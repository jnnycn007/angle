//
// Copyright 2020 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// SystemInfo_vulkan.cpp: Generic vulkan implementation of SystemInfo.h
// TODO: Use VK_KHR_driver_properties. http://anglebug.com/42263671

#include "gpu_info_util/SystemInfo_vulkan.h"

#include <vulkan/vulkan.h>
#include "gpu_info_util/SystemInfo_internal.h"

#include <algorithm>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>

#include "common/angleutils.h"
#include "common/debug.h"
#include "common/platform_helpers.h"
#include "common/system_utils.h"
#include "common/vulkan/libvulkan_loader.h"

namespace angle
{
class VulkanLibrary final : NonCopyable
{
  public:
    VulkanLibrary() = default;

    ~VulkanLibrary()
    {
        if (mInstance != VK_NULL_HANDLE)
        {
            auto pfnDestroyInstance = getProc<PFN_vkDestroyInstance>("vkDestroyInstance");
            if (pfnDestroyInstance)
            {
                pfnDestroyInstance(mInstance, nullptr);
            }
        }

        CloseSystemLibrary(mLibVulkan);
    }

    std::vector<std::string> GetInstanceExtensionNames() const
    {
        std::vector<std::string> extensionNames;

        auto pfnEnumerateInstanceExtensionProperties =
            getProc<PFN_vkEnumerateInstanceExtensionProperties>(
                "vkEnumerateInstanceExtensionProperties");
        if (!pfnEnumerateInstanceExtensionProperties)
        {
            return extensionNames;
        }

        uint32_t extensionCount = 0;
        if (pfnEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr) !=
            VK_SUCCESS)
        {
            return extensionNames;
        }

        std::vector<VkExtensionProperties> extensions(extensionCount);
        if (pfnEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data()) !=
            VK_SUCCESS)
        {
            return extensionNames;
        }

        for (const auto &extension : extensions)
        {
            extensionNames.emplace_back(extension.extensionName);
        }

        std::sort(extensionNames.begin(), extensionNames.end());

        return extensionNames;
    }

    bool ExtensionFound(std::string const &needle, const std::vector<std::string> &haystack)
    {
        // NOTE: The list must be sorted.
        return std::binary_search(haystack.begin(), haystack.end(), needle);
    }

    VkInstance getVulkanInstance()
    {
        mLibVulkan = vk::OpenLibVulkan();
        if (!mLibVulkan)
        {
            // If Vulkan doesn't exist, bail-out early:
            return VK_NULL_HANDLE;
        }

        // Determine the available Vulkan instance version:
        uint32_t instanceVersion = VK_API_VERSION_1_0;
#if defined(VK_VERSION_1_1)
        auto pfnEnumerateInstanceVersion =
            getProc<PFN_vkEnumerateInstanceVersion>("vkEnumerateInstanceVersion");
        if (!pfnEnumerateInstanceVersion ||
            pfnEnumerateInstanceVersion(&instanceVersion) != VK_SUCCESS)
        {
            instanceVersion = VK_API_VERSION_1_0;
        }
#endif  // VK_VERSION_1_1

        std::vector<std::string> availableInstanceExtensions = GetInstanceExtensionNames();
        std::vector<const char *> enabledInstanceExtensions;

        bool hasPortabilityEnumeration = false;

        if (IsApple() && ExtensionFound(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME,
                                        availableInstanceExtensions))
        {
            // On iOS/macOS, there is no native Vulkan driver, so we need to
            // enable the portability enumeration extension to allow use of
            // MoltenVK.
            enabledInstanceExtensions.push_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);
            hasPortabilityEnumeration = true;
        }

        // Create a Vulkan instance:
        VkApplicationInfo appInfo;
        appInfo.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pNext              = nullptr;
        appInfo.pApplicationName   = "";
        appInfo.applicationVersion = 1;
        appInfo.pEngineName        = "";
        appInfo.engineVersion      = 1;
        appInfo.apiVersion         = instanceVersion;

        VkInstanceCreateInfo createInstanceInfo;
        createInstanceInfo.sType               = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInstanceInfo.pNext               = nullptr;
        createInstanceInfo.flags               = 0;
        createInstanceInfo.pApplicationInfo    = &appInfo;
        createInstanceInfo.enabledLayerCount   = 0;
        createInstanceInfo.ppEnabledLayerNames = nullptr;
        createInstanceInfo.enabledExtensionCount =
            static_cast<uint32_t>(enabledInstanceExtensions.size());
        createInstanceInfo.ppEnabledExtensionNames =
            enabledInstanceExtensions.empty() ? nullptr : enabledInstanceExtensions.data();

        if (hasPortabilityEnumeration)
        {
            createInstanceInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
        }

        auto pfnCreateInstance = getProc<PFN_vkCreateInstance>("vkCreateInstance");
        if (!pfnCreateInstance ||
            pfnCreateInstance(&createInstanceInfo, nullptr, &mInstance) != VK_SUCCESS)
        {
            return VK_NULL_HANDLE;
        }

        return mInstance;
    }

    template <typename Func>
    Func getProc(const char *fn) const
    {
        return reinterpret_cast<Func>(angle::GetLibrarySymbol(mLibVulkan, fn));
    }

  private:
    void *mLibVulkan     = nullptr;
    VkInstance mInstance = VK_NULL_HANDLE;
};

ANGLE_FORMAT_PRINTF(1, 2)
std::string FormatString(const char *fmt, ...)
{
    va_list vararg;
    va_start(vararg, fmt);

    std::vector<char> buffer;
    size_t len = FormatStringIntoVector(fmt, vararg, buffer);
    va_end(vararg);

    return std::string(&buffer[0], len);
}

bool GetSystemInfoVulkan(SystemInfo *info)
{
    return GetSystemInfoVulkanWithICD(info, vk::ICD::Default);
}

bool GetSystemInfoVulkanWithICD(SystemInfo *info, vk::ICD preferredICD)
{
    const bool enableValidationLayers = false;
    vk::ScopedVkLoaderEnvironment scopedEnvironment(enableValidationLayers, preferredICD);

    static_assert(sizeof(GPUDeviceInfo::deviceUUID) == VK_UUID_SIZE);

    // This implementation builds on top of the Vulkan API, but cannot assume the existence of the
    // Vulkan library.  ANGLE can be installed on versions of Android as old as Ice Cream Sandwich.
    // Therefore, we need to use dlopen()/dlsym() in order to see if Vulkan is installed on the
    // system, and if so, to use it:
    VulkanLibrary vkLibrary;
    VkInstance instance = vkLibrary.getVulkanInstance();
    if (instance == VK_NULL_HANDLE)
    {
        // If Vulkan doesn't exist, bail-out early:
        return false;
    }

    // Enumerate the Vulkan physical devices, which are ANGLE gpus:
    auto pfnEnumeratePhysicalDevices =
        vkLibrary.getProc<PFN_vkEnumeratePhysicalDevices>("vkEnumeratePhysicalDevices");
    auto pfnGetPhysicalDeviceProperties =
        vkLibrary.getProc<PFN_vkGetPhysicalDeviceProperties>("vkGetPhysicalDeviceProperties");
    auto pfnGetPhysicalDeviceProperties2 =
        vkLibrary.getProc<PFN_vkGetPhysicalDeviceProperties2>("vkGetPhysicalDeviceProperties2");
    uint32_t physicalDeviceCount = 0;
    if (!pfnEnumeratePhysicalDevices || !pfnGetPhysicalDeviceProperties ||
        pfnEnumeratePhysicalDevices(instance, &physicalDeviceCount, nullptr) != VK_SUCCESS)
    {
        return false;
    }
    std::vector<VkPhysicalDevice> physicalDevices(physicalDeviceCount);
    if (pfnEnumeratePhysicalDevices(instance, &physicalDeviceCount, physicalDevices.data()) !=
        VK_SUCCESS)
    {
        return false;
    }

    // If we get to here, we will likely provide a valid answer (unless an unknown vendorID):
    info->gpus.resize(physicalDeviceCount);

    for (uint32_t i = 0; i < physicalDeviceCount; i++)
    {
        VkPhysicalDeviceDriverProperties driverProperties = {};
        driverProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES;

        VkPhysicalDeviceIDProperties deviceIDProperties = {};
        deviceIDProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES;
        deviceIDProperties.pNext = &driverProperties;

        VkPhysicalDeviceProperties2 properties2 = {};
        properties2.sType                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;
        properties2.pNext                       = &deviceIDProperties;

        VkPhysicalDeviceProperties &properties = properties2.properties;
        pfnGetPhysicalDeviceProperties(physicalDevices[i], &properties);

        // vkGetPhysicalDeviceProperties2() is supported since 1.1
        // Use vkGetPhysicalDeviceProperties2() to get driver information.
        if (properties.apiVersion >= VK_API_VERSION_1_1)
        {
            pfnGetPhysicalDeviceProperties2(physicalDevices[i], &properties2);
        }

        // Fill in data for a given physical device (a.k.a. gpu):
        GPUDeviceInfo &gpu = info->gpus[i];
        gpu.vendorId       = properties.vendorID;
        gpu.deviceId       = properties.deviceID;
        memcpy(gpu.deviceUUID, deviceIDProperties.deviceUUID, VK_UUID_SIZE);
        memcpy(gpu.driverUUID, deviceIDProperties.driverUUID, VK_UUID_SIZE);

        // Need to parse/re-format properties.driverVersion.
        //
        // TODO(ianelliott): Determine the formatting used for each vendor
        // (http://anglebug.com/42261385)
        // TODO(http://anglebug.com/42266143): Use driverID instead of the hardware vendorID to
        // detect driveVendor, etc.
        switch (properties.vendorID)
        {
            case kVendorID_AMD:
                gpu.driverVendor                = "Advanced Micro Devices, Inc";
                gpu.driverVersion               = FormatString("0x%x", properties.driverVersion);
                gpu.detailedDriverVersion.major = properties.driverVersion;
                break;
            case kVendorID_ARM:
                gpu.driverVendor                = "Arm Holdings";
                gpu.driverVersion               = FormatString("0x%x", properties.driverVersion);
                gpu.detailedDriverVersion.major = properties.driverVersion;
                break;
            case kVendorID_Broadcom:
                gpu.driverVendor                = "Broadcom";
                gpu.driverVersion               = FormatString("0x%x", properties.driverVersion);
                gpu.detailedDriverVersion.major = properties.driverVersion;
                break;
            case kVendorID_GOOGLE:
                gpu.driverVendor                = "Google";
                gpu.driverVersion               = FormatString("0x%x", properties.driverVersion);
                gpu.detailedDriverVersion.major = properties.driverVersion;
                break;
            case kVendorID_ImgTec:
                gpu.driverVendor                = "Imagination Technologies Limited";
                gpu.driverVersion               = FormatString("0x%x", properties.driverVersion);
                gpu.detailedDriverVersion.major = properties.driverVersion;
                break;
            case kVendorID_Intel:
                gpu.driverVendor                = "Intel Corporation";
                gpu.driverVersion               = FormatString("0x%x", properties.driverVersion);
                gpu.detailedDriverVersion.major = properties.driverVersion;
                break;
            case kVendorID_Kazan:
                gpu.driverVendor                = "Kazan Software";
                gpu.driverVersion               = FormatString("0x%x", properties.driverVersion);
                gpu.detailedDriverVersion.major = properties.driverVersion;
                break;
            case kVendorID_NVIDIA:
                gpu.driverVendor  = "NVIDIA Corporation";
                gpu.driverVersion = FormatString("%d.%d.%d.%d", properties.driverVersion >> 22,
                                                 (properties.driverVersion >> 14) & 0XFF,
                                                 (properties.driverVersion >> 6) & 0XFF,
                                                 properties.driverVersion & 0x3F);
                gpu.detailedDriverVersion.major    = properties.driverVersion >> 22;
                gpu.detailedDriverVersion.minor    = (properties.driverVersion >> 14) & 0xFF;
                gpu.detailedDriverVersion.subMinor = (properties.driverVersion >> 6) & 0xFF;
                gpu.detailedDriverVersion.patch    = properties.driverVersion & 0x3F;
                break;
            case kVendorID_Qualcomm:
                gpu.driverVendor = "Qualcomm Technologies, Inc";
                if (properties.driverVersion & 0x80000000)
                {
                    gpu.driverVersion = FormatString("%d.%d.%d", properties.driverVersion >> 22,
                                                     (properties.driverVersion >> 12) & 0X3FF,
                                                     properties.driverVersion & 0xFFF);
                    gpu.detailedDriverVersion.major    = properties.driverVersion >> 22;
                    gpu.detailedDriverVersion.minor    = (properties.driverVersion >> 12) & 0x3FF;
                    gpu.detailedDriverVersion.subMinor = properties.driverVersion & 0xFFF;
                }
                else
                {
                    gpu.driverVersion = FormatString("0x%x", properties.driverVersion);
                    gpu.detailedDriverVersion.major = properties.driverVersion;
                }
                break;
            case kVendorID_Samsung:
                gpu.driverVendor                = "Samsung";
                gpu.driverVersion               = FormatString("0x%x", properties.driverVersion);
                gpu.detailedDriverVersion.major = properties.driverVersion;
                break;
            case kVendorID_VeriSilicon:
                gpu.driverVendor                = "VeriSilicon";
                gpu.driverVersion               = FormatString("0x%x", properties.driverVersion);
                gpu.detailedDriverVersion.major = properties.driverVersion;
                break;
            case kVendorID_Vivante:
                gpu.driverVendor                = "Vivante";
                gpu.driverVersion               = FormatString("0x%x", properties.driverVersion);
                gpu.detailedDriverVersion.major = properties.driverVersion;
                break;
            case kVendorID_Mesa:
                gpu.driverVendor                = "Mesa";
                gpu.driverVersion               = FormatString("0x%x", properties.driverVersion);
                gpu.detailedDriverVersion.major = properties.driverVersion;
                break;
            case kVendorID_Apple:
                // Note: this is the version extraction for MoltenVK, which
                // formulates its version number as a decimal number like so:
                //     (major * 10000) + (minor * 100) + patch
                gpu.driverVendor                = "Apple";
                gpu.detailedDriverVersion.major = properties.driverVersion / 10000;
                gpu.detailedDriverVersion.minor = (properties.driverVersion / 100) % 100;
                gpu.detailedDriverVersion.patch = properties.driverVersion % 100;
                gpu.driverVersion =
                    FormatString("%d.%d.%d", gpu.detailedDriverVersion.major,
                                 gpu.detailedDriverVersion.minor, gpu.detailedDriverVersion.patch);
                break;
            default:
                return false;
        }
        gpu.driverId         = static_cast<DriverID>(driverProperties.driverID);
        gpu.driverApiVersion = properties.apiVersion;
        gpu.driverDate       = "";
    }

    return true;
}

}  // namespace angle

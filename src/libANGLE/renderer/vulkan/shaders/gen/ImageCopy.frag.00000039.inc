// GENERATED FILE - DO NOT EDIT.
// Generated by gen_vk_internal_shaders.py.
//
// Copyright 2018 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// shaders/gen/ImageCopy.frag.00000039.inc:
//   Pre-generated shader for the ANGLE Vulkan back-end.

#pragma once
constexpr uint8_t kImageCopy_frag_00000039[] = {
    0x1f,0x8b,0x08,0x00,0x00,0x00,0x00,0x00,0x02,0xff,0x85,0x96,0xe9,0x4f,0x9c,0x55,
    0x14,0xc6,0xef,0x6c,0x0c,0x05,0x81,0xb2,0xb4,0x88,0xda,0xda,0x05,0x92,0x1a,0x2a,
    0x4c,0x14,0x2b,0x82,0x6d,0xa4,0x56,0xda,0x68,0x95,0xd2,0xda,0xa2,0xc2,0x07,0x1b,
    0x69,0x0a,0x2a,0xe3,0xc2,0xc4,0xd8,0xc6,0x1a,0xc1,0x16,0x4c,0x6c,0xb5,0x10,0x43,
    0x6a,0xa3,0x90,0x54,0xe1,0x83,0x40,0xda,0x0f,0x26,0x7e,0x32,0xc6,0x68,0x5d,0x5a,
    0x97,0xbf,0xc6,0xb8,0x24,0x26,0x9e,0x73,0xe7,0x77,0x9a,0xe3,0x44,0xd3,0x49,0x6e,
    0xde,0xb9,0xcf,0xd9,0x9e,0xe7,0x9c,0xfb,0xde,0x99,0x54,0x72,0x6b,0x36,0x84,0x44,
    0xa8,0x08,0xe5,0xe1,0xd7,0x50,0xfc,0xd4,0x86,0xa4,0x20,0xc5,0xe7,0x3d,0xf2,0xac,
    0x0c,0x65,0x71,0xbf,0x77,0xff,0xa1,0xfd,0x6d,0xe3,0x85,0xe1,0xb6,0x8e,0xfb,0x72,
    0xea,0x57,0x1d,0x52,0xd1,0x5f,0x6d,0x35,0x21,0x1b,0xd2,0xf2,0xd4,0x35,0x76,0x74,
    0x34,0xaf,0x78,0x95,0xac,0x2b,0xb2,0xd6,0x8a,0x9f,0xe2,0x59,0xcd,0x21,0xdf,0xaa,
    0x62,0x4e,0x8d,0x09,0x61,0x5f,0xc8,0x84,0x7a,0xea,0x6e,0xe5,0x69,0x58,0x02,0xac,
    0xdc,0x61,0x49,0xb0,0xb5,0x0e,0x4b,0x81,0x35,0x38,0x2c,0x0d,0x76,0xab,0xc3,0x32,
    0x60,0x77,0x38,0xac,0x0c,0x6c,0x93,0xc3,0xb2,0x60,0xcd,0x0e,0x2b,0x07,0xdb,0xe6,
    0xb0,0x35,0x60,0xdb,0x1d,0x56,0x01,0x96,0x73,0x58,0x25,0x58,0x87,0xc3,0x6e,0x01,
    0xeb,0x74,0x58,0x15,0xd8,0x83,0x0e,0xab,0x06,0x7b,0x28,0xf6,0x2e,0x75,0xa3,0x07,
    0xda,0xc7,0x3d,0xf2,0xdc,0x42,0xcf,0x6c,0xbf,0xd9,0xed,0xb5,0xf7,0x1b,0xd9,0xd7,
    0x4b,0x54,0x32,0xda,0x53,0xb1,0x5f,0xfa,0x7d,0x9d,0xf8,0x94,0xa1,0x5d,0x7b,0xdd,
    0x28,0xfb,0x2c,0x3d,0x51,0xfb,0x7a,0xf1,0xac,0xc0,0xae,0xb6,0x4a,0xf4,0xa5,0x23,
    0x96,0x8e,0x1a,0x12,0xe8,0xeb,0x66,0x5f,0xe5,0x72,0x55,0xe3,0x6f,0xb5,0xea,0xc8,
    0x15,0x22,0xaf,0xda,0x1b,0xbd,0xb6,0x9a,0xb6,0xea,0x6e,0xb2,0xcc,0x47,0x39,0x34,
    0x30,0x87,0x7a,0x38,0x34,0xc4,0x5a,0x45,0xac,0x15,0x7d,0xeb,0xe1,0xa4,0xfe,0x8d,
    0xd8,0xb2,0xce,0xbe,0x81,0xb3,0xa1,0xf6,0x8d,0xd8,0xeb,0xe2,0x79,0x4a,0xc6,0x7e,
    0xb6,0xc2,0xdd,0x7a,0x6d,0x71,0xad,0x70,0xb1,0xfd,0x0e,0xe6,0xa5,0xda,0x77,0x91,
    0x43,0x7b,0xd5,0x24,0x19,0x7b,0xd8,0x27,0xc2,0xbf,0x3f,0xb6,0xbf,0x5d,0x7a,0xbd,
    0x5b,0x9e,0x3d,0xf0,0x78,0x18,0x7c,0x37,0xba,0x74,0xbf,0xa7,0xa4,0x7e,0x6f,0xc9,
    0xbe,0x9f,0x5e,0x6b,0xfc,0x41,0x74,0x78,0x7e,0x03,0xe8,0x56,0x7e,0x47,0xe1,0x93,
    0x72,0xf6,0x51,0xce,0xb9,0xda,0x4f,0x11,0x9b,0x76,0xf6,0xc9,0x92,0xbe,0x9e,0x63,
    0xbe,0xb6,0xbf,0xc0,0xfc,0x6d,0x7f,0xc9,0x9d,0x95,0xcb,0xd4,0x3a,0x85,0x9e,0xcb,
    0xdc,0x0d,0xa9,0xd8,0xb7,0x4c,0xe4,0x9d,0x46,0x8f,0x62,0x7f,0x08,0xa2,0x33,0xd9,
    0xc9,0xb9,0xab,0x21,0x77,0x9f,0x28,0xa8,0xe6,0xfd,0xaf,0x61,0x59,0x1f,0xf3,0x9c,
    0xdf,0x5a,0xec,0x3d,0x92,0xa1,0x91,0x3b,0x60,0x1d,0xe7,0x60,0x27,0x3e,0x4d,0xe0,
    0x93,0xe2,0xa3,0xfb,0xdb,0x88,0x6b,0x22,0x4e,0xcf,0xc1,0x9d,0xc4,0x6d,0x20,0xce,
    0xce,0xaf,0xe2,0xcb,0xe2,0xb3,0xd9,0xdd,0x1d,0x7a,0x36,0x7e,0x17,0xe6,0x2d,0xf0,
    0xf9,0x4b,0xfc,0xed,0x0e,0x69,0x41,0x4f,0x73,0x9c,0x51,0x26,0xf6,0x66,0x1b,0x35,
    0xf5,0xf3,0x26,0xfd,0xba,0x0b,0xfc,0xa0,0xec,0x94,0xd3,0xe7,0x60,0xe6,0xf7,0xa7,
    0xe4,0xb0,0x5c,0xfa,0xfc,0x4d,0xbc,0xd4,0xef,0x5b,0x7c,0x32,0xc4,0x34,0x3b,0x0d,
    0xdb,0xd1,0xd0,0xea,0x34,0xdc,0x0d,0x6e,0x1a,0xda,0xc0,0x4c,0x43,0xce,0x69,0x50,
    0x5b,0x3b,0xf7,0x99,0xd6,0x6d,0x77,0x1a,0xee,0xa5,0x76,0xc2,0x69,0xe8,0x00,0x37,
    0x0d,0x5f,0x80,0x99,0x9f,0x6a,0xb0,0x5c,0x39,0xa7,0xe1,0x2a,0x3e,0x2d,0xc4,0xb4,
    0x3b,0x0d,0xf7,0xa3,0x61,0x87,0xd3,0xd0,0x09,0x6e,0x1a,0x1e,0x00,0x33,0x0d,0xdd,
    0x4e,0x83,0xda,0xba,0xe2,0xb9,0x2b,0xd6,0xed,0xe2,0x1c,0x65,0x63,0xbe,0x62,0xed,
    0xab,0xee,0x5d,0x54,0x8e,0xe6,0xdb,0xed,0x38,0x7e,0x87,0x5f,0x8e,0xb8,0x2e,0xf8,
    0xe8,0x3b,0xfa,0x08,0xef,0xa7,0x9d,0xb9,0xbd,0x70,0xee,0x75,0x67,0x6e,0x1f,0xf8,
    0x5b,0x9c,0xb9,0x47,0xc1,0x34,0xef,0x4b,0xdc,0x97,0x8f,0x81,0x0f,0xcb,0x5e,0xef,
    0x82,0xc7,0xc9,0x7d,0x9c,0x98,0x27,0xc0,0x7a,0x5d,0x4c,0x1f,0xf8,0x3b,0xe2,0xa3,
    0xfb,0x03,0xe4,0xe9,0x83,0x8f,0xde,0x05,0x87,0xe0,0xd3,0x0f,0x1f,0x9d,0xd5,0x93,
    0xe0,0x9a,0x47,0xdf,0xe3,0xc3,0x60,0x03,0x52,0x49,0xef,0xaf,0x23,0xd4,0x3e,0x40,
    0x6f,0x0e,0xbb,0x99,0x3c,0x45,0xbe,0x01,0x37,0x93,0xa7,0xc1,0x6d,0x26,0xcf,0x80,
    0xd9,0x4c,0x86,0xdc,0x4c,0xd4,0x36,0x28,0x6b,0x84,0x3e,0x0f,0x72,0xae,0x34,0xcf,
    0xb3,0xd4,0x4e,0x45,0x0d,0xe5,0xf1,0xae,0x7a,0x0e,0xec,0x88,0x7b,0xdf,0x93,0x91,
    0x5b,0x59,0xb4,0x0f,0x13,0x67,0xeb,0xb4,0xe4,0x52,0xfc,0x18,0xb1,0xc3,0x31,0xd7,
    0x9a,0xa8,0xeb,0x38,0x79,0x8e,0x71,0xe7,0x64,0xb8,0xeb,0x52,0xcc,0x7e,0x08,0x4e,
    0x23,0x4e,0xef,0xf3,0xe8,0x1d,0x75,0x7a,0x5f,0x00,0x37,0xbd,0x2f,0x82,0x99,0xde,
    0xbc,0xd3,0xab,0xb6,0xb1,0x78,0x47,0x15,0x73,0x8f,0x39,0xbd,0x2f,0x3b,0xbd,0x2b,
    0xe4,0x7a,0x05,0x7c,0x0b,0x9c,0x2c,0x2e,0xcf,0x79,0x54,0x9f,0x57,0xa9,0x39,0x82,
    0xff,0x18,0x75,0x0b,0xae,0xae,0xfa,0x8c,0xcb,0x2a,0x10,0x3f,0xee,0xea,0xbe,0xf6,
    0x1f,0x7d,0x7e,0xfd,0x26,0x7d,0x3e,0x41,0x9c,0xad,0x29,0xfa,0x7c,0x92,0xd8,0x13,
    0xae,0xcf,0x6f,0x90,0xe7,0xe4,0xff,0xf4,0xd9,0x38,0x15,0xd0,0xa4,0x31,0x3f,0x12,
    0x93,0x27,0x7e,0xbc,0x64,0x26,0x43,0xce,0xf7,0x07,0x66,0x39,0x48,0x5c,0x21,0xc6,
    0x14,0x7f,0xbb,0x26,0xb0,0xdb,0xfc,0xde,0x66,0x7e,0x93,0x6e,0x7e,0xa7,0xc1,0x6d,
    0x7e,0x67,0xc0,0x6c,0x7e,0xd3,0xae,0x8f,0x67,0xa2,0xd6,0x10,0xce,0xc2,0x63,0x0a,
    0x9d,0x5a,0xeb,0x5d,0xea,0x4d,0xa0,0x33,0x4b,0xcf,0x4c,0xe7,0x34,0x31,0x67,0x1d,
    0x9f,0xf7,0xe0,0x73,0xce,0xf1,0x79,0x1f,0xdc,0xf8,0x9c,0x07,0x33,0x3e,0xb3,0x8e,
    0x8f,0xda,0x66,0x64,0xcd,0x91,0x7b,0xc6,0xdd,0xcb,0x1f,0xc0,0x25,0xc5,0x3d,0xac,
    0x1c,0xbf,0x74,0xb8,0xdd,0x71,0xb3,0xc4,0xce,0xb9,0x7b,0xe2,0x43,0x78,0x5d,0x70,
    0xf7,0xc4,0x45,0xf0,0xef,0xc9,0xff,0x11,0x58,0xbf,0xe3,0xfa,0x31,0x78,0x2f,0x5c,
    0x17,0x1c,0x57,0xb5,0xcd,0xcb,0x5a,0xa0,0xde,0xbc,0xe3,0xf5,0x15,0x31,0x13,0xee,
    0xf7,0xc1,0xfc,0x16,0x98,0xb5,0xfa,0x5d,0xc3,0x67,0x8e,0x98,0x79,0xc7,0xe7,0x13,
    0xf8,0x5c,0x72,0x7c,0x3e,0x05,0x37,0x3e,0x4b,0x8e,0x8f,0xda,0x16,0x65,0x2d,0x51,
    0x67,0xd1,0xf1,0xf9,0x9a,0x98,0x6b,0xcc,0x50,0xf9,0x98,0xdf,0x92,0xe3,0x73,0x1d,
    0x9f,0x05,0x62,0x16,0x1d,0x9f,0xcf,0xe0,0x33,0xea,0xf8,0x2c,0x83,0x1b,0x9f,0x55,
    0xc7,0x67,0x39,0xbe,0xf7,0x21,0x62,0x5a,0x67,0xc5,0xf1,0xf9,0x86,0xff,0x2d,0xd7,
    0xdd,0x79,0x32,0xbf,0x55,0xc7,0xe7,0x17,0x7c,0x96,0x88,0x59,0x29,0x99,0xf1,0xac,
    0xf3,0xfd,0x99,0xf3,0x30,0x43,0xdc,0x6a,0xc9,0x39,0x9d,0x76,0xbe,0x3f,0x71,0xbe,
    0xa7,0x88,0xd3,0x3c,0xbb,0x84,0xc9,0x15,0x6c,0x7f,0xcb,0xd4,0x3a,0x65,0xfd,0x03,
    0xcf,0x3e,0x5c,0xea,0x48,0x0e,0x00,0x00
};

// Generated from:
//
// #version 450 core
//
// #extension GL_EXT_samplerless_texture_functions : require
//
// layout(set = 0, binding = 0)uniform usampler2D src;
// layout(location = 0)out ivec4 dst;
//
// layout(push_constant)uniform PushConstants {
//
//     ivec2 srcOffset;
//     ivec2 dstOffset;
//     int srcMip;
//     int srcLayer;
//     int srcSampleCount;
//
//     bool flipX;
//     bool flipY;
//
//     bool premultiplyAlpha;
//     bool unmultiplyAlpha;
//
//     bool dstHasLuminance;
//     bool dstIsAlpha;
//
//     bool srcIsSRGB;
//     bool dstIsSRGB;
//
//     int dstDefaultChannelsMask;
//     bool rotateXY;
// } params;
//
// void main()
// {
//     ivec2 dstSubImageCoords = ivec2(gl_FragCoord . xy)- params . dstOffset;
//
//     ivec2 srcSubImageCoords = dstSubImageCoords;
//
//     if(params . flipX)
//     {
//         srcSubImageCoords . x = - srcSubImageCoords . x;
//     }
//     if(params . flipY)
//     {
//         srcSubImageCoords . y = - srcSubImageCoords . y;
//     }
//     if(params . rotateXY)
//     {
//         srcSubImageCoords . xy = srcSubImageCoords . yx;
//     }
//
//           uvec4 srcValue = texture(
//         src, vec2(params . srcOffset + srcSubImageCoords)/ textureSize(src, 0), params . srcMip);
//
//     if(params . premultiplyAlpha)
//     {
//         srcValue . rgb *= srcValue . a;
//     }
//     else if(params . unmultiplyAlpha && srcValue . a > 0)
//     {
//         srcValue . rgb /= srcValue . a;
//     }
//
//            ivec4 dstValue = ivec4(srcValue);
//
//     if(params . dstHasLuminance)
//     {
//         dstValue . rg = dstValue . ra;
//     }
//     else if(params . dstIsAlpha)
//     {
//         dstValue . r = dstValue . a;
//     }
//     else
//     {
//         int defaultChannelsMask = params . dstDefaultChannelsMask;
//         if((defaultChannelsMask & 2)!= 0)
//         {
//             dstValue . g = 0;
//         }
//         if((defaultChannelsMask & 4)!= 0)
//         {
//             dstValue . b = 0;
//         }
//         if((defaultChannelsMask & 8)!= 0)
//         {
//             dstValue . a = 1;
//         }
//     }
//
//     dst = dstValue;
// }
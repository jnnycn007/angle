// GENERATED FILE - DO NOT EDIT.
// Generated by gen_vk_internal_shaders.py.
//
// Copyright 2018 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// shaders/gen/ImageCopy.frag.00000035.inc:
//   Pre-generated shader for the ANGLE Vulkan back-end.

#pragma once
constexpr uint8_t kImageCopy_frag_00000035[] = {
    0x1f,0x8b,0x08,0x00,0x00,0x00,0x00,0x00,0x02,0xff,0x85,0x96,0xfd,0x4f,0xd6,0x55,
    0x18,0xc6,0xbf,0x3c,0x2f,0x3c,0x08,0x01,0xf2,0xa2,0x44,0xa5,0x69,0xc2,0x66,0xc3,
    0xe0,0x59,0x91,0x11,0xa4,0x0b,0x33,0x74,0x65,0x21,0x9a,0x52,0xc1,0x96,0x25,0x0b,
    0x2c,0xd0,0x82,0x5a,0xba,0xb6,0xd6,0xd2,0x84,0x1f,0xd2,0x12,0xd6,0x98,0xb9,0x82,
    0xcd,0x82,0x1f,0x14,0x66,0x3f,0xb4,0xf5,0x53,0x6b,0xad,0x74,0xa4,0xbd,0xfc,0x33,
    0xad,0x97,0xad,0xad,0x73,0x9f,0xe7,0x73,0xbb,0xab,0x67,0x35,0xd9,0xce,0xbe,0x9e,
    0xeb,0x7e,0xbb,0xae,0xfb,0x3e,0xe7,0xf8,0xa4,0x53,0x9b,0x72,0x49,0x52,0x92,0x94,
    0x27,0x65,0xc9,0xaf,0x49,0xe1,0xaf,0x26,0x49,0x05,0xa4,0xf0,0xbd,0x3f,0x7c,0x2b,
    0x92,0xd2,0xb8,0xdf,0xb5,0x67,0xff,0x9e,0xd6,0x89,0x37,0x86,0x5a,0xdb,0x1f,0xcc,
    0x9b,0x5f,0x55,0x92,0x8e,0xfe,0x66,0xab,0x4e,0x72,0x49,0x26,0x7c,0x6d,0x8d,0xbd,
    0x78,0xe4,0xa8,0xe1,0x95,0x61,0x7d,0x19,0xd6,0xea,0xe0,0x67,0x78,0xce,0x72,0x84,
    0x7f,0x55,0xc6,0x9c,0x16,0x93,0x24,0xbb,0x93,0x6c,0x52,0x47,0xdd,0x4d,0x7c,0x1d,
    0x2b,0x01,0x2b,0x13,0x2c,0x05,0xb6,0x5a,0xb0,0x34,0x58,0xbd,0x60,0x19,0xb0,0xdb,
    0x05,0xcb,0x82,0xdd,0x25,0x58,0x29,0xd8,0x06,0xc1,0x72,0x60,0x4d,0x82,0x95,0x81,
    0x6d,0x16,0x6c,0x15,0xd8,0x16,0xc1,0xca,0xc1,0xf2,0x82,0x55,0x80,0xb5,0x0b,0x76,
    0x1b,0x58,0x87,0x60,0x95,0x60,0x8f,0x08,0x56,0x05,0xf6,0x68,0xec,0x5d,0xfa,0x66,
    0x0f,0xac,0x8f,0x3b,0xc3,0xf7,0x1e,0x7a,0xe6,0xfb,0x8d,0xb2,0xb7,0xde,0xaf,0x67,
    0x5f,0x17,0xa2,0x52,0xd1,0x9e,0x8e,0xfd,0xb2,0x7f,0xaf,0x09,0x3e,0xa5,0x68,0xb7,
    0x5e,0x37,0x84,0x7d,0x8e,0x9e,0x98,0x7d,0x6d,0xf0,0x2c,0xc7,0x6e,0xb6,0x0a,0xf4,
    0x65,0x22,0x96,0x89,0x1a,0x4a,0xd0,0xd7,0xc5,0xbe,0x52,0x72,0x55,0xe1,0xef,0xb5,
    0x6a,0xc9,0x95,0x44,0x5e,0x35,0x37,0x7b,0xed,0x35,0x7d,0xd5,0xde,0x62,0xb9,0x8f,
    0x71,0xa8,0x67,0x0e,0x75,0x70,0xa8,0x8f,0xb5,0x0a,0x58,0x0b,0xfa,0xd6,0xc2,0xc9,
    0xfc,0x1b,0xb0,0xe5,0xc4,0xbe,0x8e,0xb3,0x61,0xf6,0xf5,0xd8,0x6b,0xe3,0x79,0x4a,
    0xc5,0x7e,0xb6,0xc0,0xdd,0x7b,0xed,0x71,0x2d,0x70,0xf1,0xfd,0x56,0xe6,0x65,0xda,
    0xb7,0x63,0xb3,0x5e,0x35,0x86,0x8c,0xdd,0xec,0x4b,0x92,0x7f,0xff,0xf9,0xfe,0xce,
    0xd0,0xeb,0x1d,0xe1,0xdb,0x0d,0x8f,0xc7,0xc0,0x77,0xa0,0xcb,0xf6,0x3b,0x8b,0xea,
    0xf7,0x14,0xed,0xfb,0xe8,0xb5,0xc5,0xef,0x43,0x87,0xf2,0xeb,0x47,0xb7,0xf1,0x3b,
    0x84,0x2d,0x2d,0xf6,0x11,0xce,0xb9,0xef,0x4f,0x16,0xf5,0xf1,0x2c,0xf3,0xf4,0xfd,
    0x79,0xe6,0xed,0xfb,0x8b,0x72,0x36,0xae,0x90,0x7b,0x3b,0xfc,0xaf,0xf0,0x16,0xa4,
    0x63,0x9f,0xb2,0x91,0x67,0x06,0xfe,0x86,0xfd,0x11,0x10,0x9b,0xc1,0x36,0xce,0x59,
    0x35,0xb9,0x7b,0x03,0xe3,0x2a,0xee,0x7b,0x35,0xcb,0xfb,0x76,0x94,0xf3,0x5a,0x83,
    0xbd,0x3b,0x64,0x68,0xe0,0xce,0xaf,0x61,0xee,0xdb,0xf0,0x69,0x04,0x7f,0x2f,0xf8,
    0xd8,0xfe,0x0e,0xe2,0x1a,0x89,0xb3,0xb9,0xdf,0x4d,0xdc,0x3a,0xe2,0xfc,0xbc,0x1a,
    0x7e,0x29,0xf8,0x6c,0x94,0xb7,0xc2,0xce,0xc2,0xef,0x81,0x79,0x33,0x7c,0xfe,0x0a,
    0xfe,0xfe,0x66,0x34,0xa3,0xa7,0x29,0xce,0x24,0x1b,0x7b,0xb3,0x99,0x9a,0xf6,0xf7,
    0x0e,0xfd,0xba,0x17,0x7c,0x5f,0xd8,0x19,0xa7,0xaf,0xc0,0xdc,0xef,0xcf,0x90,0xc3,
    0x73,0xd9,0xf7,0xb7,0xe0,0x65,0x7e,0x3f,0xe0,0x93,0x25,0xa6,0x49,0x34,0x6c,0x41,
    0x43,0x8b,0x68,0xb8,0x0f,0xdc,0x35,0xb4,0x82,0xb9,0x86,0xbc,0x68,0x30,0x5b,0x1b,
    0xef,0x97,0xd5,0x6d,0x13,0x0d,0x0f,0x50,0xbb,0x44,0x34,0xb4,0x83,0xbb,0x86,0xaf,
    0xc1,0xdc,0xcf,0x34,0x78,0xae,0xbc,0x68,0xb8,0x8a,0x4f,0x33,0x31,0x6d,0xa2,0xe1,
    0x21,0x34,0x6c,0x15,0x0d,0x1d,0xe0,0xae,0xe1,0x61,0x30,0xd7,0xd0,0x25,0x1a,0xcc,
    0xd6,0x19,0xcf,0x5d,0xa1,0x6e,0x27,0xe7,0x28,0x17,0xf3,0x15,0x6a,0x5f,0x95,0xbb,
    0x67,0x1c,0xdd,0xb7,0x4b,0x38,0x5e,0xc3,0x2f,0x4f,0x5c,0x27,0x7c,0xec,0x4e,0x3e,
    0xce,0x7d,0xf4,0x33,0xb7,0x0b,0xce,0x3d,0x72,0xe6,0x76,0x83,0xbf,0xcb,0x99,0x7b,
    0x02,0xcc,0xf2,0x1e,0xe3,0x7d,0x7c,0x12,0x7c,0x28,0xec,0xed,0xee,0x3f,0x45,0xee,
    0x61,0x62,0x9e,0x06,0xeb,0x91,0x98,0x5e,0xf0,0xa9,0xe0,0x63,0xfb,0xbd,0xe4,0xe9,
    0x85,0x8f,0xdd,0xfd,0xfd,0xf0,0xe9,0x83,0x8f,0xcd,0xea,0x19,0x70,0xcb,0x63,0xf7,
    0xf8,0x00,0x58,0x7f,0xa8,0x64,0xf7,0xf4,0x20,0xb5,0xf7,0xd2,0x9b,0x03,0x32,0x93,
    0x67,0xc9,0xd7,0x2f,0x33,0x79,0x0e,0xdc,0x67,0xf2,0x3c,0x98,0xcf,0x64,0x50,0x66,
    0x62,0xb6,0x81,0xa8,0xab,0xd0,0xe7,0x01,0x39,0x57,0x2f,0x50,0x3b,0x1d,0x35,0x94,
    0xc5,0xb7,0xe9,0x25,0xb0,0x83,0x72,0xdf,0x53,0x91,0x5b,0x69,0xb4,0x1f,0x26,0xce,
    0xd7,0xa9,0x90,0xeb,0x50,0xec,0x63,0x21,0xf6,0x70,0xcc,0xb5,0x2a,0xea,0x7a,0x99,
    0x3c,0x43,0xbc,0x39,0x59,0x79,0xfb,0x6c,0xf6,0x83,0x70,0x1a,0x16,0xbd,0x47,0xd0,
    0x3b,0x22,0x7a,0x5f,0x01,0x77,0xbd,0xaf,0x82,0xb9,0xde,0x31,0xd1,0x6b,0xb6,0x51,
    0xfb,0x2d,0x44,0xee,0x51,0xd1,0x7b,0x4c,0xf4,0x2e,0x91,0xeb,0x35,0xf0,0x1e,0x38,
    0x79,0xdc,0x18,0xe7,0xd1,0x7c,0x5e,0xa7,0xe6,0x30,0xfe,0xa3,0xd4,0x9d,0x90,0xba,
    0xe6,0x33,0x1e,0xd6,0x04,0xf1,0xe3,0x52,0xf7,0xcd,0xff,0xe8,0xf3,0x5b,0xb7,0xe8,
    0xf3,0x71,0xe2,0x7c,0x4d,0xd2,0xe7,0x13,0xc4,0x1e,0x97,0x3e,0xbf,0x4d,0x9e,0x13,
    0xff,0xd3,0x67,0xe7,0x34,0x81,0x26,0x8b,0xf9,0x91,0x98,0x31,0xe2,0xc7,0x8b,0x66,
    0x32,0x28,0xbe,0x2b,0xcc,0x72,0x80,0xb8,0x09,0x99,0xd7,0x29,0xe6,0x75,0x52,0xe6,
    0xf5,0x3e,0xb8,0xcf,0xeb,0x34,0x98,0xcf,0x6b,0x4a,0xfa,0x76,0x3a,0x6a,0x4b,0x92,
    0x33,0xd4,0x9d,0x14,0x5d,0x1f,0x50,0x7b,0x05,0x5d,0x39,0x7a,0xe4,0xba,0xa6,0x88,
    0x39,0x23,0x7c,0x3e,0x84,0xcf,0x59,0xe1,0xf3,0x11,0xb8,0xf3,0x39,0x07,0xe6,0x7c,
    0x66,0x84,0x8f,0xd9,0xa6,0xc3,0x9a,0x25,0xf7,0xb4,0xcc,0xf1,0x63,0xb8,0xa4,0x79,
    0x77,0x8d,0xe3,0x37,0x82,0xfb,0x9b,0x36,0x43,0xec,0xac,0xbc,0x0b,0x9f,0xc0,0xeb,
    0xbc,0xbc,0x0b,0x17,0xc0,0xaf,0x91,0xff,0x53,0xb0,0x3e,0xe1,0xfa,0x19,0x78,0x0f,
    0x5c,0xe7,0x85,0xab,0xd9,0xe6,0xc2,0x9a,0xa7,0xde,0x9c,0xf0,0xfa,0x96,0x98,0x15,
    0xf9,0xff,0xc0,0xfd,0xe6,0x65,0xb6,0xd7,0xf1,0x99,0x25,0x66,0x4e,0xf8,0x7c,0x0e,
    0x9f,0x8b,0xc2,0xe7,0x0b,0x70,0xe7,0xb3,0x28,0x7c,0xcc,0xb6,0x10,0xd6,0x22,0x75,
    0x16,0x84,0xcf,0x77,0xc4,0x5c,0x67,0x86,0xc6,0xc7,0xfd,0x16,0x85,0xcf,0x0d,0x7c,
    0xe6,0x89,0x59,0x10,0x3e,0x97,0xe0,0x33,0x22,0x7c,0x2e,0x83,0x3b,0x9f,0x65,0xe1,
    0x73,0x39,0xde,0xf3,0x24,0x62,0x56,0x67,0x49,0xf8,0x7c,0xcf,0xef,0x94,0x1b,0x72,
    0x9e,0xdc,0x6f,0x59,0xf8,0xfc,0x82,0xcf,0x22,0x31,0x4b,0x45,0x33,0x9e,0x11,0xdf,
    0x9f,0x39,0x0f,0xd3,0xc4,0x2d,0x17,0x9d,0xd3,0x29,0xf1,0xfd,0x89,0xf3,0x3d,0x49,
    0xdc,0x4c,0xfc,0xcd,0x96,0x8e,0xbf,0xd5,0xcc,0xf6,0x77,0x98,0x5a,0x47,0x58,0xff,
    0x00,0x65,0x3f,0x70,0x22,0x28,0x0e,0x00,0x00
};

// Generated from:
//
// #version 450 core
//
// #extension GL_EXT_samplerless_texture_functions : require
//
// layout(set = 0, binding = 0)uniform isampler2D src;
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
//           ivec4 srcValue = texture(
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
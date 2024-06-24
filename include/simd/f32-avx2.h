// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//

#ifndef THIRD_PARTY_XNNPACK_INCLUDE_SIMD_F32_AVX_H_
#define THIRD_PARTY_XNNPACK_INCLUDE_SIMD_F32_AVX_H_

#include <simd/f32-avx-base.h>
#include <xnnpack/common.h>


// Whether or not this architecture has native fused multiply-add support.
#ifdef __FMA3__
#define XNN_SIMD_HAS_NATIVE_FMA 1
#else
#define XNN_SIMD_HAS_NATIVE_FMA 0
#endif  // __FMA3__

static XNN_INLINE xnn_simd_f32_t xnn_fmadd_f32(xnn_simd_f32_t a,
                                               xnn_simd_f32_t b,
                                               xnn_simd_f32_t c) {
#ifdef __FMA3__
  return _mm256_fmadd_ps(a, b, c);
#else
  return _mm256_add_ps(_mm256_mul_ps(a, b), c);
#endif  // __FMA3__
}

static XNN_INLINE xnn_simd_f32_t xnn_fnmadd_f32(xnn_simd_f32_t a,
                                                xnn_simd_f32_t b,
                                                xnn_simd_f32_t c) {
#ifdef __FMA3__
  return _mm256_fnmadd_ps(a, b, c);
#else
  return _mm256_sub_ps(c, _mm256_mul_ps(a, b));
#endif  // __FMA3__
}

static XNN_INLINE xnn_simd_f32_t xnn_fmsub_f32(xnn_simd_f32_t a,
                                               xnn_simd_f32_t b,
                                               xnn_simd_f32_t c) {
#ifdef __FMA3__
  return _mm256_fmsub_ps(a, b, c);
#else
  return _mm256_sub_ps(_mm256_mul_ps(a, b), c);
#endif  // __FMA3__
}

#endif  // THIRD_PARTY_XNNPACK_INCLUDE_SIMD_F32_AVX_H_

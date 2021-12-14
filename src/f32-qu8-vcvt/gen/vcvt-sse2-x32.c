// Auto-generated file. Do not edit!
//   Template: src/f32-qs8-vcvt/sse.c.in
//   Generator: tools/xngen
//
// Copyright 2021 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <emmintrin.h>

#include <xnnpack/common.h>
#include <xnnpack/vcvt.h>


void xnn_f32_qu8_vcvt_ukernel__sse2_x32(
    size_t n,
    const float* x,
    uint8_t* y,
    const union xnn_f32_qu8_cvt_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(n != 0);
  assert(n % sizeof(float) == 0);
  assert(x != NULL);
  assert(y != NULL);

  const __m128 vscale = _mm_load_ps(params->sse2.scale);
  const __m128 voutput_max_less_zero_point = _mm_load_ps(params->sse2.output_max_less_zero_point);
  const __m128i voutput_zero_point = _mm_load_si128((const __m128i*) params->sse2.output_zero_point);
  const __m128i voutput_min = _mm_load_si128((const __m128i*) params->sse2.output_min);

  for (; n >= 32 * sizeof(float); n -= 32 * sizeof(float)) {
    __m128 vx0123 = _mm_loadu_ps(x);
    __m128 vx4567 = _mm_loadu_ps(x + 4);
    __m128 vx89AB = _mm_loadu_ps(x + 8);
    __m128 vxCDEF = _mm_loadu_ps(x + 12);
    __m128 vxGHIJ = _mm_loadu_ps(x + 16);
    __m128 vxKLMN = _mm_loadu_ps(x + 20);
    __m128 vxOPQR = _mm_loadu_ps(x + 24);
    __m128 vxSTUV = _mm_loadu_ps(x + 28);
    x += 32;

    vx0123 = _mm_mul_ps(vx0123, vscale);
    vx4567 = _mm_mul_ps(vx4567, vscale);
    vx89AB = _mm_mul_ps(vx89AB, vscale);
    vxCDEF = _mm_mul_ps(vxCDEF, vscale);
    vxGHIJ = _mm_mul_ps(vxGHIJ, vscale);
    vxKLMN = _mm_mul_ps(vxKLMN, vscale);
    vxOPQR = _mm_mul_ps(vxOPQR, vscale);
    vxSTUV = _mm_mul_ps(vxSTUV, vscale);

    vx0123 = _mm_min_ps(vx0123, voutput_max_less_zero_point);
    vx4567 = _mm_min_ps(vx4567, voutput_max_less_zero_point);
    vx89AB = _mm_min_ps(vx89AB, voutput_max_less_zero_point);
    vxCDEF = _mm_min_ps(vxCDEF, voutput_max_less_zero_point);
    vxGHIJ = _mm_min_ps(vxGHIJ, voutput_max_less_zero_point);
    vxKLMN = _mm_min_ps(vxKLMN, voutput_max_less_zero_point);
    vxOPQR = _mm_min_ps(vxOPQR, voutput_max_less_zero_point);
    vxSTUV = _mm_min_ps(vxSTUV, voutput_max_less_zero_point);

    const __m128i vy0123 = _mm_cvtps_epi32(vx0123);
    const __m128i vy4567 = _mm_cvtps_epi32(vx4567);
    const __m128i vy89AB = _mm_cvtps_epi32(vx89AB);
    const __m128i vyCDEF = _mm_cvtps_epi32(vxCDEF);
    const __m128i vyGHIJ = _mm_cvtps_epi32(vxGHIJ);
    const __m128i vyKLMN = _mm_cvtps_epi32(vxKLMN);
    const __m128i vyOPQR = _mm_cvtps_epi32(vxOPQR);
    const __m128i vySTUV = _mm_cvtps_epi32(vxSTUV);

    __m128i vy01234567 = _mm_packs_epi32(vy0123, vy4567);
    __m128i vy89ABCDEF = _mm_packs_epi32(vy89AB, vyCDEF);
    __m128i vyGHIJKLMN = _mm_packs_epi32(vyGHIJ, vyKLMN);
    __m128i vyOPQRSTUV = _mm_packs_epi32(vyOPQR, vySTUV);

    vy01234567 = _mm_adds_epi16(vy01234567, voutput_zero_point);
    vy89ABCDEF = _mm_adds_epi16(vy89ABCDEF, voutput_zero_point);
    vyGHIJKLMN = _mm_adds_epi16(vyGHIJKLMN, voutput_zero_point);
    vyOPQRSTUV = _mm_adds_epi16(vyOPQRSTUV, voutput_zero_point);


    __m128i vy0123456789ABCDEF = _mm_packus_epi16(vy01234567, vy89ABCDEF);
    __m128i vyGHIJKLMNOPQRSTUV = _mm_packus_epi16(vyGHIJKLMN, vyOPQRSTUV);

    vy0123456789ABCDEF = _mm_max_epu8(vy0123456789ABCDEF, voutput_min);
    vyGHIJKLMNOPQRSTUV = _mm_max_epu8(vyGHIJKLMNOPQRSTUV, voutput_min);

    _mm_storeu_si128((__m128i*) y, vy0123456789ABCDEF);
    _mm_storeu_si128((__m128i*) (y + 16), vyGHIJKLMNOPQRSTUV);
    y += 32;
  }
  for (; n >= 8 * sizeof(float); n -= 8 * sizeof(float)) {
    __m128 vx_lo = _mm_loadu_ps(x);
    __m128 vx_hi = _mm_loadu_ps(x + 4);
    x += 8;

    vx_lo = _mm_mul_ps(vx_lo, vscale);
    vx_hi = _mm_mul_ps(vx_hi, vscale);

    vx_lo = _mm_min_ps(vx_lo, voutput_max_less_zero_point);
    vx_hi = _mm_min_ps(vx_hi, voutput_max_less_zero_point);

    const __m128i vy_lo = _mm_cvtps_epi32(vx_lo);
    const __m128i vy_hi = _mm_cvtps_epi32(vx_hi);

    __m128i vy = _mm_packs_epi32(vy_lo, vy_hi);
    vy = _mm_adds_epi16(vy, voutput_zero_point);
    vy = _mm_packus_epi16(vy, vy);
    vy = _mm_max_epu8(vy, voutput_min);

    _mm_storel_epi64((__m128i*) y, vy);
    y += 8;
  }
  if XNN_UNLIKELY(n != 0) {
    __m128 vx_lo = _mm_loadu_ps(x);
    const float* x_hi = (const float*) ((uintptr_t) x + (n & (4 * sizeof(float))));
    __m128 vx_hi = _mm_loadu_ps(x_hi);

    vx_lo = _mm_mul_ps(vx_lo, vscale);
    vx_hi = _mm_mul_ps(vx_hi, vscale);

    vx_lo = _mm_min_ps(vx_lo, voutput_max_less_zero_point);
    vx_hi = _mm_min_ps(vx_hi, voutput_max_less_zero_point);

    const __m128i vy_lo = _mm_cvtps_epi32(vx_lo);
    const __m128i vy_hi = _mm_cvtps_epi32(vx_hi);

    __m128i vy = _mm_packs_epi32(vy_lo, vy_hi);
    vy = _mm_adds_epi16(vy, voutput_zero_point);
    vy = _mm_packus_epi16(vy, vy);
    vy = _mm_max_epu8(vy, voutput_min);

    if (n & (4 * sizeof(float))) {
      *((uint32_t*) y) = (uint32_t) _mm_cvtsi128_si32(vy);
      y += 4;
      vy = _mm_srli_epi64(vy, 32);
    }
    {
      uint32_t vy_lo = (uint32_t) _mm_cvtsi128_si32(vy);
      if (n & (2 * sizeof(float))) {
        *((uint16_t*) y) = (uint16_t) vy_lo;
        y += 2;
        vy_lo >>= 16;
      }
      if (n & (1 * sizeof(float))) {
        *y = (uint8_t) vy_lo;
      }
    }
  }
}

// Auto-generated file. Do not edit!
//   Template: src/f32-vsqrt/neonfma-nr2fma1adj.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <math.h>

#include <arm_neon.h>

#include <xnnpack/common.h>
#include <xnnpack/vunary.h>


void xnn_f32_vsqrt_ukernel__neonfma_nr2fma1adj_x12(
    size_t n,
    const float* x,
    float* y,
    const union xnn_f32_sqrt_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(n != 0);
  assert(n % sizeof(float) == 0);

  const float32x4_t vhalf = vmovq_n_f32(0.5f);
  for (; n >= 12 * sizeof(float); n -= 12 * sizeof(float)) {
    const float32x4_t vx0123 = vld1q_f32(x); x += 4;
    const float32x4_t vx4567 = vld1q_f32(x); x += 4;
    const float32x4_t vx89AB = vld1q_f32(x); x += 4;

    const float32x4_t vrsqrtx0123 = vrsqrteq_f32(vx0123);
    const float32x4_t vrsqrtx4567 = vrsqrteq_f32(vx4567);
    const float32x4_t vrsqrtx89AB = vrsqrteq_f32(vx89AB);

    float32x4_t vsqrtx0123 = vmulq_f32(vrsqrtx0123, vx0123);
    float32x4_t vhalfrsqrtx0123 = vmulq_f32(vrsqrtx0123, vhalf);
    float32x4_t vsqrtx4567 = vmulq_f32(vrsqrtx4567, vx4567);
    float32x4_t vhalfrsqrtx4567 = vmulq_f32(vrsqrtx4567, vhalf);
    float32x4_t vsqrtx89AB = vmulq_f32(vrsqrtx89AB, vx89AB);
    float32x4_t vhalfrsqrtx89AB = vmulq_f32(vrsqrtx89AB, vhalf);

    float32x4_t vresidual0123 = vfmsq_f32(vhalf, vsqrtx0123, vhalfrsqrtx0123);
    float32x4_t vresidual4567 = vfmsq_f32(vhalf, vsqrtx4567, vhalfrsqrtx4567);
    float32x4_t vresidual89AB = vfmsq_f32(vhalf, vsqrtx89AB, vhalfrsqrtx89AB);

    vhalfrsqrtx0123 = vfmaq_f32(vhalfrsqrtx0123, vresidual0123, vhalfrsqrtx0123);
    vsqrtx0123 = vfmaq_f32(vsqrtx0123, vresidual0123, vsqrtx0123);
    vhalfrsqrtx4567 = vfmaq_f32(vhalfrsqrtx4567, vresidual4567, vhalfrsqrtx4567);
    vsqrtx4567 = vfmaq_f32(vsqrtx4567, vresidual4567, vsqrtx4567);
    vhalfrsqrtx89AB = vfmaq_f32(vhalfrsqrtx89AB, vresidual89AB, vhalfrsqrtx89AB);
    vsqrtx89AB = vfmaq_f32(vsqrtx89AB, vresidual89AB, vsqrtx89AB);

    vresidual0123 = vfmsq_f32(vhalf, vsqrtx0123, vhalfrsqrtx0123);
    vresidual4567 = vfmsq_f32(vhalf, vsqrtx4567, vhalfrsqrtx4567);
    vresidual89AB = vfmsq_f32(vhalf, vsqrtx89AB, vhalfrsqrtx89AB);

    vhalfrsqrtx0123 = vfmaq_f32(vhalfrsqrtx0123, vresidual0123, vhalfrsqrtx0123);
    vsqrtx0123 = vfmaq_f32(vsqrtx0123, vresidual0123, vsqrtx0123);
    vhalfrsqrtx4567 = vfmaq_f32(vhalfrsqrtx4567, vresidual4567, vhalfrsqrtx4567);
    vsqrtx4567 = vfmaq_f32(vsqrtx4567, vresidual4567, vsqrtx4567);
    vhalfrsqrtx89AB = vfmaq_f32(vhalfrsqrtx89AB, vresidual89AB, vhalfrsqrtx89AB);
    vsqrtx89AB = vfmaq_f32(vsqrtx89AB, vresidual89AB, vsqrtx89AB);

    const float32x4_t vadjustment0123 = vfmsq_f32(vx0123, vsqrtx0123, vsqrtx0123);
    const float32x4_t vadjustment4567 = vfmsq_f32(vx4567, vsqrtx4567, vsqrtx4567);
    const float32x4_t vadjustment89AB = vfmsq_f32(vx89AB, vsqrtx89AB, vsqrtx89AB);

    const float32x4_t vy0123 = vfmaq_f32(vsqrtx0123, vhalfrsqrtx0123, vadjustment0123);
    const float32x4_t vy4567 = vfmaq_f32(vsqrtx4567, vhalfrsqrtx4567, vadjustment4567);
    const float32x4_t vy89AB = vfmaq_f32(vsqrtx89AB, vhalfrsqrtx89AB, vadjustment89AB);

    vst1q_f32(y, vy0123); y += 4;
    vst1q_f32(y, vy4567); y += 4;
    vst1q_f32(y, vy89AB); y += 4;
  }
  if XNN_UNLIKELY(n != 0) {
    do {
      const float vx = *x++;
      const float vy = sqrtf(vx);
      *y++ = vy;
      n -= sizeof(float);
    } while (n != 0);
  }
}

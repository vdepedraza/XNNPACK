// Auto-generated file. Do not edit!
//   Template: src/f32-vsqrt/wasmsimd-sqrt.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <math.h>

#include <wasm_simd128.h>

#include <xnnpack/common.h>
#include <xnnpack/vunary.h>


void xnn_f32_vsqrt_ukernel__wasmsimd_sqrt_x8(
    size_t n,
    const float* x,
    float* y,
    const union xnn_f32_sqrt_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(n != 0);
  assert(n % sizeof(float) == 0);

  for (; n >= 8 * sizeof(float); n -= 8 * sizeof(float)) {
    const v128_t vx0123 = wasm_v128_load(x);
    const v128_t vx4567 = wasm_v128_load(x + 4);
    x += 8;

    const v128_t vy0123 = wasm_f32x4_sqrt(vx0123);
    const v128_t vy4567 = wasm_f32x4_sqrt(vx4567);

    wasm_v128_store(y, vy0123);
    wasm_v128_store(y + 4, vy4567);
    y += 8;
  }
  for (; n >= 4 * sizeof(float); n -= 4 * sizeof(float)) {
    const v128_t vx = wasm_v128_load(x);
    x += 4;
    const v128_t vy = wasm_f32x4_sqrt(vx);
    wasm_v128_store(y, vy);
    y += 4;
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

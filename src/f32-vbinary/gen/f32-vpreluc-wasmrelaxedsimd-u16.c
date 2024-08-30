// Auto-generated file. Do not edit!
//   Template: src/f32-vbinary/vopc-wasmsimd.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <wasm_simd128.h>

#include "xnnpack/common.h"
#include "xnnpack/vbinary.h"


void xnn_f32_vpreluc_ukernel__wasmrelaxedsimd_u16(
    size_t batch,
    const float* input_a,
    const float* input_b,
    float* output,
    const union xnn_f32_default_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input_a != NULL);
  assert(input_b != NULL);
  assert(output != NULL);

  const v128_t vb = wasm_v128_load32_splat(input_b);

  for (; batch >= 16 * sizeof(float); batch -= 16 * sizeof(float)) {
    const v128_t va0 = wasm_v128_load(input_a);
    const v128_t va1 = wasm_v128_load(input_a + 4);
    const v128_t va2 = wasm_v128_load(input_a + 8);
    const v128_t va3 = wasm_v128_load(input_a + 12);
    input_a += 16;

    v128_t vy0 = wasm_f32x4_mul(va0, vb);
    v128_t vy1 = wasm_f32x4_mul(va1, vb);
    v128_t vy2 = wasm_f32x4_mul(va2, vb);
    v128_t vy3 = wasm_f32x4_mul(va3, vb);

    const v128_t vmask0 = wasm_i32x4_shr(va0, 31);
    const v128_t vmask1 = wasm_i32x4_shr(va1, 31);
    const v128_t vmask2 = wasm_i32x4_shr(va2, 31);
    const v128_t vmask3 = wasm_i32x4_shr(va3, 31);

    vy0 = wasm_i32x4_relaxed_laneselect(vy0, va0, vmask0);
    vy1 = wasm_i32x4_relaxed_laneselect(vy1, va1, vmask1);
    vy2 = wasm_i32x4_relaxed_laneselect(vy2, va2, vmask2);
    vy3 = wasm_i32x4_relaxed_laneselect(vy3, va3, vmask3);


    wasm_v128_store(output, vy0);
    wasm_v128_store(output + 4, vy1);
    wasm_v128_store(output + 8, vy2);
    wasm_v128_store(output + 12, vy3);
    output += 16;
  }
  for (; batch >= 4 * sizeof(float); batch -= 4 * sizeof(float)) {
    const v128_t va = wasm_v128_load(input_a);
    input_a += 4;

    v128_t vy = wasm_f32x4_mul(va, vb);
    const v128_t vmask = wasm_i32x4_shr(va, 31);
    vy = wasm_i32x4_relaxed_laneselect(vy, va, vmask);


    wasm_v128_store(output, vy);
    output += 4;
  }
  if XNN_UNLIKELY(batch != 0) {
    const v128_t va = wasm_v128_load(input_a);

    v128_t vy = wasm_f32x4_mul(va, vb);
    const v128_t vmask = wasm_i32x4_shr(va, 31);
    vy = wasm_i32x4_relaxed_laneselect(vy, va, vmask);


    if (batch & (2 * sizeof(float))) {
      wasm_v128_store64_lane(output, vy, 0);
      vy = wasm_v64x2_shuffle(vy, vy, 1, 1);
      output += 2;
    }
    if (batch & (1 * sizeof(float))) {
      wasm_v128_store32_lane(output, vy, 0);
    }
  }
}

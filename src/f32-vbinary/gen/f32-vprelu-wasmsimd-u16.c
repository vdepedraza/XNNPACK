// Auto-generated file. Do not edit!
//   Template: src/f32-vbinary/vop-wasmsimd.c.in
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


void xnn_f32_vprelu_ukernel__wasmsimd_u16(
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


  for (; batch >= 16 * sizeof(float); batch -= 16 * sizeof(float)) {
    const v128_t va0 = wasm_v128_load(input_a);
    const v128_t va1 = wasm_v128_load(input_a + 4);
    const v128_t va2 = wasm_v128_load(input_a + 8);
    const v128_t va3 = wasm_v128_load(input_a + 12);
    input_a += 16;

    const v128_t vb0 = wasm_v128_load(input_b);
    const v128_t vb1 = wasm_v128_load(input_b + 4);
    const v128_t vb2 = wasm_v128_load(input_b + 8);
    const v128_t vb3 = wasm_v128_load(input_b + 12);
    input_b += 16;

    v128_t vacc0 = wasm_f32x4_mul(va0, vb0);
    v128_t vacc1 = wasm_f32x4_mul(va1, vb1);
    v128_t vacc2 = wasm_f32x4_mul(va2, vb2);
    v128_t vacc3 = wasm_f32x4_mul(va3, vb3);

    const v128_t vmask0 = wasm_i32x4_shr(va0, 31);
    const v128_t vmask1 = wasm_i32x4_shr(va1, 31);
    const v128_t vmask2 = wasm_i32x4_shr(va2, 31);
    const v128_t vmask3 = wasm_i32x4_shr(va3, 31);

    vacc0 = wasm_v128_bitselect(vacc0, va0, vmask0);
    vacc1 = wasm_v128_bitselect(vacc1, va1, vmask1);
    vacc2 = wasm_v128_bitselect(vacc2, va2, vmask2);
    vacc3 = wasm_v128_bitselect(vacc3, va3, vmask3);

    wasm_v128_store(output, vacc0);
    wasm_v128_store(output + 4, vacc1);
    wasm_v128_store(output + 8, vacc2);
    wasm_v128_store(output + 12, vacc3);
    output += 16;
  }
  for (; batch >= 4 * sizeof(float); batch -= 4 * sizeof(float)) {
    const v128_t va = wasm_v128_load(input_a);
    input_a += 4;

    const v128_t vb = wasm_v128_load(input_b);
    input_b += 4;

    v128_t vacc = wasm_f32x4_mul(va, vb);
    const v128_t vmask = wasm_i32x4_shr(va, 31);

    vacc = wasm_v128_bitselect(vacc, va, vmask);


    wasm_v128_store(output, vacc);
    output += 4;
  }
  if XNN_UNLIKELY(batch != 0) {
    const v128_t va = wasm_v128_load(input_a);
    const v128_t vb = wasm_v128_load(input_b);

    v128_t vacc = wasm_f32x4_mul(va, vb);
    const v128_t vmask = wasm_i32x4_shr(va, 31);

    vacc = wasm_v128_bitselect(vacc, va, vmask);


    if (batch & (2 * sizeof(float))) {
      wasm_v128_store64_lane(output, vacc, 0);
      vacc = wasm_v64x2_shuffle(vacc, vacc, 1, 1);
      output += 2;
    }
    if (batch & (1 * sizeof(float))) {
      wasm_v128_store32_lane(output, vacc, 0);
    }
  }
}

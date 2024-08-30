"""
Microkernel filenames lists for f16c.

Auto-generated file. Do not edit!
  Generator: tools/update-microkernels.py
"""

PROD_F16C_MICROKERNEL_SRCS = [
    "src/f16-avgpool/f16-avgpool-9p8x-minmax-f16c-c8.c",
    "src/f16-avgpool/f16-avgpool-9x-minmax-f16c-c8.c",
    "src/f16-f32-vcvt/gen/f16-f32-vcvt-f16c-u16.c",
    "src/f16-f32acc-rdsum/gen/f16-f32acc-rdsum-7p7x-f16c-c32.c",
    "src/f16-f32acc-rsum/gen/f16-f32acc-rsum-f16c-u32-acc4.c",
    "src/f16-gavgpool/gen/f16-gavgpool-7p7x-minmax-f16c-c8.c",
    "src/f16-gavgpool/gen/f16-gavgpool-7x-minmax-f16c-c8.c",
    "src/f16-maxpool/f16-maxpool-9p8x-minmax-f16c-c8.c",
    "src/f16-prelu/gen/f16-prelu-f16c-2x16.c",
    "src/f16-rminmax/f16-rmax-f16c-u32.c",
    "src/f16-vbinary/gen/f16-vadd-minmax-f16c-u16.c",
    "src/f16-vbinary/gen/f16-vaddc-minmax-f16c-u16.c",
    "src/f16-vbinary/gen/f16-vdiv-minmax-f16c-u8.c",
    "src/f16-vbinary/gen/f16-vdivc-minmax-f16c-u8.c",
    "src/f16-vbinary/gen/f16-vmax-f16c-u16.c",
    "src/f16-vbinary/gen/f16-vmaxc-f16c-u16.c",
    "src/f16-vbinary/gen/f16-vmin-f16c-u16.c",
    "src/f16-vbinary/gen/f16-vminc-f16c-u16.c",
    "src/f16-vbinary/gen/f16-vmul-minmax-f16c-u16.c",
    "src/f16-vbinary/gen/f16-vmulc-minmax-f16c-u16.c",
    "src/f16-vbinary/gen/f16-vrdivc-minmax-f16c-u8.c",
    "src/f16-vbinary/gen/f16-vrsubc-minmax-f16c-u16.c",
    "src/f16-vbinary/gen/f16-vsqrdiff-f16c-u16.c",
    "src/f16-vbinary/gen/f16-vsqrdiffc-f16c-u16.c",
    "src/f16-vbinary/gen/f16-vsub-minmax-f16c-u16.c",
    "src/f16-vbinary/gen/f16-vsubc-minmax-f16c-u16.c",
    "src/f16-vclamp/gen/f16-vclamp-f16c-u16.c",
    "src/f16-vhswish/gen/f16-vhswish-f16c-u16.c",
    "src/f16-vlrelu/gen/f16-vlrelu-f16c-u16.c",
    "src/f16-vrnd/gen/f16-vrndd-f16c-u16.c",
    "src/f16-vrnd/gen/f16-vrndne-f16c-u16.c",
    "src/f16-vrnd/gen/f16-vrndu-f16c-u16.c",
    "src/f16-vrnd/gen/f16-vrndz-f16c-u16.c",
    "src/f16-vrsqrt/gen/f16-vrsqrt-f16c-rsqrt-u32.c",
    "src/f16-vsqrt/gen/f16-vsqrt-f16c-rsqrt-u32.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-rcp-u72.c",
    "src/f16-vunary/gen/f16-vsqr-f16c-u16.c",
    "src/f32-f16-vcvt/gen/f32-f16-vcvt-f16c-u16.c",
]

NON_PROD_F16C_MICROKERNEL_SRCS = [
    "src/f16-f32-vcvt/gen/f16-f32-vcvt-f16c-u8.c",
    "src/f16-f32acc-rdsum/gen/f16-f32acc-rdsum-7p7x-f16c-c16.c",
    "src/f16-f32acc-rdsum/gen/f16-f32acc-rdsum-7p7x-f16c-c64.c",
    "src/f16-f32acc-rdsum/gen/f16-f32acc-rdsum-7p7x-f16c-c128.c",
    "src/f16-f32acc-rsum/gen/f16-f32acc-rsum-f16c-u8.c",
    "src/f16-f32acc-rsum/gen/f16-f32acc-rsum-f16c-u16-acc2.c",
    "src/f16-f32acc-rsum/gen/f16-f32acc-rsum-f16c-u24-acc3.c",
    "src/f16-f32acc-rsum/gen/f16-f32acc-rsum-f16c-u32-acc2.c",
    "src/f16-gavgpool/gen/f16-gavgpool-7p7x-minmax-f16c-c16.c",
    "src/f16-gavgpool/gen/f16-gavgpool-7p7x-minmax-f16c-c24.c",
    "src/f16-gavgpool/gen/f16-gavgpool-7p7x-minmax-f16c-c32.c",
    "src/f16-gavgpool/gen/f16-gavgpool-7x-minmax-f16c-c16.c",
    "src/f16-gavgpool/gen/f16-gavgpool-7x-minmax-f16c-c24.c",
    "src/f16-gavgpool/gen/f16-gavgpool-7x-minmax-f16c-c32.c",
    "src/f16-prelu/gen/f16-prelu-f16c-2x8.c",
    "src/f16-vbinary/gen/f16-vadd-minmax-f16c-u8.c",
    "src/f16-vbinary/gen/f16-vaddc-minmax-f16c-u8.c",
    "src/f16-vbinary/gen/f16-vdiv-minmax-f16c-u16.c",
    "src/f16-vbinary/gen/f16-vdivc-minmax-f16c-u16.c",
    "src/f16-vbinary/gen/f16-vmax-f16c-u8.c",
    "src/f16-vbinary/gen/f16-vmaxc-f16c-u8.c",
    "src/f16-vbinary/gen/f16-vmin-f16c-u8.c",
    "src/f16-vbinary/gen/f16-vminc-f16c-u8.c",
    "src/f16-vbinary/gen/f16-vmul-minmax-f16c-u8.c",
    "src/f16-vbinary/gen/f16-vmulc-minmax-f16c-u8.c",
    "src/f16-vbinary/gen/f16-vprelu-f16c-u8.c",
    "src/f16-vbinary/gen/f16-vprelu-f16c-u16.c",
    "src/f16-vbinary/gen/f16-vpreluc-f16c-u8.c",
    "src/f16-vbinary/gen/f16-vpreluc-f16c-u16.c",
    "src/f16-vbinary/gen/f16-vrdivc-minmax-f16c-u16.c",
    "src/f16-vbinary/gen/f16-vrpreluc-f16c-u8.c",
    "src/f16-vbinary/gen/f16-vrpreluc-f16c-u16.c",
    "src/f16-vbinary/gen/f16-vrsubc-minmax-f16c-u8.c",
    "src/f16-vbinary/gen/f16-vsqrdiff-f16c-u8.c",
    "src/f16-vbinary/gen/f16-vsqrdiffc-f16c-u8.c",
    "src/f16-vbinary/gen/f16-vsub-minmax-f16c-u8.c",
    "src/f16-vbinary/gen/f16-vsubc-minmax-f16c-u8.c",
    "src/f16-vclamp/gen/f16-vclamp-f16c-u8.c",
    "src/f16-vhswish/gen/f16-vhswish-f16c-u8.c",
    "src/f16-vlrelu/gen/f16-vlrelu-f16c-u8.c",
    "src/f16-vrnd/gen/f16-vrndd-f16c-u8.c",
    "src/f16-vrnd/gen/f16-vrndne-f16c-u8.c",
    "src/f16-vrnd/gen/f16-vrndu-f16c-u8.c",
    "src/f16-vrnd/gen/f16-vrndz-f16c-u8.c",
    "src/f16-vrsqrt/gen/f16-vrsqrt-f16c-rsqrt-u8.c",
    "src/f16-vrsqrt/gen/f16-vrsqrt-f16c-rsqrt-u16.c",
    "src/f16-vsqrt/gen/f16-vsqrt-f16c-rsqrt-u8.c",
    "src/f16-vsqrt/gen/f16-vsqrt-f16c-rsqrt-u16.c",
    "src/f16-vsqrt/gen/f16-vsqrt-f16c-sqrt-u8.c",
    "src/f16-vsqrt/gen/f16-vsqrt-f16c-sqrt-u16.c",
    "src/f16-vsqrt/gen/f16-vsqrt-f16c-sqrt-u32.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-div-u8.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-div-u16.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-div-u24.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-div-u32.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-div-u40.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-div-u48.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-div-u56.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-div-u64.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-div-u72.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-div-u80.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-rcp-u8.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-rcp-u16.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-rcp-u24.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-rcp-u32.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-rcp-u40.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-rcp-u48.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-rcp-u56.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-rcp-u64.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-expm1minus-rr1-p3h2ts-rcp-u80.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-polynomial-p19h9t2-u8.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-polynomial-p19h9t2-u16.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-polynomial-p19h9t2-u24.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-polynomial-p19h9t2-u32.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-polynomial-p19h9t2-u40.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-polynomial-p19h9t2-u48.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-polynomial-p19h9t2-u56.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-polynomial-p19h9t2-u64.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-polynomial-p19h9t2-u72.c",
    "src/f16-vtanh/gen/f16-vtanh-f16c-polynomial-p19h9t2-u80.c",
    "src/f16-vunary/gen/f16-vsqr-f16c-u8.c",
    "src/f32-f16-vcvt/gen/f32-f16-vcvt-f16c-u8.c",
]

ALL_F16C_MICROKERNEL_SRCS = PROD_F16C_MICROKERNEL_SRCS + NON_PROD_F16C_MICROKERNEL_SRCS

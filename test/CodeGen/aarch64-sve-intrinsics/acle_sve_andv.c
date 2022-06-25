// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -emit-llvm -o - -x c++ %s | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sve -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sve -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -emit-llvm -o - -x c++ %s | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -o /dev/null %s
#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1,A2_UNUSED,A3,A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1,A2,A3,A4) A1##A2##A3##A4
#endif

// CHECK-LABEL: @test_svandv_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call i8 @llvm.aarch64.sve.andv.nxv16i8(<vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP:%.*]])
// CHECK-NEXT:    ret i8 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z14test_svandv_s8u10__SVBool_tu10__SVInt8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = call i8 @llvm.aarch64.sve.andv.nxv16i8(<vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret i8 [[TMP0]]
//
int8_t test_svandv_s8(svbool_t pg, svint8_t op)
{
  return SVE_ACLE_FUNC(svandv,_s8,,)(pg, op);
}

// CHECK-LABEL: @test_svandv_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = call i16 @llvm.aarch64.sve.andv.nxv8i16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP:%.*]])
// CHECK-NEXT:    ret i16 [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z15test_svandv_s16u10__SVBool_tu11__SVInt16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = call i16 @llvm.aarch64.sve.andv.nxv8i16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret i16 [[TMP1]]
//
int16_t test_svandv_s16(svbool_t pg, svint16_t op)
{
  return SVE_ACLE_FUNC(svandv,_s16,,)(pg, op);
}

// CHECK-LABEL: @test_svandv_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = call i32 @llvm.aarch64.sve.andv.nxv4i32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP:%.*]])
// CHECK-NEXT:    ret i32 [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z15test_svandv_s32u10__SVBool_tu11__SVInt32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = call i32 @llvm.aarch64.sve.andv.nxv4i32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret i32 [[TMP1]]
//
int32_t test_svandv_s32(svbool_t pg, svint32_t op)
{
  return SVE_ACLE_FUNC(svandv,_s32,,)(pg, op);
}

// CHECK-LABEL: @test_svandv_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = call i64 @llvm.aarch64.sve.andv.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP:%.*]])
// CHECK-NEXT:    ret i64 [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z15test_svandv_s64u10__SVBool_tu11__SVInt64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = call i64 @llvm.aarch64.sve.andv.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret i64 [[TMP1]]
//
int64_t test_svandv_s64(svbool_t pg, svint64_t op)
{
  return SVE_ACLE_FUNC(svandv,_s64,,)(pg, op);
}

// CHECK-LABEL: @test_svandv_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call i8 @llvm.aarch64.sve.andv.nxv16i8(<vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP:%.*]])
// CHECK-NEXT:    ret i8 [[TMP0]]
//
// CPP-CHECK-LABEL: @_Z14test_svandv_u8u10__SVBool_tu11__SVUint8_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = call i8 @llvm.aarch64.sve.andv.nxv16i8(<vscale x 16 x i1> [[PG:%.*]], <vscale x 16 x i8> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret i8 [[TMP0]]
//
uint8_t test_svandv_u8(svbool_t pg, svuint8_t op)
{
  return SVE_ACLE_FUNC(svandv,_u8,,)(pg, op);
}

// CHECK-LABEL: @test_svandv_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = call i16 @llvm.aarch64.sve.andv.nxv8i16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP:%.*]])
// CHECK-NEXT:    ret i16 [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z15test_svandv_u16u10__SVBool_tu12__SVUint16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = call i16 @llvm.aarch64.sve.andv.nxv8i16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x i16> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret i16 [[TMP1]]
//
uint16_t test_svandv_u16(svbool_t pg, svuint16_t op)
{
  return SVE_ACLE_FUNC(svandv,_u16,,)(pg, op);
}

// CHECK-LABEL: @test_svandv_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = call i32 @llvm.aarch64.sve.andv.nxv4i32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP:%.*]])
// CHECK-NEXT:    ret i32 [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z15test_svandv_u32u10__SVBool_tu12__SVUint32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = call i32 @llvm.aarch64.sve.andv.nxv4i32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x i32> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret i32 [[TMP1]]
//
uint32_t test_svandv_u32(svbool_t pg, svuint32_t op)
{
  return SVE_ACLE_FUNC(svandv,_u32,,)(pg, op);
}

// CHECK-LABEL: @test_svandv_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = call i64 @llvm.aarch64.sve.andv.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP:%.*]])
// CHECK-NEXT:    ret i64 [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z15test_svandv_u64u10__SVBool_tu12__SVUint64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = call i64 @llvm.aarch64.sve.andv.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[OP:%.*]])
// CPP-CHECK-NEXT:    ret i64 [[TMP1]]
//
uint64_t test_svandv_u64(svbool_t pg, svuint64_t op)
{
  return SVE_ACLE_FUNC(svandv,_u64,,)(pg, op);
}

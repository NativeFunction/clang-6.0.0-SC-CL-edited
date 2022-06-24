// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -O3 -triple powerpc64le-unknown-unknown -target-cpu pwr10 \
// RUN: -emit-llvm %s -o - | FileCheck %s --check-prefix=CHECK-LE
// RUN: %clang_cc1 -O3 -triple powerpc64-unknown-unknown -target-cpu pwr10 \
// RUN: -emit-llvm %s -o - | FileCheck %s --check-prefix=CHECK-BE

// CHECK-LE-LABEL: @test1(
// CHECK-LE-NEXT:  entry:
// CHECK-LE-NEXT:    [[TMP0:%.*]] = tail call <512 x i1> @llvm.ppc.mma.assemble.acc(<16 x i8> [[VC4:%.*]], <16 x i8> [[VC3:%.*]], <16 x i8> [[VC2:%.*]], <16 x i8> [[VC1:%.*]])
// CHECK-LE-NEXT:    [[TMP1:%.*]] = bitcast i8* [[RESP:%.*]] to <512 x i1>*
// CHECK-LE-NEXT:    store <512 x i1> [[TMP0]], <512 x i1>* [[TMP1]], align 64, !tbaa [[TBAA2:![0-9]+]]
// CHECK-LE-NEXT:    ret void
//
// CHECK-BE-LABEL: @test1(
// CHECK-BE-NEXT:  entry:
// CHECK-BE-NEXT:    [[TMP0:%.*]] = tail call <512 x i1> @llvm.ppc.mma.assemble.acc(<16 x i8> [[VC1:%.*]], <16 x i8> [[VC2:%.*]], <16 x i8> [[VC3:%.*]], <16 x i8> [[VC4:%.*]])
// CHECK-BE-NEXT:    [[TMP1:%.*]] = bitcast i8* [[RESP:%.*]] to <512 x i1>*
// CHECK-BE-NEXT:    store <512 x i1> [[TMP0]], <512 x i1>* [[TMP1]], align 64, !tbaa [[TBAA2:![0-9]+]]
// CHECK-BE-NEXT:    ret void
//
void test1(unsigned char *vqp, unsigned char *vpp, vector unsigned char vc1, vector unsigned char vc2,
            vector unsigned char vc3, vector unsigned char vc4, unsigned char *resp) {
  __vector_quad vq = *((__vector_quad *)vqp);
  __vector_pair vp = *((__vector_pair *)vpp);
  __vector_quad res;
  __builtin_mma_build_acc(&res, vc1, vc2, vc3, vc4);
  *((__vector_quad *)resp) = res;
}

// CHECK-LE-LABEL: @test2(
// CHECK-LE-NEXT:  entry:
// CHECK-LE-NEXT:    [[TMP0:%.*]] = tail call <256 x i1> @llvm.ppc.vsx.assemble.pair(<16 x i8> [[VC2:%.*]], <16 x i8> [[VC1:%.*]])
// CHECK-LE-NEXT:    [[TMP1:%.*]] = bitcast i8* [[RESP:%.*]] to <256 x i1>*
// CHECK-LE-NEXT:    store <256 x i1> [[TMP0]], <256 x i1>* [[TMP1]], align 32, !tbaa [[TBAA6:![0-9]+]]
// CHECK-LE-NEXT:    ret void
//
// CHECK-BE-LABEL: @test2(
// CHECK-BE-NEXT:  entry:
// CHECK-BE-NEXT:    [[TMP0:%.*]] = tail call <256 x i1> @llvm.ppc.vsx.assemble.pair(<16 x i8> [[VC1:%.*]], <16 x i8> [[VC2:%.*]])
// CHECK-BE-NEXT:    [[TMP1:%.*]] = bitcast i8* [[RESP:%.*]] to <256 x i1>*
// CHECK-BE-NEXT:    store <256 x i1> [[TMP0]], <256 x i1>* [[TMP1]], align 32, !tbaa [[TBAA6:![0-9]+]]
// CHECK-BE-NEXT:    ret void
//
void test2(unsigned char *vqp, unsigned char *vpp, vector unsigned char vc1,
            vector unsigned char vc2, unsigned char *resp) {
  __vector_quad vq = *((__vector_quad *)vqp);
  __vector_pair vp = *((__vector_pair *)vpp);
  __vector_pair res;
  __builtin_vsx_build_pair(&res, vc1, vc2);
  *((__vector_pair *)resp) = res;
}

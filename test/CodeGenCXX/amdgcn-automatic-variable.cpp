// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -O0 -triple amdgcn---amdgiz -emit-llvm %s -o - | FileCheck %s

// CHECK-LABEL: @_Z5func1Pi(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[X_ADDR:%.*]] = alloca i32*, align 8, addrspace(5)
// CHECK-NEXT:    [[X_ADDR_ASCAST:%.*]] = addrspacecast i32* addrspace(5)* [[X_ADDR]] to i32**
// CHECK-NEXT:    store i32* [[X:%.*]], i32** [[X_ADDR_ASCAST]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load i32*, i32** [[X_ADDR_ASCAST]], align 8
// CHECK-NEXT:    store i32 1, i32* [[TMP0]], align 4
// CHECK-NEXT:    ret void
//
void func1(int *x) {
  *x = 1;
}

// CHECK-LABEL: @_Z5func2v(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[LV1:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-NEXT:    [[LV2:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-NEXT:    [[LA:%.*]] = alloca [100 x i32], align 4, addrspace(5)
// CHECK-NEXT:    [[LP1:%.*]] = alloca i32*, align 8, addrspace(5)
// CHECK-NEXT:    [[LP2:%.*]] = alloca i32*, align 8, addrspace(5)
// CHECK-NEXT:    [[LVC:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-NEXT:    [[LV1_ASCAST:%.*]] = addrspacecast i32 addrspace(5)* [[LV1]] to i32*
// CHECK-NEXT:    [[LV2_ASCAST:%.*]] = addrspacecast i32 addrspace(5)* [[LV2]] to i32*
// CHECK-NEXT:    [[LA_ASCAST:%.*]] = addrspacecast [100 x i32] addrspace(5)* [[LA]] to [100 x i32]*
// CHECK-NEXT:    [[LP1_ASCAST:%.*]] = addrspacecast i32* addrspace(5)* [[LP1]] to i32**
// CHECK-NEXT:    [[LP2_ASCAST:%.*]] = addrspacecast i32* addrspace(5)* [[LP2]] to i32**
// CHECK-NEXT:    [[LVC_ASCAST:%.*]] = addrspacecast i32 addrspace(5)* [[LVC]] to i32*
// CHECK-NEXT:    store i32 1, i32* [[LV1_ASCAST]], align 4
// CHECK-NEXT:    store i32 2, i32* [[LV2_ASCAST]], align 4
// CHECK-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds [100 x i32], [100 x i32]* [[LA_ASCAST]], i64 0, i64 0
// CHECK-NEXT:    store i32 3, i32* [[ARRAYIDX]], align 4
// CHECK-NEXT:    store i32* [[LV1_ASCAST]], i32** [[LP1_ASCAST]], align 8
// CHECK-NEXT:    [[ARRAYDECAY:%.*]] = getelementptr inbounds [100 x i32], [100 x i32]* [[LA_ASCAST]], i64 0, i64 0
// CHECK-NEXT:    store i32* [[ARRAYDECAY]], i32** [[LP2_ASCAST]], align 8
// CHECK-NEXT:    call void @_Z5func1Pi(i32* noundef [[LV1_ASCAST]])
// CHECK-NEXT:    store i32 4, i32* [[LVC_ASCAST]], align 4
// CHECK-NEXT:    store i32 4, i32* [[LV1_ASCAST]], align 4
// CHECK-NEXT:    ret void
//
void func2(void) {

  int lv1;
  lv1 = 1;
  int lv2 = 2;

  int la[100];
  la[0] = 3;

  int *lp1 = &lv1;

  int *lp2 = la;

  func1(&lv1);

  const int lvc = 4;
  lv1 = lvc;
}

void destroy(int x);

class A {
int x;
public:
  A():x(0) {}
  ~A() {
   destroy(x);
  }
};

// CHECK-LABEL: @_Z5func3v(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[A:%.*]] = alloca [[CLASS_A:%.*]], align 4, addrspace(5)
// CHECK-NEXT:    [[A_ASCAST:%.*]] = addrspacecast [[CLASS_A]] addrspace(5)* [[A]] to %class.A*
// CHECK-NEXT:    call void @_ZN1AC1Ev(%class.A* noundef nonnull align 4 dereferenceable(4) [[A_ASCAST]])
// CHECK-NEXT:    call void @_ZN1AD1Ev(%class.A* noundef nonnull align 4 dereferenceable(4) [[A_ASCAST]])
// CHECK-NEXT:    ret void
//
void func3() {
  A a;
}

// CHECK-LABEL: @_Z5func4i(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[X_ADDR:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-NEXT:    [[X_ADDR_ASCAST:%.*]] = addrspacecast i32 addrspace(5)* [[X_ADDR]] to i32*
// CHECK-NEXT:    store i32 [[X:%.*]], i32* [[X_ADDR_ASCAST]], align 4
// CHECK-NEXT:    call void @_Z5func1Pi(i32* noundef [[X_ADDR_ASCAST]])
// CHECK-NEXT:    ret void
//
void func4(int x) {
  func1(&x);
}

// CHECK-LABEL: @_Z5func5v(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[X:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-NEXT:    [[X_ASCAST:%.*]] = addrspacecast i32 addrspace(5)* [[X]] to i32*
// CHECK-NEXT:    ret void
//
void func5() {
  return;
  int x = 0;
}

// CHECK-LABEL: @_Z5func6v(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[X:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-NEXT:    [[X_ASCAST:%.*]] = addrspacecast i32 addrspace(5)* [[X]] to i32*
// CHECK-NEXT:    ret void
//
void func6() {
  return;
  int x;
}

extern void use(int *);
// CHECK-LABEL: @_Z5func7v(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[X:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-NEXT:    [[X_ASCAST:%.*]] = addrspacecast i32 addrspace(5)* [[X]] to i32*
// CHECK-NEXT:    br label [[LATER:%.*]]
// CHECK:       later:
// CHECK-NEXT:    call void @_Z3usePi(i32* noundef [[X_ASCAST]])
// CHECK-NEXT:    ret void
//
void func7() {
  goto later;
  int x;
later:
  use(&x);
}


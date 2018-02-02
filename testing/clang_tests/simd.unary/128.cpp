// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang -std=c++11 -S -O2 -msse4.2 -o - %s | FileCheck -check-prefix=CHECK-SSE42 %s
// RUN: %clang -std=c++11 -S -O2 -mavx2 -o - %s | FileCheck -check-prefix=CHECK-AVX2 %s
#include "dimsum.h"
using namespace dimsum;

extern "C" {

// CHECK-SSE42-LABEL: operatorADD_0:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorADD_0:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    retq
Simd128<int8> operatorADD_0(Simd128<int8> a) {
  return operator+(a);
}

// CHECK-SSE42-LABEL: operatorADD_1:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorADD_1:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    retq
Simd128<int16> operatorADD_1(Simd128<int16> a) {
  return operator+(a);
}

// CHECK-SSE42-LABEL: operatorADD_2:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorADD_2:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    retq
Simd128<int32> operatorADD_2(Simd128<int32> a) {
  return operator+(a);
}

// CHECK-SSE42-LABEL: operatorADD_3:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorADD_3:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    retq
Simd128<int64> operatorADD_3(Simd128<int64> a) {
  return operator+(a);
}

// CHECK-SSE42-LABEL: operatorADD_4:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorADD_4:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    retq
Simd128<uint8> operatorADD_4(Simd128<uint8> a) {
  return operator+(a);
}

// CHECK-SSE42-LABEL: operatorADD_5:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorADD_5:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    retq
Simd128<uint16> operatorADD_5(Simd128<uint16> a) {
  return operator+(a);
}

// CHECK-SSE42-LABEL: operatorADD_6:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorADD_6:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    retq
Simd128<uint32> operatorADD_6(Simd128<uint32> a) {
  return operator+(a);
}

// CHECK-SSE42-LABEL: operatorADD_7:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorADD_7:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    retq
Simd128<uint64> operatorADD_7(Simd128<uint64> a) {
  return operator+(a);
}

// CHECK-SSE42-LABEL: operatorADD_8:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorADD_8:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    retq
Simd128<float> operatorADD_8(Simd128<float> a) {
  return operator+(a);
}

// CHECK-SSE42-LABEL: operatorADD_9:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorADD_9:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    retq
Simd128<double> operatorADD_9(Simd128<double> a) {
  return operator+(a);
}

// CHECK-SSE42-LABEL: operatorSUB_0:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    pxor %xmm1, %xmm1
// CHECK-SSE42-NEXT:    psubb %xmm0, %xmm1
// CHECK-SSE42-NEXT:    movdqa %xmm1, %xmm0
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorSUB_0:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    vpxor %xmm1, %xmm1, %xmm1
// CHECK-AVX2-NEXT:    vpsubb %xmm0, %xmm1, %xmm0
// CHECK-AVX2-NEXT:    retq
Simd128<int8> operatorSUB_0(Simd128<int8> a) {
  return operator-(a);
}

// CHECK-SSE42-LABEL: operatorSUB_1:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    pxor %xmm1, %xmm1
// CHECK-SSE42-NEXT:    psubw %xmm0, %xmm1
// CHECK-SSE42-NEXT:    movdqa %xmm1, %xmm0
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorSUB_1:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    vpxor %xmm1, %xmm1, %xmm1
// CHECK-AVX2-NEXT:    vpsubw %xmm0, %xmm1, %xmm0
// CHECK-AVX2-NEXT:    retq
Simd128<int16> operatorSUB_1(Simd128<int16> a) {
  return operator-(a);
}

// CHECK-SSE42-LABEL: operatorSUB_2:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    pxor %xmm1, %xmm1
// CHECK-SSE42-NEXT:    psubd %xmm0, %xmm1
// CHECK-SSE42-NEXT:    movdqa %xmm1, %xmm0
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorSUB_2:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    vpxor %xmm1, %xmm1, %xmm1
// CHECK-AVX2-NEXT:    vpsubd %xmm0, %xmm1, %xmm0
// CHECK-AVX2-NEXT:    retq
Simd128<int32> operatorSUB_2(Simd128<int32> a) {
  return operator-(a);
}

// CHECK-SSE42-LABEL: operatorSUB_3:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    pxor %xmm1, %xmm1
// CHECK-SSE42-NEXT:    psubq %xmm0, %xmm1
// CHECK-SSE42-NEXT:    movdqa %xmm1, %xmm0
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorSUB_3:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    vpxor %xmm1, %xmm1, %xmm1
// CHECK-AVX2-NEXT:    vpsubq %xmm0, %xmm1, %xmm0
// CHECK-AVX2-NEXT:    retq
Simd128<int64> operatorSUB_3(Simd128<int64> a) {
  return operator-(a);
}

// CHECK-SSE42-LABEL: operatorSUB_4:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    pxor %xmm1, %xmm1
// CHECK-SSE42-NEXT:    psubb %xmm0, %xmm1
// CHECK-SSE42-NEXT:    movdqa %xmm1, %xmm0
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorSUB_4:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    vpxor %xmm1, %xmm1, %xmm1
// CHECK-AVX2-NEXT:    vpsubb %xmm0, %xmm1, %xmm0
// CHECK-AVX2-NEXT:    retq
Simd128<uint8> operatorSUB_4(Simd128<uint8> a) {
  return operator-(a);
}

// CHECK-SSE42-LABEL: operatorSUB_5:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    pxor %xmm1, %xmm1
// CHECK-SSE42-NEXT:    psubw %xmm0, %xmm1
// CHECK-SSE42-NEXT:    movdqa %xmm1, %xmm0
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorSUB_5:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    vpxor %xmm1, %xmm1, %xmm1
// CHECK-AVX2-NEXT:    vpsubw %xmm0, %xmm1, %xmm0
// CHECK-AVX2-NEXT:    retq
Simd128<uint16> operatorSUB_5(Simd128<uint16> a) {
  return operator-(a);
}

// CHECK-SSE42-LABEL: operatorSUB_6:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    pxor %xmm1, %xmm1
// CHECK-SSE42-NEXT:    psubd %xmm0, %xmm1
// CHECK-SSE42-NEXT:    movdqa %xmm1, %xmm0
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorSUB_6:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    vpxor %xmm1, %xmm1, %xmm1
// CHECK-AVX2-NEXT:    vpsubd %xmm0, %xmm1, %xmm0
// CHECK-AVX2-NEXT:    retq
Simd128<uint32> operatorSUB_6(Simd128<uint32> a) {
  return operator-(a);
}

// CHECK-SSE42-LABEL: operatorSUB_7:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    pxor %xmm1, %xmm1
// CHECK-SSE42-NEXT:    psubq %xmm0, %xmm1
// CHECK-SSE42-NEXT:    movdqa %xmm1, %xmm0
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorSUB_7:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    vpxor %xmm1, %xmm1, %xmm1
// CHECK-AVX2-NEXT:    vpsubq %xmm0, %xmm1, %xmm0
// CHECK-AVX2-NEXT:    retq
Simd128<uint64> operatorSUB_7(Simd128<uint64> a) {
  return operator-(a);
}

// CHECK-SSE42-LABEL: operatorSUB_8:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    xorps {{.*}}(%rip), %xmm0
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorSUB_8:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    vbroadcastss {{.*#+}} xmm1 = [-0,-0,-0,-0]
// CHECK-AVX2-NEXT:    vxorps %xmm1, %xmm0, %xmm0
// CHECK-AVX2-NEXT:    retq
Simd128<float> operatorSUB_8(Simd128<float> a) {
  return operator-(a);
}

// CHECK-SSE42-LABEL: operatorSUB_9:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    xorps {{.*}}(%rip), %xmm0
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorSUB_9:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    vxorps {{.*}}(%rip), %xmm0, %xmm0
// CHECK-AVX2-NEXT:    retq
Simd128<double> operatorSUB_9(Simd128<double> a) {
  return operator-(a);
}

// CHECK-SSE42-LABEL: operatorNOT_0:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    pcmpeqd %xmm1, %xmm1
// CHECK-SSE42-NEXT:    pxor %xmm1, %xmm0
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorNOT_0:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    vpcmpeqd %xmm1, %xmm1, %xmm1
// CHECK-AVX2-NEXT:    vpxor %xmm1, %xmm0, %xmm0
// CHECK-AVX2-NEXT:    retq
Simd128<int8> operatorNOT_0(Simd128<int8> a) {
  return operator~(a);
}

// CHECK-SSE42-LABEL: operatorNOT_1:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    pcmpeqd %xmm1, %xmm1
// CHECK-SSE42-NEXT:    pxor %xmm1, %xmm0
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorNOT_1:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    vpcmpeqd %xmm1, %xmm1, %xmm1
// CHECK-AVX2-NEXT:    vpxor %xmm1, %xmm0, %xmm0
// CHECK-AVX2-NEXT:    retq
Simd128<int16> operatorNOT_1(Simd128<int16> a) {
  return operator~(a);
}

// CHECK-SSE42-LABEL: operatorNOT_2:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    pcmpeqd %xmm1, %xmm1
// CHECK-SSE42-NEXT:    pxor %xmm1, %xmm0
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorNOT_2:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    vpcmpeqd %xmm1, %xmm1, %xmm1
// CHECK-AVX2-NEXT:    vpxor %xmm1, %xmm0, %xmm0
// CHECK-AVX2-NEXT:    retq
Simd128<int32> operatorNOT_2(Simd128<int32> a) {
  return operator~(a);
}

// CHECK-SSE42-LABEL: operatorNOT_3:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    pcmpeqd %xmm1, %xmm1
// CHECK-SSE42-NEXT:    pxor %xmm1, %xmm0
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorNOT_3:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    vpcmpeqd %xmm1, %xmm1, %xmm1
// CHECK-AVX2-NEXT:    vpxor %xmm1, %xmm0, %xmm0
// CHECK-AVX2-NEXT:    retq
Simd128<int64> operatorNOT_3(Simd128<int64> a) {
  return operator~(a);
}

// CHECK-SSE42-LABEL: operatorNOT_4:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    pcmpeqd %xmm1, %xmm1
// CHECK-SSE42-NEXT:    pxor %xmm1, %xmm0
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorNOT_4:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    vpcmpeqd %xmm1, %xmm1, %xmm1
// CHECK-AVX2-NEXT:    vpxor %xmm1, %xmm0, %xmm0
// CHECK-AVX2-NEXT:    retq
Simd128<uint8> operatorNOT_4(Simd128<uint8> a) {
  return operator~(a);
}

// CHECK-SSE42-LABEL: operatorNOT_5:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    pcmpeqd %xmm1, %xmm1
// CHECK-SSE42-NEXT:    pxor %xmm1, %xmm0
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorNOT_5:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    vpcmpeqd %xmm1, %xmm1, %xmm1
// CHECK-AVX2-NEXT:    vpxor %xmm1, %xmm0, %xmm0
// CHECK-AVX2-NEXT:    retq
Simd128<uint16> operatorNOT_5(Simd128<uint16> a) {
  return operator~(a);
}

// CHECK-SSE42-LABEL: operatorNOT_6:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    pcmpeqd %xmm1, %xmm1
// CHECK-SSE42-NEXT:    pxor %xmm1, %xmm0
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorNOT_6:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    vpcmpeqd %xmm1, %xmm1, %xmm1
// CHECK-AVX2-NEXT:    vpxor %xmm1, %xmm0, %xmm0
// CHECK-AVX2-NEXT:    retq
Simd128<uint32> operatorNOT_6(Simd128<uint32> a) {
  return operator~(a);
}

// CHECK-SSE42-LABEL: operatorNOT_7:
// CHECK-SSE42:       # %bb.0: # %entry
// CHECK-SSE42-NEXT:    pcmpeqd %xmm1, %xmm1
// CHECK-SSE42-NEXT:    pxor %xmm1, %xmm0
// CHECK-SSE42-NEXT:    retq
//
// CHECK-AVX2-LABEL: operatorNOT_7:
// CHECK-AVX2:       # %bb.0: # %entry
// CHECK-AVX2-NEXT:    vpcmpeqd %xmm1, %xmm1, %xmm1
// CHECK-AVX2-NEXT:    vpxor %xmm1, %xmm0, %xmm0
// CHECK-AVX2-NEXT:    retq
Simd128<uint64> operatorNOT_7(Simd128<uint64> a) {
  return operator~(a);
}

}
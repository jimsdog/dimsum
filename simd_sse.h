/*
 * Copyright 2017 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef DIMSUM_SIMD_SSE_H_
#define DIMSUM_SIMD_SSE_H_

#ifdef __SSE3__
# include <pmmintrin.h>
#endif
#ifdef __SSSE3__
# include <tmmintrin.h>
#endif
#ifdef __SSE4_1__
# include <smmintrin.h>
#endif

#include "operations.h"

namespace dimsum {
namespace detail {

// SSE (16 bytes)
template <typename T>
struct ExternalTypeTraits<T, detail::Abi<StoragePolicy::kXmm, 16 / sizeof(T)>> {
  using type = __m128i;
};

template <>
struct ExternalTypeTraits<float, detail::Abi<StoragePolicy::kXmm, 4>> {
  using type = __m128;
};

template <>
struct ExternalTypeTraits<double, detail::Abi<StoragePolicy::kXmm, 2>> {
  using type = __m128d;
};

template <typename T>
struct LoadImpl<T, Abi<StoragePolicy::kXmm, 8 / sizeof(T)>,
                flags::vector_aligned_tag> {
  static Simd<T, Abi<StoragePolicy::kXmm, 8 / sizeof(T)>> Apply(
      const T* buffer) {
    Simd<T, Abi<StoragePolicy::kXmm, 8 / sizeof(T)>> ret;
    memcpy(&ret.storage_, buffer, sizeof(ret));
    return ret;
  }
};

template <typename T, size_t kNumElements>
struct LoadImpl<T, Abi<StoragePolicy::kXmm, kNumElements>,
                flags::vector_aligned_tag> {
  static Simd<T, Abi<StoragePolicy::kXmm, kNumElements>> Apply(
      const T* buffer) {
    Simd<T, Abi<StoragePolicy::kXmm, kNumElements>> ret;
    __m128i ret1[sizeof(ret) / 16];
    for (int i = 0; i < sizeof(ret) / 16; i++)
      ret1[i] = _mm_load_si128(reinterpret_cast<const __m128i*>(buffer) + i);
    memcpy(&ret.storage_, &ret1, sizeof(ret1));
    return ret;
  }
};

}  // namespace detail

#ifndef __AVX2__
template <typename T>
using NativeSimd =
    Simd<T, detail::Abi<detail::StoragePolicy::kXmm, 16 / sizeof(T)>>;
#endif

template <typename T>
using Simd128 =
    Simd<T, detail::Abi<detail::StoragePolicy::kXmm, 16 / sizeof(T)>>;

template <typename T>
using Simd64 = Simd<T, detail::Abi<detail::StoragePolicy::kXmm, 8 / sizeof(T)>>;

#ifdef __SSSE3__
template <>
inline Simd128<int8> abs(Simd128<int8> simd) {
  return _mm_abs_epi8(simd.raw());
}

template <>
inline Simd128<int16> abs(Simd128<int16> simd) {
  return _mm_abs_epi16(simd.raw());
}

template <>
inline Simd128<int32> abs(Simd128<int32> simd) {
  return _mm_abs_epi32(simd.raw());
}
#endif

#ifdef __AVX512VL__
template <>
inline Simd128<int64> abs(Simd128<int64> simd) {
  return _mm_abs_epi64(simd.raw());
}
#endif

// ::abs for floating points is implemented by bit_and each lane with shr(-1, 1)
// to clear the sign bit (the most significant bit).
template <>
inline Simd128<float> abs(Simd128<float> simd) {
  return bit_cast<float>(bit_cast<uint32>(simd) & Simd128<uint32>(~(1u << 31)));
}

template <>
inline Simd128<double> abs(Simd128<double> simd) {
  return bit_cast<double>(bit_cast<uint64>(simd) &
                          Simd128<uint64>(~(1ull << 63)));
}

template <>
inline Simd128<float> reciprocal_estimate(Simd128<float> simd) {
  return _mm_rcp_ps(simd.raw());
}

template <>
inline Simd128<float> sqrt(Simd128<float> simd) {
  return _mm_sqrt_ps(simd.raw());
}

template <>
inline Simd128<double> sqrt(Simd128<double> simd) {
  return _mm_sqrt_pd(simd.raw());
}

template <>
inline Simd128<float> reciprocal_sqrt_estimate(Simd128<float> simd) {
  return _mm_rsqrt_ps(simd.raw());
}

template <>
inline Simd128<int8> add_saturated(Simd128<int8> lhs, Simd128<int8> rhs) {
  return _mm_adds_epi8(lhs.raw(), rhs.raw());
}

template <>
inline Simd128<uint8> add_saturated(Simd128<uint8> lhs, Simd128<uint8> rhs) {
  return _mm_adds_epu8(lhs.raw(), rhs.raw());
}

template <>
inline Simd128<int16> add_saturated(Simd128<int16> lhs, Simd128<int16> rhs) {
  return _mm_adds_epi16(lhs.raw(), rhs.raw());
}

template <>
inline Simd128<uint16> add_saturated(Simd128<uint16> lhs, Simd128<uint16> rhs) {
  return _mm_adds_epu16(lhs.raw(), rhs.raw());
}

template <>
inline Simd128<int8> sub_saturated(Simd128<int8> lhs, Simd128<int8> rhs) {
  return _mm_subs_epi8(lhs.raw(), rhs.raw());
}

template <>
inline Simd128<uint8> sub_saturated(Simd128<uint8> lhs, Simd128<uint8> rhs) {
  return _mm_subs_epu8(lhs.raw(), rhs.raw());
}

template <>
inline Simd128<int16> sub_saturated(Simd128<int16> lhs, Simd128<int16> rhs) {
  return _mm_subs_epi16(lhs.raw(), rhs.raw());
}

template <>
inline Simd128<uint16> sub_saturated(Simd128<uint16> lhs, Simd128<uint16> rhs) {
  return _mm_subs_epu16(lhs.raw(), rhs.raw());
}

#ifdef __SSE4_1__
template <>
inline Simd128<int8> min(Simd128<int8> lhs, Simd128<int8> rhs) {
  return _mm_min_epi8(lhs.raw(), rhs.raw());
}
#endif

template <>
inline Simd128<int16> min(Simd128<int16> lhs, Simd128<int16> rhs) {
  return _mm_min_epi16(lhs.raw(), rhs.raw());
}

#ifdef __SSE4_1__
template <>
inline Simd128<int32> min(Simd128<int32> lhs, Simd128<int32> rhs) {
  return _mm_min_epi32(lhs.raw(), rhs.raw());
}
#endif

template <>
inline Simd128<uint8> min(Simd128<uint8> lhs, Simd128<uint8> rhs) {
  return _mm_min_epu8(lhs.raw(), rhs.raw());
}

#ifdef __SSE4_1__
template <>
inline Simd128<uint16> min(Simd128<uint16> lhs, Simd128<uint16> rhs) {
  return _mm_min_epu16(lhs.raw(), rhs.raw());
}

template <>
inline Simd128<uint32> min(Simd128<uint32> lhs, Simd128<uint32> rhs) {
  return _mm_min_epu32(lhs.raw(), rhs.raw());
}
#endif

template <>
inline Simd128<float> min(Simd128<float> lhs, Simd128<float> rhs) {
  return _mm_min_ps(lhs.raw(), rhs.raw());
}

template <>
inline Simd128<double> min(Simd128<double> lhs, Simd128<double> rhs) {
  return _mm_min_pd(lhs.raw(), rhs.raw());
}

#ifdef __SSE4_1__
template <>
inline Simd128<int8> max(Simd128<int8> lhs, Simd128<int8> rhs) {
  return _mm_max_epi8(lhs.raw(), rhs.raw());
}
#endif

template <>
inline Simd128<int16> max(Simd128<int16> lhs, Simd128<int16> rhs) {
  return _mm_max_epi16(lhs.raw(), rhs.raw());
}

#ifdef __SSE4_1__
template <>
inline Simd128<int32> max(Simd128<int32> lhs, Simd128<int32> rhs) {
  return _mm_max_epi32(lhs.raw(), rhs.raw());
}
#endif

template <>
inline Simd128<uint8> max(Simd128<uint8> lhs, Simd128<uint8> rhs) {
  return _mm_max_epu8(lhs.raw(), rhs.raw());
}

#ifdef __SSE4_1__
template <>
inline Simd128<uint16> max(Simd128<uint16> lhs, Simd128<uint16> rhs) {
  return _mm_max_epu16(lhs.raw(), rhs.raw());
}

template <>
inline Simd128<uint32> max(Simd128<uint32> lhs, Simd128<uint32> rhs) {
  return _mm_max_epu32(lhs.raw(), rhs.raw());
}
#endif

template <>
inline Simd128<float> max(Simd128<float> lhs, Simd128<float> rhs) {
  return _mm_max_ps(lhs.raw(), rhs.raw());
}

template <>
inline Simd128<double> max(Simd128<double> lhs, Simd128<double> rhs) {
  return _mm_max_pd(lhs.raw(), rhs.raw());
}

template <>
inline Simd128<uint64> reduce_add<uint64, 2>(Simd128<uint8> simd) {
  return _mm_sad_epu8(simd.raw(), Simd128<uint8>(0).raw());
}

template <>
inline Simd128<int32> reduce_add<int32, 4>(Simd128<int16> simd) {
  return _mm_madd_epi16(simd.raw(), Simd128<int16>(1).raw());
}

template <>
inline ResizeTo<Simd128<uint64>, 1> reduce_add<uint64, 1>(Simd128<uint8> simd) {
  return reduce_add<uint64, 1>(reduce_add<uint64, 2>(simd));
}

template <>
inline ResizeTo<Simd128<uint64>, 1> reduce_add<uint64, 1>(
    Simd128<uint16> simd) {
  uint64 even_sum =
      reduce_add<uint64, 1>(bit_cast<uint8>(simd & Simd128<uint16>(0x00ff)))[0];
  uint64 odd_sum =
      reduce_add<uint64, 1>(bit_cast<uint8>(simd & Simd128<uint16>(0xff00)))[0];
  return (odd_sum << 8) + even_sum;
}

template <>
inline float reduce(const Simd128<float>& simd, std::plus<float>) {
  return (simd[0] + simd[2]) + (simd[1] + simd[3]);
}

template <>
inline Simd128<int32> mul_sum<int32>(Simd128<int16> lhs, Simd128<int16> rhs,
                                     Simd128<int32> acc) {
  return _mm_add_epi32(acc.raw(), _mm_madd_epi16(lhs.raw(), rhs.raw()));
}

#ifdef __SSE4_1__
// _MM_FROUND_TO_NEAREST_INT specifies round-to-even.
template <>
inline Simd128<float> round(Simd128<float> simd) {
  return _mm_round_ps(simd.raw(),
                      _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
}

template <>
inline Simd128<double> round(Simd128<double> simd) {
  return _mm_round_pd(simd.raw(),
                      _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
}
#endif

template <>
inline Simd128<int32> round_to_integer(Simd128<float> simd) {
  return _mm_cvtps_epi32(simd.raw());
}

template <typename T>
Simd128<ScaleBy<T, 2>> mul_widened(Simd64<T> lhs, Simd64<T> rhs) {
  return simd_cast<ScaleBy<T, 2>>(lhs) * simd_cast<ScaleBy<T, 2>>(rhs);
}

}  // namespace dimsum

#endif  // DIMSUM_SIMD_SSE_H_

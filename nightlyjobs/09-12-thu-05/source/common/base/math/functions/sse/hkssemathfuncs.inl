// File Line: 20
// RVA: 0xE7EA90
__m128 __fastcall hkMath::quadReciprocal_143(__m128 *result, __m128 *r)
{
  __m128 v2; // xmm2

  v2 = _mm_rcp_ps(*result);
  return _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(*result, v2)), v2);
}

// File Line: 50
// RVA: 0xE7EAB0
__m128 __fastcall hkMath::quadReciprocalSquareRoot_178(__m128 *result, __m128 *r)
{
  __m128 v2; // xmm2

  v2 = _mm_rsqrt_ps(*result);
  return _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(*result, v2), v2)), _mm_mul_ps(*(__m128 *)_xmm, v2));
}

// File Line: 166
// RVA: 0xDD8690
float __fastcall hkMath::sqrt_20(const float r)
{
  return fsqrt(r);
}

// File Line: 171
// RVA: 0xC86F10
double __fastcall hkMath::sqrt_9(const long double r)
{
  return sqrt(r);
}

// File Line: 178
// RVA: 0xC58E80
float __fastcall hkMath::sqrtInverse(const float r)
{
  return 1.0 / fsqrt(r);
}

// File Line: 184
// RVA: 0xC8A9F0
double __fastcall hkMath::sqrtInverse_0(const long double r)
{
  return *(double *)_xmm / sqrt(r);
}

// File Line: 284
// RVA: 0xDC9E40
__m128 __fastcall hkMath::quadAtan2_4(__m128 *result, __m128 *y, __m128 *x)
{
  __m128 v3; // xmm0
  __m128 v4; // xmm1
  __m128 v5; // xmm5
  __m128 v6; // xmm4
  __m128 v7; // xmm3
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  __m128 v10; // xmm1

  v3 = _mm_rcp_ps(*y);
  v4 = _mm_mul_ps(*result, v3);
  v5 = _mm_or_ps(_mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v4), _mm_cmpltps(*(__m128 *)_xmm, v4));
  v6 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v4), v5), _mm_andnot_ps(v5, v4));
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_mul_ps(
         _mm_rcp_ps(
           _mm_add_ps(
             _mm_mul_ps(
               _mm_rcp_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_rcp_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(*(__m128 *)s0, v7)), *(__m128 *)t0),
                         _mm_add_ps(*(__m128 *)s1, v7))),
                     *(__m128 *)t1),
                   _mm_add_ps(*(__m128 *)s2, v7))),
               *(__m128 *)t2),
             _mm_add_ps(*(__m128 *)s3, v7))),
         _mm_mul_ps(*(__m128 *)t3, v6));
  v9 = _mm_cmpleps((__m128)0i64, v3);
  v10 = _mm_or_ps(
          _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(*(__m128 *)_xmm, v6), *(__m128 *)_xmm), v8), v5),
          _mm_andnot_ps(v5, v8));
  return _mm_or_ps(
           _mm_andnot_ps(v9, _mm_add_ps(_mm_or_ps(_mm_and_ps(*result, *(__m128 *)_xmm), *(__m128 *)_xmm), v10)),
           _mm_and_ps(v10, v9));
}

// File Line: 432
// RVA: 0xDD86B0
void __fastcall hkMath::prefetch128_6(const void *p)
{
  __asm { prefetchnta byte ptr [rcx]; Prefetch to L1 cache }
}

// File Line: 439
// RVA: 0xD6FDE0
void __fastcall hkMath::forcePrefetch_64_(const void *p)
{
  __asm { prefetchnta byte ptr [rcx]; Prefetch to L1 cache }
}

// File Line: 453
// RVA: 0xDFACA0
__int64 __fastcall hkMath::hkToIntFast_14(const float r)
{
  return (unsigned int)(signed int)r;
}

// File Line: 459
// RVA: 0xDFACC0
__int64 __fastcall hkMath::hkFloatToInt_4(const float r)
{
  return (unsigned int)(signed int)r;
}

// File Line: 484
// RVA: 0xE7EAE0
__m128i __fastcall hkMath::quadFabs_113(__m128 *result, __m128 *v)
{
  return _mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)result), 1u), 1u);
}

// File Line: 489
// RVA: 0xC86F30
__m128i __fastcall hkMath::twoFabs(__m128d *result, __m128d *v)
{
  return _mm_srli_epi64(_mm_slli_epi64(_mm_load_si128((const __m128i *)result), 1u), 1u);
}

// File Line: 495
// RVA: 0xE74E90
float __fastcall hkMath::fabs_25(const float r)
{
  float result; // xmm0_4

  LODWORD(result) = (unsigned int)(2 * LODWORD(r)) >> 1;
  return result;
}

// File Line: 501
// RVA: 0xC8AA30
long double __fastcall hkMath::fabs_9(const long double r)
{
  long double result; // xmm0_8

  *(_QWORD *)&result = (unsigned __int64)(2i64 * *(_QWORD *)&r) >> 1;
  return result;
}

// File Line: 530
// RVA: 0xB8B980
bool __fastcall hkMath::equal(float x, float y)
{
  return COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(x - y)) >> 1) <= 0.0000099999997;
}

// File Line: 539
// RVA: 0x132C9F0
bool __fastcall hkMath::equal_4(float x, float y, float tolerance2)
{
  return COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(x - y)) >> 1) <= tolerance2;
}

// File Line: 616
// RVA: 0xE0DD30
__int64 __fastcall hkMath::max2_unsigned_char_unsigned_char__0(char x, char y)
{
  __int64 result; // rax

  result = (unsigned __int8)y;
  if ( (unsigned __int8)x > (unsigned __int8)y )
    result = (unsigned __int8)x;
  return result;
}

// File Line: 649
// RVA: 0xE36FD0
__int64 __fastcall hkMath::min2_unsigned_int_unsigned_int__3(unsigned int x, unsigned int y)
{
  if ( x < y )
    y = x;
  return y;
}

// File Line: 682
// RVA: 0xD34E30
__int64 __fastcall hkMath::clamp_int_int_int__5(int x, int mi, int ma)
{
  if ( x < mi )
    return (unsigned int)mi;
  if ( x > ma )
    x = ma;
  return (unsigned int)x;
}

// File Line: 741
// RVA: 0xDFACE0
__m128 __fastcall hkMath::quadFloor_7(__m128 *result, __m128 *v)
{
  __m128 v2; // xmm2
  __m128 v3; // xmm3

  v2 = _mm_sub_ps(
         _mm_add_ps(_mm_add_ps(_mm_sub_ps(*result, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
         *(__m128 *)two23);
  v3 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(*(__m128i *)result, 1u), 1u));
  return _mm_or_ps(
           _mm_andnot_ps(v3, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmpltps(*result, v2)), v2)),
           _mm_and_ps(*result, v3));
}

// File Line: 782
// RVA: 0xC74190
float __fastcall hkMath::floor_0(const float r)
{
  __m128 v1; // xmm2
  __m128 v2; // xmm4
  float result; // xmm0_4

  v1 = _mm_sub_ps(
         _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)LODWORD(r), *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
         *(__m128 *)two23);
  v2 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)LODWORD(r), 1u), 1u));
  LODWORD(result) = *(unsigned __int128 *)&_mm_andnot_ps(
                                             v2,
                                             _mm_add_ps(
                                               _mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)LODWORD(r), v1)),
                                               v1)) | v2.m128_i32[0] & LODWORD(r);
  return result;
}

// File Line: 806
// RVA: 0xDFAD30
__int64 __fastcall hkMath::hkFloorToInt_0(const float r)
{
  __m128 v1; // xmm2
  __m128 v2; // xmm4

  v1 = _mm_sub_ps(
         _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)LODWORD(r), *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
         *(__m128 *)two23);
  v2 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)LODWORD(r), 1u), 1u));
  return (unsigned int)(signed int)COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                                                         v2,
                                                                         _mm_add_ps(
                                                                           _mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)LODWORD(r), v1)),
                                                                           v1)) | v2.m128_i32[0] & LODWORD(r));
}

// File Line: 820
// RVA: 0xC404C0
float __fastcall hkMath::ceil_0(const float r)
{
  __m128 v1; // xmm2
  __m128 v2; // xmm4

  v1 = _mm_sub_ps(
         _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)LODWORD(r), *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
         *(__m128 *)two23);
  v2 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)LODWORD(r), 1u), 1u));
  return COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                               v2,
                                               _mm_add_ps(
                                                 _mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)LODWORD(r), v1)),
                                                 v1)) | v2.m128_i32[0] & LODWORD(r))
       + 1.0;
}

// File Line: 909
// RVA: 0xD51760
float __fastcall hkMath::atan2Approximation_1(const float *y, const float *x)
{
  __m128 v2; // xmm1
  __m128 v3; // xmm7
  __m128 v4; // xmm2
  __m128 v5; // xmm4
  __m128 v6; // xmm5
  __m128 v7; // xmm3
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  __m128 v10; // xmm5
  float result; // xmm0_4

  v2 = _mm_rcp_ps((__m128)*(unsigned int *)x);
  v3 = (__m128)*(unsigned int *)y;
  v4 = _mm_mul_ps(v2, v3);
  v5 = _mm_or_ps(_mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v4), _mm_cmpltps(*(__m128 *)_xmm, v4));
  v6 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v4), v5), _mm_andnot_ps(v5, v4));
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_mul_ps(
         _mm_rcp_ps(
           _mm_add_ps(
             _mm_mul_ps(
               _mm_rcp_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_rcp_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(*(__m128 *)s0, v7)), *(__m128 *)t0),
                         _mm_add_ps(*(__m128 *)s1, v7))),
                     *(__m128 *)t1),
                   _mm_add_ps(*(__m128 *)s2, v7))),
               *(__m128 *)t2),
             _mm_add_ps(*(__m128 *)s3, v7))),
         _mm_mul_ps(v6, *(__m128 *)t3));
  v9 = _mm_cmpleps((__m128)0i64, v2);
  v10 = _mm_or_ps(
          _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v6, *(__m128 *)_xmm), *(__m128 *)_xmm), v8), v5),
          _mm_andnot_ps(v5, v8));
  LODWORD(result) = *(unsigned __int128 *)&_mm_andnot_ps(
                                             v9,
                                             _mm_add_ps(
                                               _mm_or_ps(_mm_and_ps(*(__m128 *)_xmm, v3), *(__m128 *)_xmm),
                                               v10)) | v10.m128_i32[0] & v9.m128_i32[0];
  return result;
}

// File Line: 927
// RVA: 0xC573C0
__m128 __fastcall hkMath::quadSinApproximation(__m128 *result, __m128 *inX)
{
  __m128i v2; // xmm1
  __m128i v3; // xmm2

  v2 = (__m128i)_mm_sub_ps(*result, _mm_and_ps(_mm_cmpnltps(*result, *(__m128 *)_xmm), *(__m128 *)twopi));
  v3 = (__m128i)_mm_add_ps(
                  _mm_mul_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v2, 1u), 1u), (__m128)v2), *(__m128 *)C),
                  _mm_mul_ps(*(__m128 *)_xmm, (__m128)v2));
  return _mm_add_ps(
           _mm_mul_ps(
             _mm_sub_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v3, 1u), 1u), (__m128)v3), (__m128)v3),
             *(__m128 *)_xmm),
           (__m128)v3);
}

// File Line: 962
// RVA: 0xC87660
__m128d __fastcall hkMath::twoSinApproximation(__m128d *result, __m128d *inX)
{
  __m128i v2; // xmm1
  __m128i v3; // xmm2

  v2 = (__m128i)_mm_sub_pd(*result, _mm_and_pd(_mm_cmpnlt_pd(*result, *(__m128d *)pi), *(__m128d *)twopi_0));
  v3 = (__m128i)_mm_add_pd(
                  _mm_mul_pd(
                    _mm_mul_pd((__m128d)_mm_srli_epi64(_mm_slli_epi64(v2, 1u), 1u), (__m128d)v2),
                    *(__m128d *)C_0),
                  _mm_mul_pd(*(__m128d *)fourDivPi, (__m128d)v2));
  return _mm_add_pd(
           _mm_mul_pd(
             _mm_sub_pd(_mm_mul_pd((__m128d)_mm_srli_epi64(_mm_slli_epi64(v3, 1u), 1u), (__m128d)v3), (__m128d)v3),
             *(__m128d *)P),
           (__m128d)v3);
}

// File Line: 1016
// RVA: 0xE30940
__m128 __fastcall hkMath::quadSin_20(__m128 *result, __m128 *inX)
{
  __m128i v2; // xmm6
  __m128i v3; // xmm7
  __m128 v4; // xmm3
  __m128i v5; // xmm6
  __m128 v6; // xmm2
  __m128 v7; // xmm5
  __m128 v8; // xmm4
  __m128 v9; // xmm2

  v2 = _mm_load_si128((const __m128i *)_xmm);
  v3 = _mm_add_epi32(v2, v2);
  v4 = _mm_andnot_ps(*(__m128 *)_xmm, *result);
  v5 = _mm_andnot_si128(v2, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(*(__m128 *)_xmm, v4)), v2));
  v6 = _mm_cvtepi32_ps(v5);
  v7 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v5, v3), (__m128i)0i64);
  v8 = _mm_add_ps(
         _mm_add_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)DP1_0, v6), v4), _mm_mul_ps(*(__m128 *)DP2, v6)),
         _mm_mul_ps(*(__m128 *)DP3, v6));
  v9 = _mm_mul_ps(v8, v8);
  return _mm_xor_ps(
           _mm_or_ps(
             _mm_and_ps(
               _mm_add_ps(
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v9, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v9),
                       *(__m128 *)sinCoeff2_0),
                     v9),
                   v8),
                 v8),
               v7),
             _mm_andnot_ps(
               v7,
               _mm_add_ps(
                 _mm_sub_ps(
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v9, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v9),
                         *(__m128 *)cosCoeff2_0),
                       v9),
                     v9),
                   _mm_mul_ps(v9, *(__m128 *)_xmm)),
                 *(__m128 *)_xmm))),
           _mm_xor_ps(
             (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v3, v3), v5), 0x1Du),
             _mm_and_ps(*(__m128 *)_xmm, *result)));
}

// File Line: 1127
// RVA: 0xC876D0
__m128d __fastcall hkMath::twoSin(__m128d *result, __m128d *inX)
{
  __m128i v2; // xmm6
  __m128i v3; // xmm7
  __m128d v4; // xmm3
  __m128i v5; // xmm6
  __m128d v6; // xmm2
  __m128d v7; // xmm5
  __m128d v8; // xmm4
  __m128d v9; // xmm3

  v2 = _mm_load_si128((const __m128i *)_xmm);
  v3 = _mm_add_epi32(v2, v2);
  v4 = _mm_andn_pd(*(__m128d *)_xmm, *result);
  v5 = _mm_andnot_si128(v2, _mm_add_epi32(_mm_cvttpd_epi32(_mm_mul_pd(*(__m128d *)fourDivPi, v4)), v2));
  v6 = _mm_cvtepi32_pd(v5);
  v7 = (__m128d)_mm_shuffle_epi32(_mm_cmpeq_epi32(_mm_and_si128(v5, v3), (__m128i)0i64), 80);
  v8 = _mm_add_pd(
         _mm_add_pd(_mm_add_pd(_mm_mul_pd(*(__m128d *)DP1, v6), v4), _mm_mul_pd(*(__m128d *)DP2_0, v6)),
         _mm_mul_pd(*(__m128d *)DP3_0, v6));
  v9 = _mm_mul_pd(v8, v8);
  return _mm_xor_pd(
           _mm_xor_pd(
             (__m128d)_mm_shuffle_epi32(_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v3, v3), v5), 0x1Du), 80),
             _mm_and_pd(*(__m128d *)_xmm, *result)),
           _mm_or_pd(
             _mm_andn_pd(
               v7,
               _mm_add_pd(
                 _mm_sub_pd(
                   _mm_mul_pd(
                     _mm_mul_pd(
                       _mm_add_pd(
                         _mm_mul_pd(
                           _mm_add_pd(
                             _mm_mul_pd(
                               _mm_add_pd(
                                 _mm_mul_pd(
                                   _mm_add_pd(
                                     _mm_mul_pd(
                                       _mm_add_pd(_mm_mul_pd(v9, *(__m128d *)cosCoeff0), *(__m128d *)cosCoeff1_0),
                                       v9),
                                     *(__m128d *)cosCoeff2),
                                   v9),
                                 *(__m128d *)cosCoeff3),
                               v9),
                             *(__m128d *)cosCoeff4),
                           v9),
                         *(__m128d *)cosCoeff5),
                       v9),
                     v9),
                   _mm_mul_pd(v9, *(__m128d *)_xmm)),
                 *(__m128d *)_xmm)),
             _mm_and_pd(
               _mm_add_pd(
                 _mm_mul_pd(
                   _mm_mul_pd(
                     _mm_add_pd(
                       _mm_mul_pd(
                         _mm_add_pd(
                           _mm_mul_pd(
                             _mm_add_pd(
                               _mm_mul_pd(
                                 _mm_add_pd(
                                   _mm_mul_pd(
                                     _mm_add_pd(_mm_mul_pd(v9, *(__m128d *)sinCoeff0_0), *(__m128d *)sinCoeff1),
                                     v9),
                                   *(__m128d *)sinCoeff2),
                                 v9),
                               *(__m128d *)sinCoeff3),
                             v9),
                           *(__m128d *)sinCoeff4),
                         v9),
                       *(__m128d *)sinCoeff5),
                     v9),
                   v8),
                 v8),
               v7)));
}

// File Line: 1263
// RVA: 0xE13A00
__m128 __fastcall hkMath::quadAsin_15(__m128 *result, __m128 *xx)
{
  __m128 v2; // xmm7
  __m128 v3; // xmm2
  __m128 v4; // xmm6
  __m128 v5; // xmm5
  __m128 v6; // xmm4
  __m128 v7; // xmm3
  __m128 v8; // xmm2

  v2 = _mm_andnot_ps(*(__m128 *)_xmm, *result);
  v3 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v2), *(__m128 *)_xmm);
  v4 = _mm_cmpltps(v2, *(__m128 *)_xmm);
  v5 = _mm_cmpltps(*(__m128 *)_xmm, v2);
  v6 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v3), v5), _mm_andnot_ps(v5, v2));
  v7 = _mm_or_ps(_mm_andnot_ps(v5, _mm_mul_ps(v2, v2)), _mm_and_ps(v5, v3));
  v8 = _mm_add_ps(
         _mm_mul_ps(
           _mm_mul_ps(
             _mm_add_ps(
               _mm_mul_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)coeff4, v7), *(__m128 *)coeff3), v7),
                       *(__m128 *)coeff2),
                     v7),
                   *(__m128 *)coeff1),
                 v7),
               *(__m128 *)coeff0),
             v7),
           v6),
         v6);
  return _mm_xor_ps(
           _mm_or_ps(
             _mm_andnot_ps(
               v4,
               _mm_or_ps(_mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v8, v8)), v5), _mm_andnot_ps(v5, v8))),
             _mm_and_ps(v4, v2)),
           _mm_and_ps(*result, *(__m128 *)_xmm));
}

// File Line: 1344
// RVA: 0xC87870
__m128d __fastcall hkMath::twoAsin(__m128d *result, __m128d *xx)
{
  __m128d v2; // xmm7
  __m128d v3; // xmm1
  __m128d v4; // xmm5
  __m128d v5; // xmm2
  __m128d v6; // xmm6
  __m128d v7; // xmm3

  v2 = _mm_andn_pd(*(__m128d *)_xmm, *result);
  v3 = _mm_sub_pd(*(__m128d *)_xmm, v2);
  v4 = _mm_cmplt_pd(*(__m128d *)limit, v2);
  v5 = _mm_mul_pd(v2, v2);
  v6 = _mm_cmplt_pd(v2, *(__m128d *)linearLimit);
  v7 = _mm_sqrt_pd(_mm_add_pd(v3, v3));
  return _mm_xor_pd(
           _mm_or_pd(
             _mm_andn_pd(
               v6,
               _mm_or_pd(
                 _mm_andn_pd(
                   v4,
                   _mm_add_pd(
                     _mm_mul_pd(
                       _mm_div_pd(
                         _mm_mul_pd(
                           _mm_add_pd(
                             _mm_mul_pd(
                               _mm_add_pd(
                                 _mm_mul_pd(
                                   _mm_add_pd(
                                     _mm_mul_pd(
                                       _mm_add_pd(
                                         _mm_mul_pd(_mm_add_pd(_mm_mul_pd(v5, *(__m128d *)P0), *(__m128d *)P1), v5),
                                         *(__m128d *)P2),
                                       v5),
                                     *(__m128d *)P3),
                                   v5),
                                 *(__m128d *)P4),
                               v5),
                             *(__m128d *)P5),
                           v5),
                         _mm_add_pd(
                           _mm_mul_pd(
                             _mm_add_pd(
                               _mm_mul_pd(
                                 _mm_add_pd(
                                   _mm_mul_pd(
                                     _mm_add_pd(_mm_mul_pd(_mm_add_pd(*(__m128d *)Q1, v5), v5), *(__m128d *)Q2),
                                     v5),
                                   *(__m128d *)Q3),
                                 v5),
                               *(__m128d *)Q4),
                             v5),
                           *(__m128d *)Q5)),
                       v2),
                     v2)),
                 _mm_and_pd(
                   _mm_add_pd(
                     _mm_sub_pd(
                       _mm_sub_pd(*(__m128d *)piover4, v7),
                       _mm_sub_pd(
                         _mm_mul_pd(
                           _mm_div_pd(
                             _mm_mul_pd(
                               _mm_add_pd(
                                 _mm_mul_pd(
                                   _mm_add_pd(
                                     _mm_mul_pd(
                                       _mm_add_pd(
                                         _mm_mul_pd(_mm_add_pd(_mm_mul_pd(*(__m128d *)R0, v3), *(__m128d *)R1), v3),
                                         *(__m128d *)R2),
                                       v3),
                                     *(__m128d *)R3),
                                   v3),
                                 *(__m128d *)R4),
                               v3),
                             _mm_add_pd(
                               _mm_mul_pd(
                                 _mm_add_pd(
                                   _mm_mul_pd(
                                     _mm_add_pd(_mm_mul_pd(_mm_add_pd(*(__m128d *)S1, v3), v3), *(__m128d *)S2),
                                     v3),
                                   *(__m128d *)S3),
                                 v3),
                               *(__m128d *)S4)),
                           v7),
                         *(__m128d *)morebits)),
                     *(__m128d *)piover4),
                   v4))),
             _mm_and_pd(v6, v2)),
           _mm_and_pd(*result, *(__m128d *)_xmm));
}

// File Line: 1485
// RVA: 0xE30A60
__m128 __fastcall hkMath::quadCos_13(__m128 *result, __m128 *x)
{
  __m128i v2; // xmm6
  __m128 v3; // xmm9
  __m128 v4; // xmm3
  __m128i v5; // xmm7
  __m128i v6; // xmm6
  __m128 v7; // xmm2
  __m128 v8; // xmm5
  __m128 v9; // xmm4
  __m128 v10; // xmm2

  v2 = _mm_load_si128((const __m128i *)_xmm);
  v3 = _mm_add_ps(*result, *(__m128 *)_xmm);
  v4 = _mm_andnot_ps(*(__m128 *)_xmm, v3);
  v5 = _mm_add_epi32(v2, v2);
  v6 = _mm_andnot_si128(v2, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(*(__m128 *)_xmm, v4)), v2));
  v7 = _mm_cvtepi32_ps(v6);
  v8 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v6, v5), (__m128i)0i64);
  v9 = _mm_add_ps(
         _mm_add_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)DP1_0, v7), v4), _mm_mul_ps(*(__m128 *)DP2, v7)),
         _mm_mul_ps(*(__m128 *)DP3, v7));
  v10 = _mm_mul_ps(v9, v9);
  return _mm_xor_ps(
           _mm_or_ps(
             _mm_and_ps(
               _mm_add_ps(
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v10, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v10),
                       *(__m128 *)sinCoeff2_0),
                     v10),
                   v9),
                 v9),
               v8),
             _mm_andnot_ps(
               v8,
               _mm_add_ps(
                 _mm_sub_ps(
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v10, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v10),
                         *(__m128 *)cosCoeff2_0),
                       v10),
                     v10),
                   _mm_mul_ps(v10, *(__m128 *)_xmm)),
                 *(__m128 *)_xmm))),
           _mm_xor_ps(
             (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v5, v5), v6), 0x1Du),
             _mm_and_ps(*(__m128 *)_xmm, v3)));
}

// File Line: 1502
// RVA: 0xE13B00
__m128 __fastcall hkMath::quadAcos_12(__m128 *result, __m128 *xx)
{
  __m128 v2; // xmm7
  __m128 v3; // xmm2
  __m128 v4; // xmm6
  __m128 v5; // xmm5
  __m128 v6; // xmm4
  __m128 v7; // xmm3
  __m128 v8; // xmm2

  v2 = _mm_andnot_ps(*(__m128 *)_xmm, *result);
  v3 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v2), *(__m128 *)_xmm);
  v4 = _mm_cmpltps(v2, *(__m128 *)_xmm);
  v5 = _mm_cmpltps(*(__m128 *)_xmm, v2);
  v6 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v3), v5), _mm_andnot_ps(v5, v2));
  v7 = _mm_or_ps(_mm_andnot_ps(v5, _mm_mul_ps(v2, v2)), _mm_and_ps(v5, v3));
  v8 = _mm_add_ps(
         _mm_mul_ps(
           _mm_mul_ps(
             _mm_add_ps(
               _mm_mul_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)coeff4, v7), *(__m128 *)coeff3), v7),
                       *(__m128 *)coeff2),
                     v7),
                   *(__m128 *)coeff1),
                 v7),
               *(__m128 *)coeff0),
             v7),
           v6),
         v6);
  return _mm_sub_ps(
           *(__m128 *)_xmm,
           _mm_xor_ps(
             _mm_or_ps(
               _mm_andnot_ps(
                 v4,
                 _mm_or_ps(_mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v8, v8)), v5), _mm_andnot_ps(v5, v8))),
               _mm_and_ps(v4, v2)),
             _mm_and_ps(*result, *(__m128 *)_xmm)));
}

// File Line: 1510
// RVA: 0xC87A50
__m128d __fastcall hkMath::twoAcos(__m128d *result, __m128d *xx)
{
  __m128d v2; // xmm7
  __m128d v3; // xmm1
  __m128d v4; // xmm5
  __m128d v5; // xmm2
  __m128d v6; // xmm6
  __m128d v7; // xmm3

  v2 = _mm_andn_pd(*(__m128d *)_xmm, *result);
  v3 = _mm_sub_pd(*(__m128d *)_xmm, v2);
  v4 = _mm_cmplt_pd(*(__m128d *)limit, v2);
  v5 = _mm_mul_pd(v2, v2);
  v6 = _mm_cmplt_pd(v2, *(__m128d *)linearLimit);
  v7 = _mm_sqrt_pd(_mm_add_pd(v3, v3));
  return _mm_sub_pd(
           *(__m128d *)piover2,
           _mm_xor_pd(
             _mm_or_pd(
               _mm_andn_pd(
                 v6,
                 _mm_or_pd(
                   _mm_andn_pd(
                     v4,
                     _mm_add_pd(
                       _mm_mul_pd(
                         _mm_div_pd(
                           _mm_mul_pd(
                             _mm_add_pd(
                               _mm_mul_pd(
                                 _mm_add_pd(
                                   _mm_mul_pd(
                                     _mm_add_pd(
                                       _mm_mul_pd(
                                         _mm_add_pd(
                                           _mm_mul_pd(_mm_add_pd(_mm_mul_pd(*(__m128d *)P0, v5), *(__m128d *)P1), v5),
                                           *(__m128d *)P2),
                                         v5),
                                       *(__m128d *)P3),
                                     v5),
                                   *(__m128d *)P4),
                                 v5),
                               *(__m128d *)P5),
                             v5),
                           _mm_add_pd(
                             _mm_mul_pd(
                               _mm_add_pd(
                                 _mm_mul_pd(
                                   _mm_add_pd(
                                     _mm_mul_pd(
                                       _mm_add_pd(_mm_mul_pd(_mm_add_pd(*(__m128d *)Q1, v5), v5), *(__m128d *)Q2),
                                       v5),
                                     *(__m128d *)Q3),
                                   v5),
                                 *(__m128d *)Q4),
                               v5),
                             *(__m128d *)Q5)),
                         v2),
                       v2)),
                   _mm_and_pd(
                     _mm_add_pd(
                       _mm_sub_pd(
                         _mm_sub_pd(*(__m128d *)piover4, v7),
                         _mm_sub_pd(
                           _mm_mul_pd(
                             _mm_div_pd(
                               _mm_mul_pd(
                                 _mm_add_pd(
                                   _mm_mul_pd(
                                     _mm_add_pd(
                                       _mm_mul_pd(
                                         _mm_add_pd(
                                           _mm_mul_pd(_mm_add_pd(_mm_mul_pd(*(__m128d *)R0, v3), *(__m128d *)R1), v3),
                                           *(__m128d *)R2),
                                         v3),
                                       *(__m128d *)R3),
                                     v3),
                                   *(__m128d *)R4),
                                 v3),
                               _mm_add_pd(
                                 _mm_mul_pd(
                                   _mm_add_pd(
                                     _mm_mul_pd(
                                       _mm_add_pd(_mm_mul_pd(_mm_add_pd(*(__m128d *)S1, v3), v3), *(__m128d *)S2),
                                       v3),
                                     *(__m128d *)S3),
                                   v3),
                                 *(__m128d *)S4)),
                             v7),
                           *(__m128d *)morebits)),
                       *(__m128d *)piover4),
                     v4))),
               _mm_and_pd(v6, v2)),
             _mm_and_pd(*result, *(__m128d *)_xmm)));
}
               _mm_

// File Line: 1520
// RVA: 0xC57760
__m128 __fastcall hkMath::quadSinCosApproximation(__m128 *result, __m128 *x)
{
  __m128 v2; // xmm1
  __m128i v3; // xmm1
  __m128i v4; // xmm2

  v2 = _mm_add_ps(*result, *(__m128 *)offset_1);
  v3 = (__m128i)_mm_sub_ps(v2, _mm_and_ps(_mm_cmpnltps(v2, *(__m128 *)_xmm), *(__m128 *)twopi));
  v4 = (__m128i)_mm_add_ps(
                  _mm_mul_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v3, 1u), 1u), (__m128)v3), *(__m128 *)C),
                  _mm_mul_ps(*(__m128 *)_xmm, (__m128)v3));
  return _mm_add_ps(
           _mm_mul_ps(
             _mm_sub_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v4, 1u), 1u), (__m128)v4), (__m128)v4),
             *(__m128 *)_xmm),
           (__m128)v4);
}

// File Line: 1530
// RVA: 0xC87C30
__m128d __fastcall hkMath::twoSinCosApproximation(__m128d *result, __m128d *x)
{
  __m128d v2; // xmm1
  __m128i v3; // xmm1
  __m128i v4; // xmm2

  v2 = _mm_add_pd(*result, *(__m128d *)offset_0);
  v3 = (__m128i)_mm_sub_pd(v2, _mm_and_pd(_mm_cmpnlt_pd(v2, *(__m128d *)pi), *(__m128d *)twopi_0));
  v4 = (__m128i)_mm_add_pd(
                  _mm_mul_pd(
                    _mm_mul_pd((__m128d)_mm_srli_epi64(_mm_slli_epi64(v3, 1u), 1u), (__m128d)v3),
                    *(__m128d *)C_0),
                  _mm_mul_pd(*(__m128d *)fourDivPi, (__m128d)v3));
  return _mm_add_pd(
           _mm_mul_pd(
             _mm_sub_pd(_mm_mul_pd((__m128d)_mm_srli_epi64(_mm_slli_epi64(v4, 1u), 1u), (__m128d)v4), (__m128d)v4),
             *(__m128d *)P),
           (__m128d)v4);
}

// File Line: 1540
// RVA: 0xDFED00
__m128 __fastcall hkMath::quadSinCos_9(__m128 *result, __m128 *x)
{
  __m128i v2; // xmm6
  __m128 v3; // xmm9
  __m128 v4; // xmm3
  __m128i v5; // xmm7
  __m128i v6; // xmm6
  __m128 v7; // xmm2
  __m128 v8; // xmm5
  __m128 v9; // xmm4
  __m128 v10; // xmm2

  v2 = _mm_load_si128((const __m128i *)_xmm);
  v3 = _mm_add_ps(*result, *(__m128 *)offset_1);
  v4 = _mm_andnot_ps(*(__m128 *)_xmm, v3);
  v5 = _mm_add_epi32(v2, v2);
  v6 = _mm_andnot_si128(v2, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(*(__m128 *)_xmm, v4)), v2));
  v7 = _mm_cvtepi32_ps(v6);
  v8 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v6, v5), (__m128i)0i64);
  v9 = _mm_add_ps(
         _mm_add_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)DP1_0, v7), v4), _mm_mul_ps(*(__m128 *)DP2, v7)),
         _mm_mul_ps(*(__m128 *)DP3, v7));
  v10 = _mm_mul_ps(v9, v9);
  return _mm_xor_ps(
           _mm_or_ps(
             _mm_and_ps(
               _mm_add_ps(
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v10, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v10),
                       *(__m128 *)sinCoeff2_0),
                     v10),
                   v9),
                 v9),
               v8),
             _mm_andnot_ps(
               v8,
               _mm_add_ps(
                 _mm_sub_ps(
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v10, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v10),
                         *(__m128 *)cosCoeff2_0),
                       v10),
                     v10),
                   _mm_mul_ps(v10, *(__m128 *)_xmm)),
                 *(__m128 *)_xmm))),
           _mm_xor_ps(
             (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v5, v5), v6), 0x1Du),
             _mm_and_ps(*(__m128 *)_xmm, v3)));
}

// File Line: 1550
// RVA: 0xC87CB0
__m128d __fastcall hkMath::twoSinCos(__m128d *result, __m128d *x)
{
  __m128i v2; // xmm6
  __m128d v3; // xmm9
  __m128d v4; // xmm3
  __m128i v5; // xmm7
  __m128i v6; // xmm6
  __m128d v7; // xmm2
  __m128d v8; // xmm5
  __m128d v9; // xmm4
  __m128d v10; // xmm3

  v2 = _mm_load_si128((const __m128i *)_xmm);
  v3 = _mm_add_pd(*result, *(__m128d *)offset_0);
  v4 = _mm_andn_pd(*(__m128d *)_xmm, v3);
  v5 = _mm_add_epi32(v2, v2);
  v6 = _mm_andnot_si128(v2, _mm_add_epi32(_mm_cvttpd_epi32(_mm_mul_pd(*(__m128d *)fourDivPi, v4)), v2));
  v7 = _mm_cvtepi32_pd(v6);
  v8 = (__m128d)_mm_shuffle_epi32(_mm_cmpeq_epi32(_mm_and_si128(v6, v5), (__m128i)0i64), 80);
  v9 = _mm_add_pd(
         _mm_add_pd(_mm_add_pd(_mm_mul_pd(*(__m128d *)DP1, v7), v4), _mm_mul_pd(*(__m128d *)DP2_0, v7)),
         _mm_mul_pd(*(__m128d *)DP3_0, v7));
  v10 = _mm_mul_pd(v9, v9);
  return _mm_xor_pd(
           _mm_xor_pd(
             (__m128d)_mm_shuffle_epi32(_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v5, v5), v6), 0x1Du), 80),
             _mm_and_pd(*(__m128d *)_xmm, v3)),
           _mm_or_pd(
             _mm_andn_pd(
               v8,
               _mm_add_pd(
                 _mm_sub_pd(
                   _mm_mul_pd(
                     _mm_mul_pd(
                       _mm_add_pd(
                         _mm_mul_pd(
                           _mm_add_pd(
                             _mm_mul_pd(
                               _mm_add_pd(
                                 _mm_mul_pd(
                                   _mm_add_pd(
                                     _mm_mul_pd(
                                       _mm_add_pd(_mm_mul_pd(v10, *(__m128d *)cosCoeff0), *(__m128d *)cosCoeff1_0),
                                       v10),
                                     *(__m128d *)cosCoeff2),
                                   v10),
                                 *(__m128d *)cosCoeff3),
                               v10),
                             *(__m128d *)cosCoeff4),
                           v10),
                         *(__m128d *)cosCoeff5),
                       v10),
                     v10),
                   _mm_mul_pd(v10, *(__m128d *)_xmm)),
                 *(__m128d *)_xmm)),
             _mm_and_pd(
               _mm_add_pd(
                 _mm_mul_pd(
                   _mm_mul_pd(
                     _mm_add_pd(
                       _mm_mul_pd(
                         _mm_add_pd(
                           _mm_mul_pd(
                             _mm_add_pd(
                               _mm_mul_pd(
                                 _mm_add_pd(
                                   _mm_mul_pd(
                                     _mm_add_pd(_mm_mul_pd(v10, *(__m128d *)sinCoeff0_0), *(__m128d *)sinCoeff1),
                                     v10),
                                   *(__m128d *)sinCoeff2),
                                 v10),
                               *(__m128d *)sinCoeff3),
                             v10),
                           *(__m128d *)sinCoeff4),
                         v10),
                       *(__m128d *)sinCoeff5),
                     v10),
                   v9),
                 v9),
               v8)));
}

// File Line: 1586
// RVA: 0xE30BA0
float __fastcall hkMath::sin_8(const float r)
{
  __m128i v1; // xmm6
  __m128i v2; // xmm7
  __m128 v3; // xmm3
  __m128i v4; // xmm6
  __m128 v5; // xmm2
  __m128 v6; // xmm5
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  float result; // xmm0_4

  v1 = _mm_load_si128((const __m128i *)_xmm);
  v2 = _mm_add_epi32(v1, v1);
  v3 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(r));
  v4 = _mm_andnot_si128(v1, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(*(__m128 *)_xmm, v3)), v1));
  v5 = _mm_cvtepi32_ps(v4);
  v6 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v4, v2), (__m128i)0i64);
  v7 = _mm_add_ps(
         _mm_add_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)DP1_0, v5), v3), _mm_mul_ps(*(__m128 *)DP2, v5)),
         _mm_mul_ps(*(__m128 *)DP3, v5));
  v8 = _mm_mul_ps(v7, v7);
  LODWORD(result) = (COERCE_UNSIGNED_INT(
                       (float)((float)((float)((float)((float)((float)(v8.m128_f32[0] * -0.00019515296) + 0.0083321612)
                                                     * v8.m128_f32[0])
                                             + -0.16666655)
                                     * v8.m128_f32[0])
                             * v7.m128_f32[0])
                     + v7.m128_f32[0]) & v6.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                                   v6,
                                                                                   _mm_add_ps(
                                                                                     _mm_sub_ps(
                                                                                       _mm_mul_ps(
                                                                                         _mm_mul_ps(
                                                                                           _mm_add_ps(
                                                                                             _mm_mul_ps(
                                                                                               _mm_add_ps(
                                                                                                 _mm_mul_ps(
                                                                                                   v8,
                                                                                                   *(__m128 *)cosCoeff0_0),
                                                                                                 *(__m128 *)cosCoeff1),
                                                                                               v8),
                                                                                             *(__m128 *)cosCoeff2_0),
                                                                                           v8),
                                                                                         v8),
                                                                                       _mm_mul_ps(v8, *(__m128 *)_xmm)),
                                                                                     *(__m128 *)_xmm))) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v2, v2), v4) << 29) ^ _xmm[0] & LODWORD(r);
  return result;
}

// File Line: 1600
// RVA: 0xE30CE0
float __fastcall hkMath::cos_13(const float r)
{
  __m128i v1; // xmm6
  __m128 v2; // xmm9
  __m128i v3; // xmm7
  __m128 v4; // xmm3
  __m128i v5; // xmm6
  __m128 v6; // xmm2
  __m128 v7; // xmm5
  __m128 v8; // xmm4
  __m128 v9; // xmm2
  float result; // xmm0_4

  v1 = _mm_load_si128((const __m128i *)_xmm);
  v2 = _mm_add_ps((__m128)LODWORD(r), *(__m128 *)_xmm);
  v3 = _mm_add_epi32(v1, v1);
  v4 = _mm_andnot_ps(*(__m128 *)_xmm, v2);
  v5 = _mm_andnot_si128(v1, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(*(__m128 *)_xmm, v4)), v1));
  v6 = _mm_cvtepi32_ps(v5);
  v7 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v5, v3), (__m128i)0i64);
  v8 = _mm_add_ps(
         _mm_add_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)DP1_0, v6), v4), _mm_mul_ps(*(__m128 *)DP2, v6)),
         _mm_mul_ps(*(__m128 *)DP3, v6));
  v9 = _mm_mul_ps(v8, v8);
  LODWORD(result) = (COERCE_UNSIGNED_INT(
                       (float)((float)((float)((float)((float)((float)(v9.m128_f32[0] * -0.00019515296) + 0.0083321612)
                                                     * v9.m128_f32[0])
                                             + -0.16666655)
                                     * v9.m128_f32[0])
                             * v8.m128_f32[0])
                     + v8.m128_f32[0]) & v7.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                                   v7,
                                                                                   _mm_add_ps(
                                                                                     _mm_sub_ps(
                                                                                       _mm_mul_ps(
                                                                                         _mm_mul_ps(
                                                                                           _mm_add_ps(
                                                                                             _mm_mul_ps(
                                                                                               _mm_add_ps(
                                                                                                 _mm_mul_ps(
                                                                                                   v9,
                                                                                                   *(__m128 *)cosCoeff0_0),
                                                                                                 *(__m128 *)cosCoeff1),
                                                                                               v9),
                                                                                             *(__m128 *)cosCoeff2_0),
                                                                                           v9),
                                                                                         v9),
                                                                                       _mm_mul_ps(v9, *(__m128 *)_xmm)),
                                                                                     *(__m128 *)_xmm))) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v3, v3), v5) << 29) ^ _xmm[0] & v2.m128_i32[0];
  return result;
}

// File Line: 1614
// RVA: 0xC9D340
float __fastcall hkMath::asin_0(const float r)
{
  __m128 v1; // xmm9
  __m128 v2; // xmm7
  __m128 v3; // xmm6
  __m128 v4; // xmm2
  __m128 v5; // xmm5
  __m128 v6; // xmm4
  __m128 v7; // xmm3
  __m128 v8; // xmm2
  float result; // xmm0_4

  v1 = _mm_min_ps(_mm_max_ps((__m128)LODWORD(r), *(__m128 *)_xmm_bf800000bf800000bf800000bf800000), *(__m128 *)_xmm);
  v2 = _mm_andnot_ps(*(__m128 *)_xmm, v1);
  v3 = _mm_cmpltps(v2, *(__m128 *)_xmm);
  v4 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v2), *(__m128 *)_xmm);
  v5 = _mm_cmpltps(*(__m128 *)_xmm, v2);
  v6 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v4), v5), _mm_andnot_ps(v5, v2));
  v7 = _mm_or_ps(_mm_andnot_ps(v5, _mm_mul_ps(v2, v2)), _mm_and_ps(v5, v4));
  v8 = _mm_add_ps(
         _mm_mul_ps(
           _mm_mul_ps(
             _mm_add_ps(
               _mm_mul_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)coeff4, v7), *(__m128 *)coeff3), v7),
                       *(__m128 *)coeff2),
                     v7),
                   *(__m128 *)coeff1),
                 v7),
               *(__m128 *)coeff0),
             v7),
           v6),
         v6);
  LODWORD(result) = (*(unsigned __int128 *)&_mm_andnot_ps(
                                              v3,
                                              _mm_or_ps(
                                                _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v8, v8)), v5),
                                                _mm_andnot_ps(v5, v8))) | v3.m128_i32[0] & v2.m128_i32[0]) ^ _xmm[0] & v1.m128_i32[0];
  return result;
}

// File Line: 1642
// RVA: 0xBAA9A0
float __fastcall hkMath::acos_1(const float r)
{
  __m128 v1; // xmm9
  __m128 v2; // xmm7
  __m128 v3; // xmm6
  __m128 v4; // xmm2
  __m128 v5; // xmm5
  __m128 v6; // xmm4
  __m128 v7; // xmm3
  __m128 v8; // xmm2

  v1 = _mm_min_ps(_mm_max_ps((__m128)LODWORD(r), *(__m128 *)_xmm_bf800000bf800000bf800000bf800000), *(__m128 *)_xmm);
  v2 = _mm_andnot_ps(*(__m128 *)_xmm, v1);
  v3 = _mm_cmpltps(v2, *(__m128 *)_xmm);
  v4 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v2), *(__m128 *)_xmm);
  v5 = _mm_cmpltps(*(__m128 *)_xmm, v2);
  v6 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v4), v5), _mm_andnot_ps(v5, v2));
  v7 = _mm_or_ps(_mm_andnot_ps(v5, _mm_mul_ps(v2, v2)), _mm_and_ps(v5, v4));
  v8 = _mm_add_ps(
         _mm_mul_ps(
           _mm_mul_ps(
             _mm_add_ps(
               _mm_mul_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v7, *(__m128 *)coeff4), *(__m128 *)coeff3), v7),
                       *(__m128 *)coeff2),
                     v7),
                   *(__m128 *)coeff1),
                 v7),
               *(__m128 *)coeff0),
             v7),
           v6),
         v6);
  return 1.5707964
       - COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                                v3,
                                                _mm_or_ps(
                                                  _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v8, v8)), v5),
                                                  _mm_andnot_ps(v5, v8))) | v3.m128_i32[0] & v2.m128_i32[0]) ^ _xmm[0] & v1.m128_i32[0]);
}

// File Line: 1764
// RVA: 0xD7C380
__int64 __fastcall hkMath::countBitsSet_4(unsigned int number)
{
  __m128i v1; // xmm0
  __m128i v2; // xmm2
  __m128i v3; // xmm0
  __m128i v4; // xmm1

  v1 = _mm_cvtsi32_si128(number);
  v2 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v1, 1u), (__m128i)_xmm), _mm_and_si128(v1, (__m128i)_xmm));
  v3 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v2, 2u), (__m128i)_xmm), _mm_and_si128(v2, (__m128i)_xmm));
  v4 = _mm_sad_epu8(_mm_and_si128(_mm_add_epi8(_mm_srli_epi16(v3, 4u), v3), (__m128i)_xmm), (__m128i)0i64);
  return (unsigned int)_mm_cvtsi128_si32(_mm_add_epi32(_mm_shuffle_epi32(v4, 78), v4));
}


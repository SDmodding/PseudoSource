// File Line: 20
// RVA: 0xBDD760
__m128 __fastcall hkMath::quadReciprocal_34(__m128 *result, __m128 *r)
{
  __m128 v2; // xmm2

  v2 = _mm_rcp_ps(*result);
  return _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(*result, v2)), v2);
}

// File Line: 50
// RVA: 0xBF8630
__m128 __fastcall hkMath::quadReciprocalSquareRoot_37(__m128 *result, __m128 *r)
{
  __m128 v2; // xmm2

  v2 = _mm_rsqrt_ps(*result);
  return _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(*result, v2), v2)), _mm_mul_ps(*(__m128 *)_xmm, v2));
}

// File Line: 166
// RVA: 0xBDD7B0
float __fastcall hkMath::sqrt_3(const float r)
{
  return fsqrt(r);
}

// File Line: 284
// RVA: 0xBDD7D0
__m128 __fastcall hkMath::quadAtan2_0(__m128 *result, __m128 *y, __m128 *x)
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

// File Line: 484
// RVA: 0xBDD8E0
__m128i __fastcall hkMath::quadFabs_25(__m128 *result, __m128 *v)
{
  return _mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)result), 1u), 1u);
}

// File Line: 495
// RVA: 0xBDD900
float __fastcall hkMath::fabs_2(const float r)
{
  float result; // xmm0_4

  LODWORD(result) = (unsigned int)(2 * LODWORD(r)) >> 1;
  return result;
}

// File Line: 616
// RVA: 0xBE90D0
__int64 __fastcall hkMath::max2_int_int__19(int x, int y)
{
  if ( x > y )
    y = x;
  return (unsigned int)y;
}

// File Line: 649
// RVA: 0xC1FDD0
__int64 __fastcall hkMath::min2_int_int__25(int x, int y)
{
  if ( x < y )
    y = x;
  return (unsigned int)y;
}

// File Line: 682
// RVA: 0xBFE9D0
__int64 __fastcall hkMath::clamp_int_int_int__2(int x, int mi, int ma)
{
  if ( x < mi )
    return (unsigned int)mi;
  if ( x > ma )
    x = ma;
  return (unsigned int)x;
}

// File Line: 909
// RVA: 0xBDD920
float __fastcall hkMath::atan2Approximation(const float *y, const float *x)
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

// File Line: 1016
// RVA: 0xBDDA30
__m128 __fastcall hkMath::quadSin_4(__m128 *result, __m128 *inX)
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

// File Line: 1263
// RVA: 0xBDDB50
__m128 __fastcall hkMath::quadAsin_2(__m128 *result, __m128 *xx)
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

// File Line: 1485
// RVA: 0xBDDC50
__m128 __fastcall hkMath::quadCos_3(__m128 *result, __m128 *x)
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
// RVA: 0xBDDD90
__m128 __fastcall hkMath::quadAcos_2(__m128 *result, __m128 *xx)
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

// File Line: 1540
// RVA: 0xBDDEA0
__m128 __fastcall hkMath::quadSinCos_2(__m128 *result, __m128 *x)
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

// File Line: 1586
// RVA: 0xBDDFE0
float __fastcall hkMath::sin(const float r)
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
// RVA: 0xBDE120
float __fastcall hkMath::cos_3(const float r)
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
// RVA: 0xC26CB0
float __fastcall hkMath::asin(const float r)
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
// RVA: 0xBDE260
float __fastcall hkMath::acos_2(const float r)
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


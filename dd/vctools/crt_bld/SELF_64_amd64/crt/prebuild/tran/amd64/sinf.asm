// File Line: 144
// RVA: 0x12AE620
// local variable allocation has failed, the output may be wrong!
float __cdecl sinf(float X)
{
  __m128d v1; // xmm2
  double v2; // xmm0_8
  unsigned __int64 v3; // r10
  char v4; // r11
  double v5; // xmm4_8
  __m128i v6; // xmm0
  double v7; // xmm2_8
  double v8; // xmm4_8
  unsigned int v9; // eax
  double v10; // xmm2_8
  double v11; // xmm2_8
  char v13; // [rsp+0h] [rbp-F8h]
  int region[4]; // [rsp+A0h] [rbp-58h] BYREF
  long double r[9]; // [rsp+B0h] [rbp-48h] BYREF

  v1 = 0i64;
  if ( (_mm_cvtsi128_si32(*(__m128i *)&X) & 0x7F800000) != 2139095040 )
  {
    v2 = X;
    v3 = *(_QWORD *)&v2 & 0x7FFFFFFFFFFFFFFFi64;
    if ( (*(_QWORD *)&v2 & 0x7FFFFFFFFFFFFFFFui64) <= 0x3FE921FB54442D18i64 )
    {
      if ( (*(_QWORD *)&v2 & 0x7FFFFFFFFFFFFFFFui64) >= 0x3F80000000000000i64 )
      {
        return v2
             + ((0.000002755731922398589 * (v2 * v2) + -0.0001984126984126984) * (v2 * v2 * (v2 * v2))
              + 0.008333333333333333 * (v2 * v2)
              + -0.1666666666666667)
             * (v2
              * (v2
               * v2));
      }
      else if ( (*(_QWORD *)&v2 & 0x7FFFFFFFFFFFFFFFui64) >= 0x3F20000000000000i64 )
      {
        return v2 - v2 * v2 * v2 * 0.1666666666666667;
      }
      return v2;
    }
    v4 = 0;
    if ( *(_QWORD *)&v2 != v3 )
    {
      v4 = 1;
      v2 = 0.0 - v2;
    }
    if ( v3 >= L__real_411E848000000000_0 )
    {
      v13 = v4;
      _remainder_piby2f(*(unsigned __int64 *)&v2, r, region);
      v4 = v13;
      v9 = region[0];
    }
    else
    {
      v5 = v2;
      v1.m128d_f64[0] = v2 * 0.6366197723675814 + 0.5;
      v6 = _mm_cvttpd_epi32(v1);
      v7 = _mm_cvtepi32_pd(v6).m128d_f64[0];
      v8 = v5 - 1.570796326734126 * v7;
      v9 = _mm_cvtsi128_si32(v6);
      v2 = v8 - 6.077100506506192e-11 * v7;
      if ( (__int64)((v3 >> 52) - ((unsigned __int64)(2i64 * *(_QWORD *)&v2) >> 53)) > 15 )
        v2 = v8
           - 6.077100506303966e-11 * v7
           - (2.022266248795951e-21 * v7
            - (v8
             - (v8
              - 6.077100506303966e-11 * v7)
             - 6.077100506303966e-11 * v7));
      if ( (unsigned __int64)(2 * COERCE__INT64(v8 - 6.077100506506192e-11 * v7)) >> 53 < 0x3F2 )
      {
        if ( (unsigned __int64)(2 * COERCE__INT64(v8 - 6.077100506506192e-11 * v7)) >> 53 <= 0x3DE )
        {
          if ( (v9 & 1) != 0 )
            v2 = *(double *)&L__real_3ff0000000000000_0;
        }
        else
        {
          v10 = v2 * v2;
          if ( (v9 & 1) != 0 )
            v2 = 1.0 - v10 * 0.5;
          else
            v2 = v2 - 0.1666666666666667 * v2 * v10;
        }
        goto Ladjust_region;
      }
    }
    v11 = v2 * v2;
    if ( (v9 & 1) != 0 )
      v2 = -0.5 * v11
         + 1.0
         + ((-0.0000002755731922398589 * v11 + 0.0000248015873015873) * (v11 * v11)
          + -0.001388888888888889 * v11
          + 0.04166666666666666)
         * (v11
          * v11);
    else
      v2 = v2
         + ((0.000002755731922398589 * v11 + -0.0001984126984126984) * (v11 * v11)
          + 0.008333333333333333 * v11
          + -0.1666666666666667)
         * (v2
          * v11);
Ladjust_region:
    if ( (((unsigned __int8)(~v4 & ~(unsigned __int8)(v9 >> 1)) | (unsigned __int8)(v4 & (v9 >> 1))) & 1) == 0 )
      return 0.0 - v2;
    return v2;
  }
  return sinf_special(X);
}


// File Line: 134
// RVA: 0x12AE320
// local variable allocation has failed, the output may be wrong!
float __cdecl cosf(float X)
{
  __m128d v1; // xmm2
  double v2; // xmm0_8
  unsigned __int64 v3; // r10
  double v4; // xmm2_8
  char v5; // al
  double v6; // xmm5_8
  double v7; // xmm4_8
  __m128i v8; // xmm0
  double v9; // xmm2_8
  double v10; // xmm4_8
  signed __int64 v11; // rcx
  double v12; // xmm1_8
  int region; // [rsp+A0h] [rbp-58h]
  long double r; // [rsp+B0h] [rbp-48h]

  if ( (_mm_cvtsi128_si32(*(__m128i *)&X) & 0x7F800000) == 2139095040 )
    return cosf_special(X);
  v1 = 0i64;
  v2 = X;
  v3 = *(_QWORD *)&v2 & 0x7FFFFFFFFFFFFFFFi64;
  if ( (*(_QWORD *)&v2 & 0x7FFFFFFFFFFFFFFFi64) > 4605249457297304856i64 )
  {
    if ( *(_QWORD *)&v2 != v3 )
      v2 = 0.0 - v2;
    if ( v3 >= L__real_411E848000000000 )
    {
      _remainder_piby2f(*(unsigned __int64 *)&v2, &r, &region);
      v2 = r;
      v5 = region;
      v4 = v2 * v2;
      v6 = *(double *)&L__real_3fe0000000000000;
    }
    else
    {
      v7 = v2;
      v1.m128d_f64[0] = v2 * 0.6366197723675814 + 0.5;
      v8 = _mm_cvttpd_epi32(v1);
      *(_QWORD *)&v9 = (unsigned __int128)_mm_cvtepi32_pd(v8);
      v10 = v7 - 1.570796326734126 * v9;
      v5 = _mm_cvtsi128_si32(v8);
      v2 = v10 - 6.077100506506192e-11 * v9;
      v11 = (unsigned __int64)(2 * COERCE_SIGNED_INT64(v10 - 6.077100506506192e-11 * v9)) >> 53;
      if ( (signed __int64)((v3 >> 52) - v11) > 15 )
        v2 = v10
           - 6.077100506303966e-11 * v9
           - (2.022266248795951e-21 * v9
            - (v10
             - (v10
              - 6.077100506303966e-11 * v9)
             - 6.077100506303966e-11 * v9));
      v4 = v2 * v2;
      v12 = v2;
      v6 = *(double *)&L__real_3fe0000000000000;
      if ( v11 < 1010 )
      {
        if ( v11 <= 990 )
        {
          if ( !(v5 & 1) )
            v12 = *(double *)&L__real_3ff0000000000000;
        }
        else if ( v5 & 1 )
        {
          v12 = v2 - 0.1666666666666667 * v2 * v4;
        }
        else
        {
          v12 = 1.0 - v4 * 0.5;
        }
        goto L__adjust_region_cos;
      }
    }
  }
  else
  {
    v4 = v2 * v2;
    v5 = 0;
    v6 = *(double *)&L__real_3fe0000000000000;
  }
  if ( v5 & 1 )
    v12 = ((0.00000275573161037288 * v4 + -0.0001984126983676113) * (v4 * v4)
         + 0.00833333333333095 * v4
         + -0.1666666666666667)
        * (v4
         * v2)
        + v2;
  else
    v12 = ((-0.0000002755731727234419 * v4 + 0.00002480158729876704) * (v4 * v4)
         + -0.00138888888888874 * v4
         + 0.04166666666666666)
        * (v4
         * v4)
        - (v6 * v4
         - 1.0);
L__adjust_region_cos:
  if ( (v5 + 1) & 2 )
    v12 = 0.0 - v12;
  return v12;
}


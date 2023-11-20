// File Line: 126
// RVA: 0x12B7FB0
double __cdecl sin(double result)
{
  __m128d v1; // xmm2
  signed __int64 v2; // r10
  char v3; // r11
  double v4; // xmm4_8
  __m128i v5; // xmm0
  double v6; // xmm2_8
  double v7; // xmm4_8
  double v8; // xmm1_8
  unsigned int v9; // eax
  signed __int64 v10; // rcx
  double v11; // xmm1_8
  double v12; // xmm4_8
  double v13; // xmm2_8
  char v14; // ST20_1
  double v15; // xmm2_8
  long double r; // [rsp+A0h] [rbp-58h]
  long double rr; // [rsp+B0h] [rbp-48h]
  int region; // [rsp+C0h] [rbp-38h]

  v1 = 0i64;
  if ( (*(_QWORD *)&result & 0x7FF0000000000000i64) == 9218868437227405312i64 )
    return sin_special(result);
  v2 = *(_QWORD *)&result & 0x7FFFFFFFFFFFFFFFi64;
  if ( (*(_QWORD *)&result & 0x7FFFFFFFFFFFFFFFi64) <= 4605249457297304856i64 )
  {
    if ( v2 >= 4548635623644200960i64 )
      return result
           + result
           * (result
            * result)
           * (((1.591814430448591e-10 * (result * result) + -0.0000000250511320680217) * (result * result)
             + 0.00000275573161037288)
            * (result
             * result
             * (result
              * result)
             * (result
              * result))
            + (-0.0001984126983676113 * (result * result) + 0.00833333333333095) * (result * result)
            + -0.1666666666666667);
    if ( v2 >= 4485585228861014016i64 )
      result = result - result * result * result * 0.1666666666666667;
    return result;
  }
  v3 = 0;
  if ( *(_QWORD *)&result != v2 )
  {
    v3 = 1;
    result = 0.0 - result;
  }
  if ( v2 >= L__real_411E848000000000_2 )
  {
    v14 = v3;
    _remainder_piby2(result, &r, &rr, &region);
    v3 = v14;
    result = r;
    v12 = rr;
    v9 = region;
  }
  else
  {
    v4 = result;
    v1.m128d_f64[0] = result * 0.6366197723675814 + 0.5;
    v5 = _mm_cvttpd_epi32(v1);
    *(_QWORD *)&v6 = (unsigned __int128)_mm_cvtepi32_pd(v5);
    v7 = v4 - 1.570796326734126 * v6;
    v8 = 6.077100506506192e-11 * v6;
    v9 = _mm_cvtsi128_si32(v5);
    result = v7 - 6.077100506506192e-11 * v6;
    v10 = (unsigned __int64)(2 * COERCE_SIGNED_INT64(v7 - 6.077100506506192e-11 * v6)) >> 53;
    if ( (signed __int64)(((unsigned __int64)v2 >> 52) - v10) > 15 )
    {
      v11 = v7;
      v7 = v7 - 6.077100506303966e-11 * v6;
      v8 = 2.022266248795951e-21 * v6 - (v11 - v7 - 6.077100506303966e-11 * v6);
      result = v7 - v8;
    }
    v12 = v7 - result - v8;
    if ( v10 < 1010 )
    {
      if ( v10 <= 990 )
      {
        if ( v9 & 1 )
          result = *(double *)&L__real_3ff0000000000000_2;
      }
      else
      {
        v13 = result * result;
        if ( v9 & 1 )
          result = 1.0 - v13 * 0.5;
        else
          result = result - 0.1666666666666667 * result * v13;
      }
      goto Ladjust_region_1;
    }
  }
  v15 = result * result;
  if ( v9 & 1 )
    result = ((0.00002480158729876704 * v15 + -0.00138888888888874) * v15
            + 0.04166666666666666
            + ((-1.138263981623609e-11 * v15 + 0.000000002087614638237214) * v15 + -0.0000002755731727234489)
            * (v15
             * v15
             * v15))
           * (v15
            * v15)
           + 0.5 * v15
           - 1.0
           + 1.0
           - v15 * 0.5
           - v12 * result
           - (v15 * 0.5
            - 1.0);
  else
    result = v12
           + result
           * v15
           * (((1.591814430448591e-10 * v15 + -0.0000000250511320680217) * v15 + 0.00000275573161037288)
            * (v15
             * v15
             * v15)
            + (-0.0001984126983676113 * v15 + 0.00833333333333095) * v15
            + -0.1666666666666667)
           - v15 * 0.5 * v12
           + result;
Ladjust_region_1:
  if ( !(((unsigned __int8)(~v3 & ~(unsigned __int8)(v9 >> 1)) | (unsigned __int8)(v3 & (v9 >> 1))) & 1) )
    result = 0.0 - result;
  return result;
}


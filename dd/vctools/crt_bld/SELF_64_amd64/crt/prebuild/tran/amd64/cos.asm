// File Line: 130
// RVA: 0x12B64C0
double __cdecl cos(double X)
{
  __m128d v1; // xmm2
  signed __int64 v2; // r10
  double result; // xmm0_8
  double v4; // xmm4_8
  double v5; // xmm4_8
  __m128i v6; // xmm0
  double v7; // xmm2_8
  double v8; // xmm4_8
  double v9; // xmm1_8
  char v10; // al
  signed __int64 v11; // rcx
  double v12; // xmm1_8
  double v13; // xmm4_8
  double v14; // xmm2_8
  double v15; // xmm2_8
  long double r; // [rsp+A0h] [rbp-58h]
  long double rr; // [rsp+B0h] [rbp-48h]
  int region; // [rsp+C0h] [rbp-38h]

  v1 = 0i64;
  if ( (*(_QWORD *)&X & 0x7FF0000000000000i64) == 9218868437227405312i64 )
    return cos_special(X);
  v2 = *(_QWORD *)&X & 0x7FFFFFFFFFFFFFFFi64;
  if ( (*(_QWORD *)&X & 0x7FFFFFFFFFFFFFFFi64) <= 4605249457297304856i64 )
  {
    if ( v2 >= 4548635623644200960i64 )
    {
      v4 = X * X * (X * X);
      result = 1.0
             - (X * X * -0.5
              + 1.0)
             + X * X * -0.5
             + (-0.00138888888888874 * (X * X) + 0.04166666666666666) * v4
             + (-0.0000002755731727234489 * (X * X) + 0.00002480158729876704) * (v4 * v4)
             + v4 * (v4 * v4) * (-1.138263981623609e-11 * (X * X) + 0.000000002087614638237214)
             + X * X * -0.5
             + 1.0;
    }
    else if ( v2 >= 4485585228861014016i64 )
    {
      result = 1.0 - X * X * 0.5;
    }
    else
    {
      result = *(double *)&L__real_3ff0000000000000_1;
    }
    return result;
  }
  if ( *(_QWORD *)&X != v2 )
    X = 0.0 - X;
  if ( v2 >= L__real_411E848000000000_1 )
  {
    _remainder_piby2(X, &r, &rr, &region);
    result = r;
    v13 = rr;
    v10 = region;
  }
  else
  {
    v5 = X;
    v1.m128d_f64[0] = X * 0.6366197723675814 + 0.5;
    v6 = _mm_cvttpd_epi32(v1);
    *(_QWORD *)&v7 = (unsigned __int128)_mm_cvtepi32_pd(v6);
    v8 = v5 - 1.570796326734126 * v7;
    v9 = 6.077100506506192e-11 * v7;
    v10 = _mm_cvtsi128_si32(v6);
    result = v8 - 6.077100506506192e-11 * v7;
    v11 = (unsigned __int64)(2 * COERCE_SIGNED_INT64(v8 - 6.077100506506192e-11 * v7)) >> 53;
    if ( (signed __int64)(((unsigned __int64)v2 >> 52) - v11) > 15 )
    {
      v12 = v8;
      v8 = v8 - 6.077100506303966e-11 * v7;
      v9 = 2.022266248795951e-21 * v7 - (v12 - v8 - 6.077100506303966e-11 * v7);
      result = v8 - v9;
    }
    v13 = v8 - result - v9;
    if ( v11 < 1010 )
    {
      if ( v11 <= 990 )
      {
        if ( !(v10 & 1) )
          result = *(double *)&L__real_3ff0000000000000_1;
      }
      else
      {
        v14 = result * result;
        if ( v10 & 1 )
          result = result - 0.1666666666666667 * result * v14;
        else
          result = 1.0 - v14 * 0.5;
      }
      goto Ladjust_region_0;
    }
  }
  v15 = result * result;
  if ( v10 & 1 )
    result = v13
           + result
           * v15
           * (((1.591814430448591e-10 * v15 + -0.0000000250511320680217) * v15 + 0.00000275573161037288)
            * (v15
             * v15
             * v15)
            + (-0.0001984126983676113 * v15 + 0.00833333333333095) * v15
            + -0.1666666666666667)
           - v15 * 0.5 * v13
           + result;
  else
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
           - v13 * result
           - (v15 * 0.5
            - 1.0);
Ladjust_region_0:
  if ( (v10 + 1) & 2 )
    result = 0.0 - result;
  return result;
}


// File Line: 130
// RVA: 0x12B64C0
double __cdecl cos(double X)
{
  __m128d v1; // xmm2
  unsigned __int64 v2; // r10
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
  long double r[2]; // [rsp+A0h] [rbp-58h] BYREF
  long double rr[2]; // [rsp+B0h] [rbp-48h] BYREF
  int region[14]; // [rsp+C0h] [rbp-38h] BYREF

  v1 = 0i64;
  if ( (*(_QWORD *)&X & 0x7FF0000000000000i64) == 0x7FF0000000000000i64 )
    return cos_special(X);
  v2 = *(_QWORD *)&X & 0x7FFFFFFFFFFFFFFFi64;
  if ( (*(_QWORD *)&X & 0x7FFFFFFFFFFFFFFFui64) <= 0x3FE921FB54442D18i64 )
  {
    if ( (*(_QWORD *)&X & 0x7FFFFFFFFFFFFFFFui64) >= 0x3F20000000000000i64 )
    {
      v4 = X * X * (X * X);
      return 1.0
           - (X * X * -0.5
            + 1.0)
           + X * X * -0.5
           + (-0.00138888888888874 * (X * X) + 0.04166666666666666) * v4
           + (-0.0000002755731727234489 * (X * X) + 0.00002480158729876704) * (v4 * v4)
           + v4 * (v4 * v4) * (-1.138263981623609e-11 * (X * X) + 0.000000002087614638237214)
           + X * X * -0.5
           + 1.0;
    }
    else if ( (*(_QWORD *)&X & 0x7FFFFFFFFFFFFFFFui64) >= 0x3E40000000000000i64 )
    {
      return 1.0 - X * X * 0.5;
    }
    else
    {
      return *(double *)&L__real_3ff0000000000000_1;
    }
  }
  if ( *(_QWORD *)&X != v2 )
    X = 0.0 - X;
  if ( v2 >= L__real_411E848000000000_1 )
  {
    _remainder_piby2(X, r, rr, region);
    result = r[0];
    v13 = rr[0];
    v10 = region[0];
  }
  else
  {
    v5 = X;
    v1.m128d_f64[0] = X * 0.6366197723675814 + 0.5;
    v6 = _mm_cvttpd_epi32(v1);
    v7 = _mm_cvtepi32_pd(v6).m128d_f64[0];
    v8 = v5 - 1.570796326734126 * v7;
    v9 = 6.077100506506192e-11 * v7;
    v10 = _mm_cvtsi128_si32(v6);
    result = v8 - 6.077100506506192e-11 * v7;
    v11 = (unsigned __int64)(2i64 * *(_QWORD *)&result) >> 53;
    if ( (__int64)((v2 >> 52) - v11) > 15 )
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
        if ( (v10 & 1) == 0 )
          result = *(double *)&L__real_3ff0000000000000_1;
      }
      else
      {
        v14 = result * result;
        if ( (v10 & 1) != 0 )
          result = result - 0.1666666666666667 * result * v14;
        else
          result = 1.0 - v14 * 0.5;
      }
      goto Ladjust_region_0;
    }
  }
  v15 = result * result;
  if ( (v10 & 1) != 0 )
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
  if ( ((v10 + 1) & 2) != 0 )
    return 0.0 - result;
  return result;
}


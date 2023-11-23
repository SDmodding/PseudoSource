// File Line: 126
// RVA: 0x12B7FB0
double __cdecl sin(double X)
{
  __m128d v1; // xmm2
  unsigned __int64 v2; // r10
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
  double v14; // xmm2_8
  char v15; // [rsp+0h] [rbp-F8h]
  long double r[2]; // [rsp+A0h] [rbp-58h] BYREF
  long double rr[2]; // [rsp+B0h] [rbp-48h] BYREF
  int region[14]; // [rsp+C0h] [rbp-38h] BYREF

  v1 = 0i64;
  if ( (*(_QWORD *)&X & 0x7FF0000000000000i64) == 0x7FF0000000000000i64 )
    return sin_special(X);
  v2 = *(_QWORD *)&X & 0x7FFFFFFFFFFFFFFFi64;
  if ( (*(_QWORD *)&X & 0x7FFFFFFFFFFFFFFFui64) <= 0x3FE921FB54442D18i64 )
  {
    if ( (*(_QWORD *)&X & 0x7FFFFFFFFFFFFFFFui64) >= 0x3F20000000000000i64 )
      return X
           + X
           * (X
            * X)
           * (((1.591814430448591e-10 * (X * X) + -0.0000000250511320680217) * (X * X) + 0.00000275573161037288)
            * (X
             * X
             * (X
              * X)
             * (X
              * X))
            + (-0.0001984126983676113 * (X * X) + 0.00833333333333095) * (X * X)
            + -0.1666666666666667);
    if ( (*(_QWORD *)&X & 0x7FFFFFFFFFFFFFFFui64) >= 0x3E40000000000000i64 )
      return X - X * X * X * 0.1666666666666667;
    return X;
  }
  v3 = 0;
  if ( *(_QWORD *)&X != v2 )
  {
    v3 = 1;
    X = 0.0 - X;
  }
  if ( v2 >= L__real_411E848000000000_2 )
  {
    v15 = v3;
    _remainder_piby2(X, r, rr, region);
    v3 = v15;
    X = r[0];
    v12 = rr[0];
    v9 = region[0];
  }
  else
  {
    v4 = X;
    v1.m128d_f64[0] = X * 0.6366197723675814 + 0.5;
    v5 = _mm_cvttpd_epi32(v1);
    v6 = _mm_cvtepi32_pd(v5).m128d_f64[0];
    v7 = v4 - 1.570796326734126 * v6;
    v8 = 6.077100506506192e-11 * v6;
    v9 = _mm_cvtsi128_si32(v5);
    X = v7 - 6.077100506506192e-11 * v6;
    v10 = (unsigned __int64)(2i64 * *(_QWORD *)&X) >> 53;
    if ( (__int64)((v2 >> 52) - v10) > 15 )
    {
      v11 = v7;
      v7 = v7 - 6.077100506303966e-11 * v6;
      v8 = 2.022266248795951e-21 * v6 - (v11 - v7 - 6.077100506303966e-11 * v6);
      X = v7 - v8;
    }
    v12 = v7 - X - v8;
    if ( v10 < 1010 )
    {
      if ( v10 <= 990 )
      {
        if ( (v9 & 1) != 0 )
          X = *(double *)&L__real_3ff0000000000000_2;
      }
      else
      {
        v13 = X * X;
        if ( (v9 & 1) != 0 )
          X = 1.0 - v13 * 0.5;
        else
          X = X - 0.1666666666666667 * X * v13;
      }
      goto Ladjust_region_1;
    }
  }
  v14 = X * X;
  if ( (v9 & 1) != 0 )
    X = ((0.00002480158729876704 * v14 + -0.00138888888888874) * v14
       + 0.04166666666666666
       + ((-1.138263981623609e-11 * v14 + 0.000000002087614638237214) * v14 + -0.0000002755731727234489)
       * (v14
        * v14
        * v14))
      * (v14
       * v14)
      + 0.5 * v14
      - 1.0
      + 1.0
      - v14 * 0.5
      - v12 * X
      - (v14 * 0.5
       - 1.0);
  else
    X = v12
      + X
      * v14
      * (((1.591814430448591e-10 * v14 + -0.0000000250511320680217) * v14 + 0.00000275573161037288) * (v14 * v14 * v14)
       + (-0.0001984126983676113 * v14 + 0.00833333333333095) * v14
       + -0.1666666666666667)
      - v14 * 0.5 * v12
      + X;
Ladjust_region_1:
  if ( (((unsigned __int8)(~v3 & ~(unsigned __int8)(v9 >> 1)) | (unsigned __int8)(v3 & (v9 >> 1))) & 1) == 0 )
    return 0.0 - X;
  return X;
}


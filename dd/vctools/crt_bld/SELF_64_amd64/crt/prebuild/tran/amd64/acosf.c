// File Line: 24
// RVA: 0x12B02F8
float __fastcall acosf(float x)
{
  unsigned int v1; // edx
  int v2; // ecx
  float v4; // xmm6_4
  float v5; // xmm5_4
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm6_4
  float v9; // [rsp+70h] [rbp+8h]
  float v10; // [rsp+78h] [rbp+10h]

  v9 = 0.0;
  v1 = LODWORD(x) & 0x80000000;
  v2 = (unsigned __int8)(LODWORD(x) >> 23) - 127;
  if ( (LODWORD(x) & 0x7FFFFFFFu) > 0x7F800000 )
    return handle_errorf("acosf", 13, LODWORD(x) | 0x400000i64, 1, 0, 33, x, 0.0, 1);
  if ( v2 < -26 )
  {
    v4 = FLOAT_1_5707964;
    goto LABEL_11;
  }
  if ( v2 >= 0 )
  {
    if ( x == 1.0 )
      return 0.0;
    if ( x != -1.0 )
      return handle_errorf("acosf", 13, 0xFFC00000ui64, 1, 8, 33, x, 0.0, 1);
    v4 = FLOAT_3_1415927;
LABEL_11:
    set_statfp(0x20ui64);
    return v4;
  }
  v5 = x;
  if ( v1 )
    LODWORD(v5) = LODWORD(x) ^ _xmm[0];
  if ( v2 < -1 )
  {
    v7 = 0.0;
    v6 = v5 * v5;
    v10 = v5 * v5;
  }
  else
  {
    v6 = (float)(1.0 - v5) * 0.5;
    v10 = v6;
    v9 = fsqrt(v6);
    v7 = v9;
    v5 = v9;
  }
  v8 = (float)((float)((float)((float)((float)((float)(-0.013381929 - (float)(v6 * 0.0039613745)) * v6) - 0.056529868)
                             * v6)
                     + 0.1841616)
             * v6)
     / (float)(1.1049696 - (float)(v6 * 0.8364113));
  if ( v2 < -1 )
    return 1.570796326794897 - (x - (6.123233995736766e-17 - (float)(v8 * x)));
  if ( v1 )
    return 3.141592653589793 - ((float)(v8 * v5) - 6.123233995736766e-17 + v7) * 2.0;
  return (float)((float)((float)((float)(v10
                                       - (float)(COERCE_FLOAT(LODWORD(v7) & 0xFFFF0000)
                                               * COERCE_FLOAT(LODWORD(v7) & 0xFFFF0000)))
                               / (float)(COERCE_FLOAT(LODWORD(v7) & 0xFFFF0000) + v9))
                       * 2.0)
               + (float)((float)(v5 * 2.0) * v8))
       + (float)(COERCE_FLOAT(LODWORD(v7) & 0xFFFF0000) * 2.0);
}


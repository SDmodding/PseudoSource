// File Line: 24
// RVA: 0x12B0584
float __fastcall asinf(float x)
{
  float v1; // xmm6_4
  unsigned int v2; // edx
  int v3; // ecx
  float result; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // [rsp+70h] [rbp+8h]
  float v10; // [rsp+78h] [rbp+10h]

  v9 = 0.0;
  v1 = x;
  v2 = LODWORD(x) & 0x80000000;
  v3 = (unsigned __int8)(LODWORD(x) >> 23) - 127;
  if ( (LODWORD(x) & 0x7FFFFFFFu) > 0x7F800000 )
    return handle_errorf("asinf", 14, LODWORD(x) | 0x400000i64, 1, 0, 33, x, 0.0, 1);
  if ( v3 < -14 )
  {
LABEL_10:
    set_statfp(0x20ui64);
    return v1;
  }
  if ( v3 < 0 )
  {
    if ( v2 )
      LODWORD(v1) = LODWORD(x) ^ _xmm[0];
    if ( v3 < -1 )
    {
      v6 = 0.0;
      v5 = v1 * v1;
      v10 = v1 * v1;
    }
    else
    {
      v5 = (float)(1.0 - v1) * 0.5;
      v10 = (float)(1.0 - v1) * 0.5;
      v9 = fsqrt(v5);
      v6 = v9;
      v1 = v9;
    }
    v7 = (float)((float)((float)((float)((float)((float)(-0.013381929 - (float)(v5 * 0.0039613745)) * v5) - 0.056529868)
                               * v5)
                       + 0.1841616)
               * v5)
       / (float)(1.1049696 - (float)(v5 * 0.8364113));
    if ( v3 >= -1 )
      v8 = 0.78539813
         - (float)((float)((float)((float)(v9 * 2.0) * v7)
                         - (float)(0.000000075497894
                                 - (float)((float)((float)(v10
                                                         - (float)(COERCE_FLOAT(LODWORD(v6) & 0xFFFF0000)
                                                                 * COERCE_FLOAT(LODWORD(v6) & 0xFFFF0000)))
                                                 / (float)(COERCE_FLOAT(LODWORD(v6) & 0xFFFF0000) + v9))
                                         * 2.0)))
                 - (float)(0.78539813 - (float)(COERCE_FLOAT(LODWORD(v6) & 0xFFFF0000) * 2.0)));
    else
      v8 = (float)(v7 * v1) + v1;
    if ( v2 )
      LODWORD(v8) ^= _xmm[0];
    result = v8;
  }
  else
  {
    if ( x == 1.0 )
    {
      v1 = FLOAT_1_5707964;
      goto LABEL_10;
    }
    if ( x == -1.0 )
    {
      v1 = FLOAT_N1_5707964;
      goto LABEL_10;
    }
    result = handle_errorf("asinf", 14, 0xFFC00000ui64, 1, 8, 33, x, 0.0, 1);
  }
  return result;
}


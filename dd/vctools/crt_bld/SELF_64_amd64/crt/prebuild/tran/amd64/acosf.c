// File Line: 24
// RVA: 0x12B02F8
float __fastcall acosf(float x)
{
  unsigned int v1; // edx
  int v2; // ecx
  float result; // xmm0_4
  float v4; // xmm6_4
  int v5; // xmm5_4
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
LABEL_11:
    set_statfp(0x20ui64);
    return v4;
  }
  if ( v2 < 0 )
  {
    *(float *)&v5 = x;
    if ( v1 )
      v5 = LODWORD(x) ^ _xmm[0];
    if ( v2 < -1 )
    {
      v7 = 0.0;
      v6 = *(float *)&v5 * *(float *)&v5;
      v10 = *(float *)&v5 * *(float *)&v5;
    }
    else
    {
      v6 = (float)(1.0 - *(float *)&v5) * 0.5;
      v10 = (float)(1.0 - *(float *)&v5) * 0.5;
      v9 = fsqrt(v6);
      v7 = v9;
      *(float *)&v5 = v9;
    }
    v8 = (float)((float)((float)((float)((float)((float)(-0.013381929 - (float)(v6 * 0.0039613745)) * v6) - 0.056529868)
                               * v6)
                       + 0.1841616)
               * v6)
       / (float)(1.1049696 - (float)(v6 * 0.8364113));
    if ( v2 >= -1 )
    {
      if ( v1 )
        result = 3.141592653589793 - ((float)(v8 * *(float *)&v5) - 6.123233995736766e-17 + v7) * 2.0;
      else
        result = (float)((float)((float)((float)(v10
                                               - (float)(COERCE_FLOAT(LODWORD(v7) & 0xFFFF0000)
                                                       * COERCE_FLOAT(LODWORD(v7) & 0xFFFF0000)))
                                       / (float)(COERCE_FLOAT(LODWORD(v7) & 0xFFFF0000) + v9))
                               * 2.0)
                       + (float)((float)(*(float *)&v5 * 2.0) * v8))
               + (float)(COERCE_FLOAT(LODWORD(v7) & 0xFFFF0000) * 2.0);
    }
    else
    {
      result = 1.570796326794897 - (x - (6.123233995736766e-17 - (float)(v8 * x)));
    }
  }
  else
  {
    if ( x == 1.0 )
      return 0.0;
    if ( x == -1.0 )
    {
      v4 = FLOAT_3_1415927;
      goto LABEL_11;
    }
    result = handle_errorf("acosf", 13, 0xFFC00000ui64, 1, 8, 33, x, 0.0, 1);
  }
  return result;
}


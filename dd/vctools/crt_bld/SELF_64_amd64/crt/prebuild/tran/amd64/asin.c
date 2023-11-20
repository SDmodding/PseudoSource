// File Line: 20
// RVA: 0x12B57E4
long double __fastcall asin(long double x)
{
  double v1; // xmm6_8
  unsigned __int64 v2; // rdx
  signed int v3; // ecx
  long double result; // xmm0_8
  double v5; // xmm2_8
  double v6; // xmm3_8
  double v7; // xmm1_8
  double v8; // xmm1_8
  double v9; // [rsp+70h] [rbp+8h]
  double v10; // [rsp+78h] [rbp+10h]

  v1 = x;
  v9 = 0.0;
  v2 = *(_QWORD *)&x & 0x8000000000000000ui64;
  v3 = ((*(_QWORD *)&x >> 52) & 0x7FF) - 1023;
  if ( (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFui64) > 0x7FF0000000000000i64 )
    return handle_error("asin", 14, *(_QWORD *)&x | 0x8000000000000i64, 1, 0, 33, x, 0.0, 1);
  if ( v3 < -28 )
  {
LABEL_10:
    set_statfp(0x20ui64);
    return v1;
  }
  if ( v3 < 0 )
  {
    if ( v2 )
      v1 = -x;
    if ( v3 < -1 )
    {
      v6 = 0.0;
      v5 = v1 * v1;
      v10 = v1 * v1;
    }
    else
    {
      v5 = (1.0 - v1) * 0.5;
      v10 = (1.0 - v1) * 0.5;
      v9 = sqrt(v5);
      v6 = v9;
      v1 = v9;
    }
    v7 = (((((v5 * 0.0000482901920344787 + 0.001092426972350747) * v5 - 0.05499898092356859) * v5 + 0.2755581752569377)
         * v5
         - 0.4450172168676356)
        * v5
        + 0.227485835556935)
       * v5
       / ((((v5 * 0.1058694220872044 - 0.9436391370324927) * v5 + 2.76568859157271) * v5 - 3.284315057209587) * v5
        + 1.36491501334161);
    if ( v3 >= -1 )
      v8 = 0.7853981633974483
         - (v9 * 2.0 * v7
          - (6.123233995736766e-17
           - (v10
            - COERCE_DOUBLE(*(_QWORD *)&v6 & 0xFFFFFFFF00000000ui64)
            * COERCE_DOUBLE(*(_QWORD *)&v6 & 0xFFFFFFFF00000000ui64))
           / (COERCE_DOUBLE(*(_QWORD *)&v6 & 0xFFFFFFFF00000000ui64) + v9)
           * 2.0)
          - (0.7853981633974483
           - COERCE_DOUBLE(*(_QWORD *)&v6 & 0xFFFFFFFF00000000ui64) * 2.0));
    else
      v8 = v7 * v1 + v1;
    if ( v2 )
      v8 = -v8;
    result = v8;
  }
  else
  {
    if ( x == 1.0 )
    {
      v1 = DOUBLE_1_570796326794897;
      goto LABEL_10;
    }
    if ( x == -1.0 )
    {
      v1 = DOUBLE_N1_570796326794897;
      goto LABEL_10;
    }
    result = handle_error("asin", 14, 0xFFF8000000000000ui64, 1, 8, 33, x, 0.0, 1);
  }
  return result;
}


// File Line: 21
// RVA: 0x12B54FC
double __fastcall acos(long double x)
{
  unsigned __int64 v1; // rdx
  int v2; // ecx
  double v4; // xmm6_8
  double v5; // xmm6_8
  double v6; // xmm3_8
  double v7; // xmm4_8
  double v8; // xmm5_8
  double v9; // [rsp+70h] [rbp+8h]
  double v10; // [rsp+78h] [rbp+10h]

  v9 = 0.0;
  v1 = *(_QWORD *)&x & 0x8000000000000000ui64;
  v2 = ((*(_QWORD *)&x >> 52) & 0x7FF) - 1023;
  if ( (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFui64) > 0x7FF0000000000000i64 )
    return handle_error("acos", 13, *(_QWORD *)&x | 0x8000000000000i64, 1, 0, 33, x, 0.0, 1);
  if ( v2 < -56 )
  {
    v4 = DOUBLE_1_570796326794897;
    goto LABEL_11;
  }
  if ( v2 >= 0 )
  {
    if ( x == 1.0 )
      return 0.0;
    if ( x != -1.0 )
      return handle_error("acos", 13, 0xFFF8000000000000ui64, 1, 8, 33, x, 0.0, 1);
    v4 = DOUBLE_3_141592653589793;
LABEL_11:
    set_statfp(0x20ui64);
    return v4;
  }
  v5 = x;
  if ( v1 )
    v5 = -x;
  if ( v2 < -1 )
  {
    v7 = 0.0;
    v6 = v5 * v5;
    v10 = v5 * v5;
  }
  else
  {
    v6 = (1.0 - v5) * 0.5;
    v10 = v6;
    v9 = sqrt(v6);
    v7 = v9;
    v5 = v9;
  }
  v8 = (((((v6 * 0.0000482901920344787 + 0.001092426972350747) * v6 - 0.05499898092356859) * v6 + 0.2755581752569377)
       * v6
       - 0.4450172168676356)
      * v6
      + 0.227485835556935)
     * v6
     / ((((v6 * 0.1058694220872044 - 0.9436391370324927) * v6 + 2.76568859157271) * v6 - 3.284315057209587) * v6
      + 1.36491501334161);
  if ( v2 < -1 )
    return 1.570796326794897 - (x - (6.123233995736766e-17 - v8 * x));
  if ( v1 )
    return 3.141592653589793 - (v8 * v5 - 6.123233995736766e-17 + v7) * 2.0;
  return (v10
        - COERCE_DOUBLE(*(_QWORD *)&v7 & 0xFFFFFFFF00000000ui64)
        * COERCE_DOUBLE(*(_QWORD *)&v7 & 0xFFFFFFFF00000000ui64))
       / (COERCE_DOUBLE(*(_QWORD *)&v7 & 0xFFFFFFFF00000000ui64) + v9)
       * 2.0
       + v5 * 2.0 * v8
       + COERCE_DOUBLE(*(_QWORD *)&v7 & 0xFFFFFFFF00000000ui64) * 2.0;
}


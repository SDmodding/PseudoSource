// File Line: 56
// RVA: 0x12B6BE8
double __fastcall fmod(double x, long double y)
{
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // r11
  __int64 v4; // rcx
  __int64 v5; // rdx
  __int64 v6; // r8
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rax
  double v9; // xmm7_8
  double v10; // xmm8_8
  unsigned int v11; // r11d
  int v12; // r10d
  double v13; // xmm10_8
  __int64 v14; // rcx
  double v15; // xmm0_8
  double v16; // xmm3_8
  double v17; // xmm7_8
  int flags; // [rsp+20h] [rbp-98h]
  long double arg1; // [rsp+30h] [rbp-88h]
  long double arg2; // [rsp+38h] [rbp-80h]
  double v21; // [rsp+C0h] [rbp+8h]
  double v22; // [rsp+D0h] [rbp+18h]

  v21 = x;
  v2 = *(_QWORD *)&y & 0x7FFFFFFFFFFFFFFFi64;
  v3 = *(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64;
  v4 = (*(_QWORD *)&x >> 52) & 0x7FFi64;
  v5 = (*(_QWORD *)&y >> 52) & 0x7FFi64;
  if ( ((*(_QWORD *)&x >> 52) & 0x7FF) == 0 )
    goto LABEL_6;
  if ( ((*(_QWORD *)&x >> 52) & 0x7FF) == 2047 )
    goto LABEL_7;
  if ( (unsigned int)(v5 - 1) > 0x7FD )
  {
LABEL_6:
    if ( ((*(_QWORD *)&x >> 52) & 0x7FF) != 2047 )
    {
      if ( ((*(_QWORD *)&y >> 52) & 0x7FF) == 2047 )
      {
        if ( (*(_QWORD *)&y & 0xFFFFFFFFFFFFFi64) == 0 )
          return x;
        arg2 = y;
        arg1 = x;
        flags = 0;
        v6 = *(_QWORD *)&y | 0x8000000000000i64;
      }
      else
      {
        if ( *(double *)&v3 == 0.0 )
        {
          if ( *(double *)&v2 != 0.0 )
            return x;
        }
        else if ( *(double *)&v2 != 0.0 )
        {
          if ( ((*(_QWORD *)&x >> 52) & 0x7FF) == 0 )
          {
            v7 = *(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64;
            if ( v3 < 0x10000000000000i64 )
            {
              do
              {
                v7 *= 2i64;
                LODWORD(v4) = v4 - 1;
              }
              while ( v7 < 0x10000000000000i64 );
            }
          }
          if ( ((*(_QWORD *)&y >> 52) & 0x7FF) == 0 )
          {
            v8 = *(_QWORD *)&y & 0x7FFFFFFFFFFFFFFFi64;
            if ( v2 < 0x10000000000000i64 )
            {
              do
              {
                v8 *= 2i64;
                LODWORD(v5) = v5 - 1;
              }
              while ( v8 < 0x10000000000000i64 );
            }
          }
          goto LABEL_24;
        }
        arg2 = y;
        arg1 = x;
        v6 = 0xFFF8000000000000ui64;
        flags = 8;
      }
      return handle_error("fmod", 22, v6, 1, flags, 33, arg1, arg2, 2);
    }
LABEL_7:
    arg2 = y;
    arg1 = x;
    if ( (*(_QWORD *)&x & 0xFFFFFFFFFFFFFi64) == 0 )
      return handle_error("fmod", 22, 0xFFF8000000000000ui64, 1, 8, 33, x, y, 2);
    flags = 0;
    v6 = *(_QWORD *)&x | 0x8000000000000i64;
    return handle_error("fmod", 22, v6, 1, flags, 33, arg1, arg2, 2);
  }
  if ( v3 == v2 )
  {
    *(_QWORD *)&x &= 0x8000000000000000ui64;
    return x;
  }
LABEL_24:
  *(_QWORD *)&v9 = *(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64;
  *(_QWORD *)&v10 = *(_QWORD *)&y & 0x7FFFFFFFFFFFFFFFi64;
  if ( v3 < v2 )
  {
    if ( x < 0.0 )
      return -*(double *)&v3;
    return v9;
  }
  v11 = _mm_getcsr();
  if ( (int)v4 > (int)v5 )
  {
    v12 = ((int)v4 - (int)v5) / 52;
    if ( v12 )
    {
      v10 = COERCE_DOUBLE((52 * v12 / 3 + 1023i64) << 52)
          * *(double *)&v2
          * COERCE_DOUBLE(((52 * v12 - 52 * v12 / 3) / 2 + 1023i64) << 52)
          * COERCE_DOUBLE((52 * v12 - (52 * v12 - 52 * v12 / 3) / 2 - 52 * v12 / 3 + 1023i64) << 52);
      v13 = 2.220446049250313e-16;
      goto LABEL_33;
    }
  }
  else
  {
    v12 = 0;
  }
  v13 = DOUBLE_1_0;
LABEL_33:
  if ( v12 > 0 )
  {
    v14 = (unsigned int)v12;
    do
    {
      v15 = (double)(int)(v9 / v10);
      v9 = v9
         - (v9
          - v15 * v10)
         - v15 * v10
         - (COERCE_DOUBLE(*(_QWORD *)&v15 & 0xFFFFFFFFF8000000ui64)
          * COERCE_DOUBLE(*(_QWORD *)&v10 & 0xFFFFFFFFF8000000ui64)
          - v15 * v10
          + (v15 - COERCE_DOUBLE(*(_QWORD *)&v15 & 0xFFFFFFFFF8000000ui64))
          * COERCE_DOUBLE(*(_QWORD *)&v10 & 0xFFFFFFFFF8000000ui64)
          + COERCE_DOUBLE(*(_QWORD *)&v15 & 0xFFFFFFFFF8000000ui64)
          * (v10 - COERCE_DOUBLE(*(_QWORD *)&v10 & 0xFFFFFFFFF8000000ui64))
          + (v15 - COERCE_DOUBLE(*(_QWORD *)&v15 & 0xFFFFFFFFF8000000ui64))
          * (v10 - COERCE_DOUBLE(*(_QWORD *)&v10 & 0xFFFFFFFFF8000000ui64)))
         + v9
         - v15 * v10;
      if ( v9 < 0.0 )
        v9 = v9 + v10;
      v10 = v10 * v13;
      --v14;
    }
    while ( v14 );
  }
  v16 = (double)(int)(v9 / v10);
  v17 = v9
      - (v9
       - v16 * v10)
      - v16 * v10
      - (COERCE_DOUBLE(*(_QWORD *)&v16 & 0xFFFFFFFFF8000000ui64)
       * COERCE_DOUBLE(*(_QWORD *)&v10 & 0xFFFFFFFFF8000000ui64)
       - v16 * v10
       + (v16 - COERCE_DOUBLE(*(_QWORD *)&v16 & 0xFFFFFFFFF8000000ui64))
       * COERCE_DOUBLE(*(_QWORD *)&v10 & 0xFFFFFFFFF8000000ui64)
       + COERCE_DOUBLE(*(_QWORD *)&v16 & 0xFFFFFFFFF8000000ui64)
       * (v10 - COERCE_DOUBLE(*(_QWORD *)&v10 & 0xFFFFFFFFF8000000ui64))
       + (v16 - COERCE_DOUBLE(*(_QWORD *)&v16 & 0xFFFFFFFFF8000000ui64))
       * (v10 - COERCE_DOUBLE(*(_QWORD *)&v10 & 0xFFFFFFFFF8000000ui64)))
      + v9
      - v16 * v10;
  v22 = v17;
  if ( v17 < 0.0 )
    v22 = v17 + v10;
  _mm_setcsr(v11);
  x = v22;
  if ( v21 < 0.0 )
    return -v22;
  return x;
}


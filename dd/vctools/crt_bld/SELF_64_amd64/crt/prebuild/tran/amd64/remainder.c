// File Line: 56
// RVA: 0x12B6BE8
long double __fastcall fmod(long double result, long double y)
{
  long double v2; // r10
  long double v3; // rbx
  unsigned __int64 v4; // r8
  unsigned __int64 v5; // r11
  signed __int64 v6; // rcx
  signed __int64 v7; // rdx
  signed __int64 v8; // r8
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rax
  double v11; // xmm7_8
  double v12; // xmm8_8
  unsigned int v13; // er11
  int v14; // er10
  double v15; // xmm10_8
  __int64 v16; // rcx
  double v17; // xmm0_8
  double v18; // xmm3_8
  double v19; // xmm7_8
  signed int flags; // [rsp+20h] [rbp-98h]
  long double arg1; // [rsp+30h] [rbp-88h]
  long double arg2; // [rsp+38h] [rbp-80h]
  double v23; // [rsp+C0h] [rbp+8h]
  double v24; // [rsp+D0h] [rbp+18h]

  v23 = result;
  v2 = result;
  v3 = y;
  v4 = *(_QWORD *)&y & 0x7FFFFFFFFFFFFFFFi64;
  v5 = *(_QWORD *)&result & 0x7FFFFFFFFFFFFFFFi64;
  v6 = (*(_QWORD *)&result >> 52) & 0x7FFi64;
  v7 = (*(_QWORD *)&y >> 52) & 0x7FFi64;
  if ( (signed int)v6 < 1 )
    goto LABEL_46;
  if ( (signed int)v6 > 2046 )
    goto LABEL_7;
  if ( (unsigned int)(v7 - 1) > 0x7FD )
  {
LABEL_46:
    if ( (signed int)v6 <= 2046 )
    {
      if ( (signed int)v7 <= 2046 )
      {
        if ( *(double *)&v5 == 0.0 )
        {
          if ( *(double *)&v4 != 0.0 )
            return result;
        }
        else if ( *(double *)&v4 != 0.0 )
        {
          if ( (signed int)v6 < 1 )
          {
            v9 = *(_QWORD *)&result & 0x7FFFFFFFFFFFFFFFi64;
            if ( v5 < 0x10000000000000i64 )
            {
              do
              {
                v9 *= 2i64;
                LODWORD(v6) = v6 - 1;
              }
              while ( v9 < 0x10000000000000i64 );
            }
          }
          if ( (signed int)v7 < 1 )
          {
            v10 = *(_QWORD *)&y & 0x7FFFFFFFFFFFFFFFi64;
            if ( v4 < 0x10000000000000i64 )
            {
              do
              {
                v10 *= 2i64;
                LODWORD(v7) = v7 - 1;
              }
              while ( v10 < 0x10000000000000i64 );
            }
          }
          goto LABEL_26;
        }
        arg2 = y;
        arg1 = result;
        v8 = -2251799813685248i64;
        flags = 8;
      }
      else
      {
        if ( !(*(_QWORD *)&v3 & 0xFFFFFFFFFFFFFi64) )
          return result;
        arg2 = y;
        arg1 = result;
        flags = 0;
        v8 = *(_QWORD *)&y | 0x8000000000000i64;
      }
      return handle_error("fmod", 22, v8, 1, flags, 33, arg1, arg2, 2);
    }
LABEL_7:
    arg2 = y;
    arg1 = result;
    if ( !(*(_QWORD *)&v2 & 0xFFFFFFFFFFFFFi64) )
      return handle_error("fmod", 22, 0xFFF8000000000000ui64, 1, 8, 33, result, y, 2);
    flags = 0;
    v8 = *(_QWORD *)&result | 0x8000000000000i64;
    return handle_error("fmod", 22, v8, 1, flags, 33, arg1, arg2, 2);
  }
  if ( v5 == v4 )
  {
    *(_QWORD *)&result &= 0x8000000000000000ui64;
    return result;
  }
LABEL_26:
  *(_QWORD *)&v11 = *(_QWORD *)&result & 0x7FFFFFFFFFFFFFFFi64;
  *(_QWORD *)&v12 = *(_QWORD *)&y & 0x7FFFFFFFFFFFFFFFi64;
  if ( v5 < v4 )
  {
    if ( result < 0.0 )
      v11 = -*(double *)&v5;
    return v11;
  }
  v13 = _mm_getcsr();
  if ( (signed int)v6 > (signed int)v7 )
  {
    v14 = ((signed int)v6 - (signed int)v7) / 52;
    if ( v14 )
    {
      v12 = COERCE_DOUBLE((52 * v14 / 3 + 1023i64) << 52)
          * *(double *)&v4
          * COERCE_DOUBLE(((52 * v14 - 52 * v14 / 3) / 2 + 1023i64) << 52)
          * COERCE_DOUBLE((52 * v14 - (52 * v14 - 52 * v14 / 3) / 2 - 52 * v14 / 3 + 1023i64) << 52);
      v15 = 2.220446049250313e-16;
      goto LABEL_35;
    }
  }
  else
  {
    v14 = 0;
  }
  v15 = DOUBLE_1_0;
LABEL_35:
  if ( v14 > 0 )
  {
    v16 = (unsigned int)v14;
    do
    {
      v17 = (double)(signed int)(v11 / v12);
      v11 = v11
          - (v11
           - v17 * v12)
          - v17 * v12
          - (COERCE_DOUBLE(*(_QWORD *)&v17 & 0xFFFFFFFFF8000000ui64)
           * COERCE_DOUBLE(*(_QWORD *)&v12 & 0xFFFFFFFFF8000000ui64)
           - v17 * v12
           + (v17 - COERCE_DOUBLE(*(_QWORD *)&v17 & 0xFFFFFFFFF8000000ui64))
           * COERCE_DOUBLE(*(_QWORD *)&v12 & 0xFFFFFFFFF8000000ui64)
           + COERCE_DOUBLE(*(_QWORD *)&v17 & 0xFFFFFFFFF8000000ui64)
           * (v12 - COERCE_DOUBLE(*(_QWORD *)&v12 & 0xFFFFFFFFF8000000ui64))
           + (v17 - COERCE_DOUBLE(*(_QWORD *)&v17 & 0xFFFFFFFFF8000000ui64))
           * (v12 - COERCE_DOUBLE(*(_QWORD *)&v12 & 0xFFFFFFFFF8000000ui64)))
          + v11
          - v17 * v12;
      if ( v11 < 0.0 )
        v11 = v11 + v12;
      v12 = v12 * v15;
      --v16;
    }
    while ( v16 );
  }
  v18 = (double)(signed int)(v11 / v12);
  v19 = v11
      - (v11
       - v18 * v12)
      - v18 * v12
      - (COERCE_DOUBLE(*(_QWORD *)&v18 & 0xFFFFFFFFF8000000ui64)
       * COERCE_DOUBLE(*(_QWORD *)&v12 & 0xFFFFFFFFF8000000ui64)
       - v18 * v12
       + (v18 - COERCE_DOUBLE(*(_QWORD *)&v18 & 0xFFFFFFFFF8000000ui64))
       * COERCE_DOUBLE(*(_QWORD *)&v12 & 0xFFFFFFFFF8000000ui64)
       + COERCE_DOUBLE(*(_QWORD *)&v18 & 0xFFFFFFFFF8000000ui64)
       * (v12 - COERCE_DOUBLE(*(_QWORD *)&v12 & 0xFFFFFFFFF8000000ui64))
       + (v18 - COERCE_DOUBLE(*(_QWORD *)&v18 & 0xFFFFFFFFF8000000ui64))
       * (v12 - COERCE_DOUBLE(*(_QWORD *)&v12 & 0xFFFFFFFFF8000000ui64)))
      + v11
      - v18 * v12;
  v24 = v19;
  if ( v19 < 0.0 )
    v24 = v19 + v12;
  _mm_setcsr(v13);
  result = v24;
  if ( v23 < 0.0 )
    result = -v24;
  return result;
}


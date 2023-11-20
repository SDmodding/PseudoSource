// File Line: 41
// RVA: 0x12AFD10
float __fastcall fmodf(float result, float y)
{
  double v2; // r8
  double v3; // r11
  double v4; // r9
  double v5; // r10
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rdx
  double v8; // xmm2_8
  double v9; // xmm3_8
  unsigned int v10; // er8
  double v11; // xmm4_8
  int v12; // edx
  unsigned int v13; // edx
  __int64 v14; // rcx
  double v15; // xmm1_8
  double v16; // xmm2_8
  double v17; // xmm0_8
  float arg1; // [rsp+30h] [rbp-28h]
  float arg2; // [rsp+38h] [rbp-20h]
  float v20; // [rsp+60h] [rbp+8h]

  v20 = result;
  v2 = result;
  v3 = y;
  *(_QWORD *)&v4 = *(unsigned __int64 *)&result & 0x7FFFFFFFFFFFFFFFi64;
  *(_QWORD *)&v5 = *(unsigned __int64 *)&y & 0x7FFFFFFFFFFFFFFFi64;
  v6 = (*(unsigned __int64 *)&result >> 52) & 0x7FF;
  v7 = (*(unsigned __int64 *)&y >> 52) & 0x7FF;
  if ( (signed int)v6 >= 1 )
  {
    if ( (signed int)v6 > 2046 )
      goto LABEL_20;
    if ( (unsigned int)(v7 - 1) <= 0x7FD )
    {
      if ( *(_QWORD *)&v4 == *(_QWORD *)&v5 )
        return COERCE_DOUBLE(*(_QWORD *)&v2 & 0x8000000000000000ui64);
      *(_QWORD *)&v8 = *(unsigned __int64 *)&result & 0x7FFFFFFFFFFFFFFFi64;
      *(_QWORD *)&v9 = *(unsigned __int64 *)&y & 0x7FFFFFFFFFFFFFFFi64;
      if ( *(_QWORD *)&v4 >= *(_QWORD *)&v5 )
      {
        v10 = _mm_getcsr();
        if ( (signed int)v6 > (signed int)v7 )
        {
          v13 = (signed int)((unsigned __int64)(715827883i64 * ((signed int)v6 - (signed int)v7)) >> 32) >> 2;
          v12 = (v13 >> 31) + v13;
          v11 = 0.00000005960464477539062;
          v9 = COERCE_DOUBLE((signed __int64)(24 * v12 + 1023) << 52) * v5;
        }
        else
        {
          v11 = DOUBLE_1_0;
          v12 = 0;
        }
        if ( v12 > 0 )
        {
          v14 = (unsigned int)v12;
          do
          {
            v15 = (double)(signed int)(v8 / v9) * v9;
            v9 = v9 * v11;
            v8 = v8 - v15;
            --v14;
          }
          while ( v14 );
        }
        v16 = v8 - (double)(signed int)(v8 / v9) * v9;
        _mm_setcsr(v10);
        v17 = v16;
        if ( v20 < 0.0 )
          v17 = -v16;
        result = v17;
      }
      else
      {
        if ( result < 0.0 )
          v8 = -v4;
        result = v8;
      }
      return result;
    }
  }
  if ( (signed int)v6 > 2046 )
  {
LABEL_20:
    arg2 = y;
    arg1 = result;
    if ( *(_QWORD *)&v2 & 0xFFFFFFFFFFFFFi64 )
      return handle_errorf("fmodf", 22, LODWORD(result) | 0x400000i64, 1, 0, 33, result, y, 2);
    return handle_errorf("fmodf", 22, 0xFFC00000ui64, 1, 8, 33, arg1, arg2, 2);
  }
  if ( (signed int)v7 <= 2046 )
  {
    if ( (signed int)v6 < 1 && (signed int)v7 >= 1 )
      return result;
    arg2 = y;
    arg1 = result;
    return handle_errorf("fmodf", 22, 0xFFC00000ui64, 1, 8, 33, arg1, arg2, 2);
  }
  if ( *(_QWORD *)&v3 & 0xFFFFFFFFFFFFFi64 )
    result = handle_errorf("fmodf", 22, LODWORD(y) | 0x400000i64, 1, 0, 33, result, y, 2);
  return result;
}


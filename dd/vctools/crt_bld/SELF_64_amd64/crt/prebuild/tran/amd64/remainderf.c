// File Line: 41
// RVA: 0x12AFD10
float __fastcall fmodf(float x, float y)
{
  double v2; // r8
  double v3; // r9
  double v4; // r10
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // rdx
  double v7; // xmm2_8
  double v8; // xmm3_8
  unsigned int v9; // r8d
  double v10; // xmm4_8
  int v11; // edx
  unsigned int v12; // edx
  __int64 v13; // rcx
  double v14; // xmm1_8
  double v15; // xmm2_8
  double v16; // xmm0_8
  float arg1; // [rsp+30h] [rbp-28h]
  float arg2; // [rsp+38h] [rbp-20h]
  float v19; // [rsp+60h] [rbp+8h]

  v19 = x;
  v2 = x;
  v3 = fabs(x);
  v4 = fabs(y);
  v5 = (COERCE_UNSIGNED_INT64(x) >> 52) & 0x7FF;
  v6 = (COERCE_UNSIGNED_INT64(y) >> 52) & 0x7FF;
  if ( ((COERCE_UNSIGNED_INT64(x) >> 52) & 0x7FF) != 0 )
  {
    if ( ((COERCE_UNSIGNED_INT64(x) >> 52) & 0x7FF) == 2047 )
      goto LABEL_20;
    if ( (unsigned int)(v6 - 1) <= 0x7FD )
    {
      if ( *(_QWORD *)&v3 == *(_QWORD *)&v4 )
        return COERCE_DOUBLE(*(_QWORD *)&v2 & 0x8000000000000000ui64);
      v7 = v3;
      v8 = v4;
      if ( *(_QWORD *)&v3 >= *(_QWORD *)&v4 )
      {
        v9 = _mm_getcsr();
        if ( (int)v5 > (int)v6 )
        {
          v12 = (int)((unsigned __int64)(715827883i64 * ((int)v5 - (int)v6)) >> 32) >> 2;
          v11 = (v12 >> 31) + v12;
          v10 = 0.00000005960464477539062;
          v8 = COERCE_DOUBLE((__int64)(24 * v11 + 1023) << 52) * v4;
        }
        else
        {
          v10 = DOUBLE_1_0;
          v11 = 0;
        }
        if ( v11 > 0 )
        {
          v13 = (unsigned int)v11;
          do
          {
            v14 = (double)(int)(v7 / v8) * v8;
            v8 = v8 * v10;
            v7 = v7 - v14;
            --v13;
          }
          while ( v13 );
        }
        v15 = v7 - (double)(int)(v7 / v8) * v8;
        _mm_setcsr(v9);
        v16 = v15;
        if ( v19 < 0.0 )
          return -v15;
        return v16;
      }
      else
      {
        if ( x < 0.0 )
          return -v3;
        return v7;
      }
    }
  }
  if ( ((COERCE_UNSIGNED_INT64(x) >> 52) & 0x7FF) == 2047 )
  {
LABEL_20:
    arg2 = y;
    arg1 = x;
    if ( (*(_QWORD *)&v2 & 0xFFFFFFFFFFFFFi64) != 0 )
      return handle_errorf("fmodf", 22, LODWORD(x) | 0x400000i64, 1, 0, 33, x, y, 2);
    return handle_errorf("fmodf", 22, 0xFFC00000ui64, 1, 8, 33, arg1, arg2, 2);
  }
  if ( ((COERCE_UNSIGNED_INT64(y) >> 52) & 0x7FF) != 2047 )
  {
    if ( ((COERCE_UNSIGNED_INT64(x) >> 52) & 0x7FF) == 0 && ((COERCE_UNSIGNED_INT64(y) >> 52) & 0x7FF) != 0 )
      return x;
    arg2 = y;
    arg1 = x;
    return handle_errorf("fmodf", 22, 0xFFC00000ui64, 1, 8, 33, arg1, arg2, 2);
  }
  if ( (COERCE_UNSIGNED_INT64(y) & 0xFFFFFFFFFFFFFi64) != 0 )
    return handle_errorf("fmodf", 22, LODWORD(y) | 0x400000i64, 1, 0, 33, x, y, 2);
  return x;
}


// File Line: 28
// RVA: 0x12B5D0C
long double __fastcall atan2(long double result, long double x)
{
  unsigned __int64 v2; // rbx
  long double v3; // r15
  double v4; // xmm9_8
  double v5; // xmm8_8
  unsigned __int64 v6; // rcx
  signed __int64 v7; // r12
  unsigned __int64 v8; // rbp
  unsigned __int64 v9; // rsi
  BOOL v10; // er9
  BOOL v11; // er8
  signed int v12; // edi
  signed __int64 v13; // r8
  double v14; // xmm6_8
  double v15; // xmm0_8
  signed __int64 v16; // xmm0_8
  double v17; // xmm0_8
  unsigned __int64 v18; // rax
  signed __int64 v19; // xmm0_8
  double v20; // xmm0_8
  unsigned __int64 v21; // rdi
  unsigned __int64 v22; // rcx
  int v23; // ecx
  double v24; // rbx
  int v25; // er10
  double v26; // xmm0_8
  double v27; // xmm5_8
  __int64 v28; // rcx
  double v29; // xmm10_8
  int v30; // er9
  __int64 v31; // r8
  double v32; // xmm6_8
  double v33; // xmm5_8
  double v34; // xmm4_8
  double v35; // xmm3_8
  double v36; // xmm10_8

  v2 = 0i64;
  v3 = result;
  v4 = x;
  v5 = result;
  v6 = *(_QWORD *)&result & 0x7FFFFFFFFFFFFFFFi64;
  v7 = (*(_QWORD *)&x >> 52) & 0x7FFi64;
  v8 = *(_QWORD *)&x & 0x8000000000000000ui64;
  v9 = *(_QWORD *)&result & 0x8000000000000000ui64;
  v10 = (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64) == 9218868437227405312i64;
  v11 = (*(_QWORD *)&result & 0x7FFFFFFFFFFFFFFFi64) == 9218868437227405312i64;
  v12 = ((*(_QWORD *)&result >> 52) & 0x7FF) - v7;
  if ( (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFui64) > 0x7FF0000000000000i64 )
  {
    v13 = *(_QWORD *)&x | 0x8000000000000i64;
    return handle_error("atan2", 16, v13, 1, 0, 33, x, result, 2);
  }
  if ( v6 > 0x7FF0000000000000i64 )
  {
    v13 = *(_QWORD *)&result | 0x8000000000000i64;
    return handle_error("atan2", 16, v13, 1, 0, 33, x, result, 2);
  }
  if ( !v6 )
  {
    if ( !v8 )
      return result;
    goto LABEL_8;
  }
  if ( (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64) == 0 )
  {
    if ( v9 )
    {
LABEL_12:
      v15 = piby2_11;
LABEL_13:
      v14 = -v15;
LABEL_33:
      v22 = 32i64;
LABEL_34:
      set_statfp(v22);
      return v14;
    }
    set_statfp(0x20ui64);
    v11 = (*(_QWORD *)&result & 0x7FFFFFFFFFFFFFFFi64) == 9218868437227405312i64;
    v10 = (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64) == 9218868437227405312i64;
  }
  if ( (signed int)v7 < 1021 && (signed int)((*(_QWORD *)&result >> 52) & 0x7FF) < 1021 )
  {
    if ( *(_QWORD *)&x & 0x7FF0000000000000i64 )
    {
      v18 = *(_QWORD *)&x + 0x4000000000000000i64;
    }
    else
    {
      v16 = *(_QWORD *)&x | 0x4010000000000000i64;
      if ( v8 )
        v17 = *(double *)&v16 + 4.0;
      else
        v17 = *(double *)&v16 - 4.0;
      *(double *)&v18 = v17;
    }
    if ( *(_QWORD *)&v3 & 0x7FF0000000000000i64 )
    {
      v21 = *(_QWORD *)&v3 + 0x4000000000000000i64;
    }
    else
    {
      v19 = *(_QWORD *)&v3 | 0x4010000000000000i64;
      if ( v9 )
        v20 = *(double *)&v19 + 4.0;
      else
        v20 = *(double *)&v19 - 4.0;
      *(double *)&v21 = v20;
    }
    v4 = *(double *)&v18;
    v5 = *(double *)&v21;
    v12 = ((v21 >> 52) & 0x7FF) - ((v18 >> 52) & 0x7FF);
  }
  if ( v12 > 56 )
  {
    if ( !v9 )
    {
      v14 = piby2_11;
      goto LABEL_33;
    }
    goto LABEL_12;
  }
  if ( v12 >= -28 || v8 )
  {
    if ( v12 < -56 && v8 )
    {
LABEL_8:
      v14 = pi_3;
      if ( v9 )
        v14 = -pi_3;
      goto LABEL_33;
    }
    if ( v11 && v10 )
    {
      if ( v8 )
      {
        if ( !v9 )
        {
          v14 = three_piby4_0;
          goto LABEL_33;
        }
        v15 = three_piby4_0;
      }
      else
      {
        if ( !v9 )
        {
          v14 = piby4_0;
          goto LABEL_33;
        }
        v15 = piby4_0;
      }
      goto LABEL_13;
    }
    if ( v8 )
      v4 = -v4;
    if ( v9 )
      v5 = -v5;
    v25 = 0;
    LOBYTE(v25) = v5 > v4;
    if ( v5 > v4 )
    {
      v26 = v4;
      v4 = v5;
      v5 = v26;
    }
    v27 = v5 / v4;
    if ( v5 / v4 <= 0.0625 )
    {
      v29 = 0.0;
      if ( v27 >= 0.00000001 )
        v27 = (v5
             - COERCE_DOUBLE(*(_QWORD *)&v27 & 0xFFFFFFFF00000000ui64)
             * COERCE_DOUBLE(*(_QWORD *)&v4 & 0xFFFFFFFF00000000ui64)
             - (v4 - COERCE_DOUBLE(*(_QWORD *)&v4 & 0xFFFFFFFF00000000ui64))
             * COERCE_DOUBLE(*(_QWORD *)&v27 & 0xFFFFFFFF00000000ui64)
             - (v27 - COERCE_DOUBLE(*(_QWORD *)&v27 & 0xFFFFFFFF00000000ui64)) * v4)
            / v4
            - (0.3333333333333317
             - (0.1999999999939322
              - (0.1428571356180717 - (0.1111073628351453 - v27 * v27 * 0.09002981028544979) * (v27 * v27))
              * (v27
               * v27))
             * (v27
              * v27))
            * (v27
             * v27
             * v27)
            + v27;
    }
    else
    {
      v28 = (unsigned int)((signed int)(v27 * 256.0 + 0.5) - 16);
      v29 = atan_jby256_lead[v28];
      v30 = (*(_QWORD *)&v4 >> 52) & 0x7FF;
      v31 = (1023 - v30) / 2;
      v32 = (double)(signed int)(v27 * 256.0 + 0.5) * 0.00390625;
      v33 = COERCE_DOUBLE((v31 + 1023) << 52) * v4 * COERCE_DOUBLE((1023 - v30 - (signed int)v31 + 1023i64) << 52);
      v34 = COERCE_DOUBLE((v31 + 1023) << 52) * v5 * COERCE_DOUBLE((1023 - v30 - (signed int)v31 + 1023i64) << 52);
      v35 = (v34
           - COERCE_DOUBLE(*(_QWORD *)&v33 & 0xFFFFFFFFF8000000ui64) * v32
           - (v33 - COERCE_DOUBLE(*(_QWORD *)&v33 & 0xFFFFFFFFF8000000ui64)) * v32)
          / (v32 * v34 + v33);
      v27 = v35 + atan_jby256_tail[v28] - (0.333333333332241 - v35 * v35 * 0.1999991803898914) * (v35 * v35) * v35;
    }
    if ( v25 )
    {
      v29 = piby2_head_1 - v29;
      v27 = piby2_tail_3 - v27;
    }
    if ( v8 )
    {
      v29 = pi_head - v29;
      v27 = pi_tail - v27;
    }
    v36 = v29 + v27;
    if ( v9 )
      v36 = -v36;
    result = v36;
  }
  else
  {
    if ( v12 < -1074 )
    {
      if ( v9 )
        v14 = DOUBLE_N0_0;
      else
        v14 = 0.0;
LABEL_47:
      v22 = 48i64;
      goto LABEL_34;
    }
    if ( v12 >= -1022 )
    {
      result = v5 / v4;
    }
    else
    {
      v23 = (((COERCE_UNSIGNED_INT64(1.267650600228229e30 * v5 / v4) & 0x7FFFFFFFFFFFFFFFi64) >> 52) & 0x7FF) - 100;
      if ( v23 <= 0 )
      {
        if ( 1 - v23 <= 54 )
          v2 = (((COERCE_UNSIGNED_INT64(1.267650600228229e30 * v5 / v4) & 0x1FFFFFFFFFFFFFi64 | 0x10000000000000i64) >> (100 - (unsigned __int8)((COERCE_UNSIGNED_INT64(1.267650600228229e30 * v5 / v4) & 0x7FFFFFFFFFFFFFFFi64) >> 52))) & 1)
             + ((COERCE_UNSIGNED_INT64(1.267650600228229e30 * v5 / v4) & 0x1FFFFFFFFFFFFFi64 | 0x10000000000000i64) >> (100 - (unsigned __int8)((COERCE_UNSIGNED_INT64(1.267650600228229e30 * v5 / v4) & 0x7FFFFFFFFFFFFFFFi64) >> 52)) >> 1);
      }
      else
      {
        v2 = COERCE_UNSIGNED_INT64(1.267650600228229e30 * v5 / v4) & 0xFFFFFFFFFFFFFi64 | ((signed __int64)v23 << 52);
      }
      *(_QWORD *)&v24 = COERCE_UNSIGNED_INT64(1.267650600228229e30 * v5 / v4) & 0x8000000000000000ui64 | v2;
      v14 = v24;
      if ( !(*(_QWORD *)&v24 & 0x7FF0000000000000i64) )
        goto LABEL_47;
      result = v24;
    }
  }
  return result;
}


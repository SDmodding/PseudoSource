// File Line: 28
// RVA: 0x12B5D0C
double __fastcall atan2(double y, long double x)
{
  unsigned __int64 v2; // rbx
  long double v3; // r15
  double v4; // xmm9_8
  double v5; // xmm8_8
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rbp
  unsigned __int64 v8; // rsi
  BOOL v9; // r9d
  BOOL v10; // r8d
  int v11; // edi
  __int64 v12; // r8
  double v13; // xmm6_8
  double v14; // xmm0_8
  __int64 v15; // xmm0_8
  double v16; // xmm0_8
  unsigned __int64 v17; // rax
  __int64 v18; // xmm0_8
  double v19; // xmm0_8
  double v20; // rdi
  unsigned __int64 v21; // rcx
  double v22; // rax
  int v23; // ecx
  unsigned __int64 v24; // rax
  double v25; // rbx
  int v26; // r10d
  double v27; // xmm0_8
  double v28; // xmm5_8
  __int64 v29; // rcx
  double v30; // xmm10_8
  int v31; // kr00_4
  __int64 v32; // r8
  double v33; // xmm6_8
  double v34; // xmm5_8
  double v35; // xmm4_8
  double v36; // xmm3_8
  double v37; // xmm10_8

  v2 = 0i64;
  v3 = y;
  v4 = x;
  v5 = y;
  v6 = *(_QWORD *)&y & 0x7FFFFFFFFFFFFFFFi64;
  v7 = *(_QWORD *)&x & 0x8000000000000000ui64;
  v8 = *(_QWORD *)&y & 0x8000000000000000ui64;
  v9 = (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64) == 0x7FF0000000000000i64;
  v10 = (*(_QWORD *)&y & 0x7FFFFFFFFFFFFFFFi64) == 0x7FF0000000000000i64;
  v11 = ((*(_QWORD *)&y >> 52) & 0x7FF) - ((*(_QWORD *)&x >> 52) & 0x7FF);
  if ( (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFui64) > 0x7FF0000000000000i64 )
  {
    v12 = *(_QWORD *)&x | 0x8000000000000i64;
    return handle_error("atan2", 16, v12, 1, 0, 33, x, y, 2);
  }
  if ( v6 > 0x7FF0000000000000i64 )
  {
    v12 = *(_QWORD *)&y | 0x8000000000000i64;
    return handle_error("atan2", 16, v12, 1, 0, 33, x, y, 2);
  }
  if ( !v6 )
  {
    if ( !v7 )
      return y;
    goto LABEL_8;
  }
  if ( (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64) == 0 )
  {
    if ( v8 )
    {
LABEL_12:
      v14 = piby2_11;
LABEL_13:
      v13 = -v14;
LABEL_33:
      v21 = 32i64;
LABEL_34:
      set_statfp(v21);
      return v13;
    }
    set_statfp(0x20ui64);
    v10 = (*(_QWORD *)&y & 0x7FFFFFFFFFFFFFFFi64) == 0x7FF0000000000000i64;
    v9 = (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64) == 0x7FF0000000000000i64;
  }
  if ( ((unsigned __int16)(*(_QWORD *)&x >> 52) & 0x7FFu) < 0x3FD
    && ((unsigned __int16)(*(_QWORD *)&y >> 52) & 0x7FFu) < 0x3FD )
  {
    if ( (*(_QWORD *)&x & 0x7FF0000000000000i64) != 0 )
    {
      v17 = *(_QWORD *)&x + 0x4000000000000000i64;
    }
    else
    {
      v15 = *(_QWORD *)&x | 0x4010000000000000i64;
      if ( v7 )
        v16 = *(double *)&v15 + 4.0;
      else
        v16 = *(double *)&v15 - 4.0;
      *(double *)&v17 = v16;
    }
    if ( (*(_QWORD *)&v3 & 0x7FF0000000000000i64) != 0 )
    {
      *(_QWORD *)&v20 = *(_QWORD *)&v3 + 0x4000000000000000i64;
    }
    else
    {
      v18 = *(_QWORD *)&v3 | 0x4010000000000000i64;
      if ( v8 )
        v19 = *(double *)&v18 + 4.0;
      else
        v19 = *(double *)&v18 - 4.0;
      v20 = v19;
    }
    v4 = *(double *)&v17;
    v5 = v20;
    v11 = ((*(_QWORD *)&v20 >> 52) & 0x7FF) - ((v17 >> 52) & 0x7FF);
  }
  if ( v11 > 56 )
  {
    if ( !v8 )
    {
      v13 = piby2_11;
      goto LABEL_33;
    }
    goto LABEL_12;
  }
  if ( v11 >= -28 || v7 )
  {
    if ( v11 < -56 && v7 )
    {
LABEL_8:
      v13 = pi_3;
      if ( v8 )
        v13 = -pi_3;
      goto LABEL_33;
    }
    if ( v10 && v9 )
    {
      if ( v7 )
      {
        if ( !v8 )
        {
          v13 = three_piby4_0;
          goto LABEL_33;
        }
        v14 = three_piby4_0;
      }
      else
      {
        if ( !v8 )
        {
          v13 = piby4_0;
          goto LABEL_33;
        }
        v14 = piby4_0;
      }
      goto LABEL_13;
    }
    if ( v7 )
      v4 = -v4;
    if ( v8 )
      v5 = -v5;
    v26 = 0;
    LOBYTE(v26) = v5 > v4;
    if ( v5 > v4 )
    {
      v27 = v4;
      v4 = v5;
      v5 = v27;
    }
    v28 = v5 / v4;
    if ( v5 / v4 <= 0.0625 )
    {
      v30 = 0.0;
      if ( v28 >= 0.00000001 )
        v28 = (v5
             - COERCE_DOUBLE(*(_QWORD *)&v28 & 0xFFFFFFFF00000000ui64)
             * COERCE_DOUBLE(*(_QWORD *)&v4 & 0xFFFFFFFF00000000ui64)
             - (v4 - COERCE_DOUBLE(*(_QWORD *)&v4 & 0xFFFFFFFF00000000ui64))
             * COERCE_DOUBLE(*(_QWORD *)&v28 & 0xFFFFFFFF00000000ui64)
             - (v28 - COERCE_DOUBLE(*(_QWORD *)&v28 & 0xFFFFFFFF00000000ui64)) * v4)
            / v4
            - (0.3333333333333317
             - (0.1999999999939322
              - (0.1428571356180717 - (0.1111073628351453 - v28 * v28 * 0.09002981028544979) * (v28 * v28))
              * (v28
               * v28))
             * (v28
              * v28))
            * (v28
             * v28
             * v28)
            + v28;
    }
    else
    {
      v29 = (unsigned int)((int)(v28 * 256.0 + 0.5) - 16);
      v30 = atan_jby256_lead[v29];
      v31 = 1023 - ((*(_QWORD *)&v4 >> 52) & 0x7FF);
      v32 = v31 / 2;
      v33 = (double)(int)(v28 * 256.0 + 0.5) * 0.00390625;
      v34 = COERCE_DOUBLE((v32 + 1023) << 52) * v4 * COERCE_DOUBLE((v31 - (int)v32 + 1023i64) << 52);
      v35 = COERCE_DOUBLE((v32 + 1023) << 52) * v5 * COERCE_DOUBLE((v31 - (int)v32 + 1023i64) << 52);
      v36 = (v35
           - COERCE_DOUBLE(*(_QWORD *)&v34 & 0xFFFFFFFFF8000000ui64) * v33
           - (v34 - COERCE_DOUBLE(*(_QWORD *)&v34 & 0xFFFFFFFFF8000000ui64)) * v33)
          / (v33 * v35 + v34);
      v28 = v36 + atan_jby256_tail[v29] - (0.333333333332241 - v36 * v36 * 0.1999991803898914) * (v36 * v36) * v36;
    }
    if ( v26 )
    {
      v30 = piby2_head_1 - v30;
      v28 = piby2_tail_3 - v28;
    }
    if ( v7 )
    {
      v30 = pi_head - v30;
      v28 = pi_tail - v28;
    }
    v37 = v30 + v28;
    if ( v8 )
      return -v37;
    return v37;
  }
  else
  {
    if ( v11 < -1074 )
    {
      if ( v8 )
        v13 = DOUBLE_N0_0;
      else
        v13 = 0.0;
LABEL_47:
      v21 = 48i64;
      goto LABEL_34;
    }
    if ( v11 >= -1022 )
    {
      return v5 / v4;
    }
    else
    {
      v22 = fabs(1.267650600228229e30 * v5 / v4);
      v23 = ((*(_QWORD *)&v22 >> 52) & 0x7FF) - 100;
      if ( v23 <= 0 )
      {
        v24 = *(_QWORD *)&v22 & 0x800FFFFFFFFFFFFFui64 | 0x10000000000000i64;
        if ( 1 - v23 <= 54 )
          v2 = ((v24 >> -(char)v23) & 1) + (v24 >> -(char)v23 >> 1);
      }
      else
      {
        v2 = *(_QWORD *)&v22 & 0x800FFFFFFFFFFFFFui64 | ((__int64)v23 << 52);
      }
      *(_QWORD *)&v25 = COERCE_UNSIGNED_INT64(1.267650600228229e30 * v5 / v4) & 0x8000000000000000ui64 | v2;
      v13 = v25;
      if ( (*(_QWORD *)&v25 & 0x7FF0000000000000i64) == 0 )
        goto LABEL_47;
      return v25;
    }
  }
}


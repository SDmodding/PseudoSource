// File Line: 27
// RVA: 0x12AF888
float __fastcall atan2f(float fy, float fx)
{
  unsigned __int64 v2; // rbx
  double v3; // xmm6_8
  double v4; // xmm7_8
  unsigned __int64 v5; // rbp
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // rcx
  BOOL v9; // er15
  BOOL v10; // er12
  signed int v11; // er14
  float v13; // xmm6_4
  unsigned __int64 v14; // rcx
  double v15; // xmm0_8
  float v16; // xmm0_4
  double v17; // rax
  double v18; // r8
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // r8
  int v21; // ecx
  unsigned __int64 v22; // rax
  int v23; // edx
  double v24; // xmm0_8
  double v25; // xmm4_8
  signed int v26; // eax
  double v27; // xmm3_8
  double v28; // xmm0_8
  float v29; // [rsp+B0h] [rbp+8h]

  v2 = 0i64;
  v3 = fy;
  v4 = fx;
  v5 = *(unsigned __int64 *)&fx & 0x8000000000000000ui64;
  v6 = *(unsigned __int64 *)&fy & 0x7FFFFFFFFFFFFFFFi64;
  v7 = *(unsigned __int64 *)&fy & 0x8000000000000000ui64;
  v8 = *(unsigned __int64 *)&fx & 0x7FFFFFFFFFFFFFFFi64;
  v9 = v8 == 9218868437227405312i64;
  v10 = v6 == 9218868437227405312i64;
  v11 = ((*(unsigned __int64 *)&fy >> 52) & 0x7FF) - ((*(unsigned __int64 *)&fx >> 52) & 0x7FF);
  if ( v8 > 0x7FF0000000000000i64 )
  {
    v29 = fx;
    return handle_errorf("atan2f", 16, LODWORD(v29) | 0x400000i64, 1, 0, 33, fx, fy, 2);
  }
  if ( v6 > 0x7FF0000000000000i64 )
  {
    v29 = fy;
    return handle_errorf("atan2f", 16, LODWORD(v29) | 0x400000i64, 1, 0, 33, fx, fy, 2);
  }
  if ( !v6 )
  {
    if ( v5 )
    {
      if ( v7 )
        v13 = -pi_2;
      else
        v13 = pi_2;
      v14 = 32i64;
      goto LABEL_12;
    }
    return v3;
  }
  if ( (*(unsigned __int64 *)&fx & 0x7FFFFFFFFFFFFFFFi64) == 0 )
  {
    if ( v7 )
    {
      v15 = piby2_8;
LABEL_16:
      v13 = -v15;
LABEL_24:
      v14 = 32i64;
LABEL_12:
      set_statfp(v14);
      return v13;
    }
    set_statfp(0x20ui64);
  }
  if ( v11 > 26 )
  {
    v15 = piby2_8;
    goto LABEL_20;
  }
  if ( v11 < -13 && !v5 )
  {
    if ( v11 < -150 )
    {
      if ( v7 )
        v13 = FLOAT_N0_0;
      else
        v13 = 0.0;
      v14 = 48i64;
      goto LABEL_12;
    }
    if ( v11 >= -126 )
    {
      v3 = v3 / v4;
    }
    else
    {
      v17 = 1.267650600228229e30 * v3 / v4;
      v18 = v17;
      v19 = *(_QWORD *)&v17 & 0x7FFFFFFFFFFFFFFFi64;
      v20 = *(_QWORD *)&v18 & 0x8000000000000000ui64;
      v21 = ((v19 >> 52) & 0x7FF) - 100;
      if ( v21 <= 0 )
      {
        v22 = v19 & 0x801FFFFFFFFFFFFFui64 | 0x10000000000000i64;
        if ( 1 - v21 <= 54 )
          v2 = ((v22 >> -(char)v21) & 1) + (v22 >> -(char)v21 >> 1);
      }
      else
      {
        v2 = v19 & 0x800FFFFFFFFFFFFFui64 | ((signed __int64)v21 << 52);
      }
      *(_QWORD *)&v3 = v20 | v2;
      if ( !((v20 | v2) & 0x7FF0000000000000i64) )
        set_statfp(0x30ui64);
    }
    return v3;
  }
  if ( v11 < -26 && v5 )
  {
    v15 = pi_2;
    if ( v7 )
      goto LABEL_16;
    goto LABEL_22;
  }
  if ( v10 && v9 )
  {
    if ( v5 )
      v15 = three_piby4;
    else
      v15 = piby4;
LABEL_20:
    if ( v7 )
    {
      v16 = -v15;
LABEL_23:
      v13 = v16;
      goto LABEL_24;
    }
LABEL_22:
    v16 = v15;
    goto LABEL_23;
  }
  if ( v5 )
    *(_QWORD *)&v4 ^= _xmm[0];
  if ( v7 )
    *(_QWORD *)&v3 ^= _xmm[0];
  v23 = 0;
  LOBYTE(v23) = v3 > v4;
  if ( v3 > v4 )
  {
    v24 = v4;
    v4 = v3;
    v3 = v24;
  }
  v25 = v3 / v4;
  if ( v3 / v4 > 0.0625 )
  {
    v26 = (signed int)(v25 * 256.0 + 0.5);
    v27 = (v3 * 256.0 - (double)v26 * v4) / ((double)v26 * v3 + v4 * 256.0);
    v25 = v27 + atan_jby256[v26 - 16];
    v28 = v27 * v27 * v27 * 0.333333333332241;
LABEL_60:
    v25 = v25 - v28;
    goto LABEL_61;
  }
  if ( v25 >= 0.0001 )
  {
    v28 = (0.3333333333333317 - (0.1999999999939322 - v25 * v25 * 0.1428571356180717) * (v25 * v25)) * (v25 * v25 * v25);
    goto LABEL_60;
  }
LABEL_61:
  if ( v23 )
    v25 = piby2_8 - v25;
  if ( v5 )
    v25 = pi_2 - v25;
  if ( v7 )
    *(_QWORD *)&v25 ^= _xmm[0];
  return v25;
} v25);
    goto LABEL_60;
  }
LABEL_61:
  if ( v23 )
    v25 = piby2_8 - v25;
  if ( v5 )


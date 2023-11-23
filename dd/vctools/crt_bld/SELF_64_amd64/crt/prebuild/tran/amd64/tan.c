// File Line: 19
// RVA: 0x12B870C
double __fastcall tan_piby4(double x, double xx, int recip)
{
  int v3; // eax
  double v4; // xmm3_8
  double v5; // xmm6_8
  double v6; // xmm2_8
  double v7; // xmm5_8
  double v8; // xmm5_8
  double v9; // xmm0_8

  v3 = 0;
  v4 = xx;
  v5 = x;
  if ( x <= 0.68 )
  {
    if ( x >= -0.68 )
      goto LABEL_6;
    v3 = -1;
    v5 = x + 0.7853981633974483 + xx + 3.061616997868382e-17;
  }
  else
  {
    v3 = 1;
    v5 = 0.7853981633974483 - x + 3.061616997868382e-17 - xx;
  }
  v4 = 0.0;
LABEL_6:
  v6 = v5 * 2.0 * v4 + v5 * v5;
  v7 = ((v6 * 0.0002240444485370221 - 0.02293450800575656) * v6 + 0.3723791597597922)
     * (v6
      * v5)
     / (((0.02606566203986454 - v6 * 0.0002323714940885636) * v6 - 0.5156585157290311) * v6 + 1.117137479279377)
     + v4;
  if ( v3 )
  {
    v8 = v7 + v5;
    if ( recip )
      v9 = v8 * 2.0 / (v8 - 1.0) - 1.0;
    else
      v9 = 1.0 - v8 * 2.0 / (v8 + 1.0);
    return v9 * (double)v3;
  }
  else if ( recip )
  {
    return (COERCE_DOUBLE(COERCE_UNSIGNED_INT64(-1.0 / (v7 + v5)) & 0xFFFFFFFF00000000ui64)
          * COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v7 + v5) & 0xFFFFFFFF00000000ui64)
          + 1.0
          + (v7 - (COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v7 + v5) & 0xFFFFFFFF00000000ui64) - v5))
          * COERCE_DOUBLE(COERCE_UNSIGNED_INT64(-1.0 / (v7 + v5)) & 0xFFFFFFFF00000000ui64))
         * (-1.0
          / (v7 + v5))
         + COERCE_DOUBLE(COERCE_UNSIGNED_INT64(-1.0 / (v7 + v5)) & 0xFFFFFFFF00000000ui64);
  }
  else
  {
    return v7 + v5;
  }
}

// File Line: 97
// RVA: 0x12B8440
long double __fastcall tan(long double x)
{
  long double v1; // xmm6_8
  unsigned __int64 v2; // rcx
  int v3; // r8d
  long double v4; // xmm1_8
  BOOL v5; // ebx
  int v6; // r8d
  double v7; // xmm3_8
  double v8; // xmm2_8
  double v9; // xmm6_8
  unsigned __int64 v10; // rdx
  double v11; // xmm1_8
  double v12; // xmm1_8
  int v13; // r8d
  double v14; // xmm6_8
  int region; // [rsp+70h] [rbp+8h] BYREF
  long double r; // [rsp+78h] [rbp+10h] BYREF
  long double rr; // [rsp+80h] [rbp+18h] BYREF
  long double v18; // [rsp+88h] [rbp+20h]

  v18 = x;
  v1 = x;
  v2 = *(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64;
  if ( (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFui64) <= 0x3FE921FB54442D18i64 )
  {
    if ( v2 < 0x3F20000000000000i64 )
    {
      if ( v2 >= 0x3E40000000000000i64 )
        return x * x * x * 0.3333333333333333 + x;
      if ( v2 )
        set_statfp(0x20ui64);
      return x;
    }
    v3 = 0;
    v4 = 0.0;
    return tan_piby4(x, v4, v3);
  }
  if ( (*(_QWORD *)&x & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 )
  {
    v5 = v2 != *(_QWORD *)&x;
    if ( v2 != *(_QWORD *)&x )
      v1 = -x;
    if ( v1 >= 500000.0 )
    {
      _remainder_piby2(v1, &r, &rr, &region);
      LOBYTE(v13) = region;
      x = r;
      v14 = rr;
    }
    else
    {
      if ( v2 > 0x400F6A7A2955385Ei64 )
      {
        if ( v2 > 0x401C463ABECCB2BBi64 )
          v6 = (int)(v1 * 0.6366197723675814 + 0.5);
        else
          v6 = (v2 > 0x4015FDBBE9BBA775i64) + 3;
      }
      else
      {
        v6 = (v2 > 0x4002D97C7F3321D2i64) + 1;
      }
      v7 = (double)v6;
      v8 = (double)v6 * 6.077100506506192e-11;
      v9 = v1 - (double)v6 * 1.570796326734126;
      v18 = v9;
      v10 = (v2 >> 52) - ((*(_QWORD *)&v9 >> 52) & 0x7FFi64);
      if ( v10 > 0xF )
      {
        v11 = v9;
        v9 = v9 - v7 * 6.077100506303966e-11;
        v8 = v7 * 2.022266248795951e-21 - (v11 - v9 - v7 * 6.077100506303966e-11);
        if ( v10 > 0x30 )
        {
          v12 = v9;
          v9 = v9 - v7 * 2.022266248711166e-21;
          v8 = v7 * 8.4784276603689e-32 - (v12 - v9 - v7 * 2.022266248711166e-21);
        }
      }
      v13 = v6 & 3;
      x = v9 - v8;
      region = v13;
      r = v9 - v8;
      v14 = v9 - (v9 - v8) - v8;
      rr = v14;
    }
    v3 = v13 & 1;
    v4 = v14;
    if ( v5 )
      return -tan_piby4(x, v14, v3);
    return tan_piby4(x, v4, v3);
  }
  if ( (*(_QWORD *)&x & 0xFFFFFFFFFFFFFi64) != 0 )
    return handle_error("tan", 32, *(_QWORD *)&x | 0x8000000000000i64, 1, 0, 33, x, 0.0, 1);
  else
    return handle_error("tan", 32, 0xFFF8000000000000ui64, 1, 8, 33, x, 0.0, 1);
}


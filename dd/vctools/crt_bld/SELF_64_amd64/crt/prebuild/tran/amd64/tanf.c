// File Line: 48
// RVA: 0x12AF440
float __fastcall tanf(float result)
{
  double v1; // xmm3_8
  double v2; // rbx
  unsigned __int64 v3; // rcx
  double v4; // xmm0_8
  double v5; // xmm4_8
  __int64 v6; // xmm5_8
  __int64 v7; // rbx
  int v8; // edx
  double v9; // xmm4_8
  double v10; // xmm2_8
  double v11; // xmm3_8
  unsigned __int64 v12; // r8
  double v13; // xmm1_8
  double v14; // xmm1_8
  double v15; // xmm3_8
  char v16; // dl
  double v17; // xmm4_8
  double v18; // xmm0_8
  int region; // [rsp+78h] [rbp+10h]
  double v20; // [rsp+80h] [rbp+18h]
  long double r; // [rsp+88h] [rbp+20h]

  v1 = result;
  v20 = result;
  v2 = result;
  v3 = *(unsigned __int64 *)&result & 0x7FFFFFFFFFFFFFFFi64;
  if ( v3 <= 0x3FE921FB54442D18i64 )
  {
    if ( v3 >= 0x3F80000000000000i64 )
    {
      v5 = result;
      return (0.3852960712639954 - v5 * v5 * 0.01720324804714817)
           * (v5
            * (v5
             * v5))
           / ((v5 * v5 * 0.01844239256901656 - 0.5139650547885454) * (v5 * v5) + 1.155888214346884)
           + v5;
    }
    if ( v3 < 0x3F20000000000000i64 )
    {
      if ( v3 )
        set_statfp(0x20ui64);
      return result;
    }
    return v1 * v1 * v1 * 0.3333333333333333 + v1;
  }
  if ( (*(_QWORD *)&v2 & 0x7FF0000000000000i64) != 9218868437227405312i64 )
  {
    v6 = _xmm[0];
    v7 = *(_QWORD *)&v2 >> 63;
    if ( (_DWORD)v7 )
      *(_QWORD *)&v1 ^= _xmm[0];
    if ( v1 >= 500000.0 )
    {
      _remainder_piby2f_inline(v3, &r, &region);
      v16 = region;
      v15 = r;
    }
    else
    {
      if ( v3 > 0x400F6A7A2955385Ei64 )
      {
        if ( v3 > 0x401C463ABECCB2BBi64 )
          v8 = (signed int)(v1 * 0.6366197723675814 + 0.5);
        else
          v8 = (v3 > 0x4015FDBBE9BBA775i64) + 3;
      }
      else
      {
        v8 = (v3 > 0x4002D97C7F3321D2i64) + 1;
      }
      v9 = (double)v8;
      v10 = (double)v8 * 6.077100506506192e-11;
      v11 = v1 - (double)v8 * 1.570796326734126;
      v20 = v11;
      v12 = (v3 >> 52) - ((*(_QWORD *)&v11 >> 52) & 0x7FFi64);
      if ( v12 > 0xF )
      {
        v13 = v11;
        v11 = v11 - v9 * 6.077100506303966e-11;
        v10 = v9 * 2.022266248795951e-21 - (v13 - v11 - v9 * 6.077100506303966e-11);
        if ( v12 > 0x30 )
        {
          v14 = v11;
          v11 = v11 - v9 * 2.022266248711166e-21;
          v10 = v9 * 8.4784276603689e-32 - (v14 - v11 - v9 * 2.022266248711166e-21);
        }
      }
      v15 = v11 - v10;
      v16 = v8 & 3;
    }
    v17 = (0.3852960712639954 - v15 * v15 * 0.01720324804714817)
        * (v15
         * v15
         * v15)
        / ((v15 * v15 * 0.01844239256901656 - 0.5139650547885454) * (v15 * v15) + 1.155888214346884)
        + v15;
    if ( (_DWORD)v7 )
    {
      if ( v16 & 1 )
        v18 = -1.0 / v17;
      else
        v18 = (0.3852960712639954 - v15 * v15 * 0.01720324804714817)
            * (v15
             * v15
             * v15)
            / ((v15 * v15 * 0.01844239256901656 - 0.5139650547885454) * (v15 * v15) + 1.155888214346884)
            + v15;
      *(_QWORD *)&v4 = *(_QWORD *)&v18 ^ v6;
    }
    else if ( v16 & 1 )
    {
      v4 = -1.0 / v17;
    }
    else
    {
      v4 = (0.3852960712639954 - v15 * v15 * 0.01720324804714817)
         * (v15
          * v15
          * v15)
         / ((v15 * v15 * 0.01844239256901656 - 0.5139650547885454) * (v15 * v15) + 1.155888214346884)
         + v15;
    }
    return v4;
  }
  if ( *(_QWORD *)&v2 & 0xFFFFFFFFFFFFFi64 )
    result = handle_errorf("tanf", 32, LODWORD(result) | 0x400000i64, 1, 0, 33, result, 0.0, 1);
  else
    result = handle_errorf("tanf", 32, 0xFFC00000ui64, 1, 8, 33, result, 0.0, 1);
  return result;
}


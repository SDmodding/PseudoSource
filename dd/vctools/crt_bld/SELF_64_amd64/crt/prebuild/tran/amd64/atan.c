// File Line: 19
// RVA: 0x12B5AAC
double __fastcall atan(long double x)
{
  double v1; // xmm1_8
  unsigned __int64 v2; // rax
  double v4; // xmm6_8
  double v5; // xmm5_8
  double v6; // xmm6_8
  double v7; // xmm4_8
  double v8; // xmm5_8

  v1 = x;
  v2 = *(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64;
  if ( *(_QWORD *)&x != (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64) )
    v1 = -x;
  if ( v2 <= 0x4003800000000000i64 )
  {
    v7 = v1;
    if ( v2 <= 0x3FF3000000000000i64 )
    {
      if ( v2 <= 0x3FE6000000000000i64 )
      {
        if ( v2 <= 0x3FDC000000000000i64 )
        {
          v5 = 0.0;
          v6 = 0.0;
        }
        else
        {
          v5 = DOUBLE_0_4636476090008061;
          v6 = DOUBLE_2_269877745296168eN17;
          v7 = (v1 * 2.0 - 1.0) / (v1 + 2.0);
        }
      }
      else
      {
        v5 = DOUBLE_0_7853981633974483;
        v7 = (v1 - 1.0) / (v1 + 1.0);
        v6 = DOUBLE_3_061616997868382eN17;
      }
    }
    else
    {
      v5 = DOUBLE_0_9827937232473291;
      v6 = DOUBLE_1_3903311031231eN17;
      v7 = (v1 - 1.5) / (v1 * 1.5 + 1.0);
    }
  }
  else
  {
    if ( v2 > 0x7FF0000000000000i64 )
      return handle_error("atan", 15, *(_QWORD *)&x | 0x8000000000000i64, 1, 0, 33, x, 0.0, 1);
    if ( v1 > 4.859383997932765e18 )
    {
      v4 = piby2_10;
      if ( *(_QWORD *)&x != (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64) )
        v4 = -piby2_10;
      set_statfp(0x20ui64);
      return v4;
    }
    v5 = DOUBLE_1_570796326794897;
    v6 = DOUBLE_6_123233995736765eN17;
    v7 = -1.0 / v1;
  }
  v8 = v5
     - (((((v7 * v7 * 0.0001423169033423178 + 0.0304455919504853) * (v7 * v7) + 0.2206387807166674) * (v7 * v7)
        + 0.4476772068054975)
       * (v7
        * v7)
       + 0.2682979205325459)
      * (v7
       * v7
       * v7)
      / ((((v7 * v7 * 0.03895258739447422 + 0.4246025942038471) * (v7 * v7) + 1.412542599319589) * (v7 * v7)
        + 1.825967877375071)
       * (v7
        * v7)
       + 0.8048937615976377)
      - v6
      - v7);
  if ( *(_QWORD *)&x != (*(_QWORD *)&x & 0x7FFFFFFFFFFFFFFFi64) )
    return -v8;
  return v8;
}


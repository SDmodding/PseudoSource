// File Line: 23
// RVA: 0x12B07D8
float __fastcall atanf(float fx)
{
  double v1; // xmm4_8
  unsigned __int64 v2; // rax
  unsigned __int64 v3; // rcx
  double v4; // xmm5_8
  float v6; // xmm6_4
  double v7; // xmm5_8

  v1 = fx;
  v2 = *(unsigned __int64 *)&fx & 0x7FFFFFFFFFFFFFFFi64;
  v3 = *(unsigned __int64 *)&fx & 0x8000000000000000ui64;
  if ( *(signed __int64 *)&fx < 0 )
    *(_QWORD *)&v1 ^= _xmm[0];
  if ( v2 < 0x3FDC000000000000i64 )
  {
    v4 = 0.0;
LABEL_19:
    v7 = v4
       - (((v1 * v1 * 0.004706779342861492 + 0.1923245464021086) * (v1 * v1) + 0.2965285988192392)
        * (v1
         * v1
         * v1)
        / ((v1 * v1 * 0.2993096999596597 + 1.110724999953995) * (v1 * v1) + 0.8895857968624323)
        - v1);
    if ( v3 )
      *(_QWORD *)&v7 ^= _xmm[0];
    return v7;
  }
  if ( v2 < 0x3FE6000000000000i64 )
  {
    v4 = DOUBLE_0_4636476090008061;
    v1 = (v1 * 2.0 - 1.0) / (v1 + 2.0);
    goto LABEL_19;
  }
  if ( v2 < 0x3FF3000000000000i64 )
  {
    v4 = DOUBLE_0_7853981633974483;
    v1 = (v1 - 1.0) / (v1 + 1.0);
    goto LABEL_19;
  }
  if ( v2 < 0x4003800000000000i64 )
  {
    v4 = DOUBLE_0_9827937232473291;
    v1 = (v1 - 1.5) / (v1 * 1.5 + 1.0);
    goto LABEL_19;
  }
  if ( v2 > 0x7FF0000000000000i64 )
    return handle_errorf("atanf", 15, LODWORD(fx) | 0x400000i64, 1, 0, 33, fx, 0.0, 1);
  if ( v1 <= 5.512405943901487e18 )
  {
    v4 = DOUBLE_1_570796326794897;
    v1 = -1.0 / v1;
    goto LABEL_19;
  }
  if ( v3 )
    v6 = COERCE_DOUBLE(*(_QWORD *)&piby2_9 ^ _xmm[0]);
  else
    v6 = piby2_9;
  set_statfp(0x20ui64);
  return v6;
}


// File Line: 74
// RVA: 0x1883C0
float __fastcall UFG::qNormalizedAngleBiased(float a, bool pos_bias)
{
  float v2; // xmm1_4
  int v3; // edx
  int i; // ecx
  float v7; // xmm2_4

  v2 = a;
  v3 = 4;
  for ( i = 4; v2 < -3.1415927; v2 = v2 + 6.2831855 )
  {
    if ( !i-- )
      break;
  }
  for ( ; v2 > 3.1415927; v2 = v2 + -6.2831855 )
  {
    if ( !v3-- )
      break;
  }
  v7 = v2 - -3.1415927;
  if ( (float)(v2 - -3.1415927) < 0.0 )
    LODWORD(v7) ^= _xmm[0];
  if ( v7 >= 0.0000099999997 )
    return v2;
  else
    return FLOAT_3_1415927;
}


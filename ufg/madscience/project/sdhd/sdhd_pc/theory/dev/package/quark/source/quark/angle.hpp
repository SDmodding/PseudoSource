// File Line: 74
// RVA: 0x1883C0
float __fastcall UFG::qNormalizedAngleBiased(float a, bool pos_bias)
{
  float v2; // xmm1_4
  signed int v3; // edx
  signed int i; // ecx
  signed int v5; // eax
  signed int v6; // eax
  float v7; // xmm2_4
  float result; // xmm0_4

  v2 = a;
  v3 = 4;
  for ( i = 4; v2 < -3.1415927; v2 = v2 + 6.2831855 )
  {
    v5 = i--;
    if ( !v5 )
      break;
  }
  for ( ; v2 > 3.1415927; v2 = v2 + -6.2831855 )
  {
    v6 = v3--;
    if ( !v6 )
      break;
  }
  v7 = v2 - -3.1415927;
  if ( (float)(v2 - -3.1415927) < 0.0 )
    LODWORD(v7) ^= _xmm[0];
  if ( v7 >= 0.0000099999997 )
    result = v2;
  else
    result = FLOAT_3_1415927;
  return result;
}


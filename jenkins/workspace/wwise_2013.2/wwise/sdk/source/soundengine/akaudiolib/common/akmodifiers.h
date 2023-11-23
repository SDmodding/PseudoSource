// File Line: 56
// RVA: 0xA8B3F0
float __fastcall RandomizerModifier::GetModValue<float>(
        RandomizerModifier *this,
        RANGED_PARAMETER<float> *in_rModifier)
{
  float v2; // xmm0_4
  float v3; // xmm6_4

  v2 = 0.0;
  v3 = *(float *)&this[8] - *(float *)&this[4];
  if ( v3 != 0.0 )
    v2 = (double)rand() * 0.00003051850947599719 * v3;
  return (float)(v2 + *(float *)&this[4]) + *(float *)this;
}


// File Line: 153
// RVA: 0x32C90
float __fastcall Illusion::StateBlockCurve::EvaluateCurve(Illusion::StateBlockCurve *this, float time)
{
  float *p_numKeys; // rdx
  __int64 v3; // r8
  float *v4; // rax
  unsigned int v6; // ecx

  if ( !this->numKeys )
    return 0.0;
  p_numKeys = (float *)&this[1].numKeys;
  v3 = this->numKeys - 1;
  v4 = (float *)&this[3].numKeys;
  if ( time <= *(float *)&this[1].numKeys )
    return *(float *)&this[2].numKeys;
  if ( time >= *(float *)&this[2 * v3 + 1].numKeys )
    return *(float *)&this[2 * v3 + 2].numKeys;
  v6 = 0;
  if ( !(_DWORD)v3 )
    return 0.0;
  while ( time > *v4 )
  {
    ++v6;
    p_numKeys += 2;
    v4 += 2;
    if ( v6 >= (unsigned int)v3 )
      return 0.0;
  }
  return (float)((float)((float)(time - *p_numKeys) / (float)(*v4 - *p_numKeys)) * (float)(v4[1] - p_numKeys[1]))
       + p_numKeys[1];
}


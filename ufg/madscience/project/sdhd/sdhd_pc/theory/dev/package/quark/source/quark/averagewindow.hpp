// File Line: 53
// RVA: 0x16F420
float __fastcall UFG::qAverageWindow<float>::GetAverage(UFG::qAverageWindow<float> *this)
{
  float result; // xmm0_4
  float v2; // xmm1_4

  result = 0.0;
  if ( this->m_StartIndex != this->m_EndIndex )
  {
    v2 = this->m_RunningSumTime;
    if ( v2 > 0.0 )
      result = this->m_RunningSum / v2;
    else
      result = FLOAT_3_4028235e38;
  }
  return result;
}

// File Line: 67
// RVA: 0x167890
bool __fastcall UFG::qAverageWindow<float>::AtLeastOneEntry(UFG::qAverageWindow<float> *this)
{
  int v1; // eax
  int v2; // er8

  v1 = this->m_StartIndex;
  v2 = this->m_EndIndex;
  return v1 != v2 && (v1 + 1) % this->m_BufferSize != v2;
}


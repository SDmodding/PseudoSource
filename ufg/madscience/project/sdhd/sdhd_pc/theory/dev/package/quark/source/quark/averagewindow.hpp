// File Line: 53
// RVA: 0x16F420
float __fastcall UFG::qAverageWindow<float>::GetAverage(UFG::qAverageWindow<float> *this)
{
  float result; // xmm0_4
  float m_RunningSumTime; // xmm1_4

  result = 0.0;
  if ( this->m_StartIndex != this->m_EndIndex )
  {
    m_RunningSumTime = this->m_RunningSumTime;
    if ( m_RunningSumTime > 0.0 )
      return this->m_RunningSum / m_RunningSumTime;
    else
      return FLOAT_3_4028235e38;
  }
  return result;
}

// File Line: 67
// RVA: 0x167890
bool __fastcall UFG::qAverageWindow<float>::AtLeastOneEntry(UFG::qAverageWindow<float> *this)
{
  int m_StartIndex; // eax
  int m_EndIndex; // r8d

  m_StartIndex = this->m_StartIndex;
  m_EndIndex = this->m_EndIndex;
  return m_StartIndex != m_EndIndex && (m_StartIndex + 1) % this->m_BufferSize != m_EndIndex;
}


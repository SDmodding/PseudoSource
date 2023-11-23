// File Line: 18
// RVA: 0xAD2A00
void __fastcall CAkLpFilter::CAkLpFilter(CAkLpFilter *this)
{
  *(_QWORD *)&this->m_fB0 = 0i64;
  *(_QWORD *)&this->m_fB2 = 0i64;
  *(_QWORD *)&this->m_fA2 = 0i64;
  *(_QWORD *)&this->m_fIn2 = 0i64;
  this->m_fOut2 = 0.0;
}

// File Line: 35
// RVA: 0xAD2A30
void __fastcall CAkLpFilter::SetCoefs(CAkLpFilter *this, float in_fCutFreq, float in_fSampRate)
{
  float v4; // xmm0_4
  float v5; // xmm5_4
  float v6; // xmm4_4
  float v7; // xmm3_4

  v4 = tanf((float)(in_fCutFreq * 3.1415927) / in_fSampRate);
  v5 = (float)(1.0 / v4) * (float)(1.0 / v4);
  v6 = (float)(1.0 / v4) * 1.4142135;
  v7 = 1.0 / (float)((float)(v6 + 1.0) + v5);
  this->m_fB0 = v7;
  this->m_fB2 = v7;
  this->m_fA2 = (float)((float)(1.0 - v6) + v5) * v7;
  this->m_fA1 = (float)((float)(1.0 - v5) * 2.0) * v7;
  this->m_fB1 = v7 * 2.0;
}

// File Line: 52
// RVA: 0xAD2A20
void __fastcall CAkLpFilter::Reset(CAkLpFilter *this)
{
  *(_QWORD *)&this->m_fIn1 = 0i64;
  *(_QWORD *)&this->m_fOut1 = 0i64;
}


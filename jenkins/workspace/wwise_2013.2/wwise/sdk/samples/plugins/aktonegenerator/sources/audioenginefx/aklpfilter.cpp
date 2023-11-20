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
  CAkLpFilter *v3; // rbx
  float v4; // xmm5_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm4_4
  float v8; // xmm3_4

  v3 = this;
  v4 = 1.0 / tanf((float)(in_fCutFreq * 3.1415927) / in_fSampRate);
  v5 = v4;
  v6 = v4 * v4;
  v7 = v5 * 1.4142135;
  v8 = 1.0 / (float)((float)(v7 + 1.0) + v6);
  v3->m_fB0 = v8;
  v3->m_fB2 = v8;
  v3->m_fA2 = (float)((float)(1.0 - v7) + v6) * v8;
  v3->m_fA1 = (float)((float)(1.0 - v6) * 2.0) * v8;
  v3->m_fB1 = v8 * 2.0;
}

// File Line: 52
// RVA: 0xAD2A20
void __fastcall CAkLpFilter::Reset(CAkLpFilter *this)
{
  *(_QWORD *)&this->m_fIn1 = 0i64;
  *(_QWORD *)&this->m_fOut1 = 0i64;
}


// File Line: 24
// RVA: 0xAD8D00
void __fastcall DSP::OnePoleZeroHPFilter::ProcessBuffer(
        DSP::OnePoleZeroHPFilter *this,
        float *io_pfBuffer,
        unsigned int in_uNumFrames)
{
  float m_fA1; // xmm5_4
  float m_fFFwd1; // xmm4_4
  float m_fFbk1; // xmm3_4
  float *v6; // r9
  float *v7; // r8
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm1_4

  m_fA1 = this->m_fA1;
  m_fFFwd1 = this->m_fFFwd1;
  m_fFbk1 = this->m_fFbk1;
  v6 = io_pfBuffer;
  v7 = &io_pfBuffer[in_uNumFrames];
  if ( io_pfBuffer < v7 )
  {
    if ( ((char *)v7 - (char *)io_pfBuffer + 3) / 4 >= 4 )
    {
      do
      {
        v8 = *v6;
        v9 = v6[1];
        v6 += 4;
        v10 = v8 - m_fFFwd1;
        m_fFFwd1 = *(v6 - 1);
        v11 = v10 + (float)(m_fFbk1 * m_fA1);
        *(v6 - 4) = v11;
        v12 = v9 - v8;
        v13 = *(v6 - 2);
        v14 = v12 + (float)(v11 * m_fA1);
        *(v6 - 3) = v14;
        v15 = (float)(v13 - v9) + (float)(v14 * m_fA1);
        *(v6 - 2) = v15;
        m_fFbk1 = (float)(m_fFFwd1 - v13) + (float)(v15 * m_fA1);
        *(v6 - 1) = m_fFbk1;
      }
      while ( (__int64)v6 < (__int64)(v7 - 3) );
    }
    for ( ; v6 < v7; m_fFbk1 = v18 )
    {
      v16 = *v6++;
      v17 = v16 - m_fFFwd1;
      m_fFFwd1 = v16;
      v18 = v17 + (float)(m_fFbk1 * m_fA1);
      *(v6 - 1) = v18;
    }
  }
  this->m_fFFwd1 = m_fFFwd1;
  this->m_fFbk1 = m_fFbk1;
}

// File Line: 51
// RVA: 0xAD8E00
void __fastcall DSP::OnePoleZeroHPFilter::ProcessBufferWithGain(
        DSP::OnePoleZeroHPFilter *this,
        float *io_pfBuffer,
        unsigned int in_uNumFrames,
        float in_fGain)
{
  float m_fFFwd1; // xmm5_4
  float m_fFbk1; // xmm4_4
  float *v7; // r9
  float *v8; // r8
  float m_fA1; // xmm7_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm1_4

  m_fFFwd1 = this->m_fFFwd1;
  m_fFbk1 = this->m_fFbk1;
  v7 = io_pfBuffer;
  v8 = &io_pfBuffer[in_uNumFrames];
  m_fA1 = this->m_fA1;
  if ( io_pfBuffer < v8 )
  {
    if ( ((char *)v8 - (char *)io_pfBuffer + 3) / 4 >= 4 )
    {
      do
      {
        v10 = in_fGain * *v7;
        v11 = in_fGain * v7[1];
        v7 += 4;
        v12 = v10 - m_fFFwd1;
        v13 = v11 - v10;
        v14 = in_fGain * *(v7 - 2);
        v15 = v12 + (float)(m_fFbk1 * m_fA1);
        m_fFFwd1 = in_fGain * *(v7 - 1);
        *(v7 - 4) = v15;
        v16 = v13 + (float)(v15 * m_fA1);
        *(v7 - 3) = v16;
        v17 = (float)(v14 - v11) + (float)(v16 * m_fA1);
        *(v7 - 2) = v17;
        m_fFbk1 = (float)(m_fFFwd1 - v14) + (float)(v17 * m_fA1);
        *(v7 - 1) = m_fFbk1;
      }
      while ( (__int64)v7 < (__int64)(v8 - 3) );
    }
    for ( ; v7 < v8; m_fFbk1 = v19 )
    {
      v18 = (float)(in_fGain * *v7++) - m_fFFwd1;
      m_fFFwd1 = in_fGain * *(v7 - 1);
      v19 = v18 + (float)(m_fFbk1 * m_fA1);
      *(v7 - 1) = v19;
    }
  }
  this->m_fFFwd1 = m_fFFwd1;
  this->m_fFbk1 = m_fFbk1;
}


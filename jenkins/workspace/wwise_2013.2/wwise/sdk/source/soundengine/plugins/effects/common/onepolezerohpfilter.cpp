// File Line: 24
// RVA: 0xAD8D00
void __fastcall DSP::OnePoleZeroHPFilter::ProcessBuffer(DSP::OnePoleZeroHPFilter *this, float *io_pfBuffer, unsigned int in_uNumFrames)
{
  float v3; // xmm5_4
  float v4; // xmm4_4
  float v5; // xmm3_4
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
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm1_4

  v3 = this->m_fA1;
  v4 = this->m_fFFwd1;
  v5 = this->m_fFbk1;
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
        v10 = v8 - v4;
        v4 = *(v6 - 1);
        v11 = v10 + (float)(v5 * v3);
        *(v6 - 4) = v11;
        v12 = v9 - v8;
        v13 = *(v6 - 2);
        v14 = v12 + (float)(v11 * v3);
        v15 = *(v6 - 2);
        *(v6 - 3) = v14;
        v16 = (float)(v15 - v9) + (float)(v14 * v3);
        *(v6 - 2) = v16;
        v5 = (float)(v4 - v13) + (float)(v16 * v3);
        *(v6 - 1) = v5;
      }
      while ( (signed __int64)v6 < (signed __int64)(v7 - 3) );
    }
    for ( ; v6 < v7; v5 = v19 )
    {
      v17 = *v6;
      ++v6;
      v18 = v17 - v4;
      v4 = v17;
      v19 = v18 + (float)(v5 * v3);
      *(v6 - 1) = v19;
    }
  }
  this->m_fFFwd1 = v4;
  this->m_fFbk1 = v5;
}

// File Line: 51
// RVA: 0xAD8E00
void __fastcall DSP::OnePoleZeroHPFilter::ProcessBufferWithGain(DSP::OnePoleZeroHPFilter *this, float *io_pfBuffer, unsigned int in_uNumFrames, float in_fGain)
{
  float v4; // xmm5_4
  float v5; // xmm4_4
  float v6; // xmm6_4
  float *v7; // r9
  float *v8; // r8
  float v9; // xmm7_4
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

  v4 = this->m_fFFwd1;
  v5 = this->m_fFbk1;
  v6 = in_fGain;
  v7 = io_pfBuffer;
  v8 = &io_pfBuffer[in_uNumFrames];
  v9 = this->m_fA1;
  if ( io_pfBuffer < v8 )
  {
    if ( ((char *)v8 - (char *)io_pfBuffer + 3) / 4 >= 4 )
    {
      do
      {
        v10 = v6 * *v7;
        v11 = v6 * v7[1];
        v7 += 4;
        v12 = v10 - v4;
        v13 = v11 - v10;
        v14 = v6 * *(v7 - 2);
        v15 = v12 + (float)(v5 * v9);
        v4 = v6 * *(v7 - 1);
        *(v7 - 4) = v15;
        v16 = v13 + (float)(v15 * v9);
        *(v7 - 3) = v16;
        v17 = (float)(v14 - v11) + (float)(v16 * v9);
        *(v7 - 2) = v17;
        v5 = (float)(v4 - v14) + (float)(v17 * v9);
        *(v7 - 1) = v5;
      }
      while ( (signed __int64)v7 < (signed __int64)(v8 - 3) );
    }
    for ( ; v7 < v8; v5 = v19 )
    {
      ++v7;
      v18 = (float)(v6 * *(v7 - 1)) - v4;
      v4 = v6 * *(v7 - 1);
      v19 = v18 + (float)(v5 * v9);
      *(v7 - 1) = v19;
    }
  }
  this->m_fFFwd1 = v4;
  this->m_fFbk1 = v5;
}


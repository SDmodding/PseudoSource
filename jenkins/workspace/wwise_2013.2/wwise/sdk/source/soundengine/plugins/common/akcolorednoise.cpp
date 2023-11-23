// File Line: 22
// RVA: 0xADDD00
void __fastcall DSP::CAkColoredNoise::Init(
        DSP::CAkColoredNoise *this,
        DSP::CAkColoredNoise::AkNoiseColor in_eNoiseColor,
        int in_uSampleRate)
{
  float v3; // xmm0_4

  this->m_NoiseColor = in_eNoiseColor;
  switch ( in_eNoiseColor )
  {
    case NOISECOLOR_PINK:
      *(_QWORD *)this->m_RandGenTable = 0i64;
      *(_QWORD *)&this->m_RandGenTable[2] = 0i64;
      *(_QWORD *)&this->m_RandGenTable[4] = 0i64;
      *(_QWORD *)&this->m_RandGenTable[6] = 0i64;
      *(_QWORD *)&this->m_RandGenTable[8] = 0i64;
      *(_QWORD *)&this->m_RandGenTable[10] = 0i64;
      *(_QWORD *)&this->m_RandGenTable[12] = 0i64;
      *(_QWORD *)&this->m_RandGenTable[14] = 0i64;
      *(_QWORD *)&this->m_uIndex = 0i64;
      this->m_DCFilter.m_fA1 = 1.0 - (float)(251.32742 / (float)in_uSampleRate);
      break;
    case NOISECOLOR_PURPLE:
      DSP::BiquadFilter<DSP::SingleChannelPolicy>::SetCoefs(
        &this->PurpleFilter,
        AKPURPLENOISE_B0COEF_2,
        AKPURPLENOISE_B1COEF_2,
        AKPURPLENOISE_B2COEF_2,
        AKPURPLENOISE_A1COEF_2,
        AKPURPLENOISE_A2COEF_2);
      break;
    case NOISECOLOR_RED:
      v3 = AKREDNOISE_B0COEF_2;
      this->RedFilter.fA1 = -0.995;
      this->RedFilter.fB0 = v3;
      break;
  }
}

// File Line: 53
// RVA: 0xADDDD0
void __fastcall DSP::CAkColoredNoise::GenerateBufferPink(
        DSP::CAkColoredNoise *this,
        float *out_pfBuffer,
        unsigned int in_uNumFrames)
{
  __int64 v3; // r14
  unsigned int m_uIndex; // edi
  float *v7; // r10
  float m_fRunningSum; // xmm6_4
  float *v9; // r9
  float *v10; // r11
  float *v11; // r8
  float v12; // xmm0_4
  __int64 v13; // rcx
  float v14; // xmm6_4
  float v15; // xmm6_4
  __int64 v16; // rcx
  float v17; // xmm0_4
  float v18; // xmm6_4
  float v19; // xmm0_4
  float v20; // xmm6_4
  __int64 v21; // rcx
  float v22; // xmm0_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  float v25; // xmm6_4
  __int64 v26; // rcx
  float v27; // xmm0_4
  float v28; // xmm6_4
  float v29; // xmm0_4
  signed __int64 v30; // r10
  float v31; // xmm0_4
  __int64 v32; // rcx
  float v33; // xmm6_4

  v3 = in_uNumFrames;
  DSP::CAkWhiteNoise::GenerateBuffer(this, out_pfBuffer, 2 * in_uNumFrames);
  m_uIndex = this->m_uIndex;
  v7 = &out_pfBuffer[v3];
  m_fRunningSum = this->m_fRunningSum;
  v9 = out_pfBuffer;
  v10 = v7;
  if ( out_pfBuffer < v7 )
  {
    if ( (4 * v3 + 3) / 4 >= 4 )
    {
      v11 = v7 - 3;
      do
      {
        v12 = *v7;
        v9 += 4;
        v7 += 4;
        v13 = CountTrailingZerosTable_0[(unsigned __int64)(125613361
                                                         * ((unsigned __int16)(m_uIndex + 1) & (unsigned int)-(unsigned __int16)(m_uIndex + 1))) >> 27];
        v14 = m_fRunningSum - this->m_RandGenTable[v13];
        this->m_RandGenTable[v13] = v12;
        v15 = v14 + v12;
        v16 = CountTrailingZerosTable_0[(unsigned __int64)(125613361
                                                         * ((unsigned __int16)(m_uIndex + 2) & (unsigned int)-(unsigned __int16)(m_uIndex + 2))) >> 27];
        v17 = v15 + *(v9 - 4);
        v18 = v15 - this->m_RandGenTable[v16];
        *(v9 - 4) = v17 * 0.14705883;
        v19 = *(v7 - 3);
        this->m_RandGenTable[v16] = v19;
        v20 = v18 + v19;
        v21 = CountTrailingZerosTable_0[(unsigned __int64)(125613361
                                                         * ((unsigned __int16)(m_uIndex + 3) & (unsigned int)-(unsigned __int16)(m_uIndex + 3))) >> 27];
        m_uIndex = (unsigned __int16)(m_uIndex + 4);
        v22 = v20 + *(v9 - 3);
        v23 = v20 - this->m_RandGenTable[v21];
        *(v9 - 3) = v22 * 0.14705883;
        v24 = *(v7 - 2);
        this->m_RandGenTable[v21] = v24;
        v25 = v23 + v24;
        v26 = CountTrailingZerosTable_0[(unsigned __int64)(125613361 * (m_uIndex & -m_uIndex)) >> 27];
        v27 = v25 + *(v9 - 2);
        v28 = v25 - this->m_RandGenTable[v26];
        *(v9 - 2) = v27 * 0.14705883;
        v29 = *(v7 - 1);
        m_fRunningSum = v28 + v29;
        this->m_RandGenTable[v26] = v29;
        *(v9 - 1) = (float)(m_fRunningSum + *(v9 - 1)) * 0.14705883;
      }
      while ( (__int64)v9 < (__int64)v11 );
    }
    if ( v9 < v10 )
    {
      v30 = (char *)v7 - (char *)v9;
      do
      {
        v31 = *(float *)((char *)v9++ + v30);
        m_uIndex = (unsigned __int16)(m_uIndex + 1);
        v32 = CountTrailingZerosTable_0[(unsigned __int64)(125613361 * (m_uIndex & -m_uIndex)) >> 27];
        v33 = m_fRunningSum - this->m_RandGenTable[v32];
        this->m_RandGenTable[v32] = v31;
        m_fRunningSum = v33 + v31;
        *(v9 - 1) = (float)(m_fRunningSum + *(v9 - 1)) * 0.14705883;
      }
      while ( v9 < v10 );
    }
  }
  DSP::OnePoleZeroHPFilter::ProcessBuffer(&this->m_DCFilter, out_pfBuffer, v3);
  this->m_uIndex = m_uIndex;
  this->m_fRunningSum = m_fRunningSum;
}

// File Line: 95
// RVA: 0xADE010
void __fastcall DSP::CAkColoredNoise::GenerateBufferRed(
        DSP::CAkColoredNoise *this,
        float *out_pfBuffer,
        unsigned int in_uNumFrames)
{
  DSP::CAkWhiteNoise::GenerateBuffer(this, out_pfBuffer, in_uNumFrames);
  DSP::OnePoleFilter::ProcessBuffer(&this->RedFilter, out_pfBuffer, in_uNumFrames);
}

// File Line: 103
// RVA: 0xADE060
void __fastcall DSP::CAkColoredNoise::GenerateBufferPurple(
        DSP::CAkColoredNoise *this,
        float *out_pfBuffer,
        unsigned int in_uNumFrames)
{
  DSP::CAkWhiteNoise::GenerateBuffer(this, out_pfBuffer, in_uNumFrames);
  DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBuffer(&this->PurpleFilter, out_pfBuffer, in_uNumFrames, 0);
}


// File Line: 38
// RVA: 0xAD6450
void __fastcall CAkSoundSeedWindProcess::CAkSoundSeedWindProcess(CAkSoundSeedWindProcess *this)
{
  this->m_pParams = 0i64;
  this->m_pDeflectors = 0i64;
  this->m_pDeflectorInfo = 0i64;
  this->m_pDeflectorDSPInfo = 0i64;
  this->m_RandGenerator.m_uLCGState = rand();
  DSP::CAkPinkNoise::CAkPinkNoise(&this->m_NoiseGen);
}

// File Line: 43
// RVA: 0xAD6490
void __fastcall CAkSoundSeedWindProcess::~CAkSoundSeedWindProcess(CAkSoundSeedWindProcess *this)
{
  ;
}

// File Line: 50
// RVA: 0xAD64A0
void __fastcall CAkSoundSeedWindProcess::Setup(
        CAkSoundSeedWindProcess *this,
        AkWindParams *in_pParams,
        AkAudioFormat *io_rFormat)
{
  unsigned int uChannelMask; // r9d
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int i; // ecx
  unsigned int m_uNumChannels; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // ecx
  unsigned __int16 v13; // ax
  float v14; // xmm1_4
  signed int v15; // eax
  float v16; // xmm1_4
  signed int v17; // eax
  float v18; // xmm2_4
  signed int v19; // eax
  float v20; // xmm1_4
  signed int v21; // eax

  this->m_uSampleRate = io_rFormat->uSampleRate;
  uChannelMask = in_pParams->uChannelMask;
  *((_DWORD *)io_rFormat + 1) &= 0xFFFC0000;
  *((_DWORD *)io_rFormat + 1) |= uChannelMask & 0x3FFFF;
  v5 = *((_DWORD *)io_rFormat + 1) & 0x3FFFF;
  if ( v5 > 0x37 )
  {
    v6 = v5 - 59;
    if ( v6 )
    {
      v7 = v6 - 4;
      if ( v7 )
      {
        v8 = v7 - 1528;
        if ( v8 )
        {
          if ( v8 != 8 )
          {
LABEL_8:
            *((_DWORD *)io_rFormat + 1) &= 0xFFFC0003;
            uChannelMask = 3;
            *((_DWORD *)io_rFormat + 1) |= 3u;
          }
        }
      }
    }
  }
  else if ( v5 != 55 )
  {
    switch ( v5 )
    {
      case 3u:
      case 4u:
      case 7u:
      case 8u:
      case 0xBu:
      case 0xCu:
      case 0xFu:
      case 0x33u:
        break;
      default:
        goto LABEL_8;
    }
  }
  for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
    ++i;
  this->m_uNumChannels = i;
  *((_DWORD *)io_rFormat + 1) &= 0xE0FFFFFF;
  *((_DWORD *)io_rFormat + 1) |= (i << 26) & 0x1F000000;
  m_uNumChannels = this->m_uNumChannels;
  this->m_NoiseGen.m_DCFilter.m_fA1 = 1.0 - (float)(251.32742 / (float)(int)this->m_uSampleRate);
  v11 = m_uNumChannels - 1;
  if ( !v11 )
  {
    v13 = 112;
    goto LABEL_17;
  }
  v12 = v11 - 1;
  if ( !v12 )
  {
    v13 = 144;
    goto LABEL_17;
  }
  if ( v12 == 2 )
  {
    v13 = 176;
LABEL_17:
    this->m_uDSPInfoSize = v13;
  }
  v14 = in_pParams->fRandomValue[0];
  v15 = 214013 * this->m_RandGenerator.m_uLCGState + 2531011;
  this->m_RandGenerator.m_uLCGState = v15;
  this->m_fRandomParamValue[0] = (float)((float)((float)((float)v15 * 2.3283064e-10) * 2.0) - 1.0) * v14;
  v16 = in_pParams->fRandomValue[1];
  v17 = 214013 * this->m_RandGenerator.m_uLCGState + 2531011;
  this->m_RandGenerator.m_uLCGState = v17;
  this->m_fRandomParamValue[1] = (float)((float)((float)((float)v17 * 2.3283064e-10) * 2.0) - 1.0) * v16;
  v18 = in_pParams->fRandomValue[2];
  v19 = 214013 * this->m_RandGenerator.m_uLCGState + 2531011;
  this->m_RandGenerator.m_uLCGState = v19;
  this->m_fRandomParamValue[2] = (float)((float)((float)((float)v19 * 2.3283064e-10) * 2.0) - 1.0) * v18;
  v20 = in_pParams->fRandomValue[3];
  v21 = 214013 * this->m_RandGenerator.m_uLCGState + 2531011;
  this->m_RandGenerator.m_uLCGState = v21;
  this->m_fRandomParamValue[3] = (float)((float)((float)((float)v21 * 2.3283064e-10) * 2.0) - 1.0) * v20;
  this->m_bFirstExecution = 1;
}

// File Line: 93
// RVA: 0xAD6970
void __fastcall CAkSoundSeedWindProcess::ComputeStereoGains(
        CAkSoundSeedWindProcess *this,
        unsigned int in_uIndex,
        float *out_fLeft,
        float *out_fRight)
{
  AkWindDeflectorParams *m_pDeflectors; // rbx
  __int64 v5; // rdi
  float v8; // xmm0_4
  float v9; // xmm7_4

  m_pDeflectors = this->m_pDeflectors;
  v5 = in_uIndex;
  v8 = powf(m_pDeflectors[in_uIndex].fDistance / this->m_pParams->fMaxDistance, 0.16666667);
  v9 = (float)((float)((float)(v8 * cosf((float)((float)(90.0 - m_pDeflectors[v5].fAngle) * 3.1415927) * 0.0055555557))
                     * 3.1415927)
             * 0.25)
     + 0.78539819;
  *out_fLeft = cosf(v9);
  *out_fRight = sinf(v9);
}

// File Line: 106
// RVA: 0xAD6A30
void __fastcall CAkSoundSeedWindProcess::ComputeQuadGains(
        CAkSoundSeedWindProcess *this,
        unsigned int in_uIndex,
        float *out_fFrontLeft,
        float *out_fFrontRight,
        float *out_fRearLeft,
        float *out_fRearRight)
{
  __int64 v6; // rax
  AkWindDeflectorParams *m_pDeflectors; // rdx
  float v10; // xmm7_4
  float v11; // xmm10_4
  float v12; // xmm6_4
  float v13; // xmm11_4
  float v14; // xmm12_4
  float v15; // xmm7_4
  float v16; // xmm6_4
  float v17; // xmm0_4

  v6 = in_uIndex;
  m_pDeflectors = this->m_pDeflectors;
  v10 = (float)((float)(90.0 - m_pDeflectors[v6].fAngle) * 3.1415927) * 0.0055555557;
  v11 = powf(m_pDeflectors[v6].fDistance / this->m_pParams->fMaxDistance, 0.16666667);
  v12 = (float)((float)((float)(cosf(v10) * v11) * 3.1415927) * 0.25) + 0.78539819;
  v13 = cosf(v12);
  v14 = sinf(v12);
  v15 = (float)((float)((float)(sinf(v10) * v11) * 3.1415927) * 0.25) + 0.78539819;
  v16 = sinf(v15);
  v17 = cosf(v15);
  *out_fFrontLeft = v16 * v13;
  *out_fFrontRight = v16 * v14;
  *out_fRearLeft = v17 * v13;
  *out_fRearRight = v17 * v14;
}

// File Line: 126
// RVA: 0xAD6B90
void __fastcall CAkSoundSeedWindProcess::InitSpatialization(CAkSoundSeedWindProcess *this)
{
  unsigned int m_cDeflectors; // r15d
  unsigned int v3; // esi
  __int64 v4; // rbx
  AkWindDeflectorParams *v5; // rcx
  float v6; // xmm8_4
  float v7; // xmm7_4
  float v8; // xmm6_4
  float v9; // xmm9_4
  float v10; // xmm10_4
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm0_4
  __int64 v14; // rdx
  unsigned int v15; // r8d
  char *v16; // r8
  unsigned int v17; // esi
  __int64 v18; // rbp
  AkWindDeflectorParams *m_pDeflectors; // rbx
  float v20; // xmm6_4
  float v21; // xmm0_4
  __int64 v22; // rbx
  char *v23; // rdi
  float v24; // xmm6_4

  m_cDeflectors = this->m_cDeflectors;
  if ( this->m_uNumChannels == 2 )
  {
    v17 = 0;
    if ( m_cDeflectors )
    {
      v18 = 0i64;
      do
      {
        m_pDeflectors = this->m_pDeflectors;
        v20 = powf(m_pDeflectors[v18].fDistance / this->m_pParams->fMaxDistance, 0.16666667);
        v21 = cosf((float)((float)(90.0 - m_pDeflectors[v18].fAngle) * 3.1415927) * 0.0055555557);
        v22 = v17 & 3;
        v23 = (char *)this->m_pDeflectorDSPInfo + this->m_uDSPInfoSize * (v17 >> 2);
        v24 = (float)((float)((float)(v20 * v21) * 3.1415927) * 0.25) + 0.78539819;
        *(float *)&v23[4 * v22 + 112] = cosf(v24);
        ++v17;
        ++v18;
        *(float *)&v23[4 * v22 + 128] = sinf(v24);
      }
      while ( v17 < m_cDeflectors );
    }
  }
  else if ( this->m_uNumChannels == 4 )
  {
    v3 = 0;
    if ( m_cDeflectors )
    {
      v4 = 0i64;
      do
      {
        v5 = this->m_pDeflectors;
        v6 = (float)((float)(90.0 - v5[v4].fAngle) * 3.1415927) * 0.0055555557;
        v7 = powf(v5[v4].fDistance / this->m_pParams->fMaxDistance, 0.16666667);
        v8 = (float)((float)((float)(cosf(v6) * v7) * 3.1415927) * 0.25) + 0.78539819;
        v9 = cosf(v8);
        v10 = sinf(v8);
        v11 = (float)((float)((float)(sinf(v6) * v7) * 3.1415927) * 0.25) + 0.78539819;
        v12 = sinf(v11);
        v13 = cosf(v11);
        v14 = v3 & 3;
        v15 = v3++ >> 2;
        ++v4;
        v16 = (char *)this->m_pDeflectorDSPInfo + this->m_uDSPInfoSize * v15;
        *(float *)&v16[4 * v14 + 112] = v12 * v9;
        *(float *)&v16[4 * v14 + 128] = v12 * v10;
        *(float *)&v16[4 * v14 + 144] = v13 * v9;
        *(float *)&v16[4 * v14 + 160] = v13 * v10;
      }
      while ( v3 < m_cDeflectors );
    }
  }
}

// File Line: 210
// RVA: 0xAD6E80
void __fastcall CAkSoundSeedWindProcess::ComputeEffectiveAverageVelocity(
        CAkSoundSeedWindProcess *this,
        float in_fAutomationValue)
{
  float v3; // xmm0_4

  v3 = powf(
         2.0,
         (float)((float)(this->m_pParams->fBaseValue[0] + this->m_fRandomParamValue[0]) + in_fAutomationValue)
       * 0.00083333335)
     * 8.0;
  if ( v3 > 2.0 )
    this->m_fEffectiveParamValue[0] = v3;
  else
    this->m_fEffectiveParamValue[0] = FLOAT_2_0;
}

// File Line: 220
// RVA: 0xAD6EF0
void __fastcall CAkSoundSeedWindProcess::ComputeEffectiveVariability(
        CAkSoundSeedWindProcess *this,
        float in_fAutomationValue)
{
  float v2; // xmm0_4

  v2 = (float)(this->m_pParams->fBaseValue[2] + this->m_fRandomParamValue[2]) + in_fAutomationValue;
  if ( v2 < 1.0 )
  {
    if ( v2 > 0.0 )
      this->m_fEffectiveParamValue[2] = v2;
    else
      this->m_fEffectiveParamValue[2] = 0.0;
  }
  else
  {
    LODWORD(this->m_fEffectiveParamValue[2]) = (_DWORD)FLOAT_1_0;
  }
}

// File Line: 234
// RVA: 0xAD6F30
void __fastcall CAkSoundSeedWindProcess::ComputeEffectiveGustiness(
        CAkSoundSeedWindProcess *this,
        float in_fAutomationValue)
{
  float v2; // xmm0_4

  v2 = (float)(this->m_pParams->fBaseValue[3] + this->m_fRandomParamValue[3]) + in_fAutomationValue;
  if ( v2 < 1.0 )
  {
    if ( v2 > 0.0 )
      this->m_fEffectiveParamValue[3] = v2;
    else
      this->m_fEffectiveParamValue[3] = 0.0;
  }
  else
  {
    LODWORD(this->m_fEffectiveParamValue[3]) = (_DWORD)FLOAT_1_0;
  }
}

// File Line: 253
// RVA: 0xAD66E0
void __fastcall CAkSoundSeedWindProcess::Prepare(
        CAkSoundSeedWindProcess *this,
        signed int in_uNumFrames,
        CAkVelocityDelayLine *in_VelocityDelayLine,
        char in_uChangeMask)
{
  AkWindParams *m_pParams; // rdi
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float in_fBufferTime; // xmm7_4
  float m_fMinVelocity; // xmm0_4
  unsigned int uDelayLineLength; // r11d
  unsigned int uCurOffset; // eax
  float *pfDelay; // r10
  float v18; // xmm6_4

  m_pParams = this->m_pParams;
  v9 = powf(
         2.0,
         (float)((float)(m_pParams->fBaseValue[0] + this->m_fRandomParamValue[0]) + this->m_fAutomationValues[0])
       * 0.00083333335)
     * 8.0;
  if ( v9 <= 2.0 )
    v9 = FLOAT_2_0;
  this->m_fEffectiveParamValue[0] = v9;
  this->m_fEffectiveParamValue[1] = (float)(m_pParams->fBaseValue[1] + this->m_fRandomParamValue[1])
                                  + this->m_fAutomationValues[1];
  v10 = (float)(m_pParams->fBaseValue[2] + this->m_fRandomParamValue[2]) + this->m_fAutomationValues[2];
  if ( v10 < 1.0 )
  {
    if ( v10 <= 0.0 )
      v10 = 0.0;
  }
  else
  {
    v10 = *(float *)&FLOAT_1_0;
  }
  this->m_fEffectiveParamValue[2] = v10;
  v11 = (float)(m_pParams->fBaseValue[3] + this->m_fRandomParamValue[3]) + this->m_fAutomationValues[3];
  if ( v11 < 1.0 )
  {
    if ( v11 <= 0.0 )
      v11 = 0.0;
  }
  else
  {
    v11 = *(float *)&FLOAT_1_0;
  }
  v12 = this->m_fAutomationValues[4];
  this->m_fEffectiveParamValue[3] = v11;
  CAkSoundSeedWindProcess::ComputeEffectiveFrequencyScale(this, v12);
  CAkSoundSeedWindProcess::ComputeEffectiveQFactorScale(this, this->m_fAutomationValues[5]);
  CAkSoundSeedWindProcess::ComputeEffectiveGainOffset(this, this->m_fAutomationValues[6]);
  in_fBufferTime = (double)in_uNumFrames / (double)(int)this->m_uSampleRate;
  m_fMinVelocity = CAkGustManager::ComputeInstantVelocity(
                     &in_VelocityDelayLine->m_GustManager,
                     this->m_fEffectiveParamValue[0],
                     this->m_fEffectiveParamValue[2],
                     this->m_fEffectiveParamValue[3],
                     in_fBufferTime);
  if ( m_fMinVelocity <= in_VelocityDelayLine->m_fMinVelocity )
    m_fMinVelocity = in_VelocityDelayLine->m_fMinVelocity;
  in_VelocityDelayLine->pfDelay[in_VelocityDelayLine->uCurOffset++] = m_fMinVelocity;
  uDelayLineLength = in_VelocityDelayLine->uDelayLineLength;
  uCurOffset = in_VelocityDelayLine->uCurOffset;
  pfDelay = in_VelocityDelayLine->pfDelay;
  if ( uCurOffset == in_VelocityDelayLine->uDelayLineLength )
    uCurOffset = 0;
  in_VelocityDelayLine->uCurOffset = uCurOffset;
  v18 = (float)((float)(pfDelay[(uCurOffset + uDelayLineLength - 2) % uDelayLineLength]
                      + pfDelay[(uCurOffset + uDelayLineLength - 1) % uDelayLineLength])
              + pfDelay[(uCurOffset + uDelayLineLength - 3) % uDelayLineLength])
      * 0.33333334;
  if ( this->m_pParams->bAutomation[1] || (in_uChangeMask & 0x15) != 0 || this->m_bFirstExecution )
    CAkSoundSeedWindProcess::ComputeDistancesToEntry(this);
  CAkSoundSeedWindProcess::ComputeDeflectorWindVelocities(this, v18, in_fBufferTime, in_VelocityDelayLine);
  if ( this->m_bFirstExecution )
    CAkSoundSeedWindProcess::InitDeflectorGainRamp(this);
  else
    CAkSoundSeedWindProcess::ComputeDeflectorGains(this, in_uNumFrames);
  CAkSoundSeedWindProcess::ComputeFilterCoefficients(this);
}

// File Line: 315
// RVA: 0xAD6910
void __fastcall CAkSoundSeedWindProcess::Process(
        CAkSoundSeedWindProcess *this,
        AkAudioBuffer *io_pBufferOut,
        float *in_pfTempStorage)
{
  switch ( this->m_uNumChannels )
  {
    case 1u:
      CAkSoundSeedWindProcess::ProcessMono(this, io_pBufferOut, in_pfTempStorage);
      break;
    case 2u:
      CAkSoundSeedWindProcess::ProcessStereo(this, io_pBufferOut, in_pfTempStorage);
      CAkSoundSeedWindProcess::DeflectorGainRampCompleted(this);
      return;
    case 4u:
      CAkSoundSeedWindProcess::ProcessQuad(this, io_pBufferOut, in_pfTempStorage);
      CAkSoundSeedWindProcess::DeflectorGainRampCompleted(this);
      return;
  }
  CAkSoundSeedWindProcess::DeflectorGainRampCompleted(this);
}

// File Line: 343
// RVA: 0xAD6F70
void __fastcall CAkSoundSeedWindProcess::ComputeDeflectorWindVelocities(
        CAkSoundSeedWindProcess *this,
        float in_fInstantVelocity,
        float in_fBufferTime,
        CAkVelocityDelayLine *in_VelocityDelayLine)
{
  signed int m_cDeflectors; // ebx
  unsigned int v5; // esi
  __int64 v6; // r10
  float v7; // xmm4_4
  unsigned int v8; // eax
  __int64 v9; // rbp
  __int64 v10; // r14
  __int64 v11; // r10
  __int64 v12; // rbx

  m_cDeflectors = this->m_cDeflectors;
  v5 = 0;
  v6 = 0i64;
  if ( m_cDeflectors >= 4 )
  {
    v7 = 1.0 / (float)(in_fInstantVelocity * in_fBufferTime);
    v8 = ((unsigned int)(m_cDeflectors - 4) >> 2) + 1;
    v9 = 0i64;
    v5 = 4 * v8;
    v6 = 4i64 * v8;
    v10 = v8;
    do
    {
      v9 += 128i64;
      *(float *)((char *)&this->m_pDeflectorInfo[-4] + v9 - 12) = in_VelocityDelayLine->pfDelay[(in_VelocityDelayLine->uDelayLineLength
                                                                                               - (int)(float)(v7 * *(float *)((char *)&this->m_pDeflectorInfo[-4] + v9 - 16))
                                                                                               + in_VelocityDelayLine->uCurOffset
                                                                                               - 1)
                                                                                              % in_VelocityDelayLine->uDelayLineLength];
      *(float *)((char *)&this->m_pDeflectorInfo[-3] + v9 - 8) = in_VelocityDelayLine->pfDelay[(in_VelocityDelayLine->uDelayLineLength
                                                                                              - (int)(float)(v7 * *(float *)((char *)&this->m_pDeflectorInfo[-3] + v9 - 12))
                                                                                              + in_VelocityDelayLine->uCurOffset
                                                                                              - 1)
                                                                                             % in_VelocityDelayLine->uDelayLineLength];
      *(float *)((char *)&this->m_pDeflectorInfo[-2] + v9 - 4) = in_VelocityDelayLine->pfDelay[(in_VelocityDelayLine->uDelayLineLength
                                                                                              - (int)(float)(v7 * *(float *)((char *)&this->m_pDeflectorInfo[-2] + v9 - 8))
                                                                                              + in_VelocityDelayLine->uCurOffset
                                                                                              - 1)
                                                                                             % in_VelocityDelayLine->uDelayLineLength];
      *(float *)((char *)&this->m_pDeflectorInfo[-1].fVelocity + v9) = in_VelocityDelayLine->pfDelay[(in_VelocityDelayLine->uDelayLineLength - (int)(float)(v7 * *(float *)((char *)&this->m_pDeflectorInfo[-1] + v9 - 4)) + in_VelocityDelayLine->uCurOffset - 1) % in_VelocityDelayLine->uDelayLineLength];
      --v10;
    }
    while ( v10 );
  }
  if ( v5 < m_cDeflectors )
  {
    v11 = 32 * v6;
    v12 = m_cDeflectors - v5;
    do
    {
      v11 += 32i64;
      *(float *)((char *)&this->m_pDeflectorInfo[-1].fVelocity + v11) = in_VelocityDelayLine->pfDelay[(in_VelocityDelayLine->uDelayLineLength - (int)(float)((float)(1.0 / (float)(in_fInstantVelocity * in_fBufferTime)) * *(float *)((char *)&this->m_pDeflectorInfo[-1] + v11 - 4)) + in_VelocityDelayLine->uCurOffset - 1) % in_VelocityDelayLine->uDelayLineLength];
      --v12;
    }
    while ( v12 );
  }
}

// File Line: 354
// RVA: 0xAD7110
void __fastcall CAkSoundSeedWindProcess::ComputeFilterCoefficients(CAkSoundSeedWindProcess *this)
{
  unsigned int m_cDeflectors; // r15d
  unsigned int v2; // r14d
  float v4; // xmm9_4
  __int64 v5; // rbp
  DeflectorInfo *m_pDeflectorInfo; // rax
  float v7; // xmm6_4
  float v8; // xmm7_4
  __int64 v9; // rbx
  char *v10; // rdi
  float v11; // xmm0_4

  m_cDeflectors = this->m_cDeflectors;
  v2 = 0;
  v4 = 1.0 / (float)(int)this->m_uSampleRate;
  if ( m_cDeflectors )
  {
    v5 = 0i64;
    do
    {
      m_pDeflectorInfo = this->m_pDeflectorInfo;
      v7 = (float)(*(float *)((char *)&m_pDeflectorInfo->fEffectiveQFactor + v5)
                 * *(float *)((char *)&m_pDeflectorInfo->fEffectiveFrequency + v5))
         * 0.125;
      if ( v7 >= (float)((float)(int)this->m_uSampleRate * 0.5) )
        v7 = (float)(int)this->m_uSampleRate * 0.5;
      if ( v7 <= 20.0 )
        v7 = FLOAT_20_0;
      v8 = expf(
             (float)((float)((float)((float)(v7 / *(float *)((char *)&m_pDeflectorInfo->fEffectiveGain + v5)) * 2.0)
                           * 3.1415927)
                   * v4)
           * -0.5);
      if ( v8 >= 0.99919999 )
        v8 = FLOAT_0_99919999;
      v9 = v2 & 3;
      v10 = (char *)this->m_pDeflectorDSPInfo + this->m_uDSPInfoSize * (v2 >> 2);
      v11 = cosf((float)(v7 * 6.2831855) * v4);
      ++v2;
      v5 += 32i64;
      *(_DWORD *)&v10[4 * v9 + 64] = COERCE_UNSIGNED_INT(v8 * v8) ^ _xmm[0];
      *(float *)&v10[4 * v9 + 48] = v11 * (float)(v8 * 2.0);
    }
    while ( v2 < m_cDeflectors );
  }
}

// File Line: 388
// RVA: 0xAD7320
void __fastcall CAkSoundSeedWindProcess::ComputeDistancesToEntry(CAkSoundSeedWindProcess *this)
{
  unsigned int m_cDeflectors; // r14d
  unsigned int v2; // r12d
  float v4; // xmm7_4
  float fMaxDistance; // xmm10_4
  float v6; // xmm6_4
  DeflectorInfo *m_pDeflectorInfo; // r13
  __int64 v8; // r15
  __int64 v9; // rsi
  __int64 v10; // rbp
  AkWindDeflectorParams *m_pDeflectors; // rbx
  __int64 v12; // rcx
  __int64 v13; // rdx
  unsigned int v14; // eax
  __int64 v15; // r8
  __int64 v16; // rcx
  __int64 v17; // rdx

  m_cDeflectors = this->m_cDeflectors;
  v2 = 0;
  v4 = (float)(this->m_fEffectiveParamValue[1] * 3.1415927) * 0.0055555557;
  fMaxDistance = this->m_pParams->fMaxDistance;
  v6 = fMaxDistance * 2.0;
  if ( m_cDeflectors )
  {
    m_pDeflectorInfo = this->m_pDeflectorInfo;
    v8 = m_cDeflectors;
    v9 = 0i64;
    v10 = 0i64;
    do
    {
      m_pDeflectors = this->m_pDeflectors;
      *(float *)((char *)&m_pDeflectorInfo->fVelocity + v9) = fMaxDistance
                                                            - (float)(cosf(
                                                                        v4
                                                                      - (float)((float)(m_pDeflectors[v10].fAngle
                                                                                      * 3.1415927)
                                                                              * 0.0055555557))
                                                                    * m_pDeflectors[v10].fDistance);
      m_pDeflectorInfo = this->m_pDeflectorInfo;
      if ( v6 >= *(float *)((char *)&m_pDeflectorInfo->fVelocity + v9) )
        v6 = *(float *)((char *)&m_pDeflectorInfo->fVelocity + v9);
      ++v10;
      v9 += 32i64;
      --v8;
    }
    while ( v8 );
  }
  v12 = 0i64;
  if ( (int)m_cDeflectors >= 4 )
  {
    v13 = 0i64;
    v14 = ((m_cDeflectors - 4) >> 2) + 1;
    v15 = v14;
    v2 = 4 * v14;
    v12 = 4i64 * v14;
    do
    {
      v13 += 128i64;
      *(float *)((char *)&this->m_pDeflectorInfo[-4] + v13 - 16) = *(float *)((char *)&this->m_pDeflectorInfo[-4]
                                                                            + v13
                                                                            - 16)
                                                                 - v6;
      *(float *)((char *)&this->m_pDeflectorInfo[-3] + v13 - 12) = *(float *)((char *)&this->m_pDeflectorInfo[-3]
                                                                            + v13
                                                                            - 12)
                                                                 - v6;
      *(float *)((char *)&this->m_pDeflectorInfo[-2] + v13 - 8) = *(float *)((char *)&this->m_pDeflectorInfo[-2]
                                                                           + v13
                                                                           - 8)
                                                                - v6;
      *(float *)((char *)&this->m_pDeflectorInfo[-1] + v13 - 4) = *(float *)((char *)&this->m_pDeflectorInfo[-1]
                                                                           + v13
                                                                           - 4)
                                                                - v6;
      --v15;
    }
    while ( v15 );
  }
  if ( v2 < m_cDeflectors )
  {
    v16 = 32 * v12;
    v17 = m_cDeflectors - v2;
    do
    {
      v16 += 32i64;
      *(float *)((char *)&this->m_pDeflectorInfo[-1] + v16 - 4) = *(float *)((char *)&this->m_pDeflectorInfo[-1]
                                                                           + v16
                                                                           - 4)
                                                                - v6;
      --v17;
    }
    while ( v17 );
  }
}

// File Line: 407
// RVA: 0xAD8010
float __fastcall CAkSoundSeedWindProcess::EqualizeTunable(
        CAkSoundSeedWindProcess *this,
        float in_fCenterFrequency,
        float in_fQ)
{
  float v4; // xmm8_4
  float v5; // xmm7_4
  float v6; // xmm6_4

  v4 = fsqrt(in_fCenterFrequency);
  v5 = logf(in_fCenterFrequency / in_fQ) * 1.442695;
  v6 = expf(
         (float)((float)((float)((float)(in_fCenterFrequency / in_fQ) * 2.0) * 3.1415927)
               / (float)(int)this->m_uSampleRate)
       * -0.5);
  if ( v6 >= 0.99919999 )
    v6 = FLOAT_0_99919999;
  return (float)((float)(expf((float)((float)(v5 * -0.023) * v5) + (float)((float)(v5 * -0.1648) + 3.9542999))
                       + 0.69999999)
               * v4)
       * (float)((float)(1.0 - (float)(v6 * v6)) * 0.5);
}

// File Line: 423
// RVA: 0xAD7520
float __fastcall CAkSoundSeedWindProcess::ComputeCombinedGain(
        CAkSoundSeedWindProcess *this,
        float in_fDeflectorGain,
        float in_fDistance,
        float in_fVelocity,
        float in_fCenterFrequency,
        float in_fQfactor)
{
  AkWindParams *m_pParams; // rbx
  float v8; // xmm11_4
  float v9; // xmm8_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4

  m_pParams = this->m_pParams;
  v8 = CAkSoundSeedWindProcess::EqualizeTunable(this, in_fCenterFrequency, in_fQfactor);
  if ( in_fDistance > m_pParams->fMinDistance )
  {
    v10 = (float)(logf(in_fDistance / m_pParams->fMinDistance) * 1.442695)
        * (float)(m_pParams->fAttenuationRolloff * -6.0);
    v9 = powf(10.0, v10 * 0.050000001);
  }
  else
  {
    v9 = *(float *)&FLOAT_1_0;
  }
  v11 = FLOAT_48_0;
  v12 = (float)((float)(m_pParams->fDynamicRange + 1.0) * 48.0) * 0.041524101;
  if ( (_S1_38 & 1) != 0 )
  {
    v11 = fMaxVelocity;
  }
  else
  {
    fMaxVelocity = FLOAT_48_0;
    _S1_38 |= 1u;
  }
  return (float)((float)(powf(in_fVelocity / v11, v12) * v9) * in_fDeflectorGain) * v8;
}

// File Line: 453
// RVA: 0xAD7650
void __fastcall CAkSoundSeedWindProcess::InitDeflectorGainRamp(CAkSoundSeedWindProcess *this)
{
  unsigned int m_cDeflectors; // r13d
  unsigned int v2; // r12d
  unsigned int v4; // esi
  float v5; // xmm7_4
  __int64 v6; // rbp
  __int64 v7; // r15
  DeflectorInfo *m_pDeflectorInfo; // rbx
  AkWindParams *m_pParams; // r14
  float v10; // xmm11_4
  float fDistance; // xmm6_4
  float fMinDistance; // xmm8_4
  float v13; // xmm12_4
  float v14; // xmm6_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  __int64 v17; // r8
  unsigned int v18; // edx
  float v19; // xmm0_4
  float v20; // xmm0_4
  char *v21; // rdx

  m_cDeflectors = this->m_cDeflectors;
  v2 = 0;
  if ( m_cDeflectors )
  {
    v4 = _S1_38;
    v5 = fMaxVelocity;
    v6 = 0i64;
    v7 = 0i64;
    do
    {
      m_pDeflectorInfo = this->m_pDeflectorInfo;
      m_pParams = this->m_pParams;
      v10 = *(float *)((char *)&m_pDeflectorInfo->fEffectiveFrequency + v6);
      fDistance = this->m_pDeflectors[v7].fDistance;
      fMinDistance = m_pParams->fMinDistance;
      v13 = CAkSoundSeedWindProcess::EqualizeTunable(
              this,
              *(float *)((char *)&m_pDeflectorInfo->fEffectiveQFactor + v6),
              *(float *)((char *)&m_pDeflectorInfo->fEffectiveGain + v6));
      if ( fDistance > fMinDistance )
      {
        v15 = (float)(logf(fDistance / fMinDistance) * 1.442695) * (float)(m_pParams->fAttenuationRolloff * -6.0);
        v14 = powf(10.0, v15 * 0.050000001);
      }
      else
      {
        v14 = *(float *)&FLOAT_1_0;
      }
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        v5 = FLOAT_48_0;
      }
      v16 = powf(v10 / v5, (float)((float)(m_pParams->fDynamicRange + 1.0) * 48.0) * 0.041524101);
      v17 = v2 & 3;
      v18 = v2++;
      v19 = (float)(v16 * v14) * *(float *)((char *)&m_pDeflectorInfo->fRandomFrequency + v6);
      ++v7;
      v6 += 32i64;
      v20 = v19 * v13;
      v21 = (char *)this->m_pDeflectorDSPInfo + this->m_uDSPInfoSize * (v18 >> 2);
      *(float *)&v21[4 * v17 + 32] = v20;
      *(float *)&v21[4 * v17] = v20;
      *(_DWORD *)&v21[4 * v17 + 16] = 0;
    }
    while ( v2 < m_cDeflectors );
    fMaxVelocity = v5;
    _S1_38 = v4;
    this->m_bFirstExecution = 0;
  }
  else
  {
    this->m_bFirstExecution = 0;
  }
}

// File Line: 483
// RVA: 0xAD78B0
void __fastcall CAkSoundSeedWindProcess::ComputeDeflectorGains(CAkSoundSeedWindProcess *this, int in_uNumFrames)
{
  unsigned int m_cDeflectors; // r13d
  unsigned int v3; // r15d
  unsigned int v5; // edi
  float v6; // xmm8_4
  __int64 v7; // rbp
  __int64 v8; // r12
  float v9; // xmm13_4
  DeflectorInfo *m_pDeflectorInfo; // rbx
  AkWindParams *m_pParams; // r14
  float v12; // xmm11_4
  float fDistance; // xmm6_4
  float fMinDistance; // xmm7_4
  float v15; // xmm12_4
  float v16; // xmm6_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  __int64 v19; // r8
  unsigned int v20; // edx
  float v21; // xmm1_4
  float v22; // xmm1_4
  char *v23; // rdx
  float v24; // xmm0_4

  m_cDeflectors = this->m_cDeflectors;
  v3 = 0;
  if ( m_cDeflectors )
  {
    v5 = _S1_38;
    v6 = fMaxVelocity;
    v7 = 0i64;
    v8 = 0i64;
    v9 = 1.0 / (float)in_uNumFrames;
    do
    {
      m_pDeflectorInfo = this->m_pDeflectorInfo;
      m_pParams = this->m_pParams;
      v12 = *(float *)((char *)&m_pDeflectorInfo->fEffectiveFrequency + v7);
      fDistance = this->m_pDeflectors[v8].fDistance;
      fMinDistance = m_pParams->fMinDistance;
      v15 = CAkSoundSeedWindProcess::EqualizeTunable(
              this,
              *(float *)((char *)&m_pDeflectorInfo->fEffectiveQFactor + v7),
              *(float *)((char *)&m_pDeflectorInfo->fEffectiveGain + v7));
      if ( fDistance > fMinDistance )
      {
        v17 = (float)(logf(fDistance / fMinDistance) * 1.442695) * (float)(m_pParams->fAttenuationRolloff * -6.0);
        v16 = powf(10.0, v17 * 0.050000001);
      }
      else
      {
        v16 = *(float *)&FLOAT_1_0;
      }
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        v6 = FLOAT_48_0;
      }
      v18 = powf(v12 / v6, (float)((float)(m_pParams->fDynamicRange + 1.0) * 48.0) * 0.041524101);
      v19 = v3 & 3;
      v20 = v3++;
      v21 = (float)(v18 * v16) * *(float *)((char *)&m_pDeflectorInfo->fRandomFrequency + v7);
      ++v8;
      v7 += 32i64;
      v22 = v21 * v15;
      v23 = (char *)this->m_pDeflectorDSPInfo + this->m_uDSPInfoSize * (v20 >> 2);
      v24 = v22 - *(float *)&v23[4 * v19];
      *(float *)&v23[4 * v19 + 32] = v22;
      *(float *)&v23[4 * v19 + 16] = v24 * v9;
    }
    while ( v3 < m_cDeflectors );
    fMaxVelocity = v6;
    _S1_38 = v5;
  }
}

// File Line: 511
// RVA: 0xAD7B10
void __fastcall CAkSoundSeedWindProcess::DeflectorGainRampCompleted(CAkSoundSeedWindProcess *this)
{
  signed int m_cDeflectors; // r11d
  unsigned int v2; // r9d
  unsigned int v3; // ebx
  __int64 v4; // r8
  unsigned int v5; // edx
  char *v6; // rdx
  __int64 v7; // r8
  char *v8; // rdx
  __int64 v9; // r8
  char *v10; // rdx
  __int64 v11; // r8
  char *v12; // rdx
  __int64 v13; // r8
  unsigned int v14; // edx
  char *v15; // rdx
  int v16; // eax

  m_cDeflectors = this->m_cDeflectors;
  v2 = 0;
  if ( m_cDeflectors >= 4 )
  {
    v3 = 1;
    do
    {
      v4 = v2 & 3;
      v5 = v2 >> 2;
      v2 += 4;
      v6 = (char *)this->m_pDeflectorDSPInfo + this->m_uDSPInfoSize * v5;
      *(_DWORD *)&v6[4 * v4 + 16] = 0;
      *(_DWORD *)&v6[4 * v4] = *(_DWORD *)&v6[4 * v4 + 32];
      v7 = v3 & 3;
      v8 = (char *)this->m_pDeflectorDSPInfo + this->m_uDSPInfoSize * (v3 >> 2);
      *(_DWORD *)&v8[4 * v7 + 16] = 0;
      *(_DWORD *)&v8[4 * v7] = *(_DWORD *)&v8[4 * v7 + 32];
      v9 = ((_BYTE)v3 + 1) & 3;
      v10 = (char *)this->m_pDeflectorDSPInfo + this->m_uDSPInfoSize * ((v3 + 1) >> 2);
      *(_DWORD *)&v10[4 * v9 + 16] = 0;
      *(_DWORD *)&v10[4 * v9] = *(_DWORD *)&v10[4 * v9 + 32];
      v11 = ((_BYTE)v3 - 2) & 3;
      LODWORD(v10) = v3 + 2;
      v3 += 4;
      v12 = (char *)this->m_pDeflectorDSPInfo + this->m_uDSPInfoSize * ((unsigned int)v10 >> 2);
      *(_DWORD *)&v12[4 * v11 + 16] = 0;
      *(_DWORD *)&v12[4 * v11] = *(_DWORD *)&v12[4 * v11 + 32];
    }
    while ( v2 < m_cDeflectors - 3 );
  }
  for ( ; v2 < m_cDeflectors; *(_DWORD *)&v15[4 * v13] = v16 )
  {
    v13 = v2 & 3;
    v14 = v2++ >> 2;
    v15 = (char *)this->m_pDeflectorDSPInfo + this->m_uDSPInfoSize * v14;
    v16 = *(_DWORD *)&v15[4 * v13 + 32];
    *(_DWORD *)&v15[4 * v13 + 16] = 0;
  }
}

// File Line: 660
// RVA: 0xAD7C40
void __fastcall CAkSoundSeedWindProcess::ComputeEffectiveDirection(
        CAkSoundSeedWindProcess *this,
        float in_fAutomationValue)
{
  this->m_fEffectiveParamValue[1] = (float)(this->m_pParams->fBaseValue[1] + this->m_fRandomParamValue[1])
                                  + in_fAutomationValue;
}

// File Line: 669
// RVA: 0xAD7C60
void __fastcall CAkSoundSeedWindProcess::ComputeEffectiveFrequencyScale(
        CAkSoundSeedWindProcess *this,
        float in_fAutomationValue)
{
  float v3; // xmm7_4
  unsigned int m_cDeflectors; // eax
  __int64 v5; // rdi
  __int64 v6; // r14
  __int64 v7; // rbp
  DeflectorInfo *m_pDeflectorInfo; // rbx
  float v9; // xmm0_4

  v3 = this->m_pParams->fBaseValue[4];
  m_cDeflectors = this->m_cDeflectors;
  if ( m_cDeflectors )
  {
    v5 = 0i64;
    v6 = m_cDeflectors;
    v7 = 0i64;
    do
    {
      m_pDeflectorInfo = this->m_pDeflectorInfo;
      v9 = powf(2.0, (float)(v3 + *(float *)((char *)&m_pDeflectorInfo->fRandomQFactor + v5)) + in_fAutomationValue);
      v5 += 32i64;
      *(float *)((char *)m_pDeflectorInfo + v5 - 24) = v9 * this->m_pDeflectors[v7++].fFrequency;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 682
// RVA: 0xAD7D20
void __fastcall CAkSoundSeedWindProcess::ComputeEffectiveQFactorScale(
        CAkSoundSeedWindProcess *this,
        float in_fAutomationValue)
{
  float v3; // xmm9_4
  unsigned int m_cDeflectors; // eax
  __int64 v5; // rbx
  __int64 v6; // rsi
  __int64 v7; // rdi
  DeflectorInfo *m_pDeflectorInfo; // rbp
  float v9; // xmm0_4

  v3 = this->m_pParams->fBaseValue[5];
  m_cDeflectors = this->m_cDeflectors;
  if ( m_cDeflectors )
  {
    v5 = 0i64;
    v6 = m_cDeflectors;
    v7 = 0i64;
    do
    {
      m_pDeflectorInfo = this->m_pDeflectorInfo;
      v9 = powf(2.0, (float)(v3 + *(float *)((char *)&m_pDeflectorInfo->fRandomGain + v5)) + in_fAutomationValue)
         * this->m_pDeflectors[v7].fQFactor;
      if ( v9 < 50.0 )
      {
        if ( v9 <= 0.1 )
          v9 = FLOAT_0_1;
      }
      else
      {
        v9 = FLOAT_50_0;
      }
      *(float *)((char *)&m_pDeflectorInfo->fEffectiveGain + v5) = v9;
      v5 += 32i64;
      ++v7;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 700
// RVA: 0xAD7E30
void __fastcall CAkSoundSeedWindProcess::ComputeEffectiveGainOffset(
        CAkSoundSeedWindProcess *this,
        float in_fAutomationValue)
{
  float v3; // xmm6_4
  float v4; // xmm0_4
  signed int m_cDeflectors; // r10d
  unsigned int v6; // r11d
  __int64 v7; // rdi
  float v8; // xmm3_4
  __int64 v9; // rcx
  __int64 v10; // rdx
  unsigned int v11; // eax
  __int64 v12; // r9
  DeflectorInfo *m_pDeflectorInfo; // r8
  float v14; // xmm0_4
  DeflectorInfo *v15; // r8
  float v16; // xmm0_4
  DeflectorInfo *v17; // r8
  float v18; // xmm0_4
  DeflectorInfo *v19; // r8
  float v20; // xmm0_4
  float v21; // xmm0_4
  __int64 v22; // rdx
  __int64 v23; // rcx
  __int64 v24; // r9
  DeflectorInfo *v25; // r8
  float v26; // xmm0_4
  float v27; // xmm0_4

  v3 = this->m_pParams->fBaseValue[6];
  v4 = powf(10.0, in_fAutomationValue * 0.050000001);
  m_cDeflectors = this->m_cDeflectors;
  v6 = 0;
  v7 = 0i64;
  v8 = v4;
  if ( m_cDeflectors >= 4 )
  {
    v9 = 0i64;
    v10 = 0i64;
    v11 = ((unsigned int)(m_cDeflectors - 4) >> 2) + 1;
    v12 = v11;
    v6 = 4 * v11;
    v7 = 4i64 * v11;
    do
    {
      m_pDeflectorInfo = this->m_pDeflectorInfo;
      v14 = (float)(v3 * *(float *)((char *)&m_pDeflectorInfo[1].fVelocity + v9)) * v8;
      if ( v14 < 16.0 )
      {
        if ( v14 <= 0.0 )
          v14 = 0.0;
      }
      else
      {
        v14 = FLOAT_16_0;
      }
      *(float *)((char *)&m_pDeflectorInfo->fRandomFrequency + v9) = v14 * this->m_pDeflectors[v10].fGain;
      v15 = this->m_pDeflectorInfo;
      v16 = (float)(v3 * *(float *)((char *)&v15[2].fEffectiveFrequency + v9)) * v8;
      if ( v16 < 16.0 )
      {
        if ( v16 <= 0.0 )
          v16 = 0.0;
      }
      else
      {
        v16 = FLOAT_16_0;
      }
      *(float *)((char *)&v15[1].fRandomQFactor + v9) = v16 * this->m_pDeflectors[v10 + 1].fGain;
      v17 = this->m_pDeflectorInfo;
      v18 = (float)(v3 * *(float *)((char *)&v17[3].fEffectiveQFactor + v9)) * v8;
      if ( v18 < 16.0 )
      {
        if ( v18 <= 0.0 )
          v18 = 0.0;
      }
      else
      {
        v18 = FLOAT_16_0;
      }
      *(float *)((char *)&v17[2].fRandomGain + v9) = v18 * this->m_pDeflectors[v10 + 2].fGain;
      v19 = this->m_pDeflectorInfo;
      v20 = (float)(v3 * *(float *)((char *)&v19[4].fEffectiveGain + v9)) * v8;
      if ( v20 < 16.0 )
      {
        if ( v20 <= 0.0 )
          v20 = 0.0;
      }
      else
      {
        v20 = FLOAT_16_0;
      }
      v21 = v20 * this->m_pDeflectors[v10 + 3].fGain;
      v9 += 128i64;
      v10 += 4i64;
      *(float *)((char *)v19 + v9 - 16) = v21;
      --v12;
    }
    while ( v12 );
  }
  if ( v6 < m_cDeflectors )
  {
    v22 = v7;
    v23 = 32 * v7;
    v24 = m_cDeflectors - v6;
    do
    {
      v25 = this->m_pDeflectorInfo;
      v26 = (float)(v3 * *(float *)((char *)&v25[1].fVelocity + v23)) * v8;
      if ( v26 < 16.0 )
      {
        if ( v26 <= 0.0 )
          v26 = 0.0;
      }
      else
      {
        v26 = FLOAT_16_0;
      }
      v27 = v26 * this->m_pDeflectors[v22].fGain;
      v23 += 32i64;
      ++v22;
      *(float *)((char *)v25 + v23 - 16) = v27;
      --v24;
    }
    while ( v24 );
  }
}

// File Line: 725
// RVA: 0xAD8100
void __fastcall CAkSoundSeedWindProcess::ProcessMono(
        CAkSoundSeedWindProcess *this,
        AkAudioBuffer *io_pBufferOut,
        float *in_pfTempStorage)
{
  unsigned int uValidFrames; // ebp
  __int64 v4; // r15
  unsigned int v7; // r12d
  DSP::CAkPinkNoise *p_m_NoiseGen; // rax
  unsigned int v10; // ebx
  __int64 v11; // r9
  __int64 v12; // r10
  __int64 v13; // rax
  char *m_pDeflectorDSPInfo; // r11
  float *v15; // rdx
  __m128 v16; // xmm3
  __m128 v17; // xmm6
  __m128 v18; // xmm7
  __m128 v19; // xmm8
  __m128 v20; // xmm4
  __m128 v21; // xmm5
  float *v22; // rcx
  __int64 v23; // r8
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm0
  float *v28; // rdx
  float *v29; // r8
  __int64 v30; // rax
  __m128 v31; // xmm1
  __m128 v32; // xmm1

  uValidFrames = io_pBufferOut->uValidFrames;
  v4 = 0i64;
  v7 = (this->m_cDeflectors + 3) >> 2;
  if ( io_pBufferOut->uValidFrames )
  {
    p_m_NoiseGen = &this->m_NoiseGen;
    do
    {
      v10 = 1024;
      if ( uValidFrames < 0x400 )
        v10 = uValidFrames;
      DSP::CAkPinkNoise::GenerateBuffer(p_m_NoiseGen, in_pfTempStorage, v10);
      memset(in_pfTempStorage + 1024, 0, 0x4000ui64);
      if ( v7 )
      {
        v11 = 0i64;
        v12 = v7;
        v13 = 0i64;
        do
        {
          m_pDeflectorDSPInfo = (char *)this->m_pDeflectorDSPInfo;
          v15 = in_pfTempStorage + 1024;
          v16 = *(__m128 *)&m_pDeflectorDSPInfo[v11];
          v17 = *(__m128 *)&m_pDeflectorDSPInfo[v11 + 16];
          v18 = *(__m128 *)&m_pDeflectorDSPInfo[v11 + 48];
          v19 = *(__m128 *)&m_pDeflectorDSPInfo[v11 + 64];
          v20 = *(__m128 *)&m_pDeflectorDSPInfo[v11 + 80];
          v21 = *(__m128 *)&m_pDeflectorDSPInfo[v11 + 96];
          if ( v10 )
          {
            v22 = in_pfTempStorage;
            v23 = v10;
            do
            {
              v24 = (__m128)*(unsigned int *)v22;
              v16 = _mm_add_ps(v16, v17);
              v15 += 4;
              ++v22;
              v25 = _mm_mul_ps(v21, v19);
              v26 = _mm_add_ps(_mm_mul_ps(v20, v18), _mm_shuffle_ps(v24, v24, 0));
              v27 = v21;
              v21 = v20;
              v20 = _mm_add_ps(v26, v25);
              *((__m128 *)v15 - 1) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v20, v27), v16), *(__m128 *)(v15 - 4));
              --v23;
            }
            while ( v23 );
          }
          *(__m128 *)&m_pDeflectorDSPInfo[v13 + 80] = v20;
          v13 += 112i64;
          v11 += 112i64;
          *(__m128 *)((char *)this->m_pDeflectorDSPInfo + v13 - 16) = v21;
          *(__m128 *)((char *)this->m_pDeflectorDSPInfo + v13 - 112) = v16;
          --v12;
        }
        while ( v12 );
      }
      v28 = in_pfTempStorage + 1024;
      v29 = (float *)((char *)io_pBufferOut->pData + 4 * v4);
      if ( v10 )
      {
        v30 = v10;
        do
        {
          v31 = *(__m128 *)v28;
          ++v29;
          v28 += 4;
          v32 = _mm_add_ps(v31, _mm_movehl_ps(v31, v31));
          *(v29 - 1) = _mm_shuffle_ps(v32, v32, 85).m128_f32[0] + v32.m128_f32[0];
          --v30;
        }
        while ( v30 );
      }
      v4 = v10 + (unsigned int)v4;
      p_m_NoiseGen = &this->m_NoiseGen;
      uValidFrames -= v10;
    }
    while ( uValidFrames );
  }
}

// File Line: 818
// RVA: 0xAD82F0
void __fastcall CAkSoundSeedWindProcess::ProcessStereo(
        CAkSoundSeedWindProcess *this,
        AkAudioBuffer *io_pBufferOut,
        float *in_pfTempStorage)
{
  unsigned int uValidFrames; // ebp
  __int64 v4; // r15
  unsigned int v7; // r12d
  DSP::CAkPinkNoise *p_m_NoiseGen; // rcx
  unsigned int v10; // ebx
  __int64 v11; // r8
  __int64 v12; // r10
  __int64 v13; // rax
  char *m_pDeflectorDSPInfo; // r11
  float *v15; // rcx
  __m128 v16; // xmm3
  __m128 v17; // xmm6
  __m128 v18; // xmm7
  __m128 v19; // xmm8
  __m128 v20; // xmm4
  __m128 v21; // xmm5
  __m128 v22; // xmm9
  __m128 v23; // xmm10
  float *v24; // rdx
  __int64 v25; // r9
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  __m128 v29; // xmm0
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm0
  char *pData; // r9
  float *v34; // rax
  float *v35; // rcx
  __int64 v36; // rdx
  __m128 v37; // xmm1
  __m128 v38; // xmm1
  float *v39; // rcx
  float *v40; // rdx
  __int64 v41; // rax
  __m128 v42; // xmm1
  __m128 v43; // xmm1

  uValidFrames = io_pBufferOut->uValidFrames;
  v4 = 0i64;
  v7 = (this->m_cDeflectors + 3) >> 2;
  if ( io_pBufferOut->uValidFrames )
  {
    p_m_NoiseGen = &this->m_NoiseGen;
    do
    {
      v10 = 1024;
      if ( uValidFrames < 0x400 )
        v10 = uValidFrames;
      DSP::CAkPinkNoise::GenerateBuffer(p_m_NoiseGen, in_pfTempStorage, v10);
      memset(in_pfTempStorage + 1024, 0, 0x8000ui64);
      if ( v7 )
      {
        v11 = 0i64;
        v12 = v7;
        v13 = 0i64;
        do
        {
          m_pDeflectorDSPInfo = (char *)this->m_pDeflectorDSPInfo;
          v15 = in_pfTempStorage + 1024;
          v16 = *(__m128 *)&m_pDeflectorDSPInfo[v11];
          v17 = *(__m128 *)&m_pDeflectorDSPInfo[v11 + 16];
          v18 = *(__m128 *)&m_pDeflectorDSPInfo[v11 + 48];
          v19 = *(__m128 *)&m_pDeflectorDSPInfo[v11 + 64];
          v20 = *(__m128 *)&m_pDeflectorDSPInfo[v11 + 80];
          v21 = *(__m128 *)&m_pDeflectorDSPInfo[v11 + 96];
          v22 = *(__m128 *)&m_pDeflectorDSPInfo[v11 + 112];
          v23 = *(__m128 *)&m_pDeflectorDSPInfo[v11 + 128];
          if ( v10 )
          {
            v24 = in_pfTempStorage;
            v25 = v10;
            do
            {
              v26 = (__m128)*(unsigned int *)v24;
              v16 = _mm_add_ps(v16, v17);
              v15 += 8;
              ++v24;
              v27 = _mm_mul_ps(v21, v19);
              v28 = _mm_add_ps(_mm_mul_ps(v20, v18), _mm_shuffle_ps(v26, v26, 0));
              v29 = v21;
              v21 = v20;
              v20 = _mm_add_ps(v28, v27);
              v30 = _mm_mul_ps(_mm_sub_ps(v20, v29), v16);
              v31 = _mm_mul_ps(v30, v22);
              v32 = _mm_add_ps(_mm_mul_ps(v30, v23), *(__m128 *)(v15 - 4));
              *((__m128 *)v15 - 2) = _mm_add_ps(v31, *(__m128 *)(v15 - 8));
              *((__m128 *)v15 - 1) = v32;
              --v25;
            }
            while ( v25 );
          }
          *(__m128 *)&m_pDeflectorDSPInfo[v13 + 80] = v20;
          v13 += 144i64;
          v11 += 144i64;
          *(__m128 *)((char *)this->m_pDeflectorDSPInfo + v13 - 48) = v21;
          *(__m128 *)((char *)this->m_pDeflectorDSPInfo + v13 - 144) = v16;
          --v12;
        }
        while ( v12 );
      }
      pData = (char *)io_pBufferOut->pData;
      v34 = in_pfTempStorage + 1024;
      v35 = (float *)((char *)io_pBufferOut->pData + 4 * v4);
      if ( v10 )
      {
        v36 = v10;
        do
        {
          v37 = *(__m128 *)v34;
          ++v35;
          v34 += 8;
          v38 = _mm_add_ps(v37, _mm_movehl_ps(v37, v37));
          *(v35 - 1) = _mm_shuffle_ps(v38, v38, 85).m128_f32[0] + v38.m128_f32[0];
          --v36;
        }
        while ( v36 );
      }
      v39 = in_pfTempStorage + 1028;
      v40 = (float *)&pData[4 * (unsigned int)v4 + 4 * (unsigned __int64)io_pBufferOut->uMaxFrames];
      if ( v10 )
      {
        v41 = v10;
        do
        {
          v42 = *(__m128 *)v39;
          ++v40;
          v39 += 8;
          v43 = _mm_add_ps(v42, _mm_movehl_ps(v42, v42));
          *(v40 - 1) = _mm_shuffle_ps(v43, v43, 85).m128_f32[0] + v43.m128_f32[0];
          --v41;
        }
        while ( v41 );
      }
      v4 = v10 + (unsigned int)v4;
      p_m_NoiseGen = &this->m_NoiseGen;
      uValidFrames -= v10;
    }
    while ( uValidFrames );
  }
}

// File Line: 943
// RVA: 0xAD8560
void __fastcall CAkSoundSeedWindProcess::ProcessQuad(
        CAkSoundSeedWindProcess *this,
        AkAudioBuffer *io_pBufferOut,
        float *in_pfTempStorage)
{
  unsigned int uValidFrames; // ebx
  unsigned int v4; // esi
  AkAudioBuffer *v6; // r15
  unsigned int v7; // ebp
  DSP::CAkPinkNoise *p_m_NoiseGen; // rax
  unsigned int v10; // edi
  __int64 v11; // rsi
  __int64 v12; // r15
  __int64 v13; // rbx
  char *m_pDeflectorDSPInfo; // rbp
  __int128 *v15; // rcx
  char *v16; // rdx
  __int64 v17; // rax
  __int128 v18; // xmm0
  __int128 v19; // xmm1
  __int128 v20; // xmm0
  __int128 v21; // xmm1
  __int128 v22; // xmm0
  __int128 v23; // xmm1
  __int128 v24; // xmm0
  __int128 v25; // xmm1
  __int128 v26; // xmm1
  __int128 v27; // xmm0
  __m128 v28; // xmm3
  __m128 v29; // xmm6
  __m128 v30; // xmm7
  __m128 v31; // xmm8
  __m128 v32; // xmm4
  __m128 v33; // xmm5
  __m128 v34; // xmm9
  __m128 v35; // xmm10
  __m128 v36; // xmm11
  __m128 v37; // xmm12
  float *v38; // rax
  float *v39; // rcx
  __int64 v40; // rdx
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm0
  __m128 v45; // xmm2
  __m128 v46; // xmm1
  __m128 v47; // xmm0
  float *v48; // r8
  __int64 v49; // r10
  __int64 v50; // r9
  __int64 v51; // r11
  __m128 *v52; // rax
  __int64 v53; // rcx
  __int64 v54; // rdx
  __m128 v55; // xmm1
  __m128 v56; // xmm1
  __int128 Dst[11]; // [rsp+20h] [rbp-168h] BYREF
  unsigned int v58; // [rsp+190h] [rbp+8h]
  unsigned int v60; // [rsp+1A0h] [rbp+18h]
  unsigned int v61; // [rsp+1A8h] [rbp+20h]

  uValidFrames = io_pBufferOut->uValidFrames;
  v4 = 0;
  v6 = io_pBufferOut;
  v7 = (this->m_cDeflectors + 3) >> 2;
  v58 = 0;
  v61 = v7;
  v60 = uValidFrames;
  if ( io_pBufferOut->uValidFrames )
  {
    p_m_NoiseGen = &this->m_NoiseGen;
    do
    {
      v10 = 1024;
      if ( uValidFrames < 0x400 )
        v10 = uValidFrames;
      DSP::CAkPinkNoise::GenerateBuffer(p_m_NoiseGen, in_pfTempStorage, v10);
      memset(in_pfTempStorage + 1024, 0, 0x10000ui64);
      if ( v7 )
      {
        v11 = 0i64;
        v12 = v7;
        v13 = 0i64;
        do
        {
          m_pDeflectorDSPInfo = (char *)this->m_pDeflectorDSPInfo;
          v15 = Dst;
          v16 = &m_pDeflectorDSPInfo[v11];
          if ( (((unsigned __int8)Dst | (unsigned __int8)(v11 + (_BYTE)m_pDeflectorDSPInfo)) & 0xF) != 0 )
          {
            memmove(Dst, v16, 0xB0ui64);
          }
          else
          {
            v17 = 1i64;
            do
            {
              v18 = *(_OWORD *)v16;
              v19 = *((_OWORD *)v16 + 1);
              v15 += 8;
              v16 += 128;
              *(v15 - 8) = v18;
              v20 = *((_OWORD *)v16 - 6);
              *(v15 - 7) = v19;
              v21 = *((_OWORD *)v16 - 5);
              *(v15 - 6) = v20;
              v22 = *((_OWORD *)v16 - 4);
              *(v15 - 5) = v21;
              v23 = *((_OWORD *)v16 - 3);
              *(v15 - 4) = v22;
              v24 = *((_OWORD *)v16 - 2);
              *(v15 - 3) = v23;
              v25 = *((_OWORD *)v16 - 1);
              *(v15 - 2) = v24;
              *(v15 - 1) = v25;
              --v17;
            }
            while ( v17 );
            v26 = *((_OWORD *)v16 + 1);
            *v15 = *(_OWORD *)v16;
            v27 = *((_OWORD *)v16 + 2);
            v15[1] = v26;
            v15[2] = v27;
          }
          v28 = (__m128)Dst[0];
          v29 = (__m128)Dst[1];
          v30 = (__m128)Dst[3];
          v31 = (__m128)Dst[4];
          v32 = (__m128)Dst[5];
          v33 = (__m128)Dst[6];
          v34 = (__m128)Dst[7];
          v35 = (__m128)Dst[8];
          v36 = (__m128)Dst[9];
          v37 = (__m128)Dst[10];
          if ( v10 )
          {
            v38 = in_pfTempStorage + 1032;
            v39 = in_pfTempStorage;
            v40 = v10;
            do
            {
              v41 = (__m128)*(unsigned int *)v39;
              v28 = _mm_add_ps(v28, v29);
              v38 += 16;
              ++v39;
              v42 = _mm_mul_ps(v33, v31);
              v43 = _mm_add_ps(_mm_mul_ps(v32, v30), _mm_shuffle_ps(v41, v41, 0));
              v44 = v33;
              v33 = v32;
              v32 = _mm_add_ps(v43, v42);
              v45 = _mm_mul_ps(_mm_sub_ps(v32, v44), v28);
              v46 = _mm_add_ps(_mm_mul_ps(v45, v35), *(__m128 *)(v38 - 20));
              *((__m128 *)v38 - 6) = _mm_add_ps(_mm_mul_ps(v45, v34), *(__m128 *)(v38 - 24));
              *((__m128 *)v38 - 5) = v46;
              v47 = _mm_add_ps(_mm_mul_ps(v45, v37), *(__m128 *)(v38 - 12));
              *((__m128 *)v38 - 4) = _mm_add_ps(_mm_mul_ps(v45, v36), *(__m128 *)(v38 - 16));
              *((__m128 *)v38 - 3) = v47;
              --v40;
            }
            while ( v40 );
          }
          *(__m128 *)&m_pDeflectorDSPInfo[v13 + 80] = v32;
          v13 += 176i64;
          v11 += 176i64;
          *(__m128 *)((char *)this->m_pDeflectorDSPInfo + v13 - 80) = v33;
          *(__m128 *)((char *)this->m_pDeflectorDSPInfo + v13 - 176) = v28;
          --v12;
        }
        while ( v12 );
        uValidFrames = v60;
        v4 = v58;
        v7 = v61;
        v6 = io_pBufferOut;
      }
      v48 = in_pfTempStorage + 1024;
      v49 = 4i64;
      v50 = (__int64)v6->pData + 4 * v4;
      v51 = 4i64 * v6->uMaxFrames;
      do
      {
        v52 = (__m128 *)v48;
        v53 = v50;
        if ( v10 )
        {
          v54 = v10;
          do
          {
            v55 = *v52;
            v53 += 4i64;
            v52 += 4;
            v56 = _mm_add_ps(v55, _mm_movehl_ps(v55, v55));
            *(float *)(v53 - 4) = _mm_shuffle_ps(v56, v56, 85).m128_f32[0] + v56.m128_f32[0];
            --v54;
          }
          while ( v54 );
        }
        v48 += 4;
        v50 += v51;
        --v49;
      }
      while ( v49 );
      v4 += v10;
      uValidFrames -= v10;
      p_m_NoiseGen = &this->m_NoiseGen;
      v60 = uValidFrames;
      v58 = v4;
    }
    while ( uValidFrames );
  }
}


// File Line: 38
// RVA: 0xAD6450
void __fastcall CAkSoundSeedWindProcess::CAkSoundSeedWindProcess(CAkSoundSeedWindProcess *this)
{
  CAkSoundSeedWindProcess *v1; // rbx

  v1 = this;
  this->m_pParams = 0i64;
  this->m_pDeflectors = 0i64;
  this->m_pDeflectorInfo = 0i64;
  this->m_pDeflectorDSPInfo = 0i64;
  this->m_RandGenerator.m_uLCGState = rand();
  DSP::CAkPinkNoise::CAkPinkNoise(&v1->m_NoiseGen);
}

// File Line: 43
// RVA: 0xAD6490
void __fastcall CAkSoundSeedWindProcess::~CAkSoundSeedWindProcess(CAkSoundSeedWindProcess *this)
{
  ;
}

// File Line: 50
// RVA: 0xAD64A0
void __fastcall CAkSoundSeedWindProcess::Setup(CAkSoundSeedWindProcess *this, AkWindParams *in_pParams, AkAudioFormat *io_rFormat)
{
  CAkSoundSeedWindProcess *v3; // r10
  unsigned int v4; // er9
  unsigned int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  unsigned int i; // ecx
  unsigned int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  signed __int16 v13; // ax
  float v14; // xmm1_4
  int v15; // eax
  float v16; // xmm1_4
  int v17; // eax
  float v18; // xmm2_4
  int v19; // eax
  float v20; // xmm1_4
  int v21; // eax

  v3 = this;
  this->m_uSampleRate = io_rFormat->uSampleRate;
  v4 = in_pParams->uChannelMask;
  *((_DWORD *)io_rFormat + 1) &= 0xFFFC0000;
  *((_DWORD *)io_rFormat + 1) |= v4 & 0x3FFFF;
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
            v4 = 3;
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
  for ( i = 0; v4; v4 &= v4 - 1 )
    ++i;
  v3->m_uNumChannels = i;
  *((_DWORD *)io_rFormat + 1) &= 0xE0FFFFFF;
  *((_DWORD *)io_rFormat + 1) |= (i << 26) & 0x1F000000;
  v10 = v3->m_uNumChannels;
  v3->m_NoiseGen.m_DCFilter.m_fA1 = 1.0 - (float)(251.32742 / (float)(signed int)v3->m_uSampleRate);
  v11 = v10 - 1;
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
    v3->m_uDSPInfoSize = v13;
  }
  v14 = in_pParams->fRandomValue[0];
  v15 = 214013 * v3->m_RandGenerator.m_uLCGState + 2531011;
  v3->m_RandGenerator.m_uLCGState = v15;
  v3->m_fRandomParamValue[0] = (float)((float)((float)((float)v15 * 2.3283064e-10) * 2.0) - 1.0) * v14;
  v16 = in_pParams->fRandomValue[1];
  v17 = 214013 * v3->m_RandGenerator.m_uLCGState + 2531011;
  v3->m_RandGenerator.m_uLCGState = v17;
  v3->m_fRandomParamValue[1] = (float)((float)((float)((float)v17 * 2.3283064e-10) * 2.0) - 1.0) * v16;
  v18 = in_pParams->fRandomValue[2];
  v19 = 214013 * v3->m_RandGenerator.m_uLCGState + 2531011;
  v3->m_RandGenerator.m_uLCGState = v19;
  v3->m_fRandomParamValue[2] = (float)((float)((float)((float)v19 * 2.3283064e-10) * 2.0) - 1.0) * v18;
  v20 = in_pParams->fRandomValue[3];
  v21 = 214013 * v3->m_RandGenerator.m_uLCGState + 2531011;
  v3->m_RandGenerator.m_uLCGState = v21;
  v3->m_fRandomParamValue[3] = (float)((float)((float)((float)v21 * 2.3283064e-10) * 2.0) - 1.0) * v20;
  v3->m_bFirstExecution = 1;
}

// File Line: 93
// RVA: 0xAD6970
void __fastcall CAkSoundSeedWindProcess::ComputeStereoGains(CAkSoundSeedWindProcess *this, unsigned int in_uIndex, float *out_fLeft, float *out_fRight)
{
  AkWindDeflectorParams *v4; // rbx
  signed __int64 v5; // rdi
  float *v6; // rbp
  float *v7; // rsi
  float v8; // xmm0_4
  float v9; // xmm7_4

  v4 = this->m_pDeflectors;
  v5 = in_uIndex;
  v6 = out_fRight;
  v7 = out_fLeft;
  v8 = powf(v4[in_uIndex].fDistance / this->m_pParams->fMaxDistance, 0.16666667);
  v9 = (float)((float)((float)(v8 * cosf((float)((float)(90.0 - v4[v5].fAngle) * 3.1415927) * 0.0055555557)) * 3.1415927)
             * 0.25)
     + 0.78539819;
  *v7 = cosf(v9);
  *v6 = sinf(v9);
}

// File Line: 106
// RVA: 0xAD6A30
void __fastcall CAkSoundSeedWindProcess::ComputeQuadGains(CAkSoundSeedWindProcess *this, unsigned int in_uIndex, float *out_fFrontLeft, float *out_fFrontRight, float *out_fRearLeft, float *out_fRearRight)
{
  __int64 v6; // rax
  AkWindDeflectorParams *v7; // rdx
  float *v8; // rdi
  float *v9; // rbx
  float v10; // xmm7_4
  float v11; // xmm10_4
  float v12; // xmm6_4
  float v13; // xmm11_4
  float v14; // xmm12_4
  float v15; // xmm7_4
  float v16; // xmm6_4
  float v17; // xmm0_4

  v6 = in_uIndex;
  v7 = this->m_pDeflectors;
  v8 = out_fFrontRight;
  v9 = out_fFrontLeft;
  v10 = (float)((float)(90.0 - v7[v6].fAngle) * 3.1415927) * 0.0055555557;
  v11 = powf(v7[v6].fDistance / this->m_pParams->fMaxDistance, 0.16666667);
  v12 = (float)((float)((float)(cosf(v10) * v11) * 3.1415927) * 0.25) + 0.78539819;
  v13 = cosf(v12);
  v14 = sinf(v12);
  v15 = (float)((float)((float)(sinf(v10) * v11) * 3.1415927) * 0.25) + 0.78539819;
  v16 = sinf(v15);
  v17 = cosf(v15);
  *v9 = v16 * v13;
  *v8 = v16 * v14;
  *out_fRearLeft = v17 * v13;
  *out_fRearRight = v17 * v14;
}

// File Line: 126
// RVA: 0xAD6B90
void __fastcall CAkSoundSeedWindProcess::InitSpatialization(CAkSoundSeedWindProcess *this)
{
  unsigned int v1; // er15
  CAkSoundSeedWindProcess *v2; // r14
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
  unsigned int v15; // er8
  char *v16; // r8
  unsigned int v17; // esi
  __int64 v18; // rbp
  AkWindDeflectorParams *v19; // rbx
  float v20; // xmm6_4
  float v21; // xmm0_4
  __int64 v22; // rbx
  char *v23; // rdi
  float v24; // xmm6_4

  v1 = this->m_cDeflectors;
  v2 = this;
  if ( this->m_uNumChannels == 2 )
  {
    v17 = 0;
    if ( v1 )
    {
      v18 = 0i64;
      do
      {
        v19 = v2->m_pDeflectors;
        v20 = powf(v19[v18].fDistance / v2->m_pParams->fMaxDistance, 0.16666667);
        v21 = cosf((float)((float)(90.0 - v19[v18].fAngle) * 3.1415927) * 0.0055555557);
        v22 = v17 & 3;
        v23 = (char *)v2->m_pDeflectorDSPInfo + v2->m_uDSPInfoSize * (v17 >> 2);
        v24 = (float)((float)((float)(v20 * v21) * 3.1415927) * 0.25) + 0.78539819;
        *(float *)&v23[4 * v22 + 112] = cosf(v24);
        ++v17;
        ++v18;
        *(float *)&v23[4 * v22 + 128] = sinf(v24);
      }
      while ( v17 < v1 );
    }
  }
  else if ( this->m_uNumChannels == 4 )
  {
    v3 = 0;
    if ( v1 )
    {
      v4 = 0i64;
      do
      {
        v5 = v2->m_pDeflectors;
        v6 = (float)((float)(90.0 - v5[v4].fAngle) * 3.1415927) * 0.0055555557;
        v7 = powf(v5[v4].fDistance / v2->m_pParams->fMaxDistance, 0.16666667);
        v8 = (float)((float)((float)(cosf(v6) * v7) * 3.1415927) * 0.25) + 0.78539819;
        v9 = cosf(v8);
        v10 = sinf(v8);
        v11 = (float)((float)((float)(sinf(v6) * v7) * 3.1415927) * 0.25) + 0.78539819;
        v12 = sinf(v11);
        v13 = cosf(v11);
        v14 = v3 & 3;
        v15 = v3++ >> 2;
        ++v4;
        v16 = (char *)v2->m_pDeflectorDSPInfo + v2->m_uDSPInfoSize * v15;
        *(float *)&v16[4 * v14 + 112] = v12 * v9;
        *(float *)&v16[4 * v14 + 128] = v12 * v10;
        *(float *)&v16[4 * v14 + 144] = v13 * v9;
        *(float *)&v16[4 * v14 + 160] = v13 * v10;
      }
      while ( v3 < v1 );
    }
  }
}

// File Line: 210
// RVA: 0xAD6E80
void __fastcall CAkSoundSeedWindProcess::ComputeEffectiveAverageVelocity(CAkSoundSeedWindProcess *this, float in_fAutomationValue)
{
  CAkSoundSeedWindProcess *v2; // rbx
  float v3; // xmm0_4

  v2 = this;
  v3 = powf(
         2.0,
         (float)((float)(this->m_pParams->fBaseValue[0] + this->m_fRandomParamValue[0]) + in_fAutomationValue)
       * 0.00083333335)
     * 8.0;
  if ( v3 > 2.0 )
    v2->m_fEffectiveParamValue[0] = v3;
  else
    v2->m_fEffectiveParamValue[0] = FLOAT_2_0;
}

// File Line: 220
// RVA: 0xAD6EF0
void __fastcall CAkSoundSeedWindProcess::ComputeEffectiveVariability(CAkSoundSeedWindProcess *this, float in_fAutomationValue)
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
void __fastcall CAkSoundSeedWindProcess::ComputeEffectiveGustiness(CAkSoundSeedWindProcess *this, float in_fAutomationValue)
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
void __fastcall CAkSoundSeedWindProcess::Prepare(CAkSoundSeedWindProcess *this, unsigned int in_uNumFrames, CAkVelocityDelayLine *in_VelocityDelayLine, const unsigned int in_uChangeMask)
{
  AkWindParams *v4; // rdi
  char v5; // r14
  CAkVelocityDelayLine *v6; // rsi
  signed int v7; // ebp
  CAkSoundSeedWindProcess *v8; // rbx
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float in_fBufferTime; // xmm7_4
  float v14; // xmm0_4
  unsigned int v15; // er11
  unsigned int v16; // eax
  float *v17; // r10
  float v18; // xmm6_4

  v4 = this->m_pParams;
  v5 = in_uChangeMask;
  v6 = in_VelocityDelayLine;
  v7 = in_uNumFrames;
  v8 = this;
  v9 = powf(
         2.0,
         (float)((float)(v4->fBaseValue[0] + this->m_fRandomParamValue[0]) + this->m_fAutomationValues[0])
       * 0.00083333335)
     * 8.0;
  if ( v9 <= 2.0 )
    v9 = FLOAT_2_0;
  v8->m_fEffectiveParamValue[0] = v9;
  v8->m_fEffectiveParamValue[1] = (float)(v4->fBaseValue[1] + v8->m_fRandomParamValue[1]) + v8->m_fAutomationValues[1];
  v10 = (float)(v4->fBaseValue[2] + v8->m_fRandomParamValue[2]) + v8->m_fAutomationValues[2];
  if ( v10 < 1.0 )
  {
    if ( v10 <= 0.0 )
      v10 = 0.0;
  }
  else
  {
    v10 = *(float *)&FLOAT_1_0;
  }
  v8->m_fEffectiveParamValue[2] = v10;
  v11 = (float)(v4->fBaseValue[3] + v8->m_fRandomParamValue[3]) + v8->m_fAutomationValues[3];
  if ( v11 < 1.0 )
  {
    if ( v11 <= 0.0 )
      v11 = 0.0;
  }
  else
  {
    v11 = *(float *)&FLOAT_1_0;
  }
  v12 = v8->m_fAutomationValues[4];
  v8->m_fEffectiveParamValue[3] = v11;
  CAkSoundSeedWindProcess::ComputeEffectiveFrequencyScale(v8, v12);
  CAkSoundSeedWindProcess::ComputeEffectiveQFactorScale(v8, v8->m_fAutomationValues[5]);
  CAkSoundSeedWindProcess::ComputeEffectiveGainOffset(v8, v8->m_fAutomationValues[6]);
  in_fBufferTime = (double)v7 / (double)(signed int)v8->m_uSampleRate;
  v14 = CAkGustManager::ComputeInstantVelocity(
          &v6->m_GustManager,
          v8->m_fEffectiveParamValue[0],
          v8->m_fEffectiveParamValue[2],
          v8->m_fEffectiveParamValue[3],
          in_fBufferTime);
  if ( v14 <= v6->m_fMinVelocity )
    v14 = v6->m_fMinVelocity;
  v6->pfDelay[v6->uCurOffset++] = v14;
  v15 = v6->uDelayLineLength;
  v16 = v6->uCurOffset;
  v17 = v6->pfDelay;
  if ( v16 == v6->uDelayLineLength )
    v16 = 0;
  v6->uCurOffset = v16;
  v18 = (float)((float)(v17[(v16 + v15 - 2) % v15] + v17[(v16 + v15 - 1) % v15]) + v17[(v16 + v15 - 3) % v15])
      * 0.33333334;
  if ( v8->m_pParams->bAutomation[1] || v5 & 0x15 || v8->m_bFirstExecution )
    CAkSoundSeedWindProcess::ComputeDistancesToEntry(v8);
  CAkSoundSeedWindProcess::ComputeDeflectorWindVelocities(v8, v18, in_fBufferTime, v6);
  if ( v8->m_bFirstExecution )
    CAkSoundSeedWindProcess::InitDeflectorGainRamp(v8);
  else
    CAkSoundSeedWindProcess::ComputeDeflectorGains(v8, v7);
  CAkSoundSeedWindProcess::ComputeFilterCoefficients(v8);
}

// File Line: 315
// RVA: 0xAD6910
void __fastcall CAkSoundSeedWindProcess::Process(CAkSoundSeedWindProcess *this, AkAudioBuffer *io_pBufferOut, float *in_pfTempStorage)
{
  CAkSoundSeedWindProcess *v3; // rbx

  v3 = this;
  switch ( this->m_uNumChannels )
  {
    case 1u:
      CAkSoundSeedWindProcess::ProcessMono(this, io_pBufferOut, in_pfTempStorage);
      break;
    case 2u:
      CAkSoundSeedWindProcess::ProcessStereo(this, io_pBufferOut, in_pfTempStorage);
      CAkSoundSeedWindProcess::DeflectorGainRampCompleted(v3);
      return;
    case 4u:
      CAkSoundSeedWindProcess::ProcessQuad(this, io_pBufferOut, in_pfTempStorage);
      CAkSoundSeedWindProcess::DeflectorGainRampCompleted(v3);
      return;
  }
  CAkSoundSeedWindProcess::DeflectorGainRampCompleted(v3);
}

// File Line: 343
// RVA: 0xAD6F70
void __fastcall CAkSoundSeedWindProcess::ComputeDeflectorWindVelocities(CAkSoundSeedWindProcess *this, float in_fInstantVelocity, float in_fBufferTime, CAkVelocityDelayLine *in_VelocityDelayLine)
{
  unsigned int v4; // ebx
  unsigned int v5; // esi
  signed __int64 v6; // r10
  float v7; // xmm4_4
  unsigned int v8; // eax
  __int64 v9; // rbp
  __int64 v10; // r14
  signed __int64 v11; // r10
  __int64 v12; // rbx

  v4 = this->m_cDeflectors;
  v5 = 0;
  v6 = 0i64;
  if ( (signed int)v4 >= 4 )
  {
    v7 = 1.0 / (float)(in_fInstantVelocity * in_fBufferTime);
    v8 = ((v4 - 4) >> 2) + 1;
    v9 = 0i64;
    v5 = 4 * v8;
    v6 = 4i64 * v8;
    v10 = v8;
    do
    {
      v9 += 128i64;
      *(float *)((char *)&this->m_pDeflectorInfo[-4] + v9 - 12) = in_VelocityDelayLine->pfDelay[(in_VelocityDelayLine->uDelayLineLength
                                                                                               - (signed int)(float)(v7 * *(float *)((char *)&this->m_pDeflectorInfo[-4] + v9 - 16))
                                                                                               + in_VelocityDelayLine->uCurOffset
                                                                                               - 1)
                                                                                              % in_VelocityDelayLine->uDelayLineLength];
      *(float *)((char *)&this->m_pDeflectorInfo[-3] + v9 - 8) = in_VelocityDelayLine->pfDelay[(in_VelocityDelayLine->uDelayLineLength
                                                                                              - (signed int)(float)(v7 * *(float *)((char *)&this->m_pDeflectorInfo[-3] + v9 - 12))
                                                                                              + in_VelocityDelayLine->uCurOffset
                                                                                              - 1)
                                                                                             % in_VelocityDelayLine->uDelayLineLength];
      *(float *)((char *)&this->m_pDeflectorInfo[-2] + v9 - 4) = in_VelocityDelayLine->pfDelay[(in_VelocityDelayLine->uDelayLineLength
                                                                                              - (signed int)(float)(v7 * *(float *)((char *)&this->m_pDeflectorInfo[-2] + v9 - 8))
                                                                                              + in_VelocityDelayLine->uCurOffset
                                                                                              - 1)
                                                                                             % in_VelocityDelayLine->uDelayLineLength];
      *(float *)((char *)&this->m_pDeflectorInfo[-1].fVelocity + v9) = in_VelocityDelayLine->pfDelay[(in_VelocityDelayLine->uDelayLineLength - (signed int)(float)(v7 * *(float *)((char *)&this->m_pDeflectorInfo[-1] + v9 - 4)) + in_VelocityDelayLine->uCurOffset - 1) % in_VelocityDelayLine->uDelayLineLength];
      --v10;
    }
    while ( v10 );
  }
  if ( v5 < v4 )
  {
    v11 = 32 * v6;
    v12 = v4 - v5;
    do
    {
      v11 += 32i64;
      *(float *)((char *)&this->m_pDeflectorInfo[-1].fVelocity + v11) = in_VelocityDelayLine->pfDelay[(in_VelocityDelayLine->uDelayLineLength - (signed int)(float)((float)(1.0 / (float)(in_fInstantVelocity * in_fBufferTime)) * *(float *)((char *)&this->m_pDeflectorInfo[-1] + v11 - 4)) + in_VelocityDelayLine->uCurOffset - 1) % in_VelocityDelayLine->uDelayLineLength];
      --v12;
    }
    while ( v12 );
  }
}

// File Line: 354
// RVA: 0xAD7110
void __fastcall CAkSoundSeedWindProcess::ComputeFilterCoefficients(CAkSoundSeedWindProcess *this)
{
  unsigned int v1; // er15
  unsigned int v2; // er14
  CAkSoundSeedWindProcess *v3; // rsi
  float v4; // xmm9_4
  __int64 v5; // rbp
  DeflectorInfo *v6; // rax
  float v7; // xmm6_4
  float v8; // xmm7_4
  __int64 v9; // rbx
  char *v10; // rdi
  float v11; // xmm0_4

  v1 = this->m_cDeflectors;
  v2 = 0;
  v3 = this;
  v4 = 1.0 / (float)(signed int)this->m_uSampleRate;
  if ( v1 )
  {
    v5 = 0i64;
    do
    {
      v6 = v3->m_pDeflectorInfo;
      v7 = (float)(*(float *)((char *)&v6->fEffectiveQFactor + v5) * *(float *)((char *)&v6->fEffectiveFrequency + v5))
         * 0.125;
      if ( v7 >= (float)((float)(signed int)v3->m_uSampleRate * 0.5) )
        v7 = (float)(signed int)v3->m_uSampleRate * 0.5;
      if ( v7 <= 20.0 )
        v7 = FLOAT_20_0;
      v8 = expf(
             (float)((float)((float)((float)(v7 / *(float *)((char *)&v6->fEffectiveGain + v5)) * 2.0) * 3.1415927) * v4)
           * -0.5);
      if ( v8 >= 0.99919999 )
        v8 = FLOAT_0_99919999;
      v9 = v2 & 3;
      v10 = (char *)v3->m_pDeflectorDSPInfo + v3->m_uDSPInfoSize * (v2 >> 2);
      v11 = cosf((float)(v7 * 6.2831855) * v4);
      ++v2;
      v5 += 32i64;
      *(_DWORD *)&v10[4 * v9 + 64] = COERCE_UNSIGNED_INT(v8 * v8) ^ _xmm[0];
      *(float *)&v10[4 * v9 + 48] = v11 * (float)(v8 * 2.0);
    }
    while ( v2 < v1 );
  }
}

// File Line: 388
// RVA: 0xAD7320
void __fastcall CAkSoundSeedWindProcess::ComputeDistancesToEntry(CAkSoundSeedWindProcess *this)
{
  unsigned int v1; // er14
  unsigned int v2; // er12
  CAkSoundSeedWindProcess *v3; // rdi
  float v4; // xmm7_4
  float v5; // xmm10_4
  float v6; // xmm6_4
  DeflectorInfo *v7; // r13
  __int64 v8; // r15
  __int64 v9; // rsi
  __int64 v10; // rbp
  AkWindDeflectorParams *v11; // rbx
  signed __int64 v12; // rcx
  __int64 v13; // rdx
  unsigned int v14; // eax
  __int64 v15; // r8
  signed __int64 v16; // rcx
  __int64 v17; // rdx

  v1 = this->m_cDeflectors;
  v2 = 0;
  v3 = this;
  v4 = (float)(this->m_fEffectiveParamValue[1] * 3.1415927) * 0.0055555557;
  v5 = this->m_pParams->fMaxDistance;
  v6 = v5 * 2.0;
  if ( v1 )
  {
    v7 = this->m_pDeflectorInfo;
    v8 = v1;
    v9 = 0i64;
    v10 = 0i64;
    do
    {
      v11 = v3->m_pDeflectors;
      *(float *)((char *)&v7->fVelocity + v9) = v5
                                              - (float)(cosf(
                                                          v4
                                                        - (float)((float)(v11[v10].fAngle * 3.1415927) * 0.0055555557))
                                                      * v11[v10].fDistance);
      v7 = v3->m_pDeflectorInfo;
      if ( v6 >= *(float *)((char *)&v7->fVelocity + v9) )
        v6 = *(float *)((char *)&v7->fVelocity + v9);
      ++v10;
      v9 += 32i64;
      --v8;
    }
    while ( v8 );
  }
  v12 = 0i64;
  if ( (signed int)v1 >= 4 )
  {
    v13 = 0i64;
    v14 = ((v1 - 4) >> 2) + 1;
    v15 = v14;
    v2 = 4 * v14;
    v12 = 4i64 * v14;
    do
    {
      v13 += 128i64;
      *(float *)((char *)&v3->m_pDeflectorInfo[-4] + v13 - 16) = *(float *)((char *)&v3->m_pDeflectorInfo[-4] + v13 - 16)
                                                               - v6;
      *(float *)((char *)&v3->m_pDeflectorInfo[-3] + v13 - 12) = *(float *)((char *)&v3->m_pDeflectorInfo[-3] + v13 - 12)
                                                               - v6;
      *(float *)((char *)&v3->m_pDeflectorInfo[-2] + v13 - 8) = *(float *)((char *)&v3->m_pDeflectorInfo[-2] + v13 - 8)
                                                              - v6;
      *(float *)((char *)&v3->m_pDeflectorInfo[-1] + v13 - 4) = *(float *)((char *)&v3->m_pDeflectorInfo[-1] + v13 - 4)
                                                              - v6;
      --v15;
    }
    while ( v15 );
  }
  if ( v2 < v1 )
  {
    v16 = 32 * v12;
    v17 = v1 - v2;
    do
    {
      v16 += 32i64;
      *(float *)((char *)&v3->m_pDeflectorInfo[-1] + v16 - 4) = *(float *)((char *)&v3->m_pDeflectorInfo[-1] + v16 - 4)
                                                              - v6;
      --v17;
    }
    while ( v17 );
  }
}

// File Line: 407
// RVA: 0xAD8010
float __fastcall CAkSoundSeedWindProcess::EqualizeTunable(CAkSoundSeedWindProcess *this, float in_fCenterFrequency, float in_fQ)
{
  CAkSoundSeedWindProcess *v3; // rbx
  float v4; // xmm8_4
  float v5; // xmm7_4
  float v6; // xmm6_4

  v3 = this;
  v4 = fsqrt(in_fCenterFrequency);
  v5 = logf(in_fCenterFrequency / in_fQ) * 1.442695;
  v6 = expf(
         (float)((float)((float)((float)(in_fCenterFrequency / in_fQ) * 2.0) * 3.1415927)
               / (float)(signed int)v3->m_uSampleRate)
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
float __fastcall CAkSoundSeedWindProcess::ComputeCombinedGain(CAkSoundSeedWindProcess *this, float in_fDeflectorGain, float in_fDistance, float in_fVelocity, float in_fCenterFrequency, float in_fQfactor)
{
  AkWindParams *v6; // rbx
  float v7; // xmm10_4
  float v8; // xmm11_4
  float v9; // xmm8_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4

  v6 = this->m_pParams;
  v7 = in_fDeflectorGain;
  v8 = CAkSoundSeedWindProcess::EqualizeTunable(this, in_fCenterFrequency, in_fQfactor);
  if ( in_fDistance > v6->fMinDistance )
  {
    v10 = (float)(logf(in_fDistance / v6->fMinDistance) * 1.442695) * (float)(v6->fAttenuationRolloff * -6.0);
    v9 = powf(10.0, v10 * 0.050000001);
  }
  else
  {
    v9 = *(float *)&FLOAT_1_0;
  }
  v11 = FLOAT_48_0;
  v12 = (float)((float)(v6->fDynamicRange + 1.0) * 48.0) * 0.041524101;
  if ( _S1_38 & 1 )
  {
    v11 = fMaxVelocity;
  }
  else
  {
    fMaxVelocity = FLOAT_48_0;
    _S1_38 |= 1u;
  }
  return (float)((float)(powf(in_fVelocity / v11, v12) * v9) * v7) * v8;
}

// File Line: 453
// RVA: 0xAD7650
void __fastcall CAkSoundSeedWindProcess::InitDeflectorGainRamp(CAkSoundSeedWindProcess *this)
{
  unsigned int v1; // er13
  unsigned int v2; // er12
  CAkSoundSeedWindProcess *v3; // rdi
  unsigned int v4; // esi
  float v5; // xmm7_4
  __int64 v6; // rbp
  __int64 v7; // r15
  DeflectorInfo *v8; // rbx
  float *v9; // r14
  float v10; // xmm11_4
  float v11; // xmm6_4
  float v12; // xmm8_4
  float v13; // xmm12_4
  float v14; // xmm6_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  __int64 v17; // r8
  unsigned int v18; // edx
  float v19; // xmm0_4
  float v20; // xmm0_4
  char *v21; // rdx

  v1 = this->m_cDeflectors;
  v2 = 0;
  v3 = this;
  if ( v1 )
  {
    v4 = _S1_38;
    v5 = fMaxVelocity;
    v6 = 0i64;
    v7 = 0i64;
    do
    {
      v8 = v3->m_pDeflectorInfo;
      v9 = &v3->m_pParams->fDuration;
      v10 = *(float *)((char *)&v8->fEffectiveFrequency + v6);
      v11 = v3->m_pDeflectors[v7].fDistance;
      v12 = v9[3];
      v13 = CAkSoundSeedWindProcess::EqualizeTunable(
              v3,
              *(float *)((char *)&v8->fEffectiveQFactor + v6),
              *(float *)((char *)&v8->fEffectiveGain + v6));
      if ( v11 > v12 )
      {
        v15 = (float)(logf(v11 / v12) * 1.442695) * (float)(v9[4] * -6.0);
        v14 = powf(10.0, v15 * 0.050000001);
      }
      else
      {
        v14 = *(float *)&FLOAT_1_0;
      }
      if ( !(v4 & 1) )
      {
        v4 |= 1u;
        v5 = FLOAT_48_0;
      }
      v16 = powf(v10 / v5, (float)((float)(v9[6] + 1.0) * 48.0) * 0.041524101);
      v17 = v2 & 3;
      v18 = v2++;
      v19 = (float)(v16 * v14) * *(float *)((char *)&v8->fRandomFrequency + v6);
      ++v7;
      v6 += 32i64;
      v20 = v19 * v13;
      v21 = (char *)v3->m_pDeflectorDSPInfo + v3->m_uDSPInfoSize * (v18 >> 2);
      *(float *)&v21[4 * v17 + 32] = v20;
      *(float *)&v21[4 * v17] = v20;
      *(_DWORD *)&v21[4 * v17 + 16] = 0;
    }
    while ( v2 < v1 );
    fMaxVelocity = v5;
    _S1_38 = v4;
    v3->m_bFirstExecution = 0;
  }
  else
  {
    this->m_bFirstExecution = 0;
  }
}

// File Line: 483
// RVA: 0xAD78B0
void __fastcall CAkSoundSeedWindProcess::ComputeDeflectorGains(CAkSoundSeedWindProcess *this, unsigned int in_uNumFrames)
{
  unsigned int v2; // er13
  unsigned int v3; // er15
  CAkSoundSeedWindProcess *v4; // rsi
  unsigned int v5; // edi
  float v6; // xmm8_4
  __int64 v7; // rbp
  __int64 v8; // r12
  float v9; // xmm13_4
  DeflectorInfo *v10; // rbx
  float *v11; // r14
  float v12; // xmm11_4
  float v13; // xmm6_4
  float v14; // xmm7_4
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

  v2 = this->m_cDeflectors;
  v3 = 0;
  v4 = this;
  if ( v2 )
  {
    v5 = _S1_38;
    v6 = fMaxVelocity;
    v7 = 0i64;
    v8 = 0i64;
    v9 = 1.0 / (float)(signed int)in_uNumFrames;
    do
    {
      v10 = v4->m_pDeflectorInfo;
      v11 = &v4->m_pParams->fDuration;
      v12 = *(float *)((char *)&v10->fEffectiveFrequency + v7);
      v13 = v4->m_pDeflectors[v8].fDistance;
      v14 = v11[3];
      v15 = CAkSoundSeedWindProcess::EqualizeTunable(
              v4,
              *(float *)((char *)&v10->fEffectiveQFactor + v7),
              *(float *)((char *)&v10->fEffectiveGain + v7));
      if ( v13 > v14 )
      {
        v17 = (float)(logf(v13 / v14) * 1.442695) * (float)(v11[4] * -6.0);
        v16 = powf(10.0, v17 * 0.050000001);
      }
      else
      {
        v16 = *(float *)&FLOAT_1_0;
      }
      if ( !(v5 & 1) )
      {
        v5 |= 1u;
        v6 = FLOAT_48_0;
      }
      v18 = powf(v12 / v6, (float)((float)(v11[6] + 1.0) * 48.0) * 0.041524101);
      v19 = v3 & 3;
      v20 = v3++;
      v21 = (float)(v18 * v16) * *(float *)((char *)&v10->fRandomFrequency + v7);
      ++v8;
      v7 += 32i64;
      v22 = v21 * v15;
      v23 = (char *)v4->m_pDeflectorDSPInfo + v4->m_uDSPInfoSize * (v20 >> 2);
      v24 = v22 - *(float *)&v23[4 * v19];
      *(float *)&v23[4 * v19 + 32] = v22;
      *(float *)&v23[4 * v19 + 16] = v24 * v9;
    }
    while ( v3 < v2 );
    fMaxVelocity = v6;
    _S1_38 = v5;
  }
}

// File Line: 511
// RVA: 0xAD7B10
void __fastcall CAkSoundSeedWindProcess::DeflectorGainRampCompleted(CAkSoundSeedWindProcess *this)
{
  unsigned int v1; // er11
  unsigned int v2; // er9
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

  v1 = this->m_cDeflectors;
  v2 = 0;
  if ( (signed int)v1 >= 4 )
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
    while ( v2 < v1 - 3 );
  }
  for ( ; v2 < v1; *(_DWORD *)&v15[4 * v13] = v16 )
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
void __fastcall CAkSoundSeedWindProcess::ComputeEffectiveDirection(CAkSoundSeedWindProcess *this, float in_fAutomationValue)
{
  this->m_fEffectiveParamValue[1] = (float)(this->m_pParams->fBaseValue[1] + this->m_fRandomParamValue[1])
                                  + in_fAutomationValue;
}

// File Line: 669
// RVA: 0xAD7C60
void __fastcall CAkSoundSeedWindProcess::ComputeEffectiveFrequencyScale(CAkSoundSeedWindProcess *this, float in_fAutomationValue)
{
  CAkSoundSeedWindProcess *v2; // rsi
  float v3; // xmm7_4
  unsigned int v4; // eax
  __int64 v5; // rdi
  __int64 v6; // r14
  __int64 v7; // rbp
  DeflectorInfo *v8; // rbx
  float v9; // xmm0_4

  v2 = this;
  v3 = this->m_pParams->fBaseValue[4];
  v4 = this->m_cDeflectors;
  if ( v4 )
  {
    v5 = 0i64;
    v6 = v4;
    v7 = 0i64;
    do
    {
      v8 = v2->m_pDeflectorInfo;
      v9 = powf(2.0, (float)(v3 + *(float *)((char *)&v8->fRandomQFactor + v5)) + in_fAutomationValue);
      v5 += 32i64;
      ++v7;
      *(float *)((char *)v8 + v5 - 24) = v9 * *((float *)&v2->m_pDeflectors[v7] - 3);
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 682
// RVA: 0xAD7D20
void __fastcall CAkSoundSeedWindProcess::ComputeEffectiveQFactorScale(CAkSoundSeedWindProcess *this, float in_fAutomationValue)
{
  CAkSoundSeedWindProcess *v2; // r14
  float v3; // xmm9_4
  unsigned int v4; // eax
  __int64 v5; // rbx
  __int64 v6; // rsi
  __int64 v7; // rdi
  DeflectorInfo *v8; // rbp
  float v9; // xmm0_4

  v2 = this;
  v3 = this->m_pParams->fBaseValue[5];
  v4 = this->m_cDeflectors;
  if ( v4 )
  {
    v5 = 0i64;
    v6 = v4;
    v7 = 0i64;
    do
    {
      v8 = v2->m_pDeflectorInfo;
      v9 = powf(2.0, (float)(v3 + *(float *)((char *)&v8->fRandomGain + v5)) + in_fAutomationValue)
         * v2->m_pDeflectors[v7].fQFactor;
      if ( v9 < 50.0 )
      {
        if ( v9 <= 0.1 )
          v9 = FLOAT_0_1;
      }
      else
      {
        v9 = FLOAT_50_0;
      }
      *(float *)((char *)&v8->fEffectiveGain + v5) = v9;
      v5 += 32i64;
      ++v7;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 700
// RVA: 0xAD7E30
void __fastcall CAkSoundSeedWindProcess::ComputeEffectiveGainOffset(CAkSoundSeedWindProcess *this, float in_fAutomationValue)
{
  CAkSoundSeedWindProcess *v2; // rbx
  float v3; // xmm6_4
  float v4; // xmm0_4
  signed int v5; // er10
  unsigned int v6; // er11
  signed __int64 v7; // rdi
  float v8; // xmm3_4
  __int64 v9; // rcx
  __int64 v10; // rdx
  unsigned int v11; // eax
  __int64 v12; // r9
  DeflectorInfo *v13; // r8
  float v14; // xmm0_4
  DeflectorInfo *v15; // r8
  float v16; // xmm0_4
  DeflectorInfo *v17; // r8
  float v18; // xmm0_4
  DeflectorInfo *v19; // r8
  float v20; // xmm0_4
  float v21; // xmm0_4
  signed __int64 v22; // rdx
  signed __int64 v23; // rcx
  __int64 v24; // r9
  DeflectorInfo *v25; // r8
  float v26; // xmm0_4
  float v27; // xmm0_4

  v2 = this;
  v3 = this->m_pParams->fBaseValue[6];
  v4 = powf(10.0, in_fAutomationValue * 0.050000001);
  v5 = v2->m_cDeflectors;
  v6 = 0;
  v7 = 0i64;
  v8 = v4;
  if ( v5 >= 4 )
  {
    v9 = 0i64;
    v10 = 0i64;
    v11 = ((unsigned int)(v5 - 4) >> 2) + 1;
    v12 = v11;
    v6 = 4 * v11;
    v7 = 4i64 * v11;
    do
    {
      v13 = v2->m_pDeflectorInfo;
      v14 = (float)(v3 * *(float *)((char *)&v13[1].fVelocity + v9)) * v8;
      if ( v14 < 16.0 )
      {
        if ( v14 <= 0.0 )
          v14 = 0.0;
      }
      else
      {
        v14 = FLOAT_16_0;
      }
      *(float *)((char *)&v13->fRandomFrequency + v9) = v14 * v2->m_pDeflectors[v10].fGain;
      v15 = v2->m_pDeflectorInfo;
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
      *(float *)((char *)&v15[1].fRandomQFactor + v9) = v16 * v2->m_pDeflectors[v10 + 1].fGain;
      v17 = v2->m_pDeflectorInfo;
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
      *(float *)((char *)&v17[2].fRandomGain + v9) = v18 * v2->m_pDeflectors[v10 + 2].fGain;
      v19 = v2->m_pDeflectorInfo;
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
      v21 = v20 * v2->m_pDeflectors[v10 + 3].fGain;
      v9 += 128i64;
      v10 += 4i64;
      *(float *)((char *)v19 + v9 - 16) = v21;
      --v12;
    }
    while ( v12 );
  }
  if ( v6 < v5 )
  {
    v22 = v7;
    v23 = 32 * v7;
    v24 = v5 - v6;
    do
    {
      v25 = v2->m_pDeflectorInfo;
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
      v27 = v26 * v2->m_pDeflectors[v22].fGain;
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
void __fastcall CAkSoundSeedWindProcess::ProcessMono(CAkSoundSeedWindProcess *this, AkAudioBuffer *io_pBufferOut, float *in_pfTempStorage)
{
  unsigned int v3; // ebp
  __int64 v4; // r15
  float *v5; // rsi
  AkAudioBuffer *v6; // r13
  unsigned int v7; // er12
  CAkSoundSeedWindProcess *v8; // rdi
  DSP::CAkPinkNoise *v9; // rax
  unsigned int v10; // ebx
  __int64 v11; // r9
  __int64 v12; // r10
  __int64 v13; // rax
  char *v14; // r11
  signed __int64 v15; // rdx
  __int128 v16; // xmm0
  __m128 v17; // xmm3
  __m128 v18; // xmm6
  __m128 v19; // xmm7
  __m128 v20; // xmm8
  __m128 v21; // xmm4
  __m128 v22; // xmm5
  float *v23; // rcx
  __int64 v24; // r8
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  __m128 v28; // xmm0
  __m128 *v29; // rdx
  signed __int64 v30; // r8
  __int64 v31; // rax
  __m128 v32; // xmm1
  __m128 v33; // xmm1

  v3 = io_pBufferOut->uValidFrames;
  v4 = 0i64;
  v5 = in_pfTempStorage;
  v6 = io_pBufferOut;
  v7 = (this->m_cDeflectors + 3) >> 2;
  v8 = this;
  if ( io_pBufferOut->uValidFrames )
  {
    v9 = &this->m_NoiseGen;
    do
    {
      v10 = 1024;
      if ( v3 < 0x400 )
        v10 = v3;
      DSP::CAkPinkNoise::GenerateBuffer(v9, v5, v10);
      memset(v5 + 1024, 0, 0x4000ui64);
      if ( v7 )
      {
        v11 = 0i64;
        v12 = v7;
        v13 = 0i64;
        do
        {
          v14 = (char *)v8->m_pDeflectorDSPInfo;
          v15 = (signed __int64)(v5 + 1024);
          v16 = *(_OWORD *)&v14[v11 + 32];
          v17 = *(__m128 *)&v14[v11];
          v18 = *(__m128 *)&v14[v11 + 16];
          v19 = *(__m128 *)&v14[v11 + 48];
          v20 = *(__m128 *)&v14[v11 + 64];
          v21 = *(__m128 *)&v14[v11 + 80];
          v22 = *(__m128 *)&v14[v11 + 96];
          if ( v10 )
          {
            v23 = v5;
            v24 = v10;
            do
            {
              v25 = (__m128)*(unsigned int *)v23;
              v17 = _mm_add_ps(v17, v18);
              v15 += 16i64;
              ++v23;
              v26 = _mm_mul_ps(v22, v20);
              v27 = _mm_add_ps(_mm_mul_ps(v21, v19), _mm_shuffle_ps(v25, v25, 0));
              v28 = v22;
              v22 = v21;
              v21 = _mm_add_ps(v27, v26);
              *(__m128 *)(v15 - 16) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v21, v28), v17), *(__m128 *)(v15 - 16));
              --v24;
            }
            while ( v24 );
          }
          *(__m128 *)&v14[v13 + 80] = v21;
          v13 += 112i64;
          v11 += 112i64;
          *(__m128 *)((char *)v8->m_pDeflectorDSPInfo + v13 - 16) = v22;
          *(__m128 *)((char *)v8->m_pDeflectorDSPInfo + v13 - 112) = v17;
          --v12;
        }
        while ( v12 );
      }
      v29 = (__m128 *)(v5 + 1024);
      v30 = (signed __int64)v6->pData + 4 * v4;
      if ( v10 )
      {
        v31 = v10;
        do
        {
          v32 = *v29;
          v30 += 4i64;
          ++v29;
          v33 = _mm_add_ps(v32, _mm_movehl_ps(v32, v32));
          *(float *)(v30 - 4) = COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 85)) + v33.m128_f32[0];
          --v31;
        }
        while ( v31 );
      }
      v4 = v10 + (unsigned int)v4;
      v9 = &v8->m_NoiseGen;
      v3 -= v10;
    }
    while ( v3 );
  }
}

// File Line: 818
// RVA: 0xAD82F0
void __fastcall CAkSoundSeedWindProcess::ProcessStereo(CAkSoundSeedWindProcess *this, AkAudioBuffer *io_pBufferOut, float *in_pfTempStorage)
{
  unsigned int v3; // ebp
  __int64 v4; // r15
  float *v5; // rsi
  AkAudioBuffer *v6; // r13
  unsigned int v7; // er12
  CAkSoundSeedWindProcess *v8; // rdi
  DSP::CAkPinkNoise *v9; // rcx
  unsigned int v10; // ebx
  __int64 v11; // r8
  __int64 v12; // r10
  __int64 v13; // rax
  char *v14; // r11
  signed __int64 v15; // rcx
  __int128 v16; // xmm0
  __m128 v17; // xmm3
  __m128 v18; // xmm6
  __m128 v19; // xmm7
  __m128 v20; // xmm8
  __m128 v21; // xmm4
  __m128 v22; // xmm5
  __m128 v23; // xmm9
  __m128 v24; // xmm10
  float *v25; // rdx
  __int64 v26; // r9
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  char *v34; // r9
  __m128 *v35; // rax
  signed __int64 v36; // rcx
  __int64 v37; // rdx
  __m128 v38; // xmm1
  __m128 v39; // xmm1
  __m128 *v40; // rcx
  unsigned __int64 v41; // rdx
  __int64 v42; // rax
  __m128 v43; // xmm1
  __m128 v44; // xmm1

  v3 = io_pBufferOut->uValidFrames;
  v4 = 0i64;
  v5 = in_pfTempStorage;
  v6 = io_pBufferOut;
  v7 = (this->m_cDeflectors + 3) >> 2;
  v8 = this;
  if ( io_pBufferOut->uValidFrames )
  {
    v9 = &this->m_NoiseGen;
    do
    {
      v10 = 1024;
      if ( v3 < 0x400 )
        v10 = v3;
      DSP::CAkPinkNoise::GenerateBuffer(v9, v5, v10);
      memset(v5 + 1024, 0, 0x8000ui64);
      if ( v7 )
      {
        v11 = 0i64;
        v12 = v7;
        v13 = 0i64;
        do
        {
          v14 = (char *)v8->m_pDeflectorDSPInfo;
          v15 = (signed __int64)(v5 + 1024);
          v16 = *(_OWORD *)&v14[v11 + 32];
          v17 = *(__m128 *)&v14[v11];
          v18 = *(__m128 *)&v14[v11 + 16];
          v19 = *(__m128 *)&v14[v11 + 48];
          v20 = *(__m128 *)&v14[v11 + 64];
          v21 = *(__m128 *)&v14[v11 + 80];
          v22 = *(__m128 *)&v14[v11 + 96];
          v23 = *(__m128 *)&v14[v11 + 112];
          v24 = *(__m128 *)&v14[v11 + 128];
          if ( v10 )
          {
            v25 = v5;
            v26 = v10;
            do
            {
              v27 = (__m128)*(unsigned int *)v25;
              v17 = _mm_add_ps(v17, v18);
              v15 += 32i64;
              ++v25;
              v28 = _mm_mul_ps(v22, v20);
              v29 = _mm_add_ps(_mm_mul_ps(v21, v19), _mm_shuffle_ps(v27, v27, 0));
              v30 = v22;
              v22 = v21;
              v31 = _mm_add_ps(v29, v28);
              v21 = v31;
              v32 = _mm_mul_ps(_mm_sub_ps(v31, v30), v17);
              v33 = _mm_add_ps(_mm_mul_ps(v32, v24), *(__m128 *)(v15 - 16));
              *(__m128 *)(v15 - 32) = _mm_add_ps(_mm_mul_ps(v32, v23), *(__m128 *)(v15 - 32));
              *(__m128 *)(v15 - 16) = v33;
              --v26;
            }
            while ( v26 );
          }
          *(__m128 *)&v14[v13 + 80] = v21;
          v13 += 144i64;
          v11 += 144i64;
          *(__m128 *)((char *)v8->m_pDeflectorDSPInfo + v13 - 48) = v22;
          *(__m128 *)((char *)v8->m_pDeflectorDSPInfo + v13 - 144) = v17;
          --v12;
        }
        while ( v12 );
      }
      v34 = (char *)v6->pData;
      v35 = (__m128 *)(v5 + 1024);
      v36 = (signed __int64)v6->pData + 4 * v4;
      if ( v10 )
      {
        v37 = v10;
        do
        {
          v38 = *v35;
          v36 += 4i64;
          v35 += 2;
          v39 = _mm_add_ps(v38, _mm_movehl_ps(v38, v38));
          *(float *)(v36 - 4) = COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 85)) + v39.m128_f32[0];
          --v37;
        }
        while ( v37 );
      }
      v40 = (__m128 *)(v5 + 1028);
      v41 = (unsigned __int64)&v34[4 * ((unsigned int)v4 + (unsigned __int64)v6->uMaxFrames)];
      if ( v10 )
      {
        v42 = v10;
        do
        {
          v43 = *v40;
          v41 += 4i64;
          v40 += 2;
          v44 = _mm_add_ps(v43, _mm_movehl_ps(v43, v43));
          *(float *)(v41 - 4) = COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 85)) + v44.m128_f32[0];
          --v42;
        }
        while ( v42 );
      }
      v4 = v10 + (unsigned int)v4;
      v9 = &v8->m_NoiseGen;
      v3 -= v10;
    }
    while ( v3 );
  }
}

// File Line: 943
// RVA: 0xAD8560
void __fastcall CAkSoundSeedWindProcess::ProcessQuad(CAkSoundSeedWindProcess *this, AkAudioBuffer *io_pBufferOut, float *in_pfTempStorage)
{
  unsigned int v3; // ebx
  unsigned int v4; // esi
  float *v5; // r12
  AkAudioBuffer *v6; // r15
  unsigned int v7; // ebp
  CAkSoundSeedWindProcess *v8; // r14
  DSP::CAkPinkNoise *v9; // rax
  unsigned int v10; // edi
  __int64 v11; // rsi
  __int64 v12; // r15
  __int64 v13; // rbx
  char *v14; // rbp
  __int128 *v15; // rcx
  char *v16; // rdx
  signed __int64 v17; // rax
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
  signed __int64 v38; // rax
  float *v39; // rcx
  __int64 v40; // rdx
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm0
  __m128 v45; // xmm2
  __m128 v46; // xmm2
  __m128 v47; // xmm1
  __m128 v48; // xmm0
  signed __int64 v49; // r8
  signed __int64 v50; // r10
  signed __int64 v51; // r9
  signed __int64 v52; // r11
  __m128 *v53; // rax
  signed __int64 v54; // rcx
  __int64 v55; // rdx
  __m128 v56; // xmm1
  __m128 v57; // xmm1
  __m128 Dst; // [rsp+20h] [rbp-168h]
  __m128 v59; // [rsp+30h] [rbp-158h]
  __m128 v60; // [rsp+50h] [rbp-138h]
  __m128 v61; // [rsp+60h] [rbp-128h]
  __m128 v62; // [rsp+70h] [rbp-118h]
  __m128 v63; // [rsp+80h] [rbp-108h]
  __m128 v64; // [rsp+90h] [rbp-F8h]
  __m128 v65; // [rsp+A0h] [rbp-E8h]
  __m128 v66; // [rsp+B0h] [rbp-D8h]
  __m128 v67; // [rsp+C0h] [rbp-C8h]
  unsigned int v68; // [rsp+190h] [rbp+8h]
  AkAudioBuffer *v69; // [rsp+198h] [rbp+10h]
  unsigned int v70; // [rsp+1A0h] [rbp+18h]
  unsigned int v71; // [rsp+1A8h] [rbp+20h]

  v69 = io_pBufferOut;
  v3 = io_pBufferOut->uValidFrames;
  v4 = 0;
  v5 = in_pfTempStorage;
  v6 = io_pBufferOut;
  v7 = (this->m_cDeflectors + 3) >> 2;
  v8 = this;
  v68 = 0;
  v71 = (this->m_cDeflectors + 3) >> 2;
  v70 = io_pBufferOut->uValidFrames;
  if ( io_pBufferOut->uValidFrames )
  {
    v9 = &this->m_NoiseGen;
    do
    {
      v10 = 1024;
      if ( v3 < 0x400 )
        v10 = v3;
      DSP::CAkPinkNoise::GenerateBuffer(v9, v5, v10);
      memset(v5 + 1024, 0, 0x10000ui64);
      if ( v7 )
      {
        v11 = 0i64;
        v12 = v7;
        v13 = 0i64;
        do
        {
          v14 = (char *)v8->m_pDeflectorDSPInfo;
          v15 = (__int128 *)&Dst;
          v16 = &v14[v11];
          if ( ((unsigned __int8)&Dst | (unsigned __int8)(v11 + (_BYTE)v14)) & 0xF )
          {
            memmove(&Dst, v16, 0xB0ui64);
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
          v28 = Dst;
          v29 = v59;
          v30 = v60;
          v31 = v61;
          v32 = v62;
          v33 = v63;
          v34 = v64;
          v35 = v65;
          v36 = v66;
          v37 = v67;
          if ( v10 )
          {
            v38 = (signed __int64)(v5 + 1032);
            v39 = v5;
            v40 = v10;
            do
            {
              v41 = (__m128)*(unsigned int *)v39;
              v28 = _mm_add_ps(v28, v29);
              v38 += 64i64;
              ++v39;
              v42 = _mm_mul_ps(v33, v31);
              v43 = _mm_add_ps(_mm_mul_ps(v32, v30), _mm_shuffle_ps(v41, v41, 0));
              v44 = v33;
              v33 = v32;
              v45 = _mm_add_ps(v43, v42);
              v32 = v45;
              v46 = _mm_mul_ps(_mm_sub_ps(v45, v44), v28);
              v47 = _mm_add_ps(_mm_mul_ps(v46, v35), *(__m128 *)(v38 - 80));
              *(__m128 *)(v38 - 96) = _mm_add_ps(_mm_mul_ps(v46, v34), *(__m128 *)(v38 - 96));
              *(__m128 *)(v38 - 80) = v47;
              v48 = _mm_add_ps(_mm_mul_ps(v46, v37), *(__m128 *)(v38 - 48));
              *(__m128 *)(v38 - 64) = _mm_add_ps(_mm_mul_ps(v46, v36), *(__m128 *)(v38 - 64));
              *(__m128 *)(v38 - 48) = v48;
              --v40;
            }
            while ( v40 );
          }
          *(__m128 *)&v14[v13 + 80] = v32;
          v13 += 176i64;
          v11 += 176i64;
          *(__m128 *)((char *)v8->m_pDeflectorDSPInfo + v13 - 80) = v33;
          *(__m128 *)((char *)v8->m_pDeflectorDSPInfo + v13 - 176) = v28;
          --v12;
        }
        while ( v12 );
        v3 = v70;
        v4 = v68;
        v7 = v71;
        v6 = v69;
      }
      v49 = (signed __int64)(v5 + 1024);
      v50 = 4i64;
      v51 = (signed __int64)v6->pData + 4 * v4;
      v52 = 4i64 * v6->uMaxFrames;
      do
      {
        v53 = (__m128 *)v49;
        v54 = v51;
        if ( v10 )
        {
          v55 = v10;
          do
          {
            v56 = *v53;
            v54 += 4i64;
            v53 += 4;
            v57 = _mm_add_ps(v56, _mm_movehl_ps(v56, v56));
            *(float *)(v54 - 4) = COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 85)) + v57.m128_f32[0];
            --v55;
          }
          while ( v55 );
        }
        v49 += 16i64;
        v51 += v52;
        --v50;
      }
      while ( v50 );
      v4 += v10;
      v3 -= v10;
      v9 = &v8->m_NoiseGen;
      v70 = v3;
      v68 = v4;
    }
    while ( v3 );
  }
}


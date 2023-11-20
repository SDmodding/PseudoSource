// File Line: 48
// RVA: 0xADB570
void __fastcall CAkSoundSeedWooshProcess::CAkSoundSeedWooshProcess(CAkSoundSeedWooshProcess *this)
{
  CAkSoundSeedWooshProcess *v1; // rdi
  signed __int64 v2; // rcx

  v1 = this;
  this->m_pParams = 0i64;
  this->m_pDeflectors = 0i64;
  this->m_pDeflectorInfo = 0i64;
  this->m_pDeflectorDSPInfo = 0i64;
  this->m_pfAutomationValues = 0i64;
  this->m_RandGenerator.m_uLCGState = rand();
  DSP::CAkWhiteNoise::CAkWhiteNoise((DSP::CAkWhiteNoise *)&v1->m_NoiseGen.m_uLCGState);
  *(_QWORD *)&v1->m_NoiseGen.m_DCFilter.m_fFFwd1 = 0i64;
  v1->m_NoiseGen.m_DCFilter.m_fA1 = 0.0;
  v2 = (signed __int64)&v1->m_NoiseGen.PurpleFilter;
  *(_QWORD *)&v1->m_NoiseGen.RedFilter.fFFbk1 = 0i64;
  v1->m_NoiseGen.RedFilter.fA1 = 0.0;
  *(_QWORD *)(v2 + 160) = 0i64;
  *(_QWORD *)(v2 + 168) = 0i64;
  DSP::BiquadFilter<DSP::SingleChannelPolicy>::SetCoefs(&v1->m_NoiseGen.PurpleFilter, 1.0, 0.0, 0.0, 0.0, 0.0);
}

// File Line: 53
// RVA: 0xADB610
void __fastcall CAkSoundSeedWooshProcess::~CAkSoundSeedWooshProcess(CAkSoundSeedWooshProcess *this)
{
  ;
}

// File Line: 60
// RVA: 0xADB620
void __fastcall CAkSoundSeedWooshProcess::Setup(CAkSoundSeedWooshProcess *this, AkWooshParams *in_pParams, AkAudioFormat *io_rFormat)
{
  AkWooshParams *v3; // rdi
  CAkSoundSeedWooshProcess *v4; // rbx
  unsigned int v5; // er9
  unsigned int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  unsigned int i; // ecx
  float v11; // xmm1_4
  int v12; // eax

  this->m_uSampleRate = io_rFormat->uSampleRate;
  v3 = in_pParams;
  v4 = this;
  this->m_fSamplePeriod = 1.0 / (double)(signed int)io_rFormat->uSampleRate;
  v5 = in_pParams->uChannelMask;
  *((_DWORD *)io_rFormat + 1) &= 0xFFFC0000;
  *((_DWORD *)io_rFormat + 1) |= v5 & 0x3FFFF;
  v6 = *((_DWORD *)io_rFormat + 1) & 0x3FFFF;
  if ( v6 > 0x37 )
  {
    v7 = v6 - 59;
    if ( v7 )
    {
      v8 = v7 - 4;
      if ( v8 )
      {
        v9 = v8 - 1528;
        if ( v9 )
        {
          if ( v9 != 8 )
          {
LABEL_8:
            *((_DWORD *)io_rFormat + 1) &= 0xFFFC0003;
            v5 = 3;
            *((_DWORD *)io_rFormat + 1) |= 3u;
          }
        }
      }
    }
  }
  else if ( v6 != 55 )
  {
    switch ( v6 )
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
  for ( i = 0; v5; v5 &= v5 - 1 )
    ++i;
  v4->m_uNumChannels = i;
  *((_DWORD *)io_rFormat + 1) &= 0xE0FFFFFF;
  *((_DWORD *)io_rFormat + 1) |= (i << 26) & 0x1F000000;
  DSP::CAkColoredNoise::Init(&v4->m_NoiseGen, in_pParams->eNoiseColor, v4->m_uSampleRate);
  v4->m_uOversamplingFactor = v3->uOversamplingFactor;
  v11 = v3->fRandomValue[0];
  v12 = 214013 * v4->m_RandGenerator.m_uLCGState + 2531011;
  v4->m_RandGenerator.m_uLCGState = v12;
  *(_WORD *)&v4->m_bLoopAfterExecution = 256;
  v4->m_bInitAdvancePosition = 1;
  v4->m_uLastPathPointIndex = 0;
  *(_QWORD *)&v4->m_fDistanceTraveled = 0i64;
  v4->m_fRandomSpeed = (float)((float)((float)((float)v12 * 2.3283064e-10) * 2.0) - 1.0) * v11;
}

// File Line: 94
// RVA: 0xADB8C0
float __fastcall CAkSoundSeedWooshProcess::ComputeIntegral(float in_fLeftX, float in_fLeftY, float in_fRightX, float in_fRightY)
{
  float v4; // xmm11_4
  float v5; // xmm7_4
  float v6; // xmm9_4
  float v7; // xmm10_4
  float v8; // xmm8_4
  float v9; // xmm0_4

  v4 = in_fLeftX;
  if ( _S1_39 & 1 )
  {
    v5 = LOG2;
  }
  else
  {
    _S1_39 |= 1u;
    v5 = logf(2.0);
    LOG2 = v5;
  }
  v6 = in_fRightX - v4;
  v7 = (float)(in_fRightY * 0.02) + 2.0;
  v8 = (float)(in_fLeftY * 0.02) + 2.0;
  if ( (float)(v7 - v8) == 0.0 )
    return powf(2.0, v8) * v6;
  v9 = expf(v5 * v7);
  return (float)((float)(v9 - expf(v5 * v8)) * (float)(v6 / (float)(v7 - v8))) / v5;
}

// File Line: 118
// RVA: 0xADC6F0
void __fastcall CAkSoundSeedWooshProcess::ComputeStereoGains(CAkSoundSeedWooshProcess *this, float in_fX, float in_fY, float *out_fLeft, float *out_fRight)
{
  float *v5; // rbx
  float v6; // xmm8_4
  float v7; // xmm0_4
  float v8; // xmm8_4

  v5 = out_fLeft;
  v6 = powf(fsqrt((float)(in_fX * in_fX) + (float)(in_fY * in_fY)), 0.16666667);
  v7 = atan2f(in_fY, in_fX);
  v8 = (float)((float)((float)(v6 * cosf(v7)) * 3.1415927) * 0.25) + 0.78539819;
  *v5 = cosf(v8);
  *out_fRight = sinf(v8);
}

// File Line: 130
// RVA: 0xADC7B0
void __fastcall CAkSoundSeedWooshProcess::ComputeQuadGains(CAkSoundSeedWooshProcess *this, float in_fX, float in_fY, float *out_fFrontLeft, float *out_fFrontRight, float *out_fRearLeft, float *out_fRearRight)
{
  float *v7; // rbx
  float v8; // xmm14_4
  float v9; // xmm11_4
  float v10; // xmm6_4
  float v11; // xmm12_4
  float v12; // xmm13_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm0_4

  v7 = out_fFrontLeft;
  v8 = atan2f(in_fY, in_fX);
  v9 = powf(fsqrt((float)(in_fX * in_fX) + (float)(in_fY * in_fY)), 0.16666667);
  v10 = (float)((float)((float)(cosf(v8) * v9) * 3.1415927) * 0.25) + 0.78539819;
  v11 = cosf(v10);
  v12 = sinf(v10);
  v13 = (float)((float)((float)(sinf(v8) * v9) * 3.1415927) * 0.25) + 0.78539819;
  v14 = sinf(v13);
  v15 = cosf(v13);
  *v7 = v14 * v11;
  *out_fFrontRight = v14 * v12;
  *out_fRearLeft = v15 * v11;
  *out_fRearRight = v15 * v12;
}

// File Line: 148
// RVA: 0xADB9E0
void __fastcall CAkSoundSeedWooshProcess::ComputeObjectPosition(CAkSoundSeedWooshProcess *this)
{
  unsigned int v1; // er10
  CAkSoundSeedWooshProcess *v2; // r9
  unsigned int v3; // edx
  __int64 v4; // r10
  __int64 v5; // r8
  float v6; // xmm3_4
  __int64 v7; // rcx
  AkWooshPathPoint *v8; // r8
  float v9; // xmm3_4
  AkWooshPathPoint *v10; // rcx
  AkWooshPathPoint *v11; // rcx

  v1 = this->m_cPathPoints;
  v2 = this;
  if ( v1 <= 1 )
  {
    v11 = this->m_pPath;
    v2->m_fCurrentPosX = v11->fX;
    v2->m_fCurrentPosY = v11->fY;
  }
  else
  {
    v3 = this->m_uLastPathPointIndex;
    v4 = v1 - 1;
    if ( v3 < (unsigned int)v4 )
    {
      v5 = v3 + 1;
      while ( this->m_fDistanceTraveled >= this->m_pPath[v5].fDistanceTravelled )
      {
        ++v3;
        v5 = (unsigned int)(v5 + 1);
        if ( v3 >= (unsigned int)v4 )
          goto LABEL_8;
      }
      this->m_uLastPathPointIndex = v3;
    }
LABEL_8:
    v6 = this->m_fDistanceTraveled;
    v7 = this->m_uLastPathPointIndex;
    if ( v6 >= v2->m_fTotalPathDistance )
    {
      v10 = v2->m_pPath;
      v2->m_fCurrentPosX = v10[v4].fX;
      v2->m_fCurrentPosY = v10[v4].fY;
    }
    else
    {
      v8 = v2->m_pPath;
      v9 = (float)(v6 - v8[v7].fDistanceTravelled)
         / (float)(v8[(unsigned int)(v7 + 1)].fDistanceTravelled - v8[v7].fDistanceTravelled);
      v2->m_fCurrentPosX = (float)((float)(v8[(unsigned int)(v7 + 1)].fX - v8[v7].fX) * v9) + v8[v7].fX;
      v2->m_fCurrentPosY = (float)((float)(v8[(unsigned int)(v7 + 1)].fY - v8[v7].fY) * v9) + v8[v7].fY;
    }
  }
}

// File Line: 200
// RVA: 0xADC910
void __fastcall CAkSoundSeedWooshProcess::InitSpatialization(CAkSoundSeedWooshProcess *this)
{
  CAkSoundSeedWooshProcess *v1; // r15
  float *v2; // r14
  float *v3; // rsi
  float *v4; // rdi
  float *v5; // rdi

  v1 = this;
  if ( this->m_uNumChannels == 2 )
  {
    v5 = &this->m_PositioningInfo.fChanGainTarget[1];
    CAkSoundSeedWooshProcess::ComputeStereoGains(
      this,
      this->m_fCurrentPosX,
      this->m_fCurrentPosY,
      this->m_PositioningInfo.fChanGainTarget,
      &this->m_PositioningInfo.fChanGainTarget[1]);
    *(_QWORD *)v1->m_PositioningInfo.fChanGainDelta = 0i64;
    v1->m_PositioningInfo.fChanGain[0] = v1->m_PositioningInfo.fChanGainTarget[0];
    v1->m_PositioningInfo.fChanGain[1] = *v5;
  }
  else if ( this->m_uNumChannels == 4 )
  {
    v2 = &this->m_PositioningInfo.fChanGainTarget[3];
    v3 = &this->m_PositioningInfo.fChanGainTarget[2];
    v4 = &this->m_PositioningInfo.fChanGainTarget[1];
    CAkSoundSeedWooshProcess::ComputeQuadGains(
      this,
      this->m_fCurrentPosX,
      this->m_fCurrentPosY,
      this->m_PositioningInfo.fChanGainTarget,
      &this->m_PositioningInfo.fChanGainTarget[1],
      &this->m_PositioningInfo.fChanGainTarget[2],
      &this->m_PositioningInfo.fChanGainTarget[3]);
    *(_QWORD *)v1->m_PositioningInfo.fChanGainDelta = 0i64;
    *(_QWORD *)&v1->m_PositioningInfo.fChanGainDelta[2] = 0i64;
    v1->m_PositioningInfo.fChanGain[0] = v1->m_PositioningInfo.fChanGainTarget[0];
    v1->m_PositioningInfo.fChanGain[1] = *v4;
    v1->m_PositioningInfo.fChanGain[2] = *v3;
    v1->m_PositioningInfo.fChanGain[3] = *v2;
  }
}

// File Line: 237
// RVA: 0xADBB00
void __fastcall CAkSoundSeedWooshProcess::ComputeDistanceToAdvance(CAkSoundSeedWooshProcess *this)
{
  CAkSoundSeedWooshProcess *v1; // rbx
  float v2; // xmm0_4

  v1 = this;
  if ( this->m_pParams->bAutomation[0] )
  {
    if ( this->m_bInitAdvancePosition )
    {
      this->m_bInitAdvancePosition = 0;
    }
    else
    {
      v2 = (float)(CAkSoundSeedWooshProcess::ComputeIntegral(
                     this->m_fPrevTimeElapsed,
                     this->m_fPrevInstantSpeed,
                     this->m_fTimeElapsed,
                     this->m_fAutomationValues[0])
                 / this->m_fAreaUnderWooshCurve)
         + this->m_fWooshIntegral;
      v1->m_fWooshIntegral = v2;
      v1->m_fDistanceTraveled = v2 * v1->m_fTotalPathDistance;
    }
    v1->m_fPrevTimeElapsed = v1->m_fTimeElapsed;
    v1->m_fPrevInstantSpeed = v1->m_fAutomationValues[0];
  }
  else
  {
    this->m_fDistanceTraveled = (float)(this->m_fTimeElapsed / this->m_fEffectiveDuration) * this->m_fTotalPathDistance;
  }
}

// File Line: 264
// RVA: 0xADB7C0
void __fastcall CAkSoundSeedWooshProcess::Prepare(CAkSoundSeedWooshProcess *this, unsigned int in_uNumFrames)
{
  float v2; // xmm1_4
  unsigned int v3; // edi
  CAkSoundSeedWooshProcess *v4; // rbx

  v2 = this->m_fAutomationValues[1];
  v3 = in_uNumFrames;
  v4 = this;
  this->m_fEffectiveSpeedValue = (float)(this->m_pParams->fBaseValue[0] + this->m_fRandomSpeed)
                               + this->m_fAutomationValues[0];
  CAkSoundSeedWooshProcess::ComputeEffectiveFrequencyScale(this, v2);
  CAkSoundSeedWooshProcess::ComputeEffectiveQFactorScale(v4, v4->m_fAutomationValues[2]);
  CAkSoundSeedWooshProcess::ComputeEffectiveGainOffset(v4, v4->m_fAutomationValues[3]);
  CAkSoundSeedWooshProcess::ComputeDeflectorAirVelocities(v4);
  CAkSoundSeedWooshProcess::ComputeDistanceToAdvance(v4);
  CAkSoundSeedWooshProcess::ComputeObjectPosition(v4);
  if ( v4->m_bInitGainRamps )
  {
    CAkSoundSeedWooshProcess::InitDeflectorGainRamp(v4);
    if ( v4->m_uNumChannels > 1 )
      CAkSoundSeedWooshProcess::InitSpatialization(v4);
    v4->m_bInitGainRamps = 0;
  }
  else
  {
    CAkSoundSeedWooshProcess::ComputeDeflectorGains(v4, v3);
    if ( v4->m_uNumChannels > 1 )
      CAkSoundSeedWooshProcess::ComputeSpatialization(v4, v3);
  }
  CAkSoundSeedWooshProcess::ComputeFilterCoefficients(v4);
  v4->m_uChangeMask = 0;
}

// File Line: 301
// RVA: 0xADB890
void __fastcall CAkSoundSeedWooshProcess::Process(CAkSoundSeedWooshProcess *this, AkAudioBuffer *io_pBufferOut, float *in_pfTempStorage)
{
  switch ( this->m_uNumChannels )
  {
    case 1u:
      CAkSoundSeedWooshProcess::ProcessMono(this, io_pBufferOut, in_pfTempStorage);
      break;
    case 2u:
      CAkSoundSeedWooshProcess::ProcessStereo(this, io_pBufferOut, in_pfTempStorage);
      break;
    case 4u:
      CAkSoundSeedWooshProcess::ProcessQuad(this, io_pBufferOut, in_pfTempStorage);
      break;
  }
}

// File Line: 321
// RVA: 0xADBBB0
void __fastcall CAkSoundSeedWooshProcess::ComputeDeflectorAirVelocities(CAkSoundSeedWooshProcess *this)
{
  CAkSoundSeedWooshProcess *v1; // rbx
  float v2; // xmm0_4
  signed __int64 v3; // r8
  signed int v4; // ecx
  float v5; // xmm1_4
  signed int v6; // ebp
  signed __int64 v7; // r11
  signed __int64 v8; // rdx
  signed __int64 v9; // rsi
  unsigned __int64 v10; // rdi
  int v11; // er8
  __int64 v12; // r10
  signed __int64 v13; // rdi
  int v14; // er9
  float v15; // xmm2_4
  int v16; // eax
  int v17; // eax
  signed int v18; // eax
  int v19; // eax
  signed int v20; // er9
  signed int v21; // ecx
  signed __int64 v22; // r8
  signed __int64 v23; // rdx
  signed int v24; // eax
  __int64 v25; // rcx
  unsigned __int64 v26; // r8
  signed __int64 v27; // rcx
  signed __int64 v28; // rdx

  v1 = this;
  v2 = powf(2.0, (float)(this->m_fEffectiveSpeedValue * 0.02) - 2.0);
  v3 = (signed int)v1->m_cDeflectors;
  v4 = v1->m_pParams->iAnchorIndex;
  v5 = v2 * 16.0;
  if ( (_DWORD)v3 == 1 && v4 != -1 )
    v4 = -1;
  v6 = v3 - v4 - 1;
  if ( v6 <= v4 )
    v6 = v4;
  v7 = 0i64;
  v8 = (signed int)v1->m_cDeflectors;
  if ( v4 == -1 )
  {
    if ( v3 >= 4 )
    {
      v25 = 0i64;
      v26 = ((unsigned __int64)(v3 - 4) >> 2) + 1;
      v7 = 4 * v26;
      do
      {
        v25 += 4i64;
        v1->m_pDeflectorInfo[v25 - 4].fVelocity = v5;
        v1->m_pDeflectorInfo[v25 - 3].fVelocity = v5;
        v1->m_pDeflectorInfo[v25 - 2].fVelocity = v5;
        v1->m_pDeflectorInfo[v25 - 1].fVelocity = v5;
        --v26;
      }
      while ( v26 );
    }
    if ( v7 < v8 )
    {
      v27 = v7;
      v28 = v8 - v7;
      do
      {
        ++v27;
        v1->m_pDeflectorInfo[v27 - 1].fVelocity = v5;
        --v28;
      }
      while ( v28 );
    }
  }
  else
  {
    v9 = 0i64;
    if ( v3 >= 4 )
    {
      v10 = (unsigned __int64)(v3 - 4) >> 2;
      v11 = 2 - v4;
      v12 = 0i64;
      v13 = v10 + 1;
      v14 = v4 - 2;
      LODWORD(v7) = 4 * v13;
      v9 = 4 * v13;
      v15 = 1.0 / (float)v6;
      do
      {
        v16 = v14 + 2;
        if ( v14 + 2 < 0 )
          v16 = v11 - 2;
        v1->m_pDeflectorInfo[v12].fVelocity = (float)((float)v16 * v15) * v5;
        v17 = v14 + 1;
        if ( v14 + 1 < 0 )
          v17 = v11 - 1;
        v1->m_pDeflectorInfo[v12 + 1].fVelocity = (float)((float)v17 * v15) * v5;
        v18 = v11;
        if ( v14 >= 0 )
          v18 = v14;
        v1->m_pDeflectorInfo[v12 + 2].fVelocity = (float)((float)v18 * v15) * v5;
        v19 = v14 - 1;
        if ( v14 - 1 < 0 )
          v19 = v11 + 1;
        v12 += 4i64;
        v14 -= 4;
        v11 += 4;
        v1->m_pDeflectorInfo[v12 - 1].fVelocity = (float)((float)v19 * v15) * v5;
        --v13;
      }
      while ( v13 );
    }
    if ( v9 < v8 )
    {
      v20 = v7 - v4;
      v21 = v4 - v7;
      v22 = v9;
      v23 = v8 - v9;
      do
      {
        v24 = v20;
        ++v22;
        if ( v21 >= 0 )
          v24 = v21;
        --v21;
        ++v20;
        v1->m_pDeflectorInfo[v22 - 1].fVelocity = (float)((float)v24 * (float)(1.0 / (float)v6)) * v5;
        --v23;
      }
      while ( v23 );
    }
  }
}

// File Line: 351
// RVA: 0xADBE30
void __fastcall CAkSoundSeedWooshProcess::ComputeFilterCoefficients(CAkSoundSeedWooshProcess *this)
{
  unsigned int v1; // er14
  unsigned int v2; // ebp
  CAkSoundSeedWooshProcess *v3; // rsi
  float v4; // xmm8_4
  __int64 v5; // rdi
  DeflectorInfo *v6; // rax
  float v7; // xmm6_4
  float v8; // xmm10_4
  float v9; // xmm7_4
  signed __int64 v10; // rbx

  v1 = this->m_cDeflectors;
  v2 = 0;
  v3 = this;
  v4 = (float)(signed int)this->m_uSampleRate * 0.5;
  if ( v1 )
  {
    v5 = 0i64;
    do
    {
      v6 = v3->m_pDeflectorInfo;
      v7 = (float)(v6[v5].fEffectiveFrequency * v6[v5].fVelocity) * 0.0625;
      if ( v7 >= v4 )
        v7 = v4;
      if ( v7 <= 20.0 )
        v7 = FLOAT_20_0;
      v8 = v3->m_fSamplePeriod;
      v9 = expf((float)((float)((float)((float)(v7 / v6[v5].fEffectiveQFactor) * 2.0) * 3.1415927) * v8) * -0.5);
      if ( v9 >= 0.99919999 )
        v9 = FLOAT_0_99919999;
      v10 = (v2 & 3) + 28i64 * (v2 >> 2);
      ++v2;
      ++v5;
      v3->m_pDeflectorDSPInfo->fCoefsA1[v10] = cosf((float)(v7 * 6.2831855) * v8) * (float)(v9 * 2.0);
      LODWORD(v3->m_pDeflectorDSPInfo->fCoefsA2[v10]) = COERCE_UNSIGNED_INT(v9 * v9) ^ _xmm[0];
    }
    while ( v2 < v1 );
  }
}

// File Line: 381
// RVA: 0xADCFD0
float __fastcall CAkSoundSeedWooshProcess::EqualizeTunable(CAkSoundSeedWooshProcess *this, float in_fCenterFrequency, float in_fQ)
{
  CAkSoundSeedWooshProcess *v3; // rbx
  DSP::CAkColoredNoise::AkNoiseColor v4; // er8
  int v5; // er8
  int v6; // er8
  float v7; // xmm6_4
  float v8; // xmm9_4
  float v9; // xmm7_4
  float v11; // [rsp+78h] [rbp+10h]

  v3 = this;
  v4 = this->m_pParams->eNoiseColor;
  if ( v4 )
  {
    v5 = v4 - 1;
    if ( v5 )
    {
      v6 = v5 - 1;
      if ( v6 )
      {
        if ( v6 == 1 )
          v7 = 650.0 / in_fCenterFrequency;
        else
          v7 = v11;
      }
      else
      {
        v7 = in_fCenterFrequency * 0.0099999998;
      }
    }
    else
    {
      v7 = fsqrt(in_fCenterFrequency * 0.025);
    }
  }
  else
  {
    v7 = *(float *)&FLOAT_1_0;
  }
  v8 = logf(in_fCenterFrequency / in_fQ) * 1.442695;
  v9 = expf((float)((float)((float)((float)(in_fCenterFrequency / in_fQ) * 2.0) * 3.1415927) * v3->m_fSamplePeriod) * -0.5);
  if ( v9 >= 0.99919999 )
    v9 = FLOAT_0_99919999;
  return (float)((float)(expf((float)((float)(v8 * -0.023) * v8) + (float)((float)(v8 * -0.1648) + 3.9542999))
                       + 0.69999999)
               * v7)
       * (float)((float)(1.0 - (float)(v9 * v9)) * 0.5);
}

// File Line: 429
// RVA: 0xADC020
float __fastcall CAkSoundSeedWooshProcess::ComputeCombinedGain(CAkSoundSeedWooshProcess *this, float in_fDeflectorGain, float in_fVelocity, float in_fDistanceAttenuation, float in_fCenterFrequency, float in_fQfactor)
{
  CAkSoundSeedWooshProcess *v6; // rbx
  float v7; // xmm0_4

  v6 = this;
  v7 = CAkSoundSeedWooshProcess::EqualizeTunable(this, in_fCenterFrequency, in_fQfactor);
  return v7
       * (float)((float)(powf(
                           in_fVelocity * 0.0625,
                           (float)((float)(v6->m_pParams->fDynamicRange + 1.0) * 48.0) * 0.041524101)
                       * in_fDeflectorGain)
               * in_fDistanceAttenuation);
}

// File Line: 442
// RVA: 0xADC670
void __fastcall CAkSoundSeedWooshProcess::ComputeDistanceBasedAttenuation(CAkSoundSeedWooshProcess *this, float in_fDistance)
{
  AkWooshParams *v2; // rbx
  float v3; // xmm2_4
  float v4; // xmm1_4

  v2 = this->m_pParams;
  if ( v2->bEnableDistanceBasedAttenuation )
  {
    v3 = v2->fMinDistance * 0.0099999998;
    if ( in_fDistance > v3 )
    {
      v4 = (float)(logf(in_fDistance / v3) * 1.442695) * (float)(v2->fAttenuationRolloff * -6.0);
      powf(10.0, v4 * 0.050000001);
    }
  }
}

// File Line: 464
// RVA: 0xADC0D0
void __fastcall CAkSoundSeedWooshProcess::InitDeflectorGainRamp(CAkSoundSeedWooshProcess *this)
{
  unsigned int v1; // er15
  CAkSoundSeedWooshProcess *v2; // rdi
  unsigned int v3; // er14
  __int64 v4; // rbp
  __m128 v5; // xmm1
  AkWooshParams *v6; // rsi
  float v7; // xmm7_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  DeflectorInfo *v11; // rbx
  float v12; // xmm6_4
  float v13; // xmm0_4
  __int64 v14; // rax
  __int64 v15; // rdx
  signed __int64 v16; // rdx
  float v17; // xmm6_4

  v1 = this->m_cDeflectors;
  v2 = this;
  v3 = 0;
  if ( v1 )
  {
    v4 = 0i64;
    do
    {
      v5 = (__m128)LODWORD(v2->m_fCurrentPosX);
      v6 = v2->m_pParams;
      v7 = *(float *)&FLOAT_1_0;
      v5.m128_f32[0] = (float)(v5.m128_f32[0] * v5.m128_f32[0]) + (float)(v2->m_fCurrentPosY * v2->m_fCurrentPosY);
      LODWORD(v8) = (unsigned __int128)_mm_sqrt_ps(v5);
      if ( v6->bEnableDistanceBasedAttenuation )
      {
        v9 = v6->fMinDistance * 0.0099999998;
        if ( v8 > v9 )
        {
          v10 = (float)(logf(v8 / v9) * 1.442695) * (float)(v6->fAttenuationRolloff * -6.0);
          v7 = powf(10.0, v10 * 0.050000001);
        }
      }
      v11 = v2->m_pDeflectorInfo;
      v12 = CAkSoundSeedWooshProcess::EqualizeTunable(v2, v11[v4].fEffectiveFrequency, v11[v4].fEffectiveQFactor);
      v13 = powf(v11[v4].fVelocity * 0.0625, (float)((float)(v6->fDynamicRange + 1.0) * 48.0) * 0.041524101)
          * v11[v4].fEffectiveGain;
      v14 = v3 & 3;
      v15 = v3++ >> 2;
      ++v4;
      v16 = v14 + 28 * v15;
      v17 = v12 * (float)(v13 * v7);
      v2->m_pDeflectorDSPInfo->fGainDelta[v16] = 0.0;
      v2->m_pDeflectorDSPInfo->fTargetGain[v16] = v17;
      v2->m_pDeflectorDSPInfo->fGain[v16] = v17;
    }
    while ( v3 < v1 );
  }
}

// File Line: 492
// RVA: 0xADC310
void __fastcall CAkSoundSeedWooshProcess::ComputeDeflectorGains(CAkSoundSeedWooshProcess *this, unsigned int in_uNumFrames)
{
  unsigned int v2; // er15
  unsigned int v3; // ebp
  CAkSoundSeedWooshProcess *v4; // rdi
  __int64 v5; // r14
  float v6; // xmm10_4
  __m128 v7; // xmm1
  AkWooshParams *v8; // rsi
  float v9; // xmm7_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  DeflectorInfo *v13; // rbx
  float v14; // xmm6_4
  float v15; // xmm0_4
  __int64 v16; // rax
  __int64 v17; // rdx
  signed __int64 v18; // rdx
  float v19; // xmm6_4

  v2 = this->m_cDeflectors;
  v3 = 0;
  v4 = this;
  if ( v2 )
  {
    v5 = 0i64;
    v6 = 1.0 / (float)(signed int)in_uNumFrames;
    do
    {
      v7 = (__m128)LODWORD(v4->m_fCurrentPosX);
      v8 = v4->m_pParams;
      v9 = *(float *)&FLOAT_1_0;
      v7.m128_f32[0] = (float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v4->m_fCurrentPosY * v4->m_fCurrentPosY);
      LODWORD(v10) = (unsigned __int128)_mm_sqrt_ps(v7);
      if ( v8->bEnableDistanceBasedAttenuation )
      {
        v11 = v8->fMinDistance * 0.0099999998;
        if ( v10 > v11 )
        {
          v12 = (float)(logf(v10 / v11) * 1.442695) * (float)(v8->fAttenuationRolloff * -6.0);
          v9 = powf(10.0, v12 * 0.050000001);
        }
      }
      v13 = v4->m_pDeflectorInfo;
      v14 = CAkSoundSeedWooshProcess::EqualizeTunable(v4, v13[v5].fEffectiveFrequency, v13[v5].fEffectiveQFactor);
      v15 = powf(v13[v5].fVelocity * 0.0625, (float)((float)(v8->fDynamicRange + 1.0) * 48.0) * 0.041524101)
          * v13[v5].fEffectiveGain;
      v16 = v3 & 3;
      v17 = v3++ >> 2;
      ++v5;
      v18 = v16 + 28 * v17;
      v19 = v14 * (float)(v15 * v9);
      v4->m_pDeflectorDSPInfo->fGainDelta[v18] = (float)(v19 - v4->m_pDeflectorDSPInfo->fGain[v18]) * v6;
      v4->m_pDeflectorDSPInfo->fTargetGain[v18] = v19;
    }
    while ( v3 < v2 );
  }
}

// File Line: 521
// RVA: 0xADC550
void __fastcall CAkSoundSeedWooshProcess::DeflectorGainRampCompleted(CAkSoundSeedWooshProcess *this)
{
  unsigned int v1; // er10
  unsigned int v2; // er8
  unsigned int v3; // er11
  char v4; // al
  unsigned int v5; // edx
  signed __int64 v6; // rdx
  signed __int64 v7; // rdx
  signed __int64 v8; // rdx
  __int64 v9; // rax
  __int64 v10; // rdx
  signed __int64 v11; // rdx
  char v12; // al
  unsigned int v13; // edx
  signed __int64 v14; // rdx

  v1 = this->m_cDeflectors;
  v2 = 0;
  if ( (signed int)v1 >= 4 )
  {
    v3 = 1;
    do
    {
      v4 = v2;
      v5 = v2;
      v2 += 4;
      v6 = (v4 & 3) + 28i64 * (v5 >> 2);
      this->m_pDeflectorDSPInfo->fGainDelta[v6] = 0.0;
      this->m_pDeflectorDSPInfo->fGain[v6] = this->m_pDeflectorDSPInfo->fTargetGain[v6];
      v7 = (v3 & 3) + 28i64 * (v3 >> 2);
      this->m_pDeflectorDSPInfo->fGainDelta[v7] = 0.0;
      this->m_pDeflectorDSPInfo->fGain[v7] = this->m_pDeflectorDSPInfo->fTargetGain[v7];
      v8 = (((_BYTE)v3 + 1) & 3) + 28i64 * ((v3 + 1) >> 2);
      this->m_pDeflectorDSPInfo->fGainDelta[v8] = 0.0;
      this->m_pDeflectorDSPInfo->fGain[v8] = this->m_pDeflectorDSPInfo->fTargetGain[v8];
      v9 = ((_BYTE)v3 - 2) & 3;
      v10 = (v3 + 2) >> 2;
      v3 += 4;
      v11 = v9 + 28 * v10;
      this->m_pDeflectorDSPInfo->fGainDelta[v11] = 0.0;
      this->m_pDeflectorDSPInfo->fGain[v11] = this->m_pDeflectorDSPInfo->fTargetGain[v11];
    }
    while ( v2 < v1 - 3 );
  }
  for ( ; v2 < v1; this->m_pDeflectorDSPInfo->fGain[v14] = this->m_pDeflectorDSPInfo->fTargetGain[v14] )
  {
    v12 = v2;
    v13 = v2++;
    v14 = (v12 & 3) + 28i64 * (v13 >> 2);
    this->m_pDeflectorDSPInfo->fGainDelta[v14] = 0.0;
  }
}

// File Line: 538
// RVA: 0xADCA20
void __fastcall CAkSoundSeedWooshProcess::ComputeSpatialization(CAkSoundSeedWooshProcess *this, unsigned int in_uNumFrames)
{
  signed int v2; // er15
  CAkSoundSeedWooshProcess *v3; // r14
  float *v4; // rbp
  float *v5; // rdi
  float *v6; // rsi
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float *v11; // rdi
  float v12; // xmm2_4
  float v13; // xmm0_4

  v2 = in_uNumFrames;
  v3 = this;
  if ( this->m_uNumChannels == 2 )
  {
    v11 = &this->m_PositioningInfo.fChanGainTarget[1];
    CAkSoundSeedWooshProcess::ComputeStereoGains(
      this,
      this->m_fCurrentPosX,
      this->m_fCurrentPosY,
      this->m_PositioningInfo.fChanGainTarget,
      &this->m_PositioningInfo.fChanGainTarget[1]);
    v12 = 1.0 / (float)v2;
    v13 = (float)(*v11 - v3->m_PositioningInfo.fChanGain[1]) * v12;
    v3->m_PositioningInfo.fChanGainDelta[0] = (float)(v3->m_PositioningInfo.fChanGainTarget[0]
                                                    - v3->m_PositioningInfo.fChanGain[0])
                                            * v12;
    v3->m_PositioningInfo.fChanGainDelta[1] = v13;
  }
  else if ( this->m_uNumChannels == 4 )
  {
    v4 = &this->m_PositioningInfo.fChanGainTarget[3];
    v5 = &this->m_PositioningInfo.fChanGainTarget[1];
    v6 = &this->m_PositioningInfo.fChanGainTarget[2];
    CAkSoundSeedWooshProcess::ComputeQuadGains(
      this,
      this->m_fCurrentPosX,
      this->m_fCurrentPosY,
      this->m_PositioningInfo.fChanGainTarget,
      &this->m_PositioningInfo.fChanGainTarget[1],
      &this->m_PositioningInfo.fChanGainTarget[2],
      &this->m_PositioningInfo.fChanGainTarget[3]);
    v7 = 1.0 / (float)v2;
    v8 = (float)(*v5 - v3->m_PositioningInfo.fChanGain[1]) * v7;
    v3->m_PositioningInfo.fChanGainDelta[0] = (float)(v3->m_PositioningInfo.fChanGainTarget[0]
                                                    - v3->m_PositioningInfo.fChanGain[0])
                                            * v7;
    v9 = *v6 - v3->m_PositioningInfo.fChanGain[2];
    v3->m_PositioningInfo.fChanGainDelta[1] = v8;
    v10 = *v4 - v3->m_PositioningInfo.fChanGain[3];
    v3->m_PositioningInfo.fChanGainDelta[2] = v9 * v7;
    v3->m_PositioningInfo.fChanGainDelta[3] = v10 * v7;
  }
}

// File Line: 566
// RVA: 0xADCBA0
void __fastcall CAkSoundSeedWooshProcess::SpatializationGainRampCompleted(CAkSoundSeedWooshProcess *this)
{
  if ( this->m_uNumChannels == 2 )
  {
    *(_QWORD *)this->m_PositioningInfo.fChanGainDelta = 0i64;
    this->m_PositioningInfo.fChanGain[0] = this->m_PositioningInfo.fChanGainTarget[0];
    this->m_PositioningInfo.fChanGain[1] = this->m_PositioningInfo.fChanGainTarget[1];
  }
  else if ( this->m_uNumChannels == 4 )
  {
    *(_QWORD *)this->m_PositioningInfo.fChanGainDelta = 0i64;
    *(_QWORD *)&this->m_PositioningInfo.fChanGainDelta[2] = 0i64;
    this->m_PositioningInfo.fChanGain[0] = this->m_PositioningInfo.fChanGainTarget[0];
    this->m_PositioningInfo.fChanGain[1] = this->m_PositioningInfo.fChanGainTarget[1];
    this->m_PositioningInfo.fChanGain[2] = this->m_PositioningInfo.fChanGainTarget[2];
    this->m_PositioningInfo.fChanGain[3] = this->m_PositioningInfo.fChanGainTarget[3];
  }
}

// File Line: 590
// RVA: 0xADCC00
void __fastcall CAkSoundSeedWooshProcess::ComputeEffectiveSpeed(CAkSoundSeedWooshProcess *this, float in_fAutomationValue)
{
  this->m_fEffectiveSpeedValue = (float)(this->m_pParams->fBaseValue[0] + this->m_fRandomSpeed) + in_fAutomationValue;
}

// File Line: 597
// RVA: 0xADCC20
void __fastcall CAkSoundSeedWooshProcess::ComputeEffectiveFrequencyScale(CAkSoundSeedWooshProcess *this, float in_fAutomationValue)
{
  CAkSoundSeedWooshProcess *v2; // rsi
  float v3; // xmm7_4
  unsigned int v4; // eax
  __int64 v5; // rdi
  __int64 v6; // r14
  __int64 v7; // rbp
  DeflectorInfo *v8; // rbx
  float v9; // xmm0_4

  v2 = this;
  v3 = this->m_pParams->fBaseValue[1];
  v4 = this->m_cDeflectors;
  if ( v4 )
  {
    v5 = 0i64;
    v6 = v4;
    v7 = 0i64;
    do
    {
      v8 = v2->m_pDeflectorInfo;
      v9 = powf(2.0, (float)(v3 + v8[v5].fRandomFrequency) + in_fAutomationValue);
      ++v5;
      ++v7;
      *((float *)&v8[v5] - 6) = v9 * v2->m_pDeflectors[v7 - 1].fFrequency;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 612
// RVA: 0xADCCE0
void __fastcall CAkSoundSeedWooshProcess::ComputeEffectiveQFactorScale(CAkSoundSeedWooshProcess *this, float in_fAutomationValue)
{
  CAkSoundSeedWooshProcess *v2; // r14
  float v3; // xmm9_4
  unsigned int v4; // eax
  __int64 v5; // rbx
  __int64 v6; // rsi
  __int64 v7; // rdi
  DeflectorInfo *v8; // rbp
  float v9; // xmm0_4

  v2 = this;
  v3 = this->m_pParams->fBaseValue[2];
  v4 = this->m_cDeflectors;
  if ( v4 )
  {
    v5 = 0i64;
    v6 = v4;
    v7 = 0i64;
    do
    {
      v8 = v2->m_pDeflectorInfo;
      v9 = powf(2.0, (float)(v3 + v8[v5].fRandomQFactor) + in_fAutomationValue) * v2->m_pDeflectors[v7].fQFactor;
      if ( v9 < 50.0 )
      {
        if ( v9 <= 0.1 )
          v9 = FLOAT_0_1;
      }
      else
      {
        v9 = FLOAT_50_0;
      }
      v8[v5].fEffectiveQFactor = v9;
      ++v5;
      ++v7;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 630
// RVA: 0xADCDF0
void __fastcall CAkSoundSeedWooshProcess::ComputeEffectiveGainOffset(CAkSoundSeedWooshProcess *this, float in_fAutomationValue)
{
  CAkSoundSeedWooshProcess *v2; // rbx
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
  v3 = this->m_pParams->fBaseValue[3];
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
      v14 = (float)(v3 * v13[v9].fRandomGain) * v8;
      if ( v14 < 16.0 )
      {
        if ( v14 <= 0.0 )
          v14 = 0.0;
      }
      else
      {
        v14 = FLOAT_16_0;
      }
      v13[v9].fEffectiveGain = v14 * v2->m_pDeflectors[v10].fGain;
      v15 = v2->m_pDeflectorInfo;
      v16 = (float)(v3 * v15[v9 + 1].fRandomGain) * v8;
      if ( v16 < 16.0 )
      {
        if ( v16 <= 0.0 )
          v16 = 0.0;
      }
      else
      {
        v16 = FLOAT_16_0;
      }
      v15[v9 + 1].fEffectiveGain = v16 * v2->m_pDeflectors[v10 + 1].fGain;
      v17 = v2->m_pDeflectorInfo;
      v18 = (float)(v3 * v17[v9 + 2].fRandomGain) * v8;
      if ( v18 < 16.0 )
      {
        if ( v18 <= 0.0 )
          v18 = 0.0;
      }
      else
      {
        v18 = FLOAT_16_0;
      }
      v17[v9 + 2].fEffectiveGain = v18 * v2->m_pDeflectors[v10 + 2].fGain;
      v19 = v2->m_pDeflectorInfo;
      v20 = (float)(v3 * v19[v9 + 3].fRandomGain) * v8;
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
      v9 += 4i64;
      v10 += 4i64;
      *((float *)&v19[v9] - 4) = v21;
      --v12;
    }
    while ( v12 );
  }
  if ( v6 < v5 )
  {
    v22 = v7;
    v23 = v7;
    v24 = v5 - v6;
    do
    {
      v25 = v2->m_pDeflectorInfo;
      v26 = (float)(v3 * v25[v23].fRandomGain) * v8;
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
      ++v23;
      ++v22;
      *((float *)&v25[v23] - 4) = v27;
      --v24;
    }
    while ( v24 );
  }
}

// File Line: 655
// RVA: 0xADD120
void __fastcall CAkSoundSeedWooshProcess::ProcessMono(CAkSoundSeedWooshProcess *this, AkAudioBuffer *io_pBufferOut, float *in_pfTempStorage)
{
  signed int v3; // er15
  CAkSoundSeedWooshProcess *v4; // rbx
  __int64 v5; // r12
  __int64 v6; // r13
  float *v7; // rsi
  __m128 v8; // xmm1
  signed int v9; // ecx
  __int64 v10; // r8
  float *v11; // r14
  unsigned int v12; // edi
  unsigned int v13; // ecx
  int v14; // eax
  float v15; // ecx
  DSP::CAkColoredNoise *v16; // rcx
  __int64 v17; // rdx
  __int64 v18; // r11
  __int64 v19; // rcx
  DeflectorDSP *v20; // rax
  float *v21; // r9
  __int128 v22; // xmm0
  __m128 v23; // xmm3
  __m128 v24; // xmm6
  __m128 v25; // xmm7
  __m128 v26; // xmm8
  __m128 v27; // xmm4
  __m128 v28; // xmm5
  float *v29; // r8
  __int64 v30; // r10
  __m128 v31; // xmm0
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  __m128 v34; // xmm0
  __m128 *v35; // rdx
  signed __int64 v36; // r8
  __int64 v37; // rax
  __m128 v38; // xmm1
  __m128 v39; // xmm1
  unsigned int v40; // [rsp+110h] [rbp+8h]
  AkAudioBuffer *v41; // [rsp+118h] [rbp+10h]
  size_t Size; // [rsp+120h] [rbp+18h]
  __int64 v43; // [rsp+128h] [rbp+20h]

  v41 = io_pBufferOut;
  v3 = io_pBufferOut->uValidFrames;
  v8 = 0i64;
  v4 = this;
  v5 = 0i64;
  v40 = (this->m_cDeflectors + 3) >> 2;
  v6 = 0i64;
  v7 = in_pfTempStorage;
  v8.m128_f32[0] = (float)v3 / (float)(signed int)this->m_uOversamplingFactor;
  v9 = (signed int)v8.m128_f32[0];
  if ( (signed int)v8.m128_f32[0] != 0x80000000 && (float)v9 != v8.m128_f32[0] )
    v8.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v8, v8)) & 1 ^ 1) + v9);
  v10 = ((signed int)v8.m128_f32[0] + 3) & 0xFFFFFFFC;
  v43 = v10;
  v11 = &v7[v10];
  if ( io_pBufferOut->uValidFrames )
  {
    Size = (unsigned int)(16 * v10);
    do
    {
      v12 = v10;
      v4->m_fAutomationValues[0] = v4->m_pfAutomationValues[v6];
      v4->m_fAutomationValues[1] = v4->m_pfAutomationValues[(unsigned int)(v6 + v4->m_uOversamplingFactor)];
      v4->m_fAutomationValues[2] = v4->m_pfAutomationValues[(unsigned int)(v6 + 2 * v4->m_uOversamplingFactor)];
      v13 = v4->m_uOversamplingFactor;
      v14 = v6 + 2 * v13;
      v6 = (unsigned int)(v6 + 1);
      v15 = v4->m_pfAutomationValues[v14 + v13];
      if ( v3 < (unsigned int)v10 )
        v12 = v3;
      v4->m_fAutomationValues[3] = v15;
      CAkSoundSeedWooshProcess::Prepare(v4, v12);
      if ( v4->m_NoiseGen.m_NoiseColor == 1 )
      {
        DSP::CAkColoredNoise::GenerateBufferPink(&v4->m_NoiseGen, v7, v12);
      }
      else if ( v4->m_NoiseGen.m_NoiseColor == 2 )
      {
        DSP::CAkColoredNoise::GenerateBufferRed(&v4->m_NoiseGen, v7, v12);
      }
      else
      {
        v16 = &v4->m_NoiseGen;
        if ( v4->m_NoiseGen.m_NoiseColor == 3 )
          DSP::CAkColoredNoise::GenerateBufferPurple(v16, v7, v12);
        else
          DSP::CAkWhiteNoise::GenerateBuffer((DSP::CAkWhiteNoise *)&v16->m_uLCGState, v7, v12);
      }
      memset(v11, 0, Size);
      if ( v40 )
      {
        v17 = 0i64;
        v18 = v40;
        v19 = 0i64;
        do
        {
          v20 = v4->m_pDeflectorDSPInfo;
          v21 = v11;
          v22 = *(_OWORD *)v20[v17].fTargetGain;
          v23 = *(__m128 *)v20[v17].fGain;
          v24 = *(__m128 *)v20[v17].fGainDelta;
          v25 = *(__m128 *)v20[v17].fCoefsA1;
          v26 = *(__m128 *)v20[v17].fCoefsA2;
          v27 = *(__m128 *)v20[v17].fFiltState1;
          v28 = *(__m128 *)v20[v17].fFiltState2;
          if ( v12 )
          {
            v29 = v7;
            v30 = v12;
            do
            {
              v31 = (__m128)*(unsigned int *)v29;
              v23 = _mm_add_ps(v23, v24);
              v21 += 4;
              ++v29;
              v32 = _mm_mul_ps(v28, v26);
              v33 = _mm_add_ps(_mm_mul_ps(v27, v25), _mm_shuffle_ps(v31, v31, 0));
              v34 = v28;
              v28 = v27;
              v27 = _mm_add_ps(v33, v32);
              *((__m128 *)v21 - 1) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v27, v34), v23), *(__m128 *)((char *)v21 - 16));
              --v30;
            }
            while ( v30 );
          }
          *(__m128 *)v20[v19].fFiltState1 = v27;
          ++v19;
          ++v17;
          *((__m128 *)&v4->m_pDeflectorDSPInfo[v19] - 1) = v28;
          *(__m128 *)v4->m_pDeflectorDSPInfo[v19 - 1].fGain = v23;
          --v18;
        }
        while ( v18 );
      }
      v35 = (__m128 *)v11;
      v36 = (signed __int64)v41->pData + 4 * v5;
      if ( v12 )
      {
        v37 = v12;
        do
        {
          v38 = *v35;
          v36 += 4i64;
          ++v35;
          v39 = _mm_add_ps(v38, _mm_movehl_ps(v38, v38));
          *(float *)(v36 - 4) = COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 85)) + v39.m128_f32[0];
          --v37;
        }
        while ( v37 );
      }
      CAkSoundSeedWooshProcess::DeflectorGainRampCompleted(v4);
      LODWORD(v10) = v43;
      v5 = v12 + (unsigned int)v5;
      v3 -= v12;
    }
    while ( v3 );
  }
}

// File Line: 762
// RVA: 0xADD440
void __fastcall CAkSoundSeedWooshProcess::ProcessStereo(CAkSoundSeedWooshProcess *this, AkAudioBuffer *io_pBufferOut, float *in_pfTempStorage)
{
  signed int v3; // er12
  __int64 v4; // rsi
  CAkSoundSeedWooshProcess *v5; // rbx
  float *v6; // r14
  int v7; // er8
  unsigned int v8; // er13
  __m128 v9; // xmm1
  signed int v10; // ecx
  __int64 v11; // r9
  float *v12; // r15
  unsigned int v13; // edi
  unsigned int v14; // ecx
  int v15; // eax
  int v16; // er8
  float v17; // ecx
  DSP::CAkColoredNoise *v18; // rcx
  __int64 v19; // rdx
  __int64 v20; // r11
  __int64 v21; // rcx
  DeflectorDSP *v22; // rax
  float *v23; // r9
  __int128 v24; // xmm0
  __m128 v25; // xmm3
  __m128 v26; // xmm6
  __m128 v27; // xmm7
  __m128 v28; // xmm8
  __m128 v29; // xmm4
  __m128 v30; // xmm5
  float *v31; // r8
  __int64 v32; // r10
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  __m128 v36; // xmm0
  __m128 *v37; // rcx
  signed __int64 v38; // rdx
  __int64 v39; // rax
  __m128 v40; // xmm1
  __m128 v41; // xmm1
  unsigned int v42; // edx
  __m128 v43; // xmm2
  __m128 v44; // xmm3
  __m128 v45; // xmm4
  signed __int64 v46; // rcx
  __m128 i; // xmm5
  __m128 v48; // xmm1
  __m128 v49; // xmm0
  float v50; // eax
  float v51; // eax
  unsigned int v52; // [rsp+20h] [rbp-F8h]
  int v53; // [rsp+120h] [rbp+8h]
  AkAudioBuffer *v54; // [rsp+128h] [rbp+10h]
  int v55; // [rsp+130h] [rbp+18h]
  size_t Size; // [rsp+138h] [rbp+20h]

  v54 = io_pBufferOut;
  v3 = io_pBufferOut->uValidFrames;
  v9 = 0i64;
  v4 = 0i64;
  v5 = this;
  v6 = in_pfTempStorage;
  v7 = 0;
  v8 = (this->m_cDeflectors + 3) >> 2;
  v53 = 0;
  v9.m128_f32[0] = (float)v3 / (float)(signed int)this->m_uOversamplingFactor;
  v10 = (signed int)v9.m128_f32[0];
  if ( (signed int)v9.m128_f32[0] != 0x80000000 && (float)v10 != v9.m128_f32[0] )
    v9.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v9, v9)) & 1 ^ 1) + v10);
  v11 = ((signed int)v9.m128_f32[0] + 3) & 0xFFFFFFFC;
  v52 = ((signed int)v9.m128_f32[0] + 3) & 0xFFFFFFFC;
  v12 = &v6[v11];
  if ( io_pBufferOut->uValidFrames )
  {
    Size = (unsigned int)(16 * v11);
    do
    {
      v13 = v11;
      v5->m_fAutomationValues[0] = v5->m_pfAutomationValues[v7];
      v5->m_fAutomationValues[1] = v5->m_pfAutomationValues[v7 + v5->m_uOversamplingFactor];
      v5->m_fAutomationValues[2] = v5->m_pfAutomationValues[v7 + 2 * v5->m_uOversamplingFactor];
      v14 = v5->m_uOversamplingFactor;
      v15 = v7 + 2 * v14;
      v16 = v7 + 1;
      v17 = v5->m_pfAutomationValues[v15 + v14];
      if ( v3 < (unsigned int)v11 )
        v13 = v3;
      v55 = v16;
      v5->m_fAutomationValues[3] = v17;
      CAkSoundSeedWooshProcess::Prepare(v5, v13);
      if ( v5->m_NoiseGen.m_NoiseColor == 1 )
      {
        DSP::CAkColoredNoise::GenerateBufferPink(&v5->m_NoiseGen, v6, v13);
      }
      else if ( v5->m_NoiseGen.m_NoiseColor == 2 )
      {
        DSP::CAkColoredNoise::GenerateBufferRed(&v5->m_NoiseGen, v6, v13);
      }
      else
      {
        v18 = &v5->m_NoiseGen;
        if ( v5->m_NoiseGen.m_NoiseColor == 3 )
          DSP::CAkColoredNoise::GenerateBufferPurple(v18, v6, v13);
        else
          DSP::CAkWhiteNoise::GenerateBuffer((DSP::CAkWhiteNoise *)&v18->m_uLCGState, v6, v13);
      }
      memset(v12, 0, Size);
      if ( v8 )
      {
        v19 = 0i64;
        v20 = v8;
        v21 = 0i64;
        do
        {
          v22 = v5->m_pDeflectorDSPInfo;
          v23 = v12;
          v24 = *(_OWORD *)v22[v19].fTargetGain;
          v25 = *(__m128 *)v22[v19].fGain;
          v26 = *(__m128 *)v22[v19].fGainDelta;
          v27 = *(__m128 *)v22[v19].fCoefsA1;
          v28 = *(__m128 *)v22[v19].fCoefsA2;
          v29 = *(__m128 *)v22[v19].fFiltState1;
          v30 = *(__m128 *)v22[v19].fFiltState2;
          if ( v13 )
          {
            v31 = v6;
            v32 = v13;
            do
            {
              v33 = (__m128)*(unsigned int *)v31;
              v25 = _mm_add_ps(v25, v26);
              v23 += 4;
              ++v31;
              v34 = _mm_mul_ps(v30, v28);
              v35 = _mm_add_ps(_mm_mul_ps(v29, v27), _mm_shuffle_ps(v33, v33, 0));
              v36 = v30;
              v30 = v29;
              v29 = _mm_add_ps(v35, v34);
              *((__m128 *)v23 - 1) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v29, v36), v25), *(__m128 *)((char *)v23 - 16));
              --v32;
            }
            while ( v32 );
          }
          *(__m128 *)v22[v21].fFiltState1 = v29;
          ++v21;
          ++v19;
          *((__m128 *)&v5->m_pDeflectorDSPInfo[v21] - 1) = v30;
          *(__m128 *)v5->m_pDeflectorDSPInfo[v21 - 1].fGain = v25;
          --v20;
        }
        while ( v20 );
      }
      v37 = (__m128 *)v12;
      v38 = (signed __int64)v54->pData + 4 * v4;
      if ( v13 )
      {
        v39 = v13;
        do
        {
          v40 = *v37;
          v38 += 4i64;
          ++v37;
          v41 = _mm_add_ps(v40, _mm_movehl_ps(v40, v40));
          *(float *)(v38 - 4) = COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 85)) + v41.m128_f32[0];
          --v39;
        }
        while ( v39 );
      }
      CAkSoundSeedWooshProcess::DeflectorGainRampCompleted(v5);
      v42 = v13 >> 2;
      v43 = _mm_shuffle_ps(
              (__m128)LODWORD(v5->m_PositioningInfo.fChanGain[0]),
              (__m128)LODWORD(v5->m_PositioningInfo.fChanGain[0]),
              0);
      v44 = _mm_shuffle_ps(
              (__m128)LODWORD(v5->m_PositioningInfo.fChanGain[1]),
              (__m128)LODWORD(v5->m_PositioningInfo.fChanGain[1]),
              0);
      v45 = _mm_shuffle_ps(
              (__m128)LODWORD(v5->m_PositioningInfo.fChanGainDelta[0]),
              (__m128)LODWORD(v5->m_PositioningInfo.fChanGainDelta[0]),
              0);
      v46 = (signed __int64)v54->pData + 4 * v4;
      for ( i = _mm_shuffle_ps(
                  (__m128)LODWORD(v5->m_PositioningInfo.fChanGainDelta[1]),
                  (__m128)LODWORD(v5->m_PositioningInfo.fChanGainDelta[1]),
                  0); v42; --v42 )
      {
        v48 = *(__m128 *)v46;
        v43 = _mm_add_ps(v43, v45);
        v44 = _mm_add_ps(v44, i);
        v49 = *(__m128 *)v46;
        v46 += 16i64;
        *(__m128 *)(v46 - 16) = _mm_mul_ps(v49, v43);
        *(__m128 *)(v46 + 4080) = _mm_mul_ps(v48, v44);
      }
      if ( v5->m_uNumChannels == 2 )
      {
        *(_QWORD *)v5->m_PositioningInfo.fChanGainDelta = 0i64;
        v5->m_PositioningInfo.fChanGain[0] = v5->m_PositioningInfo.fChanGainTarget[0];
        v5->m_PositioningInfo.fChanGain[1] = v5->m_PositioningInfo.fChanGainTarget[1];
      }
      else if ( v5->m_uNumChannels == 4 )
      {
        v5->m_PositioningInfo.fChanGain[0] = v5->m_PositioningInfo.fChanGainTarget[0];
        v50 = v5->m_PositioningInfo.fChanGainTarget[1];
        *(_QWORD *)v5->m_PositioningInfo.fChanGainDelta = 0i64;
        v5->m_PositioningInfo.fChanGain[1] = v50;
        v51 = v5->m_PositioningInfo.fChanGainTarget[2];
        *(_QWORD *)&v5->m_PositioningInfo.fChanGainDelta[2] = 0i64;
        v5->m_PositioningInfo.fChanGain[2] = v51;
        v5->m_PositioningInfo.fChanGain[3] = v5->m_PositioningInfo.fChanGainTarget[3];
      }
      v7 = v55;
      LODWORD(v11) = v52;
      v4 = v13 + v53;
      v53 += v13;
      v3 -= v13;
    }
    while ( v3 );
  }
}

// File Line: 870
// RVA: 0xADD810
void __fastcall CAkSoundSeedWooshProcess::ProcessQuad(CAkSoundSeedWooshProcess *this, AkAudioBuffer *io_pBufferOut, float *in_pfTempStorage)
{
  signed int v3; // er12
  CAkSoundSeedWooshProcess *v4; // rbx
  __int64 v5; // r14
  __int64 v6; // r13
  float *v7; // rsi
  __m128 v8; // xmm1
  signed int v9; // ecx
  __int64 v10; // r8
  float *v11; // r15
  unsigned int v12; // edi
  unsigned int v13; // ecx
  int v14; // eax
  float v15; // ecx
  DSP::CAkColoredNoise *v16; // rcx
  __int64 v17; // rdx
  __int64 v18; // r11
  __int64 v19; // rcx
  DeflectorDSP *v20; // rax
  float *v21; // r9
  __int128 v22; // xmm0
  __m128 v23; // xmm3
  __m128 v24; // xmm6
  __m128 v25; // xmm7
  __m128 v26; // xmm8
  __m128 v27; // xmm4
  __m128 v28; // xmm5
  float *v29; // r8
  __int64 v30; // r10
  __m128 v31; // xmm0
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  __m128 v34; // xmm0
  __m128 *v35; // rdx
  signed __int64 v36; // r8
  __int64 v37; // rax
  __m128 v38; // xmm1
  __m128 v39; // xmm1
  float v40; // eax
  float v41; // eax
  unsigned int v42; // [rsp+110h] [rbp+8h]
  AkAudioBuffer *io_pBufferOuta; // [rsp+118h] [rbp+10h]
  size_t Size; // [rsp+120h] [rbp+18h]
  __int64 v45; // [rsp+128h] [rbp+20h]

  io_pBufferOuta = io_pBufferOut;
  v3 = io_pBufferOut->uValidFrames;
  v8 = 0i64;
  v4 = this;
  v5 = 0i64;
  v42 = (this->m_cDeflectors + 3) >> 2;
  v6 = 0i64;
  v7 = in_pfTempStorage;
  v8.m128_f32[0] = (float)v3 / (float)(signed int)this->m_uOversamplingFactor;
  v9 = (signed int)v8.m128_f32[0];
  if ( (signed int)v8.m128_f32[0] != 0x80000000 && (float)v9 != v8.m128_f32[0] )
    v8.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v8, v8)) & 1 ^ 1) + v9);
  v10 = ((signed int)v8.m128_f32[0] + 3) & 0xFFFFFFFC;
  v45 = v10;
  v11 = &v7[v10];
  if ( io_pBufferOut->uValidFrames )
  {
    Size = (unsigned int)(16 * v10);
    do
    {
      v12 = v10;
      v4->m_fAutomationValues[0] = v4->m_pfAutomationValues[v6];
      v4->m_fAutomationValues[1] = v4->m_pfAutomationValues[(unsigned int)(v6 + v4->m_uOversamplingFactor)];
      v4->m_fAutomationValues[2] = v4->m_pfAutomationValues[(unsigned int)(v6 + 2 * v4->m_uOversamplingFactor)];
      v13 = v4->m_uOversamplingFactor;
      v14 = v6 + 2 * v13;
      v6 = (unsigned int)(v6 + 1);
      v15 = v4->m_pfAutomationValues[v14 + v13];
      if ( v3 < (unsigned int)v10 )
        v12 = v3;
      v4->m_fAutomationValues[3] = v15;
      CAkSoundSeedWooshProcess::Prepare(v4, v12);
      if ( v4->m_NoiseGen.m_NoiseColor == 1 )
      {
        DSP::CAkColoredNoise::GenerateBufferPink(&v4->m_NoiseGen, v7, v12);
      }
      else if ( v4->m_NoiseGen.m_NoiseColor == 2 )
      {
        DSP::CAkColoredNoise::GenerateBufferRed(&v4->m_NoiseGen, v7, v12);
      }
      else
      {
        v16 = &v4->m_NoiseGen;
        if ( v4->m_NoiseGen.m_NoiseColor == 3 )
          DSP::CAkColoredNoise::GenerateBufferPurple(v16, v7, v12);
        else
          DSP::CAkWhiteNoise::GenerateBuffer((DSP::CAkWhiteNoise *)&v16->m_uLCGState, v7, v12);
      }
      memset(v11, 0, Size);
      if ( v42 )
      {
        v17 = 0i64;
        v18 = v42;
        v19 = 0i64;
        do
        {
          v20 = v4->m_pDeflectorDSPInfo;
          v21 = v11;
          v22 = *(_OWORD *)v20[v17].fTargetGain;
          v23 = *(__m128 *)v20[v17].fGain;
          v24 = *(__m128 *)v20[v17].fGainDelta;
          v25 = *(__m128 *)v20[v17].fCoefsA1;
          v26 = *(__m128 *)v20[v17].fCoefsA2;
          v27 = *(__m128 *)v20[v17].fFiltState1;
          v28 = *(__m128 *)v20[v17].fFiltState2;
          if ( v12 )
          {
            v29 = v7;
            v30 = v12;
            do
            {
              v31 = (__m128)*(unsigned int *)v29;
              v23 = _mm_add_ps(v23, v24);
              v21 += 4;
              ++v29;
              v32 = _mm_mul_ps(v28, v26);
              v33 = _mm_add_ps(_mm_mul_ps(v27, v25), _mm_shuffle_ps(v31, v31, 0));
              v34 = v28;
              v28 = v27;
              v27 = _mm_add_ps(v33, v32);
              *((__m128 *)v21 - 1) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v27, v34), v23), *(__m128 *)((char *)v21 - 16));
              --v30;
            }
            while ( v30 );
          }
          *(__m128 *)v20[v19].fFiltState1 = v27;
          ++v19;
          ++v17;
          *((__m128 *)&v4->m_pDeflectorDSPInfo[v19] - 1) = v28;
          *(__m128 *)v4->m_pDeflectorDSPInfo[v19 - 1].fGain = v23;
          --v18;
        }
        while ( v18 );
      }
      v35 = (__m128 *)v11;
      v36 = (signed __int64)io_pBufferOuta->pData + 4 * v5;
      if ( v12 )
      {
        v37 = v12;
        do
        {
          v38 = *v35;
          v36 += 4i64;
          ++v35;
          v39 = _mm_add_ps(v38, _mm_movehl_ps(v38, v38));
          *(float *)(v36 - 4) = COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 85)) + v39.m128_f32[0];
          --v37;
        }
        while ( v37 );
      }
      CAkSoundSeedWooshProcess::DeflectorGainRampCompleted(v4);
      CAkSoundSeedWooshProcess::QuadSpatialization(v4, io_pBufferOuta, v12, v5);
      if ( v4->m_uNumChannels == 2 )
      {
        *(_QWORD *)v4->m_PositioningInfo.fChanGainDelta = 0i64;
        v4->m_PositioningInfo.fChanGain[0] = v4->m_PositioningInfo.fChanGainTarget[0];
        v4->m_PositioningInfo.fChanGain[1] = v4->m_PositioningInfo.fChanGainTarget[1];
      }
      else if ( v4->m_uNumChannels == 4 )
      {
        v4->m_PositioningInfo.fChanGain[0] = v4->m_PositioningInfo.fChanGainTarget[0];
        v40 = v4->m_PositioningInfo.fChanGainTarget[1];
        *(_QWORD *)v4->m_PositioningInfo.fChanGainDelta = 0i64;
        v4->m_PositioningInfo.fChanGain[1] = v40;
        v41 = v4->m_PositioningInfo.fChanGainTarget[2];
        *(_QWORD *)&v4->m_PositioningInfo.fChanGainDelta[2] = 0i64;
        v4->m_PositioningInfo.fChanGain[2] = v41;
        v4->m_PositioningInfo.fChanGain[3] = v4->m_PositioningInfo.fChanGainTarget[3];
      }
      LODWORD(v10) = v45;
      v5 = v12 + (unsigned int)v5;
      v3 -= v12;
    }
    while ( v3 );
  }
}

// File Line: 976
// RVA: 0xADDB90
void __fastcall CAkSoundSeedWooshProcess::StereoSpatialization(CAkSoundSeedWooshProcess *this, AkAudioBuffer *io_pBufferOut, unsigned int in_uNumFrames, unsigned int in_uFrameOffset)
{
  unsigned int v4; // er8
  __m128 *v5; // rax
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  __m128 v8; // xmm4
  __m128 i; // xmm5
  __m128 v10; // xmm1
  __m128 v11; // xmm0

  v4 = in_uNumFrames >> 2;
  v5 = (__m128 *)((char *)io_pBufferOut->pData + 4 * in_uFrameOffset);
  v6 = _mm_shuffle_ps(
         (__m128)LODWORD(this->m_PositioningInfo.fChanGain[0]),
         (__m128)LODWORD(this->m_PositioningInfo.fChanGain[0]),
         0);
  v7 = _mm_shuffle_ps(
         (__m128)LODWORD(this->m_PositioningInfo.fChanGain[1]),
         (__m128)LODWORD(this->m_PositioningInfo.fChanGain[1]),
         0);
  v8 = _mm_shuffle_ps(
         (__m128)LODWORD(this->m_PositioningInfo.fChanGainDelta[0]),
         (__m128)LODWORD(this->m_PositioningInfo.fChanGainDelta[0]),
         0);
  for ( i = _mm_shuffle_ps(
              (__m128)LODWORD(this->m_PositioningInfo.fChanGainDelta[1]),
              (__m128)LODWORD(this->m_PositioningInfo.fChanGainDelta[1]),
              0); v4; --v4 )
  {
    v10 = *v5;
    v6 = _mm_add_ps(v6, v8);
    v7 = _mm_add_ps(v7, i);
    v11 = *v5;
    ++v5;
    v5[-1] = _mm_mul_ps(v11, v6);
    v5[255] = _mm_mul_ps(v10, v7);
  }
}

// File Line: 1003
// RVA: 0xADDC00
void __fastcall CAkSoundSeedWooshProcess::QuadSpatialization(CAkSoundSeedWooshProcess *this, AkAudioBuffer *io_pBufferOut, unsigned int in_uNumFrames, unsigned int in_uFrameOffset)
{
  unsigned int v4; // er8
  __m128 *v5; // rdx
  __m128 v6; // xmm3
  __m128 v7; // xmm4
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  __m128 v10; // xmm7
  __m128 v11; // xmm10
  __m128 v12; // xmm8
  __m128 i; // xmm9
  __m128 v14; // xmm2
  __m128 v15; // xmm1

  v4 = in_uNumFrames >> 2;
  v5 = (__m128 *)((char *)io_pBufferOut->pData + 4 * in_uFrameOffset);
  v6 = _mm_shuffle_ps(
         (__m128)LODWORD(this->m_PositioningInfo.fChanGain[0]),
         (__m128)LODWORD(this->m_PositioningInfo.fChanGain[0]),
         0);
  v7 = _mm_shuffle_ps(
         (__m128)LODWORD(this->m_PositioningInfo.fChanGain[1]),
         (__m128)LODWORD(this->m_PositioningInfo.fChanGain[1]),
         0);
  v8 = _mm_shuffle_ps(
         (__m128)LODWORD(this->m_PositioningInfo.fChanGain[2]),
         (__m128)LODWORD(this->m_PositioningInfo.fChanGain[2]),
         0);
  v9 = _mm_shuffle_ps(
         (__m128)LODWORD(this->m_PositioningInfo.fChanGain[3]),
         (__m128)LODWORD(this->m_PositioningInfo.fChanGain[3]),
         0);
  v10 = _mm_shuffle_ps(
          (__m128)LODWORD(this->m_PositioningInfo.fChanGainDelta[0]),
          (__m128)LODWORD(this->m_PositioningInfo.fChanGainDelta[0]),
          0);
  v11 = _mm_shuffle_ps(
          (__m128)LODWORD(this->m_PositioningInfo.fChanGainDelta[3]),
          (__m128)LODWORD(this->m_PositioningInfo.fChanGainDelta[3]),
          0);
  v12 = _mm_shuffle_ps(
          (__m128)LODWORD(this->m_PositioningInfo.fChanGainDelta[1]),
          (__m128)LODWORD(this->m_PositioningInfo.fChanGainDelta[1]),
          0);
  for ( i = _mm_shuffle_ps(
              (__m128)LODWORD(this->m_PositioningInfo.fChanGainDelta[2]),
              (__m128)LODWORD(this->m_PositioningInfo.fChanGainDelta[2]),
              0); v4; --v4 )
  {
    v14 = *v5;
    v6 = _mm_add_ps(v6, v10);
    v7 = _mm_add_ps(v7, v12);
    v15 = *v5;
    ++v5;
    v8 = _mm_add_ps(v8, i);
    v9 = _mm_add_ps(v9, v11);
    v5[-1] = _mm_mul_ps(v14, v6);
    v5[255] = _mm_mul_ps(v14, v7);
    v5[511] = _mm_mul_ps(v15, v8);
    v5[767] = _mm_mul_ps(v14, v9);
  }
}


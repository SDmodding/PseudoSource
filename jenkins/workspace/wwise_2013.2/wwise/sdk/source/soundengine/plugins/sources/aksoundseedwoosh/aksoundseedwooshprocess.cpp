// File Line: 48
// RVA: 0xADB570
void __fastcall CAkSoundSeedWooshProcess::CAkSoundSeedWooshProcess(CAkSoundSeedWooshProcess *this)
{
  this->m_pParams = 0i64;
  this->m_pDeflectors = 0i64;
  this->m_pDeflectorInfo = 0i64;
  this->m_pDeflectorDSPInfo = 0i64;
  this->m_pfAutomationValues = 0i64;
  this->m_RandGenerator.m_uLCGState = rand();
  DSP::CAkWhiteNoise::CAkWhiteNoise(&this->m_NoiseGen);
  *(_QWORD *)&this->m_NoiseGen.m_DCFilter.m_fFFwd1 = 0i64;
  this->m_NoiseGen.m_DCFilter.m_fA1 = 0.0;
  *(_QWORD *)&this->m_NoiseGen.RedFilter.fFFbk1 = 0i64;
  this->m_NoiseGen.RedFilter.fA1 = 0.0;
  *(_QWORD *)&this->m_NoiseGen.PurpleFilter.m_Memories.m_Memories.fFFwd1 = 0i64;
  *(_QWORD *)&this->m_NoiseGen.PurpleFilter.m_Memories.m_Memories.fFFbk1 = 0i64;
  DSP::BiquadFilter<DSP::SingleChannelPolicy>::SetCoefs(&this->m_NoiseGen.PurpleFilter, 1.0, 0.0, 0.0, 0.0, 0.0);
}

// File Line: 53
// RVA: 0xADB610
void __fastcall CAkSoundSeedWooshProcess::~CAkSoundSeedWooshProcess(CAkSoundSeedWooshProcess *this)
{
  ;
}

// File Line: 60
// RVA: 0xADB620
void __fastcall CAkSoundSeedWooshProcess::Setup(
        CAkSoundSeedWooshProcess *this,
        AkWooshParams *in_pParams,
        AkAudioFormat *io_rFormat)
{
  unsigned int uChannelMask; // r9d
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int i; // ecx
  float v11; // xmm1_4
  signed int v12; // eax

  this->m_uSampleRate = io_rFormat->uSampleRate;
  this->m_fSamplePeriod = 1.0 / (double)(int)io_rFormat->uSampleRate;
  uChannelMask = in_pParams->uChannelMask;
  *((_DWORD *)io_rFormat + 1) &= 0xFFFC0000;
  *((_DWORD *)io_rFormat + 1) |= uChannelMask & 0x3FFFF;
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
            uChannelMask = 3;
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
  for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
    ++i;
  this->m_uNumChannels = i;
  *((_DWORD *)io_rFormat + 1) &= 0xE0FFFFFF;
  *((_DWORD *)io_rFormat + 1) |= (i << 26) & 0x1F000000;
  DSP::CAkColoredNoise::Init(&this->m_NoiseGen, in_pParams->eNoiseColor, this->m_uSampleRate);
  this->m_uOversamplingFactor = in_pParams->uOversamplingFactor;
  v11 = in_pParams->fRandomValue[0];
  v12 = 214013 * this->m_RandGenerator.m_uLCGState + 2531011;
  this->m_RandGenerator.m_uLCGState = v12;
  *(_WORD *)&this->m_bLoopAfterExecution = 256;
  this->m_bInitAdvancePosition = 1;
  this->m_uLastPathPointIndex = 0;
  *(_QWORD *)&this->m_fDistanceTraveled = 0i64;
  this->m_fRandomSpeed = (float)((float)((float)((float)v12 * 2.3283064e-10) * 2.0) - 1.0) * v11;
}

// File Line: 94
// RVA: 0xADB8C0
float __fastcall CAkSoundSeedWooshProcess::ComputeIntegral(
        float in_fLeftX,
        float in_fLeftY,
        float in_fRightX,
        float in_fRightY)
{
  float v5; // xmm7_4
  float v6; // xmm9_4
  float v7; // xmm10_4
  float v8; // xmm8_4
  float v9; // xmm0_4

  if ( (_S1_39 & 1) != 0 )
  {
    v5 = LOG2;
  }
  else
  {
    _S1_39 |= 1u;
    v5 = logf(2.0);
    LOG2 = v5;
  }
  v6 = in_fRightX - in_fLeftX;
  v7 = (float)(in_fRightY * 0.02) + 2.0;
  v8 = (float)(in_fLeftY * 0.02) + 2.0;
  if ( (float)(v7 - v8) == 0.0 )
    return powf(2.0, v8) * v6;
  v9 = expf(v5 * v7);
  return (float)((float)(v9 - expf(v5 * v8)) * (float)(v6 / (float)(v7 - v8))) / v5;
}

// File Line: 118
// RVA: 0xADC6F0
void __fastcall CAkSoundSeedWooshProcess::ComputeStereoGains(
        CAkSoundSeedWooshProcess *this,
        float in_fX,
        float in_fY,
        float *out_fLeft,
        float *out_fRight)
{
  float v6; // xmm8_4
  float v7; // xmm0_4
  float v8; // xmm8_4

  v6 = powf(fsqrt((float)(in_fX * in_fX) + (float)(in_fY * in_fY)), 0.16666667);
  v7 = atan2f(in_fY, in_fX);
  v8 = (float)((float)((float)(v6 * cosf(v7)) * 3.1415927) * 0.25) + 0.78539819;
  *out_fLeft = cosf(v8);
  *out_fRight = sinf(v8);
}

// File Line: 130
// RVA: 0xADC7B0
void __fastcall CAkSoundSeedWooshProcess::ComputeQuadGains(
        CAkSoundSeedWooshProcess *this,
        float in_fX,
        float in_fY,
        float *out_fFrontLeft,
        float *out_fFrontRight,
        float *out_fRearLeft,
        float *out_fRearRight)
{
  float v8; // xmm14_4
  float v9; // xmm11_4
  float v10; // xmm6_4
  float v11; // xmm12_4
  float v12; // xmm13_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm0_4

  v8 = atan2f(in_fY, in_fX);
  v9 = powf(fsqrt((float)(in_fX * in_fX) + (float)(in_fY * in_fY)), 0.16666667);
  v10 = (float)((float)((float)(cosf(v8) * v9) * 3.1415927) * 0.25) + 0.78539819;
  v11 = cosf(v10);
  v12 = sinf(v10);
  v13 = (float)((float)((float)(sinf(v8) * v9) * 3.1415927) * 0.25) + 0.78539819;
  v14 = sinf(v13);
  v15 = cosf(v13);
  *out_fFrontLeft = v14 * v11;
  *out_fFrontRight = v14 * v12;
  *out_fRearLeft = v15 * v11;
  *out_fRearRight = v15 * v12;
}

// File Line: 148
// RVA: 0xADB9E0
void __fastcall CAkSoundSeedWooshProcess::ComputeObjectPosition(CAkSoundSeedWooshProcess *this)
{
  unsigned int m_cPathPoints; // r10d
  unsigned int m_uLastPathPointIndex; // edx
  __int64 v4; // r10
  __int64 v5; // r8
  float m_fDistanceTraveled; // xmm3_4
  __int64 v7; // rcx
  AkWooshPathPoint *v8; // r8
  float v9; // xmm3_4
  AkWooshPathPoint *v10; // rcx
  AkWooshPathPoint *m_pPath; // rcx

  m_cPathPoints = this->m_cPathPoints;
  if ( m_cPathPoints <= 1 )
  {
    m_pPath = this->m_pPath;
    this->m_fCurrentPosX = m_pPath->fX;
    this->m_fCurrentPosY = m_pPath->fY;
  }
  else
  {
    m_uLastPathPointIndex = this->m_uLastPathPointIndex;
    v4 = m_cPathPoints - 1;
    if ( m_uLastPathPointIndex < (unsigned int)v4 )
    {
      v5 = m_uLastPathPointIndex + 1;
      while ( this->m_fDistanceTraveled >= this->m_pPath[v5].fDistanceTravelled )
      {
        ++m_uLastPathPointIndex;
        v5 = (unsigned int)(v5 + 1);
        if ( m_uLastPathPointIndex >= (unsigned int)v4 )
          goto LABEL_8;
      }
      this->m_uLastPathPointIndex = m_uLastPathPointIndex;
    }
LABEL_8:
    m_fDistanceTraveled = this->m_fDistanceTraveled;
    v7 = this->m_uLastPathPointIndex;
    if ( m_fDistanceTraveled >= this->m_fTotalPathDistance )
    {
      v10 = this->m_pPath;
      this->m_fCurrentPosX = v10[v4].fX;
      this->m_fCurrentPosY = v10[v4].fY;
    }
    else
    {
      v8 = this->m_pPath;
      v9 = (float)(m_fDistanceTraveled - v8[v7].fDistanceTravelled)
         / (float)(v8[(unsigned int)(v7 + 1)].fDistanceTravelled - v8[v7].fDistanceTravelled);
      this->m_fCurrentPosX = (float)((float)(v8[(unsigned int)(v7 + 1)].fX - v8[v7].fX) * v9) + v8[v7].fX;
      this->m_fCurrentPosY = (float)((float)(v8[(unsigned int)(v7 + 1)].fY - v8[v7].fY) * v9) + v8[v7].fY;
    }
  }
}

// File Line: 200
// RVA: 0xADC910
void __fastcall CAkSoundSeedWooshProcess::InitSpatialization(CAkSoundSeedWooshProcess *this)
{
  float *v2; // r14
  float *v3; // rsi
  float *v4; // rdi
  float *v5; // rdi

  if ( this->m_uNumChannels == 2 )
  {
    v5 = &this->m_PositioningInfo.fChanGainTarget[1];
    CAkSoundSeedWooshProcess::ComputeStereoGains(
      this,
      this->m_fCurrentPosX,
      this->m_fCurrentPosY,
      this->m_PositioningInfo.fChanGainTarget,
      &this->m_PositioningInfo.fChanGainTarget[1]);
    *(_QWORD *)this->m_PositioningInfo.fChanGainDelta = 0i64;
    this->m_PositioningInfo.fChanGain[0] = this->m_PositioningInfo.fChanGainTarget[0];
    this->m_PositioningInfo.fChanGain[1] = *v5;
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
    *(_QWORD *)this->m_PositioningInfo.fChanGainDelta = 0i64;
    *(_QWORD *)&this->m_PositioningInfo.fChanGainDelta[2] = 0i64;
    this->m_PositioningInfo.fChanGain[0] = this->m_PositioningInfo.fChanGainTarget[0];
    this->m_PositioningInfo.fChanGain[1] = *v4;
    this->m_PositioningInfo.fChanGain[2] = *v3;
    this->m_PositioningInfo.fChanGain[3] = *v2;
  }
}

// File Line: 237
// RVA: 0xADBB00
void __fastcall CAkSoundSeedWooshProcess::ComputeDistanceToAdvance(CAkSoundSeedWooshProcess *this)
{
  float v2; // xmm0_4

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
      this->m_fWooshIntegral = v2;
      this->m_fDistanceTraveled = v2 * this->m_fTotalPathDistance;
    }
    this->m_fPrevTimeElapsed = this->m_fTimeElapsed;
    this->m_fPrevInstantSpeed = this->m_fAutomationValues[0];
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

  v2 = this->m_fAutomationValues[1];
  this->m_fEffectiveSpeedValue = (float)(this->m_pParams->fBaseValue[0] + this->m_fRandomSpeed)
                               + this->m_fAutomationValues[0];
  CAkSoundSeedWooshProcess::ComputeEffectiveFrequencyScale(this, v2);
  CAkSoundSeedWooshProcess::ComputeEffectiveQFactorScale(this, this->m_fAutomationValues[2]);
  CAkSoundSeedWooshProcess::ComputeEffectiveGainOffset(this, this->m_fAutomationValues[3]);
  CAkSoundSeedWooshProcess::ComputeDeflectorAirVelocities(this);
  CAkSoundSeedWooshProcess::ComputeDistanceToAdvance(this);
  CAkSoundSeedWooshProcess::ComputeObjectPosition(this);
  if ( this->m_bInitGainRamps )
  {
    CAkSoundSeedWooshProcess::InitDeflectorGainRamp(this);
    if ( this->m_uNumChannels > 1 )
      CAkSoundSeedWooshProcess::InitSpatialization(this);
    this->m_bInitGainRamps = 0;
  }
  else
  {
    CAkSoundSeedWooshProcess::ComputeDeflectorGains(this, in_uNumFrames);
    if ( this->m_uNumChannels > 1 )
      CAkSoundSeedWooshProcess::ComputeSpatialization(this, in_uNumFrames);
  }
  CAkSoundSeedWooshProcess::ComputeFilterCoefficients(this);
  this->m_uChangeMask = 0;
}

// File Line: 301
// RVA: 0xADB890
void __fastcall CAkSoundSeedWooshProcess::Process(
        CAkSoundSeedWooshProcess *this,
        AkAudioBuffer *io_pBufferOut,
        float *in_pfTempStorage)
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
  float v2; // xmm0_4
  __int64 m_cDeflectors; // r8
  int iAnchorIndex; // ecx
  float v5; // xmm1_4
  int v6; // ebp
  __int64 v7; // r11
  __int64 v8; // rdx
  __int64 v9; // rsi
  unsigned __int64 v10; // rdi
  int v11; // r8d
  __int64 v12; // r10
  unsigned __int64 v13; // rdi
  int v14; // r9d
  float v15; // xmm2_4
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // r9d
  int v21; // ecx
  __int64 v22; // r8
  __int64 v23; // rdx
  int v24; // eax
  __int64 v25; // rcx
  unsigned __int64 v26; // r8
  __int64 v27; // rcx
  __int64 v28; // rdx

  v2 = powf(2.0, (float)(this->m_fEffectiveSpeedValue * 0.02) - 2.0);
  m_cDeflectors = (int)this->m_cDeflectors;
  iAnchorIndex = this->m_pParams->iAnchorIndex;
  v5 = v2 * 16.0;
  if ( (_DWORD)m_cDeflectors == 1 && iAnchorIndex != -1 )
    iAnchorIndex = -1;
  v6 = m_cDeflectors - iAnchorIndex - 1;
  if ( v6 <= iAnchorIndex )
    v6 = iAnchorIndex;
  v7 = 0i64;
  v8 = (int)this->m_cDeflectors;
  if ( iAnchorIndex == -1 )
  {
    if ( m_cDeflectors >= 4 )
    {
      v25 = 0i64;
      v26 = ((unsigned __int64)(m_cDeflectors - 4) >> 2) + 1;
      v7 = 4 * v26;
      do
      {
        v25 += 4i64;
        this->m_pDeflectorInfo[v25 - 4].fVelocity = v5;
        this->m_pDeflectorInfo[v25 - 3].fVelocity = v5;
        this->m_pDeflectorInfo[v25 - 2].fVelocity = v5;
        this->m_pDeflectorInfo[v25 - 1].fVelocity = v5;
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
        this->m_pDeflectorInfo[v27++].fVelocity = v5;
        --v28;
      }
      while ( v28 );
    }
  }
  else
  {
    v9 = 0i64;
    if ( m_cDeflectors >= 4 )
    {
      v10 = (unsigned __int64)(m_cDeflectors - 4) >> 2;
      v11 = 2 - iAnchorIndex;
      v12 = 0i64;
      v13 = v10 + 1;
      v14 = iAnchorIndex - 2;
      LODWORD(v7) = 4 * v13;
      v9 = 4 * v13;
      v15 = 1.0 / (float)v6;
      do
      {
        v16 = v14 + 2;
        if ( v14 + 2 < 0 )
          v16 = v11 - 2;
        this->m_pDeflectorInfo[v12].fVelocity = (float)((float)v16 * v15) * v5;
        v17 = v14 + 1;
        if ( v14 + 1 < 0 )
          v17 = v11 - 1;
        this->m_pDeflectorInfo[v12 + 1].fVelocity = (float)((float)v17 * v15) * v5;
        v18 = v11;
        if ( v14 >= 0 )
          v18 = v14;
        this->m_pDeflectorInfo[v12 + 2].fVelocity = (float)((float)v18 * v15) * v5;
        v19 = v14 - 1;
        if ( v14 - 1 < 0 )
          v19 = v11 + 1;
        v12 += 4i64;
        v14 -= 4;
        v11 += 4;
        this->m_pDeflectorInfo[v12 - 1].fVelocity = (float)((float)v19 * v15) * v5;
        --v13;
      }
      while ( v13 );
    }
    if ( v9 < v8 )
    {
      v20 = v7 - iAnchorIndex;
      v21 = iAnchorIndex - v7;
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
        this->m_pDeflectorInfo[v22 - 1].fVelocity = (float)((float)v24 * (float)(1.0 / (float)v6)) * v5;
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
  unsigned int m_cDeflectors; // r14d
  unsigned int v2; // ebp
  float v4; // xmm8_4
  __int64 v5; // rdi
  DeflectorInfo *m_pDeflectorInfo; // rax
  float v7; // xmm6_4
  float m_fSamplePeriod; // xmm10_4
  float v9; // xmm7_4
  __int64 v10; // rbx

  m_cDeflectors = this->m_cDeflectors;
  v2 = 0;
  v4 = (float)(int)this->m_uSampleRate * 0.5;
  if ( m_cDeflectors )
  {
    v5 = 0i64;
    do
    {
      m_pDeflectorInfo = this->m_pDeflectorInfo;
      v7 = (float)(m_pDeflectorInfo[v5].fEffectiveFrequency * m_pDeflectorInfo[v5].fVelocity) * 0.0625;
      if ( v7 >= v4 )
        v7 = v4;
      if ( v7 <= 20.0 )
        v7 = FLOAT_20_0;
      m_fSamplePeriod = this->m_fSamplePeriod;
      v9 = expf(
             (float)((float)((float)((float)(v7 / m_pDeflectorInfo[v5].fEffectiveQFactor) * 2.0) * 3.1415927)
                   * m_fSamplePeriod)
           * -0.5);
      if ( v9 >= 0.99919999 )
        v9 = FLOAT_0_99919999;
      v10 = (v2 & 3) + 28i64 * (v2 >> 2);
      ++v2;
      ++v5;
      this->m_pDeflectorDSPInfo->fCoefsA1[v10] = cosf((float)(v7 * 6.2831855) * m_fSamplePeriod) * (float)(v9 * 2.0);
      LODWORD(this->m_pDeflectorDSPInfo->fCoefsA2[v10]) = COERCE_UNSIGNED_INT(v9 * v9) ^ _xmm[0];
    }
    while ( v2 < m_cDeflectors );
  }
}

// File Line: 381
// RVA: 0xADCFD0
float __fastcall CAkSoundSeedWooshProcess::EqualizeTunable(
        CAkSoundSeedWooshProcess *this,
        float in_fCenterFrequency,
        float in_fQ)
{
  DSP::CAkColoredNoise::AkNoiseColor eNoiseColor; // r8d
  __int32 v5; // r8d
  __int32 v6; // r8d
  float v7; // xmm6_4
  float v8; // xmm9_4
  float v9; // xmm7_4
  float v11; // [rsp+78h] [rbp+10h]

  eNoiseColor = this->m_pParams->eNoiseColor;
  if ( eNoiseColor )
  {
    v5 = eNoiseColor - 1;
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
  v9 = expf(
         (float)((float)((float)((float)(in_fCenterFrequency / in_fQ) * 2.0) * 3.1415927) * this->m_fSamplePeriod)
       * -0.5);
  if ( v9 >= 0.99919999 )
    v9 = FLOAT_0_99919999;
  return (float)((float)(expf((float)((float)(v8 * -0.023) * v8) + (float)((float)(v8 * -0.1648) + 3.9542999))
                       + 0.69999999)
               * v7)
       * (float)((float)(1.0 - (float)(v9 * v9)) * 0.5);
}

// File Line: 429
// RVA: 0xADC020
float __fastcall CAkSoundSeedWooshProcess::ComputeCombinedGain(
        CAkSoundSeedWooshProcess *this,
        float in_fDeflectorGain,
        float in_fVelocity,
        float in_fDistanceAttenuation,
        float in_fCenterFrequency,
        float in_fQfactor)
{
  float v7; // xmm0_4

  v7 = CAkSoundSeedWooshProcess::EqualizeTunable(this, in_fCenterFrequency, in_fQfactor);
  return v7
       * (float)((float)(powf(
                           in_fVelocity * 0.0625,
                           (float)((float)(this->m_pParams->fDynamicRange + 1.0) * 48.0) * 0.041524101)
                       * in_fDeflectorGain)
               * in_fDistanceAttenuation);
}

// File Line: 442
// RVA: 0xADC670
double __fastcall CAkSoundSeedWooshProcess::ComputeDistanceBasedAttenuation(
        CAkSoundSeedWooshProcess *this,
        float in_fDistance)
{
  AkWooshParams *m_pParams; // rbx
  double result; // xmm0_8
  float v4; // xmm2_4
  float v5; // xmm1_4

  m_pParams = this->m_pParams;
  *(_QWORD *)&result = (unsigned int)FLOAT_1_0;
  if ( m_pParams->bEnableDistanceBasedAttenuation )
  {
    v4 = m_pParams->fMinDistance * 0.0099999998;
    if ( in_fDistance > v4 )
    {
      v5 = (float)(logf(in_fDistance / v4) * 1.442695) * (float)(m_pParams->fAttenuationRolloff * -6.0);
      *(_QWORD *)&result = LODWORD(FLOAT_10_0);
      *(float *)&result = powf(10.0, v5 * 0.050000001);
    }
  }
  return result;
}

// File Line: 464
// RVA: 0xADC0D0
void __fastcall CAkSoundSeedWooshProcess::InitDeflectorGainRamp(CAkSoundSeedWooshProcess *this)
{
  unsigned int m_cDeflectors; // r15d
  unsigned int v3; // r14d
  __int64 v4; // rbp
  __m128 m_fCurrentPosX_low; // xmm1
  AkWooshParams *m_pParams; // rsi
  float v7; // xmm7_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  DeflectorInfo *m_pDeflectorInfo; // rbx
  float v12; // xmm6_4
  float v13; // xmm0_4
  __int64 v14; // rax
  __int64 v15; // rdx
  __int64 v16; // rdx
  float v17; // xmm6_4

  m_cDeflectors = this->m_cDeflectors;
  v3 = 0;
  if ( m_cDeflectors )
  {
    v4 = 0i64;
    do
    {
      m_fCurrentPosX_low = (__m128)LODWORD(this->m_fCurrentPosX);
      m_pParams = this->m_pParams;
      v7 = *(float *)&FLOAT_1_0;
      m_fCurrentPosX_low.m128_f32[0] = (float)(m_fCurrentPosX_low.m128_f32[0] * m_fCurrentPosX_low.m128_f32[0])
                                     + (float)(this->m_fCurrentPosY * this->m_fCurrentPosY);
      LODWORD(v8) = _mm_sqrt_ps(m_fCurrentPosX_low).m128_u32[0];
      if ( m_pParams->bEnableDistanceBasedAttenuation )
      {
        v9 = m_pParams->fMinDistance * 0.0099999998;
        if ( v8 > v9 )
        {
          v10 = (float)(logf(v8 / v9) * 1.442695) * (float)(m_pParams->fAttenuationRolloff * -6.0);
          v7 = powf(10.0, v10 * 0.050000001);
        }
      }
      m_pDeflectorInfo = this->m_pDeflectorInfo;
      v12 = CAkSoundSeedWooshProcess::EqualizeTunable(
              this,
              m_pDeflectorInfo[v4].fEffectiveFrequency,
              m_pDeflectorInfo[v4].fEffectiveQFactor);
      v13 = powf(
              m_pDeflectorInfo[v4].fVelocity * 0.0625,
              (float)((float)(m_pParams->fDynamicRange + 1.0) * 48.0) * 0.041524101)
          * m_pDeflectorInfo[v4].fEffectiveGain;
      v14 = v3 & 3;
      v15 = v3++ >> 2;
      ++v4;
      v16 = v14 + 28 * v15;
      v17 = v12 * (float)(v13 * v7);
      this->m_pDeflectorDSPInfo->fGainDelta[v16] = 0.0;
      this->m_pDeflectorDSPInfo->fTargetGain[v16] = v17;
      this->m_pDeflectorDSPInfo->fGain[v16] = v17;
    }
    while ( v3 < m_cDeflectors );
  }
}

// File Line: 492
// RVA: 0xADC310
void __fastcall CAkSoundSeedWooshProcess::ComputeDeflectorGains(CAkSoundSeedWooshProcess *this, int in_uNumFrames)
{
  unsigned int m_cDeflectors; // r15d
  unsigned int v3; // ebp
  __int64 v5; // r14
  float v6; // xmm10_4
  __m128 m_fCurrentPosX_low; // xmm1
  AkWooshParams *m_pParams; // rsi
  float v9; // xmm7_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  DeflectorInfo *m_pDeflectorInfo; // rbx
  float v14; // xmm6_4
  float v15; // xmm0_4
  __int64 v16; // rax
  __int64 v17; // rdx
  __int64 v18; // rdx
  float v19; // xmm6_4

  m_cDeflectors = this->m_cDeflectors;
  v3 = 0;
  if ( m_cDeflectors )
  {
    v5 = 0i64;
    v6 = 1.0 / (float)in_uNumFrames;
    do
    {
      m_fCurrentPosX_low = (__m128)LODWORD(this->m_fCurrentPosX);
      m_pParams = this->m_pParams;
      v9 = *(float *)&FLOAT_1_0;
      m_fCurrentPosX_low.m128_f32[0] = (float)(m_fCurrentPosX_low.m128_f32[0] * m_fCurrentPosX_low.m128_f32[0])
                                     + (float)(this->m_fCurrentPosY * this->m_fCurrentPosY);
      LODWORD(v10) = _mm_sqrt_ps(m_fCurrentPosX_low).m128_u32[0];
      if ( m_pParams->bEnableDistanceBasedAttenuation )
      {
        v11 = m_pParams->fMinDistance * 0.0099999998;
        if ( v10 > v11 )
        {
          v12 = (float)(logf(v10 / v11) * 1.442695) * (float)(m_pParams->fAttenuationRolloff * -6.0);
          v9 = powf(10.0, v12 * 0.050000001);
        }
      }
      m_pDeflectorInfo = this->m_pDeflectorInfo;
      v14 = CAkSoundSeedWooshProcess::EqualizeTunable(
              this,
              m_pDeflectorInfo[v5].fEffectiveFrequency,
              m_pDeflectorInfo[v5].fEffectiveQFactor);
      v15 = powf(
              m_pDeflectorInfo[v5].fVelocity * 0.0625,
              (float)((float)(m_pParams->fDynamicRange + 1.0) * 48.0) * 0.041524101)
          * m_pDeflectorInfo[v5].fEffectiveGain;
      v16 = v3 & 3;
      v17 = v3++ >> 2;
      ++v5;
      v18 = v16 + 28 * v17;
      v19 = v14 * (float)(v15 * v9);
      this->m_pDeflectorDSPInfo->fGainDelta[v18] = (float)(v19 - this->m_pDeflectorDSPInfo->fGain[v18]) * v6;
      this->m_pDeflectorDSPInfo->fTargetGain[v18] = v19;
    }
    while ( v3 < m_cDeflectors );
  }
}

// File Line: 521
// RVA: 0xADC550
void __fastcall CAkSoundSeedWooshProcess::DeflectorGainRampCompleted(CAkSoundSeedWooshProcess *this)
{
  signed int m_cDeflectors; // r10d
  unsigned int v2; // r8d
  unsigned int v3; // r11d
  char v4; // al
  unsigned int v5; // edx
  __int64 v6; // rdx
  __int64 v7; // rdx
  __int64 v8; // rdx
  __int64 v9; // rax
  __int64 v10; // rdx
  __int64 v11; // rdx
  char v12; // al
  unsigned int v13; // edx
  __int64 v14; // rdx

  m_cDeflectors = this->m_cDeflectors;
  v2 = 0;
  if ( m_cDeflectors >= 4 )
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
    while ( v2 < m_cDeflectors - 3 );
  }
  for ( ; v2 < m_cDeflectors; this->m_pDeflectorDSPInfo->fGain[v14] = this->m_pDeflectorDSPInfo->fTargetGain[v14] )
  {
    v12 = v2;
    v13 = v2++;
    v14 = (v12 & 3) + 28i64 * (v13 >> 2);
    this->m_pDeflectorDSPInfo->fGainDelta[v14] = 0.0;
  }
}

// File Line: 538
// RVA: 0xADCA20
void __fastcall CAkSoundSeedWooshProcess::ComputeSpatialization(CAkSoundSeedWooshProcess *this, int in_uNumFrames)
{
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

  if ( this->m_uNumChannels == 2 )
  {
    v11 = &this->m_PositioningInfo.fChanGainTarget[1];
    CAkSoundSeedWooshProcess::ComputeStereoGains(
      this,
      this->m_fCurrentPosX,
      this->m_fCurrentPosY,
      this->m_PositioningInfo.fChanGainTarget,
      &this->m_PositioningInfo.fChanGainTarget[1]);
    v12 = 1.0 / (float)in_uNumFrames;
    v13 = (float)(*v11 - this->m_PositioningInfo.fChanGain[1]) * v12;
    this->m_PositioningInfo.fChanGainDelta[0] = (float)(this->m_PositioningInfo.fChanGainTarget[0]
                                                      - this->m_PositioningInfo.fChanGain[0])
                                              * v12;
    this->m_PositioningInfo.fChanGainDelta[1] = v13;
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
    v7 = 1.0 / (float)in_uNumFrames;
    v8 = (float)(*v5 - this->m_PositioningInfo.fChanGain[1]) * v7;
    this->m_PositioningInfo.fChanGainDelta[0] = (float)(this->m_PositioningInfo.fChanGainTarget[0]
                                                      - this->m_PositioningInfo.fChanGain[0])
                                              * v7;
    v9 = *v6 - this->m_PositioningInfo.fChanGain[2];
    this->m_PositioningInfo.fChanGainDelta[1] = v8;
    v10 = *v4 - this->m_PositioningInfo.fChanGain[3];
    this->m_PositioningInfo.fChanGainDelta[2] = v9 * v7;
    this->m_PositioningInfo.fChanGainDelta[3] = v10 * v7;
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
    *(_OWORD *)this->m_PositioningInfo.fChanGain = *(_OWORD *)this->m_PositioningInfo.fChanGainTarget;
  }
}

// File Line: 590
// RVA: 0xADCC00
void __fastcall CAkSoundSeedWooshProcess::ComputeEffectiveSpeed(
        CAkSoundSeedWooshProcess *this,
        float in_fAutomationValue)
{
  this->m_fEffectiveSpeedValue = (float)(this->m_pParams->fBaseValue[0] + this->m_fRandomSpeed) + in_fAutomationValue;
}

// File Line: 597
// RVA: 0xADCC20
void __fastcall CAkSoundSeedWooshProcess::ComputeEffectiveFrequencyScale(
        CAkSoundSeedWooshProcess *this,
        float in_fAutomationValue)
{
  float v3; // xmm7_4
  unsigned int m_cDeflectors; // eax
  __int64 v5; // rdi
  __int64 v6; // r14
  __int64 v7; // rbp
  DeflectorInfo *m_pDeflectorInfo; // rbx
  float v9; // xmm0_4

  v3 = this->m_pParams->fBaseValue[1];
  m_cDeflectors = this->m_cDeflectors;
  if ( m_cDeflectors )
  {
    v5 = 0i64;
    v6 = m_cDeflectors;
    v7 = 0i64;
    do
    {
      m_pDeflectorInfo = this->m_pDeflectorInfo;
      v9 = powf(2.0, (float)(v3 + m_pDeflectorInfo[v5++].fRandomFrequency) + in_fAutomationValue);
      m_pDeflectorInfo[v5 - 1].fEffectiveFrequency = v9 * this->m_pDeflectors[v7++].fFrequency;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 612
// RVA: 0xADCCE0
void __fastcall CAkSoundSeedWooshProcess::ComputeEffectiveQFactorScale(
        CAkSoundSeedWooshProcess *this,
        float in_fAutomationValue)
{
  float v3; // xmm9_4
  unsigned int m_cDeflectors; // eax
  __int64 v5; // rbx
  __int64 v6; // rsi
  __int64 v7; // rdi
  DeflectorInfo *m_pDeflectorInfo; // rbp
  float v9; // xmm0_4

  v3 = this->m_pParams->fBaseValue[2];
  m_cDeflectors = this->m_cDeflectors;
  if ( m_cDeflectors )
  {
    v5 = 0i64;
    v6 = m_cDeflectors;
    v7 = 0i64;
    do
    {
      m_pDeflectorInfo = this->m_pDeflectorInfo;
      v9 = powf(2.0, (float)(v3 + m_pDeflectorInfo[v5].fRandomQFactor) + in_fAutomationValue)
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
      m_pDeflectorInfo[v5++].fEffectiveQFactor = v9;
      ++v7;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 630
// RVA: 0xADCDF0
void __fastcall CAkSoundSeedWooshProcess::ComputeEffectiveGainOffset(
        CAkSoundSeedWooshProcess *this,
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

  v3 = this->m_pParams->fBaseValue[3];
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
      v14 = (float)(v3 * m_pDeflectorInfo[v9].fRandomGain) * v8;
      if ( v14 < 16.0 )
      {
        if ( v14 <= 0.0 )
          v14 = 0.0;
      }
      else
      {
        v14 = FLOAT_16_0;
      }
      m_pDeflectorInfo[v9].fEffectiveGain = v14 * this->m_pDeflectors[v10].fGain;
      v15 = this->m_pDeflectorInfo;
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
      v15[v9 + 1].fEffectiveGain = v16 * this->m_pDeflectors[v10 + 1].fGain;
      v17 = this->m_pDeflectorInfo;
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
      v17[v9 + 2].fEffectiveGain = v18 * this->m_pDeflectors[v10 + 2].fGain;
      v19 = this->m_pDeflectorInfo;
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
      v21 = v20 * this->m_pDeflectors[v10 + 3].fGain;
      v9 += 4i64;
      v10 += 4i64;
      v19[v9 - 1].fEffectiveGain = v21;
      --v12;
    }
    while ( v12 );
  }
  if ( v6 < m_cDeflectors )
  {
    v22 = v7;
    v23 = v7;
    v24 = m_cDeflectors - v6;
    do
    {
      v25 = this->m_pDeflectorInfo;
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
      v27 = v26 * this->m_pDeflectors[v22].fGain;
      ++v23;
      ++v22;
      v25[v23 - 1].fEffectiveGain = v27;
      --v24;
    }
    while ( v24 );
  }
}

// File Line: 655
// RVA: 0xADD120
void __fastcall CAkSoundSeedWooshProcess::ProcessMono(
        CAkSoundSeedWooshProcess *this,
        AkAudioBuffer *io_pBufferOut,
        float *in_pfTempStorage)
{
  int uValidFrames; // r15d
  __int64 v5; // r12
  __int64 v6; // r13
  __m128 v8; // xmm1
  int v9; // ecx
  __int64 v10; // r8
  float *v11; // r14
  unsigned int v12; // edi
  unsigned int m_uOversamplingFactor; // ecx
  int v14; // eax
  float v15; // ecx
  DSP::CAkColoredNoise *p_m_NoiseGen; // rcx
  __int64 v17; // rdx
  __int64 v18; // r11
  __int64 v19; // rcx
  DeflectorDSP *m_pDeflectorDSPInfo; // rax
  float *v21; // r9
  __m128 v22; // xmm3
  __m128 v23; // xmm6
  __m128 v24; // xmm7
  __m128 v25; // xmm8
  __m128 v26; // xmm4
  __m128 v27; // xmm5
  float *v28; // r8
  __int64 v29; // r10
  __m128 v30; // xmm0
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  __m128 *v34; // rdx
  float *v35; // r8
  __int64 v36; // rax
  __m128 v37; // xmm1
  __m128 v38; // xmm1
  unsigned int v39; // [rsp+110h] [rbp+8h]
  size_t Size; // [rsp+120h] [rbp+18h]
  unsigned int v42; // [rsp+128h] [rbp+20h]

  uValidFrames = io_pBufferOut->uValidFrames;
  v8 = 0i64;
  v5 = 0i64;
  v39 = (this->m_cDeflectors + 3) >> 2;
  v6 = 0i64;
  v8.m128_f32[0] = (float)uValidFrames / (float)(int)this->m_uOversamplingFactor;
  v9 = (int)v8.m128_f32[0];
  if ( (int)v8.m128_f32[0] != 0x80000000 && (float)v9 != v8.m128_f32[0] )
    v8.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v8, v8)) & 1) + v9);
  v10 = ((int)v8.m128_f32[0] + 3) & 0xFFFFFFFC;
  v42 = ((int)v8.m128_f32[0] + 3) & 0xFFFFFFFC;
  v11 = &in_pfTempStorage[v10];
  if ( io_pBufferOut->uValidFrames )
  {
    Size = (unsigned int)(16 * v10);
    do
    {
      v12 = v10;
      this->m_fAutomationValues[0] = this->m_pfAutomationValues[v6];
      this->m_fAutomationValues[1] = this->m_pfAutomationValues[(unsigned int)(v6 + this->m_uOversamplingFactor)];
      this->m_fAutomationValues[2] = this->m_pfAutomationValues[(unsigned int)(v6 + 2 * this->m_uOversamplingFactor)];
      m_uOversamplingFactor = this->m_uOversamplingFactor;
      v14 = v6 + 2 * m_uOversamplingFactor;
      v6 = (unsigned int)(v6 + 1);
      v15 = this->m_pfAutomationValues[v14 + m_uOversamplingFactor];
      if ( uValidFrames < (unsigned int)v10 )
        v12 = uValidFrames;
      this->m_fAutomationValues[3] = v15;
      CAkSoundSeedWooshProcess::Prepare(this, v12);
      if ( this->m_NoiseGen.m_NoiseColor == NOISECOLOR_PINK )
      {
        DSP::CAkColoredNoise::GenerateBufferPink(&this->m_NoiseGen, in_pfTempStorage, v12);
      }
      else if ( this->m_NoiseGen.m_NoiseColor == NOISECOLOR_RED )
      {
        DSP::CAkColoredNoise::GenerateBufferRed(&this->m_NoiseGen, in_pfTempStorage, v12);
      }
      else
      {
        p_m_NoiseGen = &this->m_NoiseGen;
        if ( this->m_NoiseGen.m_NoiseColor == NOISECOLOR_PURPLE )
          DSP::CAkColoredNoise::GenerateBufferPurple(p_m_NoiseGen, in_pfTempStorage, v12);
        else
          DSP::CAkWhiteNoise::GenerateBuffer(p_m_NoiseGen, in_pfTempStorage, v12);
      }
      memset(v11, 0, Size);
      if ( v39 )
      {
        v17 = 0i64;
        v18 = v39;
        v19 = 0i64;
        do
        {
          m_pDeflectorDSPInfo = this->m_pDeflectorDSPInfo;
          v21 = v11;
          v22 = *(__m128 *)m_pDeflectorDSPInfo[v17].fGain;
          v23 = *(__m128 *)m_pDeflectorDSPInfo[v17].fGainDelta;
          v24 = *(__m128 *)m_pDeflectorDSPInfo[v17].fCoefsA1;
          v25 = *(__m128 *)m_pDeflectorDSPInfo[v17].fCoefsA2;
          v26 = *(__m128 *)m_pDeflectorDSPInfo[v17].fFiltState1;
          v27 = *(__m128 *)m_pDeflectorDSPInfo[v17].fFiltState2;
          if ( v12 )
          {
            v28 = in_pfTempStorage;
            v29 = v12;
            do
            {
              v30 = (__m128)*(unsigned int *)v28;
              v22 = _mm_add_ps(v22, v23);
              v21 += 4;
              ++v28;
              v31 = _mm_mul_ps(v27, v25);
              v32 = _mm_add_ps(_mm_mul_ps(v26, v24), _mm_shuffle_ps(v30, v30, 0));
              v33 = v27;
              v27 = v26;
              v26 = _mm_add_ps(v32, v31);
              *((__m128 *)v21 - 1) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v26, v33), v22), *(__m128 *)(v21 - 4));
              --v29;
            }
            while ( v29 );
          }
          *(__m128 *)m_pDeflectorDSPInfo[v19++].fFiltState1 = v26;
          ++v17;
          *(__m128 *)this->m_pDeflectorDSPInfo[v19 - 1].fFiltState2 = v27;
          *(__m128 *)this->m_pDeflectorDSPInfo[v19 - 1].fGain = v22;
          --v18;
        }
        while ( v18 );
      }
      v34 = (__m128 *)v11;
      v35 = (float *)((char *)io_pBufferOut->pData + 4 * v5);
      if ( v12 )
      {
        v36 = v12;
        do
        {
          v37 = *v34;
          ++v35;
          ++v34;
          v38 = _mm_add_ps(v37, _mm_movehl_ps(v37, v37));
          *(v35 - 1) = _mm_shuffle_ps(v38, v38, 85).m128_f32[0] + v38.m128_f32[0];
          --v36;
        }
        while ( v36 );
      }
      CAkSoundSeedWooshProcess::DeflectorGainRampCompleted(this);
      LODWORD(v10) = v42;
      v5 = v12 + (unsigned int)v5;
      uValidFrames -= v12;
    }
    while ( uValidFrames );
  }
}

// File Line: 762
// RVA: 0xADD440
void __fastcall CAkSoundSeedWooshProcess::ProcessStereo(
        CAkSoundSeedWooshProcess *this,
        AkAudioBuffer *io_pBufferOut,
        float *in_pfTempStorage)
{
  int uValidFrames; // r12d
  __int64 v4; // rsi
  int v7; // r8d
  unsigned int v8; // r13d
  __m128 v9; // xmm1
  int v10; // ecx
  __int64 v11; // r9
  float *v12; // r15
  unsigned int v13; // edi
  unsigned int m_uOversamplingFactor; // ecx
  int v15; // eax
  int v16; // r8d
  float v17; // ecx
  DSP::CAkColoredNoise *p_m_NoiseGen; // rcx
  __int64 v19; // rdx
  __int64 v20; // r11
  __int64 v21; // rcx
  DeflectorDSP *m_pDeflectorDSPInfo; // rax
  float *v23; // r9
  __m128 v24; // xmm3
  __m128 v25; // xmm6
  __m128 v26; // xmm7
  __m128 v27; // xmm8
  __m128 v28; // xmm4
  __m128 v29; // xmm5
  float *v30; // r8
  __int64 v31; // r10
  __m128 v32; // xmm0
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm0
  __m128 *v36; // rcx
  float *v37; // rdx
  __int64 v38; // rax
  __m128 v39; // xmm1
  __m128 v40; // xmm1
  unsigned int v41; // edx
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 *v45; // rcx
  __m128 i; // xmm5
  __m128 v47; // xmm0
  float v48; // eax
  float v49; // eax
  unsigned int v50; // [rsp+20h] [rbp-F8h]
  int v51; // [rsp+120h] [rbp+8h]
  int v53; // [rsp+130h] [rbp+18h]
  size_t Size; // [rsp+138h] [rbp+20h]

  uValidFrames = io_pBufferOut->uValidFrames;
  v9 = 0i64;
  v4 = 0i64;
  v7 = 0;
  v8 = (this->m_cDeflectors + 3) >> 2;
  v51 = 0;
  v9.m128_f32[0] = (float)uValidFrames / (float)(int)this->m_uOversamplingFactor;
  v10 = (int)v9.m128_f32[0];
  if ( (int)v9.m128_f32[0] != 0x80000000 && (float)v10 != v9.m128_f32[0] )
    v9.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v9, v9)) & 1) + v10);
  v11 = ((int)v9.m128_f32[0] + 3) & 0xFFFFFFFC;
  v50 = ((int)v9.m128_f32[0] + 3) & 0xFFFFFFFC;
  v12 = &in_pfTempStorage[v11];
  if ( io_pBufferOut->uValidFrames )
  {
    Size = (unsigned int)(16 * v11);
    do
    {
      v13 = v11;
      this->m_fAutomationValues[0] = this->m_pfAutomationValues[v7];
      this->m_fAutomationValues[1] = this->m_pfAutomationValues[v7 + this->m_uOversamplingFactor];
      this->m_fAutomationValues[2] = this->m_pfAutomationValues[v7 + 2 * this->m_uOversamplingFactor];
      m_uOversamplingFactor = this->m_uOversamplingFactor;
      v15 = v7 + 2 * m_uOversamplingFactor;
      v16 = v7 + 1;
      v17 = this->m_pfAutomationValues[v15 + m_uOversamplingFactor];
      if ( uValidFrames < (unsigned int)v11 )
        v13 = uValidFrames;
      v53 = v16;
      this->m_fAutomationValues[3] = v17;
      CAkSoundSeedWooshProcess::Prepare(this, v13);
      if ( this->m_NoiseGen.m_NoiseColor == NOISECOLOR_PINK )
      {
        DSP::CAkColoredNoise::GenerateBufferPink(&this->m_NoiseGen, in_pfTempStorage, v13);
      }
      else if ( this->m_NoiseGen.m_NoiseColor == NOISECOLOR_RED )
      {
        DSP::CAkColoredNoise::GenerateBufferRed(&this->m_NoiseGen, in_pfTempStorage, v13);
      }
      else
      {
        p_m_NoiseGen = &this->m_NoiseGen;
        if ( this->m_NoiseGen.m_NoiseColor == NOISECOLOR_PURPLE )
          DSP::CAkColoredNoise::GenerateBufferPurple(p_m_NoiseGen, in_pfTempStorage, v13);
        else
          DSP::CAkWhiteNoise::GenerateBuffer(p_m_NoiseGen, in_pfTempStorage, v13);
      }
      memset(v12, 0, Size);
      if ( v8 )
      {
        v19 = 0i64;
        v20 = v8;
        v21 = 0i64;
        do
        {
          m_pDeflectorDSPInfo = this->m_pDeflectorDSPInfo;
          v23 = v12;
          v24 = *(__m128 *)m_pDeflectorDSPInfo[v19].fGain;
          v25 = *(__m128 *)m_pDeflectorDSPInfo[v19].fGainDelta;
          v26 = *(__m128 *)m_pDeflectorDSPInfo[v19].fCoefsA1;
          v27 = *(__m128 *)m_pDeflectorDSPInfo[v19].fCoefsA2;
          v28 = *(__m128 *)m_pDeflectorDSPInfo[v19].fFiltState1;
          v29 = *(__m128 *)m_pDeflectorDSPInfo[v19].fFiltState2;
          if ( v13 )
          {
            v30 = in_pfTempStorage;
            v31 = v13;
            do
            {
              v32 = (__m128)*(unsigned int *)v30;
              v24 = _mm_add_ps(v24, v25);
              v23 += 4;
              ++v30;
              v33 = _mm_mul_ps(v29, v27);
              v34 = _mm_add_ps(_mm_mul_ps(v28, v26), _mm_shuffle_ps(v32, v32, 0));
              v35 = v29;
              v29 = v28;
              v28 = _mm_add_ps(v34, v33);
              *((__m128 *)v23 - 1) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v28, v35), v24), *(__m128 *)(v23 - 4));
              --v31;
            }
            while ( v31 );
          }
          *(__m128 *)m_pDeflectorDSPInfo[v21++].fFiltState1 = v28;
          ++v19;
          *(__m128 *)this->m_pDeflectorDSPInfo[v21 - 1].fFiltState2 = v29;
          *(__m128 *)this->m_pDeflectorDSPInfo[v21 - 1].fGain = v24;
          --v20;
        }
        while ( v20 );
      }
      v36 = (__m128 *)v12;
      v37 = (float *)((char *)io_pBufferOut->pData + 4 * v4);
      if ( v13 )
      {
        v38 = v13;
        do
        {
          v39 = *v36;
          ++v37;
          ++v36;
          v40 = _mm_add_ps(v39, _mm_movehl_ps(v39, v39));
          *(v37 - 1) = _mm_shuffle_ps(v40, v40, 85).m128_f32[0] + v40.m128_f32[0];
          --v38;
        }
        while ( v38 );
      }
      CAkSoundSeedWooshProcess::DeflectorGainRampCompleted(this);
      v41 = v13 >> 2;
      v42 = _mm_shuffle_ps(
              (__m128)LODWORD(this->m_PositioningInfo.fChanGain[0]),
              (__m128)LODWORD(this->m_PositioningInfo.fChanGain[0]),
              0);
      v43 = _mm_shuffle_ps(
              (__m128)LODWORD(this->m_PositioningInfo.fChanGain[1]),
              (__m128)LODWORD(this->m_PositioningInfo.fChanGain[1]),
              0);
      v44 = _mm_shuffle_ps(
              (__m128)LODWORD(this->m_PositioningInfo.fChanGainDelta[0]),
              (__m128)LODWORD(this->m_PositioningInfo.fChanGainDelta[0]),
              0);
      v45 = (__m128 *)((char *)io_pBufferOut->pData + 4 * v4);
      for ( i = _mm_shuffle_ps(
                  (__m128)LODWORD(this->m_PositioningInfo.fChanGainDelta[1]),
                  (__m128)LODWORD(this->m_PositioningInfo.fChanGainDelta[1]),
                  0); v41; --v41 )
      {
        v42 = _mm_add_ps(v42, v44);
        v43 = _mm_add_ps(v43, i);
        v47 = *v45++;
        v45[-1] = _mm_mul_ps(v47, v42);
        v45[255] = _mm_mul_ps(v47, v43);
      }
      if ( this->m_uNumChannels == 2 )
      {
        *(_QWORD *)this->m_PositioningInfo.fChanGainDelta = 0i64;
        this->m_PositioningInfo.fChanGain[0] = this->m_PositioningInfo.fChanGainTarget[0];
        this->m_PositioningInfo.fChanGain[1] = this->m_PositioningInfo.fChanGainTarget[1];
      }
      else if ( this->m_uNumChannels == 4 )
      {
        this->m_PositioningInfo.fChanGain[0] = this->m_PositioningInfo.fChanGainTarget[0];
        v48 = this->m_PositioningInfo.fChanGainTarget[1];
        *(_QWORD *)this->m_PositioningInfo.fChanGainDelta = 0i64;
        this->m_PositioningInfo.fChanGain[1] = v48;
        v49 = this->m_PositioningInfo.fChanGainTarget[2];
        *(_QWORD *)&this->m_PositioningInfo.fChanGainDelta[2] = 0i64;
        this->m_PositioningInfo.fChanGain[2] = v49;
        this->m_PositioningInfo.fChanGain[3] = this->m_PositioningInfo.fChanGainTarget[3];
      }
      v7 = v53;
      LODWORD(v11) = v50;
      v4 = v13 + v51;
      v51 += v13;
      uValidFrames -= v13;
    }
    while ( uValidFrames );
  }
}

// File Line: 870
// RVA: 0xADD810
void __fastcall CAkSoundSeedWooshProcess::ProcessQuad(
        CAkSoundSeedWooshProcess *this,
        AkAudioBuffer *io_pBufferOut,
        float *in_pfTempStorage)
{
  int uValidFrames; // r12d
  __int64 v5; // r14
  __int64 v6; // r13
  __m128 v8; // xmm1
  int v9; // ecx
  __int64 v10; // r8
  float *v11; // r15
  unsigned int v12; // edi
  unsigned int m_uOversamplingFactor; // ecx
  int v14; // eax
  float v15; // ecx
  DSP::CAkColoredNoise *p_m_NoiseGen; // rcx
  __int64 v17; // rdx
  __int64 v18; // r11
  __int64 v19; // rcx
  DeflectorDSP *m_pDeflectorDSPInfo; // rax
  float *v21; // r9
  __m128 v22; // xmm3
  __m128 v23; // xmm6
  __m128 v24; // xmm7
  __m128 v25; // xmm8
  __m128 v26; // xmm4
  __m128 v27; // xmm5
  float *v28; // r8
  __int64 v29; // r10
  __m128 v30; // xmm0
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  __m128 *v34; // rdx
  float *v35; // r8
  __int64 v36; // rax
  __m128 v37; // xmm1
  __m128 v38; // xmm1
  float v39; // eax
  float v40; // eax
  unsigned int v41; // [rsp+110h] [rbp+8h]
  size_t Size; // [rsp+120h] [rbp+18h]
  unsigned int v44; // [rsp+128h] [rbp+20h]

  uValidFrames = io_pBufferOut->uValidFrames;
  v8 = 0i64;
  v5 = 0i64;
  v41 = (this->m_cDeflectors + 3) >> 2;
  v6 = 0i64;
  v8.m128_f32[0] = (float)uValidFrames / (float)(int)this->m_uOversamplingFactor;
  v9 = (int)v8.m128_f32[0];
  if ( (int)v8.m128_f32[0] != 0x80000000 && (float)v9 != v8.m128_f32[0] )
    v8.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v8, v8)) & 1) + v9);
  v10 = ((int)v8.m128_f32[0] + 3) & 0xFFFFFFFC;
  v44 = ((int)v8.m128_f32[0] + 3) & 0xFFFFFFFC;
  v11 = &in_pfTempStorage[v10];
  if ( io_pBufferOut->uValidFrames )
  {
    Size = (unsigned int)(16 * v10);
    do
    {
      v12 = v10;
      this->m_fAutomationValues[0] = this->m_pfAutomationValues[v6];
      this->m_fAutomationValues[1] = this->m_pfAutomationValues[(unsigned int)(v6 + this->m_uOversamplingFactor)];
      this->m_fAutomationValues[2] = this->m_pfAutomationValues[(unsigned int)(v6 + 2 * this->m_uOversamplingFactor)];
      m_uOversamplingFactor = this->m_uOversamplingFactor;
      v14 = v6 + 2 * m_uOversamplingFactor;
      v6 = (unsigned int)(v6 + 1);
      v15 = this->m_pfAutomationValues[v14 + m_uOversamplingFactor];
      if ( uValidFrames < (unsigned int)v10 )
        v12 = uValidFrames;
      this->m_fAutomationValues[3] = v15;
      CAkSoundSeedWooshProcess::Prepare(this, v12);
      if ( this->m_NoiseGen.m_NoiseColor == NOISECOLOR_PINK )
      {
        DSP::CAkColoredNoise::GenerateBufferPink(&this->m_NoiseGen, in_pfTempStorage, v12);
      }
      else if ( this->m_NoiseGen.m_NoiseColor == NOISECOLOR_RED )
      {
        DSP::CAkColoredNoise::GenerateBufferRed(&this->m_NoiseGen, in_pfTempStorage, v12);
      }
      else
      {
        p_m_NoiseGen = &this->m_NoiseGen;
        if ( this->m_NoiseGen.m_NoiseColor == NOISECOLOR_PURPLE )
          DSP::CAkColoredNoise::GenerateBufferPurple(p_m_NoiseGen, in_pfTempStorage, v12);
        else
          DSP::CAkWhiteNoise::GenerateBuffer(p_m_NoiseGen, in_pfTempStorage, v12);
      }
      memset(v11, 0, Size);
      if ( v41 )
      {
        v17 = 0i64;
        v18 = v41;
        v19 = 0i64;
        do
        {
          m_pDeflectorDSPInfo = this->m_pDeflectorDSPInfo;
          v21 = v11;
          v22 = *(__m128 *)m_pDeflectorDSPInfo[v17].fGain;
          v23 = *(__m128 *)m_pDeflectorDSPInfo[v17].fGainDelta;
          v24 = *(__m128 *)m_pDeflectorDSPInfo[v17].fCoefsA1;
          v25 = *(__m128 *)m_pDeflectorDSPInfo[v17].fCoefsA2;
          v26 = *(__m128 *)m_pDeflectorDSPInfo[v17].fFiltState1;
          v27 = *(__m128 *)m_pDeflectorDSPInfo[v17].fFiltState2;
          if ( v12 )
          {
            v28 = in_pfTempStorage;
            v29 = v12;
            do
            {
              v30 = (__m128)*(unsigned int *)v28;
              v22 = _mm_add_ps(v22, v23);
              v21 += 4;
              ++v28;
              v31 = _mm_mul_ps(v27, v25);
              v32 = _mm_add_ps(_mm_mul_ps(v26, v24), _mm_shuffle_ps(v30, v30, 0));
              v33 = v27;
              v27 = v26;
              v26 = _mm_add_ps(v32, v31);
              *((__m128 *)v21 - 1) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v26, v33), v22), *(__m128 *)(v21 - 4));
              --v29;
            }
            while ( v29 );
          }
          *(__m128 *)m_pDeflectorDSPInfo[v19++].fFiltState1 = v26;
          ++v17;
          *(__m128 *)this->m_pDeflectorDSPInfo[v19 - 1].fFiltState2 = v27;
          *(__m128 *)this->m_pDeflectorDSPInfo[v19 - 1].fGain = v22;
          --v18;
        }
        while ( v18 );
      }
      v34 = (__m128 *)v11;
      v35 = (float *)((char *)io_pBufferOut->pData + 4 * v5);
      if ( v12 )
      {
        v36 = v12;
        do
        {
          v37 = *v34;
          ++v35;
          ++v34;
          v38 = _mm_add_ps(v37, _mm_movehl_ps(v37, v37));
          *(v35 - 1) = _mm_shuffle_ps(v38, v38, 85).m128_f32[0] + v38.m128_f32[0];
          --v36;
        }
        while ( v36 );
      }
      CAkSoundSeedWooshProcess::DeflectorGainRampCompleted(this);
      CAkSoundSeedWooshProcess::QuadSpatialization(this, io_pBufferOut, v12, v5);
      if ( this->m_uNumChannels == 2 )
      {
        *(_QWORD *)this->m_PositioningInfo.fChanGainDelta = 0i64;
        this->m_PositioningInfo.fChanGain[0] = this->m_PositioningInfo.fChanGainTarget[0];
        this->m_PositioningInfo.fChanGain[1] = this->m_PositioningInfo.fChanGainTarget[1];
      }
      else if ( this->m_uNumChannels == 4 )
      {
        this->m_PositioningInfo.fChanGain[0] = this->m_PositioningInfo.fChanGainTarget[0];
        v39 = this->m_PositioningInfo.fChanGainTarget[1];
        *(_QWORD *)this->m_PositioningInfo.fChanGainDelta = 0i64;
        this->m_PositioningInfo.fChanGain[1] = v39;
        v40 = this->m_PositioningInfo.fChanGainTarget[2];
        *(_QWORD *)&this->m_PositioningInfo.fChanGainDelta[2] = 0i64;
        this->m_PositioningInfo.fChanGain[2] = v40;
        this->m_PositioningInfo.fChanGain[3] = this->m_PositioningInfo.fChanGainTarget[3];
      }
      LODWORD(v10) = v44;
      v5 = v12 + (unsigned int)v5;
      uValidFrames -= v12;
    }
    while ( uValidFrames );
  }
}

// File Line: 976
// RVA: 0xADDB90
void __fastcall CAkSoundSeedWooshProcess::StereoSpatialization(
        CAkSoundSeedWooshProcess *this,
        AkAudioBuffer *io_pBufferOut,
        unsigned int in_uNumFrames,
        unsigned int in_uFrameOffset)
{
  unsigned int v4; // r8d
  __m128 *v5; // rax
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  __m128 v8; // xmm4
  __m128 i; // xmm5
  __m128 v10; // xmm0

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
    v6 = _mm_add_ps(v6, v8);
    v7 = _mm_add_ps(v7, i);
    v10 = *v5++;
    v5[-1] = _mm_mul_ps(v10, v6);
    v5[255] = _mm_mul_ps(v10, v7);
  }
}

// File Line: 1003
// RVA: 0xADDC00
void __fastcall CAkSoundSeedWooshProcess::QuadSpatialization(
        CAkSoundSeedWooshProcess *this,
        AkAudioBuffer *io_pBufferOut,
        unsigned int in_uNumFrames,
        unsigned int in_uFrameOffset)
{
  unsigned int v4; // r8d
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
    v15 = *v5++;
    v8 = _mm_add_ps(v8, i);
    v9 = _mm_add_ps(v9, v11);
    v5[-1] = _mm_mul_ps(v14, v6);
    v5[255] = _mm_mul_ps(v14, v7);
    v5[511] = _mm_mul_ps(v15, v8);
    v5[767] = _mm_mul_ps(v14, v9);
  }
}


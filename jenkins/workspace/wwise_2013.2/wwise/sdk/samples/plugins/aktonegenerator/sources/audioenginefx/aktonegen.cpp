// File Line: 143
// RVA: 0xAD2080
void __fastcall CreateToneSource(AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkToneGen *v1; // rax

  v1 = (CAkToneGen *)in_pAllocator->vfptr->Malloc(in_pAllocator, 360i64);
  if ( v1 )
    CAkToneGen::CAkToneGen(v1);
}

// File Line: 155
// RVA: 0xAD1F10
void __fastcall CAkToneGen::CAkToneGen(CAkToneGen *this)
{
  CAkLpFilter *m_LpFilters; // rbx
  int i; // esi

  m_LpFilters = this->m_LpFilters;
  this->vfptr = (AK::IAkPluginVtbl *)&CAkToneGen::`vftable;
  for ( i = 2; i >= 0; --i )
    CAkLpFilter::CAkLpFilter(m_LpFilters++);
  *(_QWORD *)&this->m_GainRamp.m_fStepIncrement = 0i64;
  *(_QWORD *)&this->m_GainRamp.m_fTarget = 0i64;
  *(_QWORD *)&this->m_GainRamp.m_uRampCount = 0i64;
  this->m_pSharedParams = 0i64;
  this->m_pSourceFXContext = 0i64;
  this->m_uSampleRate = 0;
  memset(&this->m_staticParams, 0, sizeof(this->m_staticParams));
  memset(this->m_LpFilters, 0, sizeof(this->m_LpFilters));
  this->m_pOscWaveTable = 0i64;
  this->m_pPinkNoiseRandGen = 0i64;
  this->m_fpPerformDSP = 0i64;
  *(_QWORD *)&this->m_uTotalOutSampCount = 0i64;
  *(_QWORD *)&this->m_uTotalNumSamples = 0i64;
  this->m_uPhaseIndex = 0;
  *(_QWORD *)&this->m_fOscMaxFreq = 0i64;
  this->m_fFreqSweepScaleFactor = 0.0;
  *(_QWORD *)&this->m_fOverSamplingFrequency = 0i64;
  *(_QWORD *)&this->m_fSampleInc = 1065353216i64;
  this->m_iNumLoops = 1;
  this->m_bFinite = 1;
  *(_QWORD *)&this->m_fEnvInc[1] = 0i64;
  this->m_fEnvInc[3] = 0.0;
  this->m_uCurEnvSegment = 0;
  *(_QWORD *)this->m_uEnvSegmentDur = 0i64;
  *(_QWORD *)&this->m_uEnvSegmentDur[2] = 0i64;
  *(_QWORD *)&this->m_uEnvSegmentCount = 0i64;
}

// File Line: 203
// RVA: 0xAD2190
__int64 __fastcall CAkToneGen::Init(
        CAkToneGen *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkSourcePluginContext *in_pSourceFXContext,
        CAkToneGenParams *in_pParams,
        AkAudioFormat *io_rFormat)
{
  signed int uSampleRate; // eax
  float v8; // xmm0_4
  unsigned int uChannelMask; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  __int16 v14; // ax
  int v15; // r8d
  int v16; // edx
  int v17; // ecx
  int v18; // eax
  int v19; // eax
  float v20; // xmm0_4
  int v21; // eax
  float v22; // xmm1_4
  int v23; // eax
  signed int v24; // eax
  int v25; // edx
  signed int v26; // eax
  int v27; // ecx
  float v28; // xmm0_4
  __int64 v29; // rsi
  AkToneGenType eGenType; // eax
  float *v31; // rax
  __int64 result; // rax
  __int64 v33; // rcx
  __int64 v34; // rdx
  float fStartFreqRandMin; // xmm6_4
  float fStartFreqRandMax; // xmm7_4
  float v37; // xmm0_4
  bool v38; // zf
  float fStopFreqRandMax; // xmm7_4
  float fStopFreqRandMin; // xmm6_4
  float v41; // xmm0_4
  CAkLpFilter *m_LpFilters; // rdi
  void (__fastcall *v43)(CAkToneGen *, float *, unsigned int); // rax
  void (__fastcall *v44)(CAkToneGen *, float *, unsigned int); // rcx

  this->m_pSourceFXContext = in_pSourceFXContext;
  uSampleRate = io_rFormat->uSampleRate;
  this->m_uSampleRate = io_rFormat->uSampleRate;
  v8 = (float)uSampleRate * 0.5;
  if ( v8 >= 20000.0 )
    v8 = FLOAT_20000_0;
  this->m_fOscMaxFreq = v8;
  this->m_pSharedParams = in_pParams;
  this->m_staticParams.fStartFreqRandMin = in_pParams->m_Params.staticParams.fStartFreqRandMin;
  *(AK::IAkPluginParam *)&this->m_staticParams.fStartFreqRandMax = *(AK::IAkPluginParam *)&in_pParams->m_Params.staticParams.fStartFreqRandMax;
  *(AK::IAkPluginParam *)&this->m_staticParams.eGenSweep = *(AK::IAkPluginParam *)&in_pParams->m_Params.staticParams.eGenSweep;
  *(AK::IAkPluginParam *)&this->m_staticParams.fStopFreqRandMax = *(AK::IAkPluginParam *)&in_pParams->m_Params.staticParams.fStopFreqRandMax;
  *(AK::IAkPluginParam *)&this->m_staticParams.eGenMode = *(AK::IAkPluginParam *)&in_pParams->m_Params.staticParams.eGenMode;
  *(AK::IAkPluginParam *)&this->m_staticParams.fAttackDur = *(AK::IAkPluginParam *)&in_pParams->m_Params.staticParams.fAttackDur;
  *(AK::IAkPluginParam *)&this->m_staticParams.fSustainDur = *(AK::IAkPluginParam *)&in_pParams->m_Params.staticParams.fSustainDur;
  this->m_staticParams.fReleaseDur = in_pParams->m_Params.staticParams.fReleaseDur;
  uChannelMask = in_pParams->m_Params.staticParams.uChannelMask;
  this->m_staticParams.uChannelMask = uChannelMask;
  *((_DWORD *)io_rFormat + 1) ^= (*((_DWORD *)io_rFormat + 1) ^ uChannelMask) & 0x3FFFF;
  v10 = *((_DWORD *)io_rFormat + 1) & 0x3FFFF;
  if ( v10 > 0x37 )
  {
    v11 = v10 - 59;
    if ( v11 )
    {
      v12 = v11 - 4;
      if ( v12 )
      {
        v13 = v12 - 1528;
        if ( v13 )
        {
          if ( v13 != 8 )
LABEL_10:
            *((_DWORD *)io_rFormat + 1) = *((_DWORD *)io_rFormat + 1) & 0xFFFC0000 | 4;
        }
      }
    }
  }
  else if ( v10 != 55 )
  {
    switch ( v10 )
    {
      case 3u:
        break;
      case 5u:
      case 6u:
      case 7u:
        JUMPOUT(0x141010000i64);
      case 8u:
        JUMPOUT(0x141010100i64);
      case 9u:
      case 0xAu:
      case 0xBu:
      case 0xCu:
      case 0xDu:
      case 0xEu:
      case 0xFu:
      case 0x10u:
        JUMPOUT(0x141010101i64);
      default:
        goto LABEL_10;
    }
  }
  v14 = ((__int64 (__fastcall *)(AK::IAkSourcePluginContext *))this->m_pSourceFXContext->vfptr[1].__vecDelDtor)(this->m_pSourceFXContext);
  this->m_iNumLoops = v14;
  this->m_bFinite = v14 != 0;
  if ( this->m_staticParams.eGenMode == AKTONEGENMODE_ENV )
  {
    v15 = (int)(float)((float)(int)this->m_uSampleRate * this->m_staticParams.fAttackDur);
    this->m_uEnvSegmentDur[0] = v15;
    v16 = (int)(float)((float)(int)this->m_uSampleRate * this->m_staticParams.fDecayDur);
    this->m_uEnvSegmentDur[1] = v16;
    v17 = (int)(float)((float)(int)this->m_uSampleRate * this->m_staticParams.fSustainDur);
    this->m_uEnvSegmentDur[2] = v17;
    v18 = (int)(float)((float)(int)this->m_uSampleRate * this->m_staticParams.fReleaseDur);
    this->m_uEnvSegmentDur[3] = v18;
    this->m_uIterNumSamples = v17 + v16 + v15 + v18;
    v19 = this->m_uEnvSegmentDur[0];
    if ( !v19 )
      v19 = 1;
    this->m_uEnvSegmentDur[0] = v19;
    this->m_fEnvInc[0] = 1.0 / (float)v19;
    v20 = powf(10.0, this->m_staticParams.fSustainVal * 0.050000001);
    v21 = this->m_uEnvSegmentDur[1];
    if ( !v21 )
      v21 = 1;
    this->m_uEnvSegmentDur[1] = v21;
    this->m_fEnvInc[2] = 0.0;
    v22 = (float)v21;
    v23 = this->m_uEnvSegmentDur[3];
    if ( !v23 )
      v23 = 1;
    this->m_uEnvSegmentDur[3] = v23;
    this->m_fEnvInc[1] = (float)(-1.0 / v22) * (float)(1.0 - v20);
    this->m_fEnvInc[3] = (float)(-1.0 / (float)v23) * v20;
    this->m_fEnvCurGain = 0.0;
  }
  else
  {
    if ( v14 == 1 )
    {
      v24 = io_rFormat->uSampleRate;
      this->m_uEnvSegmentDur[1] = 0;
      v25 = (int)(float)((float)v24 * 0.0049999999);
      this->m_uEnvSegmentDur[0] = v25;
      this->m_uEnvSegmentDur[2] = (int)(float)((float)(int)this->m_uSampleRate * this->m_staticParams.fFixDur);
      v26 = io_rFormat->uSampleRate;
      *(_QWORD *)&this->m_fEnvInc[1] = 0i64;
      v27 = (int)(float)((float)v26 * 0.0049999999);
      this->m_uEnvSegmentDur[3] = v27;
      this->m_fEnvInc[0] = 1.0 / (float)v25;
      this->m_fEnvInc[3] = -1.0 / (float)v27;
      this->m_fEnvCurGain = 0.0;
    }
    else
    {
      *(_QWORD *)this->m_uEnvSegmentDur = 0i64;
      v28 = (float)(int)this->m_uSampleRate * this->m_staticParams.fFixDur;
      this->m_uEnvSegmentDur[3] = 0;
      *(_QWORD *)this->m_fEnvInc = 0i64;
      *(_QWORD *)&this->m_fEnvInc[2] = 0i64;
      this->m_uEnvSegmentDur[2] = (int)v28;
      this->m_fEnvCurGain = 1.0;
    }
    this->m_uIterNumSamples = this->m_uEnvSegmentDur[2]
                            + this->m_uEnvSegmentDur[1]
                            + this->m_uEnvSegmentDur[0]
                            + this->m_uEnvSegmentDur[3];
  }
  v29 = 3i64;
  this->m_uTotalNumSamples = this->m_uIterNumSamples * this->m_iNumLoops;
  eGenType = this->m_staticParams.eGenType;
  if ( (unsigned int)eGenType <= AKTONEGENTYPE_SAWTOOTH )
  {
    fStartFreqRandMin = this->m_staticParams.fStartFreqRandMin;
    fStartFreqRandMax = this->m_staticParams.fStartFreqRandMax;
    if ( fStartFreqRandMin == fStartFreqRandMax )
      v37 = this->m_staticParams.fStartFreqRandMin;
    else
      v37 = (float)((float)((float)rand() * 0.000030518509) * (float)(fStartFreqRandMax - fStartFreqRandMin))
          + fStartFreqRandMin;
    v38 = !this->m_staticParams.bFreqSweep;
    this->m_fStartFreqModifier = v37;
    if ( !v38 )
    {
      fStopFreqRandMax = this->m_staticParams.fStopFreqRandMax;
      fStopFreqRandMin = this->m_staticParams.fStopFreqRandMin;
      if ( fStopFreqRandMin == fStopFreqRandMax )
        v41 = this->m_staticParams.fStopFreqRandMin;
      else
        v41 = (float)((float)((float)rand() * 0.000030518509) * (float)(fStopFreqRandMax - fStopFreqRandMin))
            + fStopFreqRandMin;
      this->m_fStopFreqModifier = v41;
    }
  }
  else if ( eGenType == AKTONEGENTYPE_PINKNOISE )
  {
    v31 = (float *)in_pAllocator->vfptr->Malloc(in_pAllocator, 120i64);
    this->m_pPinkNoiseRandGen = v31;
    if ( !v31 )
      return 52i64;
    *(_QWORD *)&this->m_uPinkNoiseIndMask = 0x3FFFFFFFi64;
    this->m_fNoiseScale = 0.12903225;
    v33 = 3i64;
    v34 = 3i64;
    do
    {
      v33 += 10i64;
      this->m_pPinkNoiseRandGen[v33 - 13] = 0.0;
      this->m_pPinkNoiseRandGen[v33 - 12] = 0.0;
      this->m_pPinkNoiseRandGen[v33 - 11] = 0.0;
      this->m_pPinkNoiseRandGen[v33 - 10] = 0.0;
      this->m_pPinkNoiseRandGen[v33 - 9] = 0.0;
      this->m_pPinkNoiseRandGen[v33 - 8] = 0.0;
      this->m_pPinkNoiseRandGen[v33 - 7] = 0.0;
      this->m_pPinkNoiseRandGen[v33 - 6] = 0.0;
      this->m_pPinkNoiseRandGen[v33 - 5] = 0.0;
      this->m_pPinkNoiseRandGen[v33 - 4] = 0.0;
      --v34;
    }
    while ( v34 );
    this->m_fPinkNoiseRunSum = 0.0;
  }
  m_LpFilters = this->m_LpFilters;
  this->m_fOverSamplingFrequency = (float)(4 * this->m_uSampleRate);
  do
  {
    CAkLpFilter::SetCoefs(
      m_LpFilters++,
      (float)((float)(int)this->m_uSampleRate * 18000.0) * 0.000020833333,
      this->m_fOverSamplingFrequency);
    --v29;
  }
  while ( v29 );
  switch ( this->m_staticParams.eGenType )
  {
    case AKTONEGENTYPE_SINE:
      v38 = !this->m_staticParams.bFreqSweep;
      this->m_pOscWaveTable = fSineTable;
      if ( !v38 )
      {
        v43 = CAkToneGen::ProcessWaveTableLinSweep;
        v44 = CAkToneGen::ProcessWaveTableLogSweep;
        goto LABEL_43;
      }
      this->m_fpPerformDSP = CAkToneGen::ProcessWaveTableNoSweep;
      goto LABEL_56;
    case AKTONEGENTYPE_TRIANGLE:
      v38 = !this->m_staticParams.bFreqSweep;
      this->m_pOscWaveTable = fTriangleTable;
      if ( v38 )
        goto LABEL_49;
      v43 = CAkToneGen::ProcessOversampledWaveTableLinSweep;
      v44 = CAkToneGen::ProcessOversampledWaveTableLogSweep;
      goto LABEL_43;
    case AKTONEGENTYPE_SQUARE:
      v38 = !this->m_staticParams.bFreqSweep;
      this->m_pOscWaveTable = fSquareTable;
      if ( v38 )
        goto LABEL_49;
      v43 = CAkToneGen::ProcessOversampledWaveTableLinSweep;
      v44 = CAkToneGen::ProcessOversampledWaveTableLogSweep;
      goto LABEL_43;
    case AKTONEGENTYPE_SAWTOOTH:
      v38 = !this->m_staticParams.bFreqSweep;
      this->m_pOscWaveTable = fSawtoothTable;
      if ( v38 )
      {
LABEL_49:
        this->m_fpPerformDSP = CAkToneGen::ProcessOversampledWaveTableNoSweep;
      }
      else
      {
        v43 = CAkToneGen::ProcessOversampledWaveTableLinSweep;
        v44 = CAkToneGen::ProcessOversampledWaveTableLogSweep;
LABEL_43:
        if ( this->m_staticParams.eGenSweep == AKTONEGENSWEEP_LOG )
          v43 = v44;
        this->m_fpPerformDSP = v43;
      }
LABEL_56:
      result = 1i64;
      break;
    case AKTONEGENTYPE_WHITENOISE:
      this->m_fpPerformDSP = CAkToneGen::ProcessWhiteNoise;
      goto LABEL_56;
    case AKTONEGENTYPE_PINKNOISE:
      this->m_fpPerformDSP = CAkToneGen::ProcessPinkNoise;
      goto LABEL_56;
    default:
      goto LABEL_56;
  }
  return result;
}

// File Line: 445
// RVA: 0xAD29A0
__int64 __fastcall CAkToneGen::Term(CAkToneGen *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this->m_pPinkNoiseRandGen )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    this->m_pPinkNoiseRandGen = 0i64;
  }
  this->vfptr->__vecDelDtor(this, 0i64);
  in_pAllocator->vfptr->Free(in_pAllocator, this);
  return 1i64;
}

// File Line: 461
// RVA: 0xAD2870
__int64 __fastcall CAkToneGen::Reset(CAkToneGen *this)
{
  bool v1; // zf
  float v3; // xmm0_4
  signed int m_uSampleRate; // eax
  float v5; // xmm2_4
  CAkLpFilter *m_LpFilters; // rbx
  __int64 v7; // rdi

  v1 = this->m_staticParams.eGenMode == AKTONEGENMODE_ENV;
  *(_QWORD *)&this->m_uTotalOutSampCount = 0i64;
  *(_QWORD *)&this->m_uPhaseIndex = 0i64;
  this->m_uCurEnvSegment = 0;
  this->m_uEnvSegmentCount = 0;
  if ( v1 || this->m_iNumLoops == 1 )
    this->m_fEnvCurGain = 0.0;
  else
    this->m_fEnvCurGain = 1.0;
  v3 = powf(10.0, this->m_pSharedParams->m_Params.fGain * 0.050000001);
  m_uSampleRate = this->m_uSampleRate;
  this->m_GainRamp.m_uRampCount = 0;
  this->m_GainRamp.m_fCurrent = v3;
  this->m_GainRamp.m_fTarget = v3;
  v5 = 1.0 / (float)((float)m_uSampleRate * 0.1);
  this->m_GainRamp.m_fStepIncrement = v5;
  this->m_GainRamp.m_uRampLength = (int)(float)(0.0 / v5);
  LODWORD(this->m_GainRamp.m_fInc) = LODWORD(v5) ^ _xmm[0];
  m_LpFilters = this->m_LpFilters;
  v7 = 3i64;
  do
  {
    CAkLpFilter::Reset(m_LpFilters++);
    --v7;
  }
  while ( v7 );
  return 1i64;
}

// File Line: 495
// RVA: 0xAD2170
__int64 __fastcall CAkToneGen::GetPluginInfo(CAkToneGen *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeSource;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 511
// RVA: 0xAD20B0
void __fastcall CAkToneGen::Execute(CAkToneGen *this, AkAudioBuffer *io_pBufferOut)
{
  unsigned int uMaxFrames; // esi

  if ( this->m_bFinite )
  {
    uMaxFrames = this->m_uTotalNumSamples - this->m_uTotalOutSampCount;
    if ( io_pBufferOut->uMaxFrames < uMaxFrames )
      uMaxFrames = io_pBufferOut->uMaxFrames;
  }
  else
  {
    uMaxFrames = io_pBufferOut->uMaxFrames;
  }
  if ( uMaxFrames )
  {
    this->m_fpPerformDSP(this, (float *)io_pBufferOut->pData, uMaxFrames);
    io_pBufferOut->uValidFrames = uMaxFrames;
  }
  if ( this->m_uTotalOutSampCount >= this->m_uTotalNumSamples && this->m_bFinite )
    io_pBufferOut->eState = AK_NoMoreData;
  else
    io_pBufferOut->eState = AK_DataReady;
}

// File Line: 547
// RVA: 0xAD2130
float __fastcall CAkToneGen::GetDuration(CAkToneGen *this)
{
  return (float)((float)(int)this->m_uTotalNumSamples * 1000.0) / (float)(int)this->m_uSampleRate;
}

// File Line: 555
// RVA: 0xAD2160
float __fastcall CAkToneGen::GetEnvelope(CAkToneGen *this)
{
  return this->m_fEnvCurGain;
}

// File Line: 560
// RVA: 0xAD2970
__int64 __fastcall CAkToneGen::StopLooping(CAkToneGen *this)
{
  unsigned int m_uIterNumSamples; // r8d
  unsigned int v2; // edx
  __int64 result; // rax

  m_uIterNumSamples = this->m_uIterNumSamples;
  v2 = this->m_uTotalOutSampCount % m_uIterNumSamples;
  this->m_bFinite = 1;
  this->m_iNumLoops = 1;
  this->m_uTotalNumSamples = m_uIterNumSamples;
  result = 1i64;
  this->m_uTotalOutSampCount = v2;
  return result;
}


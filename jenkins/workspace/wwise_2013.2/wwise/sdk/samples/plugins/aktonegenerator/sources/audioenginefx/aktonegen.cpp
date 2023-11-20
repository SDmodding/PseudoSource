// File Line: 143
// RVA: 0xAD2080
void __fastcall CreateToneSource(AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkToneGen *v1; // rax

  v1 = (CAkToneGen *)in_pAllocator->vfptr->Malloc(in_pAllocator, 360ui64);
  if ( v1 )
    CAkToneGen::CAkToneGen(v1);
}

// File Line: 155
// RVA: 0xAD1F10
void __fastcall CAkToneGen::CAkToneGen(CAkToneGen *this)
{
  CAkToneGen *v1; // rdi
  CAkLpFilter *v2; // rbx
  signed int v3; // esi

  v1 = this;
  v2 = this->m_LpFilters;
  this->vfptr = (AK::IAkPluginVtbl *)&CAkToneGen::`vftable;
  v3 = 2;
  do
  {
    CAkLpFilter::CAkLpFilter(v2);
    ++v2;
    --v3;
  }
  while ( v3 >= 0 );
  *(_QWORD *)&v1->m_GainRamp.m_fStepIncrement = 0i64;
  *(_QWORD *)&v1->m_GainRamp.m_fTarget = 0i64;
  *(_QWORD *)&v1->m_GainRamp.m_uRampCount = 0i64;
  v1->m_pSharedParams = 0i64;
  v1->m_pSourceFXContext = 0i64;
  v1->m_uSampleRate = 0;
  memset(&v1->m_staticParams, 0, 0x3Cui64);
  memset(v1->m_LpFilters, 0, 0x6Cui64);
  v1->m_pOscWaveTable = 0i64;
  v1->m_pPinkNoiseRandGen = 0i64;
  v1->m_fpPerformDSP = 0i64;
  *(_QWORD *)&v1->m_uTotalOutSampCount = 0i64;
  *(_QWORD *)&v1->m_uTotalNumSamples = 0i64;
  v1->m_uPhaseIndex = 0;
  *(_QWORD *)&v1->m_fOscMaxFreq = 0i64;
  v1->m_fFreqSweepScaleFactor = 0.0;
  *(_QWORD *)&v1->m_fOverSamplingFrequency = 0i64;
  *(_QWORD *)&v1->m_fSampleInc = 1065353216i64;
  v1->m_iNumLoops = 1;
  v1->m_bFinite = 1;
  *(_QWORD *)&v1->m_fEnvInc[1] = 0i64;
  v1->m_fEnvInc[3] = 0.0;
  v1->m_uCurEnvSegment = 0;
  *(_QWORD *)v1->m_uEnvSegmentDur = 0i64;
  *(_QWORD *)&v1->m_uEnvSegmentDur[2] = 0i64;
  *(_QWORD *)&v1->m_uEnvSegmentCount = 0i64;
}

// File Line: 203
// RVA: 0xAD2190
CAkToneGen::Init

// File Line: 445
// RVA: 0xAD29A0
signed __int64 __fastcall CAkToneGen::Term(CAkToneGen *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkToneGen *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this->m_pPinkNoiseRandGen )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    v3->m_pPinkNoiseRandGen = 0i64;
  }
  v3->vfptr->__vecDelDtor((AK::IAkPlugin *)&v3->vfptr, 0);
  v2->vfptr->Free(v2, v3);
  return 1i64;
}

// File Line: 461
// RVA: 0xAD2870
signed __int64 __fastcall CAkToneGen::Reset(CAkToneGen *this)
{
  bool v1; // zf
  CAkToneGen *v2; // rbx
  float v3; // xmm0_4
  signed int v4; // eax
  float v5; // xmm2_4
  CAkLpFilter *v6; // rbx
  signed __int64 v7; // rdi

  v1 = this->m_staticParams.eGenMode == 1;
  v2 = this;
  *(_QWORD *)&this->m_uTotalOutSampCount = 0i64;
  *(_QWORD *)&this->m_uPhaseIndex = 0i64;
  this->m_uCurEnvSegment = 0;
  this->m_uEnvSegmentCount = 0;
  if ( v1 || this->m_iNumLoops == 1 )
    this->m_fEnvCurGain = 0.0;
  else
    this->m_fEnvCurGain = 1.0;
  v3 = powf(10.0, this->m_pSharedParams->m_Params.fGain * 0.050000001);
  v4 = v2->m_uSampleRate;
  v2->m_GainRamp.m_uRampCount = 0;
  v2->m_GainRamp.m_fCurrent = v3;
  v2->m_GainRamp.m_fTarget = v3;
  v5 = 1.0 / (float)((float)v4 * 0.1);
  v2->m_GainRamp.m_fStepIncrement = v5;
  v2->m_GainRamp.m_uRampLength = (signed int)(float)(0.0 / (float)(1.0 / (float)((float)v4 * 0.1)));
  LODWORD(v2->m_GainRamp.m_fInc) = LODWORD(v5) ^ _xmm[0];
  v6 = v2->m_LpFilters;
  v7 = 3i64;
  do
  {
    CAkLpFilter::Reset(v6);
    ++v6;
    --v7;
  }
  while ( v7 );
  return 1i64;
}

// File Line: 495
// RVA: 0xAD2170
signed __int64 __fastcall CAkToneGen::GetPluginInfo(CAkToneGen *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 2;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 511
// RVA: 0xAD20B0
void __fastcall CAkToneGen::Execute(CAkToneGen *this, AkAudioBuffer *io_pBufferOut)
{
  AkAudioBuffer *v2; // rdi
  CAkToneGen *v3; // rbx
  unsigned int v4; // esi

  v2 = io_pBufferOut;
  v3 = this;
  if ( this->m_bFinite )
  {
    v4 = this->m_uTotalNumSamples - this->m_uTotalOutSampCount;
    if ( io_pBufferOut->uMaxFrames < v4 )
      v4 = io_pBufferOut->uMaxFrames;
  }
  else
  {
    v4 = io_pBufferOut->uMaxFrames;
  }
  if ( v4 )
  {
    this->m_fpPerformDSP(this, (float *)io_pBufferOut->pData, v4);
    v2->uValidFrames = v4;
  }
  if ( v3->m_uTotalOutSampCount >= v3->m_uTotalNumSamples && v3->m_bFinite )
    v2->eState = 17;
  else
    v2->eState = 45;
}

// File Line: 547
// RVA: 0xAD2130
float __fastcall CAkToneGen::GetDuration(CAkToneGen *this)
{
  return (float)((float)(signed int)this->m_uTotalNumSamples * 1000.0) / (float)(signed int)this->m_uSampleRate;
}

// File Line: 555
// RVA: 0xAD2160
float __fastcall CAkToneGen::GetEnvelope(CAkToneGen *this)
{
  return this->m_fEnvCurGain;
}

// File Line: 560
// RVA: 0xAD2970
signed __int64 __fastcall CAkToneGen::StopLooping(CAkToneGen *this)
{
  unsigned int v1; // er8
  unsigned int v2; // edx
  signed __int64 result; // rax

  v1 = this->m_uIterNumSamples;
  v2 = this->m_uTotalOutSampCount % v1;
  this->m_bFinite = 1;
  this->m_iNumLoops = 1;
  this->m_uTotalNumSamples = v1;
  result = 1i64;
  this->m_uTotalOutSampCount = v2;
  return result;
}


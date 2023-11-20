// File Line: 29
// RVA: 0xAD9F10
AK::IAkPlugin *__fastcall CreateSoundSeedWoosh(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax
  AK::IAkPlugin *v2; // rbx

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 624ui64);
  v2 = result;
  if ( result )
  {
    result->vfptr = (AK::IAkPluginVtbl *)&CAkSoundSeedWoosh::`vftable;
    result[1].vfptr = 0i64;
    result[2].vfptr = 0i64;
    result[3].vfptr = 0i64;
    result[4].vfptr = 0i64;
    result[5].vfptr = 0i64;
    result[6].vfptr = 0i64;
    result[7].vfptr = 0i64;
    CAkSoundSeedWooshProcess::CAkSoundSeedWooshProcess((CAkSoundSeedWooshProcess *)&result[12]);
    v2[10].vfptr = 0i64;
    v2[11].vfptr = 0i64;
    result = v2;
  }
  return result;
}

// File Line: 39
// RVA: 0xAD9F80
void __fastcall CAkSoundSeedWoosh::CAkSoundSeedWoosh(CAkSoundSeedWoosh *this)
{
  CAkSoundSeedWoosh *v1; // rbx
  CAkSoundSeedWooshProcess *v2; // rcx

  v1 = this;
  v2 = &this->m_WooshProcess;
  *(_QWORD *)&v2[-1].m_NoiseGen.PurpleFilter.m_Memories.m_Memories.fFFwd1 = &CAkSoundSeedWoosh::`vftable;
  *(_QWORD *)&v2[-1].m_NoiseGen.PurpleFilter.m_Memories.m_Memories.fFFbk1 = 0i64;
  *(_QWORD *)&v2[-1].m_NoiseGen.m_NoiseColor = 0i64;
  *((_QWORD *)&v2[-1].m_NoiseGen.m_NoiseColor + 1) = 0i64;
  *(_QWORD *)&v2[-1].m_cDeflectors = 0i64;
  *(_QWORD *)&v2[-1].m_uLastPathPointIndex = 0i64;
  *(_QWORD *)&v2[-1].m_fPrevTimeElapsed = 0i64;
  *(_QWORD *)&v2[-1].m_fDistanceTraveled = 0i64;
  CAkSoundSeedWooshProcess::CAkSoundSeedWooshProcess(v2);
  *(_QWORD *)v1->m_uCurvePointIndex = 0i64;
  *(_QWORD *)&v1->m_uCurvePointIndex[2] = 0i64;
}

// File Line: 44
// RVA: 0xAD9FE0
void __fastcall CAkSoundSeedWoosh::~CAkSoundSeedWoosh(CAkSoundSeedWoosh *this)
{
  CAkSoundSeedWoosh *v1; // rbx
  CAkSoundSeedWooshProcess *v2; // rcx

  v1 = this;
  v2 = &this->m_WooshProcess;
  *(_QWORD *)&v2[-1].m_NoiseGen.PurpleFilter.m_Memories.m_Memories.fFFwd1 = &CAkSoundSeedWoosh::`vftable;
  CAkSoundSeedWooshProcess::~CAkSoundSeedWooshProcess(v2);
  v1->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 53
// RVA: 0xADA020
unsigned int __fastcall CAkSoundSeedWoosh::Init(CAkSoundSeedWoosh *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkSourcePluginContext *in_pSourceFXContext, AK::IAkPluginParam *in_pParams, AkAudioFormat *io_rFormat)
{
  CAkSoundSeedWoosh *v5; // rbx
  unsigned __int16 v6; // ax
  AkWooshParams *v7; // rdx
  CAkSoundSeedWooshParams *v8; // rcx
  unsigned int v9; // eax
  unsigned int result; // eax
  unsigned int v11; // esi
  float *v12; // rax
  CAkSoundSeedWooshParams *v13; // rax
  float *v14; // r10
  AkWooshDeflectorParams *v15; // rcx
  AkWooshPathPoint *v16; // r9
  DeflectorDSP *v17; // r8
  DeflectorInfo *v18; // rdx

  this->m_pSharedParams = (CAkSoundSeedWooshParams *)in_pParams;
  this->m_pAllocator = in_pAllocator;
  v5 = this;
  v6 = ((__int64 (__fastcall *)(AK::IAkSourcePluginContext *))in_pSourceFXContext->vfptr[1].__vecDelDtor)(in_pSourceFXContext);
  v7 = &v5->m_pSharedParams->m_Params;
  v5->m_uNumLoops = v6;
  v5->m_WooshProcess.m_uChangeMask = v7[1].uChannelMask;
  CAkSoundSeedWooshProcess::Setup(&v5->m_WooshProcess, v7, io_rFormat);
  v8 = v5->m_pSharedParams;
  v5->m_WooshProcess.m_uChangeMask &= 0xFFFFFFF7;
  v5->m_WooshProcess.m_fTotalPathDistance = v8->m_fTotalPathDistance;
  v9 = v8->m_cPathPoints;
  v5->m_WooshProcess.m_uChangeMask &= 0xFFFFFFFB;
  v5->m_WooshProcess.m_cPathPoints = v9;
  result = CAkSoundSeedWoosh::SetupDeflectors(v5);
  if ( result == 1 )
  {
    CAkSoundSeedWoosh::ComputeDuration(v5);
    result = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
               &v5->m_RandomizedSpeedCurve,
               v5->m_pSharedParams->m_Curves[0].m_pArrayGraphPoints,
               v5->m_pSharedParams->m_Curves[0].m_ulArraySize,
               v5->m_pSharedParams->m_Curves[0].m_eScaling);
    if ( result != 52 )
    {
      if ( CAkSoundSeedWoosh::ComputeRandomizedSpeed(v5) == 1 )
      {
        CAkSoundSeedWoosh::ComputeWooshSpeedAreaUnderCurve(v5);
        v11 = 16 * v5->m_WooshProcess.m_uOversamplingFactor;
        v12 = (float *)v5->m_pAllocator->vfptr->Malloc(v5->m_pAllocator, v11);
        v5->m_pfAutomationValues = v12;
        if ( v12 )
        {
          memset(v12, 0, v11);
          v13 = v5->m_pSharedParams;
          v14 = v5->m_pfAutomationValues;
          v15 = v13->m_pDeflectors;
          v16 = v13->m_pPath;
          v17 = v5->m_pDeflectorDSPInfo;
          v18 = v5->m_pDeflectorInfo;
          v5->m_WooshProcess.m_pParams = &v13->m_Params;
          v5->m_WooshProcess.m_pDeflectors = v15;
          v5->m_WooshProcess.m_pPath = v16;
          v5->m_WooshProcess.m_pDeflectorInfo = v18;
          v5->m_WooshProcess.m_pDeflectorDSPInfo = v17;
          v5->m_WooshProcess.m_pfAutomationValues = v14;
          v5->m_pSharedParams->m_uChangeMask = v5->m_WooshProcess.m_uChangeMask;
          result = 1;
        }
        else
        {
          result = 52;
        }
      }
      else
      {
        result = 2;
      }
    }
  }
  return result;
}

// File Line: 109
// RVA: 0xADA900
signed __int64 __fastcall CAkSoundSeedWoosh::SetupDeflectors(CAkSoundSeedWoosh *this)
{
  CAkSoundSeedWoosh *v1; // rbx
  unsigned int v2; // ecx
  size_t v3; // rsi
  size_t v4; // rdi
  DeflectorInfo *v5; // rax
  DeflectorDSP *v7; // rax

  v1 = this;
  v2 = this->m_pSharedParams->m_cDeflectors;
  v1->m_WooshProcess.m_cDeflectors = v2;
  if ( v2 )
  {
    v3 = 28 * v2;
    v4 = 112 * ((v2 + 3) >> 2);
    v5 = (DeflectorInfo *)v1->m_pAllocator->vfptr->Malloc(v1->m_pAllocator, (unsigned int)v3);
    v1->m_pDeflectorInfo = v5;
    if ( !v5 )
      return 52i64;
    memset(v5, 0, v3);
    v7 = (DeflectorDSP *)v1->m_pAllocator->vfptr->Malloc(v1->m_pAllocator, v4);
    v1->m_pDeflectorDSPInfo = v7;
    if ( !v7 )
      return 52i64;
    memset(v7, 0, v4);
    v1->m_WooshProcess.m_bInitGainRamps = 1;
    CAkSoundSeedWoosh::ComputeDeflectorRandomValues(v1);
  }
  v1->m_WooshProcess.m_uChangeMask &= 0xFFFFFFFC;
  return 1i64;
}

// File Line: 137
// RVA: 0xADA9C0
void __fastcall CAkSoundSeedWoosh::TermDeflectors(CAkSoundSeedWoosh *this)
{
  CAkSoundSeedWoosh *v1; // rbx

  v1 = this;
  if ( this->m_pDeflectorInfo )
  {
    ((void (*)(void))this->m_pAllocator->vfptr->Free)();
    v1->m_pDeflectorInfo = 0i64;
  }
  if ( v1->m_pDeflectorDSPInfo )
  {
    ((void (*)(void))v1->m_pAllocator->vfptr->Free)();
    v1->m_pDeflectorDSPInfo = 0i64;
  }
}

// File Line: 151
// RVA: 0xADA1B0
signed __int64 __fastcall CAkSoundSeedWoosh::Term(CAkSoundSeedWoosh *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkSoundSeedWoosh *v3; // rbx
  AkRTPCGraphPointBase<float> *v4; // rdx

  v2 = in_pAllocator;
  v3 = this;
  if ( this->m_pDeflectorInfo )
  {
    ((void (*)(void))this->m_pAllocator->vfptr->Free)();
    v3->m_pDeflectorInfo = 0i64;
  }
  if ( v3->m_pDeflectorDSPInfo )
  {
    ((void (*)(void))v3->m_pAllocator->vfptr->Free)();
    v3->m_pDeflectorDSPInfo = 0i64;
  }
  v4 = v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
  if ( v4 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v4);
    v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints = 0i64;
  }
  *(_QWORD *)&v3->m_RandomizedSpeedCurve.m_ulArraySize = 0i64;
  if ( v3->m_pfAutomationValues )
  {
    ((void (*)(void))v3->m_pAllocator->vfptr->Free)();
    v3->m_pfAutomationValues = 0i64;
  }
  v3->vfptr->__vecDelDtor((AK::IAkPlugin *)&v3->vfptr, 0);
  v2->vfptr->Free(v2, v3);
  return 1i64;
}

// File Line: 167
// RVA: 0xADA260
signed __int64 __fastcall CAkSoundSeedWoosh::Reset(CAkSoundSeedWoosh *this)
{
  *(_WORD *)&this->m_WooshProcess.m_bInitAdvancePosition = 1;
  this->m_WooshProcess.m_fTimeElapsed = 0.0;
  *(_QWORD *)&this->m_WooshProcess.m_fDistanceTraveled = 0i64;
  this->m_WooshProcess.m_uLastPathPointIndex = 0;
  *(_QWORD *)this->m_uCurvePointIndex = 0i64;
  *(_QWORD *)&this->m_uCurvePointIndex[2] = 0i64;
  this->m_uLoopCount = 0;
  return 1i64;
}

// File Line: 180
// RVA: 0xADA2A0
signed __int64 __fastcall CAkSoundSeedWoosh::GetPluginInfo(CAkSoundSeedWoosh *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 2;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 189
// RVA: 0xADA680
signed __int64 __fastcall CAkSoundSeedWoosh::TimeSkip(CAkSoundSeedWoosh *this, unsigned int *io_uFrames)
{
  CAkSoundSeedWoosh *v2; // rbx
  float v3; // xmm8_4
  float v4; // xmm9_4
  signed int v5; // eax
  signed int v6; // ebp
  float v7; // xmm7_4
  float v8; // xmm6_4
  unsigned int v9; // edi
  unsigned int *v10; // rsi
  CAkSoundSeedWooshParams *v11; // rdx
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v12; // rcx
  float v13; // xmm1_4
  float v14; // xmm8_4
  float v15; // xmm0_4
  unsigned int v16; // eax

  v2 = this;
  v3 = this->m_pSharedParams->m_Params.fPlaybackRate;
  v4 = this->m_WooshProcess.m_fSamplePeriod * (double)(signed int)*io_uFrames;
  if ( this->m_WooshProcess.m_bLoopAfterExecution )
  {
    *(_WORD *)&this->m_WooshProcess.m_bInitAdvancePosition = 1;
    *(_QWORD *)&this->m_WooshProcess.m_fDistanceTraveled = 0i64;
    this->m_WooshProcess.m_uLastPathPointIndex = 0;
  }
  if ( this->m_WooshProcess.m_cDeflectors > 0 )
  {
    v5 = this->m_WooshProcess.m_uOversamplingFactor;
    v6 = 0;
    v7 = this->m_fDuration / this->m_WooshProcess.m_fEffectiveDuration;
    v8 = (float)(v3 * v4) / (float)v5;
    if ( v5 )
    {
      do
      {
        v9 = 0;
        v10 = v2->m_uCurvePointIndex;
        do
        {
          v11 = v2->m_pSharedParams;
          if ( v11->m_Params.bAutomation[v9] )
          {
            if ( v9 )
              v12 = &v11->m_Curves[v9];
            else
              v12 = &v2->m_RandomizedSpeedCurve;
            v2->m_pfAutomationValues[v6 + v9 * v2->m_WooshProcess.m_uOversamplingFactor] = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                                                                                             v12,
                                                                                             (float)((float)((float)v6 * v8) + v2->m_WooshProcess.m_fTimeElapsed)
                                                                                           * v7,
                                                                                             *v10,
                                                                                             v10);
          }
          else
          {
            v2->m_pfAutomationValues[v6 + v9 * v2->m_WooshProcess.m_uOversamplingFactor] = 0.0;
          }
          ++v9;
          ++v10;
        }
        while ( v9 < 4 );
        ++v6;
      }
      while ( v6 < v2->m_WooshProcess.m_uOversamplingFactor );
    }
  }
  v13 = v2->m_WooshProcess.m_fEffectiveDuration;
  v14 = (float)(v3 * v4) + v2->m_WooshProcess.m_fTimeElapsed;
  v2->m_WooshProcess.m_fTimeElapsed = v14;
  if ( v14 >= v13 )
  {
    v15 = fmodf(v14, v13);
    v16 = v2->m_uNumLoops;
    ++v2->m_uLoopCount;
    v2->m_WooshProcess.m_fTimeElapsed = v15;
    if ( v16 && v2->m_uLoopCount >= v16 )
      return 17i64;
    v2->m_WooshProcess.m_bLoopAfterExecution = 1;
    CAkSoundSeedWoosh::ComputeDuration(v2);
    if ( CAkSoundSeedWoosh::ComputeRandomizedSpeed(v2) != 1 )
      return 2i64;
    CAkSoundSeedWoosh::ComputeWooshSpeedAreaUnderCurve(v2);
    *(_QWORD *)v2->m_uCurvePointIndex = 0i64;
    *(_QWORD *)&v2->m_uCurvePointIndex[2] = 0i64;
  }
  return 45i64;
}

// File Line: 257
// RVA: 0xADA2C0
void __fastcall CAkSoundSeedWoosh::Execute(CAkSoundSeedWoosh *this, AkAudioBuffer *io_pBufferOut)
{
  signed int v2; // ebp
  AkAudioBuffer *v3; // r14
  CAkSoundSeedWoosh *v4; // rbx
  unsigned int v5; // edi
  CAkSoundSeedWooshParams *v6; // rax
  float v7; // xmm8_4
  float v8; // xmm9_4
  signed int v9; // eax
  signed int v10; // ebp
  float v11; // xmm7_4
  float v12; // xmm6_4
  unsigned int v13; // edi
  unsigned int *v14; // rsi
  CAkSoundSeedWooshParams *v15; // rdx
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v16; // rcx
  __m128 v17; // xmm1
  signed int v18; // ecx
  float *v19; // rax
  float *v20; // rdi
  float v21; // xmm1_4
  float v22; // xmm8_4
  float v23; // xmm0_4
  unsigned int v24; // eax
  CAkSoundSeedWooshParams *v25; // rcx
  float v26; // xmm0_4
  int v27; // eax
  float v28; // xmm1_4
  CAkSoundSeedWooshParams *v29; // rax
  float v30; // xmm1_4
  float v31; // xmm1_4

  v2 = io_pBufferOut->uMaxFrames;
  io_pBufferOut->eState = 45;
  io_pBufferOut->uValidFrames = v2;
  v3 = io_pBufferOut;
  v4 = this;
  v5 = 0;
  if ( this->m_WooshProcess.m_uNumChannels )
  {
    do
      memset((char *)v3->pData + 4 * v5++ * (unsigned __int64)v3->uMaxFrames, 0, (unsigned int)(4 * v2));
    while ( v5 < v4->m_WooshProcess.m_uNumChannels );
  }
  v6 = v4->m_pSharedParams;
  v7 = v6->m_Params.fPlaybackRate;
  v8 = v4->m_WooshProcess.m_fSamplePeriod * (double)v2;
  v4->m_WooshProcess.m_uChangeMask = v6->m_uChangeMask;
  if ( v4->m_WooshProcess.m_bLoopAfterExecution )
  {
    *(_WORD *)&v4->m_WooshProcess.m_bInitAdvancePosition = 1;
    *(_QWORD *)&v4->m_WooshProcess.m_fDistanceTraveled = 0i64;
    v4->m_WooshProcess.m_uLastPathPointIndex = 0;
  }
  v4->m_pSharedParams->m_uChangeMask = 0;
  if ( v4->m_WooshProcess.m_cDeflectors > 0 )
  {
    v9 = v4->m_WooshProcess.m_uOversamplingFactor;
    v10 = 0;
    v11 = v4->m_fDuration / v4->m_WooshProcess.m_fEffectiveDuration;
    v12 = (float)(v7 * v8) / (float)v9;
    if ( v9 )
    {
      do
      {
        v13 = 0;
        v14 = v4->m_uCurvePointIndex;
        do
        {
          v15 = v4->m_pSharedParams;
          if ( v15->m_Params.bAutomation[v13] )
          {
            if ( v13 )
              v16 = &v15->m_Curves[v13];
            else
              v16 = &v4->m_RandomizedSpeedCurve;
            v4->m_pfAutomationValues[v10 + v13 * v4->m_WooshProcess.m_uOversamplingFactor] = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                                                                                               v16,
                                                                                               (float)((float)((float)v10 * v12) + v4->m_WooshProcess.m_fTimeElapsed)
                                                                                             * v11,
                                                                                               *v14,
                                                                                               v14);
          }
          else
          {
            v4->m_pfAutomationValues[v10 + v13 * v4->m_WooshProcess.m_uOversamplingFactor] = 0.0;
          }
          ++v13;
          ++v14;
        }
        while ( v13 < 4 );
        ++v10;
      }
      while ( v10 < v4->m_WooshProcess.m_uOversamplingFactor );
    }
    v17 = (__m128)COERCE_UNSIGNED_INT((float)v3->uValidFrames);
    v17.m128_f32[0] = v17.m128_f32[0] / (float)(signed int)v4->m_WooshProcess.m_uOversamplingFactor;
    v18 = (signed int)v17.m128_f32[0];
    if ( (signed int)v17.m128_f32[0] != 0x80000000 && (float)v18 != v17.m128_f32[0] )
      v17.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v17, v17)) & 1 ^ 1) + v18);
    v19 = (float *)v4->m_pAllocator->vfptr->Malloc(
                     v4->m_pAllocator,
                     20i64 * (((signed int)v17.m128_f32[0] + 3) & 0xFFFFFFFC));
    v20 = v19;
    if ( !v19 )
    {
LABEL_28:
      v3->eState = 2;
      return;
    }
    CAkSoundSeedWooshProcess::Process(&v4->m_WooshProcess, v3, v19);
    v4->m_pAllocator->vfptr->Free(v4->m_pAllocator, v20);
  }
  v21 = v4->m_WooshProcess.m_fEffectiveDuration;
  v22 = (float)(v7 * v8) + v4->m_WooshProcess.m_fTimeElapsed;
  v4->m_WooshProcess.m_fTimeElapsed = v22;
  if ( v22 < v21 )
    return;
  v23 = fmodf(v22, v21);
  v24 = v4->m_uNumLoops;
  ++v4->m_uLoopCount;
  v4->m_WooshProcess.m_fTimeElapsed = v23;
  if ( v24 && v4->m_uLoopCount >= v24 )
  {
    v3->eState = 17;
    return;
  }
  v25 = v4->m_pSharedParams;
  v4->m_WooshProcess.m_bLoopAfterExecution = 1;
  v4->m_fDuration = v25->m_Params.fDuration;
  v26 = v25->m_Params.fDurationRdm;
  v27 = 214013 * v4->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
  v4->m_WooshProcess.m_RandGenerator.m_uLCGState = v27;
  v28 = (float)v27;
  v29 = v4->m_pSharedParams;
  v30 = (float)((float)((float)(v28 * 2.3283064e-10) * 2.0) - 1.0) * v26;
  v4->m_fRandomDuration = v30;
  v31 = v30 + v29->m_Params.fDuration;
  v4->m_WooshProcess.m_fEffectiveDuration = v31;
  if ( v31 <= 0.1 )
    v31 = FLOAT_0_1;
  v4->m_WooshProcess.m_fEffectiveDuration = v31;
  if ( CAkSoundSeedWoosh::ComputeRandomizedSpeed(v4) != 1 )
    goto LABEL_28;
  CAkSoundSeedWoosh::ComputeWooshSpeedAreaUnderCurve(v4);
  *(_QWORD *)v4->m_uCurvePointIndex = 0i64;
  *(_QWORD *)&v4->m_uCurvePointIndex[2] = 0i64;
}

// File Line: 428
// RVA: 0xADA630
float __fastcall CAkSoundSeedWoosh::GetDuration(CAkSoundSeedWoosh *this)
{
  return (float)(this->m_WooshProcess.m_fEffectiveDuration * 1000.0) * (float)(signed int)this->m_uNumLoops;
}

// File Line: 433
// RVA: 0xADA660
signed __int64 __fastcall CAkSoundSeedWoosh::StopLooping(CAkSoundSeedWoosh *this)
{
  this->m_uNumLoops = 1;
  return 1i64;
}

// File Line: 439
// RVA: 0xADA8D0
void __fastcall CAkSoundSeedWoosh::ComputeDeflectorAllocationSizes(CAkSoundSeedWoosh *this, unsigned int *out_uInfoAllocSize, unsigned int *out_uDSPAllocSize)
{
  *out_uInfoAllocSize = 28 * this->m_WooshProcess.m_cDeflectors;
  *out_uDSPAllocSize = 112 * ((this->m_WooshProcess.m_cDeflectors + 3) >> 2);
}

// File Line: 483
// RVA: 0xADAA10
void __fastcall CAkSoundSeedWoosh::ComputeDeflectorRandomValues(CAkSoundSeedWoosh *this)
{
  unsigned int v1; // eax
  CAkSoundSeedWoosh *v2; // rbx
  __int64 v3; // rdi
  __int64 v4; // rsi
  float v5; // xmm1_4
  int v6; // eax
  float v7; // xmm1_4
  int v8; // eax
  float v9; // xmm2_4
  int v10; // eax

  v1 = this->m_WooshProcess.m_cDeflectors;
  v2 = this;
  if ( v1 )
  {
    v3 = 0i64;
    v4 = v1;
    do
    {
      v5 = v2->m_pSharedParams->m_Params.fRandomValue[1];
      v6 = 214013 * v2->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
      v2->m_WooshProcess.m_RandGenerator.m_uLCGState = v6;
      v2->m_pDeflectorInfo[v3].fRandomFrequency = (float)((float)((float)((float)v6 * 2.3283064e-10) * 2.0) - 1.0) * v5;
      v7 = v2->m_pSharedParams->m_Params.fRandomValue[2];
      v8 = 214013 * v2->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
      v2->m_WooshProcess.m_RandGenerator.m_uLCGState = v8;
      v2->m_pDeflectorInfo[v3].fRandomQFactor = (float)((float)((float)((float)v8 * 2.3283064e-10) * 2.0) - 1.0) * v7;
      v9 = v2->m_pSharedParams->m_Params.fRandomValue[3];
      v10 = 214013 * v2->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
      v2->m_WooshProcess.m_RandGenerator.m_uLCGState = v10;
      ++v3;
      *((float *)&v2->m_pDeflectorInfo[v3] - 1) = powf(
                                                    10.0,
                                                    (float)((float)((float)((float)((float)v10 * 2.3283064e-10) * 2.0)
                                                                  - 1.0)
                                                          * v9)
                                                  * 0.050000001);
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 494
// RVA: 0xADABB0
void __fastcall CAkSoundSeedWoosh::ComputeDuration(CAkSoundSeedWoosh *this)
{
  CAkSoundSeedWooshParams *v1; // rdx
  float v2; // xmm0_4
  signed int v3; // eax
  float v4; // xmm1_4
  CAkSoundSeedWooshParams *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm1_4

  v1 = this->m_pSharedParams;
  this->m_fDuration = v1->m_Params.fDuration;
  v2 = v1->m_Params.fDurationRdm;
  v3 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
  this->m_WooshProcess.m_RandGenerator.m_uLCGState = v3;
  v4 = (float)v3;
  v5 = this->m_pSharedParams;
  v6 = (float)((float)((float)(v4 * 2.3283064e-10) * 2.0) - 1.0) * v2;
  this->m_fRandomDuration = v6;
  v7 = v6 + v5->m_Params.fDuration;
  this->m_WooshProcess.m_fEffectiveDuration = v7;
  if ( v7 <= 0.1 )
    this->m_WooshProcess.m_fEffectiveDuration = FLOAT_0_1;
  else
    this->m_WooshProcess.m_fEffectiveDuration = v7;
}

// File Line: 502
// RVA: 0xADAC30
signed __int64 __fastcall CAkSoundSeedWoosh::ComputeRandomizedSpeed(CAkSoundSeedWoosh *this)
{
  CAkSoundSeedWooshParams *v1; // rdx
  float v2; // xmm7_4
  CAkSoundSeedWoosh *v3; // rbx
  float v4; // xmm11_4
  float v5; // xmm6_4
  unsigned int v7; // er8
  unsigned int v8; // er10
  unsigned int v9; // er11
  signed __int64 v10; // r9
  float v11; // xmm4_4
  float v12; // xmm5_4
  signed __int64 v13; // rdx
  __int64 v14; // rbp
  unsigned int v15; // eax
  __int64 v16; // rsi
  AkRTPCGraphPointBase<float> *v17; // rcx
  int v18; // eax
  float v19; // xmm2_4
  float v20; // xmm5_4
  int v21; // eax
  AkRTPCGraphPointBase<float> *v22; // rcx
  int v23; // eax
  float v24; // xmm3_4
  float v25; // xmm5_4
  int v26; // eax
  AkRTPCGraphPointBase<float> *v27; // rcx
  int v28; // eax
  float v29; // xmm2_4
  float v30; // xmm5_4
  int v31; // eax
  AkRTPCGraphPointBase<float> *v32; // rcx
  int v33; // eax
  int v34; // eax
  signed __int64 v35; // r9
  signed __int64 v36; // rdx
  __int64 v37; // r10
  AkRTPCGraphPointBase<float> *v38; // rcx
  int v39; // eax
  float v40; // xmm0_4
  float v41; // xmm2_4
  int v42; // eax
  AkRTPCGraphPointBase<float> *v43; // rcx
  unsigned int v44; // er9
  float v45; // xmm4_4
  signed __int64 v46; // r10
  int v47; // eax
  signed __int64 v48; // rcx
  unsigned int v49; // eax
  __int64 v50; // rdx
  signed __int64 v51; // rcx
  __int64 v52; // rdx
  unsigned int v53; // er10
  signed __int64 v54; // r11
  __int64 v55; // rdx
  unsigned int v56; // eax
  __int64 v57; // r9
  AkRTPCGraphPointBase<float> *v58; // rcx
  int v59; // eax
  AkRTPCGraphPointBase<float> *v60; // rcx
  int v61; // eax
  AkRTPCGraphPointBase<float> *v62; // rcx
  int v63; // eax
  AkRTPCGraphPointBase<float> *v64; // rcx
  int v65; // eax
  signed __int64 v66; // rdx
  __int64 v67; // r9
  AkRTPCGraphPointBase<float> *v68; // rcx
  int v69; // eax

  v1 = this->m_pSharedParams;
  v2 = 0.0;
  v3 = this;
  v4 = v1->m_Params.fRandomSpeedX;
  v5 = v1->m_Params.fRandomSpeedY;
  if ( v1->m_Params.bAutomation[0] && (v4 != 0.0 || v5 != 0.0) )
  {
    if ( (unsigned int)CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
                         &this->m_RandomizedSpeedCurve,
                         v1->m_Curves[0].m_pArrayGraphPoints,
                         v1->m_Curves[0].m_ulArraySize,
                         v1->m_Curves[0].m_eScaling) == 52 )
      return 2i64;
    v7 = v3->m_RandomizedSpeedCurve.m_ulArraySize;
    if ( v7 <= 2 || v4 == 0.0 )
    {
      v53 = 0;
      v54 = 0i64;
      if ( (signed int)v7 >= 4 )
      {
        v55 = 0i64;
        v56 = ((v7 - 4) >> 2) + 1;
        v57 = v56;
        v53 = 4 * v56;
        v54 = 4i64 * v56;
        do
        {
          v58 = v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          v55 += 4i64;
          v59 = 214013 * v3->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          v3->m_WooshProcess.m_RandGenerator.m_uLCGState = v59;
          *((float *)&v58[v55 - 3] - 2) = (float)((float)((float)((float)((float)v59 * 2.3283064e-10) * 2.0) - 1.0) * v5)
                                        + *((float *)&v58[v55 - 3] - 2);
          v60 = v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          v61 = 214013 * v3->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          v3->m_WooshProcess.m_RandGenerator.m_uLCGState = v61;
          *((float *)&v60[v55 - 2] - 2) = (float)((float)((float)((float)((float)v61 * 2.3283064e-10) * 2.0) - 1.0) * v5)
                                        + *((float *)&v60[v55 - 2] - 2);
          v62 = v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          v63 = 214013 * v3->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          v3->m_WooshProcess.m_RandGenerator.m_uLCGState = v63;
          *((float *)&v62[v55 - 1] - 2) = (float)((float)((float)((float)((float)v63 * 2.3283064e-10) * 2.0) - 1.0) * v5)
                                        + *((float *)&v62[v55 - 1] - 2);
          v64 = v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          v65 = 214013 * v3->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          v3->m_WooshProcess.m_RandGenerator.m_uLCGState = v65;
          *((float *)&v64[v55] - 2) = (float)((float)((float)((float)((float)v65 * 2.3283064e-10) * 2.0) - 1.0) * v5)
                                    + *((float *)&v64[v55] - 2);
          --v57;
        }
        while ( v57 );
      }
      if ( v53 < v7 )
      {
        v66 = v54;
        v67 = v7 - v53;
        do
        {
          v68 = v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          ++v66;
          v69 = 214013 * v3->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          v3->m_WooshProcess.m_RandGenerator.m_uLCGState = v69;
          *((float *)&v68[v66] - 2) = (float)((float)((float)((float)((float)v69 * 2.3283064e-10) * 2.0) - 1.0) * v5)
                                    + *((float *)&v68[v66] - 2);
          --v67;
        }
        while ( v67 );
      }
    }
    else
    {
      v8 = 0;
      v9 = v7 - 1;
      v10 = 0i64;
      v11 = v3->m_pSharedParams->m_Params.fDuration;
      v12 = 0.0;
      if ( (signed int)(v7 - 1) >= 4 )
      {
        v13 = 2i64;
        v14 = 0i64;
        v15 = ((v7 - 5) >> 2) + 1;
        v16 = v15;
        v8 = 4 * v15;
        v10 = 4i64 * v15;
        do
        {
          v17 = v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          v18 = 214013 * v3->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          v19 = v17[v13 - 1].From;
          v3->m_WooshProcess.m_RandGenerator.m_uLCGState = v18;
          v20 = v12
              + (float)((float)((float)((float)((float)((float)((float)((float)v18 * 2.3283064e-10) * 2.0) - 1.0) * v4)
                                      * (float)(v19 - v2))
                              * 0.99000001)
                      + (float)(v19 - v2));
          v17[v13 - 1].From = (float)((float)((float)((float)((float)((float)((float)((float)v18 * 2.3283064e-10) * 2.0)
                                                                    - 1.0)
                                                            * v4)
                                                    * (float)(v19 - v2))
                                            * 0.99000001)
                                    + (float)(v19 - v2))
                            + v17[v14].From;
          v21 = 214013 * v3->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          v3->m_WooshProcess.m_RandGenerator.m_uLCGState = v21;
          *((float *)&v17[v13] - 2) = (float)((float)((float)((float)((float)v21 * 2.3283064e-10) * 2.0) - 1.0) * v5)
                                    + *((float *)&v17[v13] - 2);
          v22 = v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          v23 = 214013 * v3->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          v24 = v22[v13].From;
          v3->m_WooshProcess.m_RandGenerator.m_uLCGState = v23;
          v25 = v20
              + (float)((float)((float)((float)((float)((float)((float)((float)v23 * 2.3283064e-10) * 2.0) - 1.0) * v4)
                                      * (float)(v24 - v19))
                              * 0.99000001)
                      + (float)(v24 - v19));
          v22[v13].From = (float)((float)((float)((float)((float)((float)((float)((float)v23 * 2.3283064e-10) * 2.0)
                                                                - 1.0)
                                                        * v4)
                                                * (float)(v24 - v19))
                                        * 0.99000001)
                                + (float)(v24 - v19))
                        + v22[v14 + 1].From;
          v26 = 214013 * v3->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          v3->m_WooshProcess.m_RandGenerator.m_uLCGState = v26;
          v22[v13].To = (float)((float)((float)((float)((float)v26 * 2.3283064e-10) * 2.0) - 1.0) * v5) + v22[v13].To;
          v27 = v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          v28 = 214013 * v3->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          v29 = v27[v13 + 1].From;
          v3->m_WooshProcess.m_RandGenerator.m_uLCGState = v28;
          v13 += 4i64;
          v14 += 4i64;
          v30 = v25
              + (float)((float)((float)((float)((float)((float)((float)((float)v28 * 2.3283064e-10) * 2.0) - 1.0) * v4)
                                      * (float)(v29 - v24))
                              * 0.99000001)
                      + (float)(v29 - v24));
          v27[v13 - 3].From = (float)((float)((float)((float)((float)((float)((float)((float)v28 * 2.3283064e-10) * 2.0)
                                                                    - 1.0)
                                                            * v4)
                                                    * (float)(v29 - v24))
                                            * 0.99000001)
                                    + (float)(v29 - v24))
                            + v27[v14 - 2].From;
          v31 = 214013 * v3->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          v3->m_WooshProcess.m_RandGenerator.m_uLCGState = v31;
          *((float *)&v27[v13 - 2] - 2) = (float)((float)((float)((float)((float)v31 * 2.3283064e-10) * 2.0) - 1.0) * v5)
                                        + *((float *)&v27[v13 - 2] - 2);
          v32 = v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          v33 = 214013 * v3->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          v2 = v32[v13 - 2].From;
          v3->m_WooshProcess.m_RandGenerator.m_uLCGState = v33;
          v12 = v30
              + (float)((float)((float)((float)((float)((float)((float)((float)v33 * 2.3283064e-10) * 2.0) - 1.0) * v4)
                                      * (float)(v2 - v29))
                              * 0.99000001)
                      + (float)(v2 - v29));
          v32[v13 - 2].From = (float)((float)((float)((float)((float)((float)((float)((float)v33 * 2.3283064e-10) * 2.0)
                                                                    - 1.0)
                                                            * v4)
                                                    * (float)(v2 - v29))
                                            * 0.99000001)
                                    + (float)(v2 - v29))
                            + v32[v14 - 1].From;
          v34 = 214013 * v3->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          v3->m_WooshProcess.m_RandGenerator.m_uLCGState = v34;
          *((float *)&v32[v13 - 1] - 2) = (float)((float)((float)((float)((float)v34 * 2.3283064e-10) * 2.0) - 1.0) * v5)
                                        + *((float *)&v32[v13 - 1] - 2);
          --v16;
        }
        while ( v16 );
      }
      if ( v8 < v9 )
      {
        v35 = v10;
        v36 = v8 + 1;
        v37 = v9 - v8;
        do
        {
          v38 = v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          ++v36;
          ++v35;
          v39 = 214013 * v3->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          v40 = v38[v36 - 1].From;
          v3->m_WooshProcess.m_RandGenerator.m_uLCGState = v39;
          v41 = v40 - v2;
          v2 = v40;
          v12 = v12
              + (float)((float)((float)((float)((float)((float)((float)((float)v39 * 2.3283064e-10) * 2.0) - 1.0) * v4)
                                      * v41)
                              * 0.99000001)
                      + v41);
          v38[v36 - 1].From = (float)((float)((float)((float)((float)((float)((float)((float)v39 * 2.3283064e-10) * 2.0)
                                                                    - 1.0)
                                                            * v4)
                                                    * v41)
                                            * 0.99000001)
                                    + v41)
                            + v38[v35 - 1].From;
          v42 = 214013 * v3->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          v3->m_WooshProcess.m_RandGenerator.m_uLCGState = v42;
          *((float *)&v38[v36] - 2) = (float)((float)((float)((float)((float)v42 * 2.3283064e-10) * 2.0) - 1.0) * v5)
                                    + *((float *)&v38[v36] - 2);
          --v37;
        }
        while ( v37 );
      }
      v43 = v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
      v44 = 1;
      v45 = v11 / v12;
      v46 = 1i64;
      v47 = 214013 * v3->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
      v3->m_WooshProcess.m_RandGenerator.m_uLCGState = v47;
      v43->To = (float)((float)((float)((float)((float)v47 * 2.3283064e-10) * 2.0) - 1.0) * v5) + v43->To;
      if ( v7 > 1 )
      {
        if ( (signed int)(v7 - 1) >= 4 )
        {
          v48 = 1i64;
          v49 = ((v7 - 5) >> 2) + 1;
          v50 = v49;
          v44 = 4 * v49 + 1;
          v46 = 4i64 * v49 + 1;
          do
          {
            v48 += 4i64;
            v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v48 - 4].From = v45
                                                                         * v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v48 - 4].From;
            v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v48 - 3].From = v45
                                                                         * v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v48 - 3].From;
            v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v48 - 2].From = v45
                                                                         * v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v48 - 2].From;
            v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v48 - 1].From = v45
                                                                         * v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v48 - 1].From;
            --v50;
          }
          while ( v50 );
        }
        if ( v44 < v7 )
        {
          v51 = v46;
          v52 = v7 - v44;
          do
          {
            ++v51;
            v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v51 - 1].From = v45
                                                                         * v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v51 - 1].From;
            --v52;
          }
          while ( v52 );
        }
      }
    }
  }
  return 1i64;
}

// File Line: 559
// RVA: 0xADB3F0
__int64 __fastcall CAkSoundSeedWoosh::ResetRandomizedSpeedCopy(CAkSoundSeedWoosh *this)
{
  int v1; // eax
  unsigned int v2; // ecx

  v1 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
         &this->m_RandomizedSpeedCurve,
         this->m_pSharedParams->m_Curves[0].m_pArrayGraphPoints,
         this->m_pSharedParams->m_Curves[0].m_ulArraySize,
         this->m_pSharedParams->m_Curves[0].m_eScaling);
  v2 = 52;
  if ( v1 != 52 )
    v2 = 1;
  return v2;
}

// File Line: 570
// RVA: 0xADB430
void __fastcall CAkSoundSeedWoosh::ComputeWooshSpeedAreaUnderCurve(CAkSoundSeedWoosh *this)
{
  CAkSoundSeedWooshParams *v1; // rax
  __int64 v2; // rdi
  CAkSoundSeedWoosh *v3; // rbx
  unsigned int v4; // eax
  unsigned int v5; // eax
  signed __int64 v6; // rsi
  __int64 v7; // rbp
  AkRTPCGraphPointBase<float> *v8; // rax
  AkCurveInterpolation v9; // ST28_4
  AkCurveInterpolation v10; // ST28_4
  float v11; // xmm0_4

  v1 = this->m_pSharedParams;
  v2 = 0i64;
  v3 = this;
  this->m_WooshProcess.m_fAreaUnderWooshCurve = 0.0;
  if ( v1->m_Params.bAutomation[0] )
  {
    v4 = this->m_RandomizedSpeedCurve.m_ulArraySize;
    if ( v4 >= 2 )
    {
      v5 = v4 - 1;
      if ( v5 )
      {
        v6 = 1i64;
        v7 = v5;
        do
        {
          v8 = v3->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          v9 = v8[v2].Interp;
          v10 = v8[v6].Interp;
          v11 = CAkSoundSeedWooshProcess::ComputeIntegral(v8[v2].From, v8[v2].To, v8[v6].From, v8[v6].To);
          ++v6;
          ++v2;
          v3->m_WooshProcess.m_fAreaUnderWooshCurve = v11 + v3->m_WooshProcess.m_fAreaUnderWooshCurve;
          --v7;
        }
        while ( v7 );
      }
    }
  }
}


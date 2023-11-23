// File Line: 29
// RVA: 0xAD9F10
AK::IAkPlugin *__fastcall CreateSoundSeedWoosh(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax
  AK::IAkPlugin *v2; // rbx

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 624i64);
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
    return v2;
  }
  return result;
}

// File Line: 39
// RVA: 0xAD9F80
void __fastcall CAkSoundSeedWoosh::CAkSoundSeedWoosh(CAkSoundSeedWoosh *this)
{
  CAkSoundSeedWooshProcess *p_m_WooshProcess; // rcx

  p_m_WooshProcess = &this->m_WooshProcess;
  *(_QWORD *)&p_m_WooshProcess[-1].m_NoiseGen.PurpleFilter.m_Memories.m_Memories.fFFwd1 = &CAkSoundSeedWoosh::`vftable;
  *(_QWORD *)&p_m_WooshProcess[-1].m_NoiseGen.PurpleFilter.m_Memories.m_Memories.fFFbk1 = 0i64;
  *(_QWORD *)&p_m_WooshProcess[-1].m_NoiseGen.m_NoiseColor = 0i64;
  *((_QWORD *)&p_m_WooshProcess[-1].m_NoiseGen.m_NoiseColor + 1) = 0i64;
  *(_QWORD *)&p_m_WooshProcess[-1].m_cDeflectors = 0i64;
  *(_QWORD *)&p_m_WooshProcess[-1].m_uLastPathPointIndex = 0i64;
  *(_QWORD *)&p_m_WooshProcess[-1].m_fPrevTimeElapsed = 0i64;
  *(_QWORD *)&p_m_WooshProcess[-1].m_fDistanceTraveled = 0i64;
  CAkSoundSeedWooshProcess::CAkSoundSeedWooshProcess(p_m_WooshProcess);
  *(_QWORD *)this->m_uCurvePointIndex = 0i64;
  *(_QWORD *)&this->m_uCurvePointIndex[2] = 0i64;
}

// File Line: 44
// RVA: 0xAD9FE0
void __fastcall CAkSoundSeedWoosh::~CAkSoundSeedWoosh(CAkSoundSeedWoosh *this)
{
  CAkSoundSeedWooshProcess *p_m_WooshProcess; // rcx

  p_m_WooshProcess = &this->m_WooshProcess;
  *(_QWORD *)&p_m_WooshProcess[-1].m_NoiseGen.PurpleFilter.m_Memories.m_Memories.fFFwd1 = &CAkSoundSeedWoosh::`vftable;
  CAkSoundSeedWooshProcess::~CAkSoundSeedWooshProcess(p_m_WooshProcess);
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 53
// RVA: 0xADA020
unsigned int __fastcall CAkSoundSeedWoosh::Init(
        CAkSoundSeedWoosh *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkSourcePluginContext *in_pSourceFXContext,
        CAkSoundSeedWooshParams *in_pParams,
        AkAudioFormat *io_rFormat)
{
  unsigned __int16 v6; // ax
  AkWooshParams *p_m_Params; // rdx
  CAkSoundSeedWooshParams *m_pSharedParams; // rcx
  unsigned int m_cPathPoints; // eax
  unsigned int result; // eax
  unsigned int v11; // esi
  float *v12; // rax
  CAkSoundSeedWooshParams *v13; // rax
  float *m_pfAutomationValues; // r10
  AkWooshDeflectorParams *m_pDeflectors; // rcx
  AkWooshPathPoint *m_pPath; // r9
  DeflectorDSP *m_pDeflectorDSPInfo; // r8
  DeflectorInfo *m_pDeflectorInfo; // rdx

  this->m_pSharedParams = in_pParams;
  this->m_pAllocator = in_pAllocator;
  v6 = ((__int64 (__fastcall *)(AK::IAkSourcePluginContext *))in_pSourceFXContext->vfptr[1].__vecDelDtor)(in_pSourceFXContext);
  p_m_Params = &this->m_pSharedParams->m_Params;
  this->m_uNumLoops = v6;
  this->m_WooshProcess.m_uChangeMask = p_m_Params[1].uChannelMask;
  CAkSoundSeedWooshProcess::Setup(&this->m_WooshProcess, p_m_Params, io_rFormat);
  m_pSharedParams = this->m_pSharedParams;
  this->m_WooshProcess.m_uChangeMask &= ~8u;
  this->m_WooshProcess.m_fTotalPathDistance = m_pSharedParams->m_fTotalPathDistance;
  m_cPathPoints = m_pSharedParams->m_cPathPoints;
  this->m_WooshProcess.m_uChangeMask &= ~4u;
  this->m_WooshProcess.m_cPathPoints = m_cPathPoints;
  result = CAkSoundSeedWoosh::SetupDeflectors(this);
  if ( result == 1 )
  {
    CAkSoundSeedWoosh::ComputeDuration(this);
    result = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
               &this->m_RandomizedSpeedCurve,
               this->m_pSharedParams->m_Curves[0].m_pArrayGraphPoints,
               this->m_pSharedParams->m_Curves[0].m_ulArraySize,
               this->m_pSharedParams->m_Curves[0].m_eScaling);
    if ( result != 52 )
    {
      if ( CAkSoundSeedWoosh::ComputeRandomizedSpeed(this) == AK_Success )
      {
        CAkSoundSeedWoosh::ComputeWooshSpeedAreaUnderCurve(this);
        v11 = 16 * this->m_WooshProcess.m_uOversamplingFactor;
        v12 = (float *)this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, v11);
        this->m_pfAutomationValues = v12;
        if ( v12 )
        {
          memset(v12, 0, v11);
          v13 = this->m_pSharedParams;
          m_pfAutomationValues = this->m_pfAutomationValues;
          m_pDeflectors = v13->m_pDeflectors;
          m_pPath = v13->m_pPath;
          m_pDeflectorDSPInfo = this->m_pDeflectorDSPInfo;
          m_pDeflectorInfo = this->m_pDeflectorInfo;
          this->m_WooshProcess.m_pParams = &v13->m_Params;
          this->m_WooshProcess.m_pDeflectors = m_pDeflectors;
          this->m_WooshProcess.m_pPath = m_pPath;
          this->m_WooshProcess.m_pDeflectorInfo = m_pDeflectorInfo;
          this->m_WooshProcess.m_pDeflectorDSPInfo = m_pDeflectorDSPInfo;
          this->m_WooshProcess.m_pfAutomationValues = m_pfAutomationValues;
          this->m_pSharedParams->m_uChangeMask = this->m_WooshProcess.m_uChangeMask;
          return 1;
        }
        else
        {
          return 52;
        }
      }
      else
      {
        return 2;
      }
    }
  }
  return result;
}

// File Line: 109
// RVA: 0xADA900
__int64 __fastcall CAkSoundSeedWoosh::SetupDeflectors(CAkSoundSeedWoosh *this)
{
  unsigned int m_cDeflectors; // ecx
  size_t v3; // rsi
  unsigned __int64 v4; // rdi
  DeflectorInfo *v5; // rax
  DeflectorDSP *v7; // rax

  m_cDeflectors = this->m_pSharedParams->m_cDeflectors;
  this->m_WooshProcess.m_cDeflectors = m_cDeflectors;
  if ( m_cDeflectors )
  {
    v3 = 28 * m_cDeflectors;
    v4 = 112 * ((m_cDeflectors + 3) >> 2);
    v5 = (DeflectorInfo *)this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, (unsigned int)v3);
    this->m_pDeflectorInfo = v5;
    if ( !v5 )
      return 52i64;
    memset(v5, 0, v3);
    v7 = (DeflectorDSP *)this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, v4);
    this->m_pDeflectorDSPInfo = v7;
    if ( !v7 )
      return 52i64;
    memset(v7, 0, v4);
    this->m_WooshProcess.m_bInitGainRamps = 1;
    CAkSoundSeedWoosh::ComputeDeflectorRandomValues(this);
  }
  this->m_WooshProcess.m_uChangeMask &= 0xFFFFFFFC;
  return 1i64;
}

// File Line: 137
// RVA: 0xADA9C0
void __fastcall CAkSoundSeedWoosh::TermDeflectors(CAkSoundSeedWoosh *this)
{
  if ( this->m_pDeflectorInfo )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Free)(this->m_pAllocator);
    this->m_pDeflectorInfo = 0i64;
  }
  if ( this->m_pDeflectorDSPInfo )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Free)(this->m_pAllocator);
    this->m_pDeflectorDSPInfo = 0i64;
  }
}

// File Line: 151
// RVA: 0xADA1B0
__int64 __fastcall CAkSoundSeedWoosh::Term(CAkSoundSeedWoosh *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AkRTPCGraphPointBase<float> *m_pArrayGraphPoints; // rdx

  if ( this->m_pDeflectorInfo )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Free)(this->m_pAllocator);
    this->m_pDeflectorInfo = 0i64;
  }
  if ( this->m_pDeflectorDSPInfo )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Free)(this->m_pAllocator);
    this->m_pDeflectorDSPInfo = 0i64;
  }
  m_pArrayGraphPoints = this->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
  if ( m_pArrayGraphPoints )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pArrayGraphPoints);
    this->m_RandomizedSpeedCurve.m_pArrayGraphPoints = 0i64;
  }
  *(_QWORD *)&this->m_RandomizedSpeedCurve.m_ulArraySize = 0i64;
  if ( this->m_pfAutomationValues )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Free)(this->m_pAllocator);
    this->m_pfAutomationValues = 0i64;
  }
  this->vfptr->__vecDelDtor(this, 0i64);
  in_pAllocator->vfptr->Free(in_pAllocator, this);
  return 1i64;
}

// File Line: 167
// RVA: 0xADA260
__int64 __fastcall CAkSoundSeedWoosh::Reset(CAkSoundSeedWoosh *this)
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
__int64 __fastcall CAkSoundSeedWoosh::GetPluginInfo(CAkSoundSeedWoosh *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeSource;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 189
// RVA: 0xADA680
__int64 __fastcall CAkSoundSeedWoosh::TimeSkip(CAkSoundSeedWoosh *this, unsigned int *io_uFrames)
{
  float fPlaybackRate; // xmm8_4
  float v4; // xmm9_4
  signed int m_uOversamplingFactor; // eax
  unsigned int v6; // ebp
  float v7; // xmm7_4
  float v8; // xmm6_4
  unsigned int v9; // edi
  unsigned int *m_uCurvePointIndex; // rsi
  CAkSoundSeedWooshParams *m_pSharedParams; // rdx
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *p_m_RandomizedSpeedCurve; // rcx
  float m_fEffectiveDuration; // xmm1_4
  float v14; // xmm8_4
  float v15; // xmm0_4
  unsigned int m_uNumLoops; // eax

  fPlaybackRate = this->m_pSharedParams->m_Params.fPlaybackRate;
  v4 = this->m_WooshProcess.m_fSamplePeriod * (double)(int)*io_uFrames;
  if ( this->m_WooshProcess.m_bLoopAfterExecution )
  {
    *(_WORD *)&this->m_WooshProcess.m_bInitAdvancePosition = 1;
    *(_QWORD *)&this->m_WooshProcess.m_fDistanceTraveled = 0i64;
    this->m_WooshProcess.m_uLastPathPointIndex = 0;
  }
  if ( this->m_WooshProcess.m_cDeflectors )
  {
    m_uOversamplingFactor = this->m_WooshProcess.m_uOversamplingFactor;
    v6 = 0;
    v7 = this->m_fDuration / this->m_WooshProcess.m_fEffectiveDuration;
    v8 = (float)(fPlaybackRate * v4) / (float)m_uOversamplingFactor;
    if ( m_uOversamplingFactor )
    {
      do
      {
        v9 = 0;
        m_uCurvePointIndex = this->m_uCurvePointIndex;
        do
        {
          m_pSharedParams = this->m_pSharedParams;
          if ( m_pSharedParams->m_Params.bAutomation[v9] )
          {
            if ( v9 )
              p_m_RandomizedSpeedCurve = &m_pSharedParams->m_Curves[v9];
            else
              p_m_RandomizedSpeedCurve = &this->m_RandomizedSpeedCurve;
            this->m_pfAutomationValues[v6 + v9 * this->m_WooshProcess.m_uOversamplingFactor] = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                                                                                                 p_m_RandomizedSpeedCurve,
                                                                                                 (float)((float)((float)(int)v6 * v8) + this->m_WooshProcess.m_fTimeElapsed)
                                                                                               * v7,
                                                                                                 *m_uCurvePointIndex,
                                                                                                 m_uCurvePointIndex);
          }
          else
          {
            this->m_pfAutomationValues[v6 + v9 * this->m_WooshProcess.m_uOversamplingFactor] = 0.0;
          }
          ++v9;
          ++m_uCurvePointIndex;
        }
        while ( v9 < 4 );
        ++v6;
      }
      while ( v6 < this->m_WooshProcess.m_uOversamplingFactor );
    }
  }
  m_fEffectiveDuration = this->m_WooshProcess.m_fEffectiveDuration;
  v14 = (float)(fPlaybackRate * v4) + this->m_WooshProcess.m_fTimeElapsed;
  this->m_WooshProcess.m_fTimeElapsed = v14;
  if ( v14 >= m_fEffectiveDuration )
  {
    v15 = fmodf(v14, m_fEffectiveDuration);
    m_uNumLoops = this->m_uNumLoops;
    ++this->m_uLoopCount;
    this->m_WooshProcess.m_fTimeElapsed = v15;
    if ( m_uNumLoops && this->m_uLoopCount >= m_uNumLoops )
      return 17i64;
    this->m_WooshProcess.m_bLoopAfterExecution = 1;
    CAkSoundSeedWoosh::ComputeDuration(this);
    if ( CAkSoundSeedWoosh::ComputeRandomizedSpeed(this) != AK_Success )
      return 2i64;
    CAkSoundSeedWoosh::ComputeWooshSpeedAreaUnderCurve(this);
    *(_QWORD *)this->m_uCurvePointIndex = 0i64;
    *(_QWORD *)&this->m_uCurvePointIndex[2] = 0i64;
  }
  return 45i64;
}

// File Line: 257
// RVA: 0xADA2C0
void __fastcall CAkSoundSeedWoosh::Execute(CAkSoundSeedWoosh *this, AkAudioBuffer *io_pBufferOut)
{
  int uMaxFrames; // ebp
  unsigned int i; // edi
  CAkSoundSeedWooshParams *m_pSharedParams; // rax
  float fPlaybackRate; // xmm8_4
  float v8; // xmm9_4
  signed int m_uOversamplingFactor; // eax
  unsigned int v10; // ebp
  float v11; // xmm7_4
  float v12; // xmm6_4
  unsigned int v13; // edi
  unsigned int *m_uCurvePointIndex; // rsi
  CAkSoundSeedWooshParams *v15; // rdx
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *p_m_RandomizedSpeedCurve; // rcx
  __m128 v17; // xmm1
  int v18; // ecx
  float *v19; // rax
  float *v20; // rdi
  float m_fEffectiveDuration; // xmm1_4
  float v22; // xmm8_4
  float v23; // xmm0_4
  unsigned int m_uNumLoops; // eax
  CAkSoundSeedWooshParams *v25; // rcx
  float fDurationRdm; // xmm0_4
  signed int v27; // eax
  float v28; // xmm1_4
  CAkSoundSeedWooshParams *v29; // rax
  float v30; // xmm1_4
  float v31; // xmm1_4

  uMaxFrames = io_pBufferOut->uMaxFrames;
  io_pBufferOut->eState = AK_DataReady;
  io_pBufferOut->uValidFrames = uMaxFrames;
  for ( i = 0; i < this->m_WooshProcess.m_uNumChannels; ++i )
    memset(
      (char *)io_pBufferOut->pData + 4 * i * (unsigned __int64)io_pBufferOut->uMaxFrames,
      0,
      (unsigned int)(4 * uMaxFrames));
  m_pSharedParams = this->m_pSharedParams;
  fPlaybackRate = m_pSharedParams->m_Params.fPlaybackRate;
  v8 = this->m_WooshProcess.m_fSamplePeriod * (double)uMaxFrames;
  this->m_WooshProcess.m_uChangeMask = m_pSharedParams->m_uChangeMask;
  if ( this->m_WooshProcess.m_bLoopAfterExecution )
  {
    *(_WORD *)&this->m_WooshProcess.m_bInitAdvancePosition = 1;
    *(_QWORD *)&this->m_WooshProcess.m_fDistanceTraveled = 0i64;
    this->m_WooshProcess.m_uLastPathPointIndex = 0;
  }
  this->m_pSharedParams->m_uChangeMask = 0;
  if ( this->m_WooshProcess.m_cDeflectors )
  {
    m_uOversamplingFactor = this->m_WooshProcess.m_uOversamplingFactor;
    v10 = 0;
    v11 = this->m_fDuration / this->m_WooshProcess.m_fEffectiveDuration;
    v12 = (float)(fPlaybackRate * v8) / (float)m_uOversamplingFactor;
    if ( m_uOversamplingFactor )
    {
      do
      {
        v13 = 0;
        m_uCurvePointIndex = this->m_uCurvePointIndex;
        do
        {
          v15 = this->m_pSharedParams;
          if ( v15->m_Params.bAutomation[v13] )
          {
            if ( v13 )
              p_m_RandomizedSpeedCurve = &v15->m_Curves[v13];
            else
              p_m_RandomizedSpeedCurve = &this->m_RandomizedSpeedCurve;
            this->m_pfAutomationValues[v10 + v13 * this->m_WooshProcess.m_uOversamplingFactor] = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                                                                                                   p_m_RandomizedSpeedCurve,
                                                                                                   (float)((float)((float)(int)v10 * v12) + this->m_WooshProcess.m_fTimeElapsed)
                                                                                                 * v11,
                                                                                                   *m_uCurvePointIndex,
                                                                                                   m_uCurvePointIndex);
          }
          else
          {
            this->m_pfAutomationValues[v10 + v13 * this->m_WooshProcess.m_uOversamplingFactor] = 0.0;
          }
          ++v13;
          ++m_uCurvePointIndex;
        }
        while ( v13 < 4 );
        ++v10;
      }
      while ( v10 < this->m_WooshProcess.m_uOversamplingFactor );
    }
    v17 = (__m128)COERCE_UNSIGNED_INT((float)io_pBufferOut->uValidFrames);
    v17.m128_f32[0] = v17.m128_f32[0] / (float)(int)this->m_WooshProcess.m_uOversamplingFactor;
    v18 = (int)v17.m128_f32[0];
    if ( (int)v17.m128_f32[0] != 0x80000000 && (float)v18 != v17.m128_f32[0] )
      v17.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v17, v17)) & 1) + v18);
    v19 = (float *)this->m_pAllocator->vfptr->Malloc(
                     this->m_pAllocator,
                     20i64 * (((int)v17.m128_f32[0] + 3) & 0xFFFFFFFC));
    v20 = v19;
    if ( !v19 )
    {
LABEL_28:
      io_pBufferOut->eState = AK_Fail;
      return;
    }
    CAkSoundSeedWooshProcess::Process(&this->m_WooshProcess, io_pBufferOut, v19);
    this->m_pAllocator->vfptr->Free(this->m_pAllocator, v20);
  }
  m_fEffectiveDuration = this->m_WooshProcess.m_fEffectiveDuration;
  v22 = (float)(fPlaybackRate * v8) + this->m_WooshProcess.m_fTimeElapsed;
  this->m_WooshProcess.m_fTimeElapsed = v22;
  if ( v22 < m_fEffectiveDuration )
    return;
  v23 = fmodf(v22, m_fEffectiveDuration);
  m_uNumLoops = this->m_uNumLoops;
  ++this->m_uLoopCount;
  this->m_WooshProcess.m_fTimeElapsed = v23;
  if ( m_uNumLoops && this->m_uLoopCount >= m_uNumLoops )
  {
    io_pBufferOut->eState = AK_NoMoreData;
    return;
  }
  v25 = this->m_pSharedParams;
  this->m_WooshProcess.m_bLoopAfterExecution = 1;
  this->m_fDuration = v25->m_Params.fDuration;
  fDurationRdm = v25->m_Params.fDurationRdm;
  v27 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
  this->m_WooshProcess.m_RandGenerator.m_uLCGState = v27;
  v28 = (float)v27;
  v29 = this->m_pSharedParams;
  v30 = (float)((float)((float)(v28 * 2.3283064e-10) * 2.0) - 1.0) * fDurationRdm;
  this->m_fRandomDuration = v30;
  v31 = v30 + v29->m_Params.fDuration;
  this->m_WooshProcess.m_fEffectiveDuration = v31;
  if ( v31 <= 0.1 )
    v31 = FLOAT_0_1;
  this->m_WooshProcess.m_fEffectiveDuration = v31;
  if ( CAkSoundSeedWoosh::ComputeRandomizedSpeed(this) != AK_Success )
    goto LABEL_28;
  CAkSoundSeedWoosh::ComputeWooshSpeedAreaUnderCurve(this);
  *(_QWORD *)this->m_uCurvePointIndex = 0i64;
  *(_QWORD *)&this->m_uCurvePointIndex[2] = 0i64;
}

// File Line: 428
// RVA: 0xADA630
float __fastcall CAkSoundSeedWoosh::GetDuration(CAkSoundSeedWoosh *this)
{
  return (float)(this->m_WooshProcess.m_fEffectiveDuration * 1000.0) * (float)(int)this->m_uNumLoops;
}

// File Line: 433
// RVA: 0xADA660
__int64 __fastcall CAkSoundSeedWoosh::StopLooping(CAkSoundSeedWoosh *this)
{
  this->m_uNumLoops = 1;
  return 1i64;
}

// File Line: 439
// RVA: 0xADA8D0
void __fastcall CAkSoundSeedWoosh::ComputeDeflectorAllocationSizes(
        CAkSoundSeedWoosh *this,
        unsigned int *out_uInfoAllocSize,
        unsigned int *out_uDSPAllocSize)
{
  *out_uInfoAllocSize = 28 * this->m_WooshProcess.m_cDeflectors;
  *out_uDSPAllocSize = 112 * ((this->m_WooshProcess.m_cDeflectors + 3) >> 2);
}

// File Line: 483
// RVA: 0xADAA10
void __fastcall CAkSoundSeedWoosh::ComputeDeflectorRandomValues(CAkSoundSeedWoosh *this)
{
  unsigned int m_cDeflectors; // eax
  __int64 v3; // rdi
  __int64 v4; // rsi
  float v5; // xmm1_4
  signed int v6; // eax
  float v7; // xmm1_4
  signed int v8; // eax
  float v9; // xmm2_4
  signed int v10; // eax

  m_cDeflectors = this->m_WooshProcess.m_cDeflectors;
  if ( m_cDeflectors )
  {
    v3 = 0i64;
    v4 = m_cDeflectors;
    do
    {
      v5 = this->m_pSharedParams->m_Params.fRandomValue[1];
      v6 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
      this->m_WooshProcess.m_RandGenerator.m_uLCGState = v6;
      this->m_pDeflectorInfo[v3].fRandomFrequency = (float)((float)((float)((float)v6 * 2.3283064e-10) * 2.0) - 1.0)
                                                  * v5;
      v7 = this->m_pSharedParams->m_Params.fRandomValue[2];
      v8 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
      this->m_WooshProcess.m_RandGenerator.m_uLCGState = v8;
      this->m_pDeflectorInfo[v3].fRandomQFactor = (float)((float)((float)((float)v8 * 2.3283064e-10) * 2.0) - 1.0) * v7;
      v9 = this->m_pSharedParams->m_Params.fRandomValue[3];
      v10 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
      this->m_WooshProcess.m_RandGenerator.m_uLCGState = v10;
      this->m_pDeflectorInfo[v3++].fRandomGain = powf(
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
  CAkSoundSeedWooshParams *m_pSharedParams; // rdx
  float fDurationRdm; // xmm0_4
  signed int v3; // eax
  float v4; // xmm1_4
  CAkSoundSeedWooshParams *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm1_4

  m_pSharedParams = this->m_pSharedParams;
  this->m_fDuration = m_pSharedParams->m_Params.fDuration;
  fDurationRdm = m_pSharedParams->m_Params.fDurationRdm;
  v3 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
  this->m_WooshProcess.m_RandGenerator.m_uLCGState = v3;
  v4 = (float)v3;
  v5 = this->m_pSharedParams;
  v6 = (float)((float)((float)(v4 * 2.3283064e-10) * 2.0) - 1.0) * fDurationRdm;
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
__int64 __fastcall CAkSoundSeedWoosh::ComputeRandomizedSpeed(CAkSoundSeedWoosh *this)
{
  CAkSoundSeedWooshParams *m_pSharedParams; // rdx
  float v2; // xmm7_4
  float fRandomSpeedX; // xmm11_4
  float fRandomSpeedY; // xmm6_4
  unsigned int m_ulArraySize; // r8d
  unsigned int v8; // r10d
  unsigned int v9; // r11d
  __int64 v10; // r9
  float fDuration; // xmm4_4
  float v12; // xmm5_4
  __int64 v13; // rdx
  __int64 v14; // rbp
  unsigned int v15; // eax
  __int64 v16; // rsi
  AkRTPCGraphPointBase<float> *v17; // rcx
  signed int v18; // eax
  float From; // xmm2_4
  float v20; // xmm5_4
  signed int v21; // eax
  AkRTPCGraphPointBase<float> *v22; // rcx
  signed int v23; // eax
  float v24; // xmm3_4
  float v25; // xmm5_4
  signed int v26; // eax
  AkRTPCGraphPointBase<float> *v27; // rcx
  signed int v28; // eax
  float v29; // xmm2_4
  float v30; // xmm5_4
  signed int v31; // eax
  AkRTPCGraphPointBase<float> *v32; // rcx
  signed int v33; // eax
  signed int v34; // eax
  __int64 v35; // r9
  __int64 v36; // rdx
  __int64 v37; // r10
  AkRTPCGraphPointBase<float> *v38; // rcx
  signed int v39; // eax
  float v40; // xmm0_4
  float v41; // xmm2_4
  signed int v42; // eax
  AkRTPCGraphPointBase<float> *v43; // rcx
  unsigned int v44; // r9d
  float v45; // xmm4_4
  __int64 v46; // r10
  signed int v47; // eax
  __int64 v48; // rcx
  unsigned int v49; // eax
  __int64 v50; // rdx
  __int64 v51; // rcx
  __int64 v52; // rdx
  unsigned int v53; // r10d
  __int64 v54; // r11
  __int64 v55; // rdx
  unsigned int v56; // eax
  __int64 v57; // r9
  AkRTPCGraphPointBase<float> *m_pArrayGraphPoints; // rcx
  signed int v59; // eax
  AkRTPCGraphPointBase<float> *v60; // rcx
  signed int v61; // eax
  AkRTPCGraphPointBase<float> *v62; // rcx
  signed int v63; // eax
  AkRTPCGraphPointBase<float> *v64; // rcx
  signed int v65; // eax
  __int64 v66; // rdx
  __int64 v67; // r9
  AkRTPCGraphPointBase<float> *v68; // rcx
  signed int v69; // eax

  m_pSharedParams = this->m_pSharedParams;
  v2 = 0.0;
  fRandomSpeedX = m_pSharedParams->m_Params.fRandomSpeedX;
  fRandomSpeedY = m_pSharedParams->m_Params.fRandomSpeedY;
  if ( m_pSharedParams->m_Params.bAutomation[0] && (fRandomSpeedX != 0.0 || fRandomSpeedY != 0.0) )
  {
    if ( (unsigned int)CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
                         &this->m_RandomizedSpeedCurve,
                         m_pSharedParams->m_Curves[0].m_pArrayGraphPoints,
                         m_pSharedParams->m_Curves[0].m_ulArraySize,
                         m_pSharedParams->m_Curves[0].m_eScaling) == 52 )
      return 2i64;
    m_ulArraySize = this->m_RandomizedSpeedCurve.m_ulArraySize;
    if ( m_ulArraySize <= 2 || fRandomSpeedX == 0.0 )
    {
      v53 = 0;
      v54 = 0i64;
      if ( (int)m_ulArraySize >= 4 )
      {
        v55 = 0i64;
        v56 = ((m_ulArraySize - 4) >> 2) + 1;
        v57 = v56;
        v53 = 4 * v56;
        v54 = 4i64 * v56;
        do
        {
          m_pArrayGraphPoints = this->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          v55 += 4i64;
          v59 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          this->m_WooshProcess.m_RandGenerator.m_uLCGState = v59;
          *((float *)&m_pArrayGraphPoints[v55 - 3] - 2) = (float)((float)((float)((float)((float)v59 * 2.3283064e-10)
                                                                                * 2.0)
                                                                        - 1.0)
                                                                * fRandomSpeedY)
                                                        + *((float *)&m_pArrayGraphPoints[v55 - 3] - 2);
          v60 = this->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          v61 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          this->m_WooshProcess.m_RandGenerator.m_uLCGState = v61;
          *((float *)&v60[v55 - 2] - 2) = (float)((float)((float)((float)((float)v61 * 2.3283064e-10) * 2.0) - 1.0)
                                                * fRandomSpeedY)
                                        + *((float *)&v60[v55 - 2] - 2);
          v62 = this->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          v63 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          this->m_WooshProcess.m_RandGenerator.m_uLCGState = v63;
          *((float *)&v62[v55 - 1] - 2) = (float)((float)((float)((float)((float)v63 * 2.3283064e-10) * 2.0) - 1.0)
                                                * fRandomSpeedY)
                                        + *((float *)&v62[v55 - 1] - 2);
          v64 = this->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          v65 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          this->m_WooshProcess.m_RandGenerator.m_uLCGState = v65;
          v64[v55 - 1].To = (float)((float)((float)((float)((float)v65 * 2.3283064e-10) * 2.0) - 1.0) * fRandomSpeedY)
                          + v64[v55 - 1].To;
          --v57;
        }
        while ( v57 );
      }
      if ( v53 < m_ulArraySize )
      {
        v66 = v54;
        v67 = m_ulArraySize - v53;
        do
        {
          v68 = this->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          ++v66;
          v69 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          this->m_WooshProcess.m_RandGenerator.m_uLCGState = v69;
          v68[v66 - 1].To = (float)((float)((float)((float)((float)v69 * 2.3283064e-10) * 2.0) - 1.0) * fRandomSpeedY)
                          + v68[v66 - 1].To;
          --v67;
        }
        while ( v67 );
      }
    }
    else
    {
      v8 = 0;
      v9 = m_ulArraySize - 1;
      v10 = 0i64;
      fDuration = this->m_pSharedParams->m_Params.fDuration;
      v12 = 0.0;
      if ( (int)(m_ulArraySize - 1) >= 4 )
      {
        v13 = 2i64;
        v14 = 0i64;
        v15 = ((m_ulArraySize - 5) >> 2) + 1;
        v16 = v15;
        v8 = 4 * v15;
        v10 = 4i64 * v15;
        do
        {
          v17 = this->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          v18 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          From = v17[v13 - 1].From;
          this->m_WooshProcess.m_RandGenerator.m_uLCGState = v18;
          v20 = v12
              + (float)((float)((float)((float)((float)((float)((float)((float)v18 * 2.3283064e-10) * 2.0) - 1.0)
                                              * fRandomSpeedX)
                                      * (float)(From - v2))
                              * 0.99000001)
                      + (float)(From - v2));
          v17[v13 - 1].From = (float)((float)((float)((float)((float)((float)((float)((float)v18 * 2.3283064e-10) * 2.0)
                                                                    - 1.0)
                                                            * fRandomSpeedX)
                                                    * (float)(From - v2))
                                            * 0.99000001)
                                    + (float)(From - v2))
                            + v17[v14].From;
          v21 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          this->m_WooshProcess.m_RandGenerator.m_uLCGState = v21;
          v17[v13 - 1].To = (float)((float)((float)((float)((float)v21 * 2.3283064e-10) * 2.0) - 1.0) * fRandomSpeedY)
                          + v17[v13 - 1].To;
          v22 = this->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          v23 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          v24 = v22[v13].From;
          this->m_WooshProcess.m_RandGenerator.m_uLCGState = v23;
          v25 = v20
              + (float)((float)((float)((float)((float)((float)((float)((float)v23 * 2.3283064e-10) * 2.0) - 1.0)
                                              * fRandomSpeedX)
                                      * (float)(v24 - From))
                              * 0.99000001)
                      + (float)(v24 - From));
          v22[v13].From = (float)((float)((float)((float)((float)((float)((float)((float)v23 * 2.3283064e-10) * 2.0)
                                                                - 1.0)
                                                        * fRandomSpeedX)
                                                * (float)(v24 - From))
                                        * 0.99000001)
                                + (float)(v24 - From))
                        + v22[v14 + 1].From;
          v26 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          this->m_WooshProcess.m_RandGenerator.m_uLCGState = v26;
          v22[v13].To = (float)((float)((float)((float)((float)v26 * 2.3283064e-10) * 2.0) - 1.0) * fRandomSpeedY)
                      + v22[v13].To;
          v27 = this->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          v28 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          v29 = v27[v13 + 1].From;
          this->m_WooshProcess.m_RandGenerator.m_uLCGState = v28;
          v13 += 4i64;
          v14 += 4i64;
          v30 = v25
              + (float)((float)((float)((float)((float)((float)((float)((float)v28 * 2.3283064e-10) * 2.0) - 1.0)
                                              * fRandomSpeedX)
                                      * (float)(v29 - v24))
                              * 0.99000001)
                      + (float)(v29 - v24));
          v27[v13 - 3].From = (float)((float)((float)((float)((float)((float)((float)((float)v28 * 2.3283064e-10) * 2.0)
                                                                    - 1.0)
                                                            * fRandomSpeedX)
                                                    * (float)(v29 - v24))
                                            * 0.99000001)
                                    + (float)(v29 - v24))
                            + v27[v14 - 2].From;
          v31 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          this->m_WooshProcess.m_RandGenerator.m_uLCGState = v31;
          *((float *)&v27[v13 - 2] - 2) = (float)((float)((float)((float)((float)v31 * 2.3283064e-10) * 2.0) - 1.0)
                                                * fRandomSpeedY)
                                        + *((float *)&v27[v13 - 2] - 2);
          v32 = this->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          v33 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          v2 = v32[v13 - 2].From;
          this->m_WooshProcess.m_RandGenerator.m_uLCGState = v33;
          v12 = v30
              + (float)((float)((float)((float)((float)((float)((float)((float)v33 * 2.3283064e-10) * 2.0) - 1.0)
                                              * fRandomSpeedX)
                                      * (float)(v2 - v29))
                              * 0.99000001)
                      + (float)(v2 - v29));
          v32[v13 - 2].From = (float)((float)((float)((float)((float)((float)((float)((float)v33 * 2.3283064e-10) * 2.0)
                                                                    - 1.0)
                                                            * fRandomSpeedX)
                                                    * (float)(v2 - v29))
                                            * 0.99000001)
                                    + (float)(v2 - v29))
                            + v32[v14 - 1].From;
          v34 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          this->m_WooshProcess.m_RandGenerator.m_uLCGState = v34;
          *((float *)&v32[v13 - 1] - 2) = (float)((float)((float)((float)((float)v34 * 2.3283064e-10) * 2.0) - 1.0)
                                                * fRandomSpeedY)
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
          v38 = this->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
          ++v36;
          ++v35;
          v39 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          v40 = v38[v36 - 1].From;
          this->m_WooshProcess.m_RandGenerator.m_uLCGState = v39;
          v41 = v40 - v2;
          v2 = v40;
          v12 = v12
              + (float)((float)((float)((float)((float)((float)((float)((float)v39 * 2.3283064e-10) * 2.0) - 1.0)
                                              * fRandomSpeedX)
                                      * v41)
                              * 0.99000001)
                      + v41);
          v38[v36 - 1].From = (float)((float)((float)((float)((float)((float)((float)((float)v39 * 2.3283064e-10) * 2.0)
                                                                    - 1.0)
                                                            * fRandomSpeedX)
                                                    * v41)
                                            * 0.99000001)
                                    + v41)
                            + v38[v35 - 1].From;
          v42 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
          this->m_WooshProcess.m_RandGenerator.m_uLCGState = v42;
          v38[v36 - 1].To = (float)((float)((float)((float)((float)v42 * 2.3283064e-10) * 2.0) - 1.0) * fRandomSpeedY)
                          + v38[v36 - 1].To;
          --v37;
        }
        while ( v37 );
      }
      v43 = this->m_RandomizedSpeedCurve.m_pArrayGraphPoints;
      v44 = 1;
      v45 = fDuration / v12;
      v46 = 1i64;
      v47 = 214013 * this->m_WooshProcess.m_RandGenerator.m_uLCGState + 2531011;
      this->m_WooshProcess.m_RandGenerator.m_uLCGState = v47;
      v43->To = (float)((float)((float)((float)((float)v47 * 2.3283064e-10) * 2.0) - 1.0) * fRandomSpeedY) + v43->To;
      if ( (int)(m_ulArraySize - 1) >= 4 )
      {
        v48 = 1i64;
        v49 = ((m_ulArraySize - 5) >> 2) + 1;
        v50 = v49;
        v44 = 4 * v49 + 1;
        v46 = 4i64 * v49 + 1;
        do
        {
          v48 += 4i64;
          this->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v48 - 4].From = v45
                                                                         * this->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v48 - 4].From;
          this->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v48 - 3].From = v45
                                                                         * this->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v48 - 3].From;
          this->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v48 - 2].From = v45
                                                                         * this->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v48 - 2].From;
          this->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v48 - 1].From = v45
                                                                         * this->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v48 - 1].From;
          --v50;
        }
        while ( v50 );
      }
      if ( v44 < m_ulArraySize )
      {
        v51 = v46;
        v52 = m_ulArraySize - v44;
        do
        {
          ++v51;
          this->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v51 - 1].From = v45
                                                                         * this->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v51 - 1].From;
          --v52;
        }
        while ( v52 );
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
    return 1;
  return v2;
}

// File Line: 570
// RVA: 0xADB430
void __fastcall CAkSoundSeedWoosh::ComputeWooshSpeedAreaUnderCurve(CAkSoundSeedWoosh *this)
{
  CAkSoundSeedWooshParams *m_pSharedParams; // rax
  __int64 v2; // rdi
  unsigned int m_ulArraySize; // eax
  unsigned int v5; // eax
  __int64 v6; // rsi
  __int64 v7; // rbp
  float v8; // xmm0_4

  m_pSharedParams = this->m_pSharedParams;
  v2 = 0i64;
  this->m_WooshProcess.m_fAreaUnderWooshCurve = 0.0;
  if ( m_pSharedParams->m_Params.bAutomation[0] )
  {
    m_ulArraySize = this->m_RandomizedSpeedCurve.m_ulArraySize;
    if ( m_ulArraySize >= 2 )
    {
      v5 = m_ulArraySize - 1;
      if ( v5 )
      {
        v6 = 1i64;
        v7 = v5;
        do
        {
          v8 = CAkSoundSeedWooshProcess::ComputeIntegral(
                 this->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v2].From,
                 this->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v2].To,
                 this->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v6].From,
                 this->m_RandomizedSpeedCurve.m_pArrayGraphPoints[v6].To);
          ++v6;
          ++v2;
          this->m_WooshProcess.m_fAreaUnderWooshCurve = v8 + this->m_WooshProcess.m_fAreaUnderWooshCurve;
          --v7;
        }
        while ( v7 );
      }
    }
  }
}


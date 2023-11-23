// File Line: 29
// RVA: 0xAD5340
void __fastcall CreateSoundSeedWind(AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkSoundSeedWind *v1; // rax

  v1 = (CAkSoundSeedWind *)in_pAllocator->vfptr->Malloc(in_pAllocator, 352i64);
  if ( v1 )
    CAkSoundSeedWind::CAkSoundSeedWind(v1);
}

// File Line: 38
// RVA: 0xAD5370
void __fastcall CAkSoundSeedWind::CAkSoundSeedWind(CAkSoundSeedWind *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&CAkSoundSeedWind::`vftable;
  this->m_pSharedParams = 0i64;
  this->m_pAllocator = 0i64;
  this->m_pDeflectorInfo = 0i64;
  this->m_pDeflectorDSPInfo = 0i64;
  CAkSoundSeedWindProcess::CAkSoundSeedWindProcess(&this->m_WindProcess);
  this->m_VelocityDelayLine.uDelayLineLength = 0;
  this->m_VelocityDelayLine.pfDelay = 0i64;
  this->m_VelocityDelayLine.uCurOffset = 0;
  CAkGustManager::CAkGustManager(&this->m_VelocityDelayLine.m_GustManager);
  *(_QWORD *)this->m_uCurvePointIndex = 0i64;
  *(_QWORD *)&this->m_uCurvePointIndex[2] = 0i64;
  *(_QWORD *)&this->m_uCurvePointIndex[4] = 0i64;
  this->m_uCurvePointIndex[6] = 0;
}

// File Line: 43
// RVA: 0xAD53F0
void __fastcall CAkSoundSeedWind::~CAkSoundSeedWind(CAkSoundSeedWind *this)
{
  CAkSoundSeedWindProcess *p_m_WindProcess; // rcx

  p_m_WindProcess = &this->m_WindProcess;
  *(_QWORD *)&p_m_WindProcess[-1].m_NoiseGen.m_DCFilter.m_fFbk1 = &CAkSoundSeedWind::`vftable;
  CAkSoundSeedWindProcess::~CAkSoundSeedWindProcess(p_m_WindProcess);
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 52
// RVA: 0xAD5430
AKRESULT __fastcall CAkSoundSeedWind::Init(
        CAkSoundSeedWind *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkSourcePluginContext *in_pSourceFXContext,
        CAkSoundSeedWindParams *in_pParams,
        AkAudioFormat *io_rFormat)
{
  AK::IAkSourcePluginContext *v6; // rbx
  AKRESULT result; // eax

  this->m_pSharedParams = in_pParams;
  this->m_pAllocator = in_pAllocator;
  v6 = in_pSourceFXContext;
  this->m_uNumLoops = ((unsigned __int16 (__fastcall *)(AK::IAkSourcePluginContext *))in_pSourceFXContext->vfptr[1].__vecDelDtor)(in_pSourceFXContext);
  LODWORD(v6) = (*(unsigned __int16 (__fastcall **)(AK::IAkSourcePluginContext *))&v6->vfptr->gap8[8])(v6);
  CAkSoundSeedWindProcess::Setup(&this->m_WindProcess, &this->m_pSharedParams->m_Params, io_rFormat);
  this->m_fBufferTime = (float)(int)v6 / (float)(int)this->m_WindProcess.m_uSampleRate;
  result = CAkSoundSeedWind::SetupDeflectors(this);
  if ( result == AK_Success )
  {
    CAkSoundSeedWind::ComputeDuration(this);
    result = CAkSoundSeedWind::InitVelocityLine(this, in_pAllocator);
    this->m_pSharedParams->m_uChangeMask &= ~0x20u;
  }
  return result;
}

// File Line: 88
// RVA: 0xAD5A30
__int64 __fastcall CAkSoundSeedWind::SetupDeflectors(CAkSoundSeedWind *this)
{
  CAkSoundSeedWindParams *m_pSharedParams; // rax
  unsigned int m_cDeflectors; // ecx
  size_t v4; // rsi
  unsigned __int64 v5; // rdi
  DeflectorInfo *v6; // rax
  void *v8; // rax
  CAkSoundSeedWindParams *v9; // rax
  void *m_pDeflectorDSPInfo; // r9
  DeflectorInfo *m_pDeflectorInfo; // r8
  bool v12; // cc
  void *v13; // r8
  DeflectorInfo *v14; // rdx

  m_pSharedParams = this->m_pSharedParams;
  m_cDeflectors = m_pSharedParams->m_cDeflectors;
  this->m_WindProcess.m_cDeflectors = m_cDeflectors;
  if ( m_cDeflectors )
  {
    v4 = 32 * m_cDeflectors;
    v5 = this->m_WindProcess.m_uDSPInfoSize * ((m_cDeflectors + 3) >> 2);
    v6 = (DeflectorInfo *)((__int64 (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Malloc)(this->m_pAllocator);
    this->m_pDeflectorInfo = v6;
    if ( !v6 )
      return 52i64;
    memset(v6, 0, v4);
    v8 = this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, v5);
    this->m_pDeflectorDSPInfo = v8;
    if ( !v8 )
      return 52i64;
    memset(v8, 0, v5);
    v9 = this->m_pSharedParams;
    m_pDeflectorDSPInfo = this->m_pDeflectorDSPInfo;
    m_pDeflectorInfo = this->m_pDeflectorInfo;
    this->m_WindProcess.m_pDeflectors = v9->m_pDeflectors;
    this->m_WindProcess.m_pDeflectorInfo = m_pDeflectorInfo;
    this->m_WindProcess.m_pParams = &v9->m_Params;
    this->m_WindProcess.m_pDeflectorDSPInfo = m_pDeflectorDSPInfo;
    v12 = this->m_WindProcess.m_uNumChannels <= 1;
    this->m_WindProcess.m_bFirstExecution = 1;
    if ( !v12 )
      CAkSoundSeedWindProcess::InitSpatialization(&this->m_WindProcess);
    CAkSoundSeedWind::ComputeDeflectorRandomValues(this);
  }
  else
  {
    v13 = this->m_pDeflectorDSPInfo;
    v14 = this->m_pDeflectorInfo;
    this->m_WindProcess.m_pDeflectors = m_pSharedParams->m_pDeflectors;
    this->m_WindProcess.m_pDeflectorInfo = v14;
    this->m_WindProcess.m_pDeflectorDSPInfo = v13;
    this->m_WindProcess.m_pParams = &m_pSharedParams->m_Params;
  }
  this->m_pSharedParams->m_uChangeMask &= ~1u;
  this->m_pSharedParams->m_uChangeMask &= ~4u;
  return 1i64;
}

// File Line: 129
// RVA: 0xAD5B70
void __fastcall CAkSoundSeedWind::TermDeflectors(CAkSoundSeedWind *this)
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

// File Line: 143
// RVA: 0xAD5EB0
AKRESULT __fastcall CAkSoundSeedWind::InitVelocityLine(CAkSoundSeedWind *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkSoundSeedWindParams *m_pSharedParams; // r8
  __m128 fMaxDistance_low; // xmm2
  int v6; // ecx
  float v7; // xmm6_4
  float v8; // xmm0_4
  CAkSoundSeedWindParams *v9; // rcx
  float v10; // xmm8_4
  float v11; // xmm0_4
  CAkSoundSeedWindParams *v12; // rcx
  float v13; // xmm7_4

  m_pSharedParams = this->m_pSharedParams;
  fMaxDistance_low = (__m128)LODWORD(m_pSharedParams->m_Params.fMaxDistance);
  fMaxDistance_low.m128_f32[0] = (float)(fMaxDistance_low.m128_f32[0] * 2.0) / (float)(this->m_fBufferTime * 2.0);
  v6 = (int)fMaxDistance_low.m128_f32[0];
  if ( (int)fMaxDistance_low.m128_f32[0] != 0x80000000 && (float)v6 != fMaxDistance_low.m128_f32[0] )
    fMaxDistance_low.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(fMaxDistance_low, fMaxDistance_low)) & 1)
                                         + v6);
  v7 = 0.0;
  if ( m_pSharedParams->m_Params.bAutomation[0] )
    v8 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
           m_pSharedParams->m_Curves,
           0.0,
           this->m_uCurvePointIndex[0],
           this->m_uCurvePointIndex);
  else
    v8 = 0.0;
  CAkSoundSeedWindProcess::ComputeEffectiveAverageVelocity(&this->m_WindProcess, v8);
  v9 = this->m_pSharedParams;
  v10 = this->m_WindProcess.m_fEffectiveParamValue[0];
  if ( v9->m_Params.bAutomation[2] )
    v11 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
            &v9->m_Curves[2],
            0.0,
            this->m_uCurvePointIndex[2],
            &this->m_uCurvePointIndex[2]);
  else
    v11 = 0.0;
  CAkSoundSeedWindProcess::ComputeEffectiveVariability(&this->m_WindProcess, v11);
  v12 = this->m_pSharedParams;
  v13 = this->m_WindProcess.m_fEffectiveParamValue[2];
  if ( v12->m_Params.bAutomation[3] )
    v7 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
           &v12->m_Curves[3],
           0.0,
           this->m_uCurvePointIndex[3],
           &this->m_uCurvePointIndex[3]);
  CAkSoundSeedWindProcess::ComputeEffectiveGustiness(&this->m_WindProcess, v7);
  return CAkVelocityDelayLine::Init(
           &this->m_VelocityDelayLine,
           v10,
           v13,
           this->m_WindProcess.m_fEffectiveParamValue[3],
           this->m_fBufferTime,
           in_pAllocator,
           (int)fMaxDistance_low.m128_f32[0],
           2.0);
}

// File Line: 161
// RVA: 0xAD54F0
__int64 __fastcall CAkSoundSeedWind::Term(CAkSoundSeedWind *this, AK::IAkPluginMemAlloc *in_pAllocator)
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
  CAkVelocityDelayLine::Term(&this->m_VelocityDelayLine, in_pAllocator);
  this->vfptr->__vecDelDtor(this, 0i64);
  in_pAllocator->vfptr->Free(in_pAllocator, this);
  return 1i64;
}

// File Line: 169
// RVA: 0xAD5580
__int64 __fastcall CAkSoundSeedWind::Reset(CAkSoundSeedWind *this)
{
  this->m_WindProcess.m_bFirstExecution = 1;
  this->m_fTimeElapsed = 0.0;
  this->m_uLoopCount = 0;
  *(_QWORD *)this->m_uCurvePointIndex = 0i64;
  *(_QWORD *)&this->m_uCurvePointIndex[2] = 0i64;
  *(_QWORD *)&this->m_uCurvePointIndex[4] = 0i64;
  this->m_uCurvePointIndex[6] = 0;
  return 1i64;
}

// File Line: 178
// RVA: 0xAD55B0
__int64 __fastcall CAkSoundSeedWind::GetPluginInfo(CAkSoundSeedWind *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeSource;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 186
// RVA: 0xAD5DE0
float __fastcall CAkSoundSeedWind::GetInitialEffectiveParam(CAkSoundSeedWind *this, unsigned int in_ParameterName)
{
  CAkSoundSeedWindParams *m_pSharedParams; // rcx
  __int64 v4; // rdi
  __int64 v5; // rsi
  float v6; // xmm0_4
  int v7; // edi

  m_pSharedParams = this->m_pSharedParams;
  v4 = in_ParameterName;
  v5 = in_ParameterName;
  if ( m_pSharedParams->m_Params.bAutomation[in_ParameterName] )
    v6 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
           &m_pSharedParams->m_Curves[in_ParameterName],
           0.0,
           this->m_uCurvePointIndex[in_ParameterName],
           &this->m_uCurvePointIndex[in_ParameterName]);
  else
    v6 = 0.0;
  if ( (_DWORD)v4 )
  {
    v7 = v4 - 2;
    if ( v7 )
    {
      if ( v7 == 1 )
      {
        CAkSoundSeedWindProcess::ComputeEffectiveGustiness(&this->m_WindProcess, v6);
        return this->m_WindProcess.m_fEffectiveParamValue[v5];
      }
    }
    else
    {
      CAkSoundSeedWindProcess::ComputeEffectiveVariability(&this->m_WindProcess, v6);
    }
    return this->m_WindProcess.m_fEffectiveParamValue[v5];
  }
  else
  {
    CAkSoundSeedWindProcess::ComputeEffectiveAverageVelocity(&this->m_WindProcess, v6);
    return this->m_WindProcess.m_fEffectiveParamValue[v4];
  }
}

// File Line: 210
// RVA: 0xAD58A0
__int64 __fastcall CAkSoundSeedWind::TimeSkip(CAkSoundSeedWind *this, unsigned int *io_uFrames)
{
  int v2; // r15d
  __int64 v4; // rsi
  __int64 v5; // rbp
  float *m_fAutomationValues; // rdi
  float v7; // xmm6_4
  __int64 v8; // r14
  CAkSoundSeedWindParams *m_pSharedParams; // rax
  float v10; // xmm0_4
  float m_fEffectiveDuration; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  unsigned int m_uNumLoops; // eax

  v2 = *io_uFrames;
  if ( this->m_WindProcess.m_cDeflectors )
  {
    v4 = 0i64;
    v5 = 0i64;
    m_fAutomationValues = this->m_WindProcess.m_fAutomationValues;
    v7 = this->m_fDuration / this->m_fEffectiveDuration;
    v8 = 7i64;
    do
    {
      m_pSharedParams = this->m_pSharedParams;
      if ( m_pSharedParams->m_Params.bAutomation[v4] )
        *m_fAutomationValues = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                                 &m_pSharedParams->m_Curves[v5],
                                 v7 * this->m_fTimeElapsed,
                                 *((_DWORD *)m_fAutomationValues - 17),
                                 (unsigned int *)m_fAutomationValues - 17);
      else
        *m_fAutomationValues = 0.0;
      ++v4;
      ++v5;
      ++m_fAutomationValues;
      --v8;
    }
    while ( v8 );
  }
  v10 = (double)v2 / (double)(int)this->m_WindProcess.m_uSampleRate;
  m_fEffectiveDuration = this->m_fEffectiveDuration;
  v12 = (float)(v10 * this->m_pSharedParams->m_Params.fPlaybackRate) + this->m_fTimeElapsed;
  this->m_fTimeElapsed = v12;
  if ( v12 >= m_fEffectiveDuration )
  {
    v13 = fmodf(v12, m_fEffectiveDuration);
    ++this->m_uLoopCount;
    this->m_fTimeElapsed = v13;
    *(_QWORD *)this->m_uCurvePointIndex = 0i64;
    *(_QWORD *)&this->m_uCurvePointIndex[2] = 0i64;
    *(_QWORD *)&this->m_uCurvePointIndex[4] = 0i64;
    this->m_uCurvePointIndex[6] = 0;
    m_uNumLoops = this->m_uNumLoops;
    if ( m_uNumLoops && this->m_uLoopCount >= m_uNumLoops )
      return 17i64;
    CAkSoundSeedWind::ComputeDuration(this);
  }
  return 45i64;
}

// File Line: 266
// RVA: 0xAD55D0
void __fastcall CAkSoundSeedWind::Execute(CAkSoundSeedWind *this, AkAudioBuffer *io_pBufferOut)
{
  int uMaxFrames; // r13d
  unsigned int v3; // edi
  __int64 v6; // rbp
  float *m_fAutomationValues; // rdi
  float v8; // xmm6_4
  __int64 v9; // r14
  __int64 v10; // r15
  CAkSoundSeedWindParams *m_pSharedParams; // rax
  float *v12; // rax
  float *v13; // rdi
  float v14; // xmm0_4
  float m_fEffectiveDuration; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  unsigned int m_uNumLoops; // eax
  CAkSoundSeedWindParams *v19; // rcx
  float fDurationRdm; // xmm0_4
  signed int v21; // eax
  float v22; // xmm1_4
  CAkSoundSeedWindParams *v23; // rax
  float v24; // xmm1_4
  float v25; // xmm1_4

  uMaxFrames = io_pBufferOut->uMaxFrames;
  v3 = 0;
  io_pBufferOut->eState = AK_DataReady;
  for ( io_pBufferOut->uValidFrames = uMaxFrames; v3 < this->m_WindProcess.m_uNumChannels; ++v3 )
    memset(
      (char *)io_pBufferOut->pData + 4 * v3 * (unsigned __int64)io_pBufferOut->uMaxFrames,
      0,
      (unsigned int)(4 * uMaxFrames));
  if ( this->m_WindProcess.m_cDeflectors )
  {
    v6 = 0i64;
    m_fAutomationValues = this->m_WindProcess.m_fAutomationValues;
    v8 = this->m_fDuration / this->m_fEffectiveDuration;
    v9 = 0i64;
    v10 = 7i64;
    do
    {
      m_pSharedParams = this->m_pSharedParams;
      if ( m_pSharedParams->m_Params.bAutomation[v6] )
        *m_fAutomationValues = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                                 &m_pSharedParams->m_Curves[v9],
                                 v8 * this->m_fTimeElapsed,
                                 *((_DWORD *)m_fAutomationValues - 17),
                                 (unsigned int *)m_fAutomationValues - 17);
      else
        *m_fAutomationValues = 0.0;
      ++v6;
      ++v9;
      ++m_fAutomationValues;
      --v10;
    }
    while ( v10 );
    CAkSoundSeedWindProcess::Prepare(
      &this->m_WindProcess,
      uMaxFrames,
      &this->m_VelocityDelayLine,
      this->m_pSharedParams->m_uChangeMask);
    v12 = (float *)this->m_pAllocator->vfptr->Malloc(
                     this->m_pAllocator,
                     4i64 * ((this->m_WindProcess.m_uNumChannels << 12) + 1024));
    v13 = v12;
    if ( !v12 )
    {
      io_pBufferOut->eState = AK_Fail;
      return;
    }
    CAkSoundSeedWindProcess::Process(&this->m_WindProcess, io_pBufferOut, v12);
    this->m_pAllocator->vfptr->Free(this->m_pAllocator, v13);
  }
  v14 = (double)uMaxFrames / (double)(int)this->m_WindProcess.m_uSampleRate;
  m_fEffectiveDuration = this->m_fEffectiveDuration;
  v16 = (float)(v14 * this->m_pSharedParams->m_Params.fPlaybackRate) + this->m_fTimeElapsed;
  this->m_fTimeElapsed = v16;
  if ( v16 >= m_fEffectiveDuration )
  {
    v17 = fmodf(v16, m_fEffectiveDuration);
    ++this->m_uLoopCount;
    this->m_fTimeElapsed = v17;
    *(_QWORD *)this->m_uCurvePointIndex = 0i64;
    *(_QWORD *)&this->m_uCurvePointIndex[2] = 0i64;
    *(_QWORD *)&this->m_uCurvePointIndex[4] = 0i64;
    this->m_uCurvePointIndex[6] = 0;
    m_uNumLoops = this->m_uNumLoops;
    if ( m_uNumLoops && this->m_uLoopCount >= m_uNumLoops )
    {
      io_pBufferOut->eState = AK_NoMoreData;
    }
    else
    {
      v19 = this->m_pSharedParams;
      this->m_fDuration = v19->m_Params.fDuration;
      fDurationRdm = v19->m_Params.fDurationRdm;
      v21 = 214013 * this->m_WindProcess.m_RandGenerator.m_uLCGState + 2531011;
      this->m_WindProcess.m_RandGenerator.m_uLCGState = v21;
      v22 = (float)v21;
      v23 = this->m_pSharedParams;
      v24 = (float)((float)((float)(v22 * 2.3283064e-10) * 2.0) - 1.0) * fDurationRdm;
      this->m_fRandomDuration = v24;
      v25 = v24 + v23->m_Params.fDuration;
      this->m_fEffectiveDuration = v25;
      if ( v25 <= 0.1 )
        v25 = FLOAT_0_1;
      this->m_fEffectiveDuration = v25;
      v23->m_uChangeMask &= ~8u;
    }
  }
  this->m_pSharedParams->m_uChangeMask = 0;
}

// File Line: 409
// RVA: 0xAD5850
float __fastcall CAkSoundSeedWind::GetDuration(CAkSoundSeedWind *this)
{
  return (float)(this->m_fEffectiveDuration * 1000.0) * (float)(int)this->m_uNumLoops;
}

// File Line: 414
// RVA: 0xAD5880
__int64 __fastcall CAkSoundSeedWind::StopLooping(CAkSoundSeedWind *this)
{
  this->m_uNumLoops = 1;
  return 1i64;
}

// File Line: 420
// RVA: 0xAD5A00
void __fastcall CAkSoundSeedWind::ComputeDeflectorAllocationSizes(
        CAkSoundSeedWind *this,
        unsigned int *out_uInfoAllocSize,
        unsigned int *out_uDSPAllocSize)
{
  *out_uInfoAllocSize = 32 * this->m_WindProcess.m_cDeflectors;
  *out_uDSPAllocSize = ((this->m_WindProcess.m_cDeflectors + 3) >> 2) * this->m_WindProcess.m_uDSPInfoSize;
}

// File Line: 466
// RVA: 0xAD5BC0
void __fastcall CAkSoundSeedWind::ComputeDeflectorRandomValues(CAkSoundSeedWind *this)
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

  m_cDeflectors = this->m_WindProcess.m_cDeflectors;
  if ( m_cDeflectors )
  {
    v3 = 0i64;
    v4 = m_cDeflectors;
    do
    {
      v5 = this->m_pSharedParams->m_Params.fRandomValue[4];
      v6 = 214013 * this->m_WindProcess.m_RandGenerator.m_uLCGState + 2531011;
      this->m_WindProcess.m_RandGenerator.m_uLCGState = v6;
      *(float *)((char *)&this->m_pDeflectorInfo->fRandomQFactor + v3) = (float)((float)((float)((float)v6
                                                                                               * 2.3283064e-10)
                                                                                       * 2.0)
                                                                               - 1.0)
                                                                       * v5;
      v7 = this->m_pSharedParams->m_Params.fRandomValue[5];
      v8 = 214013 * this->m_WindProcess.m_RandGenerator.m_uLCGState + 2531011;
      this->m_WindProcess.m_RandGenerator.m_uLCGState = v8;
      *(float *)((char *)&this->m_pDeflectorInfo->fRandomGain + v3) = (float)((float)((float)((float)v8 * 2.3283064e-10)
                                                                                    * 2.0)
                                                                            - 1.0)
                                                                    * v7;
      v9 = this->m_pSharedParams->m_Params.fRandomValue[6];
      v10 = 214013 * this->m_WindProcess.m_RandGenerator.m_uLCGState + 2531011;
      this->m_WindProcess.m_RandGenerator.m_uLCGState = v10;
      v3 += 32i64;
      *(float *)((char *)this->m_pDeflectorInfo + v3 - 4) = powf(
                                                              10.0,
                                                              (float)((float)((float)((float)((float)v10 * 2.3283064e-10)
                                                                                    * 2.0)
                                                                            - 1.0)
                                                                    * v9)
                                                            * 0.050000001);
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 477
// RVA: 0xAD5D60
void __fastcall CAkSoundSeedWind::ComputeDuration(CAkSoundSeedWind *this)
{
  CAkSoundSeedWindParams *m_pSharedParams; // rdx
  float fDurationRdm; // xmm0_4
  signed int v3; // eax
  float v4; // xmm1_4
  CAkSoundSeedWindParams *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm1_4

  m_pSharedParams = this->m_pSharedParams;
  this->m_fDuration = m_pSharedParams->m_Params.fDuration;
  fDurationRdm = m_pSharedParams->m_Params.fDurationRdm;
  v3 = 214013 * this->m_WindProcess.m_RandGenerator.m_uLCGState + 2531011;
  this->m_WindProcess.m_RandGenerator.m_uLCGState = v3;
  v4 = (float)v3;
  v5 = this->m_pSharedParams;
  v6 = (float)((float)((float)(v4 * 2.3283064e-10) * 2.0) - 1.0) * fDurationRdm;
  this->m_fRandomDuration = v6;
  v7 = v6 + v5->m_Params.fDuration;
  this->m_fEffectiveDuration = v7;
  if ( v7 <= 0.1 )
    v7 = FLOAT_0_1;
  this->m_fEffectiveDuration = v7;
  v5->m_uChangeMask &= ~8u;
}


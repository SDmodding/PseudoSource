// File Line: 29
// RVA: 0xAD5340
void __fastcall CreateSoundSeedWind(AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkSoundSeedWind *v1; // rax

  v1 = (CAkSoundSeedWind *)in_pAllocator->vfptr->Malloc(in_pAllocator, 352ui64);
  if ( v1 )
    CAkSoundSeedWind::CAkSoundSeedWind(v1);
}

// File Line: 38
// RVA: 0xAD5370
void __fastcall CAkSoundSeedWind::CAkSoundSeedWind(CAkSoundSeedWind *this)
{
  CAkSoundSeedWind *v1; // rbx

  v1 = this;
  this->vfptr = (AK::IAkPluginVtbl *)&CAkSoundSeedWind::`vftable';
  this->m_pSharedParams = 0i64;
  this->m_pAllocator = 0i64;
  this->m_pDeflectorInfo = 0i64;
  this->m_pDeflectorDSPInfo = 0i64;
  CAkSoundSeedWindProcess::CAkSoundSeedWindProcess(&this->m_WindProcess);
  v1->m_VelocityDelayLine.uDelayLineLength = 0;
  v1->m_VelocityDelayLine.pfDelay = 0i64;
  v1->m_VelocityDelayLine.uCurOffset = 0;
  CAkGustManager::CAkGustManager(&v1->m_VelocityDelayLine.m_GustManager);
  *(_QWORD *)v1->m_uCurvePointIndex = 0i64;
  *(_QWORD *)&v1->m_uCurvePointIndex[2] = 0i64;
  *(_QWORD *)&v1->m_uCurvePointIndex[4] = 0i64;
  v1->m_uCurvePointIndex[6] = 0;
}

// File Line: 43
// RVA: 0xAD53F0
void __fastcall CAkSoundSeedWind::~CAkSoundSeedWind(CAkSoundSeedWind *this)
{
  CAkSoundSeedWind *v1; // rbx
  CAkSoundSeedWindProcess *v2; // rcx

  v1 = this;
  v2 = &this->m_WindProcess;
  *(_QWORD *)&v2[-1].m_NoiseGen.m_DCFilter.m_fFbk1 = &CAkSoundSeedWind::`vftable';
  CAkSoundSeedWindProcess::~CAkSoundSeedWindProcess(v2);
  v1->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable';
}

// File Line: 52
// RVA: 0xAD5430
AKRESULT __fastcall CAkSoundSeedWind::Init(CAkSoundSeedWind *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkSourcePluginContext *in_pSourceFXContext, AK::IAkPluginParam *in_pParams, AkAudioFormat *io_rFormat)
{
  CAkSoundSeedWind *v5; // rdi
  AK::IAkSourcePluginContext *v6; // rbx
  AK::IAkPluginMemAlloc *v7; // rsi
  AKRESULT result; // eax

  this->m_pSharedParams = (CAkSoundSeedWindParams *)in_pParams;
  this->m_pAllocator = in_pAllocator;
  v5 = this;
  v6 = in_pSourceFXContext;
  v7 = in_pAllocator;
  this->m_uNumLoops = ((unsigned __int16 (__fastcall *)(AK::IAkSourcePluginContext *))in_pSourceFXContext->vfptr[1].__vecDelDtor)(in_pSourceFXContext);
  LODWORD(v6) = (*(unsigned __int16 (__fastcall **)(AK::IAkSourcePluginContext *))&v6->vfptr->gap8[8])(v6);
  CAkSoundSeedWindProcess::Setup(&v5->m_WindProcess, &v5->m_pSharedParams->m_Params, io_rFormat);
  v5->m_fBufferTime = (float)(signed int)v6 / (float)(signed int)v5->m_WindProcess.m_uSampleRate;
  result = CAkSoundSeedWind::SetupDeflectors(v5);
  if ( result == 1 )
  {
    CAkSoundSeedWind::ComputeDuration(v5);
    result = CAkSoundSeedWind::InitVelocityLine(v5, v7);
    v5->m_pSharedParams->m_uChangeMask &= 0xFFFFFFDF;
  }
  return result;
}

// File Line: 88
// RVA: 0xAD5A30
signed __int64 __fastcall CAkSoundSeedWind::SetupDeflectors(CAkSoundSeedWind *this)
{
  CAkSoundSeedWindParams *v1; // rax
  CAkSoundSeedWind *v2; // rbx
  unsigned int v3; // ecx
  size_t v4; // rsi
  size_t v5; // rdi
  DeflectorInfo *v6; // rax
  void *v8; // rax
  CAkSoundSeedWindParams *v9; // rax
  void *v10; // r9
  DeflectorInfo *v11; // r8
  CAkSoundSeedWindProcess *v12; // rcx
  bool v13; // cf
  bool v14; // zf
  void *v15; // r8
  DeflectorInfo *v16; // rdx

  v1 = this->m_pSharedParams;
  v2 = this;
  v3 = v1->m_cDeflectors;
  v2->m_WindProcess.m_cDeflectors = v3;
  if ( v3 )
  {
    v4 = 32 * v3;
    v5 = v2->m_WindProcess.m_uDSPInfoSize * ((v3 + 3) >> 2);
    v6 = (DeflectorInfo *)((__int64 (*)(void))v2->m_pAllocator->vfptr->Malloc)();
    v2->m_pDeflectorInfo = v6;
    if ( !v6 )
      return 52i64;
    memset(v6, 0, v4);
    v8 = v2->m_pAllocator->vfptr->Malloc(v2->m_pAllocator, v5);
    v2->m_pDeflectorDSPInfo = v8;
    if ( !v8 )
      return 52i64;
    memset(v8, 0, v5);
    v9 = v2->m_pSharedParams;
    v10 = v2->m_pDeflectorDSPInfo;
    v11 = v2->m_pDeflectorInfo;
    v12 = &v2->m_WindProcess;
    v12->m_pDeflectors = v9->m_pDeflectors;
    v12->m_pDeflectorInfo = v11;
    v12->m_pParams = &v9->m_Params;
    v12->m_pDeflectorDSPInfo = v10;
    v13 = v2->m_WindProcess.m_uNumChannels < 1;
    v14 = v2->m_WindProcess.m_uNumChannels == 1;
    v2->m_WindProcess.m_bFirstExecution = 1;
    if ( !v13 && !v14 )
      CAkSoundSeedWindProcess::InitSpatialization(v12);
    CAkSoundSeedWind::ComputeDeflectorRandomValues(v2);
  }
  else
  {
    v15 = v2->m_pDeflectorDSPInfo;
    v16 = v2->m_pDeflectorInfo;
    v2->m_WindProcess.m_pDeflectors = v1->m_pDeflectors;
    v2->m_WindProcess.m_pDeflectorInfo = v16;
    v2->m_WindProcess.m_pDeflectorDSPInfo = v15;
    v2->m_WindProcess.m_pParams = &v1->m_Params;
  }
  v2->m_pSharedParams->m_uChangeMask &= 0xFFFFFFFE;
  v2->m_pSharedParams->m_uChangeMask &= 0xFFFFFFFB;
  return 1i64;
}

// File Line: 129
// RVA: 0xAD5B70
void __fastcall CAkSoundSeedWind::TermDeflectors(CAkSoundSeedWind *this)
{
  CAkSoundSeedWind *v1; // rbx

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

// File Line: 143
// RVA: 0xAD5EB0
AKRESULT __fastcall CAkSoundSeedWind::InitVelocityLine(CAkSoundSeedWind *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkSoundSeedWindParams *v2; // r8
  CAkSoundSeedWind *v3; // rbx
  AK::IAkPluginMemAlloc *v4; // rbp
  __m128 v5; // xmm2
  signed int v6; // ecx
  float v7; // xmm6_4
  float v8; // xmm0_4
  CAkSoundSeedWindParams *v9; // rcx
  float v10; // xmm8_4
  float v11; // xmm0_4
  CAkSoundSeedWindParams *v12; // rcx
  float v13; // xmm7_4

  v2 = this->m_pSharedParams;
  v3 = this;
  v4 = in_pAllocator;
  v5 = (__m128)LODWORD(v2->m_Params.fMaxDistance);
  v5.m128_f32[0] = (float)(v5.m128_f32[0] * 2.0) / (float)(this->m_fBufferTime * 2.0);
  v6 = (signed int)v5.m128_f32[0];
  if ( (signed int)v5.m128_f32[0] != 0x80000000 && (float)v6 != v5.m128_f32[0] )
    v5.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v5, v5)) & 1 ^ 1) + v6);
  v7 = 0.0;
  if ( v2->m_Params.bAutomation[0] )
    v8 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
           v2->m_Curves,
           0.0,
           v3->m_uCurvePointIndex[0],
           v3->m_uCurvePointIndex);
  else
    v8 = 0.0;
  CAkSoundSeedWindProcess::ComputeEffectiveAverageVelocity(&v3->m_WindProcess, v8);
  v9 = v3->m_pSharedParams;
  v10 = v3->m_WindProcess.m_fEffectiveParamValue[0];
  if ( v9->m_Params.bAutomation[2] )
    v11 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
            &v9->m_Curves[2],
            0.0,
            v3->m_uCurvePointIndex[2],
            &v3->m_uCurvePointIndex[2]);
  else
    v11 = 0.0;
  CAkSoundSeedWindProcess::ComputeEffectiveVariability(&v3->m_WindProcess, v11);
  v12 = v3->m_pSharedParams;
  v13 = v3->m_WindProcess.m_fEffectiveParamValue[2];
  if ( v12->m_Params.bAutomation[3] )
    v7 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
           &v12->m_Curves[3],
           0.0,
           v3->m_uCurvePointIndex[3],
           &v3->m_uCurvePointIndex[3]);
  CAkSoundSeedWindProcess::ComputeEffectiveGustiness(&v3->m_WindProcess, v7);
  return CAkVelocityDelayLine::Init(
           &v3->m_VelocityDelayLine,
           v10,
           v13,
           v3->m_WindProcess.m_fEffectiveParamValue[3],
           v3->m_fBufferTime,
           v4,
           (signed int)v5.m128_f32[0],
           2.0);
}

// File Line: 161
// RVA: 0xAD54F0
signed __int64 __fastcall CAkSoundSeedWind::Term(CAkSoundSeedWind *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkSoundSeedWind *v3; // rbx

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
  CAkVelocityDelayLine::Term(&v3->m_VelocityDelayLine, v2);
  v3->vfptr->__vecDelDtor((AK::IAkPlugin *)&v3->vfptr, 0);
  v2->vfptr->Free(v2, v3);
  return 1i64;
}

// File Line: 169
// RVA: 0xAD5580
signed __int64 __fastcall CAkSoundSeedWind::Reset(CAkSoundSeedWind *this)
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
signed __int64 __fastcall CAkSoundSeedWind::GetPluginInfo(CAkSoundSeedWind *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 2;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 186
// RVA: 0xAD5DE0
float __fastcall CAkSoundSeedWind::GetInitialEffectiveParam(CAkSoundSeedWind *this, unsigned int in_ParameterName)
{
  CAkSoundSeedWind *v2; // rbx
  CAkSoundSeedWindParams *v3; // rcx
  __int64 v4; // rdi
  __int64 v5; // rsi
  float v6; // xmm0_4
  int v7; // edi
  float result; // xmm0_4

  v2 = this;
  v3 = this->m_pSharedParams;
  v4 = in_ParameterName;
  v5 = in_ParameterName;
  if ( v3->m_Params.bAutomation[in_ParameterName] )
    v6 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
           &v3->m_Curves[in_ParameterName],
           0.0,
           v2->m_uCurvePointIndex[in_ParameterName],
           &v2->m_uCurvePointIndex[in_ParameterName]);
  else
    v6 = 0.0;
  if ( (_DWORD)v4 )
  {
    v7 = v4 - 2;
    if ( v7 )
    {
      if ( v7 == 1 )
      {
        CAkSoundSeedWindProcess::ComputeEffectiveGustiness(&v2->m_WindProcess, v6);
        return v2->m_WindProcess.m_fEffectiveParamValue[v5];
      }
    }
    else
    {
      CAkSoundSeedWindProcess::ComputeEffectiveVariability(&v2->m_WindProcess, v6);
    }
    result = v2->m_WindProcess.m_fEffectiveParamValue[v5];
  }
  else
  {
    CAkSoundSeedWindProcess::ComputeEffectiveAverageVelocity(&v2->m_WindProcess, v6);
    result = v2->m_WindProcess.m_fEffectiveParamValue[v4];
  }
  return result;
}

// File Line: 210
// RVA: 0xAD58A0
signed __int64 __fastcall CAkSoundSeedWind::TimeSkip(CAkSoundSeedWind *this, unsigned int *io_uFrames)
{
  signed int v2; // er15
  CAkSoundSeedWind *v3; // rbx
  __int64 v4; // rsi
  __int64 v5; // rbp
  float *v6; // rdi
  float v7; // xmm6_4
  signed __int64 v8; // r14
  CAkSoundSeedWindParams *v9; // rax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  unsigned int v14; // eax

  v2 = *io_uFrames;
  v3 = this;
  if ( this->m_WindProcess.m_cDeflectors )
  {
    v4 = 0i64;
    v5 = 0i64;
    v6 = this->m_WindProcess.m_fAutomationValues;
    v7 = this->m_fDuration / this->m_fEffectiveDuration;
    v8 = 7i64;
    do
    {
      v9 = v3->m_pSharedParams;
      if ( v9->m_Params.bAutomation[v4] )
        *v6 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                &v9->m_Curves[v5],
                v7 * v3->m_fTimeElapsed,
                *((_DWORD *)v6 - 17),
                (unsigned int *)v6 - 17);
      else
        *v6 = 0.0;
      ++v4;
      ++v5;
      ++v6;
      --v8;
    }
    while ( v8 );
  }
  v10 = (double)v2 / (double)(signed int)v3->m_WindProcess.m_uSampleRate;
  v11 = v3->m_fEffectiveDuration;
  v12 = (float)(v10 * v3->m_pSharedParams->m_Params.fPlaybackRate) + v3->m_fTimeElapsed;
  v3->m_fTimeElapsed = v12;
  if ( v12 >= v11 )
  {
    v13 = fmodf(v12, v11);
    ++v3->m_uLoopCount;
    v3->m_fTimeElapsed = v13;
    *(_QWORD *)v3->m_uCurvePointIndex = 0i64;
    *(_QWORD *)&v3->m_uCurvePointIndex[2] = 0i64;
    *(_QWORD *)&v3->m_uCurvePointIndex[4] = 0i64;
    v3->m_uCurvePointIndex[6] = 0;
    v14 = v3->m_uNumLoops;
    if ( v14 && v3->m_uLoopCount >= v14 )
      return 17i64;
    CAkSoundSeedWind::ComputeDuration(v3);
  }
  return 45i64;
}

// File Line: 266
// RVA: 0xAD55D0
void __fastcall CAkSoundSeedWind::Execute(CAkSoundSeedWind *this, AkAudioBuffer *io_pBufferOut)
{
  signed int v2; // er13
  unsigned int v3; // edi
  AkAudioBuffer *v4; // rsi
  CAkSoundSeedWind *v5; // rbx
  __int64 v6; // rbp
  float *v7; // rdi
  float v8; // xmm6_4
  __int64 v9; // r14
  signed __int64 v10; // r15
  CAkSoundSeedWindParams *v11; // rax
  float *v12; // rax
  float *v13; // rdi
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  unsigned int v18; // eax
  CAkSoundSeedWindParams *v19; // rcx
  float v20; // xmm0_4
  int v21; // eax
  float v22; // xmm1_4
  CAkSoundSeedWindParams *v23; // rax
  float v24; // xmm1_4
  float v25; // xmm1_4

  v2 = io_pBufferOut->uMaxFrames;
  v3 = 0;
  io_pBufferOut->eState = 45;
  io_pBufferOut->uValidFrames = v2;
  v4 = io_pBufferOut;
  v5 = this;
  if ( this->m_WindProcess.m_uNumChannels )
  {
    do
      memset((char *)v4->pData + 4 * v3++ * (unsigned __int64)v4->uMaxFrames, 0, (unsigned int)(4 * v2));
    while ( v3 < v5->m_WindProcess.m_uNumChannels );
  }
  if ( v5->m_WindProcess.m_cDeflectors )
  {
    v6 = 0i64;
    v7 = v5->m_WindProcess.m_fAutomationValues;
    v8 = v5->m_fDuration / v5->m_fEffectiveDuration;
    v9 = 0i64;
    v10 = 7i64;
    do
    {
      v11 = v5->m_pSharedParams;
      if ( v11->m_Params.bAutomation[v6] )
        *v7 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                &v11->m_Curves[v9],
                v8 * v5->m_fTimeElapsed,
                *((_DWORD *)v7 - 17),
                (unsigned int *)v7 - 17);
      else
        *v7 = 0.0;
      ++v6;
      ++v9;
      ++v7;
      --v10;
    }
    while ( v10 );
    CAkSoundSeedWindProcess::Prepare(
      &v5->m_WindProcess,
      v2,
      &v5->m_VelocityDelayLine,
      v5->m_pSharedParams->m_uChangeMask);
    v12 = (float *)v5->m_pAllocator->vfptr->Malloc(
                     v5->m_pAllocator,
                     4i64 * ((v5->m_WindProcess.m_uNumChannels << 12) + 1024));
    v13 = v12;
    if ( !v12 )
    {
      v4->eState = 2;
      return;
    }
    CAkSoundSeedWindProcess::Process(&v5->m_WindProcess, v4, v12);
    v5->m_pAllocator->vfptr->Free(v5->m_pAllocator, v13);
  }
  v14 = (double)v2 / (double)(signed int)v5->m_WindProcess.m_uSampleRate;
  v15 = v5->m_fEffectiveDuration;
  v16 = (float)(v14 * v5->m_pSharedParams->m_Params.fPlaybackRate) + v5->m_fTimeElapsed;
  v5->m_fTimeElapsed = v16;
  if ( v16 >= v15 )
  {
    v17 = fmodf(v16, v15);
    ++v5->m_uLoopCount;
    v5->m_fTimeElapsed = v17;
    *(_QWORD *)v5->m_uCurvePointIndex = 0i64;
    *(_QWORD *)&v5->m_uCurvePointIndex[2] = 0i64;
    *(_QWORD *)&v5->m_uCurvePointIndex[4] = 0i64;
    v5->m_uCurvePointIndex[6] = 0;
    v18 = v5->m_uNumLoops;
    if ( v18 && v5->m_uLoopCount >= v18 )
    {
      v4->eState = 17;
    }
    else
    {
      v19 = v5->m_pSharedParams;
      v5->m_fDuration = v19->m_Params.fDuration;
      v20 = v19->m_Params.fDurationRdm;
      v21 = 214013 * v5->m_WindProcess.m_RandGenerator.m_uLCGState + 2531011;
      v5->m_WindProcess.m_RandGenerator.m_uLCGState = v21;
      v22 = (float)v21;
      v23 = v5->m_pSharedParams;
      v24 = (float)((float)((float)(v22 * 2.3283064e-10) * 2.0) - 1.0) * v20;
      v5->m_fRandomDuration = v24;
      v25 = v24 + v23->m_Params.fDuration;
      v5->m_fEffectiveDuration = v25;
      if ( v25 <= 0.1 )
        v25 = FLOAT_0_1;
      v5->m_fEffectiveDuration = v25;
      v23->m_uChangeMask &= 0xFFFFFFF7;
    }
  }
  v5->m_pSharedParams->m_uChangeMask = 0;
}

// File Line: 409
// RVA: 0xAD5850
float __fastcall CAkSoundSeedWind::GetDuration(CAkSoundSeedWind *this)
{
  return (float)(this->m_fEffectiveDuration * 1000.0) * (float)(signed int)this->m_uNumLoops;
}

// File Line: 414
// RVA: 0xAD5880
signed __int64 __fastcall CAkSoundSeedWind::StopLooping(CAkSoundSeedWind *this)
{
  this->m_uNumLoops = 1;
  return 1i64;
}

// File Line: 420
// RVA: 0xAD5A00
void __fastcall CAkSoundSeedWind::ComputeDeflectorAllocationSizes(CAkSoundSeedWind *this, unsigned int *out_uInfoAllocSize, unsigned int *out_uDSPAllocSize)
{
  *out_uInfoAllocSize = 32 * this->m_WindProcess.m_cDeflectors;
  *out_uDSPAllocSize = ((this->m_WindProcess.m_cDeflectors + 3) >> 2) * this->m_WindProcess.m_uDSPInfoSize;
}

// File Line: 466
// RVA: 0xAD5BC0
void __fastcall CAkSoundSeedWind::ComputeDeflectorRandomValues(CAkSoundSeedWind *this)
{
  unsigned int v1; // eax
  CAkSoundSeedWind *v2; // rbx
  __int64 v3; // rdi
  __int64 v4; // rsi
  float v5; // xmm1_4
  int v6; // eax
  float v7; // xmm1_4
  int v8; // eax
  float v9; // xmm2_4
  int v10; // eax

  v1 = this->m_WindProcess.m_cDeflectors;
  v2 = this;
  if ( v1 )
  {
    v3 = 0i64;
    v4 = v1;
    do
    {
      v5 = v2->m_pSharedParams->m_Params.fRandomValue[4];
      v6 = 214013 * v2->m_WindProcess.m_RandGenerator.m_uLCGState + 2531011;
      v2->m_WindProcess.m_RandGenerator.m_uLCGState = v6;
      *(float *)((char *)&v2->m_pDeflectorInfo->fRandomQFactor + v3) = (float)((float)((float)((float)v6 * 2.3283064e-10)
                                                                                     * 2.0)
                                                                             - 1.0)
                                                                     * v5;
      v7 = v2->m_pSharedParams->m_Params.fRandomValue[5];
      v8 = 214013 * v2->m_WindProcess.m_RandGenerator.m_uLCGState + 2531011;
      v2->m_WindProcess.m_RandGenerator.m_uLCGState = v8;
      *(float *)((char *)&v2->m_pDeflectorInfo->fRandomGain + v3) = (float)((float)((float)((float)v8 * 2.3283064e-10)
                                                                                  * 2.0)
                                                                          - 1.0)
                                                                  * v7;
      v9 = v2->m_pSharedParams->m_Params.fRandomValue[6];
      v10 = 214013 * v2->m_WindProcess.m_RandGenerator.m_uLCGState + 2531011;
      v2->m_WindProcess.m_RandGenerator.m_uLCGState = v10;
      v3 += 32i64;
      *(float *)((char *)v2->m_pDeflectorInfo + v3 - 4) = powf(
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
  CAkSoundSeedWindParams *v1; // rdx
  float v2; // xmm0_4
  signed int v3; // eax
  float v4; // xmm1_4
  CAkSoundSeedWindParams *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm1_4

  v1 = this->m_pSharedParams;
  this->m_fDuration = v1->m_Params.fDuration;
  v2 = v1->m_Params.fDurationRdm;
  v3 = 214013 * this->m_WindProcess.m_RandGenerator.m_uLCGState + 2531011;
  this->m_WindProcess.m_RandGenerator.m_uLCGState = v3;
  v4 = (float)v3;
  v5 = this->m_pSharedParams;
  v6 = (float)((float)((float)(v4 * 2.3283064e-10) * 2.0) - 1.0) * v2;
  this->m_fRandomDuration = v6;
  v7 = v6 + v5->m_Params.fDuration;
  this->m_fEffectiveDuration = v7;
  if ( v7 <= 0.1 )
    v7 = FLOAT_0_1;
  this->m_fEffectiveDuration = v7;
  v5->m_uChangeMask &= 0xFFFFFFF7;
}


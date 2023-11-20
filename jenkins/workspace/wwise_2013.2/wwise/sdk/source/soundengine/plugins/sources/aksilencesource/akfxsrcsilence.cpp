// File Line: 27
// RVA: 0xAD1620
AK::IAkPluginParam *__fastcall CreateSilenceSourceParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 24ui64);
  if ( result )
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFxSrcSilenceParams::`vftable';
  return result;
}

// File Line: 33
// RVA: 0xAD16A0
void __fastcall CAkFxSrcSilenceParams::CAkFxSrcSilenceParams(CAkFxSrcSilenceParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFxSrcSilenceParams::`vftable';
}

// File Line: 38
// RVA: 0xAD16C0
void __fastcall CAkFxSrcSilenceParams::CAkFxSrcSilenceParams(CAkFxSrcSilenceParams *this, CAkFxSrcSilenceParams *Copy)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFxSrcSilenceParams::`vftable';
  this->m_Params.fDuration = Copy->m_Params.fDuration;
  this->m_Params.fRandomizedLengthMinus = Copy->m_Params.fRandomizedLengthMinus;
  this->m_Params.fRandomizedLengthPlus = Copy->m_Params.fRandomizedLengthPlus;
}

// File Line: 44
// RVA: 0xAD16F0
void __fastcall CAkFxSrcSilenceParams::~CAkFxSrcSilenceParams(CAkFxSrcSilenceParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable';
}

// File Line: 49
// RVA: 0xAD1710
AK::IAkPluginParam *__fastcall CAkFxSrcSilenceParams::Clone(CAkFxSrcSilenceParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkFxSrcSilenceParams *v2; // rbx
  AK::IAkPluginParam *result; // rax

  v2 = this;
  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 24ui64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFxSrcSilenceParams::`vftable';
    *(float *)&result[1].vfptr = v2->m_Params.fDuration;
    HIDWORD(result[1].vfptr) = LODWORD(v2->m_Params.fRandomizedLengthMinus);
    *(float *)&result[2].vfptr = v2->m_Params.fRandomizedLengthPlus;
  }
  return result;
}

// File Line: 58
// RVA: 0xAD1760
__int64 __fastcall CAkFxSrcSilenceParams::Init(CAkFxSrcSilenceParams *this, AK::IAkPluginMemAlloc *__formal, const void *in_pvParamsBlock, unsigned int in_ulBlockSize)
{
  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkFxSrcSilenceParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pvParamsBlock,
             in_ulBlockSize);
  *(_QWORD *)&this->m_Params.fDuration = 1065353216i64;
  this->m_Params.fRandomizedLengthPlus = 0.0;
  return 1i64;
}

// File Line: 74
// RVA: 0xAD1790
signed __int64 __fastcall CAkFxSrcSilenceParams::Term(CAkFxSrcSilenceParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkFxSrcSilenceParams *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
  {
    this->vfptr->__vecDelDtor((AK::IAkRTPCSubscriber *)this, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 83
// RVA: 0xAD17D0
signed __int64 __fastcall CAkFxSrcSilenceParams::SetParamsBlock(CAkFxSrcSilenceParams *this, const void *in_pvParamsBlock, unsigned int in_ulBlockSize)
{
  this->m_Params.fDuration = *(float *)in_pvParamsBlock;
  this->m_Params.fRandomizedLengthMinus = *((float *)in_pvParamsBlock + 1);
  this->m_Params.fRandomizedLengthPlus = *((float *)in_pvParamsBlock + 2);
  return 1i64;
}

// File Line: 100
// RVA: 0xAD1800
signed __int64 __fastcall CAkFxSrcSilenceParams::SetParam(CAkFxSrcSilenceParams *this, __int16 in_ParamID, const void *in_pvValue, unsigned int __formal)
{
  signed __int64 result; // rax

  if ( !in_pvValue )
    return 31i64;
  if ( in_ParamID )
  {
    if ( in_ParamID == 1 )
    {
      this->m_Params.fRandomizedLengthMinus = *(float *)in_pvValue;
      result = 1i64;
    }
    else
    {
      if ( in_ParamID != 2 )
        return 31i64;
      this->m_Params.fRandomizedLengthPlus = *(float *)in_pvValue;
      result = 1i64;
    }
  }
  else
  {
    this->m_Params.fDuration = *(float *)in_pvValue;
    result = 1i64;
  }
  return result;
}

// File Line: 134
// RVA: 0xAD1650
AK::IAkPlugin *__fastcall CreateSilenceSource(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPlugin *result; // rax

  result = (AK::IAkPlugin *)in_pAllocator->vfptr->Malloc(in_pAllocator, 48ui64);
  if ( !result )
    return 0i64;
  LODWORD(result[3].vfptr) = 1;
  result->vfptr = (AK::IAkPluginVtbl *)&CAkFXSrcSilence::`vftable';
  result[1].vfptr = 0i64;
  HIDWORD(result[2].vfptr) = 0;
  HIDWORD(result[3].vfptr) = 0;
  result[5].vfptr = 0i64;
  result[4].vfptr = 0i64;
  return result;
}

// File Line: 143
// RVA: 0xAD1850
void __fastcall CAkFXSrcSilence::CAkFXSrcSilence(CAkFXSrcSilence *this)
{
  *(_DWORD *)&this->m_sNumLoops = 1;
  this->vfptr = (AK::IAkPluginVtbl *)&CAkFXSrcSilence::`vftable';
  *(_QWORD *)&this->m_uSampleRate = 0i64;
  this->m_fDurationModifier = 0.0;
  this->m_fInitDuration = 0.0;
  this->m_pSourceFXContext = 0i64;
  this->m_pSharedParams = 0i64;
}

// File Line: 160
// RVA: 0xAD1880
void __fastcall CAkFXSrcSilence::~CAkFXSrcSilence(CAkFXSrcSilence *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable';
}

// File Line: 173
// RVA: 0xAD18A0
signed __int64 __fastcall CAkFXSrcSilence::Init(CAkFXSrcSilence *this, AK::IAkPluginMemAlloc *__formal, AK::IAkSourcePluginContext *in_pSourceFXContext, AK::IAkPluginParam *in_pParams, AkAudioFormat *io_rFormat)
{
  CAkFXSrcSilence *v5; // rdi
  AK::IAkPluginParam *v6; // rbx
  __int16 v7; // ax
  float v8; // xmm6_4
  float v9; // xmm7_4
  __m128i v10; // xmm0
  CAkFxSrcSilenceParams *v11; // rax
  signed __int64 result; // rax

  this->m_pSourceFXContext = in_pSourceFXContext;
  v5 = this;
  v6 = in_pParams;
  this->m_uSampleRate = io_rFormat->uSampleRate;
  this->m_uBytesPerSample = (*((_DWORD *)io_rFormat + 1) >> 21) & 7;
  v7 = ((__int64 (__fastcall *)(AK::IAkSourcePluginContext *))in_pSourceFXContext->vfptr[1].__vecDelDtor)(in_pSourceFXContext);
  v5->m_pSharedParams = (CAkFxSrcSilenceParams *)v6;
  v5->m_sNumLoops = v7;
  v8 = *(float *)&v6[2].vfptr;
  v9 = *((float *)&v6[1].vfptr + 1);
  v10 = _mm_cvtsi32_si128(rand());
  v11 = v5->m_pSharedParams;
  *(float *)v10.m128i_i32 = (float)((float)(COERCE_FLOAT(_mm_cvtepi32_ps(v10)) * 0.000030518509) * (float)(v8 - v9))
                          + v9;
  LODWORD(v5->m_fDurationModifier) = v10.m128i_i32[0];
  *(float *)v10.m128i_i32 = *(float *)v10.m128i_i32 + v11->m_Params.fDuration;
  result = 1i64;
  LODWORD(v5->m_fInitDuration) = v10.m128i_i32[0];
  if ( *(float *)v10.m128i_i32 < 0.001 )
    v5->m_fInitDuration = 0.001;
  return result;
}

// File Line: 212
// RVA: 0xAD1960
signed __int64 __fastcall CAkFXSrcSilence::Term(CAkFXSrcSilence *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkFXSrcSilence *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
  {
    this->vfptr->__vecDelDtor((AK::IAkPlugin *)this, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 222
// RVA: 0xAD19A0
signed __int64 __fastcall CAkFXSrcSilence::Reset(CAkFXSrcSilence *this)
{
  this->m_ulOutByteCount = 0;
  this->m_sCurLoopCount = 0;
  return 1i64;
}

// File Line: 236
// RVA: 0xAD19C0
signed __int64 __fastcall CAkFXSrcSilence::GetPluginInfo(CAkFXSrcSilence *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 2;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 245
// RVA: 0xAD19E0
__int64 __fastcall CAkFXSrcSilence::TimeSkip(CAkFXSrcSilence *this, unsigned int *io_uFrames)
{
  unsigned int v2; // er10
  unsigned int v3; // ebx
  unsigned int v4; // er9
  unsigned int *v5; // rdi
  __int16 v6; // dx
  CAkFXSrcSilence *v7; // r8
  unsigned int v8; // er10
  unsigned int v9; // er11
  float v10; // xmm1_4
  unsigned int v11; // eax
  unsigned int v12; // ecx
  signed int v13; // ecx
  __int64 result; // rax

  v2 = *io_uFrames;
  v3 = this->m_uBytesPerSample;
  v4 = 0;
  v5 = io_uFrames;
  v6 = this->m_sNumLoops;
  v7 = this;
  v8 = v3 * v2;
  v9 = 45;
  if ( v6 )
  {
    v10 = this->m_pSharedParams->m_Params.fDuration + this->m_fDurationModifier;
    if ( v10 < 0.001 )
      v10 = FLOAT_0_001;
    v11 = this->m_ulOutByteCount;
    v12 = v3 * v6 * (signed int)(float)((float)(signed int)this->m_uSampleRate * v10);
    if ( v11 < v12 )
    {
      v4 = v12 - v11;
      if ( v8 < v12 - v11 )
        v4 = v8;
      v7->m_ulOutByteCount = v11 + v4;
      v13 = 45;
      if ( v4 < v8 )
        v13 = 17;
      v9 = v13;
    }
    else
    {
      v9 = 17;
    }
  }
  else
  {
    v4 = v8;
  }
  result = v9;
  *v5 = (unsigned __int16)(v4 / v3);
  return result;
}

// File Line: 301
// RVA: 0xAD1AB0
void __fastcall CAkFXSrcSilence::Execute(CAkFXSrcSilence *this, AkAudioBuffer *io_pBufferOut)
{
  AkAudioBuffer *v2; // rdi
  CAkFXSrcSilence *v3; // rbx
  AKRESULT v4; // eax
  int v5; // er8
  void *v6; // rcx
  int v7; // [rsp+30h] [rbp+8h]

  v2 = io_pBufferOut;
  v7 = io_pBufferOut->uMaxFrames;
  v3 = this;
  v4 = ((unsigned int (__fastcall *)(CAkFXSrcSilence *, int *))this->vfptr[1].RelocateMedia)(this, &v7);
  v5 = v7;
  v6 = v2->pData;
  v2->uValidFrames = v7;
  v2->eState = v4;
  memset(v6, 0, v3->m_uBytesPerSample * v5);
}

// File Line: 323
// RVA: 0xAD1B00
float __fastcall CAkFXSrcSilence::GetDuration(CAkFXSrcSilence *this)
{
  return (float)(this->m_fInitDuration * 1000.0) * (float)this->m_sNumLoops;
}

// File Line: 328
// RVA: 0xAD1B30
signed __int64 __fastcall CAkFXSrcSilence::StopLooping(CAkFXSrcSilence *this)
{
  signed __int64 result; // rax

  result = 1i64;
  this->m_sNumLoops = 1;
  return result;
}

// File Line: 335
// RVA: 0xAD1B40
signed __int64 __fastcall CAkFXSrcSilence::Seek(CAkFXSrcSilence *this, unsigned int in_uPosition)
{
  __int16 v2; // r10
  float v3; // xmm1_4
  unsigned int v4; // er9

  v2 = this->m_sNumLoops;
  if ( v2 )
  {
    v3 = this->m_pSharedParams->m_Params.fDuration + this->m_fDurationModifier;
    if ( v3 < 0.001 )
      v3 = FLOAT_0_001;
    v4 = in_uPosition * this->m_uBytesPerSample;
    if ( v4 >= this->m_uBytesPerSample * v2 * (signed int)(float)((float)(signed int)this->m_uSampleRate * v3) )
      return 2i64;
    this->m_ulOutByteCount = v4;
  }
  return 1i64;
}


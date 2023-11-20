// File Line: 20
// RVA: 0xAECA40
AK::IAkPluginParam *__fastcall CreateTimeStretchFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 24ui64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkTimeStretchFXParams::`vftable;
    result[1].vfptr = (AK::IAkRTPCSubscriberVtbl *)2048;
    LODWORD(result[2].vfptr) = 0;
    HIDWORD(result[2].vfptr) = 1065353216;
  }
  return result;
}

// File Line: 26
// RVA: 0xAECA90
void __fastcall CAkTimeStretchFXParams::CAkTimeStretchFXParams(CAkTimeStretchFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkTimeStretchFXParams::`vftable;
  *(_QWORD *)&this->m_Params.uWindowSize = 2048i64;
  this->m_Params.fTimeStretchRandom = 0.0;
  this->m_Params.fOutputGain = 1.0;
}

// File Line: 30
// RVA: 0xAECAC0
void __fastcall CAkTimeStretchFXParams::~CAkTimeStretchFXParams(CAkTimeStretchFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
}

// File Line: 35
// RVA: 0xAECAE0
void __fastcall CAkTimeStretchFXParams::CAkTimeStretchFXParams(CAkTimeStretchFXParams *this, CAkTimeStretchFXParams *in_rCopy)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkTimeStretchFXParams::`vftable;
  *(_QWORD *)&this->m_Params.uWindowSize = 2048i64;
  this->m_Params.fOutputGain = 1.0;
  this->m_Params.fTimeStretchRandom = 0.0;
  this->m_Params.uWindowSize = in_rCopy->m_Params.uWindowSize;
  this->m_Params.fTimeStretch = in_rCopy->m_Params.fTimeStretch;
  this->m_Params.fTimeStretchRandom = in_rCopy->m_Params.fTimeStretchRandom;
  this->m_Params.fOutputGain = in_rCopy->m_Params.fOutputGain;
}

// File Line: 41
// RVA: 0xAECB20
AK::IAkPluginParam *__fastcall CAkTimeStretchFXParams::Clone(CAkTimeStretchFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkTimeStretchFXParams *v2; // rbx
  AK::IAkPluginParam *result; // rax

  v2 = this;
  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 24ui64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkTimeStretchFXParams::`vftable;
    result[1].vfptr = (AK::IAkRTPCSubscriberVtbl *)2048;
    LODWORD(result[2].vfptr) = 0;
    HIDWORD(result[2].vfptr) = 1065353216;
    LODWORD(result[1].vfptr) = v2->m_Params.uWindowSize;
    HIDWORD(result[1].vfptr) = LODWORD(v2->m_Params.fTimeStretch);
    *(float *)&result[2].vfptr = v2->m_Params.fTimeStretchRandom;
    HIDWORD(result[2].vfptr) = LODWORD(v2->m_Params.fOutputGain);
  }
  return result;
}

// File Line: 49
// RVA: 0xAECB90
__int64 __fastcall CAkTimeStretchFXParams::Init(CAkTimeStretchFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  __int64 result; // rax

  if ( in_ulBlockSize )
    result = ((__int64 (__fastcall *)(CAkTimeStretchFXParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
               this,
               in_pParamsBlock,
               in_ulBlockSize);
  else
    result = 1i64;
  return result;
}

// File Line: 59
// RVA: 0xAECBC0
signed __int64 __fastcall CAkTimeStretchFXParams::Term(CAkTimeStretchFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkTimeStretchFXParams *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
  {
    this->vfptr->__vecDelDtor((AK::IAkRTPCSubscriber *)this, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 68
// RVA: 0xAECC00
signed __int64 __fastcall CAkTimeStretchFXParams::SetParamsBlock(CAkTimeStretchFXParams *this, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  CAkTimeStretchFXParams *v3; // rbx
  float v4; // xmm0_4
  signed __int64 result; // rax

  v3 = this;
  this->m_Params.uWindowSize = *(_DWORD *)in_pParamsBlock;
  this->m_Params.fTimeStretch = *((float *)in_pParamsBlock + 1);
  this->m_Params.fTimeStretchRandom = *((float *)in_pParamsBlock + 2);
  v4 = powf(10.0, *((float *)in_pParamsBlock + 3) * 0.050000001);
  result = 1i64;
  v3->m_Params.fOutputGain = v4;
  return result;
}

// File Line: 85
// RVA: 0xAECC50
signed __int64 __fastcall CAkTimeStretchFXParams::SetParam(CAkTimeStretchFXParams *this, __int16 in_ParamID, const void *in_pValue, unsigned int in_ulParamSize)
{
  CAkTimeStretchFXParams *v4; // rbx
  signed __int64 result; // rax
  float v6; // xmm0_4

  v4 = this;
  if ( !in_pValue )
    return 31i64;
  if ( in_ParamID )
  {
    switch ( in_ParamID )
    {
      case 1:
        this->m_Params.fTimeStretch = *(float *)in_pValue;
        return 1i64;
      case 2:
        v6 = powf(10.0, *(float *)in_pValue * 0.050000001);
        result = 1i64;
        v4->m_Params.fOutputGain = v6;
        return result;
      case 3:
        this->m_Params.fTimeStretchRandom = *(float *)in_pValue;
        return 1i64;
    }
  }
  else
  {
    this->m_Params.uWindowSize = *(_DWORD *)in_pValue;
  }
  return 1i64;
}

// File Line: 112
// RVA: 0xAECCE0
void __fastcall CAkTimeStretchFXParams::GetParams(CAkTimeStretchFXParams *this, AkTimeStretchFXParams *out_pParams)
{
  out_pParams->uWindowSize = this->m_Params.uWindowSize;
  out_pParams->fTimeStretch = this->m_Params.fTimeStretch;
  out_pParams->fTimeStretchRandom = this->m_Params.fTimeStretchRandom;
  out_pParams->fOutputGain = this->m_Params.fOutputGain;
}


// File Line: 20
// RVA: 0xAECA40
AK::IAkPluginParam *__fastcall CreateTimeStretchFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 24i64);
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
void __fastcall CAkTimeStretchFXParams::CAkTimeStretchFXParams(
        CAkTimeStretchFXParams *this,
        CAkTimeStretchFXParams *in_rCopy)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkTimeStretchFXParams::`vftable;
  *(_QWORD *)&this->m_Params.uWindowSize = 2048i64;
  this->m_Params.fOutputGain = 1.0;
  this->m_Params.fTimeStretchRandom = 0.0;
  this->m_Params = in_rCopy->m_Params;
}

// File Line: 41
// RVA: 0xAECB20
AK::IAkPluginParam *__fastcall CAkTimeStretchFXParams::Clone(
        CAkTimeStretchFXParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 24i64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkTimeStretchFXParams::`vftable;
    result[1].vfptr = (AK::IAkRTPCSubscriberVtbl *)2048;
    LODWORD(result[2].vfptr) = 0;
    HIDWORD(result[2].vfptr) = 1065353216;
    LODWORD(result[1].vfptr) = this->m_Params.uWindowSize;
    HIDWORD(result[1].vfptr) = LODWORD(this->m_Params.fTimeStretch);
    *(float *)&result[2].vfptr = this->m_Params.fTimeStretchRandom;
    HIDWORD(result[2].vfptr) = LODWORD(this->m_Params.fOutputGain);
  }
  return result;
}

// File Line: 49
// RVA: 0xAECB90
__int64 __fastcall CAkTimeStretchFXParams::Init(
        CAkTimeStretchFXParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        const void *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkTimeStretchFXParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  else
    return 1i64;
}

// File Line: 59
// RVA: 0xAECBC0
__int64 __fastcall CAkTimeStretchFXParams::Term(CAkTimeStretchFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 68
// RVA: 0xAECC00
__int64 __fastcall CAkTimeStretchFXParams::SetParamsBlock(
        CAkTimeStretchFXParams *this,
        const void *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  float v4; // xmm0_4
  __int64 result; // rax

  this->m_Params.uWindowSize = *(_DWORD *)in_pParamsBlock;
  this->m_Params.fTimeStretch = *((float *)in_pParamsBlock + 1);
  this->m_Params.fTimeStretchRandom = *((float *)in_pParamsBlock + 2);
  v4 = powf(10.0, *((float *)in_pParamsBlock + 3) * 0.050000001);
  result = 1i64;
  this->m_Params.fOutputGain = v4;
  return result;
}

// File Line: 85
// RVA: 0xAECC50
__int64 __fastcall CAkTimeStretchFXParams::SetParam(
        CAkTimeStretchFXParams *this,
        __int16 in_ParamID,
        float *in_pValue,
        unsigned int in_ulParamSize)
{
  __int64 result; // rax
  float v6; // xmm0_4

  if ( !in_pValue )
    return 31i64;
  if ( in_ParamID )
  {
    switch ( in_ParamID )
    {
      case 1:
        this->m_Params.fTimeStretch = *in_pValue;
        return 1i64;
      case 2:
        v6 = powf(10.0, *in_pValue * 0.050000001);
        result = 1i64;
        this->m_Params.fOutputGain = v6;
        return result;
      case 3:
        this->m_Params.fTimeStretchRandom = *in_pValue;
        return 1i64;
    }
  }
  else
  {
    this->m_Params.uWindowSize = *(unsigned int *)in_pValue;
  }
  return 1i64;
}

// File Line: 112
// RVA: 0xAECCE0
void __fastcall CAkTimeStretchFXParams::GetParams(CAkTimeStretchFXParams *this, AkTimeStretchFXParams *out_pParams)
{
  *out_pParams = this->m_Params;
}


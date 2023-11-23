// File Line: 18
// RVA: 0xAF62F0
AK::IAkPluginParam *__fastcall CreateGainFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 16i64);
  if ( result )
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkGainFXParams::`vftable;
  return result;
}

// File Line: 25
// RVA: 0xAF6320
void __fastcall CAkGainFXParams::CAkGainFXParams(CAkGainFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkGainFXParams::`vftable;
}

// File Line: 29
// RVA: 0xAF6340
void __fastcall CAkGainFXParams::~CAkGainFXParams(CAkGainFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
}

// File Line: 34
// RVA: 0xAF6360
void __fastcall CAkGainFXParams::CAkGainFXParams(CAkGainFXParams *this, CAkGainFXParams *in_rCopy)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkGainFXParams::`vftable;
  this->m_Params = in_rCopy->m_Params;
}

// File Line: 40
// RVA: 0xAF6380
AK::IAkPluginParam *__fastcall CAkGainFXParams::Clone(CAkGainFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 16i64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkGainFXParams::`vftable;
    result[1].vfptr = (AK::IAkRTPCSubscriberVtbl *)this->m_Params;
  }
  return result;
}

// File Line: 49
// RVA: 0xAF63D0
__int64 __fastcall CAkGainFXParams::Init(
        CAkGainFXParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        const void *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkGainFXParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  this->m_Params = 0i64;
  return 1i64;
}

// File Line: 62
// RVA: 0xAF6400
__int64 __fastcall CAkGainFXParams::Term(CAkGainFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 72
// RVA: 0xAF6440
__int64 __fastcall CAkGainFXParams::SetParamsBlock(
        CAkGainFXParams *this,
        AkGainFXParams *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  this->m_Params = *in_pParamsBlock;
  return 1i64;
}

// File Line: 87
// RVA: 0xAF6460
__int64 __fastcall CAkGainFXParams::SetParam(
        CAkGainFXParams *this,
        __int16 in_ParamID,
        float *in_pValue,
        unsigned int in_ulParamSize)
{
  __int64 result; // rax

  if ( !in_pValue )
    return 31i64;
  if ( in_ParamID )
  {
    if ( in_ParamID == 1 )
    {
      this->m_Params.fLFEGain = *in_pValue;
      return 1i64;
    }
    else
    {
      return 31i64;
    }
  }
  else
  {
    result = 1i64;
    this->m_Params.fFullbandGain = *in_pValue;
  }
  return result;
}


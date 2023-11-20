// File Line: 19
// RVA: 0xA35810
AK::IAkPluginParam *__fastcall CreateMP3SourceParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 16ui64);
  if ( !result )
    return 0i64;
  result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable';
  result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkPluginParam::`vftable';
  result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFxSrcMP3Params::`vftable';
  return result;
}

// File Line: 43
// RVA: 0xA356D0
AK::IAkPluginParam *__fastcall CAkFxSrcMP3Params::Clone(CAkFxSrcMP3Params *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkFxSrcMP3Params *v2; // rbx
  AK::IAkPluginParam *result; // rax

  v2 = this;
  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 16ui64);
  if ( !result )
    return 0i64;
  result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable';
  result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkPluginParam::`vftable';
  result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFxSrcMP3Params::`vftable';
  LODWORD(result[1].vfptr) = v2->m_Params.uToken;
  return result;
}

// File Line: 52
// RVA: 0xA360B0
__int64 __fastcall CAkFxSrcMP3Params::Init(CAkFxSrcMP3Params *this, AK::IAkPluginMemAlloc *in_pAllocator, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkFxSrcMP3Params *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  this->m_Params.uToken = 0;
  return 1i64;
}

// File Line: 74
// RVA: 0xA36530
signed __int64 __fastcall CAkFxSrcMP3Params::SetParamsBlock(CAkFxSrcMP3Params *this, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  this->m_Params.uToken = *(_DWORD *)in_pParamsBlock;
  return 1i64;
}

// File Line: 87
// RVA: 0xA36510
signed __int64 __fastcall CAkFxSrcMP3Params::SetParam(CAkFxSrcMP3Params *this, __int16 in_ParamID, const void *in_pValue, unsigned int in_ulParamSize)
{
  if ( !in_pValue || in_ParamID )
    return 31i64;
  this->m_Params.uToken = *(_DWORD *)in_pValue;
  return 1i64;
}


// File Line: 19
// RVA: 0xACFCC0
AK::IAkPluginParam *__fastcall CreateCompressorFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 32ui64);
  if ( result )
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkCompressorFXParams::`vftable;
  return result;
}

// File Line: 26
// RVA: 0xACFCF0
void __fastcall CAkCompressorFXParams::CAkCompressorFXParams(CAkCompressorFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkCompressorFXParams::`vftable;
}

// File Line: 30
// RVA: 0xACFD10
void __fastcall CAkCompressorFXParams::~CAkCompressorFXParams(CAkCompressorFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
}

// File Line: 35
// RVA: 0xACFD30
void __fastcall CAkCompressorFXParams::CAkCompressorFXParams(CAkCompressorFXParams *this, CAkCompressorFXParams *in_rCopy)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkCompressorFXParams::`vftable;
  this->m_Params.fThreshold = in_rCopy->m_Params.fThreshold;
  this->m_Params.fRatio = in_rCopy->m_Params.fRatio;
  this->m_Params.fAttack = in_rCopy->m_Params.fAttack;
  this->m_Params.fRelease = in_rCopy->m_Params.fRelease;
  this->m_Params.fOutputLevel = in_rCopy->m_Params.fOutputLevel;
  *(_DWORD *)&this->m_Params.bProcessLFE = *(_DWORD *)&in_rCopy->m_Params.bProcessLFE;
}

// File Line: 41
// RVA: 0xACFD70
AK::IAkPluginParam *__fastcall CAkCompressorFXParams::Clone(CAkCompressorFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkCompressorFXParams *v2; // rbx
  AK::IAkPluginParam *result; // rax

  v2 = this;
  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 32ui64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkCompressorFXParams::`vftable;
    *(float *)&result[1].vfptr = v2->m_Params.fThreshold;
    HIDWORD(result[1].vfptr) = LODWORD(v2->m_Params.fRatio);
    *(float *)&result[2].vfptr = v2->m_Params.fAttack;
    HIDWORD(result[2].vfptr) = LODWORD(v2->m_Params.fRelease);
    *(float *)&result[3].vfptr = v2->m_Params.fOutputLevel;
    HIDWORD(result[3].vfptr) = *(_DWORD *)&v2->m_Params.bProcessLFE;
  }
  return result;
}

// File Line: 50
// RVA: 0xACFDE0
__int64 __fastcall CAkCompressorFXParams::Init(CAkCompressorFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkCompressorFXParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  this->m_Params.fThreshold = -12.0;
  this->m_Params.fRatio = 4.0;
  this->m_Params.fAttack = 0.0099999998;
  this->m_Params.fRelease = 0.1;
  this->m_Params.fOutputLevel = 1.0;
  *(_WORD *)&this->m_Params.bProcessLFE = 257;
  return 1i64;
}

// File Line: 69
// RVA: 0xACFE30
signed __int64 __fastcall CAkCompressorFXParams::Term(CAkCompressorFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkCompressorFXParams *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
  {
    this->vfptr->__vecDelDtor((AK::IAkRTPCSubscriber *)this, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 79
// RVA: 0xACFE70
signed __int64 __fastcall CAkCompressorFXParams::SetParamsBlock(CAkCompressorFXParams *this, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  char *v3; // rbx
  CAkCompressorFXParams *v4; // rdi

  v3 = (char *)in_pParamsBlock + 4;
  v4 = this;
  this->m_Params.fThreshold = *(float *)in_pParamsBlock;
  this->m_Params.fRatio = *((float *)in_pParamsBlock + 1);
  this->m_Params.fAttack = *((float *)in_pParamsBlock + 2);
  this->m_Params.fRelease = *((float *)in_pParamsBlock + 3);
  this->m_Params.fOutputLevel = powf(10.0, *((float *)in_pParamsBlock + 4) * 0.050000001);
  v4->m_Params.bProcessLFE = v3[16];
  v4->m_Params.bChannelLink = v3[17];
  return 1i64;
}

// File Line: 97
// RVA: 0xACFEF0
signed __int64 __fastcall CAkCompressorFXParams::SetParam(CAkCompressorFXParams *this, __int16 in_ParamID, const void *in_pValue, unsigned int in_ulParamSize)
{
  CAkCompressorFXParams *v4; // rbx
  signed __int64 result; // rax
  float v6; // xmm0_4

  v4 = this;
  if ( !in_pValue )
    return 31i64;
  switch ( in_ParamID )
  {
    case 0:
      this->m_Params.fThreshold = *(float *)in_pValue;
      result = 1i64;
      break;
    case 1:
      this->m_Params.fRatio = *(float *)in_pValue;
      result = 1i64;
      break;
    case 2:
      this->m_Params.fAttack = *(float *)in_pValue;
      result = 1i64;
      break;
    case 3:
      this->m_Params.fRelease = *(float *)in_pValue;
      result = 1i64;
      break;
    case 4:
      v6 = powf(10.0, *(float *)in_pValue * 0.050000001);
      result = 1i64;
      v4->m_Params.fOutputLevel = v6;
      break;
    case 5:
      this->m_Params.bProcessLFE = *(_BYTE *)in_pValue;
      result = 1i64;
      break;
    case 6:
      this->m_Params.bChannelLink = *(_BYTE *)in_pValue;
      result = 1i64;
      break;
    default:
      result = 31i64;
      break;
  }
  return result;
}


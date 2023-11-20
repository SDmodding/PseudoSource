// File Line: 19
// RVA: 0xAF5310
AK::IAkPluginParam *__fastcall CreateMeterFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 40ui64);
  if ( result )
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkMeterFXParams::`vftable';
  return result;
}

// File Line: 26
// RVA: 0xAF5340
void __fastcall CAkMeterFXParams::CAkMeterFXParams(CAkMeterFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkMeterFXParams::`vftable';
}

// File Line: 30
// RVA: 0xAF5360
void __fastcall CAkMeterFXParams::~CAkMeterFXParams(CAkMeterFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable';
}

// File Line: 35
// RVA: 0xAF5380
void __fastcall CAkMeterFXParams::CAkMeterFXParams(CAkMeterFXParams *this, CAkMeterFXParams *in_rCopy)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkMeterFXParams::`vftable';
  this->RTPC.fAttack = in_rCopy->RTPC.fAttack;
  this->RTPC.fRelease = in_rCopy->RTPC.fRelease;
  this->RTPC.fMin = in_rCopy->RTPC.fMin;
  this->RTPC.fMax = in_rCopy->RTPC.fMax;
  this->RTPC.fHold = in_rCopy->RTPC.fHold;
  this->NonRTPC = in_rCopy->NonRTPC;
}

// File Line: 42
// RVA: 0xAF53C0
AK::IAkPluginParam *__fastcall CAkMeterFXParams::Clone(CAkMeterFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkMeterFXParams *v2; // rbx
  AK::IAkPluginParam *result; // rax

  v2 = this;
  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 40ui64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkMeterFXParams::`vftable';
    *(float *)&result[1].vfptr = v2->RTPC.fAttack;
    HIDWORD(result[1].vfptr) = LODWORD(v2->RTPC.fRelease);
    *(float *)&result[2].vfptr = v2->RTPC.fMin;
    HIDWORD(result[2].vfptr) = LODWORD(v2->RTPC.fMax);
    *(float *)&result[3].vfptr = v2->RTPC.fHold;
    *(AkMeterNonRTPCParams *)((char *)result + 28) = v2->NonRTPC;
  }
  return result;
}

// File Line: 52
// RVA: 0xAF5430
__int64 __fastcall CAkMeterFXParams::Init(CAkMeterFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  __int64 result; // rax

  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkMeterFXParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  this->RTPC.fRelease = 0.1;
  this->RTPC.fMin = -48.0;
  this->RTPC.fAttack = 0.0;
  this->NonRTPC = 0i64;
  result = 1i64;
  *(_QWORD *)&this->RTPC.fMax = 1086324736i64;
  return result;
}

// File Line: 72
// RVA: 0xAF5470
signed __int64 __fastcall CAkMeterFXParams::Term(CAkMeterFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkMeterFXParams *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
  {
    this->vfptr->__vecDelDtor((AK::IAkRTPCSubscriber *)this, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 82
// RVA: 0xAF54B0
signed __int64 __fastcall CAkMeterFXParams::SetParamsBlock(CAkMeterFXParams *this, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  this->RTPC.fAttack = *(float *)in_pParamsBlock;
  this->RTPC.fRelease = *((float *)in_pParamsBlock + 1);
  this->RTPC.fMin = *((float *)in_pParamsBlock + 2);
  this->RTPC.fMax = *((float *)in_pParamsBlock + 3);
  this->RTPC.fHold = *((float *)in_pParamsBlock + 4);
  this->NonRTPC.eMode = *((unsigned __int8 *)in_pParamsBlock + 20);
  this->NonRTPC.uGameParamID = *(_DWORD *)((char *)in_pParamsBlock + 21);
  return 1i64;
}

// File Line: 105
// RVA: 0xAF5500
signed __int64 __fastcall CAkMeterFXParams::SetParam(CAkMeterFXParams *this, __int16 in_ParamID, const void *in_pValue, unsigned int in_ulParamSize)
{
  signed __int64 result; // rax

  if ( in_ParamID > 0x7FFF )
    return 31i64;
  if ( in_ParamID == 0x7FFF )
  {
    this->NonRTPC.uGameParamID = *(_DWORD *)in_pValue;
    result = 1i64;
  }
  else
  {
    switch ( in_ParamID )
    {
      case 0:
        result = 1i64;
        this->RTPC.fAttack = *(float *)in_pValue;
        break;
      case 1:
        this->RTPC.fRelease = *(float *)in_pValue;
        result = 1i64;
        break;
      case 2:
        this->NonRTPC.eMode = *(_DWORD *)in_pValue;
        result = 1i64;
        break;
      case 4:
        this->RTPC.fMin = *(float *)in_pValue;
        result = 1i64;
        break;
      case 5:
        this->RTPC.fMax = *(float *)in_pValue;
        result = 1i64;
        break;
      case 6:
        this->RTPC.fHold = *(float *)in_pValue;
        result = 1i64;
        break;
      default:
        return 31i64;
    }
  }
  return result;
}


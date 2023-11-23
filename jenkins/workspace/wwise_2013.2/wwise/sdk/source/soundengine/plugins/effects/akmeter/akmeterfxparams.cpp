// File Line: 19
// RVA: 0xAF5310
AK::IAkPluginParam *__fastcall CreateMeterFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 40i64);
  if ( result )
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkMeterFXParams::`vftable;
  return result;
}

// File Line: 26
// RVA: 0xAF5340
void __fastcall CAkMeterFXParams::CAkMeterFXParams(CAkMeterFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkMeterFXParams::`vftable;
}

// File Line: 30
// RVA: 0xAF5360
void __fastcall CAkMeterFXParams::~CAkMeterFXParams(CAkMeterFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
}

// File Line: 35
// RVA: 0xAF5380
void __fastcall CAkMeterFXParams::CAkMeterFXParams(CAkMeterFXParams *this, CAkMeterFXParams *in_rCopy)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkMeterFXParams::`vftable;
  this->AkMeterFXParams = in_rCopy->AkMeterFXParams;
}

// File Line: 42
// RVA: 0xAF53C0
AK::IAkPluginParam *__fastcall CAkMeterFXParams::Clone(CAkMeterFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 40i64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkMeterFXParams::`vftable;
    *(float *)&result[1].vfptr = this->RTPC.fAttack;
    HIDWORD(result[1].vfptr) = LODWORD(this->RTPC.fRelease);
    *(float *)&result[2].vfptr = this->RTPC.fMin;
    HIDWORD(result[2].vfptr) = LODWORD(this->RTPC.fMax);
    *(float *)&result[3].vfptr = this->RTPC.fHold;
    *(AkMeterNonRTPCParams *)((char *)result + 28) = this->NonRTPC;
  }
  return result;
}

// File Line: 52
// RVA: 0xAF5430
__int64 __fastcall CAkMeterFXParams::Init(
        CAkMeterFXParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        const void *in_pParamsBlock,
        unsigned int in_ulBlockSize)
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
__int64 __fastcall CAkMeterFXParams::Term(CAkMeterFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 82
// RVA: 0xAF54B0
__int64 __fastcall CAkMeterFXParams::SetParamsBlock(
        CAkMeterFXParams *this,
        unsigned __int8 *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  this->RTPC.fAttack = *(float *)in_pParamsBlock;
  this->RTPC.fRelease = *((float *)in_pParamsBlock + 1);
  this->RTPC.fMin = *((float *)in_pParamsBlock + 2);
  this->RTPC.fMax = *((float *)in_pParamsBlock + 3);
  this->RTPC.fHold = *((float *)in_pParamsBlock + 4);
  this->NonRTPC.eMode = in_pParamsBlock[20];
  this->NonRTPC.uGameParamID = *(_DWORD *)(in_pParamsBlock + 21);
  return 1i64;
}

// File Line: 105
// RVA: 0xAF5500
__int64 __fastcall CAkMeterFXParams::SetParam(
        CAkMeterFXParams *this,
        __int16 in_ParamID,
        unsigned int *in_pValue,
        unsigned int in_ulParamSize)
{
  __int64 result; // rax

  if ( in_ParamID == 0x7FFF )
  {
    this->NonRTPC.uGameParamID = *in_pValue;
    return 1i64;
  }
  else
  {
    switch ( in_ParamID )
    {
      case 0:
        result = 1i64;
        LODWORD(this->RTPC.fAttack) = *in_pValue;
        break;
      case 1:
        LODWORD(this->RTPC.fRelease) = *in_pValue;
        result = 1i64;
        break;
      case 2:
        this->NonRTPC.eMode = *in_pValue;
        result = 1i64;
        break;
      case 4:
        LODWORD(this->RTPC.fMin) = *in_pValue;
        result = 1i64;
        break;
      case 5:
        LODWORD(this->RTPC.fMax) = *in_pValue;
        result = 1i64;
        break;
      case 6:
        LODWORD(this->RTPC.fHold) = *in_pValue;
        result = 1i64;
        break;
      default:
        result = 31i64;
        break;
    }
  }
  return result;
}


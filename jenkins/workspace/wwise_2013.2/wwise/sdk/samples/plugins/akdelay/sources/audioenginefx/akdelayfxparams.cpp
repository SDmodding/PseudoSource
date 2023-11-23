// File Line: 18
// RVA: 0xACC2F0
AK::IAkPluginParam *__fastcall CreateDelayFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 32i64);
  if ( result )
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkDelayFXParams::`vftable;
  return result;
}

// File Line: 43
// RVA: 0xACC280
AK::IAkPluginParam *__fastcall CAkDelayFXParams::Clone(CAkDelayFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 32i64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkDelayFXParams::`vftable;
    *(float *)&result[1].vfptr = this->RTPC.fFeedback;
    HIDWORD(result[1].vfptr) = LODWORD(this->RTPC.fWetDryMix);
    *(float *)&result[2].vfptr = this->RTPC.fOutputLevel;
    HIDWORD(result[2].vfptr) = *(_DWORD *)&this->RTPC.bFeedbackEnabled;
    BYTE5(result[2].vfptr) = 1;
    result[3].vfptr = (AK::IAkRTPCSubscriberVtbl *)this->NonRTPC;
    BYTE5(result[3].vfptr) = 1;
  }
  return result;
}

// File Line: 52
// RVA: 0xACC320
__int64 __fastcall CAkDelayFXParams::Init(
        CAkDelayFXParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        const void *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  float v5; // xmm0_4
  __int64 result; // rax

  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkDelayFXParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  this->NonRTPC.fDelayTime = 0.5;
  this->RTPC.fFeedback = 0.0;
  this->RTPC.fWetDryMix = 0.5;
  v5 = powf(10.0, 0.0);
  *(_WORD *)&this->RTPC.bFeedbackEnabled = 256;
  *(_WORD *)&this->NonRTPC.bProcessLFE = 257;
  result = 1i64;
  this->RTPC.fOutputLevel = v5;
  return result;
}

// File Line: 71
// RVA: 0xACC550
__int64 __fastcall CAkFxSrcMP3Params::Term(CAkToneGenParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 80
// RVA: 0xACC4B0
__int64 __fastcall CAkDelayFXParams::SetParamsBlock(
        CAkDelayFXParams *this,
        float *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  char *v3; // rbx
  float v5; // xmm7_4
  float v6; // xmm6_4
  char v7; // al

  v3 = (char *)(in_pParamsBlock + 1);
  this->NonRTPC.fDelayTime = *in_pParamsBlock;
  v5 = in_pParamsBlock[1];
  this->RTPC.fFeedback = v5;
  v6 = in_pParamsBlock[2];
  this->RTPC.fWetDryMix = v6;
  this->RTPC.fOutputLevel = powf(10.0, in_pParamsBlock[3] * 0.050000001);
  this->RTPC.bFeedbackEnabled = v3[12];
  v7 = v3[13];
  this->RTPC.fFeedback = v5 * 0.0099999998;
  this->RTPC.fWetDryMix = v6 * 0.0099999998;
  this->NonRTPC.bProcessLFE = v7;
  this->RTPC.bHasChanged = 1;
  this->NonRTPC.bHasChanged = 1;
  return 1i64;
}

// File Line: 106
// RVA: 0xACC390
__int64 __fastcall CAkDelayFXParams::SetParam(
        CAkDelayFXParams *this,
        __int16 in_ParamID,
        float *in_pValue,
        unsigned int in_ulParamSize)
{
  float v5; // ecx
  __int64 result; // rax
  float v7; // xmm0_4
  float v8; // xmm0_4
  char v9; // al

  switch ( in_ParamID )
  {
    case 0:
      v5 = *in_pValue;
      result = 1i64;
      this->NonRTPC.bHasChanged = 1;
      this->NonRTPC.fDelayTime = v5;
      break;
    case 1:
      v7 = *in_pValue;
      result = 1i64;
      this->RTPC.bHasChanged = 1;
      this->RTPC.fFeedback = v7 * 0.0099999998;
      break;
    case 2:
      result = 1i64;
      this->RTPC.fWetDryMix = *in_pValue * 0.0099999998;
      break;
    case 3:
      v8 = powf(10.0, *in_pValue * 0.050000001);
      result = 1i64;
      this->RTPC.fOutputLevel = v8;
      break;
    case 4:
      if ( *in_pValue == 0.0 )
      {
        this->RTPC.bHasChanged = 1;
        this->RTPC.bFeedbackEnabled = 0;
        result = 1i64;
      }
      else
      {
        result = 1i64;
        this->RTPC.bFeedbackEnabled = 1;
        this->RTPC.bHasChanged = 1;
      }
      break;
    case 5:
      v9 = *(_BYTE *)in_pValue;
      this->NonRTPC.bHasChanged = 1;
      this->NonRTPC.bProcessLFE = v9;
      result = 1i64;
      break;
    default:
      result = 31i64;
      break;
  }
  return result;
}


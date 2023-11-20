// File Line: 18
// RVA: 0xACC2F0
AK::IAkPluginParam *__fastcall CreateDelayFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 32ui64);
  if ( result )
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkDelayFXParams::`vftable';
  return result;
}

// File Line: 43
// RVA: 0xACC280
AK::IAkPluginParam *__fastcall CAkDelayFXParams::Clone(CAkDelayFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkDelayFXParams *v2; // rbx
  AK::IAkPluginParam *result; // rax

  v2 = this;
  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 32ui64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkDelayFXParams::`vftable';
    *(float *)&result[1].vfptr = v2->RTPC.fFeedback;
    HIDWORD(result[1].vfptr) = LODWORD(v2->RTPC.fWetDryMix);
    *(float *)&result[2].vfptr = v2->RTPC.fOutputLevel;
    HIDWORD(result[2].vfptr) = *(_DWORD *)&v2->RTPC.bFeedbackEnabled;
    BYTE5(result[2].vfptr) = 1;
    result[3].vfptr = (AK::IAkRTPCSubscriberVtbl *)v2->NonRTPC;
    BYTE5(result[3].vfptr) = 1;
  }
  return result;
}

// File Line: 52
// RVA: 0xACC320
__int64 __fastcall CAkDelayFXParams::Init(CAkDelayFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  CAkDelayFXParams *v4; // rbx
  float v5; // xmm0_4
  __int64 result; // rax

  v4 = this;
  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkDelayFXParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  this->NonRTPC.fDelayTime = 0.5;
  this->RTPC.fFeedback = 0.0;
  this->RTPC.fWetDryMix = 0.5;
  v5 = powf(10.0, 0.0);
  *(_WORD *)&v4->RTPC.bFeedbackEnabled = 256;
  *(_WORD *)&v4->NonRTPC.bProcessLFE = 257;
  result = 1i64;
  v4->RTPC.fOutputLevel = v5;
  return result;
}

// File Line: 71
// RVA: 0xACC550
signed __int64 __fastcall CAkFxSrcMP3Params::Term(CAkToneGenParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkToneGenParams *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
  {
    this->vfptr->__vecDelDtor((AK::IAkRTPCSubscriber *)this, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 80
// RVA: 0xACC4B0
signed __int64 __fastcall CAkDelayFXParams::SetParamsBlock(CAkDelayFXParams *this, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  char *v3; // rbx
  CAkDelayFXParams *v4; // rdi
  float v5; // xmm7_4
  float v6; // xmm6_4
  char v7; // al

  v3 = (char *)in_pParamsBlock + 4;
  this->NonRTPC.fDelayTime = *(float *)in_pParamsBlock;
  v4 = this;
  v5 = *((float *)in_pParamsBlock + 1);
  this->RTPC.fFeedback = v5;
  v6 = *((float *)in_pParamsBlock + 2);
  this->RTPC.fWetDryMix = v6;
  this->RTPC.fOutputLevel = powf(10.0, *((float *)in_pParamsBlock + 3) * 0.050000001);
  v4->RTPC.bFeedbackEnabled = v3[12];
  v7 = v3[13];
  v4->RTPC.fFeedback = v5 * 0.0099999998;
  v4->RTPC.fWetDryMix = v6 * 0.0099999998;
  v4->NonRTPC.bProcessLFE = v7;
  v4->RTPC.bHasChanged = 1;
  v4->NonRTPC.bHasChanged = 1;
  return 1i64;
}

// File Line: 106
// RVA: 0xACC390
signed __int64 __fastcall CAkDelayFXParams::SetParam(CAkDelayFXParams *this, __int16 in_ParamID, const void *in_pValue, unsigned int in_ulParamSize)
{
  CAkDelayFXParams *v4; // rbx
  float v5; // ecx
  signed __int64 result; // rax
  float v7; // xmm0_4
  float v8; // xmm0_4
  char v9; // al

  v4 = this;
  switch ( 0x40000000 )
  {
    case 0:
      v5 = *(float *)in_pValue;
      result = 1i64;
      v4->NonRTPC.bHasChanged = 1;
      v4->NonRTPC.fDelayTime = v5;
      break;
    case 1:
      v7 = *(float *)in_pValue;
      result = 1i64;
      this->RTPC.bHasChanged = 1;
      this->RTPC.fFeedback = v7 * 0.0099999998;
      break;
    case 2:
      result = 1i64;
      this->RTPC.fWetDryMix = *(float *)in_pValue * 0.0099999998;
      break;
    case 3:
      v8 = powf(10.0, *(float *)in_pValue * 0.050000001);
      result = 1i64;
      v4->RTPC.fOutputLevel = v8;
      break;
    case 4:
      if ( *(float *)in_pValue == 0.0 )
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


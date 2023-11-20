// File Line: 18
// RVA: 0xAF2650
AK::IAkPluginParam *__fastcall CreateTremoloFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 56ui64);
  if ( result )
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkTremoloFXParams::`vftable';
  return result;
}

// File Line: 24
// RVA: 0xAF2680
void __fastcall CAkTremoloFXParams::CAkTremoloFXParams(CAkTremoloFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkTremoloFXParams::`vftable';
}

// File Line: 28
// RVA: 0xAF26A0
void __fastcall CAkTremoloFXParams::~CAkTremoloFXParams(CAkTremoloFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable';
}

// File Line: 33
// RVA: 0xAF26C0
void __fastcall CAkTremoloFXParams::CAkTremoloFXParams(CAkTremoloFXParams *this, CAkTremoloFXParams *in_rCopy)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkTremoloFXParams::`vftable';
  this->m_Params.RTPC.fModDepth = in_rCopy->m_Params.RTPC.fModDepth;
  this->m_Params.RTPC.modParams.lfoParams.eWaveform = in_rCopy->m_Params.RTPC.modParams.lfoParams.eWaveform;
  this->m_Params.RTPC.modParams.lfoParams.fFrequency = in_rCopy->m_Params.RTPC.modParams.lfoParams.fFrequency;
  this->m_Params.RTPC.modParams.lfoParams.fSmooth = in_rCopy->m_Params.RTPC.modParams.lfoParams.fSmooth;
  this->m_Params.RTPC.modParams.lfoParams.fPWM = in_rCopy->m_Params.RTPC.modParams.lfoParams.fPWM;
  this->m_Params.RTPC.modParams.phaseParams.fPhaseOffset = in_rCopy->m_Params.RTPC.modParams.phaseParams.fPhaseOffset;
  this->m_Params.RTPC.modParams.phaseParams.fPhaseSpread = in_rCopy->m_Params.RTPC.modParams.phaseParams.fPhaseSpread;
  this->m_Params.RTPC.modParams.phaseParams.ePhaseMode = in_rCopy->m_Params.RTPC.modParams.phaseParams.ePhaseMode;
  this->m_Params.RTPC.fOutputGain = in_rCopy->m_Params.RTPC.fOutputGain;
  *(_DWORD *)&this->m_Params.RTPC.bHasChanged = *(_DWORD *)&in_rCopy->m_Params.RTPC.bHasChanged;
  *(_DWORD *)&this->m_Params.NonRTPC.bProcessCenter = *(_DWORD *)&in_rCopy->m_Params.NonRTPC.bProcessCenter;
  this->m_Params.NonRTPC.bHasChanged = 1;
  this->m_Params.RTPC.bHasChanged = 1;
}

// File Line: 39
// RVA: 0xAF2AF0
void __fastcall CAkTremoloFXParams::SetDirty(CAkTremoloFXParams *this, bool in_bDirty)
{
  this->m_Params.NonRTPC.bHasChanged = in_bDirty;
  this->m_Params.RTPC.bHasChanged = in_bDirty;
}

// File Line: 46
// RVA: 0xAF2720
AK::IAkPluginParam *__fastcall CAkTremoloFXParams::Clone(CAkTremoloFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkTremoloFXParams *v2; // rbx
  AK::IAkPluginParam *result; // rax

  v2 = this;
  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 56ui64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkTremoloFXParams::`vftable';
    *(float *)&result[1].vfptr = v2->m_Params.RTPC.fModDepth;
    HIDWORD(result[1].vfptr) = v2->m_Params.RTPC.modParams.lfoParams.eWaveform;
    *(float *)&result[2].vfptr = v2->m_Params.RTPC.modParams.lfoParams.fFrequency;
    HIDWORD(result[2].vfptr) = LODWORD(v2->m_Params.RTPC.modParams.lfoParams.fSmooth);
    *(float *)&result[3].vfptr = v2->m_Params.RTPC.modParams.lfoParams.fPWM;
    HIDWORD(result[3].vfptr) = LODWORD(v2->m_Params.RTPC.modParams.phaseParams.fPhaseOffset);
    *(float *)&result[4].vfptr = v2->m_Params.RTPC.modParams.phaseParams.fPhaseSpread;
    HIDWORD(result[4].vfptr) = v2->m_Params.RTPC.modParams.phaseParams.ePhaseMode;
    *(float *)&result[5].vfptr = v2->m_Params.RTPC.fOutputGain;
    HIDWORD(result[5].vfptr) = *(_DWORD *)&v2->m_Params.RTPC.bHasChanged;
    LODWORD(result[6].vfptr) = *(_DWORD *)&v2->m_Params.NonRTPC.bProcessCenter;
    BYTE2(result[6].vfptr) = 1;
    BYTE4(result[5].vfptr) = 1;
  }
  return result;
}

// File Line: 55
// RVA: 0xAF27C0
__int64 __fastcall CAkTremoloFXParams::Init(CAkTremoloFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  __int64 result; // rax

  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkTremoloFXParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  *(_QWORD *)&this->m_Params.RTPC.fModDepth = 1065353216i64;
  *(_QWORD *)&this->m_Params.RTPC.modParams.lfoParams.fFrequency = 1065353216i64;
  *(_QWORD *)&this->m_Params.RTPC.modParams.phaseParams.fPhaseSpread = 0i64;
  *(_QWORD *)&this->m_Params.RTPC.modParams.lfoParams.fPWM = 1056964608i64;
  this->m_Params.RTPC.fOutputGain = 1.0;
  result = 1i64;
  *(_WORD *)&this->m_Params.NonRTPC.bProcessCenter = 257;
  this->m_Params.NonRTPC.bHasChanged = 1;
  this->m_Params.RTPC.bHasChanged = 1;
  return result;
}

// File Line: 80
// RVA: 0xAF2820
signed __int64 __fastcall CAkTremoloFXParams::Term(CAkTremoloFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkTremoloFXParams *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
  {
    this->vfptr->__vecDelDtor((AK::IAkRTPCSubscriber *)this, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 89
// RVA: 0xAF2860
signed __int64 __fastcall CAkTremoloFXParams::SetParamsBlock(CAkTremoloFXParams *this, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  char *v3; // rbx
  CAkTremoloFXParams *v4; // rdi
  float v5; // xmm8_4
  float v6; // xmm7_4
  float v7; // xmm6_4
  char v8; // al
  signed __int64 result; // rax

  v3 = (char *)in_pParamsBlock + 4;
  v4 = this;
  v5 = *(float *)in_pParamsBlock;
  this->m_Params.RTPC.fModDepth = *(float *)in_pParamsBlock;
  this->m_Params.RTPC.modParams.lfoParams.fFrequency = *((float *)in_pParamsBlock + 1);
  this->m_Params.RTPC.modParams.lfoParams.eWaveform = *((_DWORD *)in_pParamsBlock + 2);
  v6 = *((float *)in_pParamsBlock + 3);
  this->m_Params.RTPC.modParams.lfoParams.fSmooth = v6;
  v7 = *((float *)in_pParamsBlock + 4);
  this->m_Params.RTPC.modParams.lfoParams.fPWM = v7;
  this->m_Params.RTPC.modParams.phaseParams.fPhaseOffset = *((float *)in_pParamsBlock + 5);
  this->m_Params.RTPC.modParams.phaseParams.ePhaseMode = *((_DWORD *)in_pParamsBlock + 6);
  this->m_Params.RTPC.modParams.phaseParams.fPhaseSpread = *((float *)in_pParamsBlock + 7);
  this->m_Params.RTPC.fOutputGain = powf(10.0, *((float *)in_pParamsBlock + 8) * 0.050000001);
  v4->m_Params.NonRTPC.bProcessCenter = v3[32];
  v8 = v3[33];
  v4->m_Params.RTPC.fModDepth = v5 * 0.0099999998;
  v4->m_Params.RTPC.modParams.lfoParams.fSmooth = v6 * 0.0099999998;
  v4->m_Params.NonRTPC.bProcessLFE = v8;
  v4->m_Params.NonRTPC.bHasChanged = 1;
  v4->m_Params.RTPC.modParams.lfoParams.fPWM = v7 * 0.0099999998;
  result = 1i64;
  v4->m_Params.RTPC.bHasChanged = 1;
  return result;
}

// File Line: 122
// RVA: 0xAF2950
signed __int64 __fastcall CAkTremoloFXParams::SetParam(CAkTremoloFXParams *this, __int16 in_ParamID, const void *in_pValue, unsigned int in_ulParamSize)
{
  CAkTremoloFXParams *v4; // rbx
  signed __int64 result; // rax
  float v6; // xmm0_4
  float v7; // eax
  DSP::LFO::Waveform v8; // eax
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  bool v12; // zf

  v4 = this;
  if ( !in_pValue )
    return 31i64;
  switch ( in_ParamID )
  {
    case 1:
      v6 = *(float *)in_pValue;
      result = 1i64;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.fModDepth = v6 * 0.0099999998;
      break;
    case 2:
      v7 = *(float *)in_pValue;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.modParams.lfoParams.fFrequency = v7;
      result = 1i64;
      break;
    case 3:
      v8 = (signed int)*(float *)in_pValue;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.modParams.lfoParams.eWaveform = v8;
      result = 1i64;
      break;
    case 4:
      v9 = *(float *)in_pValue;
      result = 1i64;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.modParams.lfoParams.fSmooth = v9 * 0.0099999998;
      break;
    case 5:
      v10 = *(float *)in_pValue;
      result = 1i64;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.modParams.lfoParams.fPWM = v10 * 0.0099999998;
      break;
    case 6:
      this->m_Params.RTPC.modParams.phaseParams.fPhaseOffset = *(float *)in_pValue;
      result = 1i64;
      break;
    case 7:
      this->m_Params.RTPC.modParams.phaseParams.ePhaseMode = (signed int)*(float *)in_pValue;
      result = 1i64;
      break;
    case 8:
      this->m_Params.RTPC.modParams.phaseParams.fPhaseSpread = *(float *)in_pValue;
      result = 1i64;
      break;
    case 9:
      v11 = powf(10.0, *(float *)in_pValue * 0.050000001);
      v4->m_Params.RTPC.bHasChanged = 1;
      result = 1i64;
      v4->m_Params.RTPC.fOutputGain = v11;
      break;
    case 10:
      v12 = *(_BYTE *)in_pValue == 0;
      this->m_Params.NonRTPC.bHasChanged = 1;
      this->m_Params.NonRTPC.bProcessCenter = !v12;
      result = 1i64;
      break;
    case 11:
      v12 = *(_BYTE *)in_pValue == 0;
      this->m_Params.NonRTPC.bHasChanged = 1;
      this->m_Params.NonRTPC.bProcessLFE = !v12;
      goto LABEL_15;
    default:
LABEL_15:
      result = 1i64;
      break;
  }
  return result;
}


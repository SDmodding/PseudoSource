// File Line: 18
// RVA: 0xAF9280
AK::IAkPluginParam *__fastcall CreateFlangerFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 72ui64);
  if ( result )
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFlangerFXParams::`vftable;
  return result;
}

// File Line: 24
// RVA: 0xAF92B0
void __fastcall CAkFlangerFXParams::CAkFlangerFXParams(CAkFlangerFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFlangerFXParams::`vftable;
}

// File Line: 28
// RVA: 0xAF92D0
void __fastcall CAkFlangerFXParams::~CAkFlangerFXParams(CAkFlangerFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
}

// File Line: 33
// RVA: 0xAF92F0
void __fastcall CAkFlangerFXParams::CAkFlangerFXParams(CAkFlangerFXParams *this, CAkFlangerFXParams *in_rCopy)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFlangerFXParams::`vftable;
  this->m_Params.RTPC.fDryLevel = in_rCopy->m_Params.RTPC.fDryLevel;
  this->m_Params.RTPC.fFfwdLevel = in_rCopy->m_Params.RTPC.fFfwdLevel;
  this->m_Params.RTPC.fFbackLevel = in_rCopy->m_Params.RTPC.fFbackLevel;
  this->m_Params.RTPC.fModDepth = in_rCopy->m_Params.RTPC.fModDepth;
  this->m_Params.RTPC.modParams.lfoParams.eWaveform = in_rCopy->m_Params.RTPC.modParams.lfoParams.eWaveform;
  this->m_Params.RTPC.modParams.lfoParams.fFrequency = in_rCopy->m_Params.RTPC.modParams.lfoParams.fFrequency;
  this->m_Params.RTPC.modParams.lfoParams.fSmooth = in_rCopy->m_Params.RTPC.modParams.lfoParams.fSmooth;
  this->m_Params.RTPC.modParams.lfoParams.fPWM = in_rCopy->m_Params.RTPC.modParams.lfoParams.fPWM;
  this->m_Params.RTPC.modParams.phaseParams.fPhaseOffset = in_rCopy->m_Params.RTPC.modParams.phaseParams.fPhaseOffset;
  this->m_Params.RTPC.modParams.phaseParams.fPhaseSpread = in_rCopy->m_Params.RTPC.modParams.phaseParams.fPhaseSpread;
  this->m_Params.RTPC.modParams.phaseParams.ePhaseMode = in_rCopy->m_Params.RTPC.modParams.phaseParams.ePhaseMode;
  this->m_Params.RTPC.fOutputLevel = in_rCopy->m_Params.RTPC.fOutputLevel;
  this->m_Params.RTPC.fWetDryMix = in_rCopy->m_Params.RTPC.fWetDryMix;
  *(_DWORD *)&this->m_Params.RTPC.bHasChanged = *(_DWORD *)&in_rCopy->m_Params.RTPC.bHasChanged;
  this->m_Params.NonRTPC.fDelayTime = in_rCopy->m_Params.NonRTPC.fDelayTime;
  *(_DWORD *)&this->m_Params.NonRTPC.bEnableLFO = *(_DWORD *)&in_rCopy->m_Params.NonRTPC.bEnableLFO;
  this->m_Params.NonRTPC.bHasChanged = 1;
  this->m_Params.RTPC.bHasChanged = 1;
}

// File Line: 39
// RVA: 0xAF9820
void __fastcall CAkFlangerFXParams::SetDirty(CAkFlangerFXParams *this, bool in_bDirty)
{
  this->m_Params.NonRTPC.bHasChanged = in_bDirty;
  this->m_Params.RTPC.bHasChanged = in_bDirty;
}

// File Line: 46
// RVA: 0xAF9370
AK::IAkPluginParam *__fastcall CAkFlangerFXParams::Clone(CAkFlangerFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkFlangerFXParams *v2; // rbx
  AK::IAkPluginParam *result; // rax

  v2 = this;
  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 72ui64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFlangerFXParams::`vftable;
    *(float *)&result[1].vfptr = v2->m_Params.RTPC.fDryLevel;
    HIDWORD(result[1].vfptr) = LODWORD(v2->m_Params.RTPC.fFfwdLevel);
    *(float *)&result[2].vfptr = v2->m_Params.RTPC.fFbackLevel;
    HIDWORD(result[2].vfptr) = LODWORD(v2->m_Params.RTPC.fModDepth);
    LODWORD(result[3].vfptr) = v2->m_Params.RTPC.modParams.lfoParams.eWaveform;
    HIDWORD(result[3].vfptr) = LODWORD(v2->m_Params.RTPC.modParams.lfoParams.fFrequency);
    *(float *)&result[4].vfptr = v2->m_Params.RTPC.modParams.lfoParams.fSmooth;
    HIDWORD(result[4].vfptr) = LODWORD(v2->m_Params.RTPC.modParams.lfoParams.fPWM);
    *(float *)&result[5].vfptr = v2->m_Params.RTPC.modParams.phaseParams.fPhaseOffset;
    HIDWORD(result[5].vfptr) = LODWORD(v2->m_Params.RTPC.modParams.phaseParams.fPhaseSpread);
    LODWORD(result[6].vfptr) = v2->m_Params.RTPC.modParams.phaseParams.ePhaseMode;
    HIDWORD(result[6].vfptr) = LODWORD(v2->m_Params.RTPC.fOutputLevel);
    *(float *)&result[7].vfptr = v2->m_Params.RTPC.fWetDryMix;
    HIDWORD(result[7].vfptr) = *(_DWORD *)&v2->m_Params.RTPC.bHasChanged;
    *(float *)&result[8].vfptr = v2->m_Params.NonRTPC.fDelayTime;
    HIDWORD(result[8].vfptr) = *(_DWORD *)&v2->m_Params.NonRTPC.bEnableLFO;
    HIBYTE(result[8].vfptr) = 1;
    BYTE4(result[7].vfptr) = 1;
  }
  return result;
}

// File Line: 55
// RVA: 0xAF9430
__int64 __fastcall CAkFlangerFXParams::Init(CAkFlangerFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  __int64 result; // rax

  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkFlangerFXParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  this->m_Params.NonRTPC.fDelayTime = 3.0;
  this->m_Params.RTPC.modParams.lfoParams.fFrequency = 1.0;
  *(_QWORD *)&this->m_Params.RTPC.fDryLevel = 0i64;
  *(_QWORD *)&this->m_Params.RTPC.fFbackLevel = 0i64;
  this->m_Params.RTPC.modParams.lfoParams.eWaveform = 0;
  *(_QWORD *)&this->m_Params.RTPC.modParams.phaseParams.fPhaseOffset = 0i64;
  this->m_Params.RTPC.modParams.phaseParams.ePhaseMode = 0;
  *(_DWORD *)&this->m_Params.NonRTPC.bEnableLFO = 16777217;
  result = 1i64;
  this->m_Params.RTPC.fWetDryMix = 100.0;
  this->m_Params.RTPC.fOutputLevel = 1.0;
  this->m_Params.RTPC.bHasChanged = 1;
  return result;
}

// File Line: 89
// RVA: 0xAF9490
signed __int64 __fastcall CAkFlangerFXParams::Term(CAkFlangerFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkFlangerFXParams *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
  {
    this->vfptr->__vecDelDtor((AK::IAkRTPCSubscriber *)this, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 98
// RVA: 0xAF94D0
signed __int64 __fastcall CAkFlangerFXParams::SetParamsBlock(CAkFlangerFXParams *this, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  float *v3; // rbx
  CAkFlangerFXParams *v4; // rdi
  float v5; // xmm4_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm0_4

  v3 = (float *)((char *)in_pParamsBlock + 4);
  v4 = this;
  this->m_Params.NonRTPC.fDelayTime = *(float *)in_pParamsBlock;
  this->m_Params.RTPC.fDryLevel = *((float *)in_pParamsBlock + 1);
  this->m_Params.RTPC.fFfwdLevel = *((float *)in_pParamsBlock + 2);
  this->m_Params.RTPC.fFbackLevel = *((float *)in_pParamsBlock + 3);
  v5 = *((float *)in_pParamsBlock + 4);
  this->m_Params.RTPC.fModDepth = v5;
  this->m_Params.RTPC.modParams.lfoParams.fFrequency = *((float *)in_pParamsBlock + 5);
  this->m_Params.RTPC.modParams.lfoParams.eWaveform = *((_DWORD *)in_pParamsBlock + 6);
  v6 = *((float *)in_pParamsBlock + 7);
  this->m_Params.RTPC.modParams.lfoParams.fSmooth = v6;
  v7 = *((float *)in_pParamsBlock + 8);
  this->m_Params.RTPC.modParams.lfoParams.fPWM = v7;
  this->m_Params.RTPC.modParams.phaseParams.fPhaseOffset = *((float *)in_pParamsBlock + 9);
  this->m_Params.RTPC.modParams.phaseParams.ePhaseMode = *((_DWORD *)in_pParamsBlock + 10);
  v8 = *((float *)in_pParamsBlock + 11);
  this->m_Params.RTPC.fModDepth = v5 * 0.0099999998;
  this->m_Params.RTPC.modParams.lfoParams.fSmooth = v6 * 0.0099999998;
  this->m_Params.RTPC.modParams.phaseParams.fPhaseSpread = v8;
  this->m_Params.RTPC.modParams.lfoParams.fPWM = v7 * 0.0099999998;
  this->m_Params.RTPC.fOutputLevel = powf(10.0, *((float *)in_pParamsBlock + 12) * 0.050000001);
  v4->m_Params.RTPC.fWetDryMix = v3[12];
  v4->m_Params.NonRTPC.bEnableLFO = *((_BYTE *)v3 + 52);
  v4->m_Params.NonRTPC.bProcessCenter = *((_BYTE *)v3 + 53);
  v4->m_Params.NonRTPC.bProcessLFE = *((_BYTE *)v3 + 54);
  v4->m_Params.NonRTPC.bHasChanged = 1;
  v4->m_Params.RTPC.bHasChanged = 1;
  return 1i64;
}

// File Line: 140
// RVA: 0xAF95D0
signed __int64 __fastcall CAkFlangerFXParams::SetParam(CAkFlangerFXParams *this, __int16 in_ParamID, const void *in_pValue, unsigned int in_ulParamSize)
{
  CAkFlangerFXParams *v4; // rbx
  signed __int64 result; // rax
  float v6; // eax
  float v7; // eax
  float v8; // eax
  float v9; // xmm0_4
  float v10; // eax
  DSP::LFO::Waveform v11; // eax
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // eax
  bool v16; // zf
  float v17; // eax

  v4 = this;
  if ( !in_pValue )
    return 31i64;
  switch ( in_ParamID )
  {
    case 0:
      v17 = *(float *)in_pValue;
      this->m_Params.NonRTPC.bHasChanged = 1;
      this->m_Params.NonRTPC.fDelayTime = v17;
      goto LABEL_21;
    case 1:
      v15 = *(float *)in_pValue;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.fWetDryMix = v15;
      result = 1i64;
      break;
    case 2:
      v16 = *(_BYTE *)in_pValue == 0;
      this->m_Params.NonRTPC.bHasChanged = 1;
      this->m_Params.NonRTPC.bProcessLFE = !v16;
      result = 1i64;
      break;
    case 5:
      v6 = *(float *)in_pValue;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.fDryLevel = v6;
      result = 1i64;
      break;
    case 6:
      v7 = *(float *)in_pValue;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.fFfwdLevel = v7;
      result = 1i64;
      break;
    case 7:
      v8 = *(float *)in_pValue;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.fFbackLevel = v8;
      result = 1i64;
      break;
    case 8:
      v11 = (signed int)*(float *)in_pValue;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.modParams.lfoParams.eWaveform = v11;
      result = 1i64;
      break;
    case 9:
      v10 = *(float *)in_pValue;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.modParams.lfoParams.fFrequency = v10;
      result = 1i64;
      break;
    case 10:
      v9 = *(float *)in_pValue;
      result = 1i64;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.fModDepth = v9 * 0.0099999998;
      break;
    case 14:
      v16 = *(_BYTE *)in_pValue == 0;
      this->m_Params.NonRTPC.bHasChanged = 1;
      this->m_Params.NonRTPC.bEnableLFO = !v16;
      result = 1i64;
      break;
    case 16:
      v14 = powf(10.0, *(float *)in_pValue * 0.050000001);
      v4->m_Params.RTPC.bHasChanged = 1;
      result = 1i64;
      v4->m_Params.RTPC.fOutputLevel = v14;
      break;
    case 17:
      v16 = *(_BYTE *)in_pValue == 0;
      this->m_Params.NonRTPC.bHasChanged = 1;
      this->m_Params.NonRTPC.bProcessCenter = !v16;
      result = 1i64;
      break;
    case 18:
      v12 = *(float *)in_pValue;
      result = 1i64;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.modParams.lfoParams.fSmooth = v12 * 0.0099999998;
      break;
    case 19:
      v13 = *(float *)in_pValue;
      result = 1i64;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.modParams.lfoParams.fPWM = v13 * 0.0099999998;
      break;
    case 20:
      this->m_Params.RTPC.modParams.phaseParams.fPhaseOffset = *(float *)in_pValue;
      result = 1i64;
      break;
    case 21:
      this->m_Params.RTPC.modParams.phaseParams.ePhaseMode = (signed int)*(float *)in_pValue;
      result = 1i64;
      break;
    case 22:
      this->m_Params.RTPC.modParams.phaseParams.fPhaseSpread = *(float *)in_pValue;
      result = 1i64;
      break;
    default:
LABEL_21:
      result = 1i64;
      break;
  }
  return result;
}


// File Line: 18
// RVA: 0xAF9280
AK::IAkPluginParam *__fastcall CreateFlangerFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 72i64);
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
  this->m_Params = in_rCopy->m_Params;
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
AK::IAkPluginParam *__fastcall CAkFlangerFXParams::Clone(
        CAkFlangerFXParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 72i64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFlangerFXParams::`vftable;
    *(float *)&result[1].vfptr = this->m_Params.RTPC.fDryLevel;
    HIDWORD(result[1].vfptr) = LODWORD(this->m_Params.RTPC.fFfwdLevel);
    *(float *)&result[2].vfptr = this->m_Params.RTPC.fFbackLevel;
    HIDWORD(result[2].vfptr) = LODWORD(this->m_Params.RTPC.fModDepth);
    LODWORD(result[3].vfptr) = this->m_Params.RTPC.modParams.lfoParams.eWaveform;
    HIDWORD(result[3].vfptr) = LODWORD(this->m_Params.RTPC.modParams.lfoParams.fFrequency);
    *(float *)&result[4].vfptr = this->m_Params.RTPC.modParams.lfoParams.fSmooth;
    HIDWORD(result[4].vfptr) = LODWORD(this->m_Params.RTPC.modParams.lfoParams.fPWM);
    *(float *)&result[5].vfptr = this->m_Params.RTPC.modParams.phaseParams.fPhaseOffset;
    HIDWORD(result[5].vfptr) = LODWORD(this->m_Params.RTPC.modParams.phaseParams.fPhaseSpread);
    LODWORD(result[6].vfptr) = this->m_Params.RTPC.modParams.phaseParams.ePhaseMode;
    HIDWORD(result[6].vfptr) = LODWORD(this->m_Params.RTPC.fOutputLevel);
    *(float *)&result[7].vfptr = this->m_Params.RTPC.fWetDryMix;
    HIDWORD(result[7].vfptr) = *(_DWORD *)&this->m_Params.RTPC.bHasChanged;
    *(float *)&result[8].vfptr = this->m_Params.NonRTPC.fDelayTime;
    HIDWORD(result[8].vfptr) = *(_DWORD *)&this->m_Params.NonRTPC.bEnableLFO;
    HIBYTE(result[8].vfptr) = 1;
    BYTE4(result[7].vfptr) = 1;
  }
  return result;
}

// File Line: 55
// RVA: 0xAF9430
__int64 __fastcall CAkFlangerFXParams::Init(
        CAkFlangerFXParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        const void *in_pParamsBlock,
        unsigned int in_ulBlockSize)
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
  this->m_Params.RTPC.modParams.lfoParams.eWaveform = WAVEFORM_SINE;
  *(_QWORD *)&this->m_Params.RTPC.modParams.phaseParams.fPhaseOffset = 0i64;
  this->m_Params.RTPC.modParams.phaseParams.ePhaseMode = PHASE_MODE_LEFT_RIGHT;
  *(_DWORD *)&this->m_Params.NonRTPC.bEnableLFO = 16777217;
  result = 1i64;
  this->m_Params.RTPC.fWetDryMix = 100.0;
  this->m_Params.RTPC.fOutputLevel = 1.0;
  this->m_Params.RTPC.bHasChanged = 1;
  return result;
}

// File Line: 89
// RVA: 0xAF9490
__int64 __fastcall CAkFlangerFXParams::Term(CAkFlangerFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 98
// RVA: 0xAF94D0
__int64 __fastcall CAkFlangerFXParams::SetParamsBlock(
        CAkFlangerFXParams *this,
        char *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  float *v3; // rbx
  float v5; // xmm4_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm0_4

  v3 = (float *)(in_pParamsBlock + 4);
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
  this->m_Params.RTPC.fWetDryMix = v3[12];
  this->m_Params.NonRTPC.bEnableLFO = *((_BYTE *)v3 + 52);
  this->m_Params.NonRTPC.bProcessCenter = *((_BYTE *)v3 + 53);
  this->m_Params.NonRTPC.bProcessLFE = *((_BYTE *)v3 + 54);
  this->m_Params.NonRTPC.bHasChanged = 1;
  this->m_Params.RTPC.bHasChanged = 1;
  return 1i64;
}

// File Line: 140
// RVA: 0xAF95D0
__int64 __fastcall CAkFlangerFXParams::SetParam(
        CAkFlangerFXParams *this,
        __int16 in_ParamID,
        float *in_pValue,
        unsigned int in_ulParamSize)
{
  __int64 result; // rax
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

  if ( !in_pValue )
    return 31i64;
  switch ( in_ParamID )
  {
    case 0:
      v17 = *in_pValue;
      this->m_Params.NonRTPC.bHasChanged = 1;
      this->m_Params.NonRTPC.fDelayTime = v17;
      goto LABEL_21;
    case 1:
      v15 = *in_pValue;
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
      v6 = *in_pValue;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.fDryLevel = v6;
      result = 1i64;
      break;
    case 6:
      v7 = *in_pValue;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.fFfwdLevel = v7;
      result = 1i64;
      break;
    case 7:
      v8 = *in_pValue;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.fFbackLevel = v8;
      result = 1i64;
      break;
    case 8:
      v11 = (int)*in_pValue;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.modParams.lfoParams.eWaveform = v11;
      result = 1i64;
      break;
    case 9:
      v10 = *in_pValue;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.modParams.lfoParams.fFrequency = v10;
      result = 1i64;
      break;
    case 10:
      v9 = *in_pValue;
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
      v14 = powf(10.0, *in_pValue * 0.050000001);
      this->m_Params.RTPC.bHasChanged = 1;
      result = 1i64;
      this->m_Params.RTPC.fOutputLevel = v14;
      break;
    case 17:
      v16 = *(_BYTE *)in_pValue == 0;
      this->m_Params.NonRTPC.bHasChanged = 1;
      this->m_Params.NonRTPC.bProcessCenter = !v16;
      result = 1i64;
      break;
    case 18:
      v12 = *in_pValue;
      result = 1i64;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.modParams.lfoParams.fSmooth = v12 * 0.0099999998;
      break;
    case 19:
      v13 = *in_pValue;
      result = 1i64;
      this->m_Params.RTPC.bHasChanged = 1;
      this->m_Params.RTPC.modParams.lfoParams.fPWM = v13 * 0.0099999998;
      break;
    case 20:
      this->m_Params.RTPC.modParams.phaseParams.fPhaseOffset = *in_pValue;
      result = 1i64;
      break;
    case 21:
      this->m_Params.RTPC.modParams.phaseParams.ePhaseMode = (int)*in_pValue;
      result = 1i64;
      break;
    case 22:
      this->m_Params.RTPC.modParams.phaseParams.fPhaseSpread = *in_pValue;
      result = 1i64;
      break;
    default:
LABEL_21:
      result = 1i64;
      break;
  }
  return result;
}


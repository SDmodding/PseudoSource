// File Line: 20
// RVA: 0xAE9D40
AK::IAkPluginParam *__fastcall CreatePitchShifterFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 56i64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkPitchShifterFXParams::`vftable;
    LOWORD(result[1].vfptr) = 0;
    HIDWORD(result[1].vfptr) = 0;
    LODWORD(result[2].vfptr) = 1065353216;
    HIDWORD(result[2].vfptr) = 1148846080;
    LODWORD(result[3].vfptr) = 1065353216;
    *(AK::IAkRTPCSubscriberVtbl **)((char *)&result[3].vfptr + 4) = (AK::IAkRTPCSubscriberVtbl *)1065353216;
    HIDWORD(result[4].vfptr) = 1065353216;
    LODWORD(result[5].vfptr) = 1065353216;
    HIDWORD(result[5].vfptr) = 1112014848;
    LOWORD(result[6].vfptr) = 0;
  }
  return result;
}

// File Line: 26
// RVA: 0xAE9DB0
void __fastcall CAkPitchShifterFXParams::CAkPitchShifterFXParams(CAkPitchShifterFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkPitchShifterFXParams::`vftable;
  this->m_ParamChangeHandler = 0;
  this->m_Params.Voice.Filter.eFilterType = AKFILTERTYPE_LOWPASS;
  this->m_Params.Voice.Filter.fFilterGain = 1.0;
  this->m_Params.Voice.Filter.fFilterFrequency = 1000.0;
  this->m_Params.Voice.Filter.fFilterQFactor = 1.0;
  *(_QWORD *)&this->m_Params.gap0[16] = 1065353216i64;
  *(_WORD *)&this->m_Params.bProcessLFE = 0;
  this->m_Params.fDryLevel = 1.0;
  this->m_Params.fWetLevel = 1.0;
  this->m_Params.fDelayTime = 50.0;
}

// File Line: 30
// RVA: 0xAE9E10
void __fastcall CAkPitchShifterFXParams::~CAkPitchShifterFXParams(CAkPitchShifterFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
}

// File Line: 35
// RVA: 0xAE9E30
void __fastcall CAkPitchShifterFXParams::CAkPitchShifterFXParams(
        CAkPitchShifterFXParams *this,
        CAkPitchShifterFXParams *in_rCopy)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkPitchShifterFXParams::`vftable;
  this->m_ParamChangeHandler = 0;
  this->m_Params.Voice.Filter.eFilterType = AKFILTERTYPE_LOWPASS;
  this->m_Params.Voice.Filter.fFilterGain = 1.0;
  this->m_Params.Voice.Filter.fFilterFrequency = 1000.0;
  this->m_Params.Voice.Filter.fFilterQFactor = 1.0;
  *(_QWORD *)&this->m_Params.gap0[16] = 1065353216i64;
  *(_WORD *)&this->m_Params.bProcessLFE = 0;
  this->m_Params.fDryLevel = 1.0;
  this->m_Params.fWetLevel = 1.0;
  this->m_Params.fDelayTime = 50.0;
  this->m_Params = in_rCopy->m_Params;
  this->m_ParamChangeHandler = (AK::AkFXParameterChangeHandler<11>)-1;
}

// File Line: 42
// RVA: 0xAE9ED0
AK::IAkPluginParam *__fastcall CAkPitchShifterFXParams::Clone(
        CAkPitchShifterFXParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 56i64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkPitchShifterFXParams::`vftable;
    LOWORD(result[1].vfptr) = 0;
    HIDWORD(result[1].vfptr) = 0;
    LODWORD(result[2].vfptr) = 1065353216;
    HIDWORD(result[2].vfptr) = 1148846080;
    LODWORD(result[3].vfptr) = 1065353216;
    *(AK::IAkRTPCSubscriberVtbl **)((char *)&result[3].vfptr + 4) = (AK::IAkRTPCSubscriberVtbl *)1065353216;
    LOWORD(result[6].vfptr) = 0;
    HIDWORD(result[4].vfptr) = 1065353216;
    LODWORD(result[5].vfptr) = 1065353216;
    HIDWORD(result[5].vfptr) = 1112014848;
    HIDWORD(result[1].vfptr) = this->m_Params.Voice.Filter.eFilterType;
    *(float *)&result[2].vfptr = this->m_Params.Voice.Filter.fFilterGain;
    HIDWORD(result[2].vfptr) = LODWORD(this->m_Params.Voice.Filter.fFilterFrequency);
    *(float *)&result[3].vfptr = this->m_Params.Voice.Filter.fFilterQFactor;
    HIDWORD(result[3].vfptr) = LODWORD(this->m_Params.Voice.fPitchFactor);
    LODWORD(result[4].vfptr) = this->m_Params.eInputType;
    HIDWORD(result[4].vfptr) = LODWORD(this->m_Params.fDryLevel);
    *(float *)&result[5].vfptr = this->m_Params.fWetLevel;
    HIDWORD(result[5].vfptr) = LODWORD(this->m_Params.fDelayTime);
    LODWORD(result[6].vfptr) = *(_DWORD *)&this->m_Params.bProcessLFE;
    LOWORD(result[1].vfptr) = -1;
  }
  return result;
}

// File Line: 50
// RVA: 0xAE9FA0
__int64 __fastcall CAkPitchShifterFXParams::Init(
        CAkPitchShifterFXParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        const void *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkPitchShifterFXParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  else
    return 1i64;
}

// File Line: 60
// RVA: 0xAE9FD0
__int64 __fastcall CAkPitchShifterFXParams::Term(CAkPitchShifterFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 69
// RVA: 0xAEA010
__int64 __fastcall CAkPitchShifterFXParams::SetParamsBlock(
        CAkPitchShifterFXParams *this,
        AkInputType *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  char *v3; // rbx

  v3 = (char *)(in_pParamsBlock + 1);
  this->m_Params.eInputType = *in_pParamsBlock;
  this->m_Params.fDryLevel = powf(10.0, *((float *)in_pParamsBlock + 1) * 0.050000001);
  this->m_Params.fWetLevel = powf(10.0, *((float *)v3 + 1) * 0.050000001);
  this->m_Params.fDelayTime = *((float *)v3 + 2);
  this->m_Params.bProcessLFE = v3[12];
  this->m_Params.bSyncDry = v3[13];
  this->m_Params.Voice.fPitchFactor = powf(2.0, *(float *)(v3 + 14) * 0.00083333335);
  this->m_Params.Voice.Filter.eFilterType = *(_DWORD *)(v3 + 18);
  this->m_Params.Voice.Filter.fFilterGain = *(float *)(v3 + 22);
  this->m_Params.Voice.Filter.fFilterFrequency = *(float *)(v3 + 26);
  this->m_Params.Voice.Filter.fFilterQFactor = *(float *)(v3 + 30);
  this->m_ParamChangeHandler = (AK::AkFXParameterChangeHandler<11>)-1;
  return 1i64;
}

// File Line: 96
// RVA: 0xAEA0E0
__int64 __fastcall CAkPitchShifterFXParams::SetParam(
        CAkPitchShifterFXParams *this,
        __int16 in_ParamID,
        AkInputType *in_pValue,
        unsigned int in_ulParamSize)
{
  __int64 result; // rax
  int v6; // edi

  if ( !in_pValue )
    return 31i64;
  v6 = in_ParamID;
  switch ( in_ParamID )
  {
    case 0:
      this->m_Params.eInputType = *in_pValue;
      break;
    case 1:
      this->m_Params.bProcessLFE = *(_BYTE *)in_pValue;
      break;
    case 2:
      this->m_Params.bSyncDry = *(_BYTE *)in_pValue;
      break;
    case 3:
      this->m_Params.fDryLevel = powf(10.0, *(float *)in_pValue * 0.050000001);
      break;
    case 4:
      this->m_Params.fWetLevel = powf(10.0, *(float *)in_pValue * 0.050000001);
      break;
    case 5:
      this->m_Params.fDelayTime = *(float *)in_pValue;
      break;
    case 6:
      this->m_Params.Voice.fPitchFactor = powf(2.0, *(float *)in_pValue * 0.00083333335);
      break;
    case 7:
      this->m_Params.Voice.Filter.eFilterType = (int)*(float *)in_pValue;
      break;
    case 8:
      this->m_Params.Voice.Filter.fFilterGain = *(float *)in_pValue;
      break;
    case 9:
      this->m_Params.Voice.Filter.fFilterFrequency = *(float *)in_pValue;
      break;
    case 10:
      this->m_Params.Voice.Filter.fFilterQFactor = *(float *)in_pValue;
      break;
    default:
      break;
  }
  result = 1i64;
  this->m_ParamChangeHandler.m_uParamBitArray[v6 / 8] |= 1 << (v6 % 8);
  return result;
}

// File Line: 145
// RVA: 0xAEA240
void __fastcall CAkPitchShifterFXParams::GetParams(CAkPitchShifterFXParams *this, AkPitchShifterFXParams *out_pParams)
{
  *out_pParams = this->m_Params;
}


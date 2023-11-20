// File Line: 20
// RVA: 0xAE9D40
AK::IAkPluginParam *__fastcall CreatePitchShifterFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 56ui64);
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
  this->m_Params.Voice.Filter.eFilterType = 0;
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
void __fastcall CAkPitchShifterFXParams::CAkPitchShifterFXParams(CAkPitchShifterFXParams *this, CAkPitchShifterFXParams *in_rCopy)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkPitchShifterFXParams::`vftable;
  this->m_ParamChangeHandler = 0;
  this->m_Params.Voice.Filter.eFilterType = 0;
  this->m_Params.Voice.Filter.fFilterGain = 1.0;
  this->m_Params.Voice.Filter.fFilterFrequency = 1000.0;
  this->m_Params.Voice.Filter.fFilterQFactor = 1.0;
  *(_QWORD *)&this->m_Params.gap0[16] = 1065353216i64;
  *(_WORD *)&this->m_Params.bProcessLFE = 0;
  this->m_Params.fDryLevel = 1.0;
  this->m_Params.fWetLevel = 1.0;
  this->m_Params.fDelayTime = 50.0;
  this->m_Params.Voice.Filter = in_rCopy->m_Params.Voice.Filter;
  *(_QWORD *)&this->m_Params.gap0[16] = *(_QWORD *)&in_rCopy->m_Params.gap0[16];
  this->m_Params.fDryLevel = in_rCopy->m_Params.fDryLevel;
  this->m_Params.fWetLevel = in_rCopy->m_Params.fWetLevel;
  this->m_Params.fDelayTime = in_rCopy->m_Params.fDelayTime;
  *(_DWORD *)&this->m_Params.bProcessLFE = *(_DWORD *)&in_rCopy->m_Params.bProcessLFE;
  this->m_ParamChangeHandler = (AK::AkFXParameterChangeHandler<11>)-1;
}

// File Line: 42
// RVA: 0xAE9ED0
AK::IAkPluginParam *__fastcall CAkPitchShifterFXParams::Clone(CAkPitchShifterFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkPitchShifterFXParams *v2; // rbx
  AK::IAkPluginParam *result; // rax

  v2 = this;
  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 56ui64);
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
    HIDWORD(result[1].vfptr) = v2->m_Params.Voice.Filter.eFilterType;
    *(float *)&result[2].vfptr = v2->m_Params.Voice.Filter.fFilterGain;
    HIDWORD(result[2].vfptr) = LODWORD(v2->m_Params.Voice.Filter.fFilterFrequency);
    *(float *)&result[3].vfptr = v2->m_Params.Voice.Filter.fFilterQFactor;
    HIDWORD(result[3].vfptr) = LODWORD(v2->m_Params.Voice.fPitchFactor);
    *(float *)&result[4].vfptr = v2->m_Params.Voice.fGain;
    HIDWORD(result[4].vfptr) = LODWORD(v2->m_Params.fDryLevel);
    *(float *)&result[5].vfptr = v2->m_Params.fWetLevel;
    HIDWORD(result[5].vfptr) = LODWORD(v2->m_Params.fDelayTime);
    LODWORD(result[6].vfptr) = *(_DWORD *)&v2->m_Params.bProcessLFE;
    LOWORD(result[1].vfptr) = -1;
  }
  return result;
}

// File Line: 50
// RVA: 0xAE9FA0
__int64 __fastcall CAkPitchShifterFXParams::Init(CAkPitchShifterFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  __int64 result; // rax

  if ( in_ulBlockSize )
    result = ((__int64 (__fastcall *)(CAkPitchShifterFXParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
               this,
               in_pParamsBlock,
               in_ulBlockSize);
  else
    result = 1i64;
  return result;
}

// File Line: 60
// RVA: 0xAE9FD0
signed __int64 __fastcall CAkPitchShifterFXParams::Term(CAkPitchShifterFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkPitchShifterFXParams *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
  {
    this->vfptr->__vecDelDtor((AK::IAkRTPCSubscriber *)this, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 69
// RVA: 0xAEA010
signed __int64 __fastcall CAkPitchShifterFXParams::SetParamsBlock(CAkPitchShifterFXParams *this, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  char *v3; // rbx
  CAkPitchShifterFXParams *v4; // rdi

  v3 = (char *)in_pParamsBlock + 4;
  this->m_Params.Voice.fGain = *(float *)in_pParamsBlock;
  v4 = this;
  this->m_Params.fDryLevel = powf(10.0, *((float *)in_pParamsBlock + 1) * 0.050000001);
  v4->m_Params.fWetLevel = powf(10.0, *((float *)v3 + 1) * 0.050000001);
  v4->m_Params.fDelayTime = *((float *)v3 + 2);
  v4->m_Params.bProcessLFE = v3[12];
  v4->m_Params.bSyncDry = v3[13];
  v4->m_Params.Voice.fPitchFactor = powf(2.0, *(float *)(v3 + 14) * 0.00083333335);
  v4->m_Params.Voice.Filter.eFilterType = *(_DWORD *)(v3 + 18);
  v4->m_Params.Voice.Filter.fFilterGain = *(float *)(v3 + 22);
  v4->m_Params.Voice.Filter.fFilterFrequency = *(float *)(v3 + 26);
  v4->m_Params.Voice.Filter.fFilterQFactor = *(float *)(v3 + 30);
  v4->m_ParamChangeHandler = (AK::AkFXParameterChangeHandler<11>)-1;
  return 1i64;
}

// File Line: 96
// RVA: 0xAEA0E0
signed __int64 __fastcall CAkPitchShifterFXParams::SetParam(CAkPitchShifterFXParams *this, __int16 in_ParamID, const void *in_pValue, unsigned int in_ulParamSize)
{
  CAkPitchShifterFXParams *v4; // rbx
  signed __int64 result; // rax
  int v6; // edi

  v4 = this;
  if ( !in_pValue )
    return 31i64;
  v6 = in_ParamID;
  switch ( in_ParamID )
  {
    case 0:
      this->m_Params.Voice.fGain = *(float *)in_pValue;
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
      this->m_Params.Voice.Filter.eFilterType = (signed int)*(float *)in_pValue;
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
  v4->m_ParamChangeHandler.m_uParamBitArray[v6 / 8] |= 1 << v6 % 8;
  return result;
}

// File Line: 145
// RVA: 0xAEA240
void __fastcall CAkPitchShifterFXParams::GetParams(CAkPitchShifterFXParams *this, AkPitchShifterFXParams *out_pParams)
{
  out_pParams->Voice.Filter = this->m_Params.Voice.Filter;
  *(_QWORD *)&out_pParams->gap0[16] = *(_QWORD *)&this->m_Params.gap0[16];
  out_pParams->fDryLevel = this->m_Params.fDryLevel;
  out_pParams->fWetLevel = this->m_Params.fWetLevel;
  out_pParams->fDelayTime = this->m_Params.fDelayTime;
  *(_DWORD *)&out_pParams->bProcessLFE = *(_DWORD *)&this->m_Params.bProcessLFE;
}


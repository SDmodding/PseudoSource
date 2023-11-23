// File Line: 20
// RVA: 0xAF6A70
AK::IAkPluginParam *__fastcall CreateHarmonizerFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 88i64);
  if ( !result )
    return 0i64;
  result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkHarmonizerFXParams::`vftable;
  LOWORD(result[1].vfptr) = 0;
  BYTE2(result[1].vfptr) = 0;
  HIDWORD(result[1].vfptr) = 0;
  LODWORD(result[2].vfptr) = 1065353216;
  HIDWORD(result[2].vfptr) = 1148846080;
  LODWORD(result[3].vfptr) = 1065353216;
  HIDWORD(result[3].vfptr) = 1065353216;
  LODWORD(result[4].vfptr) = 1065353216;
  BYTE4(result[4].vfptr) = 0;
  LODWORD(result[5].vfptr) = 0;
  HIDWORD(result[5].vfptr) = 1065353216;
  LODWORD(result[6].vfptr) = 1148846080;
  HIDWORD(result[6].vfptr) = 1065353216;
  LODWORD(result[7].vfptr) = 1065353216;
  HIDWORD(result[7].vfptr) = 1065353216;
  LOBYTE(result[8].vfptr) = 0;
  HIDWORD(result[8].vfptr) = 0;
  LODWORD(result[9].vfptr) = 1065353216;
  HIDWORD(result[9].vfptr) = 1065353216;
  LODWORD(result[10].vfptr) = 1024;
  WORD2(result[10].vfptr) = 0;
  return result;
}

// File Line: 26
// RVA: 0xAF6B20
void __fastcall CAkHarmonizerFXParams::CAkHarmonizerFXParams(CAkHarmonizerFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkHarmonizerFXParams::`vftable;
  *(_WORD *)this->m_ParamChangeHandler.m_uParamBitArray = 0;
  this->m_ParamChangeHandler.m_uParamBitArray[2] = 0;
  this->m_Params.Voice[0].Filter.eFilterType = AKFILTERTYPE_LOWPASS;
  this->m_Params.Voice[0].Filter.fFilterGain = 1.0;
  this->m_Params.Voice[0].Filter.fFilterFrequency = 1000.0;
  this->m_Params.Voice[0].Filter.fFilterQFactor = 1.0;
  this->m_Params.Voice[0].bEnable = 0;
  this->m_Params.Voice[0].fPitchFactor = 1.0;
  this->m_Params.Voice[0].fGain = 1.0;
  this->m_Params.Voice[1].Filter.eFilterType = AKFILTERTYPE_LOWPASS;
  this->m_Params.Voice[1].Filter.fFilterGain = 1.0;
  this->m_Params.Voice[1].Filter.fFilterFrequency = 1000.0;
  this->m_Params.Voice[1].Filter.fFilterQFactor = 1.0;
  this->m_Params.Voice[1].bEnable = 0;
  this->m_Params.Voice[1].fPitchFactor = 1.0;
  this->m_Params.Voice[1].fGain = 1.0;
  this->m_Params.eInputType = AKINPUTTYPE_ASINPUT;
  *(_WORD *)&this->m_Params.bProcessLFE = 0;
  this->m_Params.fDryLevel = 1.0;
  this->m_Params.fWetLevel = 1.0;
  this->m_Params.uWindowSize = 1024;
}

// File Line: 30
// RVA: 0xAF6BB0
void __fastcall CAkHarmonizerFXParams::~CAkHarmonizerFXParams(CAkHarmonizerFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
}

// File Line: 35
// RVA: 0xAF6BD0
void __fastcall CAkHarmonizerFXParams::CAkHarmonizerFXParams(
        CAkHarmonizerFXParams *this,
        CAkHarmonizerFXParams *in_rCopy)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkHarmonizerFXParams::`vftable;
  *(_WORD *)this->m_ParamChangeHandler.m_uParamBitArray = 0;
  this->m_ParamChangeHandler.m_uParamBitArray[2] = 0;
  this->m_Params.Voice[0].Filter.eFilterType = AKFILTERTYPE_LOWPASS;
  this->m_Params.Voice[0].Filter.fFilterGain = 1.0;
  this->m_Params.Voice[0].Filter.fFilterFrequency = 1000.0;
  this->m_Params.Voice[0].Filter.fFilterQFactor = 1.0;
  this->m_Params.Voice[0].bEnable = 0;
  this->m_Params.Voice[0].fPitchFactor = 1.0;
  this->m_Params.Voice[0].fGain = 1.0;
  this->m_Params.Voice[1].Filter.eFilterType = AKFILTERTYPE_LOWPASS;
  this->m_Params.Voice[1].Filter.fFilterGain = 1.0;
  this->m_Params.Voice[1].Filter.fFilterFrequency = 1000.0;
  this->m_Params.Voice[1].Filter.fFilterQFactor = 1.0;
  this->m_Params.Voice[1].bEnable = 0;
  this->m_Params.Voice[1].fPitchFactor = 1.0;
  this->m_Params.Voice[1].fGain = 1.0;
  this->m_Params.eInputType = AKINPUTTYPE_ASINPUT;
  *(_WORD *)&this->m_Params.bProcessLFE = 0;
  this->m_Params.fDryLevel = 1.0;
  this->m_Params.fWetLevel = 1.0;
  this->m_Params.uWindowSize = 1024;
  this->m_Params = in_rCopy->m_Params;
  *(_WORD *)this->m_ParamChangeHandler.m_uParamBitArray = -1;
  this->m_ParamChangeHandler.m_uParamBitArray[2] = -1;
}

// File Line: 42
// RVA: 0xAF6CE0
void __fastcall CAkHarmonizerFXParams::Clone(CAkHarmonizerFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkHarmonizerFXParams *v3; // rax

  v3 = (CAkHarmonizerFXParams *)in_pAllocator->vfptr->Malloc(in_pAllocator, 88i64);
  if ( v3 )
    CAkHarmonizerFXParams::CAkHarmonizerFXParams(v3, this);
}

// File Line: 50
// RVA: 0xAF6D20
__int64 __fastcall CAkHarmonizerFXParams::Init(
        CAkHarmonizerFXParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        const void *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkHarmonizerFXParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  else
    return 1i64;
}

// File Line: 60
// RVA: 0xAF6D50
__int64 __fastcall CAkHarmonizerFXParams::Term(CAkHarmonizerFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 69
// RVA: 0xAF6D90
__int64 __fastcall CAkHarmonizerFXParams::SetParamsBlock(
        CAkHarmonizerFXParams *this,
        char *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  float *p_fPitchFactor; // rdi
  __int64 v6; // rbp
  float v7; // xmm0_4

  p_fPitchFactor = &this->m_Params.Voice[0].fPitchFactor;
  v6 = 2i64;
  do
  {
    *((_BYTE *)p_fPitchFactor + 8) = *in_pParamsBlock;
    *p_fPitchFactor = powf(2.0, *(float *)(in_pParamsBlock + 1) * 0.00083333335);
    v7 = powf(10.0, *(float *)(in_pParamsBlock + 5) * 0.050000001);
    p_fPitchFactor += 7;
    in_pParamsBlock += 25;
    *(p_fPitchFactor - 6) = v7;
    *(p_fPitchFactor - 11) = *((float *)in_pParamsBlock - 4);
    *(p_fPitchFactor - 10) = *((float *)in_pParamsBlock - 3);
    *(p_fPitchFactor - 9) = *((float *)in_pParamsBlock - 2);
    *(p_fPitchFactor - 8) = *((float *)in_pParamsBlock - 1);
    --v6;
  }
  while ( v6 );
  this->m_Params.eInputType = *(_DWORD *)in_pParamsBlock;
  this->m_Params.fDryLevel = powf(10.0, *((float *)in_pParamsBlock + 1) * 0.050000001);
  this->m_Params.fWetLevel = powf(10.0, *((float *)in_pParamsBlock + 2) * 0.050000001);
  this->m_Params.uWindowSize = *((_DWORD *)in_pParamsBlock + 3);
  this->m_Params.bProcessLFE = in_pParamsBlock[16];
  this->m_Params.bSyncDry = in_pParamsBlock[17];
  *(_WORD *)this->m_ParamChangeHandler.m_uParamBitArray = -1;
  this->m_ParamChangeHandler.m_uParamBitArray[2] = -1;
  return 1i64;
}

// File Line: 101
// RVA: 0xAF6EE0
__int64 __fastcall CAkHarmonizerFXParams::SetParam(
        CAkHarmonizerFXParams *this,
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
      this->m_Params.uWindowSize = *in_pValue;
      break;
    case 6:
      this->m_Params.Voice[0].bEnable = *(_BYTE *)in_pValue;
      break;
    case 7:
      this->m_Params.Voice[0].fPitchFactor = powf(2.0, *(float *)in_pValue * 0.00083333335);
      break;
    case 8:
      this->m_Params.Voice[0].fGain = powf(10.0, *(float *)in_pValue * 0.050000001);
      break;
    case 9:
      this->m_Params.Voice[0].Filter.eFilterType = (int)*(float *)in_pValue;
      break;
    case 10:
      this->m_Params.Voice[0].Filter.fFilterGain = *(float *)in_pValue;
      break;
    case 11:
      this->m_Params.Voice[0].Filter.fFilterFrequency = *(float *)in_pValue;
      break;
    case 12:
      this->m_Params.Voice[0].Filter.fFilterQFactor = *(float *)in_pValue;
      break;
    case 13:
      this->m_Params.Voice[1].bEnable = *(_BYTE *)in_pValue;
      break;
    case 14:
      this->m_Params.Voice[1].fPitchFactor = powf(2.0, *(float *)in_pValue * 0.00083333335);
      break;
    case 15:
      this->m_Params.Voice[1].fGain = powf(10.0, *(float *)in_pValue * 0.050000001);
      break;
    case 16:
      this->m_Params.Voice[1].Filter.eFilterType = (int)*(float *)in_pValue;
      break;
    case 17:
      this->m_Params.Voice[1].Filter.fFilterGain = *(float *)in_pValue;
      break;
    case 18:
      this->m_Params.Voice[1].Filter.fFilterFrequency = *(float *)in_pValue;
      break;
    case 19:
      this->m_Params.Voice[1].Filter.fFilterQFactor = *(float *)in_pValue;
      break;
    default:
      break;
  }
  result = 1i64;
  this->m_ParamChangeHandler.m_uParamBitArray[v6 / 8] |= 1 << (v6 % 8);
  return result;
}

// File Line: 177
// RVA: 0xAF7110
void __fastcall CAkHarmonizerFXParams::GetParams(CAkHarmonizerFXParams *this, AkHarmonizerFXParams *out_pParams)
{
  *out_pParams = this->m_Params;
}


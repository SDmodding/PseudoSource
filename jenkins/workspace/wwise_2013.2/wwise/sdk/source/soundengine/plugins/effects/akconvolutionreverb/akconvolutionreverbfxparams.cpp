// File Line: 18
// RVA: 0xB16070
AK::IAkPluginParam *__fastcall CreateConvolutionReverbFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 56ui64);
  if ( !result )
    return 0i64;
  result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkConvolutionReverbFXParams::`vftable';
  LODWORD(result[2].vfptr) = 1127481344;
  *(AK::IAkRTPCSubscriberVtbl **)((char *)&result[2].vfptr + 4) = (AK::IAkRTPCSubscriberVtbl *)1065353216;
  HIDWORD(result[3].vfptr) = 1065353216;
  LODWORD(result[4].vfptr) = 1065353216;
  result[1].vfptr = 0i64;
  *(AK::IAkRTPCSubscriberVtbl **)((char *)&result[4].vfptr + 4) = (AK::IAkRTPCSubscriberVtbl *)1065353216;
  HIDWORD(result[5].vfptr) = 1065353216;
  result[6].vfptr = (AK::IAkRTPCSubscriberVtbl *)1048576000;
  return result;
}

// File Line: 24
// RVA: 0xB160E0
void __fastcall CAkConvolutionReverbFXParams::CAkConvolutionReverbFXParams(CAkConvolutionReverbFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkConvolutionReverbFXParams::`vftable';
  this->m_Params.fStereoWidth = 180.0;
  *(_QWORD *)&this->m_Params.fPreDelay = 0i64;
  *(_QWORD *)&this->m_Params.fInputCenterLevel = 1065353216i64;
  this->m_Params.fFrontLevel = 1.0;
  this->m_Params.fRearLevel = 1.0;
  *(_QWORD *)&this->m_Params.fCenterLevel = 1065353216i64;
  this->m_Params.fDryLevel = 1.0;
  *(_QWORD *)&this->m_Params.fWetLevel = 1048576000i64;
}

// File Line: 28
// RVA: 0xB16130
void __fastcall CAkConvolutionReverbFXParams::~CAkConvolutionReverbFXParams(CAkConvolutionReverbFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable';
}

// File Line: 33
// RVA: 0xB16150
void __fastcall CAkConvolutionReverbFXParams::CAkConvolutionReverbFXParams(CAkConvolutionReverbFXParams *this, CAkConvolutionReverbFXParams *in_rCopy)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkConvolutionReverbFXParams::`vftable';
  this->m_Params.fStereoWidth = 180.0;
  *(_QWORD *)&this->m_Params.fInputCenterLevel = 1065353216i64;
  this->m_Params.fFrontLevel = 1.0;
  this->m_Params.fRearLevel = 1.0;
  *(_QWORD *)&this->m_Params.fCenterLevel = 1065353216i64;
  this->m_Params.fDryLevel = 1.0;
  *(_QWORD *)&this->m_Params.fWetLevel = 1048576000i64;
  *(_QWORD *)&this->m_Params.fPreDelay = 0i64;
  this->m_Params.fPreDelay = in_rCopy->m_Params.fPreDelay;
  this->m_Params.fFrontRearDelay = in_rCopy->m_Params.fFrontRearDelay;
  this->m_Params.fStereoWidth = in_rCopy->m_Params.fStereoWidth;
  this->m_Params.fInputCenterLevel = in_rCopy->m_Params.fInputCenterLevel;
  this->m_Params.fInputLFELevel = in_rCopy->m_Params.fInputLFELevel;
  this->m_Params.fFrontLevel = in_rCopy->m_Params.fFrontLevel;
  this->m_Params.fRearLevel = in_rCopy->m_Params.fRearLevel;
  this->m_Params.fCenterLevel = in_rCopy->m_Params.fCenterLevel;
  this->m_Params.fLFELevel = in_rCopy->m_Params.fLFELevel;
  this->m_Params.fDryLevel = in_rCopy->m_Params.fDryLevel;
  this->m_Params.fWetLevel = in_rCopy->m_Params.fWetLevel;
  this->m_Params.eAlgoType = in_rCopy->m_Params.eAlgoType;
}

// File Line: 39
// RVA: 0xB161F0
AK::IAkPluginParam *__fastcall CAkConvolutionReverbFXParams::Clone(CAkConvolutionReverbFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkConvolutionReverbFXParams *v2; // rbx
  AK::IAkPluginParam *result; // rax

  v2 = this;
  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 56ui64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkConvolutionReverbFXParams::`vftable';
    LODWORD(result[2].vfptr) = 1127481344;
    *(AK::IAkRTPCSubscriberVtbl **)((char *)&result[2].vfptr + 4) = (AK::IAkRTPCSubscriberVtbl *)1065353216;
    HIDWORD(result[3].vfptr) = 1065353216;
    LODWORD(result[4].vfptr) = 1065353216;
    *(AK::IAkRTPCSubscriberVtbl **)((char *)&result[4].vfptr + 4) = (AK::IAkRTPCSubscriberVtbl *)1065353216;
    HIDWORD(result[5].vfptr) = 1065353216;
    result[6].vfptr = (AK::IAkRTPCSubscriberVtbl *)1048576000;
    result[1].vfptr = 0i64;
    *(float *)&result[1].vfptr = v2->m_Params.fPreDelay;
    HIDWORD(result[1].vfptr) = LODWORD(v2->m_Params.fFrontRearDelay);
    *(float *)&result[2].vfptr = v2->m_Params.fStereoWidth;
    HIDWORD(result[2].vfptr) = LODWORD(v2->m_Params.fInputCenterLevel);
    *(float *)&result[3].vfptr = v2->m_Params.fInputLFELevel;
    HIDWORD(result[3].vfptr) = LODWORD(v2->m_Params.fFrontLevel);
    *(float *)&result[4].vfptr = v2->m_Params.fRearLevel;
    HIDWORD(result[4].vfptr) = LODWORD(v2->m_Params.fCenterLevel);
    *(float *)&result[5].vfptr = v2->m_Params.fLFELevel;
    HIDWORD(result[5].vfptr) = LODWORD(v2->m_Params.fDryLevel);
    *(float *)&result[6].vfptr = v2->m_Params.fWetLevel;
    HIDWORD(result[6].vfptr) = v2->m_Params.eAlgoType;
  }
  return result;
}

// File Line: 47
// RVA: 0xB162C0
__int64 __fastcall CAkConvolutionReverbFXParams::Init(CAkConvolutionReverbFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  __int64 result; // rax

  if ( in_ulBlockSize )
    result = ((__int64 (__fastcall *)(CAkConvolutionReverbFXParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
               this,
               in_pParamsBlock,
               in_ulBlockSize);
  else
    result = 1i64;
  return result;
}

// File Line: 57
// RVA: 0xB162F0
signed __int64 __fastcall CAkConvolutionReverbFXParams::Term(CAkConvolutionReverbFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkConvolutionReverbFXParams *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
  {
    this->vfptr->__vecDelDtor((AK::IAkRTPCSubscriber *)this, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 66
// RVA: 0xB16330
signed __int64 __fastcall CAkConvolutionReverbFXParams::SetParamsBlock(CAkConvolutionReverbFXParams *this, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  char *v3; // rbx
  CAkConvolutionReverbFXParams *v4; // rdi

  v3 = (char *)in_pParamsBlock + 4;
  this->m_Params.fPreDelay = *(float *)in_pParamsBlock;
  v4 = this;
  this->m_Params.fFrontRearDelay = *((float *)in_pParamsBlock + 1);
  this->m_Params.fStereoWidth = *((float *)in_pParamsBlock + 2);
  this->m_Params.fInputCenterLevel = powf(10.0, *((float *)in_pParamsBlock + 3) * 0.050000001);
  v4->m_Params.fInputLFELevel = powf(10.0, *((float *)v3 + 3) * 0.050000001);
  v4->m_Params.fFrontLevel = powf(10.0, *((float *)v3 + 4) * 0.050000001);
  v4->m_Params.fRearLevel = powf(10.0, *((float *)v3 + 5) * 0.050000001);
  v4->m_Params.fCenterLevel = powf(10.0, *((float *)v3 + 6) * 0.050000001);
  v4->m_Params.fLFELevel = powf(10.0, *((float *)v3 + 7) * 0.050000001);
  v4->m_Params.fDryLevel = powf(10.0, *((float *)v3 + 8) * 0.050000001);
  v4->m_Params.fWetLevel = powf(10.0, *((float *)v3 + 9) * 0.050000001);
  v4->m_Params.eAlgoType = *((_DWORD *)v3 + 10);
  return 1i64;
}

// File Line: 89
// RVA: 0xB16450
signed __int64 __fastcall CAkConvolutionReverbFXParams::SetParam(CAkConvolutionReverbFXParams *this, __int16 in_ParamID, const void *in_pValue, unsigned int in_ulParamSize)
{
  CAkConvolutionReverbFXParams *v4; // rbx
  signed __int64 result; // rax
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4

  v4 = this;
  if ( !in_pValue )
    return 31i64;
  switch ( in_ParamID )
  {
    case 0:
      this->m_Params.fPreDelay = *(float *)in_pValue;
      result = 1i64;
      break;
    case 1:
      this->m_Params.fFrontRearDelay = *(float *)in_pValue;
      result = 1i64;
      break;
    case 2:
      this->m_Params.fStereoWidth = *(float *)in_pValue;
      result = 1i64;
      break;
    case 10:
      v6 = powf(10.0, *(float *)in_pValue * 0.050000001);
      result = 1i64;
      v4->m_Params.fInputCenterLevel = v6;
      break;
    case 11:
      v7 = powf(10.0, *(float *)in_pValue * 0.050000001);
      result = 1i64;
      v4->m_Params.fInputLFELevel = v7;
      break;
    case 20:
      v8 = powf(10.0, *(float *)in_pValue * 0.050000001);
      result = 1i64;
      v4->m_Params.fFrontLevel = v8;
      break;
    case 21:
      v9 = powf(10.0, *(float *)in_pValue * 0.050000001);
      result = 1i64;
      v4->m_Params.fRearLevel = v9;
      break;
    case 22:
      v10 = powf(10.0, *(float *)in_pValue * 0.050000001);
      result = 1i64;
      v4->m_Params.fCenterLevel = v10;
      break;
    case 23:
      v11 = powf(10.0, *(float *)in_pValue * 0.050000001);
      result = 1i64;
      v4->m_Params.fLFELevel = v11;
      break;
    case 30:
      v12 = powf(10.0, *(float *)in_pValue * 0.050000001);
      result = 1i64;
      v4->m_Params.fDryLevel = v12;
      break;
    case 31:
      v13 = powf(10.0, *(float *)in_pValue * 0.050000001);
      result = 1i64;
      v4->m_Params.fWetLevel = v13;
      break;
    case 32:
      this->m_Params.eAlgoType = *(_DWORD *)in_pValue;
      goto LABEL_16;
    default:
LABEL_16:
      result = 1i64;
      break;
  }
  return result;
}

// File Line: 150
// RVA: 0xB16680
void __fastcall CAkConvolutionReverbFXParams::GetParams(CAkConvolutionReverbFXParams *this, AkConvolutionReverbFXParams *out_pParams)
{
  out_pParams->fPreDelay = this->m_Params.fPreDelay;
  out_pParams->fFrontRearDelay = this->m_Params.fFrontRearDelay;
  out_pParams->fStereoWidth = this->m_Params.fStereoWidth;
  out_pParams->fInputCenterLevel = this->m_Params.fInputCenterLevel;
  out_pParams->fInputLFELevel = this->m_Params.fInputLFELevel;
  out_pParams->fFrontLevel = this->m_Params.fFrontLevel;
  out_pParams->fRearLevel = this->m_Params.fRearLevel;
  out_pParams->fCenterLevel = this->m_Params.fCenterLevel;
  out_pParams->fLFELevel = this->m_Params.fLFELevel;
  out_pParams->fDryLevel = this->m_Params.fDryLevel;
  out_pParams->fWetLevel = this->m_Params.fWetLevel;
  out_pParams->eAlgoType = this->m_Params.eAlgoType;
}


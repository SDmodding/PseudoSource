// File Line: 16
// RVA: 0xAFC390
AK::IAkPluginParam *__fastcall CreateMcDSPML1FXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 32i64);
  if ( result )
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CMcDSPLimiterFXParams::`vftable;
  return result;
}

// File Line: 22
// RVA: 0xAFC060
void __fastcall CMcDSPLimiterFXParams::CMcDSPLimiterFXParams(CMcDSPLimiterFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CMcDSPLimiterFXParams::`vftable;
}

// File Line: 27
// RVA: 0xAFC0C0
void __fastcall CMcDSPLimiterFXParams::~CMcDSPLimiterFXParams(CMcDSPLimiterFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
}

// File Line: 32
// RVA: 0xAFC080
void __fastcall CMcDSPLimiterFXParams::CMcDSPLimiterFXParams(
        CMcDSPLimiterFXParams *this,
        CMcDSPLimiterFXParams *in_rCopy)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CMcDSPLimiterFXParams::`vftable;
  this->m_Params = in_rCopy->m_Params;
}

// File Line: 38
// RVA: 0xAFC0E0
AK::IAkPluginParam *__fastcall CMcDSPLimiterFXParams::Clone(
        CMcDSPLimiterFXParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 32i64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CMcDSPLimiterFXParams::`vftable;
    *(float *)&result[1].vfptr = this->m_Params.fCeiling;
    HIDWORD(result[1].vfptr) = LODWORD(this->m_Params.fThreshold);
    *(float *)&result[2].vfptr = this->m_Params.fKnee;
    HIDWORD(result[2].vfptr) = LODWORD(this->m_Params.fRelease);
    LODWORD(result[3].vfptr) = this->m_Params.eMode;
    HIDWORD(result[3].vfptr) = *(_DWORD *)&this->m_Params.bParamsHaveChanged;
  }
  return result;
}

// File Line: 46
// RVA: 0xAFC150
__int64 __fastcall CMcDSPLimiterFXParams::Init(
        CMcDSPLimiterFXParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        const void *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CMcDSPLimiterFXParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  *(_QWORD *)&this->m_Params.fRelease = 1092616192i64;
  this->m_Params.bParamsHaveChanged = 1;
  *(_QWORD *)&this->m_Params.fCeiling = 0i64;
  this->m_Params.fKnee = 0.0;
  return 1i64;
}

// File Line: 63
// RVA: 0xAFC190
__int64 __fastcall CMcDSPLimiterFXParams::Term(CMcDSPLimiterFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 71
// RVA: 0xAFC1D0
__int64 __fastcall CMcDSPLimiterFXParams::SetParamsBlock(
        CMcDSPLimiterFXParams *this,
        float *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  float v3; // xmm3_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  LimiterCharacterType v6; // eax
  float fRelease; // xmm0_4

  v3 = *in_pParamsBlock;
  this->m_Params.fCeiling = *in_pParamsBlock;
  v4 = in_pParamsBlock[1];
  this->m_Params.fThreshold = v4;
  v5 = in_pParamsBlock[2];
  this->m_Params.fKnee = v5;
  this->m_Params.fRelease = in_pParamsBlock[3];
  v6 = *((_DWORD *)in_pParamsBlock + 4);
  this->m_Params.eMode = v6;
  this->m_Params.bParamsHaveChanged = 1;
  if ( v3 < -36.0 || v3 > 0.0 )
    this->m_Params.fCeiling = 0.0;
  if ( v4 < -36.0 || v4 > 0.0 )
    this->m_Params.fThreshold = 0.0;
  if ( v5 < 0.0 || v5 > 100.0 )
    this->m_Params.fKnee = 0.0;
  fRelease = this->m_Params.fRelease;
  if ( fRelease < 1.0 || fRelease > 5000.0 )
    this->m_Params.fRelease = 10.0;
  if ( (unsigned int)v6 > eCharacterMode_Crush )
    v6 = eCharacterMode_Clean;
  this->m_Params.eMode = v6;
  return 1i64;
}

// File Line: 107
// RVA: 0xAFC270
__int64 __fastcall CMcDSPLimiterFXParams::SetParam(
        CMcDSPLimiterFXParams *this,
        __int16 in_ParamID,
        float *in_pValue,
        unsigned int in_ulParamSize)
{
  LimiterCharacterType v5; // eax
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm1_4

  if ( !in_pValue )
    return 31i64;
  if ( in_ParamID )
  {
    switch ( in_ParamID )
    {
      case 1:
        v8 = *in_pValue;
        this->m_Params.fThreshold = *in_pValue;
        if ( v8 < -36.0 || v8 > 0.0 )
        {
          this->m_Params.fThreshold = 0.0;
          this->m_Params.bParamsHaveChanged = 1;
          return 1i64;
        }
        break;
      case 2:
        v7 = *in_pValue;
        this->m_Params.fKnee = *in_pValue;
        if ( v7 < 0.0 || v7 > 100.0 )
        {
          this->m_Params.fKnee = 0.0;
          this->m_Params.bParamsHaveChanged = 1;
          return 1i64;
        }
        break;
      case 3:
        v6 = *in_pValue;
        this->m_Params.fRelease = *in_pValue;
        if ( v6 < 1.0 || v6 > 5000.0 )
        {
          this->m_Params.fRelease = 10.0;
          this->m_Params.bParamsHaveChanged = 1;
          return 1i64;
        }
        break;
      case 4:
        v5 = (int)*in_pValue;
        this->m_Params.eMode = v5;
        if ( (unsigned int)v5 > eCharacterMode_Crush )
        {
          this->m_Params.eMode = eCharacterMode_Clean;
          this->m_Params.bParamsHaveChanged = 1;
          return 1i64;
        }
        break;
      default:
        this->m_Params.bParamsHaveChanged = 1;
        return 31i64;
    }
  }
  else
  {
    v9 = *in_pValue;
    this->m_Params.fCeiling = *in_pValue;
    if ( v9 < -36.0 || v9 > 0.0 )
      this->m_Params.fCeiling = 0.0;
  }
  this->m_Params.bParamsHaveChanged = 1;
  return 1i64;
}


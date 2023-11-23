// File Line: 18
// RVA: 0xACE8D0
AK::IAkPluginParam *__fastcall CreateParametricEQFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 80i64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkParameterEQFXParams::`vftable;
    WORD2(result[9].vfptr) = 257;
    BYTE6(result[9].vfptr) = 1;
  }
  return result;
}

// File Line: 25
// RVA: 0xACE910
void __fastcall CAkParameterEQFXParams::CAkParameterEQFXParams(CAkParameterEQFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkParameterEQFXParams::`vftable;
  *(_WORD *)this->m_bBandDirty = 257;
  this->m_bBandDirty[2] = 1;
}

// File Line: 32
// RVA: 0xACE930
void __fastcall CAkParameterEQFXParams::~CAkParameterEQFXParams(CAkParameterEQFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
}

// File Line: 37
// RVA: 0xACE950
void __fastcall CAkParameterEQFXParams::CAkParameterEQFXParams(
        CAkParameterEQFXParams *this,
        CAkParameterEQFXParams *in_rCopy)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkParameterEQFXParams::`vftable;
  this->m_Params = in_rCopy->m_Params;
  *(_WORD *)this->m_bBandDirty = 257;
  this->m_bBandDirty[2] = 1;
}

// File Line: 46
// RVA: 0xACE9E0
AK::IAkPluginParam *__fastcall CAkParameterEQFXParams::Clone(
        CAkParameterEQFXParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 80i64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkParameterEQFXParams::`vftable;
    LODWORD(result[1].vfptr) = this->m_Params.Band[0].eFilterType;
    HIDWORD(result[1].vfptr) = LODWORD(this->m_Params.Band[0].fGain);
    *(float *)&result[2].vfptr = this->m_Params.Band[0].fFrequency;
    HIDWORD(result[2].vfptr) = LODWORD(this->m_Params.Band[0].fQFactor);
    LODWORD(result[3].vfptr) = *(_DWORD *)&this->m_Params.Band[0].bOnOff;
    HIDWORD(result[3].vfptr) = this->m_Params.Band[1].eFilterType;
    *(float *)&result[4].vfptr = this->m_Params.Band[1].fGain;
    HIDWORD(result[4].vfptr) = LODWORD(this->m_Params.Band[1].fFrequency);
    *(float *)&result[5].vfptr = this->m_Params.Band[1].fQFactor;
    HIDWORD(result[5].vfptr) = *(_DWORD *)&this->m_Params.Band[1].bOnOff;
    LODWORD(result[6].vfptr) = this->m_Params.Band[2].eFilterType;
    HIDWORD(result[6].vfptr) = LODWORD(this->m_Params.Band[2].fGain);
    *(float *)&result[7].vfptr = this->m_Params.Band[2].fFrequency;
    HIDWORD(result[7].vfptr) = LODWORD(this->m_Params.Band[2].fQFactor);
    LODWORD(result[8].vfptr) = *(_DWORD *)&this->m_Params.Band[2].bOnOff;
    HIDWORD(result[8].vfptr) = LODWORD(this->m_Params.fOutputLevel);
    LODWORD(result[9].vfptr) = *(_DWORD *)&this->m_Params.bProcessLFE;
    WORD2(result[9].vfptr) = 257;
    BYTE6(result[9].vfptr) = 1;
  }
  return result;
}

// File Line: 55
// RVA: 0xACEAB0
__int64 __fastcall CAkParameterEQFXParams::Init(
        CAkParameterEQFXParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        const void *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  __int64 result; // rax

  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkParameterEQFXParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  *(_QWORD *)&this->m_Params.Band[0].eFilterType = 4i64;
  this->m_Params.Band[0].fFrequency = 120.0;
  this->m_Params.fOutputLevel = 0.0;
  this->m_Params.Band[0].fQFactor = 5.0;
  this->m_Params.Band[0].bOnOff = 1;
  result = 1i64;
  *(_QWORD *)&this->m_Params.Band[1].eFilterType = 6i64;
  this->m_Params.Band[1].fFrequency = 2000.0;
  this->m_Params.Band[1].fQFactor = 5.0;
  this->m_Params.Band[1].bOnOff = 1;
  *(_QWORD *)&this->m_Params.Band[2].eFilterType = 5i64;
  this->m_Params.Band[2].fFrequency = 5000.0;
  this->m_Params.Band[2].fQFactor = 5.0;
  this->m_Params.Band[2].bOnOff = 1;
  this->m_Params.bProcessLFE = 1;
  *(_WORD *)this->m_bBandDirty = 257;
  this->m_bBandDirty[2] = 1;
  return result;
}

// File Line: 90
// RVA: 0xACEB40
__int64 __fastcall CAkParameterEQFXParams::Term(CAkParameterEQFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 100
// RVA: 0xACEB80
__int64 __fastcall CAkParameterEQFXParams::SetParamsBlock(
        CAkParameterEQFXParams *this,
        char *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  char v3; // al
  __int64 result; // rax

  this->m_Params.Band[0].eFilterType = *(_DWORD *)in_pParamsBlock;
  this->m_Params.Band[0].fGain = *((float *)in_pParamsBlock + 1);
  this->m_Params.Band[0].fFrequency = *((float *)in_pParamsBlock + 2);
  this->m_Params.Band[0].fQFactor = *((float *)in_pParamsBlock + 3);
  this->m_Params.Band[0].bOnOff = in_pParamsBlock[16];
  this->m_Params.Band[1] = *(EQModuleParams *)(in_pParamsBlock + 17);
  this->m_Params.Band[2] = *(EQModuleParams *)(in_pParamsBlock + 34);
  this->m_Params.fOutputLevel = *(float *)(in_pParamsBlock + 51);
  v3 = in_pParamsBlock[55];
  *(_WORD *)this->m_bBandDirty = 257;
  this->m_Params.bProcessLFE = v3;
  result = 1i64;
  this->m_bBandDirty[2] = 1;
  return result;
}

// File Line: 137
// RVA: 0xACEC30
__int64 __fastcall CAkParameterEQFXParams::SetParam(
        CAkParameterEQFXParams *this,
        __int16 in_ParamID,
        float *in_pValue,
        unsigned int in_ulParamSize)
{
  __int64 result; // rax
  int v6; // ecx
  __int64 v7; // rdx

  if ( !in_pValue )
    return 31i64;
  v6 = in_ParamID;
  v7 = (unsigned int)(in_ParamID / 5);
  switch ( v6 )
  {
    case 0:
    case 5:
    case 10:
      this->m_Params.Band[v7].eFilterType = (int)*in_pValue;
      this->m_bBandDirty[v7] = 1;
      result = 1i64;
      break;
    case 1:
    case 6:
    case 11:
      this->m_Params.Band[v7].fGain = *in_pValue;
      this->m_bBandDirty[v7] = 1;
      result = 1i64;
      break;
    case 2:
    case 7:
    case 12:
      this->m_Params.Band[v7].fFrequency = *in_pValue;
      this->m_bBandDirty[v7] = 1;
      result = 1i64;
      break;
    case 3:
    case 8:
    case 13:
      this->m_Params.Band[v7].fQFactor = *in_pValue;
      this->m_bBandDirty[v7] = 1;
      result = 1i64;
      break;
    case 4:
    case 9:
    case 14:
      this->m_Params.Band[v7].bOnOff = *in_pValue != 0.0;
      this->m_bBandDirty[v7] = 1;
      result = 1i64;
      break;
    case 15:
      this->m_Params.fOutputLevel = *in_pValue;
      result = 1i64;
      break;
    case 16:
      this->m_Params.bProcessLFE = *(_BYTE *)in_pValue;
      result = 1i64;
      break;
    default:
      result = 31i64;
      break;
  }
  return result;
}


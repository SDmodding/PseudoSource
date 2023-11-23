// File Line: 16
// RVA: 0xAD1C70
AK::IAkPluginParam *__fastcall CreateToneSourceParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 80i64);
  if ( result )
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkToneGenParams::`vftable;
  return result;
}

// File Line: 40
// RVA: 0xAD1BB0
AK::IAkPluginParam *__fastcall CAkToneGenParams::Clone(CAkToneGenParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 80i64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkToneGenParams::`vftable;
    *(float *)&result[1].vfptr = this->m_Params.fGain;
    HIDWORD(result[1].vfptr) = LODWORD(this->m_Params.fStartFreq);
    *(float *)&result[2].vfptr = this->m_Params.fStopFreq;
    HIDWORD(result[2].vfptr) = LODWORD(this->m_Params.staticParams.fStartFreqRandMin);
    *(float *)&result[3].vfptr = this->m_Params.staticParams.fStartFreqRandMax;
    HIDWORD(result[3].vfptr) = *(_DWORD *)&this->m_Params.staticParams.bFreqSweep;
    LODWORD(result[4].vfptr) = this->m_Params.staticParams.eGenSweep;
    HIDWORD(result[4].vfptr) = LODWORD(this->m_Params.staticParams.fStopFreqRandMin);
    *(float *)&result[5].vfptr = this->m_Params.staticParams.fStopFreqRandMax;
    HIDWORD(result[5].vfptr) = this->m_Params.staticParams.eGenType;
    LODWORD(result[6].vfptr) = this->m_Params.staticParams.eGenMode;
    HIDWORD(result[6].vfptr) = LODWORD(this->m_Params.staticParams.fFixDur);
    *(float *)&result[7].vfptr = this->m_Params.staticParams.fAttackDur;
    HIDWORD(result[7].vfptr) = LODWORD(this->m_Params.staticParams.fDecayDur);
    *(float *)&result[8].vfptr = this->m_Params.staticParams.fSustainDur;
    HIDWORD(result[8].vfptr) = LODWORD(this->m_Params.staticParams.fSustainVal);
    *(float *)&result[9].vfptr = this->m_Params.staticParams.fReleaseDur;
    HIDWORD(result[9].vfptr) = this->m_Params.staticParams.uChannelMask;
  }
  return result;
}

// File Line: 49
// RVA: 0xAD1CA0
__int64 __fastcall CAkToneGenParams::Init(
        CAkToneGenParams *this,
        AK::IAkPluginMemAlloc *__formal,
        const void *in_pParamsBlock,
        unsigned int in_uBlockSize)
{
  if ( in_uBlockSize )
    return ((__int64 (__fastcall *)(CAkToneGenParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_uBlockSize);
  *(_QWORD *)&this->m_Params.fStartFreq = 1138491392i64;
  *(_QWORD *)&this->m_Params.staticParams.fFixDur = 1065353216i64;
  this->m_Params.fGain = 0.0;
  *(_QWORD *)&this->m_Params.staticParams.fStartFreqRandMin = 0i64;
  this->m_Params.staticParams.bFreqSweep = 0;
  *(_QWORD *)&this->m_Params.staticParams.eGenSweep = 0i64;
  *(_QWORD *)&this->m_Params.staticParams.fStopFreqRandMax = 0i64;
  this->m_Params.staticParams.eGenMode = AKTONEGENMODE_FIX;
  *(_QWORD *)&this->m_Params.staticParams.fDecayDur = 0i64;
  *(_QWORD *)&this->m_Params.staticParams.fSustainVal = 0i64;
  this->m_Params.staticParams.uChannelMask = 4;
  return 1i64;
}

// File Line: 91
// RVA: 0xAD1E60
__int64 __fastcall CAkToneGenParams::SetParamsBlock(
        CAkToneGenParams *this,
        char *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  this->m_Params.fGain = *(float *)in_pParamsBlock;
  this->m_Params.fStartFreq = *((float *)in_pParamsBlock + 1);
  this->m_Params.fStopFreq = *((float *)in_pParamsBlock + 2);
  this->m_Params.staticParams.fStartFreqRandMin = *((float *)in_pParamsBlock + 3);
  this->m_Params.staticParams.fStartFreqRandMax = *((float *)in_pParamsBlock + 4);
  this->m_Params.staticParams.bFreqSweep = in_pParamsBlock[20];
  this->m_Params.staticParams.eGenSweep = *(_DWORD *)(in_pParamsBlock + 21);
  this->m_Params.staticParams.fStopFreqRandMin = *(float *)(in_pParamsBlock + 25);
  this->m_Params.staticParams.fStopFreqRandMax = *(float *)(in_pParamsBlock + 29);
  this->m_Params.staticParams.eGenType = *(_DWORD *)(in_pParamsBlock + 33);
  this->m_Params.staticParams.eGenMode = *(_DWORD *)(in_pParamsBlock + 37);
  this->m_Params.staticParams.fFixDur = *(float *)(in_pParamsBlock + 41);
  this->m_Params.staticParams.fAttackDur = *(float *)(in_pParamsBlock + 45);
  this->m_Params.staticParams.fDecayDur = *(float *)(in_pParamsBlock + 49);
  this->m_Params.staticParams.fSustainDur = *(float *)(in_pParamsBlock + 53);
  this->m_Params.staticParams.fSustainVal = *(float *)(in_pParamsBlock + 57);
  this->m_Params.staticParams.fReleaseDur = *(float *)(in_pParamsBlock + 61);
  this->m_Params.staticParams.uChannelMask = *(_DWORD *)(in_pParamsBlock + 65);
  return 1i64;
}

// File Line: 121
// RVA: 0xAD1CF0
__int64 __fastcall CAkToneGenParams::SetParam(
        CAkToneGenParams *this,
        __int16 in_ParamID,
        float *in_pValue,
        unsigned int __formal)
{
  __int64 result; // rax

  if ( !in_pValue )
    return 31i64;
  switch ( in_ParamID )
  {
    case 0:
      this->m_Params.fGain = *in_pValue;
      result = 1i64;
      break;
    case 1:
      this->m_Params.fStartFreq = *in_pValue;
      result = 1i64;
      break;
    case 2:
      this->m_Params.staticParams.fStartFreqRandMin = *in_pValue;
      result = 1i64;
      break;
    case 3:
      this->m_Params.staticParams.fStartFreqRandMax = *in_pValue;
      result = 1i64;
      break;
    case 4:
      this->m_Params.staticParams.bFreqSweep = *(_BYTE *)in_pValue;
      result = 1i64;
      break;
    case 5:
      this->m_Params.staticParams.eGenSweep = *(AkToneGenSweep *)in_pValue;
      result = 1i64;
      break;
    case 6:
      this->m_Params.fStopFreq = *in_pValue;
      result = 1i64;
      break;
    case 7:
      this->m_Params.staticParams.fStopFreqRandMin = *in_pValue;
      result = 1i64;
      break;
    case 8:
      this->m_Params.staticParams.fStopFreqRandMax = *in_pValue;
      result = 1i64;
      break;
    case 9:
      this->m_Params.staticParams.eGenType = *(AkToneGenType *)in_pValue;
      result = 1i64;
      break;
    case 10:
      this->m_Params.staticParams.eGenMode = *(AkToneGenMode *)in_pValue;
      result = 1i64;
      break;
    case 11:
      this->m_Params.staticParams.fFixDur = *in_pValue;
      result = 1i64;
      break;
    case 12:
      this->m_Params.staticParams.fAttackDur = *in_pValue;
      result = 1i64;
      break;
    case 13:
      this->m_Params.staticParams.fDecayDur = *in_pValue;
      result = 1i64;
      break;
    case 14:
      this->m_Params.staticParams.fSustainDur = *in_pValue;
      result = 1i64;
      break;
    case 15:
      this->m_Params.staticParams.fSustainVal = *in_pValue;
      result = 1i64;
      break;
    case 16:
      this->m_Params.staticParams.fReleaseDur = *in_pValue;
      result = 1i64;
      break;
    case 17:
      this->m_Params.staticParams.uChannelMask = *(unsigned int *)in_pValue;
      goto LABEL_22;
    default:
LABEL_22:
      result = 1i64;
      break;
  }
  return result;
}


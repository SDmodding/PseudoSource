// File Line: 18
// RVA: 0xAC1280
AK::IAkPluginParam *__fastcall CreateMatrixReverbFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 112i64);
  if ( result )
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFDNReverbFXParams::`vftable;
  return result;
}

// File Line: 24
// RVA: 0xAC12B0
void __fastcall CAkFDNReverbFXParams::CAkFDNReverbFXParams(CAkFDNReverbFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFDNReverbFXParams::`vftable;
}

// File Line: 28
// RVA: 0xAC12D0
void __fastcall CAkFDNReverbFXParams::~CAkFDNReverbFXParams(CAkFDNReverbFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
}

// File Line: 33
// RVA: 0xAC12F0
void __fastcall CAkFDNReverbFXParams::CAkFDNReverbFXParams(CAkFDNReverbFXParams *this, CAkFDNReverbFXParams *in_rCopy)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFDNReverbFXParams::`vftable;
  this->AkFDNReverbFXParams = in_rCopy->AkFDNReverbFXParams;
  this->NonRTPC.bDirty = 1;
}

// File Line: 41
// RVA: 0xAC13A0
void __fastcall CAkFDNReverbFXParams::Clone(CAkFDNReverbFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkFDNReverbFXParams *v3; // rax

  v3 = (CAkFDNReverbFXParams *)in_pAllocator->vfptr->Malloc(in_pAllocator, 112i64);
  if ( v3 )
    CAkFDNReverbFXParams::CAkFDNReverbFXParams(v3, this);
}

// File Line: 50
// RVA: 0xAC13E0
__int64 __fastcall CAkFDNReverbFXParams::Init(
        CAkFDNReverbFXParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        const void *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  float v5; // xmm0_4
  __int64 result; // rax

  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkFDNReverbFXParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  this->RTPC.fReverbTime = 4.0;
  this->RTPC.fHFRatio = 2.0;
  this->RTPC.fDryLevel = powf(10.0, -0.15000001);
  v5 = powf(10.0, -0.5);
  *(_QWORD *)&this->NonRTPC.uNumberOfDelays = 8i64;
  *(_QWORD *)&this->NonRTPC.uProcessLFE = 1i64;
  this->NonRTPC.bDirty = 1;
  result = 1i64;
  this->RTPC.fWetLevel = v5;
  return result;
}

// File Line: 72
// RVA: 0xAC1470
__int64 __fastcall CAkFDNReverbFXParams::Term(CAkFDNReverbFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 81
// RVA: 0xAC14B0
__int64 __fastcall CAkFDNReverbFXParams::SetParamsBlock(
        CAkFDNReverbFXParams *this,
        float *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  float *v3; // rbx
  unsigned int v5; // esi
  float v6; // xmm0_4
  __int64 v7; // rcx
  BOOL v8; // eax
  float *v9; // rbx
  unsigned int v10; // eax
  float v11; // xmm0_4

  v3 = in_pParamsBlock + 1;
  this->RTPC.fReverbTime = *in_pParamsBlock;
  this->RTPC.fHFRatio = in_pParamsBlock[1];
  v5 = *((_DWORD *)in_pParamsBlock + 2);
  this->NonRTPC.uNumberOfDelays = v5;
  this->RTPC.fDryLevel = powf(10.0, in_pParamsBlock[3] * 0.050000001);
  v6 = powf(10.0, v3[3] * 0.050000001);
  v7 = 0i64;
  this->RTPC.fWetLevel = v6;
  this->NonRTPC.fPreDelay = v3[4];
  v8 = *((_BYTE *)v3 + 20) != 0;
  v9 = (float *)((char *)v3 + 25);
  this->NonRTPC.uProcessLFE = v8;
  v10 = *((_DWORD *)v9 - 1);
  this->NonRTPC.uDelayLengthsMode = v10;
  if ( v10 == 1 && v5 )
  {
    do
    {
      v11 = *v9++;
      this->NonRTPC.fDelayTime[v7] = v11;
      v7 = (unsigned int)(v7 + 1);
    }
    while ( (unsigned int)v7 < this->NonRTPC.uNumberOfDelays );
  }
  this->NonRTPC.bDirty = 1;
  return 1i64;
}

// File Line: 116
// RVA: 0xAC1590
__int64 __fastcall CAkFDNReverbFXParams::SetParam(
        CAkFDNReverbFXParams *this,
        __int16 in_ParamID,
        float *in_pValue,
        unsigned int in_ulParamSize)
{
  __int64 result; // rax
  float v6; // eax
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // eax
  bool v10; // zf
  float v11; // eax

  switch ( in_ParamID )
  {
    case 0:
      this->RTPC.fReverbTime = *in_pValue;
      result = 1i64;
      break;
    case 1:
      this->RTPC.fHFRatio = *in_pValue;
      result = 1i64;
      break;
    case 2:
      v6 = *in_pValue;
      this->NonRTPC.bDirty = 1;
      *(float *)&this->NonRTPC.uNumberOfDelays = v6;
      result = 1i64;
      break;
    case 3:
      v7 = powf(10.0, *in_pValue * 0.050000001);
      result = 1i64;
      this->RTPC.fDryLevel = v7;
      break;
    case 4:
      v8 = powf(10.0, *in_pValue * 0.050000001);
      result = 1i64;
      this->RTPC.fWetLevel = v8;
      break;
    case 5:
      v9 = *in_pValue;
      this->NonRTPC.bDirty = 1;
      this->NonRTPC.fPreDelay = v9;
      result = 1i64;
      break;
    case 6:
      v10 = *(_BYTE *)in_pValue == 0;
      this->NonRTPC.bDirty = 1;
      this->NonRTPC.uProcessLFE = !v10;
      result = 1i64;
      break;
    case 7:
      v11 = *in_pValue;
      this->NonRTPC.bDirty = 1;
      *(float *)&this->NonRTPC.uDelayLengthsMode = v11;
      result = 1i64;
      break;
    default:
      *(&this->RTPC.fReverbTime + in_ParamID) = *in_pValue;
      this->NonRTPC.bDirty = 1;
      result = 1i64;
      break;
  }
  return result;
}


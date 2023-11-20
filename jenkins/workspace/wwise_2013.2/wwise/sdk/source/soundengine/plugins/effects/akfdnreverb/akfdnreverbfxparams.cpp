// File Line: 18
// RVA: 0xAC1280
AK::IAkPluginParam *__fastcall CreateMatrixReverbFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 112ui64);
  if ( result )
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFDNReverbFXParams::`vftable';
  return result;
}

// File Line: 24
// RVA: 0xAC12B0
void __fastcall CAkFDNReverbFXParams::CAkFDNReverbFXParams(CAkFDNReverbFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFDNReverbFXParams::`vftable';
}

// File Line: 28
// RVA: 0xAC12D0
void __fastcall CAkFDNReverbFXParams::~CAkFDNReverbFXParams(CAkFDNReverbFXParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable';
}

// File Line: 33
// RVA: 0xAC12F0
void __fastcall CAkFDNReverbFXParams::CAkFDNReverbFXParams(CAkFDNReverbFXParams *this, CAkFDNReverbFXParams *in_rCopy)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkFDNReverbFXParams::`vftable';
  this->RTPC.fReverbTime = in_rCopy->RTPC.fReverbTime;
  this->RTPC.fHFRatio = in_rCopy->RTPC.fHFRatio;
  this->RTPC.fDryLevel = in_rCopy->RTPC.fDryLevel;
  this->RTPC.fWetLevel = in_rCopy->RTPC.fWetLevel;
  this->NonRTPC.uNumberOfDelays = in_rCopy->NonRTPC.uNumberOfDelays;
  this->NonRTPC.fPreDelay = in_rCopy->NonRTPC.fPreDelay;
  this->NonRTPC.uProcessLFE = in_rCopy->NonRTPC.uProcessLFE;
  this->NonRTPC.uDelayLengthsMode = in_rCopy->NonRTPC.uDelayLengthsMode;
  this->NonRTPC.fDelayTime[0] = in_rCopy->NonRTPC.fDelayTime[0];
  this->NonRTPC.fDelayTime[1] = in_rCopy->NonRTPC.fDelayTime[1];
  this->NonRTPC.fDelayTime[2] = in_rCopy->NonRTPC.fDelayTime[2];
  this->NonRTPC.fDelayTime[3] = in_rCopy->NonRTPC.fDelayTime[3];
  this->NonRTPC.fDelayTime[4] = in_rCopy->NonRTPC.fDelayTime[4];
  this->NonRTPC.fDelayTime[5] = in_rCopy->NonRTPC.fDelayTime[5];
  this->NonRTPC.fDelayTime[6] = in_rCopy->NonRTPC.fDelayTime[6];
  this->NonRTPC.fDelayTime[7] = in_rCopy->NonRTPC.fDelayTime[7];
  this->NonRTPC.fDelayTime[8] = in_rCopy->NonRTPC.fDelayTime[8];
  this->NonRTPC.fDelayTime[9] = in_rCopy->NonRTPC.fDelayTime[9];
  this->NonRTPC.fDelayTime[10] = in_rCopy->NonRTPC.fDelayTime[10];
  this->NonRTPC.fDelayTime[11] = in_rCopy->NonRTPC.fDelayTime[11];
  this->NonRTPC.fDelayTime[12] = in_rCopy->NonRTPC.fDelayTime[12];
  this->NonRTPC.fDelayTime[13] = in_rCopy->NonRTPC.fDelayTime[13];
  this->NonRTPC.fDelayTime[14] = in_rCopy->NonRTPC.fDelayTime[14];
  this->NonRTPC.fDelayTime[15] = in_rCopy->NonRTPC.fDelayTime[15];
  *(_DWORD *)&this->NonRTPC.bDirty = *(_DWORD *)&in_rCopy->NonRTPC.bDirty;
  this->NonRTPC.bDirty = 1;
}

// File Line: 41
// RVA: 0xAC13A0
void __fastcall CAkFDNReverbFXParams::Clone(CAkFDNReverbFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkFDNReverbFXParams *v2; // rbx
  CAkFDNReverbFXParams *v3; // rax

  v2 = this;
  v3 = (CAkFDNReverbFXParams *)in_pAllocator->vfptr->Malloc(in_pAllocator, 112ui64);
  if ( v3 )
    CAkFDNReverbFXParams::CAkFDNReverbFXParams(v3, v2);
}

// File Line: 50
// RVA: 0xAC13E0
__int64 __fastcall CAkFDNReverbFXParams::Init(CAkFDNReverbFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  CAkFDNReverbFXParams *v4; // rbx
  float v5; // xmm0_4
  __int64 result; // rax

  v4 = this;
  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkFDNReverbFXParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  this->RTPC.fReverbTime = 4.0;
  this->RTPC.fHFRatio = 2.0;
  this->RTPC.fDryLevel = powf(10.0, -0.15000001);
  v5 = powf(10.0, -0.5);
  *(_QWORD *)&v4->NonRTPC.uNumberOfDelays = 8i64;
  *(_QWORD *)&v4->NonRTPC.uProcessLFE = 1i64;
  v4->NonRTPC.bDirty = 1;
  result = 1i64;
  v4->RTPC.fWetLevel = v5;
  return result;
}

// File Line: 72
// RVA: 0xAC1470
signed __int64 __fastcall CAkFDNReverbFXParams::Term(CAkFDNReverbFXParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkFDNReverbFXParams *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
  {
    this->vfptr->__vecDelDtor((AK::IAkRTPCSubscriber *)this, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 81
// RVA: 0xAC14B0
signed __int64 __fastcall CAkFDNReverbFXParams::SetParamsBlock(CAkFDNReverbFXParams *this, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  float *v3; // rbx
  CAkFDNReverbFXParams *v4; // rdi
  unsigned int v5; // esi
  float v6; // xmm0_4
  __int64 v7; // rcx
  BOOL v8; // eax
  float *v9; // rbx
  unsigned int v10; // eax
  float v11; // xmm0_4

  v3 = (float *)((char *)in_pParamsBlock + 4);
  v4 = this;
  this->RTPC.fReverbTime = *(float *)in_pParamsBlock;
  this->RTPC.fHFRatio = *((float *)in_pParamsBlock + 1);
  v5 = *((_DWORD *)in_pParamsBlock + 2);
  this->NonRTPC.uNumberOfDelays = v5;
  this->RTPC.fDryLevel = powf(10.0, *((float *)in_pParamsBlock + 3) * 0.050000001);
  v6 = powf(10.0, v3[3] * 0.050000001);
  v7 = 0i64;
  v4->RTPC.fWetLevel = v6;
  v4->NonRTPC.fPreDelay = v3[4];
  v8 = *((_BYTE *)v3 + 20) != 0;
  v9 = (float *)((char *)v3 + 25);
  v4->NonRTPC.uProcessLFE = v8;
  v10 = *((_DWORD *)v9 - 1);
  v4->NonRTPC.uDelayLengthsMode = v10;
  if ( v10 == 1 && v5 )
  {
    do
    {
      v11 = *v9;
      ++v9;
      v4->NonRTPC.fDelayTime[v7] = v11;
      v7 = (unsigned int)(v7 + 1);
    }
    while ( (unsigned int)v7 < v4->NonRTPC.uNumberOfDelays );
  }
  v4->NonRTPC.bDirty = 1;
  return 1i64;
}

// File Line: 116
// RVA: 0xAC1590
signed __int64 __fastcall CAkFDNReverbFXParams::SetParam(CAkFDNReverbFXParams *this, __int16 in_ParamID, const void *in_pValue, unsigned int in_ulParamSize)
{
  CAkFDNReverbFXParams *v4; // rbx
  signed __int64 result; // rax
  float v6; // eax
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // eax
  bool v10; // zf
  float v11; // eax

  v4 = this;
  switch ( in_ParamID )
  {
    case 0:
      this->RTPC.fReverbTime = *(float *)in_pValue;
      result = 1i64;
      break;
    case 1:
      this->RTPC.fHFRatio = *(float *)in_pValue;
      result = 1i64;
      break;
    case 2:
      v6 = *(float *)in_pValue;
      this->NonRTPC.bDirty = 1;
      *(float *)&this->NonRTPC.uNumberOfDelays = v6;
      result = 1i64;
      break;
    case 3:
      v7 = powf(10.0, *(float *)in_pValue * 0.050000001);
      result = 1i64;
      v4->RTPC.fDryLevel = v7;
      break;
    case 4:
      v8 = powf(10.0, *(float *)in_pValue * 0.050000001);
      result = 1i64;
      v4->RTPC.fWetLevel = v8;
      break;
    case 5:
      v9 = *(float *)in_pValue;
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
      v11 = *(float *)in_pValue;
      this->NonRTPC.bDirty = 1;
      *(float *)&this->NonRTPC.uDelayLengthsMode = v11;
      result = 1i64;
      break;
    default:
      *((_DWORD *)&this->RTPC.fReverbTime + in_ParamID) = *(_DWORD *)in_pValue;
      this->NonRTPC.bDirty = 1;
      result = 1i64;
      break;
  }
  return result;
}


// File Line: 20
// RVA: 0xADE7D0
AK::IAkPluginParam *__fastcall CreateAkSoundSeedImpactFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 72ui64);
  if ( result )
  {
    result->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkModalSynthParams::`vftable;
    result[1].vfptr = 0i64;
    result[7].vfptr = 0i64;
    LODWORD(result[8].vfptr) = 0;
  }
  return result;
}

// File Line: 30
// RVA: 0xADE820
void __fastcall CAkModalSynthParams::CAkModalSynthParams(CAkModalSynthParams *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkModalSynthParams::`vftable;
  this->m_pAllocator = 0i64;
  this->m_pModes = 0i64;
  this->m_cModes = 0;
}

// File Line: 34
// RVA: 0xADE850
void __fastcall CAkModalSynthParams::~CAkModalSynthParams(CAkModalSynthParams *this)
{
  AkModalSynthMode *v1; // rdx
  CAkModalSynthParams *v2; // rbx

  v1 = this->m_pModes;
  v2 = this;
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkModalSynthParams::`vftable;
  if ( v1 )
  {
    ((void (*)(void))this->m_pAllocator->vfptr->Free)();
    v2->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
  }
  else
  {
    this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
  }
}

// File Line: 41
// RVA: 0xADE8A0
void __fastcall CAkModalSynthParams::CAkModalSynthParams(CAkModalSynthParams *this, CAkModalSynthParams *in_rCopy)
{
  CAkModalSynthParams *v2; // rbx
  CAkModalSynthParams *v3; // rdi
  AK::IAkPluginMemAlloc *v4; // rcx
  __int64 v5; // rdx
  __int64 v6; // rax
  unsigned int v7; // er9
  unsigned int v8; // eax
  AkModalSynthMode *v9; // rcx
  AkModalSynthMode *v10; // rdx
  signed __int64 v11; // r8

  v2 = this;
  v3 = in_rCopy;
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkModalSynthParams::`vftable;
  v4 = in_rCopy->m_pAllocator;
  v2->m_pAllocator = v4;
  v2->m_Params.fResidualLevel = in_rCopy->m_Params.fResidualLevel;
  v2->m_Params.fOutputLevel = in_rCopy->m_Params.fOutputLevel;
  v2->m_Params.fFreqAmt = in_rCopy->m_Params.fFreqAmt;
  v2->m_Params.fFreqVar = in_rCopy->m_Params.fFreqVar;
  v2->m_Params.fBWAmt = in_rCopy->m_Params.fBWAmt;
  v2->m_Params.fBWVar = in_rCopy->m_Params.fBWVar;
  v2->m_Params.fMagVar = in_rCopy->m_Params.fMagVar;
  v2->m_Params.fModelQuality = in_rCopy->m_Params.fModelQuality;
  *(_DWORD *)&v2->m_Params.bFreqEnable = *(_DWORD *)&in_rCopy->m_Params.bFreqEnable;
  v2->m_fGlobalGain = in_rCopy->m_fGlobalGain;
  if ( !in_rCopy->m_pModes || (v5 = in_rCopy->m_cModes, !(_DWORD)v5) )
  {
    v2->m_pModes = 0i64;
    goto LABEL_8;
  }
  v6 = (__int64)v4->vfptr->Malloc(v4, 16 * v5);
  v7 = 0;
  v2->m_pModes = (AkModalSynthMode *)v6;
  if ( !v6 )
  {
LABEL_8:
    v2->m_cModes = 0;
    return;
  }
  v8 = v3->m_cModes;
  v2->m_cModes = v8;
  if ( v8 )
  {
    do
    {
      v9 = v3->m_pModes;
      v10 = v2->m_pModes;
      v11 = v7++;
      v10[v11].fFreq = v9[v11].fFreq;
      v10[v11].fMag = v9[v11].fMag;
      v10[v11].fBW = v9[v11].fBW;
      v10[v11].fMagTrans = v9[v11].fMagTrans;
    }
    while ( v7 < v2->m_cModes );
  }
}

// File Line: 70
// RVA: 0xADE9A0
void __fastcall CAkModalSynthParams::Clone(CAkModalSynthParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkModalSynthParams *v2; // rbx
  CAkModalSynthParams *v3; // rax

  v2 = this;
  v3 = (CAkModalSynthParams *)in_pAllocator->vfptr->Malloc(in_pAllocator, 72ui64);
  if ( v3 )
    CAkModalSynthParams::CAkModalSynthParams(v3, v2);
}

// File Line: 79
// RVA: 0xADE9E0
__int64 __fastcall CAkModalSynthParams::Init(CAkModalSynthParams *this, AK::IAkPluginMemAlloc *in_pAllocator, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  CAkModalSynthParams *v4; // rbx
  float v5; // xmm0_4
  __int64 result; // rax

  v4 = this;
  this->m_pAllocator = in_pAllocator;
  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkModalSynthParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  v5 = powf(10.0, 0.0);
  v4->m_Params.fModelQuality = 100.0;
  v4->m_Params.fMagVar = 0.0;
  *(_QWORD *)&v4->m_Params.fFreqAmt = 0i64;
  *(_QWORD *)&v4->m_Params.fBWAmt = 0i64;
  v4->m_Params.fResidualLevel = v5;
  v4->m_Params.fOutputLevel = v5;
  result = 1i64;
  *(_WORD *)&v4->m_Params.bFreqEnable = 257;
  v4->m_Params.bMagEnable = 1;
  return result;
}

// File Line: 102
// RVA: 0xADEA50
signed __int64 __fastcall CAkModalSynthParams::Term(CAkModalSynthParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkModalSynthParams *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  if ( this )
  {
    this->vfptr->__vecDelDtor((AK::IAkRTPCSubscriber *)this, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 112
// RVA: 0xADEA90
AKRESULT __fastcall CAkModalSynthParams::SetParamsBlock(CAkModalSynthParams *this, const void *in_pParamsBlock, unsigned int in_ulBlockSize)
{
  CAkModalSynthParams *v3; // rdi
  char *v4; // rbx
  float v5; // xmm0_4
  char *in_pParamsBlocka; // [rsp+30h] [rbp+8h]
  unsigned int in_ulBlockSizea; // [rsp+40h] [rbp+18h]

  v3 = this;
  v4 = (char *)in_pParamsBlock + 4;
  this->m_Params.fResidualLevel = powf(10.0, *(float *)in_pParamsBlock * 0.050000001);
  v5 = powf(10.0, *(float *)v4 * 0.050000001);
  v4 += 31;
  in_pParamsBlocka = v4;
  v3->m_Params.fOutputLevel = v5;
  v3->m_Params.fFreqAmt = *(float *)(v4 - 27);
  v3->m_Params.fFreqVar = *(float *)(v4 - 23);
  v3->m_Params.fBWAmt = *(float *)(v4 - 19);
  v3->m_Params.fBWVar = *(float *)(v4 - 15);
  v3->m_Params.fMagVar = *(float *)(v4 - 11);
  v3->m_Params.fModelQuality = *(float *)(v4 - 7);
  v3->m_Params.bFreqEnable = *(v4 - 3);
  v3->m_Params.bBWEnable = *(v4 - 2);
  v3->m_Params.bMagEnable = *(v4 - 1);
  return CAkModalSynthParams::ReadModes(v3, &in_pParamsBlocka, &in_ulBlockSizea);
}

// File Line: 134
// RVA: 0xADEFD0
signed __int64 __fastcall CAkModalSynthParams::ReadModes(CAkModalSynthParams *this, char **in_pParamsBlock, unsigned int *in_ulBlockSize)
{
  char **v3; // rdi
  AkModalSynthMode *v4; // rdx
  CAkModalSynthParams *v5; // rbx
  signed __int64 v6; // rax
  unsigned int v7; // ecx
  __int64 v8; // rax
  unsigned int i; // edx
  __int64 v11; // rcx
  signed __int64 v12; // rax
  signed __int64 v13; // rax
  signed __int64 v14; // rax

  v3 = in_pParamsBlock;
  v4 = this->m_pModes;
  v5 = this;
  if ( v4 )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *, AkModalSynthMode *, unsigned int *))this->m_pAllocator->vfptr->Free)(
      this->m_pAllocator,
      v4,
      in_ulBlockSize);
    v5->m_pModes = 0i64;
  }
  v6 = (signed __int64)(*v3 + 4);
  *v3 = (char *)v6;
  v5->m_fGlobalGain = *(float *)(v6 - 4);
  v7 = *(unsigned __int16 *)*v3;
  *v3 += 2;
  v5->m_cModes = v7;
  if ( v7 )
  {
    v8 = ((__int64 (__fastcall *)(AK::IAkPluginMemAlloc *, signed __int64, unsigned int *))v5->m_pAllocator->vfptr->Malloc)(
           v5->m_pAllocator,
           16i64 * v7,
           in_ulBlockSize);
    v5->m_pModes = (AkModalSynthMode *)v8;
    if ( !v8 )
      return 52i64;
    for ( i = 0; i < v5->m_cModes; *((_DWORD *)&v5->m_pModes->fMagTrans + 2 * v11) = 0 )
    {
      v11 = i++;
      v12 = (signed __int64)(*v3 + 4);
      v11 *= 2i64;
      *v3 = (char *)v12;
      *((_DWORD *)&v5->m_pModes->fFreq + 2 * v11) = *(_DWORD *)(v12 - 4);
      v13 = (signed __int64)(*v3 + 4);
      *v3 = (char *)v13;
      *((_DWORD *)&v5->m_pModes->fMag + 2 * v11) = *(_DWORD *)(v13 - 4);
      v14 = (signed __int64)(*v3 + 4);
      *v3 = (char *)v14;
      *((_DWORD *)&v5->m_pModes->fBW + 2 * v11) = *(_DWORD *)(v14 - 4);
    }
  }
  return 1i64;
}

// File Line: 166
// RVA: 0xADEB60
AKRESULT __fastcall CAkModalSynthParams::SetParam(CAkModalSynthParams *this, __int16 in_ParamID, const void *in_pValue, unsigned int in_ulParamSize)
{
  CAkModalSynthParams *v4; // rbx
  AKRESULT result; // eax
  float v6; // xmm0_4
  float v7; // xmm0_4
  char *in_pParamsBlock; // [rsp+40h] [rbp+18h]
  unsigned int in_ulBlockSize; // [rsp+48h] [rbp+20h]

  v4 = this;
  if ( !in_pValue )
    return 31;
  if ( in_ParamID > 0x7FFF )
    return 31;
  if ( in_ParamID == 0x7FFF )
  {
    in_pParamsBlock = (char *)in_pValue;
    result = CAkModalSynthParams::ReadModes(this, &in_pParamsBlock, &in_ulBlockSize);
  }
  else
  {
    switch ( in_ParamID )
    {
      case 0:
        v6 = powf(10.0, *(float *)in_pValue * 0.050000001);
        result = 1;
        v4->m_Params.fResidualLevel = v6;
        break;
      case 1:
        this->m_Params.fFreqAmt = *(float *)in_pValue;
        result = 1;
        break;
      case 2:
        this->m_Params.fFreqVar = *(float *)in_pValue;
        result = 1;
        break;
      case 3:
        this->m_Params.fBWAmt = *(float *)in_pValue;
        result = 1;
        break;
      case 4:
        this->m_Params.fBWVar = *(float *)in_pValue;
        result = 1;
        break;
      case 5:
        this->m_Params.fMagVar = *(float *)in_pValue;
        result = 1;
        break;
      case 6:
        if ( *(float *)in_pValue == 0.0 )
        {
          this->m_Params.bFreqEnable = 0;
          result = 1;
        }
        else
        {
          result = 1;
          this->m_Params.bFreqEnable = 1;
        }
        break;
      case 7:
        if ( *(float *)in_pValue == 0.0 )
        {
          this->m_Params.bBWEnable = 0;
          result = 1;
        }
        else
        {
          result = 1;
          this->m_Params.bBWEnable = 1;
        }
        break;
      case 8:
        if ( *(float *)in_pValue == 0.0 )
        {
          this->m_Params.bMagEnable = 0;
          result = 1;
        }
        else
        {
          result = 1;
          this->m_Params.bMagEnable = 1;
        }
        break;
      case 9:
        this->m_Params.fModelQuality = *(float *)in_pValue;
        result = 1;
        break;
      case 10:
        v7 = powf(10.0, *(float *)in_pValue * 0.050000001);
        result = 1;
        v4->m_Params.fOutputLevel = v7;
        break;
      default:
        return 31;
    }
  }
  return result;
}

// File Line: 231
// RVA: 0xADF0E0
void __fastcall CAkModalSynthParams::GetRandomFreqStretchFactor(CAkModalSynthParams *this)
{
  CAkModalSynthParams *v1; // rbx
  float v2; // xmm1_4

  v1 = this;
  v2 = (double)rand() * 0.00003051850947599719;
  powf(
    2.0,
    (float)((float)((float)((float)(v2 * 2.0) - 1.0) * v1->m_Params.fFreqVar) + v1->m_Params.fFreqAmt) * 0.0099999998);
}

// File Line: 239
// RVA: 0xADF140
void __fastcall CAkModalSynthParams::GetRandomBWStretchFactor(CAkModalSynthParams *this)
{
  CAkModalSynthParams *v1; // rbx
  float v2; // xmm1_4

  v1 = this;
  v2 = (double)rand() * 0.00003051850947599719;
  powf(
    2.0,
    (float)((float)((float)((float)(v2 * 2.0) - 1.0) * v1->m_Params.fBWVar) + v1->m_Params.fBWAmt) * 0.0099999998);
}

// File Line: 247
// RVA: 0xADF1A0
float __fastcall CAkModalSynthParams::GetRandomMagOffset(CAkModalSynthParams *this)
{
  return (float)((float)((float)((double)rand() * 0.00003051850947599719) * 2.0) - 1.0) * this->m_Params.fMagVar;
}

// File Line: 253
// RVA: 0xADED70
void __fastcall CAkModalSynthParams::DoModelTransforms(CAkModalSynthParams *this, float in_fSampleRate)
{
  __int64 v2; // rdi
  CAkModalSynthParams *v3; // rbx
  float v4; // xmm7_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  unsigned int v7; // er9
  float i; // xmm2_4
  AkModalSynthMode *v9; // r8
  float v10; // xmm0_4
  unsigned int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  unsigned int j; // edx
  signed __int64 v15; // rcx
  unsigned int v16; // eax
  __int64 v17; // rsi
  float v18; // xmm1_4

  v2 = 0i64;
  v3 = this;
  v4 = in_fSampleRate * 0.5;
  if ( this->m_Params.bFreqEnable && (0.0 != this->m_Params.fFreqAmt || 0.0 != this->m_Params.fFreqVar) )
  {
    v5 = (double)rand() * 0.00003051850947599719;
    v6 = powf(
           2.0,
           (float)((float)((float)((float)(v5 * 2.0) - 1.0) * v3->m_Params.fFreqVar) + v3->m_Params.fFreqAmt)
         * 0.0099999998);
    v7 = 0;
    for ( i = v6; v7 < v3->m_cModes; ++v7 )
    {
      v9 = v3->m_pModes;
      v10 = i * v9[v7].fFreq;
      if ( v10 < v4 )
      {
        if ( v10 >= 20.0 )
          v9[v7].fFreq = v10;
        else
          v9[v7].fFreq = 20.0;
      }
      else
      {
        v11 = --v3->m_cModes;
        if ( v7 < v11 )
        {
          v9[v7].fFreq = v9[v11].fFreq;
          v9[v7].fMag = v9[v11].fMag;
          v9[v7].fBW = v9[v11].fBW;
          v9[v7].fMagTrans = v9[v11].fMagTrans;
        }
      }
    }
  }
  if ( v3->m_Params.bBWEnable && (0.0 != v3->m_Params.fBWAmt || 0.0 != v3->m_Params.fBWVar) )
  {
    v12 = (double)rand() * 0.00003051850947599719;
    v13 = powf(
            2.0,
            (float)((float)((float)((float)(v12 * 2.0) - 1.0) * v3->m_Params.fBWVar) + v3->m_Params.fBWAmt)
          * 0.0099999998);
    for ( j = 0; j < v3->m_cModes; v3->m_pModes[v15].fBW = v13 * v3->m_pModes[v15].fBW )
      v15 = j++;
  }
  if ( v3->m_Params.bMagEnable )
  {
    if ( 0.0 != v3->m_Params.fMagVar )
    {
      v16 = v3->m_cModes >> 1;
      if ( v16 )
      {
        v17 = ((v16 - 1) >> 1) + 1;
        do
        {
          v2 += 2i64;
          v18 = (float)((float)((float)((double)rand() * 0.00003051850947599719) * 2.0) - 1.0) * v3->m_Params.fMagVar;
          *((_DWORD *)&v3->m_pModes[v2 - 1] - 1) = LODWORD(v18) ^ _xmm[0];
          *((float *)&v3->m_pModes[v2] - 1) = v18;
          --v17;
        }
        while ( v17 );
      }
    }
  }
}


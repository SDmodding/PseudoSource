// File Line: 20
// RVA: 0xADE7D0
AK::IAkPluginParam *__fastcall CreateAkSoundSeedImpactFXParams(AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginParam *result; // rax

  result = (AK::IAkPluginParam *)in_pAllocator->vfptr->Malloc(in_pAllocator, 72i64);
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
  AkModalSynthMode *m_pModes; // rdx

  m_pModes = this->m_pModes;
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkModalSynthParams::`vftable;
  if ( m_pModes )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Free)(this->m_pAllocator);
    this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable;
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
  AK::IAkPluginMemAlloc *m_pAllocator; // rcx
  __int64 m_cModes; // rdx
  AkModalSynthMode *v6; // rax
  unsigned int v7; // r9d
  unsigned int v8; // eax
  AkModalSynthMode *m_pModes; // rcx
  AkModalSynthMode *v10; // rdx
  __int64 v11; // r8

  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&CAkModalSynthParams::`vftable;
  m_pAllocator = in_rCopy->m_pAllocator;
  this->m_pAllocator = m_pAllocator;
  this->m_Params = in_rCopy->m_Params;
  this->m_fGlobalGain = in_rCopy->m_fGlobalGain;
  if ( !in_rCopy->m_pModes || (m_cModes = in_rCopy->m_cModes, !(_DWORD)m_cModes) )
  {
    this->m_pModes = 0i64;
    goto LABEL_8;
  }
  v6 = (AkModalSynthMode *)m_pAllocator->vfptr->Malloc(m_pAllocator, 16 * m_cModes);
  v7 = 0;
  this->m_pModes = v6;
  if ( !v6 )
  {
LABEL_8:
    this->m_cModes = 0;
    return;
  }
  v8 = in_rCopy->m_cModes;
  this->m_cModes = v8;
  if ( v8 )
  {
    do
    {
      m_pModes = in_rCopy->m_pModes;
      v10 = this->m_pModes;
      v11 = v7++;
      v10[v11].fFreq = m_pModes[v11].fFreq;
      v10[v11].fMag = m_pModes[v11].fMag;
      v10[v11].fBW = m_pModes[v11].fBW;
      v10[v11].fMagTrans = m_pModes[v11].fMagTrans;
    }
    while ( v7 < this->m_cModes );
  }
}

// File Line: 70
// RVA: 0xADE9A0
void __fastcall CAkModalSynthParams::Clone(CAkModalSynthParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkModalSynthParams *v3; // rax

  v3 = (CAkModalSynthParams *)in_pAllocator->vfptr->Malloc(in_pAllocator, 72i64);
  if ( v3 )
    CAkModalSynthParams::CAkModalSynthParams(v3, this);
}

// File Line: 79
// RVA: 0xADE9E0
__int64 __fastcall CAkModalSynthParams::Init(
        CAkModalSynthParams *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        const void *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  float v5; // xmm0_4
  __int64 result; // rax

  this->m_pAllocator = in_pAllocator;
  if ( in_ulBlockSize )
    return ((__int64 (__fastcall *)(CAkModalSynthParams *, const void *, _QWORD))this->vfptr[2].SetParam)(
             this,
             in_pParamsBlock,
             in_ulBlockSize);
  v5 = powf(10.0, 0.0);
  this->m_Params.fModelQuality = 100.0;
  this->m_Params.fMagVar = 0.0;
  *(_QWORD *)&this->m_Params.fFreqAmt = 0i64;
  *(_QWORD *)&this->m_Params.fBWAmt = 0i64;
  this->m_Params.fResidualLevel = v5;
  this->m_Params.fOutputLevel = v5;
  result = 1i64;
  *(_WORD *)&this->m_Params.bFreqEnable = 257;
  this->m_Params.bMagEnable = 1;
  return result;
}

// File Line: 102
// RVA: 0xADEA50
__int64 __fastcall CAkModalSynthParams::Term(CAkModalSynthParams *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 112
// RVA: 0xADEA90
AKRESULT __fastcall CAkModalSynthParams::SetParamsBlock(
        CAkModalSynthParams *this,
        float *in_pParamsBlock,
        unsigned int in_ulBlockSize)
{
  char *v4; // rbx
  float v5; // xmm0_4
  char *in_pParamsBlocka; // [rsp+30h] [rbp+8h] BYREF
  unsigned int in_ulBlockSizea; // [rsp+40h] [rbp+18h] BYREF

  v4 = (char *)(in_pParamsBlock + 1);
  this->m_Params.fResidualLevel = powf(10.0, *in_pParamsBlock * 0.050000001);
  v5 = powf(10.0, *(float *)v4 * 0.050000001);
  v4 += 31;
  in_pParamsBlocka = v4;
  this->m_Params.fOutputLevel = v5;
  this->m_Params.fFreqAmt = *(float *)(v4 - 27);
  this->m_Params.fFreqVar = *(float *)(v4 - 23);
  this->m_Params.fBWAmt = *(float *)(v4 - 19);
  this->m_Params.fBWVar = *(float *)(v4 - 15);
  this->m_Params.fMagVar = *(float *)(v4 - 11);
  this->m_Params.fModelQuality = *(float *)(v4 - 7);
  this->m_Params.bFreqEnable = *(v4 - 3);
  this->m_Params.bBWEnable = *(v4 - 2);
  this->m_Params.bMagEnable = *(v4 - 1);
  return CAkModalSynthParams::ReadModes(this, &in_pParamsBlocka, &in_ulBlockSizea);
}

// File Line: 134
// RVA: 0xADEFD0
__int64 __fastcall CAkModalSynthParams::ReadModes(
        CAkModalSynthParams *this,
        char **in_pParamsBlock,
        unsigned int *in_ulBlockSize)
{
  AkModalSynthMode *m_pModes; // rdx
  char *v6; // rax
  unsigned int v7; // ecx
  AkModalSynthMode *v8; // rax
  unsigned int i; // edx
  __int64 v11; // rcx
  char *v12; // rax
  char *v13; // rax
  char *v14; // rax

  m_pModes = this->m_pModes;
  if ( m_pModes )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *, AkModalSynthMode *, unsigned int *))this->m_pAllocator->vfptr->Free)(
      this->m_pAllocator,
      m_pModes,
      in_ulBlockSize);
    this->m_pModes = 0i64;
  }
  v6 = *in_pParamsBlock + 4;
  *in_pParamsBlock = v6;
  this->m_fGlobalGain = *((float *)v6 - 1);
  v7 = *(unsigned __int16 *)*in_pParamsBlock;
  *in_pParamsBlock += 2;
  this->m_cModes = v7;
  if ( v7 )
  {
    v8 = (AkModalSynthMode *)((__int64 (__fastcall *)(AK::IAkPluginMemAlloc *, __int64, unsigned int *))this->m_pAllocator->vfptr->Malloc)(
                               this->m_pAllocator,
                               16i64 * v7,
                               in_ulBlockSize);
    this->m_pModes = v8;
    if ( !v8 )
      return 52i64;
    for ( i = 0; i < this->m_cModes; *((_DWORD *)&this->m_pModes->fMagTrans + 2 * v11) = 0 )
    {
      v11 = i++;
      v12 = *in_pParamsBlock + 4;
      v11 *= 2i64;
      *in_pParamsBlock = v12;
      *((_DWORD *)&this->m_pModes->fFreq + 2 * v11) = *((_DWORD *)v12 - 1);
      v13 = *in_pParamsBlock + 4;
      *in_pParamsBlock = v13;
      *((_DWORD *)&this->m_pModes->fMag + 2 * v11) = *((_DWORD *)v13 - 1);
      v14 = *in_pParamsBlock + 4;
      *in_pParamsBlock = v14;
      *((_DWORD *)&this->m_pModes->fBW + 2 * v11) = *((_DWORD *)v14 - 1);
    }
  }
  return 1i64;
}

// File Line: 166
// RVA: 0xADEB60
AKRESULT __fastcall CAkModalSynthParams::SetParam(
        CAkModalSynthParams *this,
        __int16 in_ParamID,
        char *in_pValue,
        unsigned int in_ulParamSize)
{
  AKRESULT result; // eax
  float v6; // xmm0_4
  float v7; // xmm0_4
  char *in_pParamsBlock; // [rsp+40h] [rbp+18h] BYREF
  unsigned int in_ulBlockSize; // [rsp+48h] [rbp+20h] BYREF

  if ( !in_pValue )
    return 31;
  if ( in_ParamID == 0x7FFF )
  {
    in_pParamsBlock = in_pValue;
    return CAkModalSynthParams::ReadModes(this, &in_pParamsBlock, &in_ulBlockSize);
  }
  else
  {
    switch ( in_ParamID )
    {
      case 0:
        v6 = powf(10.0, *(float *)in_pValue * 0.050000001);
        result = AK_Success;
        this->m_Params.fResidualLevel = v6;
        break;
      case 1:
        this->m_Params.fFreqAmt = *(float *)in_pValue;
        result = AK_Success;
        break;
      case 2:
        this->m_Params.fFreqVar = *(float *)in_pValue;
        result = AK_Success;
        break;
      case 3:
        this->m_Params.fBWAmt = *(float *)in_pValue;
        result = AK_Success;
        break;
      case 4:
        this->m_Params.fBWVar = *(float *)in_pValue;
        result = AK_Success;
        break;
      case 5:
        this->m_Params.fMagVar = *(float *)in_pValue;
        result = AK_Success;
        break;
      case 6:
        if ( *(float *)in_pValue == 0.0 )
        {
          this->m_Params.bFreqEnable = 0;
          result = AK_Success;
        }
        else
        {
          result = AK_Success;
          this->m_Params.bFreqEnable = 1;
        }
        break;
      case 7:
        if ( *(float *)in_pValue == 0.0 )
        {
          this->m_Params.bBWEnable = 0;
          result = AK_Success;
        }
        else
        {
          result = AK_Success;
          this->m_Params.bBWEnable = 1;
        }
        break;
      case 8:
        if ( *(float *)in_pValue == 0.0 )
        {
          this->m_Params.bMagEnable = 0;
          result = AK_Success;
        }
        else
        {
          result = AK_Success;
          this->m_Params.bMagEnable = 1;
        }
        break;
      case 9:
        this->m_Params.fModelQuality = *(float *)in_pValue;
        result = AK_Success;
        break;
      case 10:
        v7 = powf(10.0, *(float *)in_pValue * 0.050000001);
        result = AK_Success;
        this->m_Params.fOutputLevel = v7;
        break;
      default:
        result = AK_InvalidParameter;
        break;
    }
  }
  return result;
}

// File Line: 231
// RVA: 0xADF0E0
double __fastcall CAkModalSynthParams::GetRandomFreqStretchFactor(CAkModalSynthParams *this)
{
  float v2; // xmm1_4
  double result; // xmm0_8

  v2 = (double)rand() * 0.00003051850947599719;
  *(_QWORD *)&result = LODWORD(FLOAT_2_0);
  *(float *)&result = powf(
                        2.0,
                        (float)((float)((float)((float)(v2 * 2.0) - 1.0) * this->m_Params.fFreqVar)
                              + this->m_Params.fFreqAmt)
                      * 0.0099999998);
  return result;
}

// File Line: 239
// RVA: 0xADF140
double __fastcall CAkModalSynthParams::GetRandomBWStretchFactor(CAkModalSynthParams *this)
{
  float v2; // xmm1_4
  double result; // xmm0_8

  v2 = (double)rand() * 0.00003051850947599719;
  *(_QWORD *)&result = LODWORD(FLOAT_2_0);
  *(float *)&result = powf(
                        2.0,
                        (float)((float)((float)((float)(v2 * 2.0) - 1.0) * this->m_Params.fBWVar) + this->m_Params.fBWAmt)
                      * 0.0099999998);
  return result;
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
  float v4; // xmm7_4
  float v5; // xmm1_4
  unsigned int i; // r9d
  AkModalSynthMode *m_pModes; // r8
  float v8; // xmm0_4
  unsigned int v9; // eax
  float v10; // xmm1_4
  float v11; // xmm0_4
  unsigned int j; // edx
  __int64 v13; // rcx
  unsigned int v14; // eax
  __int64 v15; // rsi
  float v16; // xmm1_4

  v2 = 0i64;
  v4 = in_fSampleRate * 0.5;
  if ( this->m_Params.bFreqEnable && (this->m_Params.fFreqAmt != 0.0 || this->m_Params.fFreqVar != 0.0) )
  {
    v5 = (double)rand() * 0.00003051850947599719;
    powf(
      2.0,
      (float)((float)((float)((float)(v5 * 2.0) - 1.0) * this->m_Params.fFreqVar) + this->m_Params.fFreqAmt)
    * 0.0099999998);
    for ( i = 0; i < this->m_cModes; ++i )
    {
      m_pModes = this->m_pModes;
      v8 = 2.0 * m_pModes[i].fFreq;
      if ( v8 < v4 )
      {
        if ( v8 >= 20.0 )
          m_pModes[i].fFreq = v8;
        else
          m_pModes[i].fFreq = 20.0;
      }
      else
      {
        v9 = --this->m_cModes;
        if ( i < v9 )
        {
          m_pModes[i].fFreq = m_pModes[v9].fFreq;
          m_pModes[i].fMag = m_pModes[v9].fMag;
          m_pModes[i].fBW = m_pModes[v9].fBW;
          m_pModes[i].fMagTrans = m_pModes[v9].fMagTrans;
        }
      }
    }
  }
  if ( this->m_Params.bBWEnable && (this->m_Params.fBWAmt != 0.0 || this->m_Params.fBWVar != 0.0) )
  {
    v10 = (double)rand() * 0.00003051850947599719;
    v11 = powf(
            2.0,
            (float)((float)((float)((float)(v10 * 2.0) - 1.0) * this->m_Params.fBWVar) + this->m_Params.fBWAmt)
          * 0.0099999998);
    for ( j = 0; j < this->m_cModes; this->m_pModes[v13].fBW = v11 * this->m_pModes[v13].fBW )
      v13 = j++;
  }
  if ( this->m_Params.bMagEnable && this->m_Params.fMagVar != 0.0 )
  {
    v14 = this->m_cModes >> 1;
    if ( v14 )
    {
      v15 = ((v14 - 1) >> 1) + 1;
      do
      {
        v2 += 2i64;
        v16 = (float)((float)((float)((double)rand() * 0.00003051850947599719) * 2.0) - 1.0) * this->m_Params.fMagVar;
        *((_DWORD *)&this->m_pModes[v2 - 1] - 1) = LODWORD(v16) ^ _xmm[0];
        this->m_pModes[v2 - 1].fMagTrans = v16;
        --v15;
      }
      while ( v15 );
    }
  }
}


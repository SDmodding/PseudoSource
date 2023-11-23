// File Line: 49
// RVA: 0x15BE150
void dynamic_initializer_for__IIRCOEFCALCCONST__()
{
  IIRCOEFCALCCONST = log(10.0) * 0.25;
}

// File Line: 102
// RVA: 0xACBF60
__int64 __fastcall AkFDNQSortCompare(_DWORD *a, _DWORD *b)
{
  return (unsigned int)(*a - *b);
}

// File Line: 108
// RVA: 0xAC16D0
void __fastcall CreateMatrixReverbFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkFDNReverbFX *v1; // rax

  v1 = (CAkFDNReverbFX *)in_pAllocator->vfptr->Malloc(in_pAllocator, 608i64);
  if ( v1 )
    CAkFDNReverbFX::CAkFDNReverbFX(v1);
}

// File Line: 117
// RVA: 0xAC1700
void __fastcall CAkFDNReverbFX::CAkFDNReverbFX(CAkFDNReverbFX *this)
{
  float **m_pfDelayRead; // rcx

  this->vfptr = (AK::IAkPluginVtbl *)&CAkFDNReverbFX::`vftable;
  m_pfDelayRead = this->m_pfDelayRead;
  *(m_pfDelayRead - 14) = 0i64;
  *((_DWORD *)m_pfDelayRead + 109) = -1;
  *((_DWORD *)m_pfDelayRead + 110) = 0;
  *(m_pfDelayRead - 16) = 0i64;
  *(m_pfDelayRead - 15) = 0i64;
  *(m_pfDelayRead - 17) = 0i64;
  *(m_pfDelayRead - 13) = 0i64;
  *(m_pfDelayRead - 12) = 0i64;
  *(m_pfDelayRead - 11) = 0i64;
  m_pfDelayRead[16] = 0i64;
  m_pfDelayRead[17] = 0i64;
  m_pfDelayRead[18] = 0i64;
  m_pfDelayRead[19] = 0i64;
  m_pfDelayRead[24] = 0i64;
  m_pfDelayRead[25] = 0i64;
  m_pfDelayRead[26] = 0i64;
  m_pfDelayRead[27] = 0i64;
  memset(m_pfDelayRead, 0, 0x80ui64);
  this->m_pfDelayWrite[0] = 0i64;
  this->m_pfDelayWrite[1] = 0i64;
  this->m_pfDelayWrite[2] = 0i64;
  this->m_pfDelayWrite[3] = 0i64;
  *(_QWORD *)this->m_uNominalDelayLength = 0i64;
  *(_QWORD *)&this->m_uNominalDelayLength[2] = 0i64;
  *(_QWORD *)&this->m_uNominalDelayLength[4] = 0i64;
  *(_QWORD *)&this->m_uNominalDelayLength[6] = 0i64;
  *(_QWORD *)&this->m_uNominalDelayLength[8] = 0i64;
  *(_QWORD *)&this->m_uNominalDelayLength[10] = 0i64;
  *(_QWORD *)&this->m_uNominalDelayLength[12] = 0i64;
  *(_QWORD *)&this->m_uNominalDelayLength[14] = 0i64;
  this->m_vIIRLPFB0[0].m128_u64[0] = 0i64;
  this->m_vIIRLPFB0[0].m128_u64[1] = 0i64;
  this->m_vIIRLPFB0[1].m128_u64[0] = 0i64;
  this->m_vIIRLPFB0[1].m128_u64[1] = 0i64;
  this->m_vIIRLPFB0[2].m128_u64[0] = 0i64;
  this->m_vIIRLPFB0[2].m128_u64[1] = 0i64;
  this->m_vIIRLPFB0[3].m128_u64[0] = 0i64;
  this->m_vIIRLPFB0[3].m128_u64[1] = 0i64;
  this->m_vIIRLPFA1[0].m128_u64[0] = 0i64;
  this->m_vIIRLPFA1[0].m128_u64[1] = 0i64;
  this->m_vIIRLPFA1[1].m128_u64[0] = 0i64;
  this->m_vIIRLPFA1[1].m128_u64[1] = 0i64;
  this->m_vIIRLPFA1[2].m128_u64[0] = 0i64;
  this->m_vIIRLPFA1[2].m128_u64[1] = 0i64;
  this->m_vIIRLPFA1[3].m128_u64[0] = 0i64;
  this->m_vIIRLPFA1[3].m128_u64[1] = 0i64;
  this->m_vIIRLPFMem[0].m128_u64[0] = 0i64;
  this->m_vIIRLPFMem[0].m128_u64[1] = 0i64;
  this->m_vIIRLPFMem[1].m128_u64[0] = 0i64;
  this->m_vIIRLPFMem[1].m128_u64[1] = 0i64;
  this->m_vIIRLPFMem[2].m128_u64[0] = 0i64;
  this->m_vIIRLPFMem[2].m128_u64[1] = 0i64;
  this->m_vIIRLPFMem[3].m128_u64[0] = 0i64;
  this->m_vIIRLPFMem[3].m128_u64[1] = 0i64;
}

// File Line: 136
// RVA: 0xAC1890
void __fastcall CAkFDNReverbFX::~CAkFDNReverbFX(CAkFDNReverbFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 146
// RVA: 0xAC18B0
AKRESULT __fastcall CAkFDNReverbFX::Init(
        CAkFDNReverbFX *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkEffectPluginContext *in_pFXCtx,
        CAkFDNReverbFXParams *in_pParams,
        AkAudioFormat *in_rFormat)
{
  char v8; // al
  float m_uSampleRate; // xmm2_4

  this->m_uSampleRate = in_rFormat->uSampleRate;
  v8 = ((__int64 (__fastcall *)(AK::IAkEffectPluginContext *))in_pFXCtx->vfptr[1].__vecDelDtor)(in_pFXCtx);
  this->m_pAllocator = in_pAllocator;
  this->m_pParams = in_pParams;
  this->m_bIsSentMode = v8;
  *(AK::IAkPluginParam *)&this->m_fCurrentDry = *(AK::IAkPluginParam *)&in_pParams->RTPC.fDryLevel;
  m_uSampleRate = (float)(int)this->m_uSampleRate;
  this->m_fDCCoef = 1.0 - (float)(62.831856 / m_uSampleRate);
  this->m_uTailLength = (int)(float)(m_uSampleRate * in_pParams->RTPC.fReverbTime);
  return CAkFDNReverbFX::InitDelayLines(this, *((_DWORD *)in_rFormat + 1) & 0x3FFFF);
}

// File Line: 168
// RVA: 0xAC1970
__int64 __fastcall CAkFDNReverbFX::Term(CAkFDNReverbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkFDNReverbFX::TermDelayLines(this);
  if ( this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    in_pAllocator->vfptr->Free(in_pAllocator, this);
  }
  return 1i64;
}

// File Line: 177
// RVA: 0xAC19C0
__int64 __fastcall CAkFDNReverbFX::Reset(CAkFDNReverbFX *this)
{
  float *m_pfPreDelayStart; // rcx
  CAkFDNReverbFXParams *m_pParams; // rax
  __int64 v4; // rdi
  int v5; // esi
  float *v6; // rcx

  m_pfPreDelayStart = this->m_pfPreDelayStart;
  if ( m_pfPreDelayStart )
    memset(m_pfPreDelayStart, 0, 4 * this->m_uPreDelayLength);
  m_pParams = this->m_pParams;
  this->m_fFIRLPFMem = 0.0;
  v4 = 0i64;
  if ( (m_pParams->NonRTPC.uNumberOfDelays & 0xFFFFFFFC) != 0 )
  {
    v5 = 3;
    do
    {
      this->m_vIIRLPFMem[v4] = 0i64;
      v6 = this->m_pfDelayStart[v4];
      if ( v6 )
        memset(v6, 0, 16 * this->m_uNominalDelayLength[v5]);
      v4 = (unsigned int)(v4 + 1);
      v5 += 4;
    }
    while ( (unsigned int)v4 < this->m_pParams->NonRTPC.uNumberOfDelays >> 2 );
  }
  *(_QWORD *)&this->m_fDCFwdMem = 0i64;
  return 1i64;
}

// File Line: 207
// RVA: 0xAC1A80
__int64 __fastcall CAkFDNReverbFX::GetPluginInfo(CAkFDNReverbFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = AkPluginTypeEffect;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 219
// RVA: 0xAC1AA0
void __fastcall CAkFDNReverbFX::Execute(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  unsigned int uChannelMask; // ecx
  int i; // edx
  CAkFDNReverbFXParams *m_pParams; // rcx
  double v7; // xmm4_8
  float v8; // xmm0_4
  float v9; // xmm0_4
  CAkFDNReverbFXParams *v10; // rcx

  if ( this->m_pParams->NonRTPC.bDirty )
  {
    if ( CAkFDNReverbFX::InitDelayLines(this, io_pBuffer->uChannelMask) != AK_Success )
      return;
    this->vfptr->Reset(this);
  }
  if ( this->m_bIsSentMode )
  {
    uChannelMask = io_pBuffer->uChannelMask;
    if ( (uChannelMask & 8) != 0 && !this->m_pParams->NonRTPC.uProcessLFE )
    {
      for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
        ++i;
      memset(
        (char *)io_pBuffer->pData + 4 * io_pBuffer->uMaxFrames * (unsigned __int64)(unsigned int)(i - 1),
        0,
        4 * (unsigned int)io_pBuffer->uValidFrames);
    }
  }
  if ( this->m_uNumProcessedChannels )
  {
    m_pParams = this->m_pParams;
    if ( this->m_fCachedReverbTime != m_pParams->RTPC.fReverbTime || this->m_fCachedHFRatio != m_pParams->RTPC.fHFRatio )
    {
      CAkFDNReverbFX::ComputeIIRLPFCoefs(this);
      m_pParams = this->m_pParams;
      v7 = (1.0 - 1.0 / m_pParams->RTPC.fHFRatio) / (1.0 / m_pParams->RTPC.fHFRatio + 1.0);
      v8 = 1.0 / (1.0 - v7);
      this->m_fFIRLPFB0 = v8;
      v9 = -1.0 / (1.0 - v7) * v7;
      this->m_fFIRLPFB1 = v9;
      this->m_fCachedReverbTime = m_pParams->RTPC.fReverbTime;
      this->m_fCachedHFRatio = m_pParams->RTPC.fHFRatio;
      this->m_uTailLength = (int)(float)((float)(int)this->m_uSampleRate * m_pParams->RTPC.fReverbTime);
    }
    if ( this->m_bIsSentMode )
    {
      this->m_fCurrentDry = 0.0;
      m_pParams->RTPC.fDryLevel = 0.0;
    }
    AkFXTailHandler::HandleTail(&this->m_FXTailHandler, io_pBuffer, this->m_uTailLength);
    if ( io_pBuffer->uValidFrames )
    {
      this->m_fpPerformDSP(this, io_pBuffer);
      v10 = this->m_pParams;
      this->m_fCurrentDry = v10->RTPC.fDryLevel;
      this->m_fCurrentWet = v10->RTPC.fWetLevel;
    }
  }
}

// File Line: 274
// RVA: 0xAC1C40
__int64 __fastcall CAkFDNReverbFX::InitDelayLines(CAkFDNReverbFX *this, unsigned int in_uChannelMask)
{
  CAkFDNReverbFXParams *m_pParams; // rax
  __int64 v5; // r15
  unsigned int v6; // r8d
  __int64 v7; // rdx
  CAkFDNReverbFXParams *v8; // r8
  unsigned int v9; // ecx
  unsigned int i; // edx
  unsigned int uNumberOfDelays; // eax
  int v12; // edi
  int v13; // edi
  int v14; // edi
  void (__fastcall *v15)(CAkFDNReverbFX *, AkAudioBuffer *); // rax
  unsigned int v16; // edx
  float *v17; // rax
  unsigned int j; // r11d
  int v20; // eax
  __m128d v21; // xmm0
  int v22; // r8d
  int v23; // ecx
  unsigned int v24; // r9d
  unsigned int v25; // esi
  unsigned int v26; // edi
  __int64 v27; // rbp
  float *v28; // rax
  __int64 v29; // rdx
  unsigned int v30; // edi
  float *v31; // rax

  CAkFDNReverbFX::TermDelayLines(this);
  m_pParams = this->m_pParams;
  v5 = 0i64;
  if ( !m_pParams->NonRTPC.uDelayLengthsMode )
  {
    v6 = 0;
    if ( m_pParams->NonRTPC.uNumberOfDelays )
    {
      do
      {
        v7 = v6++;
        this->m_pParams->NonRTPC.fDelayTime[v7] = g_fDefaultDelayLengths[v7];
      }
      while ( v6 < this->m_pParams->NonRTPC.uNumberOfDelays );
    }
  }
  v8 = this->m_pParams;
  if ( !v8->NonRTPC.uProcessLFE )
    in_uChannelMask &= ~8u;
  v9 = in_uChannelMask;
  for ( i = 0; v9; v9 &= v9 - 1 )
    ++i;
  this->m_uNumProcessedChannels = i;
  uNumberOfDelays = v8->NonRTPC.uNumberOfDelays;
  v12 = in_uChannelMask - 3;
  if ( v12 )
  {
    v13 = v12 - 1;
    if ( v13 )
    {
      v14 = v13 - 51;
      if ( v14 )
      {
        if ( v14 == 8 )
        {
          switch ( uNumberOfDelays )
          {
            case 4u:
              v15 = CAkFDNReverbFX::ProcessFivePointOne4;
              break;
            case 8u:
              v15 = CAkFDNReverbFX::ProcessFivePointOne8;
              break;
            case 0xCu:
              v15 = CAkFDNReverbFX::ProcessFivePointOne12;
              break;
            case 0x10u:
              v15 = CAkFDNReverbFX::ProcessFivePointOne16;
              break;
            default:
              goto LABEL_53;
          }
        }
        else
        {
          switch ( uNumberOfDelays )
          {
            case 4u:
              v15 = CAkFDNReverbFX::ProcessN4;
              break;
            case 8u:
              v15 = CAkFDNReverbFX::ProcessN8;
              break;
            case 0xCu:
              v15 = CAkFDNReverbFX::ProcessN12;
              break;
            case 0x10u:
              v15 = CAkFDNReverbFX::ProcessN16;
              break;
            default:
              goto LABEL_53;
          }
        }
      }
      else
      {
        switch ( uNumberOfDelays )
        {
          case 4u:
            v15 = CAkFDNReverbFX::ProcessFivePointZero4;
            break;
          case 8u:
            v15 = CAkFDNReverbFX::ProcessFivePointZero8;
            break;
          case 0xCu:
            v15 = CAkFDNReverbFX::ProcessFivePointZero12;
            break;
          case 0x10u:
            v15 = CAkFDNReverbFX::ProcessFivePointZero16;
            break;
          default:
            goto LABEL_53;
        }
      }
    }
    else
    {
      switch ( uNumberOfDelays )
      {
        case 4u:
          v15 = CAkFDNReverbFX::ProcessMono4;
          break;
        case 8u:
          v15 = CAkFDNReverbFX::ProcessMono8;
          break;
        case 0xCu:
          v15 = CAkFDNReverbFX::ProcessMono12;
          break;
        case 0x10u:
          v15 = CAkFDNReverbFX::ProcessMono16;
          break;
        default:
          goto LABEL_53;
      }
    }
  }
  else
  {
    switch ( uNumberOfDelays )
    {
      case 4u:
        v15 = CAkFDNReverbFX::ProcessStereo4;
        break;
      case 8u:
        v15 = CAkFDNReverbFX::ProcessStereo8;
        break;
      case 0xCu:
        v15 = CAkFDNReverbFX::ProcessStereo12;
        break;
      case 0x10u:
        v15 = CAkFDNReverbFX::ProcessStereo16;
        break;
      default:
        goto LABEL_53;
    }
  }
  this->m_fpPerformDSP = v15;
LABEL_53:
  v16 = (int)(float)((float)(int)this->m_uSampleRate * v8->NonRTPC.fPreDelay);
  this->m_uPreDelayLength = v16;
  if ( v16 )
  {
    v17 = (float *)this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, 4i64 * v16);
    this->m_pfPreDelayStart = v17;
    if ( !v17 )
      return 52i64;
    this->m_pfPreDelayRW = v17;
    this->m_pfPreDelayEnd = &v17[this->m_uPreDelayLength];
  }
  for ( j = 0; j < this->m_pParams->NonRTPC.uNumberOfDelays; ++j )
  {
    v20 = (int)(float)((float)(this->m_pParams->NonRTPC.fDelayTime[j] * 0.001) * (float)(int)this->m_uSampleRate);
    this->m_uNominalDelayLength[j] = v20;
    if ( (v20 & 1) == 0 )
      this->m_uNominalDelayLength[j] = v20 + 1;
    v21 = 0i64;
    v21.m128d_f64[0] = (double)(int)this->m_uNominalDelayLength[j];
    v22 = (int)_mm_sqrt_pd(v21).m128d_f64[0] + 1;
    while ( 1 )
    {
      v23 = 3;
      if ( v22 <= 3 )
        break;
      v24 = this->m_uNominalDelayLength[j];
      while ( v24 % v23 )
      {
        v23 += 2;
        if ( v23 >= v22 )
          goto LABEL_65;
      }
      this->m_uNominalDelayLength[j] = v24 + 2;
    }
LABEL_65:
    ;
  }
  qsort(this->m_uNominalDelayLength, this->m_pParams->NonRTPC.uNumberOfDelays, 4ui64, AkFDNQSortCompare);
  if ( (this->m_pParams->NonRTPC.uNumberOfDelays & 0xFFFFFFFC) != 0 )
  {
    v25 = 2;
    while ( 1 )
    {
      v26 = *((_DWORD *)&this->vfptr + v25 + 21);
      v27 = v25 + 1;
      v28 = (float *)this->m_pAllocator->vfptr->Malloc(this->m_pAllocator, 16i64 * v26);
      this->m_pfDelayStart[v5] = v28;
      if ( !v28 )
        return 52i64;
      this->m_pfDelayWrite[v5] = v28;
      this->m_pfDelayEnd[v5] = &v28[4 * v26];
      *(_QWORD *)&this->m_uNominalDelayLength[2 * v25 + 12] = &v28[4 * (v26 - *((_DWORD *)&this->m_fFIRLPFB1 + v25))];
      *(_QWORD *)&this->m_uNominalDelayLength[2 * v25 + 14] = &this->m_pfDelayStart[v5][4
                                                                                      * (v26
                                                                                       - this->m_uNominalDelayLength[v25 - 1])
                                                                                      + 1];
      v29 = v25;
      v30 = v26 - this->m_uNominalDelayLength[v25];
      v25 += 4;
      this->m_pfDelayRead[v29] = &this->m_pfDelayStart[v5][4 * v30 + 2];
      v31 = this->m_pfDelayStart[v5];
      v5 = (unsigned int)(v5 + 1);
      this->m_pfDelayRead[v27] = v31 + 3;
      if ( (unsigned int)v5 >= this->m_pParams->NonRTPC.uNumberOfDelays >> 2 )
        goto LABEL_70;
    }
  }
  else
  {
LABEL_70:
    this->vfptr->Reset(this);
    this->m_pParams->NonRTPC.bDirty = 0;
    return 1i64;
  }
}

// File Line: 465
// RVA: 0xAC2080
void __fastcall CAkFDNReverbFX::TermDelayLines(CAkFDNReverbFX *this)
{
  float **m_pfDelayStart; // rbx
  __int64 v3; // rdi

  m_pfDelayStart = this->m_pfDelayStart;
  v3 = 4i64;
  do
  {
    if ( *m_pfDelayStart )
    {
      ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Free)(this->m_pAllocator);
      *m_pfDelayStart = 0i64;
    }
    ++m_pfDelayStart;
    --v3;
  }
  while ( v3 );
  if ( this->m_pfPreDelayStart )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))this->m_pAllocator->vfptr->Free)(this->m_pAllocator);
    this->m_pfPreDelayStart = 0i64;
  }
}

// File Line: 1069
// RVA: 0xAC2100
void __fastcall CAkFDNReverbFX::ProcessMono4(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm14
  float *m_pfPreDelayStart; // rbp
  float *m_pfPreDelayEnd; // r14
  float *v5; // rbx
  float *v6; // rdi
  CAkFDNReverbFXParams *m_pParams; // rdx
  __m128 v10; // xmm7
  float v11; // xmm8_4
  float v12; // xmm6_4
  float *pData; // r15
  float *v14; // rsi
  __m128 v15; // xmm5
  __m128 v16; // xmm9
  float v17; // xmm10_4
  float v18; // xmm11_4
  float v19; // xmm4_4
  unsigned int uMaxFrames; // eax
  int uValidFrames; // r8d
  float *v22; // r10
  float v23; // xmm12_4
  float *v24; // r11
  __m128i v25; // xmm0
  float *v26; // rax
  float v27; // xmm13_4
  float fDryLevel; // xmm1_4
  float v29; // xmm2_4
  __m128 fWetLevel_low; // xmm0
  float *m_pfPreDelayRW; // rdx
  float v32; // xmm1_4
  __m128 v33; // xmm14
  float *v34; // rcx
  float v35; // xmm15_4
  __m128 v36; // xmm1
  __m128 v37; // xmm2
  __m128 v38; // xmm0
  __m128 v39; // xmm3
  __m128 v40; // xmm0
  float v41; // xmm3_4
  __m128 v42; // xmm2
  __m128 v43; // xmm2
  __m128 v44; // xmm0
  __m128 v45; // xmm5
  __m128 v46; // xmm5
  __m128 v47; // xmm5
  float v48; // xmm2_4
  __m128 v49; // xmm1
  float v50; // xmm0_4
  __m128 v51; // xmm1
  __m128 i; // [rsp+0h] [rbp-E8h]
  float v53; // [rsp+10h] [rbp-D8h]
  __m128 v54; // [rsp+20h] [rbp-C8h]

  m_pfPreDelayStart = this->m_pfPreDelayStart;
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  v5 = this->m_pfDelayStart[0];
  v6 = this->m_pfDelayEnd[0];
  m_pParams = this->m_pParams;
  v10 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v11) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  LODWORD(v12) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFMem), (__m128)LODWORD(this->m_fFIRLPFMem), 0).m128_u32[0];
  pData = (float *)io_pBuffer->pData;
  v14 = this->m_pfDelayRead[1];
  v15 = this->m_vIIRLPFB0[0];
  v16 = this->m_vIIRLPFMem[0];
  LODWORD(v17) = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0).m128_u32[0];
  LODWORD(v18) = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0).m128_u32[0];
  LODWORD(v19) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  uMaxFrames = io_pBuffer->uMaxFrames;
  uValidFrames = io_pBuffer->uValidFrames;
  v22 = this->m_pfDelayRead[2];
  LODWORD(v23) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  v54 = v15;
  v24 = this->m_pfDelayRead[3];
  v25 = _mm_cvtsi32_si128(uMaxFrames);
  v26 = this->m_pfDelayWrite[0];
  LODWORD(v27) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  v2.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  fDryLevel = m_pParams->RTPC.fDryLevel;
  v29 = 1.0 / _mm_cvtepi32_ps(v25).m128_f32[0];
  fWetLevel_low = (__m128)LODWORD(m_pParams->RTPC.fWetLevel);
  m_pfPreDelayRW = this->m_pfPreDelayRW;
  fWetLevel_low.m128_f32[0] = fWetLevel_low.m128_f32[0] - this->m_fCurrentWet;
  v32 = (float)(fDryLevel - this->m_fCurrentDry) * v29;
  v33 = _mm_shuffle_ps(v2, v2, 0);
  v34 = this->m_pfDelayRead[0];
  v35 = v32;
  fWetLevel_low.m128_f32[0] = fWetLevel_low.m128_f32[0] * v29;
  LODWORD(v53) = _mm_shuffle_ps(fWetLevel_low, fWetLevel_low, 0).m128_u32[0];
  for ( i = this->m_vIIRLPFA1[0]; uValidFrames; --uValidFrames )
  {
    v36 = (__m128)*(unsigned int *)v34;
    v37 = (__m128)*(unsigned int *)v14;
    v38 = (__m128)*(unsigned int *)v22;
    v34 += 4;
    if ( v34 >= v6 )
      v34 = v5;
    v14 += 4;
    v39 = (__m128)*(unsigned int *)v24;
    if ( v14 >= v6 )
      v14 = v5 + 1;
    v22 += 4;
    if ( v22 >= v6 )
      v22 = v5 + 2;
    v24 += 4;
    if ( v24 >= v6 )
      v24 = v5 + 3;
    v18 = v18 + v53;
    v40 = _mm_unpacklo_ps(v38, v39);
    v41 = *pData;
    v17 = v17 + v35;
    ++pData;
    v16 = _mm_add_ps(_mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v36, v37), v40), v15), _mm_mul_ps(v16, i));
    v42 = _mm_mul_ps(v16, vOutDecorrelationVectorA);
    v43 = _mm_add_ps(v42, _mm_movehl_ps(v42, v42));
    v44 = _mm_add_ps(_mm_movehl_ps(v16, v16), v16);
    v45 = _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), v44);
    *(pData - 1) = (float)(v41 * v17)
                 + (float)((float)(_mm_shuffle_ps(v43, v43, 85).m128_f32[0] + v43.m128_f32[0]) * v18);
    v46 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v45, v45, 0), v33), v16);
    v47 = _mm_shuffle_ps(v46, _mm_shuffle_ps(v46, v46, 15), 201);
    v19 = (float)((float)(v27 * v19) + v41) - v23;
    v23 = v41;
    if ( m_pfPreDelayStart )
    {
      v48 = *m_pfPreDelayRW;
      *m_pfPreDelayRW++ = v19;
      if ( m_pfPreDelayRW == m_pfPreDelayEnd )
        m_pfPreDelayRW = m_pfPreDelayStart;
    }
    else
    {
      v48 = v19;
    }
    v26 += 4;
    v49 = v10;
    v50 = v11 * v12;
    v12 = v48;
    v49.m128_f32[0] = (float)(v10.m128_f32[0] * v48) + v50;
    v51 = _mm_add_ps(_mm_shuffle_ps(v49, v49, 0), v47);
    v15 = v54;
    *((__m128 *)v26 - 1) = v51;
    if ( v26 >= v6 )
      v26 = v5;
  }
  this->m_fFIRLPFMem = v12;
  this->m_fDCFwdMem = v23;
  this->m_fDCFbkMem = v19;
  this->m_pfPreDelayRW = m_pfPreDelayRW;
  this->m_pfDelayRead[3] = v24;
  this->m_pfDelayRead[1] = v14;
  this->m_pfDelayWrite[0] = v26;
  this->m_pfDelayRead[0] = v34;
  this->m_pfDelayRead[2] = v22;
  this->m_vIIRLPFMem[0] = v16;
}

// File Line: 1095
// RVA: 0xAC2490
void __fastcall CAkFDNReverbFX::ProcessMono8(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  __m128 v3; // xmm4
  float *m_pfPreDelayRW; // r10
  float *v5; // r14
  float *v6; // r13
  float *v7; // r12
  float v8; // xmm7_4
  float *v9; // r9
  float *v10; // r15
  float *v11; // r11
  float v12; // xmm6_4
  __m128 v13; // xmm9
  float v14; // xmm10_4
  float *v15; // rbx
  float *v16; // rdi
  float *v17; // rbp
  float v18; // xmm13_4
  float v19; // xmm14_4
  float v20; // xmm15_4
  CAkFDNReverbFXParams *m_pParams; // rdx
  float *v23; // rsi
  __m128 v24; // xmm0
  __m128 fDryLevel_low; // xmm1
  float *v26; // rax
  float v27; // xmm2_4
  __m128 fWetLevel_low; // xmm0
  float *v29; // rdx
  __m128 v30; // xmm8
  __m128 v31; // xmm5
  __m128 v32; // xmm12
  float *v33; // rcx
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  __m128 v36; // xmm0
  __m128 v37; // xmm3
  __m128 v38; // xmm1
  __m128 v39; // xmm2
  __m128 v40; // xmm0
  __m128 v41; // xmm1
  __m128 v42; // xmm4
  __m128 v43; // xmm0
  __m128 v44; // xmm1
  __m128 v45; // xmm0
  float v46; // xmm4_4
  __m128 v47; // xmm3
  __m128 v48; // xmm3
  __m128 v49; // xmm0
  __m128 v50; // xmm1
  __m128 v51; // xmm2
  __m128 v52; // xmm2
  __m128 v53; // xmm3
  __m128 v54; // xmm1
  __m128 v55; // xmm8
  __m128 v56; // xmm3
  float v57; // xmm2_4
  __m128 v58; // xmm1
  float v59; // xmm0_4
  __m128 v60; // xmm0
  __m128 v61; // xmm1
  float *pData; // [rsp+0h] [rbp-188h]
  float *v63; // [rsp+8h] [rbp-180h]
  float *m_pfPreDelayEnd; // [rsp+10h] [rbp-178h]
  float *m_pfPreDelayStart; // [rsp+18h] [rbp-170h]
  __m128 v66; // [rsp+20h] [rbp-168h]
  __m128 v67; // [rsp+30h] [rbp-158h]
  __m128 v68; // [rsp+40h] [rbp-148h]
  float v69; // [rsp+50h] [rbp-138h]
  float v70; // [rsp+60h] [rbp-128h]
  __m128 v71; // [rsp+70h] [rbp-118h]
  float v72; // [rsp+80h] [rbp-108h]
  __m128 v73; // [rsp+90h] [rbp-F8h]
  CAkFDNReverbFX *v74; // [rsp+190h] [rbp+8h]
  int uValidFrames; // [rsp+1A0h] [rbp+18h]
  float *v76; // [rsp+1A8h] [rbp+20h]

  v74 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  v3 = this->m_vIIRLPFB0[0];
  m_pfPreDelayRW = this->m_pfPreDelayRW;
  v5 = this->m_pfDelayStart[0];
  v6 = this->m_pfDelayStart[1];
  v7 = this->m_pfDelayEnd[0];
  LODWORD(v69) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  LODWORD(v8) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFMem), (__m128)LODWORD(this->m_fFIRLPFMem), 0).m128_u32[0];
  v9 = this->m_pfDelayWrite[1];
  v10 = this->m_pfDelayRead[1];
  v11 = this->m_pfDelayRead[2];
  LODWORD(v12) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  v13 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v14) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  v15 = this->m_pfDelayRead[3];
  v16 = this->m_pfDelayRead[4];
  v17 = this->m_pfDelayRead[7];
  LODWORD(v18) = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0).m128_u32[0];
  LODWORD(v19) = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0).m128_u32[0];
  v71 = v3;
  LODWORD(v20) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  m_pParams = this->m_pParams;
  v76 = this->m_pfDelayRead[5];
  v23 = this->m_pfDelayRead[6];
  pData = (float *)io_pBuffer->pData;
  v2.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  v24 = v2;
  fDryLevel_low = (__m128)LODWORD(m_pParams->RTPC.fDryLevel);
  v67 = _mm_shuffle_ps(v24, v24, 0);
  m_pfPreDelayStart = this->m_pfPreDelayStart;
  v63 = this->m_pfDelayEnd[1];
  v26 = this->m_pfDelayRead[0];
  v27 = 1.0 / (float)io_pBuffer->uMaxFrames;
  fDryLevel_low.m128_f32[0] = (float)(fDryLevel_low.m128_f32[0] - this->m_fCurrentDry) * v27;
  LODWORD(v72) = _mm_shuffle_ps(fDryLevel_low, fDryLevel_low, 0).m128_u32[0];
  fWetLevel_low = (__m128)LODWORD(m_pParams->RTPC.fWetLevel);
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  v29 = this->m_pfDelayWrite[0];
  fWetLevel_low.m128_f32[0] = (float)(fWetLevel_low.m128_f32[0] - this->m_fCurrentWet) * v27;
  LODWORD(v70) = _mm_shuffle_ps(fWetLevel_low, fWetLevel_low, 0).m128_u32[0];
  v68 = this->m_vIIRLPFB0[1];
  v30 = this->m_vIIRLPFA1[0];
  uValidFrames = io_pBuffer->uValidFrames;
  v31 = this->m_vIIRLPFMem[0];
  v32 = this->m_vIIRLPFMem[1];
  v73 = v30;
  v66 = this->m_vIIRLPFA1[1];
  if ( io_pBuffer->uValidFrames )
  {
    v33 = this->m_pfDelayRead[5];
    do
    {
      v34 = (__m128)*(unsigned int *)v26;
      v35 = (__m128)*(unsigned int *)v10;
      v36 = (__m128)*(unsigned int *)v11;
      v26 += 4;
      if ( v26 >= v7 )
        v26 = v5;
      v10 += 4;
      v37 = (__m128)*(unsigned int *)v15;
      if ( v10 >= v7 )
        v10 = v5 + 1;
      v11 += 4;
      if ( v11 >= v7 )
        v11 = v5 + 2;
      v15 += 4;
      if ( v15 >= v7 )
        v15 = v5 + 3;
      v38 = _mm_unpacklo_ps(v34, v35);
      v39 = (__m128)*(unsigned int *)v16;
      v40 = _mm_unpacklo_ps(v36, v37);
      v16 += 4;
      if ( v16 >= v63 )
        v16 = v6;
      v41 = _mm_mul_ps(_mm_movelh_ps(v38, v40), v3);
      v42 = (__m128)*(unsigned int *)v17;
      v76 = v33 + 4;
      v31 = _mm_add_ps(v41, _mm_mul_ps(v31, v30));
      v43 = (__m128)*(unsigned int *)v23;
      v44 = _mm_mul_ps(v31, vOutDecorrelationVectorA);
      if ( v33 + 4 >= v63 )
        v76 = v6 + 1;
      v23 += 4;
      if ( v23 >= v63 )
        v23 = v6 + 2;
      v17 += 4;
      if ( v17 >= v63 )
        v17 = v6 + 3;
      v18 = v18 + v72;
      v19 = v19 + v70;
      ++pData;
      v45 = _mm_unpacklo_ps(v43, v42);
      v46 = *(pData - 1);
      v32 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v39, (__m128)*(unsigned int *)v33), v45), v68),
              _mm_mul_ps(v32, v66));
      v47 = _mm_add_ps(_mm_mul_ps(v32, vOutDecorrelationVectorA), v44);
      v48 = _mm_add_ps(v47, _mm_movehl_ps(v47, v47));
      v49 = _mm_add_ps(v32, v31);
      v50 = _mm_add_ps(_mm_movehl_ps(v49, v49), v49);
      v51 = _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), v50);
      v52 = _mm_mul_ps(_mm_shuffle_ps(v51, v51, 0), v67);
      v50.m128_f32[0] = (float)(_mm_shuffle_ps(v48, v48, 85).m128_f32[0] + v48.m128_f32[0]) * v19;
      v53 = _mm_add_ps(v52, v31);
      *(pData - 1) = (float)(v46 * v18) + v50.m128_f32[0];
      v54 = _mm_add_ps(v32, v52);
      v55 = _mm_shuffle_ps(v54, _mm_shuffle_ps(v54, v53, 15), 201);
      v56 = _mm_shuffle_ps(v53, _mm_shuffle_ps(v53, v54, 15), 201);
      v12 = (float)((float)(v69 * v12) + v46) - v20;
      v20 = v46;
      if ( m_pfPreDelayStart )
      {
        v57 = *m_pfPreDelayRW;
        *m_pfPreDelayRW++ = v12;
        if ( m_pfPreDelayRW == m_pfPreDelayEnd )
          m_pfPreDelayRW = m_pfPreDelayStart;
      }
      else
      {
        v57 = v12;
      }
      v3 = v71;
      v33 = v76;
      v29 += 4;
      v58 = v13;
      v59 = v14 * v8;
      v8 = v57;
      v58.m128_f32[0] = (float)(v13.m128_f32[0] * v57) + v59;
      v60 = _mm_shuffle_ps(v58, v58, 0);
      v61 = _mm_add_ps(v60, v55);
      v30 = v73;
      *((__m128 *)v29 - 1) = _mm_add_ps(v60, v56);
      if ( v29 >= v7 )
        v29 = v5;
      *(__m128 *)v9 = v61;
      v9 += 4;
      if ( v9 >= v63 )
        v9 = v6;
      --uValidFrames;
    }
    while ( uValidFrames );
    this = v74;
  }
  this->m_fFIRLPFMem = v8;
  this->m_fDCFwdMem = v20;
  this->m_fDCFbkMem = v12;
  this->m_pfPreDelayRW = m_pfPreDelayRW;
  this->m_pfDelayRead[0] = v26;
  this->m_vIIRLPFMem[1] = v32;
  this->m_vIIRLPFMem[0] = v31;
  this->m_pfDelayRead[2] = v11;
  this->m_pfDelayWrite[0] = v29;
  this->m_pfDelayRead[5] = v76;
  this->m_pfDelayWrite[1] = v9;
  this->m_pfDelayRead[1] = v10;
  this->m_pfDelayRead[3] = v15;
  this->m_pfDelayRead[4] = v16;
  this->m_pfDelayRead[6] = v23;
  this->m_pfDelayRead[7] = v17;
}29;
  this->m_pfDelayRead[5] = v76;
  this->m_pfDelayWrite[1] = v9;
  this->m_pfDelayRead[1] = v10;
  this->m_pfDelayRead[3] = v15;
  this->m_pfDelayRead[4] = v16;
  this->m_pfDelayRead[6]

// File Line: 1125
// RVA: 0xAC29E0
void __fastcall CAkFDNReverbFX::ProcessMono12(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *m_pfPreDelayRW; // r11
  float *v4; // r13
  float *v5; // r9
  float *v6; // rdi
  float v8; // xmm4_4
  float v9; // xmm7_4
  CAkFDNReverbFXParams *m_pParams; // rdx
  __m128 v11; // xmm12
  float v12; // xmm10_4
  float v13; // xmm13_4
  float v14; // xmm14_4
  float v15; // xmm15_4
  __m128 v16; // xmm0
  __m128 fDryLevel_low; // xmm1
  float v18; // xmm2_4
  __m128 fWetLevel_low; // xmm0
  float *v20; // rax
  float *v21; // rdx
  __m128 v22; // xmm8
  float *v23; // rsi
  float *v24; // rbx
  __m128 v25; // xmm5
  __m128 v26; // xmm6
  __m128 v27; // xmm9
  float *v28; // rbp
  float *v29; // r14
  float *v30; // r15
  float *v31; // r12
  float *v32; // r10
  float *v33; // r8
  __m128 v34; // xmm1
  __m128 v35; // xmm0
  __m128 v36; // xmm3
  __m128 v37; // xmm4
  __m128 v38; // xmm2
  __m128 v39; // xmm1
  __m128 v40; // xmm0
  __m128 v41; // xmm5
  __m128 v42; // xmm1
  __m128 v43; // xmm0
  bool v44; // cf
  float *v45; // rcx
  __m128 v46; // xmm3
  __m128 v47; // xmm6
  __m128 v48; // xmm8
  __m128 v49; // xmm0
  __m128 v50; // xmm1
  __m128 v51; // xmm2
  __m128 v52; // xmm4
  float *v53; // rcx
  __m128 v54; // xmm1
  __m128 v55; // xmm3
  __m128 v56; // xmm0
  __m128 v57; // xmm2
  __m128 v58; // xmm2
  __m128 v59; // xmm2
  __m128 v60; // xmm0
  __m128 v61; // xmm1
  __m128 v62; // xmm3
  __m128 v63; // xmm3
  __m128 v64; // xmm2
  __m128 v65; // xmm8
  __m128 v66; // xmm1
  __m128 v67; // xmm9
  __m128 v68; // xmm3
  __m128 v69; // xmm8
  float v70; // xmm1_4
  __m128 v71; // xmm2
  float v72; // xmm0_4
  __m128 v73; // xmm1
  __m128 v74; // xmm2
  __m128 v75; // xmm0
  __m128 v76; // xmm1
  float *v77; // [rsp+0h] [rbp-208h]
  float *v78; // [rsp+8h] [rbp-200h]
  float *v79; // [rsp+10h] [rbp-1F8h]
  float *v80; // [rsp+18h] [rbp-1F0h]
  float *v81; // [rsp+20h] [rbp-1E8h]
  float *v82; // [rsp+28h] [rbp-1E0h]
  float *v83; // [rsp+30h] [rbp-1D8h]
  float *v84; // [rsp+38h] [rbp-1D0h]
  float *pData; // [rsp+40h] [rbp-1C8h]
  __m128 v86; // [rsp+50h] [rbp-1B8h]
  float *m_pfPreDelayStart; // [rsp+60h] [rbp-1A8h]
  float *m_pfPreDelayEnd; // [rsp+68h] [rbp-1A0h]
  float v89; // [rsp+70h] [rbp-198h]
  __m128 v90; // [rsp+80h] [rbp-188h]
  float v91; // [rsp+90h] [rbp-178h]
  __m128 v92; // [rsp+A0h] [rbp-168h]
  float v93; // [rsp+B0h] [rbp-158h]
  __m128 v94; // [rsp+C0h] [rbp-148h]
  __m128 v95; // [rsp+D0h] [rbp-138h]
  __m128 v96; // [rsp+E0h] [rbp-128h]
  float v97; // [rsp+F0h] [rbp-118h]
  __m128 v98; // [rsp+100h] [rbp-108h]
  __m128 v99; // [rsp+110h] [rbp-F8h]
  CAkFDNReverbFX *v100; // [rsp+210h] [rbp+8h]
  int uValidFrames; // [rsp+220h] [rbp+18h]
  float *v102; // [rsp+228h] [rbp+20h]

  v100 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  m_pfPreDelayRW = this->m_pfPreDelayRW;
  v4 = this->m_pfDelayStart[0];
  v5 = this->m_pfDelayWrite[1];
  v6 = this->m_pfDelayRead[2];
  LODWORD(v8) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  LODWORD(v9) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  m_pParams = this->m_pParams;
  v11 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v12) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFMem), (__m128)LODWORD(this->m_fFIRLPFMem), 0).m128_u32[0];
  LODWORD(v13) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  LODWORD(v14) = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0).m128_u32[0];
  LODWORD(v15) = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0).m128_u32[0];
  v102 = this->m_pfDelayRead[1];
  LODWORD(v97) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  v89 = v8;
  pData = (float *)io_pBuffer->pData;
  v2.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  v16 = v2;
  fDryLevel_low = (__m128)LODWORD(m_pParams->RTPC.fDryLevel);
  v95 = _mm_shuffle_ps(v16, v16, 0);
  m_pfPreDelayStart = this->m_pfPreDelayStart;
  v82 = this->m_pfDelayStart[1];
  v18 = 1.0 / (float)io_pBuffer->uMaxFrames;
  v81 = this->m_pfDelayStart[2];
  v80 = this->m_pfDelayEnd[0];
  fDryLevel_low.m128_f32[0] = (float)(fDryLevel_low.m128_f32[0] - this->m_fCurrentDry) * v18;
  v83 = this->m_pfDelayEnd[1];
  LODWORD(v91) = _mm_shuffle_ps(fDryLevel_low, fDryLevel_low, 0).m128_u32[0];
  fWetLevel_low = (__m128)LODWORD(m_pParams->RTPC.fWetLevel);
  v84 = this->m_pfDelayEnd[2];
  v20 = this->m_pfDelayRead[0];
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  v21 = this->m_pfDelayWrite[0];
  fWetLevel_low.m128_f32[0] = (float)(fWetLevel_low.m128_f32[0] - this->m_fCurrentWet) * v18;
  LODWORD(v93) = _mm_shuffle_ps(fWetLevel_low, fWetLevel_low, 0).m128_u32[0];
  v22 = this->m_vIIRLPFB0[0];
  v23 = this->m_pfDelayRead[3];
  v24 = this->m_pfDelayRead[4];
  v25 = this->m_vIIRLPFMem[0];
  v26 = this->m_vIIRLPFMem[1];
  v27 = this->m_vIIRLPFMem[2];
  v28 = this->m_pfDelayRead[6];
  v29 = this->m_pfDelayRead[7];
  v30 = this->m_pfDelayRead[8];
  v92 = this->m_vIIRLPFB0[1];
  v99 = v22;
  v31 = this->m_pfDelayRead[10];
  v78 = this->m_pfDelayRead[5];
  v90 = this->m_vIIRLPFB0[2];
  v79 = this->m_pfDelayRead[9];
  uValidFrames = io_pBuffer->uValidFrames;
  v94 = this->m_vIIRLPFA1[0];
  v96 = this->m_vIIRLPFA1[1];
  v77 = this->m_pfDelayRead[11];
  v32 = this->m_pfDelayWrite[2];
  v98 = this->m_vIIRLPFA1[2];
  if ( io_pBuffer->uValidFrames )
  {
    v33 = this->m_pfDelayRead[1];
    do
    {
      v34 = (__m128)*(unsigned int *)v20;
      v35 = (__m128)*(unsigned int *)v6;
      v20 += 4;
      if ( v20 >= v80 )
        v20 = v4;
      v102 = v33 + 4;
      v36 = (__m128)*(unsigned int *)v23;
      if ( v33 + 4 >= v80 )
        v102 = v4 + 1;
      v6 += 4;
      if ( v6 >= v80 )
        v6 = v4 + 2;
      v23 += 4;
      if ( v23 >= v80 )
        v23 = v4 + 3;
      v37 = (__m128)*(unsigned int *)v29;
      v24 += 4;
      v38 = (__m128)*(unsigned int *)v78;
      v39 = _mm_movelh_ps(_mm_unpacklo_ps(v34, (__m128)*(unsigned int *)v33), _mm_unpacklo_ps(v35, v36));
      v40 = _mm_mul_ps(v25, v94);
      v41 = _mm_mul_ps(v39, v22);
      v42 = (__m128)*((unsigned int *)v24 - 4);
      if ( v24 >= v83 )
        v24 = v82;
      v25 = _mm_add_ps(v41, v40);
      v43 = (__m128)*(unsigned int *)v28;
      v44 = v78 + 4 < v83;
      v78 += 4;
      v45 = v77;
      v46 = _mm_mul_ps(v25, vOutDecorrelationVectorA);
      if ( !v44 )
      {
        v78 = v82 + 1;
        v45 = v77;
      }
      v28 += 4;
      if ( v28 >= v83 )
        v28 = v82 + 2;
      v29 += 4;
      if ( v29 >= v83 )
        v29 = v82 + 3;
      v47 = _mm_mul_ps(v26, v96);
      v48 = (__m128)*(unsigned int *)v45;
      v30 += 4;
      v49 = _mm_unpacklo_ps(v43, v37);
      v50 = _mm_unpacklo_ps(v42, v38);
      v51 = (__m128)*((unsigned int *)v30 - 4);
      if ( v30 >= v84 )
        v30 = v81;
      v52 = (__m128)*(unsigned int *)v79;
      v44 = v79 + 4 < v84;
      v79 += 4;
      v53 = v77;
      v26 = _mm_add_ps(_mm_mul_ps(_mm_movelh_ps(v50, v49), v92), v47);
      v54 = _mm_add_ps(v26, v25);
      v55 = _mm_add_ps(v46, _mm_mul_ps(v26, vOutDecorrelationVectorA));
      v56 = (__m128)*(unsigned int *)v31;
      if ( !v44 )
      {
        v79 = v81 + 1;
        v53 = v77;
      }
      v31 += 4;
      if ( v31 >= v84 )
        v31 = v81 + 2;
      v77 = v53 + 4;
      if ( v53 + 4 >= v84 )
        v77 = v81 + 3;
      v14 = v14 + v91;
      v15 = v15 + v93;
      ++pData;
      v57 = _mm_unpacklo_ps(v51, v52);
      v8 = *(pData - 1);
      v86 = _mm_add_ps(_mm_mul_ps(_mm_movelh_ps(v57, _mm_unpacklo_ps(v56, v48)), v90), _mm_mul_ps(v27, v98));
      v58 = _mm_add_ps(_mm_mul_ps(v86, vOutDecorrelationVectorA), v55);
      v59 = _mm_add_ps(v58, _mm_movehl_ps(v58, v58));
      v60 = _mm_add_ps(v86, v54);
      v61 = _mm_add_ps(_mm_movehl_ps(v60, v60), v60);
      v62 = _mm_add_ps(_mm_shuffle_ps(v61, v61, 85), v61);
      v61.m128_f32[0] = _mm_shuffle_ps(v59, v59, 85).m128_f32[0] + v59.m128_f32[0];
      v63 = _mm_mul_ps(_mm_shuffle_ps(v62, v62, 0), v95);
      v64 = _mm_add_ps(v86, v63);
      v65 = _mm_add_ps(v63, v25);
      *(pData - 1) = (float)(v8 * v14) + (float)(v61.m128_f32[0] * v15);
      v66 = _mm_add_ps(v26, v63);
      v67 = _mm_shuffle_ps(v64, _mm_shuffle_ps(v64, v65, 15), 201);
      v68 = _mm_shuffle_ps(v66, _mm_shuffle_ps(v66, v64, 15), 201);
      v69 = _mm_shuffle_ps(v65, _mm_shuffle_ps(v65, v66, 15), 201);
      v9 = (float)((float)(v97 * v9) + v8) - v89;
      v89 = v8;
      if ( m_pfPreDelayStart )
      {
        v70 = *m_pfPreDelayRW;
        *m_pfPreDelayRW++ = v9;
        if ( m_pfPreDelayRW == m_pfPreDelayEnd )
          m_pfPreDelayRW = m_pfPreDelayStart;
      }
      else
      {
        v70 = v9;
      }
      v33 = v102;
      v21 += 4;
      v71 = v11;
      v72 = v13 * v12;
      v12 = v70;
      v71.m128_f32[0] = (float)(v11.m128_f32[0] * v70) + v72;
      v73 = _mm_shuffle_ps(v71, v71, 0);
      v74 = _mm_add_ps(v73, v67);
      v27 = v86;
      v75 = _mm_add_ps(v73, v69);
      v22 = v99;
      v76 = _mm_add_ps(v73, v68);
      *((__m128 *)v21 - 1) = v75;
      if ( v21 >= v80 )
        v21 = v4;
      v5 += 4;
      *((__m128 *)v5 - 1) = v76;
      if ( v5 >= v83 )
        v5 = v82;
      v32 += 4;
      *((__m128 *)v32 - 1) = v74;
      if ( v32 >= v84 )
        v32 = v81;
      --uValidFrames;
    }
    while ( uValidFrames );
    this = v100;
  }
  this->m_fFIRLPFMem = v12;
  this->m_fDCFwdMem = v8;
  this->m_fDCFbkMem = v9;
  this->m_pfPreDelayRW = m_pfPreDelayRW;
  this->m_pfDelayRead[0] = v20;
  this->m_vIIRLPFMem[1] = v26;
  this->m_vIIRLPFMem[2] = v27;
  this->m_vIIRLPFMem[0] = v25;
  this->m_pfDelayWrite[0] = v21;
  this->m_pfDelayWrite[1] = v5;
  this->m_pfDelayRead[1] = v102;
  this->m_pfDelayWrite[2] = v32;
  this->m_pfDelayRead[5] = v78;
  this->m_pfDelayRead[2] = v6;
  this->m_pfDelayRead[9] = v79;
  this->m_pfDelayRead[3] = v23;
  this->m_pfDelayRead[4] = v24;
  this->m_pfDelayRead[6] = v28;
  this->m_pfDelayRead[7] = v29;
  this->m_pfDelayRead[11] = v77;
  this->m_pfDelayRead[8] = v30;
  this->m_pfDelayRead[10] = v31;
}

// File Line: 1159
// RVA: 0xAC3150
void __fastcall CAkFDNReverbFX::ProcessMono16(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *v3; // r10
  float *v4; // r11
  CAkFDNReverbFXParams *m_pParams; // rdx
  float v7; // xmm4_4
  __m128 v8; // xmm9
  __m128 v9; // xmm10
  float v10; // xmm11_4
  float *v11; // r9
  __m128 v12; // xmm14
  float v13; // xmm15_4
  float v14; // xmm13_4
  __m128 v15; // xmm0
  __m128 fDryLevel_low; // xmm1
  float v17; // xmm2_4
  __m128 fWetLevel_low; // xmm0
  float *m_pfPreDelayRW; // rdx
  __m128 v20; // xmm8
  __m128 v21; // xmm5
  __m128 v22; // xmm6
  __m128 v23; // xmm7
  float *v24; // rax
  float *v25; // rsi
  float *v26; // rbp
  float *v27; // r12
  float *v28; // r13
  float *v29; // r14
  __m128 v30; // xmm0
  float *v31; // rdi
  float *v32; // r15
  float *v33; // rbx
  float *v34; // r8
  __m128 v35; // xmm1
  __m128 v36; // xmm0
  __m128 v37; // xmm2
  __m128 v38; // xmm3
  __m128 v39; // xmm4
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  float *v42; // rcx
  __m128 v43; // xmm1
  __m128 v44; // xmm0
  __m128 v45; // xmm5
  __m128 v46; // xmm1
  __m128 v47; // xmm0
  __m128 v48; // xmm3
  __m128 v49; // xmm1
  __m128 v50; // xmm2
  float *v51; // r8
  __m128 v52; // xmm1
  __m128 v53; // xmm0
  __m128 v54; // xmm4
  __m128 v55; // xmm6
  __m128 v56; // xmm1
  __m128 v57; // xmm8
  __m128 v58; // xmm3
  __m128 v59; // xmm0
  bool v60; // cf
  float *v61; // rcx
  __m128 v62; // xmm1
  __m128 v63; // xmm2
  __m128 v64; // xmm1
  __m128 v65; // xmm0
  __m128 v66; // xmm7
  __m128 v67; // xmm1
  __m128 v68; // xmm8
  __m128 v69; // xmm3
  __m128 v70; // xmm0
  __m128 v71; // xmm4
  __m128 v72; // xmm1
  __m128 v73; // xmm2
  __m128 v74; // xmm2
  __m128 v75; // xmm0
  __m128 v76; // xmm1
  __m128 v77; // xmm3
  __m128 v78; // xmm3
  __m128 v79; // xmm2
  __m128 v80; // xmm8
  __m128 v81; // xmm1
  __m128 v82; // xmm9
  __m128 v83; // xmm10
  __m128 v84; // xmm1
  __m128 v85; // xmm3
  __m128 v86; // xmm8
  float v87; // xmm1_4
  __m128 v88; // xmm2
  float v89; // xmm0_4
  __m128 v90; // xmm2
  __m128 v91; // xmm0
  __m128 v92; // xmm0
  __m128 v93; // xmm2
  float *v94; // [rsp+0h] [rbp-278h]
  float *v95; // [rsp+8h] [rbp-270h]
  float *v96; // [rsp+10h] [rbp-268h]
  float *v97; // [rsp+18h] [rbp-260h]
  float *v98; // [rsp+20h] [rbp-258h]
  float *v99; // [rsp+28h] [rbp-250h]
  float *v100; // [rsp+30h] [rbp-248h]
  float *v101; // [rsp+38h] [rbp-240h]
  float *v102; // [rsp+40h] [rbp-238h]
  float *v103; // [rsp+48h] [rbp-230h]
  float *v104; // [rsp+50h] [rbp-228h]
  float *v105; // [rsp+58h] [rbp-220h]
  float *v106; // [rsp+60h] [rbp-218h]
  float *v107; // [rsp+68h] [rbp-210h]
  float *v108; // [rsp+70h] [rbp-208h]
  float *pData; // [rsp+78h] [rbp-200h]
  __m128 v110; // [rsp+80h] [rbp-1F8h]
  __m128 v111; // [rsp+90h] [rbp-1E8h]
  float *m_pfPreDelayEnd; // [rsp+A0h] [rbp-1D8h]
  float *m_pfPreDelayStart; // [rsp+A8h] [rbp-1D0h]
  float v114; // [rsp+B0h] [rbp-1C8h]
  __m128 v115; // [rsp+C0h] [rbp-1B8h]
  __m128 v116; // [rsp+D0h] [rbp-1A8h]
  float v117; // [rsp+E0h] [rbp-198h]
  __m128 v118; // [rsp+F0h] [rbp-188h]
  float v119; // [rsp+100h] [rbp-178h]
  __m128 v120; // [rsp+110h] [rbp-168h]
  __m128 v121; // [rsp+120h] [rbp-158h]
  __m128 v122; // [rsp+130h] [rbp-148h]
  float v123; // [rsp+140h] [rbp-138h]
  __m128 v124; // [rsp+150h] [rbp-128h]
  __m128 v125; // [rsp+160h] [rbp-118h]
  __m128 v126; // [rsp+170h] [rbp-108h]
  __m128 v127; // [rsp+180h] [rbp-F8h]
  CAkFDNReverbFX *v128; // [rsp+280h] [rbp+8h]
  int uValidFrames; // [rsp+290h] [rbp+18h]
  float *v130; // [rsp+298h] [rbp+20h]

  v128 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  v3 = this->m_pfDelayWrite[1];
  v4 = this->m_pfDelayWrite[2];
  m_pParams = this->m_pParams;
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  LODWORD(v7) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  v8 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  v9 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  LODWORD(v10) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  v11 = this->m_pfDelayWrite[0];
  v12 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v13) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  LODWORD(v14) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFMem), (__m128)LODWORD(this->m_fFIRLPFMem), 0).m128_u32[0];
  LODWORD(v123) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  v114 = v7;
  pData = (float *)io_pBuffer->pData;
  v2.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  v15 = v2;
  fDryLevel_low = (__m128)LODWORD(m_pParams->RTPC.fDryLevel);
  v121 = _mm_shuffle_ps(v15, v15, 0);
  m_pfPreDelayStart = this->m_pfPreDelayStart;
  v94 = this->m_pfDelayStart[0];
  v17 = 1.0 / (float)io_pBuffer->uMaxFrames;
  v97 = this->m_pfDelayStart[1];
  v100 = this->m_pfDelayStart[2];
  fDryLevel_low.m128_f32[0] = (float)(fDryLevel_low.m128_f32[0] - this->m_fCurrentDry) * v17;
  v99 = this->m_pfDelayStart[3];
  LODWORD(v117) = _mm_shuffle_ps(fDryLevel_low, fDryLevel_low, 0).m128_u32[0];
  fWetLevel_low = (__m128)LODWORD(m_pParams->RTPC.fWetLevel);
  m_pfPreDelayRW = this->m_pfPreDelayRW;
  v101 = this->m_pfDelayEnd[0];
  fWetLevel_low.m128_f32[0] = (float)(fWetLevel_low.m128_f32[0] - this->m_fCurrentWet) * v17;
  v105 = this->m_pfDelayEnd[1];
  LODWORD(v119) = _mm_shuffle_ps(fWetLevel_low, fWetLevel_low, 0).m128_u32[0];
  v107 = this->m_pfDelayEnd[2];
  v108 = this->m_pfDelayEnd[3];
  v20 = this->m_vIIRLPFB0[0];
  v21 = this->m_vIIRLPFMem[0];
  v22 = this->m_vIIRLPFMem[1];
  v23 = this->m_vIIRLPFMem[2];
  v24 = this->m_pfDelayRead[0];
  v25 = this->m_pfDelayRead[2];
  v26 = this->m_pfDelayRead[3];
  v122 = this->m_vIIRLPFB0[1];
  v127 = v20;
  v27 = this->m_pfDelayRead[6];
  v28 = this->m_pfDelayRead[7];
  v29 = this->m_pfDelayRead[8];
  v126 = this->m_vIIRLPFB0[2];
  v130 = this->m_pfDelayRead[10];
  v124 = this->m_vIIRLPFB0[3];
  v120 = this->m_vIIRLPFA1[0];
  v102 = this->m_pfDelayRead[5];
  v118 = this->m_vIIRLPFA1[1];
  v104 = this->m_pfDelayRead[9];
  v106 = this->m_pfDelayRead[1];
  v115 = this->m_vIIRLPFA1[2];
  v116 = this->m_vIIRLPFA1[3];
  v30 = this->m_vIIRLPFMem[3];
  v31 = this->m_pfDelayRead[4];
  v95 = this->m_pfDelayRead[13];
  v110 = v30;
  v96 = this->m_pfDelayRead[14];
  v103 = this->m_pfDelayRead[11];
  v32 = this->m_pfDelayRead[12];
  v98 = this->m_pfDelayRead[15];
  v33 = this->m_pfDelayWrite[3];
  uValidFrames = io_pBuffer->uValidFrames;
  if ( io_pBuffer->uValidFrames )
  {
    v34 = this->m_pfDelayStart[0];
    do
    {
      v35 = (__m128)*(unsigned int *)v24;
      v36 = (__m128)*(unsigned int *)v25;
      v24 += 4;
      if ( v24 >= v101 )
        v24 = v34;
      v37 = (__m128)*(unsigned int *)v106;
      v38 = (__m128)*(unsigned int *)v26;
      v106 += 4;
      if ( v106 >= v101 )
        v106 = v34 + 1;
      v25 += 4;
      if ( v25 >= v101 )
        v25 = v34 + 2;
      v26 += 4;
      if ( v26 >= v101 )
        v26 = v34 + 3;
      v39 = (__m128)*(unsigned int *)v28;
      v31 += 4;
      v40 = _mm_unpacklo_ps(v35, v37);
      v41 = (__m128)*(unsigned int *)v102;
      v42 = v130;
      v43 = _mm_movelh_ps(v40, _mm_unpacklo_ps(v36, v38));
      v44 = _mm_mul_ps(v21, v120);
      v45 = _mm_mul_ps(v43, v20);
      v46 = (__m128)*((unsigned int *)v31 - 4);
      if ( v31 >= v105 )
        v31 = v97;
      v21 = _mm_add_ps(v45, v44);
      v47 = (__m128)*(unsigned int *)v27;
      v102 += 4;
      v48 = _mm_mul_ps(v21, vOutDecorrelationVectorA);
      if ( v102 >= v105 )
      {
        v102 = v97 + 1;
        v42 = v130;
      }
      v27 += 4;
      if ( v27 >= v105 )
        v27 = v97 + 2;
      v28 += 4;
      if ( v28 >= v105 )
        v28 = v97 + 3;
      v29 += 4;
      v49 = _mm_unpacklo_ps(v46, v41);
      v50 = (__m128)*(unsigned int *)v104;
      v51 = v103;
      v52 = _mm_mul_ps(_mm_movelh_ps(v49, _mm_unpacklo_ps(v47, v39)), v122);
      v53 = _mm_mul_ps(v22, v118);
      v54 = (__m128)*(unsigned int *)v103;
      v55 = v52;
      v56 = (__m128)*((unsigned int *)v29 - 4);
      if ( v29 >= v107 )
        v29 = v100;
      v22 = _mm_add_ps(v55, v53);
      v57 = _mm_add_ps(v22, v21);
      v58 = _mm_add_ps(v48, _mm_mul_ps(v22, vOutDecorrelationVectorA));
      v59 = (__m128)*(unsigned int *)v42;
      v60 = v104 + 4 < v107;
      v104 += 4;
      v61 = v130;
      if ( !v60 )
      {
        v104 = v100 + 1;
        v61 = v130;
      }
      v130 = v61 + 4;
      if ( v61 + 4 >= v107 )
        v130 = v100 + 2;
      v103 += 4;
      if ( v51 + 4 >= v107 )
        v103 = v100 + 3;
      v32 += 4;
      v62 = _mm_unpacklo_ps(v56, v50);
      v63 = (__m128)*(unsigned int *)v95;
      v64 = _mm_mul_ps(_mm_movelh_ps(v62, _mm_unpacklo_ps(v59, v54)), v126);
      v65 = _mm_mul_ps(v23, v115);
      v66 = v64;
      v67 = (__m128)*((unsigned int *)v32 - 4);
      if ( v32 >= v108 )
        v32 = v99;
      v23 = _mm_add_ps(v66, v65);
      v95 += 4;
      v68 = _mm_add_ps(v57, v23);
      v69 = _mm_add_ps(v58, _mm_mul_ps(v23, vOutDecorrelationVectorA));
      v70 = (__m128)*(unsigned int *)v96;
      v71 = (__m128)*(unsigned int *)v98;
      if ( v95 >= v108 )
        v95 = v99 + 1;
      v60 = v96 + 4 < v108;
      v96 += 4;
      v34 = v94;
      if ( !v60 )
        v96 = v99 + 2;
      v98 += 4;
      if ( v98 >= v108 )
        v98 = v99 + 3;
      v8.m128_f32[0] = v8.m128_f32[0] + v117;
      v9.m128_f32[0] = v9.m128_f32[0] + v119;
      ++pData;
      v72 = _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v67, v63), _mm_unpacklo_ps(v70, v71)), v124);
      v111 = v8;
      v125 = v9;
      v7 = *(pData - 1);
      v110 = _mm_add_ps(v72, _mm_mul_ps(v110, v116));
      v73 = _mm_add_ps(_mm_mul_ps(v110, vOutDecorrelationVectorA), v69);
      v74 = _mm_add_ps(v73, _mm_movehl_ps(v73, v73));
      v75 = _mm_add_ps(v110, v68);
      v76 = _mm_add_ps(_mm_movehl_ps(v75, v75), v75);
      v77 = _mm_add_ps(_mm_shuffle_ps(v76, v76, 85), v76);
      v76.m128_f32[0] = _mm_shuffle_ps(v74, v74, 85).m128_f32[0] + v74.m128_f32[0];
      v78 = _mm_mul_ps(_mm_shuffle_ps(v77, v77, 0), v121);
      v79 = _mm_add_ps(v23, v78);
      v80 = _mm_add_ps(v78, v21);
      *(pData - 1) = (float)(v7 * v8.m128_f32[0]) + (float)(v76.m128_f32[0] * v9.m128_f32[0]);
      v81 = _mm_add_ps(v110, v78);
      v82 = _mm_shuffle_ps(v81, _mm_shuffle_ps(v81, v80, 15), 201);
      v83 = _mm_shuffle_ps(v79, _mm_shuffle_ps(v79, v81, 15), 201);
      v84 = _mm_add_ps(v22, v78);
      v85 = _mm_shuffle_ps(v84, _mm_shuffle_ps(v84, v79, 15), 201);
      v86 = _mm_shuffle_ps(v80, _mm_shuffle_ps(v80, v84, 15), 201);
      v10 = (float)((float)(v123 * v10) + v7) - v114;
      v114 = v7;
      if ( m_pfPreDelayStart )
      {
        v87 = *m_pfPreDelayRW;
        *m_pfPreDelayRW++ = v10;
        if ( m_pfPreDelayRW == m_pfPreDelayEnd )
          m_pfPreDelayRW = m_pfPreDelayStart;
      }
      else
      {
        v87 = v10;
      }
      v11 += 4;
      v88 = v12;
      v89 = v13 * v14;
      v14 = v87;
      v88.m128_f32[0] = (float)(v12.m128_f32[0] * v87) + v89;
      v90 = _mm_shuffle_ps(v88, v88, 0);
      v91 = _mm_add_ps(v90, v86);
      v20 = v127;
      *((__m128 *)v11 - 1) = v91;
      *(__m128 *)v3 = _mm_add_ps(v90, v85);
      if ( v11 >= v101 )
        v11 = v94;
      v3 += 4;
      v92 = _mm_add_ps(v90, v83);
      if ( v3 >= v105 )
        v3 = v97;
      v4 += 4;
      v93 = _mm_add_ps(v90, v82);
      v8 = v111;
      v9 = v125;
      *((__m128 *)v4 - 1) = v92;
      if ( v4 >= v107 )
        v4 = v100;
      v33 += 4;
      *((__m128 *)v33 - 1) = v93;
      if ( v33 >= v108 )
        v33 = v99;
      --uValidFrames;
    }
    while ( uValidFrames );
    v30 = v110;
    this = v128;
  }
  this->m_fFIRLPFMem = v14;
  this->m_fDCFwdMem = v7;
  this->m_fDCFbkMem = v10;
  this->m_pfPreDelayRW = m_pfPreDelayRW;
  this->m_pfDelayRead[0] = v24;
  this->m_vIIRLPFMem[1] = v22;
  this->m_vIIRLPFMem[2] = v23;
  this->m_vIIRLPFMem[0] = v21;
  this->m_pfDelayRead[1] = v106;
  this->m_pfDelayWrite[2] = v4;
  this->m_vIIRLPFMem[3] = v30;
  this->m_pfDelayRead[5] = v102;
  this->m_pfDelayRead[9] = v104;
  this->m_pfDelayWrite[0] = v11;
  this->m_pfDelayRead[10] = v130;
  this->m_pfDelayWrite[1] = v3;
  this->m_pfDelayRead[11] = v103;
  this->m_pfDelayWrite[3] = v33;
  this->m_pfDelayRead[13] = v95;
  this->m_pfDelayRead[2] = v25;
  this->m_pfDelayRead[14] = v96;
  this->m_pfDelayRead[3] = v26;
  this->m_pfDelayRead[4] = v31;
  this->m_pfDelayRead[6] = v27;
  this->m_pfDelayRead[7] = v28;
  this->m_pfDelayRead[15] = v98;
  this->m_pfDelayRead[8] = v29;
  this->m_pfDelayRead[12] = v32;
}

// File Line: 1197
// RVA: 0xAC3AF0
void __fastcall CAkFDNReverbFX::ProcessStereo4(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *m_pfPreDelayStart; // r14
  float *m_pfPreDelayRW; // r9
  float *m_pfPreDelayEnd; // r15
  float *v6; // rbx
  float *v7; // rsi
  CAkFDNReverbFXParams *m_pParams; // rdx
  float v10; // xmm7_4
  float v11; // xmm6_4
  __m128 v12; // xmm9
  float v13; // xmm10_4
  int uValidFrames; // ebp
  float *pData; // r13
  float v16; // xmm12_4
  float v17; // xmm13_4
  float v18; // xmm14_4
  float v20; // xmm15_4
  float *v21; // rdi
  float *v22; // r10
  float *v23; // r11
  __m128 v24; // xmm4
  __m128 v25; // xmm5
  __m128 v26; // xmm11
  __m128 v27; // xmm0
  __m128 fDryLevel_low; // xmm1
  float v29; // xmm2_4
  __m128 fWetLevel_low; // xmm0
  float *v31; // rdx
  float *v32; // rcx
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm0
  __m128 v36; // xmm3
  __int64 uMaxFrames; // rax
  __m128 v38; // xmm11
  float v39; // xmm5_4
  __m128 v40; // xmm1
  float v41; // xmm4_4
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm2
  __m128 v45; // xmm3
  __m128 v46; // xmm0
  __m128 v47; // xmm8
  float v48; // xmm5_4
  __m128 v49; // xmm8
  __m128 v50; // xmm8
  float v51; // xmm2_4
  __m128 v52; // xmm1
  float v53; // xmm0_4
  float v54; // [rsp+0h] [rbp-118h]
  float v55; // [rsp+10h] [rbp-108h]
  __m128 v56; // [rsp+20h] [rbp-F8h]
  __m128 v57; // [rsp+30h] [rbp-E8h]
  __m128 v58; // [rsp+40h] [rbp-D8h]

  v2 = (__m128)LODWORD(FLOAT_N2_0);
  m_pfPreDelayStart = this->m_pfPreDelayStart;
  m_pfPreDelayRW = this->m_pfPreDelayRW;
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  v6 = this->m_pfDelayStart[0];
  v7 = this->m_pfDelayEnd[0];
  m_pParams = this->m_pParams;
  LODWORD(v10) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFMem), (__m128)LODWORD(this->m_fFIRLPFMem), 0).m128_u32[0];
  LODWORD(v11) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  v12 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v13) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  uValidFrames = io_pBuffer->uValidFrames;
  pData = (float *)io_pBuffer->pData;
  LODWORD(v16) = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0).m128_u32[0];
  LODWORD(v17) = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0).m128_u32[0];
  LODWORD(v18) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  LODWORD(v20) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  v21 = this->m_pfDelayRead[1];
  v22 = this->m_pfDelayRead[2];
  v23 = this->m_pfDelayRead[3];
  v24 = this->m_vIIRLPFB0[0];
  v25 = this->m_vIIRLPFA1[0];
  v26 = this->m_vIIRLPFMem[0];
  v2.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  v57 = v24;
  v58 = v25;
  v27 = v2;
  fDryLevel_low = (__m128)LODWORD(m_pParams->RTPC.fDryLevel);
  v56 = _mm_shuffle_ps(v27, v27, 0);
  v29 = 1.0 / (float)io_pBuffer->uMaxFrames;
  fDryLevel_low.m128_f32[0] = (float)(fDryLevel_low.m128_f32[0] - this->m_fCurrentDry) * v29;
  LODWORD(v54) = _mm_shuffle_ps(fDryLevel_low, fDryLevel_low, 0).m128_u32[0];
  fWetLevel_low = (__m128)LODWORD(m_pParams->RTPC.fWetLevel);
  v31 = this->m_pfDelayRead[0];
  fWetLevel_low.m128_f32[0] = fWetLevel_low.m128_f32[0] - this->m_fCurrentWet;
  v32 = this->m_pfDelayWrite[0];
  fWetLevel_low.m128_f32[0] = fWetLevel_low.m128_f32[0] * v29;
  LODWORD(v55) = _mm_shuffle_ps(fWetLevel_low, fWetLevel_low, 0).m128_u32[0];
  if ( io_pBuffer->uValidFrames )
  {
    do
    {
      v33 = (__m128)*(unsigned int *)v31;
      v34 = (__m128)*(unsigned int *)v21;
      v35 = (__m128)*(unsigned int *)v22;
      v31 += 4;
      if ( v31 >= v7 )
        v31 = v6;
      v21 += 4;
      v36 = (__m128)*(unsigned int *)v23;
      if ( v21 >= v7 )
        v21 = v6 + 1;
      v22 += 4;
      if ( v22 >= v7 )
        v22 = v6 + 2;
      v23 += 4;
      if ( v23 >= v7 )
        v23 = v6 + 3;
      v16 = v16 + v54;
      v17 = v17 + v55;
      uMaxFrames = io_pBuffer->uMaxFrames;
      v38 = _mm_mul_ps(v26, v25);
      v39 = *pData;
      v40 = _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v33, v34), _mm_unpacklo_ps(v35, v36)), v24);
      v41 = pData[uMaxFrames];
      ++pData;
      v26 = _mm_add_ps(v40, v38);
      v42 = _mm_mul_ps(v26, vOutDecorrelationVectorA);
      v43 = _mm_mul_ps(v26, vOutDecorrelationVectorB);
      v44 = _mm_add_ps(v42, _mm_movehl_ps(v42, v42));
      v45 = _mm_add_ps(v43, _mm_movehl_ps(v43, v43));
      v46 = _mm_add_ps(_mm_movehl_ps(v26, v26), v26);
      v47 = _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), v46);
      v46.m128_f32[0] = v39;
      v48 = v39 + v41;
      *(pData - 1) = (float)(v46.m128_f32[0] * v16)
                   + (float)((float)(_mm_shuffle_ps(v44, v44, 85).m128_f32[0] + v44.m128_f32[0]) * v17);
      v49 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v47, v47, 0), v56), v26);
      pData[uMaxFrames - 1] = (float)(v41 * v16)
                            + (float)((float)(_mm_shuffle_ps(v45, v45, 85).m128_f32[0] + v45.m128_f32[0]) * v17);
      v50 = _mm_shuffle_ps(v49, _mm_shuffle_ps(v49, v49, 15), 201);
      v11 = (float)((float)(v20 * v11) + v48) - v18;
      v18 = v48;
      if ( m_pfPreDelayStart )
      {
        v51 = *m_pfPreDelayRW;
        *m_pfPreDelayRW++ = v11;
        if ( m_pfPreDelayRW == m_pfPreDelayEnd )
          m_pfPreDelayRW = m_pfPreDelayStart;
      }
      else
      {
        v51 = v11;
      }
      v24 = v57;
      v25 = v58;
      v32 += 4;
      v52 = v12;
      v53 = v13 * v10;
      v10 = v51;
      v52.m128_f32[0] = (float)(v12.m128_f32[0] * v51) + v53;
      *((__m128 *)v32 - 1) = _mm_add_ps(_mm_shuffle_ps(v52, v52, 0), v50);
      if ( v32 >= v7 )
        v32 = v6;
      --uValidFrames;
    }
    while ( uValidFrames );
  }
  this->m_fFIRLPFMem = v10;
  this->m_fDCFwdMem = v18;
  this->m_fDCFbkMem = v11;
  this->m_pfPreDelayRW = m_pfPreDelayRW;
  this->m_pfDelayRead[3] = v23;
  this->m_vIIRLPFMem[0] = v26;
  this->m_pfDelayWrite[0] = v32;
  this->m_pfDelayRead[0] = v31;
  this->m_pfDelayRead[1] = v21;
  this->m_pfDelayRead[2] = v22;
}

// File Line: 1225
// RVA: 0xAC3F00
void __fastcall CAkFDNReverbFX::ProcessStereo8(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  __m128 v3; // xmm4
  float *m_pfPreDelayRW; // r10
  float *v5; // r14
  float *v6; // r13
  float *v7; // r12
  float v8; // xmm5_4
  float *v9; // r9
  float *v10; // r15
  float *v11; // rbx
  float v12; // xmm8_4
  __m128 v13; // xmm10
  float v14; // xmm9_4
  float *v15; // rdi
  float *v16; // r11
  float *v17; // rbp
  float v18; // xmm11_4
  float v19; // xmm14_4
  float v20; // xmm15_4
  CAkFDNReverbFXParams *m_pParams; // rdx
  float *v23; // rsi
  int uMaxFrames; // eax
  float *v25; // r8
  __m128 v26; // xmm0
  __m128 fDryLevel_low; // xmm1
  float v28; // xmm2_4
  __m128 fWetLevel_low; // xmm0
  float *v30; // rdx
  __m128 v31; // xmm6
  __m128 v32; // xmm7
  unsigned __int64 v33; // rax
  __m128 v34; // xmm0
  float *v35; // rcx
  __m128 v36; // xmm1
  __m128 v37; // xmm2
  __m128 v38; // xmm0
  __m128 v39; // xmm3
  __m128 v40; // xmm5
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm3
  float *v48; // rcx
  float *v49; // rax
  float v50; // xmm6_4
  __int64 v51; // rax
  float v52; // xmm5_4
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __m128 v55; // xmm2
  __m128 v56; // xmm4
  __m128 v57; // xmm0
  __m128 v58; // xmm1
  __m128 v59; // xmm3
  __m128 v60; // xmm3
  __m128 v61; // xmm4
  __m128 v62; // xmm1
  __m128 v63; // xmm3
  __m128 v64; // xmm4
  float v65; // xmm2_4
  __m128 v66; // xmm1
  float v67; // xmm0_4
  __m128 v68; // xmm0
  __m128 v69; // xmm1
  __m128 v70; // xmm0
  float *v71; // [rsp+0h] [rbp-1B8h]
  float *pData; // [rsp+8h] [rbp-1B0h]
  float *v73; // [rsp+10h] [rbp-1A8h]
  __m128 v74; // [rsp+20h] [rbp-198h]
  float *m_pfPreDelayEnd; // [rsp+30h] [rbp-188h]
  float *m_pfPreDelayStart; // [rsp+38h] [rbp-180h]
  float v77; // [rsp+40h] [rbp-178h]
  __m128 v78; // [rsp+50h] [rbp-168h]
  __m128 v79; // [rsp+60h] [rbp-158h]
  __m128 v80; // [rsp+70h] [rbp-148h]
  float v81; // [rsp+80h] [rbp-138h]
  float v82; // [rsp+90h] [rbp-128h]
  __m128 v83; // [rsp+A0h] [rbp-118h]
  float v84; // [rsp+B0h] [rbp-108h]
  __m128 v85; // [rsp+C0h] [rbp-F8h]
  CAkFDNReverbFX *v86; // [rsp+1C0h] [rbp+8h]
  int uValidFrames; // [rsp+1D8h] [rbp+20h]

  v86 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  v3 = this->m_vIIRLPFB0[0];
  m_pfPreDelayRW = this->m_pfPreDelayRW;
  v5 = this->m_pfDelayStart[0];
  v6 = this->m_pfDelayStart[1];
  v7 = this->m_pfDelayEnd[0];
  LODWORD(v81) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  LODWORD(v8) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  v9 = this->m_pfDelayWrite[1];
  v10 = this->m_pfDelayRead[1];
  v11 = this->m_pfDelayRead[2];
  LODWORD(v12) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  v13 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v14) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFMem), (__m128)LODWORD(this->m_fFIRLPFMem), 0).m128_u32[0];
  v15 = this->m_pfDelayRead[3];
  v16 = this->m_pfDelayRead[4];
  v17 = this->m_pfDelayRead[7];
  LODWORD(v18) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  LODWORD(v19) = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0).m128_u32[0];
  LODWORD(v20) = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0).m128_u32[0];
  v77 = v8;
  v83 = v3;
  m_pParams = this->m_pParams;
  v71 = this->m_pfDelayRead[5];
  v23 = this->m_pfDelayRead[6];
  pData = (float *)io_pBuffer->pData;
  uMaxFrames = io_pBuffer->uMaxFrames;
  v25 = this->m_pfDelayWrite[0];
  v2.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  v26 = v2;
  fDryLevel_low = (__m128)LODWORD(m_pParams->RTPC.fDryLevel);
  v79 = _mm_shuffle_ps(v26, v26, 0);
  m_pfPreDelayStart = this->m_pfPreDelayStart;
  v73 = this->m_pfDelayEnd[1];
  v28 = 1.0 / (float)uMaxFrames;
  fDryLevel_low.m128_f32[0] = (float)(fDryLevel_low.m128_f32[0] - this->m_fCurrentDry) * v28;
  LODWORD(v84) = _mm_shuffle_ps(fDryLevel_low, fDryLevel_low, 0).m128_u32[0];
  fWetLevel_low = (__m128)LODWORD(m_pParams->RTPC.fWetLevel);
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  v30 = this->m_pfDelayRead[0];
  fWetLevel_low.m128_f32[0] = (float)(fWetLevel_low.m128_f32[0] - this->m_fCurrentWet) * v28;
  LODWORD(v82) = _mm_shuffle_ps(fWetLevel_low, fWetLevel_low, 0).m128_u32[0];
  v78 = this->m_vIIRLPFB0[1];
  v31 = this->m_vIIRLPFA1[0];
  v32 = this->m_vIIRLPFMem[0];
  v80 = this->m_vIIRLPFA1[1];
  uValidFrames = io_pBuffer->uValidFrames;
  v33 = (unsigned __int64)v73;
  v34 = this->m_vIIRLPFMem[1];
  v85 = v31;
  v74 = v34;
  if ( io_pBuffer->uValidFrames )
  {
    v35 = this->m_pfDelayRead[5];
    do
    {
      v36 = (__m128)*(unsigned int *)v30;
      v37 = (__m128)*(unsigned int *)v10;
      v38 = (__m128)*(unsigned int *)v11;
      v30 += 4;
      if ( v30 >= v7 )
        v30 = v5;
      v10 += 4;
      v39 = (__m128)*(unsigned int *)v15;
      if ( v10 >= v7 )
        v10 = v5 + 1;
      v11 += 4;
      if ( v11 >= v7 )
        v11 = v5 + 2;
      v15 += 4;
      if ( v15 >= v7 )
        v15 = v5 + 3;
      v40 = (__m128)*(unsigned int *)v17;
      v41 = _mm_unpacklo_ps(v36, v37);
      v42 = (__m128)*(unsigned int *)v16;
      v43 = _mm_mul_ps(_mm_movelh_ps(v41, _mm_unpacklo_ps(v38, v39)), v3);
      v44 = (__m128)*(unsigned int *)v35;
      v16 += 4;
      if ( (unsigned __int64)v16 >= v33 )
        v16 = v6;
      v71 = v35 + 4;
      v32 = _mm_add_ps(v43, _mm_mul_ps(v32, v31));
      v45 = (__m128)*(unsigned int *)v23;
      v46 = _mm_mul_ps(v32, vOutDecorrelationVectorA);
      v47 = _mm_mul_ps(v32, vOutDecorrelationVectorB);
      if ( (unsigned __int64)(v35 + 4) >= v33 )
        v71 = v6 + 1;
      v23 += 4;
      if ( (unsigned __int64)v23 >= v33 )
        v23 = v6 + 2;
      v17 += 4;
      if ( (unsigned __int64)v17 >= v33 )
        v17 = v6 + 3;
      v48 = pData;
      v49 = pData;
      v19 = v19 + v84;
      ++pData;
      v50 = *v49;
      v20 = v20 + v82;
      v51 = io_pBuffer->uMaxFrames;
      v74 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v42, v44), _mm_unpacklo_ps(v45, v40)), v78),
              _mm_mul_ps(v74, v80));
      v52 = v48[v51];
      v53 = _mm_add_ps(_mm_mul_ps(v74, vOutDecorrelationVectorB), v47);
      v54 = _mm_add_ps(_mm_mul_ps(v74, vOutDecorrelationVectorA), v46);
      v55 = _mm_add_ps(v54, _mm_movehl_ps(v54, v54));
      v56 = _mm_add_ps(v53, _mm_movehl_ps(v53, v53));
      v57 = _mm_add_ps(v74, v32);
      v58 = _mm_add_ps(_mm_movehl_ps(v57, v57), v57);
      v59 = _mm_add_ps(_mm_shuffle_ps(v58, v58, 85), v58);
      v60 = _mm_mul_ps(_mm_shuffle_ps(v59, v59, 0), v79);
      *v48 = (float)(v50 * v19) + (float)((float)(_mm_shuffle_ps(v55, v55, 85).m128_f32[0] + v55.m128_f32[0]) * v20);
      v58.m128_f32[0] = _mm_shuffle_ps(v56, v56, 85).m128_f32[0] + v56.m128_f32[0];
      v57.m128_f32[0] = v52 * v19;
      v8 = v50 + v52;
      v61 = _mm_add_ps(v60, v32);
      v48[v51] = v57.m128_f32[0] + (float)(v58.m128_f32[0] * v20);
      v62 = _mm_add_ps(v74, v60);
      v63 = _mm_shuffle_ps(v62, _mm_shuffle_ps(v62, v61, 15), 201);
      v64 = _mm_shuffle_ps(v61, _mm_shuffle_ps(v61, v62, 15), 201);
      v12 = (float)((float)(v81 * v12) + v8) - v77;
      v77 = v8;
      if ( m_pfPreDelayStart )
      {
        v65 = *m_pfPreDelayRW;
        *m_pfPreDelayRW++ = v12;
        if ( m_pfPreDelayRW == m_pfPreDelayEnd )
          m_pfPreDelayRW = m_pfPreDelayStart;
      }
      else
      {
        v65 = v12;
      }
      v33 = (unsigned __int64)v73;
      v31 = v85;
      v35 = v71;
      v25 += 4;
      v66 = v13;
      v67 = v18 * v14;
      v14 = v65;
      v66.m128_f32[0] = (float)(v13.m128_f32[0] * v65) + v67;
      v68 = _mm_shuffle_ps(v66, v66, 0);
      v69 = _mm_add_ps(v68, v63);
      v70 = _mm_add_ps(v68, v64);
      v3 = v83;
      *((__m128 *)v25 - 1) = v70;
      if ( v25 >= v7 )
        v25 = v5;
      *(__m128 *)v9 = v69;
      v9 += 4;
      if ( v9 >= v73 )
        v9 = v6;
      --uValidFrames;
    }
    while ( uValidFrames );
    v34 = v74;
    this = v86;
  }
  this->m_fFIRLPFMem = v14;
  this->m_fDCFwdMem = v8;
  this->m_fDCFbkMem = v12;
  this->m_pfPreDelayRW = m_pfPreDelayRW;
  this->m_pfDelayRead[4] = v16;
  this->m_vIIRLPFMem[0] = v32;
  this->m_vIIRLPFMem[1] = v34;
  this->m_pfDelayWrite[0] = v25;
  this->m_pfDelayWrite[1] = v9;
  this->m_pfDelayRead[0] = v30;
  this->m_pfDelayRead[1] = v10;
  this->m_pfDelayRead[2] = v11;
  this->m_pfDelayRead[3] = v15;
  this->m_pfDelayRead[5] = v71;
  this->m_pfDelayRead[6] = v23;
  this->m_pfDelayRead[7] = v17;
}

// File Line: 1258
// RVA: 0xAC44D0
void __fastcall CAkFDNReverbFX::ProcessStereo12(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *m_pfPreDelayRW; // r11
  float *v4; // r13
  float *v5; // r9
  float *v6; // r10
  float *v7; // r12
  float *v8; // rsi
  float v9; // xmm5_4
  __m128 v10; // xmm10
  float v11; // xmm9_4
  float *v12; // rbp
  float *v13; // rbx
  float v14; // xmm11_4
  CAkFDNReverbFXParams *m_pParams; // rdx
  __m128 v17; // xmm14
  float v18; // xmm15_4
  int uMaxFrames; // eax
  float *v20; // r8
  __m128 v21; // xmm0
  __m128 fDryLevel_low; // xmm1
  __m128 fWetLevel_low; // xmm0
  float *v24; // rdx
  __m128 v25; // xmm4
  float *v26; // r14
  float *v27; // r15
  float *v28; // rdi
  __m128 v29; // xmm6
  __m128 v30; // xmm7
  __m128 v31; // xmm8
  float *v32; // rax
  __m128 v33; // xmm0
  float *v34; // rax
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm0
  __m128 v38; // xmm3
  __m128 v39; // xmm5
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm0
  __m128 v43; // xmm7
  __m128 v44; // xmm1
  __m128 v45; // xmm0
  bool v46; // cf
  float *v47; // rcx
  __m128 v48; // xmm3
  __m128 v49; // xmm4
  __m128 v50; // xmm8
  __m128 v51; // xmm0
  __m128 v52; // xmm5
  float *v53; // rax
  __m128 v54; // xmm1
  __m128 v55; // xmm2
  __m128 v56; // xmm6
  __m128 v57; // xmm1
  __m128 v58; // xmm3
  __m128 v59; // xmm4
  __m128 v60; // xmm0
  float *v61; // rcx
  float *v62; // rax
  __m128 v63; // xmm0
  float v64; // xmm6_4
  __int64 v65; // rax
  float v66; // xmm5_4
  __m128 v67; // xmm2
  __m128 v68; // xmm2
  __m128 v69; // xmm3
  __m128 v70; // xmm3
  __m128 v71; // xmm0
  __m128 v72; // xmm1
  __m128 v73; // xmm0
  __m128 v74; // xmm4
  __m128 v75; // xmm4
  __m128 v76; // xmm2
  __m128 v77; // xmm3
  __m128 v78; // xmm1
  __m128 v79; // xmm10
  __m128 v80; // xmm4
  __m128 v81; // xmm3
  float v82; // xmm1_4
  __m128 v83; // xmm2
  float v84; // xmm0_4
  __m128 v85; // xmm0
  __m128 v86; // xmm2
  __m128 v87; // xmm1
  float *v88; // [rsp+0h] [rbp-238h]
  float *v89; // [rsp+8h] [rbp-230h]
  float *v90; // [rsp+10h] [rbp-228h]
  float *v91; // [rsp+18h] [rbp-220h]
  float *v92; // [rsp+20h] [rbp-218h]
  float *v93; // [rsp+28h] [rbp-210h]
  float *pData; // [rsp+30h] [rbp-208h]
  float *v95; // [rsp+38h] [rbp-200h]
  __m128 v96; // [rsp+40h] [rbp-1F8h]
  float *v97; // [rsp+50h] [rbp-1E8h]
  float *v98; // [rsp+58h] [rbp-1E0h]
  float *m_pfPreDelayStart; // [rsp+60h] [rbp-1D8h]
  __m128 v100; // [rsp+70h] [rbp-1C8h]
  float *m_pfPreDelayEnd; // [rsp+80h] [rbp-1B8h]
  float v102; // [rsp+90h] [rbp-1A8h]
  __m128 v103; // [rsp+A0h] [rbp-198h]
  float v104; // [rsp+B0h] [rbp-188h]
  __m128 v105; // [rsp+C0h] [rbp-178h]
  __m128 v106; // [rsp+D0h] [rbp-168h]
  float v107; // [rsp+E0h] [rbp-158h]
  float v108; // [rsp+F0h] [rbp-148h]
  __m128 v109; // [rsp+100h] [rbp-138h]
  __m128 v110; // [rsp+110h] [rbp-128h]
  __m128 v111; // [rsp+120h] [rbp-118h]
  __m128 v112; // [rsp+130h] [rbp-108h]
  __m128 v113; // [rsp+140h] [rbp-F8h]
  CAkFDNReverbFX *v114; // [rsp+240h] [rbp+8h]
  int uValidFrames; // [rsp+258h] [rbp+20h]

  v114 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  m_pfPreDelayRW = this->m_pfPreDelayRW;
  v4 = this->m_pfDelayStart[0];
  v5 = this->m_pfDelayWrite[1];
  v6 = this->m_pfDelayWrite[2];
  v7 = this->m_pfDelayRead[1];
  v8 = this->m_pfDelayRead[2];
  LODWORD(v107) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  LODWORD(v9) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  v10 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  LODWORD(v11) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  v12 = this->m_pfDelayRead[3];
  v13 = this->m_pfDelayRead[4];
  LODWORD(v14) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFMem), (__m128)LODWORD(this->m_fFIRLPFMem), 0).m128_u32[0];
  m_pParams = this->m_pParams;
  v17 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v18) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  v102 = v9;
  pData = (float *)io_pBuffer->pData;
  uMaxFrames = io_pBuffer->uMaxFrames;
  v20 = this->m_pfDelayWrite[0];
  v2.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  v21 = v2;
  fDryLevel_low = (__m128)LODWORD(m_pParams->RTPC.fDryLevel);
  v105 = _mm_shuffle_ps(v21, v21, 0);
  v100 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  m_pfPreDelayStart = this->m_pfPreDelayStart;
  v98 = this->m_pfDelayStart[1];
  v90 = this->m_pfDelayStart[2];
  v97 = this->m_pfDelayEnd[0];
  fDryLevel_low.m128_f32[0] = (float)(fDryLevel_low.m128_f32[0] - this->m_fCurrentDry)
                            * (float)(1.0 / (float)uMaxFrames);
  v92 = this->m_pfDelayEnd[1];
  LODWORD(v108) = _mm_shuffle_ps(fDryLevel_low, fDryLevel_low, 0).m128_u32[0];
  fWetLevel_low = (__m128)LODWORD(m_pParams->RTPC.fWetLevel);
  v95 = this->m_pfDelayEnd[2];
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  v24 = this->m_pfDelayRead[0];
  fWetLevel_low.m128_f32[0] = (float)(fWetLevel_low.m128_f32[0] - this->m_fCurrentWet)
                            * (float)(1.0 / (float)uMaxFrames);
  LODWORD(v104) = _mm_shuffle_ps(fWetLevel_low, fWetLevel_low, 0).m128_u32[0];
  v25 = this->m_vIIRLPFB0[0];
  v26 = this->m_pfDelayRead[6];
  v27 = this->m_pfDelayRead[7];
  v28 = this->m_pfDelayRead[8];
  v29 = this->m_vIIRLPFA1[0];
  v30 = this->m_vIIRLPFMem[0];
  v31 = this->m_vIIRLPFMem[1];
  v93 = this->m_pfDelayRead[5];
  v91 = this->m_pfDelayRead[9];
  v106 = this->m_vIIRLPFB0[1];
  v111 = v25;
  v88 = this->m_pfDelayRead[10];
  v103 = this->m_vIIRLPFB0[2];
  v113 = v29;
  v89 = this->m_pfDelayRead[11];
  v112 = this->m_vIIRLPFA1[1];
  uValidFrames = io_pBuffer->uValidFrames;
  v32 = v88;
  v110 = this->m_vIIRLPFA1[2];
  v33 = this->m_vIIRLPFMem[2];
  v96 = v33;
  if ( io_pBuffer->uValidFrames )
  {
    v34 = this->m_pfDelayEnd[0];
    do
    {
      v35 = (__m128)*(unsigned int *)v24;
      v36 = (__m128)*(unsigned int *)v7;
      v37 = (__m128)*(unsigned int *)v8;
      v24 += 4;
      if ( v24 >= v34 )
        v24 = v4;
      v7 += 4;
      v38 = (__m128)*(unsigned int *)v12;
      if ( v7 >= v34 )
        v7 = v4 + 1;
      v8 += 4;
      if ( v8 >= v34 )
        v8 = v4 + 2;
      v12 += 4;
      if ( v12 >= v34 )
        v12 = v4 + 3;
      v39 = (__m128)*(unsigned int *)v27;
      v13 += 4;
      v40 = _mm_movelh_ps(_mm_unpacklo_ps(v35, v36), _mm_unpacklo_ps(v37, v38));
      v41 = (__m128)*(unsigned int *)v93;
      v42 = _mm_mul_ps(v30, v29);
      v43 = _mm_mul_ps(v40, v25);
      v44 = (__m128)*((unsigned int *)v13 - 4);
      if ( v13 >= v92 )
        v13 = v98;
      v30 = _mm_add_ps(v43, v42);
      v45 = (__m128)*(unsigned int *)v26;
      v46 = v93 + 4 < v92;
      v93 += 4;
      v47 = v88;
      v48 = _mm_mul_ps(v30, vOutDecorrelationVectorA);
      v49 = _mm_mul_ps(v30, vOutDecorrelationVectorB);
      if ( !v46 )
      {
        v93 = v98 + 1;
        v47 = v88;
      }
      v26 += 4;
      if ( v26 >= v92 )
        v26 = v98 + 2;
      v27 += 4;
      if ( v27 >= v92 )
        v27 = v98 + 3;
      v50 = _mm_mul_ps(v31, v112);
      v51 = _mm_unpacklo_ps(v45, v39);
      v28 += 4;
      v52 = (__m128)*(unsigned int *)v91;
      v53 = v89;
      v54 = _mm_unpacklo_ps(v44, v41);
      v55 = (__m128)*((unsigned int *)v28 - 4);
      if ( v28 >= v95 )
        v28 = v90;
      v56 = (__m128)*(unsigned int *)v89;
      v31 = _mm_add_ps(_mm_mul_ps(_mm_movelh_ps(v54, v51), v106), v50);
      v57 = _mm_add_ps(v31, v30);
      v58 = _mm_add_ps(v48, _mm_mul_ps(v31, vOutDecorrelationVectorA));
      v59 = _mm_add_ps(v49, _mm_mul_ps(v31, vOutDecorrelationVectorB));
      v60 = (__m128)*(unsigned int *)v47;
      v91 += 4;
      if ( v91 >= v95 )
      {
        v91 = v90 + 1;
        v53 = v89;
      }
      v88 += 4;
      if ( v88 >= v95 )
        v88 = v90 + 2;
      v89 = v53 + 4;
      if ( v53 + 4 >= v95 )
        v89 = v90 + 3;
      v10.m128_f32[0] = v10.m128_f32[0] + v108;
      v61 = pData;
      v62 = pData;
      v63 = _mm_unpacklo_ps(v60, v56);
      ++pData;
      v64 = *v62;
      v109 = v10;
      v65 = io_pBuffer->uMaxFrames;
      v96 = _mm_add_ps(_mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v55, v52), v63), v103), _mm_mul_ps(v96, v110));
      v66 = v61[v65];
      v67 = _mm_add_ps(_mm_mul_ps(v96, vOutDecorrelationVectorA), v58);
      v68 = _mm_add_ps(v67, _mm_movehl_ps(v67, v67));
      v69 = _mm_add_ps(_mm_mul_ps(v96, vOutDecorrelationVectorB), v59);
      v70 = _mm_add_ps(v69, _mm_movehl_ps(v69, v69));
      v71 = _mm_add_ps(v96, v57);
      v72 = _mm_add_ps(_mm_movehl_ps(v71, v71), v71);
      v73 = v100;
      v73.m128_f32[0] = v100.m128_f32[0] + v104;
      v100 = v73;
      v74 = _mm_add_ps(_mm_shuffle_ps(v72, v72, 85), v72);
      v75 = _mm_mul_ps(_mm_shuffle_ps(v74, v74, 0), v105);
      v72.m128_f32[0] = (float)(_mm_shuffle_ps(v68, v68, 85).m128_f32[0] + v68.m128_f32[0]) * v73.m128_f32[0];
      v76 = _mm_add_ps(v96, v75);
      *v61 = (float)(v64 * v10.m128_f32[0]) + v72.m128_f32[0];
      v72.m128_f32[0] = _mm_shuffle_ps(v70, v70, 85).m128_f32[0] + v70.m128_f32[0];
      v77 = _mm_add_ps(v75, v30);
      v61[v65] = (float)(v66 * v10.m128_f32[0]) + (float)(v72.m128_f32[0] * v73.m128_f32[0]);
      v78 = _mm_add_ps(v31, v75);
      v79 = _mm_shuffle_ps(v76, _mm_shuffle_ps(v76, v77, 15), 201);
      v80 = _mm_shuffle_ps(v78, _mm_shuffle_ps(v78, v76, 15), 201);
      v81 = _mm_shuffle_ps(v77, _mm_shuffle_ps(v77, v78, 15), 201);
      v9 = v64 + v66;
      v11 = (float)((float)(v107 * v11) + v9) - v102;
      v102 = v9;
      if ( m_pfPreDelayStart )
      {
        v82 = *m_pfPreDelayRW;
        *m_pfPreDelayRW++ = v11;
        if ( m_pfPreDelayRW == m_pfPreDelayEnd )
          m_pfPreDelayRW = m_pfPreDelayStart;
      }
      else
      {
        v82 = v11;
      }
      v34 = v97;
      v29 = v113;
      v20 += 4;
      v83 = v17;
      v84 = v18 * v14;
      v14 = v82;
      v83.m128_f32[0] = (float)(v17.m128_f32[0] * v82) + v84;
      v85 = _mm_shuffle_ps(v83, v83, 0);
      v86 = _mm_add_ps(v85, v79);
      v10 = v109;
      v87 = _mm_add_ps(v85, v80);
      v25 = v111;
      *((__m128 *)v20 - 1) = _mm_add_ps(v85, v81);
      if ( v20 >= v97 )
        v20 = v4;
      *(__m128 *)v5 = v87;
      v5 += 4;
      if ( v5 >= v92 )
        v5 = v98;
      *(__m128 *)v6 = v86;
      v6 += 4;
      if ( v6 >= v95 )
        v6 = v90;
      --uValidFrames;
    }
    while ( uValidFrames );
    v33 = v96;
    this = v114;
    v32 = v88;
  }
  this->m_fFIRLPFMem = v14;
  this->m_fDCFwdMem = v9;
  this->m_fDCFbkMem = v11;
  this->m_pfPreDelayRW = m_pfPreDelayRW;
  this->m_pfDelayRead[0] = v24;
  this->m_vIIRLPFMem[0] = v30;
  this->m_vIIRLPFMem[1] = v31;
  this->m_vIIRLPFMem[2] = v33;
  this->m_pfDelayRead[10] = v32;
  this->m_pfDelayRead[5] = v93;
  this->m_pfDelayWrite[0] = v20;
  this->m_pfDelayWrite[1] = v5;
  this->m_pfDelayWrite[2] = v6;
  this->m_pfDelayRead[1] = v7;
  this->m_pfDelayRead[9] = v91;
  this->m_pfDelayRead[2] = v8;
  this->m_pfDelayRead[3] = v12;
  this->m_pfDelayRead[4] = v13;
  this->m_pfDelayRead[6] = v26;
  this->m_pfDelayRead[7] = v27;
  this->m_pfDelayRead[8] = v28;
  this->m_pfDelayRead[11] = v89;
}

// File Line: 1297
// RVA: 0xAC4CC0
void __fastcall CAkFDNReverbFX::ProcessStereo16(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *m_pfPreDelayRW; // rdi
  CAkFDNReverbFXParams *m_pParams; // rdx
  float v6; // xmm5_4
  __m128 v7; // xmm11
  float v8; // xmm15_4
  float v9; // xmm12_4
  int uMaxFrames; // eax
  float *v11; // r8
  __m128 v12; // xmm0
  __m128 fDryLevel_low; // xmm1
  __m128 fWetLevel_low; // xmm0
  __m128 v15; // xmm4
  __m128 v16; // xmm10
  __m128 v17; // xmm6
  float *v18; // r9
  float *v19; // r10
  float *v20; // r11
  float *v21; // rdx
  float *v22; // r14
  float *v23; // r15
  __m128 v24; // xmm7
  __m128 v25; // xmm8
  __m128 v26; // xmm9
  float *v27; // rbx
  float *v28; // r12
  float *v29; // r13
  float *v30; // rsi
  __m128 v31; // xmm0
  float *v32; // rbp
  float *v33; // rax
  float *v34; // rcx
  float *v35; // rax
  __m128 v36; // xmm1
  __m128 v37; // xmm0
  __m128 v38; // xmm3
  __m128 v39; // xmm5
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm0
  __m128 v43; // xmm7
  __m128 v44; // xmm1
  __m128 v45; // xmm0
  __m128 v46; // xmm3
  __m128 v47; // xmm4
  float *v48; // rcx
  __m128 v49; // xmm0
  __m128 v50; // xmm1
  __m128 v51; // xmm2
  __m128 v52; // xmm5
  __m128 v53; // xmm1
  __m128 v54; // xmm0
  __m128 v55; // xmm8
  __m128 v56; // xmm1
  __m128 v57; // xmm10
  __m128 v58; // xmm3
  __m128 v59; // xmm4
  __m128 v60; // xmm0
  bool v61; // cf
  float *v62; // rax
  float *v63; // rcx
  __m128 v64; // xmm0
  __m128 v65; // xmm1
  __m128 v66; // xmm2
  __m128 v67; // xmm5
  __m128 v68; // xmm1
  __m128 v69; // xmm0
  __m128 v70; // xmm9
  __m128 v71; // xmm1
  __m128 v72; // xmm10
  __m128 v73; // xmm3
  __m128 v74; // xmm4
  __m128 v75; // xmm0
  float *v76; // rax
  float *v77; // rcx
  float *v78; // rax
  float v79; // xmm6_4
  __int64 v80; // rax
  __m128 v81; // xmm1
  float v82; // xmm5_4
  __m128 v83; // xmm2
  __m128 v84; // xmm2
  __m128 v85; // xmm3
  __m128 v86; // xmm3
  __m128 v87; // xmm0
  __m128 v88; // xmm10
  __m128 v89; // xmm1
  __m128 v90; // xmm4
  __m128 v91; // xmm4
  __m128 v92; // xmm2
  __m128 v93; // xmm3
  __m128 v94; // xmm1
  __m128 v95; // xmm10
  __m128 v96; // xmm11
  __m128 v97; // xmm1
  __m128 v98; // xmm4
  __m128 v99; // xmm3
  float v100; // xmm1_4
  __m128 v101; // xmm2
  float v102; // xmm0_4
  __m128 v103; // xmm2
  __m128 v104; // xmm1
  __m128 v105; // xmm0
  __m128 v106; // xmm2
  float *v107; // [rsp+0h] [rbp-2A8h]
  float *v108; // [rsp+8h] [rbp-2A0h]
  float *v109; // [rsp+10h] [rbp-298h]
  float *v110; // [rsp+18h] [rbp-290h]
  float *v111; // [rsp+20h] [rbp-288h]
  float *v112; // [rsp+28h] [rbp-280h]
  float *v113; // [rsp+30h] [rbp-278h]
  float *v114; // [rsp+38h] [rbp-270h]
  float *v115; // [rsp+40h] [rbp-268h]
  float *v116; // [rsp+48h] [rbp-260h]
  float *v117; // [rsp+50h] [rbp-258h]
  float *v118; // [rsp+58h] [rbp-250h]
  float *pData; // [rsp+60h] [rbp-248h]
  float *v120; // [rsp+68h] [rbp-240h]
  float *v121; // [rsp+70h] [rbp-238h]
  float *v122; // [rsp+78h] [rbp-230h]
  float *v123; // [rsp+80h] [rbp-228h]
  __m128 v124; // [rsp+90h] [rbp-218h]
  float *m_pfPreDelayStart; // [rsp+A0h] [rbp-208h]
  float *m_pfPreDelayEnd; // [rsp+A8h] [rbp-200h]
  __m128 v127; // [rsp+B0h] [rbp-1F8h]
  float v128; // [rsp+C0h] [rbp-1E8h]
  float v129; // [rsp+D0h] [rbp-1D8h]
  __m128 v130; // [rsp+E0h] [rbp-1C8h]
  float v131; // [rsp+F0h] [rbp-1B8h]
  __m128 v132; // [rsp+100h] [rbp-1A8h]
  __m128 v133; // [rsp+110h] [rbp-198h]
  __m128 v134; // [rsp+120h] [rbp-188h]
  float v135; // [rsp+130h] [rbp-178h]
  float v136; // [rsp+140h] [rbp-168h]
  __m128 v137; // [rsp+150h] [rbp-158h]
  __m128 v138; // [rsp+160h] [rbp-148h]
  __m128 v139; // [rsp+170h] [rbp-138h]
  __m128 v140; // [rsp+180h] [rbp-128h]
  __m128 v141; // [rsp+190h] [rbp-118h]
  __m128 v142; // [rsp+1A0h] [rbp-108h]
  __m128 v143; // [rsp+1B0h] [rbp-F8h]
  CAkFDNReverbFX *v144; // [rsp+2B0h] [rbp+8h]
  int uValidFrames; // [rsp+2C8h] [rbp+20h]

  v144 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  m_pfPreDelayRW = this->m_pfPreDelayRW;
  m_pParams = this->m_pParams;
  v133 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v6) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  LODWORD(v135) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  v7 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  LODWORD(v131) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  LODWORD(v8) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFMem), (__m128)LODWORD(this->m_fFIRLPFMem), 0).m128_u32[0];
  LODWORD(v9) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  v128 = v6;
  pData = (float *)io_pBuffer->pData;
  uMaxFrames = io_pBuffer->uMaxFrames;
  v11 = this->m_pfDelayWrite[0];
  v2.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  v12 = v2;
  fDryLevel_low = (__m128)LODWORD(m_pParams->RTPC.fDryLevel);
  v130 = _mm_shuffle_ps(v12, v12, 0);
  v127 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  m_pfPreDelayStart = this->m_pfPreDelayStart;
  v122 = this->m_pfDelayStart[0];
  v123 = this->m_pfDelayStart[1];
  v113 = this->m_pfDelayStart[2];
  fDryLevel_low.m128_f32[0] = (float)(fDryLevel_low.m128_f32[0] - this->m_fCurrentDry)
                            * (float)(1.0 / (float)uMaxFrames);
  v116 = this->m_pfDelayStart[3];
  LODWORD(v129) = _mm_shuffle_ps(fDryLevel_low, fDryLevel_low, 0).m128_u32[0];
  fWetLevel_low = (__m128)LODWORD(m_pParams->RTPC.fWetLevel);
  v115 = this->m_pfDelayEnd[0];
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  fWetLevel_low.m128_f32[0] = (float)(fWetLevel_low.m128_f32[0] - this->m_fCurrentWet)
                            * (float)(1.0 / (float)uMaxFrames);
  v114 = this->m_pfDelayEnd[1];
  LODWORD(v136) = _mm_shuffle_ps(fWetLevel_low, fWetLevel_low, 0).m128_u32[0];
  v120 = this->m_pfDelayEnd[2];
  v121 = this->m_pfDelayEnd[3];
  v15 = this->m_vIIRLPFB0[0];
  v16 = this->m_vIIRLPFB0[1];
  v17 = this->m_vIIRLPFA1[0];
  v18 = this->m_pfDelayWrite[1];
  v19 = this->m_pfDelayWrite[2];
  v20 = this->m_pfDelayWrite[3];
  v21 = this->m_pfDelayRead[0];
  v22 = this->m_pfDelayRead[2];
  v23 = this->m_pfDelayRead[3];
  v24 = this->m_vIIRLPFMem[0];
  v25 = this->m_vIIRLPFMem[1];
  v26 = this->m_vIIRLPFMem[2];
  v27 = this->m_pfDelayRead[4];
  v28 = this->m_pfDelayRead[6];
  v29 = this->m_pfDelayRead[7];
  v140 = this->m_vIIRLPFB0[2];
  v139 = v15;
  v138 = this->m_vIIRLPFB0[3];
  v143 = v16;
  v30 = this->m_pfDelayRead[8];
  v142 = this->m_vIIRLPFA1[1];
  v141 = v17;
  v118 = this->m_pfDelayRead[5];
  v108 = this->m_pfDelayRead[10];
  v132 = this->m_vIIRLPFA1[2];
  v110 = this->m_pfDelayRead[9];
  v134 = this->m_vIIRLPFA1[3];
  v31 = this->m_vIIRLPFMem[3];
  v111 = this->m_pfDelayRead[13];
  v117 = this->m_pfDelayRead[11];
  v124 = v31;
  v32 = this->m_pfDelayRead[12];
  v109 = this->m_pfDelayRead[14];
  v112 = this->m_pfDelayRead[15];
  uValidFrames = io_pBuffer->uValidFrames;
  v33 = this->m_pfDelayRead[1];
  if ( io_pBuffer->uValidFrames )
  {
    v34 = this->m_pfDelayRead[1];
    v35 = v122;
    do
    {
      v36 = (__m128)*(unsigned int *)v21;
      v37 = (__m128)*(unsigned int *)v22;
      v21 += 4;
      if ( v21 >= v115 )
        v21 = v35;
      v107 = v34 + 4;
      v38 = (__m128)*(unsigned int *)v23;
      if ( v34 + 4 >= v115 )
        v107 = v35 + 1;
      v22 += 4;
      if ( v22 >= v115 )
        v22 = v35 + 2;
      v23 += 4;
      if ( v23 >= v115 )
        v23 = v35 + 3;
      v39 = (__m128)*(unsigned int *)v29;
      v27 += 4;
      v40 = _mm_movelh_ps(_mm_unpacklo_ps(v36, (__m128)*(unsigned int *)v34), _mm_unpacklo_ps(v37, v38));
      v41 = (__m128)*(unsigned int *)v118;
      v42 = _mm_mul_ps(v24, v17);
      v43 = _mm_mul_ps(v40, v15);
      v44 = (__m128)*((unsigned int *)v27 - 4);
      if ( v27 >= v114 )
        v27 = v123;
      v24 = _mm_add_ps(v43, v42);
      v45 = (__m128)*(unsigned int *)v28;
      v118 += 4;
      v46 = _mm_mul_ps(v24, vOutDecorrelationVectorA);
      v47 = _mm_mul_ps(v24, vOutDecorrelationVectorB);
      if ( v118 >= v114 )
        v118 = v123 + 1;
      v28 += 4;
      if ( v28 >= v114 )
        v28 = v123 + 2;
      v29 += 4;
      if ( v29 >= v114 )
        v29 = v123 + 3;
      v48 = v117;
      v30 += 4;
      v49 = _mm_unpacklo_ps(v45, v39);
      v50 = _mm_unpacklo_ps(v44, v41);
      v51 = (__m128)*(unsigned int *)v110;
      v52 = (__m128)*(unsigned int *)v117;
      v53 = _mm_mul_ps(_mm_movelh_ps(v50, v49), v16);
      v54 = _mm_mul_ps(v25, v142);
      v55 = v53;
      v56 = (__m128)*((unsigned int *)v30 - 4);
      if ( v30 >= v120 )
        v30 = v113;
      v25 = _mm_add_ps(v55, v54);
      v57 = _mm_add_ps(v25, v24);
      v58 = _mm_add_ps(v46, _mm_mul_ps(v25, vOutDecorrelationVectorA));
      v59 = _mm_add_ps(v47, _mm_mul_ps(v25, vOutDecorrelationVectorB));
      v60 = (__m128)*(unsigned int *)v108;
      v61 = v110 + 4 < v120;
      v110 += 4;
      v62 = v108;
      if ( !v61 )
      {
        v110 = v113 + 1;
        v62 = v108;
      }
      v108 = v62 + 4;
      if ( v62 + 4 >= v120 )
        v108 = v113 + 2;
      v117 += 4;
      if ( v48 + 4 >= v120 )
        v117 = v113 + 3;
      v63 = v112;
      v32 += 4;
      v64 = _mm_unpacklo_ps(v60, v52);
      v65 = _mm_unpacklo_ps(v56, v51);
      v66 = (__m128)*(unsigned int *)v111;
      v67 = (__m128)*(unsigned int *)v112;
      v68 = _mm_mul_ps(_mm_movelh_ps(v65, v64), v140);
      v69 = _mm_mul_ps(v26, v132);
      v70 = v68;
      v71 = (__m128)*((unsigned int *)v32 - 4);
      if ( v32 >= v121 )
        v32 = v116;
      v26 = _mm_add_ps(v70, v69);
      v72 = _mm_add_ps(v57, v26);
      v73 = _mm_add_ps(v58, _mm_mul_ps(v26, vOutDecorrelationVectorA));
      v74 = _mm_add_ps(v59, _mm_mul_ps(v26, vOutDecorrelationVectorB));
      v75 = (__m128)*(unsigned int *)v109;
      v61 = v111 + 4 < v121;
      v111 += 4;
      v76 = v109;
      if ( !v61 )
      {
        v111 = v116 + 1;
        v76 = v109;
      }
      v109 = v76 + 4;
      if ( v76 + 4 >= v121 )
        v109 = v116 + 2;
      v112 += 4;
      if ( v63 + 4 >= v121 )
        v112 = v116 + 3;
      v7.m128_f32[0] = v7.m128_f32[0] + v129;
      v77 = pData;
      v78 = pData++;
      v79 = *v78;
      v137 = v7;
      v80 = io_pBuffer->uMaxFrames;
      v81 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v71, v66), _mm_unpacklo_ps(v75, v67)), v138),
              _mm_mul_ps(v124, v134));
      v82 = v77[v80];
      v124 = v81;
      v83 = _mm_add_ps(_mm_mul_ps(v81, vOutDecorrelationVectorA), v73);
      v84 = _mm_add_ps(v83, _mm_movehl_ps(v83, v83));
      v85 = _mm_add_ps(_mm_mul_ps(v81, vOutDecorrelationVectorB), v74);
      v86 = _mm_add_ps(v85, _mm_movehl_ps(v85, v85));
      v87 = _mm_add_ps(v81, v72);
      v88 = v127;
      v88.m128_f32[0] = v127.m128_f32[0] + v136;
      v89 = _mm_add_ps(_mm_movehl_ps(v87, v87), v87);
      v127 = v88;
      v90 = _mm_add_ps(_mm_shuffle_ps(v89, v89, 85), v89);
      v89.m128_f32[0] = _mm_shuffle_ps(v84, v84, 85).m128_f32[0] + v84.m128_f32[0];
      v91 = _mm_mul_ps(_mm_shuffle_ps(v90, v90, 0), v130);
      v92 = _mm_add_ps(v26, v91);
      *v77 = (float)(v79 * v7.m128_f32[0]) + (float)(v89.m128_f32[0] * v88.m128_f32[0]);
      v89.m128_f32[0] = _mm_shuffle_ps(v86, v86, 85).m128_f32[0] + v86.m128_f32[0];
      v93 = _mm_add_ps(v91, v24);
      v77[v80] = (float)(v82 * v7.m128_f32[0]) + (float)(v89.m128_f32[0] * v88.m128_f32[0]);
      v94 = _mm_add_ps(v124, v91);
      v95 = _mm_shuffle_ps(v94, _mm_shuffle_ps(v94, v93, 15), 201);
      v96 = _mm_shuffle_ps(v92, _mm_shuffle_ps(v92, v94, 15), 201);
      v97 = _mm_add_ps(v25, v91);
      v98 = _mm_shuffle_ps(v97, _mm_shuffle_ps(v97, v92, 15), 201);
      v99 = _mm_shuffle_ps(v93, _mm_shuffle_ps(v93, v97, 15), 201);
      v6 = v79 + v82;
      v9 = (float)((float)(v131 * v9) + v6) - v128;
      v128 = v6;
      if ( m_pfPreDelayStart )
      {
        v100 = *m_pfPreDelayRW;
        *m_pfPreDelayRW++ = v9;
        if ( m_pfPreDelayRW == m_pfPreDelayEnd )
          m_pfPreDelayRW = m_pfPreDelayStart;
      }
      else
      {
        v100 = v9;
      }
      v101 = v133;
      v35 = v122;
      v34 = v107;
      v11 += 4;
      v102 = v135 * v8;
      v17 = v141;
      v8 = v100;
      v101.m128_f32[0] = (float)(v133.m128_f32[0] * v100) + v102;
      v103 = _mm_shuffle_ps(v101, v101, 0);
      v104 = _mm_add_ps(v103, v98);
      v15 = v139;
      *((__m128 *)v11 - 1) = _mm_add_ps(v103, v99);
      *(__m128 *)v18 = v104;
      if ( v11 >= v115 )
        v11 = v122;
      v18 += 4;
      v105 = _mm_add_ps(v103, v96);
      if ( v18 >= v114 )
        v18 = v123;
      v19 += 4;
      v106 = _mm_add_ps(v103, v95);
      v7 = v137;
      v16 = v143;
      *((__m128 *)v19 - 1) = v105;
      if ( v19 >= v120 )
        v19 = v113;
      v20 += 4;
      *((__m128 *)v20 - 1) = v106;
      if ( v20 >= v121 )
        v20 = v116;
      --uValidFrames;
    }
    while ( uValidFrames );
    v31 = v124;
    this = v144;
    v33 = v107;
  }
  this->m_fFIRLPFMem = v8;
  this->m_fDCFwdMem = v6;
  this->m_fDCFbkMem = v9;
  this->m_pfPreDelayRW = m_pfPreDelayRW;
  this->m_pfDelayRead[1] = v33;
  this->m_vIIRLPFMem[0] = v24;
  this->m_vIIRLPFMem[1] = v25;
  this->m_vIIRLPFMem[2] = v26;
  this->m_pfDelayRead[5] = v118;
  this->m_pfDelayWrite[3] = v20;
  this->m_vIIRLPFMem[3] = v31;
  this->m_pfDelayRead[9] = v110;
  this->m_pfDelayRead[10] = v108;
  this->m_pfDelayWrite[0] = v11;
  this->m_pfDelayRead[11] = v117;
  this->m_pfDelayWrite[1] = v18;
  this->m_pfDelayRead[13] = v111;
  this->m_pfDelayWrite[2] = v19;
  this->m_pfDelayRead[14] = v109;
  this->m_pfDelayRead[0] = v21;
  this->m_pfDelayRead[2] = v22;
  this->m_pfDelayRead[3] = v23;
  this->m_pfDelayRead[4] = v27;
  this->m_pfDelayRead[15] = v112;
  this->m_pfDelayRead[6] = v28;
  this->m_pfDelayRead[7] = v29;
  this->m_pfDelayRead[8] = v30;
  this->m_pfDelayRead[12] = v32;
}

// File Line: 1341
// RVA: 0xAC56D0
void __fastcall CAkFDNReverbFX::ProcessFivePointZero4(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *m_pfPreDelayRW; // rdi
  CAkFDNReverbFX *v4; // r10
  AkAudioBuffer *v5; // r8
  CAkFDNReverbFXParams *m_pParams; // rdx
  __m128 v7; // xmm5
  __m128 v8; // xmm7
  __m128 v9; // xmm6
  int uValidFrames; // r13d
  float *v11; // r15
  float v12; // xmm4_4
  float *v13; // r12
  float *v14; // r11
  float *v15; // rbx
  float v16; // xmm13_4
  float v17; // xmm12_4
  __m128 v18; // xmm14
  float v19; // xmm15_4
  float *v20; // r14
  float *v21; // rsi
  float *v22; // rbp
  __m128 v23; // xmm0
  __m128 fDryLevel_low; // xmm1
  float v25; // xmm2_4
  __m128 fWetLevel_low; // xmm0
  float *m_pfPreDelayStart; // r10
  float *v28; // rax
  __m128 v29; // xmm1
  __m128 v30; // xmm2
  __m128 v31; // xmm0
  __m128 v32; // xmm3
  float v33; // xmm11_4
  __int64 uMaxFrames; // rcx
  float v35; // xmm9_4
  __int64 v36; // rdx
  __int64 v37; // r8
  float v38; // xmm10_4
  float v39; // xmm8_4
  __int64 v40; // r9
  __m128 v41; // xmm6
  float v42; // xmm7_4
  __m128 v43; // xmm2
  __m128 v44; // xmm3
  __m128 v45; // xmm4
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm5
  __m128 v49; // xmm6
  __m128 v50; // xmm3
  __m128 v51; // xmm4
  __m128 v52; // xmm5
  __m128 v53; // xmm6
  __m128 v54; // xmm0
  __m128 v55; // xmm1
  __m128 v56; // xmm0
  __m128 v57; // xmm0
  __m128 v58; // xmm3
  __m128 v59; // xmm3
  float v60; // xmm2_4
  __m128 v61; // xmm1
  float v62; // xmm0_4
  __m128 v63; // [rsp+0h] [rbp-1A8h]
  __m128 v64; // [rsp+10h] [rbp-198h]
  __m128 v65; // [rsp+20h] [rbp-188h]
  float *m_pfPreDelayEnd; // [rsp+30h] [rbp-178h]
  float v67; // [rsp+40h] [rbp-168h]
  float v68; // [rsp+50h] [rbp-158h]
  __m128 v69; // [rsp+60h] [rbp-148h]
  float v70; // [rsp+70h] [rbp-138h]
  __m128 v71; // [rsp+80h] [rbp-128h]
  __m128 v72; // [rsp+90h] [rbp-118h]
  float v73; // [rsp+A0h] [rbp-108h]
  __m128 v74; // [rsp+B0h] [rbp-F8h]
  bool v77; // [rsp+1C0h] [rbp+18h]
  float *pData; // [rsp+1C8h] [rbp+20h]

  v2 = (__m128)LODWORD(FLOAT_N2_0);
  m_pfPreDelayRW = this->m_pfPreDelayRW;
  v4 = this;
  v5 = io_pBuffer;
  m_pParams = this->m_pParams;
  v7 = this->m_vIIRLPFB0[0];
  v8 = this->m_vIIRLPFA1[0];
  v9 = this->m_vIIRLPFMem[0];
  uValidFrames = v5->uValidFrames;
  v11 = this->m_pfDelayStart[0];
  LODWORD(v12) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  LODWORD(v70) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  v13 = this->m_pfDelayEnd[0];
  v14 = this->m_pfDelayWrite[0];
  v15 = this->m_pfDelayRead[0];
  LODWORD(v16) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFMem), (__m128)LODWORD(this->m_fFIRLPFMem), 0).m128_u32[0];
  LODWORD(v17) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  v65 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  v18 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v19) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  v20 = this->m_pfDelayRead[1];
  v21 = this->m_pfDelayRead[2];
  v22 = this->m_pfDelayRead[3];
  v67 = v12;
  v72 = v7;
  v74 = v8;
  pData = (float *)v5->pData;
  v2.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  v23 = v2;
  fDryLevel_low = (__m128)LODWORD(m_pParams->RTPC.fDryLevel);
  v69 = _mm_shuffle_ps(v23, v23, 0);
  v64 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  v77 = this->m_pfPreDelayStart != 0i64;
  v25 = 1.0 / (float)v5->uMaxFrames;
  fDryLevel_low.m128_f32[0] = (float)(fDryLevel_low.m128_f32[0] - this->m_fCurrentDry) * v25;
  LODWORD(v68) = _mm_shuffle_ps(fDryLevel_low, fDryLevel_low, 0).m128_u32[0];
  fWetLevel_low = (__m128)LODWORD(m_pParams->RTPC.fWetLevel);
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  fWetLevel_low.m128_f32[0] = (float)(fWetLevel_low.m128_f32[0] - this->m_fCurrentWet) * v25;
  LODWORD(v73) = _mm_shuffle_ps(fWetLevel_low, fWetLevel_low, 0).m128_u32[0];
  if ( v5->uValidFrames )
  {
    m_pfPreDelayStart = this->m_pfPreDelayStart;
    v28 = (float *)v5->pData;
    do
    {
      v29 = (__m128)*(unsigned int *)v15;
      v30 = (__m128)*(unsigned int *)v20;
      v31 = (__m128)*(unsigned int *)v21;
      v15 += 4;
      if ( v15 >= v13 )
        v15 = v11;
      v20 += 4;
      v32 = (__m128)*(unsigned int *)v22;
      if ( v20 >= v13 )
        v20 = v11 + 1;
      v21 += 4;
      if ( v21 >= v13 )
        v21 = v11 + 2;
      v22 += 4;
      if ( v22 >= v13 )
        v22 = v11 + 3;
      v33 = *v28;
      uMaxFrames = v5->uMaxFrames;
      v35 = v28[uMaxFrames];
      v36 = 2 * (int)uMaxFrames;
      v37 = 3 * (int)uMaxFrames;
      v38 = pData[v36];
      v39 = pData[v37];
      v40 = 4 * (int)uMaxFrames;
      v41 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v29, v30), _mm_unpacklo_ps(v31, v32)), v7),
              _mm_mul_ps(v9, v8));
      v42 = pData[v40];
      v43 = _mm_mul_ps(v41, vOutDecorrelationVectorA);
      v44 = _mm_mul_ps(v41, vOutDecorrelationVectorB);
      v45 = _mm_mul_ps(v41, vOutDecorrelationVectorC);
      v63 = v41;
      v46 = v41;
      v47 = _mm_add_ps(v43, _mm_movehl_ps(v43, v43));
      v48 = _mm_mul_ps(v41, vOutDecorrelationVectorD);
      v49 = _mm_mul_ps(v41, vOutDecorrelationVectorF);
      v50 = _mm_add_ps(v44, _mm_movehl_ps(v44, v44));
      v51 = _mm_add_ps(v45, _mm_movehl_ps(v45, v45));
      v52 = _mm_add_ps(v48, _mm_movehl_ps(v48, v48));
      v53 = _mm_add_ps(v49, _mm_movehl_ps(v49, v49));
      v54 = _mm_add_ps(_mm_movehl_ps(v46, v46), v46);
      v55 = _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), v54);
      v56 = v64;
      v56.m128_f32[0] = v64.m128_f32[0] + v68;
      v71 = v55;
      v64 = v56;
      v57 = v65;
      v57.m128_f32[0] = v65.m128_f32[0] + v73;
      v65 = v57;
      *pData = (float)(*v28 * v64.m128_f32[0])
             + (float)((float)(_mm_shuffle_ps(v47, v47, 85).m128_f32[0] + v47.m128_f32[0]) * v57.m128_f32[0]);
      pData[uMaxFrames] = (float)(v35 * v64.m128_f32[0])
                        + (float)((float)(_mm_shuffle_ps(v50, v50, 85).m128_f32[0] + v50.m128_f32[0]) * v57.m128_f32[0]);
      v28 = pData + 1;
      pData = v28;
      v28[v36 - 1] = (float)(v38 * v64.m128_f32[0])
                   + (float)((float)(_mm_shuffle_ps(v51, v51, 85).m128_f32[0] + v51.m128_f32[0]) * v57.m128_f32[0]);
      v12 = (float)(v38 + v39) + (float)((float)(v33 + v35) + v42);
      v28[v37 - 1] = (float)(v39 * v64.m128_f32[0])
                   + (float)((float)(_mm_shuffle_ps(v52, v52, 85).m128_f32[0] + v52.m128_f32[0]) * v57.m128_f32[0]);
      v55.m128_f32[0] = _mm_shuffle_ps(v53, v53, 85).m128_f32[0] + v53.m128_f32[0];
      v9 = v63;
      v28[v40 - 1] = (float)(v42 * v64.m128_f32[0]) + (float)(v55.m128_f32[0] * v57.m128_f32[0]);
      v58 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v71, v71, 0), v69), v63);
      v59 = _mm_shuffle_ps(v58, _mm_shuffle_ps(v58, v58, 15), 201);
      v17 = (float)((float)(v70 * v17) + v12) - v67;
      v67 = v12;
      if ( v77 )
      {
        v60 = *m_pfPreDelayRW;
        *m_pfPreDelayRW++ = v17;
        if ( m_pfPreDelayRW == m_pfPreDelayEnd )
          m_pfPreDelayRW = m_pfPreDelayStart;
      }
      else
      {
        v60 = v17;
      }
      v7 = v72;
      v8 = v74;
      v5 = io_pBuffer;
      v14 += 4;
      v61 = v18;
      v62 = v19 * v16;
      v16 = v60;
      v61.m128_f32[0] = (float)(v18.m128_f32[0] * v60) + v62;
      *((__m128 *)v14 - 1) = _mm_add_ps(_mm_shuffle_ps(v61, v61, 0), v59);
      if ( v14 >= v13 )
        v14 = v11;
      --uValidFrames;
    }
    while ( uValidFrames );
    v4 = this;
  }
  v4->m_fFIRLPFMem = v16;
  v4->m_fDCFwdMem = v12;
  v4->m_fDCFbkMem = v17;
  v4->m_pfPreDelayRW = m_pfPreDelayRW;
  v4->m_pfDelayWrite[0] = v14;
  v4->m_vIIRLPFMem[0] = v9;
  v4->m_pfDelayRead[0] = v15;
  v4->m_pfDelayRead[1] = v20;
  v4->m_pfDelayRead[2] = v21;
  v4->m_pfDelayRead[3] = v22;
}
  v4->m_pf

// File Line: 1372
// RVA: 0xAC5C50
void __fastcall CAkFDNReverbFX::ProcessFivePointZero8(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *m_pfPreDelayRW; // rbp
  CAkFDNReverbFX *v4; // r10
  CAkFDNReverbFXParams *m_pParams; // rdx
  float *v7; // r9
  float *v8; // rbx
  float *v9; // rdi
  float v10; // xmm5_4
  float v11; // xmm14_4
  float *v12; // r11
  float *v13; // r12
  float *v14; // r14
  float *v15; // r15
  float *v16; // rsi
  __m128 v17; // xmm0
  __m128 fDryLevel_low; // xmm1
  float *v19; // rax
  float v20; // xmm2_4
  __m128 fWetLevel_low; // xmm0
  float *v22; // rdx
  __m128 m_fFIRLPFMem_low; // xmm2
  float *v24; // rcx
  float v25; // xmm2_4
  __m128 v26; // xmm4
  __m128 v27; // xmm8
  float *v28; // r13
  float *v29; // rax
  __m128 v30; // xmm6
  __m128 v31; // xmm9
  __m128 v32; // xmm15
  float *v33; // r8
  __m128 v34; // xmm13
  __m128 v35; // xmm7
  unsigned int *v36; // r10
  __m128 v37; // xmm1
  __m128 v38; // xmm2
  __m128 v39; // xmm0
  __m128 v40; // xmm3
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm13
  __m128 v44; // xmm0
  __m128 v45; // xmm3
  __m128 v46; // xmm0
  __m128 v47; // xmm1
  __m128 v48; // xmm4
  __m128 v49; // xmm6
  __m128 v50; // xmm7
  __m128 v51; // xmm5
  __m128 v52; // xmm15
  __int64 uMaxFrames; // rcx
  float v54; // xmm12_4
  float v55; // xmm10_4
  __m128 v56; // xmm7
  __int64 v57; // rdx
  __int64 v58; // r8
  float v59; // xmm11_4
  float v60; // xmm9_4
  __int64 v61; // r9
  __m128 v62; // xmm2
  __m128 v63; // xmm3
  float v64; // xmm8_4
  __m128 v65; // xmm2
  __m128 v66; // xmm3
  __m128 v67; // xmm4
  __m128 v68; // xmm4
  __m128 v69; // xmm5
  __m128 v70; // xmm5
  __m128 v71; // xmm7
  __m128 v72; // xmm15
  __m128 v73; // xmm7
  __m128 v74; // xmm0
  __m128 v75; // xmm1
  __m128 v76; // xmm0
  __m128 v77; // xmm6
  __m128 v78; // xmm6
  __m128 v79; // xmm3
  __m128 v80; // xmm1
  __m128 v81; // xmm4
  __m128 v82; // xmm3
  __m128 v83; // xmm1
  __m128 v84; // xmm0
  __m128 v85; // xmm1
  float *v86; // [rsp+0h] [rbp-238h]
  float *v87; // [rsp+8h] [rbp-230h]
  float *pData; // [rsp+10h] [rbp-228h]
  float *v89; // [rsp+18h] [rbp-220h]
  __m128 v90; // [rsp+20h] [rbp-218h]
  float *m_pfPreDelayStart; // [rsp+30h] [rbp-208h]
  float *v92; // [rsp+38h] [rbp-200h]
  float *v93; // [rsp+40h] [rbp-1F8h]
  float *m_pfPreDelayEnd; // [rsp+48h] [rbp-1F0h]
  float *v95; // [rsp+50h] [rbp-1E8h]
  __m128 v96; // [rsp+60h] [rbp-1D8h]
  float v97; // [rsp+70h] [rbp-1C8h]
  __m128 v98; // [rsp+80h] [rbp-1B8h]
  float v99; // [rsp+90h] [rbp-1A8h]
  float v100; // [rsp+A0h] [rbp-198h]
  __m128 v101; // [rsp+B0h] [rbp-188h]
  float v102; // [rsp+C0h] [rbp-178h]
  float v103; // [rsp+D0h] [rbp-168h]
  __m128 v104; // [rsp+E0h] [rbp-158h]
  __m128 v105; // [rsp+F0h] [rbp-148h]
  __m128 v106; // [rsp+100h] [rbp-138h]
  __m128 v107; // [rsp+110h] [rbp-128h]
  __m128 v108; // [rsp+120h] [rbp-118h]
  float v109; // [rsp+130h] [rbp-108h]
  __m128 v110; // [rsp+140h] [rbp-F8h]
  int uValidFrames; // [rsp+258h] [rbp+20h]

  v2 = (__m128)LODWORD(FLOAT_N2_0);
  m_pfPreDelayRW = this->m_pfPreDelayRW;
  v4 = this;
  m_pParams = this->m_pParams;
  v101 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  v7 = this->m_pfDelayEnd[1];
  v8 = this->m_pfDelayWrite[0];
  v9 = this->m_pfDelayWrite[1];
  LODWORD(v10) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  LODWORD(v102) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  LODWORD(v11) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  v12 = this->m_pfDelayRead[0];
  v13 = this->m_pfDelayRead[1];
  v14 = this->m_pfDelayRead[2];
  LODWORD(v100) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  v96 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  v97 = v10;
  v15 = this->m_pfDelayRead[3];
  v16 = this->m_pfDelayRead[4];
  v2.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  pData = (float *)io_pBuffer->pData;
  v89 = this->m_pfDelayStart[1];
  v92 = v7;
  v17 = v2;
  fDryLevel_low = (__m128)LODWORD(m_pParams->RTPC.fDryLevel);
  v107 = _mm_shuffle_ps(v17, v17, 0);
  v98 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  m_pfPreDelayStart = this->m_pfPreDelayStart;
  v19 = this->m_pfDelayRead[5];
  v20 = 1.0 / (float)io_pBuffer->uMaxFrames;
  fDryLevel_low.m128_f32[0] = (float)(fDryLevel_low.m128_f32[0] - this->m_fCurrentDry) * v20;
  LODWORD(v109) = _mm_shuffle_ps(fDryLevel_low, fDryLevel_low, 0).m128_u32[0];
  fWetLevel_low = (__m128)LODWORD(m_pParams->RTPC.fWetLevel);
  v22 = this->m_pfDelayEnd[0];
  v93 = v22;
  fWetLevel_low.m128_f32[0] = (float)(fWetLevel_low.m128_f32[0] - this->m_fCurrentWet) * v20;
  m_fFIRLPFMem_low = (__m128)LODWORD(this->m_fFIRLPFMem);
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  v24 = this->m_pfDelayStart[0];
  v95 = v24;
  LODWORD(v25) = _mm_shuffle_ps(m_fFIRLPFMem_low, m_fFIRLPFMem_low, 0).m128_u32[0];
  LODWORD(v103) = _mm_shuffle_ps(fWetLevel_low, fWetLevel_low, 0).m128_u32[0];
  v99 = v25;
  v26 = v4->m_vIIRLPFB0[0];
  v27 = v4->m_vIIRLPFB0[1];
  v28 = v4->m_pfDelayRead[6];
  v87 = v19;
  v29 = v4->m_pfDelayRead[7];
  v30 = v4->m_vIIRLPFA1[0];
  v31 = v4->m_vIIRLPFA1[1];
  v32 = v4->m_vIIRLPFMem[1];
  uValidFrames = io_pBuffer->uValidFrames;
  v33 = v89;
  v34 = v4->m_vIIRLPFMem[0];
  v104 = v26;
  v108 = v27;
  v106 = v30;
  v110 = v31;
  v90 = v32;
  if ( io_pBuffer->uValidFrames )
  {
    v35 = vOutDecorrelationVectorD;
    v36 = (unsigned int *)v4->m_pfDelayRead[7];
    v105 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorD);
    do
    {
      v37 = (__m128)*(unsigned int *)v12;
      v38 = (__m128)*(unsigned int *)v13;
      v39 = (__m128)*(unsigned int *)v14;
      v12 += 4;
      if ( v12 >= v22 )
        v12 = v24;
      v13 += 4;
      v40 = (__m128)*(unsigned int *)v15;
      if ( v13 >= v22 )
        v13 = v24 + 1;
      v14 += 4;
      if ( v14 >= v22 )
        v14 = v24 + 2;
      v15 += 4;
      if ( v15 >= v22 )
        v15 = v24 + 3;
      v41 = _mm_unpacklo_ps(v37, v38);
      v42 = (__m128)*(unsigned int *)v16;
      v43 = _mm_mul_ps(v34, v30);
      v44 = _mm_unpacklo_ps(v39, v40);
      v16 += 4;
      if ( v16 >= v7 )
        v16 = v33;
      v87 += 4;
      v45 = (__m128)*((unsigned int *)v87 - 4);
      v34 = _mm_add_ps(_mm_mul_ps(_mm_movelh_ps(v41, v44), v26), v43);
      v46 = (__m128)*(unsigned int *)v28;
      v47 = _mm_mul_ps(v34, vOutDecorrelationVectorA);
      v48 = _mm_mul_ps(v34, vOutDecorrelationVectorB);
      v49 = _mm_mul_ps(v34, v35);
      v50 = (__m128)*v36;
      v51 = _mm_mul_ps(v34, vOutDecorrelationVectorC);
      v52 = _mm_mul_ps(v34, vOutDecorrelationVectorF);
      if ( v87 >= v7 )
        v87 = v33 + 1;
      v28 += 4;
      if ( v28 >= v7 )
        v28 = v33 + 2;
      v36 += 4;
      if ( v36 >= (unsigned int *)v7 )
        v36 = (unsigned int *)(v33 + 3);
      uMaxFrames = io_pBuffer->uMaxFrames;
      v54 = *pData;
      v55 = pData[uMaxFrames];
      v56 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v42, v45), _mm_unpacklo_ps(v46, v50)), v27),
              _mm_mul_ps(v90, v31));
      v57 = 2 * (int)uMaxFrames;
      v58 = 3 * (int)uMaxFrames;
      v59 = pData[v57];
      v60 = pData[v58];
      v61 = 4 * (int)uMaxFrames;
      v90 = v56;
      v62 = _mm_add_ps(_mm_mul_ps(v56, vOutDecorrelationVectorA), v47);
      v63 = _mm_add_ps(_mm_mul_ps(v56, vOutDecorrelationVectorB), v48);
      v64 = pData[v61];
      v65 = _mm_add_ps(v62, _mm_movehl_ps(v62, v62));
      v66 = _mm_add_ps(v63, _mm_movehl_ps(v63, v63));
      v67 = _mm_add_ps(_mm_mul_ps(v56, vOutDecorrelationVectorC), v51);
      v68 = _mm_add_ps(v67, _mm_movehl_ps(v67, v67));
      v69 = _mm_add_ps(_mm_mul_ps(v56, vOutDecorrelationVectorE), v49);
      v70 = _mm_add_ps(v69, _mm_movehl_ps(v69, v69));
      v71 = _mm_add_ps(_mm_mul_ps(v105, v56), v52);
      v72 = v98;
      v72.m128_f32[0] = v98.m128_f32[0] + v109;
      v73 = _mm_add_ps(v71, _mm_movehl_ps(v71, v71));
      v98 = v72;
      v74 = _mm_add_ps(v90, v34);
      v75 = _mm_add_ps(_mm_movehl_ps(v74, v74), v74);
      v76 = v96;
      v76.m128_f32[0] = v96.m128_f32[0] + v103;
      v96 = v76;
      v77 = _mm_add_ps(_mm_shuffle_ps(v75, v75, 85), v75);
      v75.m128_f32[0] = _mm_shuffle_ps(v65, v65, 85).m128_f32[0] + v65.m128_f32[0];
      v65.m128_i32[0] = v76.m128_i32[0];
      *pData = (float)(*pData * v72.m128_f32[0]) + (float)(v75.m128_f32[0] * v76.m128_f32[0]);
      v78 = _mm_mul_ps(_mm_shuffle_ps(v77, v77, 0), v107);
      ++pData;
      pData[uMaxFrames - 1] = (float)(v55 * v72.m128_f32[0])
                            + (float)((float)(_mm_shuffle_ps(v66, v66, 85).m128_f32[0] + v66.m128_f32[0])
                                    * v76.m128_f32[0]);
      v79 = _mm_add_ps(v78, v34);
      pData[v57 - 1] = (float)(v59 * v72.m128_f32[0])
                     + (float)((float)(_mm_shuffle_ps(v68, v68, 85).m128_f32[0] + v68.m128_f32[0]) * v76.m128_f32[0]);
      v75.m128_f32[0] = _mm_shuffle_ps(v70, v70, 85).m128_f32[0] + v70.m128_f32[0];
      v10 = (float)(v59 + v60) + (float)((float)(v54 + v55) + v64);
      pData[v58 - 1] = (float)(v60 * v72.m128_f32[0]) + (float)(v75.m128_f32[0] * v76.m128_f32[0]);
      v76.m128_f32[0] = v64 * v72.m128_f32[0];
      v32 = v90;
      pData[v61 - 1] = v76.m128_f32[0]
                     + (float)((float)(_mm_shuffle_ps(v73, v73, 85).m128_f32[0] + v73.m128_f32[0]) * v65.m128_f32[0]);
      v80 = _mm_add_ps(v90, v78);
      v81 = _mm_shuffle_ps(v80, _mm_shuffle_ps(v80, v79, 15), 201);
      v82 = _mm_shuffle_ps(v79, _mm_shuffle_ps(v79, v80, 15), 201);
      v11 = (float)((float)(v100 * v11) + v10) - v97;
      v97 = v10;
      if ( m_pfPreDelayStart )
      {
        v25 = *m_pfPreDelayRW;
        *m_pfPreDelayRW++ = v11;
        if ( m_pfPreDelayRW == m_pfPreDelayEnd )
          m_pfPreDelayRW = m_pfPreDelayStart;
      }
      else
      {
        v25 = v11;
      }
      v83 = v101;
      v22 = v93;
      v24 = v95;
      v7 = v92;
      v33 = v89;
      v35 = vOutDecorrelationVectorD;
      v30 = v106;
      v27 = v108;
      v8 += 4;
      v83.m128_f32[0] = (float)(v101.m128_f32[0] * v25) + (float)(v102 * v99);
      v31 = v110;
      v84 = _mm_shuffle_ps(v83, v83, 0);
      v99 = v25;
      v85 = _mm_add_ps(v84, v81);
      v26 = v104;
      *((__m128 *)v8 - 1) = _mm_add_ps(v84, v82);
      *(__m128 *)v9 = v85;
      if ( v8 >= v93 )
        v8 = v95;
      v9 += 4;
      if ( v9 >= v92 )
        v9 = v89;
      --uValidFrames;
    }
    while ( uValidFrames );
    v86 = (float *)v36;
    v4 = this;
    v29 = v86;
  }
  v4->m_fFIRLPFMem = v25;
  v4->m_fDCFwdMem = v10;
  v4->m_fDCFbkMem = v11;
  v4->m_pfPreDelayRW = m_pfPreDelayRW;
  v4->m_pfDelayRead[0] = v12;
  v4->m_vIIRLPFMem[0] = v34;
  v4->m_vIIRLPFMem[1] = v32;
  v4->m_pfDelayWrite[0] = v8;
  v4->m_pfDelayWrite[1] = v9;
  v4->m_pfDelayRead[1] = v13;
  v4->m_pfDelayRead[2] = v14;
  v4->m_pfDelayRead[3] = v15;
  v4->m_pfDelayRead[4] = v16;
  v4->m_pfDelayRead[5] = v87;
  v4->m_pfDelayRead[6] = v28;
  v4->m_pfDelayRead[7] = v29;
}

// File Line: 1411
// RVA: 0xAC6400
void __fastcall CAkFDNReverbFX::ProcessFivePointZero12(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *m_pfPreDelayRW; // r14
  CAkFDNReverbFX *v4; // r10
  float *v5; // rbx
  float *v6; // rdi
  float *v7; // rsi
  float *v8; // r11
  float *v9; // r12
  float v11; // xmm8_4
  float v12; // xmm15_4
  CAkFDNReverbFXParams *m_pParams; // rdx
  unsigned int v14; // xmm3_4
  __m128 v15; // xmm0
  __m128 fDryLevel_low; // xmm1
  float *v17; // rax
  float v18; // xmm2_4
  __m128 fWetLevel_low; // xmm0
  __m128 v20; // xmm4
  __m128 v21; // xmm5
  float *v22; // r13
  float *v23; // rbp
  float *v24; // rdx
  float *v25; // r15
  __m128 v26; // xmm13
  __m128 v27; // xmm14
  float *v28; // r9
  float *v29; // rcx
  __m128 v30; // xmm0
  float *v31; // r8
  float *v32; // r10
  unsigned __int64 v33; // rax
  __m128 v34; // xmm7
  __m128 v35; // xmm9
  __m128 v36; // xmm10
  __m128 v37; // xmm11
  __m128 v38; // xmm12
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  __m128 v41; // xmm0
  __m128 v42; // xmm3
  float *v43; // r10
  __m128 v44; // xmm1
  __m128 v45; // xmm2
  float *v46; // rax
  __m128 v47; // xmm1
  __m128 v48; // xmm0
  __m128 v49; // xmm13
  __m128 v50; // xmm1
  bool v51; // cf
  __m128 v52; // xmm6
  __m128 v53; // xmm3
  __m128 v54; // xmm4
  __m128 v55; // xmm7
  __m128 v56; // xmm5
  __m128 v57; // xmm14
  float *v58; // rax
  __m128 v59; // xmm1
  __m128 v60; // xmm2
  __m128 v61; // xmm8
  __m128 v62; // xmm1
  __m128 v63; // xmm1
  __m128 v64; // xmm3
  __m128 v65; // xmm0
  __m128 v66; // xmm9
  __m128 v67; // xmm4
  __m128 v68; // xmm5
  __m128 v69; // xmm6
  __m128 v70; // xmm7
  __int64 uMaxFrames; // rcx
  float v72; // xmm12_4
  float v73; // xmm10_4
  __int64 v74; // rdx
  __int64 v75; // r8
  float v76; // xmm11_4
  __m128 v77; // xmm8
  float v78; // xmm9_4
  __int64 v79; // r9
  __m128 v80; // xmm2
  __m128 v81; // xmm2
  __m128 v82; // xmm2
  __m128 v83; // xmm3
  __m128 v84; // xmm3
  __m128 v85; // xmm4
  __m128 v86; // xmm4
  __m128 v87; // xmm5
  __m128 v88; // xmm5
  __m128 v89; // xmm6
  __m128 v90; // xmm6
  __m128 v91; // xmm0
  __m128 v92; // xmm1
  __m128 v93; // xmm0
  __m128 v94; // xmm0
  __m128 v95; // xmm7
  __m128 v96; // xmm7
  __m128 v97; // xmm4
  __m128 v98; // xmm2
  __m128 v99; // xmm1
  __m128 v100; // xmm5
  __m128 v101; // xmm6
  __m128 v102; // xmm4
  float v103; // xmm1_4
  __m128 v104; // xmm2
  __m128 v105; // xmm2
  __m128 v106; // xmm0
  __m128 v107; // xmm1
  __m128 v108; // xmm2
  float *v109; // [rsp+0h] [rbp-2A8h]
  float *v110; // [rsp+8h] [rbp-2A0h]
  __m128 v111; // [rsp+10h] [rbp-298h]
  float *v112; // [rsp+20h] [rbp-288h]
  float *v113; // [rsp+28h] [rbp-280h]
  float *v114; // [rsp+30h] [rbp-278h]
  float *v115; // [rsp+38h] [rbp-270h]
  float *v116; // [rsp+40h] [rbp-268h]
  float *v117; // [rsp+48h] [rbp-260h]
  float *pData; // [rsp+50h] [rbp-258h]
  float *v119; // [rsp+58h] [rbp-250h]
  float *v120; // [rsp+60h] [rbp-248h]
  float *v121; // [rsp+68h] [rbp-240h]
  float *v122; // [rsp+70h] [rbp-238h]
  float *v123; // [rsp+78h] [rbp-230h]
  __m128 v124; // [rsp+80h] [rbp-228h]
  __m128 v125; // [rsp+90h] [rbp-218h]
  float *m_pfPreDelayEnd; // [rsp+A0h] [rbp-208h]
  float *m_pfPreDelayStart; // [rsp+A8h] [rbp-200h]
  float v128; // [rsp+B0h] [rbp-1F8h]
  float v129; // [rsp+C0h] [rbp-1E8h]
  __m128 v130; // [rsp+D0h] [rbp-1D8h]
  float v131; // [rsp+E0h] [rbp-1C8h]
  __m128 v132; // [rsp+F0h] [rbp-1B8h]
  __m128 v133; // [rsp+100h] [rbp-1A8h]
  float v134; // [rsp+110h] [rbp-198h]
  __m128 v135; // [rsp+120h] [rbp-188h]
  __m128 v136; // [rsp+130h] [rbp-178h]
  float v137; // [rsp+140h] [rbp-168h]
  float v138; // [rsp+150h] [rbp-158h]
  __m128 v139; // [rsp+160h] [rbp-148h]
  __m128 v140; // [rsp+170h] [rbp-138h]
  __m128 v141; // [rsp+180h] [rbp-128h]
  __m128 v142; // [rsp+190h] [rbp-118h]
  __m128 v143; // [rsp+1A0h] [rbp-108h]
  __m128 v144; // [rsp+1B0h] [rbp-F8h]
  int uValidFrames; // [rsp+2C8h] [rbp+20h]

  v2 = (__m128)LODWORD(FLOAT_N2_0);
  m_pfPreDelayRW = this->m_pfPreDelayRW;
  v4 = this;
  v5 = this->m_pfDelayWrite[0];
  v6 = this->m_pfDelayWrite[1];
  v7 = this->m_pfDelayWrite[2];
  v136 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  v125 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  v8 = this->m_pfDelayRead[0];
  v9 = this->m_pfDelayRead[2];
  LODWORD(v11) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  LODWORD(v12) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  v128 = v11;
  m_pParams = this->m_pParams;
  v14 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFMem), (__m128)LODWORD(this->m_fFIRLPFMem), 0).m128_u32[0];
  LODWORD(v138) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  v129 = *(float *)&v14;
  LODWORD(v134) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  pData = (float *)io_pBuffer->pData;
  v123 = this->m_pfDelayStart[0];
  v2.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  v15 = v2;
  fDryLevel_low = (__m128)LODWORD(m_pParams->RTPC.fDryLevel);
  v132 = _mm_shuffle_ps(v15, v15, 0);
  v124 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  m_pfPreDelayStart = this->m_pfPreDelayStart;
  v120 = this->m_pfDelayEnd[0];
  v17 = this->m_pfDelayRead[1];
  v18 = 1.0 / (float)io_pBuffer->uMaxFrames;
  fDryLevel_low.m128_f32[0] = (float)(fDryLevel_low.m128_f32[0] - this->m_fCurrentDry) * v18;
  LODWORD(v137) = _mm_shuffle_ps(fDryLevel_low, fDryLevel_low, 0).m128_u32[0];
  fWetLevel_low = (__m128)LODWORD(m_pParams->RTPC.fWetLevel);
  v119 = this->m_pfDelayStart[2];
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  fWetLevel_low.m128_f32[0] = (float)(fWetLevel_low.m128_f32[0] - this->m_fCurrentWet) * v18;
  v116 = this->m_pfDelayStart[1];
  v121 = this->m_pfDelayEnd[2];
  LODWORD(v131) = _mm_shuffle_ps(fWetLevel_low, fWetLevel_low, 0).m128_u32[0];
  v122 = this->m_pfDelayEnd[1];
  v20 = this->m_vIIRLPFB0[0];
  v21 = this->m_vIIRLPFA1[0];
  v22 = this->m_pfDelayRead[3];
  v23 = this->m_pfDelayRead[4];
  v24 = this->m_pfDelayRead[7];
  v25 = this->m_pfDelayRead[8];
  v26 = this->m_vIIRLPFMem[0];
  v27 = this->m_vIIRLPFMem[1];
  v135 = this->m_vIIRLPFB0[1];
  v28 = this->m_pfDelayRead[10];
  v112 = this->m_pfDelayRead[9];
  v142 = v20;
  v144 = v21;
  v113 = this->m_pfDelayRead[11];
  v110 = this->m_pfDelayRead[5];
  v133 = this->m_vIIRLPFB0[2];
  v141 = this->m_vIIRLPFA1[1];
  v29 = this->m_pfDelayRead[6];
  v139 = v4->m_vIIRLPFA1[2];
  v30 = v4->m_vIIRLPFMem[2];
  uValidFrames = io_pBuffer->uValidFrames;
  v31 = v123;
  v111 = v30;
  if ( io_pBuffer->uValidFrames )
  {
    v32 = v17;
    v33 = (unsigned __int64)v120;
    v34 = vOutDecorrelationVectorD;
    v35 = vOutDecorrelationVectorB;
    v36 = vOutDecorrelationVectorC;
    v37 = vOutDecorrelationVectorA;
    v130 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorB);
    v38 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorD);
    v143 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorC);
    v140 = v38;
    do
    {
      v39 = (__m128)*(unsigned int *)v8;
      v40 = (__m128)*(unsigned int *)v32;
      v41 = (__m128)*(unsigned int *)v9;
      v8 += 4;
      if ( (unsigned __int64)v8 >= v33 )
        v8 = v31;
      v109 = v32 + 4;
      v42 = (__m128)*(unsigned int *)v22;
      if ( (unsigned __int64)(v32 + 4) >= v33 )
        v109 = v31 + 1;
      v9 += 4;
      if ( (unsigned __int64)v9 >= v33 )
        v9 = v31 + 2;
      v22 += 4;
      if ( (unsigned __int64)v22 >= v33 )
        v22 = v31 + 3;
      v43 = v110;
      v23 += 4;
      v44 = _mm_unpacklo_ps(v39, v40);
      v45 = (__m128)*(unsigned int *)v110;
      v46 = v116;
      v47 = _mm_mul_ps(_mm_movelh_ps(v44, _mm_unpacklo_ps(v41, v42)), v20);
      v48 = _mm_mul_ps(v26, v21);
      v49 = v47;
      v50 = (__m128)*((unsigned int *)v23 - 4);
      if ( v23 >= v122 )
        v23 = v116;
      v26 = _mm_add_ps(v49, v48);
      v110 += 4;
      v51 = v43 + 4 < v122;
      v32 = v109;
      v52 = _mm_mul_ps(v26, v34);
      v53 = _mm_mul_ps(v26, v37);
      v54 = _mm_mul_ps(v26, v35);
      v55 = _mm_mul_ps(v26, vOutDecorrelationVectorF);
      v56 = _mm_mul_ps(v26, v36);
      if ( !v51 )
      {
        v110 = v116 + 1;
        v32 = v109;
      }
      v114 = v29 + 4;
      if ( v29 + 4 >= v122 )
      {
        v114 = v116 + 2;
        v46 = v116;
      }
      v115 = v24 + 4;
      if ( v24 + 4 >= v122 )
        v115 = v46 + 3;
      v57 = _mm_mul_ps(v27, v141);
      v58 = v119;
      v25 += 4;
      v59 = _mm_unpacklo_ps(v50, v45);
      v60 = (__m128)*((unsigned int *)v25 - 4);
      v61 = (__m128)*(unsigned int *)v112;
      v62 = _mm_mul_ps(
              _mm_movelh_ps(v59, _mm_unpacklo_ps((__m128)*(unsigned int *)v29, (__m128)*(unsigned int *)v24)),
              v135);
      if ( v25 >= v121 )
        v25 = v119;
      v112 += 4;
      v27 = _mm_add_ps(v62, v57);
      v63 = _mm_add_ps(v27, v26);
      v64 = _mm_add_ps(v53, _mm_mul_ps(v27, v37));
      v65 = _mm_mul_ps(v27, v35);
      v66 = (__m128)*(unsigned int *)v113;
      v67 = _mm_add_ps(v54, v65);
      v68 = _mm_add_ps(v56, _mm_mul_ps(v27, v36));
      v69 = _mm_add_ps(v52, _mm_mul_ps(v27, vOutDecorrelationVectorE));
      v70 = _mm_add_ps(v55, _mm_mul_ps(v38, v27));
      if ( v112 >= v121 )
        v112 = v119 + 1;
      v117 = v28 + 4;
      if ( v28 + 4 >= v121 )
      {
        v117 = v119 + 2;
        v58 = v119;
      }
      v113 += 4;
      if ( v113 >= v121 )
        v113 = v58 + 3;
      uMaxFrames = io_pBuffer->uMaxFrames;
      v72 = *pData;
      v73 = pData[uMaxFrames];
      v74 = 2 * (int)uMaxFrames;
      v75 = 3 * (int)uMaxFrames;
      v76 = pData[v74];
      v77 = _mm_add_ps(
              _mm_mul_ps(
                _mm_movelh_ps(_mm_unpacklo_ps(v60, v61), _mm_unpacklo_ps((__m128)*(unsigned int *)v28, v66)),
                v133),
              _mm_mul_ps(v111, v139));
      v78 = pData[v75];
      v111 = v77;
      v79 = 4 * (int)uMaxFrames;
      v80 = v77;
      v77.m128_f32[0] = pData[v79];
      v81 = _mm_add_ps(_mm_mul_ps(v80, vOutDecorrelationVectorA), v64);
      v82 = _mm_add_ps(v81, _mm_movehl_ps(v81, v81));
      v83 = _mm_add_ps(_mm_mul_ps(v111, vOutDecorrelationVectorB), v67);
      v84 = _mm_add_ps(v83, _mm_movehl_ps(v83, v83));
      v85 = _mm_add_ps(_mm_mul_ps(v111, vOutDecorrelationVectorC), v68);
      v86 = _mm_add_ps(v85, _mm_movehl_ps(v85, v85));
      v87 = _mm_add_ps(_mm_mul_ps(v130, v111), v69);
      v88 = _mm_add_ps(v87, _mm_movehl_ps(v87, v87));
      v89 = _mm_add_ps(_mm_mul_ps(v143, v111), v70);
      v90 = _mm_add_ps(v89, _mm_movehl_ps(v89, v89));
      v91 = _mm_add_ps(v111, v63);
      v92 = _mm_add_ps(_mm_movehl_ps(v91, v91), v91);
      v93 = v124;
      v93.m128_f32[0] = v124.m128_f32[0] + v137;
      v124 = v93;
      v94 = v125;
      v95 = _mm_add_ps(_mm_shuffle_ps(v92, v92, 85), v92);
      v94.m128_f32[0] = v125.m128_f32[0] + v131;
      v125 = v94;
      *pData = (float)(*pData * v124.m128_f32[0])
             + (float)((float)(_mm_shuffle_ps(v82, v82, 85).m128_f32[0] + v82.m128_f32[0]) * v94.m128_f32[0]);
      v92.m128_f32[0] = _mm_shuffle_ps(v84, v84, 85).m128_f32[0] + v84.m128_f32[0];
      v84.m128_i32[0] = v94.m128_i32[0];
      ++pData;
      v96 = _mm_mul_ps(_mm_shuffle_ps(v95, v95, 0), v132);
      pData[uMaxFrames - 1] = (float)(v73 * v124.m128_f32[0]) + (float)(v92.m128_f32[0] * v94.m128_f32[0]);
      v94.m128_f32[0] = (float)(v76 * v124.m128_f32[0])
                      + (float)((float)(_mm_shuffle_ps(v86, v86, 85).m128_f32[0] + v86.m128_f32[0]) * v94.m128_f32[0]);
      v97 = _mm_add_ps(v96, v26);
      pData[v74 - 1] = v94.m128_f32[0];
      pData[v75 - 1] = (float)(v78 * v124.m128_f32[0])
                     + (float)((float)(_mm_shuffle_ps(v88, v88, 85).m128_f32[0] + v88.m128_f32[0]) * v84.m128_f32[0]);
      v94.m128_f32[0] = v77.m128_f32[0] * v124.m128_f32[0];
      v11 = (float)(v76 + v78) + (float)((float)(v72 + v73) + v77.m128_f32[0]);
      v98 = _mm_add_ps(v111, v96);
      pData[v79 - 1] = v94.m128_f32[0]
                     + (float)((float)(_mm_shuffle_ps(v90, v90, 85).m128_f32[0] + v90.m128_f32[0]) * v84.m128_f32[0]);
      v99 = _mm_add_ps(v27, v96);
      v100 = _mm_shuffle_ps(v98, _mm_shuffle_ps(v98, v97, 15), 201);
      v101 = _mm_shuffle_ps(v99, _mm_shuffle_ps(v99, v98, 15), 201);
      v102 = _mm_shuffle_ps(v97, _mm_shuffle_ps(v97, v99, 15), 201);
      v12 = (float)((float)(v134 * v12) + v11) - v128;
      v128 = v11;
      if ( m_pfPreDelayStart )
      {
        v103 = *m_pfPreDelayRW;
        *m_pfPreDelayRW++ = v12;
        if ( m_pfPreDelayRW == m_pfPreDelayEnd )
          m_pfPreDelayRW = m_pfPreDelayStart;
      }
      else
      {
        v103 = v12;
      }
      v104 = v136;
      v33 = (unsigned __int64)v120;
      v31 = v123;
      v29 = v114;
      v24 = v115;
      v35 = vOutDecorrelationVectorB;
      v36 = vOutDecorrelationVectorC;
      v37 = vOutDecorrelationVectorA;
      v28 = v117;
      v5 += 4;
      v104.m128_f32[0] = (float)(v136.m128_f32[0] * v103) + (float)(v138 * v129);
      v105 = _mm_shuffle_ps(v104, v104, 0);
      v38 = v140;
      v34 = vOutDecorrelationVectorD;
      v106 = _mm_add_ps(v105, v102);
      v20 = v142;
      *((__m128 *)v5 - 1) = v106;
      v14 = LODWORD(v103);
      if ( v5 >= v120 )
        v5 = v123;
      v6 += 4;
      v129 = v103;
      v107 = v105;
      v108 = _mm_add_ps(v105, v100);
      v21 = v144;
      *((__m128 *)v6 - 1) = _mm_add_ps(v107, v101);
      *(__m128 *)v7 = v108;
      if ( v6 >= v122 )
        v6 = v116;
      v7 += 4;
      if ( v7 >= v121 )
        v7 = v119;
      --uValidFrames;
    }
    while ( uValidFrames );
    v30 = v111;
    v4 = this;
    v17 = v109;
  }
  LODWORD(v4->m_fFIRLPFMem) = v14;
  v4->m_fDCFwdMem = v11;
  v4->m_fDCFbkMem = v12;
  v4->m_pfPreDelayRW = m_pfPreDelayRW;
  v4->m_pfDelayRead[1] = v17;
  v4->m_vIIRLPFMem[0] = v26;
  v4->m_pfDelayRead[5] = v110;
  v4->m_pfDelayWrite[0] = v5;
  v4->m_vIIRLPFMem[1] = v27;
  v4->m_vIIRLPFMem[2] = v30;
  v4->m_pfDelayRead[9] = v112;
  v4->m_pfDelayWrite[1] = v6;
  v4->m_pfDelayWrite[2] = v7;
  v4->m_pfDelayRead[0] = v8;
  v4->m_pfDelayRead[2] = v9;
  v4->m_pfDelayRead[11] = v113;
  v4->m_pfDelayRead[3] = v22;
  v4->m_pfDelayRead[4] = v23;
  v4->m_pfDelayRead[6] = v29;
  v4->m_pfDelayRead[7] = v24;
  v4->m_pfDelayRead[8] = v25;
  v4->m_pfDelayRead[10] = v28;
}

// File Line: 1458
// RVA: 0xAC6E40
void __fastcall CAkFDNReverbFX::ProcessFivePointZero16(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *m_pfPreDelayRW; // r15
  CAkFDNReverbFXParams *m_pParams; // rdx
  CAkFDNReverbFX *v6; // r10
  unsigned int v7; // xmm4_4
  float v8; // xmm8_4
  float v9; // xmm3_4
  __m128 v10; // xmm0
  __m128 fDryLevel_low; // xmm1
  float v12; // xmm2_4
  __m128 fWetLevel_low; // xmm0
  float *v14; // rax
  float *v15; // r13
  __m128 v16; // xmm5
  __m128 v17; // xmm6
  float *v18; // rbx
  float *v19; // rdi
  __m128 *v20; // rsi
  float *v21; // rbp
  __m128 v22; // xmm13
  __m128 v23; // xmm14
  __m128 v24; // xmm15
  float *v25; // r11
  float *v26; // rdx
  float *v27; // rcx
  float *v28; // r14
  float *v29; // r8
  float *v30; // r9
  float *v31; // r12
  __m128 v32; // xmm0
  float *v33; // r13
  __m128 v34; // xmm7
  float *v35; // r10
  float *v36; // rax
  __m128 v37; // xmm9
  __m128 v38; // xmm10
  __m128 v39; // xmm11
  __m128 v40; // xmm12
  __m128 v41; // xmm1
  __m128 v42; // xmm0
  float *v43; // rax
  __m128 v44; // xmm1
  __m128 v45; // xmm0
  __m128 v46; // xmm13
  __m128 v47; // xmm1
  __m128 v48; // xmm6
  __m128 v49; // xmm7
  __m128 v50; // xmm2
  __m128 v51; // xmm3
  __m128 v52; // xmm4
  __m128 v53; // xmm5
  __m128 v54; // xmm8
  __m128 v55; // xmm0
  __m128 v56; // xmm14
  __m128 v57; // xmm1
  __m128 v58; // xmm7
  __m128 v59; // xmm2
  __m128 v60; // xmm4
  __m128 v61; // xmm5
  __m128 v62; // xmm6
  __m128 v63; // xmm0
  __m128 v64; // xmm12
  __m128 v65; // xmm3
  __m128 v66; // xmm0
  __m128 v67; // xmm1
  __m128 v68; // xmm0
  __m128 v69; // xmm15
  __m128 v70; // xmm1
  __m128 v71; // xmm7
  __m128 v72; // xmm2
  __m128 v73; // xmm4
  __m128 v74; // xmm5
  __m128 v75; // xmm6
  __m128 v76; // xmm0
  __m128 v77; // xmm3
  __int64 uMaxFrames; // rcx
  float v79; // xmm12_4
  float v80; // xmm10_4
  __int64 v81; // rdx
  __int64 v82; // r8
  float v83; // xmm11_4
  float v84; // xmm9_4
  __int64 v85; // r9
  __m128 v86; // xmm7
  float v87; // xmm8_4
  __m128 v88; // xmm3
  __m128 v89; // xmm2
  __m128 v90; // xmm7
  __m128 v91; // xmm3
  __m128 v92; // xmm4
  __m128 v93; // xmm5
  __m128 v94; // xmm2
  __m128 v95; // xmm4
  __m128 v96; // xmm7
  __m128 v97; // xmm5
  __m128 v98; // xmm0
  __m128 v99; // xmm1
  __m128 v100; // xmm0
  __m128 v101; // xmm0
  __m128 v102; // xmm6
  __m128 v103; // xmm6
  __m128 v104; // xmm5
  __m128 v105; // xmm2
  __m128 v106; // xmm1
  __m128 v107; // xmm7
  __m128 v108; // xmm1
  __m128 v109; // xmm6
  __m128 v110; // xmm5
  float v111; // xmm1_4
  __m128 v112; // xmm2
  __m128 v113; // xmm2
  __m128 v114; // xmm0
  __m128 v115; // xmm1
  __m128 v116; // xmm0
  __m128 v117; // xmm2
  __m128 v118; // xmm1
  float *v119; // [rsp+0h] [rbp-348h]
  float *v120; // [rsp+8h] [rbp-340h]
  float *v121; // [rsp+10h] [rbp-338h]
  float *v122; // [rsp+18h] [rbp-330h]
  float *v123; // [rsp+20h] [rbp-328h]
  float *v124; // [rsp+28h] [rbp-320h]
  float *v125; // [rsp+30h] [rbp-318h]
  float *v126; // [rsp+38h] [rbp-310h]
  float *v127; // [rsp+40h] [rbp-308h]
  float *v128; // [rsp+48h] [rbp-300h]
  unsigned int *v129; // [rsp+50h] [rbp-2F8h]
  __m128 v130; // [rsp+60h] [rbp-2E8h]
  float *v131; // [rsp+60h] [rbp-2E8h]
  float *v132; // [rsp+70h] [rbp-2D8h]
  float *pData; // [rsp+78h] [rbp-2D0h]
  float *v134; // [rsp+80h] [rbp-2C8h]
  float *v135; // [rsp+88h] [rbp-2C0h]
  float *v136; // [rsp+90h] [rbp-2B8h]
  float *v137; // [rsp+98h] [rbp-2B0h]
  float *v138; // [rsp+A0h] [rbp-2A8h]
  float *v139; // [rsp+A8h] [rbp-2A0h]
  float *v140; // [rsp+B0h] [rbp-298h]
  __m128 v141; // [rsp+C0h] [rbp-288h]
  __m128 v142; // [rsp+D0h] [rbp-278h]
  __m128 v143; // [rsp+E0h] [rbp-268h]
  __m128 v144; // [rsp+F0h] [rbp-258h]
  __m128 v145; // [rsp+F0h] [rbp-258h]
  float *m_pfPreDelayStart; // [rsp+100h] [rbp-248h]
  float *m_pfPreDelayEnd; // [rsp+108h] [rbp-240h]
  float v148; // [rsp+110h] [rbp-238h]
  float v149; // [rsp+120h] [rbp-228h]
  float v150; // [rsp+130h] [rbp-218h]
  __m128 v151; // [rsp+140h] [rbp-208h]
  float v152; // [rsp+150h] [rbp-1F8h]
  __m128 v153; // [rsp+160h] [rbp-1E8h]
  float v154; // [rsp+170h] [rbp-1D8h]
  __m128 v155; // [rsp+180h] [rbp-1C8h]
  __m128 v156; // [rsp+190h] [rbp-1B8h]
  __m128 v157; // [rsp+1A0h] [rbp-1A8h]
  float v158; // [rsp+1B0h] [rbp-198h]
  __m128 v159; // [rsp+1C0h] [rbp-188h]
  float v160; // [rsp+1D0h] [rbp-178h]
  __m128 v161; // [rsp+1E0h] [rbp-168h]
  __m128 v162; // [rsp+1F0h] [rbp-158h]
  __m128 v163; // [rsp+200h] [rbp-148h]
  __m128 v164; // [rsp+210h] [rbp-138h]
  __m128 v165; // [rsp+220h] [rbp-128h]
  __m128 v166; // [rsp+230h] [rbp-118h]
  __m128 v167; // [rsp+240h] [rbp-108h]
  __m128 v168; // [rsp+250h] [rbp-F8h]
  int uValidFrames; // [rsp+368h] [rbp+20h]

  v2 = (__m128)LODWORD(FLOAT_N2_0);
  m_pfPreDelayRW = this->m_pfPreDelayRW;
  m_pParams = this->m_pParams;
  v6 = this;
  v162 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  v142 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  v7 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFMem), (__m128)LODWORD(this->m_fFIRLPFMem), 0).m128_u32[0];
  LODWORD(v8) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  LODWORD(v9) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  v149 = *(float *)&v7;
  v150 = v8;
  LODWORD(v160) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  v148 = v9;
  LODWORD(v158) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  pData = (float *)io_pBuffer->pData;
  v2.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  v10 = v2;
  fDryLevel_low = (__m128)LODWORD(m_pParams->RTPC.fDryLevel);
  v156 = _mm_shuffle_ps(v10, v10, 0);
  v143 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  m_pfPreDelayStart = this->m_pfPreDelayStart;
  v127 = this->m_pfDelayStart[0];
  v12 = 1.0 / (float)io_pBuffer->uMaxFrames;
  v121 = this->m_pfDelayEnd[0];
  fDryLevel_low.m128_f32[0] = (float)(fDryLevel_low.m128_f32[0] - this->m_fCurrentDry) * v12;
  LODWORD(v152) = _mm_shuffle_ps(fDryLevel_low, fDryLevel_low, 0).m128_u32[0];
  fWetLevel_low = (__m128)LODWORD(m_pParams->RTPC.fWetLevel);
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  v135 = this->m_pfDelayStart[1];
  v137 = this->m_pfDelayStart[2];
  fWetLevel_low.m128_f32[0] = (float)(fWetLevel_low.m128_f32[0] - this->m_fCurrentWet) * v12;
  LODWORD(v154) = _mm_shuffle_ps(fWetLevel_low, fWetLevel_low, 0).m128_u32[0];
  v140 = this->m_pfDelayStart[3];
  v136 = this->m_pfDelayEnd[1];
  v139 = this->m_pfDelayEnd[2];
  v138 = this->m_pfDelayEnd[3];
  v14 = this->m_pfDelayRead[2];
  v15 = this->m_pfDelayRead[10];
  v16 = this->m_vIIRLPFB0[0];
  v17 = this->m_vIIRLPFA1[0];
  v18 = this->m_pfDelayWrite[0];
  v19 = this->m_pfDelayWrite[1];
  v20 = (__m128 *)this->m_pfDelayWrite[2];
  v21 = this->m_pfDelayWrite[3];
  v22 = this->m_vIIRLPFMem[0];
  v23 = this->m_vIIRLPFMem[1];
  v24 = this->m_vIIRLPFMem[2];
  v25 = this->m_pfDelayRead[0];
  v26 = this->m_pfDelayRead[1];
  v27 = this->m_pfDelayRead[3];
  v165 = v6->m_vIIRLPFB0[1];
  v166 = v16;
  v28 = v6->m_pfDelayRead[4];
  v29 = v6->m_pfDelayRead[6];
  v30 = v6->m_pfDelayRead[7];
  v153 = v6->m_vIIRLPFB0[2];
  v168 = v17;
  v31 = v6->m_pfDelayRead[8];
  v157 = v6->m_vIIRLPFB0[3];
  v167 = v6->m_vIIRLPFA1[1];
  v125 = v6->m_pfDelayRead[5];
  v120 = v15;
  v161 = v6->m_vIIRLPFA1[2];
  v119 = v6->m_pfDelayRead[9];
  v163 = v6->m_vIIRLPFA1[3];
  v32 = v6->m_vIIRLPFMem[3];
  v141 = v32;
  v124 = v6->m_pfDelayRead[13];
  v122 = v6->m_pfDelayRead[11];
  v33 = v6->m_pfDelayRead[12];
  v126 = v6->m_pfDelayRead[14];
  v123 = v6->m_pfDelayRead[15];
  uValidFrames = io_pBuffer->uValidFrames;
  if ( io_pBuffer->uValidFrames )
  {
    v34 = vOutDecorrelationVectorD;
    v35 = v14;
    v36 = v127;
    v37 = vOutDecorrelationVectorB;
    v38 = vOutDecorrelationVectorC;
    v39 = vOutDecorrelationVectorA;
    v155 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorB);
    v40 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorD);
    v159 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorA);
    v151 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorC);
    v164 = v40;
    do
    {
      v41 = (__m128)*(unsigned int *)v25;
      v42 = (__m128)*(unsigned int *)v35;
      v25 += 4;
      if ( v25 >= v121 )
        v25 = v36;
      v132 = v26 + 4;
      if ( v26 + 4 >= v121 )
      {
        v132 = v36 + 1;
        v36 = v127;
      }
      v35 += 4;
      if ( v35 >= v121 )
        v35 = v36 + 2;
      v134 = v27 + 4;
      if ( v27 + 4 >= v121 )
        v134 = v36 + 3;
      v43 = v135;
      v44 = _mm_mul_ps(
              _mm_movelh_ps(
                _mm_unpacklo_ps(v41, (__m128)*(unsigned int *)v26),
                _mm_unpacklo_ps(v42, (__m128)*(unsigned int *)v27)),
              v16);
      v28 += 4;
      v45 = _mm_mul_ps(v22, v17);
      v46 = v44;
      v47 = (__m128)*((unsigned int *)v28 - 4);
      v22 = _mm_add_ps(v46, v45);
      if ( v28 >= v136 )
        v28 = v135;
      v125 += 4;
      v48 = _mm_mul_ps(v22, v34);
      v49 = (__m128)*((unsigned int *)v125 - 4);
      v50 = _mm_mul_ps(v22, v39);
      v51 = _mm_mul_ps(v22, vOutDecorrelationVectorF);
      v52 = _mm_mul_ps(v22, v37);
      v53 = _mm_mul_ps(v22, v38);
      if ( v125 >= v136 )
        v125 = v135 + 1;
      v128 = v29 + 4;
      if ( v29 + 4 >= v136 )
      {
        v128 = v135 + 2;
        v43 = v135;
      }
      v129 = (unsigned int *)(v30 + 4);
      if ( v30 + 4 >= v136 )
        v129 = (unsigned int *)(v43 + 3);
      v54 = (__m128)*(unsigned int *)v119;
      v55 = _mm_mul_ps(v23, v167);
      v31 += 4;
      v56 = _mm_mul_ps(
              _mm_movelh_ps(
                _mm_unpacklo_ps(v47, v49),
                _mm_unpacklo_ps((__m128)*(unsigned int *)v29, (__m128)*(unsigned int *)v30)),
              v165);
      v57 = (__m128)*((unsigned int *)v31 - 4);
      if ( v31 >= v139 )
        v31 = v137;
      v23 = _mm_add_ps(v56, v55);
      v119 += 4;
      v58 = _mm_add_ps(v23, v22);
      v59 = _mm_add_ps(v50, _mm_mul_ps(v23, v39));
      v60 = _mm_add_ps(v52, _mm_mul_ps(v23, v37));
      v61 = _mm_add_ps(v53, _mm_mul_ps(v23, v38));
      v62 = _mm_add_ps(v48, _mm_mul_ps(v23, vOutDecorrelationVectorE));
      v63 = v40;
      v64 = (__m128)*(unsigned int *)v122;
      v65 = _mm_add_ps(v51, _mm_mul_ps(v63, v23));
      v66 = (__m128)*(unsigned int *)v120;
      if ( v119 >= v139 )
        v119 = v137 + 1;
      v120 += 4;
      if ( v120 >= v139 )
        v120 = v137 + 2;
      v122 += 4;
      if ( v122 >= v139 )
        v122 = v137 + 3;
      v67 = _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v57, v54), _mm_unpacklo_ps(v66, v64)), v153);
      v68 = _mm_mul_ps(v24, v161);
      v33 += 4;
      v69 = v67;
      v70 = (__m128)*((unsigned int *)v33 - 4);
      if ( v33 >= v138 )
        v33 = v140;
      v24 = _mm_add_ps(v69, v68);
      v124 += 4;
      v144 = _mm_add_ps(v58, v24);
      v71 = (__m128)*(unsigned int *)v123;
      v72 = _mm_add_ps(v59, _mm_mul_ps(v24, v39));
      v73 = _mm_add_ps(v60, _mm_mul_ps(v24, v37));
      v74 = _mm_add_ps(v61, _mm_mul_ps(v24, v38));
      v75 = _mm_add_ps(v62, _mm_mul_ps(v155, v24));
      v76 = (__m128)*(unsigned int *)v126;
      v130 = _mm_add_ps(v65, _mm_mul_ps(v151, v24));
      v77 = (__m128)*((unsigned int *)v124 - 4);
      if ( v124 >= v138 )
        v124 = v140 + 1;
      v126 += 4;
      if ( v126 >= v138 )
        v126 = v140 + 2;
      v123 += 4;
      if ( v123 >= v138 )
        v123 = v140 + 3;
      uMaxFrames = io_pBuffer->uMaxFrames;
      v79 = *pData;
      v80 = pData[uMaxFrames];
      v81 = 2 * (int)uMaxFrames;
      v82 = 3 * (int)uMaxFrames;
      v83 = pData[v81];
      v84 = pData[v82];
      v141 = _mm_add_ps(
               _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v70, v77), _mm_unpacklo_ps(v76, v71)), v157),
               _mm_mul_ps(v141, v163));
      v85 = 4 * (int)uMaxFrames;
      v86 = _mm_mul_ps(v141, vOutDecorrelationVectorB);
      v87 = pData[v85];
      v88 = _mm_add_ps(_mm_mul_ps(v141, vOutDecorrelationVectorA), v72);
      v89 = _mm_add_ps(v86, v73);
      v90 = _mm_add_ps(v86, v75);
      v91 = _mm_add_ps(v88, _mm_movehl_ps(v88, v88));
      v92 = _mm_add_ps(_mm_mul_ps(v141, vOutDecorrelationVectorC), v74);
      v93 = _mm_add_ps(_mm_mul_ps(v159, v141), v130);
      v94 = _mm_add_ps(v89, _mm_movehl_ps(v89, v89));
      v95 = _mm_add_ps(v92, _mm_movehl_ps(v92, v92));
      v96 = _mm_add_ps(v90, _mm_movehl_ps(v90, v90));
      v97 = _mm_add_ps(v93, _mm_movehl_ps(v93, v93));
      v98 = _mm_add_ps(v141, v144);
      v99 = _mm_add_ps(_mm_movehl_ps(v98, v98), v98);
      v100 = v143;
      v100.m128_f32[0] = v143.m128_f32[0] + v152;
      v143 = v100;
      v101 = v142;
      v102 = _mm_add_ps(_mm_shuffle_ps(v99, v99, 85), v99);
      v101.m128_f32[0] = v142.m128_f32[0] + v154;
      v142 = v101;
      *pData = (float)(*pData * v143.m128_f32[0])
             + (float)((float)(_mm_shuffle_ps(v91, v91, 85).m128_f32[0] + v91.m128_f32[0]) * v101.m128_f32[0]);
      v99.m128_f32[0] = _mm_shuffle_ps(v94, v94, 85).m128_f32[0] + v94.m128_f32[0];
      v94.m128_i32[0] = v101.m128_i32[0];
      ++pData;
      v103 = _mm_mul_ps(_mm_shuffle_ps(v102, v102, 0), v156);
      pData[uMaxFrames - 1] = (float)(v80 * v143.m128_f32[0]) + (float)(v99.m128_f32[0] * v101.m128_f32[0]);
      pData[v81 - 1] = (float)(v83 * v143.m128_f32[0])
                     + (float)((float)(_mm_shuffle_ps(v95, v95, 85).m128_f32[0] + v95.m128_f32[0]) * v101.m128_f32[0]);
      pData[v82 - 1] = (float)(v84 * v143.m128_f32[0])
                     + (float)((float)(_mm_shuffle_ps(v96, v96, 85).m128_f32[0] + v96.m128_f32[0]) * v101.m128_f32[0]);
      v99.m128_f32[0] = _mm_shuffle_ps(v97, v97, 85).m128_f32[0] + v97.m128_f32[0];
      v101.m128_f32[0] = v87 * v143.m128_f32[0];
      v8 = (float)(v83 + v84) + (float)((float)(v79 + v80) + v87);
      v104 = _mm_add_ps(v103, v22);
      v101.m128_f32[0] = v101.m128_f32[0] + (float)(v99.m128_f32[0] * v94.m128_f32[0]);
      v105 = _mm_add_ps(v24, v103);
      pData[v85 - 1] = v101.m128_f32[0];
      v106 = _mm_add_ps(v141, v103);
      v107 = _mm_shuffle_ps(v106, _mm_shuffle_ps(v106, v104, 15), 201);
      v145 = _mm_shuffle_ps(v105, _mm_shuffle_ps(v105, v106, 15), 201);
      v108 = _mm_add_ps(v23, v103);
      v109 = _mm_shuffle_ps(v108, _mm_shuffle_ps(v108, v105, 15), 201);
      v110 = _mm_shuffle_ps(v104, _mm_shuffle_ps(v104, v108, 15), 201);
      v9 = (float)((float)(v158 * v148) + v8) - v150;
      v150 = v8;
      v148 = v9;
      if ( m_pfPreDelayStart )
      {
        v111 = *m_pfPreDelayRW;
        *m_pfPreDelayRW++ = v9;
        if ( m_pfPreDelayRW == m_pfPreDelayEnd )
          m_pfPreDelayRW = m_pfPreDelayStart;
      }
      else
      {
        v111 = v9;
      }
      v112 = v162;
      v36 = v127;
      v27 = v134;
      v26 = v132;
      v29 = v128;
      v37 = vOutDecorrelationVectorB;
      v38 = vOutDecorrelationVectorC;
      v39 = vOutDecorrelationVectorA;
      v30 = (float *)v129;
      v18 += 4;
      v112.m128_f32[0] = (float)(v162.m128_f32[0] * v111) + (float)(v160 * v149);
      v113 = _mm_shuffle_ps(v112, v112, 0);
      v40 = v164;
      v7 = LODWORD(v111);
      v114 = _mm_add_ps(v113, v110);
      v16 = v166;
      *((__m128 *)v18 - 1) = v114;
      v149 = v111;
      if ( v18 >= v121 )
        v18 = v127;
      v19 += 4;
      v115 = v113;
      v116 = v113;
      v117 = _mm_add_ps(v113, v107);
      v34 = vOutDecorrelationVectorD;
      v118 = _mm_add_ps(v115, v109);
      v17 = v168;
      *((__m128 *)v19 - 1) = v118;
      *v20 = _mm_add_ps(v116, v145);
      *(__m128 *)v21 = v117;
      if ( v19 >= v136 )
        v19 = v135;
      if ( ++v20 >= (__m128 *)v139 )
        v20 = (__m128 *)v137;
      v21 += 4;
      if ( v21 >= v138 )
        v21 = v140;
      --uValidFrames;
    }
    while ( uValidFrames );
    v32 = v141;
    v131 = v35;
    v6 = this;
    v14 = v131;
  }
  LODWORD(v6->m_fFIRLPFMem) = v7;
  v6->m_fDCFwdMem = v8;
  v6->m_fDCFbkMem = v9;
  v6->m_pfPreDelayRW = m_pfPreDelayRW;
  v6->m_pfDelayRead[2] = v14;
  v6->m_vIIRLPFMem[0] = v22;
  v6->m_vIIRLPFMem[1] = v23;
  v6->m_vIIRLPFMem[2] = v24;
  v6->m_pfDelayRead[5] = v125;
  v6->m_pfDelayRead[0] = v25;
  v6->m_vIIRLPFMem[3] = v32;
  v6->m_pfDelayRead[9] = v119;
  v6->m_pfDelayRead[10] = v120;
  v6->m_pfDelayWrite[0] = v18;
  v6->m_pfDelayRead[11] = v122;
  v6->m_pfDelayWrite[1] = v19;
  v6->m_pfDelayRead[13] = v124;
  v6->m_pfDelayWrite[2] = (float *)v20;
  v6->m_pfDelayRead[14] = v126;
  v6->m_pfDelayWrite[3] = v21;
  v6->m_pfDelayRead[1] = v26;
  v6->m_pfDelayRead[3] = v27;
  v6->m_pfDelayRead[4] = v28;
  v6->m_pfDelayRead[15] = v123;
  v6->m_pfDelayRead[6] = v29;
  v6->m_pfDelayRead[7] = v30;
  v6->m_pfDelayRead[8] = v31;
  v6->m_pfDelayRead[12] = v33;
}

// File Line: 1513
// RVA: 0xAC7AB0
void __fastcall CAkFDNReverbFX::ProcessFivePointOne4(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *m_pfPreDelayRW; // rsi
  CAkFDNReverbFX *v4; // r11
  AkAudioBuffer *v5; // r8
  CAkFDNReverbFXParams *m_pParams; // rdx
  __m128 v7; // xmm5
  __m128 v8; // xmm7
  __m128 v9; // xmm6
  float *v10; // r13
  float *v11; // r12
  float v12; // xmm4_4
  float *v13; // rbx
  float *v14; // rdi
  float v15; // xmm15_4
  float v16; // xmm14_4
  float *v17; // r15
  float *v18; // rbp
  float *v19; // r14
  __m128 v20; // xmm0
  __m128 fDryLevel_low; // xmm1
  float v22; // xmm2_4
  __m128 fWetLevel_low; // xmm0
  float *m_pfPreDelayStart; // r11
  float *v25; // rax
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  __m128 v28; // xmm0
  __m128 v29; // xmm3
  float v30; // xmm13_4
  __int64 uMaxFrames; // rcx
  float v32; // xmm11_4
  __int64 v33; // rdx
  __int64 v34; // r8
  float v35; // xmm12_4
  __int64 v36; // r9
  float v37; // xmm9_4
  __m128 v38; // xmm6
  float v39; // xmm10_4
  __int64 v40; // r10
  __m128 v41; // xmm7
  __m128 v42; // xmm3
  __m128 v43; // xmm4
  float v44; // xmm8_4
  __m128 v45; // xmm1
  __m128 v46; // xmm3
  __m128 v47; // xmm5
  __m128 v48; // xmm6
  __m128 v49; // xmm2
  __m128 v50; // xmm4
  __m128 v51; // xmm5
  __m128 v52; // xmm6
  __m128 v53; // xmm0
  __m128 v54; // xmm1
  __m128 v55; // xmm0
  __m128 v56; // xmm0
  __m128 v57; // xmm3
  __m128 v58; // xmm3
  float v59; // xmm2_4
  __m128 v60; // xmm1
  float *pData; // [rsp+0h] [rbp-1D8h]
  __m128 v62; // [rsp+10h] [rbp-1C8h]
  float *m_pfPreDelayEnd; // [rsp+20h] [rbp-1B8h]
  __m128 v64; // [rsp+30h] [rbp-1A8h]
  __m128 v65; // [rsp+40h] [rbp-198h]
  float v66; // [rsp+50h] [rbp-188h]
  float v67; // [rsp+60h] [rbp-178h]
  float v68; // [rsp+70h] [rbp-168h]
  __m128 v69; // [rsp+80h] [rbp-158h]
  __m128 v70; // [rsp+90h] [rbp-148h]
  float v71; // [rsp+A0h] [rbp-138h]
  float v72; // [rsp+B0h] [rbp-128h]
  __m128 v73; // [rsp+C0h] [rbp-118h]
  __m128 v74; // [rsp+D0h] [rbp-108h]
  __m128 v75; // [rsp+E0h] [rbp-F8h]
  bool v78; // [rsp+1F0h] [rbp+18h]
  int uValidFrames; // [rsp+1F8h] [rbp+20h]

  v2 = (__m128)LODWORD(FLOAT_N2_0);
  m_pfPreDelayRW = this->m_pfPreDelayRW;
  v4 = this;
  v5 = io_pBuffer;
  m_pParams = this->m_pParams;
  v7 = this->m_vIIRLPFB0[0];
  v8 = this->m_vIIRLPFA1[0];
  v9 = this->m_vIIRLPFMem[0];
  v10 = this->m_pfDelayStart[0];
  v11 = this->m_pfDelayEnd[0];
  LODWORD(v12) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  v69 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  v13 = this->m_pfDelayWrite[0];
  v14 = this->m_pfDelayRead[0];
  LODWORD(v15) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFMem), (__m128)LODWORD(this->m_fFIRLPFMem), 0).m128_u32[0];
  LODWORD(v16) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  LODWORD(v71) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  v64 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  v17 = this->m_pfDelayRead[1];
  v18 = this->m_pfDelayRead[2];
  v66 = v12;
  v73 = v7;
  v75 = v8;
  v19 = this->m_pfDelayRead[3];
  pData = (float *)v5->pData;
  LODWORD(v68) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  v2.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  v20 = v2;
  fDryLevel_low = (__m128)LODWORD(m_pParams->RTPC.fDryLevel);
  v74 = _mm_shuffle_ps(v20, v20, 0);
  v65 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  v78 = this->m_pfPreDelayStart != 0i64;
  uValidFrames = v5->uValidFrames;
  v22 = 1.0 / (float)v5->uMaxFrames;
  fDryLevel_low.m128_f32[0] = (float)(fDryLevel_low.m128_f32[0] - this->m_fCurrentDry) * v22;
  LODWORD(v72) = _mm_shuffle_ps(fDryLevel_low, fDryLevel_low, 0).m128_u32[0];
  fWetLevel_low = (__m128)LODWORD(m_pParams->RTPC.fWetLevel);
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  fWetLevel_low.m128_f32[0] = (float)(fWetLevel_low.m128_f32[0] - this->m_fCurrentWet) * v22;
  LODWORD(v67) = _mm_shuffle_ps(fWetLevel_low, fWetLevel_low, 0).m128_u32[0];
  if ( v5->uValidFrames )
  {
    m_pfPreDelayStart = this->m_pfPreDelayStart;
    v25 = (float *)v5->pData;
    do
    {
      v26 = (__m128)*(unsigned int *)v14;
      v27 = (__m128)*(unsigned int *)v17;
      v28 = (__m128)*(unsigned int *)v18;
      v14 += 4;
      if ( v14 >= v11 )
        v14 = v10;
      v17 += 4;
      v29 = (__m128)*(unsigned int *)v19;
      if ( v17 >= v11 )
        v17 = v10 + 1;
      v18 += 4;
      if ( v18 >= v11 )
        v18 = v10 + 2;
      v19 += 4;
      if ( v19 >= v11 )
        v19 = v10 + 3;
      v30 = *v25;
      uMaxFrames = v5->uMaxFrames;
      v32 = v25[uMaxFrames];
      v33 = 2 * (int)uMaxFrames;
      v34 = 5 * (int)uMaxFrames;
      v35 = pData[v33];
      v36 = 3 * (int)uMaxFrames;
      v37 = pData[v34];
      v38 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v26, v27), _mm_unpacklo_ps(v28, v29)), v7),
              _mm_mul_ps(v9, v8));
      v39 = pData[v36];
      v40 = 4 * (int)uMaxFrames;
      v41 = _mm_mul_ps(v38, vOutDecorrelationVectorB);
      v42 = _mm_mul_ps(v38, vOutDecorrelationVectorA);
      v43 = _mm_mul_ps(v38, vOutDecorrelationVectorC);
      v62 = v38;
      v44 = pData[v40];
      v45 = v38;
      v46 = _mm_add_ps(v42, _mm_movehl_ps(v42, v42));
      v47 = _mm_mul_ps(v38, vOutDecorrelationVectorD);
      v48 = _mm_mul_ps(v38, vOutDecorrelationVectorF);
      v49 = _mm_add_ps(v41, _mm_movehl_ps(v41, v41));
      v50 = _mm_add_ps(v43, _mm_movehl_ps(v43, v43));
      v51 = _mm_add_ps(v47, _mm_movehl_ps(v47, v47));
      v52 = _mm_add_ps(v48, _mm_movehl_ps(v48, v48));
      v53 = _mm_add_ps(_mm_movehl_ps(v45, v45), v45);
      v54 = _mm_add_ps(_mm_shuffle_ps(v53, v53, 85), v53);
      v55 = v65;
      v55.m128_f32[0] = v65.m128_f32[0] + v72;
      v70 = v54;
      v65 = v55;
      v56 = v64;
      v56.m128_f32[0] = v64.m128_f32[0] + v67;
      v64 = v56;
      *pData = (float)(*v25 * v65.m128_f32[0])
             + (float)((float)(_mm_shuffle_ps(v46, v46, 85).m128_f32[0] + v46.m128_f32[0]) * v56.m128_f32[0]);
      v25 = pData + 1;
      pData = v25;
      v25[uMaxFrames - 1] = (float)(v32 * v65.m128_f32[0])
                          + (float)((float)(_mm_shuffle_ps(v49, v49, 85).m128_f32[0] + v49.m128_f32[0]) * v56.m128_f32[0]);
      v25[v33 - 1] = (float)(v35 * v65.m128_f32[0])
                   + (float)((float)(_mm_shuffle_ps(v50, v50, 85).m128_f32[0] + v50.m128_f32[0]) * v56.m128_f32[0]);
      v12 = (float)((float)(v35 + v37) + v44) + (float)((float)(v30 + v32) + v39);
      v25[v34 - 1] = (float)(v37 * v65.m128_f32[0])
                   + (float)((float)(_mm_shuffle_ps(v49, v49, 85).m128_f32[0] + v49.m128_f32[0]) * v56.m128_f32[0]);
      v25[v36 - 1] = (float)(v39 * v65.m128_f32[0])
                   + (float)((float)(_mm_shuffle_ps(v51, v51, 85).m128_f32[0] + v51.m128_f32[0]) * v56.m128_f32[0]);
      v54.m128_f32[0] = _mm_shuffle_ps(v52, v52, 85).m128_f32[0] + v52.m128_f32[0];
      v9 = v62;
      v25[v40 - 1] = (float)(v44 * v65.m128_f32[0]) + (float)(v54.m128_f32[0] * v56.m128_f32[0]);
      v57 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v70, v70, 0), v74), v62);
      v58 = _mm_shuffle_ps(v57, _mm_shuffle_ps(v57, v57, 15), 201);
      v16 = (float)((float)(v68 * v16) + v12) - v66;
      v66 = v12;
      if ( v78 )
      {
        v59 = *m_pfPreDelayRW;
        *m_pfPreDelayRW++ = v16;
        if ( m_pfPreDelayRW == m_pfPreDelayEnd )
          m_pfPreDelayRW = m_pfPreDelayStart;
      }
      else
      {
        v59 = v16;
      }
      v60 = v69;
      v7 = v73;
      v5 = io_pBuffer;
      v13 += 4;
      v60.m128_f32[0] = (float)(v69.m128_f32[0] * v59) + (float)(v71 * v15);
      v8 = v75;
      v15 = v59;
      *((__m128 *)v13 - 1) = _mm_add_ps(_mm_shuffle_ps(v60, v60, 0), v58);
      if ( v13 >= v11 )
        v13 = v10;
      --uValidFrames;
    }
    while ( uValidFrames );
    v4 = this;
  }
  v4->m_fFIRLPFMem = v15;
  v4->m_fDCFwdMem = v12;
  v4->m_fDCFbkMem = v16;
  v4->m_pfPreDelayRW = m_pfPreDelayRW;
  v4->m_vIIRLPFMem[0] = v9;
  v4->m_pfDelayWrite[0] = v13;
  v4->m_pfDelayRead[0] = v14;
  v4->m_pfDelayRead[1] = v17;
  v4->m_pfDelayRead[2] = v18;
  v4->m_pfDelayRead[3] = v19;
}

// File Line: 1545
// RVA: 0xAC8090
void __fastcall CAkFDNReverbFX::ProcessFivePointOne8(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *m_pfPreDelayRW; // r14
  CAkFDNReverbFX *v4; // r11
  float *v5; // r9
  float *v6; // r10
  float *v7; // rdi
  float *v8; // rsi
  float *v9; // rbx
  float *v10; // r13
  float v11; // xmm7_4
  float v12; // xmm3_4
  float *v13; // r15
  float *v14; // r12
  float *v15; // rbp
  CAkFDNReverbFXParams *m_pParams; // rdx
  unsigned int uMaxFrames; // eax
  float *v19; // r8
  __m128 v20; // xmm0
  __m128 fDryLevel_low; // xmm1
  __m128i v22; // xmm0
  float *v23; // rax
  float v24; // xmm2_4
  __m128 fWetLevel_low; // xmm0
  float *v26; // rdx
  float v27; // xmm2_4
  __m128 v28; // xmm5
  __m128 v29; // xmm9
  float *v30; // rcx
  float *v31; // rax
  __m128 v32; // xmm8
  __m128 v33; // xmm10
  __m128 v34; // xmm0
  __m128 v35; // xmm15
  __m128 v36; // xmm4
  unsigned int *v37; // r11
  __m128 v38; // xmm6
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  __m128 v41; // xmm0
  __m128 v42; // xmm3
  __m128 v43; // xmm0
  __m128 v44; // xmm1
  __m128 v45; // xmm2
  __m128 v46; // xmm15
  __m128 v47; // xmm8
  __m128 v48; // xmm3
  __m128 v49; // xmm7
  __m128 v50; // xmm6
  __m128 v51; // xmm0
  __m128 v52; // xmm5
  __m128 v53; // xmm1
  __int64 v54; // rcx
  float v55; // xmm14_4
  float v56; // xmm12_4
  __int64 v57; // rdx
  __int64 v58; // r8
  __m128 v59; // xmm6
  float v60; // xmm13_4
  __int64 v61; // r9
  float v62; // xmm10_4
  float v63; // xmm11_4
  __int64 v64; // r10
  __m128 v65; // xmm8
  float v66; // xmm9_4
  __m128 v67; // xmm2
  __m128 v68; // xmm2
  __m128 v69; // xmm3
  __m128 v70; // xmm3
  __m128 v71; // xmm4
  __m128 v72; // xmm4
  __m128 v73; // xmm5
  __m128 v74; // xmm5
  __m128 v75; // xmm6
  __m128 v76; // xmm6
  __m128 v77; // xmm8
  __m128 v78; // xmm0
  __m128 v79; // xmm1
  __m128 v80; // xmm0
  __m128 v81; // xmm0
  __m128 v82; // xmm7
  __m128 v83; // xmm7
  __m128 v84; // xmm4
  __m128 v85; // xmm1
  __m128 v86; // xmm5
  __m128 v87; // xmm4
  __m128 v88; // xmm1
  __m128 v89; // xmm0
  __m128 v90; // xmm1
  __m128 v91; // xmm0
  float *v92; // [rsp+0h] [rbp-278h]
  float *pData; // [rsp+8h] [rbp-270h]
  float *v94; // [rsp+10h] [rbp-268h]
  __m128 v95; // [rsp+20h] [rbp-258h]
  float *v96; // [rsp+20h] [rbp-258h]
  float *v97; // [rsp+30h] [rbp-248h]
  __m128 v98; // [rsp+40h] [rbp-238h]
  float *m_pfPreDelayStart; // [rsp+50h] [rbp-228h]
  float *v100; // [rsp+58h] [rbp-220h]
  float *m_pfPreDelayEnd; // [rsp+60h] [rbp-218h]
  float *v102; // [rsp+68h] [rbp-210h]
  __m128 v103; // [rsp+70h] [rbp-208h]
  float *v104; // [rsp+80h] [rbp-1F8h]
  __m128 v105; // [rsp+90h] [rbp-1E8h]
  float v106; // [rsp+A0h] [rbp-1D8h]
  float v107; // [rsp+B0h] [rbp-1C8h]
  float v108; // [rsp+C0h] [rbp-1B8h]
  __m128 v109; // [rsp+D0h] [rbp-1A8h]
  __m128 v110; // [rsp+E0h] [rbp-198h]
  __m128 v111; // [rsp+F0h] [rbp-188h]
  float v112; // [rsp+100h] [rbp-178h]
  float v113; // [rsp+110h] [rbp-168h]
  __m128 v114; // [rsp+120h] [rbp-158h]
  float v115; // [rsp+130h] [rbp-148h]
  __m128 v116; // [rsp+140h] [rbp-138h]
  __m128 v117; // [rsp+150h] [rbp-128h]
  __m128 v118; // [rsp+160h] [rbp-118h]
  float v119; // [rsp+170h] [rbp-108h]
  __m128 v120; // [rsp+180h] [rbp-F8h]
  int uValidFrames; // [rsp+298h] [rbp+20h]

  v2 = (__m128)LODWORD(FLOAT_N2_0);
  m_pfPreDelayRW = this->m_pfPreDelayRW;
  v4 = this;
  v5 = this->m_pfDelayStart[1];
  v6 = this->m_pfDelayEnd[1];
  v7 = this->m_pfDelayWrite[0];
  v110 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  v8 = this->m_pfDelayWrite[1];
  v9 = this->m_pfDelayRead[0];
  v10 = this->m_pfDelayRead[1];
  LODWORD(v11) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  v105 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  v107 = v11;
  LODWORD(v12) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  v13 = this->m_pfDelayRead[2];
  v14 = this->m_pfDelayRead[3];
  v15 = this->m_pfDelayRead[4];
  LODWORD(v112) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  v106 = v12;
  LODWORD(v115) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  m_pParams = this->m_pParams;
  v97 = v5;
  v100 = v6;
  pData = (float *)io_pBuffer->pData;
  uMaxFrames = io_pBuffer->uMaxFrames;
  v19 = this->m_pfDelayEnd[0];
  v104 = v19;
  v2.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  v20 = v2;
  fDryLevel_low = (__m128)LODWORD(m_pParams->RTPC.fDryLevel);
  v109 = _mm_shuffle_ps(v20, v20, 0);
  v103 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  v22 = _mm_cvtsi32_si128(uMaxFrames);
  m_pfPreDelayStart = this->m_pfPreDelayStart;
  v23 = this->m_pfDelayRead[5];
  v24 = 1.0 / _mm_cvtepi32_ps(v22).m128_f32[0];
  fDryLevel_low.m128_f32[0] = (float)(fDryLevel_low.m128_f32[0] - this->m_fCurrentDry) * v24;
  LODWORD(v119) = _mm_shuffle_ps(fDryLevel_low, fDryLevel_low, 0).m128_u32[0];
  fWetLevel_low = (__m128)LODWORD(m_pParams->RTPC.fWetLevel);
  v26 = this->m_pfDelayStart[0];
  v102 = v26;
  fWetLevel_low.m128_f32[0] = (float)(fWetLevel_low.m128_f32[0] - this->m_fCurrentWet) * v24;
  LODWORD(v27) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFMem), (__m128)LODWORD(this->m_fFIRLPFMem), 0).m128_u32[0];
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  LODWORD(v113) = _mm_shuffle_ps(fWetLevel_low, fWetLevel_low, 0).m128_u32[0];
  v108 = v27;
  v28 = this->m_vIIRLPFB0[0];
  v29 = this->m_vIIRLPFB0[1];
  v30 = this->m_pfDelayRead[7];
  v92 = v23;
  v31 = v4->m_pfDelayRead[6];
  v32 = v4->m_vIIRLPFA1[0];
  v33 = v4->m_vIIRLPFA1[1];
  v34 = v4->m_vIIRLPFMem[1];
  uValidFrames = io_pBuffer->uValidFrames;
  v35 = v4->m_vIIRLPFMem[0];
  v114 = v28;
  v118 = v29;
  v116 = v32;
  v120 = v33;
  v98 = v34;
  if ( io_pBuffer->uValidFrames )
  {
    v36 = vOutDecorrelationVectorB;
    v37 = (unsigned int *)v4->m_pfDelayRead[6];
    v38 = vOutDecorrelationVectorD;
    v117 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorB);
    v111 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorD);
    do
    {
      v39 = (__m128)*(unsigned int *)v9;
      v40 = (__m128)*(unsigned int *)v10;
      v41 = (__m128)*(unsigned int *)v13;
      v9 += 4;
      if ( v9 >= v19 )
        v9 = v26;
      v10 += 4;
      v42 = (__m128)*(unsigned int *)v14;
      if ( v10 >= v19 )
        v10 = v26 + 1;
      v13 += 4;
      if ( v13 >= v19 )
        v13 = v26 + 2;
      v14 += 4;
      if ( v14 >= v19 )
        v14 = v26 + 3;
      v43 = _mm_unpacklo_ps(v41, v42);
      v44 = _mm_unpacklo_ps(v39, v40);
      v45 = (__m128)*(unsigned int *)v15;
      v15 += 4;
      if ( v15 >= v6 )
        v15 = v5;
      v46 = _mm_mul_ps(v35, v32);
      v92 += 4;
      v47 = (__m128)*(unsigned int *)v30;
      v35 = _mm_add_ps(_mm_mul_ps(_mm_movelh_ps(v44, v43), v28), v46);
      v48 = _mm_mul_ps(v35, vOutDecorrelationVectorA);
      v49 = _mm_mul_ps(v35, v38);
      v50 = (__m128)*((unsigned int *)v92 - 4);
      v95 = _mm_mul_ps(v35, vOutDecorrelationVectorF);
      v51 = (__m128)*v37;
      v52 = _mm_mul_ps(v35, vOutDecorrelationVectorC);
      v53 = _mm_mul_ps(v35, v36);
      if ( v92 >= v6 )
        v92 = v5 + 1;
      v37 += 4;
      if ( v37 >= (unsigned int *)v6 )
        v37 = (unsigned int *)(v5 + 2);
      v94 = v30 + 4;
      if ( v30 + 4 >= v6 )
        v94 = v5 + 3;
      v54 = io_pBuffer->uMaxFrames;
      v55 = *pData;
      v56 = pData[v54];
      v57 = 2 * (int)v54;
      v58 = 5 * (int)v54;
      v59 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v45, v50), _mm_unpacklo_ps(v51, v47)), v29),
              _mm_mul_ps(v98, v33));
      v60 = pData[v57];
      v61 = 3 * (int)v54;
      v62 = pData[v58];
      v98 = v59;
      v63 = pData[v61];
      v64 = 4 * (int)v54;
      v65 = _mm_add_ps(_mm_mul_ps(v111, v59), v95);
      v66 = pData[v64];
      v67 = _mm_add_ps(_mm_mul_ps(v59, vOutDecorrelationVectorA), v48);
      v68 = _mm_add_ps(v67, _mm_movehl_ps(v67, v67));
      v69 = _mm_add_ps(_mm_mul_ps(v59, v36), v53);
      v70 = _mm_add_ps(v69, _mm_movehl_ps(v69, v69));
      v71 = _mm_add_ps(_mm_mul_ps(v59, vOutDecorrelationVectorC), v52);
      v72 = _mm_add_ps(v71, _mm_movehl_ps(v71, v71));
      v73 = _mm_add_ps(_mm_mul_ps(v117, v59), v53);
      v74 = _mm_add_ps(v73, _mm_movehl_ps(v73, v73));
      v75 = _mm_add_ps(_mm_mul_ps(v59, vOutDecorrelationVectorE), v49);
      v76 = _mm_add_ps(v75, _mm_movehl_ps(v75, v75));
      v77 = _mm_add_ps(v65, _mm_movehl_ps(v65, v65));
      v78 = _mm_add_ps(v98, v35);
      v79 = _mm_add_ps(_mm_movehl_ps(v78, v78), v78);
      v80 = v103;
      v80.m128_f32[0] = v103.m128_f32[0] + v119;
      v103 = v80;
      v81 = v105;
      v82 = _mm_add_ps(_mm_shuffle_ps(v79, v79, 85), v79);
      v81.m128_f32[0] = v105.m128_f32[0] + v113;
      v105 = v81;
      v83 = _mm_mul_ps(_mm_shuffle_ps(v82, v82, 0), v109);
      *pData++ = (float)(v55 * v103.m128_f32[0])
               + (float)((float)(_mm_shuffle_ps(v68, v68, 85).m128_f32[0] + v68.m128_f32[0]) * v81.m128_f32[0]);
      pData[v54 - 1] = (float)(v56 * v103.m128_f32[0])
                     + (float)((float)(_mm_shuffle_ps(v70, v70, 85).m128_f32[0] + v70.m128_f32[0]) * v81.m128_f32[0]);
      v79.m128_f32[0] = _mm_shuffle_ps(v72, v72, 85).m128_f32[0] + v72.m128_f32[0];
      v84 = _mm_add_ps(v83, v35);
      pData[v57 - 1] = (float)(v60 * v103.m128_f32[0]) + (float)(v79.m128_f32[0] * v81.m128_f32[0]);
      pData[v58 - 1] = (float)(v62 * v103.m128_f32[0])
                     + (float)((float)(_mm_shuffle_ps(v74, v74, 85).m128_f32[0] + v74.m128_f32[0]) * v81.m128_f32[0]);
      pData[v61 - 1] = (float)(v63 * v103.m128_f32[0])
                     + (float)((float)(_mm_shuffle_ps(v76, v76, 85).m128_f32[0] + v76.m128_f32[0]) * v81.m128_f32[0]);
      pData[v64 - 1] = (float)(v66 * v103.m128_f32[0])
                     + (float)((float)(_mm_shuffle_ps(v77, v77, 85).m128_f32[0] + v77.m128_f32[0]) * v81.m128_f32[0]);
      v85 = _mm_add_ps(v98, v83);
      v11 = (float)((float)(v60 + v62) + v66) + (float)((float)(v55 + v56) + v63);
      v86 = _mm_shuffle_ps(v85, _mm_shuffle_ps(v85, v84, 15), 201);
      v87 = _mm_shuffle_ps(v84, _mm_shuffle_ps(v84, v85, 15), 201);
      v12 = (float)((float)(v115 * v106) + v11) - v107;
      v107 = v11;
      v106 = v12;
      if ( m_pfPreDelayStart )
      {
        v27 = *m_pfPreDelayRW;
        *m_pfPreDelayRW++ = v12;
        if ( m_pfPreDelayRW == m_pfPreDelayEnd )
          m_pfPreDelayRW = m_pfPreDelayStart;
      }
      else
      {
        v27 = v12;
      }
      v88 = v110;
      v19 = v104;
      v26 = v102;
      v6 = v100;
      v5 = v97;
      v38 = vOutDecorrelationVectorD;
      v32 = v116;
      v29 = v118;
      v30 = v94;
      v7 += 4;
      v88.m128_f32[0] = (float)(v110.m128_f32[0] * v27) + (float)(v112 * v108);
      v33 = v120;
      v89 = _mm_shuffle_ps(v88, v88, 0);
      v108 = v27;
      v90 = _mm_add_ps(v89, v86);
      v91 = _mm_add_ps(v89, v87);
      v36 = vOutDecorrelationVectorB;
      v28 = v114;
      *((__m128 *)v7 - 1) = v91;
      if ( v7 >= v104 )
        v7 = v102;
      *(__m128 *)v8 = v90;
      v8 += 4;
      if ( v8 >= v100 )
        v8 = v97;
      --uValidFrames;
    }
    while ( uValidFrames );
    v34 = v98;
    v96 = (float *)v37;
    v4 = this;
    v31 = v96;
  }
  v4->m_fFIRLPFMem = v27;
  v4->m_fDCFwdMem = v11;
  v4->m_fDCFbkMem = v12;
  v4->m_pfPreDelayRW = m_pfPreDelayRW;
  v4->m_vIIRLPFMem[0] = v35;
  v4->m_pfDelayRead[5] = v92;
  v4->m_vIIRLPFMem[1] = v34;
  v4->m_pfDelayWrite[0] = v7;
  v4->m_pfDelayWrite[1] = v8;
  v4->m_pfDelayRead[0] = v9;
  v4->m_pfDelayRead[1] = v10;
  v4->m_pfDelayRead[2] = v13;
  v4->m_pfDelayRead[3] = v14;
  v4->m_pfDelayRead[4] = v15;
  v4->m_pfDelayRead[6] = v31;
  v4->m_pfDelayRead[7] = v30;
}] = v35;
  v4->m_pfDelayRead[5] = v92;
  v4->m_vIIRLPFMem[1] = v34;
  v4->m_pfDelayWrite[0] = v7;
  v4->m_pfDelayWrite[1] = v8;
  v4->m_pfDelayRead[0] = v9;
  v4->m_pfDelayRead[1] = v10;
  v4->m_pfDelayRead[2] = v13;
  v4->m_pfDelayRead[3] =

// File Line: 1586
// RVA: 0xAC88E0
void __fastcall CAkFDNReverbFX::ProcessFivePointOne12(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *m_pfPreDelayRW; // r15
  CAkFDNReverbFX *v4; // r11
  float *v5; // rdi
  float *v6; // rsi
  float *v7; // rbp
  float *v8; // rbx
  float *v9; // r13
  unsigned int v10; // xmm4_4
  float v11; // xmm9_4
  float v12; // xmm3_4
  CAkFDNReverbFXParams *m_pParams; // rdx
  __m128 v15; // xmm0
  __m128 fDryLevel_low; // xmm1
  float v17; // xmm2_4
  __m128 fWetLevel_low; // xmm0
  float *v19; // rcx
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  float *v22; // rax
  float *v23; // r14
  float *v24; // r8
  float *v25; // r12
  __m128 v26; // xmm15
  __m128 v27; // xmm1
  float *v28; // r10
  float *v29; // rdx
  __m128 v30; // xmm0
  float *v31; // r9
  float *v32; // r11
  unsigned __int64 v33; // rax
  __m128 v34; // xmm8
  __m128 v35; // xmm10
  __m128 v36; // xmm11
  __m128 v37; // xmm12
  __m128 v38; // xmm14
  __m128 v39; // xmm13
  __m128 v40; // xmm2
  __m128 v41; // xmm0
  __m128 v42; // xmm4
  float *v43; // rax
  __m128 v44; // xmm2
  __m128 v45; // xmm0
  __m128 v46; // xmm15
  __m128 v47; // xmm2
  __m128 v48; // xmm7
  __m128 v49; // xmm8
  __m128 v50; // xmm4
  __m128 v51; // xmm3
  __m128 v52; // xmm5
  __m128 v53; // xmm6
  float *v54; // rax
  __m128 v55; // xmm2
  __m128 v56; // xmm8
  __m128 v57; // xmm1
  __m128 v58; // xmm4
  __m128 v59; // xmm0
  __m128 v60; // xmm2
  __m128 v61; // xmm6
  __m128 v62; // xmm5
  __m128 v63; // xmm7
  __m128 v64; // xmm0
  __m128 v65; // xmm1
  __m128 v66; // xmm3
  __int64 uMaxFrames; // rcx
  float v68; // xmm14_4
  float v69; // xmm12_4
  __int64 v70; // rdx
  __int64 v71; // r8
  float v72; // xmm13_4
  __int64 v73; // r9
  float v74; // xmm10_4
  float v75; // xmm11_4
  __int64 v76; // r10
  __m128 v77; // xmm2
  __m128 v78; // xmm8
  __m128 v79; // xmm2
  float v80; // xmm9_4
  __m128 v81; // xmm3
  __m128 v82; // xmm5
  __m128 v83; // xmm3
  __m128 v84; // xmm2
  __m128 v85; // xmm4
  __m128 v86; // xmm4
  __m128 v87; // xmm6
  __m128 v88; // xmm8
  __m128 v89; // xmm5
  __m128 v90; // xmm6
  __m128 v91; // xmm0
  __m128 v92; // xmm1
  __m128 v93; // xmm0
  __m128 v94; // xmm0
  __m128 v95; // xmm7
  __m128 v96; // xmm7
  __m128 v97; // xmm5
  __m128 v98; // xmm2
  __m128 v99; // xmm1
  __m128 v100; // xmm6
  __m128 v101; // xmm7
  __m128 v102; // xmm5
  float v103; // xmm1_4
  __m128 v104; // xmm2
  __m128 v105; // xmm2
  __m128 v106; // xmm0
  __m128 v107; // xmm1
  __m128 v108; // xmm2
  float *v109; // [rsp+0h] [rbp-308h]
  float *v110; // [rsp+8h] [rbp-300h]
  float *v111; // [rsp+10h] [rbp-2F8h]
  float *v112; // [rsp+18h] [rbp-2F0h]
  float *v113; // [rsp+20h] [rbp-2E8h]
  unsigned int *v114; // [rsp+28h] [rbp-2E0h]
  float *v115; // [rsp+30h] [rbp-2D8h]
  float *v116; // [rsp+38h] [rbp-2D0h]
  float *pData; // [rsp+40h] [rbp-2C8h]
  float *v118; // [rsp+48h] [rbp-2C0h]
  __m128 v119; // [rsp+50h] [rbp-2B8h]
  float *v120; // [rsp+60h] [rbp-2A8h]
  __m128 v121; // [rsp+70h] [rbp-298h]
  float *v122; // [rsp+70h] [rbp-298h]
  float *v123; // [rsp+80h] [rbp-288h]
  float *v124; // [rsp+88h] [rbp-280h]
  float *v125; // [rsp+90h] [rbp-278h]
  __m128 v126; // [rsp+A0h] [rbp-268h]
  __m128 v127; // [rsp+B0h] [rbp-258h]
  float *m_pfPreDelayStart; // [rsp+C0h] [rbp-248h]
  __m128 v129; // [rsp+D0h] [rbp-238h]
  float *m_pfPreDelayEnd; // [rsp+E0h] [rbp-228h]
  float v131; // [rsp+F0h] [rbp-218h]
  float v132; // [rsp+100h] [rbp-208h]
  float v133; // [rsp+110h] [rbp-1F8h]
  __m128 v134; // [rsp+120h] [rbp-1E8h]
  __m128 v135; // [rsp+130h] [rbp-1D8h]
  float v136; // [rsp+140h] [rbp-1C8h]
  __m128 v137; // [rsp+150h] [rbp-1B8h]
  __m128 v138; // [rsp+160h] [rbp-1A8h]
  float v139; // [rsp+170h] [rbp-198h]
  __m128 v140; // [rsp+180h] [rbp-188h]
  __m128 v141; // [rsp+190h] [rbp-178h]
  float v142; // [rsp+1A0h] [rbp-168h]
  float v143; // [rsp+1B0h] [rbp-158h]
  __m128 v144; // [rsp+1C0h] [rbp-148h]
  __m128 v145; // [rsp+1D0h] [rbp-138h]
  __m128 v146; // [rsp+1E0h] [rbp-128h]
  __m128 v147; // [rsp+1F0h] [rbp-118h]
  __m128 v148; // [rsp+200h] [rbp-108h]
  __m128 v149; // [rsp+210h] [rbp-F8h]
  int uValidFrames; // [rsp+328h] [rbp+20h]

  v2 = (__m128)LODWORD(FLOAT_N2_0);
  m_pfPreDelayRW = this->m_pfPreDelayRW;
  v4 = this;
  v5 = this->m_pfDelayWrite[0];
  v6 = this->m_pfDelayWrite[1];
  v141 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  v126 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  v7 = this->m_pfDelayWrite[2];
  v8 = this->m_pfDelayRead[0];
  v9 = this->m_pfDelayRead[2];
  v10 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFMem), (__m128)LODWORD(this->m_fFIRLPFMem), 0).m128_u32[0];
  LODWORD(v11) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  LODWORD(v12) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  v132 = *(float *)&v10;
  v133 = v11;
  v131 = v12;
  m_pParams = this->m_pParams;
  v125 = this->m_pfDelayStart[0];
  LODWORD(v143) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  LODWORD(v139) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  pData = (float *)io_pBuffer->pData;
  v2.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  v15 = v2;
  fDryLevel_low = (__m128)LODWORD(m_pParams->RTPC.fDryLevel);
  v137 = _mm_shuffle_ps(v15, v15, 0);
  v129 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  m_pfPreDelayStart = this->m_pfPreDelayStart;
  v115 = this->m_pfDelayEnd[0];
  v17 = 1.0 / (float)io_pBuffer->uMaxFrames;
  fDryLevel_low.m128_f32[0] = (float)(fDryLevel_low.m128_f32[0] - this->m_fCurrentDry) * v17;
  LODWORD(v142) = _mm_shuffle_ps(fDryLevel_low, fDryLevel_low, 0).m128_u32[0];
  fWetLevel_low = (__m128)LODWORD(m_pParams->RTPC.fWetLevel);
  v112 = this->m_pfDelayStart[2];
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  fWetLevel_low.m128_f32[0] = (float)(fWetLevel_low.m128_f32[0] - this->m_fCurrentWet) * v17;
  v118 = this->m_pfDelayStart[1];
  v123 = this->m_pfDelayEnd[2];
  LODWORD(v136) = _mm_shuffle_ps(fWetLevel_low, fWetLevel_low, 0).m128_u32[0];
  v124 = this->m_pfDelayEnd[1];
  v19 = this->m_pfDelayRead[1];
  v20 = v4->m_vIIRLPFB0[0];
  v21 = v4->m_vIIRLPFA1[0];
  v22 = v4->m_pfDelayRead[3];
  v23 = v4->m_pfDelayRead[4];
  v24 = v4->m_pfDelayRead[7];
  v25 = v4->m_pfDelayRead[8];
  v26 = v4->m_vIIRLPFMem[0];
  v27 = v4->m_vIIRLPFMem[1];
  v144 = v4->m_vIIRLPFB0[1];
  v28 = v4->m_pfDelayRead[10];
  v111 = v4->m_pfDelayRead[9];
  v147 = v20;
  v149 = v21;
  v110 = v4->m_pfDelayRead[11];
  v109 = v4->m_pfDelayRead[5];
  v138 = v4->m_vIIRLPFB0[2];
  v146 = v4->m_vIIRLPFA1[1];
  v29 = v4->m_pfDelayRead[6];
  v135 = v4->m_vIIRLPFA1[2];
  v30 = v4->m_vIIRLPFMem[2];
  uValidFrames = io_pBuffer->uValidFrames;
  v31 = v125;
  v119 = v30;
  if ( io_pBuffer->uValidFrames )
  {
    v32 = v4->m_pfDelayRead[3];
    v33 = (unsigned __int64)v115;
    v34 = vOutDecorrelationVectorD;
    v35 = vOutDecorrelationVectorB;
    v36 = vOutDecorrelationVectorC;
    v37 = vOutDecorrelationVectorA;
    v38 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorD);
    v39 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorB);
    v140 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorC);
    v145 = v38;
    v134 = v39;
    do
    {
      v40 = (__m128)*(unsigned int *)v8;
      v41 = (__m128)*(unsigned int *)v9;
      v8 += 4;
      if ( (unsigned __int64)v8 >= v33 )
        v8 = v31;
      v120 = v19 + 4;
      v42 = (__m128)*(unsigned int *)v32;
      if ( (unsigned __int64)(v19 + 4) >= v33 )
      {
        v120 = v31 + 1;
        v33 = (unsigned __int64)v115;
      }
      v9 += 4;
      if ( (unsigned __int64)v9 >= v33 )
        v9 = v31 + 2;
      v32 += 4;
      if ( (unsigned __int64)v32 >= v33 )
        v32 = v31 + 3;
      v43 = v118;
      v44 = _mm_mul_ps(
              _mm_movelh_ps(_mm_unpacklo_ps(v40, (__m128)*(unsigned int *)v19), _mm_unpacklo_ps(v41, v42)),
              v20);
      v23 += 4;
      v45 = _mm_mul_ps(v26, v21);
      v46 = v44;
      v47 = (__m128)*((unsigned int *)v23 - 4);
      v26 = _mm_add_ps(v46, v45);
      if ( v23 >= v124 )
        v23 = v118;
      v109 += 4;
      v48 = _mm_mul_ps(v26, v34);
      v49 = (__m128)*((unsigned int *)v109 - 4);
      v50 = _mm_mul_ps(v26, v37);
      v51 = _mm_mul_ps(v26, vOutDecorrelationVectorF);
      v52 = _mm_mul_ps(v26, v35);
      v53 = _mm_mul_ps(v26, v36);
      if ( v109 >= v124 )
        v109 = v118 + 1;
      v113 = v29 + 4;
      if ( v29 + 4 >= v124 )
      {
        v113 = v118 + 2;
        v43 = v118;
      }
      v114 = (unsigned int *)(v24 + 4);
      if ( v24 + 4 >= v124 )
        v114 = (unsigned int *)(v43 + 3);
      v54 = v112;
      v25 += 4;
      v55 = _mm_mul_ps(
              _mm_movelh_ps(
                _mm_unpacklo_ps(v47, v49),
                _mm_unpacklo_ps((__m128)*(unsigned int *)v29, (__m128)*(unsigned int *)v24)),
              v144);
      v56 = (__m128)*(unsigned int *)v110;
      v57 = _mm_add_ps(v55, _mm_mul_ps(v27, v146));
      v127 = v57;
      v58 = _mm_add_ps(v50, _mm_mul_ps(v57, v37));
      v59 = _mm_mul_ps(v57, v36);
      v121 = _mm_add_ps(v52, _mm_mul_ps(v57, v35));
      v60 = (__m128)*((unsigned int *)v25 - 4);
      if ( v25 >= v123 )
        v25 = v112;
      v61 = _mm_add_ps(v53, v59);
      v111 += 4;
      v62 = _mm_add_ps(v52, _mm_mul_ps(v39, v57));
      v63 = _mm_add_ps(v48, _mm_mul_ps(v57, vOutDecorrelationVectorE));
      v64 = _mm_mul_ps(v38, v57);
      v65 = _mm_add_ps(v57, v26);
      v148 = _mm_add_ps(v51, v64);
      v66 = (__m128)*((unsigned int *)v111 - 4);
      if ( v111 >= v123 )
        v111 = v112 + 1;
      v116 = v28 + 4;
      if ( v28 + 4 >= v123 )
      {
        v116 = v112 + 2;
        v54 = v112;
      }
      v110 += 4;
      if ( v110 >= v123 )
        v110 = v54 + 3;
      uMaxFrames = io_pBuffer->uMaxFrames;
      v68 = *pData;
      v69 = pData[uMaxFrames];
      v70 = 2 * (int)uMaxFrames;
      v71 = 5 * (int)uMaxFrames;
      v72 = pData[v70];
      v73 = 3 * (int)uMaxFrames;
      v74 = pData[v71];
      v75 = pData[v73];
      v119 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_movelh_ps(_mm_unpacklo_ps(v60, v66), _mm_unpacklo_ps((__m128)*(unsigned int *)v28, v56)),
                 v138),
               _mm_mul_ps(v119, v135));
      v76 = 4 * (int)uMaxFrames;
      v77 = _mm_mul_ps(v119, vOutDecorrelationVectorB);
      v78 = _mm_add_ps(v77, v62);
      v79 = _mm_add_ps(v77, v121);
      v80 = pData[v76];
      v81 = _mm_add_ps(_mm_mul_ps(v119, vOutDecorrelationVectorA), v58);
      v82 = _mm_add_ps(_mm_mul_ps(v134, v119), v63);
      v83 = _mm_add_ps(v81, _mm_movehl_ps(v81, v81));
      v84 = _mm_add_ps(v79, _mm_movehl_ps(v79, v79));
      v85 = _mm_add_ps(_mm_mul_ps(v119, vOutDecorrelationVectorC), v61);
      v86 = _mm_add_ps(v85, _mm_movehl_ps(v85, v85));
      v87 = _mm_add_ps(_mm_mul_ps(v140, v119), v148);
      v88 = _mm_add_ps(v78, _mm_movehl_ps(v78, v78));
      v89 = _mm_add_ps(v82, _mm_movehl_ps(v82, v82));
      v90 = _mm_add_ps(v87, _mm_movehl_ps(v87, v87));
      v91 = _mm_add_ps(v119, v65);
      v92 = _mm_add_ps(_mm_movehl_ps(v91, v91), v91);
      v93 = v129;
      v93.m128_f32[0] = v129.m128_f32[0] + v142;
      v129 = v93;
      v94 = v126;
      v95 = _mm_add_ps(_mm_shuffle_ps(v92, v92, 85), v92);
      v94.m128_f32[0] = v126.m128_f32[0] + v136;
      v126 = v94;
      ++pData;
      v96 = _mm_mul_ps(_mm_shuffle_ps(v95, v95, 0), v137);
      *(pData - 1) = (float)(v68 * v129.m128_f32[0])
                   + (float)((float)(_mm_shuffle_ps(v83, v83, 85).m128_f32[0] + v83.m128_f32[0]) * v94.m128_f32[0]);
      pData[uMaxFrames - 1] = (float)(v69 * v129.m128_f32[0])
                            + (float)((float)(_mm_shuffle_ps(v84, v84, 85).m128_f32[0] + v84.m128_f32[0])
                                    * v94.m128_f32[0]);
      pData[v70 - 1] = (float)(v72 * v129.m128_f32[0])
                     + (float)((float)(_mm_shuffle_ps(v86, v86, 85).m128_f32[0] + v86.m128_f32[0]) * v94.m128_f32[0]);
      pData[v71 - 1] = (float)(v74 * v129.m128_f32[0])
                     + (float)((float)(_mm_shuffle_ps(v88, v88, 85).m128_f32[0] + v88.m128_f32[0]) * v94.m128_f32[0]);
      v92.m128_f32[0] = _mm_shuffle_ps(v89, v89, 85).m128_f32[0] + v89.m128_f32[0];
      v97 = _mm_add_ps(v96, v26);
      pData[v73 - 1] = (float)(v75 * v129.m128_f32[0]) + (float)(v92.m128_f32[0] * v94.m128_f32[0]);
      v94.m128_f32[0] = v80 * v129.m128_f32[0];
      v11 = (float)((float)(v72 + v74) + v80) + (float)((float)(v68 + v69) + v75);
      v98 = _mm_add_ps(v119, v96);
      pData[v76 - 1] = v94.m128_f32[0]
                     + (float)((float)(_mm_shuffle_ps(v90, v90, 85).m128_f32[0] + v90.m128_f32[0]) * v126.m128_f32[0]);
      v99 = _mm_add_ps(v127, v96);
      v100 = _mm_shuffle_ps(v98, _mm_shuffle_ps(v98, v97, 15), 201);
      v101 = _mm_shuffle_ps(v99, _mm_shuffle_ps(v99, v98, 15), 201);
      v102 = _mm_shuffle_ps(v97, _mm_shuffle_ps(v97, v99, 15), 201);
      v12 = (float)((float)(v139 * v131) + v11) - v133;
      v133 = v11;
      v131 = v12;
      if ( m_pfPreDelayStart )
      {
        v103 = *m_pfPreDelayRW;
        *m_pfPreDelayRW++ = v12;
        if ( m_pfPreDelayRW == m_pfPreDelayEnd )
          m_pfPreDelayRW = m_pfPreDelayStart;
      }
      else
      {
        v103 = v12;
      }
      v104 = v141;
      v33 = (unsigned __int64)v115;
      v31 = v125;
      v19 = v120;
      v29 = v113;
      v35 = vOutDecorrelationVectorB;
      v36 = vOutDecorrelationVectorC;
      v37 = vOutDecorrelationVectorA;
      v24 = (float *)v114;
      v28 = v116;
      v5 += 4;
      v104.m128_f32[0] = (float)(v141.m128_f32[0] * v103) + (float)(v143 * v132);
      v105 = _mm_shuffle_ps(v104, v104, 0);
      v39 = v134;
      v38 = v145;
      v34 = vOutDecorrelationVectorD;
      v10 = LODWORD(v103);
      v132 = v103;
      v106 = _mm_add_ps(v105, v102);
      v20 = v147;
      *((__m128 *)v5 - 1) = v106;
      v107 = v105;
      if ( v5 >= v115 )
        v5 = v125;
      v6 += 4;
      v108 = _mm_add_ps(v105, v100);
      v21 = v149;
      *((__m128 *)v6 - 1) = _mm_add_ps(v107, v101);
      v27 = v127;
      if ( v6 >= v124 )
        v6 = v118;
      *(__m128 *)v7 = v108;
      v7 += 4;
      if ( v7 >= v123 )
        v7 = v112;
      --uValidFrames;
    }
    while ( uValidFrames );
    v30 = v119;
    v122 = v32;
    v4 = this;
    v22 = v122;
  }
  LODWORD(v4->m_fFIRLPFMem) = v10;
  v4->m_fDCFwdMem = v11;
  v4->m_fDCFbkMem = v12;
  v4->m_pfPreDelayRW = m_pfPreDelayRW;
  v4->m_pfDelayRead[3] = v22;
  v4->m_vIIRLPFMem[0] = v26;
  v4->m_vIIRLPFMem[1] = v27;
  v4->m_vIIRLPFMem[2] = v30;
  v4->m_pfDelayRead[5] = v109;
  v4->m_pfDelayWrite[0] = v5;
  v4->m_pfDelayRead[9] = v111;
  v4->m_pfDelayWrite[1] = v6;
  v4->m_pfDelayWrite[2] = v7;
  v4->m_pfDelayRead[0] = v8;
  v4->m_pfDelayRead[1] = v19;
  v4->m_pfDelayRead[11] = v110;
  v4->m_pfDelayRead[2] = v9;
  v4->m_pfDelayRead[4] = v23;
  v4->m_pfDelayRead[6] = v29;
  v4->m_pfDelayRead[7] = v24;
  v4->m_pfDelayRead[8] = v25;
  v4->m_pfDelayRead[10] = v28;
}

// File Line: 1636
// RVA: 0xAC93C0
void __fastcall CAkFDNReverbFX::ProcessFivePointOne16(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *m_pfPreDelayRW; // r12
  CAkFDNReverbFX *v4; // r11
  CAkFDNReverbFXParams *m_pParams; // rdx
  float *v7; // rdi
  unsigned int v8; // xmm4_4
  float v9; // xmm3_4
  unsigned int v10; // xmm9_4
  __m128 v11; // xmm0
  __m128 fDryLevel_low; // xmm1
  float v13; // xmm2_4
  __m128 fWetLevel_low; // xmm0
  float *v15; // rax
  __m128 v16; // xmm6
  float *v17; // rsi
  float *v18; // rbp
  float *v19; // r14
  __m128 v20; // xmm7
  __m128 v21; // xmm15
  __m128 v22; // xmm1
  float *v23; // rbx
  float *v24; // r8
  float *v25; // rcx
  __m128 v26; // xmm2
  float *v27; // rdx
  float *v28; // r15
  float *v29; // r9
  float *v30; // r10
  float *v31; // r13
  __m128 v32; // xmm0
  float *v33; // rax
  __m128 v34; // xmm8
  float *v35; // r11
  float *v36; // rax
  __m128 v37; // xmm10
  __m128 v38; // xmm11
  __m128 v39; // xmm12
  __m128 v40; // xmm14
  __m128 v41; // xmm3
  float *v42; // rax
  __m128 v43; // xmm9
  __m128 v44; // xmm0
  __m128 v45; // xmm15
  __m128 v46; // xmm3
  __m128 v47; // xmm7
  __m128 v48; // xmm4
  __m128 v49; // xmm6
  __m128 v50; // xmm8
  __m128 v51; // xmm5
  __m128 v52; // xmm13
  __m128 v53; // xmm9
  __m128 v54; // xmm4
  __m128 v55; // xmm3
  __m128 v56; // xmm5
  __m128 v57; // xmm0
  __m128 v58; // xmm14
  __m128 v59; // xmm6
  __m128 v60; // xmm7
  __m128 v61; // xmm0
  __m128 v62; // xmm1
  __m128 v63; // xmm8
  __m128 v64; // xmm0
  __m128 v65; // xmm1
  __m128 v66; // xmm4
  __m128 v67; // xmm6
  __m128 v68; // xmm3
  __m128 v69; // xmm5
  __m128 v70; // xmm7
  __m128 v71; // xmm0
  __m128 v72; // xmm2
  __m128 v73; // xmm8
  __m128 v74; // xmm0
  __m128 v75; // xmm8
  __int64 uMaxFrames; // rcx
  float v77; // xmm12_4
  __int64 v78; // rdx
  __int64 v79; // r8
  float v80; // xmm13_4
  __int64 v81; // r9
  float v82; // xmm10_4
  float v83; // xmm11_4
  __int64 v84; // r10
  __m128 v85; // xmm2
  __m128 v86; // xmm8
  __m128 v87; // xmm2
  float v88; // xmm9_4
  __m128 v89; // xmm3
  __m128 v90; // xmm3
  __m128 v91; // xmm2
  __m128 v92; // xmm4
  __m128 v93; // xmm4
  __m128 v94; // xmm5
  __m128 v95; // xmm5
  __m128 v96; // xmm6
  __m128 v97; // xmm8
  __m128 v98; // xmm6
  __m128 v99; // xmm0
  __m128 v100; // xmm1
  __m128 v101; // xmm0
  __m128 v102; // xmm0
  __m128 v103; // xmm7
  __m128 v104; // xmm7
  float v105; // xmm14_4
  float v106; // xmm13_4
  __m128 v107; // xmm5
  __m128 v108; // xmm2
  __m128 v109; // xmm1
  __m128 v110; // xmm6
  __m128 v111; // xmm8
  __m128 v112; // xmm1
  __m128 v113; // xmm7
  __m128 v114; // xmm5
  float v115; // xmm1_4
  __m128 v116; // xmm2
  __m128 v117; // xmm2
  __m128 v118; // xmm1
  __m128 v119; // xmm0
  __m128 v120; // xmm2
  __m128 v121; // xmm1
  __m128 v122; // xmm0
  float *v123; // [rsp+0h] [rbp-388h]
  float *v124; // [rsp+8h] [rbp-380h]
  float *v125; // [rsp+10h] [rbp-378h]
  float *v126; // [rsp+18h] [rbp-370h]
  float *v127; // [rsp+20h] [rbp-368h]
  float *v128; // [rsp+28h] [rbp-360h]
  float *v129; // [rsp+30h] [rbp-358h]
  float *v130; // [rsp+38h] [rbp-350h]
  float *v131; // [rsp+40h] [rbp-348h]
  float *v132; // [rsp+48h] [rbp-340h]
  unsigned int *v133; // [rsp+50h] [rbp-338h]
  float *pData; // [rsp+58h] [rbp-330h]
  float *v135; // [rsp+60h] [rbp-328h]
  float *v136; // [rsp+68h] [rbp-320h]
  float *v137; // [rsp+70h] [rbp-318h]
  float *v138; // [rsp+78h] [rbp-310h]
  __m128 v139; // [rsp+80h] [rbp-308h]
  float *v140; // [rsp+80h] [rbp-308h]
  __m128 v141; // [rsp+90h] [rbp-2F8h]
  float *v142; // [rsp+A0h] [rbp-2E8h]
  float *v143; // [rsp+A8h] [rbp-2E0h]
  float *v144; // [rsp+B0h] [rbp-2D8h]
  float *v145; // [rsp+B8h] [rbp-2D0h]
  float *v146; // [rsp+C0h] [rbp-2C8h]
  __m128 v147; // [rsp+D0h] [rbp-2B8h]
  __m128 v148; // [rsp+E0h] [rbp-2A8h]
  float *m_pfPreDelayEnd; // [rsp+F0h] [rbp-298h]
  __m128 v150; // [rsp+100h] [rbp-288h]
  __m128 v151; // [rsp+110h] [rbp-278h]
  float *m_pfPreDelayStart; // [rsp+120h] [rbp-268h]
  float v153; // [rsp+130h] [rbp-258h]
  float v154; // [rsp+140h] [rbp-248h]
  float v155; // [rsp+150h] [rbp-238h]
  __m128 v156; // [rsp+160h] [rbp-228h]
  __m128 v157; // [rsp+170h] [rbp-218h]
  __m128 v158; // [rsp+180h] [rbp-208h]
  __m128 v159; // [rsp+190h] [rbp-1F8h]
  __m128 v160; // [rsp+1A0h] [rbp-1E8h]
  float v161; // [rsp+1B0h] [rbp-1D8h]
  __m128 v162; // [rsp+1C0h] [rbp-1C8h]
  float v163; // [rsp+1D0h] [rbp-1B8h]
  __m128 v164; // [rsp+1E0h] [rbp-1A8h]
  __m128 v165; // [rsp+1F0h] [rbp-198h]
  __m128 v166; // [rsp+200h] [rbp-188h]
  float v167; // [rsp+210h] [rbp-178h]
  __m128 v168; // [rsp+220h] [rbp-168h]
  __m128 v169; // [rsp+230h] [rbp-158h]
  __m128 v170; // [rsp+240h] [rbp-148h]
  float v171; // [rsp+250h] [rbp-138h]
  __m128 v172; // [rsp+260h] [rbp-128h]
  __m128 v173; // [rsp+270h] [rbp-118h]
  __m128 v174; // [rsp+280h] [rbp-108h]
  __m128 v175; // [rsp+290h] [rbp-F8h]
  int uValidFrames; // [rsp+3A8h] [rbp+20h]

  v2 = (__m128)LODWORD(FLOAT_N2_0);
  m_pfPreDelayRW = this->m_pfPreDelayRW;
  v4 = this;
  m_pParams = this->m_pParams;
  v169 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  v7 = this->m_pfDelayWrite[0];
  v8 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFMem), (__m128)LODWORD(this->m_fFIRLPFMem), 0).m128_u32[0];
  LODWORD(v9) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  LODWORD(v171) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  v151 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  v154 = *(float *)&v8;
  v10 = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  v153 = v9;
  LODWORD(v167) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  v155 = *(float *)&v10;
  pData = (float *)io_pBuffer->pData;
  v2.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  v11 = v2;
  fDryLevel_low = (__m128)LODWORD(m_pParams->RTPC.fDryLevel);
  v165 = _mm_shuffle_ps(v11, v11, 0);
  v147 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  m_pfPreDelayStart = this->m_pfPreDelayStart;
  v128 = this->m_pfDelayStart[0];
  v13 = 1.0 / (float)io_pBuffer->uMaxFrames;
  v124 = this->m_pfDelayEnd[0];
  fDryLevel_low.m128_f32[0] = (float)(fDryLevel_low.m128_f32[0] - this->m_fCurrentDry) * v13;
  LODWORD(v161) = _mm_shuffle_ps(fDryLevel_low, fDryLevel_low, 0).m128_u32[0];
  fWetLevel_low = (__m128)LODWORD(m_pParams->RTPC.fWetLevel);
  v145 = this->m_pfDelayStart[2];
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  fWetLevel_low.m128_f32[0] = (float)(fWetLevel_low.m128_f32[0] - this->m_fCurrentWet) * v13;
  v132 = this->m_pfDelayStart[1];
  v146 = this->m_pfDelayEnd[2];
  LODWORD(v163) = _mm_shuffle_ps(fWetLevel_low, fWetLevel_low, 0).m128_u32[0];
  v144 = this->m_pfDelayStart[3];
  v142 = this->m_pfDelayEnd[1];
  v143 = this->m_pfDelayEnd[3];
  v15 = this->m_pfDelayRead[5];
  v16 = this->m_vIIRLPFB0[0];
  v17 = this->m_pfDelayWrite[1];
  v18 = this->m_pfDelayWrite[2];
  v19 = this->m_pfDelayWrite[3];
  v20 = this->m_vIIRLPFA1[0];
  v21 = this->m_vIIRLPFMem[0];
  v22 = this->m_vIIRLPFMem[1];
  v23 = this->m_pfDelayRead[0];
  v24 = this->m_pfDelayRead[1];
  v25 = this->m_pfDelayRead[2];
  v26 = v4->m_vIIRLPFMem[2];
  v162 = v4->m_vIIRLPFB0[1];
  v27 = v4->m_pfDelayRead[3];
  v28 = v4->m_pfDelayRead[4];
  v29 = v4->m_pfDelayRead[6];
  v168 = v4->m_vIIRLPFB0[2];
  v173 = v16;
  v30 = v4->m_pfDelayRead[7];
  v31 = v4->m_pfDelayRead[8];
  v126 = v15;
  v164 = v4->m_vIIRLPFB0[3];
  v175 = v20;
  v130 = v4->m_pfDelayRead[9];
  v174 = v4->m_vIIRLPFA1[1];
  v123 = v4->m_pfDelayRead[10];
  v157 = v4->m_vIIRLPFA1[2];
  v125 = v4->m_pfDelayRead[11];
  v170 = v4->m_vIIRLPFA1[3];
  v32 = v4->m_vIIRLPFMem[3];
  v141 = v32;
  v127 = v4->m_pfDelayRead[13];
  v129 = v4->m_pfDelayRead[14];
  v131 = v4->m_pfDelayRead[15];
  uValidFrames = io_pBuffer->uValidFrames;
  v33 = v4->m_pfDelayRead[12];
  if ( io_pBuffer->uValidFrames )
  {
    v34 = vOutDecorrelationVectorD;
    v35 = v4->m_pfDelayRead[12];
    v36 = v128;
    v37 = vOutDecorrelationVectorC;
    v38 = vOutDecorrelationVectorB;
    v39 = vOutDecorrelationVectorA;
    v160 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorD);
    v40 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorB);
    v166 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorA);
    v172 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorC);
    v156 = v40;
    do
    {
      v41 = (__m128)*(unsigned int *)v23;
      v23 += 4;
      if ( v23 >= v124 )
        v23 = v36;
      v135 = v24 + 4;
      if ( v24 + 4 >= v124 )
      {
        v135 = v36 + 1;
        v36 = v128;
      }
      v138 = v25 + 4;
      if ( v25 + 4 >= v124 )
        v138 = v36 + 2;
      v137 = v27 + 4;
      if ( v27 + 4 >= v124 )
        v137 = v128 + 3;
      v42 = v132;
      v43 = (__m128)*(unsigned int *)v126;
      v28 += 4;
      v44 = _mm_mul_ps(v21, v20);
      v45 = _mm_mul_ps(
              _mm_movelh_ps(
                _mm_unpacklo_ps(v41, (__m128)*(unsigned int *)v24),
                _mm_unpacklo_ps((__m128)*(unsigned int *)v25, (__m128)*(unsigned int *)v27)),
              v16);
      v46 = (__m128)*((unsigned int *)v28 - 4);
      v21 = _mm_add_ps(v45, v44);
      if ( v28 >= v142 )
        v28 = v132;
      v126 += 4;
      v47 = _mm_mul_ps(v21, v34);
      v48 = _mm_mul_ps(v21, v39);
      v49 = _mm_mul_ps(v21, v38);
      v50 = _mm_mul_ps(v21, vOutDecorrelationVectorF);
      v51 = _mm_mul_ps(v21, v37);
      if ( v126 >= v142 )
        v126 = v132 + 1;
      v136 = v29 + 4;
      if ( v29 + 4 >= v142 )
      {
        v136 = v132 + 2;
        v42 = v132;
      }
      v133 = (unsigned int *)(v30 + 4);
      if ( v30 + 4 >= v142 )
        v133 = (unsigned int *)(v42 + 3);
      v52 = (__m128)*(unsigned int *)v130;
      v31 += 4;
      v150 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_movelh_ps(
                   _mm_unpacklo_ps(v46, v43),
                   _mm_unpacklo_ps((__m128)*(unsigned int *)v29, (__m128)*(unsigned int *)v30)),
                 v162),
               _mm_mul_ps(v22, v174));
      v53 = _mm_add_ps(v150, v21);
      v54 = _mm_add_ps(v48, _mm_mul_ps(v150, v39));
      v55 = _mm_add_ps(v49, _mm_mul_ps(v150, v38));
      v56 = _mm_add_ps(v51, _mm_mul_ps(v150, v37));
      v57 = v40;
      v58 = (__m128)*(unsigned int *)v125;
      v59 = _mm_add_ps(v49, _mm_mul_ps(v57, v150));
      v60 = _mm_add_ps(v47, _mm_mul_ps(v150, vOutDecorrelationVectorE));
      v61 = _mm_mul_ps(v160, v150);
      v62 = (__m128)*((unsigned int *)v31 - 4);
      if ( v31 >= v146 )
        v31 = v145;
      v130 += 4;
      v63 = _mm_add_ps(v50, v61);
      v64 = (__m128)*(unsigned int *)v123;
      if ( v130 >= v146 )
        v130 = v145 + 1;
      v123 += 4;
      if ( v123 >= v146 )
        v123 = v145 + 2;
      v125 += 4;
      if ( v125 >= v146 )
        v125 = v145 + 3;
      v35 += 4;
      v148 = _mm_add_ps(
               _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v62, v52), _mm_unpacklo_ps(v64, v58)), v168),
               _mm_mul_ps(v26, v157));
      v65 = _mm_mul_ps(v148, v38);
      v159 = _mm_add_ps(v53, v148);
      v66 = _mm_add_ps(v54, _mm_mul_ps(v148, v39));
      v67 = _mm_add_ps(v59, v65);
      v139 = _mm_add_ps(v55, v65);
      v68 = (__m128)*(unsigned int *)v127;
      v69 = _mm_add_ps(v56, _mm_mul_ps(v148, v37));
      v70 = _mm_add_ps(v60, _mm_mul_ps(v156, v148));
      v71 = _mm_mul_ps(v172, v148);
      v72 = (__m128)*((unsigned int *)v35 - 4);
      if ( v35 >= v143 )
        v35 = v144;
      v127 += 4;
      v73 = _mm_add_ps(v63, v71);
      v74 = (__m128)*(unsigned int *)v129;
      v158 = v73;
      v75 = (__m128)*(unsigned int *)v131;
      if ( v127 >= v143 )
        v127 = v144 + 1;
      v129 += 4;
      if ( v129 >= v143 )
        v129 = v144 + 2;
      v131 += 4;
      if ( v131 >= v143 )
        v131 = v144 + 3;
      uMaxFrames = io_pBuffer->uMaxFrames;
      v77 = pData[uMaxFrames];
      v78 = 2 * (int)uMaxFrames;
      v79 = 5 * (int)uMaxFrames;
      v80 = pData[v78];
      v81 = 3 * (int)uMaxFrames;
      v82 = pData[v79];
      v83 = pData[v81];
      v141 = _mm_add_ps(
               _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v72, v68), _mm_unpacklo_ps(v74, v75)), v164),
               _mm_mul_ps(v141, v170));
      v84 = 4 * (int)uMaxFrames;
      v85 = _mm_mul_ps(v141, vOutDecorrelationVectorB);
      v86 = _mm_add_ps(v85, v70);
      v87 = _mm_add_ps(v85, v139);
      v88 = pData[v84];
      v89 = _mm_add_ps(_mm_mul_ps(v141, vOutDecorrelationVectorA), v66);
      v90 = _mm_add_ps(v89, _mm_movehl_ps(v89, v89));
      v91 = _mm_add_ps(v87, _mm_movehl_ps(v87, v87));
      v92 = _mm_add_ps(_mm_mul_ps(v141, vOutDecorrelationVectorC), v69);
      v93 = _mm_add_ps(v92, _mm_movehl_ps(v92, v92));
      v94 = _mm_add_ps(_mm_mul_ps(v156, v141), v67);
      v95 = _mm_add_ps(v94, _mm_movehl_ps(v94, v94));
      v96 = _mm_add_ps(_mm_mul_ps(v166, v141), v158);
      v97 = _mm_add_ps(v86, _mm_movehl_ps(v86, v86));
      v98 = _mm_add_ps(v96, _mm_movehl_ps(v96, v96));
      v99 = _mm_add_ps(v141, v159);
      v100 = _mm_add_ps(_mm_movehl_ps(v99, v99), v99);
      v101 = v147;
      v101.m128_f32[0] = v147.m128_f32[0] + v161;
      v147 = v101;
      v102 = v151;
      v103 = _mm_add_ps(_mm_shuffle_ps(v100, v100, 85), v100);
      v102.m128_f32[0] = v151.m128_f32[0] + v163;
      v151 = v102;
      v100.m128_f32[0] = (float)(_mm_shuffle_ps(v90, v90, 85).m128_f32[0] + v90.m128_f32[0]) * v102.m128_f32[0];
      v102.m128_f32[0] = *pData;
      v104 = _mm_mul_ps(_mm_shuffle_ps(v103, v103, 0), v165);
      v105 = (float)(*pData++ + v77) + v83;
      *(pData - 1) = (float)(v102.m128_f32[0] * v147.m128_f32[0]) + v100.m128_f32[0];
      pData[uMaxFrames - 1] = (float)(v77 * v147.m128_f32[0])
                            + (float)((float)(_mm_shuffle_ps(v91, v91, 85).m128_f32[0] + v91.m128_f32[0])
                                    * v151.m128_f32[0]);
      pData[v78 - 1] = (float)(v80 * v147.m128_f32[0])
                     + (float)((float)(_mm_shuffle_ps(v93, v93, 85).m128_f32[0] + v93.m128_f32[0]) * v151.m128_f32[0]);
      v106 = (float)((float)(v80 + v82) + v88) + v105;
      v102.m128_f32[0] = (float)(v82 * v147.m128_f32[0])
                       + (float)((float)(_mm_shuffle_ps(v95, v95, 85).m128_f32[0] + v95.m128_f32[0]) * v151.m128_f32[0]);
      v107 = _mm_add_ps(v104, v21);
      pData[v79 - 1] = v102.m128_f32[0];
      pData[v81 - 1] = (float)(v83 * v147.m128_f32[0])
                     + (float)((float)(_mm_shuffle_ps(v97, v97, 85).m128_f32[0] + v97.m128_f32[0]) * v151.m128_f32[0]);
      v108 = _mm_add_ps(v148, v104);
      pData[v84 - 1] = (float)(v88 * v147.m128_f32[0])
                     + (float)((float)(_mm_shuffle_ps(v98, v98, 85).m128_f32[0] + v98.m128_f32[0]) * v151.m128_f32[0]);
      v109 = _mm_add_ps(v141, v104);
      v110 = _mm_shuffle_ps(v109, _mm_shuffle_ps(v109, v107, 15), 201);
      v111 = _mm_shuffle_ps(v108, _mm_shuffle_ps(v108, v109, 15), 201);
      v112 = _mm_add_ps(v150, v104);
      v113 = _mm_shuffle_ps(v112, _mm_shuffle_ps(v112, v108, 15), 201);
      v114 = _mm_shuffle_ps(v107, _mm_shuffle_ps(v107, v112, 15), 201);
      v9 = (float)((float)(v167 * v153) + v106) - v155;
      v10 = LODWORD(v106);
      v155 = v106;
      v153 = v9;
      if ( m_pfPreDelayStart )
      {
        v115 = *m_pfPreDelayRW;
        *m_pfPreDelayRW++ = v9;
        if ( m_pfPreDelayRW == m_pfPreDelayEnd )
          m_pfPreDelayRW = m_pfPreDelayStart;
      }
      else
      {
        v115 = v9;
      }
      v116 = v169;
      v36 = v128;
      v25 = v138;
      v27 = v137;
      v24 = v135;
      v37 = vOutDecorrelationVectorC;
      v38 = vOutDecorrelationVectorB;
      v39 = vOutDecorrelationVectorA;
      v29 = v136;
      v30 = (float *)v133;
      v7 += 4;
      v116.m128_f32[0] = (float)(v169.m128_f32[0] * v115) + (float)(v171 * v154);
      v117 = _mm_shuffle_ps(v116, v116, 0);
      v40 = v156;
      v8 = LODWORD(v115);
      *((__m128 *)v7 - 1) = _mm_add_ps(v117, v114);
      if ( v7 >= v124 )
        v7 = v128;
      v17 += 4;
      v154 = v115;
      v118 = v117;
      v119 = v117;
      v120 = _mm_add_ps(v117, v110);
      v121 = _mm_add_ps(v118, v113);
      v122 = _mm_add_ps(v119, v111);
      v34 = vOutDecorrelationVectorD;
      v16 = v173;
      v20 = v175;
      *((__m128 *)v17 - 1) = v121;
      v22 = v150;
      *(__m128 *)v18 = v122;
      if ( v17 >= v142 )
        v17 = v132;
      v18 += 4;
      if ( v18 >= v146 )
        v18 = v145;
      *(__m128 *)v19 = v120;
      v26 = v148;
      v19 += 4;
      if ( v19 >= v143 )
        v19 = v144;
      --uValidFrames;
    }
    while ( uValidFrames );
    v32 = v141;
    v140 = v35;
    v4 = this;
    v33 = v140;
  }
  LODWORD(v4->m_fFIRLPFMem) = v8;
  LODWORD(v4->m_fDCFwdMem) = v10;
  v4->m_fDCFbkMem = v9;
  v4->m_pfPreDelayRW = m_pfPreDelayRW;
  v4->m_pfDelayRead[2] = v25;
  v4->m_vIIRLPFMem[0] = v21;
  v4->m_vIIRLPFMem[1] = v22;
  v4->m_vIIRLPFMem[2] = v26;
  v4->m_pfDelayRead[12] = v33;
  v4->m_pfDelayRead[5] = v126;
  v4->m_vIIRLPFMem[3] = v32;
  v4->m_pfDelayRead[13] = v127;
  v4->m_pfDelayRead[9] = v130;
  v4->m_pfDelayRead[14] = v129;
  v4->m_pfDelayRead[10] = v123;
  v4->m_pfDelayRead[11] = v125;
  v4->m_pfDelayWrite[0] = v7;
  v4->m_pfDelayWrite[1] = v17;
  v4->m_pfDelayWrite[2] = v18;
  v4->m_pfDelayWrite[3] = v19;
  v4->m_pfDelayRead[0] = v23;
  v4->m_pfDelayRead[1] = v24;
  v4->m_pfDelayRead[3] = v27;
  v4->m_pfDelayRead[4] = v28;
  v4->m_pfDelayRead[6] = v29;
  v4->m_pfDelayRead[7] = v30;
  v4->m_pfDelayRead[8] = v31;
  v4->m_pfDelayRead[15] = v131;
}

// File Line: 1697
// RVA: 0xACA0E0
void __fastcall CAkFDNReverbFX::ProcessN4(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm11
  float *m_pfPreDelayRW; // rbx
  CAkFDNReverbFX *v4; // r13
  AkAudioBuffer *v5; // r10
  CAkFDNReverbFXParams *m_pParams; // rdx
  unsigned int *pData; // r11
  float *v8; // r15
  float v9; // xmm5_4
  __m128 v10; // xmm3
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm8_4
  float *v14; // r12
  float *v15; // rdi
  float *v16; // rsi
  float v17; // xmm10_4
  float v18; // xmm9_4
  float *v19; // rbp
  float *v20; // r14
  unsigned int m_uNumProcessedChannels; // r9d
  __m128 v22; // xmm12
  float v23; // xmm13_4
  float *v24; // rax
  float v25; // xmm2_4
  __m128 v26; // xmm11
  float v27; // xmm15_4
  float v28; // xmm14_4
  float *v29; // r13
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  __m128 v32; // xmm0
  __m128 v33; // xmm4
  unsigned int v34; // edx
  __int64 v35; // rax
  __int64 v36; // rcx
  int uMaxFrames; // r10d
  unsigned int v38; // edx
  __int64 v39; // r8
  __int128 v40; // xmm0
  __int64 v41; // rcx
  __m128 v42; // xmm1
  __m128 v43; // xmm1
  unsigned int v44; // ecx
  __int64 v45; // rdx
  __m128 v46; // xmm0
  __m128 v47; // xmm2
  __m128 v48; // xmm2
  __int64 v49; // rax
  __int128 v50; // xmm1
  float v51; // xmm1_4
  __m128 v52; // xmm2
  __m128 v53; // xmm2
  float *v54; // rcx
  __int64 v55; // rdx
  float v56; // xmm4_4
  __m128 v57; // xmm1
  float v58; // xmm0_4
  float *v59; // [rsp+0h] [rbp-228h]
  float *m_pfPreDelayEnd; // [rsp+8h] [rbp-220h]
  float *m_pfPreDelayStart; // [rsp+10h] [rbp-218h]
  __m128 v62; // [rsp+20h] [rbp-208h]
  __m128 v63; // [rsp+30h] [rbp-1F8h]
  __int128 v64[8]; // [rsp+40h] [rbp-1E8h]
  __int128 v65; // [rsp+C0h] [rbp-168h]
  char v66; // [rsp+D0h] [rbp-158h] BYREF
  int uValidFrames; // [rsp+248h] [rbp+20h]

  m_pfPreDelayRW = this->m_pfPreDelayRW;
  v4 = this;
  v5 = io_pBuffer;
  m_pParams = this->m_pParams;
  pData = (unsigned int *)v5->pData;
  v8 = this->m_pfDelayStart[0];
  LODWORD(v9) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  v10 = this->m_vIIRLPFMem[0];
  LODWORD(v11) = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0).m128_u32[0];
  LODWORD(v12) = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0).m128_u32[0];
  LODWORD(v13) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  v14 = this->m_pfDelayEnd[0];
  v15 = this->m_pfDelayWrite[0];
  v16 = this->m_pfDelayRead[0];
  LODWORD(v17) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  LODWORD(v18) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFMem), (__m128)LODWORD(this->m_fFIRLPFMem), 0).m128_u32[0];
  v19 = this->m_pfDelayRead[2];
  v20 = this->m_pfDelayRead[3];
  m_uNumProcessedChannels = this->m_uNumProcessedChannels;
  v22 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v23) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  m_pfPreDelayStart = this->m_pfPreDelayStart;
  v24 = this->m_pfDelayRead[1];
  v25 = 1.0 / (float)v5->uMaxFrames;
  v2.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  v26 = _mm_shuffle_ps(v2, v2, 0);
  uValidFrames = v5->uValidFrames;
  v27 = (float)(m_pParams->RTPC.fWetLevel - this->m_fCurrentWet) * v25;
  v28 = (float)(m_pParams->RTPC.fDryLevel - this->m_fCurrentDry) * v25;
  v62 = this->m_vIIRLPFB0[0];
  v63 = this->m_vIIRLPFA1[0];
  if ( v5->uValidFrames )
  {
    v29 = this->m_pfDelayRead[1];
    do
    {
      v30 = (__m128)*(unsigned int *)v16;
      v31 = (__m128)*(unsigned int *)v29;
      v32 = (__m128)*(unsigned int *)v19;
      v16 += 4;
      if ( v16 >= v14 )
        v16 = v8;
      v29 += 4;
      v33 = (__m128)*(unsigned int *)v20;
      if ( v29 >= v14 )
        v29 = v8 + 1;
      v19 += 4;
      if ( v19 >= v14 )
        v19 = v8 + 2;
      v20 += 4;
      if ( v20 >= v14 )
        v20 = v8 + 3;
      v34 = 0;
      v10 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v30, v31), _mm_unpacklo_ps(v32, v33)), v62),
              _mm_mul_ps(v10, v63));
      do
      {
        v35 = v34;
        v36 = v34++;
        v64[v36] = (__int128)_mm_mul_ps(vOutDecorrelationVector[v35][0], v10);
      }
      while ( v34 < m_uNumProcessedChannels );
      uMaxFrames = v5->uMaxFrames;
      v38 = 0;
      v39 = 0i64;
      do
      {
        v40 = pData[v39];
        v41 = v38++;
        v41 *= 2i64;
        v39 = (unsigned int)(uMaxFrames + v39);
        v42 = *(__m128 *)((char *)v64 + 8 * v41);
        *(__int128 *)((char *)&v65 + 8 * v41) = v40;
        v43 = _mm_add_ps(v42, _mm_movehl_ps(v42, v42));
        *(__int128 *)((char *)v64 + 8 * v41) = (__int128)_mm_add_ps(_mm_shuffle_ps(v43, v43, 85), v43);
      }
      while ( v38 < m_uNumProcessedChannels );
      v44 = 0;
      v11 = v11 + v28;
      v12 = v12 + v27;
      v45 = 0i64;
      v46 = _mm_add_ps(_mm_movehl_ps(v10, v10), v10);
      v47 = _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), v46);
      v48 = _mm_shuffle_ps(v47, v47, 0);
      do
      {
        v49 = v44++;
        v49 *= 2i64;
        v50 = *(__int128 *)((char *)&v65 + 8 * v49);
        *(float *)&v50 = (float)(*(float *)&v50 * v11)
                       + (float)(COERCE_FLOAT(*(__int128 *)((char *)v64 + 8 * v49)) * v12);
        pData[v45] = v50;
        v45 = (unsigned int)(uMaxFrames + v45);
        *(__int128 *)((char *)v64 + 8 * v49) = v50;
      }
      while ( v44 < m_uNumProcessedChannels );
      v51 = *(float *)&v65;
      ++pData;
      v52 = _mm_add_ps(_mm_mul_ps(v48, v26), v10);
      v53 = _mm_shuffle_ps(v52, _mm_shuffle_ps(v52, v52, 15), 201);
      if ( m_uNumProcessedChannels > 1 )
      {
        v54 = (float *)&v66;
        v55 = m_uNumProcessedChannels - 1;
        do
        {
          v51 = v51 + *v54;
          v54 += 4;
          --v55;
        }
        while ( v55 );
      }
      v9 = (float)((float)(v17 * v9) + v51) - v13;
      v13 = v51;
      if ( m_pfPreDelayStart )
      {
        v56 = *m_pfPreDelayRW;
        *m_pfPreDelayRW++ = v9;
        if ( m_pfPreDelayRW == m_pfPreDelayEnd )
          m_pfPreDelayRW = m_pfPreDelayStart;
      }
      else
      {
        v56 = v9;
      }
      v5 = io_pBuffer;
      v15 += 4;
      v57 = v22;
      v58 = v23 * v18;
      v18 = v56;
      v57.m128_f32[0] = (float)(v22.m128_f32[0] * v56) + v58;
      *((__m128 *)v15 - 1) = _mm_add_ps(_mm_shuffle_ps(v57, v57, 0), v53);
      if ( v15 >= v14 )
        v15 = v8;
      --uValidFrames;
    }
    while ( uValidFrames );
    v59 = v29;
    v4 = this;
    v24 = v59;
  }
  v4->m_fFIRLPFMem = v18;
  v4->m_fDCFwdMem = v13;
  v4->m_fDCFbkMem = v9;
  v4->m_pfPreDelayRW = m_pfPreDelayRW;
  v4->m_pfDelayWrite[0] = v15;
  v4->m_pfDelayRead[0] = v16;
  v4->m_pfDelayRead[1] = v24;
  v4->m_pfDelayRead[2] = v19;
  v4->m_pfDelayRead[3] = v20;
  v4->m_vIIRLPFMem[0] = v10;
}

// File Line: 1732
// RVA: 0xACA560
void __fastcall CAkFDNReverbFX::ProcessN8(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm4
  __m128 v3; // xmm15
  float *m_pfPreDelayRW; // rdi
  CAkFDNReverbFX *v5; // rbx
  CAkFDNReverbFXParams *m_pParams; // rdx
  unsigned int *pData; // r11
  float *v9; // r9
  float *v10; // r10
  float v11; // xmm8_4
  float v12; // xmm7_4
  float v13; // xmm9_4
  float v14; // xmm11_4
  float v15; // xmm10_4
  float *v16; // rsi
  float *v17; // r14
  float *v18; // r15
  __m128 v19; // xmm13
  float v20; // xmm14_4
  float v21; // xmm12_4
  float *v22; // rbp
  float *v23; // r12
  int uMaxFrames; // eax
  float *v25; // r8
  float *v26; // r13
  float v27; // xmm2_4
  float *v28; // rax
  __m128 fWetLevel_low; // xmm0
  __m128 v30; // xmm15
  float v31; // xmm4_4
  float *v32; // rcx
  float *v33; // rdx
  __m128 v34; // xmm5
  __m128 v35; // xmm6
  unsigned int m_uNumProcessedChannels; // r10d
  float *v37; // rbx
  __m128 v38; // xmm1
  __m128 v39; // xmm0
  __m128 v40; // xmm3
  unsigned int v41; // edx
  __int64 v42; // rax
  __int64 v43; // rcx
  __m128 v44; // xmm1
  __m128 v45; // xmm0
  __m128 v46; // xmm2
  __m128 v47; // xmm3
  unsigned int v48; // edx
  __int64 v49; // rax
  __int64 v50; // rcx
  unsigned int v51; // edx
  int v52; // r9d
  __int64 v53; // r8
  __m128 v54; // xmm2
  __int128 v55; // xmm0
  __int64 v56; // rcx
  __m128 v57; // xmm1
  __m128 v58; // xmm1
  unsigned int v59; // ecx
  __int64 v60; // rdx
  __m128 v61; // xmm0
  __m128 v62; // xmm2
  __m128 v63; // xmm2
  __int64 v64; // rax
  __int128 v65; // xmm1
  __m128 v66; // xmm2
  __m128 v67; // xmm1
  __m128 v68; // xmm3
  __m128 v69; // xmm4
  __m128 v70; // xmm0
  float v71; // xmm1_4
  __m128 v72; // xmm3
  float *v73; // rcx
  __int64 v74; // rdx
  float v75; // xmm2_4
  __m128 v76; // xmm1
  float v77; // xmm0_4
  __m128 *v78; // rdx
  __m128 v79; // xmm0
  __m128 v80; // xmm1
  __m128 *v81; // rdx
  bool v82; // zf
  float *v83; // [rsp+0h] [rbp-298h]
  __m128 *v84; // [rsp+8h] [rbp-290h]
  float *v85; // [rsp+10h] [rbp-288h]
  __m128 *v86; // [rsp+18h] [rbp-280h]
  unsigned __int64 v87; // [rsp+20h] [rbp-278h]
  float *v88; // [rsp+28h] [rbp-270h]
  float *m_pfPreDelayStart; // [rsp+30h] [rbp-268h]
  float *m_pfPreDelayEnd; // [rsp+38h] [rbp-260h]
  unsigned __int64 v91; // [rsp+40h] [rbp-258h]
  float *v92; // [rsp+48h] [rbp-250h]
  __m128 v93; // [rsp+50h] [rbp-248h]
  float v94; // [rsp+60h] [rbp-238h]
  __m128 v95; // [rsp+70h] [rbp-228h]
  float v96; // [rsp+80h] [rbp-218h]
  __m128 v97; // [rsp+90h] [rbp-208h]
  __m128 v98; // [rsp+A0h] [rbp-1F8h]
  __m128 v99[8]; // [rsp+B0h] [rbp-1E8h]
  __int128 v100; // [rsp+130h] [rbp-168h]
  char v101; // [rsp+140h] [rbp-158h] BYREF
  int uValidFrames; // [rsp+2B8h] [rbp+20h]

  m_pfPreDelayRW = this->m_pfPreDelayRW;
  v5 = this;
  m_pParams = this->m_pParams;
  pData = (unsigned int *)io_pBuffer->pData;
  v9 = this->m_pfDelayEnd[1];
  v10 = this->m_pfDelayRead[5];
  LODWORD(v11) = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0).m128_u32[0];
  LODWORD(v12) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  LODWORD(v13) = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0).m128_u32[0];
  LODWORD(v14) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFMem), (__m128)LODWORD(this->m_fFIRLPFMem), 0).m128_u32[0];
  LODWORD(v15) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  v16 = this->m_pfDelayRead[0];
  v17 = this->m_pfDelayRead[2];
  v18 = this->m_pfDelayRead[3];
  v19 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v20) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  LODWORD(v21) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  v22 = this->m_pfDelayRead[4];
  v23 = this->m_pfDelayRead[6];
  uMaxFrames = io_pBuffer->uMaxFrames;
  v25 = this->m_pfDelayStart[1];
  v26 = this->m_pfDelayRead[7];
  v92 = v25;
  v87 = (unsigned __int64)v9;
  v27 = 1.0 / (float)uMaxFrames;
  m_pfPreDelayStart = this->m_pfPreDelayStart;
  v28 = this->m_pfDelayStart[0];
  fWetLevel_low = (__m128)LODWORD(m_pParams->RTPC.fWetLevel);
  v3.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  v30 = _mm_shuffle_ps(v3, v3, 0);
  fWetLevel_low.m128_f32[0] = (float)(fWetLevel_low.m128_f32[0] - this->m_fCurrentWet) * v27;
  v86 = (__m128 *)this->m_pfDelayWrite[0];
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  v2.m128_f32[0] = (float)(m_pParams->RTPC.fDryLevel - this->m_fCurrentDry) * v27;
  LODWORD(v31) = _mm_shuffle_ps(v2, v2, 0).m128_u32[0];
  v32 = this->m_pfDelayEnd[0];
  v84 = (__m128 *)v5->m_pfDelayWrite[1];
  v33 = v5->m_pfDelayRead[1];
  v96 = v31;
  LODWORD(v94) = _mm_shuffle_ps(fWetLevel_low, fWetLevel_low, 0).m128_u32[0];
  v88 = v28;
  v91 = (unsigned __int64)v32;
  v85 = v10;
  v34 = v5->m_vIIRLPFMem[0];
  v35 = v5->m_vIIRLPFMem[1];
  v95 = v5->m_vIIRLPFB0[0];
  uValidFrames = io_pBuffer->uValidFrames;
  m_uNumProcessedChannels = v5->m_uNumProcessedChannels;
  v98 = v5->m_vIIRLPFB0[1];
  v93 = v5->m_vIIRLPFA1[0];
  v97 = v5->m_vIIRLPFA1[1];
  if ( io_pBuffer->uValidFrames )
  {
    v37 = v5->m_pfDelayRead[1];
    do
    {
      v38 = (__m128)*(unsigned int *)v16;
      v39 = (__m128)*(unsigned int *)v17;
      v16 += 4;
      if ( v16 >= v32 )
        v16 = v28;
      v83 = v37 + 4;
      v40 = (__m128)*(unsigned int *)v18;
      if ( v37 + 4 >= v32 )
        v83 = v28 + 1;
      v17 += 4;
      if ( v17 >= v32 )
        v17 = v28 + 2;
      v18 += 4;
      if ( v18 >= v32 )
        v18 = v28 + 3;
      v41 = 0;
      v34 = _mm_add_ps(
              _mm_mul_ps(
                _mm_movelh_ps(_mm_unpacklo_ps(v38, (__m128)*(unsigned int *)v37), _mm_unpacklo_ps(v39, v40)),
                v95),
              _mm_mul_ps(v34, v93));
      do
      {
        v42 = v41;
        v43 = v41++;
        v99[v43] = _mm_mul_ps(vOutDecorrelationVector[v42][0], v34);
      }
      while ( v41 < m_uNumProcessedChannels );
      v44 = (__m128)*(unsigned int *)v22;
      v45 = (__m128)*(unsigned int *)v23;
      v37 = v83;
      v22 += 4;
      v46 = (__m128)*(unsigned int *)v85;
      v47 = (__m128)*(unsigned int *)v26;
      if ( v22 >= v9 )
        v22 = v25;
      v85 += 4;
      if ( v85 >= v9 )
        v85 = v25 + 1;
      v23 += 4;
      if ( v23 >= v9 )
        v23 = v25 + 2;
      v26 += 4;
      if ( v26 >= v9 )
        v26 = v25 + 3;
      v48 = 0;
      v35 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v44, v46), _mm_unpacklo_ps(v45, v47)), v98),
              _mm_mul_ps(v35, v97));
      do
      {
        v49 = v48;
        v50 = v48++;
        v99[v50] = _mm_add_ps(_mm_mul_ps(vOutDecorrelationVector[v49][1], v35), v99[v50]);
      }
      while ( v48 < m_uNumProcessedChannels );
      v51 = 0;
      v52 = io_pBuffer->uMaxFrames;
      v53 = 0i64;
      v54 = _mm_add_ps(v35, v34);
      do
      {
        v55 = pData[v53];
        v56 = v51++;
        v56 *= 2i64;
        v53 = (unsigned int)(v52 + v53);
        v57 = *(__m128 *)((char *)v99 + 8 * v56);
        *(__int128 *)((char *)&v100 + 8 * v56) = v55;
        v58 = _mm_add_ps(v57, _mm_movehl_ps(v57, v57));
        *(__m128 *)((char *)v99 + 8 * v56) = _mm_add_ps(_mm_shuffle_ps(v58, v58, 85), v58);
      }
      while ( v51 < m_uNumProcessedChannels );
      v13 = v13 + v94;
      v59 = 0;
      v60 = 0i64;
      v61 = _mm_add_ps(_mm_movehl_ps(v54, v54), v54);
      v11 = v11 + v31;
      v62 = _mm_add_ps(_mm_shuffle_ps(v61, v61, 85), v61);
      v63 = _mm_shuffle_ps(v62, v62, 0);
      do
      {
        v64 = v59++;
        v64 *= 2i64;
        v65 = *(__int128 *)((char *)&v100 + 8 * v64);
        *(float *)&v65 = (float)(*(float *)&v65 * v11) + (float)(COERCE_FLOAT(*(_OWORD *)((char *)v99 + 8 * v64)) * v13);
        pData[v60] = v65;
        v60 = (unsigned int)(v52 + v60);
        *(__m128 *)((char *)v99 + 8 * v64) = (__m128)v65;
      }
      while ( v59 < m_uNumProcessedChannels );
      v66 = _mm_mul_ps(v63, v30);
      ++pData;
      v67 = _mm_add_ps(v35, v66);
      v68 = _mm_add_ps(v66, v34);
      v69 = _mm_shuffle_ps(v67, _mm_shuffle_ps(v67, v68, 15), 201);
      v70 = _mm_shuffle_ps(v68, v67, 15);
      v71 = *(float *)&v100;
      v72 = _mm_shuffle_ps(v68, v70, 201);
      if ( m_uNumProcessedChannels > 1 )
      {
        v73 = (float *)&v101;
        v74 = m_uNumProcessedChannels - 1;
        do
        {
          v71 = v71 + *v73;
          v73 += 4;
          --v74;
        }
        while ( v74 );
      }
      v12 = (float)((float)(v21 * v12) + v71) - v15;
      v15 = v71;
      if ( m_pfPreDelayStart )
      {
        v75 = *m_pfPreDelayRW;
        *m_pfPreDelayRW++ = v12;
        if ( m_pfPreDelayRW == m_pfPreDelayEnd )
          m_pfPreDelayRW = m_pfPreDelayStart;
      }
      else
      {
        v75 = v12;
      }
      v32 = (float *)v91;
      v76 = v19;
      v77 = v20 * v14;
      v14 = v75;
      v9 = (float *)v87;
      v25 = v92;
      v78 = v86 + 1;
      v76.m128_f32[0] = (float)(v19.m128_f32[0] * v75) + v77;
      v79 = _mm_shuffle_ps(v76, v76, 0);
      v80 = _mm_add_ps(v79, v69);
      v31 = v96;
      *v86 = _mm_add_ps(v79, v72);
      *v84 = v80;
      v28 = v88;
      if ( (unsigned __int64)&v86[1] >= v91 )
        v78 = (__m128 *)v88;
      v86 = v78;
      v81 = v84 + 1;
      if ( (unsigned __int64)&v84[1] >= v87 )
        v81 = (__m128 *)v92;
      v82 = uValidFrames-- == 1;
      v84 = v81;
    }
    while ( !v82 );
    v5 = this;
    v33 = v83;
  }
  v5->m_fFIRLPFMem = v14;
  v5->m_fDCFwdMem = v15;
  v5->m_fDCFbkMem = v12;
  v5->m_pfPreDelayRW = m_pfPreDelayRW;
  v5->m_pfDelayWrite[0] = (float *)v86;
  v5->m_pfDelayRead[0] = v16;
  v5->m_pfDelayRead[1] = v33;
  v5->m_vIIRLPFMem[1] = v35;
  v5->m_vIIRLPFMem[0] = v34;
  v5->m_pfDelayWrite[1] = (float *)v84;
  v5->m_pfDelayRead[2] = v17;
  v5->m_pfDelayRead[3] = v18;
  v5->m_pfDelayRead[4] = v22;
  v5->m_pfDelayRead[6] = v23;
  v5->m_pfDelayRead[5] = v85;
  v5->m_pfDelayRead[7] = v26;
}

// File Line: 1777
// RVA: 0xACABE0
void __fastcall CAkFDNReverbFX::ProcessN12(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm5
  __m128 v3; // xmm1
  float *m_pfPreDelayRW; // rdi
  CAkFDNReverbFX *v5; // r11
  CAkFDNReverbFXParams *m_pParams; // rdx
  float *v8; // r9
  unsigned int *pData; // rbx
  float v10; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm9_4
  float v13; // xmm12_4
  float v14; // xmm13_4
  float v15; // xmm14_4
  __m128 v16; // xmm0
  float v17; // xmm2_4
  __m128 fWetLevel_low; // xmm0
  float *v19; // rcx
  float v20; // xmm5_4
  float *v21; // rdx
  __m128 v22; // xmm4
  float *v23; // rsi
  __m128 v24; // xmm15
  __m128 v25; // xmm6
  __m128 v26; // xmm7
  float *v27; // r14
  float *v28; // r15
  float *v29; // rbp
  __m128 v30; // xmm8
  float *v31; // r12
  float *v32; // r13
  float *v33; // r8
  unsigned int m_uNumProcessedChannels; // r10d
  float *v35; // rax
  __m128 v36; // xmm1
  __m128 v37; // xmm0
  __m128 v38; // xmm3
  __m128 v39; // xmm2
  unsigned int v40; // edx
  __int64 v41; // rax
  __int64 v42; // rcx
  __m128 v43; // xmm1
  __m128 v44; // xmm0
  __m128 v45; // xmm3
  float *v46; // r11
  __m128 v47; // xmm2
  unsigned int v48; // edx
  __int64 v49; // rax
  __int64 v50; // rcx
  __m128 v51; // xmm0
  __m128 v52; // xmm1
  __m128 v53; // xmm2
  __m128 v54; // xmm4
  float *v55; // rcx
  unsigned int v56; // edx
  __int64 v57; // rax
  __int64 v58; // rcx
  unsigned int v59; // edx
  __m128 v60; // xmm4
  int uMaxFrames; // r9d
  __int64 v62; // r8
  __int128 v63; // xmm0
  __int64 v64; // rcx
  __m128 v65; // xmm1
  __m128 v66; // xmm1
  unsigned int v67; // ecx
  __int64 v68; // rdx
  __m128 v69; // xmm0
  __m128 v70; // xmm3
  __m128 v71; // xmm3
  __int64 v72; // rax
  __int128 v73; // xmm1
  __m128 v74; // xmm3
  __m128 v75; // xmm2
  __m128 v76; // xmm1
  __m128 v77; // xmm4
  __m128 v78; // xmm5
  __m128 v79; // xmm3
  __m128 v80; // xmm0
  float v81; // xmm1_4
  __m128 v82; // xmm4
  float *v83; // rcx
  __int64 v84; // rdx
  float v85; // xmm1_4
  __m128 v86; // xmm2
  __m128 *v87; // rax
  float v88; // xmm0_4
  __m128 v89; // xmm1
  __m128 v90; // xmm2
  __m128 v91; // xmm0
  __m128 *v92; // r8
  float *m128_f32; // r8
  bool v94; // zf
  float *v95; // [rsp+0h] [rbp-318h]
  float *v96; // [rsp+8h] [rbp-310h]
  float *v97; // [rsp+10h] [rbp-308h]
  __m128 *v98; // [rsp+18h] [rbp-300h]
  float *v99; // [rsp+20h] [rbp-2F8h]
  float *v100; // [rsp+28h] [rbp-2F0h]
  __m128 *v101; // [rsp+30h] [rbp-2E8h]
  float *v102; // [rsp+38h] [rbp-2E0h]
  __m128 *v103; // [rsp+40h] [rbp-2D8h]
  unsigned __int64 v104; // [rsp+48h] [rbp-2D0h]
  unsigned __int64 v105; // [rsp+50h] [rbp-2C8h]
  float *v106; // [rsp+58h] [rbp-2C0h]
  float *v107; // [rsp+60h] [rbp-2B8h]
  float *m_pfPreDelayStart; // [rsp+68h] [rbp-2B0h]
  float *v109; // [rsp+70h] [rbp-2A8h]
  float *m_pfPreDelayEnd; // [rsp+78h] [rbp-2A0h]
  float *v111; // [rsp+80h] [rbp-298h]
  float v112; // [rsp+90h] [rbp-288h]
  __m128 v113; // [rsp+A0h] [rbp-278h]
  __m128 v114; // [rsp+B0h] [rbp-268h]
  float v115; // [rsp+C0h] [rbp-258h]
  __m128 v116; // [rsp+D0h] [rbp-248h]
  __m128 v117; // [rsp+E0h] [rbp-238h]
  __m128 v118; // [rsp+F0h] [rbp-228h]
  float v119; // [rsp+100h] [rbp-218h]
  __m128 v120; // [rsp+110h] [rbp-208h]
  __m128 v121; // [rsp+120h] [rbp-1F8h]
  __m128 v122[8]; // [rsp+130h] [rbp-1E8h]
  __int128 v123; // [rsp+1B0h] [rbp-168h]
  char v124; // [rsp+1C0h] [rbp-158h] BYREF
  int uValidFrames; // [rsp+338h] [rbp+20h]

  v3 = (__m128)LODWORD(FLOAT_N2_0);
  m_pfPreDelayRW = this->m_pfPreDelayRW;
  v5 = this;
  m_pParams = this->m_pParams;
  v8 = this->m_pfDelayStart[1];
  pData = (unsigned int *)io_pBuffer->pData;
  v111 = v8;
  LODWORD(v10) = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0).m128_u32[0];
  LODWORD(v11) = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0).m128_u32[0];
  LODWORD(v12) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  v113 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v13) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  LODWORD(v14) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  LODWORD(v115) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  LODWORD(v15) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFMem), (__m128)LODWORD(this->m_fFIRLPFMem), 0).m128_u32[0];
  v3.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  v16 = v3;
  v3.m128_f32[0] = m_pParams->RTPC.fDryLevel - this->m_fCurrentDry;
  v118 = _mm_shuffle_ps(v16, v16, 0);
  m_pfPreDelayStart = this->m_pfPreDelayStart;
  v107 = this->m_pfDelayStart[2];
  v17 = 1.0 / (float)io_pBuffer->uMaxFrames;
  fWetLevel_low = (__m128)LODWORD(m_pParams->RTPC.fWetLevel);
  v106 = this->m_pfDelayEnd[1];
  fWetLevel_low.m128_f32[0] = (float)(fWetLevel_low.m128_f32[0] - this->m_fCurrentWet) * v17;
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  v19 = this->m_pfDelayStart[0];
  v2.m128_f32[0] = v3.m128_f32[0] * v17;
  LODWORD(v20) = _mm_shuffle_ps(v2, v2, 0).m128_u32[0];
  v101 = (__m128 *)v5->m_pfDelayWrite[0];
  v104 = (unsigned __int64)v5->m_pfDelayEnd[0];
  v119 = v20;
  LODWORD(v112) = _mm_shuffle_ps(fWetLevel_low, fWetLevel_low, 0).m128_u32[0];
  v103 = (__m128 *)v5->m_pfDelayWrite[1];
  v109 = v19;
  v105 = (unsigned __int64)v5->m_pfDelayEnd[2];
  v98 = (__m128 *)v5->m_pfDelayWrite[2];
  v21 = v5->m_pfDelayRead[8];
  v22 = v5->m_vIIRLPFA1[0];
  v23 = v5->m_pfDelayRead[0];
  v24 = v5->m_vIIRLPFB0[0];
  v25 = v5->m_vIIRLPFMem[0];
  v26 = v5->m_vIIRLPFMem[1];
  v27 = v5->m_pfDelayRead[2];
  v28 = v5->m_pfDelayRead[3];
  v29 = v5->m_pfDelayRead[4];
  v30 = v5->m_vIIRLPFMem[2];
  v120 = v5->m_vIIRLPFB0[1];
  v31 = v5->m_pfDelayRead[6];
  v32 = v5->m_pfDelayRead[7];
  v33 = v5->m_pfDelayRead[11];
  v121 = v5->m_vIIRLPFB0[2];
  v117 = v22;
  v96 = v5->m_pfDelayRead[1];
  uValidFrames = io_pBuffer->uValidFrames;
  v114 = v5->m_vIIRLPFA1[1];
  m_uNumProcessedChannels = v5->m_uNumProcessedChannels;
  v97 = v5->m_pfDelayRead[5];
  v116 = v5->m_vIIRLPFA1[2];
  v100 = v21;
  v99 = v5->m_pfDelayRead[9];
  v35 = v5->m_pfDelayRead[10];
  v95 = v35;
  if ( uValidFrames )
  {
    do
    {
      v36 = (__m128)*(unsigned int *)v23;
      v37 = (__m128)*(unsigned int *)v27;
      v38 = (__m128)*(unsigned int *)v28;
      v23 += 4;
      if ( (unsigned __int64)v23 >= v104 )
        v23 = v19;
      v39 = (__m128)*(unsigned int *)v96;
      v96 += 4;
      if ( (unsigned __int64)v96 >= v104 )
        v96 = v19 + 1;
      v27 += 4;
      if ( (unsigned __int64)v27 >= v104 )
        v27 = v19 + 2;
      v28 += 4;
      if ( (unsigned __int64)v28 >= v104 )
        v28 = v19 + 3;
      v40 = 0;
      v25 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v36, v39), _mm_unpacklo_ps(v37, v38)), v24),
              _mm_mul_ps(v25, v22));
      do
      {
        v41 = v40;
        v42 = v40++;
        v122[v42] = _mm_mul_ps(vOutDecorrelationVector[v41][0], v25);
      }
      while ( v40 < m_uNumProcessedChannels );
      v43 = (__m128)*(unsigned int *)v29;
      v44 = (__m128)*(unsigned int *)v31;
      v45 = (__m128)*(unsigned int *)v32;
      v46 = v95;
      v29 += 4;
      v47 = (__m128)*(unsigned int *)v97;
      if ( v29 >= v106 )
        v29 = v8;
      v97 += 4;
      if ( v97 >= v106 )
        v97 = v8 + 1;
      v31 += 4;
      if ( v31 >= v106 )
        v31 = v8 + 2;
      v32 += 4;
      if ( v32 >= v106 )
        v32 = v8 + 3;
      v48 = 0;
      v26 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v43, v47), _mm_unpacklo_ps(v44, v45)), v120),
              _mm_mul_ps(v26, v114));
      do
      {
        v49 = v48;
        v50 = v48++;
        v122[v50] = _mm_add_ps(_mm_mul_ps(vOutDecorrelationVector[v49][1], v26), v122[v50]);
      }
      while ( v48 < m_uNumProcessedChannels );
      v51 = (__m128)*(unsigned int *)v95;
      v52 = (__m128)*(unsigned int *)v100;
      v53 = (__m128)*(unsigned int *)v99;
      v54 = _mm_add_ps(v26, v25);
      v55 = v100 + 4;
      if ( (unsigned __int64)(v100 + 4) >= v105 )
        v55 = v107;
      v100 = v55;
      v99 += 4;
      if ( (unsigned __int64)v99 >= v105 )
        v99 = v107 + 1;
      v95 += 4;
      if ( (unsigned __int64)(v46 + 4) >= v105 )
        v95 = v107 + 2;
      v102 = v33 + 4;
      if ( (unsigned __int64)(v33 + 4) >= v105 )
        v102 = v107 + 3;
      v56 = 0;
      v30 = _mm_add_ps(
              _mm_mul_ps(
                _mm_movelh_ps(_mm_unpacklo_ps(v52, v53), _mm_unpacklo_ps(v51, (__m128)*(unsigned int *)v33)),
                v121),
              _mm_mul_ps(v30, v116));
      do
      {
        v57 = v56;
        v58 = v56++;
        v122[v58] = _mm_add_ps(_mm_mul_ps(vOutDecorrelationVector[v57][2], v30), v122[v58]);
      }
      while ( v56 < m_uNumProcessedChannels );
      v59 = 0;
      v60 = _mm_add_ps(v54, v30);
      uMaxFrames = io_pBuffer->uMaxFrames;
      v62 = 0i64;
      do
      {
        v63 = pData[v62];
        v64 = v59++;
        v64 *= 2i64;
        v62 = (unsigned int)(uMaxFrames + v62);
        v65 = *(__m128 *)((char *)v122 + 8 * v64);
        *(__int128 *)((char *)&v123 + 8 * v64) = v63;
        v66 = _mm_add_ps(v65, _mm_movehl_ps(v65, v65));
        *(__m128 *)((char *)v122 + 8 * v64) = _mm_add_ps(_mm_shuffle_ps(v66, v66, 85), v66);
      }
      while ( v59 < m_uNumProcessedChannels );
      v11 = v11 + v112;
      v67 = 0;
      v68 = 0i64;
      v69 = _mm_add_ps(_mm_movehl_ps(v60, v60), v60);
      v10 = v10 + v20;
      v70 = _mm_add_ps(_mm_shuffle_ps(v69, v69, 85), v69);
      v71 = _mm_shuffle_ps(v70, v70, 0);
      do
      {
        v72 = v67++;
        v72 *= 2i64;
        v73 = *(__int128 *)((char *)&v123 + 8 * v72);
        *(float *)&v73 = (float)(*(float *)&v73 * v10)
                       + (float)(COERCE_FLOAT(*(_OWORD *)((char *)v122 + 8 * v72)) * v11);
        pData[v68] = v73;
        v68 = (unsigned int)(uMaxFrames + v68);
        *(__m128 *)((char *)v122 + 8 * v72) = (__m128)v73;
      }
      while ( v67 < m_uNumProcessedChannels );
      v74 = _mm_mul_ps(v71, v118);
      ++pData;
      v75 = _mm_add_ps(v30, v74);
      v76 = _mm_add_ps(v26, v74);
      v77 = _mm_add_ps(v74, v25);
      v78 = _mm_shuffle_ps(v75, _mm_shuffle_ps(v75, v77, 15), 201);
      v79 = _mm_shuffle_ps(v76, _mm_shuffle_ps(v76, v75, 15), 201);
      v80 = _mm_shuffle_ps(v77, v76, 15);
      v81 = *(float *)&v123;
      v82 = _mm_shuffle_ps(v77, v80, 201);
      if ( m_uNumProcessedChannels > 1 )
      {
        v83 = (float *)&v124;
        v84 = m_uNumProcessedChannels - 1;
        do
        {
          v81 = v81 + *v83;
          v83 += 4;
          --v84;
        }
        while ( v84 );
      }
      v12 = (float)((float)(v14 * v12) + v81) - v13;
      v13 = v81;
      if ( m_pfPreDelayStart )
      {
        v85 = *m_pfPreDelayRW;
        *m_pfPreDelayRW++ = v12;
        if ( m_pfPreDelayRW == m_pfPreDelayEnd )
          m_pfPreDelayRW = m_pfPreDelayStart;
      }
      else
      {
        v85 = v12;
      }
      v86 = v113;
      v8 = v111;
      v87 = v101 + 1;
      v88 = v115 * v15;
      v15 = v85;
      v86.m128_f32[0] = (float)(v113.m128_f32[0] * v85) + v88;
      v89 = _mm_shuffle_ps(v86, v86, 0);
      v90 = _mm_add_ps(v89, v78);
      v20 = v119;
      v91 = _mm_add_ps(v89, v82);
      v22 = v117;
      *v101 = v91;
      *v103 = _mm_add_ps(v89, v79);
      *v98 = v90;
      v19 = v109;
      if ( (unsigned __int64)&v101[1] >= v104 )
        v87 = (__m128 *)v109;
      v92 = v103 + 1;
      v101 = v87;
      if ( &v103[1] >= (__m128 *)v106 )
        v92 = (__m128 *)v111;
      v103 = v92;
      m128_f32 = v98[1].m128_f32;
      if ( (unsigned __int64)&v98[1] >= v105 )
        m128_f32 = v107;
      v94 = uValidFrames-- == 1;
      v98 = (__m128 *)m128_f32;
      v33 = v102;
    }
    while ( !v94 );
    v5 = this;
    v35 = v95;
    v21 = v100;
  }
  v5->m_fFIRLPFMem = v15;
  v5->m_fDCFwdMem = v13;
  v5->m_fDCFbkMem = v12;
  v5->m_pfPreDelayRW = m_pfPreDelayRW;
  v5->m_pfDelayWrite[0] = (float *)v101;
  v5->m_vIIRLPFMem[0] = v25;
  v5->m_vIIRLPFMem[1] = v26;
  v5->m_vIIRLPFMem[2] = v30;
  v5->m_pfDelayWrite[1] = (float *)v103;
  v5->m_pfDelayRead[0] = v23;
  v5->m_pfDelayWrite[2] = (float *)v98;
  v5->m_pfDelayRead[2] = v27;
  v5->m_pfDelayRead[1] = v96;
  v5->m_pfDelayRead[3] = v28;
  v5->m_pfDelayRead[5] = v97;
  v5->m_pfDelayRead[4] = v29;
  v5->m_pfDelayRead[6] = v31;
  v5->m_pfDelayRead[7] = v32;
  v5->m_pfDelayRead[8] = v21;
  v5->m_pfDelayRead[9] = v99;
  v5->m_pfDelayRead[10] = v35;
  v5->m_pfDelayRead[11] = v33;
}

// File Line: 1832
// RVA: 0xACB470
void __fastcall CAkFDNReverbFX::ProcessN16(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm5
  __m128 v3; // xmm6
  __m128 v4; // xmm1
  float *m_pfPreDelayRW; // rbp
  CAkFDNReverbFX *v6; // r11
  CAkFDNReverbFXParams *m_pParams; // rdx
  unsigned int *pData; // rbx
  float v10; // xmm12_4
  float v11; // xmm11_4
  float v12; // xmm15_4
  float v13; // xmm13_4
  float v14; // xmm14_4
  float v15; // xmm2_4
  float v16; // xmm6_4
  unsigned int v17; // xmm0_4
  float v18; // xmm5_4
  float *v19; // r9
  float *v20; // rdx
  __m128 v21; // xmm4
  __m128 v22; // xmm7
  __m128 v23; // xmm8
  float *v24; // rdi
  float *v25; // r14
  float *v26; // r15
  __m128 v27; // xmm10
  __m128 v28; // xmm9
  float *v29; // rsi
  float *v30; // r12
  float *v31; // r13
  float *v32; // r8
  unsigned int m_uNumProcessedChannels; // r10d
  float *v34; // rcx
  float *v35; // rax
  float *v36; // r11
  float *v37; // rax
  __m128 v38; // xmm1
  __m128 v39; // xmm0
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  unsigned int v42; // edx
  __int64 v43; // rax
  __int64 v44; // rcx
  __m128 v45; // xmm1
  __m128 v46; // xmm0
  __m128 v47; // xmm3
  __m128 v48; // xmm2
  unsigned int v49; // edx
  __int64 v50; // rax
  __int64 v51; // rcx
  __m128 v52; // xmm1
  float *v53; // rax
  __m128 v54; // xmm2
  __m128 v55; // xmm4
  __m128 v56; // xmm3
  unsigned int v57; // edx
  __int64 v58; // rax
  __int64 v59; // rcx
  __m128 v60; // xmm4
  __m128 v61; // xmm1
  __m128 v62; // xmm2
  __m128 v63; // xmm0
  __m128 v64; // xmm3
  float *v65; // rdx
  unsigned int v66; // edx
  __int64 v67; // rax
  __int64 v68; // rcx
  unsigned int v69; // edx
  __m128 v70; // xmm4
  int uMaxFrames; // r9d
  __int64 v72; // r8
  __int128 v73; // xmm0
  __int64 v74; // rcx
  __m128 v75; // xmm1
  __m128 v76; // xmm1
  unsigned int v77; // ecx
  __int64 v78; // rdx
  __m128 v79; // xmm0
  __m128 v80; // xmm3
  __m128 v81; // xmm3
  __int64 v82; // rax
  __int128 v83; // xmm1
  __m128 v84; // xmm3
  __m128 v85; // xmm1
  __m128 v86; // xmm2
  __m128 v87; // xmm4
  __m128 v88; // xmm5
  __m128 v89; // xmm6
  __m128 v90; // xmm1
  __m128 v91; // xmm3
  __m128 v92; // xmm0
  float v93; // xmm1_4
  __m128 v94; // xmm4
  float *v95; // rcx
  __int64 v96; // rdx
  float v97; // xmm1_4
  __m128 v98; // xmm2
  float v99; // xmm0_4
  float *v100; // rcx
  __m128 v101; // xmm2
  __m128 v102; // xmm0
  __m128 *v103; // rdx
  __m128 v104; // xmm0
  float *v105; // r8
  __m128 v106; // xmm2
  float *v107; // r9
  bool v108; // zf
  float *v109; // [rsp+0h] [rbp-388h]
  float *v110; // [rsp+8h] [rbp-380h]
  float *v111; // [rsp+10h] [rbp-378h]
  float *v112; // [rsp+18h] [rbp-370h]
  float *v113; // [rsp+20h] [rbp-368h]
  float *v114; // [rsp+28h] [rbp-360h]
  float *v115; // [rsp+30h] [rbp-358h]
  float *v116; // [rsp+38h] [rbp-350h]
  __m128 *v117; // [rsp+40h] [rbp-348h]
  float *v118; // [rsp+48h] [rbp-340h]
  float *v119; // [rsp+50h] [rbp-338h]
  float *v120; // [rsp+58h] [rbp-330h]
  float *v121; // [rsp+60h] [rbp-328h]
  float *v122; // [rsp+68h] [rbp-320h]
  float *v123; // [rsp+70h] [rbp-318h]
  float *v124; // [rsp+78h] [rbp-310h]
  float *v125; // [rsp+80h] [rbp-308h]
  float *v126; // [rsp+88h] [rbp-300h]
  float *v127; // [rsp+90h] [rbp-2F8h]
  float *v128; // [rsp+98h] [rbp-2F0h]
  float *v129; // [rsp+A0h] [rbp-2E8h]
  float *v130; // [rsp+A8h] [rbp-2E0h]
  float *m_pfPreDelayEnd; // [rsp+B0h] [rbp-2D8h]
  float *m_pfPreDelayStart; // [rsp+B8h] [rbp-2D0h]
  float v133; // [rsp+C0h] [rbp-2C8h]
  __m128 v134; // [rsp+D0h] [rbp-2B8h]
  __m128 v135; // [rsp+E0h] [rbp-2A8h]
  __m128 v136; // [rsp+F0h] [rbp-298h]
  __m128 v137; // [rsp+100h] [rbp-288h]
  float v138; // [rsp+110h] [rbp-278h]
  __m128 v139; // [rsp+120h] [rbp-268h]
  float v140; // [rsp+130h] [rbp-258h]
  __m128 v141; // [rsp+140h] [rbp-248h]
  float v142; // [rsp+150h] [rbp-238h]
  __m128 v143; // [rsp+160h] [rbp-228h]
  __m128 v144; // [rsp+170h] [rbp-218h]
  __m128 v145; // [rsp+180h] [rbp-208h]
  __m128 v146; // [rsp+190h] [rbp-1F8h]
  __m128 v147[8]; // [rsp+1A0h] [rbp-1E8h]
  __int128 v148; // [rsp+220h] [rbp-168h]
  char v149; // [rsp+230h] [rbp-158h] BYREF
  int uValidFrames; // [rsp+3A8h] [rbp+20h]

  v4 = (__m128)LODWORD(FLOAT_N2_0);
  m_pfPreDelayRW = this->m_pfPreDelayRW;
  v6 = this;
  m_pParams = this->m_pParams;
  pData = (unsigned int *)io_pBuffer->pData;
  v136 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v138) = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB1), (__m128)LODWORD(this->m_fFIRLPFB1), 0).m128_u32[0];
  LODWORD(v10) = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0).m128_u32[0];
  LODWORD(v11) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFbkMem), (__m128)LODWORD(this->m_fDCFbkMem), 0).m128_u32[0];
  LODWORD(v12) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCCoef), (__m128)LODWORD(this->m_fDCCoef), 0).m128_u32[0];
  LODWORD(v13) = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0).m128_u32[0];
  LODWORD(v14) = _mm_shuffle_ps((__m128)LODWORD(this->m_fDCFwdMem), (__m128)LODWORD(this->m_fDCFwdMem), 0).m128_u32[0];
  v4.m128_f32[0] = -2.0 / (float)(int)m_pParams->NonRTPC.uNumberOfDelays;
  v135 = _mm_shuffle_ps(v4, v4, 0);
  m_pfPreDelayStart = this->m_pfPreDelayStart;
  v126 = this->m_pfDelayStart[0];
  v15 = 1.0 / (float)io_pBuffer->uMaxFrames;
  v130 = this->m_pfDelayEnd[0];
  v116 = this->m_pfDelayStart[2];
  v3.m128_f32[0] = (float)(m_pParams->RTPC.fWetLevel - this->m_fCurrentWet) * v15;
  LODWORD(v16) = _mm_shuffle_ps(v3, v3, 0).m128_u32[0];
  v17 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFMem), (__m128)LODWORD(this->m_fFIRLPFMem), 0).m128_u32[0];
  v2.m128_f32[0] = (float)(m_pParams->RTPC.fDryLevel - this->m_fCurrentDry) * v15;
  m_pfPreDelayEnd = this->m_pfPreDelayEnd;
  v124 = this->m_pfDelayEnd[2];
  v142 = v16;
  v133 = *(float *)&v17;
  LODWORD(v18) = _mm_shuffle_ps(v2, v2, 0).m128_u32[0];
  v128 = this->m_pfDelayStart[1];
  v140 = v18;
  v127 = this->m_pfDelayStart[3];
  v129 = this->m_pfDelayEnd[1];
  v125 = this->m_pfDelayEnd[3];
  v19 = this->m_pfDelayRead[11];
  v20 = this->m_pfDelayRead[15];
  v21 = this->m_vIIRLPFB0[0];
  v22 = this->m_vIIRLPFMem[0];
  v23 = this->m_vIIRLPFMem[1];
  v24 = this->m_pfDelayRead[0];
  v25 = this->m_pfDelayRead[2];
  v26 = this->m_pfDelayRead[3];
  v27 = this->m_vIIRLPFMem[2];
  v28 = this->m_vIIRLPFMem[3];
  v145 = this->m_vIIRLPFB0[1];
  v144 = v21;
  v29 = this->m_pfDelayRead[4];
  v30 = this->m_pfDelayRead[6];
  v31 = this->m_pfDelayRead[7];
  v143 = this->m_vIIRLPFB0[2];
  v32 = this->m_pfDelayRead[10];
  v120 = this->m_pfDelayWrite[0];
  v146 = this->m_vIIRLPFB0[3];
  v137 = this->m_vIIRLPFA1[0];
  v117 = (__m128 *)this->m_pfDelayWrite[1];
  v115 = this->m_pfDelayRead[9];
  v134 = this->m_vIIRLPFA1[1];
  v119 = this->m_pfDelayWrite[2];
  v139 = this->m_vIIRLPFA1[2];
  v141 = this->m_vIIRLPFA1[3];
  v121 = this->m_pfDelayWrite[3];
  v123 = this->m_pfDelayRead[12];
  v112 = this->m_pfDelayRead[1];
  uValidFrames = io_pBuffer->uValidFrames;
  m_uNumProcessedChannels = this->m_uNumProcessedChannels;
  v110 = this->m_pfDelayRead[13];
  v34 = this->m_pfDelayRead[14];
  v113 = v6->m_pfDelayRead[5];
  v35 = v6->m_pfDelayRead[8];
  v109 = v6->m_pfDelayRead[11];
  v114 = v34;
  v111 = v6->m_pfDelayRead[15];
  if ( uValidFrames )
  {
    v36 = v6->m_pfDelayRead[8];
    v37 = v126;
    do
    {
      v38 = (__m128)*(unsigned int *)v24;
      v39 = (__m128)*(unsigned int *)v25;
      v40 = (__m128)*(unsigned int *)v26;
      v24 += 4;
      if ( v24 >= v130 )
        v24 = v37;
      v41 = (__m128)*(unsigned int *)v112;
      v112 += 4;
      if ( v112 >= v130 )
        v112 = v37 + 1;
      v25 += 4;
      if ( v25 >= v130 )
        v25 = v37 + 2;
      v26 += 4;
      if ( v26 >= v130 )
        v26 = v37 + 3;
      v42 = 0;
      v22 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v38, v41), _mm_unpacklo_ps(v39, v40)), v21),
              _mm_mul_ps(v22, v137));
      do
      {
        v43 = v42;
        v44 = v42++;
        v147[v44] = _mm_mul_ps(vOutDecorrelationVector[v43][0], v22);
      }
      while ( v42 < m_uNumProcessedChannels );
      v45 = (__m128)*(unsigned int *)v29;
      v46 = (__m128)*(unsigned int *)v30;
      v47 = (__m128)*(unsigned int *)v31;
      v29 += 4;
      v48 = (__m128)*(unsigned int *)v113;
      if ( v29 >= v129 )
        v29 = v128;
      v113 += 4;
      if ( v113 >= v129 )
        v113 = v128 + 1;
      v30 += 4;
      if ( v30 >= v129 )
        v30 = v128 + 2;
      v31 += 4;
      if ( v31 >= v129 )
        v31 = v128 + 3;
      v49 = 0;
      v23 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v45, v48), _mm_unpacklo_ps(v46, v47)), v145),
              _mm_mul_ps(v23, v134));
      do
      {
        v50 = v49;
        v51 = v49++;
        v147[v51] = _mm_add_ps(_mm_mul_ps(vOutDecorrelationVector[v50][1], v23), v147[v51]);
      }
      while ( v49 < m_uNumProcessedChannels );
      v52 = (__m128)*(unsigned int *)v36;
      v53 = v116;
      v54 = (__m128)*(unsigned int *)v115;
      v55 = _mm_add_ps(v23, v22);
      v36 += 4;
      v56 = (__m128)*(unsigned int *)v109;
      if ( v36 >= v124 )
        v36 = v116;
      v115 += 4;
      if ( v115 >= v124 )
        v115 = v116 + 1;
      v122 = v32 + 4;
      if ( v32 + 4 >= v124 )
      {
        v122 = v116 + 2;
        v53 = v116;
      }
      v109 += 4;
      if ( v109 >= v124 )
        v109 = v53 + 3;
      v57 = 0;
      v27 = _mm_add_ps(
              _mm_mul_ps(
                _mm_movelh_ps(_mm_unpacklo_ps(v52, v54), _mm_unpacklo_ps((__m128)*(unsigned int *)v32, v56)),
                v143),
              _mm_mul_ps(v27, v139));
      do
      {
        v58 = v57;
        v59 = v57++;
        v147[v59] = _mm_add_ps(_mm_mul_ps(vOutDecorrelationVector[v58][2], v27), v147[v59]);
      }
      while ( v57 < m_uNumProcessedChannels );
      v60 = _mm_add_ps(v55, v27);
      v61 = (__m128)*(unsigned int *)v123;
      v62 = (__m128)*(unsigned int *)v110;
      v63 = (__m128)*(unsigned int *)v114;
      v64 = (__m128)*(unsigned int *)v111;
      v65 = v123 + 4;
      if ( v123 + 4 >= v125 )
        v65 = v127;
      v123 = v65;
      v110 += 4;
      if ( v110 >= v125 )
        v110 = v127 + 1;
      v114 += 4;
      if ( v114 >= v125 )
        v114 = v127 + 2;
      v111 += 4;
      if ( v111 >= v125 )
        v111 = v127 + 3;
      v66 = 0;
      v28 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v61, v62), _mm_unpacklo_ps(v63, v64)), v146),
              _mm_mul_ps(v28, v141));
      do
      {
        v67 = v66;
        v68 = v66++;
        v147[v68] = _mm_add_ps(_mm_mul_ps(vOutDecorrelationVector[v67][3], v28), v147[v68]);
      }
      while ( v66 < m_uNumProcessedChannels );
      v69 = 0;
      v70 = _mm_add_ps(v60, v28);
      uMaxFrames = io_pBuffer->uMaxFrames;
      v72 = 0i64;
      do
      {
        v73 = pData[v72];
        v74 = v69++;
        v74 *= 2i64;
        v72 = (unsigned int)(uMaxFrames + v72);
        v75 = *(__m128 *)((char *)v147 + 8 * v74);
        *(__int128 *)((char *)&v148 + 8 * v74) = v73;
        v76 = _mm_add_ps(v75, _mm_movehl_ps(v75, v75));
        *(__m128 *)((char *)v147 + 8 * v74) = _mm_add_ps(_mm_shuffle_ps(v76, v76, 85), v76);
      }
      while ( v69 < m_uNumProcessedChannels );
      v77 = 0;
      v10 = v10 + v18;
      v13 = v13 + v16;
      v78 = 0i64;
      v79 = _mm_add_ps(_mm_movehl_ps(v70, v70), v70);
      v80 = _mm_add_ps(_mm_shuffle_ps(v79, v79, 85), v79);
      v81 = _mm_shuffle_ps(v80, v80, 0);
      do
      {
        v82 = v77++;
        v82 *= 2i64;
        v83 = *(__int128 *)((char *)&v148 + 8 * v82);
        *(float *)&v83 = (float)(*(float *)&v83 * v10)
                       + (float)(COERCE_FLOAT(*(_OWORD *)((char *)v147 + 8 * v82)) * v13);
        pData[v78] = v83;
        v78 = (unsigned int)(uMaxFrames + v78);
        *(__m128 *)((char *)v147 + 8 * v82) = (__m128)v83;
      }
      while ( v77 < m_uNumProcessedChannels );
      v84 = _mm_mul_ps(v81, v135);
      ++pData;
      v85 = _mm_add_ps(v28, v84);
      v86 = _mm_add_ps(v27, v84);
      v87 = _mm_add_ps(v84, v22);
      v88 = _mm_shuffle_ps(v85, _mm_shuffle_ps(v85, v87, 15), 201);
      v89 = _mm_shuffle_ps(v86, _mm_shuffle_ps(v86, v85, 15), 201);
      v90 = _mm_add_ps(v23, v84);
      v91 = _mm_shuffle_ps(v90, _mm_shuffle_ps(v90, v86, 15), 201);
      v92 = _mm_shuffle_ps(v87, v90, 15);
      v93 = *(float *)&v148;
      v94 = _mm_shuffle_ps(v87, v92, 201);
      if ( m_uNumProcessedChannels > 1 )
      {
        v95 = (float *)&v149;
        v96 = m_uNumProcessedChannels - 1;
        do
        {
          v93 = v93 + *v95;
          v95 += 4;
          --v96;
        }
        while ( v96 );
      }
      v11 = (float)((float)(v12 * v11) + v93) - v14;
      v14 = v93;
      if ( m_pfPreDelayStart )
      {
        v97 = *m_pfPreDelayRW;
        *m_pfPreDelayRW++ = v11;
        if ( m_pfPreDelayRW == m_pfPreDelayEnd )
          m_pfPreDelayRW = m_pfPreDelayStart;
      }
      else
      {
        v97 = v11;
      }
      v98 = v136;
      v99 = v138 * v133;
      v133 = v97;
      v37 = v126;
      v100 = v120 + 4;
      v98.m128_f32[0] = (float)(v136.m128_f32[0] * v97) + v99;
      v101 = _mm_shuffle_ps(v98, v98, 0);
      v102 = _mm_add_ps(v101, v94);
      v21 = v144;
      *(__m128 *)v120 = v102;
      *v117 = _mm_add_ps(v101, v91);
      if ( v120 + 4 >= v130 )
        v100 = v126;
      v103 = v117 + 1;
      v104 = _mm_add_ps(v101, v89);
      v120 = v100;
      if ( &v117[1] >= (__m128 *)v129 )
        v103 = (__m128 *)v128;
      v105 = v119 + 4;
      v106 = _mm_add_ps(v101, v88);
      v18 = v140;
      v16 = v142;
      *(__m128 *)v119 = v104;
      v117 = v103;
      if ( v119 + 4 >= v124 )
        v105 = v116;
      *(__m128 *)v121 = v106;
      v107 = v121 + 4;
      v119 = v105;
      v32 = v122;
      if ( v121 + 4 >= v125 )
        v107 = v127;
      v108 = uValidFrames-- == 1;
      v121 = v107;
    }
    while ( !v108 );
    *(float *)&v17 = v97;
    v19 = v109;
    v34 = v114;
    v20 = v111;
    v118 = v36;
    v6 = this;
    v35 = v118;
  }
  v6->m_fFIRLPFMem = *(float *)&v17;
  v6->m_fDCFwdMem = v14;
  v6->m_fDCFbkMem = v11;
  v6->m_pfPreDelayRW = m_pfPreDelayRW;
  v6->m_pfDelayWrite[0] = v120;
  v6->m_vIIRLPFMem[0] = v22;
  v6->m_vIIRLPFMem[1] = v23;
  v6->m_vIIRLPFMem[2] = v27;
  v6->m_pfDelayWrite[1] = (float *)v117;
  v6->m_pfDelayRead[8] = v35;
  v6->m_vIIRLPFMem[3] = v28;
  v6->m_pfDelayWrite[2] = v119;
  v6->m_pfDelayWrite[3] = v121;
  v6->m_pfDelayRead[9] = v115;
  v6->m_pfDelayRead[1] = v112;
  v6->m_pfDelayRead[12] = v123;
  v6->m_pfDelayRead[5] = v113;
  v6->m_pfDelayRead[0] = v24;
  v6->m_pfDelayRead[2] = v25;
  v6->m_pfDelayRead[3] = v26;
  v6->m_pfDelayRead[4] = v29;
  v6->m_pfDelayRead[6] = v30;
  v6->m_pfDelayRead[7] = v31;
  v6->m_pfDelayRead[10] = v32;
  v6->m_pfDelayRead[11] = v19;
  v6->m_pfDelayRead[13] = v110;
  v6->m_pfDelayRead[14] = v34;
  v6->m_pfDelayRead[15] = v20;
}

// File Line: 1899
// RVA: 0xACBF70
void __fastcall CAkFDNReverbFX::ComputeIIRLPFCoefs(CAkFDNReverbFX *this)
{
  CAkFDNReverbFXParams *m_pParams; // rdx
  unsigned int uNumberOfDelays; // ebx
  double v4; // xmm9_8
  double v5; // xmm7_8
  double v6; // xmm0_8
  double v7; // xmm0_8
  double v8; // xmm11_8
  double v9; // xmm0_8
  __int64 v10; // rsi
  CAkFDNReverbFXParams *v11; // rcx
  char v12; // bl
  double v13; // xmm0_8
  double v14; // xmm0_8
  unsigned __int64 v15; // rcx
  double v16; // xmm2_8
  __int64 v17; // rax
  float v18; // xmm1_4

  m_pParams = this->m_pParams;
  uNumberOfDelays = m_pParams->NonRTPC.uNumberOfDelays;
  v4 = 1.0 / (double)(int)this->m_uSampleRate;
  v5 = 1.0 - 1.0 / (1.0 / m_pParams->RTPC.fHFRatio * (1.0 / m_pParams->RTPC.fHFRatio));
  v6 = pow(0.001, (double)(int)this->m_uNominalDelayLength[uNumberOfDelays - 1] * v4 / m_pParams->RTPC.fReverbTime);
  v7 = log10(v6);
  v8 = IIRCOEFCALCCONST;
  v9 = v7 * IIRCOEFCALCCONST;
  if ( v9 * v5 > 1.0 )
    v5 = 1.0 / v9;
  v10 = 0i64;
  if ( uNumberOfDelays )
  {
    v11 = this->m_pParams;
    do
    {
      v12 = v10;
      v13 = pow(0.001, (double)(int)this->m_uNominalDelayLength[v10] * v4 / v11->RTPC.fReverbTime);
      v14 = log10(v13);
      v15 = (unsigned int)v10;
      v10 = (unsigned int)(v10 + 1);
      v16 = v14 * v8 * v5;
      v17 = (v12 & 3) + 4 * (v15 >> 2);
      *(float *)&v14 = (1.0 - v16) * 0.001;
      this->m_vIIRLPFB0[0].m128_i32[v17] = LODWORD(v14);
      v18 = v16;
      this->m_vIIRLPFA1[0].m128_f32[v17] = v18;
      v11 = this->m_pParams;
    }
    while ( (unsigned int)v10 < v11->NonRTPC.uNumberOfDelays );
  }
}


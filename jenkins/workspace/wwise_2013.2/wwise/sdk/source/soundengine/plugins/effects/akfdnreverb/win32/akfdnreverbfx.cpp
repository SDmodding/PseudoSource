// File Line: 49
// RVA: 0x15BE150
void dynamic_initializer_for__IIRCOEFCALCCONST__()
{
  IIRCOEFCALCCONST = log(10.0) * 0.25;
}

// File Line: 102
// RVA: 0xACBF60
__int64 __fastcall AkFDNQSortCompare(const void *a, const void *b)
{
  return (unsigned int)(*(_DWORD *)a - *(_DWORD *)b);
}

// File Line: 108
// RVA: 0xAC16D0
void __fastcall CreateMatrixReverbFX(AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkFDNReverbFX *v1; // rax

  v1 = (CAkFDNReverbFX *)in_pAllocator->vfptr->Malloc(in_pAllocator, 608ui64);
  if ( v1 )
    CAkFDNReverbFX::CAkFDNReverbFX(v1);
}

// File Line: 117
// RVA: 0xAC1700
void __fastcall CAkFDNReverbFX::CAkFDNReverbFX(CAkFDNReverbFX *this)
{
  CAkFDNReverbFX *v1; // rbx
  float **v2; // rcx

  v1 = this;
  this->vfptr = (AK::IAkPluginVtbl *)&CAkFDNReverbFX::`vftable;
  v2 = this->m_pfDelayRead;
  *(v2 - 14) = 0i64;
  *((_DWORD *)v2 + 109) = -1;
  *((_DWORD *)v2 + 110) = 0;
  *(v2 - 16) = 0i64;
  *(v2 - 15) = 0i64;
  *(v2 - 17) = 0i64;
  *(v2 - 13) = 0i64;
  *(v2 - 12) = 0i64;
  *(v2 - 11) = 0i64;
  v2[16] = 0i64;
  v2[17] = 0i64;
  v2[18] = 0i64;
  v2[19] = 0i64;
  v2[24] = 0i64;
  v2[25] = 0i64;
  v2[26] = 0i64;
  v2[27] = 0i64;
  memset(v2, 0, 0x80ui64);
  v1->m_pfDelayWrite[0] = 0i64;
  v1->m_pfDelayWrite[1] = 0i64;
  v1->m_pfDelayWrite[2] = 0i64;
  v1->m_pfDelayWrite[3] = 0i64;
  *(_QWORD *)v1->m_uNominalDelayLength = 0i64;
  *(_QWORD *)&v1->m_uNominalDelayLength[2] = 0i64;
  *(_QWORD *)&v1->m_uNominalDelayLength[4] = 0i64;
  *(_QWORD *)&v1->m_uNominalDelayLength[6] = 0i64;
  *(_QWORD *)&v1->m_uNominalDelayLength[8] = 0i64;
  *(_QWORD *)&v1->m_uNominalDelayLength[10] = 0i64;
  *(_QWORD *)&v1->m_uNominalDelayLength[12] = 0i64;
  *(_QWORD *)&v1->m_uNominalDelayLength[14] = 0i64;
  v1->m_vIIRLPFB0[0].m128_u64[0] = 0i64;
  v1->m_vIIRLPFB0[0].m128_u64[1] = 0i64;
  v1->m_vIIRLPFB0[1].m128_u64[0] = 0i64;
  v1->m_vIIRLPFB0[1].m128_u64[1] = 0i64;
  v1->m_vIIRLPFB0[2].m128_u64[0] = 0i64;
  v1->m_vIIRLPFB0[2].m128_u64[1] = 0i64;
  v1->m_vIIRLPFB0[3].m128_u64[0] = 0i64;
  v1->m_vIIRLPFB0[3].m128_u64[1] = 0i64;
  v1->m_vIIRLPFA1[0].m128_u64[0] = 0i64;
  v1->m_vIIRLPFA1[0].m128_u64[1] = 0i64;
  v1->m_vIIRLPFA1[1].m128_u64[0] = 0i64;
  v1->m_vIIRLPFA1[1].m128_u64[1] = 0i64;
  v1->m_vIIRLPFA1[2].m128_u64[0] = 0i64;
  v1->m_vIIRLPFA1[2].m128_u64[1] = 0i64;
  v1->m_vIIRLPFA1[3].m128_u64[0] = 0i64;
  v1->m_vIIRLPFA1[3].m128_u64[1] = 0i64;
  v1->m_vIIRLPFMem[0].m128_u64[0] = 0i64;
  v1->m_vIIRLPFMem[0].m128_u64[1] = 0i64;
  v1->m_vIIRLPFMem[1].m128_u64[0] = 0i64;
  v1->m_vIIRLPFMem[1].m128_u64[1] = 0i64;
  v1->m_vIIRLPFMem[2].m128_u64[0] = 0i64;
  v1->m_vIIRLPFMem[2].m128_u64[1] = 0i64;
  v1->m_vIIRLPFMem[3].m128_u64[0] = 0i64;
  v1->m_vIIRLPFMem[3].m128_u64[1] = 0i64;
}

// File Line: 136
// RVA: 0xAC1890
void __fastcall CAkFDNReverbFX::~CAkFDNReverbFX(CAkFDNReverbFX *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable;
}

// File Line: 146
// RVA: 0xAC18B0
AKRESULT __fastcall CAkFDNReverbFX::Init(CAkFDNReverbFX *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkEffectPluginContext *in_pFXCtx, AK::IAkPluginParam *in_pParams, AkAudioFormat *in_rFormat)
{
  CAkFDNReverbFX *v5; // rbp
  AK::IAkPluginParam *v6; // rsi
  AK::IAkPluginMemAlloc *v7; // rbx
  char v8; // al
  float v9; // xmm2_4

  v5 = this;
  v6 = in_pParams;
  v7 = in_pAllocator;
  this->m_uSampleRate = in_rFormat->uSampleRate;
  v8 = ((__int64 (__fastcall *)(AK::IAkEffectPluginContext *))in_pFXCtx->vfptr[1].__vecDelDtor)(in_pFXCtx);
  v5->m_pAllocator = v7;
  v5->m_pParams = (CAkFDNReverbFXParams *)v6;
  v5->m_bIsSentMode = v8;
  v5->m_fCurrentDry = *(float *)&v6[2].vfptr;
  v5->m_fCurrentWet = *((float *)&v6[2].vfptr + 1);
  v9 = (float)(signed int)v5->m_uSampleRate;
  v5->m_fDCCoef = 1.0 - (float)(62.831856 / v9);
  v5->m_uTailLength = (signed int)(float)(v9 * *(float *)&v6[1].vfptr);
  return CAkFDNReverbFX::InitDelayLines(v5, *((_DWORD *)in_rFormat + 1) & 0x3FFFF);
}

// File Line: 168
// RVA: 0xAC1970
signed __int64 __fastcall CAkFDNReverbFX::Term(CAkFDNReverbFX *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  CAkFDNReverbFX *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  CAkFDNReverbFX::TermDelayLines(this);
  if ( v3 )
  {
    v3->vfptr->__vecDelDtor((AK::IAkPlugin *)&v3->vfptr, 0);
    v2->vfptr->Free(v2, v3);
  }
  return 1i64;
}

// File Line: 177
// RVA: 0xAC19C0
signed __int64 __fastcall CAkFDNReverbFX::Reset(CAkFDNReverbFX *this)
{
  CAkFDNReverbFX *v1; // rbx
  float *v2; // rcx
  CAkFDNReverbFXParams *v3; // rax
  __int64 v4; // rdi
  unsigned int v5; // esi
  float *v6; // rcx

  v1 = this;
  v2 = this->m_pfPreDelayStart;
  if ( v2 )
    memset(v2, 0, 4 * v1->m_uPreDelayLength);
  v3 = v1->m_pParams;
  v1->m_fFIRLPFMem = 0.0;
  v4 = 0i64;
  if ( v3->NonRTPC.uNumberOfDelays & 0xFFFFFFFC )
  {
    v5 = 3;
    do
    {
      *((_OWORD *)&v1->vfptr + v4 + 31) = 0i64;
      v6 = v1->m_pfDelayStart[v4];
      if ( v6 )
        memset(v6, 0, 16 * v1->m_uNominalDelayLength[v5]);
      v4 = (unsigned int)(v4 + 1);
      v5 += 4;
    }
    while ( (unsigned int)v4 < v1->m_pParams->NonRTPC.uNumberOfDelays >> 2 );
  }
  *(_QWORD *)&v1->m_fDCFwdMem = 0i64;
  return 1i64;
}

// File Line: 207
// RVA: 0xAC1A80
signed __int64 __fastcall CAkFDNReverbFX::GetPluginInfo(CAkFDNReverbFX *this, AkPluginInfo *out_rPluginInfo)
{
  out_rPluginInfo->eType = 3;
  *(_WORD *)&out_rPluginInfo->bIsInPlace = 1;
  return 1i64;
}

// File Line: 219
// RVA: 0xAC1AA0
void __fastcall CAkFDNReverbFX::Execute(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  AkAudioBuffer *v2; // rdi
  CAkFDNReverbFX *v3; // rbx
  unsigned int v4; // ecx
  int i; // edx
  CAkFDNReverbFXParams *v6; // rcx
  double v7; // xmm4_8
  float v8; // xmm0_4
  float v9; // xmm0_4
  CAkFDNReverbFXParams *v10; // rcx

  v2 = io_pBuffer;
  v3 = this;
  if ( this->m_pParams->NonRTPC.bDirty )
  {
    if ( CAkFDNReverbFX::InitDelayLines(this, io_pBuffer->uChannelMask) != 1 )
      return;
    v3->vfptr->Reset((AK::IAkPlugin *)&v3->vfptr);
  }
  if ( v3->m_bIsSentMode )
  {
    v4 = v2->uChannelMask;
    if ( v4 & 8 )
    {
      if ( !v3->m_pParams->NonRTPC.uProcessLFE )
      {
        for ( i = 0; v4; v4 &= v4 - 1 )
          ++i;
        memset(
          (char *)v2->pData + 4 * v2->uMaxFrames * (unsigned __int64)(unsigned int)(i - 1),
          0,
          4 * (unsigned int)v2->uValidFrames);
      }
    }
  }
  if ( v3->m_uNumProcessedChannels )
  {
    v6 = v3->m_pParams;
    if ( v3->m_fCachedReverbTime != v6->RTPC.fReverbTime || v3->m_fCachedHFRatio != v6->RTPC.fHFRatio )
    {
      CAkFDNReverbFX::ComputeIIRLPFCoefs(v3);
      v6 = v3->m_pParams;
      v7 = (1.0 - 1.0 / v6->RTPC.fHFRatio) / (1.0 / v6->RTPC.fHFRatio + 1.0);
      v8 = 1.0 / (1.0 - v7);
      v3->m_fFIRLPFB0 = v8;
      v9 = -1.0 / (1.0 - v7) * v7;
      v3->m_fFIRLPFB1 = v9;
      v3->m_fCachedReverbTime = v6->RTPC.fReverbTime;
      v3->m_fCachedHFRatio = v6->RTPC.fHFRatio;
      v3->m_uTailLength = (signed int)(float)((float)(signed int)v3->m_uSampleRate * v6->RTPC.fReverbTime);
    }
    if ( v3->m_bIsSentMode )
    {
      v3->m_fCurrentDry = 0.0;
      v6->RTPC.fDryLevel = 0.0;
    }
    AkFXTailHandler::HandleTail(&v3->m_FXTailHandler, v2, v3->m_uTailLength);
    if ( v2->uValidFrames )
    {
      v3->m_fpPerformDSP(v3, v2);
      v10 = v3->m_pParams;
      v3->m_fCurrentDry = v10->RTPC.fDryLevel;
      v3->m_fCurrentWet = v10->RTPC.fWetLevel;
    }
  }
}

// File Line: 274
// RVA: 0xAC1C40
signed __int64 __fastcall CAkFDNReverbFX::InitDelayLines(CAkFDNReverbFX *this, unsigned int in_uChannelMask)
{
  unsigned int v2; // edi
  CAkFDNReverbFX *v3; // rbx
  CAkFDNReverbFXParams *v4; // rax
  __int64 v5; // r15
  unsigned int v6; // er8
  __int64 v7; // rdx
  CAkFDNReverbFXParams *v8; // r8
  unsigned int v9; // ecx
  unsigned int i; // edx
  unsigned int v11; // eax
  int v12; // edi
  int v13; // edi
  int v14; // edi
  void (__fastcall *v15)(CAkFDNReverbFX *, AkAudioBuffer *); // rax
  unsigned int v16; // edx
  __int64 v17; // rax
  signed __int64 result; // rax
  unsigned int j; // er11
  signed int v20; // eax
  __m128d v21; // xmm0
  int v22; // er8
  signed int v23; // ecx
  unsigned int v24; // er9
  unsigned int v25; // esi
  unsigned int v26; // edi
  __int64 v27; // rbp
  __int64 v28; // rax
  __int64 v29; // rdx
  int v30; // edi
  float *v31; // rax

  v2 = in_uChannelMask;
  v3 = this;
  CAkFDNReverbFX::TermDelayLines(this);
  v4 = v3->m_pParams;
  v5 = 0i64;
  if ( !v4->NonRTPC.uDelayLengthsMode )
  {
    v6 = 0;
    if ( v4->NonRTPC.uNumberOfDelays > 0 )
    {
      do
      {
        v7 = v6++;
        v3->m_pParams->NonRTPC.fDelayTime[v7] = g_fDefaultDelayLengths[v7];
      }
      while ( v6 < v3->m_pParams->NonRTPC.uNumberOfDelays );
    }
  }
  v8 = v3->m_pParams;
  if ( !v8->NonRTPC.uProcessLFE )
    v2 &= 0xFFFFFFF7;
  v9 = v2;
  for ( i = 0; v9; v9 &= v9 - 1 )
    ++i;
  v3->m_uNumProcessedChannels = i;
  v11 = v8->NonRTPC.uNumberOfDelays;
  v12 = v2 - 3;
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
          switch ( v11 )
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
          switch ( v11 )
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
        switch ( v11 )
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
      switch ( v11 )
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
    switch ( v11 )
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
  v3->m_fpPerformDSP = v15;
LABEL_53:
  v16 = (signed int)(float)((float)(signed int)v3->m_uSampleRate * v8->NonRTPC.fPreDelay);
  v3->m_uPreDelayLength = v16;
  if ( v16 )
  {
    v17 = (__int64)v3->m_pAllocator->vfptr->Malloc(v3->m_pAllocator, 4i64 * v16);
    v3->m_pfPreDelayStart = (float *)v17;
    if ( !v17 )
      return 52i64;
    v3->m_pfPreDelayRW = (float *)v17;
    v3->m_pfPreDelayEnd = (float *)(v17 + 4i64 * v3->m_uPreDelayLength);
  }
  for ( j = 0; j < v3->m_pParams->NonRTPC.uNumberOfDelays; ++j )
  {
    v20 = (signed int)(float)((float)(v3->m_pParams->NonRTPC.fDelayTime[j] * 0.001)
                            * (float)(signed int)v3->m_uSampleRate);
    v3->m_uNominalDelayLength[j] = v20;
    if ( !(v20 & 1) )
      v3->m_uNominalDelayLength[j] = v20 + 1;
    v21 = 0i64;
    v21.m128d_f64[0] = (double)(signed int)v3->m_uNominalDelayLength[j];
    v22 = (signed int)COERCE_DOUBLE(_mm_sqrt_pd(v21)) + 1;
    while ( 1 )
    {
      v23 = 3;
      if ( v22 <= 3 )
        break;
      v24 = v3->m_uNominalDelayLength[j];
      while ( v24 % v23 )
      {
        v23 += 2;
        if ( v23 >= v22 )
          goto LABEL_65;
      }
      v3->m_uNominalDelayLength[j] = v24 + 2;
    }
LABEL_65:
    ;
  }
  qsort(v3->m_uNominalDelayLength, v3->m_pParams->NonRTPC.uNumberOfDelays, 4ui64, AkFDNQSortCompare);
  if ( v3->m_pParams->NonRTPC.uNumberOfDelays & 0xFFFFFFFC )
  {
    v25 = 2;
    while ( 1 )
    {
      v26 = v3->m_uNominalDelayLength[v25 + 1];
      v27 = v25 + 1;
      v28 = (__int64)v3->m_pAllocator->vfptr->Malloc(v3->m_pAllocator, 16i64 * v26);
      v3->m_pfDelayStart[v5] = (float *)v28;
      if ( !v28 )
        break;
      v3->m_pfDelayWrite[v5] = (float *)v28;
      v3->m_pfDelayEnd[v5] = (float *)(16i64 * v26 + v28);
      v3->m_pfDelayRead[v25 - 2] = (float *)(v28 + 16i64 * (v26 - v3->m_uNominalDelayLength[v25 - 2]));
      v3->m_pfDelayRead[v25 - 1] = &v3->m_pfDelayStart[v5][4 * (v26 - v3->m_uNominalDelayLength[v25 - 1]) + 1];
      v29 = v25;
      v30 = v26 - v3->m_uNominalDelayLength[v25];
      v25 += 4;
      v3->m_pfDelayRead[v29] = &v3->m_pfDelayStart[v5][4 * v30 + 2];
      v31 = v3->m_pfDelayStart[v5];
      v5 = (unsigned int)(v5 + 1);
      v3->m_pfDelayRead[v27] = v31 + 3;
      if ( (unsigned int)v5 >= v3->m_pParams->NonRTPC.uNumberOfDelays >> 2 )
        goto LABEL_70;
    }
    result = 52i64;
  }
  else
  {
LABEL_70:
    v3->vfptr->Reset((AK::IAkPlugin *)&v3->vfptr);
    v3->m_pParams->NonRTPC.bDirty = 0;
    result = 1i64;
  }
  return result;
}

// File Line: 465
// RVA: 0xAC2080
void __fastcall CAkFDNReverbFX::TermDelayLines(CAkFDNReverbFX *this)
{
  CAkFDNReverbFX *v1; // rsi
  float **v2; // rbx
  signed __int64 v3; // rdi

  v1 = this;
  v2 = this->m_pfDelayStart;
  v3 = 4i64;
  do
  {
    if ( *v2 )
    {
      ((void (*)(void))v1->m_pAllocator->vfptr->Free)();
      *v2 = 0i64;
    }
    ++v2;
    --v3;
  }
  while ( v3 );
  if ( v1->m_pfPreDelayStart )
  {
    ((void (*)(void))v1->m_pAllocator->vfptr->Free)();
    v1->m_pfPreDelayStart = 0i64;
  }
}

// File Line: 1069
// RVA: 0xAC2100
void __usercall CAkFDNReverbFX::ProcessMono4(CAkFDNReverbFX *this@<rcx>, AkAudioBuffer *io_pBuffer@<rdx>, __m128 a3@<xmm14>)
{
  float *v3; // rbp
  float *v4; // r14
  float *v5; // rbx
  float *v6; // rdi
  AkAudioBuffer *v7; // r8
  CAkFDNReverbFXParams *v8; // rdx
  CAkFDNReverbFX *v9; // r9
  __m128 v10; // xmm7
  float v11; // xmm8_4
  float v12; // xmm6_4
  float *v13; // r15
  float *v14; // rsi
  __m128 v15; // xmm5
  __m128 v16; // xmm9
  float v17; // xmm10_4
  float v18; // xmm11_4
  float v19; // xmm4_4
  unsigned int v20; // eax
  int v21; // er8
  float *v22; // r10
  float v23; // xmm12_4
  float *v24; // r11
  __m128i v25; // xmm0
  float *v26; // rax
  float v27; // xmm13_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  __m128 v30; // xmm0
  float *v31; // rdx
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

  v3 = this->m_pfPreDelayStart;
  v4 = this->m_pfPreDelayEnd;
  v5 = this->m_pfDelayStart[0];
  v6 = this->m_pfDelayEnd[0];
  v7 = io_pBuffer;
  v8 = this->m_pParams;
  v9 = this;
  v10 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      0);
  LODWORD(v12) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      0);
  v13 = (float *)v7->pData;
  v14 = this->m_pfDelayRead[1];
  v15 = this->m_vIIRLPFB0[0];
  v16 = this->m_vIIRLPFMem[0];
  LODWORD(v17) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fCurrentDry),
                                      (__m128)LODWORD(this->m_fCurrentDry),
                                      0);
  LODWORD(v18) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fCurrentWet),
                                      (__m128)LODWORD(this->m_fCurrentWet),
                                      0);
  LODWORD(v19) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      0);
  v20 = v7->uMaxFrames;
  v21 = v7->uValidFrames;
  v22 = this->m_pfDelayRead[2];
  LODWORD(v23) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      0);
  v54 = this->m_vIIRLPFB0[0];
  v24 = this->m_pfDelayRead[3];
  v25 = _mm_cvtsi32_si128(v20);
  v26 = this->m_pfDelayWrite[0];
  LODWORD(v27) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      0);
  a3.m128_f32[0] = -2.0 / (float)(signed int)v8->NonRTPC.uNumberOfDelays;
  v28 = v8->RTPC.fDryLevel;
  v29 = 1.0 / COERCE_FLOAT(_mm_cvtepi32_ps(v25));
  v30 = (__m128)LODWORD(v8->RTPC.fWetLevel);
  v31 = this->m_pfPreDelayRW;
  v30.m128_f32[0] = v30.m128_f32[0] - this->m_fCurrentWet;
  v32 = (float)(v28 - this->m_fCurrentDry) * v29;
  v33 = _mm_shuffle_ps(a3, a3, 0);
  v34 = this->m_pfDelayRead[0];
  v35 = v32;
  v30.m128_f32[0] = v30.m128_f32[0] * v29;
  LODWORD(v53) = (unsigned __int128)_mm_shuffle_ps(v30, v30, 0);
  for ( i = v9->m_vIIRLPFA1[0]; v21; --v21 )
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
    v41 = *v13;
    v17 = v17 + v35;
    ++v13;
    v16 = _mm_add_ps(_mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v36, v37), v40), v15), _mm_mul_ps(v16, i));
    v42 = _mm_mul_ps(v16, vOutDecorrelationVectorA);
    v43 = _mm_add_ps(v42, _mm_movehl_ps(v42, v42));
    v44 = _mm_add_ps(_mm_movehl_ps(v16, v16), v16);
    v45 = _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), v44);
    *(v13 - 1) = (float)(v41 * v17)
               + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v43, v43, 85)) + v43.m128_f32[0]) * v18);
    v46 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v45, v45, 0), v33), v16);
    v47 = _mm_shuffle_ps(v46, _mm_shuffle_ps(v46, v46, 15), 201);
    v19 = (float)((float)(v27 * v19) + v41) - v23;
    v23 = v41;
    if ( v3 != 0i64 )
    {
      v48 = *v31;
      *v31 = v19;
      ++v31;
      if ( v31 == v4 )
        v31 = v3;
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
  v9->m_fFIRLPFMem = v12;
  v9->m_fDCFwdMem = v23;
  v9->m_fDCFbkMem = v19;
  v9->m_pfPreDelayRW = v31;
  v9->m_pfDelayRead[3] = v24;
  v9->m_pfDelayRead[1] = v14;
  v9->m_pfDelayWrite[0] = v26;
  v9->m_pfDelayRead[0] = v34;
  v9->m_pfDelayRead[2] = v22;
  v9->m_vIIRLPFMem[0] = v16;
}

// File Line: 1095
// RVA: 0xAC2490
void __fastcall CAkFDNReverbFX::ProcessMono8(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  __m128 v3; // xmm4
  float *v4; // r10
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
  AkAudioBuffer *v21; // r8
  CAkFDNReverbFXParams *v22; // rdx
  float *v23; // rsi
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  float *v26; // rax
  __m128 v27; // xmm0
  float *v28; // rdx
  __m128 v29; // xmm8
  __m128 v30; // xmm5
  __m128 v31; // xmm12
  float *v32; // rcx
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm0
  __m128 v36; // xmm3
  __m128 v37; // xmm1
  __m128 v38; // xmm2
  __m128 v39; // xmm0
  __m128 v40; // xmm1
  __m128 v41; // xmm4
  __m128 v42; // xmm0
  __m128 v43; // xmm1
  __m128 v44; // xmm0
  float v45; // xmm4_4
  __m128 v46; // xmm3
  __m128 v47; // xmm3
  __m128 v48; // xmm0
  __m128 v49; // xmm1
  __m128 v50; // xmm2
  __m128 v51; // xmm2
  __m128 v52; // xmm3
  __m128 v53; // xmm1
  __m128 v54; // xmm8
  __m128 v55; // xmm3
  float v56; // xmm2_4
  __m128 v57; // xmm1
  float v58; // xmm0_4
  __m128 v59; // xmm0
  __m128 v60; // xmm1
  float *v61; // [rsp+0h] [rbp-188h]
  float *v62; // [rsp+8h] [rbp-180h]
  float *v63; // [rsp+10h] [rbp-178h]
  float *v64; // [rsp+18h] [rbp-170h]
  __m128 v65; // [rsp+20h] [rbp-168h]
  __m128 v66; // [rsp+30h] [rbp-158h]
  __m128 v67; // [rsp+40h] [rbp-148h]
  float v68; // [rsp+50h] [rbp-138h]
  float v69; // [rsp+60h] [rbp-128h]
  __m128 v70; // [rsp+70h] [rbp-118h]
  float v71; // [rsp+80h] [rbp-108h]
  __m128 v72; // [rsp+90h] [rbp-F8h]
  CAkFDNReverbFX *v73; // [rsp+190h] [rbp+8h]
  bool v74; // [rsp+198h] [rbp+10h]
  int v75; // [rsp+1A0h] [rbp+18h]
  float *v76; // [rsp+1A8h] [rbp+20h]

  v73 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  v3 = this->m_vIIRLPFB0[0];
  v4 = this->m_pfPreDelayRW;
  v5 = this->m_pfDelayStart[0];
  v6 = this->m_pfDelayStart[1];
  v7 = this->m_pfDelayEnd[0];
  LODWORD(v68) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      0);
  LODWORD(v8) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(this->m_fFIRLPFMem),
                                     (__m128)LODWORD(this->m_fFIRLPFMem),
                                     0);
  v9 = this->m_pfDelayWrite[1];
  v10 = this->m_pfDelayRead[1];
  v11 = this->m_pfDelayRead[2];
  LODWORD(v12) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      0);
  v13 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v14) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      0);
  v15 = this->m_pfDelayRead[3];
  v16 = this->m_pfDelayRead[4];
  v17 = this->m_pfDelayRead[7];
  LODWORD(v18) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fCurrentDry),
                                      (__m128)LODWORD(this->m_fCurrentDry),
                                      0);
  LODWORD(v19) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fCurrentWet),
                                      (__m128)LODWORD(this->m_fCurrentWet),
                                      0);
  v70 = this->m_vIIRLPFB0[0];
  LODWORD(v20) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      0);
  v21 = io_pBuffer;
  v22 = this->m_pParams;
  v76 = this->m_pfDelayRead[5];
  v23 = this->m_pfDelayRead[6];
  v61 = (float *)v21->pData;
  v2.m128_f32[0] = -2.0 / (float)(signed int)v22->NonRTPC.uNumberOfDelays;
  v24 = v2;
  v25 = (__m128)LODWORD(v22->RTPC.fDryLevel);
  v66 = _mm_shuffle_ps(v24, v24, 0);
  v64 = this->m_pfPreDelayStart;
  v62 = this->m_pfDelayEnd[1];
  v26 = this->m_pfDelayRead[0];
  v74 = this->m_pfPreDelayStart != 0i64;
  v25.m128_f32[0] = (float)(v25.m128_f32[0] - this->m_fCurrentDry) * (float)(1.0 / (float)v21->uMaxFrames);
  LODWORD(v71) = (unsigned __int128)_mm_shuffle_ps(v25, v25, 0);
  v27 = (__m128)LODWORD(v22->RTPC.fWetLevel);
  v63 = this->m_pfPreDelayEnd;
  v28 = this->m_pfDelayWrite[0];
  v27.m128_f32[0] = (float)(v27.m128_f32[0] - this->m_fCurrentWet) * (float)(1.0 / (float)v21->uMaxFrames);
  LODWORD(v69) = (unsigned __int128)_mm_shuffle_ps(v27, v27, 0);
  v67 = this->m_vIIRLPFB0[1];
  v29 = this->m_vIIRLPFA1[0];
  v75 = v21->uValidFrames;
  v30 = this->m_vIIRLPFMem[0];
  v31 = this->m_vIIRLPFMem[1];
  v72 = this->m_vIIRLPFA1[0];
  v65 = this->m_vIIRLPFA1[1];
  if ( v21->uValidFrames )
  {
    v32 = this->m_pfDelayRead[5];
    do
    {
      v33 = (__m128)*(unsigned int *)v26;
      v34 = (__m128)*(unsigned int *)v10;
      v35 = (__m128)*(unsigned int *)v11;
      v26 += 4;
      if ( v26 >= v7 )
        v26 = v5;
      v10 += 4;
      v36 = (__m128)*(unsigned int *)v15;
      if ( v10 >= v7 )
        v10 = v5 + 1;
      v11 += 4;
      if ( v11 >= v7 )
        v11 = v5 + 2;
      v15 += 4;
      if ( v15 >= v7 )
        v15 = v5 + 3;
      v37 = _mm_unpacklo_ps(v33, v34);
      v38 = (__m128)*(unsigned int *)v16;
      v39 = _mm_unpacklo_ps(v35, v36);
      v16 += 4;
      if ( v16 >= v62 )
        v16 = v6;
      v40 = _mm_mul_ps(_mm_movelh_ps(v37, v39), v3);
      v41 = (__m128)*(unsigned int *)v17;
      v76 = v32 + 4;
      v30 = _mm_add_ps(v40, _mm_mul_ps(v30, v29));
      v42 = (__m128)*(unsigned int *)v23;
      v43 = _mm_mul_ps(v30, vOutDecorrelationVectorA);
      if ( v32 + 4 >= v62 )
        v76 = v6 + 1;
      v23 += 4;
      if ( v23 >= v62 )
        v23 = v6 + 2;
      v17 += 4;
      if ( v17 >= v62 )
        v17 = v6 + 3;
      v18 = v18 + v71;
      v19 = v19 + v69;
      ++v61;
      v44 = _mm_unpacklo_ps(v42, v41);
      v45 = *(v61 - 1);
      v31 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v38, (__m128)*(unsigned int *)v32), v44), v67),
              _mm_mul_ps(v31, v65));
      v46 = _mm_add_ps(_mm_mul_ps(v31, vOutDecorrelationVectorA), v43);
      v47 = _mm_add_ps(v46, _mm_movehl_ps(v46, v46));
      v48 = _mm_add_ps(v31, v30);
      v49 = _mm_add_ps(_mm_movehl_ps(v48, v48), v48);
      v50 = _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), v49);
      v51 = _mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), v66);
      v49.m128_f32[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 85)) + v47.m128_f32[0]) * v19;
      v52 = _mm_add_ps(v51, v30);
      *(v61 - 1) = (float)(*(v61 - 1) * v18) + v49.m128_f32[0];
      v53 = _mm_add_ps(v31, v51);
      v54 = _mm_shuffle_ps(v53, _mm_shuffle_ps(v53, v52, 15), 201);
      v55 = _mm_shuffle_ps(v52, _mm_shuffle_ps(v52, v53, 15), 201);
      v12 = (float)((float)(v68 * v12) + v45) - v20;
      v20 = v45;
      if ( v74 )
      {
        v56 = *v4;
        *v4 = v12;
        ++v4;
        if ( v4 == v63 )
          v4 = v64;
      }
      else
      {
        v56 = v12;
      }
      v3 = v70;
      v32 = v76;
      v28 += 4;
      v57 = v13;
      v58 = v14 * v8;
      v8 = v56;
      v57.m128_f32[0] = (float)(v13.m128_f32[0] * v56) + v58;
      v59 = _mm_shuffle_ps(v57, v57, 0);
      v60 = _mm_add_ps(v59, v54);
      v29 = v72;
      *((__m128 *)v28 - 1) = _mm_add_ps(v59, v55);
      if ( v28 >= v7 )
        v28 = v5;
      *(__m128 *)v9 = v60;
      v9 += 4;
      if ( v9 >= v62 )
        v9 = v6;
      --v75;
    }
    while ( v75 );
    this = v73;
  }
  this->m_fFIRLPFMem = v8;
  this->m_fDCFwdMem = v20;
  this->m_fDCFbkMem = v12;
  this->m_pfPreDelayRW = v4;
  this->m_pfDelayRead[0] = v26;
  this->m_vIIRLPFMem[1] = v31;
  this->m_vIIRLPFMem[0] = v30;
  this->m_pfDelayRead[2] = v11;
  this->m_pfDelayWrite[0] = v28;
  this->m_pfDelayRead[5] = v76;
  this->m_pfDelayWrite[1] = v9;
  this->m_pfDelayRead[1] = v10;
  this->m_pfDelayRead[3] = v15;
  this->m_pfDelayRead[4] = v16;
  this->m_pfDelayRead[6] = v23;
  this->m_pfDelayRead[7] = v17;
}

// File Line: 1125
// RVA: 0xAC29E0
void __fastcall CAkFDNReverbFX::ProcessMono12(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *v3; // r11
  float *v4; // r13
  float *v5; // r9
  float *v6; // rdi
  AkAudioBuffer *v7; // r8
  float v8; // xmm4_4
  float v9; // xmm7_4
  CAkFDNReverbFXParams *v10; // rdx
  __m128 v11; // xmm12
  float v12; // xmm10_4
  float v13; // xmm13_4
  float v14; // xmm14_4
  float v15; // xmm15_4
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  __m128 v18; // xmm0
  float *v19; // rax
  float *v20; // rdx
  __m128 v21; // xmm8
  float *v22; // rsi
  float *v23; // rbx
  __m128 v24; // xmm5
  __m128 v25; // xmm6
  __m128 v26; // xmm9
  float *v27; // rbp
  float *v28; // r14
  float *v29; // r15
  float *v30; // r12
  float *v31; // r10
  float *v32; // r8
  __m128 v33; // xmm1
  __m128 v34; // xmm0
  __m128 v35; // xmm3
  __m128 v36; // xmm4
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  __m128 v39; // xmm0
  __m128 v40; // xmm5
  __m128 v41; // xmm1
  __m128 v42; // xmm0
  bool v43; // cf
  float *v44; // rcx
  __m128 v45; // xmm3
  __m128 v46; // xmm6
  __m128 v47; // xmm8
  __m128 v48; // xmm0
  __m128 v49; // xmm1
  __m128 v50; // xmm2
  __m128 v51; // xmm4
  float *v52; // rcx
  __m128 v53; // xmm1
  __m128 v54; // xmm3
  __m128 v55; // xmm0
  __m128 v56; // xmm2
  __m128 v57; // xmm9
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
  __m128 v73; // xmm2
  __m128 v74; // xmm0
  __m128 v75; // xmm1
  __m128 v76; // xmm2
  __m128 v77; // xmm0
  __m128 v78; // xmm1
  float *v79; // [rsp+0h] [rbp-208h]
  float *v80; // [rsp+8h] [rbp-200h]
  float *v81; // [rsp+10h] [rbp-1F8h]
  float *v82; // [rsp+18h] [rbp-1F0h]
  float *v83; // [rsp+20h] [rbp-1E8h]
  float *v84; // [rsp+28h] [rbp-1E0h]
  float *v85; // [rsp+30h] [rbp-1D8h]
  float *v86; // [rsp+38h] [rbp-1D0h]
  float *v87; // [rsp+40h] [rbp-1C8h]
  __m128 v88; // [rsp+50h] [rbp-1B8h]
  float *v89; // [rsp+60h] [rbp-1A8h]
  float *v90; // [rsp+68h] [rbp-1A0h]
  float v91; // [rsp+70h] [rbp-198h]
  __m128 v92; // [rsp+80h] [rbp-188h]
  float v93; // [rsp+90h] [rbp-178h]
  __m128 v94; // [rsp+A0h] [rbp-168h]
  float v95; // [rsp+B0h] [rbp-158h]
  __m128 v96; // [rsp+C0h] [rbp-148h]
  __m128 v97; // [rsp+D0h] [rbp-138h]
  __m128 v98; // [rsp+E0h] [rbp-128h]
  float v99; // [rsp+F0h] [rbp-118h]
  __m128 v100; // [rsp+100h] [rbp-108h]
  __m128 v101; // [rsp+110h] [rbp-F8h]
  CAkFDNReverbFX *v102; // [rsp+210h] [rbp+8h]
  bool v103; // [rsp+218h] [rbp+10h]
  int v104; // [rsp+220h] [rbp+18h]
  float *v105; // [rsp+228h] [rbp+20h]

  v102 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  v3 = this->m_pfPreDelayRW;
  v4 = this->m_pfDelayStart[0];
  v5 = this->m_pfDelayWrite[1];
  v6 = this->m_pfDelayRead[2];
  v7 = io_pBuffer;
  LODWORD(v8) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(this->m_fDCFwdMem),
                                     (__m128)LODWORD(this->m_fDCFwdMem),
                                     0);
  LODWORD(v9) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(this->m_fDCFbkMem),
                                     (__m128)LODWORD(this->m_fDCFbkMem),
                                     0);
  v10 = this->m_pParams;
  v11 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v12) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      0);
  LODWORD(v13) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      0);
  LODWORD(v14) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fCurrentDry),
                                      (__m128)LODWORD(this->m_fCurrentDry),
                                      0);
  LODWORD(v15) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fCurrentWet),
                                      (__m128)LODWORD(this->m_fCurrentWet),
                                      0);
  v105 = this->m_pfDelayRead[1];
  LODWORD(v99) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      0);
  v91 = v8;
  v87 = (float *)v7->pData;
  v2.m128_f32[0] = -2.0 / (float)(signed int)v10->NonRTPC.uNumberOfDelays;
  v16 = v2;
  v17 = (__m128)LODWORD(v10->RTPC.fDryLevel);
  v97 = _mm_shuffle_ps(v16, v16, 0);
  v89 = this->m_pfPreDelayStart;
  v84 = this->m_pfDelayStart[1];
  v103 = this->m_pfPreDelayStart != 0i64;
  v83 = this->m_pfDelayStart[2];
  v82 = this->m_pfDelayEnd[0];
  v17.m128_f32[0] = (float)(v17.m128_f32[0] - this->m_fCurrentDry) * (float)(1.0 / (float)v7->uMaxFrames);
  v85 = this->m_pfDelayEnd[1];
  LODWORD(v93) = (unsigned __int128)_mm_shuffle_ps(v17, v17, 0);
  v18 = (__m128)LODWORD(v10->RTPC.fWetLevel);
  v86 = this->m_pfDelayEnd[2];
  v19 = this->m_pfDelayRead[0];
  v90 = this->m_pfPreDelayEnd;
  v20 = this->m_pfDelayWrite[0];
  v18.m128_f32[0] = (float)(v18.m128_f32[0] - this->m_fCurrentWet) * (float)(1.0 / (float)v7->uMaxFrames);
  LODWORD(v95) = (unsigned __int128)_mm_shuffle_ps(v18, v18, 0);
  v21 = this->m_vIIRLPFB0[0];
  v22 = this->m_pfDelayRead[3];
  v23 = this->m_pfDelayRead[4];
  v24 = this->m_vIIRLPFMem[0];
  v25 = this->m_vIIRLPFMem[1];
  v26 = this->m_vIIRLPFMem[2];
  v27 = this->m_pfDelayRead[6];
  v28 = this->m_pfDelayRead[7];
  v29 = this->m_pfDelayRead[8];
  v94 = this->m_vIIRLPFB0[1];
  v101 = this->m_vIIRLPFB0[0];
  v30 = this->m_pfDelayRead[10];
  v80 = this->m_pfDelayRead[5];
  v92 = this->m_vIIRLPFB0[2];
  v81 = this->m_pfDelayRead[9];
  v104 = v7->uValidFrames;
  v96 = this->m_vIIRLPFA1[0];
  v98 = this->m_vIIRLPFA1[1];
  v79 = this->m_pfDelayRead[11];
  v31 = this->m_pfDelayWrite[2];
  v100 = this->m_vIIRLPFA1[2];
  if ( v7->uValidFrames )
  {
    v32 = this->m_pfDelayRead[1];
    do
    {
      v33 = (__m128)*(unsigned int *)v19;
      v34 = (__m128)*(unsigned int *)v6;
      v19 += 4;
      if ( v19 >= v82 )
        v19 = v4;
      v105 = v32 + 4;
      v35 = (__m128)*(unsigned int *)v22;
      if ( v32 + 4 >= v82 )
        v105 = v4 + 1;
      v6 += 4;
      if ( v6 >= v82 )
        v6 = v4 + 2;
      v22 += 4;
      if ( v22 >= v82 )
        v22 = v4 + 3;
      v36 = (__m128)*(unsigned int *)v28;
      v23 += 4;
      v37 = (__m128)*(unsigned int *)v80;
      v38 = _mm_movelh_ps(_mm_unpacklo_ps(v33, (__m128)*(unsigned int *)v32), _mm_unpacklo_ps(v34, v35));
      v39 = _mm_mul_ps(v24, v96);
      v40 = _mm_mul_ps(v38, v21);
      v41 = (__m128)*((unsigned int *)v23 - 4);
      if ( v23 >= v85 )
        v23 = v84;
      v24 = _mm_add_ps(v40, v39);
      v42 = (__m128)*(unsigned int *)v27;
      v43 = v80 + 4 < v85;
      v80 += 4;
      v44 = v79;
      v45 = _mm_mul_ps(v24, vOutDecorrelationVectorA);
      if ( !v43 )
      {
        v80 = v84 + 1;
        v44 = v79;
      }
      v27 += 4;
      if ( v27 >= v85 )
        v27 = v84 + 2;
      v28 += 4;
      if ( v28 >= v85 )
        v28 = v84 + 3;
      v46 = _mm_mul_ps(v25, v98);
      v47 = (__m128)*(unsigned int *)v44;
      v29 += 4;
      v48 = _mm_unpacklo_ps(v42, v36);
      v49 = _mm_unpacklo_ps(v41, v37);
      v50 = (__m128)*((unsigned int *)v29 - 4);
      if ( v29 >= v86 )
        v29 = v83;
      v51 = (__m128)*(unsigned int *)v81;
      v43 = v81 + 4 < v86;
      v81 += 4;
      v52 = v79;
      v25 = _mm_add_ps(_mm_mul_ps(_mm_movelh_ps(v49, v48), v94), v46);
      v53 = _mm_add_ps(v25, v24);
      v54 = _mm_add_ps(v45, _mm_mul_ps(v25, vOutDecorrelationVectorA));
      v55 = (__m128)*(unsigned int *)v30;
      if ( !v43 )
      {
        v81 = v83 + 1;
        v52 = v79;
      }
      v30 += 4;
      if ( v30 >= v86 )
        v30 = v83 + 2;
      v79 = v52 + 4;
      if ( v52 + 4 >= v86 )
        v79 = v83 + 3;
      v14 = v14 + v93;
      v15 = v15 + v95;
      ++v87;
      v56 = _mm_unpacklo_ps(v50, v51);
      v8 = *(v87 - 1);
      v57 = _mm_add_ps(_mm_mul_ps(_mm_movelh_ps(v56, _mm_unpacklo_ps(v55, v47)), v92), _mm_mul_ps(v26, v100));
      v88 = v57;
      v58 = _mm_add_ps(_mm_mul_ps(v57, vOutDecorrelationVectorA), v54);
      v59 = _mm_add_ps(v58, _mm_movehl_ps(v58, v58));
      v60 = _mm_add_ps(v57, v53);
      v61 = _mm_add_ps(_mm_movehl_ps(v60, v60), v60);
      v62 = _mm_add_ps(_mm_shuffle_ps(v61, v61, 85), v61);
      v61.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v59, v59, 85)) + v59.m128_f32[0];
      v63 = _mm_mul_ps(_mm_shuffle_ps(v62, v62, 0), v97);
      v64 = _mm_add_ps(v57, v63);
      v65 = _mm_add_ps(v63, v24);
      *(v87 - 1) = (float)(v8 * v14) + (float)(v61.m128_f32[0] * v15);
      v66 = _mm_add_ps(v25, v63);
      v67 = _mm_shuffle_ps(v64, _mm_shuffle_ps(v64, v65, 15), 201);
      v68 = _mm_shuffle_ps(v66, _mm_shuffle_ps(v66, v64, 15), 201);
      v69 = _mm_shuffle_ps(v65, _mm_shuffle_ps(v65, v66, 15), 201);
      v9 = (float)((float)(v99 * v9) + v8) - v91;
      v91 = v8;
      if ( v103 )
      {
        v70 = *v3;
        *v3 = v9;
        ++v3;
        if ( v3 == v90 )
          v3 = v89;
      }
      else
      {
        v70 = v9;
      }
      v32 = v105;
      v20 += 4;
      v71 = v11;
      v72 = v13 * v12;
      v12 = v70;
      v71.m128_f32[0] = (float)(v11.m128_f32[0] * v70) + v72;
      v73 = _mm_shuffle_ps(v71, v71, 0);
      v74 = v73;
      v75 = v73;
      v76 = _mm_add_ps(v73, v67);
      v26 = v88;
      v77 = _mm_add_ps(v74, v69);
      v21 = v101;
      v78 = _mm_add_ps(v75, v68);
      *((__m128 *)v20 - 1) = v77;
      if ( v20 >= v82 )
        v20 = v4;
      v5 += 4;
      *((__m128 *)v5 - 1) = v78;
      if ( v5 >= v85 )
        v5 = v84;
      v31 += 4;
      *((__m128 *)v31 - 1) = v76;
      if ( v31 >= v86 )
        v31 = v83;
      --v104;
    }
    while ( v104 );
    this = v102;
  }
  this->m_fFIRLPFMem = v12;
  this->m_fDCFwdMem = v8;
  this->m_fDCFbkMem = v9;
  this->m_pfPreDelayRW = v3;
  this->m_pfDelayRead[0] = v19;
  this->m_vIIRLPFMem[1] = v25;
  this->m_vIIRLPFMem[2] = v26;
  this->m_vIIRLPFMem[0] = v24;
  this->m_pfDelayWrite[0] = v20;
  this->m_pfDelayWrite[1] = v5;
  this->m_pfDelayRead[1] = v105;
  this->m_pfDelayWrite[2] = v31;
  this->m_pfDelayRead[5] = v80;
  this->m_pfDelayRead[2] = v6;
  this->m_pfDelayRead[9] = v81;
  this->m_pfDelayRead[3] = v22;
  this->m_pfDelayRead[4] = v23;
  this->m_pfDelayRead[6] = v27;
  this->m_pfDelayRead[7] = v28;
  this->m_pfDelayRead[11] = v79;
  this->m_pfDelayRead[8] = v29;
  this->m_pfDelayRead[10] = v30;
}

// File Line: 1159
// RVA: 0xAC3150
void __fastcall CAkFDNReverbFX::ProcessMono16(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *v3; // r10
  float *v4; // r11
  AkAudioBuffer *v5; // r8
  CAkFDNReverbFXParams *v6; // rdx
  float v7; // xmm4_4
  __m128 v8; // xmm9
  __m128 v9; // xmm10
  float v10; // xmm11_4
  float *v11; // r9
  __m128 v12; // xmm14
  float v13; // xmm15_4
  float v14; // xmm13_4
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  float *v18; // rdx
  __m128 v19; // xmm8
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  __m128 v22; // xmm7
  float *v23; // rax
  float *v24; // rsi
  float *v25; // rbp
  float *v26; // r12
  float *v27; // r13
  float *v28; // r14
  __m128 v29; // xmm0
  float *v30; // rdi
  float *v31; // r15
  float *v32; // rbx
  float *v33; // r8
  __m128 v34; // xmm1
  __m128 v35; // xmm0
  __m128 v36; // xmm2
  __m128 v37; // xmm3
  __m128 v38; // xmm4
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  float *v41; // rcx
  __m128 v42; // xmm1
  __m128 v43; // xmm0
  __m128 v44; // xmm5
  __m128 v45; // xmm1
  __m128 v46; // xmm0
  __m128 v47; // xmm3
  __m128 v48; // xmm1
  __m128 v49; // xmm2
  float *v50; // r8
  __m128 v51; // xmm1
  __m128 v52; // xmm0
  __m128 v53; // xmm4
  __m128 v54; // xmm6
  __m128 v55; // xmm1
  __m128 v56; // xmm8
  __m128 v57; // xmm3
  __m128 v58; // xmm0
  bool v59; // cf
  float *v60; // rcx
  __m128 v61; // xmm1
  __m128 v62; // xmm2
  __m128 v63; // xmm1
  __m128 v64; // xmm0
  __m128 v65; // xmm7
  __m128 v66; // xmm1
  __m128 v67; // xmm8
  __m128 v68; // xmm3
  __m128 v69; // xmm0
  __m128 v70; // xmm4
  __m128 v71; // xmm1
  __m128 v72; // xmm2
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
  float *v109; // [rsp+78h] [rbp-200h]
  __m128 v110; // [rsp+80h] [rbp-1F8h]
  __m128 v111; // [rsp+90h] [rbp-1E8h]
  float *v112; // [rsp+A0h] [rbp-1D8h]
  float *v113; // [rsp+A8h] [rbp-1D0h]
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
  bool v129; // [rsp+288h] [rbp+10h]
  int v130; // [rsp+290h] [rbp+18h]
  float *v131; // [rsp+298h] [rbp+20h]

  v128 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  v3 = this->m_pfDelayWrite[1];
  v4 = this->m_pfDelayWrite[2];
  v5 = io_pBuffer;
  v6 = this->m_pParams;
  v112 = this->m_pfPreDelayEnd;
  LODWORD(v7) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(this->m_fDCFwdMem),
                                     (__m128)LODWORD(this->m_fDCFwdMem),
                                     0);
  v8 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  v9 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  LODWORD(v10) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      0);
  v11 = this->m_pfDelayWrite[0];
  v12 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v13) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      0);
  LODWORD(v14) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      0);
  LODWORD(v123) = (unsigned __int128)_mm_shuffle_ps(
                                       (__m128)LODWORD(this->m_fDCCoef),
                                       (__m128)LODWORD(this->m_fDCCoef),
                                       0);
  v114 = v7;
  v109 = (float *)v5->pData;
  v2.m128_f32[0] = -2.0 / (float)(signed int)v6->NonRTPC.uNumberOfDelays;
  v15 = v2;
  v16 = (__m128)LODWORD(v6->RTPC.fDryLevel);
  v121 = _mm_shuffle_ps(v15, v15, 0);
  v113 = this->m_pfPreDelayStart;
  v94 = this->m_pfDelayStart[0];
  v129 = this->m_pfPreDelayStart != 0i64;
  v97 = this->m_pfDelayStart[1];
  v100 = this->m_pfDelayStart[2];
  v16.m128_f32[0] = (float)(v16.m128_f32[0] - this->m_fCurrentDry) * (float)(1.0 / (float)v5->uMaxFrames);
  v99 = this->m_pfDelayStart[3];
  LODWORD(v117) = (unsigned __int128)_mm_shuffle_ps(v16, v16, 0);
  v17 = (__m128)LODWORD(v6->RTPC.fWetLevel);
  v18 = this->m_pfPreDelayRW;
  v101 = this->m_pfDelayEnd[0];
  v17.m128_f32[0] = (float)(v17.m128_f32[0] - this->m_fCurrentWet) * (float)(1.0 / (float)v5->uMaxFrames);
  v105 = this->m_pfDelayEnd[1];
  LODWORD(v119) = (unsigned __int128)_mm_shuffle_ps(v17, v17, 0);
  v107 = this->m_pfDelayEnd[2];
  v108 = this->m_pfDelayEnd[3];
  v19 = this->m_vIIRLPFB0[0];
  v20 = this->m_vIIRLPFMem[0];
  v21 = this->m_vIIRLPFMem[1];
  v22 = this->m_vIIRLPFMem[2];
  v23 = this->m_pfDelayRead[0];
  v24 = this->m_pfDelayRead[2];
  v25 = this->m_pfDelayRead[3];
  v122 = this->m_vIIRLPFB0[1];
  v127 = this->m_vIIRLPFB0[0];
  v26 = this->m_pfDelayRead[6];
  v27 = this->m_pfDelayRead[7];
  v28 = this->m_pfDelayRead[8];
  v126 = this->m_vIIRLPFB0[2];
  v131 = this->m_pfDelayRead[10];
  v124 = this->m_vIIRLPFB0[3];
  v120 = this->m_vIIRLPFA1[0];
  v102 = this->m_pfDelayRead[5];
  v118 = this->m_vIIRLPFA1[1];
  v104 = this->m_pfDelayRead[9];
  v106 = this->m_pfDelayRead[1];
  v115 = this->m_vIIRLPFA1[2];
  v116 = this->m_vIIRLPFA1[3];
  v29 = this->m_vIIRLPFMem[3];
  v30 = this->m_pfDelayRead[4];
  v95 = this->m_pfDelayRead[13];
  v110 = this->m_vIIRLPFMem[3];
  v96 = this->m_pfDelayRead[14];
  v103 = this->m_pfDelayRead[11];
  v31 = this->m_pfDelayRead[12];
  v98 = this->m_pfDelayRead[15];
  v32 = this->m_pfDelayWrite[3];
  v130 = v5->uValidFrames;
  if ( v5->uValidFrames )
  {
    v33 = this->m_pfDelayStart[0];
    do
    {
      v34 = (__m128)*(unsigned int *)v23;
      v35 = (__m128)*(unsigned int *)v24;
      v23 += 4;
      if ( v23 >= v101 )
        v23 = v33;
      v36 = (__m128)*(unsigned int *)v106;
      v37 = (__m128)*(unsigned int *)v25;
      v106 += 4;
      if ( v106 >= v101 )
        v106 = v33 + 1;
      v24 += 4;
      if ( v24 >= v101 )
        v24 = v33 + 2;
      v25 += 4;
      if ( v25 >= v101 )
        v25 = v33 + 3;
      v38 = (__m128)*(unsigned int *)v27;
      v30 += 4;
      v39 = _mm_unpacklo_ps(v34, v36);
      v40 = (__m128)*(unsigned int *)v102;
      v41 = v131;
      v42 = _mm_movelh_ps(v39, _mm_unpacklo_ps(v35, v37));
      v43 = _mm_mul_ps(v20, v120);
      v44 = _mm_mul_ps(v42, v19);
      v45 = (__m128)*((unsigned int *)v30 - 4);
      if ( v30 >= v105 )
        v30 = v97;
      v20 = _mm_add_ps(v44, v43);
      v46 = (__m128)*(unsigned int *)v26;
      v102 += 4;
      v47 = _mm_mul_ps(v20, vOutDecorrelationVectorA);
      if ( v102 >= v105 )
      {
        v102 = v97 + 1;
        v41 = v131;
      }
      v26 += 4;
      if ( v26 >= v105 )
        v26 = v97 + 2;
      v27 += 4;
      if ( v27 >= v105 )
        v27 = v97 + 3;
      v28 += 4;
      v48 = _mm_unpacklo_ps(v45, v40);
      v49 = (__m128)*(unsigned int *)v104;
      v50 = v103;
      v51 = _mm_mul_ps(_mm_movelh_ps(v48, _mm_unpacklo_ps(v46, v38)), v122);
      v52 = _mm_mul_ps(v21, v118);
      v53 = (__m128)*(unsigned int *)v103;
      v54 = v51;
      v55 = (__m128)*((unsigned int *)v28 - 4);
      if ( v28 >= v107 )
        v28 = v100;
      v21 = _mm_add_ps(v54, v52);
      v56 = _mm_add_ps(v21, v20);
      v57 = _mm_add_ps(v47, _mm_mul_ps(v21, vOutDecorrelationVectorA));
      v58 = (__m128)*(unsigned int *)v41;
      v59 = v104 + 4 < v107;
      v104 += 4;
      v60 = v131;
      if ( !v59 )
      {
        v104 = v100 + 1;
        v60 = v131;
      }
      v131 = v60 + 4;
      if ( v60 + 4 >= v107 )
        v131 = v100 + 2;
      v103 += 4;
      if ( v50 + 4 >= v107 )
        v103 = v100 + 3;
      v31 += 4;
      v61 = _mm_unpacklo_ps(v55, v49);
      v62 = (__m128)*(unsigned int *)v95;
      v63 = _mm_mul_ps(_mm_movelh_ps(v61, _mm_unpacklo_ps(v58, v53)), v126);
      v64 = _mm_mul_ps(v22, v115);
      v65 = v63;
      v66 = (__m128)*((unsigned int *)v31 - 4);
      if ( v31 >= v108 )
        v31 = v99;
      v22 = _mm_add_ps(v65, v64);
      v95 += 4;
      v67 = _mm_add_ps(v56, v22);
      v68 = _mm_add_ps(v57, _mm_mul_ps(v22, vOutDecorrelationVectorA));
      v69 = (__m128)*(unsigned int *)v96;
      v70 = (__m128)*(unsigned int *)v98;
      if ( v95 >= v108 )
        v95 = v99 + 1;
      v59 = v96 + 4 < v108;
      v96 += 4;
      v33 = v94;
      if ( !v59 )
        v96 = v99 + 2;
      v98 += 4;
      if ( v98 >= v108 )
        v98 = v99 + 3;
      v8.m128_f32[0] = v8.m128_f32[0] + v117;
      v9.m128_f32[0] = v9.m128_f32[0] + v119;
      ++v109;
      v71 = _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v66, v62), _mm_unpacklo_ps(v69, v70)), v124);
      v111 = v8;
      v125 = v9;
      v7 = *(v109 - 1);
      v72 = _mm_add_ps(v71, _mm_mul_ps(v110, v116));
      v110 = v72;
      v73 = _mm_add_ps(_mm_mul_ps(v72, vOutDecorrelationVectorA), v68);
      v74 = _mm_add_ps(v73, _mm_movehl_ps(v73, v73));
      v75 = _mm_add_ps(v110, v67);
      v76 = _mm_add_ps(_mm_movehl_ps(v75, v75), v75);
      v77 = _mm_add_ps(_mm_shuffle_ps(v76, v76, 85), v76);
      v76.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v74, v74, 85)) + v74.m128_f32[0];
      v78 = _mm_mul_ps(_mm_shuffle_ps(v77, v77, 0), v121);
      v79 = _mm_add_ps(v22, v78);
      v80 = _mm_add_ps(v78, v20);
      *(v109 - 1) = (float)(v7 * v8.m128_f32[0]) + (float)(v76.m128_f32[0] * v9.m128_f32[0]);
      v81 = _mm_add_ps(v110, v78);
      v82 = _mm_shuffle_ps(v81, _mm_shuffle_ps(v81, v80, 15), 201);
      v83 = _mm_shuffle_ps(v79, _mm_shuffle_ps(v79, v81, 15), 201);
      v84 = _mm_add_ps(v21, v78);
      v85 = _mm_shuffle_ps(v84, _mm_shuffle_ps(v84, v79, 15), 201);
      v86 = _mm_shuffle_ps(v80, _mm_shuffle_ps(v80, v84, 15), 201);
      v10 = (float)((float)(v123 * v10) + v7) - v114;
      v114 = v7;
      if ( v129 )
      {
        v87 = *v18;
        *v18 = v10;
        ++v18;
        if ( v18 == v112 )
          v18 = v113;
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
      v19 = v127;
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
      v32 += 4;
      *((__m128 *)v32 - 1) = v93;
      if ( v32 >= v108 )
        v32 = v99;
      --v130;
    }
    while ( v130 );
    v29 = v110;
    this = v128;
  }
  this->m_fFIRLPFMem = v14;
  this->m_fDCFwdMem = v7;
  this->m_fDCFbkMem = v10;
  this->m_pfPreDelayRW = v18;
  this->m_pfDelayRead[0] = v23;
  this->m_vIIRLPFMem[1] = v21;
  this->m_vIIRLPFMem[2] = v22;
  this->m_vIIRLPFMem[0] = v20;
  this->m_pfDelayRead[1] = v106;
  this->m_pfDelayWrite[2] = v4;
  this->m_vIIRLPFMem[3] = v29;
  this->m_pfDelayRead[5] = v102;
  this->m_pfDelayRead[9] = v104;
  this->m_pfDelayWrite[0] = v11;
  this->m_pfDelayRead[10] = v131;
  this->m_pfDelayWrite[1] = v3;
  this->m_pfDelayRead[11] = v103;
  this->m_pfDelayWrite[3] = v32;
  this->m_pfDelayRead[13] = v95;
  this->m_pfDelayRead[2] = v24;
  this->m_pfDelayRead[14] = v96;
  this->m_pfDelayRead[3] = v25;
  this->m_pfDelayRead[4] = v30;
  this->m_pfDelayRead[6] = v26;
  this->m_pfDelayRead[7] = v27;
  this->m_pfDelayRead[15] = v98;
  this->m_pfDelayRead[8] = v28;
  this->m_pfDelayRead[12] = v31;
}

// File Line: 1197
// RVA: 0xAC3AF0
void __fastcall CAkFDNReverbFX::ProcessStereo4(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *v3; // r14
  float *v4; // r9
  float *v5; // r15
  float *v6; // rbx
  float *v7; // rsi
  AkAudioBuffer *v8; // r12
  CAkFDNReverbFXParams *v9; // rdx
  float v10; // xmm7_4
  float v11; // xmm6_4
  __m128 v12; // xmm9
  float v13; // xmm10_4
  int v14; // ebp
  float *v15; // r13
  float v16; // xmm12_4
  float v17; // xmm13_4
  float v18; // xmm14_4
  CAkFDNReverbFX *v19; // r8
  float v20; // xmm15_4
  float *v21; // rdi
  float *v22; // r10
  float *v23; // r11
  __m128 v24; // xmm4
  __m128 v25; // xmm5
  __m128 v26; // xmm11
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  float v29; // xmm2_4
  __m128 v30; // xmm0
  float *v31; // rdx
  float *v32; // rcx
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm0
  __m128 v36; // xmm3
  __int64 v37; // rax
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
  v3 = this->m_pfPreDelayStart;
  v4 = this->m_pfPreDelayRW;
  v5 = this->m_pfPreDelayEnd;
  v6 = this->m_pfDelayStart[0];
  v7 = this->m_pfDelayEnd[0];
  v8 = io_pBuffer;
  v9 = this->m_pParams;
  LODWORD(v10) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      0);
  LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      0);
  v12 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v13) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      0);
  v14 = v8->uValidFrames;
  v15 = (float *)v8->pData;
  LODWORD(v16) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fCurrentDry),
                                      (__m128)LODWORD(this->m_fCurrentDry),
                                      0);
  LODWORD(v17) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fCurrentWet),
                                      (__m128)LODWORD(this->m_fCurrentWet),
                                      0);
  LODWORD(v18) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      0);
  v19 = this;
  LODWORD(v20) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      0);
  v21 = this->m_pfDelayRead[1];
  v22 = this->m_pfDelayRead[2];
  v23 = this->m_pfDelayRead[3];
  v24 = this->m_vIIRLPFB0[0];
  v25 = this->m_vIIRLPFA1[0];
  v26 = this->m_vIIRLPFMem[0];
  v2.m128_f32[0] = -2.0 / (float)(signed int)v9->NonRTPC.uNumberOfDelays;
  v57 = this->m_vIIRLPFB0[0];
  v58 = this->m_vIIRLPFA1[0];
  v27 = v2;
  v28 = (__m128)LODWORD(v9->RTPC.fDryLevel);
  v56 = _mm_shuffle_ps(v27, v27, 0);
  v29 = 1.0 / (float)v8->uMaxFrames;
  v28.m128_f32[0] = (float)(v28.m128_f32[0] - this->m_fCurrentDry) * v29;
  LODWORD(v54) = (unsigned __int128)_mm_shuffle_ps(v28, v28, 0);
  v30 = (__m128)LODWORD(v9->RTPC.fWetLevel);
  v31 = this->m_pfDelayRead[0];
  v30.m128_f32[0] = v30.m128_f32[0] - this->m_fCurrentWet;
  v32 = this->m_pfDelayWrite[0];
  v30.m128_f32[0] = v30.m128_f32[0] * v29;
  LODWORD(v55) = (unsigned __int128)_mm_shuffle_ps(v30, v30, 0);
  if ( v8->uValidFrames )
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
      v37 = v8->uMaxFrames;
      v38 = _mm_mul_ps(v26, v25);
      v39 = *v15;
      v40 = _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v33, v34), _mm_unpacklo_ps(v35, v36)), v24);
      v41 = v15[v37];
      ++v15;
      v26 = _mm_add_ps(v40, v38);
      v42 = _mm_mul_ps(v26, vOutDecorrelationVectorA);
      v43 = _mm_mul_ps(v26, vOutDecorrelationVectorB);
      v44 = _mm_add_ps(v42, _mm_movehl_ps(v42, v42));
      v45 = _mm_add_ps(v43, _mm_movehl_ps(v43, v43));
      v46 = _mm_add_ps(_mm_movehl_ps(v26, v26), v26);
      v47 = _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), v46);
      v46.m128_f32[0] = v39;
      v48 = v39 + v41;
      *(v15 - 1) = (float)(v46.m128_f32[0] * v16)
                 + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 85)) + v44.m128_f32[0]) * v17);
      v49 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v47, v47, 0), v56), v26);
      v15[v37 - 1] = (float)(v41 * v16)
                   + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v45, v45, 85)) + v45.m128_f32[0]) * v17);
      v50 = _mm_shuffle_ps(v49, _mm_shuffle_ps(v49, v49, 15), 201);
      v11 = (float)((float)(v20 * v11) + v48) - v18;
      v18 = v48;
      if ( v3 != 0i64 )
      {
        v51 = *v4;
        *v4 = v11;
        ++v4;
        if ( v4 == v5 )
          v4 = v3;
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
      --v14;
    }
    while ( v14 );
  }
  v19->m_fFIRLPFMem = v10;
  v19->m_fDCFwdMem = v18;
  v19->m_fDCFbkMem = v11;
  v19->m_pfPreDelayRW = v4;
  v19->m_pfDelayRead[3] = v23;
  v19->m_vIIRLPFMem[0] = v26;
  v19->m_pfDelayWrite[0] = v32;
  v19->m_pfDelayRead[0] = v31;
  v19->m_pfDelayRead[1] = v21;
  v19->m_pfDelayRead[2] = v22;
}

// File Line: 1225
// RVA: 0xAC3F00
void __fastcall CAkFDNReverbFX::ProcessStereo8(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  __m128 v3; // xmm4
  float *v4; // r10
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
  AkAudioBuffer *v21; // r8
  CAkFDNReverbFXParams *v22; // rdx
  float *v23; // rsi
  signed int v24; // eax
  float *v25; // r8
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  __m128 v28; // xmm0
  float *v29; // rdx
  __m128 v30; // xmm6
  int v31; // eax
  __m128 v32; // xmm7
  bool v33; // zf
  float *v34; // rax
  __m128 v35; // xmm0
  float *v36; // rcx
  __m128 v37; // xmm1
  __m128 v38; // xmm2
  __m128 v39; // xmm0
  __m128 v40; // xmm3
  __m128 v41; // xmm5
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm1
  __m128 v45; // xmm4
  __m128 v46; // xmm0
  __m128 v47; // xmm1
  __m128 v48; // xmm3
  float *v49; // rcx
  float *v50; // rax
  float v51; // xmm6_4
  __m128 v52; // xmm4
  __int64 v53; // rax
  __m128 v54; // xmm2
  float v55; // xmm5_4
  __m128 v56; // xmm4
  __m128 v57; // xmm2
  __m128 v58; // xmm2
  __m128 v59; // xmm4
  __m128 v60; // xmm0
  __m128 v61; // xmm1
  __m128 v62; // xmm3
  __m128 v63; // xmm3
  __m128 v64; // xmm4
  __m128 v65; // xmm1
  __m128 v66; // xmm3
  __m128 v67; // xmm4
  float v68; // xmm2_4
  __m128 v69; // xmm1
  float v70; // xmm0_4
  __m128 v71; // xmm0
  __m128 v72; // xmm1
  __m128 v73; // xmm0
  float *v74; // [rsp+0h] [rbp-1B8h]
  float *v75; // [rsp+8h] [rbp-1B0h]
  float *v76; // [rsp+10h] [rbp-1A8h]
  __m128 v77; // [rsp+20h] [rbp-198h]
  float *v78; // [rsp+30h] [rbp-188h]
  float *v79; // [rsp+38h] [rbp-180h]
  float v80; // [rsp+40h] [rbp-178h]
  __m128 v81; // [rsp+50h] [rbp-168h]
  __m128 v82; // [rsp+60h] [rbp-158h]
  __m128 v83; // [rsp+70h] [rbp-148h]
  float v84; // [rsp+80h] [rbp-138h]
  float v85; // [rsp+90h] [rbp-128h]
  __m128 v86; // [rsp+A0h] [rbp-118h]
  float v87; // [rsp+B0h] [rbp-108h]
  __m128 v88; // [rsp+C0h] [rbp-F8h]
  CAkFDNReverbFX *v89; // [rsp+1C0h] [rbp+8h]
  AkAudioBuffer *v90; // [rsp+1C8h] [rbp+10h]
  bool v91; // [rsp+1D0h] [rbp+18h]
  int v92; // [rsp+1D8h] [rbp+20h]

  v90 = io_pBuffer;
  v89 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  v3 = this->m_vIIRLPFB0[0];
  v4 = this->m_pfPreDelayRW;
  v5 = this->m_pfDelayStart[0];
  v6 = this->m_pfDelayStart[1];
  v7 = this->m_pfDelayEnd[0];
  LODWORD(v84) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      0);
  LODWORD(v8) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(this->m_fDCFwdMem),
                                     (__m128)LODWORD(this->m_fDCFwdMem),
                                     0);
  v9 = this->m_pfDelayWrite[1];
  v10 = this->m_pfDelayRead[1];
  v11 = this->m_pfDelayRead[2];
  LODWORD(v12) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      0);
  v13 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v14) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      0);
  v15 = this->m_pfDelayRead[3];
  v16 = this->m_pfDelayRead[4];
  v17 = this->m_pfDelayRead[7];
  LODWORD(v18) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      0);
  LODWORD(v19) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fCurrentDry),
                                      (__m128)LODWORD(this->m_fCurrentDry),
                                      0);
  LODWORD(v20) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fCurrentWet),
                                      (__m128)LODWORD(this->m_fCurrentWet),
                                      0);
  v80 = v8;
  v86 = this->m_vIIRLPFB0[0];
  v21 = io_pBuffer;
  v22 = this->m_pParams;
  v74 = this->m_pfDelayRead[5];
  v23 = this->m_pfDelayRead[6];
  v75 = (float *)v21->pData;
  v24 = v21->uMaxFrames;
  v25 = this->m_pfDelayWrite[0];
  v2.m128_f32[0] = -2.0 / (float)(signed int)v22->NonRTPC.uNumberOfDelays;
  v26 = v2;
  v27 = (__m128)LODWORD(v22->RTPC.fDryLevel);
  v82 = _mm_shuffle_ps(v26, v26, 0);
  v79 = this->m_pfPreDelayStart;
  v91 = this->m_pfPreDelayStart != 0i64;
  v76 = this->m_pfDelayEnd[1];
  v27.m128_f32[0] = (float)(v27.m128_f32[0] - this->m_fCurrentDry) * (float)(1.0 / (float)v24);
  LODWORD(v87) = (unsigned __int128)_mm_shuffle_ps(v27, v27, 0);
  v28 = (__m128)LODWORD(v22->RTPC.fWetLevel);
  v78 = this->m_pfPreDelayEnd;
  v29 = this->m_pfDelayRead[0];
  v28.m128_f32[0] = (float)(v28.m128_f32[0] - this->m_fCurrentWet) * (float)(1.0 / (float)v24);
  LODWORD(v85) = (unsigned __int128)_mm_shuffle_ps(v28, v28, 0);
  v81 = this->m_vIIRLPFB0[1];
  v30 = this->m_vIIRLPFA1[0];
  v31 = v90->uValidFrames;
  v32 = this->m_vIIRLPFMem[0];
  v83 = this->m_vIIRLPFA1[1];
  v92 = v31;
  v33 = v31 == 0;
  v34 = this->m_pfDelayEnd[1];
  v35 = this->m_vIIRLPFMem[1];
  v88 = this->m_vIIRLPFA1[0];
  v77 = this->m_vIIRLPFMem[1];
  if ( !v33 )
  {
    v36 = this->m_pfDelayRead[5];
    do
    {
      v37 = (__m128)*(unsigned int *)v29;
      v38 = (__m128)*(unsigned int *)v10;
      v39 = (__m128)*(unsigned int *)v11;
      v29 += 4;
      if ( v29 >= v7 )
        v29 = v5;
      v10 += 4;
      v40 = (__m128)*(unsigned int *)v15;
      if ( v10 >= v7 )
        v10 = v5 + 1;
      v11 += 4;
      if ( v11 >= v7 )
        v11 = v5 + 2;
      v15 += 4;
      if ( v15 >= v7 )
        v15 = v5 + 3;
      v41 = (__m128)*(unsigned int *)v17;
      v42 = _mm_unpacklo_ps(v37, v38);
      v43 = (__m128)*(unsigned int *)v16;
      v44 = _mm_mul_ps(_mm_movelh_ps(v42, _mm_unpacklo_ps(v39, v40)), v3);
      v45 = (__m128)*(unsigned int *)v36;
      v16 += 4;
      if ( v16 >= v34 )
        v16 = v6;
      v74 = v36 + 4;
      v32 = _mm_add_ps(v44, _mm_mul_ps(v32, v30));
      v46 = (__m128)*(unsigned int *)v23;
      v47 = _mm_mul_ps(v32, vOutDecorrelationVectorA);
      v48 = _mm_mul_ps(v32, vOutDecorrelationVectorB);
      if ( v36 + 4 >= v34 )
        v74 = v6 + 1;
      v23 += 4;
      if ( v23 >= v34 )
        v23 = v6 + 2;
      v17 += 4;
      if ( v17 >= v34 )
        v17 = v6 + 3;
      v49 = v75;
      v50 = v75;
      v19 = v19 + v87;
      ++v75;
      v51 = *v50;
      v20 = v20 + v85;
      v52 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v43, v45), _mm_unpacklo_ps(v46, v41)), v81),
              _mm_mul_ps(v77, v83));
      v53 = v90->uMaxFrames;
      v77 = v52;
      v54 = v52;
      v55 = v49[v53];
      v56 = _mm_add_ps(_mm_mul_ps(v52, vOutDecorrelationVectorB), v48);
      v57 = _mm_add_ps(_mm_mul_ps(v54, vOutDecorrelationVectorA), v47);
      v58 = _mm_add_ps(v57, _mm_movehl_ps(v57, v57));
      v59 = _mm_add_ps(v56, _mm_movehl_ps(v56, v56));
      v60 = _mm_add_ps(v77, v32);
      v61 = _mm_add_ps(_mm_movehl_ps(v60, v60), v60);
      v62 = _mm_add_ps(_mm_shuffle_ps(v61, v61, 85), v61);
      v63 = _mm_mul_ps(_mm_shuffle_ps(v62, v62, 0), v82);
      *v49 = (float)(v51 * v19) + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v58, v58, 85)) + v58.m128_f32[0]) * v20);
      v61.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v59, v59, 85)) + v59.m128_f32[0];
      v60.m128_f32[0] = v55 * v19;
      v8 = v51 + v55;
      v64 = _mm_add_ps(v63, v32);
      v49[v53] = v60.m128_f32[0] + (float)(v61.m128_f32[0] * v20);
      v65 = _mm_add_ps(v77, v63);
      v66 = _mm_shuffle_ps(v65, _mm_shuffle_ps(v65, v64, 15), 201);
      v67 = _mm_shuffle_ps(v64, _mm_shuffle_ps(v64, v65, 15), 201);
      v12 = (float)((float)(v84 * v12) + v8) - v80;
      v80 = v8;
      if ( v91 )
      {
        v68 = *v4;
        *v4 = v12;
        ++v4;
        if ( v4 == v78 )
          v4 = v79;
      }
      else
      {
        v68 = v12;
      }
      v34 = v76;
      v30 = v88;
      v36 = v74;
      v25 += 4;
      v69 = v13;
      v70 = v18 * v14;
      v14 = v68;
      v69.m128_f32[0] = (float)(v13.m128_f32[0] * v68) + v70;
      v71 = _mm_shuffle_ps(v69, v69, 0);
      v72 = _mm_add_ps(v71, v66);
      v73 = _mm_add_ps(v71, v67);
      v3 = v86;
      *((__m128 *)v25 - 1) = v73;
      if ( v25 >= v7 )
        v25 = v5;
      *(__m128 *)v9 = v72;
      v9 += 4;
      if ( v9 >= v76 )
        v9 = v6;
      --v92;
    }
    while ( v92 );
    v35 = v77;
    this = v89;
  }
  this->m_fFIRLPFMem = v14;
  this->m_fDCFwdMem = v8;
  this->m_fDCFbkMem = v12;
  this->m_pfPreDelayRW = v4;
  this->m_pfDelayRead[4] = v16;
  this->m_vIIRLPFMem[0] = v32;
  this->m_vIIRLPFMem[1] = v35;
  this->m_pfDelayWrite[0] = v25;
  this->m_pfDelayWrite[1] = v9;
  this->m_pfDelayRead[0] = v29;
  this->m_pfDelayRead[1] = v10;
  this->m_pfDelayRead[2] = v11;
  this->m_pfDelayRead[3] = v15;
  this->m_pfDelayRead[5] = v74;
  this->m_pfDelayRead[6] = v23;
  this->m_pfDelayRead[7] = v17;
}

// File Line: 1258
// RVA: 0xAC44D0
void __fastcall CAkFDNReverbFX::ProcessStereo12(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *v3; // r11
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
  AkAudioBuffer *v15; // r8
  CAkFDNReverbFXParams *v16; // rdx
  __m128 v17; // xmm14
  float v18; // xmm15_4
  signed int v19; // eax
  float *v20; // r8
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  __m128 v23; // xmm0
  float *v24; // rdx
  __m128 v25; // xmm4
  float *v26; // r14
  float *v27; // r15
  float *v28; // rdi
  __m128 v29; // xmm6
  __m128 v30; // xmm7
  __m128 v31; // xmm8
  int v32; // eax
  bool v33; // zf
  float *v34; // rax
  __m128 v35; // xmm0
  float *v36; // rax
  __m128 v37; // xmm1
  __m128 v38; // xmm2
  __m128 v39; // xmm0
  __m128 v40; // xmm3
  __m128 v41; // xmm5
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm0
  __m128 v45; // xmm7
  __m128 v46; // xmm1
  __m128 v47; // xmm0
  bool v48; // cf
  float *v49; // rcx
  __m128 v50; // xmm3
  __m128 v51; // xmm4
  __m128 v52; // xmm8
  __m128 v53; // xmm0
  __m128 v54; // xmm5
  float *v55; // rax
  __m128 v56; // xmm1
  __m128 v57; // xmm2
  __m128 v58; // xmm6
  __m128 v59; // xmm1
  __m128 v60; // xmm3
  __m128 v61; // xmm4
  __m128 v62; // xmm0
  float *v63; // rcx
  float *v64; // rax
  __m128 v65; // xmm0
  float v66; // xmm6_4
  __int64 v67; // rax
  float v68; // xmm5_4
  __m128 v69; // xmm2
  __m128 v70; // xmm2
  __m128 v71; // xmm3
  __m128 v72; // xmm3
  __m128 v73; // xmm0
  __m128 v74; // xmm1
  __m128 v75; // xmm0
  __m128 v76; // xmm4
  __m128 v77; // xmm4
  __m128 v78; // xmm2
  __m128 v79; // xmm3
  __m128 v80; // xmm1
  __m128 v81; // xmm10
  __m128 v82; // xmm4
  __m128 v83; // xmm3
  float v84; // xmm1_4
  __m128 v85; // xmm2
  float v86; // xmm0_4
  __m128 v87; // xmm2
  __m128 v88; // xmm0
  __m128 v89; // xmm1
  __m128 v90; // xmm2
  __m128 v91; // xmm1
  float *v92; // [rsp+0h] [rbp-238h]
  float *v93; // [rsp+8h] [rbp-230h]
  float *v94; // [rsp+10h] [rbp-228h]
  float *v95; // [rsp+18h] [rbp-220h]
  float *v96; // [rsp+20h] [rbp-218h]
  float *v97; // [rsp+28h] [rbp-210h]
  float *v98; // [rsp+30h] [rbp-208h]
  float *v99; // [rsp+38h] [rbp-200h]
  __m128 v100; // [rsp+40h] [rbp-1F8h]
  float *v101; // [rsp+50h] [rbp-1E8h]
  float *v102; // [rsp+58h] [rbp-1E0h]
  float *v103; // [rsp+60h] [rbp-1D8h]
  __m128 v104; // [rsp+70h] [rbp-1C8h]
  float *v105; // [rsp+80h] [rbp-1B8h]
  float v106; // [rsp+90h] [rbp-1A8h]
  __m128 v107; // [rsp+A0h] [rbp-198h]
  float v108; // [rsp+B0h] [rbp-188h]
  __m128 v109; // [rsp+C0h] [rbp-178h]
  __m128 v110; // [rsp+D0h] [rbp-168h]
  float v111; // [rsp+E0h] [rbp-158h]
  float v112; // [rsp+F0h] [rbp-148h]
  __m128 v113; // [rsp+100h] [rbp-138h]
  __m128 v114; // [rsp+110h] [rbp-128h]
  __m128 v115; // [rsp+120h] [rbp-118h]
  __m128 v116; // [rsp+130h] [rbp-108h]
  __m128 v117; // [rsp+140h] [rbp-F8h]
  CAkFDNReverbFX *v118; // [rsp+240h] [rbp+8h]
  AkAudioBuffer *v119; // [rsp+248h] [rbp+10h]
  bool v120; // [rsp+250h] [rbp+18h]
  int v121; // [rsp+258h] [rbp+20h]

  v119 = io_pBuffer;
  v118 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  v3 = this->m_pfPreDelayRW;
  v4 = this->m_pfDelayStart[0];
  v5 = this->m_pfDelayWrite[1];
  v6 = this->m_pfDelayWrite[2];
  v7 = this->m_pfDelayRead[1];
  v8 = this->m_pfDelayRead[2];
  LODWORD(v111) = (unsigned __int128)_mm_shuffle_ps(
                                       (__m128)LODWORD(this->m_fDCCoef),
                                       (__m128)LODWORD(this->m_fDCCoef),
                                       0);
  LODWORD(v9) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(this->m_fDCFwdMem),
                                     (__m128)LODWORD(this->m_fDCFwdMem),
                                     0);
  v10 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      0);
  v12 = this->m_pfDelayRead[3];
  v13 = this->m_pfDelayRead[4];
  LODWORD(v14) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      0);
  v15 = io_pBuffer;
  v16 = this->m_pParams;
  v17 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v18) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      0);
  v106 = v9;
  v98 = (float *)v15->pData;
  v19 = v15->uMaxFrames;
  v20 = this->m_pfDelayWrite[0];
  v2.m128_f32[0] = -2.0 / (float)(signed int)v16->NonRTPC.uNumberOfDelays;
  v21 = v2;
  v22 = (__m128)LODWORD(v16->RTPC.fDryLevel);
  v109 = _mm_shuffle_ps(v21, v21, 0);
  v104 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  v103 = this->m_pfPreDelayStart;
  v102 = this->m_pfDelayStart[1];
  v120 = this->m_pfPreDelayStart != 0i64;
  v94 = this->m_pfDelayStart[2];
  v101 = this->m_pfDelayEnd[0];
  v22.m128_f32[0] = (float)(v22.m128_f32[0] - this->m_fCurrentDry) * (float)(1.0 / (float)v19);
  v96 = this->m_pfDelayEnd[1];
  LODWORD(v112) = (unsigned __int128)_mm_shuffle_ps(v22, v22, 0);
  v23 = (__m128)LODWORD(v16->RTPC.fWetLevel);
  v99 = this->m_pfDelayEnd[2];
  v105 = this->m_pfPreDelayEnd;
  v24 = this->m_pfDelayRead[0];
  v23.m128_f32[0] = (float)(v23.m128_f32[0] - this->m_fCurrentWet) * (float)(1.0 / (float)v19);
  LODWORD(v108) = (unsigned __int128)_mm_shuffle_ps(v23, v23, 0);
  v25 = this->m_vIIRLPFB0[0];
  v26 = this->m_pfDelayRead[6];
  v27 = this->m_pfDelayRead[7];
  v28 = this->m_pfDelayRead[8];
  v29 = this->m_vIIRLPFA1[0];
  v30 = this->m_vIIRLPFMem[0];
  v31 = this->m_vIIRLPFMem[1];
  v97 = this->m_pfDelayRead[5];
  v95 = this->m_pfDelayRead[9];
  v110 = this->m_vIIRLPFB0[1];
  v115 = this->m_vIIRLPFB0[0];
  v92 = this->m_pfDelayRead[10];
  v107 = this->m_vIIRLPFB0[2];
  v117 = this->m_vIIRLPFA1[0];
  v93 = this->m_pfDelayRead[11];
  v32 = v119->uValidFrames;
  v116 = this->m_vIIRLPFA1[1];
  v121 = v32;
  v33 = v32 == 0;
  v34 = this->m_pfDelayRead[10];
  v114 = this->m_vIIRLPFA1[2];
  v35 = this->m_vIIRLPFMem[2];
  v100 = this->m_vIIRLPFMem[2];
  if ( !v33 )
  {
    v36 = this->m_pfDelayEnd[0];
    do
    {
      v37 = (__m128)*(unsigned int *)v24;
      v38 = (__m128)*(unsigned int *)v7;
      v39 = (__m128)*(unsigned int *)v8;
      v24 += 4;
      if ( v24 >= v36 )
        v24 = v4;
      v7 += 4;
      v40 = (__m128)*(unsigned int *)v12;
      if ( v7 >= v36 )
        v7 = v4 + 1;
      v8 += 4;
      if ( v8 >= v36 )
        v8 = v4 + 2;
      v12 += 4;
      if ( v12 >= v36 )
        v12 = v4 + 3;
      v41 = (__m128)*(unsigned int *)v27;
      v13 += 4;
      v42 = _mm_movelh_ps(_mm_unpacklo_ps(v37, v38), _mm_unpacklo_ps(v39, v40));
      v43 = (__m128)*(unsigned int *)v97;
      v44 = _mm_mul_ps(v30, v29);
      v45 = _mm_mul_ps(v42, v25);
      v46 = (__m128)*((unsigned int *)v13 - 4);
      if ( v13 >= v96 )
        v13 = v102;
      v30 = _mm_add_ps(v45, v44);
      v47 = (__m128)*(unsigned int *)v26;
      v48 = v97 + 4 < v96;
      v97 += 4;
      v49 = v92;
      v50 = _mm_mul_ps(v30, vOutDecorrelationVectorA);
      v51 = _mm_mul_ps(v30, vOutDecorrelationVectorB);
      if ( !v48 )
      {
        v97 = v102 + 1;
        v49 = v92;
      }
      v26 += 4;
      if ( v26 >= v96 )
        v26 = v102 + 2;
      v27 += 4;
      if ( v27 >= v96 )
        v27 = v102 + 3;
      v52 = _mm_mul_ps(v31, v116);
      v53 = _mm_unpacklo_ps(v47, v41);
      v28 += 4;
      v54 = (__m128)*(unsigned int *)v95;
      v55 = v93;
      v56 = _mm_unpacklo_ps(v46, v43);
      v57 = (__m128)*((unsigned int *)v28 - 4);
      if ( v28 >= v99 )
        v28 = v94;
      v58 = (__m128)*(unsigned int *)v93;
      v31 = _mm_add_ps(_mm_mul_ps(_mm_movelh_ps(v56, v53), v110), v52);
      v59 = _mm_add_ps(v31, v30);
      v60 = _mm_add_ps(v50, _mm_mul_ps(v31, vOutDecorrelationVectorA));
      v61 = _mm_add_ps(v51, _mm_mul_ps(v31, vOutDecorrelationVectorB));
      v62 = (__m128)*(unsigned int *)v49;
      v95 += 4;
      if ( v95 >= v99 )
      {
        v95 = v94 + 1;
        v55 = v93;
      }
      v92 += 4;
      if ( v92 >= v99 )
        v92 = v94 + 2;
      v93 = v55 + 4;
      if ( v55 + 4 >= v99 )
        v93 = v94 + 3;
      v10.m128_f32[0] = v10.m128_f32[0] + v112;
      v63 = v98;
      v64 = v98;
      v65 = _mm_unpacklo_ps(v62, v58);
      ++v98;
      v66 = *v64;
      v113 = v10;
      v67 = v119->uMaxFrames;
      v100 = _mm_add_ps(_mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v57, v54), v65), v107), _mm_mul_ps(v100, v114));
      v68 = v63[v67];
      v69 = _mm_add_ps(_mm_mul_ps(v100, vOutDecorrelationVectorA), v60);
      v70 = _mm_add_ps(v69, _mm_movehl_ps(v69, v69));
      v71 = _mm_add_ps(_mm_mul_ps(v100, vOutDecorrelationVectorB), v61);
      v72 = _mm_add_ps(v71, _mm_movehl_ps(v71, v71));
      v73 = _mm_add_ps(v100, v59);
      v74 = _mm_add_ps(_mm_movehl_ps(v73, v73), v73);
      v75 = v104;
      v75.m128_f32[0] = v104.m128_f32[0] + v108;
      v104 = v75;
      v76 = _mm_add_ps(_mm_shuffle_ps(v74, v74, 85), v74);
      v77 = _mm_mul_ps(_mm_shuffle_ps(v76, v76, 0), v109);
      v74.m128_f32[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v70, v70, 85)) + v70.m128_f32[0]) * v75.m128_f32[0];
      v78 = _mm_add_ps(v100, v77);
      *v63 = (float)(v66 * v10.m128_f32[0]) + v74.m128_f32[0];
      v74.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v72, v72, 85)) + v72.m128_f32[0];
      v79 = _mm_add_ps(v77, v30);
      v63[v67] = (float)(v68 * v10.m128_f32[0]) + (float)(v74.m128_f32[0] * v75.m128_f32[0]);
      v80 = _mm_add_ps(v31, v77);
      v81 = _mm_shuffle_ps(v78, _mm_shuffle_ps(v78, v79, 15), 201);
      v82 = _mm_shuffle_ps(v80, _mm_shuffle_ps(v80, v78, 15), 201);
      v83 = _mm_shuffle_ps(v79, _mm_shuffle_ps(v79, v80, 15), 201);
      v9 = v66 + v68;
      v11 = (float)((float)(v111 * v11) + v9) - v106;
      v106 = v9;
      if ( v120 )
      {
        v84 = *v3;
        *v3 = v11;
        ++v3;
        if ( v3 == v105 )
          v3 = v103;
      }
      else
      {
        v84 = v11;
      }
      v36 = v101;
      v29 = v117;
      v20 += 4;
      v85 = v17;
      v86 = v18 * v14;
      v14 = v84;
      v85.m128_f32[0] = (float)(v17.m128_f32[0] * v84) + v86;
      v87 = _mm_shuffle_ps(v85, v85, 0);
      v88 = v87;
      v89 = v87;
      v90 = _mm_add_ps(v87, v81);
      v10 = v113;
      v91 = _mm_add_ps(v89, v82);
      v25 = v115;
      *((__m128 *)v20 - 1) = _mm_add_ps(v88, v83);
      if ( v20 >= v101 )
        v20 = v4;
      *(__m128 *)v5 = v91;
      v5 += 4;
      if ( v5 >= v96 )
        v5 = v102;
      *(__m128 *)v6 = v90;
      v6 += 4;
      if ( v6 >= v99 )
        v6 = v94;
      --v121;
    }
    while ( v121 );
    v35 = v100;
    this = v118;
    v34 = v92;
  }
  this->m_fFIRLPFMem = v14;
  this->m_fDCFwdMem = v9;
  this->m_fDCFbkMem = v11;
  this->m_pfPreDelayRW = v3;
  this->m_pfDelayRead[0] = v24;
  this->m_vIIRLPFMem[0] = v30;
  this->m_vIIRLPFMem[1] = v31;
  this->m_vIIRLPFMem[2] = v35;
  this->m_pfDelayRead[10] = v34;
  this->m_pfDelayRead[5] = v97;
  this->m_pfDelayWrite[0] = v20;
  this->m_pfDelayWrite[1] = v5;
  this->m_pfDelayWrite[2] = v6;
  this->m_pfDelayRead[1] = v7;
  this->m_pfDelayRead[9] = v95;
  this->m_pfDelayRead[2] = v8;
  this->m_pfDelayRead[3] = v12;
  this->m_pfDelayRead[4] = v13;
  this->m_pfDelayRead[6] = v26;
  this->m_pfDelayRead[7] = v27;
  this->m_pfDelayRead[8] = v28;
  this->m_pfDelayRead[11] = v93;
}rite[0] = v20;
  this->m_pfDelayWrite[1] = v5;
  this->m_pfDelayWrite[2] = v6;
  this->m_pfDelayRead[1] = v7;
  this->m_pfDelayRead[9] = v95;
  this->m_pfDelayRead[2] = v8;
  this->m_pfDelayRead[3] = v12;
  thi

// File Line: 1297
// RVA: 0xAC4CC0
void __fastcall CAkFDNReverbFX::ProcessStereo16(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *v3; // rdi
  AkAudioBuffer *v4; // r8
  CAkFDNReverbFXParams *v5; // rdx
  float v6; // xmm5_4
  __m128 v7; // xmm11
  float v8; // xmm15_4
  float v9; // xmm12_4
  signed int v10; // eax
  float *v11; // r8
  __m128 v12; // xmm0
  __m128 v13; // xmm1
  __m128 v14; // xmm0
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
  int v33; // eax
  bool v34; // zf
  float *v35; // rax
  float *v36; // rcx
  float *v37; // rax
  __m128 v38; // xmm1
  __m128 v39; // xmm0
  __m128 v40; // xmm3
  __m128 v41; // xmm5
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm0
  __m128 v45; // xmm7
  __m128 v46; // xmm1
  __m128 v47; // xmm0
  __m128 v48; // xmm3
  __m128 v49; // xmm4
  float *v50; // rcx
  __m128 v51; // xmm0
  __m128 v52; // xmm1
  __m128 v53; // xmm2
  __m128 v54; // xmm5
  __m128 v55; // xmm1
  __m128 v56; // xmm0
  __m128 v57; // xmm8
  __m128 v58; // xmm1
  __m128 v59; // xmm10
  __m128 v60; // xmm3
  __m128 v61; // xmm4
  __m128 v62; // xmm0
  bool v63; // cf
  float *v64; // rax
  float *v65; // rcx
  __m128 v66; // xmm0
  __m128 v67; // xmm1
  __m128 v68; // xmm2
  __m128 v69; // xmm5
  __m128 v70; // xmm1
  __m128 v71; // xmm0
  __m128 v72; // xmm9
  __m128 v73; // xmm1
  __m128 v74; // xmm10
  __m128 v75; // xmm3
  __m128 v76; // xmm4
  __m128 v77; // xmm0
  float *v78; // rax
  float *v79; // rcx
  float *v80; // rax
  float v81; // xmm6_4
  __int64 v82; // rax
  __m128 v83; // xmm1
  float v84; // xmm5_4
  __m128 v85; // xmm2
  __m128 v86; // xmm2
  __m128 v87; // xmm3
  __m128 v88; // xmm3
  __m128 v89; // xmm0
  __m128 v90; // xmm10
  __m128 v91; // xmm1
  __m128 v92; // xmm4
  __m128 v93; // xmm4
  __m128 v94; // xmm2
  __m128 v95; // xmm3
  __m128 v96; // xmm1
  __m128 v97; // xmm10
  __m128 v98; // xmm11
  __m128 v99; // xmm1
  __m128 v100; // xmm4
  __m128 v101; // xmm3
  float v102; // xmm1_4
  __m128 v103; // xmm2
  float v104; // xmm0_4
  __m128 v105; // xmm2
  __m128 v106; // xmm1
  __m128 v107; // xmm0
  __m128 v108; // xmm2
  signed __int64 v109; // [rsp+0h] [rbp-2A8h]
  float *v110; // [rsp+8h] [rbp-2A0h]
  float *v111; // [rsp+10h] [rbp-298h]
  float *v112; // [rsp+18h] [rbp-290h]
  float *v113; // [rsp+20h] [rbp-288h]
  float *v114; // [rsp+28h] [rbp-280h]
  float *v115; // [rsp+30h] [rbp-278h]
  float *v116; // [rsp+38h] [rbp-270h]
  float *v117; // [rsp+40h] [rbp-268h]
  float *v118; // [rsp+48h] [rbp-260h]
  float *v119; // [rsp+50h] [rbp-258h]
  float *v120; // [rsp+58h] [rbp-250h]
  float *v121; // [rsp+60h] [rbp-248h]
  float *v122; // [rsp+68h] [rbp-240h]
  float *v123; // [rsp+70h] [rbp-238h]
  float *v124; // [rsp+78h] [rbp-230h]
  float *v125; // [rsp+80h] [rbp-228h]
  __m128 v126; // [rsp+90h] [rbp-218h]
  float *v127; // [rsp+A0h] [rbp-208h]
  float *v128; // [rsp+A8h] [rbp-200h]
  __m128 v129; // [rsp+B0h] [rbp-1F8h]
  float v130; // [rsp+C0h] [rbp-1E8h]
  float v131; // [rsp+D0h] [rbp-1D8h]
  __m128 v132; // [rsp+E0h] [rbp-1C8h]
  float v133; // [rsp+F0h] [rbp-1B8h]
  __m128 v134; // [rsp+100h] [rbp-1A8h]
  __m128 v135; // [rsp+110h] [rbp-198h]
  __m128 v136; // [rsp+120h] [rbp-188h]
  float v137; // [rsp+130h] [rbp-178h]
  float v138; // [rsp+140h] [rbp-168h]
  __m128 v139; // [rsp+150h] [rbp-158h]
  __m128 v140; // [rsp+160h] [rbp-148h]
  __m128 v141; // [rsp+170h] [rbp-138h]
  __m128 v142; // [rsp+180h] [rbp-128h]
  __m128 v143; // [rsp+190h] [rbp-118h]
  __m128 v144; // [rsp+1A0h] [rbp-108h]
  __m128 v145; // [rsp+1B0h] [rbp-F8h]
  CAkFDNReverbFX *v146; // [rsp+2B0h] [rbp+8h]
  AkAudioBuffer *v147; // [rsp+2B8h] [rbp+10h]
  bool v148; // [rsp+2C0h] [rbp+18h]
  int v149; // [rsp+2C8h] [rbp+20h]

  v147 = io_pBuffer;
  v146 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  v3 = this->m_pfPreDelayRW;
  v4 = io_pBuffer;
  v5 = this->m_pParams;
  v135 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v6) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(this->m_fDCFwdMem),
                                     (__m128)LODWORD(this->m_fDCFwdMem),
                                     0);
  LODWORD(v137) = (unsigned __int128)_mm_shuffle_ps(
                                       (__m128)LODWORD(this->m_fFIRLPFB1),
                                       (__m128)LODWORD(this->m_fFIRLPFB1),
                                       0);
  v7 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  LODWORD(v133) = (unsigned __int128)_mm_shuffle_ps(
                                       (__m128)LODWORD(this->m_fDCCoef),
                                       (__m128)LODWORD(this->m_fDCCoef),
                                       0);
  LODWORD(v8) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(this->m_fFIRLPFMem),
                                     (__m128)LODWORD(this->m_fFIRLPFMem),
                                     0);
  LODWORD(v9) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(this->m_fDCFbkMem),
                                     (__m128)LODWORD(this->m_fDCFbkMem),
                                     0);
  v130 = v6;
  v121 = (float *)v4->pData;
  v10 = v4->uMaxFrames;
  v11 = this->m_pfDelayWrite[0];
  v2.m128_f32[0] = -2.0 / (float)(signed int)v5->NonRTPC.uNumberOfDelays;
  v12 = v2;
  v13 = (__m128)LODWORD(v5->RTPC.fDryLevel);
  v132 = _mm_shuffle_ps(v12, v12, 0);
  v129 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  v127 = this->m_pfPreDelayStart;
  v124 = this->m_pfDelayStart[0];
  v148 = this->m_pfPreDelayStart != 0i64;
  v125 = this->m_pfDelayStart[1];
  v115 = this->m_pfDelayStart[2];
  v13.m128_f32[0] = (float)(v13.m128_f32[0] - this->m_fCurrentDry) * (float)(1.0 / (float)v10);
  v118 = this->m_pfDelayStart[3];
  LODWORD(v131) = (unsigned __int128)_mm_shuffle_ps(v13, v13, 0);
  v14 = (__m128)LODWORD(v5->RTPC.fWetLevel);
  v117 = this->m_pfDelayEnd[0];
  v128 = this->m_pfPreDelayEnd;
  v14.m128_f32[0] = (float)(v14.m128_f32[0] - this->m_fCurrentWet) * (float)(1.0 / (float)v10);
  v116 = this->m_pfDelayEnd[1];
  LODWORD(v138) = (unsigned __int128)_mm_shuffle_ps(v14, v14, 0);
  v122 = this->m_pfDelayEnd[2];
  v123 = this->m_pfDelayEnd[3];
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
  v142 = this->m_vIIRLPFB0[2];
  v141 = this->m_vIIRLPFB0[0];
  v140 = this->m_vIIRLPFB0[3];
  v145 = this->m_vIIRLPFB0[1];
  v30 = this->m_pfDelayRead[8];
  v144 = this->m_vIIRLPFA1[1];
  v143 = this->m_vIIRLPFA1[0];
  v120 = this->m_pfDelayRead[5];
  v110 = this->m_pfDelayRead[10];
  v134 = this->m_vIIRLPFA1[2];
  v112 = this->m_pfDelayRead[9];
  v136 = this->m_vIIRLPFA1[3];
  v31 = this->m_vIIRLPFMem[3];
  v113 = this->m_pfDelayRead[13];
  v119 = this->m_pfDelayRead[11];
  v126 = this->m_vIIRLPFMem[3];
  v32 = this->m_pfDelayRead[12];
  v111 = this->m_pfDelayRead[14];
  v114 = this->m_pfDelayRead[15];
  v33 = v147->uValidFrames;
  v149 = v33;
  v34 = v33 == 0;
  v35 = this->m_pfDelayRead[1];
  if ( !v34 )
  {
    v36 = this->m_pfDelayRead[1];
    v37 = v124;
    do
    {
      v38 = (__m128)*(unsigned int *)v21;
      v39 = (__m128)*(unsigned int *)v22;
      v21 += 4;
      if ( v21 >= v117 )
        v21 = v37;
      v109 = (signed __int64)(v36 + 4);
      v40 = (__m128)*(unsigned int *)v23;
      if ( v36 + 4 >= v117 )
        v109 = (signed __int64)(v37 + 1);
      v22 += 4;
      if ( v22 >= v117 )
        v22 = v37 + 2;
      v23 += 4;
      if ( v23 >= v117 )
        v23 = v37 + 3;
      v41 = (__m128)*(unsigned int *)v29;
      v27 += 4;
      v42 = _mm_movelh_ps(_mm_unpacklo_ps(v38, (__m128)*(unsigned int *)v36), _mm_unpacklo_ps(v39, v40));
      v43 = (__m128)*(unsigned int *)v120;
      v44 = _mm_mul_ps(v24, v17);
      v45 = _mm_mul_ps(v42, v15);
      v46 = (__m128)*((unsigned int *)v27 - 4);
      if ( v27 >= v116 )
        v27 = v125;
      v24 = _mm_add_ps(v45, v44);
      v47 = (__m128)*(unsigned int *)v28;
      v120 += 4;
      v48 = _mm_mul_ps(v24, vOutDecorrelationVectorA);
      v49 = _mm_mul_ps(v24, vOutDecorrelationVectorB);
      if ( v120 >= v116 )
        v120 = v125 + 1;
      v28 += 4;
      if ( v28 >= v116 )
        v28 = v125 + 2;
      v29 += 4;
      if ( v29 >= v116 )
        v29 = v125 + 3;
      v50 = v119;
      v30 += 4;
      v51 = _mm_unpacklo_ps(v47, v41);
      v52 = _mm_unpacklo_ps(v46, v43);
      v53 = (__m128)*(unsigned int *)v112;
      v54 = (__m128)*(unsigned int *)v119;
      v55 = _mm_mul_ps(_mm_movelh_ps(v52, v51), v16);
      v56 = _mm_mul_ps(v25, v144);
      v57 = v55;
      v58 = (__m128)*((unsigned int *)v30 - 4);
      if ( v30 >= v122 )
        v30 = v115;
      v25 = _mm_add_ps(v57, v56);
      v59 = _mm_add_ps(v25, v24);
      v60 = _mm_add_ps(v48, _mm_mul_ps(v25, vOutDecorrelationVectorA));
      v61 = _mm_add_ps(v49, _mm_mul_ps(v25, vOutDecorrelationVectorB));
      v62 = (__m128)*(unsigned int *)v110;
      v63 = v112 + 4 < v122;
      v112 += 4;
      v64 = v110;
      if ( !v63 )
      {
        v112 = v115 + 1;
        v64 = v110;
      }
      v110 = v64 + 4;
      if ( v64 + 4 >= v122 )
        v110 = v115 + 2;
      v119 += 4;
      if ( v50 + 4 >= v122 )
        v119 = v115 + 3;
      v65 = v114;
      v32 += 4;
      v66 = _mm_unpacklo_ps(v62, v54);
      v67 = _mm_unpacklo_ps(v58, v53);
      v68 = (__m128)*(unsigned int *)v113;
      v69 = (__m128)*(unsigned int *)v114;
      v70 = _mm_mul_ps(_mm_movelh_ps(v67, v66), v142);
      v71 = _mm_mul_ps(v26, v134);
      v72 = v70;
      v73 = (__m128)*((unsigned int *)v32 - 4);
      if ( v32 >= v123 )
        v32 = v118;
      v26 = _mm_add_ps(v72, v71);
      v74 = _mm_add_ps(v59, v26);
      v75 = _mm_add_ps(v60, _mm_mul_ps(v26, vOutDecorrelationVectorA));
      v76 = _mm_add_ps(v61, _mm_mul_ps(v26, vOutDecorrelationVectorB));
      v77 = (__m128)*(unsigned int *)v111;
      v63 = v113 + 4 < v123;
      v113 += 4;
      v78 = v111;
      if ( !v63 )
      {
        v113 = v118 + 1;
        v78 = v111;
      }
      v111 = v78 + 4;
      if ( v78 + 4 >= v123 )
        v111 = v118 + 2;
      v114 += 4;
      if ( v65 + 4 >= v123 )
        v114 = v118 + 3;
      v7.m128_f32[0] = v7.m128_f32[0] + v131;
      v79 = v121;
      v80 = v121;
      ++v121;
      v81 = *v80;
      v139 = v7;
      v82 = v147->uMaxFrames;
      v83 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v73, v68), _mm_unpacklo_ps(v77, v69)), v140),
              _mm_mul_ps(v126, v136));
      v84 = v79[v82];
      v126 = v83;
      v85 = _mm_add_ps(_mm_mul_ps(v83, vOutDecorrelationVectorA), v75);
      v86 = _mm_add_ps(v85, _mm_movehl_ps(v85, v85));
      v87 = _mm_add_ps(_mm_mul_ps(v83, vOutDecorrelationVectorB), v76);
      v88 = _mm_add_ps(v87, _mm_movehl_ps(v87, v87));
      v89 = _mm_add_ps(v83, v74);
      v90 = v129;
      v90.m128_f32[0] = v129.m128_f32[0] + v138;
      v91 = _mm_add_ps(_mm_movehl_ps(v89, v89), v89);
      v129 = v90;
      v92 = _mm_add_ps(_mm_shuffle_ps(v91, v91, 85), v91);
      v91.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v86, v86, 85)) + v86.m128_f32[0];
      v93 = _mm_mul_ps(_mm_shuffle_ps(v92, v92, 0), v132);
      v94 = _mm_add_ps(v26, v93);
      *v79 = (float)(v81 * v7.m128_f32[0]) + (float)(v91.m128_f32[0] * v90.m128_f32[0]);
      v91.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v88, v88, 85)) + v88.m128_f32[0];
      v95 = _mm_add_ps(v93, v24);
      v79[v82] = (float)(v84 * v7.m128_f32[0]) + (float)(v91.m128_f32[0] * v90.m128_f32[0]);
      v96 = _mm_add_ps(v126, v93);
      v97 = _mm_shuffle_ps(v96, _mm_shuffle_ps(v96, v95, 15), 201);
      v98 = _mm_shuffle_ps(v94, _mm_shuffle_ps(v94, v96, 15), 201);
      v99 = _mm_add_ps(v25, v93);
      v100 = _mm_shuffle_ps(v99, _mm_shuffle_ps(v99, v94, 15), 201);
      v101 = _mm_shuffle_ps(v95, _mm_shuffle_ps(v95, v99, 15), 201);
      v6 = v81 + v84;
      v9 = (float)((float)(v133 * v9) + v6) - v130;
      v130 = v6;
      if ( v148 )
      {
        v102 = *v3;
        *v3 = v9;
        ++v3;
        if ( v3 == v128 )
          v3 = v127;
      }
      else
      {
        v102 = v9;
      }
      v103 = v135;
      v37 = v124;
      v36 = (float *)v109;
      v11 += 4;
      v104 = v137 * v8;
      v17 = v143;
      v8 = v102;
      v103.m128_f32[0] = (float)(v135.m128_f32[0] * v102) + v104;
      v105 = _mm_shuffle_ps(v103, v103, 0);
      v106 = _mm_add_ps(v105, v100);
      v15 = v141;
      *((__m128 *)v11 - 1) = _mm_add_ps(v105, v101);
      *(__m128 *)v18 = v106;
      if ( v11 >= v117 )
        v11 = v124;
      v18 += 4;
      v107 = _mm_add_ps(v105, v98);
      if ( v18 >= v116 )
        v18 = v125;
      v19 += 4;
      v108 = _mm_add_ps(v105, v97);
      v7 = v139;
      v16 = v145;
      *((__m128 *)v19 - 1) = v107;
      if ( v19 >= v122 )
        v19 = v115;
      v20 += 4;
      *((__m128 *)v20 - 1) = v108;
      if ( v20 >= v123 )
        v20 = v118;
      --v149;
    }
    while ( v149 );
    v31 = v126;
    this = v146;
    v35 = (float *)v109;
  }
  this->m_fFIRLPFMem = v8;
  this->m_fDCFwdMem = v6;
  this->m_fDCFbkMem = v9;
  this->m_pfPreDelayRW = v3;
  this->m_pfDelayRead[1] = v35;
  this->m_vIIRLPFMem[0] = v24;
  this->m_vIIRLPFMem[1] = v25;
  this->m_vIIRLPFMem[2] = v26;
  this->m_pfDelayRead[5] = v120;
  this->m_pfDelayWrite[3] = v20;
  this->m_vIIRLPFMem[3] = v31;
  this->m_pfDelayRead[9] = v112;
  this->m_pfDelayRead[10] = v110;
  this->m_pfDelayWrite[0] = v11;
  this->m_pfDelayRead[11] = v119;
  this->m_pfDelayWrite[1] = v18;
  this->m_pfDelayRead[13] = v113;
  this->m_pfDelayWrite[2] = v19;
  this->m_pfDelayRead[14] = v111;
  this->m_pfDelayRead[0] = v21;
  this->m_pfDelayRead[2] = v22;
  this->m_pfDelayRead[3] = v23;
  this->m_pfDelayRead[4] = v27;
  this->m_pfDelayRead[15] = v114;
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
  float *v3; // rdi
  CAkFDNReverbFX *v4; // r10
  AkAudioBuffer *v5; // r8
  CAkFDNReverbFXParams *v6; // rdx
  __m128 v7; // xmm5
  __m128 v8; // xmm7
  __m128 v9; // xmm6
  int v10; // er13
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
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  float *v26; // r10
  float *v27; // rax
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  __m128 v30; // xmm0
  __m128 v31; // xmm3
  float v32; // xmm11_4
  __int64 v33; // rcx
  float v34; // xmm9_4
  __int64 v35; // rdx
  __int64 v36; // r8
  float v37; // xmm10_4
  float v38; // xmm8_4
  __int64 v39; // r9
  __m128 v40; // xmm6
  float v41; // xmm7_4
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // ST00_16
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
  __m128 v57; // ST80_16
  __m128 v58; // xmm0
  __m128 v59; // xmm3
  __m128 v60; // xmm3
  float v61; // xmm2_4
  __m128 v62; // xmm1
  float v63; // xmm0_4
  __m128 v64; // [rsp+10h] [rbp-198h]
  __m128 v65; // [rsp+20h] [rbp-188h]
  float *v66; // [rsp+30h] [rbp-178h]
  float v67; // [rsp+40h] [rbp-168h]
  float v68; // [rsp+50h] [rbp-158h]
  __m128 v69; // [rsp+60h] [rbp-148h]
  float v70; // [rsp+70h] [rbp-138h]
  __m128 v71; // [rsp+90h] [rbp-118h]
  float v72; // [rsp+A0h] [rbp-108h]
  __m128 v73; // [rsp+B0h] [rbp-F8h]
  CAkFDNReverbFX *v74; // [rsp+1B0h] [rbp+8h]
  AkAudioBuffer *v75; // [rsp+1B8h] [rbp+10h]
  bool v76; // [rsp+1C0h] [rbp+18h]
  float *v77; // [rsp+1C8h] [rbp+20h]

  v75 = io_pBuffer;
  v74 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  v3 = this->m_pfPreDelayRW;
  v4 = this;
  v5 = io_pBuffer;
  v6 = this->m_pParams;
  v7 = this->m_vIIRLPFB0[0];
  v8 = this->m_vIIRLPFA1[0];
  v9 = this->m_vIIRLPFMem[0];
  v10 = v5->uValidFrames;
  v11 = this->m_pfDelayStart[0];
  LODWORD(v12) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      0);
  LODWORD(v70) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      0);
  v13 = this->m_pfDelayEnd[0];
  v14 = this->m_pfDelayWrite[0];
  v15 = this->m_pfDelayRead[0];
  LODWORD(v16) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      0);
  LODWORD(v17) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      0);
  v65 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  v18 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v19) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      0);
  v20 = this->m_pfDelayRead[1];
  v21 = this->m_pfDelayRead[2];
  v22 = this->m_pfDelayRead[3];
  v67 = v12;
  v71 = this->m_vIIRLPFB0[0];
  v73 = this->m_vIIRLPFA1[0];
  v77 = (float *)v5->pData;
  v2.m128_f32[0] = -2.0 / (float)(signed int)v6->NonRTPC.uNumberOfDelays;
  v23 = v2;
  v24 = (__m128)LODWORD(v6->RTPC.fDryLevel);
  v69 = _mm_shuffle_ps(v23, v23, 0);
  v64 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  v76 = this->m_pfPreDelayStart != 0i64;
  v24.m128_f32[0] = (float)(v24.m128_f32[0] - this->m_fCurrentDry) * (float)(1.0 / (float)v5->uMaxFrames);
  LODWORD(v68) = (unsigned __int128)_mm_shuffle_ps(v24, v24, 0);
  v25 = (__m128)LODWORD(v6->RTPC.fWetLevel);
  v66 = this->m_pfPreDelayEnd;
  v25.m128_f32[0] = (float)(v25.m128_f32[0] - this->m_fCurrentWet) * (float)(1.0 / (float)v5->uMaxFrames);
  LODWORD(v72) = (unsigned __int128)_mm_shuffle_ps(v25, v25, 0);
  if ( v5->uValidFrames )
  {
    v26 = this->m_pfPreDelayStart;
    v27 = (float *)v5->pData;
    do
    {
      v28 = (__m128)*(unsigned int *)v15;
      v29 = (__m128)*(unsigned int *)v20;
      v30 = (__m128)*(unsigned int *)v21;
      v15 += 4;
      if ( v15 >= v13 )
        v15 = v11;
      v20 += 4;
      v31 = (__m128)*(unsigned int *)v22;
      if ( v20 >= v13 )
        v20 = v11 + 1;
      v21 += 4;
      if ( v21 >= v13 )
        v21 = v11 + 2;
      v22 += 4;
      if ( v22 >= v13 )
        v22 = v11 + 3;
      v32 = *v27;
      v33 = v5->uMaxFrames;
      v34 = v27[v33];
      v35 = 2 * (signed int)v33;
      v36 = 3 * (signed int)v33;
      v37 = v77[v35];
      v38 = v77[v36];
      v39 = 4 * (signed int)v33;
      v40 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v28, v29), _mm_unpacklo_ps(v30, v31)), v7),
              _mm_mul_ps(v9, v8));
      v41 = v77[v39];
      v42 = _mm_mul_ps(v40, vOutDecorrelationVectorA);
      v43 = _mm_mul_ps(v40, vOutDecorrelationVectorB);
      v44 = _mm_mul_ps(v40, vOutDecorrelationVectorC);
      v45 = v40;
      v46 = v40;
      v47 = _mm_add_ps(v42, _mm_movehl_ps(v42, v42));
      v48 = _mm_mul_ps(v40, vOutDecorrelationVectorD);
      v49 = _mm_mul_ps(v40, vOutDecorrelationVectorF);
      v50 = _mm_add_ps(v43, _mm_movehl_ps(v43, v43));
      v51 = _mm_add_ps(v44, _mm_movehl_ps(v44, v44));
      v52 = _mm_add_ps(v48, _mm_movehl_ps(v48, v48));
      v53 = _mm_add_ps(v49, _mm_movehl_ps(v49, v49));
      v54 = _mm_add_ps(_mm_movehl_ps(v46, v46), v46);
      v55 = _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), v54);
      v56 = v64;
      v56.m128_f32[0] = v64.m128_f32[0] + v68;
      v57 = v55;
      v64 = v56;
      v58 = v65;
      v58.m128_f32[0] = v65.m128_f32[0] + v72;
      v65 = v58;
      *v77 = (float)(*v27 * v64.m128_f32[0])
           + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 85)) + v47.m128_f32[0]) * v58.m128_f32[0]);
      v77[v33] = (float)(v34 * v64.m128_f32[0])
               + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 85)) + v50.m128_f32[0]) * v58.m128_f32[0]);
      v27 = v77 + 1;
      v77 = v27;
      v27[v35 - 1] = (float)(v37 * v64.m128_f32[0])
                   + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v51, v51, 85)) + v51.m128_f32[0]) * v58.m128_f32[0]);
      v12 = (float)(v37 + v38) + (float)((float)(v32 + v34) + v41);
      v27[v36 - 1] = (float)(v38 * v64.m128_f32[0])
                   + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v52, v52, 85)) + v52.m128_f32[0]) * v58.m128_f32[0]);
      v55.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v53, v53, 85)) + v53.m128_f32[0];
      v9 = v45;
      v27[v39 - 1] = (float)(v41 * v64.m128_f32[0]) + (float)(v55.m128_f32[0] * v58.m128_f32[0]);
      v59 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v57, v57, 0), v69), v45);
      v60 = _mm_shuffle_ps(v59, _mm_shuffle_ps(v59, v59, 15), 201);
      v17 = (float)((float)(v70 * v17) + v12) - v67;
      v67 = (float)(v37 + v38) + (float)((float)(v32 + v34) + v41);
      if ( v76 )
      {
        v61 = *v3;
        *v3 = v17;
        ++v3;
        if ( v3 == v66 )
          v3 = v26;
      }
      else
      {
        v61 = v17;
      }
      v7 = v71;
      v8 = v73;
      v5 = v75;
      v14 += 4;
      v62 = v18;
      v63 = v19 * v16;
      v16 = v61;
      v62.m128_f32[0] = (float)(v18.m128_f32[0] * v61) + v63;
      *((__m128 *)v14 - 1) = _mm_add_ps(_mm_shuffle_ps(v62, v62, 0), v60);
      if ( v14 >= v13 )
        v14 = v11;
      --v10;
    }
    while ( v10 );
    v4 = v74;
  }
  v4->m_fFIRLPFMem = v16;
  v4->m_fDCFwdMem = v12;
  v4->m_fDCFbkMem = v17;
  v4->m_pfPreDelayRW = v3;
  v4->m_pfDelayWrite[0] = v14;
  v4->m_vIIRLPFMem[0] = v9;
  v4->m_pfDelayRead[0] = v15;
  v4->m_pfDelayRead[1] = v20;
  v4->m_pfDelayRead[2] = v21;
  v4->m_pfDelayRead[3] = v22;
}

// File Line: 1372
// RVA: 0xAC5C50
void __fastcall CAkFDNReverbFX::ProcessFivePointZero8(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *v3; // rbp
  CAkFDNReverbFX *v4; // r10
  AkAudioBuffer *v5; // r8
  CAkFDNReverbFXParams *v6; // rdx
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
  __m128 v18; // xmm1
  float *v19; // rax
  __m128 v20; // xmm0
  float *v21; // rdx
  __m128 v22; // xmm2
  float *v23; // rcx
  float v24; // xmm2_4
  __m128 v25; // xmm4
  __m128 v26; // xmm8
  float *v27; // r13
  float *v28; // rax
  __m128 v29; // xmm6
  __m128 v30; // xmm9
  __m128 v31; // xmm15
  bool v32; // zf
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
  __int64 v53; // rcx
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
  __m128 v84; // xmm1
  __m128 v85; // xmm0
  __m128 v86; // xmm1
  float *v87; // ST00_8
  unsigned __int64 v88; // [rsp+8h] [rbp-230h]
  float *v89; // [rsp+10h] [rbp-228h]
  float *v90; // [rsp+18h] [rbp-220h]
  __m128 v91; // [rsp+20h] [rbp-218h]
  float *v92; // [rsp+30h] [rbp-208h]
  float *v93; // [rsp+38h] [rbp-200h]
  float *v94; // [rsp+40h] [rbp-1F8h]
  float *v95; // [rsp+48h] [rbp-1F0h]
  float *v96; // [rsp+50h] [rbp-1E8h]
  __m128 v97; // [rsp+60h] [rbp-1D8h]
  float v98; // [rsp+70h] [rbp-1C8h]
  __m128 v99; // [rsp+80h] [rbp-1B8h]
  float v100; // [rsp+90h] [rbp-1A8h]
  float v101; // [rsp+A0h] [rbp-198h]
  __m128 v102; // [rsp+B0h] [rbp-188h]
  float v103; // [rsp+C0h] [rbp-178h]
  float v104; // [rsp+D0h] [rbp-168h]
  __m128 v105; // [rsp+E0h] [rbp-158h]
  __m128 v106; // [rsp+F0h] [rbp-148h]
  __m128 v107; // [rsp+100h] [rbp-138h]
  __m128 v108; // [rsp+110h] [rbp-128h]
  __m128 v109; // [rsp+120h] [rbp-118h]
  float v110; // [rsp+130h] [rbp-108h]
  __m128 v111; // [rsp+140h] [rbp-F8h]
  CAkFDNReverbFX *v112; // [rsp+240h] [rbp+8h]
  AkAudioBuffer *v113; // [rsp+248h] [rbp+10h]
  bool v114; // [rsp+250h] [rbp+18h]
  int v115; // [rsp+258h] [rbp+20h]

  v113 = io_pBuffer;
  v112 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  v3 = this->m_pfPreDelayRW;
  v4 = this;
  v5 = io_pBuffer;
  v6 = this->m_pParams;
  v102 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  v7 = this->m_pfDelayEnd[1];
  v8 = this->m_pfDelayWrite[0];
  v9 = this->m_pfDelayWrite[1];
  LODWORD(v10) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      0);
  LODWORD(v103) = (unsigned __int128)_mm_shuffle_ps(
                                       (__m128)LODWORD(this->m_fFIRLPFB1),
                                       (__m128)LODWORD(this->m_fFIRLPFB1),
                                       0);
  LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      0);
  v12 = this->m_pfDelayRead[0];
  v13 = this->m_pfDelayRead[1];
  v14 = this->m_pfDelayRead[2];
  LODWORD(v101) = (unsigned __int128)_mm_shuffle_ps(
                                       (__m128)LODWORD(this->m_fDCCoef),
                                       (__m128)LODWORD(this->m_fDCCoef),
                                       0);
  v97 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  v98 = v10;
  v15 = this->m_pfDelayRead[3];
  v16 = this->m_pfDelayRead[4];
  v2.m128_f32[0] = -2.0 / (float)(signed int)v6->NonRTPC.uNumberOfDelays;
  v89 = (float *)v5->pData;
  v90 = this->m_pfDelayStart[1];
  v93 = this->m_pfDelayEnd[1];
  v17 = v2;
  v18 = (__m128)LODWORD(v6->RTPC.fDryLevel);
  v108 = _mm_shuffle_ps(v17, v17, 0);
  v99 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  v92 = this->m_pfPreDelayStart;
  v19 = this->m_pfDelayRead[5];
  v114 = this->m_pfPreDelayStart != 0i64;
  v18.m128_f32[0] = (float)(v18.m128_f32[0] - this->m_fCurrentDry) * (float)(1.0 / (float)v5->uMaxFrames);
  LODWORD(v110) = (unsigned __int128)_mm_shuffle_ps(v18, v18, 0);
  v20 = (__m128)LODWORD(v6->RTPC.fWetLevel);
  v21 = this->m_pfDelayEnd[0];
  v94 = this->m_pfDelayEnd[0];
  v20.m128_f32[0] = (float)(v20.m128_f32[0] - this->m_fCurrentWet) * (float)(1.0 / (float)v5->uMaxFrames);
  v22 = (__m128)LODWORD(this->m_fFIRLPFMem);
  v95 = this->m_pfPreDelayEnd;
  v23 = this->m_pfDelayStart[0];
  v96 = v23;
  LODWORD(v24) = (unsigned __int128)_mm_shuffle_ps(v22, v22, 0);
  LODWORD(v104) = (unsigned __int128)_mm_shuffle_ps(v20, v20, 0);
  v100 = v24;
  v25 = v4->m_vIIRLPFB0[0];
  v26 = v4->m_vIIRLPFB0[1];
  v27 = v4->m_pfDelayRead[6];
  v88 = (unsigned __int64)v19;
  v28 = v4->m_pfDelayRead[7];
  v29 = v4->m_vIIRLPFA1[0];
  v30 = v4->m_vIIRLPFA1[1];
  v31 = v4->m_vIIRLPFMem[1];
  LODWORD(v5) = v113->uValidFrames;
  v115 = (signed int)v5;
  v32 = (_DWORD)v5 == 0;
  v33 = v90;
  v34 = v4->m_vIIRLPFMem[0];
  v105 = v4->m_vIIRLPFB0[0];
  v109 = v4->m_vIIRLPFB0[1];
  v107 = v4->m_vIIRLPFA1[0];
  v111 = v4->m_vIIRLPFA1[1];
  v91 = v4->m_vIIRLPFMem[1];
  if ( !v32 )
  {
    v35 = vOutDecorrelationVectorD;
    v36 = (unsigned int *)v4->m_pfDelayRead[7];
    v106 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorD);
    do
    {
      v37 = (__m128)*(unsigned int *)v12;
      v38 = (__m128)*(unsigned int *)v13;
      v39 = (__m128)*(unsigned int *)v14;
      v12 += 4;
      if ( v12 >= v21 )
        v12 = v23;
      v13 += 4;
      v40 = (__m128)*(unsigned int *)v15;
      if ( v13 >= v21 )
        v13 = v23 + 1;
      v14 += 4;
      if ( v14 >= v21 )
        v14 = v23 + 2;
      v15 += 4;
      if ( v15 >= v21 )
        v15 = v23 + 3;
      v41 = _mm_unpacklo_ps(v37, v38);
      v42 = (__m128)*(unsigned int *)v16;
      v43 = _mm_mul_ps(v34, v29);
      v44 = _mm_unpacklo_ps(v39, v40);
      v16 += 4;
      if ( v16 >= v7 )
        v16 = v33;
      v88 += 16i64;
      v45 = (__m128)*(unsigned int *)(v88 - 16);
      v34 = _mm_add_ps(_mm_mul_ps(_mm_movelh_ps(v41, v44), v25), v43);
      v46 = (__m128)*(unsigned int *)v27;
      v47 = _mm_mul_ps(v34, vOutDecorrelationVectorA);
      v48 = _mm_mul_ps(v34, vOutDecorrelationVectorB);
      v49 = _mm_mul_ps(v34, v35);
      v50 = (__m128)*v36;
      v51 = _mm_mul_ps(v34, vOutDecorrelationVectorC);
      v52 = _mm_mul_ps(v34, vOutDecorrelationVectorF);
      if ( v88 >= (unsigned __int64)v7 )
        v88 = (unsigned __int64)(v33 + 1);
      v27 += 4;
      if ( v27 >= v7 )
        v27 = v33 + 2;
      v36 += 4;
      if ( v36 >= (unsigned int *)v7 )
        v36 = (unsigned int *)(v33 + 3);
      v53 = v113->uMaxFrames;
      v54 = *v89;
      v55 = v89[v53];
      v56 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v42, v45), _mm_unpacklo_ps(v46, v50)), v26),
              _mm_mul_ps(v91, v30));
      v57 = 2 * (signed int)v53;
      v58 = 3 * (signed int)v53;
      v59 = v89[v57];
      v60 = v89[v58];
      v61 = 4 * (signed int)v53;
      v91 = v56;
      v62 = _mm_add_ps(_mm_mul_ps(v56, vOutDecorrelationVectorA), v47);
      v63 = _mm_add_ps(_mm_mul_ps(v56, vOutDecorrelationVectorB), v48);
      v64 = v89[v61];
      v65 = _mm_add_ps(v62, _mm_movehl_ps(v62, v62));
      v66 = _mm_add_ps(v63, _mm_movehl_ps(v63, v63));
      v67 = _mm_add_ps(_mm_mul_ps(v56, vOutDecorrelationVectorC), v51);
      v68 = _mm_add_ps(v67, _mm_movehl_ps(v67, v67));
      v69 = _mm_add_ps(_mm_mul_ps(v56, vOutDecorrelationVectorE), v49);
      v70 = _mm_add_ps(v69, _mm_movehl_ps(v69, v69));
      v71 = _mm_add_ps(_mm_mul_ps(v106, v56), v52);
      v72 = v99;
      v72.m128_f32[0] = v99.m128_f32[0] + v110;
      v73 = _mm_add_ps(v71, _mm_movehl_ps(v71, v71));
      v99 = v72;
      v74 = _mm_add_ps(v91, v34);
      v75 = _mm_add_ps(_mm_movehl_ps(v74, v74), v74);
      v76 = v97;
      v76.m128_f32[0] = v97.m128_f32[0] + v104;
      v97 = v76;
      v77 = _mm_add_ps(_mm_shuffle_ps(v75, v75, 85), v75);
      v75.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v65, v65, 85)) + v65.m128_f32[0];
      v65.m128_i32[0] = v76.m128_i32[0];
      *v89 = (float)(*v89 * v72.m128_f32[0]) + (float)(v75.m128_f32[0] * v76.m128_f32[0]);
      v78 = _mm_mul_ps(_mm_shuffle_ps(v77, v77, 0), v108);
      ++v89;
      v89[v53 - 1] = (float)(v55 * v72.m128_f32[0])
                   + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v66, v66, 85)) + v66.m128_f32[0]) * v76.m128_f32[0]);
      v79 = _mm_add_ps(v78, v34);
      v89[v57 - 1] = (float)(v59 * v72.m128_f32[0])
                   + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v68, v68, 85)) + v68.m128_f32[0]) * v76.m128_f32[0]);
      v75.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v70, v70, 85)) + v70.m128_f32[0];
      v10 = (float)(v59 + v60) + (float)((float)(v54 + v55) + v64);
      v89[v58 - 1] = (float)(v60 * v72.m128_f32[0]) + (float)(v75.m128_f32[0] * v76.m128_f32[0]);
      v76.m128_f32[0] = v64 * v72.m128_f32[0];
      v31 = v91;
      v89[v61 - 1] = v76.m128_f32[0]
                   + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v73, v73, 85)) + v73.m128_f32[0]) * v65.m128_f32[0]);
      v80 = _mm_add_ps(v91, v78);
      v81 = _mm_shuffle_ps(v80, _mm_shuffle_ps(v80, v79, 15), 201);
      v82 = _mm_shuffle_ps(v79, _mm_shuffle_ps(v79, v80, 15), 201);
      v11 = (float)((float)(v101 * v11) + v10) - v98;
      v98 = (float)(v59 + v60) + (float)((float)(v54 + v55) + v64);
      if ( v114 )
      {
        v24 = *v3;
        *v3 = v11;
        ++v3;
        if ( v3 == v95 )
          v3 = v92;
      }
      else
      {
        v24 = v11;
      }
      v83 = v102;
      v21 = v94;
      v23 = v96;
      v7 = v93;
      v33 = v90;
      v35 = vOutDecorrelationVectorD;
      v29 = v107;
      v26 = v109;
      v8 += 4;
      v83.m128_f32[0] = (float)(v102.m128_f32[0] * v24) + (float)(v103 * v100);
      v84 = _mm_shuffle_ps(v83, v83, 0);
      v30 = v111;
      v85 = v84;
      v100 = v24;
      v86 = _mm_add_ps(v84, v81);
      v25 = v105;
      *((__m128 *)v8 - 1) = _mm_add_ps(v85, v82);
      *(__m128 *)v9 = v86;
      if ( v8 >= v94 )
        v8 = v96;
      v9 += 4;
      if ( v9 >= v93 )
        v9 = v90;
      --v115;
    }
    while ( v115 );
    v87 = (float *)v36;
    v4 = v112;
    v28 = v87;
  }
  v4->m_fFIRLPFMem = v24;
  v4->m_fDCFwdMem = v10;
  v4->m_fDCFbkMem = v11;
  v4->m_pfPreDelayRW = v3;
  v4->m_pfDelayRead[0] = v12;
  v4->m_vIIRLPFMem[0] = v34;
  v4->m_vIIRLPFMem[1] = v31;
  v4->m_pfDelayWrite[0] = v8;
  v4->m_pfDelayWrite[1] = v9;
  v4->m_pfDelayRead[1] = v13;
  v4->m_pfDelayRead[2] = v14;
  v4->m_pfDelayRead[3] = v15;
  v4->m_pfDelayRead[4] = v16;
  v4->m_pfDelayRead[5] = (float *)v88;
  v4->m_pfDelayRead[6] = v27;
  v4->m_pfDelayRead[7] = v28;
}2;
  v4->m_vIIRLPFMem[0] = v34;
  v4->m_vIIRLPFMem[1] = v31;
  v4->m_pfDelayWrite[0] = v8;
  v4->m_pfDelayWrite[1] = v9;
  v4->m_pfDelayRead[1] = v13;
  v4->m_pfDelayRead[2] = v14;
  v4->m_pfDelayRead[3] = v15;
  v4->m_pfDelayRead[4] = v16;
  v4->m_pfDelayRead[5] = (float *)v88;
  v4->m_pfDelayRead[6] = v27;
  v4->m_pfDelayRead[7] = v28;

// File Line: 1411
// RVA: 0xAC6400
void __fastcall CAkFDNReverbFX::ProcessFivePointZero12(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *v3; // r14
  CAkFDNReverbFX *v4; // r10
  float *v5; // rbx
  float *v6; // rdi
  float *v7; // rsi
  float *v8; // r11
  float *v9; // r12
  AkAudioBuffer *v10; // r8
  float v11; // xmm8_4
  float v12; // xmm15_4
  CAkFDNReverbFXParams *v13; // rdx
  float v14; // xmm3_4
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  float *v17; // rax
  __m128 v18; // xmm0
  __m128 v19; // xmm4
  __m128 v20; // xmm5
  float *v21; // r13
  float *v22; // rbp
  float *v23; // rdx
  float *v24; // r15
  __m128 v25; // xmm13
  __m128 v26; // xmm14
  float *v27; // r9
  float *v28; // rcx
  __m128 v29; // xmm0
  bool v30; // zf
  float *v31; // r8
  unsigned int *v32; // r10
  unsigned __int64 v33; // rax
  __m128 v34; // xmm7
  __m128 v35; // xmm9
  __m128 v36; // xmm10
  __m128 v37; // xmm11
  __m128 v38; // xmm12
  __m128 v39; // xmm1
  __m128 v40; // xmm0
  __m128 v41; // xmm3
  __m128 v42; // xmm2
  float *v43; // rax
  __m128 v44; // xmm1
  __m128 v45; // xmm0
  __m128 v46; // xmm13
  __m128 v47; // xmm1
  unsigned __int64 v48; // r10
  bool v49; // cf
  __m128 v50; // xmm6
  __m128 v51; // xmm3
  __m128 v52; // xmm4
  __m128 v53; // xmm7
  __m128 v54; // xmm5
  __m128 v55; // xmm14
  float *v56; // rax
  __m128 v57; // xmm1
  __m128 v58; // xmm2
  __m128 v59; // xmm8
  __m128 v60; // xmm1
  __m128 v61; // xmm1
  __m128 v62; // xmm3
  __m128 v63; // xmm0
  __m128 v64; // xmm9
  __m128 v65; // xmm4
  __m128 v66; // xmm5
  __m128 v67; // xmm6
  __m128 v68; // xmm7
  __int64 v69; // rcx
  float v70; // xmm12_4
  float v71; // xmm10_4
  __int64 v72; // rdx
  __int64 v73; // r8
  float v74; // xmm11_4
  __m128 v75; // xmm8
  float v76; // xmm9_4
  __int64 v77; // r9
  __m128 v78; // xmm2
  __m128 v79; // xmm2
  __m128 v80; // xmm2
  __m128 v81; // xmm3
  __m128 v82; // xmm3
  __m128 v83; // xmm4
  __m128 v84; // xmm4
  __m128 v85; // xmm5
  __m128 v86; // xmm5
  __m128 v87; // xmm6
  __m128 v88; // xmm6
  __m128 v89; // xmm0
  __m128 v90; // xmm1
  __m128 v91; // xmm0
  __m128 v92; // xmm0
  __m128 v93; // xmm7
  __m128 v94; // xmm7
  __m128 v95; // xmm4
  __m128 v96; // xmm2
  __m128 v97; // xmm1
  __m128 v98; // xmm5
  __m128 v99; // xmm6
  __m128 v100; // xmm4
  float v101; // xmm1_4
  __m128 v102; // xmm2
  __m128 v103; // xmm2
  __m128 v104; // xmm0
  __m128 v105; // xmm1
  __m128 v106; // xmm2
  signed __int64 v107; // [rsp+0h] [rbp-2A8h]
  float *v108; // [rsp+8h] [rbp-2A0h]
  __m128 v109; // [rsp+10h] [rbp-298h]
  float *v110; // [rsp+20h] [rbp-288h]
  float *v111; // [rsp+28h] [rbp-280h]
  signed __int64 v112; // [rsp+30h] [rbp-278h]
  signed __int64 v113; // [rsp+38h] [rbp-270h]
  float *v114; // [rsp+40h] [rbp-268h]
  signed __int64 v115; // [rsp+48h] [rbp-260h]
  float *v116; // [rsp+50h] [rbp-258h]
  float *v117; // [rsp+58h] [rbp-250h]
  float *v118; // [rsp+60h] [rbp-248h]
  float *v119; // [rsp+68h] [rbp-240h]
  float *v120; // [rsp+70h] [rbp-238h]
  float *v121; // [rsp+78h] [rbp-230h]
  __m128 v122; // [rsp+80h] [rbp-228h]
  __m128 v123; // [rsp+90h] [rbp-218h]
  float *v124; // [rsp+A0h] [rbp-208h]
  float *v125; // [rsp+A8h] [rbp-200h]
  float v126; // [rsp+B0h] [rbp-1F8h]
  float v127; // [rsp+C0h] [rbp-1E8h]
  __m128 v128; // [rsp+D0h] [rbp-1D8h]
  float v129; // [rsp+E0h] [rbp-1C8h]
  __m128 v130; // [rsp+F0h] [rbp-1B8h]
  __m128 v131; // [rsp+100h] [rbp-1A8h]
  float v132; // [rsp+110h] [rbp-198h]
  __m128 v133; // [rsp+120h] [rbp-188h]
  __m128 v134; // [rsp+130h] [rbp-178h]
  float v135; // [rsp+140h] [rbp-168h]
  float v136; // [rsp+150h] [rbp-158h]
  __m128 v137; // [rsp+160h] [rbp-148h]
  __m128 v138; // [rsp+170h] [rbp-138h]
  __m128 v139; // [rsp+180h] [rbp-128h]
  __m128 v140; // [rsp+190h] [rbp-118h]
  __m128 v141; // [rsp+1A0h] [rbp-108h]
  __m128 v142; // [rsp+1B0h] [rbp-F8h]
  CAkFDNReverbFX *v143; // [rsp+2B0h] [rbp+8h]
  AkAudioBuffer *v144; // [rsp+2B8h] [rbp+10h]
  bool v145; // [rsp+2C0h] [rbp+18h]
  int v146; // [rsp+2C8h] [rbp+20h]

  v144 = io_pBuffer;
  v143 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  v3 = this->m_pfPreDelayRW;
  v4 = this;
  v5 = this->m_pfDelayWrite[0];
  v6 = this->m_pfDelayWrite[1];
  v7 = this->m_pfDelayWrite[2];
  v134 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  v123 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  v8 = this->m_pfDelayRead[0];
  v9 = this->m_pfDelayRead[2];
  v10 = io_pBuffer;
  LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      0);
  LODWORD(v12) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      0);
  v126 = v11;
  v13 = this->m_pParams;
  LODWORD(v14) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      0);
  LODWORD(v136) = (unsigned __int128)_mm_shuffle_ps(
                                       (__m128)LODWORD(this->m_fFIRLPFB1),
                                       (__m128)LODWORD(this->m_fFIRLPFB1),
                                       0);
  v127 = v14;
  LODWORD(v132) = (unsigned __int128)_mm_shuffle_ps(
                                       (__m128)LODWORD(this->m_fDCCoef),
                                       (__m128)LODWORD(this->m_fDCCoef),
                                       0);
  v116 = (float *)v10->pData;
  v121 = this->m_pfDelayStart[0];
  v2.m128_f32[0] = -2.0 / (float)(signed int)v13->NonRTPC.uNumberOfDelays;
  v15 = v2;
  v16 = (__m128)LODWORD(v13->RTPC.fDryLevel);
  v130 = _mm_shuffle_ps(v15, v15, 0);
  v122 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  v125 = this->m_pfPreDelayStart;
  v118 = this->m_pfDelayEnd[0];
  v17 = this->m_pfDelayRead[1];
  v145 = this->m_pfPreDelayStart != 0i64;
  v16.m128_f32[0] = (float)(v16.m128_f32[0] - this->m_fCurrentDry) * (float)(1.0 / (float)v10->uMaxFrames);
  LODWORD(v135) = (unsigned __int128)_mm_shuffle_ps(v16, v16, 0);
  v18 = (__m128)LODWORD(v13->RTPC.fWetLevel);
  v117 = this->m_pfDelayStart[2];
  v124 = this->m_pfPreDelayEnd;
  v18.m128_f32[0] = (float)(v18.m128_f32[0] - this->m_fCurrentWet) * (float)(1.0 / (float)v10->uMaxFrames);
  v114 = this->m_pfDelayStart[1];
  v119 = this->m_pfDelayEnd[2];
  LODWORD(v129) = (unsigned __int128)_mm_shuffle_ps(v18, v18, 0);
  v120 = this->m_pfDelayEnd[1];
  v19 = this->m_vIIRLPFB0[0];
  v20 = this->m_vIIRLPFA1[0];
  v21 = this->m_pfDelayRead[3];
  v22 = this->m_pfDelayRead[4];
  v23 = this->m_pfDelayRead[7];
  v24 = this->m_pfDelayRead[8];
  v25 = this->m_vIIRLPFMem[0];
  v26 = this->m_vIIRLPFMem[1];
  v133 = this->m_vIIRLPFB0[1];
  v27 = this->m_pfDelayRead[10];
  v110 = this->m_pfDelayRead[9];
  v140 = this->m_vIIRLPFB0[0];
  v142 = this->m_vIIRLPFA1[0];
  v111 = this->m_pfDelayRead[11];
  v108 = this->m_pfDelayRead[5];
  v131 = this->m_vIIRLPFB0[2];
  v139 = this->m_vIIRLPFA1[1];
  LODWORD(v10) = v144->uValidFrames;
  v28 = this->m_pfDelayRead[6];
  v137 = v4->m_vIIRLPFA1[2];
  v29 = v4->m_vIIRLPFMem[2];
  v146 = (signed int)v10;
  v30 = (_DWORD)v10 == 0;
  v31 = v121;
  v109 = v4->m_vIIRLPFMem[2];
  if ( !v30 )
  {
    v32 = (unsigned int *)v17;
    v33 = (unsigned __int64)v118;
    v34 = vOutDecorrelationVectorD;
    v35 = vOutDecorrelationVectorB;
    v36 = vOutDecorrelationVectorC;
    v37 = vOutDecorrelationVectorA;
    v128 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorB);
    v38 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorD);
    v141 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorC);
    v138 = v38;
    do
    {
      v39 = (__m128)*(unsigned int *)v8;
      v40 = (__m128)*(unsigned int *)v9;
      v8 += 4;
      if ( (unsigned __int64)v8 >= v33 )
        v8 = v31;
      v107 = (signed __int64)(v32 + 4);
      v41 = (__m128)*(unsigned int *)v21;
      if ( (unsigned __int64)(v32 + 4) >= v33 )
        v107 = (signed __int64)(v31 + 1);
      v9 += 4;
      if ( (unsigned __int64)v9 >= v33 )
        v9 = v31 + 2;
      v21 += 4;
      if ( (unsigned __int64)v21 >= v33 )
        v21 = v31 + 3;
      v22 += 4;
      v42 = (__m128)*(unsigned int *)v108;
      v43 = v114;
      v44 = _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v39, (__m128)*v32), _mm_unpacklo_ps(v40, v41)), v19);
      v45 = _mm_mul_ps(v25, v20);
      v46 = v44;
      v47 = (__m128)*((unsigned int *)v22 - 4);
      if ( v22 >= v120 )
        v22 = v114;
      v25 = _mm_add_ps(v46, v45);
      v48 = (unsigned __int64)(v108 + 4);
      v108 = (float *)v48;
      v49 = v48 < (unsigned __int64)v120;
      v32 = (unsigned int *)v107;
      v50 = _mm_mul_ps(v25, v34);
      v51 = _mm_mul_ps(v25, v37);
      v52 = _mm_mul_ps(v25, v35);
      v53 = _mm_mul_ps(v25, vOutDecorrelationVectorF);
      v54 = _mm_mul_ps(v25, v36);
      if ( !v49 )
      {
        v108 = v114 + 1;
        v32 = (unsigned int *)v107;
      }
      v112 = (signed __int64)(v28 + 4);
      if ( v28 + 4 >= v120 )
      {
        v112 = (signed __int64)(v114 + 2);
        v43 = v114;
      }
      v113 = (signed __int64)(v23 + 4);
      if ( v23 + 4 >= v120 )
        v113 = (signed __int64)(v43 + 3);
      v55 = _mm_mul_ps(v26, v139);
      v56 = v117;
      v24 += 4;
      v57 = _mm_unpacklo_ps(v47, v42);
      v58 = (__m128)*((unsigned int *)v24 - 4);
      v59 = (__m128)*(unsigned int *)v110;
      v60 = _mm_mul_ps(
              _mm_movelh_ps(v57, _mm_unpacklo_ps((__m128)*(unsigned int *)v28, (__m128)*(unsigned int *)v23)),
              v133);
      if ( v24 >= v119 )
        v24 = v117;
      v110 += 4;
      v26 = _mm_add_ps(v60, v55);
      v61 = _mm_add_ps(v26, v25);
      v62 = _mm_add_ps(v51, _mm_mul_ps(v26, v37));
      v63 = _mm_mul_ps(v26, v35);
      v64 = (__m128)*(unsigned int *)v111;
      v65 = _mm_add_ps(v52, v63);
      v66 = _mm_add_ps(v54, _mm_mul_ps(v26, v36));
      v67 = _mm_add_ps(v50, _mm_mul_ps(v26, vOutDecorrelationVectorE));
      v68 = _mm_add_ps(v53, _mm_mul_ps(v38, v26));
      if ( v110 >= v119 )
        v110 = v117 + 1;
      v115 = (signed __int64)(v27 + 4);
      if ( v27 + 4 >= v119 )
      {
        v115 = (signed __int64)(v117 + 2);
        v56 = v117;
      }
      v111 += 4;
      if ( v111 >= v119 )
        v111 = v56 + 3;
      v69 = v144->uMaxFrames;
      v70 = *v116;
      v71 = v116[v69];
      v72 = 2 * (signed int)v69;
      v73 = 3 * (signed int)v69;
      v74 = v116[v72];
      v75 = _mm_add_ps(
              _mm_mul_ps(
                _mm_movelh_ps(_mm_unpacklo_ps(v58, v59), _mm_unpacklo_ps((__m128)*(unsigned int *)v27, v64)),
                v131),
              _mm_mul_ps(v109, v137));
      v76 = v116[v73];
      v109 = v75;
      v77 = 4 * (signed int)v69;
      v78 = v75;
      v75.m128_f32[0] = v116[v77];
      v79 = _mm_add_ps(_mm_mul_ps(v78, vOutDecorrelationVectorA), v62);
      v80 = _mm_add_ps(v79, _mm_movehl_ps(v79, v79));
      v81 = _mm_add_ps(_mm_mul_ps(v109, vOutDecorrelationVectorB), v65);
      v82 = _mm_add_ps(v81, _mm_movehl_ps(v81, v81));
      v83 = _mm_add_ps(_mm_mul_ps(v109, vOutDecorrelationVectorC), v66);
      v84 = _mm_add_ps(v83, _mm_movehl_ps(v83, v83));
      v85 = _mm_add_ps(_mm_mul_ps(v128, v109), v67);
      v86 = _mm_add_ps(v85, _mm_movehl_ps(v85, v85));
      v87 = _mm_add_ps(_mm_mul_ps(v141, v109), v68);
      v88 = _mm_add_ps(v87, _mm_movehl_ps(v87, v87));
      v89 = _mm_add_ps(v109, v61);
      v90 = _mm_add_ps(_mm_movehl_ps(v89, v89), v89);
      v91 = v122;
      v91.m128_f32[0] = v122.m128_f32[0] + v135;
      v122 = v91;
      v92 = v123;
      v93 = _mm_add_ps(_mm_shuffle_ps(v90, v90, 85), v90);
      v92.m128_f32[0] = v123.m128_f32[0] + v129;
      v123 = v92;
      *v116 = (float)(*v116 * v122.m128_f32[0])
            + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v80, v80, 85)) + v80.m128_f32[0]) * v92.m128_f32[0]);
      v90.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v82, v82, 85)) + v82.m128_f32[0];
      v82.m128_i32[0] = v92.m128_i32[0];
      ++v116;
      v94 = _mm_mul_ps(_mm_shuffle_ps(v93, v93, 0), v130);
      v116[v69 - 1] = (float)(v71 * v122.m128_f32[0]) + (float)(v90.m128_f32[0] * v92.m128_f32[0]);
      v92.m128_f32[0] = (float)(v74 * v122.m128_f32[0])
                      + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v84, v84, 85)) + v84.m128_f32[0]) * v92.m128_f32[0]);
      v95 = _mm_add_ps(v94, v25);
      v116[v72 - 1] = v92.m128_f32[0];
      v116[v73 - 1] = (float)(v76 * v122.m128_f32[0])
                    + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v86, v86, 85)) + v86.m128_f32[0]) * v82.m128_f32[0]);
      v92.m128_f32[0] = v75.m128_f32[0] * v122.m128_f32[0];
      v11 = (float)(v74 + v76) + (float)((float)(v70 + v71) + v75.m128_f32[0]);
      v96 = _mm_add_ps(v109, v94);
      v116[v77 - 1] = v92.m128_f32[0]
                    + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v88, v88, 85)) + v88.m128_f32[0]) * v82.m128_f32[0]);
      v97 = _mm_add_ps(v26, v94);
      v98 = _mm_shuffle_ps(v96, _mm_shuffle_ps(v96, v95, 15), 201);
      v99 = _mm_shuffle_ps(v97, _mm_shuffle_ps(v97, v96, 15), 201);
      v100 = _mm_shuffle_ps(v95, _mm_shuffle_ps(v95, v97, 15), 201);
      v12 = (float)((float)(v132 * v12) + v11) - v126;
      v126 = v11;
      if ( v145 )
      {
        v101 = *v3;
        *v3 = v12;
        ++v3;
        if ( v3 == v124 )
          v3 = v125;
      }
      else
      {
        v101 = v12;
      }
      v102 = v134;
      v33 = (unsigned __int64)v118;
      v31 = v121;
      v28 = (float *)v112;
      v23 = (float *)v113;
      v35 = vOutDecorrelationVectorB;
      v36 = vOutDecorrelationVectorC;
      v37 = vOutDecorrelationVectorA;
      v27 = (float *)v115;
      v5 += 4;
      v102.m128_f32[0] = (float)(v134.m128_f32[0] * v101) + (float)(v136 * v127);
      v103 = _mm_shuffle_ps(v102, v102, 0);
      v38 = v138;
      v34 = vOutDecorrelationVectorD;
      v104 = _mm_add_ps(v103, v100);
      v19 = v140;
      *((__m128 *)v5 - 1) = v104;
      v14 = v101;
      if ( v5 >= v118 )
        v5 = v121;
      v6 += 4;
      v127 = v101;
      v105 = v103;
      v106 = _mm_add_ps(v103, v98);
      v20 = v142;
      *((__m128 *)v6 - 1) = _mm_add_ps(v105, v99);
      *(__m128 *)v7 = v106;
      if ( v6 >= v120 )
        v6 = v114;
      v7 += 4;
      if ( v7 >= v119 )
        v7 = v117;
      --v146;
    }
    while ( v146 );
    v29 = v109;
    v4 = v143;
    v17 = (float *)v107;
  }
  v4->m_fFIRLPFMem = v14;
  v4->m_fDCFwdMem = v11;
  v4->m_fDCFbkMem = v12;
  v4->m_pfPreDelayRW = v3;
  v4->m_pfDelayRead[1] = v17;
  v4->m_vIIRLPFMem[0] = v25;
  v4->m_pfDelayRead[5] = v108;
  v4->m_pfDelayWrite[0] = v5;
  v4->m_vIIRLPFMem[1] = v26;
  v4->m_vIIRLPFMem[2] = v29;
  v4->m_pfDelayRead[9] = v110;
  v4->m_pfDelayWrite[1] = v6;
  v4->m_pfDelayWrite[2] = v7;
  v4->m_pfDelayRead[0] = v8;
  v4->m_pfDelayRead[2] = v9;
  v4->m_pfDelayRead[11] = v111;
  v4->m_pfDelayRead[3] = v21;
  v4->m_pfDelayRead[4] = v22;
  v4->m_pfDelayRead[6] = v28;
  v4->m_pfDelayRead[7] = v23;
  v4->m_pfDelayRead[8] = v24;
  v4->m_pfDelayRead[10] = v27;
}

// File Line: 1458
// RVA: 0xAC6E40
void __fastcall CAkFDNReverbFX::ProcessFivePointZero16(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *v3; // r15
  AkAudioBuffer *v4; // r8
  CAkFDNReverbFXParams *v5; // rdx
  CAkFDNReverbFX *v6; // r10
  float v7; // xmm4_4
  float v8; // xmm8_4
  float v9; // xmm3_4
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  float *v13; // rax
  float *v14; // r13
  __m128 v15; // xmm5
  __m128 v16; // xmm6
  float *v17; // rbx
  float *v18; // rdi
  __m128 *v19; // rsi
  float *v20; // rbp
  __m128 v21; // xmm13
  __m128 v22; // xmm14
  __m128 v23; // xmm15
  float *v24; // r11
  float *v25; // rdx
  float *v26; // rcx
  float *v27; // r14
  float *v28; // r8
  float *v29; // r9
  float *v30; // r12
  __m128 v31; // xmm0
  float *v32; // r13
  bool v33; // zf
  float *v34; // rax
  __m128 v35; // xmm7
  unsigned int *v36; // r10
  float *v37; // rax
  __m128 v38; // xmm9
  __m128 v39; // xmm10
  __m128 v40; // xmm11
  __m128 v41; // xmm12
  __m128 v42; // xmm1
  __m128 v43; // xmm0
  float *v44; // rax
  __m128 v45; // xmm1
  __m128 v46; // xmm0
  __m128 v47; // xmm13
  __m128 v48; // xmm1
  __m128 v49; // xmm6
  __m128 v50; // xmm7
  __m128 v51; // xmm2
  __m128 v52; // xmm3
  __m128 v53; // xmm4
  __m128 v54; // xmm5
  __m128 v55; // xmm8
  __m128 v56; // xmm0
  __m128 v57; // xmm14
  __m128 v58; // xmm1
  __m128 v59; // xmm7
  __m128 v60; // xmm2
  __m128 v61; // xmm4
  __m128 v62; // xmm5
  __m128 v63; // xmm6
  __m128 v64; // xmm0
  __m128 v65; // xmm12
  __m128 v66; // xmm3
  __m128 v67; // xmm0
  __m128 v68; // xmm1
  __m128 v69; // xmm0
  __m128 v70; // xmm15
  __m128 v71; // xmm1
  __m128 v72; // xmm7
  __m128 v73; // xmm2
  __m128 v74; // xmm4
  __m128 v75; // xmm5
  __m128 v76; // xmm6
  __m128 v77; // xmm0
  __m128 v78; // xmm3
  __int64 v79; // rcx
  float v80; // xmm12_4
  float v81; // xmm10_4
  __int64 v82; // rdx
  __int64 v83; // r8
  float v84; // xmm11_4
  float v85; // xmm9_4
  __int64 v86; // r9
  __m128 v87; // xmm7
  float v88; // xmm8_4
  __m128 v89; // xmm3
  __m128 v90; // xmm2
  __m128 v91; // xmm7
  __m128 v92; // xmm3
  __m128 v93; // xmm4
  __m128 v94; // xmm5
  __m128 v95; // xmm2
  __m128 v96; // xmm4
  __m128 v97; // xmm7
  __m128 v98; // xmm5
  __m128 v99; // xmm0
  __m128 v100; // xmm1
  __m128 v101; // xmm0
  __m128 v102; // xmm0
  __m128 v103; // xmm6
  __m128 v104; // xmm6
  __m128 v105; // xmm5
  __m128 v106; // xmm2
  __m128 v107; // xmm1
  __m128 v108; // xmm7
  __m128 v109; // xmm1
  __m128 v110; // xmm6
  __m128 v111; // xmm5
  float v112; // xmm1_4
  __m128 v113; // xmm2
  __m128 v114; // xmm2
  __m128 v115; // xmm0
  __m128 v116; // xmm1
  __m128 v117; // xmm0
  __m128 v118; // xmm2
  __m128 v119; // xmm1
  float *v120; // ST60_8
  float *v121; // [rsp+0h] [rbp-348h]
  float *v122; // [rsp+8h] [rbp-340h]
  float *v123; // [rsp+10h] [rbp-338h]
  float *v124; // [rsp+18h] [rbp-330h]
  float *v125; // [rsp+20h] [rbp-328h]
  unsigned __int64 v126; // [rsp+28h] [rbp-320h]
  unsigned __int64 v127; // [rsp+30h] [rbp-318h]
  float *v128; // [rsp+38h] [rbp-310h]
  float *v129; // [rsp+40h] [rbp-308h]
  signed __int64 v130; // [rsp+48h] [rbp-300h]
  signed __int64 v131; // [rsp+50h] [rbp-2F8h]
  float *v132; // [rsp+60h] [rbp-2E8h]
  __m128 v133; // [rsp+60h] [rbp-2E8h]
  signed __int64 v134; // [rsp+70h] [rbp-2D8h]
  float *v135; // [rsp+78h] [rbp-2D0h]
  signed __int64 v136; // [rsp+80h] [rbp-2C8h]
  float *v137; // [rsp+88h] [rbp-2C0h]
  float *v138; // [rsp+90h] [rbp-2B8h]
  float *v139; // [rsp+98h] [rbp-2B0h]
  float *v140; // [rsp+A0h] [rbp-2A8h]
  float *v141; // [rsp+A8h] [rbp-2A0h]
  float *v142; // [rsp+B0h] [rbp-298h]
  __m128 v143; // [rsp+C0h] [rbp-288h]
  __m128 v144; // [rsp+D0h] [rbp-278h]
  __m128 v145; // [rsp+E0h] [rbp-268h]
  __m128 v146; // [rsp+F0h] [rbp-258h]
  __m128 v147; // [rsp+F0h] [rbp-258h]
  float *v148; // [rsp+100h] [rbp-248h]
  float *v149; // [rsp+108h] [rbp-240h]
  float v150; // [rsp+110h] [rbp-238h]
  float v151; // [rsp+120h] [rbp-228h]
  float v152; // [rsp+130h] [rbp-218h]
  __m128 v153; // [rsp+140h] [rbp-208h]
  float v154; // [rsp+150h] [rbp-1F8h]
  __m128 v155; // [rsp+160h] [rbp-1E8h]
  float v156; // [rsp+170h] [rbp-1D8h]
  __m128 v157; // [rsp+180h] [rbp-1C8h]
  __m128 v158; // [rsp+190h] [rbp-1B8h]
  __m128 v159; // [rsp+1A0h] [rbp-1A8h]
  float v160; // [rsp+1B0h] [rbp-198h]
  __m128 v161; // [rsp+1C0h] [rbp-188h]
  float v162; // [rsp+1D0h] [rbp-178h]
  __m128 v163; // [rsp+1E0h] [rbp-168h]
  __m128 v164; // [rsp+1F0h] [rbp-158h]
  __m128 v165; // [rsp+200h] [rbp-148h]
  __m128 v166; // [rsp+210h] [rbp-138h]
  __m128 v167; // [rsp+220h] [rbp-128h]
  __m128 v168; // [rsp+230h] [rbp-118h]
  __m128 v169; // [rsp+240h] [rbp-108h]
  __m128 v170; // [rsp+250h] [rbp-F8h]
  CAkFDNReverbFX *v171; // [rsp+350h] [rbp+8h]
  AkAudioBuffer *v172; // [rsp+358h] [rbp+10h]
  bool v173; // [rsp+360h] [rbp+18h]
  int v174; // [rsp+368h] [rbp+20h]

  v172 = io_pBuffer;
  v171 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  v3 = this->m_pfPreDelayRW;
  v4 = io_pBuffer;
  v5 = this->m_pParams;
  v6 = this;
  v164 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  v144 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  LODWORD(v7) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(this->m_fFIRLPFMem),
                                     (__m128)LODWORD(this->m_fFIRLPFMem),
                                     0);
  LODWORD(v8) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(this->m_fDCFwdMem),
                                     (__m128)LODWORD(this->m_fDCFwdMem),
                                     0);
  LODWORD(v9) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(this->m_fDCFbkMem),
                                     (__m128)LODWORD(this->m_fDCFbkMem),
                                     0);
  v151 = v7;
  v152 = v8;
  LODWORD(v162) = (unsigned __int128)_mm_shuffle_ps(
                                       (__m128)LODWORD(this->m_fFIRLPFB1),
                                       (__m128)LODWORD(this->m_fFIRLPFB1),
                                       0);
  v150 = v9;
  LODWORD(v160) = (unsigned __int128)_mm_shuffle_ps(
                                       (__m128)LODWORD(this->m_fDCCoef),
                                       (__m128)LODWORD(this->m_fDCCoef),
                                       0);
  v135 = (float *)v4->pData;
  v2.m128_f32[0] = -2.0 / (float)(signed int)v5->NonRTPC.uNumberOfDelays;
  v10 = v2;
  v11 = (__m128)LODWORD(v5->RTPC.fDryLevel);
  v158 = _mm_shuffle_ps(v10, v10, 0);
  v145 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  v148 = this->m_pfPreDelayStart;
  v129 = this->m_pfDelayStart[0];
  v173 = this->m_pfPreDelayStart != 0i64;
  v123 = this->m_pfDelayEnd[0];
  v11.m128_f32[0] = (float)(v11.m128_f32[0] - this->m_fCurrentDry) * (float)(1.0 / (float)v4->uMaxFrames);
  LODWORD(v154) = (unsigned __int128)_mm_shuffle_ps(v11, v11, 0);
  v12 = (__m128)LODWORD(v5->RTPC.fWetLevel);
  v149 = this->m_pfPreDelayEnd;
  v137 = this->m_pfDelayStart[1];
  v139 = this->m_pfDelayStart[2];
  v12.m128_f32[0] = (float)(v12.m128_f32[0] - this->m_fCurrentWet) * (float)(1.0 / (float)v4->uMaxFrames);
  LODWORD(v156) = (unsigned __int128)_mm_shuffle_ps(v12, v12, 0);
  v142 = this->m_pfDelayStart[3];
  v138 = this->m_pfDelayEnd[1];
  v141 = this->m_pfDelayEnd[2];
  v140 = this->m_pfDelayEnd[3];
  v13 = this->m_pfDelayRead[2];
  v14 = this->m_pfDelayRead[10];
  v15 = this->m_vIIRLPFB0[0];
  v16 = this->m_vIIRLPFA1[0];
  v17 = this->m_pfDelayWrite[0];
  v18 = this->m_pfDelayWrite[1];
  v19 = (__m128 *)this->m_pfDelayWrite[2];
  v20 = this->m_pfDelayWrite[3];
  v21 = this->m_vIIRLPFMem[0];
  v22 = this->m_vIIRLPFMem[1];
  v23 = this->m_vIIRLPFMem[2];
  v24 = this->m_pfDelayRead[0];
  v25 = this->m_pfDelayRead[1];
  v26 = this->m_pfDelayRead[3];
  v167 = v6->m_vIIRLPFB0[1];
  v168 = v15;
  v27 = v6->m_pfDelayRead[4];
  v28 = v6->m_pfDelayRead[6];
  v29 = v6->m_pfDelayRead[7];
  v155 = v6->m_vIIRLPFB0[2];
  v170 = v16;
  v30 = v6->m_pfDelayRead[8];
  v132 = v13;
  v159 = v6->m_vIIRLPFB0[3];
  v169 = v6->m_vIIRLPFA1[1];
  v127 = (unsigned __int64)v6->m_pfDelayRead[5];
  v122 = v14;
  v163 = v6->m_vIIRLPFA1[2];
  v121 = v6->m_pfDelayRead[9];
  v165 = v6->m_vIIRLPFA1[3];
  v31 = v6->m_vIIRLPFMem[3];
  v143 = v6->m_vIIRLPFMem[3];
  v126 = (unsigned __int64)v6->m_pfDelayRead[13];
  v124 = v6->m_pfDelayRead[11];
  v32 = v6->m_pfDelayRead[12];
  v128 = v6->m_pfDelayRead[14];
  v125 = v6->m_pfDelayRead[15];
  LODWORD(v13) = v172->uValidFrames;
  v174 = (signed int)v13;
  v33 = (_DWORD)v13 == 0;
  v34 = v132;
  if ( !v33 )
  {
    v35 = vOutDecorrelationVectorD;
    v36 = (unsigned int *)v132;
    v37 = v129;
    v38 = vOutDecorrelationVectorB;
    v39 = vOutDecorrelationVectorC;
    v40 = vOutDecorrelationVectorA;
    v157 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorB);
    v41 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorD);
    v161 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorA);
    v153 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorC);
    v166 = v41;
    do
    {
      v42 = (__m128)*(unsigned int *)v24;
      v43 = (__m128)*v36;
      v24 += 4;
      if ( v24 >= v123 )
        v24 = v37;
      v134 = (signed __int64)(v25 + 4);
      if ( v25 + 4 >= v123 )
      {
        v134 = (signed __int64)(v37 + 1);
        v37 = v129;
      }
      v36 += 4;
      if ( v36 >= (unsigned int *)v123 )
        v36 = (unsigned int *)(v37 + 2);
      v136 = (signed __int64)(v26 + 4);
      if ( v26 + 4 >= v123 )
        v136 = (signed __int64)(v37 + 3);
      v44 = v137;
      v45 = _mm_mul_ps(
              _mm_movelh_ps(
                _mm_unpacklo_ps(v42, (__m128)*(unsigned int *)v25),
                _mm_unpacklo_ps(v43, (__m128)*(unsigned int *)v26)),
              v15);
      v27 += 4;
      v46 = _mm_mul_ps(v21, v16);
      v47 = v45;
      v48 = (__m128)*((unsigned int *)v27 - 4);
      v21 = _mm_add_ps(v47, v46);
      if ( v27 >= v138 )
        v27 = v137;
      v127 += 16i64;
      v49 = _mm_mul_ps(v21, v35);
      v50 = (__m128)*(unsigned int *)(v127 - 16);
      v51 = _mm_mul_ps(v21, v40);
      v52 = _mm_mul_ps(v21, vOutDecorrelationVectorF);
      v53 = _mm_mul_ps(v21, v38);
      v54 = _mm_mul_ps(v21, v39);
      if ( v127 >= (unsigned __int64)v138 )
        v127 = (unsigned __int64)(v137 + 1);
      v130 = (signed __int64)(v28 + 4);
      if ( v28 + 4 >= v138 )
      {
        v130 = (signed __int64)(v137 + 2);
        v44 = v137;
      }
      v131 = (signed __int64)(v29 + 4);
      if ( v29 + 4 >= v138 )
        v131 = (signed __int64)(v44 + 3);
      v55 = (__m128)*(unsigned int *)v121;
      v56 = _mm_mul_ps(v22, v169);
      v30 += 4;
      v57 = _mm_mul_ps(
              _mm_movelh_ps(
                _mm_unpacklo_ps(v48, v50),
                _mm_unpacklo_ps((__m128)*(unsigned int *)v28, (__m128)*(unsigned int *)v29)),
              v167);
      v58 = (__m128)*((unsigned int *)v30 - 4);
      if ( v30 >= v141 )
        v30 = v139;
      v22 = _mm_add_ps(v57, v56);
      v121 += 4;
      v59 = _mm_add_ps(v22, v21);
      v60 = _mm_add_ps(v51, _mm_mul_ps(v22, v40));
      v61 = _mm_add_ps(v53, _mm_mul_ps(v22, v38));
      v62 = _mm_add_ps(v54, _mm_mul_ps(v22, v39));
      v63 = _mm_add_ps(v49, _mm_mul_ps(v22, vOutDecorrelationVectorE));
      v64 = v41;
      v65 = (__m128)*(unsigned int *)v124;
      v66 = _mm_add_ps(v52, _mm_mul_ps(v64, v22));
      v67 = (__m128)*(unsigned int *)v122;
      if ( v121 >= v141 )
        v121 = v139 + 1;
      v122 += 4;
      if ( v122 >= v141 )
        v122 = v139 + 2;
      v124 += 4;
      if ( v124 >= v141 )
        v124 = v139 + 3;
      v68 = _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v58, v55), _mm_unpacklo_ps(v67, v65)), v155);
      v69 = _mm_mul_ps(v23, v163);
      v32 += 4;
      v70 = v68;
      v71 = (__m128)*((unsigned int *)v32 - 4);
      if ( v32 >= v140 )
        v32 = v142;
      v23 = _mm_add_ps(v70, v69);
      v126 += 16i64;
      v146 = _mm_add_ps(v59, v23);
      v72 = (__m128)*(unsigned int *)v125;
      v73 = _mm_add_ps(v60, _mm_mul_ps(v23, v40));
      v74 = _mm_add_ps(v61, _mm_mul_ps(v23, v38));
      v75 = _mm_add_ps(v62, _mm_mul_ps(v23, v39));
      v76 = _mm_add_ps(v63, _mm_mul_ps(v157, v23));
      v77 = (__m128)*(unsigned int *)v128;
      v133 = _mm_add_ps(v66, _mm_mul_ps(v153, v23));
      v78 = (__m128)*(unsigned int *)(v126 - 16);
      if ( v126 >= (unsigned __int64)v140 )
        v126 = (unsigned __int64)(v142 + 1);
      v128 += 4;
      if ( v128 >= v140 )
        v128 = v142 + 2;
      v125 += 4;
      if ( v125 >= v140 )
        v125 = v142 + 3;
      v79 = v172->uMaxFrames;
      v80 = *v135;
      v81 = v135[v79];
      v82 = 2 * (signed int)v79;
      v83 = 3 * (signed int)v79;
      v84 = v135[v82];
      v85 = v135[v83];
      v143 = _mm_add_ps(
               _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v71, v78), _mm_unpacklo_ps(v77, v72)), v159),
               _mm_mul_ps(v143, v165));
      v86 = 4 * (signed int)v79;
      v87 = _mm_mul_ps(v143, vOutDecorrelationVectorB);
      v88 = v135[v86];
      v89 = _mm_add_ps(_mm_mul_ps(v143, vOutDecorrelationVectorA), v73);
      v90 = _mm_add_ps(v87, v74);
      v91 = _mm_add_ps(v87, v76);
      v92 = _mm_add_ps(v89, _mm_movehl_ps(v89, v89));
      v93 = _mm_add_ps(_mm_mul_ps(v143, vOutDecorrelationVectorC), v75);
      v94 = _mm_add_ps(_mm_mul_ps(v161, v143), v133);
      v95 = _mm_add_ps(v90, _mm_movehl_ps(v90, v90));
      v96 = _mm_add_ps(v93, _mm_movehl_ps(v93, v93));
      v97 = _mm_add_ps(v91, _mm_movehl_ps(v91, v91));
      v98 = _mm_add_ps(v94, _mm_movehl_ps(v94, v94));
      v99 = _mm_add_ps(v143, v146);
      v100 = _mm_add_ps(_mm_movehl_ps(v99, v99), v99);
      v101 = v145;
      v101.m128_f32[0] = v145.m128_f32[0] + v154;
      v145 = v101;
      v102 = v144;
      v103 = _mm_add_ps(_mm_shuffle_ps(v100, v100, 85), v100);
      v102.m128_f32[0] = v144.m128_f32[0] + v156;
      v144 = v102;
      *v135 = (float)(*v135 * v145.m128_f32[0])
            + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v92, v92, 85)) + v92.m128_f32[0]) * v102.m128_f32[0]);
      v100.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v95, v95, 85)) + v95.m128_f32[0];
      v95.m128_i32[0] = v102.m128_i32[0];
      ++v135;
      v104 = _mm_mul_ps(_mm_shuffle_ps(v103, v103, 0), v158);
      v135[v79 - 1] = (float)(v81 * v145.m128_f32[0]) + (float)(v100.m128_f32[0] * v102.m128_f32[0]);
      v135[v82 - 1] = (float)(v84 * v145.m128_f32[0])
                    + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v96, v96, 85)) + v96.m128_f32[0]) * v102.m128_f32[0]);
      v135[v83 - 1] = (float)(v85 * v145.m128_f32[0])
                    + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v97, v97, 85)) + v97.m128_f32[0]) * v102.m128_f32[0]);
      v100.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v98, v98, 85)) + v98.m128_f32[0];
      v102.m128_f32[0] = v88 * v145.m128_f32[0];
      v8 = (float)(v84 + v85) + (float)((float)(v80 + v81) + v88);
      v105 = _mm_add_ps(v104, v21);
      v102.m128_f32[0] = v102.m128_f32[0] + (float)(v100.m128_f32[0] * v95.m128_f32[0]);
      v106 = _mm_add_ps(v23, v104);
      v135[v86 - 1] = v102.m128_f32[0];
      v107 = _mm_add_ps(v143, v104);
      v108 = _mm_shuffle_ps(v107, _mm_shuffle_ps(v107, v105, 15), 201);
      v147 = _mm_shuffle_ps(v106, _mm_shuffle_ps(v106, v107, 15), 201);
      v109 = _mm_add_ps(v22, v104);
      v110 = _mm_shuffle_ps(v109, _mm_shuffle_ps(v109, v106, 15), 201);
      v111 = _mm_shuffle_ps(v105, _mm_shuffle_ps(v105, v109, 15), 201);
      v9 = (float)((float)(v160 * v150) + v8) - v152;
      v152 = v8;
      v150 = v9;
      if ( v173 )
      {
        v112 = *v3;
        *v3 = v9;
        ++v3;
        if ( v3 == v149 )
          v3 = v148;
      }
      else
      {
        v112 = v9;
      }
      v113 = v164;
      v37 = v129;
      v26 = (float *)v136;
      v25 = (float *)v134;
      v28 = (float *)v130;
      v38 = vOutDecorrelationVectorB;
      v39 = vOutDecorrelationVectorC;
      v40 = vOutDecorrelationVectorA;
      v29 = (float *)v131;
      v17 += 4;
      v113.m128_f32[0] = (float)(v164.m128_f32[0] * v112) + (float)(v162 * v151);
      v114 = _mm_shuffle_ps(v113, v113, 0);
      v41 = v166;
      v7 = v112;
      v115 = _mm_add_ps(v114, v111);
      v15 = v168;
      *((__m128 *)v17 - 1) = v115;
      v151 = v112;
      if ( v17 >= v123 )
        v17 = v129;
      v18 += 4;
      v116 = v114;
      v117 = v114;
      v118 = _mm_add_ps(v114, v108);
      v35 = vOutDecorrelationVectorD;
      v119 = _mm_add_ps(v116, v110);
      v16 = v170;
      *((__m128 *)v18 - 1) = v119;
      *v19 = _mm_add_ps(v117, v147);
      *(__m128 *)v20 = v118;
      if ( v18 >= v138 )
        v18 = v137;
      ++v19;
      if ( v19 >= (__m128 *)v141 )
        v19 = (__m128 *)v139;
      v20 += 4;
      if ( v20 >= v140 )
        v20 = v142;
      --v174;
    }
    while ( v174 );
    v31 = v143;
    v120 = (float *)v36;
    v6 = v171;
    v34 = v120;
  }
  v6->m_fFIRLPFMem = v7;
  v6->m_fDCFwdMem = v8;
  v6->m_fDCFbkMem = v9;
  v6->m_pfPreDelayRW = v3;
  v6->m_pfDelayRead[2] = v34;
  v6->m_vIIRLPFMem[0] = v21;
  v6->m_vIIRLPFMem[1] = v22;
  v6->m_vIIRLPFMem[2] = v23;
  v6->m_pfDelayRead[5] = (float *)v127;
  v6->m_pfDelayRead[0] = v24;
  v6->m_vIIRLPFMem[3] = v31;
  v6->m_pfDelayRead[9] = v121;
  v6->m_pfDelayRead[10] = v122;
  v6->m_pfDelayWrite[0] = v17;
  v6->m_pfDelayRead[11] = v124;
  v6->m_pfDelayWrite[1] = v18;
  v6->m_pfDelayRead[13] = (float *)v126;
  v6->m_pfDelayWrite[2] = (float *)v19;
  v6->m_pfDelayRead[14] = v128;
  v6->m_pfDelayWrite[3] = v20;
  v6->m_pfDelayRead[1] = v25;
  v6->m_pfDelayRead[3] = v26;
  v6->m_pfDelayRead[4] = v27;
  v6->m_pfDelayRead[15] = v125;
  v6->m_pfDelayRead[6] = v28;
  v6->m_pfDelayRead[7] = v29;
  v6->m_pfDelayRead[8] = v30;
  v6->m_pfDelayRead[12] = v32;
}

// File Line: 1513
// RVA: 0xAC7AB0
void __fastcall CAkFDNReverbFX::ProcessFivePointOne4(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *v3; // rsi
  CAkFDNReverbFX *v4; // r11
  AkAudioBuffer *v5; // r8
  CAkFDNReverbFXParams *v6; // rdx
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
  __m128 v21; // xmm1
  __m128 v22; // xmm0
  float *v23; // r11
  float *v24; // rax
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm0
  __m128 v28; // xmm3
  float v29; // xmm13_4
  __int64 v30; // rcx
  float v31; // xmm11_4
  __int64 v32; // rdx
  __int64 v33; // r8
  float v34; // xmm12_4
  __int64 v35; // r9
  float v36; // xmm9_4
  __m128 v37; // xmm6
  float v38; // xmm10_4
  __int64 v39; // r10
  __m128 v40; // xmm7
  __m128 v41; // xmm3
  __m128 v42; // xmm4
  __m128 v43; // ST10_16
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
  __m128 v56; // ST90_16
  __m128 v57; // xmm0
  __m128 v58; // xmm3
  __m128 v59; // xmm3
  float v60; // xmm2_4
  __m128 v61; // xmm1
  float *v62; // [rsp+0h] [rbp-1D8h]
  float *v63; // [rsp+20h] [rbp-1B8h]
  __m128 v64; // [rsp+30h] [rbp-1A8h]
  __m128 v65; // [rsp+40h] [rbp-198h]
  float v66; // [rsp+50h] [rbp-188h]
  float v67; // [rsp+60h] [rbp-178h]
  float v68; // [rsp+70h] [rbp-168h]
  __m128 v69; // [rsp+80h] [rbp-158h]
  float v70; // [rsp+A0h] [rbp-138h]
  float v71; // [rsp+B0h] [rbp-128h]
  __m128 v72; // [rsp+C0h] [rbp-118h]
  __m128 v73; // [rsp+D0h] [rbp-108h]
  __m128 v74; // [rsp+E0h] [rbp-F8h]
  CAkFDNReverbFX *v75; // [rsp+1E0h] [rbp+8h]
  AkAudioBuffer *v76; // [rsp+1E8h] [rbp+10h]
  bool v77; // [rsp+1F0h] [rbp+18h]
  int v78; // [rsp+1F8h] [rbp+20h]

  v76 = io_pBuffer;
  v75 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  v3 = this->m_pfPreDelayRW;
  v4 = this;
  v5 = io_pBuffer;
  v6 = this->m_pParams;
  v7 = this->m_vIIRLPFB0[0];
  v8 = this->m_vIIRLPFA1[0];
  v9 = this->m_vIIRLPFMem[0];
  v10 = this->m_pfDelayStart[0];
  v11 = this->m_pfDelayEnd[0];
  LODWORD(v12) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      0);
  v69 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  v13 = this->m_pfDelayWrite[0];
  v14 = this->m_pfDelayRead[0];
  LODWORD(v15) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      0);
  LODWORD(v16) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      0);
  LODWORD(v70) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      0);
  v64 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  v17 = this->m_pfDelayRead[1];
  v18 = this->m_pfDelayRead[2];
  v66 = v12;
  v72 = this->m_vIIRLPFB0[0];
  v74 = this->m_vIIRLPFA1[0];
  v19 = this->m_pfDelayRead[3];
  v62 = (float *)v5->pData;
  LODWORD(v68) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      0);
  v2.m128_f32[0] = -2.0 / (float)(signed int)v6->NonRTPC.uNumberOfDelays;
  v20 = v2;
  v21 = (__m128)LODWORD(v6->RTPC.fDryLevel);
  v73 = _mm_shuffle_ps(v20, v20, 0);
  v65 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  v77 = this->m_pfPreDelayStart != 0i64;
  v78 = v5->uValidFrames;
  v21.m128_f32[0] = (float)(v21.m128_f32[0] - this->m_fCurrentDry) * (float)(1.0 / (float)v5->uMaxFrames);
  LODWORD(v71) = (unsigned __int128)_mm_shuffle_ps(v21, v21, 0);
  v22 = (__m128)LODWORD(v6->RTPC.fWetLevel);
  v63 = this->m_pfPreDelayEnd;
  v22.m128_f32[0] = (float)(v22.m128_f32[0] - this->m_fCurrentWet) * (float)(1.0 / (float)v5->uMaxFrames);
  LODWORD(v67) = (unsigned __int128)_mm_shuffle_ps(v22, v22, 0);
  if ( v5->uValidFrames )
  {
    v23 = this->m_pfPreDelayStart;
    v24 = (float *)v5->pData;
    do
    {
      v25 = (__m128)*(unsigned int *)v14;
      v26 = (__m128)*(unsigned int *)v17;
      v27 = (__m128)*(unsigned int *)v18;
      v14 += 4;
      if ( v14 >= v11 )
        v14 = v10;
      v17 += 4;
      v28 = (__m128)*(unsigned int *)v19;
      if ( v17 >= v11 )
        v17 = v10 + 1;
      v18 += 4;
      if ( v18 >= v11 )
        v18 = v10 + 2;
      v19 += 4;
      if ( v19 >= v11 )
        v19 = v10 + 3;
      v29 = *v24;
      v30 = v5->uMaxFrames;
      v31 = v24[v30];
      v32 = 2 * (signed int)v30;
      v33 = 5 * (signed int)v30;
      v34 = v62[v32];
      v35 = 3 * (signed int)v30;
      v36 = v62[v33];
      v37 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v25, v26), _mm_unpacklo_ps(v27, v28)), v7),
              _mm_mul_ps(v9, v8));
      v38 = v62[v35];
      v39 = 4 * (signed int)v30;
      v40 = _mm_mul_ps(v37, vOutDecorrelationVectorB);
      v41 = _mm_mul_ps(v37, vOutDecorrelationVectorA);
      v42 = _mm_mul_ps(v37, vOutDecorrelationVectorC);
      v43 = v37;
      v44 = v62[v39];
      v45 = v37;
      v46 = _mm_add_ps(v41, _mm_movehl_ps(v41, v41));
      v47 = _mm_mul_ps(v37, vOutDecorrelationVectorD);
      v48 = _mm_mul_ps(v37, vOutDecorrelationVectorF);
      v49 = _mm_add_ps(v40, _mm_movehl_ps(v40, v40));
      v50 = _mm_add_ps(v42, _mm_movehl_ps(v42, v42));
      v51 = _mm_add_ps(v47, _mm_movehl_ps(v47, v47));
      v52 = _mm_add_ps(v48, _mm_movehl_ps(v48, v48));
      v53 = _mm_add_ps(_mm_movehl_ps(v45, v45), v45);
      v54 = _mm_add_ps(_mm_shuffle_ps(v53, v53, 85), v53);
      v55 = v65;
      v55.m128_f32[0] = v65.m128_f32[0] + v71;
      v56 = v54;
      v65 = v55;
      v57 = v64;
      v57.m128_f32[0] = v64.m128_f32[0] + v67;
      v64 = v57;
      *v62 = (float)(*v24 * v65.m128_f32[0])
           + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v46, v46, 85)) + v46.m128_f32[0]) * v57.m128_f32[0]);
      v24 = v62 + 1;
      v62 = v24;
      v24[v30 - 1] = (float)(v31 * v65.m128_f32[0])
                   + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v49, v49, 85)) + v49.m128_f32[0]) * v57.m128_f32[0]);
      v24[v32 - 1] = (float)(v34 * v65.m128_f32[0])
                   + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 85)) + v50.m128_f32[0]) * v57.m128_f32[0]);
      v12 = (float)((float)(v34 + v36) + v44) + (float)((float)(v29 + v31) + v38);
      v24[v33 - 1] = (float)(v36 * v65.m128_f32[0])
                   + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v49, v49, 85)) + v49.m128_f32[0]) * v57.m128_f32[0]);
      v24[v35 - 1] = (float)(v38 * v65.m128_f32[0])
                   + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v51, v51, 85)) + v51.m128_f32[0]) * v57.m128_f32[0]);
      v54.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v52, v52, 85)) + v52.m128_f32[0];
      v9 = v43;
      v24[v39 - 1] = (float)(v44 * v65.m128_f32[0]) + (float)(v54.m128_f32[0] * v57.m128_f32[0]);
      v58 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), v73), v43);
      v59 = _mm_shuffle_ps(v58, _mm_shuffle_ps(v58, v58, 15), 201);
      v16 = (float)((float)(v68 * v16) + v12) - v66;
      v66 = (float)((float)(v34 + v36) + v44) + (float)((float)(v29 + v31) + v38);
      if ( v77 )
      {
        v60 = *v3;
        *v3 = v16;
        ++v3;
        if ( v3 == v63 )
          v3 = v23;
      }
      else
      {
        v60 = v16;
      }
      v61 = v69;
      v7 = v72;
      v5 = v76;
      v13 += 4;
      v61.m128_f32[0] = (float)(v69.m128_f32[0] * v60) + (float)(v70 * v15);
      v8 = v74;
      v15 = v60;
      *((__m128 *)v13 - 1) = _mm_add_ps(_mm_shuffle_ps(v61, v61, 0), v59);
      if ( v13 >= v11 )
        v13 = v10;
      --v78;
    }
    while ( v78 );
    v4 = v75;
  }
  v4->m_fFIRLPFMem = v15;
  v4->m_fDCFwdMem = v12;
  v4->m_fDCFbkMem = v16;
  v4->m_pfPreDelayRW = v3;
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
  float *v3; // r14
  CAkFDNReverbFX *v4; // r11
  float *v5; // r10
  float *v6; // rdi
  float *v7; // rsi
  float *v8; // rbx
  float *v9; // r13
  float v10; // xmm7_4
  float v11; // xmm3_4
  float *v12; // r15
  float *v13; // r12
  float *v14; // rbp
  AkAudioBuffer *v15; // r8
  CAkFDNReverbFXParams *v16; // rdx
  unsigned int v17; // eax
  float *v18; // r8
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128i v21; // xmm0
  float *v22; // rax
  float v23; // xmm2_4
  __m128 v24; // xmm0
  float *v25; // rdx
  float v26; // xmm2_4
  __m128 v27; // xmm5
  __m128 v28; // xmm9
  float *v29; // rcx
  float *v30; // rax
  __m128 v31; // xmm8
  __m128 v32; // xmm10
  __m128 v33; // xmm0
  int v34; // er9
  bool v35; // zf
  float *v36; // r9
  __m128 v37; // xmm15
  __m128 v38; // xmm4
  unsigned int *v39; // r11
  __m128 v40; // xmm6
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm0
  __m128 v44; // xmm3
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm15
  __m128 v49; // xmm8
  __m128 v50; // xmm3
  __m128 v51; // xmm7
  __m128 v52; // xmm6
  __m128 v53; // xmm0
  __m128 v54; // xmm5
  __m128 v55; // xmm1
  __int64 v56; // rcx
  float v57; // xmm14_4
  float v58; // xmm12_4
  __int64 v59; // rdx
  __int64 v60; // r8
  __m128 v61; // xmm6
  float v62; // xmm13_4
  __int64 v63; // r9
  float v64; // xmm10_4
  float v65; // xmm11_4
  __int64 v66; // r10
  __m128 v67; // xmm8
  float v68; // xmm9_4
  __m128 v69; // xmm2
  __m128 v70; // xmm2
  __m128 v71; // xmm3
  __m128 v72; // xmm3
  __m128 v73; // xmm4
  __m128 v74; // xmm4
  __m128 v75; // xmm5
  __m128 v76; // xmm5
  __m128 v77; // xmm6
  __m128 v78; // xmm6
  __m128 v79; // xmm8
  __m128 v80; // xmm0
  __m128 v81; // xmm1
  __m128 v82; // xmm0
  __m128 v83; // xmm0
  __m128 v84; // xmm7
  __m128 v85; // xmm7
  __m128 v86; // xmm4
  __m128 v87; // xmm1
  __m128 v88; // xmm5
  __m128 v89; // xmm4
  __m128 v90; // xmm1
  __m128 v91; // xmm0
  __m128 v92; // xmm1
  __m128 v93; // xmm0
  float *v94; // ST20_8
  unsigned __int64 v95; // [rsp+0h] [rbp-278h]
  float *v96; // [rsp+8h] [rbp-270h]
  signed __int64 v97; // [rsp+10h] [rbp-268h]
  __m128 v98; // [rsp+20h] [rbp-258h]
  float *v99; // [rsp+30h] [rbp-248h]
  __m128 v100; // [rsp+40h] [rbp-238h]
  float *v101; // [rsp+50h] [rbp-228h]
  float *v102; // [rsp+58h] [rbp-220h]
  float *v103; // [rsp+60h] [rbp-218h]
  float *v104; // [rsp+68h] [rbp-210h]
  __m128 v105; // [rsp+70h] [rbp-208h]
  float *v106; // [rsp+80h] [rbp-1F8h]
  __m128 v107; // [rsp+90h] [rbp-1E8h]
  float v108; // [rsp+A0h] [rbp-1D8h]
  float v109; // [rsp+B0h] [rbp-1C8h]
  float v110; // [rsp+C0h] [rbp-1B8h]
  __m128 v111; // [rsp+D0h] [rbp-1A8h]
  __m128 v112; // [rsp+E0h] [rbp-198h]
  __m128 v113; // [rsp+F0h] [rbp-188h]
  float v114; // [rsp+100h] [rbp-178h]
  float v115; // [rsp+110h] [rbp-168h]
  __m128 v116; // [rsp+120h] [rbp-158h]
  float v117; // [rsp+130h] [rbp-148h]
  __m128 v118; // [rsp+140h] [rbp-138h]
  __m128 v119; // [rsp+150h] [rbp-128h]
  __m128 v120; // [rsp+160h] [rbp-118h]
  float v121; // [rsp+170h] [rbp-108h]
  __m128 v122; // [rsp+180h] [rbp-F8h]
  CAkFDNReverbFX *v123; // [rsp+280h] [rbp+8h]
  AkAudioBuffer *v124; // [rsp+288h] [rbp+10h]
  bool v125; // [rsp+290h] [rbp+18h]
  int v126; // [rsp+298h] [rbp+20h]

  v124 = io_pBuffer;
  v123 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  v3 = this->m_pfPreDelayRW;
  v4 = this;
  v5 = this->m_pfDelayEnd[1];
  v6 = this->m_pfDelayWrite[0];
  v112 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  v7 = this->m_pfDelayWrite[1];
  v8 = this->m_pfDelayRead[0];
  v9 = this->m_pfDelayRead[1];
  LODWORD(v10) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      0);
  v107 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  v109 = v10;
  LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      0);
  v12 = this->m_pfDelayRead[2];
  v13 = this->m_pfDelayRead[3];
  v14 = this->m_pfDelayRead[4];
  LODWORD(v114) = (unsigned __int128)_mm_shuffle_ps(
                                       (__m128)LODWORD(this->m_fFIRLPFB1),
                                       (__m128)LODWORD(this->m_fFIRLPFB1),
                                       0);
  v108 = v11;
  LODWORD(v117) = (unsigned __int128)_mm_shuffle_ps(
                                       (__m128)LODWORD(this->m_fDCCoef),
                                       (__m128)LODWORD(this->m_fDCCoef),
                                       0);
  v15 = io_pBuffer;
  v16 = this->m_pParams;
  v99 = this->m_pfDelayStart[1];
  v102 = this->m_pfDelayEnd[1];
  v96 = (float *)v15->pData;
  v17 = v15->uMaxFrames;
  v18 = this->m_pfDelayEnd[0];
  v106 = this->m_pfDelayEnd[0];
  v2.m128_f32[0] = -2.0 / (float)(signed int)v16->NonRTPC.uNumberOfDelays;
  v19 = v2;
  v20 = (__m128)LODWORD(v16->RTPC.fDryLevel);
  v111 = _mm_shuffle_ps(v19, v19, 0);
  v105 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  v21 = _mm_cvtsi32_si128(v17);
  v101 = this->m_pfPreDelayStart;
  v22 = this->m_pfDelayRead[5];
  v125 = this->m_pfPreDelayStart != 0i64;
  v21.m128i_i32[0] = (unsigned __int128)_mm_cvtepi32_ps(v21);
  v23 = 1.0 / *(float *)v21.m128i_i32;
  v20.m128_f32[0] = (float)(v20.m128_f32[0] - this->m_fCurrentDry) * (float)(1.0 / *(float *)v21.m128i_i32);
  LODWORD(v121) = (unsigned __int128)_mm_shuffle_ps(v20, v20, 0);
  v24 = (__m128)LODWORD(v16->RTPC.fWetLevel);
  v25 = this->m_pfDelayStart[0];
  v104 = this->m_pfDelayStart[0];
  v24.m128_f32[0] = (float)(v24.m128_f32[0] - this->m_fCurrentWet) * v23;
  LODWORD(v26) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      0);
  v103 = this->m_pfPreDelayEnd;
  LODWORD(v115) = (unsigned __int128)_mm_shuffle_ps(v24, v24, 0);
  v110 = v26;
  v27 = this->m_vIIRLPFB0[0];
  v28 = this->m_vIIRLPFB0[1];
  v29 = this->m_pfDelayRead[7];
  v95 = (unsigned __int64)v22;
  v30 = v4->m_pfDelayRead[6];
  v31 = v4->m_vIIRLPFA1[0];
  v32 = v4->m_vIIRLPFA1[1];
  v33 = v4->m_vIIRLPFMem[1];
  v34 = v124->uValidFrames;
  v126 = v34;
  v35 = v34 == 0;
  v36 = v99;
  v37 = v4->m_vIIRLPFMem[0];
  v116 = v27;
  v120 = v28;
  v118 = v4->m_vIIRLPFA1[0];
  v122 = v4->m_vIIRLPFA1[1];
  v100 = v4->m_vIIRLPFMem[1];
  if ( !v35 )
  {
    v38 = vOutDecorrelationVectorB;
    v39 = (unsigned int *)v4->m_pfDelayRead[6];
    v40 = vOutDecorrelationVectorD;
    v119 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorB);
    v113 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorD);
    do
    {
      v41 = (__m128)*(unsigned int *)v8;
      v42 = (__m128)*(unsigned int *)v9;
      v43 = (__m128)*(unsigned int *)v12;
      v8 += 4;
      if ( v8 >= v18 )
        v8 = v25;
      v9 += 4;
      v44 = (__m128)*(unsigned int *)v13;
      if ( v9 >= v18 )
        v9 = v25 + 1;
      v12 += 4;
      if ( v12 >= v18 )
        v12 = v25 + 2;
      v13 += 4;
      if ( v13 >= v18 )
        v13 = v25 + 3;
      v45 = _mm_unpacklo_ps(v43, v44);
      v46 = _mm_unpacklo_ps(v41, v42);
      v47 = (__m128)*(unsigned int *)v14;
      v14 += 4;
      if ( v14 >= v5 )
        v14 = v36;
      v48 = _mm_mul_ps(v37, v31);
      v95 += 16i64;
      v49 = (__m128)*(unsigned int *)v29;
      v37 = _mm_add_ps(_mm_mul_ps(_mm_movelh_ps(v46, v45), v27), v48);
      v50 = _mm_mul_ps(v37, vOutDecorrelationVectorA);
      v51 = _mm_mul_ps(v37, v40);
      v52 = (__m128)*(unsigned int *)(v95 - 16);
      v98 = _mm_mul_ps(v37, vOutDecorrelationVectorF);
      v53 = (__m128)*v39;
      v54 = _mm_mul_ps(v37, vOutDecorrelationVectorC);
      v55 = _mm_mul_ps(v37, v38);
      if ( v95 >= (unsigned __int64)v5 )
        v95 = (unsigned __int64)(v36 + 1);
      v39 += 4;
      if ( v39 >= (unsigned int *)v5 )
        v39 = (unsigned int *)(v36 + 2);
      v97 = (signed __int64)(v29 + 4);
      if ( v29 + 4 >= v5 )
        v97 = (signed __int64)(v36 + 3);
      v56 = v124->uMaxFrames;
      v57 = *v96;
      v58 = v96[v56];
      v59 = 2 * (signed int)v56;
      v60 = 5 * (signed int)v56;
      v61 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v47, v52), _mm_unpacklo_ps(v53, v49)), v28),
              _mm_mul_ps(v100, v32));
      v62 = v96[v59];
      v63 = 3 * (signed int)v56;
      v64 = v96[v60];
      v100 = v61;
      v65 = v96[v63];
      v66 = 4 * (signed int)v56;
      v67 = _mm_add_ps(_mm_mul_ps(v113, v61), v98);
      v68 = v96[v66];
      v69 = _mm_add_ps(_mm_mul_ps(v61, vOutDecorrelationVectorA), v50);
      v70 = _mm_add_ps(v69, _mm_movehl_ps(v69, v69));
      v71 = _mm_add_ps(_mm_mul_ps(v61, v38), v55);
      v72 = _mm_add_ps(v71, _mm_movehl_ps(v71, v71));
      v73 = _mm_add_ps(_mm_mul_ps(v61, vOutDecorrelationVectorC), v54);
      v74 = _mm_add_ps(v73, _mm_movehl_ps(v73, v73));
      v75 = _mm_add_ps(_mm_mul_ps(v119, v61), v55);
      v76 = _mm_add_ps(v75, _mm_movehl_ps(v75, v75));
      v77 = _mm_add_ps(_mm_mul_ps(v61, vOutDecorrelationVectorE), v51);
      v78 = _mm_add_ps(v77, _mm_movehl_ps(v77, v77));
      v79 = _mm_add_ps(v67, _mm_movehl_ps(v67, v67));
      v80 = _mm_add_ps(v100, v37);
      v81 = _mm_add_ps(_mm_movehl_ps(v80, v80), v80);
      v82 = v105;
      v82.m128_f32[0] = v105.m128_f32[0] + v121;
      v105 = v82;
      v83 = v107;
      v84 = _mm_add_ps(_mm_shuffle_ps(v81, v81, 85), v81);
      v83.m128_f32[0] = v107.m128_f32[0] + v115;
      v107 = v83;
      v85 = _mm_mul_ps(_mm_shuffle_ps(v84, v84, 0), v111);
      ++v96;
      *(v96 - 1) = (float)(v57 * v105.m128_f32[0])
                 + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v70, v70, 85)) + v70.m128_f32[0]) * v83.m128_f32[0]);
      v96[v56 - 1] = (float)(v58 * v105.m128_f32[0])
                   + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v72, v72, 85)) + v72.m128_f32[0]) * v83.m128_f32[0]);
      v81.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v74, v74, 85)) + v74.m128_f32[0];
      v86 = _mm_add_ps(v85, v37);
      v96[v59 - 1] = (float)(v62 * v105.m128_f32[0]) + (float)(v81.m128_f32[0] * v83.m128_f32[0]);
      v96[v60 - 1] = (float)(v64 * v105.m128_f32[0])
                   + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v76, v76, 85)) + v76.m128_f32[0]) * v83.m128_f32[0]);
      v96[v63 - 1] = (float)(v65 * v105.m128_f32[0])
                   + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v78, v78, 85)) + v78.m128_f32[0]) * v83.m128_f32[0]);
      v96[v66 - 1] = (float)(v68 * v105.m128_f32[0])
                   + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v79, v79, 85)) + v79.m128_f32[0]) * v83.m128_f32[0]);
      v87 = _mm_add_ps(v100, v85);
      v10 = (float)((float)(v62 + v64) + v68) + (float)((float)(v57 + v58) + v65);
      v88 = _mm_shuffle_ps(v87, _mm_shuffle_ps(v87, v86, 15), 201);
      v89 = _mm_shuffle_ps(v86, _mm_shuffle_ps(v86, v87, 15), 201);
      v11 = (float)((float)(v117 * v108) + v10) - v109;
      v109 = (float)((float)(v62 + v64) + v68) + (float)((float)(v57 + v58) + v65);
      v108 = v11;
      if ( v125 )
      {
        v26 = *v3;
        *v3 = v11;
        ++v3;
        if ( v3 == v103 )
          v3 = v101;
      }
      else
      {
        v26 = v11;
      }
      v90 = v112;
      v18 = v106;
      v25 = v104;
      v5 = v102;
      v36 = v99;
      v40 = vOutDecorrelationVectorD;
      v31 = v118;
      v28 = v120;
      v29 = (float *)v97;
      v6 += 4;
      v90.m128_f32[0] = (float)(v112.m128_f32[0] * v26) + (float)(v114 * v110);
      v32 = v122;
      v91 = _mm_shuffle_ps(v90, v90, 0);
      v110 = v26;
      v92 = _mm_add_ps(v91, v88);
      v93 = _mm_add_ps(v91, v89);
      v38 = vOutDecorrelationVectorB;
      v27 = v116;
      *((__m128 *)v6 - 1) = v93;
      if ( v6 >= v106 )
        v6 = v104;
      *(__m128 *)v7 = v92;
      v7 += 4;
      if ( v7 >= v102 )
        v7 = v99;
      --v126;
    }
    while ( v126 );
    v33 = v100;
    v94 = (float *)v39;
    v4 = v123;
    v30 = v94;
  }
  v4->m_fFIRLPFMem = v26;
  v4->m_fDCFwdMem = v10;
  v4->m_fDCFbkMem = v11;
  v4->m_pfPreDelayRW = v3;
  v4->m_vIIRLPFMem[0] = v37;
  v4->m_pfDelayRead[5] = (float *)v95;
  v4->m_vIIRLPFMem[1] = v33;
  v4->m_pfDelayWrite[0] = v6;
  v4->m_pfDelayWrite[1] = v7;
  v4->m_pfDelayRead[0] = v8;
  v4->m_pfDelayRead[1] = v9;
  v4->m_pfDelayRead[2] = v12;
  v4->m_pfDelayRead[3] = v13;
  v4->m_pfDelayRead[4] = v14;
  v4->m_pfDelayRead[6] = v30;
  v4->m_pfDelayRead[7] = v29;
}

// File Line: 1586
// RVA: 0xAC88E0
void __fastcall CAkFDNReverbFX::ProcessFivePointOne12(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *v3; // r15
  CAkFDNReverbFX *v4; // r11
  float *v5; // rdi
  float *v6; // rsi
  float *v7; // rbp
  float *v8; // rbx
  float *v9; // r13
  float v10; // xmm4_4
  float v11; // xmm9_4
  float v12; // xmm3_4
  AkAudioBuffer *v13; // r8
  CAkFDNReverbFXParams *v14; // rdx
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  float *v18; // rcx
  __m128 v19; // xmm5
  __m128 v20; // xmm6
  float *v21; // rax
  float *v22; // r14
  float *v23; // r8
  float *v24; // r12
  __m128 v25; // xmm15
  __m128 v26; // xmm1
  float *v27; // r10
  int v28; // er9
  float *v29; // rdx
  __m128 v30; // xmm0
  bool v31; // zf
  float *v32; // r9
  float *v33; // r11
  unsigned __int64 v34; // rax
  __m128 v35; // xmm8
  __m128 v36; // xmm10
  __m128 v37; // xmm11
  __m128 v38; // xmm12
  __m128 v39; // xmm14
  __m128 v40; // xmm13
  __m128 v41; // xmm2
  __m128 v42; // xmm0
  __m128 v43; // xmm4
  float *v44; // rax
  __m128 v45; // xmm2
  __m128 v46; // xmm0
  __m128 v47; // xmm15
  __m128 v48; // xmm2
  __m128 v49; // xmm7
  __m128 v50; // xmm8
  __m128 v51; // xmm4
  __m128 v52; // xmm3
  __m128 v53; // xmm5
  __m128 v54; // xmm6
  float *v55; // rax
  __m128 v56; // xmm2
  __m128 v57; // xmm8
  __m128 v58; // xmm1
  __m128 v59; // xmm4
  __m128 v60; // xmm0
  __m128 v61; // xmm2
  __m128 v62; // xmm6
  __m128 v63; // xmm5
  __m128 v64; // xmm7
  __m128 v65; // xmm0
  __m128 v66; // xmm1
  __m128 v67; // xmm3
  __int64 v68; // rcx
  float v69; // xmm14_4
  float v70; // xmm12_4
  __int64 v71; // rdx
  __int64 v72; // r8
  float v73; // xmm13_4
  __int64 v74; // r9
  float v75; // xmm10_4
  float v76; // xmm11_4
  __m128 v77; // xmm8
  __int64 v78; // r10
  __m128 v79; // xmm2
  __m128 v80; // xmm8
  __m128 v81; // xmm2
  float v82; // xmm9_4
  __m128 v83; // xmm3
  __m128 v84; // xmm5
  __m128 v85; // xmm3
  __m128 v86; // xmm2
  __m128 v87; // xmm4
  __m128 v88; // xmm4
  __m128 v89; // xmm6
  __m128 v90; // xmm8
  __m128 v91; // xmm5
  __m128 v92; // xmm6
  __m128 v93; // xmm0
  __m128 v94; // xmm1
  __m128 v95; // xmm0
  __m128 v96; // xmm0
  __m128 v97; // xmm7
  __m128 v98; // xmm7
  __m128 v99; // xmm5
  __m128 v100; // xmm2
  __m128 v101; // xmm1
  __m128 v102; // xmm6
  __m128 v103; // xmm7
  __m128 v104; // xmm5
  float v105; // xmm1_4
  __m128 v106; // xmm2
  __m128 v107; // xmm2
  __m128 v108; // xmm0
  __m128 v109; // xmm1
  __m128 v110; // xmm2
  float *v111; // ST70_8
  unsigned __int64 v112; // [rsp+0h] [rbp-308h]
  float *v113; // [rsp+8h] [rbp-300h]
  unsigned __int64 v114; // [rsp+10h] [rbp-2F8h]
  float *v115; // [rsp+18h] [rbp-2F0h]
  signed __int64 v116; // [rsp+20h] [rbp-2E8h]
  signed __int64 v117; // [rsp+28h] [rbp-2E0h]
  float *v118; // [rsp+30h] [rbp-2D8h]
  signed __int64 v119; // [rsp+38h] [rbp-2D0h]
  float *v120; // [rsp+40h] [rbp-2C8h]
  float *v121; // [rsp+48h] [rbp-2C0h]
  __m128 v122; // [rsp+50h] [rbp-2B8h]
  signed __int64 v123; // [rsp+60h] [rbp-2A8h]
  __m128 v124; // [rsp+70h] [rbp-298h]
  float *v125; // [rsp+80h] [rbp-288h]
  float *v126; // [rsp+88h] [rbp-280h]
  float *v127; // [rsp+90h] [rbp-278h]
  __m128 v128; // [rsp+A0h] [rbp-268h]
  __m128 v129; // [rsp+B0h] [rbp-258h]
  float *v130; // [rsp+C0h] [rbp-248h]
  __m128 v131; // [rsp+D0h] [rbp-238h]
  float *v132; // [rsp+E0h] [rbp-228h]
  float v133; // [rsp+F0h] [rbp-218h]
  float v134; // [rsp+100h] [rbp-208h]
  float v135; // [rsp+110h] [rbp-1F8h]
  __m128 v136; // [rsp+120h] [rbp-1E8h]
  __m128 v137; // [rsp+130h] [rbp-1D8h]
  float v138; // [rsp+140h] [rbp-1C8h]
  __m128 v139; // [rsp+150h] [rbp-1B8h]
  __m128 v140; // [rsp+160h] [rbp-1A8h]
  float v141; // [rsp+170h] [rbp-198h]
  __m128 v142; // [rsp+180h] [rbp-188h]
  __m128 v143; // [rsp+190h] [rbp-178h]
  float v144; // [rsp+1A0h] [rbp-168h]
  float v145; // [rsp+1B0h] [rbp-158h]
  __m128 v146; // [rsp+1C0h] [rbp-148h]
  __m128 v147; // [rsp+1D0h] [rbp-138h]
  __m128 v148; // [rsp+1E0h] [rbp-128h]
  __m128 v149; // [rsp+1F0h] [rbp-118h]
  __m128 v150; // [rsp+200h] [rbp-108h]
  __m128 v151; // [rsp+210h] [rbp-F8h]
  CAkFDNReverbFX *v152; // [rsp+310h] [rbp+8h]
  AkAudioBuffer *v153; // [rsp+318h] [rbp+10h]
  bool v154; // [rsp+320h] [rbp+18h]
  int v155; // [rsp+328h] [rbp+20h]

  v153 = io_pBuffer;
  v152 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  v3 = this->m_pfPreDelayRW;
  v4 = this;
  v5 = this->m_pfDelayWrite[0];
  v6 = this->m_pfDelayWrite[1];
  v143 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  v128 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  v7 = this->m_pfDelayWrite[2];
  v8 = this->m_pfDelayRead[0];
  v9 = this->m_pfDelayRead[2];
  LODWORD(v10) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      0);
  LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      0);
  LODWORD(v12) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      0);
  v134 = v10;
  v135 = v11;
  v133 = v12;
  v13 = io_pBuffer;
  v14 = this->m_pParams;
  v127 = this->m_pfDelayStart[0];
  LODWORD(v145) = (unsigned __int128)_mm_shuffle_ps(
                                       (__m128)LODWORD(this->m_fFIRLPFB1),
                                       (__m128)LODWORD(this->m_fFIRLPFB1),
                                       0);
  LODWORD(v141) = (unsigned __int128)_mm_shuffle_ps(
                                       (__m128)LODWORD(this->m_fDCCoef),
                                       (__m128)LODWORD(this->m_fDCCoef),
                                       0);
  v120 = (float *)v13->pData;
  v2.m128_f32[0] = -2.0 / (float)(signed int)v14->NonRTPC.uNumberOfDelays;
  v15 = v2;
  v16 = (__m128)LODWORD(v14->RTPC.fDryLevel);
  v139 = _mm_shuffle_ps(v15, v15, 0);
  v131 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  v130 = this->m_pfPreDelayStart;
  v154 = this->m_pfPreDelayStart != 0i64;
  v118 = this->m_pfDelayEnd[0];
  v16.m128_f32[0] = (float)(v16.m128_f32[0] - this->m_fCurrentDry) * (float)(1.0 / (float)v13->uMaxFrames);
  LODWORD(v144) = (unsigned __int128)_mm_shuffle_ps(v16, v16, 0);
  v17 = (__m128)LODWORD(v14->RTPC.fWetLevel);
  v115 = this->m_pfDelayStart[2];
  v132 = this->m_pfPreDelayEnd;
  v17.m128_f32[0] = (float)(v17.m128_f32[0] - this->m_fCurrentWet) * (float)(1.0 / (float)v13->uMaxFrames);
  v121 = this->m_pfDelayStart[1];
  v125 = this->m_pfDelayEnd[2];
  LODWORD(v138) = (unsigned __int128)_mm_shuffle_ps(v17, v17, 0);
  v126 = this->m_pfDelayEnd[1];
  v18 = this->m_pfDelayRead[1];
  v19 = v4->m_vIIRLPFB0[0];
  v20 = v4->m_vIIRLPFA1[0];
  v21 = v4->m_pfDelayRead[3];
  v22 = v4->m_pfDelayRead[4];
  v23 = v4->m_pfDelayRead[7];
  v24 = v4->m_pfDelayRead[8];
  v25 = v4->m_vIIRLPFMem[0];
  v26 = v4->m_vIIRLPFMem[1];
  v146 = v4->m_vIIRLPFB0[1];
  v27 = v4->m_pfDelayRead[10];
  v114 = (unsigned __int64)v4->m_pfDelayRead[9];
  v149 = v4->m_vIIRLPFB0[0];
  v151 = v4->m_vIIRLPFA1[0];
  v113 = v4->m_pfDelayRead[11];
  v112 = (unsigned __int64)v4->m_pfDelayRead[5];
  v140 = v4->m_vIIRLPFB0[2];
  v148 = v4->m_vIIRLPFA1[1];
  v28 = v153->uValidFrames;
  v29 = v4->m_pfDelayRead[6];
  v137 = v4->m_vIIRLPFA1[2];
  v30 = v4->m_vIIRLPFMem[2];
  v155 = v28;
  v31 = v28 == 0;
  v32 = v127;
  v122 = v4->m_vIIRLPFMem[2];
  if ( !v31 )
  {
    v33 = v4->m_pfDelayRead[3];
    v34 = (unsigned __int64)v118;
    v35 = vOutDecorrelationVectorD;
    v36 = vOutDecorrelationVectorB;
    v37 = vOutDecorrelationVectorC;
    v38 = vOutDecorrelationVectorA;
    v39 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorD);
    v40 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorB);
    v142 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorC);
    v147 = v39;
    v136 = v40;
    do
    {
      v41 = (__m128)*(unsigned int *)v8;
      v42 = (__m128)*(unsigned int *)v9;
      v8 += 4;
      if ( (unsigned __int64)v8 >= v34 )
        v8 = v32;
      v123 = (signed __int64)(v18 + 4);
      v43 = (__m128)*(unsigned int *)v33;
      if ( (unsigned __int64)(v18 + 4) >= v34 )
      {
        v123 = (signed __int64)(v32 + 1);
        v34 = (unsigned __int64)v118;
      }
      v9 += 4;
      if ( (unsigned __int64)v9 >= v34 )
        v9 = v32 + 2;
      v33 += 4;
      if ( (unsigned __int64)v33 >= v34 )
        v33 = v32 + 3;
      v44 = v121;
      v45 = _mm_mul_ps(
              _mm_movelh_ps(_mm_unpacklo_ps(v41, (__m128)*(unsigned int *)v18), _mm_unpacklo_ps(v42, v43)),
              v19);
      v22 += 4;
      v46 = _mm_mul_ps(v25, v20);
      v47 = v45;
      v48 = (__m128)*((unsigned int *)v22 - 4);
      v25 = _mm_add_ps(v47, v46);
      if ( v22 >= v126 )
        v22 = v121;
      v112 += 16i64;
      v49 = _mm_mul_ps(v25, v35);
      v50 = (__m128)*(unsigned int *)(v112 - 16);
      v51 = _mm_mul_ps(v25, v38);
      v52 = _mm_mul_ps(v25, vOutDecorrelationVectorF);
      v53 = _mm_mul_ps(v25, v36);
      v54 = _mm_mul_ps(v25, v37);
      if ( v112 >= (unsigned __int64)v126 )
        v112 = (unsigned __int64)(v121 + 1);
      v116 = (signed __int64)(v29 + 4);
      if ( v29 + 4 >= v126 )
      {
        v116 = (signed __int64)(v121 + 2);
        v44 = v121;
      }
      v117 = (signed __int64)(v23 + 4);
      if ( v23 + 4 >= v126 )
        v117 = (signed __int64)(v44 + 3);
      v55 = v115;
      v24 += 4;
      v56 = _mm_mul_ps(
              _mm_movelh_ps(
                _mm_unpacklo_ps(v48, v50),
                _mm_unpacklo_ps((__m128)*(unsigned int *)v29, (__m128)*(unsigned int *)v23)),
              v146);
      v57 = (__m128)*(unsigned int *)v113;
      v58 = _mm_add_ps(v56, _mm_mul_ps(v26, v148));
      v129 = v58;
      v59 = _mm_add_ps(v51, _mm_mul_ps(v58, v38));
      v60 = _mm_mul_ps(v58, v37);
      v124 = _mm_add_ps(v53, _mm_mul_ps(v58, v36));
      v61 = (__m128)*((unsigned int *)v24 - 4);
      if ( v24 >= v125 )
        v24 = v115;
      v62 = _mm_add_ps(v54, v60);
      v114 += 16i64;
      v63 = _mm_add_ps(v53, _mm_mul_ps(v40, v58));
      v64 = _mm_add_ps(v49, _mm_mul_ps(v58, vOutDecorrelationVectorE));
      v65 = _mm_mul_ps(v39, v58);
      v66 = _mm_add_ps(v58, v25);
      v150 = _mm_add_ps(v52, v65);
      v67 = (__m128)*(unsigned int *)(v114 - 16);
      if ( v114 >= (unsigned __int64)v125 )
        v114 = (unsigned __int64)(v115 + 1);
      v119 = (signed __int64)(v27 + 4);
      if ( v27 + 4 >= v125 )
      {
        v119 = (signed __int64)(v115 + 2);
        v55 = v115;
      }
      v113 += 4;
      if ( v113 >= v125 )
        v113 = v55 + 3;
      v68 = v153->uMaxFrames;
      v69 = *v120;
      v70 = v120[v68];
      v71 = 2 * (signed int)v68;
      v72 = 5 * (signed int)v68;
      v73 = v120[v71];
      v74 = 3 * (signed int)v68;
      v75 = v120[v72];
      v76 = v120[v74];
      v122 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_movelh_ps(_mm_unpacklo_ps(v61, v67), _mm_unpacklo_ps((__m128)*(unsigned int *)v27, v57)),
                 v140),
               _mm_mul_ps(v122, v137));
      v77 = _mm_mul_ps(v122, vOutDecorrelationVectorB);
      v78 = 4 * (signed int)v68;
      v79 = v77;
      v80 = _mm_add_ps(v77, v63);
      v81 = _mm_add_ps(v79, v124);
      v82 = v120[v78];
      v83 = _mm_add_ps(_mm_mul_ps(v122, vOutDecorrelationVectorA), v59);
      v84 = _mm_add_ps(_mm_mul_ps(v136, v122), v64);
      v85 = _mm_add_ps(v83, _mm_movehl_ps(v83, v83));
      v86 = _mm_add_ps(v81, _mm_movehl_ps(v81, v81));
      v87 = _mm_add_ps(_mm_mul_ps(v122, vOutDecorrelationVectorC), v62);
      v88 = _mm_add_ps(v87, _mm_movehl_ps(v87, v87));
      v89 = _mm_add_ps(_mm_mul_ps(v142, v122), v150);
      v90 = _mm_add_ps(v80, _mm_movehl_ps(v80, v80));
      v91 = _mm_add_ps(v84, _mm_movehl_ps(v84, v84));
      v92 = _mm_add_ps(v89, _mm_movehl_ps(v89, v89));
      v93 = _mm_add_ps(v122, v66);
      v94 = _mm_add_ps(_mm_movehl_ps(v93, v93), v93);
      v95 = v131;
      v95.m128_f32[0] = v131.m128_f32[0] + v144;
      v131 = v95;
      v96 = v128;
      v97 = _mm_add_ps(_mm_shuffle_ps(v94, v94, 85), v94);
      v96.m128_f32[0] = v128.m128_f32[0] + v138;
      v128 = v96;
      ++v120;
      v98 = _mm_mul_ps(_mm_shuffle_ps(v97, v97, 0), v139);
      *(v120 - 1) = (float)(v69 * v131.m128_f32[0])
                  + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v85, v85, 85)) + v85.m128_f32[0]) * v96.m128_f32[0]);
      v120[v68 - 1] = (float)(v70 * v131.m128_f32[0])
                    + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v86, v86, 85)) + v86.m128_f32[0]) * v96.m128_f32[0]);
      v120[v71 - 1] = (float)(v73 * v131.m128_f32[0])
                    + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v88, v88, 85)) + v88.m128_f32[0]) * v96.m128_f32[0]);
      v120[v72 - 1] = (float)(v75 * v131.m128_f32[0])
                    + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v90, v90, 85)) + v90.m128_f32[0]) * v96.m128_f32[0]);
      v94.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v91, v91, 85)) + v91.m128_f32[0];
      v99 = _mm_add_ps(v98, v25);
      v120[v74 - 1] = (float)(v76 * v131.m128_f32[0]) + (float)(v94.m128_f32[0] * v96.m128_f32[0]);
      v96.m128_f32[0] = v82 * v131.m128_f32[0];
      v11 = (float)((float)(v73 + v75) + v82) + (float)((float)(v69 + v70) + v76);
      v100 = _mm_add_ps(v122, v98);
      v120[v78 - 1] = v96.m128_f32[0]
                    + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v92, v92, 85)) + v92.m128_f32[0]) * v128.m128_f32[0]);
      v101 = _mm_add_ps(v129, v98);
      v102 = _mm_shuffle_ps(v100, _mm_shuffle_ps(v100, v99, 15), 201);
      v103 = _mm_shuffle_ps(v101, _mm_shuffle_ps(v101, v100, 15), 201);
      v104 = _mm_shuffle_ps(v99, _mm_shuffle_ps(v99, v101, 15), 201);
      v12 = (float)((float)(v141 * v133) + v11) - v135;
      v135 = v11;
      v133 = v12;
      if ( v154 )
      {
        v105 = *v3;
        *v3 = v12;
        ++v3;
        if ( v3 == v132 )
          v3 = v130;
      }
      else
      {
        v105 = v12;
      }
      v106 = v143;
      v34 = (unsigned __int64)v118;
      v32 = v127;
      v18 = (float *)v123;
      v29 = (float *)v116;
      v36 = vOutDecorrelationVectorB;
      v37 = vOutDecorrelationVectorC;
      v38 = vOutDecorrelationVectorA;
      v23 = (float *)v117;
      v27 = (float *)v119;
      v5 += 4;
      v106.m128_f32[0] = (float)(v143.m128_f32[0] * v105) + (float)(v145 * v134);
      v107 = _mm_shuffle_ps(v106, v106, 0);
      v40 = v136;
      v39 = v147;
      v35 = vOutDecorrelationVectorD;
      v10 = v105;
      v134 = v105;
      v108 = _mm_add_ps(v107, v104);
      v19 = v149;
      *((__m128 *)v5 - 1) = v108;
      v109 = v107;
      if ( v5 >= v118 )
        v5 = v127;
      v6 += 4;
      v110 = _mm_add_ps(v107, v102);
      v20 = v151;
      *((__m128 *)v6 - 1) = _mm_add_ps(v109, v103);
      v26 = v129;
      if ( v6 >= v126 )
        v6 = v121;
      *(__m128 *)v7 = v110;
      v7 += 4;
      if ( v7 >= v125 )
        v7 = v115;
      --v155;
    }
    while ( v155 );
    v30 = v122;
    v111 = v33;
    v4 = v152;
    v21 = v111;
  }
  v4->m_fFIRLPFMem = v10;
  v4->m_fDCFwdMem = v11;
  v4->m_fDCFbkMem = v12;
  v4->m_pfPreDelayRW = v3;
  v4->m_pfDelayRead[3] = v21;
  v4->m_vIIRLPFMem[0] = v25;
  v4->m_vIIRLPFMem[1] = v26;
  v4->m_vIIRLPFMem[2] = v30;
  v4->m_pfDelayRead[5] = (float *)v112;
  v4->m_pfDelayWrite[0] = v5;
  v4->m_pfDelayRead[9] = (float *)v114;
  v4->m_pfDelayWrite[1] = v6;
  v4->m_pfDelayWrite[2] = v7;
  v4->m_pfDelayRead[0] = v8;
  v4->m_pfDelayRead[1] = v18;
  v4->m_pfDelayRead[11] = v113;
  v4->m_pfDelayRead[2] = v9;
  v4->m_pfDelayRead[4] = v22;
  v4->m_pfDelayRead[6] = v29;
  v4->m_pfDelayRead[7] = v23;
  v4->m_pfDelayRead[8] = v24;
  v4->m_pfDelayRead[10] = v27;
}vIIRLPFMem[2] = v30;
  v4->m_pfDelayRead[5] = (float *)v112;
  v4->m_pfDelayWrite[0] = v5;
  v4->m_pfDelayRead[9] = (float *)v114;
  v4->m_pfDelayWrite[1] = v6;
  v

// File Line: 1636
// RVA: 0xAC93C0
void __fastcall CAkFDNReverbFX::ProcessFivePointOne16(CAkFDNReverbFX *this, AkAudioBuffer *io_pBuffer)
{
  __m128 v2; // xmm1
  float *v3; // r12
  CAkFDNReverbFX *v4; // r11
  AkAudioBuffer *v5; // r8
  CAkFDNReverbFXParams *v6; // rdx
  float *v7; // rdi
  float v8; // xmm4_4
  float v9; // xmm3_4
  float v10; // xmm9_4
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm0
  float *v14; // rax
  __m128 v15; // xmm6
  float *v16; // rsi
  float *v17; // rbp
  float *v18; // r14
  __m128 v19; // xmm7
  __m128 v20; // xmm15
  __m128 v21; // xmm1
  float *v22; // rbx
  float *v23; // r8
  float *v24; // rcx
  __m128 v25; // xmm2
  float *v26; // rdx
  float *v27; // r15
  float *v28; // r9
  float *v29; // r10
  float *v30; // r13
  __m128 v31; // xmm0
  bool v32; // zf
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
  __m128 v53; // xmm1
  __m128 v54; // xmm9
  __m128 v55; // xmm4
  __m128 v56; // xmm3
  __m128 v57; // xmm5
  __m128 v58; // xmm0
  __m128 v59; // xmm14
  __m128 v60; // xmm6
  __m128 v61; // xmm7
  __m128 v62; // xmm0
  __m128 v63; // xmm1
  __m128 v64; // xmm8
  __m128 v65; // xmm0
  __m128 v66; // xmm2
  __m128 v67; // xmm1
  __m128 v68; // xmm4
  __m128 v69; // xmm6
  __m128 v70; // xmm3
  __m128 v71; // xmm5
  __m128 v72; // xmm7
  __m128 v73; // xmm0
  __m128 v74; // xmm2
  __m128 v75; // xmm8
  __m128 v76; // xmm0
  __m128 v77; // xmm8
  __int64 v78; // rcx
  float v79; // xmm12_4
  __int64 v80; // rdx
  __int64 v81; // r8
  float v82; // xmm13_4
  __int64 v83; // r9
  __m128 v84; // xmm8
  float v85; // xmm10_4
  float v86; // xmm11_4
  __m128 v87; // xmm3
  __m128 v88; // xmm8
  __int64 v89; // r10
  __m128 v90; // xmm2
  __m128 v91; // xmm8
  __m128 v92; // xmm2
  float v93; // xmm9_4
  __m128 v94; // xmm3
  __m128 v95; // xmm3
  __m128 v96; // xmm2
  __m128 v97; // xmm4
  __m128 v98; // xmm4
  __m128 v99; // xmm5
  __m128 v100; // xmm5
  __m128 v101; // xmm6
  __m128 v102; // xmm8
  __m128 v103; // xmm6
  __m128 v104; // xmm0
  __m128 v105; // xmm1
  __m128 v106; // xmm0
  __m128 v107; // xmm0
  __m128 v108; // xmm7
  __m128 v109; // xmm7
  float v110; // xmm13_4
  __m128 v111; // xmm5
  __m128 v112; // xmm2
  __m128 v113; // xmm1
  __m128 v114; // xmm6
  __m128 v115; // xmm8
  __m128 v116; // xmm1
  __m128 v117; // xmm7
  __m128 v118; // xmm5
  float v119; // xmm1_4
  __m128 v120; // xmm2
  __m128 v121; // xmm2
  __m128 v122; // xmm1
  __m128 v123; // xmm0
  __m128 v124; // xmm2
  __m128 v125; // xmm1
  __m128 v126; // xmm0
  float *v127; // ST80_8
  float *v128; // [rsp+0h] [rbp-388h]
  float *v129; // [rsp+8h] [rbp-380h]
  float *v130; // [rsp+10h] [rbp-378h]
  float *v131; // [rsp+18h] [rbp-370h]
  float *v132; // [rsp+20h] [rbp-368h]
  float *v133; // [rsp+28h] [rbp-360h]
  float *v134; // [rsp+30h] [rbp-358h]
  float *v135; // [rsp+38h] [rbp-350h]
  float *v136; // [rsp+40h] [rbp-348h]
  float *v137; // [rsp+48h] [rbp-340h]
  signed __int64 v138; // [rsp+50h] [rbp-338h]
  float *v139; // [rsp+58h] [rbp-330h]
  signed __int64 v140; // [rsp+60h] [rbp-328h]
  signed __int64 v141; // [rsp+68h] [rbp-320h]
  signed __int64 v142; // [rsp+70h] [rbp-318h]
  signed __int64 v143; // [rsp+78h] [rbp-310h]
  __m128 v144; // [rsp+80h] [rbp-308h]
  __m128 v145; // [rsp+90h] [rbp-2F8h]
  float *v146; // [rsp+A0h] [rbp-2E8h]
  float *v147; // [rsp+A8h] [rbp-2E0h]
  float *v148; // [rsp+B0h] [rbp-2D8h]
  float *v149; // [rsp+B8h] [rbp-2D0h]
  float *v150; // [rsp+C0h] [rbp-2C8h]
  __m128 v151; // [rsp+D0h] [rbp-2B8h]
  __m128 v152; // [rsp+E0h] [rbp-2A8h]
  float *v153; // [rsp+F0h] [rbp-298h]
  __m128 v154; // [rsp+100h] [rbp-288h]
  __m128 v155; // [rsp+110h] [rbp-278h]
  float *v156; // [rsp+120h] [rbp-268h]
  float v157; // [rsp+130h] [rbp-258h]
  float v158; // [rsp+140h] [rbp-248h]
  float v159; // [rsp+150h] [rbp-238h]
  __m128 v160; // [rsp+160h] [rbp-228h]
  __m128 v161; // [rsp+170h] [rbp-218h]
  __m128 v162; // [rsp+180h] [rbp-208h]
  __m128 v163; // [rsp+190h] [rbp-1F8h]
  __m128 v164; // [rsp+1A0h] [rbp-1E8h]
  float v165; // [rsp+1B0h] [rbp-1D8h]
  __m128 v166; // [rsp+1C0h] [rbp-1C8h]
  float v167; // [rsp+1D0h] [rbp-1B8h]
  __m128 v168; // [rsp+1E0h] [rbp-1A8h]
  __m128 v169; // [rsp+1F0h] [rbp-198h]
  __m128 v170; // [rsp+200h] [rbp-188h]
  float v171; // [rsp+210h] [rbp-178h]
  __m128 v172; // [rsp+220h] [rbp-168h]
  __m128 v173; // [rsp+230h] [rbp-158h]
  __m128 v174; // [rsp+240h] [rbp-148h]
  float v175; // [rsp+250h] [rbp-138h]
  __m128 v176; // [rsp+260h] [rbp-128h]
  __m128 v177; // [rsp+270h] [rbp-118h]
  __m128 v178; // [rsp+280h] [rbp-108h]
  __m128 v179; // [rsp+290h] [rbp-F8h]
  CAkFDNReverbFX *v180; // [rsp+390h] [rbp+8h]
  AkAudioBuffer *v181; // [rsp+398h] [rbp+10h]
  bool v182; // [rsp+3A0h] [rbp+18h]
  int v183; // [rsp+3A8h] [rbp+20h]

  v181 = io_pBuffer;
  v180 = this;
  v2 = (__m128)LODWORD(FLOAT_N2_0);
  v3 = this->m_pfPreDelayRW;
  v4 = this;
  v5 = io_pBuffer;
  v6 = this->m_pParams;
  v173 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  v7 = this->m_pfDelayWrite[0];
  LODWORD(v8) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(this->m_fFIRLPFMem),
                                     (__m128)LODWORD(this->m_fFIRLPFMem),
                                     0);
  LODWORD(v9) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(this->m_fDCFbkMem),
                                     (__m128)LODWORD(this->m_fDCFbkMem),
                                     0);
  LODWORD(v175) = (unsigned __int128)_mm_shuffle_ps(
                                       (__m128)LODWORD(this->m_fFIRLPFB1),
                                       (__m128)LODWORD(this->m_fFIRLPFB1),
                                       0);
  v155 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentWet), (__m128)LODWORD(this->m_fCurrentWet), 0);
  v158 = v8;
  LODWORD(v10) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      0);
  v157 = v9;
  LODWORD(v171) = (unsigned __int128)_mm_shuffle_ps(
                                       (__m128)LODWORD(this->m_fDCCoef),
                                       (__m128)LODWORD(this->m_fDCCoef),
                                       0);
  v159 = v10;
  v139 = (float *)v5->pData;
  v2.m128_f32[0] = -2.0 / (float)(signed int)v6->NonRTPC.uNumberOfDelays;
  v11 = v2;
  v12 = (__m128)LODWORD(v6->RTPC.fDryLevel);
  v169 = _mm_shuffle_ps(v11, v11, 0);
  v151 = _mm_shuffle_ps((__m128)LODWORD(this->m_fCurrentDry), (__m128)LODWORD(this->m_fCurrentDry), 0);
  v156 = this->m_pfPreDelayStart;
  v133 = this->m_pfDelayStart[0];
  v182 = this->m_pfPreDelayStart != 0i64;
  v129 = this->m_pfDelayEnd[0];
  v12.m128_f32[0] = (float)(v12.m128_f32[0] - this->m_fCurrentDry) * (float)(1.0 / (float)v5->uMaxFrames);
  LODWORD(v165) = (unsigned __int128)_mm_shuffle_ps(v12, v12, 0);
  v13 = (__m128)LODWORD(v6->RTPC.fWetLevel);
  v149 = this->m_pfDelayStart[2];
  v153 = this->m_pfPreDelayEnd;
  v13.m128_f32[0] = (float)(v13.m128_f32[0] - this->m_fCurrentWet) * (float)(1.0 / (float)v5->uMaxFrames);
  v137 = this->m_pfDelayStart[1];
  v150 = this->m_pfDelayEnd[2];
  LODWORD(v167) = (unsigned __int128)_mm_shuffle_ps(v13, v13, 0);
  v148 = this->m_pfDelayStart[3];
  v146 = this->m_pfDelayEnd[1];
  v147 = this->m_pfDelayEnd[3];
  v14 = this->m_pfDelayRead[5];
  v15 = this->m_vIIRLPFB0[0];
  v16 = this->m_pfDelayWrite[1];
  v17 = this->m_pfDelayWrite[2];
  v18 = this->m_pfDelayWrite[3];
  v19 = this->m_vIIRLPFA1[0];
  v20 = this->m_vIIRLPFMem[0];
  v21 = this->m_vIIRLPFMem[1];
  v22 = this->m_pfDelayRead[0];
  v23 = this->m_pfDelayRead[1];
  v24 = this->m_pfDelayRead[2];
  v25 = v4->m_vIIRLPFMem[2];
  v166 = v4->m_vIIRLPFB0[1];
  v26 = v4->m_pfDelayRead[3];
  v27 = v4->m_pfDelayRead[4];
  v28 = v4->m_pfDelayRead[6];
  v172 = v4->m_vIIRLPFB0[2];
  v177 = v15;
  v29 = v4->m_pfDelayRead[7];
  v30 = v4->m_pfDelayRead[8];
  v131 = v14;
  v168 = v4->m_vIIRLPFB0[3];
  v179 = v19;
  v135 = v4->m_pfDelayRead[9];
  v178 = v4->m_vIIRLPFA1[1];
  v128 = v4->m_pfDelayRead[10];
  v161 = v4->m_vIIRLPFA1[2];
  v130 = v4->m_pfDelayRead[11];
  v174 = v4->m_vIIRLPFA1[3];
  v31 = v4->m_vIIRLPFMem[3];
  v145 = v4->m_vIIRLPFMem[3];
  v132 = v4->m_pfDelayRead[13];
  v134 = v4->m_pfDelayRead[14];
  v136 = v4->m_pfDelayRead[15];
  LODWORD(v14) = v181->uValidFrames;
  v183 = (signed int)v14;
  v32 = (_DWORD)v14 == 0;
  v33 = v4->m_pfDelayRead[12];
  if ( !v32 )
  {
    v34 = vOutDecorrelationVectorD;
    v35 = v4->m_pfDelayRead[12];
    v36 = v133;
    v37 = vOutDecorrelationVectorC;
    v38 = vOutDecorrelationVectorB;
    v39 = vOutDecorrelationVectorA;
    v164 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorD);
    v40 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorB);
    v170 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorA);
    v176 = _mm_mul_ps(vMinusOne, vOutDecorrelationVectorC);
    v160 = v40;
    do
    {
      v41 = (__m128)*(unsigned int *)v22;
      v22 += 4;
      if ( v22 >= v129 )
        v22 = v36;
      v140 = (signed __int64)(v23 + 4);
      if ( v23 + 4 >= v129 )
      {
        v140 = (signed __int64)(v36 + 1);
        v36 = v133;
      }
      v143 = (signed __int64)(v24 + 4);
      if ( v24 + 4 >= v129 )
        v143 = (signed __int64)(v36 + 2);
      v142 = (signed __int64)(v26 + 4);
      if ( v26 + 4 >= v129 )
        v142 = (signed __int64)(v133 + 3);
      v42 = v137;
      v43 = (__m128)*(unsigned int *)v131;
      v27 += 4;
      v44 = _mm_mul_ps(v20, v19);
      v45 = _mm_mul_ps(
              _mm_movelh_ps(
                _mm_unpacklo_ps(v41, (__m128)*(unsigned int *)v23),
                _mm_unpacklo_ps((__m128)*(unsigned int *)v24, (__m128)*(unsigned int *)v26)),
              v15);
      v46 = (__m128)*((unsigned int *)v27 - 4);
      v20 = _mm_add_ps(v45, v44);
      if ( v27 >= v146 )
        v27 = v137;
      v131 += 4;
      v47 = _mm_mul_ps(v20, v34);
      v48 = _mm_mul_ps(v20, v39);
      v49 = _mm_mul_ps(v20, v38);
      v50 = _mm_mul_ps(v20, vOutDecorrelationVectorF);
      v51 = _mm_mul_ps(v20, v37);
      if ( v131 >= v146 )
        v131 = v137 + 1;
      v141 = (signed __int64)(v28 + 4);
      if ( v28 + 4 >= v146 )
      {
        v141 = (signed __int64)(v137 + 2);
        v42 = v137;
      }
      v138 = (signed __int64)(v29 + 4);
      if ( v29 + 4 >= v146 )
        v138 = (signed __int64)(v42 + 3);
      v52 = (__m128)*(unsigned int *)v135;
      v30 += 4;
      v53 = _mm_add_ps(
              _mm_mul_ps(
                _mm_movelh_ps(
                  _mm_unpacklo_ps(v46, v43),
                  _mm_unpacklo_ps((__m128)*(unsigned int *)v28, (__m128)*(unsigned int *)v29)),
                v166),
              _mm_mul_ps(v21, v178));
      v154 = v53;
      v54 = _mm_add_ps(v53, v20);
      v55 = _mm_add_ps(v48, _mm_mul_ps(v53, v39));
      v56 = _mm_add_ps(v49, _mm_mul_ps(v53, v38));
      v57 = _mm_add_ps(v51, _mm_mul_ps(v53, v37));
      v58 = v40;
      v59 = (__m128)*(unsigned int *)v130;
      v60 = _mm_add_ps(v49, _mm_mul_ps(v58, v53));
      v61 = _mm_add_ps(v47, _mm_mul_ps(v53, vOutDecorrelationVectorE));
      v62 = _mm_mul_ps(v164, v53);
      v63 = (__m128)*((unsigned int *)v30 - 4);
      if ( v30 >= v150 )
        v30 = v149;
      v135 += 4;
      v64 = _mm_add_ps(v50, v62);
      v65 = (__m128)*(unsigned int *)v128;
      if ( v135 >= v150 )
        v135 = v149 + 1;
      v128 += 4;
      if ( v128 >= v150 )
        v128 = v149 + 2;
      v130 += 4;
      if ( v130 >= v150 )
        v130 = v149 + 3;
      v35 += 4;
      v66 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v63, v52), _mm_unpacklo_ps(v65, v59)), v172),
              _mm_mul_ps(v25, v161));
      v152 = v66;
      v67 = _mm_mul_ps(v66, v38);
      v163 = _mm_add_ps(v54, v66);
      v68 = _mm_add_ps(v55, _mm_mul_ps(v66, v39));
      v69 = _mm_add_ps(v60, v67);
      v144 = _mm_add_ps(v56, v67);
      v70 = (__m128)*(unsigned int *)v132;
      v71 = _mm_add_ps(v57, _mm_mul_ps(v66, v37));
      v72 = _mm_add_ps(v61, _mm_mul_ps(v160, v66));
      v73 = _mm_mul_ps(v176, v66);
      v74 = (__m128)*((unsigned int *)v35 - 4);
      if ( v35 >= v147 )
        v35 = v148;
      v132 += 4;
      v75 = _mm_add_ps(v64, v73);
      v76 = (__m128)*(unsigned int *)v134;
      v162 = v75;
      v77 = (__m128)*(unsigned int *)v136;
      if ( v132 >= v147 )
        v132 = v148 + 1;
      v134 += 4;
      if ( v134 >= v147 )
        v134 = v148 + 2;
      v136 += 4;
      if ( v136 >= v147 )
        v136 = v148 + 3;
      v78 = v181->uMaxFrames;
      v79 = v139[v78];
      v80 = 2 * (signed int)v78;
      v81 = 5 * (signed int)v78;
      v82 = v139[v80];
      v83 = 3 * (signed int)v78;
      v84 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v74, v70), _mm_unpacklo_ps(v76, v77)), v168),
              _mm_mul_ps(v145, v174));
      v85 = v139[v81];
      v86 = v139[v83];
      v145 = v84;
      v87 = v84;
      v88 = _mm_mul_ps(v84, vOutDecorrelationVectorB);
      v89 = 4 * (signed int)v78;
      v90 = v88;
      v91 = _mm_add_ps(v88, v72);
      v92 = _mm_add_ps(v90, v144);
      v93 = v139[v89];
      v94 = _mm_add_ps(_mm_mul_ps(v87, vOutDecorrelationVectorA), v68);
      v95 = _mm_add_ps(v94, _mm_movehl_ps(v94, v94));
      v96 = _mm_add_ps(v92, _mm_movehl_ps(v92, v92));
      v97 = _mm_add_ps(_mm_mul_ps(v145, vOutDecorrelationVectorC), v71);
      v98 = _mm_add_ps(v97, _mm_movehl_ps(v97, v97));
      v99 = _mm_add_ps(_mm_mul_ps(v160, v145), v69);
      v100 = _mm_add_ps(v99, _mm_movehl_ps(v99, v99));
      v101 = _mm_add_ps(_mm_mul_ps(v170, v145), v162);
      v102 = _mm_add_ps(v91, _mm_movehl_ps(v91, v91));
      v103 = _mm_add_ps(v101, _mm_movehl_ps(v101, v101));
      v104 = _mm_add_ps(v145, v163);
      v105 = _mm_add_ps(_mm_movehl_ps(v104, v104), v104);
      v106 = v151;
      v106.m128_f32[0] = v151.m128_f32[0] + v165;
      v151 = v106;
      v107 = v155;
      v108 = _mm_add_ps(_mm_shuffle_ps(v105, v105, 85), v105);
      v107.m128_f32[0] = v155.m128_f32[0] + v167;
      v155 = v107;
      v105.m128_f32[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v95, v95, 85)) + v95.m128_f32[0]) * v107.m128_f32[0];
      v107.m128_f32[0] = *v139;
      v109 = _mm_mul_ps(_mm_shuffle_ps(v108, v108, 0), v169);
      ++v139;
      *(v139 - 1) = (float)(v107.m128_f32[0] * v151.m128_f32[0]) + v105.m128_f32[0];
      v139[v78 - 1] = (float)(v79 * v151.m128_f32[0])
                    + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v96, v96, 85)) + v96.m128_f32[0]) * v155.m128_f32[0]);
      v139[v80 - 1] = (float)(v82 * v151.m128_f32[0])
                    + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v98, v98, 85)) + v98.m128_f32[0]) * v155.m128_f32[0]);
      v110 = (float)((float)(v82 + v85) + v93) + (float)((float)(v107.m128_f32[0] + v79) + v86);
      v107.m128_f32[0] = (float)(v85 * v151.m128_f32[0])
                       + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v100, v100, 85)) + v100.m128_f32[0])
                               * v155.m128_f32[0]);
      v111 = _mm_add_ps(v109, v20);
      v139[v81 - 1] = v107.m128_f32[0];
      v139[v83 - 1] = (float)(v86 * v151.m128_f32[0])
                    + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v102, v102, 85)) + v102.m128_f32[0]) * v155.m128_f32[0]);
      v112 = _mm_add_ps(v152, v109);
      v139[v89 - 1] = (float)(v93 * v151.m128_f32[0])
                    + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v103, v103, 85)) + v103.m128_f32[0]) * v155.m128_f32[0]);
      v113 = _mm_add_ps(v145, v109);
      v114 = _mm_shuffle_ps(v113, _mm_shuffle_ps(v113, v111, 15), 201);
      v115 = _mm_shuffle_ps(v112, _mm_shuffle_ps(v112, v113, 15), 201);
      v116 = _mm_add_ps(v154, v109);
      v117 = _mm_shuffle_ps(v116, _mm_shuffle_ps(v116, v112, 15), 201);
      v118 = _mm_shuffle_ps(v111, _mm_shuffle_ps(v111, v116, 15), 201);
      v9 = (float)((float)(v171 * v157) + v110) - v159;
      v10 = v110;
      v159 = v110;
      v157 = v9;
      if ( v182 )
      {
        v119 = *v3;
        *v3 = v9;
        ++v3;
        if ( v3 == v153 )
          v3 = v156;
      }
      else
      {
        v119 = v9;
      }
      v120 = v173;
      v36 = v133;
      v24 = (float *)v143;
      v26 = (float *)v142;
      v23 = (float *)v140;
      v37 = vOutDecorrelationVectorC;
      v38 = vOutDecorrelationVectorB;
      v39 = vOutDecorrelationVectorA;
      v28 = (float *)v141;
      v29 = (float *)v138;
      v7 += 4;
      v120.m128_f32[0] = (float)(v173.m128_f32[0] * v119) + (float)(v175 * v158);
      v121 = _mm_shuffle_ps(v120, v120, 0);
      v40 = v160;
      v8 = v119;
      *((__m128 *)v7 - 1) = _mm_add_ps(v121, v118);
      if ( v7 >= v129 )
        v7 = v133;
      v16 += 4;
      v158 = v119;
      v122 = v121;
      v123 = v121;
      v124 = _mm_add_ps(v121, v114);
      v125 = _mm_add_ps(v122, v117);
      v126 = _mm_add_ps(v123, v115);
      v34 = vOutDecorrelationVectorD;
      v15 = v177;
      v19 = v179;
      *((__m128 *)v16 - 1) = v125;
      v21 = v154;
      *(__m128 *)v17 = v126;
      if ( v16 >= v146 )
        v16 = v137;
      v17 += 4;
      if ( v17 >= v150 )
        v17 = v149;
      *(__m128 *)v18 = v124;
      v25 = v152;
      v18 += 4;
      if ( v18 >= v147 )
        v18 = v148;
      --v183;
    }
    while ( v183 );
    v31 = v145;
    v127 = v35;
    v4 = v180;
    v33 = v127;
  }
  v4->m_fFIRLPFMem = v8;
  v4->m_fDCFwdMem = v10;
  v4->m_fDCFbkMem = v9;
  v4->m_pfPreDelayRW = v3;
  v4->m_pfDelayRead[2] = v24;
  v4->m_vIIRLPFMem[0] = v20;
  v4->m_vIIRLPFMem[1] = v21;
  v4->m_vIIRLPFMem[2] = v25;
  v4->m_pfDelayRead[12] = v33;
  v4->m_pfDelayRead[5] = v131;
  v4->m_vIIRLPFMem[3] = v31;
  v4->m_pfDelayRead[13] = v132;
  v4->m_pfDelayRead[9] = v135;
  v4->m_pfDelayRead[14] = v134;
  v4->m_pfDelayRead[10] = v128;
  v4->m_pfDelayRead[11] = v130;
  v4->m_pfDelayWrite[0] = v7;
  v4->m_pfDelayWrite[1] = v16;
  v4->m_pfDelayWrite[2] = v17;
  v4->m_pfDelayWrite[3] = v18;
  v4->m_pfDelayRead[0] = v22;
  v4->m_pfDelayRead[1] = v23;
  v4->m_pfDelayRead[3] = v26;
  v4->m_pfDelayRead[4] = v27;
  v4->m_pfDelayRead[6] = v28;
  v4->m_pfDelayRead[7] = v29;
  v4->m_pfDelayRead[8] = v30;
  v4->m_pfDelayRead[15] = v136;
}

// File Line: 1697
// RVA: 0xACA0E0
void __usercall CAkFDNReverbFX::ProcessN4(CAkFDNReverbFX *this@<rcx>, AkAudioBuffer *io_pBuffer@<rdx>, __m128 a3@<xmm11>)
{
  float *v3; // rbx
  CAkFDNReverbFX *v4; // r13
  AkAudioBuffer *v5; // r10
  CAkFDNReverbFXParams *v6; // rdx
  unsigned int *v7; // r11
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
  unsigned int v21; // er9
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
  int v37; // er10
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
  float *v59; // ST00_8
  float *v60; // [rsp+8h] [rbp-220h]
  float *v61; // [rsp+10h] [rbp-218h]
  __m128 v62; // [rsp+20h] [rbp-208h]
  __m128 v63; // [rsp+30h] [rbp-1F8h]
  __int128 v64[8]; // [rsp+40h] [rbp-1E8h]
  __int128 v65; // [rsp+C0h] [rbp-168h]
  char v66; // [rsp+D0h] [rbp-158h]
  CAkFDNReverbFX *v67; // [rsp+230h] [rbp+8h]
  AkAudioBuffer *v68; // [rsp+238h] [rbp+10h]
  bool v69; // [rsp+240h] [rbp+18h]
  int v70; // [rsp+248h] [rbp+20h]

  v68 = io_pBuffer;
  v67 = this;
  v3 = this->m_pfPreDelayRW;
  v4 = this;
  v5 = io_pBuffer;
  v6 = this->m_pParams;
  v7 = (unsigned int *)v5->pData;
  v8 = this->m_pfDelayStart[0];
  LODWORD(v9) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(this->m_fDCFbkMem),
                                     (__m128)LODWORD(this->m_fDCFbkMem),
                                     0);
  v10 = this->m_vIIRLPFMem[0];
  LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fCurrentDry),
                                      (__m128)LODWORD(this->m_fCurrentDry),
                                      0);
  LODWORD(v12) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fCurrentWet),
                                      (__m128)LODWORD(this->m_fCurrentWet),
                                      0);
  LODWORD(v13) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      0);
  v14 = this->m_pfDelayEnd[0];
  v15 = this->m_pfDelayWrite[0];
  v16 = this->m_pfDelayRead[0];
  LODWORD(v17) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      0);
  LODWORD(v18) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      0);
  v19 = this->m_pfDelayRead[2];
  v20 = this->m_pfDelayRead[3];
  v21 = this->m_uNumProcessedChannels;
  v22 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v23) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      0);
  v61 = this->m_pfPreDelayStart;
  v24 = this->m_pfDelayRead[1];
  v69 = this->m_pfPreDelayStart != 0i64;
  v25 = 1.0 / (float)v5->uMaxFrames;
  a3.m128_f32[0] = -2.0 / (float)(signed int)v6->NonRTPC.uNumberOfDelays;
  v60 = this->m_pfPreDelayEnd;
  v26 = _mm_shuffle_ps(a3, a3, 0);
  v70 = v5->uValidFrames;
  v27 = (float)(v6->RTPC.fWetLevel - this->m_fCurrentWet) * v25;
  v28 = (float)(v6->RTPC.fDryLevel - this->m_fCurrentDry) * v25;
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
      while ( v34 < v21 );
      v37 = v5->uMaxFrames;
      v38 = 0;
      v39 = 0i64;
      do
      {
        v40 = v7[v39];
        v41 = v38++;
        v41 *= 2i64;
        v39 = (unsigned int)(v37 + v39);
        v42 = *(__m128 *)((char *)v64 + 8 * v41);
        *(__int128 *)((char *)&v65 + 8 * v41) = v40;
        v43 = _mm_add_ps(v42, _mm_movehl_ps(v42, v42));
        *(__int128 *)((char *)v64 + 8 * v41) = (__int128)_mm_add_ps(_mm_shuffle_ps(v43, v43, 85), v43);
      }
      while ( v38 < v21 );
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
        v7[v45] = v50;
        v45 = (unsigned int)(v37 + v45);
        *(__int128 *)((char *)v64 + 8 * v49) = v50;
      }
      while ( v44 < v21 );
      v51 = *(float *)&v65;
      ++v7;
      v52 = _mm_add_ps(_mm_mul_ps(v48, v26), v10);
      v53 = _mm_shuffle_ps(v52, _mm_shuffle_ps(v52, v52, 15), 201);
      if ( v21 > 1 )
      {
        v54 = (float *)&v66;
        v55 = v21 - 1;
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
      if ( v69 )
      {
        v56 = *v3;
        *v3 = v9;
        ++v3;
        if ( v3 == v60 )
          v3 = v61;
      }
      else
      {
        v56 = v9;
      }
      v5 = v68;
      v15 += 4;
      v57 = v22;
      v58 = v23 * v18;
      v18 = v56;
      v57.m128_f32[0] = (float)(v22.m128_f32[0] * v56) + v58;
      *((__m128 *)v15 - 1) = _mm_add_ps(_mm_shuffle_ps(v57, v57, 0), v53);
      if ( v15 >= v14 )
        v15 = v8;
      --v70;
    }
    while ( v70 );
    v59 = v29;
    v4 = v67;
    v24 = v59;
  }
  v4->m_fFIRLPFMem = v18;
  v4->m_fDCFwdMem = v13;
  v4->m_fDCFbkMem = v9;
  v4->m_pfPreDelayRW = v3;
  v4->m_pfDelayWrite[0] = v15;
  v4->m_pfDelayRead[0] = v16;
  v4->m_pfDelayRead[1] = v24;
  v4->m_pfDelayRead[2] = v19;
  v4->m_pfDelayRead[3] = v20;
  v4->m_vIIRLPFMem[0] = v10;
}

// File Line: 1732
// RVA: 0xACA560
void __usercall CAkFDNReverbFX::ProcessN8(CAkFDNReverbFX *this@<rcx>, AkAudioBuffer *io_pBuffer@<rdx>, __m128 a3@<xmm4>, __m128 a4@<xmm15>)
{
  float *v4; // rdi
  CAkFDNReverbFX *v5; // rbx
  AkAudioBuffer *v6; // r8
  CAkFDNReverbFXParams *v7; // rdx
  unsigned int *v8; // r11
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
  signed int v24; // eax
  float *v25; // r8
  float *v26; // r13
  float v27; // xmm2_4
  float *v28; // rax
  __m128 v29; // xmm0
  __m128 v30; // xmm15
  float v31; // xmm4_4
  float *v32; // rcx
  float *v33; // rdx
  __m128 v34; // xmm5
  __m128 v35; // xmm6
  unsigned int v36; // er10
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
  int v52; // er9
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
  signed __int64 v78; // rdx
  __m128 v79; // xmm1
  __m128 v80; // xmm0
  __m128 v81; // xmm1
  signed __int64 v82; // rdx
  bool v83; // zf
  signed __int64 v84; // [rsp+0h] [rbp-298h]
  float *v85; // [rsp+8h] [rbp-290h]
  float *v86; // [rsp+10h] [rbp-288h]
  __m128 *v87; // [rsp+18h] [rbp-280h]
  float *v88; // [rsp+20h] [rbp-278h]
  float *v89; // [rsp+28h] [rbp-270h]
  float *v90; // [rsp+30h] [rbp-268h]
  float *v91; // [rsp+38h] [rbp-260h]
  unsigned __int64 v92; // [rsp+40h] [rbp-258h]
  float *v93; // [rsp+48h] [rbp-250h]
  __m128 v94; // [rsp+50h] [rbp-248h]
  float v95; // [rsp+60h] [rbp-238h]
  __m128 v96; // [rsp+70h] [rbp-228h]
  float v97; // [rsp+80h] [rbp-218h]
  __m128 v98; // [rsp+90h] [rbp-208h]
  __m128 v99; // [rsp+A0h] [rbp-1F8h]
  __int128 v100[8]; // [rsp+B0h] [rbp-1E8h]
  __int128 v101; // [rsp+130h] [rbp-168h]
  char v102; // [rsp+140h] [rbp-158h]
  CAkFDNReverbFX *v103; // [rsp+2A0h] [rbp+8h]
  AkAudioBuffer *v104; // [rsp+2A8h] [rbp+10h]
  bool v105; // [rsp+2B0h] [rbp+18h]
  int v106; // [rsp+2B8h] [rbp+20h]

  v104 = io_pBuffer;
  v103 = this;
  v4 = this->m_pfPreDelayRW;
  v5 = this;
  v6 = io_pBuffer;
  v7 = this->m_pParams;
  v8 = (unsigned int *)v6->pData;
  v9 = this->m_pfDelayEnd[1];
  v10 = this->m_pfDelayRead[5];
  LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fCurrentDry),
                                      (__m128)LODWORD(this->m_fCurrentDry),
                                      0);
  LODWORD(v12) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      0);
  LODWORD(v13) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fCurrentWet),
                                      (__m128)LODWORD(this->m_fCurrentWet),
                                      0);
  LODWORD(v14) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      0);
  LODWORD(v15) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      0);
  v16 = this->m_pfDelayRead[0];
  v17 = this->m_pfDelayRead[2];
  v18 = this->m_pfDelayRead[3];
  v19 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v20) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      (__m128)LODWORD(this->m_fFIRLPFB1),
                                      0);
  LODWORD(v21) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      0);
  v22 = this->m_pfDelayRead[4];
  v23 = this->m_pfDelayRead[6];
  v24 = v6->uMaxFrames;
  v25 = this->m_pfDelayStart[1];
  v26 = this->m_pfDelayRead[7];
  v93 = this->m_pfDelayStart[1];
  v88 = this->m_pfDelayEnd[1];
  v27 = 1.0 / (float)v24;
  v90 = this->m_pfPreDelayStart;
  v28 = this->m_pfDelayStart[0];
  v29 = (__m128)LODWORD(v7->RTPC.fWetLevel);
  a4.m128_f32[0] = -2.0 / (float)(signed int)v7->NonRTPC.uNumberOfDelays;
  v105 = this->m_pfPreDelayStart != 0i64;
  v30 = _mm_shuffle_ps(a4, a4, 0);
  v29.m128_f32[0] = (float)(v29.m128_f32[0] - this->m_fCurrentWet) * v27;
  v87 = (__m128 *)this->m_pfDelayWrite[0];
  v91 = this->m_pfPreDelayEnd;
  a3.m128_f32[0] = (float)(v7->RTPC.fDryLevel - this->m_fCurrentDry) * v27;
  LODWORD(v31) = (unsigned __int128)_mm_shuffle_ps(a3, a3, 0);
  v32 = this->m_pfDelayEnd[0];
  v85 = v5->m_pfDelayWrite[1];
  v33 = v5->m_pfDelayRead[1];
  v97 = v31;
  LODWORD(v95) = (unsigned __int128)_mm_shuffle_ps(v29, v29, 0);
  v89 = v28;
  v92 = (unsigned __int64)v32;
  v86 = v10;
  v34 = v5->m_vIIRLPFMem[0];
  v35 = v5->m_vIIRLPFMem[1];
  v96 = v5->m_vIIRLPFB0[0];
  v106 = v104->uValidFrames;
  v36 = v5->m_uNumProcessedChannels;
  v99 = v5->m_vIIRLPFB0[1];
  v94 = v5->m_vIIRLPFA1[0];
  v98 = v5->m_vIIRLPFA1[1];
  if ( v104->uValidFrames )
  {
    v37 = v5->m_pfDelayRead[1];
    do
    {
      v38 = (__m128)*(unsigned int *)v16;
      v39 = (__m128)*(unsigned int *)v17;
      v16 += 4;
      if ( v16 >= v32 )
        v16 = v28;
      v84 = (signed __int64)(v37 + 4);
      v40 = (__m128)*(unsigned int *)v18;
      if ( v37 + 4 >= v32 )
        v84 = (signed __int64)(v28 + 1);
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
                v96),
              _mm_mul_ps(v34, v94));
      do
      {
        v42 = v41;
        v43 = v41++;
        v100[v43] = (__int128)_mm_mul_ps(vOutDecorrelationVector[v42][0], v34);
      }
      while ( v41 < v36 );
      v44 = (__m128)*(unsigned int *)v22;
      v45 = (__m128)*(unsigned int *)v23;
      v37 = (float *)v84;
      v22 += 4;
      v46 = (__m128)*(unsigned int *)v86;
      v47 = (__m128)*(unsigned int *)v26;
      if ( v22 >= v9 )
        v22 = v25;
      v86 += 4;
      if ( v86 >= v9 )
        v86 = v25 + 1;
      v23 += 4;
      if ( v23 >= v9 )
        v23 = v25 + 2;
      v26 += 4;
      if ( v26 >= v9 )
        v26 = v25 + 3;
      v48 = 0;
      v35 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v44, v46), _mm_unpacklo_ps(v45, v47)), v99),
              _mm_mul_ps(v35, v98));
      do
      {
        v49 = v48;
        v50 = v48++;
        v100[v50] = (__int128)_mm_add_ps(_mm_mul_ps(vOutDecorrelationVector[v49][1], v35), (__m128)v100[v50]);
      }
      while ( v48 < v36 );
      v51 = 0;
      v52 = v104->uMaxFrames;
      v53 = 0i64;
      v54 = _mm_add_ps(v35, v34);
      do
      {
        v55 = v8[v53];
        v56 = v51++;
        v56 *= 2i64;
        v53 = (unsigned int)(v52 + v53);
        v57 = *(__m128 *)((char *)v100 + 8 * v56);
        *(__int128 *)((char *)&v101 + 8 * v56) = v55;
        v58 = _mm_add_ps(v57, _mm_movehl_ps(v57, v57));
        *(__int128 *)((char *)v100 + 8 * v56) = (__int128)_mm_add_ps(_mm_shuffle_ps(v58, v58, 85), v58);
      }
      while ( v51 < v36 );
      v13 = v13 + v95;
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
        v65 = *(__int128 *)((char *)&v101 + 8 * v64);
        *(float *)&v65 = (float)(*(float *)&v65 * v11)
                       + (float)(COERCE_FLOAT(*(__int128 *)((char *)v100 + 8 * v64)) * v13);
        v8[v60] = v65;
        v60 = (unsigned int)(v52 + v60);
        *(__int128 *)((char *)v100 + 8 * v64) = v65;
      }
      while ( v59 < v36 );
      v66 = _mm_mul_ps(v63, v30);
      ++v8;
      v67 = _mm_add_ps(v35, v66);
      v68 = _mm_add_ps(v66, v34);
      v69 = _mm_shuffle_ps(v67, _mm_shuffle_ps(v67, v68, 15), 201);
      v70 = _mm_shuffle_ps(v68, v67, 15);
      v71 = *(float *)&v101;
      v72 = _mm_shuffle_ps(v68, v70, 201);
      if ( v36 > 1 )
      {
        v73 = (float *)&v102;
        v74 = v36 - 1;
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
      if ( v105 )
      {
        v75 = *v4;
        *v4 = v12;
        ++v4;
        if ( v4 == v91 )
          v4 = v90;
      }
      else
      {
        v75 = v12;
      }
      v32 = (float *)v92;
      v76 = v19;
      v77 = v20 * v14;
      v14 = v75;
      v9 = v88;
      v25 = v93;
      v78 = (signed __int64)&v87[1];
      v76.m128_f32[0] = (float)(v19.m128_f32[0] * v75) + v77;
      v79 = _mm_shuffle_ps(v76, v76, 0);
      v80 = v79;
      v81 = _mm_add_ps(v79, v69);
      v31 = v97;
      *v87 = _mm_add_ps(v80, v72);
      *(__m128 *)v85 = v81;
      v28 = v89;
      if ( (unsigned __int64)&v87[1] >= v92 )
        v78 = (signed __int64)v89;
      v87 = (__m128 *)v78;
      v82 = (signed __int64)(v85 + 4);
      if ( v85 + 4 >= v88 )
        v82 = (signed __int64)v93;
      v83 = v106-- == 1;
      v85 = (float *)v82;
    }
    while ( !v83 );
    v5 = v103;
    v33 = (float *)v84;
  }
  v5->m_fFIRLPFMem = v14;
  v5->m_fDCFwdMem = v15;
  v5->m_fDCFbkMem = v12;
  v5->m_pfPreDelayRW = v4;
  v5->m_pfDelayWrite[0] = (float *)v87;
  v5->m_pfDelayRead[0] = v16;
  v5->m_pfDelayRead[1] = v33;
  v5->m_vIIRLPFMem[1] = v35;
  v5->m_vIIRLPFMem[0] = v34;
  v5->m_pfDelayWrite[1] = v85;
  v5->m_pfDelayRead[2] = v17;
  v5->m_pfDelayRead[3] = v18;
  v5->m_pfDelayRead[4] = v22;
  v5->m_pfDelayRead[6] = v23;
  v5->m_pfDelayRead[5] = v86;
  v5->m_pfDelayRead[7] = v26;
}

// File Line: 1777
// RVA: 0xACABE0
void __usercall CAkFDNReverbFX::ProcessN12(CAkFDNReverbFX *this@<rcx>, AkAudioBuffer *io_pBuffer@<rdx>, __m128 a3@<xmm5>)
{
  __m128 v3; // xmm1
  float *v4; // rdi
  CAkFDNReverbFX *v5; // r11
  AkAudioBuffer *v6; // r10
  CAkFDNReverbFXParams *v7; // rdx
  float *v8; // r9
  unsigned int *v9; // rbx
  float v10; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm9_4
  float v13; // xmm12_4
  float v14; // xmm13_4
  float v15; // xmm14_4
  __m128 v16; // xmm0
  float v17; // xmm2_4
  __m128 v18; // xmm0
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
  bool v34; // zf
  unsigned int v35; // er10
  float *v36; // rax
  __m128 v37; // xmm1
  __m128 v38; // xmm0
  __m128 v39; // xmm3
  __m128 v40; // xmm2
  unsigned int v41; // edx
  __int64 v42; // rax
  __int64 v43; // rcx
  __m128 v44; // xmm1
  __m128 v45; // xmm0
  __m128 v46; // xmm3
  float *v47; // r11
  __m128 v48; // xmm2
  unsigned int v49; // edx
  __int64 v50; // rax
  __int64 v51; // rcx
  __m128 v52; // xmm0
  __m128 v53; // xmm1
  __m128 v54; // xmm2
  __m128 v55; // xmm4
  signed __int64 v56; // rcx
  unsigned int v57; // edx
  __int64 v58; // rax
  __int64 v59; // rcx
  unsigned int v60; // edx
  __m128 v61; // xmm4
  int v62; // er9
  __int64 v63; // r8
  __int128 v64; // xmm0
  __int64 v65; // rcx
  __m128 v66; // xmm1
  __m128 v67; // xmm1
  unsigned int v68; // ecx
  __int64 v69; // rdx
  __m128 v70; // xmm0
  __m128 v71; // xmm3
  __m128 v72; // xmm3
  __int64 v73; // rax
  __int128 v74; // xmm1
  __m128 v75; // xmm3
  __m128 v76; // xmm2
  __m128 v77; // xmm1
  __m128 v78; // xmm4
  __m128 v79; // xmm5
  __m128 v80; // xmm3
  __m128 v81; // xmm0
  float v82; // xmm1_4
  __m128 v83; // xmm4
  float *v84; // rcx
  __int64 v85; // rdx
  float v86; // xmm1_4
  __m128 v87; // xmm2
  signed __int64 v88; // rax
  float v89; // xmm0_4
  __m128 v90; // xmm1
  __m128 v91; // xmm2
  __m128 v92; // xmm0
  signed __int64 v93; // r8
  signed __int64 v94; // r8
  float *v95; // [rsp+0h] [rbp-318h]
  float *v96; // [rsp+8h] [rbp-310h]
  float *v97; // [rsp+10h] [rbp-308h]
  float *v98; // [rsp+18h] [rbp-300h]
  float *v99; // [rsp+20h] [rbp-2F8h]
  float *v100; // [rsp+28h] [rbp-2F0h]
  float *v101; // [rsp+30h] [rbp-2E8h]
  signed __int64 v102; // [rsp+38h] [rbp-2E0h]
  __m128 *v103; // [rsp+40h] [rbp-2D8h]
  unsigned __int64 v104; // [rsp+48h] [rbp-2D0h]
  unsigned __int64 v105; // [rsp+50h] [rbp-2C8h]
  float *v106; // [rsp+58h] [rbp-2C0h]
  float *v107; // [rsp+60h] [rbp-2B8h]
  float *v108; // [rsp+68h] [rbp-2B0h]
  float *v109; // [rsp+70h] [rbp-2A8h]
  float *v110; // [rsp+78h] [rbp-2A0h]
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
  __int128 v122[8]; // [rsp+130h] [rbp-1E8h]
  __int128 v123; // [rsp+1B0h] [rbp-168h]
  char v124; // [rsp+1C0h] [rbp-158h]
  CAkFDNReverbFX *v125; // [rsp+320h] [rbp+8h]
  AkAudioBuffer *v126; // [rsp+328h] [rbp+10h]
  bool v127; // [rsp+330h] [rbp+18h]
  int v128; // [rsp+338h] [rbp+20h]

  v126 = io_pBuffer;
  v125 = this;
  v3 = (__m128)LODWORD(FLOAT_N2_0);
  v4 = this->m_pfPreDelayRW;
  v5 = this;
  v6 = io_pBuffer;
  v7 = this->m_pParams;
  v8 = this->m_pfDelayStart[1];
  v9 = (unsigned int *)v6->pData;
  v111 = this->m_pfDelayStart[1];
  LODWORD(v10) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fCurrentDry),
                                      (__m128)LODWORD(this->m_fCurrentDry),
                                      0);
  LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fCurrentWet),
                                      (__m128)LODWORD(this->m_fCurrentWet),
                                      0);
  LODWORD(v12) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      0);
  v113 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v13) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      0);
  LODWORD(v14) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      0);
  LODWORD(v115) = (unsigned __int128)_mm_shuffle_ps(
                                       (__m128)LODWORD(this->m_fFIRLPFB1),
                                       (__m128)LODWORD(this->m_fFIRLPFB1),
                                       0);
  LODWORD(v15) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      0);
  v3.m128_f32[0] = -2.0 / (float)(signed int)v7->NonRTPC.uNumberOfDelays;
  v16 = v3;
  v3.m128_f32[0] = v7->RTPC.fDryLevel - this->m_fCurrentDry;
  v118 = _mm_shuffle_ps(v16, v16, 0);
  v108 = this->m_pfPreDelayStart;
  v107 = this->m_pfDelayStart[2];
  v127 = this->m_pfPreDelayStart != 0i64;
  v17 = 1.0 / (float)v6->uMaxFrames;
  v18 = (__m128)LODWORD(v7->RTPC.fWetLevel);
  v106 = this->m_pfDelayEnd[1];
  v18.m128_f32[0] = (float)(v18.m128_f32[0] - this->m_fCurrentWet) * v17;
  v110 = this->m_pfPreDelayEnd;
  v19 = this->m_pfDelayStart[0];
  a3.m128_f32[0] = v3.m128_f32[0] * v17;
  LODWORD(v20) = (unsigned __int128)_mm_shuffle_ps(a3, a3, 0);
  v101 = v5->m_pfDelayWrite[0];
  v104 = (unsigned __int64)v5->m_pfDelayEnd[0];
  v119 = v20;
  LODWORD(v112) = (unsigned __int128)_mm_shuffle_ps(v18, v18, 0);
  v103 = (__m128 *)v5->m_pfDelayWrite[1];
  v109 = v19;
  v105 = (unsigned __int64)v5->m_pfDelayEnd[2];
  v98 = v5->m_pfDelayWrite[2];
  LODWORD(v6) = v6->uValidFrames;
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
  v117 = v5->m_vIIRLPFA1[0];
  v96 = v5->m_pfDelayRead[1];
  v128 = (signed int)v6;
  v114 = v5->m_vIIRLPFA1[1];
  v34 = (_DWORD)v6 == 0;
  v35 = v5->m_uNumProcessedChannels;
  v97 = v5->m_pfDelayRead[5];
  v116 = v5->m_vIIRLPFA1[2];
  v100 = v5->m_pfDelayRead[8];
  v99 = v5->m_pfDelayRead[9];
  v36 = v5->m_pfDelayRead[10];
  v95 = v5->m_pfDelayRead[10];
  if ( !v34 )
  {
    do
    {
      v37 = (__m128)*(unsigned int *)v23;
      v38 = (__m128)*(unsigned int *)v27;
      v39 = (__m128)*(unsigned int *)v28;
      v23 += 4;
      if ( (unsigned __int64)v23 >= v104 )
        v23 = v19;
      v40 = (__m128)*(unsigned int *)v96;
      v96 += 4;
      if ( (unsigned __int64)v96 >= v104 )
        v96 = v19 + 1;
      v27 += 4;
      if ( (unsigned __int64)v27 >= v104 )
        v27 = v19 + 2;
      v28 += 4;
      if ( (unsigned __int64)v28 >= v104 )
        v28 = v19 + 3;
      v41 = 0;
      v25 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v37, v40), _mm_unpacklo_ps(v38, v39)), v24),
              _mm_mul_ps(v25, v22));
      do
      {
        v42 = v41;
        v43 = v41++;
        v122[v43] = (__int128)_mm_mul_ps(vOutDecorrelationVector[v42][0], v25);
      }
      while ( v41 < v35 );
      v44 = (__m128)*(unsigned int *)v29;
      v45 = (__m128)*(unsigned int *)v31;
      v46 = (__m128)*(unsigned int *)v32;
      v47 = v95;
      v29 += 4;
      v48 = (__m128)*(unsigned int *)v97;
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
      v49 = 0;
      v26 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v44, v48), _mm_unpacklo_ps(v45, v46)), v120),
              _mm_mul_ps(v26, v114));
      do
      {
        v50 = v49;
        v51 = v49++;
        v122[v51] = (__int128)_mm_add_ps(_mm_mul_ps(vOutDecorrelationVector[v50][1], v26), (__m128)v122[v51]);
      }
      while ( v49 < v35 );
      v52 = (__m128)*(unsigned int *)v95;
      v53 = (__m128)*(unsigned int *)v100;
      v54 = (__m128)*(unsigned int *)v99;
      v55 = _mm_add_ps(v26, v25);
      v56 = (signed __int64)(v100 + 4);
      if ( (unsigned __int64)(v100 + 4) >= v105 )
        v56 = (signed __int64)v107;
      v100 = (float *)v56;
      v99 += 4;
      if ( (unsigned __int64)v99 >= v105 )
        v99 = v107 + 1;
      v95 += 4;
      if ( (unsigned __int64)(v47 + 4) >= v105 )
        v95 = v107 + 2;
      v102 = (signed __int64)(v33 + 4);
      if ( (unsigned __int64)(v33 + 4) >= v105 )
        v102 = (signed __int64)(v107 + 3);
      v57 = 0;
      v30 = _mm_add_ps(
              _mm_mul_ps(
                _mm_movelh_ps(_mm_unpacklo_ps(v53, v54), _mm_unpacklo_ps(v52, (__m128)*(unsigned int *)v33)),
                v121),
              _mm_mul_ps(v30, v116));
      do
      {
        v58 = v57;
        v59 = v57++;
        v122[v59] = (__int128)_mm_add_ps(_mm_mul_ps(vOutDecorrelationVector[v58][2], v30), (__m128)v122[v59]);
      }
      while ( v57 < v35 );
      v60 = 0;
      v61 = _mm_add_ps(v55, v30);
      v62 = v126->uMaxFrames;
      v63 = 0i64;
      do
      {
        v64 = v9[v63];
        v65 = v60++;
        v65 *= 2i64;
        v63 = (unsigned int)(v62 + v63);
        v66 = *(__m128 *)((char *)v122 + 8 * v65);
        *(__int128 *)((char *)&v123 + 8 * v65) = v64;
        v67 = _mm_add_ps(v66, _mm_movehl_ps(v66, v66));
        *(__int128 *)((char *)v122 + 8 * v65) = (__int128)_mm_add_ps(_mm_shuffle_ps(v67, v67, 85), v67);
      }
      while ( v60 < v35 );
      v11 = v11 + v112;
      v68 = 0;
      v69 = 0i64;
      v70 = _mm_add_ps(_mm_movehl_ps(v61, v61), v61);
      v10 = v10 + v20;
      v71 = _mm_add_ps(_mm_shuffle_ps(v70, v70, 85), v70);
      v72 = _mm_shuffle_ps(v71, v71, 0);
      do
      {
        v73 = v68++;
        v73 *= 2i64;
        v74 = *(__int128 *)((char *)&v123 + 8 * v73);
        *(float *)&v74 = (float)(*(float *)&v74 * v10)
                       + (float)(COERCE_FLOAT(*(__int128 *)((char *)v122 + 8 * v73)) * v11);
        v9[v69] = v74;
        v69 = (unsigned int)(v62 + v69);
        *(__int128 *)((char *)v122 + 8 * v73) = v74;
      }
      while ( v68 < v35 );
      v75 = _mm_mul_ps(v72, v118);
      ++v9;
      v76 = _mm_add_ps(v30, v75);
      v77 = _mm_add_ps(v26, v75);
      v78 = _mm_add_ps(v75, v25);
      v79 = _mm_shuffle_ps(v76, _mm_shuffle_ps(v76, v78, 15), 201);
      v80 = _mm_shuffle_ps(v77, _mm_shuffle_ps(v77, v76, 15), 201);
      v81 = _mm_shuffle_ps(v78, v77, 15);
      v82 = *(float *)&v123;
      v83 = _mm_shuffle_ps(v78, v81, 201);
      if ( v35 > 1 )
      {
        v84 = (float *)&v124;
        v85 = v35 - 1;
        do
        {
          v82 = v82 + *v84;
          v84 += 4;
          --v85;
        }
        while ( v85 );
      }
      v12 = (float)((float)(v14 * v12) + v82) - v13;
      v13 = v82;
      if ( v127 )
      {
        v86 = *v4;
        *v4 = v12;
        ++v4;
        if ( v4 == v110 )
          v4 = v108;
      }
      else
      {
        v86 = v12;
      }
      v87 = v113;
      v8 = v111;
      v88 = (signed __int64)(v101 + 4);
      v89 = v115 * v15;
      v15 = v86;
      v87.m128_f32[0] = (float)(v113.m128_f32[0] * v86) + v89;
      v90 = _mm_shuffle_ps(v87, v87, 0);
      v91 = _mm_add_ps(v90, v79);
      v20 = v119;
      v92 = _mm_add_ps(v90, v83);
      v22 = v117;
      *(__m128 *)v101 = v92;
      *v103 = _mm_add_ps(v90, v80);
      *(__m128 *)v98 = v91;
      v19 = v109;
      if ( (unsigned __int64)(v101 + 4) >= v104 )
        v88 = (signed __int64)v109;
      v93 = (signed __int64)&v103[1];
      v101 = (float *)v88;
      if ( &v103[1] >= (__m128 *)v106 )
        v93 = (signed __int64)v111;
      v103 = (__m128 *)v93;
      v94 = (signed __int64)(v98 + 4);
      if ( (unsigned __int64)(v98 + 4) >= v105 )
        v94 = (signed __int64)v107;
      v34 = v128-- == 1;
      v98 = (float *)v94;
      v33 = (float *)v102;
    }
    while ( !v34 );
    v5 = v125;
    v36 = v95;
    v21 = v100;
  }
  v5->m_fFIRLPFMem = v15;
  v5->m_fDCFwdMem = v13;
  v5->m_fDCFbkMem = v12;
  v5->m_pfPreDelayRW = v4;
  v5->m_pfDelayWrite[0] = v101;
  v5->m_vIIRLPFMem[0] = v25;
  v5->m_vIIRLPFMem[1] = v26;
  v5->m_vIIRLPFMem[2] = v30;
  v5->m_pfDelayWrite[1] = (float *)v103;
  v5->m_pfDelayRead[0] = v23;
  v5->m_pfDelayWrite[2] = v98;
  v5->m_pfDelayRead[2] = v27;
  v5->m_pfDelayRead[1] = v96;
  v5->m_pfDelayRead[3] = v28;
  v5->m_pfDelayRead[5] = v97;
  v5->m_pfDelayRead[4] = v29;
  v5->m_pfDelayRead[6] = v31;
  v5->m_pfDelayRead[7] = v32;
  v5->m_pfDelayRead[8] = v21;
  v5->m_pfDelayRead[9] = v99;
  v5->m_pfDelayRead[10] = v36;
  v5->m_pfDelayRead[11] = v33;
}

// File Line: 1832
// RVA: 0xACB470
void __usercall CAkFDNReverbFX::ProcessN16(CAkFDNReverbFX *this@<rcx>, AkAudioBuffer *io_pBuffer@<rdx>, __m128 a3@<xmm5>, __m128 a4@<xmm6>)
{
  __m128 v4; // xmm1
  float *v5; // rbp
  CAkFDNReverbFX *v6; // r11
  AkAudioBuffer *v7; // r10
  CAkFDNReverbFXParams *v8; // rdx
  unsigned int *v9; // rbx
  float v10; // xmm12_4
  float v11; // xmm11_4
  float v12; // xmm15_4
  float v13; // xmm13_4
  float v14; // xmm14_4
  float v15; // xmm2_4
  float v16; // xmm6_4
  float v17; // xmm0_4
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
  unsigned int v33; // er10
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
  signed __int64 v65; // rdx
  unsigned int v66; // edx
  __int64 v67; // rax
  __int64 v68; // rcx
  unsigned int v69; // edx
  __m128 v70; // xmm4
  int v71; // er9
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
  signed __int64 v100; // rcx
  __m128 v101; // xmm2
  __m128 v102; // xmm0
  signed __int64 v103; // rdx
  __m128 v104; // xmm0
  signed __int64 v105; // r8
  __m128 v106; // xmm2
  signed __int64 v107; // r9
  bool v108; // zf
  float *v109; // ST48_8
  float *v110; // [rsp+0h] [rbp-388h]
  float *v111; // [rsp+8h] [rbp-380h]
  float *v112; // [rsp+10h] [rbp-378h]
  float *v113; // [rsp+18h] [rbp-370h]
  float *v114; // [rsp+20h] [rbp-368h]
  float *v115; // [rsp+28h] [rbp-360h]
  float *v116; // [rsp+30h] [rbp-358h]
  float *v117; // [rsp+38h] [rbp-350h]
  __m128 *v118; // [rsp+40h] [rbp-348h]
  float *v119; // [rsp+50h] [rbp-338h]
  float *v120; // [rsp+58h] [rbp-330h]
  float *v121; // [rsp+60h] [rbp-328h]
  signed __int64 v122; // [rsp+68h] [rbp-320h]
  float *v123; // [rsp+70h] [rbp-318h]
  float *v124; // [rsp+78h] [rbp-310h]
  float *v125; // [rsp+80h] [rbp-308h]
  float *v126; // [rsp+88h] [rbp-300h]
  float *v127; // [rsp+90h] [rbp-2F8h]
  float *v128; // [rsp+98h] [rbp-2F0h]
  float *v129; // [rsp+A0h] [rbp-2E8h]
  float *v130; // [rsp+A8h] [rbp-2E0h]
  float *v131; // [rsp+B0h] [rbp-2D8h]
  float *v132; // [rsp+B8h] [rbp-2D0h]
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
  __int128 v147[8]; // [rsp+1A0h] [rbp-1E8h]
  __int128 v148; // [rsp+220h] [rbp-168h]
  char v149; // [rsp+230h] [rbp-158h]
  CAkFDNReverbFX *v150; // [rsp+390h] [rbp+8h]
  AkAudioBuffer *v151; // [rsp+398h] [rbp+10h]
  bool v152; // [rsp+3A0h] [rbp+18h]
  int v153; // [rsp+3A8h] [rbp+20h]

  v151 = io_pBuffer;
  v150 = this;
  v4 = (__m128)LODWORD(FLOAT_N2_0);
  v5 = this->m_pfPreDelayRW;
  v6 = this;
  v7 = io_pBuffer;
  v8 = this->m_pParams;
  v9 = (unsigned int *)v7->pData;
  v136 = _mm_shuffle_ps((__m128)LODWORD(this->m_fFIRLPFB0), (__m128)LODWORD(this->m_fFIRLPFB0), 0);
  LODWORD(v138) = (unsigned __int128)_mm_shuffle_ps(
                                       (__m128)LODWORD(this->m_fFIRLPFB1),
                                       (__m128)LODWORD(this->m_fFIRLPFB1),
                                       0);
  LODWORD(v10) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fCurrentDry),
                                      (__m128)LODWORD(this->m_fCurrentDry),
                                      0);
  LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      (__m128)LODWORD(this->m_fDCFbkMem),
                                      0);
  LODWORD(v12) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      (__m128)LODWORD(this->m_fDCCoef),
                                      0);
  LODWORD(v13) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fCurrentWet),
                                      (__m128)LODWORD(this->m_fCurrentWet),
                                      0);
  LODWORD(v14) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      (__m128)LODWORD(this->m_fDCFwdMem),
                                      0);
  v4.m128_f32[0] = -2.0 / (float)(signed int)v8->NonRTPC.uNumberOfDelays;
  v135 = _mm_shuffle_ps(v4, v4, 0);
  v132 = this->m_pfPreDelayStart;
  v126 = this->m_pfDelayStart[0];
  v152 = this->m_pfPreDelayStart != 0i64;
  v15 = 1.0 / (float)v7->uMaxFrames;
  v130 = this->m_pfDelayEnd[0];
  v117 = this->m_pfDelayStart[2];
  a4.m128_f32[0] = (float)(v8->RTPC.fWetLevel - this->m_fCurrentWet) * v15;
  LODWORD(v16) = (unsigned __int128)_mm_shuffle_ps(a4, a4, 0);
  LODWORD(v17) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      (__m128)LODWORD(this->m_fFIRLPFMem),
                                      0);
  a3.m128_f32[0] = (float)(v8->RTPC.fDryLevel - this->m_fCurrentDry) * v15;
  v131 = this->m_pfPreDelayEnd;
  v124 = this->m_pfDelayEnd[2];
  v142 = v16;
  v133 = v17;
  LODWORD(v18) = (unsigned __int128)_mm_shuffle_ps(a3, a3, 0);
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
  v144 = this->m_vIIRLPFB0[0];
  v29 = this->m_pfDelayRead[4];
  v30 = this->m_pfDelayRead[6];
  v31 = this->m_pfDelayRead[7];
  v143 = this->m_vIIRLPFB0[2];
  v32 = this->m_pfDelayRead[10];
  v120 = this->m_pfDelayWrite[0];
  v146 = this->m_vIIRLPFB0[3];
  v137 = this->m_vIIRLPFA1[0];
  v118 = (__m128 *)this->m_pfDelayWrite[1];
  v116 = this->m_pfDelayRead[9];
  v134 = this->m_vIIRLPFA1[1];
  v119 = this->m_pfDelayWrite[2];
  v139 = this->m_vIIRLPFA1[2];
  v141 = this->m_vIIRLPFA1[3];
  v121 = this->m_pfDelayWrite[3];
  v123 = this->m_pfDelayRead[12];
  v113 = this->m_pfDelayRead[1];
  v153 = v7->uValidFrames;
  v33 = this->m_uNumProcessedChannels;
  v111 = this->m_pfDelayRead[13];
  v34 = this->m_pfDelayRead[14];
  v114 = v6->m_pfDelayRead[5];
  v35 = v6->m_pfDelayRead[8];
  v110 = v6->m_pfDelayRead[11];
  v115 = v34;
  v112 = v6->m_pfDelayRead[15];
  if ( v153 )
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
      v41 = (__m128)*(unsigned int *)v113;
      v113 += 4;
      if ( v113 >= v130 )
        v113 = v37 + 1;
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
        v147[v44] = (__int128)_mm_mul_ps(vOutDecorrelationVector[v43][0], v22);
      }
      while ( v42 < v33 );
      v45 = (__m128)*(unsigned int *)v29;
      v46 = (__m128)*(unsigned int *)v30;
      v47 = (__m128)*(unsigned int *)v31;
      v29 += 4;
      v48 = (__m128)*(unsigned int *)v114;
      if ( v29 >= v129 )
        v29 = v128;
      v114 += 4;
      if ( v114 >= v129 )
        v114 = v128 + 1;
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
        v147[v51] = (__int128)_mm_add_ps(_mm_mul_ps(vOutDecorrelationVector[v50][1], v23), (__m128)v147[v51]);
      }
      while ( v49 < v33 );
      v52 = (__m128)*(unsigned int *)v36;
      v53 = v117;
      v54 = (__m128)*(unsigned int *)v116;
      v55 = _mm_add_ps(v23, v22);
      v36 += 4;
      v56 = (__m128)*(unsigned int *)v110;
      if ( v36 >= v124 )
        v36 = v117;
      v116 += 4;
      if ( v116 >= v124 )
        v116 = v117 + 1;
      v122 = (signed __int64)(v32 + 4);
      if ( v32 + 4 >= v124 )
      {
        v122 = (signed __int64)(v117 + 2);
        v53 = v117;
      }
      v110 += 4;
      if ( v110 >= v124 )
        v110 = v53 + 3;
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
        v147[v59] = (__int128)_mm_add_ps(_mm_mul_ps(vOutDecorrelationVector[v58][2], v27), (__m128)v147[v59]);
      }
      while ( v57 < v33 );
      v60 = _mm_add_ps(v55, v27);
      v61 = (__m128)*(unsigned int *)v123;
      v62 = (__m128)*(unsigned int *)v111;
      v63 = (__m128)*(unsigned int *)v115;
      v64 = (__m128)*(unsigned int *)v112;
      v65 = (signed __int64)(v123 + 4);
      if ( v123 + 4 >= v125 )
        v65 = (signed __int64)v127;
      v123 = (float *)v65;
      v111 += 4;
      if ( v111 >= v125 )
        v111 = v127 + 1;
      v115 += 4;
      if ( v115 >= v125 )
        v115 = v127 + 2;
      v112 += 4;
      if ( v112 >= v125 )
        v112 = v127 + 3;
      v66 = 0;
      v28 = _mm_add_ps(
              _mm_mul_ps(_mm_movelh_ps(_mm_unpacklo_ps(v61, v62), _mm_unpacklo_ps(v63, v64)), v146),
              _mm_mul_ps(v28, v141));
      do
      {
        v67 = v66;
        v68 = v66++;
        v147[v68] = (__int128)_mm_add_ps(_mm_mul_ps(vOutDecorrelationVector[v67][3], v28), (__m128)v147[v68]);
      }
      while ( v66 < v33 );
      v69 = 0;
      v70 = _mm_add_ps(v60, v28);
      v71 = v151->uMaxFrames;
      v72 = 0i64;
      do
      {
        v73 = v9[v72];
        v74 = v69++;
        v74 *= 2i64;
        v72 = (unsigned int)(v71 + v72);
        v75 = *(__m128 *)((char *)v147 + 8 * v74);
        *(__int128 *)((char *)&v148 + 8 * v74) = v73;
        v76 = _mm_add_ps(v75, _mm_movehl_ps(v75, v75));
        *(__int128 *)((char *)v147 + 8 * v74) = (__int128)_mm_add_ps(_mm_shuffle_ps(v76, v76, 85), v76);
      }
      while ( v69 < v33 );
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
                       + (float)(COERCE_FLOAT(*(__int128 *)((char *)v147 + 8 * v82)) * v13);
        v9[v78] = v83;
        v78 = (unsigned int)(v71 + v78);
        *(__int128 *)((char *)v147 + 8 * v82) = v83;
      }
      while ( v77 < v33 );
      v84 = _mm_mul_ps(v81, v135);
      ++v9;
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
      if ( v33 > 1 )
      {
        v95 = (float *)&v149;
        v96 = v33 - 1;
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
      if ( v152 )
      {
        v97 = *v5;
        *v5 = v11;
        ++v5;
        if ( v5 == v131 )
          v5 = v132;
      }
      else
      {
        v97 = v11;
      }
      v98 = v136;
      v99 = v138 * v133;
      v133 = v97;
      v37 = v126;
      v100 = (signed __int64)(v120 + 4);
      v98.m128_f32[0] = (float)(v136.m128_f32[0] * v97) + v99;
      v101 = _mm_shuffle_ps(v98, v98, 0);
      v102 = _mm_add_ps(v101, v94);
      v21 = v144;
      *(__m128 *)v120 = v102;
      *v118 = _mm_add_ps(v101, v91);
      if ( v120 + 4 >= v130 )
        v100 = (signed __int64)v126;
      v103 = (signed __int64)&v118[1];
      v104 = _mm_add_ps(v101, v89);
      v120 = (float *)v100;
      if ( &v118[1] >= (__m128 *)v129 )
        v103 = (signed __int64)v128;
      v105 = (signed __int64)(v119 + 4);
      v106 = _mm_add_ps(v101, v88);
      v18 = v140;
      v16 = v142;
      *(__m128 *)v119 = v104;
      v118 = (__m128 *)v103;
      if ( v119 + 4 >= v124 )
        v105 = (signed __int64)v117;
      *(__m128 *)v121 = v106;
      v107 = (signed __int64)(v121 + 4);
      v119 = (float *)v105;
      v32 = (float *)v122;
      if ( v121 + 4 >= v125 )
        v107 = (signed __int64)v127;
      v108 = v153-- == 1;
      v121 = (float *)v107;
    }
    while ( !v108 );
    v17 = v97;
    v19 = v110;
    v34 = v115;
    v20 = v112;
    v109 = v36;
    v6 = v150;
    v35 = v109;
  }
  v6->m_fFIRLPFMem = v17;
  v6->m_fDCFwdMem = v14;
  v6->m_fDCFbkMem = v11;
  v6->m_pfPreDelayRW = v5;
  v6->m_pfDelayWrite[0] = v120;
  v6->m_vIIRLPFMem[0] = v22;
  v6->m_vIIRLPFMem[1] = v23;
  v6->m_vIIRLPFMem[2] = v27;
  v6->m_pfDelayWrite[1] = (float *)v118;
  v6->m_pfDelayRead[8] = v35;
  v6->m_vIIRLPFMem[3] = v28;
  v6->m_pfDelayWrite[2] = v119;
  v6->m_pfDelayWrite[3] = v121;
  v6->m_pfDelayRead[9] = v116;
  v6->m_pfDelayRead[1] = v113;
  v6->m_pfDelayRead[12] = v123;
  v6->m_pfDelayRead[5] = v114;
  v6->m_pfDelayRead[0] = v24;
  v6->m_pfDelayRead[2] = v25;
  v6->m_pfDelayRead[3] = v26;
  v6->m_pfDelayRead[4] = v29;
  v6->m_pfDelayRead[6] = v30;
  v6->m_pfDelayRead[7] = v31;
  v6->m_pfDelayRead[10] = v32;
  v6->m_pfDelayRead[11] = v19;
  v6->m_pfDelayRead[13] = v111;
  v6->m_pfDelayRead[14] = v34;
  v6->m_pfDelayRead[15] = v20;
}119;
  v6->m_pfDelayWrite[3] = v121;
  v6->m_pfDelayRead[9] = v116;
  v6->m_pfDelayRead[1] = v113;
  v6->m_pfDelayRead[12] = v123;
  v6->m_pfDelayRead[5] = v114;
  v6->m_pfDelayRead[0] = v24;
  v6->m_pfDelayRead[2] = v25;
  v6->m_pfDelayRead[3] = v26;
  v6->m_

// File Line: 1899
// RVA: 0xACBF70
void __fastcall CAkFDNReverbFX::ComputeIIRLPFCoefs(CAkFDNReverbFX *this)
{
  CAkFDNReverbFXParams *v1; // rdx
  CAkFDNReverbFX *v2; // rdi
  unsigned int v3; // ebx
  double v4; // xmm9_8
  double v5; // xmm7_8
  double v6; // xmm0_8
  double v7; // xmm0_8
  double v8; // xmm11_8
  double v9; // xmm0_8
  __int64 v10; // rsi
  CAkFDNReverbFXParams *v11; // rcx
  double v12; // xmm0_8
  double v13; // xmm6_8
  double v14; // xmm0_8
  __int64 v15; // rbx
  unsigned __int64 v16; // rcx
  double v17; // xmm2_8
  float v18; // xmm1_4

  v1 = this->m_pParams;
  v2 = this;
  v3 = v1->NonRTPC.uNumberOfDelays;
  v4 = 1.0 / (double)(signed int)this->m_uSampleRate;
  v5 = 1.0 - 1.0 / (1.0 / v1->RTPC.fHFRatio * (1.0 / v1->RTPC.fHFRatio));
  v6 = pow(0.001, (double)(signed int)this->m_uNominalDelayLength[v3 - 1] * v4 / v1->RTPC.fReverbTime);
  v7 = log10(v6);
  v8 = IIRCOEFCALCCONST;
  v9 = v7 * IIRCOEFCALCCONST;
  if ( v9 * v5 > 1.0 )
    v5 = 1.0 / v9;
  v10 = 0i64;
  if ( v3 )
  {
    v11 = v2->m_pParams;
    do
    {
      v12 = pow(0.001, (double)(signed int)v2->m_uNominalDelayLength[v10] * v4 / v11->RTPC.fReverbTime);
      v13 = v12;
      v14 = log10(v12);
      v15 = v10 & 3;
      v16 = (unsigned int)v10;
      v10 = (unsigned int)(v10 + 1);
      v16 >>= 2;
      v17 = v14 * v8 * v5;
      *(float *)&v14 = (1.0 - v17) * v13;
      v2->m_vIIRLPFB0[0].m128_i32[v15 + 4 * v16] = LODWORD(v14);
      v18 = v17;
      v2->m_vIIRLPFA1[0].m128_f32[v15 + 4 * v16] = v18;
      v11 = v2->m_pParams;
    }
    while ( (unsigned int)v10 < v11->NonRTPC.uNumberOfDelays );
  }
}


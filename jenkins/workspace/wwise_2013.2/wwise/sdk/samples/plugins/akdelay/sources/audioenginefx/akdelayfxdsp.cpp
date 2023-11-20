// File Line: 17
// RVA: 0xACC880
void __fastcall CAkDelayFXDSP::CAkDelayFXDSP(CAkDelayFXDSP *this)
{
  *(_QWORD *)&this->m_DelayMem.m_uDelayLineLength = 0i64;
  this->m_DelayMem.m_uNumChannels = 0;
  this->m_DelayMem.m_pDelay[0] = 0i64;
  this->m_DelayMem.m_pDelay[1] = 0i64;
  this->m_DelayMem.m_pDelay[2] = 0i64;
  this->m_DelayMem.m_pDelay[3] = 0i64;
  this->m_DelayMem.m_pDelay[4] = 0i64;
  this->m_DelayMem.m_pDelay[5] = 0i64;
  this->m_DelayMem.m_pDelay[6] = 0i64;
  this->m_DelayMem.m_pDelay[7] = 0i64;
  this->m_FXTailHandler.uTailFramesRemaining = -1;
  this->m_FXTailHandler.uTotalTailFrames = 0;
  this->m_uNumProcessedChannels = 0;
}

// File Line: 27
// RVA: 0xACCED0
void __fastcall CAkDelayFXDSP::Setup(CAkDelayFXDSP *this, AkDelayFXParams *pInitialParams, bool in_bIsSendMode, unsigned int in_uSampleRate)
{
  int v4; // eax

  this->m_bSendMode = in_bIsSendMode;
  this->m_PreviousParams.RTPC.fFeedback = pInitialParams->RTPC.fFeedback;
  this->m_PreviousParams.RTPC.fWetDryMix = pInitialParams->RTPC.fWetDryMix;
  this->m_PreviousParams.RTPC.fOutputLevel = pInitialParams->RTPC.fOutputLevel;
  *(_DWORD *)&this->m_PreviousParams.RTPC.bFeedbackEnabled = *(_DWORD *)&pInitialParams->RTPC.bFeedbackEnabled;
  this->m_PreviousParams.NonRTPC.fDelayTime = pInitialParams->NonRTPC.fDelayTime;
  v4 = *(_DWORD *)&pInitialParams->NonRTPC.bProcessLFE;
  this->m_uSampleRate = in_uSampleRate;
  *(_DWORD *)&this->m_PreviousParams.NonRTPC.bProcessLFE = v4;
  if ( !this->m_PreviousParams.RTPC.bFeedbackEnabled )
    this->m_PreviousParams.RTPC.fFeedback = 0.0;
  if ( in_bIsSendMode )
    this->m_PreviousParams.RTPC.fWetDryMix = 1.0;
}

// File Line: 42
// RVA: 0xACC9C0
signed __int64 __fastcall CAkDelayFXDSP::InitDelay(CAkDelayFXDSP *this, AK::IAkPluginMemAlloc *in_pAllocator, AkDelayFXParams *pParams, unsigned int in_uChannelMask)
{
  unsigned int v4; // edi
  AkDelayFXParams *v5; // rsi
  AK::IAkPluginMemAlloc *v6; // rbp
  CAkDelayFXDSP *v7; // rbx
  unsigned int v8; // er11
  unsigned int i; // er10
  bool v10; // al
  unsigned int v11; // er9
  signed __int64 result; // rax

  v4 = in_uChannelMask;
  v5 = pParams;
  v6 = in_pAllocator;
  v7 = this;
  AK::DSP::CAkDelayLineMemory<float,8>::Term(
    (AK::DSP::CAkDelayLineMemory<float,8> *)this->m_DelayMem.m_pDelay,
    in_pAllocator);
  v8 = 0;
  for ( i = v4; i; i &= i - 1 )
    ++v8;
  v7->m_uNumProcessedChannels = v8;
  v10 = v5->NonRTPC.bProcessLFE;
  v7->m_bProcessLFE = v10;
  if ( v4 & 8 && !v10 )
    v7->m_uNumProcessedChannels = v8 - 1;
  v11 = v7->m_uNumProcessedChannels;
  if ( v11 )
    result = AK::DSP::CAkDelayLineMemory<float,8>::Init(
               (AK::DSP::CAkDelayLineMemory<float,8> *)v7->m_DelayMem.m_pDelay,
               v6,
               (signed int)(float)((float)(signed int)v7->m_uSampleRate * v5->NonRTPC.fDelayTime),
               v11);
  else
    result = 2i64;
  return result;
}

// File Line: 59
// RVA: 0xACCEC0
void __fastcall CAkDelayFXDSP::ResetDelay(CAkDelayFXDSP *this)
{
  AK::DSP::CAkDelayLineMemory<float,8>::Reset((AK::DSP::CAkDelayLineMemory<float,8> *)this->m_DelayMem.m_pDelay);
}

// File Line: 64
// RVA: 0xACCFA0
void __fastcall CAkDelayFXDSP::TermDelay(CAkDelayFXDSP *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::DSP::CAkDelayLineMemory<float,8>::Term(
    (AK::DSP::CAkDelayLineMemory<float,8> *)this->m_DelayMem.m_pDelay,
    in_pAllocator);
}

// File Line: 69
// RVA: 0xACC8C0
void __fastcall CAkDelayFXDSP::ComputeTailLength(CAkDelayFXDSP *this, bool in_bFeedbackEnabled, float in_fFeedbackValue)
{
  CAkDelayFXDSP *v3; // rbx
  float v4; // xmm0_4
  float v5; // xmm1_4

  v3 = this;
  if ( in_bFeedbackEnabled && in_fFeedbackValue != 0.0 )
  {
    v4 = log10f(in_fFeedbackValue) * 20.0;
    if ( v4 >= -0.60000002 )
      v5 = FLOAT_100_0;
    else
      v5 = -60.0 / v4;
    v3->m_uTailLength = (signed int)(float)((float)(signed int)v3->m_DelayMem.m_uDelayLineLength * v5);
  }
  else
  {
    this->m_uTailLength = this->m_DelayMem.m_uDelayLineLength;
  }
}

// File Line: 104
// RVA: 0xACCA60
void __usercall CAkDelayFXDSP::Process(CAkDelayFXDSP *this@<rcx>, AkAudioBuffer *io_pBuffer@<rdx>, AkDelayFXParams *pCurrentParams@<r8>, __m128 a4@<xmm8>)
{
  CAkDelayFXDSP *v4; // r15
  AkDelayFXParams *v5; // r12
  AkAudioBuffer *v6; // rbx
  signed int v7; // edi
  int v8; // esi
  unsigned int v9; // ecx
  unsigned int v10; // edx
  __m128 v11; // xmm2
  unsigned int v12; // ebp
  __m128 *v13; // r13
  __int64 v14; // rax
  CAkDelayFXDSP *v15; // r14
  float v16; // xmm4_4
  __m128 v17; // ST20_16
  signed __int64 v18; // rcx
  __m128 v19; // xmm8
  __m128 v20; // xmm9
  __m128 v21; // xmm9
  float v22; // xmm0_4
  float v23; // xmm0_4
  __m128 v24; // xmm2
  __m128 v25; // xmm12
  __m128 v26; // xmm10
  __m128 v27; // xmm10
  float v28; // xmm0_4
  float v29; // xmm0_4
  __m128 v30; // xmm2
  __m128 v31; // xmm13
  __m128 v32; // xmm11
  __m128 v33; // xmm11
  __m128 v34; // xmm4
  __m128 *v35; // r11
  unsigned int v36; // ebx
  __m128 v37; // xmm5
  __m128 v38; // xmm6
  __m128 v39; // xmm7
  unsigned int v40; // er8
  unsigned int v41; // er9
  signed __int64 v42; // r10
  __m128 v43; // xmm3
  __m128 v44; // xmm1
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm0
  __m128 v48; // xmm1
  __m128 v49; // xmm0
  unsigned int v50; // ecx
  char *v51; // rcx
  __m128 v52; // [rsp+20h] [rbp-D8h]
  signed __int64 v53; // [rsp+100h] [rbp+8h]
  AkAudioBuffer *v54; // [rsp+108h] [rbp+10h]
  __int64 v55; // [rsp+110h] [rbp+18h]

  v54 = io_pBuffer;
  v4 = this;
  v5 = pCurrentParams;
  v6 = io_pBuffer;
  AkFXTailHandler::HandleTail(&this->m_FXTailHandler, io_pBuffer, this->m_uTailLength);
  v7 = v6->uValidFrames;
  v8 = 0;
  if ( !v5->RTPC.bFeedbackEnabled )
    v5->RTPC.fFeedback = 0.0;
  if ( v4->m_bSendMode )
    v5->RTPC.fWetDryMix = 1.0;
  v9 = v4->m_uNumProcessedChannels;
  v10 = 0;
  if ( v9 )
  {
    v11 = (__m128)LODWORD(v5->RTPC.fOutputLevel);
    v12 = v4->m_DelayMem.m_uDelayLineLength;
    v13 = (__m128 *)v6->pData;
    v55 = v4->m_uNumProcessedChannels;
    v53 = 4i64 * v6->uMaxFrames;
    v14 = v9;
    v15 = v4;
    v16 = 1.0 / (float)v7;
    v17.m128_i32[0] = LODWORD(v4->m_PreviousParams.RTPC.fOutputLevel);
    v18 = 4i64 * v6->uMaxFrames;
    a4.m128_f32[0] = 1.0;
    v11.m128_f32[0] = (float)(v11.m128_f32[0] - v17.m128_f32[0]) * v16;
    v19 = _mm_shuffle_ps(a4, a4, 0);
    v20 = v11;
    v20.m128_f32[0] = v11.m128_f32[0] * 4.0;
    v21 = _mm_shuffle_ps(v20, v20, 0);
    v17.m128_f32[1] = v11.m128_f32[0] + v17.m128_f32[0];
    v22 = (float)(v11.m128_f32[0] + v17.m128_f32[0]) + v11.m128_f32[0];
    v17.m128_f32[2] = v22;
    v23 = v22 + v11.m128_f32[0];
    v24 = (__m128)LODWORD(v5->RTPC.fFeedback);
    v17.m128_f32[3] = v23;
    v25 = v17;
    v17.m128_i32[0] = LODWORD(v4->m_PreviousParams.RTPC.fFeedback);
    v24.m128_f32[0] = (float)(v24.m128_f32[0] - v17.m128_f32[0]) * v16;
    v26 = v24;
    v26.m128_f32[0] = v24.m128_f32[0] * 4.0;
    v27 = _mm_shuffle_ps(v26, v26, 0);
    v17.m128_f32[1] = v24.m128_f32[0] + v17.m128_f32[0];
    v28 = (float)(v24.m128_f32[0] + v17.m128_f32[0]) + v24.m128_f32[0];
    v17.m128_f32[2] = v28;
    v29 = v28 + v24.m128_f32[0];
    v30 = (__m128)LODWORD(v5->RTPC.fWetDryMix);
    v17.m128_f32[3] = v29;
    v31 = v17;
    v52.m128_i32[0] = LODWORD(v4->m_PreviousParams.RTPC.fWetDryMix);
    v30.m128_f32[0] = (float)(v30.m128_f32[0] - v52.m128_f32[0]) * v16;
    v32 = v30;
    v32.m128_f32[0] = v30.m128_f32[0] * 4.0;
    v52.m128_f32[1] = v30.m128_f32[0] + v52.m128_f32[0];
    v33 = _mm_shuffle_ps(v32, v32, 0);
    v52.m128_f32[2] = (float)(v30.m128_f32[0] + v52.m128_f32[0]) + v30.m128_f32[0];
    v52.m128_f32[3] = v52.m128_f32[2] + v30.m128_f32[0];
    do
    {
      v10 = v4->m_DelayMem.m_uOffset;
      v34 = v52;
      v35 = v13;
      v36 = 0;
      v37 = v25;
      v38 = v31;
      v39 = _mm_sub_ps(v19, v52);
      if ( v7 )
      {
        do
        {
          v40 = v7 - v36;
          if ( v12 - v10 < v7 - v36 )
            v40 = v12 - v10;
          v41 = v40 >> 2;
          if ( v40 >> 2 )
          {
            v42 = (signed __int64)&v15->m_DelayMem.m_pDelay[0][v10];
            do
            {
              v43 = *v35;
              v44 = v34;
              v34 = _mm_add_ps(v34, v33);
              v42 += 16i64;
              ++v35;
              v45 = _mm_mul_ps(v43, v39);
              v39 = _mm_sub_ps(v19, v34);
              v46 = _mm_add_ps(_mm_mul_ps(v44, *(__m128 *)(v42 - 16)), v45);
              v47 = v38;
              v38 = _mm_add_ps(v38, v27);
              v48 = _mm_mul_ps(v46, v37);
              v49 = _mm_add_ps(_mm_mul_ps(v47, *(__m128 *)(v42 - 16)), v43);
              v37 = _mm_add_ps(v37, v21);
              v35[-1] = v48;
              *(__m128 *)(v42 - 16) = v49;
              --v41;
            }
            while ( v41 );
          }
          v10 += v40;
          v36 += v40;
          if ( v10 == v12 )
            v10 = 0;
        }
        while ( v36 < v7 );
        v14 = v55;
        v18 = v53;
      }
      v13 = (__m128 *)((char *)v13 + v18);
      v15 = (CAkDelayFXDSP *)((char *)v15 + 8);
      v55 = --v14;
    }
    while ( v14 );
    v6 = v54;
  }
  v4->m_DelayMem.m_uOffset = v10;
  v50 = v6->uChannelMask;
  if ( v50 & 8 )
  {
    for ( ; v50; v50 &= v50 - 1 )
      ++v8;
    v51 = (char *)v6->pData + 4 * v6->uMaxFrames * (unsigned __int64)(unsigned int)(v8 - 1);
    if ( v51 && v4->m_bSendMode && !v5->NonRTPC.bProcessLFE )
      memset(v51, 0, (unsigned int)(4 * v7));
  }
  v4->m_PreviousParams.RTPC.fFeedback = v5->RTPC.fFeedback;
  v4->m_PreviousParams.RTPC.fWetDryMix = v5->RTPC.fWetDryMix;
  v4->m_PreviousParams.RTPC.fOutputLevel = v5->RTPC.fOutputLevel;
  *(_DWORD *)&v4->m_PreviousParams.RTPC.bFeedbackEnabled = *(_DWORD *)&v5->RTPC.bFeedbackEnabled;
  v4->m_PreviousParams.NonRTPC.fDelayTime = v5->NonRTPC.fDelayTime;
  *(_DWORD *)&v4->m_PreviousParams.NonRTPC.bProcessLFE = *(_DWORD *)&v5->NonRTPC.bProcessLFE;
}


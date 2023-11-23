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
void __fastcall CAkDelayFXDSP::Setup(
        CAkDelayFXDSP *this,
        AkDelayFXParams *pInitialParams,
        bool in_bIsSendMode,
        unsigned int in_uSampleRate)
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
__int64 __fastcall CAkDelayFXDSP::InitDelay(
        CAkDelayFXDSP *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AkDelayFXParams *pParams,
        unsigned int in_uChannelMask)
{
  unsigned int v8; // r11d
  unsigned int i; // r10d
  bool bProcessLFE; // al
  unsigned int m_uNumProcessedChannels; // r9d

  AK::DSP::CAkDelayLineMemory<float,8>::Term(&this->m_DelayMem, in_pAllocator);
  v8 = 0;
  for ( i = in_uChannelMask; i; i &= i - 1 )
    ++v8;
  this->m_uNumProcessedChannels = v8;
  bProcessLFE = pParams->NonRTPC.bProcessLFE;
  this->m_bProcessLFE = bProcessLFE;
  if ( (in_uChannelMask & 8) != 0 && !bProcessLFE )
    this->m_uNumProcessedChannels = v8 - 1;
  m_uNumProcessedChannels = this->m_uNumProcessedChannels;
  if ( m_uNumProcessedChannels )
    return AK::DSP::CAkDelayLineMemory<float,8>::Init(
             &this->m_DelayMem,
             in_pAllocator,
             (int)(float)((float)(int)this->m_uSampleRate * pParams->NonRTPC.fDelayTime),
             m_uNumProcessedChannels);
  else
    return 2i64;
}

// File Line: 59
// RVA: 0xACCEC0
// attributes: thunk
void __fastcall CAkDelayFXDSP::ResetDelay(CAkDelayFXDSP *this)
{
  AK::DSP::CAkDelayLineMemory<float,8>::Reset(&this->m_DelayMem);
}

// File Line: 64
// RVA: 0xACCFA0
// attributes: thunk
void __fastcall CAkDelayFXDSP::TermDelay(CAkDelayFXDSP *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::DSP::CAkDelayLineMemory<float,8>::Term(&this->m_DelayMem, in_pAllocator);
}

// File Line: 69
// RVA: 0xACC8C0
void __fastcall CAkDelayFXDSP::ComputeTailLength(
        CAkDelayFXDSP *this,
        bool in_bFeedbackEnabled,
        float in_fFeedbackValue)
{
  float v4; // xmm0_4
  float v5; // xmm1_4

  if ( !in_bFeedbackEnabled || in_fFeedbackValue == 0.0 )
  {
    this->m_uTailLength = this->m_DelayMem.m_uDelayLineLength;
  }
  else
  {
    v4 = log10f(in_fFeedbackValue) * 20.0;
    if ( v4 >= -0.60000002 )
      v5 = FLOAT_100_0;
    else
      v5 = -60.0 / v4;
    this->m_uTailLength = (int)(float)((float)(int)this->m_DelayMem.m_uDelayLineLength * v5);
  }
}

// File Line: 104
// RVA: 0xACCA60
void __fastcall CAkDelayFXDSP::Process(CAkDelayFXDSP *this, AkAudioBuffer *io_pBuffer, AkDelayFXParams *pCurrentParams)
{
  __m128 v3; // xmm8
  AkAudioBuffer *v6; // rbx
  int uValidFrames; // edi
  int v8; // esi
  unsigned int m_uNumProcessedChannels; // ecx
  unsigned int m_uOffset; // edx
  __m128 fOutputLevel_low; // xmm2
  unsigned int m_uDelayLineLength; // ebp
  __m128 *pData; // r13
  __int64 v14; // rax
  CAkDelayFXDSP *v15; // r14
  float v16; // xmm4_4
  __int64 v17; // rcx
  __m128 v18; // xmm8
  __m128 v19; // xmm9
  __m128 v20; // xmm9
  float v21; // xmm0_4
  __m128 fFeedback_low; // xmm2
  __m128 v23; // xmm12
  __m128 v24; // xmm10
  __m128 v25; // xmm10
  float v26; // xmm0_4
  __m128 fWetDryMix_low; // xmm2
  __m128 v28; // xmm13
  __m128 v29; // xmm11
  __m128 v30; // xmm11
  __m128 v31; // xmm4
  __m128 *v32; // r11
  unsigned int v33; // ebx
  __m128 v34; // xmm5
  __m128 v35; // xmm6
  __m128 v36; // xmm7
  unsigned int v37; // r8d
  unsigned int v38; // r9d
  __int64 v39; // r10
  __m128 v40; // xmm3
  __m128 v41; // xmm1
  __m128 v42; // xmm0
  __m128 v43; // xmm1
  __m128 v44; // xmm0
  __m128 v45; // xmm1
  __m128 v46; // xmm0
  unsigned int uChannelMask; // ecx
  char *v48; // rcx
  __m128 v49; // [rsp+20h] [rbp-D8h]
  __m128 v50; // [rsp+20h] [rbp-D8h]
  __int64 v51; // [rsp+100h] [rbp+8h]
  __int64 v53; // [rsp+110h] [rbp+18h]

  v6 = io_pBuffer;
  AkFXTailHandler::HandleTail(&this->m_FXTailHandler, io_pBuffer, this->m_uTailLength);
  uValidFrames = v6->uValidFrames;
  v8 = 0;
  if ( !pCurrentParams->RTPC.bFeedbackEnabled )
    pCurrentParams->RTPC.fFeedback = 0.0;
  if ( this->m_bSendMode )
    pCurrentParams->RTPC.fWetDryMix = 1.0;
  m_uNumProcessedChannels = this->m_uNumProcessedChannels;
  m_uOffset = 0;
  if ( m_uNumProcessedChannels )
  {
    fOutputLevel_low = (__m128)LODWORD(pCurrentParams->RTPC.fOutputLevel);
    m_uDelayLineLength = this->m_DelayMem.m_uDelayLineLength;
    pData = (__m128 *)v6->pData;
    v53 = this->m_uNumProcessedChannels;
    v51 = 4i64 * v6->uMaxFrames;
    v14 = m_uNumProcessedChannels;
    v15 = this;
    v16 = 1.0 / (float)uValidFrames;
    v49.m128_i32[0] = LODWORD(this->m_PreviousParams.RTPC.fOutputLevel);
    v17 = v51;
    v3.m128_f32[0] = 1.0;
    fOutputLevel_low.m128_f32[0] = (float)(fOutputLevel_low.m128_f32[0] - v49.m128_f32[0]) * v16;
    v18 = _mm_shuffle_ps(v3, v3, 0);
    v19 = fOutputLevel_low;
    v19.m128_f32[0] = fOutputLevel_low.m128_f32[0] * 4.0;
    v20 = _mm_shuffle_ps(v19, v19, 0);
    v49.m128_f32[1] = fOutputLevel_low.m128_f32[0] + v49.m128_f32[0];
    v49.m128_f32[2] = (float)(fOutputLevel_low.m128_f32[0] + v49.m128_f32[0]) + fOutputLevel_low.m128_f32[0];
    v21 = v49.m128_f32[2] + fOutputLevel_low.m128_f32[0];
    fFeedback_low = (__m128)LODWORD(pCurrentParams->RTPC.fFeedback);
    v49.m128_f32[3] = v21;
    v23 = v49;
    v49.m128_i32[0] = LODWORD(this->m_PreviousParams.RTPC.fFeedback);
    fFeedback_low.m128_f32[0] = (float)(fFeedback_low.m128_f32[0] - v49.m128_f32[0]) * v16;
    v24 = fFeedback_low;
    v24.m128_f32[0] = fFeedback_low.m128_f32[0] * 4.0;
    v25 = _mm_shuffle_ps(v24, v24, 0);
    v49.m128_f32[1] = fFeedback_low.m128_f32[0] + v49.m128_f32[0];
    v49.m128_f32[2] = (float)(fFeedback_low.m128_f32[0] + v49.m128_f32[0]) + fFeedback_low.m128_f32[0];
    v26 = v49.m128_f32[2] + fFeedback_low.m128_f32[0];
    fWetDryMix_low = (__m128)LODWORD(pCurrentParams->RTPC.fWetDryMix);
    v49.m128_f32[3] = v26;
    v28 = v49;
    v50.m128_i32[0] = LODWORD(this->m_PreviousParams.RTPC.fWetDryMix);
    fWetDryMix_low.m128_f32[0] = (float)(fWetDryMix_low.m128_f32[0] - v50.m128_f32[0]) * v16;
    v29 = fWetDryMix_low;
    v29.m128_f32[0] = fWetDryMix_low.m128_f32[0] * 4.0;
    v50.m128_f32[1] = fWetDryMix_low.m128_f32[0] + v50.m128_f32[0];
    v30 = _mm_shuffle_ps(v29, v29, 0);
    v50.m128_f32[2] = (float)(fWetDryMix_low.m128_f32[0] + v50.m128_f32[0]) + fWetDryMix_low.m128_f32[0];
    v50.m128_f32[3] = v50.m128_f32[2] + fWetDryMix_low.m128_f32[0];
    do
    {
      m_uOffset = this->m_DelayMem.m_uOffset;
      v31 = v50;
      v32 = pData;
      v33 = 0;
      v34 = v23;
      v35 = v28;
      v36 = _mm_sub_ps(v18, v50);
      if ( uValidFrames )
      {
        do
        {
          v37 = uValidFrames - v33;
          if ( m_uDelayLineLength - m_uOffset < uValidFrames - v33 )
            v37 = m_uDelayLineLength - m_uOffset;
          v38 = v37 >> 2;
          if ( v37 >> 2 )
          {
            v39 = (__int64)&v15->m_DelayMem.m_pDelay[0][m_uOffset];
            do
            {
              v40 = *v32;
              v41 = v31;
              v31 = _mm_add_ps(v31, v30);
              v39 += 16i64;
              ++v32;
              v42 = _mm_mul_ps(v40, v36);
              v36 = _mm_sub_ps(v18, v31);
              v43 = _mm_add_ps(_mm_mul_ps(v41, *(__m128 *)(v39 - 16)), v42);
              v44 = v35;
              v35 = _mm_add_ps(v35, v25);
              v45 = _mm_mul_ps(v43, v34);
              v46 = _mm_add_ps(_mm_mul_ps(v44, *(__m128 *)(v39 - 16)), v40);
              v34 = _mm_add_ps(v34, v20);
              v32[-1] = v45;
              *(__m128 *)(v39 - 16) = v46;
              --v38;
            }
            while ( v38 );
          }
          m_uOffset += v37;
          v33 += v37;
          if ( m_uOffset == m_uDelayLineLength )
            m_uOffset = 0;
        }
        while ( v33 < uValidFrames );
        v14 = v53;
        v17 = v51;
      }
      pData = (__m128 *)((char *)pData + v17);
      v15 = (CAkDelayFXDSP *)((char *)v15 + 8);
      v53 = --v14;
    }
    while ( v14 );
    v6 = io_pBuffer;
  }
  this->m_DelayMem.m_uOffset = m_uOffset;
  uChannelMask = v6->uChannelMask;
  if ( (uChannelMask & 8) != 0 )
  {
    for ( ; uChannelMask; uChannelMask &= uChannelMask - 1 )
      ++v8;
    v48 = (char *)v6->pData + 4 * v6->uMaxFrames * (unsigned __int64)(unsigned int)(v8 - 1);
    if ( v48 && this->m_bSendMode && !pCurrentParams->NonRTPC.bProcessLFE )
      memset(v48, 0, (unsigned int)(4 * uValidFrames));
  }
  this->m_PreviousParams.RTPC.fFeedback = pCurrentParams->RTPC.fFeedback;
  this->m_PreviousParams.RTPC.fWetDryMix = pCurrentParams->RTPC.fWetDryMix;
  this->m_PreviousParams.RTPC.fOutputLevel = pCurrentParams->RTPC.fOutputLevel;
  *(_DWORD *)&this->m_PreviousParams.RTPC.bFeedbackEnabled = *(_DWORD *)&pCurrentParams->RTPC.bFeedbackEnabled;
  this->m_PreviousParams.NonRTPC.fDelayTime = pCurrentParams->NonRTPC.fDelayTime;
  *(_DWORD *)&this->m_PreviousParams.NonRTPC.bProcessLFE = *(_DWORD *)&pCurrentParams->NonRTPC.bProcessLFE;
}


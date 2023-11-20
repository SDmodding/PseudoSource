// File Line: 27
// RVA: 0xAF8190
void __fastcall DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::ResetInputFill(DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder *this)
{
  unsigned int v1; // ebx
  DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder *v2; // rsi
  signed __int64 v3; // rdi

  v1 = 0;
  v2 = this;
  if ( this->m_uNumChannels )
  {
    do
    {
      v3 = v1;
      DSP::CAkResamplingCircularBuffer::Reset(&v2->m_ResamplingInputAccumBuf[v3]);
      ++v1;
      v2->m_ResamplingInputAccumBuf[v3].m_uFramesReady = v2->m_ResamplingInputAccumBuf[v3].m_uSize;
    }
    while ( v1 < v2->m_uNumChannels );
  }
}

// File Line: 41
// RVA: 0xAF8200
__int64 __fastcall DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::Init(DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder *this, AK::IAkPluginMemAlloc *in_pAllocator, unsigned int in_uNumChannels, unsigned int in_uSampleRate, unsigned int in_uFFTSize, bool in_bUseInputBuffer)
{
  AK::IAkPluginMemAlloc *v6; // rsi
  DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder *v7; // rdi
  int v8; // ebx
  __int64 result; // rax

  v6 = in_pAllocator;
  v7 = this;
  DSP::AkFFTAllButterflies::CAkPhaseVocoder::Init(
    (DSP::AkFFTAllButterflies::CAkPhaseVocoder *)this->m_InputAccumBuf,
    in_pAllocator,
    in_uNumChannels,
    in_uSampleRate,
    in_uFFTSize,
    in_bUseInputBuffer);
  v8 = 0;
  if ( !v7->m_uNumChannels )
    return 1i64;
  while ( 1 )
  {
    result = DSP::CAkCircularBuffer::Init(
               (DSP::CAkCircularBuffer *)&v7->m_ResamplingInputAccumBuf[v8].m_uSize,
               v6,
               v7->m_uFFTSize + (v7->m_uFFTSize >> 2));
    if ( (_DWORD)result != 1 )
      break;
    if ( ++v8 >= v7->m_uNumChannels )
      return 1i64;
  }
  return result;
}

// File Line: 53
// RVA: 0xAF82A0
void __fastcall DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::Term(DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  unsigned int v2; // ebx
  AK::IAkPluginMemAlloc *v3; // rsi
  DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder *v4; // rdi

  v2 = 0;
  v3 = in_pAllocator;
  v4 = this;
  if ( this->m_uNumChannels )
  {
    do
      DSP::CAkCircularBuffer::Term((DSP::CAkCircularBuffer *)&v4->m_ResamplingInputAccumBuf[v2++].m_uSize, v3);
    while ( v2 < v4->m_uNumChannels );
  }
  DSP::AkFFTAllButterflies::CAkPhaseVocoder::Term((DSP::AkFFTAllButterflies::CAkPhaseVocoder *)v4->m_InputAccumBuf, v3);
}

// File Line: 60
// RVA: 0xAF8310
void __fastcall DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::Reset(DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder *this)
{
  DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder *v1; // rdi
  unsigned int v2; // ebx

  v1 = this;
  DSP::AkFFTAllButterflies::CAkPhaseVocoder::Reset((DSP::AkFFTAllButterflies::CAkPhaseVocoder *)this->m_InputAccumBuf);
  v2 = 0;
  if ( v1->m_uNumChannels )
  {
    do
      DSP::CAkResamplingCircularBuffer::Reset(&v1->m_ResamplingInputAccumBuf[v2++]);
    while ( v2 < v1->m_uNumChannels );
  }
}

// File Line: 84
// RVA: 0xAF8360
__int64 __fastcall DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::ProcessPitchChannel(DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder *this, float *in_pfInBuf, unsigned int in_uNumFrames, bool in_bNoMoreData, unsigned int i, float *io_pfOutBuf, float in_fResamplingFactor, float *in_pfTempStorage)
{
  float v8; // xmm1_4
  unsigned int v9; // er15
  __m128 in_fInterpLoc; // xmm7
  unsigned int v11; // er12
  float *v12; // r14
  float *v13; // r10
  DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder *v14; // rbx
  int v15; // er13
  unsigned int v16; // ebp
  float v17; // xmm9_4
  unsigned int v18; // eax
  unsigned int v19; // edx
  unsigned int v20; // ecx
  signed __int64 v21; // rdi
  int v22; // ecx
  unsigned int v23; // eax
  unsigned int v24; // ecx
  unsigned int v25; // ebp
  __int64 v26; // r13
  unsigned int v27; // eax
  char v28; // cl
  signed __int64 v29; // rsi
  float v30; // xmm6_4
  signed int v31; // ecx
  signed int v32; // ecx
  int v33; // er15
  bool v34; // si
  DSP::CAkOLACircularBuffer *v35; // rdi
  unsigned __int16 v36; // ax
  bool v37; // al
  bool v38; // zf
  unsigned int v40; // [rsp+40h] [rbp-B8h]
  unsigned int v41; // [rsp+44h] [rbp-B4h]
  int v42; // [rsp+48h] [rbp-B0h]
  unsigned int in_uNumFramesa; // [rsp+100h] [rbp+8h]
  float *v44; // [rsp+108h] [rbp+10h]
  unsigned int v45; // [rsp+110h] [rbp+18h]
  bool v46; // [rsp+118h] [rbp+20h]
  bool in_fResamplingFactora; // [rsp+130h] [rbp+38h]

  v46 = in_bNoMoreData;
  v45 = in_uNumFrames;
  v44 = in_pfInBuf;
  v8 = this->m_TimeWindow.m_fCummulativeSum;
  v9 = this->m_uInputFramesToDiscard;
  in_fInterpLoc = (__m128)LODWORD(this->m_fInterpPos);
  v11 = this->m_uFFTSize;
  v12 = in_pfTempStorage;
  v13 = in_pfInBuf;
  v14 = this;
  v15 = 0;
  v16 = in_uNumFrames;
  v17 = in_fResamplingFactor;
  in_uNumFramesa = v11 >> 2;
  v18 = 0;
  v19 = 45;
  in_fResamplingFactora = this->m_bInitPhases;
  v40 = 0;
  v20 = 0;
LABEL_2:
  v41 = v19;
LABEL_3:
  v21 = i;
  while ( (v16 || v18 < in_uNumFrames) && v20 < 0x64 )
  {
    v22 = v20 + 1;
    v23 = v9;
    if ( v16 < v9 )
      v23 = v16;
    v42 = v22;
    v24 = 0;
    v9 -= v23;
    v25 = v16 - v23;
    v26 = v23 + v15;
    if ( v13 && v25 )
    {
      v27 = DSP::CAkResamplingCircularBuffer::PushFrames(
              &v14->m_ResamplingInputAccumBuf[(unsigned int)v21],
              &v13[v26],
              v25,
              v17);
      in_bNoMoreData = v46;
      v24 = v27;
    }
    v15 = v24 + v26;
    v16 = v25 - (unsigned __int16)v24;
    if ( !v14->m_FreqWindow[0][v21 + 8i64 * (v14->m_uFreqWindowIndex[v21] & 1)].m_bReady
      && DSP::CAkCircularBuffer::ReadFrameBlock(
           (DSP::CAkCircularBuffer *)&v14->m_ResamplingInputAccumBuf[v21].m_uSize,
           v12,
           v11,
           in_bNoMoreData) )
    {
      DSP::CAkCircularBuffer::AdvanceFrames(
        (DSP::CAkCircularBuffer *)&v14->m_ResamplingInputAccumBuf[v21].m_uSize,
        in_uNumFramesa);
      DSP::CAkTimeWindow::Apply(&v14->m_TimeWindow, v12, v11, 1.0);
      DSP::AkFFTAllButterflies::CAkFreqWindow::Compute(
        (DSP::AkFFTAllButterflies::CAkFreqWindow *)v14 + v21 + 8i64 * (v14->m_uFreqWindowIndex[v21] & 1) + 29,
        v12,
        v11,
        v14->m_pFFTState);
      DSP::AkFFTAllButterflies::CAkFreqWindow::CartToPol((DSP::AkFFTAllButterflies::CAkFreqWindow *)v14 + v21 + 8i64 * (v14->m_uFreqWindowIndex[v21] & 1) + 29);
    }
    if ( !v14->m_FreqWindow[0][v21 + 8i64 * ((v14->m_uFreqWindowIndex[v21] - 1) & 1)].m_bReady
      && DSP::CAkCircularBuffer::ReadFrameBlock(
           (DSP::CAkCircularBuffer *)&v14->m_ResamplingInputAccumBuf[v21].m_uSize,
           v12,
           v11,
           v46) )
    {
      DSP::CAkCircularBuffer::AdvanceFrames(
        (DSP::CAkCircularBuffer *)&v14->m_ResamplingInputAccumBuf[v21].m_uSize,
        in_uNumFramesa);
      DSP::CAkTimeWindow::Apply(&v14->m_TimeWindow, v12, v11, 1.0);
      DSP::AkFFTAllButterflies::CAkFreqWindow::Compute(
        (DSP::AkFFTAllButterflies::CAkFreqWindow *)v14 + v21 + 8i64 * ((v14->m_uFreqWindowIndex[v21] - 1) & 1) + 29,
        v12,
        v11,
        v14->m_pFFTState);
      DSP::AkFFTAllButterflies::CAkFreqWindow::CartToPol((DSP::AkFFTAllButterflies::CAkFreqWindow *)v14 + v21 + 8i64 * ((v14->m_uFreqWindowIndex[v21] - 1) & 1) + 29);
    }
    v28 = v14->m_uFreqWindowIndex[v21];
    if ( v14->m_FreqWindow[0][v21 + 8i64 * ((v28 - 1) & 1)].m_bReady
      && v14->m_FreqWindow[0][v21 + 8i64 * (v28 & 1)].m_bReady
      && !v14->m_VocoderWindow[v21].m_bReady )
    {
      DSP::AkFFTAllButterflies::CAkFreqWindow::ComputeVocoderSpectrum(
        (DSP::AkFFTAllButterflies::CAkFreqWindow *)v14 + v21 + 45,
        *((DSP::AkPolar **)&v14->m_InputAccumBuf[0].m_uSize + 2 * (v21 + 8i64 * (v28 & 1) + 29)),
        *((DSP::AkPolar **)&v14->m_InputAccumBuf[0].m_uSize + 2 * (v21 + 8i64 * ((v28 - 1) & 1) + 29)),
        v14->m_pfPrevSynthesisPhase[v21],
        in_uNumFramesa,
        in_fInterpLoc.m128_f32[0],
        in_fResamplingFactora);
      in_fResamplingFactora = 0;
    }
    v29 = v21;
    if ( v14->m_VocoderWindow[v21].m_bReady )
    {
      if ( *(&v14->m_InputAccumBuf[0].m_uSize + 8 * (v21 + 6))
         - *(&v14->m_InputAccumBuf[0].m_uFramesReady + 8 * (v21 + 6)) >= v11 )
      {
        DSP::AkFFTAllButterflies::CAkFreqWindow::ConvertToTimeDomain(
          (DSP::AkFFTAllButterflies::CAkFreqWindow *)v14 + v21 + 45,
          in_pfTempStorage,
          v11,
          v14->m_pIFFTState);
        DSP::CAkTimeWindow::Apply(
          &v14->m_TimeWindow,
          in_pfTempStorage,
          v11,
          1.0 / (float)((float)(v8 * 4.0) / (float)(signed int)v11));
        DSP::CAkOLACircularBuffer::PushOverlappedWindow(
          (DSP::CAkOLACircularBuffer *)v14 + v21 + 6,
          in_pfTempStorage,
          in_uNumFramesa);
        v14->m_VocoderWindow[v29].m_bReady = 0;
        in_fInterpLoc.m128_f32[0] = in_fInterpLoc.m128_f32[0] + (float)(1.0 / v17);
        if ( in_fInterpLoc.m128_f32[0] >= 1.0 )
        {
          v30 = in_fInterpLoc.m128_f32[0];
          v14->m_FreqWindow[0][v21 + 8i64 * (v14->m_uFreqWindowIndex[v21] & 1)].m_bReady = 0;
          v31 = (signed int)in_fInterpLoc.m128_f32[0];
          if ( (signed int)in_fInterpLoc.m128_f32[0] != 0x80000000 && (float)v31 != in_fInterpLoc.m128_f32[0] )
            v30 = (float)(v31 - (_mm_movemask_ps(_mm_unpacklo_ps(in_fInterpLoc, in_fInterpLoc)) & 1));
          v32 = (signed int)v30;
          if ( (unsigned int)(signed int)v30 < 2 )
          {
            ++v14->m_uFreqWindowIndex[v21];
          }
          else
          {
            v33 = in_uNumFramesa * (v32 - 2);
            v14->m_FreqWindow[0][v21 + 8i64 * ((v14->m_uFreqWindowIndex[v21] - 1) & 1)].m_bReady = 0;
            v9 = v33
               - (unsigned __int64)DSP::CAkCircularBuffer::AdvanceFrames(
                                     (DSP::CAkCircularBuffer *)&v14->m_ResamplingInputAccumBuf[v21].m_uSize,
                                     in_uNumFramesa * (v32 - 2));
          }
          in_fInterpLoc.m128_f32[0] = in_fInterpLoc.m128_f32[0] - v30;
        }
      }
      v12 = in_pfTempStorage;
    }
    v34 = v46
       && !v14->m_ResamplingInputAccumBuf[v21].m_uFramesReady
       && !v14->m_VocoderWindow[v29].m_bReady
       && !v14->m_OLAOutCircBuf[v21].m_uFramesReady;
    v35 = (DSP::CAkOLACircularBuffer *)((char *)v14 + 32 * (v21 + 6));
    v36 = DSP::CAkOLACircularBuffer::PopFrames(v35, &io_pfOutBuf[v40], v45 - v40, v34);
    v20 = v42;
    in_bNoMoreData = v46;
    in_uNumFrames = v45;
    v13 = v44;
    v18 = v36 + v40;
    v19 = v41;
    v40 = v18;
    if ( !v34 )
      goto LABEL_3;
    v37 = DSP::CAkOLACircularBuffer::IsDoneTail(v35);
    v20 = v42;
    in_bNoMoreData = v46;
    v21 = i;
    v19 = v41;
    in_uNumFrames = v45;
    v13 = v44;
    v38 = v37 == 0;
    v18 = v40;
    if ( !v38 )
    {
      v19 = 17;
      goto LABEL_2;
    }
  }
  if ( (_DWORD)v21 == v14->m_uNumChannels - 1 )
  {
    LODWORD(v14->m_fInterpPos) = in_fInterpLoc.m128_i32[0];
    v14->m_uInputFramesToDiscard = v9;
    v14->m_bInitPhases = in_fResamplingFactora;
  }
  return v19;
} if ( (_DWORD)v21 == v14->m_uNumChannels - 1 )


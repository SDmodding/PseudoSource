// File Line: 27
// RVA: 0xAF8190
void __fastcall DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::ResetInputFill(
        DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder *this)
{
  unsigned int i; // ebx
  __int64 v3; // rdi

  for ( i = 0;
        i < this->m_uNumChannels;
        this->m_ResamplingInputAccumBuf[v3].m_uFramesReady = this->m_ResamplingInputAccumBuf[v3].m_uSize )
  {
    v3 = i;
    DSP::CAkResamplingCircularBuffer::Reset(&this->m_ResamplingInputAccumBuf[v3]);
    ++i;
  }
}

// File Line: 41
// RVA: 0xAF8200
__int64 __fastcall DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::Init(
        DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        unsigned int in_uNumChannels,
        unsigned int in_uSampleRate,
        unsigned int in_uFFTSize,
        bool in_bUseInputBuffer)
{
  int v8; // ebx
  __int64 result; // rax

  DSP::AkFFTAllButterflies::CAkPhaseVocoder::Init(
    this,
    in_pAllocator,
    in_uNumChannels,
    in_uSampleRate,
    in_uFFTSize,
    in_bUseInputBuffer);
  v8 = 0;
  if ( !this->m_uNumChannels )
    return 1i64;
  while ( 1 )
  {
    result = DSP::CAkCircularBuffer::Init(
               &this->m_ResamplingInputAccumBuf[v8],
               in_pAllocator,
               this->m_uFFTSize + (this->m_uFFTSize >> 2));
    if ( (_DWORD)result != 1 )
      break;
    if ( ++v8 >= this->m_uNumChannels )
      return 1i64;
  }
  return result;
}

// File Line: 53
// RVA: 0xAF82A0
void __fastcall DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::Term(
        DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  unsigned int i; // ebx

  for ( i = 0; i < this->m_uNumChannels; ++i )
    DSP::CAkCircularBuffer::Term(&this->m_ResamplingInputAccumBuf[i], in_pAllocator);
  DSP::AkFFTAllButterflies::CAkPhaseVocoder::Term(this, in_pAllocator);
}

// File Line: 60
// RVA: 0xAF8310
void __fastcall DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::Reset(
        DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder *this)
{
  unsigned int i; // ebx

  DSP::AkFFTAllButterflies::CAkPhaseVocoder::Reset(this);
  for ( i = 0; i < this->m_uNumChannels; ++i )
    DSP::CAkResamplingCircularBuffer::Reset(&this->m_ResamplingInputAccumBuf[i]);
}

// File Line: 84
// RVA: 0xAF8360
__int64 __fastcall DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder::ProcessPitchChannel(
        DSP::AkFFTAllButterflies::CAkResamplingPhaseVocoder *this,
        float *in_pfInBuf,
        unsigned int in_uNumFrames,
        bool in_bNoMoreData,
        unsigned int i,
        float *io_pfOutBuf,
        float in_fResamplingFactor,
        ak_fft_cpx *in_pfTempStorage)
{
  float m_fCummulativeSum; // xmm1_4
  unsigned int m_uInputFramesToDiscard; // r15d
  __m128 in_fInterpLoc; // xmm7
  unsigned int m_uFFTSize; // r12d
  ak_fft_cpx *v12; // r14
  float *v13; // r10
  int v15; // r13d
  unsigned int v16; // ebp
  unsigned int v18; // eax
  unsigned int v19; // edx
  unsigned int v20; // ecx
  __int64 v21; // rdi
  unsigned int v22; // ecx
  unsigned int v23; // eax
  unsigned int v24; // ecx
  unsigned int v25; // ebp
  __int64 v26; // r13
  unsigned int v27; // eax
  char v28; // cl
  __int64 v29; // rsi
  float v30; // xmm6_4
  int v31; // ecx
  bool v32; // si
  DSP::CAkOLACircularBuffer *v33; // rdi
  unsigned __int16 v34; // ax
  bool IsDoneTail; // al
  bool v36; // zf
  unsigned int v38; // [rsp+40h] [rbp-B8h]
  unsigned int v39; // [rsp+44h] [rbp-B4h]
  unsigned int v40; // [rsp+48h] [rbp-B0h]
  unsigned int in_uNumFramesa; // [rsp+100h] [rbp+8h]
  unsigned int v43; // [rsp+110h] [rbp+18h]
  bool v44; // [rsp+118h] [rbp+20h]
  bool in_fResamplingFactora; // [rsp+130h] [rbp+38h]

  v44 = in_bNoMoreData;
  v43 = in_uNumFrames;
  m_fCummulativeSum = this->m_TimeWindow.m_fCummulativeSum;
  m_uInputFramesToDiscard = this->m_uInputFramesToDiscard;
  in_fInterpLoc = (__m128)LODWORD(this->m_fInterpPos);
  m_uFFTSize = this->m_uFFTSize;
  v12 = in_pfTempStorage;
  v13 = in_pfInBuf;
  v15 = 0;
  v16 = in_uNumFrames;
  in_uNumFramesa = m_uFFTSize >> 2;
  v18 = 0;
  v19 = 45;
  in_fResamplingFactora = this->m_bInitPhases;
  v38 = 0;
  v20 = 0;
LABEL_2:
  v39 = v19;
LABEL_3:
  v21 = i;
  while ( (v16 || v18 < in_uNumFrames) && v20 < 0x64 )
  {
    v22 = v20 + 1;
    v23 = m_uInputFramesToDiscard;
    if ( v16 < m_uInputFramesToDiscard )
      v23 = v16;
    v40 = v22;
    v24 = 0;
    m_uInputFramesToDiscard -= v23;
    v25 = v16 - v23;
    v26 = v23 + v15;
    if ( v13 && v25 )
    {
      v27 = DSP::CAkResamplingCircularBuffer::PushFrames(
              &this->m_ResamplingInputAccumBuf[(unsigned int)v21],
              &v13[v26],
              v25,
              in_fResamplingFactor);
      in_bNoMoreData = v44;
      v24 = v27;
    }
    v15 = v24 + v26;
    v16 = v25 - (unsigned __int16)v24;
    if ( !this->m_FreqWindow[this->m_uFreqWindowIndex[v21] & 1][v21].m_bReady
      && DSP::CAkCircularBuffer::ReadFrameBlock(
           &this->m_ResamplingInputAccumBuf[v21],
           (float *)v12,
           m_uFFTSize,
           in_bNoMoreData) )
    {
      DSP::CAkCircularBuffer::AdvanceFrames(&this->m_ResamplingInputAccumBuf[v21], in_uNumFramesa);
      DSP::CAkTimeWindow::Apply(&this->m_TimeWindow, (float *)v12, m_uFFTSize, 1.0);
      DSP::AkFFTAllButterflies::CAkFreqWindow::Compute(
        &this->m_FreqWindow[this->m_uFreqWindowIndex[v21] & 1][v21],
        v12,
        m_uFFTSize,
        this->m_pFFTState);
      DSP::AkFFTAllButterflies::CAkFreqWindow::CartToPol(&this->m_FreqWindow[this->m_uFreqWindowIndex[v21] & 1][v21]);
    }
    if ( !this->m_FreqWindow[(this->m_uFreqWindowIndex[v21] - 1) & 1][v21].m_bReady
      && DSP::CAkCircularBuffer::ReadFrameBlock(&this->m_ResamplingInputAccumBuf[v21], (float *)v12, m_uFFTSize, v44) )
    {
      DSP::CAkCircularBuffer::AdvanceFrames(&this->m_ResamplingInputAccumBuf[v21], in_uNumFramesa);
      DSP::CAkTimeWindow::Apply(&this->m_TimeWindow, (float *)v12, m_uFFTSize, 1.0);
      DSP::AkFFTAllButterflies::CAkFreqWindow::Compute(
        &this->m_FreqWindow[(this->m_uFreqWindowIndex[v21] - 1) & 1][v21],
        v12,
        m_uFFTSize,
        this->m_pFFTState);
      DSP::AkFFTAllButterflies::CAkFreqWindow::CartToPol(&this->m_FreqWindow[(this->m_uFreqWindowIndex[v21] - 1) & 1][v21]);
    }
    v28 = this->m_uFreqWindowIndex[v21];
    if ( this->m_FreqWindow[(v28 - 1) & 1][v21].m_bReady
      && this->m_FreqWindow[v28 & 1][v21].m_bReady
      && !this->m_VocoderWindow[v21].m_bReady )
    {
      DSP::AkFFTAllButterflies::CAkFreqWindow::ComputeVocoderSpectrum(
        &this->m_VocoderWindow[v21],
        (DSP::AkPolar *)this->m_FreqWindow[v28 & 1][v21].m_pfFreqData,
        (DSP::AkPolar *)this->m_FreqWindow[(v28 - 1) & 1][v21].m_pfFreqData,
        this->m_pfPrevSynthesisPhase[v21],
        in_uNumFramesa,
        in_fInterpLoc.m128_f32[0],
        in_fResamplingFactora);
      in_fResamplingFactora = 0;
    }
    v29 = v21;
    if ( this->m_VocoderWindow[v21].m_bReady )
    {
      if ( this->m_OLAOutCircBuf[v21].m_uSize - this->m_OLAOutCircBuf[v21].m_uFramesReady >= m_uFFTSize )
      {
        DSP::AkFFTAllButterflies::CAkFreqWindow::ConvertToTimeDomain(
          &this->m_VocoderWindow[v21],
          in_pfTempStorage,
          m_uFFTSize,
          this->m_pIFFTState);
        DSP::CAkTimeWindow::Apply(
          &this->m_TimeWindow,
          (float *)in_pfTempStorage,
          m_uFFTSize,
          1.0 / (float)((float)(m_fCummulativeSum * 4.0) / (float)(int)m_uFFTSize));
        DSP::CAkOLACircularBuffer::PushOverlappedWindow(
          &this->m_OLAOutCircBuf[v21],
          (float *)in_pfTempStorage,
          in_uNumFramesa);
        this->m_VocoderWindow[v29].m_bReady = 0;
        in_fInterpLoc.m128_f32[0] = in_fInterpLoc.m128_f32[0] + (float)(1.0 / in_fResamplingFactor);
        if ( in_fInterpLoc.m128_f32[0] >= 1.0 )
        {
          v30 = in_fInterpLoc.m128_f32[0];
          this->m_FreqWindow[this->m_uFreqWindowIndex[v21] & 1][v21].m_bReady = 0;
          v31 = (int)in_fInterpLoc.m128_f32[0];
          if ( (int)in_fInterpLoc.m128_f32[0] != 0x80000000 && (float)v31 != in_fInterpLoc.m128_f32[0] )
            v30 = (float)(v31 - (_mm_movemask_ps(_mm_unpacklo_ps(in_fInterpLoc, in_fInterpLoc)) & 1));
          if ( (unsigned int)(int)v30 < 2 )
          {
            ++this->m_uFreqWindowIndex[v21];
          }
          else
          {
            this->m_FreqWindow[(this->m_uFreqWindowIndex[v21] - 1) & 1][v21].m_bReady = 0;
            m_uInputFramesToDiscard = in_uNumFramesa * ((int)v30 - 2)
                                    - DSP::CAkCircularBuffer::AdvanceFrames(
                                        &this->m_ResamplingInputAccumBuf[v21],
                                        in_uNumFramesa * ((int)v30 - 2));
          }
          in_fInterpLoc.m128_f32[0] = in_fInterpLoc.m128_f32[0] - v30;
        }
      }
      v12 = in_pfTempStorage;
    }
    v32 = v44
       && !this->m_ResamplingInputAccumBuf[v21].m_uFramesReady
       && !this->m_VocoderWindow[v29].m_bReady
       && !this->m_OLAOutCircBuf[v21].m_uFramesReady;
    v33 = &this->m_OLAOutCircBuf[v21];
    v34 = DSP::CAkOLACircularBuffer::PopFrames(v33, &io_pfOutBuf[v38], v43 - v38, v32);
    v20 = v40;
    in_bNoMoreData = v44;
    in_uNumFrames = v43;
    v13 = in_pfInBuf;
    v18 = v34 + v38;
    v19 = v39;
    v38 = v18;
    if ( !v32 )
      goto LABEL_3;
    IsDoneTail = DSP::CAkOLACircularBuffer::IsDoneTail(v33);
    v20 = v40;
    in_bNoMoreData = v44;
    v21 = i;
    v19 = v39;
    in_uNumFrames = v43;
    v13 = in_pfInBuf;
    v36 = !IsDoneTail;
    v18 = v38;
    if ( !v36 )
    {
      v19 = 17;
      goto LABEL_2;
    }
  }
  if ( (_DWORD)v21 == this->m_uNumChannels - 1 )
  {
    LODWORD(this->m_fInterpPos) = in_fInterpLoc.m128_i32[0];
    this->m_uInputFramesToDiscard = m_uInputFramesToDiscard;
    this->m_bInitPhases = in_fResamplingFactora;
  }
  return v19;
}


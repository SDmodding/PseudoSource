// File Line: 31
// RVA: 0xAED6F0
void __fastcall DSP::AkFFTAllButterflies::CAkPhaseVocoder::CAkPhaseVocoder(
        DSP::AkFFTAllButterflies::CAkPhaseVocoder *this)
{
  bool *p_m_bReady; // rax
  int v2; // edx

  p_m_bReady = &this->m_FreqWindow[0][0].m_bReady;
  *(_QWORD *)&this->m_InputAccumBuf[0].m_uSize = 0i64;
  *(_QWORD *)&this->m_InputAccumBuf[0].m_uReadOffset = 0i64;
  this->m_InputAccumBuf[0].m_pfData = 0i64;
  *(_QWORD *)&this->m_InputAccumBuf[1].m_uSize = 0i64;
  *(_QWORD *)&this->m_InputAccumBuf[1].m_uReadOffset = 0i64;
  this->m_InputAccumBuf[1].m_pfData = 0i64;
  *(_QWORD *)&this->m_InputAccumBuf[2].m_uSize = 0i64;
  *(_QWORD *)&this->m_InputAccumBuf[2].m_uReadOffset = 0i64;
  this->m_InputAccumBuf[2].m_pfData = 0i64;
  *(_QWORD *)&this->m_InputAccumBuf[3].m_uSize = 0i64;
  *(_QWORD *)&this->m_InputAccumBuf[3].m_uReadOffset = 0i64;
  this->m_InputAccumBuf[3].m_pfData = 0i64;
  *(_QWORD *)&this->m_InputAccumBuf[4].m_uSize = 0i64;
  *(_QWORD *)&this->m_InputAccumBuf[4].m_uReadOffset = 0i64;
  this->m_InputAccumBuf[4].m_pfData = 0i64;
  *(_QWORD *)&this->m_InputAccumBuf[5].m_uSize = 0i64;
  *(_QWORD *)&this->m_InputAccumBuf[5].m_uReadOffset = 0i64;
  this->m_InputAccumBuf[5].m_pfData = 0i64;
  *(_QWORD *)&this->m_InputAccumBuf[6].m_uSize = 0i64;
  *(_QWORD *)&this->m_InputAccumBuf[6].m_uReadOffset = 0i64;
  this->m_InputAccumBuf[6].m_pfData = 0i64;
  *(_QWORD *)&this->m_InputAccumBuf[7].m_uSize = 0i64;
  *(_QWORD *)&this->m_InputAccumBuf[7].m_uReadOffset = 0i64;
  this->m_InputAccumBuf[7].m_pfData = 0i64;
  *(_QWORD *)&this->m_OLAOutCircBuf[0].m_uSize = 0i64;
  *(_QWORD *)&this->m_OLAOutCircBuf[0].m_uReadOffset = 0i64;
  this->m_OLAOutCircBuf[0].m_pfData = 0i64;
  this->m_OLAOutCircBuf[0].m_uWindowSize = 0;
  *(_QWORD *)&this->m_OLAOutCircBuf[1].m_uSize = 0i64;
  *(_QWORD *)&this->m_OLAOutCircBuf[1].m_uReadOffset = 0i64;
  this->m_OLAOutCircBuf[1].m_pfData = 0i64;
  this->m_OLAOutCircBuf[1].m_uWindowSize = 0;
  *(_QWORD *)&this->m_OLAOutCircBuf[2].m_uSize = 0i64;
  *(_QWORD *)&this->m_OLAOutCircBuf[2].m_uReadOffset = 0i64;
  this->m_OLAOutCircBuf[2].m_pfData = 0i64;
  this->m_OLAOutCircBuf[2].m_uWindowSize = 0;
  *(_QWORD *)&this->m_OLAOutCircBuf[3].m_uSize = 0i64;
  *(_QWORD *)&this->m_OLAOutCircBuf[3].m_uReadOffset = 0i64;
  this->m_OLAOutCircBuf[3].m_pfData = 0i64;
  this->m_OLAOutCircBuf[3].m_uWindowSize = 0;
  *(_QWORD *)&this->m_OLAOutCircBuf[4].m_uSize = 0i64;
  *(_QWORD *)&this->m_OLAOutCircBuf[4].m_uReadOffset = 0i64;
  this->m_OLAOutCircBuf[4].m_pfData = 0i64;
  this->m_OLAOutCircBuf[4].m_uWindowSize = 0;
  *(_QWORD *)&this->m_OLAOutCircBuf[5].m_uSize = 0i64;
  *(_QWORD *)&this->m_OLAOutCircBuf[5].m_uReadOffset = 0i64;
  this->m_OLAOutCircBuf[5].m_pfData = 0i64;
  this->m_OLAOutCircBuf[5].m_uWindowSize = 0;
  *(_QWORD *)&this->m_OLAOutCircBuf[6].m_uSize = 0i64;
  *(_QWORD *)&this->m_OLAOutCircBuf[6].m_uReadOffset = 0i64;
  this->m_OLAOutCircBuf[6].m_pfData = 0i64;
  this->m_OLAOutCircBuf[6].m_uWindowSize = 0;
  *(_QWORD *)&this->m_OLAOutCircBuf[7].m_uSize = 0i64;
  *(_QWORD *)&this->m_OLAOutCircBuf[7].m_uReadOffset = 0i64;
  this->m_OLAOutCircBuf[7].m_pfData = 0i64;
  this->m_OLAOutCircBuf[7].m_uWindowSize = 0;
  v2 = 15;
  this->m_TimeWindow.m_pfWindowData = 0i64;
  *(_QWORD *)&this->m_TimeWindow.m_uWindowSize = 0i64;
  do
  {
    --v2;
    *(_QWORD *)(p_m_bReady - 12) = 0i64;
    *((_DWORD *)p_m_bReady - 1) = 0;
    *(_WORD *)p_m_bReady = 0;
    p_m_bReady += 16;
  }
  while ( v2 >= 0 );
  this->m_VocoderWindow[0].m_pfFreqData = 0i64;
  this->m_VocoderWindow[0].m_uFFTSize = 0;
  *(_WORD *)&this->m_VocoderWindow[0].m_bReady = 0;
  this->m_VocoderWindow[1].m_pfFreqData = 0i64;
  this->m_VocoderWindow[1].m_uFFTSize = 0;
  *(_WORD *)&this->m_VocoderWindow[1].m_bReady = 0;
  this->m_VocoderWindow[2].m_pfFreqData = 0i64;
  this->m_VocoderWindow[2].m_uFFTSize = 0;
  *(_WORD *)&this->m_VocoderWindow[2].m_bReady = 0;
  this->m_VocoderWindow[3].m_pfFreqData = 0i64;
  this->m_VocoderWindow[3].m_uFFTSize = 0;
  *(_WORD *)&this->m_VocoderWindow[3].m_bReady = 0;
  this->m_VocoderWindow[4].m_pfFreqData = 0i64;
  this->m_VocoderWindow[4].m_uFFTSize = 0;
  *(_WORD *)&this->m_VocoderWindow[4].m_bReady = 0;
  this->m_VocoderWindow[5].m_pfFreqData = 0i64;
  this->m_VocoderWindow[5].m_uFFTSize = 0;
  *(_WORD *)&this->m_VocoderWindow[5].m_bReady = 0;
  this->m_VocoderWindow[6].m_pfFreqData = 0i64;
  this->m_VocoderWindow[6].m_uFFTSize = 0;
  *(_WORD *)&this->m_VocoderWindow[6].m_bReady = 0;
  this->m_VocoderWindow[7].m_pfFreqData = 0i64;
  this->m_VocoderWindow[7].m_uFFTSize = 0;
  *(_WORD *)&this->m_VocoderWindow[7].m_bReady = 0;
  this->m_pFFTState = 0i64;
  this->m_pIFFTState = 0i64;
  this->m_uNumChannels = 0;
  this->m_pfPrevSynthesisPhase[0] = 0i64;
  this->m_pfPrevSynthesisPhase[1] = 0i64;
  this->m_pfPrevSynthesisPhase[2] = 0i64;
  this->m_pfPrevSynthesisPhase[3] = 0i64;
  this->m_pfPrevSynthesisPhase[4] = 0i64;
  this->m_pfPrevSynthesisPhase[5] = 0i64;
  this->m_pfPrevSynthesisPhase[6] = 0i64;
  this->m_pfPrevSynthesisPhase[7] = 0i64;
}

// File Line: 39
// RVA: 0xAED990
void __fastcall DSP::AkFFTAllButterflies::CAkPhaseVocoder::~CAkPhaseVocoder(
        DSP::AkFFTAllButterflies::CAkPhaseVocoder *this)
{
  ;
}

// File Line: 50
// RVA: 0xAED9A0
AKRESULT __fastcall DSP::AkFFTAllButterflies::CAkPhaseVocoder::Init(
        DSP::AkFFTAllButterflies::CAkPhaseVocoder *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        unsigned int in_uNumChannels,
        unsigned int in_uSampleRate,
        unsigned int in_uFFTSize,
        bool in_bUseInputBuffer)
{
  ak_fftr_state *v8; // rax
  AKRESULT result; // eax
  ak_fftr_state *v10; // rax
  __int64 v11; // rsi
  unsigned int v12; // r14d
  __int64 v13; // rbp
  float *v14; // rax

  this->m_uSampleRate = in_uSampleRate;
  this->m_uNumChannels = in_uNumChannels;
  this->m_uFFTSize = in_uFFTSize;
  DSP::AkFFTAllButterflies::ak_fftr_alloc(in_uFFTSize, 0, 0i64, &this->m_uFFTSpaceRequirements);
  v8 = (ak_fftr_state *)in_pAllocator->vfptr->Malloc(in_pAllocator, this->m_uFFTSpaceRequirements);
  this->m_pFFTState = v8;
  if ( !v8 )
    return 52;
  DSP::AkFFTAllButterflies::ak_fftr_alloc(this->m_uFFTSize, 1, 0i64, &this->m_uIFFTSpaceRequirements);
  v10 = (ak_fftr_state *)in_pAllocator->vfptr->Malloc(in_pAllocator, this->m_uIFFTSpaceRequirements);
  this->m_pIFFTState = v10;
  if ( !v10 )
    return 52;
  DSP::AkFFTAllButterflies::ak_fftr_alloc(this->m_uFFTSize, 0, this->m_pFFTState, &this->m_uFFTSpaceRequirements);
  DSP::AkFFTAllButterflies::ak_fftr_alloc(this->m_uFFTSize, 1, this->m_pIFFTState, &this->m_uIFFTSpaceRequirements);
  result = DSP::CAkTimeWindow::Init(&this->m_TimeWindow, in_pAllocator, this->m_uFFTSize, WINDOWTYPE_HANN, 1, 0);
  if ( result == AK_Success )
  {
    v11 = 0i64;
    v12 = 0;
    if ( this->m_uNumChannels )
    {
      while ( 1 )
      {
        v13 = v12;
        result = DSP::AkFFTAllButterflies::CAkFreqWindow::Alloc(
                   &this->m_FreqWindow[0][v12],
                   in_pAllocator,
                   this->m_uFFTSize);
        if ( result != AK_Success )
          break;
        result = DSP::AkFFTAllButterflies::CAkFreqWindow::Alloc(
                   &this->m_FreqWindow[1][v12],
                   in_pAllocator,
                   this->m_uFFTSize);
        if ( result != AK_Success )
          break;
        result = DSP::AkFFTAllButterflies::CAkFreqWindow::Alloc(
                   &this->m_VocoderWindow[v12],
                   in_pAllocator,
                   this->m_uFFTSize);
        if ( result != AK_Success )
          break;
        v14 = (float *)in_pAllocator->vfptr->Malloc(in_pAllocator, 4i64 * ((this->m_uFFTSize >> 1) + 1));
        this->m_pfPrevSynthesisPhase[v12] = v14;
        if ( !v14 )
          return 52;
        ++v12;
        this->m_uFreqWindowIndex[v13] = 0;
        if ( v12 >= this->m_uNumChannels )
          goto LABEL_12;
      }
    }
    else
    {
LABEL_12:
      this->m_bUseInputBuffer = in_bUseInputBuffer;
      if ( this->m_uNumChannels )
      {
        while ( 1 )
        {
          if ( in_bUseInputBuffer )
          {
            result = DSP::CAkCircularBuffer::Init(
                       &this->m_InputAccumBuf[v11],
                       in_pAllocator,
                       this->m_uFFTSize + (this->m_uFFTSize >> 2));
            if ( result != AK_Success )
              break;
          }
          result = DSP::CAkOLACircularBuffer::Init(
                     &this->m_OLAOutCircBuf[(unsigned int)v11],
                     in_pAllocator,
                     this->m_uFFTSize,
                     this->m_uFFTSize);
          if ( result != AK_Success )
            break;
          v11 = (unsigned int)(v11 + 1);
          if ( (unsigned int)v11 >= this->m_uNumChannels )
            return 1;
        }
      }
      else
      {
        return 1;
      }
    }
  }
  return result;
}

// File Line: 124
// RVA: 0xAEDC20
void __fastcall DSP::AkFFTAllButterflies::CAkPhaseVocoder::Term(
        DSP::AkFFTAllButterflies::CAkPhaseVocoder *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  DSP::AkFFTAllButterflies::CAkPhaseVocoder *v3; // rdi
  bool *p_m_bUseInputBuffer; // r12
  float **m_pfPrevSynthesisPhase; // rsi
  DSP::CAkCircularBuffer *m_OLAOutCircBuf; // r14
  DSP::AkFFTAllButterflies::CAkFreqWindow *v7; // rbp
  __int64 v8; // r15

  v3 = this;
  if ( this->m_pFFTState )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    v3->m_pFFTState = 0i64;
  }
  if ( v3->m_pIFFTState )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    v3->m_pIFFTState = 0i64;
  }
  DSP::CAkTimeWindow::Term(&v3->m_TimeWindow, in_pAllocator);
  p_m_bUseInputBuffer = &v3->m_bUseInputBuffer;
  m_pfPrevSynthesisPhase = v3->m_pfPrevSynthesisPhase;
  m_OLAOutCircBuf = v3->m_OLAOutCircBuf;
  v7 = v3->m_FreqWindow[1];
  v8 = 8i64;
  do
  {
    DSP::AkFFTAllButterflies::CAkFreqWindow::Free(v7 - 8, in_pAllocator);
    DSP::AkFFTAllButterflies::CAkFreqWindow::Free(v7, in_pAllocator);
    DSP::AkFFTAllButterflies::CAkFreqWindow::Free(v7 + 8, in_pAllocator);
    if ( *p_m_bUseInputBuffer )
      DSP::CAkCircularBuffer::Term(v3->m_InputAccumBuf, in_pAllocator);
    DSP::CAkCircularBuffer::Term(m_OLAOutCircBuf, in_pAllocator);
    if ( *m_pfPrevSynthesisPhase )
    {
      ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
      *m_pfPrevSynthesisPhase = 0i64;
    }
    ++v7;
    m_OLAOutCircBuf = (DSP::CAkCircularBuffer *)((char *)m_OLAOutCircBuf + 32);
    v3 = (DSP::AkFFTAllButterflies::CAkPhaseVocoder *)((char *)v3 + 24);
    ++m_pfPrevSynthesisPhase;
    --v8;
  }
  while ( v8 );
}

// File Line: 153
// RVA: 0xAEDD40
void __fastcall DSP::AkFFTAllButterflies::CAkPhaseVocoder::Reset(DSP::AkFFTAllButterflies::CAkPhaseVocoder *this)
{
  __int64 i; // rsi
  __int64 v3; // rax
  float *v4; // rcx

  for ( i = 0i64; (unsigned int)i < this->m_uNumChannels; i = (unsigned int)(i + 1) )
  {
    v3 = (unsigned int)i;
    this->m_FreqWindow[0][v3].m_bReady = 0;
    this->m_FreqWindow[1][v3].m_bReady = 0;
    this->m_VocoderWindow[v3].m_bReady = 0;
    if ( this->m_bUseInputBuffer )
      DSP::CAkCircularBuffer::Reset(&this->m_InputAccumBuf[i]);
    DSP::CAkCircularBuffer::Reset(&this->m_OLAOutCircBuf[i]);
    v4 = this->m_pfPrevSynthesisPhase[i];
    if ( v4 )
      memset(v4, 0, 4 * (this->m_uFFTSize >> 1) + 4);
  }
  *(_QWORD *)&this->m_fInterpPos = 0i64;
  *(_WORD *)&this->m_bInitPhases = 257;
}

// File Line: 189
// RVA: 0xAEDE00
void __fastcall DSP::AkFFTAllButterflies::CAkPhaseVocoder::Execute(
        DSP::AkFFTAllButterflies::CAkPhaseVocoder *this,
        AkAudioBuffer *io_pInBuffer,
        unsigned int in_uInOffset,
        AkAudioBuffer *io_pOutBuffer,
        float in_fTSFactor,
        bool in_bEnterNoTSMode,
        float *in_pfTempStorage)
{
  unsigned int v8; // ecx
  AkAudioBuffer *v9; // r15
  unsigned int v10; // r10d
  AkAudioBuffer *v11; // rbp
  int m_uFFTSize; // esi
  float v13; // xmm9_4
  float v14; // xmm10_4
  unsigned int v15; // r9d
  __m128 in_fInterpLoc; // xmm7
  bool m_bInputStartFill; // r8
  unsigned int uValidFrames; // r14d
  unsigned int m_uInputFramesToDiscard; // r13d
  __int64 v20; // rdi
  unsigned int v21; // r12d
  unsigned __int64 v22; // rdx
  unsigned int v23; // eax
  __int64 v24; // r12
  DSP::CAkCircularBuffer *v25; // r15
  unsigned int v26; // eax
  bool v27; // r12
  char v28; // cl
  float v29; // xmm6_4
  int v30; // ecx
  bool v31; // si
  bool IsDoneTail; // al
  bool v33; // zf
  unsigned int in_uNumFrames; // [rsp+40h] [rbp-C8h]
  unsigned int v35; // [rsp+44h] [rbp-C4h]
  unsigned int v36; // [rsp+48h] [rbp-C0h]
  unsigned int v37; // [rsp+50h] [rbp-B8h]
  unsigned __int64 v38; // [rsp+58h] [rbp-B0h]
  unsigned __int64 v39; // [rsp+60h] [rbp-A8h]
  unsigned int v40; // [rsp+110h] [rbp+8h]
  bool in_fTSFactora; // [rsp+130h] [rbp+28h]
  bool in_bEnterNoTSModea; // [rsp+138h] [rbp+30h]

  v8 = 0;
  v9 = io_pOutBuffer;
  v10 = in_uInOffset;
  v11 = io_pInBuffer;
  if ( in_bEnterNoTSMode )
  {
    this->m_fInterpPos = 0.0;
    this->m_bInitPhases = 1;
  }
  m_uFFTSize = this->m_uFFTSize;
  v36 = 0;
  v37 = m_uFFTSize;
  v13 = 100.0 / in_fTSFactor;
  in_uNumFrames = (unsigned int)m_uFFTSize >> 2;
  v14 = 1.0 / (float)((float)(this->m_TimeWindow.m_fCummulativeSum * 4.0) / (float)m_uFFTSize);
  do
  {
    LOWORD(v15) = v9->uValidFrames;
    in_fInterpLoc = (__m128)LODWORD(this->m_fInterpPos);
    m_bInputStartFill = this->m_bInputStartFill;
    uValidFrames = v11->uValidFrames;
    m_uInputFramesToDiscard = this->m_uInputFramesToDiscard;
    v20 = v8;
    in_bEnterNoTSModea = this->m_bInitPhases;
    v40 = (unsigned __int16)v15;
    v21 = v10;
    in_fTSFactora = m_bInputStartFill;
    v22 = (unsigned __int64)v11->pData + 4 * v8 * (unsigned __int64)v11->uMaxFrames;
    v38 = v22;
    v39 = (unsigned __int64)v9->pData + 4 * v8 * (unsigned __int64)v9->uMaxFrames;
    while ( 1 )
    {
      v23 = m_uInputFramesToDiscard;
      if ( uValidFrames < m_uInputFramesToDiscard )
        v23 = uValidFrames;
      m_uInputFramesToDiscard -= v23;
      uValidFrames -= v23;
      v24 = v23 + v21;
      if ( m_bInputStartFill && !uValidFrames && v11->eState != AK_NoMoreData )
      {
LABEL_52:
        v9->eState = AK_DataNeeded;
        goto LABEL_55;
      }
      v25 = &this->m_InputAccumBuf[v20];
      v26 = DSP::CAkCircularBuffer::PushFrames(v25, (float *)(v22 + 4 * v24), uValidFrames);
      m_bInputStartFill = in_fTSFactora;
      if ( v25->m_uSize == v25->m_uFramesReady )
        m_bInputStartFill = 0;
      uValidFrames -= (unsigned __int16)v26;
      in_fTSFactora = m_bInputStartFill;
      v35 = v26 + v24;
      if ( !m_bInputStartFill || v25->m_uSize == v25->m_uFramesReady || uValidFrames )
      {
        if ( v11->eState != AK_NoMoreData || uValidFrames )
        {
          v27 = 0;
          goto LABEL_21;
        }
      }
      else if ( v11->eState != AK_NoMoreData )
      {
        v9 = io_pOutBuffer;
        LOWORD(v15) = v40;
        io_pOutBuffer->eState = AK_DataNeeded;
        goto LABEL_55;
      }
      v27 = 1;
LABEL_21:
      if ( !this->m_FreqWindow[this->m_uFreqWindowIndex[v20] & 1][v20].m_bReady
        && DSP::CAkCircularBuffer::ReadFrameBlock(&this->m_InputAccumBuf[v20], in_pfTempStorage, m_uFFTSize, v27) )
      {
        DSP::CAkCircularBuffer::AdvanceFrames(&this->m_InputAccumBuf[v20], in_uNumFrames);
        DSP::CAkTimeWindow::Apply(&this->m_TimeWindow, in_pfTempStorage, m_uFFTSize, 1.0);
        DSP::AkFFTAllButterflies::CAkFreqWindow::Compute(
          &this->m_FreqWindow[this->m_uFreqWindowIndex[v20] & 1][v20],
          in_pfTempStorage,
          m_uFFTSize,
          this->m_pFFTState);
        DSP::AkFFTAllButterflies::CAkFreqWindow::CartToPol(&this->m_FreqWindow[this->m_uFreqWindowIndex[v20] & 1][v20]);
      }
      if ( !this->m_FreqWindow[(this->m_uFreqWindowIndex[v20] - 1) & 1][v20].m_bReady
        && DSP::CAkCircularBuffer::ReadFrameBlock(&this->m_InputAccumBuf[v20], in_pfTempStorage, m_uFFTSize, v27) )
      {
        DSP::CAkCircularBuffer::AdvanceFrames(&this->m_InputAccumBuf[v20], in_uNumFrames);
        DSP::CAkTimeWindow::Apply(&this->m_TimeWindow, in_pfTempStorage, m_uFFTSize, 1.0);
        DSP::AkFFTAllButterflies::CAkFreqWindow::Compute(
          &this->m_FreqWindow[(this->m_uFreqWindowIndex[v20] - 1) & 1][v20],
          in_pfTempStorage,
          m_uFFTSize,
          this->m_pFFTState);
        DSP::AkFFTAllButterflies::CAkFreqWindow::CartToPol(&this->m_FreqWindow[(this->m_uFreqWindowIndex[v20] - 1) & 1][v20]);
      }
      v28 = this->m_uFreqWindowIndex[v20];
      if ( this->m_FreqWindow[(v28 - 1) & 1][v20].m_bReady
        && this->m_FreqWindow[v28 & 1][v20].m_bReady
        && !this->m_VocoderWindow[v20].m_bReady )
      {
        DSP::AkFFTAllButterflies::CAkFreqWindow::ComputeVocoderSpectrum(
          &this->m_VocoderWindow[v20],
          (DSP::AkPolar *)this->m_FreqWindow[v28 & 1][v20].m_pfFreqData,
          (DSP::AkPolar *)this->m_FreqWindow[(v28 - 1) & 1][v20].m_pfFreqData,
          this->m_pfPrevSynthesisPhase[v20],
          in_uNumFrames,
          in_fInterpLoc.m128_f32[0],
          in_bEnterNoTSModea);
        in_bEnterNoTSModea = 0;
      }
      if ( this->m_VocoderWindow[v20].m_bReady
        && this->m_OLAOutCircBuf[v20].m_uSize - this->m_OLAOutCircBuf[v20].m_uFramesReady >= v37 )
      {
        DSP::AkFFTAllButterflies::CAkFreqWindow::ConvertToTimeDomain(
          &this->m_VocoderWindow[v20],
          in_pfTempStorage,
          v37,
          this->m_pIFFTState);
        DSP::CAkTimeWindow::Apply(&this->m_TimeWindow, in_pfTempStorage, v37, v14);
        DSP::CAkOLACircularBuffer::PushOverlappedWindow(&this->m_OLAOutCircBuf[v20], in_pfTempStorage, in_uNumFrames);
        this->m_VocoderWindow[v20].m_bReady = 0;
        in_fInterpLoc.m128_f32[0] = in_fInterpLoc.m128_f32[0] + v13;
        if ( in_fInterpLoc.m128_f32[0] >= 1.0 )
        {
          v29 = in_fInterpLoc.m128_f32[0];
          this->m_FreqWindow[this->m_uFreqWindowIndex[v20] & 1][v20].m_bReady = 0;
          v30 = (int)in_fInterpLoc.m128_f32[0];
          if ( (int)in_fInterpLoc.m128_f32[0] != 0x80000000 && (float)v30 != in_fInterpLoc.m128_f32[0] )
            v29 = (float)(v30 - (_mm_movemask_ps(_mm_unpacklo_ps(in_fInterpLoc, in_fInterpLoc)) & 1));
          if ( (unsigned int)(int)v29 < 2 )
          {
            ++this->m_uFreqWindowIndex[v20];
          }
          else
          {
            this->m_FreqWindow[(this->m_uFreqWindowIndex[v20] - 1) & 1][v20].m_bReady = 0;
            m_uInputFramesToDiscard = in_uNumFrames * ((int)v29 - 2)
                                    - DSP::CAkCircularBuffer::AdvanceFrames(
                                        &this->m_InputAccumBuf[v20],
                                        in_uNumFrames * ((int)v29 - 2));
          }
          in_fInterpLoc.m128_f32[0] = in_fInterpLoc.m128_f32[0] - v29;
        }
      }
      v31 = v27
         && !v25->m_uFramesReady
         && !this->m_VocoderWindow[v20].m_bReady
         && !this->m_OLAOutCircBuf[v20].m_uFramesReady;
      v9 = io_pOutBuffer;
      v15 = (unsigned __int16)DSP::CAkOLACircularBuffer::PopFrames(
                                &this->m_OLAOutCircBuf[v20],
                                (float *)(v39 + 4i64 * v40),
                                io_pOutBuffer->uMaxFrames - v40,
                                v31)
          + v40;
      v40 = v15;
      if ( v31 )
      {
        IsDoneTail = DSP::CAkOLACircularBuffer::IsDoneTail(&this->m_OLAOutCircBuf[v20]);
        v15 = v40;
        if ( IsDoneTail )
        {
          m_uFFTSize = v37;
          v11 = io_pInBuffer;
          m_bInputStartFill = in_fTSFactora;
          io_pOutBuffer->eState = AK_NoMoreData;
          goto LABEL_55;
        }
      }
      m_uFFTSize = v37;
      v11 = io_pInBuffer;
      m_bInputStartFill = in_fTSFactora;
      if ( v15 == io_pOutBuffer->uMaxFrames )
        break;
      v22 = v38;
      v33 = !v27;
      v21 = v35;
      if ( v33 && !uValidFrames )
        goto LABEL_52;
    }
    io_pOutBuffer->eState = AK_DataReady;
LABEL_55:
    v10 = in_uInOffset;
    v8 = v36 + 1;
    v36 = v8;
  }
  while ( v8 < this->m_uNumChannels );
  v11->uValidFrames = uValidFrames;
  v9->uValidFrames = v15;
  this->m_bInitPhases = in_bEnterNoTSModea;
  this->m_uInputFramesToDiscard = m_uInputFramesToDiscard;
  LODWORD(this->m_fInterpPos) = in_fInterpLoc.m128_i32[0];
  this->m_bInputStartFill = m_bInputStartFill;
}


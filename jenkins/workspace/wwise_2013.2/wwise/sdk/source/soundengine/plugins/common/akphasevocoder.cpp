// File Line: 31
// RVA: 0xAED6F0
void __fastcall DSP::AkFFTAllButterflies::CAkPhaseVocoder::CAkPhaseVocoder(DSP::AkFFTAllButterflies::CAkPhaseVocoder *this)
{
  bool *v1; // rax
  signed int v2; // edx

  v1 = &this->m_FreqWindow[0][0].m_bReady;
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
    *(_QWORD *)(v1 - 12) = 0i64;
    *((_DWORD *)v1 - 1) = 0;
    *(_WORD *)v1 = 0;
    v1 += 16;
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
void __fastcall DSP::AkFFTAllButterflies::CAkPhaseVocoder::~CAkPhaseVocoder(DSP::AkFFTAllButterflies::CAkPhaseVocoder *this)
{
  ;
}

// File Line: 50
// RVA: 0xAED9A0
AKRESULT __fastcall DSP::AkFFTAllButterflies::CAkPhaseVocoder::Init(DSP::AkFFTAllButterflies::CAkPhaseVocoder *this, AK::IAkPluginMemAlloc *in_pAllocator, unsigned int in_uNumChannels, unsigned int in_uSampleRate, unsigned int in_uFFTSize, bool in_bUseInputBuffer)
{
  DSP::AkFFTAllButterflies::CAkPhaseVocoder *v6; // rbx
  AK::IAkPluginMemAlloc *v7; // rdi
  __int64 v8; // rax
  AKRESULT result; // eax
  __int64 v10; // rax
  __int64 v11; // rsi
  unsigned int v12; // er14
  __int64 v13; // rbp
  __int64 v14; // rax

  v6 = this;
  v7 = in_pAllocator;
  this->m_uSampleRate = in_uSampleRate;
  this->m_uNumChannels = in_uNumChannels;
  this->m_uFFTSize = in_uFFTSize;
  DSP::AkFFTAllButterflies::ak_fftr_alloc(in_uFFTSize, 0, 0i64, &this->m_uFFTSpaceRequirements);
  v8 = (__int64)v7->vfptr->Malloc(v7, v6->m_uFFTSpaceRequirements);
  v6->m_pFFTState = (ak_fftr_state *)v8;
  if ( !v8 )
    return 52;
  DSP::AkFFTAllButterflies::ak_fftr_alloc(v6->m_uFFTSize, 1, 0i64, &v6->m_uIFFTSpaceRequirements);
  v10 = (__int64)v7->vfptr->Malloc(v7, v6->m_uIFFTSpaceRequirements);
  v6->m_pIFFTState = (ak_fftr_state *)v10;
  if ( !v10 )
    return 52;
  DSP::AkFFTAllButterflies::ak_fftr_alloc(v6->m_uFFTSize, 0, v6->m_pFFTState, &v6->m_uFFTSpaceRequirements);
  DSP::AkFFTAllButterflies::ak_fftr_alloc(v6->m_uFFTSize, 1, v6->m_pIFFTState, &v6->m_uIFFTSpaceRequirements);
  result = DSP::CAkTimeWindow::Init(&v6->m_TimeWindow, v7, v6->m_uFFTSize, WINDOWTYPE_HANN, 1, 0);
  if ( result == 1 )
  {
    v11 = 0i64;
    v12 = 0;
    if ( v6->m_uNumChannels <= 0 )
    {
LABEL_12:
      v6->m_bUseInputBuffer = in_bUseInputBuffer;
      if ( v6->m_uNumChannels <= 0 )
      {
LABEL_17:
        result = 1;
      }
      else
      {
        while ( 1 )
        {
          if ( in_bUseInputBuffer )
          {
            result = DSP::CAkCircularBuffer::Init(&v6->m_InputAccumBuf[v11], v7, v6->m_uFFTSize + (v6->m_uFFTSize >> 2));
            if ( result != 1 )
              break;
          }
          result = DSP::CAkOLACircularBuffer::Init(
                     (DSP::CAkOLACircularBuffer *)v6 + (unsigned int)v11 + 6i64,
                     v7,
                     v6->m_uFFTSize,
                     v6->m_uFFTSize);
          if ( result != 1 )
            break;
          v11 = (unsigned int)(v11 + 1);
          if ( (unsigned int)v11 >= v6->m_uNumChannels )
            goto LABEL_17;
        }
      }
    }
    else
    {
      while ( 1 )
      {
        v13 = v12;
        result = DSP::AkFFTAllButterflies::CAkFreqWindow::Alloc(
                   (DSP::AkFFTAllButterflies::CAkFreqWindow *)v6 + v12 + 29i64,
                   v7,
                   v6->m_uFFTSize);
        if ( result != 1 )
          break;
        result = DSP::AkFFTAllButterflies::CAkFreqWindow::Alloc(
                   (DSP::AkFFTAllButterflies::CAkFreqWindow *)v6 + v12 + 37i64,
                   v7,
                   v6->m_uFFTSize);
        if ( result != 1 )
          break;
        result = DSP::AkFFTAllButterflies::CAkFreqWindow::Alloc(
                   (DSP::AkFFTAllButterflies::CAkFreqWindow *)v6 + v12 + 45i64,
                   v7,
                   v6->m_uFFTSize);
        if ( result != 1 )
          break;
        v14 = (__int64)v7->vfptr->Malloc(v7, 4i64 * ((v6->m_uFFTSize >> 1) + 1));
        v6->m_pfPrevSynthesisPhase[v12] = (float *)v14;
        if ( !v14 )
          return 52;
        ++v12;
        v6->m_uFreqWindowIndex[v13] = 0;
        if ( v12 >= v6->m_uNumChannels )
          goto LABEL_12;
      }
    }
  }
  return result;
}

// File Line: 124
// RVA: 0xAEDC20
void __fastcall DSP::AkFFTAllButterflies::CAkPhaseVocoder::Term(DSP::AkFFTAllButterflies::CAkPhaseVocoder *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rbx
  DSP::AkFFTAllButterflies::CAkPhaseVocoder *v3; // rdi
  bool *v4; // r12
  float **v5; // rsi
  DSP::CAkCircularBuffer *v6; // r14
  DSP::AkFFTAllButterflies::CAkFreqWindow *v7; // rbp
  signed __int64 v8; // r15

  v2 = in_pAllocator;
  v3 = this;
  if ( this->m_pFFTState )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    v3->m_pFFTState = 0i64;
  }
  if ( v3->m_pIFFTState )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))v2->vfptr->Free)(v2);
    v3->m_pIFFTState = 0i64;
  }
  DSP::CAkTimeWindow::Term(&v3->m_TimeWindow, v2);
  v4 = &v3->m_bUseInputBuffer;
  v5 = v3->m_pfPrevSynthesisPhase;
  v6 = (DSP::CAkCircularBuffer *)v3->m_OLAOutCircBuf;
  v7 = v3->m_FreqWindow[1];
  v8 = 8i64;
  do
  {
    DSP::AkFFTAllButterflies::CAkFreqWindow::Free(v7 - 8, v2);
    DSP::AkFFTAllButterflies::CAkFreqWindow::Free(v7, v2);
    DSP::AkFFTAllButterflies::CAkFreqWindow::Free(v7 + 8, v2);
    if ( *v4 )
      DSP::CAkCircularBuffer::Term(v3->m_InputAccumBuf, v2);
    DSP::CAkCircularBuffer::Term(v6, v2);
    if ( *v5 )
    {
      ((void (__fastcall *)(AK::IAkPluginMemAlloc *))v2->vfptr->Free)(v2);
      *v5 = 0i64;
    }
    ++v7;
    v6 = (DSP::CAkCircularBuffer *)((char *)v6 + 32);
    v3 = (DSP::AkFFTAllButterflies::CAkPhaseVocoder *)((char *)v3 + 24);
    ++v5;
    --v8;
  }
  while ( v8 );
}

// File Line: 153
// RVA: 0xAEDD40
void __fastcall DSP::AkFFTAllButterflies::CAkPhaseVocoder::Reset(DSP::AkFFTAllButterflies::CAkPhaseVocoder *this)
{
  __int64 v1; // rsi
  DSP::AkFFTAllButterflies::CAkPhaseVocoder *v2; // rbx
  signed __int64 v3; // rax
  float *v4; // rcx

  v1 = 0i64;
  v2 = this;
  if ( this->m_uNumChannels )
  {
    do
    {
      v3 = (unsigned int)v1;
      v2->m_FreqWindow[0][v3].m_bReady = 0;
      v2->m_FreqWindow[1][v3].m_bReady = 0;
      v2->m_VocoderWindow[v3].m_bReady = 0;
      if ( v2->m_bUseInputBuffer )
        DSP::CAkCircularBuffer::Reset(&v2->m_InputAccumBuf[v1]);
      DSP::CAkCircularBuffer::Reset((DSP::CAkCircularBuffer *)((char *)v2->m_InputAccumBuf + 32 * (v1 + 6)));
      v4 = v2->m_pfPrevSynthesisPhase[v1];
      if ( v4 )
        memset(v4, 0, 4 * (v2->m_uFFTSize >> 1) + 4);
      v1 = (unsigned int)(v1 + 1);
    }
    while ( (unsigned int)v1 < v2->m_uNumChannels );
  }
  *(_QWORD *)&v2->m_fInterpPos = 0i64;
  *(_WORD *)&v2->m_bInitPhases = 257;
}

// File Line: 189
// RVA: 0xAEDE00
void __fastcall DSP::AkFFTAllButterflies::CAkPhaseVocoder::Execute(DSP::AkFFTAllButterflies::CAkPhaseVocoder *this, AkAudioBuffer *io_pInBuffer, unsigned int in_uInOffset, AkAudioBuffer *io_pOutBuffer, float in_fTSFactor, bool in_bEnterNoTSMode, float *in_pfTempStorage)
{
  DSP::AkFFTAllButterflies::CAkPhaseVocoder *v7; // rbx
  unsigned int v8; // ecx
  AkAudioBuffer *v9; // r15
  unsigned int v10; // er10
  AkAudioBuffer *v11; // rbp
  signed int v12; // esi
  float v13; // xmm9_4
  float v14; // xmm10_4
  int v15; // er9
  __m128 in_fInterpLoc; // xmm7
  int v17; // er8
  unsigned int v18; // er14
  unsigned int v19; // er13
  __int64 v20; // rdi
  unsigned int v21; // er12
  unsigned __int64 v22; // rdx
  unsigned int v23; // eax
  __int64 v24; // r12
  DSP::CAkCircularBuffer *v25; // r15
  unsigned int v26; // eax
  bool v27; // r12
  char v28; // cl
  float v29; // xmm6_4
  signed int v30; // ecx
  bool v31; // si
  unsigned __int16 v32; // ax
  bool v33; // al
  bool v34; // zf
  unsigned int in_uNumFrames; // [rsp+40h] [rbp-C8h]
  unsigned int v36; // [rsp+44h] [rbp-C4h]
  unsigned int v37; // [rsp+48h] [rbp-C0h]
  unsigned int v38; // [rsp+50h] [rbp-B8h]
  unsigned __int64 v39; // [rsp+58h] [rbp-B0h]
  unsigned __int64 v40; // [rsp+60h] [rbp-A8h]
  unsigned int v41; // [rsp+110h] [rbp+8h]
  AkAudioBuffer *v42; // [rsp+118h] [rbp+10h]
  unsigned int v43; // [rsp+120h] [rbp+18h]
  AkAudioBuffer *v44; // [rsp+128h] [rbp+20h]
  BOOL in_fTSFactora; // [rsp+130h] [rbp+28h]
  bool in_bEnterNoTSModea; // [rsp+138h] [rbp+30h]

  v44 = io_pOutBuffer;
  v43 = in_uInOffset;
  v42 = io_pInBuffer;
  v7 = this;
  v8 = 0;
  v9 = io_pOutBuffer;
  v10 = in_uInOffset;
  v11 = io_pInBuffer;
  if ( in_bEnterNoTSMode )
  {
    v7->m_fInterpPos = 0.0;
    v7->m_bInitPhases = 1;
  }
  v12 = v7->m_uFFTSize;
  v37 = 0;
  v38 = v12;
  v13 = 100.0 / in_fTSFactor;
  in_uNumFrames = v7->m_uFFTSize >> 2;
  v14 = 1.0 / (float)((float)(v7->m_TimeWindow.m_fCummulativeSum * 4.0) / (float)v12);
  do
  {
    LOWORD(v15) = v9->uValidFrames;
    in_fInterpLoc = (__m128)LODWORD(v7->m_fInterpPos);
    LOBYTE(v17) = v7->m_bInputStartFill;
    v18 = v11->uValidFrames;
    v19 = v7->m_uInputFramesToDiscard;
    v20 = v8;
    in_bEnterNoTSModea = v7->m_bInitPhases;
    v41 = v9->uValidFrames;
    v21 = v10;
    in_fTSFactora = v7->m_bInputStartFill;
    v22 = (unsigned __int64)v11->pData + 4 * v8 * (unsigned __int64)v11->uMaxFrames;
    v39 = (unsigned __int64)v11->pData + 4 * v8 * (unsigned __int64)v11->uMaxFrames;
    v40 = (unsigned __int64)v9->pData + 4 * v8 * (unsigned __int64)v9->uMaxFrames;
    while ( 1 )
    {
      v23 = v19;
      if ( v18 < v19 )
        v23 = v18;
      v19 -= v23;
      v18 -= v23;
      v24 = v23 + v21;
      if ( (_BYTE)v17 && !v18 && v11->eState != 17 )
      {
LABEL_52:
        v9->eState = 43;
        goto LABEL_55;
      }
      v25 = &v7->m_InputAccumBuf[v20];
      v26 = DSP::CAkCircularBuffer::PushFrames(&v7->m_InputAccumBuf[v20], (float *)(v22 + 4 * v24), v18);
      v17 = (unsigned __int8)in_fTSFactora;
      if ( v25->m_uSize == v25->m_uFramesReady )
        v17 = 0;
      v18 -= (unsigned __int16)v26;
      in_fTSFactora = v17;
      v36 = v26 + v24;
      if ( !(_BYTE)v17 || v25->m_uSize == v25->m_uFramesReady || v18 )
      {
        if ( v11->eState != 17 || v18 )
        {
          v27 = 0;
          goto LABEL_21;
        }
      }
      else if ( v11->eState != 17 )
      {
        v9 = v44;
        LOWORD(v15) = v41;
        v44->eState = 43;
        goto LABEL_55;
      }
      v27 = 1;
LABEL_21:
      if ( !v7->m_FreqWindow[0][v20 + 8i64 * (v7->m_uFreqWindowIndex[v20] & 1)].m_bReady
        && DSP::CAkCircularBuffer::ReadFrameBlock(&v7->m_InputAccumBuf[v20], in_pfTempStorage, v12, v27) )
      {
        DSP::CAkCircularBuffer::AdvanceFrames(&v7->m_InputAccumBuf[v20], in_uNumFrames);
        DSP::CAkTimeWindow::Apply(&v7->m_TimeWindow, in_pfTempStorage, v12, 1.0);
        DSP::AkFFTAllButterflies::CAkFreqWindow::Compute(
          (DSP::AkFFTAllButterflies::CAkFreqWindow *)v7 + v20 + 8i64 * (v7->m_uFreqWindowIndex[v20] & 1) + 29,
          in_pfTempStorage,
          v12,
          v7->m_pFFTState);
        DSP::AkFFTAllButterflies::CAkFreqWindow::CartToPol((DSP::AkFFTAllButterflies::CAkFreqWindow *)v7 + v20 + 8i64 * (v7->m_uFreqWindowIndex[v20] & 1) + 29);
      }
      if ( !v7->m_FreqWindow[0][v20 + 8i64 * ((v7->m_uFreqWindowIndex[v20] - 1) & 1)].m_bReady
        && DSP::CAkCircularBuffer::ReadFrameBlock(&v7->m_InputAccumBuf[v20], in_pfTempStorage, v12, v27) )
      {
        DSP::CAkCircularBuffer::AdvanceFrames(&v7->m_InputAccumBuf[v20], in_uNumFrames);
        DSP::CAkTimeWindow::Apply(&v7->m_TimeWindow, in_pfTempStorage, v12, 1.0);
        DSP::AkFFTAllButterflies::CAkFreqWindow::Compute(
          (DSP::AkFFTAllButterflies::CAkFreqWindow *)v7 + v20 + 8i64 * ((v7->m_uFreqWindowIndex[v20] - 1) & 1) + 29,
          in_pfTempStorage,
          v12,
          v7->m_pFFTState);
        DSP::AkFFTAllButterflies::CAkFreqWindow::CartToPol((DSP::AkFFTAllButterflies::CAkFreqWindow *)v7 + v20 + 8i64 * ((v7->m_uFreqWindowIndex[v20] - 1) & 1) + 29);
      }
      v28 = v7->m_uFreqWindowIndex[v20];
      if ( v7->m_FreqWindow[0][v20 + 8i64 * ((v28 - 1) & 1)].m_bReady
        && v7->m_FreqWindow[0][v20 + 8i64 * (v28 & 1)].m_bReady
        && !v7->m_VocoderWindow[v20].m_bReady )
      {
        DSP::AkFFTAllButterflies::CAkFreqWindow::ComputeVocoderSpectrum(
          (DSP::AkFFTAllButterflies::CAkFreqWindow *)v7 + v20 + 45,
          *((DSP::AkPolar **)&v7->m_InputAccumBuf[0].m_uSize + 2 * (v20 + 8i64 * (v28 & 1) + 29)),
          *((DSP::AkPolar **)&v7->m_InputAccumBuf[0].m_uSize + 2 * (v20 + 8i64 * ((v28 - 1) & 1) + 29)),
          v7->m_pfPrevSynthesisPhase[v20],
          in_uNumFrames,
          in_fInterpLoc.m128_f32[0],
          in_bEnterNoTSModea);
        in_bEnterNoTSModea = 0;
      }
      if ( v7->m_VocoderWindow[v20].m_bReady )
      {
        if ( *(&v7->m_InputAccumBuf[0].m_uSize + 8 * (v20 + 6))
           - *(&v7->m_InputAccumBuf[0].m_uFramesReady + 8 * (v20 + 6)) >= v38 )
        {
          DSP::AkFFTAllButterflies::CAkFreqWindow::ConvertToTimeDomain(
            (DSP::AkFFTAllButterflies::CAkFreqWindow *)v7 + v20 + 45,
            in_pfTempStorage,
            v38,
            v7->m_pIFFTState);
          DSP::CAkTimeWindow::Apply(&v7->m_TimeWindow, in_pfTempStorage, v38, v14);
          DSP::CAkOLACircularBuffer::PushOverlappedWindow(
            (DSP::CAkOLACircularBuffer *)v7 + v20 + 6,
            in_pfTempStorage,
            in_uNumFrames);
          v7->m_VocoderWindow[v20].m_bReady = 0;
          in_fInterpLoc.m128_f32[0] = in_fInterpLoc.m128_f32[0] + v13;
          if ( in_fInterpLoc.m128_f32[0] >= 1.0 )
          {
            v29 = in_fInterpLoc.m128_f32[0];
            v7->m_FreqWindow[0][v20 + 8i64 * (v7->m_uFreqWindowIndex[v20] & 1)].m_bReady = 0;
            v30 = (signed int)in_fInterpLoc.m128_f32[0];
            if ( (signed int)in_fInterpLoc.m128_f32[0] != 0x80000000 && (float)v30 != in_fInterpLoc.m128_f32[0] )
              v29 = (float)(v30 - (_mm_movemask_ps(_mm_unpacklo_ps(in_fInterpLoc, in_fInterpLoc)) & 1));
            if ( (unsigned int)(signed int)v29 < 2 )
            {
              ++v7->m_uFreqWindowIndex[v20];
            }
            else
            {
              v7->m_FreqWindow[0][v20 + 8i64 * ((v7->m_uFreqWindowIndex[v20] - 1) & 1)].m_bReady = 0;
              v19 = in_uNumFrames * ((signed int)v29 - 2)
                  - DSP::CAkCircularBuffer::AdvanceFrames(
                      &v7->m_InputAccumBuf[v20],
                      in_uNumFrames * ((signed int)v29 - 2));
            }
            in_fInterpLoc.m128_f32[0] = in_fInterpLoc.m128_f32[0] - v29;
          }
        }
      }
      v31 = v27
         && !v25->m_uFramesReady
         && !v7->m_VocoderWindow[v20].m_bReady
         && !v7->m_OLAOutCircBuf[v20].m_uFramesReady;
      v9 = v44;
      v32 = DSP::CAkOLACircularBuffer::PopFrames(
              (DSP::CAkOLACircularBuffer *)v7 + v20 + 6,
              (float *)(v40 + 4i64 * v41),
              v44->uMaxFrames - v41,
              v31);
      v15 = v32 + v41;
      v41 += v32;
      if ( v31 )
      {
        v33 = DSP::CAkOLACircularBuffer::IsDoneTail((DSP::CAkOLACircularBuffer *)v7 + v20 + 6);
        v15 = v41;
        if ( v33 )
        {
          v12 = v38;
          v11 = v42;
          LOBYTE(v17) = in_fTSFactora;
          v44->eState = 17;
          goto LABEL_55;
        }
      }
      v12 = v38;
      v11 = v42;
      LOBYTE(v17) = in_fTSFactora;
      if ( v15 == v44->uMaxFrames )
        break;
      v22 = v39;
      v34 = v27 == 0;
      v21 = v36;
      if ( v34 && !v18 )
        goto LABEL_52;
    }
    v44->eState = 45;
LABEL_55:
    v10 = v43;
    v8 = v37 + 1;
    v37 = v8;
  }
  while ( v8 < v7->m_uNumChannels );
  v11->uValidFrames = v18;
  v9->uValidFrames = v15;
  v7->m_bInitPhases = in_bEnterNoTSModea;
  v7->m_uInputFramesToDiscard = v19;
  LODWORD(v7->m_fInterpPos) = in_fInterpLoc.m128_i32[0];
  v7->m_bInputStartFill = v17;
}


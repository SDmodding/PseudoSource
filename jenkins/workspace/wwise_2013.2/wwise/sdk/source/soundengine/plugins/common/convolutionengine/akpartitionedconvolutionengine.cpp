// File Line: 39
// RVA: 0xB18120
void __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::CAkPartitionedConvolutionEngine(
        DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this)
{
  this->m_pFFTState = 0i64;
  this->m_pIFFTState = 0i64;
  this->m_ppfOverlapAdd = 0i64;
  this->m_puNumCompressedBinsTable = 0i64;
  this->m_pFreqResp[0] = 0i64;
  this->m_pFreqResp[1] = 0i64;
}

// File Line: 44
// RVA: 0xB18150
void __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::~CAkPartitionedConvolutionEngine(
        DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this)
{
  ;
}

// File Line: 55
// RVA: 0xB18160
AKRESULT __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::Init(
        DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        AK::IAkEffectPluginContext *in_pFXCtx,
        AkAudioFormat *in_rFormat,
        AK::IAkProcessorFeatures *in_pProcessorFeatures)
{
  AK::IAkPluginContextBaseVtbl *vfptr; // rax
  unsigned int v10; // edi
  unsigned __int16 *v12; // rax
  __int128 v13; // xmm0
  unsigned __int16 *v14; // rcx
  __int64 uNumCompressedPartition; // rax
  ak_fft_cpx *v16; // rcx
  bool v17; // cc
  ak_fftr_state *v18; // rax
  ak_fftr_state *v19; // rax
  bool v20; // al
  int i; // ecx
  unsigned __int16 *v22; // [rsp+20h] [rbp-28h] BYREF
  char v23; // [rsp+60h] [rbp+18h] BYREF

  vfptr = in_pFXCtx->vfptr;
  v10 = 0;
  v22 = 0i64;
  vfptr->GetPluginMedia(in_pFXCtx, 0, (char **)&v22, (unsigned int *)&v23);
  if ( !v22 )
    return 79;
  v12 = v22 + 24;
  *(_OWORD *)&this->m_FreqDataHeader.uBlockLength = *(_OWORD *)v22;
  *(_OWORD *)&this->m_FreqDataHeader.uNumIRPartition = *((_OWORD *)v12 - 2);
  v13 = *((_OWORD *)v12 - 1);
  v22 = v12;
  *(_OWORD *)&this->m_FreqDataHeader.uChannelBinTotal = v13;
  if ( this->m_FreqDataHeader.uBlockLength == (*(unsigned __int16 (__fastcall **)(AK::IAkEffectPluginContext *))&in_pFXCtx->vfptr->gap8[8])(in_pFXCtx)
    && this->m_FreqDataHeader.uSampleRate == in_rFormat->uSampleRate )
  {
    v14 = v22;
    uNumCompressedPartition = this->m_FreqDataHeader.uNumCompressedPartition;
    this->m_puNumCompressedBinsTable = v22;
    v16 = (ak_fft_cpx *)((char *)v14 + ((2 * uNumCompressedPartition + 15) & 0xFFFFFFFFFFFFFFF0ui64));
    this->m_pFreqResp[0] = v16;
    v17 = this->m_FreqDataHeader.uNumChannels <= 1;
    v22 = (unsigned __int16 *)v16;
    if ( !v17 )
      this->m_pFreqResp[1] = &v16[this->m_FreqDataHeader.uChannelBinTotal];
    DSP::AkFFTSubsetButterflies::ak_fftr_alloc(
      this->m_FreqDataHeader.uFFTLength,
      0,
      0i64,
      &this->m_uFFTSpaceRequirements);
    v18 = (ak_fftr_state *)in_pAllocator->vfptr->Malloc(in_pAllocator, this->m_uFFTSpaceRequirements);
    this->m_pFFTState = v18;
    if ( v18 )
    {
      DSP::AkFFTSubsetButterflies::ak_fftr_alloc(
        this->m_FreqDataHeader.uFFTLength,
        1,
        0i64,
        &this->m_uIFFTSpaceRequirements);
      v19 = (ak_fftr_state *)in_pAllocator->vfptr->Malloc(in_pAllocator, this->m_uIFFTSpaceRequirements);
      this->m_pIFFTState = v19;
      if ( v19 )
      {
        DSP::AkFFTSubsetButterflies::ak_fftr_alloc(
          this->m_FreqDataHeader.uFFTLength,
          0,
          this->m_pFFTState,
          &this->m_uFFTSpaceRequirements);
        DSP::AkFFTSubsetButterflies::ak_fftr_alloc(
          this->m_FreqDataHeader.uFFTLength,
          1,
          this->m_pIFFTState,
          &this->m_uIFFTSpaceRequirements);
        v20 = in_pProcessorFeatures->vfptr->GetSIMDSupport(in_pProcessorFeatures, AK_SIMD_SSE3);
        this->m_uNumInputChannels = 0;
        this->m_bSSE3Supported = v20;
        for ( i = *((_DWORD *)in_rFormat + 1) & 0x3FFFF; i; i &= i - 1 )
          ++v10;
        return DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::InitOLABuffer(this, in_pAllocator, v10);
      }
      else
      {
        return 52;
      }
    }
    else
    {
      return 52;
    }
  }
  else
  {
    Scaleform::Render::DICommand_ApplyFilter::GetType((CAkSwitchCntr *)L"Soundbanks have been generated with convolution r"
                                                                        "everb parameters that do not match sound engine "
                                                                        "runtime conditions. No wet path will be heard.");
    return 2;
  }
}

// File Line: 117
// RVA: 0xB18420
__int64 __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::RelocateMedia(
        DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this,
        char *in_pNewMedia,
        char *in_pOldMedia)
{
  unsigned __int16 *m_puNumCompressedBinsTable; // rax
  __int64 v4; // rdx
  ak_fft_cpx *v5; // rax
  ak_fft_cpx *v6; // rax

  m_puNumCompressedBinsTable = this->m_puNumCompressedBinsTable;
  v4 = in_pNewMedia - in_pOldMedia;
  if ( m_puNumCompressedBinsTable )
    this->m_puNumCompressedBinsTable = (unsigned __int16 *)((char *)m_puNumCompressedBinsTable + v4);
  v5 = this->m_pFreqResp[0];
  if ( v5 )
    this->m_pFreqResp[0] = (ak_fft_cpx *)((char *)v5 + v4);
  v6 = this->m_pFreqResp[1];
  if ( v6 )
    this->m_pFreqResp[1] = (ak_fft_cpx *)((char *)v6 + v4);
  return 1i64;
}

// File Line: 130
// RVA: 0xB18720
void __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::TermOverlapAddBuffer(
        DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  unsigned int i; // ebx
  __int64 v5; // rsi

  if ( this->m_ppfOverlapAdd )
  {
    for ( i = 0; i < this->m_uNumInputChannels; ++i )
    {
      v5 = i;
      if ( this->m_ppfOverlapAdd[v5] )
      {
        ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
        this->m_ppfOverlapAdd[v5] = 0i64;
      }
    }
    in_pAllocator->vfptr->Free(in_pAllocator, this->m_ppfOverlapAdd);
    this->m_ppfOverlapAdd = 0i64;
  }
}

// File Line: 147
// RVA: 0xB18330
void __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::Term(
        DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::TermOverlapAddBuffer(this, in_pAllocator);
  if ( this->m_pFFTState )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    this->m_pFFTState = 0i64;
  }
  if ( this->m_pIFFTState )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    this->m_pIFFTState = 0i64;
  }
  this->m_pFreqResp[1] = 0i64;
  this->m_pFreqResp[0] = 0i64;
}

// File Line: 166
// RVA: 0xB183A0
void __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::Reset(
        DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this)
{
  __int64 v2; // rdi
  ak_fft_cpx *v3; // rcx

  if ( this->m_ppfOverlapAdd )
  {
    v2 = 0i64;
    if ( this->m_uNumInputChannels )
    {
      do
      {
        v3 = this->m_ppfOverlapAdd[v2];
        if ( v3 )
          memset(
            v3,
            0,
            8 * this->m_FreqDataHeader.uNumCompressedPartition * this->m_FreqDataHeader.uMaxCompressedNumBins);
        v2 = (unsigned int)(v2 + 1);
      }
      while ( (unsigned int)v2 < this->m_uNumInputChannels );
      this->m_uOLAIndex = 0;
    }
    else
    {
      this->m_uOLAIndex = 0;
    }
  }
  else
  {
    this->m_uOLAIndex = 0;
  }
}

// File Line: 183
// RVA: 0xB18470
__int64 __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::InitOLABuffer(
        DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        unsigned int in_uNumChannels)
{
  ak_fft_cpx **v6; // rcx
  __int64 v8; // rbx

  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::TermOverlapAddBuffer(this, in_pAllocator);
  this->m_uNumInputChannels = in_uNumChannels;
  v6 = (ak_fft_cpx **)in_pAllocator->vfptr->Malloc(in_pAllocator, 8i64 * in_uNumChannels);
  this->m_ppfOverlapAdd = v6;
  if ( !v6 )
    return 52i64;
  memset(v6, 0, 8 * this->m_uNumInputChannels);
  v8 = 0i64;
  if ( !this->m_uNumInputChannels )
    return 1i64;
  while ( 1 )
  {
    this->m_ppfOverlapAdd[v8] = (ak_fft_cpx *)in_pAllocator->vfptr->Malloc(
                                                in_pAllocator,
                                                8
                                              * this->m_FreqDataHeader.uMaxCompressedNumBins
                                              * this->m_FreqDataHeader.uNumCompressedPartition);
    if ( !this->m_ppfOverlapAdd[v8] )
      break;
    v8 = (unsigned int)(v8 + 1);
    if ( (unsigned int)v8 >= this->m_uNumInputChannels )
      return 1i64;
  }
  return 52i64;
}

// File Line: 402
// RVA: 0xB18560
void __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::ExecuteChannelInPlace(
        DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this,
        float *io_pfData,
        unsigned int in_uNumFrames,
        float *io_pfFFTBufferTD,
        ak_fft_cpx *io_pfFFTBufferFD,
        ak_fft_cpx *__formal,
        unsigned int in_uChannelIndex,
        unsigned int in_uIRChannelIndex)
{
  unsigned int uFFTLength; // ebx
  __int64 v9; // rdi
  unsigned int uNumCompressedPartition; // ecx
  ak_fft_cpx *v13; // rsi
  unsigned __int16 *m_puNumCompressedBinsTable; // r12
  unsigned int v15; // eax
  __int64 v16; // rdi
  __int64 v17; // rbx
  int uMaxCompressedNumBins; // edi
  unsigned int v19; // edx
  __int64 v20; // rdi
  unsigned int v21; // ebx
  ak_fft_cpx *v22; // rbp

  uFFTLength = this->m_FreqDataHeader.uFFTLength;
  v9 = in_uNumFrames;
  memmove(io_pfFFTBufferTD, io_pfData, 4 * in_uNumFrames);
  memset(&io_pfFFTBufferTD[v9], 0, 4 * (uFFTLength - (unsigned int)v9));
  DSP::AkFFTSubsetButterflies::ak_fftr(this->m_pFFTState, io_pfFFTBufferTD, io_pfFFTBufferFD);
  uNumCompressedPartition = this->m_FreqDataHeader.uNumCompressedPartition;
  v13 = this->m_pFreqResp[in_uIRChannelIndex];
  m_puNumCompressedBinsTable = this->m_puNumCompressedBinsTable;
  v15 = in_uChannelIndex;
  v16 = 0i64;
  if ( uNumCompressedPartition )
  {
    do
    {
      v17 = m_puNumCompressedBinsTable[v16];
      DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::FreqDomainBufferMult(
        this,
        &this->m_ppfOverlapAdd[in_uChannelIndex][this->m_FreqDataHeader.uMaxCompressedNumBins
                                               * (((int)v16 + this->m_uOLAIndex) % uNumCompressedPartition)],
        io_pfFFTBufferFD,
        v13,
        m_puNumCompressedBinsTable[v16]);
      uNumCompressedPartition = this->m_FreqDataHeader.uNumCompressedPartition;
      v16 = (unsigned int)(v16 + 1);
      v13 += v17;
    }
    while ( (unsigned int)v16 < uNumCompressedPartition );
    v15 = in_uChannelIndex;
  }
  uMaxCompressedNumBins = this->m_FreqDataHeader.uMaxCompressedNumBins;
  v19 = uMaxCompressedNumBins * (this->m_uOLAIndex % this->m_FreqDataHeader.uNumCompressedPartition);
  v20 = (unsigned int)(8 * uMaxCompressedNumBins);
  v21 = 8 * (this->m_FreqDataHeader.uFFTLength >> 1) + 8;
  v22 = &this->m_ppfOverlapAdd[v15][v19];
  memmove(io_pfFFTBufferFD, v22, (unsigned int)v20);
  memset((char *)io_pfFFTBufferFD + v20, 0, v21 - (unsigned int)v20);
  DSP::AkFFTSubsetButterflies::ak_fftri(this->m_pIFFTState, io_pfFFTBufferFD, io_pfFFTBufferTD);
  AK::DSP::ApplyGain_14(
    io_pfFFTBufferTD,
    1.0 / (float)(int)this->m_FreqDataHeader.uFFTLength,
    this->m_FreqDataHeader.uFFTLength);
  memmove(io_pfData, &io_pfFFTBufferTD[this->m_FreqDataHeader.uBlockLength], 4 * this->m_FreqDataHeader.uBlockLength);
  memset(v22, 0, (unsigned int)v20);
}

// File Line: 669
// RVA: 0xB188A0
void __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::FreqDomainBufferMult(
        DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this,
        ak_fft_cpx *io_pOutput,
        __m128 *io_pInput,
        ak_fft_cpx *in_pIRPartition,
        unsigned int in_uNumBinsToProcess)
{
  __m128 *v5; // r11
  signed __int64 v7; // r10
  unsigned int v8; // ebx
  const char *v9; // rax
  signed __int64 v10; // r8
  __int64 v11; // rcx
  __int64 v12; // rax
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  __m128 v15; // xmm2
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm0
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm0
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm0
  __m128 v29; // xmm2
  __m128 v30; // xmm1
  __int64 v31; // rax
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  __m128 v34; // xmm3
  __m128 v35; // xmm0
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  __m128 v38; // xmm3
  __m128 v39; // xmm0
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm3
  __m128 v43; // xmm2
  __m128 v44; // xmm1
  __m128 v45; // xmm3
  __m128 v46; // xmm0
  __m128 v47; // xmm3
  __m128 v48; // xmm2
  __m128 v49; // xmm3
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  __m128 v52; // xmm3
  __m128 v53; // xmm2
  int v54; // edi
  signed __int64 v55; // r11
  __int64 v56; // rcx
  __m128 v57; // xmm2
  __m128 v58; // xmm1

  v5 = io_pInput;
  v7 = (char *)io_pInput - (char *)in_pIRPartition;
  v8 = in_uNumBinsToProcess >> 3;
  v9 = (const char *)in_pIRPartition;
  v10 = (char *)io_pOutput - (char *)in_pIRPartition;
  v11 = 4i64;
  do
  {
    _mm_prefetch(&v9[v7], 0);
    _mm_prefetch(v9, 0);
    _mm_prefetch(&v9[v10], 0);
    v9 += 64;
    --v11;
  }
  while ( v11 );
  if ( this->m_bSSE3Supported )
  {
    if ( v8 )
    {
      v12 = v8;
      do
      {
        _mm_prefetch((const char *)&in_pIRPartition[32] + v7, 0);
        _mm_prefetch((const char *)&in_pIRPartition[32], 0);
        _mm_prefetch((const char *)&in_pIRPartition[32] + v10, 0);
        v13 = *(__m128 *)&in_pIRPartition->r;
        v14 = _mm_movehdup_ps(*v5);
        v15 = _mm_moveldup_ps(*v5);
        in_pIRPartition += 8;
        io_pOutput += 8;
        v5 += 4;
        v16 = _mm_mul_ps(v15, v13);
        v17 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 177), v14);
        v18 = _mm_movehdup_ps(*(__m128 *)((char *)&in_pIRPartition[-6].r + v7));
        v19 = _mm_addsub_ps(v16, v17);
        v20 = *(__m128 *)&in_pIRPartition[-6].r;
        *(__m128 *)&io_pOutput[-8].r = _mm_add_ps(v19, *(__m128 *)&io_pOutput[-8].r);
        v21 = _mm_mul_ps(_mm_moveldup_ps(*(__m128 *)((char *)&in_pIRPartition[-6].r + v7)), v20);
        v22 = _mm_mul_ps(_mm_shuffle_ps(v20, v20, 177), v18);
        v23 = _mm_movehdup_ps(*(__m128 *)((char *)&in_pIRPartition[-4].r + v7));
        v24 = _mm_addsub_ps(v21, v22);
        v25 = *(__m128 *)&in_pIRPartition[-4].r;
        *(__m128 *)((char *)&in_pIRPartition[-6].r + v10) = _mm_add_ps(
                                                              v24,
                                                              *(__m128 *)((char *)&in_pIRPartition[-6].r + v10));
        v26 = _mm_mul_ps(_mm_moveldup_ps(*(__m128 *)((char *)&in_pIRPartition[-4].r + v7)), v25);
        v27 = _mm_mul_ps(_mm_shuffle_ps(v25, v25, 177), v23);
        v28 = _mm_movehdup_ps(*(__m128 *)((char *)&in_pIRPartition[-2].r + v7));
        v29 = _mm_addsub_ps(v26, v27);
        v30 = *(__m128 *)&in_pIRPartition[-2].r;
        *(__m128 *)((char *)&in_pIRPartition[-4].r + v10) = _mm_add_ps(
                                                              v29,
                                                              *(__m128 *)((char *)&in_pIRPartition[-4].r + v10));
        *(__m128 *)((char *)&in_pIRPartition[-2].r + v10) = _mm_add_ps(
                                                              _mm_addsub_ps(
                                                                _mm_mul_ps(
                                                                  _mm_moveldup_ps(*(__m128 *)((char *)&in_pIRPartition[-2].r
                                                                                            + v7)),
                                                                  v30),
                                                                _mm_mul_ps(_mm_shuffle_ps(v30, v30, 177), v28)),
                                                              *(__m128 *)((char *)&in_pIRPartition[-2].r + v10));
        --v12;
      }
      while ( v12 );
    }
  }
  else if ( v8 )
  {
    v31 = v8;
    do
    {
      _mm_prefetch((const char *)&in_pIRPartition[32] + v7, 0);
      _mm_prefetch((const char *)&in_pIRPartition[32], 0);
      _mm_prefetch((const char *)&in_pIRPartition[32] + v10, 0);
      v32 = *(__m128 *)&in_pIRPartition->r;
      v33 = *v5;
      in_pIRPartition += 8;
      io_pOutput += 8;
      v5 += 4;
      v34 = _mm_shuffle_ps(v33, v33, 245);
      v35 = _mm_shuffle_ps(v32, v32, 177);
      v36 = _mm_mul_ps(_mm_shuffle_ps(v33, v33, 160), v32);
      v37 = *(__m128 *)&in_pIRPartition[-6].r;
      v38 = _mm_mul_ps(_mm_mul_ps(v34, _xmm), v35);
      v39 = _mm_shuffle_ps(v37, v37, 177);
      v40 = _mm_add_ps(v38, v36);
      v41 = *(__m128 *)((char *)&in_pIRPartition[-6].r + v7);
      *(__m128 *)&io_pOutput[-8].r = _mm_add_ps(v40, *(__m128 *)&io_pOutput[-8].r);
      v42 = _mm_shuffle_ps(v41, v41, 245);
      v43 = _mm_mul_ps(_mm_shuffle_ps(v41, v41, 160), v37);
      v44 = *(__m128 *)&in_pIRPartition[-4].r;
      v45 = _mm_mul_ps(_mm_mul_ps(v42, _xmm), v39);
      v46 = _mm_shuffle_ps(v44, v44, 177);
      v47 = _mm_add_ps(v45, v43);
      v48 = *(__m128 *)((char *)&in_pIRPartition[-4].r + v7);
      *(__m128 *)((char *)&in_pIRPartition[-6].r + v10) = _mm_add_ps(
                                                            v47,
                                                            *(__m128 *)((char *)&in_pIRPartition[-6].r + v10));
      v49 = _mm_shuffle_ps(v48, v48, 245);
      v50 = _mm_mul_ps(_mm_shuffle_ps(v48, v48, 160), v44);
      v51 = *(__m128 *)&in_pIRPartition[-2].r;
      v52 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v49, _xmm), v46), v50);
      v53 = *(__m128 *)((char *)&in_pIRPartition[-2].r + v7);
      *(__m128 *)((char *)&in_pIRPartition[-4].r + v10) = _mm_add_ps(
                                                            v52,
                                                            *(__m128 *)((char *)&in_pIRPartition[-4].r + v10));
      *(__m128 *)((char *)&in_pIRPartition[-2].r + v10) = _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_mul_ps(
                                                                _mm_mul_ps(_mm_shuffle_ps(v53, v53, 245), _xmm),
                                                                _mm_shuffle_ps(v51, v51, 177)),
                                                              _mm_mul_ps(_mm_shuffle_ps(v53, v53, 160), v51)),
                                                            *(__m128 *)((char *)&in_pIRPartition[-2].r + v10));
      --v31;
    }
    while ( v31 );
  }
  v54 = in_uNumBinsToProcess - 8 * v8;
  if ( v54 )
  {
    v55 = (char *)v5 - (char *)io_pOutput;
    v56 = ((unsigned int)(v54 - 1) >> 1) + 1;
    do
    {
      v57 = *(__m128 *)((char *)&io_pOutput->r + v55);
      v58 = *(__m128 *)&in_pIRPartition->r;
      io_pOutput += 2;
      in_pIRPartition += 2;
      *(__m128 *)&io_pOutput[-2].r = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_mul_ps(_mm_shuffle_ps(v57, v57, 245), _xmm),
                                           _mm_shuffle_ps(v58, v58, 177)),
                                         _mm_mul_ps(_mm_shuffle_ps(v57, v57, 160), v58)),
                                       *(__m128 *)&io_pOutput[-2].r);
      --v56;
    }
    while ( v56 );
  }
}                                _mm_mul_ps(_mm_shuffle_ps(v57, v57, 160), v


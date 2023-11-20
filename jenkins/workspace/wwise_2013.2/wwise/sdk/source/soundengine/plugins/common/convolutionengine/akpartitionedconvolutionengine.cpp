// File Line: 39
// RVA: 0xB18120
void __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::CAkPartitionedConvolutionEngine(DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this)
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
void __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::~CAkPartitionedConvolutionEngine(DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this)
{
  ;
}

// File Line: 55
// RVA: 0xB18160
AKRESULT __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::Init(DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this, AK::IAkPluginMemAlloc *in_pAllocator, AK::IAkEffectPluginContext *in_pFXCtx, AkAudioFormat *in_rFormat, AK::IAkProcessorFeatures *in_pProcessorFeatures)
{
  AK::IAkPluginContextBaseVtbl *v5; // rax
  AK::IAkEffectPluginContext *v6; // r14
  AkAudioFormat *v7; // rbp
  AK::IAkPluginMemAlloc *v8; // rsi
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *v9; // rbx
  unsigned int v10; // edi
  AKRESULT result; // eax
  ak_fft_cpx *v12; // rax
  __int128 v13; // xmm0
  ak_fft_cpx *v14; // rcx
  __int64 v15; // rax
  ak_fft_cpx *v16; // rcx
  bool v17; // cf
  bool v18; // zf
  __int64 v19; // rax
  __int64 v20; // rax
  bool v21; // al
  int i; // ecx
  ak_fft_cpx *v23; // [rsp+20h] [rbp-28h]
  char v24; // [rsp+60h] [rbp+18h]

  v5 = in_pFXCtx->vfptr;
  v6 = in_pFXCtx;
  v7 = in_rFormat;
  v8 = in_pAllocator;
  v9 = this;
  v10 = 0;
  v23 = 0i64;
  v5->GetPluginMedia((AK::IAkPluginContextBase *)&in_pFXCtx->vfptr, 0, (char **)&v23, (unsigned int *)&v24);
  if ( !v23 )
    return 79;
  v12 = v23 + 6;
  *(_OWORD *)&v9->m_FreqDataHeader.uBlockLength = *(_OWORD *)&v23->r;
  *(_OWORD *)&v9->m_FreqDataHeader.uNumIRPartition = *(_OWORD *)&v12[-4].r;
  v13 = *(_OWORD *)&v12[-2].r;
  v23 = v12;
  *(_OWORD *)&v9->m_FreqDataHeader.uChannelBinTotal = v13;
  if ( v9->m_FreqDataHeader.uBlockLength != (*(unsigned __int16 (__fastcall **)(AK::IAkEffectPluginContext *))&v6->vfptr->gap8[8])(v6)
    || v9->m_FreqDataHeader.uSampleRate != v7->uSampleRate )
  {
    Scaleform::Render::DICommand_ApplyFilter::GetType((CAkSwitchCntr *)L"Soundbanks have been generated with convolution r"
                                                                        "everb parameters that do not match sound engine "
                                                                        "runtime conditions. No wet path will be heard.");
    result = 2;
  }
  else
  {
    v14 = v23;
    v15 = v9->m_FreqDataHeader.uNumCompressedPartition;
    v9->m_puNumCompressedBinsTable = (unsigned __int16 *)v23;
    v16 = (ak_fft_cpx *)((char *)v14 + ((2 * v15 + 15) & 0xFFFFFFFFFFFFFFF0ui64));
    v9->m_pFreqResp[0] = v16;
    v17 = v9->m_FreqDataHeader.uNumChannels < 1;
    v18 = v9->m_FreqDataHeader.uNumChannels == 1;
    v23 = v16;
    if ( !v17 && !v18 )
      v9->m_pFreqResp[1] = &v16[v9->m_FreqDataHeader.uChannelBinTotal];
    DSP::AkFFTSubsetButterflies::ak_fftr_alloc(v9->m_FreqDataHeader.uFFTLength, 0, 0i64, &v9->m_uFFTSpaceRequirements);
    v19 = (__int64)v8->vfptr->Malloc(v8, v9->m_uFFTSpaceRequirements);
    v9->m_pFFTState = (ak_fftr_state *)v19;
    if ( v19 )
    {
      DSP::AkFFTSubsetButterflies::ak_fftr_alloc(
        v9->m_FreqDataHeader.uFFTLength,
        1,
        0i64,
        &v9->m_uIFFTSpaceRequirements);
      v20 = (__int64)v8->vfptr->Malloc(v8, v9->m_uIFFTSpaceRequirements);
      v9->m_pIFFTState = (ak_fftr_state *)v20;
      if ( v20 )
      {
        DSP::AkFFTSubsetButterflies::ak_fftr_alloc(
          v9->m_FreqDataHeader.uFFTLength,
          0,
          v9->m_pFFTState,
          &v9->m_uFFTSpaceRequirements);
        DSP::AkFFTSubsetButterflies::ak_fftr_alloc(
          v9->m_FreqDataHeader.uFFTLength,
          1,
          v9->m_pIFFTState,
          &v9->m_uIFFTSpaceRequirements);
        v21 = in_pProcessorFeatures->vfptr->GetSIMDSupport(in_pProcessorFeatures, AK_SIMD_SSE3);
        v9->m_uNumInputChannels = 0;
        v9->m_bSSE3Supported = v21;
        for ( i = *((_DWORD *)v7 + 1) & 0x3FFFF; i; i &= i - 1 )
          ++v10;
        result = DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::InitOLABuffer(v9, v8, v10);
      }
      else
      {
        result = 52;
      }
    }
    else
    {
      result = 52;
    }
  }
  return result;
}

// File Line: 117
// RVA: 0xB18420
signed __int64 __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::RelocateMedia(DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this, char *in_pNewMedia, char *in_pOldMedia)
{
  unsigned __int16 *v3; // rax
  signed __int64 v4; // rdx
  ak_fft_cpx *v5; // rax
  ak_fft_cpx *v6; // rax

  v3 = this->m_puNumCompressedBinsTable;
  v4 = in_pNewMedia - in_pOldMedia;
  if ( v3 )
    this->m_puNumCompressedBinsTable = (unsigned __int16 *)((char *)v3 + v4);
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
void __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::TermOverlapAddBuffer(DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // r14
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *v3; // rdi
  unsigned int v4; // ebx
  signed __int64 v5; // rsi

  v2 = in_pAllocator;
  v3 = this;
  if ( this->m_ppfOverlapAdd )
  {
    v4 = 0;
    if ( this->m_uNumInputChannels )
    {
      do
      {
        v5 = v4;
        if ( v3->m_ppfOverlapAdd[v5] )
        {
          ((void (__fastcall *)(AK::IAkPluginMemAlloc *))v2->vfptr->Free)(v2);
          v3->m_ppfOverlapAdd[v5] = 0i64;
        }
        ++v4;
      }
      while ( v4 < v3->m_uNumInputChannels );
    }
    v2->vfptr->Free(v2, v3->m_ppfOverlapAdd);
    v3->m_ppfOverlapAdd = 0i64;
  }
}

// File Line: 147
// RVA: 0xB18330
void __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::Term(DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *v3; // rbx

  v2 = in_pAllocator;
  v3 = this;
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::TermOverlapAddBuffer(this, in_pAllocator);
  if ( v3->m_pFFTState )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))v2->vfptr->Free)(v2);
    v3->m_pFFTState = 0i64;
  }
  if ( v3->m_pIFFTState )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))v2->vfptr->Free)(v2);
    v3->m_pIFFTState = 0i64;
  }
  v3->m_pFreqResp[1] = 0i64;
  v3->m_pFreqResp[0] = 0i64;
}

// File Line: 166
// RVA: 0xB183A0
void __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::Reset(DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this)
{
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *v1; // rbx
  __int64 v2; // rdi
  ak_fft_cpx *v3; // rcx

  v1 = this;
  if ( this->m_ppfOverlapAdd )
  {
    v2 = 0i64;
    if ( this->m_uNumInputChannels )
    {
      do
      {
        v3 = v1->m_ppfOverlapAdd[v2];
        if ( v3 )
          memset(v3, 0, 8 * v1->m_FreqDataHeader.uNumCompressedPartition * v1->m_FreqDataHeader.uMaxCompressedNumBins);
        v2 = (unsigned int)(v2 + 1);
      }
      while ( (unsigned int)v2 < v1->m_uNumInputChannels );
      v1->m_uOLAIndex = 0;
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
signed __int64 __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::InitOLABuffer(DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this, AK::IAkPluginMemAlloc *in_pAllocator, unsigned int in_uNumChannels)
{
  unsigned int v3; // ebx
  AK::IAkPluginMemAlloc *v4; // r14
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *v5; // rsi
  ak_fft_cpx **v6; // rcx
  __int64 v8; // rbx

  v3 = in_uNumChannels;
  v4 = in_pAllocator;
  v5 = this;
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::TermOverlapAddBuffer(this, in_pAllocator);
  v5->m_uNumInputChannels = v3;
  v6 = (ak_fft_cpx **)v4->vfptr->Malloc(v4, 8i64 * v3);
  v5->m_ppfOverlapAdd = v6;
  if ( !v6 )
    return 52i64;
  memset(v6, 0, 8 * v5->m_uNumInputChannels);
  v8 = 0i64;
  if ( !v5->m_uNumInputChannels )
    return 1i64;
  while ( 1 )
  {
    v5->m_ppfOverlapAdd[v8] = (ak_fft_cpx *)v4->vfptr->Malloc(
                                              v4,
                                              8
                                            * v5->m_FreqDataHeader.uMaxCompressedNumBins
                                            * v5->m_FreqDataHeader.uNumCompressedPartition);
    if ( !v5->m_ppfOverlapAdd[v8] )
      break;
    v8 = (unsigned int)(v8 + 1);
    if ( (unsigned int)v8 >= v5->m_uNumInputChannels )
      return 1i64;
  }
  return 52i64;
}

// File Line: 402
// RVA: 0xB18560
void __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::ExecuteChannelInPlace(DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this, float *io_pfData, unsigned int in_uNumFrames, float *io_pfFFTBufferTD, ak_fft_cpx *io_pfFFTBufferFD, ak_fft_cpx *__formal, unsigned int in_uChannelIndex, unsigned int in_uIRChannelIndex)
{
  unsigned int v8; // ebx
  __int64 v9; // rdi
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *v10; // r14
  float *v11; // r13
  unsigned int v12; // ecx
  ak_fft_cpx *v13; // rsi
  unsigned __int16 *v14; // r12
  unsigned int v15; // eax
  __int64 v16; // rdi
  __int64 v17; // rbx
  int v18; // edi
  unsigned int v19; // edx
  __int64 v20; // rdi
  int v21; // ebx
  ak_fft_cpx *v22; // rbp
  float *Dst; // [rsp+68h] [rbp+10h]

  Dst = io_pfData;
  v8 = this->m_FreqDataHeader.uFFTLength;
  v9 = in_uNumFrames;
  v10 = this;
  v11 = io_pfFFTBufferTD;
  memmove(io_pfFFTBufferTD, io_pfData, 4 * in_uNumFrames);
  memset(&v11[v9], 0, 4 * (v8 - (unsigned int)v9));
  DSP::AkFFTSubsetButterflies::ak_fftr(v10->m_pFFTState, v11, io_pfFFTBufferFD);
  v12 = v10->m_FreqDataHeader.uNumCompressedPartition;
  v13 = v10->m_pFreqResp[in_uIRChannelIndex];
  v14 = v10->m_puNumCompressedBinsTable;
  v15 = in_uChannelIndex;
  v16 = 0i64;
  if ( v12 )
  {
    do
    {
      v17 = v14[v16];
      DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::FreqDomainBufferMult(
        v10,
        &v10->m_ppfOverlapAdd[in_uChannelIndex][v10->m_FreqDataHeader.uMaxCompressedNumBins
                                              * (((signed int)v16 + v10->m_uOLAIndex) % v12)],
        io_pfFFTBufferFD,
        v13,
        v14[v16]);
      v12 = v10->m_FreqDataHeader.uNumCompressedPartition;
      v16 = (unsigned int)(v16 + 1);
      v13 += v17;
    }
    while ( (unsigned int)v16 < v12 );
    v15 = in_uChannelIndex;
  }
  v18 = v10->m_FreqDataHeader.uMaxCompressedNumBins;
  v19 = v18 * (v10->m_uOLAIndex % v10->m_FreqDataHeader.uNumCompressedPartition);
  v20 = (unsigned int)(8 * v18);
  v21 = 8 * (v10->m_FreqDataHeader.uFFTLength >> 1) + 8;
  v22 = &v10->m_ppfOverlapAdd[v15][v19];
  memmove(io_pfFFTBufferFD, v22, (unsigned int)v20);
  memset((char *)io_pfFFTBufferFD + v20, 0, (unsigned int)(v21 - v20));
  DSP::AkFFTSubsetButterflies::ak_fftri(v10->m_pIFFTState, io_pfFFTBufferFD, v11);
  AK::DSP::ApplyGain_14(
    v11,
    1.0 / (float)(signed int)v10->m_FreqDataHeader.uFFTLength,
    v10->m_FreqDataHeader.uFFTLength);
  memmove(Dst, &v11[v10->m_FreqDataHeader.uBlockLength], 4 * v10->m_FreqDataHeader.uBlockLength);
  memset(v22, 0, (unsigned int)v20);
}

// File Line: 669
// RVA: 0xB188A0
void __fastcall DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine::FreqDomainBufferMult(DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *this, ak_fft_cpx *io_pOutput, ak_fft_cpx *io_pInput, ak_fft_cpx *in_pIRPartition, unsigned int in_uNumBinsToProcess)
{
  __m128 *v5; // r11
  DSP::AkFFTSubsetButterflies::CAkPartitionedConvolutionEngine *v6; // rsi
  unsigned int v8; // ebx
  signed __int64 v11; // rcx
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
  signed __int64 v54; // r11
  __int64 v55; // rcx
  __m128 v56; // xmm2
  __m128 v57; // xmm1

  v5 = (__m128 *)io_pInput;
  v6 = this;
  _R10 = (char *)io_pInput - (char *)in_pIRPartition;
  v8 = in_uNumBinsToProcess >> 3;
  _RAX = in_pIRPartition;
  _R8 = (char *)io_pOutput - (char *)in_pIRPartition;
  v11 = 4i64;
  do
  {
    __asm
    {
      prefetchnta byte ptr [r10+rax]; Prefetch to L1 cache
      prefetchnta byte ptr [rax]; Prefetch to L1 cache
      prefetchnta byte ptr [r8+rax]; Prefetch to L1 cache
    }
    _RAX += 8;
    --v11;
  }
  while ( v11 );
  if ( v6->m_bSSE3Supported )
  {
    if ( v8 )
    {
      v12 = v8;
      do
      {
        __asm
        {
          prefetchnta byte ptr [r10+r9+100h]; Prefetch to L1 cache
          prefetchnta byte ptr [r9+100h]; Prefetch to L1 cache
          prefetchnta byte ptr [r8+r9+100h]; Prefetch to L1 cache
        }
        v13 = *(__m128 *)&in_pIRPartition->r;
        v14 = _mm_movehdup_ps(*v5);
        v15 = _mm_moveldup_ps(*v5);
        in_pIRPartition += 8;
        io_pOutput += 8;
        v5 += 4;
        v16 = _mm_mul_ps(v15, v13);
        v17 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 177), v14);
        v18 = _mm_movehdup_ps(*(__m128 *)((char *)&in_pIRPartition[-6].r + _R10));
        v19 = _mm_addsub_ps(v16, v17);
        v20 = *(__m128 *)&in_pIRPartition[-6].r;
        *(__m128 *)&io_pOutput[-8].r = _mm_add_ps(v19, *(__m128 *)&io_pOutput[-8].r);
        v21 = _mm_mul_ps(_mm_moveldup_ps(*(__m128 *)((char *)&in_pIRPartition[-6].r + _R10)), v20);
        v22 = _mm_mul_ps(_mm_shuffle_ps(v20, v20, 177), v18);
        v23 = _mm_movehdup_ps(*(__m128 *)((char *)&in_pIRPartition[-4].r + _R10));
        v24 = _mm_addsub_ps(v21, v22);
        v25 = *(__m128 *)&in_pIRPartition[-4].r;
        *(__m128 *)((char *)&in_pIRPartition[-6].r + _R8) = _mm_add_ps(
                                                              v24,
                                                              *(__m128 *)((char *)&in_pIRPartition[-6].r + _R8));
        v26 = _mm_mul_ps(_mm_moveldup_ps(*(__m128 *)((char *)&in_pIRPartition[-4].r + _R10)), v25);
        v27 = _mm_mul_ps(_mm_shuffle_ps(v25, v25, 177), v23);
        v28 = _mm_movehdup_ps(*(__m128 *)((char *)&in_pIRPartition[-2].r + _R10));
        v29 = _mm_addsub_ps(v26, v27);
        v30 = *(__m128 *)&in_pIRPartition[-2].r;
        *(__m128 *)((char *)&in_pIRPartition[-4].r + _R8) = _mm_add_ps(
                                                              v29,
                                                              *(__m128 *)((char *)&in_pIRPartition[-4].r + _R8));
        *(__m128 *)((char *)&in_pIRPartition[-2].r + _R8) = _mm_add_ps(
                                                              _mm_addsub_ps(
                                                                _mm_mul_ps(
                                                                  _mm_moveldup_ps(*(__m128 *)((char *)&in_pIRPartition[-2].r
                                                                                            + _R10)),
                                                                  v30),
                                                                _mm_mul_ps(_mm_shuffle_ps(v30, v30, 177), v28)),
                                                              *(__m128 *)((char *)&in_pIRPartition[-2].r + _R8));
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
      __asm
      {
        prefetchnta byte ptr [r10+r9+100h]; Prefetch to L1 cache
        prefetchnta byte ptr [r9+100h]; Prefetch to L1 cache
        prefetchnta byte ptr [r8+r9+100h]; Prefetch to L1 cache
      }
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
      v41 = *(__m128 *)((char *)&in_pIRPartition[-6].r + _R10);
      *(__m128 *)&io_pOutput[-8].r = _mm_add_ps(v40, *(__m128 *)&io_pOutput[-8].r);
      v42 = _mm_shuffle_ps(v41, v41, 245);
      v43 = _mm_mul_ps(_mm_shuffle_ps(v41, v41, 160), v37);
      v44 = *(__m128 *)&in_pIRPartition[-4].r;
      v45 = _mm_mul_ps(_mm_mul_ps(v42, _xmm), v39);
      v46 = _mm_shuffle_ps(v44, v44, 177);
      v47 = _mm_add_ps(v45, v43);
      v48 = *(__m128 *)((char *)&in_pIRPartition[-4].r + _R10);
      *(__m128 *)((char *)&in_pIRPartition[-6].r + _R8) = _mm_add_ps(
                                                            v47,
                                                            *(__m128 *)((char *)&in_pIRPartition[-6].r + _R8));
      v49 = _mm_shuffle_ps(v48, v48, 245);
      v50 = _mm_mul_ps(_mm_shuffle_ps(v48, v48, 160), v44);
      v51 = *(__m128 *)&in_pIRPartition[-2].r;
      v52 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v49, _xmm), v46), v50);
      v53 = *(__m128 *)((char *)&in_pIRPartition[-2].r + _R10);
      *(__m128 *)((char *)&in_pIRPartition[-4].r + _R8) = _mm_add_ps(
                                                            v52,
                                                            *(__m128 *)((char *)&in_pIRPartition[-4].r + _R8));
      *(__m128 *)((char *)&in_pIRPartition[-2].r + _R8) = _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_mul_ps(
                                                                _mm_mul_ps(_mm_shuffle_ps(v53, v53, 245), _xmm),
                                                                _mm_shuffle_ps(v51, v51, 177)),
                                                              _mm_mul_ps(_mm_shuffle_ps(v53, v53, 160), v51)),
                                                            *(__m128 *)((char *)&in_pIRPartition[-2].r + _R8));
      --v31;
    }
    while ( v31 );
  }
  if ( in_uNumBinsToProcess != 8 * v8 )
  {
    v54 = (char *)v5 - (char *)io_pOutput;
    v55 = ((in_uNumBinsToProcess - 8 * v8 - 1) >> 1) + 1;
    do
    {
      v56 = *(__m128 *)((char *)&io_pOutput->r + v54);
      v57 = *(__m128 *)&in_pIRPartition->r;
      io_pOutput += 2;
      in_pIRPartition += 2;
      *(__m128 *)&io_pOutput[-2].r = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_mul_ps(_mm_shuffle_ps(v56, v56, 245), _xmm),
                                           _mm_shuffle_ps(v57, v57, 177)),
                                         _mm_mul_ps(_mm_shuffle_ps(v56, v56, 160), v57)),
                                       *(__m128 *)&io_pOutput[-2].r);
      --v55;
    }
    while ( v55 );
  }
}


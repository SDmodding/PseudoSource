// File Line: 60
// RVA: 0xB19B20
ak_fftr_state *__fastcall DSP::AkFFTSubsetButterflies::ak_fftr_alloc(
        int nfft,
        int inverse_fft,
        _QWORD *mem,
        unsigned __int64 *lenmem)
{
  __int64 v4; // rbx
  int v9; // esi
  _QWORD *v10; // rdi
  unsigned __int64 v11; // rdx
  unsigned __int64 v12; // rax
  bool v13; // cf
  int v14; // eax
  bool v15; // zf
  __int64 v16; // rbp
  __m128i v17; // xmm0
  int v18; // esi
  double v19; // xmm7_8
  double v20; // xmm6_8
  float v21; // xmm1_4
  float v22; // xmm1_4
  __m128i v23; // xmm0
  int v24; // esi
  double v25; // xmm7_8
  double v26; // xmm6_8
  float v27; // xmm1_4
  float v28; // xmm1_4
  unsigned __int64 lenmema[2]; // [rsp+20h] [rbp-68h] BYREF

  v4 = 0i64;
  if ( (nfft & 1) != 0 )
    return 0i64;
  v9 = nfft >> 1;
  DSP::AkFFTSubsetButterflies::ak_fft_alloc(nfft >> 1, inverse_fft, 0i64, lenmema);
  v10 = 0i64;
  v11 = lenmema[0];
  v12 = lenmema[0] + 8 * (3 * v9 / 2 + 4i64);
  v13 = *lenmem < v12;
  *lenmem = v12;
  if ( !v13 )
    v10 = mem;
  if ( !v10 )
    return 0i64;
  v10[1] = (char *)v10 + v11 + 32;
  v10[2] = (char *)&v10[v9 + 4] + v11;
  *v10 = v10 + 4;
  DSP::AkFFTSubsetButterflies::ak_fft_alloc(v9, inverse_fft, v10 + 4, lenmema);
  v14 = v9 / 2;
  v15 = inverse_fft == 0;
  v16 = v9 / 2;
  if ( v15 )
  {
    if ( v14 > 0 )
    {
      v23 = _mm_cvtsi32_si128(v9);
      v24 = 1;
      v25 = 1.0 / _mm_cvtepi32_pd(v23).m128d_f64[0];
      do
      {
        v26 = ((double)v24 * v25 + 0.5) * -3.141592653589793;
        v27 = cos(v26);
        *(float *)(v10[2] + 8 * v4++) = v27;
        ++v24;
        v28 = sin(v26);
        *(float *)(v10[2] + 8 * v4 - 4) = v28;
      }
      while ( v4 < v16 );
    }
  }
  else if ( v14 > 0 )
  {
    v17 = _mm_cvtsi32_si128(v9);
    v18 = 1;
    v19 = 1.0 / _mm_cvtepi32_pd(v17).m128d_f64[0];
    do
    {
      v20 = ((double)v18 * v19 + 0.5) * 3.141592653589793;
      v21 = cos(v20);
      *(float *)(v10[2] + 8 * v4++) = v21;
      ++v18;
      v22 = sin(v20);
      *(float *)(v10[2] + 8 * v4 - 4) = v22;
    }
    while ( v4 < v16 );
  }
  return (ak_fftr_state *)v10;
}

// File Line: 112
// RVA: 0xAEE6B0
void __fastcall DSP::AkFFTAllButterflies::ak_fftr(ak_fftr_state *st, ak_fft_cpx *timedata, ak_fft_cpx *freqdata)
{
  ak_fft_state *substate; // rcx
  __int64 nfft; // rsi
  ak_fft_cpx *tmpbuf; // r10
  ak_fft_cpx *super_twiddles; // rbx
  unsigned int i; // r9d
  __int64 v10; // rdx
  __m128 v11; // xmm3
  __int64 v12; // r8
  __int64 v13; // rax
  __m128 v14; // xmm0
  __m128 v15; // xmm4
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm4
  ak_fft_cpx v19; // [rsp+50h] [rbp+8h]

  substate = st->substate;
  nfft = substate->nfft;
  DSP::AkFFTAllButterflies::ak_fft(substate, timedata, st->tmpbuf);
  tmpbuf = st->tmpbuf;
  super_twiddles = st->super_twiddles;
  for ( i = 1; i <= (int)nfft / 2; *(__m128 *)&freqdata[v12].r = _mm_shuffle_ps(v18, v18, 78) )
  {
    v10 = i;
    v11 = *(__m128 *)&tmpbuf[i].r;
    v12 = (unsigned int)nfft - i - 1;
    v13 = i - 1;
    i += 2;
    v14 = _mm_mul_ps(
            _mm_shuffle_ps(*(__m128 *)&tmpbuf[v12].r, *(__m128 *)&tmpbuf[v12].r, 78),
            _xmm_bf8000003f800000bf8000003f800000);
    v15 = _mm_add_ps(v14, v11);
    v16 = _mm_sub_ps(v11, v14);
    v17 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(_mm_shuffle_ps(v16, v16, 245), _xmm),
              _mm_shuffle_ps(*(__m128 *)&super_twiddles[v13].r, *(__m128 *)&super_twiddles[v13].r, 177)),
            _mm_mul_ps(_mm_shuffle_ps(v16, v16, 160), *(__m128 *)&super_twiddles[v13].r));
    *(__m128 *)&freqdata[v10].r = _mm_mul_ps(_mm_add_ps(v17, v15), *(__m128 *)_xmm);
    v18 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v15, v17), _xmm_bf8000003f800000bf8000003f800000), *(__m128 *)_xmm);
  }
  v19 = *tmpbuf;
  freqdata->r = COERCE_FLOAT(HIDWORD(*(unsigned __int64 *)tmpbuf)) + COERCE_FLOAT(*tmpbuf);
  freqdata[nfft].r = v19.r - v19.i;
  freqdata->i = 0.0;
  freqdata[nfft].i = 0.0;
}

// File Line: 229
// RVA: 0xB19E80
void __fastcall DSP::AkFFTSubsetButterflies::ak_fftri(ak_fftr_state *st, ak_fft_cpx *freqdata, ak_fft_cpx *timedata)
{
  ak_fft_cpx *tmpbuf; // r9
  ak_fft_state *substate; // rdi
  __int64 nfft; // r11
  ak_fft_cpx *super_twiddles; // r14
  unsigned int v8; // ebx
  float v10; // xmm2_4
  unsigned int v11; // esi
  __int64 v12; // rdx
  __m128 v13; // xmm3
  __int64 v14; // r8
  __int64 v15; // rax
  __m128 v16; // xmm0
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm0
  __m128 v21; // xmm4

  tmpbuf = st->tmpbuf;
  substate = st->substate;
  nfft = st->substate->nfft;
  super_twiddles = st->super_twiddles;
  v8 = 1;
  v10 = freqdata->r - freqdata[nfft].r;
  v11 = st->substate->nfft / 2;
  tmpbuf->r = freqdata->r + freqdata[nfft].r;
  tmpbuf->i = v10;
  if ( v11 )
  {
    do
    {
      v12 = v8;
      v13 = *(__m128 *)&freqdata[v8].r;
      v14 = (unsigned int)nfft - v8 - 1;
      v15 = v8 - 1;
      v8 += 2;
      v16 = _mm_mul_ps(
              _mm_shuffle_ps(*(__m128 *)&freqdata[v14].r, *(__m128 *)&freqdata[v14].r, 78),
              _xmm_bf8000003f800000bf8000003f800000);
      v17 = _mm_add_ps(v16, v13);
      v18 = _mm_sub_ps(v13, v16);
      v19 = _mm_add_ps(
              _mm_mul_ps(
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 245), _xmm),
                _mm_shuffle_ps(*(__m128 *)&super_twiddles[v15].r, *(__m128 *)&super_twiddles[v15].r, 177)),
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 160), *(__m128 *)&super_twiddles[v15].r));
      v20 = _mm_add_ps(v19, v17);
      v21 = _mm_mul_ps(_mm_sub_ps(v17, v19), _xmm_bf8000003f800000bf8000003f800000);
      *(__m128 *)&tmpbuf[v12].r = v20;
      *(__m128 *)&tmpbuf[v14].r = _mm_shuffle_ps(v21, v21, 78);
    }
    while ( v8 <= v11 );
  }
  DSP::AkFFTSubsetButterflies::ak_fft(substate, tmpbuf, timedata);
}


// File Line: 60
// RVA: 0xB19B20
ak_fftr_state *__fastcall DSP::AkFFTSubsetButterflies::ak_fftr_alloc(int nfft, int inverse_fft, void *mem, unsigned __int64 *lenmem)
{
  __int64 v4; // rbx
  unsigned __int64 *v5; // r14
  _QWORD *v6; // r15
  int v7; // ebp
  int v9; // esi
  _QWORD *v10; // rdi
  unsigned __int64 v11; // rdx
  unsigned __int64 v12; // rax
  bool v13; // cf
  int v14; // eax
  bool v15; // zf
  __int64 v16; // rbp
  __m128i v17; // xmm0
  signed int v18; // esi
  double v19; // xmm7_8
  double v20; // xmm6_8
  float v21; // xmm1_4
  float v22; // xmm1_4
  __m128i v23; // xmm0
  signed int v24; // esi
  double v25; // xmm7_8
  double v26; // xmm6_8
  float v27; // xmm1_4
  float v28; // xmm1_4
  unsigned __int64 lenmema; // [rsp+20h] [rbp-68h]

  v4 = 0i64;
  v5 = lenmem;
  v6 = mem;
  v7 = inverse_fft;
  if ( nfft & 1 )
    return 0i64;
  v9 = nfft >> 1;
  DSP::AkFFTSubsetButterflies::ak_fft_alloc(nfft >> 1, inverse_fft, 0i64, &lenmema);
  v10 = 0i64;
  v11 = lenmema;
  v12 = lenmema + 8 * (3 * v9 / 2 + 4i64);
  v13 = *v5 < v12;
  *v5 = v12;
  if ( !v13 )
    v10 = v6;
  if ( !v10 )
    return 0i64;
  v10[1] = (char *)v10 + v11 + 32;
  v10[2] = (char *)&v10[v9 + 4] + v11;
  *v10 = v10 + 4;
  DSP::AkFFTSubsetButterflies::ak_fft_alloc(v9, v7, v10 + 4, &lenmema);
  v14 = v9 / 2;
  v15 = v7 == 0;
  v16 = v9 / 2;
  if ( v15 )
  {
    if ( v14 > 0 )
    {
      v23 = _mm_cvtsi32_si128(v9);
      v24 = 1;
      v25 = 1.0 / COERCE_DOUBLE(_mm_cvtepi32_pd(v23));
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
    v19 = 1.0 / COERCE_DOUBLE(_mm_cvtepi32_pd(v17));
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
void __fastcall DSP::AkFFTAllButterflies::ak_fftr(ak_fftr_state *st, const float *timedata, ak_fft_cpx *freqdata)
{
  ak_fftr_state *v3; // rbx
  ak_fft_state *v4; // rcx
  ak_fft_cpx *v5; // rdi
  __int64 v6; // rsi
  ak_fft_cpx *v7; // r10
  ak_fft_cpx *v8; // rbx
  unsigned int i; // er9
  __int64 v10; // rdx
  __m128 v11; // xmm3
  __int64 v12; // r8
  __m128 v13; // xmm0
  __int64 v14; // rax
  __m128 v15; // xmm0
  __m128 v16; // xmm4
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm4
  ak_fft_cpx v20; // [rsp+50h] [rbp+8h]

  v3 = st;
  v4 = st->substate;
  v5 = freqdata;
  v6 = v4->nfft;
  DSP::AkFFTAllButterflies::ak_fft(v4, (ak_fft_cpx *)timedata, v3->tmpbuf);
  v7 = v3->tmpbuf;
  v8 = v3->super_twiddles;
  for ( i = 1; i <= (signed int)v6 / 2; *(__m128 *)&v5[v12].r = _mm_shuffle_ps(v19, v19, 78) )
  {
    v10 = i;
    v11 = *(__m128 *)&v7[i].r;
    v12 = (unsigned int)v6 - i - 1;
    v13 = *(__m128 *)&v7[v12].r;
    v14 = i - 1;
    i += 2;
    v15 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 78), _xmm_bf8000003f800000bf8000003f800000);
    v16 = _mm_add_ps(v15, v11);
    v17 = _mm_sub_ps(v11, v15);
    v18 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(_mm_shuffle_ps(v17, v17, 245), _xmm),
              _mm_shuffle_ps(*(__m128 *)&v8[v14].r, *(__m128 *)&v8[v14].r, 177)),
            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 160), *(__m128 *)&v8[v14].r));
    *(__m128 *)&v5[v10].r = _mm_mul_ps(_mm_add_ps(v18, v16), *(__m128 *)_xmm);
    v19 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v16, v18), _xmm_bf8000003f800000bf8000003f800000), *(__m128 *)_xmm);
  }
  v20 = *v7;
  v5->r = v20.i + v20.r;
  v5[v6].r = v20.r - v20.i;
  v5->i = 0.0;
  v5[v6].i = 0.0;
}

// File Line: 229
// RVA: 0xB19E80
void __fastcall DSP::AkFFTSubsetButterflies::ak_fftri(ak_fftr_state *st, ak_fft_cpx *freqdata, float *timedata)
{
  ak_fft_cpx *v3; // r9
  ak_fft_state *v4; // rdi
  __int64 v5; // r11
  ak_fft_cpx *v6; // r14
  ak_fft_cpx *v7; // r10
  unsigned int v8; // ebx
  ak_fft_cpx *v9; // rbp
  float v10; // xmm2_4
  unsigned int v11; // esi
  __int64 v12; // rdx
  __m128 v13; // xmm3
  __int64 v14; // r8
  __m128 v15; // xmm0
  __int64 v16; // rax
  __m128 v17; // xmm0
  __m128 v18; // xmm4
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm0
  __m128 v22; // xmm4

  v3 = st->tmpbuf;
  v4 = st->substate;
  v5 = st->substate->nfft;
  v6 = st->super_twiddles;
  v7 = freqdata;
  v8 = 1;
  v9 = (ak_fft_cpx *)timedata;
  v10 = freqdata->r - freqdata[v5].r;
  v11 = st->substate->nfft / 2;
  v3->r = freqdata->r + freqdata[v5].r;
  v3->i = v10;
  if ( v11 >= 1 )
  {
    do
    {
      v12 = v8;
      v13 = *(__m128 *)&v7[v8].r;
      v14 = (unsigned int)v5 - v8 - 1;
      v15 = *(__m128 *)&v7[v14].r;
      v16 = v8 - 1;
      v8 += 2;
      v17 = _mm_mul_ps(_mm_shuffle_ps(v15, v15, 78), _xmm_bf8000003f800000bf8000003f800000);
      v18 = _mm_add_ps(v17, v13);
      v19 = _mm_sub_ps(v13, v17);
      v20 = _mm_add_ps(
              _mm_mul_ps(
                _mm_mul_ps(_mm_shuffle_ps(v19, v19, 245), _xmm),
                _mm_shuffle_ps(*(__m128 *)&v6[v16].r, *(__m128 *)&v6[v16].r, 177)),
              _mm_mul_ps(_mm_shuffle_ps(v19, v19, 160), *(__m128 *)&v6[v16].r));
      v21 = _mm_add_ps(v20, v18);
      v22 = _mm_mul_ps(_mm_sub_ps(v18, v20), _xmm_bf8000003f800000bf8000003f800000);
      *(__m128 *)&v3[v12].r = v21;
      *(__m128 *)&v3[v14].r = _mm_shuffle_ps(v22, v22, 78);
    }
    while ( v8 <= v11 );
  }
  DSP::AkFFTSubsetButterflies::ak_fft(v4, v3, v9);
}


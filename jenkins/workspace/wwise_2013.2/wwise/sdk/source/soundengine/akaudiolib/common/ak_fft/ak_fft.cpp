// File Line: 37
// RVA: 0xAF0DE0
void __fastcall DSP::AkFFTAllButterflies::kf_bfly2(
        ak_fft_cpx *Fout,
        const unsigned __int64 fstride,
        ak_fft_state *const st,
        int m)
{
  ak_fft_cpx *twiddles; // r10
  unsigned __int64 v5; // rdx
  ak_fft_cpx *v6; // r8
  float r; // xmm1_4
  float i; // xmm2_4
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm5_4

  twiddles = st->twiddles;
  v5 = 8 * fstride;
  v6 = &Fout[m];
  do
  {
    r = twiddles->r;
    i = twiddles->i;
    v9 = v6->i;
    ++Fout;
    twiddles = (ak_fft_cpx *)((char *)twiddles + v5);
    ++v6;
    v10 = i * v9;
    v11 = (float)(v9 * r) + (float)(i * v6[-1].r);
    v12 = (float)(r * v6[-1].r) - v10;
    v6[-1].r = Fout[-1].r - v12;
    v6[-1].i = Fout[-1].i - v11;
    v13 = v11 + Fout[-1].i;
    Fout[-1].r = v12 + Fout[-1].r;
    Fout[-1].i = v13;
    --m;
  }
  while ( m );
}

// File Line: 130
// RVA: 0xAF0E70
void __fastcall DSP::AkFFTAllButterflies::kf_bfly4_m1_n1024(ak_fft_cpx *Fout, ak_fft_state *const st)
{
  ak_fft_cpx *twiddles; // rax
  float i; // xmm11_4
  float v4; // xmm12_4
  float v5; // xmm8_4
  float v6; // xmm7_4
  ak_fft_cpx v7; // [rsp+80h] [rbp+8h]
  ak_fft_cpx v8; // [rsp+90h] [rbp+18h]
  ak_fft_cpx v9; // [rsp+98h] [rbp+20h]

  twiddles = st->twiddles;
  i = twiddles[768].i;
  v4 = twiddles[256].i;
  v5 = COERCE_FLOAT(*Fout);
  LODWORD(v6) = HIDWORD(*(unsigned __int64 *)Fout);
  v7 = Fout[1];
  v8 = Fout[2];
  v9 = Fout[3];
  Fout->r = (float)((float)(v7.r + v5) + v8.r) + v9.r;
  Fout->i = (float)((float)(v7.i + v6) + v8.i) + v9.i;
  Fout[1].r = (float)((float)(v5 - (float)(v7.i * v4)) - v8.r) - (float)(v9.i * i);
  Fout[1].i = (float)((float)((float)(v7.r * v4) + v6) - v8.i) + (float)(v9.r * i);
  Fout[2].i = (float)((float)(v6 - v7.i) + v8.i) - v9.i;
  Fout[3].r = (float)((float)(v5 - (float)(v7.i * i)) - v8.r) - (float)(v9.i * v4);
  Fout[2].r = (float)((float)(v5 - v7.r) + v8.r) - v9.r;
  Fout[3].i = (float)((float)((float)(v7.r * i) + v6) - v8.i) + (float)(v9.r * v4);
}

// File Line: 238
// RVA: 0xAF1010
__m128 __fastcall DSP::AkFFTAllButterflies::AKSIMD_LOADUNALIGNED_DUAL(
        __m128 *result,
        __m128 *in_dAddress1,
        float *in_dAddress2)
{
  return _mm_movelh_ps(*result, *in_dAddress1);
}

// File Line: 330
// RVA: 0xB1A370
void __fastcall DSP::AkFFTSubsetButterflies::kf_bfly4(
        ak_fft_cpx *Fout,
        unsigned __int64 fstride,
        ak_fft_state *const st,
        unsigned __int64 m)
{
  ak_fft_cpx *twiddles; // r11
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // r10
  float *v8; // rbx
  float *v9; // rdi
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rbp
  __m128 v12; // xmm6
  __m128 v13; // xmm7
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // r15
  unsigned __int64 v16; // r12
  unsigned __int64 v17; // r13
  unsigned __int64 v18; // rdx
  __int64 v19; // rbp
  ak_fft_cpx *v20; // r8
  unsigned __int64 v21; // rsi
  unsigned __int64 v22; // r10
  __int64 v23; // rax
  __int64 v24; // r9
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm0
  __m128 v28; // xmm2
  __m128 v29; // xmm5
  __m128 v30; // xmm0
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  __m128 v33; // xmm5
  __m128 v34; // xmm0
  __m128 v35; // xmm5
  __m128 v36; // xmm1
  __m128 v37; // xmm2
  __m128 v38; // xmm3
  __m128 v39; // xmm0
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm3
  __m128 v43; // xmm0
  __m128 v44; // xmm3
  __m128 v45; // xmm2
  __m128 v46; // xmm4
  __m128 v47; // xmm5
  __m128 v48; // xmm3
  __m128 v49; // xmm2
  __m128 v50; // xmm1
  __m128 v51; // xmm2
  __m128 v52; // xmm0
  __int64 inverse; // r15
  unsigned __int64 v54; // r8
  float *p_i; // rax
  unsigned __int64 v56; // rcx
  unsigned __int64 v57; // rdx
  __int64 v58; // rbp
  float v59; // xmm9_4
  float v60; // xmm8_4
  float v61; // xmm4_4
  float v62; // xmm5_4
  float v63; // xmm2_4
  float v64; // xmm7_4
  float v65; // xmm8_4
  float v66; // xmm5_4
  float v67; // xmm6_4
  float v68; // xmm9_4
  float v69; // xmm4_4
  float v70; // xmm5_4
  float v71; // xmm3_4
  float v72; // xmm1_4
  float v73; // xmm2_4
  float v74; // xmm3_4
  float v75; // xmm7_4
  float v76; // xmm0_4
  float v77; // xmm1_4
  float v78; // xmm2_4
  float v79; // xmm3_4

  twiddles = st->twiddles;
  v6 = 2 * m;
  v7 = 3 * m;
  v8 = (float *)twiddles;
  v9 = (float *)twiddles;
  v10 = 2 * fstride;
  v11 = 3 * fstride;
  if ( m < 2 )
  {
    inverse = st->inverse;
    v54 = 16 * fstride;
    p_i = &Fout->i;
    v56 = 2 * m;
    v57 = 8 * fstride;
    v58 = 8 * v11;
    do
    {
      v59 = (float)(twiddles->r * p_i[v56 - 1]) - (float)(twiddles->i * p_i[v56]);
      v60 = (float)(twiddles->r * p_i[v56]) + (float)(twiddles->i * p_i[v56 - 1]);
      v61 = (float)(*v9 * p_i[2 * v7 - 1]) - (float)(v9[1] * p_i[2 * v7]);
      v62 = (float)(*v9 * p_i[2 * v7]) + (float)(v9[1] * p_i[2 * v7 - 1]);
      v63 = *(p_i - 1);
      v64 = v62 + v60;
      v65 = v60 - v62;
      v66 = v8[1];
      v67 = v61 + v59;
      v68 = v59 - v61;
      v69 = (float)(*v8 * p_i[2 * v6 - 1]) - (float)(v66 * p_i[2 * v6]);
      v70 = (float)(v66 * p_i[2 * v6 - 1]) + (float)(*v8 * p_i[2 * v6]);
      v71 = *p_i;
      v72 = v63 + v69;
      v73 = v63 - v69;
      *p_i = *p_i + v70;
      *(p_i - 1) = v72;
      p_i[2 * v6 - 1] = v72 - v67;
      v74 = v71 - v70;
      p_i[2 * v6] = *p_i - v64;
      v75 = v64 + *p_i;
      *(p_i - 1) = v67 + *(p_i - 1);
      *p_i = v75;
      if ( inverse )
      {
        v76 = v73 - v65;
        v77 = v74 + v68;
        v78 = v73 + v65;
        v79 = v74 - v68;
      }
      else
      {
        v76 = v73 + v65;
        v77 = v74 - v68;
        v78 = v73 - v65;
        v79 = v74 + v68;
      }
      p_i[v56 - 1] = v76;
      p_i[v56] = v77;
      p_i[2 * v7] = v79;
      twiddles = (ak_fft_cpx *)((char *)twiddles + v57);
      v8 = (float *)((char *)v8 + v54);
      v9 = (float *)((char *)v9 + v58);
      p_i[2 * v7 - 1] = v78;
      p_i += 2;
      --m;
    }
    while ( m );
  }
  else
  {
    v12 = _xmm_bf8000003f800000bf8000003f800000;
    v13 = _xmm;
    v14 = m >> 1;
    if ( st->inverse )
    {
      v12 = _xmm;
      v13 = _xmm_bf8000003f800000bf8000003f800000;
    }
    v15 = fstride;
    v16 = 6 * fstride;
    v17 = 4 * fstride;
    v18 = 16 * fstride;
    v19 = 16 * v11;
    v20 = &Fout[m];
    v21 = m;
    v22 = 2 * m;
    v23 = 16 * v10;
    v24 = -(__int64)m;
    do
    {
      v25 = *(__m128 *)&v20->r;
      v26 = *(__m128 *)&twiddles->r;
      v27 = *(__m128 *)&twiddles[v15].r;
      v20 += 2;
      twiddles = (ak_fft_cpx *)((char *)twiddles + v18);
      v28 = _mm_movelh_ps(v26, v27);
      v29 = _mm_shuffle_ps(v25, v25, 245);
      v30 = _mm_shuffle_ps(v28, v28, 177);
      v31 = _mm_mul_ps(_mm_shuffle_ps(v25, v25, 160), v28);
      v32 = *(__m128 *)v9;
      v33 = _mm_mul_ps(_mm_mul_ps(v29, _xmm), v30);
      v34 = *(__m128 *)&v9[v16];
      v9 = (float *)((char *)v9 + v19);
      v35 = _mm_add_ps(v33, v31);
      v36 = *(__m128 *)&v20[v22 - 2].r;
      v37 = _mm_movelh_ps(v32, v34);
      v38 = _mm_shuffle_ps(v36, v36, 245);
      v39 = _mm_shuffle_ps(v37, v37, 177);
      v40 = _mm_mul_ps(_mm_shuffle_ps(v36, v36, 160), v37);
      v41 = *(__m128 *)v8;
      v42 = _mm_mul_ps(_mm_mul_ps(v38, _xmm), v39);
      v43 = *(__m128 *)&v8[v17];
      v8 = (float *)((char *)v8 + v23);
      v44 = _mm_add_ps(v42, v40);
      v45 = _mm_movelh_ps(v41, v43);
      v46 = _mm_add_ps(v44, v35);
      v47 = _mm_sub_ps(v35, v44);
      v48 = _mm_add_ps(
              _mm_mul_ps(
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v20[v21 - 2].r, *(__m128 *)&v20[v21 - 2].r, 245), _xmm),
                _mm_shuffle_ps(v45, v45, 177)),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v20[v21 - 2].r, *(__m128 *)&v20[v21 - 2].r, 160), v45));
      v49 = *(__m128 *)&v20[v24 - 2].r;
      v50 = _mm_add_ps(v49, v48);
      v51 = _mm_sub_ps(v49, v48);
      *(__m128 *)&v20[v21 - 2].r = _mm_sub_ps(v50, v46);
      v52 = _mm_shuffle_ps(v47, v47, 177);
      *(__m128 *)&v20[v24 - 2].r = _mm_add_ps(v50, v46);
      *(__m128 *)&v20[-2].r = _mm_add_ps(_mm_mul_ps(v52, v12), v51);
      *(__m128 *)&v20[v22 - 2].r = _mm_add_ps(_mm_mul_ps(v52, v13), v51);
      --v14;
    }
    while ( v14 );
  }
}

// File Line: 520
// RVA: 0xAF1390
void __fastcall DSP::AkFFTAllButterflies::kf_bfly4_m1_s256_n1024_SIMD(
        ak_fft_cpx *Fout,
        ak_fft_cpx *Fin,
        ak_fft_state *const st)
{
  __m128 v3; // xmm6
  char v5; // r8
  __m128 v6; // xmm14
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 v9; // xmm7
  __m128 v10; // xmm8
  __m128 v11; // xmm4
  __m128 v12; // xmm2
  __m128 v13; // xmm5
  __m128 v14; // xmm3
  __m128 v15; // xmm4
  __m128 v16; // xmm2
  __m128 v17; // xmm5
  __m128 v18; // xmm3
  __m128 v19; // xmm7
  __m128 v20; // xmm8
  __m128 v21; // xmm12
  __m128 v22; // xmm15
  __m128 v23; // xmm0
  __m128 v24; // xmm13
  __m128 v25; // xmm11
  __m128 v26; // xmm15
  __m128 v27; // xmm13
  __m128 v28; // xmm2
  __m128 v29; // xmm12
  __m128 v30; // xmm11
  __m128 v31; // xmm15
  __m128 v32; // xmm4
  __m128 v33; // xmm3
  __m128 v34; // xmm12
  __m128 v35; // xmm11
  __m128 v36; // xmm5
  __m128 v37; // xmm12
  __m128 v38; // xmm11
  __m128 v39; // xmm0
  __m128 v40; // xmm1
  __m128 v41; // xmm4
  __m128 v42; // xmm2
  __m128 v43; // xmm8
  __m128 v44; // xmm3
  ak_fft_cpx *simdTwiddles; // rax
  __m128 v46; // xmm1
  __m128 v47; // xmm5
  __m128 v48; // xmm7
  __m128 v49; // xmm10
  __m128 v50; // xmm7
  __m128 v51; // xmm10
  __m128 v52; // xmm2
  __m128 v53; // xmm15
  __m128 v54; // xmm7
  __m128 v55; // xmm9
  __m128 v56; // xmm5
  __m128 v57; // xmm6
  __m128 v58; // xmm2
  __m128 v59; // xmm7
  __m128 v60; // xmm3
  __m128 v61; // xmm4
  __m128 v62; // xmm6
  __m128 v63; // xmm6
  __m128 v64; // xmm2
  __m128 v65; // xmm1
  __m128 v66; // xmm15
  __m128 v67; // xmm1
  __m128 v68; // xmm2
  __m128 v69; // xmm0
  __m128 v70; // xmm5
  __m128 v71; // xmm2
  __m128 v72; // xmm1
  __m128 v73; // xmm5
  __m128 v74; // xmm0
  __m128 v75; // xmm5
  __m128 v76; // xmm2
  __m128 v77; // xmm10
  __m128 v78; // xmm3
  __m128 v79; // xmm2
  __m128 v80; // xmm1
  __m128 v81; // xmm3
  __m128 v82; // xmm0
  __m128 v83; // xmm3
  __m128 v84; // xmm2
  __m128 v85; // xmm4
  __m128 v86; // xmm5
  __m128 v87; // xmm10
  __m128 v88; // xmm1
  __m128 v89; // xmm5
  __m128 v90; // xmm2
  __m128 v91; // xmm13
  __m128 v92; // xmm0

  v3 = _xmm;
  if ( st->inverse )
    v3 = _mm_xor_ps(_xmm, *(__m128 *)_xmm);
  v5 = 0;
  v6 = _mm_xor_ps(*(__m128 *)_xmm, v3);
  if ( ((unsigned __int8)Fin & 0xF) != 0 )
  {
    --Fin;
    v5 = 1;
  }
  v7 = *(__m128 *)&Fin->r;
  v8 = *(__m128 *)&Fin[256].r;
  v9 = *(__m128 *)&Fin[512].r;
  v10 = *(__m128 *)&Fin[768].r;
  v11 = *(__m128 *)&Fin[64].r;
  v12 = *(__m128 *)&Fin[320].r;
  v13 = *(__m128 *)&Fin[576].r;
  v14 = *(__m128 *)&Fin[832].r;
  if ( v5 )
  {
    v15 = _mm_movehl_ps(v11, v7);
    v16 = _mm_movehl_ps(v12, v8);
    v17 = _mm_movehl_ps(v13, v9);
    v18 = _mm_movehl_ps(v14, v10);
  }
  else
  {
    v15 = _mm_movelh_ps(v7, v11);
    v16 = _mm_movelh_ps(v8, v12);
    v17 = _mm_movelh_ps(v9, v13);
    v18 = _mm_movelh_ps(v10, v14);
  }
  v19 = *(__m128 *)&Fin[896].r;
  v20 = *(__m128 *)&Fin[704].r;
  v21 = _mm_shuffle_ps(v16, v16, 177);
  v22 = _mm_add_ps(v17, v15);
  v23 = _mm_shuffle_ps(v18, v18, 177);
  v24 = _mm_sub_ps(v22, v16);
  v25 = _mm_mul_ps(v21, v3);
  v26 = _mm_add_ps(v22, v16);
  v27 = _mm_sub_ps(v24, v18);
  v28 = *(__m128 *)&Fin[448].r;
  v29 = _mm_add_ps(_mm_mul_ps(v21, v6), v15);
  v30 = _mm_add_ps(v25, v15);
  v31 = _mm_add_ps(v26, v18);
  v32 = *(__m128 *)&Fin[192].r;
  v33 = *(__m128 *)&Fin[960].r;
  v34 = _mm_sub_ps(v29, v17);
  v35 = _mm_sub_ps(v30, v17);
  v36 = *(__m128 *)&Fin[640].r;
  v37 = _mm_add_ps(v34, _mm_mul_ps(v23, v3));
  v38 = _mm_add_ps(v35, _mm_mul_ps(v23, v6));
  v39 = *(__m128 *)&Fin[128].r;
  v40 = *(__m128 *)&Fin[384].r;
  if ( v5 )
  {
    v41 = _mm_movehl_ps(v32, v39);
    v42 = _mm_movehl_ps(v28, v40);
    v43 = _mm_movehl_ps(v20, v36);
    v44 = _mm_movehl_ps(v33, v19);
  }
  else
  {
    v41 = _mm_movelh_ps(v39, v32);
    v42 = _mm_movelh_ps(v40, v28);
    v43 = _mm_movelh_ps(v36, v20);
    v44 = _mm_movelh_ps(v19, v33);
  }
  simdTwiddles = st->simdTwiddles;
  v46 = _mm_shuffle_ps(v44, v44, 177);
  v47 = _mm_shuffle_ps(v42, v42, 177);
  v48 = _mm_add_ps(v43, v41);
  v49 = _mm_sub_ps(v48, v42);
  v50 = _mm_add_ps(v48, v42);
  v51 = _mm_sub_ps(v49, v44);
  v52 = _mm_movehl_ps(v37, v31);
  v53 = _mm_movelh_ps(v31, v37);
  v54 = _mm_add_ps(v50, v44);
  v55 = _mm_add_ps(_mm_sub_ps(_mm_add_ps(_mm_mul_ps(v47, v3), v41), v43), _mm_mul_ps(v46, v6));
  v56 = _mm_add_ps(_mm_sub_ps(_mm_add_ps(_mm_mul_ps(v47, v6), v41), v43), _mm_mul_ps(v46, v3));
  v57 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(_mm_shuffle_ps(v52, v52, 245), _xmm),
            _mm_shuffle_ps(*(__m128 *)&simdTwiddles->r, *(__m128 *)&simdTwiddles->r, 177)),
          _mm_mul_ps(_mm_shuffle_ps(v52, v52, 160), *(__m128 *)&simdTwiddles->r));
  v58 = _mm_movehl_ps(v56, v54);
  v59 = _mm_movelh_ps(v54, v56);
  v60 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(_mm_shuffle_ps(v58, v58, 245), _xmm),
            _mm_shuffle_ps(*(__m128 *)&simdTwiddles[4].r, *(__m128 *)&simdTwiddles[4].r, 177)),
          _mm_mul_ps(_mm_shuffle_ps(v58, v58, 160), *(__m128 *)&simdTwiddles[4].r));
  v61 = _mm_add_ps(v60, v57);
  v62 = _mm_sub_ps(v57, v60);
  v63 = _mm_mul_ps(_mm_shuffle_ps(v62, v62, 177), v6);
  v64 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(_mm_shuffle_ps(v59, v59, 245), _xmm),
            _mm_shuffle_ps(*(__m128 *)&simdTwiddles[2].r, *(__m128 *)&simdTwiddles[2].r, 177)),
          _mm_mul_ps(_mm_shuffle_ps(v59, v59, 160), *(__m128 *)&simdTwiddles[2].r));
  v65 = _mm_sub_ps(v53, v64);
  v66 = _mm_add_ps(v53, v64);
  *(__m128 *)&Fout[8].r = _mm_sub_ps(v66, v61);
  *(__m128 *)&Fout->r = _mm_add_ps(v66, v61);
  *(__m128 *)&Fout[4].r = _mm_add_ps(v65, v63);
  *(__m128 *)&Fout[12].r = _mm_sub_ps(v65, v63);
  v67 = *(__m128 *)&simdTwiddles[6].r;
  v68 = _mm_movehl_ps(v38, v27);
  v69 = _mm_shuffle_ps(v67, v67, 177);
  v70 = _mm_shuffle_ps(v68, v68, 245);
  v71 = _mm_mul_ps(_mm_shuffle_ps(v68, v68, 160), v67);
  v72 = *(__m128 *)&simdTwiddles[10].r;
  v73 = _mm_mul_ps(_mm_mul_ps(v70, _xmm), v69);
  v74 = _mm_shuffle_ps(v72, v72, 177);
  v75 = _mm_add_ps(v73, v71);
  v76 = _mm_movehl_ps(v55, v51);
  v77 = _mm_movelh_ps(v51, v55);
  v78 = _mm_shuffle_ps(v76, v76, 245);
  v79 = _mm_mul_ps(_mm_shuffle_ps(v76, v76, 160), v72);
  v80 = *(__m128 *)&simdTwiddles[8].r;
  v81 = _mm_mul_ps(_mm_mul_ps(v78, _xmm), v74);
  v82 = _mm_shuffle_ps(v80, v80, 177);
  v83 = _mm_add_ps(v81, v79);
  v84 = _mm_shuffle_ps(v77, v77, 245);
  v85 = _mm_add_ps(v83, v75);
  v86 = _mm_sub_ps(v75, v83);
  v87 = _mm_mul_ps(_mm_shuffle_ps(v77, v77, 160), v80);
  v88 = _mm_movelh_ps(v27, v38);
  v89 = _mm_mul_ps(_mm_shuffle_ps(v86, v86, 177), v6);
  v90 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v84, _xmm), v82), v87);
  v91 = _mm_add_ps(v88, v90);
  *(__m128 *)&Fout[10].r = _mm_sub_ps(v91, v85);
  *(__m128 *)&Fout[2].r = _mm_add_ps(v91, v85);
  v92 = _mm_sub_ps(v88, v90);
  *(__m128 *)&Fout[6].r = _mm_add_ps(v92, v89);
  *(__m128 *)&Fout[14].r = _mm_sub_ps(v92, v89);
}

// File Line: 771
// RVA: 0xAF1760
void __fastcall DSP::AkFFTAllButterflies::kf_bfly3(
        ak_fft_cpx *Fout,
        const unsigned __int64 fstride,
        ak_fft_state *const st,
        unsigned __int64 m)
{
  ak_fft_cpx *twiddles; // r10
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rdx
  unsigned __int64 v8; // r11
  float *v9; // r8
  float *p_i; // rcx
  unsigned __int64 v11; // rax
  float v12; // xmm5_4
  float v13; // xmm8_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm7_4
  float v18; // xmm0_4
  float v19; // xmm8_4
  float v20; // xmm7_4
  float v21; // xmm7_4
  float v22; // xmm8_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  float v26; // xmm5_4
  float v27; // xmm3_4
  float v28; // xmm7_4
  float v29; // xmm6_4
  float v30; // xmm8_4
  float v31; // xmm6_4
  float v32; // xmm0_4
  ak_fft_cpx v33; // [rsp+60h] [rbp+8h]

  twiddles = st->twiddles;
  v6 = 8 * fstride;
  v7 = 16 * fstride;
  v8 = 2 * m;
  v9 = (float *)twiddles;
  p_i = &Fout->i;
  v33 = twiddles[m * fstride];
  v11 = 2 * m;
  do
  {
    v12 = p_i[2 * v8 - 1];
    v13 = p_i[v11 - 1];
    v14 = p_i[v11];
    p_i += 2;
    v15 = v14;
    v16 = v14 * *v9;
    v17 = v13;
    v18 = v15 * v9[1];
    v19 = v13 * v9[1];
    v20 = v17 * *v9;
    v9 = (float *)((char *)v9 + v6);
    v21 = v20 - v18;
    v22 = v19 + v16;
    v23 = p_i[2 * v8 - 2] * twiddles->r;
    v24 = (float)(v12 * twiddles->r) - (float)(p_i[2 * v8 - 2] * twiddles->i);
    v25 = v12 * twiddles->i;
    twiddles = (ak_fft_cpx *)((char *)twiddles + v7);
    v26 = v25 + v23;
    v27 = v24 + v21;
    v28 = (float)(v21 - v24) * v33.i;
    v29 = v26 + v22;
    v30 = (float)(v22 - v26) * v33.i;
    p_i[v11 - 3] = *(p_i - 3) - (float)(v27 * 0.5);
    p_i[v11 - 2] = *(p_i - 2) - (float)(v29 * 0.5);
    v31 = v29 + *(p_i - 2);
    *(p_i - 3) = v27 + *(p_i - 3);
    *(p_i - 2) = v31;
    p_i[2 * v8 - 3] = v30 + p_i[v11 - 3];
    p_i[2 * v8 - 2] = p_i[v11 - 2] - v28;
    v32 = p_i[v11 - 3] - v30;
    p_i[v11 - 2] = v28 + p_i[v11 - 2];
    p_i[v11 - 3] = v32;
    --m;
  }
  while ( m );
}

// File Line: 815
// RVA: 0xAF1920
void __fastcall DSP::AkFFTAllButterflies::kf_bfly5(
        ak_fft_cpx *Fout,
        const unsigned __int64 fstride,
        ak_fft_state *const st,
        unsigned int m)
{
  ak_fft_cpx *twiddles; // r11
  unsigned __int64 v5; // r8
  __int64 v6; // r8
  ak_fft_cpx *v7; // r12
  float *p_i; // rcx
  unsigned __int64 v9; // rax
  __int64 v10; // rdi
  __int64 v11; // rsi
  __int64 v12; // r11
  float *v13; // rbx
  unsigned __int64 v14; // r14
  unsigned __int64 v15; // r15
  unsigned __int64 v16; // rdx
  __int64 v17; // rbp
  __int64 v18; // r13
  __int64 v19; // r8
  float *v20; // r10
  float *v21; // r9
  float v22; // xmm3_4
  float v23; // xmm14_4
  float v24; // xmm4_4
  float v25; // xmm15_4
  float v26; // xmm14_4
  float v27; // xmm12_4
  float v28; // xmm13_4
  float v29; // xmm7_4
  float v30; // xmm6_4
  float v31; // xmm9_4
  float v32; // xmm13_4
  float v33; // xmm8_4
  float v34; // xmm12_4
  float v35; // xmm4_4
  float v36; // xmm5_4
  float v37; // xmm10_4
  float v38; // xmm15_4
  float v39; // xmm11_4
  float v40; // xmm4_4
  float v41; // xmm14_4
  float v42; // xmm1_4
  float v43; // xmm5_4
  float v44; // xmm4_4
  float v45; // xmm3_4
  float v46; // xmm2_4
  float v47; // xmm13_4
  float v48; // xmm15_4
  float v49; // xmm10_4
  float v50; // xmm11_4
  float v51[28]; // [rsp+20h] [rbp-148h]
  ak_fft_cpx v52; // [rsp+170h] [rbp+8h]
  ak_fft_cpx v53; // [rsp+178h] [rbp+10h]
  float *v54; // [rsp+180h] [rbp+18h]

  twiddles = st->twiddles;
  v5 = fstride * (int)m;
  v53 = twiddles[v5];
  v52 = twiddles[2 * v5];
  v6 = (int)(3 * m);
  v7 = &Fout[v6];
  if ( (int)m > 0 )
  {
    p_i = &twiddles->i;
    v9 = 8 * fstride;
    v10 = (int)(4 * m) - (__int64)(int)m;
    v11 = (int)(2 * m) - (__int64)(int)m;
    v12 = -4 - 8i64 * (int)m;
    v13 = &v7[(int)m - v6].i;
    v14 = 32 * fstride;
    v15 = 24 * fstride;
    v16 = 16 * fstride;
    v17 = -(__int64)(int)m;
    v18 = m;
    v19 = v6 - (int)m;
    v20 = p_i;
    v54 = p_i;
    v21 = p_i;
    do
    {
      v22 = *(v13 - 1);
      v23 = *(p_i - 1);
      *(_QWORD *)v51 = *(_QWORD *)((char *)v13 + v12);
      v24 = *(v21 - 1);
      v25 = (float)(v22 * v23) - (float)(*p_i * *v13);
      v26 = (float)(v23 * *v13) + (float)(v22 * *p_i);
      v27 = (float)(*(v20 - 1) * v13[2 * v11 - 1]) - (float)(v13[2 * v11] * *v20);
      v28 = (float)(v13[2 * v11] * *(v20 - 1)) + (float)(*v20 * v13[2 * v11 - 1]);
      v29 = (float)(v7->r * *v21) + (float)(v24 * v13[2 * v19]);
      v30 = (float)(v7->r * v24) - (float)(*v21 * v13[2 * v19]);
      v31 = v29 + v28;
      v32 = v28 - v29;
      v33 = v30 + v27;
      v34 = v27 - v30;
      v35 = (float)(v13[2 * v10 - 1] * *(v54 - 1)) - (float)(v13[2 * v10] * *v54);
      v36 = (float)(v13[2 * v10 - 1] * *v54) + (float)(v13[2 * v10] * *(v54 - 1));
      v37 = v35 + v25;
      v38 = v25 - v35;
      v39 = v36 + v26;
      v40 = (float)((float)(v36 + v26) * v53.r) + v51[1];
      v41 = v26 - v36;
      v42 = (float)(v31 + v39) + v13[2 * v17];
      *(float *)((char *)v13 + v12) = (float)(v33 + v37) + *(float *)((char *)v13 + v12);
      v43 = (float)((float)(v37 * v53.r) + v51[0]) + (float)(v33 * v52.r);
      v13[2 * v17] = v42;
      v44 = v40 + (float)(v31 * v52.r);
      p_i = (float *)((char *)p_i + v9);
      ++v7;
      v13 += 2;
      v20 = (float *)((char *)v20 + v16);
      v21 = (float *)((char *)v21 + v15);
      v54 = (float *)((char *)v54 + v14);
      v45 = (float)(v32 * v52.i) + (float)(v41 * v53.i);
      v46 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v38 * v53.i) ^ _xmm[0]) - (float)(v34 * v52.i);
      v47 = (float)(v32 * v53.i) - (float)(v41 * v52.i);
      *(v13 - 2) = v44 - v46;
      *(v13 - 3) = v43 - v45;
      v13[2 * v10 - 3] = v45 + v43;
      v48 = (float)(v38 * v52.i) - (float)(v34 * v53.i);
      v49 = (float)((float)(v37 * v52.r) + v51[0]) + (float)(v33 * v53.r);
      v50 = (float)((float)(v39 * v52.r) + v51[1]) + (float)(v31 * v53.r);
      v13[2 * v10 - 2] = v46 + v44;
      v13[2 * v11 - 3] = v47 + v49;
      v13[2 * v11 - 2] = v48 + v50;
      v7[-1].r = v49 - v47;
      v13[2 * v19 - 2] = v50 - v48;
      --v18;
    }
    while ( v18 );
  }
}

// File Line: 878
// RVA: 0xAF1DB0
void __fastcall DSP::AkFFTAllButterflies::kf_bfly_generic(
        ak_fft_cpx *Fout,
        const unsigned __int64 fstride,
        ak_fft_state *const st,
        unsigned int m,
        int p)
{
  ak_fft_cpx *twiddles; // rbx
  int nfft; // r10d
  __int64 v7; // rdi
  ak_fft_cpx *v8; // rax
  __int64 v9; // r11
  int v10; // r9d
  int v11; // edx
  __int64 v12; // r8
  __int64 v13; // rcx
  __int64 *v14; // rdx
  __int64 v15; // rax
  __int64 v16; // r13
  int v17; // r8d
  __int64 v18; // r15
  ak_fft_cpx *v19; // rdx
  __int64 v20; // rbp
  int v21; // r14d
  int v22; // edi
  int v23; // ecx
  __int64 v24; // r9
  float r; // xmm6_4
  float i; // xmm7_4
  unsigned int v27; // eax
  __int64 v28; // r11
  int v29; // ecx
  float v30; // xmm3_4
  float v31; // xmm1_4
  __int64 v32; // rax
  int v33; // ecx
  float v34; // xmm2_4
  float v35; // xmm7_4
  float v36; // xmm6_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  __int64 v39; // rax
  int v40; // ecx
  float v41; // xmm3_4
  float v42; // xmm6_4
  float v43; // xmm7_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  __int64 v46; // rax
  float v47; // xmm3_4
  float v48; // xmm6_4
  float v49; // xmm7_4
  float v50; // xmm1_4
  float v51; // xmm2_4
  float v52; // xmm3_4
  float v53; // xmm6_4
  float v54; // xmm7_4
  float *v55; // r11
  __int64 v56; // r9
  __int64 v57; // [rsp+0h] [rbp-178h]
  __int64 v58; // [rsp+8h] [rbp-170h]
  __int64 v59[32]; // [rsp+10h] [rbp-168h] BYREF
  ak_fft_cpx *v60; // [rsp+180h] [rbp+8h]
  int v61; // [rsp+188h] [rbp+10h]
  int v62; // [rsp+190h] [rbp+18h]

  v61 = fstride;
  v60 = Fout;
  twiddles = st->twiddles;
  nfft = st->nfft;
  v7 = m;
  v8 = Fout;
  v9 = (int)m;
  v10 = fstride;
  v58 = v9;
  if ( (int)v7 > 0 )
  {
    v11 = 0;
    v12 = (unsigned int)v7;
    v57 = v7;
    v62 = 0;
    do
    {
      v13 = 0i64;
      if ( p > 0 )
      {
        v14 = (__int64 *)v8;
        do
        {
          v15 = *v14;
          ++v13;
          v14 += v9;
          v59[v13 - 1] = v15;
        }
        while ( v13 < p );
        v16 = v59[0];
        v17 = v62;
        v18 = 8 * v9;
        v19 = v60;
        v20 = (unsigned int)p;
        v21 = v7 * v10;
        do
        {
          v22 = 1;
          v23 = 0;
          *v19 = (ak_fft_cpx)v16;
          v24 = 1i64;
          if ( p > 1 )
          {
            if ( p - 1 >= 4 )
            {
              r = v19->r;
              i = v19->i;
              v27 = ((unsigned int)(p - 5) >> 2) + 1;
              v28 = v27;
              v22 = 4 * v27 + 1;
              do
              {
                v29 = v17 + v23;
                if ( v29 >= nfft )
                  v29 -= nfft;
                v30 = *((float *)&v59[v24] + 1);
                v31 = *(float *)&v59[v24];
                v32 = v29;
                v33 = v17 + v29;
                v34 = twiddles[v32].r;
                v35 = i + (float)((float)(twiddles[v32].i * v31) + (float)(v30 * v34));
                v36 = r + (float)((float)(v34 * v31) - (float)(twiddles[v32].i * v30));
                v19->i = v35;
                v19->r = v36;
                if ( v33 >= nfft )
                  v33 -= nfft;
                v37 = *(float *)&v59[v24 + 1];
                v38 = *((float *)&v59[v24 + 1] + 1);
                v39 = v33;
                v40 = v17 + v33;
                v41 = twiddles[v39].r;
                v42 = v36 + (float)((float)(v41 * v37) - (float)(twiddles[v39].i * v38));
                v43 = v35 + (float)((float)(twiddles[v39].i * v37) + (float)(v41 * v38));
                v19->r = v42;
                v19->i = v43;
                if ( v40 >= nfft )
                  v40 -= nfft;
                v44 = *(float *)&v59[v24 + 2];
                v45 = *((float *)&v59[v24 + 2] + 1);
                v46 = v40;
                v23 = v17 + v40;
                v47 = twiddles[v46].r;
                v48 = v42 + (float)((float)(v47 * v44) - (float)(twiddles[v46].i * v45));
                v49 = v43 + (float)((float)(twiddles[v46].i * v44) + (float)(v47 * v45));
                v19->r = v48;
                v19->i = v49;
                if ( v23 >= nfft )
                  v23 -= nfft;
                v50 = *(float *)&v59[v24 + 3];
                v51 = *((float *)&v59[v24 + 3] + 1);
                v24 += 4i64;
                v52 = twiddles[v23].r;
                r = v48 + (float)((float)(v52 * v50) - (float)(twiddles[v23].i * v51));
                i = v49 + (float)((float)(twiddles[v23].i * v50) + (float)(v52 * v51));
                v19->r = r;
                v19->i = i;
                --v28;
              }
              while ( v28 );
            }
            if ( v22 < p )
            {
              v53 = v19->r;
              v54 = v19->i;
              v55 = (float *)&v59[v24] + 1;
              v56 = (unsigned int)(p - v22);
              do
              {
                v23 += v17;
                if ( v23 >= nfft )
                  v23 -= nfft;
                v55 += 2;
                v53 = v53 + (float)((float)(twiddles[v23].r * *(v55 - 3)) - (float)(twiddles[v23].i * *(v55 - 2)));
                v54 = v54 + (float)((float)(twiddles[v23].i * *(v55 - 3)) + (float)(twiddles[v23].r * *(v55 - 2)));
                v19->r = v53;
                v19->i = v54;
                --v56;
              }
              while ( v56 );
            }
          }
          v17 += v21;
          v19 = (ak_fft_cpx *)((char *)v19 + v18);
          --v20;
        }
        while ( v20 );
        v8 = v60;
        v11 = v62;
        v12 = v57;
        v10 = v61;
        v9 = v58;
        LODWORD(v7) = m;
      }
      v11 += v10;
      ++v8;
      v57 = --v12;
      v62 = v11;
      v60 = v8;
    }
    while ( v12 );
  }
}

// File Line: 1016
// RVA: 0xAF2170
void __fastcall DSP::AkFFTAllButterflies::kf_work(
        ak_fft_cpx *Fout,
        ak_fft_cpx *f,
        unsigned __int64 fstride,
        int in_stride,
        int *factors,
        ak_fft_state *const st)
{
  ak_fft_cpx *v6; // rbx
  ak_fft_cpx *v7; // rsi
  unsigned __int64 v8; // r11
  __int64 v10; // rdx
  int *v11; // rcx
  ak_fft_cpx *v12; // r8
  ak_fft_cpx v13; // rax
  ak_fft_state *v14; // r10
  int v15; // eax
  ak_fft_cpx *v16; // rcx
  ak_fft_cpx *v17; // rdx
  float v18; // xmm1_4
  float v19; // xmm3_4
  ak_fft_cpx v20; // rax
  ak_fft_cpx *v21; // rcx
  float v22; // xmm1_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm3_4
  unsigned __int64 v26; // rcx
  float r; // xmm2_4
  float i; // xmm3_4
  float v29; // xmm3_4
  int v30; // [rsp+30h] [rbp-30h]
  ak_fft_cpx v31; // [rsp+38h] [rbp-28h]
  ak_fft_cpx v32; // [rsp+38h] [rbp-28h]
  ak_fft_cpx v33; // [rsp+38h] [rbp-28h]
  unsigned __int64 v34; // [rsp+38h] [rbp-28h]
  __int64 v35; // [rsp+40h] [rbp-20h]
  ak_fft_cpx *v36; // [rsp+48h] [rbp-18h]
  unsigned __int64 v37; // [rsp+50h] [rbp-10h]
  int v39; // [rsp+80h] [rbp+20h]
  int v41; // [rsp+98h] [rbp+38h]
  int *factorsa; // [rsp+A0h] [rbp+40h]
  int *factorsb; // [rsp+A0h] [rbp+40h]
  int *factorsc; // [rsp+A0h] [rbp+40h]
  int *factorsd; // [rsp+A0h] [rbp+40h]
  int *factorse; // [rsp+A0h] [rbp+40h]

  v41 = in_stride;
  v6 = Fout;
  v7 = Fout;
  v8 = fstride;
  v10 = factors[1];
  v11 = factors + 2;
  v39 = *factors;
  v30 = v10;
  factorsa = factors + 2;
  v12 = &v6[v39 * (int)v10];
  v36 = v12;
  if ( (_DWORD)v10 == 1 )
  {
    do
    {
      v13 = *f;
      ++v6;
      f += (unsigned int)(in_stride * v8);
      v6[-1] = v13;
    }
    while ( v6 != v12 );
    v14 = st;
    goto LABEL_19;
  }
  v14 = st;
  if ( st->nfft == 1024 )
  {
    if ( v11[1] != 1 )
    {
LABEL_14:
      v15 = v39;
LABEL_15:
      v26 = v8 * v15;
      v34 = 8 * v8 * in_stride;
      v37 = v26;
      v35 = 8 * v10;
      do
      {
        DSP::AkFFTAllButterflies::kf_work(v6, f, v26, in_stride, factorsa, v14);
        v6 = (ak_fft_cpx *)((char *)v6 + v35);
        f = (ak_fft_cpx *)((char *)f + v34);
        v14 = st;
        in_stride = v41;
        v26 = v37;
      }
      while ( v6 != v36 );
      v7 = Fout;
      v8 = fstride;
      goto LABEL_18;
    }
    if ( *v11 == 4 && v8 == 64 && in_stride == 1 )
    {
      DSP::AkFFTAllButterflies::kf_bfly4_m1_s256_n1024_SIMD(v6, f, st);
      return;
    }
  }
  if ( v11[1] != 1 )
    goto LABEL_14;
  v15 = v39;
  if ( *v11 != 2 || v39 != 4 )
    goto LABEL_15;
  v16 = &f[v8];
  factorsb = (int *)*f;
  v17 = &v16[v8];
  LODWORD(v18) = HIDWORD(*(unsigned __int64 *)f);
  v31 = f[4 * v8];
  v19 = v31.r + COERCE_FLOAT(*f);
  v6[1].r = COERCE_FLOAT(*f) - v31.r;
  v6[1].i = v18 - v31.i;
  v6->i = v31.i + *((float *)&factorsb + 1);
  v6->r = v19;
  factorsc = (int *)*v16;
  v20 = v16[4 * v8];
  v21 = &v17[v8];
  v6[3].r = *(float *)&factorsc - v20.r;
  v6[3].i = *((float *)&factorsc + 1) - v20.i;
  v6[2].i = v20.i + *((float *)&factorsc + 1);
  v6[2].r = v20.r + *(float *)&factorsc;
  factorsd = (int *)*v17;
  v32 = v17[4 * v8];
  LODWORD(v22) = HIDWORD(*(unsigned __int64 *)v17);
  v23 = v32.r + COERCE_FLOAT(*v17);
  v6[5].r = COERCE_FLOAT(*v17) - v32.r;
  v6[5].i = v22 - v32.i;
  v6[4].i = v32.i + *((float *)&factorsd + 1);
  v6[4].r = v23;
  factorse = (int *)*v21;
  v33 = v21[4 * v8];
  LODWORD(v24) = HIDWORD(*(unsigned __int64 *)v21);
  v25 = v33.r + COERCE_FLOAT(*v21);
  v6[7].r = COERCE_FLOAT(*v21) - v33.r;
  v6[7].i = v24 - v33.i;
  v6[6].r = v25;
  v6[6].i = v33.i + *((float *)&factorse + 1);
LABEL_18:
  LODWORD(v10) = v30;
LABEL_19:
  switch ( v39 )
  {
    case 2:
      if ( (_DWORD)v10 == 1 )
      {
        r = v7[1].r;
        i = v7[1].i;
        v7[1].r = v7->r - r;
        v7[1].i = v7->i - i;
        v29 = i + v7->i;
        v7->r = r + v7->r;
        v7->i = v29;
      }
      else
      {
        DSP::AkFFTAllButterflies::kf_bfly2(v7, v8, v14, v10);
      }
      break;
    case 3:
      DSP::AkFFTAllButterflies::kf_bfly3(v7, v8, v14, (int)v10);
      break;
    case 4:
      if ( (_DWORD)v10 == 1 && v8 == 256 )
      {
        DSP::AkFFTAllButterflies::kf_bfly4_m1_n1024(v7, v14);
      }
      else if ( (int)v10 % 2 )
      {
        DSP::AkFFTAllButterflies::kf_bfly_generic(v7, v8, v14, v10, 4);
      }
      else
      {
        DSP::AkFFTAllButterflies::kf_bfly4(v7, v8, v14, (int)v10);
      }
      break;
    case 5:
      DSP::AkFFTAllButterflies::kf_bfly5(v7, v8, v14, v10);
      break;
    default:
      DSP::AkFFTAllButterflies::kf_bfly_generic(v7, v8, v14, v10, v39);
      break;
  }
}

// File Line: 1107
// RVA: 0xB1A260
void __fastcall DSP::AkFFTSubsetButterflies::ak_fft_stride(
        ak_fft_state *st,
        ak_fft_cpx *fin,
        ak_fft_cpx *fout,
        int in_stride)
{
  DSP::AkFFTSubsetButterflies::kf_work(fout, fin, 1ui64, in_stride, st->factors, st);
}

// File Line: 1115
// RVA: 0xAF0C10
void __fastcall DSP::AkFFTAllButterflies::ak_fft(ak_fft_state *cfg, ak_fft_cpx *fin, ak_fft_cpx *fout)
{
  ak_fft_cpx *twiddles; // r9
  _QWORD v4[15]; // [rsp+30h] [rbp-78h] BYREF

  if ( cfg->nfft == 1024 )
  {
    twiddles = cfg->twiddles;
    cfg->simdTwiddles = (ak_fft_cpx *)v4;
    v4[0] = *twiddles;
    v4[1] = twiddles[64];
    v4[2] = *twiddles;
    v4[3] = twiddles[128];
    v4[4] = *twiddles;
    v4[5] = twiddles[192];
    v4[6] = twiddles[128];
    v4[7] = twiddles[192];
    v4[8] = twiddles[256];
    v4[9] = twiddles[384];
    v4[10] = twiddles[384];
    v4[11] = twiddles[576];
  }
  DSP::AkFFTAllButterflies::kf_work(fout, fin, 1ui64, 1, cfg->factors, cfg);
}

// File Line: 1149
// RVA: 0xAF2590
void __fastcall DSP::AkFFTAllButterflies::kf_factor(int n, int *facbuf)
{
  int v3; // r8d
  __m128d v4; // xmm1
  int v5; // edx

  v3 = 4;
  v4 = _mm_sqrt_pd((__m128d)COERCE_UNSIGNED_INT64((double)n));
  v5 = (int)v4.m128d_f64[0];
  if ( (double)v5 != v4.m128d_f64[0] )
    v4.m128d_f64[0] = (double)(v5 - (_mm_movemask_pd(_mm_unpacklo_pd(v4, v4)) & 1));
  do
  {
    while ( n % v3 )
    {
      if ( v3 == 2 )
      {
        v3 = 3;
      }
      else if ( v3 == 4 )
      {
        v3 = 2;
      }
      else
      {
        v3 += 2;
      }
      if ( (double)v3 > v4.m128d_f64[0] )
        v3 = n;
    }
    *facbuf = v3;
    facbuf += 2;
    *(facbuf - 1) = n / v3;
    n /= v3;
  }
  while ( n > 1 );
}

// File Line: 1181
// RVA: 0xB1A000
ak_fft_state *__fastcall DSP::AkFFTSubsetButterflies::ak_fft_alloc(
        int nfft,
        int inverse_fft,
        char *mem,
        unsigned __int64 *lenmem)
{
  int v4; // edi
  char *v6; // rbx
  unsigned __int64 v7; // r10
  __int64 v8; // rbp
  double v9; // xmm7_8
  double v10; // xmm6_8
  float v11; // xmm1_4
  float v12; // xmm1_4
  __int64 v13; // rbp
  double v14; // xmm7_8
  double v15; // xmm6_8
  float v16; // xmm1_4
  float v17; // xmm1_4

  v4 = 0;
  v6 = 0i64;
  v7 = (8i64 * (nfft - 1) + 111) & 0xFFFFFFFFFFFFFFF0ui64;
  if ( mem && *lenmem >= v7 )
    v6 = mem;
  *lenmem = v7;
  if ( v6 )
  {
    *(_DWORD *)v6 = nfft;
    *((_DWORD *)v6 + 1) = inverse_fft;
    *((_QWORD *)v6 + 9) = mem + 96;
    if ( inverse_fft )
    {
      if ( nfft > 0 )
      {
        v8 = 0i64;
        v9 = 1.0 / (double)nfft;
        do
        {
          v10 = (double)v4 * 6.283185307179586 * v9;
          v11 = cos(v10);
          *(float *)(*((_QWORD *)v6 + 9) + v8) = v11;
          ++v4;
          v8 += 8i64;
          v12 = sin(v10);
          *(float *)(*((_QWORD *)v6 + 9) + v8 - 4) = v12;
        }
        while ( v4 < nfft );
      }
    }
    else if ( nfft > 0 )
    {
      v13 = 0i64;
      v14 = 1.0 / (double)nfft;
      do
      {
        v15 = (double)v4 * -6.283185307179586 * v14;
        v16 = cos(v15);
        *(float *)(*((_QWORD *)v6 + 9) + v13) = v16;
        ++v4;
        v13 += 8i64;
        v17 = sin(v15);
        *(float *)(*((_QWORD *)v6 + 9) + v13 - 4) = v17;
      }
      while ( v4 < nfft );
    }
    DSP::AkFFTSubsetButterflies::kf_factor(nfft, (int *)v6 + 2);
  }
  return (ak_fft_state *)v6;
}

// File Line: 1223
// RVA: 0xB1A290
__int64 __fastcall DSP::AkFFTSubsetButterflies::ak_fft_next_fast_size(unsigned int n)
{
  int i; // r8d
  int j; // edx
  int k; // edx

  while ( 1 )
  {
    for ( i = n; !(i % 2); i /= 2 )
      ;
    for ( j = i / 3; i == 3 * j; j /= 3 )
      i = j;
    for ( k = i / 5; i == 5 * k; k /= 5 )
      i = k;
    if ( i <= 1 )
      break;
    ++n;
  }
  return n;
}


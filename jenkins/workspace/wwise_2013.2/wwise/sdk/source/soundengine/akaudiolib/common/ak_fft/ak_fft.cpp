// File Line: 37
// RVA: 0xAF0DE0
void __fastcall DSP::AkFFTAllButterflies::kf_bfly2(ak_fft_cpx *Fout, const unsigned __int64 fstride, ak_fft_state *const st, int m)
{
  ak_fft_cpx *v4; // r10
  unsigned __int64 v5; // rdx
  ak_fft_cpx *v6; // r8
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm5_4

  v4 = st->twiddles;
  v5 = 8 * fstride;
  v6 = &Fout[m];
  do
  {
    v7 = v4->r;
    v8 = v4->i;
    v9 = v6->i;
    ++Fout;
    v4 = (ak_fft_cpx *)((char *)v4 + v5);
    ++v6;
    v10 = v8 * v9;
    v11 = (float)(v9 * v7) + (float)(v8 * v6[-1].r);
    v12 = (float)(v7 * v6[-1].r) - v10;
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
  ak_fft_cpx *v2; // rax
  float v3; // xmm11_4
  float v4; // xmm12_4
  float v5; // xmm8_4
  float v6; // xmm7_4
  float v7; // xmm6_4
  ak_fft_cpx v8; // [rsp+80h] [rbp+8h]
  ak_fft_cpx v9; // [rsp+90h] [rbp+18h]
  ak_fft_cpx v10; // [rsp+98h] [rbp+20h]

  v2 = st->twiddles;
  v3 = v2[768].i;
  v4 = v2[256].i;
  LODWORD(v5) = *Fout;
  LODWORD(v6) = *(unsigned __int64 *)Fout >> 32;
  v8 = Fout[1];
  v9 = Fout[2];
  LODWORD(v7) = *(_QWORD *)&Fout[2] >> 32;
  v10 = Fout[3];
  Fout->r = (float)((float)(v8.r + v5) + v9.r) + v10.r;
  Fout->i = (float)((float)(v8.i + v6) + v7) + v10.i;
  Fout[1].r = (float)((float)(v5 - (float)(v8.i * v4)) - v9.r) - (float)(v10.i * v3);
  Fout[1].i = (float)((float)((float)(v8.r * v4) + v6) - v7) + (float)(v10.r * v3);
  Fout[2].i = (float)((float)(v6 - v8.i) + v7) - v10.i;
  Fout[3].r = (float)((float)(v5 - (float)(v8.i * v3)) - v9.r) - (float)(v10.i * v4);
  Fout[2].r = (float)((float)(v5 - v8.r) + v9.r) - v10.r;
  Fout[3].i = (float)((float)((float)(v8.r * v3) + v6) - v7) + (float)(v10.r * v4);
}

// File Line: 238
// RVA: 0xAF1010
__m128 __fastcall DSP::AkFFTAllButterflies::AKSIMD_LOADUNALIGNED_DUAL(__m128 *result, float *in_dAddress1, float *in_dAddress2)
{
  return _mm_movelh_ps(*result, *(__m128 *)in_dAddress1);
}

// File Line: 330
// RVA: 0xB1A370
void __fastcall DSP::AkFFTSubsetButterflies::kf_bfly4(ak_fft_cpx *Fout, const unsigned __int64 fstride, ak_fft_state *const st, const unsigned __int64 m)
{
  ak_fft_cpx *v4; // r11
  ak_fft_cpx *v5; // r14
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // r10
  ak_fft_cpx *v8; // rbx
  ak_fft_cpx *v9; // rdi
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rbp
  __m128 v12; // xmm6
  __m128 v13; // xmm7
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // r15
  unsigned __int64 v16; // r12
  unsigned __int64 v17; // r13
  unsigned __int64 v18; // rdx
  signed __int64 v19; // rbp
  __m128 *v20; // r8
  unsigned __int64 v21; // rsi
  unsigned __int64 v22; // r10
  signed __int64 v23; // rax
  signed __int64 v24; // r9
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
  __m128 v48; // xmm5
  __m128 v49; // xmm3
  __m128 v50; // xmm1
  __m128 v51; // xmm2
  __m128 v52; // xmm1
  __m128 v53; // xmm2
  __int64 v54; // r15
  unsigned __int64 v55; // r8
  float *v56; // rax
  unsigned __int64 v57; // rcx
  unsigned __int64 v58; // rdx
  signed __int64 v59; // rbp
  float v60; // xmm1_4
  float v61; // xmm9_4
  float v62; // xmm8_4
  float v63; // xmm4_4
  float v64; // xmm5_4
  float v65; // xmm2_4
  float v66; // xmm7_4
  float v67; // xmm8_4
  float v68; // xmm6_4
  float v69; // xmm9_4
  float v70; // xmm4_4
  float v71; // xmm0_4
  float v72; // xmm5_4
  float v73; // xmm1_4
  float v74; // xmm2_4
  float v75; // xmm3_4
  float v76; // xmm7_4
  float v77; // xmm0_4
  float v78; // xmm1_4
  float v79; // xmm2_4
  float v80; // xmm3_4

  v4 = st->twiddles;
  v5 = Fout;
  v6 = 2 * m;
  v7 = 3 * m;
  v8 = st->twiddles;
  v9 = st->twiddles;
  v10 = 2 * fstride;
  v11 = 3 * fstride;
  if ( m < 2 )
  {
    v54 = st->inverse;
    v55 = 16 * fstride;
    v56 = &Fout->i;
    v57 = 2 * m;
    v58 = 8 * fstride;
    v59 = 8 * v11;
    do
    {
      v60 = *(v56 - 1);
      v61 = (float)(v4->r * v56[v57 - 1]) - (float)(v4->i * v56[v57]);
      v62 = (float)(v4->r * v56[v57]) + (float)(v4->i * v56[v57 - 1]);
      v63 = (float)(v9->r * v56[2 * v7 - 1]) - (float)(v9->i * v56[2 * v7]);
      v64 = (float)(v9->r * v56[2 * v7]) + (float)(v9->i * v56[2 * v7 - 1]);
      v65 = v60;
      v66 = v64 + v62;
      v67 = v62 - v64;
      v68 = v63 + v61;
      v69 = v61 - v63;
      v70 = (float)(v8->r * v56[2 * v6 - 1]) - (float)(v8->i * v56[2 * v6]);
      v71 = *v56;
      v72 = (float)(v8->i * v56[2 * v6 - 1]) + (float)(v8->r * v56[2 * v6]);
      v73 = v60 + v70;
      v74 = v65 - v70;
      *v56 = *v56 + v72;
      *(v56 - 1) = v73;
      v56[2 * v6 - 1] = v73 - v68;
      v75 = v71 - v72;
      v56[2 * v6] = *v56 - v66;
      v76 = v66 + *v56;
      *(v56 - 1) = v68 + *(v56 - 1);
      *v56 = v76;
      if ( v54 )
      {
        v77 = v74 - v67;
        v78 = v75 + v69;
        v79 = v74 + v67;
        v80 = v75 - v69;
      }
      else
      {
        v77 = v74 + v67;
        v78 = v75 - v69;
        v79 = v74 - v67;
        v80 = v75 + v69;
      }
      v56[v57 - 1] = v77;
      v56[v57] = v78;
      v56[2 * v7] = v80;
      v4 = (ak_fft_cpx *)((char *)v4 + v58);
      v8 = (ak_fft_cpx *)((char *)v8 + v55);
      v9 = (ak_fft_cpx *)((char *)v9 + v59);
      v56[2 * v7 - 1] = v79;
      v56 += 2;
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
    v16 = 3 * fstride;
    v17 = 2 * fstride;
    v18 = 16 * fstride;
    v19 = 16 * v11;
    v20 = (__m128 *)&v5[m];
    v21 = m;
    v22 = m;
    v23 = 16 * v10;
    v24 = -(signed __int64)m;
    do
    {
      v25 = *v20;
      v26 = *(__m128 *)&v4->r;
      v27 = *(__m128 *)&v4[v15].r;
      ++v20;
      v4 = (ak_fft_cpx *)((char *)v4 + v18);
      v28 = _mm_movelh_ps(v26, v27);
      v29 = _mm_shuffle_ps(v25, v25, 245);
      v30 = _mm_shuffle_ps(v28, v28, 177);
      v31 = _mm_mul_ps(_mm_shuffle_ps(v25, v25, 160), v28);
      v32 = *(__m128 *)&v9->r;
      v33 = _mm_mul_ps(_mm_mul_ps(v29, _xmm), v30);
      v34 = *(__m128 *)&v9[v16].r;
      v9 = (ak_fft_cpx *)((char *)v9 + v19);
      v35 = _mm_add_ps(v33, v31);
      v36 = v20[v22 - 1];
      v37 = _mm_movelh_ps(v32, v34);
      v38 = _mm_shuffle_ps(v36, v36, 245);
      v39 = _mm_shuffle_ps(v37, v37, 177);
      v40 = _mm_mul_ps(_mm_shuffle_ps(v36, v36, 160), v37);
      v41 = *(__m128 *)&v8->r;
      v42 = _mm_mul_ps(_mm_mul_ps(v38, _xmm), v39);
      v43 = *(__m128 *)&v8[v17].r;
      v8 = (ak_fft_cpx *)((char *)v8 + v23);
      v44 = _mm_add_ps(v42, v40);
      v45 = _mm_movelh_ps(v41, v43);
      v46 = _mm_add_ps(v44, v35);
      v47 = _mm_sub_ps(v35, v44);
      v48 = _mm_shuffle_ps(v47, v47, 177);
      v49 = _mm_add_ps(
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(*(__m128 *)((char *)v20 + 8 * v21 - 16), *(__m128 *)((char *)v20 + 8 * v21 - 16), 245),
                  _xmm),
                _mm_shuffle_ps(v45, v45, 177)),
              _mm_mul_ps(
                _mm_shuffle_ps(*(__m128 *)((char *)v20 + 8 * v21 - 16), *(__m128 *)((char *)v20 + 8 * v21 - 16), 160),
                v45));
      v50 = *(__m128 *)((char *)v20 + 8 * v24 - 16);
      v51 = v50;
      v52 = _mm_add_ps(v50, v49);
      v53 = _mm_sub_ps(v51, v49);
      *(__m128 *)((char *)v20 + 8 * v21 - 16) = _mm_sub_ps(v52, v46);
      *(__m128 *)((char *)v20 + 8 * v24 - 16) = _mm_add_ps(v52, v46);
      v20[-1] = _mm_add_ps(_mm_mul_ps(v48, v12), v53);
      v20[v22 - 1] = _mm_add_ps(_mm_mul_ps(v48, v13), v53);
      --v14;
    }
    while ( v14 );
  }
}

// File Line: 520
// RVA: 0xAF1390
void __fastcall DSP::AkFFTAllButterflies::kf_bfly4_m1_s256_n1024_SIMD(ak_fft_cpx *Fout, ak_fft_cpx *Fin, ak_fft_state *const st)
{
  __m128 v3; // xmm6
  ak_fft_state *v4; // r9
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
  __m128 v21; // xmm11
  __m128 v22; // xmm13
  __m128 v23; // xmm1
  __m128 v24; // xmm15
  __m128 v25; // xmm13
  __m128 v26; // xmm2
  __m128 v27; // xmm12
  __m128 v28; // xmm11
  __m128 v29; // xmm15
  __m128 v30; // xmm4
  __m128 v31; // xmm3
  __m128 v32; // xmm12
  __m128 v33; // xmm11
  __m128 v34; // xmm5
  __m128 v35; // xmm12
  __m128 v36; // xmm11
  __m128 v37; // xmm0
  __m128 v38; // xmm1
  __m128 v39; // xmm4
  __m128 v40; // xmm2
  __m128 v41; // xmm8
  __m128 v42; // xmm3
  __m128 *v43; // rax
  __m128 v44; // xmm9
  __m128 v45; // xmm1
  __m128 v46; // xmm5
  __m128 v47; // xmm10
  __m128 v48; // xmm7
  __m128 v49; // xmm10
  __m128 v50; // xmm2
  __m128 v51; // xmm15
  __m128 v52; // xmm7
  __m128 v53; // xmm9
  __m128 v54; // xmm5
  __m128 v55; // xmm6
  __m128 v56; // xmm2
  __m128 v57; // xmm7
  __m128 v58; // xmm3
  __m128 v59; // xmm4
  __m128 v60; // xmm6
  __m128 v61; // xmm6
  __m128 v62; // xmm2
  __m128 v63; // xmm1
  __m128 v64; // xmm15
  __m128 v65; // xmm1
  __m128 v66; // xmm2
  __m128 v67; // xmm0
  __m128 v68; // xmm13
  __m128 v69; // xmm5
  __m128 v70; // xmm2
  __m128 v71; // xmm1
  __m128 v72; // xmm5
  __m128 v73; // xmm0
  __m128 v74; // xmm5
  __m128 v75; // xmm2
  __m128 v76; // xmm10
  __m128 v77; // xmm3
  __m128 v78; // xmm2
  __m128 v79; // xmm1
  __m128 v80; // xmm3
  __m128 v81; // xmm0
  __m128 v82; // xmm3
  __m128 v83; // xmm2
  __m128 v84; // xmm4
  __m128 v85; // xmm5
  __m128 v86; // xmm10
  __m128 v87; // xmm1
  __m128 v88; // xmm5
  __m128 v89; // xmm2
  __m128 v90; // xmm13
  __m128 v91; // xmm1

  v3 = _xmm;
  v4 = st;
  if ( st->inverse )
    v3 = _mm_xor_ps(_xmm, *(__m128 *)_xmm);
  v5 = 0;
  v6 = _mm_xor_ps(*(__m128 *)_xmm, v3);
  if ( (unsigned __int8)Fin & 0xF )
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
  v24 = _mm_add_ps(v22, v16);
  v25 = _mm_sub_ps(_mm_sub_ps(v22, v16), v18);
  v26 = *(__m128 *)&Fin[448].r;
  v27 = _mm_add_ps(_mm_mul_ps(v21, v6), v15);
  v28 = _mm_add_ps(_mm_mul_ps(v21, v3), v15);
  v29 = _mm_add_ps(v24, v18);
  v30 = *(__m128 *)&Fin[192].r;
  v31 = *(__m128 *)&Fin[960].r;
  v32 = _mm_sub_ps(v27, v17);
  v33 = _mm_sub_ps(v28, v17);
  v34 = *(__m128 *)&Fin[640].r;
  v35 = _mm_add_ps(v32, _mm_mul_ps(v23, v3));
  v36 = _mm_add_ps(v33, _mm_mul_ps(v23, v6));
  v37 = *(__m128 *)&Fin[128].r;
  v38 = *(__m128 *)&Fin[384].r;
  if ( v5 )
  {
    v39 = _mm_movehl_ps(v30, v37);
    v40 = _mm_movehl_ps(v26, v38);
    v41 = _mm_movehl_ps(v20, v34);
    v42 = _mm_movehl_ps(v31, v19);
  }
  else
  {
    v39 = _mm_movelh_ps(v37, v30);
    v40 = _mm_movelh_ps(v38, v26);
    v41 = _mm_movelh_ps(v34, v20);
    v42 = _mm_movelh_ps(v19, v31);
  }
  v43 = (__m128 *)v4->simdTwiddles;
  v44 = _mm_shuffle_ps(v40, v40, 177);
  v45 = _mm_shuffle_ps(v42, v42, 177);
  v46 = v44;
  v47 = _mm_add_ps(v41, v39);
  v48 = _mm_add_ps(v47, v40);
  v49 = _mm_sub_ps(_mm_sub_ps(v47, v40), v42);
  v50 = _mm_movehl_ps(v35, v29);
  v51 = _mm_movelh_ps(v29, v35);
  v52 = _mm_add_ps(v48, v42);
  v53 = _mm_add_ps(_mm_sub_ps(_mm_add_ps(_mm_mul_ps(v44, v3), v39), v41), _mm_mul_ps(v45, v6));
  v54 = _mm_add_ps(_mm_sub_ps(_mm_add_ps(_mm_mul_ps(v46, v6), v39), v41), _mm_mul_ps(v45, v3));
  v55 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v50, v50, 245), _xmm), _mm_shuffle_ps(*v43, *v43, 177)),
          _mm_mul_ps(_mm_shuffle_ps(v50, v50, 160), *v43));
  v56 = _mm_movehl_ps(v54, v52);
  v57 = _mm_movelh_ps(v52, v54);
  v58 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v56, v56, 245), _xmm), _mm_shuffle_ps(v43[2], v43[2], 177)),
          _mm_mul_ps(_mm_shuffle_ps(v56, v56, 160), v43[2]));
  v59 = _mm_add_ps(v58, v55);
  v60 = _mm_sub_ps(v55, v58);
  v61 = _mm_mul_ps(_mm_shuffle_ps(v60, v60, 177), v6);
  v62 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v57, v57, 245), _xmm), _mm_shuffle_ps(v43[1], v43[1], 177)),
          _mm_mul_ps(_mm_shuffle_ps(v57, v57, 160), v43[1]));
  v63 = _mm_sub_ps(v51, v62);
  v64 = _mm_add_ps(v51, v62);
  *(__m128 *)&Fout[8].r = _mm_sub_ps(v64, v59);
  *(__m128 *)&Fout->r = _mm_add_ps(v64, v59);
  *(__m128 *)&Fout[4].r = _mm_add_ps(v63, v61);
  *(__m128 *)&Fout[12].r = _mm_sub_ps(v63, v61);
  v65 = v43[3];
  v66 = _mm_movehl_ps(v36, v25);
  v67 = _mm_shuffle_ps(v65, v65, 177);
  v68 = _mm_movelh_ps(v25, v36);
  v69 = _mm_shuffle_ps(v66, v66, 245);
  v70 = _mm_mul_ps(_mm_shuffle_ps(v66, v66, 160), v65);
  v71 = v43[5];
  v72 = _mm_mul_ps(_mm_mul_ps(v69, _xmm), v67);
  v73 = _mm_shuffle_ps(v71, v71, 177);
  v74 = _mm_add_ps(v72, v70);
  v75 = _mm_movehl_ps(v53, v49);
  v76 = _mm_movelh_ps(v49, v53);
  v77 = _mm_shuffle_ps(v75, v75, 245);
  v78 = _mm_mul_ps(_mm_shuffle_ps(v75, v75, 160), v71);
  v79 = v43[4];
  v80 = _mm_mul_ps(_mm_mul_ps(v77, _xmm), v73);
  v81 = _mm_shuffle_ps(v79, v79, 177);
  v82 = _mm_add_ps(v80, v78);
  v83 = _mm_shuffle_ps(v76, v76, 245);
  v84 = _mm_add_ps(v82, v74);
  v85 = _mm_sub_ps(v74, v82);
  v86 = _mm_mul_ps(_mm_shuffle_ps(v76, v76, 160), v79);
  v87 = v68;
  v88 = _mm_mul_ps(_mm_shuffle_ps(v85, v85, 177), v6);
  v89 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v83, _xmm), v81), v86);
  v90 = _mm_add_ps(v68, v89);
  v91 = _mm_sub_ps(v87, v89);
  *(__m128 *)&Fout[10].r = _mm_sub_ps(v90, v84);
  *(__m128 *)&Fout[2].r = _mm_add_ps(v90, v84);
  *(__m128 *)&Fout[6].r = _mm_add_ps(v91, v88);
  *(__m128 *)&Fout[14].r = _mm_sub_ps(v91, v88);
}

// File Line: 771
// RVA: 0xAF1760
void __fastcall DSP::AkFFTAllButterflies::kf_bfly3(ak_fft_cpx *Fout, const unsigned __int64 fstride, ak_fft_state *const st, unsigned __int64 m)
{
  ak_fft_cpx *v4; // r10
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rdx
  unsigned __int64 v8; // r11
  float *v9; // r8
  float *v10; // rcx
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

  v4 = st->twiddles;
  v5 = fstride;
  v6 = 8 * fstride;
  v7 = 16 * fstride;
  v8 = 2 * m;
  v9 = (float *)v4;
  v10 = &Fout->i;
  v33 = v4[m * v5];
  v11 = 2 * m;
  do
  {
    v12 = v10[2 * v8 - 1];
    v13 = v10[v11 - 1];
    v14 = v10[v11];
    v10 += 2;
    v15 = v14;
    v16 = v14 * *v9;
    v17 = v13;
    v18 = v15 * v9[1];
    v19 = v13 * v9[1];
    v20 = v17 * *v9;
    v9 = (float *)((char *)v9 + v6);
    v21 = v20 - v18;
    v22 = v19 + v16;
    v23 = v10[2 * v8 - 2] * v4->r;
    v24 = (float)(v12 * v4->r) - (float)(v10[2 * v8 - 2] * v4->i);
    v25 = v12 * v4->i;
    v4 = (ak_fft_cpx *)((char *)v4 + v7);
    v26 = v25 + v23;
    v27 = v24 + v21;
    v28 = (float)(v21 - v24) * v33.i;
    v29 = v26 + v22;
    v30 = (float)(v22 - v26) * v33.i;
    v10[v11 - 3] = *(v10 - 3) - (float)(v27 * 0.5);
    v10[v11 - 2] = *(v10 - 2) - (float)(v29 * 0.5);
    v31 = v29 + *(v10 - 2);
    *(v10 - 3) = v27 + *(v10 - 3);
    *(v10 - 2) = v31;
    v10[2 * v8 - 3] = v30 + v10[v11 - 3];
    v10[2 * v8 - 2] = v10[v11 - 2] - v28;
    v32 = v10[v11 - 3] - v30;
    v10[v11 - 2] = v28 + v10[v11 - 2];
    v10[v11 - 3] = v32;
    --m;
  }
  while ( m );
}

// File Line: 815
// RVA: 0xAF1920
void __fastcall DSP::AkFFTAllButterflies::kf_bfly5(ak_fft_cpx *Fout, const unsigned __int64 fstride, ak_fft_state *const st, int m)
{
  ak_fft_cpx *v4; // r11
  unsigned __int64 v5; // r8
  __int64 v6; // r8
  ak_fft_cpx *v7; // r12
  float *v8; // rcx
  unsigned __int64 v9; // rax
  signed __int64 v10; // rdi
  signed __int64 v11; // rsi
  signed __int64 v12; // r11
  float *v13; // rbx
  unsigned __int64 v14; // r14
  unsigned __int64 v15; // r15
  unsigned __int64 v16; // rdx
  signed __int64 v17; // rbp
  __int64 v18; // r13
  __int64 v19; // r8
  float *v20; // r10
  float *v21; // r9
  float v22; // xmm3_4
  float v23; // xmm14_4
  __int64 v24; // ST20_8
  float v25; // xmm4_4
  float v26; // xmm15_4
  float v27; // xmm14_4
  float v28; // xmm12_4
  float v29; // xmm13_4
  float v30; // xmm7_4
  float v31; // xmm6_4
  float v32; // xmm9_4
  float v33; // xmm13_4
  float v34; // xmm8_4
  float v35; // xmm12_4
  float v36; // xmm4_4
  float v37; // xmm5_4
  float v38; // xmm10_4
  float v39; // xmm15_4
  float v40; // xmm11_4
  float v41; // xmm4_4
  float v42; // xmm14_4
  float v43; // xmm1_4
  float v44; // xmm5_4
  float v45; // xmm4_4
  float v46; // xmm3_4
  float v47; // xmm2_4
  float v48; // xmm13_4
  float v49; // xmm15_4
  float v50; // xmm10_4
  float v51; // xmm11_4
  ak_fft_cpx v52; // [rsp+170h] [rbp+8h]
  ak_fft_cpx v53; // [rsp+178h] [rbp+10h]
  float *v54; // [rsp+180h] [rbp+18h]

  v4 = st->twiddles;
  v5 = fstride * m;
  v53 = v4[v5];
  v52 = v4[2 * v5];
  v6 = 3 * m;
  v7 = &Fout[v6];
  if ( m > 0 )
  {
    v8 = &v4->i;
    v9 = 8 * fstride;
    v10 = 4 * m - (signed __int64)m;
    v11 = 2 * m - (signed __int64)m;
    v12 = -4 - 8i64 * m;
    v13 = &v7[m - v6].i;
    v14 = 32 * fstride;
    v15 = 24 * fstride;
    v16 = 16 * fstride;
    v17 = -(signed __int64)m;
    v18 = (unsigned int)m;
    v19 = v6 - m;
    v20 = v8;
    v54 = v8;
    v21 = v8;
    do
    {
      v22 = *(v13 - 1);
      v23 = *(v8 - 1);
      v24 = *(_QWORD *)((char *)v13 + v12);
      v25 = *(v21 - 1);
      v26 = (float)(v22 * v23) - (float)(*v8 * *v13);
      v27 = (float)(v23 * *v13) + (float)(v22 * *v8);
      v28 = (float)(*(v20 - 1) * v13[2 * v11 - 1]) - (float)(v13[2 * v11] * *v20);
      v29 = (float)(v13[2 * v11] * *(v20 - 1)) + (float)(*v20 * v13[2 * v11 - 1]);
      v30 = (float)(v7->r * *v21) + (float)(v25 * v13[2 * v19]);
      v31 = (float)(v7->r * v25) - (float)(*v21 * v13[2 * v19]);
      v32 = v30 + v29;
      v33 = v29 - v30;
      v34 = v31 + v28;
      v35 = v28 - v31;
      v36 = (float)(v13[2 * v10 - 1] * *(v54 - 1)) - (float)(v13[2 * v10] * *v54);
      v37 = (float)(v13[2 * v10 - 1] * *v54) + (float)(v13[2 * v10] * *(v54 - 1));
      v38 = v36 + v26;
      v39 = v26 - v36;
      v40 = v37 + v27;
      v41 = (float)((float)(v37 + v27) * v53.r) + *((float *)&v24 + 1);
      v42 = v27 - v37;
      v43 = (float)(v32 + v40) + v13[2 * v17];
      *(float *)((char *)v13 + v12) = (float)(v34 + v38) + *(float *)((char *)v13 + v12);
      v44 = (float)((float)(v38 * v53.r) + *(float *)&v24) + (float)(v34 * v52.r);
      v13[2 * v17] = v43;
      v45 = v41 + (float)(v32 * v52.r);
      v8 = (float *)((char *)v8 + v9);
      ++v7;
      v13 += 2;
      v20 = (float *)((char *)v20 + v16);
      v21 = (float *)((char *)v21 + v15);
      v54 = (float *)((char *)v54 + v14);
      v46 = (float)(v33 * v52.i) + (float)(v42 * v53.i);
      v47 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v39 * v53.i) ^ _xmm[0]) - (float)(v35 * v52.i);
      v48 = (float)(v33 * v53.i) - (float)(v42 * v52.i);
      *(v13 - 2) = v45 - v47;
      *(v13 - 3) = v44 - v46;
      v13[2 * v10 - 3] = v46 + v44;
      v49 = (float)(v39 * v52.i) - (float)(v35 * v53.i);
      v50 = (float)((float)(v38 * v52.r) + *(float *)&v24) + (float)(v34 * v53.r);
      v51 = (float)((float)(v40 * v52.r) + *((float *)&v24 + 1)) + (float)(v32 * v53.r);
      v13[2 * v10 - 2] = v47 + v45;
      v13[2 * v11 - 3] = v48 + v50;
      v13[2 * v11 - 2] = v49 + v51;
      v7[-1].r = v50 - v48;
      v13[2 * v19 - 2] = v51 - v49;
      --v18;
    }
    while ( v18 );
  }
}] = v49 + 

// File Line: 878
// RVA: 0xAF1DB0
void __fastcall DSP::AkFFTAllButterflies::kf_bfly_generic(ak_fft_cpx *Fout, const unsigned __int64 fstride, ak_fft_state *const st, int m, int p)
{
  ak_fft_cpx *v5; // rbx
  int v6; // er10
  __int64 v7; // rdi
  ak_fft_cpx *v8; // rax
  __int64 v9; // r11
  int v10; // er9
  int v11; // edx
  __int64 v12; // r8
  signed __int64 v13; // rcx
  __int64 *v14; // rdx
  __int64 v15; // rax
  __int64 v16; // r13
  int v17; // er8
  signed __int64 v18; // r15
  ak_fft_cpx *v19; // rdx
  __int64 v20; // rbp
  int v21; // er14
  int v22; // edi
  int v23; // ecx
  signed __int64 v24; // r9
  float v25; // xmm6_4
  float v26; // xmm7_4
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
  float v41; // xmm4_4
  float v42; // xmm6_4
  float v43; // xmm7_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  __int64 v46; // rax
  float v47; // xmm4_4
  float v48; // xmm6_4
  float v49; // xmm7_4
  float v50; // xmm1_4
  float v51; // xmm2_4
  float v52; // xmm4_4
  float v53; // xmm6_4
  float v54; // xmm7_4
  float *v55; // r11
  __int64 v56; // r9
  __int64 v57; // [rsp+0h] [rbp-178h]
  __int64 v58; // [rsp+8h] [rbp-170h]
  __int64 v59; // [rsp+10h] [rbp-168h]
  int v60; // [rsp+18h] [rbp-160h]
  int v61; // [rsp+1Ch] [rbp-15Ch]
  int v62; // [rsp+20h] [rbp-158h]
  int v63; // [rsp+24h] [rbp-154h]
  int v64; // [rsp+28h] [rbp-150h]
  int v65[57]; // [rsp+2Ch] [rbp-14Ch]
  ak_fft_cpx *v66; // [rsp+180h] [rbp+8h]
  unsigned __int64 v67; // [rsp+188h] [rbp+10h]
  int v68; // [rsp+190h] [rbp+18h]
  int v69; // [rsp+198h] [rbp+20h]

  v69 = m;
  v67 = fstride;
  v66 = Fout;
  v5 = st->twiddles;
  v6 = st->nfft;
  v7 = (unsigned int)m;
  v8 = Fout;
  v9 = m;
  v10 = fstride;
  v58 = v9;
  if ( (signed int)v7 > 0 )
  {
    v11 = 0;
    v12 = (unsigned int)v7;
    v57 = v7;
    v68 = 0;
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
          *(&v58 + v13) = v15;
        }
        while ( v13 < p );
        v16 = v59;
        v8 = v66;
        v11 = v68;
        v12 = v57;
        if ( p > 0 )
        {
          v17 = v68;
          v18 = 8 * v9;
          v19 = v66;
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
                v25 = v19->r;
                v26 = v19->i;
                v27 = ((unsigned int)(p - 5) >> 2) + 1;
                v28 = v27;
                v22 = 4 * v27 + 1;
                do
                {
                  v29 = v17 + v23;
                  if ( v29 >= v6 )
                    v29 -= v6;
                  v30 = *((float *)&v59 + 2 * v24 + 1);
                  v31 = *((float *)&v59 + 2 * v24);
                  v32 = v29;
                  v33 = v17 + v29;
                  v34 = v5[v32].r;
                  v35 = v26 + (float)((float)(v5[v32].i * v31) + (float)(v30 * v34));
                  v36 = v25 + (float)((float)(v34 * v31) - (float)(v5[v32].i * v30));
                  v19->i = v35;
                  v19->r = v36;
                  if ( v33 >= v6 )
                    v33 -= v6;
                  v37 = *((float *)&v60 + 2 * v24);
                  v38 = *((float *)&v61 + 2 * v24);
                  v39 = v33;
                  v40 = v17 + v33;
                  v41 = v5[v39].r;
                  v42 = v36 + (float)((float)(v41 * v37) - (float)(v5[v39].i * v38));
                  v43 = v35 + (float)((float)(v5[v39].i * v37) + (float)(v41 * v38));
                  v19->r = v42;
                  v19->i = v43;
                  if ( v40 >= v6 )
                    v40 -= v6;
                  v44 = *((float *)&v62 + 2 * v24);
                  v45 = *((float *)&v63 + 2 * v24);
                  v46 = v40;
                  v23 = v17 + v40;
                  v47 = v5[v46].r;
                  v48 = v42 + (float)((float)(v47 * v44) - (float)(v5[v46].i * v45));
                  v49 = v43 + (float)((float)(v5[v46].i * v44) + (float)(v47 * v45));
                  v19->r = v48;
                  v19->i = v49;
                  if ( v23 >= v6 )
                    v23 -= v6;
                  v50 = *((float *)&v64 + 2 * v24);
                  v51 = *(float *)&v65[2 * v24];
                  v24 += 4i64;
                  v52 = v5[v23].r;
                  v25 = v48 + (float)((float)(v52 * v50) - (float)(v5[v23].i * v51));
                  v26 = v49 + (float)((float)(v5[v23].i * v50) + (float)(v52 * v51));
                  v19->r = v25;
                  v19->i = v26;
                  --v28;
                }
                while ( v28 );
              }
              if ( v22 < p )
              {
                v53 = v19->r;
                v54 = v19->i;
                v55 = (float *)((char *)&v59 + 8 * v24 + 4);
                v56 = (unsigned int)(p - v22);
                do
                {
                  v23 += v17;
                  if ( v23 >= v6 )
                    v23 -= v6;
                  v55 += 2;
                  v53 = v53 + (float)((float)(v5[v23].r * *(v55 - 3)) - (float)(v5[v23].i * *(v55 - 2)));
                  v54 = v54 + (float)((float)(v5[v23].i * *(v55 - 3)) + (float)(v5[v23].r * *(v55 - 2)));
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
          v8 = v66;
          v11 = v68;
          v12 = v57;
          v10 = v67;
          v9 = v58;
          LODWORD(v7) = v69;
        }
      }
      v11 += v10;
      ++v8;
      v57 = --v12;
      v68 = v11;
      v66 = v8;
    }
    while ( v12 );
  }
}

// File Line: 1016
// RVA: 0xAF2170
void __fastcall DSP::AkFFTAllButterflies::kf_work(ak_fft_cpx *Fout, ak_fft_cpx *f, const unsigned __int64 fstride, int in_stride, int *factors, ak_fft_state *const st)
{
  ak_fft_cpx *v6; // rbx
  ak_fft_cpx *v7; // rsi
  unsigned __int64 v8; // r11
  ak_fft_cpx *v9; // rdi
  __int64 v10; // rdx
  int v11; // er8
  int *v12; // rcx
  __int64 v13; // rax
  signed __int64 v14; // r8
  ak_fft_cpx v15; // rax
  ak_fft_state *v16; // r10
  int v17; // eax
  int **v18; // rcx
  int **v19; // rdx
  float v20; // xmm1_4
  ak_fft_cpx v21; // ST38_8
  float v22; // xmm3_4
  int *v23; // rax
  int **v24; // rcx
  int *v25; // ST38_8
  float v26; // xmm1_4
  float v27; // xmm3_4
  float v28; // xmm2_4
  int *v29; // ST38_8
  float v30; // xmm1_4
  float v31; // xmm3_4
  unsigned __int64 v32; // rcx
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm3_4
  int v36; // [rsp+30h] [rbp-30h]
  unsigned __int64 v37; // [rsp+38h] [rbp-28h]
  signed __int64 v38; // [rsp+40h] [rbp-20h]
  signed __int64 v39; // [rsp+48h] [rbp-18h]
  unsigned __int64 v40; // [rsp+50h] [rbp-10h]
  ak_fft_cpx *v41; // [rsp+58h] [rbp-8h]
  int v42; // [rsp+80h] [rbp+20h]
  unsigned __int64 v43; // [rsp+90h] [rbp+30h]
  int v44; // [rsp+98h] [rbp+38h]
  int *factorsa; // [rsp+A0h] [rbp+40h]
  int *factorsb; // [rsp+A0h] [rbp+40h]
  int *factorsc; // [rsp+A0h] [rbp+40h]
  int *factorsd; // [rsp+A0h] [rbp+40h]

  v44 = in_stride;
  v43 = fstride;
  v6 = Fout;
  v7 = Fout;
  v41 = Fout;
  v8 = fstride;
  v9 = f;
  v10 = factors[1];
  v11 = *factors;
  v12 = factors + 2;
  v42 = v11;
  v36 = v10;
  factorsa = factors + 2;
  v13 = v11 * (signed int)v10;
  v14 = (signed __int64)&v6[v13];
  v39 = (signed __int64)&v6[v13];
  if ( (_DWORD)v10 == 1 )
  {
    do
    {
      v15 = *v9;
      ++v6;
      v9 += (unsigned int)(in_stride * v8);
      v6[-1] = v15;
    }
    while ( v6 != (ak_fft_cpx *)v14 );
    v16 = st;
    goto LABEL_19;
  }
  v16 = st;
  if ( st->nfft == 1024 )
  {
    if ( v12[1] != 1 )
    {
LABEL_14:
      v17 = v42;
LABEL_15:
      v32 = v8 * v17;
      v37 = 8 * v8 * in_stride;
      v40 = v8 * v17;
      v38 = 8 * v10;
      do
      {
        DSP::AkFFTAllButterflies::kf_work(v6, v9, v32, in_stride, factorsa, v16);
        v6 = (ak_fft_cpx *)((char *)v6 + v38);
        v9 = (ak_fft_cpx *)((char *)v9 + v37);
        v16 = st;
        in_stride = v44;
        v32 = v40;
      }
      while ( v6 != (ak_fft_cpx *)v39 );
      v7 = v41;
      v8 = v43;
      goto LABEL_18;
    }
    if ( *v12 == 4 && v8 == 64 && in_stride == 1 )
    {
      DSP::AkFFTAllButterflies::kf_bfly4_m1_s256_n1024_SIMD(v6, v9, st);
      return;
    }
  }
  if ( v12[1] != 1 )
    goto LABEL_14;
  v17 = v42;
  if ( *v12 != 2 || v42 != 4 )
    goto LABEL_15;
  v18 = (int **)&v9[v8];
  factorsb = (int *)*v9;
  v19 = &v18[v8];
  LODWORD(v20) = *(unsigned __int64 *)v9 >> 32;
  v21 = v9[4 * v8];
  v22 = v21.r + COERCE_FLOAT(*v9);
  v6[1].r = COERCE_FLOAT(*v9) - v21.r;
  v6[1].i = v20 - v21.i;
  v6->i = v21.i + *((float *)&factorsb + 1);
  v6->r = v22;
  factorsc = *v18;
  v23 = v18[4 * v8];
  v24 = &v19[v8];
  v6[3].r = *(float *)&factorsc - *(float *)&v23;
  v6[3].i = *((float *)&factorsc + 1) - *((float *)&v23 + 1);
  v6[2].i = *((float *)&v23 + 1) + *((float *)&factorsc + 1);
  v6[2].r = *(float *)&v23 + *(float *)&factorsc;
  factorsd = *v19;
  v25 = v19[4 * v8];
  LODWORD(v26) = (unsigned __int64)*v19 >> 32;
  v27 = *(float *)&v25 + COERCE_FLOAT(*v19);
  v6[5].r = COERCE_FLOAT(*v19) - *(float *)&v25;
  v6[5].i = v26 - *((float *)&v25 + 1);
  v6[4].i = *((float *)&v25 + 1) + *((float *)&factorsd + 1);
  v6[4].r = v27;
  LODWORD(v28) = (unsigned __int64)*v24 >> 32;
  v29 = v24[4 * v8];
  LODWORD(v30) = (unsigned __int64)*v24 >> 32;
  v31 = *(float *)&v29 + COERCE_FLOAT(*v24);
  v6[7].r = COERCE_FLOAT(*v24) - *(float *)&v29;
  v6[7].i = v30 - *((float *)&v29 + 1);
  v6[6].r = v31;
  v6[6].i = *((float *)&v29 + 1) + v28;
LABEL_18:
  LODWORD(v10) = v36;
LABEL_19:
  switch ( v42 )
  {
    case 2:
      if ( (_DWORD)v10 == 1 )
      {
        v33 = v7[1].r;
        v34 = v7[1].i;
        v7[1].r = v7->r - v33;
        v7[1].i = v7->i - v34;
        v35 = v34 + v7->i;
        v7->r = v33 + v7->r;
        v7->i = v35;
      }
      else
      {
        DSP::AkFFTAllButterflies::kf_bfly2(v7, v8, v16, v10);
      }
      break;
    case 3:
      DSP::AkFFTAllButterflies::kf_bfly3(v7, v8, v16, (signed int)v10);
      break;
    case 4:
      if ( (_DWORD)v10 != 1 || v8 != 256 )
      {
        if ( (signed int)v10 % 2 )
          DSP::AkFFTAllButterflies::kf_bfly_generic(v7, v8, v16, v10, 4);
        else
          DSP::AkFFTAllButterflies::kf_bfly4(v7, v8, v16, (signed int)v10);
      }
      else
      {
        DSP::AkFFTAllButterflies::kf_bfly4_m1_n1024(v7, v16);
      }
      break;
    case 5:
      DSP::AkFFTAllButterflies::kf_bfly5(v7, v8, v16, v10);
      break;
    default:
      DSP::AkFFTAllButterflies::kf_bfly_generic(v7, v8, v16, v10, v42);
      break;
  }
}

// File Line: 1107
// RVA: 0xB1A260
void __fastcall DSP::AkFFTSubsetButterflies::ak_fft_stride(ak_fft_state *st, ak_fft_cpx *fin, ak_fft_cpx *fout, int in_stride)
{
  DSP::AkFFTSubsetButterflies::kf_work(fout, fin, 1ui64, in_stride, st->factors, st);
}

// File Line: 1115
// RVA: 0xAF0C10
void __fastcall DSP::AkFFTAllButterflies::ak_fft(ak_fft_state *cfg, ak_fft_cpx *fin, ak_fft_cpx *fout)
{
  ak_fft_cpx *v3; // r9
  __int64 v4; // [rsp+30h] [rbp-78h]
  ak_fft_cpx v5; // [rsp+38h] [rbp-70h]
  ak_fft_cpx v6; // [rsp+40h] [rbp-68h]
  ak_fft_cpx v7; // [rsp+48h] [rbp-60h]
  ak_fft_cpx v8; // [rsp+50h] [rbp-58h]
  ak_fft_cpx v9; // [rsp+58h] [rbp-50h]
  ak_fft_cpx v10; // [rsp+60h] [rbp-48h]
  ak_fft_cpx v11; // [rsp+68h] [rbp-40h]
  ak_fft_cpx v12; // [rsp+70h] [rbp-38h]
  ak_fft_cpx v13; // [rsp+78h] [rbp-30h]
  ak_fft_cpx v14; // [rsp+80h] [rbp-28h]
  ak_fft_cpx v15; // [rsp+88h] [rbp-20h]

  if ( cfg->nfft == 1024 )
  {
    v3 = cfg->twiddles;
    cfg->simdTwiddles = (ak_fft_cpx *)&v4;
    v4 = (__int64)*v3;
    v5 = v3[64];
    v6 = *v3;
    v7 = v3[128];
    v8 = *v3;
    v9 = v3[192];
    v10 = v3[128];
    v11 = v3[192];
    v12 = v3[256];
    v13 = v3[384];
    v14 = v3[384];
    v15 = v3[576];
  }
  DSP::AkFFTAllButterflies::kf_work(fout, fin, 1ui64, 1, cfg->factors, cfg);
}

// File Line: 1149
// RVA: 0xAF2590
void __fastcall DSP::AkFFTAllButterflies::kf_factor(int n, int *facbuf)
{
  int *v2; // r9
  int v3; // er8
  __m128d v4; // xmm1
  __int64 v5; // rdx

  v2 = facbuf;
  v3 = 4;
  v4 = _mm_sqrt_pd((__m128d)COERCE_UNSIGNED_INT64((double)n));
  v5 = (unsigned int)(signed int)v4.m128d_f64[0];
  if ( v5 != 0x8000000000000000i64 && (double)(signed int)v5 != v4.m128d_f64[0] )
    v4.m128d_f64[0] = (double)(signed int)(v5 - (_mm_movemask_pd(_mm_unpckl_pd(v4, v4)) & 1));
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
    *v2 = v3;
    v2 += 2;
    *(v2 - 1) = n / v3;
    n /= v3;
  }
  while ( n > 1 );
}

// File Line: 1181
// RVA: 0xB1A000
ak_fft_state *__fastcall DSP::AkFFTSubsetButterflies::ak_fft_alloc(int nfft, int inverse_fft, void *mem, unsigned __int64 *lenmem)
{
  signed int v4; // edi
  int v5; // esi
  _DWORD *v6; // rbx
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
  v5 = nfft;
  v6 = 0i64;
  v7 = (8i64 * (nfft - 1) + 111) & 0xFFFFFFFFFFFFFFF0ui64;
  if ( mem && *lenmem >= v7 )
    v6 = mem;
  *lenmem = v7;
  if ( v6 )
  {
    *v6 = nfft;
    v6[1] = inverse_fft;
    *((_QWORD *)v6 + 9) = (char *)mem + 96;
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
        while ( v4 < v5 );
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
      while ( v4 < v5 );
    }
    DSP::AkFFTSubsetButterflies::kf_factor(v5, v6 + 2);
  }
  return (ak_fft_state *)v6;
}

// File Line: 1223
// RVA: 0xB1A290
__int64 __fastcall DSP::AkFFTSubsetButterflies::ak_fft_next_fast_size(int n)
{
  unsigned int i; // er9
  signed int j; // er8
  int k; // edx
  int l; // edx

  for ( i = n; ; ++i )
  {
    for ( j = i; !(j % 2); j /= 2 )
      ;
    for ( k = j / 3; j == 3 * k; k /= 3 )
      j = k;
    for ( l = j / 5; j == 5 * l; l /= 5 )
      j = l;
    if ( j <= 1 )
      break;
  }
  return i;
}


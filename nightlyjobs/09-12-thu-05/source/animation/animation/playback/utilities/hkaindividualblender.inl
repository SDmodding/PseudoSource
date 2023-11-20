// File Line: 11
// RVA: 0xB3F5B0
void __fastcall hkaBlender::blend(float *dst, const float *srcL, const float *srcR, hkSimdFloat32 *alpha, int n, hkaBlender::BLEND_MODE blendMode)
{
  float *v6; // r10
  __m128 v7; // xmm3
  float v8; // xmm4_4
  int v9; // er9
  float v10; // xmm1_4
  float v11; // xmm2_4
  signed __int64 v12; // rdx
  const float *v13; // rcx
  signed __int64 v14; // r8
  __int64 v15; // rax
  float v16; // xmm0_4
  float v17; // xmm0_4
  int v18; // er9
  float v19; // xmm2_4
  float v20; // xmm0_4
  signed __int64 v21; // rdx
  const float *v22; // rcx
  signed __int64 v23; // r8
  __int64 v24; // rax
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  int v28; // er9
  float v29; // xmm2_4
  float v30; // xmm4_4
  signed __int64 v31; // rdx
  const float *v32; // rcx
  signed __int64 v33; // r8
  __int64 v34; // rax
  float v35; // xmm0_4
  float v36; // xmm1_4
  __m128 v37; // xmm2

  v6 = dst;
  if ( n > 0 )
  {
    v7 = alpha->m_real;
    v8 = 1.0 - v7.m128_f32[0];
    if ( blendMode == -1 )
    {
      v28 = n - 1;
      LODWORD(v29) = (unsigned __int128)_mm_shuffle_ps((__m128)*(unsigned int *)srcL, (__m128)*(unsigned int *)srcL, 0);
      LODWORD(v30) = (unsigned __int128)_mm_shuffle_ps((__m128)*(unsigned int *)srcR, (__m128)*(unsigned int *)srcR, 0);
      if ( n - 1 > 0 )
      {
        v31 = (char *)srcL - (char *)srcR;
        v32 = srcR + 1;
        v33 = (char *)v6 - (char *)srcR - 4;
        v34 = (unsigned int)v28;
        do
        {
          ++v32;
          v35 = v7.m128_f32[0] * v30;
          LODWORD(v30) = (unsigned __int128)_mm_shuffle_ps(
                                              (__m128)*((unsigned int *)v32 - 1),
                                              (__m128)*((unsigned int *)v32 - 1),
                                              0);
          v36 = v29 - v35;
          v37 = (__m128)*(unsigned int *)((char *)v32 + v31 - 4);
          *(float *)((char *)v32 + v33 - 4) = v36;
          LODWORD(v29) = (unsigned __int128)_mm_shuffle_ps(v37, v37, 0);
          --v34;
        }
        while ( v34 );
      }
      v6[v28] = v29 - (float)(v7.m128_f32[0] * v30);
    }
    else if ( blendMode )
    {
      if ( blendMode == 1 )
      {
        v9 = n - 1;
        LODWORD(v10) = (unsigned __int128)_mm_shuffle_ps(
                                            (__m128)*(unsigned int *)srcL,
                                            (__m128)*(unsigned int *)srcL,
                                            0);
        LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(
                                            (__m128)*(unsigned int *)srcR,
                                            (__m128)*(unsigned int *)srcR,
                                            0);
        if ( n - 1 > 0 )
        {
          v12 = (char *)srcL - (char *)srcR;
          v13 = srcR + 1;
          v14 = (char *)v6 - (char *)srcR - 4;
          v15 = (unsigned int)v9;
          do
          {
            ++v13;
            v16 = v7.m128_f32[0] * v11;
            LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(
                                                (__m128)*((unsigned int *)v13 - 1),
                                                (__m128)*((unsigned int *)v13 - 1),
                                                0);
            v17 = v16 + v10;
            LODWORD(v10) = (unsigned __int128)_mm_shuffle_ps(
                                                (__m128)*(unsigned int *)((char *)v13 + v12 - 4),
                                                (__m128)*(unsigned int *)((char *)v13 + v12 - 4),
                                                0);
            *(float *)((char *)v13 + v14 - 4) = v17;
            --v15;
          }
          while ( v15 );
        }
        v6[v9] = (float)(v7.m128_f32[0] * v11) + v10;
      }
    }
    else
    {
      v18 = n - 1;
      LODWORD(v19) = (unsigned __int128)_mm_shuffle_ps((__m128)*(unsigned int *)srcL, (__m128)*(unsigned int *)srcL, 0);
      LODWORD(v20) = (unsigned __int128)_mm_shuffle_ps((__m128)*(unsigned int *)srcR, (__m128)*(unsigned int *)srcR, 0);
      if ( n - 1 > 0 )
      {
        v21 = (char *)srcL - (char *)srcR;
        v22 = srcR + 1;
        v23 = (char *)v6 - (char *)srcR - 4;
        v24 = (unsigned int)v18;
        do
        {
          ++v22;
          v25 = v7.m128_f32[0] * v20;
          v26 = v8 * v19;
          LODWORD(v19) = (unsigned __int128)_mm_shuffle_ps(
                                              (__m128)*(unsigned int *)((char *)v22 + v21 - 4),
                                              (__m128)*(unsigned int *)((char *)v22 + v21 - 4),
                                              0);
          v27 = v25 + v26;
          LODWORD(v20) = (unsigned __int128)_mm_shuffle_ps(
                                              (__m128)*((unsigned int *)v22 - 1),
                                              (__m128)*((unsigned int *)v22 - 1),
                                              0);
          *(float *)((char *)v22 + v23 - 4) = v27;
          --v24;
        }
        while ( v24 );
      }
      v6[v18] = (float)(v7.m128_f32[0] * v20) + (float)(v8 * v19);
    }
  }
}

// File Line: 77
// RVA: 0xB3F760
void __fastcall hkaBlender::blend(hkVector4f *dst, hkVector4f *srcL, hkVector4f *srcR, hkSimdFloat32 *alpha, int n, hkaBlender::BLEND_MODE blendMode)
{
  __int64 v6; // rax
  __m128 v7; // xmm1
  signed __int64 v8; // r8
  signed __int64 v9; // rcx
  __m128 v10; // xmm0
  __m128 v11; // xmm2
  signed __int64 v12; // r8
  signed __int64 v13; // rcx
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  signed __int64 v16; // r8
  signed __int64 v17; // rcx
  __m128 v18; // xmm1
  __m128 v19; // xmm0

  v6 = n;
  if ( blendMode == -1 )
  {
    if ( n > 0i64 )
    {
      v15 = alpha->m_real;
      v16 = (char *)srcR - (char *)srcL;
      v17 = (char *)dst - (char *)srcL;
      do
      {
        v18 = *(__m128 *)((char *)&srcL->m_quad + v16);
        v19 = srcL->m_quad;
        ++srcL;
        *(__m128 *)((char *)&srcL[-1].m_quad + v17) = _mm_sub_ps(v19, _mm_mul_ps(v18, v15));
        --v6;
      }
      while ( v6 );
    }
  }
  else if ( blendMode )
  {
    if ( blendMode == 1 && n > 0i64 )
    {
      v7 = alpha->m_real;
      v8 = (char *)srcR - (char *)srcL;
      v9 = (char *)dst - (char *)srcL;
      do
      {
        v10 = *(__m128 *)((char *)&srcL->m_quad + v8);
        ++srcL;
        *(__m128 *)((char *)&srcL[-1].m_quad + v9) = _mm_add_ps(_mm_mul_ps(v10, v7), srcL[-1].m_quad);
        --v6;
      }
      while ( v6 );
    }
  }
  else if ( n > 0i64 )
  {
    v11 = alpha->m_real;
    v12 = (char *)srcR - (char *)srcL;
    v13 = (char *)dst - (char *)srcL;
    do
    {
      v14 = *(__m128 *)((char *)&srcL->m_quad + v12);
      ++srcL;
      *(__m128 *)((char *)&srcL[-1].m_quad + v13) = _mm_add_ps(
                                                      _mm_mul_ps(_mm_sub_ps(v14, srcL[-1].m_quad), v11),
                                                      srcL[-1].m_quad);
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 107
// RVA: 0xB3F830
void __fastcall hkaBlender::blend(hkQuaternionf *dst, hkQuaternionf *srcL, hkQuaternionf *srcR, hkSimdFloat32 *alpha, int n, hkaBlender::BLEND_MODE blendMode, hkaBlender::ROTATION_MODE rotationMode)
{
  hkSimdFloat32 *v7; // rbp
  hkQuaternionf *v8; // rbx
  hkQuaternionf *v9; // rdi
  __int64 v10; // r15
  signed __int64 v11; // r14
  signed __int64 v12; // rsi
  __m128 v13; // xmm2
  __m128 v14; // xmm4
  __m128 v15; // xmm5
  __m128 v16; // xmm6
  __m128 v17; // xmm3
  __m128 v18; // xmm3
  signed __int64 v19; // rsi
  __int64 v20; // r14
  signed __int64 v21; // rdi
  __int64 v22; // r15
  signed __int64 v23; // r14
  signed __int64 v24; // rsi
  __m128 v25; // xmm3
  __m128 v26; // xmm4
  __m128 v27; // xmm0
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  __m128 v30; // xmm0
  __int64 v31; // rax
  __m128 v32; // xmm8
  __m128 v33; // xmm9
  __m128 v34; // xmm5
  __m128 v35; // xmm2
  __m128 v36; // xmm7
  __m128 v37; // xmm3
  __m128 v38; // xmm0
  __m128 v39; // xmm4
  __m128 v40; // xmm1
  __m128 v41; // xmm6
  __m128 v42; // xmm5
  __m128 v43; // xmm6
  __m128 v44; // xmm6
  __m128 v45; // xmm6
  __m128 v46; // xmm0
  __m128 v47; // xmm1
  signed __int64 v48; // rsi
  __m128 v49; // xmm5
  __m128 v50; // xmm6
  __m128 v51; // xmm0
  __m128 v52; // xmm0
  __m128 v53; // xmm1
  __m128 v54; // xmm6
  __m128 v55; // xmm7
  __m128 v56; // xmm2
  __m128 v57; // xmm3
  __m128 v58; // xmm1
  __m128 v59; // xmm5
  __m128 v60; // xmm0
  __m128 v61; // xmm3
  __m128 v62; // xmm5
  __m128 v63; // xmm0
  __m128 v64; // xmm5
  __m128 v65; // xmm0
  __m128 v66; // xmm1
  hkQuaternionf q1; // [rsp+20h] [rbp-78h]

  v7 = alpha;
  v8 = srcL;
  v9 = dst;
  if ( rotationMode == 1 )
  {
    if ( blendMode == -1 )
    {
      if ( n > 0 )
      {
        v22 = (unsigned int)n;
        v23 = (char *)srcL - (char *)dst;
        v24 = (char *)srcR - (char *)srcL;
        do
        {
          v25 = *(__m128 *)((char *)&v8->m_vec.m_quad + v24);
          v26 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v8->m_vec.m_quad, v8->m_vec.m_quad, 201), v25),
                  _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v8->m_vec.m_quad));
          v27 = _mm_mul_ps(_mm_shuffle_ps(v8->m_vec.m_quad, v8->m_vec.m_quad, 255), v25);
          v28 = _mm_mul_ps(v25, v8->m_vec.m_quad);
          v29 = _mm_add_ps(
                  _mm_sub_ps(_mm_shuffle_ps(v26, v26, 201), v27),
                  _mm_mul_ps(
                    _mm_shuffle_ps(
                      *(__m128 *)((char *)&v8->m_vec.m_quad + v24),
                      *(__m128 *)((char *)&v8->m_vec.m_quad + v24),
                      255),
                    v8->m_vec.m_quad));
          v30 = _mm_add_ps(_mm_shuffle_ps(v28, v28, 78), v28);
          q1.m_vec.m_quad = _mm_shuffle_ps(
                              v29,
                              _mm_unpackhi_ps(v29, _mm_add_ps(_mm_shuffle_ps(v30, v30, 177), v30)),
                              196);
          hkQuaternionf::setSlerp(v9, (hkQuaternionf *)((char *)v9 + v23), &q1, v7);
          ++v9;
          ++v8;
          --v22;
        }
        while ( v22 );
      }
    }
    else if ( blendMode )
    {
      if ( blendMode == 1 && n > 0 )
      {
        v10 = (unsigned int)n;
        v11 = (char *)srcL - (char *)dst;
        v12 = (char *)srcR - (char *)srcL;
        do
        {
          v13 = *(__m128 *)((char *)&v8->m_vec.m_quad + v12);
          v14 = _mm_shuffle_ps(v8->m_vec.m_quad, v8->m_vec.m_quad, 255);
          v15 = _mm_shuffle_ps(
                  *(__m128 *)((char *)&v8->m_vec.m_quad + v12),
                  *(__m128 *)((char *)&v8->m_vec.m_quad + v12),
                  255);
          v16 = _mm_mul_ps(v8->m_vec.m_quad, v13);
          v17 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v8->m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v8->m_vec.m_quad, v8->m_vec.m_quad, 201), v13));
          v18 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_shuffle_ps(v17, v17, 201),
                    _mm_mul_ps(*(__m128 *)((char *)&v8->m_vec.m_quad + v12), v14)),
                  _mm_mul_ps(v8->m_vec.m_quad, v15));
          q1.m_vec.m_quad = _mm_shuffle_ps(
                              v18,
                              _mm_unpackhi_ps(
                                v18,
                                _mm_sub_ps(
                                  _mm_mul_ps(v15, v14),
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                                    _mm_shuffle_ps(v16, v16, 170)))),
                              196);
          hkQuaternionf::setSlerp(v9, (hkQuaternionf *)((char *)v9 + v11), &q1, v7);
          ++v9;
          ++v8;
          --v10;
        }
        while ( v10 );
      }
    }
    else if ( n > 0 )
    {
      v19 = (char *)srcR - (char *)srcL;
      v20 = (unsigned int)n;
      v21 = (char *)dst - (char *)srcL;
      do
      {
        hkQuaternionf::setSlerp((hkQuaternionf *)((char *)v8 + v21), v8, (hkQuaternionf *)((char *)v8 + v19), v7);
        ++v8;
        --v20;
      }
      while ( v20 );
    }
  }
  else
  {
    v31 = n;
    if ( blendMode == -1 )
    {
      if ( n > 0i64 )
      {
        v54 = _mm_shuffle_ps((__m128)(unsigned int)*(_OWORD *)alpha, (__m128)(unsigned int)*(_OWORD *)alpha, 0);
        v55 = _mm_sub_ps(query.m_quad, v54);
        do
        {
          v56 = v8->m_vec.m_quad;
          v57 = *(__m128 *)((char *)&v8->m_vec.m_quad + (char *)srcR - (char *)srcL);
          ++v8;
          v58 = _mm_mul_ps(_mm_shuffle_ps(v57, v57, 255), v56);
          v59 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v57),
                  _mm_mul_ps(_mm_shuffle_ps(v57, v57, 201), v56));
          v60 = _mm_mul_ps(_mm_shuffle_ps(v56, v56, 255), v57);
          v61 = _mm_mul_ps(v57, v56);
          v62 = _mm_add_ps(_mm_sub_ps(_mm_shuffle_ps(v59, v59, 201), v60), v58);
          v63 = _mm_add_ps(_mm_shuffle_ps(v61, v61, 78), v61);
          v64 = _mm_shuffle_ps(v62, _mm_unpackhi_ps(v62, _mm_add_ps(_mm_shuffle_ps(v63, v63, 177), v63)), 196);
          v65 = _mm_mul_ps(v64, v56);
          v66 = _mm_add_ps(_mm_shuffle_ps(v65, v65, 78), v65);
          *(__m128 *)((char *)&v8[-1].m_vec.m_quad + (char *)dst - (char *)srcL) = _mm_add_ps(
                                                                                     _mm_mul_ps(
                                                                                       _mm_xor_ps(
                                                                                         (__m128)_mm_slli_epi32(
                                                                                                   _mm_srli_epi32(
                                                                                                     (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v66, v66, 177), v66), (__m128)0i64),
                                                                                                     0x1Fu),
                                                                                                   0x1Fu),
                                                                                         v55),
                                                                                       v56),
                                                                                     _mm_mul_ps(v64, v54));
          --v31;
        }
        while ( v31 );
      }
    }
    else if ( blendMode )
    {
      if ( blendMode == 1 && n > 0i64 )
      {
        v32 = _mm_shuffle_ps((__m128)(unsigned int)*(_OWORD *)alpha, (__m128)(unsigned int)*(_OWORD *)alpha, 0);
        v33 = _mm_sub_ps(query.m_quad, v32);
        do
        {
          v34 = v8->m_vec.m_quad;
          v35 = *(__m128 *)((char *)&v8->m_vec.m_quad + (char *)srcR - (char *)srcL);
          ++v8;
          v36 = v34;
          v37 = _mm_shuffle_ps(v34, v34, 255);
          v38 = _mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v35);
          v39 = _mm_shuffle_ps(v35, v35, 255);
          v40 = _mm_mul_ps(v34, v39);
          v41 = _mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), v34);
          v42 = _mm_mul_ps(v34, v35);
          v43 = _mm_sub_ps(v41, v38);
          v44 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v43, v43, 201), _mm_mul_ps(v35, v37)), v40);
          v45 = _mm_shuffle_ps(
                  v44,
                  _mm_unpackhi_ps(
                    v44,
                    _mm_sub_ps(
                      _mm_mul_ps(v39, v37),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)),
                        _mm_shuffle_ps(v42, v42, 170)))),
                  196);
          v46 = _mm_mul_ps(v45, v36);
          v47 = _mm_add_ps(_mm_shuffle_ps(v46, v46, 78), v46);
          *(__m128 *)((char *)&v8[-1].m_vec.m_quad + (char *)dst - (char *)srcL) = _mm_add_ps(
                                                                                     _mm_mul_ps(
                                                                                       _mm_xor_ps(
                                                                                         (__m128)_mm_slli_epi32(
                                                                                                   _mm_srli_epi32(
                                                                                                     (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v47, v47, 177), v47), (__m128)0i64),
                                                                                                     0x1Fu),
                                                                                                   0x1Fu),
                                                                                         v33),
                                                                                       v36),
                                                                                     _mm_mul_ps(v45, v32));
          --v31;
        }
        while ( v31 );
      }
    }
    else if ( n > 0i64 )
    {
      v48 = (char *)srcR - (char *)srcL;
      v49 = _mm_shuffle_ps((__m128)(unsigned int)*(_OWORD *)alpha, (__m128)(unsigned int)*(_OWORD *)alpha, 0);
      v50 = _mm_sub_ps(query.m_quad, v49);
      do
      {
        v51 = *(__m128 *)((char *)&v8->m_vec.m_quad + v48);
        ++v8;
        v52 = _mm_mul_ps(v51, v8[-1].m_vec.m_quad);
        v53 = _mm_add_ps(_mm_shuffle_ps(v52, v52, 78), v52);
        *(__m128 *)((char *)&v8[-1].m_vec.m_quad + (char *)dst - (char *)srcL) = _mm_add_ps(
                                                                                   _mm_mul_ps(
                                                                                     _mm_xor_ps(
                                                                                       (__m128)_mm_slli_epi32(
                                                                                                 _mm_srli_epi32(
                                                                                                   (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v53, v53, 177), v53), (__m128)0i64),
                                                                                                   0x1Fu),
                                                                                                 0x1Fu),
                                                                                       v50),
                                                                                     v8[-1].m_vec.m_quad),
                                                                                   _mm_mul_ps(
                                                                                     v49,
                                                                                     *(__m128 *)((char *)&v8[-1].m_vec.m_quad
                                                                                               + v48)));
        --v31;
      }
      while ( v31 );
    }
  }
}                                                                        *(__m128 *)((ch

// File Line: 178
// RVA: 0xB3FD30
void __fastcall hkaBlender::blend(hkQsTransformf *dst, hkQsTransformf *srcL, hkQsTransformf *srcR, hkSimdFloat32 *alpha, int n, hkaBlender::BLEND_MODE blendMode, hkaBlender::ROTATION_MODE rotationMode)
{
  hkSimdFloat32 *v7; // r15
  hkQsTransformf *v8; // rsi
  __int64 v9; // r12
  __m128 v10; // xmm8
  signed __int64 v11; // rdi
  __m128 *v12; // r13
  signed __int64 v13; // r14
  __m128 *v14; // rbx
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm6
  __m128 v19; // xmm0
  __m128 v20; // xmm3
  __m128 v21; // xmm7
  __m128 v22; // xmm4
  __m128 v23; // xmm5
  __m128 v24; // xmm0
  __m128 v25; // xmm3
  __m128 v26; // xmm5
  __m128 v27; // xmm0
  __m128 v28; // xmm2
  hkVector4f *v29; // rbx
  signed __int64 v30; // r12
  signed __int64 v31; // rsi
  signed __int64 v32; // rdi
  __int64 v33; // r14
  __m128 v34; // xmm1
  signed __int64 v35; // rdi
  hkQuaternionf *v36; // r13
  signed __int64 v37; // r14
  __int64 v38; // rsi
  __m128i v39; // xmm0
  __m128 *v40; // r12
  __m128 v41; // xmm9
  __m128 v42; // xmm10
  __m128 v43; // xmm0
  __m128 v44; // xmm4
  __m128 v45; // xmm1
  __m128 v46; // xmm5
  __m128 v47; // xmm7
  __m128 v48; // xmm8
  __m128 v49; // xmm1
  __m128 v50; // xmm3
  __m128 v51; // xmm6
  __m128 v52; // xmm3
  __m128 v53; // xmm6
  __m128 v54; // xmm4
  __m128 v55; // xmm0
  __m128 v56; // xmm7
  __m128 v57; // xmm4
  __m128 v58; // xmm0
  __m128 v59; // xmm6
  __m128 v60; // xmm12
  signed __int64 v61; // rsi
  hkQuaternionf *v62; // rax
  signed __int64 v63; // rdi
  __int64 v64; // rdx
  __m128 v65; // xmm10
  __m128 v66; // xmm11
  __m128 v67; // xmm9
  __m128 v68; // xmm2
  __m128 v69; // xmm1
  __m128 v70; // xmm3
  __m128 v71; // xmm7
  __m128 v72; // xmm0
  __m128 v73; // xmm2
  __m128 v74; // xmm8
  __m128 v75; // xmm4
  __m128 v76; // xmm1
  __m128 v77; // xmm3
  __m128 v78; // xmm6
  __m128 v79; // xmm0
  __m128 v80; // xmm2
  __m128 v81; // xmm6
  __m128 v82; // xmm6
  __m128 v83; // xmm0
  __m128 v84; // xmm1
  __m128 v85; // xmm3
  __int64 v86; // rcx
  __m128 v87; // xmm5
  signed __int64 v88; // rsi
  hkQuaternionf *v89; // rax
  signed __int64 v90; // rdi
  __m128 v91; // xmm6
  __m128 v92; // xmm7
  __m128 v93; // xmm1
  __m128 v94; // xmm0
  __m128 v95; // xmm0
  __m128 v96; // xmm1
  __m128 v97; // xmm0
  __m128 v98; // xmm2
  signed __int64 v99; // rsi
  __m128 *v100; // r12
  __m128i v101; // xmm0
  signed __int64 v102; // rdi
  __int64 v103; // r14
  __m128 v104; // xmm12
  __m128 v105; // xmm13
  char *v106; // rbx
  __m128 v107; // xmm11
  __m128 v108; // xmm2
  __m128 v109; // xmm7
  __m128 v110; // xmm3
  __m128 v111; // xmm5
  __m128 v112; // xmm10
  __m128 v113; // xmm1
  __m128 v114; // xmm4
  __m128 v115; // xmm2
  __m128 v116; // xmm0
  __m128 v117; // xmm3
  __m128 v118; // xmm9
  __m128 v119; // xmm8
  __m128 v120; // xmm0
  __m128 v121; // xmm5
  __m128 v122; // xmm8
  __m128 v123; // xmm1
  __m128 v124; // xmm5
  __m128 v125; // xmm8
  __m128 v126; // xmm6
  __m128 v127; // xmm0
  __m128 v128; // xmm0
  __m128 v129; // xmm3
  __m128 v130; // xmm6
  __m128 v131; // xmm1
  hkQuaternionf q1; // [rsp+30h] [rbp-A8h]
  __m128 v133; // [rsp+40h] [rbp-98h]
  hkVector4f v134; // [rsp+50h] [rbp-88h]
  __int64 v135; // [rsp+128h] [rbp+50h]
  void *retaddr; // [rsp+148h] [rbp+70h]
  int v137; // [rsp+150h] [rbp+78h]
  int v138; // [rsp+158h] [rbp+80h]

  v7 = alpha;
  v8 = dst;
  if ( v138 == 1 )
  {
    v9 = (signed int)retaddr;
    v135 = (signed int)retaddr;
    if ( v137 == -1 )
    {
      if ( (signed int)retaddr > 0 )
      {
        v35 = (char *)srcR - (char *)srcL;
        v36 = (hkQuaternionf *)&dst->m_scale;
        v37 = (char *)srcL - (char *)dst;
        v38 = v135;
        v39 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
        v40 = &srcL->m_rotation.m_vec.m_quad;
        v41 = (__m128)_mm_shuffle_epi32(v39, 0);
        v42 = (__m128)_mm_shuffle_epi32(v39, 64);
        do
        {
          hkVector4f::setRotatedInverseDir(
            &v134,
            (hkQuaternionf *)((char *)v40 + v35),
            (hkVector4f *)((char *)&v40[-1] + v35));
          v43 = *(__m128 *)((char *)v40 + v35 + 16);
          v44 = _mm_xor_ps(v41, v134.m_quad);
          v45 = _mm_rcp_ps(v43);
          v46 = _mm_shuffle_ps(*v40, *v40, 255);
          v47 = _mm_xor_ps(v42, *(__m128 *)((char *)v40 + v35));
          v48 = (__m128)_mm_srli_si128(
                          _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v43, v45)), v45), 4),
                          4);
          v49 = _mm_mul_ps(*v40, v44);
          v50 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), *v40),
                  _mm_mul_ps(_mm_shuffle_ps(*v40, *v40, 201), v44));
          v51 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)),
                        _mm_shuffle_ps(v49, v49, 170)),
                      *v40),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v46, v46), (__m128)xmmword_141A711B0), v44)),
                  _mm_mul_ps(_mm_shuffle_ps(v50, v50, 201), v46));
          v52 = _mm_shuffle_ps(v47, v47, 255);
          v53 = _mm_add_ps(_mm_add_ps(v51, v51), v40[-1]);
          v54 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), *v40),
                  _mm_mul_ps(_mm_shuffle_ps(*v40, *v40, 201), v47));
          v55 = _mm_mul_ps(v46, v47);
          v56 = _mm_mul_ps(v47, *v40);
          v57 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v54, v54, 201), v55), _mm_mul_ps(v52, *v40));
          v58 = _mm_mul_ps(v40[1], v48);
          q1.m_vec.m_quad = _mm_shuffle_ps(
                              v57,
                              _mm_unpackhi_ps(
                                v57,
                                _mm_sub_ps(
                                  _mm_mul_ps(v52, v46),
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
                                    _mm_shuffle_ps(v56, v56, 170)))),
                              196);
          v59 = _mm_sub_ps(v53, *(__m128 *)((char *)&v36[-2].m_vec.m_quad + v37));
          v133 = v58;
          v36[-2].m_vec.m_quad = _mm_add_ps(
                                   _mm_mul_ps(v59, v7->m_real),
                                   *(__m128 *)((char *)&v36[-2].m_vec.m_quad + v37));
          hkQuaternionf::setSlerp(v36 - 1, (hkQuaternionf *)((char *)v36 + v37 - 16), &q1, v7);
          v36 += 3;
          v40 += 3;
          v36[-3].m_vec.m_quad = _mm_add_ps(
                                   _mm_mul_ps(
                                     _mm_sub_ps(v133, *(__m128 *)((char *)&v36[-3].m_vec.m_quad + v37)),
                                     v7->m_real),
                                   *(__m128 *)((char *)&v36[-3].m_vec.m_quad + v37));
          --v38;
        }
        while ( v38 );
      }
    }
    else if ( v137 )
    {
      if ( v137 == 1 && (signed int)retaddr > 0 )
      {
        v10 = alpha->m_real;
        v11 = (char *)srcR - (char *)srcL;
        v12 = &dst->m_scale.m_quad;
        v13 = (char *)srcL - (char *)dst;
        v14 = &srcL->m_rotation.m_vec.m_quad;
        do
        {
          v15 = *(__m128 *)((char *)v14 + v11 - 16);
          v16 = _mm_mul_ps(*(__m128 *)((char *)v14 + v11 - 16), *v14);
          v17 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), *v14),
                  _mm_mul_ps(_mm_shuffle_ps(*v14, *v14, 201), v15));
          v18 = _mm_shuffle_ps(*v14, *v14, 255);
          v19 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v18, v18), (__m128)xmmword_141A711B0), v15);
          v20 = *(__m128 *)((char *)v14 + v11);
          v21 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                        _mm_shuffle_ps(v16, v16, 170)),
                      *v14),
                    v19),
                  _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v18));
          v22 = _mm_shuffle_ps(*(__m128 *)((char *)v14 + v11), *(__m128 *)((char *)v14 + v11), 255);
          v23 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), *v14),
                  _mm_mul_ps(_mm_shuffle_ps(*v14, *v14, 201), v20));
          v24 = _mm_mul_ps(v18, v20);
          v25 = _mm_mul_ps(v20, *v14);
          v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 201), v24), _mm_mul_ps(v22, *v14));
          v12[-2] = _mm_add_ps(
                      _mm_mul_ps(
                        _mm_sub_ps(_mm_add_ps(_mm_add_ps(v21, v21), v14[-1]), *(__m128 *)((char *)v12 + v13 - 32)),
                        v10),
                      *(__m128 *)((char *)v12 + v13 - 32));
          v27 = _mm_mul_ps(*(__m128 *)((char *)v14 + v11 + 16), v14[1]);
          q1.m_vec.m_quad = _mm_shuffle_ps(
                              v26,
                              _mm_unpackhi_ps(
                                v26,
                                _mm_sub_ps(
                                  _mm_mul_ps(v22, v18),
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                                    _mm_shuffle_ps(v25, v25, 170)))),
                              196);
          v133 = v27;
          hkQuaternionf::setSlerp((hkQuaternionf *)&v12[-1], (hkQuaternionf *)((char *)&v12[-1] + v13), &q1, v7);
          v10 = v7->m_real;
          *v12 = _mm_add_ps(
                   _mm_mul_ps(_mm_sub_ps(v133, *(__m128 *)((char *)v12 + v13)), v7->m_real),
                   *(__m128 *)((char *)v12 + v13));
          v12 += 3;
          v14 += 3;
          --v9;
        }
        while ( v9 );
      }
    }
    else if ( (signed int)retaddr > 0 )
    {
      v28 = alpha->m_real;
      v29 = &srcL->m_scale;
      v30 = (char *)srcL - (char *)dst;
      v31 = (char *)dst - (char *)srcL;
      v32 = (char *)srcR - (char *)srcL;
      v33 = (unsigned int)retaddr;
      do
      {
        *(__m128 *)((char *)&v29[-2].m_quad + v31) = _mm_add_ps(
                                                       _mm_mul_ps(
                                                         _mm_sub_ps(
                                                           *(__m128 *)((char *)&v29[-2].m_quad + v32),
                                                           v29[-2].m_quad),
                                                         v28),
                                                       v29[-2].m_quad);
        hkQuaternionf::setSlerp(
          (hkQuaternionf *)((char *)&v29[-1] + v31),
          (hkQuaternionf *)((char *)&v29[-1] + v31 + v30),
          (hkQuaternionf *)((char *)&v29[-1] + v32),
          v7);
        v34 = *(__m128 *)((char *)&v29->m_quad + v32);
        v29 += 3;
        v28 = v7->m_real;
        *(__m128 *)((char *)&v29[-3].m_quad + v31) = _mm_add_ps(
                                                       _mm_mul_ps(_mm_sub_ps(v34, v29[-3].m_quad), v7->m_real),
                                                       v29[-3].m_quad);
        --v33;
      }
      while ( v33 );
    }
  }
  else if ( v137 == -1 )
  {
    if ( (signed int)retaddr > 0 )
    {
      v99 = (char *)dst - (char *)srcR;
      v100 = &srcL->m_rotation.m_vec.m_quad;
      v101 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
      v102 = (char *)srcR - (char *)srcL;
      v103 = (unsigned int)retaddr;
      v104 = (__m128)_mm_shuffle_epi32(v101, 0);
      v105 = (__m128)_mm_shuffle_epi32(v101, 64);
      do
      {
        v106 = (char *)v100 + v102;
        hkVector4f::setRotatedInverseDir(
          &v134,
          (hkQuaternionf *)((char *)v100 + v102),
          (hkVector4f *)((char *)&v100[-1] + v102));
        v107 = *v100;
        v108 = _mm_rcp_ps(*(__m128 *)((char *)v100 + v102 + 16));
        v109 = v100[-1];
        v110 = _mm_xor_ps(v104, v134.m_quad);
        v111 = _mm_xor_ps(v105, *(__m128 *)((char *)v100 + v102));
        v112 = (__m128)_mm_srli_si128(
                         _mm_slli_si128(
                           (__m128i)_mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v108, *(__m128 *)((char *)v100 + v102 + 16))),
                                      v108),
                           4),
                         4);
        v113 = _mm_mul_ps(*v100, v110);
        v114 = _mm_shuffle_ps(*v100, *v100, 255);
        v115 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v110, v110, 201), *v100),
                 _mm_mul_ps(_mm_shuffle_ps(v107, v107, 201), v110));
        v116 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v114, v114), (__m128)xmmword_141A711B0), v110);
        v117 = _mm_shuffle_ps(v111, v111, 255);
        v118 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v113, v113, 85), _mm_shuffle_ps(v113, v113, 0)),
                       _mm_shuffle_ps(v113, v113, 170)),
                     *v100),
                   v116),
                 _mm_mul_ps(_mm_shuffle_ps(v115, v115, 201), v114));
        v119 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v111, v111, 201), *v100),
                 _mm_mul_ps(_mm_shuffle_ps(*v100, *v100, 201), v111));
        v120 = v111;
        v121 = _mm_mul_ps(v111, *v100);
        v122 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v119, v119, 201), _mm_mul_ps(v120, v114)), _mm_mul_ps(*v100, v117));
        v123 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v121, v121, 85), _mm_shuffle_ps(v121, v121, 0)),
                 _mm_shuffle_ps(v121, v121, 170));
        v124 = v100[1];
        v125 = _mm_shuffle_ps(v122, _mm_unpackhi_ps(v122, _mm_sub_ps(_mm_mul_ps(v117, v114), v123)), 196);
        v126 = _mm_mul_ps(v100[1], v112);
        v127 = *v100;
        v100 += 3;
        v128 = _mm_mul_ps(v127, v125);
        v129 = _mm_shuffle_ps((__m128)(unsigned int)*(_OWORD *)v7, (__m128)(unsigned int)*(_OWORD *)v7, 0);
        v130 = _mm_mul_ps(_mm_sub_ps(v126, v124), v7->m_real);
        *(__m128 *)&v106[v99 - 16] = _mm_add_ps(
                                       _mm_mul_ps(
                                         _mm_sub_ps(_mm_add_ps(_mm_add_ps(v118, v118), v109), v109),
                                         v7->m_real),
                                       v109);
        v131 = _mm_add_ps(_mm_shuffle_ps(v128, v128, 78), v128);
        *(__m128 *)&v106[v99 + 16] = _mm_add_ps(v130, v124);
        *(__m128 *)&v106[v99] = _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_xor_ps(
                                      (__m128)_mm_slli_epi32(
                                                _mm_srli_epi32(
                                                  (__m128i)_mm_cmpltps(
                                                             _mm_add_ps(_mm_shuffle_ps(v131, v131, 177), v131),
                                                             (__m128)0i64),
                                                  0x1Fu),
                                                0x1Fu),
                                      _mm_sub_ps(query.m_quad, v129)),
                                    v107),
                                  _mm_mul_ps(v125, v129));
        --v103;
      }
      while ( v103 );
    }
  }
  else if ( v137 )
  {
    if ( v137 == 1 && (signed int)retaddr > 0 )
    {
      v60 = alpha->m_real;
      v61 = (char *)dst - (char *)srcL;
      v62 = &srcL->m_rotation;
      v63 = (char *)srcR - (char *)srcL;
      v64 = (unsigned int)retaddr;
      v65 = _mm_shuffle_ps((__m128)(unsigned int)*(_OWORD *)alpha, (__m128)(unsigned int)*(_OWORD *)alpha, 0);
      v66 = _mm_sub_ps(query.m_quad, v65);
      do
      {
        v67 = v62->m_vec.m_quad;
        v68 = *(__m128 *)((char *)&v62[-1].m_vec.m_quad + v63);
        v69 = _mm_mul_ps(*(__m128 *)((char *)&v62[-1].m_vec.m_quad + v63), v62->m_vec.m_quad);
        v70 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v68, v68, 201), v62->m_vec.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v67, v67, 201), v68));
        v71 = _mm_shuffle_ps(v62->m_vec.m_quad, v62->m_vec.m_quad, 255);
        v72 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v71, v71), (__m128)xmmword_141A711B0), v68);
        v73 = *(__m128 *)((char *)&v62->m_vec.m_quad + v63);
        v74 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v69, v69, 85), _mm_shuffle_ps(v69, v69, 0)),
                      _mm_shuffle_ps(v69, v69, 170)),
                    v62->m_vec.m_quad),
                  v72),
                _mm_mul_ps(_mm_shuffle_ps(v70, v70, 201), v71));
        v75 = _mm_shuffle_ps(
                *(__m128 *)((char *)&v62->m_vec.m_quad + v63),
                *(__m128 *)((char *)&v62->m_vec.m_quad + v63),
                255);
        v76 = _mm_mul_ps(v75, v62->m_vec.m_quad);
        v77 = _mm_mul_ps(v62->m_vec.m_quad, v73);
        v78 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v73, v73, 201), v62->m_vec.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v62->m_vec.m_quad, v62->m_vec.m_quad, 201), v73));
        v79 = _mm_mul_ps(v71, v73);
        v80 = v62[1].m_vec.m_quad;
        *(__m128 *)((char *)&v62[-1].m_vec.m_quad + v61) = _mm_add_ps(
                                                             _mm_mul_ps(
                                                               _mm_sub_ps(
                                                                 _mm_add_ps(_mm_add_ps(v74, v74), v62[-1].m_vec.m_quad),
                                                                 v62[-1].m_vec.m_quad),
                                                               v60),
                                                             v62[-1].m_vec.m_quad);
        v81 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v78, v78, 201), v79), v76);
        v82 = _mm_shuffle_ps(
                v81,
                _mm_unpackhi_ps(
                  v81,
                  _mm_sub_ps(
                    _mm_mul_ps(v75, v71),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v77, v77, 85), _mm_shuffle_ps(v77, v77, 0)),
                      _mm_shuffle_ps(v77, v77, 170)))),
                196);
        v83 = _mm_mul_ps(v67, v82);
        v84 = _mm_add_ps(_mm_shuffle_ps(v83, v83, 78), v83);
        v85 = _mm_sub_ps(_mm_mul_ps(*(__m128 *)((char *)&v62[1].m_vec.m_quad + v63), v80), v80);
        v62 += 3;
        *(__m128 *)((char *)&v62[-2].m_vec.m_quad + v61) = _mm_add_ps(_mm_mul_ps(v85, v60), v80);
        *(__m128 *)((char *)&v62[-3].m_vec.m_quad + v61) = _mm_add_ps(
                                                             _mm_mul_ps(
                                                               _mm_xor_ps(
                                                                 (__m128)_mm_slli_epi32(
                                                                           _mm_srli_epi32(
                                                                             (__m128i)_mm_cmpltps(
                                                                                        _mm_add_ps(
                                                                                          _mm_shuffle_ps(v84, v84, 177),
                                                                                          v84),
                                                                                        (__m128)0i64),
                                                                             0x1Fu),
                                                                           0x1Fu),
                                                                 v66),
                                                               v67),
                                                             _mm_mul_ps(v82, v65));
        --v64;
      }
      while ( v64 );
    }
  }
  else
  {
    v86 = (unsigned int)retaddr;
    if ( (signed int)retaddr > 0 )
    {
      v87 = alpha->m_real;
      v88 = (char *)v8 - (char *)srcL;
      v89 = &srcL->m_rotation;
      v90 = (char *)srcR - (char *)srcL;
      v91 = _mm_shuffle_ps((__m128)(unsigned int)*(_OWORD *)alpha, (__m128)(unsigned int)*(_OWORD *)alpha, 0);
      v92 = _mm_sub_ps(query.m_quad, v91);
      do
      {
        v93 = *(__m128 *)((char *)&v89[-1].m_vec.m_quad + v90);
        v94 = *(__m128 *)((char *)&v89->m_vec.m_quad + v90);
        v89 += 3;
        v95 = _mm_mul_ps(v94, v89[-3].m_vec.m_quad);
        *(__m128 *)((char *)&v89[-4].m_vec.m_quad + v88) = _mm_add_ps(
                                                             _mm_mul_ps(_mm_sub_ps(v93, v89[-4].m_vec.m_quad), v87),
                                                             v89[-4].m_vec.m_quad);
        v96 = _mm_add_ps(_mm_shuffle_ps(v95, v95, 78), v95);
        v97 = _mm_mul_ps(v91, *(__m128 *)((char *)&v89[-3].m_vec.m_quad + v90));
        v98 = _mm_mul_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32(
                              (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v96, v96, 177), v96), (__m128)0i64),
                              0x1Fu),
                            0x1Fu),
                  v92),
                v89[-3].m_vec.m_quad);
        *(__m128 *)((char *)&v89[-2].m_vec.m_quad + v88) = _mm_add_ps(
                                                             _mm_mul_ps(
                                                               _mm_sub_ps(
                                                                 *(__m128 *)((char *)&v89[-2].m_vec.m_quad + v90),
                                                                 v89[-2].m_vec.m_quad),
                                                               v87),
                                                             v89[-2].m_vec.m_quad);
        *(__m128 *)((char *)&v89[-3].m_vec.m_quad + v88) = _mm_add_ps(v98, v97);
        --v86;
      }
      while ( v86 );
    }
  }
}

// File Line: 273
// RVA: 0xB40680
void __fastcall hkaBlender::blend(float *dst, float *weightsOut, const float *srcL, const float *weightsL, const float *srcR, const float *weightsR, hkSimdFloat32 *alphaIn, int n, hkaBlender::BLEND_MODE blendMode)
{
  const float *v9; // rdi
  float *v10; // rsi
  const float *v11; // rbp
  const float *v12; // rbx
  __m128 v13; // xmm6
  __int64 v14; // r14
  signed __int64 v15; // rsi
  signed __int64 v16; // rdi
  signed __int64 v17; // r10
  signed __int64 v18; // rsi
  signed __int64 v19; // rax
  signed __int64 v20; // rdx
  __int64 v21; // r8
  __m128 v22; // xmm10
  __m128 v23; // xmm11
  unsigned int v24; // xmm0_4
  unsigned int v25; // xmm1_4
  __m128 v26; // xmm8
  __m128 v27; // xmm6
  __m128 v28; // xmm9
  __m128 v29; // xmm1
  __m128 v30; // xmm7
  __m128 v31; // xmm4
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  float v34; // xmm5_4
  __m128 v35; // xmm4
  __m128 v36; // xmm0
  const float *v37; // rbp
  const float *v38; // rbx
  __m128 v39; // xmm6
  __int64 v40; // r14
  signed __int64 v41; // rsi
  signed __int64 v42; // rdi

  v9 = srcL;
  v10 = dst;
  if ( blendMode == -1 )
  {
    if ( n > 0 )
    {
      v37 = weightsR;
      v38 = srcR;
      v39 = alphaIn->m_real;
      v40 = (unsigned int)n;
      memmove(weightsOut, weightsL, 4i64 * (unsigned int)n);
      v41 = (char *)v10 - (char *)srcR;
      v42 = (char *)v9 - (char *)srcR;
      do
      {
        ++v38;
        ++v37;
        *(float *)((char *)v38 + v41 - 4) = COERCE_FLOAT(
                                              _mm_shuffle_ps(
                                                (__m128)*(unsigned int *)((char *)v38 + v42 - 4),
                                                (__m128)*(unsigned int *)((char *)v38 + v42 - 4),
                                                0))
                                          - (float)(COERCE_FLOAT(
                                                      _mm_shuffle_ps(
                                                        (__m128)COERCE_UNSIGNED_INT(v39.m128_f32[0] * *(v37 - 1)),
                                                        (__m128)COERCE_UNSIGNED_INT(v39.m128_f32[0] * *(v37 - 1)),
                                                        0))
                                                  * COERCE_FLOAT(
                                                      _mm_shuffle_ps(
                                                        (__m128)*((unsigned int *)v38 - 1),
                                                        (__m128)*((unsigned int *)v38 - 1),
                                                        0)));
        --v40;
      }
      while ( v40 );
    }
  }
  else if ( blendMode )
  {
    if ( blendMode == 1 && n > 0 )
    {
      v11 = weightsR;
      v12 = srcR;
      v13 = alphaIn->m_real;
      v14 = (unsigned int)n;
      memmove(weightsOut, weightsL, 4i64 * (unsigned int)n);
      v15 = (char *)v10 - (char *)srcR;
      v16 = (char *)v9 - (char *)srcR;
      do
      {
        ++v12;
        ++v11;
        *(float *)((char *)v12 + v15 - 4) = (float)(COERCE_FLOAT(
                                                      _mm_shuffle_ps(
                                                        (__m128)COERCE_UNSIGNED_INT(v13.m128_f32[0] * *(v11 - 1)),
                                                        (__m128)COERCE_UNSIGNED_INT(v13.m128_f32[0] * *(v11 - 1)),
                                                        0))
                                                  * COERCE_FLOAT(
                                                      _mm_shuffle_ps(
                                                        (__m128)*((unsigned int *)v12 - 1),
                                                        (__m128)*((unsigned int *)v12 - 1),
                                                        0)))
                                          + COERCE_FLOAT(
                                              _mm_shuffle_ps(
                                                (__m128)*(unsigned int *)((char *)v12 + v16 - 4),
                                                (__m128)*(unsigned int *)((char *)v12 + v16 - 4),
                                                0));
        --v14;
      }
      while ( v14 );
    }
  }
  else if ( n > 0 )
  {
    v17 = (char *)weightsOut - (char *)srcL;
    v18 = (char *)dst - (char *)srcL;
    v19 = (char *)srcR - (char *)srcL;
    v20 = (char *)weightsR - (char *)weightsL;
    v21 = (unsigned int)n;
    v22 = _mm_shuffle_ps((__m128)(unsigned int)*(_OWORD *)alphaIn, (__m128)(unsigned int)*(_OWORD *)alphaIn, 0);
    v23 = _mm_sub_ps(query.m_quad, v22);
    do
    {
      v24 = *(_DWORD *)((char *)weightsL + v20);
      v25 = *(_DWORD *)weightsL;
      ++v9;
      ++weightsL;
      v26 = _mm_shuffle_ps((__m128)v25, (__m128)v25, 0);
      v27 = _mm_cmpltps((__m128)0i64, v26);
      v28 = _mm_shuffle_ps((__m128)v24, (__m128)v24, 0);
      v29 = _mm_rcp_ps(v28);
      v30 = _mm_cmpltps((__m128)0i64, v28);
      v31 = _mm_cmpltps(v28, v26);
      v32 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v28, v29)), v29);
      v29.m128_i32[0] = (unsigned __int128)_mm_rcp_ps(v26);
      v33 = _mm_mul_ps(v23, _mm_mul_ps(v32, v26));
      v32.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(
                                             (__m128)*((unsigned int *)v9 - 1),
                                             (__m128)*((unsigned int *)v9 - 1),
                                             0);
      LODWORD(v34) = COERCE_UNSIGNED_INT(
                       (float)((float)((float)(2.0 - (float)(v26.m128_f32[0] * v29.m128_f32[0])) * v29.m128_f32[0])
                             * v28.m128_f32[0])
                     * v22.m128_f32[0]) & v31.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                                     v31,
                                                                                     _mm_sub_ps(query.m_quad, v33));
      v35 = _mm_andnot_ps(v30, aabbOut.m_quad);
      v36 = _mm_andnot_ps(v30, v26);
      v29.m128_i32[0] = (COERCE_UNSIGNED_INT((float)((float)(1.0 - v34) * v26.m128_f32[0]) + (float)(v34 * v28.m128_f32[0])) & v30.m128_i32[0] | v36.m128_i32[0]) & v27.m128_i32[0];
      v36.m128_f32[0] = COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                                              v27,
                                                              _mm_or_ps(
                                                                _mm_andnot_ps(v30, v22),
                                                                _mm_and_ps(v30, query.m_quad))) | (LODWORD(v34) & v30.m128_i32[0] | v35.m128_i32[0]) & v27.m128_i32[0]);
      *(_DWORD *)((char *)v9 + v17 - 4) = v29.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                                     v27,
                                                                                     _mm_or_ps(
                                                                                       _mm_and_ps(v28, v30),
                                                                                       v35));
      *(float *)((char *)v9 + v18 - 4) = (float)((float)(COERCE_FLOAT(
                                                           _mm_shuffle_ps(
                                                             (__m128)*(unsigned int *)((char *)v9 + v19 - 4),
                                                             (__m128)*(unsigned int *)((char *)v9 + v19 - 4),
                                                             0))
                                                       - v32.m128_f32[0])
                                               * COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 0)))
                                       + v32.m128_f32[0];
      --v21;
    }
    while ( v21 );
  }
}

// File Line: 320
// RVA: 0xB40A70
void __fastcall hkaBlender::blend(hkVector4f *dst, float *weightsOut, hkVector4f *srcL, const float *weightsL, hkVector4f *srcR, const float *weightsR, hkSimdFloat32 *alphaIn, int n, hkaBlender::BLEND_MODE blendMode)
{
  __int64 v9; // r11
  __int64 v10; // r10
  signed __int64 v11; // r11
  signed __int64 v12; // rbx
  signed __int64 v13; // rdx
  signed __int64 v14; // rcx
  int v15; // eax
  unsigned int v16; // xmm0_4
  signed __int64 v17; // rax
  signed __int64 v18; // r10
  signed __int64 v19; // rcx
  unsigned int v20; // ST08_4
  __m128 v21; // xmm10
  __m128 v22; // xmm1
  __m128 v23; // xmm6
  __m128 v24; // xmm8
  __m128 v25; // xmm9
  __m128 v26; // xmm4
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  float v29; // xmm5_4
  __m128 v30; // xmm4
  __m128 v31; // xmm0
  unsigned int v32; // xmm7_4
  __m128 v33; // xmm2
  signed __int64 v34; // r11
  signed __int64 v35; // rbx
  signed __int64 v36; // rdx
  signed __int64 v37; // rcx
  int v38; // eax
  unsigned int v39; // xmm0_4

  v9 = (unsigned int)n;
  v10 = n;
  if ( blendMode == -1 )
  {
    if ( n > 0 )
    {
      v34 = (char *)weightsR - (char *)weightsL;
      v35 = (char *)srcR - (char *)srcL;
      v36 = (char *)weightsOut - (char *)weightsL;
      v37 = (char *)dst - (char *)srcL;
      do
      {
        v38 = *(_DWORD *)weightsL;
        ++srcL;
        ++weightsL;
        *(float *)&v39 = COERCE_FLOAT(*alphaIn) * *(const float *)((char *)weightsL + v34 - 4);
        *(_DWORD *)((char *)weightsL + v36 - 4) = v38;
        *(__m128 *)((char *)&srcL[-1].m_quad + v37) = _mm_sub_ps(
                                                        srcL[-1].m_quad,
                                                        _mm_mul_ps(
                                                          _mm_shuffle_ps((__m128)v39, (__m128)v39, 0),
                                                          *(__m128 *)((char *)&srcL[-1].m_quad + v35)));
        --v10;
      }
      while ( v10 );
    }
  }
  else if ( blendMode )
  {
    if ( blendMode == 1 && n > 0 )
    {
      v11 = (char *)weightsR - (char *)weightsL;
      v12 = (char *)srcR - (char *)srcL;
      v13 = (char *)weightsOut - (char *)weightsL;
      v14 = (char *)dst - (char *)srcL;
      do
      {
        v15 = *(_DWORD *)weightsL;
        ++srcL;
        ++weightsL;
        *(float *)&v16 = COERCE_FLOAT(*alphaIn) * *(const float *)((char *)weightsL + v11 - 4);
        *(_DWORD *)((char *)weightsL + v13 - 4) = v15;
        *(__m128 *)((char *)&srcL[-1].m_quad + v14) = _mm_add_ps(
                                                        _mm_mul_ps(
                                                          _mm_shuffle_ps((__m128)v16, (__m128)v16, 0),
                                                          *(__m128 *)((char *)&srcL[-1].m_quad + v12)),
                                                        srcL[-1].m_quad);
        --v10;
      }
      while ( v10 );
    }
  }
  else if ( n > 0 )
  {
    v17 = (char *)weightsR - (char *)weightsL;
    v18 = (char *)srcR - (char *)srcL;
    v19 = (char *)dst - (char *)srcL;
    do
    {
      v20 = *(_DWORD *)((char *)weightsL + v17);
      ++srcL;
      ++weightsOut;
      ++weightsL;
      --v9;
      v21 = _mm_shuffle_ps((__m128)v20, (__m128)v20, 0);
      v22 = _mm_rcp_ps(v21);
      v23 = _mm_shuffle_ps((__m128)(unsigned int)*(_OWORD *)alphaIn, (__m128)(unsigned int)*(_OWORD *)alphaIn, 0);
      v24 = _mm_cmpltps((__m128)0i64, v21);
      v25 = _mm_shuffle_ps((__m128)*((unsigned int *)weightsL - 1), (__m128)*((unsigned int *)weightsL - 1), 0);
      v26 = _mm_cmpltps(v21, v25);
      v27 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v21, v22)), v22);
      v22.m128_i32[0] = (unsigned __int128)_mm_rcp_ps(v25);
      v28 = _mm_andnot_ps(v24, aabbOut.m_quad);
      LODWORD(v29) = COERCE_UNSIGNED_INT(
                       (float)((float)((float)(2.0 - (float)(v25.m128_f32[0] * v22.m128_f32[0])) * v22.m128_f32[0])
                             * v21.m128_f32[0])
                     * v23.m128_f32[0]) & v26.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                                     v26,
                                                                                     _mm_sub_ps(
                                                                                       query.m_quad,
                                                                                       _mm_mul_ps(
                                                                                         _mm_sub_ps(query.m_quad, v23),
                                                                                         _mm_mul_ps(v27, v25))));
      v30 = _mm_cmpltps((__m128)0i64, v25);
      v31 = _mm_andnot_ps(v24, v25);
      v32 = COERCE_UNSIGNED_INT((float)((float)(1.0 - v29) * v25.m128_f32[0]) + (float)(v29 * v21.m128_f32[0])) & v24.m128_i32[0] | v31.m128_i32[0];
      v31.m128_f32[0] = COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                                              v30,
                                                              _mm_or_ps(
                                                                _mm_andnot_ps(v24, v23),
                                                                _mm_and_ps(v24, query.m_quad))) | (LODWORD(v29) & v24.m128_i32[0] | v28.m128_i32[0]) & v30.m128_i32[0]);
      v33 = _mm_mul_ps(
              _mm_sub_ps(*(__m128 *)((char *)&srcL[-1].m_quad + v18), srcL[-1].m_quad),
              _mm_shuffle_ps(v31, v31, 0));
      *((_DWORD *)weightsOut - 1) = v32 & v30.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                                     v30,
                                                                                     _mm_or_ps(
                                                                                       _mm_and_ps(v21, v24),
                                                                                       v28));
      *(__m128 *)((char *)&srcL[-1].m_quad + v19) = _mm_add_ps(v33, srcL[-1].m_quad);
    }
    while ( v9 );
  }
}

// File Line: 358
// RVA: 0xB40DC0
void __fastcall hkaBlender::blend(hkQuaternionf *dst, float *weightsOut, hkQuaternionf *srcL, const float *weightsL, hkQuaternionf *srcR)
{
  const float *v5; // rdi
  hkQuaternionf *v6; // rbx
  float *v7; // r14
  hkQuaternionf *v8; // rsi
  unsigned __int64 v9; // rax
  signed __int64 v10; // r13
  signed __int64 v11; // r15
  signed __int64 v12; // r14
  __int64 v13; // r12
  __m128 v14; // xmm2
  __m128 v15; // xmm4
  __m128 v16; // xmm5
  __m128 v17; // xmm3
  __m128 v18; // xmm6
  __m128 v19; // xmm3
  unsigned int v20; // xmm0_4
  signed __int64 v21; // rsi
  signed __int64 v22; // r15
  __int64 v23; // r12
  __int64 v24; // r13
  __m128 v25; // xmm9
  __m128 v26; // xmm1
  __m128 v27; // xmm6
  __m128 v28; // xmm10
  __m128 v29; // xmm8
  __m128 v30; // xmm5
  __m128 v31; // xmm2
  __m128 v32; // xmm3
  float v33; // xmm4_4
  __m128 v34; // xmm5
  __m128 v35; // xmm0
  unsigned int v36; // xmm7_4
  unsigned __int64 v37; // rax
  signed __int64 v38; // r13
  signed __int64 v39; // r15
  signed __int64 v40; // r14
  __int64 v41; // r12
  __m128 v42; // xmm3
  __m128 v43; // xmm4
  __m128 v44; // xmm0
  __m128 v45; // xmm3
  __m128 v46; // xmm4
  __m128 v47; // xmm0
  __m128 v48; // xmm4
  __int64 v49; // rcx
  signed __int64 v50; // rsi
  __m128 v51; // xmm5
  __m128 v52; // xmm2
  int v53; // eax
  __m128 v54; // xmm7
  __m128 v55; // xmm3
  __m128 v56; // xmm6
  __m128 v57; // xmm4
  __m128 v58; // xmm1
  __m128 v59; // xmm5
  __m128 v60; // xmm6
  __m128 v61; // xmm6
  unsigned int v62; // xmm0_4
  __m128 v63; // xmm1
  __m128 v64; // xmm2
  __m128 v65; // xmm0
  __m128 v66; // xmm10
  __int64 v67; // r8
  char *v68; // rcx
  signed __int64 v69; // rsi
  __int128 v70; // xmm0
  __m128 v71; // xmm8
  __m128 v72; // xmm1
  __m128 v73; // xmm6
  __m128 v74; // xmm9
  __m128 v75; // xmm7
  __m128 v76; // xmm4
  __m128 v77; // xmm2
  __m128 v78; // xmm3
  float v79; // xmm5_4
  __m128 v80; // xmm4
  float v81; // xmm10_4
  __m128 v82; // xmm5
  int v83; // xmm10_4
  __m128 v84; // xmm0
  __m128 v85; // xmm1
  __m128 v86; // xmm3
  signed __int64 v87; // rsi
  __m128 v88; // xmm2
  __m128 v89; // xmm3
  int v90; // eax
  unsigned int v91; // xmm4_4
  __m128 v92; // xmm6
  __m128 v93; // xmm1
  __m128 v94; // xmm0
  __m128 v95; // xmm3
  __m128 v96; // xmm6
  __m128 v97; // xmm0
  __m128 v98; // xmm3
  __m128 v99; // xmm6
  __m128 v100; // xmm0
  __m128 v101; // xmm1
  hkQuaternionf q1; // [rsp+28h] [rbp-79h]
  hkSimdFloat32 t; // [rsp+40h] [rbp-61h]
  _BYTE *retaddr; // [rsp+F8h] [rbp+57h]
  __int64 v105; // [rsp+100h] [rbp+5Fh]
  _OWORD *v106; // [rsp+108h] [rbp+67h]
  signed int v107; // [rsp+110h] [rbp+6Fh]
  int v108; // [rsp+118h] [rbp+77h]

  v5 = weightsL;
  v6 = srcL;
  v7 = weightsOut;
  v8 = dst;
  if ( (_DWORD)srcR == 1 )
  {
    if ( v108 == -1 )
    {
      if ( v107 > 0 )
      {
        v37 = v105 - (_QWORD)weightsL;
        v38 = (char *)srcL - (char *)dst;
        v39 = retaddr - (_BYTE *)srcL;
        q1.m_vec.m_quad.m128_u64[1] = v105 - (_QWORD)weightsL;
        v40 = (char *)weightsOut - (char *)weightsL;
        v41 = (unsigned int)v107;
        do
        {
          v42 = *(__m128 *)((char *)&v6->m_vec.m_quad + v39);
          v43 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v6->m_vec.m_quad, v6->m_vec.m_quad, 201), v42),
                  _mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v6->m_vec.m_quad));
          v44 = _mm_mul_ps(_mm_shuffle_ps(v6->m_vec.m_quad, v6->m_vec.m_quad, 255), v42);
          v45 = _mm_mul_ps(v42, v6->m_vec.m_quad);
          v46 = _mm_add_ps(
                  _mm_sub_ps(_mm_shuffle_ps(v43, v43, 201), v44),
                  _mm_mul_ps(
                    _mm_shuffle_ps(
                      *(__m128 *)((char *)&v6->m_vec.m_quad + v39),
                      *(__m128 *)((char *)&v6->m_vec.m_quad + v39),
                      255),
                    v6->m_vec.m_quad));
          v47 = _mm_add_ps(_mm_shuffle_ps(v45, v45, 78), v45);
          v48 = _mm_shuffle_ps(v46, _mm_unpackhi_ps(v46, _mm_add_ps(_mm_shuffle_ps(v47, v47, 177), v47)), 196);
          v47.m128_f32[0] = COERCE_FLOAT(*v106) * *(const float *)((char *)v5 + v37);
          t.m_real = v48;
          *(const float *)((char *)v5 + v40) = *v5;
          q1.m_vec.m_quad = _mm_shuffle_ps((__m128)v47.m128_u32[0], (__m128)v47.m128_u32[0], 0);
          hkQuaternionf::setSlerp(v8, (hkQuaternionf *)((char *)v8 + v38), (hkQuaternionf *)&t, (hkSimdFloat32 *)&q1);
          v37 = q1.m_vec.m_quad.m128_u64[1];
          ++v8;
          ++v6;
          ++v5;
          --v41;
        }
        while ( v41 );
      }
    }
    else if ( v108 )
    {
      if ( v108 == 1 && v107 > 0 )
      {
        v9 = v105 - (_QWORD)weightsL;
        v10 = (char *)srcL - (char *)dst;
        v11 = retaddr - (_BYTE *)srcL;
        q1.m_vec.m_quad.m128_u64[1] = v105 - (_QWORD)weightsL;
        v12 = (char *)weightsOut - (char *)weightsL;
        v13 = (unsigned int)v107;
        do
        {
          v14 = *(__m128 *)((char *)&v6->m_vec.m_quad + v11);
          v15 = _mm_shuffle_ps(v6->m_vec.m_quad, v6->m_vec.m_quad, 255);
          v16 = _mm_shuffle_ps(
                  *(__m128 *)((char *)&v6->m_vec.m_quad + v11),
                  *(__m128 *)((char *)&v6->m_vec.m_quad + v11),
                  255);
          v17 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v6->m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v6->m_vec.m_quad, v6->m_vec.m_quad, 201), v14));
          v18 = _mm_mul_ps(v6->m_vec.m_quad, v14);
          v19 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v17, v17, 201), _mm_mul_ps(v15, v14)),
                  _mm_mul_ps(v16, v6->m_vec.m_quad));
          *(float *)&v20 = COERCE_FLOAT(*v106) * *(const float *)((char *)v5 + v9);
          q1.m_vec.m_quad = _mm_shuffle_ps(
                              v19,
                              _mm_unpackhi_ps(
                                v19,
                                _mm_sub_ps(
                                  _mm_mul_ps(v16, v15),
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                                    _mm_shuffle_ps(v18, v18, 170)))),
                              196);
          *(const float *)((char *)v5 + v12) = *v5;
          t.m_real = _mm_shuffle_ps((__m128)v20, (__m128)v20, 0);
          hkQuaternionf::setSlerp(v8, (hkQuaternionf *)((char *)v8 + v10), &q1, &t);
          v9 = q1.m_vec.m_quad.m128_u64[1];
          ++v8;
          ++v6;
          ++v5;
          --v13;
        }
        while ( v13 );
      }
    }
    else if ( v107 > 0 )
    {
      v21 = (char *)dst - (char *)srcL;
      v22 = retaddr - (_BYTE *)srcL;
      v23 = v105 - (_QWORD)weightsL;
      v24 = (unsigned int)v107;
      do
      {
        q1.m_vec.m_quad.m128_f32[0] = *(const float *)((char *)v5 + v23);
        v25 = _mm_shuffle_ps((__m128)q1.m_vec.m_quad.m128_u32[0], (__m128)q1.m_vec.m_quad.m128_u32[0], 0);
        v26 = _mm_rcp_ps(v25);
        v27 = _mm_shuffle_ps((__m128)(unsigned int)*v106, (__m128)(unsigned int)*v106, 0);
        v28 = _mm_cmpltps((__m128)0i64, v25);
        v29 = _mm_shuffle_ps((__m128)*(unsigned int *)v5, (__m128)*(unsigned int *)v5, 0);
        v30 = _mm_cmpltps(v25, v29);
        v31 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v26, v25)), v26);
        v26.m128_i32[0] = (unsigned __int128)_mm_rcp_ps(v29);
        v32 = _mm_andnot_ps(v28, aabbOut.m_quad);
        LODWORD(v33) = COERCE_UNSIGNED_INT(
                         v27.m128_f32[0]
                       * (float)((float)((float)(2.0 - (float)(v29.m128_f32[0] * v26.m128_f32[0])) * v26.m128_f32[0])
                               * v25.m128_f32[0])) & v30.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                                                v30,
                                                                                                _mm_sub_ps(
                                                                                                  query.m_quad,
                                                                                                  _mm_mul_ps(
                                                                                                    _mm_sub_ps(query.m_quad, v27),
                                                                                                    _mm_mul_ps(v31, v29))));
        v34 = _mm_cmpltps((__m128)0i64, v29);
        v35 = _mm_andnot_ps(v28, v29);
        v36 = COERCE_UNSIGNED_INT((float)((float)(1.0 - v33) * v29.m128_f32[0]) + (float)(v25.m128_f32[0] * v33)) & v28.m128_i32[0] | v35.m128_i32[0];
        v35.m128_f32[0] = COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                                                v34,
                                                                _mm_or_ps(
                                                                  _mm_and_ps(v28, query.m_quad),
                                                                  _mm_andnot_ps(v28, v27))) | (v28.m128_i32[0] & LODWORD(v33) | v32.m128_i32[0]) & v34.m128_i32[0]);
        q1.m_vec.m_quad = _mm_shuffle_ps(v35, v35, 0);
        *(_DWORD *)v7 = v36 & v34.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                         v34,
                                                                         _mm_or_ps(_mm_and_ps(v28, v25), v32));
        hkQuaternionf::setSlerp(
          (hkQuaternionf *)((char *)v6 + v21),
          v6,
          (hkQuaternionf *)((char *)v6 + v22),
          (hkSimdFloat32 *)&q1);
        ++v7;
        ++v6;
        ++v5;
        --v24;
      }
      while ( v24 );
    }
  }
  else
  {
    v49 = v107;
    if ( v108 == -1 )
    {
      if ( v107 > 0 )
      {
        v87 = (char *)v8 - (char *)srcL;
        do
        {
          v88 = v6->m_vec.m_quad;
          v89 = *(__m128 *)((char *)&v6->m_vec.m_quad + retaddr - (_BYTE *)srcL);
          v90 = *(_DWORD *)v5;
          ++v6;
          ++v5;
          *(float *)&v91 = COERCE_FLOAT(*v106) * *(const float *)((char *)v5 + v105 - (_QWORD)weightsL - 4);
          *(_DWORD *)((char *)v5 + (char *)weightsOut - (char *)weightsL - 4) = v90;
          v92 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v88, v88, 201), v89),
                  _mm_mul_ps(_mm_shuffle_ps(v89, v89, 201), v88));
          v93 = _mm_mul_ps(_mm_shuffle_ps(v89, v89, 255), v88);
          v94 = _mm_mul_ps(_mm_shuffle_ps(v88, v88, 255), v89);
          v95 = _mm_mul_ps(v89, v88);
          v96 = _mm_add_ps(_mm_sub_ps(_mm_shuffle_ps(v92, v92, 201), v94), v93);
          v97 = _mm_add_ps(_mm_shuffle_ps(v95, v95, 78), v95);
          v98 = _mm_shuffle_ps((__m128)v91, (__m128)v91, 0);
          v99 = _mm_shuffle_ps(v96, _mm_unpackhi_ps(v96, _mm_add_ps(_mm_shuffle_ps(v97, v97, 177), v97)), 196);
          v100 = _mm_mul_ps(v88, v99);
          v101 = _mm_add_ps(_mm_shuffle_ps(v100, v100, 78), v100);
          *(__m128 *)((char *)&v6[-1].m_vec.m_quad + v87) = _mm_add_ps(
                                                              _mm_mul_ps(
                                                                _mm_xor_ps(
                                                                  (__m128)_mm_slli_epi32(
                                                                            _mm_srli_epi32(
                                                                              (__m128i)_mm_cmpltps(
                                                                                         _mm_add_ps(
                                                                                           _mm_shuffle_ps(
                                                                                             v101,
                                                                                             v101,
                                                                                             177),
                                                                                           v101),
                                                                                         (__m128)0i64),
                                                                              0x1Fu),
                                                                            0x1Fu),
                                                                  _mm_sub_ps(query.m_quad, v98)),
                                                                v88),
                                                              _mm_mul_ps(v99, v98));
          --v49;
        }
        while ( v49 );
      }
    }
    else if ( v108 )
    {
      if ( v108 == 1 && v107 > 0 )
      {
        v50 = (char *)v8 - (char *)srcL;
        do
        {
          v51 = v6->m_vec.m_quad;
          v52 = *(__m128 *)((char *)&v6->m_vec.m_quad + retaddr - (_BYTE *)srcL);
          v53 = *(_DWORD *)v5;
          ++v6;
          ++v5;
          v54 = v51;
          v55 = _mm_shuffle_ps(v51, v51, 255);
          v56 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v51),
                  _mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v52));
          v57 = _mm_shuffle_ps(v52, v52, 255);
          v58 = _mm_mul_ps(v57, v51);
          v59 = _mm_mul_ps(v51, v52);
          v60 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v56, v56, 201), _mm_mul_ps(v55, v52)), v58);
          v61 = _mm_shuffle_ps(
                  v60,
                  _mm_unpackhi_ps(
                    v60,
                    _mm_sub_ps(
                      _mm_mul_ps(v57, v55),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v59, v59, 85), _mm_shuffle_ps(v59, v59, 0)),
                        _mm_shuffle_ps(v59, v59, 170)))),
                  196);
          *(float *)&v62 = COERCE_FLOAT(*v106) * *(const float *)((char *)v5 + v105 - (_QWORD)weightsL - 4);
          v63 = _mm_mul_ps(v54, v61);
          *(_DWORD *)((char *)v5 + (char *)weightsOut - (char *)weightsL - 4) = v53;
          v64 = _mm_shuffle_ps((__m128)v62, (__m128)v62, 0);
          v65 = _mm_add_ps(_mm_shuffle_ps(v63, v63, 78), v63);
          *(__m128 *)((char *)&v6[-1].m_vec.m_quad + v50) = _mm_add_ps(
                                                              _mm_mul_ps(
                                                                _mm_xor_ps(
                                                                  (__m128)_mm_slli_epi32(
                                                                            _mm_srli_epi32(
                                                                              (__m128i)_mm_cmpltps(
                                                                                         _mm_add_ps(
                                                                                           _mm_shuffle_ps(v65, v65, 177),
                                                                                           v65),
                                                                                         (__m128)0i64),
                                                                              0x1Fu),
                                                                            0x1Fu),
                                                                  _mm_sub_ps(query.m_quad, v64)),
                                                                v54),
                                                              _mm_mul_ps(v61, v64));
          --v49;
        }
        while ( v49 );
      }
    }
    else if ( v107 > 0 )
    {
      v66 = query.m_quad;
      v67 = (unsigned int)v107;
      v68 = (char *)(retaddr - (_BYTE *)v6);
      v69 = (char *)v8 - (char *)v6;
      do
      {
        v70 = *v106;
        q1.m_vec.m_quad.m128_f32[2] = *(const float *)((char *)v5 + v105 - (_QWORD)weightsL);
        q1.m_vec.m_quad.m128_i32[0] = v70;
        v71 = _mm_shuffle_ps((__m128)q1.m_vec.m_quad.m128_u32[2], (__m128)q1.m_vec.m_quad.m128_u32[2], 0);
        v72 = _mm_rcp_ps(v71);
        v73 = _mm_shuffle_ps((__m128)q1.m_vec.m_quad.m128_u32[0], (__m128)q1.m_vec.m_quad.m128_u32[0], 0);
        v74 = _mm_cmpltps((__m128)0i64, v71);
        v75 = _mm_shuffle_ps((__m128)*(unsigned int *)v5, (__m128)*(unsigned int *)v5, 0);
        v76 = _mm_cmpltps(v71, v75);
        v77 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v72, v71)), v72);
        v72.m128_i32[0] = (unsigned __int128)_mm_rcp_ps(v75);
        v78 = _mm_andnot_ps(v74, aabbOut.m_quad);
        LODWORD(v79) = COERCE_UNSIGNED_INT(
                         (float)((float)((float)(2.0 - (float)(v72.m128_f32[0] * v75.m128_f32[0])) * v72.m128_f32[0])
                               * v71.m128_f32[0])
                       * v73.m128_f32[0]) & v76.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                                       v76,
                                                                                       _mm_sub_ps(
                                                                                         v66,
                                                                                         _mm_mul_ps(
                                                                                           _mm_sub_ps(v66, v73),
                                                                                           _mm_mul_ps(v77, v75))));
        v80 = _mm_cmpltps((__m128)0i64, v75);
        v77.m128_i32[0] = (unsigned __int128)_mm_andnot_ps(
                                               v80,
                                               _mm_or_ps(_mm_andnot_ps(v74, v73), _mm_and_ps(v74, v66)));
        LODWORD(v70) = v74.m128_i32[0] & LODWORD(v79) | v78.m128_i32[0];
        v81 = (float)((float)(v66.m128_f32[0] - v79) * v75.m128_f32[0]) + (float)(v79 * v71.m128_f32[0]);
        v82 = *(__m128 *)&v68[(_QWORD)v6];
        q1.m_vec.m_quad.m128_i32[2] = v77.m128_i32[0] | v70 & v80.m128_i32[0];
        v83 = (LODWORD(v81) & v74.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(v74, v75)) & v80.m128_i32[0];
        v84 = _mm_mul_ps(v82, v6->m_vec.m_quad);
        v80.m128_i32[0] = (unsigned __int128)_mm_andnot_ps(v80, _mm_or_ps(_mm_and_ps(v74, v71), v78));
        v85 = _mm_add_ps(_mm_shuffle_ps(v84, v84, 78), v84);
        v86 = _mm_shuffle_ps((__m128)q1.m_vec.m_quad.m128_u32[2], (__m128)q1.m_vec.m_quad.m128_u32[2], 0);
        *(_DWORD *)v7 = v83 | v80.m128_i32[0];
        v66 = query.m_quad;
        ++v6;
        ++v7;
        ++v5;
        *(__m128 *)((char *)&v6[-1].m_vec.m_quad + v69) = _mm_add_ps(
                                                            _mm_mul_ps(
                                                              _mm_xor_ps(
                                                                (__m128)_mm_slli_epi32(
                                                                          _mm_srli_epi32(
                                                                            (__m128i)_mm_cmpltps(
                                                                                       _mm_add_ps(
                                                                                         _mm_shuffle_ps(v85, v85, 177),
                                                                                         v85),
                                                                                       (__m128)0i64),
                                                                            0x1Fu),
                                                                          0x1Fu),
                                                                _mm_sub_ps(query.m_quad, v86)),
                                                              v6[-1].m_vec.m_quad),
                                                            _mm_mul_ps(v82, v86));
        --v67;
      }
      while ( v67 );
    }
  }
}              0x1Fu),
                                                                          0x1Fu),
                                                                _mm_sub_ps(query.m_quad, v86)),
                                                              v6[-1].m_vec.m_quad),
                                      

// File Line: 439
// RVA: 0xB41600
void __fastcall hkaBlender::blend(hkQsTransformf *dst, float *weightsOut, hkQsTransformf *srcL, const float *weightsL, hkQsTransformf *srcR, const float *weightsR, hkSimdFloat32 *alphaIn, int n, hkaBlender::BLEND_MODE blendMode, hkaBlender::ROTATION_MODE rotationMode)
{
  float *v10; // rdi
  hkQsTransformf *v11; // rsi
  signed __int64 v12; // rsi
  signed __int64 v13; // r14
  signed __int64 v14; // r15
  hkQuaternionf *v15; // rbx
  __int64 v16; // r12
  __int64 v17; // r13
  __m128 v18; // xmm3
  __m128 v19; // xmm6
  __m128 v20; // xmm1
  __m128 v21; // xmm4
  __m128 v22; // xmm7
  __m128 v23; // xmm8
  __m128 v24; // xmm4
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  __m128 v27; // xmm8
  __m128 v28; // xmm5
  __m128 v29; // xmm0
  __m128 v30; // xmm3
  __m128 v31; // xmm4
  __m128 v32; // xmm3
  __m128 v33; // xmm5
  __m128 v34; // xmm3
  __m128 v35; // xmm0
  signed __int64 v36; // rsi
  signed __int64 v37; // r14
  signed __int64 v38; // r15
  signed __int64 v39; // r12
  hkVector4f *v40; // rbx
  __int64 v41; // r13
  __m128 v42; // xmm10
  __m128 v43; // xmm1
  __m128 v44; // xmm6
  __m128 v45; // xmm8
  __m128 v46; // xmm9
  __m128 v47; // xmm4
  __m128 v48; // xmm2
  __m128 v49; // xmm1
  __m128 v50; // xmm3
  __m128 v51; // xmm5
  __m128 v52; // xmm4
  __m128 v53; // xmm2
  __m128 v54; // xmm2
  __m128 v55; // xmm1
  bool v56; // zf
  signed __int64 v57; // r14
  __m128i v58; // xmm0
  signed __int64 v59; // rsi
  __int64 v60; // r13
  hkQuaternionf *v61; // r15
  signed __int64 v62; // r12
  __m128 v63; // xmm10
  __m128 v64; // xmm11
  char *v65; // rbx
  __m128 v66; // xmm2
  __m128 v67; // xmm0
  __m128 v68; // xmm1
  __m128 v69; // xmm4
  __m128 v70; // xmm5
  __m128 v71; // xmm8
  __m128 v72; // xmm9
  __m128 v73; // xmm1
  __m128 v74; // xmm3
  __m128 v75; // xmm6
  __m128 v76; // xmm7
  __m128 v77; // xmm3
  __m128 v78; // xmm7
  __m128 v79; // xmm4
  __m128 v80; // xmm0
  __m128 v81; // xmm8
  __m128 v82; // xmm4
  hkQuaternionf *v83; // rcx
  signed __int64 v84; // rdx
  signed __int64 v85; // rsi
  char *v86; // r14
  __int64 v87; // r9
  __int64 v88; // r8
  __m128 v89; // xmm10
  __m128 v90; // xmm2
  __m128 v91; // xmm7
  __m128 v92; // xmm1
  __m128 v93; // xmm5
  __m128 v94; // xmm3
  __m128 v95; // xmm0
  __m128 v96; // xmm2
  __m128 v97; // xmm9
  __m128 v98; // xmm4
  __m128 v99; // xmm1
  __m128 v100; // xmm3
  __m128 v101; // xmm4
  __m128 v102; // xmm8
  __m128 v103; // xmm0
  __m128 v104; // xmm5
  __m128 v105; // xmm6
  __m128 v106; // xmm8
  __m128 v107; // xmm8
  __m128 v108; // xmm4
  __m128 v109; // xmm0
  __m128 v110; // xmm3
  __m128 v111; // xmm1
  __m128 v112; // xmm10
  signed __int64 v113; // r14
  signed __int64 v114; // rsi
  signed __int64 v115; // rcx
  __m128 *v116; // rax
  __int64 v117; // r8
  __int64 v118; // rdx
  __int128 v119; // xmm0
  __m128 v120; // xmm8
  __m128 v121; // xmm1
  __m128 v122; // xmm6
  __m128 v123; // xmm9
  __m128 v124; // xmm7
  __m128 v125; // xmm4
  __m128 v126; // xmm2
  __m128 v127; // xmm3
  float v128; // xmm5_4
  __m128 v129; // xmm4
  __m128 v130; // xmm6
  __m128 v131; // xmm0
  __m128 v132; // xmm3
  __m128 v133; // xmm1
  __m128 v134; // xmm0
  __m128 v135; // xmm3
  __m128 v136; // xmm2
  unsigned __int64 v137; // r15
  __m128i v138; // xmm0
  signed __int64 v139; // r14
  signed __int64 v140; // rsi
  __int64 v141; // r12
  hkQuaternionf *v142; // r13
  __m128 v143; // xmm11
  __m128 v144; // xmm12
  unsigned __int64 v145; // r15
  char *v146; // rbx
  __m128 v147; // xmm9
  __m128 v148; // xmm0
  __m128 v149; // xmm1
  __m128 v150; // xmm3
  __m128 v151; // xmm6
  __m128 v152; // xmm5
  __m128 v153; // xmm10
  __m128 v154; // xmm1
  __m128 v155; // xmm2
  __m128 v156; // xmm4
  __m128 v157; // xmm0
  __m128 v158; // xmm3
  __m128 v159; // xmm8
  __m128 v160; // xmm7
  __m128 v161; // xmm0
  __m128 v162; // xmm5
  __m128 v163; // xmm7
  __m128 v164; // xmm1
  __m128 v165; // xmm5
  __m128 v166; // xmm7
  __m128 v167; // xmm4
  __m128 v168; // xmm0
  __m128 v169; // xmm4
  __m128 v170; // xmm3
  __m128 v171; // xmm1
  hkSimdFloat32 t; // [rsp+20h] [rbp-B8h]
  __m128 v173; // [rsp+30h] [rbp-A8h]
  hkQuaternionf q1; // [rsp+40h] [rbp-98h]
  __m128 v175; // [rsp+50h] [rbp-88h]
  hkVector4f v176; // [rsp+60h] [rbp-78h]
  __int64 v177; // [rsp+128h] [rbp+50h]
  unsigned __int64 retaddr; // [rsp+148h] [rbp+70h]
  __int64 v179; // [rsp+150h] [rbp+78h]
  _OWORD *v180; // [rsp+158h] [rbp+80h]
  unsigned int v181; // [rsp+160h] [rbp+88h]
  int v182; // [rsp+168h] [rbp+90h]
  unsigned int srcRa; // [rsp+170h] [rbp+98h]
  unsigned int srcRb; // [rsp+170h] [rbp+98h]

  v10 = weightsOut;
  v11 = dst;
  if ( (_DWORD)srcR == 1 )
  {
    if ( v182 == -1 )
    {
      if ( (signed int)v181 > 0 )
      {
        v57 = (char *)weightsL - (char *)weightsOut;
        v58 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
        v59 = (signed __int64)dst - retaddr;
        v60 = v179 - (_QWORD)weightsOut;
        v61 = &srcL->m_rotation;
        v62 = retaddr - (_QWORD)srcL;
        retaddr = v181;
        v63 = (__m128)_mm_shuffle_epi32(v58, 0);
        v64 = (__m128)_mm_shuffle_epi32(v58, 64);
        do
        {
          v65 = (char *)v61 + v62;
          hkVector4f::setRotatedInverseDir(
            &v176,
            (hkQuaternionf *)((char *)v61 + v62),
            (hkVector4f *)((char *)&v61[-1].m_vec + v62));
          v66 = v61->m_vec.m_quad;
          v67 = *(__m128 *)((char *)&v61[1].m_vec.m_quad + v62);
          v68 = _mm_rcp_ps(v67);
          v69 = _mm_xor_ps(v176.m_quad, v63);
          v70 = v61[-1].m_vec.m_quad;
          v71 = _mm_xor_ps(v64, *(__m128 *)((char *)&v61->m_vec.m_quad + v62));
          v72 = _mm_mul_ps(
                  (__m128)_mm_srli_si128(
                            _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v67, v68)), v68), 4),
                            4),
                  v61[1].m_vec.m_quad);
          v73 = _mm_mul_ps(v69, v61->m_vec.m_quad);
          v74 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v69, v69, 201), v61->m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v66, v66, 201), v69));
          v75 = _mm_shuffle_ps(v61->m_vec.m_quad, v61->m_vec.m_quad, 255);
          v76 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
                        _mm_shuffle_ps(v73, v73, 170)),
                      v61->m_vec.m_quad),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v75, v75), (__m128)xmmword_141A711B0), v69)),
                  _mm_mul_ps(_mm_shuffle_ps(v74, v74, 201), v75));
          v77 = _mm_shuffle_ps(v71, v71, 255);
          v78 = _mm_add_ps(_mm_add_ps(v76, v76), v70);
          v79 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v71, v71, 201), v61->m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v61->m_vec.m_quad, v61->m_vec.m_quad, 201), v71));
          v173 = v78;
          v80 = _mm_mul_ps(v71, v75);
          v81 = _mm_mul_ps(v71, v66);
          v82 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v79, v79, 201), v80), _mm_mul_ps(v77, v66));
          q1.m_vec.m_quad = _mm_shuffle_ps(
                              v82,
                              _mm_unpackhi_ps(
                                v82,
                                _mm_sub_ps(
                                  _mm_mul_ps(v77, v75),
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v81, v81, 85), _mm_shuffle_ps(v81, v81, 0)),
                                    _mm_shuffle_ps(v81, v81, 170)))),
                              196);
          v175 = v72;
          v80.m128_f32[0] = COERCE_FLOAT(*v180) * *(float *)((char *)v10 + v60);
          *v10 = *(float *)((char *)v10 + v57);
          t.m_real = _mm_shuffle_ps((__m128)v80.m128_u32[0], (__m128)v80.m128_u32[0], 0);
          *(__m128 *)&v65[v59 - 16] = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v78, v70), t.m_real), v70);
          hkQuaternionf::setSlerp((hkQuaternionf *)((char *)v61 + v62 + v59), v61, &q1, &t);
          v61 += 3;
          ++v10;
          v56 = retaddr-- == 1;
          *(__m128 *)&v65[v59 + 16] = _mm_add_ps(
                                        _mm_mul_ps(_mm_sub_ps(v175, v61[-2].m_vec.m_quad), t.m_real),
                                        v61[-2].m_vec.m_quad);
        }
        while ( !v56 );
      }
    }
    else if ( v182 )
    {
      if ( v182 == 1 && (signed int)v181 > 0 )
      {
        v12 = (char *)dst - (char *)srcL;
        v13 = (char *)weightsL - (char *)weightsOut;
        v14 = retaddr - (_QWORD)srcL;
        v15 = &srcL->m_rotation;
        v16 = v179 - (_QWORD)weightsOut;
        v17 = v181;
        do
        {
          v18 = *(__m128 *)((char *)&v15[-1].m_vec.m_quad + v14);
          v19 = v15[-1].m_vec.m_quad;
          v20 = _mm_mul_ps(*(__m128 *)((char *)&v15[-1].m_vec.m_quad + v14), v15->m_vec.m_quad);
          v21 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v15->m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v15->m_vec.m_quad, v15->m_vec.m_quad, 201), v18));
          v22 = _mm_shuffle_ps(v15->m_vec.m_quad, v15->m_vec.m_quad, 255);
          v23 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                        _mm_shuffle_ps(v20, v20, 170)),
                      v15->m_vec.m_quad),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v22, v22), (__m128)xmmword_141A711B0), v18)),
                  _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v22));
          v24 = v15->m_vec.m_quad;
          v25 = *(__m128 *)((char *)&v15->m_vec.m_quad + v14);
          v26 = v15->m_vec.m_quad;
          v27 = _mm_add_ps(_mm_add_ps(v23, v23), v19);
          v28 = *(__m128 *)((char *)&v15->m_vec.m_quad + v14);
          v173 = v27;
          v29 = _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v25);
          v30 = _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v24);
          v31 = _mm_mul_ps(v24, v25);
          v32 = _mm_sub_ps(v30, v29);
          v33 = _mm_shuffle_ps(v28, v28, 255);
          v34 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v32, v32, 201), _mm_mul_ps(v25, v22)), _mm_mul_ps(v26, v33));
          v35 = _mm_mul_ps(*(__m128 *)((char *)&v15[1].m_vec.m_quad + v14), v15[1].m_vec.m_quad);
          q1.m_vec.m_quad = _mm_shuffle_ps(
                              v34,
                              _mm_unpackhi_ps(
                                v34,
                                _mm_sub_ps(
                                  _mm_mul_ps(v33, v22),
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                                    _mm_shuffle_ps(v31, v31, 170)))),
                              196);
          v175 = v35;
          v35.m128_f32[0] = COERCE_FLOAT(*v180) * *(float *)((char *)v10 + v16);
          *v10 = *(float *)((char *)v10 + v13);
          t.m_real = _mm_shuffle_ps((__m128)v35.m128_u32[0], (__m128)v35.m128_u32[0], 0);
          *(__m128 *)((char *)&v15[-1].m_vec.m_quad + v12) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v27, v19), t.m_real), v19);
          hkQuaternionf::setSlerp((hkQuaternionf *)((char *)v15 + v12), v15, &q1, &t);
          v15 += 3;
          ++v10;
          *(__m128 *)((char *)&v15[-2].m_vec.m_quad + v12) = _mm_add_ps(
                                                               _mm_mul_ps(
                                                                 _mm_sub_ps(v175, v15[-2].m_vec.m_quad),
                                                                 t.m_real),
                                                               v15[-2].m_vec.m_quad);
          --v17;
        }
        while ( v17 );
      }
    }
    else if ( (signed int)v181 > 0 )
    {
      v36 = (char *)dst - (char *)srcL;
      v37 = (char *)weightsL - (char *)weightsOut;
      v38 = retaddr - (_QWORD)srcL;
      v39 = (char *)srcL - (char *)dst;
      v40 = &srcL->m_scale;
      v41 = v179 - (_QWORD)weightsOut;
      v177 = v181;
      do
      {
        v42 = _mm_shuffle_ps(
                (__m128)*(unsigned int *)((char *)v10 + v41),
                (__m128)*(unsigned int *)((char *)v10 + v41),
                0);
        v43 = _mm_rcp_ps(v42);
        v44 = _mm_shuffle_ps((__m128)(unsigned int)*v180, (__m128)(unsigned int)*v180, 0);
        v45 = _mm_cmpltps((__m128)0i64, v42);
        v46 = _mm_shuffle_ps(
                (__m128)*(unsigned int *)((char *)v10 + v37),
                (__m128)*(unsigned int *)((char *)v10 + v37),
                0);
        v47 = _mm_cmpltps(v42, v46);
        v48 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v42, v43)), v43);
        v49 = _mm_rcp_ps(v46);
        v50 = _mm_andnot_ps(v45, aabbOut.m_quad);
        v51 = _mm_or_ps(
                _mm_and_ps(
                  _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v46, v49)), v49), v42), v44),
                  v47),
                _mm_andnot_ps(
                  v47,
                  _mm_sub_ps(query.m_quad, _mm_mul_ps(_mm_sub_ps(query.m_quad, v44), _mm_mul_ps(v48, v46)))));
        v52 = _mm_cmpltps((__m128)0i64, v46);
        v53 = _mm_or_ps(
                _mm_andnot_ps(v52, _mm_or_ps(_mm_andnot_ps(v45, v44), _mm_and_ps(v45, query.m_quad))),
                _mm_and_ps(_mm_or_ps(_mm_and_ps(v51, v45), v50), v52));
        v54 = _mm_shuffle_ps(v53, v53, 0);
        v55 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)&v40[-2].m_quad + v38), v40[-2].m_quad), v54);
        t.m_real = v54;
        *(__m128 *)((char *)&v40[-2].m_quad + v36) = _mm_add_ps(v55, v40[-2].m_quad);
        *(_DWORD *)v10 = (COERCE_UNSIGNED_INT(
                            (float)((float)(1.0 - v51.m128_f32[0]) * v46.m128_f32[0])
                          + (float)(v51.m128_f32[0] * v42.m128_f32[0])) & v45.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(v45, v46)) & v52.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(v52, _mm_or_ps(_mm_and_ps(v42, v45), v50));
        hkQuaternionf::setSlerp(
          (hkQuaternionf *)((char *)&v40[-1] + v36),
          (hkQuaternionf *)((char *)&v40[-1] + v36 + v39),
          (hkQuaternionf *)((char *)&v40[-1] + v38),
          &t);
        v40 += 3;
        ++v10;
        v56 = v177-- == 1;
        *(__m128 *)((char *)&v40[-3].m_quad + v36) = _mm_add_ps(
                                                       _mm_mul_ps(
                                                         _mm_sub_ps(
                                                           *(__m128 *)((char *)&v40[-3].m_quad + v38),
                                                           v40[-3].m_quad),
                                                         t.m_real),
                                                       v40[-3].m_quad);
      }
      while ( !v56 );
    }
  }
  else if ( v182 == -1 )
  {
    if ( (signed int)v181 > 0 )
    {
      v137 = retaddr;
      v138 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
      v139 = (char *)weightsL - (char *)weightsOut;
      v140 = (signed __int64)dst - retaddr;
      v141 = v179 - (_QWORD)weightsOut;
      v142 = &srcL->m_rotation;
      retaddr = v181;
      v143 = (__m128)_mm_shuffle_epi32(v138, 0);
      v144 = (__m128)_mm_shuffle_epi32(v138, 64);
      v145 = v137 - (_QWORD)srcL;
      do
      {
        v146 = (char *)v142 + v145;
        hkVector4f::setRotatedInverseDir(
          &v176,
          (hkQuaternionf *)((char *)v142 + v145),
          (hkVector4f *)((char *)&v142[-1].m_vec + v145));
        v147 = v142->m_vec.m_quad;
        v148 = *(__m128 *)((char *)&v142[1].m_vec.m_quad + v145);
        v149 = _mm_rcp_ps(v148);
        v150 = _mm_xor_ps(v176.m_quad, v143);
        v151 = v142[-1].m_vec.m_quad;
        v152 = _mm_xor_ps(v144, *(__m128 *)((char *)&v142->m_vec.m_quad + v145));
        v153 = (__m128)_mm_srli_si128(
                         _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v148, v149)), v149), 4),
                         4);
        v154 = _mm_mul_ps(v150, v142->m_vec.m_quad);
        v155 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v150, v150, 201), v142->m_vec.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(v147, v147, 201), v150));
        v156 = _mm_shuffle_ps(v142->m_vec.m_quad, v142->m_vec.m_quad, 255);
        v157 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v156, v156), (__m128)xmmword_141A711B0), v150);
        v158 = _mm_shuffle_ps(v152, v152, 255);
        v159 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v154, v154, 85), _mm_shuffle_ps(v154, v154, 0)),
                       _mm_shuffle_ps(v154, v154, 170)),
                     v142->m_vec.m_quad),
                   v157),
                 _mm_mul_ps(_mm_shuffle_ps(v155, v155, 201), v156));
        v160 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v152, v152, 201), v142->m_vec.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(v142->m_vec.m_quad, v142->m_vec.m_quad, 201), v152));
        v161 = v152;
        v162 = _mm_mul_ps(v152, v142->m_vec.m_quad);
        v163 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v160, v160, 201), _mm_mul_ps(v161, v156)),
                 _mm_mul_ps(v142->m_vec.m_quad, v158));
        v164 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v162, v162, 85), _mm_shuffle_ps(v162, v162, 0)),
                 _mm_shuffle_ps(v162, v162, 170));
        v165 = v142[1].m_vec.m_quad;
        v166 = _mm_shuffle_ps(v163, _mm_unpackhi_ps(v163, _mm_sub_ps(_mm_mul_ps(v158, v156), v164)), 196);
        v142 += 3;
        ++v10;
        v56 = retaddr-- == 1;
        v161.m128_f32[0] = COERCE_FLOAT(*v180) * *(float *)((char *)v10 + v141 - 4);
        *(v10 - 1) = *(float *)((char *)v10 + v139 - 4);
        v167 = (__m128)v161.m128_u32[0];
        srcRb = v161.m128_i32[0];
        v168 = _mm_mul_ps(v166, v147);
        v169 = _mm_shuffle_ps(v167, v167, 0);
        v170 = _mm_shuffle_ps((__m128)srcRb, (__m128)srcRb, 0);
        v171 = _mm_add_ps(_mm_shuffle_ps(v168, v168, 78), v168);
        *(__m128 *)&v146[v140 - 16] = _mm_add_ps(
                                        _mm_mul_ps(_mm_sub_ps(_mm_add_ps(_mm_add_ps(v159, v159), v151), v151), v169),
                                        v151);
        *(__m128 *)&v146[v140 + 16] = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v153, v165), v165), v169), v165);
        *(__m128 *)&v146[v140] = _mm_add_ps(
                                   _mm_mul_ps(
                                     _mm_xor_ps(
                                       (__m128)_mm_slli_epi32(
                                                 _mm_srli_epi32(
                                                   (__m128i)_mm_cmpltps(
                                                              _mm_add_ps(_mm_shuffle_ps(v171, v171, 177), v171),
                                                              (__m128)0i64),
                                                   0x1Fu),
                                                 0x1Fu),
                                       _mm_sub_ps(query.m_quad, v170)),
                                     v147),
                                   _mm_mul_ps(v166, v170));
      }
      while ( !v56 );
    }
  }
  else if ( v182 )
  {
    if ( v182 == 1 && (signed int)v181 > 0 )
    {
      v83 = &srcL->m_rotation;
      v84 = retaddr - (_QWORD)srcL;
      v85 = (char *)v11 - (char *)srcL;
      v86 = (char *)((char *)weightsL - (char *)v10);
      v87 = v181;
      v88 = v179 - (_QWORD)v10;
      do
      {
        v89 = v83->m_vec.m_quad;
        v90 = *(__m128 *)((char *)&v83[-1].m_vec.m_quad + v84);
        v91 = v83[-1].m_vec.m_quad;
        v92 = _mm_mul_ps(*(__m128 *)((char *)&v83[-1].m_vec.m_quad + v84), v83->m_vec.m_quad);
        v93 = _mm_shuffle_ps(v83->m_vec.m_quad, v83->m_vec.m_quad, 255);
        v94 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v90, v90, 201), v83->m_vec.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v89, v89, 201), v90));
        v95 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v93, v93), (__m128)xmmword_141A711B0), v90);
        v96 = *(__m128 *)((char *)&v83->m_vec.m_quad + v84);
        v97 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v92, v92, 85), _mm_shuffle_ps(v92, v92, 0)),
                      _mm_shuffle_ps(v92, v92, 170)),
                    v83->m_vec.m_quad),
                  v95),
                _mm_mul_ps(_mm_shuffle_ps(v94, v94, 201), v93));
        v98 = _mm_shuffle_ps(
                *(__m128 *)((char *)&v83->m_vec.m_quad + v84),
                *(__m128 *)((char *)&v83->m_vec.m_quad + v84),
                255);
        v99 = _mm_mul_ps(v83->m_vec.m_quad, v98);
        v100 = _mm_mul_ps(v83->m_vec.m_quad, v96);
        v101 = _mm_mul_ps(v98, v93);
        v102 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v96, v96, 201), v83->m_vec.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(v83->m_vec.m_quad, v83->m_vec.m_quad, 201), v96));
        v103 = _mm_mul_ps(*(__m128 *)((char *)&v83->m_vec.m_quad + v84), v93);
        v104 = v83[1].m_vec.m_quad;
        v105 = _mm_mul_ps(*(__m128 *)((char *)&v83[1].m_vec.m_quad + v84), v104);
        v106 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v102, v102, 201), v103), v99);
        v107 = _mm_shuffle_ps(
                 v106,
                 _mm_unpackhi_ps(
                   v106,
                   _mm_sub_ps(
                     v101,
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v100, v100, 85), _mm_shuffle_ps(v100, v100, 0)),
                       _mm_shuffle_ps(v100, v100, 170)))),
                 196);
        v103.m128_f32[0] = COERCE_FLOAT(*v180) * *(float *)((char *)v10 + v88);
        *v10 = *(float *)&v86[(_QWORD)v10];
        srcRa = v103.m128_i32[0];
        v108 = _mm_shuffle_ps((__m128)v103.m128_u32[0], (__m128)v103.m128_u32[0], 0);
        v109 = _mm_mul_ps(v89, v107);
        *(__m128 *)((char *)&v83[-1].m_vec.m_quad + v85) = _mm_add_ps(
                                                             _mm_mul_ps(
                                                               _mm_sub_ps(_mm_add_ps(_mm_add_ps(v97, v97), v91), v91),
                                                               v108),
                                                             v91);
        v110 = _mm_shuffle_ps((__m128)srcRa, (__m128)srcRa, 0);
        v83 += 3;
        ++v10;
        v111 = _mm_add_ps(_mm_shuffle_ps(v109, v109, 78), v109);
        *(__m128 *)((char *)&v83[-2].m_vec.m_quad + v85) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v105, v104), v108), v104);
        *(__m128 *)((char *)&v83[-3].m_vec.m_quad + v85) = _mm_add_ps(
                                                             _mm_mul_ps(
                                                               _mm_xor_ps(
                                                                 (__m128)_mm_slli_epi32(
                                                                           _mm_srli_epi32(
                                                                             (__m128i)_mm_cmpltps(
                                                                                        _mm_add_ps(
                                                                                          _mm_shuffle_ps(
                                                                                            v111,
                                                                                            v111,
                                                                                            177),
                                                                                          v111),
                                                                                        (__m128)0i64),
                                                                             0x1Fu),
                                                                           0x1Fu),
                                                                 _mm_sub_ps(query.m_quad, v110)),
                                                               v89),
                                                             _mm_mul_ps(v107, v110));
        --v87;
      }
      while ( v87 );
    }
  }
  else if ( (signed int)v181 > 0 )
  {
    v112 = query.m_quad;
    v113 = (char *)weightsL - (char *)weightsOut;
    v114 = (char *)dst - (char *)srcL;
    v115 = retaddr - (_QWORD)srcL;
    v116 = &srcL->m_rotation.m_vec.m_quad;
    v117 = v181;
    v118 = v179 - (_QWORD)weightsOut;
    do
    {
      v119 = *v180;
      *(float *)&v177 = *(float *)((char *)v10 + v118);
      v120 = _mm_shuffle_ps((__m128)(unsigned int)v177, (__m128)(unsigned int)v177, 0);
      v121 = _mm_rcp_ps(v120);
      v122 = _mm_shuffle_ps((__m128)(unsigned int)v119, (__m128)(unsigned int)v119, 0);
      v123 = _mm_cmpltps((__m128)0i64, v120);
      v124 = _mm_shuffle_ps(
               (__m128)*(unsigned int *)((char *)v10 + v113),
               (__m128)*(unsigned int *)((char *)v10 + v113),
               0);
      v125 = _mm_cmpltps(v120, v124);
      v126 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v121, v120)), v121);
      v121.m128_i32[0] = (unsigned __int128)_mm_rcp_ps(v124);
      v127 = _mm_andnot_ps(v123, aabbOut.m_quad);
      LODWORD(v128) = COERCE_UNSIGNED_INT(
                        (float)((float)((float)(2.0 - (float)(v121.m128_f32[0] * v124.m128_f32[0])) * v121.m128_f32[0])
                              * v120.m128_f32[0])
                      * v122.m128_f32[0]) & v125.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                                        v125,
                                                                                        _mm_sub_ps(
                                                                                          v112,
                                                                                          _mm_mul_ps(
                                                                                            _mm_sub_ps(v112, v122),
                                                                                            _mm_mul_ps(v126, v124))));
      v129 = _mm_cmpltps((__m128)0i64, v124);
      v126.m128_i32[0] = *(unsigned __int128 *)&_mm_andnot_ps(
                                                  v129,
                                                  _mm_or_ps(_mm_and_ps(v123, v112), _mm_andnot_ps(v123, v122))) | (v123.m128_i32[0] & LODWORD(v128) | v127.m128_i32[0]) & v129.m128_i32[0];
      v122.m128_f32[0] = v126.m128_f32[0];
      v130 = _mm_shuffle_ps(v122, v122, 0);
      LODWORD(retaddr) = v126.m128_i32[0];
      v131 = _mm_mul_ps(*(__m128 *)((char *)v116 + v115), *v116);
      *(__m128 *)((char *)v116 + v114 - 16) = _mm_add_ps(
                                                _mm_mul_ps(
                                                  _mm_sub_ps(*(__m128 *)((char *)v116 + v115 - 16), v116[-1]),
                                                  v130),
                                                v116[-1]);
      *(_DWORD *)v10 = (COERCE_UNSIGNED_INT(
                          (float)((float)(v112.m128_f32[0] - v128) * v124.m128_f32[0])
                        + (float)(v128 * v120.m128_f32[0])) & v123.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(v123, v124)) & v129.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(v129, _mm_or_ps(_mm_and_ps(v123, v120), v127));
      v112 = query.m_quad;
      v116 += 3;
      ++v10;
      v132 = _mm_shuffle_ps((__m128)v126.m128_u32[0], (__m128)v126.m128_u32[0], 0);
      v133 = _mm_add_ps(_mm_shuffle_ps(v131, v131, 78), v131);
      v134 = _mm_sub_ps(query.m_quad, v132);
      v135 = _mm_mul_ps(v132, *(__m128 *)((char *)v116 + v115 - 48));
      v136 = _mm_mul_ps(
               _mm_xor_ps(
                 (__m128)_mm_slli_epi32(
                           _mm_srli_epi32(
                             (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v133, v133, 177), v133), (__m128)0i64),
                             0x1Fu),
                           0x1Fu),
                 v134),
               v116[-3]);
      *(__m128 *)((char *)v116 + v114 - 32) = _mm_add_ps(
                                                _mm_mul_ps(
                                                  _mm_sub_ps(*(__m128 *)((char *)v116 + v115 - 32), v116[-2]),
                                                  v130),
                                                v116[-2]);
      *(__m128 *)((char *)v116 + v114 - 48) = _mm_add_ps(v136, v135);
      --v117;
    }
    while ( v117 );
  }
}

// File Line: 541
// RVA: 0xB422D0
void __fastcall hkaBlender::mul(float *dst, const float *srcL, const float *srcR, int n)
{
  int v4; // er11
  const float *v5; // rbx
  float *v6; // r10
  __int64 v7; // rcx
  const float *v8; // rax
  unsigned __int64 v9; // r8
  int v10; // eax
  __int64 v11; // rdi
  __int64 v12; // rcx
  char *v13; // r8
  unsigned __int64 v14; // r11
  signed __int64 v15; // r9
  signed __int64 v16; // rax
  signed __int64 v17; // r11
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  char *v23; // rdx
  signed __int64 v24; // r10
  signed __int64 v25; // rax
  __int64 v26; // rcx
  float v27; // xmm0_4

  v4 = 0;
  v5 = srcR;
  v6 = dst;
  if ( n > 0 && (unsigned int)n >= 8 )
  {
    v7 = n - 1;
    v8 = &srcR[v7];
    v9 = (unsigned __int64)&v6[v7];
    if ( (v6 > v8 || v9 < (unsigned __int64)v5) && (v6 > &srcL[v7] || v9 < (unsigned __int64)srcL) )
    {
      do
      {
        *(__m128 *)&v6[v4] = _mm_mul_ps(*(__m128 *)&srcL[v4], *(__m128 *)&v5[v4]);
        v10 = v4 + 4;
        v4 += 8;
        *(__m128 *)&v6[v10] = _mm_mul_ps(*(__m128 *)&srcL[v10], *(__m128 *)&v5[v10]);
      }
      while ( v4 < n - n % 8 );
    }
  }
  v11 = v4;
  v12 = n;
  if ( v4 < (signed __int64)n )
  {
    if ( n - (signed __int64)v4 >= 4 )
    {
      v13 = (char *)((char *)srcL - (char *)v5);
      v14 = n - (signed __int64)v4 - 4;
      v15 = (char *)v6 - (char *)v5;
      v16 = (signed __int64)&v5[v11 + 1];
      v17 = (v14 >> 2) + 1;
      v11 += 4 * v17;
      do
      {
        v18 = *(float *)&v13[v16 - 4];
        v19 = *(float *)&v13[v16];
        v16 += 16i64;
        v20 = v19 * *(float *)(v16 - 16);
        *(float *)(v15 + v16 - 20) = v18 * *(float *)(v16 - 20);
        v21 = *(float *)&v13[v16 - 12];
        *(float *)(v15 + v16 - 16) = v20;
        v22 = *(float *)&v13[v16 - 8] * *(float *)(v16 - 8);
        *(float *)(v15 + v16 - 12) = v21 * *(float *)(v16 - 12);
        *(float *)(v15 + v16 - 8) = v22;
        --v17;
      }
      while ( v17 );
    }
    if ( v11 < v12 )
    {
      v23 = (char *)((char *)srcL - (char *)v5);
      v24 = (char *)v6 - (char *)v5;
      v25 = (signed __int64)&v5[v11];
      v26 = v12 - v11;
      do
      {
        v27 = *(float *)&v23[v25];
        v25 += 4i64;
        *(float *)(v24 + v25 - 4) = v27 * *(float *)(v25 - 4);
        --v26;
      }
      while ( v26 );
    }
  }
}

// File Line: 549
// RVA: 0xB42450
void __fastcall hkaBlender::mul(hkVector4f *dst, hkVector4f *srcL, hkVector4f *srcR, int n)
{
  __int64 v4; // rax
  signed __int64 v5; // rdx
  signed __int64 v6; // rcx
  __m128 v7; // xmm0

  v4 = n;
  if ( n > 0 )
  {
    v5 = (char *)srcL - (char *)srcR;
    v6 = (char *)dst - (char *)srcR;
    do
    {
      v7 = *(__m128 *)((char *)&srcR->m_quad + v5);
      ++srcR;
      *(__m128 *)((char *)&srcR[-1].m_quad + v6) = _mm_mul_ps(v7, srcR[-1].m_quad);
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 557
// RVA: 0xB42490
void __fastcall hkaBlender::mul(hkQuaternionf *dst, hkQuaternionf *srcL, hkQuaternionf *srcR, int n)
{
  __int64 v4; // rax
  signed __int64 v5; // r8
  signed __int64 v6; // rcx
  __m128 v7; // xmm6
  __m128 v8; // xmm2
  __m128 v9; // xmm4
  __m128 v10; // xmm5
  __m128 v11; // xmm3
  __m128 v12; // xmm1
  __m128 v13; // xmm6
  __m128 v14; // xmm3

  v4 = n;
  if ( n > 0 )
  {
    v5 = (char *)srcR - (char *)srcL;
    v6 = (char *)dst - (char *)srcL;
    do
    {
      v7 = srcL->m_vec.m_quad;
      v8 = *(__m128 *)((char *)&srcL->m_vec.m_quad + v5);
      ++srcL;
      v9 = _mm_shuffle_ps(v7, v7, 255);
      v10 = _mm_shuffle_ps(v8, v8, 255);
      v11 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v7), _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v8));
      v12 = _mm_mul_ps(v10, v7);
      v13 = _mm_mul_ps(v7, v8);
      v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 201), _mm_mul_ps(v9, v8)), v12);
      *(__m128 *)((char *)&srcL[-1].m_vec.m_quad + v6) = _mm_shuffle_ps(
                                                           v14,
                                                           _mm_unpackhi_ps(
                                                             v14,
                                                             _mm_sub_ps(
                                                               _mm_mul_ps(v10, v9),
                                                               _mm_add_ps(
                                                                 _mm_add_ps(
                                                                   _mm_shuffle_ps(v13, v13, 85),
                                                                   _mm_shuffle_ps(v13, v13, 0)),
                                                                 _mm_shuffle_ps(v13, v13, 170)))),
                                                           196);
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 565
// RVA: 0xB42540
void __fastcall hkaBlender::mul(hkQsTransformf *dst, hkQsTransformf *srcL, hkQsTransformf *srcR, int n)
{
  __int64 v4; // r10
  signed __int64 v5; // r8
  __m128 *v6; // rax
  signed __int64 v7; // rcx
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm5
  __m128 v12; // xmm6
  __m128 v13; // xmm4
  __m128 v14; // xmm5
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  __m128 v18; // xmm3
  __m128 v19; // xmm5
  __m128 v20; // xmm3
  __m128 v21; // xmm4
  __m128 v22; // xmm3
  __m128 v23; // xmm0

  v4 = n;
  if ( n > 0 )
  {
    v5 = (char *)srcR - (char *)srcL;
    v6 = &srcL->m_rotation.m_vec.m_quad;
    v7 = (char *)dst - (char *)srcL;
    do
    {
      v8 = *v6;
      v9 = *(__m128 *)((char *)v6 + v5 - 16);
      v6 += 3;
      v10 = _mm_mul_ps(v9, v8);
      v11 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v9));
      v12 = _mm_shuffle_ps(v8, v8, 255);
      v13 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                    _mm_shuffle_ps(v10, v10, 170)),
                  v8),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v12, v12), (__m128)xmmword_141A711B0), v9)),
              _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v12));
      v14 = v8;
      v15 = *(__m128 *)((char *)v6 + v5 - 48);
      v16 = v14;
      v17 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v15);
      v18 = _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v14);
      v19 = _mm_mul_ps(v14, v15);
      *(__m128 *)((char *)v6 + v7 - 64) = _mm_add_ps(_mm_add_ps(v13, v13), v6[-4]);
      v20 = _mm_sub_ps(v18, v17);
      v21 = _mm_shuffle_ps(v15, v15, 255);
      v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v20, v20, 201), _mm_mul_ps(v15, v12)), _mm_mul_ps(v16, v21));
      v23 = _mm_mul_ps(*(__m128 *)((char *)v6 + v5 - 32), v6[-2]);
      *(__m128 *)((char *)v6 + v7 - 48) = _mm_shuffle_ps(
                                            v22,
                                            _mm_unpackhi_ps(
                                              v22,
                                              _mm_sub_ps(
                                                _mm_mul_ps(v21, v12),
                                                _mm_add_ps(
                                                  _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                                                  _mm_shuffle_ps(v19, v19, 170)))),
                                            196);
      *(__m128 *)((char *)v6 + v7 - 32) = v23;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 573
// RVA: 0xB42710
void __fastcall hkaBlender::mulInv(hkQsTransformf *dst, hkQsTransformf *srcL, hkQsTransformf *srcR, int n)
{
  signed __int64 v4; // rdi
  __int64 v5; // r14
  __m128 *v6; // rbp
  signed __int64 v7; // rsi
  __m128i v8; // xmm0
  __m128 v9; // xmm9
  __m128 v10; // xmm10
  __m128 v11; // xmm2
  __m128 v12; // xmm0
  __m128 v13; // xmm5
  __m128 v14; // xmm1
  __m128 v15; // xmm6
  __m128 v16; // xmm7
  __m128 v17; // xmm8
  __m128 v18; // xmm1
  __m128 v19; // xmm4
  __m128 v20; // xmm3
  __m128 v21; // xmm4
  __m128 v22; // xmm0
  __m128 v23; // xmm3
  __m128 v24; // xmm7
  __m128 v25; // xmm4
  __m128 v26; // xmm0
  hkVector4f v27; // [rsp+20h] [rbp-98h]

  if ( n > 0 )
  {
    v4 = (char *)srcR - (char *)srcL;
    v5 = n;
    v6 = &srcL->m_rotation.m_vec.m_quad;
    v7 = (char *)dst - (char *)srcL;
    v8 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
    v9 = (__m128)_mm_shuffle_epi32(v8, 0);
    v10 = (__m128)_mm_shuffle_epi32(v8, 64);
    do
    {
      hkVector4f::setRotatedInverseDir(&v27, (hkQuaternionf *)((char *)v6 + v4), (hkVector4f *)((char *)&v6[-1] + v4));
      v11 = *v6;
      v12 = *(__m128 *)((char *)v6 + v4 + 16);
      v13 = _mm_xor_ps(v9, v27.m_quad);
      v14 = _mm_rcp_ps(v12);
      v15 = _mm_shuffle_ps(v11, v11, 255);
      v16 = _mm_xor_ps(v10, *(__m128 *)((char *)v6 + v4));
      v17 = (__m128)_mm_srli_si128(
                      _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v12, v14)), v14), 4),
                      4);
      v18 = _mm_mul_ps(v13, *v6);
      v19 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), *v6), _mm_mul_ps(_mm_shuffle_ps(*v6, *v6, 201), v13));
      v20 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                    _mm_shuffle_ps(v18, v18, 170)),
                  *v6),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v15, v15), (__m128)xmmword_141A711B0), v13)),
              _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v15));
      v21 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), *v6), _mm_mul_ps(_mm_shuffle_ps(*v6, *v6, 201), v16));
      *(__m128 *)((char *)v6 + v7 - 16) = _mm_add_ps(_mm_add_ps(v20, v20), v6[-1]);
      v22 = _mm_mul_ps(v16, v15);
      v23 = _mm_shuffle_ps(v16, v16, 255);
      v24 = _mm_mul_ps(v16, v11);
      v25 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 201), v22), _mm_mul_ps(v23, v11));
      v26 = _mm_mul_ps(v6[1], v17);
      *(__m128 *)((char *)v6 + v7) = _mm_shuffle_ps(
                                       v25,
                                       _mm_unpackhi_ps(
                                         v25,
                                         _mm_sub_ps(
                                           _mm_mul_ps(v23, v15),
                                           _mm_add_ps(
                                             _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                                             _mm_shuffle_ps(v24, v24, 170)))),
                                       196);
      *(__m128 *)((char *)v6 + v7 + 16) = v26;
      v6 += 3;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 581
// RVA: 0xB42680
void __fastcall hkaBlender::mulInv(hkQuaternionf *dst, hkQuaternionf *srcL, hkQuaternionf *srcR, int n)
{
  __int64 v4; // rax
  signed __int64 v5; // r8
  signed __int64 v6; // rcx
  __m128 v7; // xmm2
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm4
  __m128 v11; // xmm0
  __m128 v12; // xmm3
  __m128 v13; // xmm4
  __m128 v14; // xmm0

  v4 = n;
  if ( n > 0 )
  {
    v5 = (char *)srcR - (char *)srcL;
    v6 = (char *)dst - (char *)srcL;
    do
    {
      v7 = srcL->m_vec.m_quad;
      v8 = *(__m128 *)((char *)&srcL->m_vec.m_quad + v5);
      ++srcL;
      v9 = _mm_mul_ps(_mm_shuffle_ps(v8, v8, 255), v7);
      v10 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v7));
      v11 = _mm_mul_ps(_mm_shuffle_ps(v7, v7, 255), v8);
      v12 = _mm_mul_ps(v8, v7);
      v13 = _mm_add_ps(_mm_sub_ps(_mm_shuffle_ps(v10, v10, 201), v11), v9);
      v14 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 78), v12);
      *(__m128 *)((char *)&srcL[-1].m_vec.m_quad + v6) = _mm_shuffle_ps(
                                                           v13,
                                                           _mm_unpackhi_ps(
                                                             v13,
                                                             _mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14)),
                                                           196);
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 589
// RVA: 0xB42920
void __fastcall hkaBlender::normalize(hkQuaternionf *quaternionsInOut, int n)
{
  __int64 v2; // rax
  __m128 v3; // xmm3
  __m128 v4; // xmm0
  __m128 v5; // xmm2
  __m128 v6; // xmm1
  __m128 v7; // xmm2

  v2 = n;
  if ( n > 0 )
  {
    do
    {
      v3 = quaternionsInOut->m_vec.m_quad;
      ++quaternionsInOut;
      v4 = _mm_mul_ps(v3, v3);
      v5 = _mm_add_ps(_mm_shuffle_ps(v4, v4, 78), v4);
      v6 = _mm_add_ps(_mm_shuffle_ps(v5, v5, 177), v5);
      v7 = _mm_rsqrt_ps(v6);
      quaternionsInOut[-1].m_vec.m_quad = _mm_mul_ps(
                                            v3,
                                            _mm_mul_ps(
                                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v7, v6), v7)),
                                              _mm_mul_ps(*(__m128 *)_xmm, v7)));
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 597
// RVA: 0xB42990
void __fastcall hkaBlender::normalize(hkQsTransformf *transformsInOut, int n)
{
  __int64 v2; // rax
  __m128 *v3; // rcx
  __m128 v4; // xmm3
  __m128 v5; // xmm0
  __m128 v6; // xmm2
  __m128 v7; // xmm1
  __m128 v8; // xmm2

  v2 = n;
  if ( n > 0 )
  {
    v3 = &transformsInOut->m_rotation.m_vec.m_quad;
    do
    {
      v4 = *v3;
      v3 += 3;
      v5 = _mm_mul_ps(v4, v4);
      v6 = _mm_add_ps(_mm_shuffle_ps(v5, v5, 78), v5);
      v7 = _mm_add_ps(_mm_shuffle_ps(v6, v6, 177), v6);
      v8 = _mm_rsqrt_ps(v7);
      v3[-3] = _mm_mul_ps(
                 v4,
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)),
                   _mm_mul_ps(*(__m128 *)_xmm, v8)));
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 607
// RVA: 0xB42A00
void __fastcall hkaBlender::rotate(hkVector4f *dst, hkQuaternionf *srcL, hkVector4f *srcR, int n)
{
  __int64 v4; // rax
  signed __int64 v5; // r8
  signed __int64 v6; // rcx
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  __m128 v9; // xmm1
  __m128 v10; // xmm5
  __m128 v11; // xmm6
  __m128 v12; // xmm3

  v4 = n;
  if ( n > 0 )
  {
    v5 = (char *)srcR - (char *)srcL;
    v6 = (char *)dst - (char *)srcL;
    do
    {
      v7 = srcL->m_vec.m_quad;
      v8 = *(__m128 *)((char *)&srcL->m_vec.m_quad + v5);
      ++srcL;
      v9 = _mm_mul_ps(v8, v7);
      v10 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v7), _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v8));
      v11 = _mm_shuffle_ps(v7, v7, 255);
      v12 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)),
                    _mm_shuffle_ps(v9, v9, 170)),
                  v7),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v11, v11), (__m128)xmmword_141A711B0), v8)),
              _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v11));
      *(__m128 *)((char *)&srcL[-1].m_vec.m_quad + v6) = _mm_add_ps(v12, v12);
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 615
// RVA: 0xB42AC0
void __fastcall hkaBlender::rotateInv(hkVector4f *dst, hkQuaternionf *srcL, hkVector4f *srcR, int n)
{
  __int64 v4; // rax
  signed __int64 v5; // r8
  signed __int64 v6; // rcx
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  __m128 v9; // xmm1
  __m128 v10; // xmm5
  __m128 v11; // xmm6
  __m128 v12; // xmm3

  v4 = n;
  if ( n > 0 )
  {
    v5 = (char *)srcR - (char *)srcL;
    v6 = (char *)dst - (char *)srcL;
    do
    {
      v7 = srcL->m_vec.m_quad;
      v8 = *(__m128 *)((char *)&srcL->m_vec.m_quad + v5);
      ++srcL;
      v9 = _mm_mul_ps(v8, v7);
      v10 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v7));
      v11 = _mm_shuffle_ps(v7, v7, 255);
      v12 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)),
                    _mm_shuffle_ps(v9, v9, 170)),
                  v7),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v11, v11), (__m128)xmmword_141A711B0), v8)),
              _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v11));
      *(__m128 *)((char *)&srcL[-1].m_vec.m_quad + v6) = _mm_add_ps(v12, v12);
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 623
// RVA: 0xB42B80
void __fastcall hkaBlender::transform(hkVector4f *dst, hkQsTransformf *srcL, hkVector4f *srcR, int n)
{
  __int64 v4; // rax
  __m128 *v5; // rdx
  signed __int64 v6; // r8
  __m128 v7; // xmm2
  __m128 v8; // xmm5
  __m128 v9; // xmm5
  __m128 v10; // xmm1
  __m128 v11; // xmm6
  __m128 v12; // xmm4
  __m128 v13; // xmm3

  v4 = n;
  if ( n > 0 )
  {
    v5 = &srcL->m_rotation.m_vec.m_quad;
    v6 = (char *)srcR - (char *)dst;
    do
    {
      v7 = *v5;
      v8 = *(__m128 *)((char *)&dst->m_quad + v6);
      ++dst;
      v5 += 3;
      v9 = _mm_mul_ps(v8, v5[-2]);
      v10 = _mm_mul_ps(v7, v9);
      v11 = _mm_shuffle_ps(v7, v7, 255);
      v12 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v7), _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v9));
      v13 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                    _mm_shuffle_ps(v10, v10, 170)),
                  v7),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v11, v11), (__m128)xmmword_141A711B0), v9)),
              _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v11));
      dst[-1].m_quad = _mm_add_ps(_mm_add_ps(v13, v13), v5[-4]);
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 631
// RVA: 0xB42C40
void __fastcall hkaBlender::transformInv(hkVector4f *dst, hkQsTransformf *srcL, hkVector4f *srcR, int n)
{
  __int64 v4; // rax
  __m128 *v5; // rdx
  signed __int64 v6; // r8
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  __m128 v9; // xmm4
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm0
  __m128 v14; // xmm6
  __m128 v15; // xmm1

  v4 = n;
  if ( n > 0 )
  {
    v5 = &srcL->m_rotation.m_vec.m_quad;
    v6 = (char *)srcR - (char *)dst;
    do
    {
      v7 = *v5;
      v8 = *(__m128 *)((char *)&dst->m_quad + v6);
      ++dst;
      v5 += 3;
      v9 = _mm_sub_ps(v8, v5[-4]);
      v10 = _mm_shuffle_ps(v7, v7, 255);
      v11 = _mm_mul_ps(v7, v9);
      v12 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v9), _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v7));
      v13 = v5[-2];
      v14 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                    _mm_shuffle_ps(v11, v11, 170)),
                  v7),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v10, v10), (__m128)xmmword_141A711B0), v9)),
              _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v10));
      v15 = _mm_rcp_ps(v13);
      dst[-1].m_quad = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v13, v15)), v15), _mm_add_ps(v14, v14));
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 639
// RVA: 0xB42D30
void __fastcall hkaBlender::localFromModel(hkQsTransformf *poseLocalOut, hkQsTransformf *poseModelIn, const __int16 *parentIndices, int numBones, hkQsTransformf *worldFromModel)
{
  __int64 v5; // rdi
  const __int16 *v6; // r15
  hkQsTransformf *v7; // rbp
  __m128i v8; // xmm0
  __m128 *v9; // rbx
  signed __int64 v10; // rsi
  __m128 v11; // xmm12
  __m128 v12; // xmm13
  __int64 v13; // rax
  __m128 v14; // xmm10
  __m128 v15; // xmm9
  __m128 v16; // xmm11
  hkQsTransformf *v17; // rcx
  __m128 v18; // xmm7
  __m128 v19; // xmm1
  __m128 v20; // xmm6
  __m128 v21; // xmm8
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm0
  __m128 v25; // xmm4
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm0
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  __m128 v31; // xmm9
  __m128 v32; // xmm2
  __m128 v33; // xmm2
  hkVector4f direction; // [rsp+20h] [rbp-108h]
  hkQuaternionf quat; // [rsp+30h] [rbp-F8h]
  __m128 v36; // [rsp+40h] [rbp-E8h]
  hkVector4f v37; // [rsp+50h] [rbp-D8h]

  if ( numBones )
  {
    v5 = numBones;
    v6 = parentIndices;
    v7 = poseModelIn;
    v8 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
    v9 = &poseLocalOut[numBones].m_scale.m_quad;
    v10 = (char *)poseModelIn - (char *)poseLocalOut;
    v11 = (__m128)_mm_shuffle_epi32(v8, 0);
    v12 = (__m128)_mm_shuffle_epi32(v8, 64);
    do
    {
      v13 = v6[v5 - 1];
      v14 = *(__m128 *)((char *)v9 + v10 - 80);
      v15 = *(__m128 *)((char *)v9 + v10 - 64);
      v9 -= 3;
      --v5;
      v16 = *(__m128 *)((char *)v9 + v10);
      if ( (signed int)v13 < 0 )
        v17 = worldFromModel;
      else
        v17 = &v7[v13];
      direction.m_quad = (__m128)v17->m_translation;
      quat.m_vec.m_quad = (__m128)v17->m_rotation;
      v36 = v17->m_scale.m_quad;
      hkVector4f::setRotatedInverseDir(&v37, &quat, &direction);
      v18 = _mm_xor_ps(v12, quat.m_vec.m_quad);
      v19 = _mm_rcp_ps(v36);
      v20 = _mm_shuffle_ps(v18, v18, 255);
      v21 = (__m128)_mm_srli_si128(
                      _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v36, v19)), v19), 4),
                      4);
      v22 = _mm_mul_ps(v14, v18);
      v23 = _mm_shuffle_ps(v18, v18, 201);
      v24 = _mm_mul_ps(v23, v14);
      v25 = _mm_mul_ps(v23, v15);
      v26 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v18), v24);
      v27 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                    _mm_shuffle_ps(v22, v22, 170)),
                  v18),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v20, v20), (__m128)xmmword_141A711B0), v14)),
              _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v20));
      v28 = _mm_mul_ps(v15, v20);
      v29 = _mm_shuffle_ps(v15, v15, 255);
      v9[-2] = _mm_add_ps(_mm_add_ps(v27, v27), _mm_xor_ps(v11, v37.m_quad));
      v30 = _mm_shuffle_ps(v15, v15, 201);
      v31 = _mm_mul_ps(v15, v18);
      v32 = _mm_sub_ps(_mm_mul_ps(v30, v18), v25);
      v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v32, v32, 201), v28), _mm_mul_ps(v18, v29));
      v9[-1] = _mm_shuffle_ps(
                 v33,
                 _mm_unpackhi_ps(
                   v33,
                   _mm_sub_ps(
                     _mm_mul_ps(v29, v20),
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                       _mm_shuffle_ps(v31, v31, 170)))),
                 196);
      *v9 = _mm_mul_ps(v16, v21);
    }
    while ( v5 );
  }
}

// File Line: 652
// RVA: 0xB42FD0
void __fastcall hkaBlender::modelFromLocal(hkQsTransformf *poseModelOut, hkQsTransformf *poseLocalIn, const __int16 *parentIndices, int numBones, hkQsTransformf *worldFromModel)
{
  __int64 v5; // r10
  __int64 v6; // rbx
  hkVector4f *v7; // r9
  signed __int64 v8; // r11
  __int64 v9; // rax
  __m128 v10; // xmm9
  __m128 v11; // xmm8
  __m128 v12; // xmm10
  hkQsTransformf *v13; // rax
  __m128 v14; // xmm5
  __m128 v15; // xmm1
  __m128 v16; // xmm6
  __m128 v17; // xmm4
  __m128 v18; // xmm0
  __m128 v19; // xmm4
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm0
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm2
  __m128 v27; // xmm8
  __m128 v28; // xmm2
  __m128 v29; // xmm2

  if ( numBones > 0 )
  {
    v5 = 0i64;
    v6 = numBones;
    v7 = &poseModelOut->m_scale;
    v8 = (char *)poseLocalIn - (char *)poseModelOut;
    do
    {
      v9 = parentIndices[v5];
      v10 = *(__m128 *)((char *)&v7[-2].m_quad + v8);
      v11 = *(__m128 *)((char *)&v7[-1].m_quad + v8);
      v12 = *(__m128 *)((char *)&v7->m_quad + v8);
      if ( (signed int)v9 < 0 )
        v13 = worldFromModel;
      else
        v13 = &poseModelOut[v9];
      v14 = v13->m_rotation.m_vec.m_quad;
      ++v5;
      v7 += 3;
      v15 = _mm_mul_ps(v10, v14);
      v16 = _mm_shuffle_ps(v13->m_rotation.m_vec.m_quad, v14, 255);
      v17 = _mm_shuffle_ps(v13->m_rotation.m_vec.m_quad, v14, 201);
      v18 = _mm_mul_ps(v17, v10);
      v19 = _mm_mul_ps(v17, v11);
      v20 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v14), v18);
      v21 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                    _mm_shuffle_ps(v15, v15, 170)),
                  v14),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v16, v16), (__m128)xmmword_141A711B0), v10)),
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v16));
      v22 = _mm_mul_ps(v11, v16);
      v23 = _mm_shuffle_ps(v11, v11, 255);
      v24 = _mm_mul_ps(v13->m_rotation.m_vec.m_quad, v23);
      v25 = _mm_add_ps(_mm_add_ps(v21, v21), v13->m_translation.m_quad);
      v7[-3].m_quad = _mm_mul_ps(v12, v13->m_scale.m_quad);
      v7[-5] = (hkVector4f)v25;
      v26 = _mm_shuffle_ps(v11, v11, 201);
      v27 = _mm_mul_ps(v11, v14);
      v28 = _mm_sub_ps(_mm_mul_ps(v26, v14), v19);
      v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v28, v28, 201), v22), v24);
      v7[-4].m_quad = _mm_shuffle_ps(
                        v29,
                        _mm_unpackhi_ps(
                          v29,
                          _mm_sub_ps(
                            _mm_mul_ps(v23, v16),
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                              _mm_shuffle_ps(v27, v27, 170)))),
                        196);
    }
    while ( v5 < v6 );
  }
}


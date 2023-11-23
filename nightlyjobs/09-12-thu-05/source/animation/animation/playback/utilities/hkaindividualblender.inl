// File Line: 11
// RVA: 0xB3F5B0
void __fastcall hkaBlender::blend(
        float *dst,
        const float *srcL,
        const float *srcR,
        hkSimdFloat32 *alpha,
        int n,
        hkaBlender::BLEND_MODE blendMode)
{
  __m128 m_real; // xmm3
  float v8; // xmm4_4
  unsigned int v9; // r9d
  unsigned int v10; // xmm1_4
  unsigned int v11; // xmm2_4
  signed __int64 v12; // rdx
  const float *v13; // rcx
  signed __int64 v14; // r8
  __int64 v15; // rax
  float v16; // xmm0_4
  float v17; // xmm0_4
  unsigned int v18; // r9d
  unsigned int v19; // xmm2_4
  unsigned int v20; // xmm0_4
  signed __int64 v21; // rdx
  const float *v22; // rcx
  signed __int64 v23; // r8
  __int64 v24; // rax
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  unsigned int v28; // r9d
  unsigned int v29; // xmm2_4
  unsigned int v30; // xmm4_4
  signed __int64 v31; // rdx
  const float *v32; // rcx
  signed __int64 v33; // r8
  __int64 v34; // rax
  float v35; // xmm0_4
  float v36; // xmm1_4
  __m128 v37; // xmm2

  if ( n > 0 )
  {
    m_real = alpha->m_real;
    v8 = 1.0 - COERCE_FLOAT(*alpha);
    if ( blendMode == -1 )
    {
      v28 = n - 1;
      v29 = _mm_shuffle_ps((__m128)*(unsigned int *)srcL, (__m128)*(unsigned int *)srcL, 0).m128_u32[0];
      v30 = _mm_shuffle_ps((__m128)*(unsigned int *)srcR, (__m128)*(unsigned int *)srcR, 0).m128_u32[0];
      if ( n - 1 > 0 )
      {
        v31 = (char *)srcL - (char *)srcR;
        v32 = srcR + 1;
        v33 = (char *)dst - (char *)srcR - 4;
        v34 = v28;
        do
        {
          ++v32;
          v35 = m_real.m128_f32[0] * *(float *)&v30;
          v30 = _mm_shuffle_ps((__m128)*((unsigned int *)v32 - 1), (__m128)*((unsigned int *)v32 - 1), 0).m128_u32[0];
          v36 = *(float *)&v29 - v35;
          v37 = (__m128)*(unsigned int *)((char *)v32 + v31 - 4);
          *(float *)((char *)v32 + v33 - 4) = v36;
          v29 = _mm_shuffle_ps(v37, v37, 0).m128_u32[0];
          --v34;
        }
        while ( v34 );
      }
      dst[v28] = *(float *)&v29 - (float)(m_real.m128_f32[0] * *(float *)&v30);
    }
    else if ( blendMode )
    {
      if ( blendMode == ADD )
      {
        v9 = n - 1;
        v10 = _mm_shuffle_ps((__m128)*(unsigned int *)srcL, (__m128)*(unsigned int *)srcL, 0).m128_u32[0];
        v11 = _mm_shuffle_ps((__m128)*(unsigned int *)srcR, (__m128)*(unsigned int *)srcR, 0).m128_u32[0];
        if ( n - 1 > 0 )
        {
          v12 = (char *)srcL - (char *)srcR;
          v13 = srcR + 1;
          v14 = (char *)dst - (char *)srcR - 4;
          v15 = v9;
          do
          {
            ++v13;
            v16 = m_real.m128_f32[0] * *(float *)&v11;
            v11 = _mm_shuffle_ps((__m128)*((unsigned int *)v13 - 1), (__m128)*((unsigned int *)v13 - 1), 0).m128_u32[0];
            v17 = v16 + *(float *)&v10;
            v10 = _mm_shuffle_ps(
                    (__m128)*(unsigned int *)((char *)v13 + v12 - 4),
                    (__m128)*(unsigned int *)((char *)v13 + v12 - 4),
                    0).m128_u32[0];
            *(float *)((char *)v13 + v14 - 4) = v17;
            --v15;
          }
          while ( v15 );
        }
        dst[v9] = (float)(m_real.m128_f32[0] * *(float *)&v11) + *(float *)&v10;
      }
    }
    else
    {
      v18 = n - 1;
      v19 = _mm_shuffle_ps((__m128)*(unsigned int *)srcL, (__m128)*(unsigned int *)srcL, 0).m128_u32[0];
      v20 = _mm_shuffle_ps((__m128)*(unsigned int *)srcR, (__m128)*(unsigned int *)srcR, 0).m128_u32[0];
      if ( n - 1 > 0 )
      {
        v21 = (char *)srcL - (char *)srcR;
        v22 = srcR + 1;
        v23 = (char *)dst - (char *)srcR - 4;
        v24 = v18;
        do
        {
          ++v22;
          v25 = m_real.m128_f32[0] * *(float *)&v20;
          v26 = v8 * *(float *)&v19;
          v19 = _mm_shuffle_ps(
                  (__m128)*(unsigned int *)((char *)v22 + v21 - 4),
                  (__m128)*(unsigned int *)((char *)v22 + v21 - 4),
                  0).m128_u32[0];
          v27 = v25 + v26;
          v20 = _mm_shuffle_ps((__m128)*((unsigned int *)v22 - 1), (__m128)*((unsigned int *)v22 - 1), 0).m128_u32[0];
          *(float *)((char *)v22 + v23 - 4) = v27;
          --v24;
        }
        while ( v24 );
      }
      dst[v18] = (float)(m_real.m128_f32[0] * *(float *)&v20) + (float)(v8 * *(float *)&v19);
    }
  }
}

// File Line: 77
// RVA: 0xB3F760
void __fastcall hkaBlender::blend(
        hkVector4f *dst,
        hkVector4f *srcL,
        hkVector4f *srcR,
        hkSimdFloat32 *alpha,
        int n,
        hkaBlender::BLEND_MODE blendMode)
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
  __m128 m_real; // xmm2
  signed __int64 v16; // r8
  signed __int64 v17; // rcx
  __m128 v18; // xmm1
  __m128 m_quad; // xmm0

  v6 = n;
  if ( blendMode == -1 )
  {
    if ( n > 0i64 )
    {
      m_real = alpha->m_real;
      v16 = (char *)srcR - (char *)srcL;
      v17 = (char *)dst - (char *)srcL;
      do
      {
        v18 = *(__m128 *)((char *)&srcL->m_quad + v16);
        m_quad = srcL->m_quad;
        ++srcL;
        *(__m128 *)((char *)&srcL[-1].m_quad + v17) = _mm_sub_ps(m_quad, _mm_mul_ps(v18, m_real));
        --v6;
      }
      while ( v6 );
    }
  }
  else if ( blendMode )
  {
    if ( blendMode == ADD && n > 0i64 )
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
void __fastcall hkaBlender::blend(
        hkQuaternionf *dst,
        hkQuaternionf *srcL,
        hkQuaternionf *srcR,
        hkSimdFloat32 *alpha,
        int n,
        hkaBlender::BLEND_MODE blendMode,
        hkaBlender::ROTATION_MODE rotationMode)
{
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
  __m128 v45; // xmm0
  __m128 v46; // xmm6
  __m128 v47; // xmm0
  __m128 v48; // xmm1
  signed __int64 v49; // rsi
  __m128 v50; // xmm5
  __m128 v51; // xmm6
  __m128 v52; // xmm0
  __m128 v53; // xmm0
  __m128 v54; // xmm1
  __m128 v55; // xmm6
  __m128 v56; // xmm7
  __m128 m_quad; // xmm2
  __m128 v58; // xmm3
  __m128 v59; // xmm1
  __m128 v60; // xmm5
  __m128 v61; // xmm0
  __m128 v62; // xmm3
  __m128 v63; // xmm5
  __m128 v64; // xmm0
  __m128 v65; // xmm0
  __m128 v66; // xmm5
  __m128 v67; // xmm0
  __m128 v68; // xmm1
  hkQuaternionf q1; // [rsp+20h] [rbp-78h] BYREF

  v8 = srcL;
  v9 = dst;
  if ( rotationMode == SLERP )
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
          hkQuaternionf::setSlerp(v9, (hkQuaternionf *)((char *)v9 + v23), &q1, alpha);
          ++v9;
          ++v8;
          --v22;
        }
        while ( v22 );
      }
    }
    else if ( blendMode )
    {
      if ( blendMode == ADD && n > 0 )
      {
        v10 = (unsigned int)n;
        v11 = (char *)srcL - (char *)dst;
        v12 = (char *)srcR - (char *)srcL;
        do
        {
          v13 = *(__m128 *)((char *)&v8->m_vec.m_quad + v12);
          v14 = _mm_shuffle_ps(v8->m_vec.m_quad, v8->m_vec.m_quad, 255);
          v15 = _mm_shuffle_ps(v13, v13, 255);
          v16 = _mm_mul_ps(v8->m_vec.m_quad, v13);
          v17 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v8->m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v8->m_vec.m_quad, v8->m_vec.m_quad, 201), v13));
          v18 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v17, v17, 201), _mm_mul_ps(v13, v14)),
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
          hkQuaternionf::setSlerp(v9, (hkQuaternionf *)((char *)v9 + v11), &q1, alpha);
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
        hkQuaternionf::setSlerp((hkQuaternionf *)((char *)v8 + v21), v8, (hkQuaternionf *)((char *)v8 + v19), alpha);
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
        v55 = _mm_shuffle_ps((__m128)alpha->m_real.m128_u32[0], (__m128)alpha->m_real.m128_u32[0], 0);
        v56 = _mm_sub_ps(query.m_quad, v55);
        do
        {
          m_quad = v8->m_vec.m_quad;
          v58 = *(__m128 *)((char *)&v8->m_vec.m_quad + (char *)srcR - (char *)srcL);
          ++v8;
          v59 = _mm_mul_ps(_mm_shuffle_ps(v58, v58, 255), m_quad);
          v60 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v58),
                  _mm_mul_ps(_mm_shuffle_ps(v58, v58, 201), m_quad));
          v61 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 255), v58);
          v62 = _mm_mul_ps(v58, m_quad);
          v63 = _mm_add_ps(_mm_sub_ps(_mm_shuffle_ps(v60, v60, 201), v61), v59);
          v64 = _mm_add_ps(_mm_shuffle_ps(v62, v62, 78), v62);
          v65 = _mm_shuffle_ps(v63, _mm_unpackhi_ps(v63, _mm_add_ps(_mm_shuffle_ps(v64, v64, 177), v64)), 196);
          v66 = _mm_mul_ps(v65, v55);
          v67 = _mm_mul_ps(v65, m_quad);
          v68 = _mm_add_ps(_mm_shuffle_ps(v67, v67, 78), v67);
          *(__m128 *)((char *)&v8[-1].m_vec.m_quad + (char *)dst - (char *)srcL) = _mm_add_ps(
                                                                                     _mm_mul_ps(
                                                                                       _mm_xor_ps(
                                                                                         (__m128)_mm_slli_epi32(
                                                                                                   _mm_srli_epi32(
                                                                                                     (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v68, v68, 177), v68), (__m128)0i64),
                                                                                                     0x1Fu),
                                                                                                   0x1Fu),
                                                                                         v56),
                                                                                       m_quad),
                                                                                     v66);
          --v31;
        }
        while ( v31 );
      }
    }
    else if ( blendMode )
    {
      if ( blendMode == ADD && n > 0i64 )
      {
        v32 = _mm_shuffle_ps((__m128)alpha->m_real.m128_u32[0], (__m128)alpha->m_real.m128_u32[0], 0);
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
          v46 = _mm_mul_ps(v45, v32);
          v47 = _mm_mul_ps(v45, v36);
          v48 = _mm_add_ps(_mm_shuffle_ps(v47, v47, 78), v47);
          *(__m128 *)((char *)&v8[-1].m_vec.m_quad + (char *)dst - (char *)srcL) = _mm_add_ps(
                                                                                     _mm_mul_ps(
                                                                                       _mm_xor_ps(
                                                                                         (__m128)_mm_slli_epi32(
                                                                                                   _mm_srli_epi32(
                                                                                                     (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v48, v48, 177), v48), (__m128)0i64),
                                                                                                     0x1Fu),
                                                                                                   0x1Fu),
                                                                                         v33),
                                                                                       v36),
                                                                                     v46);
          --v31;
        }
        while ( v31 );
      }
    }
    else if ( n > 0i64 )
    {
      v49 = (char *)srcR - (char *)srcL;
      v50 = _mm_shuffle_ps((__m128)alpha->m_real.m128_u32[0], (__m128)alpha->m_real.m128_u32[0], 0);
      v51 = _mm_sub_ps(query.m_quad, v50);
      do
      {
        v52 = *(__m128 *)((char *)&v8->m_vec.m_quad + v49);
        ++v8;
        v53 = _mm_mul_ps(v52, v8[-1].m_vec.m_quad);
        v54 = _mm_add_ps(_mm_shuffle_ps(v53, v53, 78), v53);
        *(__m128 *)((char *)&v8[-1].m_vec.m_quad + (char *)dst - (char *)srcL) = _mm_add_ps(
                                                                                   _mm_mul_ps(
                                                                                     _mm_xor_ps(
                                                                                       (__m128)_mm_slli_epi32(
                                                                                                 _mm_srli_epi32(
                                                                                                   (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v54, v54, 177), v54), (__m128)0i64),
                                                                                                   0x1Fu),
                                                                                                 0x1Fu),
                                                                                       v51),
                                                                                     v8[-1].m_vec.m_quad),
                                                                                   _mm_mul_ps(
                                                                                     v50,
                                                                                     *(__m128 *)((char *)&v8[-1].m_vec.m_quad
                                                                                               + v49)));
        --v31;
      }
      while ( v31 );
    }
  }
}                                                                            *(__m128 *)((char *)&v8[-1].m_vec.m_quad
                                                          

// File Line: 178
// RVA: 0xB3FD30
void __fastcall hkaBlender::blend(
        hkQsTransformf *dst,
        hkQsTransformf *srcL,
        hkQsTransformf *srcR,
        hkSimdFloat32 *alpha,
        int n,
        hkaBlender::BLEND_MODE blendMode,
        hkaBlender::ROTATION_MODE rotationMode)
{
  __int64 v9; // r12
  __m128 m_real; // xmm8
  signed __int64 v11; // rdi
  hkVector4f *v12; // r13
  signed __int64 v13; // r14
  hkQuaternionf *v14; // rbx
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
  hkVector4f *p_m_scale; // r13
  signed __int64 v37; // r14
  __int64 v38; // rsi
  __m128i inserted; // xmm0
  hkQuaternionf *p_m_rotation; // r12
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
  __m128 v53; // xmm4
  __m128 v54; // xmm0
  __m128 v55; // xmm7
  __m128 v56; // xmm4
  __m128 v57; // xmm0
  __m128 v58; // xmm6
  __m128 v59; // xmm12
  signed __int64 v60; // rsi
  hkQuaternionf *v61; // rax
  signed __int64 v62; // rdi
  __int64 v63; // rdx
  __m128 v64; // xmm10
  __m128 v65; // xmm11
  __m128 v66; // xmm9
  __m128 v67; // xmm2
  __m128 v68; // xmm1
  __m128 v69; // xmm3
  __m128 v70; // xmm7
  __m128 v71; // xmm0
  __m128 v72; // xmm2
  __m128 v73; // xmm8
  __m128 v74; // xmm4
  __m128 v75; // xmm1
  __m128 v76; // xmm3
  __m128 v77; // xmm6
  __m128 v78; // xmm0
  __m128 v79; // xmm2
  __m128 v80; // xmm6
  __m128 v81; // xmm6
  __m128 v82; // xmm0
  __m128 v83; // xmm1
  __m128 v84; // xmm3
  __int64 v85; // rcx
  __m128 v86; // xmm5
  signed __int64 v87; // rsi
  hkQuaternionf *v88; // rax
  signed __int64 v89; // rdi
  __m128 v90; // xmm6
  __m128 v91; // xmm7
  __m128 v92; // xmm1
  __m128 v93; // xmm0
  __m128 v94; // xmm0
  __m128 v95; // xmm1
  __m128 v96; // xmm0
  __m128 v97; // xmm2
  signed __int64 v98; // rsi
  hkQuaternionf *v99; // r12
  __m128i v100; // xmm0
  signed __int64 v101; // rdi
  __int64 v102; // r14
  __m128 v103; // xmm12
  __m128 v104; // xmm13
  char *v105; // rbx
  __m128 m_quad; // xmm11
  __m128 v107; // xmm2
  __m128 v108; // xmm7
  __m128 v109; // xmm3
  __m128 v110; // xmm5
  __m128 v111; // xmm10
  __m128 v112; // xmm1
  __m128 v113; // xmm4
  __m128 v114; // xmm2
  __m128 v115; // xmm0
  __m128 v116; // xmm3
  __m128 v117; // xmm9
  __m128 v118; // xmm8
  __m128 v119; // xmm0
  __m128 v120; // xmm5
  __m128 v121; // xmm8
  __m128 v122; // xmm1
  __m128 v123; // xmm5
  __m128 v124; // xmm8
  __m128 v125; // xmm0
  __m128 v126; // xmm0
  __m128 v127; // xmm3
  __m128 v128; // xmm6
  __m128 v129; // xmm1
  __m128 v130; // [rsp+20h] [rbp-B8h]
  hkQuaternionf q1; // [rsp+30h] [rbp-A8h] BYREF
  __m128 v132; // [rsp+40h] [rbp-98h]
  hkVector4f v133; // [rsp+50h] [rbp-88h] BYREF
  __int64 v134; // [rsp+128h] [rbp+50h]
  void *retaddr; // [rsp+148h] [rbp+70h]
  int v136; // [rsp+150h] [rbp+78h]
  int v137; // [rsp+158h] [rbp+80h]

  if ( v137 == 1 )
  {
    v9 = (int)retaddr;
    v134 = (int)retaddr;
    if ( v136 == -1 )
    {
      if ( (int)retaddr > 0 )
      {
        v35 = (char *)srcR - (char *)srcL;
        p_m_scale = &dst->m_scale;
        v37 = (char *)srcL - (char *)dst;
        v38 = v134;
        inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
        p_m_rotation = &srcL->m_rotation;
        v41 = (__m128)_mm_shuffle_epi32(inserted, 0);
        v42 = (__m128)_mm_shuffle_epi32(inserted, 64);
        do
        {
          hkVector4f::setRotatedInverseDir(
            &v133,
            (hkQuaternionf *)((char *)p_m_rotation + v35),
            (hkVector4f *)((char *)&p_m_rotation[-1].m_vec + v35));
          v43 = *(__m128 *)((char *)&p_m_rotation[1].m_vec.m_quad + v35);
          v44 = _mm_xor_ps(v41, v133.m_quad);
          v45 = _mm_rcp_ps(v43);
          v46 = _mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 255);
          v47 = _mm_xor_ps(v42, *(__m128 *)((char *)&p_m_rotation->m_vec.m_quad + v35));
          v48 = (__m128)_mm_srli_si128(
                          _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v43, v45)), v45), 4),
                          4);
          v49 = _mm_mul_ps(p_m_rotation->m_vec.m_quad, v44);
          v50 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), p_m_rotation->m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 201), v44));
          v51 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)),
                        _mm_shuffle_ps(v49, v49, 170)),
                      p_m_rotation->m_vec.m_quad),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v46, v46), (__m128)xmmword_141A711B0), v44)),
                  _mm_mul_ps(_mm_shuffle_ps(v50, v50, 201), v46));
          v52 = _mm_shuffle_ps(v47, v47, 255);
          v53 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), p_m_rotation->m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 201), v47));
          v130 = _mm_add_ps(_mm_add_ps(v51, v51), p_m_rotation[-1].m_vec.m_quad);
          v54 = _mm_mul_ps(v46, v47);
          v55 = _mm_mul_ps(v47, p_m_rotation->m_vec.m_quad);
          v56 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v53, v53, 201), v54), _mm_mul_ps(v52, p_m_rotation->m_vec.m_quad));
          v57 = _mm_mul_ps(p_m_rotation[1].m_vec.m_quad, v48);
          q1.m_vec.m_quad = _mm_shuffle_ps(
                              v56,
                              _mm_unpackhi_ps(
                                v56,
                                _mm_sub_ps(
                                  _mm_mul_ps(v52, v46),
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                                    _mm_shuffle_ps(v55, v55, 170)))),
                              196);
          v58 = _mm_sub_ps(v130, *(__m128 *)((char *)&p_m_scale[-2].m_quad + v37));
          v132 = v57;
          p_m_scale[-2].m_quad = _mm_add_ps(
                                   _mm_mul_ps(v58, alpha->m_real),
                                   *(__m128 *)((char *)&p_m_scale[-2].m_quad + v37));
          hkQuaternionf::setSlerp(
            (hkQuaternionf *)&p_m_scale[-1],
            (hkQuaternionf *)((char *)&p_m_scale[-1] + v37),
            &q1,
            alpha);
          p_m_scale += 3;
          p_m_rotation += 3;
          p_m_scale[-3].m_quad = _mm_add_ps(
                                   _mm_mul_ps(
                                     _mm_sub_ps(v132, *(__m128 *)((char *)&p_m_scale[-3].m_quad + v37)),
                                     alpha->m_real),
                                   *(__m128 *)((char *)&p_m_scale[-3].m_quad + v37));
          --v38;
        }
        while ( v38 );
      }
    }
    else if ( v136 )
    {
      if ( v136 == 1 && (int)retaddr > 0 )
      {
        m_real = alpha->m_real;
        v11 = (char *)srcR - (char *)srcL;
        v12 = &dst->m_scale;
        v13 = (char *)srcL - (char *)dst;
        v14 = &srcL->m_rotation;
        do
        {
          v15 = *(__m128 *)((char *)&v14[-1].m_vec.m_quad + v11);
          v16 = _mm_mul_ps(v15, v14->m_vec.m_quad);
          v17 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v14->m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v14->m_vec.m_quad, v14->m_vec.m_quad, 201), v15));
          v18 = _mm_shuffle_ps(v14->m_vec.m_quad, v14->m_vec.m_quad, 255);
          v19 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v18, v18), (__m128)xmmword_141A711B0), v15);
          v20 = *(__m128 *)((char *)&v14->m_vec.m_quad + v11);
          v21 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                        _mm_shuffle_ps(v16, v16, 170)),
                      v14->m_vec.m_quad),
                    v19),
                  _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v18));
          v22 = _mm_shuffle_ps(v20, v20, 255);
          v23 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v14->m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v14->m_vec.m_quad, v14->m_vec.m_quad, 201), v20));
          v24 = _mm_mul_ps(v18, v20);
          v25 = _mm_mul_ps(v20, v14->m_vec.m_quad);
          v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 201), v24), _mm_mul_ps(v22, v14->m_vec.m_quad));
          v12[-2].m_quad = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_sub_ps(
                                 _mm_add_ps(_mm_add_ps(v21, v21), v14[-1].m_vec.m_quad),
                                 *(__m128 *)((char *)&v12[-2].m_quad + v13)),
                               m_real),
                             *(__m128 *)((char *)&v12[-2].m_quad + v13));
          v27 = _mm_mul_ps(*(__m128 *)((char *)&v14[1].m_vec.m_quad + v11), v14[1].m_vec.m_quad);
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
          v132 = v27;
          hkQuaternionf::setSlerp((hkQuaternionf *)&v12[-1], (hkQuaternionf *)((char *)&v12[-1] + v13), &q1, alpha);
          m_real = alpha->m_real;
          v12->m_quad = _mm_add_ps(
                          _mm_mul_ps(_mm_sub_ps(v132, *(__m128 *)((char *)&v12->m_quad + v13)), alpha->m_real),
                          *(__m128 *)((char *)&v12->m_quad + v13));
          v12 += 3;
          v14 += 3;
          --v9;
        }
        while ( v9 );
      }
    }
    else if ( (int)retaddr > 0 )
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
          alpha);
        v34 = *(__m128 *)((char *)&v29->m_quad + v32);
        v29 += 3;
        v28 = alpha->m_real;
        *(__m128 *)((char *)&v29[-3].m_quad + v31) = _mm_add_ps(
                                                       _mm_mul_ps(_mm_sub_ps(v34, v29[-3].m_quad), alpha->m_real),
                                                       v29[-3].m_quad);
        --v33;
      }
      while ( v33 );
    }
  }
  else if ( v136 == -1 )
  {
    if ( (int)retaddr > 0 )
    {
      v98 = (char *)dst - (char *)srcR;
      v99 = &srcL->m_rotation;
      v100 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
      v101 = (char *)srcR - (char *)srcL;
      v102 = (unsigned int)retaddr;
      v103 = (__m128)_mm_shuffle_epi32(v100, 0);
      v104 = (__m128)_mm_shuffle_epi32(v100, 64);
      do
      {
        v105 = (char *)v99 + v101;
        hkVector4f::setRotatedInverseDir(
          &v133,
          (hkQuaternionf *)((char *)v99 + v101),
          (hkVector4f *)((char *)&v99[-1].m_vec + v101));
        m_quad = v99->m_vec.m_quad;
        v107 = _mm_rcp_ps(*(__m128 *)((char *)&v99[1].m_vec.m_quad + v101));
        v108 = v99[-1].m_vec.m_quad;
        v109 = _mm_xor_ps(v103, v133.m_quad);
        v110 = _mm_xor_ps(v104, *(__m128 *)((char *)&v99->m_vec.m_quad + v101));
        v111 = (__m128)_mm_srli_si128(
                         _mm_slli_si128(
                           (__m128i)_mm_mul_ps(
                                      _mm_sub_ps(
                                        (__m128)_xmm,
                                        _mm_mul_ps(v107, *(__m128 *)((char *)&v99[1].m_vec.m_quad + v101))),
                                      v107),
                           4),
                         4);
        v112 = _mm_mul_ps(v99->m_vec.m_quad, v109);
        v113 = _mm_shuffle_ps(v99->m_vec.m_quad, v99->m_vec.m_quad, 255);
        v114 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v109, v109, 201), v99->m_vec.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v109));
        v115 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v113, v113), (__m128)xmmword_141A711B0), v109);
        v116 = _mm_shuffle_ps(v110, v110, 255);
        v117 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v112, v112, 85), _mm_shuffle_ps(v112, v112, 0)),
                       _mm_shuffle_ps(v112, v112, 170)),
                     v99->m_vec.m_quad),
                   v115),
                 _mm_mul_ps(_mm_shuffle_ps(v114, v114, 201), v113));
        v118 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v110, v110, 201), v99->m_vec.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(v99->m_vec.m_quad, v99->m_vec.m_quad, 201), v110));
        v119 = v110;
        v120 = _mm_mul_ps(v110, v99->m_vec.m_quad);
        v121 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v118, v118, 201), _mm_mul_ps(v119, v113)),
                 _mm_mul_ps(v99->m_vec.m_quad, v116));
        v122 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v120, v120, 85), _mm_shuffle_ps(v120, v120, 0)),
                 _mm_shuffle_ps(v120, v120, 170));
        v123 = v99[1].m_vec.m_quad;
        v124 = _mm_shuffle_ps(v121, _mm_unpackhi_ps(v121, _mm_sub_ps(_mm_mul_ps(v116, v113), v122)), 196);
        v125 = v99->m_vec.m_quad;
        v99 += 3;
        v126 = _mm_mul_ps(v125, v124);
        v127 = _mm_shuffle_ps((__m128)alpha->m_real.m128_u32[0], (__m128)alpha->m_real.m128_u32[0], 0);
        v128 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v123, v111), v123), alpha->m_real);
        *(__m128 *)&v105[v98 - 16] = _mm_add_ps(
                                       _mm_mul_ps(
                                         _mm_sub_ps(_mm_add_ps(_mm_add_ps(v117, v117), v108), v108),
                                         alpha->m_real),
                                       v108);
        v129 = _mm_add_ps(_mm_shuffle_ps(v126, v126, 78), v126);
        *(__m128 *)&v105[v98 + 16] = _mm_add_ps(v128, v123);
        *(__m128 *)&v105[v98] = _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_xor_ps(
                                      (__m128)_mm_slli_epi32(
                                                _mm_srli_epi32(
                                                  (__m128i)_mm_cmplt_ps(
                                                             _mm_add_ps(_mm_shuffle_ps(v129, v129, 177), v129),
                                                             (__m128)0i64),
                                                  0x1Fu),
                                                0x1Fu),
                                      _mm_sub_ps(query.m_quad, v127)),
                                    m_quad),
                                  _mm_mul_ps(v124, v127));
        --v102;
      }
      while ( v102 );
    }
  }
  else if ( v136 )
  {
    if ( v136 == 1 && (int)retaddr > 0 )
    {
      v59 = alpha->m_real;
      v60 = (char *)dst - (char *)srcL;
      v61 = &srcL->m_rotation;
      v62 = (char *)srcR - (char *)srcL;
      v63 = (unsigned int)retaddr;
      v64 = _mm_shuffle_ps((__m128)alpha->m_real.m128_u32[0], (__m128)alpha->m_real.m128_u32[0], 0);
      v65 = _mm_sub_ps(query.m_quad, v64);
      do
      {
        v66 = v61->m_vec.m_quad;
        v67 = *(__m128 *)((char *)&v61[-1].m_vec.m_quad + v62);
        v68 = _mm_mul_ps(v67, v61->m_vec.m_quad);
        v69 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v67, v67, 201), v61->m_vec.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v66, v66, 201), v67));
        v70 = _mm_shuffle_ps(v61->m_vec.m_quad, v61->m_vec.m_quad, 255);
        v71 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v70, v70), (__m128)xmmword_141A711B0), v67);
        v72 = *(__m128 *)((char *)&v61->m_vec.m_quad + v62);
        v73 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)),
                      _mm_shuffle_ps(v68, v68, 170)),
                    v61->m_vec.m_quad),
                  v71),
                _mm_mul_ps(_mm_shuffle_ps(v69, v69, 201), v70));
        v74 = _mm_shuffle_ps(v72, v72, 255);
        v75 = _mm_mul_ps(v74, v61->m_vec.m_quad);
        v76 = _mm_mul_ps(v61->m_vec.m_quad, v72);
        v77 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v72, v72, 201), v61->m_vec.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v61->m_vec.m_quad, v61->m_vec.m_quad, 201), v72));
        v78 = _mm_mul_ps(v70, v72);
        v79 = v61[1].m_vec.m_quad;
        *(__m128 *)((char *)&v61[-1].m_vec.m_quad + v60) = _mm_add_ps(
                                                             _mm_mul_ps(
                                                               _mm_sub_ps(
                                                                 _mm_add_ps(_mm_add_ps(v73, v73), v61[-1].m_vec.m_quad),
                                                                 v61[-1].m_vec.m_quad),
                                                               v59),
                                                             v61[-1].m_vec.m_quad);
        v80 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v77, v77, 201), v78), v75);
        v81 = _mm_shuffle_ps(
                v80,
                _mm_unpackhi_ps(
                  v80,
                  _mm_sub_ps(
                    _mm_mul_ps(v74, v70),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v76, v76, 85), _mm_shuffle_ps(v76, v76, 0)),
                      _mm_shuffle_ps(v76, v76, 170)))),
                196);
        v82 = _mm_mul_ps(v66, v81);
        v83 = _mm_add_ps(_mm_shuffle_ps(v82, v82, 78), v82);
        v84 = _mm_sub_ps(_mm_mul_ps(*(__m128 *)((char *)&v61[1].m_vec.m_quad + v62), v79), v79);
        v61 += 3;
        *(__m128 *)((char *)&v61[-2].m_vec.m_quad + v60) = _mm_add_ps(_mm_mul_ps(v84, v59), v79);
        *(__m128 *)((char *)&v61[-3].m_vec.m_quad + v60) = _mm_add_ps(
                                                             _mm_mul_ps(
                                                               _mm_xor_ps(
                                                                 (__m128)_mm_slli_epi32(
                                                                           _mm_srli_epi32(
                                                                             (__m128i)_mm_cmplt_ps(
                                                                                        _mm_add_ps(
                                                                                          _mm_shuffle_ps(v83, v83, 177),
                                                                                          v83),
                                                                                        (__m128)0i64),
                                                                             0x1Fu),
                                                                           0x1Fu),
                                                                 v65),
                                                               v66),
                                                             _mm_mul_ps(v81, v64));
        --v63;
      }
      while ( v63 );
    }
  }
  else
  {
    v85 = (unsigned int)retaddr;
    if ( (int)retaddr > 0 )
    {
      v86 = alpha->m_real;
      v87 = (char *)dst - (char *)srcL;
      v88 = &srcL->m_rotation;
      v89 = (char *)srcR - (char *)srcL;
      v90 = _mm_shuffle_ps((__m128)alpha->m_real.m128_u32[0], (__m128)alpha->m_real.m128_u32[0], 0);
      v91 = _mm_sub_ps(query.m_quad, v90);
      do
      {
        v92 = *(__m128 *)((char *)&v88[-1].m_vec.m_quad + v89);
        v93 = *(__m128 *)((char *)&v88->m_vec.m_quad + v89);
        v88 += 3;
        v94 = _mm_mul_ps(v93, v88[-3].m_vec.m_quad);
        *(__m128 *)((char *)&v88[-4].m_vec.m_quad + v87) = _mm_add_ps(
                                                             _mm_mul_ps(_mm_sub_ps(v92, v88[-4].m_vec.m_quad), v86),
                                                             v88[-4].m_vec.m_quad);
        v95 = _mm_add_ps(_mm_shuffle_ps(v94, v94, 78), v94);
        v96 = _mm_mul_ps(v90, *(__m128 *)((char *)&v88[-3].m_vec.m_quad + v89));
        v97 = _mm_mul_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32(
                              (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v95, v95, 177), v95), (__m128)0i64),
                              0x1Fu),
                            0x1Fu),
                  v91),
                v88[-3].m_vec.m_quad);
        *(__m128 *)((char *)&v88[-2].m_vec.m_quad + v87) = _mm_add_ps(
                                                             _mm_mul_ps(
                                                               _mm_sub_ps(
                                                                 *(__m128 *)((char *)&v88[-2].m_vec.m_quad + v89),
                                                                 v88[-2].m_vec.m_quad),
                                                               v86),
                                                             v88[-2].m_vec.m_quad);
        *(__m128 *)((char *)&v88[-3].m_vec.m_quad + v87) = _mm_add_ps(v97, v96);
        --v85;
      }
      while ( v85 );
    }
  }
}

// File Line: 273
// RVA: 0xB40680
void __fastcall hkaBlender::blend(
        float *dst,
        float *weightsOut,
        const float *srcL,
        const float *weightsL,
        const float *srcR,
        const float *weightsR,
        hkSimdFloat32 *alphaIn,
        unsigned int n,
        hkaBlender::BLEND_MODE blendMode)
{
  const float *v9; // rdi
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
  __m128 m_real; // xmm6
  __int64 v40; // r14
  signed __int64 v41; // rsi
  signed __int64 v42; // rdi

  v9 = srcL;
  if ( blendMode == -1 )
  {
    if ( (int)n > 0 )
    {
      v37 = weightsR;
      v38 = srcR;
      m_real = alphaIn->m_real;
      v40 = n;
      memmove(weightsOut, weightsL, 4i64 * n);
      v41 = (char *)dst - (char *)srcR;
      v42 = (char *)v9 - (char *)srcR;
      do
      {
        ++v38;
        ++v37;
        *(float *)((char *)v38 + v41 - 4) = _mm_shuffle_ps(
                                              (__m128)*(unsigned int *)((char *)v38 + v42 - 4),
                                              (__m128)*(unsigned int *)((char *)v38 + v42 - 4),
                                              0).m128_f32[0]
                                          - (float)(_mm_shuffle_ps(
                                                      (__m128)COERCE_UNSIGNED_INT(m_real.m128_f32[0] * *(v37 - 1)),
                                                      (__m128)COERCE_UNSIGNED_INT(m_real.m128_f32[0] * *(v37 - 1)),
                                                      0).m128_f32[0]
                                                  * _mm_shuffle_ps(
                                                      (__m128)*((unsigned int *)v38 - 1),
                                                      (__m128)*((unsigned int *)v38 - 1),
                                                      0).m128_f32[0]);
        --v40;
      }
      while ( v40 );
    }
  }
  else if ( blendMode )
  {
    if ( blendMode == ADD && (int)n > 0 )
    {
      v11 = weightsR;
      v12 = srcR;
      v13 = alphaIn->m_real;
      v14 = n;
      memmove(weightsOut, weightsL, 4i64 * n);
      v15 = (char *)dst - (char *)srcR;
      v16 = (char *)v9 - (char *)srcR;
      do
      {
        ++v12;
        ++v11;
        *(float *)((char *)v12 + v15 - 4) = (float)(_mm_shuffle_ps(
                                                      (__m128)COERCE_UNSIGNED_INT(v13.m128_f32[0] * *(v11 - 1)),
                                                      (__m128)COERCE_UNSIGNED_INT(v13.m128_f32[0] * *(v11 - 1)),
                                                      0).m128_f32[0]
                                                  * _mm_shuffle_ps(
                                                      (__m128)*((unsigned int *)v12 - 1),
                                                      (__m128)*((unsigned int *)v12 - 1),
                                                      0).m128_f32[0])
                                          + _mm_shuffle_ps(
                                              (__m128)*(unsigned int *)((char *)v12 + v16 - 4),
                                              (__m128)*(unsigned int *)((char *)v12 + v16 - 4),
                                              0).m128_f32[0];
        --v14;
      }
      while ( v14 );
    }
  }
  else if ( (int)n > 0 )
  {
    v17 = (char *)weightsOut - (char *)srcL;
    v18 = (char *)dst - (char *)srcL;
    v19 = (char *)srcR - (char *)srcL;
    v20 = (char *)weightsR - (char *)weightsL;
    v21 = n;
    v22 = _mm_shuffle_ps((__m128)alphaIn->m_real.m128_u32[0], (__m128)alphaIn->m_real.m128_u32[0], 0);
    v23 = _mm_sub_ps(query.m_quad, v22);
    do
    {
      v24 = *(_DWORD *)((char *)weightsL + v20);
      v25 = *(_DWORD *)weightsL;
      ++v9;
      ++weightsL;
      v26 = _mm_shuffle_ps((__m128)v25, (__m128)v25, 0);
      v27 = _mm_cmplt_ps((__m128)0i64, v26);
      v28 = _mm_shuffle_ps((__m128)v24, (__m128)v24, 0);
      v29 = _mm_rcp_ps(v28);
      v30 = _mm_cmplt_ps((__m128)0i64, v28);
      v31 = _mm_cmplt_ps(v28, v26);
      v32 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v28, v29)), v29);
      v29.m128_f32[0] = _mm_rcp_ps(v26).m128_f32[0];
      v33 = _mm_mul_ps(v23, _mm_mul_ps(v32, v26));
      v32.m128_f32[0] = _mm_shuffle_ps((__m128)*((unsigned int *)v9 - 1), (__m128)*((unsigned int *)v9 - 1), 0).m128_f32[0];
      LODWORD(v34) = COERCE_UNSIGNED_INT(
                       (float)((float)((float)(2.0 - (float)(v26.m128_f32[0] * v29.m128_f32[0])) * v29.m128_f32[0])
                             * v28.m128_f32[0])
                     * v22.m128_f32[0]) & v31.m128_i32[0] | _mm_andnot_ps(v31, _mm_sub_ps(query.m_quad, v33)).m128_u32[0];
      v35 = _mm_andnot_ps(v30, aabbOut.m_quad);
      v36 = _mm_andnot_ps(v30, v26);
      v29.m128_i32[0] = (COERCE_UNSIGNED_INT((float)((float)(1.0 - v34) * v26.m128_f32[0]) + (float)(v34 * v28.m128_f32[0])) & v30.m128_i32[0] | v36.m128_i32[0]) & v27.m128_i32[0];
      v36.m128_i32[0] = _mm_andnot_ps(v27, _mm_or_ps(_mm_andnot_ps(v30, v22), _mm_and_ps(v30, query.m_quad))).m128_u32[0] | (LODWORD(v34) & v30.m128_i32[0] | v35.m128_i32[0]) & v27.m128_i32[0];
      *(_DWORD *)((char *)v9 + v17 - 4) = v29.m128_i32[0] | _mm_andnot_ps(v27, _mm_or_ps(_mm_and_ps(v28, v30), v35)).m128_u32[0];
      *(float *)((char *)v9 + v18 - 4) = (float)((float)(_mm_shuffle_ps(
                                                           (__m128)*(unsigned int *)((char *)v9 + v19 - 4),
                                                           (__m128)*(unsigned int *)((char *)v9 + v19 - 4),
                                                           0).m128_f32[0]
                                                       - v32.m128_f32[0])
                                               * _mm_shuffle_ps(v36, v36, 0).m128_f32[0])
                                       + v32.m128_f32[0];
      --v21;
    }
    while ( v21 );
  }
}

// File Line: 320
// RVA: 0xB40A70
void __fastcall hkaBlender::blend(
        hkVector4f *dst,
        float *weightsOut,
        hkVector4f *srcL,
        const float *weightsL,
        hkVector4f *srcR,
        const float *weightsR,
        hkSimdFloat32 *alphaIn,
        int n,
        hkaBlender::BLEND_MODE blendMode)
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
  __m128 v20; // xmm10
  __m128 v21; // xmm1
  __m128 v22; // xmm6
  __m128 v23; // xmm8
  __m128 v24; // xmm9
  __m128 v25; // xmm4
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  float v28; // xmm5_4
  __m128 v29; // xmm4
  __m128 v30; // xmm0
  unsigned int v31; // xmm7_4
  __m128 v32; // xmm2
  signed __int64 v33; // r11
  signed __int64 v34; // rbx
  signed __int64 v35; // rdx
  signed __int64 v36; // rcx
  int v37; // eax
  unsigned int v38; // xmm0_4
  unsigned int v39; // [rsp+8h] [rbp-80h]

  v9 = (unsigned int)n;
  v10 = n;
  if ( blendMode == -1 )
  {
    if ( n > 0 )
    {
      v33 = (char *)weightsR - (char *)weightsL;
      v34 = (char *)srcR - (char *)srcL;
      v35 = (char *)weightsOut - (char *)weightsL;
      v36 = (char *)dst - (char *)srcL;
      do
      {
        v37 = *(_DWORD *)weightsL;
        ++srcL;
        *(float *)&v38 = COERCE_FLOAT(*alphaIn) * *(const float *)((char *)++weightsL + v33 - 4);
        *(_DWORD *)((char *)weightsL + v35 - 4) = v37;
        *(__m128 *)((char *)&srcL[-1].m_quad + v36) = _mm_sub_ps(
                                                        srcL[-1].m_quad,
                                                        _mm_mul_ps(
                                                          _mm_shuffle_ps((__m128)v38, (__m128)v38, 0),
                                                          *(__m128 *)((char *)&srcL[-1].m_quad + v34)));
        --v10;
      }
      while ( v10 );
    }
  }
  else if ( blendMode )
  {
    if ( blendMode == ADD && n > 0 )
    {
      v11 = (char *)weightsR - (char *)weightsL;
      v12 = (char *)srcR - (char *)srcL;
      v13 = (char *)weightsOut - (char *)weightsL;
      v14 = (char *)dst - (char *)srcL;
      do
      {
        v15 = *(_DWORD *)weightsL;
        ++srcL;
        *(float *)&v16 = COERCE_FLOAT(*alphaIn) * *(const float *)((char *)++weightsL + v11 - 4);
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
      v39 = *(_DWORD *)((char *)weightsL + v17);
      ++srcL;
      ++weightsOut;
      ++weightsL;
      --v9;
      v20 = _mm_shuffle_ps((__m128)v39, (__m128)v39, 0);
      v21 = _mm_rcp_ps(v20);
      v22 = _mm_shuffle_ps((__m128)alphaIn->m_real.m128_u32[0], (__m128)alphaIn->m_real.m128_u32[0], 0);
      v23 = _mm_cmplt_ps((__m128)0i64, v20);
      v24 = _mm_shuffle_ps((__m128)*((unsigned int *)weightsL - 1), (__m128)*((unsigned int *)weightsL - 1), 0);
      v25 = _mm_cmplt_ps(v20, v24);
      v26 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v20, v21)), v21);
      v21.m128_f32[0] = _mm_rcp_ps(v24).m128_f32[0];
      v27 = _mm_andnot_ps(v23, aabbOut.m_quad);
      LODWORD(v28) = COERCE_UNSIGNED_INT(
                       (float)((float)((float)(2.0 - (float)(v24.m128_f32[0] * v21.m128_f32[0])) * v21.m128_f32[0])
                             * v20.m128_f32[0])
                     * v22.m128_f32[0]) & v25.m128_i32[0] | _mm_andnot_ps(
                                                              v25,
                                                              _mm_sub_ps(
                                                                query.m_quad,
                                                                _mm_mul_ps(
                                                                  _mm_sub_ps(query.m_quad, v22),
                                                                  _mm_mul_ps(v26, v24)))).m128_u32[0];
      v29 = _mm_cmplt_ps((__m128)0i64, v24);
      v30 = _mm_andnot_ps(v23, v24);
      v31 = COERCE_UNSIGNED_INT((float)((float)(1.0 - v28) * v24.m128_f32[0]) + (float)(v28 * v20.m128_f32[0])) & v23.m128_i32[0] | v30.m128_i32[0];
      v30.m128_i32[0] = _mm_andnot_ps(v29, _mm_or_ps(_mm_andnot_ps(v23, v22), _mm_and_ps(v23, query.m_quad))).m128_u32[0] | (LODWORD(v28) & v23.m128_i32[0] | v27.m128_i32[0]) & v29.m128_i32[0];
      v32 = _mm_mul_ps(
              _mm_sub_ps(*(__m128 *)((char *)&srcL[-1].m_quad + v18), srcL[-1].m_quad),
              _mm_shuffle_ps(v30, v30, 0));
      *((_DWORD *)weightsOut - 1) = v31 & v29.m128_i32[0] | _mm_andnot_ps(v29, _mm_or_ps(_mm_and_ps(v20, v23), v27)).m128_u32[0];
      *(__m128 *)((char *)&srcL[-1].m_quad + v19) = _mm_add_ps(v32, srcL[-1].m_quad);
    }
    while ( v9 );
  }
}

// File Line: 358
// RVA: 0xB40DC0
void __fastcall hkaBlender::blend(
        hkQuaternionf *dst,
        float *weightsOut,
        hkQuaternionf *srcL,
        const float *weightsL,
        hkQuaternionf *srcR)
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
  unsigned int v83; // xmm10_4
  __m128 v84; // xmm0
  __m128 v85; // xmm1
  __m128 v86; // xmm3
  signed __int64 v87; // rsi
  __m128 m_quad; // xmm2
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
  hkQuaternionf q1; // [rsp+28h] [rbp-79h] BYREF
  hkSimdFloat32 t; // [rsp+40h] [rbp-61h] BYREF
  _BYTE *retaddr; // [rsp+F8h] [rbp+57h]
  __int64 v105; // [rsp+100h] [rbp+5Fh]
  _OWORD *v106; // [rsp+108h] [rbp+67h]
  int v107; // [rsp+110h] [rbp+6Fh]
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
          v16 = _mm_shuffle_ps(v14, v14, 255);
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
        v28 = _mm_cmplt_ps((__m128)0i64, v25);
        v29 = _mm_shuffle_ps((__m128)*(unsigned int *)v5, (__m128)*(unsigned int *)v5, 0);
        v30 = _mm_cmplt_ps(v25, v29);
        v31 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v26, v25)), v26);
        v26.m128_f32[0] = _mm_rcp_ps(v29).m128_f32[0];
        v32 = _mm_andnot_ps(v28, aabbOut.m_quad);
        LODWORD(v33) = COERCE_UNSIGNED_INT(
                         v27.m128_f32[0]
                       * (float)((float)((float)(2.0 - (float)(v29.m128_f32[0] * v26.m128_f32[0])) * v26.m128_f32[0])
                               * v25.m128_f32[0])) & v30.m128_i32[0] | _mm_andnot_ps(
                                                                         v30,
                                                                         _mm_sub_ps(
                                                                           query.m_quad,
                                                                           _mm_mul_ps(
                                                                             _mm_sub_ps(query.m_quad, v27),
                                                                             _mm_mul_ps(v31, v29)))).m128_u32[0];
        v34 = _mm_cmplt_ps((__m128)0i64, v29);
        v35 = _mm_andnot_ps(v28, v29);
        v36 = COERCE_UNSIGNED_INT((float)((float)(1.0 - v33) * v29.m128_f32[0]) + (float)(v25.m128_f32[0] * v33)) & v28.m128_i32[0] | v35.m128_i32[0];
        v35.m128_i32[0] = _mm_andnot_ps(v34, _mm_or_ps(_mm_and_ps(v28, query.m_quad), _mm_andnot_ps(v28, v27))).m128_u32[0] | (v28.m128_i32[0] & LODWORD(v33) | v32.m128_i32[0]) & v34.m128_i32[0];
        q1.m_vec.m_quad = _mm_shuffle_ps(v35, v35, 0);
        *(_DWORD *)v7 = v36 & v34.m128_i32[0] | _mm_andnot_ps(v34, _mm_or_ps(_mm_and_ps(v28, v25), v32)).m128_u32[0];
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
          m_quad = v6->m_vec.m_quad;
          v89 = *(__m128 *)((char *)&v6->m_vec.m_quad + retaddr - (_BYTE *)srcL);
          v90 = *(_DWORD *)v5;
          ++v6;
          *(float *)&v91 = COERCE_FLOAT(*v106) * *(const float *)((char *)++v5 + v105 - (_QWORD)weightsL - 4);
          *(_DWORD *)((char *)v5 + (char *)weightsOut - (char *)weightsL - 4) = v90;
          v92 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v89),
                  _mm_mul_ps(_mm_shuffle_ps(v89, v89, 201), m_quad));
          v93 = _mm_mul_ps(_mm_shuffle_ps(v89, v89, 255), m_quad);
          v94 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 255), v89);
          v95 = _mm_mul_ps(v89, m_quad);
          v96 = _mm_add_ps(_mm_sub_ps(_mm_shuffle_ps(v92, v92, 201), v94), v93);
          v97 = _mm_add_ps(_mm_shuffle_ps(v95, v95, 78), v95);
          v98 = _mm_shuffle_ps((__m128)v91, (__m128)v91, 0);
          v99 = _mm_shuffle_ps(v96, _mm_unpackhi_ps(v96, _mm_add_ps(_mm_shuffle_ps(v97, v97, 177), v97)), 196);
          v100 = _mm_mul_ps(m_quad, v99);
          v101 = _mm_add_ps(_mm_shuffle_ps(v100, v100, 78), v100);
          *(__m128 *)((char *)&v6[-1].m_vec.m_quad + v87) = _mm_add_ps(
                                                              _mm_mul_ps(
                                                                _mm_xor_ps(
                                                                  (__m128)_mm_slli_epi32(
                                                                            _mm_srli_epi32(
                                                                              (__m128i)_mm_cmplt_ps(
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
                                                                m_quad),
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
                                                                              (__m128i)_mm_cmplt_ps(
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
        v74 = _mm_cmplt_ps((__m128)0i64, v71);
        v75 = _mm_shuffle_ps((__m128)*(unsigned int *)v5, (__m128)*(unsigned int *)v5, 0);
        v76 = _mm_cmplt_ps(v71, v75);
        v77 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v72, v71)), v72);
        v72.m128_f32[0] = _mm_rcp_ps(v75).m128_f32[0];
        v78 = _mm_andnot_ps(v74, aabbOut.m_quad);
        LODWORD(v79) = COERCE_UNSIGNED_INT(
                         (float)((float)((float)(2.0 - (float)(v72.m128_f32[0] * v75.m128_f32[0])) * v72.m128_f32[0])
                               * v71.m128_f32[0])
                       * v73.m128_f32[0]) & v76.m128_i32[0] | _mm_andnot_ps(
                                                                v76,
                                                                _mm_sub_ps(
                                                                  v66,
                                                                  _mm_mul_ps(_mm_sub_ps(v66, v73), _mm_mul_ps(v77, v75)))).m128_u32[0];
        v80 = _mm_cmplt_ps((__m128)0i64, v75);
        v77.m128_f32[0] = _mm_andnot_ps(v80, _mm_or_ps(_mm_andnot_ps(v74, v73), _mm_and_ps(v74, v66))).m128_f32[0];
        LODWORD(v70) = v74.m128_i32[0] & LODWORD(v79) | v78.m128_i32[0];
        v81 = (float)((float)(v66.m128_f32[0] - v79) * v75.m128_f32[0]) + (float)(v79 * v71.m128_f32[0]);
        v82 = *(__m128 *)&v68[(_QWORD)v6];
        q1.m_vec.m_quad.m128_i32[2] = v77.m128_i32[0] | v70 & v80.m128_i32[0];
        v83 = (LODWORD(v81) & v74.m128_i32[0] | _mm_andnot_ps(v74, v75).m128_u32[0]) & v80.m128_i32[0];
        v84 = _mm_mul_ps(v82, v6->m_vec.m_quad);
        v80.m128_f32[0] = _mm_andnot_ps(v80, _mm_or_ps(_mm_and_ps(v74, v71), v78)).m128_f32[0];
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
                                                                            (__m128i)_mm_cmplt_ps(
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
}

// File Line: 439
// RVA: 0xB41600
void __fastcall hkaBlender::blend(
        hkQsTransformf *dst,
        float *weightsOut,
        hkQsTransformf *srcL,
        const float *weightsL,
        hkQsTransformf *srcR,
        const float *weightsR,
        hkSimdFloat32 *alphaIn,
        int n,
        hkaBlender::BLEND_MODE blendMode,
        hkaBlender::ROTATION_MODE rotationMode)
{
  float *v10; // rdi
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
  __m128 v27; // xmm0
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  __m128 v30; // xmm8
  __m128 v31; // xmm3
  __m128 v32; // xmm5
  __m128 v33; // xmm3
  __m128 v34; // xmm0
  signed __int64 v35; // rsi
  signed __int64 v36; // r14
  signed __int64 v37; // r15
  signed __int64 v38; // r12
  hkVector4f *p_m_scale; // rbx
  __int64 v40; // r13
  __m128 v41; // xmm10
  __m128 v42; // xmm1
  __m128 v43; // xmm6
  __m128 v44; // xmm8
  __m128 v45; // xmm9
  __m128 v46; // xmm4
  __m128 v47; // xmm2
  __m128 v48; // xmm1
  __m128 v49; // xmm3
  __m128 v50; // xmm5
  __m128 v51; // xmm4
  __m128 v52; // xmm2
  __m128 v53; // xmm2
  __m128 v54; // xmm1
  bool v55; // zf
  signed __int64 v56; // r14
  __m128i inserted; // xmm0
  signed __int64 v58; // rsi
  __int64 v59; // r13
  hkQuaternionf *p_m_rotation; // r15
  signed __int64 v61; // r12
  __m128 v62; // xmm10
  __m128 v63; // xmm11
  char *v64; // rbx
  __m128 m_quad; // xmm2
  __m128 v66; // xmm0
  __m128 v67; // xmm1
  __m128 v68; // xmm4
  __m128 v69; // xmm5
  __m128 v70; // xmm8
  __m128 v71; // xmm9
  __m128 v72; // xmm1
  __m128 v73; // xmm3
  __m128 v74; // xmm6
  __m128 v75; // xmm7
  __m128 v76; // xmm3
  __m128 v77; // xmm4
  __m128 v78; // xmm0
  __m128 v79; // xmm8
  __m128 v80; // xmm4
  __m128 v81; // xmm7
  hkQuaternionf *v82; // rcx
  signed __int64 v83; // rdx
  signed __int64 v84; // rsi
  char *v85; // r14
  __int64 v86; // r9
  __int64 v87; // r8
  __m128 v88; // xmm10
  __m128 v89; // xmm2
  __m128 v90; // xmm7
  __m128 v91; // xmm1
  __m128 v92; // xmm5
  __m128 v93; // xmm3
  __m128 v94; // xmm0
  __m128 v95; // xmm2
  __m128 v96; // xmm9
  __m128 v97; // xmm4
  __m128 v98; // xmm1
  __m128 v99; // xmm3
  __m128 v100; // xmm4
  __m128 v101; // xmm8
  __m128 v102; // xmm0
  __m128 v103; // xmm5
  __m128 v104; // xmm6
  __m128 v105; // xmm8
  __m128 v106; // xmm8
  __m128 v107; // xmm4
  __m128 v108; // xmm0
  __m128 v109; // xmm3
  __m128 v110; // xmm1
  __m128 v111; // xmm10
  signed __int64 v112; // r14
  signed __int64 v113; // rsi
  signed __int64 v114; // rcx
  hkQuaternionf *v115; // rax
  __int64 v116; // r8
  __int64 v117; // rdx
  __int128 v118; // xmm0
  __m128 v119; // xmm8
  __m128 v120; // xmm1
  __m128 v121; // xmm6
  __m128 v122; // xmm9
  __m128 v123; // xmm7
  __m128 v124; // xmm4
  __m128 v125; // xmm2
  __m128 v126; // xmm3
  float v127; // xmm5_4
  __m128 v128; // xmm4
  __m128 v129; // xmm6
  __m128 v130; // xmm0
  __m128 v131; // xmm3
  __m128 v132; // xmm1
  __m128 v133; // xmm0
  __m128 v134; // xmm3
  __m128 v135; // xmm2
  unsigned __int64 v136; // r15
  __m128i v137; // xmm0
  signed __int64 v138; // r14
  signed __int64 v139; // rsi
  __int64 v140; // r12
  hkQuaternionf *v141; // r13
  __m128 v142; // xmm11
  __m128 v143; // xmm12
  unsigned __int64 v144; // r15
  char *v145; // rbx
  __m128 v146; // xmm9
  __m128 v147; // xmm0
  __m128 v148; // xmm1
  __m128 v149; // xmm3
  __m128 v150; // xmm6
  __m128 v151; // xmm5
  __m128 v152; // xmm10
  __m128 v153; // xmm1
  __m128 v154; // xmm2
  __m128 v155; // xmm4
  __m128 v156; // xmm0
  __m128 v157; // xmm3
  __m128 v158; // xmm8
  __m128 v159; // xmm7
  __m128 v160; // xmm0
  __m128 v161; // xmm5
  __m128 v162; // xmm7
  __m128 v163; // xmm1
  __m128 v164; // xmm5
  __m128 v165; // xmm7
  __m128 v166; // xmm4
  __m128 v167; // xmm0
  __m128 v168; // xmm4
  __m128 v169; // xmm3
  __m128 v170; // xmm1
  hkSimdFloat32 t; // [rsp+20h] [rbp-B8h] BYREF
  __m128 v172; // [rsp+30h] [rbp-A8h]
  hkQuaternionf q1; // [rsp+40h] [rbp-98h] BYREF
  __m128 v174; // [rsp+50h] [rbp-88h]
  hkVector4f v175; // [rsp+60h] [rbp-78h] BYREF
  __int64 v176; // [rsp+128h] [rbp+50h]
  unsigned __int64 retaddr; // [rsp+148h] [rbp+70h]
  __int64 v178; // [rsp+150h] [rbp+78h]
  _OWORD *v179; // [rsp+158h] [rbp+80h]
  int v180; // [rsp+160h] [rbp+88h]
  int v181; // [rsp+168h] [rbp+90h]
  unsigned int srcRa; // [rsp+170h] [rbp+98h]
  unsigned int srcRb; // [rsp+170h] [rbp+98h]

  v10 = weightsOut;
  if ( (_DWORD)srcR == 1 )
  {
    if ( v181 == -1 )
    {
      if ( v180 > 0 )
      {
        v56 = (char *)weightsL - (char *)weightsOut;
        inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
        v58 = (signed __int64)dst - retaddr;
        v59 = v178 - (_QWORD)weightsOut;
        p_m_rotation = &srcL->m_rotation;
        v61 = retaddr - (_QWORD)srcL;
        retaddr = (unsigned int)v180;
        v62 = (__m128)_mm_shuffle_epi32(inserted, 0);
        v63 = (__m128)_mm_shuffle_epi32(inserted, 64);
        do
        {
          v64 = (char *)p_m_rotation + v61;
          hkVector4f::setRotatedInverseDir(
            &v175,
            (hkQuaternionf *)((char *)p_m_rotation + v61),
            (hkVector4f *)((char *)&p_m_rotation[-1].m_vec + v61));
          m_quad = p_m_rotation->m_vec.m_quad;
          v66 = *(__m128 *)((char *)&p_m_rotation[1].m_vec.m_quad + v61);
          v67 = _mm_rcp_ps(v66);
          v68 = _mm_xor_ps(v175.m_quad, v62);
          v69 = p_m_rotation[-1].m_vec.m_quad;
          v70 = _mm_xor_ps(v63, *(__m128 *)((char *)&p_m_rotation->m_vec.m_quad + v61));
          v71 = _mm_mul_ps(
                  (__m128)_mm_srli_si128(
                            _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v66, v67)), v67), 4),
                            4),
                  p_m_rotation[1].m_vec.m_quad);
          v72 = _mm_mul_ps(v68, p_m_rotation->m_vec.m_quad);
          v73 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v68, v68, 201), p_m_rotation->m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v68));
          v74 = _mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 255);
          v75 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v72, v72, 85), _mm_shuffle_ps(v72, v72, 0)),
                        _mm_shuffle_ps(v72, v72, 170)),
                      p_m_rotation->m_vec.m_quad),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v74, v74), (__m128)xmmword_141A711B0), v68)),
                  _mm_mul_ps(_mm_shuffle_ps(v73, v73, 201), v74));
          v76 = _mm_shuffle_ps(v70, v70, 255);
          v77 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v70, v70, 201), p_m_rotation->m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 201), v70));
          v172 = _mm_add_ps(_mm_add_ps(v75, v75), v69);
          v78 = _mm_mul_ps(v70, v74);
          v79 = _mm_mul_ps(v70, m_quad);
          v80 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v77, v77, 201), v78), _mm_mul_ps(v76, m_quad));
          q1.m_vec.m_quad = _mm_shuffle_ps(
                              v80,
                              _mm_unpackhi_ps(
                                v80,
                                _mm_sub_ps(
                                  _mm_mul_ps(v76, v74),
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v79, v79, 85), _mm_shuffle_ps(v79, v79, 0)),
                                    _mm_shuffle_ps(v79, v79, 170)))),
                              196);
          v81 = _mm_sub_ps(v172, v69);
          v174 = v71;
          v78.m128_f32[0] = COERCE_FLOAT(*v179) * *(float *)((char *)v10 + v59);
          *v10 = *(float *)((char *)v10 + v56);
          t.m_real = _mm_shuffle_ps((__m128)v78.m128_u32[0], (__m128)v78.m128_u32[0], 0);
          *(__m128 *)&v64[v58 - 16] = _mm_add_ps(_mm_mul_ps(v81, t.m_real), v69);
          hkQuaternionf::setSlerp((hkQuaternionf *)((char *)p_m_rotation + v61 + v58), p_m_rotation, &q1, &t);
          p_m_rotation += 3;
          ++v10;
          v55 = retaddr-- == 1;
          *(__m128 *)&v64[v58 + 16] = _mm_add_ps(
                                        _mm_mul_ps(_mm_sub_ps(v174, p_m_rotation[-2].m_vec.m_quad), t.m_real),
                                        p_m_rotation[-2].m_vec.m_quad);
        }
        while ( !v55 );
      }
    }
    else if ( v181 )
    {
      if ( v181 == 1 && v180 > 0 )
      {
        v12 = (char *)dst - (char *)srcL;
        v13 = (char *)weightsL - (char *)weightsOut;
        v14 = retaddr - (_QWORD)srcL;
        v15 = &srcL->m_rotation;
        v16 = v178 - (_QWORD)weightsOut;
        v17 = (unsigned int)v180;
        do
        {
          v18 = *(__m128 *)((char *)&v15[-1].m_vec.m_quad + v14);
          v19 = v15[-1].m_vec.m_quad;
          v20 = _mm_mul_ps(v18, v15->m_vec.m_quad);
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
          v172 = _mm_add_ps(_mm_add_ps(v23, v23), v19);
          v27 = _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v25);
          v28 = _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v24);
          v29 = _mm_mul_ps(v24, v25);
          v30 = _mm_sub_ps(v172, v19);
          v31 = _mm_sub_ps(v28, v27);
          v32 = _mm_shuffle_ps(v25, v25, 255);
          v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 201), _mm_mul_ps(v25, v22)), _mm_mul_ps(v26, v32));
          v34 = _mm_mul_ps(*(__m128 *)((char *)&v15[1].m_vec.m_quad + v14), v15[1].m_vec.m_quad);
          q1.m_vec.m_quad = _mm_shuffle_ps(
                              v33,
                              _mm_unpackhi_ps(
                                v33,
                                _mm_sub_ps(
                                  _mm_mul_ps(v32, v22),
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                                    _mm_shuffle_ps(v29, v29, 170)))),
                              196);
          v174 = v34;
          v34.m128_f32[0] = COERCE_FLOAT(*v179) * *(float *)((char *)v10 + v16);
          *v10 = *(float *)((char *)v10 + v13);
          t.m_real = _mm_shuffle_ps((__m128)v34.m128_u32[0], (__m128)v34.m128_u32[0], 0);
          *(__m128 *)((char *)&v15[-1].m_vec.m_quad + v12) = _mm_add_ps(_mm_mul_ps(v30, t.m_real), v19);
          hkQuaternionf::setSlerp((hkQuaternionf *)((char *)v15 + v12), v15, &q1, &t);
          v15 += 3;
          ++v10;
          *(__m128 *)((char *)&v15[-2].m_vec.m_quad + v12) = _mm_add_ps(
                                                               _mm_mul_ps(
                                                                 _mm_sub_ps(v174, v15[-2].m_vec.m_quad),
                                                                 t.m_real),
                                                               v15[-2].m_vec.m_quad);
          --v17;
        }
        while ( v17 );
      }
    }
    else if ( v180 > 0 )
    {
      v35 = (char *)dst - (char *)srcL;
      v36 = (char *)weightsL - (char *)weightsOut;
      v37 = retaddr - (_QWORD)srcL;
      v38 = (char *)srcL - (char *)dst;
      p_m_scale = &srcL->m_scale;
      v40 = v178 - (_QWORD)weightsOut;
      v176 = (unsigned int)v180;
      do
      {
        v41 = _mm_shuffle_ps(
                (__m128)*(unsigned int *)((char *)v10 + v40),
                (__m128)*(unsigned int *)((char *)v10 + v40),
                0);
        v42 = _mm_rcp_ps(v41);
        v43 = _mm_shuffle_ps((__m128)(unsigned int)*v179, (__m128)(unsigned int)*v179, 0);
        v44 = _mm_cmplt_ps((__m128)0i64, v41);
        v45 = _mm_shuffle_ps(
                (__m128)*(unsigned int *)((char *)v10 + v36),
                (__m128)*(unsigned int *)((char *)v10 + v36),
                0);
        v46 = _mm_cmplt_ps(v41, v45);
        v47 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v41, v42)), v42);
        v48 = _mm_rcp_ps(v45);
        v49 = _mm_andnot_ps(v44, aabbOut.m_quad);
        v50 = _mm_or_ps(
                _mm_and_ps(
                  _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v45, v48)), v48), v41), v43),
                  v46),
                _mm_andnot_ps(
                  v46,
                  _mm_sub_ps(query.m_quad, _mm_mul_ps(_mm_sub_ps(query.m_quad, v43), _mm_mul_ps(v47, v45)))));
        v51 = _mm_cmplt_ps((__m128)0i64, v45);
        v52 = _mm_or_ps(
                _mm_andnot_ps(v51, _mm_or_ps(_mm_andnot_ps(v44, v43), _mm_and_ps(v44, query.m_quad))),
                _mm_and_ps(_mm_or_ps(_mm_and_ps(v50, v44), v49), v51));
        v53 = _mm_shuffle_ps(v52, v52, 0);
        v54 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)&p_m_scale[-2].m_quad + v37), p_m_scale[-2].m_quad), v53);
        t.m_real = v53;
        *(__m128 *)((char *)&p_m_scale[-2].m_quad + v35) = _mm_add_ps(v54, p_m_scale[-2].m_quad);
        *(_DWORD *)v10 = (COERCE_UNSIGNED_INT(
                            (float)((float)(1.0 - v50.m128_f32[0]) * v45.m128_f32[0])
                          + (float)(v50.m128_f32[0] * v41.m128_f32[0])) & v44.m128_i32[0] | _mm_andnot_ps(v44, v45).m128_u32[0]) & v51.m128_i32[0] | _mm_andnot_ps(v51, _mm_or_ps(_mm_and_ps(v41, v44), v49)).m128_u32[0];
        hkQuaternionf::setSlerp(
          (hkQuaternionf *)((char *)&p_m_scale[-1] + v35),
          (hkQuaternionf *)((char *)&p_m_scale[-1] + v35 + v38),
          (hkQuaternionf *)((char *)&p_m_scale[-1] + v37),
          &t);
        p_m_scale += 3;
        ++v10;
        v55 = v176-- == 1;
        *(__m128 *)((char *)&p_m_scale[-3].m_quad + v35) = _mm_add_ps(
                                                             _mm_mul_ps(
                                                               _mm_sub_ps(
                                                                 *(__m128 *)((char *)&p_m_scale[-3].m_quad + v37),
                                                                 p_m_scale[-3].m_quad),
                                                               t.m_real),
                                                             p_m_scale[-3].m_quad);
      }
      while ( !v55 );
    }
  }
  else if ( v181 == -1 )
  {
    if ( v180 > 0 )
    {
      v136 = retaddr;
      v137 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
      v138 = (char *)weightsL - (char *)weightsOut;
      v139 = (signed __int64)dst - retaddr;
      v140 = v178 - (_QWORD)weightsOut;
      v141 = &srcL->m_rotation;
      retaddr = (unsigned int)v180;
      v142 = (__m128)_mm_shuffle_epi32(v137, 0);
      v143 = (__m128)_mm_shuffle_epi32(v137, 64);
      v144 = v136 - (_QWORD)srcL;
      do
      {
        v145 = (char *)v141 + v144;
        hkVector4f::setRotatedInverseDir(
          &v175,
          (hkQuaternionf *)((char *)v141 + v144),
          (hkVector4f *)((char *)&v141[-1].m_vec + v144));
        v146 = v141->m_vec.m_quad;
        v147 = *(__m128 *)((char *)&v141[1].m_vec.m_quad + v144);
        v148 = _mm_rcp_ps(v147);
        v149 = _mm_xor_ps(v175.m_quad, v142);
        v150 = v141[-1].m_vec.m_quad;
        v151 = _mm_xor_ps(v143, *(__m128 *)((char *)&v141->m_vec.m_quad + v144));
        v152 = (__m128)_mm_srli_si128(
                         _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v147, v148)), v148), 4),
                         4);
        v153 = _mm_mul_ps(v149, v141->m_vec.m_quad);
        v154 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v149, v149, 201), v141->m_vec.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(v146, v146, 201), v149));
        v155 = _mm_shuffle_ps(v141->m_vec.m_quad, v141->m_vec.m_quad, 255);
        v156 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v155, v155), (__m128)xmmword_141A711B0), v149);
        v157 = _mm_shuffle_ps(v151, v151, 255);
        v158 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v153, v153, 85), _mm_shuffle_ps(v153, v153, 0)),
                       _mm_shuffle_ps(v153, v153, 170)),
                     v141->m_vec.m_quad),
                   v156),
                 _mm_mul_ps(_mm_shuffle_ps(v154, v154, 201), v155));
        v159 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v151, v151, 201), v141->m_vec.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(v141->m_vec.m_quad, v141->m_vec.m_quad, 201), v151));
        v160 = v151;
        v161 = _mm_mul_ps(v151, v141->m_vec.m_quad);
        v162 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v159, v159, 201), _mm_mul_ps(v160, v155)),
                 _mm_mul_ps(v141->m_vec.m_quad, v157));
        v163 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v161, v161, 85), _mm_shuffle_ps(v161, v161, 0)),
                 _mm_shuffle_ps(v161, v161, 170));
        v164 = v141[1].m_vec.m_quad;
        v165 = _mm_shuffle_ps(v162, _mm_unpackhi_ps(v162, _mm_sub_ps(_mm_mul_ps(v157, v155), v163)), 196);
        v141 += 3;
        ++v10;
        v55 = retaddr-- == 1;
        v160.m128_f32[0] = COERCE_FLOAT(*v179) * *(float *)((char *)v10 + v140 - 4);
        *(v10 - 1) = *(float *)((char *)v10 + v138 - 4);
        v166 = (__m128)v160.m128_u32[0];
        srcRb = v160.m128_i32[0];
        v167 = _mm_mul_ps(v165, v146);
        v168 = _mm_shuffle_ps(v166, v166, 0);
        v169 = _mm_shuffle_ps((__m128)srcRb, (__m128)srcRb, 0);
        v170 = _mm_add_ps(_mm_shuffle_ps(v167, v167, 78), v167);
        *(__m128 *)&v145[v139 - 16] = _mm_add_ps(
                                        _mm_mul_ps(_mm_sub_ps(_mm_add_ps(_mm_add_ps(v158, v158), v150), v150), v168),
                                        v150);
        *(__m128 *)&v145[v139 + 16] = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v152, v164), v164), v168), v164);
        *(__m128 *)&v145[v139] = _mm_add_ps(
                                   _mm_mul_ps(
                                     _mm_xor_ps(
                                       (__m128)_mm_slli_epi32(
                                                 _mm_srli_epi32(
                                                   (__m128i)_mm_cmplt_ps(
                                                              _mm_add_ps(_mm_shuffle_ps(v170, v170, 177), v170),
                                                              (__m128)0i64),
                                                   0x1Fu),
                                                 0x1Fu),
                                       _mm_sub_ps(query.m_quad, v169)),
                                     v146),
                                   _mm_mul_ps(v165, v169));
      }
      while ( !v55 );
    }
  }
  else if ( v181 )
  {
    if ( v181 == 1 && v180 > 0 )
    {
      v82 = &srcL->m_rotation;
      v83 = retaddr - (_QWORD)srcL;
      v84 = (char *)dst - (char *)srcL;
      v85 = (char *)((char *)weightsL - (char *)v10);
      v86 = (unsigned int)v180;
      v87 = v178 - (_QWORD)v10;
      do
      {
        v88 = v82->m_vec.m_quad;
        v89 = *(__m128 *)((char *)&v82[-1].m_vec.m_quad + v83);
        v90 = v82[-1].m_vec.m_quad;
        v91 = _mm_mul_ps(v89, v82->m_vec.m_quad);
        v92 = _mm_shuffle_ps(v82->m_vec.m_quad, v82->m_vec.m_quad, 255);
        v93 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v89, v89, 201), v82->m_vec.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v88, v88, 201), v89));
        v94 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v92, v92), (__m128)xmmword_141A711B0), v89);
        v95 = *(__m128 *)((char *)&v82->m_vec.m_quad + v83);
        v96 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v91, v91, 85), _mm_shuffle_ps(v91, v91, 0)),
                      _mm_shuffle_ps(v91, v91, 170)),
                    v82->m_vec.m_quad),
                  v94),
                _mm_mul_ps(_mm_shuffle_ps(v93, v93, 201), v92));
        v97 = _mm_shuffle_ps(v95, v95, 255);
        v98 = _mm_mul_ps(v82->m_vec.m_quad, v97);
        v99 = _mm_mul_ps(v82->m_vec.m_quad, v95);
        v100 = _mm_mul_ps(v97, v92);
        v101 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v95, v95, 201), v82->m_vec.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(v82->m_vec.m_quad, v82->m_vec.m_quad, 201), v95));
        v102 = _mm_mul_ps(v95, v92);
        v103 = v82[1].m_vec.m_quad;
        v104 = _mm_mul_ps(*(__m128 *)((char *)&v82[1].m_vec.m_quad + v83), v103);
        v105 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v101, v101, 201), v102), v98);
        v106 = _mm_shuffle_ps(
                 v105,
                 _mm_unpackhi_ps(
                   v105,
                   _mm_sub_ps(
                     v100,
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v99, v99, 85), _mm_shuffle_ps(v99, v99, 0)),
                       _mm_shuffle_ps(v99, v99, 170)))),
                 196);
        v102.m128_f32[0] = COERCE_FLOAT(*v179) * *(float *)((char *)v10 + v87);
        *v10 = *(float *)&v85[(_QWORD)v10];
        srcRa = v102.m128_i32[0];
        v107 = _mm_shuffle_ps((__m128)v102.m128_u32[0], (__m128)v102.m128_u32[0], 0);
        v108 = _mm_mul_ps(v88, v106);
        *(__m128 *)((char *)&v82[-1].m_vec.m_quad + v84) = _mm_add_ps(
                                                             _mm_mul_ps(
                                                               _mm_sub_ps(_mm_add_ps(_mm_add_ps(v96, v96), v90), v90),
                                                               v107),
                                                             v90);
        v109 = _mm_shuffle_ps((__m128)srcRa, (__m128)srcRa, 0);
        v82 += 3;
        ++v10;
        v110 = _mm_add_ps(_mm_shuffle_ps(v108, v108, 78), v108);
        *(__m128 *)((char *)&v82[-2].m_vec.m_quad + v84) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v104, v103), v107), v103);
        *(__m128 *)((char *)&v82[-3].m_vec.m_quad + v84) = _mm_add_ps(
                                                             _mm_mul_ps(
                                                               _mm_xor_ps(
                                                                 (__m128)_mm_slli_epi32(
                                                                           _mm_srli_epi32(
                                                                             (__m128i)_mm_cmplt_ps(
                                                                                        _mm_add_ps(
                                                                                          _mm_shuffle_ps(
                                                                                            v110,
                                                                                            v110,
                                                                                            177),
                                                                                          v110),
                                                                                        (__m128)0i64),
                                                                             0x1Fu),
                                                                           0x1Fu),
                                                                 _mm_sub_ps(query.m_quad, v109)),
                                                               v88),
                                                             _mm_mul_ps(v106, v109));
        --v86;
      }
      while ( v86 );
    }
  }
  else if ( v180 > 0 )
  {
    v111 = query.m_quad;
    v112 = (char *)weightsL - (char *)weightsOut;
    v113 = (char *)dst - (char *)srcL;
    v114 = retaddr - (_QWORD)srcL;
    v115 = &srcL->m_rotation;
    v116 = (unsigned int)v180;
    v117 = v178 - (_QWORD)weightsOut;
    do
    {
      v118 = *v179;
      *(float *)&v176 = *(float *)((char *)v10 + v117);
      v119 = _mm_shuffle_ps((__m128)(unsigned int)v176, (__m128)(unsigned int)v176, 0);
      v120 = _mm_rcp_ps(v119);
      v121 = _mm_shuffle_ps((__m128)(unsigned int)v118, (__m128)(unsigned int)v118, 0);
      v122 = _mm_cmplt_ps((__m128)0i64, v119);
      v123 = _mm_shuffle_ps(
               (__m128)*(unsigned int *)((char *)v10 + v112),
               (__m128)*(unsigned int *)((char *)v10 + v112),
               0);
      v124 = _mm_cmplt_ps(v119, v123);
      v125 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v120, v119)), v120);
      v120.m128_f32[0] = _mm_rcp_ps(v123).m128_f32[0];
      v126 = _mm_andnot_ps(v122, aabbOut.m_quad);
      LODWORD(v127) = COERCE_UNSIGNED_INT(
                        (float)((float)((float)(2.0 - (float)(v120.m128_f32[0] * v123.m128_f32[0])) * v120.m128_f32[0])
                              * v119.m128_f32[0])
                      * v121.m128_f32[0]) & v124.m128_i32[0] | _mm_andnot_ps(
                                                                 v124,
                                                                 _mm_sub_ps(
                                                                   v111,
                                                                   _mm_mul_ps(
                                                                     _mm_sub_ps(v111, v121),
                                                                     _mm_mul_ps(v125, v123)))).m128_u32[0];
      v128 = _mm_cmplt_ps((__m128)0i64, v123);
      v125.m128_i32[0] = _mm_andnot_ps(v128, _mm_or_ps(_mm_and_ps(v122, v111), _mm_andnot_ps(v122, v121))).m128_u32[0] | (v122.m128_i32[0] & LODWORD(v127) | v126.m128_i32[0]) & v128.m128_i32[0];
      v121.m128_f32[0] = v125.m128_f32[0];
      v129 = _mm_shuffle_ps(v121, v121, 0);
      LODWORD(retaddr) = v125.m128_i32[0];
      v130 = _mm_mul_ps(*(__m128 *)((char *)&v115->m_vec.m_quad + v114), v115->m_vec.m_quad);
      *(__m128 *)((char *)&v115[-1].m_vec.m_quad + v113) = _mm_add_ps(
                                                             _mm_mul_ps(
                                                               _mm_sub_ps(
                                                                 *(__m128 *)((char *)&v115[-1].m_vec.m_quad + v114),
                                                                 v115[-1].m_vec.m_quad),
                                                               v129),
                                                             v115[-1].m_vec.m_quad);
      *(_DWORD *)v10 = (COERCE_UNSIGNED_INT(
                          (float)((float)(v111.m128_f32[0] - v127) * v123.m128_f32[0])
                        + (float)(v127 * v119.m128_f32[0])) & v122.m128_i32[0] | _mm_andnot_ps(v122, v123).m128_u32[0]) & v128.m128_i32[0] | _mm_andnot_ps(v128, _mm_or_ps(_mm_and_ps(v122, v119), v126)).m128_u32[0];
      v111 = query.m_quad;
      v115 += 3;
      ++v10;
      v131 = _mm_shuffle_ps((__m128)v125.m128_u32[0], (__m128)v125.m128_u32[0], 0);
      v132 = _mm_add_ps(_mm_shuffle_ps(v130, v130, 78), v130);
      v133 = _mm_sub_ps(query.m_quad, v131);
      v134 = _mm_mul_ps(v131, *(__m128 *)((char *)&v115[-3].m_vec.m_quad + v114));
      v135 = _mm_mul_ps(
               _mm_xor_ps(
                 (__m128)_mm_slli_epi32(
                           _mm_srli_epi32(
                             (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v132, v132, 177), v132), (__m128)0i64),
                             0x1Fu),
                           0x1Fu),
                 v133),
               v115[-3].m_vec.m_quad);
      *(__m128 *)((char *)&v115[-2].m_vec.m_quad + v113) = _mm_add_ps(
                                                             _mm_mul_ps(
                                                               _mm_sub_ps(
                                                                 *(__m128 *)((char *)&v115[-2].m_vec.m_quad + v114),
                                                                 v115[-2].m_vec.m_quad),
                                                               v129),
                                                             v115[-2].m_vec.m_quad);
      *(__m128 *)((char *)&v115[-3].m_vec.m_quad + v113) = _mm_add_ps(v135, v134);
      --v116;
    }
    while ( v116 );
  }
}

// File Line: 541
// RVA: 0xB422D0
void __fastcall hkaBlender::mul(const float *dst, float *srcL, float *srcR, int n)
{
  int v4; // r11d
  __int64 v7; // rcx
  const float *v8; // rax
  float *v9; // r8
  int v10; // eax
  __int64 v11; // rdi
  __int64 v12; // rcx
  signed __int64 v13; // r8
  unsigned __int64 v14; // r11
  signed __int64 v15; // r9
  const float *v16; // rax
  __int64 v17; // r11
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  signed __int64 v23; // rdx
  signed __int64 v24; // r10
  const float *v25; // rax
  __int64 v26; // rcx
  float v27; // xmm0_4

  v4 = 0;
  if ( n >= 8 )
  {
    v7 = n - 1;
    v8 = &srcR[v7];
    v9 = (float *)&dst[v7];
    if ( (dst > v8 || v9 < srcR) && (dst > &srcL[v7] || v9 < srcL) )
    {
      do
      {
        *(__m128 *)&dst[v4] = _mm_mul_ps(*(__m128 *)&srcL[v4], *(__m128 *)&srcR[v4]);
        v10 = v4 + 4;
        v4 += 8;
        *(__m128 *)&dst[v10] = _mm_mul_ps(*(__m128 *)&srcL[v10], *(__m128 *)&srcR[v10]);
      }
      while ( v4 < n - (n & 7) );
    }
  }
  v11 = v4;
  v12 = n;
  if ( v4 < (__int64)n )
  {
    if ( n - (__int64)v4 >= 4 )
    {
      v13 = (char *)srcL - (char *)srcR;
      v14 = n - (__int64)v4 - 4;
      v15 = (char *)dst - (char *)srcR;
      v16 = &srcR[v11 + 1];
      v17 = (v14 >> 2) + 1;
      v11 += 4 * v17;
      do
      {
        v18 = *(const float *)((char *)v16 + v13 - 4);
        v19 = *(const float *)((char *)v16 + v13);
        v16 += 4;
        v20 = v19 * *(v16 - 4);
        *(float *)((char *)v16 + v15 - 20) = v18 * *(v16 - 5);
        v21 = *(const float *)((char *)v16 + v13 - 12);
        *(float *)((char *)v16 + v15 - 16) = v20;
        v22 = *(const float *)((char *)v16 + v13 - 8) * *(v16 - 2);
        *(float *)((char *)v16 + v15 - 12) = v21 * *(v16 - 3);
        *(float *)((char *)v16 + v15 - 8) = v22;
        --v17;
      }
      while ( v17 );
    }
    if ( v11 < v12 )
    {
      v23 = (char *)srcL - (char *)srcR;
      v24 = (char *)dst - (char *)srcR;
      v25 = &srcR[v11];
      v26 = v12 - v11;
      do
      {
        v27 = *(const float *)((char *)v25++ + v23);
        *(float *)((char *)v25 + v24 - 4) = v27 * *(v25 - 1);
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
  __m128 m_quad; // xmm6
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
      m_quad = srcL->m_vec.m_quad;
      v8 = *(__m128 *)((char *)&srcL->m_vec.m_quad + v5);
      ++srcL;
      v9 = _mm_shuffle_ps(m_quad, m_quad, 255);
      v10 = _mm_shuffle_ps(v8, v8, 255);
      v11 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v8));
      v12 = _mm_mul_ps(v10, m_quad);
      v13 = _mm_mul_ps(m_quad, v8);
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
  hkQuaternionf *p_m_rotation; // rax
  signed __int64 v7; // rcx
  __m128 m_quad; // xmm2
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
    p_m_rotation = &srcL->m_rotation;
    v7 = (char *)dst - (char *)srcL;
    do
    {
      m_quad = p_m_rotation->m_vec.m_quad;
      v9 = *(__m128 *)((char *)&p_m_rotation[-1].m_vec.m_quad + v5);
      p_m_rotation += 3;
      v10 = _mm_mul_ps(v9, m_quad);
      v11 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v9));
      v12 = _mm_shuffle_ps(m_quad, m_quad, 255);
      v13 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                    _mm_shuffle_ps(v10, v10, 170)),
                  m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v12, v12), (__m128)xmmword_141A711B0), v9)),
              _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v12));
      v14 = m_quad;
      v15 = *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v5);
      v16 = v14;
      v17 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v15);
      v18 = _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v14);
      v19 = _mm_mul_ps(v14, v15);
      *(__m128 *)((char *)&p_m_rotation[-4].m_vec.m_quad + v7) = _mm_add_ps(
                                                                   _mm_add_ps(v13, v13),
                                                                   p_m_rotation[-4].m_vec.m_quad);
      v20 = _mm_sub_ps(v18, v17);
      v21 = _mm_shuffle_ps(v15, v15, 255);
      v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v20, v20, 201), _mm_mul_ps(v15, v12)), _mm_mul_ps(v16, v21));
      v23 = _mm_mul_ps(*(__m128 *)((char *)&p_m_rotation[-2].m_vec.m_quad + v5), p_m_rotation[-2].m_vec.m_quad);
      *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v7) = _mm_shuffle_ps(
                                                                   v22,
                                                                   _mm_unpackhi_ps(
                                                                     v22,
                                                                     _mm_sub_ps(
                                                                       _mm_mul_ps(v21, v12),
                                                                       _mm_add_ps(
                                                                         _mm_add_ps(
                                                                           _mm_shuffle_ps(v19, v19, 85),
                                                                           _mm_shuffle_ps(v19, v19, 0)),
                                                                         _mm_shuffle_ps(v19, v19, 170)))),
                                                                   196);
      *(__m128 *)((char *)p_m_rotation + v7 - 32) = v23;
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
  hkQuaternionf *p_m_rotation; // rbp
  signed __int64 v7; // rsi
  __m128i inserted; // xmm0
  __m128 v9; // xmm9
  __m128 v10; // xmm10
  __m128 m_quad; // xmm2
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
  hkVector4f v27; // [rsp+20h] [rbp-98h] BYREF

  if ( n > 0 )
  {
    v4 = (char *)srcR - (char *)srcL;
    v5 = n;
    p_m_rotation = &srcL->m_rotation;
    v7 = (char *)dst - (char *)srcL;
    inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
    v9 = (__m128)_mm_shuffle_epi32(inserted, 0);
    v10 = (__m128)_mm_shuffle_epi32(inserted, 64);
    do
    {
      hkVector4f::setRotatedInverseDir(
        &v27,
        (hkQuaternionf *)((char *)p_m_rotation + v4),
        (hkVector4f *)((char *)&p_m_rotation[-1].m_vec + v4));
      m_quad = p_m_rotation->m_vec.m_quad;
      v12 = *(__m128 *)((char *)&p_m_rotation[1].m_vec.m_quad + v4);
      v13 = _mm_xor_ps(v9, v27.m_quad);
      v14 = _mm_rcp_ps(v12);
      v15 = _mm_shuffle_ps(m_quad, m_quad, 255);
      v16 = _mm_xor_ps(v10, *(__m128 *)((char *)&p_m_rotation->m_vec.m_quad + v4));
      v17 = (__m128)_mm_srli_si128(
                      _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v12, v14)), v14), 4),
                      4);
      v18 = _mm_mul_ps(v13, p_m_rotation->m_vec.m_quad);
      v19 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), p_m_rotation->m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 201), v13));
      v20 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                    _mm_shuffle_ps(v18, v18, 170)),
                  p_m_rotation->m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v15, v15), (__m128)xmmword_141A711B0), v13)),
              _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v15));
      v21 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), p_m_rotation->m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 201), v16));
      *(__m128 *)((char *)&p_m_rotation[-1].m_vec.m_quad + v7) = _mm_add_ps(
                                                                   _mm_add_ps(v20, v20),
                                                                   p_m_rotation[-1].m_vec.m_quad);
      v22 = _mm_mul_ps(v16, v15);
      v23 = _mm_shuffle_ps(v16, v16, 255);
      v24 = _mm_mul_ps(v16, m_quad);
      v25 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 201), v22), _mm_mul_ps(v23, m_quad));
      v26 = _mm_mul_ps(p_m_rotation[1].m_vec.m_quad, v17);
      *(__m128 *)((char *)&p_m_rotation->m_vec.m_quad + v7) = _mm_shuffle_ps(
                                                                v25,
                                                                _mm_unpackhi_ps(
                                                                  v25,
                                                                  _mm_sub_ps(
                                                                    _mm_mul_ps(v23, v15),
                                                                    _mm_add_ps(
                                                                      _mm_add_ps(
                                                                        _mm_shuffle_ps(v24, v24, 85),
                                                                        _mm_shuffle_ps(v24, v24, 0)),
                                                                      _mm_shuffle_ps(v24, v24, 170)))),
                                                                196);
      *(__m128 *)((char *)p_m_rotation + v7 + 16) = v26;
      p_m_rotation += 3;
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
  __m128 m_quad; // xmm2
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
      m_quad = srcL->m_vec.m_quad;
      v8 = *(__m128 *)((char *)&srcL->m_vec.m_quad + v5);
      ++srcL;
      v9 = _mm_mul_ps(_mm_shuffle_ps(v8, v8, 255), m_quad);
      v10 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v8),
              _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), m_quad));
      v11 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 255), v8);
      v12 = _mm_mul_ps(v8, m_quad);
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
  __m128 m_quad; // xmm3
  __m128 v4; // xmm0
  __m128 v5; // xmm2
  __m128 v6; // xmm1
  __m128 v7; // xmm2

  v2 = n;
  if ( n > 0 )
  {
    do
    {
      m_quad = quaternionsInOut->m_vec.m_quad;
      ++quaternionsInOut;
      v4 = _mm_mul_ps(m_quad, m_quad);
      v5 = _mm_add_ps(_mm_shuffle_ps(v4, v4, 78), v4);
      v6 = _mm_add_ps(_mm_shuffle_ps(v5, v5, 177), v5);
      v7 = _mm_rsqrt_ps(v6);
      quaternionsInOut[-1].m_vec.m_quad = _mm_mul_ps(
                                            m_quad,
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
  hkQuaternionf *p_m_rotation; // rcx
  __m128 m_quad; // xmm3
  __m128 v5; // xmm0
  __m128 v6; // xmm2
  __m128 v7; // xmm1
  __m128 v8; // xmm2

  v2 = n;
  if ( n > 0 )
  {
    p_m_rotation = &transformsInOut->m_rotation;
    do
    {
      m_quad = p_m_rotation->m_vec.m_quad;
      p_m_rotation += 3;
      v5 = _mm_mul_ps(m_quad, m_quad);
      v6 = _mm_add_ps(_mm_shuffle_ps(v5, v5, 78), v5);
      v7 = _mm_add_ps(_mm_shuffle_ps(v6, v6, 177), v6);
      v8 = _mm_rsqrt_ps(v7);
      p_m_rotation[-3].m_vec.m_quad = _mm_mul_ps(
                                        m_quad,
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
  __m128 m_quad; // xmm2
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
      m_quad = srcL->m_vec.m_quad;
      v8 = *(__m128 *)((char *)&srcL->m_vec.m_quad + v5);
      ++srcL;
      v9 = _mm_mul_ps(v8, m_quad);
      v10 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v8));
      v11 = _mm_shuffle_ps(m_quad, m_quad, 255);
      v12 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)),
                    _mm_shuffle_ps(v9, v9, 170)),
                  m_quad),
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
  __m128 m_quad; // xmm2
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
      m_quad = srcL->m_vec.m_quad;
      v8 = *(__m128 *)((char *)&srcL->m_vec.m_quad + v5);
      ++srcL;
      v9 = _mm_mul_ps(v8, m_quad);
      v10 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v8),
              _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), m_quad));
      v11 = _mm_shuffle_ps(m_quad, m_quad, 255);
      v12 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)),
                    _mm_shuffle_ps(v9, v9, 170)),
                  m_quad),
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
  hkQuaternionf *p_m_rotation; // rdx
  signed __int64 v6; // r8
  __m128 m_quad; // xmm2
  __m128 v8; // xmm5
  __m128 v9; // xmm5
  __m128 v10; // xmm1
  __m128 v11; // xmm6
  __m128 v12; // xmm4
  __m128 v13; // xmm3

  v4 = n;
  if ( n > 0 )
  {
    p_m_rotation = &srcL->m_rotation;
    v6 = (char *)srcR - (char *)dst;
    do
    {
      m_quad = p_m_rotation->m_vec.m_quad;
      v8 = *(__m128 *)((char *)&dst->m_quad + v6);
      ++dst;
      p_m_rotation += 3;
      v9 = _mm_mul_ps(v8, p_m_rotation[-2].m_vec.m_quad);
      v10 = _mm_mul_ps(m_quad, v9);
      v11 = _mm_shuffle_ps(m_quad, m_quad, 255);
      v12 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v9));
      v13 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                    _mm_shuffle_ps(v10, v10, 170)),
                  m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v11, v11), (__m128)xmmword_141A711B0), v9)),
              _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v11));
      dst[-1].m_quad = _mm_add_ps(_mm_add_ps(v13, v13), p_m_rotation[-4].m_vec.m_quad);
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
  hkQuaternionf *p_m_rotation; // rdx
  signed __int64 v6; // r8
  __m128 m_quad; // xmm2
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
    p_m_rotation = &srcL->m_rotation;
    v6 = (char *)srcR - (char *)dst;
    do
    {
      m_quad = p_m_rotation->m_vec.m_quad;
      v8 = *(__m128 *)((char *)&dst->m_quad + v6);
      ++dst;
      p_m_rotation += 3;
      v9 = _mm_sub_ps(v8, p_m_rotation[-4].m_vec.m_quad);
      v10 = _mm_shuffle_ps(m_quad, m_quad, 255);
      v11 = _mm_mul_ps(m_quad, v9);
      v12 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v9),
              _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), m_quad));
      v13 = p_m_rotation[-2].m_vec.m_quad;
      v14 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                    _mm_shuffle_ps(v11, v11, 170)),
                  m_quad),
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
void __fastcall hkaBlender::localFromModel(
        hkQsTransformf *poseLocalOut,
        hkQsTransformf *poseModelIn,
        const __int16 *parentIndices,
        int numBones,
        hkQsTransformf *worldFromModel)
{
  __int64 v5; // rdi
  __m128i inserted; // xmm0
  hkVector4f *p_m_scale; // rbx
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
  hkVector4f direction; // [rsp+20h] [rbp-108h] BYREF
  hkQuaternionf quat; // [rsp+30h] [rbp-F8h] BYREF
  __m128 m_quad; // [rsp+40h] [rbp-E8h]
  hkVector4f v37; // [rsp+50h] [rbp-D8h] BYREF

  if ( numBones )
  {
    v5 = numBones;
    inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
    p_m_scale = &poseLocalOut[numBones].m_scale;
    v10 = (char *)poseModelIn - (char *)poseLocalOut;
    v11 = (__m128)_mm_shuffle_epi32(inserted, 0);
    v12 = (__m128)_mm_shuffle_epi32(inserted, 64);
    do
    {
      v13 = parentIndices[v5 - 1];
      v14 = *(__m128 *)((char *)&p_m_scale[-5].m_quad + v10);
      v15 = *(__m128 *)((char *)&p_m_scale[-4].m_quad + v10);
      p_m_scale -= 3;
      --v5;
      v16 = *(__m128 *)((char *)&p_m_scale->m_quad + v10);
      if ( (int)v13 < 0 )
        v17 = worldFromModel;
      else
        v17 = &poseModelIn[v13];
      direction.m_quad = (__m128)v17->m_translation;
      quat.m_vec.m_quad = (__m128)v17->m_rotation;
      m_quad = v17->m_scale.m_quad;
      hkVector4f::setRotatedInverseDir(&v37, &quat, &direction);
      v18 = _mm_xor_ps(v12, quat.m_vec.m_quad);
      v19 = _mm_rcp_ps(m_quad);
      v20 = _mm_shuffle_ps(v18, v18, 255);
      v21 = (__m128)_mm_srli_si128(
                      _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(m_quad, v19)), v19), 4),
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
      p_m_scale[-2].m_quad = _mm_add_ps(_mm_add_ps(v27, v27), _mm_xor_ps(v11, v37.m_quad));
      v30 = _mm_shuffle_ps(v15, v15, 201);
      v31 = _mm_mul_ps(v15, v18);
      v32 = _mm_sub_ps(_mm_mul_ps(v30, v18), v25);
      v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v32, v32, 201), v28), _mm_mul_ps(v18, v29));
      p_m_scale[-1].m_quad = _mm_shuffle_ps(
                               v33,
                               _mm_unpackhi_ps(
                                 v33,
                                 _mm_sub_ps(
                                   _mm_mul_ps(v29, v20),
                                   _mm_add_ps(
                                     _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                                     _mm_shuffle_ps(v31, v31, 170)))),
                               196);
      p_m_scale->m_quad = _mm_mul_ps(v16, v21);
    }
    while ( v5 );
  }
}

// File Line: 652
// RVA: 0xB42FD0
void __fastcall hkaBlender::modelFromLocal(
        hkQsTransformf *poseModelOut,
        hkQsTransformf *poseLocalIn,
        const __int16 *parentIndices,
        int numBones,
        hkQsTransformf *worldFromModel)
{
  __int64 v5; // r10
  __int64 v6; // rbx
  hkVector4f *p_m_scale; // r9
  signed __int64 v8; // r11
  __int64 v9; // rax
  __m128 v10; // xmm9
  __m128 v11; // xmm8
  __m128 v12; // xmm10
  hkQsTransformf *v13; // rax
  __m128 m_quad; // xmm5
  __m128 v15; // xmm1
  __m128 v16; // xmm6
  __m128 v17; // xmm4
  __m128 v18; // xmm0
  __m128 v19; // xmm4
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm0
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  __m128 v25; // xmm2
  __m128 v26; // xmm8
  __m128 v27; // xmm2
  __m128 v28; // xmm2

  if ( numBones > 0 )
  {
    v5 = 0i64;
    v6 = numBones;
    p_m_scale = &poseModelOut->m_scale;
    v8 = (char *)poseLocalIn - (char *)poseModelOut;
    do
    {
      v9 = parentIndices[v5];
      v10 = *(__m128 *)((char *)&p_m_scale[-2].m_quad + v8);
      v11 = *(__m128 *)((char *)&p_m_scale[-1].m_quad + v8);
      v12 = *(__m128 *)((char *)&p_m_scale->m_quad + v8);
      if ( (int)v9 < 0 )
        v13 = worldFromModel;
      else
        v13 = &poseModelOut[v9];
      m_quad = v13->m_rotation.m_vec.m_quad;
      ++v5;
      p_m_scale += 3;
      v15 = _mm_mul_ps(v10, m_quad);
      v16 = _mm_shuffle_ps(m_quad, m_quad, 255);
      v17 = _mm_shuffle_ps(m_quad, m_quad, 201);
      v18 = _mm_mul_ps(v17, v10);
      v19 = _mm_mul_ps(v17, v11);
      v20 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), m_quad), v18);
      v21 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                    _mm_shuffle_ps(v15, v15, 170)),
                  m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v16, v16), (__m128)xmmword_141A711B0), v10)),
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v16));
      v22 = _mm_mul_ps(v11, v16);
      v23 = _mm_shuffle_ps(v11, v11, 255);
      v24 = _mm_add_ps(_mm_add_ps(v21, v21), v13->m_translation.m_quad);
      p_m_scale[-3].m_quad = _mm_mul_ps(v12, v13->m_scale.m_quad);
      p_m_scale[-5] = (hkVector4f)v24;
      v25 = _mm_shuffle_ps(v11, v11, 201);
      v26 = _mm_mul_ps(v11, m_quad);
      v27 = _mm_sub_ps(_mm_mul_ps(v25, m_quad), v19);
      v28 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 201), v22), _mm_mul_ps(m_quad, v23));
      p_m_scale[-4].m_quad = _mm_shuffle_ps(
                               v28,
                               _mm_unpackhi_ps(
                                 v28,
                                 _mm_sub_ps(
                                   _mm_mul_ps(v23, v16),
                                   _mm_add_ps(
                                     _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                                     _mm_shuffle_ps(v26, v26, 170)))),
                               196);
    }
    while ( v5 < v6 );
  }
}


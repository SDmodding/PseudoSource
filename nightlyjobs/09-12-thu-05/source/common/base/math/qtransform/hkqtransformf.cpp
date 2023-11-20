// File Line: 15
// RVA: 0xC70FB0
void __fastcall hkQTransformf::setInverse(hkQTransformf *this, hkQTransformf *qt)
{
  __m128i v2; // xmm7
  hkQuaternionf v3; // xmm4
  hkVector4f v4; // xmm2
  __m128 v5; // xmm1
  __m128 v6; // xmm6
  __m128 v7; // xmm5
  __m128 v8; // xmm3

  v2 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  v3.m_vec.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(v2, 64), qt->m_rotation.m_vec.m_quad);
  this->m_rotation = (hkQuaternionf)v3.m_vec.m_quad;
  v4.m_quad = (__m128)qt->m_translation;
  v5 = _mm_mul_ps(qt->m_translation.m_quad, v3.m_vec.m_quad);
  v6 = _mm_shuffle_ps(v3.m_vec.m_quad, v3.m_vec.m_quad, 255);
  v7 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(qt->m_translation.m_quad, v4.m_quad, 201), v3.m_vec.m_quad),
         _mm_mul_ps(_mm_shuffle_ps(v3.m_vec.m_quad, v3.m_vec.m_quad, 201), v4.m_quad));
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(
             _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170)),
             v3.m_vec.m_quad),
           _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v6, v6), (__m128)xmmword_141A711B0), v4.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v6));
  this->m_translation.m_quad = _mm_xor_ps(_mm_add_ps(v8, v8), (__m128)_mm_shuffle_epi32(v2, 0));
}

// File Line: 23
// RVA: 0xC71060
void __fastcall hkQTransformf::setMul(hkQTransformf *this, hkQTransformf *qt1, hkQTransformf *qt2)
{
  hkVector4f v3; // xmm3
  __m128 v4; // xmm1
  __m128 v5; // xmm5
  __m128 v6; // xmm6
  __m128 v7; // xmm4
  __m128 v8; // xmm4
  __m128 v9; // xmm5
  __m128 v10; // xmm3
  __m128 v11; // xmm6
  __m128 v12; // xmm3

  v3.m_quad = (__m128)qt2->m_translation;
  v4 = _mm_mul_ps(qt2->m_translation.m_quad, qt1->m_rotation.m_vec.m_quad);
  v5 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 201), qt1->m_rotation.m_vec.m_quad),
         _mm_mul_ps(_mm_shuffle_ps(qt1->m_rotation.m_vec.m_quad, qt1->m_rotation.m_vec.m_quad, 201), v3.m_quad));
  v6 = _mm_shuffle_ps(qt1->m_rotation.m_vec.m_quad, qt1->m_rotation.m_vec.m_quad, 255);
  v7 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(
             _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)), _mm_shuffle_ps(v4, v4, 170)),
             qt1->m_rotation.m_vec.m_quad),
           _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v6, v6), (__m128)xmmword_141A711B0), v3.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v6));
  this->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v7, v7), qt1->m_translation.m_quad);
  v8 = _mm_shuffle_ps(qt1->m_rotation.m_vec.m_quad, qt1->m_rotation.m_vec.m_quad, 255);
  v9 = _mm_shuffle_ps(qt2->m_rotation.m_vec.m_quad, qt2->m_rotation.m_vec.m_quad, 255);
  v10 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(qt2->m_rotation.m_vec.m_quad, qt2->m_rotation.m_vec.m_quad, 201),
            qt1->m_rotation.m_vec.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(qt1->m_rotation.m_vec.m_quad, qt1->m_rotation.m_vec.m_quad, 201),
            qt2->m_rotation.m_vec.m_quad));
  v11 = _mm_mul_ps(qt1->m_rotation.m_vec.m_quad, qt2->m_rotation.m_vec.m_quad);
  v12 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v10, v10, 201), _mm_mul_ps(v8, qt2->m_rotation.m_vec.m_quad)),
          _mm_mul_ps(v9, qt1->m_rotation.m_vec.m_quad));
  this->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                    v12,
                                    _mm_unpackhi_ps(
                                      v12,
                                      _mm_sub_ps(
                                        _mm_mul_ps(v9, v8),
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                                          _mm_shuffle_ps(v11, v11, 170)))),
                                    196);
}

// File Line: 31
// RVA: 0xC71160
void __fastcall hkQTransformf::setMul(hkQTransformf *this, hkTransformf *t1, hkQTransformf *qt2)
{
  float v3; // xmm3_4
  float v4; // xmm2_4
  float v5; // xmm4_4
  hkQTransformf *v6; // rbx
  hkTransformf *v7; // r11
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  signed int v13; // edx
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r9
  float v17; // xmm2_4
  float v18; // xmm0_4
  __m128 v19; // xmm3
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm7
  __m128 v25; // xmm1
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm4
  __m128 v29; // xmm2
  __m128 v30; // xmm2
  __m128 v31; // xmm3
  __m128 v32; // xmm4
  __m128 v33; // xmm1
  __m128 v34; // xmm7
  __m128 v35; // xmm4
  __m128 v36; // xmm4
  __m128 v37; // [rsp+0h] [rbp-38h]

  v3 = t1->m_rotation.m_col0.m_quad.m128_f32[0];
  v4 = t1->m_rotation.m_col1.m_quad.m128_f32[1];
  v5 = t1->m_rotation.m_col2.m_quad.m128_f32[2];
  v6 = qt2;
  v7 = t1;
  v8 = (float)(t1->m_rotation.m_col0.m_quad.m128_f32[0] + v4) + v5;
  if ( v8 <= 0.0 )
  {
    v13 = 0;
    v37.m128_i32[0] = 1;
    if ( v4 > v3 )
      v13 = 1;
    *(unsigned __int64 *)((char *)v37.m128_u64 + 4) = 2i64;
    if ( v5 > v7->m_rotation.m_col0.m_quad.m128_f32[5 * v13] )
      v13 = 2;
    v14 = v13;
    v15 = v37.m128_i32[v13];
    v16 = v37.m128_i32[v15];
    v17 = fsqrt(
            (float)(v7->m_rotation.m_col0.m_quad.m128_f32[5 * v13]
                  - (float)(v7->m_rotation.m_col0.m_quad.m128_f32[5 * v16]
                          + v7->m_rotation.m_col0.m_quad.m128_f32[5 * v15]))
          + 1.0);
    v18 = v7->m_rotation.m_col0.m_quad.m128_f32[v16 + 4 * v15] - v7->m_rotation.m_col0.m_quad.m128_f32[v15 + 4 * v16];
    v37.m128_f32[v14] = v17 * 0.5;
    v37.m128_f32[3] = v18 * (float)(0.5 / v17);
    v37.m128_f32[v15] = (float)(v7->m_rotation.m_col0.m_quad.m128_f32[v15 + 4 * v14]
                              + v7->m_rotation.m_col0.m_quad.m128_f32[v14 + 4 * v15])
                      * (float)(0.5 / v17);
    v37.m128_f32[v16] = (float)(v7->m_rotation.m_col0.m_quad.m128_f32[v13 + 4 * v16]
                              + v7->m_rotation.m_col0.m_quad.m128_f32[v16 + 4i64 * v13])
                      * (float)(0.5 / v17);
  }
  else
  {
    v9 = fsqrt(v8 + 1.0);
    v10 = (float)(t1->m_rotation.m_col2.m_quad.m128_f32[0] - t1->m_rotation.m_col0.m_quad.m128_f32[2])
        * (float)(0.5 / v9);
    v37.m128_f32[0] = (float)(t1->m_rotation.m_col1.m_quad.m128_f32[2] - t1->m_rotation.m_col2.m_quad.m128_f32[1])
                    * (float)(0.5 / v9);
    v11 = t1->m_rotation.m_col0.m_quad.m128_f32[1];
    v37.m128_f32[1] = v10;
    v12 = v11 - t1->m_rotation.m_col1.m_quad.m128_f32[0];
    v37.m128_f32[3] = v9 * 0.5;
    v37.m128_f32[2] = v12 * (float)(0.5 / v9);
  }
  v19 = v6->m_translation.m_quad;
  v20 = _mm_mul_ps(v37, v37);
  v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 78), v20);
  v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 177), v21);
  v23 = _mm_rsqrt_ps(v22);
  v24 = _mm_mul_ps(
          v37,
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)), _mm_mul_ps(*(__m128 *)_xmm, v23)));
  v25 = _mm_mul_ps(v6->m_translation.m_quad, v24);
  v26 = _mm_shuffle_ps(v24, v24, 255);
  v27 = _mm_shuffle_ps(v24, v24, 201);
  v28 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v24), _mm_mul_ps(v27, v19));
  v29 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                _mm_shuffle_ps(v25, v25, 170)),
              v24),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v26, v26), (__m128)xmmword_141A711B0), v19)),
          _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v26));
  this->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v29, v29), v7->m_translation.m_quad);
  v30 = v6->m_rotation.m_vec.m_quad;
  v31 = _mm_shuffle_ps(v30, v30, 255);
  v32 = _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v24);
  v33 = _mm_mul_ps(v24, v31);
  v34 = _mm_mul_ps(v24, v6->m_rotation.m_vec.m_quad);
  v35 = _mm_sub_ps(v32, _mm_mul_ps(v27, v6->m_rotation.m_vec.m_quad));
  v36 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v35, v35, 201), _mm_mul_ps(v26, v6->m_rotation.m_vec.m_quad)), v33);
  this->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                    v36,
                                    _mm_unpackhi_ps(
                                      v36,
                                      _mm_sub_ps(
                                        _mm_mul_ps(v31, v26),
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                                          _mm_shuffle_ps(v34, v34, 170)))),
                                    196);
}

// File Line: 45
// RVA: 0xC71420
void __fastcall hkQTransformf::setMul(hkQTransformf *this, hkTransformf *t1, hkTransformf *t2)
{
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm3_4
  signed int v6; // edi
  hkTransformf *v7; // rbx
  hkTransformf *v8; // r11
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  signed int v14; // edx
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r9
  float v18; // xmm0_4
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm0
  float v24; // xmm2_4
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  float v27; // xmm3_4
  __m128 v28; // xmm8
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm3_4
  float v33; // xmm0_4
  float v34; // xmm0_4
  __int64 v35; // r8
  __int64 v36; // r9
  float v37; // xmm0_4
  __m128 v38; // xmm4
  __m128 v39; // xmm5
  __m128 v40; // xmm0
  __m128 v41; // xmm6
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  __m128 v44; // xmm2
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm3
  __m128 v48; // xmm7
  __m128 v49; // xmm2
  __m128 v50; // xmm3
  __m128 v51; // xmm2
  __m128 v52; // xmm0
  __m128 v53; // xmm7
  __m128 v54; // xmm2
  __m128 v55; // [rsp+0h] [rbp-60h]

  v3 = t1->m_rotation.m_col0.m_quad.m128_f32[0];
  v4 = t1->m_rotation.m_col1.m_quad.m128_f32[1];
  v5 = t1->m_rotation.m_col2.m_quad.m128_f32[2];
  v6 = 0;
  v7 = t2;
  v8 = t1;
  v9 = (float)(t1->m_rotation.m_col0.m_quad.m128_f32[0] + v4) + v5;
  if ( v9 <= 0.0 )
  {
    v55.m128_i32[0] = 1;
    *(unsigned __int64 *)((char *)v55.m128_u64 + 4) = 2i64;
    v14 = 0;
    if ( v4 > v3 )
      v14 = 1;
    if ( v5 > v8->m_rotation.m_col0.m_quad.m128_f32[5 * v14] )
      v14 = 2;
    v15 = v14;
    v16 = v55.m128_i32[v14];
    v17 = v55.m128_i32[v16];
    v18 = fsqrt(
            (float)(v8->m_rotation.m_col0.m_quad.m128_f32[5 * v14]
                  - (float)(v8->m_rotation.m_col0.m_quad.m128_f32[5 * v17]
                          + v8->m_rotation.m_col0.m_quad.m128_f32[5 * v16]))
          + 1.0);
    v55.m128_f32[v15] = v18 * 0.5;
    v55.m128_f32[3] = (float)(v8->m_rotation.m_col0.m_quad.m128_f32[v17 + 4 * v16]
                            - v8->m_rotation.m_col0.m_quad.m128_f32[v16 + 4 * v17])
                    * (float)(0.5 / v18);
    v55.m128_f32[v16] = (float)(v8->m_rotation.m_col0.m_quad.m128_f32[v16 + 4 * v15]
                              + v8->m_rotation.m_col0.m_quad.m128_f32[v15 + 4 * v16])
                      * (float)(0.5 / v18);
    v55.m128_f32[v17] = (float)(v8->m_rotation.m_col0.m_quad.m128_f32[v14 + 4 * v17]
                              + v8->m_rotation.m_col0.m_quad.m128_f32[v17 + 4i64 * v14])
                      * (float)(0.5 / v18);
  }
  else
  {
    v10 = t1->m_rotation.m_col2.m_quad.m128_f32[0] - t1->m_rotation.m_col0.m_quad.m128_f32[2];
    v11 = fsqrt(v9 + 1.0);
    v12 = t1->m_rotation.m_col1.m_quad.m128_f32[2] - t1->m_rotation.m_col2.m_quad.m128_f32[1];
    v55.m128_f32[3] = v11 * 0.5;
    v55.m128_f32[0] = v12 * (float)(0.5 / v11);
    v13 = t1->m_rotation.m_col0.m_quad.m128_f32[1];
    v55.m128_f32[1] = v10 * (float)(0.5 / v11);
    v55.m128_f32[2] = (float)(v13 - t1->m_rotation.m_col1.m_quad.m128_f32[0]) * (float)(0.5 / v11);
  }
  v19 = _mm_mul_ps(v55, v55);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 78), v19);
  v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 177), v20);
  v22 = _mm_rsqrt_ps(v21);
  v23 = _mm_mul_ps(v22, v21);
  v24 = v7->m_rotation.m_col0.m_quad.m128_f32[0];
  v25 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v22));
  v26 = _mm_mul_ps(*(__m128 *)_xmm, v22);
  v27 = v7->m_rotation.m_col2.m_quad.m128_f32[2];
  v28 = _mm_mul_ps(v55, _mm_mul_ps(v25, v26));
  v29 = v7->m_rotation.m_col1.m_quad.m128_f32[1];
  v30 = (float)(v7->m_rotation.m_col0.m_quad.m128_f32[0] + v29) + v27;
  if ( v30 <= 0.0 )
  {
    v55.m128_i32[0] = 1;
    *(unsigned __int64 *)((char *)v55.m128_u64 + 4) = 2i64;
    if ( v29 > v24 )
      v6 = 1;
    if ( v27 > v7->m_rotation.m_col0.m_quad.m128_f32[5 * v6] )
      v6 = 2;
    v35 = v55.m128_i32[v6];
    v36 = v55.m128_i32[v35];
    v37 = fsqrt(
            (float)(v7->m_rotation.m_col0.m_quad.m128_f32[5 * v6]
                  - (float)(v7->m_rotation.m_col0.m_quad.m128_f32[5 * v36]
                          + v7->m_rotation.m_col0.m_quad.m128_f32[5 * v35]))
          + 1.0);
    v55.m128_f32[v6] = v37 * 0.5;
    v55.m128_f32[3] = (float)(v7->m_rotation.m_col0.m_quad.m128_f32[v36 + 4 * v35]
                            - v7->m_rotation.m_col0.m_quad.m128_f32[v35 + 4 * v36])
                    * (float)(0.5 / v37);
    v55.m128_f32[v35] = (float)(v7->m_rotation.m_col0.m_quad.m128_f32[v35 + 4i64 * v6]
                              + v7->m_rotation.m_col0.m_quad.m128_f32[v6 + 4 * v35])
                      * (float)(0.5 / v37);
    v55.m128_f32[v36] = (float)(v7->m_rotation.m_col0.m_quad.m128_f32[v6 + 4 * v36]
                              + v7->m_rotation.m_col0.m_quad.m128_f32[v36 + 4i64 * v6])
                      * (float)(0.5 / v37);
  }
  else
  {
    v31 = v7->m_rotation.m_col2.m_quad.m128_f32[0] - v7->m_rotation.m_col0.m_quad.m128_f32[2];
    v32 = fsqrt(v30 + 1.0);
    v33 = v7->m_rotation.m_col1.m_quad.m128_f32[2] - v7->m_rotation.m_col2.m_quad.m128_f32[1];
    v55.m128_f32[3] = v32 * 0.5;
    v55.m128_f32[0] = v33 * (float)(0.5 / v32);
    v34 = v7->m_rotation.m_col0.m_quad.m128_f32[1];
    v55.m128_f32[1] = v31 * (float)(0.5 / v32);
    v55.m128_f32[2] = (float)(v34 - v7->m_rotation.m_col1.m_quad.m128_f32[0]) * (float)(0.5 / v32);
  }
  v38 = v7->m_translation.m_quad;
  v39 = _mm_shuffle_ps(v28, v28, 201);
  v40 = _mm_mul_ps(v55, v55);
  v41 = _mm_shuffle_ps(v28, v28, 255);
  v42 = _mm_add_ps(_mm_shuffle_ps(v40, v40, 78), v40);
  v43 = _mm_add_ps(_mm_shuffle_ps(v42, v42, 177), v42);
  v44 = _mm_rsqrt_ps(v43);
  v45 = _mm_mul_ps(_mm_mul_ps(v44, v43), v44);
  v46 = _mm_mul_ps(v7->m_translation.m_quad, v28);
  v47 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), v28), _mm_mul_ps(v7->m_translation.m_quad, v39));
  v48 = _mm_mul_ps(v55, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v45), _mm_mul_ps(*(__m128 *)_xmm, v44)));
  v49 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
                _mm_shuffle_ps(v46, v46, 170)),
              v28),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v41, v41), (__m128)xmmword_141A711B0), v38)),
          _mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v41));
  v50 = _mm_shuffle_ps(v48, v48, 255);
  this->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v49, v49), v8->m_translation.m_quad);
  v51 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v48, v48, 201), v28), _mm_mul_ps(v48, v39));
  v52 = v48;
  v53 = _mm_mul_ps(v48, v28);
  v54 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v51, v51, 201), _mm_mul_ps(v52, v41)), _mm_mul_ps(v28, v50));
  this->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                    v54,
                                    _mm_unpackhi_ps(
                                      v54,
                                      _mm_sub_ps(
                                        _mm_mul_ps(v50, v41),
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v53, v53, 85), _mm_shuffle_ps(v53, v53, 0)),
                                          _mm_shuffle_ps(v53, v53, 170)))),
                                    196);
}

// File Line: 60
// RVA: 0xC718A0
void __fastcall hkQTransformf::setMul(hkQTransformf *this, hkQTransformf *qt1, hkTransformf *t2)
{
  float v3; // xmm3_4
  float v4; // xmm2_4
  float v5; // xmm4_4
  hkTransformf *v6; // r11
  hkQTransformf *v7; // rbx
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  signed int v13; // edx
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r9
  float v17; // xmm2_4
  float v18; // xmm0_4
  __m128 v19; // xmm5
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm7
  __m128 v25; // xmm6
  __m128 v26; // xmm1
  __m128 v27; // xmm4
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  __m128 v30; // xmm3
  __m128 v31; // xmm5
  __m128 v32; // xmm0
  __m128 v33; // xmm7
  __m128 v34; // xmm5
  __m128 v35; // [rsp+0h] [rbp-38h]

  v3 = t2->m_rotation.m_col0.m_quad.m128_f32[0];
  v4 = t2->m_rotation.m_col1.m_quad.m128_f32[1];
  v5 = t2->m_rotation.m_col2.m_quad.m128_f32[2];
  v6 = t2;
  v7 = qt1;
  v8 = (float)(t2->m_rotation.m_col0.m_quad.m128_f32[0] + v4) + v5;
  if ( v8 <= 0.0 )
  {
    v13 = 0;
    v35.m128_i32[0] = 1;
    if ( v4 > v3 )
      v13 = 1;
    *(unsigned __int64 *)((char *)v35.m128_u64 + 4) = 2i64;
    if ( v5 > t2->m_rotation.m_col0.m_quad.m128_f32[5 * v13] )
      v13 = 2;
    v14 = v13;
    v15 = v35.m128_i32[v13];
    v16 = v35.m128_i32[v15];
    v17 = fsqrt(
            (float)(v6->m_rotation.m_col0.m_quad.m128_f32[5 * v13]
                  - (float)(v6->m_rotation.m_col0.m_quad.m128_f32[5 * v16]
                          + v6->m_rotation.m_col0.m_quad.m128_f32[5 * v15]))
          + 1.0);
    v18 = v6->m_rotation.m_col0.m_quad.m128_f32[v16 + 4 * v15] - v6->m_rotation.m_col0.m_quad.m128_f32[v15 + 4 * v16];
    v35.m128_f32[v14] = v17 * 0.5;
    v35.m128_f32[3] = v18 * (float)(0.5 / v17);
    v35.m128_f32[v15] = (float)(v6->m_rotation.m_col0.m_quad.m128_f32[v15 + 4 * v14]
                              + v6->m_rotation.m_col0.m_quad.m128_f32[v14 + 4 * v15])
                      * (float)(0.5 / v17);
    v35.m128_f32[v16] = (float)(v6->m_rotation.m_col0.m_quad.m128_f32[v13 + 4 * v16]
                              + v6->m_rotation.m_col0.m_quad.m128_f32[v16 + 4i64 * v13])
                      * (float)(0.5 / v17);
  }
  else
  {
    v9 = fsqrt(v8 + 1.0);
    v10 = (float)(t2->m_rotation.m_col2.m_quad.m128_f32[0] - t2->m_rotation.m_col0.m_quad.m128_f32[2])
        * (float)(0.5 / v9);
    v35.m128_f32[0] = (float)(t2->m_rotation.m_col1.m_quad.m128_f32[2] - t2->m_rotation.m_col2.m_quad.m128_f32[1])
                    * (float)(0.5 / v9);
    v11 = t2->m_rotation.m_col0.m_quad.m128_f32[1];
    v35.m128_f32[1] = v10;
    v12 = v11 - t2->m_rotation.m_col1.m_quad.m128_f32[0];
    v35.m128_f32[3] = v9 * 0.5;
    v35.m128_f32[2] = v12 * (float)(0.5 / v9);
  }
  v19 = v6->m_translation.m_quad;
  v20 = _mm_mul_ps(v35, v35);
  v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 78), v20);
  v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 177), v21);
  v23 = _mm_rsqrt_ps(v22);
  v24 = _mm_mul_ps(
          v35,
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)), _mm_mul_ps(*(__m128 *)_xmm, v23)));
  v25 = _mm_shuffle_ps(v7->m_rotation.m_vec.m_quad, v7->m_rotation.m_vec.m_quad, 255);
  v26 = _mm_mul_ps(v7->m_rotation.m_vec.m_quad, v19);
  v27 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v7->m_rotation.m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v7->m_rotation.m_vec.m_quad, v7->m_rotation.m_vec.m_quad, 201), v19));
  v28 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                _mm_shuffle_ps(v26, v26, 170)),
              v7->m_rotation.m_vec.m_quad),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v25, v25), (__m128)xmmword_141A711B0), v19)),
          _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v25));
  v29 = _mm_shuffle_ps(v24, v24, 255);
  this->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v28, v28), v7->m_translation.m_quad);
  v30 = _mm_shuffle_ps(v7->m_rotation.m_vec.m_quad, v7->m_rotation.m_vec.m_quad, 255);
  v31 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v7->m_rotation.m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v7->m_rotation.m_vec.m_quad, v7->m_rotation.m_vec.m_quad, 201), v24));
  v32 = v24;
  v33 = _mm_mul_ps(v24, v7->m_rotation.m_vec.m_quad);
  v34 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v31, v31, 201), _mm_mul_ps(v32, v30)),
          _mm_mul_ps(v29, v7->m_rotation.m_vec.m_quad));
  this->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                    v34,
                                    _mm_unpackhi_ps(
                                      v34,
                                      _mm_sub_ps(
                                        _mm_mul_ps(v29, v30),
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
                                          _mm_shuffle_ps(v33, v33, 170)))),
                                    196);
}

// File Line: 73
// RVA: 0xC71B70
void __fastcall hkQTransformf::setMulInverseMul(hkQTransformf *this, hkQTransformf *qt1, hkQTransformf *qt2)
{
  __m128 v3; // xmm4
  __m128 v4; // xmm6
  __m128 v5; // xmm7
  __m128 v6; // xmm5
  __m128 v7; // xmm3
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm2

  v3 = _mm_shuffle_ps(qt2->m_rotation.m_vec.m_quad, qt2->m_rotation.m_vec.m_quad, 255);
  v4 = _mm_xor_ps(
         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
         qt1->m_rotation.m_vec.m_quad);
  v5 = _mm_shuffle_ps(v4, v4, 255);
  v6 = _mm_shuffle_ps(v4, v4, 201);
  v7 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(qt2->m_rotation.m_vec.m_quad, qt2->m_rotation.m_vec.m_quad, 201), v4),
         _mm_mul_ps(v6, qt2->m_rotation.m_vec.m_quad));
  v8 = _mm_add_ps(
         _mm_add_ps(_mm_shuffle_ps(v7, v7, 201), _mm_mul_ps(v5, qt2->m_rotation.m_vec.m_quad)),
         _mm_mul_ps(v4, v3));
  v9 = _mm_mul_ps(v4, qt2->m_rotation.m_vec.m_quad);
  this->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                    v8,
                                    _mm_unpackhi_ps(
                                      v8,
                                      _mm_sub_ps(
                                        _mm_mul_ps(v3, v5),
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)),
                                          _mm_shuffle_ps(v9, v9, 170)))),
                                    196);
  v10 = _mm_sub_ps(qt2->m_translation.m_quad, qt1->m_translation.m_quad);
  v11 = _mm_mul_ps(v4, v10);
  v12 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v4), _mm_mul_ps(v6, v10));
  v13 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                _mm_shuffle_ps(v11, v11, 170)),
              v4),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v5, v5), (__m128)xmmword_141A711B0), v10)),
          _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v5));
  this->m_translation.m_quad = _mm_add_ps(v13, v13);
}

// File Line: 81
// RVA: 0xC71C80
void __fastcall hkQTransformf::setMulInverseMul(hkQTransformf *this, hkTransformf *t1, hkQTransformf *qt2)
{
  float v3; // xmm3_4
  float v4; // xmm2_4
  float v5; // xmm4_4
  hkQTransformf *v6; // rbx
  hkTransformf *v7; // r11
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  signed int v13; // edx
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r9
  float v17; // xmm2_4
  float v18; // xmm0_4
  __m128 v19; // xmm6
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm7
  __m128 v26; // xmm8
  __m128 v27; // xmm5
  __m128 v28; // xmm3
  __m128 v29; // xmm3
  __m128 v30; // xmm1
  __m128 v31; // xmm3
  __m128 v32; // xmm1
  __m128 v33; // xmm4
  __m128 v34; // xmm2
  __m128 v35; // [rsp+0h] [rbp-48h]

  v3 = t1->m_rotation.m_col0.m_quad.m128_f32[0];
  v4 = t1->m_rotation.m_col1.m_quad.m128_f32[1];
  v5 = t1->m_rotation.m_col2.m_quad.m128_f32[2];
  v6 = qt2;
  v7 = t1;
  v8 = (float)(t1->m_rotation.m_col0.m_quad.m128_f32[0] + v4) + v5;
  if ( v8 <= 0.0 )
  {
    v13 = 0;
    v35.m128_i32[0] = 1;
    if ( v4 > v3 )
      v13 = 1;
    *(unsigned __int64 *)((char *)v35.m128_u64 + 4) = 2i64;
    if ( v5 > v7->m_rotation.m_col0.m_quad.m128_f32[5 * v13] )
      v13 = 2;
    v14 = v13;
    v15 = v35.m128_i32[v13];
    v16 = v35.m128_i32[v15];
    v17 = fsqrt(
            (float)(v7->m_rotation.m_col0.m_quad.m128_f32[5 * v13]
                  - (float)(v7->m_rotation.m_col0.m_quad.m128_f32[5 * v16]
                          + v7->m_rotation.m_col0.m_quad.m128_f32[5 * v15]))
          + 1.0);
    v18 = v7->m_rotation.m_col0.m_quad.m128_f32[v16 + 4 * v15] - v7->m_rotation.m_col0.m_quad.m128_f32[v15 + 4 * v16];
    v35.m128_f32[v14] = v17 * 0.5;
    v35.m128_f32[3] = v18 * (float)(0.5 / v17);
    v35.m128_f32[v15] = (float)(v7->m_rotation.m_col0.m_quad.m128_f32[v15 + 4 * v14]
                              + v7->m_rotation.m_col0.m_quad.m128_f32[v14 + 4 * v15])
                      * (float)(0.5 / v17);
    v35.m128_f32[v16] = (float)(v7->m_rotation.m_col0.m_quad.m128_f32[v13 + 4 * v16]
                              + v7->m_rotation.m_col0.m_quad.m128_f32[v16 + 4i64 * v13])
                      * (float)(0.5 / v17);
  }
  else
  {
    v9 = fsqrt(v8 + 1.0);
    v10 = (float)(t1->m_rotation.m_col2.m_quad.m128_f32[0] - t1->m_rotation.m_col0.m_quad.m128_f32[2])
        * (float)(0.5 / v9);
    v35.m128_f32[0] = (float)(t1->m_rotation.m_col1.m_quad.m128_f32[2] - t1->m_rotation.m_col2.m_quad.m128_f32[1])
                    * (float)(0.5 / v9);
    v11 = t1->m_rotation.m_col0.m_quad.m128_f32[1];
    v35.m128_f32[1] = v10;
    v12 = v11 - t1->m_rotation.m_col1.m_quad.m128_f32[0];
    v35.m128_f32[3] = v9 * 0.5;
    v35.m128_f32[2] = v12 * (float)(0.5 / v9);
  }
  v19 = v7->m_translation.m_quad;
  v20 = _mm_mul_ps(v35, v35);
  v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 78), v20);
  v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 177), v21);
  v23 = _mm_rsqrt_ps(v22);
  v24 = _mm_shuffle_ps(v6->m_rotation.m_vec.m_quad, v6->m_rotation.m_vec.m_quad, 255);
  v25 = _mm_xor_ps(
          (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
          _mm_mul_ps(
            v35,
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
              _mm_mul_ps(*(__m128 *)_xmm, v23))));
  v26 = _mm_shuffle_ps(v25, v25, 255);
  v27 = _mm_shuffle_ps(v25, v25, 201);
  v28 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v6->m_rotation.m_vec.m_quad, v6->m_rotation.m_vec.m_quad, 201), v25),
          _mm_mul_ps(v27, v6->m_rotation.m_vec.m_quad));
  v29 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v28, v28, 201), _mm_mul_ps(v26, v6->m_rotation.m_vec.m_quad)),
          _mm_mul_ps(v25, v24));
  v30 = _mm_mul_ps(v25, v6->m_rotation.m_vec.m_quad);
  this->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                    v29,
                                    _mm_unpackhi_ps(
                                      v29,
                                      _mm_sub_ps(
                                        _mm_mul_ps(v24, v26),
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                                          _mm_shuffle_ps(v30, v30, 170)))),
                                    196);
  v31 = _mm_sub_ps(v6->m_translation.m_quad, v19);
  v32 = _mm_mul_ps(v25, v31);
  v33 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v25), _mm_mul_ps(v27, v31));
  v34 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                _mm_shuffle_ps(v32, v32, 170)),
              v25),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v26, v26), (__m128)xmmword_141A711B0), v31)),
          _mm_mul_ps(_mm_shuffle_ps(v33, v33, 201), v26));
  this->m_translation.m_quad = _mm_add_ps(v34, v34);
}

// File Line: 94
// RVA: 0xC71F60
void __fastcall hkQTransformf::setMulInverseMul(hkQTransformf *this, hkQTransformf *qt1, hkTransformf *t2)
{
  float v3; // xmm3_4
  float v4; // xmm2_4
  float v5; // xmm4_4
  hkTransformf *v6; // r11
  hkQTransformf *v7; // rbx
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  signed int v13; // edx
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r9
  float v17; // xmm2_4
  float v18; // xmm0_4
  __m128 v19; // xmm9
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm6
  __m128 v25; // xmm4
  __m128 v26; // xmm7
  __m128 v27; // xmm8
  __m128 v28; // xmm5
  __m128 v29; // xmm3
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  __m128 v32; // xmm9
  __m128 v33; // xmm1
  __m128 v34; // xmm3
  __m128 v35; // xmm2
  __m128 v36; // [rsp+0h] [rbp-58h]

  v3 = t2->m_rotation.m_col0.m_quad.m128_f32[0];
  v4 = t2->m_rotation.m_col1.m_quad.m128_f32[1];
  v5 = t2->m_rotation.m_col2.m_quad.m128_f32[2];
  v6 = t2;
  v7 = qt1;
  v8 = (float)(t2->m_rotation.m_col0.m_quad.m128_f32[0] + v4) + v5;
  if ( v8 <= 0.0 )
  {
    v13 = 0;
    v36.m128_i32[0] = 1;
    if ( v4 > v3 )
      v13 = 1;
    *(unsigned __int64 *)((char *)v36.m128_u64 + 4) = 2i64;
    if ( v5 > t2->m_rotation.m_col0.m_quad.m128_f32[5 * v13] )
      v13 = 2;
    v14 = v13;
    v15 = v36.m128_i32[v13];
    v16 = v36.m128_i32[v15];
    v17 = fsqrt(
            (float)(v6->m_rotation.m_col0.m_quad.m128_f32[5 * v13]
                  - (float)(v6->m_rotation.m_col0.m_quad.m128_f32[5 * v16]
                          + v6->m_rotation.m_col0.m_quad.m128_f32[5 * v15]))
          + 1.0);
    v18 = v6->m_rotation.m_col0.m_quad.m128_f32[v16 + 4 * v15] - v6->m_rotation.m_col0.m_quad.m128_f32[v15 + 4 * v16];
    v36.m128_f32[v14] = v17 * 0.5;
    v36.m128_f32[3] = v18 * (float)(0.5 / v17);
    v36.m128_f32[v15] = (float)(v6->m_rotation.m_col0.m_quad.m128_f32[v15 + 4 * v14]
                              + v6->m_rotation.m_col0.m_quad.m128_f32[v14 + 4 * v15])
                      * (float)(0.5 / v17);
    v36.m128_f32[v16] = (float)(v6->m_rotation.m_col0.m_quad.m128_f32[v13 + 4 * v16]
                              + v6->m_rotation.m_col0.m_quad.m128_f32[v16 + 4i64 * v13])
                      * (float)(0.5 / v17);
  }
  else
  {
    v9 = fsqrt(v8 + 1.0);
    v10 = (float)(t2->m_rotation.m_col2.m_quad.m128_f32[0] - t2->m_rotation.m_col0.m_quad.m128_f32[2])
        * (float)(0.5 / v9);
    v36.m128_f32[0] = (float)(t2->m_rotation.m_col1.m_quad.m128_f32[2] - t2->m_rotation.m_col2.m_quad.m128_f32[1])
                    * (float)(0.5 / v9);
    v11 = t2->m_rotation.m_col0.m_quad.m128_f32[1];
    v36.m128_f32[1] = v10;
    v12 = v11 - t2->m_rotation.m_col1.m_quad.m128_f32[0];
    v36.m128_f32[3] = v9 * 0.5;
    v36.m128_f32[2] = v12 * (float)(0.5 / v9);
  }
  v19 = v6->m_translation.m_quad;
  v20 = _mm_mul_ps(v36, v36);
  v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 78), v20);
  v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 177), v21);
  v23 = _mm_rsqrt_ps(v22);
  v24 = _mm_mul_ps(
          v36,
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)), _mm_mul_ps(*(__m128 *)_xmm, v23)));
  v25 = _mm_shuffle_ps(v24, v24, 255);
  v26 = _mm_xor_ps(
          (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
          v7->m_rotation.m_vec.m_quad);
  v27 = _mm_shuffle_ps(v26, v26, 255);
  v28 = _mm_shuffle_ps(v26, v26, 201);
  v29 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v26), _mm_mul_ps(v28, v24));
  v30 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v29, v29, 201), _mm_mul_ps(v24, v27)), _mm_mul_ps(v26, v25));
  v31 = _mm_mul_ps(v26, v24);
  this->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                    v30,
                                    _mm_unpackhi_ps(
                                      v30,
                                      _mm_sub_ps(
                                        _mm_mul_ps(v25, v27),
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                                          _mm_shuffle_ps(v31, v31, 170)))),
                                    196);
  v32 = _mm_sub_ps(v19, v7->m_translation.m_quad);
  v33 = _mm_mul_ps(v26, v32);
  v34 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), v26), _mm_mul_ps(v28, v32));
  v35 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
                _mm_shuffle_ps(v33, v33, 170)),
              v26),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v27, v27), (__m128)xmmword_141A711B0), v32)),
          _mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v27));
  this->m_translation.m_quad = _mm_add_ps(v35, v35);
}

// File Line: 107
// RVA: 0xC72260
void __fastcall hkQTransformf::setMulInverseMul(hkQTransformf *this, hkTransformf *t1, hkTransformf *t2)
{
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm3_4
  signed int v6; // edi
  hkTransformf *v7; // rbx
  hkTransformf *v8; // r11
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  signed int v14; // edx
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r9
  float v18; // xmm0_4
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm0
  float v24; // xmm2_4
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  float v27; // xmm3_4
  __m128 v28; // xmm9
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm3_4
  float v33; // xmm0_4
  float v34; // xmm0_4
  __int64 v35; // r8
  __int64 v36; // r9
  float v37; // xmm0_4
  __m128 v38; // xmm0
  __m128 v39; // xmm2
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm7
  __m128 v43; // xmm10
  __m128 v44; // xmm4
  __m128 v45; // xmm8
  __m128 v46; // xmm9
  __m128 v47; // xmm5
  __m128 v48; // xmm3
  __m128 v49; // xmm3
  __m128 v50; // xmm1
  __m128 v51; // xmm2
  __m128 v52; // xmm1
  __m128 v53; // xmm3
  __m128 v54; // xmm2
  __m128 v55; // [rsp+0h] [rbp-60h]

  v3 = t1->m_rotation.m_col0.m_quad.m128_f32[0];
  v4 = t1->m_rotation.m_col1.m_quad.m128_f32[1];
  v5 = t1->m_rotation.m_col2.m_quad.m128_f32[2];
  v6 = 0;
  v7 = t2;
  v8 = t1;
  v9 = (float)(t1->m_rotation.m_col0.m_quad.m128_f32[0] + v4) + v5;
  if ( v9 <= 0.0 )
  {
    v55.m128_i32[0] = 1;
    *(unsigned __int64 *)((char *)v55.m128_u64 + 4) = 2i64;
    v14 = 0;
    if ( v4 > v3 )
      v14 = 1;
    if ( v5 > v8->m_rotation.m_col0.m_quad.m128_f32[5 * v14] )
      v14 = 2;
    v15 = v14;
    v16 = v55.m128_i32[v14];
    v17 = v55.m128_i32[v16];
    v18 = fsqrt(
            (float)(v8->m_rotation.m_col0.m_quad.m128_f32[5 * v14]
                  - (float)(v8->m_rotation.m_col0.m_quad.m128_f32[5 * v17]
                          + v8->m_rotation.m_col0.m_quad.m128_f32[5 * v16]))
          + 1.0);
    v55.m128_f32[v15] = v18 * 0.5;
    v55.m128_f32[3] = (float)(v8->m_rotation.m_col0.m_quad.m128_f32[v17 + 4 * v16]
                            - v8->m_rotation.m_col0.m_quad.m128_f32[v16 + 4 * v17])
                    * (float)(0.5 / v18);
    v55.m128_f32[v16] = (float)(v8->m_rotation.m_col0.m_quad.m128_f32[v16 + 4 * v15]
                              + v8->m_rotation.m_col0.m_quad.m128_f32[v15 + 4 * v16])
                      * (float)(0.5 / v18);
    v55.m128_f32[v17] = (float)(v8->m_rotation.m_col0.m_quad.m128_f32[v14 + 4 * v17]
                              + v8->m_rotation.m_col0.m_quad.m128_f32[v17 + 4i64 * v14])
                      * (float)(0.5 / v18);
  }
  else
  {
    v10 = t1->m_rotation.m_col2.m_quad.m128_f32[0] - t1->m_rotation.m_col0.m_quad.m128_f32[2];
    v11 = fsqrt(v9 + 1.0);
    v12 = t1->m_rotation.m_col1.m_quad.m128_f32[2] - t1->m_rotation.m_col2.m_quad.m128_f32[1];
    v55.m128_f32[3] = v11 * 0.5;
    v55.m128_f32[0] = v12 * (float)(0.5 / v11);
    v13 = t1->m_rotation.m_col0.m_quad.m128_f32[1];
    v55.m128_f32[1] = v10 * (float)(0.5 / v11);
    v55.m128_f32[2] = (float)(v13 - t1->m_rotation.m_col1.m_quad.m128_f32[0]) * (float)(0.5 / v11);
  }
  v19 = _mm_mul_ps(v55, v55);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 78), v19);
  v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 177), v20);
  v22 = _mm_rsqrt_ps(v21);
  v23 = _mm_mul_ps(v22, v21);
  v24 = v7->m_rotation.m_col0.m_quad.m128_f32[0];
  v25 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v22));
  v26 = _mm_mul_ps(*(__m128 *)_xmm, v22);
  v27 = v7->m_rotation.m_col2.m_quad.m128_f32[2];
  v28 = _mm_mul_ps(v55, _mm_mul_ps(v25, v26));
  v29 = v7->m_rotation.m_col1.m_quad.m128_f32[1];
  v30 = (float)(v7->m_rotation.m_col0.m_quad.m128_f32[0] + v29) + v27;
  if ( v30 <= 0.0 )
  {
    v55.m128_i32[0] = 1;
    *(unsigned __int64 *)((char *)v55.m128_u64 + 4) = 2i64;
    if ( v29 > v24 )
      v6 = 1;
    if ( v27 > v7->m_rotation.m_col0.m_quad.m128_f32[5 * v6] )
      v6 = 2;
    v35 = v55.m128_i32[v6];
    v36 = v55.m128_i32[v35];
    v37 = fsqrt(
            (float)(v7->m_rotation.m_col0.m_quad.m128_f32[5 * v6]
                  - (float)(v7->m_rotation.m_col0.m_quad.m128_f32[5 * v36]
                          + v7->m_rotation.m_col0.m_quad.m128_f32[5 * v35]))
          + 1.0);
    v55.m128_f32[v6] = v37 * 0.5;
    v55.m128_f32[3] = (float)(v7->m_rotation.m_col0.m_quad.m128_f32[v36 + 4 * v35]
                            - v7->m_rotation.m_col0.m_quad.m128_f32[v35 + 4 * v36])
                    * (float)(0.5 / v37);
    v55.m128_f32[v35] = (float)(v7->m_rotation.m_col0.m_quad.m128_f32[v35 + 4i64 * v6]
                              + v7->m_rotation.m_col0.m_quad.m128_f32[v6 + 4 * v35])
                      * (float)(0.5 / v37);
    v55.m128_f32[v36] = (float)(v7->m_rotation.m_col0.m_quad.m128_f32[v6 + 4 * v36]
                              + v7->m_rotation.m_col0.m_quad.m128_f32[v36 + 4i64 * v6])
                      * (float)(0.5 / v37);
  }
  else
  {
    v31 = v7->m_rotation.m_col2.m_quad.m128_f32[0] - v7->m_rotation.m_col0.m_quad.m128_f32[2];
    v32 = fsqrt(v30 + 1.0);
    v33 = v7->m_rotation.m_col1.m_quad.m128_f32[2] - v7->m_rotation.m_col2.m_quad.m128_f32[1];
    v55.m128_f32[3] = v32 * 0.5;
    v55.m128_f32[0] = v33 * (float)(0.5 / v32);
    v34 = v7->m_rotation.m_col0.m_quad.m128_f32[1];
    v55.m128_f32[1] = v31 * (float)(0.5 / v32);
    v55.m128_f32[2] = (float)(v34 - v7->m_rotation.m_col1.m_quad.m128_f32[0]) * (float)(0.5 / v32);
  }
  v38 = _mm_mul_ps(v55, v55);
  v39 = _mm_add_ps(_mm_shuffle_ps(v38, v38, 78), v38);
  v40 = _mm_add_ps(_mm_shuffle_ps(v39, v39, 177), v39);
  v41 = _mm_rsqrt_ps(v40);
  v42 = _mm_mul_ps(
          v55,
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v41, v40), v41)), _mm_mul_ps(*(__m128 *)_xmm, v41)));
  v43 = _mm_sub_ps(v7->m_translation.m_quad, v8->m_translation.m_quad);
  v44 = _mm_shuffle_ps(v42, v42, 255);
  v45 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64), v28);
  v46 = _mm_shuffle_ps(v45, v45, 255);
  v47 = _mm_shuffle_ps(v45, v45, 201);
  v48 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v45), _mm_mul_ps(v42, v47));
  v49 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v48, v48, 201), _mm_mul_ps(v42, v46)), _mm_mul_ps(v45, v44));
  v50 = _mm_mul_ps(v45, v42);
  v51 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)), _mm_shuffle_ps(v50, v50, 170));
  v52 = _mm_mul_ps(v45, v43);
  this->m_rotation.m_vec.m_quad = _mm_shuffle_ps(v49, _mm_unpackhi_ps(v49, _mm_sub_ps(_mm_mul_ps(v44, v46), v51)), 196);
  v53 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), v45), _mm_mul_ps(v43, v47));
  v54 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                _mm_shuffle_ps(v52, v52, 170)),
              v45),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v46, v46), (__m128)xmmword_141A711B0), v43)),
          _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v46));
  this->m_translation.m_quad = _mm_add_ps(v54, v54);
}

// File Line: 122
// RVA: 0xC72700
void __fastcall hkQTransformf::setMulMulInverse(hkQTransformf *this, hkQTransformf *qt1, hkQTransformf *qt2)
{
  __m128 v3; // xmm3
  __m128 v4; // xmm5
  __m128 v5; // xmm4
  __m128 v6; // xmm6
  __m128 v7; // xmm0
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  hkQuaternionf v10; // xmm6
  hkVector4f v11; // xmm3
  __m128 v12; // xmm1
  __m128 v13; // xmm5
  __m128 v14; // xmm4
  __m128 v15; // xmm2

  v3 = _mm_shuffle_ps(qt1->m_rotation.m_vec.m_quad, qt1->m_rotation.m_vec.m_quad, 255);
  v4 = _mm_xor_ps(
         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
         qt2->m_rotation.m_vec.m_quad);
  v5 = _mm_shuffle_ps(v4, v4, 255);
  v6 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), qt1->m_rotation.m_vec.m_quad),
         _mm_mul_ps(_mm_shuffle_ps(qt1->m_rotation.m_vec.m_quad, qt1->m_rotation.m_vec.m_quad, 201), v4));
  v7 = _mm_mul_ps(v4, v3);
  v8 = _mm_mul_ps(v4, qt1->m_rotation.m_vec.m_quad);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 201), v7), _mm_mul_ps(v5, qt1->m_rotation.m_vec.m_quad));
  v10.m_vec.m_quad = _mm_shuffle_ps(
                       v9,
                       _mm_unpackhi_ps(
                         v9,
                         _mm_sub_ps(
                           _mm_mul_ps(v5, v3),
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)),
                             _mm_shuffle_ps(v8, v8, 170)))),
                       196);
  this->m_rotation = (hkQuaternionf)v10.m_vec.m_quad;
  v11.m_quad = (__m128)qt2->m_translation;
  v12 = _mm_mul_ps(qt2->m_translation.m_quad, v10.m_vec.m_quad);
  v13 = _mm_shuffle_ps(v10.m_vec.m_quad, v10.m_vec.m_quad, 255);
  v14 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(qt2->m_translation.m_quad, v11.m_quad, 201), v10.m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v10.m_vec.m_quad, v10.m_vec.m_quad, 201), v11.m_quad));
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                _mm_shuffle_ps(v12, v12, 170)),
              v10.m_vec.m_quad),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0), v11.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v13));
  this->m_translation.m_quad = _mm_sub_ps(qt1->m_translation.m_quad, _mm_add_ps(v15, v15));
}

// File Line: 127
// RVA: 0xC72810
bool __fastcall hkQTransformf::isApproximatelyEqual(hkQTransformf *this, hkQTransformf *other, float epsilon)
{
  __m128 v3; // xmm0
  __m128 v4; // xmm4
  __m128 v5; // xmm1

  v3 = _mm_mul_ps(other->m_rotation.m_vec.m_quad, this->m_rotation.m_vec.m_quad);
  v4 = _mm_shuffle_ps((__m128)LODWORD(epsilon), (__m128)LODWORD(epsilon), 0);
  v5 = _mm_add_ps(_mm_shuffle_ps(v3, v3, 78), v3);
  return _mm_movemask_ps(
           _mm_cmpltps(
             (__m128)_mm_srli_epi32(
                       _mm_slli_epi32(
                         (__m128i)_mm_sub_ps(
                                    this->m_rotation.m_vec.m_quad,
                                    _mm_xor_ps(
                                      (__m128)_mm_slli_epi32(
                                                _mm_srli_epi32(
                                                  (__m128i)_mm_add_ps(_mm_shuffle_ps(v5, v5, 177), v5),
                                                  0x1Fu),
                                                0x1Fu),
                                      other->m_rotation.m_vec.m_quad)),
                         1u),
                       1u),
             v4)) == 15
      && (_mm_movemask_ps(
            _mm_cmpltps(
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32((__m128i)_mm_sub_ps(this->m_translation.m_quad, other->m_translation.m_quad), 1u),
                        1u),
              v4)) & 7) == 7;
}

// File Line: 137
// RVA: 0xC72890
void __fastcall hkQTransformf::setInterpolate4(hkQTransformf *this, hkQTransformf *qtA, hkQTransformf *qtB, hkSimdFloat32 *t)
{
  __m128 v4; // xmm0
  __m128 v5; // xmm1
  __m128 v6; // xmm4
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  __m128 v10; // xmm2

  v4 = _mm_mul_ps(qtB->m_rotation.m_vec.m_quad, qtA->m_rotation.m_vec.m_quad);
  v5 = _mm_add_ps(_mm_shuffle_ps(v4, v4, 78), v4);
  v6 = _mm_add_ps(
         _mm_mul_ps(
           _mm_sub_ps(
             _mm_xor_ps(
               (__m128)_mm_slli_epi32(
                         _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v5, v5, 177), v5), 0x1Fu),
                         0x1Fu),
               qtB->m_rotation.m_vec.m_quad),
             qtA->m_rotation.m_vec.m_quad),
           t->m_real),
         qtA->m_rotation.m_vec.m_quad);
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_add_ps(_mm_shuffle_ps(v7, v7, 78), v7);
  v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 177), v8);
  v10 = _mm_rsqrt_ps(v9);
  this->m_rotation.m_vec.m_quad = _mm_mul_ps(
                                    v6,
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                                      _mm_mul_ps(*(__m128 *)_xmm, v10)));
  this->m_translation.m_quad = _mm_add_ps(
                                 _mm_mul_ps(_mm_sub_ps(qtB->m_translation.m_quad, qtA->m_translation.m_quad), t->m_real),
                                 qtA->m_translation.m_quad);
}

// File Line: 164
// RVA: 0xC72930
bool __fastcall hkQTransformf::isOk(hkQTransformf *this)
{
  return !(_mm_movemask_ps(_mm_cmpunordps(this->m_translation.m_quad, this->m_translation.m_quad)) & 7)
      && (unsigned int)hkQuaternionf::isOk(&this->m_rotation, 0.001);
}


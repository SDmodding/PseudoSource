// File Line: 15
// RVA: 0xC70FB0
void __fastcall hkQTransformf::setInverse(hkQTransformf *this, hkQTransformf *qt)
{
  __m128i inserted; // xmm7
  hkQuaternionf v3; // xmm4
  hkVector4f v4; // xmm2
  __m128 v5; // xmm1
  __m128 v6; // xmm6
  __m128 v7; // xmm5
  __m128 v8; // xmm3

  inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  v3.m_vec.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 64), qt->m_rotation.m_vec.m_quad);
  this->m_rotation = (hkQuaternionf)v3.m_vec.m_quad;
  v4.m_quad = (__m128)qt->m_translation;
  v5 = _mm_mul_ps(v4.m_quad, v3.m_vec.m_quad);
  v6 = _mm_shuffle_ps(v3.m_vec.m_quad, v3.m_vec.m_quad, 255);
  v7 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 201), v3.m_vec.m_quad),
         _mm_mul_ps(_mm_shuffle_ps(v3.m_vec.m_quad, v3.m_vec.m_quad, 201), v4.m_quad));
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(
             _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170)),
             v3.m_vec.m_quad),
           _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v6, v6), (__m128)xmmword_141A711B0), v4.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v6));
  this->m_translation.m_quad = _mm_xor_ps(_mm_add_ps(v8, v8), (__m128)_mm_shuffle_epi32(inserted, 0));
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
  v4 = _mm_mul_ps(v3.m_quad, qt1->m_rotation.m_vec.m_quad);
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
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  int v13; // edx
  __int64 v14; // r8
  __int64 v15; // r9
  float v16; // xmm2_4
  float v17; // xmm0_4
  hkVector4f v18; // xmm3
  __m128 v19; // xmm0
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm7
  __m128 v24; // xmm1
  __m128 v25; // xmm6
  __m128 v26; // xmm5
  __m128 v27; // xmm4
  __m128 v28; // xmm2
  hkQuaternionf v29; // xmm2
  __m128 v30; // xmm3
  __m128 v31; // xmm4
  __m128 v32; // xmm1
  __m128 v33; // xmm7
  __m128 v34; // xmm4
  __m128 v35; // xmm4
  __m128 v36; // [rsp+0h] [rbp-38h]

  v3 = t1->m_rotation.m_col0.m_quad.m128_f32[0];
  v4 = t1->m_rotation.m_col1.m_quad.m128_f32[1];
  v5 = t1->m_rotation.m_col2.m_quad.m128_f32[2];
  v8 = (float)(t1->m_rotation.m_col0.m_quad.m128_f32[0] + v4) + v5;
  if ( v8 <= 0.0 )
  {
    v13 = 0;
    v36.m128_i32[0] = 1;
    if ( v4 > v3 )
      v13 = 1;
    *(unsigned __int64 *)((char *)v36.m128_u64 + 4) = 2i64;
    if ( v5 > t1->m_rotation.m_col0.m_quad.m128_f32[5 * v13] )
      v13 = 2;
    v14 = v36.m128_i32[v13];
    v15 = v36.m128_i32[v14];
    v16 = fsqrt(
            (float)(t1->m_rotation.m_col0.m_quad.m128_f32[5 * v13]
                  - (float)(t1->m_rotation.m_col0.m_quad.m128_f32[5 * v15]
                          + t1->m_rotation.m_col0.m_quad.m128_f32[5 * v14]))
          + 1.0);
    v17 = t1->m_rotation.m_col0.m_quad.m128_f32[4 * v14 + v15] - t1->m_rotation.m_col0.m_quad.m128_f32[4 * v15 + v14];
    v36.m128_f32[v13] = v16 * 0.5;
    v36.m128_f32[3] = v17 * (float)(0.5 / v16);
    v36.m128_f32[v14] = (float)(t1->m_rotation.m_col0.m_quad.m128_f32[4 * v13 + v14]
                              + t1->m_rotation.m_col0.m_quad.m128_f32[4 * v14 + v13])
                      * (float)(0.5 / v16);
    v36.m128_f32[v15] = (float)(t1->m_rotation.m_col0.m_quad.m128_f32[4 * v15 + v13]
                              + t1->m_rotation.m_col0.m_quad.m128_f32[4 * v13 + v15])
                      * (float)(0.5 / v16);
  }
  else
  {
    v9 = fsqrt(v8 + 1.0);
    v10 = (float)(t1->m_rotation.m_col2.m_quad.m128_f32[0] - t1->m_rotation.m_col0.m_quad.m128_f32[2])
        * (float)(0.5 / v9);
    v36.m128_f32[0] = (float)(t1->m_rotation.m_col1.m_quad.m128_f32[2] - t1->m_rotation.m_col2.m_quad.m128_f32[1])
                    * (float)(0.5 / v9);
    v11 = t1->m_rotation.m_col0.m_quad.m128_f32[1];
    v36.m128_f32[1] = v10;
    v12 = v11 - t1->m_rotation.m_col1.m_quad.m128_f32[0];
    v36.m128_f32[3] = v9 * 0.5;
    v36.m128_f32[2] = v12 * (float)(0.5 / v9);
  }
  v18.m_quad = (__m128)qt2->m_translation;
  v19 = _mm_mul_ps(v36, v36);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 78), v19);
  v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 177), v20);
  v22 = _mm_rsqrt_ps(v21);
  v23 = _mm_mul_ps(
          v36,
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)), _mm_mul_ps(*(__m128 *)_xmm, v22)));
  v24 = _mm_mul_ps(v18.m_quad, v23);
  v25 = _mm_shuffle_ps(v23, v23, 255);
  v26 = _mm_shuffle_ps(v23, v23, 201);
  v27 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v18.m_quad, v18.m_quad, 201), v23), _mm_mul_ps(v26, v18.m_quad));
  v28 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                _mm_shuffle_ps(v24, v24, 170)),
              v23),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v25, v25), (__m128)xmmword_141A711B0), v18.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v25));
  this->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v28, v28), t1->m_translation.m_quad);
  v29.m_vec.m_quad = (__m128)qt2->m_rotation;
  v30 = _mm_shuffle_ps(v29.m_vec.m_quad, v29.m_vec.m_quad, 255);
  v31 = _mm_mul_ps(_mm_shuffle_ps(v29.m_vec.m_quad, v29.m_vec.m_quad, 201), v23);
  v32 = _mm_mul_ps(v23, v30);
  v33 = _mm_mul_ps(v23, qt2->m_rotation.m_vec.m_quad);
  v34 = _mm_sub_ps(v31, _mm_mul_ps(v26, qt2->m_rotation.m_vec.m_quad));
  v35 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v34, v34, 201), _mm_mul_ps(v25, qt2->m_rotation.m_vec.m_quad)), v32);
  this->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                    v35,
                                    _mm_unpackhi_ps(
                                      v35,
                                      _mm_sub_ps(
                                        _mm_mul_ps(v30, v25),
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
                                          _mm_shuffle_ps(v33, v33, 170)))),
                                    196);
}

// File Line: 45
// RVA: 0xC71420
void __fastcall hkQTransformf::setMul(hkQTransformf *this, hkTransformf *t1, hkTransformf *t2)
{
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm3_4
  int v6; // edi
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  int v14; // edx
  __int64 v15; // r8
  __int64 v16; // r9
  float v17; // xmm0_4
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  __m128 v22; // xmm0
  float v23; // xmm2_4
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  float v26; // xmm3_4
  __m128 v27; // xmm8
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm0_4
  float v33; // xmm0_4
  __int64 v34; // r8
  __int64 v35; // r9
  float v36; // xmm0_4
  hkVector4f v37; // xmm4
  __m128 v38; // xmm5
  __m128 v39; // xmm0
  __m128 v40; // xmm6
  __m128 v41; // xmm2
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm0
  __m128 v45; // xmm1
  __m128 v46; // xmm3
  __m128 v47; // xmm7
  __m128 v48; // xmm2
  __m128 v49; // xmm3
  __m128 v50; // xmm2
  __m128 v51; // xmm0
  __m128 v52; // xmm7
  __m128 v53; // xmm2
  __m128 v54; // [rsp+0h] [rbp-60h]

  v3 = t1->m_rotation.m_col0.m_quad.m128_f32[0];
  v4 = t1->m_rotation.m_col1.m_quad.m128_f32[1];
  v5 = t1->m_rotation.m_col2.m_quad.m128_f32[2];
  v6 = 0;
  v9 = (float)(t1->m_rotation.m_col0.m_quad.m128_f32[0] + v4) + v5;
  if ( v9 <= 0.0 )
  {
    v54.m128_i32[0] = 1;
    *(unsigned __int64 *)((char *)v54.m128_u64 + 4) = 2i64;
    v14 = v4 > v3;
    if ( v5 > t1->m_rotation.m_col0.m_quad.m128_f32[5 * (v4 > v3)] )
      v14 = 2;
    v15 = v54.m128_i32[v14];
    v16 = v54.m128_i32[v15];
    v17 = fsqrt(
            (float)(t1->m_rotation.m_col0.m_quad.m128_f32[5 * v14]
                  - (float)(t1->m_rotation.m_col0.m_quad.m128_f32[5 * v16]
                          + t1->m_rotation.m_col0.m_quad.m128_f32[5 * v15]))
          + 1.0);
    v54.m128_f32[v14] = v17 * 0.5;
    v54.m128_f32[3] = (float)(t1->m_rotation.m_col0.m_quad.m128_f32[4 * v15 + v16]
                            - t1->m_rotation.m_col0.m_quad.m128_f32[4 * v16 + v15])
                    * (float)(0.5 / v17);
    v54.m128_f32[v15] = (float)(t1->m_rotation.m_col0.m_quad.m128_f32[4 * v14 + v15]
                              + t1->m_rotation.m_col0.m_quad.m128_f32[4 * v15 + v14])
                      * (float)(0.5 / v17);
    v54.m128_f32[v16] = (float)(t1->m_rotation.m_col0.m_quad.m128_f32[4 * v16 + v14]
                              + t1->m_rotation.m_col0.m_quad.m128_f32[4 * v14 + v16])
                      * (float)(0.5 / v17);
  }
  else
  {
    v10 = t1->m_rotation.m_col2.m_quad.m128_f32[0] - t1->m_rotation.m_col0.m_quad.m128_f32[2];
    v11 = fsqrt(v9 + 1.0);
    v12 = t1->m_rotation.m_col1.m_quad.m128_f32[2] - t1->m_rotation.m_col2.m_quad.m128_f32[1];
    v54.m128_f32[3] = v11 * 0.5;
    v54.m128_f32[0] = v12 * (float)(0.5 / v11);
    v13 = t1->m_rotation.m_col0.m_quad.m128_f32[1];
    v54.m128_f32[1] = v10 * (float)(0.5 / v11);
    v54.m128_f32[2] = (float)(v13 - t1->m_rotation.m_col1.m_quad.m128_f32[0]) * (float)(0.5 / v11);
  }
  v18 = _mm_mul_ps(v54, v54);
  v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
  v21 = _mm_rsqrt_ps(v20);
  v22 = _mm_mul_ps(v21, v20);
  v23 = t2->m_rotation.m_col0.m_quad.m128_f32[0];
  v24 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v21));
  v25 = _mm_mul_ps(*(__m128 *)_xmm, v21);
  v26 = t2->m_rotation.m_col2.m_quad.m128_f32[2];
  v27 = _mm_mul_ps(v54, _mm_mul_ps(v24, v25));
  v28 = t2->m_rotation.m_col1.m_quad.m128_f32[1];
  v29 = (float)(t2->m_rotation.m_col0.m_quad.m128_f32[0] + v28) + v26;
  if ( v29 <= 0.0 )
  {
    v54.m128_i32[0] = 1;
    *(unsigned __int64 *)((char *)v54.m128_u64 + 4) = 2i64;
    if ( v28 > v23 )
      v6 = 1;
    if ( v26 > t2->m_rotation.m_col0.m_quad.m128_f32[5 * v6] )
      v6 = 2;
    v34 = v54.m128_i32[v6];
    v35 = v54.m128_i32[v34];
    v36 = fsqrt(
            (float)(t2->m_rotation.m_col0.m_quad.m128_f32[5 * v6]
                  - (float)(t2->m_rotation.m_col0.m_quad.m128_f32[5 * v35]
                          + t2->m_rotation.m_col0.m_quad.m128_f32[5 * v34]))
          + 1.0);
    v54.m128_f32[v6] = v36 * 0.5;
    v54.m128_f32[3] = (float)(t2->m_rotation.m_col0.m_quad.m128_f32[4 * v34 + v35]
                            - t2->m_rotation.m_col0.m_quad.m128_f32[4 * v35 + v34])
                    * (float)(0.5 / v36);
    v54.m128_f32[v34] = (float)(t2->m_rotation.m_col0.m_quad.m128_f32[4 * v6 + v34]
                              + t2->m_rotation.m_col0.m_quad.m128_f32[4 * v34 + v6])
                      * (float)(0.5 / v36);
    v54.m128_f32[v35] = (float)(t2->m_rotation.m_col0.m_quad.m128_f32[4 * v35 + v6]
                              + t2->m_rotation.m_col0.m_quad.m128_f32[4 * v6 + v35])
                      * (float)(0.5 / v36);
  }
  else
  {
    v30 = t2->m_rotation.m_col2.m_quad.m128_f32[0] - t2->m_rotation.m_col0.m_quad.m128_f32[2];
    v31 = fsqrt(v29 + 1.0);
    v32 = t2->m_rotation.m_col1.m_quad.m128_f32[2] - t2->m_rotation.m_col2.m_quad.m128_f32[1];
    v54.m128_f32[3] = v31 * 0.5;
    v54.m128_f32[0] = v32 * (float)(0.5 / v31);
    v33 = t2->m_rotation.m_col0.m_quad.m128_f32[1];
    v54.m128_f32[1] = v30 * (float)(0.5 / v31);
    v54.m128_f32[2] = (float)(v33 - t2->m_rotation.m_col1.m_quad.m128_f32[0]) * (float)(0.5 / v31);
  }
  v37.m_quad = (__m128)t2->m_translation;
  v38 = _mm_shuffle_ps(v27, v27, 201);
  v39 = _mm_mul_ps(v54, v54);
  v40 = _mm_shuffle_ps(v27, v27, 255);
  v41 = _mm_add_ps(_mm_shuffle_ps(v39, v39, 78), v39);
  v42 = _mm_add_ps(_mm_shuffle_ps(v41, v41, 177), v41);
  v43 = _mm_rsqrt_ps(v42);
  v44 = _mm_mul_ps(_mm_mul_ps(v43, v42), v43);
  v45 = _mm_mul_ps(v37.m_quad, v27);
  v46 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v37.m_quad, v37.m_quad, 201), v27), _mm_mul_ps(v37.m_quad, v38));
  v47 = _mm_mul_ps(v54, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v44), _mm_mul_ps(*(__m128 *)_xmm, v43)));
  v48 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
                _mm_shuffle_ps(v45, v45, 170)),
              v27),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v40, v40), (__m128)xmmword_141A711B0), v37.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), v40));
  v49 = _mm_shuffle_ps(v47, v47, 255);
  this->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v48, v48), t1->m_translation.m_quad);
  v50 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v27), _mm_mul_ps(v47, v38));
  v51 = v47;
  v52 = _mm_mul_ps(v47, v27);
  v53 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v50, v50, 201), _mm_mul_ps(v51, v40)), _mm_mul_ps(v27, v49));
  this->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                    v53,
                                    _mm_unpackhi_ps(
                                      v53,
                                      _mm_sub_ps(
                                        _mm_mul_ps(v49, v40),
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                                          _mm_shuffle_ps(v52, v52, 170)))),
                                    196);
}

// File Line: 60
// RVA: 0xC718A0
void __fastcall hkQTransformf::setMul(hkQTransformf *this, hkQTransformf *qt1, hkTransformf *t2)
{
  float v3; // xmm3_4
  float v4; // xmm2_4
  float v5; // xmm4_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  int v13; // edx
  __int64 v14; // r8
  __int64 v15; // r9
  float v16; // xmm2_4
  float v17; // xmm0_4
  hkVector4f v18; // xmm5
  __m128 v19; // xmm0
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm7
  __m128 v24; // xmm6
  __m128 v25; // xmm1
  __m128 v26; // xmm4
  __m128 v27; // xmm3
  __m128 v28; // xmm4
  __m128 v29; // xmm3
  __m128 v30; // xmm5
  __m128 v31; // xmm0
  __m128 v32; // xmm7
  __m128 v33; // xmm5
  __m128 v34; // [rsp+0h] [rbp-38h]

  v3 = t2->m_rotation.m_col0.m_quad.m128_f32[0];
  v4 = t2->m_rotation.m_col1.m_quad.m128_f32[1];
  v5 = t2->m_rotation.m_col2.m_quad.m128_f32[2];
  v8 = (float)(t2->m_rotation.m_col0.m_quad.m128_f32[0] + v4) + v5;
  if ( v8 <= 0.0 )
  {
    v13 = 0;
    v34.m128_i32[0] = 1;
    if ( v4 > v3 )
      v13 = 1;
    *(unsigned __int64 *)((char *)v34.m128_u64 + 4) = 2i64;
    if ( v5 > t2->m_rotation.m_col0.m_quad.m128_f32[5 * v13] )
      v13 = 2;
    v14 = v34.m128_i32[v13];
    v15 = v34.m128_i32[v14];
    v16 = fsqrt(
            (float)(t2->m_rotation.m_col0.m_quad.m128_f32[5 * v13]
                  - (float)(t2->m_rotation.m_col0.m_quad.m128_f32[5 * v15]
                          + t2->m_rotation.m_col0.m_quad.m128_f32[5 * v14]))
          + 1.0);
    v17 = t2->m_rotation.m_col0.m_quad.m128_f32[4 * v14 + v15] - t2->m_rotation.m_col0.m_quad.m128_f32[4 * v15 + v14];
    v34.m128_f32[v13] = v16 * 0.5;
    v34.m128_f32[3] = v17 * (float)(0.5 / v16);
    v34.m128_f32[v14] = (float)(t2->m_rotation.m_col0.m_quad.m128_f32[4 * v13 + v14]
                              + t2->m_rotation.m_col0.m_quad.m128_f32[4 * v14 + v13])
                      * (float)(0.5 / v16);
    v34.m128_f32[v15] = (float)(t2->m_rotation.m_col0.m_quad.m128_f32[4 * v15 + v13]
                              + t2->m_rotation.m_col0.m_quad.m128_f32[4 * v13 + v15])
                      * (float)(0.5 / v16);
  }
  else
  {
    v9 = fsqrt(v8 + 1.0);
    v10 = (float)(t2->m_rotation.m_col2.m_quad.m128_f32[0] - t2->m_rotation.m_col0.m_quad.m128_f32[2])
        * (float)(0.5 / v9);
    v34.m128_f32[0] = (float)(t2->m_rotation.m_col1.m_quad.m128_f32[2] - t2->m_rotation.m_col2.m_quad.m128_f32[1])
                    * (float)(0.5 / v9);
    v11 = t2->m_rotation.m_col0.m_quad.m128_f32[1];
    v34.m128_f32[1] = v10;
    v12 = v11 - t2->m_rotation.m_col1.m_quad.m128_f32[0];
    v34.m128_f32[3] = v9 * 0.5;
    v34.m128_f32[2] = v12 * (float)(0.5 / v9);
  }
  v18.m_quad = (__m128)t2->m_translation;
  v19 = _mm_mul_ps(v34, v34);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 78), v19);
  v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 177), v20);
  v22 = _mm_rsqrt_ps(v21);
  v23 = _mm_mul_ps(
          v34,
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)), _mm_mul_ps(*(__m128 *)_xmm, v22)));
  v24 = _mm_shuffle_ps(qt1->m_rotation.m_vec.m_quad, qt1->m_rotation.m_vec.m_quad, 255);
  v25 = _mm_mul_ps(qt1->m_rotation.m_vec.m_quad, v18.m_quad);
  v26 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v18.m_quad, v18.m_quad, 201), qt1->m_rotation.m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(qt1->m_rotation.m_vec.m_quad, qt1->m_rotation.m_vec.m_quad, 201), v18.m_quad));
  v27 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                _mm_shuffle_ps(v25, v25, 170)),
              qt1->m_rotation.m_vec.m_quad),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v24, v24), (__m128)xmmword_141A711B0), v18.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v24));
  v28 = _mm_shuffle_ps(v23, v23, 255);
  this->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v27, v27), qt1->m_translation.m_quad);
  v29 = _mm_shuffle_ps(qt1->m_rotation.m_vec.m_quad, qt1->m_rotation.m_vec.m_quad, 255);
  v30 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), qt1->m_rotation.m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(qt1->m_rotation.m_vec.m_quad, qt1->m_rotation.m_vec.m_quad, 201), v23));
  v31 = v23;
  v32 = _mm_mul_ps(v23, qt1->m_rotation.m_vec.m_quad);
  v33 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v30, v30, 201), _mm_mul_ps(v31, v29)),
          _mm_mul_ps(v28, qt1->m_rotation.m_vec.m_quad));
  this->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                    v33,
                                    _mm_unpackhi_ps(
                                      v33,
                                      _mm_sub_ps(
                                        _mm_mul_ps(v28, v29),
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                                          _mm_shuffle_ps(v32, v32, 170)))),
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
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  int v13; // edx
  __int64 v14; // r8
  __int64 v15; // r9
  float v16; // xmm2_4
  float v17; // xmm0_4
  hkVector4f v18; // xmm6
  __m128 v19; // xmm0
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm4
  __m128 v24; // xmm7
  __m128 v25; // xmm8
  __m128 v26; // xmm5
  __m128 v27; // xmm3
  __m128 v28; // xmm3
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  __m128 v32; // xmm4
  __m128 v33; // xmm2
  __m128 v34; // [rsp+0h] [rbp-48h]

  v3 = t1->m_rotation.m_col0.m_quad.m128_f32[0];
  v4 = t1->m_rotation.m_col1.m_quad.m128_f32[1];
  v5 = t1->m_rotation.m_col2.m_quad.m128_f32[2];
  v8 = (float)(t1->m_rotation.m_col0.m_quad.m128_f32[0] + v4) + v5;
  if ( v8 <= 0.0 )
  {
    v13 = 0;
    v34.m128_i32[0] = 1;
    if ( v4 > v3 )
      v13 = 1;
    *(unsigned __int64 *)((char *)v34.m128_u64 + 4) = 2i64;
    if ( v5 > t1->m_rotation.m_col0.m_quad.m128_f32[5 * v13] )
      v13 = 2;
    v14 = v34.m128_i32[v13];
    v15 = v34.m128_i32[v14];
    v16 = fsqrt(
            (float)(t1->m_rotation.m_col0.m_quad.m128_f32[5 * v13]
                  - (float)(t1->m_rotation.m_col0.m_quad.m128_f32[5 * v15]
                          + t1->m_rotation.m_col0.m_quad.m128_f32[5 * v14]))
          + 1.0);
    v17 = t1->m_rotation.m_col0.m_quad.m128_f32[4 * v14 + v15] - t1->m_rotation.m_col0.m_quad.m128_f32[4 * v15 + v14];
    v34.m128_f32[v13] = v16 * 0.5;
    v34.m128_f32[3] = v17 * (float)(0.5 / v16);
    v34.m128_f32[v14] = (float)(t1->m_rotation.m_col0.m_quad.m128_f32[4 * v13 + v14]
                              + t1->m_rotation.m_col0.m_quad.m128_f32[4 * v14 + v13])
                      * (float)(0.5 / v16);
    v34.m128_f32[v15] = (float)(t1->m_rotation.m_col0.m_quad.m128_f32[4 * v15 + v13]
                              + t1->m_rotation.m_col0.m_quad.m128_f32[4 * v13 + v15])
                      * (float)(0.5 / v16);
  }
  else
  {
    v9 = fsqrt(v8 + 1.0);
    v10 = (float)(t1->m_rotation.m_col2.m_quad.m128_f32[0] - t1->m_rotation.m_col0.m_quad.m128_f32[2])
        * (float)(0.5 / v9);
    v34.m128_f32[0] = (float)(t1->m_rotation.m_col1.m_quad.m128_f32[2] - t1->m_rotation.m_col2.m_quad.m128_f32[1])
                    * (float)(0.5 / v9);
    v11 = t1->m_rotation.m_col0.m_quad.m128_f32[1];
    v34.m128_f32[1] = v10;
    v12 = v11 - t1->m_rotation.m_col1.m_quad.m128_f32[0];
    v34.m128_f32[3] = v9 * 0.5;
    v34.m128_f32[2] = v12 * (float)(0.5 / v9);
  }
  v18.m_quad = (__m128)t1->m_translation;
  v19 = _mm_mul_ps(v34, v34);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 78), v19);
  v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 177), v20);
  v22 = _mm_rsqrt_ps(v21);
  v23 = _mm_shuffle_ps(qt2->m_rotation.m_vec.m_quad, qt2->m_rotation.m_vec.m_quad, 255);
  v24 = _mm_xor_ps(
          (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
          _mm_mul_ps(
            v34,
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
              _mm_mul_ps(*(__m128 *)_xmm, v22))));
  v25 = _mm_shuffle_ps(v24, v24, 255);
  v26 = _mm_shuffle_ps(v24, v24, 201);
  v27 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(qt2->m_rotation.m_vec.m_quad, qt2->m_rotation.m_vec.m_quad, 201), v24),
          _mm_mul_ps(v26, qt2->m_rotation.m_vec.m_quad));
  v28 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v27, v27, 201), _mm_mul_ps(v25, qt2->m_rotation.m_vec.m_quad)),
          _mm_mul_ps(v24, v23));
  v29 = _mm_mul_ps(v24, qt2->m_rotation.m_vec.m_quad);
  this->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                    v28,
                                    _mm_unpackhi_ps(
                                      v28,
                                      _mm_sub_ps(
                                        _mm_mul_ps(v23, v25),
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                                          _mm_shuffle_ps(v29, v29, 170)))),
                                    196);
  v30 = _mm_sub_ps(qt2->m_translation.m_quad, v18.m_quad);
  v31 = _mm_mul_ps(v24, v30);
  v32 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v24), _mm_mul_ps(v26, v30));
  v33 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                _mm_shuffle_ps(v31, v31, 170)),
              v24),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v25, v25), (__m128)xmmword_141A711B0), v30)),
          _mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), v25));
  this->m_translation.m_quad = _mm_add_ps(v33, v33);
}

// File Line: 94
// RVA: 0xC71F60
void __fastcall hkQTransformf::setMulInverseMul(hkQTransformf *this, hkQTransformf *qt1, hkTransformf *t2)
{
  float v3; // xmm3_4
  float v4; // xmm2_4
  float v5; // xmm4_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  int v13; // edx
  __int64 v14; // r8
  __int64 v15; // r9
  float v16; // xmm2_4
  float v17; // xmm0_4
  hkVector4f v18; // xmm9
  __m128 v19; // xmm0
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm6
  __m128 v24; // xmm4
  __m128 v25; // xmm7
  __m128 v26; // xmm8
  __m128 v27; // xmm5
  __m128 v28; // xmm3
  __m128 v29; // xmm3
  __m128 v30; // xmm1
  __m128 v31; // xmm9
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  __m128 v35; // [rsp+0h] [rbp-58h]

  v3 = t2->m_rotation.m_col0.m_quad.m128_f32[0];
  v4 = t2->m_rotation.m_col1.m_quad.m128_f32[1];
  v5 = t2->m_rotation.m_col2.m_quad.m128_f32[2];
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
    v14 = v35.m128_i32[v13];
    v15 = v35.m128_i32[v14];
    v16 = fsqrt(
            (float)(t2->m_rotation.m_col0.m_quad.m128_f32[5 * v13]
                  - (float)(t2->m_rotation.m_col0.m_quad.m128_f32[5 * v15]
                          + t2->m_rotation.m_col0.m_quad.m128_f32[5 * v14]))
          + 1.0);
    v17 = t2->m_rotation.m_col0.m_quad.m128_f32[4 * v14 + v15] - t2->m_rotation.m_col0.m_quad.m128_f32[4 * v15 + v14];
    v35.m128_f32[v13] = v16 * 0.5;
    v35.m128_f32[3] = v17 * (float)(0.5 / v16);
    v35.m128_f32[v14] = (float)(t2->m_rotation.m_col0.m_quad.m128_f32[4 * v13 + v14]
                              + t2->m_rotation.m_col0.m_quad.m128_f32[4 * v14 + v13])
                      * (float)(0.5 / v16);
    v35.m128_f32[v15] = (float)(t2->m_rotation.m_col0.m_quad.m128_f32[4 * v15 + v13]
                              + t2->m_rotation.m_col0.m_quad.m128_f32[4 * v13 + v15])
                      * (float)(0.5 / v16);
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
  v18.m_quad = (__m128)t2->m_translation;
  v19 = _mm_mul_ps(v35, v35);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 78), v19);
  v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 177), v20);
  v22 = _mm_rsqrt_ps(v21);
  v23 = _mm_mul_ps(
          v35,
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)), _mm_mul_ps(*(__m128 *)_xmm, v22)));
  v24 = _mm_shuffle_ps(v23, v23, 255);
  v25 = _mm_xor_ps(
          (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
          qt1->m_rotation.m_vec.m_quad);
  v26 = _mm_shuffle_ps(v25, v25, 255);
  v27 = _mm_shuffle_ps(v25, v25, 201);
  v28 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v25), _mm_mul_ps(v27, v23));
  v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v28, v28, 201), _mm_mul_ps(v23, v26)), _mm_mul_ps(v25, v24));
  v30 = _mm_mul_ps(v25, v23);
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
  v31 = _mm_sub_ps(v18.m_quad, qt1->m_translation.m_quad);
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

// File Line: 107
// RVA: 0xC72260
void __fastcall hkQTransformf::setMulInverseMul(hkQTransformf *this, hkTransformf *t1, hkTransformf *t2)
{
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm3_4
  int v6; // edi
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  int v14; // edx
  __int64 v15; // r8
  __int64 v16; // r9
  float v17; // xmm0_4
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  __m128 v22; // xmm0
  float v23; // xmm2_4
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  float v26; // xmm3_4
  __m128 v27; // xmm9
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm0_4
  float v33; // xmm0_4
  __int64 v34; // r8
  __int64 v35; // r9
  float v36; // xmm0_4
  __m128 v37; // xmm0
  __m128 v38; // xmm2
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  __m128 v41; // xmm7
  __m128 v42; // xmm10
  __m128 v43; // xmm4
  __m128 v44; // xmm8
  __m128 v45; // xmm9
  __m128 v46; // xmm5
  __m128 v47; // xmm3
  __m128 v48; // xmm3
  __m128 v49; // xmm1
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  __m128 v52; // xmm3
  __m128 v53; // xmm2
  __m128 v54; // [rsp+0h] [rbp-60h]

  v3 = t1->m_rotation.m_col0.m_quad.m128_f32[0];
  v4 = t1->m_rotation.m_col1.m_quad.m128_f32[1];
  v5 = t1->m_rotation.m_col2.m_quad.m128_f32[2];
  v6 = 0;
  v9 = (float)(t1->m_rotation.m_col0.m_quad.m128_f32[0] + v4) + v5;
  if ( v9 <= 0.0 )
  {
    v54.m128_i32[0] = 1;
    *(unsigned __int64 *)((char *)v54.m128_u64 + 4) = 2i64;
    v14 = v4 > v3;
    if ( v5 > t1->m_rotation.m_col0.m_quad.m128_f32[5 * (v4 > v3)] )
      v14 = 2;
    v15 = v54.m128_i32[v14];
    v16 = v54.m128_i32[v15];
    v17 = fsqrt(
            (float)(t1->m_rotation.m_col0.m_quad.m128_f32[5 * v14]
                  - (float)(t1->m_rotation.m_col0.m_quad.m128_f32[5 * v16]
                          + t1->m_rotation.m_col0.m_quad.m128_f32[5 * v15]))
          + 1.0);
    v54.m128_f32[v14] = v17 * 0.5;
    v54.m128_f32[3] = (float)(t1->m_rotation.m_col0.m_quad.m128_f32[4 * v15 + v16]
                            - t1->m_rotation.m_col0.m_quad.m128_f32[4 * v16 + v15])
                    * (float)(0.5 / v17);
    v54.m128_f32[v15] = (float)(t1->m_rotation.m_col0.m_quad.m128_f32[4 * v14 + v15]
                              + t1->m_rotation.m_col0.m_quad.m128_f32[4 * v15 + v14])
                      * (float)(0.5 / v17);
    v54.m128_f32[v16] = (float)(t1->m_rotation.m_col0.m_quad.m128_f32[4 * v16 + v14]
                              + t1->m_rotation.m_col0.m_quad.m128_f32[4 * v14 + v16])
                      * (float)(0.5 / v17);
  }
  else
  {
    v10 = t1->m_rotation.m_col2.m_quad.m128_f32[0] - t1->m_rotation.m_col0.m_quad.m128_f32[2];
    v11 = fsqrt(v9 + 1.0);
    v12 = t1->m_rotation.m_col1.m_quad.m128_f32[2] - t1->m_rotation.m_col2.m_quad.m128_f32[1];
    v54.m128_f32[3] = v11 * 0.5;
    v54.m128_f32[0] = v12 * (float)(0.5 / v11);
    v13 = t1->m_rotation.m_col0.m_quad.m128_f32[1];
    v54.m128_f32[1] = v10 * (float)(0.5 / v11);
    v54.m128_f32[2] = (float)(v13 - t1->m_rotation.m_col1.m_quad.m128_f32[0]) * (float)(0.5 / v11);
  }
  v18 = _mm_mul_ps(v54, v54);
  v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
  v21 = _mm_rsqrt_ps(v20);
  v22 = _mm_mul_ps(v21, v20);
  v23 = t2->m_rotation.m_col0.m_quad.m128_f32[0];
  v24 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v21));
  v25 = _mm_mul_ps(*(__m128 *)_xmm, v21);
  v26 = t2->m_rotation.m_col2.m_quad.m128_f32[2];
  v27 = _mm_mul_ps(v54, _mm_mul_ps(v24, v25));
  v28 = t2->m_rotation.m_col1.m_quad.m128_f32[1];
  v29 = (float)(t2->m_rotation.m_col0.m_quad.m128_f32[0] + v28) + v26;
  if ( v29 <= 0.0 )
  {
    v54.m128_i32[0] = 1;
    *(unsigned __int64 *)((char *)v54.m128_u64 + 4) = 2i64;
    if ( v28 > v23 )
      v6 = 1;
    if ( v26 > t2->m_rotation.m_col0.m_quad.m128_f32[5 * v6] )
      v6 = 2;
    v34 = v54.m128_i32[v6];
    v35 = v54.m128_i32[v34];
    v36 = fsqrt(
            (float)(t2->m_rotation.m_col0.m_quad.m128_f32[5 * v6]
                  - (float)(t2->m_rotation.m_col0.m_quad.m128_f32[5 * v35]
                          + t2->m_rotation.m_col0.m_quad.m128_f32[5 * v34]))
          + 1.0);
    v54.m128_f32[v6] = v36 * 0.5;
    v54.m128_f32[3] = (float)(t2->m_rotation.m_col0.m_quad.m128_f32[4 * v34 + v35]
                            - t2->m_rotation.m_col0.m_quad.m128_f32[4 * v35 + v34])
                    * (float)(0.5 / v36);
    v54.m128_f32[v34] = (float)(t2->m_rotation.m_col0.m_quad.m128_f32[4 * v6 + v34]
                              + t2->m_rotation.m_col0.m_quad.m128_f32[4 * v34 + v6])
                      * (float)(0.5 / v36);
    v54.m128_f32[v35] = (float)(t2->m_rotation.m_col0.m_quad.m128_f32[4 * v35 + v6]
                              + t2->m_rotation.m_col0.m_quad.m128_f32[4 * v6 + v35])
                      * (float)(0.5 / v36);
  }
  else
  {
    v30 = t2->m_rotation.m_col2.m_quad.m128_f32[0] - t2->m_rotation.m_col0.m_quad.m128_f32[2];
    v31 = fsqrt(v29 + 1.0);
    v32 = t2->m_rotation.m_col1.m_quad.m128_f32[2] - t2->m_rotation.m_col2.m_quad.m128_f32[1];
    v54.m128_f32[3] = v31 * 0.5;
    v54.m128_f32[0] = v32 * (float)(0.5 / v31);
    v33 = t2->m_rotation.m_col0.m_quad.m128_f32[1];
    v54.m128_f32[1] = v30 * (float)(0.5 / v31);
    v54.m128_f32[2] = (float)(v33 - t2->m_rotation.m_col1.m_quad.m128_f32[0]) * (float)(0.5 / v31);
  }
  v37 = _mm_mul_ps(v54, v54);
  v38 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 78), v37);
  v39 = _mm_add_ps(_mm_shuffle_ps(v38, v38, 177), v38);
  v40 = _mm_rsqrt_ps(v39);
  v41 = _mm_mul_ps(
          v54,
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v40, v39), v40)), _mm_mul_ps(*(__m128 *)_xmm, v40)));
  v42 = _mm_sub_ps(t2->m_translation.m_quad, t1->m_translation.m_quad);
  v43 = _mm_shuffle_ps(v41, v41, 255);
  v44 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64), v27);
  v45 = _mm_shuffle_ps(v44, v44, 255);
  v46 = _mm_shuffle_ps(v44, v44, 201);
  v47 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v44), _mm_mul_ps(v41, v46));
  v48 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v47, v47, 201), _mm_mul_ps(v41, v45)), _mm_mul_ps(v44, v43));
  v49 = _mm_mul_ps(v44, v41);
  v50 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)), _mm_shuffle_ps(v49, v49, 170));
  v51 = _mm_mul_ps(v44, v42);
  this->m_rotation.m_vec.m_quad = _mm_shuffle_ps(v48, _mm_unpackhi_ps(v48, _mm_sub_ps(_mm_mul_ps(v43, v45), v50)), 196);
  v52 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v44), _mm_mul_ps(v42, v46));
  v53 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
                _mm_shuffle_ps(v51, v51, 170)),
              v44),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v45, v45), (__m128)xmmword_141A711B0), v42)),
          _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v45));
  this->m_translation.m_quad = _mm_add_ps(v53, v53);
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
  v12 = _mm_mul_ps(v11.m_quad, v10.m_vec.m_quad);
  v13 = _mm_shuffle_ps(v10.m_vec.m_quad, v10.m_vec.m_quad, 255);
  v14 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v11.m_quad, v11.m_quad, 201), v10.m_vec.m_quad),
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
           _mm_cmplt_ps(
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
            _mm_cmplt_ps(
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32((__m128i)_mm_sub_ps(this->m_translation.m_quad, other->m_translation.m_quad), 1u),
                        1u),
              v4)) & 7) == 7;
}

// File Line: 137
// RVA: 0xC72890
void __fastcall hkQTransformf::setInterpolate4(
        hkQTransformf *this,
        hkQTransformf *qtA,
        hkQTransformf *qtB,
        hkSimdFloat32 *t)
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
  return (_mm_movemask_ps(_mm_cmpunord_ps(this->m_translation.m_quad, this->m_translation.m_quad)) & 7) == 0
      && hkQuaternionf::isOk(&this->m_rotation, 0.001);
}


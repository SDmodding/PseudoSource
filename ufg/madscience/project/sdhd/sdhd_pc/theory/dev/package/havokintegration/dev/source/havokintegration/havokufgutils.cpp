// File Line: 10
// RVA: 0x261F20
void __fastcall hkQsTransform_fasterRenormalizeBatch(hkQsTransformf *poseOut, unsigned int numTransforms)
{
  __int64 v2; // r8
  hkQuaternionf v3; // xmm6
  __m128 v4; // xmm1
  __m128 v5; // xmm3
  hkQuaternionf v6; // xmm0
  __m128 v7; // xmm5
  __m128 v8; // xmm0
  __m128 v9; // xmm4
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  unsigned int v24; // edx
  hkQuaternionf *p_m_rotation; // rax
  __int64 v26; // rcx
  __m128 m_quad; // xmm3
  __m128 v28; // xmm0
  __m128 v29; // xmm2
  __m128 v30; // xmm1
  __m128 v31; // xmm2

  if ( numTransforms >> 2 )
  {
    v2 = numTransforms >> 2;
    do
    {
      v3.m_vec.m_quad = (__m128)poseOut->m_rotation;
      v4 = _mm_mul_ps(poseOut[1].m_rotation.m_vec.m_quad, poseOut[1].m_rotation.m_vec.m_quad);
      v5 = _mm_mul_ps(poseOut[2].m_rotation.m_vec.m_quad, poseOut[2].m_rotation.m_vec.m_quad);
      v6.m_vec.m_quad = (__m128)poseOut[3].m_rotation;
      poseOut += 4;
      v7 = _mm_mul_ps(v3.m_vec.m_quad, v3.m_vec.m_quad);
      v8 = _mm_mul_ps(v6.m_vec.m_quad, v6.m_vec.m_quad);
      v9 = _mm_shuffle_ps(v7, v4, 68);
      v10 = _mm_shuffle_ps(v7, v4, 238);
      v11 = _mm_shuffle_ps(v5, v8, 68);
      v12 = _mm_shuffle_ps(v5, v8, 238);
      v13 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v10, v12, 221), _mm_shuffle_ps(v10, v12, 136)),
              _mm_add_ps(_mm_shuffle_ps(v9, v11, 221), _mm_shuffle_ps(v9, v11, 136)));
      v14 = _mm_rsqrt_ps(v13);
      v15 = _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
              _mm_mul_ps(*(__m128 *)_xmm, v14));
      v16 = _mm_and_ps(v15, (__m128)`hkVector4f::getComponent::`2::indexToMask);
      v17 = _mm_or_ps(_mm_shuffle_ps(v16, v16, 78), v16);
      poseOut[-4].m_rotation.m_vec.m_quad = _mm_mul_ps(_mm_or_ps(_mm_shuffle_ps(v17, v17, 177), v17), v3.m_vec.m_quad);
      v18 = _mm_and_ps(v15, (__m128)xmmword_141687F10);
      v19 = _mm_or_ps(_mm_shuffle_ps(v18, v18, 78), v18);
      poseOut[-3].m_rotation.m_vec.m_quad = _mm_mul_ps(
                                              _mm_or_ps(_mm_shuffle_ps(v19, v19, 177), v19),
                                              poseOut[-3].m_rotation.m_vec.m_quad);
      v20 = _mm_and_ps(v15, (__m128)xmmword_141687F20);
      v21 = _mm_or_ps(_mm_shuffle_ps(v20, v20, 78), v20);
      poseOut[-2].m_rotation.m_vec.m_quad = _mm_mul_ps(
                                              _mm_or_ps(_mm_shuffle_ps(v21, v21, 177), v21),
                                              poseOut[-2].m_rotation.m_vec.m_quad);
      v22 = _mm_and_ps(v15, (__m128)xmmword_141687F30);
      v23 = _mm_or_ps(_mm_shuffle_ps(v22, v22, 78), v22);
      poseOut[-1].m_rotation.m_vec.m_quad = _mm_mul_ps(
                                              _mm_or_ps(_mm_shuffle_ps(v23, v23, 177), v23),
                                              poseOut[-1].m_rotation.m_vec.m_quad);
      --v2;
    }
    while ( v2 );
  }
  v24 = numTransforms & 3;
  if ( v24 )
  {
    p_m_rotation = &poseOut->m_rotation;
    v26 = v24;
    do
    {
      m_quad = p_m_rotation->m_vec.m_quad;
      p_m_rotation += 3;
      v28 = _mm_mul_ps(m_quad, m_quad);
      v29 = _mm_add_ps(_mm_shuffle_ps(v28, v28, 78), v28);
      v30 = _mm_add_ps(_mm_shuffle_ps(v29, v29, 177), v29);
      v31 = _mm_rsqrt_ps(v30);
      p_m_rotation[-3].m_vec.m_quad = _mm_mul_ps(
                                        m_quad,
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v31)));
      --v26;
    }
    while ( v26 );
  }
}


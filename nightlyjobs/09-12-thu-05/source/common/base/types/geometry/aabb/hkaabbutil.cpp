// File Line: 33
// RVA: 0xC672D0
void __fastcall hkAabbUtil::calcAabb(const float *vertexArray, unsigned int numVertices, int striding, hkAabb *aabbOut)
{
  hkVector4f v4; // xmm3
  hkVector4f v5; // xmm2
  __int64 v6; // rax
  __m128 v7; // xmm1
  __m128 v8; // xmm0
  __m128 v9; // xmm1

  aabbOut->m_min = (hkVector4f)xmmword_141A712A0;
  v4.m_quad = (__m128)xmmword_141A712A0;
  v5.m_quad = _mm_xor_ps(
                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                (__m128)xmmword_141A712A0);
  aabbOut->m_max = (hkVector4f)v5.m_quad;
  if ( (int)numVertices > 0 )
  {
    v6 = numVertices;
    do
    {
      v7 = (__m128)*(unsigned __int64 *)vertexArray;
      v8 = (__m128)*((unsigned int *)vertexArray + 2);
      vertexArray = (const float *)((char *)vertexArray + striding);
      v9 = _mm_movelh_ps(v7, v8);
      v4.m_quad = _mm_min_ps(v4.m_quad, v9);
      v5.m_quad = _mm_max_ps(v5.m_quad, v9);
      aabbOut->m_min = (hkVector4f)v4.m_quad;
      aabbOut->m_max = (hkVector4f)v5.m_quad;
      --v6;
    }
    while ( v6 );
    aabbOut->m_min = (hkVector4f)_mm_srli_si128(_mm_slli_si128((__m128i)v4.m_quad, 4), 4);
    aabbOut->m_max = (hkVector4f)_mm_srli_si128(_mm_slli_si128((__m128i)v5.m_quad, 4), 4);
  }
}

// File Line: 53
// RVA: 0xC67360
void __fastcall hkAabbUtil::calcAabb(hkVector4f *vertexArray, int numVertices, hkAabb *aabbOut)
{
  hkVector4f v3; // xmm2
  hkVector4f v4; // xmm0
  __int64 v5; // rax
  hkVector4f v6; // xmm1

  aabbOut->m_min = (hkVector4f)xmmword_141A712A0;
  v3.m_quad = (__m128)xmmword_141A712A0;
  v4.m_quad = _mm_xor_ps(
                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                (__m128)xmmword_141A712A0);
  aabbOut->m_max = (hkVector4f)v4.m_quad;
  if ( numVertices > 0 )
  {
    v5 = numVertices;
    do
    {
      v3.m_quad = _mm_min_ps(v3.m_quad, vertexArray->m_quad);
      ++vertexArray;
      aabbOut->m_min = (hkVector4f)v3.m_quad;
      v4.m_quad = _mm_max_ps(v4.m_quad, vertexArray[-1].m_quad);
      aabbOut->m_max = (hkVector4f)v4.m_quad;
      --v5;
    }
    while ( v5 );
    v6.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)&aabbOut->m_max), 4), 4);
    aabbOut->m_min = (hkVector4f)_mm_srli_si128(_mm_slli_si128((__m128i)v3.m_quad, 4), 4);
    aabbOut->m_max = (hkVector4f)v6.m_quad;
  }
}

// File Line: 72
// RVA: 0xC67470
void __fastcall hkAabbUtil::calcAabb(
        hkTransformf *BvToWorld,
        hkAabb *aabb,
        hkSimdFloat32 *extraRadius,
        hkAabb *aabbOut)
{
  hkVector4f v4; // xmm2
  __m128 v5; // xmm6
  __m128 v6; // xmm2
  __m128 v7; // xmm5
  __m128 v8; // xmm2

  v4.m_quad = (__m128)aabb->m_max;
  v5 = _mm_mul_ps(_mm_add_ps(aabb->m_min.m_quad, v4.m_quad), (__m128)xmmword_141A711B0);
  v6 = _mm_mul_ps(_mm_sub_ps(v4.m_quad, aabb->m_min.m_quad), (__m128)xmmword_141A711B0);
  v7 = _mm_add_ps(
         _mm_add_ps(
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(_mm_shuffle_ps(v6, v6, 85), BvToWorld->m_rotation.m_col1.m_quad),
                       1u),
                     1u),
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(_mm_shuffle_ps(v6, v6, 0), BvToWorld->m_rotation.m_col0.m_quad),
                       1u),
                     1u)),
         _mm_add_ps(
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(_mm_shuffle_ps(v6, v6, 170), BvToWorld->m_rotation.m_col2.m_quad),
                       1u),
                     1u),
           extraRadius->m_real));
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v5, v5, 0), BvToWorld->m_rotation.m_col0.m_quad),
             _mm_mul_ps(_mm_shuffle_ps(v5, v5, 85), BvToWorld->m_rotation.m_col1.m_quad)),
           _mm_mul_ps(_mm_shuffle_ps(v5, v5, 170), BvToWorld->m_rotation.m_col2.m_quad)),
         BvToWorld->m_translation.m_quad);
  aabbOut->m_max.m_quad = _mm_add_ps(v8, v7);
  aabbOut->m_min.m_quad = _mm_add_ps(
                            _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v7),
                            v8);
}

// File Line: 81
// RVA: 0xC67540
void __fastcall hkAabbUtil::calcAabb(hkTransformf *BvToWorld, hkAabb *aabb, hkAabb *aabbOut)
{
  hkVector4f v3; // xmm2
  __m128 v4; // xmm6
  __m128 v5; // xmm2
  __m128 v6; // xmm5
  __m128 v7; // xmm2

  v3.m_quad = (__m128)aabb->m_max;
  v4 = _mm_mul_ps(_mm_add_ps(aabb->m_min.m_quad, v3.m_quad), (__m128)xmmword_141A711B0);
  v5 = _mm_mul_ps(_mm_sub_ps(v3.m_quad, aabb->m_min.m_quad), (__m128)xmmword_141A711B0);
  v6 = _mm_add_ps(
         _mm_add_ps(
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(_mm_shuffle_ps(v5, v5, 85), BvToWorld->m_rotation.m_col1.m_quad),
                       1u),
                     1u),
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(_mm_shuffle_ps(v5, v5, 0), BvToWorld->m_rotation.m_col0.m_quad),
                       1u),
                     1u)),
         (__m128)_mm_srli_epi32(
                   _mm_slli_epi32(
                     (__m128i)_mm_mul_ps(_mm_shuffle_ps(v5, v5, 170), BvToWorld->m_rotation.m_col2.m_quad),
                     1u),
                   1u));
  v7 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v4, v4, 0), BvToWorld->m_rotation.m_col0.m_quad),
             _mm_mul_ps(_mm_shuffle_ps(v4, v4, 85), BvToWorld->m_rotation.m_col1.m_quad)),
           _mm_mul_ps(_mm_shuffle_ps(v4, v4, 170), BvToWorld->m_rotation.m_col2.m_quad)),
         BvToWorld->m_translation.m_quad);
  aabbOut->m_max.m_quad = _mm_add_ps(v7, v6);
  aabbOut->m_min.m_quad = _mm_add_ps(
                            _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v6),
                            v7);
}

// File Line: 90
// RVA: 0xC67610
void __fastcall hkAabbUtil::calcAabb(hkQsTransformf *bvToWorld, hkAabb *aabb, hkAabb *aabbOut)
{
  hkVector4f v6; // xmm3
  __m128 v7; // xmm6
  __m128 v8; // xmm3
  __m128 v9; // xmm5
  __m128 v10; // xmm3
  hkTransformf transformOut; // [rsp+20h] [rbp-58h] BYREF

  hkQsTransformf::copyToTransformNoScale(bvToWorld, &transformOut);
  v6.m_quad = (__m128)aabb->m_max;
  v7 = _mm_mul_ps(
         _mm_mul_ps(_mm_add_ps(aabb->m_min.m_quad, v6.m_quad), (__m128)xmmword_141A711B0),
         bvToWorld->m_scale.m_quad);
  v8 = (__m128)_mm_srli_epi32(
                 _mm_slli_epi32(
                   (__m128i)_mm_mul_ps(
                              _mm_mul_ps(_mm_sub_ps(v6.m_quad, aabb->m_min.m_quad), (__m128)xmmword_141A711B0),
                              bvToWorld->m_scale.m_quad),
                   1u),
                 1u);
  v9 = _mm_add_ps(
         _mm_add_ps(
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), transformOut.m_rotation.m_col1.m_quad),
                       1u),
                     1u),
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), transformOut.m_rotation.m_col0.m_quad),
                       1u),
                     1u)),
         (__m128)_mm_srli_epi32(
                   _mm_slli_epi32(
                     (__m128i)_mm_mul_ps(_mm_shuffle_ps(v8, v8, 170), transformOut.m_rotation.m_col2.m_quad),
                     1u),
                   1u));
  v10 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), transformOut.m_rotation.m_col1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), transformOut.m_rotation.m_col0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), transformOut.m_rotation.m_col2.m_quad)),
          transformOut.m_translation.m_quad);
  aabbOut->m_max.m_quad = _mm_add_ps(v10, v9);
  aabbOut->m_min.m_quad = _mm_add_ps(
                            _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v9),
                            v10);
}

// File Line: 108
// RVA: 0xC67720
void __fastcall hkAabbUtil::calcAabb(hkQTransformf *bvToWorld, hkAabb *aabb, hkAabb *aabbOut)
{
  hkVector4f v6; // xmm3
  __m128 v7; // xmm6
  __m128 v8; // xmm3
  __m128 v9; // xmm5
  __m128 v10; // xmm3
  hkRotationf v11; // [rsp+20h] [rbp-58h] BYREF

  hkRotationf::set(&v11, &bvToWorld->m_rotation);
  v6.m_quad = (__m128)aabb->m_max;
  v7 = _mm_mul_ps(_mm_add_ps(aabb->m_min.m_quad, v6.m_quad), (__m128)xmmword_141A711B0);
  v8 = (__m128)_mm_srli_epi32(
                 _mm_slli_epi32(
                   (__m128i)_mm_mul_ps(_mm_sub_ps(v6.m_quad, aabb->m_min.m_quad), (__m128)xmmword_141A711B0),
                   1u),
                 1u);
  v9 = _mm_add_ps(
         _mm_add_ps(
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32((__m128i)_mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), v11.m_col1.m_quad), 1u),
                     1u),
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32((__m128i)_mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), v11.m_col0.m_quad), 1u),
                     1u)),
         (__m128)_mm_srli_epi32(
                   _mm_slli_epi32((__m128i)_mm_mul_ps(_mm_shuffle_ps(v8, v8, 170), v11.m_col2.m_quad), 1u),
                   1u));
  v10 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v11.m_col1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v11.m_col0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), v11.m_col2.m_quad)),
          bvToWorld->m_translation.m_quad);
  aabbOut->m_max.m_quad = _mm_add_ps(v10, v9);
  aabbOut->m_min.m_quad = _mm_add_ps(
                            _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v9),
                            v10);
}

// File Line: 124
// RVA: 0xC673E0
void __fastcall hkAabbUtil::calcAabb(hkVector4f *const *vectorArray, int numVertices, const __m128i *aabbOut)
{
  hkVector4f v3; // xmm2
  hkVector4f v5; // xmm0
  __int64 v6; // rcx
  hkVector4f *v7; // rax
  hkVector4f v8; // xmm1

  *aabbOut = (const __m128i)xmmword_141A712A0;
  v3.m_quad = (__m128)xmmword_141A712A0;
  v5.m_quad = _mm_xor_ps(
                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                (__m128)xmmword_141A712A0);
  aabbOut[1] = (const __m128i)v5.m_quad;
  if ( numVertices > 0 )
  {
    v6 = 0i64;
    do
    {
      v7 = vectorArray[v6++];
      v3.m_quad = _mm_min_ps(v3.m_quad, v7->m_quad);
      *(hkVector4f *)aabbOut = (hkVector4f)v3.m_quad;
      v5.m_quad = _mm_max_ps(v5.m_quad, v7->m_quad);
      aabbOut[1] = (const __m128i)v5.m_quad;
    }
    while ( v6 < numVertices );
    v8.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128(_mm_load_si128(aabbOut + 1), 4), 4);
    *aabbOut = _mm_srli_si128(_mm_slli_si128(_mm_load_si128(aabbOut), 4), 4);
    aabbOut[1] = (const __m128i)v8.m_quad;
  }
}

// File Line: 149
// RVA: 0xC67830
void __fastcall hkAabbUtil::initOffsetAabbInput(hkMotionState *motionState, hkAabbUtil::OffsetAabbInput *input)
{
  __m128 v4; // xmm0
  __m128 v5; // xmm6
  __m128 v6; // xmm4
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  hkVector4f v11; // xmm3
  hkVector4f v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm7
  __m128 v16; // xmm9
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm8
  __m128 v21; // xmm1
  __m128 v22; // xmm6
  __m128 v23; // xmm3
  __m128 v24; // xmm0
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  hkVector4f v28; // xmm3
  hkVector4f v29; // xmm1
  hkVector4f v30; // xmm3
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  __m128 m_quad; // xmm10
  __m128 v35; // xmm7
  __m128 v36; // xmm1
  __m128 v37; // xmm8
  __m128 v38; // xmm11
  __int64 m_storage; // rbx
  __m128 v40; // xmm0
  char *v41; // rbx
  __m128 v42; // xmm6
  __m128 v43; // xmm3
  __m128 v44; // xmm0
  __m128 v45; // xmm2
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm3
  hkVector4f v49; // xmm1
  __m128 v50; // xmm3
  hkQuaternionf qi; // [rsp+20h] [rbp-98h] BYREF

  input->m_motionState.m_storage = motionState;
  hkTransformf::setInverse(&input->m_endTransformInv, &motionState->m_transform);
  v4 = _mm_shuffle_ps(
         motionState->m_sweptTransform.m_centerOfMass0.m_quad,
         motionState->m_sweptTransform.m_centerOfMass0.m_quad,
         255);
  v5 = _mm_mul_ps(
         _mm_shuffle_ps(
           motionState->m_sweptTransform.m_centerOfMass1.m_quad,
           motionState->m_sweptTransform.m_centerOfMass1.m_quad,
           255),
         _mm_sub_ps(v4, v4));
  v6 = _mm_add_ps(
         _mm_mul_ps(
           _mm_sub_ps(
             motionState->m_sweptTransform.m_rotation1.m_vec.m_quad,
             motionState->m_sweptTransform.m_rotation0.m_vec.m_quad),
           v5),
         motionState->m_sweptTransform.m_rotation0.m_vec.m_quad);
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_add_ps(_mm_shuffle_ps(v7, v7, 78), v7);
  v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 177), v8);
  v10 = _mm_rsqrt_ps(v9);
  qi.m_vec.m_quad = _mm_mul_ps(
                      v6,
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                        _mm_mul_ps(*(__m128 *)_xmm, v10)));
  hkRotationf::set(&input->m_startTransform.m_rotation, &qi);
  v11.m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(
                     motionState->m_sweptTransform.m_centerOfMass1.m_quad,
                     motionState->m_sweptTransform.m_centerOfMass0.m_quad),
                   v5),
                 motionState->m_sweptTransform.m_centerOfMass0.m_quad);
  input->m_startTransform.m_translation = (hkVector4f)v11.m_quad;
  v12.m_quad = (__m128)motionState->m_sweptTransform.m_centerOfMassLocal;
  input->m_startTransform.m_translation.m_quad = _mm_sub_ps(
                                                   v11.m_quad,
                                                   _mm_add_ps(
                                                     _mm_add_ps(
                                                       _mm_mul_ps(
                                                         _mm_shuffle_ps(v12.m_quad, v12.m_quad, 85),
                                                         input->m_startTransform.m_rotation.m_col1.m_quad),
                                                       _mm_mul_ps(
                                                         _mm_shuffle_ps(v12.m_quad, v12.m_quad, 0),
                                                         input->m_startTransform.m_rotation.m_col0.m_quad)),
                                                     _mm_mul_ps(
                                                       _mm_shuffle_ps(v12.m_quad, v12.m_quad, 170),
                                                       input->m_startTransform.m_rotation.m_col2.m_quad)));
  v13 = _mm_shuffle_ps(
          motionState->m_sweptTransform.m_centerOfMass1.m_quad,
          motionState->m_sweptTransform.m_centerOfMass1.m_quad,
          255);
  if ( v13.m128_f32[0] == 0.0 )
  {
    input->m_numTransforms.m_storage = 0;
  }
  else
  {
    v14 = _mm_rcp_ps(v13);
    v15 = _mm_shuffle_ps(motionState->m_deltaAngle.m_quad, motionState->m_deltaAngle.m_quad, 255);
    v16 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v14, v13)), v14);
    v17 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_39269909), (__m128)LODWORD(FLOAT_0_39269909), 0);
    if ( v15.m128_f32[0] > v17.m128_f32[0] )
    {
      if ( v15.m128_f32[0] > 0.78539819 )
      {
        v33 = _mm_rcp_ps(v17);
        input->m_numTransforms.m_storage = 0;
        m_quad = query.m_quad;
        v35 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v17, v33)), v33), _mm_add_ps(v17, v15));
        v36 = _mm_rcp_ps(v35);
        v37 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v35, v36)), v36);
        v38 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_0824), (__m128)LODWORD(FLOAT_1_0824), 0);
        if ( v35.m128_f32[0] > 1.0 )
        {
          do
          {
            m_storage = input->m_numTransforms.m_storage;
            v40 = _mm_shuffle_ps(
                    motionState->m_sweptTransform.m_centerOfMass0.m_quad,
                    motionState->m_sweptTransform.m_centerOfMass0.m_quad,
                    255);
            input->m_numTransforms.m_storage = m_storage + 1;
            v41 = (char *)input + 64 * m_storage;
            v42 = _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v37, m_quad), v16), v40),
                      _mm_shuffle_ps(
                        motionState->m_sweptTransform.m_centerOfMass0.m_quad,
                        motionState->m_sweptTransform.m_centerOfMass0.m_quad,
                        255)),
                    _mm_shuffle_ps(
                      motionState->m_sweptTransform.m_centerOfMass1.m_quad,
                      motionState->m_sweptTransform.m_centerOfMass1.m_quad,
                      255));
            v43 = _mm_add_ps(
                    _mm_mul_ps(
                      _mm_sub_ps(
                        motionState->m_sweptTransform.m_rotation1.m_vec.m_quad,
                        motionState->m_sweptTransform.m_rotation0.m_vec.m_quad),
                      v42),
                    motionState->m_sweptTransform.m_rotation0.m_vec.m_quad);
            v44 = _mm_mul_ps(v43, v43);
            v45 = _mm_add_ps(_mm_shuffle_ps(v44, v44, 78), v44);
            v46 = _mm_add_ps(_mm_shuffle_ps(v45, v45, 177), v45);
            v47 = _mm_rsqrt_ps(v46);
            qi.m_vec.m_quad = _mm_mul_ps(
                                v43,
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v47, v46), v47)),
                                  _mm_mul_ps(v47, *(__m128 *)_xmm)));
            hkRotationf::set((hkRotationf *)(v41 + 16), &qi);
            v48 = _mm_add_ps(
                    _mm_mul_ps(
                      _mm_sub_ps(
                        motionState->m_sweptTransform.m_centerOfMass1.m_quad,
                        motionState->m_sweptTransform.m_centerOfMass0.m_quad),
                      v42),
                    motionState->m_sweptTransform.m_centerOfMass0.m_quad);
            *((__m128 *)v41 + 4) = v48;
            v49.m_quad = (__m128)motionState->m_sweptTransform.m_centerOfMassLocal;
            v50 = _mm_sub_ps(
                    v48,
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v49.m_quad, v49.m_quad, 85), *((__m128 *)v41 + 2)),
                        _mm_mul_ps(_mm_shuffle_ps(v49.m_quad, v49.m_quad, 0), *((__m128 *)v41 + 1))),
                      _mm_mul_ps(_mm_shuffle_ps(v49.m_quad, v49.m_quad, 170), *((__m128 *)v41 + 3))));
            *((__m128 *)v41 + 4) = _mm_shuffle_ps(v50, _mm_unpackhi_ps(v50, v38), 196);
            m_quad = _mm_add_ps(m_quad, (__m128)xmmword_141A710D0);
          }
          while ( m_quad.m128_f32[0] < v35.m128_f32[0] );
        }
      }
      else
      {
        v22 = _mm_mul_ps(
                _mm_sub_ps(
                  _mm_add_ps(
                    _mm_shuffle_ps(
                      motionState->m_sweptTransform.m_centerOfMass0.m_quad,
                      motionState->m_sweptTransform.m_centerOfMass0.m_quad,
                      255),
                    _mm_mul_ps(v16, (__m128)xmmword_141A711B0)),
                  _mm_shuffle_ps(
                    motionState->m_sweptTransform.m_centerOfMass0.m_quad,
                    motionState->m_sweptTransform.m_centerOfMass0.m_quad,
                    255)),
                _mm_shuffle_ps(
                  motionState->m_sweptTransform.m_centerOfMass1.m_quad,
                  motionState->m_sweptTransform.m_centerOfMass1.m_quad,
                  255));
        v23 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    motionState->m_sweptTransform.m_rotation1.m_vec.m_quad,
                    motionState->m_sweptTransform.m_rotation0.m_vec.m_quad),
                  v22),
                motionState->m_sweptTransform.m_rotation0.m_vec.m_quad);
        v24 = _mm_mul_ps(v23, v23);
        v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 78), v24);
        v26 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 177), v25);
        v27 = _mm_rsqrt_ps(v26);
        qi.m_vec.m_quad = _mm_mul_ps(
                            v23,
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                              _mm_mul_ps(*(__m128 *)_xmm, v27)));
        hkRotationf::set(&input->m_transforms[0].m_rotation, &qi);
        v28.m_quad = _mm_add_ps(
                       _mm_mul_ps(
                         _mm_sub_ps(
                           motionState->m_sweptTransform.m_centerOfMass1.m_quad,
                           motionState->m_sweptTransform.m_centerOfMass0.m_quad),
                         v22),
                       motionState->m_sweptTransform.m_centerOfMass0.m_quad);
        input->m_transforms[0].m_translation = (hkVector4f)v28.m_quad;
        v29.m_quad = (__m128)motionState->m_sweptTransform.m_centerOfMassLocal;
        v30.m_quad = _mm_sub_ps(
                       v28.m_quad,
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_shuffle_ps(v29.m_quad, v29.m_quad, 85),
                             input->m_transforms[0].m_rotation.m_col1.m_quad),
                           _mm_mul_ps(
                             _mm_shuffle_ps(v29.m_quad, v29.m_quad, 0),
                             input->m_transforms[0].m_rotation.m_col0.m_quad)),
                         _mm_mul_ps(
                           _mm_shuffle_ps(v29.m_quad, v29.m_quad, 170),
                           input->m_transforms[0].m_rotation.m_col2.m_quad)));
        input->m_transforms[0].m_translation = (hkVector4f)v30.m_quad;
        v31 = _mm_sub_ps(
                query.m_quad,
                _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(v15, v15), (__m128)xmmword_141A711D0), (__m128)xmmword_141A711B0));
        v32 = _mm_rcp_ps(v31);
        input->m_transforms[0].m_translation.m_quad = _mm_shuffle_ps(
                                                        v30.m_quad,
                                                        _mm_unpackhi_ps(
                                                          v30.m_quad,
                                                          _mm_mul_ps(
                                                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v32, v31)),
                                                            v32)),
                                                        196);
        input->m_numTransforms.m_storage = 1;
      }
    }
    else
    {
      v18 = _mm_sub_ps(query.m_quad, _mm_mul_ps(_mm_mul_ps(v15, v15), (__m128)xmmword_141A711B0));
      v19 = _mm_rcp_ps(v18);
      input->m_transforms[0].m_rotation.m_col0 = input->m_startTransform.m_rotation.m_col0;
      v20 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v19, v18)), v19);
      input->m_transforms[0].m_rotation.m_col1 = input->m_startTransform.m_rotation.m_col1;
      input->m_transforms[0].m_rotation.m_col2 = input->m_startTransform.m_rotation.m_col2;
      v21 = input->m_startTransform.m_translation.m_quad;
      input->m_transforms[0].m_translation.m_quad = v21;
      input->m_transforms[0].m_translation.m_quad = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, v20), 196);
      input->m_numTransforms.m_storage = 1;
    }
  }
}


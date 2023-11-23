// File Line: 21
// RVA: 0xB1E520
void __fastcall hkaSkeletonUtils::transformLocalPoseToWorldPose(
        int numTransforms,
        const __int16 *parentIndices,
        hkQsTransformf *worldFromModel,
        hkQsTransformf *poseLocal,
        hkQsTransformf *poseWorldOut)
{
  __int64 v5; // r10
  hkQuaternionf *p_m_rotation; // rbx
  signed __int64 v7; // r11
  __int64 v8; // rax
  hkQsTransformf *v9; // rax
  __m128 m_quad; // xmm2
  __m128 v11; // xmm3
  __m128 v12; // xmm1
  __m128 v13; // xmm5
  __m128 v14; // xmm6
  __m128 v15; // xmm4
  __m128 v16; // xmm2
  __m128 v17; // xmm4
  __m128 v18; // xmm5
  __m128 v19; // xmm6
  __m128 v20; // xmm3
  __m128 v21; // xmm4
  __m128 v22; // xmm0
  __m128 v23; // xmm6
  __m128 v24; // xmm3
  __m128 v25; // xmm3
  __m128 v26; // xmm0

  if ( numTransforms > 0 )
  {
    v5 = 0i64;
    p_m_rotation = &poseLocal->m_rotation;
    v7 = (char *)poseWorldOut - (char *)poseLocal;
    do
    {
      v8 = parentIndices[v5];
      if ( (_DWORD)v8 == -1 )
        v9 = worldFromModel;
      else
        v9 = &poseWorldOut[v8];
      m_quad = v9->m_rotation.m_vec.m_quad;
      v11 = p_m_rotation[-1].m_vec.m_quad;
      ++v5;
      p_m_rotation += 3;
      v12 = _mm_mul_ps(v11, m_quad);
      v13 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v11));
      v14 = _mm_shuffle_ps(m_quad, m_quad, 255);
      v15 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                _mm_shuffle_ps(v12, v12, 170)),
              m_quad);
      v16 = p_m_rotation[-3].m_vec.m_quad;
      v17 = _mm_add_ps(
              _mm_add_ps(v15, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v14, v14), (__m128)xmmword_141A711B0), v11)),
              _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v14));
      v18 = _mm_shuffle_ps(v16, v16, 255);
      *(__m128 *)((char *)&p_m_rotation[-4].m_vec.m_quad + v7) = _mm_add_ps(
                                                                   _mm_add_ps(v17, v17),
                                                                   v9->m_translation.m_quad);
      v19 = v9->m_rotation.m_vec.m_quad;
      v20 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v19);
      v21 = _mm_shuffle_ps(v19, v19, 255);
      v22 = _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v16);
      v23 = _mm_mul_ps(v19, v16);
      v24 = _mm_sub_ps(v20, v22);
      v25 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v24, v24, 201), _mm_mul_ps(v21, v16)),
              _mm_mul_ps(v9->m_rotation.m_vec.m_quad, v18));
      v26 = p_m_rotation[-2].m_vec.m_quad;
      *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v7) = _mm_shuffle_ps(
                                                                   v25,
                                                                   _mm_unpackhi_ps(
                                                                     v25,
                                                                     _mm_sub_ps(
                                                                       _mm_mul_ps(v18, v21),
                                                                       _mm_add_ps(
                                                                         _mm_add_ps(
                                                                           _mm_shuffle_ps(v23, v23, 85),
                                                                           _mm_shuffle_ps(v23, v23, 0)),
                                                                         _mm_shuffle_ps(v23, v23, 170)))),
                                                                   196);
      *(__m128 *)((char *)&p_m_rotation[-2].m_vec.m_quad + v7) = _mm_mul_ps(v26, v9->m_scale.m_quad);
    }
    while ( v5 < numTransforms );
  }
}

// File Line: 33
// RVA: 0xB1DFC0
void __fastcall hkaSkeletonUtils::transformLocalBoneToModelBone(
        int boneIndex,
        const __int16 *parentIndices,
        hkQsTransformf *poseLocal,
        hkQsTransformf *boneModelOut)
{
  hkQuaternionf v4; // xmm1
  __m128 m_quad; // xmm8
  int v6; // eax
  hkQuaternionf v7; // xmm7
  __int64 v8; // rcx
  __int64 v9; // rax
  hkQuaternionf v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm6
  __m128 v13; // xmm5
  __m128 v14; // xmm3
  __m128 v15; // xmm4
  hkQuaternionf v16; // xmm2
  hkQuaternionf v17; // xmm4
  __m128 v18; // xmm5
  __m128 v19; // xmm7
  __m128 v20; // xmm0
  __m128 v21; // xmm4
  __m128 v22; // xmm7

  boneModelOut->m_translation = poseLocal[boneIndex].m_translation;
  v4.m_vec.m_quad = (__m128)poseLocal[boneIndex].m_rotation;
  boneModelOut->m_rotation = (hkQuaternionf)v4.m_vec.m_quad;
  m_quad = poseLocal[boneIndex].m_scale.m_quad;
  boneModelOut->m_scale.m_quad = m_quad;
  v6 = parentIndices[boneIndex];
  if ( v6 >= 0 )
  {
    v7.m_vec.m_quad = v4.m_vec.m_quad;
    do
    {
      v8 = v6;
      v9 = v6;
      v10.m_vec.m_quad = (__m128)poseLocal[v9].m_rotation;
      v11 = _mm_mul_ps(boneModelOut->m_translation.m_quad, v10.m_vec.m_quad);
      v12 = _mm_shuffle_ps(v10.m_vec.m_quad, v10.m_vec.m_quad, 255);
      v13 = _mm_sub_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(boneModelOut->m_translation.m_quad, boneModelOut->m_translation.m_quad, 201),
                v10.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v10.m_vec.m_quad, v10.m_vec.m_quad, 201), boneModelOut->m_translation.m_quad));
      v14 = _mm_shuffle_ps(v7.m_vec.m_quad, v7.m_vec.m_quad, 255);
      v15 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                    _mm_shuffle_ps(v11, v11, 170)),
                  v10.m_vec.m_quad),
                _mm_mul_ps(
                  _mm_sub_ps(_mm_mul_ps(v12, v12), (__m128)xmmword_141A711B0),
                  boneModelOut->m_translation.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v12));
      boneModelOut->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v15, v15), poseLocal[v9].m_translation.m_quad);
      v16.m_vec.m_quad = (__m128)poseLocal[v9].m_rotation;
      v17.m_vec.m_quad = (__m128)boneModelOut->m_rotation;
      v18 = _mm_shuffle_ps(v16.m_vec.m_quad, v16.m_vec.m_quad, 255);
      v19 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v17.m_vec.m_quad, v17.m_vec.m_quad, 201), v16.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v16.m_vec.m_quad, v16.m_vec.m_quad, 201), v17.m_vec.m_quad));
      v20 = _mm_mul_ps(v18, v17.m_vec.m_quad);
      v21 = _mm_mul_ps(v17.m_vec.m_quad, v16.m_vec.m_quad);
      v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 201), v20), _mm_mul_ps(v14, v16.m_vec.m_quad));
      v7.m_vec.m_quad = _mm_shuffle_ps(
                          v22,
                          _mm_unpackhi_ps(
                            v22,
                            _mm_sub_ps(
                              _mm_mul_ps(v14, v18),
                              _mm_add_ps(
                                _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                                _mm_shuffle_ps(v21, v21, 170)))),
                          196);
      boneModelOut->m_rotation = (hkQuaternionf)v7.m_vec.m_quad;
      m_quad = _mm_mul_ps(m_quad, poseLocal[v9].m_scale.m_quad);
      boneModelOut->m_scale.m_quad = m_quad;
      v6 = parentIndices[v8];
    }
    while ( v6 >= 0 );
  }
}

// File Line: 49
// RVA: 0xB1DF90
void __fastcall hkaSkeletonUtils::transformLocalPoseToModelPose(
        int numTransforms,
        const __int16 *parentIndices,
        hkQsTransformf *poseLocal,
        hkQsTransformf *poseModelOut)
{
  hkaSkeletonUtils::transformLocalPoseToWorldPose(
    numTransforms,
    parentIndices,
    &hkQsTransformf_identityStorage,
    poseLocal,
    poseModelOut);
}

// File Line: 55
// RVA: 0xB1E6A0
void __fastcall hkaSkeletonUtils::transformWorldPoseToLocalPose(
        int numTransforms,
        const __int16 *parentIndices,
        hkQsTransformf *worldFromModel,
        hkQsTransformf *poseWorld,
        hkQsTransformf *poseLocalOut)
{
  __int64 v5; // rbp
  __m128i inserted; // xmm0
  __int64 v10; // r13
  signed __int64 v11; // r12
  __m128 v12; // xmm10
  __m128 v13; // xmm11
  __int64 v14; // rax
  hkQsTransformf *v15; // rdi
  __m128 m_quad; // xmm0
  __m128 v17; // xmm8
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm7
  __m128 v21; // xmm5
  __m128 v22; // xmm9
  __m128 v23; // xmm1
  __m128 v24; // xmm4
  __m128 v25; // xmm2
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  __m128 v30; // xmm8
  __m128 v31; // xmm4
  __m128 v32; // xmm4
  __m128 v33; // xmm0
  hkQuaternionf *p_m_rotation; // [rsp+20h] [rbp-D8h]
  hkVector4f v35; // [rsp+30h] [rbp-C8h] BYREF

  if ( numTransforms > 0 )
  {
    v5 = 0i64;
    inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
    v10 = numTransforms;
    p_m_rotation = &poseWorld->m_rotation;
    v11 = (char *)poseLocalOut - (char *)poseWorld;
    v12 = (__m128)_mm_shuffle_epi32(inserted, 0);
    v13 = (__m128)_mm_shuffle_epi32(inserted, 64);
    do
    {
      v14 = parentIndices[v5];
      if ( (_DWORD)v14 == -1 )
        v15 = worldFromModel;
      else
        v15 = &poseWorld[v14];
      hkVector4f::setRotatedInverseDir(&v35, &v15->m_rotation, &v15->m_translation);
      m_quad = v15->m_scale.m_quad;
      v17 = _mm_xor_ps(v13, v15->m_rotation.m_vec.m_quad);
      v18 = _mm_rcp_ps(m_quad);
      v19 = p_m_rotation[-1].m_vec.m_quad;
      v20 = _mm_shuffle_ps(v17, v17, 255);
      v21 = _mm_shuffle_ps(v17, v17, 201);
      v22 = (__m128)_mm_srli_si128(
                      _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(m_quad, v18)), v18), 4),
                      4);
      v23 = _mm_mul_ps(v17, v19);
      v24 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v17), _mm_mul_ps(v21, v19));
      v25 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                    _mm_shuffle_ps(v23, v23, 170)),
                  v17),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v20, v20), (__m128)xmmword_141A711B0), v19)),
              _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v20));
      *(__m128 *)((char *)&p_m_rotation[-1].m_vec.m_quad + v11) = _mm_add_ps(
                                                                    _mm_add_ps(v25, v25),
                                                                    _mm_xor_ps(v12, v35.m_quad));
      v26 = p_m_rotation->m_vec.m_quad;
      v27 = _mm_shuffle_ps(v26, v26, 255);
      v28 = _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v17);
      v29 = _mm_mul_ps(v17, v27);
      v30 = _mm_mul_ps(v17, p_m_rotation->m_vec.m_quad);
      v31 = _mm_sub_ps(v28, _mm_mul_ps(v21, p_m_rotation->m_vec.m_quad));
      v32 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 201), _mm_mul_ps(v20, p_m_rotation->m_vec.m_quad)), v29);
      v33 = _mm_mul_ps(p_m_rotation[1].m_vec.m_quad, v22);
      *(__m128 *)((char *)&p_m_rotation->m_vec.m_quad + v11) = _mm_shuffle_ps(
                                                                 v32,
                                                                 _mm_unpackhi_ps(
                                                                   v32,
                                                                   _mm_sub_ps(
                                                                     _mm_mul_ps(v27, v20),
                                                                     _mm_add_ps(
                                                                       _mm_add_ps(
                                                                         _mm_shuffle_ps(v30, v30, 85),
                                                                         _mm_shuffle_ps(v30, v30, 0)),
                                                                       _mm_shuffle_ps(v30, v30, 170)))),
                                                                 196);
      *(__m128 *)((char *)p_m_rotation + v11 + 16) = v33;
      ++v5;
      p_m_rotation += 3;
    }
    while ( v5 < v10 );
  }
}

// File Line: 67
// RVA: 0xB1E140
void __fastcall hkaSkeletonUtils::transformModelPoseToLocalPose(
        int numTransforms,
        const __int16 *parentIndices,
        hkQsTransformf *poseModel,
        hkQsTransformf *poseLocalOut)
{
  hkaSkeletonUtils::transformWorldPoseToLocalPose(
    numTransforms,
    parentIndices,
    &hkQsTransformf_identityStorage,
    poseModel,
    poseLocalOut);
}

// File Line: 72
// RVA: 0xB1E170
void __fastcall hkaSkeletonUtils::transformModelPoseToWorldPose(
        int numTransforms,
        hkQsTransformf *worldFromModel,
        hkQsTransformf *poseModel,
        hkQsTransformf *poseWorldOut)
{
  __int64 v4; // rax
  hkQuaternionf v5; // xmm5
  hkQuaternionf *p_m_rotation; // rcx
  signed __int64 v7; // r9
  hkVector4f v8; // xmm10
  hkVector4f v9; // xmm11
  __m128 v10; // xmm8
  __m128 v11; // xmm6
  __m128 m_quad; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  __m128 v15; // xmm0
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm3
  __m128 v20; // xmm4
  __m128 v21; // xmm1
  __m128 v22; // xmm0

  v4 = numTransforms;
  if ( numTransforms > 0 )
  {
    v5.m_vec.m_quad = (__m128)worldFromModel->m_rotation;
    p_m_rotation = &poseModel->m_rotation;
    v7 = (char *)poseWorldOut - (char *)poseModel;
    v8.m_quad = (__m128)worldFromModel->m_translation;
    v9.m_quad = (__m128)worldFromModel->m_scale;
    v10 = _mm_shuffle_ps(v5.m_vec.m_quad, v5.m_vec.m_quad, 201);
    v11 = _mm_shuffle_ps(v5.m_vec.m_quad, v5.m_vec.m_quad, 255);
    do
    {
      m_quad = p_m_rotation[-1].m_vec.m_quad;
      p_m_rotation += 3;
      v13 = _mm_mul_ps(m_quad, v5.m_vec.m_quad);
      v14 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v5.m_vec.m_quad), _mm_mul_ps(m_quad, v10));
      v15 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v11, v11), (__m128)xmmword_141A711B0), m_quad);
      v16 = p_m_rotation[-3].m_vec.m_quad;
      v17 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                    _mm_shuffle_ps(v13, v13, 170)),
                  v5.m_vec.m_quad),
                v15),
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v11));
      v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v5.m_vec.m_quad), _mm_mul_ps(v10, v16));
      *(__m128 *)((char *)&p_m_rotation[-4].m_vec.m_quad + v7) = _mm_add_ps(_mm_add_ps(v17, v17), v8.m_quad);
      v19 = _mm_shuffle_ps(v16, v16, 255);
      v20 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v18, v18, 201), _mm_mul_ps(v11, v16)),
              _mm_mul_ps(v5.m_vec.m_quad, v19));
      v21 = _mm_mul_ps(v5.m_vec.m_quad, v16);
      v22 = _mm_mul_ps(p_m_rotation[-2].m_vec.m_quad, v9.m_quad);
      *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v7) = _mm_shuffle_ps(
                                                                   v20,
                                                                   _mm_unpackhi_ps(
                                                                     v20,
                                                                     _mm_sub_ps(
                                                                       _mm_mul_ps(v19, v11),
                                                                       _mm_add_ps(
                                                                         _mm_add_ps(
                                                                           _mm_shuffle_ps(v21, v21, 85),
                                                                           _mm_shuffle_ps(v21, v21, 0)),
                                                                         _mm_shuffle_ps(v21, v21, 170)))),
                                                                   196);
      *(__m128 *)((char *)p_m_rotation + v7 - 32) = v22;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 81
// RVA: 0xB1E300
void __fastcall hkaSkeletonUtils::transformWorldPoseToModelPose(
        int numTransforms,
        hkQsTransformf *worldFromModel,
        hkQsTransformf *poseWorld,
        hkQsTransformf *poseModelOut)
{
  __int64 v5; // rdi
  hkQuaternionf *p_m_rotation; // rbp
  signed __int64 v7; // rbx
  __m128i inserted; // xmm0
  __m128 v9; // xmm10
  __m128 v10; // xmm11
  __m128 m_quad; // xmm3
  hkVector4f v12; // xmm0
  __m128 v13; // xmm8
  __m128 v14; // xmm1
  __m128 v15; // xmm7
  __m128 v16; // xmm5
  __m128 v17; // xmm4
  __m128i v18; // xmm9
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm4
  __m128 v24; // xmm1
  __m128 v25; // xmm8
  __m128 v26; // xmm4
  __m128 v27; // xmm4
  __m128 v28; // xmm0
  hkVector4f v29; // [rsp+20h] [rbp-A8h] BYREF

  if ( numTransforms > 0 )
  {
    v5 = numTransforms;
    p_m_rotation = &poseWorld->m_rotation;
    v7 = (char *)poseModelOut - (char *)poseWorld;
    inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
    v9 = (__m128)_mm_shuffle_epi32(inserted, 0);
    v10 = (__m128)_mm_shuffle_epi32(inserted, 64);
    do
    {
      hkVector4f::setRotatedInverseDir(&v29, &worldFromModel->m_rotation, &worldFromModel->m_translation);
      p_m_rotation += 3;
      m_quad = p_m_rotation[-4].m_vec.m_quad;
      v12.m_quad = (__m128)worldFromModel->m_scale;
      v13 = _mm_xor_ps(v10, worldFromModel->m_rotation.m_vec.m_quad);
      v14 = _mm_rcp_ps(v12.m_quad);
      v15 = _mm_shuffle_ps(v13, v13, 255);
      v16 = _mm_shuffle_ps(v13, v13, 201);
      v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v13), _mm_mul_ps(v16, m_quad));
      v18 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v12.m_quad, v14)), v14), 4);
      v19 = _mm_mul_ps(v13, m_quad);
      v20 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                    _mm_shuffle_ps(v19, v19, 170)),
                  v13),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v15, v15), (__m128)xmmword_141A711B0), m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v15));
      *(__m128 *)((char *)&p_m_rotation[-4].m_vec.m_quad + v7) = _mm_add_ps(
                                                                   _mm_add_ps(v20, v20),
                                                                   _mm_xor_ps(v9, v29.m_quad));
      v21 = p_m_rotation[-3].m_vec.m_quad;
      v22 = _mm_shuffle_ps(v21, v21, 255);
      v23 = _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v13);
      v24 = _mm_mul_ps(v13, v22);
      v25 = _mm_mul_ps(v13, v21);
      v26 = _mm_sub_ps(v23, _mm_mul_ps(v16, v21));
      v27 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v26, v26, 201), _mm_mul_ps(v15, v21)), v24);
      v28 = _mm_mul_ps(p_m_rotation[-2].m_vec.m_quad, (__m128)_mm_srli_si128(v18, 4));
      *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v7) = _mm_shuffle_ps(
                                                                   v27,
                                                                   _mm_unpackhi_ps(
                                                                     v27,
                                                                     _mm_sub_ps(
                                                                       _mm_mul_ps(v22, v15),
                                                                       _mm_add_ps(
                                                                         _mm_add_ps(
                                                                           _mm_shuffle_ps(v25, v25, 85),
                                                                           _mm_shuffle_ps(v25, v25, 0)),
                                                                         _mm_shuffle_ps(v25, v25, 170)))),
                                                                   196);
      *(__m128 *)((char *)p_m_rotation + v7 - 32) = v28;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 92
// RVA: 0xB1EFD0
void __fastcall hkaSkeletonUtils::enforceSkeletonConstraintsLocalSpace(
        hkaSkeleton *skeleton,
        hkQsTransformf *poseInOut)
{
  __int64 m_size; // r9
  __int64 v3; // rax
  __int64 v4; // r8

  m_size = skeleton->m_bones.m_size;
  if ( m_size > 0 )
  {
    v3 = 0i64;
    v4 = 0i64;
    do
    {
      if ( skeleton->m_bones.m_data[v4].m_lockTranslation.m_bool )
        poseInOut[v3].m_translation = skeleton->m_referencePose.m_data[v3].m_translation;
      ++v4;
      ++v3;
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 107
// RVA: 0xB1F140
void __fastcall hkaSkeletonUtils::enforcePoseConstraintsLocalSpace(
        hkaSkeleton *skeleton,
        hkQsTransformf *constraintsLocal,
        hkQsTransformf *poseInOut)
{
  __int64 m_size; // r10
  __int64 v4; // r9
  signed __int64 v5; // rdx

  m_size = skeleton->m_bones.m_size;
  if ( m_size > 0 )
  {
    v4 = 0i64;
    v5 = (char *)constraintsLocal - (char *)poseInOut;
    do
    {
      if ( skeleton->m_bones.m_data[v4].m_lockTranslation.m_bool )
        poseInOut->m_translation = *(hkVector4f *)((char *)&poseInOut->m_translation + v5);
      ++v4;
      ++poseInOut;
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 122
// RVA: 0xB1F010
void __fastcall hkaSkeletonUtils::enforceSkeletonConstraintsModelSpace(
        hkaSkeleton *skeleton,
        hkQsTransformf *poseModelInOut)
{
  __int64 m_size; // rdi
  __int64 v3; // r8
  __int64 v5; // r11
  hkQsTransformf *v6; // r9
  __int16 v7; // cx
  signed __int64 v8; // rax
  __m128 v9; // xmm3
  hkQuaternionf v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm6
  __m128 v13; // xmm4
  __m128 v14; // xmm5
  __m128 v15; // xmm5

  m_size = skeleton->m_bones.m_size;
  v3 = 0i64;
  if ( m_size > 0 )
  {
    v5 = 0i64;
    v6 = poseModelInOut;
    do
    {
      v7 = skeleton->m_parentIndices.m_data[v3];
      if ( skeleton->m_bones.m_data[v5].m_lockTranslation.m_bool )
      {
        v8 = (char *)skeleton->m_referencePose.m_data - (char *)poseModelInOut;
        if ( v7 == -1 )
        {
          v6->m_translation = *(hkVector4f *)((char *)&v6->m_translation + v8);
        }
        else
        {
          v9 = *(__m128 *)((char *)&v6->m_translation.m_quad + v8);
          v10.m_vec.m_quad = (__m128)poseModelInOut[v7].m_rotation;
          v11 = _mm_mul_ps(v10.m_vec.m_quad, v9);
          v12 = _mm_shuffle_ps(v10.m_vec.m_quad, v10.m_vec.m_quad, 255);
          v13 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v10.m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v10.m_vec.m_quad, v10.m_vec.m_quad, 201), v9));
          v14 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                        _mm_shuffle_ps(v11, v11, 170)),
                      v10.m_vec.m_quad),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v12, v12), (__m128)xmmword_141A711B0), v9)),
                  _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v12));
          v15 = _mm_add_ps(v14, v14);
          v6->m_translation.m_quad = v15;
          v6->m_translation.m_quad = _mm_add_ps(v15, poseModelInOut[v7].m_translation.m_quad);
        }
      }
      ++v3;
      ++v5;
      ++v6;
    }
    while ( v3 < m_size );
  }
}

// File Line: 149
// RVA: 0xB1F180
void __fastcall hkaSkeletonUtils::enforcePoseConstraintsModelSpace(
        hkaSkeleton *skeleton,
        hkQsTransformf *constraintsLocal,
        hkQsTransformf *poseModelInOut)
{
  __int64 m_size; // rbx
  __int64 v4; // r9
  __int64 v7; // r10
  signed __int64 v8; // r8
  __int16 v9; // cx
  hkQsTransformf *v10; // rcx
  __m128 m_quad; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm6
  __m128 v14; // xmm5
  __m128 v15; // xmm4

  m_size = skeleton->m_bones.m_size;
  v4 = 0i64;
  if ( m_size > 0 )
  {
    v7 = 0i64;
    v8 = (char *)poseModelInOut - (char *)constraintsLocal;
    do
    {
      v9 = skeleton->m_parentIndices.m_data[v4];
      if ( skeleton->m_bones.m_data[v7].m_lockTranslation.m_bool )
      {
        if ( v9 == -1 )
        {
          *(hkVector4f *)((char *)&constraintsLocal->m_translation + v8) = constraintsLocal->m_translation;
        }
        else
        {
          v10 = &poseModelInOut[v9];
          m_quad = v10->m_rotation.m_vec.m_quad;
          v12 = _mm_mul_ps(constraintsLocal->m_translation.m_quad, m_quad);
          v13 = _mm_shuffle_ps(m_quad, m_quad, 255);
          v14 = _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(constraintsLocal->m_translation.m_quad, constraintsLocal->m_translation.m_quad, 201),
                    m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), constraintsLocal->m_translation.m_quad));
          v15 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                        _mm_shuffle_ps(v12, v12, 170)),
                      m_quad),
                    _mm_mul_ps(
                      _mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0),
                      constraintsLocal->m_translation.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v13));
          *(__m128 *)((char *)&constraintsLocal->m_translation.m_quad + v8) = _mm_add_ps(
                                                                                _mm_add_ps(v15, v15),
                                                                                v10->m_translation.m_quad);
        }
      }
      ++v4;
      ++v7;
      ++constraintsLocal;
    }
    while ( v4 < m_size );
  }
}

// File Line: 179
// RVA: 0xB1F310
void __fastcall hkaSkeletonUtils::lockTranslations(hkaSkeleton *skeleton, hkBool exceptRoots)
{
  __int64 m_size; // r11
  __int64 v3; // rax
  __int64 v4; // r9
  char m_bool; // [rsp+10h] [rbp+10h]

  m_size = skeleton->m_bones.m_size;
  v3 = 0i64;
  m_bool = exceptRoots.m_bool;
  if ( m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      if ( skeleton->m_parentIndices.m_data[v3] > 0 || !exceptRoots.m_bool )
      {
        skeleton->m_bones.m_data[v4].m_lockTranslation.m_bool = 1;
        exceptRoots.m_bool = m_bool;
      }
      ++v3;
      ++v4;
    }
    while ( v3 < m_size );
  }
}

// File Line: 194
// RVA: 0xB1F3A0
hkBool *__fastcall hkaSkeletonUtils::getBoneChain(
        hkBool *result,
        hkaSkeleton *skeleton,
        __int16 startBone,
        __int16 endBone,
        hkArray<short,hkContainerHeapAllocator> *bonesOut)
{
  __int16 v5; // bx
  hkArray<short,hkContainerHeapAllocator> *v9; // rax
  int m_size; // edi
  int v11; // edx
  hkLifoAllocator *Value; // rax
  char *m_cur; // r8
  int v14; // edx
  char *v15; // rcx
  char *v16; // rax
  unsigned int v17; // edi
  bool v18; // zf
  bool v19; // sf
  bool v20; // of
  __int16 *m_data; // rax
  bool v22; // bl
  hkArray<short,hkContainerHeapAllocator> *v23; // rdi
  int v24; // eax
  __int64 v25; // r14
  int v26; // eax
  __int64 v27; // r8
  __int64 v28; // r9
  __int16 v29; // cx
  char *v30; // rdi
  int v31; // eax
  unsigned int m_slotID; // ecx
  signed int v33; // ebx
  hkLifoAllocator *v34; // rax
  int v35; // r8d
  char *array; // [rsp+30h] [rbp-20h] BYREF
  int v38; // [rsp+38h] [rbp-18h]
  int v39; // [rsp+3Ch] [rbp-14h]
  void *p; // [rsp+40h] [rbp-10h]
  int v41; // [rsp+48h] [rbp-8h]
  hkResult resulta; // [rsp+90h] [rbp+40h] BYREF

  v5 = endBone;
  if ( startBone <= endBone )
  {
    m_size = skeleton->m_bones.m_size;
    v11 = 0;
    array = 0i64;
    v38 = 0;
    v39 = 0x80000000;
    v41 = m_size;
    if ( m_size )
    {
      Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (char *)Value->m_cur;
      v14 = (2 * m_size + 127) & 0xFFFFFF80;
      v15 = &m_cur[v14];
      if ( v14 > Value->m_slabSize || v15 > Value->m_end )
      {
        v16 = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v14);
        v11 = v38;
        array = v16;
      }
      else
      {
        Value->m_cur = v15;
        v11 = v38;
        array = m_cur;
      }
    }
    else
    {
      array = 0i64;
    }
    v17 = m_size | 0x80000000;
    p = array;
    v39 = v17;
    v20 = __OFSUB__(v5, -1);
    v18 = v5 == -1;
    v19 = (__int16)(v5 + 1) < 0;
    if ( v5 > -1 )
    {
      do
      {
        if ( v5 == startBone )
          break;
        if ( v11 == (v17 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 2);
          v11 = v38;
        }
        *(_WORD *)&array[2 * v11] = v5;
        m_data = skeleton->m_parentIndices.m_data;
        v17 = v39;
        v11 = ++v38;
        v5 = m_data[v5];
      }
      while ( v5 > -1 );
      v20 = __OFSUB__(v5, -1);
      v18 = v5 == -1;
      v19 = (__int16)(v5 + 1) < 0;
    }
    v22 = !(v19 ^ v20 | v18);
    if ( !(v19 ^ v20 | v18) )
    {
      if ( v11 == (v17 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 2);
        v11 = v38;
      }
      v23 = bonesOut;
      *(_WORD *)&array[2 * v11] = startBone;
      v11 = v38 + 1;
      v24 = v23->m_capacityAndFlags & 0x3FFFFFFF;
      v38 = v11;
      v25 = v11;
      if ( v24 < v11 )
      {
        v26 = 2 * v24;
        if ( v11 < v26 )
          v11 = v26;
        hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, v23, v11, 2);
        v11 = v38;
      }
      v23->m_size = v25;
      v27 = 0i64;
      if ( (int)v25 > 0 )
      {
        v28 = 2 * v25;
        do
        {
          ++v27;
          v29 = *(_WORD *)&array[v28 - 2];
          v28 -= 2i64;
          v23->m_data[v27 - 1] = v29;
        }
        while ( v27 < v25 );
        v11 = v38;
      }
    }
    v30 = (char *)p;
    v31 = v41;
    m_slotID = hkMemoryRouter::s_memoryRouter.m_slotID;
    v18 = p == array;
    result->m_bool = v22;
    if ( v18 )
      v11 = 0;
    v33 = (2 * v31 + 127) & 0xFFFFFF80;
    v38 = v11;
    v34 = (hkLifoAllocator *)TlsGetValue(m_slotID);
    v35 = (v33 + 15) & 0xFFFFFFF0;
    if ( v33 > v34->m_slabSize || &v30[v35] != v34->m_cur || v34->m_firstNonLifoEnd == v30 )
      hkLifoAllocator::slowBlockFree(v34, v30, v35);
    else
      v34->m_cur = v30;
    v38 = 0;
    if ( v39 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        array,
        2 * (v39 & 0x3FFFFFFF));
  }
  else
  {
    v9 = bonesOut;
    result->m_bool = 0;
    v9->m_size = 0;
  }
  return result;
}

// File Line: 236
// RVA: 0xB1F620
hkBool *__fastcall hkaSkeletonUtils::getBoneChainWithinPartition(
        hkBool *result,
        hkaSkeleton *skeleton,
        __int16 startBone,
        __int16 endBone,
        hkArray<short,hkContainerHeapAllocator> *bonesOut)
{
  __int16 v5; // bx
  hkBool *v8; // r15
  hkArray<short,hkContainerHeapAllocator> *v9; // rax
  int m_size; // edi
  int v12; // r9d
  hkLifoAllocator *Value; // rax
  char *m_cur; // r8
  int v15; // edx
  char *v16; // rcx
  char *v17; // rax
  __int64 v18; // r14
  unsigned int v19; // edi
  int v20; // r10d
  int v21; // r11d
  __int16 *p_m_startBoneIndex; // r8
  int v23; // ecx
  int v24; // eax
  __int64 v25; // r14
  bool v26; // zf
  bool v27; // sf
  bool v28; // of
  __int16 *m_data; // rax
  bool v30; // bl
  hkArray<short,hkContainerHeapAllocator> *v31; // rdi
  int v32; // eax
  __int64 v33; // r14
  int v34; // eax
  __int64 v35; // r8
  __int64 v36; // r9
  __int16 v37; // cx
  char *v38; // rdi
  int v39; // eax
  unsigned int m_slotID; // ecx
  signed int v41; // ebx
  hkLifoAllocator *v42; // rax
  int v43; // r8d
  char *array; // [rsp+30h] [rbp-28h] BYREF
  int v45; // [rsp+38h] [rbp-20h]
  int v46; // [rsp+3Ch] [rbp-1Ch]
  void *p; // [rsp+40h] [rbp-18h]
  int v48; // [rsp+48h] [rbp-10h]
  hkResult resulta; // [rsp+A0h] [rbp+48h] BYREF

  v5 = endBone;
  v8 = result;
  if ( startBone <= endBone )
  {
    m_size = skeleton->m_bones.m_size;
    array = 0i64;
    v12 = 0;
    v45 = 0;
    v46 = 0x80000000;
    v48 = m_size;
    if ( m_size )
    {
      Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (char *)Value->m_cur;
      v15 = (2 * m_size + 127) & 0xFFFFFF80;
      v16 = &m_cur[v15];
      if ( v15 > Value->m_slabSize || v16 > Value->m_end )
      {
        v17 = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v15);
        v12 = v45;
        array = v17;
      }
      else
      {
        Value->m_cur = v16;
        v12 = v45;
        array = m_cur;
      }
    }
    else
    {
      array = 0i64;
    }
    v18 = skeleton->m_partitions.m_size;
    v19 = m_size | 0x80000000;
    v20 = -1;
    v46 = v19;
    v21 = 0;
    p = array;
    if ( v18 > 0 )
    {
      p_m_startBoneIndex = &skeleton->m_partitions.m_data->m_startBoneIndex;
      do
      {
        v23 = *p_m_startBoneIndex;
        v24 = v23 + p_m_startBoneIndex[1];
        p_m_startBoneIndex += 8;
        if ( v5 < v24 && v23 <= v5 )
          v20 = v21;
        ++v21;
        --v18;
      }
      while ( v18 );
      v8 = result;
    }
    v25 = v20;
    while ( 1 )
    {
      v28 = __OFSUB__(v5, -1);
      v26 = v5 == -1;
      v27 = (__int16)(v5 + 1) < 0;
      if ( v5 <= -1 )
        break;
      if ( v5 == startBone )
        goto LABEL_24;
      if ( v25 != -1
        && (v5 >= skeleton->m_partitions.m_data[v25].m_startBoneIndex + skeleton->m_partitions.m_data[v25].m_numBones
         || skeleton->m_partitions.m_data[v25].m_startBoneIndex > v5) )
      {
        v5 = -1;
LABEL_24:
        v28 = __OFSUB__(v5, -1);
        v26 = v5 == -1;
        v27 = (__int16)(v5 + 1) < 0;
        break;
      }
      if ( v12 == (v19 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 2);
        v12 = v45;
      }
      *(_WORD *)&array[2 * v12] = v5;
      m_data = skeleton->m_parentIndices.m_data;
      v19 = v46;
      v12 = ++v45;
      v5 = m_data[v5];
    }
    v30 = !(v27 ^ v28 | v26);
    if ( !(v27 ^ v28 | v26) )
    {
      if ( v12 == (v19 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 2);
        v12 = v45;
      }
      v31 = bonesOut;
      *(_WORD *)&array[2 * v12] = startBone;
      v12 = v45 + 1;
      v32 = v31->m_capacityAndFlags & 0x3FFFFFFF;
      v45 = v12;
      v33 = v12;
      if ( v32 < v12 )
      {
        v34 = 2 * v32;
        if ( v12 < v34 )
          v12 = v34;
        hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, v31, v12, 2);
        v12 = v45;
      }
      v31->m_size = v33;
      v35 = 0i64;
      if ( (int)v33 > 0 )
      {
        v36 = 2 * v33;
        do
        {
          ++v35;
          v37 = *(_WORD *)&array[v36 - 2];
          v36 -= 2i64;
          v31->m_data[v35 - 1] = v37;
        }
        while ( v35 < v33 );
        v12 = v45;
      }
    }
    v38 = (char *)p;
    v39 = v48;
    m_slotID = hkMemoryRouter::s_memoryRouter.m_slotID;
    v26 = p == array;
    v8->m_bool = v30;
    if ( v26 )
      v12 = 0;
    v41 = (2 * v39 + 127) & 0xFFFFFF80;
    v45 = v12;
    v42 = (hkLifoAllocator *)TlsGetValue(m_slotID);
    v43 = (v41 + 15) & 0xFFFFFFF0;
    if ( v41 > v42->m_slabSize || &v38[v43] != v42->m_cur || v42->m_firstNonLifoEnd == v38 )
      hkLifoAllocator::slowBlockFree(v42, v38, v43);
    else
      v42->m_cur = v38;
    v45 = 0;
    if ( v46 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        array,
        2 * (v46 & 0x3FFFFFFF));
    return v8;
  }
  else
  {
    v9 = bonesOut;
    result->m_bool = 0;
    v9->m_size = 0;
    return result;
  }
}

// File Line: 294
// RVA: 0xB1F280
__int64 __fastcall hkaSkeletonUtils::findBoneWithName(
        hkaSkeleton *skeleton,
        const char *name,
        int (__fastcall *compare)(const char *, const char *))
{
  int m_size; // edi
  int (__fastcall *v4)(const char *, const char *); // rsi
  unsigned __int16 v7; // bx

  m_size = skeleton->m_bones.m_size;
  v4 = compare;
  if ( !compare )
    v4 = hkString::strCasecmp;
  v7 = 0;
  if ( m_size <= 0 )
    return 0xFFFFFFFFi64;
  while ( v4(
            name,
            (const char *)((unsigned __int64)skeleton->m_bones.m_data[(__int16)v7].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64)) )
  {
    if ( (__int16)++v7 >= m_size )
      return 0xFFFFFFFFi64;
  }
  return v7;
}

// File Line: 316
// RVA: 0xB1F370
void __fastcall hkaSkeletonUtils::unlockTranslations(hkaSkeleton *skeleton)
{
  __int64 m_size; // r8
  __int64 v2; // rax

  m_size = skeleton->m_bones.m_size;
  if ( m_size > 0 )
  {
    v2 = 0i64;
    do
    {
      skeleton->m_bones.m_data[v2++].m_lockTranslation.m_bool = 0;
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 330
// RVA: 0xB1F950
void __fastcall hkaSkeletonUtils::getDescendants(
        hkaSkeleton *skeleton,
        __int16 startBone,
        hkArray<short,hkContainerHeapAllocator> *bonesOut,
        bool includeStart)
{
  int m_size; // edi
  int v6; // edx
  hkLifoAllocator *Value; // rax
  char *m_cur; // rcx
  int v12; // edx
  char *v13; // r8
  char *v14; // rax
  int v15; // r15d
  int v16; // edi
  int v17; // r9d
  int v18; // eax
  char *v19; // rdi
  unsigned __int64 v20; // rdx
  __int64 v21; // rax
  __int16 v22; // si
  char *i; // rcx
  __int16 v24; // dx
  int v25; // eax
  char *v26; // rbx
  signed int v27; // edi
  hkLifoAllocator *v28; // rax
  int v29; // r8d
  char *array; // [rsp+30h] [rbp-20h] BYREF
  int v31; // [rsp+38h] [rbp-18h]
  int v32; // [rsp+3Ch] [rbp-14h]
  void *p; // [rsp+40h] [rbp-10h]
  int v34; // [rsp+48h] [rbp-8h]
  hkResult result; // [rsp+98h] [rbp+48h] BYREF

  m_size = skeleton->m_bones.m_size;
  v6 = 0;
  array = 0i64;
  v32 = 0x80000000;
  v31 = 0;
  v34 = m_size;
  if ( m_size )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)Value->m_cur;
    v12 = (m_size + 127) & 0xFFFFFF80;
    v13 = &m_cur[v12];
    if ( v12 > Value->m_slabSize || v13 > Value->m_end )
    {
      v14 = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v12);
      v6 = v31;
      m_cur = v14;
    }
    else
    {
      Value->m_cur = v13;
      v6 = v31;
    }
  }
  else
  {
    m_cur = 0i64;
  }
  v15 = skeleton->m_bones.m_size;
  array = m_cur;
  v32 = m_size | 0x80000000;
  v16 = m_size & 0x3FFFFFFF;
  p = m_cur;
  if ( v16 < v15 )
  {
    v17 = v15;
    if ( v15 < 2 * v16 )
      v17 = 2 * v16;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array, v17, 1);
    v6 = v31;
    m_cur = array;
  }
  v18 = v15 - v6;
  v19 = &m_cur[v6];
  v20 = v15 - v6;
  if ( v18 > 0 )
  {
    memset(v19, 0, v20);
    m_cur = array;
  }
  v31 = v15;
  if ( includeStart )
  {
    if ( bonesOut->m_size == (bonesOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, bonesOut, 2);
    bonesOut->m_data[bonesOut->m_size++] = startBone;
    m_cur = array;
  }
  v21 = startBone;
  v22 = startBone + 1;
  m_cur[v21] = 1;
  for ( i = array; v22 < skeleton->m_bones.m_size; ++v22 )
  {
    v24 = skeleton->m_parentIndices.m_data[v22];
    if ( v24 != -1 && i[v24] )
    {
      i[v22] = 1;
      if ( bonesOut->m_size == (bonesOut->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, bonesOut, 2);
      bonesOut->m_data[bonesOut->m_size++] = v22;
      i = array;
    }
  }
  v25 = v31;
  v26 = (char *)p;
  if ( p == i )
    v25 = 0;
  v27 = (v34 + 127) & 0xFFFFFF80;
  v31 = v25;
  v28 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v29 = (v27 + 15) & 0xFFFFFFF0;
  if ( v27 > v28->m_slabSize || &v26[v29] != v28->m_cur || v28->m_firstNonLifoEnd == v26 )
    hkLifoAllocator::slowBlockFree(v28, v26, v29);
  else
    v28->m_cur = v26;
  v31 = 0;
  if ( v32 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, v32 & 0x3FFFFFFF);
}

// File Line: 352
// RVA: 0xB1FBB0
void __fastcall hkaSkeletonUtils::getAncestors(
        hkaSkeleton *skeleton,
        __int16 startBone,
        hkArray<short,hkContainerHeapAllocator> *bonesOut)
{
  __int16 i; // di

  for ( i = skeleton->m_parentIndices.m_data[startBone]; i != -1; i = skeleton->m_parentIndices.m_data[i] )
  {
    if ( bonesOut->m_size == (bonesOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, bonesOut, 2);
    bonesOut->m_data[bonesOut->m_size++] = i;
  }
}

// File Line: 364
// RVA: 0xB1FC40
void __fastcall hkaSkeletonUtils::markDescendants(hkaSkeleton *skeleton, int startBone, bool *out, bool includeStart)
{
  __int64 v5; // r11
  int v6; // edx
  bool *v7; // rcx
  __int64 v8; // rdi
  __int16 v9; // ax
  bool v10; // al

  v5 = startBone;
  if ( startBone > 0 )
    memset(out, 0, startBone);
  v6 = startBone + 1;
  out[v5] = 1;
  if ( v6 < skeleton->m_bones.m_size )
  {
    v7 = &out[v6];
    v8 = v6;
    do
    {
      v9 = skeleton->m_parentIndices.m_data[v8];
      v10 = v9 >= 0 && out[v9];
      *v7 = v10;
      ++v6;
      ++v8;
      ++v7;
    }
    while ( v6 < skeleton->m_bones.m_size );
  }
  out[v5] = includeStart;
}

// File Line: 389
// RVA: 0xB1FCD0
void __fastcall hkaSkeletonUtils::getLeaves(hkaSkeleton *skeleton, hkArray<short,hkContainerHeapAllocator> *leavesOut)
{
  int m_size; // edi
  int v4; // edx
  hkLifoAllocator *Value; // rax
  char *m_cur; // rcx
  int v8; // edx
  char *v9; // r8
  char *v10; // rax
  int v11; // r14d
  int v12; // edi
  int v13; // r9d
  int v14; // eax
  char *v15; // rdi
  unsigned __int64 v16; // rdx
  int v17; // edx
  __int64 v18; // rdi
  __int16 v19; // r8
  __int16 i; // di
  int v21; // eax
  char *v22; // rbx
  signed int v23; // edi
  hkLifoAllocator *v24; // rax
  int v25; // r8d
  char *array; // [rsp+30h] [rbp-20h] BYREF
  int v27; // [rsp+38h] [rbp-18h]
  int v28; // [rsp+3Ch] [rbp-14h]
  void *p; // [rsp+40h] [rbp-10h]
  int v30; // [rsp+48h] [rbp-8h]
  hkResult result; // [rsp+70h] [rbp+20h] BYREF

  m_size = skeleton->m_bones.m_size;
  v4 = 0;
  v28 = 0x80000000;
  array = 0i64;
  v30 = m_size;
  v27 = 0;
  if ( m_size )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)Value->m_cur;
    v8 = (m_size + 127) & 0xFFFFFF80;
    v9 = &m_cur[v8];
    if ( v8 > Value->m_slabSize || v9 > Value->m_end )
    {
      v10 = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v8);
      v4 = v27;
      m_cur = v10;
    }
    else
    {
      Value->m_cur = v9;
      v4 = v27;
    }
  }
  else
  {
    m_cur = 0i64;
  }
  v11 = skeleton->m_bones.m_size;
  array = m_cur;
  v28 = m_size | 0x80000000;
  v12 = m_size & 0x3FFFFFFF;
  p = m_cur;
  if ( v12 < v11 )
  {
    v13 = v11;
    if ( v11 < 2 * v12 )
      v13 = 2 * v12;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array, v13, 1);
    v4 = v27;
    m_cur = array;
  }
  v14 = v11 - v4;
  v15 = &m_cur[v4];
  v16 = v11 - v4;
  if ( v14 > 0 )
  {
    memset(v15, 0, v16);
    m_cur = array;
  }
  v17 = 0;
  v27 = v11;
  if ( skeleton->m_parentIndices.m_size > 0 )
  {
    v18 = 0i64;
    do
    {
      v19 = skeleton->m_parentIndices.m_data[v18];
      if ( v19 != -1 )
      {
        m_cur[v19] = 1;
        m_cur = array;
      }
      ++v17;
      ++v18;
    }
    while ( v17 < skeleton->m_parentIndices.m_size );
  }
  for ( i = 0; i < skeleton->m_bones.m_size; ++i )
  {
    if ( !m_cur[i] )
    {
      if ( leavesOut->m_size == (leavesOut->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, leavesOut, 2);
      leavesOut->m_data[leavesOut->m_size++] = i;
      m_cur = array;
    }
  }
  v21 = v27;
  v22 = (char *)p;
  if ( p == m_cur )
    v21 = 0;
  v23 = (v30 + 127) & 0xFFFFFF80;
  v27 = v21;
  v24 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v25 = (v23 + 15) & 0xFFFFFFF0;
  if ( v23 > v24->m_slabSize || &v22[v25] != v24->m_cur || v24->m_firstNonLifoEnd == v22 )
    hkLifoAllocator::slowBlockFree(v24, v22, v25);
  else
    v24->m_cur = v22;
  v27 = 0;
  if ( v28 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, v28 & 0x3FFFFFFF);
}

// File Line: 455
// RVA: 0xB1E900
void __fastcall hkaSkeletonUtils::blendPoses(
        unsigned int numBones,
        hkQsTransformf *poseA,
        hkQsTransformf *poseB,
        const float *weights,
        hkQsTransformf *poseOut)
{
  signed __int64 v5; // r8
  hkQuaternionf *p_m_rotation; // r10
  signed __int64 v7; // rax
  __int64 v8; // rdx
  __m128 v9; // xmm1
  __m128 m_quad; // xmm3
  __m128 v11; // xmm4
  __m128 v12; // xmm4
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm5
  __m128 v16; // xmm5
  __m128 v17; // xmm2
  __m128 v18; // xmm0
  __m128 v19; // xmm3
  __m128 v20; // xmm1
  __m128 v21; // xmm2

  if ( numBones )
  {
    v5 = (char *)poseB - (char *)poseA;
    p_m_rotation = &poseA->m_rotation;
    v7 = (char *)poseOut - (char *)poseA;
    v8 = numBones;
    do
    {
      v9 = *(__m128 *)((char *)&p_m_rotation[-1].m_vec.m_quad + v5);
      m_quad = p_m_rotation->m_vec.m_quad;
      v11 = (__m128)*(unsigned int *)weights;
      p_m_rotation += 3;
      ++weights;
      v12 = _mm_shuffle_ps(v11, v11, 0);
      *(__m128 *)((char *)&p_m_rotation[-4].m_vec.m_quad + v7) = _mm_add_ps(
                                                                   _mm_mul_ps(
                                                                     _mm_sub_ps(v9, p_m_rotation[-4].m_vec.m_quad),
                                                                     v12),
                                                                   p_m_rotation[-4].m_vec.m_quad);
      v13 = _mm_mul_ps(*(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v5), m_quad);
      v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
      v15 = _mm_sub_ps(
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14), 0x1Fu),
                          0x1Fu),
                *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v5)),
              m_quad);
      *(__m128 *)((char *)&p_m_rotation[-2].m_vec.m_quad + v7) = _mm_add_ps(
                                                                   _mm_mul_ps(
                                                                     _mm_sub_ps(
                                                                       *(__m128 *)((char *)&p_m_rotation[-2].m_vec.m_quad
                                                                                 + v5),
                                                                       p_m_rotation[-2].m_vec.m_quad),
                                                                     v12),
                                                                   p_m_rotation[-2].m_vec.m_quad);
      v16 = _mm_add_ps(_mm_mul_ps(v15, v12), m_quad);
      v17 = _mm_mul_ps(v16, v16);
      v18 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 78), v17);
      v19 = _mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 177), v18), *(__m128 *)&epsilon);
      v20 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 177), v18);
      v21 = _mm_rsqrt_ps(v20);
      *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v7) = _mm_or_ps(
                                                                   _mm_andnot_ps(
                                                                     v19,
                                                                     _mm_mul_ps(
                                                                       v16,
                                                                       _mm_mul_ps(
                                                                         _mm_sub_ps(
                                                                           (__m128)_xmm,
                                                                           _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                                                                         _mm_mul_ps(*(__m128 *)_xmm, v21)))),
                                                                   _mm_and_ps(v19, qi.m_vec.m_quad));
      --v8;
    }
    while ( v8 );
  }
} _mm_and_ps(v19, qi.m_vec.m_quad));
      --v8;
    }
    while ( v8 );
  }

// File Line: 464
// RVA: 0xB1EA50
void __fastcall hkaSkeletonUtils::blendPoses(
        unsigned int numBones,
        hkQsTransformf *poseA,
        hkQsTransformf *poseB,
        const float weight,
        hkQsTransformf *poseOut)
{
  signed __int64 v5; // r8
  signed __int64 v6; // rax
  hkQuaternionf *p_m_rotation; // r9
  __int64 v8; // rdx
  __m128 v9; // xmm5
  __m128 v10; // xmm1
  __m128 m_quad; // xmm3
  __m128 v12; // xmm0
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  __m128 v15; // xmm4
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm2

  if ( numBones )
  {
    v5 = (char *)poseB - (char *)poseA;
    v6 = (char *)poseOut - (char *)poseA;
    p_m_rotation = &poseA->m_rotation;
    v8 = numBones;
    v9 = _mm_shuffle_ps((__m128)LODWORD(weight), (__m128)LODWORD(weight), 0);
    do
    {
      v10 = *(__m128 *)((char *)&p_m_rotation[-1].m_vec.m_quad + v5);
      m_quad = p_m_rotation->m_vec.m_quad;
      p_m_rotation += 3;
      *(__m128 *)((char *)&p_m_rotation[-4].m_vec.m_quad + v6) = _mm_add_ps(
                                                                   _mm_mul_ps(
                                                                     _mm_sub_ps(v10, p_m_rotation[-4].m_vec.m_quad),
                                                                     v9),
                                                                   p_m_rotation[-4].m_vec.m_quad);
      v12 = _mm_mul_ps(*(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v5), m_quad);
      v13 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 78), v12);
      v14 = _mm_sub_ps(
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v13, v13, 177), v13), 0x1Fu),
                          0x1Fu),
                *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v5)),
              m_quad);
      *(__m128 *)((char *)&p_m_rotation[-2].m_vec.m_quad + v6) = _mm_add_ps(
                                                                   _mm_mul_ps(
                                                                     _mm_sub_ps(
                                                                       *(__m128 *)((char *)&p_m_rotation[-2].m_vec.m_quad
                                                                                 + v5),
                                                                       p_m_rotation[-2].m_vec.m_quad),
                                                                     v9),
                                                                   p_m_rotation[-2].m_vec.m_quad);
      v15 = _mm_add_ps(_mm_mul_ps(v14, v9), m_quad);
      v16 = _mm_mul_ps(v15, v15);
      v17 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 78), v16);
      v18 = _mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 177), v17), *(__m128 *)&epsilon);
      v19 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 177), v17);
      v20 = _mm_rsqrt_ps(v19);
      *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v6) = _mm_or_ps(
                                                                   _mm_andnot_ps(
                                                                     v18,
                                                                     _mm_mul_ps(
                                                                       v15,
                                                                       _mm_mul_ps(
                                                                         _mm_sub_ps(
                                                                           (__m128)_xmm,
                                                                           _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                                                                         _mm_mul_ps(*(__m128 *)_xmm, v20)))),
                                                                   _mm_and_ps(v18, qi.m_vec.m_quad));
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 475
// RVA: 0xB1EBA0
void __fastcall hkaSkeletonUtils::blendPosesNoAlias(
        unsigned int numBones,
        hkQsTransformf *poseA,
        hkQsTransformf *poseB,
        const float *weights,
        hkQsTransformf *poseOut)
{
  signed __int64 v5; // r8
  hkQuaternionf *p_m_rotation; // r10
  signed __int64 v7; // rax
  __int64 v8; // rdx
  __m128 m_quad; // xmm3
  __m128 v10; // xmm4
  __m128 v11; // xmm4
  __m128 v12; // xmm1
  __m128 v13; // xmm0
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm5
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  __m128 v20; // xmm3
  __m128 v21; // xmm1
  __m128 v22; // xmm2

  if ( numBones )
  {
    v5 = (char *)poseB - (char *)poseA;
    p_m_rotation = &poseA->m_rotation;
    v7 = (char *)poseOut - (char *)poseA;
    v8 = numBones;
    do
    {
      m_quad = p_m_rotation->m_vec.m_quad;
      v10 = (__m128)*(unsigned int *)weights++;
      v11 = _mm_shuffle_ps(v10, v10, 0);
      v12 = _mm_sub_ps(*(__m128 *)((char *)&p_m_rotation[-1].m_vec.m_quad + v5), p_m_rotation[-1].m_vec.m_quad);
      v13 = *(__m128 *)((char *)&p_m_rotation->m_vec.m_quad + v5);
      p_m_rotation += 3;
      v14 = _mm_mul_ps(v13, m_quad);
      *(__m128 *)((char *)&p_m_rotation[-4].m_vec.m_quad + v7) = _mm_add_ps(
                                                                   _mm_mul_ps(v12, v11),
                                                                   p_m_rotation[-4].m_vec.m_quad);
      v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 78), v14);
      v16 = _mm_sub_ps(
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v15, v15, 177), v15), 0x1Fu),
                          0x1Fu),
                *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v5)),
              m_quad);
      *(__m128 *)((char *)&p_m_rotation[-2].m_vec.m_quad + v7) = _mm_add_ps(
                                                                   _mm_mul_ps(
                                                                     _mm_sub_ps(
                                                                       *(__m128 *)((char *)&p_m_rotation[-2].m_vec.m_quad
                                                                                 + v5),
                                                                       p_m_rotation[-2].m_vec.m_quad),
                                                                     v11),
                                                                   p_m_rotation[-2].m_vec.m_quad);
      v17 = _mm_add_ps(_mm_mul_ps(v16, v11), m_quad);
      v18 = _mm_mul_ps(v17, v17);
      v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
      v20 = _mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19), *(__m128 *)&epsilon);
      v21 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
      v22 = _mm_rsqrt_ps(v21);
      *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v7) = _mm_or_ps(
                                                                   _mm_andnot_ps(
                                                                     v20,
                                                                     _mm_mul_ps(
                                                                       v17,
                                                                       _mm_mul_ps(
                                                                         _mm_sub_ps(
                                                                           (__m128)_xmm,
                                                                           _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                                                                         _mm_mul_ps(*(__m128 *)_xmm, v22)))),
                                                                   _mm_and_ps(v20, qi.m_vec.m_quad));
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 491
// RVA: 0xB1ED00
void __fastcall hkaSkeletonUtils::blendPosesNoAlias(
        unsigned int numBones,
        hkQsTransformf *poseA,
        hkQsTransformf *poseB,
        const float weight,
        hkQsTransformf *poseOut)
{
  signed __int64 v5; // r8
  hkQuaternionf *p_m_rotation; // r9
  signed __int64 v7; // rax
  __int64 v8; // rdx
  __m128 v9; // xmm5
  __m128 m_quad; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm4
  __m128 v16; // xmm4
  __m128 v17; // xmm2
  __m128 v18; // xmm0
  __m128 v19; // xmm3
  __m128 v20; // xmm1
  __m128 v21; // xmm2

  if ( numBones )
  {
    v5 = (char *)poseB - (char *)poseA;
    p_m_rotation = &poseA->m_rotation;
    v7 = (char *)poseOut - (char *)poseA;
    v8 = numBones;
    v9 = _mm_shuffle_ps((__m128)LODWORD(weight), (__m128)LODWORD(weight), 0);
    do
    {
      m_quad = p_m_rotation->m_vec.m_quad;
      v11 = *(__m128 *)((char *)&p_m_rotation[-1].m_vec.m_quad + v5);
      v12 = *(__m128 *)((char *)&p_m_rotation->m_vec.m_quad + v5);
      p_m_rotation += 3;
      v13 = _mm_mul_ps(v12, m_quad);
      *(__m128 *)((char *)&p_m_rotation[-4].m_vec.m_quad + v7) = _mm_add_ps(
                                                                   _mm_mul_ps(
                                                                     _mm_sub_ps(v11, p_m_rotation[-4].m_vec.m_quad),
                                                                     v9),
                                                                   p_m_rotation[-4].m_vec.m_quad);
      v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
      v15 = _mm_sub_ps(
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14), 0x1Fu),
                          0x1Fu),
                *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v5)),
              m_quad);
      *(__m128 *)((char *)&p_m_rotation[-2].m_vec.m_quad + v7) = _mm_add_ps(
                                                                   _mm_mul_ps(
                                                                     _mm_sub_ps(
                                                                       *(__m128 *)((char *)&p_m_rotation[-2].m_vec.m_quad
                                                                                 + v5),
                                                                       p_m_rotation[-2].m_vec.m_quad),
                                                                     v9),
                                                                   p_m_rotation[-2].m_vec.m_quad);
      v16 = _mm_add_ps(_mm_mul_ps(v15, v9), m_quad);
      v17 = _mm_mul_ps(v16, v16);
      v18 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 78), v17);
      v19 = _mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 177), v18), *(__m128 *)&epsilon);
      v20 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 177), v18);
      v21 = _mm_rsqrt_ps(v20);
      *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v7) = _mm_or_ps(
                                                                   _mm_andnot_ps(
                                                                     v19,
                                                                     _mm_mul_ps(
                                                                       v16,
                                                                       _mm_mul_ps(
                                                                         _mm_sub_ps(
                                                                           (__m128)_xmm,
                                                                           _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                                                                         _mm_mul_ps(*(__m128 *)_xmm, v21)))),
                                                                   _mm_and_ps(v19, qi.m_vec.m_quad));
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 505
// RVA: 0xB1EE60
void __fastcall hkaSkeletonUtils::blendPartialPoses(
        unsigned int numBones,
        __int16 *bones,
        hkQsTransformf *poseA,
        hkQsTransformf *poseB,
        unsigned int weight,
        hkQsTransformf *poseOut)
{
  __m128 v7; // xmm5
  __int64 v8; // r11
  __int64 v9; // rax
  __int64 v10; // rcx
  hkQuaternionf v11; // xmm3
  __m128 v12; // xmm0
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  __m128 v15; // xmm4
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm2

  v7 = _mm_shuffle_ps((__m128)weight, (__m128)weight, 0);
  if ( numBones )
  {
    v8 = numBones;
    do
    {
      v9 = *bones++;
      v10 = v9;
      v11.m_vec.m_quad = (__m128)poseA[v9].m_rotation;
      v12 = _mm_mul_ps(v11.m_vec.m_quad, poseB[v9].m_rotation.m_vec.m_quad);
      poseOut[v10].m_translation.m_quad = _mm_add_ps(
                                            _mm_mul_ps(
                                              _mm_sub_ps(poseB[v9].m_translation.m_quad, poseA[v9].m_translation.m_quad),
                                              v7),
                                            poseA[v9].m_translation.m_quad);
      v13 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 78), v12);
      v14 = _mm_sub_ps(
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v13, v13, 177), v13), 0x1Fu),
                          0x1Fu),
                poseB[v9].m_rotation.m_vec.m_quad),
              v11.m_vec.m_quad);
      poseOut[v10].m_scale.m_quad = _mm_add_ps(
                                      _mm_mul_ps(_mm_sub_ps(poseB[v9].m_scale.m_quad, poseA[v9].m_scale.m_quad), v7),
                                      poseA[v9].m_scale.m_quad);
      v15 = _mm_add_ps(_mm_mul_ps(v14, v7), v11.m_vec.m_quad);
      v16 = _mm_mul_ps(v15, v15);
      v17 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 78), v16);
      v18 = _mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 177), v17), *(__m128 *)&epsilon);
      v19 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 177), v17);
      v20 = _mm_rsqrt_ps(v19);
      poseOut[v10].m_rotation.m_vec.m_quad = _mm_or_ps(
                                               _mm_andnot_ps(
                                                 v18,
                                                 _mm_mul_ps(
                                                   v15,
                                                   _mm_mul_ps(
                                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                                                     _mm_mul_ps(*(__m128 *)_xmm, v20)))),
                                               _mm_and_ps(v18, qi.m_vec.m_quad));
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 520
// RVA: 0xB1FEF0
hkBool *__fastcall hkaSkeletonUtils::isBindingOk(hkBool *result, hkaSkeleton *skeleton, hkaAnimationBinding *binding)
{
  __int64 m_size; // r10
  __int64 v4; // r9
  __int16 *m_data; // r8

  m_size = binding->m_transformTrackToBoneIndices.m_size;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_6:
    result->m_bool = 1;
    return result;
  }
  else
  {
    m_data = binding->m_transformTrackToBoneIndices.m_data;
    while ( *m_data >= 0 && *m_data < skeleton->m_bones.m_size )
    {
      ++v4;
      ++m_data;
      if ( v4 >= m_size )
        goto LABEL_6;
    }
    result->m_bool = 0;
    return result;
  }
}

// File Line: 534
// RVA: 0xB1FF30
void __fastcall hkaSkeletonUtils::getModelSpaceScale(
        hkaSkeleton *skeleton,
        hkQsTransformf *poseLocal,
        int boneId,
        hkVector4f *scaleOut)
{
  __m128 m_quad; // xmm0
  __int16 *m_data; // r10
  __int64 v6; // rcx

  m_quad = query.m_quad;
  if ( boneId != -1 )
  {
    m_data = skeleton->m_parentIndices.m_data;
    do
    {
      v6 = boneId;
      boneId = m_data[boneId];
      m_quad = _mm_mul_ps(m_quad, poseLocal[v6].m_scale.m_quad);
    }
    while ( boneId != -1 );
  }
  *scaleOut = (hkVector4f)m_quad;
}

// File Line: 546
// RVA: 0xB1FF70
void __fastcall hkaSkeletonUtils::normalizeRotations(hkQsTransformf *transformsInOut, int numTransforms)
{
  int v3; // edx
  unsigned int v4; // r8d
  __int64 v5; // rdx
  __int64 v6; // rax
  hkQuaternionf v7; // xmm6
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  hkQuaternionf v10; // xmm0
  __m128 v11; // xmm5
  __m128 v12; // xmm0
  __m128 v13; // xmm4
  __m128 v14; // xmm5
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  hkQuaternionf *p_m_rotation; // rax
  __int64 v22; // rcx
  __m128 m_quad; // xmm3
  __m128 v24; // xmm0
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  __m128 v27; // xmm2

  v3 = (numTransforms >> 31) & 3;
  v4 = (v3 + numTransforms) >> 2;
  v5 = ((v3 + numTransforms) & 3u) - v3;
  if ( v4 )
  {
    v6 = v4;
    do
    {
      v7.m_vec.m_quad = (__m128)transformsInOut->m_rotation;
      v8 = _mm_mul_ps(transformsInOut[1].m_rotation.m_vec.m_quad, transformsInOut[1].m_rotation.m_vec.m_quad);
      v9 = _mm_mul_ps(transformsInOut[2].m_rotation.m_vec.m_quad, transformsInOut[2].m_rotation.m_vec.m_quad);
      v10.m_vec.m_quad = (__m128)transformsInOut[3].m_rotation;
      transformsInOut += 4;
      v11 = _mm_mul_ps(v7.m_vec.m_quad, v7.m_vec.m_quad);
      v12 = _mm_mul_ps(v10.m_vec.m_quad, v10.m_vec.m_quad);
      v13 = _mm_shuffle_ps(v11, v8, 68);
      v14 = _mm_shuffle_ps(v11, v8, 238);
      v15 = v9;
      v16 = _mm_shuffle_ps(v9, v12, 238);
      v17 = _mm_shuffle_ps(v15, v12, 68);
      v18 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v14, v16, 221), _mm_shuffle_ps(v14, v16, 136)),
              _mm_add_ps(_mm_shuffle_ps(v13, v17, 221), _mm_shuffle_ps(v13, v17, 136)));
      v19 = _mm_rsqrt_ps(v18);
      v20 = _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v19), v19)),
              _mm_mul_ps(*(__m128 *)_xmm, v19));
      transformsInOut[-4].m_rotation.m_vec.m_quad = _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v7.m_vec.m_quad);
      transformsInOut[-3].m_rotation.m_vec.m_quad = _mm_mul_ps(
                                                      _mm_shuffle_ps(v20, v20, 85),
                                                      transformsInOut[-3].m_rotation.m_vec.m_quad);
      transformsInOut[-2].m_rotation.m_vec.m_quad = _mm_mul_ps(
                                                      _mm_shuffle_ps(v20, v20, 170),
                                                      transformsInOut[-2].m_rotation.m_vec.m_quad);
      transformsInOut[-1].m_rotation.m_vec.m_quad = _mm_mul_ps(
                                                      _mm_shuffle_ps(v20, v20, 255),
                                                      transformsInOut[-1].m_rotation.m_vec.m_quad);
      --v6;
    }
    while ( v6 );
  }
  if ( (_DWORD)v5 )
  {
    p_m_rotation = &transformsInOut->m_rotation;
    v22 = v5;
    do
    {
      m_quad = p_m_rotation->m_vec.m_quad;
      p_m_rotation += 3;
      v24 = _mm_mul_ps(m_quad, m_quad);
      v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 78), v24);
      v26 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 177), v25);
      v27 = _mm_rsqrt_ps(v26);
      p_m_rotation[-3].m_vec.m_quad = _mm_mul_ps(
                                        m_quad,
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v27)));
      --v22;
    }
    while ( v22 );
  }
}

// File Line: 577
// RVA: 0xB20110
hkResult *__fastcall hkaSkeletonUtils::bindByName(
        hkResult *result,
        hkaSkeleton *skeleton,
        hkaAnimation *anim,
        int (__fastcall *compare)(const char *, const char *),
        hkaAnimationBinding *bindingOut)
{
  hkaAnimation *v6; // r9
  int m_size; // eax
  hkResult *v9; // rdi
  int m_numberOfTransformTracks; // r10d
  hkResult *v11; // rax
  __int64 v12; // rcx
  int v13; // ebx
  __int64 v14; // rdx
  hkaBone *m_data; // rax
  __int64 v16; // rdi
  __int64 v17; // r13
  char v18; // bp
  __int16 v19; // bx
  const char *v20; // r14
  int v21; // r12d
  hkOstream *v22; // rax
  hkOstream *v23; // rax
  hkErrStream v24; // [rsp+20h] [rbp-258h] BYREF
  char buf[512]; // [rsp+40h] [rbp-238h] BYREF
  int bindingOuta; // [rsp+2A0h] [rbp+28h]

  v6 = anim;
  m_size = bindingOut->m_transformTrackToBoneIndices.m_size;
  v9 = result;
  if ( m_size && (m_numberOfTransformTracks = anim->m_numberOfTransformTracks, m_size == m_numberOfTransformTracks) )
  {
    if ( anim->m_annotationTracks.m_size == m_numberOfTransformTracks )
    {
      v12 = skeleton->m_bones.m_size;
      v13 = 0;
      v14 = 0i64;
      if ( (int)v12 <= 0 )
      {
LABEL_9:
        bindingOuta = 0;
        if ( m_numberOfTransformTracks <= 0 )
        {
LABEL_18:
          v9->m_enum = HK_SUCCESS;
          return v9;
        }
        else
        {
          v16 = 0i64;
          v17 = 0i64;
          while ( 1 )
          {
            v18 = 0;
            v19 = 0;
            v20 = (const char *)((unsigned __int64)v6->m_annotationTracks.m_data[v17].m_trackName.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
            if ( (int)v12 <= 0 )
              break;
            do
            {
              if ( !compare(
                      (const char *)((unsigned __int64)skeleton->m_bones.m_data[v19].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                      v20) )
              {
                v18 = 1;
                bindingOut->m_transformTrackToBoneIndices.m_data[v16] = v19;
              }
              LODWORD(v12) = skeleton->m_bones.m_size;
              ++v19;
            }
            while ( v19 < (int)v12 );
            v21 = bindingOuta;
            if ( !v18 )
              break;
            v6 = anim;
            ++v17;
            ++v16;
            ++bindingOuta;
            if ( v21 + 1 >= anim->m_numberOfTransformTracks )
            {
              v9 = result;
              goto LABEL_18;
            }
          }
          hkErrStream::hkErrStream(&v24, buf, 512);
          v23 = hkOstream::operator<<(&v24, "No match for track ");
          hkOstream::operator<<(v23, v20);
          hkError::messageWarning(1699623992, buf, "Rig\\hkaSkeletonUtils.cpp", 620);
          hkOstream::~hkOstream(&v24);
          v11 = result;
          result->m_enum = HK_FAILURE;
        }
      }
      else
      {
        m_data = skeleton->m_bones.m_data;
        while ( ((unsigned __int64)m_data->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64) != 0 )
        {
          ++v14;
          ++v13;
          ++m_data;
          if ( v14 >= v12 )
            goto LABEL_9;
        }
        hkErrStream::hkErrStream(&v24, buf, 512);
        v22 = hkOstream::operator<<(&v24, "No bone name for bone ");
        hkOstream::operator<<(v22, v13);
        hkError::messageWarning(1699623991, buf, "Rig\\hkaSkeletonUtils.cpp", 598);
        hkOstream::~hkOstream(&v24);
        v9->m_enum = HK_FAILURE;
        return v9;
      }
    }
    else
    {
      hkErrStream::hkErrStream(&v24, buf, 512);
      hkOstream::operator<<(&v24, "No track names present in animation");
      hkError::messageWarning(1699623991, buf, "Rig\\hkaSkeletonUtils.cpp", 588);
      hkOstream::~hkOstream(&v24);
      v9->m_enum = HK_FAILURE;
      return v9;
    }
  }
  else
  {
    hkErrStream::hkErrStream(&v24, buf, 512);
    hkOstream::operator<<(&v24, "Binding is not initiialized");
    hkError::messageWarning(1699623989, buf, "Rig\\hkaSkeletonUtils.cpp", 581);
    hkOstream::~hkOstream(&v24);
    v9->m_enum = HK_FAILURE;
    return v9;
  }
  return v11;
}

// File Line: 629
// RVA: 0xB20460
void __fastcall hkaSkeletonUtils::calcAabb(
        int numBones,
        hkQsTransformf *poseLocal,
        const __int16 *parentIndices,
        hkQsTransformf *worldFromModel,
        hkAabb *aabbOut)
{
  hkAabb *v5; // rbx
  hkQsTransformf *v6; // rax
  __int64 v10; // rdi
  int v11; // r9d
  hkQsTransformf *v12; // rdx
  __m128 m_quad; // xmm1
  __int64 v14; // rax
  __int64 v15; // rcx
  hkQsTransformf *v16; // [rsp+30h] [rbp-28h] BYREF
  int v17; // [rsp+38h] [rbp-20h]
  int v18; // [rsp+3Ch] [rbp-1Ch]
  hkResult v19; // [rsp+60h] [rbp+8h] BYREF

  v5 = aabbOut;
  v17 = 0;
  v6 = 0i64;
  aabbOut->m_min = (hkVector4f)xmmword_141A712A0;
  v16 = 0i64;
  v10 = (unsigned int)numBones;
  v18 = 0x80000000;
  v5->m_max.m_quad = _mm_xor_ps(
                       (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                       v5->m_min.m_quad);
  if ( numBones > 0 )
  {
    v11 = numBones;
    hkArrayUtil::_reserve(&v19, &hkContainerHeapAllocator::s_alloc, &v16, v11, 48);
    v6 = v16;
  }
  v17 = v10;
  hkaSkeletonUtils::transformLocalPoseToWorldPose(v10, parentIndices, worldFromModel, poseLocal, v6);
  v12 = v16;
  if ( (_DWORD)v10 )
  {
    m_quad = v5->m_max.m_quad;
    v14 = (__int64)v16;
    v15 = v10;
    do
    {
      v14 += 48i64;
      v5->m_min.m_quad = _mm_min_ps(v5->m_min.m_quad, *(__m128 *)(v14 - 48));
      m_quad = _mm_max_ps(m_quad, *(__m128 *)(v14 - 48));
      v5->m_max.m_quad = m_quad;
      --v15;
    }
    while ( v15 );
  }
  v17 = 0;
  if ( v18 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v12, 48 * (v18 & 0x3FFFFFFF));
}

// File Line: 646
// RVA: 0xB20590
hkBool *__fastcall hkaSkeletonUtils::hasValidPartitions(hkBool *result, hkaSkeleton *skeleton)
{
  int v5; // r8d
  int m_size; // r10d
  unsigned int *m_storage; // r9
  char m_numBits; // al
  int m_capacityAndFlags; // edx
  int v10; // esi
  __int64 v11; // r14
  hkaSkeleton::Partition *m_data; // rax
  int m_startBoneIndex; // ecx
  int v14; // r9d
  char v15; // dl
  int v16; // r11d
  int v17; // r10d
  int v18; // r9d
  int v19; // r9d
  _DWORD *v20; // rdi
  __int64 i; // rcx
  int v22; // r8d
  unsigned int *v23; // r9
  __int64 v24; // rcx
  int v25; // eax
  int v26; // edx
  __int64 v27; // rcx
  unsigned int *v28; // rdx
  __int64 v29; // rax
  int v30; // ecx
  __int64 *v31; // rdi
  __int64 j; // rcx
  char v33; // cl
  int v34; // eax
  int v35; // r11d
  __int64 v36; // r10
  int v37; // ebx
  __m128i si128; // xmm2
  __m128i v39; // xmm3
  __m128i v40; // xmm4
  unsigned int v41; // ecx
  __m128i v42; // xmm1
  __m128i v43; // xmm0
  __m128i v44; // xmm0
  __m128i v45; // xmm1
  bool v46; // zf
  __int64 v47; // r8
  int v48; // r8d
  int v49; // [rsp+2Ch] [rbp-6Dh]
  __int64 v50[4]; // [rsp+30h] [rbp-69h] BYREF
  int v51; // [rsp+50h] [rbp-49h]
  hkBitFieldStorage<hkInplaceArray<unsigned int,8,hkContainerHeapAllocator> > v52; // [rsp+58h] [rbp-41h] BYREF
  hkBitFieldStorage<hkInplaceArray<unsigned int,8,hkContainerHeapAllocator> > __that; // [rsp+90h] [rbp-9h] BYREF

  if ( !skeleton->m_partitions.m_size )
  {
    result->m_bool = 1;
    return result;
  }
  v5 = -2147483640;
  m_size = 8;
  m_storage = v52.m_words.m_storage;
  __that.m_words.m_data = __that.m_words.m_storage;
  m_numBits = 0;
  m_capacityAndFlags = -2147483640;
  __that.m_numBits = 256;
  v51 = 256;
  v52.m_numBits = 256;
  __that.m_words.m_capacityAndFlags = -2147483640;
  __that.m_words.m_size = 8;
  memset(__that.m_words.m_storage, 0, sizeof(__that.m_words.m_storage));
  v49 = -2147483640;
  memset(v50, 0, sizeof(v50));
  v52.m_words.m_data = v52.m_words.m_storage;
  v52.m_words.m_capacityAndFlags = -2147483640;
  v52.m_words.m_size = 8;
  memset(v52.m_words.m_storage, 0, sizeof(v52.m_words.m_storage));
  v10 = 0;
  if ( skeleton->m_partitions.m_size <= 0 )
  {
LABEL_27:
    v33 = m_numBits - 1;
    v34 = m_size - 1;
    v35 = 0;
    v36 = m_size - 1;
    v37 = (2 * ~(-1 << (v33 & 0x1F))) | 1;
    if ( v34 >= 0 )
    {
      si128 = _mm_load_si128((const __m128i *)&_xmm);
      v39 = _mm_load_si128((const __m128i *)&_xmm);
      v40 = _mm_load_si128((const __m128i *)&_xmm);
      do
      {
        v41 = v37 & __that.m_words.m_data[v36];
        v37 = -1;
        v42 = _mm_cvtsi32_si128(v41);
        v43 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v42, 1u), si128), _mm_and_si128(v42, si128));
        v44 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v43, 2u), v39), _mm_and_si128(v43, v39));
        v45 = _mm_sad_epu8(_mm_and_si128(_mm_add_epi8(_mm_srli_epi16(v44, 4u), v44), v40), (__m128i)0i64);
        v35 += _mm_cvtsi128_si32(_mm_add_epi32(_mm_shuffle_epi32(v45, 78), v45));
        --v36;
      }
      while ( v36 >= 0 );
    }
    v46 = v35 == skeleton->m_bones.m_size;
    v52.m_words.m_size = 0;
    result->m_bool = v46;
    if ( m_capacityAndFlags < 0 )
      goto LABEL_34;
    v47 = (unsigned int)(4 * m_capacityAndFlags);
  }
  else
  {
    v11 = 0i64;
    while ( 1 )
    {
      m_data = skeleton->m_partitions.m_data;
      m_startBoneIndex = m_data[v11].m_startBoneIndex;
      v14 = m_startBoneIndex + m_data[v11].m_numBones;
      v15 = v14 & 0x1F;
      v16 = -1 << (m_startBoneIndex & 0x1F);
      v17 = m_startBoneIndex >> 5;
      v18 = v14 >> 5;
      if ( m_startBoneIndex >> 5 == v18 )
      {
        v22 = v16 & ~(-1 << v15);
        if ( v22 )
          *((_DWORD *)v50 + v17) = v22 | *((_DWORD *)v50 + v17) & ~v22;
      }
      else
      {
        *((_DWORD *)v50 + v17) = v16 | *((_DWORD *)v50 + v17) & ~v16;
        if ( -1 << v15 != -1 )
          *((_DWORD *)v50 + v18) = ~(-1 << v15) | *((_DWORD *)v50 + v18) & (-1 << v15);
        v19 = v18 - v17 - 2;
        v20 = (_DWORD *)v50 + v17 + 1;
        if ( v19 >= 0 )
        {
          for ( i = (unsigned int)(v19 + 1); i; --i )
            *v20++ = -1;
        }
      }
      hkBitFieldStorage<hkInplaceArray<unsigned int,8,hkContainerHeapAllocator>>::operator=(&v52, &__that);
      v23 = v52.m_words.m_data;
      v24 = 8i64;
      do
      {
        v25 = *((_DWORD *)v50 + --v24);
        v23[v24] &= v25;
      }
      while ( v24 );
      m_storage = v52.m_words.m_data;
      v26 = (2 * ~(-1 << ((LOBYTE(v52.m_numBits) - 1) & 0x1F))) | 1;
      v27 = v52.m_words.m_size - 1;
      if ( v52.m_words.m_size - 1 >= 0 )
        break;
LABEL_20:
      v28 = __that.m_words.m_data;
      v29 = 8i64;
      do
      {
        v30 = *((_DWORD *)v50 + --v29);
        v28[v29] |= v30;
      }
      while ( v29 );
      v31 = v50;
      for ( j = 8i64; j; --j )
      {
        *(_DWORD *)v31 = 0;
        v31 = (__int64 *)((char *)v31 + 4);
      }
      m_storage = v52.m_words.m_data;
      ++v10;
      ++v11;
      if ( v10 >= skeleton->m_partitions.m_size )
      {
        m_numBits = __that.m_numBits;
        m_size = __that.m_words.m_size;
        v5 = v49;
        m_capacityAndFlags = v52.m_words.m_capacityAndFlags;
        goto LABEL_27;
      }
    }
    while ( (v26 & v52.m_words.m_data[v27]) == 0 )
    {
      --v27;
      v26 = -1;
      if ( v27 < 0 )
        goto LABEL_20;
    }
    v48 = v52.m_words.m_capacityAndFlags;
    result->m_bool = 0;
    v52.m_words.m_size = 0;
    if ( v48 < 0 )
      goto LABEL_33;
    v47 = (unsigned int)(4 * v48);
  }
  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, m_storage, v47);
LABEL_33:
  v5 = v49;
LABEL_34:
  v52.m_words.m_capacityAndFlags = 0x80000000;
  v52.m_words.m_data = 0i64;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v50, 4 * v5);
  __that.m_words.m_size = 0;
  v49 = 0x80000000;
  if ( __that.m_words.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      __that.m_words.m_data,
      4 * __that.m_words.m_capacityAndFlags);
  return result;
}


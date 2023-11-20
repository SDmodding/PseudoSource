// File Line: 21
// RVA: 0xB1E520
void __fastcall hkaSkeletonUtils::transformLocalPoseToWorldPose(int numTransforms, const __int16 *parentIndices, hkQsTransformf *worldFromModel, hkQsTransformf *poseLocal, hkQsTransformf *poseWorldOut)
{
  signed __int64 v5; // r10
  hkQuaternionf *v6; // rbx
  signed __int64 v7; // r11
  __int64 v8; // rax
  hkQsTransformf *v9; // rax
  __m128 v10; // xmm2
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
    v6 = &poseLocal->m_rotation;
    v7 = (char *)poseWorldOut - (char *)poseLocal;
    do
    {
      v8 = parentIndices[v5];
      if ( (_DWORD)v8 == -1 )
        v9 = worldFromModel;
      else
        v9 = &poseWorldOut[v8];
      v10 = v9->m_rotation.m_vec.m_quad;
      v11 = v6[-1].m_vec.m_quad;
      ++v5;
      v6 += 3;
      v12 = _mm_mul_ps(v11, v10);
      v13 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v10), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v11));
      v14 = _mm_shuffle_ps(v9->m_rotation.m_vec.m_quad, v10, 255);
      v15 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                _mm_shuffle_ps(v12, v12, 170)),
              v10);
      v16 = v6[-3].m_vec.m_quad;
      v17 = _mm_add_ps(
              _mm_add_ps(v15, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v14, v14), (__m128)xmmword_141A711B0), v11)),
              _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v14));
      v18 = _mm_shuffle_ps(v6[-3].m_vec.m_quad, v6[-3].m_vec.m_quad, 255);
      *(__m128 *)((char *)&v6[-4].m_vec.m_quad + v7) = _mm_add_ps(_mm_add_ps(v17, v17), v9->m_translation.m_quad);
      v19 = v9->m_rotation.m_vec.m_quad;
      v20 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v19);
      v21 = _mm_shuffle_ps(v9->m_rotation.m_vec.m_quad, v9->m_rotation.m_vec.m_quad, 255);
      v22 = _mm_mul_ps(_mm_shuffle_ps(v9->m_rotation.m_vec.m_quad, v19, 201), v16);
      v23 = _mm_mul_ps(v19, v16);
      v24 = _mm_sub_ps(v20, v22);
      v25 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v24, v24, 201), _mm_mul_ps(v21, v16)),
              _mm_mul_ps(v9->m_rotation.m_vec.m_quad, v18));
      v26 = v6[-2].m_vec.m_quad;
      *(__m128 *)((char *)&v6[-3].m_vec.m_quad + v7) = _mm_shuffle_ps(
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
      *(__m128 *)((char *)&v6[-2].m_vec.m_quad + v7) = _mm_mul_ps(v26, v9->m_scale.m_quad);
    }
    while ( v5 < numTransforms );
  }
}

// File Line: 33
// RVA: 0xB1DFC0
void __fastcall hkaSkeletonUtils::transformLocalBoneToModelBone(int boneIndex, const __int16 *parentIndices, hkQsTransformf *poseLocal, hkQsTransformf *boneModelOut)
{
  hkQuaternionf v4; // xmm1
  __m128 v5; // xmm8
  int v6; // eax
  hkQuaternionf v7; // xmm7
  __m128 v8; // xmm7
  __int64 v9; // rcx
  __int64 v10; // rax
  hkQuaternionf v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm6
  __m128 v14; // xmm5
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  hkQuaternionf v17; // xmm2
  hkQuaternionf v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm5
  __m128 v21; // xmm7
  __m128 v22; // xmm0
  __m128 v23; // xmm4
  __m128 v24; // xmm7

  boneModelOut->m_translation = poseLocal[boneIndex].m_translation;
  v4.m_vec.m_quad = (__m128)poseLocal[boneIndex].m_rotation;
  boneModelOut->m_rotation = (hkQuaternionf)v4.m_vec.m_quad;
  v5 = poseLocal[boneIndex].m_scale.m_quad;
  boneModelOut->m_scale.m_quad = v5;
  v6 = parentIndices[boneIndex];
  if ( v6 >= 0 )
  {
    v7.m_vec.m_quad = v4.m_vec.m_quad;
    do
    {
      v8 = _mm_shuffle_ps(v7.m_vec.m_quad, v7.m_vec.m_quad, 255);
      v9 = v6;
      v10 = v6;
      v11.m_vec.m_quad = (__m128)poseLocal[v10].m_rotation;
      v12 = _mm_mul_ps(boneModelOut->m_translation.m_quad, v11.m_vec.m_quad);
      v13 = _mm_shuffle_ps(poseLocal[v10].m_rotation.m_vec.m_quad, v11.m_vec.m_quad, 255);
      v14 = _mm_sub_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(boneModelOut->m_translation.m_quad, boneModelOut->m_translation.m_quad, 201),
                v11.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v11.m_vec.m_quad, v11.m_vec.m_quad, 201), boneModelOut->m_translation.m_quad));
      v15 = v8;
      v16 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                    _mm_shuffle_ps(v12, v12, 170)),
                  v11.m_vec.m_quad),
                _mm_mul_ps(
                  _mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0),
                  boneModelOut->m_translation.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v13));
      boneModelOut->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v16, v16), poseLocal[v10].m_translation.m_quad);
      v17.m_vec.m_quad = (__m128)poseLocal[v10].m_rotation;
      v18.m_vec.m_quad = (__m128)boneModelOut->m_rotation;
      v19 = _mm_mul_ps(v8, v17.m_vec.m_quad);
      v20 = _mm_shuffle_ps(poseLocal[v10].m_rotation.m_vec.m_quad, poseLocal[v10].m_rotation.m_vec.m_quad, 255);
      v21 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v18.m_vec.m_quad, v18.m_vec.m_quad, 201), v17.m_vec.m_quad),
              _mm_mul_ps(
                _mm_shuffle_ps(poseLocal[v10].m_rotation.m_vec.m_quad, v17.m_vec.m_quad, 201),
                v18.m_vec.m_quad));
      v22 = _mm_mul_ps(v20, v18.m_vec.m_quad);
      v23 = _mm_mul_ps(v18.m_vec.m_quad, v17.m_vec.m_quad);
      v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 201), v22), v19);
      v7.m_vec.m_quad = _mm_shuffle_ps(
                          v24,
                          _mm_unpackhi_ps(
                            v24,
                            _mm_sub_ps(
                              _mm_mul_ps(v15, v20),
                              _mm_add_ps(
                                _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                                _mm_shuffle_ps(v23, v23, 170)))),
                          196);
      boneModelOut->m_rotation = (hkQuaternionf)v7.m_vec.m_quad;
      v5 = _mm_mul_ps(v5, poseLocal[v10].m_scale.m_quad);
      boneModelOut->m_scale.m_quad = v5;
      v6 = parentIndices[v9];
    }
    while ( v6 >= 0 );
  }
}

// File Line: 49
// RVA: 0xB1DF90
void __fastcall hkaSkeletonUtils::transformLocalPoseToModelPose(int numTransforms, const __int16 *parentIndices, hkQsTransformf *poseLocal, hkQsTransformf *poseModelOut)
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
void __fastcall hkaSkeletonUtils::transformWorldPoseToLocalPose(int numTransforms, const __int16 *parentIndices, hkQsTransformf *worldFromModel, hkQsTransformf *poseWorld, hkQsTransformf *poseLocalOut)
{
  __int64 v5; // rbp
  hkQsTransformf *v6; // rsi
  hkQsTransformf *v7; // r14
  const __int16 *v8; // r15
  __m128i v9; // xmm0
  __int64 v10; // r13
  signed __int64 v11; // r12
  __m128 v12; // xmm10
  __m128 v13; // xmm11
  __int64 v14; // rax
  signed __int64 v15; // rdi
  __m128 v16; // xmm0
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
  __m128 *v34; // [rsp+20h] [rbp-D8h]
  hkVector4f v35; // [rsp+30h] [rbp-C8h]

  if ( numTransforms > 0 )
  {
    v5 = 0i64;
    v6 = poseWorld;
    v7 = worldFromModel;
    v8 = parentIndices;
    v9 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
    v10 = numTransforms;
    v34 = &poseWorld->m_rotation.m_vec.m_quad;
    v11 = (char *)poseLocalOut - (char *)poseWorld;
    v12 = (__m128)_mm_shuffle_epi32(v9, 0);
    v13 = (__m128)_mm_shuffle_epi32(v9, 64);
    do
    {
      v14 = v8[v5];
      if ( (_DWORD)v14 == -1 )
        v15 = (signed __int64)v7;
      else
        v15 = (signed __int64)&v6[v14];
      hkVector4f::setRotatedInverseDir(&v35, (hkQuaternionf *)(v15 + 16), (hkVector4f *)v15);
      v16 = *(__m128 *)(v15 + 32);
      v17 = _mm_xor_ps(v13, *(__m128 *)(v15 + 16));
      v18 = _mm_rcp_ps(v16);
      v19 = v34[-1];
      v20 = _mm_shuffle_ps(v17, v17, 255);
      v21 = _mm_shuffle_ps(v17, v17, 201);
      v22 = (__m128)_mm_srli_si128(
                      _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v16, v18)), v18), 4),
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
      *(__m128 *)((char *)v34 + v11 - 16) = _mm_add_ps(_mm_add_ps(v25, v25), _mm_xor_ps(v12, v35.m_quad));
      v26 = *v34;
      v27 = _mm_shuffle_ps(v26, v26, 255);
      v28 = _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v17);
      v29 = _mm_mul_ps(v17, v27);
      v30 = _mm_mul_ps(v17, *v34);
      v31 = _mm_sub_ps(v28, _mm_mul_ps(v21, *v34));
      v32 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 201), _mm_mul_ps(v20, *v34)), v29);
      v33 = _mm_mul_ps(v34[1], v22);
      *(__m128 *)((char *)v34 + v11) = _mm_shuffle_ps(
                                         v32,
                                         _mm_unpackhi_ps(
                                           v32,
                                           _mm_sub_ps(
                                             _mm_mul_ps(v27, v20),
                                             _mm_add_ps(
                                               _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                                               _mm_shuffle_ps(v30, v30, 170)))),
                                         196);
      *(__m128 *)((char *)v34 + v11 + 16) = v33;
      ++v5;
      v34 += 3;
    }
    while ( v5 < v10 );
  }
}

// File Line: 67
// RVA: 0xB1E140
void __fastcall hkaSkeletonUtils::transformModelPoseToLocalPose(int numTransforms, const __int16 *parentIndices, hkQsTransformf *poseModel, hkQsTransformf *poseLocalOut)
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
void __fastcall hkaSkeletonUtils::transformModelPoseToWorldPose(int numTransforms, hkQsTransformf *worldFromModel, hkQsTransformf *poseModel, hkQsTransformf *poseWorldOut)
{
  __int64 v4; // rax
  hkQuaternionf v5; // xmm5
  hkQuaternionf *v6; // rcx
  signed __int64 v7; // r9
  hkVector4f v8; // xmm10
  hkVector4f v9; // xmm11
  __m128 v10; // xmm8
  __m128 v11; // xmm6
  __m128 v12; // xmm2
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
    v6 = &poseModel->m_rotation;
    v7 = (char *)poseWorldOut - (char *)poseModel;
    v8.m_quad = (__m128)worldFromModel->m_translation;
    v9.m_quad = (__m128)worldFromModel->m_scale;
    v10 = _mm_shuffle_ps(v5.m_vec.m_quad, v5.m_vec.m_quad, 201);
    v11 = _mm_shuffle_ps(v5.m_vec.m_quad, v5.m_vec.m_quad, 255);
    do
    {
      v12 = v6[-1].m_vec.m_quad;
      v6 += 3;
      v13 = _mm_mul_ps(v12, v5.m_vec.m_quad);
      v14 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v5.m_vec.m_quad), _mm_mul_ps(v12, v10));
      v15 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v11, v11), (__m128)xmmword_141A711B0), v12);
      v16 = v6[-3].m_vec.m_quad;
      v17 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                    _mm_shuffle_ps(v13, v13, 170)),
                  v5.m_vec.m_quad),
                v15),
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v11));
      v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v6[-3].m_vec.m_quad, v16, 201), v5.m_vec.m_quad), _mm_mul_ps(v10, v16));
      *(__m128 *)((char *)&v6[-4].m_vec.m_quad + v7) = _mm_add_ps(_mm_add_ps(v17, v17), v8.m_quad);
      v19 = _mm_shuffle_ps(v16, v16, 255);
      v20 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v18, v18, 201), _mm_mul_ps(v11, v16)),
              _mm_mul_ps(v5.m_vec.m_quad, v19));
      v21 = _mm_mul_ps(v5.m_vec.m_quad, v16);
      v22 = _mm_mul_ps(v6[-2].m_vec.m_quad, v9.m_quad);
      *(__m128 *)((char *)&v6[-3].m_vec.m_quad + v7) = _mm_shuffle_ps(
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
      *(__m128 *)((char *)v6 + v7 - 32) = v22;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 81
// RVA: 0xB1E300
void __fastcall hkaSkeletonUtils::transformWorldPoseToModelPose(int numTransforms, hkQsTransformf *worldFromModel, hkQsTransformf *poseWorld, hkQsTransformf *poseModelOut)
{
  hkQsTransformf *v4; // rsi
  __int64 v5; // rdi
  hkQuaternionf *v6; // rbp
  signed __int64 v7; // rbx
  __m128i v8; // xmm0
  __m128 v9; // xmm10
  __m128 v10; // xmm11
  __m128 v11; // xmm3
  __m128 v12; // xmm0
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
  hkVector4f v29; // [rsp+20h] [rbp-A8h]

  if ( numTransforms > 0 )
  {
    v4 = worldFromModel;
    v5 = numTransforms;
    v6 = &poseWorld->m_rotation;
    v7 = (char *)poseModelOut - (char *)poseWorld;
    v8 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
    v9 = (__m128)_mm_shuffle_epi32(v8, 0);
    v10 = (__m128)_mm_shuffle_epi32(v8, 64);
    do
    {
      hkVector4f::setRotatedInverseDir(&v29, &v4->m_rotation, &v4->m_translation);
      v6 += 3;
      v11 = v6[-4].m_vec.m_quad;
      v12 = v4->m_scale.m_quad;
      v13 = _mm_xor_ps(v10, v4->m_rotation.m_vec.m_quad);
      v14 = _mm_rcp_ps(v12);
      v15 = _mm_shuffle_ps(v13, v13, 255);
      v16 = _mm_shuffle_ps(v13, v13, 201);
      v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v13), _mm_mul_ps(v16, v11));
      v18 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v12, v14)), v14), 4);
      v19 = _mm_mul_ps(v13, v11);
      v20 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                    _mm_shuffle_ps(v19, v19, 170)),
                  v13),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v15, v15), (__m128)xmmword_141A711B0), v11)),
              _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v15));
      *(__m128 *)((char *)&v6[-4].m_vec.m_quad + v7) = _mm_add_ps(_mm_add_ps(v20, v20), _mm_xor_ps(v9, v29.m_quad));
      v21 = v6[-3].m_vec.m_quad;
      v22 = _mm_shuffle_ps(v6[-3].m_vec.m_quad, v6[-3].m_vec.m_quad, 255);
      v23 = _mm_mul_ps(_mm_shuffle_ps(v6[-3].m_vec.m_quad, v21, 201), v13);
      v24 = _mm_mul_ps(v13, v22);
      v25 = _mm_mul_ps(v13, v21);
      v26 = _mm_sub_ps(v23, _mm_mul_ps(v16, v21));
      v27 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v26, v26, 201), _mm_mul_ps(v15, v21)), v24);
      v28 = _mm_mul_ps(v6[-2].m_vec.m_quad, (__m128)_mm_srli_si128(v18, 4));
      *(__m128 *)((char *)&v6[-3].m_vec.m_quad + v7) = _mm_shuffle_ps(
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
      *(__m128 *)((char *)v6 + v7 - 32) = v28;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 92
// RVA: 0xB1EFD0
void __fastcall hkaSkeletonUtils::enforceSkeletonConstraintsLocalSpace(hkaSkeleton *skeleton, hkQsTransformf *poseInOut)
{
  __int64 v2; // r9
  __int64 v3; // rax
  __int64 v4; // r8

  v2 = skeleton->m_bones.m_size;
  if ( v2 > 0 )
  {
    v3 = 0i64;
    v4 = 0i64;
    do
    {
      if ( skeleton->m_bones.m_data[v4].m_lockTranslation.m_bool )
        poseInOut[v3].m_translation = skeleton->m_referencePose.m_data[v3].m_translation;
      ++v4;
      ++v3;
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 107
// RVA: 0xB1F140
void __fastcall hkaSkeletonUtils::enforcePoseConstraintsLocalSpace(hkaSkeleton *skeleton, hkQsTransformf *constraintsLocal, hkQsTransformf *poseInOut)
{
  __int64 v3; // r10
  __int64 v4; // r9
  signed __int64 v5; // rdx

  v3 = skeleton->m_bones.m_size;
  if ( v3 > 0 )
  {
    v4 = 0i64;
    v5 = (char *)constraintsLocal - (char *)poseInOut;
    do
    {
      if ( skeleton->m_bones.m_data[v4].m_lockTranslation.m_bool )
        poseInOut->m_translation = *(hkVector4f *)((char *)&poseInOut->m_translation + v5);
      ++v4;
      ++poseInOut;
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 122
// RVA: 0xB1F010
void __fastcall hkaSkeletonUtils::enforceSkeletonConstraintsModelSpace(hkaSkeleton *skeleton, hkQsTransformf *poseModelInOut)
{
  __int64 v2; // rdi
  __int64 v3; // r8
  hkaSkeleton *v4; // r10
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

  v2 = skeleton->m_bones.m_size;
  v3 = 0i64;
  v4 = skeleton;
  if ( v2 > 0 )
  {
    v5 = 0i64;
    v6 = poseModelInOut;
    do
    {
      v7 = v4->m_parentIndices.m_data[v3];
      if ( v4->m_bones.m_data[v5].m_lockTranslation.m_bool )
      {
        v8 = (char *)v4->m_referencePose.m_data - (char *)poseModelInOut;
        if ( v7 == -1 )
        {
          v6->m_translation = *(hkVector4f *)((char *)&v6->m_translation + v8);
        }
        else
        {
          v9 = *(__m128 *)((char *)&v6->m_translation.m_quad + v8);
          v10.m_vec.m_quad = (__m128)poseModelInOut[v7].m_rotation;
          v11 = _mm_mul_ps(poseModelInOut[v7].m_rotation.m_vec.m_quad, v9);
          v12 = _mm_shuffle_ps(poseModelInOut[v7].m_rotation.m_vec.m_quad, v10.m_vec.m_quad, 255);
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
    while ( v3 < v2 );
  }
}

// File Line: 149
// RVA: 0xB1F180
void __fastcall hkaSkeletonUtils::enforcePoseConstraintsModelSpace(hkaSkeleton *skeleton, hkQsTransformf *constraintsLocal, hkQsTransformf *poseModelInOut)
{
  __int64 v3; // rbx
  __int64 v4; // r9
  hkQsTransformf *v5; // rdi
  hkaSkeleton *v6; // r11
  __int64 v7; // r10
  signed __int64 v8; // r8
  __int16 v9; // cx
  __m128 *v10; // rcx
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm6
  __m128 v14; // xmm5
  __m128 v15; // xmm4

  v3 = skeleton->m_bones.m_size;
  v4 = 0i64;
  v5 = poseModelInOut;
  v6 = skeleton;
  if ( v3 > 0 )
  {
    v7 = 0i64;
    v8 = (char *)poseModelInOut - (char *)constraintsLocal;
    do
    {
      v9 = v6->m_parentIndices.m_data[v4];
      if ( v6->m_bones.m_data[v7].m_lockTranslation.m_bool )
      {
        if ( v9 == -1 )
        {
          *(hkVector4f *)((char *)&constraintsLocal->m_translation + v8) = constraintsLocal->m_translation;
        }
        else
        {
          v10 = &v5[v9].m_translation.m_quad;
          v11 = v10[1];
          v12 = _mm_mul_ps(constraintsLocal->m_translation.m_quad, v11);
          v13 = _mm_shuffle_ps(v10[1], v11, 255);
          v14 = _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(constraintsLocal->m_translation.m_quad, constraintsLocal->m_translation.m_quad, 201),
                    v11),
                  _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), constraintsLocal->m_translation.m_quad));
          v15 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                        _mm_shuffle_ps(v12, v12, 170)),
                      v11),
                    _mm_mul_ps(
                      _mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0),
                      constraintsLocal->m_translation.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v13));
          *(__m128 *)((char *)&constraintsLocal->m_translation.m_quad + v8) = _mm_add_ps(_mm_add_ps(v15, v15), *v10);
        }
      }
      ++v4;
      ++v7;
      ++constraintsLocal;
    }
    while ( v4 < v3 );
  }
}

// File Line: 179
// RVA: 0xB1F310
void __fastcall hkaSkeletonUtils::lockTranslations(hkaSkeleton *skeleton, hkBool exceptRoots)
{
  __int64 v2; // r11
  __int64 v3; // rax
  __int64 v4; // r9
  char v5; // [rsp+10h] [rbp+10h]

  v2 = skeleton->m_bones.m_size;
  v3 = 0i64;
  v5 = exceptRoots.m_bool;
  if ( v2 > 0 )
  {
    v4 = 0i64;
    do
    {
      if ( skeleton->m_parentIndices.m_data[v3] > 0 || !exceptRoots.m_bool )
      {
        skeleton->m_bones.m_data[v4].m_lockTranslation.m_bool = 1;
        exceptRoots.m_bool = v5;
      }
      ++v3;
      ++v4;
    }
    while ( v3 < v2 );
  }
}

// File Line: 194
// RVA: 0xB1F3A0
hkBool *__fastcall hkaSkeletonUtils::getBoneChain(hkBool *result, hkaSkeleton *skeleton, __int16 startBone, __int16 endBone, hkArray<short,hkContainerHeapAllocator> *bonesOut)
{
  __int16 v5; // bx
  __int16 v6; // r14
  hkaSkeleton *v7; // r15
  hkBool *v8; // r12
  hkArray<short,hkContainerHeapAllocator> *v9; // rax
  int v10; // edi
  int v11; // edx
  hkLifoAllocator *v12; // rax
  char *v13; // r8
  int v14; // edx
  char *v15; // rcx
  char *v16; // rax
  unsigned int v17; // edi
  bool v18; // zf
  bool v19; // sf
  unsigned __int8 v20; // of
  __int16 *v21; // rax
  bool v22; // bl
  hkArray<short,hkContainerHeapAllocator> *v23; // rdi
  int v24; // eax
  __int64 v25; // r14
  int v26; // eax
  __int64 v27; // r8
  signed __int64 v28; // r9
  __int16 v29; // cx
  char *v30; // rdi
  int v31; // eax
  unsigned int v32; // ecx
  signed int v33; // ebx
  hkLifoAllocator *v34; // rax
  int v35; // er8
  char *array; // [rsp+30h] [rbp-20h]
  int v38; // [rsp+38h] [rbp-18h]
  int v39; // [rsp+3Ch] [rbp-14h]
  void *p; // [rsp+40h] [rbp-10h]
  int v41; // [rsp+48h] [rbp-8h]
  hkResult resulta; // [rsp+90h] [rbp+40h]

  v5 = endBone;
  v6 = startBone;
  v7 = skeleton;
  v8 = result;
  if ( startBone <= endBone )
  {
    v10 = skeleton->m_bones.m_size;
    v11 = 0;
    array = 0i64;
    v38 = 0;
    v39 = 2147483648;
    v41 = v10;
    if ( v10 )
    {
      v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v13 = (char *)v12->m_cur;
      v14 = (2 * v10 + 127) & 0xFFFFFF80;
      v15 = &v13[v14];
      if ( v14 > v12->m_slabSize || v15 > v12->m_end )
      {
        v16 = (char *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
        v11 = v38;
        array = v16;
      }
      else
      {
        v12->m_cur = v15;
        v11 = v38;
        array = v13;
      }
    }
    else
    {
      array = 0i64;
    }
    v17 = v10 | 0x80000000;
    p = array;
    v39 = v17;
    v20 = __OFSUB__(v5, -1);
    v18 = v5 == -1;
    v19 = (signed __int16)(v5 + 1) < 0;
    if ( v5 > -1 )
    {
      do
      {
        if ( v5 == v6 )
          break;
        if ( v11 == (v17 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 2);
          v11 = v38;
        }
        *(_WORD *)&array[2 * v11] = v5;
        v21 = v7->m_parentIndices.m_data;
        v17 = v39;
        v11 = v38++ + 1;
        v5 = v21[v5];
      }
      while ( v5 > -1 );
      v20 = __OFSUB__(v5, -1);
      v18 = v5 == -1;
      v19 = (signed __int16)(v5 + 1) < 0;
    }
    v22 = !((unsigned __int8)(v19 ^ v20) | v18);
    if ( !((unsigned __int8)(v19 ^ v20) | v18) )
    {
      if ( v11 == (v17 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 2);
        v11 = v38;
      }
      v23 = bonesOut;
      *(_WORD *)&array[2 * v11] = v6;
      v11 = v38 + 1;
      v24 = v23->m_capacityAndFlags & 0x3FFFFFFF;
      v38 = v11;
      v25 = v11;
      if ( v24 < v11 )
      {
        v26 = 2 * v24;
        if ( v11 < v26 )
          v11 = v26;
        hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v23, v11, 2);
        v11 = v38;
      }
      v23->m_size = v25;
      v27 = 0i64;
      if ( (signed int)v25 > 0 )
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
    v32 = hkMemoryRouter::s_memoryRouter.m_slotID;
    v18 = p == array;
    v8->m_bool = v22;
    if ( v18 )
      v11 = 0;
    v33 = (2 * v31 + 127) & 0xFFFFFF80;
    v38 = v11;
    v34 = (hkLifoAllocator *)TlsGetValue(v32);
    v35 = (v33 + 15) & 0xFFFFFFF0;
    if ( v33 > v34->m_slabSize || &v30[v35] != v34->m_cur || v34->m_firstNonLifoEnd == v30 )
      hkLifoAllocator::slowBlockFree(v34, v30, v35);
    else
      v34->m_cur = v30;
    v38 = 0;
    if ( v39 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        2 * (v39 & 0x3FFFFFFF));
  }
  else
  {
    v9 = bonesOut;
    result->m_bool = 0;
    v9->m_size = 0;
  }
  return v8;
}

// File Line: 236
// RVA: 0xB1F620
hkBool *__fastcall hkaSkeletonUtils::getBoneChainWithinPartition(hkBool *result, hkaSkeleton *skeleton, __int16 startBone, __int16 endBone, hkArray<short,hkContainerHeapAllocator> *bonesOut)
{
  __int16 v5; // bx
  __int16 v6; // r12
  hkaSkeleton *v7; // r13
  hkBool *v8; // r15
  hkArray<short,hkContainerHeapAllocator> *v9; // rax
  hkBool *v10; // rax
  int v11; // edi
  int v12; // er9
  hkLifoAllocator *v13; // rax
  char *v14; // r8
  int v15; // edx
  char *v16; // rcx
  char *v17; // rax
  __int64 v18; // r14
  unsigned int v19; // edi
  signed int v20; // er10
  signed int v21; // er11
  __int16 *v22; // r8
  signed int v23; // ecx
  int v24; // eax
  __int64 v25; // r14
  bool v26; // zf
  bool v27; // sf
  unsigned __int8 v28; // of
  __int16 *v29; // rax
  bool v30; // bl
  hkArray<short,hkContainerHeapAllocator> *v31; // rdi
  int v32; // eax
  __int64 v33; // r14
  int v34; // eax
  __int64 v35; // r8
  signed __int64 v36; // r9
  __int16 v37; // cx
  char *v38; // rdi
  int v39; // eax
  unsigned int v40; // ecx
  signed int v41; // ebx
  hkLifoAllocator *v42; // rax
  int v43; // er8
  char *array; // [rsp+30h] [rbp-28h]
  int v45; // [rsp+38h] [rbp-20h]
  int v46; // [rsp+3Ch] [rbp-1Ch]
  void *p; // [rsp+40h] [rbp-18h]
  int v48; // [rsp+48h] [rbp-10h]
  hkBool *v49; // [rsp+90h] [rbp+38h]
  hkResult resulta; // [rsp+A0h] [rbp+48h]

  v49 = result;
  v5 = endBone;
  v6 = startBone;
  v7 = skeleton;
  v8 = result;
  if ( startBone <= endBone )
  {
    v11 = skeleton->m_bones.m_size;
    array = 0i64;
    v12 = 0;
    v45 = 0;
    v46 = 2147483648;
    v48 = v11;
    if ( v11 )
    {
      v13 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v14 = (char *)v13->m_cur;
      v15 = (2 * v11 + 127) & 0xFFFFFF80;
      v16 = &v14[v15];
      if ( v15 > v13->m_slabSize || v16 > v13->m_end )
      {
        v17 = (char *)hkLifoAllocator::allocateFromNewSlab(v13, v15);
        v12 = v45;
        array = v17;
      }
      else
      {
        v13->m_cur = v16;
        v12 = v45;
        array = v14;
      }
    }
    else
    {
      array = 0i64;
    }
    v18 = v7->m_partitions.m_size;
    v19 = v11 | 0x80000000;
    v20 = -1;
    v46 = v19;
    v21 = 0;
    p = array;
    if ( v18 > 0 )
    {
      v22 = &v7->m_partitions.m_data->m_startBoneIndex;
      do
      {
        v23 = *v22;
        v24 = v23 + v22[1];
        v22 += 8;
        if ( v5 < v24 && v23 <= v5 )
          v20 = v21;
        ++v21;
        --v18;
      }
      while ( v18 );
      v8 = v49;
    }
    v25 = v20;
    while ( 1 )
    {
      v28 = __OFSUB__(v5, -1);
      v26 = v5 == -1;
      v27 = (signed __int16)(v5 + 1) < 0;
      if ( v5 <= -1 )
        break;
      if ( v5 == v6 )
        goto LABEL_24;
      if ( v25 != -1
        && (v5 >= v7->m_partitions.m_data[v25].m_startBoneIndex + v7->m_partitions.m_data[v25].m_numBones
         || v7->m_partitions.m_data[v25].m_startBoneIndex > v5) )
      {
        v5 = -1;
LABEL_24:
        v28 = __OFSUB__(v5, -1);
        v26 = v5 == -1;
        v27 = (signed __int16)(v5 + 1) < 0;
        break;
      }
      if ( v12 == (v19 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 2);
        v12 = v45;
      }
      *(_WORD *)&array[2 * v12] = v5;
      v29 = v7->m_parentIndices.m_data;
      v19 = v46;
      v12 = v45++ + 1;
      v5 = v29[v5];
    }
    v30 = !((unsigned __int8)(v27 ^ v28) | v26);
    if ( !((unsigned __int8)(v27 ^ v28) | v26) )
    {
      if ( v12 == (v19 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 2);
        v12 = v45;
      }
      v31 = bonesOut;
      *(_WORD *)&array[2 * v12] = v6;
      v12 = v45 + 1;
      v32 = v31->m_capacityAndFlags & 0x3FFFFFFF;
      v45 = v12;
      v33 = v12;
      if ( v32 < v12 )
      {
        v34 = 2 * v32;
        if ( v12 < v34 )
          v12 = v34;
        hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v31, v12, 2);
        v12 = v45;
      }
      v31->m_size = v33;
      v35 = 0i64;
      if ( (signed int)v33 > 0 )
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
    v40 = hkMemoryRouter::s_memoryRouter.m_slotID;
    v26 = p == array;
    v8->m_bool = v30;
    if ( v26 )
      v12 = 0;
    v41 = (2 * v39 + 127) & 0xFFFFFF80;
    v45 = v12;
    v42 = (hkLifoAllocator *)TlsGetValue(v40);
    v43 = (v41 + 15) & 0xFFFFFFF0;
    if ( v41 > v42->m_slabSize || &v38[v43] != v42->m_cur || v42->m_firstNonLifoEnd == v38 )
      hkLifoAllocator::slowBlockFree(v42, v38, v43);
    else
      v42->m_cur = v38;
    v45 = 0;
    if ( v46 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        2 * (v46 & 0x3FFFFFFF));
    v10 = v8;
  }
  else
  {
    v9 = bonesOut;
    result->m_bool = 0;
    v9->m_size = 0;
    v10 = result;
  }
  return v10;
}

// File Line: 294
// RVA: 0xB1F280
signed __int64 __fastcall hkaSkeletonUtils::findBoneWithName(hkaSkeleton *skeleton, const char *name, int (__fastcall *compare)(const char *, const char *))
{
  int v3; // edi
  int (__fastcall *v4)(const char *, const char *); // rsi
  const char *v5; // r14
  hkaSkeleton *v6; // rbp
  unsigned __int16 v7; // bx

  v3 = skeleton->m_bones.m_size;
  v4 = compare;
  v5 = name;
  v6 = skeleton;
  if ( !compare )
    v4 = hkString::strCasecmp;
  v7 = 0;
  if ( v3 <= 0 )
    return 0xFFFFFFFFi64;
  while ( v4(
            v5,
            (const char *)((_QWORD)v6->m_bones.m_data[(signed __int16)v7].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64)) )
  {
    if ( (signed __int16)++v7 >= v3 )
      return 0xFFFFFFFFi64;
  }
  return v7;
}

// File Line: 316
// RVA: 0xB1F370
void __fastcall hkaSkeletonUtils::unlockTranslations(hkaSkeleton *skeleton)
{
  __int64 v1; // r8
  __int64 v2; // rax

  v1 = skeleton->m_bones.m_size;
  if ( v1 > 0 )
  {
    v2 = 0i64;
    do
    {
      ++v2;
      *((_BYTE *)&skeleton->m_bones.m_data[v2] - 8) = 0;
      --v1;
    }
    while ( v1 );
  }
}

// File Line: 330
// RVA: 0xB1F950
void __fastcall hkaSkeletonUtils::getDescendants(hkaSkeleton *skeleton, __int16 startBone, hkArray<short,hkContainerHeapAllocator> *bonesOut, bool includeStart)
{
  int v4; // edi
  __int16 v5; // si
  int v6; // edx
  bool v7; // r12
  hkArray<short,hkContainerHeapAllocator> *v8; // rbx
  hkaSkeleton *v9; // r14
  hkLifoAllocator *v10; // rax
  char *v11; // rcx
  int v12; // edx
  char *v13; // r8
  char *v14; // rax
  int v15; // er15
  unsigned int v16; // edi
  int v17; // edi
  int v18; // er9
  int v19; // eax
  char *v20; // rdi
  unsigned __int64 v21; // rdx
  __int64 v22; // rax
  __int16 v23; // si
  char *i; // rcx
  __int16 v25; // dx
  int v26; // eax
  char *v27; // rbx
  signed int v28; // edi
  hkLifoAllocator *v29; // rax
  int v30; // er8
  char *array; // [rsp+30h] [rbp-20h]
  int v32; // [rsp+38h] [rbp-18h]
  int v33; // [rsp+3Ch] [rbp-14h]
  void *p; // [rsp+40h] [rbp-10h]
  int v35; // [rsp+48h] [rbp-8h]
  hkResult result; // [rsp+98h] [rbp+48h]

  v4 = skeleton->m_bones.m_size;
  v5 = startBone;
  v6 = 0;
  v7 = includeStart;
  v8 = bonesOut;
  v9 = skeleton;
  array = 0i64;
  v33 = 2147483648;
  v32 = 0;
  v35 = v4;
  if ( v4 )
  {
    v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (char *)v10->m_cur;
    v12 = (v4 + 127) & 0xFFFFFF80;
    v13 = &v11[v12];
    if ( v12 > v10->m_slabSize || v13 > v10->m_end )
    {
      v14 = (char *)hkLifoAllocator::allocateFromNewSlab(v10, v12);
      v6 = v32;
      v11 = v14;
    }
    else
    {
      v10->m_cur = v13;
      v6 = v32;
    }
  }
  else
  {
    v11 = 0i64;
  }
  v15 = v9->m_bones.m_size;
  v16 = v4 | 0x80000000;
  array = v11;
  v33 = v16;
  v17 = v16 & 0x3FFFFFFF;
  p = v11;
  if ( v17 < v15 )
  {
    v18 = v15;
    if ( v15 < 2 * v17 )
      v18 = 2 * v17;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v18, 1);
    v6 = v32;
    v11 = array;
  }
  v19 = v15 - v6;
  v20 = &v11[v6];
  v21 = v15 - v6;
  if ( v19 > 0 )
  {
    memset(v20, 0, v21);
    v11 = array;
  }
  v32 = v15;
  if ( v7 )
  {
    if ( v8->m_size == (v8->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, 2);
    v8->m_data[v8->m_size++] = v5;
    v11 = array;
  }
  v22 = v5;
  v23 = v5 + 1;
  v11[v22] = 1;
  for ( i = array; v23 < v9->m_bones.m_size; ++v23 )
  {
    v25 = v9->m_parentIndices.m_data[v23];
    if ( v25 != -1 && i[v25] )
    {
      i[v23] = 1;
      if ( v8->m_size == (v8->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, 2);
      v8->m_data[v8->m_size++] = v23;
      i = array;
    }
  }
  v26 = v32;
  v27 = (char *)p;
  if ( p == i )
    v26 = 0;
  v28 = (v35 + 127) & 0xFFFFFF80;
  v32 = v26;
  v29 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v30 = (v28 + 15) & 0xFFFFFFF0;
  if ( v28 > v29->m_slabSize || &v27[v30] != v29->m_cur || v29->m_firstNonLifoEnd == v27 )
    hkLifoAllocator::slowBlockFree(v29, v27, v30);
  else
    v29->m_cur = v27;
  v32 = 0;
  if ( v33 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      v33 & 0x3FFFFFFF);
}

// File Line: 352
// RVA: 0xB1FBB0
void __fastcall hkaSkeletonUtils::getAncestors(hkaSkeleton *skeleton, __int16 startBone, hkArray<short,hkContainerHeapAllocator> *bonesOut)
{
  hkArray<short,hkContainerHeapAllocator> *v3; // rbx
  __int16 v4; // di
  hkaSkeleton *i; // rsi

  v3 = bonesOut;
  v4 = skeleton->m_parentIndices.m_data[startBone];
  for ( i = skeleton; v4 != -1; v4 = i->m_parentIndices.m_data[v4] )
  {
    if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 2);
    v3->m_data[v3->m_size++] = v4;
  }
}

// File Line: 364
// RVA: 0xB1FC40
void __fastcall hkaSkeletonUtils::markDescendants(hkaSkeleton *skeleton, int startBone, bool *out, bool includeStart)
{
  hkaSkeleton *v4; // r10
  __int64 v5; // r11
  int v6; // edx
  bool *v7; // rcx
  signed __int64 v8; // rdi
  __int16 v9; // ax
  bool v10; // al

  v4 = skeleton;
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
      v9 = v4->m_parentIndices.m_data[v8];
      v10 = v9 >= 0 && out[v9];
      *v7 = v10;
      ++v6;
      ++v8;
      ++v7;
    }
    while ( v6 < v4->m_bones.m_size );
  }
  out[v5] = includeStart;
}

// File Line: 389
// RVA: 0xB1FCD0
void __fastcall hkaSkeletonUtils::getLeaves(hkaSkeleton *skeleton, hkArray<short,hkContainerHeapAllocator> *leavesOut)
{
  int v2; // edi
  hkArray<short,hkContainerHeapAllocator> *v3; // rbx
  int v4; // edx
  hkaSkeleton *v5; // rsi
  hkLifoAllocator *v6; // rax
  char *v7; // rcx
  int v8; // edx
  char *v9; // r8
  char *v10; // rax
  int v11; // er14
  unsigned int v12; // edi
  int v13; // edi
  int v14; // er9
  int v15; // eax
  char *v16; // rdi
  unsigned __int64 v17; // rdx
  int v18; // edx
  __int64 v19; // rdi
  __int16 v20; // r8
  __int16 v21; // di
  int v22; // eax
  char *v23; // rbx
  signed int v24; // edi
  hkLifoAllocator *v25; // rax
  int v26; // er8
  char *array; // [rsp+30h] [rbp-20h]
  int v28; // [rsp+38h] [rbp-18h]
  int v29; // [rsp+3Ch] [rbp-14h]
  void *p; // [rsp+40h] [rbp-10h]
  int v31; // [rsp+48h] [rbp-8h]
  hkResult result; // [rsp+70h] [rbp+20h]

  v2 = skeleton->m_bones.m_size;
  v3 = leavesOut;
  v4 = 0;
  v5 = skeleton;
  v29 = 2147483648;
  array = 0i64;
  v31 = v2;
  v28 = 0;
  if ( v2 )
  {
    v6 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v7 = (char *)v6->m_cur;
    v8 = (v2 + 127) & 0xFFFFFF80;
    v9 = &v7[v8];
    if ( v8 > v6->m_slabSize || v9 > v6->m_end )
    {
      v10 = (char *)hkLifoAllocator::allocateFromNewSlab(v6, v8);
      v4 = v28;
      v7 = v10;
    }
    else
    {
      v6->m_cur = v9;
      v4 = v28;
    }
  }
  else
  {
    v7 = 0i64;
  }
  v11 = v5->m_bones.m_size;
  v12 = v2 | 0x80000000;
  array = v7;
  v29 = v12;
  v13 = v12 & 0x3FFFFFFF;
  p = v7;
  if ( v13 < v11 )
  {
    v14 = v11;
    if ( v11 < 2 * v13 )
      v14 = 2 * v13;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v14, 1);
    v4 = v28;
    v7 = array;
  }
  v15 = v11 - v4;
  v16 = &v7[v4];
  v17 = v11 - v4;
  if ( v15 > 0 )
  {
    memset(v16, 0, v17);
    v7 = array;
  }
  v18 = 0;
  v28 = v11;
  if ( v5->m_parentIndices.m_size > 0 )
  {
    v19 = 0i64;
    do
    {
      v20 = v5->m_parentIndices.m_data[v19];
      if ( v20 != -1 )
      {
        v7[v20] = 1;
        v7 = array;
      }
      ++v18;
      ++v19;
    }
    while ( v18 < v5->m_parentIndices.m_size );
  }
  v21 = 0;
  if ( v5->m_bones.m_size > 0 )
  {
    do
    {
      if ( !v7[v21] )
      {
        if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 2);
        v3->m_data[v3->m_size++] = v21;
        v7 = array;
      }
      ++v21;
    }
    while ( v21 < v5->m_bones.m_size );
  }
  v22 = v28;
  v23 = (char *)p;
  if ( p == v7 )
    v22 = 0;
  v24 = (v31 + 127) & 0xFFFFFF80;
  v28 = v22;
  v25 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v26 = (v24 + 15) & 0xFFFFFFF0;
  if ( v24 > v25->m_slabSize || &v23[v26] != v25->m_cur || v25->m_firstNonLifoEnd == v23 )
    hkLifoAllocator::slowBlockFree(v25, v23, v26);
  else
    v25->m_cur = v23;
  v28 = 0;
  if ( v29 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      v29 & 0x3FFFFFFF);
}

// File Line: 455
// RVA: 0xB1E900
void __fastcall hkaSkeletonUtils::blendPoses(unsigned int numBones, hkQsTransformf *poseA, hkQsTransformf *poseB, const float *weights, hkQsTransformf *poseOut)
{
  signed __int64 v5; // r8
  __m128 *v6; // r10
  signed __int64 v7; // rax
  __int64 v8; // rdx
  __m128 v9; // xmm1
  __m128 v10; // xmm3
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
    v6 = &poseA->m_rotation.m_vec.m_quad;
    v7 = (char *)poseOut - (char *)poseA;
    v8 = numBones;
    do
    {
      v9 = *(__m128 *)((char *)v6 + v5 - 16);
      v10 = *v6;
      v11 = (__m128)*(unsigned int *)weights;
      v6 += 3;
      ++weights;
      v12 = _mm_shuffle_ps(v11, v11, 0);
      *(__m128 *)((char *)v6 + v7 - 64) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v9, v6[-4]), v12), v6[-4]);
      v13 = _mm_mul_ps(*(__m128 *)((char *)v6 + v5 - 48), v10);
      v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
      v15 = _mm_sub_ps(
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14), 0x1Fu),
                          0x1Fu),
                *(__m128 *)((char *)v6 + v5 - 48)),
              v10);
      *(__m128 *)((char *)v6 + v7 - 32) = _mm_add_ps(
                                            _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v6 + v5 - 32), v6[-2]), v12),
                                            v6[-2]);
      v16 = _mm_add_ps(_mm_mul_ps(v15, v12), v10);
      v17 = _mm_mul_ps(v16, v16);
      v18 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 78), v17);
      v19 = _mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 177), v18), *(__m128 *)&epsilon);
      v20 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 177), v18);
      v21 = _mm_rsqrt_ps(v20);
      *(__m128 *)((char *)v6 + v7 - 48) = _mm_or_ps(
                                            _mm_andnot_ps(
                                              v19,
                                              _mm_mul_ps(
                                                v16,
                                                _mm_mul_ps(
                                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                                                  _mm_mul_ps(*(__m128 *)_xmm, v21)))),
                                            _mm_and_ps(v19, qi.m_vec.m_quad));
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 464
// RVA: 0xB1EA50
void __fastcall hkaSkeletonUtils::blendPoses(unsigned int numBones, hkQsTransformf *poseA, hkQsTransformf *poseB, const float weight, hkQsTransformf *poseOut)
{
  signed __int64 v5; // r8
  signed __int64 v6; // rax
  __m128 *v7; // r9
  __int64 v8; // rdx
  __m128 v9; // xmm5
  __m128 v10; // xmm1
  __m128 v11; // xmm3
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
    v7 = &poseA->m_rotation.m_vec.m_quad;
    v8 = numBones;
    v9 = _mm_shuffle_ps((__m128)LODWORD(weight), (__m128)LODWORD(weight), 0);
    do
    {
      v10 = *(__m128 *)((char *)v7 + v5 - 16);
      v11 = *v7;
      v7 += 3;
      *(__m128 *)((char *)v7 + v6 - 64) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v10, v7[-4]), v9), v7[-4]);
      v12 = _mm_mul_ps(*(__m128 *)((char *)v7 + v5 - 48), v11);
      v13 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 78), v12);
      v14 = _mm_sub_ps(
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v13, v13, 177), v13), 0x1Fu),
                          0x1Fu),
                *(__m128 *)((char *)v7 + v5 - 48)),
              v11);
      *(__m128 *)((char *)v7 + v6 - 32) = _mm_add_ps(
                                            _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v7 + v5 - 32), v7[-2]), v9),
                                            v7[-2]);
      v15 = _mm_add_ps(_mm_mul_ps(v14, v9), v11);
      v16 = _mm_mul_ps(v15, v15);
      v17 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 78), v16);
      v18 = _mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 177), v17), *(__m128 *)&epsilon);
      v19 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 177), v17);
      v20 = _mm_rsqrt_ps(v19);
      *(__m128 *)((char *)v7 + v6 - 48) = _mm_or_ps(
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

// File Line: 475
// RVA: 0xB1EBA0
void __fastcall hkaSkeletonUtils::blendPosesNoAlias(unsigned int numBones, hkQsTransformf *poseA, hkQsTransformf *poseB, const float *weights, hkQsTransformf *poseOut)
{
  signed __int64 v5; // r8
  __m128 *v6; // r10
  signed __int64 v7; // rax
  __int64 v8; // rdx
  __m128 v9; // xmm3
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
    v6 = &poseA->m_rotation.m_vec.m_quad;
    v7 = (char *)poseOut - (char *)poseA;
    v8 = numBones;
    do
    {
      v9 = *v6;
      v10 = (__m128)*(unsigned int *)weights;
      ++weights;
      v11 = _mm_shuffle_ps(v10, v10, 0);
      v12 = _mm_sub_ps(*(__m128 *)((char *)v6 + v5 - 16), v6[-1]);
      v13 = *(__m128 *)((char *)v6 + v5);
      v6 += 3;
      v14 = _mm_mul_ps(v13, v9);
      *(__m128 *)((char *)v6 + v7 - 64) = _mm_add_ps(_mm_mul_ps(v12, v11), v6[-4]);
      v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 78), v14);
      v16 = _mm_sub_ps(
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v15, v15, 177), v15), 0x1Fu),
                          0x1Fu),
                *(__m128 *)((char *)v6 + v5 - 48)),
              v9);
      *(__m128 *)((char *)v6 + v7 - 32) = _mm_add_ps(
                                            _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v6 + v5 - 32), v6[-2]), v11),
                                            v6[-2]);
      v17 = _mm_add_ps(_mm_mul_ps(v16, v11), v9);
      v18 = _mm_mul_ps(v17, v17);
      v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
      v20 = _mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19), *(__m128 *)&epsilon);
      v21 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
      v22 = _mm_rsqrt_ps(v21);
      *(__m128 *)((char *)v6 + v7 - 48) = _mm_or_ps(
                                            _mm_andnot_ps(
                                              v20,
                                              _mm_mul_ps(
                                                v17,
                                                _mm_mul_ps(
                                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                                                  _mm_mul_ps(*(__m128 *)_xmm, v22)))),
                                            _mm_and_ps(v20, qi.m_vec.m_quad));
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 491
// RVA: 0xB1ED00
void __fastcall hkaSkeletonUtils::blendPosesNoAlias(unsigned int numBones, hkQsTransformf *poseA, hkQsTransformf *poseB, const float weight, hkQsTransformf *poseOut)
{
  signed __int64 v5; // r8
  __m128 *v6; // r9
  signed __int64 v7; // rax
  __int64 v8; // rdx
  __m128 v9; // xmm5
  __m128 v10; // xmm3
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
    v6 = &poseA->m_rotation.m_vec.m_quad;
    v7 = (char *)poseOut - (char *)poseA;
    v8 = numBones;
    v9 = _mm_shuffle_ps((__m128)LODWORD(weight), (__m128)LODWORD(weight), 0);
    do
    {
      v10 = *v6;
      v11 = *(__m128 *)((char *)v6 + v5 - 16);
      v12 = *(__m128 *)((char *)v6 + v5);
      v6 += 3;
      v13 = _mm_mul_ps(v12, v10);
      *(__m128 *)((char *)v6 + v7 - 64) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v11, v6[-4]), v9), v6[-4]);
      v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
      v15 = _mm_sub_ps(
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32((__m128i)_mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14), 0x1Fu),
                          0x1Fu),
                *(__m128 *)((char *)v6 + v5 - 48)),
              v10);
      *(__m128 *)((char *)v6 + v7 - 32) = _mm_add_ps(
                                            _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)v6 + v5 - 32), v6[-2]), v9),
                                            v6[-2]);
      v16 = _mm_add_ps(_mm_mul_ps(v15, v9), v10);
      v17 = _mm_mul_ps(v16, v16);
      v18 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 78), v17);
      v19 = _mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 177), v18), *(__m128 *)&epsilon);
      v20 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 177), v18);
      v21 = _mm_rsqrt_ps(v20);
      *(__m128 *)((char *)v6 + v7 - 48) = _mm_or_ps(
                                            _mm_andnot_ps(
                                              v19,
                                              _mm_mul_ps(
                                                v16,
                                                _mm_mul_ps(
                                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                                                  _mm_mul_ps(*(__m128 *)_xmm, v21)))),
                                            _mm_and_ps(v19, qi.m_vec.m_quad));
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 505
// RVA: 0xB1EE60
void __fastcall hkaSkeletonUtils::blendPartialPoses(unsigned int numBones, __int16 *bones, hkQsTransformf *poseA, hkQsTransformf *poseB, const float weight, hkQsTransformf *poseOut)
{
  __int16 *v6; // r10
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

  v6 = bones;
  v7 = _mm_shuffle_ps((__m128)LODWORD(weight), (__m128)LODWORD(weight), 0);
  if ( numBones )
  {
    v8 = numBones;
    do
    {
      v9 = *v6;
      ++v6;
      v10 = v9;
      v11.m_vec.m_quad = (__m128)poseA[v9].m_rotation;
      v12 = _mm_mul_ps(poseA[v9].m_rotation.m_vec.m_quad, poseB[v9].m_rotation.m_vec.m_quad);
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
      v18 = _mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 177), v17), *(__m128 *)&epsilon);
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
  __int64 v3; // r10
  __int64 v4; // r9
  __int16 *v5; // r8
  hkBool *v6; // rax

  v3 = binding->m_transformTrackToBoneIndices.m_size;
  v4 = 0i64;
  if ( v3 <= 0 )
  {
LABEL_6:
    result->m_bool = 1;
    v6 = result;
  }
  else
  {
    v5 = binding->m_transformTrackToBoneIndices.m_data;
    while ( *v5 >= 0 && *v5 < skeleton->m_bones.m_size )
    {
      ++v4;
      ++v5;
      if ( v4 >= v3 )
        goto LABEL_6;
    }
    result->m_bool = 0;
    v6 = result;
  }
  return v6;
}

// File Line: 534
// RVA: 0xB1FF30
void __fastcall hkaSkeletonUtils::getModelSpaceScale(hkaSkeleton *skeleton, hkQsTransformf *poseLocal, int boneId, hkVector4f *scaleOut)
{
  __m128 v4; // xmm0
  __int16 *v5; // r10
  __int64 v6; // rcx

  v4 = query.m_quad;
  if ( boneId != -1 )
  {
    v5 = skeleton->m_parentIndices.m_data;
    do
    {
      v6 = boneId;
      boneId = v5[boneId];
      v4 = _mm_mul_ps(v4, poseLocal[v6].m_scale.m_quad);
    }
    while ( boneId != -1 );
  }
  *scaleOut = (hkVector4f)v4;
}

// File Line: 546
// RVA: 0xB1FF70
void __fastcall hkaSkeletonUtils::normalizeRotations(hkQsTransformf *transformsInOut, int numTransforms)
{
  int v2; // kr00_4
  int v3; // edx
  int v4; // eax
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
  __m128 *v21; // rax
  __int64 v22; // rcx
  __m128 v23; // xmm3
  __m128 v24; // xmm0
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  __m128 v27; // xmm2

  v2 = numTransforms;
  v3 = (numTransforms >> 31) & 3;
  v4 = v3 + v2;
  v5 = ((v3 + v2) & 3u) - v3;
  if ( v4 >> 2 )
  {
    v6 = (unsigned int)(v4 >> 2);
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
    v21 = &transformsInOut->m_rotation.m_vec.m_quad;
    v22 = v5;
    do
    {
      v23 = *v21;
      v21 += 3;
      v24 = _mm_mul_ps(v23, v23);
      v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 78), v24);
      v26 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 177), v25);
      v27 = _mm_rsqrt_ps(v26);
      v21[-3] = _mm_mul_ps(
                  v23,
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
hkResult *__fastcall hkaSkeletonUtils::bindByName(hkResult *result, hkaSkeleton *skeleton, hkaAnimation *anim, int (__fastcall *compare)(const char *, const char *), hkaAnimationBinding *bindingOut)
{
  hkaAnimationBinding *v5; // r15
  hkaAnimation *v6; // r9
  hkaSkeleton *v7; // rsi
  int v8; // eax
  hkResult *v9; // rdi
  int v10; // er10
  hkResult *v11; // rax
  __int64 v12; // rcx
  int v13; // ebx
  __int64 v14; // rdx
  hkaBone *v15; // rax
  __int64 v16; // rdi
  __int64 v17; // r13
  char v18; // bp
  __int16 v19; // bx
  const char *v20; // r14
  int v21; // er12
  hkOstream *v22; // rax
  hkOstream *v23; // rax
  hkErrStream v24; // [rsp+20h] [rbp-258h]
  char buf; // [rsp+40h] [rbp-238h]
  hkResult *v26; // [rsp+280h] [rbp+8h]
  hkaAnimation *v27; // [rsp+290h] [rbp+18h]
  int (__fastcall *v28)(const char *, const char *); // [rsp+298h] [rbp+20h]
  int bindingOuta; // [rsp+2A0h] [rbp+28h]

  v28 = compare;
  v27 = anim;
  v26 = result;
  v5 = bindingOut;
  v6 = anim;
  v7 = skeleton;
  v8 = bindingOut->m_transformTrackToBoneIndices.m_size;
  v9 = result;
  if ( v8 && (v10 = anim->m_numberOfTransformTracks, v8 == v10) )
  {
    if ( anim->m_annotationTracks.m_size == v10 )
    {
      v12 = skeleton->m_bones.m_size;
      v13 = 0;
      v14 = 0i64;
      if ( (signed int)v12 <= 0 )
      {
LABEL_9:
        bindingOuta = 0;
        if ( v10 <= 0 )
        {
LABEL_18:
          v9->m_enum = 0;
          v11 = v9;
        }
        else
        {
          v16 = 0i64;
          v17 = 0i64;
          while ( 1 )
          {
            v18 = 0;
            v19 = 0;
            v20 = (const char *)((_QWORD)v6->m_annotationTracks.m_data[v17].m_trackName.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
            if ( (signed int)v12 <= 0 )
              break;
            do
            {
              if ( !v28(
                      (const char *)((_QWORD)v7->m_bones.m_data[v19].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                      v20) )
              {
                v18 = 1;
                v5->m_transformTrackToBoneIndices.m_data[v16] = v19;
              }
              LODWORD(v12) = v7->m_bones.m_size;
              ++v19;
            }
            while ( v19 < (signed int)v12 );
            v21 = bindingOuta;
            if ( !v18 )
              break;
            v6 = v27;
            ++v17;
            ++v16;
            ++bindingOuta;
            if ( v21 + 1 >= v27->m_numberOfTransformTracks )
            {
              v9 = v26;
              goto LABEL_18;
            }
          }
          hkErrStream::hkErrStream(&v24, &buf, 512);
          v23 = hkOstream::operator<<((hkOstream *)&v24.vfptr, "No match for track ");
          hkOstream::operator<<(v23, v20);
          hkError::messageWarning(1699623992, &buf, "Rig\\hkaSkeletonUtils.cpp", 620);
          hkOstream::~hkOstream((hkOstream *)&v24.vfptr);
          v11 = v26;
          v26->m_enum = 1;
        }
      }
      else
      {
        v15 = v7->m_bones.m_data;
        while ( (_QWORD)v15->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64 )
        {
          ++v14;
          ++v13;
          ++v15;
          if ( v14 >= v12 )
            goto LABEL_9;
        }
        hkErrStream::hkErrStream(&v24, &buf, 512);
        v22 = hkOstream::operator<<((hkOstream *)&v24.vfptr, "No bone name for bone ");
        hkOstream::operator<<(v22, v13);
        hkError::messageWarning(1699623991, &buf, "Rig\\hkaSkeletonUtils.cpp", 598);
        hkOstream::~hkOstream((hkOstream *)&v24.vfptr);
        v9->m_enum = 1;
        v11 = v9;
      }
    }
    else
    {
      hkErrStream::hkErrStream(&v24, &buf, 512);
      hkOstream::operator<<((hkOstream *)&v24.vfptr, "No track names present in animation");
      hkError::messageWarning(1699623991, &buf, "Rig\\hkaSkeletonUtils.cpp", 588);
      hkOstream::~hkOstream((hkOstream *)&v24.vfptr);
      v9->m_enum = 1;
      v11 = v9;
    }
  }
  else
  {
    hkErrStream::hkErrStream(&v24, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v24.vfptr, "Binding is not initiialized");
    hkError::messageWarning(1699623989, &buf, "Rig\\hkaSkeletonUtils.cpp", 581);
    hkOstream::~hkOstream((hkOstream *)&v24.vfptr);
    v9->m_enum = 1;
    v11 = v9;
  }
  return v11;
}

// File Line: 629
// RVA: 0xB20460
void __fastcall hkaSkeletonUtils::calcAabb(unsigned int numBones, hkQsTransformf *poseLocal, const __int16 *parentIndices, hkQsTransformf *worldFromModel, hkAabb *aabbOut)
{
  hkAabb *v5; // rbx
  hkQsTransformf *v6; // rax
  hkQsTransformf *v7; // rsi
  const __int16 *v8; // rbp
  hkQsTransformf *v9; // r14
  __int64 v10; // rdi
  int v11; // er9
  hkQsTransformf *v12; // rdx
  __m128 v13; // xmm1
  __int64 v14; // rax
  __int64 v15; // rcx
  hkQsTransformf *v16; // [rsp+30h] [rbp-28h]
  int v17; // [rsp+38h] [rbp-20h]
  int v18; // [rsp+3Ch] [rbp-1Ch]
  __int64 v19; // [rsp+60h] [rbp+8h]

  v5 = aabbOut;
  v17 = 0;
  v6 = 0i64;
  v7 = worldFromModel;
  aabbOut->m_min = (hkVector4f)xmmword_141A712A0;
  v16 = 0i64;
  v8 = parentIndices;
  v9 = poseLocal;
  v10 = numBones;
  v18 = 2147483648;
  v5->m_max.m_quad = _mm_xor_ps(
                       (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                       v5->m_min.m_quad);
  if ( (signed int)numBones > 0 )
  {
    v11 = v10;
    if ( (signed int)v10 < 0 )
      v11 = 0;
    hkArrayUtil::_reserve(
      (hkResult *)&v19,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v16,
      v11,
      48);
    v6 = v16;
  }
  v17 = v10;
  hkaSkeletonUtils::transformLocalPoseToWorldPose(v10, v8, v7, v9, v6);
  v12 = v16;
  if ( (_DWORD)v10 )
  {
    v13 = v5->m_max.m_quad;
    v14 = (__int64)v16;
    v15 = v10;
    do
    {
      v14 += 48i64;
      v5->m_min.m_quad = _mm_min_ps(v5->m_min.m_quad, *(__m128 *)(v14 - 48));
      v13 = _mm_max_ps(v13, *(__m128 *)(v14 - 48));
      v5->m_max.m_quad = v13;
      --v15;
    }
    while ( v15 );
  }
  v17 = 0;
  if ( v18 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v12,
      48 * (v18 & 0x3FFFFFFF));
}

// File Line: 646
// RVA: 0xB20590
hkBool *__fastcall hkaSkeletonUtils::hasValidPartitions(hkBool *result, hkaSkeleton *skeleton)
{
  hkaSkeleton *v2; // r15
  hkBool *v3; // r12
  signed int v5; // er8
  int v6; // er10
  unsigned int *v7; // r9
  char v8; // al
  int v9; // edx
  int v10; // esi
  __int64 v11; // r14
  hkaSkeleton::Partition *v12; // rax
  int v13; // ecx
  signed int v14; // er11
  int v15; // er10
  int v16; // er9
  int v17; // er8
  int v18; // er9
  _DWORD *v19; // rdi
  __int64 i; // rcx
  int v21; // er8
  unsigned int *v22; // r9
  signed __int64 v23; // rcx
  int v24; // eax
  int v25; // edx
  __int64 v26; // rcx
  unsigned int *v27; // rdx
  signed __int64 v28; // rax
  int v29; // ecx
  __int64 *v30; // rdi
  signed __int64 j; // rcx
  char v32; // cl
  int v33; // eax
  int v34; // er11
  __int64 v35; // r10
  int v36; // ebx
  __m128i v37; // xmm2
  __m128i v38; // xmm3
  __m128i v39; // xmm4
  unsigned int v40; // ecx
  __m128i v41; // xmm0
  __m128i v42; // xmm1
  __m128i v43; // xmm0
  __m128i v44; // xmm1
  bool v45; // zf
  __int64 v46; // r8
  int v47; // er8
  int v48; // [rsp+2Ch] [rbp-6Dh]
  __int64 v49; // [rsp+30h] [rbp-69h]
  __int64 v50; // [rsp+38h] [rbp-61h]
  __int64 v51; // [rsp+40h] [rbp-59h]
  __int64 v52; // [rsp+48h] [rbp-51h]
  int v53; // [rsp+50h] [rbp-49h]
  hkBitFieldStorage<hkInplaceArray<unsigned int,8,hkContainerHeapAllocator> > v54; // [rsp+58h] [rbp-41h]
  hkBitFieldStorage<hkInplaceArray<unsigned int,8,hkContainerHeapAllocator> > __that; // [rsp+90h] [rbp-9h]

  v2 = skeleton;
  v3 = result;
  if ( !skeleton->m_partitions.m_size )
  {
    result->m_bool = 1;
    return result;
  }
  v5 = -2147483640;
  v6 = 8;
  v7 = v54.m_words.m_storage;
  __that.m_words.m_data = __that.m_words.m_storage;
  v8 = 0;
  v9 = -2147483640;
  __that.m_numBits = 256;
  v53 = 256;
  v54.m_numBits = 256;
  __that.m_words.m_capacityAndFlags = -2147483640;
  __that.m_words.m_size = 8;
  *(_QWORD *)__that.m_words.m_storage = 0i64;
  *(_QWORD *)&__that.m_words.m_storage[2] = 0i64;
  *(_QWORD *)&__that.m_words.m_storage[4] = 0i64;
  *(_QWORD *)&__that.m_words.m_storage[6] = 0i64;
  v48 = -2147483640;
  v49 = 0i64;
  v50 = 0i64;
  v51 = 0i64;
  v52 = 0i64;
  v54.m_words.m_data = v54.m_words.m_storage;
  v54.m_words.m_capacityAndFlags = -2147483640;
  v54.m_words.m_size = 8;
  *(_QWORD *)v54.m_words.m_storage = 0i64;
  *(_QWORD *)&v54.m_words.m_storage[2] = 0i64;
  *(_QWORD *)&v54.m_words.m_storage[4] = 0i64;
  *(_QWORD *)&v54.m_words.m_storage[6] = 0i64;
  v10 = 0;
  if ( v2->m_partitions.m_size <= 0 )
  {
LABEL_27:
    v32 = v8 - 1;
    v33 = v6 - 1;
    v34 = 0;
    v35 = v6 - 1;
    v36 = 2 * ~(-1 << (v32 & 0x1F)) | 1;
    if ( v33 >= 0 )
    {
      v37 = _mm_load_si128((const __m128i *)&_xmm);
      v38 = _mm_load_si128((const __m128i *)&_xmm);
      v39 = _mm_load_si128((const __m128i *)&_xmm);
      do
      {
        v40 = v36 & __that.m_words.m_data[v35];
        v36 = -1;
        v41 = _mm_cvtsi32_si128(v40);
        v42 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v41, 1u), v37), _mm_and_si128(v41, v37));
        v43 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v42, 2u), v38), _mm_and_si128(v42, v38));
        v44 = _mm_sad_epu8(_mm_and_si128(_mm_add_epi8(_mm_srli_epi16(v43, 4u), v43), v39), (__m128i)0i64);
        v34 += _mm_cvtsi128_si32(_mm_add_epi32(_mm_shuffle_epi32(v44, 78), v44));
        --v35;
      }
      while ( v35 >= 0 );
    }
    v45 = v34 == v2->m_bones.m_size;
    v54.m_words.m_size = 0;
    v3->m_bool = v45;
    if ( v9 < 0 )
      goto LABEL_34;
    v46 = (unsigned int)(4 * v9);
  }
  else
  {
    v11 = 0i64;
    while ( 1 )
    {
      v12 = v2->m_partitions.m_data;
      v13 = v12[v11].m_startBoneIndex;
      v14 = -1 << (v13 & 0x1F);
      v15 = v13 >> 5;
      v16 = (v13 + v12[v11].m_numBones) >> 5;
      v17 = ~(-1 << ((v13 + v12[v11].m_numBones) & 0x1F));
      if ( v13 >> 5 == v16 )
      {
        v21 = v14 & v17;
        if ( v21 )
          *((_DWORD *)&v49 + v15) = v21 | *((_DWORD *)&v49 + v15) & ~v21;
      }
      else
      {
        *((_DWORD *)&v49 + v15) = v14 | *((_DWORD *)&v49 + v15) & ~v14;
        if ( v17 )
          *((_DWORD *)&v49 + v16) = v17 | *((_DWORD *)&v49 + v16) & ~v17;
        v18 = v16 - v15 - 2;
        v19 = (_DWORD *)((char *)&v49 + 4 * (v15 + 1));
        if ( v18 >= 0 )
        {
          for ( i = (unsigned int)(v18 + 1); i; --i )
          {
            *v19 = -1;
            ++v19;
          }
        }
      }
      hkBitFieldStorage<hkInplaceArray<unsigned int,8,hkContainerHeapAllocator>>::operator=(&v54, &__that);
      v22 = v54.m_words.m_data;
      v23 = 8i64;
      do
      {
        v24 = *((_DWORD *)&v49 + v23-- - 1);
        v22[v23] &= v24;
      }
      while ( v23 );
      v7 = v54.m_words.m_data;
      v25 = 2 * ~(-1 << ((LOBYTE(v54.m_numBits) - 1) & 0x1F)) | 1;
      v26 = v54.m_words.m_size - 1;
      if ( v54.m_words.m_size - 1 >= 0 )
        break;
LABEL_20:
      v27 = __that.m_words.m_data;
      v28 = 8i64;
      do
      {
        v29 = *((_DWORD *)&v49 + v28-- - 1);
        v27[v28] |= v29;
      }
      while ( v28 );
      v30 = &v49;
      for ( j = 8i64; j; --j )
      {
        *(_DWORD *)v30 = 0;
        v30 = (__int64 *)((char *)v30 + 4);
      }
      v7 = v54.m_words.m_data;
      ++v10;
      ++v11;
      if ( v10 >= v2->m_partitions.m_size )
      {
        v8 = __that.m_numBits;
        v6 = __that.m_words.m_size;
        v5 = v48;
        v9 = v54.m_words.m_capacityAndFlags;
        goto LABEL_27;
      }
    }
    while ( !(v25 & v54.m_words.m_data[v26]) )
    {
      --v26;
      v25 = -1;
      if ( v26 < 0 )
        goto LABEL_20;
    }
    v47 = v54.m_words.m_capacityAndFlags;
    v3->m_bool = 0;
    v54.m_words.m_size = 0;
    if ( v47 < 0 )
      goto LABEL_33;
    v46 = (unsigned int)(4 * v47);
  }
  hkContainerHeapAllocator::s_alloc.vfptr->bufFree((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc, v7, v46);
LABEL_33:
  v5 = v48;
LABEL_34:
  v54.m_words.m_capacityAndFlags = 2147483648;
  v54.m_words.m_data = 0i64;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      &v49,
      4 * v5);
  __that.m_words.m_size = 0;
  v48 = 2147483648;
  if ( __that.m_words.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      __that.m_words.m_data,
      4 * __that.m_words.m_capacityAndFlags);
  return v3;
}


// File Line: 22
// RVA: 0xB2BBD0
void __fastcall hkaSampleAndCombineUtils::blendNormal(
        hkaSampleAndCombineUtils::TransformBlendParameters *paramsIn,
        hkQsTransformf *accumulationPoseInOut,
        float *accumulatedPerBoneWeightsInOut)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r8
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  __int64 v11; // r8
  unsigned __int64 v12; // rdx
  __int64 v13; // rdi
  hkaSkeleton::Partition *v14; // rcx
  __int64 m_startBoneIndex; // r9
  unsigned __int64 v16; // r10
  hkQuaternionf *p_m_rotation; // r11
  const char *m_perBoneWeights; // rax
  __m128 v19; // xmm4
  __m128 v20; // xmm0
  __m128 *v21; // rax
  __m128 v22; // xmm4
  hkQsTransformf *m_animationTransformsIn; // rax
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  __int64 v27; // rax
  __int64 m_maxTransformTrackIndex; // r10
  __int64 v29; // r9
  __int16 v30; // dx
  const char *v31; // rax
  __m128 v32; // xmm5
  __m128 v33; // xmm0
  __m128 *p_m_quad; // rax
  __m128 v35; // xmm5
  hkQsTransformf *v36; // rcx
  __int64 v37; // rax
  __m128 v38; // xmm0
  __m128 v39; // xmm1
  __m128 v40; // xmm0
  __int64 v41; // rdx
  hkQuaternionf *v42; // rcx
  const char *v43; // rax
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 *v46; // rax
  __m128 v47; // xmm4
  __m128 *v48; // rax
  __m128 v49; // xmm0
  __m128 v50; // xmm1
  __m128 v51; // xmm0
  _QWORD *v52; // rax
  _QWORD *v53; // rcx
  _QWORD *v54; // r8
  unsigned __int64 v55; // rax
  _QWORD *v56; // rcx
  __m128 v57; // [rsp+20h] [rbp-28h] BYREF
  __m128 m_quad; // [rsp+30h] [rbp-18h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtBlendNormal";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  v11 = 0i64;
  if ( paramsIn->m_partitionIndices )
  {
    v12 = 0i64;
    if ( paramsIn->m_numPartitionIndices > 0 )
    {
      v13 = 0i64;
      do
      {
        v14 = &paramsIn->m_skeletonPartitions[paramsIn->m_partitionIndices[v13]];
        m_startBoneIndex = v14->m_startBoneIndex;
        if ( (int)m_startBoneIndex <= (__int16)(v14->m_numBones + m_startBoneIndex - 1) )
        {
          v16 = v12;
          p_m_rotation = &accumulationPoseInOut[m_startBoneIndex].m_rotation;
          do
          {
            m_perBoneWeights = paramsIn->m_perBoneWeights;
            v19 = _mm_shuffle_ps(
                    (__m128)LODWORD(paramsIn->m_masterWeight),
                    (__m128)LODWORD(paramsIn->m_masterWeight),
                    0);
            if ( m_perBoneWeights )
            {
              v20 = 0i64;
              v20.m128_f32[0] = (float)(unsigned __int8)m_perBoneWeights[v12];
              v21 = &v57;
              v57 = _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), (__m128)xmmword_141A71250);
            }
            else
            {
              v21 = &m_quad;
              m_quad = query.m_quad;
            }
            v22 = _mm_mul_ps(v19, *v21);
            m_animationTransformsIn = paramsIn->m_animationTransformsIn;
            ++v12;
            ++v16;
            p_m_rotation += 3;
            p_m_rotation[-4].m_vec.m_quad = _mm_add_ps(
                                              _mm_mul_ps(
                                                paramsIn->m_animationTransformsIn[v16 - 1].m_translation.m_quad,
                                                v22),
                                              p_m_rotation[-4].m_vec.m_quad);
            p_m_rotation[-2].m_vec.m_quad = _mm_add_ps(
                                              _mm_mul_ps(m_animationTransformsIn[v16 - 1].m_scale.m_quad, v22),
                                              p_m_rotation[-2].m_vec.m_quad);
            v24 = _mm_mul_ps(m_animationTransformsIn[v16 - 1].m_rotation.m_vec.m_quad, p_m_rotation[-3].m_vec.m_quad);
            v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 78), v24);
            v26 = _mm_xor_ps(
                    (__m128)_mm_slli_epi32(
                              _mm_srli_epi32(
                                (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 177), v25), (__m128)0i64),
                                0x1Fu),
                              0x1Fu),
                    m_animationTransformsIn[v16 - 1].m_rotation.m_vec.m_quad);
            v27 = (int)m_startBoneIndex;
            LODWORD(m_startBoneIndex) = m_startBoneIndex + 1;
            p_m_rotation[-3].m_vec.m_quad = _mm_add_ps(_mm_mul_ps(v26, v22), p_m_rotation[-3].m_vec.m_quad);
            accumulatedPerBoneWeightsInOut[v27] = _mm_shuffle_ps(
                                                    (__m128)LODWORD(accumulatedPerBoneWeightsInOut[v27]),
                                                    (__m128)LODWORD(accumulatedPerBoneWeightsInOut[v27]),
                                                    0).m128_f32[0]
                                                + v22.m128_f32[0];
          }
          while ( (int)m_startBoneIndex <= (__int16)(v14->m_startBoneIndex + v14->m_numBones - 1) );
        }
        LODWORD(v11) = v11 + 1;
        ++v13;
      }
      while ( (int)v11 < paramsIn->m_numPartitionIndices );
    }
  }
  else
  {
    m_maxTransformTrackIndex = paramsIn->m_maxTransformTrackIndex;
    if ( paramsIn->m_trackToBoneMapping )
    {
      if ( m_maxTransformTrackIndex >= 0 )
      {
        v29 = 0i64;
        do
        {
          v30 = paramsIn->m_trackToBoneMapping[v11];
          if ( v30 >= 0 && (unsigned __int16)v30 < paramsIn->m_numBones )
          {
            v31 = paramsIn->m_perBoneWeights;
            v32 = _mm_shuffle_ps(
                    (__m128)LODWORD(paramsIn->m_masterWeight),
                    (__m128)LODWORD(paramsIn->m_masterWeight),
                    0);
            if ( v31 )
            {
              v33 = 0i64;
              v33.m128_f32[0] = (float)(unsigned __int8)v31[v11];
              p_m_quad = &m_quad;
              m_quad = _mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), (__m128)xmmword_141A71250);
            }
            else
            {
              p_m_quad = &v57;
              v57 = query.m_quad;
            }
            v35 = _mm_mul_ps(v32, *p_m_quad);
            v36 = &paramsIn->m_animationTransformsIn[v29];
            v37 = v30;
            accumulationPoseInOut[v37].m_translation.m_quad = _mm_add_ps(
                                                                _mm_mul_ps(v36->m_translation.m_quad, v35),
                                                                accumulationPoseInOut[v30].m_translation.m_quad);
            accumulationPoseInOut[v37].m_scale.m_quad = _mm_add_ps(
                                                          _mm_mul_ps(v36->m_scale.m_quad, v35),
                                                          accumulationPoseInOut[v30].m_scale.m_quad);
            v38 = _mm_mul_ps(accumulationPoseInOut[v30].m_rotation.m_vec.m_quad, v36->m_rotation.m_vec.m_quad);
            v39 = _mm_add_ps(_mm_shuffle_ps(v38, v38, 78), v38);
            accumulationPoseInOut[v37].m_rotation.m_vec.m_quad = _mm_add_ps(
                                                                   _mm_mul_ps(
                                                                     _mm_xor_ps(
                                                                       (__m128)_mm_slli_epi32(
                                                                                 _mm_srli_epi32(
                                                                                   (__m128i)_mm_cmplt_ps(
                                                                                              _mm_add_ps(
                                                                                                _mm_shuffle_ps(
                                                                                                  v39,
                                                                                                  v39,
                                                                                                  177),
                                                                                                v39),
                                                                                              (__m128)0i64),
                                                                                   0x1Fu),
                                                                                 0x1Fu),
                                                                       v36->m_rotation.m_vec.m_quad),
                                                                     v35),
                                                                   accumulationPoseInOut[v30].m_rotation.m_vec.m_quad);
            v40 = (__m128)LODWORD(accumulatedPerBoneWeightsInOut[v30]);
            accumulatedPerBoneWeightsInOut[v30] = _mm_shuffle_ps(v40, v40, 0).m128_f32[0] + v35.m128_f32[0];
          }
          ++v11;
          ++v29;
        }
        while ( v11 <= m_maxTransformTrackIndex );
      }
    }
    else
    {
      v41 = 0i64;
      if ( m_maxTransformTrackIndex >= 0 )
      {
        v42 = &accumulationPoseInOut->m_rotation;
        do
        {
          v43 = paramsIn->m_perBoneWeights;
          v44 = _mm_shuffle_ps((__m128)LODWORD(paramsIn->m_masterWeight), (__m128)LODWORD(paramsIn->m_masterWeight), 0);
          if ( v43 )
          {
            v45 = 0i64;
            v45.m128_f32[0] = (float)(unsigned __int8)v43[v41];
            v46 = &m_quad;
            m_quad = _mm_mul_ps(_mm_shuffle_ps(v45, v45, 0), (__m128)xmmword_141A71250);
          }
          else
          {
            v46 = &v57;
            v57 = query.m_quad;
          }
          v47 = _mm_mul_ps(v44, *v46);
          v48 = (__m128 *)((char *)&paramsIn->m_animationTransformsIn->m_translation.m_quad
                         + (unsigned __int64)v42
                         - 16
                         - (_QWORD)accumulationPoseInOut);
          v42[-1].m_vec.m_quad = _mm_add_ps(_mm_mul_ps(v47, *v48), v42[-1].m_vec.m_quad);
          v42[1].m_vec.m_quad = _mm_add_ps(_mm_mul_ps(v48[2], v47), v42[1].m_vec.m_quad);
          v49 = _mm_mul_ps(v42->m_vec.m_quad, v48[1]);
          v50 = _mm_add_ps(_mm_shuffle_ps(v49, v49, 78), v49);
          v42->m_vec.m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_xor_ps(
                                    (__m128)_mm_slli_epi32(
                                              _mm_srli_epi32(
                                                (__m128i)_mm_cmplt_ps(
                                                           _mm_add_ps(_mm_shuffle_ps(v50, v50, 177), v50),
                                                           (__m128)0i64),
                                                0x1Fu),
                                              0x1Fu),
                                    v48[1]),
                                  v47),
                                v42->m_vec.m_quad);
          if ( accumulatedPerBoneWeightsInOut )
          {
            v51 = (__m128)LODWORD(accumulatedPerBoneWeightsInOut[(int)v11]);
            accumulatedPerBoneWeightsInOut[(int)v11] = _mm_shuffle_ps(v51, v51, 0).m128_f32[0] + v47.m128_f32[0];
          }
          ++v41;
          LODWORD(v11) = v11 + 1;
          v42 += 3;
        }
        while ( v41 <= m_maxTransformTrackIndex );
      }
    }
  }
  v52 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v53 = (_QWORD *)v52[1];
  v54 = v52;
  if ( (unsigned __int64)v53 < v52[3] )
  {
    *v53 = "Et";
    v55 = __rdtsc();
    v56 = v53 + 2;
    *((_DWORD *)v56 - 2) = v55;
    v54[1] = v56;
  }
}

// File Line: 93
// RVA: 0xB2C7F0
void __fastcall hkaSampleAndCombineUtils::blendNormalFloat(
        hkaSampleAndCombineUtils::FloatBlendParameters *paramsIn,
        float *accumulationInOut,
        float *accumulatedWeightsInOut)
{
  __int64 m_maxFloatTrackIndex; // r11
  int v4; // r9d
  __int64 i; // r10
  __int16 v8; // dx
  const char *m_perFloatTrackWeights; // rax
  float v10; // xmm2_4
  __m128 v11; // xmm0
  __m128 *v12; // rax
  float v13; // xmm2_4
  __int64 v14; // r8
  __m128 v15; // xmm1
  __int64 j; // rdx
  const char *v17; // rax
  float v18; // xmm2_4
  __m128 v19; // xmm0
  __m128 *p_m_quad; // rax
  float v21; // xmm2_4
  __int64 v22; // r8
  __m128 v23; // [rsp+0h] [rbp-28h] BYREF
  __m128 m_quad; // [rsp+10h] [rbp-18h] BYREF

  m_maxFloatTrackIndex = paramsIn->m_maxFloatTrackIndex;
  v4 = 0;
  if ( paramsIn->m_floatTrackToFloatSlotMapping )
  {
    for ( i = 0i64; i <= m_maxFloatTrackIndex; ++v4 )
    {
      v8 = paramsIn->m_floatTrackToFloatSlotMapping[i];
      if ( v8 >= 0 && (unsigned __int16)v8 < paramsIn->m_numFloatSlots )
      {
        m_perFloatTrackWeights = paramsIn->m_perFloatTrackWeights;
        LODWORD(v10) = _mm_shuffle_ps(
                         (__m128)LODWORD(paramsIn->m_masterWeight),
                         (__m128)LODWORD(paramsIn->m_masterWeight),
                         0).m128_u32[0];
        if ( m_perFloatTrackWeights )
        {
          v11 = 0i64;
          v11.m128_f32[0] = (float)(unsigned __int8)m_perFloatTrackWeights[i];
          v12 = &v23;
          v23 = _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), (__m128)xmmword_141A71250);
        }
        else
        {
          v12 = &m_quad;
          m_quad = query.m_quad;
        }
        v13 = v10 * v12->m128_f32[0];
        v14 = v8;
        v15 = (__m128)LODWORD(paramsIn->m_floatTracksIn[v4]);
        accumulationInOut[v14] = (float)(_mm_shuffle_ps(v15, v15, 0).m128_f32[0] * v13)
                               + _mm_shuffle_ps(
                                   (__m128)LODWORD(accumulationInOut[v14]),
                                   (__m128)LODWORD(accumulationInOut[v14]),
                                   0).m128_f32[0];
        accumulatedWeightsInOut[v14] = _mm_shuffle_ps(
                                         (__m128)LODWORD(accumulatedWeightsInOut[v14]),
                                         (__m128)LODWORD(accumulatedWeightsInOut[v14]),
                                         0).m128_f32[0]
                                     + v13;
      }
      ++i;
    }
  }
  else
  {
    for ( j = 0i64; j <= m_maxFloatTrackIndex; ++v4 )
    {
      v17 = paramsIn->m_perFloatTrackWeights;
      LODWORD(v18) = _mm_shuffle_ps(
                       (__m128)LODWORD(paramsIn->m_masterWeight),
                       (__m128)LODWORD(paramsIn->m_masterWeight),
                       0).m128_u32[0];
      if ( v17 )
      {
        v19 = 0i64;
        v19.m128_f32[0] = (float)(unsigned __int8)v17[j];
        p_m_quad = &m_quad;
        m_quad = _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), (__m128)xmmword_141A71250);
      }
      else
      {
        p_m_quad = &v23;
        v23 = query.m_quad;
      }
      v21 = v18 * p_m_quad->m128_f32[0];
      v22 = v4;
      accumulationInOut[v22] = (float)(_mm_shuffle_ps(
                                         (__m128)LODWORD(paramsIn->m_floatTracksIn[v22]),
                                         (__m128)LODWORD(paramsIn->m_floatTracksIn[v22]),
                                         0).m128_f32[0]
                                     * v21)
                             + _mm_shuffle_ps(
                                 (__m128)LODWORD(accumulationInOut[v22]),
                                 (__m128)LODWORD(accumulationInOut[v22]),
                                 0).m128_f32[0];
      if ( accumulatedWeightsInOut )
        accumulatedWeightsInOut[v22] = _mm_shuffle_ps(
                                         (__m128)LODWORD(accumulatedWeightsInOut[v22]),
                                         (__m128)LODWORD(accumulatedWeightsInOut[v22]),
                                         0).m128_f32[0]
                                     + v21;
      ++j;
    }
  }
}

// File Line: 155
// RVA: 0xB2C000
void __fastcall hkaSampleAndCombineUtils::blendAdditive(
        hkaSampleAndCombineUtils::TransformBlendParameters *paramsIn,
        hkQsTransformf *accumulationPoseInOut)
{
  _QWORD *Value; // rax
  _QWORD *v5; // rcx
  _QWORD *v6; // r8
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  __int64 m_maxTransformTrackIndex; // r9
  __int64 v10; // rdx
  __int64 v11; // r9
  __int64 v12; // rdi
  hkaSkeleton::Partition *v13; // r8
  __int64 m_startBoneIndex; // r10
  __int64 v15; // rcx
  hkQuaternionf *p_m_rotation; // r11
  const char *m_perBoneWeights; // rax
  __m128 v18; // xmm8
  __m128 v19; // xmm0
  __m128 *v20; // rax
  __m128 v21; // xmm3
  __m128 v22; // xmm8
  hkQuaternionf v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm6
  __m128 v26; // xmm4
  __m128 v27; // xmm7
  __m128 v28; // xmm7
  __m128 v29; // xmm4
  __m128 v30; // xmm5
  __m128 v31; // xmm3
  __m128 v32; // xmm5
  __m128 v33; // xmm5
  __m128 v34; // xmm0
  __m128 v35; // xmm1
  __m128 v36; // xmm3
  __m128 v37; // xmm0
  __m128 v38; // xmm2
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  __int64 v41; // r8
  __int16 v42; // cx
  const char *v43; // rax
  __m128 v44; // xmm8
  __m128 v45; // xmm0
  __m128 *p_m_quad; // rax
  __m128 v47; // xmm8
  __int64 v48; // rcx
  hkQuaternionf v49; // xmm2
  hkVector4f v50; // xmm3
  __m128 v51; // xmm6
  __m128 v52; // xmm1
  __m128 v53; // xmm4
  __m128 v54; // xmm7
  __m128 v55; // xmm0
  __m128 v56; // xmm3
  hkQuaternionf v57; // xmm2
  __m128 v58; // xmm7
  __m128 v59; // xmm7
  __m128 v60; // xmm4
  __m128 v61; // xmm5
  __m128 v62; // xmm1
  __m128 v63; // xmm3
  __m128 v64; // xmm5
  __m128 v65; // xmm5
  __m128 v66; // xmm0
  __m128 v67; // xmm1
  __m128 v68; // xmm3
  __m128 v69; // xmm0
  __m128 v70; // xmm2
  __m128 v71; // xmm1
  __m128 v72; // xmm2
  __int64 v73; // rcx
  hkQuaternionf *v74; // r8
  const char *v75; // rax
  __m128 v76; // xmm8
  __m128 v77; // xmm0
  __m128 *v78; // rax
  __m128 v79; // xmm3
  __m128 v80; // xmm8
  __m128 *v81; // rax
  __m128 v82; // xmm2
  __m128 v83; // xmm1
  __m128 v84; // xmm6
  __m128 v85; // xmm4
  __m128 v86; // xmm7
  __m128 v87; // xmm7
  __m128 v88; // xmm4
  __m128 v89; // xmm5
  __m128 v90; // xmm3
  __m128 v91; // xmm5
  __m128 v92; // xmm5
  __m128 v93; // xmm0
  __m128 v94; // xmm1
  __m128 v95; // xmm3
  __m128 v96; // xmm0
  __m128 v97; // xmm2
  __m128 v98; // xmm1
  __m128 v99; // xmm2
  _QWORD *v100; // rax
  _QWORD *v101; // rcx
  _QWORD *v102; // r8
  unsigned __int64 v103; // rax
  _QWORD *v104; // rcx
  __m128 v105; // [rsp+20h] [rbp-88h] BYREF
  __m128 m_quad; // [rsp+30h] [rbp-78h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  v6 = Value;
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtBlendAdditive";
    v7 = __rdtsc();
    v8 = v5 + 2;
    *((_DWORD *)v8 - 2) = v7;
    v6[1] = v8;
  }
  m_maxTransformTrackIndex = paramsIn->m_maxTransformTrackIndex;
  v10 = 0i64;
  if ( paramsIn->m_partitionIndices )
  {
    v11 = 0i64;
    if ( paramsIn->m_numPartitionIndices > 0 )
    {
      v12 = 0i64;
      do
      {
        v13 = &paramsIn->m_skeletonPartitions[paramsIn->m_partitionIndices[v12]];
        m_startBoneIndex = v13->m_startBoneIndex;
        if ( (int)m_startBoneIndex <= (__int16)(m_startBoneIndex + v13->m_numBones - 1) )
        {
          v15 = v11;
          p_m_rotation = &accumulationPoseInOut[m_startBoneIndex].m_rotation;
          do
          {
            m_perBoneWeights = paramsIn->m_perBoneWeights;
            v18 = _mm_shuffle_ps(
                    (__m128)LODWORD(paramsIn->m_masterWeight),
                    (__m128)LODWORD(paramsIn->m_masterWeight),
                    0);
            if ( m_perBoneWeights )
            {
              v19 = 0i64;
              v19.m128_f32[0] = (float)(unsigned __int8)m_perBoneWeights[v11];
              v20 = &v105;
              v105 = _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), (__m128)xmmword_141A71250);
            }
            else
            {
              v20 = &m_quad;
              m_quad = query.m_quad;
            }
            v21 = p_m_rotation[-1].m_vec.m_quad;
            v22 = _mm_mul_ps(v18, *v20);
            v23.m_vec.m_quad = (__m128)paramsIn->m_animationTransformsIn[v15].m_rotation;
            v24 = _mm_mul_ps(v21, v23.m_vec.m_quad);
            v25 = _mm_shuffle_ps(v23.m_vec.m_quad, v23.m_vec.m_quad, 255);
            v26 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v23.m_vec.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v23.m_vec.m_quad, v23.m_vec.m_quad, 201), v21));
            v27 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                          _mm_shuffle_ps(v24, v24, 170)),
                        v23.m_vec.m_quad),
                      _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v25, v25), (__m128)xmmword_141A711B0), v21)),
                    _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v25));
            v28 = _mm_add_ps(_mm_add_ps(v27, v27), paramsIn->m_animationTransformsIn[v15].m_translation.m_quad);
            v29 = _mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 255);
            v30 = _mm_sub_ps(
                    _mm_mul_ps(
                      _mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 201),
                      v23.m_vec.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v23.m_vec.m_quad, v23.m_vec.m_quad, 201), p_m_rotation->m_vec.m_quad));
            v31 = _mm_mul_ps(v23.m_vec.m_quad, p_m_rotation->m_vec.m_quad);
            v32 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v30, v30, 201), _mm_mul_ps(v25, p_m_rotation->m_vec.m_quad)),
                    _mm_mul_ps(v29, v23.m_vec.m_quad));
            v33 = _mm_shuffle_ps(
                    v32,
                    _mm_unpackhi_ps(
                      v32,
                      _mm_sub_ps(
                        _mm_mul_ps(v29, v25),
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                          _mm_shuffle_ps(v31, v31, 170)))),
                    196);
            p_m_rotation[1].m_vec.m_quad = _mm_add_ps(
                                             _mm_mul_ps(
                                               _mm_sub_ps(
                                                 _mm_mul_ps(
                                                   paramsIn->m_animationTransformsIn[v15].m_scale.m_quad,
                                                   p_m_rotation[1].m_vec.m_quad),
                                                 p_m_rotation[1].m_vec.m_quad),
                                               v22),
                                             p_m_rotation[1].m_vec.m_quad);
            p_m_rotation[-1].m_vec.m_quad = _mm_add_ps(
                                              _mm_mul_ps(_mm_sub_ps(v28, p_m_rotation[-1].m_vec.m_quad), v22),
                                              p_m_rotation[-1].m_vec.m_quad);
            v34 = _mm_mul_ps(p_m_rotation->m_vec.m_quad, v33);
            v35 = _mm_add_ps(_mm_shuffle_ps(v34, v34, 78), v34);
            LODWORD(m_startBoneIndex) = m_startBoneIndex + 1;
            ++v11;
            ++v15;
            p_m_rotation += 3;
            v36 = _mm_add_ps(
                    _mm_mul_ps(
                      _mm_xor_ps(
                        (__m128)_mm_slli_epi32(
                                  _mm_srli_epi32(
                                    (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v35, v35, 177), v35), (__m128)0i64),
                                    0x1Fu),
                                  0x1Fu),
                        v22),
                      v33),
                    _mm_mul_ps(_mm_sub_ps(query.m_quad, v22), p_m_rotation[-3].m_vec.m_quad));
            v37 = _mm_mul_ps(v36, v36);
            v38 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 78), v37);
            v39 = _mm_add_ps(_mm_shuffle_ps(v38, v38, 177), v38);
            v40 = _mm_rsqrt_ps(v39);
            p_m_rotation[-3].m_vec.m_quad = _mm_mul_ps(
                                              _mm_mul_ps(
                                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v40, v39), v40)),
                                                _mm_mul_ps(*(__m128 *)_xmm, v40)),
                                              v36);
          }
          while ( (int)m_startBoneIndex <= (__int16)(v13->m_startBoneIndex + v13->m_numBones - 1) );
        }
        LODWORD(v10) = v10 + 1;
        ++v12;
      }
      while ( (int)v10 < paramsIn->m_numPartitionIndices );
    }
  }
  else if ( paramsIn->m_trackToBoneMapping )
  {
    if ( (int)m_maxTransformTrackIndex >= 0 )
    {
      v41 = 0i64;
      do
      {
        v42 = paramsIn->m_trackToBoneMapping[v10];
        if ( v42 >= 0 && (unsigned __int16)v42 < paramsIn->m_numBones )
        {
          v43 = paramsIn->m_perBoneWeights;
          v44 = _mm_shuffle_ps((__m128)LODWORD(paramsIn->m_masterWeight), (__m128)LODWORD(paramsIn->m_masterWeight), 0);
          if ( v43 )
          {
            v45 = 0i64;
            v45.m128_f32[0] = (float)(unsigned __int8)v43[v10];
            p_m_quad = &m_quad;
            m_quad = _mm_mul_ps(_mm_shuffle_ps(v45, v45, 0), (__m128)xmmword_141A71250);
          }
          else
          {
            p_m_quad = &v105;
            v105 = query.m_quad;
          }
          v47 = _mm_mul_ps(v44, *p_m_quad);
          v48 = v42;
          v49.m_vec.m_quad = (__m128)paramsIn->m_animationTransformsIn[v41].m_rotation;
          v50.m_quad = (__m128)accumulationPoseInOut[v48].m_translation;
          v51 = _mm_shuffle_ps(v49.m_vec.m_quad, v49.m_vec.m_quad, 255);
          v52 = _mm_mul_ps(v50.m_quad, v49.m_vec.m_quad);
          v53 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v50.m_quad, v50.m_quad, 201), v49.m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v49.m_vec.m_quad, v49.m_vec.m_quad, 201), v50.m_quad));
          v54 = _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                    _mm_shuffle_ps(v52, v52, 170)),
                  v49.m_vec.m_quad);
          v55 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v51, v51), (__m128)xmmword_141A711B0), v50.m_quad);
          v56 = v49.m_vec.m_quad;
          v57.m_vec.m_quad = (__m128)accumulationPoseInOut[v48].m_rotation;
          v58 = _mm_add_ps(_mm_add_ps(v54, v55), _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v51));
          v59 = _mm_add_ps(_mm_add_ps(v58, v58), paramsIn->m_animationTransformsIn[v41].m_translation.m_quad);
          v60 = _mm_shuffle_ps(v57.m_vec.m_quad, v57.m_vec.m_quad, 255);
          v61 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v57.m_vec.m_quad, v57.m_vec.m_quad, 201), v56),
                  _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v57.m_vec.m_quad));
          v62 = _mm_mul_ps(v60, v56);
          v63 = _mm_mul_ps(v56, v57.m_vec.m_quad);
          v64 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v61, v61, 201), _mm_mul_ps(v51, v57.m_vec.m_quad)), v62);
          v65 = _mm_shuffle_ps(
                  v64,
                  _mm_unpackhi_ps(
                    v64,
                    _mm_sub_ps(
                      _mm_mul_ps(v60, v51),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v63, v63, 85), _mm_shuffle_ps(v63, v63, 0)),
                        _mm_shuffle_ps(v63, v63, 170)))),
                  196);
          accumulationPoseInOut[v48].m_scale.m_quad = _mm_add_ps(
                                                        _mm_mul_ps(
                                                          _mm_sub_ps(
                                                            _mm_mul_ps(
                                                              paramsIn->m_animationTransformsIn[v41].m_scale.m_quad,
                                                              accumulationPoseInOut[v48].m_scale.m_quad),
                                                            accumulationPoseInOut[v48].m_scale.m_quad),
                                                          v47),
                                                        accumulationPoseInOut[v48].m_scale.m_quad);
          accumulationPoseInOut[v48].m_translation.m_quad = _mm_add_ps(
                                                              _mm_mul_ps(
                                                                _mm_sub_ps(
                                                                  v59,
                                                                  accumulationPoseInOut[v48].m_translation.m_quad),
                                                                v47),
                                                              accumulationPoseInOut[v48].m_translation.m_quad);
          v66 = _mm_mul_ps(accumulationPoseInOut[v48].m_rotation.m_vec.m_quad, v65);
          v67 = _mm_add_ps(_mm_shuffle_ps(v66, v66, 78), v66);
          v68 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_xor_ps(
                      (__m128)_mm_slli_epi32(
                                _mm_srli_epi32(
                                  (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v67, v67, 177), v67), (__m128)0i64),
                                  0x1Fu),
                                0x1Fu),
                      v47),
                    v65),
                  _mm_mul_ps(_mm_sub_ps(query.m_quad, v47), accumulationPoseInOut[v48].m_rotation.m_vec.m_quad));
          v69 = _mm_mul_ps(v68, v68);
          v70 = _mm_add_ps(_mm_shuffle_ps(v69, v69, 78), v69);
          v71 = _mm_add_ps(_mm_shuffle_ps(v70, v70, 177), v70);
          v72 = _mm_rsqrt_ps(v71);
          accumulationPoseInOut[v48].m_rotation.m_vec.m_quad = _mm_mul_ps(
                                                                 v68,
                                                                 _mm_mul_ps(
                                                                   _mm_sub_ps(
                                                                     (__m128)_xmm,
                                                                     _mm_mul_ps(_mm_mul_ps(v72, v71), v72)),
                                                                   _mm_mul_ps(*(__m128 *)_xmm, v72)));
        }
        ++v10;
        ++v41;
      }
      while ( v10 <= m_maxTransformTrackIndex );
    }
  }
  else if ( (int)m_maxTransformTrackIndex >= 0 )
  {
    v73 = 0i64;
    v74 = &accumulationPoseInOut->m_rotation;
    do
    {
      if ( (int)v10 >= 0 && (unsigned __int16)v10 < paramsIn->m_numBones )
      {
        v75 = paramsIn->m_perBoneWeights;
        v76 = _mm_shuffle_ps((__m128)LODWORD(paramsIn->m_masterWeight), (__m128)LODWORD(paramsIn->m_masterWeight), 0);
        if ( v75 )
        {
          v77 = 0i64;
          v77.m128_f32[0] = (float)(unsigned __int8)v75[v73];
          v78 = &m_quad;
          m_quad = _mm_mul_ps(_mm_shuffle_ps(v77, v77, 0), (__m128)xmmword_141A71250);
        }
        else
        {
          v78 = &v105;
          v105 = query.m_quad;
        }
        v79 = v74[-1].m_vec.m_quad;
        v80 = _mm_mul_ps(v76, *v78);
        v81 = (__m128 *)((char *)&v74->m_vec.m_quad
                       + (unsigned __int64)paramsIn->m_animationTransformsIn
                       - 16
                       - (_QWORD)accumulationPoseInOut);
        v82 = *(__m128 *)((char *)&v74->m_vec.m_quad
                        + (char *)paramsIn->m_animationTransformsIn
                        - (char *)accumulationPoseInOut);
        v83 = _mm_mul_ps(v82, v79);
        v84 = _mm_shuffle_ps(v82, v82, 255);
        v85 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v79, v79, 201), v82), _mm_mul_ps(_mm_shuffle_ps(v82, v82, 201), v79));
        v86 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v83, v83, 85), _mm_shuffle_ps(v83, v83, 0)),
                      _mm_shuffle_ps(v83, v83, 170)),
                    v82),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v84, v84), (__m128)xmmword_141A711B0), v79)),
                _mm_mul_ps(_mm_shuffle_ps(v85, v85, 201), v84));
        v87 = _mm_add_ps(_mm_add_ps(v86, v86), *v81);
        v88 = _mm_shuffle_ps(v74->m_vec.m_quad, v74->m_vec.m_quad, 255);
        v89 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v74->m_vec.m_quad, v74->m_vec.m_quad, 201), v82),
                _mm_mul_ps(_mm_shuffle_ps(v82, v82, 201), v74->m_vec.m_quad));
        v90 = _mm_mul_ps(v82, v74->m_vec.m_quad);
        v91 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v89, v89, 201), _mm_mul_ps(v84, v74->m_vec.m_quad)),
                _mm_mul_ps(v88, v82));
        v92 = _mm_shuffle_ps(
                v91,
                _mm_unpackhi_ps(
                  v91,
                  _mm_sub_ps(
                    _mm_mul_ps(v88, v84),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v90, v90, 85), _mm_shuffle_ps(v90, v90, 0)),
                      _mm_shuffle_ps(v90, v90, 170)))),
                196);
        v74[1].m_vec.m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_sub_ps(_mm_mul_ps(v81[2], v74[1].m_vec.m_quad), v74[1].m_vec.m_quad),
                                  v80),
                                v74[1].m_vec.m_quad);
        v74[-1].m_vec.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v87, v74[-1].m_vec.m_quad), v80), v74[-1].m_vec.m_quad);
        v93 = _mm_mul_ps(v92, v74->m_vec.m_quad);
        v94 = _mm_add_ps(_mm_shuffle_ps(v93, v93, 78), v93);
        v95 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_xor_ps(
                    (__m128)_mm_slli_epi32(
                              _mm_srli_epi32(
                                (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v94, v94, 177), v94), (__m128)0i64),
                                0x1Fu),
                              0x1Fu),
                    v80),
                  v92),
                _mm_mul_ps(_mm_sub_ps(query.m_quad, v80), v74->m_vec.m_quad));
        v96 = _mm_mul_ps(v95, v95);
        v97 = _mm_add_ps(_mm_shuffle_ps(v96, v96, 78), v96);
        v98 = _mm_add_ps(_mm_shuffle_ps(v97, v97, 177), v97);
        v99 = _mm_rsqrt_ps(v98);
        v74->m_vec.m_quad = _mm_mul_ps(
                              v95,
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v99, v98), v99)),
                                _mm_mul_ps(*(__m128 *)_xmm, v99)));
      }
      LODWORD(v10) = v10 + 1;
      ++v73;
      v74 += 3;
    }
    while ( (int)v10 <= (int)m_maxTransformTrackIndex );
  }
  v100 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v101 = (_QWORD *)v100[1];
  v102 = v100;
  if ( (unsigned __int64)v101 < v100[3] )
  {
    *v101 = "Et";
    v103 = __rdtsc();
    v104 = v101 + 2;
    *((_DWORD *)v104 - 2) = v103;
    v102[1] = v104;
  }
}

// File Line: 237
// RVA: 0xB2C9A0
__int64 __fastcall hkaSampleAndCombineUtils::getMaxTrackIndex(
        const __int16 *trackToBoneMapping,
        const char *perTrackWeights,
        unsigned int numBones,
        unsigned int numTracks,
        hkBool hasPartitions)
{
  int v5; // r10d
  __int64 v6; // r9
  bool i; // sf
  __int16 v8; // ax

  if ( !trackToBoneMapping || hasPartitions.m_bool )
  {
    if ( numTracks < numBones )
      numBones = numTracks;
    return numBones - 1;
  }
  else
  {
    v5 = numTracks - 1;
    v6 = (int)(numTracks - 1);
    for ( i = v5 < 0; !i; i = v6 < 0 )
    {
      v8 = trackToBoneMapping[v6];
      if ( v8 >= 0 && v8 < numBones && (!perTrackWeights || perTrackWeights[v6]) )
        return (unsigned int)v5;
      --v5;
      --v6;
    }
    return 0xFFFFFFFFi64;
  }
}

// File Line: 268
// RVA: 0xB2CA00
void __fastcall hkaSampleAndCombineUtils::scaleTranslations(float scaleR, hkQsTransformf *poseInOut, int numTransforms)
{
  __int64 v3; // rax
  __m128 v4; // xmm1

  v3 = numTransforms;
  v4 = _mm_shuffle_ps((__m128)LODWORD(scaleR), (__m128)LODWORD(scaleR), 0);
  if ( numTransforms > 0 )
  {
    do
    {
      ++poseInOut;
      poseInOut[-1].m_translation.m_quad = _mm_mul_ps(v4, poseInOut[-1].m_translation.m_quad);
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 277
// RVA: 0xB2CA40
void __fastcall hkaSampleAndCombineUtils::copyReferencePose(
        hkQsTransformf *bonesOut,
        float *floatsOut,
        hkaSkeleton *skeleton)
{
  hkaSampleAndCombineUtils::copyReferencePose(
    bonesOut,
    floatsOut,
    skeleton->m_referencePose.m_data,
    skeleton->m_bones.m_size,
    skeleton->m_referenceFloats.m_data,
    skeleton->m_floatSlots.m_size);
}

// File Line: 286
// RVA: 0xB2CA70
void __fastcall hkaSampleAndCombineUtils::copyReferencePose(
        hkQsTransformf *bonesOut,
        float *floatsOut,
        hkQsTransformf *referencePose,
        unsigned int numBones,
        const float *referenceFloats,
        signed int numFloats)
{
  unsigned int v6; // eax
  unsigned __int64 *v8; // r9
  signed __int64 v9; // r11
  __int64 v10; // rbx
  int v11; // edx
  int v12; // r8d
  int v13; // eax
  const float *v14; // rax
  signed __int64 v15; // r10
  __int64 v16; // rdx
  int v17; // ecx

  v6 = 3 * numBones;
  if ( (int)(3 * numBones) > 0 )
  {
    v8 = &bonesOut->m_translation.m_quad.m128_u64[1];
    v9 = (char *)referencePose - (char *)bonesOut;
    v10 = v6;
    do
    {
      v11 = *(_DWORD *)((char *)v8 + v9);
      v12 = *(_DWORD *)((char *)v8 + v9 + 4);
      v13 = *(_DWORD *)((char *)v8 + v9 - 8);
      *((_DWORD *)v8 - 1) = *(_DWORD *)((char *)v8 + v9 - 4);
      *(_DWORD *)v8 = v11;
      *((_DWORD *)v8 + 1) = v12;
      *((_DWORD *)v8 - 2) = v13;
      v8 += 2;
      --v10;
    }
    while ( v10 );
  }
  v14 = referenceFloats;
  if ( numFloats > 0 )
  {
    v15 = (char *)floatsOut - (char *)referenceFloats;
    v16 = (unsigned int)numFloats;
    do
    {
      v17 = *(_DWORD *)v14++;
      *(_DWORD *)((char *)v14 + v15 - 4) = v17;
      --v16;
    }
    while ( v16 );
  }
}


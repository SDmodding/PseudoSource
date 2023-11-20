// File Line: 22
// RVA: 0xB2BBD0
void __fastcall hkaSampleAndCombineUtils::blendNormal(hkaSampleAndCombineUtils::TransformBlendParameters *paramsIn, hkQsTransformf *accumulationPoseInOut, float *accumulatedPerBoneWeightsInOut)
{
  hkaSampleAndCombineUtils::TransformBlendParameters *v3; // rbx
  float *v4; // rsi
  hkQsTransformf *v5; // rbp
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r8
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  __int64 v11; // r8
  signed __int64 v12; // rdx
  __int64 v13; // rdi
  signed __int64 v14; // rcx
  __int64 v15; // r9
  signed __int64 v16; // r10
  signed __int64 v17; // r11
  const char *v18; // rax
  __m128 v19; // xmm4
  __m128 v20; // xmm0
  __m128 *v21; // rax
  __m128 v22; // xmm4
  hkQsTransformf *v23; // rax
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  __int64 v27; // rax
  __int64 v28; // r10
  __int64 v29; // r9
  __int64 v30; // rdx
  const char *v31; // rax
  __m128 v32; // xmm5
  __m128 v33; // xmm0
  __m128 *v34; // rax
  __m128 v35; // xmm5
  __m128 *v36; // rcx
  signed __int64 v37; // rax
  __m128 v38; // xmm0
  __m128 v39; // xmm1
  __m128 v40; // xmm0
  __int64 v41; // rdx
  __m128 *v42; // rcx
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
  signed __int64 v56; // rcx
  __m128 v57; // [rsp+20h] [rbp-28h]
  __m128 v58; // [rsp+30h] [rbp-18h]

  v3 = paramsIn;
  v4 = accumulatedPerBoneWeightsInOut;
  v5 = accumulationPoseInOut;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtBlendNormal";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = 0i64;
  if ( v3->m_partitionIndices )
  {
    v12 = 0i64;
    if ( v3->m_numPartitionIndices > 0 )
    {
      v13 = 0i64;
      do
      {
        v14 = (signed __int64)&v3->m_skeletonPartitions[v3->m_partitionIndices[v13]];
        v15 = *(signed __int16 *)(v14 + 8);
        if ( (signed int)v15 <= (signed __int16)(*(_WORD *)(v14 + 10) + v15 - 1) )
        {
          v16 = v12;
          v17 = (signed __int64)&v5[v15].m_rotation;
          do
          {
            v18 = v3->m_perBoneWeights;
            v19 = _mm_shuffle_ps((__m128)LODWORD(v3->m_masterWeight), (__m128)LODWORD(v3->m_masterWeight), 0);
            if ( v18 )
            {
              v20 = 0i64;
              v20.m128_f32[0] = (float)(unsigned __int8)v18[v12];
              v21 = &v57;
              v57 = _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), (__m128)xmmword_141A71250);
            }
            else
            {
              v21 = &v58;
              v58 = query.m_quad;
            }
            v22 = _mm_mul_ps(v19, *v21);
            v23 = v3->m_animationTransformsIn;
            ++v12;
            ++v16;
            v17 += 48i64;
            *(__m128 *)(v17 - 64) = _mm_add_ps(
                                      _mm_mul_ps(v3->m_animationTransformsIn[v16 - 1].m_translation.m_quad, v22),
                                      *(__m128 *)(v17 - 64));
            *(__m128 *)(v17 - 32) = _mm_add_ps(_mm_mul_ps(*((__m128 *)&v23[v16] - 1), v22), *(__m128 *)(v17 - 32));
            v24 = _mm_mul_ps(*((__m128 *)&v23[v16] - 2), *(__m128 *)(v17 - 48));
            v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 78), v24);
            v26 = _mm_xor_ps(
                    (__m128)_mm_slli_epi32(
                              _mm_srli_epi32(
                                (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 177), v25), (__m128)0i64),
                                0x1Fu),
                              0x1Fu),
                    *((__m128 *)&v23[v16] - 2));
            v27 = (signed int)v15;
            LODWORD(v15) = v15 + 1;
            *(__m128 *)(v17 - 48) = _mm_add_ps(_mm_mul_ps(v26, v22), *(__m128 *)(v17 - 48));
            v4[v27] = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v4[v27]), (__m128)LODWORD(v4[v27]), 0))
                    + v22.m128_f32[0];
          }
          while ( (signed int)v15 <= (signed __int16)(*(_WORD *)(v14 + 8) + *(_WORD *)(v14 + 10) - 1) );
        }
        LODWORD(v11) = v11 + 1;
        ++v13;
      }
      while ( (signed int)v11 < v3->m_numPartitionIndices );
    }
  }
  else
  {
    v28 = v3->m_maxTransformTrackIndex;
    if ( v3->m_trackToBoneMapping )
    {
      if ( v28 >= 0 )
      {
        v29 = 0i64;
        do
        {
          LOWORD(v30) = v3->m_trackToBoneMapping[v11];
          if ( (v30 & 0x8000u) == 0i64 && (unsigned __int16)v30 < v3->m_numBones )
          {
            v31 = v3->m_perBoneWeights;
            v32 = _mm_shuffle_ps((__m128)LODWORD(v3->m_masterWeight), (__m128)LODWORD(v3->m_masterWeight), 0);
            if ( v31 )
            {
              v33 = 0i64;
              v33.m128_f32[0] = (float)(unsigned __int8)v31[v11];
              v34 = &v58;
              v58 = _mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), (__m128)xmmword_141A71250);
            }
            else
            {
              v34 = &v57;
              v57 = query.m_quad;
            }
            v35 = _mm_mul_ps(v32, *v34);
            v30 = (signed __int16)v30;
            v36 = &v3->m_animationTransformsIn[v29].m_translation.m_quad;
            v37 = (signed __int16)v30;
            v5[v37].m_translation.m_quad = _mm_add_ps(
                                             _mm_mul_ps(*v36, v35),
                                             v5[(signed __int16)v30].m_translation.m_quad);
            v5[v37].m_scale.m_quad = _mm_add_ps(_mm_mul_ps(v36[2], v35), v5[(signed __int16)v30].m_scale.m_quad);
            v38 = _mm_mul_ps(v5[(signed __int16)v30].m_rotation.m_vec.m_quad, v36[1]);
            v39 = _mm_add_ps(_mm_shuffle_ps(v38, v38, 78), v38);
            v5[v37].m_rotation.m_vec.m_quad = _mm_add_ps(
                                                _mm_mul_ps(
                                                  _mm_xor_ps(
                                                    (__m128)_mm_slli_epi32(
                                                              _mm_srli_epi32(
                                                                (__m128i)_mm_cmpltps(
                                                                           _mm_add_ps(
                                                                             _mm_shuffle_ps(v39, v39, 177),
                                                                             v39),
                                                                           (__m128)0i64),
                                                                0x1Fu),
                                                              0x1Fu),
                                                    v36[1]),
                                                  v35),
                                                v5[(signed __int16)v30].m_rotation.m_vec.m_quad);
            v40 = (__m128)LODWORD(v4[(signed __int16)v30]);
            v4[v30] = COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 0)) + v35.m128_f32[0];
          }
          ++v11;
          ++v29;
        }
        while ( v11 <= v28 );
      }
    }
    else
    {
      v41 = 0i64;
      if ( v28 >= 0 )
      {
        v42 = &v5->m_rotation.m_vec.m_quad;
        do
        {
          v43 = v3->m_perBoneWeights;
          v44 = _mm_shuffle_ps((__m128)LODWORD(v3->m_masterWeight), (__m128)LODWORD(v3->m_masterWeight), 0);
          if ( v43 )
          {
            v45 = 0i64;
            v45.m128_f32[0] = (float)(unsigned __int8)v43[v41];
            v46 = &v58;
            v58 = _mm_mul_ps(_mm_shuffle_ps(v45, v45, 0), (__m128)xmmword_141A71250);
          }
          else
          {
            v46 = &v57;
            v57 = query.m_quad;
          }
          v47 = _mm_mul_ps(v44, *v46);
          v48 = (__m128 *)((char *)&v3->m_animationTransformsIn->m_translation.m_quad
                         + (unsigned __int64)((char *)v42 - 16i64 - (_QWORD)v5));
          v42[-1] = _mm_add_ps(_mm_mul_ps(v47, *v48), v42[-1]);
          v42[1] = _mm_add_ps(_mm_mul_ps(v48[2], v47), v42[1]);
          v49 = _mm_mul_ps(*v42, v48[1]);
          v50 = _mm_add_ps(_mm_shuffle_ps(v49, v49, 78), v49);
          *v42 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_xor_ps(
                       (__m128)_mm_slli_epi32(
                                 _mm_srli_epi32(
                                   (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v50, v50, 177), v50), (__m128)0i64),
                                   0x1Fu),
                                 0x1Fu),
                       v48[1]),
                     v47),
                   *v42);
          if ( v4 )
          {
            v51 = (__m128)LODWORD(v4[(signed int)v11]);
            v4[(signed int)v11] = COERCE_FLOAT(_mm_shuffle_ps(v51, v51, 0)) + v47.m128_f32[0];
          }
          ++v41;
          LODWORD(v11) = v11 + 1;
          v42 += 3;
        }
        while ( v41 <= v28 );
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
    v56 = (signed __int64)(v53 + 2);
    *(_DWORD *)(v56 - 8) = v55;
    v54[1] = v56;
  }
}

// File Line: 93
// RVA: 0xB2C7F0
void __fastcall hkaSampleAndCombineUtils::blendNormalFloat(hkaSampleAndCombineUtils::FloatBlendParameters *paramsIn, float *accumulationInOut, float *accumulatedWeightsInOut)
{
  __int64 v3; // r11
  int v4; // er9
  float *v5; // rbx
  float *v6; // rdi
  __int64 i; // r10
  __int16 v8; // dx
  const char *v9; // rax
  float v10; // xmm2_4
  __m128 v11; // xmm0
  __m128 *v12; // rax
  float v13; // xmm2_4
  signed __int64 v14; // r8
  __m128 v15; // xmm1
  __int64 j; // rdx
  const char *v17; // rax
  float v18; // xmm2_4
  __m128 v19; // xmm0
  __m128 *v20; // rax
  float v21; // xmm2_4
  unsigned __int64 v22; // r8
  __m128 v23; // [rsp+0h] [rbp-28h]
  __m128 v24; // [rsp+10h] [rbp-18h]

  v3 = paramsIn->m_maxFloatTrackIndex;
  v4 = 0;
  v5 = accumulatedWeightsInOut;
  v6 = accumulationInOut;
  if ( paramsIn->m_floatTrackToFloatSlotMapping )
  {
    for ( i = 0i64; i <= v3; ++v4 )
    {
      v8 = paramsIn->m_floatTrackToFloatSlotMapping[i];
      if ( v8 >= 0 && (unsigned __int16)v8 < paramsIn->m_numFloatSlots )
      {
        v9 = paramsIn->m_perFloatTrackWeights;
        LODWORD(v10) = (unsigned __int128)_mm_shuffle_ps(
                                            (__m128)LODWORD(paramsIn->m_masterWeight),
                                            (__m128)LODWORD(paramsIn->m_masterWeight),
                                            0);
        if ( v9 )
        {
          v11 = 0i64;
          v11.m128_f32[0] = (float)(unsigned __int8)v9[i];
          v12 = &v23;
          v23 = _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), (__m128)xmmword_141A71250);
        }
        else
        {
          v12 = &v24;
          v24 = query.m_quad;
        }
        v13 = v10 * *(float *)v12->m128_u64;
        v14 = v8;
        v15 = (__m128)LODWORD(paramsIn->m_floatTracksIn[v4]);
        v6[v14] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 0)) * v13)
                + COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v6[v14]), (__m128)LODWORD(v6[v14]), 0));
        v5[v14] = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v5[v14]), (__m128)LODWORD(v5[v14]), 0)) + v13;
      }
      ++i;
    }
  }
  else
  {
    for ( j = 0i64; j <= v3; ++v4 )
    {
      v17 = paramsIn->m_perFloatTrackWeights;
      LODWORD(v18) = (unsigned __int128)_mm_shuffle_ps(
                                          (__m128)LODWORD(paramsIn->m_masterWeight),
                                          (__m128)LODWORD(paramsIn->m_masterWeight),
                                          0);
      if ( v17 )
      {
        v19 = 0i64;
        v19.m128_f32[0] = (float)(unsigned __int8)v17[j];
        v20 = &v24;
        v24 = _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), (__m128)xmmword_141A71250);
      }
      else
      {
        v20 = &v23;
        v23 = query.m_quad;
      }
      v21 = v18 * *(float *)v20->m128_u64;
      v22 = v4;
      v6[v22] = (float)(COERCE_FLOAT(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(paramsIn->m_floatTracksIn[v22]),
                            (__m128)LODWORD(paramsIn->m_floatTracksIn[v22]),
                            0))
                      * v21)
              + COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v6[v22]), (__m128)LODWORD(v6[v22]), 0));
      if ( v5 )
        v5[v22] = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v5[v22]), (__m128)LODWORD(v5[v22]), 0)) + v21;
      ++j;
    }
  }
}

// File Line: 155
// RVA: 0xB2C000
void __fastcall hkaSampleAndCombineUtils::blendAdditive(hkaSampleAndCombineUtils::TransformBlendParameters *paramsIn, hkQsTransformf *accumulationPoseInOut)
{
  hkaSampleAndCombineUtils::TransformBlendParameters *v2; // rbx
  hkQsTransformf *v3; // rsi
  _QWORD *v4; // rax
  _QWORD *v5; // rcx
  _QWORD *v6; // r8
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  __int64 v9; // r9
  __int64 v10; // rdx
  signed __int64 v11; // r9
  __int64 v12; // rdi
  signed __int64 v13; // r8
  __int64 v14; // r10
  signed __int64 v15; // rcx
  __m128 *v16; // r11
  const char *v17; // rax
  __m128 v18; // xmm8
  __m128 v19; // xmm0
  __m128 *v20; // rax
  __m128 v21; // xmm3
  __m128 v22; // xmm8
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm6
  __m128 v26; // xmm4
  __m128 v27; // xmm0
  __m128 v28; // xmm3
  __m128 v29; // xmm7
  __m128 v30; // xmm7
  __m128 v31; // xmm4
  __m128 v32; // xmm5
  __m128 v33; // xmm1
  __m128 v34; // xmm3
  __m128 v35; // xmm5
  __m128 v36; // xmm5
  __m128 v37; // xmm0
  __m128 v38; // xmm1
  __m128 v39; // xmm3
  __m128 v40; // xmm0
  __m128 v41; // xmm2
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __int64 v44; // r8
  __int16 v45; // cx
  const char *v46; // rax
  __m128 v47; // xmm8
  __m128 v48; // xmm0
  __m128 *v49; // rax
  __m128 v50; // xmm8
  signed __int64 v51; // rcx
  __m128 v52; // xmm2
  __m128 v53; // xmm3
  __m128 v54; // xmm6
  __m128 v55; // xmm1
  __m128 v56; // xmm4
  __m128 v57; // xmm7
  __m128 v58; // xmm0
  __m128 v59; // xmm3
  __m128 v60; // xmm2
  __m128 v61; // xmm7
  __m128 v62; // xmm7
  __m128 v63; // xmm4
  __m128 v64; // xmm5
  __m128 v65; // xmm1
  __m128 v66; // xmm3
  __m128 v67; // xmm5
  __m128 v68; // xmm5
  __m128 v69; // xmm0
  __m128 v70; // xmm1
  __m128 v71; // xmm3
  __m128 v72; // xmm0
  __m128 v73; // xmm2
  __m128 v74; // xmm1
  __m128 v75; // xmm2
  __int64 v76; // rcx
  __m128 *v77; // r8
  const char *v78; // rax
  __m128 v79; // xmm8
  __m128 v80; // xmm0
  __m128 *v81; // rax
  __m128 v82; // xmm3
  __m128 v83; // xmm8
  __m128 *v84; // rax
  __m128 v85; // xmm2
  __m128 v86; // xmm1
  __m128 v87; // xmm6
  __m128 v88; // xmm4
  __m128 v89; // xmm0
  __m128 v90; // xmm3
  __m128 v91; // xmm7
  __m128 v92; // xmm7
  __m128 v93; // xmm4
  __m128 v94; // xmm5
  __m128 v95; // xmm1
  __m128 v96; // xmm3
  __m128 v97; // xmm5
  __m128 v98; // xmm5
  __m128 v99; // xmm0
  __m128 v100; // xmm1
  __m128 v101; // xmm3
  __m128 v102; // xmm0
  __m128 v103; // xmm2
  __m128 v104; // xmm1
  __m128 v105; // xmm2
  _QWORD *v106; // rax
  _QWORD *v107; // rcx
  _QWORD *v108; // r8
  unsigned __int64 v109; // rax
  signed __int64 v110; // rcx
  __m128 v111; // [rsp+20h] [rbp-88h]
  __m128 v112; // [rsp+30h] [rbp-78h]

  v2 = paramsIn;
  v3 = accumulationPoseInOut;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  v6 = v4;
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtBlendAdditive";
    v7 = __rdtsc();
    v8 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v8 - 8) = v7;
    v6[1] = v8;
  }
  v9 = v2->m_maxTransformTrackIndex;
  v10 = 0i64;
  if ( v2->m_partitionIndices )
  {
    v11 = 0i64;
    if ( v2->m_numPartitionIndices > 0 )
    {
      v12 = 0i64;
      do
      {
        v13 = (signed __int64)&v2->m_skeletonPartitions[v2->m_partitionIndices[v12]];
        v14 = *(signed __int16 *)(v13 + 8);
        if ( (signed int)v14 <= (signed __int16)(v14 + *(_WORD *)(v13 + 10) - 1) )
        {
          v15 = v11;
          v16 = &v3[v14].m_rotation.m_vec.m_quad;
          do
          {
            v17 = v2->m_perBoneWeights;
            v18 = _mm_shuffle_ps((__m128)LODWORD(v2->m_masterWeight), (__m128)LODWORD(v2->m_masterWeight), 0);
            if ( v17 )
            {
              v19 = 0i64;
              v19.m128_f32[0] = (float)(unsigned __int8)v17[v11];
              v20 = &v111;
              v111 = _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), (__m128)xmmword_141A71250);
            }
            else
            {
              v20 = &v112;
              v112 = query.m_quad;
            }
            v21 = v16[-1];
            v22 = _mm_mul_ps(v18, *v20);
            v23 = v2->m_animationTransformsIn[v15].m_rotation.m_vec.m_quad;
            v24 = _mm_mul_ps(v16[-1], v23);
            v25 = _mm_shuffle_ps(v2->m_animationTransformsIn[v15].m_rotation.m_vec.m_quad, v23, 255);
            v26 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v23),
                    _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v21));
            v27 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v25, v25), (__m128)xmmword_141A711B0), v21);
            v28 = v2->m_animationTransformsIn[v15].m_rotation.m_vec.m_quad;
            v29 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                          _mm_shuffle_ps(v24, v24, 170)),
                        v23),
                      v27),
                    _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v25));
            v30 = _mm_add_ps(_mm_add_ps(v29, v29), v2->m_animationTransformsIn[v15].m_translation.m_quad);
            v31 = _mm_shuffle_ps(*v16, *v16, 255);
            v32 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*v16, *v16, 201), v28),
                    _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), *v16));
            v33 = _mm_mul_ps(v31, v28);
            v34 = _mm_mul_ps(v28, *v16);
            v35 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v32, v32, 201), _mm_mul_ps(v25, *v16)), v33);
            v36 = _mm_shuffle_ps(
                    v35,
                    _mm_unpackhi_ps(
                      v35,
                      _mm_sub_ps(
                        _mm_mul_ps(v31, v25),
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                          _mm_shuffle_ps(v34, v34, 170)))),
                    196);
            v16[1] = _mm_add_ps(
                       _mm_mul_ps(
                         _mm_sub_ps(_mm_mul_ps(v2->m_animationTransformsIn[v15].m_scale.m_quad, v16[1]), v16[1]),
                         v22),
                       v16[1]);
            v16[-1] = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v30, v16[-1]), v22), v16[-1]);
            v37 = _mm_mul_ps(*v16, v36);
            v38 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 78), v37);
            LODWORD(v14) = v14 + 1;
            ++v11;
            ++v15;
            v16 += 3;
            v39 = _mm_add_ps(
                    _mm_mul_ps(
                      _mm_xor_ps(
                        (__m128)_mm_slli_epi32(
                                  _mm_srli_epi32(
                                    (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v38, v38, 177), v38), (__m128)0i64),
                                    0x1Fu),
                                  0x1Fu),
                        v22),
                      v36),
                    _mm_mul_ps(_mm_sub_ps(query.m_quad, v22), v16[-3]));
            v40 = _mm_mul_ps(v39, v39);
            v41 = _mm_add_ps(_mm_shuffle_ps(v40, v40, 78), v40);
            v42 = _mm_add_ps(_mm_shuffle_ps(v41, v41, 177), v41);
            v43 = _mm_rsqrt_ps(v42);
            v16[-3] = _mm_mul_ps(
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v43, v42), v43)),
                          _mm_mul_ps(*(__m128 *)_xmm, v43)),
                        v39);
          }
          while ( (signed int)v14 <= (signed __int16)(*(_WORD *)(v13 + 8) + *(_WORD *)(v13 + 10) - 1) );
        }
        LODWORD(v10) = v10 + 1;
        ++v12;
      }
      while ( (signed int)v10 < v2->m_numPartitionIndices );
    }
  }
  else if ( v2->m_trackToBoneMapping )
  {
    if ( (signed int)v9 >= 0 )
    {
      v44 = 0i64;
      do
      {
        v45 = v2->m_trackToBoneMapping[v10];
        if ( v45 >= 0 && (unsigned __int16)v45 < v2->m_numBones )
        {
          v46 = v2->m_perBoneWeights;
          v47 = _mm_shuffle_ps((__m128)LODWORD(v2->m_masterWeight), (__m128)LODWORD(v2->m_masterWeight), 0);
          if ( v46 )
          {
            v48 = 0i64;
            v48.m128_f32[0] = (float)(unsigned __int8)v46[v10];
            v49 = &v112;
            v112 = _mm_mul_ps(_mm_shuffle_ps(v48, v48, 0), (__m128)xmmword_141A71250);
          }
          else
          {
            v49 = &v111;
            v111 = query.m_quad;
          }
          v50 = _mm_mul_ps(v47, *v49);
          v51 = v45;
          v52 = v2->m_animationTransformsIn[v44].m_rotation.m_vec.m_quad;
          v53 = v3[v51].m_translation.m_quad;
          v54 = _mm_shuffle_ps(v2->m_animationTransformsIn[v44].m_rotation.m_vec.m_quad, v52, 255);
          v55 = _mm_mul_ps(v3[v51].m_translation.m_quad, v52);
          v56 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v52),
                  _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v53));
          v57 = _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                    _mm_shuffle_ps(v55, v55, 170)),
                  v52);
          v58 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v54, v54), (__m128)xmmword_141A711B0), v53);
          v59 = v2->m_animationTransformsIn[v44].m_rotation.m_vec.m_quad;
          v60 = v3[v51].m_rotation.m_vec.m_quad;
          v61 = _mm_add_ps(_mm_add_ps(v57, v58), _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v54));
          v62 = _mm_add_ps(_mm_add_ps(v61, v61), v2->m_animationTransformsIn[v44].m_translation.m_quad);
          v63 = _mm_shuffle_ps(v3[v51].m_rotation.m_vec.m_quad, v3[v51].m_rotation.m_vec.m_quad, 255);
          v64 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v60, v60, 201), v59),
                  _mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v60));
          v65 = _mm_mul_ps(v63, v59);
          v66 = _mm_mul_ps(v59, v60);
          v67 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v64, v64, 201), _mm_mul_ps(v54, v60)), v65);
          v68 = _mm_shuffle_ps(
                  v67,
                  _mm_unpackhi_ps(
                    v67,
                    _mm_sub_ps(
                      _mm_mul_ps(v63, v54),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v66, v66, 85), _mm_shuffle_ps(v66, v66, 0)),
                        _mm_shuffle_ps(v66, v66, 170)))),
                  196);
          v3[v51].m_scale.m_quad = _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_sub_ps(
                                         _mm_mul_ps(
                                           v2->m_animationTransformsIn[v44].m_scale.m_quad,
                                           v3[v51].m_scale.m_quad),
                                         v3[v51].m_scale.m_quad),
                                       v50),
                                     v3[v51].m_scale.m_quad);
          v3[v51].m_translation.m_quad = _mm_add_ps(
                                           _mm_mul_ps(_mm_sub_ps(v62, v3[v51].m_translation.m_quad), v50),
                                           v3[v51].m_translation.m_quad);
          v69 = _mm_mul_ps(v3[v51].m_rotation.m_vec.m_quad, v68);
          v70 = _mm_add_ps(_mm_shuffle_ps(v69, v69, 78), v69);
          v71 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_xor_ps(
                      (__m128)_mm_slli_epi32(
                                _mm_srli_epi32(
                                  (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v70, v70, 177), v70), (__m128)0i64),
                                  0x1Fu),
                                0x1Fu),
                      v50),
                    v68),
                  _mm_mul_ps(_mm_sub_ps(query.m_quad, v50), v3[v51].m_rotation.m_vec.m_quad));
          v72 = _mm_mul_ps(v71, v71);
          v73 = _mm_add_ps(_mm_shuffle_ps(v72, v72, 78), v72);
          v74 = _mm_add_ps(_mm_shuffle_ps(v73, v73, 177), v73);
          v75 = _mm_rsqrt_ps(v74);
          v3[v51].m_rotation.m_vec.m_quad = _mm_mul_ps(
                                              v71,
                                              _mm_mul_ps(
                                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v75, v74), v75)),
                                                _mm_mul_ps(*(__m128 *)_xmm, v75)));
        }
        ++v10;
        ++v44;
      }
      while ( v10 <= v9 );
    }
  }
  else if ( (signed int)v9 >= 0 )
  {
    v76 = 0i64;
    v77 = &v3->m_rotation.m_vec.m_quad;
    do
    {
      if ( (signed int)v10 >= 0 && (unsigned __int16)v10 < v2->m_numBones )
      {
        v78 = v2->m_perBoneWeights;
        v79 = _mm_shuffle_ps((__m128)LODWORD(v2->m_masterWeight), (__m128)LODWORD(v2->m_masterWeight), 0);
        if ( v78 )
        {
          v80 = 0i64;
          v80.m128_f32[0] = (float)(unsigned __int8)v78[v76];
          v81 = &v112;
          v112 = _mm_mul_ps(_mm_shuffle_ps(v80, v80, 0), (__m128)xmmword_141A71250);
        }
        else
        {
          v81 = &v111;
          v111 = query.m_quad;
        }
        v82 = v77[-1];
        v83 = _mm_mul_ps(v79, *v81);
        v84 = (__m128 *)((char *)v77 + (unsigned __int64)((char *)v2->m_animationTransformsIn - 16i64 - (_QWORD)v3));
        v85 = *(__m128 *)((char *)v77 + (char *)v2->m_animationTransformsIn - (char *)v3);
        v86 = _mm_mul_ps(*(__m128 *)((char *)v77 + (char *)v2->m_animationTransformsIn - (char *)v3), v82);
        v87 = _mm_shuffle_ps(*(__m128 *)((char *)v77 + (char *)v2->m_animationTransformsIn - (char *)v3), v85, 255);
        v88 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v82, v82, 201), v85), _mm_mul_ps(_mm_shuffle_ps(v85, v85, 201), v82));
        v89 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v87, v87), (__m128)xmmword_141A711B0), v82);
        v90 = *(__m128 *)((char *)v77 + (char *)v2->m_animationTransformsIn - (char *)v3);
        v91 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v86, v86, 85), _mm_shuffle_ps(v86, v86, 0)),
                      _mm_shuffle_ps(v86, v86, 170)),
                    v85),
                  v89),
                _mm_mul_ps(_mm_shuffle_ps(v88, v88, 201), v87));
        v92 = _mm_add_ps(_mm_add_ps(v91, v91), *v84);
        v93 = _mm_shuffle_ps(*v77, *v77, 255);
        v94 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(*v77, *v77, 201), v90),
                _mm_mul_ps(_mm_shuffle_ps(v90, v90, 201), *v77));
        v95 = _mm_mul_ps(v93, v90);
        v96 = _mm_mul_ps(v90, *v77);
        v97 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v94, v94, 201), _mm_mul_ps(v87, *v77)), v95);
        v98 = _mm_shuffle_ps(
                v97,
                _mm_unpackhi_ps(
                  v97,
                  _mm_sub_ps(
                    _mm_mul_ps(v93, v87),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v96, v96, 85), _mm_shuffle_ps(v96, v96, 0)),
                      _mm_shuffle_ps(v96, v96, 170)))),
                196);
        v77[1] = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v84[2], v77[1]), v77[1]), v83), v77[1]);
        v77[-1] = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v92, v77[-1]), v83), v77[-1]);
        v99 = _mm_mul_ps(v98, *v77);
        v100 = _mm_add_ps(_mm_shuffle_ps(v99, v99, 78), v99);
        v101 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(
                                 (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v100, v100, 177), v100), (__m128)0i64),
                                 0x1Fu),
                               0x1Fu),
                     v83),
                   v98),
                 _mm_mul_ps(_mm_sub_ps(query.m_quad, v83), *v77));
        v102 = _mm_mul_ps(v101, v101);
        v103 = _mm_add_ps(_mm_shuffle_ps(v102, v102, 78), v102);
        v104 = _mm_add_ps(_mm_shuffle_ps(v103, v103, 177), v103);
        v105 = _mm_rsqrt_ps(v104);
        *v77 = _mm_mul_ps(
                 v101,
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v105, v104), v105)),
                   _mm_mul_ps(*(__m128 *)_xmm, v105)));
      }
      LODWORD(v10) = v10 + 1;
      ++v76;
      v77 += 3;
    }
    while ( (signed int)v10 <= (signed int)v9 );
  }
  v106 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v107 = (_QWORD *)v106[1];
  v108 = v106;
  if ( (unsigned __int64)v107 < v106[3] )
  {
    *v107 = "Et";
    v109 = __rdtsc();
    v110 = (signed __int64)(v107 + 2);
    *(_DWORD *)(v110 - 8) = v109;
    v108[1] = v110;
  }
}

// File Line: 237
// RVA: 0xB2C9A0
signed __int64 __fastcall hkaSampleAndCombineUtils::getMaxTrackIndex(const __int16 *trackToBoneMapping, const char *perTrackWeights, unsigned int numBones, unsigned int numTracks, hkBool hasPartitions)
{
  unsigned int v5; // er10
  __int64 v6; // r9
  bool i; // sf
  __int16 v8; // ax
  signed __int64 result; // rax

  if ( !trackToBoneMapping || hasPartitions.m_bool )
  {
    if ( numTracks < numBones )
      numBones = numTracks;
    result = numBones - 1;
  }
  else
  {
    v5 = numTracks - 1;
    v6 = (signed int)(numTracks - 1);
    for ( i = (v5 & 0x80000000) != 0; !i; i = v6 < 0 )
    {
      v8 = trackToBoneMapping[v6];
      if ( v8 >= 0 && v8 < numBones && (!perTrackWeights || perTrackWeights[v6]) )
        return v5;
      --v5;
      --v6;
    }
    result = 0xFFFFFFFFi64;
  }
  return result;
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
void __fastcall hkaSampleAndCombineUtils::copyReferencePose(hkQsTransformf *bonesOut, float *floatsOut, hkaSkeleton *skeleton)
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
void __fastcall hkaSampleAndCombineUtils::copyReferencePose(hkQsTransformf *bonesOut, float *floatsOut, hkQsTransformf *referencePose, unsigned int numBones, const float *referenceFloats, unsigned int numFloats)
{
  unsigned int v6; // eax
  float *v7; // r10
  int *v8; // r9
  signed __int64 v9; // r11
  __int64 v10; // rbx
  int v11; // edx
  int v12; // er8
  int v13; // eax
  const float *v14; // rax
  signed __int64 v15; // r10
  __int64 v16; // rdx
  int v17; // ecx

  v6 = 3 * numBones;
  v7 = floatsOut;
  if ( (signed int)(3 * numBones) > 0 )
  {
    v8 = &bonesOut->m_translation.m_quad.m128_i32[2];
    v9 = (char *)referencePose - (char *)bonesOut;
    v10 = v6;
    do
    {
      v11 = *(int *)((char *)v8 + v9);
      v12 = *(int *)((char *)v8 + v9 + 4);
      v13 = *(int *)((char *)v8 + v9 - 8);
      *(v8 - 1) = *(int *)((char *)v8 + v9 - 4);
      *v8 = v11;
      v8[1] = v12;
      *(v8 - 2) = v13;
      v8 += 4;
      --v10;
    }
    while ( v10 );
  }
  v14 = referenceFloats;
  if ( (signed int)numFloats > 0 )
  {
    v15 = (char *)v7 - (char *)referenceFloats;
    v16 = numFloats;
    do
    {
      v17 = *(_DWORD *)v14;
      ++v14;
      *(_DWORD *)((char *)v14 + v15 - 4) = v17;
      --v16;
    }
    while ( v16 );
  }
}


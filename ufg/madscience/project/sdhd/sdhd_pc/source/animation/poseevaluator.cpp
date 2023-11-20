// File Line: 167
// RVA: 0x3A73A0
void __usercall PoseEvaluator::EvaluatePoseLocalSpace(PoseEvaluator *this@<rcx>, PoseRecipe *recipe@<rdx>, hkQsTransformf *transforms@<r8>, __m128 *a4@<xmm4>)
{
  __int64 v4; // rsi
  hkQsTransformf *v5; // r13
  signed int v6; // eax
  PoseRecipe *v7; // r12
  PoseEvaluator *v8; // rbp
  __int64 v9; // r15
  signed __int64 v10; // r14
  PoseRecipe::PoseStackEntry *v11; // r8
  PoseRecipe::PoseDescType v12; // edx
  hkQsTransformf *v13; // rbx
  hkVector4f v14; // xmm0
  hkQuaternionf v15; // xmm1
  hkVector4f v16; // xmm2
  hkQsTransformf *v17; // rdx
  __int64 v18; // rcx
  __m128 *v19; // rax
  hkQsTransformf **v20; // rax
  hkQsTransformf *v21; // rbx
  int v22; // eax
  signed int v23; // er9
  __int64 v24; // rsi
  hkQsTransformf *v25; // rbx
  __int64 v26; // rsi
  hkQsTransformf *v27; // rdi
  bool v28; // cl
  int v29; // eax
  signed int v30; // er9
  __int64 v31; // rsi
  bool v32; // cl
  int v33; // eax
  signed int v34; // er9
  __int64 v35; // rsi
  __int64 v36; // rsi
  hkQsTransformf *v37; // rbx
  hkQsTransformf *outputLocalSpace[69]; // [rsp+30h] [rbp-228h]

  v4 = 0i64;
  v5 = transforms;
  v6 = recipe->mStackCount - 1;
  v7 = recipe;
  v8 = this;
  v9 = v6;
  if ( v6 >= 0 )
  {
    v10 = v6;
    do
    {
      v11 = v7->mPoseStack;
      v12 = v11[v10].mType;
      switch ( v12 )
      {
        case 0:
          v13 = v8->mScratchBuffers.mStack[--v8->mScratchBuffers.mStackDepth];
          UFG::qMemCopy(
            v8->mScratchBuffers.mStack[v8->mScratchBuffers.mStackDepth],
            v7->mSkelDesc.mReferencePose,
            48 * v7->mSkelDesc.mBoneCount);
          outputLocalSpace[v4] = v13;
          v4 = (unsigned int)(v4 + 1);
          break;
        case 1:
          --v8->mScratchBuffers.mStackDepth;
          v14.m_quad = (__m128)hkQsTransformf_identityStorage.m_translation;
          v15.m_vec.m_quad = (__m128)hkQsTransformf_identityStorage.m_rotation;
          v16.m_quad = (__m128)hkQsTransformf_identityStorage.m_scale;
          v17 = v8->mScratchBuffers.mStack[v8->mScratchBuffers.mStackDepth];
          v18 = v7->mSkelDesc.mBoneCount;
          if ( (_DWORD)v18 )
          {
            v19 = &v17->m_scale.m_quad;
            do
            {
              v19[-2] = v14.m_quad;
              v19[-1] = v15.m_vec.m_quad;
              *(hkVector4f *)v19 = (hkVector4f)v16.m_quad;
              v19 += 3;
              --v18;
            }
            while ( v18 );
          }
          outputLocalSpace[v4] = v17;
          v4 = (unsigned int)(v4 + 1);
          break;
        case 2:
          --v8->mScratchBuffers.mStackDepth;
          v20 = v8->mScratchBuffers.mStack;
          v21 = v20[v8->mScratchBuffers.mStackDepth];
          PoseEvaluator::EvaluateAnim(
            v8,
            v7,
            &v7->mAnimData[v11[v10].mAnim.mIndex],
            v20[v8->mScratchBuffers.mStackDepth]);
          outputLocalSpace[v4] = v21;
          v4 = (unsigned int)(v4 + 1);
          break;
        case 3:
        case 4:
          v22 = v7->mBoneUpdateCount;
          v23 = v7->mSkelDesc.mBoneCount;
          v24 = (unsigned int)(v4 - 1);
          v25 = outputLocalSpace[v24];
          v26 = (unsigned int)(v24 - 1);
          v27 = outputLocalSpace[v26];
          v28 = v12 == 4;
          if ( v22 >= 0 && v22 < v23 )
            v23 = v7->mBoneUpdateCount;
          if ( (!v8->mMemoryStreamer || v28) && v28 )
            PoseEvaluator::BlendPoseWeightSet(v8, v25, outputLocalSpace[v26], v23, a4, v11[v10].mBlend.mPerBoneWeights);
          else
            PoseEvaluator::BlendPose(v8, v25, outputLocalSpace[v26], v23, *(float *)&v11[v10].mAnim.mIndex);
          goto LABEL_31;
        case 5:
        case 6:
          v29 = v7->mBoneUpdateCount;
          v30 = v7->mSkelDesc.mBoneCount;
          v31 = (unsigned int)(v4 - 1);
          v25 = outputLocalSpace[v31];
          v26 = (unsigned int)(v31 - 1);
          v27 = outputLocalSpace[v26];
          v32 = v12 == 6;
          if ( v29 >= 0 && v29 < v30 )
            v30 = v7->mBoneUpdateCount;
          if ( (!v8->mMemoryStreamer || v32) && v32 )
            PoseEvaluator::BlendPoseAddWeightSet(v8, v25, outputLocalSpace[v26], v30, v11[v10].mBlend.mPerBoneWeights);
          else
            PoseEvaluator::BlendPoseAdd(v8, v25, outputLocalSpace[v26], v30, *(float *)&v11[v10].mAnim.mIndex);
          goto LABEL_31;
        case 7:
        case 8:
          v33 = v7->mBoneUpdateCount;
          v34 = v7->mSkelDesc.mBoneCount;
          v35 = (unsigned int)(v4 - 1);
          v25 = outputLocalSpace[v35];
          v26 = (unsigned int)(v35 - 1);
          v27 = outputLocalSpace[v26];
          if ( v33 >= 0 && v33 < v34 )
            v34 = v7->mBoneUpdateCount;
          PoseEvaluator::BlendPoseSub(v8, v25, outputLocalSpace[v26], v34, *(float *)&v11[v10].mAnim.mIndex);
          goto LABEL_31;
        case 9:
          v36 = (unsigned int)(v4 - 1);
          v25 = outputLocalSpace[v36];
          v26 = (unsigned int)(v36 - 1);
          v27 = outputLocalSpace[v26];
          PoseEvaluator::EvaluateBlendAccum(v8, v7, (PoseRecipe::BlendDesc *)&v11[v10].8, v25, outputLocalSpace[v26]);
LABEL_31:
          outputLocalSpace[v26] = v25;
          v8->mScratchBuffers.mStack[v8->mScratchBuffers.mStackDepth] = v27;
          v4 = (unsigned int)(v26 + 1);
          ++v8->mScratchBuffers.mStackDepth;
          break;
        default:
          break;
      }
      --v10;
      --v9;
    }
    while ( v9 >= 0 );
  }
  v37 = outputLocalSpace[(unsigned int)(v4 - 1)];
  UFG::qMemCopy(v5, outputLocalSpace[(unsigned int)(v4 - 1)], 48 * v7->mSkelDesc.mBoneCount);
  v8->mScratchBuffers.mStack[v8->mScratchBuffers.mStackDepth++] = v37;
}

// File Line: 268
// RVA: 0x14BCBE0
void dynamic_initializer_for__aabbMinStart__()
{
  aabbMinStart.m_quad = (__m128)_xmm;
}

// File Line: 269
// RVA: 0x14BCBD0
void dynamic_initializer_for__aabbMaxStart__()
{
  aabbMaxStart.m_quad = (__m128)_xmm;
}

// File Line: 272
// RVA: 0x3A76C0
void __usercall PoseEvaluator::EvaluatePoseModelSpace(PoseEvaluator *this@<rcx>, PoseRecipe *recipe@<rdx>, hkQsTransformf *transforms@<r8>, UFG::qVector3 *aabbMin@<r9>, __m128 *a5@<xmm4>, UFG::qVector3 *aabbMax)
{
  UFG::qVector3 *v6; // rdi
  hkQsTransformf *v7; // rsi
  PoseRecipe *v8; // rbx
  unsigned int v9; // ebp
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  __m128 *v12; // rcx
  __int64 v13; // rdx
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  __m128 v18; // [rsp+20h] [rbp-28h]
  hkVector4f v19; // [rsp+30h] [rbp-18h]

  v6 = aabbMin;
  v7 = transforms;
  v8 = recipe;
  PoseEvaluator::EvaluatePoseLocalSpace(this, recipe, transforms, a5);
  v9 = v8->mSkelDesc.mBoneCount;
  hkaSkeletonUtils::transformLocalPoseToModelPose(
    v8->mSkelDesc.mBoneCount,
    (const __int16 *)v8->mSkelDesc.mParentIndices,
    v7,
    v7);
  v10 = aabbMinStart.m_quad;
  v11 = aabbMaxStart.m_quad;
  v18 = aabbMinStart.m_quad;
  v19.m_quad = aabbMaxStart.m_quad;
  if ( v9 > 1 )
  {
    v12 = &v7[1].m_translation.m_quad;
    v13 = v9 - 1;
    do
    {
      v14 = *v12;
      v12 += 3;
      v15 = v14;
      v16 = _mm_max_ps(v14, v11);
      v17 = _mm_min_ps(v15, v10);
      v11 = v16;
      v10 = v17;
      --v13;
    }
    while ( v13 );
    v18 = v17;
    v19.m_quad = v16;
  }
  *(_QWORD *)&v6->x = v18.m128_u64[0];
  v6->z = v18.m128_f32[2];
  *(_QWORD *)&aabbMax->x = v19.m_quad.m128_u64[0];
  aabbMax->z = v19.m_quad.m128_f32[2];
}

// File Line: 328
// RVA: 0x3A6ED0
void __fastcall PoseEvaluator::EvaluateAnim(PoseEvaluator *this, PoseRecipe *recipe, PoseRecipe::AnimData *anim, hkQsTransformf *pose)
{
  PoseEvaluator *v4; // r13
  __int64 v5; // rcx
  hkQsTransformf *v6; // rbp
  PoseRecipe::AnimData *v7; // rbx
  PoseRecipe *v8; // r12
  hkVector4f v9; // xmm0
  hkQuaternionf v10; // xmm1
  hkVector4f v11; // xmm2
  __m128 *v12; // rax
  unsigned __int16 *v13; // rsi
  hkaAnimation::DataChunk *chunks; // r14
  signed int v15; // er15
  signed int v16; // eax
  float v17; // xmm0_4
  hkQsTransformf **v18; // rax
  hkQsTransformf *transformTracksOut; // rdx
  unsigned int v20; // er15
  unsigned int v21; // edi
  float v22; // xmm2_4
  char v23; // r14
  hkVector4f *v24; // rdx
  unsigned int v25; // er8
  char v26; // r10
  signed __int64 v27; // rcx
  hkVector4f v28; // xmm0
  unsigned __int8 v29; // al
  float v30; // xmm1_4
  hkVector4f v31; // ST50_16
  char v32; // al
  signed __int64 v33; // rcx
  hkVector4f v34; // ST50_16
  char v35; // [rsp+A0h] [rbp+8h]
  unsigned int v36; // [rsp+A8h] [rbp+10h]
  hkQsTransformf *v37; // [rsp+B0h] [rbp+18h]

  v4 = this;
  v5 = recipe->mSkelDesc.mBoneCount;
  v6 = pose;
  v7 = anim;
  v8 = recipe;
  v36 = recipe->mSkelDesc.mBoneCount;
  if ( anim->mBlendHint == 1 )
  {
    v9.m_quad = (__m128)hkQsTransformf_identityStorage.m_translation;
    v10.m_vec.m_quad = (__m128)hkQsTransformf_identityStorage.m_rotation;
    v11.m_quad = (__m128)hkQsTransformf_identityStorage.m_scale;
    if ( !(_DWORD)v5 )
      goto LABEL_8;
    v12 = &pose->m_scale.m_quad;
    do
    {
      v12[-2] = v9.m_quad;
      v12[-1] = v10.m_vec.m_quad;
      *(hkVector4f *)v12 = (hkVector4f)v11.m_quad;
      v12 += 3;
      --v5;
    }
    while ( v5 );
  }
  else
  {
    UFG::qMemCopy(pose, recipe->mSkelDesc.mReferencePose, 48 * v5);
  }
  LODWORD(v5) = v36;
LABEL_8:
  v13 = v7->mTrackToBoneIndices;
  v4->mMemoryStreamer;
  chunks = v7->mDataChunks;
  v15 = hkaSampleAndCombineUtils::getMaxTrackIndex(
          (const __int16 *)v7->mTrackToBoneIndices,
          0i64,
          v5,
          (unsigned __int8)v7->mNumTransformTracks,
          0);
  if ( v15 > 200 )
    v15 = 200;
  v16 = v8->mBoneUpdateCount;
  if ( v16 >= 0 )
  {
    v17 = (float)v16;
    if ( (float)v16 >= (float)v15 )
      v17 = (float)v15;
    v15 = (signed int)v17;
  }
  --v4->mScratchBuffers.mStackDepth;
  v18 = v4->mScratchBuffers.mStack;
  transformTracksOut = v18[v4->mScratchBuffers.mStackDepth];
  v20 = v15 + 1;
  v21 = 0;
  v37 = v18[v4->mScratchBuffers.mStackDepth];
  switch ( v7->mAnimType )
  {
    case 1:
      hkaInterleavedUncompressedAnimation::samplePartialWithDataChunks(
        v7->mFrameIndex,
        v7->mFrameDelta,
        v20,
        transformTracksOut,
        0,
        0i64,
        chunks,
        (unsigned __int8)v7->mNumDataChunks);
      break;
    case 3:
      hkaSplineCompressedAnimation::samplePartialWithDataChunks(
        v7->mFrameIndex,
        v7->mFrameDelta,
        v20,
        transformTracksOut,
        0,
        0i64,
        chunks,
        (unsigned __int8)v7->mNumDataChunks);
      break;
    case 4:
      hkaQuantizedAnimation::samplePartialWithDataChunks(
        v7->mFrameIndex,
        v7->mFrameDelta,
        v20,
        0,
        v8->mSkelDesc.mReferencePose,
        0i64,
        chunks,
        (unsigned __int8)v7->mNumDataChunks,
        transformTracksOut,
        0i64);
      break;
    case 5:
      hkaPredictiveCompressedAnimation::samplePartialWithDataChunks(
        v7->mFrameIndex,
        v7->mFrameDelta,
        v20,
        0,
        v8->mSkelDesc.mReferencePose,
        0i64,
        chunks,
        (unsigned __int8)v7->mNumDataChunks,
        transformTracksOut,
        0i64);
      break;
    default:
      goto LABEL_23;
  }
  transformTracksOut = v37;
LABEL_23:
  v22 = *(float *)&FLOAT_1_0;
  v35 = 0;
  v23 = v8->mFlags & 1;
  if ( v20 == -1 || !transformTracksOut || !v20 )
    goto LABEL_46;
  v24 = &transformTracksOut->m_scale;
  do
  {
    if ( v7->mTrackToBoneIndices )
      v25 = (signed __int16)*v13;
    else
      v25 = v21;
    if ( v25 < v36 )
    {
      if ( v7->mBlendHint == 1 )
      {
        v33 = v25;
        v6[v33].m_translation = (hkVector4f)v24[-2].m_quad;
        v6[v33].m_rotation.m_vec = (hkVector4f)v24[-1].m_quad;
        v6[v33].m_scale = (hkVector4f)v24->m_quad;
      }
      else
      {
        if ( !v8->mSkelDesc.mBones[v25].m_lockTranslation.m_bool || v23 )
        {
          v28.m_quad = (__m128)v24[-2];
          v26 = 0;
          v27 = v25;
        }
        else
        {
          v26 = 1;
          v27 = v25;
          v28.m_quad = (__m128)v8->mSkelDesc.mReferencePose[v25].m_translation;
        }
        v6[v27].m_translation = (hkVector4f)v28.m_quad;
        v6[v27].m_rotation.m_vec = (hkVector4f)v24[-1].m_quad;
        v6[v27].m_scale = (hkVector4f)v24->m_quad;
        v29 = v7->mRootRetargetIndex;
        if ( v29 != -1 )
        {
          if ( v26 )
          {
            if ( v25 == v29 )
            {
              LODWORD(v30) = v24[-2].m_quad.m128_i32[0] & _xmm;
              if ( v30 > 0.001 )
              {
                v32 = 1;
                v35 = 1;
                v31.m_quad = (__m128)v8->mSkelDesc.mReferencePose[v27].m_translation;
                v22 = v30 / COERCE_FLOAT(v31.m_quad.m128_i32[0] & _xmm);
                goto LABEL_43;
              }
            }
          }
        }
      }
    }
    v32 = v35;
LABEL_43:
    ++v21;
    ++v13;
    v24 += 3;
  }
  while ( v21 < v20 );
  if ( v32 )
  {
    v34.m_quad = (__m128)v6->m_translation;
    v34.m_quad.m128_f32[2] = v6->m_translation.m_quad.m128_f32[2] / v22;
    v6->m_translation = (hkVector4f)v34.m_quad;
  }
LABEL_46:
  v4->mScratchBuffers.mStack[v4->mScratchBuffers.mStackDepth++] = v37;
}

// File Line: 581
// RVA: 0x3A7270
void __fastcall PoseEvaluator::EvaluateBlendAccum(PoseEvaluator *this, PoseRecipe *recipe, PoseRecipe::BlendDesc *blend, hkQsTransformf *pose1, hkQsTransformf *pose2)
{
  hkQuaternionf *v5; // rcx
  __int64 v6; // rdx
  signed __int64 v7; // rax
  __m128 v8; // xmm1
  __m128 v9; // xmm4
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2

  if ( recipe->mSkelDesc.mBoneCount )
  {
    v5 = &pose1->m_rotation;
    v6 = recipe->mSkelDesc.mBoneCount;
    v7 = (char *)pose2 - (char *)pose1;
    do
    {
      v8 = *(__m128 *)((char *)&v5[1].m_vec.m_quad + v7);
      v5 += 3;
      v9 = _mm_shuffle_ps((__m128)LODWORD(blend->mWeight), (__m128)LODWORD(blend->mWeight), 0);
      v5[-2].m_vec.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v8, v5[-2].m_vec.m_quad), v9), v5[-2].m_vec.m_quad);
      v5[-4].m_vec.m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_sub_ps(*(__m128 *)((char *)&v5[-4].m_vec.m_quad + v7), v5[-4].m_vec.m_quad),
                                v9),
                              v5[-4].m_vec.m_quad);
      v10 = _mm_mul_ps(*(__m128 *)((char *)&v5[-3].m_vec.m_quad + v7), v5[-3].m_vec.m_quad);
      v11 = _mm_add_ps(_mm_shuffle_ps(v10, v10, 78), v10);
      v12 = _mm_add_ps(
              _mm_mul_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32(
                              (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 177), v11), (__m128)0i64),
                              0x1Fu),
                            0x1Fu),
                  v9),
                *(__m128 *)((char *)&v5[-3].m_vec.m_quad + v7)),
              _mm_mul_ps(_mm_sub_ps(query.m_quad, v9), v5[-3].m_vec.m_quad));
      v13 = _mm_mul_ps(v12, v12);
      v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
      v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14);
      v16 = _mm_rsqrt_ps(v15);
      v5[-3].m_vec.m_quad = _mm_mul_ps(
                              v12,
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
                                _mm_mul_ps(*(__m128 *)_xmm, v16)));
      v5[-2] = (hkQuaternionf)_xmm;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 595
// RVA: 0x3A4090
void __fastcall PoseEvaluator::BlendPose(PoseEvaluator *this, hkQsTransformf *outputLocalSpace, hkQsTransformf *posePose, unsigned int numBones, float weight)
{
  signed __int64 v5; // r8
  hkQuaternionf *v6; // rax
  signed __int64 v7; // rcx
  __m128 v8; // xmm5
  __m128 v9; // xmm1
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2

  if ( (signed int)(numBones - 1) >= 0 )
  {
    v5 = (char *)posePose - (char *)outputLocalSpace;
    v6 = &outputLocalSpace->m_rotation;
    v7 = (signed int)(numBones - 1) + 1i64;
    v8 = _mm_shuffle_ps((__m128)LODWORD(weight), (__m128)LODWORD(weight), 0);
    do
    {
      v9 = *(__m128 *)((char *)&v6[1].m_vec.m_quad + v5);
      v6 += 3;
      v6[-2].m_vec.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v9, v6[-2].m_vec.m_quad), v8), v6[-2].m_vec.m_quad);
      v6[-4].m_vec.m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_sub_ps(*(__m128 *)((char *)&v6[-4].m_vec.m_quad + v5), v6[-4].m_vec.m_quad),
                                v8),
                              v6[-4].m_vec.m_quad);
      v10 = _mm_mul_ps(*(__m128 *)((char *)&v6[-3].m_vec.m_quad + v5), v6[-3].m_vec.m_quad);
      v11 = _mm_add_ps(_mm_shuffle_ps(v10, v10, 78), v10);
      v12 = _mm_add_ps(
              _mm_mul_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32(
                              (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 177), v11), (__m128)0i64),
                              0x1Fu),
                            0x1Fu),
                  v8),
                *(__m128 *)((char *)&v6[-3].m_vec.m_quad + v5)),
              _mm_mul_ps(_mm_sub_ps(query.m_quad, v8), v6[-3].m_vec.m_quad));
      v13 = _mm_mul_ps(v12, v12);
      v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
      v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14);
      v16 = _mm_rsqrt_ps(v15);
      v6[-3].m_vec.m_quad = _mm_mul_ps(
                              v12,
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
                                _mm_mul_ps(*(__m128 *)_xmm, v16)));
      v6[-2] = (hkQuaternionf)_xmm;
      --v7;
    }
    while ( v7 );
  }
  hkQsTransform_fasterRenormalizeBatch(outputLocalSpace, numBones);
}

// File Line: 609
// RVA: 0x3A48B0
void __usercall PoseEvaluator::BlendPoseWeightSet(PoseEvaluator *this@<rcx>, hkQsTransformf *outputLocalSpace@<rdx>, hkQsTransformf *posePose@<r8>, unsigned int numBones@<r9d>, __m128 a5@<xmm4>, const float *perBoneWeights)
{
  hkQsTransformf *v6; // r10
  signed __int64 v7; // rdx
  signed __int64 v8; // rax
  char *v9; // r8
  float v10; // xmm0_4
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  __m128 v13; // xmm1
  __m128 v14; // xmm5
  __m128 v15; // xmm0
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm2

  v6 = outputLocalSpace;
  v7 = 0i64;
  if ( (signed int)(numBones - 1) >= 0 )
  {
    v8 = (signed __int64)&v6->m_rotation;
    v9 = (char *)((char *)posePose - (char *)v6);
    do
    {
      v10 = perBoneWeights[v7];
      v11 = *(__m128 *)&v9[v8 + 16];
      ++v7;
      v8 += 48i64;
      a5.m128_f32[0] = v10 * 0.0039215689;
      a5 = _mm_shuffle_ps(a5, a5, 0);
      *(__m128 *)(v8 - 32) = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v11, *(__m128 *)(v8 - 32)), a5), *(__m128 *)(v8 - 32));
      *(__m128 *)(v8 - 64) = _mm_add_ps(
                               _mm_mul_ps(_mm_sub_ps(*(__m128 *)&v9[v8 - 64], *(__m128 *)(v8 - 64)), a5),
                               *(__m128 *)(v8 - 64));
      v12 = _mm_mul_ps(*(__m128 *)&v9[v8 - 48], *(__m128 *)(v8 - 48));
      v13 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 78), v12);
      v14 = _mm_add_ps(
              _mm_mul_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32(
                              (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 177), v13), (__m128)0i64),
                              0x1Fu),
                            0x1Fu),
                  a5),
                *(__m128 *)&v9[v8 - 48]),
              _mm_mul_ps(_mm_sub_ps(query.m_quad, a5), *(__m128 *)(v8 - 48)));
      v15 = _mm_mul_ps(v14, v14);
      v16 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 78), v15);
      v17 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 177), v16);
      v18 = _mm_rsqrt_ps(v17);
      *(__m128 *)(v8 - 48) = _mm_mul_ps(
                               v14,
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                                 _mm_mul_ps(*(__m128 *)_xmm, v18)));
      *(_OWORD *)(v8 - 32) = _xmm;
    }
    while ( v7 <= (signed int)(numBones - 1) );
  }
  hkQsTransform_fasterRenormalizeBatch(v6, numBones);
}

// File Line: 623
// RVA: 0x3A41E0
void __fastcall PoseEvaluator::BlendPoseAdd(PoseEvaluator *this, hkQsTransformf *outputLocalSpace, hkQsTransformf *posePose, unsigned int numBones, float weight)
{
  hkQsTransformf *v5; // r10
  __m128 *v6; // rdx
  signed __int64 v7; // rax
  signed __int64 v8; // rcx
  __m128 v9; // xmm8
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm6
  __m128 v14; // xmm0
  __m128 v15; // xmm2
  __m128 v16; // xmm7
  __m128 v17; // xmm7
  __m128 v18; // xmm3
  __m128 v19; // xmm5
  __m128 v20; // xmm2
  __m128 v21; // xmm5
  __m128 v22; // xmm5
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  __m128 v25; // xmm3
  __m128 v26; // xmm0
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  __m128 v29; // xmm2

  v5 = outputLocalSpace;
  if ( (signed int)(numBones - 1) >= 0 )
  {
    v6 = &posePose->m_rotation.m_vec.m_quad;
    v7 = (char *)v5 - (char *)posePose;
    v8 = (signed int)(numBones - 1) + 1i64;
    v9 = _mm_shuffle_ps((__m128)LODWORD(weight), (__m128)LODWORD(weight), 0);
    do
    {
      v10 = *(__m128 *)((char *)v6 + v7 - 16);
      v11 = _mm_mul_ps(*(__m128 *)((char *)v6 + v7 - 16), *v6);
      v12 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), *v6), _mm_mul_ps(_mm_shuffle_ps(*v6, *v6, 201), v10));
      v13 = _mm_shuffle_ps(*v6, *v6, 255);
      v14 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0), v10);
      v15 = *(__m128 *)((char *)v6 + v7);
      v16 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                    _mm_shuffle_ps(v11, v11, 170)),
                  *v6),
                v14),
              _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v13));
      v17 = _mm_add_ps(_mm_add_ps(v16, v16), v6[-1]);
      v18 = _mm_shuffle_ps(*(__m128 *)((char *)v6 + v7), v15, 255);
      v19 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), *v6), _mm_mul_ps(_mm_shuffle_ps(*v6, *v6, 201), v15));
      v20 = _mm_mul_ps(v15, *v6);
      v21 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v19, v19, 201), _mm_mul_ps(*(__m128 *)((char *)v6 + v7), v13)),
              _mm_mul_ps(*v6, v18));
      v22 = _mm_shuffle_ps(
              v21,
              _mm_unpackhi_ps(
                v21,
                _mm_sub_ps(
                  _mm_mul_ps(v18, v13),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                    _mm_shuffle_ps(v20, v20, 170)))),
              196);
      *(__m128 *)((char *)v6 + v7 + 16) = _mm_add_ps(
                                            _mm_mul_ps(
                                              _mm_sub_ps(
                                                _mm_mul_ps(v6[1], *(__m128 *)((char *)v6 + v7 + 16)),
                                                *(__m128 *)((char *)v6 + v7 + 16)),
                                              v9),
                                            *(__m128 *)((char *)v6 + v7 + 16));
      *(__m128 *)((char *)v6 + v7 - 16) = _mm_add_ps(
                                            _mm_mul_ps(_mm_sub_ps(v17, *(__m128 *)((char *)v6 + v7 - 16)), v9),
                                            *(__m128 *)((char *)v6 + v7 - 16));
      v23 = _mm_mul_ps(*(__m128 *)((char *)v6 + v7), v22);
      v24 = _mm_add_ps(_mm_shuffle_ps(v23, v23, 78), v23);
      v6 += 3;
      v25 = _mm_add_ps(
              _mm_mul_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32(
                              (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v24, v24, 177), v24), (__m128)0i64),
                              0x1Fu),
                            0x1Fu),
                  v9),
                v22),
              _mm_mul_ps(_mm_sub_ps(query.m_quad, v9), *(__m128 *)((char *)v6 + v7 - 48)));
      v26 = _mm_mul_ps(v25, v25);
      v27 = _mm_add_ps(_mm_shuffle_ps(v26, v26, 78), v26);
      v28 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 177), v27);
      v29 = _mm_rsqrt_ps(v28);
      *(__m128 *)((char *)v6 + v7 - 48) = _mm_mul_ps(
                                            v25,
                                            _mm_mul_ps(
                                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
                                              _mm_mul_ps(*(__m128 *)_xmm, v29)));
      --v8;
    }
    while ( v8 );
  }
  hkQsTransform_fasterRenormalizeBatch(v5, numBones);
}

// File Line: 635
// RVA: 0x3A4410
void __fastcall PoseEvaluator::BlendPoseAddWeightSet(PoseEvaluator *this, hkQsTransformf *outputLocalSpace, hkQsTransformf *posePose, unsigned int numBones, const float *perBoneWeights)
{
  signed __int64 v5; // r11
  hkQsTransformf *v6; // r10
  __m128 *v7; // rdx
  signed __int64 v8; // rax
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm6
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm7
  __m128 v16; // xmm7
  __m128 v17; // xmm3
  __m128 v18; // xmm5
  __m128 v19; // xmm2
  __m128 v20; // xmm5
  __m128 v21; // xmm3
  __m128 v22; // xmm5
  __m128 v23; // xmm3
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  __m128 v26; // xmm4
  __m128 v27; // xmm0
  __m128 v28; // xmm2
  __m128 v29; // xmm1
  __m128 v30; // xmm2

  v5 = 0i64;
  v6 = outputLocalSpace;
  if ( (signed int)(numBones - 1) >= 0 )
  {
    v7 = &posePose->m_rotation.m_vec.m_quad;
    v8 = (char *)v6 - (char *)posePose;
    do
    {
      v9 = *(__m128 *)((char *)v7 + v8 - 16);
      v10 = _mm_mul_ps(*(__m128 *)((char *)v7 + v8 - 16), *v7);
      v11 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), *v7), _mm_mul_ps(_mm_shuffle_ps(*v7, *v7, 201), v9));
      v12 = _mm_shuffle_ps(*v7, *v7, 255);
      v13 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v12, v12), (__m128)xmmword_141A711B0), v9);
      v14 = *(__m128 *)((char *)v7 + v8);
      v15 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                    _mm_shuffle_ps(v10, v10, 170)),
                  *v7),
                v13),
              _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v12));
      v16 = _mm_add_ps(_mm_add_ps(v15, v15), v7[-1]);
      v17 = _mm_shuffle_ps(*(__m128 *)((char *)v7 + v8), v14, 255);
      v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), *v7), _mm_mul_ps(_mm_shuffle_ps(*v7, *v7, 201), v14));
      v19 = _mm_mul_ps(v14, *v7);
      v20 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v18, v18, 201), _mm_mul_ps(*(__m128 *)((char *)v7 + v8), v12)),
              _mm_mul_ps(*v7, v17));
      v21 = _mm_sub_ps(
              _mm_mul_ps(v17, v12),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                _mm_shuffle_ps(v19, v19, 170)));
      v22 = _mm_shuffle_ps(v20, _mm_unpackhi_ps(v20, v21), 196);
      v21.m128_f32[0] = perBoneWeights[v5] * 0.0039215689;
      v23 = _mm_shuffle_ps(v21, v21, 0);
      *(__m128 *)((char *)v7 + v8 + 16) = _mm_add_ps(
                                            _mm_mul_ps(
                                              _mm_sub_ps(
                                                _mm_mul_ps(v7[1], *(__m128 *)((char *)v7 + v8 + 16)),
                                                *(__m128 *)((char *)v7 + v8 + 16)),
                                              v23),
                                            *(__m128 *)((char *)v7 + v8 + 16));
      *(__m128 *)((char *)v7 + v8 - 16) = _mm_add_ps(
                                            _mm_mul_ps(_mm_sub_ps(v16, *(__m128 *)((char *)v7 + v8 - 16)), v23),
                                            *(__m128 *)((char *)v7 + v8 - 16));
      v24 = _mm_mul_ps(*(__m128 *)((char *)v7 + v8), v22);
      v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 78), v24);
      ++v5;
      v7 += 3;
      v26 = _mm_add_ps(
              _mm_mul_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32(
                              (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 177), v25), (__m128)0i64),
                              0x1Fu),
                            0x1Fu),
                  v23),
                v22),
              _mm_mul_ps(_mm_sub_ps(query.m_quad, v23), *(__m128 *)((char *)v7 + v8 - 48)));
      v27 = _mm_mul_ps(v26, v26);
      v28 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 78), v27);
      v29 = _mm_add_ps(_mm_shuffle_ps(v28, v28, 177), v28);
      v30 = _mm_rsqrt_ps(v29);
      *(__m128 *)((char *)v7 + v8 - 48) = _mm_mul_ps(
                                            v26,
                                            _mm_mul_ps(
                                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                                              _mm_mul_ps(*(__m128 *)_xmm, v30)));
    }
    while ( v5 <= (signed int)(numBones - 1) );
  }
  hkQsTransform_fasterRenormalizeBatch(v6, numBones);
}

// File Line: 648
// RVA: 0x3A4660
void __fastcall PoseEvaluator::BlendPoseSub(PoseEvaluator *this, hkQsTransformf *outputLocalSpace, hkQsTransformf *posePose, unsigned int numBones, float weight)
{
  unsigned int v5; // edi
  hkQsTransformf *v6; // rsi
  __m128 *v7; // rbp
  __m128i v8; // xmm0
  signed __int64 v9; // rbx
  signed __int64 v10; // r14
  __m128 v11; // xmm9
  __m128 v12; // xmm10
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  __m128 v16; // xmm6
  __m128 v17; // xmm5
  __m128 v18; // xmm7
  __m128 v19; // xmm8
  __m128 v20; // xmm1
  __m128 v21; // xmm4
  __m128 v22; // xmm3
  __m128 v23; // xmm4
  __m128 v24; // xmm3
  __m128 v25; // xmm5
  __m128 v26; // xmm0
  __m128 v27; // xmm7
  __m128 v28; // xmm5
  hkVector4f direction; // [rsp+20h] [rbp-C8h]
  hkQuaternionf quat; // [rsp+30h] [rbp-B8h]
  __m128 v31; // [rsp+40h] [rbp-A8h]
  hkVector4f v32; // [rsp+50h] [rbp-98h]

  v5 = numBones;
  v6 = outputLocalSpace;
  if ( (signed int)(numBones - 1) >= 0 )
  {
    v7 = &posePose->m_rotation.m_vec.m_quad;
    v8 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
    v9 = (char *)outputLocalSpace - (char *)posePose;
    v10 = (signed int)(numBones - 1) + 1i64;
    v11 = (__m128)_mm_shuffle_epi32(v8, 0);
    v12 = (__m128)_mm_shuffle_epi32(v8, 64);
    do
    {
      v13 = *(__m128 *)((char *)v7 + v9);
      direction.m_quad = *(__m128 *)((char *)&v7[-1] + v9);
      v14 = *(__m128 *)((char *)v7 + v9 + 16);
      quat.m_vec.m_quad = v13;
      v31 = v14;
      hkVector4f::setRotatedInverseDir(&v32, &quat, &direction);
      v15 = _mm_rcp_ps(v31);
      v16 = _mm_xor_ps(v11, v32.m_quad);
      v17 = _mm_shuffle_ps(*v7, *v7, 255);
      v18 = _mm_xor_ps(v12, quat.m_vec.m_quad);
      v19 = (__m128)_mm_srli_si128(
                      _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v31, v15)), v15), 4),
                      4);
      v20 = _mm_mul_ps(v16, *v7);
      v21 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), *v7), _mm_mul_ps(_mm_shuffle_ps(*v7, *v7, 201), v16));
      v22 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                    _mm_shuffle_ps(v20, v20, 170)),
                  *v7),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v17, v17), (__m128)xmmword_141A711B0), v16)),
              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v17));
      v23 = _mm_shuffle_ps(v18, v18, 255);
      *(__m128 *)((char *)v7 + v9 - 16) = _mm_add_ps(_mm_add_ps(v22, v22), v7[-1]);
      v24 = _mm_shuffle_ps(*v7, *v7, 255);
      v25 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), *v7), _mm_mul_ps(_mm_shuffle_ps(*v7, *v7, 201), v18));
      v26 = v18;
      v27 = _mm_mul_ps(v18, *v7);
      v28 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 201), _mm_mul_ps(v26, v24)), _mm_mul_ps(v23, *v7));
      v7 += 3;
      *(__m128 *)((char *)v7 + v9 - 48) = _mm_shuffle_ps(
                                            v28,
                                            _mm_unpackhi_ps(
                                              v28,
                                              _mm_sub_ps(
                                                _mm_mul_ps(v23, v24),
                                                _mm_add_ps(
                                                  _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                                                  _mm_shuffle_ps(v27, v27, 170)))),
                                            196);
      *(__m128 *)((char *)v7 + v9 - 32) = _mm_mul_ps(v7[-2], v19);
      --v10;
    }
    while ( v10 );
  }
  hkQsTransform_fasterRenormalizeBatch(v6, v5);
}


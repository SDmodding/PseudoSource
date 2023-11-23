// File Line: 167
// RVA: 0x3A73A0
void __fastcall PoseEvaluator::EvaluatePoseLocalSpace(
        PoseEvaluator *this,
        PoseRecipe *recipe,
        hkQsTransformf *transforms)
{
  __int64 v3; // rsi
  signed int v5; // eax
  __int64 v8; // r15
  __int64 v9; // r14
  PoseRecipe::PoseStackEntry *mPoseStack; // r8
  PoseRecipe::PoseDescType mType; // edx
  hkQsTransformf *v12; // rbx
  hkVector4f v13; // xmm0
  hkQuaternionf v14; // xmm1
  hkVector4f v15; // xmm2
  hkQsTransformf *v16; // rdx
  __int64 mBoneCount; // rcx
  __m128 *p_m_quad; // rax
  hkQsTransformf *v19; // rbx
  int mBoneUpdateCount; // eax
  signed int v21; // r9d
  __int64 v22; // rsi
  hkQsTransformf *v23; // rbx
  __int64 v24; // rsi
  hkQsTransformf *v25; // rdi
  int v26; // eax
  signed int v27; // r9d
  __int64 v28; // rsi
  int v29; // eax
  signed int v30; // r9d
  __int64 v31; // rsi
  __int64 v32; // rsi
  hkQsTransformf *v33; // rbx
  hkQsTransformf *outputLocalSpace[69]; // [rsp+30h] [rbp-228h]

  v3 = 0i64;
  v5 = recipe->mStackCount - 1;
  v8 = v5;
  if ( v5 >= 0 )
  {
    v9 = v5;
    do
    {
      mPoseStack = recipe->mPoseStack;
      mType = mPoseStack[v9].mType;
      switch ( mType )
      {
        case PoseDescType_RestPose:
          v12 = this->mScratchBuffers.mStack[--this->mScratchBuffers.mStackDepth];
          UFG::qMemCopy(v12, recipe->mSkelDesc.mReferencePose, 48 * recipe->mSkelDesc.mBoneCount);
          outputLocalSpace[v3] = v12;
          v3 = (unsigned int)(v3 + 1);
          break;
        case PoseDescType_IdentityPose:
          --this->mScratchBuffers.mStackDepth;
          v13.m_quad = (__m128)hkQsTransformf_identityStorage.m_translation;
          v14.m_vec.m_quad = (__m128)hkQsTransformf_identityStorage.m_rotation;
          v15.m_quad = (__m128)hkQsTransformf_identityStorage.m_scale;
          v16 = this->mScratchBuffers.mStack[this->mScratchBuffers.mStackDepth];
          mBoneCount = recipe->mSkelDesc.mBoneCount;
          if ( (_DWORD)mBoneCount )
          {
            p_m_quad = &v16->m_scale.m_quad;
            do
            {
              p_m_quad[-2] = v13.m_quad;
              p_m_quad[-1] = v14.m_vec.m_quad;
              *(hkVector4f *)p_m_quad = (hkVector4f)v15.m_quad;
              p_m_quad += 3;
              --mBoneCount;
            }
            while ( mBoneCount );
          }
          outputLocalSpace[v3] = v16;
          v3 = (unsigned int)(v3 + 1);
          break;
        case PoseDescType_Anim:
          v19 = this->mScratchBuffers.mStack[--this->mScratchBuffers.mStackDepth];
          PoseEvaluator::EvaluateAnim(this, recipe, &recipe->mAnimData[mPoseStack[v9].mAnim.mIndex], v19);
          outputLocalSpace[v3] = v19;
          v3 = (unsigned int)(v3 + 1);
          break;
        case PoseDescType_Blend:
        case PoseDescType_BlendWeightSet:
          mBoneUpdateCount = recipe->mBoneUpdateCount;
          v21 = recipe->mSkelDesc.mBoneCount;
          v22 = (unsigned int)(v3 - 1);
          v23 = outputLocalSpace[v22];
          v24 = (unsigned int)(v22 - 1);
          v25 = outputLocalSpace[v24];
          if ( mBoneUpdateCount >= 0 && mBoneUpdateCount < v21 )
            v21 = recipe->mBoneUpdateCount;
          if ( (!this->mMemoryStreamer || mType == PoseDescType_BlendWeightSet) && mType == PoseDescType_BlendWeightSet )
            PoseEvaluator::BlendPoseWeightSet(
              this,
              v23,
              outputLocalSpace[v24],
              v21,
              mPoseStack[v9].mBlend.mPerBoneWeights);
          else
            PoseEvaluator::BlendPose(this, v23, outputLocalSpace[v24], v21, mPoseStack[v9].mBlend.mWeight);
          goto LABEL_31;
        case PoseDescType_BlendAdd:
        case PoseDescType_BlendAddWeightSet:
          v26 = recipe->mBoneUpdateCount;
          v27 = recipe->mSkelDesc.mBoneCount;
          v28 = (unsigned int)(v3 - 1);
          v23 = outputLocalSpace[v28];
          v24 = (unsigned int)(v28 - 1);
          v25 = outputLocalSpace[v24];
          if ( v26 >= 0 && v26 < v27 )
            v27 = recipe->mBoneUpdateCount;
          if ( (!this->mMemoryStreamer || mType == PoseDescType_BlendAddWeightSet)
            && mType == PoseDescType_BlendAddWeightSet )
          {
            PoseEvaluator::BlendPoseAddWeightSet(
              this,
              v23,
              outputLocalSpace[v24],
              v27,
              mPoseStack[v9].mBlend.mPerBoneWeights);
          }
          else
          {
            PoseEvaluator::BlendPoseAdd(this, v23, outputLocalSpace[v24], v27, mPoseStack[v9].mBlend.mWeight);
          }
          goto LABEL_31;
        case PoseDescType_BlendSub:
        case PoseDescType_BlendSubWeightSet:
          v29 = recipe->mBoneUpdateCount;
          v30 = recipe->mSkelDesc.mBoneCount;
          v31 = (unsigned int)(v3 - 1);
          v23 = outputLocalSpace[v31];
          v24 = (unsigned int)(v31 - 1);
          v25 = outputLocalSpace[v24];
          if ( v29 >= 0 && v29 < v30 )
            v30 = recipe->mBoneUpdateCount;
          PoseEvaluator::BlendPoseSub(this, v23, outputLocalSpace[v24], v30, mPoseStack[v9].mBlend.mWeight);
          goto LABEL_31;
        case PoseDescType_BlendAccum:
          v32 = (unsigned int)(v3 - 1);
          v23 = outputLocalSpace[v32];
          v24 = (unsigned int)(v32 - 1);
          v25 = outputLocalSpace[v24];
          PoseEvaluator::EvaluateBlendAccum(this, recipe, (PoseRecipe::BlendDesc *)&mPoseStack[v9].8, v23, v25);
LABEL_31:
          outputLocalSpace[v24] = v23;
          this->mScratchBuffers.mStack[this->mScratchBuffers.mStackDepth] = v25;
          v3 = (unsigned int)(v24 + 1);
          ++this->mScratchBuffers.mStackDepth;
          break;
        default:
          break;
      }
      --v9;
      --v8;
    }
    while ( v8 >= 0 );
  }
  v33 = outputLocalSpace[(unsigned int)(v3 - 1)];
  UFG::qMemCopy(transforms, v33, 48 * recipe->mSkelDesc.mBoneCount);
  this->mScratchBuffers.mStack[this->mScratchBuffers.mStackDepth++] = v33;
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
void __fastcall PoseEvaluator::EvaluatePoseModelSpace(
        PoseEvaluator *this,
        PoseRecipe *recipe,
        hkQsTransformf *transforms,
        UFG::qVector3 *aabbMin,
        UFG::qVector3 *aabbMax)
{
  unsigned int mBoneCount; // ebp
  __m128 m_quad; // xmm2
  __m128 v10; // xmm3
  hkQsTransformf *v11; // rcx
  __int64 v12; // rdx
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  __m128 v17; // [rsp+20h] [rbp-28h]
  __m128 v18; // [rsp+30h] [rbp-18h]

  PoseEvaluator::EvaluatePoseLocalSpace(this, recipe, transforms);
  mBoneCount = recipe->mSkelDesc.mBoneCount;
  hkaSkeletonUtils::transformLocalPoseToModelPose(
    recipe->mSkelDesc.mBoneCount,
    (const __int16 *)recipe->mSkelDesc.mParentIndices,
    transforms,
    transforms);
  m_quad = aabbMinStart.m_quad;
  v10 = aabbMaxStart.m_quad;
  v17 = aabbMinStart.m_quad;
  v18 = aabbMaxStart.m_quad;
  if ( mBoneCount > 1 )
  {
    v11 = transforms + 1;
    v12 = mBoneCount - 1;
    do
    {
      v13 = v11->m_translation.m_quad;
      ++v11;
      v14 = v13;
      v15 = _mm_max_ps(v13, v10);
      v16 = _mm_min_ps(v14, m_quad);
      v10 = v15;
      m_quad = v16;
      --v12;
    }
    while ( v12 );
    v17 = v16;
    v18 = v15;
  }
  *(_QWORD *)&aabbMin->x = v17.m128_u64[0];
  LODWORD(aabbMin->z) = v17.m128_i32[2];
  *aabbMax = *(UFG::qVector3 *)v18.m128_f32;
}

// File Line: 328
// RVA: 0x3A6ED0
void __fastcall PoseEvaluator::EvaluateAnim(
        PoseEvaluator *this,
        PoseRecipe *recipe,
        PoseRecipe::AnimData *anim,
        hkQsTransformf *pose)
{
  __int64 mBoneCount; // rcx
  hkVector4f v9; // xmm0
  hkQuaternionf v10; // xmm1
  hkVector4f v11; // xmm2
  hkVector4f *p_m_scale; // rax
  unsigned __int16 *mTrackToBoneIndices; // rsi
  hkaAnimation::DataChunk *chunks; // r14
  int MaxTrackIndex; // r15d
  int mBoneUpdateCount; // eax
  float v17; // xmm0_4
  hkQsTransformf *transformTracksOut; // rdx
  unsigned int v19; // r15d
  unsigned int v20; // edi
  float v21; // xmm2_4
  char v22; // r14
  hkVector4f *v23; // rdx
  unsigned int v24; // r8d
  char v25; // r10
  __int64 v26; // rcx
  hkVector4f v27; // xmm0
  unsigned __int8 mRootRetargetIndex; // al
  float v29; // xmm1_4
  char v30; // al
  __int64 v31; // rcx
  hkVector4f v32; // [rsp+50h] [rbp-48h]
  char v33; // [rsp+A0h] [rbp+8h]
  unsigned int v34; // [rsp+A8h] [rbp+10h]
  hkQsTransformf *v35; // [rsp+B0h] [rbp+18h]

  mBoneCount = recipe->mSkelDesc.mBoneCount;
  v34 = recipe->mSkelDesc.mBoneCount;
  if ( anim->mBlendHint == 1 )
  {
    v9.m_quad = (__m128)hkQsTransformf_identityStorage.m_translation;
    v10.m_vec.m_quad = (__m128)hkQsTransformf_identityStorage.m_rotation;
    v11.m_quad = (__m128)hkQsTransformf_identityStorage.m_scale;
    if ( !(_DWORD)mBoneCount )
      goto LABEL_8;
    p_m_scale = &pose->m_scale;
    do
    {
      p_m_scale[-2] = (hkVector4f)v9.m_quad;
      p_m_scale[-1] = (hkVector4f)v10.m_vec.m_quad;
      *p_m_scale = (hkVector4f)v11.m_quad;
      p_m_scale += 3;
      --mBoneCount;
    }
    while ( mBoneCount );
  }
  else
  {
    UFG::qMemCopy(pose, recipe->mSkelDesc.mReferencePose, 48 * mBoneCount);
  }
  LODWORD(mBoneCount) = v34;
LABEL_8:
  mTrackToBoneIndices = anim->mTrackToBoneIndices;
  chunks = anim->mDataChunks;
  MaxTrackIndex = hkaSampleAndCombineUtils::getMaxTrackIndex(
                    (const __int16 *)mTrackToBoneIndices,
                    0i64,
                    mBoneCount,
                    (unsigned __int8)anim->mNumTransformTracks,
                    0);
  if ( MaxTrackIndex > 200 )
    MaxTrackIndex = 200;
  mBoneUpdateCount = recipe->mBoneUpdateCount;
  if ( mBoneUpdateCount >= 0 )
  {
    v17 = (float)mBoneUpdateCount;
    if ( (float)mBoneUpdateCount >= (float)MaxTrackIndex )
      v17 = (float)MaxTrackIndex;
    MaxTrackIndex = (int)v17;
  }
  transformTracksOut = this->mScratchBuffers.mStack[--this->mScratchBuffers.mStackDepth];
  v19 = MaxTrackIndex + 1;
  v20 = 0;
  v35 = transformTracksOut;
  switch ( anim->mAnimType )
  {
    case 1:
      hkaInterleavedUncompressedAnimation::samplePartialWithDataChunks(
        anim->mFrameIndex,
        anim->mFrameDelta,
        v19,
        transformTracksOut,
        0,
        0i64,
        chunks,
        (unsigned __int8)anim->mNumDataChunks);
      break;
    case 3:
      hkaSplineCompressedAnimation::samplePartialWithDataChunks(
        anim->mFrameIndex,
        anim->mFrameDelta,
        v19,
        transformTracksOut,
        0,
        0i64,
        chunks,
        (unsigned __int8)anim->mNumDataChunks);
      break;
    case 4:
      hkaQuantizedAnimation::samplePartialWithDataChunks(
        anim->mFrameIndex,
        anim->mFrameDelta,
        v19,
        0,
        recipe->mSkelDesc.mReferencePose,
        0i64,
        chunks,
        (unsigned __int8)anim->mNumDataChunks,
        transformTracksOut,
        0i64);
      break;
    case 5:
      hkaPredictiveCompressedAnimation::samplePartialWithDataChunks(
        anim->mFrameIndex,
        anim->mFrameDelta,
        v19,
        0,
        recipe->mSkelDesc.mReferencePose,
        0i64,
        chunks,
        (unsigned __int8)anim->mNumDataChunks,
        transformTracksOut,
        0i64);
      break;
    default:
      goto LABEL_23;
  }
  transformTracksOut = v35;
LABEL_23:
  v21 = *(float *)&FLOAT_1_0;
  v33 = 0;
  v22 = recipe->mFlags & 1;
  if ( v19 == -1 || !transformTracksOut || !v19 )
    goto LABEL_46;
  v23 = &transformTracksOut->m_scale;
  do
  {
    if ( anim->mTrackToBoneIndices )
      v24 = (__int16)*mTrackToBoneIndices;
    else
      v24 = v20;
    if ( v24 < v34 )
    {
      if ( anim->mBlendHint == 1 )
      {
        v31 = v24;
        pose[v31].m_translation = (hkVector4f)v23[-2].m_quad;
        pose[v31].m_rotation.m_vec = (hkVector4f)v23[-1].m_quad;
        pose[v31].m_scale = (hkVector4f)v23->m_quad;
      }
      else
      {
        if ( !recipe->mSkelDesc.mBones[v24].m_lockTranslation.m_bool || v22 )
        {
          v27.m_quad = (__m128)v23[-2];
          v25 = 0;
          v26 = v24;
        }
        else
        {
          v25 = 1;
          v26 = v24;
          v27.m_quad = (__m128)recipe->mSkelDesc.mReferencePose[v26].m_translation;
        }
        pose[v26].m_translation = (hkVector4f)v27.m_quad;
        pose[v26].m_rotation.m_vec = (hkVector4f)v23[-1].m_quad;
        pose[v26].m_scale = (hkVector4f)v23->m_quad;
        mRootRetargetIndex = anim->mRootRetargetIndex;
        if ( mRootRetargetIndex != 0xFF )
        {
          if ( v25 )
          {
            if ( v24 == mRootRetargetIndex )
            {
              LODWORD(v29) = v23[-2].m_quad.m128_i32[0] & _xmm;
              if ( v29 > 0.001 )
              {
                v30 = 1;
                v33 = 1;
                v21 = v29 / COERCE_FLOAT(*(_OWORD *)&recipe->mSkelDesc.mReferencePose[v26].m_translation & _xmm);
                goto LABEL_43;
              }
            }
          }
        }
      }
    }
    v30 = v33;
LABEL_43:
    ++v20;
    ++mTrackToBoneIndices;
    v23 += 3;
  }
  while ( v20 < v19 );
  if ( v30 )
  {
    v32.m_quad = (__m128)pose->m_translation;
    v32.m_quad.m128_f32[2] = pose->m_translation.m_quad.m128_f32[2] / v21;
    pose->m_translation = (hkVector4f)v32.m_quad;
  }
LABEL_46:
  this->mScratchBuffers.mStack[this->mScratchBuffers.mStackDepth++] = v35;
}

// File Line: 581
// RVA: 0x3A7270
void __fastcall PoseEvaluator::EvaluateBlendAccum(
        PoseEvaluator *this,
        PoseRecipe *recipe,
        PoseRecipe::BlendDesc *blend,
        hkQsTransformf *pose1,
        hkQsTransformf *pose2)
{
  hkQuaternionf *p_m_rotation; // rcx
  __int64 mBoneCount; // rdx
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
    p_m_rotation = &pose1->m_rotation;
    mBoneCount = recipe->mSkelDesc.mBoneCount;
    v7 = (char *)pose2 - (char *)pose1;
    do
    {
      v8 = *(__m128 *)((char *)&p_m_rotation[1].m_vec.m_quad + v7);
      p_m_rotation += 3;
      v9 = _mm_shuffle_ps((__m128)LODWORD(blend->mWeight), (__m128)LODWORD(blend->mWeight), 0);
      p_m_rotation[-2].m_vec.m_quad = _mm_add_ps(
                                        _mm_mul_ps(_mm_sub_ps(v8, p_m_rotation[-2].m_vec.m_quad), v9),
                                        p_m_rotation[-2].m_vec.m_quad);
      p_m_rotation[-4].m_vec.m_quad = _mm_add_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps(
                                            *(__m128 *)((char *)&p_m_rotation[-4].m_vec.m_quad + v7),
                                            p_m_rotation[-4].m_vec.m_quad),
                                          v9),
                                        p_m_rotation[-4].m_vec.m_quad);
      v10 = _mm_mul_ps(*(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v7), p_m_rotation[-3].m_vec.m_quad);
      v11 = _mm_add_ps(_mm_shuffle_ps(v10, v10, 78), v10);
      v12 = _mm_add_ps(
              _mm_mul_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32(
                              (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 177), v11), (__m128)0i64),
                              0x1Fu),
                            0x1Fu),
                  v9),
                *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v7)),
              _mm_mul_ps(_mm_sub_ps(query.m_quad, v9), p_m_rotation[-3].m_vec.m_quad));
      v13 = _mm_mul_ps(v12, v12);
      v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
      v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14);
      v16 = _mm_rsqrt_ps(v15);
      p_m_rotation[-3].m_vec.m_quad = _mm_mul_ps(
                                        v12,
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v16)));
      p_m_rotation[-2] = (hkQuaternionf)_xmm;
      --mBoneCount;
    }
    while ( mBoneCount );
  }
}

// File Line: 595
// RVA: 0x3A4090
void __fastcall PoseEvaluator::BlendPose(
        PoseEvaluator *this,
        hkQsTransformf *outputLocalSpace,
        hkQsTransformf *posePose,
        unsigned int numBones,
        float weight)
{
  signed __int64 v5; // r8
  hkQuaternionf *p_m_rotation; // rax
  __int64 v7; // rcx
  __m128 v8; // xmm5
  __m128 v9; // xmm1
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2

  if ( (int)(numBones - 1) >= 0 )
  {
    v5 = (char *)posePose - (char *)outputLocalSpace;
    p_m_rotation = &outputLocalSpace->m_rotation;
    v7 = (int)(numBones - 1) + 1i64;
    v8 = _mm_shuffle_ps((__m128)LODWORD(weight), (__m128)LODWORD(weight), 0);
    do
    {
      v9 = *(__m128 *)((char *)&p_m_rotation[1].m_vec.m_quad + v5);
      p_m_rotation += 3;
      p_m_rotation[-2].m_vec.m_quad = _mm_add_ps(
                                        _mm_mul_ps(_mm_sub_ps(v9, p_m_rotation[-2].m_vec.m_quad), v8),
                                        p_m_rotation[-2].m_vec.m_quad);
      p_m_rotation[-4].m_vec.m_quad = _mm_add_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps(
                                            *(__m128 *)((char *)&p_m_rotation[-4].m_vec.m_quad + v5),
                                            p_m_rotation[-4].m_vec.m_quad),
                                          v8),
                                        p_m_rotation[-4].m_vec.m_quad);
      v10 = _mm_mul_ps(*(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v5), p_m_rotation[-3].m_vec.m_quad);
      v11 = _mm_add_ps(_mm_shuffle_ps(v10, v10, 78), v10);
      v12 = _mm_add_ps(
              _mm_mul_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32(
                              (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 177), v11), (__m128)0i64),
                              0x1Fu),
                            0x1Fu),
                  v8),
                *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v5)),
              _mm_mul_ps(_mm_sub_ps(query.m_quad, v8), p_m_rotation[-3].m_vec.m_quad));
      v13 = _mm_mul_ps(v12, v12);
      v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
      v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14);
      v16 = _mm_rsqrt_ps(v15);
      p_m_rotation[-3].m_vec.m_quad = _mm_mul_ps(
                                        v12,
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v16)));
      p_m_rotation[-2] = (hkQuaternionf)_xmm;
      --v7;
    }
    while ( v7 );
  }
  hkQsTransform_fasterRenormalizeBatch(outputLocalSpace, numBones);
}

// File Line: 609
// RVA: 0x3A48B0
void __fastcall PoseEvaluator::BlendPoseWeightSet(
        PoseEvaluator *this,
        hkQsTransformf *outputLocalSpace,
        hkQsTransformf *posePose,
        unsigned int numBones,
        const float *perBoneWeights)
{
  __m128 v5; // xmm4
  __int64 v7; // rdx
  hkQuaternionf *p_m_rotation; // rax
  signed __int64 v9; // r8
  float v10; // xmm0_4
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  __m128 v13; // xmm1
  __m128 v14; // xmm5
  __m128 v15; // xmm0
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm2

  v7 = 0i64;
  if ( (int)(numBones - 1) >= 0 )
  {
    p_m_rotation = &outputLocalSpace->m_rotation;
    v9 = (char *)posePose - (char *)outputLocalSpace;
    do
    {
      v10 = perBoneWeights[v7];
      v11 = *(__m128 *)((char *)&p_m_rotation[1].m_vec.m_quad + v9);
      ++v7;
      p_m_rotation += 3;
      v5.m128_f32[0] = v10 * 0.0039215689;
      v5 = _mm_shuffle_ps(v5, v5, 0);
      p_m_rotation[-2].m_vec.m_quad = _mm_add_ps(
                                        _mm_mul_ps(_mm_sub_ps(v11, p_m_rotation[-2].m_vec.m_quad), v5),
                                        p_m_rotation[-2].m_vec.m_quad);
      p_m_rotation[-4].m_vec.m_quad = _mm_add_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps(
                                            *(__m128 *)((char *)&p_m_rotation[-4].m_vec.m_quad + v9),
                                            p_m_rotation[-4].m_vec.m_quad),
                                          v5),
                                        p_m_rotation[-4].m_vec.m_quad);
      v12 = _mm_mul_ps(*(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v9), p_m_rotation[-3].m_vec.m_quad);
      v13 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 78), v12);
      v14 = _mm_add_ps(
              _mm_mul_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32(
                              (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 177), v13), (__m128)0i64),
                              0x1Fu),
                            0x1Fu),
                  v5),
                *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v9)),
              _mm_mul_ps(_mm_sub_ps(query.m_quad, v5), p_m_rotation[-3].m_vec.m_quad));
      v15 = _mm_mul_ps(v14, v14);
      v16 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 78), v15);
      v17 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 177), v16);
      v18 = _mm_rsqrt_ps(v17);
      p_m_rotation[-3].m_vec.m_quad = _mm_mul_ps(
                                        v14,
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v18)));
      p_m_rotation[-2] = (hkQuaternionf)_xmm;
    }
    while ( v7 <= (int)(numBones - 1) );
  }
  hkQsTransform_fasterRenormalizeBatch(outputLocalSpace, numBones);
}

// File Line: 623
// RVA: 0x3A41E0
void __fastcall PoseEvaluator::BlendPoseAdd(
        PoseEvaluator *this,
        hkQsTransformf *outputLocalSpace,
        hkQsTransformf *posePose,
        unsigned int numBones,
        float weight)
{
  hkQuaternionf *p_m_rotation; // rdx
  signed __int64 v7; // rax
  __int64 v8; // rcx
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

  if ( (int)(numBones - 1) >= 0 )
  {
    p_m_rotation = &posePose->m_rotation;
    v7 = (char *)outputLocalSpace - (char *)posePose;
    v8 = (int)(numBones - 1) + 1i64;
    v9 = _mm_shuffle_ps((__m128)LODWORD(weight), (__m128)LODWORD(weight), 0);
    do
    {
      v10 = *(__m128 *)((char *)&p_m_rotation[-1].m_vec.m_quad + v7);
      v11 = _mm_mul_ps(v10, p_m_rotation->m_vec.m_quad);
      v12 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), p_m_rotation->m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 201), v10));
      v13 = _mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 255);
      v14 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0), v10);
      v15 = *(__m128 *)((char *)&p_m_rotation->m_vec.m_quad + v7);
      v16 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                    _mm_shuffle_ps(v11, v11, 170)),
                  p_m_rotation->m_vec.m_quad),
                v14),
              _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v13));
      v17 = _mm_add_ps(_mm_add_ps(v16, v16), p_m_rotation[-1].m_vec.m_quad);
      v18 = _mm_shuffle_ps(v15, v15, 255);
      v19 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), p_m_rotation->m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 201), v15));
      v20 = _mm_mul_ps(v15, p_m_rotation->m_vec.m_quad);
      v21 = _mm_add_ps(
              _mm_add_ps(
                _mm_shuffle_ps(v19, v19, 201),
                _mm_mul_ps(*(__m128 *)((char *)&p_m_rotation->m_vec.m_quad + v7), v13)),
              _mm_mul_ps(p_m_rotation->m_vec.m_quad, v18));
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
      *(__m128 *)((char *)&p_m_rotation[1].m_vec.m_quad + v7) = _mm_add_ps(
                                                                  _mm_mul_ps(
                                                                    _mm_sub_ps(
                                                                      _mm_mul_ps(
                                                                        p_m_rotation[1].m_vec.m_quad,
                                                                        *(__m128 *)((char *)&p_m_rotation[1].m_vec.m_quad
                                                                                  + v7)),
                                                                      *(__m128 *)((char *)&p_m_rotation[1].m_vec.m_quad
                                                                                + v7)),
                                                                    v9),
                                                                  *(__m128 *)((char *)&p_m_rotation[1].m_vec.m_quad + v7));
      *(__m128 *)((char *)&p_m_rotation[-1].m_vec.m_quad + v7) = _mm_add_ps(
                                                                   _mm_mul_ps(
                                                                     _mm_sub_ps(
                                                                       v17,
                                                                       *(__m128 *)((char *)&p_m_rotation[-1].m_vec.m_quad
                                                                                 + v7)),
                                                                     v9),
                                                                   *(__m128 *)((char *)&p_m_rotation[-1].m_vec.m_quad
                                                                             + v7));
      v23 = _mm_mul_ps(*(__m128 *)((char *)&p_m_rotation->m_vec.m_quad + v7), v22);
      v24 = _mm_add_ps(_mm_shuffle_ps(v23, v23, 78), v23);
      p_m_rotation += 3;
      v25 = _mm_add_ps(
              _mm_mul_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32(
                              (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v24, v24, 177), v24), (__m128)0i64),
                              0x1Fu),
                            0x1Fu),
                  v9),
                v22),
              _mm_mul_ps(_mm_sub_ps(query.m_quad, v9), *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v7)));
      v26 = _mm_mul_ps(v25, v25);
      v27 = _mm_add_ps(_mm_shuffle_ps(v26, v26, 78), v26);
      v28 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 177), v27);
      v29 = _mm_rsqrt_ps(v28);
      *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v7) = _mm_mul_ps(
                                                                   v25,
                                                                   _mm_mul_ps(
                                                                     _mm_sub_ps(
                                                                       (__m128)_xmm,
                                                                       _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
                                                                     _mm_mul_ps(*(__m128 *)_xmm, v29)));
      --v8;
    }
    while ( v8 );
  }
  hkQsTransform_fasterRenormalizeBatch(outputLocalSpace, numBones);
}

// File Line: 635
// RVA: 0x3A4410
void __fastcall PoseEvaluator::BlendPoseAddWeightSet(
        PoseEvaluator *this,
        hkQsTransformf *outputLocalSpace,
        hkQsTransformf *posePose,
        unsigned int numBones,
        const float *perBoneWeights)
{
  __int64 v5; // r11
  hkQuaternionf *p_m_rotation; // rdx
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
  if ( (int)(numBones - 1) >= 0 )
  {
    p_m_rotation = &posePose->m_rotation;
    v8 = (char *)outputLocalSpace - (char *)posePose;
    do
    {
      v9 = *(__m128 *)((char *)&p_m_rotation[-1].m_vec.m_quad + v8);
      v10 = _mm_mul_ps(v9, p_m_rotation->m_vec.m_quad);
      v11 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), p_m_rotation->m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 201), v9));
      v12 = _mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 255);
      v13 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v12, v12), (__m128)xmmword_141A711B0), v9);
      v14 = *(__m128 *)((char *)&p_m_rotation->m_vec.m_quad + v8);
      v15 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                    _mm_shuffle_ps(v10, v10, 170)),
                  p_m_rotation->m_vec.m_quad),
                v13),
              _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v12));
      v16 = _mm_add_ps(_mm_add_ps(v15, v15), p_m_rotation[-1].m_vec.m_quad);
      v17 = _mm_shuffle_ps(v14, v14, 255);
      v18 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), p_m_rotation->m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 201), v14));
      v19 = _mm_mul_ps(v14, p_m_rotation->m_vec.m_quad);
      v20 = _mm_add_ps(
              _mm_add_ps(
                _mm_shuffle_ps(v18, v18, 201),
                _mm_mul_ps(*(__m128 *)((char *)&p_m_rotation->m_vec.m_quad + v8), v12)),
              _mm_mul_ps(p_m_rotation->m_vec.m_quad, v17));
      v21 = _mm_sub_ps(
              _mm_mul_ps(v17, v12),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                _mm_shuffle_ps(v19, v19, 170)));
      v22 = _mm_shuffle_ps(v20, _mm_unpackhi_ps(v20, v21), 196);
      v21.m128_f32[0] = perBoneWeights[v5] * 0.0039215689;
      v23 = _mm_shuffle_ps(v21, v21, 0);
      *(__m128 *)((char *)&p_m_rotation[1].m_vec.m_quad + v8) = _mm_add_ps(
                                                                  _mm_mul_ps(
                                                                    _mm_sub_ps(
                                                                      _mm_mul_ps(
                                                                        p_m_rotation[1].m_vec.m_quad,
                                                                        *(__m128 *)((char *)&p_m_rotation[1].m_vec.m_quad
                                                                                  + v8)),
                                                                      *(__m128 *)((char *)&p_m_rotation[1].m_vec.m_quad
                                                                                + v8)),
                                                                    v23),
                                                                  *(__m128 *)((char *)&p_m_rotation[1].m_vec.m_quad + v8));
      *(__m128 *)((char *)&p_m_rotation[-1].m_vec.m_quad + v8) = _mm_add_ps(
                                                                   _mm_mul_ps(
                                                                     _mm_sub_ps(
                                                                       v16,
                                                                       *(__m128 *)((char *)&p_m_rotation[-1].m_vec.m_quad
                                                                                 + v8)),
                                                                     v23),
                                                                   *(__m128 *)((char *)&p_m_rotation[-1].m_vec.m_quad
                                                                             + v8));
      v24 = _mm_mul_ps(*(__m128 *)((char *)&p_m_rotation->m_vec.m_quad + v8), v22);
      v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 78), v24);
      ++v5;
      p_m_rotation += 3;
      v26 = _mm_add_ps(
              _mm_mul_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(
                            _mm_srli_epi32(
                              (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 177), v25), (__m128)0i64),
                              0x1Fu),
                            0x1Fu),
                  v23),
                v22),
              _mm_mul_ps(_mm_sub_ps(query.m_quad, v23), *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v8)));
      v27 = _mm_mul_ps(v26, v26);
      v28 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 78), v27);
      v29 = _mm_add_ps(_mm_shuffle_ps(v28, v28, 177), v28);
      v30 = _mm_rsqrt_ps(v29);
      *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v8) = _mm_mul_ps(
                                                                   v26,
                                                                   _mm_mul_ps(
                                                                     _mm_sub_ps(
                                                                       (__m128)_xmm,
                                                                       _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                                                                     _mm_mul_ps(*(__m128 *)_xmm, v30)));
    }
    while ( v5 <= (int)(numBones - 1) );
  }
  hkQsTransform_fasterRenormalizeBatch(outputLocalSpace, numBones);
}

// File Line: 648
// RVA: 0x3A4660
void __fastcall PoseEvaluator::BlendPoseSub(
        PoseEvaluator *this,
        hkQsTransformf *outputLocalSpace,
        hkQsTransformf *posePose,
        unsigned int numBones,
        float weight)
{
  hkQuaternionf *p_m_rotation; // rbp
  __m128i inserted; // xmm0
  signed __int64 v9; // rbx
  __int64 v10; // r14
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
  hkVector4f direction; // [rsp+20h] [rbp-C8h] BYREF
  hkQuaternionf quat; // [rsp+30h] [rbp-B8h] BYREF
  __m128 v31; // [rsp+40h] [rbp-A8h]
  hkVector4f v32; // [rsp+50h] [rbp-98h] BYREF

  if ( (int)(numBones - 1) >= 0 )
  {
    p_m_rotation = &posePose->m_rotation;
    inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
    v9 = (char *)outputLocalSpace - (char *)posePose;
    v10 = (int)(numBones - 1) + 1i64;
    v11 = (__m128)_mm_shuffle_epi32(inserted, 0);
    v12 = (__m128)_mm_shuffle_epi32(inserted, 64);
    do
    {
      v13 = *(__m128 *)((char *)&p_m_rotation->m_vec.m_quad + v9);
      direction.m_quad = *(__m128 *)((char *)&p_m_rotation[-1] + v9);
      v14 = *(__m128 *)((char *)&p_m_rotation[1].m_vec.m_quad + v9);
      quat.m_vec.m_quad = v13;
      v31 = v14;
      hkVector4f::setRotatedInverseDir(&v32, &quat, &direction);
      v15 = _mm_rcp_ps(v31);
      v16 = _mm_xor_ps(v11, v32.m_quad);
      v17 = _mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 255);
      v18 = _mm_xor_ps(v12, quat.m_vec.m_quad);
      v19 = (__m128)_mm_srli_si128(
                      _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v31, v15)), v15), 4),
                      4);
      v20 = _mm_mul_ps(v16, p_m_rotation->m_vec.m_quad);
      v21 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), p_m_rotation->m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 201), v16));
      v22 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                    _mm_shuffle_ps(v20, v20, 170)),
                  p_m_rotation->m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v17, v17), (__m128)xmmword_141A711B0), v16)),
              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v17));
      v23 = _mm_shuffle_ps(v18, v18, 255);
      *(__m128 *)((char *)&p_m_rotation[-1].m_vec.m_quad + v9) = _mm_add_ps(
                                                                   _mm_add_ps(v22, v22),
                                                                   p_m_rotation[-1].m_vec.m_quad);
      v24 = _mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 255);
      v25 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), p_m_rotation->m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 201), v18));
      v26 = v18;
      v27 = _mm_mul_ps(v18, p_m_rotation->m_vec.m_quad);
      v28 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v25, v25, 201), _mm_mul_ps(v26, v24)),
              _mm_mul_ps(v23, p_m_rotation->m_vec.m_quad));
      p_m_rotation += 3;
      *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v9) = _mm_shuffle_ps(
                                                                   v28,
                                                                   _mm_unpackhi_ps(
                                                                     v28,
                                                                     _mm_sub_ps(
                                                                       _mm_mul_ps(v23, v24),
                                                                       _mm_add_ps(
                                                                         _mm_add_ps(
                                                                           _mm_shuffle_ps(v27, v27, 85),
                                                                           _mm_shuffle_ps(v27, v27, 0)),
                                                                         _mm_shuffle_ps(v27, v27, 170)))),
                                                                   196);
      *(__m128 *)((char *)&p_m_rotation[-2].m_vec.m_quad + v9) = _mm_mul_ps(p_m_rotation[-2].m_vec.m_quad, v19);
      --v10;
    }
    while ( v10 );
  }
  hkQsTransform_fasterRenormalizeBatch(outputLocalSpace, numBones);
}


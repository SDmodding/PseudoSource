// File Line: 38
// RVA: 0x3B5DB0
void __fastcall PoseRecipeVisitor::Visit(ResourceOpportunityVisitor *this, PoseNodeParent *node)
{
  int *p_mNetPoseSequence; // rsi
  PoseNodeParent *p_mNext; // rbx

  if ( this->mRecurse )
  {
    p_mNetPoseSequence = &node->mNetPoseSequence;
    p_mNext = (PoseNodeParent *)&node->mChildren.mNode.mNext[-3].mNext;
    if ( p_mNext != (PoseNodeParent *)&node->mNetPoseSequence )
    {
      do
      {
        p_mNext->PoseNode::Expression::IMemberMap::vfptr[1].FindWithOldPath(p_mNext, (const char *)this);
        p_mNext = (PoseNodeParent *)&p_mNext->mNext[-3].mNext;
      }
      while ( p_mNext != (PoseNodeParent *)p_mNetPoseSequence );
    }
  }
}

// File Line: 43
// RVA: 0x3B5BA0
void __fastcall PoseRecipeVisitor::Visit(PoseRecipeVisitor *this, BlendPhaseNode *node)
{
  float v4; // xmm0_4
  int v5; // eax
  int *p_mNext; // rcx
  int *p_mNetPoseSequence; // rsi
  UFG::qNode<PoseNode,PoseNode> *mNext; // rbx
  int *v9; // rsi
  int *i; // rbx

  if ( !this->mIsValid )
    return;
  v4 = (float)(sinf((float)(node->mBlendParam * 3.1415927) - 1.5707964) + 1.0) * 0.5;
  if ( v4 <= 0.0 )
  {
    v4 = 0.0;
    goto LABEL_6;
  }
  if ( v4 < 1.0 )
  {
LABEL_6:
    if ( v4 < 0.000099999997 )
    {
      ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, PoseRecipeVisitor *))node->mChildren.mNode.mNext[-3].mNext[5].mPrev)(
        &node->mChildren.mNode.mNext[-3].mNext,
        this);
      return;
    }
    if ( v4 <= 0.99989998 )
      goto LABEL_14;
  }
  if ( !node->mWeightSet )
  {
    v5 = 1;
    p_mNext = (int *)&node->mChildren.mNode.mNext[-3].mNext;
    p_mNetPoseSequence = &node->mNetPoseSequence;
    do
    {
      if ( p_mNext == p_mNetPoseSequence )
        break;
      --v5;
      p_mNext = (int *)(*((_QWORD *)p_mNext + 6) - 40i64);
    }
    while ( v5 > 0 );
    (*(void (__fastcall **)(int *, PoseRecipeVisitor *))(*(_QWORD *)p_mNext + 80i64))(p_mNext, this);
    return;
  }
LABEL_14:
  PoseRecipeVisitor::PopulateBlendNodeCommon(this, this->mRecipe, node, NORMAL);
  if ( this->mRecurse )
  {
    mNext = node->mChildren.mNode.mNext;
    v9 = &node->mNetPoseSequence;
    for ( i = (int *)&mNext[-3].mNext; i != v9; i = (int *)(*((_QWORD *)i + 6) - 40i64) )
      (*(void (__fastcall **)(int *, PoseRecipeVisitor *))(*(_QWORD *)i + 80i64))(i, this);
  }
}

// File Line: 68
// RVA: 0x3B5800
void __fastcall PoseRecipeVisitor::Visit(PoseRecipeVisitor *this, BlendAddNode *node)
{
  float v4; // xmm0_4
  UFG::qNode<PoseNode,PoseNode> *mNext; // rbx
  int *p_mNetPoseSequence; // rsi
  int *i; // rbx

  if ( this->mIsValid )
  {
    v4 = (float)(sinf((float)(node->mBlendParam * 3.1415927) - 1.5707964) + 1.0) * 0.5;
    if ( v4 <= 0.0 || v4 < 1.0 && v4 < 0.000099999997 )
    {
      ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, PoseRecipeVisitor *))node->mChildren.mNode.mNext[-3].mNext[5].mPrev)(
        &node->mChildren.mNode.mNext[-3].mNext,
        this);
    }
    else
    {
      PoseRecipeVisitor::PopulateBlendNodeCommon(this, this->mRecipe, node, ADD);
      if ( this->mRecurse )
      {
        mNext = node->mChildren.mNode.mNext;
        p_mNetPoseSequence = &node->mNetPoseSequence;
        for ( i = (int *)&mNext[-3].mNext; i != p_mNetPoseSequence; i = (int *)(*((_QWORD *)i + 6) - 40i64) )
          (*(void (__fastcall **)(int *, PoseRecipeVisitor *))(*(_QWORD *)i + 80i64))(i, this);
      }
    }
  }
}

// File Line: 88
// RVA: 0x3B5CD0
void __fastcall PoseRecipeVisitor::Visit(PoseRecipeVisitor *this, BlendSubNode *node)
{
  float v4; // xmm0_4
  UFG::qNode<PoseNode,PoseNode> *mNext; // rbx
  int *p_mNetPoseSequence; // rsi
  int *i; // rbx

  if ( this->mIsValid )
  {
    v4 = (float)(sinf((float)(node->mBlendParam * 3.1415927) - 1.5707964) + 1.0) * 0.5;
    if ( v4 <= 0.0 || v4 < 1.0 && v4 < 0.000099999997 )
    {
      ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, PoseRecipeVisitor *))node->mChildren.mNode.mNext[-3].mNext[5].mPrev)(
        &node->mChildren.mNode.mNext[-3].mNext,
        this);
    }
    else
    {
      PoseRecipeVisitor::PopulateBlendNodeCommon(this, this->mRecipe, node, SUB);
      if ( this->mRecurse )
      {
        mNext = node->mChildren.mNode.mNext;
        p_mNetPoseSequence = &node->mNetPoseSequence;
        for ( i = (int *)&mNext[-3].mNext; i != p_mNetPoseSequence; i = (int *)(*((_QWORD *)i + 6) - 40i64) )
          (*(void (__fastcall **)(int *, PoseRecipeVisitor *))(*(_QWORD *)i + 80i64))(i, this);
      }
    }
  }
}

// File Line: 133
// RVA: 0x3B58E0
void __fastcall PoseRecipeVisitor::Visit(PoseRecipeVisitor *this, BlendDirectionNode *node)
{
  int mChild0ID; // ecx
  float mWeight; // xmm0_4
  int *p_mNext; // rbx
  BlendDirectionNode *i; // rdi
  int mChild1ID; // eax
  int *p_mNetPoseSequence; // rdx
  Expression::IMemberMapVtbl *vfptr; // rax
  BlendDirectionNode *v10; // rcx
  __int64 mStackCount; // rax
  float *v12; // [rsp+30h] [rbp+8h]

  if ( this->mIsValid )
  {
    mChild0ID = node->mChild0ID;
    mWeight = node->mWeight;
    p_mNext = (int *)&node->mChildren.mNode.mNext[-3].mNext;
    for ( i = (BlendDirectionNode *)p_mNext; mChild0ID > 0; i = (BlendDirectionNode *)&i->mNext[-3].mNext )
    {
      if ( i == (BlendDirectionNode *)&node->mNetPoseSequence )
        break;
      --mChild0ID;
    }
    mChild1ID = node->mChild1ID;
    if ( mChild1ID > 0 )
    {
      p_mNetPoseSequence = &node->mNetPoseSequence;
      do
      {
        if ( p_mNext == p_mNetPoseSequence )
          break;
        --mChild1ID;
        p_mNext = (int *)(*((_QWORD *)p_mNext + 6) - 40i64);
      }
      while ( mChild1ID > 0 );
    }
    if ( mWeight >= 0.000099999997 )
    {
      if ( mWeight <= 0.99989998 )
      {
        mStackCount = this->mStackCount;
        *(float *)&v12 = mWeight;
        if ( (unsigned int)mStackCount >= 0xC0 )
        {
          this->mIsValid = 0;
        }
        else
        {
          UFG::qMemSet(&this->mPoseStack[mStackCount], 0, 0x10u);
          this->mPoseStack[this->mStackCount].mType = PoseDescType_Blend;
          this->mPoseStack[this->mStackCount++].mBlend.mPerBoneWeights = v12;
        }
        i->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[1].FindWithOldPath(i, (const char *)this);
      }
      vfptr = *(Expression::IMemberMapVtbl **)p_mNext;
      v10 = (BlendDirectionNode *)p_mNext;
    }
    else
    {
      vfptr = i->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr;
      v10 = i;
    }
    vfptr[1].FindWithOldPath(v10, (const char *)this);
  }
}

// File Line: 165
// RVA: 0x3B5530
void __fastcall PoseRecipeVisitor::Visit(PoseRecipeVisitor *this, AnimationNode *node)
{
  SkeletalAnimation *m_pPointer; // rsi
  UFG::qResourceData *mData; // rdi
  SkeletalAnimation *m_pFallbackAnimation; // rax
  UFG::qResourceData *v7; // rdi
  hkaAnimation *v8; // r14
  int v9; // eax
  __m128 v10; // xmm2
  __m128 v11; // xmm4
  unsigned int v12; // eax
  __m128 v13; // xmm1
  __m128i v14; // xmm5
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  unsigned int v18; // edx
  float v19; // xmm6_4
  __m128 v20; // xmm5
  __m128 v21; // xmm1
  char mCompression; // cl
  __int64 mOffset; // rax
  char v24; // al
  char v25; // al
  bool v26; // zf
  char v27; // al
  bool v28; // cc
  __int64 v29; // rax
  __int64 mStackCount; // rax
  PoseRecipe::AnimData anim; // [rsp+20h] [rbp-48h] BYREF
  float v32; // [rsp+70h] [rbp+8h]

  if ( !this->mIsValid )
    return;
  m_pPointer = node->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  if ( !m_pPointer )
  {
    mStackCount = this->mStackCount;
    if ( (unsigned int)mStackCount >= 0xC0 )
    {
      this->mIsValid = 0;
    }
    else
    {
      UFG::qMemSet(&this->mPoseStack[mStackCount], 0, 0x10u);
      this->mPoseStack[this->mStackCount++].mType = PoseDescType_RestPose;
    }
    return;
  }
  mData = m_pPointer->m_AnimationResourceHandle.mData;
  if ( !mData || (mData = (UFG::qResourceData *)mData[1].mNode.mChild[0]) == 0i64 )
  {
    m_pFallbackAnimation = m_pPointer->m_pFallbackAnimation;
    if ( m_pFallbackAnimation )
    {
      v7 = m_pFallbackAnimation->m_AnimationResourceHandle.mData;
      if ( !v7 )
        goto LABEL_26;
      mData = (UFG::qResourceData *)v7[1].mNode.mChild[0];
    }
    if ( !mData )
      goto LABEL_26;
  }
  if ( ((float (__fastcall *)(AnimationNode *))node->PoseNode::Expression::IMemberMap::vfptr[4].GetResourceOwner)(node) < 0.0 )
  {
LABEL_26:
    v29 = this->mStackCount;
    if ( (unsigned int)v29 >= 0xC0 )
    {
      this->mIsValid = 0;
    }
    else
    {
      UFG::qMemSet(&this->mPoseStack[v29], 0, 0x10u);
      this->mPoseStack[this->mStackCount++].mType = PoseDescType_RestPose;
    }
    return;
  }
  v8 = *(hkaAnimation **)&mData->mNode.mUID;
  v32 = ((float (__fastcall *)(AnimationNode *))node->PoseNode::Expression::IMemberMap::vfptr[4].GetResourceOwner)(node);
  v9 = ((__int64 (__fastcall *)(hkaAnimation *))v8->vfptr[4].__vecDelDtor)(v8) - 1;
  v10 = 0i64;
  v11 = _mm_shuffle_ps((__m128)LODWORD(v8->m_duration), (__m128)LODWORD(v8->m_duration), 0);
  v10.m128_f32[0] = (float)v9;
  v12 = v9 - 1;
  v13 = _mm_rcp_ps(v11);
  v14 = (__m128i)_mm_and_ps(
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v13, v11)), v13),
                       _mm_shuffle_ps((__m128)LODWORD(v32), (__m128)LODWORD(v32), 0)),
                     _mm_shuffle_ps(v10, v10, 0)),
                   _mm_cmplt_ps((__m128)0i64, v11));
  v15 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v14, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v16 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v14, 1u), 1u));
  v17 = _mm_or_ps(
          _mm_andnot_ps(v16, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v14, v15)), v15)),
          _mm_and_ps((__m128)v14, v16));
  v18 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v17));
  if ( v18 <= v12 )
  {
    v20 = _mm_sub_ps((__m128)v14, v17);
    v21 = _mm_cmplt_ps(v20, query.m_quad);
    v19 = fmax(0.0, COERCE_FLOAT(v20.m128_i32[0] & v21.m128_i32[0] | _mm_andnot_ps(v21, query.m_quad).m128_u32[0]));
  }
  else
  {
    v19 = *(float *)&FLOAT_1_0;
    v18 = v12;
  }
  mCompression = m_pPointer->mCompression;
  if ( !mCompression )
  {
    mOffset = m_pPointer->m_pAnimationGroup.mOffset;
    if ( mOffset )
      mOffset += (__int64)&m_pPointer->m_pAnimationGroup;
    mCompression = *(_BYTE *)(mOffset + 201);
  }
  anim.mAnimType = v8->m_type.m_storage;
  v24 = mData->mDebugName[28];
  anim.mFrameIndex = v18;
  anim.mBlendHint = v24;
  anim.mNumTransformTracks = v8->m_numberOfTransformTracks;
  v25 = -1;
  if ( mCompression == 5 )
    v25 = 13;
  v26 = node->mPoseOnFrameBoundaries == 0;
  anim.mRootRetargetIndex = v25;
  if ( v26 )
    anim.mFrameDelta = v19;
  else
    anim.mFrameDelta = 0.0;
  v27 = ((__int64 (__fastcall *)(hkaAnimation *))v8->vfptr[4].__first_virtual_table_function__)(v8);
  v28 = SLODWORD(mData->mResourceHandles.mNode.mNext) <= 0;
  anim.mTrackToBoneIndices = 0i64;
  anim.mNumDataChunks = v27;
  if ( !v28 )
    anim.mTrackToBoneIndices = (unsigned __int16 *)mData->mResourceHandles.mNode.mPrev;
  PoseRecipeVisitor::AddAnim(this, &anim, v8);
}

// File Line: 228
// RVA: 0x3A4FD0
void __fastcall PoseRecipeVisitor::CommitAnimData(PoseRecipeVisitor *this)
{
  unsigned int i; // esi
  hkaAnimation *v3; // r14
  __int64 v4; // rdi
  unsigned __int8 mNumDataChunks; // al
  char *v6; // rax
  int v7; // edx
  int v8; // eax
  PoseRecipe *mRecipe; // rcx
  unsigned int v10; // eax

  if ( this->mIsValid )
  {
    for ( i = 0; i < this->mAnimDataCount; ++i )
    {
      v3 = this->mAnimList[i];
      v4 = i;
      mNumDataChunks = this->mAnimData[v4].mNumDataChunks;
      if ( mNumDataChunks )
      {
        v6 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 16 * (unsigned int)mNumDataChunks, 0x10u);
        v7 = (unsigned __int8)this->mAnimData[v4].mNumDataChunks;
        this->mAnimData[v4].mDataChunks = (hkaAnimation::DataChunk *)v6;
        ((void (__fastcall *)(hkaAnimation *, _QWORD, hkBaseObjectVtbl *, char *, int))v3->vfptr[5].__vecDelDtor)(
          v3,
          this->mAnimData[v4].mFrameIndex,
          v3->vfptr,
          v6,
          v7);
        v8 = ((__int64 (__fastcall *)(hkaAnimation *))v3->vfptr[5].__first_virtual_table_function__)(v3);
        mRecipe = this->mRecipe;
        v10 = (v8 + 15) & 0xFFFFFFF0;
        if ( v10 > mRecipe->mAnimMemoryHighWaterMark )
          mRecipe->mAnimMemoryHighWaterMark = v10;
      }
      else
      {
        this->mAnimData[v4].mDataChunks = 0i64;
      }
    }
  }
}

// File Line: 255
// RVA: 0x3B59F0
void __fastcall PoseRecipeVisitor::Visit(PoseRecipeVisitor *this, BlendHistoryNode *node)
{
  float ActivePoses; // xmm0_4
  PoseNode *v4; // rsi
  PoseNode *v5; // rdi
  __int64 mStackCount; // rax
  __int64 v7; // rax
  PoseNode *poseNode0; // [rsp+30h] [rbp+8h] BYREF
  PoseNode *poseNodeF; // [rsp+40h] [rbp+18h] BYREF

  if ( this->mIsValid )
  {
    poseNode0 = 0i64;
    poseNodeF = 0i64;
    ActivePoses = BlendHistoryNode::getActivePoses(node, &poseNode0, &poseNodeF);
    v4 = poseNode0;
    if ( poseNode0 && (v5 = poseNodeF) != 0i64 )
    {
      if ( !gBlendedMode )
      {
        if ( ActivePoses > 0.5 )
        {
          poseNodeF->Expression::IMemberMap::vfptr[1].FindWithOldPath(poseNodeF, (const char *)this);
          return;
        }
        goto LABEL_9;
      }
      if ( ActivePoses < 0.000099999997 )
      {
LABEL_9:
        poseNode0->Expression::IMemberMap::vfptr[1].FindWithOldPath(poseNode0, (const char *)this);
        return;
      }
      if ( ActivePoses <= 0.99989998 )
      {
        mStackCount = this->mStackCount;
        *(float *)&poseNode0 = ActivePoses;
        if ( (unsigned int)mStackCount >= 0xC0 )
        {
          this->mIsValid = 0;
        }
        else
        {
          UFG::qMemSet(&this->mPoseStack[mStackCount], 0, 0x10u);
          this->mPoseStack[this->mStackCount].mType = PoseDescType_Blend;
          this->mPoseStack[this->mStackCount++].mBlend.mPerBoneWeights = (float *)poseNode0;
        }
        v4->Expression::IMemberMap::vfptr[1].FindWithOldPath(v4, (const char *)this);
      }
      v5->Expression::IMemberMap::vfptr[1].FindWithOldPath(v5, (const char *)this);
    }
    else
    {
      v7 = this->mStackCount;
      if ( (unsigned int)v7 >= 0xC0 )
      {
        this->mIsValid = 0;
      }
      else
      {
        UFG::qMemSet(&this->mPoseStack[v7], 0, 0x10u);
        this->mPoseStack[this->mStackCount++].mType = PoseDescType_RestPose;
      }
    }
  }
}

// File Line: 305
// RVA: 0x3AD020
void __fastcall PoseRecipeVisitor::PopulateBlendNodeCommon(
        PoseRecipeVisitor *this,
        PoseRecipe *recipe,
        BlendNode *node,
        PoseRecipe::BlendDesc::BlendType type)
{
  int mBoneUpdateCount; // eax
  signed int mBoneCount; // ebx
  float v9; // xmm0_4
  float *Weights; // rbx
  float v11; // xmm1_4
  float v12; // xmm0_4
  int v13; // esi
  __int64 mStackCount; // rax
  bool v15; // si
  PoseRecipe::PoseDescType v16; // ecx
  __int64 v17; // rax
  bool v18; // si
  __int64 v19; // rax
  bool v20; // si
  float *v21; // [rsp+40h] [rbp+18h]

  if ( !node->mWeightSet )
  {
    v11 = *(float *)&FLOAT_1_0;
    v12 = (float)(sinf((float)(node->mBlendParam * 3.1415927) - 1.5707964) + 1.0) * 0.5;
    if ( v12 <= 0.0 )
    {
      v12 = 0.0;
    }
    else if ( v12 >= 1.0 )
    {
      goto LABEL_15;
    }
    v11 = v12;
LABEL_15:
    *(float *)&v21 = v11;
    Weights = v21;
    goto LABEL_16;
  }
  mBoneUpdateCount = recipe->mBoneUpdateCount;
  mBoneCount = recipe->mSkelDesc.mBoneCount;
  if ( mBoneUpdateCount >= 0 && mBoneUpdateCount < mBoneCount )
    mBoneCount = recipe->mBoneUpdateCount;
  v9 = (float)(sinf((float)(node->mBlendParam * 3.1415927) - 1.5707964) + 1.0) * 0.5;
  if ( v9 <= 0.0 )
  {
    v9 = 0.0;
  }
  else if ( v9 >= 1.0 )
  {
    Weights = BlendNode::GetWeights(node, mBoneCount, 1.0);
    goto LABEL_16;
  }
  Weights = BlendNode::GetWeights(node, mBoneCount, v9);
LABEL_16:
  if ( type )
  {
    v13 = type - 1;
    if ( v13 )
    {
      if ( v13 != 1 )
        return;
      mStackCount = this->mStackCount;
      v15 = node->mWeightSet != 0i64;
      if ( (unsigned int)mStackCount < 0xC0 )
      {
        UFG::qMemSet(&this->mPoseStack[mStackCount], 0, 0x10u);
        v16 = v15 + 7;
LABEL_25:
        this->mPoseStack[this->mStackCount].mType = v16;
        this->mPoseStack[this->mStackCount++].mBlend.mPerBoneWeights = Weights;
        return;
      }
    }
    else
    {
      v17 = this->mStackCount;
      v18 = node->mWeightSet != 0i64;
      if ( (unsigned int)v17 < 0xC0 )
      {
        UFG::qMemSet(&this->mPoseStack[v17], 0, 0x10u);
        v16 = v18 + 5;
        goto LABEL_25;
      }
    }
  }
  else
  {
    v19 = this->mStackCount;
    v20 = node->mWeightSet != 0i64;
    if ( (unsigned int)v19 < 0xC0 )
    {
      UFG::qMemSet(&this->mPoseStack[v19], 0, 0x10u);
      v16 = v20 + 3;
      goto LABEL_25;
    }
  }
  this->mIsValid = 0;
}

// File Line: 339
// RVA: 0x3A50C0
__int64 __fastcall PoseRecipeVisitor::CommitData(PoseRecipeVisitor *this)
{
  char v1; // r15
  unsigned int v2; // ebp
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int mStackCount; // edx
  UFG::qLinearAllocator *FrameMemory; // r13
  __int64 v8; // r14
  unsigned int i; // ebx
  char *v10; // rcx
  unsigned int mAnimDataCount; // edx
  char *v12; // rbx
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax

  v1 = 0;
  v2 = -1;
  if ( this->mIsValid )
  {
    this->mRecipe->mStackCount = this->mStackCount;
    this->mRecipe->mAnimDataCount = this->mAnimDataCount;
    v4 = UFG::qDataHash32((char *)&this->mStackCount, 4ui64, 0xFFFFFFFF);
    v5 = UFG::qDataHash32((char *)&this->mAnimDataCount, 4ui64, v4);
    mStackCount = this->mStackCount;
    FrameMemory = Illusion::gEngine.FrameMemory;
    v2 = v5;
    if ( mStackCount )
    {
      this->mRecipe->mPoseStack = (PoseRecipe::PoseStackEntry *)UFG::qLinearAllocator::Malloc(
                                                                  Illusion::gEngine.FrameMemory,
                                                                  16 * mStackCount,
                                                                  0x10u);
      UFG::qMemCopy(this->mRecipe->mPoseStack, this->mPoseStack, 16 * this->mStackCount);
      v8 = 0i64;
      for ( i = 0; i < this->mStackCount; ++i )
      {
        v10 = (char *)&this->mPoseStack[i];
        if ( *(_DWORD *)v10 <= 2u )
          v2 = UFG::qDataHash32(v10, 0x10ui64, v2);
        else
          v1 = 1;
      }
      mAnimDataCount = this->mAnimDataCount;
      if ( mAnimDataCount )
      {
        this->mRecipe->mAnimData = (PoseRecipe::AnimData *)UFG::qLinearAllocator::Malloc(
                                                             FrameMemory,
                                                             32 * mAnimDataCount,
                                                             0x10u);
        UFG::qMemCopy(this->mRecipe->mAnimData, this->mAnimData, 32 * this->mAnimDataCount);
        if ( this->mAnimDataCount )
        {
          do
          {
            v12 = (char *)this + 32 * (unsigned int)v8;
            v13 = UFG::qDataHash32(v12 + 3112, 1ui64, v2);
            v14 = UFG::qDataHash32(v12 + 3113, 1ui64, v13);
            v15 = UFG::qDataHash32(v12 + 3115, 1ui64, v14);
            v16 = UFG::qDataHash32(v12 + 3116, 1ui64, v15);
            v17 = UFG::qDataHash32(v12 + 3120, 4ui64, v16);
            v18 = UFG::qDataHash32(v12 + 3114, 1ui64, v17);
            v19 = UFG::qDataHash32(v12 + 3128, 8ui64, v18);
            v20 = UFG::qDataHash32((char *)this->mAnimList[v8], 8ui64, v19);
            v8 = (unsigned int)(v8 + 1);
            v2 = v20;
          }
          while ( (unsigned int)v8 < this->mAnimDataCount );
        }
      }
    }
  }
  else
  {
    this->mRecipe->mStackCount = 0;
    this->mRecipe->mAnimDataCount = 0;
  }
  if ( v1 )
    return (unsigned int)-1;
  return v2;
}


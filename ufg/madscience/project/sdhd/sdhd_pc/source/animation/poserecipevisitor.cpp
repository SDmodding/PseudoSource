// File Line: 38
// RVA: 0x3B5DB0
void __fastcall PoseRecipeVisitor::Visit(ResourceOpportunityVisitor *this, PoseNodeParent *node)
{
  ResourceOpportunityVisitor *v2; // rdi
  int *v3; // rsi
  PoseNodeParent *v4; // rbx

  v2 = this;
  if ( this->mRecurse )
  {
    v3 = &node->mNetPoseSequence;
    v4 = (PoseNodeParent *)&node->mChildren.mNode.mNext[-3].mNext;
    if ( v4 != (PoseNodeParent *)&node->mNetPoseSequence )
    {
      do
      {
        v4->vfptr[1].FindWithOldPath((Expression::IMemberMap *)&v4->vfptr, (const char *)v2);
        v4 = (PoseNodeParent *)&v4->mNext[-3].mNext;
      }
      while ( v4 != (PoseNodeParent *)v3 );
    }
  }
}

// File Line: 43
// RVA: 0x3B5BA0
void __fastcall PoseRecipeVisitor::Visit(PoseRecipeVisitor *this, BlendPhaseNode *node)
{
  BlendPhaseNode *v2; // rsi
  PoseRecipeVisitor *v3; // rdi
  float v4; // xmm0_4
  signed int v5; // eax
  UFG::qNode<PoseNode,PoseNode> **v6; // rcx
  signed __int64 v7; // rsi
  UFG::qNode<PoseNode,PoseNode> *v8; // rbx
  signed __int64 v9; // rsi
  UFG::qNode<PoseNode,PoseNode> **i; // rbx

  v2 = node;
  v3 = this;
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
      ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, PoseRecipeVisitor *))v2->mChildren.mNode.mNext[-3].mNext[5].mPrev)(
        &v2->mChildren.mNode.mNext[-3].mNext,
        v3);
      return;
    }
    if ( v4 <= 0.99989998 )
      goto LABEL_14;
  }
  if ( !v2->mWeightSet )
  {
    v5 = 1;
    v6 = &v2->mChildren.mNode.mNext[-3].mNext;
    v7 = (signed __int64)&v2->mNetPoseSequence;
    do
    {
      if ( v6 == (UFG::qNode<PoseNode,PoseNode> **)v7 )
        break;
      --v5;
      v6 = &v6[6][-3].mNext;
    }
    while ( v5 > 0 );
    ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, PoseRecipeVisitor *))(*v6)[5].mPrev)(v6, v3);
    return;
  }
LABEL_14:
  PoseRecipeVisitor::PopulateBlendNodeCommon(v3, v3->mRecipe, (BlendNode *)&v2->vfptr, 0);
  if ( v3->mRecurse )
  {
    v8 = v2->mChildren.mNode.mNext;
    v9 = (signed __int64)&v2->mNetPoseSequence;
    for ( i = &v8[-3].mNext; i != (UFG::qNode<PoseNode,PoseNode> **)v9; i = &i[6][-3].mNext )
      ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, PoseRecipeVisitor *))(*i)[5].mPrev)(i, v3);
  }
}

// File Line: 68
// RVA: 0x3B5800
void __fastcall PoseRecipeVisitor::Visit(PoseRecipeVisitor *this, BlendAddNode *node)
{
  BlendAddNode *v2; // rsi
  PoseRecipeVisitor *v3; // rdi
  float v4; // xmm0_4
  UFG::qNode<PoseNode,PoseNode> *v5; // rbx
  signed __int64 v6; // rsi
  UFG::qNode<PoseNode,PoseNode> **i; // rbx

  v2 = node;
  v3 = this;
  if ( this->mIsValid )
  {
    v4 = (float)(sinf((float)(node->mBlendParam * 3.1415927) - 1.5707964) + 1.0) * 0.5;
    if ( v4 <= 0.0 || v4 < 1.0 && v4 < 0.000099999997 )
    {
      ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, PoseRecipeVisitor *))v2->mChildren.mNode.mNext[-3].mNext[5].mPrev)(
        &v2->mChildren.mNode.mNext[-3].mNext,
        v3);
    }
    else
    {
      PoseRecipeVisitor::PopulateBlendNodeCommon(v3, v3->mRecipe, (BlendNode *)&v2->vfptr, ADD);
      if ( v3->mRecurse )
      {
        v5 = v2->mChildren.mNode.mNext;
        v6 = (signed __int64)&v2->mNetPoseSequence;
        for ( i = &v5[-3].mNext; i != (UFG::qNode<PoseNode,PoseNode> **)v6; i = &i[6][-3].mNext )
          ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, PoseRecipeVisitor *))(*i)[5].mPrev)(i, v3);
      }
    }
  }
}

// File Line: 88
// RVA: 0x3B5CD0
void __fastcall PoseRecipeVisitor::Visit(PoseRecipeVisitor *this, BlendSubNode *node)
{
  BlendSubNode *v2; // rsi
  PoseRecipeVisitor *v3; // rdi
  float v4; // xmm0_4
  UFG::qNode<PoseNode,PoseNode> *v5; // rbx
  signed __int64 v6; // rsi
  UFG::qNode<PoseNode,PoseNode> **i; // rbx

  v2 = node;
  v3 = this;
  if ( this->mIsValid )
  {
    v4 = (float)(sinf((float)(node->mBlendParam * 3.1415927) - 1.5707964) + 1.0) * 0.5;
    if ( v4 <= 0.0 || v4 < 1.0 && v4 < 0.000099999997 )
    {
      ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, PoseRecipeVisitor *))v2->mChildren.mNode.mNext[-3].mNext[5].mPrev)(
        &v2->mChildren.mNode.mNext[-3].mNext,
        v3);
    }
    else
    {
      PoseRecipeVisitor::PopulateBlendNodeCommon(v3, v3->mRecipe, (BlendNode *)&v2->vfptr, SUB);
      if ( v3->mRecurse )
      {
        v5 = v2->mChildren.mNode.mNext;
        v6 = (signed __int64)&v2->mNetPoseSequence;
        for ( i = &v5[-3].mNext; i != (UFG::qNode<PoseNode,PoseNode> **)v6; i = &i[6][-3].mNext )
          ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, PoseRecipeVisitor *))(*i)[5].mPrev)(i, v3);
      }
    }
  }
}

// File Line: 133
// RVA: 0x3B58E0
void __fastcall PoseRecipeVisitor::Visit(PoseRecipeVisitor *this, BlendDirectionNode *node)
{
  PoseRecipeVisitor *v2; // rsi
  int v3; // ecx
  float v4; // xmm0_4
  UFG::qNode<PoseNode,PoseNode> **v5; // rbx
  BlendDirectionNode *i; // rdi
  int v7; // eax
  int *v8; // rdx
  Expression::IMemberMapVtbl *v9; // rax
  BlendDirectionNode *v10; // rcx
  __int64 v11; // rax
  __int64 v12; // [rsp+30h] [rbp+8h]

  v2 = this;
  if ( this->mIsValid )
  {
    v3 = node->mChild0ID;
    v4 = node->mWeight;
    v5 = &node->mChildren.mNode.mNext[-3].mNext;
    for ( i = (BlendDirectionNode *)&node->mChildren.mNode.mNext[-3].mNext;
          v3 > 0;
          i = (BlendDirectionNode *)&i->mNext[-3].mNext )
    {
      if ( i == (BlendDirectionNode *)&node->mNetPoseSequence )
        break;
      --v3;
    }
    v7 = node->mChild1ID;
    if ( v7 > 0 )
    {
      v8 = &node->mNetPoseSequence;
      do
      {
        if ( v5 == (UFG::qNode<PoseNode,PoseNode> **)v8 )
          break;
        --v7;
        v5 = &v5[6][-3].mNext;
      }
      while ( v7 > 0 );
    }
    if ( v4 >= 0.000099999997 )
    {
      if ( v4 <= 0.99989998 )
      {
        v11 = v2->mStackCount;
        *(float *)&v12 = v4;
        if ( (unsigned int)v11 >= 0xC0 )
        {
          v2->mIsValid = 0;
        }
        else
        {
          UFG::qMemSet(&v2->mPoseStack[v11], 0, 0x10u);
          v2->mPoseStack[v2->mStackCount].mType = 3;
          *((_QWORD *)&v2->vfptr + 2 * (v2->mStackCount++ + 3i64)) = v12;
        }
        i->vfptr[1].FindWithOldPath((Expression::IMemberMap *)&i->vfptr, (const char *)v2);
      }
      v9 = (Expression::IMemberMapVtbl *)*v5;
      v10 = (BlendDirectionNode *)v5;
    }
    else
    {
      v9 = i->vfptr;
      v10 = i;
    }
    v9[1].FindWithOldPath((Expression::IMemberMap *)&v10->vfptr, (const char *)v2);
  }
}

// File Line: 165
// RVA: 0x3B5530
void __usercall PoseRecipeVisitor::Visit(PoseRecipeVisitor *this@<rcx>, AnimationNode *node@<rdx>, float a3@<xmm0>)
{
  AnimationNode *v3; // r15
  PoseRecipeVisitor *v4; // rbx
  SkeletalAnimation *v5; // rsi
  UFG::qResourceData *v6; // rdi
  SkeletalAnimation *v7; // rax
  UFG::qResourceData *v8; // rdi
  hkaAnimation *v9; // r14
  signed int v10; // eax
  __m128 v11; // xmm2
  __m128 v12; // xmm4
  unsigned int v13; // eax
  __m128 v14; // xmm1
  __m128i v15; // xmm5
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  unsigned int v19; // edx
  float v20; // xmm6_4
  __m128 v21; // xmm5
  __m128 v22; // xmm1
  char v23; // cl
  __int64 v24; // rax
  char v25; // al
  char v26; // al
  bool v27; // zf
  char v28; // al
  bool v29; // sf
  __int64 v30; // rax
  __int64 v31; // rax
  PoseRecipe::AnimData anim; // [rsp+20h] [rbp-48h]

  v3 = node;
  v4 = this;
  if ( !this->mIsValid )
    return;
  v5 = node->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  if ( !v5 )
  {
    v31 = this->mStackCount;
    if ( (unsigned int)v31 >= 0xC0 )
    {
      this->mIsValid = 0;
    }
    else
    {
      UFG::qMemSet(&this->mPoseStack[v31], 0, 0x10u);
      v4->mPoseStack[v4->mStackCount++].mType = 0;
    }
    return;
  }
  v6 = v5->m_AnimationResourceHandle.mData;
  if ( !v6 || (v6 = (UFG::qResourceData *)v6[1].mNode.mChild[0]) == 0i64 )
  {
    v7 = v5->m_pFallbackAnimation;
    if ( v7 )
    {
      v8 = v7->m_AnimationResourceHandle.mData;
      if ( !v8 )
        goto LABEL_26;
      v6 = (UFG::qResourceData *)v8[1].mNode.mChild[0];
    }
    if ( !v6 )
      goto LABEL_26;
  }
  node->vfptr[4].GetResourceOwner((Expression::IMemberMap *)node);
  if ( a3 < 0.0 )
  {
LABEL_26:
    v30 = v4->mStackCount;
    if ( (unsigned int)v30 >= 0xC0 )
    {
      v4->mIsValid = 0;
    }
    else
    {
      UFG::qMemSet(&v4->mPoseStack[v30], 0, 0x10u);
      v4->mPoseStack[v4->mStackCount++].mType = 0;
    }
    return;
  }
  v9 = *(hkaAnimation **)&v6->mNode.mUID;
  v3->vfptr[4].GetResourceOwner((Expression::IMemberMap *)&v3->vfptr);
  v10 = (unsigned __int64)((__int64 (__fastcall *)(hkaAnimation *))v9->vfptr[4].__vecDelDtor)(v9) - 1;
  v11 = 0i64;
  v12 = _mm_shuffle_ps((__m128)LODWORD(v9->m_duration), (__m128)LODWORD(v9->m_duration), 0);
  v11.m128_f32[0] = (float)v10;
  v13 = v10 - 1;
  v14 = _mm_rcp_ps(v12);
  v15 = (__m128i)_mm_and_ps(
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v14, v12)), v14),
                       _mm_shuffle_ps((__m128)LODWORD(a3), (__m128)LODWORD(a3), 0)),
                     _mm_shuffle_ps(v11, v11, 0)),
                   _mm_cmpltps((__m128)0i64, v12));
  v16 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v15, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v17 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v15, 1u), 1u));
  v18 = _mm_or_ps(
          _mm_andnot_ps(v17, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v15, v16)), v16)),
          _mm_and_ps((__m128)v15, v17));
  v19 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v18));
  if ( v19 <= v13 )
  {
    v21 = _mm_sub_ps((__m128)v15, v18);
    v22 = _mm_cmpltps(v21, query.m_quad);
    v20 = fmax(
            0.0,
            COERCE_FLOAT(v21.m128_i32[0] & v22.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(v22, query.m_quad)));
  }
  else
  {
    v20 = *(float *)&FLOAT_1_0;
    v19 = v13;
  }
  v23 = v5->mCompression;
  if ( !v23 )
  {
    v24 = v5->m_pAnimationGroup.mOffset;
    if ( v24 )
      v24 += (__int64)&v5->m_pAnimationGroup;
    v23 = *(_BYTE *)(v24 + 201);
  }
  anim.mAnimType = v9->m_type.m_storage;
  v25 = v6->mDebugName[28];
  anim.mFrameIndex = v19;
  anim.mBlendHint = v25;
  anim.mNumTransformTracks = v9->m_numberOfTransformTracks;
  v26 = -1;
  if ( v23 == 5 )
    v26 = 13;
  v27 = v3->mPoseOnFrameBoundaries == 0;
  anim.mRootRetargetIndex = v26;
  if ( v27 )
    anim.mFrameDelta = v20;
  else
    anim.mFrameDelta = 0.0;
  v28 = ((__int64 (__fastcall *)(hkaAnimation *))v9->vfptr[4].__first_virtual_table_function__)(v9);
  v27 = LODWORD(v6->mResourceHandles.mNode.mNext) == 0;
  v29 = SLODWORD(v6->mResourceHandles.mNode.mNext) < 0;
  anim.mTrackToBoneIndices = 0i64;
  anim.mNumDataChunks = v28;
  if ( !v29 && !v27 )
    anim.mTrackToBoneIndices = (unsigned __int16 *)v6->mResourceHandles.mNode.mPrev;
  PoseRecipeVisitor::AddAnim(v4, &anim, v9);
}

// File Line: 228
// RVA: 0x3A4FD0
void __fastcall PoseRecipeVisitor::CommitAnimData(PoseRecipeVisitor *this)
{
  PoseRecipeVisitor *v1; // rbx
  unsigned int v2; // esi
  hkaAnimation *v3; // r14
  signed __int64 v4; // rdi
  unsigned __int8 v5; // al
  char *v6; // rax
  int v7; // edx
  __int128 v8; // xmm2
  int v9; // eax
  PoseRecipe *v10; // rcx
  unsigned int v11; // eax
  _QWORD v12[3]; // [rsp+20h] [rbp-18h]

  v1 = this;
  if ( this->mIsValid )
  {
    v2 = 0;
    if ( this->mAnimDataCount )
    {
      do
      {
        v3 = v1->mAnimList[v2];
        v4 = v2;
        v5 = v1->mAnimData[v4].mNumDataChunks;
        if ( v5 )
        {
          v6 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 16 * (unsigned int)v5, 0x10u);
          v7 = (unsigned __int8)v1->mAnimData[v4].mNumDataChunks;
          v8 = LODWORD(v1->mAnimData[v4].mFrameDelta);
          v1->mAnimData[v4].mDataChunks = (hkaAnimation::DataChunk *)v6;
          LODWORD(v12[0]) = v7;
          ((void (__fastcall *)(hkaAnimation *, _QWORD, hkBaseObjectVtbl *, char *, _QWORD))v3->vfptr[5].__vecDelDtor)(
            v3,
            v1->mAnimData[v4].mFrameIndex,
            v3->vfptr,
            v6,
            v12[0]);
          v9 = ((__int64 (__fastcall *)(hkaAnimation *))v3->vfptr[5].__first_virtual_table_function__)(v3);
          v10 = v1->mRecipe;
          v11 = (v9 + 15) & 0xFFFFFFF0;
          if ( v11 > v10->mAnimMemoryHighWaterMark )
            v10->mAnimMemoryHighWaterMark = v11;
        }
        else
        {
          v1->mAnimData[v4].mDataChunks = 0i64;
        }
        ++v2;
      }
      while ( v2 < v1->mAnimDataCount );
    }
  }
}

// File Line: 255
// RVA: 0x3B59F0
void __fastcall PoseRecipeVisitor::Visit(PoseRecipeVisitor *this, BlendHistoryNode *node)
{
  PoseRecipeVisitor *v2; // rbx
  float v3; // xmm0_4
  PoseNode *v4; // rsi
  PoseNode *v5; // rdi
  __int64 v6; // rax
  __int64 v7; // rax
  PoseNode *poseNode0; // [rsp+30h] [rbp+8h]
  PoseNode *poseNodeF; // [rsp+40h] [rbp+18h]

  v2 = this;
  if ( this->mIsValid )
  {
    poseNode0 = 0i64;
    poseNodeF = 0i64;
    v3 = BlendHistoryNode::getActivePoses(node, &poseNode0, &poseNodeF);
    v4 = poseNode0;
    if ( poseNode0 && (v5 = poseNodeF) != 0i64 )
    {
      if ( gBlendedMode )
      {
        if ( v3 >= 0.000099999997 )
        {
          if ( v3 <= 0.99989998 )
          {
            v6 = v2->mStackCount;
            *(float *)&poseNode0 = v3;
            if ( (unsigned int)v6 >= 0xC0 )
            {
              v2->mIsValid = 0;
            }
            else
            {
              UFG::qMemSet(&v2->mPoseStack[v6], 0, 0x10u);
              v2->mPoseStack[v2->mStackCount].mType = 3;
              *((_QWORD *)&v2->vfptr + 2 * (v2->mStackCount++ + 3i64)) = poseNode0;
            }
            v4->vfptr[1].FindWithOldPath((Expression::IMemberMap *)&v4->vfptr, (const char *)v2);
          }
          v5->vfptr[1].FindWithOldPath((Expression::IMemberMap *)&v5->vfptr, (const char *)v2);
        }
        else
        {
          poseNode0->vfptr[1].FindWithOldPath((Expression::IMemberMap *)poseNode0, (const char *)v2);
        }
      }
      else if ( v3 <= 0.5 )
      {
        poseNode0->vfptr[1].FindWithOldPath((Expression::IMemberMap *)poseNode0, (const char *)v2);
      }
      else
      {
        poseNodeF->vfptr[1].FindWithOldPath((Expression::IMemberMap *)poseNodeF, (const char *)v2);
      }
    }
    else
    {
      v7 = v2->mStackCount;
      if ( (unsigned int)v7 >= 0xC0 )
      {
        v2->mIsValid = 0;
      }
      else
      {
        UFG::qMemSet(&v2->mPoseStack[v7], 0, 0x10u);
        v2->mPoseStack[v2->mStackCount++].mType = 0;
      }
    }
  }
}

// File Line: 305
// RVA: 0x3AD020
void __fastcall PoseRecipeVisitor::PopulateBlendNodeCommon(PoseRecipeVisitor *this, PoseRecipe *recipe, BlendNode *node, PoseRecipe::BlendDesc::BlendType type)
{
  PoseRecipe::BlendDesc::BlendType v4; // esi
  BlendNode *v5; // rbp
  PoseRecipeVisitor *v6; // rdi
  int v7; // eax
  int v8; // ebx
  float v9; // xmm0_4
  float *v10; // rbx
  float v11; // xmm1_4
  float v12; // xmm0_4
  int v13; // esi
  __int64 v14; // rax
  bool v15; // si
  int v16; // ecx
  __int64 v17; // rax
  bool v18; // si
  __int64 v19; // rax
  bool v20; // si
  float *v21; // [rsp+40h] [rbp+18h]

  v4 = type;
  v5 = node;
  v6 = this;
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
    v10 = v21;
    goto LABEL_16;
  }
  v7 = recipe->mBoneUpdateCount;
  v8 = recipe->mSkelDesc.mBoneCount;
  if ( v7 >= 0 && v7 < v8 )
    v8 = recipe->mBoneUpdateCount;
  v9 = (float)(sinf((float)(node->mBlendParam * 3.1415927) - 1.5707964) + 1.0) * 0.5;
  if ( v9 <= 0.0 )
  {
    v9 = 0.0;
  }
  else if ( v9 >= 1.0 )
  {
    v10 = BlendNode::GetWeights(v5, v8, 1.0);
    goto LABEL_16;
  }
  v10 = BlendNode::GetWeights(v5, v8, v9);
LABEL_16:
  if ( v4 )
  {
    v13 = v4 - 1;
    if ( v13 )
    {
      if ( v13 != 1 )
        return;
      v14 = v6->mStackCount;
      v15 = v5->mWeightSet != 0i64;
      if ( (unsigned int)v14 < 0xC0 )
      {
        UFG::qMemSet(&v6->mPoseStack[v14], 0, 0x10u);
        v16 = (v15 != 0) + 7;
LABEL_25:
        v6->mPoseStack[v6->mStackCount].mType = v16;
        *((_QWORD *)&v6->vfptr + 2 * (v6->mStackCount++ + 3i64)) = v10;
        return;
      }
    }
    else
    {
      v17 = v6->mStackCount;
      v18 = v5->mWeightSet != 0i64;
      if ( (unsigned int)v17 < 0xC0 )
      {
        UFG::qMemSet(&v6->mPoseStack[v17], 0, 0x10u);
        v16 = (v18 != 0) + 5;
        goto LABEL_25;
      }
    }
  }
  else
  {
    v19 = v6->mStackCount;
    v20 = v5->mWeightSet != 0i64;
    if ( (unsigned int)v19 < 0xC0 )
    {
      UFG::qMemSet(&v6->mPoseStack[v19], 0, 0x10u);
      v16 = (v20 != 0) + 3;
      goto LABEL_25;
    }
  }
  v6->mIsValid = 0;
}

// File Line: 339
// RVA: 0x3A50C0
__int64 __fastcall PoseRecipeVisitor::CommitData(PoseRecipeVisitor *this)
{
  char v1; // r15
  unsigned int v2; // ebp
  PoseRecipeVisitor *v3; // rsi
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // edx
  UFG::qLinearAllocator *v7; // r13
  __int64 v8; // r14
  unsigned int v9; // ebx
  PoseRecipe::PoseStackEntry *v10; // rcx
  unsigned int v11; // edx
  signed __int64 v12; // rbx
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
  v3 = this;
  if ( this->mIsValid )
  {
    this->mRecipe->mStackCount = this->mStackCount;
    this->mRecipe->mAnimDataCount = this->mAnimDataCount;
    v4 = UFG::qDataHash32(&this->mStackCount, 4ui64, 0xFFFFFFFF);
    v5 = UFG::qDataHash32(&v3->mAnimDataCount, 4ui64, v4);
    v6 = v3->mStackCount;
    v7 = Illusion::gEngine.FrameMemory;
    v2 = v5;
    if ( v6 )
    {
      v3->mRecipe->mPoseStack = (PoseRecipe::PoseStackEntry *)UFG::qLinearAllocator::Malloc(
                                                                Illusion::gEngine.FrameMemory,
                                                                16 * v6,
                                                                0x10u);
      UFG::qMemCopy(v3->mRecipe->mPoseStack, v3->mPoseStack, 16 * v3->mStackCount);
      v8 = 0i64;
      v9 = 0;
      if ( v3->mStackCount )
      {
        do
        {
          v10 = &v3->mPoseStack[v9];
          if ( v10->mType <= 2u )
            v2 = UFG::qDataHash32(v10, 0x10ui64, v2);
          else
            v1 = 1;
          ++v9;
        }
        while ( v9 < v3->mStackCount );
      }
      v11 = v3->mAnimDataCount;
      if ( v11 )
      {
        v3->mRecipe->mAnimData = (PoseRecipe::AnimData *)UFG::qLinearAllocator::Malloc(v7, 32 * v11, 0x10u);
        UFG::qMemCopy(v3->mRecipe->mAnimData, v3->mAnimData, 32 * v3->mAnimDataCount);
        if ( v3->mAnimDataCount > 0 )
        {
          do
          {
            v12 = (signed __int64)v3 + 32 * (unsigned int)v8;
            v13 = UFG::qDataHash32((const void *)(v12 + 3112), 1ui64, v2);
            v14 = UFG::qDataHash32((const void *)(v12 + 3113), 1ui64, v13);
            v15 = UFG::qDataHash32((const void *)(v12 + 3115), 1ui64, v14);
            v16 = UFG::qDataHash32((const void *)(v12 + 3116), 1ui64, v15);
            v17 = UFG::qDataHash32((const void *)(v12 + 3120), 4ui64, v16);
            v18 = UFG::qDataHash32((const void *)(v12 + 3114), 1ui64, v17);
            v19 = UFG::qDataHash32((const void *)(v12 + 3128), 8ui64, v18);
            v20 = UFG::qDataHash32(v3->mAnimList[v8], 8ui64, v19);
            v8 = (unsigned int)(v8 + 1);
            v2 = v20;
          }
          while ( (unsigned int)v8 < v3->mAnimDataCount );
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
    v2 = -1;
  return v2;
}


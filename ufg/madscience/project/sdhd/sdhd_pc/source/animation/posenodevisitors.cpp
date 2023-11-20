// File Line: 29
// RVA: 0x3B5F50
void __fastcall PoseStackCalculatorVisitor::Visit(PoseStackCalculatorVisitor *this, BlendPhaseNode *node)
{
  BlendPhaseNode *v2; // rsi
  PoseStackCalculatorVisitor *v3; // rdi
  float v4; // xmm0_4
  signed int v5; // eax
  UFG::qNode<PoseNode,PoseNode> **v6; // rcx
  signed __int64 v7; // rsi
  UFG::qNode<PoseNode,PoseNode> *v8; // rbx
  signed __int64 v9; // rsi
  UFG::qNode<PoseNode,PoseNode> **i; // rbx

  v2 = node;
  v3 = this;
  v4 = (float)(sinf((float)(node->mBlendParam * 3.1415927) - 1.5707964) + 1.0) * 0.5;
  if ( v4 <= 0.0 )
  {
    v4 = 0.0;
    goto LABEL_5;
  }
  if ( v4 < 1.0 )
  {
LABEL_5:
    if ( v4 < 0.000099999997 )
    {
      ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, PoseStackCalculatorVisitor *))v2->mChildren.mNode.mNext[-3].mNext[5].mPrev)(
        &v2->mChildren.mNode.mNext[-3].mNext,
        v3);
      return;
    }
    if ( v4 <= 0.99989998 )
      goto LABEL_13;
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
    ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, PoseStackCalculatorVisitor *))(*v6)[5].mPrev)(v6, v3);
    return;
  }
LABEL_13:
  ++v3->mStackCount;
  if ( v3->mRecurse )
  {
    v8 = v2->mChildren.mNode.mNext;
    v9 = (signed __int64)&v2->mNetPoseSequence;
    for ( i = &v8[-3].mNext; i != (UFG::qNode<PoseNode,PoseNode> **)v9; i = &i[6][-3].mNext )
      ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, PoseStackCalculatorVisitor *))(*i)[5].mPrev)(i, v3);
  }
}

// File Line: 51
// RVA: 0x3B6070
void __fastcall PoseStackCalculatorVisitor::Visit(PoseStackCalculatorVisitor *this, BlendSubNode *node)
{
  BlendSubNode *v2; // rsi
  PoseStackCalculatorVisitor *v3; // rdi
  float v4; // xmm0_4
  UFG::qNode<PoseNode,PoseNode> *v5; // rbx
  signed __int64 v6; // rsi
  UFG::qNode<PoseNode,PoseNode> **i; // rbx

  v2 = node;
  v3 = this;
  v4 = (float)(sinf((float)(node->mBlendParam * 3.1415927) - 1.5707964) + 1.0) * 0.5;
  if ( v4 <= 0.0 || v4 < 1.0 && v4 < 0.000099999997 )
  {
    ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, PoseStackCalculatorVisitor *))v2->mChildren.mNode.mNext[-3].mNext[5].mPrev)(
      &v2->mChildren.mNode.mNext[-3].mNext,
      v3);
  }
  else
  {
    ++v3->mStackCount;
    if ( v3->mRecurse )
    {
      v5 = v2->mChildren.mNode.mNext;
      v6 = (signed __int64)&v2->mNetPoseSequence;
      for ( i = &v5[-3].mNext; i != (UFG::qNode<PoseNode,PoseNode> **)v6; i = &i[6][-3].mNext )
        ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, PoseStackCalculatorVisitor *))(*i)[5].mPrev)(i, v3);
    }
  }
}

// File Line: 107
// RVA: 0x3B5E80
void __fastcall PoseStackCalculatorVisitor::Visit(PoseStackCalculatorVisitor *this, BlendDirectionNode *node)
{
  int v2; // er8
  float v3; // xmm0_4
  UFG::qNode<PoseNode,PoseNode> **v4; // rbx
  PoseStackCalculatorVisitor *v5; // rdi
  BlendDirectionNode *i; // rcx
  int v7; // eax
  int *v8; // rdx
  PoseStackCalculatorVisitor *v9; // rdx
  UFG::qNode<PoseNode,PoseNode> *v10; // rax
  UFG::qNode<PoseNode,PoseNode> **v11; // rcx

  v2 = node->mChild0ID;
  v3 = node->mWeight;
  v4 = &node->mChildren.mNode.mNext[-3].mNext;
  v5 = this;
  for ( i = (BlendDirectionNode *)&node->mChildren.mNode.mNext[-3].mNext;
        v2 > 0;
        i = (BlendDirectionNode *)&i->mNext[-3].mNext )
  {
    if ( i == (BlendDirectionNode *)&node->mNetPoseSequence )
      break;
    --v2;
  }
  v7 = node->mChild1ID;
  if ( v7 > 0 )
  {
    v8 = &node->mNetPoseSequence;
    do
    {
      if ( v4 == (UFG::qNode<PoseNode,PoseNode> **)v8 )
        break;
      --v7;
      v4 = &v4[6][-3].mNext;
    }
    while ( v7 > 0 );
  }
  if ( v3 >= 0.000099999997 )
  {
    v9 = v5;
    if ( v3 <= 0.99989998 )
    {
      ++v5->mStackCount;
      i->vfptr[1].FindWithOldPath((Expression::IMemberMap *)&i->vfptr, (const char *)v5);
      v10 = *v4;
      v11 = v4;
      v9 = v5;
    }
    else
    {
      v10 = *v4;
      v11 = v4;
    }
    ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, PoseStackCalculatorVisitor *))v10[5].mPrev)(v11, v9);
  }
  else
  {
    i->vfptr[1].FindWithOldPath((Expression::IMemberMap *)&i->vfptr, (const char *)v5);
  }
}

// File Line: 131
// RVA: 0x3B5E10
void __usercall PoseStackCalculatorVisitor::Visit(PoseStackCalculatorVisitor *this@<rcx>, AnimationNode *node@<rdx>, float a3@<xmm0>)
{
  SkeletalAnimation *v3; // rax
  PoseStackCalculatorVisitor *v4; // rbx
  UFG::qResourceData *v5; // rcx
  SkeletalAnimation *v6; // rcx
  UFG::qResourceData *v7; // rax

  v3 = node->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  v4 = this;
  if ( v3 )
  {
    v5 = v3->m_AnimationResourceHandle.mData;
    if ( v5 && v5[1].mNode.mChild[0]
      || (v6 = v3->m_pFallbackAnimation) != 0i64
      && (v7 = v6->m_AnimationResourceHandle.mData) != 0i64
      && v7[1].mNode.mChild[0] )
    {
      node->vfptr[4].GetResourceOwner((Expression::IMemberMap *)node);
      if ( a3 >= 0.0 )
        ++v4->mAnimDataCount;
    }
    ++v4->mStackCount;
  }
  else
  {
    ++this->mStackCount;
  }
}

// File Line: 172
// RVA: 0x3B92A0
void __fastcall PoseNode_SetPauseBlend::visit_blendNodes(PoseNode_SetPauseBlend *this, BlendNode *node)
{
  unsigned int v2; // eax
  BlendNode *v3; // rbx
  PoseNode_SetPauseBlend *v4; // rsi
  Weightset *v5; // rax
  __int64 v6; // rax
  __int64 v7; // r8
  BlendNode *v8; // rdi
  __int64 v9; // rax
  signed __int64 v10; // rcx
  __int64 v11; // rsi
  bool v12; // zf

  v2 = this->mPlayPriority;
  v3 = node;
  v4 = this;
  if ( !v2 || node->mPriority != v2 )
    return;
  if ( this->mPauseState == 1 )
  {
    v5 = this->mWeightSet;
    if ( v5 && v5 != node->mWeightSet )
    {
      if ( sReparent )
      {
        v6 = ((__int64 (__fastcall *)(BlendNode *))node->vfptr[1].Serialize)(node);
        v7 = *(_QWORD *)v6;
        *(_QWORD *)(v6 + 136) = v3->mWeightSet;
        *(_QWORD *)(v6 + 144) = v4->mWeightSet;
        *(_BYTE *)(v6 + 154) = 1;
        v8 = (BlendNode *)v6;
        (*(void (__fastcall **)(__int64, _QWORD))(v7 + 328))(v6, v4->mPlayPriority);
        if ( sUnpauseMaskedPose )
          v3->mPauseBlend = 0;
        v3->mPauseBlend = 0;
        v9 = v3->mParent.mOffset;
        if ( v9 )
          v10 = (signed __int64)&v3->mParent + v9;
        else
          v10 = 0i64;
        (*(void (__fastcall **)(signed __int64, BlendNode *, BlendNode *))(*(_QWORD *)v10 + 400i64))(v10, v3, v8);
        v11 = (__int64)v8->vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v8->vfptr, 0);
        ((void (__fastcall *)(BlendNode *, __int64, BlendNode *))v8->vfptr[5].FindWithOldPath)(v8, v11, v3);
        if ( v8->mBlendRate >= 0.0 )
          BlendNode::SetBlendOut(v8, 0.033333335);
        if ( sForceBlendout )
          BlendNode::SetBlendOut(v8, 0.033333335);
        if ( sForcePlayPause )
          ((void (__fastcall *)(BlendNode *))v8->vfptr[2].__vecDelDtor)(v8);
        if ( v11 )
          (*(void (__fastcall **)(__int64, signed __int64))(*(_QWORD *)v11 + 8i64))(v11, 1i64);
        return;
      }
      if ( sPauseBlendOnlyOnLikeWeightSets )
        return;
    }
    node->mPauseBlend = 1;
    return;
  }
  v12 = sBlendOff == 0;
  node->mPauseBlend = 0;
  if ( !v12 )
    node->mBlendParam = 0.0;
}


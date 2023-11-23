// File Line: 29
// RVA: 0x3B5F50
void __fastcall PoseStackCalculatorVisitor::Visit(PoseStackCalculatorVisitor *this, BlendPhaseNode *node)
{
  float v4; // xmm0_4
  int v5; // eax
  int *p_mNext; // rcx
  int *p_mNetPoseSequence; // rsi
  UFG::qNode<PoseNode,PoseNode> *mNext; // rbx
  int *v9; // rsi
  int *i; // rbx

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
      ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, PoseStackCalculatorVisitor *))node->mChildren.mNode.mNext[-3].mNext[5].mPrev)(
        &node->mChildren.mNode.mNext[-3].mNext,
        this);
      return;
    }
    if ( v4 <= 0.99989998 )
      goto LABEL_13;
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
    (*(void (__fastcall **)(int *, PoseStackCalculatorVisitor *))(*(_QWORD *)p_mNext + 80i64))(p_mNext, this);
    return;
  }
LABEL_13:
  ++this->mStackCount;
  if ( this->mRecurse )
  {
    mNext = node->mChildren.mNode.mNext;
    v9 = &node->mNetPoseSequence;
    for ( i = (int *)&mNext[-3].mNext; i != v9; i = (int *)(*((_QWORD *)i + 6) - 40i64) )
      (*(void (__fastcall **)(int *, PoseStackCalculatorVisitor *))(*(_QWORD *)i + 80i64))(i, this);
  }
}

// File Line: 51
// RVA: 0x3B6070
void __fastcall PoseStackCalculatorVisitor::Visit(PoseStackCalculatorVisitor *this, BlendSubNode *node)
{
  float v4; // xmm0_4
  UFG::qNode<PoseNode,PoseNode> *mNext; // rbx
  int *p_mNetPoseSequence; // rsi
  int *i; // rbx

  v4 = (float)(sinf((float)(node->mBlendParam * 3.1415927) - 1.5707964) + 1.0) * 0.5;
  if ( v4 <= 0.0 || v4 < 1.0 && v4 < 0.000099999997 )
  {
    ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, PoseStackCalculatorVisitor *))node->mChildren.mNode.mNext[-3].mNext[5].mPrev)(
      &node->mChildren.mNode.mNext[-3].mNext,
      this);
  }
  else
  {
    ++this->mStackCount;
    if ( this->mRecurse )
    {
      mNext = node->mChildren.mNode.mNext;
      p_mNetPoseSequence = &node->mNetPoseSequence;
      for ( i = (int *)&mNext[-3].mNext; i != p_mNetPoseSequence; i = (int *)(*((_QWORD *)i + 6) - 40i64) )
        (*(void (__fastcall **)(int *, PoseStackCalculatorVisitor *))(*(_QWORD *)i + 80i64))(i, this);
    }
  }
}

// File Line: 107
// RVA: 0x3B5E80
void __fastcall PoseStackCalculatorVisitor::Visit(PoseStackCalculatorVisitor *this, BlendDirectionNode *node)
{
  int mChild0ID; // r8d
  float mWeight; // xmm0_4
  int *p_mNext; // rbx
  BlendDirectionNode *i; // rcx
  int mChild1ID; // eax
  int *p_mNetPoseSequence; // rdx
  PoseStackCalculatorVisitor *v9; // rdx
  __int64 v10; // rax
  int *v11; // rcx

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
    v9 = this;
    if ( mWeight <= 0.99989998 )
    {
      ++this->mStackCount;
      i->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[1].FindWithOldPath(i, (const char *)this);
      v10 = *(_QWORD *)p_mNext;
      v11 = p_mNext;
      v9 = this;
    }
    else
    {
      v10 = *(_QWORD *)p_mNext;
      v11 = p_mNext;
    }
    (*(void (__fastcall **)(int *, PoseStackCalculatorVisitor *))(v10 + 80))(v11, v9);
  }
  else
  {
    i->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[1].FindWithOldPath(i, (const char *)this);
  }
}

// File Line: 131
// RVA: 0x3B5E10
void __fastcall PoseStackCalculatorVisitor::Visit(PoseStackCalculatorVisitor *this, AnimationNode *node)
{
  SkeletalAnimation *m_pPointer; // rax
  UFG::qResourceData *mData; // rcx
  SkeletalAnimation *m_pFallbackAnimation; // rcx
  UFG::qResourceData *v6; // rax

  m_pPointer = node->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  if ( m_pPointer )
  {
    mData = m_pPointer->m_AnimationResourceHandle.mData;
    if ( (mData && mData[1].mNode.mChild[0]
       || (m_pFallbackAnimation = m_pPointer->m_pFallbackAnimation) != 0i64
       && (v6 = m_pFallbackAnimation->m_AnimationResourceHandle.mData) != 0i64
       && v6[1].mNode.mChild[0])
      && ((float (__fastcall *)(AnimationNode *))node->PoseNode::Expression::IMemberMap::vfptr[4].GetResourceOwner)(node) >= 0.0 )
    {
      ++this->mAnimDataCount;
    }
    ++this->mStackCount;
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
  unsigned int mPlayPriority; // eax
  Weightset *mWeightSet; // rax
  __int64 v6; // rax
  __int64 v7; // r8
  BlendNode *v8; // rdi
  __int64 mOffset; // rax
  char *v10; // rcx
  __int64 v11; // rsi
  bool v12; // zf

  mPlayPriority = this->mPlayPriority;
  if ( !mPlayPriority || node->mPriority != mPlayPriority )
    return;
  if ( this->mPauseState )
  {
    mWeightSet = this->mWeightSet;
    if ( mWeightSet && mWeightSet != node->mWeightSet )
    {
      if ( sReparent )
      {
        v6 = ((__int64 (__fastcall *)(BlendNode *))node->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[1].Serialize)(node);
        v7 = *(_QWORD *)v6;
        *(_QWORD *)(v6 + 136) = node->mWeightSet;
        *(_QWORD *)(v6 + 144) = this->mWeightSet;
        *(_BYTE *)(v6 + 154) = 1;
        v8 = (BlendNode *)v6;
        (*(void (__fastcall **)(__int64, _QWORD))(v7 + 328))(v6, this->mPlayPriority);
        if ( sUnpauseMaskedPose )
          node->mPauseBlend = 0;
        node->mPauseBlend = 0;
        mOffset = node->mParent.mOffset;
        if ( mOffset )
          v10 = (char *)&node->mParent + mOffset;
        else
          v10 = 0i64;
        (*(void (__fastcall **)(char *, BlendNode *, BlendNode *))(*(_QWORD *)v10 + 400i64))(v10, node, v8);
        v11 = (__int64)v8->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[1].__vecDelDtor(v8, 0);
        ((void (__fastcall *)(BlendNode *, __int64, BlendNode *))v8->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[5].FindWithOldPath)(
          v8,
          v11,
          node);
        if ( v8->mBlendRate >= 0.0 )
          BlendNode::SetBlendOut(v8, 0.033333335);
        if ( sForceBlendout )
          BlendNode::SetBlendOut(v8, 0.033333335);
        if ( sForcePlayPause )
          ((void (__fastcall *)(BlendNode *))v8->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[2].__vecDelDtor)(v8);
        if ( v11 )
          (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v11 + 8i64))(v11, 1i64);
        return;
      }
      if ( sPauseBlendOnlyOnLikeWeightSets )
        return;
    }
    node->mPauseBlend = 1;
    return;
  }
  v12 = !sBlendOff;
  node->mPauseBlend = 0;
  if ( !v12 )
    node->mBlendParam = 0.0;
}


// File Line: 25
// RVA: 0x313650
void __fastcall FirstAnimationNode::Visit(FirstAnimationNode *this, PoseNodeParent *node)
{
  int *p_mNetPoseSequence; // rsi
  PoseNodeParent *p_mNext; // rbx

  if ( !this->mAnimationNode && this->mRecurse )
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

// File Line: 39
// RVA: 0x313640
void __fastcall FirstAnimationNode::Visit(FirstAnimationNode *this, AnimationNode *node)
{
  if ( !this->mAnimationNode )
    this->mAnimationNode = node;
}

// File Line: 77
// RVA: 0x3B51B0
void __fastcall AnimationNode_SetLocalTime::Visit(AnimationNode_SetLocalTime *this, AnimationNode *node)
{
  if ( this->mDebugPlay )
    node->PoseNode::Expression::IMemberMap::vfptr[2].FindWithOldPath(node, (const char *)1);
  ((void (__fastcall *)(AnimationNode *))node->PoseNode::Expression::IMemberMap::vfptr[3].GetResourcePath)(node);
  if ( this->mSetPlayRate )
    node->PoseNode::Expression::IMemberMap::vfptr[3].ResolveReferences(node);
}

// File Line: 92
// RVA: 0x3B5210
void __fastcall AnimationNode_SetLocalTime::Visit(AnimationNode_SetLocalTime *this, BlendHistoryNode *node)
{
  ((void (__fastcall *)(BlendHistoryNode *))node->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[3].GetResourcePath)(node);
  node->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[2].FindWithOldPath(node, (const char *)3);
}

// File Line: 118
// RVA: 0x3B5250
void __fastcall AnimationNode_SetLocalTimeParametric::Visit(
        AnimationNode_SetLocalTimeParametric *this,
        AnimationNode *node)
{
  Expression::IMemberMapVtbl *vfptr; // rax

  if ( !((unsigned __int8 (__fastcall *)(AnimationNode *))node->PoseNode::Expression::IMemberMap::vfptr[5].FindWithOldPath)(node) )
  {
    ((void (__fastcall *)(AnimationNode *))node->PoseNode::Expression::IMemberMap::vfptr[2].SetResourceOwner)(node);
    vfptr = node->PoseNode::Expression::IMemberMap::vfptr;
    if ( this->mSetPlayRate )
    {
      vfptr[3].ResolveReferences(node);
      if ( this->mPlayRate > 0.0 )
      {
        ((void (__fastcall *)(AnimationNode *))node->PoseNode::Expression::IMemberMap::vfptr[3].GetResourcePath)(node);
        node->PoseNode::Expression::IMemberMap::vfptr[3].ResolveReferences(node);
      }
    }
    else
    {
      ((void (__fastcall *)(AnimationNode *))vfptr[3].GetResourcePath)(node);
    }
  }
}

// File Line: 156
// RVA: 0x3B5300
void __fastcall AnimationNode_SetPlayEndTime::Visit(AnimationNode_SetPlayEndTime *this, AnimationNode *node)
{
  node->mPlayEndTime = this->mEndTime;
}

// File Line: 174
// RVA: 0x3B5310
void __fastcall AnimationNode_SetPlayRate::Visit(AnimationNode_SetPlayRate *this, AnimationNode *node)
{
  node->PoseNode::Expression::IMemberMap::vfptr[3].ResolveReferences(node);
}

// File Line: 194
// RVA: 0x3B5360
void __fastcall BlendDirectionNode_GetBlendDirection::Visit(
        BlendDirectionNode_GetBlendDirection *this,
        BlendDirectionNode *node)
{
  __int64 mDirectionParam; // rax
  int *p_mNetPoseSequence; // rsi
  BlendDirectionNode *p_mNext; // rbx

  mDirectionParam = node->mDirectionParam;
  if ( (int)mDirectionParam < 8 && this->mBlendDirection[mDirectionParam] != 0.0 )
    this->mBlendDirection[node->mDirectionParam] = node->mActiveDirection;
  if ( this->mRecurse )
  {
    p_mNetPoseSequence = &node->mNetPoseSequence;
    p_mNext = (BlendDirectionNode *)&node->mChildren.mNode.mNext[-3].mNext;
    if ( p_mNext != (BlendDirectionNode *)&node->mNetPoseSequence )
    {
      do
      {
        p_mNext->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[1].FindWithOldPath(p_mNext, (const char *)this);
        p_mNext = (BlendDirectionNode *)&p_mNext->mNext[-3].mNext;
      }
      while ( p_mNext != (BlendDirectionNode *)p_mNetPoseSequence );
    }
  }
}

// File Line: 231
// RVA: 0x3B53E0
void __fastcall BlendDirectionNode_SetBlendDirection::Visit(
        BlendDirectionNode_SetBlendDirection *this,
        BlendDirectionNode *node)
{
  __int64 mDirectionParam; // rax
  float v5; // xmm1_4
  UFG::qNode<PoseNode,PoseNode> *mNext; // rbx
  int *p_mNetPoseSequence; // rdi
  int *i; // rbx

  mDirectionParam = node->mDirectionParam;
  if ( (int)mDirectionParam < 8 )
  {
    v5 = this->mBlendDirection[mDirectionParam];
    if ( v5 > 0.0 )
    {
      node->mActiveDirection = v5;
      node->mDesiredActiveDirection = v5;
      node->mWeight = BlendDirectionNode::selectActive(node, &node->mChild0ID, &node->mChild1ID);
    }
  }
  if ( this->mRecurse )
  {
    mNext = node->mChildren.mNode.mNext;
    p_mNetPoseSequence = &node->mNetPoseSequence;
    for ( i = (int *)&mNext[-3].mNext; i != p_mNetPoseSequence; i = (int *)(*((_QWORD *)i + 6) - 40i64) )
      (*(void (__fastcall **)(int *, BlendDirectionNode_SetBlendDirection *))(*(_QWORD *)i + 80i64))(i, this);
  }
}

// File Line: 258
// RVA: 0x313630
void __fastcall BlendNode_SetBlendWeight::Visit(BlendNode_SetBlendWeight *this, BlendPhaseNode *node)
{
  node->mBlendParam = this->mWeight;
}

// File Line: 277
// RVA: 0x3B5330
void __fastcall AnimationNode_UpdateLastPlayTime::Visit(AnimationNode_UpdateLastPlayTime *this, AnimationNode *node)
{
  float mLocalTime; // eax

  if ( node->mFirstPlay )
    node->mFirstPlay = 0;
  mLocalTime = node->mLocalTime;
  node->mLoops = 0;
  node->mLastPlayTime = mLocalTime;
}

// File Line: 377
// RVA: 0x3B54F0
void __fastcall PoseNode_GetPhase::Visit(PoseNode_GetPhase *this, AnimationNode *node)
{
  node->PoseNode::Expression::IMemberMap::vfptr[2].Serialize(node, (IActionTreeSerializer *)&this->mMotionPhase);
}

// File Line: 415
// RVA: 0x3B5510
// attributes: thunk
void __fastcall PoseNode_SetPauseBlend::Visit(PoseNode_SetPauseBlend *this, BlendPhaseNode *node)
{
  PoseNode_SetPauseBlend::visit_blendNodes(this, node);
}


// File Line: 25
// RVA: 0x313650
void __fastcall FirstAnimationNode::Visit(FirstAnimationNode *this, PoseNodeParent *node)
{
  FirstAnimationNode *v2; // rdi
  int *v3; // rsi
  PoseNodeParent *v4; // rbx

  v2 = this;
  if ( !this->mAnimationNode )
  {
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
  AnimationNode *v2; // rbx
  AnimationNode_SetLocalTime *v3; // rdi
  __int128 v4; // xmm1
  __int128 v5; // xmm1

  v2 = node;
  v3 = this;
  if ( this->mDebugPlay )
    node->vfptr[2].FindWithOldPath((Expression::IMemberMap *)node, (const char *)1);
  v4 = LODWORD(v3->mLocalTime);
  ((void (__fastcall *)(AnimationNode *))v2->vfptr[3].GetResourcePath)(v2);
  if ( v3->mSetPlayRate )
  {
    v5 = LODWORD(v3->mPlayRate);
    v2->vfptr[3].ResolveReferences((Expression::IMemberMap *)&v2->vfptr);
  }
}

// File Line: 92
// RVA: 0x3B5210
void __fastcall AnimationNode_SetLocalTime::Visit(AnimationNode_SetLocalTime *this, BlendHistoryNode *node)
{
  __int128 v2; // xmm1
  BlendHistoryNode *v3; // rbx

  v2 = LODWORD(this->mLocalTime);
  v3 = node;
  ((void (__fastcall *)(BlendHistoryNode *))node->vfptr[3].GetResourcePath)(node);
  v3->vfptr[2].FindWithOldPath((Expression::IMemberMap *)&v3->vfptr, (const char *)3);
}

// File Line: 118
// RVA: 0x3B5250
void __usercall AnimationNode_SetLocalTimeParametric::Visit(AnimationNode_SetLocalTimeParametric *this@<rcx>, AnimationNode *node@<rdx>, float a3@<xmm0>)
{
  AnimationNode_SetLocalTimeParametric *v3; // rdi
  AnimationNode *v4; // rbx
  Expression::IMemberMapVtbl *v5; // rax
  float v6; // xmm7_4
  __int128 v7; // xmm1
  float v8; // xmm6_4
  float v9; // xmm6_4

  v3 = this;
  v4 = node;
  if ( !((unsigned __int8 (__fastcall *)(AnimationNode *))node->vfptr[5].FindWithOldPath)(node) )
  {
    ((void (__fastcall *)(AnimationNode *))v4->vfptr[2].SetResourceOwner)(v4);
    v5 = v4->vfptr;
    if ( v3->mSetPlayRate )
    {
      v7 = LODWORD(v3->mPlayRate);
      v5[3].ResolveReferences((Expression::IMemberMap *)&v4->vfptr);
      v8 = a3 / v3->mWeightedDuration;
      if ( v3->mPlayRate > 0.0 )
      {
        ((void (__fastcall *)(AnimationNode *))v4->vfptr[3].GetResourcePath)(v4);
        v9 = v8 * v3->mPlayRate;
        v4->vfptr[3].ResolveReferences((Expression::IMemberMap *)&v4->vfptr);
      }
    }
    else
    {
      v6 = a3 * v3->mLocalTimeParametric;
      ((void (__fastcall *)(AnimationNode *))v5[3].GetResourcePath)(v4);
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
  __int128 v2; // xmm1

  v2 = LODWORD(this->mPlayRate);
  node->vfptr[3].ResolveReferences((Expression::IMemberMap *)node);
}

// File Line: 194
// RVA: 0x3B5360
void __fastcall BlendDirectionNode_GetBlendDirection::Visit(BlendDirectionNode_GetBlendDirection *this, BlendDirectionNode *node)
{
  __int64 v2; // rax
  BlendDirectionNode_GetBlendDirection *v3; // rdi
  int *v4; // rsi
  BlendDirectionNode *v5; // rbx

  v2 = node->mDirectionParam;
  v3 = this;
  if ( (signed int)v2 < 8 && this->mBlendDirection[v2] != 0.0 )
    this->mBlendDirection[node->mDirectionParam] = node->mActiveDirection;
  if ( this->mRecurse )
  {
    v4 = &node->mNetPoseSequence;
    v5 = (BlendDirectionNode *)&node->mChildren.mNode.mNext[-3].mNext;
    if ( v5 != (BlendDirectionNode *)&node->mNetPoseSequence )
    {
      do
      {
        v5->vfptr[1].FindWithOldPath((Expression::IMemberMap *)&v5->vfptr, (const char *)v3);
        v5 = (BlendDirectionNode *)&v5->mNext[-3].mNext;
      }
      while ( v5 != (BlendDirectionNode *)v4 );
    }
  }
}

// File Line: 231
// RVA: 0x3B53E0
void __fastcall BlendDirectionNode_SetBlendDirection::Visit(BlendDirectionNode_SetBlendDirection *this, BlendDirectionNode *node)
{
  __int64 v2; // rax
  unsigned __int128 v3; // di
  float v4; // xmm1_4
  __int64 v5; // rbx
  _QWORD *i; // rbx

  v2 = node->mDirectionParam;
  v3 = __PAIR__((unsigned __int64)this, (unsigned __int64)node);
  if ( (signed int)v2 < 8 )
  {
    v4 = this->mBlendDirection[v2];
    if ( v4 > 0.0 )
    {
      node->mActiveDirection = v4;
      node->mDesiredActiveDirection = v4;
      node->mWeight = BlendDirectionNode::selectActive(node, &node->mChild0ID, &node->mChild1ID);
    }
  }
  if ( *(_BYTE *)(*((_QWORD *)&v3 + 1) + 8i64) )
  {
    v5 = *(_QWORD *)(v3 + 120);
    *(_QWORD *)&v3 = v3 + 72;
    for ( i = (_QWORD *)(v5 - 40); i != (_QWORD *)v3; i = (_QWORD *)(i[6] - 40i64) )
      (*(void (__fastcall **)(_QWORD *, _QWORD))(*i + 80i64))(i, *((_QWORD *)&v3 + 1));
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
  float v2; // eax

  if ( node->mFirstPlay )
    node->mFirstPlay = 0;
  v2 = node->mLocalTime;
  node->mLoops = 0;
  node->mLastPlayTime = v2;
}

// File Line: 377
// RVA: 0x3B54F0
void __fastcall PoseNode_GetPhase::Visit(PoseNode_GetPhase *this, AnimationNode *node)
{
  node->vfptr[2].Serialize((Expression::IMemberMap *)node, (IActionTreeSerializer *)&this->mMotionPhase);
}

// File Line: 415
// RVA: 0x3B5510
void __fastcall PoseNode_SetPauseBlend::Visit(PoseNode_SetPauseBlend *this, BlendPhaseNode *node)
{
  PoseNode_SetPauseBlend::visit_blendNodes(this, (BlendNode *)&node->vfptr);
}


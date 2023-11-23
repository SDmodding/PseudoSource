// File Line: 98
// RVA: 0x3B7BA0
void __fastcall PoseNode::nodeBreakOnStart(PoseNode *this)
{
  char *v2; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  if ( PoseNode::sBreakOnStart
    && PoseNode::sEnableNodeBreakPoints
    && this->mBreakPoint
    && (!PoseNode::sBreakOnCondition
     || PoseNode::sBreakOnCondition && this->Expression::IMemberMap::vfptr[4].GetClassname(this))
    && PoseNode::sSoftBreakPoints )
  {
    v2 = UFG::qSymbol::as_cstr_dbg(&this->mName);
    UFG::qString::FormatEx(&result, "node:\n%s", v2);
    ActionTreeDebugMessageHandler("PoseNode::nodeBreakOnStart", result.mData);
    UFG::qString::~qString(&result);
  }
}

// File Line: 111
// RVA: 0x3B7C30
void __fastcall PoseNode::nodeBreakOnUpdate(PoseNode *this)
{
  char *v2; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  if ( PoseNode::sBreakOnUpdate
    && PoseNode::sEnableNodeBreakPoints
    && this->mBreakPoint
    && (!PoseNode::sBreakOnCondition
     || PoseNode::sBreakOnCondition && this->Expression::IMemberMap::vfptr[4].GetClassname(this))
    && PoseNode::sSoftBreakPoints )
  {
    v2 = UFG::qSymbol::as_cstr_dbg(&this->mName);
    UFG::qString::FormatEx(&result, "node:\n%s", v2);
    ActionTreeDebugMessageHandler("PoseNode::nodeBreakOnUpdate", result.mData);
    UFG::qString::~qString(&result);
  }
}

// File Line: 156
// RVA: 0x39FAB0
void __fastcall PoseNode::~PoseNode(PoseNode *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // rbx
  __int64 mOffset; // rax
  __int64 v4; // rax
  char *v5; // rcx
  UFG::qNode<PoseNode,PoseNode> *mPrev; // rcx
  UFG::qNode<PoseNode,PoseNode> *mNext; // rax
  UFG::qNode<PoseNode,PoseNode> *v8; // rcx
  UFG::qNode<PoseNode,PoseNode> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v11; // rax

  this->Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&PoseNode::`vftable{for `Expression::IMemberMap};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->UFG::qSafePointerNode<PoseNode>;
  this->UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  mOffset = this->mParent.mOffset;
  if ( mOffset && (UFG::qOffset64<PoseNodeParent *> *)((char *)&this->mParent + mOffset) )
  {
    v4 = this->mParent.mOffset;
    if ( v4 )
      v5 = (char *)&this->mParent + v4;
    else
      v5 = 0i64;
    (*(void (__fastcall **)(char *, PoseNode *))(*(_QWORD *)v5 + 384i64))(v5, this);
  }
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<PoseNode,PoseNode>;
  this->mNext = &this->UFG::qNode<PoseNode,PoseNode>;
  v8 = this->mPrev;
  v9 = this->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  this->mPrev = &this->UFG::qNode<PoseNode,PoseNode>;
  this->mNext = &this->UFG::qNode<PoseNode,PoseNode>;
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<PoseNode>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v2->m_SafePointerList);
  v10 = v2->m_SafePointerList.mNode.mPrev;
  v11 = v2->m_SafePointerList.mNode.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->m_SafePointerList.mNode.mPrev = &v2->m_SafePointerList.mNode;
  v2->m_SafePointerList.mNode.mNext = &v2->m_SafePointerList.mNode;
  this->Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 190
// RVA: 0x39E310
void __fastcall PoseNodeParent::PoseNodeParent(PoseNodeParent *this, MemImageLoadFlag flag)
{
  UFG::qList<PoseNode,PoseNode,1,0> *p_mChildren; // r9
  __int64 v4; // rdx
  __int64 mOffset; // rax
  char *v6; // rcx
  char *v7; // r8
  char *v8; // rcx
  UFG::qNode<PoseNode,PoseNode> *v9; // rcx
  UFG::qNode<PoseNode,PoseNode> *mPrev; // rax

  this->PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  UFG::qSafePointerNode<PoseNode>::qSafePointerNode<PoseNode>(&this->UFG::qSafePointerNode<PoseNode>);
  this->mPrev = &this->UFG::qNode<PoseNode,PoseNode>;
  this->mNext = &this->UFG::qNode<PoseNode,PoseNode>;
  this->PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&PoseNode::`vftable{for `Expression::IMemberMap};
  this->PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  this->PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&PoseNodeParent::`vftable{for `Expression::IMemberMap};
  this->PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNodeParent::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  p_mChildren = &this->mChildren;
  this->mChildren.mNode.mPrev = &this->mChildren.mNode;
  this->mChildren.mNode.mNext = &this->mChildren.mNode;
  v4 = 0i64;
  if ( (this->mChildrenSerialized.mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      mOffset = this->mChildrenSerialized.mData.mOffset;
      if ( mOffset )
        v6 = (char *)&this->mChildrenSerialized.mData + mOffset;
      else
        v6 = 0i64;
      v7 = &v6[8 * v4];
      if ( *(_QWORD *)v7 )
        v8 = &v7[*(_QWORD *)v7];
      else
        v8 = 0i64;
      v9 = (UFG::qNode<PoseNode,PoseNode> *)(v8 + 40);
      mPrev = p_mChildren->mNode.mPrev;
      mPrev->mNext = v9;
      v9->mPrev = mPrev;
      v9->mNext = &p_mChildren->mNode;
      p_mChildren->mNode.mPrev = v9;
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < (this->mChildrenSerialized.mCount & 0x7FFFFFFFu) );
  }
  this->mChildrenSerialized.mCount &= 0x80000000;
}

// File Line: 202
// RVA: 0x3AE680
void __fastcall PoseNodeParent::Serialize(PoseNodeParent *this, unsigned __int64 serializer)
{
  int *p_mNetPoseSequence; // r9
  PoseNodeParent *p_mNext; // rsi
  IActionTreeSerializer *v4; // r12
  int v6; // r8d
  __int64 v7; // rax
  int mCount; // edi
  BinPtrArray<ITrack,1,0> *p_mChildrenSerialized; // r14
  unsigned int v10; // r11d
  __int64 mOffset; // rbx
  __int64 v12; // r10
  char *v13; // rax
  char *v14; // rcx
  __int64 v15; // rax
  char *v16; // r8
  int v17; // ecx
  __int64 i; // rax
  __int64 v19; // rax
  char *v20; // rcx
  PoseNodeParent *j; // rsi
  __int64 v22; // rdi
  unsigned int v23; // ebx
  unsigned int v24; // edx
  __int64 v25; // rax
  char *v26; // rcx
  IActionTreeSerializerVtbl *v27; // rax
  unsigned int v28; // ebx
  char *v29; // rsi
  char *v30; // rcx
  char *v31; // rdi
  __int64 v32; // rax

  p_mNetPoseSequence = &this->mNetPoseSequence;
  p_mNext = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  v4 = (IActionTreeSerializer *)serializer;
  v6 = 0;
  v7 = (__int64)p_mNext;
  if ( p_mNext != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      ++v6;
      v7 = *(_QWORD *)(v7 + 48) - 40i64;
    }
    while ( (int *)v7 != p_mNetPoseSequence );
  }
  mCount = this->mChildrenSerialized.mCount;
  p_mChildrenSerialized = (BinPtrArray<ITrack,1,0> *)&this->mChildrenSerialized;
  v10 = mCount & 0x7FFFFFFF;
  if ( v6 == (mCount & 0x7FFFFFFF) )
  {
    serializer = 0i64;
    if ( !v10 )
      goto LABEL_38;
    mOffset = this->mChildrenSerialized.mData.mOffset;
    v12 = 0i64;
    while ( 1 )
    {
      if ( mOffset )
        v13 = (char *)&this->mChildrenSerialized.mData + mOffset;
      else
        v13 = 0i64;
      v14 = &v13[v12];
      v15 = *(_QWORD *)&v13[v12];
      v16 = &v14[v15];
      if ( !v15 )
        v16 = 0i64;
      v17 = serializer;
      for ( i = (__int64)p_mNext; v17 > 0; i = *(_QWORD *)(i + 48) - 40i64 )
      {
        if ( (int *)i == p_mNetPoseSequence )
          break;
        --v17;
      }
      if ( v16 != (char *)i )
        break;
      serializer = (unsigned int)(serializer + 1);
      v12 += 8i64;
      if ( (unsigned int)serializer >= v10 )
        goto LABEL_38;
    }
  }
  if ( mCount >= 0 )
  {
    v19 = p_mChildrenSerialized->mData.mOffset;
    if ( v19 )
    {
      v20 = (char *)&p_mChildrenSerialized->mData + v19;
      if ( v20 )
        operator delete[](v20);
    }
    p_mChildrenSerialized->mData.mOffset = 0i64;
    p_mChildrenSerialized->mCount &= 0x80000000;
  }
  for ( j = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
        j != (PoseNodeParent *)&this->mNetPoseSequence;
        j = (PoseNodeParent *)&j->mNext[-3].mNext )
  {
    v22 = (unsigned int)p_mChildrenSerialized->mCount;
    LODWORD(v22) = v22 & 0x7FFFFFFF;
    v23 = v22 + 1;
    if ( (int)v22 + 1 > (unsigned int)v22 )
    {
      v24 = 1;
      if ( (_DWORD)v22 )
        v24 = 2 * v22;
      for ( ; v24 < v23; v24 *= 2 )
        ;
      if ( v24 - v23 > 0x10000 )
        v24 = v22 + 65537;
      BinPtrArray<Condition,1,0>::Reallocate(p_mChildrenSerialized, v24, "BinPtrArray.Add");
    }
    p_mChildrenSerialized->mCount &= 0x80000000;
    p_mChildrenSerialized->mCount |= v23 & 0x7FFFFFFF;
    v25 = p_mChildrenSerialized->mData.mOffset;
    if ( v25 )
      v26 = (char *)&p_mChildrenSerialized->mData + v25;
    else
      v26 = 0i64;
    serializer = (unsigned __int64)&v26[8 * v22];
    if ( j )
      v27 = (IActionTreeSerializerVtbl *)((char *)j - serializer);
    else
      v27 = 0i64;
    *(_QWORD *)serializer = v27;
  }
LABEL_38:
  v28 = 0;
  v29 = (char *)&this->mChildrenSerialized.mData + this->mChildrenSerialized.mData.mOffset;
  if ( (p_mChildrenSerialized->mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v30 = &v29[8 * v28];
      v31 = &v30[*(_QWORD *)v30];
      if ( v31 )
      {
        v32 = (*(__int64 (__fastcall **)(char *, unsigned __int64))(*(_QWORD *)v31 + 32i64))(
                &v30[*(_QWORD *)v30],
                serializer);
        v4->vfptr->_PushObjectToSerialize(
          v4,
          v31,
          1u,
          (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
          (const char *)v32,
          PRIORITY_MEDIUM,
          0,
          0i64,
          -1u,
          0i64);
      }
      ++v28;
    }
    while ( v28 < (p_mChildrenSerialized->mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 247
// RVA: 0x14B98D0
__int64 dynamic_initializer_for__PoseNodeParent::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PoseNodeParent", 0xFFFFFFFF);
  PoseNodeParent::sClassNameUID = result;
  return result;
}

// File Line: 255
// RVA: 0x14B98F0
__int64 dynamic_initializer_for__PoseNodeRoot::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PoseNodeRoot", 0xFFFFFFFF);
  PoseNodeRoot::sClassNameUID = result;
  return result;
}

// File Line: 276
// RVA: 0x14B96D0
__int64 dynamic_initializer_for__BlendNode::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("BlendNode", 0xFFFFFFFF);
  BlendNode::sClassNameUID = result;
  return result;
}

// File Line: 347
// RVA: 0x14B96B0
__int64 dynamic_initializer_for__BlendDirectionNode::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("BlendDirectionNode", 0xFFFFFFFF);
  BlendDirectionNode::sClassNameUID = result;
  return result;
}

// File Line: 389
// RVA: 0x39DC60
void __fastcall BlendDirectionNode::BlendDirectionNode(BlendDirectionNode *this)
{
  PoseNode::PoseNode(this);
  this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&PoseNodeParent::`vftable{for `Expression::IMemberMap};
  this->PoseNodeParent::PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNodeParent::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  this->mChildrenSerialized.mCount = 0;
  this->mChildrenSerialized.mData.mOffset = 0i64;
  this->mChildren.mNode.PoseNodeParent::mPrev = &this->mChildren.mNode;
  this->mChildren.mNode.mNext = &this->mChildren.mNode;
  this->mLocalTime = 0.0;
  this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&BlendDirectionNode::`vftable{for `Expression::IMemberMap};
  this->PoseNodeParent::PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&BlendDirectionNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  *(_QWORD *)&this->mActiveDirection = 0i64;
  this->mMotionPhase.vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mMotionPhase.mResourceOwner = 0i64;
  this->mMotionPhase.vfptr = (Expression::IMemberMapVtbl *)&MotionPhase2::`vftable;
  *(_QWORD *)&this->mMotionPhase.mPhaseMark.mValue = 0i64;
  *(_QWORD *)&this->mMotionPhase.mPhase = 0i64;
  *(_QWORD *)this->mDirections = 0xBF800000BF800000ui64;
  *(_QWORD *)&this->mDirections[2] = 0xBF800000BF800000ui64;
  *(_QWORD *)&this->mDirections[4] = 0xBF800000BF800000ui64;
  *(_QWORD *)&this->mDirections[6] = 0xBF800000BF800000ui64;
  *(_QWORD *)&this->mWeight = 0i64;
  this->mChild1ID = 0;
  *(_QWORD *)&this->mLimitIndexCW = -1i64;
  this->mDirectionParam = 0;
  *(_WORD *)&this->mSetPhaseMatch = 0;
  this->mPlayRate = 1.0;
  this->mDebugPoseColour = UFG::qColour::Blue;
}

// File Line: 415
// RVA: 0x39DBF0
void __fastcall BlendDirectionNode::BlendDirectionNode(BlendDirectionNode *this, MemImageLoadFlag flag)
{
  PoseNodeParent::PoseNodeParent(this, flag);
  this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&BlendDirectionNode::`vftable{for `Expression::IMemberMap};
  this->PoseNodeParent::PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&BlendDirectionNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  this->mMotionPhase.vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mMotionPhase.mResourceOwner = 0i64;
  this->mMotionPhase.vfptr = (Expression::IMemberMapVtbl *)&MotionPhase2::`vftable;
  *(_QWORD *)&this->mMotionPhase.mPhaseMark.mValue = 0i64;
  *(_QWORD *)&this->mMotionPhase.mPhase = 0i64;
}

// File Line: 462
// RVA: 0x14B9690
__int64 dynamic_initializer_for__BlendAddNode::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("BlendAddNode", 0xFFFFFFFF);
  BlendAddNode::sClassNameUID = result;
  return result;
}

// File Line: 498
// RVA: 0x14B9710
__int64 dynamic_initializer_for__BlendSubNode::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("BlendSubNode", 0xFFFFFFFF);
  BlendSubNode::sClassNameUID = result;
  return result;
}

// File Line: 533
// RVA: 0x14B96F0
__int64 dynamic_initializer_for__BlendPhaseNode::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("BlendPhaseNode", 0xFFFFFFFF);
  BlendPhaseNode::sClassNameUID = result;
  return result;
}

// File Line: 573
// RVA: 0x14B9670
__int64 dynamic_initializer_for__AnimationNode::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AnimationNode", 0xFFFFFFFF);
  AnimationNode::sClassNameUID = result;
  return result;
}

// File Line: 632
// RVA: 0x3A7E60
__int64 __fastcall AnimationNode::GetCount_RunningTasksDebug(AnimationNode *this)
{
  UFG::qNode<ITask,ITask> *mNext; // rdx
  ActionContext **p_mpContext; // rcx
  __int64 result; // rax
  __int64 i; // rdx

  mNext = this->m_RunningTasks.mNode.mNext;
  p_mpContext = &this->mpContext;
  result = 0i64;
  for ( i = (__int64)&mNext[-1].mNext; (ActionContext **)i != p_mpContext; i = *(_QWORD *)(i + 16) - 8i64 )
    result = (unsigned int)(result + 1);
  return result;
}

// File Line: 638
// RVA: 0x3AA720
UFG::qNode<ITask,ITask> *__fastcall AnimationNode::Get_RunningTasksDebug(AnimationNode *this, int priority)
{
  UFG::qNode<ITask,ITask> **p_mNext; // rax
  ActionContext **p_mpContext; // rcx

  p_mNext = &this->m_RunningTasks.mNode.mNext[-1].mNext;
  if ( priority > 0 )
  {
    p_mpContext = &this->mpContext;
    do
    {
      if ( p_mNext == (UFG::qNode<ITask,ITask> **)p_mpContext )
        break;
      --priority;
      p_mNext = &p_mNext[2][-1].mNext;
    }
    while ( priority > 0 );
  }
  return p_mNext[3];
}

// File Line: 645
// RVA: 0x3AA8C0
void AnimationNode::Init(void)
{
  hkJobQueue *mJobQueue; // rcx

  mJobQueue = UFG::BasePhysicsSystem::mInstance->mJobQueue;
  if ( mJobQueue )
    hkaAnimationSampleAndCombineJobQueueUtils::registerWithJobQueue(mJobQueue);
}

// File Line: 734
// RVA: 0x39D550
void __fastcall AnimationNode::AnimationNode(AnimationNode *this)
{
  ActionContext *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  ActionContext *v4; // rax

  PoseNode::PoseNode(this);
  UFG::qSafePointerNode<AnimationNode>::qSafePointerNode<AnimationNode>(&this->UFG::qSafePointerNode<AnimationNode>);
  this->PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&AnimationNode::`vftable{for `Expression::IMemberMap};
  this->PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&AnimationNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  this->UFG::qSafePointerNode<AnimationNode>::vfptr = (UFG::qSafePointerNode<AnimationNode>Vtbl *)&AnimationNode::`vftable;
  this->m_RunningTasks.mNode.mPrev = &this->m_RunningTasks.mNode;
  this->m_RunningTasks.mNode.mNext = &this->m_RunningTasks.mNode;
  this->mSkeletalAnimationHandle.mPrev = &this->mSkeletalAnimationHandle;
  this->mSkeletalAnimationHandle.mNext = &this->mSkeletalAnimationHandle;
  this->mSkeletalAnimationHandle.m_SkeletalAnimationName.mUID = -1;
  this->mSkeletalAnimationHandle.m_SkeletalAnimation.mPrev = &this->mSkeletalAnimationHandle.m_SkeletalAnimation;
  this->mSkeletalAnimationHandle.m_SkeletalAnimation.mNext = &this->mSkeletalAnimationHandle.m_SkeletalAnimation;
  v2 = 0i64;
  this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer = 0i64;
  this->mAnimationGroupHandle.mPrev = &this->mAnimationGroupHandle;
  this->mAnimationGroupHandle.mNext = &this->mAnimationGroupHandle;
  this->mAnimationGroupHandle.mPrev = &this->mAnimationGroupHandle.UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>;
  this->mAnimationGroupHandle.mNext = &this->mAnimationGroupHandle.UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>;
  this->mAnimationGroupHandle.m_AnimationGroupSymbol.mUID = -1;
  this->mAnimationGroupHandle.m_AnimationGroup.mPrev = &this->mAnimationGroupHandle.m_AnimationGroup;
  this->mAnimationGroupHandle.m_AnimationGroup.mNext = &this->mAnimationGroupHandle.m_AnimationGroup;
  this->mAnimationGroupHandle.m_AnimationGroup.m_pPointer = 0i64;
  *(_DWORD *)&this->mAnimationGroupHandle.m_eAnimationPriority.mValue = -65524;
  this->mAnimationGroupHandle.m_bHasBeenBound = 0;
  this->mAnimationGroupHandle.m_pReferenceInfo = 0i64;
  this->mLocalTime = 0.0;
  this->mLastPlayTime = -1.0;
  this->mPlayStartTime = 0.0;
  this->mPlayEndTime = -1.0;
  *(_QWORD *)&this->mPlayRate = 1065353216i64;
  this->mDuration = -1.0;
  *(_QWORD *)&this->mCurrentExtractedMotionSpeed = 0i64;
  this->mDebugPlayingFromActionNode = 0i64;
  this->mMotionPhase.vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mMotionPhase.mResourceOwner = 0i64;
  this->mMotionPhase.vfptr = (Expression::IMemberMapVtbl *)&MotionPhase2::`vftable;
  *(_QWORD *)&this->mMotionPhase.mPhaseMark.mValue = 0i64;
  *(_QWORD *)&this->mMotionPhase.mPhase = 0i64;
  *(_DWORD *)&this->mPlayMode.mValue = 16777473;
  *(_WORD *)&this->mFirstPlay = 1;
  this->mFinished = 0;
  v3 = UFG::qMalloc(0xD8ui64, "ActionContext", 0i64);
  if ( v3 )
  {
    ActionContext::ActionContext((ActionContext *)v3);
    v2 = v4;
  }
  this->mpContext = v2;
}

// File Line: 765
// RVA: 0x39D260
void __fastcall AnimationNode::AnimationNode(
        AnimationNode *this,
        UFG::qSymbolUC *animName,
        AnimationPlayMode playMode,
        float startTime,
        float endTime)
{
  char v5; // di
  ActionContext *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  ActionContext *v10; // rax

  v5 = playMode;
  PoseNode::PoseNode(this);
  UFG::qSafePointerNode<AnimationNode>::qSafePointerNode<AnimationNode>(&this->UFG::qSafePointerNode<AnimationNode>);
  this->PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&AnimationNode::`vftable{for `Expression::IMemberMap};
  this->PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&AnimationNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  this->UFG::qSafePointerNode<AnimationNode>::vfptr = (UFG::qSafePointerNode<AnimationNode>Vtbl *)&AnimationNode::`vftable;
  this->m_RunningTasks.mNode.mPrev = &this->m_RunningTasks.mNode;
  this->m_RunningTasks.mNode.mNext = &this->m_RunningTasks.mNode;
  this->mSkeletalAnimationHandle.mPrev = &this->mSkeletalAnimationHandle;
  this->mSkeletalAnimationHandle.mNext = &this->mSkeletalAnimationHandle;
  this->mSkeletalAnimationHandle.m_SkeletalAnimationName.mUID = -1;
  this->mSkeletalAnimationHandle.m_SkeletalAnimation.mPrev = &this->mSkeletalAnimationHandle.m_SkeletalAnimation;
  this->mSkeletalAnimationHandle.m_SkeletalAnimation.mNext = &this->mSkeletalAnimationHandle.m_SkeletalAnimation;
  v8 = 0i64;
  this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer = 0i64;
  this->mAnimationGroupHandle.mPrev = &this->mAnimationGroupHandle;
  this->mAnimationGroupHandle.mNext = &this->mAnimationGroupHandle;
  this->mAnimationGroupHandle.mPrev = &this->mAnimationGroupHandle.UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>;
  this->mAnimationGroupHandle.mNext = &this->mAnimationGroupHandle.UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>;
  this->mAnimationGroupHandle.m_AnimationGroupSymbol.mUID = -1;
  this->mAnimationGroupHandle.m_AnimationGroup.mPrev = &this->mAnimationGroupHandle.m_AnimationGroup;
  this->mAnimationGroupHandle.m_AnimationGroup.mNext = &this->mAnimationGroupHandle.m_AnimationGroup;
  this->mAnimationGroupHandle.m_AnimationGroup.m_pPointer = 0i64;
  *(_DWORD *)&this->mAnimationGroupHandle.m_eAnimationPriority.mValue = -65524;
  this->mAnimationGroupHandle.m_bHasBeenBound = 0;
  this->mAnimationGroupHandle.m_pReferenceInfo = 0i64;
  this->mLocalTime = startTime;
  this->mLastPlayTime = -1.0;
  this->mPlayStartTime = startTime;
  this->mPlayEndTime = endTime;
  *(_QWORD *)&this->mPlayRate = 1065353216i64;
  this->mDuration = -1.0;
  *(_QWORD *)&this->mCurrentExtractedMotionSpeed = 0i64;
  this->mDebugPlayingFromActionNode = 0i64;
  this->mMotionPhase.vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mMotionPhase.mResourceOwner = 0i64;
  this->mMotionPhase.vfptr = (Expression::IMemberMapVtbl *)&MotionPhase2::`vftable;
  *(_QWORD *)&this->mMotionPhase.mPhaseMark.mValue = 0i64;
  *(_QWORD *)&this->mMotionPhase.mPhase = 0i64;
  this->mPlayMode.mValue = v5;
  *(_DWORD *)&this->mPreserveMotionOnHoldLastFrame = 16842753;
  *(_WORD *)&this->mPoseOnFrameBoundaries = 0;
  v9 = UFG::qMalloc(0xD8ui64, "ActionContext", 0i64);
  if ( v9 )
  {
    ActionContext::ActionContext((ActionContext *)v9);
    v8 = v10;
  }
  this->mpContext = v8;
  this->mName = (UFG::qSymbolUC)animName->mUID;
  AnimationNode::verifyBindAnimation(this);
}

// File Line: 782
// RVA: 0x39D430
void __fastcall AnimationNode::AnimationNode(AnimationNode *this, MemImageLoadFlag flag)
{
  this->PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  UFG::qSafePointerNode<PoseNode>::qSafePointerNode<PoseNode>(&this->UFG::qSafePointerNode<PoseNode>);
  this->mPrev = &this->UFG::qNode<PoseNode,PoseNode>;
  this->mNext = &this->UFG::qNode<PoseNode,PoseNode>;
  this->PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&PoseNode::`vftable{for `Expression::IMemberMap};
  this->PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  UFG::qSafePointerNode<AnimationNode>::qSafePointerNode<AnimationNode>(&this->UFG::qSafePointerNode<AnimationNode>);
  this->PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&AnimationNode::`vftable{for `Expression::IMemberMap};
  this->PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&AnimationNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  this->UFG::qSafePointerNode<AnimationNode>::vfptr = (UFG::qSafePointerNode<AnimationNode>Vtbl *)&AnimationNode::`vftable;
  this->mpContext = 0i64;
  this->m_RunningTasks.mNode.mPrev = &this->m_RunningTasks.mNode;
  this->m_RunningTasks.mNode.mNext = &this->m_RunningTasks.mNode;
  this->mSkeletalAnimationHandle.mPrev = &this->mSkeletalAnimationHandle;
  this->mSkeletalAnimationHandle.mNext = &this->mSkeletalAnimationHandle;
  this->mSkeletalAnimationHandle.m_SkeletalAnimation.mPrev = &this->mSkeletalAnimationHandle.m_SkeletalAnimation;
  this->mSkeletalAnimationHandle.m_SkeletalAnimation.mNext = &this->mSkeletalAnimationHandle.m_SkeletalAnimation;
  this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer = 0i64;
  this->mAnimationGroupHandle.mPrev = &this->mAnimationGroupHandle;
  this->mAnimationGroupHandle.mNext = &this->mAnimationGroupHandle;
  this->mAnimationGroupHandle.mPrev = &this->mAnimationGroupHandle.UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>;
  this->mAnimationGroupHandle.mNext = &this->mAnimationGroupHandle.UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>;
  this->mAnimationGroupHandle.m_AnimationGroup.mPrev = &this->mAnimationGroupHandle.m_AnimationGroup;
  this->mAnimationGroupHandle.m_AnimationGroup.mNext = &this->mAnimationGroupHandle.m_AnimationGroup;
  this->mAnimationGroupHandle.m_AnimationGroup.m_pPointer = 0i64;
  this->mMotionPhase.vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mMotionPhase.mResourceOwner = 0i64;
  this->mMotionPhase.vfptr = (Expression::IMemberMapVtbl *)&MotionPhase2::`vftable;
}

// File Line: 791
// RVA: 0x39F1C0
void __fastcall AnimationNode::~AnimationNode(AnimationNode *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // r14
  UFG::qNode<ITask,ITask> *mNext; // rbx
  UFG::qNode<ITask,ITask> *mPrev; // rdx
  UFG::qNode<ITask,ITask> *v5; // rax
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v6; // rcx
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v7; // rax
  ActionContext *mpContext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v14; // rax

  this->PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&AnimationNode::`vftable{for `Expression::IMemberMap};
  this->PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&AnimationNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->UFG::qSafePointerNode<AnimationNode>;
  this->UFG::qSafePointerNode<AnimationNode>::vfptr = (UFG::qSafePointerNode<AnimationNode>Vtbl *)&AnimationNode::`vftable;
  while ( (ActionContext **)&this->m_RunningTasks.mNode.mNext[-1].mNext != &this->mpContext )
  {
    mNext = this->m_RunningTasks.mNode.mNext;
    ((void (__fastcall *)(UFG::qNode<ITask,ITask> **))mNext[-1].mNext[1].mNext)(&mNext[-1].mNext);
    mPrev = mNext->mPrev;
    v5 = mNext->mNext;
    mPrev->mNext = v5;
    v5->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    ((void (__fastcall *)(UFG::qNode<ITask,ITask> **, __int64))mNext[-1].mNext->mPrev)(&mNext[-1].mNext, 1i64);
  }
  v6 = this->mSkeletalAnimationHandle.mPrev;
  v7 = this->mSkeletalAnimationHandle.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  this->mSkeletalAnimationHandle.mPrev = &this->mSkeletalAnimationHandle;
  this->mSkeletalAnimationHandle.mNext = &this->mSkeletalAnimationHandle;
  AnimationGroupHandle::Unbind(&this->mAnimationGroupHandle);
  mpContext = this->mpContext;
  if ( mpContext )
  {
    if ( mpContext->mSimObject.m_pPointer )
    {
      v9 = mpContext->mSimObject.mPrev;
      v10 = mpContext->mSimObject.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      mpContext->mSimObject.mPrev = &mpContext->mSimObject;
      mpContext->mSimObject.mNext = &mpContext->mSimObject;
    }
    mpContext->mSimObject.m_pPointer = 0i64;
    v11 = mpContext->mSimObject.mPrev;
    v12 = mpContext->mSimObject.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    mpContext->mSimObject.mPrev = &mpContext->mSimObject;
    mpContext->mSimObject.mNext = &mpContext->mSimObject;
    operator delete[](mpContext);
  }
  this->mMotionPhase.vfptr = (Expression::IMemberMapVtbl *)&MotionPhase2::`vftable;
  this->mMotionPhase.vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  AnimationGroupHandle::~AnimationGroupHandle(&this->mAnimationGroupHandle);
  SkeletalAnimationHandle::~SkeletalAnimationHandle(&this->mSkeletalAnimationHandle);
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>(&this->m_RunningTasks);
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<AnimationNode>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v2->m_SafePointerList);
  v13 = v2->m_SafePointerList.mNode.mPrev;
  v14 = v2->m_SafePointerList.mNode.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v2->m_SafePointerList.mNode.mPrev = &v2->m_SafePointerList.mNode;
  v2->m_SafePointerList.mNode.mNext = &v2->m_SafePointerList.mNode;
  PoseNode::~PoseNode(this);
}

// File Line: 820
// RVA: 0x3AEF90
void __fastcall AnimationNode::SetContext(AnimationNode *this, ActionContext *context)
{
  AnimationGroup *m_pPointer; // rdx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v4; // rdx
  UFG::qList<AnimationGroup,AnimationGroupUpdateList,0,0> *p_mQueuedUpdateGroups; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *mPrev; // rax

  ActionContext::operator=(this->mpContext, context);
  this->mpContext->mActionController = 0i64;
  if ( LocalPlayer == this->mpContext->mSimObject.m_pPointer
    && (this->mAnimationGroupHandle.m_eAnimationPriority.mValue != 15
     || this->mAnimationGroupHandle.m_AnimationSubPriority) )
  {
    m_pPointer = this->mAnimationGroupHandle.m_AnimationGroup.m_pPointer;
    *(_DWORD *)&this->mAnimationGroupHandle.m_eAnimationPriority.mValue = 15;
    if ( m_pPointer )
    {
      v4 = &m_pPointer->UFG::qNode<AnimationGroup,AnimationGroupUpdateList>;
      if ( v4->mPrev == v4 && v4->mNext == v4 )
      {
        p_mQueuedUpdateGroups = &AnimationDataBase::sAnimationDataBase->mQueuedUpdateGroups;
        mPrev = AnimationDataBase::sAnimationDataBase->mQueuedUpdateGroups.mNode.mPrev;
        mPrev->mNext = v4;
        v4->mPrev = mPrev;
        v4->mNext = &p_mQueuedUpdateGroups->mNode;
        p_mQueuedUpdateGroups->mNode.mPrev = v4;
      }
    }
  }
}

// File Line: 880
// RVA: 0x3A4D10
AnimationNode *__fastcall AnimationNode::Clone(AnimationNode *this)
{
  char *v2; // rax
  AnimationNode *v3; // rax
  AnimationNode *v4; // rbx
  ActionContext *mpContext; // rdx

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x170ui64, "Clone of AnimationNode", 0i64, 1u);
  if ( v2 )
  {
    AnimationNode::AnimationNode((AnimationNode *)v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  v4->mName.mUID = this->mName.mUID;
  mpContext = this->mpContext;
  if ( mpContext )
    ActionContext::operator=(v4->mpContext, mpContext);
  AnimationNode::verifyBindAnimation(v4);
  v4->mLocalTime = this->mLocalTime;
  v4->mLastPlayTime = this->mLastPlayTime;
  v4->mPlayStartTime = this->mPlayStartTime;
  v4->mPlayEndTime = this->mPlayEndTime;
  v4->mPlayRate = this->mPlayRate;
  v4->mLoops = this->mLoops;
  v4->mPreserveMotionOnHoldLastFrame = this->mPreserveMotionOnHoldLastFrame;
  v4->mPause = this->mPause;
  v4->mPlayTracks = this->mPlayTracks;
  v4->mPlayMode.mValue = this->mPlayMode.mValue;
  v4->mMotionPhase.mResourceOwner = this->mMotionPhase.mResourceOwner;
  v4->mMotionPhase.mPhaseMark.mValue = this->mMotionPhase.mPhaseMark.mValue;
  v4->mMotionPhase.mPhasePeriod = this->mMotionPhase.mPhasePeriod;
  v4->mMotionPhase.mPhase = this->mMotionPhase.mPhase;
  v4->mMotionPhase.mPhaseDuration = this->mMotionPhase.mPhaseDuration;
  v4->mFirstPlay = this->mFirstPlay;
  v4->mPoseOnFrameBoundaries = this->mPoseOnFrameBoundaries;
  return v4;
}

// File Line: 914
// RVA: 0x3A6360
Expression::IMemberMap *__fastcall ActionNodeFileReference::GetChild2(ActionNodeImplementation *this, __int64 priority)
{
  return (Expression::IMemberMap *)((__int64 (__fastcall *)(ActionNodeImplementation *, __int64))this->vfptr[1].Serialize)(
                                     this,
                                     priority);
}

// File Line: 943
// RVA: 0x3AA0B0
char __fastcall GetWeightedDurationAndParametricTime(
        PoseNode *pose0,
        PoseNode *pose1,
        float weight,
        float *weightedDurationMaster,
        float *parametricLocalTimeMaster)
{
  float v5; // xmm6_4
  Expression::IMemberMapVtbl *vfptr; // rax
  double v9; // xmm0_8
  float v10; // xmm7_4
  double v11; // xmm0_8
  Expression::IMemberMapVtbl *v12; // rax
  float v13; // xmm8_4
  double v14; // xmm0_8
  void **v16; // [rsp+20h] [rbp-68h] BYREF
  char v17; // [rsp+28h] [rbp-60h]
  __int64 v18; // [rsp+30h] [rbp-58h]

  v5 = FLOAT_N1_0;
  v16 = &FirstAnimationNode::`vftable;
  vfptr = pose0->Expression::IMemberMap::vfptr;
  v17 = 1;
  v18 = 0i64;
  vfptr[1].FindWithOldPath(pose0, (const char *)&v16);
  if ( !v18 )
    return 0;
  v9 = (*(double (__fastcall **)(__int64))(*(_QWORD *)v18 + 224i64))(v18);
  v10 = *(float *)&v9;
  v11 = (*(double (__fastcall **)(__int64))(*(_QWORD *)v18 + 392i64))(v18);
  v12 = pose1->Expression::IMemberMap::vfptr;
  v13 = *(float *)&v11;
  v18 = 0i64;
  v12[1].FindWithOldPath(pose1, (const char *)&v16);
  if ( v18 )
  {
    v14 = (*(double (__fastcall **)(__int64))(*(_QWORD *)v18 + 224i64))(v18);
    v5 = *(float *)&v14;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v18 + 392i64))(v18);
  }
  if ( v10 <= 0.0 || v5 <= 0.0 )
    return 0;
  *weightedDurationMaster = (float)((float)(v5 - v10) * weight) + v10;
  *parametricLocalTimeMaster = v13 / v10;
  return 1;
}

// File Line: 978
// RVA: 0x3A6CF0
void __fastcall DurationMatch(PoseNode *pose0, PoseNode *pose1, float weight, float masterRate)
{
  Expression::IMemberMapVtbl *vfptr; // rax
  float parametricLocalTimeMaster; // [rsp+30h] [rbp-48h] BYREF
  float weightedDurationMaster; // [rsp+34h] [rbp-44h] BYREF
  void **v8; // [rsp+38h] [rbp-40h] BYREF
  char v9; // [rsp+40h] [rbp-38h]
  float v10; // [rsp+48h] [rbp-30h]
  float v11; // [rsp+4Ch] [rbp-2Ch]
  float v12; // [rsp+50h] [rbp-28h]
  char v13; // [rsp+54h] [rbp-24h]

  if ( GetWeightedDurationAndParametricTime(pose0, pose1, weight, &weightedDurationMaster, &parametricLocalTimeMaster) )
  {
    v8 = &AnimationNode_SetLocalTimeParametric::`vftable;
    vfptr = pose1->Expression::IMemberMap::vfptr;
    v10 = parametricLocalTimeMaster;
    v11 = weightedDurationMaster;
    v12 = masterRate;
    v9 = 1;
    v13 = 1;
    vfptr[1].FindWithOldPath(pose1, (const char *)&v8);
  }
}

// File Line: 998
// RVA: 0x3B67E0
void __fastcall debugDrawFootTracks(SkeletalAnimation *anim, float time, float xScreenPos, float yScreenPos)
{
  __int64 v5; // rsi
  float Duration; // xmm0_4
  float v7; // xmm8_4
  __int64 v8; // rbx
  __int64 v9; // r14
  float *v10; // rdi
  int v11; // eax
  int v12; // ecx
  UFG::qColour *v13; // rax
  float v14; // xmm0_4
  UFG::qVector3 v15; // [rsp+18h] [rbp-49h] BYREF
  UFG::qVector3 v16; // [rsp+28h] [rbp-39h] BYREF
  UFG::qVector3 v17; // [rsp+38h] [rbp-29h] BYREF
  UFG::qColour v18; // [rsp+48h] [rbp-19h] BYREF
  UFG::qColour v19; // [rsp+58h] [rbp-9h] BYREF

  v5 = ((__int64 (__fastcall *)(SkeletalAnimation *))anim->Expression::IMemberMap::vfptr[1].Serialize)(anim);
  Duration = SkeletalAnimation::GetDuration(anim);
  if ( Duration > 0.0 )
  {
    v18 = UFG::qColour::Green;
    UFG::DrawBoxScreenSpace(xScreenPos, yScreenPos, sBarThinkness, sBarLength, &v18);
    v16.y = xScreenPos;
    v7 = 1.0 / Duration;
    v16.z = 0.0;
    v15.z = 0.0;
    v16.x = (float)((float)((float)(1.0 / Duration) * time) * sBarLength) + xScreenPos;
    v18 = UFG::qColour::Green;
    UFG::DrawLineScreenSpace(&v16, &v15, &v18);
    v8 = 0i64;
    v9 = v5 + *(_QWORD *)(v5 + 24) + 24i64;
    if ( (*(_DWORD *)(v5 + 16) & 0x7FFFFFFF) != 0 )
    {
      while ( 1 )
      {
        v10 = (float *)(v9 + 8 * v8 + *(_QWORD *)(v9 + 8 * v8));
        v11 = (*(__int64 (__fastcall **)(float *))(*(_QWORD *)v10 + 80i64))(v10);
        if ( v11 == 1 )
          break;
        if ( v11 == 2 )
        {
          v12 = 1;
          goto LABEL_7;
        }
LABEL_10:
        v8 = (unsigned int)(v8 + 1);
        if ( (unsigned int)v8 >= (*(_DWORD *)(v5 + 16) & 0x7FFFFFFFu) )
          return;
      }
      v12 = 0;
LABEL_7:
      v13 = &UFG::qColour::Red;
      if ( v12 )
        v13 = &UFG::qColour::Blue;
      *(_QWORD *)&v18.g = LODWORD(xScreenPos);
      v14 = v7 * v10[4];
      v17.z = 0.0;
      v18.r = (float)(v14 * sBarLength) + xScreenPos;
      v17.x = v18.r;
      v17.y = sBarThinkness + xScreenPos;
      v19 = *v13;
      UFG::DrawLineScreenSpace((UFG::qVector3 *)&v18, &v17, &v19);
      goto LABEL_10;
    }
  }
}

// File Line: 1044
// RVA: 0x3B6D30
void __fastcall getBoundFootTracks(
        SkeletalAnimation *anim,
        float time,
        MotionKey **track0,
        MotionKey **track1,
        int *period,
        bool animCycles)
{
  __int64 v8; // rbp
  int v9; // r13d
  unsigned int v10; // edi
  int v11; // r12d
  unsigned int v12; // esi
  float Duration; // xmm6_4
  __int64 v14; // r15
  _QWORD *v15; // rcx
  MotionKey *v16; // rbx
  int v17; // eax
  float mTimeBegin; // xmm0_4
  MotionKey **v19; // rcx
  MotionKey *v20; // rcx
  int v21; // eax
  __int64 v22; // r15
  int v23; // esi
  MotionKey *v24; // rbx
  int v25; // eax
  int v26; // ebx
  int v27; // r14d
  __int64 v28; // rsi
  __int64 v29; // rcx
  __int64 v30; // rdx
  __int64 v31; // rcx
  MotionKey *v32; // rbx
  int v33; // eax

  v8 = ((__int64 (__fastcall *)(SkeletalAnimation *))anim->Expression::IMemberMap::vfptr[1].Serialize)(anim);
  if ( !v8 )
    return;
  v9 = -1;
  v10 = 0;
  v11 = -1;
  v12 = 0;
  Duration = SkeletalAnimation::GetDuration(anim);
  v14 = *(_QWORD *)(v8 + 24) + v8 + 24;
  if ( (*(_DWORD *)(v8 + 16) & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v15 = (_QWORD *)(v14 + 8i64 * v12);
      v16 = (MotionKey *)((char *)v15 + *v15);
      if ( *track1 )
        break;
      v17 = ((__int64 (__fastcall *)(char *))v16->vfptr[1].FindWithOldPath)((char *)v15 + *v15);
      if ( v17 > 0 )
      {
        mTimeBegin = v16->mTimeBegin;
        if ( mTimeBegin >= Duration )
          mTimeBegin = Duration;
        if ( mTimeBegin > time )
        {
          *track1 = v16;
        }
        else
        {
          *track0 = v16;
          if ( v17 == 1 )
            ++v9;
          else
            ++v11;
        }
      }
      ++v12;
    }
    while ( v12 < (*(_DWORD *)(v8 + 16) & 0x7FFFFFFFu) );
    v10 = 0;
  }
  v19 = track0;
  if ( !animCycles )
    goto LABEL_22;
  v20 = *track0;
  if ( !*track0 )
  {
    if ( *track1 )
    {
      v26 = *(_DWORD *)(v8 + 16) & 0x7FFFFFFF;
      v27 = ((__int64 (__fastcall *)(_QWORD))(*track1)->vfptr[1].FindWithOldPath)(*track1);
      v28 = v26 - 1;
      if ( v26 - 1 >= 0 )
      {
        while ( 1 )
        {
          v29 = *(_QWORD *)(v8 + 24);
          if ( v29 )
            v30 = v29 + v8 + 24;
          else
            v30 = 0i64;
          v31 = *(_QWORD *)(v30 + 8 * v28);
          v32 = (MotionKey *)(v31 + v30 + 8 * v28);
          if ( !v31 )
            v32 = 0i64;
          v33 = ((__int64 (__fastcall *)(MotionKey *))v32->vfptr[1].FindWithOldPath)(v32);
          if ( v33 > 0 && v27 != v33 )
            break;
          if ( --v28 < 0 )
            goto LABEL_21;
        }
        v19 = track0;
        *track0 = v32;
LABEL_22:
        v20 = *v19;
        if ( !v20 )
          return;
        goto LABEL_23;
      }
    }
LABEL_21:
    v19 = track0;
    goto LABEL_22;
  }
  if ( !*track1 )
  {
    v21 = ((__int64 (__fastcall *)(MotionKey *))v20->vfptr[1].FindWithOldPath)(v20);
    v22 = *(_QWORD *)(v8 + 24) + v8 + 24;
    v23 = v21;
    if ( (*(_DWORD *)(v8 + 16) & 0x7FFFFFFF) != 0 )
    {
      while ( 1 )
      {
        v24 = (MotionKey *)(v22 + 8i64 * v10 + *(_QWORD *)(v22 + 8i64 * v10));
        v25 = ((__int64 (__fastcall *)(MotionKey *))v24->vfptr[1].FindWithOldPath)(v24);
        if ( v25 > 0 && v23 != v25 )
          break;
        if ( ++v10 >= (*(_DWORD *)(v8 + 16) & 0x7FFFFFFFu) )
          goto LABEL_21;
      }
      *track1 = v24;
    }
    goto LABEL_21;
  }
LABEL_23:
  if ( ((unsigned int (__fastcall *)(MotionKey *))v20->vfptr[1].FindWithOldPath)(v20) == 1 )
    v11 = v9;
  *period = v11;
}

// File Line: 1156
// RVA: 0x3B6F50
__int64 __fastcall getBoundFootTracksAtMotionPhase(
        SkeletalAnimation *anim,
        MotionPhase2 *motionPhase,
        MotionKey **track0,
        MotionKey **track1,
        bool animCycles)
{
  unsigned int v5; // esi
  __int64 v10; // rbp
  unsigned int v11; // edi
  __int64 v12; // rcx
  unsigned int v13; // r14d
  MotionKey *v14; // r12
  int mPhasePeriod; // eax
  __int64 v16; // r12
  MotionKey *v17; // r14
  __int64 v18; // rcx
  int v19; // ebx
  int v20; // r15d
  __int64 v21; // r14
  __int64 v22; // rcx
  __int64 v23; // rdx
  __int64 v24; // rcx
  MotionKey *v25; // rbx
  int v26; // eax
  __int64 v28; // [rsp+58h] [rbp+10h]

  v5 = -1;
  if ( motionPhase->mPhaseMark.mValue )
  {
    v10 = ((__int64 (*)(void))anim->Expression::IMemberMap::vfptr[1].Serialize)();
    if ( v10 )
    {
      SkeletalAnimation::GetDuration(anim);
      v11 = 0;
      v12 = *(_QWORD *)(v10 + 24) + v10 + 24;
      v13 = 0;
      v28 = v12;
      if ( (*(_DWORD *)(v10 + 16) & 0x7FFFFFFF) != 0 )
      {
        do
        {
          v14 = (MotionKey *)(v12 + 8i64 * v13 + *(_QWORD *)(v12 + 8i64 * v13));
          if ( motionPhase->mPhaseMark.mValue == ((unsigned int (__fastcall *)(MotionKey *))v14->vfptr[1].FindWithOldPath)(v14) )
          {
            mPhasePeriod = motionPhase->mPhasePeriod;
            if ( mPhasePeriod != v5 && (mPhasePeriod == ++v5 || !v5) )
            {
              *track0 = v14;
              *track1 = 0i64;
            }
          }
          else if ( !*track1 && (motionPhase->mPhasePeriod == v5 || !v5) )
          {
            *track1 = v14;
          }
          v12 = v28;
          ++v13;
        }
        while ( v13 < (*(_DWORD *)(v10 + 16) & 0x7FFFFFFFu) );
      }
      if ( animCycles )
      {
        if ( *track0 )
        {
          if ( !*track1 )
          {
            v16 = *(_QWORD *)(v10 + 24) + v10 + 24;
            if ( (*(_DWORD *)(v10 + 16) & 0x7FFFFFFF) != 0 )
            {
              while ( 1 )
              {
                v17 = (MotionKey *)(v16 + 8i64 * v11 + *(_QWORD *)(v16 + 8i64 * v11));
                if ( motionPhase->mPhaseMark.mValue != ((unsigned int (__fastcall *)(MotionKey *))v17->vfptr[1].FindWithOldPath)(v17) )
                  break;
                if ( ++v11 >= (*(_DWORD *)(v10 + 16) & 0x7FFFFFFFu) )
                  return v5;
              }
              *track1 = v17;
            }
          }
        }
        else
        {
          v18 = (__int64)*track1;
          if ( *track1 )
          {
            v19 = *(_DWORD *)(v10 + 16) & 0x7FFFFFFF;
            v20 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v18 + 80i64))(v18);
            v21 = v19 - 1;
            if ( v19 - 1 >= 0 )
            {
              while ( 1 )
              {
                v22 = *(_QWORD *)(v10 + 24);
                v23 = v22 ? v22 + v10 + 24 : 0i64;
                v24 = *(_QWORD *)(v23 + 8 * v21);
                v25 = (MotionKey *)(v24 + v23 + 8 * v21);
                if ( !v24 )
                  v25 = 0i64;
                v26 = ((__int64 (__fastcall *)(MotionKey *))v25->vfptr[1].FindWithOldPath)(v25);
                if ( v26 > 0 && v20 != v26 )
                  break;
                if ( --v21 < 0 )
                  return v5;
              }
              *track0 = v25;
            }
          }
        }
      }
    }
  }
  return v5;
}

// File Line: 1244
// RVA: 0x3B7270
void __fastcall getPhase(AnimationNode *child0, MotionPhase2 *motionPhase)
{
  SkeletalAnimation *m_pPointer; // rsi
  int *period; // r14
  Expression::IMemberMapVtbl *vfptr; // rax
  double v7; // xmm0_8
  float v8; // xmm6_4
  float Duration; // xmm0_4
  float v10; // xmm7_4
  MotionKey *v11; // rdi
  MotionKey *v12; // rsi
  float v13; // xmm1_4
  float mTimeBegin; // xmm1_4
  float mPhaseDuration; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm6_4
  MotionKey *v18; // rdi
  unsigned int v19; // eax
  float v20; // xmm0_4
  MotionKey *track1; // [rsp+70h] [rbp+8h] BYREF
  MotionKey *track0; // [rsp+78h] [rbp+10h] BYREF

  m_pPointer = child0->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  period = &motionPhase->mPhasePeriod;
  motionPhase->mPhaseMark.mValue = 0;
  motionPhase->mPhasePeriod = 0;
  *(_QWORD *)&motionPhase->mPhase = 0i64;
  if ( m_pPointer )
  {
    vfptr = child0->PoseNode::Expression::IMemberMap::vfptr;
    track0 = 0i64;
    track1 = 0i64;
    v7 = ((double (*)(void))vfptr[4].GetResourceOwner)();
    v8 = *(float *)&v7;
    Duration = SkeletalAnimation::GetDuration(m_pPointer);
    v10 = Duration;
    getBoundFootTracks(m_pPointer, v8, &track0, &track1, period, child0->mPlayMode.mValue == 1);
    v11 = track0;
    if ( track0 )
    {
      v12 = track1;
      motionPhase->mPhaseMark.mValue = ((__int64 (__fastcall *)(MotionKey *))track0->vfptr[1].FindWithOldPath)(track0);
      if ( !v12 )
      {
        *period = 0;
        return;
      }
      v13 = v12->mTimeBegin - v11->mTimeBegin;
      motionPhase->mPhaseDuration = v13;
      if ( v13 < 0.0 )
      {
        mTimeBegin = v12->mTimeBegin;
        motionPhase->mPhaseDuration = mTimeBegin;
        motionPhase->mPhaseDuration = (float)(Duration - v11->mTimeBegin) + mTimeBegin;
      }
      mPhaseDuration = motionPhase->mPhaseDuration;
      if ( mPhaseDuration > 0.000099999997 )
      {
        motionPhase->mPhase = v8 / mPhaseDuration;
        if ( v8 <= Duration )
        {
          v16 = v11->mTimeBegin;
          if ( v8 < v16 )
          {
            motionPhase->mPhase = (float)((float)(v10 - v16) + v8) / mPhaseDuration;
            return;
          }
          v17 = (float)(v8 - v16) / mPhaseDuration;
          goto LABEL_18;
        }
      }
    }
    else
    {
      v18 = track1;
      if ( track1 )
      {
        v19 = ((__int64 (__fastcall *)(MotionKey *))track1->vfptr[1].FindWithOldPath)(track1);
        motionPhase->mPhaseMark.mValue = v19;
        if ( v19 == 1 || v19 == 2 )
          motionPhase->mPhaseMark.mValue = 2;
        v20 = v18->mTimeBegin;
        motionPhase->mPhaseDuration = v20;
        if ( v20 > 0.000099999997 )
        {
          v17 = v8 / v20;
LABEL_18:
          motionPhase->mPhase = v17;
        }
      }
    }
  }
}

// File Line: 1338
// RVA: 0x3B81A0
void __fastcall setLocalTimeFromPhaseTracks(
        AnimationNode *pose,
        float relativeTrackWeight,
        MotionKey *track10,
        MotionKey *track11)
{
  SkeletalAnimation *m_pPointer; // rcx

  m_pPointer = pose->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  if ( m_pPointer && track10 )
  {
    if ( track11 )
    {
      SkeletalAnimation::GetDuration(m_pPointer);
      ((void (__fastcall *)(AnimationNode *))pose->PoseNode::Expression::IMemberMap::vfptr[3].GetResourcePath)(pose);
    }
  }
}

// File Line: 1413
// RVA: 0x3AC720
void __fastcall PhaseSync(PoseNode *pose0, PoseNode *pose1)
{
  __int64 v3[6]; // [rsp+28h] [rbp-30h] BYREF

  memset(&v3[1], 0, 24);
  v3[0] = (__int64)&MotionPhase2::`vftable;
  pose0->Expression::IMemberMap::vfptr[2].Serialize(pose0, (IActionTreeSerializer *)v3);
  ((void (__fastcall *)(PoseNode *, __int64 *))pose1->Expression::IMemberMap::vfptr[2].GetClassNameUID)(pose1, v3);
}

// File Line: 1428
// RVA: 0x3AC5F0
void __fastcall PhaseMatch(PoseNode *pose0, PoseNode *pose1, float weight)
{
  __int64 v5[2]; // [rsp+28h] [rbp-58h] BYREF
  __int64 v6; // [rsp+38h] [rbp-48h]
  __int64 v7; // [rsp+40h] [rbp-40h]
  __int64 v8[2]; // [rsp+48h] [rbp-38h] BYREF
  __int64 v9; // [rsp+58h] [rbp-28h]
  __int64 v10; // [rsp+60h] [rbp-20h]

  v5[1] = 0i64;
  v5[0] = (__int64)&MotionPhase2::`vftable;
  v6 = 0i64;
  v7 = 0i64;
  v8[1] = 0i64;
  v8[0] = (__int64)&MotionPhase2::`vftable;
  v9 = 0i64;
  v10 = 0i64;
  pose0->Expression::IMemberMap::vfptr[2].Serialize(pose0, (IActionTreeSerializer *)v5);
  pose1->Expression::IMemberMap::vfptr[2].Serialize(pose1, (IActionTreeSerializer *)v8);
  if ( (_DWORD)v6 && (_DWORD)v9 )
  {
    ((void (__fastcall *)(PoseNode *, __int64 *))pose1->Expression::IMemberMap::vfptr[2].GetClassNameUID)(pose1, v5);
    ((void (__fastcall *)(PoseNode *))pose0->Expression::IMemberMap::vfptr[2].GetResourcePath)(pose0);
    pose1->Expression::IMemberMap::vfptr[2].ResolveReferences(pose1);
  }
  else if ( sDurationMatchOnPhaseMatch )
  {
    DurationMatch(pose0, pose1, weight, 1.0);
  }
}

// File Line: 1472
// RVA: 0x3A2D60
BlendNode *__fastcall PoseNode::BlendIn(PoseNode *this, PoseNode *newNode, float blendInTime, bool syncStart)
{
  __int64 mOffset; // rax
  char *v8; // rax

  mOffset = this->mParent.mOffset;
  if ( !mOffset || !(UFG::qOffset64<PoseNodeParent *> *)((char *)&this->mParent + mOffset) )
    return 0i64;
  v8 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB0ui64, "PoseNode.BlendIn", 0i64, 1u);
  if ( v8 )
    BlendNode::BlendNode((BlendNode *)v8, blendInTime);
  return PoseNode::BlendIn(this, newNode, (BlendNode *)v8, syncStart);
}

// File Line: 1488
// RVA: 0x3A2E10
BlendNode *__fastcall PoseNode::BlendIn(PoseNode *this, PoseNode *newNode, BlendNode *blendIn, char syncStart)
{
  __int64 mOffset; // rax
  char *v8; // rcx
  UFG::qNode<PoseNode,PoseNode> *mPrev; // rax

  mOffset = this->mParent.mOffset;
  if ( !mOffset )
    return 0i64;
  v8 = (char *)&this->mParent + mOffset;
  if ( !v8 )
    return 0i64;
  blendIn->mSyncOnStart = syncStart;
  blendIn->mPriority = this->mPriority;
  mPrev = this->mPrev;
  mPrev->mNext = &blendIn->UFG::qNode<PoseNode,PoseNode>;
  blendIn->mPrev = mPrev;
  blendIn->mNext = &this->UFG::qNode<PoseNode,PoseNode>;
  this->mPrev = &blendIn->UFG::qNode<PoseNode,PoseNode>;
  blendIn->mParent.mOffset = v8 - (char *)&blendIn->mParent;
  (*(void (__fastcall **)(char *, PoseNode *))(*(_QWORD *)v8 + 384i64))(v8, this);
  ((void (__fastcall *)(BlendNode *, PoseNode *))blendIn->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[4].GetClassNameUID)(
    blendIn,
    this);
  ((void (__fastcall *)(BlendNode *, PoseNode *))blendIn->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[4].GetClassNameUID)(
    blendIn,
    newNode);
  return blendIn;
}

// File Line: 1511
// RVA: 0x3B9BE0
void __fastcall PoseNode::writeDebugDisplayToString(
        PoseNode *this,
        UFG::qStringBuilder *debugStringBuilder,
        unsigned int indentSpaces,
        char *parentInfo)
{
  char *v5; // rdi
  char *v8; // rbx
  const char *v9; // rax

  v5 = &customCaption;
  if ( parentInfo )
    v5 = parentInfo;
  v8 = UFG::qSymbol::as_cstr_dbg(&this->mName);
  v9 = this->Expression::IMemberMap::vfptr->GetClassname(this);
  UFG::qStringBuilder::Format(debugStringBuilder, "%*s%s:%s:%s\n", indentSpaces, &customCaption, v9, v8, v5);
}

// File Line: 1523
// RVA: 0x3B9C70
void __fastcall PoseNodeParent::writeDebugDisplayToString(
        PoseNodeParent *this,
        UFG::qStringBuilder *debugStringBuilder,
        int indentSpaces,
        char *parentInfo)
{
  UFG::qNode<PoseNode,PoseNode> *mNext; // rbx
  unsigned int v8; // esi
  int *p_mNetPoseSequence; // rdi
  int *i; // rbx

  PoseNode::writeDebugDisplayToString(this, debugStringBuilder, 0, parentInfo);
  mNext = this->mChildren.mNode.mNext;
  v8 = sSpacesPerIndent_0 + indentSpaces;
  p_mNetPoseSequence = &this->mNetPoseSequence;
  for ( i = (int *)&mNext[-3].mNext; i != p_mNetPoseSequence; i = (int *)(*((_QWORD *)i + 6) - 40i64) )
    (*(void (__fastcall **)(int *, UFG::qStringBuilder *, _QWORD, _QWORD))(*(_QWORD *)i + 136i64))(
      i,
      debugStringBuilder,
      v8,
      0i64);
}

// File Line: 1537
// RVA: 0x3AB220
char __fastcall PoseNodeParent::IsFinished(PoseNodeParent *this, float inTimeDelta)
{
  int *p_mNetPoseSequence; // rdi
  PoseNodeParent *p_mNext; // rbx

  p_mNetPoseSequence = &this->mNetPoseSequence;
  p_mNext = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( p_mNext == (PoseNodeParent *)&this->mNetPoseSequence )
    return 1;
  while ( ((unsigned __int8 (__fastcall *)(PoseNodeParent *))p_mNext->PoseNode::Expression::IMemberMap::vfptr[1].SetResourceOwner)(p_mNext) )
  {
    p_mNext = (PoseNodeParent *)&p_mNext->mNext[-3].mNext;
    if ( p_mNext == (PoseNodeParent *)p_mNetPoseSequence )
      return 1;
  }
  return 0;
}

// File Line: 1551
// RVA: 0x3AA7B0
void __fastcall PoseNodeParent::HoldLastFrame(PoseNodeParent *this)
{
  int *p_mNetPoseSequence; // rdi
  PoseNodeParent *p_mNext; // rbx

  p_mNetPoseSequence = &this->mNetPoseSequence;
  p_mNext = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( p_mNext != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      p_mNext->PoseNode::Expression::IMemberMap::vfptr[1].GetResourceOwner(p_mNext);
      p_mNext = (PoseNodeParent *)&p_mNext->mNext[-3].mNext;
    }
    while ( p_mNext != (PoseNodeParent *)p_mNetPoseSequence );
  }
}

// File Line: 1560
// RVA: 0x3AF5C0
void __fastcall PoseNodeParent::SetPlayMode(PoseNodeParent *this, unsigned int mode)
{
  int *p_mNetPoseSequence; // rdi
  PoseNodeParent *p_mNext; // rbx

  p_mNetPoseSequence = &this->mNetPoseSequence;
  p_mNext = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( p_mNext != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      p_mNext->PoseNode::Expression::IMemberMap::vfptr[2].FindWithOldPath(p_mNext, (const char *)mode);
      p_mNext = (PoseNodeParent *)&p_mNext->mNext[-3].mNext;
    }
    while ( p_mNext != (PoseNodeParent *)p_mNetPoseSequence );
  }
}

// File Line: 1569
// RVA: 0x3AC5A0
void __fastcall PoseNodeParent::Pause(PoseNodeParent *this)
{
  int *p_mNetPoseSequence; // rdi
  PoseNodeParent *p_mNext; // rbx

  p_mNetPoseSequence = &this->mNetPoseSequence;
  p_mNext = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( p_mNext != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      ((void (__fastcall *)(PoseNodeParent *))p_mNext->PoseNode::Expression::IMemberMap::vfptr[2].__vecDelDtor)(p_mNext);
      p_mNext = (PoseNodeParent *)&p_mNext->mNext[-3].mNext;
    }
    while ( p_mNext != (PoseNodeParent *)p_mNetPoseSequence );
  }
}

// File Line: 1578
// RVA: 0x3AE4B0
void __fastcall PoseNodeParent::Resume(PoseNodeParent *this)
{
  int *p_mNetPoseSequence; // rdi
  PoseNodeParent *p_mNext; // rbx

  p_mNetPoseSequence = &this->mNetPoseSequence;
  p_mNext = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( p_mNext != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      p_mNext->PoseNode::Expression::IMemberMap::vfptr[2].CreateClone(p_mNext);
      p_mNext = (PoseNodeParent *)&p_mNext->mNext[-3].mNext;
    }
    while ( p_mNext != (PoseNodeParent *)p_mNetPoseSequence );
  }
}

// File Line: 1605
// RVA: 0x3B0C40
__int64 __fastcall BlendDirectionNode::Update(BlendDirectionNode *this, float timeDelta, bool updateAnimation)
{
  unsigned __int8 v5; // di

  ((void (__fastcall *)(BlendDirectionNode *))this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[4].Serialize)(this);
  BlendDirectionNode::updateActiveDirection(this, timeDelta);
  this->mWeight = BlendDirectionNode::selectActive(this, &this->mChild0ID, &this->mChild1ID);
  if ( sSyncBlendDirNode )
    this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[5].ResolveReferences(this);
  v5 = PoseNodeParent::Update(this, timeDelta, updateAnimation);
  if ( this->mSetPhaseMatch )
    this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[5].ResolveReferences(this);
  return v5;
}

// File Line: 1637
// RVA: 0x3B7DD0
float __fastcall BlendDirectionNode::selectActive(BlendDirectionNode *this, int *child0ID, int *child1ID)
{
  int v3; // r9d
  int v7; // ebp
  BlendDirectionNode *i; // rax
  float v9; // xmm8_4
  __int64 v10; // r11
  int v11; // ecx
  float *v12; // rdx
  unsigned __int64 v13; // r8
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  __int64 v21; // r10
  float *v22; // rax
  float v23; // xmm1_4
  __int64 v24; // rbx
  float v25; // xmm10_4
  float v26; // xmm11_4
  float mActiveDirection; // xmm6_4
  float v28; // xmm7_4
  float v29; // xmm7_4
  float v30; // xmm6_4
  __int64 v31; // rax
  float v32; // xmm1_4
  __int64 v33; // rax
  float v34; // xmm1_4
  float v35; // xmm8_4
  float result; // xmm0_4

  v3 = 0;
  *child0ID = 0;
  *child1ID = 1;
  v7 = 0;
  for ( i = (BlendDirectionNode *)&this->mChildren.mNode.mNext[-3].mNext;
        i != (BlendDirectionNode *)&this->mNetPoseSequence;
        i = (BlendDirectionNode *)&i->mNext[-3].mNext )
  {
    ++v7;
  }
  v9 = FLOAT_3_4028235e38;
  v10 = 0i64;
  if ( v7 >= 4i64 )
  {
    v11 = 2;
    v12 = &this->mDirections[1];
    v13 = ((unsigned __int64)(v7 - 4i64) >> 2) + 1;
    v10 = 4 * v13;
    do
    {
      if ( v3 < 8 )
      {
        v14 = *(v12 - 1);
        if ( v14 >= 0.0 )
        {
          LODWORD(v15) = COERCE_UNSIGNED_INT(v14 - this->mActiveDirection) & _xmm;
          if ( v15 > 6.2831855 )
            v15 = v15 + -6.2831855;
          if ( v15 > 3.1415927 )
            v15 = 6.2831855 - v15;
          if ( v15 < v9 )
          {
            v9 = v15;
            *child0ID = v3;
          }
        }
      }
      if ( v11 - 1 < 8 && *v12 >= 0.0 )
      {
        LODWORD(v16) = COERCE_UNSIGNED_INT(*v12 - this->mActiveDirection) & _xmm;
        if ( v16 > 6.2831855 )
          v16 = v16 + -6.2831855;
        if ( v16 > 3.1415927 )
          v16 = 6.2831855 - v16;
        if ( v16 < v9 )
        {
          v9 = v16;
          *child0ID = v11 - 1;
        }
      }
      if ( v11 < 8 )
      {
        v17 = v12[1];
        if ( v17 >= 0.0 )
        {
          LODWORD(v18) = COERCE_UNSIGNED_INT(v17 - this->mActiveDirection) & _xmm;
          if ( v18 > 6.2831855 )
            v18 = v18 + -6.2831855;
          if ( v18 > 3.1415927 )
            v18 = 6.2831855 - v18;
          if ( v18 < v9 )
          {
            v9 = v18;
            *child0ID = v11;
          }
        }
      }
      if ( v11 + 1 < 8 )
      {
        v19 = v12[2];
        if ( v19 >= 0.0 )
        {
          LODWORD(v20) = COERCE_UNSIGNED_INT(v19 - this->mActiveDirection) & _xmm;
          if ( v20 > 6.2831855 )
            v20 = v20 + -6.2831855;
          if ( v20 > 3.1415927 )
            v20 = 6.2831855 - v20;
          if ( v20 < v9 )
          {
            v9 = v20;
            *child0ID = v11 + 1;
          }
        }
      }
      v3 += 4;
      v11 += 4;
      v12 += 4;
      --v13;
    }
    while ( v13 );
  }
  if ( v10 < v7 )
  {
    v21 = v7 - v10;
    v22 = &this->mDirections[v10];
    do
    {
      if ( v3 < 8 && *v22 >= 0.0 )
      {
        LODWORD(v23) = COERCE_UNSIGNED_INT(*v22 - this->mActiveDirection) & _xmm;
        if ( v23 > 6.2831855 )
          v23 = v23 + -6.2831855;
        if ( v23 > 3.1415927 )
          v23 = 6.2831855 - v23;
        if ( v23 < v9 )
        {
          v9 = v23;
          *child0ID = v3;
        }
      }
      ++v3;
      ++v22;
      --v21;
    }
    while ( v21 );
  }
  v24 = *child0ID;
  v25 = FLOAT_N1_0;
  if ( (int)v24 >= 8 )
    v26 = FLOAT_N1_0;
  else
    v26 = this->mDirections[v24];
  mActiveDirection = this->mActiveDirection;
  v28 = cosf(mActiveDirection);
  v29 = v28 * sinf(v26);
  v30 = sinf(mActiveDirection);
  if ( (float)(v29 - (float)(v30 * cosf(v26))) > 0.0 )
  {
    *child1ID = v24 - 1;
    if ( (int)v24 - 1 < 0 )
      *child1ID = v7 - 1;
  }
  else
  {
    *child1ID = ((int)v24 + 1) % v7;
  }
  v31 = *child0ID;
  if ( (int)v31 >= 8 )
    v32 = FLOAT_N1_0;
  else
    v32 = this->mDirections[v31];
  v33 = *child1ID;
  if ( (int)v33 < 8 )
    v25 = this->mDirections[v33];
  LODWORD(v34) = COERCE_UNSIGNED_INT(v32 - v25) & _xmm;
  if ( v34 > 3.1415927 )
    v34 = 6.2831855 - v34;
  if ( v34 <= 0.0000099999997 )
    return 0.0;
  v35 = v9 > v34 ? v9 / (float)(6.2831855 - v34) : v9 / v34;
  if ( v35 <= 0.0 )
    return 0.0;
  result = *(float *)&FLOAT_1_0;
  if ( v35 < 1.0 )
    return v35;
  return result;
}

// File Line: 1723
// RVA: 0x3B98D0
void __fastcall BlendDirectionNode::writeDebugDisplayToString(
        BlendDirectionNode *this,
        UFG::qStringBuilder *debugStringBuilder,
        unsigned int indentSpaces,
        char *parentInfo)
{
  float mActiveDirection; // xmm6_4
  char *v6; // rdi
  char *v9; // rbx
  const char *v10; // rax
  unsigned int v11; // ebp
  float v12; // xmm0_4
  UFG::qNode<PoseNode,PoseNode> *mNext; // rbx
  int *p_mNext; // rbx
  int *p_mNetPoseSequence; // rsi
  float *v16; // rdi
  float dest[8]; // [rsp+40h] [rbp-88h] BYREF
  char v18[64]; // [rsp+60h] [rbp-68h] BYREF
  int child1ID; // [rsp+D0h] [rbp+8h] BYREF
  int child0ID; // [rsp+E0h] [rbp+18h] BYREF

  mActiveDirection = this->mActiveDirection;
  v6 = &customCaption;
  if ( parentInfo )
    v6 = parentInfo;
  v9 = UFG::qSymbol::as_cstr_dbg(&this->mName);
  v10 = this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr->GetClassname(this);
  UFG::qStringBuilder::Format(
    debugStringBuilder,
    "%*s%s:%s:Dir:%0.3f:%s\n",
    indentSpaces,
    &customCaption,
    v10,
    v9,
    mActiveDirection,
    v6);
  v11 = sSpacesPerIndent_0 + indentSpaces;
  v12 = BlendDirectionNode::selectActive(this, &child0ID, &child1ID);
  UFG::qMemSet(dest, 0, 0x20u);
  mNext = this->mChildren.mNode.mNext;
  dest[child0ID] = 1.0 - v12;
  p_mNext = (int *)&mNext[-3].mNext;
  p_mNetPoseSequence = &this->mNetPoseSequence;
  dest[child1ID] = v12;
  if ( p_mNext != p_mNetPoseSequence )
  {
    v16 = dest;
    do
    {
      UFG::qSPrintf(v18, "w:%0.3f", *v16);
      (*(void (__fastcall **)(int *, UFG::qStringBuilder *, _QWORD, char *))(*(_QWORD *)p_mNext + 136i64))(
        p_mNext,
        debugStringBuilder,
        v11,
        v18);
      ++v16;
      p_mNext = (int *)(*((_QWORD *)p_mNext + 6) - 40i64);
    }
    while ( p_mNext != p_mNetPoseSequence );
  }
}

// File Line: 1752
// RVA: 0x3A89C0
void __fastcall BlendDirectionNode::GetExtractedDeltaReferenceFrame(
        BlendDirectionNode *this,
        float deltaTime,
        hkQsTransformf *deltaMotionOut)
{
  unsigned __int64 mChild0ID; // rdx
  UFG::qNode<PoseNode,PoseNode> **p_mNext; // rbx
  BlendDirectionNode *i; // rcx
  int mChild1ID; // eax
  __int64 v9; // rdx
  __m128 v10; // xmm4
  __m128 v11; // xmm0
  hkVector4f v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm5
  __m128 v15; // xmm0
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // [rsp+20h] [rbp-78h] BYREF
  __m128 v20; // [rsp+30h] [rbp-68h]
  __m128 v21; // [rsp+40h] [rbp-58h]
  __m128 v22; // [rsp+50h] [rbp-48h] BYREF
  __m128 v23; // [rsp+60h] [rbp-38h]
  __m128 v24; // [rsp+70h] [rbp-28h]

  mChild0ID = (unsigned int)this->mChild0ID;
  p_mNext = &this->mChildren.mNode.mNext[-3].mNext;
  for ( i = (BlendDirectionNode *)p_mNext; (int)mChild0ID > 0; i = (BlendDirectionNode *)&i->mNext[-3].mNext )
  {
    if ( i == (BlendDirectionNode *)&this->mNetPoseSequence )
      break;
    mChild0ID = (unsigned int)(mChild0ID - 1);
  }
  mChild1ID = this->mChild1ID;
  if ( mChild1ID > 0 )
  {
    mChild0ID = (unsigned __int64)&this->mNetPoseSequence;
    do
    {
      if ( p_mNext == (UFG::qNode<PoseNode,PoseNode> **)mChild0ID )
        break;
      --mChild1ID;
      p_mNext = &p_mNext[6][-3].mNext;
    }
    while ( mChild1ID > 0 );
  }
  i->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[1].GetResourcePath(i, (char *)mChild0ID, (int)&v22);
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, __int64, __m128 *))(*p_mNext)[8].mPrev)(p_mNext, v9, &v19);
  v10 = _mm_shuffle_ps((__m128)LODWORD(this->mWeight), (__m128)LODWORD(this->mWeight), 0);
  v11 = _mm_mul_ps(v20, v23);
  v12.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v19, v22), v10), v22);
  deltaMotionOut->m_scale.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v21, v24), v10), v24);
  v13 = _mm_add_ps(_mm_shuffle_ps(v11, v11, 78), v11);
  deltaMotionOut->m_translation = (hkVector4f)v12.m_quad;
  v14 = _mm_add_ps(
          _mm_mul_ps(
            _mm_xor_ps(
              (__m128)_mm_slli_epi32(
                        _mm_srli_epi32(
                          (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 177), v13), (__m128)0i64),
                          0x1Fu),
                        0x1Fu),
              v10),
            v20),
          _mm_mul_ps(_mm_sub_ps(query.m_quad, v10), v23));
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 78), v15);
  v17 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 177), v16);
  v18 = _mm_rsqrt_ps(v17);
  deltaMotionOut->m_rotation.m_vec.m_quad = _mm_mul_ps(
                                              v14,
                                              _mm_mul_ps(
                                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                                                _mm_mul_ps(*(__m128 *)_xmm, v18)));
}

// File Line: 1769
// RVA: 0x3A9110
float __fastcall BlendDirectionNode::GetPhase(BlendDirectionNode *this, float futureTimeDelta)
{
  float result; // xmm0_4
  int v4; // eax
  BlendDirectionNode *i; // rcx
  int child0ID; // [rsp+40h] [rbp+8h] BYREF
  int child1ID; // [rsp+50h] [rbp+18h] BYREF

  child0ID = 0;
  child1ID = 1;
  result = BlendDirectionNode::selectActive(this, &child0ID, &child1ID);
  v4 = child0ID;
  for ( i = (BlendDirectionNode *)&this->mChildren.mNode.mNext[-3].mNext;
        v4 > 0;
        i = (BlendDirectionNode *)&i->mNext[-3].mNext )
  {
    if ( i == (BlendDirectionNode *)&this->mNetPoseSequence )
      break;
    --v4;
  }
  i->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[2].GetClassname(i);
  return result;
}

// File Line: 1780
// RVA: 0x3A8200
float __fastcall BlendDirectionNode::GetDuration(BlendDirectionNode *this)
{
  float result; // xmm0_4
  int v3; // eax
  BlendDirectionNode *i; // rcx
  int child0ID; // [rsp+30h] [rbp+8h] BYREF
  int child1ID; // [rsp+38h] [rbp+10h] BYREF

  child0ID = 0;
  child1ID = 1;
  result = BlendDirectionNode::selectActive(this, &child0ID, &child1ID);
  v3 = child0ID;
  for ( i = (BlendDirectionNode *)&this->mChildren.mNode.mNext[-3].mNext;
        v3 > 0;
        i = (BlendDirectionNode *)&i->mNext[-3].mNext )
  {
    if ( i == (BlendDirectionNode *)&this->mNetPoseSequence )
      break;
    --v3;
  }
  ((void (__fastcall *)(BlendDirectionNode *))i->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[2].SetResourceOwner)(i);
  return result;
}

// File Line: 1791
// RVA: 0x3A9180
void __fastcall BlendDirectionNode::GetPhase(BlendDirectionNode *this, MotionPhase2 *motionPhase)
{
  int v4; // r8d
  BlendDirectionNode *p_mNext; // rax
  void *v6; // rax
  int child0ID; // [rsp+30h] [rbp+8h] BYREF
  int child1ID; // [rsp+40h] [rbp+18h] BYREF

  v4 = 0;
  p_mNext = (BlendDirectionNode *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( p_mNext == (BlendDirectionNode *)&this->mNetPoseSequence )
    goto LABEL_5;
  do
  {
    ++v4;
    p_mNext = (BlendDirectionNode *)&p_mNext->mNext[-3].mNext;
  }
  while ( p_mNext != (BlendDirectionNode *)&this->mNetPoseSequence );
  if ( v4 < 2 )
  {
LABEL_5:
    *(_QWORD *)&motionPhase->mPhaseMark.mValue = 0i64;
    *(_QWORD *)&motionPhase->mPhase = 0i64;
  }
  else
  {
    child0ID = 0;
    child1ID = 1;
    BlendDirectionNode::selectActive(this, &child0ID, &child1ID);
    v6 = this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[1].__vecDelDtor(this, (unsigned int)child0ID);
    (*(void (__fastcall **)(void *, MotionPhase2 *))(*(_QWORD *)v6 + 184i64))(v6, motionPhase);
  }
}

// File Line: 1808
// RVA: 0x3AF550
void __fastcall BlendPhaseNode::SetPhase(BlendPhaseNode *this, MotionPhase2 *motionPhase)
{
  int *p_mNetPoseSequence; // rdi
  BlendPhaseNode *p_mNext; // rbx

  p_mNetPoseSequence = &this->mNetPoseSequence;
  p_mNext = (BlendPhaseNode *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( p_mNext != (BlendPhaseNode *)&this->mNetPoseSequence )
  {
    do
    {
      ((void (__fastcall *)(BlendPhaseNode *, MotionPhase2 *))p_mNext->BlendNode::PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[2].GetClassNameUID)(
        p_mNext,
        motionPhase);
      p_mNext = (BlendPhaseNode *)&p_mNext->mNext[-3].mNext;
    }
    while ( p_mNext != (BlendPhaseNode *)p_mNetPoseSequence );
  }
}

// File Line: 1817
// RVA: 0x3AA690
MotionPhase2 *__fastcall BlendDirectionNode::Get_MotionPhase(BlendDirectionNode *this)
{
  MotionPhase2 *p_mMotionPhase; // rbx
  BlendDirectionNode *p_mNext; // rax
  int v4; // edx
  void *v5; // rax
  int child0ID; // [rsp+30h] [rbp+8h] BYREF
  int child1ID; // [rsp+38h] [rbp+10h] BYREF

  p_mMotionPhase = &this->mMotionPhase;
  *(_QWORD *)&this->mMotionPhase.mPhaseMark.mValue = 0i64;
  *(_QWORD *)&this->mMotionPhase.mPhase = 0i64;
  p_mNext = (BlendDirectionNode *)&this->mChildren.mNode.mNext[-3].mNext;
  v4 = 0;
  if ( p_mNext != (BlendDirectionNode *)&this->mNetPoseSequence )
  {
    do
    {
      ++v4;
      p_mNext = (BlendDirectionNode *)&p_mNext->mNext[-3].mNext;
    }
    while ( p_mNext != (BlendDirectionNode *)&this->mNetPoseSequence );
    if ( v4 >= 2 )
    {
      child0ID = 0;
      child1ID = 1;
      BlendDirectionNode::selectActive(this, &child0ID, &child1ID);
      v5 = this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[1].__vecDelDtor(this, (unsigned int)child0ID);
      (*(void (__fastcall **)(void *, MotionPhase2 *))(*(_QWORD *)v5 + 184i64))(v5, p_mMotionPhase);
    }
  }
  return p_mMotionPhase;
}

// File Line: 1838
// RVA: 0x3AF6A0
void __fastcall BlendPhaseNode::SetRateWeight0(
        BlendPhaseNode *this,
        float animLength0,
        float animLength1,
        float weight)
{
  int *p_mNetPoseSequence; // rdi
  BlendPhaseNode *p_mNext; // rbx

  p_mNetPoseSequence = &this->mNetPoseSequence;
  p_mNext = (BlendPhaseNode *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( p_mNext != (BlendPhaseNode *)&this->mNetPoseSequence )
  {
    do
    {
      ((void (__fastcall *)(BlendPhaseNode *))p_mNext->BlendNode::PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[2].GetResourcePath)(p_mNext);
      p_mNext = (BlendPhaseNode *)&p_mNext->mNext[-3].mNext;
    }
    while ( p_mNext != (BlendPhaseNode *)p_mNetPoseSequence );
  }
}

// File Line: 1847
// RVA: 0x3AF760
void __fastcall BlendPhaseNode::SetRateWeight1(
        BlendPhaseNode *this,
        float animLength0,
        float animLength1,
        float weight)
{
  int *p_mNetPoseSequence; // rdi
  BlendPhaseNode *p_mNext; // rbx

  p_mNetPoseSequence = &this->mNetPoseSequence;
  p_mNext = (BlendPhaseNode *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( p_mNext != (BlendPhaseNode *)&this->mNetPoseSequence )
  {
    do
    {
      p_mNext->BlendNode::PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[2].ResolveReferences(p_mNext);
      p_mNext = (BlendPhaseNode *)&p_mNext->mNext[-3].mNext;
    }
    while ( p_mNext != (BlendPhaseNode *)p_mNetPoseSequence );
  }
}

// File Line: 1856
// RVA: 0x3AED60
void __fastcall BlendDirectionNode::SetActiveDirection(BlendDirectionNode *this, float activeDirection, bool force)
{
  float LimitedActiveAngle; // xmm0_4
  float v6; // xmm2_4

  LimitedActiveAngle = BlendDirectionNode::getLimitedActiveAngle(this, activeDirection);
  this->mDesiredActiveDirection = LimitedActiveAngle;
  v6 = LimitedActiveAngle - activeDirection;
  if ( (float)(LimitedActiveAngle - activeDirection) < 0.0 )
    LODWORD(v6) ^= _xmm[0];
  if ( v6 < 0.001 && force )
    this->mActiveDirection = LimitedActiveAngle;
}

// File Line: 1874
// RVA: 0x3B7190
float __fastcall BlendDirectionNode::getLimitedActiveAngle(BlendDirectionNode *this, float inputAngle)
{
  __int64 mLimitIndexCW; // rax
  __int64 mLimitIndexCCW; // rdx
  float v4; // xmm2_4
  float v5; // xmm0_4
  int v6; // r8d
  int v7; // edx
  unsigned __int16 v8; // r10
  int v9; // eax

  mLimitIndexCW = this->mLimitIndexCW;
  if ( (int)mLimitIndexCW < 0 )
    return inputAngle;
  mLimitIndexCCW = this->mLimitIndexCCW;
  if ( (int)mLimitIndexCCW < 0 )
    return inputAngle;
  v4 = FLOAT_N1_0;
  if ( (int)mLimitIndexCW >= 8 )
    v5 = FLOAT_N1_0;
  else
    v5 = this->mDirections[mLimitIndexCW];
  v6 = (int)(float)((float)(v5 * 32768.0) * 0.31830987);
  if ( (int)mLimitIndexCCW < 8 )
    v4 = this->mDirections[mLimitIndexCCW];
  v7 = (int)(float)((float)(v4 * 32768.0) * 0.31830987);
  v8 = (int)(float)((float)(inputAngle * 32768.0) * 0.31830987) - v7;
  if ( v8 <= (unsigned __int16)(v6 - v7) )
    return inputAngle;
  if ( v8 >= (unsigned __int16)(v6 - v7) + ((unsigned __int16)(v7 - v6) >> 1) )
    v9 = (unsigned __int16)v7;
  else
    v9 = (unsigned __int16)v6;
  return (float)((float)v9 * 3.1415927) * 0.000030517578;
}

// File Line: 1914
// RVA: 0x3B8340
void __fastcall BlendDirectionNode::updateActiveDirection(BlendDirectionNode *this, float timeDelta)
{
  float mDesiredActiveDirection; // xmm6_4
  float mActiveDirection; // xmm9_4
  float v5; // xmm11_4
  float v6; // xmm12_4
  float v7; // xmm8_4
  float v8; // xmm6_4
  float v9; // xmm10_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm8_4
  int v14; // xmm1_4
  float v15; // xmm7_4
  __int64 mLimitIndexCW; // rax
  __int64 mLimitIndexCCW; // rax

  mDesiredActiveDirection = this->mDesiredActiveDirection;
  mActiveDirection = this->mActiveDirection;
  v5 = cosf(mDesiredActiveDirection);
  v6 = sinf(mDesiredActiveDirection);
  v7 = cosf(mActiveDirection);
  v8 = FLOAT_N1_0;
  v9 = sinf(mActiveDirection);
  v10 = (float)(v9 * v6) + (float)(v7 * v5);
  if ( v10 <= -1.0 )
  {
    v10 = FLOAT_N1_0;
    goto LABEL_5;
  }
  v11 = *(float *)&FLOAT_1_0;
  if ( v10 < 1.0 )
LABEL_5:
    v11 = v10;
  v12 = acosf(v11);
  v13 = (float)(v7 * v6) - (float)(v9 * v5);
  *(float *)&v14 = v12;
  if ( v13 < 0.0 )
    v14 = LODWORD(v12) ^ _xmm[0];
  v15 = mActiveDirection + (float)(sChangeErrorsGain * *(float *)&v14);
  if ( v15 >= 6.2831855 )
    v15 = v15 + -6.2831855;
  if ( v15 < 0.0 )
    v15 = v15 + 6.2831855;
  if ( v13 < 0.0 )
  {
    mLimitIndexCCW = this->mLimitIndexCCW;
    if ( (int)mLimitIndexCCW >= 0 )
    {
      if ( (int)mLimitIndexCCW < 8 )
        v8 = this->mDirections[mLimitIndexCCW];
      if ( v8 > v15 && mActiveDirection >= v8 )
        goto LABEL_18;
    }
  }
  else
  {
    mLimitIndexCW = this->mLimitIndexCW;
    if ( (int)mLimitIndexCW >= 0 )
    {
      if ( (int)mLimitIndexCW < 8 )
        v8 = this->mDirections[mLimitIndexCW];
      if ( v15 > v8 && mActiveDirection <= v8 )
      {
LABEL_18:
        this->mActiveDirection = v8;
        return;
      }
    }
  }
  this->mActiveDirection = v15;
}

// File Line: 1977
// RVA: 0x3B8BC0
void __fastcall BlendDirectionNode::updateOperation(BlendDirectionNode *this)
{
  float mPlayRate; // xmm6_4
  float v3; // xmm0_4
  int v4; // r8d
  BlendDirectionNode *p_mNext; // rdx
  BlendDirectionNode *i; // rcx
  int j; // eax
  Expression::IMemberMapVtbl *vfptr; // rax
  Expression::IMemberMapVtbl *v9; // rax
  void **v10; // [rsp+30h] [rbp-38h] BYREF
  char v11; // [rsp+38h] [rbp-30h]
  float v12; // [rsp+40h] [rbp-28h]
  int v13; // [rsp+44h] [rbp-24h]
  float v14; // [rsp+48h] [rbp-20h]
  char v15; // [rsp+4Ch] [rbp-1Ch]
  int child0ID; // [rsp+70h] [rbp+8h] BYREF
  int child1ID; // [rsp+78h] [rbp+10h] BYREF

  mPlayRate = this->mPlayRate;
  if ( this->mDurationMatch )
  {
    *(float *)&child0ID = 0.0;
    child1ID = 1;
    v3 = BlendDirectionNode::selectActive(this, &child0ID, &child1ID);
    v4 = child0ID;
    p_mNext = (BlendDirectionNode *)&this->mChildren.mNode.mNext[-3].mNext;
    for ( i = p_mNext; v4 > 0; i = (BlendDirectionNode *)&i->mNext[-3].mNext )
    {
      if ( i == (BlendDirectionNode *)&this->mNetPoseSequence )
        break;
      --v4;
    }
    for ( j = child1ID; j > 0; p_mNext = (BlendDirectionNode *)&p_mNext->mNext[-3].mNext )
    {
      if ( p_mNext == (BlendDirectionNode *)&this->mNetPoseSequence )
        break;
      --j;
    }
    if ( GetWeightedDurationAndParametricTime(i, p_mNext, v3, (float *)&child1ID, (float *)&child0ID) )
    {
      v10 = &AnimationNode_SetLocalTimeParametric::`vftable;
      vfptr = this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr;
      v12 = *(float *)&child0ID;
      v13 = child1ID;
      v14 = mPlayRate;
      v15 = 1;
      v11 = 1;
      vfptr[1].FindWithOldPath(this, (const char *)&v10);
    }
  }
  else
  {
    v12 = this->mPlayRate;
    v10 = &AnimationNode_SetPlayRate::`vftable;
    v9 = this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr;
    v11 = 1;
    v9[1].FindWithOldPath(this, (const char *)&v10);
  }
}

// File Line: 2014
// RVA: 0x3AF120
void __fastcall BlendDirectionNode::SetDesiredExtractedMotionSpeed(BlendDirectionNode *this, float extractedSpeed)
{
  int *p_mNetPoseSequence; // rsi
  BlendDirectionNode *p_mNext; // rbx

  p_mNetPoseSequence = &this->mNetPoseSequence;
  p_mNext = (BlendDirectionNode *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( p_mNext != (BlendDirectionNode *)&this->mNetPoseSequence )
  {
    do
    {
      ((void (__fastcall *)(BlendDirectionNode *))p_mNext->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[3].FindWithOldPath)(p_mNext);
      this->mPlayRate = ((float (__fastcall *)(BlendDirectionNode *))p_mNext->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[3].SetResourceOwner)(p_mNext);
      p_mNext = (BlendDirectionNode *)&p_mNext->mNext[-3].mNext;
    }
    while ( p_mNext != (BlendDirectionNode *)p_mNetPoseSequence );
  }
}

// File Line: 2030
// RVA: 0x3A2AC0
void __fastcall BlendNode::Begin(BlendNode *this)
{
  bool v2; // zf
  UFG::qNode<PoseNode,PoseNode> *mNext; // rcx
  Weightset *mWeightSet; // rax
  void **v5; // [rsp+20h] [rbp-28h] BYREF
  char v6; // [rsp+28h] [rbp-20h]
  char v7; // [rsp+30h] [rbp-18h]
  int mPriority; // [rsp+34h] [rbp-14h]
  Weightset *v9; // [rsp+38h] [rbp-10h]

  if ( !this->mStarted )
  {
    v2 = this->mPauseBlend == 0;
    this->mStarted = 1;
    if ( v2 )
    {
      if ( this->mKeepBlend )
      {
        if ( !sDisablePauseBlend )
        {
          mNext = this->mChildren.mNode.mNext;
          v7 = 1;
          v5 = &PoseNode_SetPauseBlend::`vftable;
          mPriority = this->mPriority;
          mWeightSet = this->mWeightSet;
          v6 = 0;
          v9 = mWeightSet;
          ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, void ***))mNext[-3].mNext[5].mPrev)(
            &mNext[-3].mNext,
            &v5);
        }
      }
    }
  }
}

// File Line: 2061
// RVA: 0x3B0CE0
bool __fastcall BlendNode::Update(BlendNode *this, float timeDelta, bool updateAnimation)
{
  __int64 mOffset; // rax
  char *v6; // rax
  __int64 v7; // rcx
  float mBlendRate; // xmm2_4
  float v9; // xmm0_4
  UFG::qNode<PoseNode,PoseNode> *mNext; // rdi
  UFG::qNode<PoseNode,PoseNode> *v11; // rsi
  PoseNode *p_mNext; // rdi
  PoseNode *v13; // rsi
  Expression::IMemberMapVtbl *vfptr; // rax
  void **v16; // [rsp+20h] [rbp-88h] BYREF
  char v17; // [rsp+28h] [rbp-80h]
  void **v18; // [rsp+30h] [rbp-78h] BYREF
  char v19; // [rsp+38h] [rbp-70h]
  char dest[32]; // [rsp+40h] [rbp-68h] BYREF
  void **v21; // [rsp+60h] [rbp-48h] BYREF
  char v22; // [rsp+68h] [rbp-40h]
  char v23[32]; // [rsp+70h] [rbp-38h] BYREF

  this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[1].GetClassname(this);
  if ( !this->mPauseBlend )
    goto LABEL_8;
  mOffset = this->mParent.mOffset;
  if ( mOffset )
  {
    v6 = (char *)&this->mParent + mOffset;
    if ( v6 )
    {
      v7 = *((_QWORD *)v6 + 7);
      if ( !v7 || !&v6[v7 + 56] )
        this->mPauseBlend = 0;
    }
  }
  if ( !this->mPauseBlend )
  {
LABEL_8:
    mBlendRate = this->mBlendRate;
    if ( mBlendRate != 0.0 )
    {
      v9 = (float)(mBlendRate * timeDelta) + this->mBlendParam;
      this->mBlendParam = v9;
      if ( mBlendRate <= 0.0 )
      {
        if ( v9 <= 0.0 )
          this->mBlendParam = 0.0;
      }
      else if ( v9 > 1.0 )
      {
        this->mBlendParam = 1.0;
      }
    }
  }
  if ( this->mSyncOnStart )
  {
    mNext = this->mChildren.mNode.mNext;
    v11 = mNext->mNext;
    p_mNext = (PoseNode *)&mNext[-3].mNext;
    this->mSyncOnStart = 0;
    v13 = (PoseNode *)&v11[-3].mNext;
    if ( v13 )
    {
      PhaseSync(p_mNext, v13);
      v16 = &AnimationNode_UpdateLastPlayTime::`vftable;
      vfptr = v13->Expression::IMemberMap::vfptr;
      v17 = 1;
      vfptr[1].FindWithOldPath(v13, (const char *)&v16);
      if ( sSyncBlendDirection )
      {
        v19 = 1;
        v18 = &BlendDirectionNode_GetBlendDirection::`vftable;
        UFG::qMemSet(dest, 0, 0x20u);
        p_mNext->Expression::IMemberMap::vfptr[1].FindWithOldPath(p_mNext, (const char *)&v18);
        v21 = &BlendDirectionNode_SetBlendDirection::`vftable;
        v22 = 1;
        UFG::qMemCopy(v23, dest, 0x20u);
        v13->Expression::IMemberMap::vfptr[1].FindWithOldPath(v13, (const char *)&v21);
      }
      if ( sUnpausePhasedSyncedBranch )
        p_mNext->Expression::IMemberMap::vfptr[2].CreateClone(p_mNext);
    }
  }
  PoseNodeParent::Update(this, timeDelta, updateAnimation);
  this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[5].GetClassNameUID(this);
  return BlendNode::updateOperationPost(this);
}

// File Line: 2143
// RVA: 0x3B8D60
char __fastcall BlendNode::updateOperationPost(BlendNode *this)
{
  __int64 v2; // rax
  int v3; // eax
  BlendNode *p_mNext; // rdx
  UFG::qNode<PoseNode,PoseNode> *v5; // rax
  UFG::qNode<PoseNode,PoseNode> *v6; // rcx
  UFG::qNode<PoseNode,PoseNode> *mNext; // r9
  __int64 v8; // rax
  char *p_mParent; // rdx
  char *v10; // rax
  __int64 v11; // rax
  UFG::qNode<PoseNode,PoseNode> *v12; // rax
  __int64 mOffset; // rax
  UFG::qNode<PoseNode,PoseNode> *v15; // rax
  UFG::qNode<PoseNode,PoseNode> *mPrev; // rcx
  __int64 v17; // rax
  char *v18; // rax
  UFG::qNode<PoseNode,PoseNode> *v19; // rcx
  int v20; // eax
  Weightset *mWeightSet; // rax
  void **v22; // [rsp+20h] [rbp-28h] BYREF
  char v23; // [rsp+28h] [rbp-20h]
  char v24; // [rsp+30h] [rbp-18h]
  int v25; // [rsp+34h] [rbp-14h]
  Weightset *v26; // [rsp+38h] [rbp-10h]

  if ( !this->mKeepBlend )
  {
    if ( this->mBlendRate <= 0.0 )
    {
      if ( this->mBlendParam == 0.0 )
      {
        mOffset = this->mParent.mOffset;
        if ( mOffset )
        {
          if ( (UFG::qOffset64<PoseNodeParent *> *)((char *)&this->mParent + mOffset) )
          {
            if ( PoseNode::sSimPauseOnBranchFinish )
            {
              UFG::Metrics::msInstance.mSimPausedDebug = 1;
              UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
            }
            mNext = this->mChildren.mNode.mNext;
            v15 = mNext->mNext;
            mPrev = mNext->mPrev;
            mPrev->mNext = v15;
            v15->mPrev = mPrev;
            mNext->mPrev = mNext;
            mNext->mNext = mNext;
            v17 = this->mParent.mOffset;
            p_mParent = (char *)&mNext[1];
            if ( v17 )
            {
              v18 = (char *)&this->mParent + v17;
              if ( v18 )
              {
                v11 = v18 - p_mParent;
                goto LABEL_15;
              }
            }
            goto LABEL_14;
          }
        }
      }
    }
    else if ( 1.0 == this->mBlendParam )
    {
      v2 = this->mParent.mOffset;
      if ( v2 )
      {
        if ( (UFG::qOffset64<PoseNodeParent *> *)((char *)&this->mParent + v2) )
        {
          if ( PoseNode::sSimPauseOnBranchFinish )
          {
            UFG::Metrics::msInstance.mSimPausedDebug = 1;
            UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
          }
          v3 = 1;
          p_mNext = (BlendNode *)&this->mChildren.mNode.mNext[-3].mNext;
          do
          {
            if ( p_mNext == (BlendNode *)&this->mNetPoseSequence )
              break;
            --v3;
            p_mNext = (BlendNode *)&p_mNext->mNext[-3].mNext;
          }
          while ( v3 > 0 );
          v5 = p_mNext->mNext;
          v6 = p_mNext->mPrev;
          mNext = &p_mNext->UFG::qNode<PoseNode,PoseNode>;
          v6->mNext = v5;
          v5->mPrev = v6;
          p_mNext->mPrev = &p_mNext->UFG::qNode<PoseNode,PoseNode>;
          p_mNext->mNext = &p_mNext->UFG::qNode<PoseNode,PoseNode>;
          v8 = this->mParent.mOffset;
          p_mParent = (char *)&p_mNext->mParent;
          if ( v8 )
          {
            v10 = (char *)&this->mParent + v8;
            if ( v10 )
            {
              v11 = v10 - p_mParent;
LABEL_15:
              *(_QWORD *)p_mParent = v11;
              v12 = this->mPrev;
              v12->mNext = mNext;
              mNext->mPrev = v12;
              mNext->mNext = &this->UFG::qNode<PoseNode,PoseNode>;
              this->mPrev = mNext;
              return 0;
            }
          }
LABEL_14:
          v11 = 0i64;
          goto LABEL_15;
        }
      }
    }
LABEL_26:
    if ( !sNoPauseOnBlendout || this->mBlendRate >= 0.0 )
      return 1;
    goto LABEL_28;
  }
  if ( 1.0 != this->mBlendParam )
    goto LABEL_26;
LABEL_28:
  v19 = this->mChildren.mNode.mNext;
  v20 = (int)v19[1].mNext;
  v22 = &PoseNode_SetPauseBlend::`vftable;
  v25 = v20;
  mWeightSet = this->mWeightSet;
  v24 = 0;
  v23 = 0;
  v26 = mWeightSet;
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, void ***))v19[-3].mNext[5].mPrev)(&v19[-3].mNext, &v22);
  return 1;
}

// File Line: 2213
// RVA: 0x3B9A40
void __fastcall BlendNode::writeDebugDisplayToString(
        BlendNode *this,
        UFG::qStringBuilder *debugStringBuilder,
        unsigned int indentSpaces,
        const char *parentInfo)
{
  double mBlendParam; // xmm6_8
  char *v8; // rbx
  const char *v9; // rax
  unsigned int v10; // esi
  int *p_mNext; // rbx
  int *i; // rdi

  mBlendParam = this->mBlendParam;
  v8 = UFG::qSymbol::as_cstr_dbg(&this->mName);
  v9 = this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr->GetClassname(this);
  UFG::qStringBuilder::Format(
    debugStringBuilder,
    "%*s%s:%s:Blend:%0.3f\n",
    indentSpaces,
    &customCaption,
    v9,
    v8,
    mBlendParam);
  v10 = sSpacesPerIndent_0 + indentSpaces;
  p_mNext = (int *)&this->mChildren.mNode.mNext[-3].mNext;
  for ( i = &this->mNetPoseSequence; p_mNext != i; p_mNext = (int *)(*((_QWORD *)p_mNext + 6) - 40i64) )
    (*(void (__fastcall **)(int *, UFG::qStringBuilder *, _QWORD, _QWORD))(*(_QWORD *)p_mNext + 136i64))(
      p_mNext,
      debugStringBuilder,
      v10,
      0i64);
}

// File Line: 2228
// RVA: 0x3A8B40
void __fastcall BlendNode::GetExtractedDeltaReferenceFrame(
        BlendNode *this,
        float deltaTime,
        hkQsTransformf *deltaMotionOut)
{
  __int64 v3; // rdx
  UFG::qNode<PoseNode,PoseNode> *mNext; // rcx
  UFG::qNode<PoseNode,PoseNode> *v7; // rbx
  __int64 v8; // rdx
  __m128 v9; // xmm4
  __m128 mBlendParam_low; // xmm1
  __m128 v11; // xmm2
  Weightset *mWeightSet; // rax
  float *mOffset; // rcx
  __m128 v14; // xmm4
  __m128 v15; // xmm0
  hkVector4f v16; // xmm1
  __m128 v17; // xmm1
  __m128 v18; // xmm5
  __m128 v19; // xmm0
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // [rsp+20h] [rbp-78h] BYREF
  __m128 v24; // [rsp+30h] [rbp-68h]
  __m128 v25; // [rsp+40h] [rbp-58h]
  __m128 v26; // [rsp+50h] [rbp-48h] BYREF
  __m128 v27; // [rsp+60h] [rbp-38h]
  __m128 v28; // [rsp+70h] [rbp-28h]

  mNext = this->mChildren.mNode.mNext;
  v7 = mNext->mNext;
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, __int64, __m128 *))mNext[-3].mNext[8].mPrev)(
    &mNext[-3].mNext,
    v3,
    &v26);
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, __int64, __m128 *))v7[-3].mNext[8].mPrev)(
    &v7[-3].mNext,
    v8,
    &v23);
  mBlendParam_low = (__m128)LODWORD(this->mBlendParam);
  if ( !sBlendOnlyTranlation || this->mWeightSet )
  {
    mWeightSet = this->mWeightSet;
    if ( mWeightSet )
    {
      mOffset = (float *)mWeightSet->mRawWeightSet.mOffset;
      if ( mOffset )
        mOffset = (float *)((char *)mOffset + (_QWORD)mWeightSet + 48);
      mBlendParam_low.m128_f32[0] = mBlendParam_low.m128_f32[0] * *mOffset;
    }
    v9.m128_f32[0] = mBlendParam_low.m128_f32[0];
    v14 = _mm_shuffle_ps(v9, v9, 0);
    v15 = _mm_mul_ps(v27, v24);
    v16.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v25, v28), v14), v28);
    deltaMotionOut->m_translation.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v23, v26), v14), v26);
    deltaMotionOut->m_scale = (hkVector4f)v16.m_quad;
    v17 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 78), v15);
    v18 = _mm_add_ps(
            _mm_mul_ps(
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32(
                            (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 177), v17), (__m128)0i64),
                            0x1Fu),
                          0x1Fu),
                v14),
              v24),
            _mm_mul_ps(_mm_sub_ps(query.m_quad, v14), v27));
    v19 = _mm_mul_ps(v18, v18);
    v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 78), v19);
    v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 177), v20);
    v22 = _mm_rsqrt_ps(v21);
    deltaMotionOut->m_rotation.m_vec.m_quad = _mm_mul_ps(
                                                v18,
                                                _mm_mul_ps(
                                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                                                  _mm_mul_ps(*(__m128 *)_xmm, v22)));
  }
  else
  {
    v11 = _mm_sub_ps(v23, v26);
    deltaMotionOut->m_rotation.m_vec.m_quad = v24;
    deltaMotionOut->m_scale = (hkVector4f)_xmm;
    deltaMotionOut->m_translation.m_quad = _mm_add_ps(
                                             _mm_mul_ps(v11, _mm_shuffle_ps(mBlendParam_low, mBlendParam_low, 0)),
                                             v26);
  }
}

// File Line: 2273
// RVA: 0x3A9220
void __fastcall BlendNode::GetPhase(BlendNode *this, MotionPhase2 *motionPhase)
{
  UFG::qNode<PoseNode,PoseNode> **p_mNext; // rcx
  UFG::qNode<PoseNode,PoseNode> *v5; // rbx
  float mBlendParam; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float mPhase; // xmm0_4
  Expression::IMemberMap *v12; // rcx
  int v13; // eax
  float v14; // xmm0_4
  float v15; // xmm1_4
  void **v16; // [rsp+28h] [rbp-58h] BYREF
  Expression::IMemberMap *v17; // [rsp+30h] [rbp-50h]
  __int64 v18; // [rsp+38h] [rbp-48h]
  __int64 v19; // [rsp+40h] [rbp-40h]
  void **v20; // [rsp+48h] [rbp-38h] BYREF
  Expression::IMemberMap *v21; // [rsp+50h] [rbp-30h]
  __int64 v22; // [rsp+58h] [rbp-28h]
  __int64 v23; // [rsp+60h] [rbp-20h]

  if ( (int *)&this->mChildren.mNode.mNext[-3].mNext != &this->mNetPoseSequence )
  {
    if ( sOldWay )
    {
      ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **))this->mChildren.mNode.mNext[-3].mNext[11].mNext)(&this->mChildren.mNode.mNext[-3].mNext);
      return;
    }
    v21 = 0i64;
    v20 = &MotionPhase2::`vftable;
    v22 = 0i64;
    v23 = 0i64;
    v17 = 0i64;
    v16 = &MotionPhase2::`vftable;
    v18 = 0i64;
    v19 = 0i64;
    p_mNext = &this->mChildren.mNode.mNext[-3].mNext;
    v5 = p_mNext[6];
    ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, void ***))(*p_mNext)[11].mNext)(p_mNext, &v20);
    ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, void ***))v5[-3].mNext[11].mNext)(&v5[-3].mNext, &v16);
    if ( sPhaseBlending )
    {
      mBlendParam = this->mBlendParam;
      if ( !(_DWORD)v22 || !(_DWORD)v18 )
      {
        *(_QWORD *)&motionPhase->mPhaseMark.mValue = 0i64;
        *(_QWORD *)&motionPhase->mPhase = 0i64;
        goto LABEL_28;
      }
      if ( (_DWORD)v22 == (_DWORD)v18 )
      {
        motionPhase->mPhaseMark.mValue = v22;
        motionPhase->mPhase = (float)((float)(*(float *)&v19 - *(float *)&v23) * mBlendParam) + *(float *)&v23;
LABEL_28:
        v16 = &Expression::IMemberMap::`vftable;
        v20 = &Expression::IMemberMap::`vftable;
        return;
      }
      v7 = *(float *)&FLOAT_1_0;
      v8 = *(float *)&v23;
      v9 = 1.0 - *(float *)&v23;
      if ( (float)(1.0 - *(float *)&v23) <= 0.0 )
      {
        v9 = 0.0;
      }
      else if ( v9 >= 1.0 )
      {
        v9 = *(float *)&FLOAT_1_0;
      }
      v10 = (float)(*(float *)&v19 + v9) * mBlendParam;
      if ( v10 < v9 )
      {
        motionPhase->mPhaseMark.mValue = v22;
        motionPhase->mPhase = (float)(v9 - v10) + v8;
      }
      else
      {
        motionPhase->mPhaseMark.mValue = v18;
        motionPhase->mPhase = v10 - v9;
      }
      mPhase = motionPhase->mPhase;
      if ( mPhase <= 0.0 )
      {
        mPhase = 0.0;
      }
      else if ( mPhase >= 1.0 )
      {
        goto LABEL_21;
      }
      v7 = mPhase;
LABEL_21:
      motionPhase->mPhase = v7;
      goto LABEL_28;
    }
    if ( (_DWORD)v18 )
    {
      v12 = v17;
      motionPhase->mPhaseMark.mValue = v18;
      v13 = HIDWORD(v18);
      v14 = *(float *)&v19;
      v15 = *((float *)&v19 + 1);
LABEL_27:
      motionPhase->mPhaseDuration = v15;
      motionPhase->mPhase = v14;
      motionPhase->mPhasePeriod = v13;
      motionPhase->mResourceOwner = v12;
      goto LABEL_28;
    }
    if ( (_DWORD)v22 )
    {
      v12 = v21;
      motionPhase->mPhaseMark.mValue = v22;
      v13 = HIDWORD(v22);
      v14 = *(float *)&v23;
      v15 = *((float *)&v23 + 1);
      goto LABEL_27;
    }
    v16 = &Expression::IMemberMap::`vftable;
    v20 = &Expression::IMemberMap::`vftable;
  }
  *(_QWORD *)&motionPhase->mPhaseMark.mValue = 0i64;
  *(_QWORD *)&motionPhase->mPhase = 0i64;
}

// File Line: 2317
// RVA: 0x3AA1D0
float *__fastcall BlendNode::GetWeights(BlendNode *this, unsigned int numBones, float weight)
{
  Weightset *mWeightSet; // rbx
  __int64 v4; // rbp
  float *Weights; // rdi
  __int64 mOffset; // rax
  char *v9; // r10
  float v10; // xmm0_4
  __int64 v11; // rax
  int v12; // edi
  int v13; // edx
  unsigned __int64 v14; // r8
  __int64 v15; // rcx
  __m128 v16; // xmm1
  int v17; // eax
  __int64 v18; // r11
  unsigned __int64 v19; // r9
  __int64 v20; // rcx
  unsigned __int64 v21; // rax
  __int64 v22; // rdx
  unsigned __int64 v23; // r8
  char *v24; // rax
  __int64 v25; // rax
  float *v26; // rdi
  __int64 i; // rcx

  mWeightSet = this->mWeightSet;
  v4 = (int)numBones;
  if ( !mWeightSet )
    return 0i64;
  if ( this->mWeightSetMask )
  {
    Weights = Weightset::GetWeights(mWeightSet, numBones, weight, 1);
    Weightset::MaskWeights(this->mWeightSetMask, Weights, v4);
    return Weights;
  }
  else if ( weight == 1.0 && numBones <= mWeightSet->mRawWeightSetPaddedLength )
  {
    mOffset = mWeightSet->mRawWeightSet.mOffset;
    if ( mOffset )
      return (float *)((char *)&mWeightSet->mRawWeightSet + mOffset);
    else
      return 0i64;
  }
  else
  {
    v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 4 * numBones, 0x10u);
    v10 = (float)(mWeightSet->mWeightsetEntires.mCount & 0x7FFFFFFF);
    if ( v10 >= (float)(int)v4 )
      v10 = (float)(int)v4;
    v11 = mWeightSet->mRawWeightSet.mOffset;
    v12 = 0;
    v13 = (int)v10;
    if ( v11 )
      v14 = (unsigned __int64)&mWeightSet->mRawWeightSet + v11;
    else
      v14 = 0i64;
    if ( v13 >= 8 )
    {
      v15 = v13 - 1;
      v16 = _mm_shuffle_ps((__m128)LODWORD(weight), (__m128)LODWORD(weight), 0);
      if ( (unsigned __int64)v9 > v14 + 4 * v15 || (unsigned __int64)&v9[4 * v15] < v14 )
      {
        do
        {
          *(__m128 *)&v9[4 * v12] = _mm_mul_ps(*(__m128 *)(v14 + 4i64 * v12), v16);
          v17 = v12 + 4;
          v12 += 8;
          *(__m128 *)&v9[4 * v17] = _mm_mul_ps(*(__m128 *)(v14 + 4i64 * v17), v16);
        }
        while ( v12 < (int)v10 - ((int)v10 & 7) );
      }
    }
    v18 = v12;
    if ( v12 < (__int64)v13 )
    {
      if ( v13 - (__int64)v12 >= 4 )
      {
        v19 = v14 - (_QWORD)v9;
        v20 = (__int64)&v9[4 * v12 + 4];
        v21 = ((unsigned __int64)(v13 - (__int64)v12 - 4) >> 2) + 1;
        v12 += 4 * v21;
        v18 += 4 * v21;
        do
        {
          v20 += 16i64;
          *(float *)(v20 - 20) = weight * *(float *)(v19 + v20 - 20);
          *(float *)(v20 - 16) = weight * *(float *)(v19 + v20 - 16);
          *(float *)(v20 - 12) = weight * *(float *)(v19 + v20 - 12);
          *(float *)(v20 - 8) = weight * *(float *)(v19 + v20 - 8);
          --v21;
        }
        while ( v21 );
      }
      if ( v18 < v13 )
      {
        v22 = v13 - v18;
        v23 = v14 - (_QWORD)v9;
        v24 = &v9[4 * v18];
        v12 += v22;
        do
        {
          v24 += 4;
          *((float *)v24 - 1) = weight * *(float *)&v24[v23 - 4];
          --v22;
        }
        while ( v22 );
      }
    }
    v25 = v12;
    if ( v12 < v4 )
    {
      v26 = (float *)&v9[4 * v12];
      for ( i = v4 - v25; i; --i )
        *v26++ = weight * 255.0;
    }
    return (float *)v9;
  }
}

// File Line: 2342
// RVA: 0x3B0C30
// attributes: thunk
bool __fastcall BlendAddNode::Update(BlendAddNode *this, float timeDelta, bool updateAnimation)
{
  return BlendNode::Update(this, timeDelta, updateAnimation);
}

// File Line: 2347
// RVA: 0x3B9B10
void __fastcall BlendPhaseNode::writeDebugDisplayToString(
        BlendSubNode *this,
        UFG::qStringBuilder *debugStringBuilder,
        unsigned int indentSpaces,
        const char *parentInfo)
{
  double mBlendParam; // xmm6_8
  char *v8; // rbx
  const char *v9; // rax
  unsigned int v10; // esi
  int *p_mNext; // rbx
  int *i; // rdi

  mBlendParam = this->mBlendParam;
  v8 = UFG::qSymbol::as_cstr_dbg(&this->mName);
  v9 = this->BlendNode::PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr->GetClassname(this);
  UFG::qStringBuilder::Format(
    debugStringBuilder,
    "%*s%s:%s::weight%0.3f\n",
    indentSpaces,
    &customCaption,
    v9,
    v8,
    mBlendParam);
  v10 = sSpacesPerIndent_0 + indentSpaces;
  p_mNext = (int *)&this->mChildren.mNode.mNext[-3].mNext;
  for ( i = &this->mNetPoseSequence; p_mNext != i; p_mNext = (int *)(*((_QWORD *)p_mNext + 6) - 40i64) )
    (*(void (__fastcall **)(int *, UFG::qStringBuilder *, _QWORD, _QWORD))(*(_QWORD *)p_mNext + 136i64))(
      p_mNext,
      debugStringBuilder,
      v10,
      0i64);
}

// File Line: 2361
// RVA: 0x3A8E60
void __fastcall BlendSubNode::GetExtractedDeltaReferenceFrame(
        BlendSubNode *this,
        float deltaTime,
        hkQsTransformf *deltaMotionOut)
{
  __int64 v3; // rdx
  hkQuaternionf v5; // xmm1
  hkVector4f v6; // xmm0
  __int128 v7[3]; // [rsp+20h] [rbp-38h] BYREF

  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, __int64, __int128 *))this->mChildren.mNode.mNext[-3].mNext[8].mPrev)(
    &this->mChildren.mNode.mNext[-3].mNext,
    v3,
    v7);
  v5.m_vec.m_quad = (__m128)v7[1];
  deltaMotionOut->m_translation = (hkVector4f)v7[0];
  v6.m_quad = (__m128)v7[2];
  deltaMotionOut->m_rotation = (hkQuaternionf)v5.m_vec.m_quad;
  deltaMotionOut->m_scale = (hkVector4f)v6.m_quad;
}

// File Line: 2374
// RVA: 0x3A90E0
void __fastcall BlendAddNode::GetPhase(BlendAddNode *this, MotionPhase2 *motionPhase)
{
  if ( (int *)&this->mChildren.mNode.mNext[-3].mNext == &this->mNetPoseSequence )
  {
    *(_QWORD *)&motionPhase->mPhaseMark.mValue = 0i64;
    *(_QWORD *)&motionPhase->mPhase = 0i64;
  }
  else
  {
    ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, MotionPhase2 *))this->mChildren.mNode.mNext[-3].mNext[11].mNext)(
      &this->mChildren.mNode.mNext[-3].mNext,
      motionPhase);
  }
}

// File Line: 2391
// RVA: 0x3B1120
bool __fastcall BlendSubNode::Update(BlendSubNode *this, float timeDelta, __int64 updateAnimation)
{
  __int64 v3; // rdx
  bool result; // al

  ((void (__fastcall *)(BlendSubNode *, __int64, __int64))this->BlendNode::PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[1].GetClassname)(
    this,
    v3,
    updateAnimation);
  result = 1;
  this->mLocalTime = timeDelta + this->mLocalTime;
  return result;
}

// File Line: 2432
// RVA: 0x3B0ED0
bool __fastcall BlendPhaseNode::Update(BlendPhaseNode *this, float timeDelta, bool updateAnimation)
{
  __int64 mOffset; // rax
  char *v7; // rax
  __int64 v8; // rcx
  float mBlendRate; // xmm1_4
  float v10; // xmm0_4
  UFG::qNode<PoseNode,PoseNode> *mNext; // rsi
  UFG::qNode<PoseNode,PoseNode> *v12; // rdi
  PoseNode *p_mNext; // rsi
  PoseNode *v14; // rdi
  Expression::IMemberMapVtbl *vfptr; // rax
  Expression::IMemberMapVtbl *v16; // rax
  __int64 v17; // rdx
  bool v18; // zf
  void **v20; // [rsp+20h] [rbp-B8h] BYREF
  char v21; // [rsp+28h] [rbp-B0h]
  __int64 v22; // [rsp+30h] [rbp-A8h]
  void **v23; // [rsp+38h] [rbp-A0h] BYREF
  char v24; // [rsp+40h] [rbp-98h]
  void **v25; // [rsp+48h] [rbp-90h] BYREF
  char v26; // [rsp+50h] [rbp-88h]
  char dest[32]; // [rsp+58h] [rbp-80h] BYREF
  void **v28; // [rsp+78h] [rbp-60h] BYREF
  char v29; // [rsp+80h] [rbp-58h]
  char v30[72]; // [rsp+88h] [rbp-50h] BYREF

  this->BlendNode::PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[1].GetClassname(this);
  if ( this->mPauseBlend )
  {
    mOffset = this->mParent.mOffset;
    if ( mOffset )
    {
      v7 = (char *)&this->mParent + mOffset;
      if ( v7 )
      {
        v8 = *((_QWORD *)v7 + 7);
        if ( !v8 || !&v7[v8 + 56] )
          this->mPauseBlend = 0;
      }
    }
  }
  if ( !this->mPauseBlend )
  {
    mBlendRate = this->mBlendRate;
    if ( mBlendRate != 0.0 )
    {
      v10 = (float)(mBlendRate * timeDelta) + this->mBlendParam;
      this->mBlendParam = v10;
      if ( mBlendRate <= 0.0 )
      {
        if ( v10 <= 0.0 )
          this->mBlendParam = 0.0;
      }
      else if ( v10 > 1.0 )
      {
        this->mBlendParam = 1.0;
      }
    }
  }
  PoseNodeParent::Update(this, timeDelta, updateAnimation);
  if ( this->mSyncOnStart )
  {
    mNext = this->mChildren.mNode.mNext;
    v12 = mNext->mNext;
    p_mNext = (PoseNode *)&mNext[-3].mNext;
    this->mSyncOnStart = 0;
    v14 = (PoseNode *)&v12[-3].mNext;
    if ( v14 )
    {
      PhaseSync(p_mNext, v14);
      v23 = &AnimationNode_UpdateLastPlayTime::`vftable;
      vfptr = v14->Expression::IMemberMap::vfptr;
      v24 = 1;
      vfptr[1].FindWithOldPath(v14, (const char *)&v23);
      if ( sSyncBlendDirection )
      {
        v26 = 1;
        v25 = &BlendDirectionNode_GetBlendDirection::`vftable;
        UFG::qMemSet(dest, 0, 0x20u);
        p_mNext->Expression::IMemberMap::vfptr[1].FindWithOldPath(p_mNext, (const char *)&v25);
        v28 = &BlendDirectionNode_SetBlendDirection::`vftable;
        v29 = 1;
        UFG::qMemCopy(v30, dest, 0x20u);
        v14->Expression::IMemberMap::vfptr[1].FindWithOldPath(v14, (const char *)&v28);
      }
      v20 = &FirstAnimationNode::`vftable;
      v16 = p_mNext->Expression::IMemberMap::vfptr;
      v21 = 1;
      v22 = 0i64;
      v16[1].FindWithOldPath(p_mNext, (const char *)&v20);
      if ( v22 )
      {
        if ( (*(float (__fastcall **)(__int64))(*(_QWORD *)v22 + 304i64))(v22) == 0.0 )
        {
LABEL_23:
          ((void (__fastcall *)(PoseNode *, __int64, bool))v14->Expression::IMemberMap::vfptr[1].GetClassNameUID)(
            v14,
            v17,
            updateAnimation);
          goto LABEL_24;
        }
        v18 = (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v22 + 376i64))(v22) == 0;
      }
      else
      {
        v18 = !sUpdateFromSync;
      }
      if ( !v18 )
        goto LABEL_23;
    }
  }
LABEL_24:
  this->BlendNode::PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[5].GetClassNameUID(this);
  return BlendNode::updateOperationPost(this);
}

// File Line: 2523
// RVA: 0x3B8CF0
void __fastcall BlendPhaseNode::updateOperation(BlendPhaseNode *this)
{
  UFG::qNode<PoseNode,PoseNode> *mNext; // rax
  UFG::qNode<PoseNode,PoseNode> *v2; // r8
  int v3; // edx
  PoseNode *p_mNext; // rax
  int v5; // r9d
  PoseNode *v6; // r8

  if ( !this->mHoldPose && !this->mPauseBlend )
  {
    mNext = this->mChildren.mNode.mNext;
    v2 = mNext->mNext;
    v3 = (int)mNext[1].mNext;
    p_mNext = (PoseNode *)&mNext[-3].mNext;
    v5 = (int)v2[1].mNext;
    v6 = (PoseNode *)&v2[-3].mNext;
    if ( v3 > v5 )
    {
      PhaseMatch(v6, p_mNext, 1.0 - this->mBlendParam);
    }
    else if ( v3 >= v5 )
    {
      PhaseMatch(p_mNext, v6, this->mBlendParam);
    }
    else
    {
      PhaseMatch(p_mNext, v6, 0.0);
    }
  }
}

// File Line: 2569
// RVA: 0x3A8CE0
void __fastcall BlendPhaseNode::GetExtractedDeltaReferenceFrame(
        BlendPhaseNode *this,
        float deltaTime,
        hkQsTransformf *deltaMotionOut)
{
  __int64 v3; // rdx
  UFG::qNode<PoseNode,PoseNode> *mNext; // rcx
  UFG::qNode<PoseNode,PoseNode> *v7; // rbx
  __int64 v8; // rdx
  Weightset *mWeightSet; // rax
  float *mOffset; // rcx
  hkQuaternionf v11; // xmm1
  hkVector4f v12; // xmm0
  __m128 v13; // xmm4
  __m128 v14; // xmm0
  hkVector4f v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm0
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // [rsp+20h] [rbp-78h] BYREF
  __m128 v23; // [rsp+30h] [rbp-68h]
  __m128 v24; // [rsp+40h] [rbp-58h]
  __m128 v25; // [rsp+50h] [rbp-48h] BYREF
  __m128 v26; // [rsp+60h] [rbp-38h]
  __m128 v27; // [rsp+70h] [rbp-28h]

  mNext = this->mChildren.mNode.mNext;
  v7 = mNext->mNext;
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, __int64, __m128 *))mNext[-3].mNext[8].mPrev)(
    &mNext[-3].mNext,
    v3,
    &v22);
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, __int64, __m128 *))v7[-3].mNext[8].mPrev)(
    &v7[-3].mNext,
    v8,
    &v25);
  mWeightSet = this->mWeightSet;
  if ( !mWeightSet )
    goto LABEL_6;
  mOffset = (float *)mWeightSet->mRawWeightSet.mOffset;
  if ( mOffset )
    mOffset = (float *)((char *)mOffset + (_QWORD)mWeightSet + 48);
  if ( *mOffset <= 0.0 )
  {
    v11.m_vec.m_quad = v23;
    deltaMotionOut->m_translation.m_quad = v22;
    v12.m_quad = v24;
    deltaMotionOut->m_rotation = (hkQuaternionf)v11.m_vec.m_quad;
    deltaMotionOut->m_scale = (hkVector4f)v12.m_quad;
  }
  else
  {
LABEL_6:
    v13 = _mm_shuffle_ps((__m128)LODWORD(this->mBlendParam), (__m128)LODWORD(this->mBlendParam), 0);
    v14 = _mm_mul_ps(v26, v23);
    v15.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v25, v22), v13), v22);
    deltaMotionOut->m_scale.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v27, v24), v13), v24);
    v16 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 78), v14);
    deltaMotionOut->m_translation = (hkVector4f)v15.m_quad;
    v17 = _mm_add_ps(
            _mm_mul_ps(
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32(
                            (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 177), v16), (__m128)0i64),
                            0x1Fu),
                          0x1Fu),
                v13),
              v26),
            _mm_mul_ps(_mm_sub_ps(query.m_quad, v13), v23));
    v18 = _mm_mul_ps(v17, v17);
    v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
    v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
    v21 = _mm_rsqrt_ps(v20);
    deltaMotionOut->m_rotation.m_vec.m_quad = _mm_mul_ps(
                                                v17,
                                                _mm_mul_ps(
                                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                                                  _mm_mul_ps(*(__m128 *)_xmm, v21)));
  }
}

// File Line: 2600
// RVA: 0x3AB200
__int64 __fastcall BlendPhaseNode::IsFinished(BlendPhaseNode *this, float inTimeDelta)
{
  return ((__int64 (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **))this->mChildren.mNode.mNext[-3].mNext[9].mPrev)(&this->mChildren.mNode.mNext[-3].mNext);
}

// File Line: 2605
// RVA: 0x3AA760
void __fastcall BlendPhaseNode::HoldLastFrame(BlendPhaseNode *this)
{
  UFG::qNode<PoseNode,PoseNode> *mNext; // rcx
  UFG::qNode<PoseNode,PoseNode> *v3; // rbx

  mNext = this->mChildren.mNode.mNext;
  v3 = mNext->mNext;
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **))mNext[-3].mNext[9].mNext)(&mNext[-3].mNext);
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **))v3[-3].mNext[9].mNext)(&v3[-3].mNext);
  this->mHoldPose = 1;
}

// File Line: 2616
// RVA: 0x3AC550
void __fastcall BlendPhaseNode::Pause(BlendPhaseNode *this)
{
  UFG::qNode<PoseNode,PoseNode> *mNext; // rcx
  UFG::qNode<PoseNode,PoseNode> *v3; // rbx

  mNext = this->mChildren.mNode.mNext;
  v3 = mNext->mNext;
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **))mNext[-3].mNext[10].mNext)(&mNext[-3].mNext);
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **))v3[-3].mNext[10].mNext)(&v3[-3].mNext);
  this->mHoldPose = 1;
}

// File Line: 2627
// RVA: 0x3AE460
void __fastcall BlendPhaseNode::Resume(BlendPhaseNode *this)
{
  UFG::qNode<PoseNode,PoseNode> *mNext; // rcx
  UFG::qNode<PoseNode,PoseNode> *v3; // rbx

  mNext = this->mChildren.mNode.mNext;
  v3 = mNext->mNext;
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **))mNext[-3].mNext[11].mPrev)(&mNext[-3].mNext);
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **))v3[-3].mNext[11].mPrev)(&v3[-3].mNext);
  this->mHoldPose = 0;
}

// File Line: 2638
// RVA: 0x3A8270
void __fastcall BlendPhaseNode::GetDuration(BlendPhaseNode *this)
{
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **))this->mChildren.mNode.mNext[-3].mNext[14].mPrev)(&this->mChildren.mNode.mNext[-3].mNext);
}

// File Line: 2645
// RVA: 0x3A9460
void __fastcall BlendPhaseNode::GetPhase(BlendPhaseNode *this, float futureTimeDelta)
{
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **))this->mChildren.mNode.mNext[-3].mNext[12].mPrev)(&this->mChildren.mNode.mNext[-3].mNext);
}

// File Line: 2652
// RVA: 0x3A9480
void __fastcall BlendPhaseNode::GetPhase(BlendPhaseNode *this, MotionPhase2 *motionPhase)
{
  void **v3; // [rsp+28h] [rbp-40h] BYREF
  char v4; // [rsp+30h] [rbp-38h]
  void **v5; // [rsp+38h] [rbp-30h]
  Expression::IMemberMap *v6; // [rsp+40h] [rbp-28h]
  __int64 v7; // [rsp+48h] [rbp-20h]
  __int64 v8; // [rsp+50h] [rbp-18h]

  v4 = 1;
  v3 = &PoseNode_GetPhase::`vftable;
  v6 = 0i64;
  v5 = &MotionPhase2::`vftable;
  v7 = 0i64;
  v8 = 0i64;
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, void ***))this->mChildren.mNode.mNext[-3].mNext[5].mPrev)(
    &this->mChildren.mNode.mNext[-3].mNext,
    &v3);
  motionPhase->mResourceOwner = v6;
  *(_QWORD *)&motionPhase->mPhaseMark.mValue = v7;
  *(_QWORD *)&motionPhase->mPhase = v8;
}

// File Line: 2702
// RVA: 0x3B91E0
void __fastcall AnimationNode::verifyBindAnimation(AnimationNode *this)
{
  unsigned int mUID; // edx
  SkeletalAnimationHandle *p_mSkeletalAnimationHandle; // rcx
  SkeletalAnimation *m_pPointer; // rax
  __int64 mOffset; // rcx
  UFG::qSymbolUC *v6; // rdx
  UFG::eAnimationPriorityEnum v7; // r8d

  if ( !this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer )
  {
    mUID = this->mName.mUID;
    if ( mUID != UFG::gNullQSymbolUC.mUID )
    {
      if ( this->mSkeletalAnimationHandle.m_SkeletalAnimationName.mUID == UFG::gNullQSymbolUC.mUID )
      {
        p_mSkeletalAnimationHandle = &this->mSkeletalAnimationHandle;
        p_mSkeletalAnimationHandle->m_SkeletalAnimationName.mUID = mUID;
LABEL_6:
        SkeletalAnimationHandle::Init(p_mSkeletalAnimationHandle);
        goto LABEL_7;
      }
      p_mSkeletalAnimationHandle = &this->mSkeletalAnimationHandle;
      if ( !p_mSkeletalAnimationHandle->m_SkeletalAnimation.m_pPointer )
        goto LABEL_6;
    }
  }
LABEL_7:
  if ( this->mAnimationGroupHandle.m_AnimationGroupSymbol.mUID == -1 )
  {
    m_pPointer = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
    if ( m_pPointer )
    {
      mOffset = m_pPointer->m_pAnimationGroup.mOffset;
      if ( mOffset )
      {
        v6 = (UFG::qSymbolUC *)((char *)&m_pPointer->m_pAnimationGroup + mOffset);
        if ( v6 )
        {
          v7 = eANIM_PRIORITY_ANIMATION_PLAYING;
          if ( gPLayingRemoteDebug )
            v7 = eANIM_PRIORITY_PLAYER;
          AnimationGroupHandle::Init(&this->mAnimationGroupHandle, v6 + 0x2B, v7);
          AnimationGroupHandle::Bind(&this->mAnimationGroupHandle);
        }
      }
    }
  }
}

// File Line: 2783
// RVA: 0x3B7AB0
// local variable allocation has failed, the output may be wrong!
float __fastcall getfutureTimeUtil(
        float currentTime,
        double timeDelta,
        float playRate,
        const float playTimeStart,
        float playTimeFinal,
        int *loops)
{
  __int128 v6; // xmm4
  __int128 v7; // xmm0
  __int128 v8; // xmm4
  float i; // xmm0_4

  v6 = *(_OWORD *)&timeDelta;
  if ( COERCE_FLOAT(LODWORD(playRate) & _xmm) > 1000.0 && playRate > 0.0 && playRate >= 1000.0 )
    playRate = FLOAT_1000_0;
  if ( (float)(playTimeFinal - playTimeStart) > 0.000099999997 )
  {
    *(float *)&v6 = (float)(*(float *)&timeDelta * playRate) + currentTime;
    if ( *(float *)&v6 <= currentTime )
    {
      if ( *(float *)&v6 < currentTime )
      {
        for ( i = playTimeStart - *(float *)&v6;
              (float)(playTimeStart - *(float *)&v6) > 0.0;
              i = playTimeStart - *(float *)&v6 )
        {
          --*loops;
          *(float *)&v6 = playTimeFinal - i;
        }
      }
    }
    else
    {
      v7 = v6;
      *(float *)&v7 = *(float *)&v6 - playTimeFinal;
      if ( (float)(*(float *)&v6 - playTimeFinal) > 0.0 )
      {
        do
        {
          ++*loops;
          v8 = v7;
          *(float *)&v8 = *(float *)&v7 + playTimeStart;
          v7 = v8;
          *(float *)&v7 = *(float *)&v8 - playTimeFinal;
        }
        while ( (float)(*(float *)&v8 - playTimeFinal) > 0.0 );
        return *(float *)&v8;
      }
    }
    return *(float *)&v6;
  }
  return currentTime;
}

// File Line: 2834
// RVA: 0x3B7110
float __fastcall AnimationNode::getEndTimePlay(AnimationNode *this)
{
  float v1; // xmm6_4
  SkeletalAnimation *m_pPointer; // rcx
  float Duration; // xmm0_4
  float result; // xmm0_4

  v1 = sTposeAnimPlayDuration;
  m_pPointer = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  if ( m_pPointer )
  {
    Duration = SkeletalAnimation::GetDuration(m_pPointer);
    if ( Duration > 0.0 )
      v1 = Duration;
  }
  if ( v1 <= 0.0 )
    return 0.0;
  result = this->mPlayEndTime;
  if ( result < 0.0 || result > v1 )
    return v1;
  return result;
}

// File Line: 2868
// RVA: 0x3B79D0
float __fastcall AnimationNode::getfutureTimeFast(AnimationNode *this, float timeDelta, float duration, int *loops)
{
  float mLocalTime; // xmm7_4
  float mPlayRate; // xmm6_4
  float playTimeFinal; // xmm0_4

  *loops = 0;
  mLocalTime = this->mLocalTime;
  if ( ((unsigned __int8 (*)(void))this->PoseNode::Expression::IMemberMap::vfptr[4].ResolveReferences)() )
    mPlayRate = 0.0;
  else
    mPlayRate = this->mPlayRate;
  if ( duration <= 0.0 )
    return mLocalTime + (float)(mPlayRate * timeDelta);
  playTimeFinal = AnimationNode::getEndTimePlay(this);
  return getfutureTimeUtil(this->mLocalTime, timeDelta, mPlayRate, 0.0, playTimeFinal, loops);
}

// File Line: 2889
// RVA: 0x3B0890
char __fastcall AnimationNode::Update(AnimationNode *this, float timeDelta, bool updateAnimation)
{
  SkeletalAnimation *m_pPointer; // rcx
  float v5; // xmm9_4
  float Duration; // xmm0_4
  SkeletalAnimation *v7; // rcx
  float mLocalTime; // xmm10_4
  float v9; // xmm8_4
  float v10; // xmm7_4
  float mPlayStartTime; // xmm11_4
  float v12; // xmm0_4
  float mPlayEndTime; // xmm0_4
  int *p_mLoops; // rdi
  float v15; // xmm0_4
  unsigned __int8 mValue; // cl
  int v17; // edx
  float v18; // xmm0_4
  Expression::IMemberMapVtbl *vfptr; // rax

  if ( updateAnimation )
  {
    AnimationNode::verifyBindAnimation(this);
    if ( !this->mPause )
    {
      m_pPointer = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
      v5 = sTposeAnimPlayDuration;
      if ( m_pPointer )
      {
        Duration = SkeletalAnimation::GetDuration(m_pPointer);
        if ( Duration > 0.0 )
          v5 = Duration;
      }
      if ( v5 > 0.0 )
      {
        v7 = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
        mLocalTime = this->mLocalTime;
        v9 = sTposeAnimPlayDuration;
        v10 = 0.0;
        mPlayStartTime = this->mPlayStartTime;
        if ( v7 )
        {
          v12 = SkeletalAnimation::GetDuration(v7);
          if ( v12 > 0.0 )
            v9 = v12;
        }
        if ( v9 > 0.0 )
        {
          mPlayEndTime = this->mPlayEndTime;
          v10 = v9;
          if ( mPlayEndTime >= 0.0 && mPlayEndTime <= v9 )
            v10 = this->mPlayEndTime;
        }
        p_mLoops = &this->mLoops;
        v15 = AnimationNode::getfutureTimeFast(this, timeDelta, v5, &this->mLoops);
        mValue = this->mPlayMode.mValue;
        if ( mValue > 7u || (v17 = 165, !_bittest(&v17, mValue)) )
        {
          this->mLocalTime = v15;
LABEL_31:
          if ( mLocalTime == this->mLocalTime )
          {
            AnimationNode::endAllTracks(this);
          }
          else
          {
            getPhase(this, &this->mMotionPhase);
            if ( mLocalTime > this->mLocalTime )
            {
              mLocalTime = 0.0;
              AnimationNode::endAllTracks(this);
            }
            if ( this->mPlayTracks )
            {
              AnimationNode::startTracks(this, mLocalTime, this->mLocalTime);
              AnimationNode::updateTracks(this, timeDelta, this->mLocalTime);
            }
          }
          return 1;
        }
        if ( *p_mLoops <= 0 )
        {
          if ( *p_mLoops >= 0 )
          {
            this->mLocalTime = v15;
LABEL_23:
            v18 = this->mLocalTime;
            if ( v18 > mPlayStartTime )
            {
              if ( v18 >= v10 )
                this->mLocalTime = v10;
            }
            else
            {
              this->mLocalTime = mPlayStartTime;
            }
            if ( this->mPlayMode.mValue == 2 && *p_mLoops > 0 )
            {
              vfptr = this->PoseNode::Expression::IMemberMap::vfptr;
              this->mLocalTime = v10;
              *p_mLoops = 0;
              ((void (__fastcall *)(AnimationNode *))vfptr[2].__vecDelDtor)(this);
            }
            goto LABEL_31;
          }
          this->mLocalTime = mPlayStartTime;
        }
        else
        {
          this->mLocalTime = v10;
        }
        *p_mLoops = 0;
        if ( mValue != 7 )
          ((void (__fastcall *)(AnimationNode *))this->PoseNode::Expression::IMemberMap::vfptr[2].__vecDelDtor)(this);
        goto LABEL_23;
      }
    }
  }
  return 1;
}

// File Line: 3204
// RVA: 0x3B8240
void __fastcall AnimationNode::startTracks(AnimationNode *this, float currentTime, float newTime)
{
  SkeletalAnimation *m_pPointer; // rcx
  __int64 v5; // rax
  __int64 v6; // rsi
  __int64 v7; // rdi
  __int64 v8; // r14
  float *v9; // rcx
  float v10; // xmm0_4
  __int64 v11; // rbx
  UFG::qNode<ITask,ITask> *mPrev; // rax

  m_pPointer = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  if ( m_pPointer )
  {
    v5 = ((__int64 (*)(void))m_pPointer->Expression::IMemberMap::vfptr[1].CreateClone)();
    v6 = v5;
    if ( v5 )
    {
      v7 = 0i64;
      v8 = v5 + *(_QWORD *)(v5 + 24) + 24i64;
      if ( (*(_DWORD *)(v5 + 16) & 0x7FFFFFFF) != 0 )
      {
        do
        {
          v9 = (float *)(*(_QWORD *)(v8 + 8 * v7) + v8 + 8 * v7);
          v10 = v9[12];
          if ( currentTime <= v10 && v10 < newTime )
          {
            v11 = (*(__int64 (__fastcall **)(float *, const char *))(*(_QWORD *)v9 + 80i64))(
                    v9,
                    "AnimationNode::startTracks()");
            (*(void (__fastcall **)(__int64, ActionContext *))(*(_QWORD *)v11 + 8i64))(v11, this->mpContext);
            mPrev = this->m_RunningTasks.mNode.mPrev;
            mPrev->mNext = (UFG::qNode<ITask,ITask> *)(v11 + 8);
            *(_QWORD *)(v11 + 8) = mPrev;
            *(_QWORD *)(v11 + 16) = &this->m_RunningTasks;
            this->m_RunningTasks.mNode.mPrev = (UFG::qNode<ITask,ITask> *)(v11 + 8);
          }
          v7 = (unsigned int)(v7 + 1);
        }
        while ( (unsigned int)v7 < (*(_DWORD *)(v6 + 16) & 0x7FFFFFFFu) );
      }
    }
  }
}

// File Line: 3226
// RVA: 0x3B90D0
void __fastcall AnimationNode::updateTracks(AnimationNode *this, float timeDelta, float newTime)
{
  ActionContext **p_mpContext; // rbp
  ActionContext **p_mNext; // rbx
  bool v5; // di
  float v6; // xmm6_4
  __int64 v7; // rsi
  ActionContext *v8; // rdx
  ActionContext *v9; // rax

  p_mpContext = &this->mpContext;
  p_mNext = (ActionContext **)&this->m_RunningTasks.mNode.mNext[-1].mNext;
  v5 = p_mNext == &this->mpContext;
  if ( this->m_RunningTasks.mNode.mNext != (UFG::qNode<ITask,ITask> *)8 )
  {
    do
    {
      if ( v5 )
        break;
      v6 = *((float *)&p_mNext[3]->mDebugBreak + 1);
      if ( ((unsigned __int8 (__fastcall *)(ActionContext **))(*p_mNext)->mSimObject.m_pPointer)(p_mNext)
        && (v6 < 0.0 || newTime < v6) )
      {
        p_mNext = (ActionContext **)&p_mNext[2][-1].mProbabilitys[9];
        v5 = p_mNext == p_mpContext;
      }
      else
      {
        ((void (__fastcall *)(ActionContext **))(*p_mNext)->m_OpeningBranch)(p_mNext);
        v7 = (__int64)&p_mNext[2][-1].mProbabilitys[9];
        v5 = p_mNext[2] == (ActionContext *)8 || (ActionContext **)v7 == p_mpContext;
        v8 = p_mNext[1];
        v9 = p_mNext[2];
        v8->mSimObject.mNext = &v9->mSimObject;
        v9->mSimObject.mPrev = &v8->mSimObject;
        p_mNext[1] = (ActionContext *)(p_mNext + 1);
        p_mNext[2] = (ActionContext *)(p_mNext + 1);
        ((void (__fastcall *)(ActionContext **, __int64))(*p_mNext)->mSimObject.mPrev)(p_mNext, 1i64);
        p_mNext = (ActionContext **)v7;
      }
    }
    while ( p_mNext );
  }
}

// File Line: 3271
// RVA: 0x3B6A00
void __fastcall AnimationNode::endAllTracks(AnimationNode *this)
{
  ActionContext **p_mpContext; // rsi
  UFG::qNode<ITask,ITask> *mNext; // rbx
  UFG::qNode<ITask,ITask> *mPrev; // rdx
  UFG::qNode<ITask,ITask> *v5; // rax

  p_mpContext = &this->mpContext;
  while ( (ActionContext **)&this->m_RunningTasks.mNode.mNext[-1].mNext != p_mpContext )
  {
    mNext = this->m_RunningTasks.mNode.mNext;
    ((void (__fastcall *)(UFG::qNode<ITask,ITask> **))mNext[-1].mNext[1].mNext)(&mNext[-1].mNext);
    mPrev = mNext->mPrev;
    v5 = mNext->mNext;
    mPrev->mNext = v5;
    v5->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    ((void (__fastcall *)(UFG::qNode<ITask,ITask> **, __int64))mNext[-1].mNext->mPrev)(&mNext[-1].mNext, 1i64);
  }
}

// File Line: 3314
// RVA: 0x3B9440
AnimationNode::writeDebugDisplayToString

// File Line: 3416
// RVA: 0x3A8870
void __fastcall AnimationNode::GetExtractedDeltaReferenceFrame(
        AnimationNode *this,
        float fromTime,
        float toTime,
        hkQsTransformf *deltaMotionOut)
{
  SkeletalAnimation *m_pPointer; // rdx
  UFG::qResourceData *mData; // rax
  unsigned int v7; // ebx
  UFG::qBaseNodeRB *v8; // rax
  SkeletalAnimation *m_pFallbackAnimation; // rcx
  UFG::qResourceData *v10; // rax
  __int64 v11; // rsi
  float v12; // xmm7_4
  __int64 v13; // rdx
  __int64 v14; // r8
  float i; // xmm6_4

  m_pPointer = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  if ( !m_pPointer )
  {
    deltaMotionOut->m_translation = 0i64;
    deltaMotionOut->m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
    deltaMotionOut->m_scale = (hkVector4f)query.m_quad;
    return;
  }
  mData = m_pPointer->m_AnimationResourceHandle.mData;
  v7 = 0;
  if ( mData )
  {
    v8 = mData[1].mNode.mChild[0];
    if ( v8 )
      goto LABEL_11;
  }
  else
  {
    v8 = 0i64;
  }
  m_pFallbackAnimation = m_pPointer->m_pFallbackAnimation;
  if ( m_pFallbackAnimation )
  {
    v10 = m_pFallbackAnimation->m_AnimationResourceHandle.mData;
    if ( !v10 )
    {
LABEL_15:
      deltaMotionOut->m_translation = 0i64;
      deltaMotionOut->m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
      deltaMotionOut->m_scale = (hkVector4f)query.m_quad;
      return;
    }
    v8 = v10[1].mNode.mChild[0];
  }
  if ( !v8 )
    goto LABEL_15;
LABEL_11:
  v11 = *(_QWORD *)&v8->mUID;
  if ( !*(_QWORD *)(v11 + 32) )
    goto LABEL_15;
  v12 = *(float *)(v11 + 20);
  for ( i = (float)(toTime - fromTime) + fmodf(fromTime, v12); i > v12; ++v7 )
    i = i - v12;
  (*(void (__fastcall **)(__int64, __int64, __int64, _QWORD, hkQsTransformf *, _DWORD, _DWORD))(*(_QWORD *)v11 + 112i64))(
    v11,
    v13,
    v14,
    v7,
    deltaMotionOut,
    0,
    0);
}

// File Line: 3453
// RVA: 0x3A86F0
void __fastcall AnimationNode::GetExtractedDeltaReferenceFrame(
        AnimationNode *this,
        float deltaTime,
        hkQsTransformf *deltaMotionOut)
{
  SkeletalAnimation *m_pPointer; // rax
  UFG::qResourceData *mData; // rdi
  SkeletalAnimation *m_pFallbackAnimation; // rcx
  UFG::qResourceData *v8; // rdi
  float mLoops; // xmm9_4
  __int64 v10; // rdx
  __int64 v11; // r8

  AnimationNode::verifyBindAnimation(this);
  m_pPointer = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  if ( !m_pPointer )
  {
    deltaMotionOut->m_translation = 0i64;
    deltaMotionOut->m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
    deltaMotionOut->m_scale = (hkVector4f)query.m_quad;
    return;
  }
  mData = m_pPointer->m_AnimationResourceHandle.mData;
  if ( !mData || (mData = (UFG::qResourceData *)mData[1].mNode.mChild[0]) == 0i64 )
  {
    m_pFallbackAnimation = m_pPointer->m_pFallbackAnimation;
    if ( m_pFallbackAnimation )
    {
      v8 = m_pFallbackAnimation->m_AnimationResourceHandle.mData;
      if ( !v8 )
        goto LABEL_11;
      mData = (UFG::qResourceData *)v8[1].mNode.mChild[0];
    }
    if ( !mData )
      goto LABEL_11;
  }
  if ( *(_QWORD *)(*(_QWORD *)&mData->mNode.mUID + 32i64) )
  {
    mLoops = (float)this->mLoops;
    this->PoseNode::Expression::IMemberMap::vfptr[4].ResolveReferences(this);
    (*(void (__fastcall **)(_QWORD, __int64, __int64, _QWORD, hkQsTransformf *, _DWORD, _DWORD))(**(_QWORD **)&mData->mNode.mUID
                                                                                               + 112i64))(
      *(_QWORD *)&mData->mNode.mUID,
      v10,
      v11,
      (unsigned int)(int)mLoops,
      deltaMotionOut,
      0,
      0);
    return;
  }
LABEL_11:
  deltaMotionOut->m_translation = 0i64;
  deltaMotionOut->m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  deltaMotionOut->m_scale = (hkVector4f)query.m_quad;
}

// File Line: 3543
// RVA: 0x3A83B0
void __fastcall AnimationNode::GetExtractedCurrentAbsoluteReferenceFrame(
        AnimationNode *this,
        hkQsTransformf *absMotionOut)
{
  SkeletalAnimation *m_pPointer; // rbx
  UFG::qResourceData *mData; // rdi
  SkeletalAnimation *m_pFallbackAnimation; // rax
  UFG::qResourceData *v7; // rdi
  __int64 v8; // r8
  __m128 v9; // xmm1
  __m128 v10; // xmm7
  __m128 v11; // xmm5
  __m128 v12; // xmm4
  __m128 v13; // xmm2
  hkQuaternionf v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm4
  __m128 v18; // xmm0
  __m128 v19; // xmm2
  __m128 v20; // xmm3
  __m128 v21; // xmm4
  __m128 v22; // xmm4
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  hkQsTransformf v27; // [rsp+40h] [rbp-108h] BYREF
  __m128 v28; // [rsp+70h] [rbp-D8h] BYREF
  __m128 v29; // [rsp+80h] [rbp-C8h]
  __m128 v30; // [rsp+90h] [rbp-B8h]
  UFG::qMatrix44 outMatrix; // [rsp+A0h] [rbp-A8h] BYREF
  hkTransformf transform; // [rsp+E0h] [rbp-68h] BYREF

  m_pPointer = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  if ( m_pPointer
    && SkeletalAnimation::GetAnimationRootOrigin(
         this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer,
         &outMatrix) )
  {
    mData = m_pPointer->m_AnimationResourceHandle.mData;
    if ( mData )
    {
      mData = (UFG::qResourceData *)mData[1].mNode.mChild[0];
      if ( mData )
        goto LABEL_15;
    }
    m_pFallbackAnimation = m_pPointer->m_pFallbackAnimation;
    if ( m_pFallbackAnimation )
    {
      v7 = m_pFallbackAnimation->m_AnimationResourceHandle.mData;
      if ( !v7 )
        return;
      mData = (UFG::qResourceData *)v7[1].mNode.mChild[0];
    }
    if ( mData )
    {
LABEL_15:
      if ( *(_QWORD *)(*(_QWORD *)&mData->mNode.mUID + 32i64) )
      {
        hkTransformf::set4x4ColumnMajor(&transform, &outMatrix.v0.x);
        hkQsTransformf::setFromTransformNoScale(&v27, &transform);
        if ( this->mPoseOnFrameBoundaries )
        {
          (*(void (__fastcall **)(_QWORD))(**(_QWORD **)&mData->mNode.mUID + 64i64))(*(_QWORD *)&mData->mNode.mUID);
          (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)&mData->mNode.mUID + 64i64))(*(_QWORD *)&mData->mNode.mUID);
        }
        (*(void (__fastcall **)(_QWORD, __m128 *, __int64, _QWORD, __m128 *, _DWORD, _DWORD))(**(_QWORD **)&mData->mNode.mUID
                                                                                            + 112i64))(
          *(_QWORD *)&mData->mNode.mUID,
          &v28,
          v8,
          0i64,
          &v28,
          0,
          0);
        v9 = _mm_mul_ps(v28, v27.m_rotation.m_vec.m_quad);
        v10 = _mm_shuffle_ps(v27.m_rotation.m_vec.m_quad, v27.m_rotation.m_vec.m_quad, 255);
        v11 = _mm_shuffle_ps(v27.m_rotation.m_vec.m_quad, v27.m_rotation.m_vec.m_quad, 201);
        v12 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v27.m_rotation.m_vec.m_quad), _mm_mul_ps(v28, v11));
        v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
        v14.m_vec.m_quad = (__m128)v27.m_rotation;
        v15 = v29;
        v16 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(v13, v27.m_rotation.m_vec.m_quad),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v10, v10), (__m128)xmmword_141A711B0), v28)),
                _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v10));
        v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v27.m_rotation.m_vec.m_quad), _mm_mul_ps(v29, v11));
        absMotionOut->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v16, v16), v27.m_translation.m_quad);
        v18 = _mm_mul_ps(v15, v10);
        v19 = _mm_shuffle_ps(v15, v15, 255);
        v20 = _mm_mul_ps(v15, v14.m_vec.m_quad);
        v21 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 201), v18), _mm_mul_ps(v14.m_vec.m_quad, v19));
        v22 = _mm_shuffle_ps(
                v21,
                _mm_unpackhi_ps(
                  v21,
                  _mm_sub_ps(
                    _mm_mul_ps(v19, v10),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                      _mm_shuffle_ps(v20, v20, 170)))),
                196);
        v23 = _mm_mul_ps(v22, v22);
        absMotionOut->m_scale.m_quad = _mm_mul_ps(v30, v27.m_scale.m_quad);
        v24 = _mm_add_ps(_mm_shuffle_ps(v23, v23, 78), v23);
        v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 177), v24);
        v26 = _mm_rsqrt_ps(v25);
        absMotionOut->m_rotation.m_vec.m_quad = _mm_mul_ps(
                                                  _mm_mul_ps(
                                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                                                    _mm_mul_ps(*(__m128 *)_xmm, v26)),
                                                  v22);
      }
    }
  }
}

// File Line: 3591
// RVA: 0x3A9080
void __fastcall AnimationNode::GetPhase(AnimationNode *this, MotionPhase2 *motionPhase)
{
  if ( sReSyncPhase )
    getPhase(this, &this->mMotionPhase);
  motionPhase->mResourceOwner = this->mMotionPhase.mResourceOwner;
  motionPhase->mPhaseMark.mValue = this->mMotionPhase.mPhaseMark.mValue;
  motionPhase->mPhasePeriod = this->mMotionPhase.mPhasePeriod;
  motionPhase->mPhase = this->mMotionPhase.mPhase;
  motionPhase->mPhaseDuration = this->mMotionPhase.mPhaseDuration;
}

// File Line: 3600
// RVA: 0x3AF490
void __fastcall AnimationNode::SetPhase(AnimationNode *this, MotionPhase2 *motionPhase)
{
  SkeletalAnimation *m_pPointer; // rcx
  bool animCycles; // al
  MotionKey *track1; // [rsp+40h] [rbp+8h] BYREF
  MotionKey *track0; // [rsp+50h] [rbp+18h] BYREF

  m_pPointer = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  if ( m_pPointer )
  {
    animCycles = this->mPlayMode.mValue == 1;
    track0 = 0i64;
    track1 = 0i64;
    getBoundFootTracksAtMotionPhase(m_pPointer, motionPhase, &track0, &track1, animCycles);
    setLocalTimeFromPhaseTracks(this, motionPhase->mPhase, track0, track1);
  }
  this->mLoops = this->mLocalTime < this->mLastPlayTime
              && (this->mPlayRate > 0.0
               || !((unsigned __int8 (__fastcall *)(AnimationNode *))this->PoseNode::Expression::IMemberMap::vfptr[4].ResolveReferences)(this));
  getPhase(this, &this->mMotionPhase);
}

// File Line: 3621
// RVA: 0x3AF660
void __fastcall AnimationNode::SetRateWeight0(AnimationNode *this, float animLength0, float animLength1, float weight)
{
  if ( animLength1 > 0.0 && weight <= 1.0 )
    this->PoseNode::Expression::IMemberMap::vfptr[3].ResolveReferences(this);
}

// File Line: 3633
// RVA: 0x3AF720
void __fastcall AnimationNode::SetRateWeight1(AnimationNode *this, float animLength0, float animLength1, float weight)
{
  if ( animLength0 > 0.0 && weight <= 1.0 )
    this->PoseNode::Expression::IMemberMap::vfptr[3].ResolveReferences(this);
}

// File Line: 3645
// RVA: 0x3AB170
bool __fastcall AnimationNode::IsFinished(AnimationNode *this, float inTimeDelta)
{
  float Duration; // xmm6_4
  SkeletalAnimation *m_pPointer; // rcx
  int loops; // [rsp+50h] [rbp+8h] BYREF

  AnimationNode::verifyBindAnimation(this);
  Duration = 0.0;
  if ( this->mPlayRate == 0.0
    || ((unsigned __int8 (__fastcall *)(AnimationNode *))this->PoseNode::Expression::IMemberMap::vfptr[4].ResolveReferences)(this) )
  {
    return 1;
  }
  m_pPointer = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  loops = 0;
  if ( m_pPointer )
    Duration = SkeletalAnimation::GetDuration(m_pPointer);
  AnimationNode::getfutureTimeFast(this, inTimeDelta, Duration, &loops);
  return loops != 0;
}

// File Line: 3663
// RVA: 0x3A8F00
float __fastcall AnimationNode::GetPhase(AnimationNode *this, float futureTimeDelta)
{
  SkeletalAnimation *m_pPointer; // rdi
  float mLocalTime; // xmm1_4
  bool animCycles; // zf
  MotionKey *v7; // rsi
  MotionKey *v8; // rbp
  float v9; // xmm7_4
  float Duration; // xmm0_4
  float mTimeBegin; // xmm2_4
  float v12; // xmm6_4
  float v13; // xmm1_4
  SkeletalAnimation *v16; // rcx
  float v17; // xmm0_4
  float v18; // xmm0_4
  int loops; // [rsp+70h] [rbp+8h] BYREF
  MotionKey *v20; // [rsp+80h] [rbp+18h] BYREF
  MotionKey *v21; // [rsp+88h] [rbp+20h] BYREF

  m_pPointer = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  if ( !m_pPointer )
    return FLOAT_N1_0;
  mLocalTime = this->mLocalTime;
  animCycles = this->mPlayMode.mValue == 1;
  v20 = 0i64;
  v21 = 0i64;
  getBoundFootTracks(m_pPointer, mLocalTime, &v20, &v21, &loops, animCycles);
  v7 = v20;
  if ( v20 && (v8 = v21) != 0i64 )
  {
    v9 = this->mLocalTime;
    Duration = SkeletalAnimation::GetDuration(m_pPointer);
    mTimeBegin = v7->mTimeBegin;
    v12 = 0.0;
    v13 = v8->mTimeBegin - mTimeBegin;
    if ( v13 < 0.0 )
      v13 = (float)(Duration - mTimeBegin) + v8->mTimeBegin;
    if ( v13 > 0.000099999997 )
    {
      v12 = (float)(1.0 / v13) * v9;
      if ( v9 >= mTimeBegin && v9 <= Duration )
        v12 = (float)(v9 - mTimeBegin) * (float)(1.0 / v13);
    }
    if ( MotionKeyFootStepLeft::sClassNameUID != v7->vfptr->GetClassNameUID(v7) )
      v12 = v12 + 1.0;
    return v12 * 0.5;
  }
  else
  {
    v16 = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
    if ( v16 )
      v17 = SkeletalAnimation::GetDuration(v16);
    else
      v17 = 0.0;
    v18 = AnimationNode::getfutureTimeFast(this, futureTimeDelta, v17, &loops);
    return v18 / SkeletalAnimation::GetDuration(m_pPointer);
  }
}

// File Line: 3726
// RVA: 0x3AF3E0
void __fastcall AnimationNode::SetParametricPlayTime(AnimationNode *this, float parametric)
{
  SkeletalAnimation *m_pPointer; // rcx

  m_pPointer = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  if ( m_pPointer )
  {
    if ( parametric >= 0.0 )
    {
      SkeletalAnimation::GetDuration(m_pPointer);
      ((void (__fastcall *)(AnimationNode *))this->PoseNode::Expression::IMemberMap::vfptr[3].GetResourcePath)(this);
      this->PoseNode::Expression::IMemberMap::vfptr[3].ResolveReferences(this);
    }
  }
}

// File Line: 3758
// RVA: 0x3AF350
void __fastcall AnimationNode::SetLocalTime(AnimationNode *this, float localtime)
{
  bool v3; // cc
  float EndTimePlay; // xmm0_4
  char mValue; // al

  if ( localtime >= 0.0 )
  {
    v3 = this->mLastPlayTime >= 0.0;
    this->mLocalTime = localtime;
    if ( !v3 || this->mFirstPlay )
      this->mLastPlayTime = localtime;
    EndTimePlay = AnimationNode::getEndTimePlay(this);
    mValue = this->mPlayMode.mValue;
    if ( mValue == 1 || mValue == 6 )
    {
      this->mLocalTime = fmodf(localtime, EndTimePlay);
    }
    else if ( EndTimePlay < this->mLocalTime )
    {
      this->mLocalTime = EndTimePlay;
    }
  }
}

// File Line: 3789
// RVA: 0x3A81D0
double __fastcall AnimationNode::GetDuration(AnimationNode *this)
{
  SkeletalAnimation *m_pPointer; // rcx
  double result; // xmm0_8

  if ( this->mSkeletalAnimationHandle.m_SkeletalAnimationName.mUID != UFG::gNullQSymbolUC.mUID
    && (m_pPointer = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer) != 0i64 )
  {
    *(float *)&result = SkeletalAnimation::GetDuration(m_pPointer);
  }
  else
  {
    *(_QWORD *)&result = LODWORD(FLOAT_N1_0);
  }
  return result;
}

// File Line: 3855
// RVA: 0x3B6C80
float __fastcall AnimationNode::getAverageExtractedSpeed(AnimationNode *this)
{
  __int64 v2; // r8
  SkeletalAnimation *m_pPointer; // rcx
  UFG::qResourceData *mData; // rax
  SkeletalAnimation *m_pFallbackAnimation; // rdx
  UFG::qResourceData *v6; // rax
  _QWORD *v7; // rcx
  __m128 v8; // xmm1
  float result; // xmm0_4
  int v10[14]; // [rsp+40h] [rbp-38h] BYREF

  AnimationNode::verifyBindAnimation(this);
  m_pPointer = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  if ( !m_pPointer )
    return 0.0;
  mData = m_pPointer->m_AnimationResourceHandle.mData;
  if ( !mData || (mData = (UFG::qResourceData *)mData[1].mNode.mChild[0]) == 0i64 )
  {
    m_pFallbackAnimation = m_pPointer->m_pFallbackAnimation;
    if ( m_pFallbackAnimation )
    {
      v6 = m_pFallbackAnimation->m_AnimationResourceHandle.mData;
      if ( !v6 )
        return 0.0;
      mData = (UFG::qResourceData *)v6[1].mNode.mChild[0];
    }
    if ( !mData )
      return 0.0;
  }
  v7 = *(_QWORD **)&mData->mNode.mUID;
  if ( v7[4] )
  {
    (*(void (__fastcall **)(_QWORD *, int *, __int64, _QWORD, int *, _DWORD, _DWORD))(*v7 + 112i64))(
      v7,
      v10,
      v2,
      0i64,
      v10,
      0,
      0);
    v8 = (__m128)(unsigned int)v10[1];
    v8.m128_f32[0] = (float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(*(float *)v10 * *(float *)v10);
    LODWORD(result) = _mm_sqrt_ps(v8).m128_u32[0];
    return result;
  }
  return 0.0;
}

// File Line: 3888
// RVA: 0x3AF0E0
void __fastcall AnimationNode::SetDesiredExtractedMotionSpeed(AnimationNode *this, float extractedSpeed)
{
  if ( AnimationNode::getAverageExtractedSpeed(this) >= 0.001 )
    this->PoseNode::Expression::IMemberMap::vfptr[3].ResolveReferences(this);
}

// File Line: 3904
// RVA: 0x3B67C0
void __fastcall PoseNode::constructNetSequence(PoseNode *this, Creature *creature)
{
  if ( this->mNetPoseSequence < 0 )
  {
    ++creature->mNetPoseSequence;
    this->mNetPoseSequence = LOWORD(creature->mNetPoseSequence);
  }
}

// File Line: 3928
// RVA: 0x3B6780
void __fastcall BlendDirectionNode::constructNetSequence(BlendDirectionNode *this, Creature *creature)
{
  void **v3; // [rsp+20h] [rbp-28h] BYREF
  char v4; // [rsp+28h] [rbp-20h]
  unsigned int mNetPoseSequence; // [rsp+30h] [rbp-18h]

  v4 = 1;
  v3 = &ConstructNetSequence::`vftable;
  mNetPoseSequence = creature->mNetPoseSequence;
  this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[1].FindWithOldPath(this, (const char *)&v3);
  creature->mNetPoseSequence = mNetPoseSequence;
}

// File Line: 3941
// RVA: 0x3ABC40
char __fastcall PoseNode::NetSerialize(PoseNode *this, NetAnimationState *state, IActionTreeSerializer *creature)
{
  __int64 mEntryCount; // rcx
  NetAnimationState::AnimationEntry *v6; // rbx
  unsigned __int16 mNetPoseSequence; // ax

  mEntryCount = state->mEntryCount;
  if ( (int)mEntryCount >= 64 )
    return 0;
  state->mEntryCount = mEntryCount + 1;
  v6 = &state->mEntries[mEntryCount];
  UFG::qMemSet(v6, 0, 0x60u);
  if ( !v6 )
    return 0;
  v6->mPose.mType = 0;
  if ( this->mNetPoseSequence < 0 )
    this->Expression::IMemberMap::vfptr[3].Serialize(this, creature);
  mNetPoseSequence = this->mNetPoseSequence;
  v6->mPose.mLocalTime = 0.0;
  v6->mPose.mSequence = mNetPoseSequence;
  return 1;
}

// File Line: 3958
// RVA: 0x3AB9D0
char __fastcall AnimationNode::NetSerialize(
        AnimationNode *this,
        NetAnimationState *state,
        IActionTreeSerializer *creature)
{
  SkeletalAnimation *m_pPointer; // rsi
  __int64 mEntryCount; // rcx
  NetAnimationState::AnimationEntry *v7; // rdi

  m_pPointer = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  mEntryCount = state->mEntryCount;
  if ( (int)mEntryCount >= 64 )
    return 0;
  state->mEntryCount = mEntryCount + 1;
  v7 = &state->mEntries[mEntryCount];
  UFG::qMemSet(v7, 0, 0x60u);
  if ( !v7 )
    return 0;
  v7->mPose.mType = 1;
  if ( this->mNetPoseSequence < 0 )
    this->PoseNode::Expression::IMemberMap::vfptr[3].Serialize(this, creature);
  v7->mPose.mSequence = this->mNetPoseSequence;
  v7->mPose.mLocalTime = this->mLocalTime;
  if ( m_pPointer )
    v7->mAnimation.mAnimationUID = m_pPointer->mNameSymbol.mUID;
  else
    v7->mAnimation.mAnimationUID = 0;
  v7->mBlendDirection.mChildCount = (unsigned __int8)this->mPlayMode.mValue;
  return 1;
}

// File Line: 3979
// RVA: 0x3ABCE0
char __fastcall PoseNodeParent::NetSerialize(
        PoseNodeParent *this,
        NetAnimationState *state,
        IActionTreeSerializer *creature)
{
  if ( (int *)&this->mChildren.mNode.mNext[-3].mNext == &this->mNetPoseSequence )
    return PoseNode::NetSerialize(this, state, creature);
  else
    return ((__int64 (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, NetAnimationState *, IActionTreeSerializer *))this->mChildren.mNode.mNext[-3].mNext[16].mPrev)(
             &this->mChildren.mNode.mNext[-3].mNext,
             state,
             creature);
}

// File Line: 3997
// RVA: 0x3ABD10
char __fastcall BlendNode::NetSerializeBlend(
        BlendNode *this,
        PoseNodeType type,
        NetAnimationState *state,
        IActionTreeSerializer *creature,
        bool holdPose)
{
  char v5; // si
  int *p_mNext; // rax
  int *p_mNetPoseSequence; // rcx
  unsigned __int16 v11; // r15
  int v12; // r11d
  __int64 v13; // r10
  __int64 mEntryCount; // rdx
  NetAnimationState::AnimationEntry *v15; // rdi
  Weightset *mWeightSet; // rax
  unsigned int mUID; // eax
  Weightset *mWeightSetMask; // rax
  unsigned int v19; // ecx

  v5 = 0;
  p_mNext = (int *)&this->mChildren.mNode.mNext[-3].mNext;
  p_mNetPoseSequence = &this->mNetPoseSequence;
  v11 = type;
  v12 = 0;
  v13 = (__int64)p_mNext;
  if ( p_mNext == p_mNetPoseSequence )
    return 0;
  do
  {
    ++v12;
    v13 = *(_QWORD *)(v13 + 48) - 40i64;
  }
  while ( (int *)v13 != p_mNetPoseSequence );
  if ( v12 != 2 )
  {
    for ( ; p_mNext != p_mNetPoseSequence; p_mNext = (int *)(*((_QWORD *)p_mNext + 6) - 40i64) )
      ;
    return 0;
  }
  mEntryCount = state->mEntryCount;
  if ( (int)mEntryCount >= 64 )
    return 0;
  state->mEntryCount = mEntryCount + 1;
  v15 = &state->mEntries[mEntryCount];
  UFG::qMemSet(v15, 0, 0x60u);
  if ( !v15 )
    return 0;
  v15->mPose.mType = v11;
  if ( this->mNetPoseSequence < 0 )
    this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[3].Serialize(this, creature);
  v15->mPose.mSequence = this->mNetPoseSequence;
  v15->mPose.mLocalTime = this->mLocalTime;
  v15->mAnimation.mAnimationUID = LODWORD(this->mBlendParam);
  v15->mBlendDirection.mChildCount = LODWORD(this->mBlendRate);
  mWeightSet = this->mWeightSet;
  if ( mWeightSet )
    mUID = mWeightSet->mName.mUID;
  else
    mUID = 0;
  v15->mBlend.mWeightSetUID = mUID;
  mWeightSetMask = this->mWeightSetMask;
  if ( mWeightSetMask )
    v19 = mWeightSetMask->mName.mUID;
  else
    v19 = 0;
  v15->mBlend.mWeightSetMaskUID = v19;
  v15->mBlend.mStarted = this->mStarted != 0;
  v15->mBlend.mSyncOnStart = this->mSyncOnStart != 0;
  v15->mBlend.mPauseBlend = this->mPauseBlend != 0;
  v15->mBlend.mPauseBlend = this->mPauseBlend != 0;
  v15->mBlend.mKeepBlend = this->mKeepBlend != 0;
  v15->mBlend.mHoldPose = holdPose;
  if ( ((__int64 (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, NetAnimationState *, IActionTreeSerializer *))this->mChildren.mNode.mNext[-3].mNext[16].mPrev)(
         &this->mChildren.mNode.mNext[-3].mNext,
         state,
         creature) )
  {
    if ( ((__int64 (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, NetAnimationState *, IActionTreeSerializer *))this->mChildren.mNode.PoseNodeParent::mPrev[-3].mNext[16].mPrev)(
           &this->mChildren.mNode.PoseNodeParent::mPrev[-3].mNext,
           state,
           creature) )
    {
      return 1;
    }
  }
  return v5;
}

// File Line: 4047
// RVA: 0x3ABBD0
bool __fastcall BlendNode::NetSerialize(BlendNode *this, NetAnimationState *state, Creature *creature)
{
  return BlendNode::NetSerializeBlend(this, PNT_BLEND, state, creature, 0);
}

// File Line: 4070
// RVA: 0x3ABAC0
char __fastcall BlendDirectionNode::NetSerialize(
        BlendDirectionNode *this,
        NetAnimationState *state,
        IActionTreeSerializer *creature)
{
  __int64 mEntryCount; // rcx
  NetAnimationState::AnimationEntry *v7; // rdi
  int *p_mNetPoseSequence; // r14
  char v9; // di
  int *i; // rbx
  char v11; // al

  mEntryCount = state->mEntryCount;
  if ( (int)mEntryCount >= 64 )
    return 0;
  state->mEntryCount = mEntryCount + 1;
  v7 = &state->mEntries[mEntryCount];
  UFG::qMemSet(v7, 0, 0x60u);
  if ( !v7 )
    return 0;
  p_mNetPoseSequence = &this->mNetPoseSequence;
  v7->mPose.mType = 3;
  if ( this->mNetPoseSequence < 0 )
    this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[3].Serialize(this, creature);
  v7->mPose.mSequence = *(_WORD *)p_mNetPoseSequence;
  v7->mPose.mLocalTime = this->mLocalTime;
  v7->mAnimation.mAnimationUID = this->mName.mUID;
  v7->mBlend.mWeightSetUID = LODWORD(this->mActiveDirection);
  v7->mBlend.mWeightSetMaskUID = LODWORD(this->mDesiredActiveDirection);
  v7->mBlendDirection.mChildCount = (unsigned int)this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr[1].CreateClone(this);
  v9 = 1;
  for ( i = (int *)&this->mChildren.mNode.mNext[-3].mNext; i != p_mNetPoseSequence; v9 &= v11 )
  {
    v11 = (*(__int64 (__fastcall **)(int *, NetAnimationState *, IActionTreeSerializer *))(*(_QWORD *)i + 256i64))(
            i,
            state,
            creature);
    i = (int *)(*((_QWORD *)i + 6) - 40i64);
  }
  return v9;
}

// File Line: 4098
// RVA: 0x3ABAA0
bool __fastcall BlendAddNode::NetSerialize(BlendAddNode *this, NetAnimationState *state, Creature *creature)
{
  return BlendNode::NetSerializeBlend(this, PNT_BLEND_ADD, state, creature, 0);
}

// File Line: 4107
// RVA: 0x3ABC20
bool __fastcall BlendSubNode::NetSerialize(BlendSubNode *this, NetAnimationState *state, Creature *creature)
{
  return BlendNode::NetSerializeBlend(this, PNT_BLEND_SUB, state, creature, 0);
}

// File Line: 4117
// RVA: 0x3ABBF0
bool __fastcall BlendPhaseNode::NetSerialize(BlendPhaseNode *this, NetAnimationState *state, Creature *creature)
{
  return BlendNode::NetSerializeBlend(this, PNT_BLEND_PHASE, state, creature, this->mHoldPose != 0);
}

// File Line: 4404
// RVA: 0x3B6B60
float __fastcall BlendHistoryNode::getActivePoses(
        BlendHistoryNode *this,
        UFG::qNode<PoseNode,PoseNode> ***poseNode0,
        PoseNode **poseNodeF)
{
  UFG::qNode<BlendHistoryNode::TimeRecord,BlendHistoryNode::TimeRecord> *mNext; // rax
  int v4; // r11d
  UFG::qList<BlendHistoryNode::TimeRecord,BlendHistoryNode::TimeRecord,1,0> *p_mTimeRecords; // r10
  float v6; // xmm2_4
  int v9; // r9d
  float v10; // xmm1_4
  float v11; // xmm0_4
  int *p_mNetPoseSequence; // r8
  int v13; // edx
  PoseNode *p_mNext; // rax
  __int64 i; // rcx
  UFG::qList<BlendHistoryNode::TimeRecord,BlendHistoryNode::TimeRecord,1,0> *j; // rcx
  int k; // ecx
  UFG::qNode<BlendHistoryNode::TimeRecord,BlendHistoryNode::TimeRecord> *v18; // rax

  mNext = this->mTimeRecords.mNode.mNext;
  v4 = 0;
  p_mTimeRecords = &this->mTimeRecords;
  v6 = 0.0;
  v9 = 0;
  v10 = 0.0;
  v11 = *(float *)&mNext[1].mPrev + this->mLocalTime;
  if ( mNext != (UFG::qNode<BlendHistoryNode::TimeRecord,BlendHistoryNode::TimeRecord> *)&this->mTimeRecords )
  {
    do
    {
      if ( v11 < *(float *)&mNext[1].mPrev )
        break;
      mNext = mNext->mNext;
      ++v9;
    }
    while ( mNext != (UFG::qNode<BlendHistoryNode::TimeRecord,BlendHistoryNode::TimeRecord> *)p_mTimeRecords );
    if ( v9 > 0 )
    {
      p_mNetPoseSequence = &this->mNetPoseSequence;
      v13 = 0;
      p_mNext = (PoseNode *)&this->mChildren.mNode.mNext[-3].mNext;
      for ( i = (__int64)p_mNext; (int *)i != p_mNetPoseSequence; i = *(_QWORD *)(i + 48) - 40i64 )
        ++v13;
      if ( v9 < v13 )
      {
        for ( j = (UFG::qList<BlendHistoryNode::TimeRecord,BlendHistoryNode::TimeRecord,1,0> *)p_mTimeRecords->mNode.mNext;
              j != p_mTimeRecords;
              ++v4 )
        {
          j = (UFG::qList<BlendHistoryNode::TimeRecord,BlendHistoryNode::TimeRecord,1,0> *)j->mNode.mNext;
        }
        if ( v9 < v4 )
        {
          for ( k = v9; k > 0; --k )
          {
            if ( p_mNext == (PoseNode *)p_mNetPoseSequence )
              break;
            p_mNext = (PoseNode *)&p_mNext->mNext[-3].mNext;
          }
          *poseNodeF = p_mNext;
          *poseNode0 = &p_mNext->mPrev[-3].mNext;
          v18 = p_mTimeRecords->mNode.mNext;
          do
          {
            if ( v18 == (UFG::qNode<BlendHistoryNode::TimeRecord,BlendHistoryNode::TimeRecord> *)p_mTimeRecords )
              break;
            v18 = v18->mNext;
            --v9;
          }
          while ( v9 > 0 );
          v10 = *(float *)&v18[1].mPrev;
          v6 = *(float *)&v18->mPrev[1].mPrev;
        }
      }
    }
  }
  return (float)(v11 - v6) / (float)(v10 - v6);
}


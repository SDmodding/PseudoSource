// File Line: 98
// RVA: 0x3B7BA0
void __fastcall PoseNode::nodeBreakOnStart(PoseNode *this)
{
  PoseNode *v1; // rbx
  char *v2; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v1 = this;
  if ( PoseNode::sBreakOnStart
    && PoseNode::sEnableNodeBreakPoints
    && this->mBreakPoint
    && (!PoseNode::sBreakOnCondition
     || PoseNode::sBreakOnCondition == 1 && ((unsigned __int8 (__cdecl *)(PoseNode *))this->vfptr[4].GetClassname)(this))
    && PoseNode::sSoftBreakPoints )
  {
    v2 = UFG::qSymbol::as_cstr_dbg(&v1->mName);
    UFG::qString::FormatEx(&result, "node:\n%s", v2);
    ActionTreeDebugMessageHandler("PoseNode::nodeBreakOnStart", result.mData);
    UFG::qString::~qString(&result);
  }
}

// File Line: 111
// RVA: 0x3B7C30
void __fastcall PoseNode::nodeBreakOnUpdate(PoseNode *this)
{
  PoseNode *v1; // rbx
  char *v2; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v1 = this;
  if ( PoseNode::sBreakOnUpdate
    && PoseNode::sEnableNodeBreakPoints
    && this->mBreakPoint
    && (!PoseNode::sBreakOnCondition
     || PoseNode::sBreakOnCondition == 1 && ((unsigned __int8 (__cdecl *)(PoseNode *))this->vfptr[4].GetClassname)(this))
    && PoseNode::sSoftBreakPoints )
  {
    v2 = UFG::qSymbol::as_cstr_dbg(&v1->mName);
    UFG::qString::FormatEx(&result, "node:\n%s", v2);
    ActionTreeDebugMessageHandler("PoseNode::nodeBreakOnUpdate", result.mData);
    UFG::qString::~qString(&result);
  }
}

// File Line: 156
// RVA: 0x39FAB0
void __fastcall PoseNode::~PoseNode(PoseNode *this)
{
  PoseNode *v1; // rdi
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // rbx
  __int64 v3; // rax
  __int64 v4; // rax
  char *v5; // rcx
  UFG::qNode<PoseNode,PoseNode> *v6; // rdx
  UFG::qNode<PoseNode,PoseNode> *v7; // rcx
  UFG::qNode<PoseNode,PoseNode> *v8; // rax
  UFG::qNode<PoseNode,PoseNode> *v9; // rcx
  UFG::qNode<PoseNode,PoseNode> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *v13; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseNode::`vftable{for `Expression::IMemberMap};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->vfptr;
  this->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v3 = this->mParent.mOffset;
  if ( v3 && (UFG::qOffset64<PoseNodeParent *> *)((char *)&this->mParent + v3) )
  {
    v4 = this->mParent.mOffset;
    if ( v4 )
      v5 = (char *)&this->mParent + v4;
    else
      v5 = 0i64;
    (*(void (__fastcall **)(char *, PoseNode *))(*(_QWORD *)v5 + 384i64))(v5, v1);
  }
  v6 = (UFG::qNode<PoseNode,PoseNode> *)&v1->mPrev;
  v7 = v1->mPrev;
  v8 = v1->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v6->mPrev = v6;
  v6->mNext = v6;
  v9 = v1->mPrev;
  v10 = v1->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v6->mPrev = v6;
  v1->mNext = (UFG::qNode<PoseNode,PoseNode> *)&v1->mPrev;
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<PoseNode>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  v13 = &v2->m_SafePointerList;
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v2->m_SafePointerList);
  v11 = v2->m_SafePointerList.mNode.mPrev;
  v12 = v2->m_SafePointerList.mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v13->mNode.mPrev = &v13->mNode;
  v13->mNode.mNext = &v13->mNode;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 190
// RVA: 0x39E310
void __fastcall PoseNodeParent::PoseNodeParent(PoseNodeParent *this, MemImageLoadFlag flag)
{
  PoseNodeParent *v2; // rdi
  UFG::qNode<PoseNode,PoseNode> *v3; // rax
  UFG::qList<PoseNode,PoseNode,1,0> *v4; // r9
  __int64 v5; // rdx
  __int64 v6; // rax
  signed __int64 v7; // rcx
  _QWORD *v8; // r8
  char *v9; // rcx
  UFG::qNode<PoseNode,PoseNode> *v10; // rcx
  UFG::qNode<PoseNode,PoseNode> *v11; // rax

  v2 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  UFG::qSafePointerNode<PoseNode>::qSafePointerNode<PoseNode>((UFG::qSafePointerNode<PoseNode> *)&this->vfptr);
  v3 = (UFG::qNode<PoseNode,PoseNode> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (Expression::IMemberMapVtbl *)&PoseNode::`vftable{for `Expression::IMemberMap};
  v2->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v2->vfptr = (Expression::IMemberMapVtbl *)&PoseNodeParent::`vftable{for `Expression::IMemberMap};
  v2->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNodeParent::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v4 = &v2->mChildren;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v5 = 0i64;
  if ( v2->mChildrenSerialized.mCount & 0x7FFFFFFF )
  {
    do
    {
      v6 = v2->mChildrenSerialized.mData.mOffset;
      if ( v6 )
        v7 = (signed __int64)&v2->mChildrenSerialized.mData + v6;
      else
        v7 = 0i64;
      v8 = (_QWORD *)(v7 + 8 * v5);
      if ( *v8 )
        v9 = (char *)v8 + *v8;
      else
        v9 = 0i64;
      v10 = (UFG::qNode<PoseNode,PoseNode> *)(v9 + 40);
      v11 = v4->mNode.mPrev;
      v11->mNext = v10;
      v10->mPrev = v11;
      v10->mNext = &v4->mNode;
      v4->mNode.mPrev = v10;
      v5 = (unsigned int)(v5 + 1);
    }
    while ( (unsigned int)v5 < (v2->mChildrenSerialized.mCount & 0x7FFFFFFFu) );
  }
  v2->mChildrenSerialized.mCount &= 0x80000000;
}

// File Line: 202
// RVA: 0x3AE680
void __fastcall PoseNodeParent::Serialize(PoseNodeParent *this, IActionTreeSerializer *serializer)
{
  char *v2; // r9
  PoseNodeParent *v3; // rsi
  IActionTreeSerializer *v4; // r12
  PoseNodeParent *v5; // r15
  int v6; // er8
  signed __int64 v7; // rax
  int v8; // edi
  BinPtrArray<ITrack,1,0> *v9; // r14
  unsigned int v10; // er11
  __int64 v11; // rbx
  __int64 v12; // r10
  signed __int64 v13; // rax
  signed __int64 v14; // rcx
  __int64 v15; // rax
  signed __int64 v16; // r8
  int v17; // ecx
  signed __int64 i; // rax
  __int64 v19; // rax
  char *v20; // rcx
  signed __int64 j; // rsi
  __int64 v22; // rdi
  unsigned int v23; // ebx
  unsigned int v24; // edx
  __int64 v25; // rax
  signed __int64 v26; // rcx
  IActionTreeSerializerVtbl *v27; // rax
  unsigned int v28; // ebx
  signed __int64 v29; // rsi
  char *v30; // rcx
  char *v31; // rdi
  __int64 v32; // rax
  __int64 v33; // [rsp+28h] [rbp-50h]
  __int64 v34; // [rsp+30h] [rbp-48h]
  __int64 v35; // [rsp+40h] [rbp-38h]

  v2 = (char *)&this->mNetPoseSequence;
  v3 = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  v4 = serializer;
  v5 = this;
  v6 = 0;
  v7 = (signed __int64)v3;
  if ( v3 != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      ++v6;
      v7 = *(_QWORD *)(v7 + 48) - 40i64;
    }
    while ( (char *)v7 != v2 );
  }
  v8 = this->mChildrenSerialized.mCount;
  v9 = (BinPtrArray<ITrack,1,0> *)&this->mChildrenSerialized;
  v10 = this->mChildrenSerialized.mCount & 0x7FFFFFFF;
  if ( v6 == v10 )
  {
    serializer = 0i64;
    if ( !v10 )
      goto LABEL_38;
    v11 = this->mChildrenSerialized.mData.mOffset;
    v12 = 0i64;
    while ( 1 )
    {
      if ( v11 )
        v13 = (signed __int64)&v5->mChildrenSerialized.mData + v11;
      else
        v13 = 0i64;
      v14 = v12 + v13;
      v15 = *(_QWORD *)(v12 + v13);
      v16 = v15 + v14;
      if ( !v15 )
        v16 = 0i64;
      v17 = (signed int)serializer;
      for ( i = (signed __int64)v3; v17 > 0; i = *(_QWORD *)(i + 48) - 40i64 )
      {
        if ( (char *)i == v2 )
          break;
        --v17;
      }
      if ( v16 != i )
        break;
      serializer = (IActionTreeSerializer *)(unsigned int)((_DWORD)serializer + 1);
      v12 += 8i64;
      if ( (unsigned int)serializer >= v10 )
        goto LABEL_38;
    }
  }
  if ( v8 >= 0 )
  {
    v19 = v9->mData.mOffset;
    if ( v19 )
    {
      v20 = (char *)&v9->mData + v19;
      if ( v20 )
        operator delete[](v20);
    }
    v9->mData.mOffset = 0i64;
    v9->mCount &= 0x80000000;
  }
  for ( j = (signed __int64)&v5->mChildren.mNode.mNext[-3].mNext;
        (int *)j != &v5->mNetPoseSequence;
        j = *(_QWORD *)(j + 48) - 40i64 )
  {
    v22 = (unsigned int)v9->mCount;
    LODWORD(v22) = v22 & 0x7FFFFFFF;
    v23 = v22 + 1;
    if ( (signed int)v22 + 1 > (unsigned int)v22 )
    {
      v24 = 1;
      if ( (_DWORD)v22 )
        v24 = 2 * v22;
      for ( ; v24 < v23; v24 *= 2 )
        ;
      if ( v24 - v23 > 0x10000 )
        v24 = v22 + 65537;
      BinPtrArray<Condition,1,0>::Reallocate(v9, v24, "BinPtrArray.Add");
    }
    v9->mCount &= 0x80000000;
    v9->mCount |= v23 & 0x7FFFFFFF;
    v25 = v9->mData.mOffset;
    if ( v25 )
      v26 = (signed __int64)&v9->mData + v25;
    else
      v26 = 0i64;
    serializer = (IActionTreeSerializer *)(v26 + 8 * v22);
    if ( j )
      v27 = (IActionTreeSerializerVtbl *)(j - (_QWORD)serializer);
    else
      v27 = 0i64;
    serializer->vfptr = v27;
  }
LABEL_38:
  v28 = 0;
  v29 = (signed __int64)&v5->mChildrenSerialized.mData + v5->mChildrenSerialized.mData.mOffset;
  if ( v9->mCount & 0x7FFFFFFF )
  {
    do
    {
      v30 = (char *)(v29 + 8i64 * v28);
      v31 = &v30[*(_QWORD *)v30];
      if ( v31 )
      {
        v32 = (*(__int64 (__fastcall **)(char *, IActionTreeSerializer *))(*(_QWORD *)v31 + 32i64))(
                &v30[*(_QWORD *)v30],
                serializer);
        LODWORD(v35) = -1;
        LODWORD(v34) = 0;
        LODWORD(v33) = 1;
        v4->vfptr->_PushObjectToSerialize(
          v4,
          v31,
          1u,
          (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
          (const char *)v32,
          (QUEUE_PRIORITY)v33,
          v34,
          0i64,
          v35,
          0i64);
      }
      ++v28;
    }
    while ( v28 < (v9->mCount & 0x7FFFFFFFu) );
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
  BlendDirectionNode *v1; // rbx
  UFG::qList<PoseNode,PoseNode,1,0> *v2; // [rsp+48h] [rbp+10h]
  MotionPhase2 *v3; // [rsp+48h] [rbp+10h]

  v1 = this;
  PoseNode::PoseNode((PoseNode *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PoseNodeParent::`vftable{for `Expression::IMemberMap};
  v1->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNodeParent::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v1->mChildrenSerialized.mCount = 0;
  v1->mChildrenSerialized.mData.mOffset = 0i64;
  v2 = &v1->mChildren;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v1->mLocalTime = 0.0;
  v1->vfptr = (Expression::IMemberMapVtbl *)&BlendDirectionNode::`vftable{for `Expression::IMemberMap};
  v1->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&BlendDirectionNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  *(_QWORD *)&v1->mActiveDirection = 0i64;
  v3 = &v1->mMotionPhase;
  v3->0 = (Expression::IMemberMap)(unsigned __int64)&Expression::IMemberMap::`vftable;
  v3->vfptr = (Expression::IMemberMapVtbl *)&MotionPhase2::`vftable;
  *(_QWORD *)&v1->mMotionPhase.mPhaseMark.mValue = 0i64;
  *(_QWORD *)&v1->mMotionPhase.mPhase = 0i64;
  *(_QWORD *)v1->mDirections = -4647714812233515008i64;
  *(_QWORD *)&v1->mDirections[2] = -4647714812233515008i64;
  *(_QWORD *)&v1->mDirections[4] = -4647714812233515008i64;
  *(_QWORD *)&v1->mDirections[6] = -4647714812233515008i64;
  *(_QWORD *)&v1->mWeight = 0i64;
  v1->mChild1ID = 0;
  *(_QWORD *)&v1->mLimitIndexCW = -1i64;
  v1->mDirectionParam = 0;
  *(_WORD *)&v1->mSetPhaseMatch = 0;
  v1->mPlayRate = 1.0;
  v1->mDebugPoseColour.r = UFG::qColour::Blue.r;
  v1->mDebugPoseColour.g = UFG::qColour::Blue.g;
  v1->mDebugPoseColour.b = UFG::qColour::Blue.b;
  v1->mDebugPoseColour.a = UFG::qColour::Blue.a;
}

// File Line: 415
// RVA: 0x39DBF0
void __fastcall BlendDirectionNode::BlendDirectionNode(BlendDirectionNode *this, MemImageLoadFlag flag)
{
  BlendDirectionNode *v2; // rbx
  MotionPhase2 *v3; // [rsp+50h] [rbp+18h]

  v2 = this;
  PoseNodeParent::PoseNodeParent((PoseNodeParent *)&this->vfptr, flag);
  v2->vfptr = (Expression::IMemberMapVtbl *)&BlendDirectionNode::`vftable{for `Expression::IMemberMap};
  v2->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&BlendDirectionNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v3 = &v2->mMotionPhase;
  v3->0 = (Expression::IMemberMap)(unsigned __int64)&Expression::IMemberMap::`vftable;
  v3->vfptr = (Expression::IMemberMapVtbl *)&MotionPhase2::`vftable;
  *(_QWORD *)&v2->mMotionPhase.mPhaseMark.mValue = 0i64;
  *(_QWORD *)&v2->mMotionPhase.mPhase = 0i64;
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
  UFG::qNode<ITask,ITask> *v1; // rdx
  ActionContext **v2; // rcx
  __int64 result; // rax
  signed __int64 i; // rdx

  v1 = this->m_RunningTasks.mNode.mNext;
  v2 = &this->mpContext;
  result = 0i64;
  for ( i = (signed __int64)&v1[-1].mNext; (ActionContext **)i != v2; i = *(_QWORD *)(i + 16) - 8i64 )
    result = (unsigned int)(result + 1);
  return result;
}

// File Line: 638
// RVA: 0x3AA720
UFG::qNode<ITask,ITask> *__fastcall AnimationNode::Get_RunningTasksDebug(AnimationNode *this, int priority)
{
  UFG::qNode<ITask,ITask> **v2; // rax
  ActionContext **v3; // rcx

  v2 = &this->m_RunningTasks.mNode.mNext[-1].mNext;
  if ( priority > 0 )
  {
    v3 = &this->mpContext;
    do
    {
      if ( v2 == (UFG::qNode<ITask,ITask> **)v3 )
        break;
      --priority;
      v2 = &v2[2][-1].mNext;
    }
    while ( priority > 0 );
  }
  return v2[3];
}

// File Line: 645
// RVA: 0x3AA8C0
void AnimationNode::Init(void)
{
  JUMPOUT(
    UFG::BasePhysicsSystem::mInstance->mJobQueue,
    0i64,
    hkaAnimationSampleAndCombineJobQueueUtils::registerWithJobQueue);
}

// File Line: 734
// RVA: 0x39D550
void __fastcall AnimationNode::AnimationNode(AnimationNode *this)
{
  AnimationNode *v1; // rdi
  UFG::qSafePointer<SkeletalAnimation,SkeletalAnimation> *v2; // rax
  ActionContext *v3; // rbx
  AnimationGroupHandle *v4; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v5; // rax
  MotionPhase2 *v6; // rax
  UFG::allocator::free_link *v7; // rax
  ActionContext *v8; // rax
  UFG::qList<ITask,ITask,0,0> *v9; // [rsp+48h] [rbp+10h]
  SkeletalAnimationHandle *v10; // [rsp+48h] [rbp+10h]
  UFG::qSafePointer<AnimationGroup,AnimationGroup> *v11; // [rsp+50h] [rbp+18h]

  v1 = this;
  PoseNode::PoseNode((PoseNode *)&this->vfptr);
  UFG::qSafePointerNode<AnimationNode>::qSafePointerNode<AnimationNode>((UFG::qSafePointerNode<AnimationNode> *)&v1->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&AnimationNode::`vftable{for `Expression::IMemberMap};
  v1->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&AnimationNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v1->vfptr = (UFG::qSafePointerNode<AnimationNode>Vtbl *)&AnimationNode::`vftable;
  v9 = &v1->m_RunningTasks;
  v9->mNode.mPrev = &v9->mNode;
  v9->mNode.mNext = &v9->mNode;
  v10 = &v1->mSkeletalAnimationHandle;
  v10->mPrev = (UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *)&v10->mPrev;
  v1->mSkeletalAnimationHandle.m_SkeletalAnimationName.mUID = -1;
  v2 = &v1->mSkeletalAnimationHandle.m_SkeletalAnimation;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v3 = 0i64;
  v2->m_pPointer = 0i64;
  v4 = &v1->mAnimationGroupHandle;
  v4->mPrev = (UFG::qNode<AnimationGroupHandle,AnimationGroupList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<AnimationGroupHandle,AnimationGroupList> *)&v4->mPrev;
  v5 = (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)&v1->mAnimationGroupHandle.mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v1->mAnimationGroupHandle.m_AnimationGroupSymbol.mUID = -1;
  v11 = &v1->mAnimationGroupHandle.m_AnimationGroup;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v11->mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v4->m_AnimationGroup.m_pPointer = 0i64;
  *(_DWORD *)&v1->mAnimationGroupHandle.m_eAnimationPriority.mValue = -65524;
  v1->mAnimationGroupHandle.m_bHasBeenBound = 0;
  v1->mAnimationGroupHandle.m_pReferenceInfo = 0i64;
  v1->mLocalTime = 0.0;
  v1->mLastPlayTime = -1.0;
  v1->mPlayStartTime = 0.0;
  v1->mPlayEndTime = -1.0;
  *(_QWORD *)&v1->mPlayRate = 1065353216i64;
  v1->mDuration = -1.0;
  *(_QWORD *)&v1->mCurrentExtractedMotionSpeed = 0i64;
  v1->mDebugPlayingFromActionNode = 0i64;
  v6 = &v1->mMotionPhase;
  v6->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  v6->mResourceOwner = 0i64;
  v6->vfptr = (Expression::IMemberMapVtbl *)&MotionPhase2::`vftable;
  *(_QWORD *)&v1->mMotionPhase.mPhaseMark.mValue = 0i64;
  *(_QWORD *)&v1->mMotionPhase.mPhase = 0i64;
  *(_DWORD *)&v1->mPlayMode.mValue = 16777473;
  *(_WORD *)&v1->mFirstPlay = 1;
  v1->mFinished = 0;
  v7 = UFG::qMalloc(0xD8ui64, "ActionContext", 0i64);
  if ( v7 )
  {
    ActionContext::ActionContext((ActionContext *)v7);
    v3 = v8;
  }
  v1->mpContext = v3;
}

// File Line: 765
// RVA: 0x39D260
void __fastcall AnimationNode::AnimationNode(AnimationNode *this, UFG::qSymbolUC *animName, AnimationPlayMode playMode, float startTime, float endTime)
{
  char v5; // di
  UFG::qSymbolUC *v6; // r14
  AnimationNode *v7; // rsi
  UFG::qSafePointer<SkeletalAnimation,SkeletalAnimation> *v8; // rax
  ActionContext *v9; // rbx
  AnimationGroupHandle *v10; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v11; // rax
  UFG::qSafePointer<AnimationGroup,AnimationGroup> *v12; // ST28_8
  MotionPhase2 *v13; // rax
  UFG::allocator::free_link *v14; // rax
  ActionContext *v15; // rax
  UFG::qList<ITask,ITask,0,0> *v16; // [rsp+68h] [rbp+10h]
  SkeletalAnimationHandle *v17; // [rsp+68h] [rbp+10h]

  v5 = playMode;
  v6 = animName;
  v7 = this;
  PoseNode::PoseNode((PoseNode *)&this->vfptr);
  UFG::qSafePointerNode<AnimationNode>::qSafePointerNode<AnimationNode>((UFG::qSafePointerNode<AnimationNode> *)&v7->vfptr);
  v7->vfptr = (Expression::IMemberMapVtbl *)&AnimationNode::`vftable{for `Expression::IMemberMap};
  v7->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&AnimationNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v7->vfptr = (UFG::qSafePointerNode<AnimationNode>Vtbl *)&AnimationNode::`vftable;
  v16 = &v7->m_RunningTasks;
  v16->mNode.mPrev = &v16->mNode;
  v16->mNode.mNext = &v16->mNode;
  v17 = &v7->mSkeletalAnimationHandle;
  v17->mPrev = (UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *)&v17->mPrev;
  v17->mNext = (UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *)&v17->mPrev;
  v7->mSkeletalAnimationHandle.m_SkeletalAnimationName.mUID = -1;
  v8 = &v7->mSkeletalAnimationHandle.m_SkeletalAnimation;
  v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v8->mNext = (UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v9 = 0i64;
  v8->m_pPointer = 0i64;
  v10 = &v7->mAnimationGroupHandle;
  v10->mPrev = (UFG::qNode<AnimationGroupHandle,AnimationGroupList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<AnimationGroupHandle,AnimationGroupList> *)&v10->mPrev;
  v11 = (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)&v7->mAnimationGroupHandle.mPrev;
  v11->mPrev = v11;
  v11->mNext = v11;
  v7->mAnimationGroupHandle.m_AnimationGroupSymbol.mUID = -1;
  v12 = &v7->mAnimationGroupHandle.m_AnimationGroup;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v12->mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v10->m_AnimationGroup.m_pPointer = 0i64;
  *(_DWORD *)&v7->mAnimationGroupHandle.m_eAnimationPriority.mValue = -65524;
  v7->mAnimationGroupHandle.m_bHasBeenBound = 0;
  v7->mAnimationGroupHandle.m_pReferenceInfo = 0i64;
  v7->mLocalTime = startTime;
  v7->mLastPlayTime = -1.0;
  v7->mPlayStartTime = startTime;
  v7->mPlayEndTime = endTime;
  *(_QWORD *)&v7->mPlayRate = 1065353216i64;
  v7->mDuration = -1.0;
  *(_QWORD *)&v7->mCurrentExtractedMotionSpeed = 0i64;
  v7->mDebugPlayingFromActionNode = 0i64;
  v13 = &v7->mMotionPhase;
  v13->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  v13->mResourceOwner = 0i64;
  v13->vfptr = (Expression::IMemberMapVtbl *)&MotionPhase2::`vftable;
  *(_QWORD *)&v7->mMotionPhase.mPhaseMark.mValue = 0i64;
  *(_QWORD *)&v7->mMotionPhase.mPhase = 0i64;
  v7->mPlayMode.mValue = v5;
  *(_DWORD *)&v7->mPreserveMotionOnHoldLastFrame = 16842753;
  *(_WORD *)&v7->mPoseOnFrameBoundaries = 0;
  v14 = UFG::qMalloc(0xD8ui64, "ActionContext", 0i64);
  if ( v14 )
  {
    ActionContext::ActionContext((ActionContext *)v14);
    v9 = v15;
  }
  v7->mpContext = v9;
  v7->mName = (UFG::qSymbolUC)v6->mUID;
  AnimationNode::verifyBindAnimation(v7);
}

// File Line: 782
// RVA: 0x39D430
void __fastcall AnimationNode::AnimationNode(AnimationNode *this, MemImageLoadFlag flag)
{
  AnimationNode *v2; // rsi
  UFG::qNode<PoseNode,PoseNode> *v3; // rax
  UFG::qSafePointer<SkeletalAnimation,SkeletalAnimation> *v4; // rax
  AnimationGroupHandle *v5; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v6; // rax
  UFG::qList<ITask,ITask,0,0> *v7; // [rsp+70h] [rbp+18h]
  SkeletalAnimationHandle *v8; // [rsp+70h] [rbp+18h]
  MotionPhase2 *v9; // [rsp+70h] [rbp+18h]
  UFG::qSafePointer<AnimationGroup,AnimationGroup> *v10; // [rsp+78h] [rbp+20h]

  v2 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  UFG::qSafePointerNode<PoseNode>::qSafePointerNode<PoseNode>((UFG::qSafePointerNode<PoseNode> *)&this->vfptr);
  v3 = (UFG::qNode<PoseNode,PoseNode> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (Expression::IMemberMapVtbl *)&PoseNode::`vftable{for `Expression::IMemberMap};
  v2->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  UFG::qSafePointerNode<AnimationNode>::qSafePointerNode<AnimationNode>((UFG::qSafePointerNode<AnimationNode> *)&v2->vfptr);
  v2->vfptr = (Expression::IMemberMapVtbl *)&AnimationNode::`vftable{for `Expression::IMemberMap};
  v2->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&AnimationNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v2->vfptr = (UFG::qSafePointerNode<AnimationNode>Vtbl *)&AnimationNode::`vftable;
  v2->mpContext = 0i64;
  v7 = &v2->m_RunningTasks;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  v8 = &v2->mSkeletalAnimationHandle;
  v8->mPrev = (UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *)&v8->mPrev;
  v8->mNext = (UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *)&v8->mPrev;
  v4 = &v2->mSkeletalAnimationHandle.m_SkeletalAnimation;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<SkeletalAnimation>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->m_pPointer = 0i64;
  v5 = &v2->mAnimationGroupHandle;
  v5->mPrev = (UFG::qNode<AnimationGroupHandle,AnimationGroupList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<AnimationGroupHandle,AnimationGroupList> *)&v5->mPrev;
  v6 = (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)&v2->mAnimationGroupHandle.mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  v10 = &v2->mAnimationGroupHandle.m_AnimationGroup;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v5->m_AnimationGroup.m_pPointer = 0i64;
  v9 = &v2->mMotionPhase;
  v9->0 = (Expression::IMemberMap)(unsigned __int64)&Expression::IMemberMap::`vftable;
  v9->vfptr = (Expression::IMemberMapVtbl *)&MotionPhase2::`vftable;
}

// File Line: 791
// RVA: 0x39F1C0
void __fastcall AnimationNode::~AnimationNode(AnimationNode *this)
{
  AnimationNode *v1; // rdi
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // r14
  UFG::qNode<ITask,ITask> *v3; // rbx
  UFG::qNode<ITask,ITask> *v4; // rdx
  UFG::qNode<ITask,ITask> *v5; // rax
  SkeletalAnimationHandle *v6; // rbx
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v7; // rcx
  UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *v8; // rax
  ActionContext *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v15; // rax
  MotionPhase2 *v16; // [rsp+58h] [rbp+10h]

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationNode::`vftable{for `Expression::IMemberMap};
  this->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&AnimationNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->vfptr;
  this->vfptr = (UFG::qSafePointerNode<AnimationNode>Vtbl *)&AnimationNode::`vftable;
  while ( (ActionContext **)&v1->m_RunningTasks.mNode.mNext[-1].mNext != &v1->mpContext )
  {
    v3 = v1->m_RunningTasks.mNode.mNext;
    ((void (__fastcall *)(UFG::qNode<ITask,ITask> **))v3[-1].mNext[1].mNext)(&v3[-1].mNext);
    v4 = v3->mPrev;
    v5 = v3->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = v3;
    v3->mNext = v3;
    ((void (__fastcall *)(UFG::qNode<ITask,ITask> **, signed __int64))v3[-1].mNext->mPrev)(&v3[-1].mNext, 1i64);
  }
  v6 = &v1->mSkeletalAnimationHandle;
  v7 = v1->mSkeletalAnimationHandle.mPrev;
  v8 = v1->mSkeletalAnimationHandle.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v6->mPrev = (UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<SkeletalAnimationHandle,SkeletalAnimationList> *)&v6->mPrev;
  AnimationGroupHandle::Unbind(&v1->mAnimationGroupHandle);
  v9 = v1->mpContext;
  if ( v9 )
  {
    if ( v9->mSimObject.m_pPointer )
    {
      v10 = v9->mSimObject.mPrev;
      v11 = v9->mSimObject.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mSimObject.mPrev;
      v9->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mSimObject.mPrev;
    }
    v9->mSimObject.m_pPointer = 0i64;
    v12 = v9->mSimObject.mPrev;
    v13 = v9->mSimObject.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v9->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mSimObject.mPrev;
    v9->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mSimObject.mPrev;
    operator delete[](v9);
  }
  v16 = &v1->mMotionPhase;
  v16->vfptr = (Expression::IMemberMapVtbl *)&MotionPhase2::`vftable;
  v16->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  AnimationGroupHandle::~AnimationGroupHandle(&v1->mAnimationGroupHandle);
  SkeletalAnimationHandle::~SkeletalAnimationHandle(&v1->mSkeletalAnimationHandle);
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>(&v1->m_RunningTasks);
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<AnimationNode>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v2->m_SafePointerList);
  v14 = v2->m_SafePointerList.mNode.mPrev;
  v15 = v2->m_SafePointerList.mNode.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v2->m_SafePointerList.mNode.mPrev = &v2->m_SafePointerList.mNode;
  v2->m_SafePointerList.mNode.mNext = &v2->m_SafePointerList.mNode;
  PoseNode::~PoseNode((PoseNode *)&v1->vfptr);
}

// File Line: 820
// RVA: 0x3AEF90
void __fastcall AnimationNode::SetContext(AnimationNode *this, ActionContext *context)
{
  AnimationNode *v2; // rbx
  AnimationGroup *v3; // rdx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v4; // rdx
  UFG::qList<AnimationGroup,AnimationGroupUpdateList,0,0> *v5; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v6; // rax

  v2 = this;
  ActionContext::operator=(this->mpContext, context);
  v2->mpContext->mActionController = 0i64;
  if ( LocalPlayer == (UFG::SimObjectCharacter *)v2->mpContext->mSimObject.m_pPointer
    && (v2->mAnimationGroupHandle.m_eAnimationPriority.mValue != 15 || v2->mAnimationGroupHandle.m_AnimationSubPriority) )
  {
    v3 = v2->mAnimationGroupHandle.m_AnimationGroup.m_pPointer;
    *(_DWORD *)&v2->mAnimationGroupHandle.m_eAnimationPriority.mValue = 15;
    if ( v3 )
    {
      v4 = (UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *)&v3->mPrev;
      if ( v4->mPrev == v4 && v4->mNext == v4 )
      {
        v5 = &AnimationDataBase::sAnimationDataBase->mQueuedUpdateGroups;
        v6 = AnimationDataBase::sAnimationDataBase->mQueuedUpdateGroups.mNode.mPrev;
        v6->mNext = v4;
        v4->mPrev = v6;
        v4->mNext = &v5->mNode;
        v5->mNode.mPrev = v4;
      }
    }
  }
}

// File Line: 880
// RVA: 0x3A4D10
AnimationNode *__fastcall AnimationNode::Clone(AnimationNode *this)
{
  AnimationNode *v1; // rdi
  char *v2; // rax
  AnimationNode *v3; // rax
  AnimationNode *v4; // rbx
  ActionContext *v5; // rdx

  v1 = this;
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
  v4->mName.mUID = v1->mName.mUID;
  v5 = v1->mpContext;
  if ( v5 )
    ActionContext::operator=(v4->mpContext, v5);
  AnimationNode::verifyBindAnimation(v4);
  v4->mLocalTime = v1->mLocalTime;
  v4->mLastPlayTime = v1->mLastPlayTime;
  v4->mPlayStartTime = v1->mPlayStartTime;
  v4->mPlayEndTime = v1->mPlayEndTime;
  v4->mPlayRate = v1->mPlayRate;
  v4->mLoops = v1->mLoops;
  v4->mPreserveMotionOnHoldLastFrame = v1->mPreserveMotionOnHoldLastFrame;
  v4->mPause = v1->mPause;
  v4->mPlayTracks = v1->mPlayTracks;
  v4->mPlayMode.mValue = v1->mPlayMode.mValue;
  v4->mMotionPhase.mResourceOwner = v1->mMotionPhase.mResourceOwner;
  v4->mMotionPhase.mPhaseMark.mValue = v1->mMotionPhase.mPhaseMark.mValue;
  v4->mMotionPhase.mPhasePeriod = v1->mMotionPhase.mPhasePeriod;
  v4->mMotionPhase.mPhase = v1->mMotionPhase.mPhase;
  v4->mMotionPhase.mPhaseDuration = v1->mMotionPhase.mPhaseDuration;
  v4->mFirstPlay = v1->mFirstPlay;
  v4->mPoseOnFrameBoundaries = v1->mPoseOnFrameBoundaries;
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
char __usercall GetWeightedDurationAndParametricTime@<al>(PoseNode *pose0@<rcx>, PoseNode *pose1@<rdx>, float weight@<xmm2>, float *weightedDurationMaster@<r9>, float a5@<xmm0>, float *parametricLocalTimeMaster)
{
  float v6; // xmm6_4
  Expression::IMemberMapVtbl *v7; // rax
  PoseNode *v8; // rbx
  float *v9; // rdi
  Expression::IMemberMapVtbl *v10; // rax
  void **v12; // [rsp+20h] [rbp-68h]
  char v13; // [rsp+28h] [rbp-60h]
  __int64 v14; // [rsp+30h] [rbp-58h]

  v6 = FLOAT_N1_0;
  v12 = &FirstAnimationNode::`vftable;
  v7 = pose0->vfptr;
  v8 = pose1;
  v9 = weightedDurationMaster;
  v13 = 1;
  v14 = 0i64;
  v7[1].FindWithOldPath((Expression::IMemberMap *)&pose0->vfptr, (const char *)&v12);
  if ( !v14 )
    return 0;
  (*(void (**)(void))(*(_QWORD *)v14 + 224i64))();
  (*(void (**)(void))(*(_QWORD *)v14 + 392i64))();
  v10 = v8->vfptr;
  v14 = 0i64;
  v10[1].FindWithOldPath((Expression::IMemberMap *)&v8->vfptr, (const char *)&v12);
  if ( v14 )
  {
    (*(void (**)(void))(*(_QWORD *)v14 + 224i64))();
    v6 = a5;
    (*(void (**)(void))(*(_QWORD *)v14 + 392i64))();
  }
  if ( a5 <= 0.0 || v6 <= 0.0 )
    return 0;
  *v9 = (float)((float)(v6 - a5) * weight) + a5;
  *parametricLocalTimeMaster = a5 / a5;
  return 1;
}

// File Line: 978
// RVA: 0x3A6CF0
void __fastcall DurationMatch(PoseNode *pose0, PoseNode *pose1, float weight, float masterRate)
{
  PoseNode *v4; // rbx
  Expression::IMemberMapVtbl *v5; // rax
  float parametricLocalTimeMaster; // [rsp+30h] [rbp-48h]
  float weightedDurationMaster; // [rsp+34h] [rbp-44h]
  void **v8; // [rsp+38h] [rbp-40h]
  char v9; // [rsp+40h] [rbp-38h]
  float v10; // [rsp+48h] [rbp-30h]
  float v11; // [rsp+4Ch] [rbp-2Ch]
  float v12; // [rsp+50h] [rbp-28h]
  char v13; // [rsp+54h] [rbp-24h]

  v4 = pose1;
  if ( GetWeightedDurationAndParametricTime(pose0, pose1, weight, &weightedDurationMaster, &parametricLocalTimeMaster) )
  {
    v8 = &AnimationNode_SetLocalTimeParametric::`vftable;
    v5 = v4->vfptr;
    v10 = parametricLocalTimeMaster;
    v11 = weightedDurationMaster;
    v12 = masterRate;
    v9 = 1;
    v13 = 1;
    v5[1].FindWithOldPath((Expression::IMemberMap *)&v4->vfptr, (const char *)&v8);
  }
}

// File Line: 998
// RVA: 0x3B67E0
void __fastcall debugDrawFootTracks(SkeletalAnimation *anim, float time, float xScreenPos, float yScreenPos)
{
  SkeletalAnimation *v4; // rbx
  __int64 v5; // rsi
  float v6; // xmm0_4
  float v7; // xmm8_4
  __int64 v8; // rbx
  signed __int64 v9; // r14
  float *v10; // rdi
  int v11; // eax
  signed int v12; // ecx
  UFG::qColour *v13; // rax
  float v14; // xmm0_4
  int v15; // [rsp+18h] [rbp-49h]
  __int64 v16; // [rsp+20h] [rbp-41h]
  float v17; // [rsp+28h] [rbp-39h]
  float v18; // [rsp+2Ch] [rbp-35h]
  int v19; // [rsp+30h] [rbp-31h]
  float v20; // [rsp+38h] [rbp-29h]
  float v21; // [rsp+3Ch] [rbp-25h]
  int v22; // [rsp+40h] [rbp-21h]
  UFG::qColour v23; // [rsp+48h] [rbp-19h]
  UFG::qColour v24; // [rsp+58h] [rbp-9h]

  v4 = anim;
  v5 = ((__int64 (*)(void))anim->vfptr[1].Serialize)();
  v6 = SkeletalAnimation::GetDuration(v4);
  if ( v6 > 0.0 )
  {
    v23 = UFG::qColour::Green;
    UFG::DrawBoxScreenSpace(xScreenPos, yScreenPos, sBarThinkness, sBarLength, &v23);
    v18 = xScreenPos;
    v7 = 1.0 / v6;
    v19 = 0;
    LODWORD(v16) = 0;
    v17 = (float)((float)((float)(1.0 / v6) * time) * sBarLength) + xScreenPos;
    v23 = UFG::qColour::Green;
    UFG::DrawLineScreenSpace((UFG::qVector3 *)&v17, (UFG::qVector3 *)&v15, &v23);
    v8 = 0i64;
    v9 = v5 + *(_QWORD *)(v5 + 24) + 24i64;
    if ( *(_DWORD *)(v5 + 16) & 0x7FFFFFFF )
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
      *(_QWORD *)&v23.g = LODWORD(xScreenPos);
      v14 = v7 * v10[4];
      v22 = 0;
      v23.r = (float)(v14 * sBarLength) + xScreenPos;
      v20 = (float)(v14 * sBarLength) + xScreenPos;
      v21 = sBarThinkness + xScreenPos;
      v24 = *v13;
      UFG::DrawLineScreenSpace((UFG::qVector3 *)&v23, (UFG::qVector3 *)&v20, &v24);
      goto LABEL_10;
    }
  }
}

// File Line: 1044
// RVA: 0x3B6D30
void __fastcall getBoundFootTracks(SkeletalAnimation *anim, float time, MotionKey **track0, MotionKey **track1, int *period, bool animCycles)
{
  MotionKey **v6; // r14
  SkeletalAnimation *v7; // rbx
  __int64 v8; // rbp
  signed int v9; // er13
  unsigned int v10; // edi
  int v11; // er12
  unsigned int v12; // esi
  float v13; // xmm6_4
  signed __int64 v14; // r15
  char *v15; // rcx
  float *v16; // rbx
  int v17; // eax
  float v18; // xmm0_4
  MotionKey **v19; // rcx
  MotionKey *v20; // rcx
  int v21; // eax
  signed __int64 v22; // r15
  int v23; // esi
  signed __int64 v24; // rbx
  int v25; // eax
  int v26; // ebx
  int v27; // er14
  __int64 v28; // rsi
  __int64 v29; // rcx
  signed __int64 v30; // rdx
  __int64 v31; // rcx
  signed __int64 v32; // rbx
  int v33; // eax
  MotionKey **v34; // [rsp+80h] [rbp+18h]

  v34 = track0;
  v6 = track1;
  v7 = anim;
  v8 = ((__int64 (*)(void))anim->vfptr[1].Serialize)();
  if ( !v8 )
    return;
  v9 = -1;
  v10 = 0;
  v11 = -1;
  v12 = 0;
  v13 = SkeletalAnimation::GetDuration(v7);
  v14 = *(_QWORD *)(v8 + 24) + v8 + 24;
  if ( *(_DWORD *)(v8 + 16) & 0x7FFFFFFF )
  {
    do
    {
      v15 = (char *)(v14 + 8i64 * v12);
      v16 = (float *)&v15[*(_QWORD *)v15];
      if ( *v6 )
        break;
      v17 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v16 + 80i64))(&v15[*(_QWORD *)v15]);
      if ( v17 > 0 )
      {
        v18 = v16[4];
        if ( v18 >= v13 )
          v18 = v13;
        if ( v18 > time )
        {
          *v6 = (MotionKey *)v16;
        }
        else
        {
          *v34 = (MotionKey *)v16;
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
  v19 = v34;
  if ( !animCycles )
    goto LABEL_22;
  v20 = *v34;
  if ( !*v34 )
  {
    if ( *v6 )
    {
      v26 = *(_DWORD *)(v8 + 16) & 0x7FFFFFFF;
      v27 = ((__int64 (*)(void))(*v6)->vfptr[1].FindWithOldPath)();
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
          v32 = v31 + v30 + 8 * v28;
          if ( !v31 )
            v32 = 0i64;
          v33 = (*(__int64 (__fastcall **)(signed __int64))(*(_QWORD *)v32 + 80i64))(v32);
          if ( v33 > 0 && v27 != v33 )
            break;
          if ( --v28 < 0 )
            goto LABEL_21;
        }
        v19 = v34;
        *v34 = (MotionKey *)v32;
LABEL_22:
        v20 = *v19;
        if ( !v20 )
          return;
        goto LABEL_23;
      }
    }
LABEL_21:
    v19 = v34;
    goto LABEL_22;
  }
  if ( !*v6 )
  {
    v21 = ((__int64 (*)(void))v20->vfptr[1].FindWithOldPath)();
    v22 = *(_QWORD *)(v8 + 24) + v8 + 24;
    v23 = v21;
    if ( *(_DWORD *)(v8 + 16) & 0x7FFFFFFF )
    {
      while ( 1 )
      {
        v24 = v22 + 8i64 * v10 + *(_QWORD *)(v22 + 8i64 * v10);
        v25 = (*(__int64 (__fastcall **)(signed __int64))(*(_QWORD *)v24 + 80i64))(v24);
        if ( v25 > 0 && v23 != v25 )
          break;
        if ( ++v10 >= (*(_DWORD *)(v8 + 16) & 0x7FFFFFFFu) )
          goto LABEL_21;
      }
      *v6 = (MotionKey *)v24;
    }
    goto LABEL_21;
  }
LABEL_23:
  if ( ((unsigned int (*)(void))v20->vfptr[1].FindWithOldPath)() == 1 )
    v11 = v9;
  *period = v11;
}

// File Line: 1156
// RVA: 0x3B6F50
__int64 __fastcall getBoundFootTracksAtMotionPhase(SkeletalAnimation *anim, MotionPhase2 *motionPhase, MotionKey **track0, MotionKey **track1, bool animCycles)
{
  unsigned int v5; // esi
  MotionKey **v6; // rbx
  MotionKey **v7; // r13
  MotionPhase2 *v8; // r15
  SkeletalAnimation *v9; // rdi
  __int64 v10; // rbp
  unsigned int v11; // edi
  signed __int64 v12; // rcx
  unsigned int v13; // er14
  signed __int64 v14; // r12
  int v15; // eax
  signed __int64 v16; // r12
  signed __int64 v17; // r14
  MotionKey *v18; // rcx
  int v19; // ebx
  int v20; // er15
  __int64 v21; // r14
  __int64 v22; // rcx
  signed __int64 v23; // rdx
  __int64 v24; // rcx
  signed __int64 v25; // rbx
  int v26; // eax
  signed __int64 v28; // [rsp+58h] [rbp+10h]

  v5 = -1;
  v6 = track1;
  v7 = track0;
  v8 = motionPhase;
  v9 = anim;
  if ( motionPhase->mPhaseMark.mValue )
  {
    v10 = ((__int64 (*)(void))anim->vfptr[1].Serialize)();
    if ( v10 )
    {
      SkeletalAnimation::GetDuration(v9);
      v11 = 0;
      v12 = *(_QWORD *)(v10 + 24) + v10 + 24;
      v13 = 0;
      v28 = *(_QWORD *)(v10 + 24) + v10 + 24;
      if ( *(_DWORD *)(v10 + 16) & 0x7FFFFFFF )
      {
        do
        {
          v14 = v12 + 8i64 * v13 + *(_QWORD *)(v12 + 8i64 * v13);
          if ( v8->mPhaseMark.mValue == (*(unsigned int (__fastcall **)(signed __int64))(*(_QWORD *)v14 + 80i64))(v14) )
          {
            v15 = v8->mPhasePeriod;
            if ( v15 != v5 && (v15 == ++v5 || !v5) )
            {
              *v7 = (MotionKey *)v14;
              *v6 = 0i64;
            }
          }
          else if ( !*v6 && (v8->mPhasePeriod == v5 || !v5) )
          {
            *v6 = (MotionKey *)v14;
          }
          v12 = v28;
          ++v13;
        }
        while ( v13 < (*(_DWORD *)(v10 + 16) & 0x7FFFFFFFu) );
      }
      if ( animCycles )
      {
        if ( *v7 )
        {
          if ( !*v6 )
          {
            v16 = *(_QWORD *)(v10 + 24) + v10 + 24;
            if ( *(_DWORD *)(v10 + 16) & 0x7FFFFFFF )
            {
              while ( 1 )
              {
                v17 = v16 + 8i64 * v11 + *(_QWORD *)(v16 + 8i64 * v11);
                if ( v8->mPhaseMark.mValue != (*(unsigned int (__fastcall **)(signed __int64))(*(_QWORD *)v17 + 80i64))(v17) )
                  break;
                if ( ++v11 >= (*(_DWORD *)(v10 + 16) & 0x7FFFFFFFu) )
                  return v5;
              }
              *v6 = (MotionKey *)v17;
            }
          }
        }
        else
        {
          v18 = *v6;
          if ( *v6 )
          {
            v19 = *(_DWORD *)(v10 + 16) & 0x7FFFFFFF;
            v20 = ((__int64 (*)(void))v18->vfptr[1].FindWithOldPath)();
            v21 = v19 - 1;
            if ( v19 - 1 >= 0 )
            {
              while ( 1 )
              {
                v22 = *(_QWORD *)(v10 + 24);
                v23 = v22 ? v22 + v10 + 24 : 0i64;
                v24 = *(_QWORD *)(v23 + 8 * v21);
                v25 = v24 + v23 + 8 * v21;
                if ( !v24 )
                  v25 = 0i64;
                v26 = (*(__int64 (__fastcall **)(signed __int64))(*(_QWORD *)v25 + 80i64))(v25);
                if ( v26 > 0 && v20 != v26 )
                  break;
                if ( --v21 < 0 )
                  return v5;
              }
              *v7 = (MotionKey *)v25;
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
void __usercall getPhase(AnimationNode *child0@<rcx>, MotionPhase2 *motionPhase@<rdx>, float a3@<xmm0>)
{
  SkeletalAnimation *v3; // rsi
  int *period; // r14
  MotionPhase2 *v5; // rbx
  AnimationNode *v6; // rdi
  Expression::IMemberMapVtbl *v7; // rax
  float v8; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm7_4
  MotionKey *v11; // rdi
  MotionKey *v12; // rsi
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm6_4
  MotionKey *v18; // rdi
  unsigned int v19; // eax
  float v20; // xmm0_4
  MotionKey *track1; // [rsp+70h] [rbp+8h]
  MotionKey *track0; // [rsp+78h] [rbp+10h]

  v3 = child0->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  period = &motionPhase->mPhasePeriod;
  v5 = motionPhase;
  v6 = child0;
  motionPhase->mPhaseMark.mValue = 0;
  motionPhase->mPhasePeriod = 0;
  *(_QWORD *)&motionPhase->mPhase = 0i64;
  if ( v3 )
  {
    v7 = child0->vfptr;
    track0 = 0i64;
    track1 = 0i64;
    ((void (*)(void))v7[4].GetResourceOwner)();
    v8 = a3;
    v9 = SkeletalAnimation::GetDuration(v3);
    v10 = v9;
    getBoundFootTracks(v3, v8, &track0, &track1, period, v6->mPlayMode.mValue == 1);
    v11 = track0;
    if ( track0 )
    {
      v12 = track1;
      v5->mPhaseMark.mValue = ((__int64 (__fastcall *)(MotionKey *))track0->vfptr[1].FindWithOldPath)(track0);
      if ( !v12 )
      {
        *period = 0;
        return;
      }
      v13 = v12->mTimeBegin - v11->mTimeBegin;
      v5->mPhaseDuration = v13;
      if ( v13 < 0.0 )
      {
        v14 = v12->mTimeBegin;
        v5->mPhaseDuration = v14;
        v5->mPhaseDuration = (float)(v9 - v11->mTimeBegin) + v14;
      }
      v15 = v5->mPhaseDuration;
      if ( v15 > 0.000099999997 )
      {
        v5->mPhase = v8 / v15;
        if ( v8 <= v9 )
        {
          v16 = v11->mTimeBegin;
          if ( v8 < v16 )
          {
            v5->mPhase = (float)((float)(v10 - v16) + v8) / v15;
            return;
          }
          v17 = (float)(v8 - v16) / v15;
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
        v5->mPhaseMark.mValue = v19;
        if ( v19 == 1 || v19 == 2 )
          v5->mPhaseMark.mValue = 2;
        v20 = v18->mTimeBegin;
        v5->mPhaseDuration = v20;
        if ( v20 > 0.000099999997 )
        {
          v17 = v8 / v20;
LABEL_18:
          v5->mPhase = v17;
          return;
        }
      }
    }
  }
}

// File Line: 1338
// RVA: 0x3B81A0
void __fastcall setLocalTimeFromPhaseTracks(AnimationNode *pose, float relativeTrackWeight, MotionKey *track10, MotionKey *track11)
{
  AnimationNode *v4; // rbx
  SkeletalAnimation *v5; // rcx
  MotionKey *v6; // rdi
  MotionKey *v7; // rsi

  v4 = pose;
  v5 = pose->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  v6 = track11;
  v7 = track10;
  if ( v5 && track10 )
  {
    if ( track11 )
    {
      SkeletalAnimation::GetDuration(v5);
      v6->mTimeBegin;
      v7->mTimeBegin;
      ((void (__fastcall *)(AnimationNode *))v4->vfptr[3].GetResourcePath)(v4);
    }
  }
}

// File Line: 1413
// RVA: 0x3AC720
void __fastcall PhaseSync(PoseNode *pose0, PoseNode *pose1)
{
  PoseNode *v2; // rbx
  void **v3; // [rsp+28h] [rbp-30h]
  __int64 v4; // [rsp+30h] [rbp-28h]
  __int64 v5; // [rsp+38h] [rbp-20h]
  __int64 v6; // [rsp+40h] [rbp-18h]

  v2 = pose1;
  v4 = 0i64;
  v3 = &MotionPhase2::`vftable;
  v5 = 0i64;
  v6 = 0i64;
  pose0->vfptr[2].Serialize((Expression::IMemberMap *)pose0, (IActionTreeSerializer *)&v3);
  ((void (__fastcall *)(PoseNode *, void ***))v2->vfptr[2].GetClassNameUID)(v2, &v3);
}

// File Line: 1428
// RVA: 0x3AC5F0
void __fastcall PhaseMatch(PoseNode *pose0, PoseNode *pose1, float weight)
{
  PoseNode *v3; // rbx
  PoseNode *v4; // rdi
  void **v5; // [rsp+28h] [rbp-58h]
  __int64 v6; // [rsp+30h] [rbp-50h]
  __int64 v7; // [rsp+38h] [rbp-48h]
  __int64 v8; // [rsp+40h] [rbp-40h]
  void **v9; // [rsp+48h] [rbp-38h]
  __int64 v10; // [rsp+50h] [rbp-30h]
  __int64 v11; // [rsp+58h] [rbp-28h]
  __int64 v12; // [rsp+60h] [rbp-20h]

  v3 = pose1;
  v4 = pose0;
  v6 = 0i64;
  v5 = &MotionPhase2::`vftable;
  v7 = 0i64;
  v8 = 0i64;
  v10 = 0i64;
  v9 = &MotionPhase2::`vftable;
  v11 = 0i64;
  v12 = 0i64;
  pose0->vfptr[2].Serialize((Expression::IMemberMap *)pose0, (IActionTreeSerializer *)&v5);
  v3->vfptr[2].Serialize((Expression::IMemberMap *)&v3->vfptr, (IActionTreeSerializer *)&v9);
  if ( (_DWORD)v7 && (_DWORD)v11 )
  {
    ((void (__fastcall *)(PoseNode *, void ***))v3->vfptr[2].GetClassNameUID)(v3, &v5);
    ((void (__fastcall *)(PoseNode *))v4->vfptr[2].GetResourcePath)(v4);
    v3->vfptr[2].ResolveReferences((Expression::IMemberMap *)&v3->vfptr);
  }
  else if ( sDurationMatchOnPhaseMatch )
  {
    DurationMatch(v4, v3, weight, 1.0);
  }
}

// File Line: 1472
// RVA: 0x3A2D60
BlendNode *__fastcall PoseNode::BlendIn(PoseNode *this, PoseNode *newNode, float blendInTime, bool syncStart)
{
  bool v4; // di
  PoseNode *v5; // rsi
  PoseNode *v6; // rbx
  __int64 v7; // rax
  char *v8; // rax

  v4 = syncStart;
  v5 = newNode;
  v6 = this;
  v7 = this->mParent.mOffset;
  if ( !v7 || !(UFG::qOffset64<PoseNodeParent *> *)((char *)&this->mParent + v7) )
    return 0i64;
  v8 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB0ui64, "PoseNode.BlendIn", 0i64, 1u);
  if ( v8 )
    BlendNode::BlendNode((BlendNode *)v8, blendInTime);
  return PoseNode::BlendIn(v6, v5, (BlendNode *)v8, v4);
}

// File Line: 1488
// RVA: 0x3A2E10
BlendNode *__fastcall PoseNode::BlendIn(PoseNode *this, PoseNode *newNode, BlendNode *blendIn, bool syncStart)
{
  __int64 v4; // rax
  BlendNode *v5; // rbx
  PoseNode *v6; // rsi
  PoseNode *v7; // rdi
  char *v8; // rcx
  UFG::qNode<PoseNode,PoseNode> *v9; // rdx
  UFG::qNode<PoseNode,PoseNode> *v10; // rax

  v4 = this->mParent.mOffset;
  v5 = blendIn;
  v6 = newNode;
  v7 = this;
  if ( !v4 )
    return 0i64;
  v8 = (char *)&this->mParent + v4;
  if ( !v8 )
    return 0i64;
  blendIn->mSyncOnStart = syncStart;
  v9 = (UFG::qNode<PoseNode,PoseNode> *)&blendIn->mPrev;
  blendIn->mPriority = v7->mPriority;
  v10 = v7->mPrev;
  v10->mNext = (UFG::qNode<PoseNode,PoseNode> *)&blendIn->mPrev;
  v9->mPrev = v10;
  v9->mNext = (UFG::qNode<PoseNode,PoseNode> *)&v7->mPrev;
  v7->mPrev = (UFG::qNode<PoseNode,PoseNode> *)&blendIn->mPrev;
  blendIn->mParent.mOffset = v8 - (char *)&blendIn->mParent;
  (*(void (__fastcall **)(char *, PoseNode *))(*(_QWORD *)v8 + 384i64))(v8, v7);
  ((void (__fastcall *)(BlendNode *, PoseNode *))v5->vfptr[4].GetClassNameUID)(v5, v7);
  ((void (__fastcall *)(BlendNode *, PoseNode *))v5->vfptr[4].GetClassNameUID)(v5, v6);
  return v5;
}

// File Line: 1511
// RVA: 0x3B9BE0
void __fastcall PoseNode::writeDebugDisplayToString(PoseNode *this, UFG::qStringBuilder *debugStringBuilder, int indentSpaces, const char *parentInfo)
{
  PoseNode *v4; // rsi
  const char *v5; // rdi
  unsigned int v6; // ebp
  UFG::qStringBuilder *v7; // r14
  char *v8; // rbx
  __int64 v9; // rax

  v4 = this;
  v5 = &customWorldMapCaption;
  if ( parentInfo )
    v5 = parentInfo;
  v6 = indentSpaces;
  v7 = debugStringBuilder;
  v8 = UFG::qSymbol::as_cstr_dbg(&this->mName);
  v9 = (__int64)v4->vfptr->GetClassname((Expression::IMemberMap *)&v4->vfptr);
  UFG::qStringBuilder::Format(v7, "%*s%s:%s:%s\n", v6, &customWorldMapCaption, v9, v8, v5);
}

// File Line: 1523
// RVA: 0x3B9C70
void __fastcall PoseNodeParent::writeDebugDisplayToString(PoseNodeParent *this, UFG::qStringBuilder *debugStringBuilder, int indentSpaces, const char *parentInfo)
{
  int v4; // esi
  UFG::qStringBuilder *v5; // rbp
  PoseNodeParent *v6; // rdi
  UFG::qNode<PoseNode,PoseNode> *v7; // rbx
  unsigned int v8; // esi
  signed __int64 v9; // rdi
  UFG::qNode<PoseNode,PoseNode> **i; // rbx

  v4 = indentSpaces;
  v5 = debugStringBuilder;
  v6 = this;
  PoseNode::writeDebugDisplayToString((PoseNode *)&this->vfptr, debugStringBuilder, 0, parentInfo);
  v7 = v6->mChildren.mNode.mNext;
  v8 = sSpacesPerIndent_0 + v4;
  v9 = (signed __int64)&v6->mNetPoseSequence;
  for ( i = &v7[-3].mNext; i != (UFG::qNode<PoseNode,PoseNode> **)v9; i = &i[6][-3].mNext )
    ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, UFG::qStringBuilder *, _QWORD, _QWORD))(*i)[8].mNext)(
      i,
      v5,
      v8,
      0i64);
}

// File Line: 1537
// RVA: 0x3AB220
char __fastcall PoseNodeParent::IsFinished(PoseNodeParent *this, float inTimeDelta)
{
  int *v2; // rdi
  PoseNodeParent *v3; // rbx

  v2 = &this->mNetPoseSequence;
  v3 = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( v3 == (PoseNodeParent *)&this->mNetPoseSequence )
    return 1;
  while ( ((unsigned __int8 (__fastcall *)(PoseNodeParent *))v3->vfptr[1].SetResourceOwner)(v3) )
  {
    v3 = (PoseNodeParent *)&v3->mNext[-3].mNext;
    if ( v3 == (PoseNodeParent *)v2 )
      return 1;
  }
  return 0;
}

// File Line: 1551
// RVA: 0x3AA7B0
void __fastcall PoseNodeParent::HoldLastFrame(PoseNodeParent *this)
{
  int *v1; // rdi
  PoseNodeParent *v2; // rbx

  v1 = &this->mNetPoseSequence;
  v2 = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( v2 != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      v2->vfptr[1].GetResourceOwner((Expression::IMemberMap *)&v2->vfptr);
      v2 = (PoseNodeParent *)&v2->mNext[-3].mNext;
    }
    while ( v2 != (PoseNodeParent *)v1 );
  }
}

// File Line: 1560
// RVA: 0x3AF5C0
void __fastcall PoseNodeParent::SetPlayMode(PoseNodeParent *this, AnimationPlayMode mode)
{
  int *v2; // rdi
  AnimationPlayMode v3; // esi
  PoseNodeParent *v4; // rbx

  v2 = &this->mNetPoseSequence;
  v3 = mode;
  v4 = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( v4 != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      v4->vfptr[2].FindWithOldPath((Expression::IMemberMap *)&v4->vfptr, (const char *)(unsigned int)v3);
      v4 = (PoseNodeParent *)&v4->mNext[-3].mNext;
    }
    while ( v4 != (PoseNodeParent *)v2 );
  }
}

// File Line: 1569
// RVA: 0x3AC5A0
void __fastcall PoseNodeParent::Pause(PoseNodeParent *this)
{
  int *v1; // rdi
  PoseNodeParent *v2; // rbx

  v1 = &this->mNetPoseSequence;
  v2 = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( v2 != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      ((void (__fastcall *)(PoseNodeParent *))v2->vfptr[2].__vecDelDtor)(v2);
      v2 = (PoseNodeParent *)&v2->mNext[-3].mNext;
    }
    while ( v2 != (PoseNodeParent *)v1 );
  }
}

// File Line: 1578
// RVA: 0x3AE4B0
void __fastcall PoseNodeParent::Resume(PoseNodeParent *this)
{
  int *v1; // rdi
  PoseNodeParent *v2; // rbx

  v1 = &this->mNetPoseSequence;
  v2 = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( v2 != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      v2->vfptr[2].CreateClone((Expression::IMemberMap *)&v2->vfptr);
      v2 = (PoseNodeParent *)&v2->mNext[-3].mNext;
    }
    while ( v2 != (PoseNodeParent *)v1 );
  }
}

// File Line: 1605
// RVA: 0x3B0C40
__int64 __fastcall BlendDirectionNode::Update(BlendDirectionNode *this, float timeDelta, bool updateAnimation)
{
  bool v3; // di
  BlendDirectionNode *v4; // rbx
  __int64 v5; // rdx
  unsigned __int8 v6; // di

  v3 = updateAnimation;
  v4 = this;
  ((void (*)(void))this->vfptr[4].Serialize)();
  BlendDirectionNode::updateActiveDirection(v4, timeDelta);
  v4->mWeight = BlendDirectionNode::selectActive(v4, &v4->mChild0ID, &v4->mChild1ID);
  if ( sSyncBlendDirNode )
    v4->vfptr[5].ResolveReferences((Expression::IMemberMap *)&v4->vfptr);
  v6 = PoseNodeParent::Update((PoseNodeParent *)&v4->vfptr, timeDelta, v3, v5);
  if ( v4->mSetPhaseMatch )
    v4->vfptr[5].ResolveReferences((Expression::IMemberMap *)&v4->vfptr);
  return v6;
}

// File Line: 1637
// RVA: 0x3B7DD0
float __fastcall BlendDirectionNode::selectActive(BlendDirectionNode *this, int *child0ID, int *child1ID)
{
  signed int v3; // er9
  int *v4; // r14
  int *v5; // rsi
  BlendDirectionNode *v6; // rdi
  int v7; // ebp
  BlendDirectionNode *i; // rax
  float v9; // xmm8_4
  signed __int64 v10; // r11
  signed int v11; // ecx
  float *v12; // rdx
  unsigned __int64 v13; // r8
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  signed __int64 v21; // r10
  float *v22; // rax
  float v23; // xmm1_4
  __int64 v24; // rbx
  float v25; // xmm10_4
  float v26; // xmm11_4
  float v27; // xmm6_4
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
  v4 = child1ID;
  *child0ID = 0;
  *child1ID = 1;
  v5 = child0ID;
  v6 = this;
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
    v12 = &v6->mDirections[1];
    v13 = ((unsigned __int64)(v7 - 4i64) >> 2) + 1;
    v10 = 4 * v13;
    do
    {
      if ( v3 < 8 )
      {
        v14 = *(v12 - 1);
        if ( v14 >= 0.0 )
        {
          LODWORD(v15) = COERCE_UNSIGNED_INT(v14 - v6->mActiveDirection) & _xmm;
          if ( v15 > 6.2831855 )
            v15 = v15 + -6.2831855;
          if ( v15 > 3.1415927 )
            v15 = 6.2831855 - v15;
          if ( v15 < v9 )
          {
            v9 = v15;
            *v5 = v3;
          }
        }
      }
      if ( v11 - 1 < 8 && *v12 >= 0.0 )
      {
        LODWORD(v16) = COERCE_UNSIGNED_INT(*v12 - v6->mActiveDirection) & _xmm;
        if ( v16 > 6.2831855 )
          v16 = v16 + -6.2831855;
        if ( v16 > 3.1415927 )
          v16 = 6.2831855 - v16;
        if ( v16 < v9 )
        {
          v9 = v16;
          *v5 = v11 - 1;
        }
      }
      if ( v11 < 8 )
      {
        v17 = v12[1];
        if ( v17 >= 0.0 )
        {
          LODWORD(v18) = COERCE_UNSIGNED_INT(v17 - v6->mActiveDirection) & _xmm;
          if ( v18 > 6.2831855 )
            v18 = v18 + -6.2831855;
          if ( v18 > 3.1415927 )
            v18 = 6.2831855 - v18;
          if ( v18 < v9 )
          {
            v9 = v18;
            *v5 = v11;
          }
        }
      }
      if ( v11 + 1 < 8 )
      {
        v19 = v12[2];
        if ( v19 >= 0.0 )
        {
          LODWORD(v20) = COERCE_UNSIGNED_INT(v19 - v6->mActiveDirection) & _xmm;
          if ( v20 > 6.2831855 )
            v20 = v20 + -6.2831855;
          if ( v20 > 3.1415927 )
            v20 = 6.2831855 - v20;
          if ( v20 < v9 )
          {
            v9 = v20;
            *v5 = v11 + 1;
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
    v22 = &v6->mDirections[v10];
    do
    {
      if ( v3 < 8 && *v22 >= 0.0 )
      {
        LODWORD(v23) = COERCE_UNSIGNED_INT(*v22 - v6->mActiveDirection) & _xmm;
        if ( v23 > 6.2831855 )
          v23 = v23 + -6.2831855;
        if ( v23 > 3.1415927 )
          v23 = 6.2831855 - v23;
        if ( v23 < v9 )
        {
          v9 = v23;
          *v5 = v3;
        }
      }
      ++v3;
      ++v22;
      --v21;
    }
    while ( v21 );
  }
  v24 = *v5;
  v25 = FLOAT_N1_0;
  if ( (signed int)v24 >= 8 )
    v26 = FLOAT_N1_0;
  else
    v26 = v6->mDirections[v24];
  v27 = v6->mActiveDirection;
  v28 = cosf(v6->mActiveDirection);
  v29 = v28 * sinf(v26);
  v30 = sinf(v27);
  if ( (float)(v29 - (float)(v30 * cosf(v26))) > 0.0 )
  {
    *v4 = v24 - 1;
    if ( (signed int)v24 - 1 < 0 )
      *v4 = v7 - 1;
  }
  else
  {
    *v4 = ((signed int)v24 + 1) % v7;
  }
  v31 = *v5;
  if ( (signed int)v31 >= 8 )
    v32 = FLOAT_N1_0;
  else
    v32 = v6->mDirections[v31];
  v33 = *v4;
  if ( (signed int)v33 < 8 )
    v25 = v6->mDirections[v33];
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
void __fastcall BlendDirectionNode::writeDebugDisplayToString(BlendDirectionNode *this, UFG::qStringBuilder *debugStringBuilder, int indentSpaces, const char *parentInfo)
{
  float v4; // xmm6_4
  BlendDirectionNode *v5; // rsi
  const char *v6; // rdi
  unsigned int v7; // ebp
  UFG::qStringBuilder *v8; // r14
  char *v9; // rbx
  __int64 v10; // rax
  unsigned int v11; // ebp
  float v12; // xmm0_4
  UFG::qNode<PoseNode,PoseNode> *v13; // rbx
  UFG::qNode<PoseNode,PoseNode> **v14; // rbx
  signed __int64 v15; // rsi
  float *v16; // rdi
  int dest[8]; // [rsp+40h] [rbp-88h]
  char v18; // [rsp+60h] [rbp-68h]
  int child1ID; // [rsp+D0h] [rbp+8h]
  int child0ID; // [rsp+E0h] [rbp+18h]

  v4 = this->mActiveDirection;
  v5 = this;
  v6 = &customWorldMapCaption;
  v7 = indentSpaces;
  if ( parentInfo )
    v6 = parentInfo;
  v8 = debugStringBuilder;
  v9 = UFG::qSymbol::as_cstr_dbg(&this->mName);
  v10 = (__int64)v5->vfptr->GetClassname((Expression::IMemberMap *)&v5->vfptr);
  UFG::qStringBuilder::Format(v8, "%*s%s:%s:Dir:%0.3f:%s\n", v7, &customWorldMapCaption, v10, v9, v4, v6);
  v11 = sSpacesPerIndent_0 + v7;
  v12 = BlendDirectionNode::selectActive(v5, &child0ID, &child1ID);
  UFG::qMemSet(dest, 0, 0x20u);
  v13 = v5->mChildren.mNode.mNext;
  *(float *)&dest[child0ID] = 1.0 - v12;
  v14 = &v13[-3].mNext;
  v15 = (signed __int64)&v5->mNetPoseSequence;
  *(float *)&dest[child1ID] = v12;
  if ( v14 != (UFG::qNode<PoseNode,PoseNode> **)v15 )
  {
    v16 = (float *)dest;
    do
    {
      UFG::qSPrintf(&v18, "w:%0.3f", *v16);
      ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, UFG::qStringBuilder *, _QWORD, char *))(*v14)[8].mNext)(
        v14,
        v8,
        v11,
        &v18);
      ++v16;
      v14 = &v14[6][-3].mNext;
    }
    while ( v14 != (UFG::qNode<PoseNode,PoseNode> **)v15 );
  }
}

// File Line: 1752
// RVA: 0x3A89C0
void __fastcall BlendDirectionNode::GetExtractedDeltaReferenceFrame(BlendDirectionNode *this, float deltaTime, hkQsTransformf *deltaMotionOut)
{
  signed __int64 v3; // rdx
  UFG::qNode<PoseNode,PoseNode> **v4; // rbx
  BlendDirectionNode *v5; // rdi
  hkQsTransformf *v6; // rsi
  int *i; // rcx
  int v8; // eax
  __int64 v9; // rdx
  __m128 v10; // xmm4
  __m128 v11; // xmm0
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm5
  __m128 v15; // xmm0
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // [rsp+20h] [rbp-78h]
  __m128 v20; // [rsp+30h] [rbp-68h]
  __m128 v21; // [rsp+40h] [rbp-58h]
  __m128 v22; // [rsp+50h] [rbp-48h]
  __m128 v23; // [rsp+60h] [rbp-38h]
  __m128 v24; // [rsp+70h] [rbp-28h]

  v3 = (unsigned int)this->mChild0ID;
  v4 = &this->mChildren.mNode.mNext[-3].mNext;
  v5 = this;
  v6 = deltaMotionOut;
  for ( i = (int *)&this->mChildren.mNode.mNext[-3].mNext; (signed int)v3 > 0; i = (int *)(*((_QWORD *)i + 6) - 40i64) )
  {
    if ( i == &v5->mNetPoseSequence )
      break;
    v3 = (unsigned int)(v3 - 1);
  }
  v8 = v5->mChild1ID;
  if ( v8 > 0 )
  {
    v3 = (signed __int64)&v5->mNetPoseSequence;
    do
    {
      if ( v4 == (UFG::qNode<PoseNode,PoseNode> **)v3 )
        break;
      --v8;
      v4 = &v4[6][-3].mNext;
    }
    while ( v8 > 0 );
  }
  (*(void (__fastcall **)(int *, signed __int64, __m128 *))(*(_QWORD *)i + 128i64))(i, v3, &v22);
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, __int64, __m128 *))(*v4)[8].mPrev)(v4, v9, &v19);
  v10 = _mm_shuffle_ps((__m128)LODWORD(v5->mWeight), (__m128)LODWORD(v5->mWeight), 0);
  v11 = _mm_mul_ps(v20, v23);
  v12 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v19, v22), v10), v22);
  v6->m_scale.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v21, v24), v10), v24);
  v13 = _mm_add_ps(_mm_shuffle_ps(v11, v11, 78), v11);
  v6->m_translation.m_quad = v12;
  v14 = _mm_add_ps(
          _mm_mul_ps(
            _mm_xor_ps(
              (__m128)_mm_slli_epi32(
                        _mm_srli_epi32(
                          (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 177), v13), (__m128)0i64),
                          0x1Fu),
                        0x1Fu),
              v10),
            v20),
          _mm_mul_ps(_mm_sub_ps(query.m_quad, v10), v23));
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 78), v15);
  v17 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 177), v16);
  v18 = _mm_rsqrt_ps(v17);
  v6->m_rotation.m_vec.m_quad = _mm_mul_ps(
                                  v14,
                                  _mm_mul_ps(
                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                                    _mm_mul_ps(*(__m128 *)_xmm, v18)));
}

// File Line: 1769
// RVA: 0x3A9110
float __fastcall BlendDirectionNode::GetPhase(BlendDirectionNode *this, float futureTimeDelta)
{
  BlendDirectionNode *v2; // rbx
  float result; // xmm0_4
  int v4; // eax
  int *i; // rcx
  int child0ID; // [rsp+40h] [rbp+8h]
  int child1ID; // [rsp+50h] [rbp+18h]

  v2 = this;
  child0ID = 0;
  child1ID = 1;
  result = BlendDirectionNode::selectActive(this, &child0ID, &child1ID);
  v4 = child0ID;
  for ( i = (int *)&v2->mChildren.mNode.mNext[-3].mNext; v4 > 0; i = (int *)(*((_QWORD *)i + 6) - 40i64) )
  {
    if ( i == &v2->mNetPoseSequence )
      break;
    --v4;
  }
  (*(void (**)(void))(*(_QWORD *)i + 192i64))();
  return result;
}

// File Line: 1780
// RVA: 0x3A8200
float __fastcall BlendDirectionNode::GetDuration(BlendDirectionNode *this)
{
  BlendDirectionNode *v1; // rbx
  float result; // xmm0_4
  int v3; // eax
  int *i; // rcx
  int child0ID; // [rsp+30h] [rbp+8h]
  int child1ID; // [rsp+38h] [rbp+10h]

  v1 = this;
  child0ID = 0;
  child1ID = 1;
  result = BlendDirectionNode::selectActive(this, &child0ID, &child1ID);
  v3 = child0ID;
  for ( i = (int *)&v1->mChildren.mNode.mNext[-3].mNext; v3 > 0; i = (int *)(*((_QWORD *)i + 6) - 40i64) )
  {
    if ( i == &v1->mNetPoseSequence )
      break;
    --v3;
  }
  (*(void (**)(void))(*(_QWORD *)i + 224i64))();
  return result;
}

// File Line: 1791
// RVA: 0x3A9180
void __fastcall BlendDirectionNode::GetPhase(BlendDirectionNode *this, MotionPhase2 *motionPhase)
{
  BlendDirectionNode *v2; // rdi
  MotionPhase2 *v3; // rbx
  signed int v4; // er8
  BlendDirectionNode *v5; // rax
  __int64 v6; // rax
  int child0ID; // [rsp+30h] [rbp+8h]
  int child1ID; // [rsp+40h] [rbp+18h]

  v2 = this;
  v3 = motionPhase;
  v4 = 0;
  v5 = (BlendDirectionNode *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( v5 == (BlendDirectionNode *)&this->mNetPoseSequence )
    goto LABEL_8;
  do
  {
    ++v4;
    v5 = (BlendDirectionNode *)&v5->mNext[-3].mNext;
  }
  while ( v5 != (BlendDirectionNode *)&this->mNetPoseSequence );
  if ( v4 < 2 )
  {
LABEL_8:
    *(_QWORD *)&motionPhase->mPhaseMark.mValue = 0i64;
    *(_QWORD *)&motionPhase->mPhase = 0i64;
  }
  else
  {
    child0ID = 0;
    child1ID = 1;
    BlendDirectionNode::selectActive(this, &child0ID, &child1ID);
    v6 = (__int64)v2->vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v2->vfptr, child0ID);
    (*(void (__fastcall **)(__int64, MotionPhase2 *))(*(_QWORD *)v6 + 184i64))(v6, v3);
  }
}

// File Line: 1808
// RVA: 0x3AF550
void __fastcall BlendPhaseNode::SetPhase(BlendPhaseNode *this, MotionPhase2 *motionPhase)
{
  int *v2; // rdi
  MotionPhase2 *v3; // rsi
  BlendPhaseNode *v4; // rbx

  v2 = &this->mNetPoseSequence;
  v3 = motionPhase;
  v4 = (BlendPhaseNode *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( v4 != (BlendPhaseNode *)&this->mNetPoseSequence )
  {
    do
    {
      ((void (__fastcall *)(BlendPhaseNode *, MotionPhase2 *))v4->vfptr[2].GetClassNameUID)(v4, v3);
      v4 = (BlendPhaseNode *)&v4->mNext[-3].mNext;
    }
    while ( v4 != (BlendPhaseNode *)v2 );
  }
}

// File Line: 1817
// RVA: 0x3AA690
MotionPhase2 *__fastcall BlendDirectionNode::Get_MotionPhase(BlendDirectionNode *this)
{
  MotionPhase2 *v1; // rbx
  BlendDirectionNode *v2; // rdi
  BlendDirectionNode *v3; // rax
  signed int v4; // edx
  __int64 v5; // rax
  int child0ID; // [rsp+30h] [rbp+8h]
  int child1ID; // [rsp+38h] [rbp+10h]

  v1 = &this->mMotionPhase;
  v2 = this;
  *(_QWORD *)&v1->mPhaseMark.mValue = 0i64;
  *(_QWORD *)&v1->mPhase = 0i64;
  v3 = (BlendDirectionNode *)&this->mChildren.mNode.mNext[-3].mNext;
  v4 = 0;
  if ( v3 != (BlendDirectionNode *)&this->mNetPoseSequence )
  {
    do
    {
      ++v4;
      v3 = (BlendDirectionNode *)&v3->mNext[-3].mNext;
    }
    while ( v3 != (BlendDirectionNode *)&this->mNetPoseSequence );
    if ( v4 >= 2 )
    {
      child0ID = 0;
      child1ID = 1;
      BlendDirectionNode::selectActive(this, &child0ID, &child1ID);
      v5 = (__int64)v2->vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v2->vfptr, child0ID);
      (*(void (__fastcall **)(__int64, MotionPhase2 *))(*(_QWORD *)v5 + 184i64))(v5, v1);
    }
  }
  return v1;
}

// File Line: 1838
// RVA: 0x3AF6A0
void __fastcall BlendPhaseNode::SetRateWeight0(BlendPhaseNode *this, float animLength0, float animLength1, float weight)
{
  int *v4; // rdi
  BlendPhaseNode *v5; // rbx

  v4 = &this->mNetPoseSequence;
  v5 = (BlendPhaseNode *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( v5 != (BlendPhaseNode *)&this->mNetPoseSequence )
  {
    do
    {
      ((void (__fastcall *)(BlendPhaseNode *))v5->vfptr[2].GetResourcePath)(v5);
      v5 = (BlendPhaseNode *)&v5->mNext[-3].mNext;
    }
    while ( v5 != (BlendPhaseNode *)v4 );
  }
}

// File Line: 1847
// RVA: 0x3AF760
void __fastcall BlendPhaseNode::SetRateWeight1(BlendPhaseNode *this, float animLength0, float animLength1, float weight)
{
  int *v4; // rdi
  BlendPhaseNode *v5; // rbx

  v4 = &this->mNetPoseSequence;
  v5 = (BlendPhaseNode *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( v5 != (BlendPhaseNode *)&this->mNetPoseSequence )
  {
    do
    {
      v5->vfptr[2].ResolveReferences((Expression::IMemberMap *)&v5->vfptr);
      v5 = (BlendPhaseNode *)&v5->mNext[-3].mNext;
    }
    while ( v5 != (BlendPhaseNode *)v4 );
  }
}

// File Line: 1856
// RVA: 0x3AED60
void __fastcall BlendDirectionNode::SetActiveDirection(BlendDirectionNode *this, float activeDirection, bool force)
{
  bool v3; // di
  BlendDirectionNode *v4; // rbx
  float v5; // xmm0_4
  float v6; // xmm2_4

  v3 = force;
  v4 = this;
  v5 = BlendDirectionNode::getLimitedActiveAngle(this, activeDirection);
  v4->mDesiredActiveDirection = v5;
  v6 = v5 - activeDirection;
  if ( (float)(v5 - activeDirection) < 0.0 )
    LODWORD(v6) ^= _xmm[0];
  if ( v6 < 0.001 && v3 )
    v4->mActiveDirection = v5;
}

// File Line: 1874
// RVA: 0x3B7190
float __fastcall BlendDirectionNode::getLimitedActiveAngle(BlendDirectionNode *this, float inputAngle)
{
  __int64 v2; // rax
  __int64 v3; // rdx
  float v4; // xmm2_4
  float v5; // xmm0_4
  signed int v6; // er8
  signed int v7; // edx
  unsigned __int16 v8; // r10
  signed int v9; // eax

  v2 = this->mLimitIndexCW;
  if ( (signed int)v2 < 0 )
    return inputAngle;
  v3 = this->mLimitIndexCCW;
  if ( (signed int)v3 < 0 )
    return inputAngle;
  v4 = FLOAT_N1_0;
  if ( (signed int)v2 >= 8 )
    v5 = FLOAT_N1_0;
  else
    v5 = this->mDirections[v2];
  v6 = (signed int)(float)((float)(v5 * 32768.0) * 0.31830987);
  if ( (signed int)v3 < 8 )
    v4 = this->mDirections[v3];
  v7 = (signed int)(float)((float)(v4 * 32768.0) * 0.31830987);
  v8 = (signed int)(float)((float)(inputAngle * 32768.0) * 0.31830987) - v7;
  if ( v8 <= (unsigned __int16)(v6 - v7) )
    return inputAngle;
  if ( v8 >= (signed int)((unsigned __int16)(v6 - v7) + ((unsigned int)(unsigned __int16)(v7 - v6) >> 1)) )
    v9 = (unsigned __int16)v7;
  else
    v9 = (unsigned __int16)v6;
  return (float)((float)v9 * 3.1415927) * 0.000030517578;
}

// File Line: 1914
// RVA: 0x3B8340
void __fastcall BlendDirectionNode::updateActiveDirection(BlendDirectionNode *this, float timeDelta)
{
  float v2; // xmm6_4
  BlendDirectionNode *v3; // rbx
  float v4; // xmm9_4
  float v5; // xmm7_4
  float v6; // xmm11_4
  float v7; // xmm12_4
  float v8; // xmm8_4
  float v9; // xmm6_4
  float v10; // xmm10_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm8_4
  int v15; // xmm1_4
  float v16; // xmm7_4
  __int64 v17; // rax
  __int64 v18; // rax

  v2 = this->mDesiredActiveDirection;
  v3 = this;
  v4 = this->mActiveDirection;
  v5 = this->mActiveDirection;
  v6 = cosf(this->mDesiredActiveDirection);
  v7 = sinf(v2);
  v8 = cosf(v5);
  v9 = FLOAT_N1_0;
  v10 = sinf(v5);
  v11 = (float)(v10 * v7) + (float)(v8 * v6);
  if ( v11 <= -1.0 )
  {
    v11 = FLOAT_N1_0;
    goto LABEL_5;
  }
  v12 = *(float *)&FLOAT_1_0;
  if ( v11 < 1.0 )
LABEL_5:
    v12 = v11;
  v13 = acosf(v12);
  v14 = (float)(v8 * v7) - (float)(v10 * v6);
  *(float *)&v15 = v13;
  if ( v14 < 0.0 )
    v15 = LODWORD(v13) ^ _xmm[0];
  v16 = v5 + (float)(sChangeErrorsGain * *(float *)&v15);
  if ( v16 >= 6.2831855 )
    v16 = v16 + -6.2831855;
  if ( v16 < 0.0 )
    v16 = v16 + 6.2831855;
  if ( v14 < 0.0 )
  {
    v18 = v3->mLimitIndexCCW;
    if ( (signed int)v18 >= 0 )
    {
      if ( (signed int)v18 < 8 )
        v9 = v3->mDirections[v18];
      if ( v9 > v16 && v4 >= v9 )
        goto LABEL_18;
    }
  }
  else
  {
    v17 = v3->mLimitIndexCW;
    if ( (signed int)v17 >= 0 )
    {
      if ( (signed int)v17 < 8 )
        v9 = v3->mDirections[v17];
      if ( v16 > v9 && v4 <= v9 )
      {
LABEL_18:
        v3->mActiveDirection = v9;
        return;
      }
    }
  }
  v3->mActiveDirection = v16;
}

// File Line: 1977
// RVA: 0x3B8BC0
void __fastcall BlendDirectionNode::updateOperation(BlendDirectionNode *this)
{
  float v1; // xmm6_4
  BlendDirectionNode *v2; // rbx
  float v3; // xmm0_4
  int v4; // er8
  PoseNode *v5; // rdx
  PoseNode *i; // rcx
  int j; // eax
  Expression::IMemberMapVtbl *v8; // rax
  Expression::IMemberMapVtbl *v9; // rax
  void **v10; // [rsp+30h] [rbp-38h]
  char v11; // [rsp+38h] [rbp-30h]
  float v12; // [rsp+40h] [rbp-28h]
  int v13; // [rsp+44h] [rbp-24h]
  float v14; // [rsp+48h] [rbp-20h]
  char v15; // [rsp+4Ch] [rbp-1Ch]
  int child0ID; // [rsp+70h] [rbp+8h]
  int child1ID; // [rsp+78h] [rbp+10h]

  v1 = this->mPlayRate;
  v2 = this;
  if ( this->mDurationMatch )
  {
    *(float *)&child0ID = 0.0;
    child1ID = 1;
    v3 = BlendDirectionNode::selectActive(this, &child0ID, &child1ID);
    v4 = child0ID;
    v5 = (PoseNode *)&v2->mChildren.mNode.mNext[-3].mNext;
    for ( i = (PoseNode *)&v2->mChildren.mNode.mNext[-3].mNext; v4 > 0; i = (PoseNode *)&i->mNext[-3].mNext )
    {
      if ( i == (PoseNode *)&v2->mNetPoseSequence )
        break;
      --v4;
    }
    for ( j = child1ID; j > 0; v5 = (PoseNode *)&v5->mNext[-3].mNext )
    {
      if ( v5 == (PoseNode *)&v2->mNetPoseSequence )
        break;
      --j;
    }
    if ( GetWeightedDurationAndParametricTime(i, v5, v3, (float *)&child1ID, v3, (float *)&child0ID) )
    {
      v10 = &AnimationNode_SetLocalTimeParametric::`vftable;
      v8 = v2->vfptr;
      v12 = *(float *)&child0ID;
      v13 = child1ID;
      v14 = v1;
      v15 = 1;
      v11 = 1;
      v8[1].FindWithOldPath((Expression::IMemberMap *)&v2->vfptr, (const char *)&v10);
    }
  }
  else
  {
    v12 = this->mPlayRate;
    v10 = &AnimationNode_SetPlayRate::`vftable;
    v9 = this->vfptr;
    v11 = 1;
    v9[1].FindWithOldPath((Expression::IMemberMap *)&this->vfptr, (const char *)&v10);
  }
}

// File Line: 2014
// RVA: 0x3AF120
void __usercall BlendDirectionNode::SetDesiredExtractedMotionSpeed(BlendDirectionNode *this@<rcx>, float extractedSpeed@<xmm1>, float a3@<xmm0>)
{
  int *v3; // rsi
  BlendDirectionNode *v4; // rbx
  BlendDirectionNode *v5; // rdi

  v3 = &this->mNetPoseSequence;
  v4 = (BlendDirectionNode *)&this->mChildren.mNode.mNext[-3].mNext;
  v5 = this;
  if ( v4 != (BlendDirectionNode *)&this->mNetPoseSequence )
  {
    do
    {
      ((void (__fastcall *)(BlendDirectionNode *))v4->vfptr[3].FindWithOldPath)(v4);
      ((void (__fastcall *)(BlendDirectionNode *))v4->vfptr[3].SetResourceOwner)(v4);
      v5->mPlayRate = a3;
      v4 = (BlendDirectionNode *)&v4->mNext[-3].mNext;
    }
    while ( v4 != (BlendDirectionNode *)v3 );
  }
}

// File Line: 2030
// RVA: 0x3A2AC0
void __fastcall BlendNode::Begin(BlendNode *this)
{
  BlendNode *v1; // rdx
  bool v2; // zf
  UFG::qNode<PoseNode,PoseNode> *v3; // rcx
  __int64 v4; // rax
  void **v5; // [rsp+20h] [rbp-28h]
  char v6; // [rsp+28h] [rbp-20h]
  char v7; // [rsp+30h] [rbp-18h]
  int v8; // [rsp+34h] [rbp-14h]
  __int64 v9; // [rsp+38h] [rbp-10h]

  v1 = this;
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
          v3 = this->mChildren.mNode.mNext;
          v7 = 1;
          v5 = &PoseNode_SetPauseBlend::`vftable;
          v8 = v1->mPriority;
          v4 = (__int64)v1->mWeightSet;
          v6 = 0;
          v9 = v4;
          ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, void ***))v3[-3].mNext[5].mPrev)(&v3[-3].mNext, &v5);
        }
      }
    }
  }
}

// File Line: 2061
// RVA: 0x3B0CE0
bool __fastcall BlendNode::Update(BlendNode *this, float timeDelta, bool updateAnimation)
{
  bool v3; // bp
  BlendNode *v4; // rbx
  __int64 v5; // rdx
  __int64 v6; // rax
  signed __int64 v7; // rax
  __int64 v8; // rcx
  float v9; // xmm2_4
  float v10; // xmm0_4
  UFG::qNode<PoseNode,PoseNode> *v11; // rdi
  UFG::qNode<PoseNode,PoseNode> *v12; // rsi
  PoseNode *v13; // rdi
  PoseNode *v14; // rsi
  Expression::IMemberMapVtbl *v15; // rax
  void **v17; // [rsp+20h] [rbp-88h]
  char v18; // [rsp+28h] [rbp-80h]
  void **v19; // [rsp+30h] [rbp-78h]
  char v20; // [rsp+38h] [rbp-70h]
  char dest; // [rsp+40h] [rbp-68h]
  void **v22; // [rsp+60h] [rbp-48h]
  char v23; // [rsp+68h] [rbp-40h]
  char v24; // [rsp+70h] [rbp-38h]

  v3 = updateAnimation;
  v4 = this;
  ((void (*)(void))this->vfptr[1].GetClassname)();
  if ( !v4->mPauseBlend )
    goto LABEL_23;
  v6 = v4->mParent.mOffset;
  if ( v6 )
  {
    v7 = (signed __int64)&v4->mParent + v6;
    if ( v7 )
    {
      v8 = *(_QWORD *)(v7 + 56);
      if ( !v8 || !(v8 + v7 + 56) )
        v4->mPauseBlend = 0;
    }
  }
  if ( !v4->mPauseBlend )
  {
LABEL_23:
    v9 = v4->mBlendRate;
    if ( v9 != 0.0 )
    {
      v10 = (float)(v9 * timeDelta) + v4->mBlendParam;
      v4->mBlendParam = v10;
      if ( v9 <= 0.0 )
      {
        if ( v10 <= 0.0 )
          v4->mBlendParam = 0.0;
      }
      else if ( v10 > 1.0 )
      {
        v4->mBlendParam = 1.0;
      }
    }
  }
  if ( v4->mSyncOnStart )
  {
    v11 = v4->mChildren.mNode.mNext;
    v12 = v11->mNext;
    v13 = (PoseNode *)&v11[-3].mNext;
    v4->mSyncOnStart = 0;
    v14 = (PoseNode *)&v12[-3].mNext;
    if ( v14 )
    {
      PhaseSync(v13, v14);
      v17 = &AnimationNode_UpdateLastPlayTime::`vftable;
      v15 = v14->vfptr;
      v18 = 1;
      v15[1].FindWithOldPath((Expression::IMemberMap *)&v14->vfptr, (const char *)&v17);
      if ( sSyncBlendDirection )
      {
        v20 = 1;
        v19 = &BlendDirectionNode_GetBlendDirection::`vftable;
        UFG::qMemSet(&dest, 0, 0x20u);
        v13->vfptr[1].FindWithOldPath((Expression::IMemberMap *)&v13->vfptr, (const char *)&v19);
        v22 = &BlendDirectionNode_SetBlendDirection::`vftable;
        v23 = 1;
        UFG::qMemCopy(&v24, &dest, 0x20u);
        v14->vfptr[1].FindWithOldPath((Expression::IMemberMap *)&v14->vfptr, (const char *)&v22);
      }
      if ( sUnpausePhasedSyncedBranch )
        v13->vfptr[2].CreateClone((Expression::IMemberMap *)&v13->vfptr);
    }
  }
  PoseNodeParent::Update((PoseNodeParent *)&v4->vfptr, timeDelta, v3, v5);
  v4->vfptr[5].GetClassNameUID((Expression::IMemberMap *)&v4->vfptr);
  return BlendNode::updateOperationPost(v4);
}

// File Line: 2143
// RVA: 0x3B8D60
char __fastcall BlendNode::updateOperationPost(BlendNode *this)
{
  BlendNode *v1; // r8
  __int64 v2; // rax
  signed int v3; // eax
  BlendNode *v4; // rdx
  UFG::qNode<PoseNode,PoseNode> *v5; // rax
  UFG::qNode<PoseNode,PoseNode> *v6; // rcx
  UFG::qNode<PoseNode,PoseNode> *v7; // r9
  __int64 v8; // rax
  _QWORD *v9; // rdx
  signed __int64 v10; // rax
  signed __int64 v11; // rax
  UFG::qNode<PoseNode,PoseNode> *v12; // rax
  __int64 v14; // rax
  UFG::qNode<PoseNode,PoseNode> *v15; // rdx
  UFG::qNode<PoseNode,PoseNode> *v16; // rax
  UFG::qNode<PoseNode,PoseNode> *v17; // rcx
  __int64 v18; // rax
  signed __int64 v19; // rax
  UFG::qNode<PoseNode,PoseNode> *v20; // rcx
  int v21; // eax
  __int64 v22; // rax
  void **v23; // [rsp+20h] [rbp-28h]
  char v24; // [rsp+28h] [rbp-20h]
  char v25; // [rsp+30h] [rbp-18h]
  int v26; // [rsp+34h] [rbp-14h]
  __int64 v27; // [rsp+38h] [rbp-10h]

  v1 = this;
  if ( !this->mKeepBlend )
  {
    if ( this->mBlendRate <= 0.0 )
    {
      if ( 0.0 == this->mBlendParam )
      {
        v14 = this->mParent.mOffset;
        if ( v14 )
        {
          if ( (UFG::qOffset64<PoseNodeParent *> *)((char *)&this->mParent + v14) )
          {
            if ( PoseNode::sSimPauseOnBranchFinish )
            {
              UFG::Metrics::msInstance.mSimPausedDebug = 1;
              UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
            }
            v15 = this->mChildren.mNode.mNext;
            v7 = v15;
            v16 = v15->mNext;
            v17 = v15->mPrev;
            v17->mNext = v16;
            v16->mPrev = v17;
            v15->mPrev = v15;
            v15->mNext = v15;
            v18 = v1->mParent.mOffset;
            v9 = &v15[1].mPrev;
            if ( v18 )
            {
              v19 = (signed __int64)&v1->mParent + v18;
              if ( v19 )
              {
                v11 = v19 - (_QWORD)v9;
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
          v4 = (BlendNode *)&this->mChildren.mNode.mNext[-3].mNext;
          do
          {
            if ( v4 == (BlendNode *)&this->mNetPoseSequence )
              break;
            --v3;
            v4 = (BlendNode *)&v4->mNext[-3].mNext;
          }
          while ( v3 > 0 );
          v5 = v4->mNext;
          v6 = v4->mPrev;
          v7 = (UFG::qNode<PoseNode,PoseNode> *)&v4->mPrev;
          v6->mNext = v5;
          v5->mPrev = v6;
          v7->mPrev = v7;
          v7->mNext = v7;
          v8 = v1->mParent.mOffset;
          v9 = &v4->mParent.mOffset;
          if ( v8 )
          {
            v10 = (signed __int64)&v1->mParent + v8;
            if ( v10 )
            {
              v11 = v10 - (_QWORD)v9;
LABEL_15:
              *v9 = v11;
              v12 = v1->mPrev;
              v12->mNext = v7;
              v7->mPrev = v12;
              v7->mNext = (UFG::qNode<PoseNode,PoseNode> *)&v1->mPrev;
              v1->mPrev = v7;
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
  v20 = this->mChildren.mNode.mNext;
  v21 = (int)v20[1].mNext;
  v23 = &PoseNode_SetPauseBlend::`vftable;
  v26 = v21;
  v22 = (__int64)v1->mWeightSet;
  v25 = 0;
  v24 = 0;
  v27 = v22;
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, void ***))v20[-3].mNext[5].mPrev)(&v20[-3].mNext, &v23);
  return 1;
}27 = v22;
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, void ***))v20

// File Line: 2213
// RVA: 0x3B9A40
void __fastcall BlendNode::writeDebugDisplayToString(BlendNode *this, UFG::qStringBuilder *debugStringBuilder, int indentSpaces, const char *parentInfo)
{
  BlendNode *v4; // rdi
  unsigned int v5; // esi
  UFG::qStringBuilder *v6; // rbp
  double v7; // xmm6_8
  char *v8; // rbx
  __int64 v9; // rax
  unsigned int v10; // esi
  UFG::qNode<PoseNode,PoseNode> **v11; // rbx
  signed __int64 i; // rdi

  v4 = this;
  v5 = indentSpaces;
  v6 = debugStringBuilder;
  v7 = this->mBlendParam;
  v8 = UFG::qSymbol::as_cstr_dbg(&this->mName);
  v9 = (__int64)v4->vfptr->GetClassname((Expression::IMemberMap *)&v4->vfptr);
  UFG::qStringBuilder::Format(v6, "%*s%s:%s:Blend:%0.3f\n", v5, &customWorldMapCaption, v9, v8, v7);
  v10 = sSpacesPerIndent_0 + v5;
  v11 = &v4->mChildren.mNode.mNext[-3].mNext;
  for ( i = (signed __int64)&v4->mNetPoseSequence; v11 != (UFG::qNode<PoseNode,PoseNode> **)i; v11 = &v11[6][-3].mNext )
    ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, UFG::qStringBuilder *, _QWORD, _QWORD))(*v11)[8].mNext)(
      v11,
      v6,
      v10,
      0i64);
}

// File Line: 2228
// RVA: 0x3A8B40
void __usercall BlendNode::GetExtractedDeltaReferenceFrame(BlendNode *this@<rcx>, float deltaTime@<xmm1>, hkQsTransformf *deltaMotionOut@<r8>, __int64 a4@<rdx>)
{
  BlendNode *v4; // rdi
  UFG::qNode<PoseNode,PoseNode> *v5; // rcx
  hkQsTransformf *v6; // rsi
  UFG::qNode<PoseNode,PoseNode> *v7; // rbx
  __int64 v8; // rdx
  __m128 v9; // xmm4
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  Weightset *v12; // rax
  float *v13; // rcx
  __m128 v14; // xmm4
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm1
  __m128 v18; // xmm5
  __m128 v19; // xmm0
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // [rsp+20h] [rbp-78h]
  __m128 v24; // [rsp+30h] [rbp-68h]
  __m128 v25; // [rsp+40h] [rbp-58h]
  __m128 v26; // [rsp+50h] [rbp-48h]
  __m128 v27; // [rsp+60h] [rbp-38h]
  __m128 v28; // [rsp+70h] [rbp-28h]

  v4 = this;
  v5 = this->mChildren.mNode.mNext;
  v6 = deltaMotionOut;
  v7 = v5->mNext;
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, __int64, __m128 *))v5[-3].mNext[8].mPrev)(
    &v5[-3].mNext,
    a4,
    &v26);
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, __int64, __m128 *))v7[-3].mNext[8].mPrev)(
    &v7[-3].mNext,
    v8,
    &v23);
  v10 = (__m128)LODWORD(v4->mBlendParam);
  if ( !sBlendOnlyTranlation || v4->mWeightSet )
  {
    v12 = v4->mWeightSet;
    if ( v12 )
    {
      v13 = (float *)v12->mRawWeightSet.mOffset;
      if ( v13 )
        v13 = (float *)((char *)v13 + (_QWORD)v12 + 48);
      v10.m128_f32[0] = v10.m128_f32[0] * *v13;
    }
    v9.m128_f32[0] = v10.m128_f32[0];
    v14 = _mm_shuffle_ps(v9, v9, 0);
    v15 = _mm_mul_ps(v27, v24);
    v16 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v25, v28), v14), v28);
    v6->m_translation.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v23, v26), v14), v26);
    v6->m_scale.m_quad = v16;
    v17 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 78), v15);
    v18 = _mm_add_ps(
            _mm_mul_ps(
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32(
                            (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 177), v17), (__m128)0i64),
                            0x1Fu),
                          0x1Fu),
                v14),
              v24),
            _mm_mul_ps(_mm_sub_ps(query.m_quad, v14), v27));
    v19 = _mm_mul_ps(v18, v18);
    v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 78), v19);
    v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 177), v20);
    v22 = _mm_rsqrt_ps(v21);
    v6->m_rotation.m_vec.m_quad = _mm_mul_ps(
                                    v18,
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                                      _mm_mul_ps(*(__m128 *)_xmm, v22)));
  }
  else
  {
    v11 = _mm_sub_ps(v23, v26);
    v6->m_rotation.m_vec.m_quad = v24;
    v6->m_scale = (hkVector4f)_xmm;
    v6->m_translation.m_quad = _mm_add_ps(_mm_mul_ps(v11, _mm_shuffle_ps(v10, v10, 0)), v26);
  }
}

// File Line: 2273
// RVA: 0x3A9220
void __fastcall BlendNode::GetPhase(BlendNode *this, MotionPhase2 *motionPhase)
{
  MotionPhase2 *v2; // rdi
  BlendNode *v3; // rsi
  UFG::qNode<PoseNode,PoseNode> **v4; // rcx
  UFG::qNode<PoseNode,PoseNode> *v5; // rbx
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  __int64 v12; // rcx
  int v13; // eax
  float v14; // xmm0_4
  float v15; // xmm1_4
  void **v16; // [rsp+28h] [rbp-58h]
  __int64 v17; // [rsp+30h] [rbp-50h]
  __int64 v18; // [rsp+38h] [rbp-48h]
  __int64 v19; // [rsp+40h] [rbp-40h]
  void **v20; // [rsp+48h] [rbp-38h]
  __int64 v21; // [rsp+50h] [rbp-30h]
  __int64 v22; // [rsp+58h] [rbp-28h]
  __int64 v23; // [rsp+60h] [rbp-20h]

  v2 = motionPhase;
  v3 = this;
  if ( (int *)&this->mChildren.mNode.mNext[-3].mNext != &this->mNetPoseSequence )
  {
    if ( sOldWay )
    {
      ((void (__cdecl *)(UFG::qNode<PoseNode,PoseNode> **))this->mChildren.mNode.mNext[-3].mNext[11].mNext)(&this->mChildren.mNode.mNext[-3].mNext);
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
    v4 = &this->mChildren.mNode.mNext[-3].mNext;
    v5 = v4[6];
    ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, void ***))(*v4)[11].mNext)(v4, &v20);
    ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, void ***))v5[-3].mNext[11].mNext)(&v5[-3].mNext, &v16);
    if ( sPhaseBlending )
    {
      v6 = v3->mBlendParam;
      if ( !(_DWORD)v22 || !(_DWORD)v18 )
      {
        *(_QWORD *)&v2->mPhaseMark.mValue = 0i64;
        *(_QWORD *)&v2->mPhase = 0i64;
        goto LABEL_28;
      }
      if ( (_DWORD)v22 == (_DWORD)v18 )
      {
        v2->mPhaseMark.mValue = v22;
        v2->mPhase = (float)((float)(*(float *)&v19 - *(float *)&v23) * v6) + *(float *)&v23;
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
      v10 = (float)(*(float *)&v19 + v9) * v6;
      if ( v10 < v9 )
      {
        v2->mPhaseMark.mValue = v22;
        v2->mPhase = (float)(v9 - v10) + v8;
      }
      else
      {
        v2->mPhaseMark.mValue = v18;
        v2->mPhase = v10 - v9;
      }
      v11 = v2->mPhase;
      if ( v11 <= 0.0 )
      {
        v11 = 0.0;
      }
      else if ( v11 >= 1.0 )
      {
        goto LABEL_21;
      }
      v7 = v11;
LABEL_21:
      v2->mPhase = v7;
      goto LABEL_28;
    }
    if ( (_DWORD)v18 )
    {
      v12 = v17;
      v2->mPhaseMark.mValue = v18;
      v13 = HIDWORD(v18);
      v15 = *((float *)&v19 + 1);
      v14 = *(float *)&v19;
LABEL_27:
      v2->mPhaseDuration = v15;
      v2->mPhase = v14;
      v2->mPhasePeriod = v13;
      v2->mResourceOwner = (Expression::IMemberMap *)v12;
      goto LABEL_28;
    }
    if ( (_DWORD)v22 )
    {
      v12 = v21;
      v2->mPhaseMark.mValue = v22;
      v13 = HIDWORD(v22);
      v15 = *((float *)&v23 + 1);
      v14 = *(float *)&v23;
      goto LABEL_27;
    }
    v16 = &Expression::IMemberMap::`vftable;
    v20 = &Expression::IMemberMap::`vftable;
  }
  *(_QWORD *)&v2->mPhaseMark.mValue = 0i64;
  *(_QWORD *)&v2->mPhase = 0i64;
}

// File Line: 2317
// RVA: 0x3AA1D0
float *__fastcall BlendNode::GetWeights(BlendNode *this, int numBones, float weight)
{
  Weightset *v3; // rbx
  signed __int64 v4; // rbp
  BlendNode *v5; // rsi
  float *v6; // rdi
  float *result; // rax
  __int64 v8; // rax
  float *v9; // r10
  float v10; // xmm0_4
  __int64 v11; // rax
  int v12; // edi
  __int64 v13; // rdx
  unsigned __int64 v14; // r8
  __int64 v15; // rcx
  __m128 v16; // xmm1
  int v17; // eax
  __int64 v18; // r11
  unsigned __int64 v19; // r9
  signed __int64 v20; // rcx
  unsigned __int64 v21; // rax
  __int64 v22; // rdx
  unsigned __int64 v23; // r8
  signed __int64 v24; // rax
  __int64 v25; // rax
  float *v26; // rdi
  signed __int64 i; // rcx

  v3 = this->mWeightSet;
  v4 = numBones;
  v5 = this;
  if ( !v3 )
    return 0i64;
  if ( this->mWeightSetMask )
  {
    v6 = Weightset::GetWeights(v3, numBones, weight, 1);
    Weightset::MaskWeights(v5->mWeightSetMask, v6, v4);
    result = v6;
  }
  else if ( weight != 1.0 || numBones > v3->mRawWeightSetPaddedLength )
  {
    v9 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 4 * numBones, 0x10u);
    v10 = (float)(v3->mWeightsetEntires.mCount & 0x7FFFFFFF);
    if ( v10 >= (float)(signed int)v4 )
      v10 = (float)(signed int)v4;
    v11 = v3->mRawWeightSet.mOffset;
    v12 = 0;
    LODWORD(v13) = (signed int)v10;
    if ( v11 )
      v14 = (unsigned __int64)&v3->mRawWeightSet + v11;
    else
      v14 = 0i64;
    if ( (signed int)v13 > 0 && (unsigned int)v13 >= 8 )
    {
      v15 = (signed int)v13 - 1;
      v16 = _mm_shuffle_ps((__m128)LODWORD(weight), (__m128)LODWORD(weight), 0);
      if ( (unsigned __int64)v9 > v14 + 4 * v15 || (unsigned __int64)&v9[v15] < v14 )
      {
        do
        {
          *(__m128 *)&v9[v12] = _mm_mul_ps(*(__m128 *)(v14 + 4i64 * v12), v16);
          v17 = v12 + 4;
          v12 += 8;
          *(__m128 *)&v9[v17] = _mm_mul_ps(*(__m128 *)(v14 + 4i64 * v17), v16);
        }
        while ( v12 < (signed int)v13 - (signed int)v13 % 8 );
      }
    }
    v18 = v12;
    v13 = (signed int)v13;
    if ( v12 < (signed __int64)(signed int)v13 )
    {
      if ( v13 - v12 >= 4 )
      {
        v19 = v14 - (_QWORD)v9;
        v20 = (signed __int64)&v9[v12 + 1];
        v21 = ((unsigned __int64)(v13 - v12 - 4) >> 2) + 1;
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
        v24 = (signed __int64)&v9[v18];
        v12 += v22;
        do
        {
          v24 += 4i64;
          *(float *)(v24 - 4) = weight * *(float *)(v23 + v24 - 4);
          --v22;
        }
        while ( v22 );
      }
    }
    v25 = v12;
    if ( v12 < v4 )
    {
      v26 = &v9[v12];
      for ( i = v4 - v25; i; --i )
      {
        *v26 = weight * 255.0;
        ++v26;
      }
    }
    result = v9;
  }
  else
  {
    v8 = v3->mRawWeightSet.mOffset;
    if ( v8 )
      result = (float *)((char *)&v3->mRawWeightSet + v8);
    else
      result = 0i64;
  }
  return result;
}

// File Line: 2342
// RVA: 0x3B0C30
bool __fastcall BlendAddNode::Update(BlendAddNode *this, float timeDelta, bool updateAnimation)
{
  return BlendNode::Update((BlendNode *)&this->vfptr, timeDelta, updateAnimation);
}

// File Line: 2347
// RVA: 0x3B9B10
void __fastcall BlendPhaseNode::writeDebugDisplayToString(BlendSubNode *this, UFG::qStringBuilder *debugStringBuilder, int indentSpaces, const char *parentInfo)
{
  BlendSubNode *v4; // rdi
  unsigned int v5; // esi
  UFG::qStringBuilder *v6; // rbp
  double v7; // xmm6_8
  char *v8; // rbx
  __int64 v9; // rax
  unsigned int v10; // esi
  UFG::qNode<PoseNode,PoseNode> **v11; // rbx
  signed __int64 i; // rdi

  v4 = this;
  v5 = indentSpaces;
  v6 = debugStringBuilder;
  v7 = this->mBlendParam;
  v8 = UFG::qSymbol::as_cstr_dbg(&this->mName);
  v9 = (__int64)v4->vfptr->GetClassname((Expression::IMemberMap *)&v4->vfptr);
  UFG::qStringBuilder::Format(v6, "%*s%s:%s::weight%0.3f\n", v5, &customWorldMapCaption, v9, v8, v7);
  v10 = sSpacesPerIndent_0 + v5;
  v11 = &v4->mChildren.mNode.mNext[-3].mNext;
  for ( i = (signed __int64)&v4->mNetPoseSequence; v11 != (UFG::qNode<PoseNode,PoseNode> **)i; v11 = &v11[6][-3].mNext )
    ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, UFG::qStringBuilder *, _QWORD, _QWORD))(*v11)[8].mNext)(
      v11,
      v6,
      v10,
      0i64);
}

// File Line: 2361
// RVA: 0x3A8E60
void __usercall BlendSubNode::GetExtractedDeltaReferenceFrame(BlendSubNode *this@<rcx>, float deltaTime@<xmm1>, hkQsTransformf *deltaMotionOut@<r8>, __int64 a4@<rdx>)
{
  hkQsTransformf *v4; // rbx
  __int128 v5; // xmm1
  __int128 v6; // xmm0
  hkVector4f v7; // [rsp+20h] [rbp-38h]
  __int128 v8; // [rsp+30h] [rbp-28h]
  __int128 v9; // [rsp+40h] [rbp-18h]

  v4 = deltaMotionOut;
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, __int64, hkVector4f *))this->mChildren.mNode.mNext[-3].mNext[8].mPrev)(
    &this->mChildren.mNode.mNext[-3].mNext,
    a4,
    &v7);
  v5 = v8;
  v4->m_translation = (hkVector4f)v7.m_quad;
  v6 = v9;
  v4->m_rotation = (hkQuaternionf)v5;
  v4->m_scale = (hkVector4f)v6;
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
char __usercall BlendSubNode::Update@<al>(BlendSubNode *this@<rcx>, float timeDelta@<xmm1>, __int64 updateAnimation@<r8>, __int64 a4@<rdx>)
{
  BlendSubNode *v4; // rbx
  char result; // al

  v4 = this;
  ((void (__fastcall *)(BlendSubNode *, __int64, __int64))this->vfptr[1].GetClassname)(this, a4, updateAnimation);
  result = 1;
  v4->mLocalTime = timeDelta + v4->mLocalTime;
  return result;
}

// File Line: 2432
// RVA: 0x3B0ED0
bool __usercall BlendPhaseNode::Update@<al>(BlendPhaseNode *this@<rcx>, float timeDelta@<xmm1>, bool updateAnimation@<r8b>, float a4@<xmm0>)
{
  bool v4; // bp
  BlendPhaseNode *v5; // rbx
  float v6; // xmm7_4
  __int64 v7; // rdx
  __int64 v8; // rax
  signed __int64 v9; // rax
  __int64 v10; // rcx
  float v11; // xmm1_4
  UFG::qNode<PoseNode,PoseNode> *v12; // rsi
  UFG::qNode<PoseNode,PoseNode> *v13; // rdi
  PoseNode *v14; // rsi
  PoseNode *v15; // rdi
  Expression::IMemberMapVtbl *v16; // rax
  Expression::IMemberMapVtbl *v17; // rax
  __int64 v18; // rdx
  bool v19; // zf
  void **v21; // [rsp+20h] [rbp-B8h]
  char v22; // [rsp+28h] [rbp-B0h]
  __int64 v23; // [rsp+30h] [rbp-A8h]
  void **v24; // [rsp+38h] [rbp-A0h]
  char v25; // [rsp+40h] [rbp-98h]
  void **v26; // [rsp+48h] [rbp-90h]
  char v27; // [rsp+50h] [rbp-88h]
  char dest; // [rsp+58h] [rbp-80h]
  void **v29; // [rsp+78h] [rbp-60h]
  char v30; // [rsp+80h] [rbp-58h]
  char v31; // [rsp+88h] [rbp-50h]

  v4 = updateAnimation;
  v5 = this;
  v6 = timeDelta;
  ((void (*)(void))this->vfptr[1].GetClassname)();
  if ( v5->mPauseBlend )
  {
    v8 = v5->mParent.mOffset;
    if ( v8 )
    {
      v9 = (signed __int64)&v5->mParent + v8;
      if ( v9 )
      {
        v10 = *(_QWORD *)(v9 + 56);
        if ( !v10 || !(v10 + v9 + 56) )
          v5->mPauseBlend = 0;
      }
    }
  }
  if ( !v5->mPauseBlend )
  {
    v11 = v5->mBlendRate;
    if ( v11 != 0.0 )
    {
      a4 = (float)(v11 * v6) + v5->mBlendParam;
      v5->mBlendParam = a4;
      if ( v11 <= 0.0 )
      {
        if ( a4 <= 0.0 )
          v5->mBlendParam = 0.0;
      }
      else if ( a4 > 1.0 )
      {
        v5->mBlendParam = 1.0;
      }
    }
  }
  PoseNodeParent::Update((PoseNodeParent *)&v5->vfptr, v6, v4, v7);
  if ( v5->mSyncOnStart )
  {
    v12 = v5->mChildren.mNode.mNext;
    v13 = v12->mNext;
    v14 = (PoseNode *)&v12[-3].mNext;
    v5->mSyncOnStart = 0;
    v15 = (PoseNode *)&v13[-3].mNext;
    if ( v15 )
    {
      PhaseSync(v14, v15);
      v24 = &AnimationNode_UpdateLastPlayTime::`vftable;
      v16 = v15->vfptr;
      v25 = 1;
      v16[1].FindWithOldPath((Expression::IMemberMap *)&v15->vfptr, (const char *)&v24);
      if ( sSyncBlendDirection )
      {
        v27 = 1;
        v26 = &BlendDirectionNode_GetBlendDirection::`vftable;
        UFG::qMemSet(&dest, 0, 0x20u);
        v14->vfptr[1].FindWithOldPath((Expression::IMemberMap *)&v14->vfptr, (const char *)&v26);
        v29 = &BlendDirectionNode_SetBlendDirection::`vftable;
        v30 = 1;
        UFG::qMemCopy(&v31, &dest, 0x20u);
        v15->vfptr[1].FindWithOldPath((Expression::IMemberMap *)&v15->vfptr, (const char *)&v29);
      }
      v21 = &FirstAnimationNode::`vftable;
      v17 = v14->vfptr;
      v22 = 1;
      v23 = 0i64;
      v17[1].FindWithOldPath((Expression::IMemberMap *)&v14->vfptr, (const char *)&v21);
      if ( v23 )
      {
        (*(void (**)(void))(*(_QWORD *)v23 + 304i64))();
        if ( a4 == 0.0 )
        {
LABEL_23:
          ((void (__fastcall *)(PoseNode *, __int64, bool))v15->vfptr[1].GetClassNameUID)(v15, v18, v4);
          goto LABEL_24;
        }
        v19 = (*(unsigned __int8 (**)(void))(*(_QWORD *)v23 + 376i64))() == 0;
      }
      else
      {
        v19 = sUpdateFromSync == 0;
      }
      if ( !v19 )
        goto LABEL_23;
    }
  }
LABEL_24:
  v5->vfptr[5].GetClassNameUID((Expression::IMemberMap *)&v5->vfptr);
  return BlendNode::updateOperationPost((BlendNode *)&v5->vfptr);
}

// File Line: 2523
// RVA: 0x3B8CF0
void __fastcall BlendPhaseNode::updateOperation(BlendPhaseNode *this)
{
  UFG::qNode<PoseNode,PoseNode> *v1; // rax
  UFG::qNode<PoseNode,PoseNode> *v2; // r8
  int v3; // edx
  PoseNode *v4; // rax
  int v5; // er9
  PoseNode *v6; // r8

  if ( !this->mHoldPose && !this->mPauseBlend )
  {
    v1 = this->mChildren.mNode.mNext;
    v2 = v1->mNext;
    v3 = (int)v1[1].mNext;
    v4 = (PoseNode *)&v1[-3].mNext;
    v5 = (int)v2[1].mNext;
    v6 = (PoseNode *)&v2[-3].mNext;
    if ( v3 > v5 )
    {
      PhaseMatch(v6, v4, 1.0 - this->mBlendParam);
    }
    else if ( v3 >= v5 )
    {
      PhaseMatch(v4, v6, this->mBlendParam);
    }
    else
    {
      PhaseMatch(v4, v6, 0.0);
    }
  }
}

// File Line: 2569
// RVA: 0x3A8CE0
void __usercall BlendPhaseNode::GetExtractedDeltaReferenceFrame(BlendPhaseNode *this@<rcx>, float deltaTime@<xmm1>, hkQsTransformf *deltaMotionOut@<r8>, __int64 a4@<rdx>)
{
  BlendPhaseNode *v4; // rsi
  UFG::qNode<PoseNode,PoseNode> *v5; // rcx
  hkQsTransformf *v6; // rdi
  UFG::qNode<PoseNode,PoseNode> *v7; // rbx
  __int64 v8; // rdx
  Weightset *v9; // rax
  float *v10; // rcx
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  __m128 v13; // xmm4
  __m128 v14; // xmm0
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm0
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // [rsp+20h] [rbp-78h]
  __m128 v23; // [rsp+30h] [rbp-68h]
  __m128 v24; // [rsp+40h] [rbp-58h]
  __m128 v25; // [rsp+50h] [rbp-48h]
  __m128 v26; // [rsp+60h] [rbp-38h]
  __m128 v27; // [rsp+70h] [rbp-28h]

  v4 = this;
  v5 = this->mChildren.mNode.mNext;
  v6 = deltaMotionOut;
  v7 = v5->mNext;
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, __int64, __m128 *))v5[-3].mNext[8].mPrev)(
    &v5[-3].mNext,
    a4,
    &v22);
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, __int64, __m128 *))v7[-3].mNext[8].mPrev)(
    &v7[-3].mNext,
    v8,
    &v25);
  v9 = v4->mWeightSet;
  if ( !v9 )
    goto LABEL_9;
  v10 = (float *)v9->mRawWeightSet.mOffset;
  if ( v10 )
    v10 = (float *)((char *)v10 + (_QWORD)v9 + 48);
  if ( *v10 <= 0.0 )
  {
    v11 = v23;
    v6->m_translation.m_quad = v22;
    v12 = v24;
    v6->m_rotation.m_vec.m_quad = v11;
    v6->m_scale.m_quad = v12;
  }
  else
  {
LABEL_9:
    v13 = _mm_shuffle_ps((__m128)LODWORD(v4->mBlendParam), (__m128)LODWORD(v4->mBlendParam), 0);
    v14 = _mm_mul_ps(v26, v23);
    v15 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v25, v22), v13), v22);
    v6->m_scale.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v27, v24), v13), v24);
    v16 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 78), v14);
    v6->m_translation.m_quad = v15;
    v17 = _mm_add_ps(
            _mm_mul_ps(
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32(
                            (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 177), v16), (__m128)0i64),
                            0x1Fu),
                          0x1Fu),
                v13),
              v26),
            _mm_mul_ps(_mm_sub_ps(query.m_quad, v13), v23));
    v18 = _mm_mul_ps(v17, v17);
    v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
    v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
    v21 = _mm_rsqrt_ps(v20);
    v6->m_rotation.m_vec.m_quad = _mm_mul_ps(
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
  BlendPhaseNode *v1; // rdi
  UFG::qNode<PoseNode,PoseNode> *v2; // rcx
  UFG::qNode<PoseNode,PoseNode> *v3; // rbx

  v1 = this;
  v2 = this->mChildren.mNode.mNext;
  v3 = v2->mNext;
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **))v2[-3].mNext[9].mNext)(&v2[-3].mNext);
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **))v3[-3].mNext[9].mNext)(&v3[-3].mNext);
  v1->mHoldPose = 1;
}

// File Line: 2616
// RVA: 0x3AC550
void __fastcall BlendPhaseNode::Pause(BlendPhaseNode *this)
{
  BlendPhaseNode *v1; // rdi
  UFG::qNode<PoseNode,PoseNode> *v2; // rcx
  UFG::qNode<PoseNode,PoseNode> *v3; // rbx

  v1 = this;
  v2 = this->mChildren.mNode.mNext;
  v3 = v2->mNext;
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **))v2[-3].mNext[10].mNext)(&v2[-3].mNext);
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **))v3[-3].mNext[10].mNext)(&v3[-3].mNext);
  v1->mHoldPose = 1;
}

// File Line: 2627
// RVA: 0x3AE460
void __fastcall BlendPhaseNode::Resume(BlendPhaseNode *this)
{
  BlendPhaseNode *v1; // rdi
  UFG::qNode<PoseNode,PoseNode> *v2; // rcx
  UFG::qNode<PoseNode,PoseNode> *v3; // rbx

  v1 = this;
  v2 = this->mChildren.mNode.mNext;
  v3 = v2->mNext;
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **))v2[-3].mNext[11].mPrev)(&v2[-3].mNext);
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **))v3[-3].mNext[11].mPrev)(&v3[-3].mNext);
  v1->mHoldPose = 0;
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
  MotionPhase2 *v2; // rbx
  void **v3; // [rsp+28h] [rbp-40h]
  char v4; // [rsp+30h] [rbp-38h]
  void **v5; // [rsp+38h] [rbp-30h]
  __int128 v6; // [rsp+40h] [rbp-28h]
  __int64 v7; // [rsp+50h] [rbp-18h]

  v2 = motionPhase;
  v4 = 1;
  v3 = &PoseNode_GetPhase::`vftable;
  v6 = 0ui64;
  v5 = &MotionPhase2::`vftable;
  v7 = 0i64;
  ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, void ***))this->mChildren.mNode.mNext[-3].mNext[5].mPrev)(
    &this->mChildren.mNode.mNext[-3].mNext,
    &v3);
  *(_OWORD *)&v2->mResourceOwner = v6;
  *(_QWORD *)&v2->mPhase = v7;
}

// File Line: 2702
// RVA: 0x3B91E0
void __fastcall AnimationNode::verifyBindAnimation(AnimationNode *this)
{
  AnimationNode *v1; // rbx
  unsigned int v2; // edx
  SkeletalAnimationHandle *v3; // rcx
  SkeletalAnimation *v4; // rax
  __int64 v5; // rcx
  UFG::qSymbolUC *v6; // rdx
  UFG::eAnimationPriorityEnum v7; // er8

  v1 = this;
  if ( !this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer )
  {
    v2 = this->mName.mUID;
    if ( v2 != UFG::gNullQSymbolUC.mUID )
    {
      if ( this->mSkeletalAnimationHandle.m_SkeletalAnimationName.mUID == UFG::gNullQSymbolUC.mUID )
      {
        v3 = &this->mSkeletalAnimationHandle;
        v3->m_SkeletalAnimationName.mUID = v2;
LABEL_6:
        SkeletalAnimationHandle::Init(v3);
        goto LABEL_7;
      }
      v3 = &this->mSkeletalAnimationHandle;
      if ( !v3->m_SkeletalAnimation.m_pPointer )
        goto LABEL_6;
    }
  }
LABEL_7:
  if ( v1->mAnimationGroupHandle.m_AnimationGroupSymbol.mUID == -1 )
  {
    v4 = v1->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
    if ( v4 )
    {
      v5 = v4->m_pAnimationGroup.mOffset;
      if ( v5 )
      {
        v6 = (UFG::qSymbolUC *)((char *)&v4->m_pAnimationGroup + v5);
        if ( v6 )
        {
          v7 = eANIM_PRIORITY_ANIMATION_PLAYING;
          if ( gPLayingRemoteDebug )
            v7 = eANIM_PRIORITY_PLAYER;
          AnimationGroupHandle::Init(&v1->mAnimationGroupHandle, v6 + 0x2B, v7);
          AnimationGroupHandle::Bind(&v1->mAnimationGroupHandle);
        }
      }
    }
  }
}

// File Line: 2783
// RVA: 0x3B7AB0
int getfutureTimeUtil(...)
{
  __int128 v6; // xmm4
  __int128 v7; // xmm0
  __int128 v8; // xmm4
  float i; // xmm0_4

  v6 = timeDelta;
  if ( COERCE_FLOAT(LODWORD(playRate) & _xmm) > 1000.0 && playRate > 0.0 && playRate >= 1000.0 )
    playRate = FLOAT_1000_0;
  if ( (float)(playTimeFinal - playTimeStart) > 0.000099999997 )
  {
    *(float *)&v6 = (float)(*(float *)&timeDelta * playRate) + result;
    if ( *(float *)&v6 <= result )
    {
      if ( *(float *)&v6 < result )
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
    result = *(float *)&v6;
  }
  return result;
}

// File Line: 2834
// RVA: 0x3B7110
float __fastcall AnimationNode::getEndTimePlay(AnimationNode *this)
{
  float v1; // xmm6_4
  AnimationNode *v2; // rbx
  SkeletalAnimation *v3; // rcx
  float v4; // xmm0_4
  float result; // xmm0_4

  v1 = sTposeAnimPlayDuration;
  v2 = this;
  v3 = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  if ( v3 )
  {
    v4 = SkeletalAnimation::GetDuration(v3);
    if ( v4 > 0.0 )
      v1 = v4;
  }
  if ( v1 <= 0.0 )
    return 0.0;
  result = v2->mPlayEndTime;
  if ( result < 0.0 || result > v1 )
    result = v1;
  return result;
}

// File Line: 2868
// RVA: 0x3B79D0
float __fastcall AnimationNode::getfutureTimeFast(AnimationNode *this, float timeDelta, float duration, int *loops)
{
  float v4; // xmm7_4
  int *v5; // rdi
  AnimationNode *v6; // rbx
  float v7; // xmm6_4
  float playTimeFinal; // xmm0_4

  *loops = 0;
  v4 = this->mLocalTime;
  v5 = loops;
  v6 = this;
  if ( ((unsigned __int8 (*)(void))this->vfptr[4].ResolveReferences)() )
    v7 = 0.0;
  else
    v7 = v6->mPlayRate;
  if ( duration <= 0.0 )
    return v4 + (float)(v7 * timeDelta);
  playTimeFinal = AnimationNode::getEndTimePlay(v6);
  return getfutureTimeUtil(v6->mLocalTime, timeDelta, v7, 0.0, playTimeFinal, v5);
}

// File Line: 2889
// RVA: 0x3B0890
char __fastcall AnimationNode::Update(AnimationNode *this, float timeDelta, bool updateAnimation)
{
  AnimationNode *v3; // rbx
  SkeletalAnimation *v4; // rcx
  float v5; // xmm9_4
  float v6; // xmm0_4
  SkeletalAnimation *v7; // rcx
  float v8; // xmm10_4
  float v9; // xmm8_4
  float v10; // xmm7_4
  float v11; // xmm11_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  int *v14; // rdi
  float v15; // xmm0_4
  unsigned __int8 v16; // cl
  signed int v17; // edx
  float v18; // xmm0_4
  Expression::IMemberMapVtbl *v19; // rax

  v3 = this;
  if ( updateAnimation )
  {
    AnimationNode::verifyBindAnimation(this);
    if ( !v3->mPause )
    {
      v4 = v3->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
      v5 = sTposeAnimPlayDuration;
      if ( v4 )
      {
        v6 = SkeletalAnimation::GetDuration(v4);
        if ( v6 > 0.0 )
          v5 = v6;
      }
      if ( v5 > 0.0 )
      {
        v7 = v3->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
        v8 = v3->mLocalTime;
        v9 = sTposeAnimPlayDuration;
        v10 = 0.0;
        v11 = v3->mPlayStartTime;
        if ( v7 )
        {
          v12 = SkeletalAnimation::GetDuration(v7);
          if ( v12 > 0.0 )
            v9 = v12;
        }
        if ( v9 > 0.0 )
        {
          v13 = v3->mPlayEndTime;
          v10 = v9;
          if ( v13 >= 0.0 && v13 <= v9 )
            v10 = v3->mPlayEndTime;
        }
        v14 = &v3->mLoops;
        v15 = AnimationNode::getfutureTimeFast(v3, timeDelta, v5, &v3->mLoops);
        v16 = v3->mPlayMode.mValue;
        if ( v16 > 7u || (v17 = 165, !_bittest(&v17, v16)) )
        {
          v3->mLocalTime = v15;
LABEL_31:
          if ( v8 == v3->mLocalTime )
          {
            AnimationNode::endAllTracks(v3);
          }
          else
          {
            getPhase(v3, &v3->mMotionPhase);
            if ( v8 > v3->mLocalTime )
            {
              v8 = 0.0;
              AnimationNode::endAllTracks(v3);
            }
            if ( v3->mPlayTracks )
            {
              AnimationNode::startTracks(v3, v8, v3->mLocalTime);
              AnimationNode::updateTracks(v3, timeDelta, v3->mLocalTime);
            }
          }
          return 1;
        }
        if ( *v14 <= 0 )
        {
          if ( *v14 >= 0 )
          {
            v3->mLocalTime = v15;
LABEL_23:
            v18 = v3->mLocalTime;
            if ( v18 > v11 )
            {
              if ( v18 >= v10 )
                v3->mLocalTime = v10;
            }
            else
            {
              v3->mLocalTime = v11;
            }
            if ( v3->mPlayMode.mValue == 2 && *v14 > 0 )
            {
              v19 = v3->vfptr;
              v3->mLocalTime = v10;
              *v14 = 0;
              ((void (__fastcall *)(AnimationNode *))v19[2].__vecDelDtor)(v3);
            }
            goto LABEL_31;
          }
          v3->mLocalTime = v11;
        }
        else
        {
          v3->mLocalTime = v10;
        }
        *v14 = 0;
        if ( v16 != 7 )
          ((void (__fastcall *)(AnimationNode *))v3->vfptr[2].__vecDelDtor)(v3);
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
  AnimationNode *v3; // rbp
  SkeletalAnimation *v4; // rcx
  __int64 v5; // rax
  __int64 v6; // rsi
  __int64 v7; // rdi
  signed __int64 v8; // r14
  float *v9; // rcx
  float v10; // xmm0_4
  __int64 v11; // rbx
  UFG::qNode<ITask,ITask> **v12; // rcx
  UFG::qNode<ITask,ITask> *v13; // rax

  v3 = this;
  v4 = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  if ( v4 )
  {
    v5 = ((__int64 (*)(void))v4->vfptr[1].CreateClone)();
    v6 = v5;
    if ( v5 )
    {
      v7 = 0i64;
      v8 = v5 + *(_QWORD *)(v5 + 24) + 24i64;
      if ( *(_DWORD *)(v5 + 16) & 0x7FFFFFFF )
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
            (*(void (__fastcall **)(__int64, ActionContext *))(*(_QWORD *)v11 + 8i64))(v11, v3->mpContext);
            v12 = (UFG::qNode<ITask,ITask> **)(v11 + 8);
            v13 = v3->m_RunningTasks.mNode.mPrev;
            v13->mNext = (UFG::qNode<ITask,ITask> *)(v11 + 8);
            *v12 = v13;
            v12[1] = &v3->m_RunningTasks.mNode;
            v3->m_RunningTasks.mNode.mPrev = (UFG::qNode<ITask,ITask> *)(v11 + 8);
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
  ActionContext **v3; // rbp
  ActionContext **v4; // rbx
  bool v5; // di
  float v6; // xmm6_4
  signed __int64 v7; // rsi
  ActionContext *v8; // rdx
  ActionContext *v9; // rax
  _QWORD *v10; // r8

  v3 = &this->mpContext;
  v4 = (ActionContext **)&this->m_RunningTasks.mNode.mNext[-1].mNext;
  v5 = v4 == &this->mpContext;
  if ( this->m_RunningTasks.mNode.mNext != (UFG::qNode<ITask,ITask> *)8 )
  {
    do
    {
      if ( v5 )
        break;
      v6 = *((float *)&v4[3]->mDebugBreak + 1);
      if ( ((unsigned __int8 (__fastcall *)(ActionContext **))(*v4)->mSimObject.m_pPointer)(v4)
        && (v6 < 0.0 || newTime < v6) )
      {
        v4 = (ActionContext **)&v4[2][-1].mProbabilitys[9];
        v5 = v4 == v3;
      }
      else
      {
        ((void (__fastcall *)(ActionContext **))(*v4)->m_OpeningBranch)(v4);
        v7 = (signed __int64)&v4[2][-1].mProbabilitys[9];
        v5 = v4[2] == (ActionContext *)8 || (ActionContext **)v7 == v3;
        v8 = v4[1];
        v9 = v4[2];
        v10 = v4 + 1;
        v8->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mSimObject.mPrev;
        v9->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mSimObject.mPrev;
        *v10 = v10;
        v10[1] = v10;
        ((void (__fastcall *)(ActionContext **, signed __int64))(*v4)->mSimObject.mPrev)(v4, 1i64);
        v4 = (ActionContext **)v7;
      }
    }
    while ( v4 );
  }
}

// File Line: 3271
// RVA: 0x3B6A00
void __fastcall AnimationNode::endAllTracks(AnimationNode *this)
{
  ActionContext **v1; // rsi
  AnimationNode *v2; // rdi
  UFG::qNode<ITask,ITask> *v3; // rbx
  UFG::qNode<ITask,ITask> *v4; // rdx
  UFG::qNode<ITask,ITask> *v5; // rax

  v1 = &this->mpContext;
  v2 = this;
  if ( (ActionContext **)&this->m_RunningTasks.mNode.mNext[-1].mNext != &this->mpContext )
  {
    do
    {
      v3 = v2->m_RunningTasks.mNode.mNext;
      ((void (__fastcall *)(UFG::qNode<ITask,ITask> **))v3[-1].mNext[1].mNext)(&v3[-1].mNext);
      v4 = v3->mPrev;
      v5 = v3->mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = v3;
      v3->mNext = v3;
      ((void (__fastcall *)(UFG::qNode<ITask,ITask> **, signed __int64))v3[-1].mNext->mPrev)(&v3[-1].mNext, 1i64);
    }
    while ( (ActionContext **)&v2->m_RunningTasks.mNode.mNext[-1].mNext != v1 );
  }
}

// File Line: 3314
// RVA: 0x3B9440
AnimationNode::writeDebugDisplayToString

// File Line: 3416
// RVA: 0x3A8870
void __fastcall AnimationNode::GetExtractedDeltaReferenceFrame(AnimationNode *this, float fromTime, float toTime, hkQsTransformf *deltaMotionOut)
{
  SkeletalAnimation *v4; // rdx
  hkQsTransformf *v5; // rdi
  UFG::qResourceData *v6; // rax
  unsigned int v7; // ebx
  UFG::qBaseNodeRB *v8; // rax
  SkeletalAnimation *v9; // rcx
  UFG::qResourceData *v10; // rax
  __int64 v11; // rsi
  float v12; // xmm7_4
  __int64 v13; // rdx
  __int64 v14; // r8
  float i; // xmm6_4

  v4 = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  v5 = deltaMotionOut;
  if ( !v4 )
  {
    deltaMotionOut->m_translation = 0i64;
    deltaMotionOut->m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
    deltaMotionOut->m_scale = (hkVector4f)query.m_quad;
    return;
  }
  v6 = v4->m_AnimationResourceHandle.mData;
  v7 = 0;
  if ( v6 )
  {
    v8 = v6[1].mNode.mChild[0];
    if ( v8 )
      goto LABEL_11;
  }
  else
  {
    v8 = 0i64;
  }
  v9 = v4->m_pFallbackAnimation;
  if ( v9 )
  {
    v10 = v9->m_AnimationResourceHandle.mData;
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
  for ( i = (float)(toTime - fromTime) + fmodf(fromTime, *(float *)(v11 + 20)); i > v12; ++v7 )
    i = i - v12;
  (*(void (__fastcall **)(__int64, __int64, __int64, _QWORD, hkQsTransformf *, _DWORD, _DWORD))(*(_QWORD *)v11 + 112i64))(
    v11,
    v13,
    v14,
    v7,
    v5,
    0,
    0);
}

// File Line: 3453
// RVA: 0x3A86F0
void __fastcall AnimationNode::GetExtractedDeltaReferenceFrame(AnimationNode *this, float deltaTime, hkQsTransformf *deltaMotionOut)
{
  hkQsTransformf *v3; // rbx
  AnimationNode *v4; // rsi
  SkeletalAnimation *v5; // rax
  UFG::qResourceData *v6; // rdi
  SkeletalAnimation *v7; // rcx
  UFG::qResourceData *v8; // rdi
  __int128 v9; // xmm6
  __int128 v10; // xmm8
  float v11; // xmm9_4
  char v12; // al
  __int64 v13; // rdx
  __int64 v14; // r8
  float v15; // xmm1_4

  v3 = deltaMotionOut;
  v4 = this;
  AnimationNode::verifyBindAnimation(this);
  v5 = v4->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  if ( !v5 )
  {
    v3->m_translation = 0i64;
    v3->m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
    v3->m_scale = (hkVector4f)query.m_quad;
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
        goto LABEL_14;
      v6 = (UFG::qResourceData *)v8[1].mNode.mChild[0];
    }
    if ( v6 )
      goto LABEL_9;
LABEL_14:
    v3->m_translation = 0i64;
    v3->m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
    v3->m_scale = (hkVector4f)query.m_quad;
    return;
  }
LABEL_9:
  if ( !*(_QWORD *)(*(_QWORD *)&v6->mNode.mUID + 32i64) )
    goto LABEL_14;
  v9 = LODWORD(v4->mLastPlayTime);
  v10 = LODWORD(v4->mLocalTime);
  v11 = (float)v4->mLoops;
  v12 = ((__int64 (__fastcall *)(AnimationNode *))v4->vfptr[4].ResolveReferences)(v4);
  if ( v4->mPreserveMotionOnHoldLastFrame )
  {
    if ( v12 )
    {
      v15 = v4->mPlayRate;
      v4->mLocalTime;
    }
  }
  (*(void (__fastcall **)(_QWORD, __int64, __int64, _QWORD, hkQsTransformf *, _DWORD, _DWORD))(**(_QWORD **)&v6->mNode.mUID
                                                                                             + 112i64))(
    *(_QWORD *)&v6->mNode.mUID,
    v13,
    v14,
    (unsigned int)(signed int)v11,
    v3,
    0,
    0);
}

// File Line: 3543
// RVA: 0x3A83B0
void __fastcall AnimationNode::GetExtractedCurrentAbsoluteReferenceFrame(AnimationNode *this, hkQsTransformf *absMotionOut)
{
  SkeletalAnimation *v2; // rbx
  hkQsTransformf *v3; // rbp
  AnimationNode *v4; // rsi
  UFG::qResourceData *v5; // rdi
  SkeletalAnimation *v6; // rax
  UFG::qResourceData *v7; // rdi
  __int64 v8; // r8
  float v9; // xmm6_4
  int v10; // eax
  float *v11; // rbx
  float v12; // xmm7_4
  int v13; // eax
  __m128 v14; // xmm1
  __m128 v15; // xmm7
  __m128 v16; // xmm5
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  hkQuaternionf v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm4
  __m128 v23; // xmm0
  __m128 v24; // xmm2
  __m128 v25; // xmm3
  __m128 v26; // xmm4
  __m128 v27; // xmm4
  __m128 v28; // xmm1
  __m128 v29; // xmm0
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  hkQsTransformf v32; // [rsp+40h] [rbp-108h]
  __m128 v33; // [rsp+70h] [rbp-D8h]
  __m128 v34; // [rsp+80h] [rbp-C8h]
  __m128 v35; // [rsp+90h] [rbp-B8h]
  UFG::qMatrix44 outMatrix; // [rsp+A0h] [rbp-A8h]
  hkTransformf transform; // [rsp+E0h] [rbp-68h]

  v2 = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  v3 = absMotionOut;
  v4 = this;
  if ( v2
    && SkeletalAnimation::GetAnimationRootOrigin(
         this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer,
         &outMatrix) )
  {
    v5 = v2->m_AnimationResourceHandle.mData;
    if ( v5 )
    {
      v5 = (UFG::qResourceData *)v5[1].mNode.mChild[0];
      if ( v5 )
        goto LABEL_15;
    }
    v6 = v2->m_pFallbackAnimation;
    if ( v6 )
    {
      v7 = v6->m_AnimationResourceHandle.mData;
      if ( !v7 )
        return;
      v5 = (UFG::qResourceData *)v7[1].mNode.mChild[0];
    }
    if ( v5 )
    {
LABEL_15:
      if ( *(_QWORD *)(*(_QWORD *)&v5->mNode.mUID + 32i64) )
      {
        hkTransformf::set4x4ColumnMajor(&transform, &outMatrix.v0.x);
        hkQsTransformf::setFromTransformNoScale(&v32, &transform);
        v9 = v4->mLocalTime;
        if ( v4->mPoseOnFrameBoundaries )
        {
          v10 = (*(__int64 (**)(void))(**(_QWORD **)&v5->mNode.mUID + 64i64))();
          v11 = *(float **)&v5->mNode.mUID;
          v12 = v11[5] / (float)(v10 - 1);
          v13 = (unsigned __int64)(*(__int64 (__fastcall **)(float *))(*(_QWORD *)v11 + 64i64))(v11) - 1;
        }
        (*(void (__fastcall **)(_QWORD, __m128 *, __int64, _QWORD, __m128 *, _DWORD, _DWORD))(**(_QWORD **)&v5->mNode.mUID
                                                                                            + 112i64))(
          *(_QWORD *)&v5->mNode.mUID,
          &v33,
          v8,
          0i64,
          &v33,
          0,
          0);
        v14 = _mm_mul_ps(v33, v32.m_rotation.m_vec.m_quad);
        v15 = _mm_shuffle_ps(v32.m_rotation.m_vec.m_quad, v32.m_rotation.m_vec.m_quad, 255);
        v16 = _mm_shuffle_ps(v32.m_rotation.m_vec.m_quad, v32.m_rotation.m_vec.m_quad, 201);
        v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v33, v33, 201), v32.m_rotation.m_vec.m_quad), _mm_mul_ps(v33, v16));
        v18 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                _mm_shuffle_ps(v14, v14, 170));
        v19.m_vec.m_quad = (__m128)v32.m_rotation;
        v20 = v34;
        v21 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(v18, v32.m_rotation.m_vec.m_quad),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v15, v15), (__m128)xmmword_141A711B0), v33)),
                _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v15));
        v22 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v32.m_rotation.m_vec.m_quad), _mm_mul_ps(v34, v16));
        v3->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v21, v21), v32.m_translation.m_quad);
        v23 = _mm_mul_ps(v20, v15);
        v24 = _mm_shuffle_ps(v20, v20, 255);
        v25 = _mm_mul_ps(v20, v19.m_vec.m_quad);
        v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 201), v23), _mm_mul_ps(v19.m_vec.m_quad, v24));
        v27 = _mm_shuffle_ps(
                v26,
                _mm_unpackhi_ps(
                  v26,
                  _mm_sub_ps(
                    _mm_mul_ps(v24, v15),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                      _mm_shuffle_ps(v25, v25, 170)))),
                196);
        v28 = _mm_mul_ps(v27, v27);
        v3->m_scale.m_quad = _mm_mul_ps(v35, v32.m_scale.m_quad);
        v29 = _mm_add_ps(_mm_shuffle_ps(v28, v28, 78), v28);
        v30 = _mm_add_ps(_mm_shuffle_ps(v29, v29, 177), v29);
        v31 = _mm_rsqrt_ps(v30);
        v3->m_rotation.m_vec.m_quad = _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v31)),
                                        v27);
      }
    }
  }
}

// File Line: 3591
// RVA: 0x3A9080
void __fastcall AnimationNode::GetPhase(AnimationNode *this, MotionPhase2 *motionPhase)
{
  MotionPhase2 *v2; // rdi
  AnimationNode *v3; // rbx

  v2 = motionPhase;
  v3 = this;
  if ( sReSyncPhase )
    getPhase(this, &this->mMotionPhase);
  v2->mResourceOwner = v3->mMotionPhase.mResourceOwner;
  v2->mPhaseMark.mValue = v3->mMotionPhase.mPhaseMark.mValue;
  v2->mPhasePeriod = v3->mMotionPhase.mPhasePeriod;
  v2->mPhase = v3->mMotionPhase.mPhase;
  v2->mPhaseDuration = v3->mMotionPhase.mPhaseDuration;
}

// File Line: 3600
// RVA: 0x3AF490
void __fastcall AnimationNode::SetPhase(AnimationNode *this, MotionPhase2 *motionPhase)
{
  AnimationNode *v2; // rbx
  SkeletalAnimation *v3; // rcx
  MotionPhase2 *v4; // rdi
  bool animCycles; // al
  MotionKey *track1; // [rsp+40h] [rbp+8h]
  MotionKey *track0; // [rsp+50h] [rbp+18h]

  v2 = this;
  v3 = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  v4 = motionPhase;
  if ( v3 )
  {
    animCycles = v2->mPlayMode.mValue == 1;
    track0 = 0i64;
    track1 = 0i64;
    getBoundFootTracksAtMotionPhase(v3, motionPhase, &track0, &track1, animCycles);
    setLocalTimeFromPhaseTracks(v2, v4->mPhase, track0, track1);
  }
  v2->mLoops = v2->mLocalTime < v2->mLastPlayTime
            && (v2->mPlayRate > 0.0
             || !((unsigned __int8 (__fastcall *)(AnimationNode *))v2->vfptr[4].ResolveReferences)(v2));
  getPhase(v2, &v2->mMotionPhase);
}

// File Line: 3621
// RVA: 0x3AF660
void __fastcall AnimationNode::SetRateWeight0(AnimationNode *this, float animLength0, float animLength1, float weight)
{
  if ( animLength1 > 0.0 && weight <= 1.0 )
    ((void (*)(void))this->vfptr[3].ResolveReferences)();
}

// File Line: 3633
// RVA: 0x3AF720
void __fastcall AnimationNode::SetRateWeight1(AnimationNode *this, float animLength0, float animLength1, float weight)
{
  if ( animLength0 > 0.0 && weight <= 1.0 )
    ((void (*)(void))this->vfptr[3].ResolveReferences)();
}

// File Line: 3645
// RVA: 0x3AB170
bool __fastcall AnimationNode::IsFinished(AnimationNode *this, float inTimeDelta)
{
  AnimationNode *v2; // rbx
  float v3; // xmm6_4
  SkeletalAnimation *v4; // rcx
  int loops; // [rsp+50h] [rbp+8h]

  v2 = this;
  AnimationNode::verifyBindAnimation(this);
  v3 = 0.0;
  if ( v2->mPlayRate == 0.0 || ((unsigned __int8 (__fastcall *)(AnimationNode *))v2->vfptr[4].ResolveReferences)(v2) )
    return 1;
  v4 = v2->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  loops = 0;
  if ( v4 )
    v3 = SkeletalAnimation::GetDuration(v4);
  AnimationNode::getfutureTimeFast(v2, inTimeDelta, v3, &loops);
  return loops != 0;
}

// File Line: 3663
// RVA: 0x3A8F00
float __fastcall AnimationNode::GetPhase(AnimationNode *this, float futureTimeDelta)
{
  SkeletalAnimation *v2; // rdi
  AnimationNode *v3; // rbx
  float v4; // xmm6_4
  float v5; // xmm1_4
  bool animCycles; // zf
  float *v7; // rsi
  __int64 v8; // rbp
  float v9; // xmm7_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm6_4
  float v13; // xmm1_4
  float v14; // xmm6_4
  SkeletalAnimation *v16; // rcx
  float v17; // xmm0_4
  float v18; // xmm0_4
  int loops; // [rsp+70h] [rbp+8h]
  __int128 v20; // [rsp+80h] [rbp+18h]

  v2 = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  v3 = this;
  v4 = futureTimeDelta;
  if ( !v2 )
    return FLOAT_N1_0;
  v5 = this->mLocalTime;
  animCycles = this->mPlayMode.mValue == 1;
  v20 = 0ui64;
  getBoundFootTracks(v2, v5, (MotionKey **)&v20, (MotionKey **)&v20 + 1, &loops, animCycles);
  v7 = (float *)v20;
  if ( (_QWORD)v20 && (v8 = *((_QWORD *)&v20 + 1)) != 0 )
  {
    v9 = v3->mLocalTime;
    v10 = SkeletalAnimation::GetDuration(v2);
    v11 = v7[4];
    v12 = 0.0;
    v13 = *(float *)(v8 + 16) - v11;
    if ( v13 < 0.0 )
      v13 = (float)(v10 - v11) + *(float *)(v8 + 16);
    if ( v13 > 0.000099999997 )
    {
      v12 = (float)(1.0 / v13) * v9;
      if ( v9 >= v11 && v9 <= v10 )
        v12 = (float)(v9 - v11) * (float)(1.0 / v13);
    }
    if ( MotionKeyFootStepLeft::sClassNameUID != (*(unsigned int (__fastcall **)(float *))(*(_QWORD *)v7 + 40i64))(v7) )
      v12 = v12 + 1.0;
    v14 = v12 * 0.5;
  }
  else
  {
    v16 = v3->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
    if ( v16 )
      v17 = SkeletalAnimation::GetDuration(v16);
    else
      v17 = 0.0;
    v18 = AnimationNode::getfutureTimeFast(v3, v4, v17, &loops);
    v14 = v18 / SkeletalAnimation::GetDuration(v2);
  }
  return v14;
}

// File Line: 3726
// RVA: 0x3AF3E0
void __fastcall AnimationNode::SetParametricPlayTime(AnimationNode *this, float parametric)
{
  AnimationNode *v2; // rbx
  SkeletalAnimation *v3; // rcx

  v2 = this;
  v3 = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  if ( v3 )
  {
    if ( parametric >= 0.0 )
    {
      SkeletalAnimation::GetDuration(v3);
      v2->mPlayEndTime;
      v2->mPlayStartTime;
      ((void (__fastcall *)(AnimationNode *))v2->vfptr[3].GetResourcePath)(v2);
      v2->vfptr[3].ResolveReferences((Expression::IMemberMap *)&v2->vfptr);
    }
  }
}

// File Line: 3758
// RVA: 0x3AF350
void __fastcall AnimationNode::SetLocalTime(AnimationNode *this, float localtime)
{
  AnimationNode *v2; // rbx
  bool v3; // cf
  bool v4; // zf
  float v5; // xmm0_4
  char v6; // al

  v2 = this;
  if ( localtime >= 0.0 )
  {
    v3 = this->mLastPlayTime > 0.0;
    v4 = this->mLastPlayTime == 0.0;
    this->mLocalTime = localtime;
    if ( !v3 && !v4 || this->mFirstPlay )
      this->mLastPlayTime = localtime;
    v5 = AnimationNode::getEndTimePlay(this);
    v6 = v2->mPlayMode.mValue;
    if ( v6 == 1 || v6 == 6 )
    {
      v2->mLocalTime = fmodf(localtime, v5);
    }
    else if ( v5 < v2->mLocalTime )
    {
      v2->mLocalTime = v5;
    }
  }
}

// File Line: 3789
// RVA: 0x3A81D0
float __fastcall AnimationNode::GetDuration(AnimationNode *this)
{
  if ( this->mSkeletalAnimationHandle.m_SkeletalAnimationName.mUID != UFG::gNullQSymbolUC.mUID )
    JUMPOUT(this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer, 0i64, SkeletalAnimation::GetDuration);
  return FLOAT_N1_0;
}

// File Line: 3855
// RVA: 0x3B6C80
float __fastcall AnimationNode::getAverageExtractedSpeed(AnimationNode *this)
{
  AnimationNode *v1; // rbx
  __int64 v2; // r8
  SkeletalAnimation *v3; // rcx
  UFG::qResourceData *v4; // rax
  SkeletalAnimation *v5; // rdx
  UFG::qResourceData *v6; // rax
  __int64 v7; // rcx
  __int128 v8; // xmm2
  int v9; // ST30_4
  int v10; // ST28_4
  __m128 v11; // xmm1
  float result; // xmm0_4
  float v13; // [rsp+40h] [rbp-38h]
  unsigned int v14; // [rsp+44h] [rbp-34h]

  v1 = this;
  AnimationNode::verifyBindAnimation(this);
  v3 = v1->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  if ( !v3 )
    return 0.0;
  v4 = v3->m_AnimationResourceHandle.mData;
  if ( !v4 || (v4 = (UFG::qResourceData *)v4[1].mNode.mChild[0]) == 0i64 )
  {
    v5 = v3->m_pFallbackAnimation;
    if ( v5 )
    {
      v6 = v5->m_AnimationResourceHandle.mData;
      if ( !v6 )
        return 0.0;
      v4 = (UFG::qResourceData *)v6[1].mNode.mChild[0];
    }
    if ( !v4 )
      return 0.0;
  }
  v7 = *(_QWORD *)&v4->mNode.mUID;
  if ( *(_QWORD *)(v7 + 32) )
  {
    v8 = *(unsigned int *)(v7 + 20);
    v9 = 0;
    v10 = 0;
    (*(void (__fastcall **)(__int64, float *, __int64, _QWORD, float *, int, int))(*(_QWORD *)v7 + 112i64))(
      v7,
      &v13,
      v2,
      0i64,
      &v13,
      v10,
      v9);
    v11 = (__m128)v14;
    v11.m128_f32[0] = (float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v13 * v13);
    LODWORD(result) = (unsigned __int128)_mm_sqrt_ps(v11);
    return result;
  }
  return 0.0;
}

// File Line: 3888
// RVA: 0x3AF0E0
void __fastcall AnimationNode::SetDesiredExtractedMotionSpeed(AnimationNode *this, float extractedSpeed)
{
  AnimationNode *v2; // rbx

  v2 = this;
  if ( AnimationNode::getAverageExtractedSpeed(this) >= 0.001 )
    v2->vfptr[3].ResolveReferences((Expression::IMemberMap *)&v2->vfptr);
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
  Creature *v2; // rbx
  void **v3; // [rsp+20h] [rbp-28h]
  char v4; // [rsp+28h] [rbp-20h]
  unsigned int v5; // [rsp+30h] [rbp-18h]

  v2 = creature;
  v4 = 1;
  v3 = &ConstructNetSequence::`vftable;
  v5 = creature->mNetPoseSequence;
  this->vfptr[1].FindWithOldPath((Expression::IMemberMap *)this, (const char *)&v3);
  v2->mNetPoseSequence = v5;
}

// File Line: 3941
// RVA: 0x3ABC40
char __fastcall PoseNode::NetSerialize(PoseNode *this, NetAnimationState *state, Creature *creature)
{
  PoseNode *v3; // rdi
  __int64 v4; // rcx
  Creature *v5; // rsi
  NetAnimationState::AnimationEntry *v6; // rbx
  unsigned __int16 v7; // ax

  v3 = this;
  v4 = state->mEntryCount;
  v5 = creature;
  if ( (signed int)v4 >= 64 )
    return 0;
  state->mEntryCount = v4 + 1;
  v6 = &state->mEntries[v4];
  UFG::qMemSet(v6, 0, 0x60u);
  if ( !v6 )
    return 0;
  v6->mPose.mType = 0;
  if ( v3->mNetPoseSequence < 0 )
    v3->vfptr[3].Serialize((Expression::IMemberMap *)&v3->vfptr, (IActionTreeSerializer *)v5);
  v7 = v3->mNetPoseSequence;
  v6->mPose.mLocalTime = 0.0;
  v6->mPose.mSequence = v7;
  return 1;
}

// File Line: 3958
// RVA: 0x3AB9D0
char __fastcall AnimationNode::NetSerialize(AnimationNode *this, NetAnimationState *state, Creature *creature)
{
  SkeletalAnimation *v3; // rsi
  AnimationNode *v4; // rbx
  __int64 v5; // rcx
  Creature *v6; // rbp
  NetAnimationState::AnimationEntry *v7; // rdi

  v3 = this->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer;
  v4 = this;
  v5 = state->mEntryCount;
  v6 = creature;
  if ( (signed int)v5 >= 64 )
    return 0;
  state->mEntryCount = v5 + 1;
  v7 = &state->mEntries[v5];
  UFG::qMemSet(v7, 0, 0x60u);
  if ( !v7 )
    return 0;
  v7->mPose.mType = 1;
  if ( v4->mNetPoseSequence < 0 )
    v4->vfptr[3].Serialize((Expression::IMemberMap *)&v4->vfptr, (IActionTreeSerializer *)v6);
  v7->mPose.mSequence = v4->mNetPoseSequence;
  v7->mPose.mLocalTime = v4->mLocalTime;
  if ( v3 )
    v7->mAnimation.mAnimationUID = v3->mNameSymbol.mUID;
  else
    v7->mAnimation.mAnimationUID = 0;
  v7->mBlendDirection.mChildCount = (unsigned __int8)v4->mPlayMode.mValue;
  return 1;
}

// File Line: 3979
// RVA: 0x3ABCE0
char __fastcall PoseNodeParent::NetSerialize(PoseNodeParent *this, NetAnimationState *state, Creature *creature)
{
  char result; // al

  if ( (int *)&this->mChildren.mNode.mNext[-3].mNext == &this->mNetPoseSequence )
    result = PoseNode::NetSerialize((PoseNode *)&this->vfptr, state, creature);
  else
    result = ((__int64 (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, NetAnimationState *, Creature *))this->mChildren.mNode.mNext[-3].mNext[16].mPrev)(
               &this->mChildren.mNode.mNext[-3].mNext,
               state,
               creature);
  return result;
}

// File Line: 3997
// RVA: 0x3ABD10
char __fastcall BlendNode::NetSerializeBlend(BlendNode *this, PoseNodeType type, NetAnimationState *state, Creature *creature, bool holdPose)
{
  char v5; // si
  BlendNode *v6; // rbx
  UFG::qNode<PoseNode,PoseNode> **v7; // rax
  int *v8; // rcx
  Creature *v9; // rbp
  NetAnimationState *v10; // r14
  unsigned __int16 v11; // r15
  int v12; // er11
  signed __int64 v13; // r10
  __int64 v14; // rdx
  NetAnimationState::AnimationEntry *v15; // rdi
  Weightset *v16; // rax
  unsigned int v17; // eax
  Weightset *v18; // rax
  unsigned int v19; // ecx

  v5 = 0;
  v6 = this;
  v7 = &this->mChildren.mNode.mNext[-3].mNext;
  v8 = &this->mNetPoseSequence;
  v9 = creature;
  v10 = state;
  v11 = type;
  v12 = 0;
  v13 = (signed __int64)v7;
  if ( v7 == (UFG::qNode<PoseNode,PoseNode> **)v8 )
    return 0;
  do
  {
    ++v12;
    v13 = *(_QWORD *)(v13 + 48) - 40i64;
  }
  while ( (int *)v13 != v8 );
  if ( v12 != 2 )
  {
    for ( ; v7 != (UFG::qNode<PoseNode,PoseNode> **)v8; v7 = &v7[6][-3].mNext )
      ;
    return 0;
  }
  v14 = state->mEntryCount;
  if ( (signed int)v14 >= 64 )
    return 0;
  state->mEntryCount = v14 + 1;
  v15 = &state->mEntries[v14];
  UFG::qMemSet(v15, 0, 0x60u);
  if ( !v15 )
    return 0;
  v15->mPose.mType = v11;
  if ( v6->mNetPoseSequence < 0 )
    v6->vfptr[3].Serialize((Expression::IMemberMap *)&v6->vfptr, (IActionTreeSerializer *)v9);
  v15->mPose.mSequence = v6->mNetPoseSequence;
  v15->mPose.mLocalTime = v6->mLocalTime;
  v15->mAnimation.mAnimationUID = LODWORD(v6->mBlendParam);
  v15->mBlendDirection.mChildCount = LODWORD(v6->mBlendRate);
  v16 = v6->mWeightSet;
  if ( v16 )
    v17 = v16->mName.mUID;
  else
    v17 = 0;
  v15->mBlend.mWeightSetUID = v17;
  v18 = v6->mWeightSetMask;
  if ( v18 )
    v19 = v18->mName.mUID;
  else
    v19 = 0;
  v15->mBlend.mWeightSetMaskUID = v19;
  v15->mBlend.mStarted = v6->mStarted != 0;
  v15->mBlend.mSyncOnStart = v6->mSyncOnStart != 0;
  v15->mBlend.mPauseBlend = v6->mPauseBlend != 0;
  v15->mBlend.mPauseBlend = v6->mPauseBlend != 0;
  v15->mBlend.mKeepBlend = v6->mKeepBlend != 0;
  v15->mBlend.mHoldPose = holdPose;
  if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, NetAnimationState *, Creature *))v6->mChildren.mNode.mNext[-3].mNext[16].mPrev)(
         &v6->mChildren.mNode.mNext[-3].mNext,
         v10,
         v9) )
  {
    if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, NetAnimationState *, Creature *))v6->mChildren.mNode.mPrev[-3].mNext[16].mPrev)(
           &v6->mChildren.mNode.mPrev[-3].mNext,
           v10,
           v9) )
    {
      v5 = 1;
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
char __fastcall BlendDirectionNode::NetSerialize(BlendDirectionNode *this, NetAnimationState *state, Creature *creature)
{
  BlendDirectionNode *v3; // rbx
  __int64 v4; // rcx
  Creature *v5; // rbp
  NetAnimationState *v6; // rsi
  NetAnimationState::AnimationEntry *v7; // rdi
  int *v8; // r14
  char v9; // di
  UFG::qNode<PoseNode,PoseNode> **i; // rbx
  char v11; // al

  v3 = this;
  v4 = state->mEntryCount;
  v5 = creature;
  v6 = state;
  if ( (signed int)v4 >= 64 )
    return 0;
  state->mEntryCount = v4 + 1;
  v7 = &state->mEntries[v4];
  UFG::qMemSet(v7, 0, 0x60u);
  if ( !v7 )
    return 0;
  v8 = &v3->mNetPoseSequence;
  v7->mPose.mType = 3;
  if ( v3->mNetPoseSequence < 0 )
    v3->vfptr[3].Serialize((Expression::IMemberMap *)&v3->vfptr, (IActionTreeSerializer *)v5);
  v7->mPose.mSequence = *(_WORD *)v8;
  v7->mPose.mLocalTime = v3->mLocalTime;
  v7->mAnimation.mAnimationUID = v3->mName.mUID;
  v7->mBlend.mWeightSetUID = LODWORD(v3->mActiveDirection);
  v7->mBlend.mWeightSetMaskUID = LODWORD(v3->mDesiredActiveDirection);
  v7->mBlendDirection.mChildCount = (__int64)v3->vfptr[1].CreateClone((Expression::IMemberMap *)&v3->vfptr);
  v9 = 1;
  for ( i = &v3->mChildren.mNode.mNext[-3].mNext; i != (UFG::qNode<PoseNode,PoseNode> **)v8; v9 &= v11 )
  {
    v11 = ((__int64 (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, NetAnimationState *, Creature *))(*i)[16].mPrev)(
            i,
            v6,
            v5);
    i = &i[6][-3].mNext;
  }
  return v9;
}

// File Line: 4098
// RVA: 0x3ABAA0
bool __fastcall BlendAddNode::NetSerialize(BlendAddNode *this, NetAnimationState *state, Creature *creature)
{
  return BlendNode::NetSerializeBlend((BlendNode *)&this->vfptr, PNT_BLEND_ADD, state, creature, 0);
}

// File Line: 4107
// RVA: 0x3ABC20
bool __fastcall BlendSubNode::NetSerialize(BlendSubNode *this, NetAnimationState *state, Creature *creature)
{
  return BlendNode::NetSerializeBlend((BlendNode *)&this->vfptr, PNT_BLEND_SUB, state, creature, 0);
}

// File Line: 4117
// RVA: 0x3ABBF0
bool __fastcall BlendPhaseNode::NetSerialize(BlendPhaseNode *this, NetAnimationState *state, Creature *creature)
{
  return BlendNode::NetSerializeBlend((BlendNode *)&this->vfptr, PNT_BLEND_PHASE, state, creature, this->mHoldPose != 0);
}

// File Line: 4404
// RVA: 0x3B6B60
float __fastcall BlendHistoryNode::getActivePoses(BlendHistoryNode *this, PoseNode **poseNode0, PoseNode **poseNodeF)
{
  UFG::qNode<BlendHistoryNode::TimeRecord,BlendHistoryNode::TimeRecord> *v3; // rax
  int v4; // er11
  UFG::qList<BlendHistoryNode::TimeRecord,BlendHistoryNode::TimeRecord,1,0> *v5; // r10
  float v6; // xmm2_4
  PoseNode **v7; // rbx
  PoseNode **v8; // rdi
  int v9; // er9
  float v10; // xmm1_4
  float v11; // xmm0_4
  int *v12; // r8
  int v13; // edx
  PoseNode *v14; // rax
  signed __int64 i; // rcx
  UFG::qList<BlendHistoryNode::TimeRecord,BlendHistoryNode::TimeRecord,1,0> *j; // rcx
  int v17; // ecx
  UFG::qNode<BlendHistoryNode::TimeRecord,BlendHistoryNode::TimeRecord> *v18; // rax

  v3 = this->mTimeRecords.mNode.mNext;
  v4 = 0;
  v5 = &this->mTimeRecords;
  v6 = 0.0;
  v7 = poseNodeF;
  v8 = poseNode0;
  v9 = 0;
  v10 = 0.0;
  v11 = *(float *)&v3[1].mPrev + this->mLocalTime;
  if ( v3 != (UFG::qNode<BlendHistoryNode::TimeRecord,BlendHistoryNode::TimeRecord> *)&this->mTimeRecords )
  {
    do
    {
      if ( v11 < *(float *)&v3[1].mPrev )
        break;
      v3 = v3->mNext;
      ++v9;
    }
    while ( v3 != (UFG::qNode<BlendHistoryNode::TimeRecord,BlendHistoryNode::TimeRecord> *)v5 );
    if ( v9 > 0 )
    {
      v12 = &this->mNetPoseSequence;
      v13 = 0;
      v14 = (PoseNode *)&this->mChildren.mNode.mNext[-3].mNext;
      for ( i = (signed __int64)v14; (int *)i != v12; i = *(_QWORD *)(i + 48) - 40i64 )
        ++v13;
      if ( v9 < v13 )
      {
        for ( j = (UFG::qList<BlendHistoryNode::TimeRecord,BlendHistoryNode::TimeRecord,1,0> *)v5->mNode.mNext;
              j != v5;
              ++v4 )
        {
          j = (UFG::qList<BlendHistoryNode::TimeRecord,BlendHistoryNode::TimeRecord,1,0> *)j->mNode.mNext;
        }
        if ( v9 < v4 )
        {
          v17 = v9;
          do
          {
            if ( v14 == (PoseNode *)v12 )
              break;
            --v17;
            v14 = (PoseNode *)&v14->mNext[-3].mNext;
          }
          while ( v17 > 0 );
          *v7 = v14;
          *v8 = (PoseNode *)&v14->mPrev[-3].mNext;
          v18 = v5->mNode.mNext;
          do
          {
            if ( v18 == (UFG::qNode<BlendHistoryNode::TimeRecord,BlendHistoryNode::TimeRecord> *)v5 )
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


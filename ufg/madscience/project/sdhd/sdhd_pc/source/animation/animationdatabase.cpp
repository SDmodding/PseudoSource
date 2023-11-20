// File Line: 187
// RVA: 0x3ADB60
void __fastcall ReloadHotSwapBinFile(const char *filename)
{
  UFG::qString *v1; // rax
  UFG::qString v2; // [rsp+28h] [rbp-60h]
  UFG::qString result; // [rsp+50h] [rbp-38h]

  UFG::qString::qString(&v2, filename);
  v1 = UFG::qString::GetFilenameWithoutExtension(&v2, &result);
  AnimationDataBase::ReLoadAnimBankData(AnimationDataBase::sAnimationDataBase, v1->mData);
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&v2);
}

// File Line: 194
// RVA: 0x3ADBC0
void __fastcall ReloadHotSwapBtrFile(const char *filename)
{
  const char *v1; // rbp
  UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *v2; // rdi
  char *v3; // rcx
  signed __int64 v4; // rbx
  UFG::qList<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent,1,0> *v5; // rcx
  UFG::qList<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent,1,0> *v6; // rbx
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *v7; // rcx
  char *v8; // rcx
  signed __int64 v9; // rbx
  UFG::qString v10; // [rsp+28h] [rbp-30h]

  v1 = filename;
  v2 = (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *)((char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList
                                                                       - 152);
  v3 = (char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext[-10].mNext;
  if ( &UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext[-10].mNext != (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> **)((char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList - 152) )
  {
    do
    {
      v4 = *((_QWORD *)v3 + 20) - 152i64;
      ActionController::Stop((ActionController *)(v3 + 192));
      v3 = (char *)v4;
    }
    while ( (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *)v4 != v2 );
  }
  v5 = (UFG::qList<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent,1,0> *)&UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mNext[-13].mNext;
  if ( &UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mNext[-13].mNext != (UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> **)((char *)&UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList - 200) )
  {
    do
    {
      v6 = (UFG::qList<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent,1,0> *)&v5[13].mNode.mPrev[-13].mNext;
      v7 = v5[9].mNode.mNext;
      if ( v7 && !LOBYTE(v7[2].mNext) )
        ((void (__cdecl *)(UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *))v7[31].mPrev[24].mNext)(&v7[31]);
      v5 = v6;
    }
    while ( v6 != (UFG::qList<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent,1,0> *)((char *)&UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList - 200) );
  }
  UFG::qString::qString(&v10, v1);
  BlendTreeDataBase::ReLoadBlendTrees(BlendTreeDataBase::sBlendTreeDataBase, v10.mData);
  ActionNode::ResolveReferencesGlobal();
  v8 = (char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext[-10].mNext;
  if ( (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *)((char *)UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext
                                                                       - 152) != v2 )
  {
    do
    {
      v9 = *((_QWORD *)v8 + 20) - 152i64;
      ActionController::Play((ActionController *)(v8 + 192));
      v8 = (char *)v9;
    }
    while ( (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *)v9 != v2 );
  }
  UFG::qString::~qString(&v10);
}

// File Line: 227
// RVA: 0x3ADD10
void __fastcall ReloadHotSwapBtrFile_Bin(const char *filename)
{
  char *v1; // rcx
  UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *v2; // rdi
  signed __int64 v3; // rbx
  UFG::qList<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent,1,0> *v4; // rcx
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *v5; // rbx
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *v6; // rcx
  UFG::qList<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent,1,0> *v7; // rbx
  char *v8; // rcx
  signed __int64 v9; // rbx

  v1 = (char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext[-10].mNext;
  v2 = (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *)((char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList
                                                                       - 152);
  if ( &UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext[-10].mNext != (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> **)((char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList - 152) )
  {
    do
    {
      v3 = *((_QWORD *)v1 + 20) - 152i64;
      ActionController::Stop((ActionController *)(v1 + 192));
      v1 = (char *)v3;
    }
    while ( (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *)v3 != v2 );
  }
  v4 = (UFG::qList<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent,1,0> *)&UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mNext[-13].mNext;
  if ( &UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mNext[-13].mNext != (UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> **)((char *)&UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList - 200) )
  {
    do
    {
      v5 = v4[13].mNode.mPrev;
      v6 = v4[9].mNode.mNext;
      v7 = (UFG::qList<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent,1,0> *)&v5[-13].mNext;
      if ( v6 && !LOBYTE(v6[2].mNext) )
        ((void (*)(void))v6[31].mPrev[24].mNext)();
      v4 = v7;
    }
    while ( v7 != (UFG::qList<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent,1,0> *)((char *)&UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList - 200) );
  }
  UFG::StreamResourceLoader::UnloadResourceFile("Data\\Global\\btr_files.bin");
  UFG::StreamResourceLoader::LoadResourceFile("Data\\Global\\btr_files.bin", UFG::gMainMemoryPool, 0, 0i64, 0i64, 0i64);
  ActionNode::ResolveReferencesGlobal();
  v8 = (char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext[-10].mNext;
  if ( (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *)((char *)UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext
                                                                       - 152) != v2 )
  {
    do
    {
      v9 = *((_QWORD *)v8 + 20) - 152i64;
      ActionController::Play((ActionController *)(v8 + 192));
      v8 = (char *)v9;
    }
    while ( (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *)v9 != v2 );
  }
}

// File Line: 261
// RVA: 0x3AFC70
bool __fastcall SortDescendingPriority(AnimationGroup *const a, AnimationGroup *const b)
{
  char v2; // al
  char v3; // r8

  v2 = b->mCurrentAnimationPriority.mValue;
  v3 = a->mCurrentAnimationPriority.mValue;
  if ( v2 < v3 )
    return 1;
  if ( v2 == v3 )
    return b->mCurrentAnimationSubPriority <= a->mCurrentAnimationSubPriority;
  return 0;
}

// File Line: 279
// RVA: 0x14B9730
__int64 dynamic_initializer_for__BlendTreeDataBase::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("BlendTreeDataBase", 0xFFFFFFFF);
  BlendTreeDataBase::sClassNameUID = result;
  return result;
}

// File Line: 284
// RVA: 0x3AA8E0
void BlendTreeDataBase::Init(void)
{
  char *v0; // rcx
  void (__fastcall *v1)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // rax
  hkResourceHandle *v2; // rax
  fastdelegate::FastDelegate1<char const *,void> v3; // [rsp+38h] [rbp-30h]
  void (__fastcall *v4)(const char *); // [rsp+48h] [rbp-20h]
  void (__fastcall *v5)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // [rsp+50h] [rbp-18h]
  _QWORD *v6; // [rsp+78h] [rbp+10h]

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x30ui64, "BlendTreeDataBase", 0i64, 1u);
  if ( v0 )
  {
    *(_QWORD *)v0 = &Expression::IMemberMap::`vftable;
    *((_QWORD *)v0 + 1) = 0i64;
    *(_QWORD *)v0 = &BlendTreeDataBase::`vftable;
    *((_QWORD *)v0 + 3) = 0i64;
    *((_QWORD *)v0 + 2) = 0i64;
    v6 = v0 + 32;
    *v6 = v6;
    v6[1] = v6;
  }
  else
  {
    v0 = 0i64;
  }
  BlendTreeDataBase::sBlendTreeDataBase = (BlendTreeDataBase *)v0;
  v3 = UFG::DefaultHotSwapCallBack;
  v1 = fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  if ( !ReloadHotSwapBtrFile_Bin )
    v1 = 0i64;
  v5 = v1;
  v4 = ReloadHotSwapBtrFile_Bin;
  v2 = (hkResourceHandle *)UFG::HotSwapFileManager::Get();
  TargetVisibleInAIDataCondition::CreateClone(v2);
}

// File Line: 320
// RVA: 0x3A8EB0
BlendTreeDataBase *__fastcall BlendTreeDataBase::GetInstance()
{
  return BlendTreeDataBase::sBlendTreeDataBase;
}

// File Line: 334
// RVA: 0x39F700
void __fastcall BlendTreeDataBase::~BlendTreeDataBase(BlendTreeDataBase *this)
{
  BlendTreeDataBase *v1; // rdi
  UFG::qList<PoseNode,PoseNode,1,0> *v2; // rbx
  UFG::qNode<PoseNode,PoseNode> *v3; // rcx
  UFG::qNode<PoseNode,PoseNode> *v4; // rax
  BlendTreeDataBase::PoseNodeLookupEntry *v5; // rcx
  PoseNode **v6; // rbx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&BlendTreeDataBase::`vftable;
  v2 = &this->mPoseNodes;
  UFG::qList<PoseNode,PoseNode,1,0>::DeleteNodes(&this->mPoseNodes);
  v3 = v2->mNode.mPrev;
  v4 = v2->mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v5 = v1->mPoseNodeLookup.p;
  if ( v5 )
  {
    v6 = &v5[-1].mpPoseNode;
    `eh vector destructor iterator(v5, 0x10ui64, (int)v5[-1].mpPoseNode, (void (__fastcall *)(void *))_);
    operator delete[](v6);
  }
  v1->mPoseNodeLookup.p = 0i64;
  *(_QWORD *)&v1->mPoseNodeLookup.size = 0i64;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 341
// RVA: 0x14B9630
__int64 dynamic_initializer_for__AnimationDataBase::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AnimationDataBase", 0xFFFFFFFF);
  AnimationDataBase::sClassNameUID = result;
  return result;
}

// File Line: 386
// RVA: 0x14BCF40
__int64 dynamic_initializer_for__gBankNameFilter__()
{
  UFG::qString::qString(&gBankNameFilter);
  return atexit(dynamic_atexit_destructor_for__gBankNameFilter__);
}

// File Line: 387
// RVA: 0x14BD020
__int64 dynamic_initializer_for__gReferencedByFilter__()
{
  UFG::qString::qString(&gReferencedByFilter);
  return atexit(dynamic_atexit_destructor_for__gReferencedByFilter__);
}

// File Line: 402
// RVA: 0x3AA800
void AnimationDataBase::Init(void)
{
  char *v0; // rax
  AnimationDataBase *v1; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x360ui64, "AnimationDataBase", 0i64, 1u);
  if ( v0 )
  {
    AnimationDataBase::AnimationDataBase((AnimationDataBase *)v0);
    AnimationDataBase::sAnimationDataBase = v1;
  }
  else
  {
    AnimationDataBase::sAnimationDataBase = 0i64;
  }
}

// File Line: 438
// RVA: 0x3A8EA0
AnimationDataBase *__fastcall AnimationDataBase::GetInstance()
{
  return AnimationDataBase::sAnimationDataBase;
}

// File Line: 461
// RVA: 0x39CE10
void __fastcall AnimationDataBase::AnimationDataBase(AnimationDataBase *this)
{
  AnimationDataBase *v1; // rdi
  UFG::StreamPrioritySystem *v2; // rbx
  signed int v3; // ecx
  UFG::eAnimationPriorityEnum *v4; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::StreamPrioritySystem *v6; // rax
  UFG::qList<AnimationGroup,AnimationGroupBudgetedList,0,0> *v7; // [rsp+68h] [rbp+10h]
  UFG::qList<AnimationGroup,AnimationGroupUpdateList,0,0> *v8; // [rsp+68h] [rbp+10h]

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  v2 = 0i64;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationDataBase::`vftable;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mAnimGroups.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mAnimations.mTree);
  `eh vector constructor iterator(
    v1->mDefaultReferenceContainers,
    0x18ui64,
    17,
    (void (__fastcall *)(void *))AnimationGroupHandleContainer::AnimationGroupHandleContainer);
  v7 = &v1->mBudgetedAnimationGroups;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  v8 = &v1->mQueuedUpdateGroups;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
  v3 = 16;
  v4 = &v1->mPriorityBudgets.p[0].mOverFlowPriority;
  do
  {
    *((_QWORD *)v4 - 1) = 0i64;
    *v4 = 0;
    v4 += 3;
    --v3;
  }
  while ( v3 >= 0 );
  v1->mPriorityBudgets.size = 0;
  UFG::qString::qString(&v1->mGlobalFallbackAnimation);
  v5 = UFG::qMalloc(0x70ui64, "AnimationDataBase.StreamPrioritySystem", 0i64);
  if ( v5 )
  {
    UFG::StreamPrioritySystem::StreamPrioritySystem(
      (UFG::StreamPrioritySystem *)v5,
      5u,
      DATA_ANIMATION,
      0,
      g_HK_AnimationMemoryPoolSize - 0x100000,
      1500,
      0x30000u,
      0xA0000u);
    v2 = v6;
  }
  v1->m_pStreamPrioritySystem = v2;
  AnimationGroup::sStreamPrioritySystem = v2;
  NISManager::sStreamPrioritySystem = v1->m_pStreamPrioritySystem;
  UFG::qString::Set(&v1->mGlobalFallbackAnimation, "LOC_Stand_Idle");
  v1->mPriorityBudgets.size = 17;
  v1->mPriorityBudgets.p[9].mMaxSize = 0x100000;
  v1->mPriorityBudgets.p[9].mOverFlowPriority = 5;
  v1->mPriorityBudgets.p[5].mMaxSize = 0x800000;
  v1->mPriorityBudgets.p[5].mOverFlowPriority = 4;
  v1->mPriorityBudgets.p[4].mMaxSize = 0x400000;
  v1->mPriorityBudgets.p[4].mOverFlowPriority = 3;
  v1->mPriorityBudgets.p[3].mMaxSize = 0x800000;
  v1->mPriorityBudgets.p[3].mOverFlowPriority = 2;
  v1->mUseFallbackAnimations = 1;
}

// File Line: 575
// RVA: 0x39ECD0
void __fastcall AnimationDataBase::~AnimationDataBase(AnimationDataBase *this)
{
  AnimationDataBase *v1; // rsi
  Render::Skinning *v2; // rdi
  Render::SkinningCacheNode *v3; // rax
  signed __int64 v4; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v5; // rdx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationDataBase::`vftable;
  v2 = (Render::Skinning *)&this->mAnimGroups;
  if ( this->mAnimGroups.mTree.mCount )
  {
    while ( 1 )
    {
      v3 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&v2->mSkinnedVertexBuffers);
      if ( !v3 )
        break;
      v4 = (signed __int64)&v3[-1];
      if ( v3 == (Render::SkinningCacheNode *)40 )
        goto LABEL_6;
      v5 = &v3->mNode;
LABEL_7:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v2->mSkinnedVertexBuffers.mTree, v5);
      if ( v4 )
        (*(void (__fastcall **)(signed __int64, signed __int64))(*(_QWORD *)v4 + 8i64))(v4, 1i64);
      if ( !v2->mSkinnedVertexBuffers.mTree.mCount )
        goto LABEL_10;
    }
    v4 = 0i64;
LABEL_6:
    v5 = 0i64;
    goto LABEL_7;
  }
LABEL_10:
  AnimationGroup::sStreamPrioritySystem = 0i64;
  UFG::qString::~qString(&v1->mGlobalFallbackAnimation);
  v1->mPriorityBudgets.size = 0;
  UFG::qList<ActionNodeBank,ActionNodeBank,0,1>::~qList<ActionNodeBank,ActionNodeBank,0,1>((UFG::qList<ActionNodeBank,ActionNodeBank,0,1> *)&v1->mQueuedUpdateGroups);
  UFG::qList<AnimationGroup,AnimationGroupBudgetedList,0,0>::~qList<AnimationGroup,AnimationGroupBudgetedList,0,0>(&v1->mBudgetedAnimationGroups);
  `eh vector destructor iterator(
    v1->mDefaultReferenceContainers,
    0x18ui64,
    17,
    (void (__fastcall *)(void *))AnimationGroupHandleContainer::~AnimationGroupHandleContainer);
  UFG::qTreeRB<AnimationGroup,AnimationGroup,1>::DeleteAll(&v1->mAnimations);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->mAnimations);
  UFG::qTreeRB<AnimationGroup,AnimationGroup,1>::DeleteAll((UFG::qTreeRB<SkeletalAnimation,SkeletalAnimation,1> *)v2);
  UFG::qBaseTreeRB::~qBaseTreeRB(v2);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 584
// RVA: 0x3A7B80
__int64 __fastcall AnimationDataBase::GetAvailablePriority(AnimationDataBase *this, __int64 requestPriority, const unsigned int size)
{
  signed __int64 v3; // rax
  unsigned int v4; // er11
  unsigned int *v5; // rax

  v3 = 3i64 * (unsigned int)requestPriority + 151;
  v4 = *((_DWORD *)&this->vfptr + v3);
  v5 = (unsigned int *)((char *)this + 4 * v3);
  if ( v4 )
  {
    do
    {
      if ( size + v5[1] <= v4 )
        break;
      requestPriority = v5[2];
      v5 = (unsigned int *)((char *)this + 4 * (requestPriority + 2 * requestPriority + 151));
      v4 = *v5;
    }
    while ( *v5 );
  }
  return (unsigned int)requestPriority;
}

// File Line: 605
// RVA: 0x3B4B40
void __fastcall AnimationDataBase::UpdateQueuedUpdateGroups(AnimationDataBase *this)
{
  AnimationDataBase *v1; // rdi
  AnimationGroup *v2; // rsi
  AnimationGroup *v3; // rcx
  signed __int64 v4; // rbx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *i; // rax
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v6; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v7; // rdx

  v1 = this;
  v2 = (AnimationGroup *)&this->mDefaultReferenceContainers[14];
  v3 = (AnimationGroup *)&this->mQueuedUpdateGroups.mNode.mNext[-6].mNext;
  if ( v3 != v2 )
  {
    do
    {
      v4 = (signed __int64)&v3->mNext[-6].mNext;
      AnimationGroup::UpdatePriorityFromHandles(v3);
      v3 = (AnimationGroup *)v4;
    }
    while ( (AnimationGroup *)v4 != v2 );
  }
  for ( i = v1->mQueuedUpdateGroups.mNode.mNext;
        &i[-6].mNext != (UFG::qNode<AnimationGroup,AnimationGroupUpdateList> **)&v1->mDefaultReferenceContainers[14];
        i = v1->mQueuedUpdateGroups.mNode.mNext )
  {
    v6 = i->mNext;
    v7 = i->mPrev;
    v7->mNext = v6;
    v6->mPrev = v7;
    i->mPrev = i;
    i->mNext = i;
  }
}

// File Line: 633
// RVA: 0x3B06B0
void __fastcall AnimationDataBase::Update(AnimationDataBase *this, const float fDeltaS)
{
  AnimationDataBase *v2; // rsi
  __int64 v3; // rcx
  unsigned int *v4; // rax
  signed __int64 v5; // rbx
  __int64 v6; // rdi
  signed __int64 v7; // rbp
  unsigned int v8; // er14
  _DWORD *v9; // rdx
  unsigned int v10; // er8
  UFG::StreamPriorityHandle *v11; // rdx
  __int64 v12; // r8
  unsigned int v13; // ebx
  _DWORD *v14; // rdx
  unsigned int v15; // er9

  v2 = this;
  AnimationDataBase::UpdateQueuedUpdateGroups(this);
  UFG::qList<AnimationGroup,AnimationGroupBudgetedList,0,0>::MergeSort(
    &v2->mBudgetedAnimationGroups,
    (bool (__fastcall *)(AnimationGroup *, AnimationGroup *))SortDescendingPriority);
  v3 = v2->mPriorityBudgets.size;
  if ( (_DWORD)v3 )
  {
    v4 = &v2->mPriorityBudgets.p[0].mUsedSize;
    do
    {
      *v4 = 0;
      v4 += 3;
      --v3;
    }
    while ( v3 );
  }
  v5 = (signed __int64)&v2->mBudgetedAnimationGroups.mNode.mNext[-5].mNext;
  if ( (AnimationGroupHandleContainer *)v5 != &v2->mDefaultReferenceContainers[14] )
  {
    do
    {
      v6 = (unsigned int)*(char *)(v5 + 198);
      v7 = *(_QWORD *)(v5 + 80) - 72i64;
      if ( v2->mPriorityBudgets.p[v6].mMaxSize )
      {
        v8 = *(_DWORD *)(v5 + 168);
        v9 = (_DWORD *)((char *)v2 + 12 * v6);
        v10 = v9[151];
        if ( v10 && v8 + v9[152] > v10 )
          LODWORD(v6) = AnimationDataBase::GetAvailablePriority(v2, (unsigned int)v9[153], v8);
        if ( (_DWORD)v6 != *(char *)(v5 + 198) )
        {
          v11 = *(UFG::StreamPriorityHandle **)(v5 + 104);
          *(_BYTE *)(v5 + 198) = v6;
          *(_WORD *)(v5 + 196) = -1;
          if ( v11 )
            UFG::StreamPrioritySystem::ChangePriority(
              AnimationGroup::sStreamPrioritySystem,
              v11,
              ((unsigned __int16)(char)v6 << 16) | 0xFFFF);
        }
        if ( v2->mPriorityBudgets.p[(unsigned int)v6].mMaxSize )
          v2->mPriorityBudgets.p[(unsigned int)v6].mUsedSize += v8;
      }
      else
      {
        v12 = (unsigned int)*(char *)(v5 + 200);
        if ( v2->mPriorityBudgets.p[v12].mMaxSize )
        {
          v13 = *(_DWORD *)(v5 + 168);
          v14 = (_DWORD *)((char *)v2 + 12 * v12);
          v15 = v14[151];
          if ( v15 && v13 + v14[152] > v15 )
            LODWORD(v12) = AnimationDataBase::GetAvailablePriority(v2, (unsigned int)v14[153], v13);
          if ( v2->mPriorityBudgets.p[(unsigned int)v12].mMaxSize )
            v2->mPriorityBudgets.p[(unsigned int)v12].mUsedSize += v13;
        }
      }
      v5 = v7;
    }
    while ( (AnimationGroupHandleContainer *)v7 != &v2->mDefaultReferenceContainers[14] );
  }
  UFG::StreamPrioritySystem::Update(v2->m_pStreamPrioritySystem);
}

// File Line: 771
// RVA: 0x3A7910
PoseNode *__fastcall BlendTreeDataBase::FindBlendTree(BlendTreeDataBase *this, UFG::qSymbolUC *animUID)
{
  BlendTreeDataBase *v2; // rax
  unsigned int v3; // ecx
  int v4; // er8
  int v5; // ecx
  BlendTreeDataBase::PoseNodeLookupEntry *v6; // r11
  unsigned int v7; // er10
  unsigned int v8; // eax
  unsigned int v9; // er9

  v2 = this;
  v3 = this->mPoseNodeLookup.size;
  if ( !v3 )
    return 0i64;
  v4 = 0;
  v5 = v3 - 1;
  if ( v5 < 0 )
    return 0i64;
  v6 = v2->mPoseNodeLookup.p;
  v7 = animUID->mUID;
  while ( 1 )
  {
    v8 = (v5 + v4) / 2;
    v9 = v6[v8].mName.mUID;
    if ( v7 <= v9 )
      break;
    v4 = v8 + 1;
LABEL_8:
    if ( v4 > v5 )
      return 0i64;
  }
  if ( v7 < v9 )
  {
    v5 = v8 - 1;
    goto LABEL_8;
  }
  return v6[(v5 + v4) / 2].mpPoseNode;
}

// File Line: 805
// RVA: 0x14BF3A0
const char *dynamic_initializer_for__sAnimationNodeFactoryList__()
{
  const char *result; // rax

  sAnimationNodeFactoryList[0].mClassName = AnimationGroup::sClassName;
  sAnimationNodeFactoryList[1].mClassName = SkeletalAnimation::sClassName;
  result = MotionPhaseChannel::sClassName;
  sAnimationNodeFactoryList[2].mClassName = MotionPhaseChannel::sClassName;
  return result;
}

// File Line: 811
// RVA: 0x14BCF10
__int64 dynamic_initializer_for__gAnimationNodeFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(
    &gAnimationNodeFactory,
    sAnimationNodeFactoryList,
    sAnimationNodeFactoryListNum);
  return atexit(dynamic_atexit_destructor_for__gAnimationNodeFactory__);
}

// File Line: 829
// RVA: 0x3AB380
AnimationGroup *__fastcall AnimationDataBase::LoadAnimBank(AnimationDataBase *this, const char *animBankName)
{
  const char *v2; // rbx
  AnimationDataBase *v3; // rdi
  UFG::qBaseTreeRB *v4; // rax
  signed __int64 v5; // rdi
  UFG::qSymbolUC result; // [rsp+38h] [rbp+10h]

  v2 = animBankName;
  v3 = this;
  if ( !animBankName )
    return 0i64;
  UFG::qSymbolUC::create_from_string(&result, animBankName);
  if ( !result.mUID )
    return 0i64;
  v4 = UFG::qBaseTreeRB::Get(&v3->mAnimGroups.mTree, result.mUID);
  if ( !v4 )
    return 0i64;
  v5 = (signed __int64)&v4[-1].mNULL;
  if ( v4 == (UFG::qBaseTreeRB *)40 )
    return 0i64;
  UFG::qPrintf("WARNING: Animation Group Already Loaded: %s\n", v2);
  return (AnimationGroup *)v5;
}

// File Line: 921
// RVA: 0x3A0B40
void __fastcall AnimationDataBase::AddAnimBank(AnimationDataBase *this, AnimationGroup *animGroup)
{
  AnimationDataBase *v2; // rdi
  AnimationGroup *v3; // rbx
  UFG::qBaseNodeRB *v4; // rdx

  v2 = this;
  v3 = animGroup;
  AnimationGroup::LoadInternal(animGroup);
  if ( v3 )
    v4 = &v3->mNode;
  else
    v4 = 0i64;
  UFG::qBaseTreeRB::Add(&v2->mAnimGroups.mTree, v4);
}

// File Line: 954
// RVA: 0x3AB2B0
char __fastcall AnimationDataBase::IsStreamedIn(AnimationDataBase *this, const char *animBankName)
{
  const char *v2; // rbx
  AnimationDataBase *v3; // rdi
  UFG::qBaseTreeRB *v4; // rax
  signed __int64 v5; // rax
  UFG::DataStreamer::Handle *v6; // rcx
  UFG::qSymbolUC result; // [rsp+38h] [rbp+10h]

  v2 = animBankName;
  v3 = this;
  if ( animBankName
    && (UFG::qSymbolUC::create_from_string(&result, animBankName), result.mUID)
    && (v4 = UFG::qBaseTreeRB::Get(&v3->mAnimGroups.mTree, result.mUID)) != 0i64
    && (v5 = (signed __int64)&v4[-1].mNULL) != 0 )
  {
    v6 = *(UFG::DataStreamer::Handle **)(v5 + 104);
    if ( v6 && (unsigned int)UFG::DataStreamer::GetStreamState(v6) == 6 )
      return 1;
  }
  else
  {
    UFG::qPrintf("WARNING: AnimationDataBase::IsStreamedIn: Animation Group Not Found (%s)!\n", v2);
  }
  return 0;
}

// File Line: 977
// RVA: 0x3B0440
void __fastcall AnimationDataBase::UnloadAnimBank(AnimationDataBase *this, const char *animBankName)
{
  const char *v2; // rbx
  AnimationDataBase *v3; // rsi
  UFG::qBaseTreeRB *v4; // rax
  signed __int64 v5; // rdi
  UFG::qSymbolUC result; // [rsp+38h] [rbp+10h]

  v2 = animBankName;
  v3 = this;
  if ( animBankName
    && (UFG::qSymbolUC::create_from_string(&result, animBankName), result.mUID)
    && (v4 = UFG::qBaseTreeRB::Get(&v3->mAnimGroups.mTree, result.mUID)) != 0i64
    && (v5 = (signed __int64)&v4[-1].mNULL, v4 != (UFG::qBaseTreeRB *)40) )
  {
    AnimationGroup::UnloadInternal((AnimationGroup *)&v4[-1].mNULL);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mAnimGroups,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)(v5 + 40));
    (*(void (__fastcall **)(signed __int64, signed __int64))(*(_QWORD *)v5 + 8i64))(v5, 1i64);
  }
  else
  {
    UFG::qPrintf("WARNING: AnimationDataBase::UnloadAnimBank: Animation Group Not Found (%s)!\n", v2);
  }
}

// File Line: 992
// RVA: 0x3ADF70
void __fastcall AnimationDataBase::RemoveAnimBank(AnimationDataBase *this, AnimationGroup *animationGroup)
{
  AnimationDataBase *v2; // rdi
  AnimationGroup *v3; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rdx

  v2 = this;
  v3 = animationGroup;
  AnimationGroup::UnloadInternal(animationGroup);
  if ( v3 )
    v4 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v3->mNode;
  else
    v4 = 0i64;
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)&v2->mAnimGroups, v4);
}

// File Line: 1039
// RVA: 0x3AD5D0
void __fastcall AnimationDataBase::ReLoadAnimBankData(AnimationDataBase *this, const char *animBankName)
{
  AnimationDataBase *v2; // rbx
  UFG::qBaseTreeRB *v3; // rax
  signed __int64 v4; // rbx
  UFG::StreamPriorityHandle *v5; // rdx
  UFG::StreamPriorityHandle *v6; // rdx
  UFG *v7; // rcx
  UFG::qSymbolUC result; // [rsp+38h] [rbp+10h]

  if ( animBankName )
  {
    v2 = this;
    UFG::qSymbolUC::create_from_string(&result, animBankName);
    if ( result.mUID )
    {
      v3 = UFG::qBaseTreeRB::Get(&v2->mAnimGroups.mTree, result.mUID);
      if ( v3 )
      {
        v4 = (signed __int64)&v3[-1].mNULL;
        if ( v3 != (UFG::qBaseTreeRB *)40 )
        {
          v5 = *(UFG::StreamPriorityHandle **)(v4 + 104);
          if ( v5 )
          {
            UFG::StreamPrioritySystem::EvictFromMemory(AnimationGroup::sStreamPrioritySystem, v5);
            v6 = *(UFG::StreamPriorityHandle **)(v4 + 104);
            if ( v6 )
              UFG::StreamPrioritySystem::ChangePriority(
                AnimationGroup::sStreamPrioritySystem,
                v6,
                *(unsigned __int16 *)(v4 + 196) | ((unsigned __int16)*(char *)(v4 + 198) << 16));
          }
          UFG::DataStreamer::Service(0.0);
          UFG::DataStreamer::Service(0.0);
          UFG::DataStreamer::Service(0.0);
          UFG::DataStreamer::Service(0.0);
          UFG::DataStreamer::Service(0.0);
          UFG::DataStreamer::Service(0.0);
          UFG::DataStreamer::Service(0.0);
          UFG::DataStreamer::Service(0.0);
          UFG::StreamPool_ClearAllCachedData(v7);
        }
      }
    }
  }
}

// File Line: 1067
// RVA: 0x3A2C60
void __fastcall AnimationDataBase::BindStaticGroups(AnimationDataBase *this)
{
  AnimationDataBase *v1; // r15
  Render::SkinningCacheNode *v2; // rax
  signed __int64 v3; // rbx
  UFG::qBaseNodeRB *v4; // rdx
  UFG::qBaseTreeRB *v5; // rax
  signed __int64 v6; // rdi
  signed __int64 v7; // rsi
  signed __int64 v8; // rbp
  bool v9; // di
  AnimationGroupHandle *i; // rbx
  char v11; // al

  v1 = this;
  v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mAnimGroups);
  if ( v2 )
  {
    v3 = (signed __int64)&v2[-1];
    if ( v2 != (Render::SkinningCacheNode *)40 )
    {
      do
      {
        if ( v3 )
          v4 = (UFG::qBaseNodeRB *)(v3 + 40);
        else
          v4 = 0i64;
        v5 = UFG::qBaseTreeRB::GetNext(&v1->mAnimGroups.mTree, v4);
        if ( v5 )
          v6 = (signed __int64)&v5[-1].mNULL;
        else
          v6 = 0i64;
        AnimationGroupHandleContainer::Add(
          (AnimationGroupHandleContainer *)(&v1->vfptr + *(char *)(v3 + 199) + 2 * (*(char *)(v3 + 199) + 10i64)),
          (UFG::qSymbolUC *)(v3 + 172),
          (UFG::eAnimationPriorityEnum)*(char *)(v3 + 199));
        v3 = v6;
      }
      while ( v6 );
    }
  }
  v7 = (signed __int64)&v1->mAnimations.mTree.mNULL.mUID;
  v8 = 17i64;
  do
  {
    v9 = 1;
    for ( i = (AnimationGroupHandle *)(*(_QWORD *)(v7 + 24) - 16i64);
          i != (AnimationGroupHandle *)v7;
          i = (AnimationGroupHandle *)&i->mNext[-1] )
    {
      v11 = AnimationGroupHandle::Bind(i);
      v9 = v9 && v11;
    }
    *(_BYTE *)(v7 + 32) = 1;
    v7 += 24i64;
    --v8;
  }
  while ( v8 );
  AnimationDataBase::Update(v1, 0.0);
}

// File Line: 1094
// RVA: 0x3B4B30
void __fastcall AnimationDataBase::UpdatePrioritySystem(AnimationDataBase *this)
{
  UFG::StreamPrioritySystem::Update(this->m_pStreamPrioritySystem);
}

// File Line: 1121
// RVA: 0x3AE390
void __fastcall AnimationDataBase::ResolveFallbackAnimations(AnimationDataBase *this)
{
  AnimationDataBase *v1; // rbx
  unsigned int v2; // eax
  UFG::qBaseTreeRB *v3; // rax
  SkeletalAnimation *v4; // rsi
  UFG::qBaseTreeRB *v5; // rbp
  Render::SkinningCacheNode *v6; // rax
  SkeletalAnimation *v7; // rbx
  UFG::qBaseNodeRB *v8; // rdx
  UFG::qBaseTreeRB *v9; // rax
  signed __int64 v10; // rdi

  v1 = this;
  if ( this->mUseFallbackAnimations )
  {
    v2 = UFG::qStringHashUpper32(this->mGlobalFallbackAnimation.mData, 0xFFFFFFFF);
    if ( v2 && (v3 = UFG::qBaseTreeRB::Get(&v1->mAnimations.mTree, v2)) != 0i64 )
      v4 = (SkeletalAnimation *)&v3[-1].mNULL;
    else
      v4 = 0i64;
    v5 = &v1->mAnimations.mTree;
    v6 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mAnimations);
    if ( v6 )
    {
      v7 = (SkeletalAnimation *)&v6[-1];
      if ( v6 != (Render::SkinningCacheNode *)40 )
      {
        do
        {
          if ( v7 )
            v8 = &v7->mNode;
          else
            v8 = 0i64;
          v9 = UFG::qBaseTreeRB::GetNext(v5, v8);
          if ( v9 )
            v10 = (signed __int64)&v9[-1].mNULL;
          else
            v10 = 0i64;
          SkeletalAnimation::ResolveFallbackAnimation(v7, v4);
          v7 = (SkeletalAnimation *)v10;
        }
        while ( v10 );
      }
    }
  }
}

// File Line: 1204
// RVA: 0x3A78D0
UFG::qBaseNodeRB *__fastcall AnimationDataBase::FindAnimBank(AnimationDataBase *this, const char *pAnimBankName)
{
  AnimationDataBase *v2; // rbx
  UFG::qBaseTreeRB *v3; // rax
  UFG::qBaseNodeRB *v4; // rax
  UFG::qSymbolUC result; // [rsp+38h] [rbp+10h]

  v2 = this;
  if ( pAnimBankName
    && (UFG::qSymbolUC::create_from_string(&result, pAnimBankName), result.mUID)
    && (v3 = UFG::qBaseTreeRB::Get(&v2->mAnimGroups.mTree, result.mUID)) != 0i64 )
  {
    v4 = &v3[-1].mNULL;
  }
  else
  {
    v4 = 0i64;
  }
  return v4;
}

// File Line: 1217
// RVA: 0x3A78A0
UFG::qBaseNodeRB *__fastcall AnimationDataBase::FindAnimBank(AnimationDataBase *this, UFG::qSymbolUC *theAnimationGroupSymbol)
{
  unsigned int v2; // edx
  UFG::qBaseTreeRB *v3; // rax
  UFG::qBaseNodeRB *result; // rax

  v2 = theAnimationGroupSymbol->mUID;
  if ( v2 && (v3 = UFG::qBaseTreeRB::Get(&this->mAnimGroups.mTree, v2)) != 0i64 )
    result = &v3[-1].mNULL;
  else
    result = 0i64;
  return result;
}

// File Line: 1239
// RVA: 0x3A13D0
void __fastcall BlendTreeDataBase::AddBlendTrees(BlendTreeDataBase *this, PoseNode *poseNode)
{
  UFG::qNode<PoseNode,PoseNode> *v2; // rax
  UFG::qNode<PoseNode,PoseNode> *v3; // rdx

  v2 = this->mPoseNodes.mNode.mPrev;
  v3 = (UFG::qNode<PoseNode,PoseNode> *)&poseNode->mPrev;
  v2->mNext = v3;
  v3->mPrev = v2;
  v3->mNext = &this->mPoseNodes.mNode;
  this->mPoseNodes.mNode.mPrev = v3;
  BlendTreeDataBase::RebuildPoseNodeLookup(this);
}

// File Line: 1246
// RVA: 0x3AE030
void __fastcall BlendTreeDataBase::RemoveBlendTrees(BlendTreeDataBase *this, PoseNode *poseNode)
{
  UFG::qNode<PoseNode,PoseNode> *v2; // rcx
  UFG::qNode<PoseNode,PoseNode> *v3; // rax
  UFG::qNode<PoseNode,PoseNode> *v4; // rdx

  v2 = poseNode->mPrev;
  v3 = poseNode->mNext;
  v4 = (UFG::qNode<PoseNode,PoseNode> *)&poseNode->mPrev;
  v2->mNext = v3;
  v3->mPrev = v2;
  v4->mPrev = v4;
  v4->mNext = v4;
}

// File Line: 1255
// RVA: 0x3AD990
void __fastcall BlendTreeDataBase::RebuildPoseNodeLookup(BlendTreeDataBase *this)
{
  UFG::qArray<BlendTreeDataBase::PoseNodeLookupEntry,0> *v1; // rdi
  BlendTreeDataBase *v2; // rsi
  BlendTreeDataBase::PoseNodeLookupEntry *v3; // rcx
  PoseNode **v4; // rbx
  signed __int64 v5; // r14
  __int64 v6; // rsi
  unsigned int v7; // edx
  int v8; // ebp
  signed __int64 v9; // r15
  unsigned int v10; // ebx
  unsigned int v11; // edx
  signed __int64 v12; // rax
  unsigned int v13; // esi
  int v14; // er13
  __int64 v15; // rax
  __int64 v16; // r15
  unsigned int v17; // edx
  int v18; // er12
  unsigned int v19; // ebx
  __int64 v20; // rbp
  unsigned int v21; // edx
  signed __int64 v22; // rax
  signed __int64 v23; // [rsp+60h] [rbp+8h]
  signed __int64 v24; // [rsp+68h] [rbp+10h]

  v1 = &this->mPoseNodeLookup;
  v2 = this;
  v3 = this->mPoseNodeLookup.p;
  if ( v3 )
  {
    v4 = &v3[-1].mpPoseNode;
    `eh vector destructor iterator(v3, 0x10ui64, (int)v3[-1].mpPoseNode, (void (__fastcall *)(void *))_);
    operator delete[](v4);
  }
  v1->p = 0i64;
  *(_QWORD *)&v1->size = 0i64;
  v24 = (signed __int64)&v2[-1].mPoseNodes.mNode.mNext;
  v5 = (signed __int64)&v2->mPoseNodes.mNode.mNext[-3].mNext;
  if ( (UFG::qNode<PoseNode,PoseNode> **)v5 != &v2[-1].mPoseNodes.mNode.mNext )
  {
    do
    {
      v6 = v1->size;
      v7 = v1->capacity;
      v8 = *(_DWORD *)(v5 + 68);
      v9 = *(_QWORD *)(v5 + 48) - 40i64;
      v10 = v6 + 1;
      v23 = *(_QWORD *)(v5 + 48) - 40i64;
      if ( (signed int)v6 + 1 > v7 )
      {
        if ( v7 )
          v11 = 2 * v7;
        else
          v11 = 1;
        for ( ; v11 < v10; v11 *= 2 )
          ;
        if ( v11 - v10 > 0x10000 )
          v11 = v6 + 65537;
        UFG::qArray<BlendTreeDataBase::PoseNodeLookupEntry,0>::Reallocate(v1, v11, "qArray.Add");
      }
      v1->size = v10;
      v12 = (signed __int64)&v1->p[v6];
      *(_DWORD *)v12 = v8;
      *(_QWORD *)(v12 + 8) = v5;
      v13 = 0;
      v14 = (*(__int64 (__fastcall **)(signed __int64))(*(_QWORD *)v5 + 96i64))(v5);
      if ( v14 > 0 )
      {
        do
        {
          v15 = (*(__int64 (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v5 + 88i64))(v5, v13);
          v16 = v1->size;
          v17 = v1->capacity;
          v18 = *(_DWORD *)(v15 + 68);
          v19 = v16 + 1;
          v20 = v15;
          if ( (signed int)v16 + 1 > v17 )
          {
            if ( v17 )
              v21 = 2 * v17;
            else
              v21 = 1;
            for ( ; v21 < v19; v21 *= 2 )
              ;
            if ( v21 - v19 > 0x10000 )
              v21 = v16 + 65537;
            UFG::qArray<BlendTreeDataBase::PoseNodeLookupEntry,0>::Reallocate(v1, v21, "qArray.Add");
          }
          v1->size = v19;
          ++v13;
          v22 = (signed __int64)&v1->p[v16];
          *(_DWORD *)v22 = v18;
          *(_QWORD *)(v22 + 8) = v20;
        }
        while ( (signed int)v13 < v14 );
        v9 = v23;
      }
      v5 = v9;
    }
    while ( v9 != v24 );
  }
  UFG::qQuickSortImpl<BlendTreeDataBase::PoseNodeLookupEntry,bool (*)(BlendTreeDataBase::PoseNodeLookupEntry const &,BlendTreeDataBase::PoseNodeLookupEntry const &)>(
    v1->p,
    &v1->p[(signed int)v1->size - 1],
    (bool (__fastcall *)(BlendTreeDataBase::PoseNodeLookupEntry *, BlendTreeDataBase::PoseNodeLookupEntry *))BlendTreeDataBase::UIDSort);
}

// File Line: 1336
// RVA: 0x39C4D0
bool __fastcall AnimGroupSortBySizeUsed(AnimationGroupStats *A, AnimationGroupStats *B)
{
  return B->mSizeUsed <= A->mSizeUsed;
}

// File Line: 1340
// RVA: 0x39C4E0
bool __fastcall AnimGroupSortBySizeTot(AnimationGroupStats *A, AnimationGroupStats *B)
{
  return B->mSizeTot <= A->mSizeTot;
}

// File Line: 1344
// RVA: 0x39C4F0
bool __fastcall AnimGroupSortByAnimRefCountTotal(AnimationGroupStats *A, AnimationGroupStats *B)
{
  return B->mAnimRefCountTotal >= A->mAnimRefCountTotal;
}

// File Line: 1348
// RVA: 0x39C500
bool __fastcall AnimGroupSortByAnimRefCount(AnimationGroupStats *A, AnimationGroupStats *B)
{
  return B->mAnimRefCount >= A->mAnimRefCount;
}

// File Line: 1352
// RVA: 0x39C510
bool __fastcall AnimGroupSortByRefCountTotal(AnimationGroupStats *A, AnimationGroupStats *B)
{
  return B->mRefCountTotal >= A->mRefCountTotal;
}

// File Line: 1356
// RVA: 0x39C520
bool __fastcall AnimGroupSortByRefCount(AnimationGroupStats *A, AnimationGroupStats *B)
{
  return B->mRefCount >= A->mRefCount;
}

// File Line: 1360
// RVA: 0x39C530
bool __fastcall AnimGroupSortByPriority(AnimationGroupStats *A, AnimationGroupStats *B)
{
  int v2; // eax
  int v3; // er8

  v2 = B->mCurrentPriority;
  v3 = A->mCurrentPriority;
  return v2 < v3 || v2 == v3 && B->mCurrentSubPriority <= A->mCurrentSubPriority;
}

// File Line: 1365
// RVA: 0x39C550
bool __fastcall AnimGroupSortByName(AnimationGroupStats *A, AnimationGroupStats *B)
{
  return (signed int)UFG::qStringCompareInsensitive(B->mName, A->mName, -1) >= 0;
}

// File Line: 2244
// RVA: 0x39D200
void __fastcall AnimationGroupHandle::AnimationGroupHandle(AnimationGroupHandle *this)
{
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v1; // rax
  UFG::qSafePointer<AnimationGroup,AnimationGroup> *v2; // [rsp+28h] [rbp+10h]

  this->mPrev = (UFG::qNode<AnimationGroupHandle,AnimationGroupList> *)&this->mPrev;
  this->mNext = (UFG::qNode<AnimationGroupHandle,AnimationGroupList> *)&this->mPrev;
  v1 = (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->m_AnimationGroupSymbol.mUID = -1;
  v2 = &this->m_AnimationGroup;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_AnimationGroup.m_pPointer = 0i64;
  *(_DWORD *)&this->m_eAnimationPriority.mValue = -65524;
  this->m_bHasBeenBound = 0;
  this->m_pReferenceInfo = 0i64;
}

// File Line: 2255
// RVA: 0x39F0F0
void __fastcall AnimationGroupHandle::~AnimationGroupHandle(AnimationGroupHandle *this)
{
  AnimationGroupHandle *v1; // rbx
  UFG::qSharedString *v2; // rdi
  UFG::qSafePointer<AnimationGroup,AnimationGroup> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v8; // rdx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v9; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v10; // rax
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *v11; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *v12; // rax

  v1 = this;
  AnimationGroupHandle::Unbind(this);
  UFG::qSymbolUC::set_null(&v1->m_AnimationGroupSymbol);
  v2 = (UFG::qSharedString *)v1->m_pReferenceInfo;
  if ( v2 )
  {
    UFG::qSharedString::~qSharedString(v2 + 1);
    operator delete[](v2);
  }
  v3 = &v1->m_AnimationGroup;
  if ( v1->m_AnimationGroup.m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = v1->m_AnimationGroup.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v1->m_AnimationGroup.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *)&v1->m_AnimationGroup.mPrev;
  }
  v1->m_AnimationGroup.m_pPointer = 0i64;
  v6 = v3->mPrev;
  v7 = v1->m_AnimationGroup.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v1->m_AnimationGroup.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *)&v1->m_AnimationGroup.mPrev;
  v8 = (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)&v1->mPrev;
  v9 = v1->mPrev;
  v10 = v1->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v8->mPrev = v8;
  v8->mNext = v8;
  v11 = v1->mPrev;
  v12 = v1->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v1->mPrev = (UFG::qNode<AnimationGroupHandle,AnimationGroupList> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<AnimationGroupHandle,AnimationGroupList> *)&v1->mPrev;
}

// File Line: 2268
// RVA: 0x3AA860
void __fastcall AnimationGroupHandle::Init(AnimationGroupHandle *this, UFG::qSymbolUC *theAnimationGroupSymbol, UFG::eAnimationPriorityEnum eAnimationPriority)
{
  unsigned int v3; // eax
  unsigned __int16 v4; // bp
  UFG::qSymbolUC *v5; // rsi
  AnimationGroupHandle *v6; // rbx

  v3 = this->m_AnimationGroupSymbol.mUID;
  v4 = eAnimationPriority;
  v5 = theAnimationGroupSymbol;
  v6 = this;
  if ( v3 != theAnimationGroupSymbol->mUID )
  {
    if ( v3 != -1 )
    {
      AnimationGroupHandle::Unbind(this);
      UFG::qSymbolUC::set_null(&v6->m_AnimationGroupSymbol);
    }
    v6->m_AnimationGroupSymbol = (UFG::qSymbolUC)v5->mUID;
    v6->m_eAnimationPriority.mValue = v4;
    v6->m_AnimationSubPriority = -1;
  }
}

// File Line: 2284
// RVA: 0x3AE0F0
void __fastcall AnimationGroupHandle::Reset(AnimationGroupHandle *this)
{
  AnimationGroupHandle *v1; // rbx

  v1 = this;
  AnimationGroupHandle::Unbind(this);
  UFG::qSymbolUC::set_null(&v1->m_AnimationGroupSymbol);
}

// File Line: 2296
// RVA: 0x3A2B60
char __fastcall AnimationGroupHandle::Bind(AnimationGroupHandle *this)
{
  AnimationGroupHandle *v1; // rbx
  unsigned int v2; // edx
  UFG::qBaseTreeRB *v3; // rax
  signed __int64 v4; // r8
  UFG::qSafePointer<AnimationGroup,AnimationGroup> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *v8; // rax
  AnimationGroup *v9; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *v10; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *v11; // rax
  AnimationGroup *v12; // rax
  AnimationGroup *v13; // rax
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v14; // rdx
  UFG::qList<AnimationGroup,AnimationGroupUpdateList,0,0> *v15; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v16; // rax

  v1 = this;
  if ( this->m_AnimationGroup.m_pPointer )
    AnimationGroupHandle::Unbind(this);
  v2 = v1->m_AnimationGroupSymbol.mUID;
  v1->m_bHasBeenBound = 1;
  if ( v2 && (v3 = UFG::qBaseTreeRB::Get(&AnimationDataBase::sAnimationDataBase->mAnimGroups.mTree, v2)) != 0i64 )
    v4 = (signed __int64)&v3[-1].mNULL;
  else
    v4 = 0i64;
  v5 = &v1->m_AnimationGroup;
  if ( v1->m_AnimationGroup.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->m_AnimationGroup.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->m_AnimationGroup.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *)&v1->m_AnimationGroup.mPrev;
  }
  v1->m_AnimationGroup.m_pPointer = (AnimationGroup *)v4;
  if ( v4 )
  {
    v8 = *(UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> **)(v4 + 24);
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v5->mPrev = v8;
    v1->m_AnimationGroup.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *)(v4 + 24);
    *(_QWORD *)(v4 + 24) = v5;
  }
  v9 = v1->m_AnimationGroup.m_pPointer;
  if ( !v9 || !v9->mMemorySize )
    return 0;
  v10 = &v9->mAnimGroupHandles.mNode;
  v11 = v10->mPrev;
  v11->mNext = (UFG::qNode<AnimationGroupHandle,AnimationGroupList> *)&v1->mPrev;
  v1->mPrev = v11;
  v1->mNext = v10;
  v10->mPrev = (UFG::qNode<AnimationGroupHandle,AnimationGroupList> *)&v1->mPrev;
  v12 = v1->m_AnimationGroup.m_pPointer;
  ++v12->mRefCount;
  ++v12->mRefCountTotal;
  v13 = v1->m_AnimationGroup.m_pPointer;
  v14 = (UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *)&v13->mPrev;
  if ( v14->mPrev == v14 && (UFG::qNode<AnimationGroup,AnimationGroupUpdateList> **)v13->mNext == &v13->mPrev )
  {
    v15 = &AnimationDataBase::sAnimationDataBase->mQueuedUpdateGroups;
    v16 = AnimationDataBase::sAnimationDataBase->mQueuedUpdateGroups.mNode.mPrev;
    v16->mNext = v14;
    v14->mPrev = v16;
    v14->mNext = &v15->mNode;
    v15->mNode.mPrev = v14;
  }
  return 1;
}

// File Line: 2340
// RVA: 0x3B02C0
void __fastcall AnimationGroupHandle::Unbind(AnimationGroupHandle *this)
{
  AnimationGroupHandle *v1; // rbx
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *v2; // rdx
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *v3; // rax
  AnimationGroup *v4; // rcx
  bool v5; // zf
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v6; // rdx
  UFG::qList<AnimationGroup,AnimationGroupUpdateList,0,0> *v7; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v8; // rax
  UFG::qSafePointer<AnimationGroup,AnimationGroup> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *v11; // rax

  v1 = this;
  if ( this->m_AnimationGroup.m_pPointer )
  {
    v2 = this->mPrev;
    v3 = this->mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    this->mPrev = (UFG::qNode<AnimationGroupHandle,AnimationGroupList> *)&this->mPrev;
    this->mNext = (UFG::qNode<AnimationGroupHandle,AnimationGroupList> *)&this->mPrev;
    v4 = this->m_AnimationGroup.m_pPointer;
    v5 = v4->mRefCount-- == 1;
    if ( v5 && !v4->mAnimRefCount )
      AnimationGroup::DestroyStreamHandle(v4);
    v6 = (UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *)&v1->m_AnimationGroup.m_pPointer->mPrev;
    if ( v6->mPrev == v6
      && v1->m_AnimationGroup.m_pPointer->mNext == (UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *)&v1->m_AnimationGroup.m_pPointer->mPrev )
    {
      v7 = &AnimationDataBase::sAnimationDataBase->mQueuedUpdateGroups;
      v8 = AnimationDataBase::sAnimationDataBase->mQueuedUpdateGroups.mNode.mPrev;
      v8->mNext = v6;
      v6->mPrev = v8;
      v6->mNext = &v7->mNode;
      v7->mNode.mPrev = v6;
    }
    v9 = &v1->m_AnimationGroup;
    if ( v1->m_AnimationGroup.m_pPointer )
    {
      v10 = v9->mPrev;
      v11 = v1->m_AnimationGroup.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v1->m_AnimationGroup.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *)&v1->m_AnimationGroup.mPrev;
    }
    v1->m_AnimationGroup.m_pPointer = 0i64;
    v1->m_bHasBeenBound = 0;
  }
  else
  {
    this->m_bHasBeenBound = 0;
  }
}

// File Line: 2369
// RVA: 0x3AEEA0
void __fastcall AnimationGroupHandle::SetAnimationPriority(AnimationGroupHandle *this, UFG::eAnimationPriorityEnum eAnimationPriority, unsigned __int16 subPriority)
{
  AnimationGroup *v3; // rdx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v4; // rdx
  UFG::qList<AnimationGroup,AnimationGroupUpdateList,0,0> *v5; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v6; // rax

  if ( this->m_eAnimationPriority.mValue != eAnimationPriority || this->m_AnimationSubPriority != subPriority )
  {
    this->m_eAnimationPriority.mValue = eAnimationPriority;
    v3 = this->m_AnimationGroup.m_pPointer;
    this->m_AnimationSubPriority = subPriority;
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

// File Line: 2431
// RVA: 0x14BD0A0
__int64 dynamic_initializer_for__gStaticSymbol_Default__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("default", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&gStaticSymbol_Default, v0);
  return atexit(dynamic_atexit_destructor_for__gStaticSymbol_Default__);
}

// File Line: 2433
// RVA: 0x14BCDC0
__int64 dynamic_initializer_for__gAnimCompressionProfileTracksEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &gAnimCompressionProfileTracksEnum,
    "Global\\Act\\AnimCompressionProfileEnum.xml");
  return atexit(dynamic_atexit_destructor_for__gAnimCompressionProfileTracksEnum__);
}

// File Line: 2434
// RVA: 0x14BCD30
__int64 dynamic_initializer_for__gAnimCompressionProfileDefault__()
{
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v0; // rax

  gAnimCompressionProfileDefault.m_EnumSymbol.mUID = gStaticSymbol_Default.mUID;
  *(_QWORD *)&gAnimCompressionProfileDefault.m_EnumValue = 0i64;
  gAnimCompressionProfileDefault.m_uEnumUID = 0;
  if ( gAnimCompressionProfileTracksEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gAnimCompressionProfileTracksEnum, &gAnimCompressionProfileDefault);
  }
  else
  {
    v0 = gAnimCompressionProfileTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gAnimCompressionProfileTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gAnimCompressionProfileDefault;
    gAnimCompressionProfileDefault.mPrev = v0;
    gAnimCompressionProfileDefault.mNext = &gAnimCompressionProfileTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gAnimCompressionProfileTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gAnimCompressionProfileDefault;
  }
  return atexit(dynamic_atexit_destructor_for__gAnimCompressionProfileDefault__);
}

// File Line: 2437
// RVA: 0x14BCEE0
__int64 dynamic_initializer_for__gAnimationBlendTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gAnimationBlendTypeEnum, gAnimationBlendTypeValues, 3, 0i64);
  return atexit(dynamic_atexit_destructor_for__gAnimationBlendTypeEnum__);
}

// File Line: 2438
// RVA: 0x14BCE50
__int64 dynamic_initializer_for__gAnimationBlendTypeDefault__()
{
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v0; // rax

  gAnimationBlendTypeDefault.m_EnumSymbol.mUID = gStaticSymbol_Default.mUID;
  *(_QWORD *)&gAnimationBlendTypeDefault.m_EnumValue = 0i64;
  gAnimationBlendTypeDefault.m_uEnumUID = 0;
  if ( gAnimationBlendTypeEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gAnimationBlendTypeEnum, &gAnimationBlendTypeDefault);
  }
  else
  {
    v0 = gAnimationBlendTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gAnimationBlendTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gAnimationBlendTypeDefault;
    gAnimationBlendTypeDefault.mPrev = v0;
    gAnimationBlendTypeDefault.mNext = &gAnimationBlendTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gAnimationBlendTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&gAnimationBlendTypeDefault;
  }
  return atexit(dynamic_atexit_destructor_for__gAnimationBlendTypeDefault__);
}

// File Line: 2440
// RVA: 0x14B9650
__int64 dynamic_initializer_for__AnimationGroup::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AnimationGroup", 0xFFFFFFFF);
  AnimationGroup::sClassNameUID = result;
  return result;
}

// File Line: 2483
// RVA: 0x39D0D0
void __fastcall AnimationGroup::AnimationGroup(AnimationGroup *this)
{
  AnimationGroup *v1; // rdi
  UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *v2; // rax
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v3; // rax
  UFG::qList<AnimationGroupHandle,AnimationGroupList,0,0> *v4; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  UFG::qSafePointerNode<AnimationGroup>::qSafePointerNode<AnimationGroup>((UFG::qSafePointerNode<AnimationGroup> *)&this->vfptr);
  v1->mNode.mParent = 0i64;
  v1->mNode.mChild[0] = 0i64;
  v1->mNode.mChild[1] = 0i64;
  v2 = (UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *)&v1->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v3 = (UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *)&v1->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v1->vfptr = (Expression::IMemberMapVtbl *)&AnimationGroup::`vftable{for `Expression::IMemberMap};
  v1->vfptr = (UFG::qSafePointerNode<AnimationGroup>Vtbl *)&AnimationGroup::`vftable{for `UFG::qSafePointerNode<AnimationGroup>};
  v1->mName.mOffset = 1i64;
  BinString::Set(&v1->mName, &customWorldMapCaption);
  v1->mAnimations.mCount = 0;
  v1->mAnimations.mData.mOffset = 0i64;
  v1->mCategory.mOffset = 1i64;
  BinString::Set(&v1->mCategory, "default");
  v1->mMode.mOffset = 1i64;
  BinString::Set(&v1->mMode, "default");
  v4 = &v1->mAnimGroupHandles;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v1->mMemorySize = 0;
  *(_QWORD *)&v1->mNameSymbol.mUID = -1i64;
  *(_QWORD *)&v1->mRefCount = 0i64;
  *(_QWORD *)&v1->mRefCountTotal = 0i64;
  *(_DWORD *)&v1->mCurrentAnimationSubPriority = 16842752;
  *(_DWORD *)&v1->mHighestBudgetedPriority.mValue = 1;
  v1->mSourceABKFromSingleHKX = 0;
  v1->mStreamHandle = 0i64;
}

// File Line: 2509
// RVA: 0x39CFE0
void __fastcall AnimationGroup::AnimationGroup(AnimationGroup *this, MemImageLoadFlag flag)
{
  AnimationGroup *v2; // rdi
  UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *v3; // rax
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v4; // rax
  signed __int64 v5; // rsi
  unsigned int v6; // ebx
  signed __int64 v7; // rdx
  UFG::qBaseNodeRB *v8; // rdx
  UFG::qList<AnimationGroupHandle,AnimationGroupList,0,0> *v9; // [rsp+60h] [rbp+18h]

  v2 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  UFG::qSafePointerNode<AnimationGroup>::qSafePointerNode<AnimationGroup>((UFG::qSafePointerNode<AnimationGroup> *)&this->vfptr);
  v2->mNode.mParent = 0i64;
  v2->mNode.mChild[0] = 0i64;
  v2->mNode.mChild[1] = 0i64;
  v3 = (UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v4 = (UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *)&v2->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v2->vfptr = (Expression::IMemberMapVtbl *)&AnimationGroup::`vftable{for `Expression::IMemberMap};
  v2->vfptr = (UFG::qSafePointerNode<AnimationGroup>Vtbl *)&AnimationGroup::`vftable{for `UFG::qSafePointerNode<AnimationGroup>};
  v9 = &v2->mAnimGroupHandles;
  v9->mNode.mPrev = &v9->mNode;
  v9->mNode.mNext = &v9->mNode;
  v2->mMemorySize = 0;
  v5 = (signed __int64)&v2->mAnimations.mData + v2->mAnimations.mData.mOffset;
  v6 = 0;
  if ( v2->mAnimations.mCount & 0x7FFFFFFF )
  {
    do
    {
      v7 = v5 + 8i64 * v6 + *(_QWORD *)(v5 + 8i64 * v6);
      if ( v7 )
        v8 = (UFG::qBaseNodeRB *)(v7 + 40);
      else
        v8 = 0i64;
      UFG::qBaseTreeRB::Add(&AnimationDataBase::sAnimationDataBase->mAnimations.mTree, v8);
      ++v6;
    }
    while ( v6 < (v2->mAnimations.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 2519
// RVA: 0x39EDF0
void __fastcall AnimationGroup::~AnimationGroup(AnimationGroup *this)
{
  AnimationGroup *v1; // rdi
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // rbx
  int v3; // er8
  int v4; // edx
  __int64 v5; // rcx
  signed __int64 v6; // r9
  _QWORD *v7; // r10
  _QWORD *v8; // r10
  signed __int64 v9; // r11
  UFG::qList<AnimationGroupHandle,AnimationGroupList,0,0> *v17; // r8
  UFG::qList<AnimationGroupHandle,AnimationGroupList,0,0> *v18; // rdx
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *v19; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *v20; // rax
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *v21; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *v22; // rax
  char *v23; // rcx
  char *v24; // rcx
  __int64 v25; // rax
  char *v26; // rcx
  char *v27; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v28; // rdx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v29; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v30; // rax
  UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *v31; // rdx
  UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *v32; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *v33; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v34; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *v36; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationGroup::`vftable{for `Expression::IMemberMap};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->vfptr;
  this->vfptr = (UFG::qSafePointerNode<AnimationGroup>Vtbl *)&AnimationGroup::`vftable{for `UFG::qSafePointerNode<AnimationGroup>};
  AnimationGroup::Destroy(this);
  while ( v1->mAnimations.mCount & 0x7FFFFFFF )
  {
    v3 = v1->mAnimations.mCount & 0x7FFFFFFF;
    if ( v3 && (v4 = v3 - 1, v3 - 1 >= 0) && v4 < v3 )
    {
      v5 = v1->mAnimations.mData.mOffset;
      if ( v5 )
        v6 = (signed __int64)&v1->mAnimations.mData + v5;
      else
        v6 = 0i64;
      v7 = (_QWORD *)(v6 + 8i64 * v4);
      if ( *v7 )
        v8 = (_QWORD *)((char *)v7 + *v7);
      else
        v8 = 0i64;
      if ( v5 )
        v9 = (signed __int64)&v1->mAnimations.mData + v5;
      else
        v9 = 0i64;
      if ( v3 == 1 )
      {
        v1->mAnimations.mCount &= 0x80000000;
        v1->mAnimations.mData.mOffset = 0i64;
      }
      else
      {
        v1->mAnimations.mCount ^= (((v1->mAnimations.mCount & 0x7FFFFFFF) - 1) ^ v1->mAnimations.mCount) & 0x7FFFFFFF;
        *(_QWORD *)(v9 + 8i64 * (unsigned int)(v3 - 1)) = 0i64;
      }
    }
    else
    {
      v8 = 0i64;
    }
    v8[15] = 0i64;
    (*(void (__fastcall **)(_QWORD *, signed __int64))(*v8 + 8i64))(v8, 1i64);
  }
  v17 = &v1->mAnimGroupHandles;
  v18 = (UFG::qList<AnimationGroupHandle,AnimationGroupList,0,0> *)v1->mAnimGroupHandles.mNode.mNext;
  if ( v18 != &v1->mAnimGroupHandles )
  {
    do
    {
      v19 = v18->mNode.mPrev;
      v20 = v18->mNode.mNext;
      v19->mNext = v20;
      v20->mPrev = v19;
      v18->mNode.mPrev = &v18->mNode;
      v18->mNode.mNext = &v18->mNode;
      v18 = (UFG::qList<AnimationGroupHandle,AnimationGroupList,0,0> *)v1->mAnimGroupHandles.mNode.mNext;
    }
    while ( v18 != v17 );
  }
  v21 = v17->mNode.mPrev;
  v22 = v1->mAnimGroupHandles.mNode.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  v17->mNode.mPrev = &v17->mNode;
  v1->mAnimGroupHandles.mNode.mNext = &v1->mAnimGroupHandles.mNode;
  if ( !(~LOBYTE(v1->mMode.mOffset) & 1) )
  {
    if ( v1->mMode.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v23 = (char *)&v1->mMode + (v1->mMode.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v23 != BinString::sEmptyString )
        operator delete[](v23);
    }
  }
  if ( !(~LOBYTE(v1->mCategory.mOffset) & 1) )
  {
    if ( v1->mCategory.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v24 = (char *)&v1->mCategory + (v1->mCategory.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v24 != BinString::sEmptyString )
        operator delete[](v24);
    }
  }
  if ( v1->mAnimations.mCount >= 0 )
  {
    v25 = v1->mAnimations.mData.mOffset;
    if ( v25 )
    {
      v26 = (char *)&v1->mAnimations.mData + v25;
      if ( v26 )
        operator delete[](v26);
    }
    v1->mAnimations.mData.mOffset = 0i64;
    v1->mAnimations.mCount &= 0x80000000;
  }
  if ( !(~LOBYTE(v1->mName.mOffset) & 1) )
  {
    if ( v1->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v27 = (char *)&v1->mName + (v1->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v27 != BinString::sEmptyString )
        operator delete[](v27);
    }
  }
  v28 = (UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *)&v1->mPrev;
  v29 = v1->mPrev;
  v30 = v1->mNext;
  v29->mNext = v30;
  v30->mPrev = v29;
  v28->mPrev = v28;
  v28->mNext = v28;
  v31 = (UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *)&v1->mPrev;
  v32 = v1->mPrev;
  v33 = v1->mNext;
  v32->mNext = v33;
  v33->mPrev = v32;
  v31->mPrev = v31;
  v31->mNext = v31;
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<AnimationGroup>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  v36 = &v2->m_SafePointerList;
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v2->m_SafePointerList);
  v34 = v2->m_SafePointerList.mNode.mPrev;
  v35 = v2->m_SafePointerList.mNode.mNext;
  v34->mNext = v35;
  v35->mPrev = v34;
  v36->mNode.mPrev = &v36->mNode;
  v36->mNode.mNext = &v36->mNode;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 2533
// RVA: 0x3A6840
void __fastcall AnimationGroup::Destroy(AnimationGroup *this)
{
  AnimationGroup *v1; // r13
  char *v2; // rdi
  unsigned int v3; // ebx
  signed __int64 v4; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v5; // rdx
  AnimationDataBase *v6; // rbx
  UFG::allocator::free_link *v7; // r14
  unsigned int v8; // esi
  unsigned int v9; // ecx
  AnimationGroup *i; // r15
  __int64 v11; // r12
  unsigned int v12; // edi
  unsigned int v13; // ebx
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::allocator::free_link *v16; // rbp
  UFG::allocator::free_link *v17; // rdx
  __int64 v18; // r8
  signed __int64 j; // rbx
  UFG::StreamPriorityHandle *v20; // rdx

  v1 = this;
  v2 = (char *)&this->mAnimations.mData + this->mAnimations.mData.mOffset;
  v3 = 0;
  if ( this->mAnimations.mCount & 0x7FFFFFFF )
  {
    do
    {
      v4 = (signed __int64)&v2[8 * v3 + *(_QWORD *)&v2[8 * v3]];
      if ( v4 )
        v5 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)(v4 + 40);
      else
        v5 = 0i64;
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&AnimationDataBase::sAnimationDataBase->mAnimations,
        v5);
      ++v3;
    }
    while ( v3 < (v1->mAnimations.mCount & 0x7FFFFFFFu) );
  }
  v6 = AnimationDataBase::sAnimationDataBase;
  AnimationGroup::UnloadInternal(v1);
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v6->mAnimGroups,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v1->mNode);
  v7 = 0i64;
  v8 = 0;
  v9 = 0;
  for ( i = (AnimationGroup *)v1->mAnimGroupHandles.mNode.mNext;
        i != (AnimationGroup *)&v1->mAnimGroupHandles;
        i = (AnimationGroup *)i->mResourceOwner )
  {
    v11 = v8;
    v12 = v8 + 1;
    if ( v8 + 1 > v9 )
    {
      v13 = 1;
      if ( v9 )
        v13 = 2 * v9;
      for ( ; v13 < v12; v13 *= 2 )
        ;
      if ( v13 <= 2 )
        v13 = 2;
      if ( v13 - v12 > 0x10000 )
        v13 = v8 + 65537;
      if ( v13 != v8 )
      {
        v14 = 8i64 * v13;
        if ( !is_mul_ok(v13, 8ui64) )
          v14 = -1i64;
        v15 = UFG::qMalloc(v14, "qArray.Add", 0i64);
        v16 = v15;
        if ( v7 )
        {
          if ( v8 )
          {
            v17 = v15;
            v18 = v8;
            do
            {
              v17->mNext = *(UFG::allocator::free_link **)((char *)v17 + (char *)v7 - (char *)v15);
              ++v17;
              --v18;
            }
            while ( v18 );
          }
          operator delete[](v7);
        }
        v7 = v16;
        v9 = v13;
      }
    }
    ++v8;
    v7[v11].mNext = (UFG::allocator::free_link *)i;
  }
  for ( j = 0i64; j < v8; ++j )
    AnimationGroupHandle::Unbind((AnimationGroupHandle *)v7[j].mNext);
  if ( v7 )
    operator delete[](v7);
  v20 = v1->mStreamHandle;
  if ( v20 )
  {
    UFG::StreamPrioritySystem::FreeHandle(AnimationGroup::sStreamPrioritySystem, v20);
    v1->mStreamHandle = 0i64;
  }
}

// File Line: 2596
// RVA: 0x3AB490
void __fastcall AnimationGroup::LoadInternal(AnimationGroup *this)
{
  AnimationGroup *v1; // rbp
  const char **v2; // r15
  signed __int64 v3; // r12
  char *v4; // rax
  signed __int64 v5; // r14
  __int64 v6; // rbx
  signed __int64 v7; // rdx
  unsigned int v8; // esi
  UFG::qResourceHandle *v9; // rdi
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax
  const char *v12; // rax
  unsigned int v13; // eax
  const char *v14; // rdx
  signed __int64 v15; // [rsp+20h] [rbp-88h]
  UFG::qString v16; // [rsp+28h] [rbp-80h]
  UFG::qString v17; // [rsp+50h] [rbp-58h]

  v15 = -2i64;
  v1 = this;
  v2 = gLoadPaths;
  v3 = 2i64;
  do
  {
    UFG::qString::qString(&v16, *v2);
    v4 = UFG::qSymbol::as_cstr_dbg(&v1->mNameSymbol);
    UFG::qString::operator+=(&v16, v4);
    UFG::qString::operator+=(&v16, "\\");
    v5 = (signed __int64)&v1->mAnimations.mData + v1->mAnimations.mData.mOffset;
    v6 = 0i64;
    if ( v1->mAnimations.mCount & 0x7FFFFFFF )
    {
      do
      {
        v7 = v5 + 8 * v6 + *(_QWORD *)(v5 + 8 * v6);
        v8 = *(_DWORD *)(v7 + 168);
        v9 = (UFG::qResourceHandle *)(v7 + 88);
        *(_QWORD *)(v7 + 120) = v7;
        v10 = `UFG::qGetResourceInventory<UFG::AnimationResource>::`2::result;
        if ( !`UFG::qGetResourceInventory<UFG::AnimationResource>::`2::result )
        {
          v11 = UFG::qResourceWarehouse::Instance();
          v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x53F1685Eu);
          `UFG::qGetResourceInventory<UFG::AnimationResource>::`2::result = v10;
        }
        UFG::qResourceHandle::Init(v9, 0x53F1685Eu, v8, v10);
        v6 = (unsigned int)(v6 + 1);
      }
      while ( (unsigned int)v6 < (v1->mAnimations.mCount & 0x7FFFFFFFu) );
    }
    v12 = AnimationGroup::GetName(v1);
    UFG::qString::qString(&v17, "%s%s.bin", *v2, v12, v15);
    v13 = UFG::StreamPrioritySystem::GetMemorySize(v17.mData);
    if ( v1->mMemorySize > v13 )
      v13 = v1->mMemorySize;
    v1->mMemorySize = v13;
    UFG::qString::~qString(&v17);
    UFG::qString::~qString(&v16);
    ++v2;
    --v3;
  }
  while ( v3 );
  if ( v1->mMemorySize <= 0 )
  {
    if ( v1->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
      v14 = (char *)&v1->mName + (v1->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    else
      v14 = BinString::sEmptyString;
    UFG::qPrintf(
      "WARNING: Zero Byte Animation Binary File Found: %s -- this will cause all sorts of streaming problems!\n",
      v14);
  }
  AnimationGroup::CreateStreamHandle(v1);
}

// File Line: 2629
// RVA: 0x3B04E0
void __fastcall AnimationGroup::UnloadInternal(AnimationGroup *this)
{
  AnimationGroup *v1; // rsi
  signed __int64 v2; // rbp
  __int64 v3; // rbx
  signed __int64 v4; // r14
  UFG::qResourceInventory *v5; // rax
  signed __int64 v6; // rdi
  UFG::qResourceWarehouse *v7; // rax
  UFG::StreamPriorityHandle *v8; // rbx
  const char *v9; // rbx
  UFG::HotSwapFileManager *v10; // rax
  fastdelegate::FastDelegate1<char const *,void> v11; // [rsp+20h] [rbp-18h]

  v1 = this;
  v2 = 2i64;
  do
  {
    v3 = 0i64;
    v4 = (signed __int64)&v1->mAnimations.mData + v1->mAnimations.mData.mOffset;
    if ( v1->mAnimations.mCount & 0x7FFFFFFF )
    {
      do
      {
        v5 = `UFG::qGetResourceInventory<UFG::AnimationResource>::`2::result;
        v6 = v4 + 8 * v3 + *(_QWORD *)(v4 + 8 * v3);
        if ( !`UFG::qGetResourceInventory<UFG::AnimationResource>::`2::result )
        {
          v7 = UFG::qResourceWarehouse::Instance();
          v5 = UFG::qResourceWarehouse::GetInventory(v7, 0x53F1685Eu);
          `UFG::qGetResourceInventory<UFG::AnimationResource>::`2::result = v5;
        }
        UFG::qResourceHandle::Close((UFG::qResourceHandle *)(v6 + 88), v5);
        v3 = (unsigned int)(v3 + 1);
      }
      while ( (unsigned int)v3 < (v1->mAnimations.mCount & 0x7FFFFFFFu) );
    }
    --v2;
  }
  while ( v2 );
  v8 = v1->mStreamHandle;
  if ( v8 )
  {
    v11 = UFG::DefaultHotSwapCallBack;
    v9 = v8->mFilename.mText;
    v10 = UFG::HotSwapFileManager::Get();
    UFG::HotSwapFileManager::UnRegisterFile(v10, v9, &v11);
    UFG::StreamPrioritySystem::FreeHandle(AnimationGroup::sStreamPrioritySystem, v1->mStreamHandle);
    v1->mStreamHandle = 0i64;
  }
}

// File Line: 2647
// RVA: 0x3A13F0
void __fastcall AnimationGroup::AddRefCount(AnimationGroup *this)
{
  ++this->mRefCount;
  ++this->mRefCountTotal;
}

// File Line: 2654
// RVA: 0x3AE050
_BOOL8 __fastcall AnimationGroup::RemoveRefCount(AnimationGroup *this)
{
  bool v1; // zf
  AnimationGroup *v2; // rbx

  v1 = this->mRefCount-- == 1;
  v2 = this;
  if ( v1 && !this->mAnimRefCount )
    AnimationGroup::DestroyStreamHandle(this);
  return v2->mRefCount == 0;
}

// File Line: 2696
// RVA: 0x3AE500
void __fastcall AnimationGroup::Serialize(AnimationGroup *this, IActionTreeSerializer *serializer)
{
  IActionTreeSerializer *v2; // r15
  AnimationGroup *v3; // rsi
  unsigned int v4; // ebx
  char *v5; // r14
  char *v6; // rcx
  char *v7; // rdi
  __int64 v8; // rax
  __int64 v9; // [rsp+28h] [rbp-40h]
  __int64 v10; // [rsp+30h] [rbp-38h]
  __int64 v11; // [rsp+40h] [rbp-28h]

  v2 = serializer;
  v3 = this;
  v4 = 0;
  v5 = (char *)&this->mAnimations.mData + this->mAnimations.mData.mOffset;
  if ( this->mAnimations.mCount & 0x7FFFFFFF )
  {
    do
    {
      v6 = &v5[8 * v4];
      v7 = &v6[*(_QWORD *)v6];
      if ( v7 )
      {
        v8 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v7 + 32i64))(&v6[*(_QWORD *)v6]);
        LODWORD(v11) = -1;
        LODWORD(v10) = 0;
        LODWORD(v9) = 1;
        v2->vfptr->_PushObjectToSerialize(
          v2,
          v7,
          1u,
          (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
          (const char *)v8,
          (QUEUE_PRIORITY)v9,
          v10,
          0i64,
          v11,
          0i64);
      }
      ++v4;
    }
    while ( v4 < (v3->mAnimations.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 2749
// RVA: 0x3A6540
void __fastcall AnimationGroup::CreateStreamHandle(AnimationGroup *this)
{
  AnimationGroup *v1; // rbx
  const char *v2; // r8
  void (__fastcall *v3)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // rax
  hkResourceHandle *v4; // rax
  const char *v5; // r8
  void (__fastcall *v6)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // rax
  hkResourceHandle *v7; // rax
  fastdelegate::FastDelegate1<char const *,void> v8; // [rsp+38h] [rbp-30h]
  fastdelegate::FastDelegate1<char const *,void> v9; // [rsp+48h] [rbp-20h]
  UFG::qSharedString filename; // [rsp+70h] [rbp+8h]
  UFG::qSharedString v11; // [rsp+78h] [rbp+10h]

  v1 = this;
  if ( this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    v2 = (char *)&this->mName + (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
  else
    v2 = BinString::sEmptyString;
  UFG::qSharedString::qSharedString(&filename, "Data\\Animation\\%s.bin", v2);
  if ( (unsigned int)UFG::StreamPrioritySystem::GetMemorySize(filename.mText) )
  {
    v1->mStreamHandle = UFG::StreamPrioritySystem::CreateHandle(AnimationGroup::sStreamPrioritySystem, &filename);
    v8 = UFG::DefaultHotSwapCallBack;
    v3 = fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
    if ( !ReloadHotSwapBinFile )
      v3 = 0i64;
    v9.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))v3;
    v9.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)ReloadHotSwapBinFile;
    v4 = (hkResourceHandle *)UFG::HotSwapFileManager::Get();
    TargetVisibleInAIDataCondition::CreateClone(v4);
  }
  else
  {
    if ( v1->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
      v5 = (char *)&v1->mName + (v1->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    else
      v5 = BinString::sEmptyString;
    UFG::qSharedString::qSharedString(&v11, "Data\\AnimationNIS\\%s.bin", v5);
    v1->mStreamHandle = UFG::StreamPrioritySystem::CreateHandle(AnimationGroup::sStreamPrioritySystem, &v11);
    v9 = UFG::DefaultHotSwapCallBack;
    v6 = fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
    if ( !ReloadHotSwapBinFile )
      v6 = 0i64;
    v8.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))v6;
    v8.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)ReloadHotSwapBinFile;
    v7 = (hkResourceHandle *)UFG::HotSwapFileManager::Get();
    TargetVisibleInAIDataCondition::CreateClone(v7);
    UFG::qSharedString::~qSharedString(&v11);
  }
  UFG::qSharedString::~qSharedString(&filename);
}

// File Line: 2767
// RVA: 0x3A6C80
void __fastcall AnimationGroup::DestroyStreamHandle(AnimationGroup *this)
{
  UFG::StreamPriorityHandle *v1; // rbx
  AnimationGroup *v2; // rdi
  const char *v3; // rbx
  UFG::HotSwapFileManager *v4; // rax
  fastdelegate::FastDelegate1<char const *,void> v5; // [rsp+20h] [rbp-18h]

  v1 = this->mStreamHandle;
  v2 = this;
  if ( v1 )
  {
    v5 = UFG::DefaultHotSwapCallBack;
    v3 = v1->mFilename.mText;
    v4 = UFG::HotSwapFileManager::Get();
    UFG::HotSwapFileManager::UnRegisterFile(v4, v3, &v5);
    UFG::StreamPrioritySystem::FreeHandle(AnimationGroup::sStreamPrioritySystem, v2->mStreamHandle);
    v2->mStreamHandle = 0i64;
  }
}

// File Line: 2808
// RVA: 0x3AB330
bool __fastcall AnimationGroup::IsStreamedIn(AnimationGroup *this)
{
  UFG::StreamPriorityHandle *v1; // rcx

  v1 = this->mStreamHandle;
  return v1 && (unsigned int)UFG::DataStreamer::GetStreamState(&v1->mHandle) == 6;
}

// File Line: 2864
// RVA: 0x3B49F0
void __fastcall AnimationGroup::UpdatePriorityFromHandles(AnimationGroup *this)
{
  __int64 v1; // r8
  signed int v2; // er10
  __int64 v3; // rbx
  UFG::qList<AnimationGroupHandle,AnimationGroupList,0,0> *v4; // r11
  AnimationGroup *v5; // rdi
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *v6; // rcx
  char *v7; // r9
  __int64 v8; // rdx
  UFG::StreamPriorityHandle *v9; // rdx
  UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *v10; // rdx
  UFG::qList<AnimationGroup,AnimationGroupBudgetedList,0,0> *v11; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *v12; // rax
  UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *v13; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *v14; // rax

  v1 = (unsigned int)this->mDefaultAnimationPriority.mValue;
  v2 = 0;
  v3 = 0i64;
  v4 = &this->mAnimGroupHandles;
  v5 = this;
  v6 = this->mAnimGroupHandles.mNode.mNext;
  if ( AnimationDataBase::sAnimationDataBase->mPriorityBudgets.p[v1].mMaxSize )
    v3 = (unsigned int)v1;
  if ( v6 != (UFG::qNode<AnimationGroupHandle,AnimationGroupList> *)v4 )
  {
    do
    {
      v7 = (char *)v6->mNext;
      if ( v6[3].mNext )
      {
        v8 = LOWORD(v6[4].mPrev);
        if ( (signed int)v8 > (signed int)v1 || (_DWORD)v8 == (_DWORD)v1 && WORD1(v6[4].mPrev) > v2 )
        {
          v2 = WORD1(v6[4].mPrev);
          LODWORD(v1) = v8;
        }
        if ( AnimationDataBase::sAnimationDataBase->mPriorityBudgets.p[v8].mMaxSize && (signed int)v8 > (signed int)v3 )
          v3 = (unsigned int)v8;
      }
      v6 = v6->mNext;
    }
    while ( v7 != (char *)v4 );
  }
  v9 = v5->mStreamHandle;
  v5->mCurrentAnimationPriority.mValue = v1;
  v5->mCurrentAnimationSubPriority = v2;
  if ( v9 )
    UFG::StreamPrioritySystem::ChangePriority(
      AnimationGroup::sStreamPrioritySystem,
      v9,
      (unsigned __int16)v2 | ((unsigned __int16)(char)v1 << 16));
  v5->mHighestBudgetedPriority.mValue = v3;
  v10 = (UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *)&v5->mPrev;
  if ( AnimationDataBase::sAnimationDataBase->mPriorityBudgets.p[v3].mMaxSize )
  {
    if ( v10->mPrev == v10 && (UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> **)v5->mNext == &v5->mPrev )
    {
      v11 = &AnimationDataBase::sAnimationDataBase->mBudgetedAnimationGroups;
      v12 = AnimationDataBase::sAnimationDataBase->mBudgetedAnimationGroups.mNode.mPrev;
      v12->mNext = v10;
      v10->mPrev = v12;
      v5->mNext = &v11->mNode;
      v11->mNode.mPrev = v10;
    }
  }
  else
  {
    v13 = v10->mPrev;
    v14 = v5->mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v10->mPrev = v10;
    v5->mNext = (UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *)&v5->mPrev;
  }
}

// File Line: 3162
// RVA: 0x14BF3D0
const char *dynamic_initializer_for__sBlendTreeNodeFactoryList__()
{
  const char *result; // rax

  sBlendTreeNodeFactoryList[0].mClassName = PoseNodeParent::sClassName;
  sBlendTreeNodeFactoryList[1].mClassName = PoseNodeRoot::sClassName;
  sBlendTreeNodeFactoryList[2].mClassName = BlendNode::sClassName;
  sBlendTreeNodeFactoryList[3].mClassName = BlendDirectionNode::sClassName;
  sBlendTreeNodeFactoryList[4].mClassName = BlendAddNode::sClassName;
  sBlendTreeNodeFactoryList[5].mClassName = BlendSubNode::sClassName;
  sBlendTreeNodeFactoryList[6].mClassName = BlendPhaseNode::sClassName;
  sBlendTreeNodeFactoryList[7].mClassName = MotionPhase2::sClassName;
  result = AnimationNode::sClassName;
  sBlendTreeNodeFactoryList[8].mClassName = AnimationNode::sClassName;
  return result;
}

// File Line: 3168
// RVA: 0x14BCF60
__int64 dynamic_initializer_for__gBlendTreeNodeFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(
    &gBlendTreeNodeFactory,
    sBlendTreeNodeFactoryList,
    sBlendTreeNodeFactoryListNum);
  return atexit(dynamic_atexit_destructor_for__gBlendTreeNodeFactory__);
}

// File Line: 3240
// RVA: 0x3AB3F0
PoseNode *__fastcall BlendTreeDataBase::LoadBlendTrees(BlendTreeDataBase *this, const char *bankBlendTreeFileName)
{
  void (__fastcall *v2)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // rax
  hkResourceHandle *v3; // rax
  fastdelegate::FastDelegate1<char const *,void> v5; // [rsp+38h] [rbp-50h]
  void (__fastcall *v6)(const char *); // [rsp+48h] [rbp-40h]
  void (__fastcall *v7)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // [rsp+50h] [rbp-38h]
  UFG::qString v8; // [rsp+58h] [rbp-30h]

  v5 = UFG::DefaultHotSwapCallBack;
  v2 = fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  if ( !ReloadHotSwapBtrFile )
    v2 = 0i64;
  v7 = v2;
  v6 = ReloadHotSwapBtrFile;
  v3 = (hkResourceHandle *)UFG::HotSwapFileManager::Get();
  TargetVisibleInAIDataCondition::CreateClone(v3);
  UFG::qString::qString(&v8);
  UFG::qString::~qString(&v8);
  return 0i64;
}

// File Line: 3288
// RVA: 0x3AD6B0
PoseNode *__fastcall BlendTreeDataBase::ReLoadBlendTrees(BlendTreeDataBase *this, const char *bankNameFileName)
{
  const char *v2; // r14
  BlendTreeDataBase *v3; // rbp
  signed __int64 v4; // rbx
  char *v5; // rdi
  char *v6; // rax
  _QWORD *v7; // rdx
  __int64 v8; // rcx
  _QWORD *v9; // rax
  PoseNode *v10; // rbx
  UFG::qString result; // [rsp+28h] [rbp-60h]
  UFG::qString v13; // [rsp+50h] [rbp-38h]

  v2 = bankNameFileName;
  v3 = this;
  UFG::qString::qString(&v13, bankNameFileName);
  UFG::qString::GetFilenameWithoutExtension(&v13, &result);
  v4 = (signed __int64)&v3->mPoseNodes.mNode.mNext[-3].mNext;
  if ( (UFG::qNode<PoseNode,PoseNode> **)v4 != &v3[-1].mPoseNodes.mNode.mNext )
  {
    while ( 1 )
    {
      v5 = result.mData;
      v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(v4 + 68));
      if ( !(unsigned int)UFG::qStringCompareInsensitive(v5, v6, -1) )
        break;
      v4 = *(_QWORD *)(v4 + 48) - 40i64;
      if ( (UFG::qNode<PoseNode,PoseNode> **)v4 == &v3[-1].mPoseNodes.mNode.mNext )
        goto LABEL_7;
    }
    v7 = (_QWORD *)(v4 + 40);
    v8 = *(_QWORD *)(v4 + 40);
    v9 = *(_QWORD **)(v4 + 48);
    *(_QWORD *)(v8 + 8) = v9;
    *v9 = v8;
    *v7 = v7;
    v7[1] = v7;
    if ( v4 )
      (*(void (__fastcall **)(signed __int64, signed __int64))(*(_QWORD *)v4 + 8i64))(v4, 1i64);
  }
LABEL_7:
  v10 = BlendTreeDataBase::LoadBlendTrees(v3, v2);
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&v13);
  return v10;
}

// File Line: 3309
// RVA: 0x3AA9C0
void __fastcall PoseCache::Init(unsigned __int64 cache_size)
{
  __int64 v1; // rbx
  UFG::allocator::free_link *v2; // rax
  PoseCache *v3; // rax

  v1 = cache_size;
  v2 = UFG::qMalloc(0x24C8ui64, "PoseCache", 0i64);
  if ( v2 )
    PoseCache::PoseCache((PoseCache *)v2);
  else
    v3 = 0i64;
  PoseCache::sPoseCache = v3;
  if ( v1 )
  {
    UFG::qMemoryPool::Init(&v3->mCachedDataPool, "PoseCachePool", v1, 0, 0, 1u, 0i64, 1, 1);
    PoseCache::sPoseCache->mEnablePoseCache = 1;
  }
  else
  {
    v3->mEnablePoseCache = 0;
  }
  PoseCache::sPoseCache->mPoseCacheUsageBytes = 0;
  PoseCache::sPoseCache->mPoseCacheUsageEntries = 0;
}

// File Line: 3348
// RVA: 0x3A7840
PoseCacheNode *__fastcall PoseCache::Find(PoseCache *this, unsigned __int64 uid)
{
  PoseCacheNode *v2; // rcx
  PoseCacheNode *result; // rax
  bool i; // zf
  PoseCacheNode *j; // rcx

  if ( uid )
  {
    v2 = (PoseCacheNode *)&this->mCachedDataTree;
    result = v2;
    for ( i = v2 == (PoseCacheNode *)&v2->mPrev; !i; i = result == (PoseCacheNode *)&v2->mPrev )
    {
      if ( result != v2 && result->mNode.mUID == uid )
      {
        for ( j = (PoseCacheNode *)result->mNode.mChild[0]; j; j = (PoseCacheNode *)j->mNode.mChild[0] )
        {
          if ( j->mNode.mUID != uid )
            break;
          result = j;
        }
        return result;
      }
      if ( uid > result->mNode.mUID )
        result = (PoseCacheNode *)result->mNode.mChild[1];
      else
        result = (PoseCacheNode *)result->mNode.mChild[0];
    }
  }
  return 0i64;
}

// File Line: 3376
// RVA: 0x3AFCA0
UFG::allocator::free_link *__fastcall PoseCache::Store(PoseCache *this, unsigned __int64 uid, unsigned __int64 size)
{
  unsigned __int64 v3; // r15
  unsigned __int64 v4; // rdi
  PoseCache *v5; // rsi
  UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *v6; // rcx
  char *v7; // rax
  bool i; // zf
  char *j; // rcx
  UFG::qList<PoseCacheNode,PoseCacheNode,1,0> *v11; // r14
  UFG::qNode<PoseCacheNode,PoseCacheNode> *v12; // rdx
  UFG::qNode<PoseCacheNode,PoseCacheNode> *v13; // rcx
  UFG::qNode<PoseCacheNode,PoseCacheNode> *v14; // rax
  signed __int64 v15; // rbx
  _QWORD *v16; // r8
  __int64 v17; // rdx
  _QWORD *v18; // rax
  UFG::allocator::free_link *v19; // rbp
  UFG::allocator::free_link *v20; // rax
  UFG::allocator::free_link *v21; // rbx
  UFG::allocator::free_link *v22; // rax
  UFG::allocator::free_link *v23; // rdx
  UFG::qNode<PoseCacheNode,PoseCacheNode> *v24; // rcx

  v3 = size;
  v4 = uid;
  v5 = this;
  if ( uid )
  {
    v6 = &this->mCachedDataTree;
    v7 = (char *)v6;
    for ( i = v6 == (UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *)&v6->mTree.mNULL;
          !i;
          i = v7 == (char *)&v6->mTree.mNULL )
    {
      if ( v7 != (char *)v6 && *((_QWORD *)v7 + 3) == uid )
      {
        for ( j = (char *)*((_QWORD *)v7 + 1); j; j = (char *)*((_QWORD *)j + 1) )
        {
          if ( *((_QWORD *)j + 3) != uid )
            break;
          v7 = j;
        }
        if ( v7 )
          return 0i64;
        break;
      }
      if ( uid > *((_QWORD *)v7 + 3) )
        v7 = (char *)*((_QWORD *)v7 + 2);
      else
        v7 = (char *)*((_QWORD *)v7 + 1);
    }
  }
  v11 = &v5->mCachedDataList;
  while ( ($CA91B2824B6F331601351B2AC7FEF5D9 *)&v5->mCachedDataList.mNode.mNext[-2] != &v5->mCachedDataTree.mTree.mNULL.8 )
  {
    if ( UFG::qMemoryPool::GetLargestFree(&v5->mCachedDataPool, 0i64) >= v3 )
      break;
    v12 = v5->mCachedDataList.mNode.mNext;
    v13 = v12->mPrev;
    v14 = v12->mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = v12;
    v12->mNext = v12;
    v15 = (signed __int64)&v12[-2];
    UFG::qMemoryPool::Free(&v5->mCachedDataPool, v12[1].mPrev);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      &v5->mCachedDataTree.mTree,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)v15);
    v5->mPoseCacheUsageBytes -= *(_DWORD *)(v15 + 80);
    --v5->mPoseCacheUsageEntries;
    v16 = (_QWORD *)(v15 + 32);
    v17 = *(_QWORD *)(v15 + 32);
    v18 = *(_QWORD **)(v15 + 40);
    *(_QWORD *)(v17 + 8) = v18;
    *v18 = v17;
    *v16 = v16;
    v16[1] = v16;
    operator delete[]((void *)v15);
  }
  v19 = UFG::qMemoryPool::Allocate(&v5->mCachedDataPool, v3, "pose_cache_alloc", 0i64, 1u);
  v20 = UFG::qMalloc(0x60ui64, "PoseCacheNode", 0x800ui64);
  v21 = v20;
  if ( v20 )
  {
    v20->mNext = 0i64;
    v20[1].mNext = 0i64;
    v20[2].mNext = 0i64;
    v20[3].mNext = (UFG::allocator::free_link *)v4;
    v22 = v20 + 4;
    v22->mNext = v22;
    v22[1].mNext = v22;
    v21[6].mNext = v19;
    v21[10].mNext = (UFG::allocator::free_link *)v3;
    LODWORD(v21[11].mNext) = 0;
  }
  else
  {
    v21 = 0i64;
  }
  v23 = v21 + 4;
  v24 = v11->mNode.mPrev;
  v24->mNext = (UFG::qNode<PoseCacheNode,PoseCacheNode> *)&v21[4];
  v23->mNext = (UFG::allocator::free_link *)v24;
  v23[1].mNext = (UFG::allocator::free_link *)v11;
  v11->mNode.mPrev = (UFG::qNode<PoseCacheNode,PoseCacheNode> *)&v21[4];
  UFG::qBaseTreeVariableRB<unsigned __int64>::Add(
    &v5->mCachedDataTree.mTree,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)v21);
  v5->mPoseCacheUsageBytes += LODWORD(v21[10].mNext);
  ++v5->mPoseCacheUsageEntries;
  return v21;
}


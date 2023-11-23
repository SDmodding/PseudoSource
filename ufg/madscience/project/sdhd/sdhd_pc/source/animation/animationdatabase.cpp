// File Line: 187
// RVA: 0x3ADB60
void __fastcall ReloadHotSwapBinFile(const char *filename)
{
  UFG::qString *FilenameWithoutExtension; // rax
  UFG::qString v2; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString result; // [rsp+50h] [rbp-38h] BYREF

  UFG::qString::qString(&v2, filename);
  FilenameWithoutExtension = UFG::qString::GetFilenameWithoutExtension(&v2, &result);
  AnimationDataBase::ReLoadAnimBankData(AnimationDataBase::sAnimationDataBase, FilenameWithoutExtension->mData);
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&v2);
}

// File Line: 194
// RVA: 0x3ADBC0
void __fastcall ReloadHotSwapBtrFile(const char *filename)
{
  UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *v2; // rdi
  char *p_mNext; // rcx
  __int64 v4; // rbx
  UFG::qList<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent,1,0> *v5; // rcx
  UFG::qList<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent,1,0> *v6; // rbx
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *mNext; // rcx
  char *v8; // rcx
  __int64 v9; // rbx
  UFG::qString v10; // [rsp+28h] [rbp-30h] BYREF

  v2 = (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *)((char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList
                                                                       - 152);
  p_mNext = (char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext[-10].mNext;
  if ( &UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext[-10].mNext != (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> **)((char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList - 152) )
  {
    do
    {
      v4 = *((_QWORD *)p_mNext + 20) - 152i64;
      ActionController::Stop((ActionController *)(p_mNext + 192));
      p_mNext = (char *)v4;
    }
    while ( (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *)v4 != v2 );
  }
  v5 = (UFG::qList<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent,1,0> *)&UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mNext[-13].mNext;
  if ( &UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mNext[-13].mNext != (UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> **)((char *)&UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList - 200) )
  {
    do
    {
      v6 = (UFG::qList<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent,1,0> *)&v5[13].mNode.mPrev[-13].mNext;
      mNext = v5[9].mNode.mNext;
      if ( mNext && !LOBYTE(mNext[2].mNext) )
        ((void (__fastcall *)(UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *))mNext[31].mPrev[24].mNext)(&mNext[31]);
      v5 = v6;
    }
    while ( v6 != (UFG::qList<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent,1,0> *)((char *)&UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList - 200) );
  }
  UFG::qString::qString(&v10, filename);
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
  char *p_mNext; // rcx
  UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *v2; // rdi
  __int64 v3; // rbx
  UFG::qList<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent,1,0> *v4; // rcx
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *mPrev; // rbx
  UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *mNext; // rcx
  UFG::qList<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent,1,0> *v7; // rbx
  char *v8; // rcx
  __int64 v9; // rbx

  p_mNext = (char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext[-10].mNext;
  v2 = (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *)((char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList
                                                                       - 152);
  if ( &UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext[-10].mNext != (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> **)((char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList - 152) )
  {
    do
    {
      v3 = *((_QWORD *)p_mNext + 20) - 152i64;
      ActionController::Stop((ActionController *)(p_mNext + 192));
      p_mNext = (char *)v3;
    }
    while ( (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> *)v3 != v2 );
  }
  v4 = (UFG::qList<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent,1,0> *)&UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mNext[-13].mNext;
  if ( &UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList.mNode.mNext[-13].mNext != (UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> **)((char *)&UFG::CharacterAnimationComponent::s_CharacterAnimationComponentList - 200) )
  {
    do
    {
      mPrev = v4[13].mNode.mPrev;
      mNext = v4[9].mNode.mNext;
      v7 = (UFG::qList<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent,1,0> *)&mPrev[-13].mNext;
      if ( mNext && !LOBYTE(mNext[2].mNext) )
        ((void (__fastcall *)(UFG::qNode<UFG::CharacterAnimationComponent,UFG::CharacterAnimationComponent> *))mNext[31].mPrev[24].mNext)(&mNext[31]);
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
  char mValue; // al
  char v3; // r8

  mValue = b->mCurrentAnimationPriority.mValue;
  v3 = a->mCurrentAnimationPriority.mValue;
  if ( mValue < v3 )
    return 1;
  if ( mValue == v3 )
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
  hkResourceHandle *v1; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x30ui64, "BlendTreeDataBase", 0i64, 1u);
  if ( v0 )
  {
    *(_QWORD *)v0 = &Expression::IMemberMap::`vftable;
    *((_QWORD *)v0 + 1) = 0i64;
    *(_QWORD *)v0 = &BlendTreeDataBase::`vftable;
    *((_QWORD *)v0 + 3) = 0i64;
    *((_QWORD *)v0 + 2) = 0i64;
    *((_QWORD *)v0 + 4) = v0 + 32;
    *((_QWORD *)v0 + 5) = v0 + 32;
  }
  else
  {
    v0 = 0i64;
  }
  BlendTreeDataBase::sBlendTreeDataBase = (BlendTreeDataBase *)v0;
  v1 = (hkResourceHandle *)UFG::HotSwapFileManager::Get();
  TargetVisibleInAIDataCondition::CreateClone(v1);
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
  UFG::qList<PoseNode,PoseNode,1,0> *p_mPoseNodes; // rbx
  UFG::qNode<PoseNode,PoseNode> *mPrev; // rcx
  UFG::qNode<PoseNode,PoseNode> *mNext; // rax
  BlendTreeDataBase::PoseNodeLookupEntry *p; // rcx
  PoseNode **p_mpPoseNode; // rbx

  this->vfptr = (Expression::IMemberMapVtbl *)&BlendTreeDataBase::`vftable;
  p_mPoseNodes = &this->mPoseNodes;
  UFG::qList<PoseNode,PoseNode,1,0>::DeleteNodes(&this->mPoseNodes);
  mPrev = p_mPoseNodes->mNode.mPrev;
  mNext = p_mPoseNodes->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mPoseNodes->mNode.mPrev = &p_mPoseNodes->mNode;
  p_mPoseNodes->mNode.mNext = &p_mPoseNodes->mNode;
  p = this->mPoseNodeLookup.p;
  if ( p )
  {
    p_mpPoseNode = &p[-1].mpPoseNode;
    `eh vector destructor iterator(p, 0x10ui64, (int)p[-1].mpPoseNode, (void (__fastcall *)(void *))_);
    operator delete[](p_mpPoseNode);
  }
  this->mPoseNodeLookup.p = 0i64;
  *(_QWORD *)&this->mPoseNodeLookup.size = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gBankNameFilter__);
}

// File Line: 387
// RVA: 0x14BD020
__int64 dynamic_initializer_for__gReferencedByFilter__()
{
  UFG::qString::qString(&gReferencedByFilter);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gReferencedByFilter__);
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
  UFG::StreamPrioritySystem *v2; // rbx
  int v3; // ecx
  UFG::eAnimationPriorityEnum *p_mOverFlowPriority; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::StreamPrioritySystem *v6; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  v2 = 0i64;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationDataBase::`vftable;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mAnimGroups.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mAnimations.mTree);
  `eh vector constructor iterator(
    this->mDefaultReferenceContainers,
    0x18ui64,
    17,
    (void (__fastcall *)(void *))AnimationGroupHandleContainer::AnimationGroupHandleContainer);
  this->mBudgetedAnimationGroups.mNode.mPrev = &this->mBudgetedAnimationGroups.mNode;
  this->mBudgetedAnimationGroups.mNode.mNext = &this->mBudgetedAnimationGroups.mNode;
  this->mQueuedUpdateGroups.mNode.mPrev = &this->mQueuedUpdateGroups.mNode;
  this->mQueuedUpdateGroups.mNode.mNext = &this->mQueuedUpdateGroups.mNode;
  v3 = 16;
  p_mOverFlowPriority = &this->mPriorityBudgets.p[0].mOverFlowPriority;
  do
  {
    *((_QWORD *)p_mOverFlowPriority - 1) = 0i64;
    *p_mOverFlowPriority = eANIM_PRIORITY_INACTIVE_NIS;
    p_mOverFlowPriority += 3;
    --v3;
  }
  while ( v3 >= 0 );
  this->mPriorityBudgets.size = 0;
  UFG::qString::qString(&this->mGlobalFallbackAnimation);
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
  this->m_pStreamPrioritySystem = v2;
  AnimationGroup::sStreamPrioritySystem = v2;
  NISManager::sStreamPrioritySystem = this->m_pStreamPrioritySystem;
  UFG::qString::Set(&this->mGlobalFallbackAnimation, "LOC_Stand_Idle");
  this->mPriorityBudgets.size = 17;
  this->mPriorityBudgets.p[9].mMaxSize = 0x100000;
  this->mPriorityBudgets.p[9].mOverFlowPriority = eANIM_PRIORITY_ACTIVE_POI;
  this->mPriorityBudgets.p[5].mMaxSize = 0x800000;
  this->mPriorityBudgets.p[5].mOverFlowPriority = eANIM_PRIORITY_PREDICTIVE_POI;
  this->mPriorityBudgets.p[4].mMaxSize = 0x400000;
  this->mPriorityBudgets.p[4].mOverFlowPriority = eANIM_PRIORITY_INSTANCED_POI;
  this->mPriorityBudgets.p[3].mMaxSize = 0x800000;
  this->mPriorityBudgets.p[3].mOverFlowPriority = eANIM_PRIORITY_INACTIVE_POI;
  this->mUseFallbackAnimations = 1;
}

// File Line: 575
// RVA: 0x39ECD0
void __fastcall AnimationDataBase::~AnimationDataBase(AnimationDataBase *this)
{
  Render::Skinning *p_mAnimGroups; // rdi
  Render::SkinningCacheNode *Head; // rax
  Render::SkinningCacheNode *v4; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNode; // rdx

  this->vfptr = (Expression::IMemberMapVtbl *)&AnimationDataBase::`vftable;
  p_mAnimGroups = (Render::Skinning *)&this->mAnimGroups;
  if ( this->mAnimGroups.mTree.mCount )
  {
    while ( 1 )
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&p_mAnimGroups->mSkinnedVertexBuffers);
      if ( !Head )
        break;
      v4 = Head - 1;
      if ( Head == (Render::SkinningCacheNode *)40 )
        goto LABEL_6;
      p_mNode = &Head->mNode;
LABEL_7:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&p_mAnimGroups->mSkinnedVertexBuffers.mTree, p_mNode);
      if ( v4 )
        ((void (__fastcall *)(Render::SkinningCacheNode *, __int64))v4->mNode.mParent->mChild[0])(v4, 1i64);
      if ( !p_mAnimGroups->mSkinnedVertexBuffers.mTree.mCount )
        goto LABEL_10;
    }
    v4 = 0i64;
LABEL_6:
    p_mNode = 0i64;
    goto LABEL_7;
  }
LABEL_10:
  AnimationGroup::sStreamPrioritySystem = 0i64;
  UFG::qString::~qString(&this->mGlobalFallbackAnimation);
  this->mPriorityBudgets.size = 0;
  UFG::qList<ActionNodeBank,ActionNodeBank,0,1>::~qList<ActionNodeBank,ActionNodeBank,0,1>((UFG::qList<ActionNodeBank,ActionNodeBank,0,1> *)&this->mQueuedUpdateGroups);
  UFG::qList<AnimationGroup,AnimationGroupBudgetedList,0,0>::~qList<AnimationGroup,AnimationGroupBudgetedList,0,0>(&this->mBudgetedAnimationGroups);
  `eh vector destructor iterator(
    this->mDefaultReferenceContainers,
    0x18ui64,
    17,
    (void (__fastcall *)(void *))AnimationGroupHandleContainer::~AnimationGroupHandleContainer);
  UFG::qTreeRB<AnimationGroup,AnimationGroup,1>::DeleteAll(&this->mAnimations);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->mAnimations);
  UFG::qTreeRB<AnimationGroup,AnimationGroup,1>::DeleteAll((UFG::qTreeRB<SkeletalAnimation,SkeletalAnimation,1> *)p_mAnimGroups);
  UFG::qBaseTreeRB::~qBaseTreeRB(p_mAnimGroups);
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 584
// RVA: 0x3A7B80
__int64 __fastcall AnimationDataBase::GetAvailablePriority(
        AnimationDataBase *this,
        __int64 requestPriority,
        const unsigned int size)
{
  __int64 v3; // rax
  unsigned int v4; // r11d
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
      v5 = &this->mPriorityBudgets.p[0].mMaxSize + 2 * requestPriority + requestPriority;
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
  AnimationGroupHandleContainer *v2; // rsi
  AnimationGroup *p_mNext; // rcx
  __int64 v4; // rbx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *i; // rax
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *mNext; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *mPrev; // rdx

  v2 = &this->mDefaultReferenceContainers[14];
  p_mNext = (AnimationGroup *)&this->mQueuedUpdateGroups.mNode.mNext[-6].mNext;
  if ( p_mNext != (AnimationGroup *)v2 )
  {
    do
    {
      v4 = (__int64)&p_mNext->UFG::qNode<AnimationGroup,AnimationGroupUpdateList>::mNext[-6].mNext;
      AnimationGroup::UpdatePriorityFromHandles(p_mNext);
      p_mNext = (AnimationGroup *)v4;
    }
    while ( (AnimationGroupHandleContainer *)v4 != v2 );
  }
  for ( i = this->mQueuedUpdateGroups.mNode.mNext;
        &i[-6].mNext != (UFG::qNode<AnimationGroup,AnimationGroupUpdateList> **)&this->mDefaultReferenceContainers[14];
        i = this->mQueuedUpdateGroups.mNode.mNext )
  {
    mNext = i->mNext;
    mPrev = i->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
  }
}

// File Line: 633
// RVA: 0x3B06B0
void __fastcall AnimationDataBase::Update(AnimationDataBase *this, const float fDeltaS)
{
  __int64 size; // rcx
  unsigned int *p_mUsedSize; // rax
  AnimationGroupHandleContainer *p_mNext; // rbx
  __int64 v6; // rdi
  AnimationDataBase *v7; // rbp
  unsigned int mPrev; // r14d
  _DWORD *v9; // rdx
  unsigned int v10; // r8d
  UFG::qPropertySet *mNext; // rdx
  __int64 mNext_low; // r8
  unsigned int v13; // ebx
  _DWORD *v14; // rdx
  unsigned int v15; // r9d

  AnimationDataBase::UpdateQueuedUpdateGroups(this);
  UFG::qList<AnimationGroup,AnimationGroupBudgetedList,0,0>::MergeSort(
    &this->mBudgetedAnimationGroups,
    (bool (__fastcall *)(AnimationGroup *, AnimationGroup *))SortDescendingPriority);
  size = this->mPriorityBudgets.size;
  if ( (_DWORD)size )
  {
    p_mUsedSize = &this->mPriorityBudgets.p[0].mUsedSize;
    do
    {
      *p_mUsedSize = 0;
      p_mUsedSize += 3;
      --size;
    }
    while ( size );
  }
  p_mNext = (AnimationGroupHandleContainer *)&this->mBudgetedAnimationGroups.mNode.mNext[-5].mNext;
  if ( p_mNext != &this->mDefaultReferenceContainers[14] )
  {
    do
    {
      v6 = (unsigned int)SBYTE6(p_mNext[8].m_AnimationGroupHandleList.mNode.mPrev);
      v7 = (AnimationDataBase *)&p_mNext[3].m_AnimationGroupHandleList.mNode.mNext[-5].mNext;
      if ( this->mPriorityBudgets.p[v6].mMaxSize )
      {
        mPrev = (unsigned int)p_mNext[7].m_AnimationGroupHandleList.mNode.mPrev;
        v9 = (_DWORD *)((char *)this + 12 * v6);
        v10 = v9[151];
        if ( v10 && mPrev + v9[152] > v10 )
          LODWORD(v6) = AnimationDataBase::GetAvailablePriority(this, (unsigned int)v9[153], mPrev);
        if ( (_DWORD)v6 != SBYTE6(p_mNext[8].m_AnimationGroupHandleList.mNode.mPrev) )
        {
          mNext = (UFG::qPropertySet *)p_mNext[4].m_AnimationGroupHandleList.mNode.mNext;
          BYTE6(p_mNext[8].m_AnimationGroupHandleList.mNode.mPrev) = v6;
          WORD2(p_mNext[8].m_AnimationGroupHandleList.mNode.mPrev) = -1;
          if ( mNext )
            UFG::StreamPrioritySystem::ChangePriority(
              AnimationGroup::sStreamPrioritySystem,
              mNext,
              ((unsigned __int16)(char)v6 << 16) | 0xFFFF);
        }
        if ( this->mPriorityBudgets.p[(unsigned int)v6].mMaxSize )
          this->mPriorityBudgets.p[(unsigned int)v6].mUsedSize += mPrev;
      }
      else
      {
        mNext_low = (unsigned int)SLOBYTE(p_mNext[8].m_AnimationGroupHandleList.mNode.mNext);
        if ( this->mPriorityBudgets.p[mNext_low].mMaxSize )
        {
          v13 = (unsigned int)p_mNext[7].m_AnimationGroupHandleList.mNode.mPrev;
          v14 = (_DWORD *)((char *)this + 12 * mNext_low);
          v15 = v14[151];
          if ( v15 && v13 + v14[152] > v15 )
            LODWORD(mNext_low) = AnimationDataBase::GetAvailablePriority(this, (unsigned int)v14[153], v13);
          if ( this->mPriorityBudgets.p[(unsigned int)mNext_low].mMaxSize )
            this->mPriorityBudgets.p[(unsigned int)mNext_low].mUsedSize += v13;
        }
      }
      p_mNext = (AnimationGroupHandleContainer *)v7;
    }
    while ( v7 != (AnimationDataBase *)&this->mDefaultReferenceContainers[14] );
  }
  UFG::StreamPrioritySystem::Update(this->m_pStreamPrioritySystem);
}

// File Line: 771
// RVA: 0x3A7910
PoseNode *__fastcall BlendTreeDataBase::FindBlendTree(BlendTreeDataBase *this, UFG::qSymbolUC *animUID)
{
  unsigned int size; // ecx
  int v4; // r8d
  int v5; // ecx
  BlendTreeDataBase::PoseNodeLookupEntry *p; // r11
  unsigned int mUID; // r10d
  unsigned int v8; // eax
  unsigned int v9; // r9d

  size = this->mPoseNodeLookup.size;
  if ( !size )
    return 0i64;
  v4 = 0;
  v5 = size - 1;
  if ( v5 < 0 )
    return 0i64;
  p = this->mPoseNodeLookup.p;
  mUID = animUID->mUID;
  while ( 1 )
  {
    v8 = (v5 + v4) / 2;
    v9 = p[v8].mName.mUID;
    if ( mUID <= v9 )
      break;
    v4 = v8 + 1;
LABEL_8:
    if ( v4 > v5 )
      return 0i64;
  }
  if ( mUID < v9 )
  {
    v5 = v8 - 1;
    goto LABEL_8;
  }
  return p[(v5 + v4) / 2].mpPoseNode;
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gAnimationNodeFactory__);
}

// File Line: 829
// RVA: 0x3AB380
UFG::qBaseNodeRB *__fastcall AnimationDataBase::LoadAnimBank(AnimationDataBase *this, const char *animBankName)
{
  UFG::qBaseTreeRB *v4; // rax
  UFG::qBaseNodeRB *p_mNULL; // rdi
  UFG::qSymbolUC result; // [rsp+38h] [rbp+10h] BYREF

  if ( !animBankName )
    return 0i64;
  UFG::qSymbolUC::create_from_string(&result, animBankName);
  if ( !result.mUID )
    return 0i64;
  v4 = UFG::qBaseTreeRB::Get(&this->mAnimGroups.mTree, result.mUID);
  if ( !v4 )
    return 0i64;
  p_mNULL = &v4[-1].mNULL;
  if ( v4 == (UFG::qBaseTreeRB *)40 )
    return 0i64;
  UFG::qPrintf("WARNING: Animation Group Already Loaded: %s\n", animBankName);
  return p_mNULL;
}

// File Line: 921
// RVA: 0x3A0B40
void __fastcall AnimationDataBase::AddAnimBank(AnimationDataBase *this, AnimationGroup *animGroup)
{
  UFG::qNodeRB<AnimationGroup> *v4; // rdx

  AnimationGroup::LoadInternal(animGroup);
  if ( animGroup )
    v4 = &animGroup->UFG::qNodeRB<AnimationGroup>;
  else
    v4 = 0i64;
  UFG::qBaseTreeRB::Add(&this->mAnimGroups.mTree, &v4->mNode);
}

// File Line: 954
// RVA: 0x3AB2B0
char __fastcall AnimationDataBase::IsStreamedIn(AnimationDataBase *this, const char *animBankName)
{
  UFG::qBaseTreeRB *v4; // rax
  UFG::qBaseNodeRB *p_mNULL; // rax
  UFG::DataStreamer::Handle *v6; // rcx
  UFG::qSymbolUC result; // [rsp+38h] [rbp+10h] BYREF

  if ( animBankName
    && (UFG::qSymbolUC::create_from_string(&result, animBankName), result.mUID)
    && (v4 = UFG::qBaseTreeRB::Get(&this->mAnimGroups.mTree, result.mUID)) != 0i64
    && (p_mNULL = &v4[-1].mNULL) != 0i64 )
  {
    v6 = (UFG::DataStreamer::Handle *)p_mNULL[3].mChild[0];
    if ( v6 && (unsigned int)UFG::DataStreamer::GetStreamState(v6) == 6 )
      return 1;
  }
  else
  {
    UFG::qPrintf("WARNING: AnimationDataBase::IsStreamedIn: Animation Group Not Found (%s)!\n", animBankName);
  }
  return 0;
}

// File Line: 977
// RVA: 0x3B0440
void __fastcall AnimationDataBase::UnloadAnimBank(AnimationDataBase *this, const char *animBankName)
{
  UFG::qBaseTreeRB *v4; // rax
  UFG::qBaseNodeRB *p_mNULL; // rdi
  UFG::qSymbolUC result; // [rsp+38h] [rbp+10h] BYREF

  if ( animBankName
    && (UFG::qSymbolUC::create_from_string(&result, animBankName), result.mUID)
    && (v4 = UFG::qBaseTreeRB::Get(&this->mAnimGroups.mTree, result.mUID)) != 0i64
    && (p_mNULL = &v4[-1].mNULL, v4 != (UFG::qBaseTreeRB *)40) )
  {
    AnimationGroup::UnloadInternal((AnimationGroup *)&v4[-1].mNULL);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mAnimGroups,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)p_mNULL[1].mChild);
    ((void (__fastcall *)(UFG::qBaseNodeRB *, __int64))p_mNULL->mParent->mChild[0])(p_mNULL, 1i64);
  }
  else
  {
    UFG::qPrintf("WARNING: AnimationDataBase::UnloadAnimBank: Animation Group Not Found (%s)!\n", animBankName);
  }
}

// File Line: 992
// RVA: 0x3ADF70
void __fastcall AnimationDataBase::RemoveAnimBank(AnimationDataBase *this, AnimationGroup *animationGroup)
{
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rdx

  AnimationGroup::UnloadInternal(animationGroup);
  if ( animationGroup )
    v4 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)&animationGroup->UFG::qNodeRB<AnimationGroup>;
  else
    v4 = 0i64;
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mAnimGroups,
    v4);
}

// File Line: 1039
// RVA: 0x3AD5D0
void __fastcall AnimationDataBase::ReLoadAnimBankData(AnimationDataBase *this, const char *animBankName)
{
  UFG::qBaseTreeRB *v3; // rax
  UFG::qBaseNodeRB *p_mNULL; // rbx
  UFG::StreamPriorityHandle *v5; // rdx
  UFG::qPropertySet *v6; // rdx
  UFG *v7; // rcx
  UFG::qSymbolUC result; // [rsp+38h] [rbp+10h] BYREF

  if ( animBankName )
  {
    UFG::qSymbolUC::create_from_string(&result, animBankName);
    if ( result.mUID )
    {
      v3 = UFG::qBaseTreeRB::Get(&this->mAnimGroups.mTree, result.mUID);
      if ( v3 )
      {
        p_mNULL = &v3[-1].mNULL;
        if ( v3 != (UFG::qBaseTreeRB *)40 )
        {
          v5 = (UFG::StreamPriorityHandle *)p_mNULL[3].mChild[0];
          if ( v5 )
          {
            UFG::StreamPrioritySystem::EvictFromMemory(AnimationGroup::sStreamPrioritySystem, v5);
            v6 = (UFG::qPropertySet *)p_mNULL[3].mChild[0];
            if ( v6 )
              UFG::StreamPrioritySystem::ChangePriority(
                AnimationGroup::sStreamPrioritySystem,
                v6,
                WORD2(p_mNULL[6].mParent) | ((unsigned __int16)SBYTE6(p_mNULL[6].mParent) << 16));
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
  Render::SkinningCacheNode *Head; // rax
  Render::SkinningCacheNode *v3; // rbx
  UFG::qBaseNodeRB *v4; // rdx
  UFG::qBaseTreeRB *Next; // rax
  UFG::qBaseNodeRB *p_mNULL; // rdi
  unsigned int *p_mUID; // rsi
  __int64 v8; // rbp
  bool v9; // di
  AnimationGroupHandle *i; // rbx
  char v11; // al

  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mAnimGroups);
  if ( Head )
  {
    v3 = Head - 1;
    if ( Head != (Render::SkinningCacheNode *)40 )
    {
      do
      {
        if ( v3 )
          v4 = (UFG::qBaseNodeRB *)&v3[1];
        else
          v4 = 0i64;
        Next = UFG::qBaseTreeRB::GetNext(&this->mAnimGroups.mTree, v4);
        if ( Next )
          p_mNULL = &Next[-1].mNULL;
        else
          p_mNULL = 0i64;
        AnimationGroupHandleContainer::Add(
          (AnimationGroupHandleContainer *)((char *)this->mDefaultReferenceContainers
                                          + 16 * SHIBYTE(v3[4].mCachedBufferPtr)
                                          + 8 * SHIBYTE(v3[4].mCachedBufferPtr)),
          (UFG::qSymbolUC *)&v3[4].mNode.mChild0 + 1,
          (UFG::eAnimationPriorityEnum)SHIBYTE(v3[4].mCachedBufferPtr));
        v3 = (Render::SkinningCacheNode *)p_mNULL;
      }
      while ( p_mNULL );
    }
  }
  p_mUID = &this->mAnimations.mTree.mNULL.mUID;
  v8 = 17i64;
  do
  {
    v9 = 1;
    for ( i = (AnimationGroupHandle *)(*((_QWORD *)p_mUID + 3) - 16i64);
          i != (AnimationGroupHandle *)p_mUID;
          i = (AnimationGroupHandle *)&i->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext[-1] )
    {
      v11 = AnimationGroupHandle::Bind(i);
      v9 = v9 && v11;
    }
    *((_BYTE *)p_mUID + 32) = 1;
    p_mUID += 6;
    --v8;
  }
  while ( v8 );
  AnimationDataBase::Update(this, 0.0);
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
  unsigned int v2; // eax
  UFG::qBaseTreeRB *v3; // rax
  SkeletalAnimation *p_mNULL; // rsi
  UFG::qTreeRB<SkeletalAnimation,SkeletalAnimation,1> *p_mAnimations; // rbp
  Render::SkinningCacheNode *Head; // rax
  SkeletalAnimation *v7; // rbx
  UFG::qBaseNodeRB *p_mNode; // rdx
  UFG::qBaseTreeRB *Next; // rax
  SkeletalAnimation *v10; // rdi

  if ( this->mUseFallbackAnimations )
  {
    v2 = UFG::qStringHashUpper32(this->mGlobalFallbackAnimation.mData, -1);
    if ( v2 && (v3 = UFG::qBaseTreeRB::Get(&this->mAnimations.mTree, v2)) != 0i64 )
      p_mNULL = (SkeletalAnimation *)&v3[-1].mNULL;
    else
      p_mNULL = 0i64;
    p_mAnimations = &this->mAnimations;
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mAnimations);
    if ( Head )
    {
      v7 = (SkeletalAnimation *)&Head[-1];
      if ( Head != (Render::SkinningCacheNode *)40 )
      {
        do
        {
          if ( v7 )
            p_mNode = &v7->mNode;
          else
            p_mNode = 0i64;
          Next = UFG::qBaseTreeRB::GetNext(&p_mAnimations->mTree, p_mNode);
          if ( Next )
            v10 = (SkeletalAnimation *)&Next[-1].mNULL;
          else
            v10 = 0i64;
          SkeletalAnimation::ResolveFallbackAnimation(v7, p_mNULL);
          v7 = v10;
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
  UFG::qBaseTreeRB *v3; // rax
  UFG::qSymbolUC result; // [rsp+38h] [rbp+10h] BYREF

  if ( pAnimBankName
    && (UFG::qSymbolUC::create_from_string(&result, pAnimBankName), result.mUID)
    && (v3 = UFG::qBaseTreeRB::Get(&this->mAnimGroups.mTree, result.mUID)) != 0i64 )
  {
    return &v3[-1].mNULL;
  }
  else
  {
    return 0i64;
  }
}

// File Line: 1217
// RVA: 0x3A78A0
UFG::qBaseNodeRB *__fastcall AnimationDataBase::FindAnimBank(
        AnimationDataBase *this,
        UFG::qSymbolUC *theAnimationGroupSymbol)
{
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v3; // rax

  mUID = theAnimationGroupSymbol->mUID;
  if ( mUID && (v3 = UFG::qBaseTreeRB::Get(&this->mAnimGroups.mTree, mUID)) != 0i64 )
    return &v3[-1].mNULL;
  else
    return 0i64;
}

// File Line: 1239
// RVA: 0x3A13D0
void __fastcall BlendTreeDataBase::AddBlendTrees(BlendTreeDataBase *this, PoseNode *poseNode)
{
  UFG::qNode<PoseNode,PoseNode> *mPrev; // rax
  UFG::qNode<PoseNode,PoseNode> *v3; // rdx

  mPrev = this->mPoseNodes.mNode.mPrev;
  v3 = &poseNode->UFG::qNode<PoseNode,PoseNode>;
  mPrev->mNext = v3;
  v3->mPrev = mPrev;
  v3->mNext = &this->mPoseNodes.mNode;
  this->mPoseNodes.mNode.mPrev = v3;
  BlendTreeDataBase::RebuildPoseNodeLookup(this);
}

// File Line: 1246
// RVA: 0x3AE030
void __fastcall BlendTreeDataBase::RemoveBlendTrees(BlendTreeDataBase *this, PoseNode *poseNode)
{
  UFG::qNode<PoseNode,PoseNode> *mPrev; // rcx
  UFG::qNode<PoseNode,PoseNode> *mNext; // rax
  UFG::qNode<PoseNode,PoseNode> *v4; // rdx

  mPrev = poseNode->mPrev;
  mNext = poseNode->mNext;
  v4 = &poseNode->UFG::qNode<PoseNode,PoseNode>;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
}

// File Line: 1255
// RVA: 0x3AD990
void __fastcall BlendTreeDataBase::RebuildPoseNodeLookup(BlendTreeDataBase *this)
{
  UFG::qArray<BlendTreeDataBase::PoseNodeLookupEntry,0> *p_mPoseNodeLookup; // rdi
  BlendTreeDataBase::PoseNodeLookupEntry *p; // rcx
  PoseNode **p_mpPoseNode; // rbx
  BlendTreeDataBase *v5; // r14
  __int64 size; // rsi
  unsigned int capacity; // edx
  unsigned int v8; // ebp
  __int64 p_GetClassNameUID; // r15
  unsigned int v10; // ebx
  unsigned int v11; // edx
  __int64 v12; // rax
  int v13; // esi
  int v14; // r13d
  __int64 v15; // rax
  __int64 v16; // r15
  unsigned int v17; // edx
  int v18; // r12d
  unsigned int v19; // ebx
  __int64 v20; // rbp
  unsigned int v21; // edx
  __int64 v22; // rax
  __int64 v23; // [rsp+60h] [rbp+8h]
  UFG::qNode<PoseNode,PoseNode> **p_mNext; // [rsp+68h] [rbp+10h]

  p_mPoseNodeLookup = &this->mPoseNodeLookup;
  p = this->mPoseNodeLookup.p;
  if ( p )
  {
    p_mpPoseNode = &p[-1].mpPoseNode;
    `eh vector destructor iterator(p, 0x10ui64, (int)p[-1].mpPoseNode, (void (__fastcall *)(void *))_);
    operator delete[](p_mpPoseNode);
  }
  p_mPoseNodeLookup->p = 0i64;
  *(_QWORD *)&p_mPoseNodeLookup->size = 0i64;
  p_mNext = &this[-1].mPoseNodes.mNode.mNext;
  v5 = (BlendTreeDataBase *)&this->mPoseNodes.mNode.mNext[-3].mNext;
  if ( v5 != (BlendTreeDataBase *)&this[-1].mPoseNodes.mNode.mNext )
  {
    do
    {
      size = p_mPoseNodeLookup->size;
      capacity = p_mPoseNodeLookup->capacity;
      v8 = v5[1].mPoseNodeLookup.capacity;
      p_GetClassNameUID = (__int64)&v5[1].vfptr[-1].GetClassNameUID;
      v10 = size + 1;
      v23 = p_GetClassNameUID;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v11 = 2 * capacity;
        else
          v11 = 1;
        for ( ; v11 < v10; v11 *= 2 )
          ;
        if ( v11 - v10 > 0x10000 )
          v11 = size + 65537;
        UFG::qArray<BlendTreeDataBase::PoseNodeLookupEntry,0>::Reallocate(p_mPoseNodeLookup, v11, "qArray.Add");
      }
      p_mPoseNodeLookup->size = v10;
      v12 = (__int64)&p_mPoseNodeLookup->p[size];
      *(_DWORD *)v12 = v8;
      *(_QWORD *)(v12 + 8) = v5;
      v13 = 0;
      v14 = (int)v5->vfptr[1].CreateClone(v5);
      if ( v14 > 0 )
      {
        do
        {
          v15 = (__int64)v5->vfptr[1].__vecDelDtor(v5, v13);
          v16 = p_mPoseNodeLookup->size;
          v17 = p_mPoseNodeLookup->capacity;
          v18 = *(_DWORD *)(v15 + 68);
          v19 = v16 + 1;
          v20 = v15;
          if ( (int)v16 + 1 > v17 )
          {
            if ( v17 )
              v21 = 2 * v17;
            else
              v21 = 1;
            for ( ; v21 < v19; v21 *= 2 )
              ;
            if ( v21 - v19 > 0x10000 )
              v21 = v16 + 65537;
            UFG::qArray<BlendTreeDataBase::PoseNodeLookupEntry,0>::Reallocate(p_mPoseNodeLookup, v21, "qArray.Add");
          }
          p_mPoseNodeLookup->size = v19;
          ++v13;
          v22 = (__int64)&p_mPoseNodeLookup->p[v16];
          *(_DWORD *)v22 = v18;
          *(_QWORD *)(v22 + 8) = v20;
        }
        while ( v13 < v14 );
        p_GetClassNameUID = v23;
      }
      v5 = (BlendTreeDataBase *)p_GetClassNameUID;
    }
    while ( (UFG::qNode<PoseNode,PoseNode> **)p_GetClassNameUID != p_mNext );
  }
  UFG::qQuickSortImpl<BlendTreeDataBase::PoseNodeLookupEntry,bool (*)(BlendTreeDataBase::PoseNodeLookupEntry const &,BlendTreeDataBase::PoseNodeLookupEntry const &)>(
    p_mPoseNodeLookup->p,
    &p_mPoseNodeLookup->p[(int)p_mPoseNodeLookup->size - 1],
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
  int mCurrentPriority; // eax
  int v3; // r8d

  mCurrentPriority = B->mCurrentPriority;
  v3 = A->mCurrentPriority;
  return mCurrentPriority < v3 || mCurrentPriority == v3 && B->mCurrentSubPriority <= A->mCurrentSubPriority;
}

// File Line: 1365
// RVA: 0x39C550
bool __fastcall AnimGroupSortByName(AnimationGroupStats *A, AnimationGroupStats *B)
{
  return (int)UFG::qStringCompareInsensitive(B->mName, A->mName, -1) >= 0;
}

// File Line: 2244
// RVA: 0x39D200
void __fastcall AnimationGroupHandle::AnimationGroupHandle(AnimationGroupHandle *this)
{
  this->UFG::qNode<AnimationGroupHandle,AnimationGroupList>::mPrev = this;
  this->UFG::qNode<AnimationGroupHandle,AnimationGroupList>::mNext = this;
  this->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mPrev = &this->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>;
  this->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext = &this->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>;
  this->m_AnimationGroupSymbol.mUID = -1;
  this->m_AnimationGroup.mPrev = &this->m_AnimationGroup;
  this->m_AnimationGroup.mNext = &this->m_AnimationGroup;
  this->m_AnimationGroup.m_pPointer = 0i64;
  *(_DWORD *)&this->m_eAnimationPriority.mValue = -65524;
  this->m_bHasBeenBound = 0;
  this->m_pReferenceInfo = 0i64;
}

// File Line: 2255
// RVA: 0x39F0F0
void __fastcall AnimationGroupHandle::~AnimationGroupHandle(AnimationGroupHandle *this)
{
  AnimationGroupHandle::ReferenceInfo *m_pReferenceInfo; // rdi
  UFG::qSafePointer<AnimationGroup,AnimationGroup> *p_m_AnimationGroup; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v8; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v9; // rax
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *v10; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *v11; // rax

  AnimationGroupHandle::Unbind(this);
  UFG::qSymbolUC::set_null(&this->m_AnimationGroupSymbol);
  m_pReferenceInfo = this->m_pReferenceInfo;
  if ( m_pReferenceInfo )
  {
    UFG::qSharedString::~qSharedString(&m_pReferenceInfo->m_ReferenceText);
    operator delete[](m_pReferenceInfo);
  }
  p_m_AnimationGroup = &this->m_AnimationGroup;
  if ( this->m_AnimationGroup.m_pPointer )
  {
    mPrev = p_m_AnimationGroup->mPrev;
    mNext = this->m_AnimationGroup.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_AnimationGroup->mPrev = p_m_AnimationGroup;
    this->m_AnimationGroup.mNext = &this->m_AnimationGroup;
  }
  this->m_AnimationGroup.m_pPointer = 0i64;
  v6 = p_m_AnimationGroup->mPrev;
  v7 = this->m_AnimationGroup.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  p_m_AnimationGroup->mPrev = p_m_AnimationGroup;
  this->m_AnimationGroup.mNext = &this->m_AnimationGroup;
  v8 = this->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mPrev;
  v9 = this->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  this->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mPrev = &this->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>;
  this->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext = &this->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>;
  v10 = this->UFG::qNode<AnimationGroupHandle,AnimationGroupList>::mPrev;
  v11 = this->UFG::qNode<AnimationGroupHandle,AnimationGroupList>::mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->UFG::qNode<AnimationGroupHandle,AnimationGroupList>::mPrev = this;
  this->UFG::qNode<AnimationGroupHandle,AnimationGroupList>::mNext = this;
}

// File Line: 2268
// RVA: 0x3AA860
void __fastcall AnimationGroupHandle::Init(
        AnimationGroupHandle *this,
        UFG::qSymbolUC *theAnimationGroupSymbol,
        UFG::eAnimationPriorityEnum eAnimationPriority)
{
  unsigned int mUID; // eax
  unsigned __int16 v4; // bp

  mUID = this->m_AnimationGroupSymbol.mUID;
  v4 = eAnimationPriority;
  if ( mUID != theAnimationGroupSymbol->mUID )
  {
    if ( mUID != -1 )
    {
      AnimationGroupHandle::Unbind(this);
      UFG::qSymbolUC::set_null(&this->m_AnimationGroupSymbol);
    }
    this->m_AnimationGroupSymbol = (UFG::qSymbolUC)theAnimationGroupSymbol->mUID;
    this->m_eAnimationPriority.mValue = v4;
    this->m_AnimationSubPriority = -1;
  }
}

// File Line: 2284
// RVA: 0x3AE0F0
void __fastcall AnimationGroupHandle::Reset(AnimationGroupHandle *this)
{
  AnimationGroupHandle::Unbind(this);
  UFG::qSymbolUC::set_null(&this->m_AnimationGroupSymbol);
}

// File Line: 2296
// RVA: 0x3A2B60
char __fastcall AnimationGroupHandle::Bind(AnimationGroupHandle *this)
{
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v3; // rax
  AnimationGroup *p_mNULL; // r8
  UFG::qSafePointer<AnimationGroup,AnimationGroup> *p_m_AnimationGroup; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *v8; // rax
  AnimationGroup *m_pPointer; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *p_mNode; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *v11; // rax
  AnimationGroup *v12; // rax
  AnimationGroup *v13; // rax
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v14; // rdx
  UFG::qList<AnimationGroup,AnimationGroupUpdateList,0,0> *p_mQueuedUpdateGroups; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v16; // rax

  if ( this->m_AnimationGroup.m_pPointer )
    AnimationGroupHandle::Unbind(this);
  mUID = this->m_AnimationGroupSymbol.mUID;
  this->m_bHasBeenBound = 1;
  if ( mUID && (v3 = UFG::qBaseTreeRB::Get(&AnimationDataBase::sAnimationDataBase->mAnimGroups.mTree, mUID)) != 0i64 )
    p_mNULL = (AnimationGroup *)&v3[-1].mNULL;
  else
    p_mNULL = 0i64;
  p_m_AnimationGroup = &this->m_AnimationGroup;
  if ( this->m_AnimationGroup.m_pPointer )
  {
    mPrev = p_m_AnimationGroup->mPrev;
    mNext = this->m_AnimationGroup.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_AnimationGroup->mPrev = p_m_AnimationGroup;
    this->m_AnimationGroup.mNext = &this->m_AnimationGroup;
  }
  this->m_AnimationGroup.m_pPointer = p_mNULL;
  if ( p_mNULL )
  {
    v8 = p_mNULL->m_SafePointerList.UFG::qSafePointerNode<AnimationGroup>::mNode.UFG::qSafePointerNode<AnimationGroup>::mPrev;
    v8->mNext = p_m_AnimationGroup;
    p_m_AnimationGroup->mPrev = v8;
    this->m_AnimationGroup.mNext = &p_mNULL->m_SafePointerList.UFG::qSafePointerNode<AnimationGroup>::mNode;
    p_mNULL->m_SafePointerList.UFG::qSafePointerNode<AnimationGroup>::mNode.UFG::qSafePointerNode<AnimationGroup>::mPrev = p_m_AnimationGroup;
  }
  m_pPointer = this->m_AnimationGroup.m_pPointer;
  if ( !m_pPointer || !m_pPointer->mMemorySize )
    return 0;
  p_mNode = &m_pPointer->mAnimGroupHandles.mNode;
  v11 = p_mNode->mPrev;
  v11->mNext = this;
  this->UFG::qNode<AnimationGroupHandle,AnimationGroupList>::mPrev = v11;
  this->UFG::qNode<AnimationGroupHandle,AnimationGroupList>::mNext = p_mNode;
  p_mNode->mPrev = this;
  v12 = this->m_AnimationGroup.m_pPointer;
  ++v12->mRefCount;
  ++v12->mRefCountTotal;
  v13 = this->m_AnimationGroup.m_pPointer;
  v14 = &v13->UFG::qNode<AnimationGroup,AnimationGroupUpdateList>;
  if ( v14->mPrev == v14
    && v13->UFG::qNode<AnimationGroup,AnimationGroupUpdateList>::mNext == &v13->UFG::qNode<AnimationGroup,AnimationGroupUpdateList> )
  {
    p_mQueuedUpdateGroups = &AnimationDataBase::sAnimationDataBase->mQueuedUpdateGroups;
    v16 = AnimationDataBase::sAnimationDataBase->mQueuedUpdateGroups.mNode.mPrev;
    v16->mNext = v14;
    v14->mPrev = v16;
    v14->mNext = &p_mQueuedUpdateGroups->mNode;
    p_mQueuedUpdateGroups->mNode.mPrev = v14;
  }
  return 1;
}

// File Line: 2340
// RVA: 0x3B02C0
void __fastcall AnimationGroupHandle::Unbind(AnimationGroupHandle *this)
{
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *mPrev; // rdx
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *mNext; // rax
  AnimationGroup *m_pPointer; // rcx
  bool v5; // zf
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v6; // rdx
  UFG::qList<AnimationGroup,AnimationGroupUpdateList,0,0> *p_mQueuedUpdateGroups; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v8; // rax
  UFG::qSafePointer<AnimationGroup,AnimationGroup> *p_m_AnimationGroup; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationGroup>,UFG::qSafePointerNodeList> *v11; // rax

  if ( this->m_AnimationGroup.m_pPointer )
  {
    mPrev = this->UFG::qNode<AnimationGroupHandle,AnimationGroupList>::mPrev;
    mNext = this->UFG::qNode<AnimationGroupHandle,AnimationGroupList>::mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->UFG::qNode<AnimationGroupHandle,AnimationGroupList>::mPrev = this;
    this->UFG::qNode<AnimationGroupHandle,AnimationGroupList>::mNext = this;
    m_pPointer = this->m_AnimationGroup.m_pPointer;
    v5 = m_pPointer->mRefCount-- == 1;
    if ( v5 && !m_pPointer->mAnimRefCount )
      AnimationGroup::DestroyStreamHandle(m_pPointer);
    v6 = &this->m_AnimationGroup.m_pPointer->UFG::qNode<AnimationGroup,AnimationGroupUpdateList>;
    if ( v6->mPrev == v6
      && this->m_AnimationGroup.m_pPointer->mNext == &this->m_AnimationGroup.m_pPointer->UFG::qNode<AnimationGroup,AnimationGroupUpdateList> )
    {
      p_mQueuedUpdateGroups = &AnimationDataBase::sAnimationDataBase->mQueuedUpdateGroups;
      v8 = AnimationDataBase::sAnimationDataBase->mQueuedUpdateGroups.mNode.mPrev;
      v8->mNext = v6;
      v6->mPrev = v8;
      v6->mNext = &p_mQueuedUpdateGroups->mNode;
      p_mQueuedUpdateGroups->mNode.mPrev = v6;
    }
    p_m_AnimationGroup = &this->m_AnimationGroup;
    if ( this->m_AnimationGroup.m_pPointer )
    {
      v10 = p_m_AnimationGroup->mPrev;
      v11 = this->m_AnimationGroup.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      p_m_AnimationGroup->mPrev = p_m_AnimationGroup;
      this->m_AnimationGroup.mNext = &this->m_AnimationGroup;
    }
    this->m_AnimationGroup.m_pPointer = 0i64;
    this->m_bHasBeenBound = 0;
  }
  else
  {
    this->m_bHasBeenBound = 0;
  }
}

// File Line: 2369
// RVA: 0x3AEEA0
void __fastcall AnimationGroupHandle::SetAnimationPriority(
        AnimationGroupHandle *this,
        UFG::eAnimationPriorityEnum eAnimationPriority,
        unsigned __int16 subPriority)
{
  AnimationGroup *m_pPointer; // rdx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v4; // rdx
  UFG::qList<AnimationGroup,AnimationGroupUpdateList,0,0> *p_mQueuedUpdateGroups; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *mPrev; // rax

  if ( this->m_eAnimationPriority.mValue != eAnimationPriority || this->m_AnimationSubPriority != subPriority )
  {
    this->m_eAnimationPriority.mValue = eAnimationPriority;
    m_pPointer = this->m_AnimationGroup.m_pPointer;
    this->m_AnimationSubPriority = subPriority;
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

// File Line: 2431
// RVA: 0x14BD0A0
__int64 dynamic_initializer_for__gStaticSymbol_Default__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("default", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&gStaticSymbol_Default, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gStaticSymbol_Default__);
}

// File Line: 2433
// RVA: 0x14BCDC0
__int64 dynamic_initializer_for__gAnimCompressionProfileTracksEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &gAnimCompressionProfileTracksEnum,
    "Global\\Act\\AnimCompressionProfileEnum.xml");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gAnimCompressionProfileTracksEnum__);
}

// File Line: 2434
// RVA: 0x14BCD30
__int64 dynamic_initializer_for__gAnimCompressionProfileDefault__()
{
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax

  gAnimCompressionProfileDefault.m_EnumSymbol.mUID = gStaticSymbol_Default.mUID;
  *(_QWORD *)&gAnimCompressionProfileDefault.m_EnumValue = 0i64;
  gAnimCompressionProfileDefault.m_uEnumUID = 0;
  if ( gAnimCompressionProfileTracksEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gAnimCompressionProfileTracksEnum, &gAnimCompressionProfileDefault);
  }
  else
  {
    mPrev = gAnimCompressionProfileTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gAnimCompressionProfileTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &gAnimCompressionProfileDefault;
    gAnimCompressionProfileDefault.mPrev = mPrev;
    gAnimCompressionProfileDefault.mNext = &gAnimCompressionProfileTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gAnimCompressionProfileTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &gAnimCompressionProfileDefault;
  }
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gAnimCompressionProfileDefault__);
}

// File Line: 2437
// RVA: 0x14BCEE0
__int64 dynamic_initializer_for__gAnimationBlendTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gAnimationBlendTypeEnum, gAnimationBlendTypeValues, 3, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gAnimationBlendTypeEnum__);
}

// File Line: 2438
// RVA: 0x14BCE50
__int64 dynamic_initializer_for__gAnimationBlendTypeDefault__()
{
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax

  gAnimationBlendTypeDefault.m_EnumSymbol.mUID = gStaticSymbol_Default.mUID;
  *(_QWORD *)&gAnimationBlendTypeDefault.m_EnumValue = 0i64;
  gAnimationBlendTypeDefault.m_uEnumUID = 0;
  if ( gAnimationBlendTypeEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gAnimationBlendTypeEnum, &gAnimationBlendTypeDefault);
  }
  else
  {
    mPrev = gAnimationBlendTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gAnimationBlendTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &gAnimationBlendTypeDefault;
    gAnimationBlendTypeDefault.mPrev = mPrev;
    gAnimationBlendTypeDefault.mNext = &gAnimationBlendTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gAnimationBlendTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &gAnimationBlendTypeDefault;
  }
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gAnimationBlendTypeDefault__);
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
  this->Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  UFG::qSafePointerNode<AnimationGroup>::qSafePointerNode<AnimationGroup>(&this->UFG::qSafePointerNode<AnimationGroup>);
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>::mPrev = &this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>;
  this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>::mNext = &this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>;
  this->UFG::qNode<AnimationGroup,AnimationGroupUpdateList>::mPrev = &this->UFG::qNode<AnimationGroup,AnimationGroupUpdateList>;
  this->UFG::qNode<AnimationGroup,AnimationGroupUpdateList>::mNext = &this->UFG::qNode<AnimationGroup,AnimationGroupUpdateList>;
  this->Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&AnimationGroup::`vftable{for `Expression::IMemberMap};
  this->UFG::qSafePointerNode<AnimationGroup>::vfptr = (UFG::qSafePointerNode<AnimationGroup>Vtbl *)&AnimationGroup::`vftable{for `UFG::qSafePointerNode<AnimationGroup>};
  this->mName.mOffset = 1i64;
  BinString::Set(&this->mName, &customCaption);
  this->mAnimations.mCount = 0;
  this->mAnimations.mData.mOffset = 0i64;
  this->mCategory.mOffset = 1i64;
  BinString::Set(&this->mCategory, "default");
  this->mMode.mOffset = 1i64;
  BinString::Set(&this->mMode, "default");
  this->mAnimGroupHandles.mNode.mPrev = &this->mAnimGroupHandles.mNode;
  this->mAnimGroupHandles.mNode.mNext = &this->mAnimGroupHandles.mNode;
  this->mMemorySize = 0;
  *(_QWORD *)&this->mNameSymbol.mUID = -1i64;
  *(_QWORD *)&this->mRefCount = 0i64;
  *(_QWORD *)&this->mRefCountTotal = 0i64;
  *(_DWORD *)&this->mCurrentAnimationSubPriority = 16842752;
  *(_DWORD *)&this->mHighestBudgetedPriority.mValue = 1;
  this->mSourceABKFromSingleHKX = 0;
  this->mStreamHandle = 0i64;
}

// File Line: 2509
// RVA: 0x39CFE0
void __fastcall AnimationGroup::AnimationGroup(AnimationGroup *this, MemImageLoadFlag flag)
{
  char *v3; // rsi
  unsigned int v4; // ebx
  __int64 v5; // rdx
  UFG::qBaseNodeRB *v6; // rdx

  this->Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  UFG::qSafePointerNode<AnimationGroup>::qSafePointerNode<AnimationGroup>(&this->UFG::qSafePointerNode<AnimationGroup>);
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>::mPrev = &this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>;
  this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>::mNext = &this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>;
  this->UFG::qNode<AnimationGroup,AnimationGroupUpdateList>::mPrev = &this->UFG::qNode<AnimationGroup,AnimationGroupUpdateList>;
  this->UFG::qNode<AnimationGroup,AnimationGroupUpdateList>::mNext = &this->UFG::qNode<AnimationGroup,AnimationGroupUpdateList>;
  this->Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&AnimationGroup::`vftable{for `Expression::IMemberMap};
  this->UFG::qSafePointerNode<AnimationGroup>::vfptr = (UFG::qSafePointerNode<AnimationGroup>Vtbl *)&AnimationGroup::`vftable{for `UFG::qSafePointerNode<AnimationGroup>};
  this->mAnimGroupHandles.mNode.mPrev = &this->mAnimGroupHandles.mNode;
  this->mAnimGroupHandles.mNode.mNext = &this->mAnimGroupHandles.mNode;
  this->mMemorySize = 0;
  v3 = (char *)&this->mAnimations.mData + this->mAnimations.mData.mOffset;
  v4 = 0;
  if ( (this->mAnimations.mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v5 = (__int64)&v3[8 * v4 + *(_QWORD *)&v3[8 * v4]];
      if ( v5 )
        v6 = (UFG::qBaseNodeRB *)(v5 + 40);
      else
        v6 = 0i64;
      UFG::qBaseTreeRB::Add(&AnimationDataBase::sAnimationDataBase->mAnimations.mTree, v6);
      ++v4;
    }
    while ( v4 < (this->mAnimations.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 2519
// RVA: 0x39EDF0
void __fastcall AnimationGroup::~AnimationGroup(AnimationGroup *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // rbx
  int v3; // r8d
  int v4; // edx
  __int64 mOffset; // rcx
  char *v6; // r9
  char *v7; // r10
  char *v8; // r10
  char *v9; // r11
  UFG::qList<AnimationGroupHandle,AnimationGroupList,0,0> *p_mAnimGroupHandles; // r8
  AnimationGroup *mNext; // rdx
  Expression::IMemberMapVtbl *vfptr; // rcx
  Expression::IMemberMap *mResourceOwner; // rax
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *mPrev; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *v15; // rax
  char *v16; // rcx
  char *v17; // rcx
  __int64 v18; // rax
  char *v19; // rcx
  char *v20; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v21; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupUpdateList> *v22; // rax
  UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *v23; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v26; // rax

  this->Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&AnimationGroup::`vftable{for `Expression::IMemberMap};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->UFG::qSafePointerNode<AnimationGroup>;
  this->UFG::qSafePointerNode<AnimationGroup>::vfptr = (UFG::qSafePointerNode<AnimationGroup>Vtbl *)&AnimationGroup::`vftable{for `UFG::qSafePointerNode<AnimationGroup>};
  AnimationGroup::Destroy(this);
  while ( (this->mAnimations.mCount & 0x7FFFFFFF) != 0 )
  {
    v3 = this->mAnimations.mCount & 0x7FFFFFFF;
    if ( v3 && (v4 = v3 - 1, v3 - 1 >= 0) && v4 < v3 )
    {
      mOffset = this->mAnimations.mData.mOffset;
      if ( mOffset )
        v6 = (char *)&this->mAnimations.mData + mOffset;
      else
        v6 = 0i64;
      v7 = &v6[8 * v4];
      if ( *(_QWORD *)v7 )
        v8 = &v7[*(_QWORD *)v7];
      else
        v8 = 0i64;
      if ( mOffset )
        v9 = (char *)&this->mAnimations.mData + mOffset;
      else
        v9 = 0i64;
      if ( v3 == 1 )
      {
        this->mAnimations.mCount &= 0x80000000;
        this->mAnimations.mData.mOffset = 0i64;
      }
      else
      {
        this->mAnimations.mCount ^= (((this->mAnimations.mCount & 0x7FFFFFFF) - 1) ^ this->mAnimations.mCount) & 0x7FFFFFFF;
        *(_QWORD *)&v9[8 * (v3 - 1)] = 0i64;
      }
    }
    else
    {
      v8 = 0i64;
    }
    *((_QWORD *)v8 + 15) = 0i64;
    (*(void (__fastcall **)(char *, __int64))(*(_QWORD *)v8 + 8i64))(v8, 1i64);
  }
  p_mAnimGroupHandles = &this->mAnimGroupHandles;
  mNext = (AnimationGroup *)this->mAnimGroupHandles.mNode.mNext;
  if ( mNext != (AnimationGroup *)&this->mAnimGroupHandles )
  {
    do
    {
      vfptr = mNext->Expression::IMemberMap::vfptr;
      mResourceOwner = mNext->mResourceOwner;
      vfptr->__vecDelDtor = (void *(__fastcall *)(Expression::IMemberMap *, unsigned int))mResourceOwner;
      mResourceOwner->vfptr = vfptr;
      mNext->Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)mNext;
      mNext->mResourceOwner = mNext;
      mNext = (AnimationGroup *)this->mAnimGroupHandles.mNode.mNext;
    }
    while ( mNext != (AnimationGroup *)p_mAnimGroupHandles );
  }
  mPrev = p_mAnimGroupHandles->mNode.mPrev;
  v15 = this->mAnimGroupHandles.mNode.mNext;
  mPrev->mNext = v15;
  v15->mPrev = mPrev;
  p_mAnimGroupHandles->mNode.mPrev = &p_mAnimGroupHandles->mNode;
  this->mAnimGroupHandles.mNode.mNext = &this->mAnimGroupHandles.mNode;
  if ( (this->mMode.mOffset & 1) != 0 && (this->mMode.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v16 = (char *)&this->mMode + (this->mMode.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v16 != BinString::sEmptyString )
      operator delete[](v16);
  }
  if ( (this->mCategory.mOffset & 1) != 0 && (this->mCategory.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v17 = (char *)&this->mCategory + (this->mCategory.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v17 != BinString::sEmptyString )
      operator delete[](v17);
  }
  if ( this->mAnimations.mCount >= 0 )
  {
    v18 = this->mAnimations.mData.mOffset;
    if ( v18 )
    {
      v19 = (char *)&this->mAnimations.mData + v18;
      if ( v19 )
        operator delete[](v19);
    }
    this->mAnimations.mData.mOffset = 0i64;
    this->mAnimations.mCount &= 0x80000000;
  }
  if ( (this->mName.mOffset & 1) != 0 && (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v20 = (char *)&this->mName + (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v20 != BinString::sEmptyString )
      operator delete[](v20);
  }
  v21 = this->UFG::qNode<AnimationGroup,AnimationGroupUpdateList>::mPrev;
  v22 = this->UFG::qNode<AnimationGroup,AnimationGroupUpdateList>::mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  this->UFG::qNode<AnimationGroup,AnimationGroupUpdateList>::mPrev = &this->UFG::qNode<AnimationGroup,AnimationGroupUpdateList>;
  this->UFG::qNode<AnimationGroup,AnimationGroupUpdateList>::mNext = &this->UFG::qNode<AnimationGroup,AnimationGroupUpdateList>;
  v23 = this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>::mPrev;
  v24 = this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>::mNext;
  v23->mNext = v24;
  v24->mPrev = v23;
  this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>::mPrev = &this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>;
  this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>::mNext = &this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>;
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<AnimationGroup>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v2->m_SafePointerList);
  v25 = v2->m_SafePointerList.mNode.mPrev;
  v26 = v2->m_SafePointerList.mNode.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  v2->m_SafePointerList.mNode.mPrev = &v2->m_SafePointerList.mNode;
  v2->m_SafePointerList.mNode.mNext = &v2->m_SafePointerList.mNode;
  this->Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 2533
// RVA: 0x3A6840
void __fastcall AnimationGroup::Destroy(AnimationGroup *this)
{
  char *v2; // rdi
  unsigned int v3; // ebx
  __int64 v4; // rdx
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
  __int64 v19; // rbx
  UFG::StreamPriorityHandle *mStreamHandle; // rdx

  v2 = (char *)&this->mAnimations.mData + this->mAnimations.mData.mOffset;
  v3 = 0;
  if ( (this->mAnimations.mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v4 = (__int64)&v2[8 * v3 + *(_QWORD *)&v2[8 * v3]];
      if ( v4 )
        v5 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)(v4 + 40);
      else
        v5 = 0i64;
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&AnimationDataBase::sAnimationDataBase->mAnimations,
        v5);
      ++v3;
    }
    while ( v3 < (this->mAnimations.mCount & 0x7FFFFFFFu) );
  }
  v6 = AnimationDataBase::sAnimationDataBase;
  AnimationGroup::UnloadInternal(this);
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v6->mAnimGroups,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&this->UFG::qNodeRB<AnimationGroup>);
  v7 = 0i64;
  v8 = 0;
  v9 = 0;
  for ( i = (AnimationGroup *)this->mAnimGroupHandles.mNode.mNext;
        i != (AnimationGroup *)&this->mAnimGroupHandles;
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
  v19 = 0i64;
  if ( v8 )
  {
    do
      AnimationGroupHandle::Unbind((AnimationGroupHandle *)v7[v19++].mNext);
    while ( v19 < v8 );
  }
  if ( v7 )
    operator delete[](v7);
  mStreamHandle = this->mStreamHandle;
  if ( mStreamHandle )
  {
    UFG::StreamPrioritySystem::FreeHandle(AnimationGroup::sStreamPrioritySystem, mStreamHandle);
    this->mStreamHandle = 0i64;
  }
}

// File Line: 2596
// RVA: 0x3AB490
void __fastcall AnimationGroup::LoadInternal(AnimationGroup *this)
{
  const char **v2; // r15
  __int64 v3; // r12
  char *v4; // rax
  char *v5; // r14
  __int64 v6; // rbx
  __int64 v7; // rdx
  unsigned int v8; // esi
  UFG::qResourceHandle *v9; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v11; // rax
  const char *Name; // rax
  unsigned int MemorySize; // eax
  const char *v14; // rdx
  UFG::qString v15; // [rsp+28h] [rbp-80h] BYREF
  UFG::qString v16; // [rsp+50h] [rbp-58h] BYREF

  v2 = gLoadPaths;
  v3 = 2i64;
  do
  {
    UFG::qString::qString(&v15, *v2);
    v4 = UFG::qSymbol::as_cstr_dbg(&this->mNameSymbol);
    UFG::qString::operator+=(&v15, v4);
    UFG::qString::operator+=(&v15, "\\");
    v5 = (char *)&this->mAnimations.mData + this->mAnimations.mData.mOffset;
    v6 = 0i64;
    if ( (this->mAnimations.mCount & 0x7FFFFFFF) != 0 )
    {
      do
      {
        v7 = (__int64)&v5[8 * v6 + *(_QWORD *)&v5[8 * v6]];
        v8 = *(_DWORD *)(v7 + 168);
        v9 = (UFG::qResourceHandle *)(v7 + 88);
        *(_QWORD *)(v7 + 120) = v7;
        Inventory = `UFG::qGetResourceInventory<UFG::AnimationResource>::`2::result;
        if ( !`UFG::qGetResourceInventory<UFG::AnimationResource>::`2::result )
        {
          v11 = UFG::qResourceWarehouse::Instance();
          Inventory = UFG::qResourceWarehouse::GetInventory(v11, 0x53F1685Eu);
          `UFG::qGetResourceInventory<UFG::AnimationResource>::`2::result = Inventory;
        }
        UFG::qResourceHandle::Init(v9, 0x53F1685Eu, v8, Inventory);
        v6 = (unsigned int)(v6 + 1);
      }
      while ( (unsigned int)v6 < (this->mAnimations.mCount & 0x7FFFFFFFu) );
    }
    Name = AnimationGroup::GetName(this);
    UFG::qString::qString(&v16, "%s%s.bin", *v2, Name);
    MemorySize = UFG::StreamPrioritySystem::GetMemorySize(v16.mData);
    if ( this->mMemorySize > MemorySize )
      MemorySize = this->mMemorySize;
    this->mMemorySize = MemorySize;
    UFG::qString::~qString(&v16);
    UFG::qString::~qString(&v15);
    ++v2;
    --v3;
  }
  while ( v3 );
  if ( !this->mMemorySize )
  {
    if ( (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
      v14 = (char *)&this->mName + (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    else
      v14 = BinString::sEmptyString;
    UFG::qPrintf(
      "WARNING: Zero Byte Animation Binary File Found: %s -- this will cause all sorts of streaming problems!\n",
      v14);
  }
  AnimationGroup::CreateStreamHandle(this);
}

// File Line: 2629
// RVA: 0x3B04E0
void __fastcall AnimationGroup::UnloadInternal(AnimationGroup *this)
{
  __int64 v2; // rbp
  __int64 v3; // rbx
  char *v4; // r14
  UFG::qResourceInventory *Inventory; // rax
  __int64 v6; // rdi
  UFG::qResourceWarehouse *v7; // rax
  UFG::StreamPriorityHandle *mStreamHandle; // rbx
  const char *mText; // rbx
  UFG::HotSwapFileManager *v10; // rax
  fastdelegate::FastDelegate1<char const *,void> v11; // [rsp+20h] [rbp-18h] BYREF

  v2 = 2i64;
  do
  {
    v3 = 0i64;
    v4 = (char *)&this->mAnimations.mData + this->mAnimations.mData.mOffset;
    if ( (this->mAnimations.mCount & 0x7FFFFFFF) != 0 )
    {
      do
      {
        Inventory = `UFG::qGetResourceInventory<UFG::AnimationResource>::`2::result;
        v6 = (__int64)&v4[8 * v3 + *(_QWORD *)&v4[8 * v3]];
        if ( !`UFG::qGetResourceInventory<UFG::AnimationResource>::`2::result )
        {
          v7 = UFG::qResourceWarehouse::Instance();
          Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x53F1685Eu);
          `UFG::qGetResourceInventory<UFG::AnimationResource>::`2::result = Inventory;
        }
        UFG::qResourceHandle::Close((UFG::qResourceHandle *)(v6 + 88), Inventory);
        v3 = (unsigned int)(v3 + 1);
      }
      while ( (unsigned int)v3 < (this->mAnimations.mCount & 0x7FFFFFFFu) );
    }
    --v2;
  }
  while ( v2 );
  mStreamHandle = this->mStreamHandle;
  if ( mStreamHandle )
  {
    v11 = UFG::DefaultHotSwapCallBack;
    mText = mStreamHandle->mFilename.mText;
    v10 = UFG::HotSwapFileManager::Get();
    UFG::HotSwapFileManager::UnRegisterFile(v10, mText, &v11);
    UFG::StreamPrioritySystem::FreeHandle(AnimationGroup::sStreamPrioritySystem, this->mStreamHandle);
    this->mStreamHandle = 0i64;
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

  v1 = this->mRefCount-- == 1;
  if ( v1 && !this->mAnimRefCount )
    AnimationGroup::DestroyStreamHandle(this);
  return this->mRefCount == 0;
}

// File Line: 2696
// RVA: 0x3AE500
void __fastcall AnimationGroup::Serialize(AnimationGroup *this, IActionTreeSerializer *serializer)
{
  unsigned int v4; // ebx
  char *v5; // r14
  char *v6; // rcx
  char *v7; // rdi
  const char *v8; // rax

  v4 = 0;
  v5 = (char *)&this->mAnimations.mData + this->mAnimations.mData.mOffset;
  if ( (this->mAnimations.mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v6 = &v5[8 * v4];
      v7 = &v6[*(_QWORD *)v6];
      if ( v7 )
      {
        v8 = (const char *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v7 + 32i64))(&v6[*(_QWORD *)v6]);
        serializer->vfptr->_PushObjectToSerialize(
          serializer,
          v7,
          1u,
          (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
          v8,
          PRIORITY_MEDIUM,
          0,
          0i64,
          -1u,
          0i64);
      }
      ++v4;
    }
    while ( v4 < (this->mAnimations.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 2749
// RVA: 0x3A6540
void __fastcall AnimationGroup::CreateStreamHandle(AnimationGroup *this)
{
  const char *v2; // r8
  hkResourceHandle *v3; // rax
  const char *v4; // r8
  hkResourceHandle *v5; // rax
  UFG::qSharedString filename; // [rsp+70h] [rbp+8h] BYREF
  UFG::qSharedString v7; // [rsp+78h] [rbp+10h] BYREF

  if ( (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    v2 = (char *)&this->mName + (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
  else
    v2 = BinString::sEmptyString;
  UFG::qSharedString::qSharedString(&filename, "Data\\Animation\\%s.bin", v2);
  if ( (unsigned int)UFG::StreamPrioritySystem::GetMemorySize(filename.mText) )
  {
    this->mStreamHandle = UFG::StreamPrioritySystem::CreateHandle(AnimationGroup::sStreamPrioritySystem, &filename);
    v3 = (hkResourceHandle *)UFG::HotSwapFileManager::Get();
    TargetVisibleInAIDataCondition::CreateClone(v3);
  }
  else
  {
    if ( (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
      v4 = (char *)&this->mName + (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    else
      v4 = BinString::sEmptyString;
    UFG::qSharedString::qSharedString(&v7, "Data\\AnimationNIS\\%s.bin", v4);
    this->mStreamHandle = UFG::StreamPrioritySystem::CreateHandle(AnimationGroup::sStreamPrioritySystem, &v7);
    v5 = (hkResourceHandle *)UFG::HotSwapFileManager::Get();
    TargetVisibleInAIDataCondition::CreateClone(v5);
    UFG::qSharedString::~qSharedString(&v7);
  }
  UFG::qSharedString::~qSharedString(&filename);
}

// File Line: 2767
// RVA: 0x3A6C80
void __fastcall AnimationGroup::DestroyStreamHandle(AnimationGroup *this)
{
  UFG::StreamPriorityHandle *mStreamHandle; // rbx
  const char *mText; // rbx
  UFG::HotSwapFileManager *v4; // rax
  fastdelegate::FastDelegate1<char const *,void> v5; // [rsp+20h] [rbp-18h] BYREF

  mStreamHandle = this->mStreamHandle;
  if ( mStreamHandle )
  {
    v5 = UFG::DefaultHotSwapCallBack;
    mText = mStreamHandle->mFilename.mText;
    v4 = UFG::HotSwapFileManager::Get();
    UFG::HotSwapFileManager::UnRegisterFile(v4, mText, &v5);
    UFG::StreamPrioritySystem::FreeHandle(AnimationGroup::sStreamPrioritySystem, this->mStreamHandle);
    this->mStreamHandle = 0i64;
  }
}

// File Line: 2808
// RVA: 0x3AB330
bool __fastcall AnimationGroup::IsStreamedIn(AnimationGroup *this)
{
  UFG::StreamPriorityHandle *mStreamHandle; // rcx

  mStreamHandle = this->mStreamHandle;
  return mStreamHandle && (unsigned int)UFG::DataStreamer::GetStreamState(&mStreamHandle->mHandle) == 6;
}

// File Line: 2864
// RVA: 0x3B49F0
void __fastcall AnimationGroup::UpdatePriorityFromHandles(AnimationGroup *this)
{
  __int64 mValue; // r8
  int v2; // r10d
  __int64 v3; // rbx
  UFG::qList<AnimationGroupHandle,AnimationGroupList,0,0> *p_mAnimGroupHandles; // r11
  UFG::qNode<AnimationGroupHandle,AnimationGroupList> *mNext; // rcx
  UFG::qList<AnimationGroupHandle,AnimationGroupList,0,0> *v7; // r9
  __int64 mPrev_low; // rdx
  UFG::qPropertySet *mStreamHandle; // rdx
  UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *v10; // rdx
  UFG::qList<AnimationGroup,AnimationGroupBudgetedList,0,0> *p_mBudgetedAnimationGroups; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *mPrev; // rax
  UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *v13; // rcx
  UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> *v14; // rax

  mValue = (unsigned int)this->mDefaultAnimationPriority.mValue;
  v2 = 0;
  v3 = 0i64;
  p_mAnimGroupHandles = &this->mAnimGroupHandles;
  mNext = this->mAnimGroupHandles.mNode.mNext;
  if ( AnimationDataBase::sAnimationDataBase->mPriorityBudgets.p[mValue].mMaxSize )
    v3 = (unsigned int)mValue;
  if ( mNext != (UFG::qNode<AnimationGroupHandle,AnimationGroupList> *)p_mAnimGroupHandles )
  {
    do
    {
      v7 = (UFG::qList<AnimationGroupHandle,AnimationGroupList,0,0> *)mNext->mNext;
      if ( mNext[3].mNext )
      {
        mPrev_low = LOWORD(mNext[4].mPrev);
        if ( (int)mPrev_low > (int)mValue || (_DWORD)mPrev_low == (_DWORD)mValue && WORD1(mNext[4].mPrev) > v2 )
        {
          v2 = WORD1(mNext[4].mPrev);
          LODWORD(mValue) = LOWORD(mNext[4].mPrev);
        }
        if ( AnimationDataBase::sAnimationDataBase->mPriorityBudgets.p[mPrev_low].mMaxSize && (int)mPrev_low > (int)v3 )
          v3 = LOWORD(mNext[4].mPrev);
      }
      mNext = mNext->mNext;
    }
    while ( v7 != p_mAnimGroupHandles );
  }
  mStreamHandle = (UFG::qPropertySet *)this->mStreamHandle;
  this->mCurrentAnimationPriority.mValue = mValue;
  this->mCurrentAnimationSubPriority = v2;
  if ( mStreamHandle )
    UFG::StreamPrioritySystem::ChangePriority(
      AnimationGroup::sStreamPrioritySystem,
      mStreamHandle,
      (unsigned __int16)v2 | ((unsigned __int16)(char)mValue << 16));
  this->mHighestBudgetedPriority.mValue = v3;
  v10 = &this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>;
  if ( AnimationDataBase::sAnimationDataBase->mPriorityBudgets.p[v3].mMaxSize )
  {
    if ( v10->mPrev == v10
      && this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>::mNext == &this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList> )
    {
      p_mBudgetedAnimationGroups = &AnimationDataBase::sAnimationDataBase->mBudgetedAnimationGroups;
      mPrev = AnimationDataBase::sAnimationDataBase->mBudgetedAnimationGroups.mNode.mPrev;
      mPrev->mNext = v10;
      v10->mPrev = mPrev;
      this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>::mNext = &p_mBudgetedAnimationGroups->mNode;
      p_mBudgetedAnimationGroups->mNode.mPrev = v10;
    }
  }
  else
  {
    v13 = v10->mPrev;
    v14 = this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>::mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v10->mPrev = v10;
    this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>::mNext = &this->UFG::qNode<AnimationGroup,AnimationGroupBudgetedList>;
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gBlendTreeNodeFactory__);
}

// File Line: 3240
// RVA: 0x3AB3F0
PoseNode *__fastcall BlendTreeDataBase::LoadBlendTrees(BlendTreeDataBase *this, const char *bankBlendTreeFileName)
{
  hkResourceHandle *v2; // rax
  UFG::qString v4; // [rsp+58h] [rbp-30h] BYREF

  v2 = (hkResourceHandle *)UFG::HotSwapFileManager::Get();
  TargetVisibleInAIDataCondition::CreateClone(v2);
  UFG::qString::qString(&v4);
  UFG::qString::~qString(&v4);
  return 0i64;
}

// File Line: 3288
// RVA: 0x3AD6B0
PoseNode *__fastcall BlendTreeDataBase::ReLoadBlendTrees(BlendTreeDataBase *this, const char *bankNameFileName)
{
  UFG::qSymbolUC *p_mNext; // rbx
  char *mData; // rdi
  char *v6; // rax
  __int64 v7; // rcx
  _QWORD *v8; // rax
  PoseNode *BlendTrees; // rbx
  UFG::qString result; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString v12; // [rsp+50h] [rbp-38h] BYREF

  UFG::qString::qString(&v12, bankNameFileName);
  UFG::qString::GetFilenameWithoutExtension(&v12, &result);
  p_mNext = (UFG::qSymbolUC *)&this->mPoseNodes.mNode.mNext[-3].mNext;
  if ( p_mNext != (UFG::qSymbolUC *)&this[-1].mPoseNodes.mNode.mNext )
  {
    while ( 1 )
    {
      mData = result.mData;
      v6 = UFG::qSymbol::as_cstr_dbg(p_mNext + 17);
      if ( !(unsigned int)UFG::qStringCompareInsensitive(mData, v6, -1) )
        break;
      p_mNext = (UFG::qSymbolUC *)(*(_QWORD *)&p_mNext[12].mUID - 40i64);
      if ( p_mNext == (UFG::qSymbolUC *)&this[-1].mPoseNodes.mNode.mNext )
        goto LABEL_7;
    }
    v7 = *(_QWORD *)&p_mNext[10].mUID;
    v8 = *(_QWORD **)&p_mNext[12].mUID;
    *(_QWORD *)(v7 + 8) = v8;
    *v8 = v7;
    *(_QWORD *)&p_mNext[10].mUID = p_mNext + 10;
    *(_QWORD *)&p_mNext[12].mUID = p_mNext + 10;
    if ( p_mNext )
      (*(void (__fastcall **)(UFG::qSymbolUC *, __int64))(*(_QWORD *)&p_mNext->mUID + 8i64))(p_mNext, 1i64);
  }
LABEL_7:
  BlendTrees = BlendTreeDataBase::LoadBlendTrees(this, bankNameFileName);
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&v12);
  return BlendTrees;
}

// File Line: 3309
// RVA: 0x3AA9C0
void __fastcall PoseCache::Init(unsigned __int64 cache_size)
{
  UFG::allocator::free_link *v2; // rax
  PoseCache *v3; // rax

  v2 = UFG::qMalloc(0x24C8ui64, "PoseCache", 0i64);
  if ( v2 )
    PoseCache::PoseCache((PoseCache *)v2);
  else
    v3 = 0i64;
  PoseCache::sPoseCache = v3;
  if ( cache_size )
  {
    UFG::qMemoryPool::Init(&v3->mCachedDataPool, "PoseCachePool", cache_size, 0, 0, 1u, 0i64, 1, 1);
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
UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *__fastcall PoseCache::Find(PoseCache *this, unsigned __int64 uid)
{
  UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *p_mCachedDataTree; // rcx
  UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *result; // rax
  bool i; // zf
  PoseCacheNode *j; // rcx

  if ( uid )
  {
    p_mCachedDataTree = &this->mCachedDataTree;
    result = p_mCachedDataTree;
    for ( i = p_mCachedDataTree == (UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *)&p_mCachedDataTree->mTree.mNULL;
          !i;
          i = result == (UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *)&p_mCachedDataTree->mTree.mNULL )
    {
      if ( result != p_mCachedDataTree && result->mTree.mRoot.mUID == uid )
      {
        for ( j = (PoseCacheNode *)result->mTree.mRoot.mChild[0]; j; j = (PoseCacheNode *)j->mNode.mChild[0] )
        {
          if ( j->mNode.mUID != uid )
            break;
          result = (UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *)j;
        }
        return result;
      }
      if ( uid > result->mTree.mRoot.mUID )
        result = (UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *)result->mTree.mRoot.mChild[1];
      else
        result = (UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *)result->mTree.mRoot.mChild[0];
    }
  }
  return 0i64;
}

// File Line: 3376
// RVA: 0x3AFCA0
UFG::allocator::free_link *__fastcall PoseCache::Store(
        PoseCache *this,
        UFG::allocator::free_link *uid,
        UFG::allocator::free_link *size)
{
  UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *p_mCachedDataTree; // rcx
  UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *v7; // rax
  bool i; // zf
  UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *j; // rcx
  UFG::qList<PoseCacheNode,PoseCacheNode,1,0> *p_mCachedDataList; // r14
  UFG::qNode<PoseCacheNode,PoseCacheNode> *mNext; // rdx
  UFG::qNode<PoseCacheNode,PoseCacheNode> *mPrev; // rcx
  UFG::qNode<PoseCacheNode,PoseCacheNode> *v14; // rax
  UFG::qNode<PoseCacheNode,PoseCacheNode> *v15; // rbx
  UFG::qNode<PoseCacheNode,PoseCacheNode> *v16; // rdx
  UFG::qNode<PoseCacheNode,PoseCacheNode> *v17; // rax
  UFG::allocator::free_link *v18; // rbp
  UFG::allocator::free_link *v19; // rax
  UFG::allocator::free_link *v20; // rbx
  UFG::allocator::free_link *v21; // rax
  UFG::qNode<PoseCacheNode,PoseCacheNode> *v22; // rcx

  if ( uid )
  {
    p_mCachedDataTree = &this->mCachedDataTree;
    v7 = p_mCachedDataTree;
    for ( i = p_mCachedDataTree == (UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *)&p_mCachedDataTree->mTree.mNULL;
          !i;
          i = v7 == (UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *)&p_mCachedDataTree->mTree.mNULL )
    {
      if ( v7 != p_mCachedDataTree && (UFG::allocator::free_link *)v7->mTree.mRoot.mUID == uid )
      {
        for ( j = (UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *)v7->mTree.mRoot.mChild[0];
              j;
              j = (UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *)j->mTree.mRoot.mChild[0] )
        {
          if ( (UFG::allocator::free_link *)j->mTree.mRoot.mUID != uid )
            break;
          v7 = j;
        }
        if ( v7 )
          return 0i64;
        break;
      }
      if ( (unsigned __int64)uid > v7->mTree.mRoot.mUID )
        v7 = (UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *)v7->mTree.mRoot.mChild[1];
      else
        v7 = (UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *)v7->mTree.mRoot.mChild[0];
    }
  }
  p_mCachedDataList = &this->mCachedDataList;
  while ( ($CA91B2824B6F331601351B2AC7FEF5D9 *)&this->mCachedDataList.mNode.mNext[-2] != &this->mCachedDataTree.mTree.mNULL.8 )
  {
    if ( UFG::qMemoryPool::GetLargestFree(&this->mCachedDataPool, 0i64) >= (unsigned __int64)size )
      break;
    mNext = this->mCachedDataList.mNode.mNext;
    mPrev = mNext->mPrev;
    v14 = mNext->mNext;
    mPrev->mNext = v14;
    v14->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    v15 = mNext - 2;
    UFG::qMemoryPool::Free(&this->mCachedDataPool, (char *)mNext[1].mPrev);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      &this->mCachedDataTree.mTree,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)v15);
    this->mPoseCacheUsageBytes -= LODWORD(v15[5].mPrev);
    --this->mPoseCacheUsageEntries;
    v16 = v15[2].mPrev;
    v17 = v15[2].mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v15[2].mPrev = v15 + 2;
    v15[2].mNext = v15 + 2;
    operator delete[](v15);
  }
  v18 = UFG::qMemoryPool::Allocate(&this->mCachedDataPool, (unsigned __int64)size, "pose_cache_alloc", 0i64, 1u);
  v19 = UFG::qMalloc(0x60ui64, "PoseCacheNode", 0x800ui64);
  v20 = v19;
  if ( v19 )
  {
    v19->mNext = 0i64;
    v19[1].mNext = 0i64;
    v19[2].mNext = 0i64;
    v19[3].mNext = uid;
    v21 = v19 + 4;
    v21->mNext = v21;
    v21[1].mNext = v21;
    v20[6].mNext = v18;
    v20[10].mNext = size;
    LODWORD(v20[11].mNext) = 0;
  }
  else
  {
    v20 = 0i64;
  }
  v22 = p_mCachedDataList->mNode.mPrev;
  v22->mNext = (UFG::qNode<PoseCacheNode,PoseCacheNode> *)&v20[4];
  v20[4].mNext = (UFG::allocator::free_link *)v22;
  v20[5].mNext = (UFG::allocator::free_link *)p_mCachedDataList;
  p_mCachedDataList->mNode.mPrev = (UFG::qNode<PoseCacheNode,PoseCacheNode> *)&v20[4];
  UFG::qBaseTreeVariableRB<unsigned __int64>::Add(
    &this->mCachedDataTree.mTree,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)v20);
  this->mPoseCacheUsageBytes += LODWORD(v20[10].mNext);
  ++this->mPoseCacheUsageEntries;
  return v20;
}


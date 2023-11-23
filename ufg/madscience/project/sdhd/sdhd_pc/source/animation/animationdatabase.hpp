// File Line: 161
// RVA: 0x2DD9E0
void __fastcall AnimationGroupHandleContainer::AnimationGroupHandleContainer(AnimationGroupHandleContainer *this)
{
  this->m_AnimationGroupHandleList.mNode.mPrev = &this->m_AnimationGroupHandleList.mNode;
  this->m_AnimationGroupHandleList.mNode.mNext = &this->m_AnimationGroupHandleList.mNode;
  this->m_bHasBeenBound = 0;
}

// File Line: 162
// RVA: 0x2E3130
void __fastcall AnimationGroupHandleContainer::~AnimationGroupHandleContainer(AnimationGroupHandleContainer *this)
{
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *mPrev; // rdx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *mNext; // rax

  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&this->m_AnimationGroupHandleList);
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&this->m_AnimationGroupHandleList);
  mPrev = this->m_AnimationGroupHandleList.mNode.mPrev;
  mNext = this->m_AnimationGroupHandleList.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->m_AnimationGroupHandleList.mNode.mPrev = &this->m_AnimationGroupHandleList.mNode;
  this->m_AnimationGroupHandleList.mNode.mNext = &this->m_AnimationGroupHandleList.mNode;
}

// File Line: 167
// RVA: 0x492700
void __fastcall AnimationGroupHandleContainer::Add(
        AnimationGroupHandleContainer *this,
        const char *pAnimationGroupName,
        UFG::eAnimationPriorityEnum eAnimationPriority)
{
  UFG::qSymbolUC *v5; // rax
  UFG::qSymbolUC result; // [rsp+48h] [rbp+20h] BYREF

  v5 = UFG::qSymbolUC::create_from_string(&result, pAnimationGroupName);
  AnimationGroupHandleContainer::Add(this, v5, eAnimationPriority);
}

// File Line: 174
// RVA: 0x2E79E0
void __fastcall AnimationGroupHandleContainer::Add(
        AnimationGroupHandleContainer *this,
        UFG::qSymbolUC *theAnimationGroupSymbol,
        UFG::eAnimationPriorityEnum eAnimationPriority)
{
  UFG::allocator::free_link *v6; // rax
  AnimationGroupHandle *v7; // rax
  AnimationGroupHandle *v8; // rbx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *mPrev; // rax

  v6 = UFG::qMalloc(0x50ui64, "AnimationGroupHandle", 0i64);
  if ( v6 )
  {
    AnimationGroupHandle::AnimationGroupHandle((AnimationGroupHandle *)v6);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  AnimationGroupHandle::Init(v8, theAnimationGroupSymbol, eAnimationPriority);
  mPrev = this->m_AnimationGroupHandleList.mNode.mPrev;
  mPrev->mNext = &v8->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>;
  v8->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mPrev = mPrev;
  v8->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext = &this->m_AnimationGroupHandleList.mNode;
  this->m_AnimationGroupHandleList.mNode.mPrev = &v8->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>;
}

// File Line: 184
// RVA: 0x4B62F0
char __fastcall AnimationGroupHandleContainer::Remove(
        AnimationGroupHandleContainer *this,
        UFG::qSymbolUC *theAnimationGroupSymbol)
{
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *mNext; // rbx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> **p_mNext; // rcx
  AnimationGroupHandle *v4; // rbx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *mPrev; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v7; // rax

  mNext = this->m_AnimationGroupHandleList.mNode.mNext;
  p_mNext = &this[-1].m_AnimationGroupHandleList.mNode.mNext;
  v4 = (AnimationGroupHandle *)&mNext[-1];
  if ( v4 == (AnimationGroupHandle *)p_mNext )
    return 0;
  while ( v4->m_AnimationGroupSymbol.mUID != theAnimationGroupSymbol->mUID )
  {
    v4 = (AnimationGroupHandle *)&v4->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext[-1];
    if ( v4 == (AnimationGroupHandle *)p_mNext )
      return 0;
  }
  AnimationGroupHandle::Unbind(v4);
  mPrev = v4->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mPrev;
  v7 = v4->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext;
  mPrev->mNext = v7;
  v7->mPrev = mPrev;
  v4->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mPrev = &v4->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>;
  v4->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext = &v4->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>;
  AnimationGroupHandle::~AnimationGroupHandle(v4);
  operator delete[](v4);
  return 1;
}

// File Line: 199
// RVA: 0x4B6370
char __fastcall AnimationGroupHandleContainer::Remove(
        AnimationGroupHandleContainer *this,
        const char *pAnimationGroupName)
{
  UFG::qSymbolUC *v3; // rax
  UFG::qSymbolUC result; // [rsp+40h] [rbp+18h] BYREF

  v3 = UFG::qSymbolUC::create_from_string(&result, pAnimationGroupName);
  return AnimationGroupHandleContainer::Remove(this, v3);
}

// File Line: 209
// RVA: 0x2FD360
_BOOL8 __fastcall AnimationGroupHandleContainer::Bind(AnimationGroupHandleContainer *this)
{
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> **p_mNext; // rsi
  AnimationGroupHandle *v3; // rbx
  bool v4; // di
  char v5; // al

  p_mNext = &this[-1].m_AnimationGroupHandleList.mNode.mNext;
  v3 = (AnimationGroupHandle *)&this->m_AnimationGroupHandleList.mNode.mNext[-1];
  v4 = 1;
  if ( v3 == (AnimationGroupHandle *)&this[-1].m_AnimationGroupHandleList.mNode.mNext )
  {
    this->m_bHasBeenBound = 1;
  }
  else
  {
    do
    {
      v5 = AnimationGroupHandle::Bind(v3);
      v4 = v4 && v5;
      v3 = (AnimationGroupHandle *)&v3->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext[-1];
    }
    while ( v3 != (AnimationGroupHandle *)p_mNext );
    this->m_bHasBeenBound = 1;
  }
  return v4;
}

// File Line: 224
// RVA: 0x3038E0
void __fastcall AnimationGroupHandleContainer::Unbind(AnimationGroupHandleContainer *this)
{
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> **p_mNext; // rsi
  AnimationGroupHandle *v3; // rbx

  p_mNext = &this[-1].m_AnimationGroupHandleList.mNode.mNext;
  v3 = (AnimationGroupHandle *)&this->m_AnimationGroupHandleList.mNode.mNext[-1];
  if ( v3 == (AnimationGroupHandle *)&this[-1].m_AnimationGroupHandleList.mNode.mNext )
  {
    this->m_bHasBeenBound = 0;
  }
  else
  {
    do
    {
      AnimationGroupHandle::Unbind(v3);
      v3 = (AnimationGroupHandle *)&v3->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext[-1];
    }
    while ( v3 != (AnimationGroupHandle *)p_mNext );
    this->m_bHasBeenBound = 0;
  }
}

// File Line: 310
// RVA: 0x58B800
void __fastcall AnimationGroupHandleContainer::SetAnimationPriority(
        AnimationGroupHandleContainer *this,
        UFG::eAnimationPriorityEnum eAnimationPriority,
        unsigned __int16 subPriority)
{
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> **p_mNext; // rdi
  AnimationGroupHandle *v5; // rbx

  p_mNext = &this[-1].m_AnimationGroupHandleList.mNode.mNext;
  v5 = (AnimationGroupHandle *)&this->m_AnimationGroupHandleList.mNode.mNext[-1];
  if ( v5 != (AnimationGroupHandle *)&this[-1].m_AnimationGroupHandleList.mNode.mNext )
  {
    do
    {
      AnimationGroupHandle::SetAnimationPriority(v5, eAnimationPriority, subPriority);
      v5 = (AnimationGroupHandle *)&v5->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext[-1];
    }
    while ( v5 != (AnimationGroupHandle *)p_mNext );
  }
}

// File Line: 376
// RVA: 0x3A7DA0
__int64 __fastcall BlendTreeDataBase::GetClassNameUID(BlendTreeDataBase *this)
{
  return BlendTreeDataBase::sClassNameUID;
}

// File Line: 449
// RVA: 0x3A7DE0
const char *__fastcall AnimationDataBase::GetClassname(AnimationDataBase *this)
{
  return AnimationDataBase::sClassName;
}

// File Line: 593
// RVA: 0x3A7DF0
const char *__fastcall AnimationGroup::GetClassname(AnimationGroup *this)
{
  return AnimationGroup::sClassName;
}

// File Line: 596
// RVA: 0x297280
const char *__fastcall AnimationGroup::GetName(AnimationGroup *this)
{
  if ( (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    return (char *)&this->mName + (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
  else
    return BinString::sEmptyString;
}

// File Line: 885
// RVA: 0x39E210
void __fastcall PoseCache::PoseCache(PoseCache *this)
{
  this->mCachedDataTree.mTree.mRoot.mParent = 0i64;
  this->mCachedDataTree.mTree.mRoot.8 = 0ui64;
  this->mCachedDataTree.mTree.mNULL.mParent = 0i64;
  this->mCachedDataTree.mTree.mNULL.8 = 0ui64;
  this->mCachedDataTree.mTree.mNULL.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&this->mCachedDataTree.mTree.mNULL | (__int64)this->mCachedDataTree.mTree.mNULL.mParent & 1);
  this->mCachedDataTree.mTree.mNULL.mChild[0] = &this->mCachedDataTree.mTree.mNULL;
  this->mCachedDataTree.mTree.mNULL.mChild[1] = &this->mCachedDataTree.mTree.mNULL;
  this->mCachedDataTree.mTree.mNULL.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)this->mCachedDataTree.mTree.mNULL.mParent & ~1ui64);
  this->mCachedDataTree.mTree.mNULL.mUID = 0i64;
  this->mCachedDataTree.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&this->mCachedDataTree.mTree.mNULL | (__int64)this->mCachedDataTree.mTree.mRoot.mParent & 1);
  this->mCachedDataTree.mTree.mRoot.mChild[0] = &this->mCachedDataTree.mTree.mNULL;
  this->mCachedDataTree.mTree.mRoot.mChild[1] = &this->mCachedDataTree.mTree.mNULL;
  this->mCachedDataTree.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)this->mCachedDataTree.mTree.mRoot.mParent & ~1ui64);
  this->mCachedDataTree.mTree.mRoot.mUID = -1i64;
  this->mCachedDataTree.mTree.mCount = 0;
  this->mCachedDataList.mNode.mPrev = &this->mCachedDataList.mNode;
  this->mCachedDataList.mNode.mNext = &this->mCachedDataList.mNode;
  UFG::qMemoryPool::qMemoryPool(&this->mCachedDataPool);
}


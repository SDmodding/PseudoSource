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
  AnimationGroupHandleContainer *v1; // rbx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v2; // rdx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v3; // rax

  v1 = this;
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&this->m_AnimationGroupHandleList);
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&v1->m_AnimationGroupHandleList);
  v2 = v1->m_AnimationGroupHandleList.mNode.mPrev;
  v3 = v1->m_AnimationGroupHandleList.mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->m_AnimationGroupHandleList.mNode.mPrev = &v1->m_AnimationGroupHandleList.mNode;
  v1->m_AnimationGroupHandleList.mNode.mNext = &v1->m_AnimationGroupHandleList.mNode;
}

// File Line: 167
// RVA: 0x492700
void __fastcall AnimationGroupHandleContainer::Add(AnimationGroupHandleContainer *this, const char *pAnimationGroupName, UFG::eAnimationPriorityEnum eAnimationPriority)
{
  AnimationGroupHandleContainer *v3; // rbx
  UFG::eAnimationPriorityEnum v4; // edi
  UFG::qSymbolUC *v5; // rax
  UFG::qSymbolUC result; // [rsp+48h] [rbp+20h]

  v3 = this;
  v4 = eAnimationPriority;
  v5 = UFG::qSymbolUC::create_from_string(&result, pAnimationGroupName);
  AnimationGroupHandleContainer::Add(v3, v5, v4);
}

// File Line: 174
// RVA: 0x2E79E0
void __fastcall AnimationGroupHandleContainer::Add(AnimationGroupHandleContainer *this, UFG::qSymbolUC *theAnimationGroupSymbol, UFG::eAnimationPriorityEnum eAnimationPriority)
{
  UFG::eAnimationPriorityEnum v3; // esi
  UFG::qSymbolUC *v4; // rbp
  AnimationGroupHandleContainer *v5; // rdi
  UFG::allocator::free_link *v6; // rax
  AnimationGroupHandle *v7; // rax
  AnimationGroupHandle *v8; // rbx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v9; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v10; // rax

  v3 = eAnimationPriority;
  v4 = theAnimationGroupSymbol;
  v5 = this;
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
  AnimationGroupHandle::Init(v8, v4, v3);
  v9 = (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)&v8->mPrev;
  v10 = v5->m_AnimationGroupHandleList.mNode.mPrev;
  v10->mNext = (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)&v8->mPrev;
  v9->mPrev = v10;
  v9->mNext = &v5->m_AnimationGroupHandleList.mNode;
  v5->m_AnimationGroupHandleList.mNode.mPrev = (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)&v8->mPrev;
}

// File Line: 184
// RVA: 0x4B62F0
char __fastcall AnimationGroupHandleContainer::Remove(AnimationGroupHandleContainer *this, UFG::qSymbolUC *theAnimationGroupSymbol)
{
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v2; // rbx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> **v3; // rcx
  AnimationGroupHandle *v4; // rbx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v6; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v7; // rax
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v8; // rdx

  v2 = this->m_AnimationGroupHandleList.mNode.mNext;
  v3 = &this[-1].m_AnimationGroupHandleList.mNode.mNext;
  v4 = (AnimationGroupHandle *)&v2[-1];
  if ( v4 == (AnimationGroupHandle *)v3 )
    return 0;
  while ( v4->m_AnimationGroupSymbol.mUID != theAnimationGroupSymbol->mUID )
  {
    v4 = (AnimationGroupHandle *)&v4->mNext[-1];
    if ( v4 == (AnimationGroupHandle *)v3 )
      return 0;
  }
  AnimationGroupHandle::Unbind(v4);
  v6 = v4->mPrev;
  v7 = v4->mNext;
  v8 = (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)&v4->mPrev;
  v6->mNext = v7;
  v7->mPrev = v6;
  v8->mPrev = v8;
  v8->mNext = v8;
  AnimationGroupHandle::~AnimationGroupHandle(v4);
  operator delete[](v4);
  return 1;
}

// File Line: 199
// RVA: 0x4B6370
char __fastcall AnimationGroupHandleContainer::Remove(AnimationGroupHandleContainer *this, const char *pAnimationGroupName)
{
  AnimationGroupHandleContainer *v2; // rbx
  UFG::qSymbolUC *v3; // rax
  UFG::qSymbolUC result; // [rsp+40h] [rbp+18h]

  v2 = this;
  v3 = UFG::qSymbolUC::create_from_string(&result, pAnimationGroupName);
  return AnimationGroupHandleContainer::Remove(v2, v3);
}

// File Line: 209
// RVA: 0x2FD360
_BOOL8 __fastcall AnimationGroupHandleContainer::Bind(AnimationGroupHandleContainer *this)
{
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> **v1; // rsi
  AnimationGroupHandleContainer *v2; // rbp
  AnimationGroupHandle *v3; // rbx
  bool v4; // di
  char v5; // al

  v1 = &this[-1].m_AnimationGroupHandleList.mNode.mNext;
  v2 = this;
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
      v3 = (AnimationGroupHandle *)&v3->mNext[-1];
    }
    while ( v3 != (AnimationGroupHandle *)v1 );
    v2->m_bHasBeenBound = 1;
  }
  return v4;
}

// File Line: 224
// RVA: 0x3038E0
void __fastcall AnimationGroupHandleContainer::Unbind(AnimationGroupHandleContainer *this)
{
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> **v1; // rsi
  AnimationGroupHandleContainer *v2; // rdi
  AnimationGroupHandle *v3; // rbx

  v1 = &this[-1].m_AnimationGroupHandleList.mNode.mNext;
  v2 = this;
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
      v3 = (AnimationGroupHandle *)&v3->mNext[-1];
    }
    while ( v3 != (AnimationGroupHandle *)v1 );
    v2->m_bHasBeenBound = 0;
  }
}

// File Line: 310
// RVA: 0x58B800
void __fastcall AnimationGroupHandleContainer::SetAnimationPriority(AnimationGroupHandleContainer *this, UFG::eAnimationPriorityEnum eAnimationPriority, unsigned __int16 subPriority)
{
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> **v3; // rdi
  unsigned __int16 v4; // si
  AnimationGroupHandle *v5; // rbx
  UFG::eAnimationPriorityEnum v6; // ebp

  v3 = &this[-1].m_AnimationGroupHandleList.mNode.mNext;
  v4 = subPriority;
  v5 = (AnimationGroupHandle *)&this->m_AnimationGroupHandleList.mNode.mNext[-1];
  v6 = eAnimationPriority;
  if ( v5 != (AnimationGroupHandle *)&this[-1].m_AnimationGroupHandleList.mNode.mNext )
  {
    do
    {
      AnimationGroupHandle::SetAnimationPriority(v5, v6, v4);
      v5 = (AnimationGroupHandle *)&v5->mNext[-1];
    }
    while ( v5 != (AnimationGroupHandle *)v3 );
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
  const char *result; // rax

  if ( this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    result = (char *)&this->mName + (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
  else
    result = BinString::sEmptyString;
  return result;
}

// File Line: 885
// RVA: 0x39E210
void __fastcall PoseCache::PoseCache(PoseCache *this)
{
  _QWORD *v1; // rdx
  UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *v2; // [rsp+48h] [rbp+10h]
  UFG::qList<PoseCacheNode,PoseCacheNode,1,0> *v3; // [rsp+48h] [rbp+10h]

  v2 = &this->mCachedDataTree;
  *(_OWORD *)&v2->mTree.mRoot.mParent = 0ui64;
  v2->mTree.mRoot.mChild[1] = 0i64;
  v1 = &this->mCachedDataTree.mTree.mNULL.mParent;
  *v1 = 0i64;
  v1[1] = 0i64;
  v1[2] = 0i64;
  *v1 = (unsigned __int64)&this->mCachedDataTree.mTree.mNULL | (_QWORD)this->mCachedDataTree.mTree.mNULL.mParent & 1;
  v2->mTree.mNULL.mChild[0] = &v2->mTree.mNULL;
  v2->mTree.mNULL.mChild[1] = &v2->mTree.mNULL;
  *v1 &= 0xFFFFFFFFFFFFFFFEui64;
  v2->mTree.mNULL.mUID = 0i64;
  v2->mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&v2->mTree.mNULL | (_QWORD)v2->mTree.mRoot.mParent & 1);
  v2->mTree.mRoot.mChild[0] = &v2->mTree.mNULL;
  v2->mTree.mRoot.mChild[1] = &v2->mTree.mNULL;
  v2->mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((_QWORD)v2->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
  v2->mTree.mRoot.mUID = -1i64;
  v2->mTree.mCount = 0;
  v3 = &this->mCachedDataList;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  UFG::qMemoryPool::qMemoryPool(&this->mCachedDataPool);
}


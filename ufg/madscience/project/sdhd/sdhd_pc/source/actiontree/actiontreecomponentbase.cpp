// File Line: 50
// RVA: 0x297320
void UFG::ActionTreeComponentBase::Init(void)
{
  unsigned int (*v0)[11]; // rax
  __int64 v1; // rcx

  v0 = UFG::ActionTreeComponentBase::s_NumValueUIDs;
  v1 = 2i64;
  do
  {
    *(_QWORD *)v0 = 0i64;
    *(_QWORD *)&(*v0)[2] = 0i64;
    *(_QWORD *)&(*v0)[4] = 0i64;
    v0 = (unsigned int (*)[11])((char *)v0 + 64);
    *(_QWORD *)&(*v0)[-10] = 0i64;
    *(_QWORD *)&(*v0)[-8] = 0i64;
    *(_QWORD *)&(*v0)[-6] = 0i64;
    *(_QWORD *)&(*v0)[-4] = 0i64;
    *(_QWORD *)&(*v0)[-2] = 0i64;
    --v1;
  }
  while ( v1 );
  *(_QWORD *)v0 = 0i64;
  *(_QWORD *)&(*v0)[2] = 0i64;
  *(_QWORD *)&(*v0)[4] = 0i64;
  *(_QWORD *)&(*v0)[6] = 0i64;
  *(_QWORD *)&(*v0)[8] = 0i64;
  *(_QWORD *)&(*v0)[10] = 0i64;
}

// File Line: 61
// RVA: 0x296C20
void UFG::ActionTreeComponentBase::BeginDeferredResolve(void)
{
  UFG::ActionTreeComponentBase::s_HasResolved = 0;
}

// File Line: 67
// RVA: 0x297110
void UFG::ActionTreeComponentBase::EndDeferredResolve(void)
{
  UFG::ActionTreeComponentBase::s_HasResolved = 1;
}

// File Line: 72
// RVA: 0x296C30
void __fastcall UFG::ActionTreeComponentBase::BeginResolvingActionTreeType(UFG::eActionTreeType action_tree_type)
{
  UFG::ActionTreeComponentBase::s_CurrentlyResolvingActionTreeType = action_tree_type;
}

// File Line: 80
// RVA: 0x297120
void __fastcall UFG::ActionTreeComponentBase::EndResolvingActionTreeType(UFG::eActionTreeType action_tree_type)
{
  unsigned int *v1; // rax

  if ( action_tree_type )
  {
    v1 = UFG::ActionTreeComponentBase::s_NumValueUIDs[action_tree_type];
    *(_QWORD *)v1 = 0i64;
    *((_QWORD *)v1 + 1) = 0i64;
    *((_QWORD *)v1 + 2) = 0i64;
    *((_QWORD *)v1 + 3) = 0i64;
    *((_QWORD *)v1 + 4) = 0i64;
    UFG::ActionTreeComponentBase::s_CurrentlyResolvingActionTreeType = eACTION_TREE_TYPE_NONE;
    v1[10] = 0;
  }
  else
  {
    UFG::ActionTreeComponentBase::s_CurrentlyResolvingActionTreeType = eACTION_TREE_TYPE_NONE;
  }
}

// File Line: 96
// RVA: 0x2972A0
__int64 __fastcall UFG::ActionTreeComponentBase::GetNumValueUIDs(
        UFG::eActionTreeType action_tree_type,
        UFG::eActionTreeMemoryElementType memory_element_type)
{
  return UFG::ActionTreeComponentBase::s_NumValueUIDs[action_tree_type][memory_element_type];
}

// File Line: 101
// RVA: 0x295600
void __fastcall UFG::ActionTreeComponentBase::ActionTreeComponentBase(
        UFG::ActionTreeComponentBase *this,
        UFG::eActionTreeType eType)
{
  char v3; // cl

  this->vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::ActionTreeComponentBase::`vftable;
  this->mActionTreeMemoryDataStructs.mTree.mRoot.mParent = 0i64;
  this->mActionTreeMemoryDataStructs.mTree.mRoot.8 = 0ui64;
  this->mActionTreeMemoryDataStructs.mTree.mNULL.mParent = 0i64;
  this->mActionTreeMemoryDataStructs.mTree.mNULL.8 = 0ui64;
  this->mActionTreeMemoryDataStructs.mTree.mNULL.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&this->mActionTreeMemoryDataStructs.mTree.mNULL | (__int64)this->mActionTreeMemoryDataStructs.mTree.mNULL.mParent & 1);
  this->mActionTreeMemoryDataStructs.mTree.mNULL.mChild[0] = &this->mActionTreeMemoryDataStructs.mTree.mNULL;
  this->mActionTreeMemoryDataStructs.mTree.mNULL.mChild[1] = &this->mActionTreeMemoryDataStructs.mTree.mNULL;
  this->mActionTreeMemoryDataStructs.mTree.mNULL.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)this->mActionTreeMemoryDataStructs.mTree.mNULL.mParent & ~1ui64);
  this->mActionTreeMemoryDataStructs.mTree.mNULL.mUID = 0i64;
  this->mActionTreeMemoryDataStructs.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&this->mActionTreeMemoryDataStructs.mTree.mNULL | (__int64)this->mActionTreeMemoryDataStructs.mTree.mRoot.mParent & 1);
  this->mActionTreeMemoryDataStructs.mTree.mRoot.mChild[0] = &this->mActionTreeMemoryDataStructs.mTree.mNULL;
  this->mActionTreeMemoryDataStructs.mTree.mRoot.mChild[1] = &this->mActionTreeMemoryDataStructs.mTree.mNULL;
  this->mActionTreeMemoryDataStructs.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)this->mActionTreeMemoryDataStructs.mTree.mRoot.mParent & ~1ui64);
  this->mActionTreeMemoryDataStructs.mTree.mRoot.mUID = -1i64;
  this->mActionTreeMemoryDataStructs.mTree.mCount = 0;
  v3 = once_7;
  if ( !once_7 )
    v3 = 1;
  once_7 = v3;
  this->m_eType = eType;
}

// File Line: 113
// RVA: 0x296190
void __fastcall UFG::ActionTreeComponentBase::~ActionTreeComponentBase(UFG::ActionTreeComponentBase *this)
{
  this->vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::ActionTreeComponentBase::`vftable;
  UFG::ActionTreeComponentBase::ResetMemory(this);
  UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::ActionTreeMemoryData,1>::~qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::ActionTreeMemoryData,1>(&this->mActionTreeMemoryDataStructs);
}

// File Line: 117
// RVA: 0x1493F20
__int64 dynamic_initializer_for__UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs__()
{
  UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs.mTree.mNULL.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs__);
}

// File Line: 118
// RVA: 0x1493F00
__int64 dynamic_initializer_for__UFG::ActionTreeComponentBase::msMemoryManageRecyclableActionTreeMemoryDataStructs__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ActionTreeComponentBase::msMemoryManageRecyclableActionTreeMemoryDataStructs__);
}

// File Line: 127
// RVA: 0x296A60
char __fastcall UFG::ActionTreeComponentBase::AllocateFor(
        UFG::ActionTreeComponentBase *this,
        ActionNodeRoot *action_node_root)
{
  UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::ActionTreeMemoryData,1> *p_mActionTreeMemoryDataStructs; // rax
  bool i; // zf
  UFG::qBaseNodeVariableRB<unsigned __int64> *j; // rcx
  UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *v8; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *k; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v10; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *mParent; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v12; // rax
  UFG::ActionTreeComponentBase::ActionTreeMemoryData *v13; // rdi
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *mPrev; // rcx
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *mNext; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::ActionTreeComponentBase::ActionTreeMemoryData *v17; // rax

  if ( !action_node_root )
    goto LABEL_30;
  p_mActionTreeMemoryDataStructs = &this->mActionTreeMemoryDataStructs;
  for ( i = &this->mActionTreeMemoryDataStructs == (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::ActionTreeMemoryData,1> *)&this->mActionTreeMemoryDataStructs.mTree.mNULL;
        !i;
        i = p_mActionTreeMemoryDataStructs == (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::ActionTreeMemoryData,1> *)&this->mActionTreeMemoryDataStructs.mTree.mNULL )
  {
    if ( p_mActionTreeMemoryDataStructs != &this->mActionTreeMemoryDataStructs
      && (ActionNodeRoot *)p_mActionTreeMemoryDataStructs->mTree.mRoot.mUID == action_node_root )
    {
      for ( j = p_mActionTreeMemoryDataStructs->mTree.mRoot.mChild[0]; j; j = j->mChild[0] )
      {
        if ( (ActionNodeRoot *)j->mUID != action_node_root )
          break;
        p_mActionTreeMemoryDataStructs = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::ActionTreeMemoryData,1> *)j;
      }
      if ( p_mActionTreeMemoryDataStructs )
        return 0;
      break;
    }
    if ( (unsigned __int64)action_node_root > p_mActionTreeMemoryDataStructs->mTree.mRoot.mUID )
      p_mActionTreeMemoryDataStructs = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::ActionTreeMemoryData,1> *)p_mActionTreeMemoryDataStructs->mTree.mRoot.mChild[1];
    else
      p_mActionTreeMemoryDataStructs = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::ActionTreeMemoryData,1> *)p_mActionTreeMemoryDataStructs->mTree.mRoot.mChild[0];
  }
  v8 = &UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs;
  while ( v8 == &UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs
       || (ActionNodeRoot *)v8->mTree.mRoot.mUID != action_node_root )
  {
    if ( (unsigned __int64)action_node_root > v8->mTree.mRoot.mUID )
      v8 = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)v8->mTree.mRoot.mChild[1];
    else
      v8 = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)v8->mTree.mRoot.mChild[0];
    if ( v8 == (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)&UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs.mTree.mNULL )
      goto LABEL_30;
  }
  for ( k = v8->mTree.mRoot.mChild[0]; k; k = k->mChild[0] )
  {
    if ( (ActionNodeRoot *)k->mUID != action_node_root )
      break;
    v8 = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)k;
  }
  if ( !v8 )
    goto LABEL_30;
  if ( (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)&v8->mTree.mNULL.mChild[0][-1] == v8 )
    goto LABEL_30;
  v10 = v8->mTree.mNULL.mChild[0];
  mParent = v10->mParent;
  v12 = v10->mChild[0];
  mParent->mChild[0] = v12;
  v12->mParent = mParent;
  v10->mParent = v10;
  v10->mChild[0] = v10;
  v13 = (UFG::ActionTreeComponentBase::ActionTreeMemoryData *)&v10[-1];
  if ( v10 == (UFG::qBaseNodeVariableRB<unsigned __int64> *)32 )
  {
LABEL_30:
    v16 = UFG::qMalloc(0x100ui64, "ActionTreeMemoryData", 0i64);
    if ( v16 )
    {
      UFG::ActionTreeComponentBase::ActionTreeMemoryData::ActionTreeMemoryData(
        (UFG::ActionTreeComponentBase::ActionTreeMemoryData *)v16,
        this,
        action_node_root);
      v13 = v17;
    }
    else
    {
      v13 = 0i64;
    }
    v13->mNode.mUID = (unsigned __int64)action_node_root;
  }
  else
  {
    mPrev = v13->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList>::mPrev;
    mNext = v13->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList>::mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v13->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList>::mPrev = &v13->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList>;
    v13->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList>::mNext = &v13->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList>;
    UFG::ActionTreeComponentBase::msTotalRecyclableBytes -= v13->mSize;
    UFG::ActionTreeComponentBase::ActionTreeMemoryData::Reset(v13);
  }
  UFG::qBaseTreeVariableRB<unsigned __int64>::Add(&this->mActionTreeMemoryDataStructs.mTree, &v13->mNode);
  return 1;
}

// File Line: 161
// RVA: 0x297A80
void __fastcall UFG::ActionTreeComponentBase::ResetMemory(UFG::ActionTreeComponentBase *this)
{
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNULL; // rdi
  UFG::qBaseNodeVariableRB<unsigned __int64> *v3; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *i; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v5; // rsi
  unsigned __int64 mUID; // rcx
  UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *v7; // rbx
  UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *j; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v10; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v11; // rax
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *mNext; // rax

  if ( this->mActionTreeMemoryDataStructs.mTree.mCount )
  {
    p_mNULL = &this->mActionTreeMemoryDataStructs.mTree.mNULL;
    do
    {
      v3 = this->mActionTreeMemoryDataStructs.mTree.mRoot.mChild[0];
      for ( i = v3->mChild[0]; i != p_mNULL; i = i->mChild[0] )
        v3 = i;
      v5 = 0i64;
      if ( v3 != p_mNULL )
        v5 = v3;
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&this->mActionTreeMemoryDataStructs.mTree, v5);
      mUID = v5->mUID;
      if ( !mUID )
        goto LABEL_22;
      v7 = &UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs;
      while ( v7 == &UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs
           || v7->mTree.mRoot.mUID != mUID )
      {
        if ( mUID > v7->mTree.mRoot.mUID )
          v7 = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)v7->mTree.mRoot.mChild[1];
        else
          v7 = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)v7->mTree.mRoot.mChild[0];
        if ( v7 == (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)&UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs.mTree.mNULL )
        {
          v7 = 0i64;
          goto LABEL_21;
        }
      }
      for ( j = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)v7->mTree.mRoot.mChild[0];
            j;
            j = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)j->mTree.mRoot.mChild[0] )
      {
        if ( j->mTree.mRoot.mUID != mUID )
          break;
        v7 = j;
      }
LABEL_21:
      if ( !v7 )
      {
LABEL_22:
        v9 = UFG::qMalloc(0x30ui64, "ActionTreeComponentBase::ResetMemory", 0i64);
        v7 = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)v9;
        if ( v9 )
        {
          v9->mNext = 0i64;
          v9[1].mNext = 0i64;
          v9[2].mNext = 0i64;
          v9[4].mNext = v9 + 4;
          v9[5].mNext = v9 + 4;
        }
        else
        {
          v7 = 0i64;
        }
        v7->mTree.mRoot.mUID = v5->mUID;
        UFG::qBaseTreeVariableRB<unsigned __int64>::Add(
          &UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs.mTree,
          &v7->mTree.mRoot);
      }
      v10 = &v7->mTree.mNULL;
      v11 = v10->mChild[0];
      v10->mChild[0] = v5 + 1;
      v5[1].mParent = v10;
      v5[1].mChild[0] = v11;
      v11->mParent = v5 + 1;
      mNext = UFG::ActionTreeComponentBase::msMemoryManageRecyclableActionTreeMemoryDataStructs.mNode.mNext;
      UFG::ActionTreeComponentBase::msMemoryManageRecyclableActionTreeMemoryDataStructs.mNode.mNext = (UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *)&v5[1].mChild1;
      v5[1].mChild[1] = (UFG::qBaseNodeVariableRB<unsigned __int64> *)&UFG::ActionTreeComponentBase::msMemoryManageRecyclableActionTreeMemoryDataStructs;
      v5[1].mUID = (unsigned __int64)mNext;
      mNext->mPrev = (UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *)&v5[1].mChild1;
      UFG::ActionTreeComponentBase::msTotalRecyclableBytes += LODWORD(v5[7].mUID);
    }
    while ( this->mActionTreeMemoryDataStructs.mTree.mCount );
  }
  UFG::ActionTreeComponentBase::ManageMemory();
}

// File Line: 184
// RVA: 0x2973B0
void UFG::ActionTreeComponentBase::ManageMemory(void)
{
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *mPrev; // rbx
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *v1; // rcx
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *mNext; // rax

  while ( UFG::ActionTreeComponentBase::msTotalRecyclableBytes > UFG::ActionTreeComponentBase::msMaxTotalRecyclableBytes )
  {
    mPrev = UFG::ActionTreeComponentBase::msMemoryManageRecyclableActionTreeMemoryDataStructs.mNode.mPrev;
    v1 = UFG::ActionTreeComponentBase::msMemoryManageRecyclableActionTreeMemoryDataStructs.mNode.mPrev->mPrev;
    mNext = UFG::ActionTreeComponentBase::msMemoryManageRecyclableActionTreeMemoryDataStructs.mNode.mPrev->mNext;
    v1->mNext = mNext;
    mNext->mPrev = v1;
    mPrev->mPrev = mPrev;
    mPrev->mNext = mPrev;
    UFG::ActionTreeComponentBase::msTotalRecyclableBytes -= LODWORD(mPrev[12].mNext);
    UFG::ActionTreeComponentBase::ActionTreeMemoryData::~ActionTreeMemoryData((UFG::ActionTreeComponentBase::ActionTreeMemoryData *)&mPrev[-3]);
    operator delete[](&mPrev[-3]);
  }
}

// File Line: 240
// RVA: 0x296E60
void UFG::ActionTreeComponentBase::DeleteAllMemory(void)
{
  UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *v0; // rcx
  UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *i; // rax
  UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *v2; // rsi
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNULL; // rdi
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *mParent; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v6; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v7; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v8; // rax

  while ( UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs.mTree.mCount )
  {
    v0 = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs.mTree.mRoot.mChild[0];
    for ( i = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs.mTree.mRoot.mChild[0]->mChild[0];
          i != (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)&UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs.mTree.mNULL;
          i = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)i->mTree.mRoot.mChild[0] )
    {
      v0 = i;
    }
    v2 = 0i64;
    if ( v0 != (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)&UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs.mTree.mNULL )
      v2 = v0;
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      &UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs.mTree,
      &v2->mTree.mRoot);
    p_mNULL = &v2->mTree.mNULL;
    while ( (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)&v2->mTree.mNULL.mChild[0][-1] != v2 )
    {
      v4 = v2->mTree.mNULL.mChild[0];
      mParent = v4->mParent;
      v6 = v4->mChild[0];
      mParent->mChild[0] = v6;
      v6->mParent = mParent;
      v4->mParent = v4;
      v4->mChild[0] = v4;
      UFG::ActionTreeComponentBase::msTotalRecyclableBytes -= LODWORD(v4[6].mUID);
      UFG::ActionTreeComponentBase::ActionTreeMemoryData::~ActionTreeMemoryData((UFG::ActionTreeComponentBase::ActionTreeMemoryData *)&v4[-1]);
      operator delete[](&v4[-1]);
    }
    if ( v2 )
    {
      UFG::qList<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree,1,0>::DeleteNodes((UFG::qList<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree,1,0> *)&v2->mTree.mNULL);
      v7 = p_mNULL->mParent;
      v8 = v2->mTree.mNULL.mChild[0];
      v7->mChild[0] = v8;
      v8->mParent = v7;
      p_mNULL->mParent = p_mNULL;
      v2->mTree.mNULL.mChild[0] = &v2->mTree.mNULL;
      operator delete[](v2);
    }
  }
}

// File Line: 258
// RVA: 0x2956B0
void __fastcall UFG::ActionTreeComponentBase::ActionTreeMemoryData::ActionTreeMemoryData(
        UFG::ActionTreeComponentBase::ActionTreeMemoryData *this,
        UFG::ActionTreeComponentBase *component,
        ActionNodeRoot *action_node_root)
{
  unsigned int v4; // ebp
  unsigned int v5; // r15d
  unsigned int v6; // edi
  unsigned int capacity; // edx
  unsigned int v8; // esi
  unsigned int v9; // edx
  unsigned int v10; // r14d
  unsigned int v11; // edi
  unsigned int v12; // edx
  unsigned int v13; // edx
  unsigned int v14; // r14d
  unsigned int v15; // edi
  unsigned int v16; // edx
  unsigned int v17; // edx
  unsigned int v18; // r12d
  UFG::allocator::free_link *v19; // rax
  char *v20; // rdi
  unsigned int i; // r9d
  unsigned int size; // ecx
  unsigned int v23; // r14d
  unsigned int v24; // edi
  unsigned int v25; // edi
  UFG::allocator::free_link *v26; // rax
  char *v27; // r15
  unsigned int v28; // r14d
  UFG::qArray<unsigned long,0> *p_m_pQSymbolArray; // r15
  unsigned int v30; // edi
  unsigned int v31; // edx
  unsigned int v32; // edx
  unsigned int v33; // r14d
  UFG::qArray<unsigned long,0> *p_m_pQSymbolUCArray; // r15
  unsigned int v35; // edi
  unsigned int v36; // edx
  unsigned int v37; // edx
  unsigned int v38; // r14d
  UFG::qArray<UFG::qSafePointer<UFG::SimObject,UFG::SimObject>,0> *p_m_pSimObjectPointerArray; // r15
  unsigned int v40; // edi
  unsigned int v41; // edx
  unsigned int v42; // edx
  unsigned int v43; // r14d
  UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0> *p_m_pSimComponentPointerArray; // r15
  unsigned int v45; // edi
  unsigned int v46; // edx
  unsigned int v47; // edx
  unsigned int v48; // r14d
  UFG::qArray<UFG::qSafePointer<UFG::GetInFormationNode,UFG::GetInFormationNode>,0> *p_m_pGetInFormationNodePointerArray; // r15
  unsigned int v50; // edi
  unsigned int v51; // edx
  unsigned int v52; // edx
  unsigned int v53; // r14d
  UFG::qArray<UFG::qSafePointer<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode>,0> *p_m_pGetInPedFormationNodePointerArray; // r15
  unsigned int v55; // edi
  unsigned int v56; // edx
  unsigned int v57; // edx
  unsigned int v58; // r14d
  UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0> *p_m_pHasAttackRequestNodePointerArray; // r15
  unsigned int v60; // edi
  unsigned int v61; // eax

  v4 = 0;
  this->mNode.mParent = 0i64;
  this->mNode.8 = 0ui64;
  this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree>::mPrev = &this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree>;
  this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree>::mNext = &this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree>;
  this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList>::mPrev = &this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList>;
  this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList>::mNext = &this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList>;
  this->m_pFloatArray.p = 0i64;
  *(_QWORD *)&this->m_pFloatArray.size = 0i64;
  this->m_pIntArray.p = 0i64;
  *(_QWORD *)&this->m_pIntArray.size = 0i64;
  this->m_pUInt64Array.p = 0i64;
  *(_QWORD *)&this->m_pUInt64Array.size = 0i64;
  this->m_pBoolArray.p = 0i64;
  *(_QWORD *)&this->m_pBoolArray.size = 0i64;
  this->m_pQSymbolArray.p = 0i64;
  *(_QWORD *)&this->m_pQSymbolArray.size = 0i64;
  this->m_pQSymbolUCArray.p = 0i64;
  *(_QWORD *)&this->m_pQSymbolUCArray.size = 0i64;
  this->m_pSimObjectPointerArray.p = 0i64;
  *(_QWORD *)&this->m_pSimObjectPointerArray.size = 0i64;
  this->m_pSimComponentPointerArray.p = 0i64;
  *(_QWORD *)&this->m_pSimComponentPointerArray.size = 0i64;
  this->m_pGetInFormationNodePointerArray.p = 0i64;
  *(_QWORD *)&this->m_pGetInFormationNodePointerArray.size = 0i64;
  this->m_pGetInPedFormationNodePointerArray.p = 0i64;
  *(_QWORD *)&this->m_pGetInPedFormationNodePointerArray.size = 0i64;
  this->m_pHasAttackRequestNodePointerArray.p = 0i64;
  *(_QWORD *)&this->m_pHasAttackRequestNodePointerArray.size = 0i64;
  if ( action_node_root )
  {
    this->m_pMyComponent = component;
    this->mSize = 256;
    v5 = action_node_root->m_NumNeededActionTreeComponentBaseValueUIDs[0];
    if ( v5 > this->m_pFloatArray.capacity )
      UFG::qArray<float,0>::Reallocate(&this->m_pFloatArray, v5, "ActionTreeMemory.float");
    v6 = v5 + this->m_pFloatArray.size;
    capacity = this->m_pFloatArray.capacity;
    v8 = 1;
    if ( v6 > capacity )
    {
      if ( capacity )
        v9 = 2 * capacity;
      else
        v9 = 1;
      for ( ; v9 < v6; v9 *= 2 )
        ;
      if ( v9 <= 4 )
        v9 = 4;
      if ( v9 - v6 > 0x10000 )
        v9 = v6 + 0x10000;
      UFG::qArray<float,0>::Reallocate(&this->m_pFloatArray, v9, "ActionTreeMemory.float");
    }
    this->m_pFloatArray.size = v6;
    this->mSize += 4 * v5;
    v10 = action_node_root->m_NumNeededActionTreeComponentBaseValueUIDs[1];
    if ( v10 > this->m_pIntArray.capacity )
      UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)&this->m_pIntArray, v10, "ActionTreeMemory.int32");
    v11 = v10 + this->m_pIntArray.size;
    v12 = this->m_pIntArray.capacity;
    if ( v11 > v12 )
    {
      if ( v12 )
        v13 = 2 * v12;
      else
        v13 = 1;
      for ( ; v13 < v11; v13 *= 2 )
        ;
      if ( v13 <= 4 )
        v13 = 4;
      if ( v13 - v11 > 0x10000 )
        v13 = v11 + 0x10000;
      UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)&this->m_pIntArray, v13, "ActionTreeMemory.int32");
    }
    this->m_pIntArray.size = v11;
    this->mSize += 4 * v10;
    v14 = action_node_root->m_NumNeededActionTreeComponentBaseValueUIDs[2];
    if ( v14 > this->m_pUInt64Array.capacity )
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_pUInt64Array,
        v14,
        "ActionTreeMemory.uint64");
    v15 = v14 + this->m_pUInt64Array.size;
    v16 = this->m_pUInt64Array.capacity;
    if ( v15 > v16 )
    {
      if ( v16 )
        v17 = 2 * v16;
      else
        v17 = 1;
      for ( ; v17 < v15; v17 *= 2 )
        ;
      if ( v17 <= 2 )
        v17 = 2;
      if ( v17 - v15 > 0x10000 )
        v17 = v15 + 0x10000;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_pUInt64Array,
        v17,
        "ActionTreeMemory.uint64");
    }
    this->m_pUInt64Array.size = v15;
    this->mSize += 8 * v14;
    v18 = action_node_root->m_NumNeededActionTreeComponentBaseValueUIDs[3];
    if ( v18 > this->m_pBoolArray.capacity && v18 != this->m_pBoolArray.size )
    {
      v19 = UFG::qMalloc(v18, "ActionTreeMemory.uint8", 0i64);
      v20 = (char *)v19;
      if ( this->m_pBoolArray.p )
      {
        for ( i = 0; i < this->m_pBoolArray.size; ++i )
          *((_BYTE *)&v19->mNext + i) = this->m_pBoolArray.p[i];
        operator delete[](this->m_pBoolArray.p);
      }
      this->m_pBoolArray.p = v20;
      this->m_pBoolArray.capacity = v18;
    }
    size = this->m_pBoolArray.size;
    v23 = size + v18;
    v24 = this->m_pBoolArray.capacity;
    if ( size + v18 > v24 )
    {
      if ( v24 )
        v25 = 2 * v24;
      else
        v25 = 1;
      for ( ; v25 < v23; v25 *= 2 )
        ;
      if ( v25 <= 0x10 )
        v25 = 16;
      if ( v25 - v23 > 0x10000 )
        v25 = v23 + 0x10000;
      if ( v25 != size )
      {
        v26 = UFG::qMalloc(v25, "ActionTreeMemory.uint8", 0i64);
        v27 = (char *)v26;
        if ( this->m_pBoolArray.p )
        {
          if ( this->m_pBoolArray.size )
          {
            do
            {
              *((_BYTE *)&v26->mNext + v4) = this->m_pBoolArray.p[v4];
              ++v4;
            }
            while ( v4 < this->m_pBoolArray.size );
          }
          operator delete[](this->m_pBoolArray.p);
        }
        this->m_pBoolArray.p = v27;
        this->m_pBoolArray.capacity = v25;
      }
    }
    this->m_pBoolArray.size = v23;
    this->mSize += v18;
    v28 = action_node_root->m_NumNeededActionTreeComponentBaseValueUIDs[4];
    p_m_pQSymbolArray = &this->m_pQSymbolArray;
    if ( v28 > this->m_pQSymbolArray.capacity )
      UFG::qArray<long,0>::Reallocate(&this->m_pQSymbolArray, v28, "ActionTreeMemory.uint32");
    v30 = v28 + p_m_pQSymbolArray->size;
    v31 = this->m_pQSymbolArray.capacity;
    if ( v30 > v31 )
    {
      if ( v31 )
        v32 = 2 * v31;
      else
        v32 = 1;
      for ( ; v32 < v30; v32 *= 2 )
        ;
      if ( v32 <= 4 )
        v32 = 4;
      if ( v32 - v30 > 0x10000 )
        v32 = v30 + 0x10000;
      UFG::qArray<long,0>::Reallocate(&this->m_pQSymbolArray, v32, "ActionTreeMemory.uint32");
    }
    p_m_pQSymbolArray->size = v30;
    this->mSize += 4 * v28;
    v33 = action_node_root->m_NumNeededActionTreeComponentBaseValueUIDs[5];
    p_m_pQSymbolUCArray = &this->m_pQSymbolUCArray;
    if ( v33 > this->m_pQSymbolUCArray.capacity )
      UFG::qArray<long,0>::Reallocate(&this->m_pQSymbolUCArray, v33, "ActionTreeMemory.uint32");
    v35 = v33 + p_m_pQSymbolUCArray->size;
    v36 = this->m_pQSymbolUCArray.capacity;
    if ( v35 > v36 )
    {
      if ( v36 )
        v37 = 2 * v36;
      else
        v37 = 1;
      for ( ; v37 < v35; v37 *= 2 )
        ;
      if ( v37 <= 4 )
        v37 = 4;
      if ( v37 - v35 > 0x10000 )
        v37 = v35 + 0x10000;
      UFG::qArray<long,0>::Reallocate(&this->m_pQSymbolUCArray, v37, "ActionTreeMemory.uint32");
    }
    p_m_pQSymbolUCArray->size = v35;
    this->mSize += 4 * v33;
    v38 = action_node_root->m_NumNeededActionTreeComponentBaseValueUIDs[6];
    p_m_pSimObjectPointerArray = &this->m_pSimObjectPointerArray;
    if ( v38 > this->m_pSimObjectPointerArray.capacity )
      UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
        (UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *)&this->m_pSimObjectPointerArray,
        v38,
        "ActionTreeMemory.SimObjectSafePtr");
    v40 = v38 + p_m_pSimObjectPointerArray->size;
    v41 = this->m_pSimObjectPointerArray.capacity;
    if ( v40 > v41 )
    {
      if ( v41 )
        v42 = 2 * v41;
      else
        v42 = 1;
      for ( ; v42 < v40; v42 *= 2 )
        ;
      if ( v42 - v40 > 0x10000 )
        v42 = v40 + 0x10000;
      UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
        (UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *)&this->m_pSimObjectPointerArray,
        v42,
        "ActionTreeMemory.SimObjectSafePtr");
    }
    p_m_pSimObjectPointerArray->size = v40;
    this->mSize += 16 * v38;
    v43 = action_node_root->m_NumNeededActionTreeComponentBaseValueUIDs[7];
    p_m_pSimComponentPointerArray = &this->m_pSimComponentPointerArray;
    if ( v43 > this->m_pSimComponentPointerArray.capacity )
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(
        &this->m_pSimComponentPointerArray,
        v43,
        "ActionTreeMemory.SimComponentPtr");
    v45 = v43 + p_m_pSimComponentPointerArray->size;
    v46 = this->m_pSimComponentPointerArray.capacity;
    if ( v45 > v46 )
    {
      if ( v46 )
        v47 = 2 * v46;
      else
        v47 = 1;
      for ( ; v47 < v45; v47 *= 2 )
        ;
      if ( v47 - v45 > 0x10000 )
        v47 = v45 + 0x10000;
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(
        &this->m_pSimComponentPointerArray,
        v47,
        "ActionTreeMemory.SimComponentPtr");
    }
    p_m_pSimComponentPointerArray->size = v45;
    this->mSize += 16 * v43;
    v48 = action_node_root->m_NumNeededActionTreeComponentBaseValueUIDs[8];
    p_m_pGetInFormationNodePointerArray = &this->m_pGetInFormationNodePointerArray;
    if ( v48 > this->m_pGetInFormationNodePointerArray.capacity )
      UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
        (UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *)&this->m_pGetInFormationNodePointerArray,
        v48,
        "ActionTreeMemory.GetInFormationNodePtr");
    v50 = v48 + p_m_pGetInFormationNodePointerArray->size;
    v51 = this->m_pGetInFormationNodePointerArray.capacity;
    if ( v50 > v51 )
    {
      if ( v51 )
        v52 = 2 * v51;
      else
        v52 = 1;
      for ( ; v52 < v50; v52 *= 2 )
        ;
      if ( v52 - v50 > 0x10000 )
        v52 = v50 + 0x10000;
      UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
        (UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *)&this->m_pGetInFormationNodePointerArray,
        v52,
        "ActionTreeMemory.GetInFormationNodePtr");
    }
    p_m_pGetInFormationNodePointerArray->size = v50;
    this->mSize += 16 * v48;
    v53 = action_node_root->m_NumNeededActionTreeComponentBaseValueUIDs[9];
    p_m_pGetInPedFormationNodePointerArray = &this->m_pGetInPedFormationNodePointerArray;
    if ( v53 > this->m_pGetInPedFormationNodePointerArray.capacity )
      UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
        (UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *)&this->m_pGetInPedFormationNodePointerArray,
        v53,
        "ActionTreeMemory.GetInPedFormationNodePtr");
    v55 = v53 + p_m_pGetInPedFormationNodePointerArray->size;
    v56 = this->m_pGetInPedFormationNodePointerArray.capacity;
    if ( v55 > v56 )
    {
      if ( v56 )
        v57 = 2 * v56;
      else
        v57 = 1;
      for ( ; v57 < v55; v57 *= 2 )
        ;
      if ( v57 - v55 > 0x10000 )
        v57 = v55 + 0x10000;
      UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
        (UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *)&this->m_pGetInPedFormationNodePointerArray,
        v57,
        "ActionTreeMemory.GetInPedFormationNodePtr");
    }
    p_m_pGetInPedFormationNodePointerArray->size = v55;
    this->mSize += 16 * v53;
    v58 = action_node_root->m_NumNeededActionTreeComponentBaseValueUIDs[10];
    p_m_pHasAttackRequestNodePointerArray = &this->m_pHasAttackRequestNodePointerArray;
    if ( v58 > this->m_pHasAttackRequestNodePointerArray.capacity )
      UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
        (UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *)&this->m_pHasAttackRequestNodePointerArray,
        v58,
        "ActionTreeMemory.HasAttackRequestNodePtr");
    v60 = v58 + p_m_pHasAttackRequestNodePointerArray->size;
    v61 = this->m_pHasAttackRequestNodePointerArray.capacity;
    if ( v60 > v61 )
    {
      if ( v61 )
        v8 = 2 * v61;
      for ( ; v8 < v60; v8 *= 2 )
        ;
      if ( v8 - v60 > 0x10000 )
        v8 = v60 + 0x10000;
      UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
        (UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *)&this->m_pHasAttackRequestNodePointerArray,
        v8,
        "ActionTreeMemory.HasAttackRequestNodePtr");
    }
    p_m_pHasAttackRequestNodePointerArray->size = v60;
    this->mSize += 16 * v58;
    this->mNode.mUID = (unsigned __int64)action_node_root;
    UFG::ActionTreeComponentBase::ActionTreeMemoryData::Reset(this);
  }
}root;
    UFG::ActionTreeComponentBase::ActionTreeMemoryData::Reset(this);
  }
}

// File Line: 332
// RVA: 0x297810
void __fastcall UFG::ActionTreeComponentBase::ActionTreeMemoryData::Reset(
        UFG::ActionTreeComponentBase::ActionTreeMemoryData *this)
{
  _DWORD *mUID; // rax
  int v3; // esi
  int v4; // ebp
  unsigned int v5; // r14d
  int v6; // r15d
  int v7; // r12d
  __int64 v8; // rdi
  __int64 v9; // r13
  __int64 v10; // r8
  __int64 v11; // r9
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  __int64 v15; // r8
  __int64 v16; // r9
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  __int64 v20; // r8
  __int64 v21; // r9
  UFG::qSafePointer<UFG::GetInFormationNode,UFG::GetInFormationNode> *v22; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v24; // rax
  __int64 v25; // r8
  __int64 v26; // r9
  UFG::qSafePointer<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *v27; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v29; // rax
  __int64 v30; // r8
  __int64 v31; // r9
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v32; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v33; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *v34; // rax
  unsigned int v35; // [rsp+60h] [rbp+8h]
  unsigned int v36; // [rsp+68h] [rbp+10h]
  unsigned int v37; // [rsp+70h] [rbp+18h]

  mUID = (_DWORD *)this->mNode.mUID;
  v3 = mUID[49];
  v4 = mUID[50];
  v5 = mUID[51];
  v6 = mUID[52];
  v7 = mUID[53];
  v8 = (unsigned int)mUID[54];
  v9 = (unsigned int)mUID[55];
  v35 = mUID[56];
  v37 = mUID[58];
  v36 = mUID[57];
  if ( this->m_pFloatArray.size )
    UFG::qMemSet(this->m_pFloatArray.p, -1, 4 * mUID[48]);
  if ( this->m_pIntArray.size )
    UFG::qMemSet(this->m_pIntArray.p, 0, 4 * v3);
  if ( this->m_pUInt64Array.size )
    UFG::qMemSet(this->m_pUInt64Array.p, 0, 8 * v4);
  if ( this->m_pBoolArray.size )
    UFG::qMemSet(this->m_pBoolArray.p, 0, v5);
  if ( this->m_pQSymbolArray.size )
    UFG::qMemSet(this->m_pQSymbolArray.p, -1, 4 * v6);
  if ( this->m_pQSymbolUCArray.size )
    UFG::qMemSet(this->m_pQSymbolUCArray.p, -1, 4 * v7);
  if ( (_DWORD)v8 )
  {
    v10 = 0i64;
    v11 = v8;
    do
    {
      v12 = &this->m_pSimObjectPointerArray.p[v10];
      if ( v12->m_pPointer )
      {
        mPrev = v12->mPrev;
        mNext = v12->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        v12->mPrev = v12;
        v12->mNext = v12;
      }
      ++v10;
      v12->m_pPointer = 0i64;
      --v11;
    }
    while ( v11 );
  }
  if ( (_DWORD)v9 )
  {
    v15 = 0i64;
    v16 = v9;
    do
    {
      v17 = &this->m_pSimComponentPointerArray.p[v15];
      if ( v17->m_pPointer )
      {
        v18 = v17->mPrev;
        v19 = v17->mNext;
        v18->mNext = v19;
        v19->mPrev = v18;
        v17->mPrev = v17;
        v17->mNext = v17;
      }
      ++v15;
      v17->m_pPointer = 0i64;
      --v16;
    }
    while ( v16 );
  }
  if ( v35 )
  {
    v20 = 0i64;
    v21 = v35;
    do
    {
      v22 = &this->m_pGetInFormationNodePointerArray.p[v20];
      if ( v22->m_pPointer )
      {
        v23 = v22->mPrev;
        v24 = v22->mNext;
        v23->mNext = v24;
        v24->mPrev = v23;
        v22->mPrev = v22;
        v22->mNext = v22;
      }
      ++v20;
      v22->m_pPointer = 0i64;
      --v21;
    }
    while ( v21 );
  }
  if ( v36 )
  {
    v25 = 0i64;
    v26 = v36;
    do
    {
      v27 = &this->m_pGetInPedFormationNodePointerArray.p[v25];
      if ( v27->m_pPointer )
      {
        v28 = v27->mPrev;
        v29 = v27->mNext;
        v28->mNext = v29;
        v29->mPrev = v28;
        v27->mPrev = v27;
        v27->mNext = v27;
      }
      ++v25;
      v27->m_pPointer = 0i64;
      --v26;
    }
    while ( v26 );
  }
  if ( v37 )
  {
    v30 = 0i64;
    v31 = v37;
    do
    {
      v32 = &this->m_pHasAttackRequestNodePointerArray.p[v30];
      if ( v32->m_pPointer )
      {
        v33 = v32->mPrev;
        v34 = v32->mNext;
        v33->mNext = v34;
        v34->mPrev = v33;
        v32->mPrev = v32;
        v32->mNext = v32;
      }
      ++v30;
      v32->m_pPointer = 0i64;
      --v31;
    }
    while ( v31 );
  }
}

// File Line: 387
// RVA: 0x2961D0
void __fastcall UFG::ActionTreeComponentBase::ActionTreeMemoryData::~ActionTreeMemoryData(
        UFG::ActionTreeComponentBase::ActionTreeMemoryData *this)
{
  float *p; // rcx
  int *v3; // rcx
  unsigned __int64 *v4; // rcx
  char *v5; // rcx
  unsigned int *v6; // rcx
  unsigned int *v7; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v8; // rcx
  UFG::SimObject **p_m_pPointer; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v10; // rcx
  UFG::SimComponent **v11; // rbx
  UFG::qSafePointer<UFG::GetInFormationNode,UFG::GetInFormationNode> *v12; // rcx
  UFG::GetInFormationNode **v13; // rbx
  UFG::qSafePointer<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *v14; // rcx
  UFG::GetInPedFormationNode **v15; // rbx
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v16; // rcx
  UFG::HasAttackRequestNode **v17; // rbx
  UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode> *v18; // rcx
  UFG::HasAttackRequestNode **v19; // rbx
  UFG::qSafePointer<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *v20; // rcx
  UFG::GetInPedFormationNode **v21; // rbx
  UFG::qSafePointer<UFG::GetInFormationNode,UFG::GetInFormationNode> *v22; // rcx
  UFG::GetInFormationNode **v23; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v24; // rcx
  UFG::SimComponent **v25; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v26; // rcx
  UFG::SimObject **v27; // rbx
  unsigned int *v28; // rcx
  unsigned int *v29; // rcx
  char *v30; // rcx
  unsigned __int64 *v31; // rcx
  int *v32; // rcx
  float *v33; // rcx
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *mPrev; // rcx
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *mNext; // rax
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree> *v36; // rcx
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree> *v37; // rax

  this->m_pMyComponent = 0i64;
  p = this->m_pFloatArray.p;
  if ( p )
    operator delete[](p);
  this->m_pFloatArray.p = 0i64;
  *(_QWORD *)&this->m_pFloatArray.size = 0i64;
  v3 = this->m_pIntArray.p;
  if ( v3 )
    operator delete[](v3);
  this->m_pIntArray.p = 0i64;
  *(_QWORD *)&this->m_pIntArray.size = 0i64;
  v4 = this->m_pUInt64Array.p;
  if ( v4 )
    operator delete[](v4);
  this->m_pUInt64Array.p = 0i64;
  *(_QWORD *)&this->m_pUInt64Array.size = 0i64;
  v5 = this->m_pBoolArray.p;
  if ( v5 )
    operator delete[](v5);
  this->m_pBoolArray.p = 0i64;
  *(_QWORD *)&this->m_pBoolArray.size = 0i64;
  v6 = this->m_pQSymbolArray.p;
  if ( v6 )
    operator delete[](v6);
  this->m_pQSymbolArray.p = 0i64;
  *(_QWORD *)&this->m_pQSymbolArray.size = 0i64;
  v7 = this->m_pQSymbolUCArray.p;
  if ( v7 )
    operator delete[](v7);
  this->m_pQSymbolUCArray.p = 0i64;
  *(_QWORD *)&this->m_pQSymbolUCArray.size = 0i64;
  v8 = this->m_pSimObjectPointerArray.p;
  if ( v8 )
  {
    p_m_pPointer = &v8[-1].m_pPointer;
    `eh vector destructor iterator(
      v8,
      0x18ui64,
      (int)v8[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](p_m_pPointer);
  }
  this->m_pSimObjectPointerArray.p = 0i64;
  *(_QWORD *)&this->m_pSimObjectPointerArray.size = 0i64;
  v10 = this->m_pSimComponentPointerArray.p;
  if ( v10 )
  {
    v11 = &v10[-1].m_pPointer;
    `eh vector destructor iterator(
      v10,
      0x18ui64,
      (int)v10[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
    operator delete[](v11);
  }
  this->m_pSimComponentPointerArray.p = 0i64;
  *(_QWORD *)&this->m_pSimComponentPointerArray.size = 0i64;
  v12 = this->m_pGetInFormationNodePointerArray.p;
  if ( v12 )
  {
    v13 = &v12[-1].m_pPointer;
    `eh vector destructor iterator(
      v12,
      0x18ui64,
      (int)v12[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v13);
  }
  this->m_pGetInFormationNodePointerArray.p = 0i64;
  *(_QWORD *)&this->m_pGetInFormationNodePointerArray.size = 0i64;
  v14 = this->m_pGetInPedFormationNodePointerArray.p;
  if ( v14 )
  {
    v15 = &v14[-1].m_pPointer;
    `eh vector destructor iterator(
      v14,
      0x18ui64,
      (int)v14[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v15);
  }
  this->m_pGetInPedFormationNodePointerArray.p = 0i64;
  *(_QWORD *)&this->m_pGetInPedFormationNodePointerArray.size = 0i64;
  v16 = this->m_pHasAttackRequestNodePointerArray.p;
  if ( v16 )
  {
    v17 = &v16[-1].m_pPointer;
    `eh vector destructor iterator(
      v16,
      0x18ui64,
      (int)v16[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v17);
  }
  this->m_pHasAttackRequestNodePointerArray.p = 0i64;
  *(_QWORD *)&this->m_pHasAttackRequestNodePointerArray.size = 0i64;
  v18 = this->m_pHasAttackRequestNodePointerArray.p;
  if ( v18 )
  {
    v19 = &v18[-1].m_pPointer;
    `eh vector destructor iterator(
      v18,
      0x18ui64,
      (int)v18[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v19);
  }
  this->m_pHasAttackRequestNodePointerArray.p = 0i64;
  *(_QWORD *)&this->m_pHasAttackRequestNodePointerArray.size = 0i64;
  v20 = this->m_pGetInPedFormationNodePointerArray.p;
  if ( v20 )
  {
    v21 = &v20[-1].m_pPointer;
    `eh vector destructor iterator(
      v20,
      0x18ui64,
      (int)v20[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v21);
  }
  this->m_pGetInPedFormationNodePointerArray.p = 0i64;
  *(_QWORD *)&this->m_pGetInPedFormationNodePointerArray.size = 0i64;
  v22 = this->m_pGetInFormationNodePointerArray.p;
  if ( v22 )
  {
    v23 = &v22[-1].m_pPointer;
    `eh vector destructor iterator(
      v22,
      0x18ui64,
      (int)v22[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v23);
  }
  this->m_pGetInFormationNodePointerArray.p = 0i64;
  *(_QWORD *)&this->m_pGetInFormationNodePointerArray.size = 0i64;
  v24 = this->m_pSimComponentPointerArray.p;
  if ( v24 )
  {
    v25 = &v24[-1].m_pPointer;
    `eh vector destructor iterator(
      v24,
      0x18ui64,
      (int)v24[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
    operator delete[](v25);
  }
  this->m_pSimComponentPointerArray.p = 0i64;
  *(_QWORD *)&this->m_pSimComponentPointerArray.size = 0i64;
  v26 = this->m_pSimObjectPointerArray.p;
  if ( v26 )
  {
    v27 = &v26[-1].m_pPointer;
    `eh vector destructor iterator(
      v26,
      0x18ui64,
      (int)v26[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v27);
  }
  this->m_pSimObjectPointerArray.p = 0i64;
  *(_QWORD *)&this->m_pSimObjectPointerArray.size = 0i64;
  v28 = this->m_pQSymbolUCArray.p;
  if ( v28 )
    operator delete[](v28);
  this->m_pQSymbolUCArray.p = 0i64;
  *(_QWORD *)&this->m_pQSymbolUCArray.size = 0i64;
  v29 = this->m_pQSymbolArray.p;
  if ( v29 )
    operator delete[](v29);
  this->m_pQSymbolArray.p = 0i64;
  *(_QWORD *)&this->m_pQSymbolArray.size = 0i64;
  v30 = this->m_pBoolArray.p;
  if ( v30 )
    operator delete[](v30);
  this->m_pBoolArray.p = 0i64;
  *(_QWORD *)&this->m_pBoolArray.size = 0i64;
  v31 = this->m_pUInt64Array.p;
  if ( v31 )
    operator delete[](v31);
  this->m_pUInt64Array.p = 0i64;
  *(_QWORD *)&this->m_pUInt64Array.size = 0i64;
  v32 = this->m_pIntArray.p;
  if ( v32 )
    operator delete[](v32);
  this->m_pIntArray.p = 0i64;
  *(_QWORD *)&this->m_pIntArray.size = 0i64;
  v33 = this->m_pFloatArray.p;
  if ( v33 )
    operator delete[](v33);
  this->m_pFloatArray.p = 0i64;
  *(_QWORD *)&this->m_pFloatArray.size = 0i64;
  mPrev = this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList>::mPrev;
  mNext = this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList>::mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList>::mPrev = &this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList>;
  this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList>::mNext = &this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList>;
  v36 = this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree>::mPrev;
  v37 = this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree>::mNext;
  v36->mNext = v37;
  v37->mPrev = v36;
  this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree>::mPrev = &this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree>;
  this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree>::mNext = &this->UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree>;
}

// File Line: 428
// RVA: 0x295590
char __fastcall UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(
        UFG::ActionTreeComponentBase *this,
        UFG::ActionTreeComponentBase *baseComponent,
        ActionNodeRoot *currentRoot,
        char value_uid)
{
  int v5; // ebx
  Render::PersistentSkinningCacheNode *v6; // rax
  __int64 v7; // rcx

  v5 = (int)currentRoot;
  if ( !this )
    return 0;
  if ( !baseComponent )
    return 0;
  v6 = Render::PersistentSkinningCache::Find(
         (Render::PersistentSkinningCache *)&this->mActionTreeMemoryDataStructs,
         (unsigned __int64)baseComponent);
  if ( !v6 )
    return 0;
  v7 = (unsigned int)(v5 - 400000);
  if ( (unsigned int)v7 >= LODWORD(v6[1].mCachedDataPtr) )
    return 0;
  *(_BYTE *)(v7 + v6[1].mSize) = (value_uid != 0) - 16;
  return 1;
}

// File Line: 454
// RVA: 0x295120
bool __fastcall UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::GetInPedFormationNode *>(
        UFG::ActionTreeComponentBase *this,
        UFG::ActionTreeComponentBase *baseComponent,
        ActionNodeRoot *currentRoot,
        UFG::qBaseNodeVariableRB<unsigned __int64> **value_uid)
{
  int v5; // ebx
  Render::PersistentSkinningCacheNode *v6; // rax
  __int64 v7; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v8; // rcx
  bool result; // al

  v5 = (int)currentRoot;
  if ( !this )
    return 0;
  if ( !baseComponent )
    return 0;
  v6 = Render::PersistentSkinningCache::Find(
         (Render::PersistentSkinningCache *)&this->mActionTreeMemoryDataStructs,
         (unsigned __int64)baseComponent);
  if ( !v6 )
    return 0;
  v7 = (unsigned int)(v5 - 1000000);
  if ( (unsigned int)v7 >= LODWORD(v6[3].mNode.mParent) )
    return 0;
  v8 = v6[3].mNode.mChild[0]->mChild[3 * v7 + 1];
  result = 1;
  *value_uid = v8;
  return result;
}

// File Line: 474
// RVA: 0x2972D0
bool __fastcall UFG::ActionTreeComponentBase::ActionTreeMemoryData::GetValue(
        UFG::ActionTreeComponentBase::ActionTreeMemoryData *this,
        unsigned int value_uid,
        UFG::qSymbol *value)
{
  __int64 v3; // rdx
  unsigned int v5; // edx
  unsigned int mUID; // ecx
  bool v7; // al
  UFG::qWiseSymbol result; // [rsp+38h] [rbp+10h] BYREF

  v3 = value_uid - 500000;
  if ( (unsigned int)v3 >= this->m_pQSymbolArray.size )
    return 0;
  v5 = this->m_pQSymbolArray.p[v3];
  if ( v5 == -1 )
    return 0;
  mUID = UFG::qSymbol::qSymbol(&result, v5)->mUID;
  v7 = 1;
  value->mUID = mUID;
  return v7;
}

// File Line: 781
// RVA: 0x297370
__int64 __fastcall UFG::ActionTreeComponentBase::MakeValueUID(
        unsigned int prev_value_uid,
        UFG::eActionTreeMemoryElementType type)
{
  unsigned int *v2; // r8
  __int64 result; // rax

  if ( prev_value_uid )
    return prev_value_uid;
  v2 = &UFG::ActionTreeComponentBase::s_NumValueUIDs[UFG::ActionTreeComponentBase::s_CurrentlyResolvingActionTreeType][type];
  result = *v2 + 100000 * (type + 1);
  ++*v2;
  return result;
}


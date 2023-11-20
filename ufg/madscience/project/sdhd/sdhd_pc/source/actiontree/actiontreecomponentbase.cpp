// File Line: 50
// RVA: 0x297320
void UFG::ActionTreeComponentBase::Init(void)
{
  unsigned int (*v0)[11]; // rax
  signed __int64 v1; // rcx

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
    UFG::ActionTreeComponentBase::s_CurrentlyResolvingActionTreeType = 0;
    v1[10] = 0;
  }
  else
  {
    UFG::ActionTreeComponentBase::s_CurrentlyResolvingActionTreeType = 0;
  }
}

// File Line: 96
// RVA: 0x2972A0
__int64 __fastcall UFG::ActionTreeComponentBase::GetNumValueUIDs(UFG::eActionTreeType action_tree_type, UFG::eActionTreeMemoryElementType memory_element_type)
{
  return UFG::ActionTreeComponentBase::s_NumValueUIDs[0][(signed int)memory_element_type
                                                       + 11i64 * (signed int)action_tree_type];
}

// File Line: 101
// RVA: 0x295600
void __fastcall UFG::ActionTreeComponentBase::ActionTreeComponentBase(UFG::ActionTreeComponentBase *this, UFG::eActionTreeType eType)
{
  UFG::ActionTreeComponentBase *v2; // r10
  _QWORD *v3; // r8
  char v4; // cl
  UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::ActionTreeMemoryData,1> *v5; // [rsp+30h] [rbp+18h]

  v2 = this;
  this->vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::ActionTreeComponentBase::`vftable';
  v5 = &this->mActionTreeMemoryDataStructs;
  *(_OWORD *)&v5->mTree.mRoot.mParent = 0ui64;
  v5->mTree.mRoot.mChild[1] = 0i64;
  v3 = &this->mActionTreeMemoryDataStructs.mTree.mNULL.mParent;
  *v3 = 0i64;
  v3[1] = 0i64;
  v3[2] = 0i64;
  *v3 = (unsigned __int64)&this->mActionTreeMemoryDataStructs.mTree.mNULL | (_QWORD)this->mActionTreeMemoryDataStructs.mTree.mNULL.mParent & 1;
  v5->mTree.mNULL.mChild[0] = &v5->mTree.mNULL;
  v5->mTree.mNULL.mChild[1] = &v5->mTree.mNULL;
  *v3 &= 0xFFFFFFFFFFFFFFFEui64;
  v5->mTree.mNULL.mUID = 0i64;
  v5->mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&v5->mTree.mNULL | (_QWORD)v5->mTree.mRoot.mParent & 1);
  v5->mTree.mRoot.mChild[0] = &v5->mTree.mNULL;
  v5->mTree.mRoot.mChild[1] = &v5->mTree.mNULL;
  v5->mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((_QWORD)v5->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
  v5->mTree.mRoot.mUID = -1i64;
  v5->mTree.mCount = 0;
  v4 = once_7;
  if ( !once_7 )
    v4 = 1;
  once_7 = v4;
  v2->m_eType = eType;
}

// File Line: 113
// RVA: 0x296190
void __fastcall UFG::ActionTreeComponentBase::~ActionTreeComponentBase(UFG::ActionTreeComponentBase *this)
{
  UFG::ActionTreeComponentBase *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::ActionTreeComponentBase::`vftable';
  UFG::ActionTreeComponentBase::ResetMemory(this);
  UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::ActionTreeMemoryData,1>::~qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::ActionTreeMemoryData,1>(&v1->mActionTreeMemoryDataStructs);
}

// File Line: 117
// RVA: 0x1493F20
__int64 dynamic_initializer_for__UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs__()
{
  UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs.mTree.mNULL.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  return atexit(dynamic_atexit_destructor_for__UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs__);
}

// File Line: 118
// RVA: 0x1493F00
__int64 dynamic_initializer_for__UFG::ActionTreeComponentBase::msMemoryManageRecyclableActionTreeMemoryDataStructs__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::ActionTreeComponentBase::msMemoryManageRecyclableActionTreeMemoryDataStructs__);
}

// File Line: 127
// RVA: 0x296A60
char __fastcall UFG::ActionTreeComponentBase::AllocateFor(UFG::ActionTreeComponentBase *this, ActionNodeRoot *action_node_root)
{
  ActionNodeRoot *v2; // rbx
  UFG::ActionTreeComponentBase *v3; // rsi
  UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::ActionTreeMemoryData,1> *v4; // rax
  bool i; // zf
  UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::ActionTreeMemoryData,1> *j; // rcx
  UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *v8; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *k; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v10; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v11; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v12; // rax
  UFG::ActionTreeComponentBase::ActionTreeMemoryData *v13; // rdi
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *v14; // rdx
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *v15; // rcx
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *v16; // rax
  UFG::allocator::free_link *v17; // rax
  UFG::ActionTreeComponentBase::ActionTreeMemoryData *v18; // rax

  v2 = action_node_root;
  v3 = this;
  if ( !action_node_root )
    goto LABEL_30;
  v4 = &this->mActionTreeMemoryDataStructs;
  for ( i = &this->mActionTreeMemoryDataStructs == (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::ActionTreeMemoryData,1> *)&this->mActionTreeMemoryDataStructs.mTree.mNULL;
        !i;
        i = v4 == (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::ActionTreeMemoryData,1> *)&this->mActionTreeMemoryDataStructs.mTree.mNULL )
  {
    if ( v4 != &this->mActionTreeMemoryDataStructs && (ActionNodeRoot *)v4->mTree.mRoot.mUID == action_node_root )
    {
      for ( j = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::ActionTreeMemoryData,1> *)v4->mTree.mRoot.mChild[0];
            j;
            j = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::ActionTreeMemoryData,1> *)j->mTree.mRoot.mChild[0] )
      {
        if ( (ActionNodeRoot *)j->mTree.mRoot.mUID != action_node_root )
          break;
        v4 = j;
      }
      if ( v4 )
        return 0;
      break;
    }
    if ( (unsigned __int64)action_node_root > v4->mTree.mRoot.mUID )
      v4 = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::ActionTreeMemoryData,1> *)v4->mTree.mRoot.mChild[1];
    else
      v4 = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::ActionTreeMemoryData,1> *)v4->mTree.mRoot.mChild[0];
  }
  v8 = &UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs;
  while ( v8 == &UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs
       || (ActionNodeRoot *)v8->mTree.mRoot.mUID != v2 )
  {
    if ( (unsigned __int64)v2 > v8->mTree.mRoot.mUID )
      v8 = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)v8->mTree.mRoot.mChild[1];
    else
      v8 = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)v8->mTree.mRoot.mChild[0];
    if ( v8 == (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)&UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs.mTree.mNULL )
      goto LABEL_30;
  }
  for ( k = v8->mTree.mRoot.mChild[0]; k; k = k->mChild[0] )
  {
    if ( (ActionNodeRoot *)k->mUID != v2 )
      break;
    v8 = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)k;
  }
  if ( !v8 )
    goto LABEL_30;
  if ( (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)&v8->mTree.mNULL.mChild[0][-1] == v8 )
    goto LABEL_30;
  v10 = v8->mTree.mNULL.mChild[0];
  v11 = v10->mParent;
  v12 = v10->mChild[0];
  v11->mChild[0] = v12;
  v12->mParent = v11;
  v10->mParent = v10;
  v10->mChild[0] = v10;
  v13 = (UFG::ActionTreeComponentBase::ActionTreeMemoryData *)&v10[-1];
  if ( v10 != (UFG::qBaseNodeVariableRB<unsigned __int64> *)32 )
  {
    v14 = (UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *)&v13->mPrev;
    v15 = v13->mPrev;
    v16 = v13->mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v14->mPrev = v14;
    v14->mNext = v14;
    UFG::ActionTreeComponentBase::msTotalRecyclableBytes -= v13->mSize;
    UFG::ActionTreeComponentBase::ActionTreeMemoryData::Reset(v13);
  }
  else
  {
LABEL_30:
    v17 = UFG::qMalloc(0x100ui64, "ActionTreeMemoryData", 0i64);
    if ( v17 )
    {
      UFG::ActionTreeComponentBase::ActionTreeMemoryData::ActionTreeMemoryData(
        (UFG::ActionTreeComponentBase::ActionTreeMemoryData *)v17,
        v3,
        v2);
      v13 = v18;
    }
    else
    {
      v13 = 0i64;
    }
    v13->mNode.mUID = (unsigned __int64)v2;
  }
  UFG::qBaseTreeVariableRB<unsigned __int64>::Add(&v3->mActionTreeMemoryDataStructs.mTree, &v13->mNode);
  return 1;
}

// File Line: 161
// RVA: 0x297A80
void __fastcall UFG::ActionTreeComponentBase::ResetMemory(UFG::ActionTreeComponentBase *this)
{
  UFG::ActionTreeComponentBase *v1; // r14
  char *v2; // rdi
  UFG::qBaseNodeVariableRB<unsigned __int64> *v3; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *i; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v5; // rsi
  unsigned __int64 v6; // rcx
  UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *v7; // rbx
  UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *j; // rax
  UFG::allocator::free_link *v9; // rax
  signed __int64 v10; // rbx
  signed __int64 *v11; // rcx
  _QWORD *v12; // rax
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *v13; // rcx
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *v14; // rax
  UFG::allocator::free_link *v15; // [rsp+78h] [rbp+10h]

  v1 = this;
  if ( this->mActionTreeMemoryDataStructs.mTree.mCount )
  {
    v2 = (char *)&this->mActionTreeMemoryDataStructs.mTree.mNULL;
    do
    {
      v3 = v1->mActionTreeMemoryDataStructs.mTree.mRoot.mChild[0];
      for ( i = v3->mChild[0]; i != (UFG::qBaseNodeVariableRB<unsigned __int64> *)v2; i = i->mChild[0] )
        v3 = i;
      v5 = 0i64;
      if ( v3 != (UFG::qBaseNodeVariableRB<unsigned __int64> *)v2 )
        v5 = v3;
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v1->mActionTreeMemoryDataStructs.mTree, v5);
      v6 = v5->mUID;
      if ( !v6 )
        goto LABEL_30;
      v7 = &UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs;
      while ( v7 == &UFG::ActionTreeComponentBase::msRecyclableActionTreeMemoryDataStructs || v7->mTree.mRoot.mUID != v6 )
      {
        if ( v6 > v7->mTree.mRoot.mUID )
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
        if ( j->mTree.mRoot.mUID != v6 )
          break;
        v7 = j;
      }
LABEL_21:
      if ( !v7 )
      {
LABEL_30:
        v9 = UFG::qMalloc(0x30ui64, "ActionTreeComponentBase::ResetMemory", 0i64);
        v7 = (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)v9;
        if ( v9 )
        {
          v9->mNext = 0i64;
          v9[1].mNext = 0i64;
          v9[2].mNext = 0i64;
          v15 = v9 + 4;
          v15->mNext = v15;
          v15[1].mNext = v15;
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
      v10 = (signed __int64)&v7->mTree.mNULL;
      v11 = (signed __int64 *)&v5[1];
      v12 = *(_QWORD **)(v10 + 8);
      *(_QWORD *)(v10 + 8) = v5 + 1;
      *v11 = v10;
      v11[1] = (signed __int64)v12;
      *v12 = v5 + 1;
      v13 = (UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *)&v5[1].mChild1;
      v14 = UFG::ActionTreeComponentBase::msMemoryManageRecyclableActionTreeMemoryDataStructs.mNode.mNext;
      UFG::ActionTreeComponentBase::msMemoryManageRecyclableActionTreeMemoryDataStructs.mNode.mNext = v13;
      v13->mPrev = (UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *)&UFG::ActionTreeComponentBase::msMemoryManageRecyclableActionTreeMemoryDataStructs;
      v13->mNext = v14;
      v14->mPrev = (UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *)&v5[1].mChild1;
      UFG::ActionTreeComponentBase::msTotalRecyclableBytes += LODWORD(v5[7].mUID);
    }
    while ( v1->mActionTreeMemoryDataStructs.mTree.mCount );
  }
  UFG::ActionTreeComponentBase::ManageMemory();
}

// File Line: 184
// RVA: 0x2973B0
void UFG::ActionTreeComponentBase::ManageMemory(void)
{
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *v0; // rbx
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *v1; // rcx
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *v2; // rax

  while ( UFG::ActionTreeComponentBase::msTotalRecyclableBytes > UFG::ActionTreeComponentBase::msMaxTotalRecyclableBytes )
  {
    v0 = UFG::ActionTreeComponentBase::msMemoryManageRecyclableActionTreeMemoryDataStructs.mNode.mPrev;
    v1 = UFG::ActionTreeComponentBase::msMemoryManageRecyclableActionTreeMemoryDataStructs.mNode.mPrev->mPrev;
    v2 = UFG::ActionTreeComponentBase::msMemoryManageRecyclableActionTreeMemoryDataStructs.mNode.mPrev->mNext;
    v1->mNext = v2;
    v2->mPrev = v1;
    v0->mPrev = v0;
    v0->mNext = v0;
    UFG::ActionTreeComponentBase::msTotalRecyclableBytes -= LODWORD(v0[12].mNext);
    UFG::ActionTreeComponentBase::ActionTreeMemoryData::~ActionTreeMemoryData((UFG::ActionTreeComponentBase::ActionTreeMemoryData *)&v0[-3]);
    operator delete[](&v0[-3]);
  }
}

// File Line: 240
// RVA: 0x296E60
void UFG::ActionTreeComponentBase::DeleteAllMemory(void)
{
  UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *v0; // rcx
  UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *i; // rax
  UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *v2; // rsi
  UFG::qBaseNodeVariableRB<unsigned __int64> *v3; // rdi
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v5; // rcx
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
    v3 = &v2->mTree.mNULL;
    while ( (UFG::qTreeRB64<UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,UFG::ActionTreeComponentBase::ActionTreeMemoryDataList,1> *)&v2->mTree.mNULL.mChild[0][-1] != v2 )
    {
      v4 = v2->mTree.mNULL.mChild[0];
      v5 = v4->mParent;
      v6 = v4->mChild[0];
      v5->mChild[0] = v6;
      v6->mParent = v5;
      v4->mParent = v4;
      v4->mChild[0] = v4;
      UFG::ActionTreeComponentBase::msTotalRecyclableBytes -= LODWORD(v4[6].mUID);
      UFG::ActionTreeComponentBase::ActionTreeMemoryData::~ActionTreeMemoryData((UFG::ActionTreeComponentBase::ActionTreeMemoryData *)&v4[-1]);
      operator delete[](&v4[-1]);
    }
    if ( v2 )
    {
      UFG::qList<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree,1,0>::DeleteNodes((UFG::qList<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree,1,0> *)&v2->mTree.mNULL);
      v7 = v3->mParent;
      v8 = v2->mTree.mNULL.mChild[0];
      v7->mChild[0] = v8;
      v8->mParent = v7;
      v3->mParent = v3;
      v2->mTree.mNULL.mChild[0] = &v2->mTree.mNULL;
      operator delete[](v2);
    }
  }
}

// File Line: 258
// RVA: 0x2956B0
void __fastcall UFG::ActionTreeComponentBase::ActionTreeMemoryData::ActionTreeMemoryData(UFG::ActionTreeComponentBase::ActionTreeMemoryData *this, UFG::ActionTreeComponentBase *component, ActionNodeRoot *action_node_root)
{
  UFG::ActionTreeComponentBase::ActionTreeMemoryData *v3; // rbx
  unsigned int v4; // ebp
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree> *v5; // rax
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *v6; // rax
  unsigned int v7; // er15
  unsigned int v8; // edi
  unsigned int v9; // edx
  unsigned int v10; // esi
  unsigned int v11; // edx
  unsigned int v12; // er14
  unsigned int v13; // edi
  unsigned int v14; // edx
  unsigned int v15; // edx
  unsigned int v16; // er14
  unsigned int v17; // edi
  unsigned int v18; // edx
  unsigned int v19; // edx
  unsigned int v20; // er12
  UFG::allocator::free_link *v21; // rax
  char *v22; // rdi
  unsigned int i; // er9
  unsigned int v24; // ecx
  unsigned int v25; // er14
  unsigned int v26; // edi
  unsigned int v27; // edi
  UFG::allocator::free_link *v28; // rax
  char *v29; // r15
  unsigned int v30; // er14
  UFG::qArray<unsigned long,0> *v31; // r15
  unsigned int v32; // edi
  unsigned int v33; // edx
  unsigned int v34; // edx
  unsigned int v35; // er14
  UFG::qArray<unsigned long,0> *v36; // r15
  unsigned int v37; // edi
  unsigned int v38; // edx
  unsigned int v39; // edx
  unsigned int v40; // er14
  UFG::qArray<UFG::qSafePointer<UFG::SimObject,UFG::SimObject>,0> *v41; // r15
  unsigned int v42; // edi
  unsigned int v43; // edx
  unsigned int v44; // edx
  unsigned int v45; // er14
  UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0> *v46; // r15
  unsigned int v47; // edi
  unsigned int v48; // edx
  unsigned int v49; // edx
  unsigned int v50; // er14
  UFG::qArray<UFG::qSafePointer<UFG::GetInFormationNode,UFG::GetInFormationNode>,0> *v51; // r15
  unsigned int v52; // edi
  unsigned int v53; // edx
  unsigned int v54; // edx
  unsigned int v55; // er14
  UFG::qArray<UFG::qSafePointer<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode>,0> *v56; // r15
  unsigned int v57; // edi
  unsigned int v58; // edx
  unsigned int v59; // edx
  unsigned int v60; // er14
  UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0> *v61; // r15
  unsigned int v62; // edi
  unsigned int v63; // eax
  ActionNodeRoot *v64; // [rsp+80h] [rbp+18h]

  v64 = action_node_root;
  v3 = this;
  v4 = 0;
  this->mNode.mParent = 0i64;
  this->mNode.8 = 0ui64;
  v5 = (UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree> *)&this->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v6 = (UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *)&this->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
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
    v7 = action_node_root->m_NumNeededActionTreeComponentBaseValueUIDs[0];
    if ( v7 > this->m_pFloatArray.capacity )
      UFG::qArray<float,0>::Reallocate(&this->m_pFloatArray, v7, "ActionTreeMemory.float");
    v8 = v7 + v3->m_pFloatArray.size;
    v9 = v3->m_pFloatArray.capacity;
    v10 = 1;
    if ( v8 > v9 )
    {
      if ( v9 )
        v11 = 2 * v9;
      else
        v11 = 1;
      for ( ; v11 < v8; v11 *= 2 )
        ;
      if ( v11 <= 4 )
        v11 = 4;
      if ( v11 - v8 > 0x10000 )
        v11 = v8 + 0x10000;
      UFG::qArray<float,0>::Reallocate(&v3->m_pFloatArray, v11, "ActionTreeMemory.float");
    }
    v3->m_pFloatArray.size = v8;
    v3->mSize += 4 * v7;
    v12 = v64->m_NumNeededActionTreeComponentBaseValueUIDs[1];
    if ( v12 > v3->m_pIntArray.capacity )
      UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)&v3->m_pIntArray, v12, "ActionTreeMemory.int32");
    v13 = v12 + v3->m_pIntArray.size;
    v14 = v3->m_pIntArray.capacity;
    if ( v13 > v14 )
    {
      if ( v14 )
        v15 = 2 * v14;
      else
        v15 = 1;
      for ( ; v15 < v13; v15 *= 2 )
        ;
      if ( v15 <= 4 )
        v15 = 4;
      if ( v15 - v13 > 0x10000 )
        v15 = v13 + 0x10000;
      UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)&v3->m_pIntArray, v15, "ActionTreeMemory.int32");
    }
    v3->m_pIntArray.size = v13;
    v3->mSize += 4 * v12;
    v16 = v64->m_NumNeededActionTreeComponentBaseValueUIDs[2];
    if ( v16 > v3->m_pUInt64Array.capacity )
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v3->m_pUInt64Array,
        v16,
        "ActionTreeMemory.uint64");
    v17 = v16 + v3->m_pUInt64Array.size;
    v18 = v3->m_pUInt64Array.capacity;
    if ( v17 > v18 )
    {
      if ( v18 )
        v19 = 2 * v18;
      else
        v19 = 1;
      for ( ; v19 < v17; v19 *= 2 )
        ;
      if ( v19 <= 2 )
        v19 = 2;
      if ( v19 - v17 > 0x10000 )
        v19 = v17 + 0x10000;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v3->m_pUInt64Array,
        v19,
        "ActionTreeMemory.uint64");
    }
    v3->m_pUInt64Array.size = v17;
    v3->mSize += 8 * v16;
    v20 = v64->m_NumNeededActionTreeComponentBaseValueUIDs[3];
    if ( v20 > v3->m_pBoolArray.capacity && v20 != v3->m_pBoolArray.size )
    {
      v21 = UFG::qMalloc(v20, "ActionTreeMemory.uint8", 0i64);
      v22 = (char *)v21;
      if ( v3->m_pBoolArray.p )
      {
        for ( i = 0; i < v3->m_pBoolArray.size; ++i )
          *((_BYTE *)&v21->mNext + i) = v3->m_pBoolArray.p[i];
        operator delete[](v3->m_pBoolArray.p);
      }
      v3->m_pBoolArray.p = v22;
      v3->m_pBoolArray.capacity = v20;
    }
    v24 = v3->m_pBoolArray.size;
    v25 = v24 + v20;
    v26 = v3->m_pBoolArray.capacity;
    if ( v24 + v20 > v26 )
    {
      if ( v26 )
        v27 = 2 * v26;
      else
        v27 = 1;
      for ( ; v27 < v25; v27 *= 2 )
        ;
      if ( v27 <= 0x10 )
        v27 = 16;
      if ( v27 - v25 > 0x10000 )
        v27 = v25 + 0x10000;
      if ( v27 != v24 )
      {
        v28 = UFG::qMalloc(v27, "ActionTreeMemory.uint8", 0i64);
        v29 = (char *)v28;
        if ( v3->m_pBoolArray.p )
        {
          if ( v3->m_pBoolArray.size )
          {
            do
            {
              *((_BYTE *)&v28->mNext + v4) = v3->m_pBoolArray.p[v4];
              ++v4;
            }
            while ( v4 < v3->m_pBoolArray.size );
          }
          operator delete[](v3->m_pBoolArray.p);
        }
        v3->m_pBoolArray.p = v29;
        v3->m_pBoolArray.capacity = v27;
      }
    }
    v3->m_pBoolArray.size = v25;
    v3->mSize += v20;
    v30 = v64->m_NumNeededActionTreeComponentBaseValueUIDs[4];
    v31 = &v3->m_pQSymbolArray;
    if ( v30 > v3->m_pQSymbolArray.capacity )
      UFG::qArray<long,0>::Reallocate(&v3->m_pQSymbolArray, v30, "ActionTreeMemory.uint32");
    v32 = v30 + v31->size;
    v33 = v3->m_pQSymbolArray.capacity;
    if ( v32 > v33 )
    {
      if ( v33 )
        v34 = 2 * v33;
      else
        v34 = 1;
      for ( ; v34 < v32; v34 *= 2 )
        ;
      if ( v34 <= 4 )
        v34 = 4;
      if ( v34 - v32 > 0x10000 )
        v34 = v32 + 0x10000;
      UFG::qArray<long,0>::Reallocate(&v3->m_pQSymbolArray, v34, "ActionTreeMemory.uint32");
    }
    v31->size = v32;
    v3->mSize += 4 * v30;
    v35 = v64->m_NumNeededActionTreeComponentBaseValueUIDs[5];
    v36 = &v3->m_pQSymbolUCArray;
    if ( v35 > v3->m_pQSymbolUCArray.capacity )
      UFG::qArray<long,0>::Reallocate(&v3->m_pQSymbolUCArray, v35, "ActionTreeMemory.uint32");
    v37 = v35 + v36->size;
    v38 = v3->m_pQSymbolUCArray.capacity;
    if ( v37 > v38 )
    {
      if ( v38 )
        v39 = 2 * v38;
      else
        v39 = 1;
      for ( ; v39 < v37; v39 *= 2 )
        ;
      if ( v39 <= 4 )
        v39 = 4;
      if ( v39 - v37 > 0x10000 )
        v39 = v37 + 0x10000;
      UFG::qArray<long,0>::Reallocate(&v3->m_pQSymbolUCArray, v39, "ActionTreeMemory.uint32");
    }
    v36->size = v37;
    v3->mSize += 4 * v35;
    v40 = v64->m_NumNeededActionTreeComponentBaseValueUIDs[6];
    v41 = &v3->m_pSimObjectPointerArray;
    if ( v40 > v3->m_pSimObjectPointerArray.capacity )
      UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
        (UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *)&v3->m_pSimObjectPointerArray,
        v40,
        "ActionTreeMemory.SimObjectSafePtr");
    v42 = v40 + v41->size;
    v43 = v3->m_pSimObjectPointerArray.capacity;
    if ( v42 > v43 )
    {
      if ( v43 )
        v44 = 2 * v43;
      else
        v44 = 1;
      for ( ; v44 < v42; v44 *= 2 )
        ;
      if ( v44 - v42 > 0x10000 )
        v44 = v42 + 0x10000;
      UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
        (UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *)&v3->m_pSimObjectPointerArray,
        v44,
        "ActionTreeMemory.SimObjectSafePtr");
    }
    v41->size = v42;
    v3->mSize += 16 * v40;
    v45 = v64->m_NumNeededActionTreeComponentBaseValueUIDs[7];
    v46 = &v3->m_pSimComponentPointerArray;
    if ( v45 > v3->m_pSimComponentPointerArray.capacity )
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(
        &v3->m_pSimComponentPointerArray,
        v45,
        "ActionTreeMemory.SimComponentPtr");
    v47 = v45 + v46->size;
    v48 = v3->m_pSimComponentPointerArray.capacity;
    if ( v47 > v48 )
    {
      if ( v48 )
        v49 = 2 * v48;
      else
        v49 = 1;
      for ( ; v49 < v47; v49 *= 2 )
        ;
      if ( v49 - v47 > 0x10000 )
        v49 = v47 + 0x10000;
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(
        &v3->m_pSimComponentPointerArray,
        v49,
        "ActionTreeMemory.SimComponentPtr");
    }
    v46->size = v47;
    v3->mSize += 16 * v45;
    v50 = v64->m_NumNeededActionTreeComponentBaseValueUIDs[8];
    v51 = &v3->m_pGetInFormationNodePointerArray;
    if ( v50 > v3->m_pGetInFormationNodePointerArray.capacity )
      UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
        (UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *)&v3->m_pGetInFormationNodePointerArray,
        v50,
        "ActionTreeMemory.GetInFormationNodePtr");
    v52 = v50 + v51->size;
    v53 = v3->m_pGetInFormationNodePointerArray.capacity;
    if ( v52 > v53 )
    {
      if ( v53 )
        v54 = 2 * v53;
      else
        v54 = 1;
      for ( ; v54 < v52; v54 *= 2 )
        ;
      if ( v54 - v52 > 0x10000 )
        v54 = v52 + 0x10000;
      UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
        (UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *)&v3->m_pGetInFormationNodePointerArray,
        v54,
        "ActionTreeMemory.GetInFormationNodePtr");
    }
    v51->size = v52;
    v3->mSize += 16 * v50;
    v55 = v64->m_NumNeededActionTreeComponentBaseValueUIDs[9];
    v56 = &v3->m_pGetInPedFormationNodePointerArray;
    if ( v55 > v3->m_pGetInPedFormationNodePointerArray.capacity )
      UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
        (UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *)&v3->m_pGetInPedFormationNodePointerArray,
        v55,
        "ActionTreeMemory.GetInPedFormationNodePtr");
    v57 = v55 + v56->size;
    v58 = v3->m_pGetInPedFormationNodePointerArray.capacity;
    if ( v57 > v58 )
    {
      if ( v58 )
        v59 = 2 * v58;
      else
        v59 = 1;
      for ( ; v59 < v57; v59 *= 2 )
        ;
      if ( v59 - v57 > 0x10000 )
        v59 = v57 + 0x10000;
      UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
        (UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *)&v3->m_pGetInPedFormationNodePointerArray,
        v59,
        "ActionTreeMemory.GetInPedFormationNodePtr");
    }
    v56->size = v57;
    v3->mSize += 16 * v55;
    v60 = v64->m_NumNeededActionTreeComponentBaseValueUIDs[10];
    v61 = &v3->m_pHasAttackRequestNodePointerArray;
    if ( v60 > v3->m_pHasAttackRequestNodePointerArray.capacity )
      UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
        (UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *)&v3->m_pHasAttackRequestNodePointerArray,
        v60,
        "ActionTreeMemory.HasAttackRequestNodePtr");
    v62 = v60 + v61->size;
    v63 = v3->m_pHasAttackRequestNodePointerArray.capacity;
    if ( v62 > v63 )
    {
      if ( v63 )
        v10 = 2 * v63;
      for ( ; v10 < v62; v10 *= 2 )
        ;
      if ( v10 - v62 > 0x10000 )
        v10 = v62 + 0x10000;
      UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
        (UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *)&v3->m_pHasAttackRequestNodePointerArray,
        v10,
        "ActionTreeMemory.HasAttackRequestNodePtr");
    }
    v61->size = v62;
    v3->mSize += 16 * v60;
    v3->mNode.mUID = (unsigned __int64)v64;
    UFG::ActionTreeComponentBase::ActionTreeMemoryData::Reset(v3);
  }
}

// File Line: 332
// RVA: 0x297810
void __fastcall UFG::ActionTreeComponentBase::ActionTreeMemoryData::Reset(UFG::ActionTreeComponentBase::ActionTreeMemoryData *this)
{
  _DWORD *v1; // rax
  UFG::ActionTreeComponentBase::ActionTreeMemoryData *v2; // rbx
  int v3; // esi
  int v4; // ebp
  unsigned int v5; // er14
  int v6; // er15
  int v7; // er12
  __int64 v8; // rdi
  __int64 v9; // r13
  __int64 v10; // r8
  __int64 v11; // r9
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
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

  v1 = (_DWORD *)this->mNode.mUID;
  v2 = this;
  v3 = v1[49];
  v4 = v1[50];
  v5 = v1[51];
  v6 = v1[52];
  v7 = v1[53];
  v8 = (unsigned int)v1[54];
  v9 = (unsigned int)v1[55];
  v35 = v1[56];
  v37 = v1[58];
  v36 = v1[57];
  if ( this->m_pFloatArray.size )
    UFG::qMemSet(this->m_pFloatArray.p, -1, 4 * v1[48]);
  if ( v2->m_pIntArray.size )
    UFG::qMemSet(v2->m_pIntArray.p, 0, 4 * v3);
  if ( v2->m_pUInt64Array.size )
    UFG::qMemSet(v2->m_pUInt64Array.p, 0, 8 * v4);
  if ( v2->m_pBoolArray.size )
    UFG::qMemSet(v2->m_pBoolArray.p, 0, v5);
  if ( v2->m_pQSymbolArray.size )
    UFG::qMemSet(v2->m_pQSymbolArray.p, -1, 4 * v6);
  if ( v2->m_pQSymbolUCArray.size )
    UFG::qMemSet(v2->m_pQSymbolUCArray.p, -1, 4 * v7);
  if ( (_DWORD)v8 )
  {
    v10 = 0i64;
    v11 = v8;
    do
    {
      v12 = &v2->m_pSimObjectPointerArray.p[v10];
      if ( v12->m_pPointer )
      {
        v13 = v12->mPrev;
        v14 = v12->mNext;
        v13->mNext = v14;
        v14->mPrev = v13;
        v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
        v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
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
      v17 = &v2->m_pSimComponentPointerArray.p[v15];
      if ( v17->m_pPointer )
      {
        v18 = v17->mPrev;
        v19 = v17->mNext;
        v18->mNext = v19;
        v19->mPrev = v18;
        v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
        v17->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
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
      v22 = &v2->m_pGetInFormationNodePointerArray.p[v20];
      if ( v22->m_pPointer )
      {
        v23 = v22->mPrev;
        v24 = v22->mNext;
        v23->mNext = v24;
        v24->mPrev = v23;
        v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *)&v22->mPrev;
        v22->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *)&v22->mPrev;
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
      v27 = &v2->m_pGetInPedFormationNodePointerArray.p[v25];
      if ( v27->m_pPointer )
      {
        v28 = v27->mPrev;
        v29 = v27->mNext;
        v28->mNext = v29;
        v29->mPrev = v28;
        v27->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *)&v27->mPrev;
        v27->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *)&v27->mPrev;
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
      v32 = &v2->m_pHasAttackRequestNodePointerArray.p[v30];
      if ( v32->m_pPointer )
      {
        v33 = v32->mPrev;
        v34 = v32->mNext;
        v33->mNext = v34;
        v34->mPrev = v33;
        v32->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v32->mPrev;
        v32->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::HasAttackRequestNode>,UFG::qSafePointerNodeList> *)&v32->mPrev;
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
void __fastcall UFG::ActionTreeComponentBase::ActionTreeMemoryData::~ActionTreeMemoryData(UFG::ActionTreeComponentBase::ActionTreeMemoryData *this)
{
  UFG::ActionTreeComponentBase::ActionTreeMemoryData *v1; // rdi
  float *v2; // rcx
  int *v3; // rcx
  unsigned __int64 *v4; // rcx
  char *v5; // rcx
  unsigned int *v6; // rcx
  unsigned int *v7; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v8; // rcx
  UFG::SimObject **v9; // rbx
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
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *v34; // rdx
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *v35; // rcx
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *v36; // rax
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree> *v37; // rdx
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree> *v38; // rcx
  UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree> *v39; // rax

  v1 = this;
  this->m_pMyComponent = 0i64;
  v2 = this->m_pFloatArray.p;
  if ( v2 )
    operator delete[](v2);
  v1->m_pFloatArray.p = 0i64;
  *(_QWORD *)&v1->m_pFloatArray.size = 0i64;
  v3 = v1->m_pIntArray.p;
  if ( v3 )
    operator delete[](v3);
  v1->m_pIntArray.p = 0i64;
  *(_QWORD *)&v1->m_pIntArray.size = 0i64;
  v4 = v1->m_pUInt64Array.p;
  if ( v4 )
    operator delete[](v4);
  v1->m_pUInt64Array.p = 0i64;
  *(_QWORD *)&v1->m_pUInt64Array.size = 0i64;
  v5 = v1->m_pBoolArray.p;
  if ( v5 )
    operator delete[](v5);
  v1->m_pBoolArray.p = 0i64;
  *(_QWORD *)&v1->m_pBoolArray.size = 0i64;
  v6 = v1->m_pQSymbolArray.p;
  if ( v6 )
    operator delete[](v6);
  v1->m_pQSymbolArray.p = 0i64;
  *(_QWORD *)&v1->m_pQSymbolArray.size = 0i64;
  v7 = v1->m_pQSymbolUCArray.p;
  if ( v7 )
    operator delete[](v7);
  v1->m_pQSymbolUCArray.p = 0i64;
  *(_QWORD *)&v1->m_pQSymbolUCArray.size = 0i64;
  v8 = v1->m_pSimObjectPointerArray.p;
  if ( v8 )
  {
    v9 = &v8[-1].m_pPointer;
    `eh vector destructor iterator'(
      v8,
      0x18ui64,
      (int)v8[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v9);
  }
  v1->m_pSimObjectPointerArray.p = 0i64;
  *(_QWORD *)&v1->m_pSimObjectPointerArray.size = 0i64;
  v10 = v1->m_pSimComponentPointerArray.p;
  if ( v10 )
  {
    v11 = &v10[-1].m_pPointer;
    `eh vector destructor iterator'(
      v10,
      0x18ui64,
      (int)v10[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
    operator delete[](v11);
  }
  v1->m_pSimComponentPointerArray.p = 0i64;
  *(_QWORD *)&v1->m_pSimComponentPointerArray.size = 0i64;
  v12 = v1->m_pGetInFormationNodePointerArray.p;
  if ( v12 )
  {
    v13 = &v12[-1].m_pPointer;
    `eh vector destructor iterator'(
      v12,
      0x18ui64,
      (int)v12[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v13);
  }
  v1->m_pGetInFormationNodePointerArray.p = 0i64;
  *(_QWORD *)&v1->m_pGetInFormationNodePointerArray.size = 0i64;
  v14 = v1->m_pGetInPedFormationNodePointerArray.p;
  if ( v14 )
  {
    v15 = &v14[-1].m_pPointer;
    `eh vector destructor iterator'(
      v14,
      0x18ui64,
      (int)v14[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v15);
  }
  v1->m_pGetInPedFormationNodePointerArray.p = 0i64;
  *(_QWORD *)&v1->m_pGetInPedFormationNodePointerArray.size = 0i64;
  v16 = v1->m_pHasAttackRequestNodePointerArray.p;
  if ( v16 )
  {
    v17 = &v16[-1].m_pPointer;
    `eh vector destructor iterator'(
      v16,
      0x18ui64,
      (int)v16[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v17);
  }
  v1->m_pHasAttackRequestNodePointerArray.p = 0i64;
  *(_QWORD *)&v1->m_pHasAttackRequestNodePointerArray.size = 0i64;
  v18 = v1->m_pHasAttackRequestNodePointerArray.p;
  if ( v18 )
  {
    v19 = &v18[-1].m_pPointer;
    `eh vector destructor iterator'(
      v18,
      0x18ui64,
      (int)v18[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v19);
  }
  v1->m_pHasAttackRequestNodePointerArray.p = 0i64;
  *(_QWORD *)&v1->m_pHasAttackRequestNodePointerArray.size = 0i64;
  v20 = v1->m_pGetInPedFormationNodePointerArray.p;
  if ( v20 )
  {
    v21 = &v20[-1].m_pPointer;
    `eh vector destructor iterator'(
      v20,
      0x18ui64,
      (int)v20[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v21);
  }
  v1->m_pGetInPedFormationNodePointerArray.p = 0i64;
  *(_QWORD *)&v1->m_pGetInPedFormationNodePointerArray.size = 0i64;
  v22 = v1->m_pGetInFormationNodePointerArray.p;
  if ( v22 )
  {
    v23 = &v22[-1].m_pPointer;
    `eh vector destructor iterator'(
      v22,
      0x18ui64,
      (int)v22[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v23);
  }
  v1->m_pGetInFormationNodePointerArray.p = 0i64;
  *(_QWORD *)&v1->m_pGetInFormationNodePointerArray.size = 0i64;
  v24 = v1->m_pSimComponentPointerArray.p;
  if ( v24 )
  {
    v25 = &v24[-1].m_pPointer;
    `eh vector destructor iterator'(
      v24,
      0x18ui64,
      (int)v24[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
    operator delete[](v25);
  }
  v1->m_pSimComponentPointerArray.p = 0i64;
  *(_QWORD *)&v1->m_pSimComponentPointerArray.size = 0i64;
  v26 = v1->m_pSimObjectPointerArray.p;
  if ( v26 )
  {
    v27 = &v26[-1].m_pPointer;
    `eh vector destructor iterator'(
      v26,
      0x18ui64,
      (int)v26[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v27);
  }
  v1->m_pSimObjectPointerArray.p = 0i64;
  *(_QWORD *)&v1->m_pSimObjectPointerArray.size = 0i64;
  v28 = v1->m_pQSymbolUCArray.p;
  if ( v28 )
    operator delete[](v28);
  v1->m_pQSymbolUCArray.p = 0i64;
  *(_QWORD *)&v1->m_pQSymbolUCArray.size = 0i64;
  v29 = v1->m_pQSymbolArray.p;
  if ( v29 )
    operator delete[](v29);
  v1->m_pQSymbolArray.p = 0i64;
  *(_QWORD *)&v1->m_pQSymbolArray.size = 0i64;
  v30 = v1->m_pBoolArray.p;
  if ( v30 )
    operator delete[](v30);
  v1->m_pBoolArray.p = 0i64;
  *(_QWORD *)&v1->m_pBoolArray.size = 0i64;
  v31 = v1->m_pUInt64Array.p;
  if ( v31 )
    operator delete[](v31);
  v1->m_pUInt64Array.p = 0i64;
  *(_QWORD *)&v1->m_pUInt64Array.size = 0i64;
  v32 = v1->m_pIntArray.p;
  if ( v32 )
    operator delete[](v32);
  v1->m_pIntArray.p = 0i64;
  *(_QWORD *)&v1->m_pIntArray.size = 0i64;
  v33 = v1->m_pFloatArray.p;
  if ( v33 )
    operator delete[](v33);
  v1->m_pFloatArray.p = 0i64;
  *(_QWORD *)&v1->m_pFloatArray.size = 0i64;
  v34 = (UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemManList> *)&v1->mPrev;
  v35 = v1->mPrev;
  v36 = v1->mNext;
  v35->mNext = v36;
  v36->mPrev = v35;
  v34->mPrev = v34;
  v34->mNext = v34;
  v37 = (UFG::qNode<UFG::ActionTreeComponentBase::ActionTreeMemoryData,UFG::ActionTreeComponentBase::MemRBTree> *)&v1->mPrev;
  v38 = v1->mPrev;
  v39 = v1->mNext;
  v38->mNext = v39;
  v39->mPrev = v38;
  v37->mPrev = v37;
  v37->mNext = v37;
}

// File Line: 428
// RVA: 0x295590
char __fastcall UFG::ActionTreeComponentBase::SetMemoryValueImpl<bool>(UFG::ActionTreeComponentBase *this, UFG::ActionTreeComponentBase *baseComponent, ActionNodeRoot *currentRoot, unsigned int value_uid)
{
  char v4; // di
  int v5; // ebx
  Render::PersistentSkinningCacheNode *v6; // rax
  __int64 v7; // rcx

  v4 = value_uid;
  v5 = (signed int)currentRoot;
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
  *(_BYTE *)(v7 + v6[1].mSize) = (v4 != 0) - 16;
  return 1;
}

// File Line: 454
// RVA: 0x295120
char __fastcall UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::GetInPedFormationNode *>(UFG::ActionTreeComponentBase *this, UFG::ActionTreeComponentBase *baseComponent, ActionNodeRoot *currentRoot, __int64 value_uid)
{
  UFG::qBaseNodeVariableRB<unsigned __int64> **v4; // rdi
  int v5; // ebx
  Render::PersistentSkinningCacheNode *v6; // rax
  __int64 v7; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v8; // rcx
  char result; // al

  v4 = (UFG::qBaseNodeVariableRB<unsigned __int64> **)value_uid;
  v5 = (signed int)currentRoot;
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
  *v4 = v8;
  return result;
}

// File Line: 474
// RVA: 0x2972D0
char __fastcall UFG::ActionTreeComponentBase::ActionTreeMemoryData::GetValue(UFG::ActionTreeComponentBase::ActionTreeMemoryData *this, unsigned int value_uid, UFG::qSymbol *value)
{
  __int64 v3; // rdx
  UFG::qSymbol *v4; // rbx
  unsigned int v5; // edx
  unsigned int v6; // ecx
  char v7; // al
  UFG::qWiseSymbol result; // [rsp+38h] [rbp+10h]

  v3 = value_uid - 500000;
  v4 = value;
  if ( (unsigned int)v3 >= this->m_pQSymbolArray.size )
    return 0;
  v5 = this->m_pQSymbolArray.p[v3];
  if ( v5 == -1 )
    return 0;
  v6 = UFG::qSymbol::qSymbol(&result, v5)->mUID;
  v7 = 1;
  v4->mUID = v6;
  return v7;
}

// File Line: 781
// RVA: 0x297370
__int64 __fastcall UFG::ActionTreeComponentBase::MakeValueUID(unsigned int prev_value_uid, UFG::eActionTreeMemoryElementType type)
{
  _DWORD *v2; // r8

  if ( prev_value_uid )
    return prev_value_uid;
  v2 = (_DWORD *)((char *)UFG::ActionTreeComponentBase::s_NumValueUIDs
                + 4
                * ((signed int)type
                 + 11i64 * (signed int)UFG::ActionTreeComponentBase::s_CurrentlyResolvingActionTreeType));
  return (unsigned int)((*v2)++ + 100000 * (type + 1));
}


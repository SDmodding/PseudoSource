// File Line: 47
// RVA: 0x173FC0
UFG::qReflectWarehouse *__fastcall UFG::qReflectWarehouse::Instance()
{
  if ( (_S12 & 1) == 0 )
  {
    _S12 |= 1u;
    sReflectWarehouse.mInventoryTree.mTree.mHead.mUID = 0i64;
    sReflectWarehouse.mInventoryTree.mTree.mHead.mParent = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
    sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[0] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
    sReflectWarehouse.mInventoryTree.mTree.mHead.mChildren[1] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
    sReflectWarehouse.mInventoryTree.mTree.mHead.mNeighbours[0] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
    sReflectWarehouse.mInventoryTree.mTree.mHead.mNeighbours[1] = (UFG::qTree64Base::BaseNode *)&sReflectWarehouse;
    sReflectWarehouse.mInventoryTree.mTree.mCount = 0i64;
    atexit(UFG::qReflectWarehouse::Instance_::_2_::_dynamic_atexit_destructor_for__sReflectWarehouse__);
  }
  return &sReflectWarehouse;
}

// File Line: 53
// RVA: 0x170B40
UFG::qReflectInventoryBase *__fastcall UFG::qReflectWarehouse::GetInventory(
        UFG::qReflectWarehouse *this,
        unsigned __int64 type)
{
  UFG::qReflectWarehouse *v2; // rax

  v2 = (UFG::qReflectWarehouse *)this->mInventoryTree.mTree.mHead.mChildren[0];
  if ( v2 == this )
    return 0i64;
  while ( v2->mInventoryTree.mTree.mHead.mUID < type )
  {
    v2 = (UFG::qReflectWarehouse *)v2->mInventoryTree.mTree.mHead.mChildren[1];
LABEL_6:
    if ( v2 == this )
      return 0i64;
  }
  if ( v2->mInventoryTree.mTree.mHead.mUID > type )
  {
    v2 = (UFG::qReflectWarehouse *)v2->mInventoryTree.mTree.mHead.mChildren[0];
    goto LABEL_6;
  }
  return (UFG::qReflectInventoryBase *)&v2[-1].mInventoryTree.mTree.mCount;
}

// File Line: 58
// RVA: 0x165720
void __fastcall UFG::qReflectWarehouse::Add(UFG::qReflectWarehouse *this, UFG::qReflectInventoryBase *inventory)
{
  UFG::qTree64Base::Add(&this->mInventoryTree.mTree, &inventory->mBaseNode);
}

// File Line: 68
// RVA: 0x14680C0
__int64 UFG::_dynamic_initializer_for__gRootInventory__()
{
  const char *v0; // r9
  unsigned __int64 v1; // r8
  char v2; // al
  UFG::qReflectWarehouse *v3; // rax

  v0 = "UFG::qReflectObject";
  v1 = -1i64;
  v2 = 85;
  do
  {
    v1 = (v1 >> 8) ^ sCrcTable64[(unsigned __int8)(v1 ^ v2)];
    v2 = *++v0;
  }
  while ( *v0 );
  UFG::qReflectInventoryBase::qReflectInventoryBase(&UFG::gRootInventory, "UFG::qReflectObject", v1);
  UFG::gRootInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::qReflectObject>::`vftable;
  UFG::qReflectInventory<UFG::qReflectObject>::OnAddToWarehouse(&UFG::gRootInventory);
  v3 = UFG::qReflectWarehouse::Instance();
  UFG::qTree64Base::Add(&v3->mInventoryTree.mTree, &stru_14235A7B8);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gRootInventory__);
}

// File Line: 97
// RVA: 0x161940
void __fastcall UFG::qReflectInventoryBase::qReflectInventoryBase(
        UFG::qReflectInventoryBase *this,
        const char *name,
        unsigned __int64 type_uid)
{
  UFG::qTreeNode64<UFG::qReflectInventoryBase,UFG::qReflectInventoryBase> *v5; // rbx

  v5 = &this->UFG::qTreeNode64<UFG::qReflectInventoryBase,UFG::qReflectInventoryBase>;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventoryBase::`vftable;
  this->mName = name;
  this->mItems.mTree.mHead.mUID = 0i64;
  this->mItems.mTree.mHead.mParent = &this->mItems.mTree.mHead;
  this->mItems.mTree.mHead.mChildren[0] = &this->mItems.mTree.mHead;
  this->mItems.mTree.mHead.mChildren[1] = &this->mItems.mTree.mHead;
  this->mItems.mTree.mHead.mNeighbours[0] = &this->mItems.mTree.mHead;
  this->mItems.mTree.mHead.mNeighbours[1] = &this->mItems.mTree.mHead;
  this->mItems.mTree.mCount = 0i64;
  this->mNameLookups.mTree.mHead.mUID = 0i64;
  this->mNameLookups.mTree.mHead.mParent = &this->mNameLookups.mTree.mHead;
  this->mNameLookups.mTree.mHead.mChildren[0] = &this->mNameLookups.mTree.mHead;
  this->mNameLookups.mTree.mHead.mChildren[1] = &this->mNameLookups.mTree.mHead;
  this->mNameLookups.mTree.mHead.mNeighbours[0] = &this->mNameLookups.mTree.mHead;
  this->mNameLookups.mTree.mHead.mNeighbours[1] = &this->mNameLookups.mTree.mHead;
  this->mNameLookups.mTree.mCount = 0i64;
  this->mNameObjectLookups.mTree.mHead.mUID = 0i64;
  this->mNameObjectLookups.mTree.mHead.mParent = &this->mNameObjectLookups.mTree.mHead;
  this->mNameObjectLookups.mTree.mHead.mChildren[0] = &this->mNameObjectLookups.mTree.mHead;
  this->mNameObjectLookups.mTree.mHead.mChildren[1] = &this->mNameObjectLookups.mTree.mHead;
  this->mNameObjectLookups.mTree.mHead.mNeighbours[0] = &this->mNameObjectLookups.mTree.mHead;
  this->mNameObjectLookups.mTree.mHead.mNeighbours[1] = &this->mNameObjectLookups.mTree.mHead;
  this->mNameObjectLookups.mTree.mCount = 0i64;
  `eh vector constructor iterator(
    this->mUnBoundHandles,
    0x10ui64,
    8,
    (void (__fastcall *)(void *))UFG::qReflectHandleBase::qReflectHandleBase);
  this->mBaseClassInventory = 0i64;
  this->mDerivedInventories.p = 0i64;
  *(_QWORD *)&this->mDerivedInventories.size = 0i64;
  *(_QWORD *)&this->mAddTime = 0i64;
  *(_QWORD *)&this->mUnresolvedTime = 0i64;
  v5->mBaseNode.mUID = type_uid;
}

// File Line: 102
// RVA: 0x1678B0
void __fastcall UFG::qReflectInventoryBase::AttachHandle(
        UFG::qReflectInventoryBase *this,
        UFG::qReflectHandleBase *handle)
{
  unsigned __int64 mNameUID; // rdi
  UFG::qReflectObject *Object; // rax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *mPrev; // rcx
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v7; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v8; // rax

  mNameUID = handle->mNameUID;
  Object = UFG::qReflectInventoryBase::FindObject(this, mNameUID);
  if ( Object )
  {
    mPrev = Object->mHandles.mNode.mPrev;
    mPrev->mNext = handle;
    handle->mPrev = mPrev;
    handle->mNext = &Object->mHandles.mNode;
    Object->mHandles.mNode.mPrev = handle;
    handle->mData = Object;
  }
  else
  {
    v7 = &this->mUnBoundHandles[mNameUID & 7];
    v8 = v7->mNode.mPrev;
    v8->mNext = handle;
    handle->mPrev = v8;
    handle->mNext = &v7->mNode;
    v7->mNode.mPrev = handle;
    handle->mData = 0i64;
  }
}

// File Line: 119
// RVA: 0x1654D0
void __fastcall UFG::qReflectInventoryBase::Add(UFG::qReflectInventoryBase *this, UFG::qReflectObject *data)
{
  UFG::qReflectInventoryBase *v4; // rcx
  UFG::qTree64<UFG::qReflectObject,UFG::qReflectObject,0> *p_mItems; // rbp
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v6; // r14
  UFG::qReflectInventoryBase *i; // rax
  UFG::qReflectInventoryBase *v8; // r9
  unsigned __int64 v9; // rcx
  __int64 v10; // rdx
  unsigned __int64 v11; // rax
  unsigned __int64 j; // rcx
  char v13; // cl
  UFG::qReflectInventoryBase *v14; // rdi
  UFG::qTree64Base::BaseNode *p_mBaseNode; // rbx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *mParent; // r8
  UFG::qTree64<UFG::qReflectObject,UFG::qReflectObject,0> *v17; // r9
  unsigned int v18; // esi
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *mPrev; // rax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *mNext; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v21; // rax

  if ( sHotSwapModeEnabled )
  {
    UFG::qReflectOnDemandLoader::LoadCachedReferences(data);
    v4 = (UFG::qReflectInventoryBase *)this->mItems.mTree.mHead.mChildren[0];
    p_mItems = &this->mItems;
    v6 = &this->mUnBoundHandles[data->mBaseNode.mUID & 7];
    if ( v4 != (UFG::qReflectInventoryBase *)&this->mItems )
    {
      for ( i = (UFG::qReflectInventoryBase *)v4->mBaseNode.mParent;
            i != (UFG::qReflectInventoryBase *)p_mItems;
            i = (UFG::qReflectInventoryBase *)i->mBaseNode.mParent )
      {
        v4 = i;
      }
      v8 = (UFG::qReflectInventoryBase *)((char *)v4 - 8);
      if ( v4 != (UFG::qReflectInventoryBase *)8 )
      {
        do
        {
          v9 = (unsigned __int64)v8->mBaseNode.mNeighbours[1];
          v10 = *(_QWORD *)(v9 + 8);
          if ( (v10 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          {
            v11 = *(_QWORD *)(v9 + 24);
            if ( v11 == *(_QWORD *)(v11 + 24) )
            {
              v11 = *(_QWORD *)(v9 + 8) & 0xFFFFFFFFFFFFFFFCui64;
              if ( (v10 & 2) != 0 )
              {
                do
                {
                  v13 = (unsigned __int8)*(_DWORD *)(v11 + 8) >> 1;
                  v11 = *(_QWORD *)(v11 + 8) & 0xFFFFFFFFFFFFFFFCui64;
                }
                while ( (v13 & 1) != 0 );
              }
            }
            else
            {
              for ( j = *(_QWORD *)(v11 + 16); j != *(_QWORD *)(j + 24); j = *(_QWORD *)(j + 16) )
                v11 = j;
            }
            v9 = 0i64;
            if ( (UFG::qTree64<UFG::qReflectObject,UFG::qReflectObject,0> *)v11 != p_mItems )
              v9 = v11;
          }
          v14 = (UFG::qReflectInventoryBase *)(v9 - 8);
          if ( !v9 )
            v14 = 0i64;
          p_mBaseNode = &v8->mBaseNode;
          if ( v8->mBaseNode.mUID == data->mBaseNode.mUID )
          {
            mParent = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)v8->mItems.mTree.mHead.mParent;
            v17 = &v8->mItems;
            v18 = ~LODWORD(p_mBaseNode->mUID);
            if ( mParent != (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)v17 )
            {
              do
              {
                mPrev = mParent->mPrev;
                mNext = mParent->mNext;
                mPrev->mNext = mNext;
                mNext->mPrev = mPrev;
                mParent->mPrev = mParent;
                mParent->mNext = mParent;
                mParent[2].mPrev = 0i64;
                v21 = v6->mNode.mNext;
                v6->mNode.mNext = mParent;
                mParent->mNext = v21;
                mParent->mPrev = &v6->mNode;
                v21->mPrev = mParent;
                mParent = mNext;
              }
              while ( mNext != (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)v17 );
            }
            UFG::qTree64Base::Remove(&this->mItems.mTree, p_mBaseNode);
            p_mBaseNode->mUID = v18;
            UFG::qTree64Base::Add(&this->mItems.mTree, p_mBaseNode);
          }
          v8 = v14;
        }
        while ( v14 );
      }
    }
  }
  if ( UFG::qReflectInventoryBase::sFilterFunc(data) )
  {
    UFG::qTree64Base::Add(&this->mItems.mTree, &data->mBaseNode);
    UFG::qReflectInventoryBase::BindHandles(this, data);
  }
}

// File Line: 186
// RVA: 0x1663D0
void __fastcall UFG::qReflectInventoryBase::AddLookup(
        UFG::qReflectInventoryBase *this,
        UFG::qReflectInventoryBase::NameLookup *name_lookup,
        UFG::qReflectInventoryBase::ObjectLookup *object_lookup)
{
  UFG::qTree64Base::Add(&this->mNameLookups.mTree, &name_lookup->mBaseNode);
  UFG::qTree64Base::Add(&this->mNameObjectLookups.mTree, &object_lookup->mBaseNode);
}

// File Line: 198
// RVA: 0x16E200
char *__fastcall UFG::qReflectInventoryBase::FindObjectName(
        UFG::qReflectInventoryBase *this,
        UFG::qReflectInventoryBaseVtbl *name_uid)
{
  UFG::qReflectInventoryBase *mParent; // rax
  unsigned int size; // r11d
  int v4; // r9d
  UFG::qReflectInventoryBase **i; // r10
  __int64 p_mNameLookups; // r8

  mParent = (UFG::qReflectInventoryBase *)this->mNameLookups.mTree.mHead.mChildren[0];
  while ( mParent != (UFG::qReflectInventoryBase *)&this->mNameLookups )
  {
    if ( mParent->vfptr >= name_uid )
    {
      if ( mParent->vfptr <= name_uid )
        goto LABEL_8;
      mParent = (UFG::qReflectInventoryBase *)mParent->mBaseNode.mParent;
    }
    else
    {
      mParent = (UFG::qReflectInventoryBase *)mParent->mBaseNode.mChildren[0];
    }
  }
  mParent = 0i64;
LABEL_8:
  if ( !mParent )
  {
    size = this->mDerivedInventories.size;
    v4 = 0;
    if ( !size )
      return &customCaption;
    for ( i = this->mDerivedInventories.p; ; ++i )
    {
      p_mNameLookups = (__int64)&(*i)->mNameLookups;
      mParent = (UFG::qReflectInventoryBase *)(*i)->mNameLookups.mTree.mHead.mChildren[0];
      while ( mParent != (UFG::qReflectInventoryBase *)p_mNameLookups )
      {
        if ( mParent->vfptr >= name_uid )
        {
          if ( mParent->vfptr <= name_uid )
            goto LABEL_18;
          mParent = (UFG::qReflectInventoryBase *)mParent->mBaseNode.mParent;
        }
        else
        {
          mParent = (UFG::qReflectInventoryBase *)mParent->mBaseNode.mChildren[0];
        }
      }
      mParent = 0i64;
LABEL_18:
      if ( mParent )
        break;
      if ( ++v4 >= size )
        return &customCaption;
    }
  }
  return (char *)mParent->mBaseNode.mNeighbours[1];
}

// File Line: 220
// RVA: 0x16E060
UFG::qReflectObject *__fastcall UFG::qReflectInventoryBase::FindObject(
        UFG::qReflectInventoryBase *this,
        UFG::qReflectInventoryBaseVtbl *name_uid)
{
  UFG::qReflectInventoryBase *mParent; // rax
  unsigned int v4; // ebx
  UFG::qReflectObject *result; // rax
  unsigned int size; // ebp
  __int64 v7; // rdi
  UFG::qReflectInventoryBase *v8; // [rsp+30h] [rbp+8h]

  v8 = this;
  mParent = (UFG::qReflectInventoryBase *)this->mItems.mTree.mHead.mChildren[0];
  v4 = 0;
  while ( mParent != (UFG::qReflectInventoryBase *)&this->mItems )
  {
    if ( mParent->vfptr >= name_uid )
    {
      if ( mParent->vfptr <= name_uid )
      {
        result = (UFG::qReflectObject *)&mParent[-1].mUnresolvedTime;
        if ( result )
          return result;
        goto LABEL_8;
      }
      mParent = (UFG::qReflectInventoryBase *)mParent->mBaseNode.mParent;
    }
    else
    {
      mParent = (UFG::qReflectInventoryBase *)mParent->mBaseNode.mChildren[0];
    }
  }
  result = 0i64;
LABEL_8:
  size = this->mDerivedInventories.size;
  if ( size )
  {
    v7 = 0i64;
    do
    {
      result = UFG::qReflectInventoryBase::FindObject(this->mDerivedInventories.p[v7], (unsigned __int64)name_uid);
      if ( result )
        break;
      this = v8;
      ++v4;
      ++v7;
    }
    while ( v4 < size );
  }
  return result;
}

// File Line: 238
// RVA: 0x16E110
UFG::qReflectObject *__fastcall UFG::qReflectInventoryBase::FindObjectByName(
        UFG::qReflectInventoryBase *this,
        char *name)
{
  unsigned __int64 v2; // r8
  char i; // al
  UFG::qTree64<UFG::qReflectInventoryBase::ObjectLookup,UFG::qReflectInventoryBase::ObjectLookup,0> *p_mNameObjectLookups; // rcx
  UFG::qTree64Base::BaseNode *v6; // rdx
  unsigned int size; // r11d
  int v8; // r9d
  UFG::qReflectInventoryBase **j; // r10
  __int64 v10; // rcx

  v2 = -1i64;
  if ( name )
  {
    for ( i = *name; *name; i = *name )
    {
      ++name;
      v2 = (v2 >> 8) ^ sCrcTable64[(unsigned __int8)(v2 ^ i)];
    }
  }
  p_mNameObjectLookups = &this->mNameObjectLookups;
  v6 = this->mNameObjectLookups.mTree.mHead.mChildren[0];
  if ( v6 != (UFG::qTree64Base::BaseNode *)&this->mNameObjectLookups )
  {
    do
    {
      if ( v6->mUID >= v2 )
      {
        if ( v6->mUID <= v2 )
          goto LABEL_11;
        v6 = v6->mChildren[0];
      }
      else
      {
        v6 = v6->mChildren[1];
      }
    }
    while ( v6 != (UFG::qTree64Base::BaseNode *)p_mNameObjectLookups );
  }
  v6 = 0i64;
LABEL_11:
  if ( !v6 )
  {
    size = this->mDerivedInventories.size;
    v8 = 0;
    if ( !size )
      return 0i64;
    for ( j = this->mDerivedInventories.p; ; ++j )
    {
      v10 = (__int64)&(*j)->mNameObjectLookups;
      v6 = (*j)->mNameObjectLookups.mTree.mHead.mChildren[0];
      while ( v6 != (UFG::qTree64Base::BaseNode *)v10 )
      {
        if ( v6->mUID >= v2 )
        {
          if ( v6->mUID <= v2 )
            goto LABEL_21;
          v6 = v6->mChildren[0];
        }
        else
        {
          v6 = v6->mChildren[1];
        }
      }
      v6 = 0i64;
LABEL_21:
      if ( v6 )
        break;
      if ( ++v8 >= size )
        return 0i64;
    }
  }
  return UFG::qReflectInventoryBase::FindObject(this, (UFG::qReflectInventoryBaseVtbl *)v6[1].mUID);
}

// File Line: 261
// RVA: 0x1679C0
void __fastcall UFG::qReflectInventoryBase::BindHandles(
        UFG::qReflectInventoryBase *this,
        UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *data)
{
  unsigned __int64 mNext; // r10
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v4; // r9
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *p_mNode; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v6; // r8
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v8; // rcx

  do
  {
    mNext = (unsigned __int64)data->mNext;
    v4 = &this->mUnBoundHandles[mNext & 7];
    p_mNode = v4->mNode.mNext;
    if ( p_mNode != (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)v4 )
    {
      do
      {
        v6 = (UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)p_mNode->mNext;
        if ( p_mNode[1].mNext == (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)mNext )
        {
          mPrev = p_mNode->mPrev;
          mPrev->mNext = &v6->mNode;
          v6->mNode.mPrev = mPrev;
          p_mNode->mPrev = p_mNode;
          p_mNode->mNext = p_mNode;
          p_mNode[2].mPrev = data;
          v8 = data[4].mPrev;
          v8->mNext = p_mNode;
          p_mNode->mPrev = v8;
          p_mNode->mNext = data + 4;
          data[4].mPrev = p_mNode;
        }
        p_mNode = &v6->mNode;
      }
      while ( v6 != v4 );
    }
    this = this->mBaseClassInventory;
  }
  while ( this );
}

// File Line: 295
// RVA: 0x17A260
void __fastcall UFG::qReflectInventoryBase::Remove(UFG::qReflectInventoryBase *this, UFG::qReflectObject *data)
{
  unsigned int mUID; // ebx
  UFG::qReflectObject *Object; // rdi
  UFG::qReflectHandleBase *mNext; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *mPrev; // r8
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v8; // rdx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v9; // rax

  if ( UFG::qReflectInventoryBase::sFilterFunc(data) )
  {
    mUID = data->mBaseNode.mUID;
    UFG::qTree64Base::Remove(&this->mItems.mTree, &data->mBaseNode);
    Object = UFG::qReflectInventoryBase::FindObject(this, (UFG::qReflectInventoryBaseVtbl *)mUID);
    while ( (UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)data->mHandles.mNode.mNext != &data->mHandles )
    {
      mNext = (UFG::qReflectHandleBase *)data->mHandles.mNode.mNext;
      mPrev = mNext->mPrev;
      v8 = mNext->mNext;
      mPrev->mNext = v8;
      v8->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      if ( Object )
      {
        v9 = Object->mHandles.mNode.mPrev;
        v9->mNext = mNext;
        mNext->mPrev = v9;
        mNext->mNext = &Object->mHandles.mNode;
        Object->mHandles.mNode.mPrev = mNext;
        mNext->mData = Object;
      }
      else
      {
        UFG::qReflectHandleBase::Init(mNext, mNext->mTypeUID, mNext->mNameUID);
      }
    }
  }
}


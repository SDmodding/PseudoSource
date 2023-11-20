// File Line: 47
// RVA: 0x173FC0
UFG::qReflectWarehouse *__fastcall UFG::qReflectWarehouse::Instance()
{
  if ( !(_S12 & 1) )
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
UFG::qReflectInventoryBase *__fastcall UFG::qReflectWarehouse::GetInventory(UFG::qReflectWarehouse *this, unsigned __int64 type)
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
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::gRootInventory.vfptr,
    "UFG::qReflectObject",
    v1);
  UFG::gRootInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::qReflectObject>::`vftable;
  UFG::qReflectInventory<UFG::qReflectObject>::OnAddToWarehouse(&UFG::gRootInventory);
  v3 = UFG::qReflectWarehouse::Instance();
  UFG::qTree64Base::Add(&v3->mInventoryTree.mTree, &stru_14235A7B8);
  return atexit(UFG::_dynamic_atexit_destructor_for__gRootInventory__);
}

// File Line: 97
// RVA: 0x161940
void __fastcall UFG::qReflectInventoryBase::qReflectInventoryBase(UFG::qReflectInventoryBase *this, const char *name, unsigned __int64 type_uid)
{
  unsigned __int64 v3; // rdi
  UFG::qReflectInventoryBase *v4; // rsi
  UFG::qTreeNode64<UFG::qReflectInventoryBase,UFG::qReflectInventoryBase> *v5; // rbx
  UFG::qTree64<UFG::qReflectObject,UFG::qReflectObject,0> *v6; // rax
  UFG::qTree64<UFG::qReflectInventoryBase::NameLookup,UFG::qReflectInventoryBase::NameLookup,0> *v7; // rax
  UFG::qTree64<UFG::qReflectInventoryBase::ObjectLookup,UFG::qReflectInventoryBase::ObjectLookup,0> *v8; // rax

  v3 = type_uid;
  v4 = this;
  v5 = (UFG::qTreeNode64<UFG::qReflectInventoryBase,UFG::qReflectInventoryBase> *)&this->mBaseNode;
  v5->mBaseNode.mUID = 0i64;
  v5->mBaseNode.mParent = &v5->mBaseNode;
  v5->mBaseNode.mChildren[0] = &v5->mBaseNode;
  v5->mBaseNode.mChildren[1] = &v5->mBaseNode;
  v5->mBaseNode.mNeighbours[0] = &v5->mBaseNode;
  v5->mBaseNode.mNeighbours[1] = &v5->mBaseNode;
  this->vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventoryBase::`vftable;
  this->mName = name;
  v6 = &this->mItems;
  v6->mTree.mHead.mUID = 0i64;
  v6->mTree.mHead.mParent = &v6->mTree.mHead;
  v6->mTree.mHead.mChildren[0] = &v6->mTree.mHead;
  v6->mTree.mHead.mChildren[1] = &v6->mTree.mHead;
  v6->mTree.mHead.mNeighbours[0] = &v6->mTree.mHead;
  v6->mTree.mHead.mNeighbours[1] = &v6->mTree.mHead;
  v6->mTree.mCount = 0i64;
  v7 = &this->mNameLookups;
  v7->mTree.mHead.mUID = 0i64;
  v7->mTree.mHead.mParent = &v7->mTree.mHead;
  v7->mTree.mHead.mChildren[0] = &v7->mTree.mHead;
  v7->mTree.mHead.mChildren[1] = &v7->mTree.mHead;
  v7->mTree.mHead.mNeighbours[0] = &v7->mTree.mHead;
  v7->mTree.mHead.mNeighbours[1] = &v7->mTree.mHead;
  v7->mTree.mCount = 0i64;
  v8 = &this->mNameObjectLookups;
  v8->mTree.mHead.mUID = 0i64;
  v8->mTree.mHead.mParent = &v8->mTree.mHead;
  v8->mTree.mHead.mChildren[0] = &v8->mTree.mHead;
  v8->mTree.mHead.mChildren[1] = &v8->mTree.mHead;
  v8->mTree.mHead.mNeighbours[0] = &v8->mTree.mHead;
  v8->mTree.mHead.mNeighbours[1] = &v8->mTree.mHead;
  v8->mTree.mCount = 0i64;
  `eh vector constructor iterator(
    this->mUnBoundHandles,
    0x10ui64,
    8,
    (void (__fastcall *)(void *))UFG::qReflectHandleBase::qReflectHandleBase);
  v4->mBaseClassInventory = 0i64;
  v4->mDerivedInventories.p = 0i64;
  *(_QWORD *)&v4->mDerivedInventories.size = 0i64;
  *(_QWORD *)&v4->mAddTime = 0i64;
  *(_QWORD *)&v4->mUnresolvedTime = 0i64;
  v5->mBaseNode.mUID = v3;
}

// File Line: 102
// RVA: 0x1678B0
void __fastcall UFG::qReflectInventoryBase::AttachHandle(UFG::qReflectInventoryBase *this, UFG::qReflectHandleBase *handle)
{
  unsigned __int64 v2; // rdi
  UFG::qReflectHandleBase *v3; // rbx
  UFG::qReflectInventoryBase *v4; // rsi
  UFG::qReflectObject *v5; // rax
  UFG::qReflectObject *v6; // rdx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v7; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v8; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v9; // rax

  v2 = handle->mNameUID;
  v3 = handle;
  v4 = this;
  v5 = UFG::qReflectInventoryBase::FindObject(this, handle->mNameUID);
  v6 = v5;
  if ( v5 )
  {
    v7 = v5->mHandles.mNode.mPrev;
    v7->mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v3->mPrev;
    v3->mPrev = v7;
    v3->mNext = &v5->mHandles.mNode;
    v5->mHandles.mNode.mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v3->mPrev;
    v3->mData = v5;
  }
  else
  {
    v8 = &v4->mUnBoundHandles[v2 & 7].mNode;
    v9 = v8->mPrev;
    v9->mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v3->mPrev;
    v3->mPrev = v9;
    v3->mNext = v8;
    v8->mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v3->mPrev;
    v3->mData = v6;
  }
}

// File Line: 119
// RVA: 0x1654D0
void __fastcall UFG::qReflectInventoryBase::Add(UFG::qReflectInventoryBase *this, UFG::qReflectObject *data)
{
  UFG::qReflectObject *v2; // r15
  UFG::qReflectInventoryBase *v3; // r13
  UFG::qReflectInventoryBase *v4; // rcx
  signed __int64 v5; // rbp
  signed __int64 v6; // r14
  UFG::qReflectInventoryBase *i; // rax
  _QWORD *v8; // r9
  unsigned __int64 v9; // rcx
  __int64 v10; // rdx
  unsigned __int64 v11; // rax
  unsigned __int64 j; // rcx
  char v13; // cl
  signed __int64 v14; // rdi
  UFG::qTree64Base::BaseNode *v15; // rbx
  signed __int64 *v16; // r8
  signed __int64 v17; // r9
  unsigned int v18; // esi
  signed __int64 v19; // rax
  signed __int64 *v20; // rcx
  signed __int64 **v21; // rax

  v2 = data;
  v3 = this;
  if ( sHotSwapModeEnabled )
  {
    UFG::qReflectOnDemandLoader::LoadCachedReferences(data);
    v4 = (UFG::qReflectInventoryBase *)v3->mItems.mTree.mHead.mChildren[0];
    v5 = (signed __int64)&v3->mItems;
    v6 = (signed __int64)&v3->mUnBoundHandles[v2->mBaseNode.mUID & 7];
    if ( v4 != (UFG::qReflectInventoryBase *)&v3->mItems )
    {
      for ( i = (UFG::qReflectInventoryBase *)v4->mBaseNode.mParent;
            i != (UFG::qReflectInventoryBase *)v5;
            i = (UFG::qReflectInventoryBase *)i->mBaseNode.mParent )
      {
        v4 = i;
      }
      v8 = (_QWORD *)&v4[-1].mUnresolvedTime;
      if ( v4 != (UFG::qReflectInventoryBase *)8 )
      {
        do
        {
          v9 = v8[6];
          v10 = *(_QWORD *)(v9 + 8);
          if ( *(_QWORD *)(v9 + 8) & 0xFFFFFFFFFFFFFFFCui64 )
          {
            v11 = *(_QWORD *)(v9 + 24);
            if ( v11 == *(_QWORD *)(v11 + 24) )
            {
              v11 = *(_QWORD *)(v9 + 8) & 0xFFFFFFFFFFFFFFFCui64;
              if ( ((unsigned __int8)v10 >> 1) & 1 )
              {
                do
                {
                  v13 = (unsigned __int8)*(_DWORD *)(v11 + 8) >> 1;
                  v11 = *(_QWORD *)(v11 + 8) & 0xFFFFFFFFFFFFFFFCui64;
                }
                while ( v13 & 1 );
              }
            }
            else
            {
              for ( j = *(_QWORD *)(v11 + 16); j != *(_QWORD *)(j + 24); j = *(_QWORD *)(j + 16) )
                v11 = j;
            }
            v9 = 0i64;
            if ( v11 != v5 )
              v9 = v11;
          }
          v14 = v9 - 8;
          if ( !v9 )
            v14 = 0i64;
          v15 = (UFG::qTree64Base::BaseNode *)(v8 + 1);
          if ( v8[1] == v2->mBaseNode.mUID )
          {
            v16 = (signed __int64 *)v8[9];
            v17 = (signed __int64)(v8 + 8);
            v18 = ~LODWORD(v15->mUID);
            if ( v16 != (signed __int64 *)v17 )
            {
              do
              {
                v19 = *v16;
                v20 = (signed __int64 *)v16[1];
                *(_QWORD *)(v19 + 8) = v20;
                *v20 = v19;
                *v16 = (signed __int64)v16;
                v16[1] = (signed __int64)v16;
                v16[4] = 0i64;
                v21 = *(signed __int64 ***)(v6 + 8);
                *(_QWORD *)(v6 + 8) = v16;
                v16[1] = (signed __int64)v21;
                *v16 = v6;
                *v21 = v16;
                v16 = v20;
              }
              while ( v20 != (signed __int64 *)v17 );
            }
            UFG::qTree64Base::Remove(&v3->mItems.mTree, v15);
            v15->mUID = v18;
            UFG::qTree64Base::Add(&v3->mItems.mTree, v15);
          }
          v8 = (_QWORD *)v14;
        }
        while ( v14 );
      }
    }
  }
  if ( UFG::qReflectInventoryBase::sFilterFunc(v2) )
  {
    UFG::qTree64Base::Add(&v3->mItems.mTree, &v2->mBaseNode);
    UFG::qReflectInventoryBase::BindHandles(v3, v2);
  }
}

// File Line: 186
// RVA: 0x1663D0
void __fastcall UFG::qReflectInventoryBase::AddLookup(UFG::qReflectInventoryBase *this, UFG::qReflectInventoryBase::NameLookup *name_lookup, UFG::qReflectInventoryBase::ObjectLookup *object_lookup)
{
  UFG::qReflectInventoryBase *v3; // rbx
  UFG::qReflectInventoryBase::ObjectLookup *v4; // rdi

  v3 = this;
  v4 = object_lookup;
  UFG::qTree64Base::Add(&this->mNameLookups.mTree, &name_lookup->mBaseNode);
  UFG::qTree64Base::Add(&v3->mNameObjectLookups.mTree, &v4->mBaseNode);
}

// File Line: 198
// RVA: 0x16E200
char *__fastcall UFG::qReflectInventoryBase::FindObjectName(UFG::qReflectInventoryBase *this, unsigned __int64 name_uid)
{
  UFG::qReflectInventoryBase *v2; // rax
  unsigned int v3; // er11
  unsigned int v4; // er9
  UFG::qReflectInventoryBase **v5; // r10
  signed __int64 v6; // r8

  v2 = (UFG::qReflectInventoryBase *)this->mNameLookups.mTree.mHead.mChildren[0];
  while ( v2 != (UFG::qReflectInventoryBase *)&this->mNameLookups )
  {
    if ( v2->vfptr >= (UFG::qReflectInventoryBaseVtbl *)name_uid )
    {
      if ( v2->vfptr <= (UFG::qReflectInventoryBaseVtbl *)name_uid )
        goto LABEL_8;
      v2 = (UFG::qReflectInventoryBase *)v2->mBaseNode.mParent;
    }
    else
    {
      v2 = (UFG::qReflectInventoryBase *)v2->mBaseNode.mChildren[0];
    }
  }
  v2 = 0i64;
LABEL_8:
  if ( !v2 )
  {
    v3 = this->mDerivedInventories.size;
    v4 = 0;
    if ( !v3 )
      return &customWorldMapCaption;
    v5 = this->mDerivedInventories.p;
    while ( 1 )
    {
      v6 = (signed __int64)&(*v5)->mNameLookups;
      v2 = (UFG::qReflectInventoryBase *)(*v5)->mNameLookups.mTree.mHead.mChildren[0];
      while ( v2 != (UFG::qReflectInventoryBase *)v6 )
      {
        if ( v2->vfptr >= (UFG::qReflectInventoryBaseVtbl *)name_uid )
        {
          if ( v2->vfptr <= (UFG::qReflectInventoryBaseVtbl *)name_uid )
            goto LABEL_18;
          v2 = (UFG::qReflectInventoryBase *)v2->mBaseNode.mParent;
        }
        else
        {
          v2 = (UFG::qReflectInventoryBase *)v2->mBaseNode.mChildren[0];
        }
      }
      v2 = 0i64;
LABEL_18:
      if ( v2 )
        break;
      ++v4;
      ++v5;
      if ( v4 >= v3 )
        return &customWorldMapCaption;
    }
  }
  return (char *)v2->mBaseNode.mNeighbours[1];
}

// File Line: 220
// RVA: 0x16E060
UFG::qReflectObject *__fastcall UFG::qReflectInventoryBase::FindObject(UFG::qReflectInventoryBase *this, unsigned __int64 name_uid)
{
  UFG::qReflectInventoryBase *v2; // rax
  unsigned __int64 v3; // rsi
  unsigned int v4; // ebx
  UFG::qReflectObject *result; // rax
  unsigned int v6; // ebp
  __int64 v7; // rdi
  UFG::qReflectInventoryBase *v8; // [rsp+30h] [rbp+8h]

  v8 = this;
  v2 = (UFG::qReflectInventoryBase *)this->mItems.mTree.mHead.mChildren[0];
  v3 = name_uid;
  v4 = 0;
  while ( v2 != (UFG::qReflectInventoryBase *)&this->mItems )
  {
    if ( v2->vfptr >= (UFG::qReflectInventoryBaseVtbl *)name_uid )
    {
      if ( v2->vfptr <= (UFG::qReflectInventoryBaseVtbl *)name_uid )
      {
        result = (UFG::qReflectObject *)&v2[-1].mUnresolvedTime;
        if ( result )
          return result;
        goto LABEL_8;
      }
      v2 = (UFG::qReflectInventoryBase *)v2->mBaseNode.mParent;
    }
    else
    {
      v2 = (UFG::qReflectInventoryBase *)v2->mBaseNode.mChildren[0];
    }
  }
  result = 0i64;
LABEL_8:
  v6 = this->mDerivedInventories.size;
  if ( v6 )
  {
    v7 = 0i64;
    do
    {
      result = UFG::qReflectInventoryBase::FindObject(this->mDerivedInventories.p[v7], v3);
      if ( result )
        break;
      this = v8;
      ++v4;
      ++v7;
    }
    while ( v4 < v6 );
  }
  return result;
}

// File Line: 238
// RVA: 0x16E110
UFG::qReflectObject *__fastcall UFG::qReflectInventoryBase::FindObjectByName(UFG::qReflectInventoryBase *this, const char *name)
{
  unsigned __int64 v2; // r8
  UFG::qReflectInventoryBase *v3; // rbx
  char i; // al
  UFG::qTree64<UFG::qReflectInventoryBase::ObjectLookup,UFG::qReflectInventoryBase::ObjectLookup,0> *v5; // rcx
  UFG::qTree64<UFG::qReflectInventoryBase::ObjectLookup,UFG::qReflectInventoryBase::ObjectLookup,0> *v6; // rdx
  unsigned int v7; // er11
  unsigned int v8; // er9
  UFG::qReflectInventoryBase **v9; // r10
  signed __int64 v10; // rcx

  v2 = -1i64;
  v3 = this;
  if ( name )
  {
    for ( i = *name; *name; i = *name )
    {
      ++name;
      v2 = (v2 >> 8) ^ sCrcTable64[(unsigned __int8)(v2 ^ i)];
    }
  }
  v5 = &this->mNameObjectLookups;
  v6 = (UFG::qTree64<UFG::qReflectInventoryBase::ObjectLookup,UFG::qReflectInventoryBase::ObjectLookup,0> *)v3->mNameObjectLookups.mTree.mHead.mChildren[0];
  if ( v6 != &v3->mNameObjectLookups )
  {
    do
    {
      if ( v6->mTree.mHead.mUID >= v2 )
      {
        if ( v6->mTree.mHead.mUID <= v2 )
          goto LABEL_11;
        v6 = (UFG::qTree64<UFG::qReflectInventoryBase::ObjectLookup,UFG::qReflectInventoryBase::ObjectLookup,0> *)v6->mTree.mHead.mChildren[0];
      }
      else
      {
        v6 = (UFG::qTree64<UFG::qReflectInventoryBase::ObjectLookup,UFG::qReflectInventoryBase::ObjectLookup,0> *)v6->mTree.mHead.mChildren[1];
      }
    }
    while ( v6 != v5 );
  }
  v6 = 0i64;
LABEL_11:
  if ( !v6 )
  {
    v7 = v3->mDerivedInventories.size;
    v8 = 0;
    if ( !v7 )
      return 0i64;
    v9 = v3->mDerivedInventories.p;
    while ( 1 )
    {
      v10 = (signed __int64)&(*v9)->mNameObjectLookups;
      v6 = (UFG::qTree64<UFG::qReflectInventoryBase::ObjectLookup,UFG::qReflectInventoryBase::ObjectLookup,0> *)(*v9)->mNameObjectLookups.mTree.mHead.mChildren[0];
      while ( v6 != (UFG::qTree64<UFG::qReflectInventoryBase::ObjectLookup,UFG::qReflectInventoryBase::ObjectLookup,0> *)v10 )
      {
        if ( v6->mTree.mHead.mUID >= v2 )
        {
          if ( v6->mTree.mHead.mUID <= v2 )
            goto LABEL_21;
          v6 = (UFG::qTree64<UFG::qReflectInventoryBase::ObjectLookup,UFG::qReflectInventoryBase::ObjectLookup,0> *)v6->mTree.mHead.mChildren[0];
        }
        else
        {
          v6 = (UFG::qTree64<UFG::qReflectInventoryBase::ObjectLookup,UFG::qReflectInventoryBase::ObjectLookup,0> *)v6->mTree.mHead.mChildren[1];
        }
      }
      v6 = 0i64;
LABEL_21:
      if ( v6 )
        break;
      ++v8;
      ++v9;
      if ( v8 >= v7 )
        return 0i64;
    }
  }
  return UFG::qReflectInventoryBase::FindObject(v3, v6->mTree.mCount);
}

// File Line: 261
// RVA: 0x1679C0
void __fastcall UFG::qReflectInventoryBase::BindHandles(UFG::qReflectInventoryBase *this, UFG::qReflectObject *data)
{
  UFG::qReflectInventoryBase *v2; // r11
  unsigned __int64 v3; // r10
  unsigned __int64 v4; // r9
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v5; // rax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v6; // r8
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v7; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v8; // rcx

  v2 = this;
  do
  {
    v3 = data->mBaseNode.mUID;
    v4 = (unsigned __int64)&v2->mUnBoundHandles[data->mBaseNode.mUID & 7];
    v5 = *(UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> **)(v4 + 8);
    if ( v5 != (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)v4 )
    {
      do
      {
        v6 = v5->mNext;
        if ( v5[1].mNext == (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)v3 )
        {
          v7 = v5->mPrev;
          v7->mNext = v6;
          v6->mPrev = v7;
          v5->mPrev = v5;
          v5->mNext = v5;
          v5[2].mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)data;
          v8 = data->mHandles.mNode.mPrev;
          v8->mNext = v5;
          v5->mPrev = v8;
          v5->mNext = &data->mHandles.mNode;
          data->mHandles.mNode.mPrev = v5;
        }
        v5 = v6;
      }
      while ( v6 != (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)v4 );
    }
    v2 = v2->mBaseClassInventory;
  }
  while ( v2 );
}

// File Line: 295
// RVA: 0x17A260
void __fastcall UFG::qReflectInventoryBase::Remove(UFG::qReflectInventoryBase *this, UFG::qReflectObject *data)
{
  UFG::qReflectInventoryBase *v2; // rdi
  UFG::qReflectObject *v3; // rsi
  unsigned int v4; // ebx
  UFG::qReflectObject *v5; // rdi
  UFG::qReflectHandleBase *v6; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v7; // r8
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v8; // rdx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v9; // rax

  v2 = this;
  v3 = data;
  if ( UFG::qReflectInventoryBase::sFilterFunc(data) )
  {
    v4 = v3->mBaseNode.mUID;
    UFG::qTree64Base::Remove(&v2->mItems.mTree, &v3->mBaseNode);
    v5 = UFG::qReflectInventoryBase::FindObject(v2, v4);
    while ( (UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)v3->mHandles.mNode.mNext != &v3->mHandles )
    {
      v6 = (UFG::qReflectHandleBase *)v3->mHandles.mNode.mNext;
      v7 = v6->mPrev;
      v8 = v6->mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      v6->mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v6->mPrev;
      v6->mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v6->mPrev;
      if ( v5 )
      {
        v9 = v5->mHandles.mNode.mPrev;
        v9->mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v6->mPrev;
        v6->mPrev = v9;
        v6->mNext = &v5->mHandles.mNode;
        v5->mHandles.mNode.mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v6->mPrev;
        v6->mData = v5;
      }
      else
      {
        UFG::qReflectHandleBase::Init(v6, v6->mTypeUID, v6->mNameUID);
      }
    }
  }
}


// File Line: 66
// RVA: 0x1467E30
__int64 UFG::_dynamic_initializer_for__gInventoryChannel__()
{
  gInventoryChannel.mLogFilename.mPrev = &gInventoryChannel.mLogFilename;
  gInventoryChannel.mLogFilename.mNext = &gInventoryChannel.mLogFilename;
  *(_QWORD *)&gInventoryChannel.mLogFilename.mMagic = 16909060i64;
  gInventoryChannel.mLogFilename.mData = (char *)UFG::qString::sEmptyString;
  *(_QWORD *)&gInventoryChannel.mLogFilename.mStringHash32 = -1i64;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gInventoryChannel__);
}

// File Line: 67
// RVA: 0x1468180
__int64 UFG::_dynamic_initializer_for__gWarehouseChannel__()
{
  gWarehouseChannel.mLogFilename.mPrev = &gWarehouseChannel.mLogFilename;
  gWarehouseChannel.mLogFilename.mNext = &gWarehouseChannel.mLogFilename;
  *(_QWORD *)&gWarehouseChannel.mLogFilename.mMagic = 16909060i64;
  gWarehouseChannel.mLogFilename.mData = (char *)UFG::qString::sEmptyString;
  *(_QWORD *)&gWarehouseChannel.mLogFilename.mStringHash32 = -1i64;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gWarehouseChannel__);
}

// File Line: 73
// RVA: 0x1467FF0
__int64 UFG::_dynamic_initializer_for__gResourceFileUIDContentPrefixHash__()
{
  char v0; // dl
  unsigned int v1; // r8d
  const char *v2; // r10
  unsigned int i; // r9d
  char v4; // al
  __int64 result; // rax
  const char *v6; // r9

  v0 = aStandard_5[0];
  v1 = -1;
  v2 = "Standard:";
  for ( i = -1; v0; i = (i << 8) ^ sCrcTable32[(unsigned __int8)(v4 ^ HIBYTE(i))] )
  {
    if ( v0 <= 122 && v0 >= 97 )
      v0 -= 32;
    v4 = v0;
    v0 = *++v2;
  }
  result = (unsigned __int8)aIllusionTextur_3[0];
  gResourceFileUIDContentPrefixHash[0] = i;
  v6 = "Illusion:Texture:";
  if ( aIllusionTextur_3[0] )
  {
    do
    {
      if ( (char)result <= 122 && (char)result >= 97 )
        LOBYTE(result) = result - 32;
      ++v6;
      v1 = (v1 << 8) ^ sCrcTable32[(unsigned __int8)(result ^ HIBYTE(v1))];
      result = *(unsigned __int8 *)v6;
    }
    while ( (_BYTE)result );
  }
  dword_14235B2D4 = v1;
  return result;
}

// File Line: 78
// RVA: 0x16EE60
__int64 __fastcall UFG::GenerateResourceFileUID(UFG::ResourceFileContentType content_type, const char *file_path)
{
  __int64 v3; // rdi
  char *LastInsensitive; // r8
  char v5; // al
  char *i; // rcx
  char v7; // al
  char *v8; // r9
  unsigned int j; // r8d
  unsigned int v10; // ecx
  unsigned int v11; // r8d
  char v13[264]; // [rsp+20h] [rbp-108h] BYREF

  v3 = content_type;
  LastInsensitive = UFG::qStringFindLastInsensitive(file_path, "data\\");
  if ( !LastInsensitive )
    LastInsensitive = UFG::qStringFindLastInsensitive(file_path, "data/");
  v5 = *LastInsensitive;
  for ( i = v13; v5; ++LastInsensitive )
  {
    if ( v5 != 47 && v5 != 92 )
      *i++ = v5;
    v5 = LastInsensitive[1];
  }
  *i = 0;
  v7 = v13[0];
  v8 = v13;
  for ( j = gResourceFileUIDContentPrefixHash[v3]; *v8; j = v10 ^ v11 )
  {
    if ( v7 <= 122 && v7 >= 97 )
      v7 -= 32;
    ++v8;
    v10 = j << 8;
    v11 = sCrcTable32[(unsigned __int8)(v7 ^ HIBYTE(j))];
    v7 = *v8;
  }
  return j;
}

// File Line: 138
// RVA: 0x1467CC0
__int64 UFG::_dynamic_initializer_for__gChunkFileIndexInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gChunkFileIndexInventory,
    "ChunkFileIndexInventory",
    0xF569FE1B,
    0x7040F7D2u,
    0,
    0);
  UFG::gChunkFileIndexInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::ChunkFileIndexInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gChunkFileIndexInventory__);
}

// File Line: 186
// RVA: 0x1467C60
__int64 UFG::_dynamic_initializer_for__gChunkFileFatIndexInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gChunkFileFatIndexInventory,
    "ChunkFileFatIndexInventory",
    0xE36C885C,
    0xE445B80C,
    0,
    0);
  UFG::gChunkFileFatIndexInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::ChunkFileFatIndexInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gChunkFileFatIndexInventory__);
}

// File Line: 193
// RVA: 0x164FB0
void __fastcall UFG::ChunkFileIndexInventory::Add(
        UFG::ChunkFileIndexInventory *this,
        UFG::qResourceData *resource_data)
{
  if ( resource_data )
  {
    resource_data->mNode.mParent = 0i64;
    resource_data->mNode.mChild[0] = 0i64;
    resource_data->mNode.mChild[1] = 0i64;
    resource_data->mResourceHandles.mNode.mPrev = &resource_data->mResourceHandles.mNode;
    resource_data->mResourceHandles.mNode.mNext = &resource_data->mResourceHandles.mNode;
  }
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 212
// RVA: 0x161BB0
void __fastcall UFG::qResourceHandle::qResourceHandle(UFG::qResourceHandle *this)
{
  this->mPrev = this;
  this->mNext = this;
  this->mData = 0i64;
}

// File Line: 227
// RVA: 0x164090
void __fastcall UFG::qResourceHandle::~qResourceHandle(UFG::qResourceHandle *this)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax

  UFG::qResourceHandle::Close(this);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 247
// RVA: 0x173500
void __fastcall UFG::qResourceHandle::Init(
        UFG::qResourceHandle *this,
        unsigned int type_uid,
        unsigned int name_uid,
        UFG::qResourceData *resource_data,
        UFG::qResourceInventory *inventory)
{
  UFG::qResourceHandle::Close(this);
  if ( inventory )
    (*(void (__fastcall **)(UFG::qResourceInventory *, UFG::qResourceHandle *, _QWORD, UFG::qResourceData *))inventory->vfptr->gap8)(
      inventory,
      this,
      name_uid,
      resource_data);
}

// File Line: 260
// RVA: 0x1734B0
void __fastcall UFG::qResourceHandle::Init(UFG::qResourceHandle *this, unsigned int type_uid, unsigned int name_uid)
{
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceInventory *Inventory; // rax

  UFG::qResourceHandle::Close(this);
  v6 = UFG::qResourceWarehouse::Instance();
  Inventory = UFG::qResourceWarehouse::GetInventory(v6, type_uid);
  if ( Inventory )
    Inventory->vfptr->InitHandle(Inventory, this, name_uid);
}

// File Line: 275
// RVA: 0x173550
void __fastcall UFG::qResourceHandle::Init(
        UFG::qResourceHandle *this,
        unsigned int type_uid,
        unsigned int name_uid,
        UFG::qResourceInventory *inventory)
{
  UFG::qResourceHandle::Close(this);
  if ( inventory )
    inventory->vfptr->InitHandle(inventory, this, name_uid);
}

// File Line: 288
// RVA: 0x167FB0
void __fastcall UFG::qResourceHandle::Close(UFG::qResourceHandle *this)
{
  UFG::qResourceData *mData; // rdi
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // r8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rdx
  UFG::qResourceData *v7; // r8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v9; // rcx

  mData = this->mData;
  if ( mData )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, mData->mTypeUID);
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v7 = this->mData;
    this->mPrev = this;
    this->mNext = this;
    Inventory->vfptr->OnDetachHandle(Inventory, this, v7);
    this->mData = 0i64;
  }
  else
  {
    v8 = this->mNext;
    v9 = this->mPrev;
    v9->mNext = v8;
    v8->mPrev = v9;
    this->mPrev = this;
    this->mNext = this;
  }
}

// File Line: 320
// RVA: 0x167F40
void __fastcall UFG::qResourceHandle::Close(UFG::qResourceHandle *this, UFG::qResourceInventory *inventory)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // r8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax
  UFG::qResourceData *mData; // r8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v6; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rax

  if ( this->mData )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    mData = this->mData;
    this->mPrev = this;
    this->mNext = this;
    inventory->vfptr->OnDetachHandle(inventory, this, mData);
    this->mData = 0i64;
  }
  else
  {
    v6 = this->mPrev;
    v7 = this->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    this->mPrev = this;
    this->mNext = this;
  }
}

// File Line: 349
// RVA: 0x1754B0
bool __fastcall UFG::qResourceHandle::IsDefault(UFG::qResourceHandle *this)
{
  UFG::qResourceData *mData; // rdi
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceData *mDefaultResourceData; // rcx

  mData = this->mData;
  if ( !mData )
    return 0;
  v4 = UFG::qResourceWarehouse::Instance();
  mDefaultResourceData = UFG::qResourceWarehouse::GetInventory(v4, mData->mTypeUID)->mDefaultResourceData;
  return mDefaultResourceData != 0i64 && mDefaultResourceData == this->mData;
}

// File Line: 371
// RVA: 0x161B20
void __fastcall UFG::qResourceData::qResourceData(UFG::qResourceData *this)
{
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mResourceHandles.mNode.mPrev = &this->mResourceHandles.mNode;
  this->mResourceHandles.mNode.mNext = &this->mResourceHandles.mNode;
}

// File Line: 390
// RVA: 0x161B60
void __fastcall UFG::qResourceData::qResourceData(
        UFG::qResourceData *this,
        unsigned int type_uid,
        unsigned int name_uid,
        const char *name)
{
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = name_uid;
  this->mResourceHandles.mNode.mPrev = &this->mResourceHandles.mNode;
  this->mResourceHandles.mNode.mNext = &this->mResourceHandles.mNode;
  this->mTypeUID = type_uid;
  UFG::qResourceData::SetDebugName(this, name);
}

// File Line: 402
// RVA: 0x17CD40
void __fastcall UFG::qResourceData::SetDebugName(UFG::qResourceData *this, const char *name)
{
  char *mDebugName; // rbx
  int v5; // esi
  const char *v6; // rdx
  int v8; // edx
  char v9; // al
  char v10; // al
  char v11; // al
  char v12; // al
  char v13; // al
  const char *v14; // rcx
  int v15; // r8d
  char v16; // al
  char v17; // al
  char v18; // al
  char v19; // al
  char v20; // al
  char *v21; // rcx
  int v22; // r8d
  const char *v23; // rdx
  char v24; // al
  char v25; // al

  mDebugName = this->mDebugName;
  v5 = 36;
  UFG::qMemSet(this->mDebugName, 0, 0x24u);
  if ( name )
  {
    v6 = name;
    while ( *v6++ )
      ;
    v8 = (_DWORD)v6 - (_DWORD)name - 1;
    if ( v8 >= 36 )
    {
      v14 = name;
      v15 = 21;
      if ( mDebugName )
      {
        do
        {
          v16 = *v14;
          *mDebugName++ = *v14;
          if ( !v16 )
            break;
          v17 = v14[1];
          *mDebugName++ = v17;
          if ( !v17 )
            break;
          v18 = v14[2];
          *mDebugName++ = v18;
          if ( !v18 )
            break;
          v19 = v14[3];
          *mDebugName++ = v19;
          if ( !v19 )
            break;
          v20 = v14[4];
          ++mDebugName;
          v14 += 5;
          *(mDebugName - 1) = v20;
          if ( !v20 )
            break;
          v15 -= 5;
        }
        while ( v15 > 1 );
        if ( *(mDebugName - 1) )
          *mDebugName = 0;
      }
      v21 = &this->mDebugName[21];
      this->mDebugName[20] = 126;
      v22 = 15;
      v23 = &name[v8 - 14];
      if ( this != (UFG::qResourceData *)-73i64 )
      {
        if ( !v23 )
          goto LABEL_29;
        do
        {
          v24 = *v23;
          *v21++ = *v23;
          if ( !v24 )
            break;
          v25 = v23[1];
          ++v21;
          v23 += 2;
          *(v21 - 1) = v25;
          if ( !v25 )
            break;
          v22 -= 2;
        }
        while ( v22 > 1 );
        if ( *(v21 - 1) )
LABEL_29:
          *v21 = 0;
      }
    }
    else if ( mDebugName )
    {
      do
      {
        v9 = *name;
        *mDebugName++ = *name;
        if ( !v9 )
          break;
        v10 = name[1];
        *mDebugName++ = v10;
        if ( !v10 )
          break;
        v11 = name[2];
        *mDebugName++ = v11;
        if ( !v11 )
          break;
        v12 = name[3];
        *mDebugName++ = v12;
        if ( !v12 )
          break;
        v13 = name[4];
        ++mDebugName;
        name += 5;
        *(mDebugName - 1) = v13;
        if ( !v13 )
          break;
        v5 -= 5;
      }
      while ( v5 > 1 );
      if ( *(mDebugName - 1) )
        *mDebugName = 0;
    }
  }
}

// File Line: 441
// RVA: 0x161BE0
void __fastcall UFG::qResourceInventory::qResourceInventory(
        UFG::qResourceInventory *this,
        const char *name,
        unsigned int type_uid,
        unsigned int chunk_uid,
        unsigned int default_name_uid,
        unsigned int num_unsolved_hash_lists)
{
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v9; // rbp
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v10; // r15
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *p_mResourceDatas; // rdx
  UFG::qBaseNodeRB *p_mNULL; // rcx
  __int64 v13; // rbx
  bool v14; // cf
  unsigned __int64 v15; // rbx
  UFG::qMemoryPool *v16; // rcx
  char *v17; // rax
  UFG::qResourceWarehouse *v18; // rbx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *mPrev; // rcx

  v9 = 0i64;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = type_uid;
  v10 = &this->UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory>;
  this->mPrev = &this->UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory>;
  this->mNext = &this->UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory>;
  this->vfptr = (UFG::qResourceInventoryVtbl *)&UFG::qResourceInventory::`vftable;
  p_mResourceDatas = &this->mResourceDatas;
  this->mResourceDatas.mTree.mRoot.mParent = 0i64;
  this->mResourceDatas.mTree.mRoot.mChild[0] = 0i64;
  this->mResourceDatas.mTree.mRoot.mChild[1] = 0i64;
  p_mNULL = &this->mResourceDatas.mTree.mNULL;
  p_mNULL->mParent = 0i64;
  p_mNULL->mChild[0] = 0i64;
  p_mNULL->mChild[1] = 0i64;
  p_mNULL->mParent = (UFG::qBaseNodeRB *)((unsigned __int64)p_mNULL | (__int64)p_mNULL->mParent & 1);
  p_mResourceDatas->mTree.mNULL.mChild[0] = p_mNULL;
  p_mResourceDatas->mTree.mNULL.mChild[1] = p_mNULL;
  p_mNULL->mParent = (UFG::qBaseNodeRB *)((unsigned __int64)p_mNULL->mParent & ~1ui64);
  p_mResourceDatas->mTree.mNULL.mUID = 0;
  p_mResourceDatas->mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)p_mNULL | (__int64)p_mResourceDatas->mTree.mRoot.mParent & 1);
  p_mResourceDatas->mTree.mRoot.mChild[0] = p_mNULL;
  p_mResourceDatas->mTree.mRoot.mChild[1] = p_mNULL;
  p_mResourceDatas->mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)p_mResourceDatas->mTree.mRoot.mParent & ~1ui64);
  p_mResourceDatas->mTree.mRoot.mUID = -1;
  p_mResourceDatas->mTree.mCount = 0;
  this->mNullHandles.mNode.mPrev = &this->mNullHandles.mNode;
  this->mNullHandles.mNode.mNext = &this->mNullHandles.mNode;
  `eh vector constructor iterator(
    this->mInternalUnresolvedHandles,
    0x10ui64,
    4,
    (void (__fastcall *)(void *))UFG::qReflectHandleBase::qReflectHandleBase);
  this->mDefaultResourceData = 0i64;
  this->mDefaultResourceNameUID = default_name_uid;
  this->mChunkUID = chunk_uid;
  this->mName = name;
  this->mUnresolvedHandleLists = this->mInternalUnresolvedHandles;
  *(_QWORD *)&this->mNumUnresolvedHandleLists = 4i64;
  *(_QWORD *)&this->mNumResourceBytes = 0i64;
  *(_QWORD *)&this->mLastUpdate = 0i64;
  *(_QWORD *)&this->mRemoveTime = 0i64;
  *(_QWORD *)&this->mLoadTime = 0i64;
  this->mInitHandleTime = 0.0;
  if ( num_unsolved_hash_lists > 4 )
  {
    v13 = 16i64 * num_unsolved_hash_lists;
    if ( !is_mul_ok(num_unsolved_hash_lists, 0x10ui64) )
      v13 = -1i64;
    v14 = __CFADD__(v13, 8i64);
    v15 = v13 + 8;
    if ( v14 )
      v15 = -1i64;
    v16 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v16 = UFG::gMainMemoryPool;
    }
    v17 = UFG::qMemoryPool::Allocate(v16, v15, "qResourceInventory.Hash", 0i64, 1u);
    if ( v17 )
    {
      *(_DWORD *)v17 = num_unsolved_hash_lists;
      v9 = (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)(v17 + 8);
      `eh vector constructor iterator(
        v17 + 8,
        0x10ui64,
        num_unsolved_hash_lists,
        (void (__fastcall *)(void *))UFG::qReflectHandleBase::qReflectHandleBase);
    }
    this->mUnresolvedHandleLists = v9;
    this->mNumUnresolvedHandleLists = num_unsolved_hash_lists;
  }
  v18 = UFG::qResourceWarehouse::Instance();
  UFG::qBaseTreeRB::Add(&v18->mInventoryTree.mTree, &this->mNode);
  mPrev = v18->mInventoryList.mNode.mPrev;
  mPrev->mNext = v10;
  v10->mPrev = mPrev;
  v10->mNext = &v18->mInventoryList.mNode;
  v18->mInventoryList.mNode.mPrev = v10;
  ++v18->mNumInventories;
}

// File Line: 503
// RVA: 0x1640D0
void __fastcall UFG::qResourceInventory::~qResourceInventory(UFG::qResourceInventory *this)
{
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *p_mResourceDatas; // rdi
  UFG::qBaseNodeRB *p_mNULL; // rcx
  UFG::qResourceInventory *i; // rdx
  UFG::qResourceInventoryVtbl *vfptr; // rcx
  UFG::qBaseNodeRB *mParent; // rax
  unsigned int j; // r9d
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v8; // r8
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *k; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rcx
  UFG::qResourceWarehouse *v12; // rbx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v13; // r14
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v14; // r8
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v15; // rdx
  Render::SkinningCacheNode *Head; // rbx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v17; // rcx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v18; // rax

  this->vfptr = (UFG::qResourceInventoryVtbl *)&UFG::qResourceInventory::`vftable;
  p_mResourceDatas = &this->mResourceDatas;
  p_mNULL = &this->mResourceDatas.mTree.mNULL;
  p_mResourceDatas->mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)p_mNULL | (__int64)p_mResourceDatas->mTree.mRoot.mParent & 1);
  p_mResourceDatas->mTree.mRoot.mChild[0] = p_mNULL;
  p_mResourceDatas->mTree.mRoot.mChild[1] = p_mNULL;
  p_mResourceDatas->mTree.mCount = 0;
  for ( i = (UFG::qResourceInventory *)this->mNullHandles.mNode.mNext;
        i != (UFG::qResourceInventory *)&this->mNullHandles;
        i = (UFG::qResourceInventory *)this->mNullHandles.mNode.mNext )
  {
    vfptr = i->vfptr;
    mParent = i->mNode.mParent;
    *(_QWORD *)vfptr->gap8 = mParent;
    mParent->mParent = (UFG::qBaseNodeRB *)vfptr;
    i->vfptr = (UFG::qResourceInventoryVtbl *)i;
    i->mNode.mParent = (UFG::qBaseNodeRB *)i;
  }
  for ( j = 0; j < this->mNumUnresolvedHandleLists; ++j )
  {
    v8 = &this->mUnresolvedHandleLists[j];
    for ( k = (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)v8->mNode.mNext;
          k != v8;
          k = (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)v8->mNode.mNext )
    {
      mPrev = k->mNode.mPrev;
      mNext = k->mNode.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      k->mNode.mPrev = &k->mNode;
      k->mNode.mNext = &k->mNode;
    }
  }
  v12 = UFG::qResourceWarehouse::Instance();
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)v12,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&this->UFG::qNodeRB<UFG::qResourceInventory>);
  v13 = &this->UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory>;
  v14 = this->mPrev;
  v15 = this->mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  this->mPrev = &this->UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory>;
  this->mNext = &this->UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory>;
  --v12->mNumInventories;
  `eh vector destructor iterator(
    this->mInternalUnresolvedHandles,
    0x10ui64,
    4,
    (void (__fastcall *)(void *))UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::~qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>);
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::~qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>(&this->mNullHandles);
  while ( p_mResourceDatas->mTree.mCount )
  {
    Head = UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1>::GetHead(p_mResourceDatas);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)p_mResourceDatas,
      &Head->mNode);
    if ( Head )
    {
      UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::~qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>((UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)&Head->mCachedBufferPtr);
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, Head);
    }
  }
  p_mResourceDatas->mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&p_mResourceDatas->mTree.mNULL | (__int64)p_mResourceDatas->mTree.mRoot.mParent & 1);
  p_mResourceDatas->mTree.mRoot.mChild[0] = &p_mResourceDatas->mTree.mNULL;
  p_mResourceDatas->mTree.mRoot.mChild[1] = &p_mResourceDatas->mTree.mNULL;
  p_mResourceDatas->mTree.mCount = 0;
  v17 = v13->mPrev;
  v18 = this->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v13->mPrev = v13;
  this->mNext = &this->UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory>;
}

// File Line: 525
// RVA: 0x168030
void __fastcall UFG::qResourceInventory::Close(UFG::qResourceInventory *this)
{
  UFG::qBaseNodeRB *p_mNULL; // rdi
  UFG::qBaseNodeRB *v3; // rcx
  UFG::qBaseNodeRB *i; // rax
  UFG::qResourceData *v5; // rbx

  UFG::qPrintChannel::Print(&gInventoryChannel, OUTPUT_LEVEL_DEBUG, "[%s] Close()\n");
  if ( this->mResourceDatas.mTree.mCount )
  {
    p_mNULL = &this->mResourceDatas.mTree.mNULL;
    do
    {
      v3 = this->mResourceDatas.mTree.mRoot.mChild[0];
      for ( i = v3->mChild[0]; i != p_mNULL; i = i->mChild[0] )
        v3 = i;
      v5 = 0i64;
      if ( v3 != p_mNULL )
        v5 = (UFG::qResourceData *)v3;
      UFG::qPrintChannel::Print(
        &gInventoryChannel,
        OUTPUT_LEVEL_DEBUG,
        "[%s] WARNING: Remaining resource name = %s\n");
      this->vfptr->Remove(this, v5);
    }
    while ( this->mResourceDatas.mTree.mCount );
  }
}

// File Line: 541
// RVA: 0x17CFA0
void __fastcall UFG::qResourceInventory::SetHotSwapMode(bool hotSwapModeEnabled)
{
  UFG::qResourceInventory::smHotSwapMode = hotSwapModeEnabled;
}

// File Line: 629
// RVA: 0x173A00
void __fastcall UFG::qResourceInventory::InitHandle(
        UFG::qResourceInventory *this,
        UFG::qResourceHandle *handle,
        unsigned int name_uid,
        UFG::qResourceData *data)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v5; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *p_mNullHandles; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rax

  if ( !data || data == this->mDefaultResourceData )
  {
    if ( name_uid == 0xDEDEDEDE || name_uid == 0xFEFEFEFE || name_uid == -1 || name_uid == 0 )
      p_mNullHandles = &this->mNullHandles;
    else
      p_mNullHandles = &this->mUnresolvedHandleLists[name_uid % this->mNumUnresolvedHandleLists];
    mPrev = p_mNullHandles->mNode.mPrev;
    mPrev->mNext = handle;
    handle->mPrev = mPrev;
    handle->mNext = &p_mNullHandles->mNode;
    p_mNullHandles->mNode.mPrev = handle;
    data = this->mDefaultResourceData;
  }
  else
  {
    v5 = data->mResourceHandles.mNode.mPrev;
    v5->mNext = handle;
    handle->mPrev = v5;
    handle->mNext = &data->mResourceHandles.mNode;
    data->mResourceHandles.mNode.mPrev = handle;
  }
  handle->mData = data;
  handle->mNameUID = name_uid;
  if ( data )
    (*(void (__fastcall **)(UFG::qResourceInventory *, UFG::qResourceHandle *, UFG::qResourceData *))&this->vfptr->gap8[8])(
      this,
      handle,
      data);
}

// File Line: 676
// RVA: 0x173970
void __fastcall UFG::qResourceInventory::InitHandle(
        UFG::qResourceInventory *this,
        UFG::qResourceHandle *handle,
        __int64 name_uid)
{
  UFG::qResourceData *v4; // rcx
  unsigned int v5; // edi

  v4 = 0i64;
  v5 = name_uid;
  if ( (_DWORD)name_uid != -555819298
    && (_DWORD)name_uid != -16843010
    && (_DWORD)name_uid != -1
    && (_DWORD)name_uid != 0 )
  {
    v4 = this->vfptr->Get(this, (unsigned int)name_uid);
  }
  (*(void (__fastcall **)(UFG::qResourceInventory *, UFG::qResourceHandle *, _QWORD, UFG::qResourceData *))this->vfptr->gap8)(
    this,
    handle,
    v5,
    v4);
}

// File Line: 724
// RVA: 0x1755D0
_BOOL8 __fastcall UFG::qResourceInventory::IsEmpty(UFG::qResourceInventory *this)
{
  return this->mNumResourceData == 0;
}

// File Line: 730
// RVA: 0x165760
void __fastcall UFG::qResourceInventory::Add(UFG::qResourceInventory *this, UFG::qResourceData *data)
{
  unsigned int mUID; // edi
  UFG::qResourceData *v3; // r12
  UFG::qResourceInventory *v4; // rsi
  UFG::qBaseNodeRB *v5; // r8
  UFG::qBaseTreeVariableRB<unsigned __int64> *p_mResourceDatas; // rdi
  UFG::qBaseNodeRB *v7; // rax
  UFG::qBaseNodeRB *p_mNULL; // r15
  UFG::qResourceData *v9; // r14
  UFG::qResourceData *v10; // rbx
  UFG::qBaseNodeRB *j; // rax
  UFG::qResourceData *v12; // rax
  unsigned int v13; // r13d
  unsigned int v14; // r8d
  int v15; // r13d
  __int64 p_mNullHandles; // rbp
  UFG::qResourceHandle *mNext; // rsi
  UFG::qResourceHandle *v18; // rdi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v19; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qResourceHandle **v21; // rax
  unsigned int mDefaultResourceNameUID; // eax
  UFG::qResourceData *v23; // r15
  __int64 v24; // rbp
  UFG::qResourceHandle *v25; // rbx
  UFG::qResourceHandle *v26; // r14
  UFG::qResourceData *mData; // rax
  unsigned int mTypeUID; // edi
  UFG::qResourceWarehouse *v29; // rax
  UFG::qResourceInventory *mLastInventory; // rcx
  UFG::qResourceWarehouse *v31; // rdx
  UFG::qResourceWarehouse *v32; // r8
  unsigned int v33; // ecx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v34; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v35; // rax
  UFG::qResourceData *v36; // r8
  UFG::qResourceWarehouse *k; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v38; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v39; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v40; // [rsp+40h] [rbp-58h]
  unsigned int v43; // [rsp+B0h] [rbp+18h]
  UFG::qBaseNodeRB *i; // [rsp+B8h] [rbp+20h]

  mUID = data->mNode.mUID;
  v3 = data;
  v43 = mUID;
  v4 = this;
  if ( UFG::qResourceInventory::smHotSwapMode )
  {
    v5 = this->mResourceDatas.mTree.mRoot.mChild[0];
    p_mResourceDatas = (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mResourceDatas;
    v7 = v5->mChild[0];
    p_mNULL = &this->mResourceDatas.mTree.mNULL;
    v40 = &this->mResourceDatas;
    for ( i = &this->mResourceDatas.mTree.mNULL; v7 != p_mNULL; v7 = v7->mChild[0] )
      v5 = v7;
    v9 = 0i64;
    if ( v5 != p_mNULL )
      v9 = (UFG::qResourceData *)v5;
    if ( v9 )
    {
      do
      {
        v10 = (UFG::qResourceData *)v9->mNode.mChild[1];
        if ( p_mNULL == (UFG::qBaseNodeRB *)v10 )
        {
          v10 = (UFG::qResourceData *)((unsigned __int64)v9->mNode.mParent & 0xFFFFFFFFFFFFFFFEui64);
          if ( v9 == (UFG::qResourceData *)v10->mNode.mChild[1] )
          {
            do
            {
              v12 = v10;
              v10 = (UFG::qResourceData *)((unsigned __int64)v10->mNode.mParent & 0xFFFFFFFFFFFFFFFEui64);
            }
            while ( v12 == (UFG::qResourceData *)v10->mNode.mChild[1] );
          }
          if ( v10 == (UFG::qResourceData *)p_mResourceDatas )
            v10 = 0i64;
        }
        else
        {
          for ( j = v10->mNode.mChild[0]; j != p_mNULL; j = j->mChild[0] )
            v10 = (UFG::qResourceData *)j;
        }
        v13 = v9->mNode.mUID;
        v14 = v3->mNode.mUID;
        if ( v13 == v14 )
        {
          v15 = ~v13;
          if ( v14 == -555819298 || v14 == -16843010 || v14 == -1 || v14 == 0 )
            p_mNullHandles = (__int64)&v4->mNullHandles;
          else
            p_mNullHandles = (__int64)&v4->mUnresolvedHandleLists[v14 % v4->mNumUnresolvedHandleLists];
          mNext = (UFG::qResourceHandle *)v9->mResourceHandles.mNode.mNext;
          if ( mNext != (UFG::qResourceHandle *)&v9->mResourceHandles )
          {
            do
            {
              v18 = (UFG::qResourceHandle *)mNext->mNext;
              this->vfptr->OnDetachHandle(this, mNext, v9);
              v19 = mNext->mNext;
              mPrev = mNext->mPrev;
              mNext->mData = 0i64;
              mPrev->mNext = v19;
              v19->mPrev = mPrev;
              mNext->mPrev = mNext;
              mNext->mNext = mNext;
              v21 = *(UFG::qResourceHandle ***)(p_mNullHandles + 8);
              *(_QWORD *)(p_mNullHandles + 8) = mNext;
              mNext->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)v21;
              mNext->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)p_mNullHandles;
              *v21 = mNext;
              mNext = v18;
            }
            while ( v18 != (UFG::qResourceHandle *)&v9->mResourceHandles );
            p_mNULL = i;
            p_mResourceDatas = (UFG::qBaseTreeVariableRB<unsigned __int64> *)v40;
          }
          UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
            p_mResourceDatas,
            (UFG::qBaseNodeVariableRB<unsigned __int64> *)v9);
          v9->mNode.mUID = v15;
          UFG::qBaseTreeRB::Add((UFG::qBaseTreeRB *)p_mResourceDatas, &v9->mNode);
          v4 = this;
          v3 = data;
        }
        v9 = v10;
      }
      while ( v10 );
    }
    mUID = v43;
  }
  UFG::qBaseTreeRB::Add(&v4->mResourceDatas.mTree, &v3->mNode);
  mDefaultResourceNameUID = v4->mDefaultResourceNameUID;
  v23 = 0i64;
  if ( mDefaultResourceNameUID && mUID == mDefaultResourceNameUID )
  {
    v4->mDefaultResourceData = v3;
    v23 = v3;
  }
  if ( mUID == 0xDEDEDEDE || mUID == 0xFEFEFEFE || mUID == -1 || mUID == 0 )
    v24 = (__int64)&v4->mNullHandles;
  else
    v24 = (__int64)&v4->mUnresolvedHandleLists[mUID % v4->mNumUnresolvedHandleLists];
  v25 = *(UFG::qResourceHandle **)(v24 + 8);
  if ( v25 != (UFG::qResourceHandle *)v24 )
  {
    do
    {
      v26 = (UFG::qResourceHandle *)v25->mNext;
      if ( v25->mNameUID == mUID )
      {
        mData = v25->mData;
        if ( mData )
        {
          mTypeUID = mData->mTypeUID;
          v29 = UFG::qResourceWarehouse::Instance();
          mLastInventory = v29->mLastInventory;
          v31 = v29;
          if ( !mLastInventory || v29->mLastTypeUID != mTypeUID )
          {
            if ( !mTypeUID )
              goto LABEL_44;
            v32 = (UFG::qResourceWarehouse *)&v29->mInventoryTree.mTree.mNULL;
            if ( v29 == (UFG::qResourceWarehouse *)&v29->mInventoryTree.mTree.mNULL )
              goto LABEL_44;
            while ( 1 )
            {
              v33 = v29->mInventoryTree.mTree.mRoot.mUID;
              if ( v29 != v31 && v33 == mTypeUID )
                break;
              if ( mTypeUID > v33 )
                v29 = (UFG::qResourceWarehouse *)v29->mInventoryTree.mTree.mRoot.mChild[1];
              else
                v29 = (UFG::qResourceWarehouse *)v29->mInventoryTree.mTree.mRoot.mChild[0];
              if ( v29 == v32 )
                goto LABEL_44;
            }
            for ( k = (UFG::qResourceWarehouse *)v29->mInventoryTree.mTree.mRoot.mChild[0];
                  k;
                  k = (UFG::qResourceWarehouse *)k->mInventoryTree.mTree.mRoot.mChild[0] )
            {
              if ( k->mInventoryTree.mTree.mRoot.mUID != mTypeUID )
                break;
              v29 = k;
            }
            if ( v29 )
              mLastInventory = (UFG::qResourceInventory *)&v29[-1].mUnloadTime;
            else
LABEL_44:
              mLastInventory = 0i64;
            v31->mLastInventory = mLastInventory;
            v31->mLastTypeUID = mTypeUID;
          }
          v34 = v25->mPrev;
          v35 = v25->mNext;
          v34->mNext = v35;
          v35->mPrev = v34;
          v36 = v25->mData;
          v25->mPrev = v25;
          v25->mNext = v25;
          mLastInventory->vfptr->OnDetachHandle(mLastInventory, v25, v36);
          mUID = v43;
          v25->mData = 0i64;
        }
        else
        {
          v38 = v25->mPrev;
          v38->mNext = v26;
          v26->mPrev = v38;
          v25->mPrev = v25;
          v25->mNext = v25;
        }
        v25->mData = v3;
        v39 = v3->mResourceHandles.mNode.mPrev;
        v39->mNext = v25;
        v25->mNext = &v3->mResourceHandles.mNode;
        v25->mPrev = v39;
        v3->mResourceHandles.mNode.mPrev = v25;
        (*(void (__fastcall **)(UFG::qResourceInventory *, UFG::qResourceHandle *, UFG::qResourceData *))&v4->vfptr->gap8[8])(
          v4,
          v25,
          v3);
      }
      else if ( v23 )
      {
        v25->mData = v23;
      }
      v25 = v26;
    }
    while ( v26 != (UFG::qResourceHandle *)v24 );
  }
  ++v4->mNumResourceData;
  ++v4->mTransactionNum;
  UFG::qPrintChannel::Print(&gInventoryChannel, OUTPUT_LEVEL_DEBUG, "[%s] ADD%s - 0x%08x - %s\n");
}

// File Line: 860
// RVA: 0x17A370
void __fastcall UFG::qResourceInventory::Remove(UFG::qResourceInventory *this, UFG::qResourceData *data)
{
  unsigned int mUID; // edi
  UFG::qResourceData *v5; // rax
  unsigned int v6; // esi
  UFG::qResourceData *mDefaultResourceData; // r14
  int v8; // r12d
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *p_mResourceHandles; // rbp
  UFG::qResourceHandle *mNext; // rdi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v12; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v13; // rax
  UFG::qResourceData *v14; // rdx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v15; // rcx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *i; // rax

  mUID = data->mNode.mUID;
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mResourceDatas,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)data);
  v5 = this->vfptr->Get(this, mUID);
  v6 = 0;
  mDefaultResourceData = v5;
  v8 = 0;
  if ( this->mDefaultResourceData == data )
  {
    this->mDefaultResourceData = v5;
    v8 = 1;
  }
  if ( v5 )
  {
    p_mResourceHandles = &v5->mResourceHandles;
  }
  else
  {
    if ( mUID == -555819298 || mUID == -16843010 || mUID == -1 || mUID == 0 )
      p_mResourceHandles = &this->mNullHandles;
    else
      p_mResourceHandles = &this->mUnresolvedHandleLists[mUID % this->mNumUnresolvedHandleLists];
    mDefaultResourceData = this->mDefaultResourceData;
  }
  for ( ;
        (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)data->mResourceHandles.mNode.mNext != &data->mResourceHandles;
        v13->mPrev = mNext )
  {
    mNext = (UFG::qResourceHandle *)data->mResourceHandles.mNode.mNext;
    mPrev = mNext->mPrev;
    v12 = mNext->mNext;
    mPrev->mNext = v12;
    v12->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    this->vfptr->OnDetachHandle(this, mNext, data);
    mNext->mData = mDefaultResourceData;
    if ( mDefaultResourceData )
      (*(void (__fastcall **)(UFG::qResourceInventory *, UFG::qResourceHandle *, UFG::qResourceData *))&this->vfptr->gap8[8])(
        this,
        mNext,
        mDefaultResourceData);
    v13 = p_mResourceHandles->mNode.mNext;
    p_mResourceHandles->mNode.mNext = mNext;
    mNext->mPrev = &p_mResourceHandles->mNode;
    mNext->mNext = v13;
  }
  if ( v8 )
  {
    v14 = this->mDefaultResourceData;
    if ( this->mNumUnresolvedHandleLists )
    {
      do
      {
        v15 = &this->mUnresolvedHandleLists[v6];
        for ( i = (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)v15->mNode.mNext;
              i != v15;
              i = (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)i->mNode.mNext )
        {
          i[1].mNode.mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)v14;
        }
        ++v6;
      }
      while ( v6 < this->mNumUnresolvedHandleLists );
    }
  }
  --this->mNumResourceData;
  ++this->mTransactionNum;
  UFG::qPrintChannel::Print(&gInventoryChannel, OUTPUT_LEVEL_DEBUG, "[%s] REMOVE - 0x%08x - %s\n");
}

// File Line: 966
// RVA: 0x16F010
UFG::qResourceData *__fastcall UFG::qResourceInventory::Get(UFG::qResourceInventory *this, unsigned int name_uid)
{
  UFG::qResourceData *p_mResourceDatas; // r8
  UFG::qResourceData *result; // rax
  UFG::qResourceData *p_mNULL; // r9
  bool i; // zf
  unsigned int mUID; // ecx
  UFG::qResourceData *j; // rcx

  if ( name_uid )
  {
    p_mResourceDatas = (UFG::qResourceData *)&this->mResourceDatas;
    result = (UFG::qResourceData *)&this->mResourceDatas;
    p_mNULL = (UFG::qResourceData *)&this->mResourceDatas.mTree.mNULL;
    for ( i = &this->mResourceDatas == (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)&this->mResourceDatas.mTree.mNULL;
          !i;
          i = result == p_mNULL )
    {
      mUID = result->mNode.mUID;
      if ( result != p_mResourceDatas && mUID == name_uid )
      {
        for ( j = (UFG::qResourceData *)result->mNode.mChild[0]; j; j = (UFG::qResourceData *)j->mNode.mChild[0] )
        {
          if ( j->mNode.mUID != name_uid )
            break;
          result = j;
        }
        return result;
      }
      if ( name_uid > mUID )
        result = (UFG::qResourceData *)result->mNode.mChild[1];
      else
        result = (UFG::qResourceData *)result->mNode.mChild[0];
    }
  }
  return 0i64;
}

// File Line: 971
// RVA: 0x16B830
UFG::qBaseNodeRB *__fastcall UFG::qResourceInventory::DebugGet(UFG::qResourceInventory *this, const char *name)
{
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *p_mResourceDatas; // rbp
  UFG::qBaseNodeRB *p_mRoot; // rcx
  UFG::qBaseNodeRB *p_mNULL; // rbx
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v6; // rax
  UFG::qBaseNodeRB *v7; // r11
  const char *v8; // r9
  int v9; // r10d
  char v10; // dl
  char v11; // r8
  UFG::qBaseNodeRB *v13; // rcx
  UFG::qBaseNodeRB *i; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v15; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v16; // rcx

  p_mResourceDatas = &this->mResourceDatas;
  p_mRoot = this->mResourceDatas.mTree.mRoot.mChild[0];
  p_mNULL = &p_mResourceDatas->mTree.mNULL;
  v6 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)p_mRoot->mChild[0];
  if ( v6 != (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)&p_mResourceDatas->mTree.mNULL )
  {
    do
    {
      p_mRoot = &v6->mTree.mRoot;
      v6 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v6->mTree.mRoot.mChild[0];
    }
    while ( v6 != (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)p_mNULL );
  }
  v7 = 0i64;
  if ( p_mRoot != p_mNULL )
    v7 = p_mRoot;
  while ( v7 )
  {
    v8 = name;
    if ( v7 != (UFG::qBaseNodeRB *)-52i64 && name )
    {
      v9 = -1;
      while ( 1 )
      {
        v10 = v8[(char *)v7 - name + 52];
        if ( v10 <= 122 && v10 >= 97 )
          v10 -= 32;
        v11 = *v8;
        if ( *v8 <= 122 && *v8 >= 97 )
          v11 -= 32;
        if ( !v10 )
          break;
        if ( v10 != v11 )
          goto LABEL_18;
        ++v8;
        if ( !--v9 )
          return v7;
      }
      if ( !v11 )
        return v7;
    }
LABEL_18:
    v13 = v7->mChild[1];
    if ( p_mNULL == v13 )
    {
      v15 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((unsigned __int64)v7->mParent & 0xFFFFFFFFFFFFFFFEui64);
      if ( v7 == v15->mTree.mRoot.mChild[1] )
      {
        do
        {
          v16 = v15;
          v15 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((unsigned __int64)v15->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
        }
        while ( v16 == (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v15->mTree.mRoot.mChild[1] );
      }
      v7 = &v15->mTree.mRoot;
      if ( v15 == p_mResourceDatas )
        v7 = 0i64;
    }
    else
    {
      for ( i = v13->mChild[0]; i != p_mNULL; i = i->mChild[0] )
        v13 = i;
      v7 = v13;
    }
  }
  return 0i64;
}

// File Line: 985
// RVA: 0x176B00
signed __int64 __fastcall UFG::qResourceInventory::Load(UFG::qResourceInventory *this, UFG::qChunk *chunk)
{
  unsigned int mChunkUID; // eax
  unsigned int mDataSize; // edi

  mChunkUID = this->mChunkUID;
  mDataSize = chunk->mDataSize;
  if ( !mChunkUID || chunk->mUID != mChunkUID )
    return 0i64;
  this->vfptr->Add(this, (UFG::qResourceData *)((char *)&chunk[1] + chunk->mDataOffset));
  this->mNumResourceBytes += mDataSize;
  return 1i64;
}

// File Line: 1038
// RVA: 0x17F130
__int64 __fastcall UFG::qResourceInventory::Unload(UFG::qResourceInventory *this, UFG::qChunk *chunk)
{
  unsigned int mChunkUID; // eax
  unsigned int mDataSize; // edi

  mChunkUID = this->mChunkUID;
  mDataSize = chunk->mDataSize;
  if ( !mChunkUID || chunk->mUID != mChunkUID )
    return 0i64;
  this->vfptr->Remove(this, (UFG::qResourceData *)((char *)&chunk[1] + chunk->mDataOffset));
  this->mNumResourceBytes -= mDataSize;
  return 1i64;
}

// File Line: 1090
// RVA: 0x178B00
__int64 __fastcall UFG::qResourceInventory::PreMove(UFG::qResourceInventory *this, UFG::qChunk *chunk)
{
  unsigned int mChunkUID; // eax

  mChunkUID = this->mChunkUID;
  if ( !mChunkUID || !chunk || chunk->mUID != mChunkUID )
    return 0i64;
  this->vfptr->OnPreMove(this, (UFG::qResourceData *)((char *)&chunk[1] + chunk->mDataOffset));
  return ((__int64 (__fastcall *)(UFG::qResourceInventory *, UFG::qChunk *))this->vfptr->Unload)(this, chunk);
}

// File Line: 1099
// RVA: 0x178940
__int64 __fastcall UFG::qResourceInventory::PostMove(UFG::qResourceInventory *this, UFG::qChunk *chunk)
{
  if ( !((unsigned int (__fastcall *)(UFG::qResourceInventory *))this->vfptr->Load)(this) )
    return 0i64;
  this->vfptr->OnPostMove(this, (UFG::qResourceData *)((char *)&chunk[1] + chunk->mDataOffset));
  return 1i64;
}

// File Line: 1120
// RVA: 0x1794F0
void __fastcall UFG::qResourceInventory::PrintContents(UFG::qResourceInventory *this)
{
  UFG::qBaseNodeRB *v2; // rcx
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *p_mResourceDatas; // rsi
  UFG::qBaseNodeRB *v4; // rax
  UFG::qBaseNodeRB *i; // rdi
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v6; // rbx
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v7; // rcx
  UFG::qBaseNodeRB *j; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v9; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v10; // rcx

  UFG::qPrintf("Contents of Inventory %.64s %d items\n", this->mName, this->mNumResourceData);
  v2 = this->mResourceDatas.mTree.mRoot.mChild[0];
  p_mResourceDatas = &this->mResourceDatas;
  v4 = v2->mChild[0];
  for ( i = &p_mResourceDatas->mTree.mNULL; v4 != i; v4 = v4->mChild[0] )
    v2 = v4;
  v6 = 0i64;
  if ( v2 != i )
    v6 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v2;
  while ( v6 )
  {
    UFG::qPrintf(
      "  - Resource TypeUID:0x%08x DataUID:0x%08x Memory:0x%08x Name:%.36s\n",
      LODWORD(v6->mTree.mNULL.mChild[1]),
      v6->mTree.mRoot.mUID,
      v6,
      (const char *)&v6->mTree.mNULL.mChild[1] + 4);
    v7 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v6->mTree.mRoot.mChild[1];
    if ( i == (UFG::qBaseNodeRB *)v7 )
    {
      v9 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((unsigned __int64)v6->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
      if ( v6 == (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v9->mTree.mRoot.mChild[1] )
      {
        do
        {
          v10 = v9;
          v9 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((unsigned __int64)v9->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
        }
        while ( v10 == (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v9->mTree.mRoot.mChild[1] );
      }
      v6 = v9;
      if ( v9 == p_mResourceDatas )
        v6 = 0i64;
    }
    else
    {
      for ( j = v7->mTree.mRoot.mChild[0]; j != i; j = j->mChild[0] )
        v7 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)j;
      v6 = v7;
    }
  }
}

// File Line: 1153
// RVA: 0x164290
void __fastcall UFG::qResourceWarehouse::~qResourceWarehouse(UFG::qResourceWarehouse *this)
{
  UFG::qBaseNodeRB *p_mNULL; // rsi
  UFG::qList<UFG::qResourceInventory,UFG::qResourceInventory,1,0> *p_mInventoryList; // rbx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> **p_mNext; // rax
  UFG::qBaseNodeRB *i; // r8
  _QWORD *v6; // rdx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v7; // rcx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v8; // rax
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *mPrev; // rcx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *mNext; // rax

  p_mNULL = &this->mInventoryTree.mTree.mNULL;
  this->mInventoryTree.mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&this->mInventoryTree.mTree.mNULL | (__int64)this->mInventoryTree.mTree.mRoot.mParent & 1);
  this->mInventoryTree.mTree.mRoot.mChild[0] = &this->mInventoryTree.mTree.mNULL;
  this->mInventoryTree.mTree.mRoot.mChild[1] = &this->mInventoryTree.mTree.mNULL;
  this->mInventoryTree.mTree.mCount = 0;
  p_mInventoryList = &this->mInventoryList;
  p_mNext = &this->mInventoryList.mNode.mNext[-3].mNext;
  for ( i = &this->mInventoryTree.mTree.mNULL;
        p_mNext != (UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> **)i;
        p_mNext = &p_mInventoryList->mNode.mNext[-3].mNext )
  {
    v6 = p_mNext + 5;
    v7 = p_mNext[5];
    v8 = p_mNext[6];
    v7->mNext = v8;
    v8->mPrev = v7;
    *v6 = v6;
    v6[1] = v6;
  }
  UFG::qList<UFG::qResourceInventory,UFG::qResourceInventory,1,0>::DeleteNodes(p_mInventoryList);
  mPrev = p_mInventoryList->mNode.mPrev;
  mNext = p_mInventoryList->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mInventoryList->mNode.mPrev = &p_mInventoryList->mNode;
  p_mInventoryList->mNode.mNext = &p_mInventoryList->mNode;
  UFG::qTreeRB<UFG::qResourceInventory,UFG::qResourceInventory,1>::DeleteAll(&this->mInventoryTree);
  this->mInventoryTree.mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)p_mNULL | (__int64)this->mInventoryTree.mTree.mRoot.mParent & 1);
  this->mInventoryTree.mTree.mRoot.mChild[0] = p_mNULL;
  this->mInventoryTree.mTree.mRoot.mChild[1] = p_mNULL;
  this->mInventoryTree.mTree.mCount = 0;
}

// File Line: 1162
// RVA: 0x174040
UFG::qResourceWarehouse *__fastcall UFG::qResourceWarehouse::Instance()
{
  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    sResourceWarehouse.mInventoryTree.mTree.mNULL.mChild[0] = &sResourceWarehouse.mInventoryTree.mTree.mNULL;
    sResourceWarehouse.mInventoryTree.mTree.mNULL.mChild[1] = &sResourceWarehouse.mInventoryTree.mTree.mNULL;
    sResourceWarehouse.mInventoryTree.mTree.mNULL.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&sResourceWarehouse.mInventoryTree.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
    sResourceWarehouse.mInventoryTree.mTree.mNULL.mUID = 0;
    sResourceWarehouse.mInventoryTree.mTree.mRoot.mChild[0] = &sResourceWarehouse.mInventoryTree.mTree.mNULL;
    sResourceWarehouse.mInventoryTree.mTree.mRoot.mChild[1] = &sResourceWarehouse.mInventoryTree.mTree.mNULL;
    sResourceWarehouse.mInventoryTree.mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&sResourceWarehouse.mInventoryTree.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
    sResourceWarehouse.mInventoryTree.mTree.mRoot.mUID = -1;
    sResourceWarehouse.mInventoryTree.mTree.mCount = 0;
    sResourceWarehouse.mInventoryList.mNode.mPrev = &sResourceWarehouse.mInventoryList.mNode;
    sResourceWarehouse.mInventoryList.mNode.mNext = &sResourceWarehouse.mInventoryList.mNode;
    sResourceWarehouse.mLastInventory = 0i64;
    sResourceWarehouse.mLastTypeUID = 0;
    sResourceWarehouse.mUnresolvedTime = 0.0;
    UFG::gResourceWarehouse = &sResourceWarehouse;
    atexit(UFG::qResourceWarehouse::Instance_::_2_::_dynamic_atexit_destructor_for__sResourceWarehouse__);
  }
  return &sResourceWarehouse;
}

// File Line: 1169
// RVA: 0x1735B0
void __fastcall UFG::qResourceWarehouse::Init(UFG::qResourceWarehouse *this)
{
  UFG::qBaseNodeRB *p_mRoot; // rdx
  UFG::qBaseNodeRB *p_mNULL; // rdi
  UFG::qResourceWarehouse *v4; // rax
  UFG::qBaseNodeRB *v5; // rbx
  unsigned int *p_mUID; // rbx
  UFG::qResourceWarehouse *v7; // rax
  UFG::qBaseNodeRB *v8; // rbx
  UFG::qResourceWarehouse *i; // rcx
  UFG::qResourceWarehouse *v10; // rcx

  p_mRoot = this->mInventoryTree.mTree.mRoot.mChild[0];
  p_mNULL = &this->mInventoryTree.mTree.mNULL;
  v4 = (UFG::qResourceWarehouse *)p_mRoot->mChild[0];
  if ( v4 != (UFG::qResourceWarehouse *)&this->mInventoryTree.mTree.mNULL )
  {
    do
    {
      p_mRoot = &v4->mInventoryTree.mTree.mRoot;
      v4 = (UFG::qResourceWarehouse *)v4->mInventoryTree.mTree.mRoot.mChild[0];
    }
    while ( v4 != (UFG::qResourceWarehouse *)p_mNULL );
  }
  v5 = 0i64;
  if ( p_mRoot != p_mNULL )
    v5 = p_mRoot;
  if ( !v5 )
    goto LABEL_7;
  p_mUID = &v5[-1].mUID;
  while ( p_mUID )
  {
    (*(void (__fastcall **)(unsigned int *))(*(_QWORD *)p_mUID + 48i64))(p_mUID);
    v7 = (UFG::qResourceWarehouse *)*((_QWORD *)p_mUID + 3);
    v8 = (UFG::qBaseNodeRB *)(p_mUID + 2);
    if ( p_mNULL != (UFG::qBaseNodeRB *)v7 )
    {
      for ( i = (UFG::qResourceWarehouse *)v7->mInventoryTree.mTree.mRoot.mChild[0];
            i != (UFG::qResourceWarehouse *)p_mNULL;
            i = (UFG::qResourceWarehouse *)i->mInventoryTree.mTree.mRoot.mChild[0] )
      {
        v7 = i;
      }
      goto LABEL_16;
    }
    v7 = (UFG::qResourceWarehouse *)((unsigned __int64)v8->mParent & 0xFFFFFFFFFFFFFFFEui64);
    if ( v8 == v7->mInventoryTree.mTree.mRoot.mChild[1] )
    {
      do
      {
        v10 = v7;
        v7 = (UFG::qResourceWarehouse *)((unsigned __int64)v7->mInventoryTree.mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
      }
      while ( v10 == (UFG::qResourceWarehouse *)v7->mInventoryTree.mTree.mRoot.mChild[1] );
    }
    if ( v7 == this )
    {
LABEL_7:
      p_mUID = 0i64;
    }
    else
    {
LABEL_16:
      if ( !v7 )
        goto LABEL_7;
      p_mUID = (unsigned int *)&v7[-1].mUnloadTime;
    }
  }
}

// File Line: 1209
// RVA: 0x170B80
UFG::qResourceInventory *__fastcall UFG::qResourceWarehouse::GetInventory(
        UFG::qResourceWarehouse *this,
        unsigned int type_uid)
{
  UFG::qResourceInventory *result; // rax
  UFG::qBaseNodeRB *p_mNULL; // r9
  UFG::qResourceWarehouse *v5; // rax
  bool i; // zf
  unsigned int mUID; // ecx
  UFG::qResourceWarehouse *j; // rcx

  result = this->mLastInventory;
  if ( !result || this->mLastTypeUID != type_uid )
  {
    if ( type_uid )
    {
      p_mNULL = &this->mInventoryTree.mTree.mNULL;
      v5 = this;
      for ( i = this == (UFG::qResourceWarehouse *)&this->mInventoryTree.mTree.mNULL;
            !i;
            i = v5 == (UFG::qResourceWarehouse *)p_mNULL )
      {
        mUID = v5->mInventoryTree.mTree.mRoot.mUID;
        if ( v5 != this && mUID == type_uid )
        {
          for ( j = (UFG::qResourceWarehouse *)v5->mInventoryTree.mTree.mRoot.mChild[0];
                j;
                j = (UFG::qResourceWarehouse *)j->mInventoryTree.mTree.mRoot.mChild[0] )
          {
            if ( j->mInventoryTree.mTree.mRoot.mUID != type_uid )
              break;
            v5 = j;
          }
          if ( v5 )
          {
            result = (UFG::qResourceInventory *)&v5[-1].mUnloadTime;
            this->mLastTypeUID = type_uid;
            this->mLastInventory = result;
            return result;
          }
          break;
        }
        if ( type_uid > mUID )
          v5 = (UFG::qResourceWarehouse *)v5->mInventoryTree.mTree.mRoot.mChild[1];
        else
          v5 = (UFG::qResourceWarehouse *)v5->mInventoryTree.mTree.mRoot.mChild[0];
      }
    }
    result = 0i64;
    this->mLastTypeUID = type_uid;
    this->mLastInventory = 0i64;
  }
  return result;
}

// File Line: 1226
// RVA: 0x165B60
void __fastcall UFG::qResourceWarehouse::Add(UFG::qResourceWarehouse *this, UFG::qResourceData *data)
{
  UFG::qResourceInventory *Inventory; // rax

  Inventory = UFG::qResourceWarehouse::GetInventory(this, data->mTypeUID);
  if ( Inventory )
    Inventory->vfptr->Add(Inventory, data);
}

// File Line: 1248
// RVA: 0x17A530
void __fastcall UFG::qResourceWarehouse::Remove(UFG::qResourceWarehouse *this, UFG::qResourceData *data)
{
  UFG::qResourceInventory *Inventory; // rax

  if ( ((unsigned __int64)data->mNode.mParent & 0xFFFFFFFFFFFFFFFEui64) != 0
    || data->mNode.mChild[0]
    || data->mNode.mChild[1] )
  {
    Inventory = UFG::qResourceWarehouse::GetInventory(this, data->mTypeUID);
    if ( Inventory )
      Inventory->vfptr->Remove(Inventory, data);
  }
}

// File Line: 1274
// RVA: 0x16B980
UFG::qResourceInventory *__fastcall UFG::qResourceWarehouse::DebugGet(
        UFG::qResourceWarehouse *this,
        unsigned int type_uid,
        unsigned int name_uid)
{
  UFG::qResourceInventory *result; // rax

  result = UFG::qResourceWarehouse::GetInventory(this, type_uid);
  if ( result )
    return (UFG::qResourceInventory *)result->vfptr->Get(result, name_uid);
  return result;
}

// File Line: 1325
// RVA: 0x176B50
void __fastcall UFG::qResourceWarehouse::Load(
        UFG::qResourceWarehouse *this,
        char *buffer,
        UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *num_bytes)
{
  int *v3; // rdi
  char *v5; // r12
  UFG::qBaseNodeRB *p_mNULL; // rsi
  int v7; // ebp
  __int64 v8; // r9
  unsigned __int64 v9; // r15
  UFG::qResourceInventory *p_mNext; // rbx
  unsigned int v11; // eax
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *mNext; // rcx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *mPrev; // rdx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v14; // rax

  v3 = (int *)buffer;
  v5 = &buffer[(unsigned int)num_bytes];
  if ( buffer < v5 )
  {
    p_mNULL = &this->mInventoryTree.mTree.mNULL;
    do
    {
      v7 = *v3;
      v8 = 0i64;
      v9 = (unsigned __int64)v3 + ((v3[1] + 3) & 0xFFFFFFFC) + 16;
      p_mNext = (UFG::qResourceInventory *)&this->mInventoryList.mNode.mNext[-3].mNext;
      do
      {
        if ( p_mNext == (UFG::qResourceInventory *)p_mNULL )
          break;
        if ( p_mNext->mChunkUID != 0 && p_mNext->mChunkUID == v7 )
        {
          v11 = ((__int64 (__fastcall *)(UFG::qResourceInventory *, int *, UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *, __int64))p_mNext->vfptr->Load)(
                  p_mNext,
                  v3,
                  num_bytes,
                  v8);
          v8 = v11;
          if ( v11 )
          {
            mNext = p_mNext->mNext;
            mPrev = p_mNext->mPrev;
            num_bytes = &p_mNext->UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory>;
            mPrev->mNext = mNext;
            mNext->mPrev = mPrev;
            p_mNext->mPrev = &p_mNext->UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory>;
            p_mNext->mNext = &p_mNext->UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory>;
            v14 = this->mInventoryList.mNode.mNext;
            this->mInventoryList.mNode.mNext = &p_mNext->UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory>;
            p_mNext->mNext = v14;
            p_mNext->mPrev = &this->mInventoryList.mNode;
            v14->mPrev = &p_mNext->UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory>;
          }
        }
        p_mNext = (UFG::qResourceInventory *)&p_mNext->mNext[-3].mNext;
      }
      while ( !(_DWORD)v8 );
      v3 = (int *)v9;
    }
    while ( v9 < (unsigned __int64)v5 );
  }
}

// File Line: 1443
// RVA: 0x17F180
void __fastcall UFG::qResourceWarehouse::Unload(
        UFG::qResourceWarehouse *this,
        char *buffer,
        UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *num_bytes)
{
  int *v3; // rdi
  char *v5; // r12
  UFG::qBaseNodeRB *p_mNULL; // rsi
  int v7; // ebp
  __int64 v8; // r9
  unsigned __int64 v9; // r15
  UFG::qResourceInventory *p_mNext; // rbx
  unsigned int v11; // eax
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *mNext; // rcx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *mPrev; // rdx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v14; // rax

  v3 = (int *)buffer;
  v5 = &buffer[(unsigned int)num_bytes];
  if ( buffer < v5 )
  {
    p_mNULL = &this->mInventoryTree.mTree.mNULL;
    do
    {
      v7 = *v3;
      v8 = 0i64;
      v9 = (unsigned __int64)v3 + ((v3[1] + 3) & 0xFFFFFFFC) + 16;
      p_mNext = (UFG::qResourceInventory *)&this->mInventoryList.mNode.mNext[-3].mNext;
      do
      {
        if ( p_mNext == (UFG::qResourceInventory *)p_mNULL )
          break;
        if ( p_mNext->mChunkUID != 0 && p_mNext->mChunkUID == v7 )
        {
          v11 = ((__int64 (__fastcall *)(UFG::qResourceInventory *, int *, UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *, __int64))p_mNext->vfptr->Unload)(
                  p_mNext,
                  v3,
                  num_bytes,
                  v8);
          v8 = v11;
          if ( v11 )
          {
            mNext = p_mNext->mNext;
            mPrev = p_mNext->mPrev;
            num_bytes = &p_mNext->UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory>;
            mPrev->mNext = mNext;
            mNext->mPrev = mPrev;
            p_mNext->mPrev = &p_mNext->UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory>;
            p_mNext->mNext = &p_mNext->UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory>;
            v14 = this->mInventoryList.mNode.mNext;
            this->mInventoryList.mNode.mNext = &p_mNext->UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory>;
            p_mNext->mNext = v14;
            p_mNext->mPrev = &this->mInventoryList.mNode;
            v14->mPrev = &p_mNext->UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory>;
          }
        }
        p_mNext = (UFG::qResourceInventory *)&p_mNext->mNext[-3].mNext;
      }
      while ( !(_DWORD)v8 );
      v3 = (int *)v9;
    }
    while ( v9 < (unsigned __int64)v5 );
  }
}


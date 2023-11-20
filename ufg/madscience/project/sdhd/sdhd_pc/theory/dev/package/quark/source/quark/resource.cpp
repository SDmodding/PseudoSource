// File Line: 66
// RVA: 0x1467E30
__int64 UFG::_dynamic_initializer_for__gInventoryChannel__()
{
  gInventoryChannel.mLogFilename.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&gInventoryChannel.mLogFilename.mPrev;
  gInventoryChannel.mLogFilename.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&gInventoryChannel.mLogFilename.mPrev;
  *(_QWORD *)&gInventoryChannel.mLogFilename.mMagic = 16909060i64;
  gInventoryChannel.mLogFilename.mData = (char *)UFG::qString::sEmptyString;
  *(_QWORD *)&gInventoryChannel.mLogFilename.mStringHash32 = -1i64;
  return atexit(UFG::_dynamic_atexit_destructor_for__gInventoryChannel__);
}

// File Line: 67
// RVA: 0x1468180
__int64 UFG::_dynamic_initializer_for__gWarehouseChannel__()
{
  gWarehouseChannel.mLogFilename.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&gWarehouseChannel.mLogFilename.mPrev;
  gWarehouseChannel.mLogFilename.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&gWarehouseChannel.mLogFilename.mPrev;
  *(_QWORD *)&gWarehouseChannel.mLogFilename.mMagic = 16909060i64;
  gWarehouseChannel.mLogFilename.mData = (char *)UFG::qString::sEmptyString;
  *(_QWORD *)&gWarehouseChannel.mLogFilename.mStringHash32 = -1i64;
  return atexit(UFG::_dynamic_atexit_destructor_for__gWarehouseChannel__);
}

// File Line: 73
// RVA: 0x1467FF0
__int64 UFG::_dynamic_initializer_for__gResourceFileUIDContentPrefixHash__()
{
  char v0; // dl
  unsigned int v1; // er8
  const char *v2; // r10
  unsigned int i; // er9
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
    v0 = (v2++)[1];
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
  const char *v2; // rbx
  __int64 v3; // rdi
  char *v4; // r8
  char v5; // al
  char *i; // rcx
  char v7; // al
  char *v8; // r9
  unsigned int v9; // er8
  unsigned int v10; // ecx
  unsigned int v11; // er8
  char v13; // [rsp+20h] [rbp-108h]

  v2 = file_path;
  v3 = content_type;
  v4 = UFG::qStringFindLastInsensitive(file_path, "data\\");
  if ( !v4 )
    v4 = UFG::qStringFindLastInsensitive(v2, "data/");
  v5 = *v4;
  for ( i = &v13; v5; ++v4 )
  {
    if ( v5 != 47 && v5 != 92 )
      *i++ = v5;
    v5 = v4[1];
  }
  *i = 0;
  v7 = v13;
  v8 = &v13;
  v9 = gResourceFileUIDContentPrefixHash[v3];
  if ( v13 )
  {
    do
    {
      if ( v7 <= 122 && v7 >= 97 )
        v7 -= 32;
      ++v8;
      v10 = v9 << 8;
      v11 = sCrcTable32[(unsigned __int8)(v7 ^ HIBYTE(v9))];
      v7 = *v8;
      v9 = v10 ^ v11;
    }
    while ( *v8 );
  }
  return v9;
}

// File Line: 138
// RVA: 0x1467CC0
__int64 UFG::_dynamic_initializer_for__gChunkFileIndexInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gChunkFileIndexInventory.vfptr,
    "ChunkFileIndexInventory",
    0xF569FE1B,
    0x7040F7D2u,
    0,
    0);
  UFG::gChunkFileIndexInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::ChunkFileIndexInventory::`vftable';
  return atexit(UFG::_dynamic_atexit_destructor_for__gChunkFileIndexInventory__);
}

// File Line: 186
// RVA: 0x1467C60
__int64 UFG::_dynamic_initializer_for__gChunkFileFatIndexInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gChunkFileFatIndexInventory.vfptr,
    "ChunkFileFatIndexInventory",
    0xE36C885C,
    0xE445B80C,
    0,
    0);
  UFG::gChunkFileFatIndexInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::ChunkFileFatIndexInventory::`vftable';
  return atexit(UFG::_dynamic_atexit_destructor_for__gChunkFileFatIndexInventory__);
}

// File Line: 193
// RVA: 0x164FB0
void __fastcall UFG::ChunkFileIndexInventory::Add(UFG::ChunkFileIndexInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v2; // [rsp+58h] [rbp+20h]

  if ( resource_data )
  {
    resource_data->mNode.mParent = 0i64;
    resource_data->mNode.mChild[0] = 0i64;
    resource_data->mNode.mChild[1] = 0i64;
    v2 = &resource_data->mResourceHandles;
    v2->mNode.mPrev = &v2->mNode;
    v2->mNode.mNext = &v2->mNode;
  }
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&this->vfptr, resource_data);
}

// File Line: 212
// RVA: 0x161BB0
void __fastcall UFG::qResourceHandle::qResourceHandle(UFG::qResourceHandle *this)
{
  this->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&this->mPrev;
  this->mData = 0i64;
}

// File Line: 227
// RVA: 0x164090
void __fastcall UFG::qResourceHandle::~qResourceHandle(UFG::qResourceHandle *this)
{
  UFG::qResourceHandle *v1; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v2; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v3; // rax

  v1 = this;
  UFG::qResourceHandle::Close(this);
  v2 = v1->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v1->mPrev;
}

// File Line: 247
// RVA: 0x173500
void __fastcall UFG::qResourceHandle::Init(UFG::qResourceHandle *this, unsigned int type_uid, unsigned int name_uid, UFG::qResourceData *resource_data, UFG::qResourceInventory *inventory)
{
  UFG::qResourceData *v5; // rdi
  unsigned int v6; // esi
  UFG::qResourceHandle *v7; // rbx

  v5 = resource_data;
  v6 = name_uid;
  v7 = this;
  UFG::qResourceHandle::Close(this);
  if ( inventory )
    (*(void (__fastcall **)(UFG::qResourceInventory *, UFG::qResourceHandle *, _QWORD, UFG::qResourceData *))inventory->vfptr->gap8)(
      inventory,
      v7,
      v6,
      v5);
}

// File Line: 260
// RVA: 0x1734B0
void __fastcall UFG::qResourceHandle::Init(UFG::qResourceHandle *this, unsigned int type_uid, unsigned int name_uid)
{
  unsigned int v3; // esi
  unsigned int v4; // ebx
  UFG::qResourceHandle *v5; // rdi
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceInventory *v7; // rax

  v3 = name_uid;
  v4 = type_uid;
  v5 = this;
  UFG::qResourceHandle::Close(this);
  v6 = UFG::qResourceWarehouse::Instance();
  v7 = UFG::qResourceWarehouse::GetInventory(v6, v4);
  if ( v7 )
    v7->vfptr->InitHandle(v7, v5, v3);
}

// File Line: 275
// RVA: 0x173550
void __fastcall UFG::qResourceHandle::Init(UFG::qResourceHandle *this, unsigned int type_uid, unsigned int name_uid, UFG::qResourceInventory *inventory)
{
  UFG::qResourceInventory *v4; // rbx
  unsigned int v5; // esi
  UFG::qResourceHandle *v6; // rdi

  v4 = inventory;
  v5 = name_uid;
  v6 = this;
  UFG::qResourceHandle::Close(this);
  if ( v4 )
    v4->vfptr->InitHandle(v4, v6, v5);
}

// File Line: 288
// RVA: 0x167FB0
void __fastcall UFG::qResourceHandle::Close(UFG::qResourceHandle *this)
{
  UFG::qResourceData *v1; // rdi
  UFG::qResourceHandle *v2; // rbx
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceInventory *v4; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v5; // r8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v6; // rdx
  UFG::qResourceData *v7; // r8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v9; // rcx

  v1 = this->mData;
  v2 = this;
  if ( v1 )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v3, v1->mTypeUID);
    v5 = v2->mPrev;
    v6 = v2->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v7 = v2->mData;
    v2->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v2->mPrev;
    v4->vfptr->OnDetachHandle(v4, v2, v7);
    v2->mData = 0i64;
  }
  else
  {
    v8 = this->mNext;
    v9 = this->mPrev;
    v9->mNext = v8;
    v8->mPrev = v9;
    v2->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v2->mPrev;
  }
}

// File Line: 320
// RVA: 0x167F40
void __fastcall UFG::qResourceHandle::Close(UFG::qResourceHandle *this, UFG::qResourceInventory *inventory)
{
  UFG::qResourceHandle *v2; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v3; // r8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v4; // rax
  UFG::qResourceData *v5; // r8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v6; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rax

  v2 = this;
  if ( this->mData )
  {
    v3 = this->mPrev;
    v4 = this->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v5 = this->mData;
    this->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&this->mPrev;
    this->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&this->mPrev;
    inventory->vfptr->OnDetachHandle(inventory, this, v5);
    v2->mData = 0i64;
  }
  else
  {
    v6 = this->mPrev;
    v7 = v2->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v2->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v2->mPrev;
  }
}

// File Line: 349
// RVA: 0x1754B0
bool __fastcall UFG::qResourceHandle::IsDefault(UFG::qResourceHandle *this)
{
  UFG::qResourceData *v1; // rdi
  UFG::qResourceHandle *v2; // rbx
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceData *v5; // rcx

  v1 = this->mData;
  v2 = this;
  if ( !v1 )
    return 0;
  v4 = UFG::qResourceWarehouse::Instance();
  v5 = UFG::qResourceWarehouse::GetInventory(v4, v1->mTypeUID)->mDefaultResourceData;
  return v5 != 0i64 && v5 == v2->mData;
}

// File Line: 371
// RVA: 0x161B20
void __fastcall UFG::qResourceData::qResourceData(UFG::qResourceData *this)
{
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v1; // [rsp+28h] [rbp+10h]

  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  v1 = &this->mResourceHandles;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
}

// File Line: 390
// RVA: 0x161B60
void __fastcall UFG::qResourceData::qResourceData(UFG::qResourceData *this, unsigned int type_uid, unsigned int name_uid, const char *name)
{
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v4; // ST28_8

  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = name_uid;
  v4 = &this->mResourceHandles;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  this->mTypeUID = type_uid;
  UFG::qResourceData::SetDebugName(this, name);
}

// File Line: 402
// RVA: 0x17CD40
void __fastcall UFG::qResourceData::SetDebugName(UFG::qResourceData *this, const char *name)
{
  char *v2; // rbx
  const char *v3; // rdi
  UFG::qResourceData *v4; // rbp
  signed int v5; // esi
  const char *v6; // rdx
  char v7; // al
  signed int v8; // edx
  char v9; // al
  char v10; // al
  char v11; // al
  char v12; // al
  char v13; // al
  const char *v14; // rcx
  signed int v15; // er8
  char v16; // al
  char v17; // al
  char v18; // al
  char v19; // al
  char v20; // al
  char *v21; // rcx
  signed int v22; // er8
  const char *v23; // rdx
  char v24; // al
  char v25; // al

  v2 = this->mDebugName;
  v3 = name;
  v4 = this;
  v5 = 36;
  UFG::qMemSet(this->mDebugName, 0, 0x24u);
  if ( v3 )
  {
    v6 = v3;
    do
      v7 = *v6++;
    while ( v7 );
    v8 = (_DWORD)v6 - (_DWORD)v3 - 1;
    if ( v8 >= 36 )
    {
      v14 = v3;
      v15 = 21;
      if ( v2 )
      {
        do
        {
          v16 = *v14;
          *(++v2 - 1) = *v14;
          if ( !v16 )
            break;
          v17 = v14[1];
          *(++v2 - 1) = v17;
          if ( !v17 )
            break;
          v18 = v14[2];
          *(++v2 - 1) = v18;
          if ( !v18 )
            break;
          v19 = v14[3];
          *(++v2 - 1) = v19;
          if ( !v19 )
            break;
          v20 = v14[4];
          ++v2;
          v14 += 5;
          *(v2 - 1) = v20;
          if ( !v20 )
            break;
          v15 -= 5;
        }
        while ( v15 > 1 );
        if ( *(v2 - 1) )
          *v2 = 0;
      }
      v21 = &v4->mDebugName[21];
      v4->mDebugName[20] = 126;
      v22 = 15;
      v23 = &v3[v8 - 14];
      if ( v4 != (UFG::qResourceData *)-73i64 )
      {
        if ( !v23 )
          goto LABEL_32;
        do
        {
          v24 = *v23;
          *(++v21 - 1) = *v23;
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
LABEL_32:
          *v21 = 0;
      }
    }
    else if ( v2 )
    {
      do
      {
        v9 = *v3;
        *(++v2 - 1) = *v3;
        if ( !v9 )
          break;
        v10 = v3[1];
        *(++v2 - 1) = v10;
        if ( !v10 )
          break;
        v11 = v3[2];
        *(++v2 - 1) = v11;
        if ( !v11 )
          break;
        v12 = v3[3];
        *(++v2 - 1) = v12;
        if ( !v12 )
          break;
        v13 = v3[4];
        ++v2;
        v3 += 5;
        *(v2 - 1) = v13;
        if ( !v13 )
          break;
        v5 -= 5;
      }
      while ( v5 > 1 );
      if ( *(v2 - 1) )
        *v2 = 0;
    }
  }
}

// File Line: 441
// RVA: 0x161BE0
void __fastcall UFG::qResourceInventory::qResourceInventory(UFG::qResourceInventory *this, const char *name, unsigned int type_uid, unsigned int chunk_uid, unsigned int default_name_uid, unsigned int num_unsolved_hash_lists)
{
  unsigned int v6; // esi
  const char *v7; // rdi
  UFG::qResourceInventory *v8; // r14
  signed __int64 v9; // rbp
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v10; // r15
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v11; // rdx
  unsigned __int64 v12; // rcx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v13; // rax
  signed __int64 v14; // rbx
  unsigned __int8 v15; // cf
  unsigned __int64 v16; // rbx
  UFG::qMemoryPool *v17; // rcx
  char *v18; // rax
  UFG::qResourceWarehouse *v19; // rbx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v20; // rcx

  v6 = chunk_uid;
  v7 = name;
  v8 = this;
  v9 = 0i64;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = type_uid;
  v10 = (UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *)&this->mPrev;
  v10->mPrev = v10;
  v10->mNext = v10;
  this->vfptr = (UFG::qResourceInventoryVtbl *)&UFG::qResourceInventory::`vftable';
  v11 = &this->mResourceDatas;
  v11->mTree.mRoot.mParent = 0i64;
  v11->mTree.mRoot.mChild[0] = 0i64;
  v11->mTree.mRoot.mChild[1] = 0i64;
  v12 = (unsigned __int64)&this->mResourceDatas.mTree.mNULL;
  *(_QWORD *)v12 = 0i64;
  *(_QWORD *)(v12 + 8) = 0i64;
  *(_QWORD *)(v12 + 16) = 0i64;
  *(_QWORD *)v12 = v12 | *(_DWORD *)v12 & 1;
  v11->mTree.mNULL.mChild[0] = (UFG::qBaseNodeRB *)v12;
  v11->mTree.mNULL.mChild[1] = (UFG::qBaseNodeRB *)v12;
  *(_QWORD *)v12 &= 0xFFFFFFFFFFFFFFFEui64;
  v11->mTree.mNULL.mUID = 0;
  v11->mTree.mRoot.mParent = (UFG::qBaseNodeRB *)(v12 | (_QWORD)v11->mTree.mRoot.mParent & 1);
  v11->mTree.mRoot.mChild[0] = (UFG::qBaseNodeRB *)v12;
  v11->mTree.mRoot.mChild[1] = (UFG::qBaseNodeRB *)v12;
  v11->mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((_QWORD)v11->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
  v11->mTree.mRoot.mUID = -1;
  v11->mTree.mCount = 0;
  v13 = &v8->mNullHandles;
  v13->mNode.mPrev = &v13->mNode;
  v13->mNode.mNext = &v13->mNode;
  `eh vector constructor iterator'(
    v8->mInternalUnresolvedHandles,
    0x10ui64,
    4,
    (void (__fastcall *)(void *))UFG::qReflectHandleBase::qReflectHandleBase);
  v8->mDefaultResourceData = 0i64;
  v8->mDefaultResourceNameUID = default_name_uid;
  v8->mChunkUID = v6;
  v8->mName = v7;
  v8->mUnresolvedHandleLists = v8->mInternalUnresolvedHandles;
  *(_QWORD *)&v8->mNumUnresolvedHandleLists = 4i64;
  *(_QWORD *)&v8->mNumResourceBytes = 0i64;
  *(_QWORD *)&v8->mLastUpdate = 0i64;
  *(_QWORD *)&v8->mRemoveTime = 0i64;
  *(_QWORD *)&v8->mLoadTime = 0i64;
  v8->mInitHandleTime = 0.0;
  if ( num_unsolved_hash_lists > 4 )
  {
    v14 = 16i64 * num_unsolved_hash_lists;
    if ( !is_mul_ok(num_unsolved_hash_lists, 0x10ui64) )
      v14 = -1i64;
    v15 = __CFADD__(v14, 8i64);
    v16 = v14 + 8;
    if ( v15 )
      v16 = -1i64;
    v17 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v17 = UFG::gMainMemoryPool;
    }
    v18 = UFG::qMemoryPool::Allocate(v17, v16, "qResourceInventory.Hash", 0i64, 1u);
    if ( v18 )
    {
      *(_DWORD *)v18 = num_unsolved_hash_lists;
      v9 = (signed __int64)(v18 + 8);
      `eh vector constructor iterator'(
        v18 + 8,
        0x10ui64,
        num_unsolved_hash_lists,
        (void (__fastcall *)(void *))UFG::qReflectHandleBase::qReflectHandleBase);
    }
    v8->mUnresolvedHandleLists = (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)v9;
    v8->mNumUnresolvedHandleLists = num_unsolved_hash_lists;
  }
  v19 = UFG::qResourceWarehouse::Instance();
  UFG::qBaseTreeRB::Add(&v19->mInventoryTree.mTree, &v8->mNode);
  v20 = v19->mInventoryList.mNode.mPrev;
  v20->mNext = v10;
  v10->mPrev = v20;
  v10->mNext = &v19->mInventoryList.mNode;
  v19->mInventoryList.mNode.mPrev = v10;
  ++v19->mNumInventories;
}

// File Line: 503
// RVA: 0x1640D0
void __fastcall UFG::qResourceInventory::~qResourceInventory(UFG::qResourceInventory *this)
{
  UFG::qResourceInventory *v1; // rsi
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v2; // rdi
  UFG::qBaseNodeRB *v3; // rcx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *i; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v5; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v6; // rax
  unsigned int v7; // er9
  signed __int64 v8; // r8
  __int64 *j; // rax
  __int64 v10; // rdx
  _QWORD *v11; // rcx
  UFG::qResourceWarehouse *v12; // rbx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v13; // r14
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v14; // r8
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v15; // rdx
  Render::SkinningCacheNode *v16; // rbx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v17; // rcx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v18; // rax

  v1 = this;
  this->vfptr = (UFG::qResourceInventoryVtbl *)&UFG::qResourceInventory::`vftable';
  v2 = &this->mResourceDatas;
  v3 = &this->mResourceDatas.mTree.mNULL;
  v2->mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)v3 | (_QWORD)v2->mTree.mRoot.mParent & 1);
  v2->mTree.mRoot.mChild[0] = v3;
  v2->mTree.mRoot.mChild[1] = v3;
  v2->mTree.mCount = 0;
  for ( i = (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)v1->mNullHandles.mNode.mNext;
        i != &v1->mNullHandles;
        i = (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)v1->mNullHandles.mNode.mNext )
  {
    v5 = i->mNode.mPrev;
    v6 = i->mNode.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    i->mNode.mPrev = &i->mNode;
    i->mNode.mNext = &i->mNode;
  }
  v7 = 0;
  if ( v1->mNumUnresolvedHandleLists )
  {
    do
    {
      v8 = (signed __int64)&v1->mUnresolvedHandleLists[v7];
      for ( j = *(__int64 **)(v8 + 8); j != (__int64 *)v8; j = *(__int64 **)(v8 + 8) )
      {
        v10 = *j;
        v11 = (_QWORD *)j[1];
        *(_QWORD *)(v10 + 8) = v11;
        *v11 = v10;
        *j = (__int64)j;
        j[1] = (__int64)j;
      }
      ++v7;
    }
    while ( v7 < v1->mNumUnresolvedHandleLists );
  }
  v12 = UFG::qResourceWarehouse::Instance();
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)v12,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v1->mNode);
  v13 = (UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *)&v1->mPrev;
  v14 = v1->mPrev;
  v15 = v1->mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v13->mPrev = v13;
  v13->mNext = v13;
  --v12->mNumInventories;
  `eh vector destructor iterator'(
    v1->mInternalUnresolvedHandles,
    0x10ui64,
    4,
    (void (__fastcall *)(void *))UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::~qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>);
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::~qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>(&v1->mNullHandles);
  while ( v2->mTree.mCount )
  {
    v16 = UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1>::GetHead(v2);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)v2, &v16->mNode);
    if ( v16 )
    {
      UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::~qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>((UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)&v16->mCachedBufferPtr);
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v16);
    }
  }
  v2->mTree.mRoot.mParent = (UFG::qBaseNodeRB *)((unsigned __int64)&v2->mTree.mNULL | (_QWORD)v2->mTree.mRoot.mParent & 1);
  v2->mTree.mRoot.mChild[0] = &v2->mTree.mNULL;
  v2->mTree.mRoot.mChild[1] = &v2->mTree.mNULL;
  v2->mTree.mCount = 0;
  v17 = v13->mPrev;
  v18 = v1->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v13->mPrev = v13;
  v1->mNext = (UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *)&v1->mPrev;
}v13;
  v1->mNext = (UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> 

// File Line: 525
// RVA: 0x168030
void __fastcall UFG::qResourceInventory::Close(UFG::qResourceInventory *this)
{
  const char *v1; // r9
  UFG::qResourceInventory *v2; // rsi
  signed __int64 v3; // rdi
  UFG::qBaseNodeRB *v4; // rcx
  UFG::qBaseNodeRB *i; // rax
  const char *v6; // r9
  UFG::qResourceData *v7; // rbx

  v1 = this->mName;
  v2 = this;
  UFG::qPrintChannel::Print(&gInventoryChannel, OUTPUT_LEVEL_DEBUG, "[%s] Close()\n");
  if ( v2->mResourceDatas.mTree.mCount )
  {
    v3 = (signed __int64)&v2->mResourceDatas.mTree.mNULL;
    do
    {
      v4 = v2->mResourceDatas.mTree.mRoot.mChild[0];
      for ( i = v4->mChild[0]; i != (UFG::qBaseNodeRB *)v3; i = i->mChild[0] )
        v4 = i;
      v6 = v2->mName;
      v7 = 0i64;
      if ( v4 != (UFG::qBaseNodeRB *)v3 )
        v7 = (UFG::qResourceData *)v4;
      UFG::qPrintChannel::Print(
        &gInventoryChannel,
        OUTPUT_LEVEL_DEBUG,
        "[%s] WARNING: Remaining resource name = '%s'\n");
      v2->vfptr->Remove(v2, v7);
    }
    while ( v2->mResourceDatas.mTree.mCount );
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
void __fastcall UFG::qResourceInventory::InitHandle(UFG::qResourceInventory *this, UFG::qResourceHandle *handle, unsigned int name_uid, UFG::qResourceData *data)
{
  UFG::qResourceInventory *v4; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v5; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v6; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rax

  v4 = this;
  if ( data && data != this->mDefaultResourceData )
  {
    v5 = data->mResourceHandles.mNode.mPrev;
    v5->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&handle->mPrev;
    handle->mPrev = v5;
    handle->mNext = &data->mResourceHandles.mNode;
    data->mResourceHandles.mNode.mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&handle->mPrev;
  }
  else
  {
    if ( name_uid == 0xDEDEDEDE || name_uid == 0xFEFEFEFE || name_uid == -1 || name_uid == 0 )
      v6 = &this->mNullHandles;
    else
      v6 = &this->mUnresolvedHandleLists[name_uid % this->mNumUnresolvedHandleLists];
    v7 = v6->mNode.mPrev;
    v7->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&handle->mPrev;
    handle->mPrev = v7;
    handle->mNext = &v6->mNode;
    v6->mNode.mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&handle->mPrev;
    data = v4->mDefaultResourceData;
  }
  handle->mData = data;
  handle->mNameUID = name_uid;
  if ( data )
    (*(void (__fastcall **)(UFG::qResourceInventory *, UFG::qResourceHandle *, UFG::qResourceData *))&v4->vfptr->gap8[8])(
      v4,
      handle,
      data);
}

// File Line: 676
// RVA: 0x173970
void __fastcall UFG::qResourceInventory::InitHandle(UFG::qResourceInventory *this, UFG::qResourceHandle *handle, __int64 name_uid)
{
  UFG::qResourceInventory *v3; // rbx
  __int64 v4; // rcx
  unsigned int v5; // edi
  UFG::qResourceHandle *v6; // rsi
  BOOL v7; // eax

  v3 = this;
  v4 = 0i64;
  v5 = name_uid;
  v6 = handle;
  v7 = name_uid == -555819298;
  if ( !v7 && (_DWORD)name_uid != -16843010 && (_DWORD)name_uid != -1 && (_DWORD)name_uid != 0 )
    v4 = ((__int64 (__fastcall *)(UFG::qResourceInventory *, _QWORD, __int64, _QWORD))v3->vfptr->Get)(
           v3,
           (unsigned int)name_uid,
           name_uid,
           v7 | ((_DWORD)name_uid == -16843010) | ((_DWORD)name_uid == -1) | (unsigned int)((_DWORD)name_uid == 0));
  (*(void (__fastcall **)(UFG::qResourceInventory *, UFG::qResourceHandle *, _QWORD, __int64))v3->vfptr->gap8)(
    v3,
    v6,
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
  unsigned int v2; // edi
  UFG::qResourceData *v3; // r12
  UFG::qResourceInventory *v4; // rsi
  UFG::qBaseNodeRB *v5; // r8
  UFG::qBaseTreeVariableRB<unsigned __int64> *v6; // rdi
  UFG::qBaseNodeRB *v7; // rax
  char *v8; // r15
  UFG::qResourceData *v9; // r14
  UFG::qBaseTreeVariableRB<unsigned __int64> *v10; // rbx
  UFG::qBaseTreeVariableRB<unsigned __int64> *i; // rax
  UFG::qBaseTreeVariableRB<unsigned __int64> *v12; // rax
  unsigned int v13; // er13
  unsigned int v14; // er8
  int v15; // er13
  signed __int64 v16; // rbp
  signed __int64 *v17; // rsi
  signed __int64 *v18; // rdi
  signed __int64 *v19; // rax
  signed __int64 v20; // rcx
  signed __int64 **v21; // rax
  unsigned int v22; // eax
  UFG::qResourceData *v23; // r15
  signed __int64 v24; // rbp
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v25; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v26; // r14
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v27; // rax
  unsigned int v28; // edi
  UFG::qResourceWarehouse *v29; // rax
  signed __int64 v30; // rcx
  UFG::qResourceWarehouse *v31; // rdx
  signed __int64 v32; // r8
  unsigned int v33; // ecx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v34; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v35; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v36; // r8
  UFG::qResourceWarehouse *j; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v38; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v39; // rax
  const char *v40; // r9
  unsigned int v41; // ST28_4
  UFG::qBaseTreeVariableRB<unsigned __int64> *v42; // [rsp+40h] [rbp-58h]
  UFG::qResourceInventory *v43; // [rsp+A0h] [rbp+8h]
  UFG::qResourceData *v44; // [rsp+A8h] [rbp+10h]
  unsigned int v45; // [rsp+B0h] [rbp+18h]
  UFG::qBaseNodeRB *v46; // [rsp+B8h] [rbp+20h]

  v44 = data;
  v43 = this;
  v2 = data->mNode.mUID;
  v3 = data;
  v45 = data->mNode.mUID;
  v4 = this;
  if ( UFG::qResourceInventory::smHotSwapMode )
  {
    v5 = this->mResourceDatas.mTree.mRoot.mChild[0];
    v6 = (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mResourceDatas;
    v7 = v5->mChild[0];
    v8 = (char *)&this->mResourceDatas.mTree.mNULL;
    v42 = (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mResourceDatas;
    v46 = &this->mResourceDatas.mTree.mNULL;
    if ( v7 != &this->mResourceDatas.mTree.mNULL )
    {
      do
      {
        v5 = v7;
        v7 = v7->mChild[0];
      }
      while ( v7 != (UFG::qBaseNodeRB *)v8 );
    }
    v9 = 0i64;
    if ( v5 != (UFG::qBaseNodeRB *)v8 )
      v9 = (UFG::qResourceData *)v5;
    if ( v9 )
    {
      do
      {
        v10 = (UFG::qBaseTreeVariableRB<unsigned __int64> *)v9->mNode.mChild[1];
        if ( v8 == (char *)v10 )
        {
          v10 = (UFG::qBaseTreeVariableRB<unsigned __int64> *)((_QWORD)v9->mNode.mParent & 0xFFFFFFFFFFFFFFFEui64);
          if ( v9 == (UFG::qResourceData *)v10->mRoot.mChild[1] )
          {
            do
            {
              v12 = v10;
              v10 = (UFG::qBaseTreeVariableRB<unsigned __int64> *)((_QWORD)v10->mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
            }
            while ( v12 == (UFG::qBaseTreeVariableRB<unsigned __int64> *)v10->mRoot.mChild[1] );
          }
          if ( v10 == v6 )
            v10 = 0i64;
        }
        else
        {
          for ( i = (UFG::qBaseTreeVariableRB<unsigned __int64> *)v10->mRoot.mChild[0];
                i != (UFG::qBaseTreeVariableRB<unsigned __int64> *)v8;
                i = (UFG::qBaseTreeVariableRB<unsigned __int64> *)i->mRoot.mChild[0] )
          {
            v10 = i;
          }
        }
        v13 = v9->mNode.mUID;
        v14 = v3->mNode.mUID;
        if ( v13 == v14 )
        {
          v15 = ~v13;
          if ( v14 == -555819298 || v14 == -16843010 || v14 == -1 || v14 == 0 )
            v16 = (signed __int64)&v4->mNullHandles;
          else
            v16 = (signed __int64)&v4->mUnresolvedHandleLists[v14 % v4->mNumUnresolvedHandleLists];
          v17 = (signed __int64 *)v9->mResourceHandles.mNode.mNext;
          if ( v17 != (signed __int64 *)&v9->mResourceHandles )
          {
            do
            {
              v18 = (signed __int64 *)v17[1];
              v43->vfptr->OnDetachHandle(v43, (UFG::qResourceHandle *)v17, v9);
              v19 = (signed __int64 *)v17[1];
              v20 = *v17;
              v17[2] = 0i64;
              *(_QWORD *)(v20 + 8) = v19;
              *v19 = v20;
              *v17 = (signed __int64)v17;
              v17[1] = (signed __int64)v17;
              v21 = *(signed __int64 ***)(v16 + 8);
              *(_QWORD *)(v16 + 8) = v17;
              v17[1] = (signed __int64)v21;
              *v17 = v16;
              *v21 = v17;
              v17 = v18;
            }
            while ( v18 != (signed __int64 *)&v9->mResourceHandles );
            v8 = (char *)v46;
            v6 = v42;
          }
          UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(v6, (UFG::qBaseNodeVariableRB<unsigned __int64> *)v9);
          v9->mNode.mUID = v15;
          UFG::qBaseTreeRB::Add((UFG::qBaseTreeRB *)v6, &v9->mNode);
          v4 = v43;
          v3 = v44;
        }
        v9 = (UFG::qResourceData *)v10;
      }
      while ( v10 );
    }
    v2 = v45;
  }
  UFG::qBaseTreeRB::Add(&v4->mResourceDatas.mTree, &v3->mNode);
  v22 = v4->mDefaultResourceNameUID;
  v23 = 0i64;
  if ( v22 && v2 == v22 )
  {
    v4->mDefaultResourceData = v3;
    v23 = v3;
  }
  if ( v2 == 0xDEDEDEDE || v2 == 0xFEFEFEFE || v2 == -1 || v2 == 0 )
    v24 = (signed __int64)&v4->mNullHandles;
  else
    v24 = (signed __int64)&v4->mUnresolvedHandleLists[v2 % v4->mNumUnresolvedHandleLists];
  v25 = *(UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)(v24 + 8);
  if ( v25 != (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)v24 )
  {
    do
    {
      v26 = v25->mNext;
      if ( LODWORD(v25[1].mNext) == v2 )
      {
        v27 = v25[1].mPrev;
        if ( v27 )
        {
          v28 = (unsigned int)v27[3].mPrev;
          v29 = UFG::qResourceWarehouse::Instance();
          v30 = (signed __int64)v29->mLastInventory;
          v31 = v29;
          if ( !v30 || v29->mLastTypeUID != v28 )
          {
            if ( !v28 )
              goto LABEL_44;
            v32 = (signed __int64)&v29->mInventoryTree.mTree.mNULL;
            if ( v29 == (UFG::qResourceWarehouse *)&v29->mInventoryTree.mTree.mNULL )
              goto LABEL_44;
            while ( 1 )
            {
              v33 = v29->mInventoryTree.mTree.mRoot.mUID;
              if ( v29 != v31 && v33 == v28 )
                break;
              if ( v28 > v33 )
                v29 = (UFG::qResourceWarehouse *)v29->mInventoryTree.mTree.mRoot.mChild[1];
              else
                v29 = (UFG::qResourceWarehouse *)v29->mInventoryTree.mTree.mRoot.mChild[0];
              if ( v29 == (UFG::qResourceWarehouse *)v32 )
                goto LABEL_44;
            }
            for ( j = (UFG::qResourceWarehouse *)v29->mInventoryTree.mTree.mRoot.mChild[0];
                  j;
                  j = (UFG::qResourceWarehouse *)j->mInventoryTree.mTree.mRoot.mChild[0] )
            {
              if ( j->mInventoryTree.mTree.mRoot.mUID != v28 )
                break;
              v29 = j;
            }
            if ( v29 )
              v30 = (signed __int64)&v29[-1].mUnloadTime;
            else
LABEL_44:
              v30 = 0i64;
            v31->mLastInventory = (UFG::qResourceInventory *)v30;
            v31->mLastTypeUID = v28;
          }
          v34 = v25->mPrev;
          v35 = v25->mNext;
          v34->mNext = v35;
          v35->mPrev = v34;
          v36 = v25[1].mPrev;
          v25->mPrev = v25;
          v25->mNext = v25;
          (*(void (__fastcall **)(signed __int64, UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *, UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *))(*(_QWORD *)v30 + 24i64))(
            v30,
            v25,
            v36);
          v2 = v45;
          v25[1].mPrev = 0i64;
        }
        else
        {
          v38 = v25->mPrev;
          v38->mNext = v26;
          v26->mPrev = v38;
          v25->mPrev = v25;
          v25->mNext = v25;
        }
        v25[1].mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)v3;
        v39 = v3->mResourceHandles.mNode.mPrev;
        v39->mNext = v25;
        v25->mNext = &v3->mResourceHandles.mNode;
        v25->mPrev = v39;
        v3->mResourceHandles.mNode.mPrev = v25;
        (*(void (__fastcall **)(UFG::qResourceInventory *, UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *, UFG::qResourceData *))&v4->vfptr->gap8[8])(
          v4,
          v25,
          v3);
      }
      else if ( v23 )
      {
        v25[1].mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)v23;
      }
      v25 = v26;
    }
    while ( v26 != (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)v24 );
  }
  ++v4->mNumResourceData;
  ++v4->mTransactionNum;
  v40 = v4->mName;
  v4->mDefaultResourceData;
  v41 = v3->mNode.mUID;
  UFG::qPrintChannel::Print(&gInventoryChannel, OUTPUT_LEVEL_DEBUG, "[%s] ADD%s - 0x%08x - %s\n");
}

// File Line: 860
// RVA: 0x17A370
void __fastcall UFG::qResourceInventory::Remove(UFG::qResourceInventory *this, UFG::qResourceData *data)
{
  unsigned int v2; // edi
  UFG::qResourceInventory *v3; // rbx
  UFG::qResourceData *v4; // r13
  __int64 v5; // rax
  unsigned int v6; // esi
  __int64 v7; // r14
  signed int v8; // er12
  signed __int64 v9; // rbp
  __int64 *v10; // rdi
  __int64 v11; // rcx
  _QWORD *v12; // rax
  UFG::qResourceHandle *v13; // rdx
  __int64 **v14; // rax
  UFG::qResourceData *v15; // rdx
  signed __int64 v16; // rcx
  __int64 i; // rax
  const char *v18; // r9
  unsigned int v19; // ST20_4

  v2 = data->mNode.mUID;
  v3 = this;
  v4 = data;
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mResourceDatas,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)data);
  v5 = (__int64)v3->vfptr->Get(v3, v2);
  v6 = 0;
  v7 = v5;
  v8 = 0;
  if ( v3->mDefaultResourceData == v4 )
  {
    v3->mDefaultResourceData = (UFG::qResourceData *)v5;
    v8 = 1;
  }
  if ( v5 )
  {
    v9 = v5 + 32;
  }
  else
  {
    if ( v2 == -555819298 || v2 == -16843010 || v2 == -1 || v2 == 0 )
      v9 = (signed __int64)&v3->mNullHandles;
    else
      v9 = (signed __int64)&v3->mUnresolvedHandleLists[v2 % v3->mNumUnresolvedHandleLists];
    v7 = (__int64)v3->mDefaultResourceData;
  }
  for ( ;
        (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)v4->mResourceHandles.mNode.mNext != &v4->mResourceHandles;
        *v14 = v10 )
  {
    v10 = (__int64 *)v4->mResourceHandles.mNode.mNext;
    v11 = *v10;
    v12 = (_QWORD *)v10[1];
    v13 = (UFG::qResourceHandle *)v4->mResourceHandles.mNode.mNext;
    *(_QWORD *)(v11 + 8) = v12;
    *v12 = v11;
    *v10 = (__int64)v10;
    v10[1] = (__int64)v10;
    v3->vfptr->OnDetachHandle(v3, v13, v4);
    v10[2] = v7;
    if ( v7 )
      (*(void (__fastcall **)(UFG::qResourceInventory *, __int64 *, __int64))&v3->vfptr->gap8[8])(v3, v10, v7);
    v14 = *(__int64 ***)(v9 + 8);
    *(_QWORD *)(v9 + 8) = v10;
    *v10 = v9;
    v10[1] = (__int64)v14;
  }
  if ( v8 )
  {
    v15 = v3->mDefaultResourceData;
    if ( v3->mNumUnresolvedHandleLists > 0 )
    {
      do
      {
        v16 = (signed __int64)&v3->mUnresolvedHandleLists[v6];
        for ( i = *(_QWORD *)(v16 + 8); i != v16; i = *(_QWORD *)(i + 8) )
          *(_QWORD *)(i + 16) = v15;
        ++v6;
      }
      while ( v6 < v3->mNumUnresolvedHandleLists );
    }
  }
  --v3->mNumResourceData;
  ++v3->mTransactionNum;
  v18 = v3->mName;
  v19 = v4->mNode.mUID;
  UFG::qPrintChannel::Print(&gInventoryChannel, OUTPUT_LEVEL_DEBUG, "[%s] REMOVE - 0x%08x - %s\n");
}

// File Line: 966
// RVA: 0x16F010
UFG::qResourceData *__fastcall UFG::qResourceInventory::Get(UFG::qResourceInventory *this, unsigned int name_uid)
{
  UFG::qResourceData *v2; // r8
  UFG::qResourceData *result; // rax
  UFG::qResourceData *v4; // r9
  bool i; // zf
  unsigned int v6; // ecx
  UFG::qResourceData *j; // rcx

  if ( name_uid )
  {
    v2 = (UFG::qResourceData *)&this->mResourceDatas;
    result = (UFG::qResourceData *)&this->mResourceDatas;
    v4 = (UFG::qResourceData *)&this->mResourceDatas.mTree.mNULL;
    for ( i = &this->mResourceDatas == (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)&this->mResourceDatas.mTree.mNULL;
          !i;
          i = result == v4 )
    {
      v6 = result->mNode.mUID;
      if ( result != v2 && v6 == name_uid )
      {
        for ( j = (UFG::qResourceData *)result->mNode.mChild[0]; j; j = (UFG::qResourceData *)j->mNode.mChild[0] )
        {
          if ( j->mNode.mUID != name_uid )
            break;
          result = j;
        }
        return result;
      }
      if ( name_uid > v6 )
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
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v2; // rbp
  const char *v3; // rsi
  UFG::qBaseNodeRB *v4; // rcx
  signed __int64 v5; // rbx
  UFG::qBaseNodeRB *v6; // rax
  UFG::qBaseNodeRB *v7; // r11
  const char *v8; // r9
  signed int v9; // er10
  char v10; // dl
  char v11; // r8
  UFG::qBaseNodeRB *v13; // rcx
  UFG::qBaseNodeRB *i; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v15; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v16; // rcx

  v2 = &this->mResourceDatas;
  v3 = name;
  v4 = this->mResourceDatas.mTree.mRoot.mChild[0];
  v5 = (signed __int64)&v2->mTree.mNULL;
  v6 = v4->mChild[0];
  if ( v6 != &v2->mTree.mNULL )
  {
    do
    {
      v4 = v6;
      v6 = v6->mChild[0];
    }
    while ( v6 != (UFG::qBaseNodeRB *)v5 );
  }
  v7 = 0i64;
  if ( v4 != (UFG::qBaseNodeRB *)v5 )
    v7 = v4;
  while ( v7 )
  {
    v8 = v3;
    if ( v7 != (UFG::qBaseNodeRB *)-52i64 && v3 )
    {
      v9 = -1;
      while ( 1 )
      {
        v10 = v8[(char *)v7 - v3 + 52];
        if ( v8[(char *)v7 - v3 + 52] <= 122 && v8[(char *)v7 - v3 + 52] >= 97 )
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
      if ( 0 == v11 )
        return v7;
    }
LABEL_18:
    v13 = v7->mChild[1];
    if ( (UFG::qBaseNodeRB *)v5 == v13 )
    {
      v15 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((_QWORD)v7->mParent & 0xFFFFFFFFFFFFFFFEui64);
      if ( v7 == v15->mTree.mRoot.mChild[1] )
      {
        do
        {
          v16 = v15;
          v15 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((_QWORD)v15->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
        }
        while ( v16 == (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v15->mTree.mRoot.mChild[1] );
      }
      v7 = &v15->mTree.mRoot;
      if ( v15 == v2 )
        v7 = 0i64;
    }
    else
    {
      for ( i = v13->mChild[0]; i != (UFG::qBaseNodeRB *)v5; i = i->mChild[0] )
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
  unsigned int v2; // eax
  unsigned int v3; // edi
  UFG::qResourceInventory *v4; // rbx

  v2 = this->mChunkUID;
  v3 = chunk->mDataSize;
  v4 = this;
  if ( !v2 || chunk->mUID != v2 )
    return 0i64;
  this->vfptr->Add(this, (UFG::qResourceData *)((char *)&chunk[1] + chunk->mDataOffset));
  v4->mNumResourceBytes += v3;
  return 1i64;
}

// File Line: 1038
// RVA: 0x17F130
signed __int64 __fastcall UFG::qResourceInventory::Unload(UFG::qResourceInventory *this, UFG::qChunk *chunk)
{
  unsigned int v2; // eax
  unsigned int v3; // edi
  UFG::qResourceInventory *v4; // rbx

  v2 = this->mChunkUID;
  v3 = chunk->mDataSize;
  v4 = this;
  if ( !v2 || chunk->mUID != v2 )
    return 0i64;
  this->vfptr->Remove(this, (UFG::qResourceData *)((char *)&chunk[1] + chunk->mDataOffset));
  v4->mNumResourceBytes -= v3;
  return 1i64;
}

// File Line: 1090
// RVA: 0x178B00
__int64 __fastcall UFG::qResourceInventory::PreMove(UFG::qResourceInventory *this, UFG::qChunk *chunk)
{
  unsigned int v2; // eax
  UFG::qChunk *v3; // rbx
  UFG::qResourceInventory *v4; // rdi

  v2 = this->mChunkUID;
  v3 = chunk;
  v4 = this;
  if ( !v2 || !chunk || chunk->mUID != v2 )
    return 0i64;
  this->vfptr->OnPreMove(this, (UFG::qResourceData *)((char *)&chunk[1] + chunk->mDataOffset));
  return v4->vfptr->Unload(v4, v3);
}

// File Line: 1099
// RVA: 0x178940
signed __int64 __fastcall UFG::qResourceInventory::PostMove(UFG::qResourceInventory *this, UFG::qChunk *chunk)
{
  UFG::qChunk *v2; // rdi
  UFG::qResourceInventory *v3; // rbx

  v2 = chunk;
  v3 = this;
  if ( !((unsigned int (*)(void))this->vfptr->Load)() )
    return 0i64;
  v3->vfptr->OnPostMove(v3, (UFG::qResourceData *)((char *)&v2[1] + v2->mDataOffset));
  return 1i64;
}

// File Line: 1120
// RVA: 0x1794F0
void __fastcall UFG::qResourceInventory::PrintContents(UFG::qResourceInventory *this)
{
  UFG::qResourceInventory *v1; // rsi
  UFG::qBaseNodeRB *v2; // rcx
  signed __int64 v3; // rsi
  UFG::qBaseNodeRB *v4; // rax
  signed __int64 i; // rdi
  UFG::qBaseNodeRB *v6; // rbx
  UFG::qBaseNodeRB *v7; // rcx
  UFG::qBaseNodeRB *j; // rax
  UFG::qBaseNodeRB *v9; // rax
  UFG::qBaseNodeRB *v10; // rcx

  v1 = this;
  UFG::qPrintf("Contents of Inventory '%.64s' %d items\n", this->mName, this->mNumResourceData);
  v2 = v1->mResourceDatas.mTree.mRoot.mChild[0];
  v3 = (signed __int64)&v1->mResourceDatas;
  v4 = v2->mChild[0];
  for ( i = v3 + 0x20; v4 != (UFG::qBaseNodeRB *)i; v4 = v4->mChild[0] )
    v2 = v4;
  v6 = 0i64;
  if ( v2 != (UFG::qBaseNodeRB *)i )
    v6 = v2;
  while ( v6 )
  {
    UFG::qPrintf(
      "  - Resource TypeUID:0x%08x DataUID:0x%08x Memory:0x%08x Name:'%.36s'\n",
      LODWORD(v6[1].mChild[1]),
      v6->mUID,
      v6,
      (char *)&v6[1].mChild[1] + 4);
    v7 = v6->mChild[1];
    if ( (UFG::qBaseNodeRB *)i == v7 )
    {
      v9 = (UFG::qBaseNodeRB *)((_QWORD)v6->mParent & 0xFFFFFFFFFFFFFFFEui64);
      if ( v6 == v9->mChild[1] )
      {
        do
        {
          v10 = v9;
          v9 = (UFG::qBaseNodeRB *)((_QWORD)v9->mParent & 0xFFFFFFFFFFFFFFFEui64);
        }
        while ( v10 == v9->mChild[1] );
      }
      v6 = v9;
      if ( v9 == (UFG::qBaseNodeRB *)v3 )
        v6 = 0i64;
    }
    else
    {
      for ( j = v7->mChild[0]; j != (UFG::qBaseNodeRB *)i; j = j->mChild[0] )
        v7 = j;
      v6 = v7;
    }
  }
}

// File Line: 1153
// RVA: 0x164290
UFG::qResourceWarehouse::~qResourceWarehouse

// File Line: 1162
// RVA: 0x174040
UFG::qResourceWarehouse *__fastcall UFG::qResourceWarehouse::Instance()
{
  if ( !(_S3_5 & 1) )
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
  UFG::qBaseNodeRB *v1; // rdx
  UFG::qResourceWarehouse *v2; // rdi
  UFG::qResourceWarehouse *v3; // rsi
  UFG::qResourceWarehouse *v4; // rax
  UFG::qBaseNodeRB *v5; // rbx
  unsigned int *v6; // rbx
  UFG::qResourceWarehouse *v7; // rax
  UFG::qBaseNodeRB *v8; // rbx
  UFG::qResourceWarehouse *i; // rcx
  UFG::qResourceWarehouse *v10; // rcx

  v1 = this->mInventoryTree.mTree.mRoot.mChild[0];
  v2 = (UFG::qResourceWarehouse *)((char *)this + 32);
  v3 = this;
  v4 = (UFG::qResourceWarehouse *)v1->mChild[0];
  if ( v4 != (UFG::qResourceWarehouse *)&this->mInventoryTree.mTree.mNULL )
  {
    do
    {
      v1 = &v4->mInventoryTree.mTree.mRoot;
      v4 = (UFG::qResourceWarehouse *)v4->mInventoryTree.mTree.mRoot.mChild[0];
    }
    while ( v4 != v2 );
  }
  v5 = 0i64;
  if ( v1 != (UFG::qBaseNodeRB *)v2 )
    v5 = v1;
  if ( !v5 )
    goto LABEL_7;
  v6 = &v5[-1].mUID;
  while ( v6 )
  {
    (*(void (__fastcall **)(unsigned int *))(*(_QWORD *)v6 + 48i64))(v6);
    v7 = (UFG::qResourceWarehouse *)*((_QWORD *)v6 + 3);
    v8 = (UFG::qBaseNodeRB *)(v6 + 2);
    if ( v2 != v7 )
    {
      for ( i = (UFG::qResourceWarehouse *)v7->mInventoryTree.mTree.mRoot.mChild[0];
            i != v2;
            i = (UFG::qResourceWarehouse *)i->mInventoryTree.mTree.mRoot.mChild[0] )
      {
        v7 = i;
      }
      goto LABEL_16;
    }
    v7 = (UFG::qResourceWarehouse *)((_QWORD)v8->mParent & 0xFFFFFFFFFFFFFFFEui64);
    if ( v8 == v7->mInventoryTree.mTree.mRoot.mChild[1] )
    {
      do
      {
        v10 = v7;
        v7 = (UFG::qResourceWarehouse *)((_QWORD)v7->mInventoryTree.mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
      }
      while ( v10 == (UFG::qResourceWarehouse *)v7->mInventoryTree.mTree.mRoot.mChild[1] );
    }
    if ( v7 == v3 )
    {
LABEL_7:
      v6 = 0i64;
    }
    else
    {
LABEL_16:
      if ( !v7 )
        goto LABEL_7;
      v6 = (unsigned int *)&v7[-1].mUnloadTime;
    }
  }
}

// File Line: 1209
// RVA: 0x170B80
UFG::qResourceInventory *__fastcall UFG::qResourceWarehouse::GetInventory(UFG::qResourceWarehouse *this, unsigned int type_uid)
{
  UFG::qResourceInventory *result; // rax
  UFG::qResourceWarehouse *v3; // r8
  UFG::qResourceWarehouse *v4; // r9
  UFG::qResourceWarehouse *v5; // rax
  bool i; // zf
  unsigned int v7; // ecx
  UFG::qResourceWarehouse *j; // rcx

  result = this->mLastInventory;
  v3 = this;
  if ( !result || this->mLastTypeUID != type_uid )
  {
    if ( type_uid )
    {
      v4 = (UFG::qResourceWarehouse *)((char *)this + 32);
      v5 = this;
      for ( i = this == (UFG::qResourceWarehouse *)&this->mInventoryTree.mTree.mNULL; !i; i = v5 == v4 )
      {
        v7 = v5->mInventoryTree.mTree.mRoot.mUID;
        if ( v5 != v3 && v7 == type_uid )
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
            v3->mLastTypeUID = type_uid;
            v3->mLastInventory = result;
            return result;
          }
          break;
        }
        if ( type_uid > v7 )
          v5 = (UFG::qResourceWarehouse *)v5->mInventoryTree.mTree.mRoot.mChild[1];
        else
          v5 = (UFG::qResourceWarehouse *)v5->mInventoryTree.mTree.mRoot.mChild[0];
      }
    }
    result = 0i64;
    v3->mLastTypeUID = type_uid;
    v3->mLastInventory = 0i64;
  }
  return result;
}

// File Line: 1226
// RVA: 0x165B60
void __fastcall UFG::qResourceWarehouse::Add(UFG::qResourceWarehouse *this, UFG::qResourceData *data)
{
  UFG::qResourceData *v2; // rbx
  UFG::qResourceInventory *v3; // rax

  v2 = data;
  v3 = UFG::qResourceWarehouse::GetInventory(this, data->mTypeUID);
  if ( v3 )
    v3->vfptr->Add(v3, v2);
}

// File Line: 1248
// RVA: 0x17A530
void __fastcall UFG::qResourceWarehouse::Remove(UFG::qResourceWarehouse *this, UFG::qResourceData *data)
{
  UFG::qResourceData *v2; // rbx
  UFG::qResourceInventory *v3; // rax

  v2 = data;
  if ( (_QWORD)data->mNode.mParent & 0xFFFFFFFFFFFFFFFEui64 || *(_OWORD *)data->mNode.mChild != 0i64 )
  {
    v3 = UFG::qResourceWarehouse::GetInventory(this, data->mTypeUID);
    if ( v3 )
      v3->vfptr->Remove(v3, v2);
  }
}

// File Line: 1274
// RVA: 0x16B980
UFG::qResourceWarehouse::DebugGet

// File Line: 1325
// RVA: 0x176B50
void __fastcall UFG::qResourceWarehouse::Load(UFG::qResourceWarehouse *this, void *buffer, __int64 num_bytes)
{
  int *v3; // rdi
  UFG::qResourceWarehouse *v4; // r14
  char *v5; // r12
  UFG::qResourceInventory *v6; // rsi
  int v7; // ebp
  __int64 v8; // r9
  unsigned __int64 v9; // r15
  UFG::qResourceInventory *v10; // rbx
  unsigned int v11; // eax
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v12; // rcx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v13; // rdx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v14; // rax

  v3 = (int *)buffer;
  v4 = this;
  v5 = (char *)buffer + (unsigned int)num_bytes;
  if ( buffer < v5 )
  {
    v6 = (UFG::qResourceInventory *)&this->mInventoryTree.mTree.mNULL;
    do
    {
      v7 = *v3;
      v8 = 0i64;
      v9 = (unsigned __int64)v3 + ((v3[1] + 3) & 0xFFFFFFFC) + 16;
      v10 = (UFG::qResourceInventory *)&v4->mInventoryList.mNode.mNext[-3].mNext;
      do
      {
        if ( v10 == v6 )
          break;
        if ( v10->mChunkUID != 0 && v10->mChunkUID == v7 )
        {
          v11 = ((__int64 (__fastcall *)(UFG::qResourceInventory *, int *, __int64, __int64))v10->vfptr->Load)(
                  v10,
                  v3,
                  num_bytes,
                  v8);
          v8 = v11;
          if ( v11 )
          {
            v12 = v10->mNext;
            v13 = v10->mPrev;
            num_bytes = (__int64)&v10->mPrev;
            v13->mNext = v12;
            v12->mPrev = v13;
            *(_QWORD *)num_bytes = num_bytes;
            *(_QWORD *)(num_bytes + 8) = num_bytes;
            v14 = v4->mInventoryList.mNode.mNext;
            v4->mInventoryList.mNode.mNext = (UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *)&v10->mPrev;
            *(_QWORD *)(num_bytes + 8) = v14;
            *(_QWORD *)num_bytes = (char *)v4 + 72;
            v14->mPrev = (UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *)&v10->mPrev;
          }
        }
        v10 = (UFG::qResourceInventory *)&v10->mNext[-3].mNext;
      }
      while ( !(_DWORD)v8 );
      v3 = (int *)v9;
    }
    while ( v9 < (unsigned __int64)v5 );
  }
}

// File Line: 1443
// RVA: 0x17F180
void __fastcall UFG::qResourceWarehouse::Unload(UFG::qResourceWarehouse *this, void *buffer, __int64 num_bytes)
{
  int *v3; // rdi
  UFG::qResourceWarehouse *v4; // r14
  char *v5; // r12
  UFG::qResourceInventory *v6; // rsi
  int v7; // ebp
  __int64 v8; // r9
  unsigned __int64 v9; // r15
  UFG::qResourceInventory *v10; // rbx
  unsigned int v11; // eax
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v12; // rcx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v13; // rdx
  UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *v14; // rax

  v3 = (int *)buffer;
  v4 = this;
  v5 = (char *)buffer + (unsigned int)num_bytes;
  if ( buffer < v5 )
  {
    v6 = (UFG::qResourceInventory *)&this->mInventoryTree.mTree.mNULL;
    do
    {
      v7 = *v3;
      v8 = 0i64;
      v9 = (unsigned __int64)v3 + ((v3[1] + 3) & 0xFFFFFFFC) + 16;
      v10 = (UFG::qResourceInventory *)&v4->mInventoryList.mNode.mNext[-3].mNext;
      do
      {
        if ( v10 == v6 )
          break;
        if ( v10->mChunkUID != 0 && v10->mChunkUID == v7 )
        {
          v11 = ((__int64 (__fastcall *)(UFG::qResourceInventory *, int *, __int64, __int64))v10->vfptr->Unload)(
                  v10,
                  v3,
                  num_bytes,
                  v8);
          v8 = v11;
          if ( v11 )
          {
            v12 = v10->mNext;
            v13 = v10->mPrev;
            num_bytes = (__int64)&v10->mPrev;
            v13->mNext = v12;
            v12->mPrev = v13;
            *(_QWORD *)num_bytes = num_bytes;
            *(_QWORD *)(num_bytes + 8) = num_bytes;
            v14 = v4->mInventoryList.mNode.mNext;
            v4->mInventoryList.mNode.mNext = (UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *)&v10->mPrev;
            *(_QWORD *)(num_bytes + 8) = v14;
            *(_QWORD *)num_bytes = (char *)v4 + 72;
            v14->mPrev = (UFG::qNode<UFG::qResourceInventory,UFG::qResourceInventory> *)&v10->mPrev;
          }
        }
        v10 = (UFG::qResourceInventory *)&v10->mNext[-3].mNext;
      }
      while ( !(_DWORD)v8 );
      v3 = (int *)v9;
    }
    while ( v9 < (unsigned __int64)v5 );
  }
}


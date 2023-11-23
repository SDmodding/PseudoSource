// File Line: 35
// RVA: 0x930B0
Illusion::MemImageSchema *__fastcall Illusion::Factory::NewStateBlock(
        const char *name,
        unsigned int name_uid,
        unsigned int num_values,
        unsigned int byte_size,
        Illusion::MemImageSchema *schema,
        UFG::qMemoryPool *memory_pool,
        unsigned __int64 allocation_params)
{
  Illusion::MemImageSchema *v11; // r10
  unsigned int v12; // r9d
  signed int v13; // r8d
  __int64 mNumMemStructures; // rcx
  char *v15; // rdx
  signed int v16; // r8d
  __int64 v17; // rcx
  char *v18; // rdx
  Illusion::StateBlock *v19; // rbx
  __int64 v21[5]; // [rsp+20h] [rbp-28h] BYREF

  v21[1] = -2i64;
  v11 = &Illusion::gMemImageSchema;
  if ( schema )
    v11 = schema;
  v11->mCurrSize = 0i64;
  v11->mCurrSerializeIndex = 0;
  v11->mBaseFilePosition = 0i64;
  v12 = 4 * num_values;
  v11->mNumMemStructures = 1;
  v11->mMemStructure[0].mName = "StateBlock";
  v11->mMemStructure[0].mBaseOffset = v11->mCurrSize;
  v11->mMemStructure[0].mSize = 128;
  v11->mMemStructure[0].mPointer = 0i64;
  v11->mMemStructure[0].mFixupOffsetPointer = 0i64;
  v11->mMemStructure[0].mFixupOffset = 0i64;
  schema = (Illusion::MemImageSchema *)v11->mCurrSize;
  v11->mMemStructure[0].mPointer = (void **)&schema;
  v11->mCurrSize = (v11->mCurrSize + 143) & 0xFFFFFFFFFFFFFFF0ui64;
  v13 = (byte_size + 15) & 0xFFFFFFF0;
  mNumMemStructures = v11->mNumMemStructures;
  v15 = (char *)v11 + 48 * mNumMemStructures;
  v11->mNumMemStructures = mNumMemStructures + 1;
  *((_QWORD *)v15 + 2) = "StateBlockData";
  *((_QWORD *)v15 + 3) = v11->mCurrSize;
  *((_DWORD *)v15 + 8) = v13;
  *((_QWORD *)v15 + 7) = 0i64;
  *((_QWORD *)v15 + 6) = 0i64;
  *((_QWORD *)v15 + 5) = v21;
  v11->mCurrSize = (v13 + v11->mCurrSize + 15) & 0xFFFFFFFFFFFFFFF0ui64;
  v16 = (v12 + 0xF) & 0xFFFFFFF0;
  v17 = v11->mNumMemStructures;
  v18 = (char *)v11 + 48 * v17;
  v11->mNumMemStructures = v17 + 1;
  *((_QWORD *)v18 + 2) = "StateBlockHeaders";
  *((_QWORD *)v18 + 3) = v11->mCurrSize;
  *((_DWORD *)v18 + 8) = v16;
  *((_QWORD *)v18 + 5) = 0i64;
  *((_QWORD *)v18 + 7) = 0i64;
  *((_QWORD *)v18 + 6) = 0i64;
  v21[0] = v11->mCurrSize;
  *((_QWORD *)v18 + 5) = v21;
  v11->mCurrSize += v16;
  Illusion::MemImageSchema::Allocate(v11, memory_pool, allocation_params);
  v19 = (Illusion::StateBlock *)schema;
  v21[2] = (__int64)schema;
  if ( schema )
  {
    UFG::qResourceData::qResourceData((UFG::qResourceData *)schema, 0x4D04C7F2u, name_uid, name);
    v19->mPrev = &v19->UFG::qNode<Illusion::StateBlock,Illusion::StateBlock>;
    v19->mNext = &v19->UFG::qNode<Illusion::StateBlock,Illusion::StateBlock>;
    v19->mNameUID = UFG::qStringHashUpper32(name, 0xFFFFFFFF);
    v19->mNumValues = num_values;
    v19->mDataByteSize = byte_size;
  }
  return schema;
}

// File Line: 106
// RVA: 0x92CB0
Illusion::Material *__fastcall Illusion::Factory::NewMaterial(
        const char *name,
        unsigned int name_uid,
        unsigned int num_params,
        Illusion::MemImageSchema *schema,
        UFG::qMemoryPool *memory_pool,
        unsigned __int64 allocation_params)
{
  Illusion::MemImageSchema *v9; // rcx
  __int64 v10; // r9
  __int64 mNumMemStructures; // rdx
  char *v12; // r8
  Illusion::Material *v13; // r9
  __int64 v14; // rdx
  char *v15; // r8
  UFG::qOffset64<Illusion::MaterialUser *> *p_mMaterialUser; // r9
  Illusion::MaterialUser *v18[2]; // [rsp+20h] [rbp-28h] BYREF
  Illusion::Material *v19; // [rsp+30h] [rbp-18h]
  Illusion::Material *mCurrSize; // [rsp+68h] [rbp+20h] BYREF

  v18[1] = (Illusion::MaterialUser *)-2i64;
  v9 = &Illusion::gMemImageSchema;
  if ( schema )
    v9 = schema;
  v9->mCurrSize = 0i64;
  v9->mCurrSerializeIndex = 0;
  v9->mBaseFilePosition = 0i64;
  v9->mNumMemStructures = 1;
  v9->mMemStructure[0].mName = "Material";
  v9->mMemStructure[0].mBaseOffset = v9->mCurrSize;
  v9->mMemStructure[0].mSize = 128;
  v9->mMemStructure[0].mPointer = 0i64;
  v9->mMemStructure[0].mFixupOffsetPointer = 0i64;
  v9->mMemStructure[0].mFixupOffset = 0i64;
  mCurrSize = (Illusion::Material *)v9->mCurrSize;
  v9->mMemStructure[0].mPointer = (void **)&mCurrSize;
  v9->mCurrSize = (v9->mCurrSize + 143) & 0xFFFFFFFFFFFFFFF0ui64;
  if ( num_params )
  {
    v10 = num_params;
    do
    {
      mNumMemStructures = v9->mNumMemStructures;
      v12 = (char *)v9 + 48 * mNumMemStructures;
      v9->mNumMemStructures = mNumMemStructures + 1;
      *((_QWORD *)v12 + 2) = "MaterialParam";
      *((_QWORD *)v12 + 3) = v9->mCurrSize;
      *((_DWORD *)v12 + 8) = 56;
      *((_QWORD *)v12 + 5) = 0i64;
      *((_QWORD *)v12 + 7) = 0i64;
      *((_QWORD *)v12 + 6) = 0i64;
      v9->mCurrSize += 56i64;
      --v10;
    }
    while ( v10 );
  }
  v9->mCurrSize = (v9->mCurrSize + 15) & 0xFFFFFFFFFFFFFFF0ui64;
  v13 = mCurrSize;
  v14 = v9->mNumMemStructures;
  v15 = (char *)v9 + 48 * v14;
  v9->mNumMemStructures = v14 + 1;
  *((_QWORD *)v15 + 2) = "MaterialUser";
  *((_QWORD *)v15 + 3) = v9->mCurrSize;
  *((_DWORD *)v15 + 8) = 16;
  *((_QWORD *)v15 + 5) = 0i64;
  *((_QWORD *)v15 + 7) = 0i64;
  *((_QWORD *)v15 + 6) = 0i64;
  v18[0] = (Illusion::MaterialUser *)v9->mCurrSize;
  *((_QWORD *)v15 + 5) = v18;
  p_mMaterialUser = &v13->mMaterialUser;
  if ( p_mMaterialUser )
  {
    *((_QWORD *)v15 + 7) = p_mMaterialUser;
    *((_QWORD *)v15 + 6) = v9->mCurrSize - (_QWORD)p_mMaterialUser;
  }
  v9->mCurrSize += 16i64;
  Illusion::MemImageSchema::Allocate(v9, memory_pool, allocation_params);
  v19 = mCurrSize;
  if ( mCurrSize )
    Illusion::Material::Material(mCurrSize, name, name_uid, num_params);
  v19 = (Illusion::Material *)v18[0];
  if ( v18[0] )
    Illusion::MaterialUser::MaterialUser(v18[0]);
  return mCurrSize;
}

// File Line: 148
// RVA: 0x92EA0
Illusion::MaterialTable *__fastcall Illusion::Factory::NewMaterialTable(
        const char *name,
        unsigned int name_uid,
        __int64 num_materials,
        Illusion::MemImageSchema *schema,
        UFG::qMemoryPool *memory_pool,
        unsigned __int64 allocation_params)
{
  int v6; // esi
  Illusion::MemImageSchema *v9; // r10
  unsigned int v10; // ebx
  __int64 mNumMemStructures; // rcx
  char *v12; // rdx
  UFG::qResourceData *v13; // r8
  __int64 v14; // rcx
  char *v15; // rdx
  UFG::qBaseNodeRB **mChild; // r8
  UFG::qResourceData *v17; // rdi
  UFG::qResourceHandle *v18; // rcx
  __int64 v20[9]; // [rsp+20h] [rbp-48h] BYREF
  UFG::qResourceData *mCurrSize; // [rsp+88h] [rbp+20h] BYREF

  v20[1] = -2i64;
  v6 = num_materials;
  v9 = &Illusion::gMemImageSchema;
  if ( schema )
    v9 = schema;
  v10 = 0;
  v9->mCurrSize = 0i64;
  v9->mCurrSerializeIndex = 0;
  v9->mBaseFilePosition = 0i64;
  v9->mNumMemStructures = 1;
  v9->mMemStructure[0].mName = "MaterialTable";
  v9->mMemStructure[0].mBaseOffset = v9->mCurrSize;
  v9->mMemStructure[0].mSize = 104;
  v9->mMemStructure[0].mPointer = 0i64;
  v9->mMemStructure[0].mFixupOffsetPointer = 0i64;
  v9->mMemStructure[0].mFixupOffset = 0i64;
  mCurrSize = (UFG::qResourceData *)v9->mCurrSize;
  v9->mMemStructure[0].mPointer = (void **)&mCurrSize;
  v9->mCurrSize += 104i64;
  if ( (_DWORD)num_materials )
  {
    num_materials = (unsigned int)num_materials;
    do
    {
      mNumMemStructures = v9->mNumMemStructures;
      v12 = (char *)v9 + 48 * mNumMemStructures;
      v9->mNumMemStructures = mNumMemStructures + 1;
      *((_QWORD *)v12 + 2) = "MaterialHandle";
      *((_QWORD *)v12 + 3) = v9->mCurrSize;
      *((_DWORD *)v12 + 8) = 32;
      *((_QWORD *)v12 + 5) = 0i64;
      *((_QWORD *)v12 + 7) = 0i64;
      *((_QWORD *)v12 + 6) = 0i64;
      v9->mCurrSize += 32i64;
      --num_materials;
    }
    while ( num_materials );
  }
  v13 = mCurrSize;
  v14 = v9->mNumMemStructures;
  v15 = (char *)v9 + 48 * v14;
  v9->mNumMemStructures = v14 + 1;
  *((_QWORD *)v15 + 2) = "MaterialTableUser";
  *((_QWORD *)v15 + 3) = v9->mCurrSize;
  *((_DWORD *)v15 + 8) = 16;
  *((_QWORD *)v15 + 5) = 0i64;
  *((_QWORD *)v15 + 7) = 0i64;
  *((_QWORD *)v15 + 6) = 0i64;
  v20[0] = v9->mCurrSize;
  *((_QWORD *)v15 + 5) = v20;
  mChild = v13[1].mNode.mChild;
  if ( mChild )
  {
    *((_QWORD *)v15 + 7) = mChild;
    *((_QWORD *)v15 + 6) = v9->mCurrSize - (_QWORD)mChild;
  }
  v9->mCurrSize += 16i64;
  Illusion::MemImageSchema::Allocate(v9, memory_pool, allocation_params);
  v17 = mCurrSize;
  v20[2] = (__int64)mCurrSize;
  if ( mCurrSize )
  {
    UFG::qResourceData::qResourceData(mCurrSize, 0x80D1F139, name_uid, name);
    if ( LODWORD(v17[1].mNode.mParent) )
    {
      do
      {
        v18 = (UFG::qResourceHandle *)&v17[1].mNode.mChild[4 * v10 + 1];
        v20[3] = (__int64)v18;
        v20[4] = (__int64)v18;
        if ( v18 )
          UFG::qResourceHandle::qResourceHandle(v18);
        ++v10;
      }
      while ( v10 < LODWORD(v17[1].mNode.mParent) );
    }
    LODWORD(v17[1].mNode.mParent) = v6;
  }
  return (Illusion::MaterialTable *)mCurrSize;
}

// File Line: 547
// RVA: 0x1457D40
__int64 Illusion::_dynamic_initializer_for__gDeleteQueueBuffer__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&gDeleteQueueBuffer.mWaitQueue.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB((UFG::qBaseTreeRB *)&stru_1421674E8);
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gDeleteQueueBuffer__);
}

// File Line: 548
// RVA: 0x1457D90
__int64 Illusion::_dynamic_initializer_for__gDeleteQueueModel__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&gDeleteQueueModel.mWaitQueue.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB((UFG::qBaseTreeRB *)&stru_1421677B8);
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gDeleteQueueModel__);
}

// File Line: 549
// RVA: 0x1457E10
__int64 Illusion::_dynamic_initializer_for__gDeleteQueueTexture__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&gDeleteQueueTexture.mWaitQueue.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB((UFG::qBaseTreeRB *)&stru_142167AC8);
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gDeleteQueueTexture__);
}

// File Line: 550
// RVA: 0x1457DE0
__int64 Illusion::_dynamic_initializer_for__gDeleteQueueMutex__()
{
  UFG::qMutex::qMutex(&Illusion::gDeleteQueueMutex, &customCaption);
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gDeleteQueueMutex__);
}

// File Line: 554
// RVA: 0x94740
void __fastcall Illusion::Factory::QueueDelete(Illusion::Texture *resource)
{
  unsigned int mUID; // edx
  UFG::qBaseNodeRB *v3; // rdx
  unsigned int v4; // eax

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&Illusion::gDeleteQueueMutex);
  if ( resource )
  {
    mUID = resource->mNode.mUID;
    if ( !mUID || !UFG::qBaseTreeRB::Get(&gDeleteQueueTexture.mWaitQueue.mTree, mUID) )
    {
      v3 = (UFG::qBaseNodeRB *)UFG::qMalloc(0x28ui64, "DeleteQueueNode", 0i64);
      if ( v3 )
      {
        v4 = resource->mNode.mUID;
        v3->mParent = 0i64;
        v3->mChild[0] = 0i64;
        v3->mChild[1] = 0i64;
        v3->mUID = v4;
        v3[1].mParent = (UFG::qBaseNodeRB *)resource;
      }
      else
      {
        v3 = 0i64;
      }
      UFG::qBaseTreeRB::Add(&gDeleteQueueTexture.mWaitQueue.mTree, v3);
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&Illusion::gDeleteQueueMutex);
}

// File Line: 557
// RVA: 0x945E0
void Illusion::Factory::ProcessWaitDeleteQueueAll(void)
{
  UFG::qBaseNodeRB *Head; // rbx
  UFG::qBaseTreeRB *Next; // rdi
  UFG::qBaseNodeRB *p_mRoot; // rbx
  UFG::qBaseTreeRB *v3; // rdi
  UFG::qBaseNodeRB *v4; // rbx
  UFG::qBaseTreeRB *v5; // rdi

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&Illusion::gDeleteQueueMutex);
  Head = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&gDeleteQueueBuffer);
  if ( Head )
  {
    do
    {
      Next = UFG::qBaseTreeRB::GetNext(&gDeleteQueueBuffer.mWaitQueue.mTree, Head);
      if ( Head[1].mParent[3].mUID <= Illusion::gEngine.mSafeToDeleteFrameCount )
      {
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&gDeleteQueueBuffer,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)Head);
        UFG::qBaseTreeRB::Add((UFG::qBaseTreeRB *)&stru_1421674E8, Head);
      }
      Head = &Next->mRoot;
    }
    while ( Next );
  }
  p_mRoot = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&gDeleteQueueModel);
  if ( p_mRoot )
  {
    do
    {
      v3 = UFG::qBaseTreeRB::GetNext(&gDeleteQueueModel.mWaitQueue.mTree, p_mRoot);
      if ( HIDWORD(p_mRoot[1].mParent[6].mChild[1]) <= Illusion::gEngine.mSafeToDeleteFrameCount )
      {
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&gDeleteQueueModel,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)p_mRoot);
        UFG::qBaseTreeRB::Add((UFG::qBaseTreeRB *)&stru_1421677B8, p_mRoot);
      }
      p_mRoot = &v3->mRoot;
    }
    while ( v3 );
  }
  v4 = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&gDeleteQueueTexture);
  if ( v4 )
  {
    do
    {
      v5 = UFG::qBaseTreeRB::GetNext(&gDeleteQueueTexture.mWaitQueue.mTree, v4);
      if ( *(&v4[1].mParent[3].mUID + 1) <= Illusion::gEngine.mSafeToDeleteFrameCount )
      {
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&gDeleteQueueTexture,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)v4);
        UFG::qBaseTreeRB::Add((UFG::qBaseTreeRB *)&stru_142167AC8, v4);
      }
      v4 = &v5->mRoot;
    }
    while ( v5 );
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&Illusion::gDeleteQueueMutex);
}

// File Line: 568
// RVA: 0x8E810
void Illusion::Factory::ClearFinalDeleteQueueAll(void)
{
  Render::SkinningCacheNode *Head; // rdi
  Illusion::Buffer *mCachedBufferPtr; // rbx
  UFG::qResourceWarehouse *v2; // rax
  Render::SkinningCacheNode *v3; // rdi
  Illusion::Model *v4; // rbx
  UFG::qResourceWarehouse *v5; // rax
  Render::SkinningCacheNode *v6; // rdi
  Illusion::Texture *v7; // rbx
  UFG::qResourceWarehouse *v8; // rax

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&Illusion::gDeleteQueueMutex);
  while ( stru_1421674E8.mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1421674E8);
    mCachedBufferPtr = Head->mCachedBufferPtr;
    v2 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v2, &mCachedBufferPtr->UFG::qResourceData);
    Illusion::Factory::Delete(mCachedBufferPtr, 0);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&stru_1421674E8.mTree, &Head->mNode);
    operator delete[](Head);
  }
  while ( stru_1421677B8.mTree.mCount )
  {
    v3 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1421677B8);
    v4 = (Illusion::Model *)v3->mCachedBufferPtr;
    v5 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v5, &v4->UFG::qResourceData);
    Illusion::Factory::Delete(v4, 0);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&stru_1421677B8.mTree, &v3->mNode);
    operator delete[](v3);
  }
  while ( stru_142167AC8.mTree.mCount )
  {
    v6 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_142167AC8);
    v7 = (Illusion::Texture *)v6->mCachedBufferPtr;
    v8 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v8, &v7->UFG::qResourceData);
    Illusion::Factory::Delete(v7, 0);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&stru_142167AC8.mTree, &v6->mNode);
    operator delete[](v6);
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&Illusion::gDeleteQueueMutex);
}


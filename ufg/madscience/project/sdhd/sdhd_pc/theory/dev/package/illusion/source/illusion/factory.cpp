// File Line: 35
// RVA: 0x930B0
Illusion::MemImageSchema *__fastcall Illusion::Factory::NewStateBlock(const char *name, unsigned int name_uid, unsigned int num_values, unsigned int byte_size, Illusion::MemImageSchema *schema, UFG::qMemoryPool *memory_pool, unsigned __int64 allocation_params)
{
  unsigned int v7; // esi
  unsigned int v8; // ebp
  unsigned int v9; // er14
  const char *v10; // rdi
  Illusion::MemImageSchema *v11; // r10
  unsigned int v12; // er9
  signed int v13; // er8
  __int64 v14; // rcx
  signed __int64 v15; // rdx
  signed int v16; // er8
  __int64 v17; // rcx
  signed __int64 v18; // rdx
  Illusion::StateBlock *v19; // rbx
  UFG::qNode<Illusion::StateBlock,Illusion::StateBlock> *v20; // rax
  unsigned __int64 v22; // [rsp+20h] [rbp-28h]
  __int64 v23; // [rsp+28h] [rbp-20h]
  Illusion::MemImageSchema *v24; // [rsp+30h] [rbp-18h]

  v23 = -2i64;
  v7 = byte_size;
  v8 = num_values;
  v9 = name_uid;
  v10 = name;
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
  v13 = (v7 + 15) & 0xFFFFFFF0;
  v14 = v11->mNumMemStructures;
  v15 = (signed __int64)v11 + 48 * v14;
  v11->mNumMemStructures = v14 + 1;
  *(_QWORD *)(v15 + 16) = "StateBlockData";
  *(_QWORD *)(v15 + 24) = v11->mCurrSize;
  *(_DWORD *)(v15 + 32) = v13;
  *(_QWORD *)(v15 + 56) = 0i64;
  *(_QWORD *)(v15 + 48) = 0i64;
  *(_QWORD *)(v15 + 40) = &v22;
  v11->mCurrSize = (v13 + v11->mCurrSize + 15) & 0xFFFFFFFFFFFFFFF0ui64;
  v16 = (v12 + 0xF) & 0xFFFFFFF0;
  v17 = v11->mNumMemStructures;
  v18 = (signed __int64)v11 + 48 * v17;
  v11->mNumMemStructures = v17 + 1;
  *(_QWORD *)(v18 + 16) = "StateBlockHeaders";
  *(_QWORD *)(v18 + 24) = v11->mCurrSize;
  *(_DWORD *)(v18 + 32) = v16;
  *(_QWORD *)(v18 + 40) = 0i64;
  *(_QWORD *)(v18 + 56) = 0i64;
  *(_QWORD *)(v18 + 48) = 0i64;
  v22 = v11->mCurrSize;
  *(_QWORD *)(v18 + 40) = &v22;
  v11->mCurrSize += v16;
  Illusion::MemImageSchema::Allocate(v11, memory_pool, allocation_params);
  v19 = (Illusion::StateBlock *)schema;
  v24 = schema;
  if ( schema )
  {
    UFG::qResourceData::qResourceData((UFG::qResourceData *)schema, 0x4D04C7F2u, v9, v10);
    v20 = (UFG::qNode<Illusion::StateBlock,Illusion::StateBlock> *)&v19->mPrev;
    v20->mPrev = v20;
    v20->mNext = v20;
    v19->mNameUID = UFG::qStringHashUpper32(v10, 0xFFFFFFFF);
    v19->mNumValues = v8;
    v19->mDataByteSize = v7;
  }
  return schema;
}

// File Line: 106
// RVA: 0x92CB0
Illusion::Material *__fastcall Illusion::Factory::NewMaterial(const char *name, unsigned int name_uid, unsigned int num_params, Illusion::MemImageSchema *schema, UFG::qMemoryPool *memory_pool, unsigned __int64 allocation_params)
{
  unsigned int v6; // ebx
  unsigned int v7; // edi
  const char *v8; // rsi
  Illusion::MemImageSchema *v9; // rcx
  __int64 v10; // r9
  __int64 v11; // rdx
  signed __int64 v12; // r8
  Illusion::Material *v13; // r9
  __int64 v14; // rdx
  signed __int64 v15; // r8
  signed __int64 v16; // r9
  Illusion::MaterialUser *v18; // [rsp+20h] [rbp-28h]
  __int64 v19; // [rsp+28h] [rbp-20h]
  void *v20; // [rsp+30h] [rbp-18h]
  Illusion::Material *v21; // [rsp+68h] [rbp+20h]

  v19 = -2i64;
  v6 = num_params;
  v7 = name_uid;
  v8 = name;
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
  v21 = (Illusion::Material *)v9->mCurrSize;
  v9->mMemStructure[0].mPointer = (void **)&v21;
  v9->mCurrSize = (v9->mCurrSize + 143) & 0xFFFFFFFFFFFFFFF0ui64;
  if ( num_params )
  {
    v10 = num_params;
    do
    {
      v11 = v9->mNumMemStructures;
      v12 = (signed __int64)v9 + 48 * v11;
      v9->mNumMemStructures = v11 + 1;
      *(_QWORD *)(v12 + 16) = "MaterialParam";
      *(_QWORD *)(v12 + 24) = v9->mCurrSize;
      *(_DWORD *)(v12 + 32) = 56;
      *(_QWORD *)(v12 + 40) = 0i64;
      *(_QWORD *)(v12 + 56) = 0i64;
      *(_QWORD *)(v12 + 48) = 0i64;
      v9->mCurrSize += 56i64;
      --v10;
    }
    while ( v10 );
  }
  v9->mCurrSize = (v9->mCurrSize + 15) & 0xFFFFFFFFFFFFFFF0ui64;
  v13 = v21;
  v14 = v9->mNumMemStructures;
  v15 = (signed __int64)v9 + 48 * v14;
  v9->mNumMemStructures = v14 + 1;
  *(_QWORD *)(v15 + 16) = "MaterialUser";
  *(_QWORD *)(v15 + 24) = v9->mCurrSize;
  *(_DWORD *)(v15 + 32) = 16;
  *(_QWORD *)(v15 + 40) = 0i64;
  *(_QWORD *)(v15 + 56) = 0i64;
  *(_QWORD *)(v15 + 48) = 0i64;
  v18 = (Illusion::MaterialUser *)v9->mCurrSize;
  *(_QWORD *)(v15 + 40) = &v18;
  v16 = (signed __int64)&v13->mMaterialUser;
  if ( v16 )
  {
    *(_QWORD *)(v15 + 56) = v16;
    *(_QWORD *)(v15 + 48) = v9->mCurrSize - v16;
  }
  v9->mCurrSize += 16i64;
  Illusion::MemImageSchema::Allocate(v9, memory_pool, allocation_params);
  v20 = v21;
  if ( v21 )
    Illusion::Material::Material(v21, v8, v7, v6);
  v20 = v18;
  if ( v18 )
    Illusion::MaterialUser::MaterialUser(v18);
  return v21;
}

// File Line: 148
// RVA: 0x92EA0
UFG::qResourceData *__fastcall Illusion::Factory::NewMaterialTable(const char *name, unsigned int name_uid, __int64 num_materials, Illusion::MemImageSchema *schema, UFG::qMemoryPool *memory_pool, unsigned __int64 allocation_params)
{
  int v6; // esi
  unsigned int v7; // ebp
  const char *v8; // r14
  Illusion::MemImageSchema *v9; // r10
  unsigned int v10; // ebx
  __int64 v11; // rcx
  signed __int64 v12; // rdx
  UFG::qResourceData *v13; // r8
  __int64 v14; // rcx
  signed __int64 v15; // rdx
  signed __int64 v16; // r8
  UFG::qResourceData *v17; // rdi
  signed __int64 v18; // rax
  unsigned __int64 v20; // [rsp+20h] [rbp-48h]
  __int64 v21; // [rsp+28h] [rbp-40h]
  UFG::qResourceData *v22; // [rsp+30h] [rbp-38h]
  UFG::qBaseNodeRB **v23; // [rsp+38h] [rbp-30h]
  UFG::qBaseNodeRB **v24; // [rsp+40h] [rbp-28h]
  UFG::qResourceData *v25; // [rsp+88h] [rbp+20h]

  v21 = -2i64;
  v6 = num_materials;
  v7 = name_uid;
  v8 = name;
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
  v25 = (UFG::qResourceData *)v9->mCurrSize;
  v9->mMemStructure[0].mPointer = (void **)&v25;
  v9->mCurrSize += 104i64;
  if ( (_DWORD)num_materials )
  {
    num_materials = (unsigned int)num_materials;
    do
    {
      v11 = v9->mNumMemStructures;
      v12 = (signed __int64)v9 + 48 * v11;
      v9->mNumMemStructures = v11 + 1;
      *(_QWORD *)(v12 + 16) = "MaterialHandle";
      *(_QWORD *)(v12 + 24) = v9->mCurrSize;
      *(_DWORD *)(v12 + 32) = 32;
      *(_QWORD *)(v12 + 40) = 0i64;
      *(_QWORD *)(v12 + 56) = 0i64;
      *(_QWORD *)(v12 + 48) = 0i64;
      v9->mCurrSize += 32i64;
      --num_materials;
    }
    while ( num_materials );
  }
  v13 = v25;
  v14 = v9->mNumMemStructures;
  v15 = (signed __int64)v9 + 48 * v14;
  v9->mNumMemStructures = v14 + 1;
  *(_QWORD *)(v15 + 16) = "MaterialTableUser";
  *(_QWORD *)(v15 + 24) = v9->mCurrSize;
  *(_DWORD *)(v15 + 32) = 16;
  *(_QWORD *)(v15 + 40) = 0i64;
  *(_QWORD *)(v15 + 56) = 0i64;
  *(_QWORD *)(v15 + 48) = 0i64;
  v20 = v9->mCurrSize;
  *(_QWORD *)(v15 + 40) = &v20;
  v16 = (signed __int64)v13[1].mNode.mChild;
  if ( v16 )
  {
    *(_QWORD *)(v15 + 56) = v16;
    *(_QWORD *)(v15 + 48) = v9->mCurrSize - v16;
  }
  v9->mCurrSize += 16i64;
  Illusion::MemImageSchema::Allocate(v9, memory_pool, allocation_params);
  v17 = v25;
  v22 = v25;
  if ( v25 )
  {
    UFG::qResourceData::qResourceData(v25, 0x80D1F139, v7, v8);
    if ( LODWORD(v17[1].mNode.mParent) )
    {
      do
      {
        v18 = 4i64 * v10;
        v23 = &v17[1].mNode.mChild[v18 + 1];
        v24 = &v17[1].mNode.mChild[v18 + 1];
        if ( &v17[1].mNode.mChild[v18 + 1] )
          UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v17[1].mNode.mChild[v18 + 1]);
        ++v10;
      }
      while ( v10 < LODWORD(v17[1].mNode.mParent) );
    }
    LODWORD(v17[1].mNode.mParent) = v6;
  }
  return v25;
}

// File Line: 547
// RVA: 0x1457D40
__int64 Illusion::_dynamic_initializer_for__gDeleteQueueBuffer__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&gDeleteQueueBuffer.mWaitQueue.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB((UFG::qBaseTreeRB *)&stru_1421674E8);
  return atexit(Illusion::_dynamic_atexit_destructor_for__gDeleteQueueBuffer__);
}

// File Line: 548
// RVA: 0x1457D90
__int64 Illusion::_dynamic_initializer_for__gDeleteQueueModel__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&gDeleteQueueModel.mWaitQueue.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB((UFG::qBaseTreeRB *)&stru_1421677B8);
  return atexit(Illusion::_dynamic_atexit_destructor_for__gDeleteQueueModel__);
}

// File Line: 549
// RVA: 0x1457E10
__int64 Illusion::_dynamic_initializer_for__gDeleteQueueTexture__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&gDeleteQueueTexture.mWaitQueue.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB((UFG::qBaseTreeRB *)&stru_142167AC8);
  return atexit(Illusion::_dynamic_atexit_destructor_for__gDeleteQueueTexture__);
}

// File Line: 550
// RVA: 0x1457DE0
__int64 Illusion::_dynamic_initializer_for__gDeleteQueueMutex__()
{
  UFG::qMutex::qMutex(&Illusion::gDeleteQueueMutex, &customWorldMapCaption);
  return atexit(Illusion::_dynamic_atexit_destructor_for__gDeleteQueueMutex__);
}

// File Line: 554
// RVA: 0x94740
void __fastcall Illusion::Factory::QueueDelete(Illusion::Texture *resource)
{
  Illusion::Texture *v1; // rbx
  unsigned int v2; // edx
  UFG::qBaseNodeRB *v3; // rdx
  unsigned int v4; // eax

  v1 = resource;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&Illusion::gDeleteQueueMutex);
  if ( v1 )
  {
    v2 = v1->mNode.mUID;
    if ( !v2 || !UFG::qBaseTreeRB::Get(&gDeleteQueueTexture.mWaitQueue.mTree, v2) )
    {
      v3 = (UFG::qBaseNodeRB *)UFG::qMalloc(0x28ui64, "DeleteQueueNode", 0i64);
      if ( v3 )
      {
        v4 = v1->mNode.mUID;
        v3->mParent = 0i64;
        v3->mChild[0] = 0i64;
        v3->mChild[1] = 0i64;
        v3->mUID = v4;
        v3[1].mParent = (UFG::qBaseNodeRB *)v1;
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
  UFG::qBaseNodeRB *v0; // rbx
  UFG::qBaseTreeRB *v1; // rdi
  UFG::qBaseNodeRB *v2; // rbx
  UFG::qBaseTreeRB *v3; // rdi
  UFG::qBaseNodeRB *v4; // rbx
  UFG::qBaseTreeRB *v5; // rdi

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&Illusion::gDeleteQueueMutex);
  v0 = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&gDeleteQueueBuffer);
  if ( v0 )
  {
    do
    {
      v1 = UFG::qBaseTreeRB::GetNext(&gDeleteQueueBuffer.mWaitQueue.mTree, v0);
      if ( v0[1].mParent[3].mUID <= Illusion::gEngine.mSafeToDeleteFrameCount )
      {
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&gDeleteQueueBuffer,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)v0);
        UFG::qBaseTreeRB::Add((UFG::qBaseTreeRB *)&stru_1421674E8, v0);
      }
      v0 = &v1->mRoot;
    }
    while ( v1 );
  }
  v2 = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&gDeleteQueueModel);
  if ( v2 )
  {
    do
    {
      v3 = UFG::qBaseTreeRB::GetNext(&gDeleteQueueModel.mWaitQueue.mTree, v2);
      if ( HIDWORD(v2[1].mParent[6].mChild[1]) <= Illusion::gEngine.mSafeToDeleteFrameCount )
      {
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&gDeleteQueueModel,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)v2);
        UFG::qBaseTreeRB::Add((UFG::qBaseTreeRB *)&stru_1421677B8, v2);
      }
      v2 = &v3->mRoot;
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
  Render::SkinningCacheNode *v0; // rdi
  Illusion::Buffer *v1; // rbx
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
    v0 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1421674E8);
    v1 = v0->mCachedBufferPtr;
    v2 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v2, (UFG::qResourceData *)&v1->mNode);
    Illusion::Factory::Delete(v1, 0);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&stru_1421674E8.mTree, &v0->mNode);
    operator delete[](v0);
  }
  while ( stru_1421677B8.mTree.mCount )
  {
    v3 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1421677B8);
    v4 = (Illusion::Model *)v3->mCachedBufferPtr;
    v5 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v5, (UFG::qResourceData *)&v4->mNode);
    Illusion::Factory::Delete(v4, 0);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&stru_1421677B8.mTree, &v3->mNode);
    operator delete[](v3);
  }
  while ( stru_142167AC8.mTree.mCount )
  {
    v6 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_142167AC8);
    v7 = (Illusion::Texture *)v6->mCachedBufferPtr;
    v8 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v8, (UFG::qResourceData *)&v7->mNode);
    Illusion::Factory::Delete(v7, 0);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&stru_142167AC8.mTree, &v6->mNode);
    operator delete[](v6);
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&Illusion::gDeleteQueueMutex);
}


// File Line: 18
// RVA: 0x455FA0
void __fastcall UFG::AddTerrainDataPhysicsCallback(
        Render::TerrainData *pData,
        Render::TerrainDefinition *terrainParams,
        UFG::TerrainQuadTreeNode *terrainNode)
{
  UFG::TerrainCollisionManager *v6; // rcx
  UFG::allocator::free_link *v7; // rax

  v6 = UFG::TerrainCollisionManager::mInstance;
  if ( !UFG::TerrainCollisionManager::mInstance )
  {
    v7 = UFG::qMalloc(0x50ui64, "TerrainCollisionManager", 0i64);
    if ( v7 )
      UFG::TerrainCollisionManager::TerrainCollisionManager((UFG::TerrainCollisionManager *)v7);
    UFG::TerrainCollisionManager::mInstance = (UFG::TerrainCollisionManager *)v7;
    UFG::TerrainCollisionManager::GetInstance();
    v6 = UFG::TerrainCollisionManager::mInstance;
  }
  UFG::TerrainCollisionManager::AddTerrainData(v6, pData, terrainParams, terrainNode);
}

// File Line: 24
// RVA: 0x4732F0
void __fastcall UFG::RemoveTerrainDataPhysicsCallback(Render::TerrainData *pData)
{
  UFG::TerrainCollisionManager *v2; // rcx

  v2 = UFG::TerrainCollisionManager::mInstance;
  if ( !UFG::TerrainCollisionManager::mInstance )
  {
    UFG::TerrainCollisionManager::Initialize();
    v2 = UFG::TerrainCollisionManager::mInstance;
  }
  UFG::TerrainCollisionManager::RemoveTerrainData(v2, pData);
}

// File Line: 31
// RVA: 0x469850
void UFG::TerrainCollisionManager::Initialize(void)
{
  UFG::allocator::free_link *v0; // rax

  if ( !UFG::TerrainCollisionManager::mInstance )
  {
    do
    {
      v0 = UFG::qMalloc(0x50ui64, "TerrainCollisionManager", 0i64);
      if ( v0 )
        UFG::TerrainCollisionManager::TerrainCollisionManager((UFG::TerrainCollisionManager *)v0);
      UFG::TerrainCollisionManager::mInstance = (UFG::TerrainCollisionManager *)v0;
    }
    while ( !v0 );
  }
}

// File Line: 40
// RVA: 0x466930
UFG::TerrainCollisionManager *__fastcall UFG::TerrainCollisionManager::GetInstance()
{
  UFG::TerrainCollisionManager *result; // rax
  UFG::allocator::free_link *v1; // rax

  result = UFG::TerrainCollisionManager::mInstance;
  if ( !UFG::TerrainCollisionManager::mInstance )
  {
    v1 = UFG::qMalloc(
           (unsigned int)((_DWORD)UFG::TerrainCollisionManager::mInstance + 80),
           "TerrainCollisionManager",
           0i64);
    if ( v1 )
      UFG::TerrainCollisionManager::TerrainCollisionManager((UFG::TerrainCollisionManager *)v1);
    UFG::TerrainCollisionManager::mInstance = (UFG::TerrainCollisionManager *)v1;
    UFG::TerrainCollisionManager::GetInstance();
    return UFG::TerrainCollisionManager::mInstance;
  }
  return result;
}

// File Line: 49
// RVA: 0x44E090
void __fastcall UFG::TerrainCollisionManager::TerrainCollisionManager(UFG::TerrainCollisionManager *this)
{
  this->vfptr = (UFG::TerrainCollisionManagerVtbl *)&UFG::TerrainCollisionManager::`vftable;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mTerrainObjectMap.mTree.mTree);
  UFG::RenderWorld::msStageTerrain->mAddTerrainDataPhysicsCallback = UFG::AddTerrainDataPhysicsCallback;
  UFG::RenderWorld::msStageTerrain->mRemoveTerrainDataPhysicsCallback = UFG::RemoveTerrainDataPhysicsCallback;
}

// File Line: 54
// RVA: 0x451790
void __fastcall UFG::TerrainCollisionManager::~TerrainCollisionManager(UFG::TerrainCollisionManager *this)
{
  Render::Skinning *p_mTerrainObjectMap; // rdi
  Render::SkinningCacheNode *Head; // rbx

  this->vfptr = (UFG::TerrainCollisionManagerVtbl *)&UFG::TerrainCollisionManager::`vftable;
  p_mTerrainObjectMap = (Render::Skinning *)&this->mTerrainObjectMap;
  if ( this->mTerrainObjectMap.mTree.mTree.mCount )
  {
    do
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&p_mTerrainObjectMap->mSkinnedVertexBuffers);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        &p_mTerrainObjectMap->mSkinnedVertexBuffers.mTree,
        &Head->mNode);
      operator delete[](Head);
    }
    while ( p_mTerrainObjectMap->mSkinnedVertexBuffers.mTree.mCount );
  }
  UFG::qBaseTreeRB::~qBaseTreeRB(p_mTerrainObjectMap);
}

// File Line: 60
// RVA: 0x475EF0
void __fastcall UFG::TerrainCollisionManager::Shutdown(UFG::TerrainCollisionManager *this)
{
  Render::SkinningCacheNode *Head; // rbx
  UFG::SimObject *mCachedBufferPtr; // rdx

  while ( this->mTerrainObjectMap.mTree.mTree.mCount > 0 )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mTerrainObjectMap);
    mCachedBufferPtr = (UFG::SimObject *)Head->mCachedBufferPtr;
    if ( mCachedBufferPtr )
      UFG::Simulation::DestroySimObject(&UFG::gSim, mCachedBufferPtr);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mTerrainObjectMap,
      &Head->mNode);
  }
}

// File Line: 75
// RVA: 0x455D70
void __fastcall UFG::TerrainCollisionManager::AddTerrainData(
        UFG::TerrainCollisionManager *this,
        Render::TerrainData *pTerrainData,
        Render::TerrainDefinition *terrainParams,
        UFG::TerrainQuadTreeNode *terrainNode)
{
  UFG::qSymbol *v8; // rax
  UFG::SimObject *v9; // rsi
  float v10; // xmm6_4
  float quant_scale; // xmm7_4
  float z; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  UFG::allocator::free_link *v15; // rax
  __int64 mOffset; // rcx
  unsigned __int16 *v17; // rdx
  UFG::SimComponent *v18; // rax
  UFG::SimComponent *v19; // rbx
  unsigned int mUID; // ebp
  UFG::qBaseTreeRB *v21; // rax
  UFG::allocator::free_link *v22; // rax
  UFG::qBaseNodeRB *v23; // rbx
  UFG::qVector3 pos; // [rsp+58h] [rbp-80h] BYREF
  UFG::qVector3 dimensions; // [rsp+68h] [rbp-70h] BYREF
  UFG::SimObjectModifier v26; // [rsp+78h] [rbp-60h] BYREF
  UFG::allocator::free_link *v27; // [rsp+E0h] [rbp+8h] BYREF
  UFG::qSymbol result; // [rsp+E8h] [rbp+10h] BYREF

  v8 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&v27, "TerrainCollisionElement");
  UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, v8);
  v9 = UFG::Simulation::CreateSimObject(&UFG::gSim, &result);
  v10 = (float)(terrainParams->mMapResolution >> 2);
  quant_scale = terrainParams->mDimensions.z * 0.000015259022;
  z = terrainNode->mAABBMin.z;
  pos.x = terrainNode->mAABBMin.x;
  pos.z = z;
  pos.y = terrainNode->mAABBMax.y;
  v13 = terrainNode->mAABBMax.z - z;
  v14 = pos.y - terrainNode->mAABBMin.y;
  dimensions.x = terrainNode->mAABBMax.x - pos.x;
  dimensions.y = v14;
  dimensions.z = v13;
  v15 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0xB8ui64, "TerrainCollisionComponent", 0i64, 1u);
  v27 = v15;
  if ( v15 )
  {
    mOffset = pTerrainData->mHeightField.mOffset;
    if ( mOffset )
      v17 = (unsigned __int16 *)((char *)&pTerrainData->mHeightField + mOffset);
    else
      v17 = 0i64;
    UFG::TerrainCollisionComponent::TerrainCollisionComponent(
      (UFG::TerrainCollisionComponent *)v15,
      v9->mNode.mUID,
      (int)v10,
      (int)v10,
      v17,
      0.0,
      quant_scale,
      &dimensions,
      &pos);
    v19 = v18;
  }
  else
  {
    v19 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v26, v9, 1);
  UFG::SimObjectModifier::AttachComponent(&v26, v19, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v26);
  UFG::SimObjectModifier::~SimObjectModifier(&v26);
  mUID = pTerrainData->mUID;
  if ( mUID && (v21 = UFG::qBaseTreeRB::Get(&this->mTerrainObjectMap.mTree.mTree, mUID)) != 0i64 )
  {
    v21->mNULL.mParent = (UFG::qBaseNodeRB *)v9;
  }
  else
  {
    v22 = UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
    v23 = (UFG::qBaseNodeRB *)v22;
    v27 = v22;
    if ( v22 )
    {
      v22->mNext = 0i64;
      v22[1].mNext = 0i64;
      v22[2].mNext = 0i64;
      LODWORD(v22[3].mNext) = mUID;
      v22[4].mNext = (UFG::allocator::free_link *)v9;
    }
    else
    {
      v23 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&this->mTerrainObjectMap.mTree.mTree, v23);
    v23[1].mParent = (UFG::qBaseNodeRB *)v9;
  }
}

// File Line: 105
// RVA: 0x473260
void __fastcall UFG::TerrainCollisionManager::RemoveTerrainData(
        UFG::TerrainCollisionManager *this,
        Render::TerrainData *pTerrainData)
{
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v5; // rax
  UFG::SimObject **p_mNULL; // rax
  unsigned int v7; // edx
  UFG::qBaseTreeRB *v8; // rax
  UFG::qBaseTreeRB *v9; // rbx
  __int64 v10; // [rsp+38h] [rbp+10h] BYREF

  mUID = pTerrainData->mUID;
  v10 = 0i64;
  if ( mUID && (v5 = UFG::qBaseTreeRB::Get(&this->mTerrainObjectMap.mTree.mTree, mUID)) != 0i64 )
    p_mNULL = (UFG::SimObject **)&v5->mNULL;
  else
    p_mNULL = (UFG::SimObject **)&v10;
  if ( *p_mNULL )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, *p_mNULL);
    v7 = pTerrainData->mUID;
    if ( v7 )
    {
      v8 = UFG::qBaseTreeRB::Get(&this->mTerrainObjectMap.mTree.mTree, v7);
      v9 = v8;
      if ( v8 )
      {
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mTerrainObjectMap,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)v8);
        operator delete[](v9);
      }
    }
  }
}


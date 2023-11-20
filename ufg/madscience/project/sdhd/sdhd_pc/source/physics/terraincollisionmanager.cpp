// File Line: 18
// RVA: 0x455FA0
void __fastcall UFG::AddTerrainDataPhysicsCallback(Render::TerrainData *pData, Render::TerrainDefinition *terrainParams, UFG::TerrainQuadTreeNode *terrainNode)
{
  UFG::TerrainQuadTreeNode *v3; // rbx
  Render::TerrainDefinition *v4; // rdi
  Render::TerrainData *v5; // rsi
  UFG::TerrainCollisionManager *v6; // rcx
  UFG::allocator::free_link *v7; // rax

  v3 = terrainNode;
  v4 = terrainParams;
  v5 = pData;
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
  UFG::TerrainCollisionManager::AddTerrainData(v6, v5, v4, v3);
}

// File Line: 24
// RVA: 0x4732F0
void __fastcall UFG::RemoveTerrainDataPhysicsCallback(Render::TerrainData *pData)
{
  Render::TerrainData *v1; // rbx
  UFG::TerrainCollisionManager *v2; // rcx

  v1 = pData;
  v2 = UFG::TerrainCollisionManager::mInstance;
  if ( !UFG::TerrainCollisionManager::mInstance )
  {
    UFG::TerrainCollisionManager::Initialize();
    v2 = UFG::TerrainCollisionManager::mInstance;
  }
  UFG::TerrainCollisionManager::RemoveTerrainData(v2, v1);
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
    result = UFG::TerrainCollisionManager::mInstance;
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
  Render::Skinning *v1; // rdi
  Render::SkinningCacheNode *v2; // rbx

  this->vfptr = (UFG::TerrainCollisionManagerVtbl *)&UFG::TerrainCollisionManager::`vftable;
  v1 = (Render::Skinning *)&this->mTerrainObjectMap;
  if ( this->mTerrainObjectMap.mTree.mTree.mCount )
  {
    do
    {
      v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&v1->mSkinnedVertexBuffers);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v1->mSkinnedVertexBuffers.mTree, &v2->mNode);
      operator delete[](v2);
    }
    while ( v1->mSkinnedVertexBuffers.mTree.mCount );
  }
  UFG::qBaseTreeRB::~qBaseTreeRB(v1);
}

// File Line: 60
// RVA: 0x475EF0
void __fastcall UFG::TerrainCollisionManager::Shutdown(UFG::TerrainCollisionManager *this)
{
  UFG::TerrainCollisionManager *i; // rsi
  Render::SkinningCacheNode *v2; // rbx
  UFG::SimObject *v3; // rdx

  for ( i = this;
        i->mTerrainObjectMap.mTree.mTree.mCount > 0;
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&i->mTerrainObjectMap,
          &v2->mNode) )
  {
    v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&i->mTerrainObjectMap);
    v3 = (UFG::SimObject *)v2->mCachedBufferPtr;
    if ( v3 )
      UFG::Simulation::DestroySimObject(&UFG::gSim, v3);
  }
}

// File Line: 75
// RVA: 0x455D70
void __fastcall UFG::TerrainCollisionManager::AddTerrainData(UFG::TerrainCollisionManager *this, Render::TerrainData *pTerrainData, Render::TerrainDefinition *terrainParams, UFG::TerrainQuadTreeNode *terrainNode)
{
  UFG::TerrainQuadTreeNode *v4; // rdi
  Render::TerrainDefinition *v5; // rbx
  Render::TerrainData *v6; // rbp
  UFG::TerrainCollisionManager *v7; // r14
  UFG::qSymbol *v8; // rax
  UFG::SimObject *v9; // rsi
  float v10; // xmm6_4
  float quant_scale; // xmm7_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  UFG::allocator::free_link *v15; // rax
  __int64 v16; // rcx
  unsigned __int16 *v17; // rdx
  UFG::SimComponent *v18; // rax
  UFG::SimComponent *v19; // rbx
  unsigned int v20; // ebp
  UFG::qBaseTreeRB *v21; // rax
  UFG::allocator::free_link *v22; // rax
  UFG::qBaseNodeRB *v23; // rbx
  UFG::qVector3 pos; // [rsp+58h] [rbp-80h]
  UFG::qVector3 dimensions; // [rsp+68h] [rbp-70h]
  UFG::SimObjectModifier v26; // [rsp+78h] [rbp-60h]
  UFG::allocator::free_link *v27; // [rsp+E0h] [rbp+8h]
  UFG::qSymbol result; // [rsp+E8h] [rbp+10h]

  v4 = terrainNode;
  v5 = terrainParams;
  v6 = pTerrainData;
  v7 = this;
  v8 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&v27, "TerrainCollisionElement");
  UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, v8);
  v9 = UFG::Simulation::CreateSimObject(&UFG::gSim, &result);
  v10 = (float)(v5->mMapResolution >> 2);
  quant_scale = v5->mDimensions.z * 0.000015259022;
  v12 = v4->mAABBMin.z;
  pos.x = v4->mAABBMin.x;
  pos.z = v12;
  pos.y = v4->mAABBMax.y;
  v13 = v4->mAABBMax.z - v12;
  v14 = pos.y - v4->mAABBMin.y;
  dimensions.x = v4->mAABBMax.x - pos.x;
  dimensions.y = v14;
  dimensions.z = v13;
  v15 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0xB8ui64, "TerrainCollisionComponent", 0i64, 1u);
  v27 = v15;
  if ( v15 )
  {
    v16 = v6->mHeightField.mOffset;
    if ( v16 )
      v17 = (unsigned __int16 *)((char *)&v6->mHeightField + v16);
    else
      v17 = 0i64;
    UFG::TerrainCollisionComponent::TerrainCollisionComponent(
      (UFG::TerrainCollisionComponent *)v15,
      v9->mNode.mUID,
      (signed int)v10,
      (signed int)v10,
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
  v20 = v6->mUID;
  if ( v20 && (v21 = UFG::qBaseTreeRB::Get(&v7->mTerrainObjectMap.mTree.mTree, v20)) != 0i64 )
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
      LODWORD(v22[3].mNext) = v20;
      v22[4].mNext = (UFG::allocator::free_link *)v9;
    }
    else
    {
      v23 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&v7->mTerrainObjectMap.mTree.mTree, v23);
    v23[1].mParent = (UFG::qBaseNodeRB *)v9;
  }
}

// File Line: 105
// RVA: 0x473260
void __fastcall UFG::TerrainCollisionManager::RemoveTerrainData(UFG::TerrainCollisionManager *this, Render::TerrainData *pTerrainData)
{
  Render::TerrainData *v2; // rbx
  unsigned int v3; // edx
  UFG::TerrainCollisionManager *v4; // rdi
  UFG::qBaseTreeRB *v5; // rax
  UFG::SimObject **v6; // rax
  unsigned int v7; // edx
  UFG::qBaseTreeRB *v8; // rax
  UFG::qBaseTreeRB *v9; // rbx
  __int64 v10; // [rsp+38h] [rbp+10h]

  v2 = pTerrainData;
  v3 = pTerrainData->mUID;
  v4 = this;
  v10 = 0i64;
  if ( v3 && (v5 = UFG::qBaseTreeRB::Get(&this->mTerrainObjectMap.mTree.mTree, v3)) != 0i64 )
    v6 = (UFG::SimObject **)&v5->mNULL;
  else
    v6 = (UFG::SimObject **)&v10;
  if ( *v6 )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, *v6);
    v7 = v2->mUID;
    if ( v7 )
    {
      v8 = UFG::qBaseTreeRB::Get(&v4->mTerrainObjectMap.mTree.mTree, v7);
      v9 = v8;
      if ( v8 )
      {
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v4->mTerrainObjectMap,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)v8);
        operator delete[](v9);
      }
    }
  }
}


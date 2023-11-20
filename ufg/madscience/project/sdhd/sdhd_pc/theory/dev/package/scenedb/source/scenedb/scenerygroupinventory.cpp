// File Line: 20
// RVA: 0x1470330
__int64 UFG::_dynamic_initializer_for__gSceneryGroupInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gSceneryGroupInventory.vfptr,
    "SceneryGroupInventory",
    0xF0A07244,
    0x7480E00Bu,
    0,
    0);
  UFG::gSceneryGroupInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::SceneryGroupInventory::`vftable;
  return atexit(UFG::_dynamic_atexit_destructor_for__gSceneryGroupInventory__);
}

// File Line: 27
// RVA: 0x230020
void __fastcall UFG::SceneryGroupInventory::Add(UFG::SceneryGroupInventory *this, UFG::qResourceData *resource_data)
{
  UFG::SceneryGroup *v2; // rbp
  UFG::SceneryGroupInventory *v3; // r15
  UFG::qMemoryPool *v4; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::SceneryGroupComponent *v6; // rax
  __int64 v7; // rax
  signed __int64 v8; // rsi
  int v9; // er14
  unsigned int v10; // er10
  __int64 v11; // rax
  signed __int64 v12; // rcx
  unsigned __int64 v13; // rdx
  __int64 v14; // rax
  signed __int64 v15; // r8
  signed __int64 v16; // rcx
  signed int v17; // ebx
  UFG::qResourceHandle *v18; // rdi
  signed __int64 v19; // rax
  UFG::qResourceInventory *v20; // rax
  UFG::qResourceWarehouse *v21; // rax

  v2 = (UFG::SceneryGroup *)resource_data;
  v3 = this;
  if ( resource_data )
  {
    UFG::qResourceData::qResourceData(resource_data);
    v2->mRenderComponent = 0i64;
  }
  v4 = UFG::GetSimulationMemoryPool();
  v5 = UFG::qMemoryPool::Allocate(v4, 0x78ui64, "SceneryGroupComponent", 0i64, 1u);
  if ( v5 )
    UFG::SceneryGroupComponent::SceneryGroupComponent((UFG::SceneryGroupComponent *)v5, v2);
  else
    v6 = 0i64;
  v2->mRenderComponent = v6;
  v7 = v2->mObjects.mOffset;
  if ( v7 )
    v8 = (signed __int64)&v2->mObjects + v7;
  else
    v8 = 0i64;
  v9 = v2->mNumObjects;
  v10 = 0;
  if ( v2->mNumInstances > 0u )
  {
    do
    {
      v11 = v2->mCullInfo.mOffset;
      if ( v11 )
        v12 = (signed __int64)&v2->mCullInfo + v11;
      else
        v12 = 0i64;
      v13 = v12 + ((unsigned __int64)v10 << 6);
      v14 = v2->mInstances.mOffset;
      if ( v14 )
        v15 = (signed __int64)&v2->mInstances + v14;
      else
        v15 = 0i64;
      v16 = v15 + 96i64 * v10;
      *(_WORD *)(v13 + 30) = 0;
      *(_QWORD *)(v13 + 56) = v16 + 32;
      *(_QWORD *)(v13 + 40) = v16;
      *(_QWORD *)(v13 + 48) = v2;
      ++v10;
    }
    while ( v10 < v2->mNumInstances );
  }
  for ( ; v9; v8 += 144i64 )
  {
    --v9;
    v17 = 0;
    v18 = (UFG::qResourceHandle *)(v8 + 16);
    do
    {
      v19 = 32i64 * v17;
      if ( v19 + v8 + 16 )
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)(v19 + v8 + 16));
      v20 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
      {
        v21 = UFG::qResourceWarehouse::Instance();
        v20 = UFG::qResourceWarehouse::GetInventory(v21, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v20;
      }
      UFG::qResourceHandle::Init(v18, 0xA2ADCD77, v18->mNameUID, v20);
      ++v17;
      ++v18;
    }
    while ( v17 < 2 );
  }
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, (UFG::qResourceData *)&v2->mNode);
  if ( v2->mSectionVisIndex >= 0x400u )
    UFG::FarGroundLayout::OnFarGroundSceneryGroupLoad(v2);
}

// File Line: 96
// RVA: 0x234E10
void __fastcall UFG::SceneryGroupInventory::Remove(UFG::SceneryGroupInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // r14
  UFG::SceneryGroupInventory *v3; // rbx
  UFG::qBaseNodeRB *v4; // rax
  signed __int64 v5; // rbp
  int v6; // esi
  signed __int64 v7; // rbp
  UFG::qResourceHandle *v8; // rbx
  signed __int64 v9; // rdi
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax
  __int64 v12; // rcx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v13; // rdi
  UFG::qResourceHandle *v14; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v15; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v16; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v17; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v18; // rax

  v2 = resource_data;
  v3 = this;
  if ( *(_WORD *)&resource_data[1].mDebugName[30] >= 0x400u )
    UFG::FarGroundLayout::OnFarGroundSceneryGroupUnload((UFG::SceneryGroup *)resource_data);
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&v3->vfptr, v2);
  v4 = v2[1].mNode.mChild[0];
  if ( v4 )
    v5 = (signed __int64)v2[1].mNode.mChild + (_QWORD)v4;
  else
    v5 = 0i64;
  v6 = LOWORD(v2[1].mNode.mParent);
  if ( LOWORD(v2[1].mNode.mParent) )
  {
    v7 = v5 + 16;
    do
    {
      --v6;
      v8 = (UFG::qResourceHandle *)v7;
      v9 = 2i64;
      do
      {
        v10 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
        if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
        {
          v11 = UFG::qResourceWarehouse::Instance();
          v10 = UFG::qResourceWarehouse::GetInventory(v11, 0xA2ADCD77);
          `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v10;
        }
        UFG::qResourceHandle::Close(v8, v10);
        ++v8;
        --v9;
      }
      while ( v9 );
      v7 += 144i64;
    }
    while ( v6 );
  }
  v12 = *(_QWORD *)&v2[1].mTypeUID;
  if ( v12 )
    (**(void (__fastcall ***)(signed __int64, signed __int64))(v12 + 24))(v12 + 24, 1i64);
  *(_QWORD *)&v2[1].mTypeUID = 0i64;
  v13 = &v2->mResourceHandles;
  v14 = (UFG::qResourceHandle *)v2->mResourceHandles.mNode.mNext;
  if ( v14 != (UFG::qResourceHandle *)&v2->mResourceHandles )
  {
    do
    {
      v15 = v14->mPrev;
      v16 = v14->mNext;
      v15->mNext = v16;
      v16->mPrev = v15;
      v14->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v14->mPrev;
      v14->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v14->mPrev;
      UFG::qResourceHandle::~qResourceHandle(v14);
      operator delete[](v14);
      v14 = (UFG::qResourceHandle *)v2->mResourceHandles.mNode.mNext;
    }
    while ( v14 != (UFG::qResourceHandle *)v13 );
  }
  v17 = v13->mNode.mPrev;
  v18 = v2->mResourceHandles.mNode.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v13->mNode.mPrev = &v13->mNode;
  v2->mResourceHandles.mNode.mNext = &v2->mResourceHandles.mNode;
}


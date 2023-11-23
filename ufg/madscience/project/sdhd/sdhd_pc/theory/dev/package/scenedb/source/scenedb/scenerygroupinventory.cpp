// File Line: 20
// RVA: 0x1470330
__int64 UFG::_dynamic_initializer_for__gSceneryGroupInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gSceneryGroupInventory,
    "SceneryGroupInventory",
    0xF0A07244,
    0x7480E00Bu,
    0,
    0);
  UFG::gSceneryGroupInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::SceneryGroupInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSceneryGroupInventory__);
}

// File Line: 27
// RVA: 0x230020
void __fastcall UFG::SceneryGroupInventory::Add(UFG::SceneryGroupInventory *this, UFG::SceneryGroup *resource_data)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::SceneryGroupComponent *v6; // rax
  UFG::qBaseNodeRB *mOffset; // rax
  char *v8; // rsi
  int mNumObjects; // r14d
  unsigned int i; // r10d
  __int64 v11; // rax
  char *v12; // rcx
  char *v13; // rdx
  UFG::qBaseNodeRB *v14; // rax
  char *v15; // r8
  char *v16; // rcx
  int v17; // ebx
  UFG::qResourceHandle *v18; // rdi
  UFG::qResourceHandle *v19; // rcx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v21; // rax

  if ( resource_data )
  {
    UFG::qResourceData::qResourceData(resource_data);
    resource_data->mRenderComponent = 0i64;
  }
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v5 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x78ui64, "SceneryGroupComponent", 0i64, 1u);
  if ( v5 )
    UFG::SceneryGroupComponent::SceneryGroupComponent((UFG::SceneryGroupComponent *)v5, resource_data);
  else
    v6 = 0i64;
  resource_data->mRenderComponent = v6;
  mOffset = (UFG::qBaseNodeRB *)resource_data->mObjects.mOffset;
  if ( mOffset )
    v8 = (char *)&resource_data->mObjects + (_QWORD)mOffset;
  else
    v8 = 0i64;
  mNumObjects = resource_data->mNumObjects;
  for ( i = 0; i < resource_data->mNumInstances; ++i )
  {
    v11 = resource_data->mCullInfo.mOffset;
    if ( v11 )
      v12 = (char *)&resource_data->mCullInfo + v11;
    else
      v12 = 0i64;
    v13 = &v12[64 * (unsigned __int64)i];
    v14 = (UFG::qBaseNodeRB *)resource_data->mInstances.mOffset;
    if ( v14 )
      v15 = (char *)&resource_data->mInstances + (_QWORD)v14;
    else
      v15 = 0i64;
    v16 = &v15[96 * i];
    *((_WORD *)v13 + 15) = 0;
    *((_QWORD *)v13 + 7) = v16 + 32;
    *((_QWORD *)v13 + 5) = v16;
    *((_QWORD *)v13 + 6) = resource_data;
  }
  for ( ; mNumObjects; v8 += 144 )
  {
    --mNumObjects;
    v17 = 0;
    v18 = (UFG::qResourceHandle *)(v8 + 16);
    do
    {
      v19 = (UFG::qResourceHandle *)&v8[32 * v17 + 16];
      if ( v19 )
        UFG::qResourceHandle::qResourceHandle(v19);
      Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
      {
        v21 = UFG::qResourceWarehouse::Instance();
        Inventory = UFG::qResourceWarehouse::GetInventory(v21, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
      }
      UFG::qResourceHandle::Init(v18, 0xA2ADCD77, v18->mNameUID, Inventory);
      ++v17;
      ++v18;
    }
    while ( v17 < 2 );
  }
  UFG::qResourceInventory::Add(this, resource_data);
  if ( resource_data->mSectionVisIndex >= 0x400u )
    UFG::FarGroundLayout::OnFarGroundSceneryGroupLoad(resource_data);
}

// File Line: 96
// RVA: 0x234E10
void __fastcall UFG::SceneryGroupInventory::Remove(UFG::SceneryGroupInventory *this, UFG::SceneryGroup *resource_data)
{
  UFG::qBaseNodeRB *mOffset; // rax
  char *v5; // rbp
  int mNumObjects; // esi
  UFG::qResourceHandle *v7; // rbp
  UFG::qResourceHandle *v8; // rbx
  __int64 v9; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v11; // rax
  UFG::SceneryGroupComponent *mRenderComponent; // rcx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *p_mResourceHandles; // rdi
  UFG::qResourceHandle *mNext; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v16; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v17; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v18; // rax

  if ( resource_data->mSectionVisIndex >= 0x400u )
    UFG::FarGroundLayout::OnFarGroundSceneryGroupUnload(resource_data);
  UFG::qResourceInventory::Remove(this, resource_data);
  mOffset = (UFG::qBaseNodeRB *)resource_data->mObjects.mOffset;
  if ( mOffset )
    v5 = (char *)&resource_data->mObjects + (_QWORD)mOffset;
  else
    v5 = 0i64;
  mNumObjects = resource_data->mNumObjects;
  if ( resource_data->mNumObjects )
  {
    v7 = (UFG::qResourceHandle *)(v5 + 16);
    do
    {
      --mNumObjects;
      v8 = v7;
      v9 = 2i64;
      do
      {
        Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
        if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
        {
          v11 = UFG::qResourceWarehouse::Instance();
          Inventory = UFG::qResourceWarehouse::GetInventory(v11, 0xA2ADCD77);
          `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
        }
        UFG::qResourceHandle::Close(v8++, Inventory);
        --v9;
      }
      while ( v9 );
      v7 = (UFG::qResourceHandle *)((char *)v7 + 144);
    }
    while ( mNumObjects );
  }
  mRenderComponent = resource_data->mRenderComponent;
  if ( mRenderComponent )
    mRenderComponent->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr->__vecDelDtor(
      &mRenderComponent->UFG::SimComponent,
      1u);
  resource_data->mRenderComponent = 0i64;
  p_mResourceHandles = &resource_data->mResourceHandles;
  mNext = (UFG::qResourceHandle *)resource_data->mResourceHandles.UFG::qResourceData::mNode.mNext;
  if ( mNext != (UFG::qResourceHandle *)&resource_data->mResourceHandles )
  {
    do
    {
      mPrev = mNext->mPrev;
      v16 = mNext->mNext;
      mPrev->mNext = v16;
      v16->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      UFG::qResourceHandle::~qResourceHandle(mNext);
      operator delete[](mNext);
      mNext = (UFG::qResourceHandle *)resource_data->mResourceHandles.UFG::qResourceData::mNode.mNext;
    }
    while ( mNext != (UFG::qResourceHandle *)p_mResourceHandles );
  }
  v17 = p_mResourceHandles->mNode.mPrev;
  v18 = resource_data->mResourceHandles.UFG::qResourceData::mNode.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  p_mResourceHandles->mNode.mPrev = &p_mResourceHandles->mNode;
  resource_data->mResourceHandles.UFG::qResourceData::mNode.mNext = &resource_data->mResourceHandles.UFG::qResourceData::mNode;
}


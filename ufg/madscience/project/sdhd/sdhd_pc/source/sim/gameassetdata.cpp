// File Line: 22
// RVA: 0x5800B0
void __fastcall UFG::ModelData::Create(UFG::ModelData *this, UFG::SimObject *simObject, UFG::ModelAsset *modelAsset)
{
  UFG::SimComponent *v6; // rsi
  UFG::SimComponent *ComponentOfType; // rax
  const char *StaticTypeName; // rax
  unsigned __int64 v9; // rax
  int v10; // r8d
  unsigned int mNumItems; // r9d
  UFG::ModelAssetData **mItems; // r10
  UFG::ModelAssetData *v13; // rcx
  UFG::qResourceData *v14; // r13
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  int v16; // edi
  UFG::allocator::free_link *v17; // rax
  __int64 v18; // rax
  __int64 v19; // rbx
  unsigned int mUID; // r14d
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v22; // rax
  UFG::allocator::free_link *v23; // rax
  ModelType *v24; // rax
  ModelType *v25; // r14
  unsigned int i; // edi
  Illusion::rModel *v27; // rbx
  UFG::qResourceInventory *v28; // rax
  UFG::qResourceWarehouse *v29; // rax
  UFG::qResourceInventory *v30; // rax
  UFG::qResourceWarehouse *v31; // rax
  UFG::qMemoryPool *v32; // rax
  UFG::allocator::free_link *v33; // rax
  _DWORD *v34; // rax
  _DWORD *v35; // rbx
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v38; // rax
  char *MemImagePtr; // rax
  UFG::TiDo *Instance; // rax
  Illusion::ModelProxy v41[2]; // [rsp+38h] [rbp-60h] BYREF

  v6 = 0i64;
  if ( simObject )
    ComponentOfType = UFG::SimObject::GetComponentOfType(simObject, UFG::CompositeDrawableComponent::_TypeUID);
  else
    ComponentOfType = 0i64;
  if ( !ComponentOfType )
  {
    StaticTypeName = UFG::qReflectObjectType<UFG::SkeletonData,UFG::ModelAssetData>::GetStaticTypeName((UFG::qReflectObjectType<UFG::SkeletonData,UFG::ModelAssetData> *)this);
    v9 = UFG::qStringHash64(StaticTypeName, 0xFFFFFFFFFFFFFFFFui64);
    v10 = 0;
    mNumItems = modelAsset->mData.mData.mNumItems;
    if ( !mNumItems )
      goto LABEL_28;
    mItems = modelAsset->mData.mData.mItems;
    while ( mItems[v10]->mTypeUID != v9 )
    {
      if ( ++v10 >= mNumItems )
        goto LABEL_28;
    }
    v13 = mItems[v10];
    if ( v13 )
    {
      v14 = UFG::qResourceInventory::Get(&UFG::gRigInventory, (unsigned int)v13[1].vfptr);
      SimulationMemoryPool = UFG::GetSimulationMemoryPool();
      v16 = 1;
      v17 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x5E0ui64, "CompositeDrawableComponent", 0i64, 1u);
      if ( v17 )
      {
        UFG::CompositeDrawableComponent::CompositeDrawableComponent((UFG::CompositeDrawableComponent *)v17);
        v19 = v18;
      }
      else
      {
        v19 = 0i64;
      }
      UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)v41, simObject, 1);
      UFG::SimObjectModifier::AttachComponent((UFG::SimObjectModifier *)v41, (UFG::SimComponent *)v19, 0xFFFFFFFFi64);
      UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)v41);
      UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)v41);
      mUID = v14->mNode.mUID;
      Inventory = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
      if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
      {
        v22 = UFG::qResourceWarehouse::Instance();
        Inventory = UFG::qResourceWarehouse::GetInventory(v22, 0x39BC0A7Eu);
        `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = Inventory;
      }
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)(v19 + 1352), 0x39BC0A7Eu, mUID, Inventory);
      v23 = UFG::qMalloc(0xA0ui64, "ModelDataBase::ModelType", 0x800ui64);
      if ( v23 )
      {
        ModelType::ModelType((ModelType *)v23);
        v25 = v24;
      }
      else
      {
        v25 = 0i64;
      }
      *(_QWORD *)(v19 + 1424) = v25;
      if ( *(_DWORD *)(v19 + 1416) > 1u )
        v16 = *(_DWORD *)(v19 + 1416);
      *(_DWORD *)(v19 + 1416) = v16;
      UFG::qTypedResourceHandle<968624766,UFG::RigResource>::Init(&v25->mRigHandle, v14->mNode.mUID, v14);
      for ( i = 0; i < this->mModels.mData.mNumItems; ++i )
      {
        v27 = &this->mModels.mData.mItems[i];
        UFG::qResourceHandle::qResourceHandle(&v41[0].mModelHandle);
        v28 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
        if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
        {
          v29 = UFG::qResourceWarehouse::Instance();
          v28 = UFG::qResourceWarehouse::GetInventory(v29, 0xA2ADCD77);
          `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v28;
        }
        UFG::qResourceHandle::Init(&v41[0].mModelHandle, 0xA2ADCD77, 0, v28);
        v41[0].mRModel = v27;
        ModelType::AddModelBinding(v25, v41, &UFG::qMatrix44::msIdentity, 0, 0);
        v30 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
        if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
        {
          v31 = UFG::qResourceWarehouse::Instance();
          v30 = UFG::qResourceWarehouse::GetInventory(v31, 0xA2ADCD77);
          `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v30;
        }
        UFG::qResourceHandle::Close(&v41[0].mModelHandle, v30);
        UFG::qResourceHandle::~qResourceHandle(&v41[0].mModelHandle);
      }
    }
    else
    {
LABEL_28:
      v32 = UFG::GetSimulationMemoryPool();
      v33 = UFG::qMemoryPool::Allocate(v32, 0x100ui64, "SimpleDrawableComponent", 0i64, 1u);
      if ( v33 )
      {
        Render::SimpleDrawableComponent::SimpleDrawableComponent(
          (Render::SimpleDrawableComponent *)v33,
          modelAsset->mBaseNode.mUID);
        v35 = v34;
      }
      else
      {
        v35 = 0i64;
      }
      UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)v41, simObject, 1);
      if ( v35 )
        v6 = (UFG::SimComponent *)(v35 + 6);
      UFG::SimObjectModifier::AttachComponent((UFG::SimObjectModifier *)v41, v6, 0xFFFFFFFFi64);
      UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)v41);
      UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)v41);
      m_pSceneObj = simObject->m_pSceneObj;
      mpWritableProperties = m_pSceneObj->mpWritableProperties;
      if ( !mpWritableProperties )
        mpWritableProperties = m_pSceneObj->mpConstProperties;
      v38 = UFG::qPropertySet::Get<UFG::qPropertySet>(
              mpWritableProperties,
              (UFG::qArray<unsigned long,0> *)&component_ColourTint::sPropertyName,
              DEPTH_RECURSE);
      if ( v38 )
      {
        MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v38);
        if ( MemImagePtr )
        {
          v35[48] = *(_DWORD *)MemImagePtr;
          v35[49] = *((_DWORD *)MemImagePtr + 1);
          v35[50] = *((_DWORD *)MemImagePtr + 2);
          v35[51] = *((_DWORD *)MemImagePtr + 3);
        }
      }
    }
  }
  Instance = UFG::TiDo::GetInstance();
  Instance->vfptr->Create(Instance, simObject, modelAsset);
}

// File Line: 76
// RVA: 0x580480
void __fastcall UFG::SkeletonData::Create(
        UFG::SkeletonData *this,
        UFG::SimObject *simObject,
        UFG::ModelAsset *modelAsset)
{
  UFG::SimComponent *v5; // rbx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::RigResource *v7; // rsi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::SimComponent *v10; // rax
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h] BYREF

  v5 = 0i64;
  if ( simObject )
    ComponentOfType = UFG::SimObject::GetComponentOfType(simObject, UFG::CharacterAnimationComponent::_TypeUID);
  else
    ComponentOfType = 0i64;
  if ( !ComponentOfType )
  {
    v7 = (UFG::RigResource *)UFG::qResourceInventory::Get(&UFG::gRigInventory, this->mRigHandle);
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v9 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xE8ui64, "CharacterAnimationComponent", 0i64, 1u);
    if ( v9 )
    {
      UFG::CharacterAnimationComponent::CharacterAnimationComponent((UFG::CharacterAnimationComponent *)v9, v7);
      v5 = v10;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v11, simObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v11, v5, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v11);
    UFG::SimObjectModifier::~SimObjectModifier(&v11);
  }
}

// File Line: 89
// RVA: 0x57FF20
void __fastcall UFG::CollisionData::Create(
        UFG::CollisionData *this,
        UFG::SimObject *simObject,
        UFG::ModelAsset *modelAsset)
{
  const char *StaticTypeName; // rax
  unsigned __int64 v7; // rax
  unsigned int mNumItems; // r10d
  UFG::SkeletonData *v9; // r11
  unsigned int v10; // r9d
  UFG::ModelAssetData **mItems; // rdx

  StaticTypeName = UFG::qReflectObjectType<UFG::SkeletonData,UFG::ModelAssetData>::GetStaticTypeName((UFG::qReflectObjectType<UFG::SkeletonData,UFG::ModelAssetData> *)this);
  v7 = UFG::qStringHash64(StaticTypeName, 0xFFFFFFFFFFFFFFFFui64);
  mNumItems = modelAsset->mData.mData.mNumItems;
  v9 = 0i64;
  v10 = 0;
  if ( mNumItems )
  {
    mItems = modelAsset->mData.mData.mItems;
    while ( (*mItems)->mTypeUID != v7 )
    {
      ++v10;
      ++mItems;
      if ( v10 >= mNumItems )
        goto LABEL_7;
    }
    v9 = (UFG::SkeletonData *)modelAsset->mData.mData.mItems[v10];
  }
LABEL_7:
  UFG::PhysicsSystem::Create((UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance, simObject, this, v9);
}

// File Line: 95
// RVA: 0x580030
void __fastcall UFG::FreeRunData::Create(
        UFG::FreeRunData *this,
        UFG::SimObject *simObject,
        UFG::ModelAsset *modelAsset)
{
  const char *TypeName; // rax
  unsigned __int64 v7; // rax
  unsigned int mNumItems; // r10d
  unsigned int v9; // r9d
  UFG::ModelAssetData **mItems; // r8

  TypeName = UFG::qReflectObjectType<UFG::FreeRunData,UFG::ModelAssetData>::GetTypeName(this);
  v7 = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  mNumItems = modelAsset->mData.mData.mNumItems;
  v9 = 0;
  if ( mNumItems )
  {
    mItems = modelAsset->mData.mData.mItems;
    do
    {
      if ( (*mItems)->mTypeUID == v7 )
        break;
      ++v9;
      ++mItems;
    }
    while ( v9 < mNumItems );
  }
  UFG::PhysicsSystem::Create((UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance, simObject, this);
}

// File Line: 101
// RVA: 0x57FFB0
void __fastcall UFG::CoverData::Create(UFG::CoverData *this, UFG::SimObject *simObject, UFG::ModelAsset *modelAsset)
{
  const char *TypeName; // rax
  unsigned __int64 v7; // rax
  unsigned int mNumItems; // r10d
  unsigned int v9; // r9d
  UFG::ModelAssetData **mItems; // r8

  TypeName = UFG::qReflectObjectType<UFG::CoverData,UFG::ModelAssetData>::GetTypeName(this);
  v7 = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  mNumItems = modelAsset->mData.mData.mNumItems;
  v9 = 0;
  if ( mNumItems )
  {
    mItems = modelAsset->mData.mData.mItems;
    do
    {
      if ( (*mItems)->mTypeUID == v7 )
        break;
      ++v9;
      ++mItems;
    }
    while ( v9 < mNumItems );
  }
  UFG::PhysicsSystem::Create((UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance, simObject, this);
}


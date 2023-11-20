// File Line: 22
// RVA: 0x5800B0
void __fastcall UFG::ModelData::Create(UFG::ModelData *this, UFG::SimObject *simObject, UFG::ModelAsset *modelAsset)
{
  UFG::ModelAsset *v3; // r12
  UFG::SimObject *v4; // r15
  UFG::ModelData *v5; // rbp
  UFG::SimComponent *v6; // rsi
  UFG::SimComponent *v7; // rax
  const char *v8; // rax
  unsigned __int64 v9; // rax
  int v10; // er8
  unsigned int v11; // er9
  UFG::ModelAssetData **v12; // r10
  UFG::ModelAssetData *v13; // rcx
  UFG::qResourceData *v14; // r13
  UFG::qMemoryPool *v15; // rax
  signed int v16; // edi
  UFG::allocator::free_link *v17; // rax
  __int64 v18; // rax
  __int64 v19; // rbx
  unsigned int v20; // er14
  UFG::qResourceInventory *v21; // rax
  UFG::qResourceWarehouse *v22; // rax
  UFG::allocator::free_link *v23; // rax
  ModelType *v24; // rax
  ModelType *v25; // r14
  unsigned int i; // edi
  signed __int64 v27; // rbx
  UFG::qResourceInventory *v28; // rax
  UFG::qResourceWarehouse *v29; // rax
  UFG::qResourceInventory *v30; // rax
  UFG::qResourceWarehouse *v31; // rax
  UFG::qMemoryPool *v32; // rax
  UFG::allocator::free_link *v33; // rax
  _DWORD *v34; // rax
  _DWORD *v35; // rbx
  UFG::SceneObjectProperties *v36; // rax
  UFG::qPropertySet *v37; // rcx
  UFG::qPropertySet *v38; // rax
  char *v39; // rax
  UFG::TiDo *v40; // rax
  UFG::SimObjectModifier v41; // [rsp+38h] [rbp-60h]
  __int64 v42; // [rsp+58h] [rbp-40h]

  v3 = modelAsset;
  v4 = simObject;
  v5 = this;
  v6 = 0i64;
  if ( simObject )
    v7 = UFG::SimObject::GetComponentOfType(simObject, UFG::CompositeDrawableComponent::_TypeUID);
  else
    v7 = 0i64;
  if ( v7 == 0i64 )
  {
    v8 = UFG::qReflectObjectType<UFG::SkeletonData,UFG::ModelAssetData>::GetStaticTypeName((UFG::qReflectObjectType<UFG::SkeletonData,UFG::ModelAssetData> *)this);
    v9 = UFG::qStringHash64(v8, 0xFFFFFFFFFFFFFFFFui64);
    v10 = 0;
    v11 = v3->mData.mData.mNumItems;
    if ( !v11 )
      goto LABEL_28;
    v12 = v3->mData.mData.mItems;
    while ( v12[v10]->mTypeUID != v9 )
    {
      if ( ++v10 >= v11 )
        goto LABEL_28;
    }
    v13 = v12[v10];
    if ( v13 )
    {
      v14 = UFG::qResourceInventory::Get(
              (UFG::qResourceInventory *)&UFG::gRigInventory.vfptr,
              (unsigned int)v13[1].vfptr);
      v15 = UFG::GetSimulationMemoryPool();
      v16 = 1;
      v17 = UFG::qMemoryPool::Allocate(v15, 0x5E0ui64, "CompositeDrawableComponent", 0i64, 1u);
      if ( v17 )
      {
        UFG::CompositeDrawableComponent::CompositeDrawableComponent((UFG::CompositeDrawableComponent *)v17);
        v19 = v18;
      }
      else
      {
        v19 = 0i64;
      }
      UFG::SimObjectModifier::SimObjectModifier(&v41, v4, 1);
      UFG::SimObjectModifier::AttachComponent(&v41, (UFG::SimComponent *)v19, 0xFFFFFFFFi64);
      UFG::SimObjectModifier::Close(&v41);
      UFG::SimObjectModifier::~SimObjectModifier(&v41);
      v20 = v14->mNode.mUID;
      v21 = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
      if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
      {
        v22 = UFG::qResourceWarehouse::Instance();
        v21 = UFG::qResourceWarehouse::GetInventory(v22, 0x39BC0A7Eu);
        `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = v21;
      }
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)(v19 + 1352), 0x39BC0A7Eu, v20, v21);
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
      UFG::qTypedResourceHandle<968624766,UFG::RigResource>::Init(
        (UFG::qTypedResourceHandle<968624766,UFG::RigResource> *)&v25->mRigHandle.mPrev,
        v14->mNode.mUID,
        v14);
      for ( i = 0; i < v5->mModels.mData.mNumItems; ++i )
      {
        v27 = (signed __int64)&v5->mModels.mData.mItems[i];
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v41);
        v28 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
        if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
        {
          v29 = UFG::qResourceWarehouse::Instance();
          v28 = UFG::qResourceWarehouse::GetInventory(v29, 0xA2ADCD77);
          `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v28;
        }
        UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v41, 0xA2ADCD77, 0, v28);
        v42 = v27;
        ModelType::AddModelBinding(v25, (Illusion::ModelProxy *)&v41, &UFG::qMatrix44::msIdentity, 0, 0);
        v30 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
        if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
        {
          v31 = UFG::qResourceWarehouse::Instance();
          v30 = UFG::qResourceWarehouse::GetInventory(v31, 0xA2ADCD77);
          `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v30;
        }
        UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v41, v30);
        UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v41);
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
          v3->mBaseNode.mUID);
        v35 = v34;
      }
      else
      {
        v35 = 0i64;
      }
      UFG::SimObjectModifier::SimObjectModifier(&v41, v4, 1);
      if ( v35 )
        v6 = (UFG::SimComponent *)(v35 + 6);
      UFG::SimObjectModifier::AttachComponent(&v41, v6, 0xFFFFFFFFi64);
      UFG::SimObjectModifier::Close(&v41);
      UFG::SimObjectModifier::~SimObjectModifier(&v41);
      v36 = v4->m_pSceneObj;
      v37 = v36->mpWritableProperties;
      if ( !v37 )
        v37 = v36->mpConstProperties;
      v38 = UFG::qPropertySet::Get<UFG::qPropertySet>(
              v37,
              (UFG::qSymbol *)&component_ColourTint::sPropertyName.mUID,
              DEPTH_RECURSE);
      if ( v38 )
      {
        v39 = UFG::qPropertySet::GetMemImagePtr(v38);
        if ( v39 )
        {
          v35[48] = *(_DWORD *)v39;
          v35[49] = *((_DWORD *)v39 + 1);
          v35[50] = *((_DWORD *)v39 + 2);
          v35[51] = *((_DWORD *)v39 + 3);
        }
      }
    }
  }
  v40 = UFG::TiDo::GetInstance();
  v40->vfptr->Create(v40, v4, v3);
}

// File Line: 76
// RVA: 0x580480
void __fastcall UFG::SkeletonData::Create(UFG::SkeletonData *this, UFG::SimObject *simObject, UFG::ModelAsset *modelAsset)
{
  UFG::SimObject *v3; // rdi
  UFG::SkeletonData *v4; // rsi
  UFG::SimComponent *v5; // rbx
  UFG::SimComponent *v6; // rax
  UFG::RigResource *v7; // rsi
  UFG::qMemoryPool *v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::SimComponent *v10; // rax
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h]

  v3 = simObject;
  v4 = this;
  v5 = 0i64;
  if ( simObject )
    v6 = UFG::SimObject::GetComponentOfType(simObject, UFG::CharacterAnimationComponent::_TypeUID);
  else
    v6 = 0i64;
  if ( v6 == 0i64 )
  {
    v7 = (UFG::RigResource *)UFG::qResourceInventory::Get(
                               (UFG::qResourceInventory *)&UFG::gRigInventory.vfptr,
                               v4->mRigHandle);
    v8 = UFG::GetSimulationMemoryPool();
    v9 = UFG::qMemoryPool::Allocate(v8, 0xE8ui64, "CharacterAnimationComponent", 0i64, 1u);
    if ( v9 )
    {
      UFG::CharacterAnimationComponent::CharacterAnimationComponent((UFG::CharacterAnimationComponent *)v9, v7);
      v5 = v10;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v11, v3, 1);
    UFG::SimObjectModifier::AttachComponent(&v11, v5, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v11);
    UFG::SimObjectModifier::~SimObjectModifier(&v11);
  }
}

// File Line: 89
// RVA: 0x57FF20
void __fastcall UFG::CollisionData::Create(UFG::CollisionData *this, UFG::SimObject *simObject, UFG::ModelAsset *modelAsset)
{
  UFG::ModelAsset *v3; // rbx
  UFG::SimObject *v4; // rdi
  UFG::CollisionData *v5; // rsi
  const char *v6; // rax
  unsigned __int64 v7; // rax
  unsigned int v8; // er10
  UFG::SkeletonData *v9; // r11
  unsigned int v10; // er9
  UFG::ModelAssetData **v11; // rdx

  v3 = modelAsset;
  v4 = simObject;
  v5 = this;
  v6 = UFG::qReflectObjectType<UFG::SkeletonData,UFG::ModelAssetData>::GetStaticTypeName((UFG::qReflectObjectType<UFG::SkeletonData,UFG::ModelAssetData> *)this);
  v7 = UFG::qStringHash64(v6, 0xFFFFFFFFFFFFFFFFui64);
  v8 = v3->mData.mData.mNumItems;
  v9 = 0i64;
  v10 = 0;
  if ( v8 )
  {
    v11 = v3->mData.mData.mItems;
    while ( (*v11)->mTypeUID != v7 )
    {
      ++v10;
      ++v11;
      if ( v10 >= v8 )
        goto LABEL_7;
    }
    v9 = (UFG::SkeletonData *)v3->mData.mData.mItems[v10];
  }
LABEL_7:
  UFG::PhysicsSystem::Create((UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance, v4, v5, v9);
}

// File Line: 95
// RVA: 0x580030
void __fastcall UFG::FreeRunData::Create(UFG::FreeRunData *this, UFG::SimObject *simObject, UFG::ModelAsset *modelAsset)
{
  UFG::ModelAsset *v3; // rbx
  UFG::SimObject *v4; // rdi
  UFG::FreeRunData *v5; // rsi
  const char *v6; // rax
  unsigned __int64 v7; // rax
  unsigned int v8; // er10
  unsigned int v9; // er9
  UFG::ModelAssetData **v10; // r8

  v3 = modelAsset;
  v4 = simObject;
  v5 = this;
  v6 = UFG::qReflectObjectType<UFG::FreeRunData,UFG::ModelAssetData>::GetTypeName((UFG::qReflectObjectType<UFG::FreeRunData,UFG::ModelAssetData> *)&this->vfptr);
  v7 = UFG::qStringHash64(v6, 0xFFFFFFFFFFFFFFFFui64);
  v8 = v3->mData.mData.mNumItems;
  v9 = 0;
  if ( v8 )
  {
    v10 = v3->mData.mData.mItems;
    do
    {
      if ( (*v10)->mTypeUID == v7 )
        break;
      ++v9;
      ++v10;
    }
    while ( v9 < v8 );
  }
  UFG::PhysicsSystem::Create((UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance, v4, v5);
}

// File Line: 101
// RVA: 0x57FFB0
void __fastcall UFG::CoverData::Create(UFG::CoverData *this, UFG::SimObject *simObject, UFG::ModelAsset *modelAsset)
{
  UFG::ModelAsset *v3; // rbx
  UFG::SimObject *v4; // rdi
  UFG::CoverData *v5; // rsi
  const char *v6; // rax
  unsigned __int64 v7; // rax
  unsigned int v8; // er10
  unsigned int v9; // er9
  UFG::ModelAssetData **v10; // r8

  v3 = modelAsset;
  v4 = simObject;
  v5 = this;
  v6 = UFG::qReflectObjectType<UFG::CoverData,UFG::ModelAssetData>::GetTypeName((UFG::qReflectObjectType<UFG::CoverData,UFG::ModelAssetData> *)&this->vfptr);
  v7 = UFG::qStringHash64(v6, 0xFFFFFFFFFFFFFFFFui64);
  v8 = v3->mData.mData.mNumItems;
  v9 = 0;
  if ( v8 )
  {
    v10 = v3->mData.mData.mItems;
    do
    {
      if ( (*v10)->mTypeUID == v7 )
        break;
      ++v9;
      ++v10;
    }
    while ( v9 < v8 );
  }
  UFG::PhysicsSystem::Create((UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance, v4, v5);
}


// File Line: 54
// RVA: 0x15143D0
__int64 dynamic_initializer_for__UFG::SensorComponent::s_SensorComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SensorComponent::s_SensorComponentList__);
}

// File Line: 55
// RVA: 0x466460
UFG::ComponentIDDesc *__fastcall UFG::SensorComponent::GetDesc(UFG::SensorComponent *this)
{
  return &UFG::SensorComponent::_TypeIDesc;
}

// File Line: 66
// RVA: 0x44D4D0
void __fastcall UFG::SensorComponent::SensorComponent(
        UFG::SensorComponent *this,
        unsigned int name_uid,
        component_Sensor *dataPtr)
{
  UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *mPrev; // rax
  __m128 mSensorPhantomSizeZ_low; // xmm7
  __m128 v7; // xmm4
  __m128 mSensorPhantomSizeY_low; // xmm6
  __m128 v9; // xmm2
  __m128 mSensorPhantomSizeX_low; // xmm5
  __m128 v11; // xmm3
  UFG::allocator::free_link *v12; // rax
  UFG::SensorPhantom *v13; // rax
  UFG::allocator::free_link *v14; // rax
  hkAabb aabb; // [rsp+40h] [rbp-48h] BYREF

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::SensorComponent,UFG::SensorComponent>;
  this->mNext = &this->UFG::qNode<UFG::SensorComponent,UFG::SensorComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SensorComponent::`vftable;
  this->mWallRunningRequests.mNode.mPrev = &this->mWallRunningRequests.mNode;
  this->mWallRunningRequests.mNode.mNext = &this->mWallRunningRequests.mNode;
  this->mLatchedWallRunningRequests.mNode.mPrev = &this->mLatchedWallRunningRequests.mNode;
  this->mLatchedWallRunningRequests.mNode.mNext = &this->mLatchedWallRunningRequests.mNode;
  this->mSphereCaster = 0i64;
  this->mActiveRegion = 0i64;
  qmemcpy(&this->mSensorPhantomSizeX, "ffF@ffF@ffF@", 12);
  mPrev = UFG::SensorComponent::s_SensorComponentList.mNode.mPrev;
  UFG::SensorComponent::s_SensorComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::SensorComponent,UFG::SensorComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *)&UFG::SensorComponent::s_SensorComponentList;
  UFG::SensorComponent::s_SensorComponentList.mNode.mPrev = &this->UFG::qNode<UFG::SensorComponent,UFG::SensorComponent>;
  UFG::SimComponent::AddType(this, UFG::SensorComponent::_SensorComponentTypeUID, "SensorComponent");
  if ( dataPtr )
    UFG::SensorComponent::PropertiesLoad(this, dataPtr);
  mSensorPhantomSizeZ_low = (__m128)LODWORD(this->mSensorPhantomSizeZ);
  v7 = mSensorPhantomSizeZ_low;
  v7.m128_f32[0] = mSensorPhantomSizeZ_low.m128_f32[0] * -0.5;
  mSensorPhantomSizeY_low = (__m128)LODWORD(this->mSensorPhantomSizeY);
  v9 = mSensorPhantomSizeY_low;
  v9.m128_f32[0] = mSensorPhantomSizeY_low.m128_f32[0] * -0.5;
  mSensorPhantomSizeX_low = (__m128)LODWORD(this->mSensorPhantomSizeX);
  v11 = mSensorPhantomSizeX_low;
  v11.m128_f32[0] = mSensorPhantomSizeX_low.m128_f32[0] * -0.5;
  aabb.m_min.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v11, v7), _mm_unpacklo_ps(v9, (__m128)0i64));
  mSensorPhantomSizeZ_low.m128_f32[0] = mSensorPhantomSizeZ_low.m128_f32[0] * 0.5;
  mSensorPhantomSizeY_low.m128_f32[0] = mSensorPhantomSizeY_low.m128_f32[0] * 0.5;
  mSensorPhantomSizeX_low.m128_f32[0] = mSensorPhantomSizeX_low.m128_f32[0] * 0.5;
  aabb.m_max.m_quad = _mm_unpacklo_ps(
                        _mm_unpacklo_ps(mSensorPhantomSizeX_low, mSensorPhantomSizeZ_low),
                        _mm_unpacklo_ps(mSensorPhantomSizeY_low, (__m128)0i64));
  v12 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x18ui64, "SensorPhantom", 0i64, 1u);
  if ( v12 )
    UFG::SensorPhantom::SensorPhantom((UFG::SensorPhantom *)v12, &aabb, 0x1Du, "SensorComponent");
  else
    v13 = 0i64;
  this->mSensor = v13;
  once_3 = 0;
  v14 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
  if ( v14 )
  {
    v14->mNext = v14;
    v14[1].mNext = v14;
    v14[8].mNext = 0i64;
    v14[7].mNext = 0i64;
  }
  else
  {
    v14 = 0i64;
  }
  this->mParkourQuery = (UFG::ParkourQuery *)v14;
}

// File Line: 98
// RVA: 0x470AC0
void __fastcall UFG::SensorComponent::PropertiesLoad(UFG::SensorComponent *this, component_Sensor *dataPtr)
{
  UFG::allocator::free_link *v3; // rax
  UFG::ActiveRegion *v4; // rax
  UFG::ActiveRegion *v5; // rdx
  UFG::ActiveRegionManager *p_mActiveRegionManager; // rcx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *mPrev; // rax
  hkVector4f centre; // [rsp+30h] [rbp-28h] BYREF
  hkVector4f extents; // [rsp+40h] [rbp-18h] BYREF

  this->mSensorPhantomSizeX = dataPtr->SensorPhantomSizeX;
  this->mSensorPhantomSizeY = dataPtr->SensorPhantomSizeY;
  this->mSensorPhantomSizeZ = dataPtr->SensorPhantomSizeZ;
  if ( dataPtr->HasActiveRegion )
  {
    extents.m_quad = (__m128)_xmm;
    centre.m_quad = 0i64;
    v3 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
    if ( v3 )
    {
      UFG::ActiveRegion::ActiveRegion((UFG::ActiveRegion *)v3, &extents, &centre);
      v5 = v4;
    }
    else
    {
      v5 = 0i64;
    }
    this->mActiveRegion = v5;
    p_mActiveRegionManager = &UFG::BasePhysicsSystem::mInstance->mActiveRegionManager;
    mPrev = UFG::BasePhysicsSystem::mInstance->mActiveRegionManager.mRegions.mNode.mPrev;
    mPrev->mNext = v5;
    v5->mPrev = mPrev;
    v5->mNext = &p_mActiveRegionManager->mRegions.mNode;
    p_mActiveRegionManager->mRegions.mNode.mPrev = v5;
  }
}

// File Line: 115
// RVA: 0x4710F0
UFG::SimComponent *__fastcall UFG::SensorComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *sceneObject,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *MemImagePtr; // rdi
  UFG::allocator::free_link *v9; // rax
  UFG::SimComponent *v10; // rax
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v13; // ebx
  UFG::SimObjectModifier v14; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = sceneObject->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sceneObject->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_Sensor::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
  else
    MemImagePtr = 0i64;
  if ( !required && !MemImagePtr )
    return 0i64;
  v9 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0xA0ui64, "SensorComponent", 0i64, 1u);
  if ( v9 )
  {
    UFG::SensorComponent::SensorComponent(
      (UFG::SensorComponent *)v9,
      sceneObject->m_NameUID,
      (component_Sensor *)MemImagePtr);
    v6 = v10;
  }
  m_pSimObject = sceneObject->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v13 = 26;
  else
    v13 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v14, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v14, v6, v13);
  UFG::SimObjectModifier::Close(&v14);
  UFG::SimObjectModifier::~SimObjectModifier(&v14);
  return v6;
}

// File Line: 137
// RVA: 0x451130
void __fastcall UFG::SensorComponent::~SensorComponent(UFG::SensorComponent *this)
{
  UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *v2; // rsi
  UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *mPrev; // rcx
  UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *mNext; // rax
  UFG::ActiveRegion *mActiveRegion; // rdx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v6; // rcx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v7; // rax
  UFG::ActiveRegion *v8; // rcx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v9; // rdx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v10; // rax
  UFG::SensorPhantom *mSensor; // rcx
  UFG::ShapeCasterCollector *mSphereCaster; // rcx
  UFG::ParkourQuery *mParkourQuery; // rbx
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v14; // rcx
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v15; // rax
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v16; // rcx
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v17; // rax
  UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *v18; // rcx
  UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *v19; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SensorComponent::`vftable;
  if ( this == UFG::SensorComponent::s_SensorComponentpCurrentIterator )
    UFG::SensorComponent::s_SensorComponentpCurrentIterator = (UFG::SensorComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::SensorComponent,UFG::SensorComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  mActiveRegion = this->mActiveRegion;
  if ( mActiveRegion )
  {
    v6 = mActiveRegion->mPrev;
    v7 = mActiveRegion->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    mActiveRegion->mPrev = mActiveRegion;
    mActiveRegion->mNext = mActiveRegion;
    v8 = this->mActiveRegion;
    if ( v8 )
    {
      v9 = v8->mPrev;
      v10 = v8->mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = v8;
      v8->mNext = v8;
      operator delete[](v8);
    }
  }
  mSensor = this->mSensor;
  if ( mSensor )
    mSensor->vfptr->__vecDelDtor(mSensor, 1u);
  mSphereCaster = this->mSphereCaster;
  if ( mSphereCaster )
    mSphereCaster->vfptr->__vecDelDtor(mSphereCaster, 1u);
  mParkourQuery = this->mParkourQuery;
  if ( mParkourQuery )
  {
    UFG::ParkourQuery::~ParkourQuery(this->mParkourQuery);
    operator delete[](mParkourQuery);
  }
  UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0>::DeleteNodes(&this->mLatchedWallRunningRequests);
  v14 = this->mLatchedWallRunningRequests.mNode.mPrev;
  v15 = this->mLatchedWallRunningRequests.mNode.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  this->mLatchedWallRunningRequests.mNode.mPrev = &this->mLatchedWallRunningRequests.mNode;
  this->mLatchedWallRunningRequests.mNode.mNext = &this->mLatchedWallRunningRequests.mNode;
  UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0>::DeleteNodes(&this->mWallRunningRequests);
  v16 = this->mWallRunningRequests.mNode.mPrev;
  v17 = this->mWallRunningRequests.mNode.mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  this->mWallRunningRequests.mNode.mPrev = &this->mWallRunningRequests.mNode;
  this->mWallRunningRequests.mNode.mNext = &this->mWallRunningRequests.mNode;
  v18 = v2->mPrev;
  v19 = v2->mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 154
// RVA: 0x47D2F0
void __fastcall UFG::SensorComponent::Update(UFG::SensorComponent *this, float delta_sec)
{
  UFG::SimObject *m_pSimObject; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::SensorPhantom *mSensor; // rcx
  float z; // xmm2_4
  float w; // xmm3_4
  float x; // xmm0_4
  float y; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  UFG::ParkourQuery *mParkourQuery; // rax
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  UFG::ActiveRegion *mActiveRegion; // rcx
  UFG::ParkourQuery *v23; // rcx
  UFG::qList<UFG::ParkourQuery,UFG::ParkourQuery,1,0> *p_mQueries; // rdx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *mPrev; // rax
  hkVector4f centre; // [rsp+20h] [rbp-50h] BYREF
  UFG::qMatrix44 transform; // [rsp+30h] [rbp-40h] BYREF

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject || (m_pSimObject->m_Flags & 0x400) == 0 )
  {
    if ( m_pSimObject )
      m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
    else
      m_pTransformNodeComponent = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    mSensor = this->mSensor;
    z = m_pTransformNodeComponent->mWorldTransform.v0.z;
    w = m_pTransformNodeComponent->mWorldTransform.v0.w;
    x = m_pTransformNodeComponent->mWorldTransform.v0.x;
    transform.v0.y = m_pTransformNodeComponent->mWorldTransform.v0.y;
    transform.v0.z = z;
    transform.v0.x = x;
    transform.v0.w = w;
    y = m_pTransformNodeComponent->mWorldTransform.v1.y;
    v10 = m_pTransformNodeComponent->mWorldTransform.v1.z;
    v11 = m_pTransformNodeComponent->mWorldTransform.v1.w;
    transform.v1.x = m_pTransformNodeComponent->mWorldTransform.v1.x;
    transform.v1.y = y;
    transform.v1.z = v10;
    transform.v1.w = v11;
    v12 = m_pTransformNodeComponent->mWorldTransform.v2.z;
    v13 = m_pTransformNodeComponent->mWorldTransform.v2.w;
    v14 = m_pTransformNodeComponent->mWorldTransform.v2.x;
    transform.v2.y = m_pTransformNodeComponent->mWorldTransform.v2.y;
    transform.v2.x = v14;
    transform.v2.z = v12;
    transform.v2.w = v13;
    v15 = m_pTransformNodeComponent->mWorldTransform.v3.z;
    v16 = m_pTransformNodeComponent->mWorldTransform.v3.w;
    v17 = m_pTransformNodeComponent->mWorldTransform.v3.x;
    transform.v3.y = m_pTransformNodeComponent->mWorldTransform.v3.y;
    transform.v3.z = v15;
    transform.v3.x = v17;
    transform.v3.w = v16;
    UFG::SensorPhantom::SetTransform(mSensor, &transform);
    mParkourQuery = this->mParkourQuery;
    if ( mParkourQuery )
    {
      v19 = transform.v3.z;
      v20 = transform.v3.w;
      v21 = transform.v3.x;
      mParkourQuery->mCentre.y = transform.v3.y;
      mParkourQuery->mCentre.z = v19;
      mParkourQuery->mCentre.x = v21;
      mParkourQuery->mCentre.w = v20;
    }
    mActiveRegion = this->mActiveRegion;
    if ( mActiveRegion )
    {
      centre.m_quad = _mm_unpacklo_ps(
                        _mm_unpacklo_ps((__m128)LODWORD(transform.v3.x), (__m128)LODWORD(transform.v3.z)),
                        _mm_unpacklo_ps((__m128)LODWORD(transform.v3.y), (__m128)LODWORD(transform.v3.w)));
      UFG::ActiveRegion::SetCentre(mActiveRegion, &centre);
    }
    UFG::SensorComponent::CollectWallRunningInfo(this);
    if ( (m_pSimObject->m_Flags & 0x4000) != 0 )
    {
      this->mParkourQuery->handlesOut.size = 0;
      this->mParkourQuery->userData = this;
      this->mParkourQuery->callback = 0i64;
      this->mParkourQuery->mRadius = 4.5;
      v23 = this->mParkourQuery;
      p_mQueries = &UFG::ParkourQueryManager::mInstance->mQueries;
      mPrev = UFG::ParkourQueryManager::mInstance->mQueries.mNode.mPrev;
      mPrev->mNext = v23;
      v23->mPrev = mPrev;
      v23->mNext = &p_mQueries->mNode;
      p_mQueries->mNode.mPrev = v23;
    }
  }
}

// File Line: 199
// RVA: 0x476CC0
void __fastcall UFG::SensorComponent::TeleportEventHandler(UFG::SensorComponent *this, UFG::Event *event)
{
  UFG::SensorPhantom::SetTransform(this->mSensor, (UFG::qMatrix44 *)&event[1].m_EventUID);
}

// File Line: 207
// RVA: 0x466720
void __fastcall UFG::SensorComponent::GetExtents(UFG::SensorComponent *this, UFG::qVector3 *vmin, UFG::qVector3 *vmax)
{
  Scaleform::Render::WrapperImageSource::GetImageType(this->mSensor, vmin, vmax);
}

// File Line: 215
// RVA: 0x45A710
void __fastcall UFG::SensorComponent::CollectParkourHandles(UFG::SensorComponent *this, float queryRadius)
{
  UFG::ParkourQuery *mParkourQuery; // rcx
  UFG::qList<UFG::ParkourQuery,UFG::ParkourQuery,1,0> *p_mQueries; // rdx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *mPrev; // rax

  this->mParkourQuery->handlesOut.size = 0;
  this->mParkourQuery->userData = this;
  this->mParkourQuery->callback = 0i64;
  this->mParkourQuery->mRadius = queryRadius;
  mParkourQuery = this->mParkourQuery;
  p_mQueries = &UFG::ParkourQueryManager::mInstance->mQueries;
  mPrev = UFG::ParkourQueryManager::mInstance->mQueries.mNode.mPrev;
  mPrev->mNext = mParkourQuery;
  mParkourQuery->mPrev = mPrev;
  mParkourQuery->mNext = &p_mQueries->mNode;
  p_mQueries->mNode.mPrev = mParkourQuery;
}

// File Line: 235
// RVA: 0x466C80
void __fastcall UFG::SensorComponent::GetParkourHandles(
        UFG::SensorComponent *this,
        UFG::qFixedArray<UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle>,768> *out)
{
  unsigned int v4; // r10d
  UFG::ParkourQuery *mParkourQuery; // rdx
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p; // rax
  __int64 m_pPointer; // rcx
  __int64 **v8; // rcx
  __int64 *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> **v10; // rdx
  __int64 v11; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v14; // rax
  __int64 *v15; // rcx
  __int64 **v16; // rax
  __int64 *v17; // rcx
  __int64 **v18; // rax
  UFG::SensorComponent *i; // r9
  __int64 m_pSimObject; // rcx
  __int64 **v21; // rcx
  __int64 *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> **v23; // rdx
  __int64 v24; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v27; // rax
  __int64 *v28; // rcx
  __int64 **v29; // rax
  __int64 *v30; // rcx
  __int64 **v31; // rax
  UFG::SensorComponent *j; // r9
  __int64 v33; // rcx
  __int64 **v34; // rcx
  __int64 *v35; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> **v36; // rdx
  __int64 v37; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v38; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v39; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v40; // rax
  __int64 *v41; // rcx
  __int64 **v42; // rax
  __int64 *v43; // rcx
  __int64 **v44; // rax
  __int64 *v45; // [rsp+8h] [rbp-18h] BYREF
  __int64 **v46; // [rsp+10h] [rbp-10h]
  __int64 v47; // [rsp+18h] [rbp-8h]

  v4 = 0;
  mParkourQuery = this->mParkourQuery;
  if ( mParkourQuery->handlesOut.size )
  {
    do
    {
      p = mParkourQuery->handlesOut.p;
      v45 = (__int64 *)&v45;
      v46 = &v45;
      m_pPointer = (__int64)p[v4].m_pPointer;
      v47 = m_pPointer;
      if ( m_pPointer )
      {
        v8 = (__int64 **)(m_pPointer + 8);
        v9 = *v8;
        v9[1] = (__int64)&v45;
        v45 = v9;
        v46 = v8;
        *v8 = (__int64 *)&v45;
      }
      v10 = &out->p[0].mPrev + 2 * out->size + out->size;
      v11 = v47;
      if ( v10[2] )
      {
        v12 = *v10;
        v13 = v10[1];
        v12->mNext = v13;
        v13->mPrev = v12;
        *v10 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v10;
        v10[1] = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v10;
      }
      v10[2] = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v11;
      if ( v11 )
      {
        v14 = *(UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> **)(v11 + 8);
        v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v10;
        *v10 = v14;
        v10[1] = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)(v11 + 8);
        *(_QWORD *)(v11 + 8) = v10;
      }
      ++out->size;
      if ( v47 )
      {
        v15 = v45;
        v16 = v46;
        v45[1] = (__int64)v46;
        *v16 = v15;
        v45 = (__int64 *)&v45;
        v46 = &v45;
      }
      v47 = 0i64;
      v17 = v45;
      v18 = v46;
      v45[1] = (__int64)v46;
      *v18 = v17;
      v45 = (__int64 *)&v45;
      v46 = &v45;
      ++v4;
      mParkourQuery = this->mParkourQuery;
    }
    while ( v4 < mParkourQuery->handlesOut.size );
  }
  for ( i = (UFG::SensorComponent *)this->mWallRunningRequests.mNode.mNext;
        i != (UFG::SensorComponent *)&this->mWallRunningRequests;
        i = (UFG::SensorComponent *)i->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev )
  {
    m_pSimObject = (__int64)i->m_pSimObject;
    if ( m_pSimObject )
    {
      v45 = (__int64 *)&v45;
      v46 = &v45;
      v47 = m_pSimObject;
      v21 = (__int64 **)(m_pSimObject + 8);
      v22 = *v21;
      v22[1] = (__int64)&v45;
      v45 = v22;
      v46 = v21;
      *v21 = (__int64 *)&v45;
      v23 = &out->p[0].mPrev + 2 * out->size + out->size;
      v24 = v47;
      if ( v23[2] )
      {
        v25 = *v23;
        v26 = v23[1];
        v25->mNext = v26;
        v26->mPrev = v25;
        *v23 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v23;
        v23[1] = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v23;
      }
      v23[2] = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v24;
      if ( v24 )
      {
        v27 = *(UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> **)(v24 + 8);
        v27->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v23;
        *v23 = v27;
        v23[1] = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)(v24 + 8);
        *(_QWORD *)(v24 + 8) = v23;
      }
      ++out->size;
      if ( v47 )
      {
        v28 = v45;
        v29 = v46;
        v45[1] = (__int64)v46;
        *v29 = v28;
        v45 = (__int64 *)&v45;
        v46 = &v45;
      }
      v47 = 0i64;
      v30 = v45;
      v31 = v46;
      v45[1] = (__int64)v46;
      *v31 = v30;
      v45 = (__int64 *)&v45;
      v46 = &v45;
    }
  }
  for ( j = (UFG::SensorComponent *)this->mLatchedWallRunningRequests.mNode.mNext;
        j != (UFG::SensorComponent *)&this->mLatchedWallRunningRequests;
        j = (UFG::SensorComponent *)j->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev )
  {
    v33 = (__int64)j->m_pSimObject;
    if ( v33 )
    {
      v45 = (__int64 *)&v45;
      v46 = &v45;
      v47 = v33;
      v34 = (__int64 **)(v33 + 8);
      v35 = *v34;
      v35[1] = (__int64)&v45;
      v45 = v35;
      v46 = v34;
      *v34 = (__int64 *)&v45;
      v36 = &out->p[0].mPrev + 2 * out->size + out->size;
      v37 = v47;
      if ( v36[2] )
      {
        v38 = *v36;
        v39 = v36[1];
        v38->mNext = v39;
        v39->mPrev = v38;
        *v36 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v36;
        v36[1] = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v36;
      }
      v36[2] = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v37;
      if ( v37 )
      {
        v40 = *(UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> **)(v37 + 8);
        v40->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)v36;
        *v36 = v40;
        v36[1] = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)(v37 + 8);
        *(_QWORD *)(v37 + 8) = v36;
      }
      ++out->size;
      if ( v47 )
      {
        v41 = v45;
        v42 = v46;
        v45[1] = (__int64)v46;
        *v42 = v41;
        v45 = (__int64 *)&v45;
        v46 = &v45;
      }
      v47 = 0i64;
      v43 = v45;
      v44 = v46;
      v45[1] = (__int64)v46;
      *v44 = v43;
      v45 = (__int64 *)&v45;
      v46 = &v45;
    }
  }
}

// File Line: 265
// RVA: 0x4591A0
UFG::WallRunningRequest *__fastcall UFG::SensorComponent::BeginWallRunningTest(UFG::SensorComponent *this)
{
  UFG::allocator::free_link *v2; // rax
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v3; // rdx
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *mNext; // rcx

  if ( (this->m_Flags & 3) != 1 )
    return 0i64;
  v2 = UFG::qMalloc(0x30ui64, "WallRunningRequest", 0x800ui64);
  v3 = (UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *)v2;
  if ( v2 )
  {
    v2->mNext = v2;
    v2[1].mNext = v2;
    LODWORD(v2[2].mNext) = 0;
    HIDWORD(v2[2].mNext) = 1061158912;
    LODWORD(v2[3].mNext) = 1065353216;
    *(UFG::allocator::free_link **)((char *)&v2[3].mNext + 4) = (UFG::allocator::free_link *)1077936128;
    v2[5].mNext = 0i64;
  }
  else
  {
    v3 = 0i64;
  }
  mNext = this->mWallRunningRequests.mNode.mNext;
  this->mWallRunningRequests.mNode.mNext = v3;
  v3->mPrev = &this->mWallRunningRequests.mNode;
  v3->mNext = mNext;
  mNext->mPrev = v3;
  return (UFG::WallRunningRequest *)v3;
}

// File Line: 280
// RVA: 0x463E30
void __fastcall UFG::SensorComponent::EndWallRunningTest(UFG::SensorComponent *this, UFG::WallRunningRequest *request)
{
  request->queuedForDeletion = 1;
}

// File Line: 288
// RVA: 0x45A760
void __fastcall UFG::SensorComponent::CollectWallRunningInfo(UFG::SensorComponent *this)
{
  Render::DebugDrawContext *Context; // r12
  Render::DebugDrawContext *v3; // r13
  UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0> *mNext; // rbx
  UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0> *p_mLatchedWallRunningRequests; // rsi
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v6; // rcx
  UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0> *mPrev; // rdi
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v8; // rcx
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v9; // rdx
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v10; // rax
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v11; // rdi
  UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0> *p_mWallRunningRequests; // rax
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v13; // rbx
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v14; // rax
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v15; // rax
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v16; // rax
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v17; // rcx
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v18; // rdx
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v19; // rax
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v20; // rcx
  UFG::SimObject *m_pSimObject; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  float v25; // xmm0_4
  char v26; // r15
  char v27; // si
  __int64 v28; // rbx
  __int64 v29; // r14
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v30; // rcx
  const char *TypeName; // rax
  UFG::qReflectObject *mData; // rax
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v33; // rcx
  const char *v34; // rax
  __int64 v35; // rax
  float x; // xmm6_4
  float v37; // xmm7_4
  char v38; // al
  int v39; // ebx
  unsigned __int64 v40; // rsi
  __m128 v41; // xmm0
  float v42; // xmm2_4
  unsigned __int64 v43; // rbx
  float v44; // xmm8_4
  float v45; // xmm6_4
  UFG::ParkourQueryManager *v46; // rsi
  UFG::allocator::free_link *v47; // rax
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v48; // rax
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v49; // r8
  UFG::qList<UFG::ParkourHandle,UFG::ParkourHandle,1,0> *v50; // rdx
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v51; // rax
  UFG::qVector3 rayStart; // [rsp+40h] [rbp-80h] BYREF
  UFG::qVector3 rayEnd; // [rsp+50h] [rbp-70h] BYREF
  UFG::qVector3 _v0; // [rsp+60h] [rbp-60h] BYREF
  float v55; // [rsp+6Ch] [rbp-54h]
  UFG::qVector3 dest; // [rsp+70h] [rbp-50h] BYREF
  unsigned __int64 type_uid; // [rsp+88h] [rbp-38h]
  __int64 v58; // [rsp+98h] [rbp-28h]
  UFG::qReflectHandleBase v59; // [rsp+A0h] [rbp-20h] BYREF
  float v60; // [rsp+C8h] [rbp+8h]
  float v61; // [rsp+CCh] [rbp+Ch]
  int v62[8]; // [rsp+D0h] [rbp+10h]
  UFG::RayCastData data; // [rsp+F0h] [rbp+30h] BYREF
  __int64 v64; // [rsp+1D0h] [rbp+110h]
  UFG::SensorComponent *v65; // [rsp+2E0h] [rbp+220h]
  UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0> *i; // [rsp+2E8h] [rbp+228h]
  UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0> *j; // [rsp+2F0h] [rbp+230h]
  void *v68; // [rsp+2F8h] [rbp+238h]

  v64 = -2i64;
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v3 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  mNext = (UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0> *)this->mLatchedWallRunningRequests.mNode.mNext;
  p_mLatchedWallRunningRequests = &this->mLatchedWallRunningRequests;
  for ( i = &this->mLatchedWallRunningRequests;
        mNext != p_mLatchedWallRunningRequests;
        mNext = (UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0> *)mNext->mNode.mNext )
  {
    v6 = mNext[2].mNode.mNext;
    if ( !v6 || ((__int64)v6[9].mNext & 1) == 0 )
    {
      mPrev = (UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0> *)mNext->mNode.mPrev;
      j = mNext;
      v8 = mNext[2].mNode.mNext;
      if ( v8 )
        ((void (__fastcall *)(UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *, __int64))v8->mPrev->mPrev)(
          v8,
          1i64);
      v9 = mNext->mNode.mPrev;
      v10 = mNext->mNode.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      mNext->mNode.mPrev = &mNext->mNode;
      mNext->mNode.mNext = &mNext->mNode;
      operator delete[](mNext);
      mNext = mPrev;
    }
  }
  v11 = this->mWallRunningRequests.mNode.mNext;
  p_mWallRunningRequests = &this->mWallRunningRequests;
  for ( j = &this->mWallRunningRequests;
        v11 != (UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *)p_mWallRunningRequests;
        v11 = v11->mNext )
  {
    if ( LODWORD(v11[2].mPrev) )
    {
      v13 = v11->mPrev;
      v14 = v11->mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      v11->mPrev = v11;
      v11->mNext = v11;
      v15 = v11[2].mNext;
      if ( v15 && ((__int64)v15[9].mNext & 1) != 0 )
      {
        v16 = p_mLatchedWallRunningRequests->mNode.mPrev;
        v16->mNext = v11;
        v11->mPrev = v16;
        v11->mNext = &p_mLatchedWallRunningRequests->mNode;
        p_mLatchedWallRunningRequests->mNode.mPrev = v11;
      }
      else
      {
        v68 = v11;
        v17 = v11[2].mNext;
        if ( v17 )
          ((void (__fastcall *)(UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *, __int64))v17->mPrev->mPrev)(
            v17,
            1i64);
        v18 = v11->mPrev;
        v19 = v11->mNext;
        v18->mNext = v19;
        v19->mPrev = v18;
        v11->mPrev = v11;
        v11->mNext = v11;
        operator delete[](v11);
      }
      v11 = v13;
      p_mWallRunningRequests = &this->mWallRunningRequests;
    }
    else
    {
      v20 = v11[2].mNext;
      if ( v20 && ((__int64)v20[9].mNext & 1) == 0 )
      {
        ((void (__fastcall *)(UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *, __int64))v20->mPrev->mPrev)(
          v20,
          1i64);
        v11[2].mNext = 0i64;
        p_mWallRunningRequests = &this->mWallRunningRequests;
      }
      if ( !v11[2].mNext )
      {
        m_pSimObject = this->m_pSimObject;
        if ( m_pSimObject )
          m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
        else
          m_pTransformNodeComponent = 0i64;
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        y = m_pTransformNodeComponent->mWorldTransform.v3.y;
        z = m_pTransformNodeComponent->mWorldTransform.v3.z;
        rayStart.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
        rayStart.y = y;
        rayStart.z = z + *((float *)&v11[1].mPrev + 1);
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        UFG::qRotateVectorZ(
          &dest,
          (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform,
          *(float *)&v11[1].mPrev);
        v25 = *((float *)&v11[1].mNext + 1);
        rayEnd.x = (float)(dest.x * v25) + rayStart.x;
        rayEnd.y = rayStart.y + (float)(dest.y * v25);
        rayEnd.z = (float)(dest.z * v25) + rayStart.z;
        v26 = 1;
        v27 = 0;
        v28 = 0i64;
        v29 = 0i64;
        do
        {
          if ( !v26 )
          {
            this = v65;
            p_mWallRunningRequests = j;
            goto LABEL_70;
          }
          v26 = 0;
          data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
          data.mInput.m_filterInfo = 0;
          data.mInput.m_userData = 0i64;
          data.mOutput.m_hitFraction = 1.0;
          data.mOutput.m_extraInfo = -1;
          data.mOutput.m_shapeKeyIndex = 0;
          data.mOutput.m_shapeKeys[0] = -1;
          data.mOutput.m_rootCollidable = 0i64;
          data.mDebugName = "WallRunProbe";
          data.mCollisionModelName.mUID = -1;
          UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0xCu);
          if ( UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
          {
            if ( data.mPhysicsObjectPropertyHandleUid )
            {
              UFG::qReflectHandleBase::qReflectHandleBase(&v59);
              TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v30);
              v59.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
              UFG::qReflectHandleBase::Init(&v59, v59.mTypeUID, data.mPhysicsObjectPropertyHandleUid);
              mData = v59.mData;
              if ( !v59.mData )
              {
                UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v59);
                mData = v59.mData;
              }
              if ( BYTE5(mData[1].mTypeUID) )
              {
                if ( gDrawSensor )
                  Render::DebugDrawContext::DrawText(
                    Context,
                    &data.point,
                    &UFG::qColour::White,
                    "disabled by object tag");
                v27 = 1;
              }
              UFG::qReflectHandleBase::~qReflectHandleBase(&v59);
            }
            if ( data.mPhysicsSurfacePropertyHandleUid )
            {
              UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&dest.z);
              v34 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v33);
              type_uid = UFG::qStringHash64(v34, 0xFFFFFFFFFFFFFFFFui64);
              UFG::qReflectHandleBase::Init(
                (UFG::qReflectHandleBase *)&dest.z,
                type_uid,
                data.mPhysicsSurfacePropertyHandleUid);
              v35 = v58;
              if ( !v58 )
              {
                UFG::PhysicsPropertyManager::GetDefaultSurfaceProperties((UFG::qReflectHandle<UFG::PhysicsSurfaceProperties> *)&dest.z);
                v35 = v58;
              }
              if ( *(_BYTE *)(v35 + 96) )
              {
                if ( gDrawSensor )
                  Render::DebugDrawContext::DrawText(
                    Context,
                    &data.point,
                    &UFG::qColour::White,
                    "disabled by surface tag");
                v27 = 1;
              }
              UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&dest.z);
            }
            if ( !v27 )
            {
              v26 = 1;
              *(float *)((char *)&rayStart.x + v28 * 4) = data.point.x;
              *(float *)((char *)&rayStart.y + v28 * 4) = data.point.y;
              *(float *)((char *)&rayStart.z + v28 * 4) = data.point.z;
              *(float *)((char *)&v60 + v28 * 4) = data.normal.x;
              *(float *)&v62[v28 - 1] = data.normal.y;
              v62[v28] = LODWORD(data.normal.z);
            }
          }
          if ( gDrawSensor )
          {
            if ( data.hit )
            {
              Render::DebugDrawContext::DrawLine(
                v3,
                &rayStart,
                &data.point,
                &UFG::qColour::Green,
                &UFG::qMatrix44::msIdentity,
                0i64,
                0);
              Render::DebugDrawContext::DrawSphere(
                v3,
                &data.point,
                0.1,
                &UFG::qColour::Green,
                &UFG::qMatrix44::msIdentity,
                0i64);
            }
            else
            {
              Render::DebugDrawContext::DrawLine(
                v3,
                &rayStart,
                &rayEnd,
                &UFG::qColour::Red,
                &UFG::qMatrix44::msIdentity,
                0i64,
                0);
            }
          }
          rayStart.z = rayStart.z + *(float *)&v11[1].mNext;
          rayEnd.z = rayEnd.z + *(float *)&v11[1].mNext;
          v28 += 3i64;
          v29 += 8i64;
        }
        while ( v28 < 9 );
        if ( v26 )
        {
          x = rayStart.x;
          v37 = rayStart.y;
          v38 = 1;
          v39 = 0;
          v40 = 0i64;
          while ( v38 )
          {
            if ( COERCE_FLOAT(v62[v40 / 4] & _xmm) > 0.0099999998 )
            {
              if ( gDrawSensor )
                Render::DebugDrawContext::DrawText(Context, &rayStart + v39, &UFG::qColour::White, "not vertical");
              v38 = 0;
            }
            v41 = (__m128)*(unsigned int *)((char *)&rayStart.x + v40);
            v41.m128_f32[0] = (float)((float)(v41.m128_f32[0] - x) * (float)(v41.m128_f32[0] - x))
                            + (float)((float)(*(float *)((char *)&rayStart.y + v40) - v37)
                                    * (float)(*(float *)((char *)&rayStart.y + v40) - v37));
            v42 = _mm_sqrt_ps(v41).m128_f32[0];
            if ( v42 > 0.050000001 )
            {
              if ( gDrawSensor )
                Render::DebugDrawContext::DrawText(Context, &rayStart + v39, &UFG::qColour::White, "not smooth %f", v42);
              v38 = 0;
            }
            ++v39;
            v40 += 12i64;
            if ( v39 >= 3 )
            {
              this = v65;
              if ( !v38 )
                goto LABEL_69;
              v43 = (unsigned int)v11 | ((_QWORD)v65 << 32);
              v44 = (float)(v60 - (float)(*(float *)v62 * 0.0)) * 0.5;
              v45 = (float)((float)(*(float *)v62 * 0.0) - v61) * 0.5;
              _v0.x = rayStart.x - v45;
              _v0.y = rayStart.y - v44;
              _v0.z = rayStart.x + v45;
              v55 = rayStart.y + v44;
              dest.x = rayStart.z + (float)((float)((float)(v61 * 0.0) - (float)(v60 * 0.0)) * 0.5);
              v46 = UFG::ParkourQueryManager::mInstance;
              v47 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0xA0ui64, "ParkourHandle", 0i64, 1u);
              v68 = v47;
              if ( v47 )
              {
                UFG::ParkourHandle::ParkourHandle(
                  (UFG::ParkourHandle *)v47,
                  (unsigned int)v11 | ((_QWORD)this << 32),
                  &_v0,
                  (UFG::qVector3 *)&_v0.z,
                  0x810u);
                v49 = v48;
              }
              else
              {
                v49 = 0i64;
              }
              v50 = &v46->mActiveHandles[v43 % 0x101];
              v51 = (UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *)v50->mNode.mPrev;
              v51->mNext = (UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *)((char *)v49 + 24);
              v49[1].mNext = v51;
              v49[2].mPrev = (UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *)v50;
              v50->mNode.mPrev = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)&v49[1].mNext;
              v11[2].mNext = v49;
              p_mWallRunningRequests = &this->mWallRunningRequests;
              goto LABEL_70;
            }
          }
        }
        this = v65;
LABEL_69:
        p_mWallRunningRequests = j;
LABEL_70:
        p_mLatchedWallRunningRequests = i;
      }
    }
  }
}

// File Line: 489
// RVA: 0x45A260
char __fastcall UFG::SensorComponent::CastSphere(
        UFG::SensorComponent *this,
        UFG::qMatrix44 *transform,
        float radius,
        unsigned int collisionFilter,
        UFG::qVector3 *start,
        UFG::qVector3 *end,
        UFG::SimObject *trueIfHits)
{
  UFG::ShapeCasterCollector *mSphereCaster; // rcx
  UFG::ShapeCasterCollector *v11; // rcx
  UFG::allocator::free_link *v12; // rax
  UFG::ShapeCasterCollector *v13; // rax
  float x; // xmm2_4
  float y; // xmm3_4
  float z; // xmm5_4
  float v18; // xmm12_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  float v22; // xmm13_4
  UFG::ShapeCasterCollector *v23; // rax
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *mNext; // rcx
  UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *p_mHitList; // rax
  UFG::qVector3 v27; // [rsp+38h] [rbp-C0h] BYREF
  UFG::qVector3 v28; // [rsp+44h] [rbp-B4h] BYREF
  float starta; // [rsp+120h] [rbp+28h]
  float enda; // [rsp+128h] [rbp+30h]

  mSphereCaster = this->mSphereCaster;
  if ( mSphereCaster
    && (mSphereCaster->mRadius != radius
     || (unsigned int)UFG::ShapeCasterCollector::GetCollisionFilter(mSphereCaster) != collisionFilter) )
  {
    v11 = this->mSphereCaster;
    if ( v11 )
      v11->vfptr->__vecDelDtor(v11, 1u);
    this->mSphereCaster = 0i64;
  }
  if ( !this->mSphereCaster )
  {
    v12 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x30ui64, "SphereCaster", 0i64, 1u);
    if ( v12 )
      UFG::ShapeCasterCollector::ShapeCasterCollector(
        (UFG::ShapeCasterCollector *)v12,
        radius,
        collisionFilter,
        PhantomBehaviour_Simple);
    else
      v13 = 0i64;
    this->mSphereCaster = v13;
  }
  x = start->x;
  y = start->y;
  z = start->z;
  starta = (float)((float)((float)(transform->v0.x * start->x) + (float)(transform->v1.x * y))
                 + (float)(transform->v2.x * z))
         + transform->v3.x;
  enda = (float)((float)((float)(transform->v0.y * x) + (float)(transform->v1.y * y)) + (float)(transform->v2.y * z))
       + transform->v3.y;
  v18 = (float)((float)((float)(transform->v0.z * x) + (float)(transform->v1.z * y)) + (float)(transform->v2.z * z))
      + transform->v3.z;
  v19 = end->y;
  v20 = end->z;
  v21 = (float)((float)((float)(transform->v0.y * end->x) + (float)(transform->v1.y * v19))
              + (float)(transform->v2.y * v20))
      + transform->v3.y;
  v22 = (float)((float)((float)(transform->v0.z * end->x) + (float)(transform->v1.z * v19))
              + (float)(transform->v2.z * v20))
      + transform->v3.z;
  v27.x = (float)((float)((float)(transform->v0.x * end->x) + (float)(transform->v1.x * v19))
                + (float)(transform->v2.x * v20))
        + transform->v3.x;
  v27.y = v21;
  v27.z = v22;
  v28.x = starta;
  v28.y = enda;
  v28.z = v18;
  if ( UFG::BasePhysicsSystem::CastShape(UFG::BasePhysicsSystem::mInstance, this->mSphereCaster, &v28, &v27) )
  {
    if ( !trueIfHits )
      return 1;
    v23 = this->mSphereCaster;
    mNext = v23->mHitList.mNode.mNext;
    p_mHitList = &v23->mHitList;
    if ( mNext != (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)p_mHitList )
    {
      while ( (UFG::SimObject *)mNext[5].mPrev != trueIfHits )
      {
        mNext = mNext->mNext;
        if ( mNext == (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)p_mHitList )
          return 0;
      }
      return 1;
    }
  }
  return 0;
}


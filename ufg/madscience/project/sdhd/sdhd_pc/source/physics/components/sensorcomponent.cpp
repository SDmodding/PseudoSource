// File Line: 54
// RVA: 0x15143D0
__int64 dynamic_initializer_for__UFG::SensorComponent::s_SensorComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::SensorComponent::s_SensorComponentList__);
}

// File Line: 55
// RVA: 0x466460
UFG::ComponentIDDesc *__fastcall UFG::SensorComponent::GetDesc(UFG::SensorComponent *this)
{
  return &UFG::SensorComponent::_TypeIDesc;
}

// File Line: 66
// RVA: 0x44D4D0
void __fastcall UFG::SensorComponent::SensorComponent(UFG::SensorComponent *this, unsigned int name_uid, component_Sensor *dataPtr)
{
  component_Sensor *v3; // rdi
  UFG::SensorComponent *v4; // rbx
  UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *v5; // rdx
  UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *v6; // rax
  __m128 v7; // xmm7
  __m128 v8; // xmm4
  __m128 v9; // xmm6
  __m128 v10; // xmm2
  __m128 v11; // xmm5
  __m128 v12; // xmm3
  UFG::allocator::free_link *v13; // rax
  UFG::SensorPhantom *v14; // rax
  UFG::allocator::free_link *v15; // rax
  hkAabb aabb; // [rsp+40h] [rbp-48h]
  UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0> *v17; // [rsp+A0h] [rbp+18h]
  UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0> *v18; // [rsp+A0h] [rbp+18h]

  v3 = dataPtr;
  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v5 = (UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SensorComponent::`vftable';
  v17 = &v4->mWallRunningRequests;
  v17->mNode.mPrev = &v17->mNode;
  v17->mNode.mNext = &v17->mNode;
  v18 = &v4->mLatchedWallRunningRequests;
  v18->mNode.mPrev = &v18->mNode;
  v18->mNode.mNext = &v18->mNode;
  v4->mSphereCaster = 0i64;
  v4->mActiveRegion = 0i64;
  v4->mSensorPhantomSizeX = 3.0999999;
  v4->mSensorPhantomSizeY = 3.0999999;
  v4->mSensorPhantomSizeZ = 3.0999999;
  v6 = UFG::SensorComponent::s_SensorComponentList.mNode.mPrev;
  UFG::SensorComponent::s_SensorComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *)&v4->mPrev;
  v5->mPrev = v6;
  v4->mNext = (UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *)&UFG::SensorComponent::s_SensorComponentList;
  UFG::SensorComponent::s_SensorComponentList.mNode.mPrev = (UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::SensorComponent::_SensorComponentTypeUID,
    "SensorComponent");
  if ( v3 )
    UFG::SensorComponent::PropertiesLoad(v4, v3);
  v7 = (__m128)LODWORD(v4->mSensorPhantomSizeZ);
  v8 = (__m128)LODWORD(v4->mSensorPhantomSizeZ);
  v8.m128_f32[0] = v8.m128_f32[0] * -0.5;
  v9 = (__m128)LODWORD(v4->mSensorPhantomSizeY);
  v10 = (__m128)LODWORD(v4->mSensorPhantomSizeY);
  v10.m128_f32[0] = v10.m128_f32[0] * -0.5;
  v11 = (__m128)LODWORD(v4->mSensorPhantomSizeX);
  v12 = (__m128)LODWORD(v4->mSensorPhantomSizeX);
  v12.m128_f32[0] = v12.m128_f32[0] * -0.5;
  aabb.m_min.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v12, v8), _mm_unpacklo_ps(v10, (__m128)0i64));
  v7.m128_f32[0] = v7.m128_f32[0] * 0.5;
  v9.m128_f32[0] = v9.m128_f32[0] * 0.5;
  v11.m128_f32[0] = v11.m128_f32[0] * 0.5;
  aabb.m_max.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v11, v7), _mm_unpacklo_ps(v9, (__m128)0i64));
  v13 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x18ui64, "SensorPhantom", 0i64, 1u);
  if ( v13 )
    UFG::SensorPhantom::SensorPhantom((UFG::SensorPhantom *)v13, &aabb, 0x1Du, "SensorComponent");
  else
    v14 = 0i64;
  v4->mSensor = v14;
  once_3 = 0;
  v15 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
  if ( v15 )
  {
    v15->mNext = v15;
    v15[1].mNext = v15;
    v15[8].mNext = 0i64;
    v15[7].mNext = 0i64;
  }
  else
  {
    v15 = 0i64;
  }
  v4->mParkourQuery = (UFG::ParkourQuery *)v15;
}

// File Line: 98
// RVA: 0x470AC0
void __fastcall UFG::SensorComponent::PropertiesLoad(UFG::SensorComponent *this, component_Sensor *dataPtr)
{
  UFG::SensorComponent *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  UFG::ActiveRegion *v4; // rax
  UFG::ActiveRegion *v5; // rdx
  UFG::ActiveRegionManager *v6; // rcx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v7; // rax
  hkVector4f centre; // [rsp+30h] [rbp-28h]
  hkVector4f extents; // [rsp+40h] [rbp-18h]

  v2 = this;
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
    v2->mActiveRegion = v5;
    v6 = &UFG::BasePhysicsSystem::mInstance->mActiveRegionManager;
    v7 = UFG::BasePhysicsSystem::mInstance->mActiveRegionManager.mRegions.mNode.mPrev;
    v7->mNext = (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *)&v5->mPrev;
    v5->mPrev = v7;
    v5->mNext = &v6->mRegions.mNode;
    v6->mRegions.mNode.mPrev = (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *)&v5->mPrev;
  }
}

// File Line: 115
// RVA: 0x4710F0
UFG::SimComponent *__fastcall UFG::SensorComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *sceneObject, bool required)
{
  bool v2; // bp
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *v7; // rdi
  UFG::allocator::free_link *v9; // rax
  UFG::SimComponent *v10; // rax
  UFG::SimObject *v11; // rdx
  unsigned __int16 v12; // cx
  unsigned int v13; // ebx
  UFG::SimObjectModifier v14; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = sceneObject;
  v4 = sceneObject->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_Sensor::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    v7 = UFG::qPropertySet::GetMemImagePtr(v5);
  else
    v7 = 0i64;
  if ( !v2 && !v7 )
    return 0i64;
  v9 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0xA0ui64, "SensorComponent", 0i64, 1u);
  if ( v9 )
  {
    UFG::SensorComponent::SensorComponent((UFG::SensorComponent *)v9, v3->m_NameUID, (component_Sensor *)v7);
    v6 = v10;
  }
  v11 = v3->m_pSimObject;
  v12 = v11->m_Flags;
  if ( (v12 >> 14) & 1 || (v12 & 0x8000u) != 0 )
    v13 = 26;
  else
    v13 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v14, v11, 1);
  UFG::SimObjectModifier::AttachComponent(&v14, v6, v13);
  UFG::SimObjectModifier::Close(&v14);
  UFG::SimObjectModifier::~SimObjectModifier(&v14);
  return v6;
}

// File Line: 137
// RVA: 0x451130
void __fastcall UFG::SensorComponent::~SensorComponent(UFG::SensorComponent *this)
{
  UFG::SensorComponent *v1; // rdi
  UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *v2; // rsi
  UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *v3; // rcx
  UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *v4; // rax
  UFG::ActiveRegion *v5; // rdx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v6; // rcx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v7; // rax
  UFG::ActiveRegion *v8; // rcx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v9; // rdx
  UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *v10; // rax
  UFG::SensorPhantom *v11; // rcx
  UFG::ShapeCasterCollector *v12; // rcx
  UFG::ParkourQuery *v13; // rbx
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v14; // rcx
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v15; // rax
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v16; // rcx
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v17; // rax
  UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *v18; // rcx
  UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *v19; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SensorComponent::`vftable';
  if ( this == UFG::SensorComponent::s_SensorComponentpCurrentIterator )
    UFG::SensorComponent::s_SensorComponentpCurrentIterator = (UFG::SensorComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v1->mActiveRegion;
  if ( v5 )
  {
    v6 = v5->mPrev;
    v7 = v5->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *)&v5->mPrev;
    v5->mNext = (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *)&v5->mPrev;
    v8 = v1->mActiveRegion;
    if ( v8 )
    {
      v9 = v8->mPrev;
      v10 = v8->mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *)&v8->mPrev;
      v8->mNext = (UFG::qNode<UFG::ActiveRegion,UFG::ActiveRegion> *)&v8->mPrev;
      operator delete[](v8);
    }
  }
  v11 = v1->mSensor;
  if ( v11 )
    v11->vfptr->__vecDelDtor(v11, 1u);
  v12 = v1->mSphereCaster;
  if ( v12 )
    v12->vfptr->__vecDelDtor(v12, 1u);
  v13 = v1->mParkourQuery;
  if ( v13 )
  {
    UFG::ParkourQuery::~ParkourQuery(v1->mParkourQuery);
    operator delete[](v13);
  }
  UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0>::DeleteNodes(&v1->mLatchedWallRunningRequests);
  v14 = v1->mLatchedWallRunningRequests.mNode.mPrev;
  v15 = v1->mLatchedWallRunningRequests.mNode.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v1->mLatchedWallRunningRequests.mNode.mPrev = &v1->mLatchedWallRunningRequests.mNode;
  v1->mLatchedWallRunningRequests.mNode.mNext = &v1->mLatchedWallRunningRequests.mNode;
  UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0>::DeleteNodes(&v1->mWallRunningRequests);
  v16 = v1->mWallRunningRequests.mNode.mPrev;
  v17 = v1->mWallRunningRequests.mNode.mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  v1->mWallRunningRequests.mNode.mPrev = &v1->mWallRunningRequests.mNode;
  v1->mWallRunningRequests.mNode.mNext = &v1->mWallRunningRequests.mNode;
  v18 = v2->mPrev;
  v19 = v2->mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 154
// RVA: 0x47D2F0
void __fastcall UFG::SensorComponent::Update(UFG::SensorComponent *this, float delta_sec)
{
  UFG::SimObject *v2; // rdi
  UFG::SensorComponent *v3; // rbx
  UFG::TransformNodeComponent *v4; // rsi
  UFG::SensorPhantom *v5; // rcx
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  UFG::ParkourQuery *v18; // rax
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  UFG::ActiveRegion *v22; // rcx
  UFG::ParkourQuery *v23; // rcx
  UFG::qList<UFG::ParkourQuery,UFG::ParkourQuery,1,0> *v24; // rdx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *v25; // rax
  hkVector4f centre; // [rsp+20h] [rbp-50h]
  UFG::qMatrix44 transform; // [rsp+30h] [rbp-40h]

  v2 = this->m_pSimObject;
  v3 = this;
  if ( !v2 || !((v2->m_Flags >> 10) & 1) )
  {
    if ( v2 )
      v4 = v2->m_pTransformNodeComponent;
    else
      v4 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v4);
    v5 = v3->mSensor;
    v6 = v4->mWorldTransform.v0.z;
    v7 = v4->mWorldTransform.v0.w;
    v8 = v4->mWorldTransform.v0.x;
    transform.v0.y = v4->mWorldTransform.v0.y;
    transform.v0.z = v6;
    transform.v0.x = v8;
    transform.v0.w = v7;
    v9 = v4->mWorldTransform.v1.y;
    v10 = v4->mWorldTransform.v1.z;
    v11 = v4->mWorldTransform.v1.w;
    transform.v1.x = v4->mWorldTransform.v1.x;
    transform.v1.y = v9;
    transform.v1.z = v10;
    transform.v1.w = v11;
    v12 = v4->mWorldTransform.v2.z;
    v13 = v4->mWorldTransform.v2.w;
    v14 = v4->mWorldTransform.v2.x;
    transform.v2.y = v4->mWorldTransform.v2.y;
    transform.v2.x = v14;
    transform.v2.z = v12;
    transform.v2.w = v13;
    v15 = v4->mWorldTransform.v3.z;
    v16 = v4->mWorldTransform.v3.w;
    v17 = v4->mWorldTransform.v3.x;
    transform.v3.y = v4->mWorldTransform.v3.y;
    transform.v3.z = v15;
    transform.v3.x = v17;
    transform.v3.w = v16;
    UFG::SensorPhantom::SetTransform(v5, &transform);
    v18 = v3->mParkourQuery;
    if ( v18 )
    {
      v19 = transform.v3.z;
      v20 = transform.v3.w;
      v21 = transform.v3.x;
      v18->mCentre.y = transform.v3.y;
      v18->mCentre.z = v19;
      v18->mCentre.x = v21;
      v18->mCentre.w = v20;
    }
    v22 = v3->mActiveRegion;
    if ( v22 )
    {
      centre.m_quad = _mm_unpacklo_ps(
                        _mm_unpacklo_ps((__m128)LODWORD(transform.v3.x), (__m128)LODWORD(transform.v3.z)),
                        _mm_unpacklo_ps((__m128)LODWORD(transform.v3.y), (__m128)LODWORD(transform.v3.w)));
      UFG::ActiveRegion::SetCentre(v22, &centre);
    }
    UFG::SensorComponent::CollectWallRunningInfo(v3);
    if ( (v2->m_Flags >> 14) & 1 )
    {
      v3->mParkourQuery->handlesOut.size = 0;
      v3->mParkourQuery->userData = v3;
      v3->mParkourQuery->callback = 0i64;
      v3->mParkourQuery->mRadius = 4.5;
      v23 = v3->mParkourQuery;
      v24 = &UFG::ParkourQueryManager::mInstance->mQueries;
      v25 = UFG::ParkourQueryManager::mInstance->mQueries.mNode.mPrev;
      v25->mNext = (UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *)&v23->mPrev;
      v23->mPrev = v25;
      v23->mNext = &v24->mNode;
      v24->mNode.mPrev = (UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *)&v23->mPrev;
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
  UFG::ParkourQuery *v2; // rcx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *v3; // rdx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *v4; // rax

  this->mParkourQuery->handlesOut.size = 0;
  this->mParkourQuery->userData = this;
  this->mParkourQuery->callback = 0i64;
  this->mParkourQuery->mRadius = queryRadius;
  v2 = this->mParkourQuery;
  v3 = &UFG::ParkourQueryManager::mInstance->mQueries.mNode;
  v4 = UFG::ParkourQueryManager::mInstance->mQueries.mNode.mPrev;
  v4->mNext = (UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *)&v2->mPrev;
  v2->mPrev = v4;
  v2->mNext = v3;
  v3->mPrev = (UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *)&v2->mPrev;
}

// File Line: 235
// RVA: 0x466C80
void __fastcall UFG::SensorComponent::GetParkourHandles(UFG::SensorComponent *this, UFG::qFixedArray<UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle>,768> *out)
{
  UFG::qFixedArray<UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle>,768> *v2; // r8
  UFG::SensorComponent *v3; // rbx
  unsigned int v4; // er10
  UFG::ParkourQuery *v5; // rdx
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v6; // rax
  __int64 v7; // rcx
  __int64 **v8; // rcx
  __int64 *v9; // rax
  unsigned int *v10; // rdx
  __int64 v11; // r9
  __int64 v12; // rcx
  _QWORD *v13; // rax
  __int64 v14; // rax
  __int64 *v15; // rcx
  __int64 **v16; // rax
  __int64 *v17; // rcx
  __int64 **v18; // rax
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *i; // r9
  __int64 v20; // rcx
  __int64 **v21; // rcx
  __int64 *v22; // rax
  unsigned int *v23; // rdx
  __int64 v24; // r10
  __int64 v25; // rcx
  _QWORD *v26; // rax
  __int64 v27; // rax
  __int64 *v28; // rcx
  __int64 **v29; // rax
  __int64 *v30; // rcx
  __int64 **v31; // rax
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *j; // r9
  __int64 v33; // rcx
  __int64 **v34; // rcx
  __int64 *v35; // rax
  unsigned int *v36; // rdx
  __int64 v37; // r10
  __int64 v38; // rcx
  _QWORD *v39; // rax
  __int64 v40; // rax
  __int64 *v41; // rcx
  __int64 **v42; // rax
  __int64 *v43; // rcx
  __int64 **v44; // rax
  __int64 *v45; // [rsp+8h] [rbp-18h]
  __int64 **v46; // [rsp+10h] [rbp-10h]
  __int64 v47; // [rsp+18h] [rbp-8h]

  v2 = out;
  v3 = this;
  v4 = 0;
  v5 = this->mParkourQuery;
  if ( v5->handlesOut.size )
  {
    do
    {
      v6 = v5->handlesOut.p;
      v45 = (__int64 *)&v45;
      v46 = &v45;
      v7 = (__int64)v6[v4].m_pPointer;
      v47 = v7;
      if ( v7 )
      {
        v8 = (__int64 **)(v7 + 8);
        v9 = *v8;
        v9[1] = (__int64)&v45;
        v45 = v9;
        v46 = v8;
        *v8 = (__int64 *)&v45;
      }
      v10 = &v2->size + 2 * (v2->size + 2i64 * v2->size + 1);
      v11 = v47;
      if ( *((_QWORD *)v10 + 2) )
      {
        v12 = *(_QWORD *)v10;
        v13 = (_QWORD *)*((_QWORD *)v10 + 1);
        *(_QWORD *)(v12 + 8) = v13;
        *v13 = v12;
        *(_QWORD *)v10 = v10;
        *((_QWORD *)v10 + 1) = v10;
      }
      *((_QWORD *)v10 + 2) = v11;
      if ( v11 )
      {
        v14 = *(_QWORD *)(v11 + 8);
        *(_QWORD *)(v14 + 8) = v10;
        *(_QWORD *)v10 = v14;
        *((_QWORD *)v10 + 1) = v11 + 8;
        *(_QWORD *)(v11 + 8) = v10;
      }
      ++v2->size;
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
      v5 = v3->mParkourQuery;
    }
    while ( v4 < v5->handlesOut.size );
  }
  for ( i = v3->mWallRunningRequests.mNode.mNext;
        i != (UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *)&v3->mWallRunningRequests;
        i = i->mNext )
  {
    v20 = (__int64)i[2].mNext;
    if ( v20 )
    {
      v45 = (__int64 *)&v45;
      v46 = &v45;
      v47 = v20;
      v21 = (__int64 **)(v20 + 8);
      v22 = *v21;
      v22[1] = (__int64)&v45;
      v45 = v22;
      v46 = v21;
      *v21 = (__int64 *)&v45;
      v23 = &v2->size + 2 * (v2->size + 2i64 * v2->size + 1);
      v24 = v47;
      if ( *((_QWORD *)v23 + 2) )
      {
        v25 = *(_QWORD *)v23;
        v26 = (_QWORD *)*((_QWORD *)v23 + 1);
        *(_QWORD *)(v25 + 8) = v26;
        *v26 = v25;
        *(_QWORD *)v23 = v23;
        *((_QWORD *)v23 + 1) = v23;
      }
      *((_QWORD *)v23 + 2) = v24;
      if ( v24 )
      {
        v27 = *(_QWORD *)(v24 + 8);
        *(_QWORD *)(v27 + 8) = v23;
        *(_QWORD *)v23 = v27;
        *((_QWORD *)v23 + 1) = v24 + 8;
        *(_QWORD *)(v24 + 8) = v23;
      }
      ++v2->size;
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
  for ( j = v3->mLatchedWallRunningRequests.mNode.mNext;
        j != (UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *)&v3->mLatchedWallRunningRequests;
        j = j->mNext )
  {
    v33 = (__int64)j[2].mNext;
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
      v36 = &v2->size + 2 * (v2->size + 2i64 * v2->size + 1);
      v37 = v47;
      if ( *((_QWORD *)v36 + 2) )
      {
        v38 = *(_QWORD *)v36;
        v39 = (_QWORD *)*((_QWORD *)v36 + 1);
        *(_QWORD *)(v38 + 8) = v39;
        *v39 = v38;
        *(_QWORD *)v36 = v36;
        *((_QWORD *)v36 + 1) = v36;
      }
      *((_QWORD *)v36 + 2) = v37;
      if ( v37 )
      {
        v40 = *(_QWORD *)(v37 + 8);
        *(_QWORD *)(v40 + 8) = v36;
        *(_QWORD *)v36 = v40;
        *((_QWORD *)v36 + 1) = v37 + 8;
        *(_QWORD *)(v37 + 8) = v36;
      }
      ++v2->size;
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
UFG::allocator::free_link *__fastcall UFG::SensorComponent::BeginWallRunningTest(UFG::SensorComponent *this)
{
  UFG::SensorComponent *v1; // rbx
  UFG::allocator::free_link *v2; // rax
  UFG::allocator::free_link *v3; // rdx
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v4; // rcx

  v1 = this;
  if ( (this->m_Flags & 3) != 1 )
    return 0i64;
  v2 = UFG::qMalloc(0x30ui64, "WallRunningRequest", 0x800ui64);
  v3 = v2;
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
  v4 = v1->mWallRunningRequests.mNode.mNext;
  v1->mWallRunningRequests.mNode.mNext = (UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *)v3;
  v3->mNext = (UFG::allocator::free_link *)&v1->mWallRunningRequests;
  v3[1].mNext = (UFG::allocator::free_link *)v4;
  v4->mPrev = (UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *)v3;
  return v3;
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
  UFG::SensorComponent *v1; // r14
  Render::DebugDrawContext *v2; // r12
  Render::DebugDrawContext *v3; // r13
  UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0> *v4; // rbx
  UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0> *v5; // rsi
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v6; // rcx
  UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0> *v7; // rdi
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v8; // rcx
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v9; // rdx
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v10; // rax
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v11; // rdi
  signed __int64 v12; // rax
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v13; // rbx
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v14; // rax
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v15; // rax
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v16; // rax
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v17; // rcx
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v18; // rdx
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v19; // rax
  UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *v20; // rcx
  UFG::SimObject *v21; // rbx
  UFG::TransformNodeComponent *v22; // rbx
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm0_4
  char v26; // r15
  char v27; // si
  signed __int64 v28; // rbx
  __int64 v29; // r14
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v30; // rcx
  const char *v31; // rax
  UFG::qReflectObject *v32; // rax
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v33; // rcx
  const char *v34; // rax
  __int64 v35; // rax
  float v36; // xmm6_4
  float v37; // xmm7_4
  char v38; // al
  signed int v39; // ebx
  unsigned __int64 v40; // rsi
  __m128 v41; // xmm0
  float v42; // xmm2_4
  float v43; // xmm8_4
  float v44; // xmm6_4
  UFG::ParkourQueryManager *v45; // rsi
  UFG::allocator::free_link *v46; // rax
  __int64 v47; // rax
  __int64 v48; // r8
  UFG::qList<UFG::ParkourHandle,UFG::ParkourHandle,1,0> *v49; // rdx
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> **v50; // rcx
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v51; // rax
  UFG::qVector3 rayStart; // [rsp+40h] [rbp-80h]
  UFG::qVector3 rayEnd; // [rsp+50h] [rbp-70h]
  UFG::qVector3 _v0; // [rsp+60h] [rbp-60h]
  float v55; // [rsp+6Ch] [rbp-54h]
  UFG::qVector3 dest; // [rsp+70h] [rbp-50h]
  unsigned __int64 type_uid; // [rsp+88h] [rbp-38h]
  __int64 v58; // [rsp+98h] [rbp-28h]
  UFG::qReflectHandleBase v59; // [rsp+A0h] [rbp-20h]
  float v60; // [rsp+C8h] [rbp+8h]
  float v61; // [rsp+CCh] [rbp+Ch]
  int v62[8]; // [rsp+D0h] [rbp+10h]
  UFG::RayCastData data; // [rsp+F0h] [rbp+30h]
  __int64 v64; // [rsp+1D0h] [rbp+110h]
  UFG::SensorComponent *v65; // [rsp+2E0h] [rbp+220h]
  UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0> *v66; // [rsp+2E8h] [rbp+228h]
  UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0> *i; // [rsp+2F0h] [rbp+230h]
  UFG::allocator::free_link *v68; // [rsp+2F8h] [rbp+238h]

  v64 = -2i64;
  v1 = this;
  v2 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v3 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  v4 = (UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0> *)v1->mLatchedWallRunningRequests.mNode.mNext;
  v5 = &v1->mLatchedWallRunningRequests;
  v66 = &v1->mLatchedWallRunningRequests;
  if ( v4 != &v1->mLatchedWallRunningRequests )
  {
    do
    {
      v6 = v4[2].mNode.mNext;
      if ( !v6 || !((_QWORD)v6[9].mNext & 1) )
      {
        v7 = (UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0> *)v4->mNode.mPrev;
        i = v4;
        v8 = v4[2].mNode.mNext;
        if ( v8 )
          ((void (__fastcall *)(UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *, signed __int64))v8->mPrev->mPrev)(
            v8,
            1i64);
        v9 = v4->mNode.mPrev;
        v10 = v4->mNode.mNext;
        v9->mNext = v10;
        v10->mPrev = v9;
        v4->mNode.mPrev = &v4->mNode;
        v4->mNode.mNext = &v4->mNode;
        operator delete[](v4);
        v4 = v7;
      }
      v4 = (UFG::qList<UFG::WallRunningRequest,UFG::WallRunningRequest,1,0> *)v4->mNode.mNext;
    }
    while ( v4 != v5 );
  }
  v11 = v1->mWallRunningRequests.mNode.mNext;
  v12 = (signed __int64)&v1->mWallRunningRequests;
  for ( i = &v1->mWallRunningRequests;
        v11 != (UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *)v12;
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
      if ( v15 && (_QWORD)v15[9].mNext & 1 )
      {
        v16 = v5->mNode.mPrev;
        v16->mNext = v11;
        v11->mPrev = v16;
        v11->mNext = &v5->mNode;
        v5->mNode.mPrev = v11;
      }
      else
      {
        v68 = (UFG::allocator::free_link *)v11;
        v17 = v11[2].mNext;
        if ( v17 )
          ((void (__fastcall *)(UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *, signed __int64))v17->mPrev->mPrev)(
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
      v12 = (signed __int64)&v1->mWallRunningRequests;
    }
    else
    {
      v20 = v11[2].mNext;
      if ( v20 && !((_QWORD)v20[9].mNext & 1) )
      {
        ((void (__fastcall *)(UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *, signed __int64))v20->mPrev->mPrev)(
          v20,
          1i64);
        v11[2].mNext = 0i64;
        v12 = (signed __int64)&v1->mWallRunningRequests;
      }
      if ( !v11[2].mNext )
      {
        v21 = v1->m_pSimObject;
        if ( v21 )
          v22 = v21->m_pTransformNodeComponent;
        else
          v22 = 0i64;
        UFG::TransformNodeComponent::UpdateWorldTransform(v22);
        v23 = v22->mWorldTransform.v3.y;
        v24 = v22->mWorldTransform.v3.z;
        rayStart.x = v22->mWorldTransform.v3.x;
        rayStart.y = v23;
        rayStart.z = v24 + *((float *)&v11[1].mPrev + 1);
        UFG::TransformNodeComponent::UpdateWorldTransform(v22);
        UFG::qRotateVectorZ(&dest, (UFG::qVector3 *)&v22->mWorldTransform, *(float *)&v11[1].mPrev);
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
            v1 = v65;
            v12 = (signed __int64)i;
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
              v31 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v30);
              v59.mTypeUID = UFG::qStringHash64(v31, 0xFFFFFFFFFFFFFFFFui64);
              UFG::qReflectHandleBase::Init(&v59, v59.mTypeUID, data.mPhysicsObjectPropertyHandleUid);
              v32 = v59.mData;
              if ( !v59.mData )
              {
                UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v59);
                v32 = v59.mData;
              }
              if ( BYTE5(v32[1].mTypeUID) )
              {
                if ( gDrawSensor )
                  Render::DebugDrawContext::DrawText(v2, &data.point, &UFG::qColour::White, "disabled by object tag");
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
                  Render::DebugDrawContext::DrawText(v2, &data.point, &UFG::qColour::White, "disabled by surface tag");
                v27 = 1;
              }
              UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&dest.z);
            }
            if ( !v27 )
            {
              v26 = 1;
              *(float *)((char *)&rayStart.x + v28) = data.point.x;
              *(float *)((char *)&rayStart.y + v28) = data.point.y;
              *(float *)((char *)&rayStart.z + v28) = data.point.z;
              *(float *)((char *)&v60 + v28) = data.normal.x;
              *(float *)((char *)&v61 + v28) = data.normal.y;
              v62[(unsigned __int64)v28 / 4] = LODWORD(data.normal.z);
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
          v28 += 12i64;
          v29 += 8i64;
        }
        while ( v28 < 36 );
        if ( v26 )
        {
          v36 = rayStart.x;
          v37 = rayStart.y;
          v38 = 1;
          v39 = 0;
          v40 = 0i64;
          while ( v38 )
          {
            if ( COERCE_FLOAT(v62[v40 / 4] & _xmm) > 0.0099999998 )
            {
              if ( gDrawSensor )
                Render::DebugDrawContext::DrawText(v2, &rayStart + v39, &UFG::qColour::White, "not vertical");
              v38 = 0;
            }
            v41 = (__m128)*(unsigned int *)((char *)&rayStart.x + v40);
            v41.m128_f32[0] = (float)((float)(v41.m128_f32[0] - v36) * (float)(v41.m128_f32[0] - v36))
                            + (float)((float)(*(float *)((char *)&rayStart.y + v40) - v37)
                                    * (float)(*(float *)((char *)&rayStart.y + v40) - v37));
            LODWORD(v42) = (unsigned __int128)_mm_sqrt_ps(v41);
            if ( v42 > 0.050000001 )
            {
              if ( gDrawSensor )
                Render::DebugDrawContext::DrawText(v2, &rayStart + v39, &UFG::qColour::White, "not smooth %f", v42);
              v38 = 0;
            }
            ++v39;
            v40 += 12i64;
            if ( v39 >= 3 )
            {
              v1 = v65;
              if ( !v38 )
                goto LABEL_69;
              v43 = (float)(v60 - (float)(*(float *)v62 * 0.0)) * 0.5;
              v44 = (float)((float)(*(float *)v62 * 0.0) - v61) * 0.5;
              _v0.x = rayStart.x - v44;
              _v0.y = rayStart.y - v43;
              _v0.z = rayStart.x + v44;
              v55 = rayStart.y + v43;
              dest.x = rayStart.z + (float)((float)((float)(v61 * 0.0) - (float)(v60 * 0.0)) * 0.5);
              v45 = UFG::ParkourQueryManager::mInstance;
              v46 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0xA0ui64, "ParkourHandle", 0i64, 1u);
              v68 = v46;
              if ( v46 )
              {
                UFG::ParkourHandle::ParkourHandle(
                  (UFG::ParkourHandle *)v46,
                  (unsigned int)v11 | ((_QWORD)v1 << 32),
                  &_v0,
                  (UFG::qVector3 *)((char *)&_v0 + 8),
                  0x810u);
                v48 = v47;
              }
              else
              {
                v48 = 0i64;
              }
              v49 = &v45->mActiveHandles[(signed int)((_DWORD)v11
                                                    - 257
                                                    * ((unsigned __int64)(((unsigned __int64)(unsigned int)v11 | ((_QWORD)v1 << 32))
                                                                        * (unsigned __int128)0xFF00FF00FF00FF01ui64 >> 64) >> 8))];
              v50 = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> **)(v48 + 24);
              v51 = v49->mNode.mPrev;
              v51->mNext = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)(v48 + 24);
              *v50 = v51;
              v50[1] = &v49->mNode;
              v49->mNode.mPrev = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)(v48 + 24);
              v11[2].mNext = (UFG::qNode<UFG::WallRunningRequest,UFG::WallRunningRequest> *)v48;
              v12 = (signed __int64)&v1->mWallRunningRequests;
              goto LABEL_70;
            }
          }
        }
        v1 = v65;
LABEL_69:
        v12 = (signed __int64)i;
LABEL_70:
        v5 = v66;
      }
    }
  }
}

// File Line: 489
// RVA: 0x45A260
char __fastcall UFG::SensorComponent::CastSphere(UFG::SensorComponent *this, UFG::qMatrix44 *transform, float radius, unsigned int collisionFilter, UFG::qVector3 *start, UFG::qVector3 *end, UFG::SimObject *trueIfHits)
{
  unsigned int v7; // edi
  UFG::qMatrix44 *v8; // rsi
  UFG::SensorComponent *v9; // rbx
  UFG::ShapeCasterCollector *v10; // rcx
  UFG::ShapeCasterCollector *v11; // rcx
  UFG::allocator::free_link *v12; // rax
  UFG::ShapeCasterCollector *v13; // rax
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm5_4
  UFG::qVector3 *v17; // rax
  float v18; // xmm12_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  float v22; // xmm13_4
  UFG::ShapeCasterCollector *v23; // rax
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v24; // rcx
  signed __int64 v25; // rax
  UFG::qVector3 v27; // [rsp+38h] [rbp-C0h]
  UFG::qVector3 v28; // [rsp+44h] [rbp-B4h]
  float starta; // [rsp+120h] [rbp+28h]
  float enda; // [rsp+128h] [rbp+30h]

  v7 = collisionFilter;
  v8 = transform;
  v9 = this;
  v10 = this->mSphereCaster;
  if ( v10
    && (v10->mRadius != radius || (unsigned int)UFG::ShapeCasterCollector::GetCollisionFilter(v10) != collisionFilter) )
  {
    v11 = v9->mSphereCaster;
    if ( v11 )
      v11->vfptr->__vecDelDtor(v11, 1u);
    v9->mSphereCaster = 0i64;
  }
  if ( !v9->mSphereCaster )
  {
    v12 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x30ui64, "SphereCaster", 0i64, 1u);
    if ( v12 )
      UFG::ShapeCasterCollector::ShapeCasterCollector((UFG::ShapeCasterCollector *)v12, radius, v7, 0);
    else
      v13 = 0i64;
    v9->mSphereCaster = v13;
  }
  v14 = start->x;
  v15 = start->y;
  v16 = start->z;
  v17 = end;
  starta = (float)((float)((float)(v8->v0.x * start->x) + (float)(v8->v1.x * v15)) + (float)(v8->v2.x * v16)) + v8->v3.x;
  enda = (float)((float)((float)(v8->v0.y * v14) + (float)(v8->v1.y * v15)) + (float)(v8->v2.y * v16)) + v8->v3.y;
  v18 = (float)((float)((float)(v8->v0.z * v14) + (float)(v8->v1.z * v15)) + (float)(v8->v2.z * v16)) + v8->v3.z;
  v19 = v17->y;
  v20 = v17->z;
  v21 = (float)((float)((float)(v8->v0.y * v17->x) + (float)(v8->v1.y * v19)) + (float)(v8->v2.y * v20)) + v8->v3.y;
  v22 = (float)((float)((float)(v8->v0.z * v17->x) + (float)(v8->v1.z * v19)) + (float)(v8->v2.z * v20)) + v8->v3.z;
  v27.x = (float)((float)((float)(v8->v0.x * v17->x) + (float)(v8->v1.x * v19)) + (float)(v8->v2.x * v20)) + v8->v3.x;
  v27.y = v21;
  v27.z = v22;
  v28.x = starta;
  v28.y = enda;
  v28.z = v18;
  if ( UFG::BasePhysicsSystem::CastShape(UFG::BasePhysicsSystem::mInstance, v9->mSphereCaster, &v28, &v27) )
  {
    if ( !trueIfHits )
      return 1;
    v23 = v9->mSphereCaster;
    v24 = v23->mHitList.mNode.mNext;
    v25 = (signed __int64)&v23->mHitList;
    if ( v24 != (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)v25 )
    {
      while ( (UFG::SimObject *)v24[5].mPrev != trueIfHits )
      {
        v24 = v24->mNext;
        if ( v24 == (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)v25 )
          return 0;
      }
      return 1;
    }
  }
  return 0;
}


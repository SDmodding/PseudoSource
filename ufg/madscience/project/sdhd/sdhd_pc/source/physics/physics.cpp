// File Line: 143
// RVA: 0x1519CA0
void UFG::_dynamic_initializer_for__VERY_LOW_LOD_RADIUS__()
{
  VERY_LOW_LOD_RADIUS.m_real = (__m128)_xmm;
}

// File Line: 161
// RVA: 0x46A870
void UFG::PhysicsSystem::InitializeMemory(void)
{
  signed int v0; // ecx
  hkHardwareInfo info; // [rsp+30h] [rbp+8h]

  hkGetHardwareInfo(&info);
  v0 = 4;
  UFG::BasePhysicsSystem::mParam.maxLoadedBodies = 2500;
  UFG::BasePhysicsSystem::mParam.solverBufferSize = 0x100000;
  if ( info.m_numThreads < 4 )
    v0 = info.m_numThreads;
  UFG::BasePhysicsSystem::mParam.numThreads = v0;
  UFG::BasePhysicsSystem::InitMemory();
}

// File Line: 184
// RVA: 0x469700
void __fastcall UFG::PhysicsSystem::Initialize(UFG *a1)
{
  UFG::allocator::free_link *v1; // rax
  UFG::RagdollFactory *v2; // rbx
  UFG::BasePhysicsSystem *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::RagdollFactory *v5; // rax

  if ( !UFG::BasePhysicsSystem::mInstance )
  {
    UFG::BasePhysicsSystem::mParam.gravity = FLOAT_N9_8100004;
    UFG::BasePhysicsSystem::mParam.broadPhaseMin = (hkVector4f)_xmm;
    UFG::BasePhysicsSystem::mParam.broadPhaseMax = (hkVector4f)_xmm;
    UFG::RegisterCollisionLayers(a1);
    v1 = UFG::qMalloc(0x18620ui64, "PhysicsSystem", 0i64);
    v2 = 0i64;
    if ( v1 )
      UFG::PhysicsSystem::PhysicsSystem((UFG::PhysicsSystem *)v1, &gPhysicsMemoryPool);
    else
      v3 = 0i64;
    UFG::BasePhysicsSystem::mInstance = v3;
    v4 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x68ui64, "RagdollFactory", 0i64, 1u);
    if ( v4 )
    {
      UFG::RagdollFactory::RagdollFactory((UFG::RagdollFactory *)v4);
      v2 = v5;
    }
    UFG::RagdollFactory::mInstance = v2;
    UFG::PhysicsPropertyManager::LoadDefinitionsFromInventory();
    UFG::PhysicsVolumePropertyManager::LoadDefinitionsFromInventory();
  }
}

// File Line: 225
// RVA: 0x473A30
void __fastcall UFG::PhysicsSystem::ResetScene(UFG::PhysicsSystem *this, UFG::PhysicsSystem::ResetFlags flags)
{
  UFG::PhysicsSystem *v2; // rbx
  UFG::RagdollFactory *v3; // rsi
  __int32 v4; // ebp
  UFG::RagdollFactory *v5; // rdi
  UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *v6; // rcx
  UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *v7; // rdx
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *v8; // rcx
  UFG::allocator::free_link *v9; // rax
  UFG::RagdollFactory *v10; // rax

  v2 = this;
  v3 = 0i64;
  v4 = flags & 1;
  if ( flags & 1 )
  {
    v5 = UFG::RagdollFactory::mInstance;
    if ( UFG::RagdollFactory::mInstance )
    {
      UFG::RagdollFactory::~RagdollFactory(UFG::RagdollFactory::mInstance);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v5);
    }
    UFG::RagdollFactory::mInstance = 0i64;
  }
  UFG::PhysicsSystem::DeleteStreamedCollisionInstances(v2);
  UFG::BasePhysicsSystem::CancelAllAsyncRayCasts((UFG::BasePhysicsSystem *)&v2->vfptr);
  if ( UFG::BulletManager::mInstance )
  {
    UFG::BulletManager::mInstance->vfptr->__vecDelDtor(UFG::BulletManager::mInstance, 1u);
    UFG::BulletManager::mInstance = 0i64;
  }
  UFG::Destruction::ResetScene(UFG::Destruction::mInstance);
  UFG::PhantomCallback::Shutdown();
  UFG::CharacterPhysicsComponentManager::ResetScene(UFG::CharacterPhysicsComponentManager::mInstance);
  v6 = (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
  if ( &UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext != (UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> **)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList - 72) )
  {
    do
    {
      v7 = (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)&v6[5].mNode.mPrev[-5].mNext;
      v8 = v6[40].mNode.mNext;
      if ( v8 && (HIDWORD(v8[37].mNext) & 7) == 2 && BYTE1(v8[77].mPrev) )
        LOWORD(v8[77].mPrev) = 0;
      v6 = v7;
    }
    while ( v7 != (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList
                                                                                          - 72) );
  }
  UFG::BulletManager::Initialize();
  UFG::PhantomCallback::Initialize();
  if ( v4 )
  {
    v9 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x68ui64, "RagdollFactory", 0i64, 1u);
    if ( v9 )
    {
      UFG::RagdollFactory::RagdollFactory((UFG::RagdollFactory *)v9);
      v3 = v10;
    }
    UFG::RagdollFactory::mInstance = v3;
    UFG::CustomCollisionFilter::ResetState(v2->mCollisionFilter);
  }
  UFG::PhysicsSystem::ResetFracturables(v2);
  UFG::PhysicsSystem::ResetParkourComponents(v2);
  UFG::PhysicsSystem::RecreateStreamedCollisionInstances(v2);
}

// File Line: 295
// RVA: 0x44ADC0
void __fastcall UFG::PhysicsSystem::PhysicsSystem(UFG::PhysicsSystem *this, UFG::qMemoryPool *pool)
{
  UFG::PhysicsSystem *v2; // r14
  UFG::ParkourContainerBundleInventory *v3; // rsi
  UFG::qString *v4; // rax
  UFG::qString *v5; // rax
  UFG::qString *v6; // rax
  UFG::qString *v7; // rax
  UFG::qString *v8; // rax
  UFG::qString *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::ParkourQueryManager *v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::ParkourInstanceInventory *v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::ParkourContainerInventory *v15; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::ParkourContainerBundleInventory *v17; // rax
  hkVector4f centre; // [rsp+40h] [rbp-19h]
  UFG::qString v19; // [rsp+50h] [rbp-9h]
  UFG::qList<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking,1,0> *v20; // [rsp+D0h] [rbp+77h]
  UFG::qList<SceneryToDisable,SceneryToDisable,1,0> *v21; // [rsp+D0h] [rbp+77h]
  UFG::WorldBoundaries *v22; // [rsp+D0h] [rbp+77h]

  v2 = this;
  UFG::BasePhysicsSystem::BasePhysicsSystem((UFG::BasePhysicsSystem *)&this->vfptr, pool);
  v2->vfptr = (UFG::BasePhysicsSystemVtbl *)&UFG::PhysicsSystem::`vftable';
  v20 = &v2->mStaticSceneryToDisable;
  v20->mNode.mPrev = &v20->mNode;
  v20->mNode.mNext = &v20->mNode;
  v21 = &v2->mSceneryFoundForDisable;
  v21->mNode.mPrev = &v21->mNode;
  v21->mNode.mNext = &v21->mNode;
  UFG::qMutex::qMutex(&v2->mEntitiesLeftBroadphase.mutex, &customWorldMapCaption);
  v2->mEntitiesLeftBroadphase.head.next = &v2->mEntitiesLeftBroadphase.tail;
  v3 = 0i64;
  v2->mEntitiesLeftBroadphase.head.prev = 0i64;
  v2->mEntitiesLeftBroadphase.tail.prev = &v2->mEntitiesLeftBroadphase.head;
  v2->mEntitiesLeftBroadphase.tail.next = 0i64;
  v22 = &v2->mBoundaries;
  v22->vfptr = (UFG::WorldBoundariesVtbl *)&UFG::WorldBoundaries::`vftable';
  v22->mWorldBoundaries.p = 0i64;
  *(_QWORD *)&v22->mWorldBoundaries.size = 0i64;
  UFG::qBaseTreeRB::qBaseTreeRB(&v2->mBoundaries.mMappings.mTree);
  v2->mWaterElevation = 0.0;
  v2->mWaterWaveHeight = 0.050000001;
  v2->mWaterWaveFrequency = 2.0;
  *(_QWORD *)&v2->mWaterWavePhase = 1056964608i64;
  hkpGroupFilter::disableCollisionsUsingBitfield((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 0xFFFFFFFE, 0xFFFFFFFE);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 1, 1);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 1, 2);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 1, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 1, 10);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 1, 19);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 1, 20);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 1, 26);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 1, 22);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 1, 31);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 2, 1);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 2, 2);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 2, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 2, 10);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 2, 19);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 2, 20);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 2, 26);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 2, 22);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 2, 31);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 4, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 4, 10);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 4, 20);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 4, 31);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 5, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 5, 20);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 5, 25);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 6, 1);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 6, 2);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 6, 25);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 6, 22);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 3, 3);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 9, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 9, 10);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 9, 31);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 25, 1);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 25, 3);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 25, 7);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 25, 8);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 25, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 25, 10);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 25, 19);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 25, 20);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 25, 27);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 25, 31);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 25, 28);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 7, 19);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 7, 20);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 7, 22);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 7, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 7, 10);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 7, 31);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 7, 7);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 19, 19);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 19, 20);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 19, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 19, 10);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 19, 31);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 20, 20);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 20, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 20, 10);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 20, 31);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 26, 19);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 26, 20);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 26, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 26, 10);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 26, 31);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 22, 22);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 22, 1);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 22, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 22, 10);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 22, 19);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 22, 20);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 22, 26);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 22, 31);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 18, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 18, 22);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 18, 30);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 23, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 24, 20);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 24, 22);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 24, 1);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 24, 2);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 29, 19);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 29, 20);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 29, 26);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 29, 22);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 11, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 11, 10);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 11, 22);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 11, 20);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 11, 7);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 12, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 12, 10);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 12, 19);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 12, 20);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 12, 22);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 13, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 13, 10);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 13, 20);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 13, 22);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 14, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 15, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 15, 20);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 15, 22);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 16, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 16, 10);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 16, 31);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 16, 19);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 16, 20);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 16, 27);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 17, 9);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 17, 10);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 28, 2);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 28, 19);
  hkpGroupFilter::enableCollisionsBetween((hkpGroupFilter *)&v2->mCollisionFilter->vfptr, 28, 20);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1197311665i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    2911353378i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    536383246i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    2910362013i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1908879335i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1648293198i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1893482955i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    205165038i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    2551363397i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    2300271228i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1566868405i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1312147186i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1312147187i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    592477054i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1407467077i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    4029961327i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1698822422i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    2073359529i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1412852942i64,
    0i64);
  UFG::qString::qString(&v19, "ARM_INTERIOR");
  UFG::qArray<UFG::qString,0>::Add(&v2->mActiveRegionManager.mNames, v4, "qArray.Add");
  UFG::qString::~qString(&v19);
  if ( v2->mActiveRegionManager.mExtents.m_size == (v2->mActiveRegionManager.mExtents.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v2->mActiveRegionManager.mExtents,
      16);
  v2->mActiveRegionManager.mExtents.m_data[v2->mActiveRegionManager.mExtents.m_size++] = (hkVector4f)_xmm;
  UFG::qString::qString(&v19, "ARM_SWEATSHOP_INTERIOR");
  UFG::qArray<UFG::qString,0>::Add(&v2->mActiveRegionManager.mNames, v5, "qArray.Add");
  UFG::qString::~qString(&v19);
  if ( v2->mActiveRegionManager.mExtents.m_size == (v2->mActiveRegionManager.mExtents.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v2->mActiveRegionManager.mExtents,
      16);
  v2->mActiveRegionManager.mExtents.m_data[v2->mActiveRegionManager.mExtents.m_size++] = (hkVector4f)_xmm;
  UFG::qString::qString(&v19, "ARM_WEDDING_INTERIOR");
  UFG::qArray<UFG::qString,0>::Add(&v2->mActiveRegionManager.mNames, v6, "qArray.Add");
  UFG::qString::~qString(&v19);
  if ( v2->mActiveRegionManager.mExtents.m_size == (v2->mActiveRegionManager.mExtents.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v2->mActiveRegionManager.mExtents,
      16);
  v2->mActiveRegionManager.mExtents.m_data[v2->mActiveRegionManager.mExtents.m_size++] = (hkVector4f)_xmm;
  UFG::qString::qString(&v19, "ARM_PENTHOUSE_INTERIOR");
  UFG::qArray<UFG::qString,0>::Add(&v2->mActiveRegionManager.mNames, v7, "qArray.Add");
  UFG::qString::~qString(&v19);
  if ( v2->mActiveRegionManager.mExtents.m_size == (v2->mActiveRegionManager.mExtents.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v2->mActiveRegionManager.mExtents,
      16);
  v2->mActiveRegionManager.mExtents.m_data[v2->mActiveRegionManager.mExtents.m_size++] = (hkVector4f)_xmm;
  UFG::qString::qString(&v19, "ARM_EXTERIOR");
  UFG::qArray<UFG::qString,0>::Add(&v2->mActiveRegionManager.mNames, v8, "qArray.Add");
  UFG::qString::~qString(&v19);
  if ( v2->mActiveRegionManager.mExtents.m_size == (v2->mActiveRegionManager.mExtents.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v2->mActiveRegionManager.mExtents,
      16);
  v2->mActiveRegionManager.mExtents.m_data[v2->mActiveRegionManager.mExtents.m_size++] = (hkVector4f)_xmm;
  UFG::qString::qString(&v19, "ARM_AIPACKER");
  UFG::qArray<UFG::qString,0>::Add(&v2->mActiveRegionManager.mNames, v9, "qArray.Add");
  UFG::qString::~qString(&v19);
  if ( v2->mActiveRegionManager.mExtents.m_size == (v2->mActiveRegionManager.mExtents.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v2->mActiveRegionManager.mExtents,
      16);
  v2->mActiveRegionManager.mExtents.m_data[v2->mActiveRegionManager.mExtents.m_size++] = (hkVector4f)_xmm;
  UFG::Destruction::Initialize(v2->mWorld);
  UFG::RigidBodyComponent::mAllocatorBuffer = UFG::qMemoryPool::Allocate(
                                                &gPhysicsMemoryPool,
                                                0x120160ui64,
                                                "RigidBodyComponentPool",
                                                0i64,
                                                1u);
  UFG::qFixedAllocator::Init(
    &UFG::RigidBodyComponent::mAllocator,
    UFG::RigidBodyComponent::mAllocatorBuffer,
    1180000,
    472,
    "RigidBodyComponentPool");
  UFG::StateMachineDefinition::LoadDefinitionsFromInventory();
  UFG::ExplosionManager::Initialize();
  UFG::BulletManager::Initialize();
  UFG::PhysicsVehicle::Initialize();
  UFG::CharacterPhysicsComponent::Initialize();
  UFG::PhantomCallback::Initialize();
  v10 = UFG::qMalloc(0x1040ui64, UFG::gGlobalNewName, 0i64);
  if ( v10 )
    UFG::ParkourQueryManager::ParkourQueryManager((UFG::ParkourQueryManager *)v10);
  else
    v11 = 0i64;
  UFG::ParkourQueryManager::mInstance = v11;
  UFG::RigidBody::mAcquireWaterFloatingTrackerFunc = UFG::AquireWaterFloatingTrackerComponent;
  v2->mBroadPhaseBorder->mCallback = UFG::PhysicsSystem::BroadPhaseBorderHandler;
  UFG::ActiveRegionManager::SetMode(&v2->mActiveRegionManager, 4);
  centre.m_quad = 0i64;
  UFG::ActiveRegionManager::SetCentre(&v2->mActiveRegionManager, &centre);
  v12 = UFG::qMalloc(0x120ui64, "ParkourInstanceInventory", 0i64);
  if ( v12 )
    UFG::ParkourInstanceInventory::ParkourInstanceInventory((UFG::ParkourInstanceInventory *)v12);
  else
    v13 = 0i64;
  UFG::gParkourInstanceInventory = v13;
  v14 = UFG::qMalloc(0x130ui64, "ParkourContainerInventory", 0i64);
  if ( v14 )
    UFG::ParkourContainerInventory::ParkourContainerInventory((UFG::ParkourContainerInventory *)v14);
  else
    v15 = 0i64;
  UFG::gParkourContainerInventory = v15;
  v16 = UFG::qMalloc(0x120ui64, "ParkourContainerBundleInventory", 0i64);
  if ( v16 )
  {
    UFG::ParkourContainerBundleInventory::ParkourContainerBundleInventory((UFG::ParkourContainerBundleInventory *)v16);
    v3 = v17;
  }
  UFG::gParkourContainerBundleInventory = v3;
}

// File Line: 606
// RVA: 0x450560
void __fastcall UFG::PhysicsSystem::~PhysicsSystem(UFG::PhysicsSystem *this)
{
  UFG::PhysicsSystem *v1; // rdi
  UFG::ParkourQueryManager *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  UFG::RagdollFactory *v4; // rax
  Render::SkinningCacheNode *v5; // rbx
  UFG::ParkourContainerBundleInventory *v6; // rbx
  UFG::ParkourContainerInventory *v7; // rbx
  UFG::ParkourInstanceInventory *v8; // rbx
  UFG::qNode<SceneryToDisable,SceneryToDisable> *v9; // rcx
  UFG::qNode<SceneryToDisable,SceneryToDisable> *v10; // rax
  UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *v11; // rcx
  UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *v12; // rax

  v1 = this;
  this->vfptr = (UFG::BasePhysicsSystemVtbl *)&UFG::PhysicsSystem::`vftable';
  v2 = UFG::ParkourQueryManager::mInstance;
  if ( UFG::ParkourQueryManager::mInstance )
  {
    UFG::ParkourQueryManager::~ParkourQueryManager(UFG::ParkourQueryManager::mInstance);
    operator delete[](v2);
  }
  UFG::PhantomCallback::Shutdown();
  UFG::CharacterPhysicsComponentManager::Shutdown();
  UFG::qFixedAllocator::Close(&UFG::CharacterPhysicsComponent::mAllocator);
  UFG::qMemoryPool::Free(&gPhysicsMemoryPool, UFG::CharacterPhysicsComponent::mAllocatorBuffer);
  UFG::CharacterPhysicsComponent::mAllocatorBuffer = 0i64;
  UFG::qFixedAllocator::Close(&UFG::PhysicsVehicle::mAllocator);
  UFG::qMemoryPool::Free(&gPhysicsMemoryPool, UFG::PhysicsVehicle::mAllocatorBuffer);
  UFG::PhysicsVehicle::mAllocatorBuffer = 0i64;
  UFG::ExplosionManager::Shutdown();
  if ( UFG::BulletManager::mInstance )
  {
    UFG::BulletManager::mInstance->vfptr->__vecDelDtor(UFG::BulletManager::mInstance, 1u);
    UFG::BulletManager::mInstance = 0i64;
  }
  v3 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x68ui64, "RagdollFactory", 0i64, 1u);
  if ( v3 )
    UFG::RagdollFactory::RagdollFactory((UFG::RagdollFactory *)v3);
  else
    v4 = 0i64;
  UFG::RagdollFactory::mInstance = v4;
  while ( UFG::StateMachineDefinition::mGuidTranslation.mTree.mCount )
  {
    v5 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::StateMachineDefinition::mGuidTranslation);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::StateMachineDefinition::mGuidTranslation,
      &v5->mNode);
    operator delete[](v5);
  }
  UFG::qFixedAllocator::Close(&UFG::RigidBodyComponent::mAllocator);
  UFG::qMemoryPool::Free(&gPhysicsMemoryPool, UFG::RigidBodyComponent::mAllocatorBuffer);
  UFG::RigidBodyComponent::mAllocatorBuffer = 0i64;
  v6 = UFG::gParkourContainerBundleInventory;
  if ( UFG::gParkourContainerBundleInventory )
  {
    UFG::qResourceInventory::~qResourceInventory((UFG::qResourceInventory *)&UFG::gParkourContainerBundleInventory->vfptr);
    operator delete[](v6);
  }
  UFG::gParkourContainerBundleInventory = 0i64;
  v7 = UFG::gParkourContainerInventory;
  if ( UFG::gParkourContainerInventory )
  {
    UFG::qResourceInventory::~qResourceInventory((UFG::qResourceInventory *)&UFG::gParkourContainerInventory->vfptr);
    operator delete[](v7);
  }
  UFG::gParkourContainerInventory = 0i64;
  v8 = UFG::gParkourInstanceInventory;
  if ( UFG::gParkourInstanceInventory )
  {
    UFG::qResourceInventory::~qResourceInventory((UFG::qResourceInventory *)&UFG::gParkourInstanceInventory->vfptr);
    operator delete[](v8);
  }
  UFG::gParkourInstanceInventory = 0i64;
  UFG::WorldBoundaries::~WorldBoundaries(&v1->mBoundaries);
  UFG::ThreadSafeQueue<UFG::CollisionEvent>::~ThreadSafeQueue<UFG::CollisionEvent>((UFG::ThreadSafeQueue<UFG::CollisionEvent> *)&v1->mEntitiesLeftBroadphase);
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v1->mSceneryFoundForDisable);
  v9 = v1->mSceneryFoundForDisable.mNode.mPrev;
  v10 = v1->mSceneryFoundForDisable.mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v1->mSceneryFoundForDisable.mNode.mPrev = &v1->mSceneryFoundForDisable.mNode;
  v1->mSceneryFoundForDisable.mNode.mNext = &v1->mSceneryFoundForDisable.mNode;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v1->mStaticSceneryToDisable);
  v11 = v1->mStaticSceneryToDisable.mNode.mPrev;
  v12 = v1->mStaticSceneryToDisable.mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v1->mStaticSceneryToDisable.mNode.mPrev = &v1->mStaticSceneryToDisable.mNode;
  v1->mStaticSceneryToDisable.mNode.mNext = &v1->mStaticSceneryToDisable.mNode;
  UFG::BasePhysicsSystem::~BasePhysicsSystem((UFG::BasePhysicsSystem *)&v1->vfptr);
}

// File Line: 669
// RVA: 0x46E150
UFG::RigidBodyComponent *__fastcall UFG::PhysicsSystem::OnCollisionInstanceAddedToWorld(UFG::PhysicsSystem *this, UFG::CollisionInstanceData *instance, UFG::CollisionMeshData *mesh, unsigned int onAddedFlags, unsigned int rigidBodyFlags, UFG::SimObject *simObject)
{
  unsigned int v6; // er12
  UFG::CollisionMeshData *v7; // rsi
  UFG::CollisionInstanceData *v8; // r13
  UFG::RigidBodyComponent *v9; // rdi
  UFG::PhysicsObjectProperties *v10; // r14
  unsigned int v11; // ebx
  UFG::allocator::free_link *v12; // rax
  __int64 v13; // rdx
  UFG::SimComponent *v14; // rax
  UFG::SimComponent *v15; // rax
  UFG::allocator::free_link *v16; // rax
  __int64 v17; // rdx
  UFG::RigidBodyComponent *v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::RigidBodyComponent *v20; // rax
  unsigned int v21; // er15
  UFG::SimObjectGame *v22; // rsi
  UFG::qMemoryPool *v23; // rax
  UFG::ComponentTypeTable *v24; // rax
  UFG::qMemoryPool *v25; // rax
  UFG::allocator::free_link *v26; // rax
  UFG::TransformNodeComponent *v27; // rax
  UFG::TransformNodeComponent *v28; // r13
  unsigned __int16 v29; // cx
  unsigned int v30; // ebx
  unsigned int v31; // eax
  UFG::qMemoryPool *v32; // rax
  UFG::allocator::free_link *v33; // rax
  char *v34; // r9
  UFG::SimComponent *v35; // rax
  UFG::allocator::free_link *v36; // rax
  UFG::allocator::free_link *v37; // rbx
  UFG::SimComponent *v38; // rbx
  unsigned __int16 v39; // cx
  UFG::qSymbol name; // [rsp+30h] [rbp-D0h]
  UFG::SimComponent *component; // [rsp+38h] [rbp-C8h]
  UFG::SimComponent *v43; // [rsp+40h] [rbp-C0h]
  UFG::SimObjectModifier v44; // [rsp+48h] [rbp-B8h]
  UFG::allocator::free_link *v45; // [rsp+68h] [rbp-98h]
  __int64 v46; // [rsp+70h] [rbp-90h]
  hkRotationf v47; // [rsp+80h] [rbp-80h]
  hkVector4f v48; // [rsp+B0h] [rbp-50h]
  float d; // [rsp+C0h] [rbp-40h]
  UFG::PhysicsSystem *v50; // [rsp+150h] [rbp+50h]
  UFG::CollisionInstanceData *v51; // [rsp+158h] [rbp+58h]
  UFG::CollisionMeshData *mesha; // [rsp+160h] [rbp+60h]
  char ptr; // [rsp+168h] [rbp+68h]

  mesha = mesh;
  v51 = instance;
  v50 = this;
  v46 = -2i64;
  v6 = onAddedFlags;
  v7 = mesh;
  v8 = instance;
  v9 = 0i64;
  v10 = (UFG::PhysicsObjectProperties *)mesh->mObjectProperties.mData;
  v43 = 0i64;
  ptr = 0;
  v11 = rigidBodyFlags;
  if ( onAddedFlags & 1 )
    v11 = rigidBodyFlags | 4;
  if ( v10->mCreateWaterPhantom )
  {
    v12 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x2D8ui64, "WaterPhantomComponent", 0i64, 1u);
    v45 = v12;
    if ( v12 )
    {
      UFG::WaterPhantomComponent::WaterPhantomComponent((UFG::WaterPhantomComponent *)v12, v8);
      component = v14;
    }
    else
    {
      v13 = 0i64;
      component = 0i64;
    }
    v15 = component;
  }
  else
  {
    if ( v10->mMotionType != 1 || v10->mForceLibraryObject || v10->mPreventStaticWorldMerge )
    {
      if ( v10->mActiveRegionManagement != 1 )
        v11 |= 1u;
      v19 = UFG::RigidBodyComponent::operator new(0x1D8ui64);
      v45 = v19;
      if ( v19 )
      {
        UFG::RigidBodyComponent::RigidBodyComponent((UFG::RigidBodyComponent *)v19, v7, v8, v11, -1);
        v9 = v20;
      }
      else
      {
        v9 = 0i64;
      }
      if ( v10->mActiveRegionManagement == 1 )
      {
        LOBYTE(v13) = 1;
        v9->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v9->vfptr, v13);
      }
      ptr = 1;
    }
    else
    {
      v16 = UFG::RigidBodyComponent::operator new(0x1D8ui64);
      v45 = v16;
      if ( v16 )
      {
        UFG::RigidBodyComponent::RigidBodyComponent((UFG::RigidBodyComponent *)v16, v7, v8, v11, -1);
        v9 = v18;
      }
      else
      {
        v9 = 0i64;
      }
      LOBYTE(v17) = 1;
      v9->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v9->vfptr, v17);
    }
    v15 = (UFG::SimComponent *)&v9->vfptr;
    component = (UFG::SimComponent *)&v9->vfptr;
  }
  v8->mPhysicsComponent = v15;
  name.mUID = v8->mSimObjectName.mUID;
  v21 = -1;
  v22 = (UFG::SimObjectGame *)simObject;
  if ( !simObject )
  {
    v23 = UFG::GetSimulationMemoryPool();
    v22 = (UFG::SimObjectGame *)UFG::qMemoryPool::Allocate(v23, 0x90ui64, "SimObject", 0i64, 1u);
    if ( v22 )
    {
      v24 = UFG::GetTypeTableProp();
      UFG::SimObjectGame::SimObjectGame(v22, v24, &name);
      v22->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)&UFG::SimObjectProp::`vftable';
      v22->m_Flags |= 0x2000u;
    }
    else
    {
      v22 = 0i64;
    }
    v48.m_quad = (__m128)v8->mInitialPosition;
    hkRotationf::set(&v47, &v8->mInitialOrientation);
    hkTransformf::get4x4ColumnMajor((hkTransformf *)&v47, &d);
    v25 = UFG::GetSimulationMemoryPool();
    v26 = UFG::qMemoryPool::Allocate(v25, 0x110ui64, "SimComponent", 0i64, 1u);
    if ( v26 )
    {
      UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v26, name.mUID, 0i64, 0);
      v28 = v27;
    }
    else
    {
      v28 = 0i64;
    }
    UFG::TransformNodeComponent::SetWorldTransform(v28, (UFG::qMatrix44 *)&d);
    v29 = v22->m_Flags;
    if ( (v29 >> 14) & 1 )
    {
      v30 = 2;
    }
    else if ( (v29 & 0x8000u) == 0 )
    {
      if ( (v29 >> 13) & 1 )
      {
        v30 = 2;
      }
      else
      {
        v30 = -1;
        if ( (v29 >> 12) & 1 )
          v30 = 1;
      }
    }
    else
    {
      v30 = 2;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v44, (UFG::SimObject *)&v22->vfptr, 1);
    UFG::SimObjectModifier::AttachComponent(&v44, (UFG::SimComponent *)&v28->vfptr, v30);
    UFG::SimObjectModifier::Close(&v44);
    UFG::SimObjectModifier::~SimObjectModifier(&v44);
    v8 = v51;
  }
  if ( !(v6 & 0x10) && !(v6 & 0x20) && ptr )
    UFG::PhysicsSystem::AddRenderHelper(v50, (UFG::SimObject *)&v22->vfptr, v9, v8, mesha);
  v31 = v10->mActFileName.mText.mData.mNumItems;
  if ( v31 && (v31 != 1 || *v10->mActFileName.mText.mData.mItems) )
  {
    v32 = UFG::GetSimulationMemoryPool();
    v33 = UFG::qMemoryPool::Allocate(v32, 0x560ui64, "ActionTreeComponent", 0i64, 1u);
    if ( v33 )
    {
      if ( v10->mActFileName.mText.mData.mNumItems )
        v34 = v10->mActFileName.mText.mData.mItems;
      else
        v34 = &customWorldMapCaption;
      UFG::ActionTreeComponent::ActionTreeComponent((UFG::ActionTreeComponent *)v33, 0i64, v22->mNode.mUID, v34);
      v43 = v35;
    }
    else
    {
      v43 = 0i64;
    }
    v36 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x80ui64, "StateMachineDefinition", 0i64, 1u);
    v37 = v36;
    if ( v36 )
    {
      UFG::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject>::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject>((UFG::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject> *)v36);
      v37->mNext = (UFG::allocator::free_link *)&UFG::StateMachineDefinition::`vftable';
      v37[11].mNext = 0i64;
      v37[10].mNext = 0i64;
      LODWORD(v37[12].mNext) = -1;
      LOWORD(v37[15].mNext) = 0;
      BYTE2(v37[15].mNext) = 0;
    }
    else
    {
      v37 = 0i64;
    }
    HIDWORD(v37[12].mNext) = 1065353216;
    LODWORD(v37[13].mNext) = 1065353216;
    HIDWORD(v37[13].mNext) = 1065353216;
    HIDWORD(v37[14].mNext) = 1065353216;
    UFG::RigidBodyComponent::CreateRuntimeStateMachineDefinition(v9, (UFG::StateMachineDefinition *)v37);
  }
  if ( v6 & 2 )
    v9->mFlags |= 0x20u;
  if ( v6 & 8 )
  {
    LOBYTE(v13) = 1;
    v9->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v9->vfptr, v13);
  }
  UFG::SimObjectModifier::SimObjectModifier(&v44, (UFG::SimObject *)&v22->vfptr, 1);
  UFG::SimObjectModifier::AttachComponent(&v44, component, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v44);
  UFG::SimObjectModifier::~SimObjectModifier(&v44);
  v38 = v43;
  if ( v43 )
  {
    v39 = v22->m_Flags;
    if ( (v39 >> 14) & 1 )
    {
      v21 = 7;
    }
    else if ( (v39 & 0x8000u) == 0 )
    {
      if ( (v39 >> 13) & 1 )
        v21 = 6;
    }
    else
    {
      v21 = 7;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v44, (UFG::SimObject *)&v22->vfptr, 1);
    UFG::SimObjectModifier::AttachComponent(&v44, v38, v21);
    UFG::SimObjectModifier::Close(&v44);
    UFG::SimObjectModifier::~SimObjectModifier(&v44);
  }
  if ( ~(unsigned __int8)(v6 >> 1) & 1 )
    UFG::PhysicsSystem::AddParkourAndCover(v50, (UFG::SimObject *)&v22->vfptr, v9, mesha, -1);
  UFG::PhysicsSystem::AddStateMachines(v50, (UFG::SimObject *)&v22->vfptr, v9, v8, mesha);
  return v9;
}

// File Line: 796
// RVA: 0x46E6A0
void __fastcall UFG::PhysicsSystem::OnCollisionInstanceRemovedFromWorld(UFG::PhysicsSystem *this, UFG::CollisionInstanceData *instance)
{
  UFG::CollisionInstanceData *v2; // rax
  UFG::SimComponent *v3; // rdx
  UFG::SimObject *v4; // rdx

  v2 = instance;
  v3 = instance->mPhysicsComponent;
  if ( v3 )
  {
    v4 = v3->m_pSimObject;
    v2->mPhysicsComponent = 0i64;
    UFG::Simulation::DestroySimObject(&UFG::gSim, v4);
  }
}

// File Line: 811
// RVA: 0x455210
void __fastcall UFG::PhysicsSystem::AddPhysicsComponents(UFG::PhysicsSystem *this, UFG::SimObject *simObject, UFG::RigResource *rig)
{
  UFG::RigResource *v3; // rsi
  UFG::SimObjectGame *v4; // rdi
  UFG::PhysicsSystem *v5; // r13
  UFG::TransformNodeComponent *v6; // rbx
  unsigned __int16 v7; // cx
  UFG::SimComponent *v8; // rax
  __int64 v9; // rbp
  __int64 v10; // r15
  UFG::RigResource::CollisionMap *v11; // rax
  unsigned int collisionModelGuid; // ebx
  __int64 v13; // r14
  UFG::qBaseTreeRB *v14; // rax
  UFG::CollisionMeshData *v15; // rsi
  UFG::qBaseNodeRB *v16; // r12
  hkaPose *v17; // rcx
  hkQsTransformf *v18; // rax
  __m128 v19; // xmm6
  __m128 v20; // xmm7
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm5
  __m128 v26; // xmm4
  __m128 v27; // xmm3
  __m128 v28; // xmm5
  __m128 v29; // xmm5
  __m128 v30; // xmm8
  __m128 v31; // xmm5
  __m128 v32; // xmm1
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  UFG::allocator::free_link *v36; // rax
  UFG::CollisionInstanceData *v37; // rax
  UFG::CollisionInstanceData *v38; // rbp
  unsigned int v39; // edx
  unsigned int v40; // ebx
  UFG::allocator::free_link *v41; // rax
  __int64 v42; // rdx
  UFG::RigidBodyComponent *v43; // rax
  UFG::RigidBodyComponent *v44; // rbx
  hkQuaternionf orient; // [rsp+40h] [rbp-108h]
  hkVector4f pos; // [rsp+50h] [rbp-F8h]
  __int64 *v47; // [rsp+60h] [rbp-E8h]
  __int64 v48; // [rsp+68h] [rbp-E0h]
  hkTransformf transform; // [rsp+70h] [rbp-D8h]
  hkQsTransformf v50; // [rsp+B0h] [rbp-98h]
  UFG::allocator::free_link *name; // [rsp+158h] [rbp+10h]
  UFG::RigResource *v52; // [rsp+160h] [rbp+18h]
  __int64 v53; // [rsp+168h] [rbp+20h]

  v52 = rig;
  v48 = -2i64;
  v3 = rig;
  v4 = (UFG::SimObjectGame *)simObject;
  v5 = this;
  v6 = simObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(simObject->m_pTransformNodeComponent);
  hkTransformf::set4x4ColumnMajor(&transform, &v6->mWorldTransform.v0.x);
  hkQsTransformf::setFromTransformNoScale(&v50, &transform);
  v7 = v4->m_Flags;
  if ( (v7 >> 14) & 1 )
  {
    v8 = v4->m_Components.p[9].m_pComponent;
  }
  else if ( (v7 & 0x8000u) == 0 )
  {
    if ( (v7 >> 13) & 1 )
    {
      v8 = v4->m_Components.p[8].m_pComponent;
    }
    else if ( (v7 >> 12) & 1 )
    {
      v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::BaseAnimationComponent::_TypeUID);
    }
    else
    {
      v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::BaseAnimationComponent::_TypeUID);
    }
  }
  else
  {
    v8 = v4->m_Components.p[9].m_pComponent;
  }
  v9 = *(_QWORD *)&v8[2].m_TypeUID;
  v53 = v9;
  if ( v9 )
  {
    v10 = 0i64;
    if ( v3->mNumCollisionMap )
    {
      do
      {
        v11 = v3->mCollisionMap;
        collisionModelGuid = v11[v10].collisionGuid;
        v13 = (signed int)v11[v10].boneIndex;
        v14 = UFG::BasePhysicsSystem::GetCollisionModel(UFG::BasePhysicsSystem::mInstance, v11[v10].collisionGuid);
        v15 = (UFG::CollisionMeshData *)v14;
        if ( v14 )
        {
          v16 = v14[3].mNULL.mChild[0];
          if ( !BYTE4(v16[4].mChild[0])
            && UFG::BasePhysicsSystem::RequestAnotherRigidBody(UFG::BasePhysicsSystem::mInstance) )
          {
            v17 = *(hkaPose **)(v9 + 488);
            if ( v17->m_boneFlags.m_data[v13] & 2 )
              v18 = hkaPose::calculateBoneModelSpace(v17, v13);
            else
              v18 = &v17->m_modelPose.m_data[v13];
            v19 = v18->m_rotation.m_vec.m_quad;
            v20 = _mm_shuffle_ps(v50.m_rotation.m_vec.m_quad, v50.m_rotation.m_vec.m_quad, 255);
            v21 = _mm_mul_ps(v50.m_rotation.m_vec.m_quad, v18->m_translation.m_quad);
            v22 = _mm_mul_ps(
                    v50.m_rotation.m_vec.m_quad,
                    _mm_add_ps(
                      _mm_shuffle_ps(v21, v21, 170),
                      _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0))));
            v23 = _mm_shuffle_ps(v50.m_rotation.m_vec.m_quad, v50.m_rotation.m_vec.m_quad, 201);
            v24 = _mm_sub_ps(
                    _mm_mul_ps(
                      v50.m_rotation.m_vec.m_quad,
                      _mm_shuffle_ps(v18->m_translation.m_quad, v18->m_translation.m_quad, 201)),
                    _mm_mul_ps(v18->m_translation.m_quad, v23));
            v25 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(v18->m_translation.m_quad, _mm_sub_ps(_mm_mul_ps(v20, v20), (__m128)xmmword_141A711B0)),
                      v22),
                    _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v20));
            v26 = _mm_add_ps(v50.m_translation.m_quad, _mm_add_ps(v25, v25));
            v27 = _mm_shuffle_ps(v19, v19, 255);
            v28 = _mm_sub_ps(
                    _mm_mul_ps(v50.m_rotation.m_vec.m_quad, _mm_shuffle_ps(v18->m_rotation.m_vec.m_quad, v19, 201)),
                    _mm_mul_ps(v18->m_rotation.m_vec.m_quad, v23));
            v29 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v28, v28, 201), _mm_mul_ps(v18->m_rotation.m_vec.m_quad, v20)),
                    _mm_mul_ps(v50.m_rotation.m_vec.m_quad, v27));
            v30 = _mm_mul_ps(v50.m_rotation.m_vec.m_quad, v19);
            v31 = _mm_shuffle_ps(
                    v29,
                    _mm_unpackhi_ps(
                      v29,
                      _mm_sub_ps(
                        _mm_mul_ps(v27, v20),
                        _mm_add_ps(
                          _mm_shuffle_ps(v30, v30, 170),
                          _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0))))),
                    196);
            pos.m_quad = v26;
            v32 = _mm_mul_ps(v31, v31);
            v33 = _mm_add_ps(v32, _mm_shuffle_ps(v32, v32, 78));
            v34 = _mm_add_ps(_mm_shuffle_ps(v33, v33, 177), v33);
            v35 = _mm_rsqrt_ps(v34);
            orient.m_vec.m_quad = _mm_mul_ps(
                                    v31,
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v35, v34), v35)),
                                      _mm_mul_ps(v35, *(__m128 *)_xmm)));
            v36 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x70ui64, "CollisionInstanceData", 0i64, 1u);
            name = v36;
            if ( v36 )
            {
              UFG::CollisionInstanceData::CollisionInstanceData((UFG::CollisionInstanceData *)v36);
              v38 = v37;
            }
            else
            {
              v38 = 0i64;
            }
            v39 = v4->m_Name.mUID;
            v47 = (__int64 *)&name;
            LODWORD(name) = v39;
            UFG::CollisionInstanceData::Set(v38, v39, 0, (__int64)&name, &pos, &orient, collisionModelGuid);
            v40 = 0;
            if ( !LODWORD(v16[6].mChild[0]) )
              v40 = 1;
            v41 = UFG::RigidBodyComponent::operator new(0x1D8ui64);
            name = v41;
            if ( v41 )
            {
              UFG::RigidBodyComponent::RigidBodyComponent((UFG::RigidBodyComponent *)v41, v15, v38, v40, v13);
              v44 = v43;
            }
            else
            {
              v44 = 0i64;
            }
            if ( v44 )
            {
              LOBYTE(v42) = 1;
              v44->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v44->vfptr, v42);
              UFG::SimObjectModifier::SimObjectModifier(
                (UFG::SimObjectModifier *)&transform,
                (UFG::SimObject *)&v4->vfptr,
                1);
              UFG::SimObjectModifier::AttachComponent(
                (UFG::SimObjectModifier *)&transform,
                (UFG::SimComponent *)&v44->vfptr,
                0xFFFFFFFFi64);
              UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&transform);
              UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&transform);
              UFG::PhysicsSystem::AddParkourAndCover(v5, (UFG::SimObject *)&v4->vfptr, v44, v15, v13);
              UFG::PhysicsSystem::AddStateMachines(v5, (UFG::SimObject *)&v4->vfptr, v44, v38, v15);
              UFG::PhysicsSystem::AddRenderHelper(v5, (UFG::SimObject *)&v4->vfptr, v44, v38, v15);
            }
            v9 = v53;
          }
        }
        v10 = (unsigned int)(v10 + 1);
        v3 = v52;
      }
      while ( (unsigned int)v10 < v52->mNumCollisionMap );
    }
  }
}

// File Line: 873
// RVA: 0x4731F0
void __fastcall UFG::PhysicsSystem::RemovePhysicsComponents(UFG::PhysicsSystem *this, UFG::SimObject *simObject)
{
  UFG::SimObject *v2; // rbx
  UFG::SimComponent *v3; // rax

  v2 = simObject;
  if ( !((LOBYTE(simObject->m_Flags) >> 1) & 1) )
  {
    while ( 1 )
    {
      v3 = UFG::SimObject::GetComponentOfType(v2, UFG::RigidBodyComponent::_TypeUID);
      if ( !v3 )
        break;
      UFG::Simulation::DestroySimComponent(&UFG::gSim, v3);
    }
  }
}

// File Line: 892
// RVA: 0x45BF80
void __fastcall UFG::PhysicsSystem::Create(UFG::PhysicsSystem *this, UFG::SimObject *simObject, UFG::FreeRunData *data)
{
  UFG::FreeRunData *v3; // rbx
  UFG::SimObject *v4; // rbp
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceData *v7; // rsi
  __int64 v8; // rdi
  UFG::qBaseNodeRB **v9; // rdx
  char *v10; // rbx
  UFG::allocator::free_link *v11; // rax
  UFG::SimComponent *v12; // rax
  UFG::SimComponent *v13; // rbx
  UFG::SimObjectModifier v14; // [rsp+28h] [rbp-30h]

  v3 = data;
  v4 = simObject;
  v5 = `UFG::qGetResourceInventory<UFG::ParkourContainerBundle>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::ParkourContainerBundle>'::`2'::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0x4558A12Eu);
    `UFG::qGetResourceInventory<UFG::ParkourContainerBundle>'::`2'::result = v5;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v3->mParkourContainerBundle.mPrev,
    0x4558A12Eu,
    v3->mParkourContainerBundle.mNameUID,
    v5);
  v7 = v3->mParkourContainerBundle.mData;
  v8 = 0i64;
  if ( LODWORD(v7[1].mNode.mParent) )
  {
    do
    {
      v9 = &v7[1].mNode.mChild[0]->mParent + v8;
      if ( *v9 )
        v10 = (char *)v9 + (_QWORD)*v9;
      else
        v10 = 0i64;
      v11 = UFG::qMalloc(0xC8ui64, "ParkourComponent", 0x800ui64);
      if ( v11 )
      {
        UFG::ParkourComponent::ParkourComponent((UFG::ParkourComponent *)v11, *((_DWORD *)v10 + 6), -1);
        v13 = v12;
      }
      else
      {
        v13 = 0i64;
      }
      UFG::SimObjectModifier::SimObjectModifier(&v14, v4, 1);
      UFG::SimObjectModifier::AttachComponent(&v14, v13, 0xFFFFFFFFi64);
      UFG::SimObjectModifier::Close(&v14);
      UFG::SimObjectModifier::~SimObjectModifier(&v14);
      v8 = (unsigned int)(v8 + 1);
    }
    while ( (unsigned int)v8 < LODWORD(v7[1].mNode.mParent) );
  }
}

// File Line: 907
// RVA: 0x45BE80
void __fastcall UFG::PhysicsSystem::Create(UFG::PhysicsSystem *this, UFG::SimObject *simObject, UFG::CoverData *data)
{
  UFG::CoverData *v3; // rbx
  UFG::SimObject *v4; // rbp
  UFG::qResourceData *v5; // rsi
  __int64 v6; // rdi
  UFG::qBaseNodeRB **v7; // rdx
  char *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  UFG::SimComponent *v10; // rax
  UFG::SimComponent *v11; // rbx
  UFG::SimObjectModifier v12; // [rsp+28h] [rbp-30h]

  v3 = data;
  v4 = simObject;
  UFG::qResourceHandle::Init(&data->mDynamicCoverResource, 0xEC7A2131, data->mDynamicCoverResource.mNameUID);
  v5 = v3->mDynamicCoverResource.mData;
  if ( v5 )
  {
    v6 = 0i64;
    if ( LODWORD(v5[1].mNode.mParent) )
    {
      do
      {
        v7 = &v5[1].mNode.mChild[0]->mParent + v6;
        if ( *v7 )
          v8 = (char *)v7 + (_QWORD)*v7;
        else
          v8 = 0i64;
        v9 = UFG::qMalloc(0x88ui64, "DynamicCoverComponent", 0x800ui64);
        if ( v9 )
        {
          UFG::DynamicCoverComponent::DynamicCoverComponent((UFG::DynamicCoverComponent *)v9, *((_DWORD *)v8 + 6));
          v11 = v10;
        }
        else
        {
          v11 = 0i64;
        }
        UFG::SimObjectModifier::SimObjectModifier(&v12, v4, 1);
        UFG::SimObjectModifier::AttachComponent(&v12, v11, 0xFFFFFFFFi64);
        UFG::SimObjectModifier::Close(&v12);
        UFG::SimObjectModifier::~SimObjectModifier(&v12);
        v6 = (unsigned int)(v6 + 1);
      }
      while ( (unsigned int)v6 < LODWORD(v5[1].mNode.mParent) );
    }
  }
}

// File Line: 925
// RVA: 0x45B3B0
void __fastcall UFG::PhysicsSystem::Create(UFG::PhysicsSystem *this, UFG::SimObject *simObject, UFG::CollisionData *collisionData, UFG::SkeletonData *skeletonData)
{
  UFG::SkeletonData *v4; // rdi
  UFG::CollisionData *v5; // rbx
  UFG::SimObject *v6; // r13
  unsigned int v7; // er8
  unsigned __int64 v8; // rsi
  UFG::TransformNodeComponent *v9; // rbx
  UFG::qResourceData *v10; // rax
  UFG::SimComponent *v11; // rax
  __m128 v12; // xmm1
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm0
  UFG::allocator::free_link *v16; // r15
  unsigned int v17; // er12
  UFG::MultiBodyComponent *v18; // rbx
  signed int v19; // edx
  unsigned int v20; // eax
  __int64 v21; // rcx
  __int64 v22; // r8
  UFG::allocator::free_link *v23; // rax
  UFG::MultiBodyComponent *v24; // rax
  unsigned int v25; // eax
  UFG::CollisionMeshData *v26; // rsi
  UFG::RigidBody *v27; // rdi
  char *v28; // rax
  UFG::allocator::free_link *v29; // rax
  UFG::CollisionInstanceData *v30; // rax
  UFG::CollisionInstanceData *v31; // r14
  unsigned int collisionModelGuid; // eax
  UFG::qReflectObject *v33; // rax
  UFG::allocator::free_link *v34; // rax
  UFG::SimComponent *v35; // rax
  UFG::SimComponent *v36; // rbx
  int v37; // edi
  __int64 v38; // rax
  signed __int64 v39; // rcx
  __m128 *v40; // rcx
  __m128 v41; // xmm8
  __m128 v42; // xmm2
  __m128 v43; // xmm4
  __m128 v44; // xmm1
  __m128 v45; // xmm6
  __m128 v46; // xmm7
  __m128 v47; // xmm2
  __m128 v48; // xmm3
  __m128 v49; // xmm5
  __m128 v50; // xmm5
  __m128 v51; // xmm9
  __m128 v52; // xmm5
  __m128 v53; // xmm7
  __m128 v54; // xmm1
  __m128 v55; // xmm1
  __m128 v56; // xmm2
  __m128 v57; // xmm1
  __m128 v58; // xmm5
  UFG::RigidBodyComponent *v59; // rbx
  unsigned int v60; // eax
  UFG::RigidBody *v61; // rax
  __int64 v62; // rdx
  unsigned int v63; // er14
  unsigned int v64; // ebx
  unsigned __int64 v65; // rax
  UFG::allocator::free_link *v66; // rax
  UFG::allocator::free_link *v67; // rdx
  __int64 v68; // r8
  unsigned int v69; // eax
  signed __int64 v70; // rsi
  __int64 v71; // r14
  __int64 v72; // rbx
  __int64 v73; // rbx
  UFG::allocator::free_link *v74; // rax
  UFG::SimComponent *v75; // rax
  UFG::SimComponent *v76; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v77; // rdx
  UFG::qSafePointerNode<UFG::SimObject>Vtbl *v78; // rcx
  UFG::SimObject *v79; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v80; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v81; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v82; // rcx
  UFG::SimComponent *v83; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v84; // rax
  __int64 v85; // rcx
  __int64 v86; // rax
  signed __int64 v87; // rsi
  UFG::qReflectObjectType<UFG::ConstraintDef,UFG::qReflectObject> *v88; // rcx
  const char *v89; // rax
  unsigned __int64 v90; // rdi
  unsigned __int64 v91; // rbx
  UFG::ReflectionDB *v92; // rax
  __int64 v93; // r9
  hkpRigidBody *v94; // rbx
  hkpRigidBody *v95; // rdi
  UFG::RigidBody *v96; // r14
  UFG::RigidBody *v97; // rsi
  __int64 v98; // rdx
  UFG::allocator::free_link *v99; // rcx
  UFG::allocator::free_link *v100; // r8
  UFG::allocator::free_link *v101; // r13
  UFG::Constraint *v102; // rax
  UFG::Constraint *v103; // rbx
  UFG::qResourceData *v104; // [rsp+40h] [rbp-88h]
  __int64 v105; // [rsp+40h] [rbp-88h]
  UFG::MultiBodyComponent *v106; // [rsp+48h] [rbp-80h]
  __int64 v107; // [rsp+50h] [rbp-78h]
  UFG::allocator::free_link *v108; // [rsp+58h] [rbp-70h]
  void *v109; // [rsp+60h] [rbp-68h]
  hkVector4f pos; // [rsp+68h] [rbp-60h]
  UFG::SimObjectModifier v111; // [rsp+78h] [rbp-50h]
  hkQuaternionf orient; // [rsp+98h] [rbp-30h]
  UFG::SimObjectModifier v113; // [rsp+A8h] [rbp-20h]
  hkTransformf transform; // [rsp+C8h] [rbp+0h]
  __int64 v115; // [rsp+108h] [rbp+40h]
  hkQsTransformf v116; // [rsp+118h] [rbp+50h]
  UFG::BasePhysicsSystem *v117; // [rsp+1E8h] [rbp+120h]
  UFG::qSymbol name[2]; // [rsp+1F8h] [rbp+130h]
  __int64 v119; // [rsp+208h] [rbp+140h]

  v115 = -2i64;
  v4 = skeletonData;
  v5 = collisionData;
  v6 = simObject;
  v7 = collisionData->mCollisionMeshBundle.mNameUID;
  v5->mCollisionMeshBundle.mOwner = 0i64;
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v5->mCollisionMeshBundle.mPrev, 0x1723EA91u, v7);
  v8 = (unsigned __int64)v5->mCollisionMeshBundle.mData;
  pos.m_quad.m128_u64[1] = v8;
  if ( !v8 )
    return;
  v9 = v6->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v6->m_pTransformNodeComponent);
  v104 = 0i64;
  if ( v4 )
  {
    v10 = UFG::qResourceInventory::Get((UFG::qResourceInventory *)&UFG::gRigInventory.vfptr, v4->mRigHandle);
LABEL_6:
    v104 = v10;
    goto LABEL_7;
  }
  v11 = UFG::SimObject::GetComponentOfType(v6, UFG::CompositeDrawableComponent::_TypeUID);
  if ( v11 )
  {
    v10 = *(UFG::qResourceData **)&v11[21].m_TypeUID;
    goto LABEL_6;
  }
LABEL_7:
  hkTransformf::set4x4ColumnMajor(&transform, &v9->mWorldTransform.v0.x);
  hkQsTransformf::setFromTransformNoScale(&v116, &transform);
  pos.m_quad = (__m128)v116.m_translation;
  v12 = _mm_mul_ps(v116.m_rotation.m_vec.m_quad, v116.m_rotation.m_vec.m_quad);
  v13 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 78), v12);
  v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 177), v13);
  v15 = _mm_rsqrt_ps(v14);
  orient.m_vec.m_quad = _mm_mul_ps(
                          v116.m_rotation.m_vec.m_quad,
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
                            _mm_mul_ps(v15, *(__m128 *)_xmm)));
  v16 = 0i64;
  v108 = 0i64;
  v17 = 0;
  v107 = 0i64;
  v18 = 0i64;
  v106 = 0i64;
  v19 = 0;
  v20 = *(_DWORD *)(v8 + 88);
  if ( v20 )
  {
    v21 = *(_QWORD *)(v8 + 112);
    v22 = v20;
    do
    {
      if ( !(*(_BYTE *)(*(_QWORD *)v21 + 88i64) & 1) )
        ++v19;
      v21 += 8i64;
      --v22;
    }
    while ( v22 );
    if ( v19 > 1 )
    {
      v23 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x78ui64, "MultiBodyComponent", 0i64, 1u);
      *(_QWORD *)&name[0].mUID = v23;
      if ( v23 )
      {
        UFG::MultiBodyComponent::MultiBodyComponent((UFG::MultiBodyComponent *)v23, v6->mNode.mUID);
        v18 = v24;
      }
      else
      {
        v18 = 0i64;
      }
      v106 = v18;
    }
  }
  v25 = 0;
  pos.m_quad.m128_i32[0] = 0;
  if ( *(_DWORD *)(v8 + 88) )
  {
    while ( 1 )
    {
      v26 = *(UFG::CollisionMeshData **)(*(_QWORD *)(v8 + 112) + 8i64 * v25);
      v27 = 0i64;
      if ( v26->mFlags & 1 )
        goto LABEL_69;
      if ( v26->mShape->m_type.m_storage == 8 )
      {
        v28 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v26->mName);
        UFG::qPrintf("cloning CollisionMeshData %s\n", v28);
        v26 = UFG::CollisionMeshData::Clone(v26);
      }
      v29 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x70ui64, "CollisionInstanceData", 0i64, 1u);
      *(_QWORD *)&name[0].mUID = v29;
      if ( v29 )
      {
        UFG::CollisionInstanceData::CollisionInstanceData((UFG::CollisionInstanceData *)v29);
        v31 = v30;
      }
      else
      {
        v31 = 0i64;
      }
      collisionModelGuid = v26->mNode.mUID;
      v109 = name;
      name[0] = v26->mName;
      UFG::CollisionInstanceData::Set(v31, name[0].mUID, 0, (__int64)name, &pos, &orient, collisionModelGuid);
      name[0].mUID = 1024;
      v33 = v26->mObjectProperties.mData;
      if ( !BYTE4(v33[1].mHandles.mNode.mPrev) )
        break;
      v34 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x2D8ui64, "WaterPhantomComponent", 0i64, 1u);
      *(_QWORD *)&name[0].mUID = v34;
      if ( v34 )
      {
        UFG::WaterPhantomComponent::WaterPhantomComponent((UFG::WaterPhantomComponent *)v34, v31);
        v36 = v35;
      }
      else
      {
        v36 = 0i64;
      }
      UFG::SimObjectModifier::SimObjectModifier(&v113, v6, 1);
      UFG::SimObjectModifier::AttachComponent(&v113, v36, 0xFFFFFFFFi64);
      UFG::SimObjectModifier::Close(&v113);
      UFG::SimObjectModifier::~SimObjectModifier(&v113);
LABEL_87:
      v25 = pos.m_quad.m128_i32[0] + 1;
      pos.m_quad.m128_i32[0] = v25;
      v8 = pos.m_quad.m128_u64[1];
      v18 = v106;
      if ( v25 >= *(_DWORD *)(pos.m_quad.m128_u64[1] + 88) )
        goto LABEL_88;
    }
    if ( !LODWORD(v33[2].mBaseNode.mNeighbours[0]) )
    {
      if ( v18 )
        v18->mFlags |= 1u;
      else
        name[0].mUID = 1025;
    }
    v37 = -1;
    if ( v104 )
    {
      v37 = Skeleton::GetBoneID((Skeleton *)v104[3].mNode.mParent, v26->mRenderModelGuid);
      if ( v37 != -1
        || (v38 = v26->mPartDetails.mOffset) != 0
        && (v39 = (signed __int64)&v26->mPartDetails + v38) != 0
        && (v37 = Skeleton::GetBoneID((Skeleton *)v104[3].mNode.mParent, *(_DWORD *)(v39 + 80)), v37 != -1) )
      {
        v40 = (__m128 *)(*(_QWORD *)&v104[1].mNode.mChild[0][1].mUID + 48i64 * v37);
        v41 = _mm_shuffle_ps(v116.m_rotation.m_vec.m_quad, v116.m_rotation.m_vec.m_quad, 255);
        v42 = _mm_mul_ps(v116.m_rotation.m_vec.m_quad, *v40);
        v43 = _mm_shuffle_ps(v116.m_rotation.m_vec.m_quad, v116.m_rotation.m_vec.m_quad, 201);
        v44 = _mm_sub_ps(
                _mm_mul_ps(v116.m_rotation.m_vec.m_quad, _mm_shuffle_ps(*v40, *v40, 201)),
                _mm_mul_ps(*v40, v43));
        v45 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(*v40, _mm_sub_ps(_mm_mul_ps(v41, v41), (__m128)xmmword_141A711B0)),
                  _mm_mul_ps(
                    v116.m_rotation.m_vec.m_quad,
                    _mm_add_ps(
                      _mm_shuffle_ps(v42, v42, 170),
                      _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0))))),
                _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), v41));
        v46 = _mm_add_ps(v116.m_translation.m_quad, _mm_add_ps(v45, v45));
        v47 = v40[1];
        v48 = _mm_shuffle_ps(v47, v47, 255);
        v49 = _mm_sub_ps(
                _mm_mul_ps(v116.m_rotation.m_vec.m_quad, _mm_shuffle_ps(v40[1], v47, 201)),
                _mm_mul_ps(v40[1], v43));
        v50 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v49, v49, 201), _mm_mul_ps(v40[1], v41)),
                _mm_mul_ps(v116.m_rotation.m_vec.m_quad, v48));
        v51 = _mm_mul_ps(v116.m_rotation.m_vec.m_quad, v47);
        v52 = _mm_shuffle_ps(
                v50,
                _mm_unpackhi_ps(
                  v50,
                  _mm_sub_ps(
                    _mm_mul_ps(v48, v41),
                    _mm_add_ps(
                      _mm_shuffle_ps(v51, v51, 170),
                      _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0))))),
                196);
        v53 = _mm_shuffle_ps(v46, _mm_unpackhi_ps(v46, *(__m128 *)_xmm), 196);
        v54 = _mm_mul_ps(v52, v52);
        v55 = _mm_add_ps(v54, _mm_shuffle_ps(v54, v54, 78));
        v56 = _mm_add_ps(_mm_shuffle_ps(v55, v55, 177), v55);
        v57 = _mm_rsqrt_ps(v56);
        v58 = _mm_mul_ps(
                v52,
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v57, v56), v57)),
                  _mm_mul_ps(v57, *(__m128 *)_xmm)));
        v31->mPosition.m_quad = v53;
        v31->mInitialPosition.m_quad = v53;
        v31->mOrientation.m_vec.m_quad = v58;
        v31->mInitialOrientation.m_vec.m_quad = v58;
      }
    }
    v59 = (UFG::RigidBodyComponent *)UFG::RigidBodyComponent::mAllocator.mFreeListHead;
    if ( UFG::RigidBodyComponent::mAllocator.mFreeListHead )
    {
      UFG::RigidBodyComponent::mAllocator.mFreeListHead = *(char **)UFG::RigidBodyComponent::mAllocator.mFreeListHead;
      v60 = UFG::RigidBodyComponent::mAllocator.mNumSlotsAllocated + 1;
      UFG::RigidBodyComponent::mAllocator.mNumSlotsAllocated = v60;
      if ( UFG::RigidBodyComponent::mAllocator.mMostSlotsAllocated <= v60 )
        UFG::RigidBodyComponent::mAllocator.mMostSlotsAllocated = v60;
      v109 = v59;
    }
    else
    {
      v59 = (UFG::RigidBodyComponent *)UFG::qMemoryPool::Allocate(
                                         &gPhysicsMemoryPool,
                                         0x1D8ui64,
                                         "RigidBodyComponent",
                                         0i64,
                                         1u);
      v109 = v59;
    }
    if ( v59 )
    {
      UFG::RigidBodyComponent::RigidBodyComponent(v59, v26, v31, name[0].mUID, v37);
      v27 = v61;
    }
    else
    {
      v27 = 0i64;
    }
    if ( v27 )
    {
      UFG::SimObjectModifier::SimObjectModifier(&v111, v6, 1);
      UFG::SimObjectModifier::AttachComponent(&v111, (UFG::SimComponent *)&v27->vfptr, 0xFFFFFFFFi64);
      UFG::SimObjectModifier::Close(&v111);
      UFG::SimObjectModifier::~SimObjectModifier(&v111);
      LOBYTE(v62) = 1;
      v27->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v27->vfptr, v62);
      name[0].mUID = v17;
      v63 = v17 + 1;
      if ( v17 + 1 > HIDWORD(v107) )
      {
        v64 = 1;
        if ( HIDWORD(v107) )
          v64 = 2 * HIDWORD(v107);
        for ( ; v64 < v63; v64 *= 2 )
          ;
        if ( v64 <= 2 )
          v64 = 2;
        if ( v64 - v63 > 0x10000 )
          v64 = v17 + 65537;
        if ( v64 != v17 )
        {
          v65 = 8i64 * v64;
          if ( !is_mul_ok(v64, 8ui64) )
            v65 = -1i64;
          v66 = UFG::qMalloc(v65, "qArray.Add", 0i64);
          v109 = v66;
          if ( v16 )
          {
            if ( v17 )
            {
              v67 = v66;
              v68 = v17;
              do
              {
                v67->mNext = *(UFG::allocator::free_link **)((char *)v67 + (char *)v16 - (char *)v66);
                ++v67;
                --v68;
              }
              while ( v68 );
            }
            operator delete[](v16);
            v66 = (UFG::allocator::free_link *)v109;
          }
          v16 = v66;
          v108 = v66;
          HIDWORD(v107) = v64;
        }
      }
      ++v17;
      LODWORD(v107) = v63;
      v16[name[0].mUID].mNext = (UFG::allocator::free_link *)v27;
    }
    if ( v106 )
      UFG::MultiBodyComponent::AddBody(v106, v27);
LABEL_69:
    v69 = v26->mCustomDataSlotIndex;
    if ( v69 != -1 )
    {
      v70 = *(_QWORD *)(v119 + 112) + 16i64 * v69;
      v71 = 0i64;
      if ( *(_DWORD *)(v70 + 8) )
      {
        do
        {
          UFG::qReflectHandleBase::qReflectHandleBase(
            (UFG::qReflectHandleBase *)&transform,
            (UFG::qReflectHandleBase *)(*(_QWORD *)v70 + 40 * v71));
          v72 = *(_QWORD *)(transform.m_rotation.m_col2.m_quad.m128_u64[0] + 56);
          if ( v72 == UFG::qStringHash64("UFG::StateMachineDefinition", 0xFFFFFFFFFFFFFFFFui64) )
          {
            v73 = *(_QWORD *)(*(_QWORD *)v70 + 40 * v71 + 32);
            v74 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x120ui64, "StateMachineComponent", 0i64, 1u);
            *(_QWORD *)&name[0].mUID = v74;
            if ( v74 )
            {
              UFG::StateMachineComponent::StateMachineComponent(
                (UFG::StateMachineComponent *)v74,
                *(_QWORD *)(v73 + 8),
                -1);
              v76 = v75;
            }
            else
            {
              v76 = 0i64;
            }
            v77 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v76[1].m_Flags;
            if ( v76[1].m_BoundComponentHandles.mNode.mPrev )
            {
              v78 = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)v77->mPrev;
              v79 = v76[1].m_pSimObject;
              v78[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimObject> *, unsigned int))v79;
              v79->vfptr = v78;
              v77->mPrev = v77;
              v76[1].m_pSimObject = (UFG::SimObject *)&v76[1].m_Flags;
            }
            v76[1].m_BoundComponentHandles.mNode.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v27;
            if ( v27 )
            {
              v80 = v27->m_SafePointerList.mNode.mPrev;
              v80->mNext = v77;
              v77->mPrev = v80;
              v76[1].m_pSimObject = (UFG::SimObject *)&v27->m_SafePointerList;
              v27->m_SafePointerList.mNode.mPrev = v77;
            }
            v81 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27[1].mUserData.simComponent.mNext;
            if ( v27[1].mCollisionMeshBundle.mPrev )
            {
              v82 = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v81->mPrev;
              v83 = v27[1].mUserData.simComponent.m_pPointer;
              v82[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v83;
              v83->vfptr = v82;
              v81->mPrev = v81;
              v27[1].mUserData.simComponent.m_pPointer = (UFG::SimComponent *)&v27[1].mUserData.simComponent.mNext;
            }
            v27[1].mCollisionMeshBundle.mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)v76;
            if ( v76 )
            {
              v84 = v76->m_SafePointerList.mNode.mPrev;
              v84->mNext = v81;
              v81->mPrev = v84;
              v27[1].mUserData.simComponent.m_pPointer = (UFG::SimComponent *)((char *)v76 + 8);
              v76->m_SafePointerList.mNode.mPrev = v81;
              v27->mFlags |= 0x4000u;
            }
            else
            {
              v27->mFlags &= 0xFFFFBFFF;
            }
            UFG::SimObjectModifier::SimObjectModifier(&v111, v6, 1);
            UFG::SimObjectModifier::AttachComponent(&v111, v76, 0xFFFFFFFFi64);
            UFG::SimObjectModifier::Close(&v111);
            UFG::SimObjectModifier::~SimObjectModifier(&v111);
          }
          UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&transform);
          v71 = (unsigned int)(v71 + 1);
        }
        while ( (unsigned int)v71 < *(_DWORD *)(v70 + 8) );
        v17 = v107;
        v16 = v108;
      }
    }
    goto LABEL_87;
  }
LABEL_88:
  v85 = *(_QWORD *)(v119 + 112);
  v105 = v85;
  v86 = 0i64;
  name[0].mUID = 0;
  if ( *(_DWORD *)(v85 + 8) )
  {
    do
    {
      v87 = 5 * v86;
      UFG::qReflectHandleBase::qReflectHandleBase(
        (UFG::qReflectHandleBase *)&v111,
        (UFG::qReflectHandleBase *)(*(_QWORD *)v85 + 40 * v86));
      v89 = UFG::qReflectObjectType<UFG::ConstraintDef,UFG::qReflectObject>::GetTypeName(v88);
      v90 = UFG::qStringHash64(v89, 0xFFFFFFFFFFFFFFFFui64);
      v91 = *((_QWORD *)v109 + 7);
      v92 = UFG::ReflectionDB::Instance();
      if ( UFG::ReflectionDB::IsDerivedFrom(v92, v91, v90) )
      {
        v93 = *(_QWORD *)(*(_QWORD *)v105 + 8 * v87 + 32);
        v94 = 0i64;
        v95 = 0i64;
        v96 = 0i64;
        v97 = 0i64;
        v98 = 0i64;
        if ( v17 )
        {
          do
          {
            v99 = v16[v98].mNext;
            v100 = v99[20].mNext;
            if ( LODWORD(v100[27].mNext) == *(_DWORD *)(v93 + 84) )
            {
              v94 = (hkpRigidBody *)v99[21].mNext;
              v96 = (UFG::RigidBody *)v16[v98].mNext;
            }
            else if ( LODWORD(v100[27].mNext) == *(_DWORD *)(v93 + 88) )
            {
              v95 = (hkpRigidBody *)v99[21].mNext;
              v97 = (UFG::RigidBody *)v16[v98].mNext;
            }
            if ( v94 && v95 )
              break;
            v98 = (unsigned int)(v98 + 1);
          }
          while ( (unsigned int)v98 < v17 );
          if ( v94 )
          {
            v101 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x60ui64, "Constraint", 0i64, 1u);
            pos.m_quad.m128_u64[1] = (unsigned __int64)v101;
            if ( v101 )
            {
              v109 = &transform;
              UFG::qReflectHandleBase::qReflectHandleBase(
                (UFG::qReflectHandleBase *)&transform,
                (UFG::qReflectHandleBase *)&v111);
              UFG::Constraint::Constraint(
                (UFG::Constraint *)v101,
                (UFG::qReflectHandle<UFG::qReflectObject> *)&transform,
                v94,
                v95);
              v103 = v102;
            }
            else
            {
              v103 = 0i64;
            }
            UFG::BasePhysicsSystem::AddConstraint(v117, v103->mConstraintInstance);
            UFG::RigidBody::AddConstraint(v96, v103);
            if ( v97 )
              UFG::RigidBody::AddConstraint(v97, v103);
            if ( v106 )
              UFG::MultiBodyComponent::AddConstraint(v106, v103);
          }
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v111);
      v86 = name[0].mUID + 1;
      name[0].mUID = v86;
      v85 = v105;
    }
    while ( (unsigned int)v86 < *(_DWORD *)(v105 + 8) );
  }
  if ( v106 )
    UFG::MultiBodyComponent::UpdateCollisionFiltersForConstraints(v106);
  if ( v16 )
    operator delete[](v16);
}

// File Line: 1195
// RVA: 0x455670
void __fastcall UFG::PhysicsSystem::AddRenderHelper(UFG::PhysicsSystem *this, UFG::SimObject *simObject, UFG::RigidBodyComponent *rbc, UFG::CollisionInstanceData *instance, UFG::CollisionMeshData *mesh)
{
  UFG::CollisionInstanceData *v5; // rdi
  UFG::RigidBodyComponent *v6; // rsi
  UFG::SimObject *v7; // rbx
  unsigned __int16 v8; // cx
  UFG::SimComponent *v9; // rax
  UFG::qMemoryPool *v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::SimComponent *v12; // rax
  UFG::SimComponent *v13; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsRenderHelper> *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::SimObjectModifier v18; // [rsp+38h] [rbp-30h]

  if ( rbc )
  {
    v5 = instance;
    v6 = rbc;
    v7 = simObject;
    if ( !simObject
      || ((v8 = simObject->m_Flags, !((v8 >> 14) & 1)) ? ((v8 & 0x8000u) == 0 ? (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v9 = UFG::SimObject::GetComponentOfType(simObject, UFG::CompositeDrawableComponent::_TypeUID)) : (v9 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)simObject, UFG::CompositeDrawableComponent::_TypeUID))) : (v9 = simObject->m_Components.p[9].m_pComponent)) : (v9 = simObject->m_Components.p[14].m_pComponent)) : (v9 = simObject->m_Components.p[14].m_pComponent),
          !v9) )
    {
      v10 = UFG::GetSimulationMemoryPool();
      v11 = UFG::qMemoryPool::Allocate(v10, 0x68ui64, "SimComponent", 0i64, 1u);
      if ( v11 )
      {
        UFG::PhysicsRenderHelper::PhysicsRenderHelper((UFG::PhysicsRenderHelper *)v11, v5, mesh);
        v13 = v12;
      }
      else
      {
        v13 = 0i64;
      }
      v14 = &v6->mRenderComponent;
      if ( v6->mRenderComponent.m_pPointer )
      {
        v15 = v14->mPrev;
        v16 = v6->mRenderComponent.mNext;
        v15->mNext = v16;
        v16->mPrev = v15;
        v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
        v6->mRenderComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mRenderComponent.mPrev;
      }
      v6->mRenderComponent.m_pPointer = v13;
      if ( v13 )
      {
        v17 = v13->m_SafePointerList.mNode.mPrev;
        v17->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
        v14->mPrev = v17;
        v6->mRenderComponent.mNext = &v13->m_SafePointerList.mNode;
        v13->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
      }
      UFG::SimObjectModifier::SimObjectModifier(&v18, v7, 1);
      UFG::SimObjectModifier::AttachComponent(&v18, v13, 0xFFFFFFFFi64);
      UFG::SimObjectModifier::Close(&v18);
      UFG::SimObjectModifier::~SimObjectModifier(&v18);
    }
  }
}

// File Line: 1212
// RVA: 0x455060
void __fastcall UFG::PhysicsSystem::AddParkourAndCover(UFG::PhysicsSystem *this, UFG::SimObject *simObject, UFG::RigidBodyComponent *rbc, UFG::CollisionMeshData *mesh, int followBone)
{
  UFG::CollisionMeshData *v5; // rbp
  UFG::RigidBodyComponent *v6; // rsi
  UFG::SimObject *v7; // r14
  unsigned int v8; // edi
  UFG::SimComponent *v9; // rbx
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::ParkourComponent> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  unsigned int v17; // edi
  UFG::allocator::free_link *v18; // rax
  UFG::SimComponent *v19; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::DynamicCoverComponent> *v20; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::SimObjectModifier v24; // [rsp+28h] [rbp-40h]

  v5 = mesh;
  v6 = rbc;
  v7 = simObject;
  v8 = mesh->mParkourGuid;
  v9 = 0i64;
  if ( v8 )
  {
    v10 = UFG::qMalloc(0xC8ui64, "ParkourComponent", 0x800ui64);
    if ( v10 )
    {
      UFG::ParkourComponent::ParkourComponent((UFG::ParkourComponent *)v10, v8, followBone);
      v12 = v11;
    }
    else
    {
      v12 = 0i64;
    }
    v13 = &v6->mParkourComponent;
    if ( v6->mParkourComponent.m_pPointer )
    {
      v14 = v13->mPrev;
      v15 = v6->mParkourComponent.mNext;
      v14->mNext = v15;
      v15->mPrev = v14;
      v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
      v6->mParkourComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mParkourComponent.mPrev;
    }
    v6->mParkourComponent.m_pPointer = v12;
    if ( v12 )
    {
      v16 = v12->m_SafePointerList.mNode.mPrev;
      v16->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
      v13->mPrev = v16;
      v6->mParkourComponent.mNext = &v12->m_SafePointerList.mNode;
      v12->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v24, v7, 1);
    UFG::SimObjectModifier::AttachComponent(&v24, v12, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v24);
    UFG::SimObjectModifier::~SimObjectModifier(&v24);
  }
  v17 = v5->mCoverGuid;
  if ( v17 )
  {
    v18 = UFG::qMalloc(0x88ui64, "DynamicCoverComponent", 0x800ui64);
    if ( v18 )
    {
      UFG::DynamicCoverComponent::DynamicCoverComponent((UFG::DynamicCoverComponent *)v18, v17);
      v9 = v19;
    }
    v20 = &v6->mCoverComponent;
    if ( v6->mCoverComponent.m_pPointer )
    {
      v21 = v20->mPrev;
      v22 = v6->mCoverComponent.mNext;
      v21->mNext = v22;
      v22->mPrev = v21;
      v20->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v20->mPrev;
      v6->mCoverComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mCoverComponent.mPrev;
    }
    v6->mCoverComponent.m_pPointer = v9;
    if ( v9 )
    {
      v23 = v9->m_SafePointerList.mNode.mPrev;
      v23->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v20->mPrev;
      v20->mPrev = v23;
      v6->mCoverComponent.mNext = &v9->m_SafePointerList.mNode;
      v9->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v20->mPrev;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v24, v7, 1);
    UFG::SimObjectModifier::AttachComponent(&v24, v9, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v24);
    UFG::SimObjectModifier::~SimObjectModifier(&v24);
  }
}

// File Line: 1233
// RVA: 0x455930
void __fastcall UFG::PhysicsSystem::AddStateMachines(UFG::PhysicsSystem *this, UFG::SimObject *simObject, UFG::RigidBodyComponent *rbc, UFG::CollisionInstanceData *instance, UFG::CollisionMeshData *mesh)
{
  UFG::CollisionInstanceData *v5; // r14
  UFG::RigidBodyComponent *v6; // r15
  UFG::SimObject *v7; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v8; // rcx
  const char *v9; // rax
  UFG::CollisionMeshData *v10; // rdx
  UFG::StateMachineComponent *v11; // rbx
  unsigned int v12; // edx
  UFG::qBaseTreeRB *v13; // rax
  unsigned __int64 v14; // rdi
  UFG::allocator::free_link *v15; // rax
  UFG::StateMachineComponent *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBodyComponent> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  unsigned __int64 v21; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v22; // rcx
  const char *v23; // rax
  unsigned int v24; // edx
  unsigned int v25; // er14
  UFG::qOffset64<UFG::CollisionMeshData::Part *> *v26; // r13
  __int64 v27; // r12
  char *v28; // rdi
  unsigned __int64 v29; // rdi
  unsigned int v30; // edx
  UFG::qBaseTreeRB *v31; // rax
  UFG::allocator::free_link *v32; // rax
  UFG::StateMachineComponent *v33; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBodyComponent> *v34; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v37; // rax
  UFG::allocator::free_link *v38; // rax
  UFG::StateMachineComponent *v39; // rax
  UFG::StateMachineComponent *v40; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBodyComponent> *v41; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v42; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v43; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v44; // rax
  unsigned int v45; // [rsp+30h] [rbp-91h]
  unsigned __int64 v46; // [rsp+38h] [rbp-89h]
  UFG::SimObjectModifier v47; // [rsp+40h] [rbp-81h]
  UFG::qReflectHandleBase v48; // [rsp+60h] [rbp-61h]
  UFG::qReflectHandleBase v49; // [rsp+88h] [rbp-39h]
  __int64 v50; // [rsp+B0h] [rbp-11h]
  UFG::qReflectHandleBase v51; // [rsp+B8h] [rbp-9h]
  UFG::SimObject *simObjecta; // [rsp+128h] [rbp+67h]

  if ( rbc )
  {
    simObjecta = simObject;
    v50 = -2i64;
    v5 = instance;
    v6 = rbc;
    v7 = simObject;
    UFG::qReflectHandleBase::qReflectHandleBase(&v51);
    v9 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v8);
    v51.mTypeUID = UFG::qStringHash64(v9, 0xFFFFFFFFFFFFFFFFui64);
    v10 = v6->mCollisionMeshData;
    if ( v10 )
      UFG::qReflectHandleBase::operator=(&v51, (UFG::qReflectHandleBase *)&v10->mObjectProperties.mPrev);
    v11 = 0i64;
    v12 = HIDWORD(v51.mData[4].mBaseNode.mParent);
    if ( v12 )
    {
      v13 = UFG::qBaseTreeRB::Get(&UFG::StateMachineDefinition::mGuidTranslation.mTree, v12);
      if ( v13 )
      {
        v14 = (unsigned __int64)v13->mNULL.mParent;
        if ( v14 )
        {
          v15 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x120ui64, "StateMachineComponent", 0i64, 1u);
          if ( v15 )
          {
            UFG::StateMachineComponent::StateMachineComponent((UFG::StateMachineComponent *)v15, v14, -1);
            v11 = v16;
          }
          else
          {
            v11 = 0i64;
          }
          v17 = &v11->mRigidBodyComponent;
          if ( v11->mRigidBodyComponent.m_pPointer )
          {
            v18 = v17->mPrev;
            v19 = v11->mRigidBodyComponent.mNext;
            v18->mNext = v19;
            v19->mPrev = v18;
            v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
            v11->mRigidBodyComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mRigidBodyComponent.mPrev;
          }
          v11->mRigidBodyComponent.m_pPointer = (UFG::SimComponent *)&v6->vfptr;
          v20 = v6->m_SafePointerList.mNode.mPrev;
          v20->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
          v17->mPrev = v20;
          v11->mRigidBodyComponent.mNext = &v6->m_SafePointerList.mNode;
          v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
          UFG::RigidBodyComponent::SetStateMachineComponent(v6, v11);
          UFG::SimObjectModifier::SimObjectModifier(&v47, v7, 1);
          UFG::SimObjectModifier::AttachComponent(&v47, (UFG::SimComponent *)&v11->vfptr, 0xFFFFFFFFi64);
          UFG::SimObjectModifier::Close(&v47);
          UFG::SimObjectModifier::~SimObjectModifier(&v47);
        }
      }
    }
    v46 = 0i64;
    v21 = 0i64;
    UFG::qReflectHandleBase::qReflectHandleBase(&v49);
    v23 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v22);
    v49.mTypeUID = UFG::qStringHash64(v23, 0xFFFFFFFFFFFFFFFFui64);
    v24 = mesh->mNumParts;
    if ( v5->mNumParts < v24 )
      v24 = v5->mNumParts;
    v45 = v24;
    v25 = 0;
    if ( v24 )
    {
      v26 = &mesh->mParts;
      v27 = 0i64;
      do
      {
        if ( v26->mOffset )
          v28 = (char *)v26 + v26->mOffset;
        else
          v28 = 0i64;
        v29 = *(_QWORD *)&v28[v27 + 16];
        if ( v46 != v29 )
        {
          UFG::qReflectHandleBase::Init(&v49, v49.mTypeUID, v29);
          v46 = v29;
          v30 = HIDWORD(v49.mData[4].mBaseNode.mParent);
          if ( !v30 || (v31 = UFG::qBaseTreeRB::Get(&UFG::StateMachineDefinition::mGuidTranslation.mTree, v30)) == 0i64 )
          {
            v21 = 0i64;
LABEL_41:
            v24 = v45;
            goto LABEL_42;
          }
          v21 = (unsigned __int64)v31->mNULL.mParent;
          v24 = v45;
        }
        if ( v21 )
        {
          UFG::qReflectHandleBase::qReflectHandleBase(&v48);
          v48.mTypeUID = UFG::qStringHash64("UFG::StateMachineDefinition", 0xFFFFFFFFFFFFFFFFui64);
          UFG::qReflectHandleBase::Init(&v48, v48.mTypeUID, v21);
          if ( BYTE2(v48.mData[1].mBaseNode.mNeighbours[0]) )
          {
            if ( !v11 )
            {
              v32 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x120ui64, "StateMachineComponent", 0i64, 1u);
              if ( v32 )
              {
                UFG::StateMachineComponent::StateMachineComponent((UFG::StateMachineComponent *)v32, 0i64, -1);
                v11 = v33;
              }
              else
              {
                v11 = 0i64;
              }
              v34 = &v11->mRigidBodyComponent;
              if ( v11->mRigidBodyComponent.m_pPointer )
              {
                v35 = v34->mPrev;
                v36 = v11->mRigidBodyComponent.mNext;
                v35->mNext = v36;
                v36->mPrev = v35;
                v34->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v34->mPrev;
                v11->mRigidBodyComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mRigidBodyComponent.mPrev;
              }
              v11->mRigidBodyComponent.m_pPointer = (UFG::SimComponent *)&v6->vfptr;
              v37 = v6->m_SafePointerList.mNode.mPrev;
              v37->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v34->mPrev;
              v34->mPrev = v37;
              v11->mRigidBodyComponent.mNext = &v6->m_SafePointerList.mNode;
              v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v34->mPrev;
              UFG::RigidBodyComponent::SetStateMachineComponent(v6, v11);
              UFG::SimObjectModifier::SimObjectModifier(&v47, simObjecta, 1);
              UFG::SimObjectModifier::AttachComponent(&v47, (UFG::SimComponent *)&v11->vfptr, 0xFFFFFFFFi64);
              UFG::SimObjectModifier::Close(&v47);
              UFG::SimObjectModifier::~SimObjectModifier(&v47);
            }
            v38 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x120ui64, "StateMachineComponent", 0i64, 1u);
            if ( v38 )
            {
              UFG::StateMachineComponent::StateMachineComponent((UFG::StateMachineComponent *)v38, v21, v25);
              v40 = v39;
            }
            else
            {
              v40 = 0i64;
            }
            v41 = &v40->mRigidBodyComponent;
            if ( v40->mRigidBodyComponent.m_pPointer )
            {
              v42 = v41->mPrev;
              v43 = v40->mRigidBodyComponent.mNext;
              v42->mNext = v43;
              v43->mPrev = v42;
              v41->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v41->mPrev;
              v40->mRigidBodyComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v40->mRigidBodyComponent.mPrev;
            }
            v40->mRigidBodyComponent.m_pPointer = (UFG::SimComponent *)&v6->vfptr;
            v44 = v6->m_SafePointerList.mNode.mPrev;
            v44->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v41->mPrev;
            v41->mPrev = v44;
            v40->mRigidBodyComponent.mNext = &v6->m_SafePointerList.mNode;
            v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v41->mPrev;
            UFG::StateMachineComponent::AddChildMachine(v11, v40);
          }
          UFG::qReflectHandleBase::~qReflectHandleBase(&v48);
          goto LABEL_41;
        }
LABEL_42:
        ++v25;
        v27 += 48i64;
      }
      while ( v25 < v24 );
    }
    UFG::qReflectHandleBase::~qReflectHandleBase(&v49);
    UFG::qReflectHandleBase::~qReflectHandleBase(&v51);
  }
}

// File Line: 1303
// RVA: 0x46C700
void __fastcall UFG::PhysicsSystem::ManageActiveRegions(UFG::PhysicsSystem *this)
{
  UFG::PhysicsSystem *v1; // r13
  char *v2; // rcx
  UFG::RigidBody *v3; // rdi
  unsigned int v4; // eax
  bool v5; // cl
  unsigned int v6; // er14
  UFG::CollisionMeshData *v7; // r15
  hkpRigidBody *v8; // rax
  hkVector4f v9; // xmm1
  hkVector4f v10; // xmm2
  hkVector4f v11; // xmm3
  unsigned int v12; // esi
  __int64 v13; // rbx
  UFG::CollisionInstanceData::Part *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  unsigned int v17; // eax
  __int64 v18; // rdx
  unsigned int v19; // er12
  __int64 v20; // rcx
  hkpRigidBody *v21; // rax
  hkVector4f v22; // xmm1
  hkVector4f v23; // xmm2
  hkVector4f v24; // xmm3
  BOOL v25; // er13
  unsigned __int16 v26; // r15
  unsigned int v27; // esi
  signed __int64 v28; // rbx
  __int64 v29; // rax
  signed __int64 v30; // rdx
  UFG::qSymbol *v31; // r14
  UFG::qPropertySet *v32; // rsi
  UFG::SimObject *v33; // rax
  __int64 v34; // rdx
  _QWORD *v35; // rcx
  _QWORD *v36; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v37; // rax
  signed __int64 v38; // [rsp+30h] [rbp-D0h]
  hkTransformf a; // [rsp+40h] [rbp-C0h]
  hkVector4f v40; // [rsp+80h] [rbp-80h]
  hkVector4f p; // [rsp+90h] [rbp-70h]
  hkVector4f v42; // [rsp+A0h] [rbp-60h]
  __int64 v43; // [rsp+B0h] [rbp-50h]
  hkTransformf transformOut; // [rsp+C0h] [rbp-40h]
  UFG::qString v45; // [rsp+100h] [rbp+0h]
  hkTransformf v46; // [rsp+130h] [rbp+30h]
  float d; // [rsp+170h] [rbp+70h]
  UFG::PhysicsSystem *v48; // [rsp+200h] [rbp+100h]
  UFG::qSymbol name; // [rsp+208h] [rbp+108h]
  char *v50; // [rsp+210h] [rbp+110h]
  __int64 v51; // [rsp+218h] [rbp+118h]

  v48 = this;
  v43 = -2i64;
  v1 = this;
  v2 = (char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280;
  v50 = (char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280;
  v3 = (UFG::RigidBody *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
  if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
  {
    do
    {
      v38 = (signed __int64)&v3[1].m_SafePointerList.mNode.mPrev[-18].mNext;
      v4 = v3->mFlags;
      if ( !(v4 & 8) )
      {
        if ( v4 & 1 )
        {
          if ( v4 & 2 )
          {
            v5 = (v4 & 0x80u) != 0 && !UFG::RigidBody::IsSleeping(v3);
            p.m_quad = (__m128)v3->mBody->m_motion.m_motionState.m_transform.m_translation;
            if ( (!v5 || v3->mWindAction) && !UFG::ActiveRegionManager::IsInActiveRegion(&v1->mActiveRegionManager, &p) )
              ((void (__fastcall *)(UFG::RigidBody *))v3->vfptr[16].__vecDelDtor)(v3);
            v2 = v50;
          }
        }
        else if ( v4 & 2 )
        {
          v6 = v3->mInstanceData->mNumParts;
          if ( v6 )
          {
            v7 = v3->mCollisionMeshData;
            v8 = v3->mBody;
            v9.m_quad = (__m128)v8->m_motion.m_motionState.m_transform.m_rotation.m_col1;
            v10.m_quad = (__m128)v8->m_motion.m_motionState.m_transform.m_rotation.m_col2;
            v11.m_quad = (__m128)v8->m_motion.m_motionState.m_transform.m_translation;
            a.m_rotation.m_col0 = v8->m_motion.m_motionState.m_transform.m_rotation.m_col0;
            a.m_rotation.m_col1 = (hkVector4f)v9.m_quad;
            a.m_rotation.m_col2 = (hkVector4f)v10.m_quad;
            a.m_translation = (hkVector4f)v11.m_quad;
            v12 = 0;
            if ( v6 )
            {
              v13 = 0i64;
              do
              {
                if ( v3->mInstanceData->mParts[v13].mSimObject.m_pPointer )
                {
                  UFG::GetTransformFromShapeKey(&transformOut, v7->mShape, v12);
                  hkVector4f::setTransformedPos(&v42, &a, &transformOut.m_translation);
                  if ( !UFG::ActiveRegionManager::IsInActiveRegion(&v1->mActiveRegionManager, &v42) )
                  {
                    UFG::Simulation::DestroySimObject(&UFG::gSim, v3->mInstanceData->mParts[v13].mSimObject.m_pPointer);
                    v14 = &v3->mInstanceData->mParts[v13];
                    if ( v14->mSimObject.m_pPointer )
                    {
                      v15 = v14->mSimObject.mPrev;
                      v16 = v14->mSimObject.mNext;
                      v15->mNext = v16;
                      v16->mPrev = v15;
                      v14->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mSimObject.mPrev;
                      v14->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mSimObject.mPrev;
                    }
                    v14->mSimObject.m_pPointer = 0i64;
                  }
                }
                ++v12;
                ++v13;
              }
              while ( v12 < v6 );
              v2 = v50;
            }
          }
        }
        v17 = v3->mFlags;
        if ( v17 & 1 && !(v17 & 2) )
        {
          if ( UFG::ActiveRegionManager::IsInActiveRegion(&v1->mActiveRegionManager, &v3->mInstanceData->mPosition) )
          {
            LOBYTE(v18) = 1;
            v3->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v3->vfptr, v18);
          }
LABEL_50:
          v2 = v50;
          goto LABEL_51;
        }
        v19 = v3->mInstanceData->mNumParts;
        if ( v19 )
        {
          v20 = (__int64)v3->mCollisionMeshData;
          v51 = v20;
          v21 = v3->mBody;
          v22.m_quad = (__m128)v21->m_motion.m_motionState.m_transform.m_rotation.m_col1;
          v23.m_quad = (__m128)v21->m_motion.m_motionState.m_transform.m_rotation.m_col2;
          v24.m_quad = (__m128)v21->m_motion.m_motionState.m_transform.m_translation;
          a.m_rotation.m_col0 = v21->m_motion.m_motionState.m_transform.m_rotation.m_col0;
          a.m_rotation.m_col1 = (hkVector4f)v22.m_quad;
          a.m_rotation.m_col2 = (hkVector4f)v23.m_quad;
          a.m_translation = (hkVector4f)v24.m_quad;
          LODWORD(v21) = *(_DWORD *)(v20 + 56);
          v25 = (_DWORD)v21 != v19;
          if ( v19 >= (unsigned int)v21 )
            v19 = *(_DWORD *)(v20 + 56);
          v26 = 0;
          if ( v19 )
          {
            v27 = 0;
            do
            {
              v28 = (signed __int64)&v3->mInstanceData->mParts[v26];
              v29 = *(_QWORD *)(v20 + 160);
              if ( v29 )
                v30 = v29 + v20 + 160;
              else
                v30 = 0i64;
              v31 = (UFG::qSymbol *)(v30 + 96i64 * (signed int)(v27 + v25));
              if ( v31[18].mUID != -1
                && !*(_QWORD *)(v28 + 16)
                && !(unsigned int)UFG::RigidBody::IsPartFractured(v3, v27 + v25) )
              {
                UFG::GetTransformFromShapeKey(&transformOut, *(hkpShape **)(v51 + 192), v27);
                hkVector4f::setTransformedPos(&v40, &a, &transformOut.m_translation);
                if ( UFG::ActiveRegionManager::IsInActiveRegion(&v48->mActiveRegionManager, &v40) )
                {
                  v32 = UFG::PropertySetManager::FindPropertySet(v31 + 18);
                  if ( v32 )
                  {
                    hkTransformf::setMul(&v46, &a, &transformOut);
                    hkTransformf::get4x4ColumnMajor(&v46, &d);
                    name.mUID = *(_DWORD *)(v28 + 24);
                    while ( UFG::Simulation::GetSimObject(&UFG::gSim, &name) )
                    {
                      ++count_2;
                      UFG::qString::qString(&v45, "Physics-%d");
                      UFG::qSymbol::set_from_cstr(&name, v45.mData);
                      UFG::qString::~qString(&v45);
                    }
                    v33 = UFG::SpawnInfoInterface::SpawnObject(&name, v32, (UFG::qMatrix44 *)&d, Count, 0i64, 0i64);
                    if ( *(_QWORD *)(v28 + 16) )
                    {
                      v34 = *(_QWORD *)v28;
                      v35 = *(_QWORD **)(v28 + 8);
                      *(_QWORD *)(v34 + 8) = v35;
                      *v35 = v34;
                      *(_QWORD *)v28 = v28;
                      *(_QWORD *)(v28 + 8) = v28;
                    }
                    *(_QWORD *)(v28 + 16) = v33;
                    if ( v33 )
                    {
                      v36 = &v33->m_SafePointerList.mNode.mPrev;
                      v37 = v33->m_SafePointerList.mNode.mPrev;
                      v37->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v28;
                      *(_QWORD *)v28 = v37;
                      *(_QWORD *)(v28 + 8) = v36;
                      *v36 = v28;
                    }
                  }
                }
              }
              v27 = ++v26;
              v20 = v51;
            }
            while ( v26 < v19 );
          }
          v1 = v48;
          goto LABEL_50;
        }
      }
LABEL_51:
      v3 = (UFG::RigidBody *)v38;
    }
    while ( (char *)v38 != v2 );
  }
}

// File Line: 1456
// RVA: 0x476590
void __fastcall UFG::PhysicsSystem::SuspendPhysicsComponents(UFG::PhysicsSystem *this, UFG::SimObject *simObject)
{
  unsigned __int16 v2; // cx
  UFG::SimObjectGame *v3; // rdi
  UFG::SimComponent *v4; // rax
  UFG::TransformNodeComponent *v5; // rbx
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rax
  UFG::TransformNodeComponent *v8; // rbx

  if ( simObject )
  {
    v2 = simObject->m_Flags;
    v3 = (UFG::SimObjectGame *)simObject;
    if ( (v2 >> 14) & 1 )
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)simObject, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)simObject,
               UFG::RigidBodyComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)simObject,
               UFG::RigidBodyComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType(simObject, UFG::RigidBodyComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)simObject, UFG::RigidBodyComponent::_TypeUID);
    }
    v5 = (UFG::TransformNodeComponent *)v4;
    if ( v4 )
    {
      do
      {
        ((void (__fastcall *)(UFG::TransformNodeComponent *))v5->vfptr[8].__vecDelDtor)(v5);
        v5 = UFG::SimObject::GetComponentOfType(
               v5->m_pSimObject,
               UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
               0,
               (UFG::SimComponent *)&v5->vfptr);
      }
      while ( v5 );
    }
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ParkourComponent::_TypeUID);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ParkourComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ParkourComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::ParkourComponent::_TypeUID);
      }
    }
    else
    {
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ParkourComponent::_TypeUID);
    }
    v8 = (UFG::TransformNodeComponent *)v7;
    if ( v7 )
    {
      do
      {
        ((void (__fastcall *)(UFG::TransformNodeComponent *))v8->vfptr[8].__vecDelDtor)(v8);
        v8 = UFG::SimObject::GetComponentOfType(
               v8->m_pSimObject,
               UFG::ParkourComponent::_ParkourComponentTypeUID,
               0,
               (UFG::SimComponent *)&v8->vfptr);
      }
      while ( v8 );
    }
  }
}

// File Line: 1475
// RVA: 0x474120
void __fastcall UFG::PhysicsSystem::RestorePhysicsComponents(UFG::PhysicsSystem *this, UFG::SimObject *simObject)
{
  unsigned __int16 v2; // cx
  UFG::SimObjectGame *v3; // rdi
  UFG::SimComponent *v4; // rax
  UFG::TransformNodeComponent *v5; // rbx
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rax
  UFG::TransformNodeComponent *v8; // rbx

  if ( simObject )
  {
    v2 = simObject->m_Flags;
    v3 = (UFG::SimObjectGame *)simObject;
    if ( (v2 >> 14) & 1 )
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)simObject, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)simObject,
               UFG::RigidBodyComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)simObject,
               UFG::RigidBodyComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType(simObject, UFG::RigidBodyComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)simObject, UFG::RigidBodyComponent::_TypeUID);
    }
    v5 = (UFG::TransformNodeComponent *)v4;
    if ( v4 )
    {
      do
      {
        ((void (__fastcall *)(UFG::TransformNodeComponent *))v5->vfptr[9].__vecDelDtor)(v5);
        v5 = UFG::SimObject::GetComponentOfType(
               v5->m_pSimObject,
               UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
               0,
               (UFG::SimComponent *)&v5->vfptr);
      }
      while ( v5 );
    }
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ParkourComponent::_TypeUID);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ParkourComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ParkourComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::ParkourComponent::_TypeUID);
      }
    }
    else
    {
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ParkourComponent::_TypeUID);
    }
    v8 = (UFG::TransformNodeComponent *)v7;
    if ( v7 )
    {
      do
      {
        ((void (__fastcall *)(UFG::TransformNodeComponent *))v8->vfptr[9].__vecDelDtor)(v8);
        v8 = UFG::SimObject::GetComponentOfType(
               v8->m_pSimObject,
               UFG::ParkourComponent::_ParkourComponentTypeUID,
               0,
               (UFG::SimComponent *)&v8->vfptr);
      }
      while ( v8 );
    }
  }
}

// File Line: 1494
// RVA: 0x47AAC0
void __fastcall UFG::PhysicsSystem::Update(UFG::PhysicsSystem *this, float timestep)
{
  float v2; // xmm8_4
  UFG::PhysicsSystem *v3; // rsi
  unsigned int *v4; // rbx
  UFG::qBaseTreeRB *i; // rdi
  unsigned int j; // ebx
  __m128 *v7; // rcx
  float v8; // eax
  __m128 v9; // xmm3
  __m128 v10; // xmm3
  __m128 v11; // xmm3
  __m128 v12; // xmm1
  float v13; // xmm4_4
  _QWORD *v14; // rcx
  UFG::SimObject *v15; // rdx
  __m128 v16; // xmm0
  __m128 v17; // xmm6
  __m128 v18; // xmm0
  __m128 v19; // xmm7
  __m128 v20; // xmm0
  hkArray<hkpEntity *,hkContainerHeapAllocator> entitiesToAdd; // [rsp+28h] [rbp-80h]
  hkVector4f centre; // [rsp+40h] [rbp-68h]
  hkVector4f result; // [rsp+50h] [rbp-58h]
  hkVector4f location; // [rsp+60h] [rbp-48h]

  v2 = timestep;
  v3 = this;
  if ( LocalPlayer )
  {
    v4 = (unsigned int *)LocalPlayer->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(LocalPlayer->m_pTransformNodeComponent);
    centre.m_quad = _mm_unpacklo_ps(
                      _mm_unpacklo_ps((__m128)v4[44], (__m128)v4[46]),
                      _mm_unpacklo_ps((__m128)v4[45], (__m128)(unsigned int)FLOAT_1_0));
    UFG::ActiveRegionManager::SetCentre(&v3->mActiveRegionManager, &centre);
  }
  UFG::BasePhysicsSystem::BeginRemoveEntityBatch((UFG::BasePhysicsSystem *)&v3->vfptr);
  UFG::ActiveRegionManager::GetCentre(&v3->mActiveRegionManager, &result);
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_14216D960);
        i;
        i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_14216D960, &i->mRoot) )
  {
    for ( j = 0; j < i[1].mRoot.mUID; ++j )
    {
      v7 = (__m128 *)*((_QWORD *)&i[1].mRoot.mChild[1]->mParent + j);
      v8 = v7[5].m128_f32[2];
      if ( LOBYTE(v8) & 1 )
      {
        if ( !(LOBYTE(v8) & 2) )
        {
          v9 = _mm_sub_ps(v7[2], result.m_quad);
          v10 = _mm_mul_ps(v9, v9);
          v11 = _mm_add_ps(
                  _mm_shuffle_ps(v10, v10, 170),
                  _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)));
          v12 = _mm_rsqrt_ps(v11);
          LODWORD(v13) = (unsigned __int128)_mm_andnot_ps(
                                              _mm_cmpleps(v11, (__m128)0i64),
                                              _mm_mul_ps(
                                                _mm_mul_ps(
                                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
                                                  _mm_mul_ps(*(__m128 *)_xmm, v12)),
                                                v11));
          v14 = (_QWORD *)v7[4].m128_u64[0];
          if ( v14 )
          {
            v15 = (UFG::SimObject *)v14[5];
            if ( v13 >= VERY_LOW_LOD_RADIUS.m_real.m128_f32[0] )
            {
              if ( v15 )
                UFG::PhysicsSystem::SuspendPhysicsComponents(v3, v15);
              else
                (*(void (__cdecl **)(_QWORD *))(*v14 + 64i64))(v14);
            }
            else if ( v15 )
            {
              UFG::PhysicsSystem::RestorePhysicsComponents(v3, v15);
            }
            else
            {
              (*(void (__cdecl **)(_QWORD *))(*v14 + 72i64))(v14);
            }
          }
        }
      }
    }
  }
  entitiesToAdd.m_data = 0i64;
  entitiesToAdd.m_size = 0;
  entitiesToAdd.m_capacityAndFlags = 2147483648;
  UFG::CharacterPhysicsComponentManager::GetEntitiesForBatchOperations(
    UFG::CharacterPhysicsComponentManager::mInstance,
    &entitiesToAdd,
    &v3->mEntitiesToRemove);
  if ( entitiesToAdd.m_size )
    hkpWorld::addEntityBatch(v3->mWorld, entitiesToAdd.m_data, entitiesToAdd.m_size, HK_ENTITY_ACTIVATION_DO_ACTIVATE);
  UFG::WorldCollisionListener::BeginFrame(UFG::WorldCollisionListener::mInstance);
  UFG::ExplosionManager::Update(v2);
  UFG::PhysicsSystem::ManageActiveRegions(v3);
  UFG::BasePhysicsSystem::EndRemoveEntityBatch((UFG::BasePhysicsSystem *)&v3->vfptr);
  entitiesToAdd.m_size = 0;
  if ( entitiesToAdd.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      entitiesToAdd.m_data,
      8 * entitiesToAdd.m_capacityAndFlags);
  entitiesToAdd.m_data = 0i64;
  entitiesToAdd.m_capacityAndFlags = 2147483648;
  UFG::BasePhysicsSystem::Update((UFG::BasePhysicsSystem *)&v3->vfptr, v2);
  UFG::WorldCollisionListener::EndFrame(UFG::WorldCollisionListener::mInstance, v3->mWorld);
  UFG::Destruction::Update(UFG::Destruction::mInstance);
  UFG::PhantomCallback::Update(UFG::PhantomCallback::mInstance, v2);
  v16 = (__m128)LODWORD(UFG::WindAction::mWindTicker);
  UFG::WindAction::mWindTicker = UFG::WindAction::mWindTicker + v2;
  v16.m128_f32[0] = UFG::qNoise<float,float>::GetValue(
                      &UFG::WindAction::mWindTurbulance,
                      UFG::WindAction::gWindDirectionFrequency * UFG::WindAction::mWindTicker);
  v17 = v16;
  v17.m128_f32[0] = v16.m128_f32[0] * 3.1415999;
  v18 = v17;
  v18.m128_f32[0] = cosf(v17.m128_f32[0]);
  v19 = v18;
  v20 = v17;
  v20.m128_f32[0] = sinf(v17.m128_f32[0]);
  UFG::WindAction::mWindDirection.m_quad = _mm_unpacklo_ps(
                                             _mm_unpacklo_ps(v19, (__m128)0i64),
                                             _mm_unpacklo_ps(v20, (__m128)0i64));
  UFG::WindAction::mWindPerp.m_quad = _mm_unpacklo_ps(
                                        _mm_unpacklo_ps(v20, (__m128)0i64),
                                        _mm_unpacklo_ps(_mm_xor_ps(v19, *(__m128 *)_xmm), (__m128)0i64));
  UFG::PhysicsSystem::DeleteEntitiesLeftBroadphase(v3);
  UFG::PhysicsSystem::UpdateWater(v3, v2);
  UFG::PhysicsSystem::MakeStaticSceneryInvisible(v3);
  UFG::ActiveRegionManager::GetCentre(&v3->mActiveRegionManager, &location);
  UFG::Constraint::GenerateAudioEvents(&location);
}

// File Line: 1679
// RVA: 0x454D20
void __fastcall UFG::PhysicsSystem::AddCollisionInstanceToWorld(UFG::PhysicsSystem *this, UFG::CollisionInstanceData *instance)
{
  UFG::BasePhysicsSystem::AddCollisionInstanceToWorld((UFG::BasePhysicsSystem *)&this->vfptr, instance);
}

// File Line: 1706
// RVA: 0x45A140
char __fastcall UFG::PhysicsSystem::CastAsyncRay(UFG::PhysicsSystem *this, UFG::qVector3 *rayStart, UFG::qVector3 *rayEnd, unsigned int collisionFilter, void (__fastcall *callback)(UFG::RayCastData *, UFG::SimComponent *, void *), UFG::SimComponent *simComponent, void *userData)
{
  unsigned int v7; // edi
  UFG::qVector3 *v8; // rsi
  UFG::qVector3 *v9; // rbp
  UFG::PhysicsSystem *v10; // rbx
  char result; // al

  v7 = collisionFilter;
  v8 = rayEnd;
  v9 = rayStart;
  v10 = this;
  if ( !this->mBuildingAiData
    && (UFG::gFlowController.mCurrentState
     && UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED)
     || UFG::Metrics::msInstance.mSimTimeDelta <= 0.0) )
  {
    result = 0;
  }
  else
  {
    result = UFG::BasePhysicsSystem::CastAsyncRay(
               (UFG::BasePhysicsSystem *)&v10->vfptr,
               v9,
               v8,
               v7,
               callback,
               simComponent,
               userData);
  }
  return result;
}

// File Line: 1724
// RVA: 0x45A1E0
char __fastcall UFG::PhysicsSystem::CastAsyncShape(UFG::PhysicsSystem *this, UFG::AsyncShapeCasterCollector *caster, UFG::SimComponent *simComponent, void *userData)
{
  void *v4; // rdi
  UFG::SimComponent *v5; // rsi
  UFG::AsyncShapeCasterCollector *v6; // rbp
  UFG::PhysicsSystem *v7; // rbx
  char result; // al

  v4 = userData;
  v5 = simComponent;
  v6 = caster;
  v7 = this;
  if ( !this->mBuildingAiData
    && (UFG::gFlowController.mCurrentState
     && UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED)
     || UFG::Metrics::msInstance.mSimTimeDelta <= 0.0) )
  {
    result = 0;
  }
  else
  {
    result = UFG::BasePhysicsSystem::CastAsyncShape((UFG::BasePhysicsSystem *)&v7->vfptr, v6, v5, v4);
  }
  return result;
}

// File Line: 1765
// RVA: 0x464830
char __fastcall UFG::PhysicsSystem::FindParentObjectOfSimObject(UFG::SimObject *simObjectToFind, UFG::RigidBodyComponent **parentOut, int *indexOut)
{
  int *v3; // rbx
  UFG::RigidBodyComponent **v4; // rdi
  UFG::SimObject *v5; // r9
  UFG::RigidBodyComponent *v6; // r10
  UFG::CollisionInstanceData *v7; // rax
  unsigned int v8; // ecx
  unsigned int v9; // edx
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *v10; // r8
  UFG::SimObject **v11; // rax
  char result; // al

  v3 = indexOut;
  v4 = parentOut;
  v5 = simObjectToFind;
  if ( simObjectToFind
    && (v6 = (UFG::RigidBodyComponent *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext,
        &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280)) )
  {
    while ( 1 )
    {
      v7 = v6->mInstanceData;
      v8 = 0;
      v9 = v7->mNumParts;
      v10 = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&v6->mNext[-18].mNext;
      if ( v9 )
        break;
LABEL_7:
      v6 = (UFG::RigidBodyComponent *)&v6->mNext[-18].mNext;
      if ( v10 == (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                    - 280) )
        goto LABEL_8;
    }
    v11 = &v7->mParts->mSimObject.m_pPointer;
    while ( *v11 != v5 )
    {
      ++v8;
      v11 += 4;
      if ( v8 >= v9 )
        goto LABEL_7;
    }
    *v4 = v6;
    *v3 = v8;
    result = 1;
  }
  else
  {
LABEL_8:
    *v4 = 0i64;
    result = 0;
    *v3 = -1;
  }
  return result;
}

// File Line: 2030
// RVA: 0x461EB0
void __fastcall UFG::PhysicsSystem::DisableStaticSceneryInstance(UFG::PhysicsSystem *this, unsigned int sceneryGuid, UFG::qVector3 *pos)
{
  UFG::qVector3 *v3; // rbx
  unsigned int v4; // esi
  UFG::PhysicsSystem *v5; // rdi
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // r9
  float v8; // xmm1_4
  float v9; // xmm2_4
  UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *v10; // rax

  v3 = pos;
  v4 = sceneryGuid;
  v5 = this;
  v6 = UFG::qMalloc(0x20ui64, "StaticSceneryTracking", 0i64);
  v7 = v6;
  if ( v6 )
  {
    v6->mNext = v6;
    v6[1].mNext = v6;
    v8 = v3->y;
    v9 = v3->z;
    *(float *)&v6[2].mNext = v3->x;
    *((float *)&v6[2].mNext + 1) = v8;
    *(float *)&v6[3].mNext = v9;
    HIDWORD(v6[3].mNext) = v4;
  }
  else
  {
    v7 = 0i64;
  }
  v10 = v5->mStaticSceneryToDisable.mNode.mPrev;
  v10->mNext = (UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *)v7;
  v7->mNext = (UFG::allocator::free_link *)v10;
  v7[1].mNext = (UFG::allocator::free_link *)&v5->mStaticSceneryToDisable;
  v5->mStaticSceneryToDisable.mNode.mPrev = (UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *)v7;
}

// File Line: 2039
// RVA: 0x46C3E0
void __fastcall UFG::PhysicsSystem::MakeStaticSceneryInvisible(UFG::PhysicsSystem *this)
{
  UFG::PhysicsSystem *v1; // r15
  char **v2; // r12
  char *v3; // rax
  UFG::qTaskGroup *v4; // rsi
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v5; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v6; // rax
  UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *v7; // rdi
  UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *v8; // rcx
  UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *v9; // rax
  UFG::qBaseTreeRB *v10; // rbp
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v11; // r14
  UFG::allocator::free_link *v12; // rax
  UFG::allocator::free_link *v13; // rbx
  int v14; // xmm1_4
  int v15; // xmm2_4
  UFG::qNode<SceneryToDisable,SceneryToDisable> *v16; // rax
  char *v17; // rax
  char *v18; // rdx
  _QWORD *v19; // rcx
  UFG::qSpuElf *v20; // rax
  void (__fastcall *v21)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *v22)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v23)(void *, void *, void *, void *); // r9
  char *v24; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v25; // rax
  UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *v26; // rdx
  UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *v27; // rax
  UFG::qNode<SceneryToDisable,SceneryToDisable> *v28; // rbx
  UFG::qNode<SceneryToDisable,SceneryToDisable> *v29; // rcx
  UFG::qNode<SceneryToDisable,SceneryToDisable> *v30; // rax
  UFG::SceneryGroup *v31; // rcx
  UFG::qNode<SceneryToDisable,SceneryToDisable> *v32; // rdx
  UFG::qNode<SceneryToDisable,SceneryToDisable> *v33; // rax
  UFG::PhysicsSystem *v34; // [rsp+70h] [rbp+8h]
  unsigned int v35; // [rsp+78h] [rbp+10h]

  v34 = this;
  v1 = this;
  v2 = (char **)&this->mStaticSceneryToDisable;
  if ( (UFG::qList<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking,1,0> *)this->mStaticSceneryToDisable.mNode.mNext != &this->mStaticSceneryToDisable )
  {
    v3 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
    v4 = (UFG::qTaskGroup *)v3;
    if ( v3 )
      UFG::qTaskGroup::qTaskGroup((UFG::qTaskGroup *)v3, "testTaskGroup");
    v5 = UFG::gTaskManager.mSingleFrameTaskGroups;
    v6 = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
    v6->mNext = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v4->mPrev;
    v4->mPrev = v6;
    v4->mNext = &v5->mNode;
    v5->mNode.mPrev = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v4->mPrev;
    while ( v2[1] != (char *)v2 )
    {
      v7 = v1->mStaticSceneryToDisable.mNode.mNext;
      v8 = v7->mPrev;
      v9 = v7->mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = v7;
      v7->mNext = v7;
      v35 = HIDWORD(v7[1].mNext);
      v10 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423A9A90);
      if ( v10 )
      {
        v11 = &v4->mTasks;
        do
        {
          v12 = UFG::qMalloc(0x30ui64, "SceneryToDisable", 0i64);
          v13 = v12;
          if ( v12 )
          {
            v12->mNext = v12;
            v12[1].mNext = v12;
            v12[4].mNext = 0i64;
            LODWORD(v12[5].mNext) = 0;
          }
          else
          {
            v13 = 0i64;
          }
          v14 = HIDWORD(v7[1].mPrev);
          v15 = (int)v7[1].mNext;
          LODWORD(v13[2].mNext) = v7[1].mPrev;
          HIDWORD(v13[2].mNext) = v14;
          LODWORD(v13[3].mNext) = v15;
          v16 = v1->mSceneryFoundForDisable.mNode.mNext;
          v1->mSceneryFoundForDisable.mNode.mNext = (UFG::qNode<SceneryToDisable,SceneryToDisable> *)v13;
          v13->mNext = (UFG::allocator::free_link *)&v1->mSceneryFoundForDisable;
          v13[1].mNext = (UFG::allocator::free_link *)v16;
          v16->mPrev = (UFG::qNode<SceneryToDisable,SceneryToDisable> *)v13;
          v17 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
          v18 = v17;
          if ( v17 )
          {
            *(_QWORD *)v17 = v17;
            *((_QWORD *)v17 + 1) = v17;
            v19 = v17 + 16;
            *v19 = v19;
            v19[1] = v19;
            v20 = gTaskFunctionDeclData_MakeStaticSceneryInvisibleTask.mSpuElf;
            v21 = gTaskFunctionDeclData_MakeStaticSceneryInvisibleTask.mTaskFunctionSPU;
            v22 = gTaskFunctionDeclData_MakeStaticSceneryInvisibleTask.mTaskFunctionPPU;
            v23 = gTaskFunctionDeclData_MakeStaticSceneryInvisibleTask.mTaskFunctionOffload;
            if ( !gTaskFunctionDeclData_MakeStaticSceneryInvisibleTask.mCurrentSPUEnabled )
            {
              v20 = 0i64;
              v21 = 0i64;
              v23 = 0i64;
            }
            *((_QWORD *)v18 + 6) = v4;
            *((_DWORD *)v18 + 14) = 2;
            *((_QWORD *)v18 + 4) = 0i64;
            *((_QWORD *)v18 + 5) = 0i64;
            *((_QWORD *)v18 + 8) = &gTaskFunctionDeclData_MakeStaticSceneryInvisibleTask;
            if ( v20 )
              v24 = v20->mAddress;
            else
              v24 = 0i64;
            *((_QWORD *)v18 + 9) = v24;
            *((_QWORD *)v18 + 10) = v21;
            *((_QWORD *)v18 + 11) = v22;
            *((_QWORD *)v18 + 12) = v10;
            *((_QWORD *)v18 + 13) = v13;
            *((_QWORD *)v18 + 14) = v35;
            *((_QWORD *)v18 + 15) = 0i64;
            if ( v23 )
            {
              *((_DWORD *)v18 + 14) = 130;
              *((_DWORD *)v18 + 12) = 0;
            }
          }
          v25 = v11->mNode.mPrev;
          v25->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)v18;
          *(_QWORD *)v18 = v25;
          *((_QWORD *)v18 + 1) = v11;
          v11->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)v18;
          ++v4->mNumTasks;
          v10 = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423A9A90, &v10->mRoot);
        }
        while ( v10 );
        v1 = v34;
        v2 = (char **)&v34->mStaticSceneryToDisable;
      }
      v26 = v7->mPrev;
      v27 = v7->mNext;
      v26->mNext = v27;
      v27->mPrev = v26;
      v7->mPrev = v7;
      v7->mNext = v7;
      operator delete[](v7);
    }
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v4);
    UFG::qTaskManager::Sync(&UFG::gTaskManager, v4);
    while ( (UFG::qList<SceneryToDisable,SceneryToDisable,1,0> *)v1->mSceneryFoundForDisable.mNode.mNext != &v1->mSceneryFoundForDisable )
    {
      v28 = v1->mSceneryFoundForDisable.mNode.mNext;
      v29 = v28->mPrev;
      v30 = v28->mNext;
      v29->mNext = v30;
      v30->mPrev = v29;
      v28->mPrev = v28;
      v28->mNext = v28;
      v31 = (UFG::SceneryGroup *)v28[2].mPrev;
      if ( v31 )
        UFG::SceneryGroup::MakeInvisible(v31, (unsigned int)v28[2].mNext);
      v32 = v28->mPrev;
      v33 = v28->mNext;
      v32->mNext = v33;
      v33->mPrev = v32;
      v28->mPrev = v28;
      v28->mNext = v28;
      operator delete[](v28);
    }
  }
}

// File Line: 2090
// RVA: 0x473810
void __fastcall UFG::PhysicsSystem::ResetFracturables(UFG::PhysicsSystem *this)
{
  UFG::qBaseNodeRB *i; // rdi
  unsigned int j; // ebx
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *v3; // rcx
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *v4; // rax
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *v5; // rcx
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *v6; // rax

  for ( i = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_14216D7B0);
        i;
        i = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_14216D7B0, i) )
  {
    for ( j = 0; j < i[2].mUID; ++j )
      UFG::CollisionMeshData::ResetFracture(*((UFG::CollisionMeshData **)&i[3].mChild[1]->mParent + j));
  }
  v3 = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
  if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
  {
    do
    {
      v4 = v3[18].mNode.mPrev;
      v5 = v3[15].mNode.mPrev;
      v6 = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&v4[-18].mNext;
      if ( v5 )
      {
        v5->mPrev = 0i64;
        v5->mNext = 0i64;
        v5[1].mPrev = 0i64;
        v5[1].mNext = 0i64;
      }
      v3 = v6;
    }
    while ( v6 != (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                    - 280) );
  }
}

// File Line: 2115
// RVA: 0x4738E0
void __fastcall UFG::PhysicsSystem::ResetParkourComponents(UFG::PhysicsSystem *this)
{
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *i; // rbx
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v2; // rcx

  for ( i = UFG::ParkourComponent::s_ParkourComponentList.mNode.mNext - 4;
        i != (UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *)(&UFG::ParkourComponent::s_ParkourComponentList
                                                                       - 4);
        i = i[4].mNext - 4 )
  {
    v2 = i[11].mPrev;
    LODWORD(i[11].mNext) &= 0xFFFFFFEF;
    if ( v2 )
      ((void (__fastcall *)(UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *, signed __int64))v2->mPrev->mPrev)(
        v2,
        1i64);
    i[11].mPrev = 0i64;
  }
}

// File Line: 2128
// RVA: 0x4615B0
void __fastcall UFG::PhysicsSystem::DeleteStreamedCollisionInstances(UFG::PhysicsSystem *this)
{
  UFG::BasePhysicsSystem *v1; // rsi
  UFG::qBaseTreeRB *i; // rdi
  __int64 v3; // rbx

  v1 = UFG::BasePhysicsSystem::mInstance;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_14216D960);
        i;
        i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_14216D960, &i->mRoot) )
  {
    v3 = 0i64;
    if ( i[1].mRoot.mUID )
    {
      do
      {
        UFG::BasePhysicsSystem::RemoveCollisionInstanceFromWorld(
          v1,
          *((UFG::CollisionInstanceData **)&i[1].mRoot.mChild[1]->mParent + v3));
        v3 = (unsigned int)(v3 + 1);
      }
      while ( (unsigned int)v3 < i[1].mRoot.mUID );
    }
  }
}

// File Line: 2146
// RVA: 0x472770
void __fastcall UFG::PhysicsSystem::RecreateStreamedCollisionInstances(UFG::PhysicsSystem *this)
{
  UFG::BasePhysicsSystem *v1; // rsi
  UFG::qBaseTreeRB *i; // rbx
  __int64 v3; // rdi
  __int64 v4; // rdx
  __int128 v5; // xmm0
  __int128 v6; // xmm1

  v1 = UFG::BasePhysicsSystem::mInstance;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_14216D960);
        i;
        i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_14216D960, &i->mRoot) )
  {
    v3 = 0i64;
    if ( i[1].mRoot.mUID )
    {
      do
      {
        v4 = *((_QWORD *)&i[1].mRoot.mChild[1]->mParent + v3);
        v5 = *(_OWORD *)(v4 + 48);
        v6 = *(_OWORD *)(v4 + 16);
        *(_DWORD *)(v4 + 88) &= 0xFFFFFFFD;
        *(_OWORD *)(v4 + 32) = v5;
        *(_OWORD *)v4 = v6;
        (*((void (__fastcall **)(UFG::BasePhysicsSystem *))&v1->vfptr->__vecDelDtor + 1))(v1);
        v3 = (unsigned int)(v3 + 1);
      }
      while ( (unsigned int)v3 < i[1].mRoot.mUID );
    }
  }
}

// File Line: 2170
// RVA: 0x459240
void __fastcall UFG::PhysicsSystem::BroadPhaseBorderHandler(hkpEntity *entity)
{
  hkpEntity *v1; // rbx

  v1 = entity;
  hkReferencedObject::addReference((hkReferencedObject *)&entity->vfptr);
  UFG::ThreadSafeQueue<hkpEntity>::AddHead(
    (UFG::ThreadSafeQueue<UFG::CollisionEvent> *)&UFG::BasePhysicsSystem::mInstance[1].mCollisionModels.mTree.mRoot.mUID,
    (UFG::CollisionEvent *)v1);
}

// File Line: 2178
// RVA: 0x45A130
void __fastcall UFG::PhysicsSystem::CalculateWorldBoundaries(UFG::PhysicsSystem *this)
{
  UFG::WorldBoundaries::Initialize(&this->mBoundaries);
}

// File Line: 2185
// RVA: 0x465500
void __fastcall UFG::PhysicsSystem::FlushWorldBoundaries(UFG::PhysicsSystem *this)
{
  UFG::WorldBoundaries::Shutdown(&this->mBoundaries);
}

// File Line: 2193
// RVA: 0x460C10
void __fastcall UFG::PhysicsSystem::DeleteEntitiesLeftBroadphase(UFG::PhysicsSystem *this)
{
  _RTL_CRITICAL_SECTION *v1; // rsi
  UFG::PhysicsSystem *v2; // r13
  UFG::QueueNode<hkpEntity> *v3; // r14
  bool v4; // bl
  hkpEntity *v5; // rdi
  bool v6; // bl
  UFG::QueueNode<hkpEntity> *v7; // rcx
  UFG::QueueNode<hkpEntity> *v8; // rax
  signed int v9; // ebx
  __int64 v10; // r8
  __int128 v11; // xmm1
  hkpShape *v12; // rcx
  __int128 v13; // xmm0
  __int128 v14; // xmm1
  __m128 v15; // xmm6
  float v16; // xmm0_4
  unsigned __int64 v17; // r15
  __int64 v18; // rbx
  UFG::SimComponent *v19; // rcx
  __m128 v20; // xmm1
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  __m128 v23; // xmm6
  UFG::SimObjectGame *v24; // rcx
  unsigned __int16 v25; // dx
  UFG::SimComponent *v26; // rax
  UFG::SimObject *v27; // rdi
  UFG::TransformNodeComponent *v28; // rbx
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm4_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  char *v43; // rax
  unsigned __int64 v44; // rbx
  __int64 v45; // rbx
  UFG::TransformNodeComponent *i; // rax
  char *v47; // rax
  hkpWorld *v48; // rbx
  bool v49; // bl
  UFG::qMatrix44 xform; // [rsp+40h] [rbp-C0h]
  int v51; // [rsp+80h] [rbp-80h]
  int v52; // [rsp+84h] [rbp-7Ch]
  int v53; // [rsp+88h] [rbp-78h]
  int v54; // [rsp+90h] [rbp-70h]
  int v55; // [rsp+94h] [rbp-6Ch]
  int v56; // [rsp+98h] [rbp-68h]
  __m128 v57; // [rsp+A0h] [rbp-60h]
  __m128 v58; // [rsp+B0h] [rbp-50h]
  hkVector4f v59; // [rsp+C0h] [rbp-40h]
  __int128 v60; // [rsp+D0h] [rbp-30h]
  __int128 v61; // [rsp+E0h] [rbp-20h]
  __int128 v62; // [rsp+F0h] [rbp-10h]
  hkBool result; // [rsp+180h] [rbp+80h]

  v1 = (_RTL_CRITICAL_SECTION *)&this->mEntitiesLeftBroadphase.mutex;
  v2 = this;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mEntitiesLeftBroadphase.mutex);
  v3 = &v2->mEntitiesLeftBroadphase.tail;
  v4 = v2->mEntitiesLeftBroadphase.head.next == &v2->mEntitiesLeftBroadphase.tail;
  UFG::qMutex::Unlock(v1);
  if ( !v4 )
  {
    do
    {
      v5 = 0i64;
      UFG::qMutex::Lock(v1);
      UFG::qMutex::Lock(v1);
      v6 = v2->mEntitiesLeftBroadphase.head.next == v3;
      UFG::qMutex::Unlock(v1);
      if ( !v6 )
      {
        v7 = v3->prev;
        v8 = v3->prev->prev;
        v8->next = v3;
        v3->prev = v8;
        v5 = v7->data;
        operator delete[](v7);
      }
      UFG::qMutex::Unlock(v1);
      v9 = v5->m_referenceCount;
      hkReferencedObject::removeReference((hkReferencedObject *)&v5->vfptr);
      if ( v5->m_world && v9 > 1 )
      {
        v11 = (__int128)v5->m_motion.m_motionState.m_transform.m_rotation.m_col1;
        v12 = v5->m_collidable.m_shape;
        v59.m_quad = (__m128)v5->m_motion.m_motionState.m_transform.m_rotation.m_col0;
        v13 = (__int128)v5->m_motion.m_motionState.m_transform.m_rotation.m_col2;
        v60 = v11;
        v14 = (__int128)v5->m_motion.m_motionState.m_transform.m_translation;
        v61 = v13;
        v62 = v14;
        ((void (__fastcall *)(hkpShape *, hkVector4f *, __int64, int *))v12->vfptr[2].__vecDelDtor)(
          v12,
          &v59,
          v10,
          &v51);
        v15 = v5->m_motion.m_motionState.m_transform.m_translation.m_quad;
        LODWORD(v16) = (unsigned __int128)_mm_shuffle_ps(v15, v15, 170);
        if ( v16 <= -10.0 || v16 >= 10.0 )
        {
          if ( !sDisableLeavingWorld )
          {
            UFG::qPrintf(
              "PHYSICS: DeleteEntitiesLeftBroadphase %s (%f %f %f), (%f %f %f)\n",
              (_QWORD)v5->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
              v51,
              v52,
              v53,
              v54,
              v55,
              v56);
            v43 = UFG::GetCollisionLayerName(v5->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo & 0x1F);
            UFG::qPrintf("PHYSICS: %x layer %s\n", v5, v43);
            v44 = v5->m_userData;
            if ( v44 )
            {
              v45 = *(_QWORD *)(v44 + 24);
              if ( v45 )
                v45 = *(_QWORD *)(v45 + 40);
              if ( v45 && !UFG::SimObjectUtility::HandleSimObjectLeavingWorld((UFG::SimObject *)v45) )
              {
                for ( i = (UFG::TransformNodeComponent *)UFG::SimObject::GetComponentOfType(
                                                           (UFG::SimObject *)v45,
                                                           UFG::RigidBodyComponent::_RigidBodyComponentTypeUID);
                      i;
                      i = UFG::SimObject::GetComponentOfType(
                            (UFG::SimObject *)v45,
                            UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                            0,
                            (UFG::SimComponent *)&i->vfptr) )
                {
                  *(_DWORD *)(*(_QWORD *)&i->mWorldTransform.v1.z + 88i64) |= 2u;
                }
                v47 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(v45 + 72));
                UFG::qPrintf("PHYSICS: SimObject has left the world (deleting) %s\n", v47);
                UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, (UFG::SimObject *)v45);
              }
            }
            else
            {
              v48 = v5->m_world;
              if ( v48 )
              {
                UFG::qPrintf(
                  "PHYSICS: hkpEntity has left the world (possible memory leak) %s\n",
                  (_QWORD)v5->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
                hkpWorld::removeEntity(v48, &result, v5);
              }
            }
          }
        }
        else
        {
          v17 = v5->m_userData;
          v18 = 0i64;
          v19 = *(UFG::SimComponent **)(v17 + 24);
          v20 = _mm_mul_ps(v15, v15);
          v21 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                  _mm_shuffle_ps(v20, v20, 170));
          v22 = _mm_rsqrt_ps(v21);
          v23 = _mm_mul_ps(
                  v15,
                  _mm_andnot_ps(
                    _mm_cmpleps(v21, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                      _mm_mul_ps(*(__m128 *)_xmm, v22))));
          v57 = v23;
          if ( !v19
            || !UFG::SimComponent::IsType(v19, UFG::CharacterPhysicsComponent::_CharacterPhysicsComponentTypeUID)
            || (v18 = *(_QWORD *)(v17 + 24), (v24 = *(UFG::SimObjectGame **)(v18 + 40)) == 0i64)
            || ((v25 = v24->m_Flags, !((v25 >> 14) & 1)) ? ((v25 & 0x8000u) == 0 ? (!((v25 >> 13) & 1) ? (!((v25 >> 12) & 1) ? (v26 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v24->vfptr, UFG::CharacterOccupantComponent::_TypeUID)) : (v26 = UFG::SimObjectGame::GetComponentOfTypeHK(v24, UFG::CharacterOccupantComponent::_TypeUID))) : (v26 = UFG::SimObjectGame::GetComponentOfTypeHK(v24, UFG::CharacterOccupantComponent::_TypeUID))) : (v26 = UFG::SimObjectGame::GetComponentOfTypeHK(v24, UFG::CharacterOccupantComponent::_TypeUID))) : (v26 = v24->m_Components.p[44].m_pComponent),
                !v26) )
          {
            hkpEntity::activate(v5);
            v58 = _mm_mul_ps((__m128)_xmm_c0a00000c0a00000c0a00000c0a00000, v23);
            hkpEntity::activate(v5);
            v5->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v5->m_motion.vfptr, (unsigned int)&v58);
            if ( v18 )
            {
              v27 = *(UFG::SimObject **)(v18 + 40);
              if ( v27 )
                v28 = v27->m_pTransformNodeComponent;
              else
                v28 = 0i64;
              if ( v28 )
              {
                UFG::TransformNodeComponent::UpdateWorldTransform(v28);
                v29 = v28->mWorldTransform.v0.y;
                v30 = v28->mWorldTransform.v3.x;
                v31 = v28->mWorldTransform.v3.y;
                v32 = v28->mWorldTransform.v3.z;
                xform.v0.x = v28->mWorldTransform.v0.x;
                v33 = v28->mWorldTransform.v0.z;
                xform.v0.y = v29;
                v34 = v28->mWorldTransform.v0.w;
                xform.v0.z = v33;
                v35 = v28->mWorldTransform.v1.x;
                xform.v0.w = v34;
                v36 = v28->mWorldTransform.v1.y;
                xform.v1.x = v35;
                xform.v1.z = v28->mWorldTransform.v1.z;
                v37 = v28->mWorldTransform.v2.x;
                xform.v1.y = v36;
                v38 = v28->mWorldTransform.v1.w;
                xform.v2.x = v37;
                v39 = v28->mWorldTransform.v2.z;
                xform.v1.w = v38;
                v40 = v28->mWorldTransform.v2.y;
                xform.v2.z = v39;
                v41 = v28->mWorldTransform.v3.w;
                xform.v2.y = v40;
                v42 = v28->mWorldTransform.v2.w;
                xform.v3.w = v41;
                xform.v2.w = v42;
                xform.v3.y = v31 + (float)(v57.m128_f32[1] * -10.0);
                xform.v3.z = v32 + 5.0;
                xform.v3.x = v30 + (float)(v57.m128_f32[0] * -10.0);
                UFG::SimObjectUtility::Teleport(v27, &xform);
              }
            }
          }
        }
      }
      UFG::qMutex::Lock(v1);
      v49 = v2->mEntitiesLeftBroadphase.head.next == v3;
      UFG::qMutex::Unlock(v1);
    }
    while ( !v49 );
  }
}

// File Line: 2308
// RVA: 0x480F20
void __fastcall UFG::PhysicsSystem::UpdateWater(UFG::PhysicsSystem *this, float deltaTime)
{
  UFG::qList<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent,1,0> *v2; // rcx
  UFG::qList<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent,1,0> *v3; // rbx
  UFG::qList<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent,1,0> *v4; // rcx
  UFG::qList<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent,1,0> *v5; // rbx
  UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *v6; // rbx
  UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *v7; // rdi
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *v8; // rax
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *v9; // rsi
  UFG::CharacterEffectsComponent *v10; // r14
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *v11; // rcx
  UFG::TransformNodeComponent *v12; // rsi
  float v13; // xmm6_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  __m128 v16; // xmm1
  UFG::qVector3 offset; // [rsp+20h] [rbp-88h]
  UFG::qVector3 characterVelocity; // [rsp+30h] [rbp-78h]
  UFG::qMatrix44 dest; // [rsp+40h] [rbp-68h]

  this->mWaterWaveAngle = fmodf((float)(deltaTime * this->mWaterWaveFrequency) + this->mWaterWaveAngle, 6.2800002);
  v2 = (UFG::qList<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent,1,0> *)&UFG::WaterPhantomComponent::s_WaterPhantomComponentList.mNode.mNext[-7].mNext;
  if ( &UFG::WaterPhantomComponent::s_WaterPhantomComponentList.mNode.mNext[-7].mNext != (UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> **)((char *)&UFG::WaterPhantomComponent::s_WaterPhantomComponentList - 104) )
  {
    do
    {
      v3 = (UFG::qList<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent,1,0> *)&v2[7].mNode.mPrev[-7].mNext;
      if ( ((_QWORD)v2[2].mNode.mPrev & 3) == 1 )
        ((void (*)(void))v2->mNode.mPrev[7].mPrev)();
      v2 = v3;
    }
    while ( v3 != (UFG::qList<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent,1,0> *)((char *)&UFG::WaterPhantomComponent::s_WaterPhantomComponentList
                                                                                          - 104) );
  }
  v4 = (UFG::qList<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent,1,0> *)&UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentList.mNode.mNext[-6].mNext;
  if ( &UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> **)((char *)&UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentList - 88) )
  {
    do
    {
      v5 = (UFG::qList<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent,1,0> *)&v4[6].mNode.mPrev[-6].mNext;
      if ( ((_QWORD)v4[2].mNode.mPrev & 3) == 1 )
        ((void (__fastcall *)(UFG::qList<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent,1,0> *))v4[4].mNode.mPrev->mPrev)(&v4[4]);
      v4 = v5;
    }
    while ( v5 != (UFG::qList<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent,1,0> *)((char *)&UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentList - 88) );
  }
  v6 = (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext;
  if ( &UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext != (UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> **)((char *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList - 104) )
  {
    do
    {
      v7 = (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)&v6[7].mNode.mPrev[-7].mNext;
      if ( ((_QWORD)v6[2].mNode.mPrev & 3) == 1 )
      {
        v8 = v6[11].mNode.mNext;
        if ( v8 )
        {
          if ( SLODWORD(v8[7].mNext) > 0 )
          {
            v9 = v6[2].mNode.mNext;
            v10 = (UFG::CharacterEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)v6[2].mNode.mNext,
                                                      UFG::CharacterEffectsComponent::_TypeUID);
            if ( v10 )
            {
              v11 = v6[11].mNode.mNext;
              v12 = (UFG::TransformNodeComponent *)v9[5].mNext;
              if ( v11 )
                v13 = *((float *)&v11[8].mNext + 1);
              else
                v13 = FLOAT_N0_31400001;
              UFG::TransformNodeComponent::UpdateWorldTransform(v12);
              v14 = v12->mWorldTransform.v3.y;
              v15 = v12->mWorldTransform.v3.x;
              offset.z = v13;
              offset.x = v15;
              offset.y = v14;
              UFG::qTranslationMatrix(&dest, &offset);
              v16 = (__m128)v6[27].mNode.mPrev[2].mPrev[35];
              LODWORD(characterVelocity.x) = v6[27].mNode.mPrev[2].mPrev[35];
              LODWORD(characterVelocity.z) = (unsigned __int128)_mm_shuffle_ps(v16, v16, 170);
              LODWORD(characterVelocity.y) = (unsigned __int128)_mm_shuffle_ps(v16, v16, 85);
              UFG::CharacterEffectsComponent::HandleWaterCollision(v10, &dest, &characterVelocity);
            }
          }
        }
      }
      v6 = v7;
    }
    while ( v7 != (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)((char *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList
                                                                                                  - 104) );
  }
}

// File Line: 2375
// RVA: 0x45B010
float __fastcall UFG::PhysicsSystem::ComputeBuoyancy(UFG::PhysicsSystem *this, float cubePosZ, float cubeSideLength, float waterHeight)
{
  float v4; // xmm4_4

  v4 = cubePosZ - (float)(cubeSideLength * 0.5);
  if ( v4 >= waterHeight )
    return 0.0;
  if ( (float)((float)(cubeSideLength * 0.5) + cubePosZ) > waterHeight )
    return (float)(waterHeight - v4) / cubeSideLength;
  return *(float *)&FLOAT_1_0;
}

// File Line: 2405
// RVA: 0x461A40
void __fastcall UFG::PhysicsSystem::DisableCollisionsBetween(UFG::PhysicsSystem *this, UFG::SimObject *simObjectA, UFG::SimObject *simObjectB)
{
  UFG::SimObjectGame *v3; // rbx
  UFG::SimObjectGame *v4; // r8
  UFG::PhysicsSystem *v5; // rdi
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  hkpEntity *v8; // rsi
  UFG::CustomCollisionFilter *v9; // rdi
  unsigned __int16 v10; // cx
  UFG::SimComponent *v11; // rax
  hkpEntity *v12; // r8
  unsigned __int16 v13; // cx
  UFG::SimComponent *v14; // rax
  unsigned __int16 v15; // cx
  UFG::SimComponent *v16; // rax
  UFG::RigidBody *v17; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v18; // rcx
  const char *v19; // rax
  UFG::CollisionMeshData *v20; // rdx
  hkpEntity *v21; // r8
  UFG::qReflectHandleBase v22; // [rsp+38h] [rbp-30h]

  if ( !simObjectA )
    return;
  v3 = (UFG::SimObjectGame *)simObjectB;
  v4 = (UFG::SimObjectGame *)simObjectA;
  v5 = this;
  if ( !v3 )
    return;
  v6 = simObjectA->m_Flags;
  if ( (v6 >> 14) & 1 )
  {
    v7 = v4->m_Components.p[27].m_pComponent;
  }
  else if ( (v6 & 0x8000u) == 0 )
  {
    if ( (v6 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterPhysicsComponent::_TypeUID);
    else
      v7 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterPhysicsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::CharacterPhysicsComponent::_TypeUID);
  }
  else
  {
    v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterPhysicsComponent::_TypeUID);
  }
  if ( !v7 )
    return;
  v8 = (hkpEntity *)v7[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev;
  if ( !v8 )
    return;
  v9 = v5->mCollisionFilter;
  v10 = v3->m_Flags;
  if ( (v10 >> 14) & 1 )
  {
    v11 = v3->m_Components.p[27].m_pComponent;
  }
  else if ( (v10 & 0x8000u) == 0 )
  {
    if ( (v10 >> 13) & 1 )
    {
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
    }
    else if ( (v10 >> 12) & 1 )
    {
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
    }
    else
    {
      v11 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterPhysicsComponent::_TypeUID);
    }
  }
  else
  {
    v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
  }
  if ( v11 )
  {
    v12 = (hkpEntity *)v11[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev;
    if ( v12 )
    {
      UFG::CustomCollisionFilter::DisableCollisionsBetween(v9, v8, v12);
      return;
    }
  }
  v13 = v3->m_Flags;
  if ( !((v13 >> 14) & 1) )
  {
    if ( (v13 & 0x8000u) != 0 )
    {
      v14 = v3->m_Components.p[34].m_pComponent;
      goto LABEL_33;
    }
    if ( !((v13 >> 13) & 1) )
    {
      if ( (v13 >> 12) & 1 )
        v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PhysicsMoverInterface::_TypeUID);
      else
        v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
LABEL_33:
      if ( v14 )
        return;
      goto LABEL_34;
    }
  }
LABEL_34:
  v15 = v3->m_Flags;
  if ( (v15 >> 14) & 1 )
  {
    v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
  }
  else if ( (v15 & 0x8000u) == 0 )
  {
    if ( (v15 >> 13) & 1 )
    {
      v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v15 >> 12) & 1 )
    {
      v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
    }
    else
    {
      v16 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RigidBodyComponent::_TypeUID);
    }
  }
  else
  {
    v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
  }
  v17 = (UFG::RigidBody *)v16;
  if ( v16 )
  {
    do
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v22);
      v19 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v18);
      v22.mTypeUID = UFG::qStringHash64(v19, 0xFFFFFFFFFFFFFFFFui64);
      v20 = v17->mCollisionMeshData;
      if ( v20 )
        UFG::qReflectHandleBase::operator=(&v22, (UFG::qReflectHandleBase *)&v20->mObjectProperties.mPrev);
      if ( v22.mData )
      {
        if ( BYTE2(v22.mData[2].vfptr) )
        {
          v21 = (hkpEntity *)&v17->mBody->vfptr;
          if ( v21 )
            UFG::CustomCollisionFilter::DisableCollisionsBetween(v9, v8, v21);
        }
        else
        {
          UFG::RigidBody::SetCollisionLayer(v17, 0x15u, -1, -1, -1);
        }
      }
      v17 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                v17->m_pSimObject,
                                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                0,
                                (UFG::SimComponent *)&v17->vfptr);
      UFG::qReflectHandleBase::~qReflectHandleBase(&v22);
    }
    while ( v17 );
  }
}

// File Line: 2465
// RVA: 0x4723A0
void __fastcall UFG::PhysicsSystem::ReEnableCollisionsBetween(UFG::PhysicsSystem *this, UFG::SimObject *simObjectA, UFG::SimObject *simObjectB)
{
  UFG::SimObjectGame *v3; // rbx
  UFG::SimObjectGame *v4; // r8
  UFG::PhysicsSystem *v5; // rdi
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  hkpEntity *v8; // rsi
  UFG::CustomCollisionFilter *v9; // rbp
  unsigned __int16 v10; // cx
  UFG::SimComponent *v11; // rax
  hkpEntity *v12; // r8
  unsigned __int16 v13; // cx
  UFG::SimComponent *v14; // rax
  unsigned __int16 v15; // cx
  UFG::SimComponent *v16; // rax
  UFG::RigidBodyComponent *v17; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v18; // rcx
  const char *v19; // rax
  UFG::CollisionMeshData *v20; // rdx
  hkpEntity *v21; // r8
  UFG::qReflectHandleBase v22; // [rsp+28h] [rbp-30h]

  if ( !simObjectA )
    return;
  v3 = (UFG::SimObjectGame *)simObjectB;
  v4 = (UFG::SimObjectGame *)simObjectA;
  v5 = this;
  v6 = simObjectA->m_Flags;
  if ( (v6 >> 14) & 1 )
  {
    v7 = v4->m_Components.p[27].m_pComponent;
  }
  else if ( (v6 & 0x8000u) == 0 )
  {
    if ( (v6 >> 13) & 1 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterPhysicsComponent::_TypeUID);
    else
      v7 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterPhysicsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::CharacterPhysicsComponent::_TypeUID);
  }
  else
  {
    v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterPhysicsComponent::_TypeUID);
  }
  if ( !v7 )
    return;
  v8 = (hkpEntity *)v7[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev;
  if ( !v8 )
    return;
  v9 = v5->mCollisionFilter;
  if ( !v3 )
    return;
  v10 = v3->m_Flags;
  if ( (v10 >> 14) & 1 )
  {
    v11 = v3->m_Components.p[27].m_pComponent;
  }
  else if ( (v10 & 0x8000u) == 0 )
  {
    if ( (v10 >> 13) & 1 )
    {
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
    }
    else if ( (v10 >> 12) & 1 )
    {
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
    }
    else
    {
      v11 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterPhysicsComponent::_TypeUID);
    }
  }
  else
  {
    v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
  }
  if ( v11 )
  {
    v12 = (hkpEntity *)v11[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev;
    if ( v12 )
    {
      UFG::CustomCollisionFilter::ReenableCollisionsBetween(v5->mCollisionFilter, v8, v12);
      return;
    }
  }
  v13 = v3->m_Flags;
  if ( !((v13 >> 14) & 1) )
  {
    if ( (v13 & 0x8000u) != 0 )
    {
      v14 = v3->m_Components.p[34].m_pComponent;
      goto LABEL_33;
    }
    if ( !((v13 >> 13) & 1) )
    {
      if ( (v13 >> 12) & 1 )
        v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PhysicsMoverInterface::_TypeUID);
      else
        v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
LABEL_33:
      if ( v14 )
        return;
      goto LABEL_34;
    }
  }
LABEL_34:
  v15 = v3->m_Flags;
  if ( (v15 >> 14) & 1 )
  {
    v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
  }
  else if ( (v15 & 0x8000u) == 0 )
  {
    if ( (v15 >> 13) & 1 )
    {
      v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v15 >> 12) & 1 )
    {
      v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
    }
    else
    {
      v16 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RigidBodyComponent::_TypeUID);
    }
  }
  else
  {
    v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
  }
  v17 = (UFG::RigidBodyComponent *)v16;
  if ( v16 )
  {
    do
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v22);
      v19 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v18);
      v22.mTypeUID = UFG::qStringHash64(v19, 0xFFFFFFFFFFFFFFFFui64);
      v20 = v17->mCollisionMeshData;
      if ( v20 )
        UFG::qReflectHandleBase::operator=(&v22, (UFG::qReflectHandleBase *)&v20->mObjectProperties.mPrev);
      if ( BYTE2(v22.mData[2].vfptr) )
      {
        v21 = (hkpEntity *)&v17->mBody->vfptr;
        if ( v21 )
          UFG::CustomCollisionFilter::ReenableCollisionsBetween(v9, v8, v21);
      }
      else
      {
        UFG::RigidBodyComponent::RestoreCollisionFilter(v17);
      }
      v17 = (UFG::RigidBodyComponent *)UFG::SimObject::GetComponentOfType(
                                         v17->m_pSimObject,
                                         UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                         0,
                                         (UFG::SimComponent *)&v17->vfptr);
      UFG::qReflectHandleBase::~qReflectHandleBase(&v22);
    }
    while ( v17 );
  }
}

// File Line: 2514
// RVA: 0x46F720
void __fastcall UFG::PhysicsSystem::PhysicsVolumeHandler(UFG::PhysicsSystem *this, UFG::PhantomCallback *pcb, UFG::SimObject *simObject, UFG::PhantomCallbackData *data)
{
  UFG::PhantomCallbackData *v4; // rbx
  UFG::SimObject *v5; // rdi
  UFG::SceneObjectProperties *v6; // rax
  UFG::qPropertySet *v7; // rcx
  bool *v8; // rax
  UFG::PhantomVolumeComponent *v9; // rax
  UFG::PhantomCallbackShape *v10; // rdx
  UFG::qMemoryPool *v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::PhantomVolumeComponent *v13; // rax
  UFG::PhantomVolumeComponent *v14; // rsi
  unsigned __int16 v15; // cx
  unsigned int v16; // ebx
  UFG::SimObjectModifier v17; // [rsp+38h] [rbp-30h]

  v4 = data;
  v5 = simObject;
  if ( data->mPhantomCallbackShape->mVolumeProperties->mReserved != 1 )
    goto LABEL_24;
  v6 = simObject->m_pSceneObj;
  if ( v6 )
  {
    v7 = v6->mpWritableProperties;
    if ( !v7 )
      v7 = v6->mpConstProperties;
    v8 = PropertyUtils::Get<bool>(v7, (UFG::qSymbol *)&qSymbol_ImportantVFXCharacter.mUID, DEPTH_RECURSE);
    if ( v8 )
    {
      if ( *v8 )
      {
LABEL_24:
        v9 = (UFG::PhantomVolumeComponent *)UFG::SimObject::GetComponentOfType(
                                              v5,
                                              UFG::PhantomVolumeComponent::_TypeUID);
        if ( v9 )
        {
          v10 = v4->mPhantomCallbackShape;
          if ( v4->mEvent )
            UFG::PhantomVolumeComponent::OnLeaveVolume(v9, v10);
          else
            UFG::PhantomVolumeComponent::OnEnterVolume(v9, v10);
        }
        else if ( v4->mEvent == ENTER_EVENT )
        {
          v11 = UFG::GetSimulationMemoryPool();
          v12 = UFG::qMemoryPool::Allocate(v11, 0xA8ui64, "SimComponent", 0i64, 1u);
          if ( v12 )
          {
            UFG::PhantomVolumeComponent::PhantomVolumeComponent((UFG::PhantomVolumeComponent *)v12, v5->mNode.mUID);
            v14 = v13;
          }
          else
          {
            v14 = 0i64;
          }
          UFG::PhantomVolumeComponent::OnEnterVolume(v14, v4->mPhantomCallbackShape);
          v15 = v5->m_Flags;
          if ( (v15 >> 14) & 1 || (v15 & 0x8000u) != 0 )
          {
            v16 = 18;
          }
          else if ( (v15 >> 13) & 1 )
          {
            v16 = 5;
          }
          else
          {
            v16 = -1;
          }
          UFG::SimObjectModifier::SimObjectModifier(&v17, v5, 1);
          UFG::SimObjectModifier::AttachComponent(&v17, (UFG::SimComponent *)&v14->vfptr, v16);
          UFG::SimObjectModifier::Close(&v17);
          UFG::SimObjectModifier::~SimObjectModifier(&v17);
        }
      }
    }
  }
}


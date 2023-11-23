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
  int m_numThreads; // ecx
  hkHardwareInfo info; // [rsp+30h] [rbp+8h] BYREF

  hkGetHardwareInfo(&info);
  m_numThreads = 4;
  UFG::BasePhysicsSystem::mParam.maxLoadedBodies = 2500;
  UFG::BasePhysicsSystem::mParam.solverBufferSize = 0x100000;
  if ( info.m_numThreads < 4 )
    m_numThreads = info.m_numThreads;
  UFG::BasePhysicsSystem::mParam.numThreads = m_numThreads;
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
  UFG::RagdollFactory *v3; // rsi
  __int32 v4; // ebp
  UFG::RagdollFactory *v5; // rdi
  UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *p_mNext; // rcx
  UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *v7; // rdx
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *mNext; // rcx
  UFG::allocator::free_link *v9; // rax
  UFG::RagdollFactory *v10; // rax

  v3 = 0i64;
  v4 = flags & 1;
  if ( (flags & 1) != 0 )
  {
    v5 = UFG::RagdollFactory::mInstance;
    if ( UFG::RagdollFactory::mInstance )
    {
      UFG::RagdollFactory::~RagdollFactory(UFG::RagdollFactory::mInstance);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, (char *)&v5->mDisableCaching);
    }
    UFG::RagdollFactory::mInstance = 0i64;
  }
  UFG::PhysicsSystem::DeleteStreamedCollisionInstances(this);
  UFG::BasePhysicsSystem::CancelAllAsyncRayCasts(this);
  if ( UFG::BulletManager::mInstance )
  {
    UFG::BulletManager::mInstance->vfptr->__vecDelDtor(UFG::BulletManager::mInstance, 1i64);
    UFG::BulletManager::mInstance = 0i64;
  }
  UFG::Destruction::ResetScene(UFG::Destruction::mInstance);
  UFG::PhantomCallback::Shutdown();
  UFG::CharacterPhysicsComponentManager::ResetScene(UFG::CharacterPhysicsComponentManager::mInstance);
  p_mNext = (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
  if ( &UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext != (UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> **)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList - 72) )
  {
    do
    {
      v7 = (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)&p_mNext[5].mNode.mPrev[-5].mNext;
      mNext = p_mNext[40].mNode.mNext;
      if ( mNext && (HIDWORD(mNext[37].mNext) & 7) == 2 && BYTE1(mNext[77].mPrev) )
        LOWORD(mNext[77].mPrev) = 0;
      p_mNext = v7;
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
    UFG::CustomCollisionFilter::ResetState(this->mCollisionFilter);
  }
  UFG::PhysicsSystem::ResetFracturables(this);
  UFG::PhysicsSystem::ResetParkourComponents(this);
  UFG::PhysicsSystem::RecreateStreamedCollisionInstances(this);
}

// File Line: 295
// RVA: 0x44ADC0
void __fastcall UFG::PhysicsSystem::PhysicsSystem(UFG::PhysicsSystem *this, UFG::qMemoryPool *pool)
{
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
  hkVector4f centre; // [rsp+40h] [rbp-19h] BYREF
  UFG::qString v19; // [rsp+50h] [rbp-9h] BYREF

  UFG::BasePhysicsSystem::BasePhysicsSystem(this, pool);
  this->vfptr = (UFG::BasePhysicsSystemVtbl *)&UFG::PhysicsSystem::`vftable;
  this->mStaticSceneryToDisable.mNode.mPrev = &this->mStaticSceneryToDisable.mNode;
  this->mStaticSceneryToDisable.mNode.mNext = &this->mStaticSceneryToDisable.mNode;
  this->mSceneryFoundForDisable.mNode.mPrev = &this->mSceneryFoundForDisable.mNode;
  this->mSceneryFoundForDisable.mNode.mNext = &this->mSceneryFoundForDisable.mNode;
  UFG::qMutex::qMutex(&this->mEntitiesLeftBroadphase.mutex, &customCaption);
  this->mEntitiesLeftBroadphase.head.next = &this->mEntitiesLeftBroadphase.tail;
  v3 = 0i64;
  this->mEntitiesLeftBroadphase.head.prev = 0i64;
  this->mEntitiesLeftBroadphase.tail.prev = &this->mEntitiesLeftBroadphase.head;
  this->mEntitiesLeftBroadphase.tail.next = 0i64;
  this->mBoundaries.vfptr = (UFG::WorldBoundariesVtbl *)&UFG::WorldBoundaries::`vftable;
  this->mBoundaries.mWorldBoundaries.p = 0i64;
  *(_QWORD *)&this->mBoundaries.mWorldBoundaries.size = 0i64;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mBoundaries.mMappings.mTree);
  this->mWaterElevation = 0.0;
  this->mWaterWaveHeight = 0.050000001;
  this->mWaterWaveFrequency = 2.0;
  *(_QWORD *)&this->mWaterWavePhase = 1056964608i64;
  hkpGroupFilter::disableCollisionsUsingBitfield(this->mCollisionFilter, 0xFFFFFFFE, 0xFFFFFFFE);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 1, 1);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 1, 2);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 1, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 1, 10);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 1, 19);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 1, 20);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 1, 26);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 1, 22);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 1, 31);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 2, 1);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 2, 2);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 2, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 2, 10);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 2, 19);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 2, 20);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 2, 26);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 2, 22);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 2, 31);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 4, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 4, 10);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 4, 20);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 4, 31);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 5, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 5, 20);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 5, 25);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 6, 1);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 6, 2);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 6, 25);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 6, 22);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 3, 3);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 9, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 9, 10);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 9, 31);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 25, 1);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 25, 3);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 25, 7);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 25, 8);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 25, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 25, 10);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 25, 19);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 25, 20);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 25, 27);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 25, 31);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 25, 28);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 7, 19);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 7, 20);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 7, 22);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 7, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 7, 10);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 7, 31);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 7, 7);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 19, 19);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 19, 20);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 19, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 19, 10);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 19, 31);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 20, 20);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 20, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 20, 10);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 20, 31);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 26, 19);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 26, 20);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 26, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 26, 10);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 26, 31);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 22, 22);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 22, 1);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 22, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 22, 10);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 22, 19);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 22, 20);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 22, 26);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 22, 31);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 18, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 18, 22);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 18, 30);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 23, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 24, 20);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 24, 22);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 24, 1);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 24, 2);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 29, 19);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 29, 20);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 29, 26);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 29, 22);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 11, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 11, 10);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 11, 22);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 11, 20);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 11, 7);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 12, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 12, 10);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 12, 19);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 12, 20);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 12, 22);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 13, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 13, 10);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 13, 20);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 13, 22);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 14, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 15, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 15, 20);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 15, 22);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 16, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 16, 10);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 16, 31);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 16, 19);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 16, 20);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 16, 27);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 17, 9);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 17, 10);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 28, 2);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 28, 19);
  hkpGroupFilter::enableCollisionsBetween(this->mCollisionFilter, 28, 20);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1197311665i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    2911353378i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    536383246i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    2910362013i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1908879335i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1648293198i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1893482955i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    205165038i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    2551363397i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    2300271228i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1566868405i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1312147186i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1312147187i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    592477054i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1407467077i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    4029961327i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1698822422i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    2073359529i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1412852942i64,
    0i64);
  UFG::qString::qString(&v19, "ARM_INTERIOR");
  UFG::qArray<UFG::qString,0>::Add(&this->mActiveRegionManager.mNames, v4, "qArray.Add");
  UFG::qString::~qString(&v19);
  if ( this->mActiveRegionManager.mExtents.m_size == (this->mActiveRegionManager.mExtents.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->mActiveRegionManager.mExtents, 16);
  this->mActiveRegionManager.mExtents.m_data[this->mActiveRegionManager.mExtents.m_size++] = (hkVector4f)_xmm;
  UFG::qString::qString(&v19, "ARM_SWEATSHOP_INTERIOR");
  UFG::qArray<UFG::qString,0>::Add(&this->mActiveRegionManager.mNames, v5, "qArray.Add");
  UFG::qString::~qString(&v19);
  if ( this->mActiveRegionManager.mExtents.m_size == (this->mActiveRegionManager.mExtents.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->mActiveRegionManager.mExtents, 16);
  this->mActiveRegionManager.mExtents.m_data[this->mActiveRegionManager.mExtents.m_size++] = (hkVector4f)_xmm;
  UFG::qString::qString(&v19, "ARM_WEDDING_INTERIOR");
  UFG::qArray<UFG::qString,0>::Add(&this->mActiveRegionManager.mNames, v6, "qArray.Add");
  UFG::qString::~qString(&v19);
  if ( this->mActiveRegionManager.mExtents.m_size == (this->mActiveRegionManager.mExtents.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->mActiveRegionManager.mExtents, 16);
  this->mActiveRegionManager.mExtents.m_data[this->mActiveRegionManager.mExtents.m_size++] = (hkVector4f)_xmm;
  UFG::qString::qString(&v19, "ARM_PENTHOUSE_INTERIOR");
  UFG::qArray<UFG::qString,0>::Add(&this->mActiveRegionManager.mNames, v7, "qArray.Add");
  UFG::qString::~qString(&v19);
  if ( this->mActiveRegionManager.mExtents.m_size == (this->mActiveRegionManager.mExtents.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->mActiveRegionManager.mExtents, 16);
  this->mActiveRegionManager.mExtents.m_data[this->mActiveRegionManager.mExtents.m_size++] = (hkVector4f)_xmm;
  UFG::qString::qString(&v19, "ARM_EXTERIOR");
  UFG::qArray<UFG::qString,0>::Add(&this->mActiveRegionManager.mNames, v8, "qArray.Add");
  UFG::qString::~qString(&v19);
  if ( this->mActiveRegionManager.mExtents.m_size == (this->mActiveRegionManager.mExtents.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->mActiveRegionManager.mExtents, 16);
  this->mActiveRegionManager.mExtents.m_data[this->mActiveRegionManager.mExtents.m_size++] = (hkVector4f)_xmm;
  UFG::qString::qString(&v19, "ARM_AIPACKER");
  UFG::qArray<UFG::qString,0>::Add(&this->mActiveRegionManager.mNames, v9, "qArray.Add");
  UFG::qString::~qString(&v19);
  if ( this->mActiveRegionManager.mExtents.m_size == (this->mActiveRegionManager.mExtents.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->mActiveRegionManager.mExtents, 16);
  this->mActiveRegionManager.mExtents.m_data[this->mActiveRegionManager.mExtents.m_size++] = (hkVector4f)_xmm;
  UFG::Destruction::Initialize(this->mWorld);
  UFG::RigidBodyComponent::mAllocatorBuffer = UFG::qMemoryPool::Allocate(
                                                &gPhysicsMemoryPool,
                                                0x120160ui64,
                                                "RigidBodyComponentPool",
                                                0i64,
                                                1u);
  UFG::qFixedAllocator::Init(
    &UFG::RigidBodyComponent::mAllocator,
    (char *)UFG::RigidBodyComponent::mAllocatorBuffer,
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
  this->mBroadPhaseBorder->mCallback = UFG::PhysicsSystem::BroadPhaseBorderHandler;
  UFG::ActiveRegionManager::SetMode(&this->mActiveRegionManager, 4u);
  centre.m_quad = 0i64;
  UFG::ActiveRegionManager::SetCentre(&this->mActiveRegionManager, &centre);
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
  UFG::ParkourQueryManager *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  UFG::RagdollFactory *v4; // rax
  Render::SkinningCacheNode *Head; // rbx
  UFG::ParkourContainerBundleInventory *v6; // rbx
  UFG::ParkourContainerInventory *v7; // rbx
  UFG::ParkourInstanceInventory *v8; // rbx
  UFG::qNode<SceneryToDisable,SceneryToDisable> *mPrev; // rcx
  UFG::qNode<SceneryToDisable,SceneryToDisable> *mNext; // rax
  UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *v11; // rcx
  UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *v12; // rax

  this->vfptr = (UFG::BasePhysicsSystemVtbl *)&UFG::PhysicsSystem::`vftable;
  v2 = UFG::ParkourQueryManager::mInstance;
  if ( UFG::ParkourQueryManager::mInstance )
  {
    UFG::ParkourQueryManager::~ParkourQueryManager(UFG::ParkourQueryManager::mInstance);
    operator delete[](v2);
  }
  UFG::PhantomCallback::Shutdown();
  UFG::CharacterPhysicsComponentManager::Shutdown();
  UFG::qFixedAllocator::Close(&UFG::CharacterPhysicsComponent::mAllocator);
  UFG::qMemoryPool::Free(&gPhysicsMemoryPool, (char *)UFG::CharacterPhysicsComponent::mAllocatorBuffer);
  UFG::CharacterPhysicsComponent::mAllocatorBuffer = 0i64;
  UFG::qFixedAllocator::Close(&UFG::PhysicsVehicle::mAllocator);
  UFG::qMemoryPool::Free(&gPhysicsMemoryPool, (char *)UFG::PhysicsVehicle::mAllocatorBuffer);
  UFG::PhysicsVehicle::mAllocatorBuffer = 0i64;
  UFG::ExplosionManager::Shutdown();
  if ( UFG::BulletManager::mInstance )
  {
    UFG::BulletManager::mInstance->vfptr->__vecDelDtor(UFG::BulletManager::mInstance, 1i64);
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
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::StateMachineDefinition::mGuidTranslation);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::StateMachineDefinition::mGuidTranslation,
      &Head->mNode);
    operator delete[](Head);
  }
  UFG::qFixedAllocator::Close(&UFG::RigidBodyComponent::mAllocator);
  UFG::qMemoryPool::Free(&gPhysicsMemoryPool, (char *)UFG::RigidBodyComponent::mAllocatorBuffer);
  UFG::RigidBodyComponent::mAllocatorBuffer = 0i64;
  v6 = UFG::gParkourContainerBundleInventory;
  if ( UFG::gParkourContainerBundleInventory )
  {
    UFG::qResourceInventory::~qResourceInventory(UFG::gParkourContainerBundleInventory);
    operator delete[](v6);
  }
  UFG::gParkourContainerBundleInventory = 0i64;
  v7 = UFG::gParkourContainerInventory;
  if ( UFG::gParkourContainerInventory )
  {
    UFG::qResourceInventory::~qResourceInventory(UFG::gParkourContainerInventory);
    operator delete[](v7);
  }
  UFG::gParkourContainerInventory = 0i64;
  v8 = UFG::gParkourInstanceInventory;
  if ( UFG::gParkourInstanceInventory )
  {
    UFG::qResourceInventory::~qResourceInventory(UFG::gParkourInstanceInventory);
    operator delete[](v8);
  }
  UFG::gParkourInstanceInventory = 0i64;
  UFG::WorldBoundaries::~WorldBoundaries(&this->mBoundaries);
  UFG::ThreadSafeQueue<UFG::CollisionEvent>::~ThreadSafeQueue<UFG::CollisionEvent>((UFG::ThreadSafeQueue<UFG::CollisionEvent> *)&this->mEntitiesLeftBroadphase);
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->mSceneryFoundForDisable);
  mPrev = this->mSceneryFoundForDisable.mNode.mPrev;
  mNext = this->mSceneryFoundForDisable.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mSceneryFoundForDisable.mNode.mPrev = &this->mSceneryFoundForDisable.mNode;
  this->mSceneryFoundForDisable.mNode.mNext = &this->mSceneryFoundForDisable.mNode;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->mStaticSceneryToDisable);
  v11 = this->mStaticSceneryToDisable.mNode.mPrev;
  v12 = this->mStaticSceneryToDisable.mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  this->mStaticSceneryToDisable.mNode.mPrev = &this->mStaticSceneryToDisable.mNode;
  this->mStaticSceneryToDisable.mNode.mNext = &this->mStaticSceneryToDisable.mNode;
  UFG::BasePhysicsSystem::~BasePhysicsSystem(this);
}

// File Line: 669
// RVA: 0x46E150
UFG::RigidBodyComponent *__fastcall UFG::PhysicsSystem::OnCollisionInstanceAddedToWorld(
        UFG::PhysicsSystem *this,
        UFG::CollisionInstanceData *instance,
        UFG::CollisionMeshData *mesh,
        char onAddedFlags,
        unsigned int rigidBodyFlags,
        UFG::SimObjectGame *simObject)
{
  UFG::CollisionInstanceData *v8; // r13
  UFG::RigidBodyComponent *v9; // rdi
  UFG::PhysicsObjectProperties *mData; // r14
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
  unsigned int v21; // r15d
  UFG::SimObjectGame *v22; // rsi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::ComponentTypeTable *TypeTableProp; // rax
  UFG::qMemoryPool *v25; // rax
  UFG::allocator::free_link *v26; // rax
  UFG::TransformNodeComponent *v27; // rax
  UFG::TransformNodeComponent *v28; // r13
  __int16 m_Flags; // cx
  unsigned int v30; // ebx
  unsigned int mNumItems; // eax
  UFG::qMemoryPool *v32; // rax
  UFG::allocator::free_link *v33; // rax
  char *mItems; // r9
  UFG::SimComponent *v35; // rax
  UFG::allocator::free_link *v36; // rax
  UFG::allocator::free_link *v37; // rbx
  UFG::SimComponent *v38; // rbx
  __int16 v39; // cx
  UFG::qSymbol name; // [rsp+30h] [rbp-D0h] BYREF
  UFG::SimComponent *component; // [rsp+38h] [rbp-C8h]
  UFG::SimComponent *v43; // [rsp+40h] [rbp-C0h]
  UFG::SimObjectModifier v44; // [rsp+48h] [rbp-B8h] BYREF
  UFG::allocator::free_link *v45; // [rsp+68h] [rbp-98h]
  __int64 v46; // [rsp+70h] [rbp-90h]
  hkTransformf v47; // [rsp+80h] [rbp-80h] BYREF
  UFG::qMatrix44 d[2]; // [rsp+C0h] [rbp-40h] BYREF
  char ptr; // [rsp+168h] [rbp+68h]

  v46 = -2i64;
  v8 = instance;
  v9 = 0i64;
  mData = (UFG::PhysicsObjectProperties *)mesh->mObjectProperties.mData;
  v43 = 0i64;
  ptr = 0;
  v11 = rigidBodyFlags;
  if ( (onAddedFlags & 1) != 0 )
    v11 = rigidBodyFlags | 4;
  if ( mData->mCreateWaterPhantom )
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
    if ( mData->mMotionType != CGF_STATIC || mData->mForceLibraryObject || mData->mPreventStaticWorldMerge )
    {
      if ( mData->mActiveRegionManagement != ARM_DISABLE )
        v11 |= 1u;
      v19 = UFG::RigidBodyComponent::operator new(0x1D8ui64);
      v45 = v19;
      if ( v19 )
      {
        UFG::RigidBodyComponent::RigidBodyComponent((UFG::RigidBodyComponent *)v19, mesh, v8, v11, -1);
        v9 = v20;
      }
      else
      {
        v9 = 0i64;
      }
      if ( mData->mActiveRegionManagement == ARM_DISABLE )
      {
        LOBYTE(v13) = 1;
        v9->UFG::RigidBody::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor(v9, v13);
      }
      ptr = 1;
    }
    else
    {
      v16 = UFG::RigidBodyComponent::operator new(0x1D8ui64);
      v45 = v16;
      if ( v16 )
      {
        UFG::RigidBodyComponent::RigidBodyComponent((UFG::RigidBodyComponent *)v16, mesh, v8, v11, -1);
        v9 = v18;
      }
      else
      {
        v9 = 0i64;
      }
      LOBYTE(v17) = 1;
      v9->UFG::RigidBody::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor(v9, v17);
    }
    v15 = v9;
    component = v9;
  }
  v8->mPhysicsComponent = v15;
  name.mUID = v8->mSimObjectName.mUID;
  v21 = -1;
  v22 = simObject;
  if ( !simObject )
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v22 = (UFG::SimObjectGame *)UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x90ui64, "SimObject", 0i64, 1u);
    if ( v22 )
    {
      TypeTableProp = UFG::GetTypeTableProp();
      UFG::SimObjectGame::SimObjectGame(v22, TypeTableProp, &name);
      v22->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)&UFG::SimObjectProp::`vftable;
      v22->m_Flags |= 0x2000u;
    }
    else
    {
      v22 = 0i64;
    }
    v47.m_translation = v8->mInitialPosition;
    hkRotationf::set(&v47.m_rotation, &v8->mInitialOrientation);
    hkTransformf::get4x4ColumnMajor(&v47, &d[0].v0.x);
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
    UFG::TransformNodeComponent::SetWorldTransform(v28, d);
    m_Flags = v22->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      v30 = 2;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        v30 = 2;
      }
      else
      {
        v30 = -1;
        if ( (m_Flags & 0x1000) != 0 )
          v30 = 1;
      }
    }
    else
    {
      v30 = 2;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v44, v22, 1);
    UFG::SimObjectModifier::AttachComponent(&v44, v28, v30);
    UFG::SimObjectModifier::Close(&v44);
    UFG::SimObjectModifier::~SimObjectModifier(&v44);
    v8 = instance;
  }
  if ( (onAddedFlags & 0x10) == 0 && (onAddedFlags & 0x20) == 0 && ptr )
    UFG::PhysicsSystem::AddRenderHelper(this, v22, v9, v8, mesh);
  mNumItems = mData->mActFileName.mText.mData.mNumItems;
  if ( mNumItems && (mNumItems != 1 || *mData->mActFileName.mText.mData.mItems) )
  {
    v32 = UFG::GetSimulationMemoryPool();
    v33 = UFG::qMemoryPool::Allocate(v32, 0x560ui64, "ActionTreeComponent", 0i64, 1u);
    if ( v33 )
    {
      if ( mData->mActFileName.mText.mData.mNumItems )
        mItems = mData->mActFileName.mText.mData.mItems;
      else
        mItems = &customCaption;
      UFG::ActionTreeComponent::ActionTreeComponent((UFG::ActionTreeComponent *)v33, 0i64, v22->mNode.mUID, mItems);
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
      v37->mNext = (UFG::allocator::free_link *)&UFG::StateMachineDefinition::`vftable;
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
  if ( (onAddedFlags & 2) != 0 )
    v9->mFlags |= 0x20u;
  if ( (onAddedFlags & 8) != 0 )
  {
    LOBYTE(v13) = 1;
    v9->UFG::RigidBody::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor(v9, v13);
  }
  UFG::SimObjectModifier::SimObjectModifier(&v44, v22, 1);
  UFG::SimObjectModifier::AttachComponent(&v44, component, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v44);
  UFG::SimObjectModifier::~SimObjectModifier(&v44);
  v38 = v43;
  if ( v43 )
  {
    v39 = v22->m_Flags;
    if ( (v39 & 0x4000) != 0 )
    {
      v21 = 7;
    }
    else if ( v39 >= 0 )
    {
      if ( (v39 & 0x2000) != 0 )
        v21 = 6;
    }
    else
    {
      v21 = 7;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v44, v22, 1);
    UFG::SimObjectModifier::AttachComponent(&v44, v38, v21);
    UFG::SimObjectModifier::Close(&v44);
    UFG::SimObjectModifier::~SimObjectModifier(&v44);
  }
  if ( (onAddedFlags & 2) == 0 )
    UFG::PhysicsSystem::AddParkourAndCover(this, v22, v9, mesh, -1);
  UFG::PhysicsSystem::AddStateMachines(this, v22, v9, v8, mesh);
  return v9;
}

// File Line: 796
// RVA: 0x46E6A0
void __fastcall UFG::PhysicsSystem::OnCollisionInstanceRemovedFromWorld(
        UFG::PhysicsSystem *this,
        UFG::CollisionInstanceData *instance)
{
  UFG::SimComponent *mPhysicsComponent; // rdx
  UFG::SimObject *m_pSimObject; // rdx

  mPhysicsComponent = instance->mPhysicsComponent;
  if ( mPhysicsComponent )
  {
    m_pSimObject = mPhysicsComponent->m_pSimObject;
    instance->mPhysicsComponent = 0i64;
    UFG::Simulation::DestroySimObject(&UFG::gSim, m_pSimObject);
  }
}

// File Line: 811
// RVA: 0x455210
void __fastcall UFG::PhysicsSystem::AddPhysicsComponents(
        UFG::PhysicsSystem *this,
        UFG::SimObjectGame *simObject,
        UFG::RigResource *rig)
{
  UFG::RigResource *v3; // rsi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  __int64 v9; // rbp
  __int64 v10; // r15
  UFG::RigResource::CollisionMap *mCollisionMap; // rax
  unsigned int collisionModelGuid; // ebx
  __int64 boneIndex; // r14
  UFG::qBaseTreeRB *CollisionModel; // rax
  UFG::CollisionMeshData *v15; // rsi
  UFG::qBaseNodeRB *v16; // r12
  hkaPose *v17; // rcx
  hkQsTransformf *v18; // rax
  __m128 m_quad; // xmm6
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
  unsigned int mUID; // edx
  BOOL v40; // ebx
  UFG::allocator::free_link *v41; // rax
  __int64 v42; // rdx
  UFG::RigidBodyComponent *v43; // rax
  UFG::RigidBodyComponent *v44; // rbx
  hkQuaternionf orient; // [rsp+40h] [rbp-108h] BYREF
  hkVector4f pos; // [rsp+50h] [rbp-F8h] BYREF
  __int64 *p_name; // [rsp+60h] [rbp-E8h]
  __int64 v48; // [rsp+68h] [rbp-E0h]
  hkTransformf transform; // [rsp+70h] [rbp-D8h] BYREF
  hkQsTransformf v50; // [rsp+B0h] [rbp-98h] BYREF
  UFG::allocator::free_link *name; // [rsp+158h] [rbp+10h] BYREF
  UFG::RigResource *v52; // [rsp+160h] [rbp+18h]
  __int64 v53; // [rsp+168h] [rbp+20h]

  v52 = rig;
  v48 = -2i64;
  v3 = rig;
  m_pTransformNodeComponent = simObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  hkTransformf::set4x4ColumnMajor(&transform, &m_pTransformNodeComponent->mWorldTransform.v0.x);
  hkQsTransformf::setFromTransformNoScale(&v50, &transform);
  m_Flags = simObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = simObject->m_Components.p[9].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = simObject->m_Components.p[8].m_pComponent;
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(simObject, UFG::BaseAnimationComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(simObject, UFG::BaseAnimationComponent::_TypeUID);
    }
  }
  else
  {
    m_pComponent = simObject->m_Components.p[9].m_pComponent;
  }
  v9 = *(_QWORD *)&m_pComponent[2].m_TypeUID;
  v53 = v9;
  if ( v9 )
  {
    v10 = 0i64;
    if ( v3->mNumCollisionMap )
    {
      do
      {
        mCollisionMap = v3->mCollisionMap;
        collisionModelGuid = mCollisionMap[v10].collisionGuid;
        boneIndex = (int)mCollisionMap[v10].boneIndex;
        CollisionModel = UFG::BasePhysicsSystem::GetCollisionModel(
                           UFG::BasePhysicsSystem::mInstance,
                           collisionModelGuid);
        v15 = (UFG::CollisionMeshData *)CollisionModel;
        if ( CollisionModel )
        {
          v16 = CollisionModel[3].mNULL.mChild[0];
          if ( !BYTE4(v16[4].mChild[0])
            && UFG::BasePhysicsSystem::RequestAnotherRigidBody(UFG::BasePhysicsSystem::mInstance) )
          {
            v17 = *(hkaPose **)(v9 + 488);
            if ( (v17->m_boneFlags.m_data[boneIndex] & 2) != 0 )
              v18 = hkaPose::calculateBoneModelSpace(v17, boneIndex);
            else
              v18 = &v17->m_modelPose.m_data[boneIndex];
            m_quad = v18->m_rotation.m_vec.m_quad;
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
            v27 = _mm_shuffle_ps(m_quad, m_quad, 255);
            v28 = _mm_sub_ps(
                    _mm_mul_ps(v50.m_rotation.m_vec.m_quad, _mm_shuffle_ps(m_quad, m_quad, 201)),
                    _mm_mul_ps(m_quad, v23));
            v29 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v28, v28, 201), _mm_mul_ps(m_quad, v20)),
                    _mm_mul_ps(v50.m_rotation.m_vec.m_quad, v27));
            v30 = _mm_mul_ps(v50.m_rotation.m_vec.m_quad, m_quad);
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
            mUID = simObject->m_Name.mUID;
            p_name = (__int64 *)&name;
            LODWORD(name) = mUID;
            UFG::CollisionInstanceData::Set(v38, mUID, 0, (unsigned int *)&name, &pos, &orient, collisionModelGuid);
            v40 = LODWORD(v16[6].mChild[0]) == 0;
            v41 = UFG::RigidBodyComponent::operator new(0x1D8ui64);
            name = v41;
            if ( v41 )
            {
              UFG::RigidBodyComponent::RigidBodyComponent((UFG::RigidBodyComponent *)v41, v15, v38, v40, boneIndex);
              v44 = v43;
            }
            else
            {
              v44 = 0i64;
            }
            if ( v44 )
            {
              LOBYTE(v42) = 1;
              v44->UFG::RigidBody::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor(
                v44,
                v42);
              UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&transform, simObject, 1);
              UFG::SimObjectModifier::AttachComponent((UFG::SimObjectModifier *)&transform, v44, 0xFFFFFFFFi64);
              UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&transform);
              UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&transform);
              UFG::PhysicsSystem::AddParkourAndCover(this, simObject, v44, v15, boneIndex);
              UFG::PhysicsSystem::AddStateMachines(this, simObject, v44, v38, v15);
              UFG::PhysicsSystem::AddRenderHelper(this, simObject, v44, v38, v15);
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
  UFG::SimComponent *ComponentOfType; // rax

  if ( (simObject->m_Flags & 2) == 0 )
  {
    while ( 1 )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(simObject, UFG::RigidBodyComponent::_TypeUID);
      if ( !ComponentOfType )
        break;
      UFG::Simulation::DestroySimComponent(&UFG::gSim, ComponentOfType);
    }
  }
}

// File Line: 892
// RVA: 0x45BF80
void __fastcall UFG::PhysicsSystem::Create(UFG::PhysicsSystem *this, UFG::SimObject *simObject, UFG::FreeRunData *data)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceData *mData; // rsi
  __int64 i; // rdi
  UFG::qBaseNodeRB **v9; // rdx
  char *v10; // rbx
  UFG::allocator::free_link *v11; // rax
  UFG::SimComponent *v12; // rax
  UFG::SimComponent *v13; // rbx
  UFG::SimObjectModifier v14; // [rsp+28h] [rbp-30h] BYREF

  Inventory = `UFG::qGetResourceInventory<UFG::ParkourContainerBundle>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::ParkourContainerBundle>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v6, 0x4558A12Eu);
    `UFG::qGetResourceInventory<UFG::ParkourContainerBundle>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(
    &data->mParkourContainerBundle,
    0x4558A12Eu,
    data->mParkourContainerBundle.mNameUID,
    Inventory);
  mData = data->mParkourContainerBundle.mData;
  for ( i = 0i64; (unsigned int)i < LODWORD(mData[1].mNode.mParent); i = (unsigned int)(i + 1) )
  {
    v9 = &mData[1].mNode.mChild[0]->mParent + i;
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
    UFG::SimObjectModifier::SimObjectModifier(&v14, simObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v14, v13, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v14);
    UFG::SimObjectModifier::~SimObjectModifier(&v14);
  }
}

// File Line: 907
// RVA: 0x45BE80
void __fastcall UFG::PhysicsSystem::Create(UFG::PhysicsSystem *this, UFG::SimObject *simObject, UFG::CoverData *data)
{
  UFG::qResourceData *mData; // rsi
  __int64 i; // rdi
  UFG::qBaseNodeRB **v7; // rdx
  char *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  UFG::SimComponent *v10; // rax
  UFG::SimComponent *v11; // rbx
  UFG::SimObjectModifier v12; // [rsp+28h] [rbp-30h] BYREF

  UFG::qResourceHandle::Init(&data->mDynamicCoverResource, 0xEC7A2131, data->mDynamicCoverResource.mNameUID);
  mData = data->mDynamicCoverResource.mData;
  if ( mData )
  {
    for ( i = 0i64; (unsigned int)i < LODWORD(mData[1].mNode.mParent); i = (unsigned int)(i + 1) )
    {
      v7 = &mData[1].mNode.mChild[0]->mParent + i;
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
      UFG::SimObjectModifier::SimObjectModifier(&v12, simObject, 1);
      UFG::SimObjectModifier::AttachComponent(&v12, v11, 0xFFFFFFFFi64);
      UFG::SimObjectModifier::Close(&v12);
      UFG::SimObjectModifier::~SimObjectModifier(&v12);
    }
  }
}

// File Line: 925
// RVA: 0x45B3B0
void __fastcall UFG::PhysicsSystem::Create(
        UFG::PhysicsSystem *this,
        UFG::SimObject *simObject,
        UFG::CollisionData *collisionData,
        UFG::SkeletonData *skeletonData)
{
  unsigned int mNameUID; // r8d
  UFG::qResourceData *mData; // rsi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qResourceData *v10; // rax
  UFG::SimComponent *ComponentOfType; // rax
  __m128 v12; // xmm1
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm0
  UFG::allocator::free_link *v16; // r15
  unsigned int v17; // r12d
  UFG::MultiBodyComponent *v18; // rbx
  int v19; // edx
  unsigned int mParent; // eax
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
  int BoneID; // edi
  __int64 mOffset; // rax
  char *v39; // rcx
  __int64 v40; // rcx
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
  UFG::RigidBodyComponent *mFreeListHead; // rbx
  unsigned int v60; // eax
  UFG::RigidBody *v61; // rax
  __int64 v62; // rdx
  unsigned int v63; // r14d
  unsigned int v64; // ebx
  unsigned __int64 v65; // rax
  UFG::allocator::free_link *v66; // rax
  UFG::allocator::free_link *v67; // rdx
  __int64 v68; // r8
  unsigned int mCustomDataSlotIndex; // eax
  __int64 v70; // rsi
  __int64 v71; // r14
  __int64 v72; // rbx
  __int64 v73; // rbx
  UFG::allocator::free_link *v74; // rax
  UFG::SimComponent *v75; // rax
  UFG::SimComponent *v76; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *p_m_Flags; // rdx
  UFG::qSafePointerNode<UFG::SimObject>Vtbl *mPrev; // rcx
  UFG::SimObject *m_pSimObject; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v80; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *p_mNext; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v82; // rcx
  UFG::SimComponent *m_pPointer; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v84; // rax
  _QWORD *v85; // rcx
  __int64 v86; // rax
  __int64 v87; // rsi
  UFG::qReflectObjectType<UFG::ConstraintDef,UFG::qReflectObject> *v88; // rcx
  const char *TypeName; // rax
  unsigned __int64 v90; // rdi
  unsigned __int64 v91; // rbx
  UFG::ReflectionDB *v92; // rax
  __int64 v93; // r9
  hkpRigidBody *v94; // rbx
  hkpRigidBody *v95; // rdi
  UFG::RigidBody *v96; // r14
  UFG::RigidBody *v97; // rsi
  __int64 v98; // rdx
  UFG::allocator::free_link *mNext; // rcx
  UFG::allocator::free_link *v100; // r8
  UFG::allocator::free_link *v101; // r13
  UFG::Constraint *v102; // rax
  UFG::Constraint *v103; // rbx
  UFG::qResourceData *v104; // [rsp+40h] [rbp-88h]
  _QWORD *v105; // [rsp+40h] [rbp-88h]
  UFG::MultiBodyComponent *v106; // [rsp+48h] [rbp-80h]
  __int64 v107; // [rsp+50h] [rbp-78h]
  UFG::allocator::free_link *v108; // [rsp+58h] [rbp-70h]
  void *p_transform; // [rsp+60h] [rbp-68h]
  hkVector4f pos; // [rsp+68h] [rbp-60h] BYREF
  UFG::SimObjectModifier v111; // [rsp+78h] [rbp-50h] BYREF
  hkQuaternionf orient; // [rsp+98h] [rbp-30h] BYREF
  UFG::SimObjectModifier v113; // [rsp+A8h] [rbp-20h] BYREF
  hkTransformf transform; // [rsp+C8h] [rbp+0h] BYREF
  __int64 v115; // [rsp+108h] [rbp+40h]
  hkQsTransformf v116; // [rsp+118h] [rbp+50h] BYREF
  UFG::BasePhysicsSystem *v117; // [rsp+1E8h] [rbp+120h]
  UFG::qSymbol name[2]; // [rsp+1F8h] [rbp+130h] BYREF
  __int64 v119; // [rsp+208h] [rbp+140h]

  v115 = -2i64;
  mNameUID = collisionData->mCollisionMeshBundle.mNameUID;
  collisionData->mCollisionMeshBundle.mOwner = 0i64;
  UFG::qResourceHandle::Init(&collisionData->mCollisionMeshBundle, 0x1723EA91u, mNameUID);
  mData = collisionData->mCollisionMeshBundle.mData;
  pos.m_quad.m128_u64[1] = (unsigned __int64)mData;
  if ( !mData )
    return;
  m_pTransformNodeComponent = simObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v104 = 0i64;
  if ( skeletonData )
  {
    v10 = UFG::qResourceInventory::Get(&UFG::gRigInventory, skeletonData->mRigHandle);
LABEL_6:
    v104 = v10;
    goto LABEL_7;
  }
  ComponentOfType = UFG::SimObject::GetComponentOfType(simObject, UFG::CompositeDrawableComponent::_TypeUID);
  if ( ComponentOfType )
  {
    v10 = *(UFG::qResourceData **)&ComponentOfType[21].m_TypeUID;
    goto LABEL_6;
  }
LABEL_7:
  hkTransformf::set4x4ColumnMajor(&transform, &m_pTransformNodeComponent->mWorldTransform.v0.x);
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
  mParent = (unsigned int)mData[1].mNode.mParent;
  if ( mParent )
  {
    v21 = *(_QWORD *)&mData[1].mNode.mUID;
    v22 = mParent;
    do
    {
      if ( (*(_BYTE *)(*(_QWORD *)v21 + 88i64) & 1) == 0 )
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
        UFG::MultiBodyComponent::MultiBodyComponent((UFG::MultiBodyComponent *)v23, simObject->mNode.mUID);
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
  if ( LODWORD(mData[1].mNode.mParent) )
  {
    while ( 1 )
    {
      v26 = *(UFG::CollisionMeshData **)(*(_QWORD *)&mData[1].mNode.mUID + 8i64 * v25);
      v27 = 0i64;
      if ( (v26->mFlags & 1) != 0 )
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
      p_transform = name;
      name[0] = v26->mName;
      UFG::CollisionInstanceData::Set(v31, name[0].mUID, 0, &name[0].mUID, &pos, &orient, collisionModelGuid);
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
      UFG::SimObjectModifier::SimObjectModifier(&v113, simObject, 1);
      UFG::SimObjectModifier::AttachComponent(&v113, v36, 0xFFFFFFFFi64);
      UFG::SimObjectModifier::Close(&v113);
      UFG::SimObjectModifier::~SimObjectModifier(&v113);
LABEL_87:
      v25 = pos.m_quad.m128_i32[0] + 1;
      pos.m_quad.m128_i32[0] = v25;
      mData = (UFG::qResourceData *)pos.m_quad.m128_u64[1];
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
    LOWORD(BoneID) = -1;
    if ( v104 )
    {
      BoneID = Skeleton::GetBoneID((Skeleton *)v104[3].mNode.mParent, v26->mRenderModelGuid);
      if ( BoneID != -1
        || (mOffset = v26->mPartDetails.mOffset) != 0
        && (v39 = (char *)&v26->mPartDetails + mOffset) != 0i64
        && (BoneID = Skeleton::GetBoneID((Skeleton *)v104[3].mNode.mParent, *((_DWORD *)v39 + 20)), BoneID != -1) )
      {
        v40 = *(_QWORD *)&v104[1].mNode.mChild[0][1].mUID + 48i64 * BoneID;
        v41 = _mm_shuffle_ps(v116.m_rotation.m_vec.m_quad, v116.m_rotation.m_vec.m_quad, 255);
        v42 = _mm_mul_ps(v116.m_rotation.m_vec.m_quad, *(__m128 *)v40);
        v43 = _mm_shuffle_ps(v116.m_rotation.m_vec.m_quad, v116.m_rotation.m_vec.m_quad, 201);
        v44 = _mm_sub_ps(
                _mm_mul_ps(v116.m_rotation.m_vec.m_quad, _mm_shuffle_ps(*(__m128 *)v40, *(__m128 *)v40, 201)),
                _mm_mul_ps(*(__m128 *)v40, v43));
        v45 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(*(__m128 *)v40, _mm_sub_ps(_mm_mul_ps(v41, v41), (__m128)xmmword_141A711B0)),
                  _mm_mul_ps(
                    v116.m_rotation.m_vec.m_quad,
                    _mm_add_ps(
                      _mm_shuffle_ps(v42, v42, 170),
                      _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0))))),
                _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), v41));
        v46 = _mm_add_ps(v116.m_translation.m_quad, _mm_add_ps(v45, v45));
        v47 = *(__m128 *)(v40 + 16);
        v48 = _mm_shuffle_ps(v47, v47, 255);
        v49 = _mm_sub_ps(_mm_mul_ps(v116.m_rotation.m_vec.m_quad, _mm_shuffle_ps(v47, v47, 201)), _mm_mul_ps(v47, v43));
        v50 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v49, v49, 201), _mm_mul_ps(v47, v41)),
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
    mFreeListHead = (UFG::RigidBodyComponent *)UFG::RigidBodyComponent::mAllocator.mFreeListHead;
    if ( UFG::RigidBodyComponent::mAllocator.mFreeListHead )
    {
      UFG::RigidBodyComponent::mAllocator.mFreeListHead = *(char **)UFG::RigidBodyComponent::mAllocator.mFreeListHead;
      v60 = UFG::RigidBodyComponent::mAllocator.mNumSlotsAllocated + 1;
      UFG::RigidBodyComponent::mAllocator.mNumSlotsAllocated = v60;
      if ( UFG::RigidBodyComponent::mAllocator.mMostSlotsAllocated <= v60 )
        UFG::RigidBodyComponent::mAllocator.mMostSlotsAllocated = v60;
      p_transform = mFreeListHead;
    }
    else
    {
      mFreeListHead = (UFG::RigidBodyComponent *)UFG::qMemoryPool::Allocate(
                                                   &gPhysicsMemoryPool,
                                                   0x1D8ui64,
                                                   "RigidBodyComponent",
                                                   0i64,
                                                   1u);
      p_transform = mFreeListHead;
    }
    if ( mFreeListHead )
    {
      UFG::RigidBodyComponent::RigidBodyComponent(mFreeListHead, v26, v31, name[0].mUID, BoneID);
      v27 = v61;
    }
    else
    {
      v27 = 0i64;
    }
    if ( v27 )
    {
      UFG::SimObjectModifier::SimObjectModifier(&v111, simObject, 1);
      UFG::SimObjectModifier::AttachComponent(&v111, v27, 0xFFFFFFFFi64);
      UFG::SimObjectModifier::Close(&v111);
      UFG::SimObjectModifier::~SimObjectModifier(&v111);
      LOBYTE(v62) = 1;
      v27->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor(v27, v62);
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
          p_transform = v66;
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
            v66 = (UFG::allocator::free_link *)p_transform;
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
    mCustomDataSlotIndex = v26->mCustomDataSlotIndex;
    if ( mCustomDataSlotIndex != -1 )
    {
      v70 = *(_QWORD *)(v119 + 112) + 16i64 * mCustomDataSlotIndex;
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
            p_m_Flags = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v76[1].m_Flags;
            if ( v76[1].m_BoundComponentHandles.mNode.mPrev )
            {
              mPrev = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)p_m_Flags->mPrev;
              m_pSimObject = v76[1].m_pSimObject;
              mPrev[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimObject> *, unsigned int))m_pSimObject;
              m_pSimObject->vfptr = mPrev;
              p_m_Flags->mPrev = p_m_Flags;
              v76[1].m_pSimObject = (UFG::SimObject *)&v76[1].m_Flags;
            }
            v76[1].m_BoundComponentHandles.mNode.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v27;
            if ( v27 )
            {
              v80 = v27->m_SafePointerList.mNode.mPrev;
              v80->mNext = p_m_Flags;
              p_m_Flags->mPrev = v80;
              v76[1].m_pSimObject = (UFG::SimObject *)&v27->m_SafePointerList;
              v27->m_SafePointerList.mNode.mPrev = p_m_Flags;
            }
            p_mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27[1].mUserData.simComponent.mNext;
            if ( v27[1].mCollisionMeshBundle.mPrev )
            {
              v82 = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)p_mNext->mPrev;
              m_pPointer = v27[1].mUserData.simComponent.m_pPointer;
              v82[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))m_pPointer;
              m_pPointer->vfptr = v82;
              p_mNext->mPrev = p_mNext;
              v27[1].mUserData.simComponent.m_pPointer = (UFG::RigidBody *)((char *)v27 + 368);
            }
            v27[1].mCollisionMeshBundle.mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)v76;
            if ( v76 )
            {
              v84 = v76->m_SafePointerList.mNode.mPrev;
              v84->mNext = p_mNext;
              p_mNext->mPrev = v84;
              v27[1].mUserData.simComponent.m_pPointer = (UFG::SimComponent *)&v76->m_SafePointerList;
              v76->m_SafePointerList.mNode.mPrev = p_mNext;
              v27->mFlags |= 0x4000u;
            }
            else
            {
              v27->mFlags &= ~0x4000u;
            }
            UFG::SimObjectModifier::SimObjectModifier(&v111, simObject, 1);
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
  v85 = *(_QWORD **)(v119 + 112);
  v105 = v85;
  v86 = 0i64;
  for ( name[0].mUID = 0; (unsigned int)v86 < *((_DWORD *)v105 + 2); v85 = v105 )
  {
    v87 = 5 * v86;
    UFG::qReflectHandleBase::qReflectHandleBase(
      (UFG::qReflectHandleBase *)&v111,
      (UFG::qReflectHandleBase *)(*v85 + 40 * v86));
    TypeName = UFG::qReflectObjectType<UFG::ConstraintDef,UFG::qReflectObject>::GetTypeName(v88);
    v90 = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
    v91 = *((_QWORD *)p_transform + 7);
    v92 = UFG::ReflectionDB::Instance();
    if ( UFG::ReflectionDB::IsDerivedFrom(v92, v91, v90) )
    {
      v93 = *(_QWORD *)(*v105 + 8 * v87 + 32);
      v94 = 0i64;
      v95 = 0i64;
      v96 = 0i64;
      v97 = 0i64;
      v98 = 0i64;
      if ( v17 )
      {
        do
        {
          mNext = v16[v98].mNext;
          v100 = mNext[20].mNext;
          if ( LODWORD(v100[27].mNext) == *(_DWORD *)(v93 + 84) )
          {
            v94 = (hkpRigidBody *)mNext[21].mNext;
            v96 = (UFG::RigidBody *)v16[v98].mNext;
          }
          else if ( LODWORD(v100[27].mNext) == *(_DWORD *)(v93 + 88) )
          {
            v95 = (hkpRigidBody *)mNext[21].mNext;
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
            p_transform = &transform;
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
  }
  if ( v106 )
    UFG::MultiBodyComponent::UpdateCollisionFiltersForConstraints(v106);
  if ( v16 )
    operator delete[](v16);
}

// File Line: 1195
// RVA: 0x455670
void __fastcall UFG::PhysicsSystem::AddRenderHelper(
        UFG::PhysicsSystem *this,
        UFG::SimObjectGame *simObject,
        UFG::RigidBodyComponent *rbc,
        UFG::CollisionInstanceData *instance,
        UFG::CollisionMeshData *mesh)
{
  signed __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::SimComponent *v12; // rax
  UFG::SimComponent *v13; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::PhysicsRenderHelper> *p_mRenderComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::SimObjectModifier v18; // [rsp+38h] [rbp-30h] BYREF

  if ( rbc )
  {
    if ( !simObject
      || ((m_Flags = simObject->m_Flags, (m_Flags & 0x4000) == 0)
        ? (m_Flags >= 0
         ? ((m_Flags & 0x2000) == 0
          ? ((m_Flags & 0x1000) == 0
           ? (ComponentOfType = UFG::SimObject::GetComponentOfType(simObject, UFG::CompositeDrawableComponent::_TypeUID))
           : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  simObject,
                                  UFG::CompositeDrawableComponent::_TypeUID)))
          : (ComponentOfType = simObject->m_Components.p[9].m_pComponent))
         : (ComponentOfType = simObject->m_Components.p[14].m_pComponent))
        : (ComponentOfType = simObject->m_Components.p[14].m_pComponent),
          !ComponentOfType) )
    {
      SimulationMemoryPool = UFG::GetSimulationMemoryPool();
      v11 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x68ui64, "SimComponent", 0i64, 1u);
      if ( v11 )
      {
        UFG::PhysicsRenderHelper::PhysicsRenderHelper((UFG::PhysicsRenderHelper *)v11, instance, mesh);
        v13 = v12;
      }
      else
      {
        v13 = 0i64;
      }
      p_mRenderComponent = &rbc->mRenderComponent;
      if ( rbc->mRenderComponent.m_pPointer )
      {
        mPrev = p_mRenderComponent->mPrev;
        mNext = rbc->mRenderComponent.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mRenderComponent->mPrev = p_mRenderComponent;
        rbc->mRenderComponent.mNext = &rbc->mRenderComponent;
      }
      rbc->mRenderComponent.m_pPointer = v13;
      if ( v13 )
      {
        v17 = v13->m_SafePointerList.mNode.mPrev;
        v17->mNext = p_mRenderComponent;
        p_mRenderComponent->mPrev = v17;
        rbc->mRenderComponent.mNext = &v13->m_SafePointerList.mNode;
        v13->m_SafePointerList.mNode.mPrev = p_mRenderComponent;
      }
      UFG::SimObjectModifier::SimObjectModifier(&v18, simObject, 1);
      UFG::SimObjectModifier::AttachComponent(&v18, v13, 0xFFFFFFFFi64);
      UFG::SimObjectModifier::Close(&v18);
      UFG::SimObjectModifier::~SimObjectModifier(&v18);
    }
  }
}

// File Line: 1212
// RVA: 0x455060
void __fastcall UFG::PhysicsSystem::AddParkourAndCover(
        UFG::PhysicsSystem *this,
        UFG::SimObject *simObject,
        UFG::RigidBodyComponent *rbc,
        UFG::CollisionMeshData *mesh,
        int followBone)
{
  unsigned int mParkourGuid; // edi
  UFG::SimComponent *v9; // rbx
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::ParkourComponent> *p_mParkourComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  unsigned int mCoverGuid; // edi
  UFG::allocator::free_link *v18; // rax
  UFG::SimComponent *v19; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::DynamicCoverComponent> *p_mCoverComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::SimObjectModifier v24; // [rsp+28h] [rbp-40h] BYREF

  mParkourGuid = mesh->mParkourGuid;
  v9 = 0i64;
  if ( mParkourGuid )
  {
    v10 = UFG::qMalloc(0xC8ui64, "ParkourComponent", 0x800ui64);
    if ( v10 )
    {
      UFG::ParkourComponent::ParkourComponent((UFG::ParkourComponent *)v10, mParkourGuid, followBone);
      v12 = v11;
    }
    else
    {
      v12 = 0i64;
    }
    p_mParkourComponent = &rbc->mParkourComponent;
    if ( rbc->mParkourComponent.m_pPointer )
    {
      mPrev = p_mParkourComponent->mPrev;
      mNext = rbc->mParkourComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mParkourComponent->mPrev = p_mParkourComponent;
      rbc->mParkourComponent.mNext = &rbc->mParkourComponent;
    }
    rbc->mParkourComponent.m_pPointer = v12;
    if ( v12 )
    {
      v16 = v12->m_SafePointerList.mNode.mPrev;
      v16->mNext = p_mParkourComponent;
      p_mParkourComponent->mPrev = v16;
      rbc->mParkourComponent.mNext = &v12->m_SafePointerList.mNode;
      v12->m_SafePointerList.mNode.mPrev = p_mParkourComponent;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v24, simObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v24, v12, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v24);
    UFG::SimObjectModifier::~SimObjectModifier(&v24);
  }
  mCoverGuid = mesh->mCoverGuid;
  if ( mCoverGuid )
  {
    v18 = UFG::qMalloc(0x88ui64, "DynamicCoverComponent", 0x800ui64);
    if ( v18 )
    {
      UFG::DynamicCoverComponent::DynamicCoverComponent((UFG::DynamicCoverComponent *)v18, mCoverGuid);
      v9 = v19;
    }
    p_mCoverComponent = &rbc->mCoverComponent;
    if ( rbc->mCoverComponent.m_pPointer )
    {
      v21 = p_mCoverComponent->mPrev;
      v22 = rbc->mCoverComponent.mNext;
      v21->mNext = v22;
      v22->mPrev = v21;
      p_mCoverComponent->mPrev = p_mCoverComponent;
      rbc->mCoverComponent.mNext = &rbc->mCoverComponent;
    }
    rbc->mCoverComponent.m_pPointer = v9;
    if ( v9 )
    {
      v23 = v9->m_SafePointerList.mNode.mPrev;
      v23->mNext = p_mCoverComponent;
      p_mCoverComponent->mPrev = v23;
      rbc->mCoverComponent.mNext = &v9->m_SafePointerList.mNode;
      v9->m_SafePointerList.mNode.mPrev = p_mCoverComponent;
    }
    UFG::SimObjectModifier::SimObjectModifier(&v24, simObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v24, v9, 0xFFFFFFFFi64);
    UFG::SimObjectModifier::Close(&v24);
    UFG::SimObjectModifier::~SimObjectModifier(&v24);
  }
}

// File Line: 1233
// RVA: 0x455930
void __fastcall UFG::PhysicsSystem::AddStateMachines(
        UFG::PhysicsSystem *this,
        UFG::SimObject *simObject,
        UFG::RigidBodyComponent *rbc,
        UFG::CollisionInstanceData *instance,
        UFG::CollisionMeshData *mesh)
{
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v8; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  UFG::StateMachineComponent *v11; // rbx
  unsigned int mParent_high; // edx
  UFG::qBaseTreeRB *v13; // rax
  unsigned __int64 mParent; // rdi
  UFG::allocator::free_link *v15; // rax
  UFG::StateMachineComponent *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *p_mRigidBodyComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  unsigned __int64 v21; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v22; // rcx
  const char *v23; // rax
  unsigned int mNumParts; // edx
  unsigned int v25; // r14d
  UFG::qOffset64<UFG::CollisionMeshData::Part *> *p_mParts; // r13
  __int64 v27; // r12
  char *v28; // rdi
  unsigned __int64 v29; // rdi
  unsigned int v30; // edx
  UFG::qBaseTreeRB *v31; // rax
  UFG::allocator::free_link *v32; // rax
  UFG::StateMachineComponent *v33; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v34; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v37; // rax
  UFG::allocator::free_link *v38; // rax
  UFG::qReflectInventoryBase *v39; // rax
  UFG::qReflectInventoryBase *v40; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNeighbours; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v42; // rcx
  UFG::qTree64Base::BaseNode *v43; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v44; // rax
  unsigned int v45; // [rsp+30h] [rbp-91h]
  unsigned __int64 v46; // [rsp+38h] [rbp-89h]
  UFG::SimObjectModifier v47; // [rsp+40h] [rbp-81h] BYREF
  UFG::qReflectHandleBase v48; // [rsp+60h] [rbp-61h] BYREF
  UFG::qReflectHandleBase v49; // [rsp+88h] [rbp-39h] BYREF
  __int64 v50; // [rsp+B0h] [rbp-11h]
  UFG::qReflectHandleBase v51; // [rsp+B8h] [rbp-9h] BYREF

  if ( rbc )
  {
    v50 = -2i64;
    UFG::qReflectHandleBase::qReflectHandleBase(&v51);
    TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v8);
    v51.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
    mCollisionMeshData = rbc->mCollisionMeshData;
    if ( mCollisionMeshData )
      UFG::qReflectHandleBase::operator=(&v51, &mCollisionMeshData->mObjectProperties);
    v11 = 0i64;
    mParent_high = HIDWORD(v51.mData[4].mBaseNode.mParent);
    if ( mParent_high )
    {
      v13 = UFG::qBaseTreeRB::Get(&UFG::StateMachineDefinition::mGuidTranslation.mTree, mParent_high);
      if ( v13 )
      {
        mParent = (unsigned __int64)v13->mNULL.mParent;
        if ( mParent )
        {
          v15 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x120ui64, "StateMachineComponent", 0i64, 1u);
          if ( v15 )
          {
            UFG::StateMachineComponent::StateMachineComponent((UFG::StateMachineComponent *)v15, mParent, -1);
            v11 = v16;
          }
          else
          {
            v11 = 0i64;
          }
          p_mRigidBodyComponent = &v11->mRigidBodyComponent;
          if ( v11->mRigidBodyComponent.m_pPointer )
          {
            mPrev = p_mRigidBodyComponent->mPrev;
            mNext = v11->mRigidBodyComponent.mNext;
            mPrev->mNext = mNext;
            mNext->mPrev = mPrev;
            p_mRigidBodyComponent->mPrev = p_mRigidBodyComponent;
            v11->mRigidBodyComponent.mNext = &v11->mRigidBodyComponent;
          }
          v11->mRigidBodyComponent.m_pPointer = rbc;
          v20 = rbc->m_SafePointerList.mNode.UFG::RigidBody::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
          v20->mNext = p_mRigidBodyComponent;
          p_mRigidBodyComponent->mPrev = v20;
          v11->mRigidBodyComponent.mNext = &rbc->m_SafePointerList.mNode;
          rbc->m_SafePointerList.mNode.UFG::RigidBody::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_mRigidBodyComponent;
          UFG::RigidBodyComponent::SetStateMachineComponent(rbc, v11);
          UFG::SimObjectModifier::SimObjectModifier(&v47, simObject, 1);
          UFG::SimObjectModifier::AttachComponent(&v47, v11, 0xFFFFFFFFi64);
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
    mNumParts = mesh->mNumParts;
    if ( instance->mNumParts < mNumParts )
      mNumParts = instance->mNumParts;
    v45 = mNumParts;
    v25 = 0;
    if ( mNumParts )
    {
      p_mParts = &mesh->mParts;
      v27 = 0i64;
      do
      {
        if ( p_mParts->mOffset )
          v28 = (char *)p_mParts + p_mParts->mOffset;
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
            mNumParts = v45;
            goto LABEL_42;
          }
          v21 = (unsigned __int64)v31->mNULL.mParent;
          mNumParts = v45;
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
                v34->mPrev = v34;
                v11->mRigidBodyComponent.mNext = &v11->mRigidBodyComponent;
              }
              v11->mRigidBodyComponent.m_pPointer = rbc;
              v37 = rbc->m_SafePointerList.mNode.UFG::RigidBody::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
              v37->mNext = v34;
              v34->mPrev = v37;
              v11->mRigidBodyComponent.mNext = &rbc->m_SafePointerList.mNode;
              rbc->m_SafePointerList.mNode.UFG::RigidBody::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = v34;
              UFG::RigidBodyComponent::SetStateMachineComponent(rbc, v11);
              UFG::SimObjectModifier::SimObjectModifier(&v47, simObject, 1);
              UFG::SimObjectModifier::AttachComponent(&v47, v11, 0xFFFFFFFFi64);
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
            mNeighbours = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v40->mItems.mTree.mHead.mNeighbours;
            if ( v40->mItems.mTree.mCount )
            {
              v42 = mNeighbours->mPrev;
              v43 = v40->mItems.mTree.mHead.mNeighbours[1];
              v42->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v43;
              v43->mUID = (unsigned __int64)v42;
              mNeighbours->mPrev = mNeighbours;
              v40->mItems.mTree.mHead.mNeighbours[1] = (UFG::qTree64Base::BaseNode *)v40->mItems.mTree.mHead.mNeighbours;
            }
            v40->mItems.mTree.mCount = (__int64)rbc;
            v44 = rbc->m_SafePointerList.mNode.UFG::RigidBody::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
            v44->mNext = mNeighbours;
            mNeighbours->mPrev = v44;
            v40->mItems.mTree.mHead.mNeighbours[1] = (UFG::qTree64Base::BaseNode *)&rbc->m_SafePointerList;
            rbc->m_SafePointerList.mNode.UFG::RigidBody::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = mNeighbours;
            UFG::StateMachineComponent::AddChildMachine(v11, v40);
          }
          UFG::qReflectHandleBase::~qReflectHandleBase(&v48);
          goto LABEL_41;
        }
LABEL_42:
        ++v25;
        v27 += 48i64;
      }
      while ( v25 < mNumParts );
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
  UFG::RigidBody *p_mNext; // rdi
  unsigned int mFlags; // eax
  bool v5; // cl
  unsigned int mNumParts; // r14d
  UFG::CollisionMeshData *mCollisionMeshData; // r15
  hkpRigidBody *mBody; // rax
  hkVector4f v9; // xmm1
  hkVector4f v10; // xmm2
  hkVector4f v11; // xmm3
  unsigned int v12; // esi
  __int64 v13; // rbx
  UFG::CollisionInstanceData::Part *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  unsigned int v17; // eax
  __int64 v18; // rdx
  unsigned int v19; // r12d
  __int64 v20; // rcx
  hkpRigidBody *v21; // rax
  hkVector4f v22; // xmm1
  hkVector4f v23; // xmm2
  hkVector4f v24; // xmm3
  BOOL v25; // r13d
  unsigned __int16 v26; // r15
  int v27; // esi
  __int64 v28; // rbx
  __int64 v29; // rax
  __int64 v30; // rdx
  UFG::qSymbol *v31; // r14
  UFG::qPropertySet *PropertySet; // rsi
  UFG::SimObject *v33; // rax
  __int64 v34; // rdx
  _QWORD *v35; // rcx
  _QWORD *p_mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v37; // rax
  __int64 v38; // [rsp+30h] [rbp-D0h]
  hkTransformf a; // [rsp+40h] [rbp-C0h] BYREF
  hkVector4f v40; // [rsp+80h] [rbp-80h] BYREF
  hkVector4f p; // [rsp+90h] [rbp-70h] BYREF
  hkVector4f v42; // [rsp+A0h] [rbp-60h] BYREF
  __int64 v43; // [rsp+B0h] [rbp-50h]
  hkTransformf transformOut; // [rsp+C0h] [rbp-40h] BYREF
  UFG::qString v45; // [rsp+100h] [rbp+0h] BYREF
  hkTransformf v46; // [rsp+130h] [rbp+30h] BYREF
  UFG::qMatrix44 d[2]; // [rsp+170h] [rbp+70h] BYREF
  UFG::qSymbol name; // [rsp+208h] [rbp+108h] BYREF
  char *v50; // [rsp+210h] [rbp+110h]
  __int64 v51; // [rsp+218h] [rbp+118h]

  v43 = -2i64;
  v1 = this;
  v2 = (char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280;
  v50 = (char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280;
  p_mNext = (UFG::RigidBody *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
  if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
  {
    do
    {
      v38 = (__int64)&p_mNext[1].m_SafePointerList.mNode.mPrev[-18].mNext;
      mFlags = p_mNext->mFlags;
      if ( (mFlags & 8) == 0 )
      {
        if ( (mFlags & 1) != 0 )
        {
          if ( (mFlags & 2) != 0 )
          {
            v5 = (mFlags & 0x80u) != 0 && !UFG::RigidBody::IsSleeping(p_mNext);
            p.m_quad = (__m128)p_mNext->mBody->m_motion.m_motionState.m_transform.m_translation;
            if ( (!v5 || p_mNext->mWindAction)
              && !UFG::ActiveRegionManager::IsInActiveRegion(&v1->mActiveRegionManager, &p) )
            {
              ((void (__fastcall *)(UFG::RigidBody *))p_mNext->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(p_mNext);
            }
            v2 = v50;
          }
        }
        else if ( (mFlags & 2) != 0 )
        {
          mNumParts = p_mNext->mInstanceData->mNumParts;
          if ( mNumParts )
          {
            mCollisionMeshData = p_mNext->mCollisionMeshData;
            mBody = p_mNext->mBody;
            v9.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col1;
            v10.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col2;
            v11.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_translation;
            a.m_rotation.m_col0 = mBody->m_motion.m_motionState.m_transform.m_rotation.m_col0;
            a.m_rotation.m_col1 = (hkVector4f)v9.m_quad;
            a.m_rotation.m_col2 = (hkVector4f)v10.m_quad;
            a.m_translation = (hkVector4f)v11.m_quad;
            v12 = 0;
            v13 = 0i64;
            do
            {
              if ( p_mNext->mInstanceData->mParts[v13].mSimObject.m_pPointer )
              {
                UFG::GetTransformFromShapeKey(&transformOut, mCollisionMeshData->mShape, v12);
                hkVector4f::setTransformedPos(&v42, &a, &transformOut.m_translation);
                if ( !UFG::ActiveRegionManager::IsInActiveRegion(&v1->mActiveRegionManager, &v42) )
                {
                  UFG::Simulation::DestroySimObject(
                    &UFG::gSim,
                    p_mNext->mInstanceData->mParts[v13].mSimObject.m_pPointer);
                  v14 = &p_mNext->mInstanceData->mParts[v13];
                  if ( v14->mSimObject.m_pPointer )
                  {
                    mPrev = v14->mSimObject.mPrev;
                    mNext = v14->mSimObject.mNext;
                    mPrev->mNext = mNext;
                    mNext->mPrev = mPrev;
                    v14->mSimObject.mPrev = &v14->mSimObject;
                    v14->mSimObject.mNext = &v14->mSimObject;
                  }
                  v14->mSimObject.m_pPointer = 0i64;
                }
              }
              ++v12;
              ++v13;
            }
            while ( v12 < mNumParts );
            v2 = v50;
          }
        }
        v17 = p_mNext->mFlags;
        if ( (v17 & 1) != 0 && (v17 & 2) == 0 )
        {
          if ( UFG::ActiveRegionManager::IsInActiveRegion(&v1->mActiveRegionManager, &p_mNext->mInstanceData->mPosition) )
          {
            LOBYTE(v18) = 1;
            p_mNext->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor(p_mNext, v18);
          }
LABEL_49:
          v2 = v50;
          goto LABEL_50;
        }
        v19 = p_mNext->mInstanceData->mNumParts;
        if ( v19 )
        {
          v20 = (__int64)p_mNext->mCollisionMeshData;
          v51 = v20;
          v21 = p_mNext->mBody;
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
              v28 = (__int64)&p_mNext->mInstanceData->mParts[v26];
              v29 = *(_QWORD *)(v20 + 160);
              if ( v29 )
                v30 = v29 + v20 + 160;
              else
                v30 = 0i64;
              v31 = (UFG::qSymbol *)(v30 + 96i64 * (v27 + v25));
              if ( v31[18].mUID != -1
                && !*(_QWORD *)(v28 + 16)
                && !(unsigned int)UFG::RigidBody::IsPartFractured(p_mNext, v27 + v25) )
              {
                UFG::GetTransformFromShapeKey(&transformOut, *(hkpShape **)(v51 + 192), v27);
                hkVector4f::setTransformedPos(&v40, &a, &transformOut.m_translation);
                if ( UFG::ActiveRegionManager::IsInActiveRegion(&this->mActiveRegionManager, &v40) )
                {
                  PropertySet = UFG::PropertySetManager::FindPropertySet(v31 + 18);
                  if ( PropertySet )
                  {
                    hkTransformf::setMul(&v46, &a, &transformOut);
                    hkTransformf::get4x4ColumnMajor(&v46, &d[0].v0.x);
                    name.mUID = *(_DWORD *)(v28 + 24);
                    while ( UFG::Simulation::GetSimObject(&UFG::gSim, &name) )
                    {
                      UFG::qString::qString(&v45, "Physics-%d", (unsigned int)++count_2);
                      UFG::qSymbol::set_from_cstr(&name, v45.mData);
                      UFG::qString::~qString(&v45);
                    }
                    v33 = UFG::SpawnInfoInterface::SpawnObject(&name, PropertySet, d, Count, 0i64, 0i64);
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
                      p_mPrev = &v33->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
                      v37 = v33->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
                      v37->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v28;
                      *(_QWORD *)v28 = v37;
                      *(_QWORD *)(v28 + 8) = p_mPrev;
                      *p_mPrev = v28;
                    }
                  }
                }
              }
              v27 = ++v26;
              v20 = v51;
            }
            while ( v26 < v19 );
          }
          v1 = this;
          goto LABEL_49;
        }
      }
LABEL_50:
      p_mNext = (UFG::RigidBody *)v38;
    }
    while ( (char *)v38 != v2 );
  }
}

// File Line: 1456
// RVA: 0x476590
void __fastcall UFG::PhysicsSystem::SuspendPhysicsComponents(UFG::PhysicsSystem *this, UFG::SimObjectGame *simObject)
{
  signed __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::TransformNodeComponent *ComponentOfType; // rbx
  signed __int16 v6; // cx
  UFG::SimComponent *v7; // rax
  UFG::TransformNodeComponent *v8; // rbx

  if ( simObject )
  {
    m_Flags = simObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(simObject, UFG::RigidBodyComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(simObject, UFG::RigidBodyComponent::_TypeUID);
    ComponentOfType = (UFG::TransformNodeComponent *)ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      do
      {
        ((void (__fastcall *)(UFG::TransformNodeComponent *))ComponentOfType->vfptr[8].__vecDelDtor)(ComponentOfType);
        ComponentOfType = UFG::SimObject::GetComponentOfType(
                            ComponentOfType->m_pSimObject,
                            UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                            0,
                            ComponentOfType);
      }
      while ( ComponentOfType );
    }
    v6 = simObject->m_Flags;
    if ( (v6 & 0x4000) != 0 || v6 < 0 || (v6 & 0x2000) != 0 || (v6 & 0x1000) != 0 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(simObject, UFG::ParkourComponent::_TypeUID);
    else
      v7 = UFG::SimObject::GetComponentOfType(simObject, UFG::ParkourComponent::_TypeUID);
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
               v8);
      }
      while ( v8 );
    }
  }
}

// File Line: 1475
// RVA: 0x474120
void __fastcall UFG::PhysicsSystem::RestorePhysicsComponents(UFG::PhysicsSystem *this, UFG::SimObjectGame *simObject)
{
  signed __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::TransformNodeComponent *ComponentOfType; // rbx
  signed __int16 v6; // cx
  UFG::SimComponent *v7; // rax
  UFG::TransformNodeComponent *v8; // rbx

  if ( simObject )
  {
    m_Flags = simObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(simObject, UFG::RigidBodyComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(simObject, UFG::RigidBodyComponent::_TypeUID);
    ComponentOfType = (UFG::TransformNodeComponent *)ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      do
      {
        ((void (__fastcall *)(UFG::TransformNodeComponent *))ComponentOfType->vfptr[9].__vecDelDtor)(ComponentOfType);
        ComponentOfType = UFG::SimObject::GetComponentOfType(
                            ComponentOfType->m_pSimObject,
                            UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                            0,
                            ComponentOfType);
      }
      while ( ComponentOfType );
    }
    v6 = simObject->m_Flags;
    if ( (v6 & 0x4000) != 0 || v6 < 0 || (v6 & 0x2000) != 0 || (v6 & 0x1000) != 0 )
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(simObject, UFG::ParkourComponent::_TypeUID);
    else
      v7 = UFG::SimObject::GetComponentOfType(simObject, UFG::ParkourComponent::_TypeUID);
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
               v8);
      }
      while ( v8 );
    }
  }
}

// File Line: 1494
// RVA: 0x47AAC0
void __fastcall UFG::PhysicsSystem::Update(UFG::PhysicsSystem *this, float timestep)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qBaseTreeRB *i; // rdi
  unsigned int j; // ebx
  __m128 *v7; // rcx
  int v8; // eax
  __m128 v9; // xmm3
  __m128 v10; // xmm3
  __m128 v11; // xmm3
  __m128 v12; // xmm1
  float v13; // xmm4_4
  _QWORD *v14; // rcx
  UFG::SimObjectGame *v15; // rdx
  __m128 v16; // xmm0
  double v17; // xmm1_8
  __m128 v18; // xmm6
  __m128 v19; // xmm0
  __m128 v20; // xmm7
  __m128 v21; // xmm0
  hkArray<hkpEntity *,hkContainerHeapAllocator> entitiesToAdd; // [rsp+28h] [rbp-80h] BYREF
  hkVector4f centre; // [rsp+40h] [rbp-68h] BYREF
  hkVector4f result; // [rsp+50h] [rbp-58h] BYREF
  hkVector4f location; // [rsp+60h] [rbp-48h] BYREF

  if ( LocalPlayer )
  {
    m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    centre.m_quad = _mm_unpacklo_ps(
                      _mm_unpacklo_ps(
                        (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.x),
                        (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.z)),
                      _mm_unpacklo_ps(
                        (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y),
                        (__m128)(unsigned int)FLOAT_1_0));
    UFG::ActiveRegionManager::SetCentre(&this->mActiveRegionManager, &centre);
  }
  UFG::BasePhysicsSystem::BeginRemoveEntityBatch(this);
  UFG::ActiveRegionManager::GetCentre(&this->mActiveRegionManager, &result);
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_14216D960);
        i;
        i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_14216D960, &i->mRoot) )
  {
    for ( j = 0; j < i[1].mRoot.mUID; ++j )
    {
      v7 = (__m128 *)*((_QWORD *)&i[1].mRoot.mChild[1]->mParent + j);
      v8 = v7[5].m128_i32[2];
      if ( (v8 & 1) != 0 && (v8 & 2) == 0 )
      {
        v9 = _mm_sub_ps(v7[2], result.m_quad);
        v10 = _mm_mul_ps(v9, v9);
        v11 = _mm_add_ps(
                _mm_shuffle_ps(v10, v10, 170),
                _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)));
        v12 = _mm_rsqrt_ps(v11);
        LODWORD(v13) = _mm_andnot_ps(
                         _mm_cmple_ps(v11, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
                             _mm_mul_ps(*(__m128 *)_xmm, v12)),
                           v11)).m128_u32[0];
        v14 = (_QWORD *)v7[4].m128_u64[0];
        if ( v14 )
        {
          v15 = (UFG::SimObjectGame *)v14[5];
          if ( v13 >= VERY_LOW_LOD_RADIUS.m_real.m128_f32[0] )
          {
            if ( v15 )
              UFG::PhysicsSystem::SuspendPhysicsComponents(this, v15);
            else
              (*(void (__fastcall **)(_QWORD *))(*v14 + 64i64))(v14);
          }
          else if ( v15 )
          {
            UFG::PhysicsSystem::RestorePhysicsComponents(this, v15);
          }
          else
          {
            (*(void (__fastcall **)(_QWORD *))(*v14 + 72i64))(v14);
          }
        }
      }
    }
  }
  entitiesToAdd.m_data = 0i64;
  entitiesToAdd.m_size = 0;
  entitiesToAdd.m_capacityAndFlags = 0x80000000;
  UFG::CharacterPhysicsComponentManager::GetEntitiesForBatchOperations(
    UFG::CharacterPhysicsComponentManager::mInstance,
    &entitiesToAdd,
    &this->mEntitiesToRemove);
  if ( entitiesToAdd.m_size )
    hkpWorld::addEntityBatch(this->mWorld, entitiesToAdd.m_data, entitiesToAdd.m_size, HK_ENTITY_ACTIVATION_DO_ACTIVATE);
  UFG::WorldCollisionListener::BeginFrame(UFG::WorldCollisionListener::mInstance);
  UFG::ExplosionManager::Update(timestep);
  UFG::PhysicsSystem::ManageActiveRegions(this);
  UFG::BasePhysicsSystem::EndRemoveEntityBatch(this);
  entitiesToAdd.m_size = 0;
  if ( entitiesToAdd.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      entitiesToAdd.m_data,
      8 * entitiesToAdd.m_capacityAndFlags);
  entitiesToAdd.m_data = 0i64;
  entitiesToAdd.m_capacityAndFlags = 0x80000000;
  UFG::BasePhysicsSystem::Update(this, timestep);
  UFG::WorldCollisionListener::EndFrame(UFG::WorldCollisionListener::mInstance, this->mWorld);
  UFG::Destruction::Update(UFG::Destruction::mInstance);
  UFG::PhantomCallback::Update(UFG::PhantomCallback::mInstance, timestep);
  v16 = (__m128)LODWORD(UFG::WindAction::mWindTicker);
  UFG::WindAction::mWindTicker = UFG::WindAction::mWindTicker + timestep;
  *(_QWORD *)&v17 = LODWORD(UFG::WindAction::gWindDirectionFrequency);
  *(float *)&v17 = UFG::WindAction::gWindDirectionFrequency * UFG::WindAction::mWindTicker;
  v16.m128_f32[0] = UFG::qNoise<float,float>::GetValue(&UFG::WindAction::mWindTurbulance, v17);
  v18 = v16;
  v18.m128_f32[0] = v16.m128_f32[0] * 3.1415999;
  v19 = v18;
  v19.m128_f32[0] = cosf(v18.m128_f32[0]);
  v20 = v19;
  v21 = v18;
  v21.m128_f32[0] = sinf(v18.m128_f32[0]);
  UFG::WindAction::mWindDirection.m_quad = _mm_unpacklo_ps(
                                             _mm_unpacklo_ps(v20, (__m128)0i64),
                                             _mm_unpacklo_ps(v21, (__m128)0i64));
  UFG::WindAction::mWindPerp.m_quad = _mm_unpacklo_ps(
                                        _mm_unpacklo_ps(v21, (__m128)0i64),
                                        _mm_unpacklo_ps(_mm_xor_ps(v20, *(__m128 *)_xmm), (__m128)0i64));
  UFG::PhysicsSystem::DeleteEntitiesLeftBroadphase(this);
  UFG::PhysicsSystem::UpdateWater(this, timestep);
  UFG::PhysicsSystem::MakeStaticSceneryInvisible(this);
  UFG::ActiveRegionManager::GetCentre(&this->mActiveRegionManager, &location);
  UFG::Constraint::GenerateAudioEvents(&location);
}

// File Line: 1679
// RVA: 0x454D20
// attributes: thunk
void __fastcall UFG::PhysicsSystem::AddCollisionInstanceToWorld(
        UFG::PhysicsSystem *this,
        UFG::CollisionInstanceData *instance)
{
  UFG::BasePhysicsSystem::AddCollisionInstanceToWorld(this, instance);
}

// File Line: 1706
// RVA: 0x45A140
char __fastcall UFG::PhysicsSystem::CastAsyncRay(
        UFG::PhysicsSystem *this,
        UFG::qVector3 *rayStart,
        UFG::qVector3 *rayEnd,
        int collisionFilter,
        void (__fastcall *callback)(UFG::RayCastData *, UFG::SimComponent *, void *),
        UFG::SimComponent *simComponent,
        void *userData)
{
  if ( !this->mBuildingAiData
    && (UFG::gFlowController.mCurrentState
     && UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED)
     || UFG::Metrics::msInstance.mSimTimeDelta <= 0.0) )
  {
    return 0;
  }
  else
  {
    return UFG::BasePhysicsSystem::CastAsyncRay(
             this,
             rayStart,
             rayEnd,
             collisionFilter,
             callback,
             simComponent,
             userData);
  }
}

// File Line: 1724
// RVA: 0x45A1E0
char __fastcall UFG::PhysicsSystem::CastAsyncShape(
        UFG::PhysicsSystem *this,
        UFG::AsyncShapeCasterCollector *caster,
        UFG::SimComponent *simComponent,
        void *userData)
{
  if ( !this->mBuildingAiData
    && (UFG::gFlowController.mCurrentState
     && UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED)
     || UFG::Metrics::msInstance.mSimTimeDelta <= 0.0) )
  {
    return 0;
  }
  else
  {
    return UFG::BasePhysicsSystem::CastAsyncShape(this, caster, simComponent, userData);
  }
}

// File Line: 1765
// RVA: 0x464830
char __fastcall UFG::PhysicsSystem::FindParentObjectOfSimObject(
        UFG::SimObject *simObjectToFind,
        UFG::RigidBodyComponent **parentOut,
        unsigned int *indexOut)
{
  UFG::RigidBodyComponent *v6; // r10
  UFG::CollisionInstanceData *mInstanceData; // rax
  unsigned int v8; // ecx
  unsigned int mNumParts; // edx
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *p_mNext; // r8
  UFG::SimObject **p_m_pPointer; // rax
  char result; // al

  if ( !simObjectToFind
    || (v6 = (UFG::RigidBodyComponent *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext,
        &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext == (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280)) )
  {
LABEL_8:
    *parentOut = 0i64;
    result = 0;
    *indexOut = -1;
  }
  else
  {
    while ( 1 )
    {
      mInstanceData = v6->mInstanceData;
      v8 = 0;
      mNumParts = mInstanceData->mNumParts;
      p_mNext = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&v6->mNext[-18].mNext;
      if ( mNumParts )
        break;
LABEL_7:
      v6 = (UFG::RigidBodyComponent *)&v6->mNext[-18].mNext;
      if ( p_mNext == (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                        - 280) )
        goto LABEL_8;
    }
    p_m_pPointer = &mInstanceData->mParts->mSimObject.m_pPointer;
    while ( *p_m_pPointer != simObjectToFind )
    {
      ++v8;
      p_m_pPointer += 4;
      if ( v8 >= mNumParts )
        goto LABEL_7;
    }
    *parentOut = v6;
    *indexOut = v8;
    return 1;
  }
  return result;
}

// File Line: 2030
// RVA: 0x461EB0
void __fastcall UFG::PhysicsSystem::DisableStaticSceneryInstance(
        UFG::PhysicsSystem *this,
        unsigned int sceneryGuid,
        UFG::qVector3 *pos)
{
  UFG::allocator::free_link *v6; // rax
  UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *v7; // r9
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *mPrev; // rax

  v6 = UFG::qMalloc(0x20ui64, "StaticSceneryTracking", 0i64);
  v7 = (UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *)v6;
  if ( v6 )
  {
    v6->mNext = v6;
    v6[1].mNext = v6;
    y = pos->y;
    z = pos->z;
    *(float *)&v6[2].mNext = pos->x;
    *((float *)&v6[2].mNext + 1) = y;
    *(float *)&v6[3].mNext = z;
    HIDWORD(v6[3].mNext) = sceneryGuid;
  }
  else
  {
    v7 = 0i64;
  }
  mPrev = this->mStaticSceneryToDisable.mNode.mPrev;
  mPrev->mNext = v7;
  v7->mPrev = mPrev;
  v7->mNext = &this->mStaticSceneryToDisable.mNode;
  this->mStaticSceneryToDisable.mNode.mPrev = v7;
}

// File Line: 2039
// RVA: 0x46C3E0
void __fastcall UFG::PhysicsSystem::MakeStaticSceneryInvisible(UFG::PhysicsSystem *this)
{
  UFG::PhysicsSystem *v1; // r15
  UFG::qList<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking,1,0> *p_mStaticSceneryToDisable; // r12
  char *v3; // rax
  UFG::qTaskGroup *v4; // rsi
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *mSingleFrameTaskGroups; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *mPrev; // rax
  UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *mNext; // rdi
  UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *v8; // rcx
  UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *v9; // rax
  UFG::qBaseTreeRB *Head; // rbp
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *p_mTasks; // r14
  UFG::allocator::free_link *v12; // rax
  UFG::allocator::free_link *v13; // rbx
  int mPrev_high; // xmm1_4
  int v15; // xmm2_4
  UFG::qNode<SceneryToDisable,SceneryToDisable> *v16; // rax
  char *v17; // rax
  char *v18; // rdx
  UFG::qSpuElf *mSpuElf; // rax
  void (__fastcall *mTaskFunctionSPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *mTaskFunctionPPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *mTaskFunctionOffload)(void *, void *, void *, void *); // r9
  char *mAddress; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v24; // rax
  UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *v25; // rdx
  UFG::qNode<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking> *v26; // rax
  UFG::qNode<SceneryToDisable,SceneryToDisable> *v27; // rbx
  UFG::qNode<SceneryToDisable,SceneryToDisable> *v28; // rcx
  UFG::qNode<SceneryToDisable,SceneryToDisable> *v29; // rax
  UFG::SceneryGroup *v30; // rcx
  UFG::qNode<SceneryToDisable,SceneryToDisable> *v31; // rdx
  UFG::qNode<SceneryToDisable,SceneryToDisable> *v32; // rax
  unsigned int mNext_high; // [rsp+78h] [rbp+10h]

  v1 = this;
  p_mStaticSceneryToDisable = &this->mStaticSceneryToDisable;
  if ( (UFG::qList<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking,1,0> *)this->mStaticSceneryToDisable.mNode.mNext != &this->mStaticSceneryToDisable )
  {
    v3 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
    v4 = (UFG::qTaskGroup *)v3;
    if ( v3 )
      UFG::qTaskGroup::qTaskGroup((UFG::qTaskGroup *)v3, "testTaskGroup");
    mSingleFrameTaskGroups = UFG::gTaskManager.mSingleFrameTaskGroups;
    mPrev = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
    mPrev->mNext = v4;
    v4->mPrev = mPrev;
    v4->mNext = &mSingleFrameTaskGroups->mNode;
    mSingleFrameTaskGroups->mNode.mPrev = v4;
    while ( (UFG::qList<UFG::PhysicsSystem::StaticSceneryTracking,UFG::PhysicsSystem::StaticSceneryTracking,1,0> *)p_mStaticSceneryToDisable->mNode.mNext != p_mStaticSceneryToDisable )
    {
      mNext = v1->mStaticSceneryToDisable.mNode.mNext;
      v8 = mNext->mPrev;
      v9 = mNext->mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      mNext_high = HIDWORD(mNext[1].mNext);
      Head = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423A9A90);
      if ( Head )
      {
        p_mTasks = &v4->mTasks;
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
          mPrev_high = HIDWORD(mNext[1].mPrev);
          v15 = (int)mNext[1].mNext;
          LODWORD(v13[2].mNext) = mNext[1].mPrev;
          HIDWORD(v13[2].mNext) = mPrev_high;
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
            *((_QWORD *)v17 + 2) = v17 + 16;
            *((_QWORD *)v17 + 3) = v17 + 16;
            mSpuElf = gTaskFunctionDeclData_MakeStaticSceneryInvisibleTask.mSpuElf;
            mTaskFunctionSPU = gTaskFunctionDeclData_MakeStaticSceneryInvisibleTask.mTaskFunctionSPU;
            mTaskFunctionPPU = gTaskFunctionDeclData_MakeStaticSceneryInvisibleTask.mTaskFunctionPPU;
            mTaskFunctionOffload = gTaskFunctionDeclData_MakeStaticSceneryInvisibleTask.mTaskFunctionOffload;
            if ( !gTaskFunctionDeclData_MakeStaticSceneryInvisibleTask.mCurrentSPUEnabled )
            {
              mSpuElf = 0i64;
              mTaskFunctionSPU = 0i64;
              mTaskFunctionOffload = 0i64;
            }
            *((_QWORD *)v18 + 6) = v4;
            *((_DWORD *)v18 + 14) = 2;
            *((_QWORD *)v18 + 4) = 0i64;
            *((_QWORD *)v18 + 5) = 0i64;
            *((_QWORD *)v18 + 8) = &gTaskFunctionDeclData_MakeStaticSceneryInvisibleTask;
            if ( mSpuElf )
              mAddress = mSpuElf->mAddress;
            else
              mAddress = 0i64;
            *((_QWORD *)v18 + 9) = mAddress;
            *((_QWORD *)v18 + 10) = mTaskFunctionSPU;
            *((_QWORD *)v18 + 11) = mTaskFunctionPPU;
            *((_QWORD *)v18 + 12) = Head;
            *((_QWORD *)v18 + 13) = v13;
            *((_QWORD *)v18 + 14) = mNext_high;
            *((_QWORD *)v18 + 15) = 0i64;
            if ( mTaskFunctionOffload )
            {
              *((_DWORD *)v18 + 14) = 130;
              *((_DWORD *)v18 + 12) = 0;
            }
          }
          v24 = p_mTasks->mNode.mPrev;
          v24->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)v18;
          *(_QWORD *)v18 = v24;
          *((_QWORD *)v18 + 1) = p_mTasks;
          p_mTasks->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)v18;
          ++v4->mNumTasks;
          Head = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423A9A90, &Head->mRoot);
        }
        while ( Head );
        v1 = this;
        p_mStaticSceneryToDisable = &this->mStaticSceneryToDisable;
      }
      v25 = mNext->mPrev;
      v26 = mNext->mNext;
      v25->mNext = v26;
      v26->mPrev = v25;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      operator delete[](mNext);
    }
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v4);
    UFG::qTaskManager::Sync(&UFG::gTaskManager, v4);
    while ( (UFG::qList<SceneryToDisable,SceneryToDisable,1,0> *)v1->mSceneryFoundForDisable.mNode.mNext != &v1->mSceneryFoundForDisable )
    {
      v27 = v1->mSceneryFoundForDisable.mNode.mNext;
      v28 = v27->mPrev;
      v29 = v27->mNext;
      v28->mNext = v29;
      v29->mPrev = v28;
      v27->mPrev = v27;
      v27->mNext = v27;
      v30 = (UFG::SceneryGroup *)v27[2].mPrev;
      if ( v30 )
        UFG::SceneryGroup::MakeInvisible(v30, (unsigned int)v27[2].mNext);
      v31 = v27->mPrev;
      v32 = v27->mNext;
      v31->mNext = v32;
      v32->mPrev = v31;
      v27->mPrev = v27;
      v27->mNext = v27;
      operator delete[](v27);
    }
  }
}

// File Line: 2090
// RVA: 0x473810
void __fastcall UFG::PhysicsSystem::ResetFracturables(UFG::PhysicsSystem *this)
{
  UFG::qBaseNodeRB *i; // rdi
  unsigned int j; // ebx
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *p_mNext; // rcx
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *mPrev; // rax
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *v5; // rcx
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *v6; // rax

  for ( i = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_14216D7B0);
        i;
        i = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_14216D7B0, i) )
  {
    for ( j = 0; j < i[2].mUID; ++j )
      UFG::CollisionMeshData::ResetFracture(*((UFG::CollisionMeshData **)&i[3].mChild[1]->mParent + j));
  }
  p_mNext = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
  if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
  {
    do
    {
      mPrev = p_mNext[18].mNode.mPrev;
      v5 = p_mNext[15].mNode.mPrev;
      v6 = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&mPrev[-18].mNext;
      if ( v5 )
      {
        v5->mPrev = 0i64;
        v5->mNext = 0i64;
        v5[1].mPrev = 0i64;
        v5[1].mNext = 0i64;
      }
      p_mNext = v6;
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
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *mPrev; // rcx

  for ( i = UFG::ParkourComponent::s_ParkourComponentList.mNode.mNext - 4;
        i != (UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *)(&UFG::ParkourComponent::s_ParkourComponentList
                                                                       - 4);
        i = i[4].mNext - 4 )
  {
    mPrev = i[11].mPrev;
    LODWORD(i[11].mNext) &= ~0x10u;
    if ( mPrev )
      ((void (__fastcall *)(UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *, __int64))mPrev->mPrev->mPrev)(
        mPrev,
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
  __int64 j; // rbx

  v1 = UFG::BasePhysicsSystem::mInstance;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_14216D960);
        i;
        i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_14216D960, &i->mRoot) )
  {
    for ( j = 0i64; (unsigned int)j < i[1].mRoot.mUID; j = (unsigned int)(j + 1) )
      UFG::BasePhysicsSystem::RemoveCollisionInstanceFromWorld(
        v1,
        *((UFG::CollisionInstanceData **)&i[1].mRoot.mChild[1]->mParent + j));
  }
}

// File Line: 2146
// RVA: 0x472770
void __fastcall UFG::PhysicsSystem::RecreateStreamedCollisionInstances(UFG::PhysicsSystem *this)
{
  UFG::BasePhysicsSystem *v1; // rsi
  UFG::qBaseTreeRB *i; // rbx
  __int64 j; // rdi
  __int64 v4; // rdx
  __int128 v5; // xmm0
  __int128 v6; // xmm1

  v1 = UFG::BasePhysicsSystem::mInstance;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_14216D960);
        i;
        i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_14216D960, &i->mRoot) )
  {
    for ( j = 0i64; (unsigned int)j < i[1].mRoot.mUID; j = (unsigned int)(j + 1) )
    {
      v4 = *((_QWORD *)&i[1].mRoot.mChild[1]->mParent + j);
      v5 = *(_OWORD *)(v4 + 48);
      v6 = *(_OWORD *)(v4 + 16);
      *(_DWORD *)(v4 + 88) &= ~2u;
      *(_OWORD *)(v4 + 32) = v5;
      *(_OWORD *)v4 = v6;
      (*((void (__fastcall **)(UFG::BasePhysicsSystem *))&v1->vfptr->__vecDelDtor + 1))(v1);
    }
  }
}

// File Line: 2170
// RVA: 0x459240
void __fastcall UFG::PhysicsSystem::BroadPhaseBorderHandler(hkpEntity *entity)
{
  hkReferencedObject::addReference(entity);
  UFG::ThreadSafeQueue<hkpEntity>::AddHead(
    (UFG::ThreadSafeQueue<UFG::CollisionEvent> *)&UFG::BasePhysicsSystem::mInstance[1].mCollisionModels.mTree.mRoot.mUID,
    (UFG::CollisionEvent *)entity);
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
  _RTL_CRITICAL_SECTION *p_mutex; // rsi
  UFG::QueueNode<hkpEntity> *p_tail; // r14
  bool v4; // bl
  hkpEntity *data; // rdi
  bool v6; // bl
  UFG::QueueNode<hkpEntity> *prev; // rcx
  UFG::QueueNode<hkpEntity> *v8; // rax
  int m_referenceCount; // ebx
  __int64 v10; // r8
  __int128 m_col1; // xmm1
  hkpShape *m_shape; // rcx
  __int128 m_col2; // xmm0
  __int128 m_translation; // xmm1
  __m128 m_quad; // xmm6
  float v16; // xmm0_4
  unsigned __int64 v17; // r15
  __int64 v18; // rbx
  UFG::SimComponent *v19; // rcx
  __m128 v20; // xmm1
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  __m128 v23; // xmm6
  UFG::SimObjectGame *v24; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject *v27; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float y; // xmm1_4
  float x; // xmm2_4
  float v31; // xmm3_4
  float z; // xmm4_4
  float v33; // xmm0_4
  float w; // xmm1_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  char *CollisionLayerName; // rax
  unsigned __int64 m_userData; // rbx
  __int64 v45; // rbx
  UFG::TransformNodeComponent *i; // rax
  char *v47; // rax
  hkpWorld *m_world; // rbx
  bool v49; // bl
  UFG::qMatrix44 xform; // [rsp+40h] [rbp-C0h] BYREF
  int v51[8]; // [rsp+80h] [rbp-80h] BYREF
  __m128 v52; // [rsp+A0h] [rbp-60h]
  __m128 v53; // [rsp+B0h] [rbp-50h] BYREF
  __int128 v54[4]; // [rsp+C0h] [rbp-40h] BYREF
  hkBool result; // [rsp+180h] [rbp+80h] BYREF

  p_mutex = (_RTL_CRITICAL_SECTION *)&this->mEntitiesLeftBroadphase.mutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mEntitiesLeftBroadphase.mutex);
  p_tail = &this->mEntitiesLeftBroadphase.tail;
  v4 = this->mEntitiesLeftBroadphase.head.next == &this->mEntitiesLeftBroadphase.tail;
  UFG::qMutex::Unlock(p_mutex);
  if ( !v4 )
  {
    do
    {
      data = 0i64;
      UFG::qMutex::Lock(p_mutex);
      UFG::qMutex::Lock(p_mutex);
      v6 = this->mEntitiesLeftBroadphase.head.next == p_tail;
      UFG::qMutex::Unlock(p_mutex);
      if ( !v6 )
      {
        prev = p_tail->prev;
        v8 = p_tail->prev->prev;
        v8->next = p_tail;
        p_tail->prev = v8;
        data = prev->data;
        operator delete[](prev);
      }
      UFG::qMutex::Unlock(p_mutex);
      m_referenceCount = data->m_referenceCount;
      hkReferencedObject::removeReference(data);
      if ( data->m_world && m_referenceCount > 1 )
      {
        m_col1 = (__int128)data->m_motion.m_motionState.m_transform.m_rotation.m_col1;
        m_shape = data->m_collidable.m_shape;
        v54[0] = (__int128)data->m_motion.m_motionState.m_transform.m_rotation.m_col0;
        m_col2 = (__int128)data->m_motion.m_motionState.m_transform.m_rotation.m_col2;
        v54[1] = m_col1;
        m_translation = (__int128)data->m_motion.m_motionState.m_transform.m_translation;
        v54[2] = m_col2;
        v54[3] = m_translation;
        ((void (__fastcall *)(hkpShape *, __int128 *, __int64, int *))m_shape->vfptr[2].__vecDelDtor)(
          m_shape,
          v54,
          v10,
          v51);
        m_quad = data->m_motion.m_motionState.m_transform.m_translation.m_quad;
        v16 = _mm_shuffle_ps(m_quad, m_quad, 170).m128_f32[0];
        if ( v16 <= -10.0 || v16 >= 10.0 )
        {
          if ( !sDisableLeavingWorld )
          {
            UFG::qPrintf(
              "PHYSICS: DeleteEntitiesLeftBroadphase %s (%f %f %f), (%f %f %f)\n",
              (const char *)((unsigned __int64)data->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
              *(float *)v51,
              *(float *)&v51[1],
              *(float *)&v51[2],
              *(float *)&v51[4],
              *(float *)&v51[5],
              *(float *)&v51[6]);
            CollisionLayerName = UFG::GetCollisionLayerName(data->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo & 0x1F);
            UFG::qPrintf("PHYSICS: %x layer %s\n", data, CollisionLayerName);
            m_userData = data->m_userData;
            if ( m_userData )
            {
              v45 = *(_QWORD *)(m_userData + 24);
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
                            i) )
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
              m_world = data->m_world;
              if ( m_world )
              {
                UFG::qPrintf(
                  "PHYSICS: hkpEntity has left the world (possible memory leak) %s\n",
                  (const char *)((unsigned __int64)data->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
                hkpWorld::removeEntity(m_world, &result, data);
              }
            }
          }
        }
        else
        {
          v17 = data->m_userData;
          v18 = 0i64;
          v19 = *(UFG::SimComponent **)(v17 + 24);
          v20 = _mm_mul_ps(m_quad, m_quad);
          v21 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                  _mm_shuffle_ps(v20, v20, 170));
          v22 = _mm_rsqrt_ps(v21);
          v23 = _mm_mul_ps(
                  m_quad,
                  _mm_andnot_ps(
                    _mm_cmple_ps(v21, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                      _mm_mul_ps(*(__m128 *)_xmm, v22))));
          v52 = v23;
          if ( !v19
            || !UFG::SimComponent::IsType(v19, UFG::CharacterPhysicsComponent::_CharacterPhysicsComponentTypeUID)
            || (v18 = *(_QWORD *)(v17 + 24), (v24 = *(UFG::SimObjectGame **)(v18 + 40)) == 0i64)
            || ((m_Flags = v24->m_Flags, (m_Flags & 0x4000) == 0)
              ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
               ? (ComponentOfType = UFG::SimObject::GetComponentOfType(v24, UFG::CharacterOccupantComponent::_TypeUID))
               : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v24,
                                      UFG::CharacterOccupantComponent::_TypeUID)))
              : (ComponentOfType = v24->m_Components.p[44].m_pComponent),
                !ComponentOfType) )
          {
            hkpEntity::activate(data);
            v53 = _mm_mul_ps((__m128)_xmm_c0a00000c0a00000c0a00000c0a00000, v23);
            hkpEntity::activate(data);
            data->m_motion.vfptr[9].__vecDelDtor(&data->m_motion, (unsigned int)&v53);
            if ( v18 )
            {
              v27 = *(UFG::SimObject **)(v18 + 40);
              if ( v27 )
                m_pTransformNodeComponent = v27->m_pTransformNodeComponent;
              else
                m_pTransformNodeComponent = 0i64;
              if ( m_pTransformNodeComponent )
              {
                UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
                y = m_pTransformNodeComponent->mWorldTransform.v0.y;
                x = m_pTransformNodeComponent->mWorldTransform.v3.x;
                v31 = m_pTransformNodeComponent->mWorldTransform.v3.y;
                z = m_pTransformNodeComponent->mWorldTransform.v3.z;
                xform.v0.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
                v33 = m_pTransformNodeComponent->mWorldTransform.v0.z;
                xform.v0.y = y;
                w = m_pTransformNodeComponent->mWorldTransform.v0.w;
                xform.v0.z = v33;
                v35 = m_pTransformNodeComponent->mWorldTransform.v1.x;
                xform.v0.w = w;
                v36 = m_pTransformNodeComponent->mWorldTransform.v1.y;
                xform.v1.x = v35;
                xform.v1.z = m_pTransformNodeComponent->mWorldTransform.v1.z;
                v37 = m_pTransformNodeComponent->mWorldTransform.v2.x;
                xform.v1.y = v36;
                v38 = m_pTransformNodeComponent->mWorldTransform.v1.w;
                xform.v2.x = v37;
                v39 = m_pTransformNodeComponent->mWorldTransform.v2.z;
                xform.v1.w = v38;
                v40 = m_pTransformNodeComponent->mWorldTransform.v2.y;
                xform.v2.z = v39;
                v41 = m_pTransformNodeComponent->mWorldTransform.v3.w;
                xform.v2.y = v40;
                v42 = m_pTransformNodeComponent->mWorldTransform.v2.w;
                xform.v3.w = v41;
                xform.v2.w = v42;
                xform.v3.y = v31 + (float)(v52.m128_f32[1] * -10.0);
                xform.v3.z = z + 5.0;
                xform.v3.x = x + (float)(v52.m128_f32[0] * -10.0);
                UFG::SimObjectUtility::Teleport(v27, &xform);
              }
            }
          }
        }
      }
      UFG::qMutex::Lock(p_mutex);
      v49 = this->mEntitiesLeftBroadphase.head.next == p_tail;
      UFG::qMutex::Unlock(p_mutex);
    }
    while ( !v49 );
  }
}

// File Line: 2308
// RVA: 0x480F20
void __fastcall UFG::PhysicsSystem::UpdateWater(UFG::PhysicsSystem *this, float deltaTime)
{
  UFG::qList<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent,1,0> *p_mNext; // rcx
  UFG::qList<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent,1,0> *v3; // rbx
  UFG::qList<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent,1,0> *v4; // rcx
  UFG::qList<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent,1,0> *v5; // rbx
  UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *v6; // rbx
  UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *v7; // rdi
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *mNext; // rax
  UFG::SimObject *v9; // rsi
  UFG::CharacterEffectsComponent *ComponentOfType; // r14
  UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> *v11; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  float v13; // xmm6_4
  float y; // xmm1_4
  float x; // xmm0_4
  __m128 v16; // xmm1
  UFG::qVector3 offset; // [rsp+20h] [rbp-88h] BYREF
  UFG::qVector3 characterVelocity; // [rsp+30h] [rbp-78h] BYREF
  UFG::qMatrix44 dest; // [rsp+40h] [rbp-68h] BYREF

  this->mWaterWaveAngle = fmodf((float)(deltaTime * this->mWaterWaveFrequency) + this->mWaterWaveAngle, 6.2800002);
  p_mNext = (UFG::qList<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent,1,0> *)&UFG::WaterPhantomComponent::s_WaterPhantomComponentList.mNode.mNext[-7].mNext;
  if ( &UFG::WaterPhantomComponent::s_WaterPhantomComponentList.mNode.mNext[-7].mNext != (UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> **)((char *)&UFG::WaterPhantomComponent::s_WaterPhantomComponentList - 104) )
  {
    do
    {
      v3 = (UFG::qList<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent,1,0> *)&p_mNext[7].mNode.mPrev[-7].mNext;
      if ( ((__int64)p_mNext[2].mNode.mPrev & 3) == 1 )
        ((void (__fastcall *)(UFG::qList<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent,1,0> *))p_mNext->mNode.mPrev[7].mPrev)(p_mNext);
      p_mNext = v3;
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
      if ( ((__int64)v4[2].mNode.mPrev & 3) == 1 )
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
      if ( ((__int64)v6[2].mNode.mPrev & 3) == 1 )
      {
        mNext = v6[11].mNode.mNext;
        if ( mNext )
        {
          if ( SLODWORD(mNext[7].mNext) > 0 )
          {
            v9 = (UFG::SimObject *)v6[2].mNode.mNext;
            ComponentOfType = (UFG::CharacterEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                                                  v9,
                                                                  UFG::CharacterEffectsComponent::_TypeUID);
            if ( ComponentOfType )
            {
              v11 = v6[11].mNode.mNext;
              m_pTransformNodeComponent = v9->m_pTransformNodeComponent;
              if ( v11 )
                v13 = *((float *)&v11[8].mNext + 1);
              else
                v13 = FLOAT_N0_31400001;
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
              y = m_pTransformNodeComponent->mWorldTransform.v3.y;
              x = m_pTransformNodeComponent->mWorldTransform.v3.x;
              offset.z = v13;
              offset.x = x;
              offset.y = y;
              UFG::qTranslationMatrix(&dest, &offset);
              v16 = (__m128)v6[27].mNode.mPrev[2].mPrev[35];
              LODWORD(characterVelocity.x) = v16.m128_i32[0];
              LODWORD(characterVelocity.z) = _mm_shuffle_ps(v16, v16, 170).m128_u32[0];
              LODWORD(characterVelocity.y) = _mm_shuffle_ps(v16, v16, 85).m128_u32[0];
              UFG::CharacterEffectsComponent::HandleWaterCollision(ComponentOfType, &dest, &characterVelocity);
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
float __fastcall UFG::PhysicsSystem::ComputeBuoyancy(
        UFG::PhysicsSystem *this,
        float cubePosZ,
        float cubeSideLength,
        float waterHeight)
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
void __fastcall UFG::PhysicsSystem::DisableCollisionsBetween(
        UFG::PhysicsSystem *this,
        UFG::SimObjectGame *simObjectA,
        UFG::SimObjectGame *simObjectB)
{
  signed __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  hkpEntity *mPrev; // rsi
  UFG::CustomCollisionFilter *mCollisionFilter; // rdi
  signed __int16 v10; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  hkpEntity *v12; // r8
  signed __int16 v13; // cx
  UFG::SimComponent *ComponentOfType; // rax
  signed __int16 v15; // cx
  UFG::SimComponent *v16; // rax
  UFG::RigidBody *v17; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v18; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  hkpEntity *mBody; // r8
  UFG::qReflectHandleBase v22; // [rsp+38h] [rbp-30h] BYREF

  if ( !simObjectA || !simObjectB )
    return;
  m_Flags = simObjectA->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    m_pComponent = simObjectA->m_Components.p[27].m_pComponent;
  else
    m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(simObjectA, UFG::CharacterPhysicsComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(simObjectA, UFG::CharacterPhysicsComponent::_TypeUID);
  if ( !m_pComponent )
    return;
  mPrev = (hkpEntity *)m_pComponent[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev;
  if ( !mPrev )
    return;
  mCollisionFilter = this->mCollisionFilter;
  v10 = simObjectB->m_Flags;
  if ( (v10 & 0x4000) != 0 )
  {
    ComponentOfTypeHK = simObjectB->m_Components.p[27].m_pComponent;
  }
  else if ( v10 < 0 || (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(simObjectB, UFG::CharacterPhysicsComponent::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(simObjectB, UFG::CharacterPhysicsComponent::_TypeUID);
  }
  if ( ComponentOfTypeHK )
  {
    v12 = (hkpEntity *)ComponentOfTypeHK[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev;
    if ( v12 )
    {
      UFG::CustomCollisionFilter::DisableCollisionsBetween(mCollisionFilter, mPrev, v12);
      return;
    }
  }
  v13 = simObjectB->m_Flags;
  if ( (v13 & 0x4000) == 0 )
  {
    if ( v13 < 0 )
    {
      ComponentOfType = simObjectB->m_Components.p[34].m_pComponent;
      goto LABEL_31;
    }
    if ( (v13 & 0x2000) == 0 )
    {
      if ( (v13 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(simObjectB, UFG::PhysicsMoverInterface::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(simObjectB, UFG::PhysicsMoverInterface::_TypeUID);
LABEL_31:
      if ( ComponentOfType )
        return;
    }
  }
  v15 = simObjectB->m_Flags;
  if ( (v15 & 0x4000) != 0 || v15 < 0 || (v15 & 0x2000) != 0 || (v15 & 0x1000) != 0 )
    v16 = UFG::SimObjectGame::GetComponentOfTypeHK(simObjectB, UFG::RigidBodyComponent::_TypeUID);
  else
    v16 = UFG::SimObject::GetComponentOfType(simObjectB, UFG::RigidBodyComponent::_TypeUID);
  v17 = (UFG::RigidBody *)v16;
  if ( v16 )
  {
    do
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v22);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v18);
      v22.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      mCollisionMeshData = v17->mCollisionMeshData;
      if ( mCollisionMeshData )
        UFG::qReflectHandleBase::operator=(&v22, &mCollisionMeshData->mObjectProperties);
      if ( v22.mData )
      {
        if ( BYTE2(v22.mData[2].vfptr) )
        {
          mBody = v17->mBody;
          if ( mBody )
            UFG::CustomCollisionFilter::DisableCollisionsBetween(mCollisionFilter, mPrev, mBody);
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
                                v17);
      UFG::qReflectHandleBase::~qReflectHandleBase(&v22);
    }
    while ( v17 );
  }
}

// File Line: 2465
// RVA: 0x4723A0
void __fastcall UFG::PhysicsSystem::ReEnableCollisionsBetween(
        UFG::PhysicsSystem *this,
        UFG::SimObjectGame *simObjectA,
        UFG::SimObjectGame *simObjectB)
{
  signed __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  hkpEntity *mPrev; // rsi
  UFG::CustomCollisionFilter *mCollisionFilter; // rbp
  signed __int16 v10; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  hkpEntity *v12; // r8
  signed __int16 v13; // cx
  UFG::SimComponent *ComponentOfType; // rax
  signed __int16 v15; // cx
  UFG::SimComponent *v16; // rax
  UFG::RigidBodyComponent *v17; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v18; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  hkpEntity *mBody; // r8
  UFG::qReflectHandleBase v22; // [rsp+28h] [rbp-30h] BYREF

  if ( !simObjectA )
    return;
  m_Flags = simObjectA->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    m_pComponent = simObjectA->m_Components.p[27].m_pComponent;
  else
    m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(simObjectA, UFG::CharacterPhysicsComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(simObjectA, UFG::CharacterPhysicsComponent::_TypeUID);
  if ( !m_pComponent )
    return;
  mPrev = (hkpEntity *)m_pComponent[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev;
  if ( !mPrev )
    return;
  mCollisionFilter = this->mCollisionFilter;
  if ( !simObjectB )
    return;
  v10 = simObjectB->m_Flags;
  if ( (v10 & 0x4000) != 0 )
  {
    ComponentOfTypeHK = simObjectB->m_Components.p[27].m_pComponent;
  }
  else if ( v10 < 0 || (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(simObjectB, UFG::CharacterPhysicsComponent::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(simObjectB, UFG::CharacterPhysicsComponent::_TypeUID);
  }
  if ( ComponentOfTypeHK )
  {
    v12 = (hkpEntity *)ComponentOfTypeHK[6].m_BoundComponentHandles.mNode.mPrev[2].mPrev;
    if ( v12 )
    {
      UFG::CustomCollisionFilter::ReenableCollisionsBetween(this->mCollisionFilter, mPrev, v12);
      return;
    }
  }
  v13 = simObjectB->m_Flags;
  if ( (v13 & 0x4000) == 0 )
  {
    if ( v13 < 0 )
    {
      ComponentOfType = simObjectB->m_Components.p[34].m_pComponent;
      goto LABEL_31;
    }
    if ( (v13 & 0x2000) == 0 )
    {
      if ( (v13 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(simObjectB, UFG::PhysicsMoverInterface::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(simObjectB, UFG::PhysicsMoverInterface::_TypeUID);
LABEL_31:
      if ( ComponentOfType )
        return;
    }
  }
  v15 = simObjectB->m_Flags;
  if ( (v15 & 0x4000) != 0 || v15 < 0 || (v15 & 0x2000) != 0 || (v15 & 0x1000) != 0 )
    v16 = UFG::SimObjectGame::GetComponentOfTypeHK(simObjectB, UFG::RigidBodyComponent::_TypeUID);
  else
    v16 = UFG::SimObject::GetComponentOfType(simObjectB, UFG::RigidBodyComponent::_TypeUID);
  v17 = (UFG::RigidBodyComponent *)v16;
  if ( v16 )
  {
    do
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v22);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v18);
      v22.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      mCollisionMeshData = v17->mCollisionMeshData;
      if ( mCollisionMeshData )
        UFG::qReflectHandleBase::operator=(&v22, &mCollisionMeshData->mObjectProperties);
      if ( BYTE2(v22.mData[2].vfptr) )
      {
        mBody = v17->mBody;
        if ( mBody )
          UFG::CustomCollisionFilter::ReenableCollisionsBetween(mCollisionFilter, mPrev, mBody);
      }
      else
      {
        UFG::RigidBodyComponent::RestoreCollisionFilter(v17);
      }
      v17 = (UFG::RigidBodyComponent *)UFG::SimObject::GetComponentOfType(
                                         v17->m_pSimObject,
                                         UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                         0,
                                         v17);
      UFG::qReflectHandleBase::~qReflectHandleBase(&v22);
    }
    while ( v17 );
  }
}

// File Line: 2514
// RVA: 0x46F720
void __fastcall UFG::PhysicsSystem::PhysicsVolumeHandler(
        UFG::PhysicsSystem *this,
        UFG::PhantomCallback *pcb,
        UFG::SimObject *simObject,
        UFG::PhantomCallbackData *data)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  bool *v8; // rax
  UFG::PhantomVolumeComponent *ComponentOfType; // rax
  UFG::PhantomCallbackShape *mPhantomCallbackShape; // rdx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::PhantomVolumeComponent *v13; // rax
  UFG::PhantomVolumeComponent *v14; // rsi
  signed __int16 m_Flags; // cx
  unsigned int v16; // ebx
  UFG::SimObjectModifier v17; // [rsp+38h] [rbp-30h] BYREF

  if ( !data->mPhantomCallbackShape->mVolumeProperties->mReserved )
    goto LABEL_7;
  m_pSceneObj = simObject->m_pSceneObj;
  if ( m_pSceneObj )
  {
    mpWritableProperties = m_pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = m_pSceneObj->mpConstProperties;
    v8 = PropertyUtils::Get<bool>(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&qSymbol_ImportantVFXCharacter,
           DEPTH_RECURSE);
    if ( v8 )
    {
      if ( *v8 )
      {
LABEL_7:
        ComponentOfType = (UFG::PhantomVolumeComponent *)UFG::SimObject::GetComponentOfType(
                                                           simObject,
                                                           UFG::PhantomVolumeComponent::_TypeUID);
        if ( ComponentOfType )
        {
          mPhantomCallbackShape = data->mPhantomCallbackShape;
          if ( data->mEvent )
            UFG::PhantomVolumeComponent::OnLeaveVolume(ComponentOfType, mPhantomCallbackShape);
          else
            UFG::PhantomVolumeComponent::OnEnterVolume(ComponentOfType, mPhantomCallbackShape);
        }
        else if ( data->mEvent == ENTER_EVENT )
        {
          SimulationMemoryPool = UFG::GetSimulationMemoryPool();
          v12 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xA8ui64, "SimComponent", 0i64, 1u);
          if ( v12 )
          {
            UFG::PhantomVolumeComponent::PhantomVolumeComponent(
              (UFG::PhantomVolumeComponent *)v12,
              simObject->mNode.mUID);
            v14 = v13;
          }
          else
          {
            v14 = 0i64;
          }
          UFG::PhantomVolumeComponent::OnEnterVolume(v14, data->mPhantomCallbackShape);
          m_Flags = simObject->m_Flags;
          if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
          {
            v16 = 18;
          }
          else if ( (m_Flags & 0x2000) != 0 )
          {
            v16 = 5;
          }
          else
          {
            v16 = -1;
          }
          UFG::SimObjectModifier::SimObjectModifier(&v17, simObject, 1);
          UFG::SimObjectModifier::AttachComponent(&v17, v14, v16);
          UFG::SimObjectModifier::Close(&v17);
          UFG::SimObjectModifier::~SimObjectModifier(&v17);
        }
      }
    }
  }
}


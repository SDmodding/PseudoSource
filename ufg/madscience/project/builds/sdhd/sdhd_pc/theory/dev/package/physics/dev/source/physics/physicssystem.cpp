// File Line: 127
// RVA: 0x14590C0
__int64 dynamic_initializer_for__gPhysicsMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gPhysicsMemoryPool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gPhysicsMemoryPool__);
}

// File Line: 128
// RVA: 0x14590E0
__int64 dynamic_initializer_for__gPoseMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gPoseMemoryPool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gPoseMemoryPool__);
}

// File Line: 129
// RVA: 0x1458E60
__int64 dynamic_initializer_for__gAIMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gAIMemoryPool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gAIMemoryPool__);
}

// File Line: 139
// RVA: 0x1458500
void dynamic_initializer_for__UFG::BasePhysicsSystem::mParam__()
{
  UFG::BasePhysicsSystem::mParam.broadPhaseMin = (hkVector4f)_xmm;
  UFG::BasePhysicsSystem::mParam.broadPhaseMax = (hkVector4f)_xmm;
}

// File Line: 172
// RVA: 0x96AD0
void __fastcall UFG::BasePhysicsSystem::BasePhysicsSystem(UFG::BasePhysicsSystem *this, UFG::qMemoryPool *memPool)
{
  __int64 v4; // rbx
  char v5; // dl
  char v6; // cl
  int v7; // r9d
  __int64 m_size; // rax
  hkpWorldRayCastCommand *v9; // r9
  int v10; // edx
  __int64 v11; // r8
  unsigned int *p_m_filterInfo; // rcx
  _QWORD **Value; // rax
  __int64 v14; // rax
  char v15; // al
  char v16; // dl
  char v17; // cl
  int v18; // r9d
  int v19; // ecx
  hkpWorldLinearCastCommand *v20; // r8
  int v21; // eax
  __int64 v22; // r9
  _QWORD **v23; // rax
  __int64 v24; // rax
  char v25; // al
  void *result; // [rsp+88h] [rbp+10h] BYREF
  void *v27; // [rsp+90h] [rbp+18h]
  hkpWorldLinearCastCommand *v28; // [rsp+98h] [rbp+20h]

  this->vfptr = (UFG::BasePhysicsSystemVtbl *)&UFG::BasePhysicsSystem::`vftable;
  result = &this->mCollisionModels;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mCollisionModels.mTree);
  UFG::ActiveRegionManager::ActiveRegionManager(&this->mActiveRegionManager);
  this->mEntitiesToAdd.m_data = 0i64;
  this->mEntitiesToAdd.m_size = 0;
  this->mEntitiesToAdd.m_capacityAndFlags = 0x80000000;
  this->mEntitiesToRemove.m_data = 0i64;
  this->mEntitiesToRemove.m_size = 0;
  this->mEntitiesToRemove.m_capacityAndFlags = 0x80000000;
  this->mPhantomsToAdd.m_data = 0i64;
  this->mPhantomsToAdd.m_size = 0;
  this->mPhantomsToAdd.m_capacityAndFlags = 0x80000000;
  this->mPhantomsToRemove.m_data = 0i64;
  this->mPhantomsToRemove.m_size = 0;
  this->mPhantomsToRemove.m_capacityAndFlags = 0x80000000;
  this->mActionsToAdd.m_data = 0i64;
  this->mActionsToAdd.m_size = 0;
  this->mActionsToAdd.m_capacityAndFlags = 0x80000000;
  this->mConstraintsToAdd.m_data = 0i64;
  this->mConstraintsToAdd.m_size = 0;
  this->mConstraintsToAdd.m_capacityAndFlags = 0x80000000;
  this->mWorld = 0i64;
  this->mBroadPhaseBorder = 0i64;
  this->mThreadPool = 0i64;
  this->mJobQueue = 0i64;
  this->mRayCastCommands.m_data = 0i64;
  this->mRayCastCommands.m_size = 0;
  this->mRayCastCommands.m_capacityAndFlags = 0x80000000;
  this->mRayCastSemaphore = 0i64;
  `eh vector constructor iterator(
    this->mRaycastBatches,
    0xAE50ui64,
    2,
    (void (__fastcall *)(void *))UFG::BasePhysicsSystem::RaycastBatch::RaycastBatch);
  this->mShapeCastCommands.m_data = 0i64;
  this->mShapeCastCommands.m_size = 0;
  this->mShapeCastCommands.m_capacityAndFlags = 0x80000000;
  this->mShapeCastSemaphore = 0i64;
  result = &this->mShapecastBatch;
  `eh vector constructor iterator(
    &this->mShapecastBatch,
    0xD0ui64,
    48,
    (void (__fastcall *)(void *))UFG::AsyncShapeCasterCollector::AsyncShapeCasterCollector);
  this->mCollisionFilter = 0i64;
  this->mFrameNumber = 0;
  *(_WORD *)&this->mBuildingAiData = 0;
  this->mRaycastCallbackActive = 0;
  UFG::BasePhysicsSystem::mMemoryPool = memPool;
  UFG::BasePhysicsSystem::InitWorld(this);
  v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v5 = ++*(_BYTE *)(v4 + 80);
  *(_DWORD *)(v4 + 4i64 * v5) = 3;
  *(_QWORD *)(v4 + 8i64 * v5 + 16) = "AsyncRayCast";
  *(_QWORD *)(v4 + 8i64 * v5 + 48) = 0i64;
  v6 = *(_BYTE *)(v4 + 81);
  if ( v5 > v6 )
    v6 = v5;
  *(_BYTE *)(v4 + 81) = v6;
  if ( (this->mRayCastCommands.m_capacityAndFlags & 0x3FFFFFFFu) < 0xA4 )
    hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, &this->mRayCastCommands, 164, 80);
  if ( (this->mRayCastCommands.m_capacityAndFlags & 0x3FFFFFFFu) < 0xA4 )
  {
    v7 = 164;
    if ( 2 * (this->mRayCastCommands.m_capacityAndFlags & 0x3FFFFFFF) > 164 )
      v7 = 2 * (this->mRayCastCommands.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, &this->mRayCastCommands, v7, 80);
  }
  m_size = this->mRayCastCommands.m_size;
  v9 = &this->mRayCastCommands.m_data[m_size];
  v27 = v9;
  v10 = 0;
  LODWORD(result) = 0;
  v11 = 164 - (int)m_size;
  if ( 164 - (int)m_size > 0 )
  {
    p_m_filterInfo = &v9->m_rayInput.m_filterInfo;
    do
    {
      v28 = (hkpWorldLinearCastCommand *)(p_m_filterInfo - 9);
      if ( p_m_filterInfo != (unsigned int *)36 )
      {
        *((_BYTE *)p_m_filterInfo - 4) = 0;
        *p_m_filterInfo = 0;
        *(_QWORD *)(p_m_filterInfo + 1) = 0i64;
        *((_WORD *)p_m_filterInfo + 14) = 0;
      }
      LODWORD(result) = ++v10;
      p_m_filterInfo += 20;
      --v11;
    }
    while ( v11 );
  }
  this->mRayCastCommands.m_size = 164;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 16i64);
  if ( v14 )
  {
    *(_QWORD *)v14 = 0i64;
    *(_QWORD *)(v14 + 8) = 0i64;
  }
  else
  {
    v14 = 0i64;
  }
  this->mRayCastJobHeader = (hkpCollisionQueryJobHeader *)v14;
  v15 = *(_BYTE *)(v4 + 80);
  if ( v15 > 0 )
  {
    *(_BYTE *)(v4 + 80) = v15 - 1;
  }
  else
  {
    *(_BYTE *)(v4 + 80) = 0;
    *(_DWORD *)v4 = 3;
    *(_QWORD *)(v4 + 16) = 0i64;
    *(_QWORD *)(v4 + 48) = 0i64;
  }
  this->mRaycastBatchSubmitBuffer = this->mRaycastBatches;
  this->mRaycastBatchExecuteBuffer = &this->mRaycastBatches[1];
  this->mRaycastBatches[0].mCount = 0;
  this->mRaycastBatchExecuteBuffer->mCount = 0;
  v16 = ++*(_BYTE *)(v4 + 80);
  *(_DWORD *)(v4 + 4i64 * v16) = 3;
  *(_QWORD *)(v4 + 8i64 * v16 + 16) = "AsyncShapeCast";
  *(_QWORD *)(v4 + 8i64 * v16 + 48) = 0i64;
  v17 = *(_BYTE *)(v4 + 81);
  if ( v16 > v17 )
    v17 = v16;
  *(_BYTE *)(v4 + 81) = v17;
  if ( (this->mShapeCastCommands.m_capacityAndFlags & 0x3FFFFFFFu) < 0x30 )
    hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, &this->mShapeCastCommands, 48, 64);
  if ( (this->mShapeCastCommands.m_capacityAndFlags & 0x3FFFFFFFu) < 0x30 )
  {
    v18 = 48;
    if ( 2 * (this->mShapeCastCommands.m_capacityAndFlags & 0x3FFFFFFF) > 48 )
      v18 = 2 * (this->mShapeCastCommands.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, &this->mShapeCastCommands, v18, 64);
  }
  v19 = 48 - this->mShapeCastCommands.m_size;
  v20 = &this->mShapeCastCommands.m_data[(__int64)this->mShapeCastCommands.m_size];
  v27 = v20;
  v21 = 0;
  LODWORD(result) = 0;
  v22 = v19;
  if ( v19 > 0 )
  {
    do
    {
      v28 = v20;
      if ( v20 )
      {
        v20->m_input.m_maxExtraPenetration = 0.00000011920929;
        v20->m_input.m_startPointTolerance = 0.00000011920929;
      }
      LODWORD(result) = ++v21;
      ++v20;
      --v22;
    }
    while ( v22 );
  }
  this->mShapeCastCommands.m_size = 48;
  v23 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v24 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v23[11] + 8i64))(v23[11], 16i64);
  if ( v24 )
  {
    *(_QWORD *)v24 = 0i64;
    *(_QWORD *)(v24 + 8) = 0i64;
  }
  else
  {
    v24 = 0i64;
  }
  this->mShapeCastJobHeader = (hkpCollisionQueryJobHeader *)v24;
  this->mShapecastBatch.mCount = 0;
  v25 = *(_BYTE *)(v4 + 80);
  if ( v25 > 0 )
  {
    *(_BYTE *)(v4 + 80) = v25 - 1;
  }
  else
  {
    *(_BYTE *)(v4 + 80) = 0;
    *(_DWORD *)v4 = 3;
    *(_QWORD *)(v4 + 16) = 0i64;
    *(_QWORD *)(v4 + 48) = 0i64;
  }
  UFG::PhysicsVolumePropertyManager::Initialize();
  UFG::CollisionEvent::Initialize();
}

// File Line: 203
// RVA: 0x9B560
void __fastcall UFG::BasePhysicsSystem::~BasePhysicsSystem(UFG::BasePhysicsSystem *this)
{
  UFG::ThreadSafeQueue<UFG::CollisionEvent> *v2; // rbx
  Render::SkinningCacheNode *Head; // rbx
  int m_capacityAndFlags; // r8d
  int v5; // r8d
  int v6; // r8d
  int v7; // r8d
  hkSemaphore *mRayCastSemaphore; // rbx
  _QWORD **Value; // rax
  hkpCollisionQueryJobHeader *mRayCastJobHeader; // rbx
  _QWORD **v11; // rax
  int v12; // eax
  hkSemaphore *mShapeCastSemaphore; // rbx
  _QWORD **v14; // rax
  hkpCollisionQueryJobHeader *mShapeCastJobHeader; // rbx
  _QWORD **v16; // rax
  int v17; // r8d
  int v18; // r8d
  int v19; // eax
  int v20; // r8d
  int v21; // r8d
  int v22; // r8d
  int v23; // r8d
  int v24; // r8d
  int v25; // r8d

  this->vfptr = (UFG::BasePhysicsSystemVtbl *)&UFG::BasePhysicsSystem::`vftable;
  if ( UFG::Destruction::mInstance )
  {
    UFG::Destruction::mInstance->hkpBreakOffPartsListener::vfptr->__vecDelDtor(UFG::Destruction::mInstance, 1i64);
    UFG::Destruction::mInstance = 0i64;
  }
  hkpWorld::removeContactListener(this->mWorld, UFG::WorldCollisionListener::mInstance);
  if ( UFG::WorldCollisionListener::mInstance )
    ((void (__fastcall *)(UFG::WorldCollisionListener *, __int64))UFG::WorldCollisionListener::mInstance->vfptr->~hkpContactListener)(
      UFG::WorldCollisionListener::mInstance,
      1i64);
  UFG::WorldCollisionListener::mInstance = 0i64;
  v2 = UFG::CollisionEvent::mQueue;
  if ( UFG::CollisionEvent::mQueue )
  {
    UFG::ThreadSafeQueue<UFG::CollisionEvent>::~ThreadSafeQueue<UFG::CollisionEvent>(UFG::CollisionEvent::mQueue);
    operator delete[](v2);
  }
  UFG::CollisionEvent::mQueue = 0i64;
  UFG::PhysicsPropertyManager::Shutdown();
  while ( UFG::PhysicsVolumePropertyManager::mGuidTranslation.mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::PhysicsVolumePropertyManager::mGuidTranslation);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::PhysicsVolumePropertyManager::mGuidTranslation,
      &Head->mNode);
    operator delete[](Head);
  }
  UFG::BasePhysicsSystem::CloseWorld(this);
  this->mEntitiesToAdd.m_size = 0;
  m_capacityAndFlags = this->mEntitiesToAdd.m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mEntitiesToAdd.m_data,
      8 * m_capacityAndFlags);
  this->mEntitiesToAdd.m_data = 0i64;
  this->mEntitiesToAdd.m_capacityAndFlags = 0x80000000;
  this->mPhantomsToAdd.m_size = 0;
  v5 = this->mPhantomsToAdd.m_capacityAndFlags;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mPhantomsToAdd.m_data,
      8 * v5);
  this->mPhantomsToAdd.m_data = 0i64;
  this->mPhantomsToAdd.m_capacityAndFlags = 0x80000000;
  this->mActionsToAdd.m_size = 0;
  v6 = this->mActionsToAdd.m_capacityAndFlags;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mActionsToAdd.m_data,
      8 * v6);
  this->mActionsToAdd.m_data = 0i64;
  this->mActionsToAdd.m_capacityAndFlags = 0x80000000;
  this->mConstraintsToAdd.m_size = 0;
  v7 = this->mConstraintsToAdd.m_capacityAndFlags;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mConstraintsToAdd.m_data,
      8 * v7);
  this->mConstraintsToAdd.m_data = 0i64;
  this->mConstraintsToAdd.m_capacityAndFlags = 0x80000000;
  mRayCastSemaphore = this->mRayCastSemaphore;
  if ( mRayCastSemaphore )
  {
    hkSemaphore::~hkSemaphore(this->mRayCastSemaphore);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkSemaphore *, __int64))(*Value[11] + 16i64))(Value[11], mRayCastSemaphore, 8i64);
  }
  mRayCastJobHeader = this->mRayCastJobHeader;
  if ( mRayCastJobHeader )
  {
    v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpCollisionQueryJobHeader *, __int64))(*v11[11] + 16i64))(
      v11[11],
      mRayCastJobHeader,
      16i64);
  }
  this->mRayCastCommands.m_size = 0;
  v12 = this->mRayCastCommands.m_capacityAndFlags;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mRayCastCommands.m_data,
      80 * (v12 & 0x3FFFFFFF));
  this->mRayCastCommands.m_data = 0i64;
  this->mRayCastCommands.m_capacityAndFlags = 0x80000000;
  mShapeCastSemaphore = this->mShapeCastSemaphore;
  if ( mShapeCastSemaphore )
  {
    hkSemaphore::~hkSemaphore(this->mShapeCastSemaphore);
    v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkSemaphore *, __int64))(*v14[11] + 16i64))(v14[11], mShapeCastSemaphore, 8i64);
  }
  mShapeCastJobHeader = this->mShapeCastJobHeader;
  if ( mShapeCastJobHeader )
  {
    v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpCollisionQueryJobHeader *, __int64))(*v16[11] + 16i64))(
      v16[11],
      mShapeCastJobHeader,
      16i64);
  }
  this->mShapeCastCommands.m_size = 0;
  v17 = this->mShapeCastCommands.m_capacityAndFlags;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mShapeCastCommands.m_data,
      v17 << 6);
  this->mShapeCastCommands.m_data = 0i64;
  this->mShapeCastCommands.m_capacityAndFlags = 0x80000000;
  `eh vector destructor iterator(
    &this->mShapecastBatch,
    0xD0ui64,
    48,
    (void (__fastcall *)(void *))UFG::AsyncShapeCasterCollector::~AsyncShapeCasterCollector);
  this->mShapeCastCommands.m_size = 0;
  v18 = this->mShapeCastCommands.m_capacityAndFlags;
  if ( v18 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mShapeCastCommands.m_data,
      v18 << 6);
  this->mShapeCastCommands.m_data = 0i64;
  this->mShapeCastCommands.m_capacityAndFlags = 0x80000000;
  `eh vector destructor iterator(
    this->mRaycastBatches,
    0xAE50ui64,
    2,
    (void (__fastcall *)(void *))UFG::BasePhysicsSystem::RaycastBatch::~RaycastBatch);
  this->mRayCastCommands.m_size = 0;
  v19 = this->mRayCastCommands.m_capacityAndFlags;
  if ( v19 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mRayCastCommands.m_data,
      80 * (v19 & 0x3FFFFFFF));
  this->mRayCastCommands.m_data = 0i64;
  this->mRayCastCommands.m_capacityAndFlags = 0x80000000;
  this->mConstraintsToAdd.m_size = 0;
  v20 = this->mConstraintsToAdd.m_capacityAndFlags;
  if ( v20 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mConstraintsToAdd.m_data,
      8 * v20);
  this->mConstraintsToAdd.m_data = 0i64;
  this->mConstraintsToAdd.m_capacityAndFlags = 0x80000000;
  this->mActionsToAdd.m_size = 0;
  v21 = this->mActionsToAdd.m_capacityAndFlags;
  if ( v21 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mActionsToAdd.m_data,
      8 * v21);
  this->mActionsToAdd.m_data = 0i64;
  this->mActionsToAdd.m_capacityAndFlags = 0x80000000;
  this->mPhantomsToRemove.m_size = 0;
  v22 = this->mPhantomsToRemove.m_capacityAndFlags;
  if ( v22 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mPhantomsToRemove.m_data,
      8 * v22);
  this->mPhantomsToRemove.m_data = 0i64;
  this->mPhantomsToRemove.m_capacityAndFlags = 0x80000000;
  this->mPhantomsToAdd.m_size = 0;
  v23 = this->mPhantomsToAdd.m_capacityAndFlags;
  if ( v23 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mPhantomsToAdd.m_data,
      8 * v23);
  this->mPhantomsToAdd.m_data = 0i64;
  this->mPhantomsToAdd.m_capacityAndFlags = 0x80000000;
  this->mEntitiesToRemove.m_size = 0;
  v24 = this->mEntitiesToRemove.m_capacityAndFlags;
  if ( v24 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mEntitiesToRemove.m_data,
      8 * v24);
  this->mEntitiesToRemove.m_data = 0i64;
  this->mEntitiesToRemove.m_capacityAndFlags = 0x80000000;
  this->mEntitiesToAdd.m_size = 0;
  v25 = this->mEntitiesToAdd.m_capacityAndFlags;
  if ( v25 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mEntitiesToAdd.m_data,
      8 * v25);
  this->mEntitiesToAdd.m_data = 0i64;
  this->mEntitiesToAdd.m_capacityAndFlags = 0x80000000;
  UFG::ActiveRegionManager::~ActiveRegionManager(&this->mActiveRegionManager);
  UFG::qTreeRB<UFG::CollisionMeshData,UFG::CollisionMeshData,1>::DeleteAll(&this->mCollisionModels);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->mCollisionModels);
}

// File Line: 233
// RVA: 0xAC140
void UFG::BasePhysicsSystem::InitMemory(void)
{
  hkMemorySystem *v0; // rax
  hkMemorySystem *v1; // rbx
  hkMemorySystem::FrameInfo v2; // [rsp+40h] [rbp+8h] BYREF
  CustomHavokMemorySystem *result; // [rsp+48h] [rbp+10h] BYREF

  if ( (_S7_1 & 1) == 0 )
  {
    _S7_1 |= 1u;
    customAllocator.vfptr = (hkMemoryAllocatorVtbl *)&CustomHavokMemoryAllocator::`vftable;
    atexit(UFG::BasePhysicsSystem::InitMemory_::_2_::_dynamic_atexit_destructor_for__customAllocator__);
  }
  CustomHavokMemoryAllocator::initDefaultPools(&customAllocator, UFG::BasePhysicsSystem::mParam.maxLoadedBodies);
  result = &buffer;
  CustomHavokMemorySystem::CustomHavokMemorySystem(&buffer);
  v1 = v0;
  v0[2].vfptr = (hkMemorySystemVtbl *)&customAllocator;
  hkMemorySystem::replaceInstance(v0);
  hkMemorySystem::FrameInfo::FrameInfo(&v2, UFG::BasePhysicsSystem::mParam.solverBufferSize);
  UFG::BasePhysicsSystem::mMemoryRouter = (hkMemoryRouter *)(*(__int64 (__fastcall **)(hkMemorySystem *, hkMemorySystem::FrameInfo *, __int64))v1->vfptr->gap8)(
                                                              v1,
                                                              &v2,
                                                              3i64);
  hkBaseSystem::init(
    (hkResult *)&result,
    UFG::BasePhysicsSystem::mMemoryRouter,
    (void (__fastcall *)(const char *, void *))_,
    0i64);
}

// File Line: 253
// RVA: 0xAC220
void __fastcall UFG::BasePhysicsSystem::InitWorld(UFG::BasePhysicsSystem *this)
{
  char v2; // al
  __int64 v3; // rbx
  char v4; // dl
  char v5; // cl
  _QWORD **Value; // rax
  hkpWorld *v7; // rax
  hkpWorld *v8; // rax
  char v9; // al
  char v10; // dl
  char v11; // cl
  _QWORD **v12; // rax
  hkpBroadPhaseBorder *v13; // rax
  UFG::BroadPhaseHandler *v14; // rsi
  char v15; // al
  char v16; // dl
  char v17; // cl
  _QWORD **v18; // rax
  UFG::CustomCollisionFilter *v19; // rax
  UFG::CustomCollisionFilter *v20; // rax
  char v21; // al
  __int64 v22; // r14
  char v23; // dl
  char v24; // cl
  _QWORD **v25; // rax
  hkCpuJobThreadPool *v26; // rax
  hkJobThreadPool *v27; // rax
  char v28; // al
  hkThread *p_m_memSizeAndFlags; // rsi
  void *Handle; // rax
  char v31; // dl
  char v32; // cl
  _QWORD **v33; // rax
  hkJobQueue *v34; // rax
  hkJobQueue *v35; // rax
  _QWORD **v36; // rax
  HavokJobMemoryPoolTagger *v37; // rax
  char v38; // al
  hkMonitorStream *v39; // rax
  char v40; // dl
  char v41; // cl
  _QWORD **v42; // rax
  hkSemaphore *v43; // rax
  hkSemaphore *v44; // rax
  _QWORD **v45; // rax
  hkSemaphore *v46; // rax
  hkSemaphore *v47; // rax
  char v48; // al
  hkCpuJobThreadPoolCinfo ci; // [rsp+30h] [rbp-A8h] BYREF
  hkJobQueueCinfo v50; // [rsp+60h] [rbp-78h] BYREF
  hkpWorldCinfo v51; // [rsp+90h] [rbp-48h] BYREF
  void *v52; // [rsp+198h] [rbp+C0h]

  *(_QWORD *)&v50.m_jobQueueHwSetup.m_cellRules = -2i64;
  hkpWorldCinfo::hkpWorldCinfo(&v51);
  *(float *)&v51.m_broadPhaseType.m_storage = FLOAT_0_1;
  v51.m_broadPhaseWorldAabb.m_max.m_quad.m128_f32[2] = FLOAT_0_016666668;
  *(__m128 *)&v50.m_jobQueueHwSetup.m_threadIdsSharingCaches.m_size = _mm_unpacklo_ps(
                                                                        _mm_unpacklo_ps(
                                                                          (__m128)0i64,
                                                                          (__m128)LODWORD(UFG::BasePhysicsSystem::mParam.gravity)),
                                                                        (__m128)0i64);
  v2 = BYTE1(v51.m_maxSectorsPerMidphaseCollideTask);
  if ( UFG::BasePhysicsSystem::mParam.numThreads > 1 )
    v2 = 3;
  BYTE1(v51.m_maxSectorsPerMidphaseCollideTask) = v2;
  *(hkVector4f *)&v51.m_memSizeAndFlags = UFG::BasePhysicsSystem::mParam.broadPhaseMin;
  *(hkVector4f *)((char *)&v51.m_gravity + 8) = UFG::BasePhysicsSystem::mParam.broadPhaseMax;
  LOBYTE(v51.vfptr) = 1;
  hkpWorldCinfo::setupSolverInfo((hkpWorldCinfo *)&v50.m_jobQueueHwSetup.m_spuSchedulePolicy, SOLVER_TYPE_4ITERS_MEDIUM);
  v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v4 = ++*(_BYTE *)(v3 + 80);
  *(_DWORD *)(v3 + 4i64 * v4) = 3;
  *(_QWORD *)(v3 + 8i64 * v4 + 16) = "hkpWorld";
  *(_QWORD *)(v3 + 8i64 * v4 + 48) = 0i64;
  v5 = *(_BYTE *)(v3 + 81);
  if ( v4 > v5 )
    v5 = v4;
  *(_BYTE *)(v3 + 81) = v5;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkpWorld *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 1088i64);
  v52 = v7;
  if ( v7 )
    hkpWorld::hkpWorld(v7, (hkpWorldCinfo *)&v50.m_jobQueueHwSetup.m_spuSchedulePolicy, 0x1332998u);
  else
    v8 = 0i64;
  this->mWorld = v8;
  v9 = *(_BYTE *)(v3 + 80);
  if ( v9 > 0 )
  {
    *(_BYTE *)(v3 + 80) = v9 - 1;
  }
  else
  {
    *(_BYTE *)(v3 + 80) = 0;
    *(_DWORD *)v3 = 3;
    *(_QWORD *)(v3 + 16) = 0i64;
    *(_QWORD *)(v3 + 48) = 0i64;
  }
  hkpWorld::lock(this->mWorld);
  v10 = ++*(_BYTE *)(v3 + 80);
  *(_DWORD *)(v3 + 4i64 * v10) = 3;
  *(_QWORD *)(v3 + 8i64 * v10 + 16) = "BroadPhaseHandler";
  *(_QWORD *)(v3 + 8i64 * v10 + 48) = 0i64;
  v11 = *(_BYTE *)(v3 + 81);
  if ( v10 > v11 )
    v11 = v10;
  *(_BYTE *)(v3 + 81) = v11;
  v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (hkpBroadPhaseBorder *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v12[11] + 8i64))(v12[11], 128i64);
  v14 = (UFG::BroadPhaseHandler *)v13;
  v52 = v13;
  if ( v13 )
  {
    hkpBroadPhaseBorder::hkpBroadPhaseBorder(v13, this->mWorld, BROADPHASE_BORDER_DO_NOTHING, 0);
    v14->hkpBroadPhaseBorder::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&UFG::BroadPhaseHandler::`vftable{for `hkReferencedObject};
    v14->hkpBroadPhaseBorder::hkpWorldDeletionListener::vfptr = (hkpWorldDeletionListenerVtbl *)&UFG::BroadPhaseHandler::`vftable{for `hkpWorldDeletionListener};
    v14->hkpBroadPhaseBorder::hkpPhantomOverlapListener::vfptr = (hkpPhantomOverlapListenerVtbl *)&UFG::BroadPhaseHandler::`vftable{for `hkpPhantomOverlapListener};
    v14->hkpBroadPhaseBorder::hkpWorldPostSimulationListener::vfptr = (hkpWorldPostSimulationListenerVtbl *)&UFG::BroadPhaseHandler::`vftable{for `hkpWorldPostSimulationListener};
    v14->mCallback = 0i64;
  }
  else
  {
    v14 = 0i64;
  }
  this->mBroadPhaseBorder = v14;
  v15 = *(_BYTE *)(v3 + 80);
  if ( v15 > 0 )
  {
    *(_BYTE *)(v3 + 80) = v15 - 1;
  }
  else
  {
    *(_BYTE *)(v3 + 80) = 0;
    *(_DWORD *)v3 = 3;
    *(_QWORD *)(v3 + 16) = 0i64;
    *(_QWORD *)(v3 + 48) = 0i64;
  }
  hkpWorld::setBroadPhaseBorder(this->mWorld, this->mBroadPhaseBorder);
  hkReferencedObject::removeReference(this->mBroadPhaseBorder);
  UFG::BasePhysicsSystem::RegisterAgents(this);
  v16 = ++*(_BYTE *)(v3 + 80);
  *(_DWORD *)(v3 + 4i64 * v16) = 3;
  *(_QWORD *)(v3 + 8i64 * v16 + 16) = "CustomCollisionFilter";
  *(_QWORD *)(v3 + 8i64 * v16 + 48) = 0i64;
  v17 = *(_BYTE *)(v3 + 81);
  if ( v16 > v17 )
    v17 = v16;
  *(_BYTE *)(v3 + 81) = v17;
  v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v19 = (UFG::CustomCollisionFilter *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v18[11] + 8i64))(v18[11], 304i64);
  v52 = v19;
  if ( v19 )
    UFG::CustomCollisionFilter::CustomCollisionFilter(v19);
  else
    v20 = 0i64;
  this->mCollisionFilter = v20;
  v21 = *(_BYTE *)(v3 + 80);
  if ( v21 > 0 )
  {
    *(_BYTE *)(v3 + 80) = v21 - 1;
  }
  else
  {
    *(_BYTE *)(v3 + 80) = 0;
    *(_DWORD *)v3 = 3;
    *(_QWORD *)(v3 + 16) = 0i64;
    *(_QWORD *)(v3 + 48) = 0i64;
  }
  hkpWorld::setCollisionFilter(
    this->mWorld,
    this->mCollisionFilter,
    (hkBool)1,
    HK_UPDATE_FILTER_ON_WORLD_FULL_CHECK,
    HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
  UFG::WorldCollisionListener::Initialize(this->mWorld);
  if ( UFG::BasePhysicsSystem::mParam.numThreads > 1 )
  {
    v22 = (unsigned int)(UFG::BasePhysicsSystem::mParam.numThreads - 1);
    hkCpuJobThreadPoolCinfo::hkCpuJobThreadPoolCinfo(&ci);
    ci.m_numThreads = v22;
    *(_QWORD *)&ci.m_stackSize = 98304i64;
    v23 = ++*(_BYTE *)(v3 + 80);
    *(_DWORD *)(v3 + 4i64 * v23) = 3;
    *(_QWORD *)(v3 + 8i64 * v23 + 16) = "hkCpuJobThreadPool";
    *(_QWORD *)(v3 + 8i64 * v23 + 48) = 0i64;
    v24 = *(_BYTE *)(v3 + 81);
    if ( v23 > v24 )
      v24 = v23;
    *(_BYTE *)(v3 + 81) = v24;
    v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v26 = (hkCpuJobThreadPool *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v25[11] + 8i64))(v25[11], 960i64);
    v52 = v26;
    if ( v26 )
      hkCpuJobThreadPool::hkCpuJobThreadPool(v26, &ci);
    else
      v27 = 0i64;
    this->mThreadPool = v27;
    v28 = *(_BYTE *)(v3 + 80);
    if ( v28 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v28 - 1;
    }
    else
    {
      *(_BYTE *)(v3 + 80) = 0;
      *(_DWORD *)v3 = 3;
      *(_QWORD *)(v3 + 16) = 0i64;
      *(_QWORD *)(v3 + 48) = 0i64;
    }
    if ( (int)v22 > 0 )
    {
      p_m_memSizeAndFlags = (hkThread *)&this->mThreadPool[2].m_memSizeAndFlags;
      do
      {
        Handle = hkThread::getHandle(p_m_memSizeAndFlags);
        SetThreadPriority(Handle, 2);
        p_m_memSizeAndFlags = (hkThread *)((char *)p_m_memSizeAndFlags + 72);
        --v22;
      }
      while ( v22 );
    }
    hkJobQueueHwSetup::hkJobQueueHwSetup(&v50.m_jobQueueHwSetup);
    LODWORD(ci.m_threadName) = 20;
    v50.m_jobQueueHwSetup.m_numCpuThreads = UFG::BasePhysicsSystem::mParam.numThreads;
    v31 = ++*(_BYTE *)(v3 + 80);
    *(_DWORD *)(v3 + 4i64 * v31) = 3;
    *(_QWORD *)(v3 + 8i64 * v31 + 16) = "hkJobQueue";
    *(_QWORD *)(v3 + 8i64 * v31 + 48) = 0i64;
    v32 = *(_BYTE *)(v3 + 81);
    if ( v31 > v32 )
      v32 = v31;
    *(_BYTE *)(v3 + 81) = v32;
    v33 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v34 = (hkJobQueue *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v33[11] + 8i64))(v33[11], 1024i64);
    v52 = v34;
    if ( v34 )
      hkJobQueue::hkJobQueue(v34, &v50);
    else
      v35 = 0i64;
    this->mJobQueue = v35;
    v36 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v37 = (HavokJobMemoryPoolTagger *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v36[11] + 8i64))(v36[11], 8i64);
    v52 = v37;
    if ( v37 )
    {
      v37->vfptr = (hkExternalJobProfilerVtbl *)&hkExternalJobProfiler::`vftable;
      v37->vfptr = (hkExternalJobProfilerVtbl *)&HavokJobMemoryPoolTagger::`vftable;
    }
    else
    {
      v37 = 0i64;
    }
    this->mMemoryPoolTagger = v37;
    hkJobQueue::setExternalProfiler(this->mJobQueue, v37);
    v38 = *(_BYTE *)(v3 + 80);
    if ( v38 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v38 - 1;
    }
    else
    {
      *(_BYTE *)(v3 + 80) = 0;
      *(_DWORD *)v3 = 3;
      *(_QWORD *)(v3 + 16) = 0i64;
      *(_QWORD *)(v3 + 48) = 0i64;
    }
    v39 = (hkMonitorStream *)TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    hkMonitorStream::resize(v39, 0);
    hkpWorld::registerWithJobQueue(this->mJobQueue);
    v40 = ++*(_BYTE *)(v3 + 80);
    *(_DWORD *)(v3 + 4i64 * v40) = 3;
    *(_QWORD *)(v3 + 8i64 * v40 + 16) = "hkSemaphoreBusyWait";
    *(_QWORD *)(v3 + 8i64 * v40 + 48) = 0i64;
    v41 = *(_BYTE *)(v3 + 81);
    if ( v40 > v41 )
      v41 = v40;
    *(_BYTE *)(v3 + 81) = v41;
    v42 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v43 = (hkSemaphore *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v42[11] + 8i64))(v42[11], 8i64);
    v52 = v43;
    if ( v43 )
      hkSemaphore::hkSemaphore(v43, 0, 1000, 0);
    else
      v44 = 0i64;
    this->mRayCastSemaphore = v44;
    hkpRayCastQueryJobQueueUtils::registerWithJobQueue(this->mJobQueue);
    v45 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v46 = (hkSemaphore *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v45[11] + 8i64))(v45[11], 8i64);
    v52 = v46;
    if ( v46 )
      hkSemaphore::hkSemaphore(v46, 0, 1000, 0);
    else
      v47 = 0i64;
    this->mShapeCastSemaphore = v47;
    hkpCollisionQueryJobQueueUtils::registerWithJobQueue(this->mJobQueue);
    v48 = *(_BYTE *)(v3 + 80);
    if ( v48 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v48 - 1;
    }
    else
    {
      *(_BYTE *)(v3 + 80) = 0;
      *(_DWORD *)v3 = 3;
      *(_QWORD *)(v3 + 16) = 0i64;
      *(_QWORD *)(v3 + 48) = 0i64;
    }
    hkpFixedBufferCdPointCollector::registerDefaultAddCdPointFunction();
    hkJobQueueHwSetup::~hkJobQueueHwSetup(&v50.m_jobQueueHwSetup);
    ci.m_hardwareThreadIds.m_size = 0;
    if ( ci.m_hardwareThreadIds.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        ci.m_hardwareThreadIds.m_data,
        4 * ci.m_hardwareThreadIds.m_capacityAndFlags);
    ci.m_hardwareThreadIds.m_data = 0i64;
    ci.m_hardwareThreadIds.m_capacityAndFlags = 0x80000000;
  }
  hkpWorld::unlock(this->mWorld);
  *(_QWORD *)&v50.m_jobQueueHwSetup.m_spuSchedulePolicy = &hkpWorldCinfo::`vftable;
  if ( *(_QWORD *)&v51.m_collisionTolerance )
    hkReferencedObject::removeReference(*(hkReferencedObject **)&v51.m_collisionTolerance);
  *(_QWORD *)&v51.m_collisionTolerance = 0i64;
  if ( v51.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[1] )
    hkReferencedObject::removeReference((hkReferencedObject *)v51.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[1]);
  v51.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[1] = 0i64;
  if ( v51.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[0] )
    hkReferencedObject::removeReference((hkReferencedObject *)v51.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[0]);
}moveReference((hkReferencedObject *)v51.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[1]);
  v51.m_broadPhaseWorldAabb.m_min.m

// File Line: 363
// RVA: 0xA2710
void __fastcall UFG::BasePhysicsSystem::CloseWorld(UFG::BasePhysicsSystem *this)
{
  UFG::CustomCollisionFilter *mCollisionFilter; // rcx
  hkJobQueue *mJobQueue; // rdi
  _QWORD **Value; // rax
  HavokJobMemoryPoolTagger *mMemoryPoolTagger; // rcx
  hkJobThreadPool *mThreadPool; // rcx

  mCollisionFilter = this->mCollisionFilter;
  if ( mCollisionFilter )
    mCollisionFilter->hkpGroupFilter::hkpCollisionFilter::hkReferencedObject::hkBaseObject::vfptr->__vecDelDtor(
      mCollisionFilter,
      1u);
  hkReferencedObject::removeReference(this->mWorld);
  mJobQueue = this->mJobQueue;
  if ( mJobQueue )
  {
    hkJobQueue::~hkJobQueue(this->mJobQueue);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkJobQueue *, __int64))(*Value[11] + 16i64))(Value[11], mJobQueue, 1024i64);
  }
  mMemoryPoolTagger = this->mMemoryPoolTagger;
  if ( mMemoryPoolTagger )
    mMemoryPoolTagger->vfptr->__vecDelDtor(mMemoryPoolTagger, 1u);
  mThreadPool = this->mThreadPool;
  if ( mThreadPool )
    hkReferencedObject::removeReference(mThreadPool);
}

// File Line: 378
// RVA: 0xAE6D0
void __fastcall UFG::BasePhysicsSystem::RegisterAgents(UFG::BasePhysicsSystem *this)
{
  hkpCollisionDispatcher *m_collisionDispatcher; // rbx

  m_collisionDispatcher = this->mWorld->m_collisionDispatcher;
  hkpCollisionDispatcher::registerAlternateShapeType(m_collisionDispatcher, SPHERE, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(m_collisionDispatcher, TRIANGLE, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(m_collisionDispatcher, BOX, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(m_collisionDispatcher, CAPSULE, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(m_collisionDispatcher, CYLINDER, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(m_collisionDispatcher, CONVEX_VERTICES, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(m_collisionDispatcher, CONVEX_TRANSFORM, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(m_collisionDispatcher, CONVEX_PIECE, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(m_collisionDispatcher, TRIANGLE_COLLECTION, COLLECTION);
  hkpCollisionDispatcher::registerAlternateShapeType(m_collisionDispatcher, LIST, COLLECTION);
  hkpCollisionDispatcher::registerAlternateShapeType(m_collisionDispatcher, EXTENDED_MESH, COLLECTION);
  hkpCollisionDispatcher::registerAlternateShapeType(m_collisionDispatcher, MOPP, BV_TREE);
  hkpCollisionDispatcher::registerAlternateShapeType(m_collisionDispatcher, CONVEX, SPHERE_REP);
  hkpCollisionDispatcher::registerAlternateShapeType(m_collisionDispatcher, SAMPLED_HEIGHT_FIELD, HEIGHT_FIELD);
  hkpCollisionDispatcher::registerAlternateShapeType(m_collisionDispatcher, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE, BV_TREE);
  hkpBvAgent::registerAgent(m_collisionDispatcher);
  hkpAgentRegisterUtil::_registerBvTreeAgents(m_collisionDispatcher);
  hkpCollisionDispatcher::setEnableChecks(m_collisionDispatcher, 0);
  hkpShapeCollectionAgent::registerAgent(m_collisionDispatcher);
  hkpCollisionDispatcher::setEnableChecks(m_collisionDispatcher, (hkBool)1);
  hkpAgentRegisterUtil::_registerListAgents(m_collisionDispatcher);
  hkpTransformAgent::registerAgent(m_collisionDispatcher);
  hkpPhantomAgent::registerAgent(m_collisionDispatcher);
  hkpAgentRegisterUtil::_registerTerminalAgents(m_collisionDispatcher);
}

// File Line: 450
// RVA: 0xA01E0
void __fastcall UFG::BasePhysicsSystem::AddCollisionInstanceToWorld(
        UFG::BasePhysicsSystem *this,
        UFG::CollisionInstanceData *instance)
{
  unsigned int mCollisionModelGuid; // edx
  UFG::CollisionMeshData *v5; // rax
  UFG::qReflectObject *mData; // rcx

  mCollisionModelGuid = instance->mCollisionModelGuid;
  if ( mCollisionModelGuid )
  {
    v5 = (UFG::CollisionMeshData *)UFG::qBaseTreeRB::Get(&this->mCollisionModels.mTree, mCollisionModelGuid);
    if ( v5 )
    {
      mData = v5->mObjectProperties.mData;
      if ( !this->mBuildingAiData || LOBYTE(mData[1].mHandles.mNode.mNext) )
      {
        if ( LODWORD(mData[2].mBaseNode.mChildren[1]) == 1 )
        {
          this->vfptr->OnCollisionInstanceAddedToWorld(this, instance, v5, 1u, 0, 0i64);
        }
        else if ( UFG::RigidBody::mCount < UFG::BasePhysicsSystem::mParam.maxLoadedBodies )
        {
          this->vfptr->OnCollisionInstanceAddedToWorld(
            this,
            instance,
            v5,
            1u,
            LODWORD(mData[2].mBaseNode.mNeighbours[0]) == 0,
            0i64);
        }
      }
    }
  }
}

// File Line: 481
// RVA: 0xAF610
void __fastcall UFG::BasePhysicsSystem::RemoveCollisionInstanceFromWorld(
        UFG::BasePhysicsSystem *this,
        UFG::CollisionInstanceData *instance)
{
  this->vfptr->OnCollisionInstanceRemovedFromWorld(this, instance);
}

// File Line: 488
// RVA: 0xAE3A0
void __fastcall UFG::BasePhysicsSystem::PreFrameUpdate(UFG::BasePhysicsSystem *this, float timestep)
{
  UFG::BasePhysicsSystem::AddBatchedEntities(this);
  UFG::BasePhysicsSystem::mSyncRayCastCount = 0;
  UFG::BasePhysicsSystem::mAsyncRayCastCount = 0;
  UFG::BasePhysicsSystem::mAsyncShapeCastCount = 0;
}

// File Line: 510
// RVA: 0xB44B0
void __fastcall UFG::BasePhysicsSystem::Update(UFG::BasePhysicsSystem *this, float deltaTime)
{
  float v2; // xmm7_4
  __m128 v4; // xmm2
  int v5; // ecx
  float v6; // xmm6_4
  __int64 v7; // rbx
  hkpWorld *mWorld; // rcx
  hkJobThreadPool *mThreadPool; // rcx
  UFG::CollisionMeshData::DeferredBreakablePartsMark *mNext; // rbx
  UFG::qList<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark,1,0> *v11; // rsi
  float v12; // xmm0_4
  UFG::RigidBody *m_pPointer; // rcx
  UFG::qNode<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark> *v14; // rax
  UFG::qNode<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark> *mPrev; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody> *p_rigidBody; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark> *v21; // rcx
  UFG::qNode<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark> *v22; // rax

  v2 = deltaTime;
  if ( deltaTime > 0.000001 )
  {
    if ( this->mWorld )
    {
      _mm_setcsr(_mm_getcsr() | 0x8000);
      v2 = deltaTime;
      v4 = (__m128)LODWORD(deltaTime);
      v4.m128_f32[0] = deltaTime * 29.999998;
      v5 = (int)(float)(deltaTime * 29.999998);
      if ( v5 != 0x80000000 && (float)v5 != v4.m128_f32[0] )
        v4.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v4, v4)) & 1) + v5);
      v6 = deltaTime / v4.m128_f32[0];
      if ( (int)v4.m128_f32[0] > 0 )
      {
        v7 = (unsigned int)(int)v4.m128_f32[0];
        do
        {
          mWorld = this->mWorld;
          if ( UFG::BasePhysicsSystem::mParam.numThreads <= 1 )
            hkpWorld::stepDeltaTime(mWorld, v6);
          else
            hkpWorld::stepMultithreaded(mWorld, this->mJobQueue, this->mThreadPool, v6);
          --v7;
        }
        while ( v7 );
      }
    }
    mThreadPool = this->mThreadPool;
    if ( mThreadPool )
      mThreadPool->vfptr[4].__first_virtual_table_function__(mThreadPool);
  }
  mNext = (UFG::CollisionMeshData::DeferredBreakablePartsMark *)UFG::CollisionMeshData::mDeferredBreakableList.mNode.mNext;
  if ( (UFG::qList<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark,1,0> *)UFG::CollisionMeshData::mDeferredBreakableList.mNode.mNext != &UFG::CollisionMeshData::mDeferredBreakableList )
  {
    do
    {
      v11 = (UFG::qList<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark,1,0> *)mNext->mNext;
      v12 = mNext->timer - v2;
      mNext->timer = v12;
      if ( v12 < 0.0 )
      {
        m_pPointer = (UFG::RigidBody *)mNext->rigidBody.m_pPointer;
        if ( !m_pPointer )
        {
          mPrev = mNext->mPrev;
          mPrev->mNext = &v11->mNode;
          v11->mNode.mPrev = mPrev;
          mNext->mPrev = mNext;
          mNext->mNext = mNext;
          p_rigidBody = &mNext->rigidBody;
          if ( mNext->rigidBody.m_pPointer )
          {
            v17 = p_rigidBody->mPrev;
            v18 = mNext->rigidBody.mNext;
            v17->mNext = v18;
            v18->mPrev = v17;
            p_rigidBody->mPrev = p_rigidBody;
            mNext->rigidBody.mNext = &mNext->rigidBody;
          }
          mNext->rigidBody.m_pPointer = 0i64;
          v19 = p_rigidBody->mPrev;
          v20 = mNext->rigidBody.mNext;
          v19->mNext = v20;
          v20->mPrev = v19;
          p_rigidBody->mPrev = p_rigidBody;
          mNext->rigidBody.mNext = &mNext->rigidBody;
          v21 = mNext->mPrev;
          v22 = mNext->mNext;
          v21->mNext = v22;
          v22->mPrev = v21;
          mNext->mPrev = mNext;
          mNext->mNext = mNext;
          goto LABEL_22;
        }
        if ( m_pPointer->mBody )
        {
          v14 = mNext->mPrev;
          v14->mNext = &v11->mNode;
          v11->mNode.mPrev = v14;
          mNext->mPrev = mNext;
          mNext->mNext = mNext;
          UFG::CollisionMeshData::MarkBreakableParts(m_pPointer->mCollisionMeshData, m_pPointer, 0.0);
          UFG::SupplementaryAttackTarget::~SupplementaryAttackTarget(mNext);
LABEL_22:
          operator delete[](mNext);
        }
      }
      mNext = (UFG::CollisionMeshData::DeferredBreakablePartsMark *)v11;
    }
    while ( v11 != &UFG::CollisionMeshData::mDeferredBreakableList );
  }
  ++this->mFrameNumber;
}

// File Line: 594
// RVA: 0xA1650
char __fastcall UFG::BasePhysicsSystem::CastAsyncRay(
        UFG::BasePhysicsSystem *this,
        UFG::qVector3 *rayStart,
        UFG::qVector3 *rayEnd,
        int collisionFilter,
        void (__fastcall *callback)(UFG::RayCastData *, UFG::SimComponent *, void *),
        UFG::SimComponent *simComponent,
        void *userData)
{
  UFG::BasePhysicsSystem::RaycastBatch *mRaycastBatchSubmitBuffer; // rcx
  unsigned int mCount; // r11d
  hkpWorld *mWorld; // rax
  __m128 m_quad; // xmm6
  __m128 v12; // xmm4
  __m128 v13; // xmm3
  __m128 *p_m_quad; // rax
  __m128 z_low; // xmm0
  __m128 x_low; // xmm3
  __m128 v17; // xmm2
  UFG::CastData *v18; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  char result; // al

  mRaycastBatchSubmitBuffer = this->mRaycastBatchSubmitBuffer;
  mCount = mRaycastBatchSubmitBuffer->mCount;
  if ( mCount >= 0xA4 )
    return 0;
  mWorld = this->mWorld;
  m_quad = mWorld->m_broadPhaseExtents[1].m_quad;
  v12 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(rayStart->x), (__m128)LODWORD(rayStart->z)),
          _mm_unpacklo_ps((__m128)LODWORD(rayStart->y), (__m128)(unsigned int)FLOAT_1_0));
  v13 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(rayEnd->x), (__m128)LODWORD(rayEnd->z)),
          _mm_unpacklo_ps((__m128)LODWORD(rayEnd->y), (__m128)(unsigned int)FLOAT_1_0));
  if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v12, m_quad), _mm_cmple_ps(mWorld->m_broadPhaseExtents[0].m_quad, v12))) & 7) != 7
    || (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v13, m_quad), _mm_cmple_ps(mWorld->m_broadPhaseExtents[0].m_quad, v13))) & 7) != 7 )
  {
    return 0;
  }
  p_m_quad = &mRaycastBatchSubmitBuffer->mAsyncRayData[mCount].mInput.m_from.m_quad;
  *p_m_quad = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)LODWORD(rayStart->x), (__m128)LODWORD(rayStart->z)),
                _mm_unpacklo_ps((__m128)LODWORD(rayStart->y), (__m128)0i64));
  z_low = (__m128)LODWORD(rayEnd->z);
  x_low = (__m128)LODWORD(rayEnd->x);
  v17 = _mm_unpacklo_ps((__m128)LODWORD(rayEnd->y), (__m128)0i64);
  p_m_quad[2].m128_i32[1] = collisionFilter;
  p_m_quad[1] = _mm_unpacklo_ps(_mm_unpacklo_ps(x_low, z_low), v17);
  p_m_quad[2].m128_i8[0] = 1;
  p_m_quad[12].m128_i8[8] = 0;
  p_m_quad[11].m128_u64[1] = 0i64;
  p_m_quad[12].m128_u64[0] = 0i64;
  v18 = &this->mRaycastBatchSubmitBuffer->mAsyncRayData[this->mRaycastBatchSubmitBuffer->mCount].UFG::CastData;
  if ( v18->simComponent.m_pPointer )
  {
    mPrev = v18->simComponent.mPrev;
    mNext = v18->simComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v18->simComponent.mPrev = &v18->simComponent;
    v18->simComponent.mNext = &v18->simComponent;
  }
  v18->simComponent.m_pPointer = simComponent;
  if ( simComponent )
  {
    v21 = simComponent->m_SafePointerList.mNode.mPrev;
    v21->mNext = &v18->simComponent;
    v18->simComponent.mPrev = v21;
    v18->simComponent.mNext = &simComponent->m_SafePointerList.mNode;
    simComponent->m_SafePointerList.mNode.mPrev = &v18->simComponent;
  }
  result = 1;
  this->mRaycastBatchSubmitBuffer->mAsyncRayData[this->mRaycastBatchSubmitBuffer->mCount].callbackUserData = userData;
  this->mRaycastBatchSubmitBuffer->mAsyncRayData[this->mRaycastBatchSubmitBuffer->mCount++].raycastCallback = callback;
  return result;
}

// File Line: 634
// RVA: 0xB3500
void __fastcall UFG::BasePhysicsSystem::StartAsyncRayCasts(UFG::BasePhysicsSystem *this)
{
  UFG::BasePhysicsSystem::RaycastBatch *mRaycastBatchSubmitBuffer; // rax
  UFG::BasePhysicsSystem::RaycastBatch *mRaycastBatchExecuteBuffer; // rdx
  unsigned int numThreads; // r11d
  unsigned int v5; // esi
  unsigned int mCount; // ebp
  __int64 v7; // r8
  __int64 v8; // r10
  __int64 v9; // r9
  __int64 v10; // r12
  unsigned int v11; // eax
  __int64 v12; // r15
  UFG::BasePhysicsSystem::RaycastBatch *v13; // rax
  UFG::BasePhysicsSystem::RaycastBatch *v14; // rdx
  hkpWorldRayCastCommand *m_data; // rcx
  UFG::BasePhysicsSystem::RaycastBatch *v16; // rax
  UFG::BasePhysicsSystem::RaycastBatch *v17; // rdx
  hkpWorldRayCastCommand *v18; // rcx
  UFG::BasePhysicsSystem::RaycastBatch *v19; // rax
  UFG::BasePhysicsSystem::RaycastBatch *v20; // rdx
  hkpWorldRayCastCommand *v21; // rcx
  UFG::BasePhysicsSystem::RaycastBatch *v22; // rax
  UFG::BasePhysicsSystem::RaycastBatch *v23; // rdx
  hkpWorldRayCastCommand *v24; // rcx
  hkpWorldRayCastOutput *v25; // rcx
  __int64 v26; // r9
  __int64 v27; // r8
  __int64 v28; // r10
  __int64 v29; // rsi
  UFG::BasePhysicsSystem::RaycastBatch *v30; // rax
  UFG::BasePhysicsSystem::RaycastBatch *v31; // rdx
  hkpWorldRayCastCommand *v32; // rcx
  hkpWorldRayCastOutput *v33; // rcx
  float v34; // xmm0_4
  int v35; // r15d
  signed int v36; // ebp
  __int64 v37; // r12
  hkpWorld *mWorld; // rax
  hkpProcessCollisionInput *m_collisionInput; // rcx
  hkpBroadPhase *m_broadPhase; // rdx
  hkSemaphore *mRayCastSemaphore; // rax
  int v42; // esi
  hkpCollisionQueryJobHeader *mRayCastJobHeader; // r8
  hkpWorldRayCastCommand *v44; // rcx
  int v45; // eax
  UFG::AsyncRayCastData *v46; // rdx
  hkpWorldRayCastJob v47; // [rsp+20h] [rbp-88h] BYREF

  mRaycastBatchSubmitBuffer = this->mRaycastBatchSubmitBuffer;
  mRaycastBatchExecuteBuffer = this->mRaycastBatchExecuteBuffer;
  this->mRaycastBatchExecuteBuffer = mRaycastBatchSubmitBuffer;
  this->mRaycastBatchSubmitBuffer = mRaycastBatchExecuteBuffer;
  if ( mRaycastBatchSubmitBuffer->mCount )
  {
    this->mRaycastCallbackActive = 1;
    numThreads = UFG::BasePhysicsSystem::mParam.numThreads;
    v5 = 0;
    if ( UFG::BasePhysicsSystem::mParam.numThreads <= 1u )
    {
      if ( mRaycastBatchSubmitBuffer->mCount )
      {
        do
        {
          v46 = &this->mRaycastBatchExecuteBuffer->mAsyncRayData[v5];
          v46->mOutput.m_rootCollidable = 0i64;
          v46->mOutput.m_hitFraction = 1.0;
          v46->mOutput.m_extraInfo = -1;
          v46->mOutput.m_shapeKeyIndex = 0;
          v46->mOutput.m_shapeKeys[0] = -1;
          UFG::BasePhysicsSystem::CastRay(this, v46);
          ++v5;
        }
        while ( v5 < this->mRaycastBatchExecuteBuffer->mCount );
      }
    }
    else
    {
      mCount = mRaycastBatchSubmitBuffer->mCount;
      v7 = 0i64;
      if ( (int)mCount >= 4 )
      {
        v8 = 0i64;
        v9 = 0i64;
        v10 = 544i64;
        v11 = ((mCount - 4) >> 2) + 1;
        v12 = v11;
        v5 = 4 * v11;
        v7 = 4i64 * v11;
        do
        {
          v13 = this->mRaycastBatchExecuteBuffer;
          v13->mAsyncRayData[v9].mOutput.m_rootCollidable = 0i64;
          v13->mAsyncRayData[v9].mOutput.m_hitFraction = 1.0;
          v13->mAsyncRayData[v9].mOutput.m_extraInfo = -1;
          v13->mAsyncRayData[v9].mOutput.m_shapeKeyIndex = 0;
          v13->mAsyncRayData[v9].mOutput.m_shapeKeys[0] = -1;
          v14 = this->mRaycastBatchExecuteBuffer;
          m_data = this->mRayCastCommands.m_data;
          m_data[v8].m_rayInput.m_from = v14->mAsyncRayData[v9].mInput.m_from;
          m_data[v8].m_rayInput.m_to = v14->mAsyncRayData[v9].mInput.m_to;
          m_data[v8].m_rayInput.m_enableShapeCollectionFilter.m_bool = v14->mAsyncRayData[v9].mInput.m_enableShapeCollectionFilter.m_bool;
          m_data[v8].m_rayInput.m_filterInfo = v14->mAsyncRayData[v9].mInput.m_filterInfo;
          m_data[v8].m_rayInput.m_userData = v14->mAsyncRayData[v9].mInput.m_userData;
          this->mRayCastCommands.m_data[v8].m_results = (hkpWorldRayCastOutput *)((char *)&this->mRaycastBatchExecuteBuffer[-1].mAsyncRayData[162].mOutput.m_hitFraction
                                                                                + v10);
          this->mRayCastCommands.m_data[v8].m_resultsCapacity = 1;
          this->mRayCastCommands.m_data[v8].m_numResultsOut = 0;
          this->mRayCastCommands.m_data[v8].m_rayInput.m_enableShapeCollectionFilter.m_bool = 1;
          v16 = this->mRaycastBatchExecuteBuffer;
          v16->mAsyncRayData[v9 + 1].mOutput.m_rootCollidable = 0i64;
          v16->mAsyncRayData[v9 + 1].mOutput.m_hitFraction = 1.0;
          v16->mAsyncRayData[v9 + 1].mOutput.m_extraInfo = -1;
          v16->mAsyncRayData[v9 + 1].mOutput.m_shapeKeyIndex = 0;
          v16->mAsyncRayData[v9 + 1].mOutput.m_shapeKeys[0] = -1;
          v17 = this->mRaycastBatchExecuteBuffer;
          v18 = this->mRayCastCommands.m_data;
          v18[v8 + 1].m_rayInput.m_from = v17->mAsyncRayData[v9 + 1].mInput.m_from;
          v18[v8 + 1].m_rayInput.m_to = v17->mAsyncRayData[v9 + 1].mInput.m_to;
          v18[v8 + 1].m_rayInput.m_enableShapeCollectionFilter.m_bool = v17->mAsyncRayData[v9 + 1].mInput.m_enableShapeCollectionFilter.m_bool;
          v18[v8 + 1].m_rayInput.m_filterInfo = v17->mAsyncRayData[v9 + 1].mInput.m_filterInfo;
          v18[v8 + 1].m_rayInput.m_userData = v17->mAsyncRayData[v9 + 1].mInput.m_userData;
          this->mRayCastCommands.m_data[v8 + 1].m_results = (hkpWorldRayCastOutput *)((char *)&this->mRaycastBatchExecuteBuffer[-1].mAsyncRayData[163].mOutput.m_hitFraction
                                                                                    + v10);
          this->mRayCastCommands.m_data[v8 + 1].m_resultsCapacity = 1;
          this->mRayCastCommands.m_data[v8 + 1].m_numResultsOut = 0;
          this->mRayCastCommands.m_data[v8 + 1].m_rayInput.m_enableShapeCollectionFilter.m_bool = 1;
          v19 = this->mRaycastBatchExecuteBuffer;
          v19->mAsyncRayData[v9 + 2].mOutput.m_rootCollidable = 0i64;
          v19->mAsyncRayData[v9 + 2].mOutput.m_hitFraction = 1.0;
          v19->mAsyncRayData[v9 + 2].mOutput.m_extraInfo = -1;
          v19->mAsyncRayData[v9 + 2].mOutput.m_shapeKeyIndex = 0;
          v19->mAsyncRayData[v9 + 2].mOutput.m_shapeKeys[0] = -1;
          v20 = this->mRaycastBatchExecuteBuffer;
          v21 = this->mRayCastCommands.m_data;
          v21[v8 + 2].m_rayInput.m_from = v20->mAsyncRayData[v9 + 2].mInput.m_from;
          v21[v8 + 2].m_rayInput.m_to = v20->mAsyncRayData[v9 + 2].mInput.m_to;
          v21[v8 + 2].m_rayInput.m_enableShapeCollectionFilter.m_bool = v20->mAsyncRayData[v9 + 2].mInput.m_enableShapeCollectionFilter.m_bool;
          v21[v8 + 2].m_rayInput.m_filterInfo = v20->mAsyncRayData[v9 + 2].mInput.m_filterInfo;
          v21[v8 + 2].m_rayInput.m_userData = v20->mAsyncRayData[v9 + 2].mInput.m_userData;
          this->mRayCastCommands.m_data[v8 + 2].m_results = (hkpWorldRayCastOutput *)((char *)&this->mRaycastBatchExecuteBuffer->mAsyncRayData[0].mOutput
                                                                                    + v10);
          v8 += 4i64;
          v9 += 4i64;
          *((_DWORD *)&this->mRayCastCommands.m_data[v8 - 1] - 6) = 1;
          *((_DWORD *)&this->mRayCastCommands.m_data[v8 - 1] - 5) = 0;
          *((_BYTE *)&this->mRayCastCommands.m_data[v8 - 1] - 48) = 1;
          v22 = this->mRaycastBatchExecuteBuffer;
          v22->mAsyncRayData[v9 - 1].mOutput.m_rootCollidable = 0i64;
          v22->mAsyncRayData[v9 - 1].mOutput.m_hitFraction = 1.0;
          v22->mAsyncRayData[v9 - 1].mOutput.m_extraInfo = -1;
          v22->mAsyncRayData[v9 - 1].mOutput.m_shapeKeyIndex = 0;
          v22->mAsyncRayData[v9 - 1].mOutput.m_shapeKeys[0] = -1;
          v23 = this->mRaycastBatchExecuteBuffer;
          v24 = this->mRayCastCommands.m_data;
          v24[v8 - 1].m_rayInput.m_from = v23->mAsyncRayData[v9 - 1].mInput.m_from;
          v24[v8 - 1].m_rayInput.m_to = v23->mAsyncRayData[v9 - 1].mInput.m_to;
          v24[v8 - 1].m_rayInput.m_enableShapeCollectionFilter.m_bool = v23->mAsyncRayData[v9 - 1].mInput.m_enableShapeCollectionFilter.m_bool;
          v24[v8 - 1].m_rayInput.m_filterInfo = v23->mAsyncRayData[v9 - 1].mInput.m_filterInfo;
          v24[v8 - 1].m_rayInput.m_userData = v23->mAsyncRayData[v9 - 1].mInput.m_userData;
          v25 = (hkpWorldRayCastOutput *)((char *)&this->mRaycastBatchExecuteBuffer->mAsyncRayData[1].mOutput + v10);
          v10 += 1088i64;
          this->mRayCastCommands.m_data[v8 - 1].m_results = v25;
          this->mRayCastCommands.m_data[v8 - 1].m_resultsCapacity = 1;
          this->mRayCastCommands.m_data[v8 - 1].m_numResultsOut = 0;
          this->mRayCastCommands.m_data[v8 - 1].m_rayInput.m_enableShapeCollectionFilter.m_bool = 1;
          --v12;
        }
        while ( v12 );
      }
      if ( v5 < mCount )
      {
        v26 = v7;
        v27 = v7;
        v28 = 272i64 * v5;
        v29 = mCount - v5;
        do
        {
          v30 = this->mRaycastBatchExecuteBuffer;
          ++v26;
          v30->mAsyncRayData[v27++].mOutput.m_rootCollidable = 0i64;
          v30->mAsyncRayData[v27 - 1].mOutput.m_hitFraction = 1.0;
          v30->mAsyncRayData[v27 - 1].mOutput.m_extraInfo = -1;
          v30->mAsyncRayData[v27 - 1].mOutput.m_shapeKeyIndex = 0;
          v30->mAsyncRayData[v27 - 1].mOutput.m_shapeKeys[0] = -1;
          v31 = this->mRaycastBatchExecuteBuffer;
          v32 = this->mRayCastCommands.m_data;
          v32[v26 - 1].m_rayInput.m_from = v31->mAsyncRayData[v27 - 1].mInput.m_from;
          v32[v26 - 1].m_rayInput.m_to = v31->mAsyncRayData[v27 - 1].mInput.m_to;
          v32[v26 - 1].m_rayInput.m_enableShapeCollectionFilter.m_bool = v31->mAsyncRayData[v27 - 1].mInput.m_enableShapeCollectionFilter.m_bool;
          v32[v26 - 1].m_rayInput.m_filterInfo = v31->mAsyncRayData[v27 - 1].mInput.m_filterInfo;
          v32[v26 - 1].m_rayInput.m_userData = v31->mAsyncRayData[v27 - 1].mInput.m_userData;
          v33 = (hkpWorldRayCastOutput *)((char *)&this->mRaycastBatchExecuteBuffer->mAsyncRayData[0].mOutput + v28);
          v28 += 272i64;
          this->mRayCastCommands.m_data[v26 - 1].m_results = v33;
          this->mRayCastCommands.m_data[v26 - 1].m_resultsCapacity = 1;
          this->mRayCastCommands.m_data[v26 - 1].m_numResultsOut = 0;
          this->mRayCastCommands.m_data[v26 - 1].m_rayInput.m_enableShapeCollectionFilter.m_bool = 1;
          --v29;
        }
        while ( v29 );
      }
      v34 = *(float *)&FLOAT_1_0;
      if ( mCount < numThreads )
        numThreads = mCount;
      if ( (float)(int)(mCount / numThreads) >= 1.0 )
        v34 = (float)(int)(mCount / numThreads);
      v35 = 0;
      v36 = mCount - numThreads * (int)v34;
      if ( numThreads )
      {
        v37 = numThreads;
        do
        {
          mWorld = this->mWorld;
          m_collisionInput = mWorld->m_collisionInput;
          m_broadPhase = mWorld->m_broadPhase;
          mRayCastSemaphore = this->mRayCastSemaphore;
          v47.m_collisionInput = m_collisionInput;
          v47.m_semaphore = mRayCastSemaphore;
          v42 = (int)v34 + (v36 > 0);
          v47.m_size = 96;
          mRayCastJobHeader = this->mRayCastJobHeader;
          --v36;
          *(_WORD *)&v47.m_jobSubType = 769;
          v47.m_threadAffinity = -1;
          v44 = &this->mRayCastCommands.m_data[v35];
          v47.m_jobDoneFlag = 0i64;
          v47.m_jobSpuType.m_storage = 1;
          v47.m_sharedJobHeaderOnPpu = mRayCastJobHeader;
          v47.m_numCommandsPerTask = 64;
          v47.m_numCommands = v42;
          v47.m_commandArray = v44;
          v47.m_broadphase = m_broadPhase;
          if ( v42 )
            v45 = (v42 - 1) / 64 + 1;
          else
            v45 = 1;
          mRayCastJobHeader->m_openJobs = v45;
          v47.m_bundleCommandArray = 0i64;
          v47.m_numBundleCommands = 0;
          hkpWorldRayCastJob::setRunsOnSpuOrPpu(&v47);
          hkJobQueue::addJob(this->mJobQueue, &v47, JOB_HIGH_PRIORITY);
          v35 += v42;
          --v37;
        }
        while ( v37 );
      }
      ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, __int64))this->mThreadPool->vfptr[5].__first_virtual_table_function__)(
        this->mThreadPool,
        this->mJobQueue,
        20i64);
    }
  }
}

// File Line: 702
// RVA: 0xB5D60
__int64 __fastcall UFG::BasePhysicsSystem::WaitForAsyncRayCastCompletion(UFG::BasePhysicsSystem *this)
{
  unsigned int i; // edi
  UFG::AsyncRayCastData *v3; // rcx
  float m_hitFraction; // xmm0_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm6_4
  float v8; // xmm5_4
  float v9; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  hkpCollidable *m_rootCollidable; // rax
  hkpRigidBody *v13; // r8
  hkpPhantom *v14; // rdx
  __int64 m_size; // r9
  __int64 v16; // rax
  hkSimpleProperty *m_data; // r10
  hkSimpleProperty *v18; // rdx
  unsigned __int64 v19; // rax
  __int64 v20; // r8
  hkSimpleProperty *v21; // rdx
  UFG::BasePhysicsSystem::RaycastBatch *mRaycastBatchExecuteBuffer; // rax

  if ( this->mRaycastBatchExecuteBuffer->mCount )
  {
    if ( UFG::BasePhysicsSystem::mParam.numThreads > 1 )
    {
      ((void (__fastcall *)(hkJobThreadPool *))this->mThreadPool->vfptr[2].__vecDelDtor)(this->mThreadPool);
      hkSemaphore::acquire(this->mRayCastSemaphore);
      for ( i = 0; i < this->mRaycastBatchExecuteBuffer->mCount; ++i )
      {
        v3 = &this->mRaycastBatchExecuteBuffer->mAsyncRayData[i];
        if ( !v3->mOutput.m_rootCollidable )
        {
          v3->hit = 0;
          continue;
        }
        m_hitFraction = v3->mOutput.m_hitFraction;
        v3->hit = 1;
        v5 = v3->mInput.m_to.m_quad.m128_f32[0];
        v6 = v3->mInput.m_to.m_quad.m128_f32[1];
        v7 = v3->mInput.m_to.m_quad.m128_f32[2];
        v3->t = m_hitFraction;
        v8 = (float)((float)(v6 - v3->mInput.m_from.m_quad.m128_f32[1]) * m_hitFraction)
           + v3->mInput.m_from.m_quad.m128_f32[1];
        v9 = (float)((float)(v7 - v3->mInput.m_from.m_quad.m128_f32[2]) * m_hitFraction)
           + v3->mInput.m_from.m_quad.m128_f32[2];
        v3->point.x = (float)((float)(v5 - v3->mInput.m_from.m_quad.m128_f32[0]) * m_hitFraction)
                    + v3->mInput.m_from.m_quad.m128_f32[0];
        v3->point.y = v8;
        v3->point.z = v9;
        v10 = v3->mOutput.m_normal.m_quad.m128_f32[1];
        v11 = v3->mOutput.m_normal.m_quad.m128_f32[2];
        LODWORD(v3->normal.x) = v3->mOutput.m_normal.m_quad.m128_i32[0];
        v3->normal.y = v10;
        v3->normal.z = v11;
        m_rootCollidable = v3->mOutput.m_rootCollidable;
        if ( m_rootCollidable->m_broadPhaseHandle.m_type == 1 )
          v13 = (hkpRigidBody *)((char *)m_rootCollidable + m_rootCollidable->m_ownerOffset);
        else
          v13 = 0i64;
        v3->mHavokRigidBody = v13;
        if ( m_rootCollidable->m_broadPhaseHandle.m_type == 2 )
          v14 = (hkpPhantom *)((char *)m_rootCollidable + m_rootCollidable->m_ownerOffset);
        else
          v14 = 0i64;
        v3->mHavokPhantom = v14;
        v3->mPhysicsObjectPropertyHandleUid = 0i64;
        v3->mPhysicsSurfacePropertyHandleUid = 0i64;
        if ( v13 )
        {
          m_size = v13->m_properties.m_size;
          v16 = 0i64;
          if ( m_size > 0 )
          {
            m_data = v13->m_properties.m_data;
            v18 = m_data;
            while ( v18->m_key != UFG::physicsObjectPropertyTypeUid )
            {
              ++v16;
              ++v18;
              if ( v16 >= m_size )
                goto LABEL_16;
            }
LABEL_25:
            v19 = m_data[v16].m_value.m_data;
            goto LABEL_17;
          }
        }
        else
        {
          if ( !v14 )
            goto LABEL_18;
          v20 = v14->m_properties.m_size;
          v16 = 0i64;
          if ( v20 > 0 )
          {
            m_data = v14->m_properties.m_data;
            v21 = m_data;
            while ( v21->m_key != UFG::physicsObjectPropertyTypeUid )
            {
              ++v16;
              ++v21;
              if ( v16 >= v20 )
                goto LABEL_16;
            }
            goto LABEL_25;
          }
        }
LABEL_16:
        v19 = 0i64;
LABEL_17:
        v3->mPhysicsObjectPropertyHandleUid = v19;
LABEL_18:
        UFG::BasePhysicsSystem::DetermineRaycastSurfaceProperties(this, v3);
      }
    }
  }
  mRaycastBatchExecuteBuffer = this->mRaycastBatchExecuteBuffer;
  this->mRaycastCallbackActive = 0;
  return mRaycastBatchExecuteBuffer->mCount;
}

// File Line: 772
// RVA: 0xA7050
void __fastcall UFG::BasePhysicsSystem::DetermineRaycastSurfaceProperties(
        UFG::BasePhysicsSystem *this,
        UFG::RayCastData *data)
{
  signed int v3; // edi
  unsigned int v4; // ecx
  __int64 v5; // rsi
  __int64 v6; // rax
  __int64 v7; // rcx
  __int64 v8; // r8
  UFG::BaseProperty *BaseProperty; // rax
  UFG::qReflectObject *mData; // rax
  unsigned int v11; // eax
  UFG::qBaseTreeRB *v12; // r8
  UFG::qReflectHandleBase v13; // [rsp+28h] [rbp-30h] BYREF

  v3 = data->mOutput.m_shapeKeys[0];
  v4 = data->mOutput.m_shapeKeys[1];
  if ( v3 != -1 )
  {
    if ( v4 == -1 )
    {
      BaseProperty = UFG::GetBaseProperty(data->mOutput.m_rootCollidable->m_shape, v3);
      if ( BaseProperty )
      {
        data->mPhysicsSurfacePropertyHandleUid = BaseProperty->surfacePropertyHandleId;
        data->mPhysicsObjectPropertyHandleUid = BaseProperty->objectPropertyHandleId;
        data->mCollisionModelName.mUID = BaseProperty->collisionModelName.mUID;
      }
    }
    else
    {
      if ( v4 )
        v3 = data->mOutput.m_shapeKeys[1];
      v5 = *(_QWORD *)(data->mHavokRigidBody->m_userData + 24);
      if ( UFG::SimComponent::IsType((UFG::SimComponent *)v5, UFG::RigidBody::_RigidBodyTypeUID) )
      {
        v6 = *(_QWORD *)(v5 + 160);
        v7 = *(_QWORD *)(v6 + 152);
        if ( v7 )
          v8 = v7 + v6 + 152;
        else
          v8 = 0i64;
        data->mPhysicsObjectPropertyHandleUid = *(_QWORD *)(v8 + 48i64 * v3 + 16);
        data->mCollisionModelName.mUID = *(_DWORD *)(v8 + 48i64 * v3 + 24);
        return;
      }
    }
  }
  if ( !data->mPhysicsSurfacePropertyHandleUid )
  {
    UFG::qReflectHandleBase::qReflectHandleBase(&v13);
    v13.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v13, v13.mTypeUID, data->mPhysicsObjectPropertyHandleUid);
    mData = v13.mData;
    if ( !v13.mData )
    {
      if ( (_S4_2 & 1) != 0 )
      {
        v11 = default_uid_1;
      }
      else
      {
        _S4_2 |= 1u;
        v11 = UFG::qStringHashUpper32("default", 0xFFFFFFFF);
        default_uid_1 = v11;
      }
      if ( v11 )
        v12 = UFG::qBaseTreeRB::Get(&UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree, v11);
      else
        v12 = 0i64;
      UFG::qReflectHandleBase::Init(&v13, v13.mTypeUID, *(_QWORD *)&v12->mNULL.mUID);
      mData = v13.mData;
    }
    data->mPhysicsSurfacePropertyHandleUid = *(_QWORD *)(mData[4].mBaseNode.mUID + 8);
    UFG::qReflectHandleBase::~qReflectHandleBase(&v13);
  }
}

// File Line: 832
// RVA: 0xA7760
void __fastcall UFG::BasePhysicsSystem::DispatchAsyncRayCastResultCallbacks(UFG::BasePhysicsSystem *this)
{
  UFG::BasePhysicsSystem::RaycastBatch *mRaycastBatchExecuteBuffer; // rdx
  unsigned int v2; // ebx

  mRaycastBatchExecuteBuffer = this->mRaycastBatchExecuteBuffer;
  v2 = 0;
  if ( mRaycastBatchExecuteBuffer->mCount )
  {
    do
    {
      mRaycastBatchExecuteBuffer->mAsyncRayData[v2].raycastCallback(
        &mRaycastBatchExecuteBuffer->mAsyncRayData[v2],
        mRaycastBatchExecuteBuffer->mAsyncRayData[v2].simComponent.m_pPointer,
        mRaycastBatchExecuteBuffer->mAsyncRayData[v2].callbackUserData);
      mRaycastBatchExecuteBuffer = this->mRaycastBatchExecuteBuffer;
      ++v2;
    }
    while ( v2 < mRaycastBatchExecuteBuffer->mCount );
    mRaycastBatchExecuteBuffer->mCount = 0;
  }
  else
  {
    mRaycastBatchExecuteBuffer->mCount = 0;
  }
}

// File Line: 845
// RVA: 0xA1630
void __fastcall UFG::BasePhysicsSystem::CancelAllAsyncRayCasts(UFG::BasePhysicsSystem *this)
{
  this->mRaycastBatchSubmitBuffer->mCount = 0;
  this->mRaycastBatchExecuteBuffer->mCount = 0;
}

// File Line: 855
// RVA: 0xA1950
char __fastcall UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem *this, UFG::RayCastData *data)
{
  hkpWorld *mWorld; // rcx
  __m128 m_quad; // xmm3
  bool v6; // al
  float m_hitFraction; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm6_4
  float v12; // xmm5_4
  float v13; // eax
  float v14; // xmm1_4
  hkpCollidable *m_rootCollidable; // rax
  hkpRigidBody *v16; // rdi
  hkpPhantom *v17; // rcx
  unsigned __int64 m_userData; // rdi
  __int64 v19; // rdi

  data->mOutput.m_hitFraction = 1.0;
  data->mOutput.m_extraInfo = -1;
  data->mOutput.m_rootCollidable = 0i64;
  data->mOutput.m_shapeKeyIndex = 0;
  data->mOutput.m_shapeKeys[0] = -1;
  ++UFG::BasePhysicsSystem::mSyncRayCastCount;
  mWorld = this->mWorld;
  if ( !mWorld )
    return 0;
  m_quad = mWorld->m_broadPhaseExtents[1].m_quad;
  if ( (_mm_movemask_ps(
          _mm_and_ps(
            _mm_cmple_ps(mWorld->m_broadPhaseExtents[0].m_quad, data->mInput.m_from.m_quad),
            _mm_cmple_ps(data->mInput.m_from.m_quad, m_quad))) & 7) != 7
    && (_mm_movemask_ps(
          _mm_and_ps(
            _mm_cmple_ps(mWorld->m_broadPhaseExtents[0].m_quad, data->mInput.m_to.m_quad),
            _mm_cmple_ps(data->mInput.m_to.m_quad, m_quad))) & 7) != 7 )
  {
    return 0;
  }
  hkpWorld::castRay(mWorld, &data->mInput, &data->mOutput);
  v6 = data->mOutput.m_rootCollidable != 0i64;
  data->hit = v6;
  if ( !v6 )
    return 0;
  m_hitFraction = data->mOutput.m_hitFraction;
  v8 = data->mInput.m_to.m_quad.m128_f32[0];
  v9 = data->mInput.m_to.m_quad.m128_f32[1];
  v10 = data->mInput.m_to.m_quad.m128_f32[2];
  data->t = m_hitFraction;
  v11 = (float)((float)(v10 - data->mInput.m_from.m_quad.m128_f32[2]) * m_hitFraction)
      + data->mInput.m_from.m_quad.m128_f32[2];
  v12 = (float)((float)(v9 - data->mInput.m_from.m_quad.m128_f32[1]) * m_hitFraction)
      + data->mInput.m_from.m_quad.m128_f32[1];
  data->point.x = (float)((float)(v8 - data->mInput.m_from.m_quad.m128_f32[0]) * m_hitFraction)
                + data->mInput.m_from.m_quad.m128_f32[0];
  data->point.z = v11;
  data->point.y = v12;
  v13 = data->mOutput.m_normal.m_quad.m128_f32[0];
  v14 = data->mOutput.m_normal.m_quad.m128_f32[2];
  LODWORD(data->normal.y) = data->mOutput.m_normal.m_quad.m128_i32[1];
  data->normal.x = v13;
  data->normal.z = v14;
  m_rootCollidable = data->mOutput.m_rootCollidable;
  if ( m_rootCollidable->m_broadPhaseHandle.m_type == 1 )
    v16 = (hkpRigidBody *)((char *)m_rootCollidable + m_rootCollidable->m_ownerOffset);
  else
    v16 = 0i64;
  data->mHavokRigidBody = v16;
  if ( m_rootCollidable->m_broadPhaseHandle.m_type == 2 )
    v17 = (hkpPhantom *)((char *)m_rootCollidable + m_rootCollidable->m_ownerOffset);
  else
    v17 = 0i64;
  data->mHavokPhantom = v17;
  data->mPhysicsObjectPropertyHandleUid = 0i64;
  data->mPhysicsSurfacePropertyHandleUid = 0i64;
  if ( v16 )
  {
    data->mPhysicsObjectPropertyHandleUid = UFG::PhysicsPropertyManager::GetObjectPropertiesHandleUid(v16);
    m_userData = v16->m_userData;
    if ( m_userData )
    {
      v19 = *(_QWORD *)(m_userData + 0x18);
      if ( v19 )
      {
        if ( UFG::SimComponent::IsType((UFG::SimComponent *)v19, UFG::RigidBody::_RigidBodyTypeUID) )
          data->mCollisionModelName.mUID = *(_DWORD *)(*(_QWORD *)(v19 + 0xA0) + 0xD8i64);
      }
    }
  }
  UFG::BasePhysicsSystem::DetermineRaycastSurfaceProperties(this, data);
  return 1;
}

// File Line: 933
// RVA: 0xA1DD0
bool __fastcall UFG::BasePhysicsSystem::CastShape(
        UFG::BasePhysicsSystem *this,
        UFG::ShapeCasterCollector *sc,
        UFG::qVector3 *start,
        UFG::qVector3 *end)
{
  __m128 z_low; // xmm0
  __m128 v5; // xmm2
  hkVector4f enda; // [rsp+30h] [rbp-28h] BYREF
  hkVector4f starta; // [rsp+40h] [rbp-18h] BYREF

  z_low = (__m128)LODWORD(end->z);
  v5 = _mm_unpacklo_ps((__m128)LODWORD(end->y), (__m128)(unsigned int)FLOAT_1_0);
  starta.m_quad = _mm_unpacklo_ps(
                    _mm_unpacklo_ps((__m128)LODWORD(start->x), (__m128)LODWORD(start->z)),
                    _mm_unpacklo_ps((__m128)LODWORD(start->y), (__m128)(unsigned int)FLOAT_1_0));
  enda.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)LODWORD(end->x), z_low), v5);
  return UFG::BasePhysicsSystem::CastShape(this, sc, &starta, &enda);
}

// File Line: 941
// RVA: 0xA1B50
bool __fastcall UFG::BasePhysicsSystem::CastShape(
        UFG::BasePhysicsSystem *this,
        UFG::ShapeCasterCollector *sc,
        hkVector4f *start,
        hkVector4f *end)
{
  UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *p_mHitList; // r12
  hkpWorld *mWorld; // r13
  hkpShapePhantom *mPhantom; // rdx
  int i; // ebx
  _BOOL8 v13; // r8
  bool v14; // bl
  __m128 m_quad; // [rsp+30h] [rbp-A8h] BYREF
  __m128 v16; // [rsp+40h] [rbp-98h] BYREF
  int v17; // [rsp+50h] [rbp-88h]
  int v18; // [rsp+54h] [rbp-84h]
  __m128 v19; // [rsp+58h] [rbp-80h] BYREF
  __int64 v20; // [rsp+68h] [rbp-70h]
  char v21[40]; // [rsp+70h] [rbp-68h] BYREF
  __int64 v22; // [rsp+98h] [rbp-40h]
  hkpAllCdPointCollector v23; // [rsp+A8h] [rbp-30h] BYREF
  hkInplaceArray<hkpRootCdPoint,8,hkContainerHeapAllocator> *p_m_hits; // [rsp+2F8h] [rbp+220h]
  void *retaddr; // [rsp+318h] [rbp+240h]
  char v26; // [rsp+320h] [rbp+248h]

  v22 = -2i64;
  p_mHitList = &sc->mHitList;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&sc->mHitList);
  mWorld = this->mWorld;
  if ( !mWorld )
    return 0;
  mPhantom = sc->mPhantom;
  if ( !mPhantom->m_world )
    hkpWorld::addPhantom(this->mWorld, mPhantom);
  v17 = 872415232;
  v18 = 872415232;
  m_quad = start->m_quad;
  v16 = end->m_quad;
  if ( (_DWORD)retaddr )
  {
    if ( (unsigned int)((_DWORD)retaddr - 1) <= 1 )
    {
      v23.vfptr = (hkpCdPointCollectorVtbl *)&hkpAllCdPointCollector::`vftable;
      p_m_hits = &v23.m_hits;
      v23.m_hits.m_data = v23.m_hits.m_storage;
      v23.m_hits.m_capacityAndFlags = -2147483640;
      v23.m_hits.m_size = 0;
      v23.m_earlyOutDistance = 3.40282e38;
      ((void (__fastcall *)(hkpShapePhantom *, __m128 *, __m128 *, hkpAllCdPointCollector *, hkpAllCdPointCollector *))sc->mPhantom->vfptr[7].__first_virtual_table_function__)(
        sc->mPhantom,
        &m_quad,
        &v16,
        &v23,
        &v23);
      hkpAllCdPointCollector::sortHits(&v23);
      for ( i = 0; i < v23.m_hits.m_size; ++i )
        sc->vfptr->AddHit(sc, &v23.m_hits.m_data[(__int64)i], (_DWORD)retaddr == 1);
      v23.vfptr = (hkpCdPointCollectorVtbl *)&hkpAllCdPointCollector::`vftable;
      p_m_hits = &v23.m_hits;
      v23.m_hits.m_size = 0;
      if ( v23.m_hits.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v23.m_hits.m_data,
          v23.m_hits.m_capacityAndFlags << 6);
      v23.m_hits.m_data = 0i64;
      v23.m_hits.m_capacityAndFlags = 0x80000000;
      v23.vfptr = (hkpCdPointCollectorVtbl *)&hkpCdPointCollector::`vftable;
    }
  }
  else
  {
    v19.m128_u64[1] = (unsigned __int64)&hkpClosestCdPointCollector::`vftable;
    v19 = _mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, (__m128)xmmword_141A712A0), 196);
    v20 = 2139095022i64;
    ((void (__fastcall *)(hkpShapePhantom *, __m128 *, __m128 *, unsigned __int16 *, unsigned __int16 *))sc->mPhantom->vfptr[7].__first_virtual_table_function__)(
      sc->mPhantom,
      &m_quad,
      &v16,
      &v19.m128_u16[4],
      &v19.m128_u16[4]);
    if ( v20 )
    {
      LOBYTE(v13) = 1;
      sc->vfptr->AddHit(sc, (hkpRootCdPoint *)v21, v13);
    }
    v19.m128_u64[1] = (unsigned __int64)&hkpCdPointCollector::`vftable;
  }
  v14 = p_mHitList->mNode.mNext != (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)p_mHitList;
  if ( v26 )
    hkpWorld::removePhantom(mWorld, sc->mPhantom);
  return v14;
}

// File Line: 1093
// RVA: 0xA1840
char __fastcall UFG::BasePhysicsSystem::CastAsyncShape(
        UFG::BasePhysicsSystem *this,
        UFG::AsyncShapeCasterCollector *caster,
        UFG::SimComponent *simComponent,
        void *userData)
{
  unsigned int mCount; // ecx
  hkpWorld *mWorld; // rax
  __m128 m_quad; // xmm3
  __m128 v8; // xmm4
  __m128 v9; // xmm6
  hkVector4f position; // [rsp+20h] [rbp-28h] BYREF

  mCount = this->mShapecastBatch.mCount;
  if ( mCount >= 0x30 )
    return 0;
  mWorld = this->mWorld;
  m_quad = mWorld->m_broadPhaseExtents[0].m_quad;
  v8 = mWorld->m_broadPhaseExtents[1].m_quad;
  v9 = caster->m_to.m_quad;
  position.m_quad = (__m128)caster->m_from;
  if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(position.m_quad, v8), _mm_cmple_ps(m_quad, position.m_quad))) & 7) != 7
    || (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v9, v8), _mm_cmple_ps(m_quad, v9))) & 7) != 7 )
  {
    return 0;
  }
  UFG::AsyncShapeCasterCollector::operator=(&this->mShapecastBatch.mAsyncShapeData[mCount], caster);
  this->mShapecastBatch.mAsyncShapeData[this->mShapecastBatch.mCount].mInput.m_to.m_quad = v9;
  hkpShapePhantom::setPosition(
    this->mShapecastBatch.mAsyncShapeData[this->mShapecastBatch.mCount].mPhantom,
    &position,
    0.0);
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->mShapecastBatch.mAsyncShapeData[this->mShapecastBatch.mCount].mHitList);
  ++this->mShapecastBatch.mCount;
  return 1;
}

// File Line: 1380
// RVA: 0xA0460
void __fastcall UFG::BasePhysicsSystem::AddEntity(UFG::BasePhysicsSystem *this, hkpPhantom *p, bool addBatched)
{
  __int64 v4; // rbx
  char v6; // r9
  char v7; // cl
  hkArray<hkpPhantom *,hkContainerHeapAllocator> *p_mPhantomsToAdd; // rdi
  char v9; // al

  v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v6 = ++*(_BYTE *)(v4 + 80);
  *(_DWORD *)(v4 + 4i64 * v6) = 3;
  *(_QWORD *)(v4 + 8i64 * v6 + 16) = "BasePhysicsSystem::AddEntity";
  *(_QWORD *)(v4 + 8i64 * v6 + 48) = 0i64;
  v7 = *(_BYTE *)(v4 + 81);
  if ( v6 > v7 )
    v7 = v6;
  *(_BYTE *)(v4 + 81) = v7;
  if ( addBatched )
  {
    p_mPhantomsToAdd = &this->mPhantomsToAdd;
    if ( this->mPhantomsToAdd.m_size == (this->mPhantomsToAdd.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->mPhantomsToAdd, 8);
    p_mPhantomsToAdd->m_data[p_mPhantomsToAdd->m_size++] = p;
  }
  else
  {
    hkpWorld::addPhantom(this->mWorld, p);
  }
  v9 = *(_BYTE *)(v4 + 80);
  if ( v9 > 0 )
  {
    *(_BYTE *)(v4 + 80) = v9 - 1;
  }
  else
  {
    *(_BYTE *)(v4 + 80) = 0;
    *(_DWORD *)v4 = 3;
    *(_QWORD *)(v4 + 16) = 0i64;
    *(_QWORD *)(v4 + 48) = 0i64;
  }
}

// File Line: 1423
// RVA: 0xA0560
void __fastcall UFG::BasePhysicsSystem::AddEntity(UFG::BasePhysicsSystem *this, hkpRigidBody *rb, bool addBatched)
{
  hkArray<hkpEntity *,hkContainerHeapAllocator> *p_mEntitiesToAdd; // rbx

  if ( addBatched )
  {
    p_mEntitiesToAdd = &this->mEntitiesToAdd;
    if ( this->mEntitiesToAdd.m_size == (this->mEntitiesToAdd.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_mEntitiesToAdd, 8);
    p_mEntitiesToAdd->m_data[p_mEntitiesToAdd->m_size++] = rb;
  }
  else
  {
    hkpWorld::addEntity(this->mWorld, rb, HK_ENTITY_ACTIVATION_DO_ACTIVATE);
  }
}

// File Line: 1468
// RVA: 0x9FDD0
void __fastcall UFG::BasePhysicsSystem::AddAction(UFG::BasePhysicsSystem *this, hkpAction *action)
{
  __int64 m_size; // rdx
  __int64 v4; // r8
  hkpAction **m_data; // rax
  hkArray<hkpAction *,hkContainerHeapAllocator> *p_mActionsToAdd; // rbx

  m_size = this->mActionsToAdd.m_size;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    if ( !action->m_world )
    {
      p_mActionsToAdd = &this->mActionsToAdd;
      if ( this->mActionsToAdd.m_size == (this->mActionsToAdd.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_mActionsToAdd, 8);
      p_mActionsToAdd->m_data[p_mActionsToAdd->m_size++] = action;
    }
  }
  else
  {
    m_data = this->mActionsToAdd.m_data;
    while ( *m_data != action )
    {
      ++v4;
      ++m_data;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
  }
}

// File Line: 1494
// RVA: 0xA02A0
void __fastcall UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem *this, hkpConstraintInstance *constraint)
{
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *p_mConstraintsToAdd; // rbx

  if ( constraint )
  {
    p_mConstraintsToAdd = &this->mConstraintsToAdd;
    if ( this->mConstraintsToAdd.m_size == (this->mConstraintsToAdd.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_mConstraintsToAdd, 8);
    p_mConstraintsToAdd->m_data[p_mConstraintsToAdd->m_size++] = constraint;
    hkReferencedObject::addReference(constraint);
  }
}

// File Line: 1534
// RVA: 0x9FE50
void __fastcall UFG::BasePhysicsSystem::AddBatchedEntities(UFG::BasePhysicsSystem *this)
{
  __int64 v2; // rdi
  char v3; // dl
  char v4; // cl
  char v5; // al
  int v6; // r14d
  __int64 v7; // rsi
  hkpEntity **m_data; // rdx
  char m_storage; // cl
  char v10; // dl
  char v11; // cl
  _QWORD **Value; // rax
  hkpEasePenetrationAction *v13; // rax
  hkpAction *v14; // rax
  hkpAction *v15; // rbp
  char v16; // al
  int m_size; // r8d
  int v18; // edi
  __int64 v19; // rsi
  int v20; // esi
  __int64 v21; // rdi

  if ( this->mEntitiesToAdd.m_size > 0 )
  {
    v2 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v3 = ++*(_BYTE *)(v2 + 80);
    *(_DWORD *)(v2 + 4i64 * v3) = 3;
    *(_QWORD *)(v2 + 8i64 * v3 + 16) = "addEntityBatch";
    *(_QWORD *)(v2 + 8i64 * v3 + 48) = 0i64;
    v4 = *(_BYTE *)(v2 + 81);
    if ( v3 > v4 )
      v4 = v3;
    *(_BYTE *)(v2 + 81) = v4;
    hkpWorld::addEntityBatch(
      this->mWorld,
      this->mEntitiesToAdd.m_data,
      this->mEntitiesToAdd.m_size,
      HK_ENTITY_ACTIVATION_DO_ACTIVATE);
    v5 = *(_BYTE *)(v2 + 80);
    if ( v5 > 0 )
    {
      *(_BYTE *)(v2 + 80) = v5 - 1;
    }
    else
    {
      *(_BYTE *)(v2 + 80) = 0;
      *(_DWORD *)v2 = 3;
      *(_QWORD *)(v2 + 16) = 0i64;
      *(_QWORD *)(v2 + 48) = 0i64;
    }
    v6 = 0;
    if ( this->mEntitiesToAdd.m_size > 0 )
    {
      v7 = 0i64;
      do
      {
        m_data = this->mEntitiesToAdd.m_data;
        m_storage = m_data[v7]->m_motion.m_type.m_storage;
        if ( m_storage != 5
          && m_storage != 4
          && (unsigned int)(m_data[v7]->m_collidable.m_broadPhaseHandle.m_objectQualityType - 4) <= 1 )
        {
          v10 = ++*(_BYTE *)(v2 + 80);
          *(_DWORD *)(v2 + 4i64 * v10) = 3;
          *(_QWORD *)(v2 + 8i64 * v10 + 16) = "hkpEasePenetrationAction";
          *(_QWORD *)(v2 + 8i64 * v10 + 48) = 0i64;
          v11 = *(_BYTE *)(v2 + 81);
          if ( v10 > v11 )
            v11 = v10;
          *(_BYTE *)(v2 + 81) = v11;
          Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v13 = (hkpEasePenetrationAction *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                              Value[11],
                                              88i64);
          if ( v13 )
          {
            hkpEasePenetrationAction::hkpEasePenetrationAction(v13, this->mEntitiesToAdd.m_data[v7], 2.0);
            v15 = v14;
          }
          else
          {
            v15 = 0i64;
          }
          v16 = *(_BYTE *)(v2 + 80);
          if ( v16 > 0 )
          {
            *(_BYTE *)(v2 + 80) = v16 - 1;
          }
          else
          {
            *(_BYTE *)(v2 + 80) = 0;
            *(_DWORD *)v2 = 3;
            *(_QWORD *)(v2 + 16) = 0i64;
            *(_QWORD *)(v2 + 48) = 0i64;
          }
          hkpWorld::addAction(this->mWorld, v15);
          hkReferencedObject::removeReference(v15);
        }
        ++v6;
        ++v7;
      }
      while ( v6 < this->mEntitiesToAdd.m_size );
    }
    this->mEntitiesToAdd.m_size = 0;
  }
  m_size = this->mPhantomsToAdd.m_size;
  if ( m_size > 0 )
  {
    hkpWorld::addPhantomBatch(this->mWorld, this->mPhantomsToAdd.m_data, m_size);
    this->mPhantomsToAdd.m_size = 0;
  }
  v18 = 0;
  if ( this->mActionsToAdd.m_size > 0 )
  {
    v19 = 0i64;
    do
    {
      hkpWorld::addAction(this->mWorld, this->mActionsToAdd.m_data[v19]);
      ++v18;
      ++v19;
    }
    while ( v18 < this->mActionsToAdd.m_size );
  }
  this->mActionsToAdd.m_size = 0;
  v20 = 0;
  if ( this->mConstraintsToAdd.m_size > 0 )
  {
    v21 = 0i64;
    do
    {
      hkpWorld::addConstraint(this->mWorld, this->mConstraintsToAdd.m_data[v21]);
      hkReferencedObject::removeReference(this->mConstraintsToAdd.m_data[v21]);
      ++v20;
      ++v21;
    }
    while ( v20 < this->mConstraintsToAdd.m_size );
  }
  this->mConstraintsToAdd.m_size = 0;
}1]);
      ++v20;
      ++v21;
    }
    while ( v20 < this->mConstraintsToAdd.m_size );
  }
  this->mConstraintsToAdd.m_size =

// File Line: 1605
// RVA: 0xAF890
void __fastcall UFG::BasePhysicsSystem::RemoveEntity(
        UFG::BasePhysicsSystem *this,
        hkpRigidBody *rb,
        bool removeBatched)
{
  int v3; // r10d
  __int64 m_size; // rcx
  __int64 v7; // r9
  hkpEntity **m_data; // rax
  __int64 v9; // rax
  hkpWorld *m_world; // rcx
  hkArray<hkpEntity *,hkContainerHeapAllocator> *p_mEntitiesToRemove; // rbx
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  v3 = 0;
  m_size = this->mEntitiesToAdd.m_size;
  v7 = 0i64;
  if ( m_size > 0 )
  {
    m_data = this->mEntitiesToAdd.m_data;
    while ( *m_data != rb )
    {
      ++v7;
      ++v3;
      ++m_data;
      if ( v7 >= m_size )
        goto LABEL_8;
    }
    v9 = --this->mEntitiesToAdd.m_size;
    if ( (_DWORD)v9 != v3 )
      this->mEntitiesToAdd.m_data[v3] = this->mEntitiesToAdd.m_data[v9];
  }
LABEL_8:
  m_world = rb->m_world;
  if ( m_world )
  {
    if ( removeBatched || this->mForceRemoveEntitiesToBeBatched )
    {
      p_mEntitiesToRemove = &this->mEntitiesToRemove;
      if ( p_mEntitiesToRemove->m_size == (p_mEntitiesToRemove->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_mEntitiesToRemove, 8);
      p_mEntitiesToRemove->m_data[p_mEntitiesToRemove->m_size++] = rb;
      hkReferencedObject::addReference(rb);
    }
    else
    {
      hkpWorld::removeEntity(m_world, &result, rb);
    }
  }
}

// File Line: 1651
// RVA: 0xAF770
void __fastcall UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem *this, hkpPhantom *p, bool removeBatched)
{
  __int64 v3; // r11
  int v5; // r9d
  __int64 v6; // r10
  __int64 v7; // rax
  __int64 m_size; // rdx
  hkpPhantom **m_data; // rax
  hkArray<hkpPhantom *,hkContainerHeapAllocator> *p_mPhantomsToRemove; // rdi

  v3 = 0i64;
  v5 = 0;
  if ( this->mPhantomsToAdd.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      if ( this->mPhantomsToAdd.m_data[v6] == p )
      {
        v7 = --this->mPhantomsToAdd.m_size;
        if ( (_DWORD)v7 != v5 )
          this->mPhantomsToAdd.m_data[v6] = this->mPhantomsToAdd.m_data[v7];
        --v5;
        --v6;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < this->mPhantomsToAdd.m_size );
  }
  if ( p->m_world )
  {
    if ( removeBatched || this->mForceRemoveEntitiesToBeBatched )
    {
      m_size = this->mPhantomsToRemove.m_size;
      if ( m_size <= 0 )
      {
LABEL_16:
        p_mPhantomsToRemove = &this->mPhantomsToRemove;
        if ( this->mPhantomsToRemove.m_size == (this->mPhantomsToRemove.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_mPhantomsToRemove, 8);
        p_mPhantomsToRemove->m_data[p_mPhantomsToRemove->m_size++] = p;
        hkReferencedObject::addReference(p);
      }
      else
      {
        m_data = this->mPhantomsToRemove.m_data;
        while ( *m_data != p )
        {
          ++v3;
          ++m_data;
          if ( v3 >= m_size )
            goto LABEL_16;
        }
        UFG::qPrintf("ignoring duplicate call to PhysicsSystem::RemoveEntity(hkpPhantom) %x\n", p);
      }
    }
    else
    {
      hkpWorld::removePhantom(p->m_world, p);
    }
  }
}

// File Line: 1703
// RVA: 0xA10F0
void __fastcall UFG::BasePhysicsSystem::BeginRemoveEntityBatch(UFG::BasePhysicsSystem *this)
{
  this->mForceRemoveEntitiesToBeBatched = 1;
}

// File Line: 1710
// RVA: 0xA7E40
void __fastcall UFG::BasePhysicsSystem::EndRemoveEntityBatch(UFG::BasePhysicsSystem *this)
{
  __int64 m_size; // rsi
  __int64 i; // rdi
  __int64 v4; // rsi
  __int64 j; // rdi

  m_size = this->mEntitiesToRemove.m_size;
  this->mForceRemoveEntitiesToBeBatched = 0;
  if ( (_DWORD)m_size )
  {
    hkpWorld::removeEntityBatch(UFG::BasePhysicsSystem::mInstance->mWorld, this->mEntitiesToRemove.m_data, m_size);
    for ( i = 0i64; i < m_size; ++i )
      hkReferencedObject::removeReference(this->mEntitiesToRemove.m_data[i]);
    this->mEntitiesToRemove.m_size = 0;
  }
  v4 = this->mPhantomsToRemove.m_size;
  if ( (_DWORD)v4 )
  {
    hkpWorld::removePhantomBatch(UFG::BasePhysicsSystem::mInstance->mWorld, this->mPhantomsToRemove.m_data, v4);
    for ( j = 0i64; j < v4; ++j )
      hkReferencedObject::removeReference(this->mPhantomsToRemove.m_data[j]);
    this->mPhantomsToRemove.m_size = 0;
  }
}

// File Line: 1774
// RVA: 0xAF5B0
void __fastcall UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem *this, hkpAction *action)
{
  int v2; // eax
  __int64 v4; // r9
  hkpAction **m_data; // r8
  __int64 v6; // rcx
  hkpWorld *m_world; // rcx

  v2 = 0;
  if ( this->mActionsToAdd.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      m_data = this->mActionsToAdd.m_data;
      if ( m_data[v4] == action )
      {
        v6 = --this->mActionsToAdd.m_size;
        if ( (_DWORD)v6 != v2 )
          m_data[v4] = m_data[v6];
        --v2;
        --v4;
      }
      ++v2;
      ++v4;
    }
    while ( v2 < this->mActionsToAdd.m_size );
  }
  m_world = action->m_world;
  if ( m_world )
    hkpWorld::removeAction(m_world, action);
}

// File Line: 1800
// RVA: 0xAF620
char __fastcall UFG::BasePhysicsSystem::RemoveConstraint(
        UFG::BasePhysicsSystem *this,
        hkpConstraintInstance *constraint)
{
  char v2; // r10
  int v4; // eax
  __int64 v5; // r8
  __int64 v6; // rcx
  hkBool result; // [rsp+38h] [rbp+10h] BYREF

  v2 = 0;
  if ( !constraint )
    return v2;
  v4 = 0;
  if ( this->mConstraintsToAdd.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      if ( this->mConstraintsToAdd.m_data[v5] == constraint )
      {
        v6 = --this->mConstraintsToAdd.m_size;
        if ( (_DWORD)v6 != v4 )
          this->mConstraintsToAdd.m_data[v5] = this->mConstraintsToAdd.m_data[v6];
        --v4;
        v2 = 1;
        --v5;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->mConstraintsToAdd.m_size );
  }
  if ( !constraint->m_owner )
    return v2;
  hkpWorld::removeConstraint(this->mWorld, &result, constraint);
  return 1;
}

// File Line: 1842
// RVA: 0xAFE20
bool __fastcall UFG::BasePhysicsSystem::RequestAnotherRigidBody(UFG::BasePhysicsSystem *this)
{
  return UFG::RigidBody::mCount < UFG::BasePhysicsSystem::mParam.maxLoadedBodies;
}


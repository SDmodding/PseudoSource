// File Line: 127
// RVA: 0x14590C0
__int64 dynamic_initializer_for__gPhysicsMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gPhysicsMemoryPool);
  return atexit(dynamic_atexit_destructor_for__gPhysicsMemoryPool__);
}

// File Line: 128
// RVA: 0x14590E0
__int64 dynamic_initializer_for__gPoseMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gPoseMemoryPool);
  return atexit(dynamic_atexit_destructor_for__gPoseMemoryPool__);
}

// File Line: 129
// RVA: 0x1458E60
__int64 dynamic_initializer_for__gAIMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gAIMemoryPool);
  return atexit(dynamic_atexit_destructor_for__gAIMemoryPool__);
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
  UFG::qMemoryPool *v2; // rbx
  UFG::BasePhysicsSystem *v3; // rdi
  signed __int64 v4; // r14
  signed __int64 v5; // rsi
  signed __int64 v6; // rbx
  char v7; // dl
  __int64 v8; // rax
  char v9; // cl
  int v10; // eax
  int v11; // eax
  int v12; // er9
  __int64 v13; // rax
  signed __int64 v14; // r9
  int v15; // edx
  __int64 v16; // r8
  signed __int64 v17; // rcx
  _QWORD **v18; // rax
  hkpCollisionQueryJobHeader *v19; // rax
  char v20; // al
  char v21; // dl
  __int64 v22; // rax
  char v23; // cl
  int v24; // eax
  int v25; // eax
  int v26; // er9
  int v27; // ecx
  signed __int64 v28; // r8
  int v29; // eax
  __int64 v30; // r9
  _QWORD **v31; // rax
  hkpCollisionQueryJobHeader *v32; // rax
  char v33; // al
  UFG::qTreeRB<UFG::CollisionMeshData,UFG::CollisionMeshData,1> *result; // [rsp+88h] [rbp+10h]
  hkpWorldLinearCastCommand *v35; // [rsp+90h] [rbp+18h]
  __int64 v36; // [rsp+98h] [rbp+20h]

  v2 = memPool;
  v3 = this;
  this->vfptr = (UFG::BasePhysicsSystemVtbl *)&UFG::BasePhysicsSystem::`vftable;
  result = &this->mCollisionModels;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mCollisionModels.mTree);
  UFG::ActiveRegionManager::ActiveRegionManager(&v3->mActiveRegionManager);
  v3->mEntitiesToAdd.m_data = 0i64;
  v3->mEntitiesToAdd.m_size = 0;
  v3->mEntitiesToAdd.m_capacityAndFlags = 2147483648;
  v3->mEntitiesToRemove.m_data = 0i64;
  v3->mEntitiesToRemove.m_size = 0;
  v3->mEntitiesToRemove.m_capacityAndFlags = 2147483648;
  v3->mPhantomsToAdd.m_data = 0i64;
  v3->mPhantomsToAdd.m_size = 0;
  v3->mPhantomsToAdd.m_capacityAndFlags = 2147483648;
  v3->mPhantomsToRemove.m_data = 0i64;
  v3->mPhantomsToRemove.m_size = 0;
  v3->mPhantomsToRemove.m_capacityAndFlags = 2147483648;
  v3->mActionsToAdd.m_data = 0i64;
  v3->mActionsToAdd.m_size = 0;
  v3->mActionsToAdd.m_capacityAndFlags = 2147483648;
  v3->mConstraintsToAdd.m_data = 0i64;
  v3->mConstraintsToAdd.m_size = 0;
  v3->mConstraintsToAdd.m_capacityAndFlags = 2147483648;
  v3->mWorld = 0i64;
  v3->mBroadPhaseBorder = 0i64;
  v3->mThreadPool = 0i64;
  v3->mJobQueue = 0i64;
  v4 = (signed __int64)&v3->mRayCastCommands;
  *(_QWORD *)v4 = 0i64;
  *(_DWORD *)(v4 + 8) = 0;
  *(_DWORD *)(v4 + 12) = 2147483648;
  v3->mRayCastSemaphore = 0i64;
  `eh vector constructor iterator(
    v3->mRaycastBatches,
    0xAE50ui64,
    2,
    (void (__fastcall *)(void *))UFG::BasePhysicsSystem::RaycastBatch::RaycastBatch);
  v5 = (signed __int64)&v3->mShapeCastCommands;
  *(_QWORD *)v5 = 0i64;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 2147483648;
  v3->mShapeCastSemaphore = 0i64;
  result = (UFG::qTreeRB<UFG::CollisionMeshData,UFG::CollisionMeshData,1> *)&v3->mShapecastBatch;
  `eh vector constructor iterator(
    &v3->mShapecastBatch,
    0xD0ui64,
    48,
    (void (__fastcall *)(void *))UFG::AsyncShapeCasterCollector::AsyncShapeCasterCollector);
  v3->mCollisionFilter = 0i64;
  v3->mFrameNumber = 0;
  *(_WORD *)&v3->mBuildingAiData = 0;
  v3->mRaycastCallbackActive = 0;
  UFG::BasePhysicsSystem::mMemoryPool = v2;
  UFG::BasePhysicsSystem::InitWorld(v3);
  v6 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v7 = ++*(_BYTE *)(v6 + 80);
  v8 = v7;
  *(_DWORD *)(v6 + 4 * v8) = 3;
  *(_QWORD *)(v6 + 8 * v8 + 16) = "AsyncRayCast";
  *(_QWORD *)(v6 + 8 * v8 + 48) = 0i64;
  v9 = *(_BYTE *)(v6 + 81);
  if ( v7 > v9 )
    v9 = v7;
  *(_BYTE *)(v6 + 81) = v9;
  if ( (v3->mRayCastCommands.m_capacityAndFlags & 0x3FFFFFFF) < 164 )
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v3->mRayCastCommands,
      164,
      80);
  v10 = v3->mRayCastCommands.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < 164 )
  {
    v11 = 2 * v10;
    v12 = 164;
    if ( v11 > 164 )
      v12 = v11;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v3->mRayCastCommands,
      v12,
      80);
  }
  v13 = v3->mRayCastCommands.m_size;
  v14 = *(_QWORD *)v4 + 80 * v13;
  v35 = (hkpWorldLinearCastCommand *)(*(_QWORD *)v4 + 80 * v13);
  v15 = 0;
  LODWORD(result) = 0;
  v16 = 164 - (signed int)v13;
  if ( 164 - (signed int)v13 > 0 )
  {
    v17 = v14 + 36;
    do
    {
      v36 = v17 - 36;
      if ( v17 != 36 )
      {
        *(_BYTE *)(v17 - 4) = 0;
        *(_DWORD *)v17 = 0;
        *(_QWORD *)(v17 + 4) = 0i64;
        *(_WORD *)(v17 + 28) = 0;
      }
      LODWORD(result) = ++v15;
      v17 += 80i64;
      --v16;
    }
    while ( v16 );
  }
  v3->mRayCastCommands.m_size = 164;
  v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v19 = (hkpCollisionQueryJobHeader *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v18[11] + 8i64))(
                                        v18[11],
                                        16i64);
  if ( v19 )
  {
    *(_QWORD *)&v19->m_openJobs = 0i64;
    *((_QWORD *)&v19->m_openJobs + 1) = 0i64;
  }
  else
  {
    v19 = 0i64;
  }
  v3->mRayCastJobHeader = v19;
  v20 = *(_BYTE *)(v6 + 80);
  if ( v20 > 0 )
  {
    *(_BYTE *)(v6 + 80) = v20 - 1;
  }
  else
  {
    *(_BYTE *)(v6 + 80) = 0;
    *(_DWORD *)v6 = 3;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 48) = 0i64;
  }
  v3->mRaycastBatchSubmitBuffer = v3->mRaycastBatches;
  v3->mRaycastBatchExecuteBuffer = &v3->mRaycastBatches[1];
  v3->mRaycastBatches[0].mCount = 0;
  v3->mRaycastBatchExecuteBuffer->mCount = 0;
  v21 = ++*(_BYTE *)(v6 + 80);
  v22 = v21;
  *(_DWORD *)(v6 + 4 * v22) = 3;
  *(_QWORD *)(v6 + 8 * v22 + 16) = "AsyncShapeCast";
  *(_QWORD *)(v6 + 8 * v22 + 48) = 0i64;
  v23 = *(_BYTE *)(v6 + 81);
  if ( v21 > v23 )
    v23 = v21;
  *(_BYTE *)(v6 + 81) = v23;
  if ( (v3->mShapeCastCommands.m_capacityAndFlags & 0x3FFFFFFF) < 48 )
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v3->mShapeCastCommands,
      48,
      64);
  v24 = v3->mShapeCastCommands.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v24 < 48 )
  {
    v25 = 2 * v24;
    v26 = 48;
    if ( v25 > 48 )
      v26 = v25;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v3->mShapeCastCommands,
      v26,
      64);
  }
  v27 = 48 - v3->mShapeCastCommands.m_size;
  v28 = (signed __int64)&v3->mShapeCastCommands.m_data[(signed __int64)v3->mShapeCastCommands.m_size];
  v35 = &v3->mShapeCastCommands.m_data[(signed __int64)v3->mShapeCastCommands.m_size];
  v29 = 0;
  LODWORD(result) = 0;
  v30 = v27;
  if ( v27 > 0 )
  {
    do
    {
      v36 = v28;
      if ( v28 )
      {
        *(_DWORD *)(v28 + 16) = 872415232;
        *(_DWORD *)(v28 + 20) = 872415232;
      }
      LODWORD(result) = ++v29;
      v28 += 64i64;
      --v30;
    }
    while ( v30 );
  }
  v3->mShapeCastCommands.m_size = 48;
  v31 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v32 = (hkpCollisionQueryJobHeader *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v31[11] + 8i64))(
                                        v31[11],
                                        16i64);
  if ( v32 )
  {
    *(_QWORD *)&v32->m_openJobs = 0i64;
    *((_QWORD *)&v32->m_openJobs + 1) = 0i64;
  }
  else
  {
    v32 = 0i64;
  }
  v3->mShapeCastJobHeader = v32;
  v3->mShapecastBatch.mCount = 0;
  v33 = *(_BYTE *)(v6 + 80);
  if ( v33 > 0 )
  {
    *(_BYTE *)(v6 + 80) = v33 - 1;
  }
  else
  {
    *(_BYTE *)(v6 + 80) = 0;
    *(_DWORD *)v6 = 3;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 48) = 0i64;
  }
  UFG::PhysicsVolumePropertyManager::Initialize();
  UFG::CollisionEvent::Initialize();
}

// File Line: 203
// RVA: 0x9B560
void __fastcall UFG::BasePhysicsSystem::~BasePhysicsSystem(UFG::BasePhysicsSystem *this)
{
  UFG::BasePhysicsSystem *v1; // rdi
  UFG::ThreadSafeQueue<UFG::CollisionEvent> *v2; // rbx
  Render::SkinningCacheNode *v3; // rbx
  int v4; // er8
  int v5; // er8
  int v6; // er8
  int v7; // er8
  hkSemaphore *v8; // rbx
  _QWORD **v9; // rax
  hkpCollisionQueryJobHeader *v10; // rbx
  _QWORD **v11; // rax
  int v12; // eax
  hkSemaphore *v13; // rbx
  _QWORD **v14; // rax
  hkpCollisionQueryJobHeader *v15; // rbx
  _QWORD **v16; // rax
  int v17; // er8
  int v18; // er8
  int v19; // eax
  int v20; // er8
  int v21; // er8
  int v22; // er8
  int v23; // er8
  int v24; // er8
  int v25; // er8

  v1 = this;
  this->vfptr = (UFG::BasePhysicsSystemVtbl *)&UFG::BasePhysicsSystem::`vftable;
  if ( UFG::Destruction::mInstance )
  {
    UFG::Destruction::mInstance->vfptr->__vecDelDtor((hkpBreakOffPartsListener *)UFG::Destruction::mInstance, 1u);
    UFG::Destruction::mInstance = 0i64;
  }
  hkpWorld::removeContactListener(v1->mWorld, (hkpContactListener *)&UFG::WorldCollisionListener::mInstance->vfptr);
  if ( UFG::WorldCollisionListener::mInstance )
    ((void (__fastcall *)(UFG::WorldCollisionListener *, signed __int64))UFG::WorldCollisionListener::mInstance->vfptr->~hkpContactListener)(
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
    v3 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::PhysicsVolumePropertyManager::mGuidTranslation);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::PhysicsVolumePropertyManager::mGuidTranslation,
      &v3->mNode);
    operator delete[](v3);
  }
  UFG::BasePhysicsSystem::CloseWorld(v1);
  v1->mEntitiesToAdd.m_size = 0;
  v4 = v1->mEntitiesToAdd.m_capacityAndFlags;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mEntitiesToAdd.m_data,
      8 * v4);
  v1->mEntitiesToAdd.m_data = 0i64;
  v1->mEntitiesToAdd.m_capacityAndFlags = 2147483648;
  v1->mPhantomsToAdd.m_size = 0;
  v5 = v1->mPhantomsToAdd.m_capacityAndFlags;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mPhantomsToAdd.m_data,
      8 * v5);
  v1->mPhantomsToAdd.m_data = 0i64;
  v1->mPhantomsToAdd.m_capacityAndFlags = 2147483648;
  v1->mActionsToAdd.m_size = 0;
  v6 = v1->mActionsToAdd.m_capacityAndFlags;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mActionsToAdd.m_data,
      8 * v6);
  v1->mActionsToAdd.m_data = 0i64;
  v1->mActionsToAdd.m_capacityAndFlags = 2147483648;
  v1->mConstraintsToAdd.m_size = 0;
  v7 = v1->mConstraintsToAdd.m_capacityAndFlags;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mConstraintsToAdd.m_data,
      8 * v7);
  v1->mConstraintsToAdd.m_data = 0i64;
  v1->mConstraintsToAdd.m_capacityAndFlags = 2147483648;
  v8 = v1->mRayCastSemaphore;
  if ( v8 )
  {
    hkSemaphore::~hkSemaphore(v1->mRayCastSemaphore);
    v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkSemaphore *, signed __int64))(*v9[11] + 16i64))(v9[11], v8, 8i64);
  }
  v10 = v1->mRayCastJobHeader;
  if ( v10 )
  {
    v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpCollisionQueryJobHeader *, signed __int64))(*v11[11] + 16i64))(
      v11[11],
      v10,
      16i64);
  }
  v1->mRayCastCommands.m_size = 0;
  v12 = v1->mRayCastCommands.m_capacityAndFlags;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mRayCastCommands.m_data,
      80 * (v12 & 0x3FFFFFFF));
  v1->mRayCastCommands.m_data = 0i64;
  v1->mRayCastCommands.m_capacityAndFlags = 2147483648;
  v13 = v1->mShapeCastSemaphore;
  if ( v13 )
  {
    hkSemaphore::~hkSemaphore(v1->mShapeCastSemaphore);
    v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkSemaphore *, signed __int64))(*v14[11] + 16i64))(v14[11], v13, 8i64);
  }
  v15 = v1->mShapeCastJobHeader;
  if ( v15 )
  {
    v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpCollisionQueryJobHeader *, signed __int64))(*v16[11] + 16i64))(
      v16[11],
      v15,
      16i64);
  }
  v1->mShapeCastCommands.m_size = 0;
  v17 = v1->mShapeCastCommands.m_capacityAndFlags;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mShapeCastCommands.m_data,
      v17 << 6);
  v1->mShapeCastCommands.m_data = 0i64;
  v1->mShapeCastCommands.m_capacityAndFlags = 2147483648;
  `eh vector destructor iterator(
    &v1->mShapecastBatch,
    0xD0ui64,
    48,
    (void (__fastcall *)(void *))UFG::AsyncShapeCasterCollector::~AsyncShapeCasterCollector);
  v1->mShapeCastCommands.m_size = 0;
  v18 = v1->mShapeCastCommands.m_capacityAndFlags;
  if ( v18 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mShapeCastCommands.m_data,
      v18 << 6);
  v1->mShapeCastCommands.m_data = 0i64;
  v1->mShapeCastCommands.m_capacityAndFlags = 2147483648;
  `eh vector destructor iterator(
    v1->mRaycastBatches,
    0xAE50ui64,
    2,
    (void (__fastcall *)(void *))UFG::BasePhysicsSystem::RaycastBatch::~RaycastBatch);
  v1->mRayCastCommands.m_size = 0;
  v19 = v1->mRayCastCommands.m_capacityAndFlags;
  if ( v19 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mRayCastCommands.m_data,
      80 * (v19 & 0x3FFFFFFF));
  v1->mRayCastCommands.m_data = 0i64;
  v1->mRayCastCommands.m_capacityAndFlags = 2147483648;
  v1->mConstraintsToAdd.m_size = 0;
  v20 = v1->mConstraintsToAdd.m_capacityAndFlags;
  if ( v20 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mConstraintsToAdd.m_data,
      8 * v20);
  v1->mConstraintsToAdd.m_data = 0i64;
  v1->mConstraintsToAdd.m_capacityAndFlags = 2147483648;
  v1->mActionsToAdd.m_size = 0;
  v21 = v1->mActionsToAdd.m_capacityAndFlags;
  if ( v21 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mActionsToAdd.m_data,
      8 * v21);
  v1->mActionsToAdd.m_data = 0i64;
  v1->mActionsToAdd.m_capacityAndFlags = 2147483648;
  v1->mPhantomsToRemove.m_size = 0;
  v22 = v1->mPhantomsToRemove.m_capacityAndFlags;
  if ( v22 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mPhantomsToRemove.m_data,
      8 * v22);
  v1->mPhantomsToRemove.m_data = 0i64;
  v1->mPhantomsToRemove.m_capacityAndFlags = 2147483648;
  v1->mPhantomsToAdd.m_size = 0;
  v23 = v1->mPhantomsToAdd.m_capacityAndFlags;
  if ( v23 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mPhantomsToAdd.m_data,
      8 * v23);
  v1->mPhantomsToAdd.m_data = 0i64;
  v1->mPhantomsToAdd.m_capacityAndFlags = 2147483648;
  v1->mEntitiesToRemove.m_size = 0;
  v24 = v1->mEntitiesToRemove.m_capacityAndFlags;
  if ( v24 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mEntitiesToRemove.m_data,
      8 * v24);
  v1->mEntitiesToRemove.m_data = 0i64;
  v1->mEntitiesToRemove.m_capacityAndFlags = 2147483648;
  v1->mEntitiesToAdd.m_size = 0;
  v25 = v1->mEntitiesToAdd.m_capacityAndFlags;
  if ( v25 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mEntitiesToAdd.m_data,
      8 * v25);
  v1->mEntitiesToAdd.m_data = 0i64;
  v1->mEntitiesToAdd.m_capacityAndFlags = 2147483648;
  UFG::ActiveRegionManager::~ActiveRegionManager(&v1->mActiveRegionManager);
  UFG::qTreeRB<UFG::CollisionMeshData,UFG::CollisionMeshData,1>::DeleteAll(&v1->mCollisionModels);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->mCollisionModels);
}

// File Line: 233
// RVA: 0xAC140
void UFG::BasePhysicsSystem::InitMemory(void)
{
  hkMemorySystem *v0; // rax
  hkMemorySystem *v1; // rbx
  hkMemorySystem::FrameInfo v2; // [rsp+40h] [rbp+8h]
  CustomHavokMemorySystem *result; // [rsp+48h] [rbp+10h]

  if ( !(_S7_1 & 1) )
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
  UFG::BasePhysicsSystem::mMemoryRouter = (hkMemoryRouter *)(*(__int64 (__fastcall **)(hkMemorySystem *, hkMemorySystem::FrameInfo *, signed __int64))v1->vfptr->gap8)(
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
  UFG::BasePhysicsSystem *v1; // rdi
  char v2; // al
  signed __int64 v3; // rbx
  char v4; // dl
  __int64 v5; // rax
  char v6; // cl
  _QWORD **v7; // rax
  hkpWorld *v8; // rax
  hkpWorld *v9; // rax
  char v10; // al
  char v11; // dl
  __int64 v12; // rax
  char v13; // cl
  _QWORD **v14; // rax
  hkpBroadPhaseBorder *v15; // rax
  UFG::BroadPhaseHandler *v16; // rsi
  char v17; // al
  char v18; // dl
  __int64 v19; // rax
  char v20; // cl
  _QWORD **v21; // rax
  UFG::CustomCollisionFilter *v22; // rax
  UFG::CustomCollisionFilter *v23; // rax
  char v24; // al
  __int64 v25; // r14
  char v26; // dl
  __int64 v27; // rax
  char v28; // cl
  _QWORD **v29; // rax
  hkCpuJobThreadPool *v30; // rax
  hkJobThreadPool *v31; // rax
  char v32; // al
  hkThread *v33; // rsi
  void *v34; // rax
  char v35; // dl
  __int64 v36; // rax
  char v37; // cl
  _QWORD **v38; // rax
  hkJobQueue *v39; // rax
  hkJobQueue *v40; // rax
  _QWORD **v41; // rax
  hkExternalJobProfiler *v42; // rax
  char v43; // al
  hkMonitorStream *v44; // rax
  char v45; // dl
  __int64 v46; // rax
  char v47; // cl
  _QWORD **v48; // rax
  hkSemaphore *v49; // rax
  hkSemaphore *v50; // rax
  _QWORD **v51; // rax
  hkSemaphore *v52; // rax
  hkSemaphore *v53; // rax
  char v54; // al
  hkCpuJobThreadPoolCinfo ci; // [rsp+30h] [rbp-A8h]
  hkJobQueueHwSetup v56; // [rsp+60h] [rbp-78h]
  __int64 v57; // [rsp+90h] [rbp-48h]
  hkVector4f v58; // [rsp+98h] [rbp-40h]
  hkVector4f v59; // [rsp+A8h] [rbp-30h]
  float v60; // [rsp+B8h] [rbp-20h]
  hkReferencedObject *v61; // [rsp+C0h] [rbp-18h]
  hkReferencedObject *v62; // [rsp+C8h] [rbp-10h]
  float v63; // [rsp+D8h] [rbp+0h]
  hkReferencedObject *v64; // [rsp+E0h] [rbp+8h]
  char v65; // [rsp+155h] [rbp+7Dh]
  void *v66; // [rsp+198h] [rbp+C0h]

  *(_QWORD *)&v56.m_cellRules = -2i64;
  v1 = this;
  hkpWorldCinfo::hkpWorldCinfo((hkpWorldCinfo *)&v57);
  v60 = FLOAT_0_1;
  v63 = FLOAT_0_016666668;
  *(__m128 *)&v56.m_threadIdsSharingCaches.m_size = _mm_unpacklo_ps(
                                                      _mm_unpacklo_ps(
                                                        (__m128)0i64,
                                                        (__m128)LODWORD(UFG::BasePhysicsSystem::mParam.gravity)),
                                                      (__m128)0i64);
  v2 = v65;
  if ( UFG::BasePhysicsSystem::mParam.numThreads > 1 )
    v2 = 3;
  v65 = v2;
  v58.m_quad = (__m128)UFG::BasePhysicsSystem::mParam.broadPhaseMin;
  v59.m_quad = (__m128)UFG::BasePhysicsSystem::mParam.broadPhaseMax;
  LOBYTE(v57) = 1;
  hkpWorldCinfo::setupSolverInfo((hkpWorldCinfo *)&v56.m_spuSchedulePolicy, SOLVER_TYPE_4ITERS_MEDIUM);
  v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v4 = ++*(_BYTE *)(v3 + 80);
  v5 = v4;
  *(_DWORD *)(v3 + 4 * v5) = 3;
  *(_QWORD *)(v3 + 8 * v5 + 16) = "hkpWorld";
  *(_QWORD *)(v3 + 8 * v5 + 48) = 0i64;
  v6 = *(_BYTE *)(v3 + 81);
  if ( v4 > v6 )
    v6 = v4;
  *(_BYTE *)(v3 + 81) = v6;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkpWorld *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 1088i64);
  v66 = v8;
  if ( v8 )
    hkpWorld::hkpWorld(v8, (hkpWorldCinfo *)&v56.m_spuSchedulePolicy, 0x1332998u);
  else
    v9 = 0i64;
  v1->mWorld = v9;
  v10 = *(_BYTE *)(v3 + 80);
  if ( v10 > 0 )
  {
    *(_BYTE *)(v3 + 80) = v10 - 1;
  }
  else
  {
    *(_BYTE *)(v3 + 80) = 0;
    *(_DWORD *)v3 = 3;
    *(_QWORD *)(v3 + 16) = 0i64;
    *(_QWORD *)(v3 + 48) = 0i64;
  }
  hkpWorld::lock(v1->mWorld);
  v11 = ++*(_BYTE *)(v3 + 80);
  v12 = v11;
  *(_DWORD *)(v3 + 4 * v12) = 3;
  *(_QWORD *)(v3 + 8 * v12 + 16) = "BroadPhaseHandler";
  *(_QWORD *)(v3 + 8 * v12 + 48) = 0i64;
  v13 = *(_BYTE *)(v3 + 81);
  if ( v11 > v13 )
    v13 = v11;
  *(_BYTE *)(v3 + 81) = v13;
  v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (hkpBroadPhaseBorder *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(v14[11], 128i64);
  v16 = (UFG::BroadPhaseHandler *)v15;
  v66 = v15;
  if ( v15 )
  {
    hkpBroadPhaseBorder::hkpBroadPhaseBorder(v15, v1->mWorld, BROADPHASE_BORDER_DO_NOTHING, 0);
    v16->vfptr = (hkBaseObjectVtbl *)&UFG::BroadPhaseHandler::`vftable{for `hkReferencedObject};
    v16->vfptr = (hkpWorldDeletionListenerVtbl *)&UFG::BroadPhaseHandler::`vftable{for `hkpWorldDeletionListener};
    v16->vfptr = (hkpPhantomOverlapListenerVtbl *)&UFG::BroadPhaseHandler::`vftable{for `hkpPhantomOverlapListener};
    v16->vfptr = (hkpWorldPostSimulationListenerVtbl *)&UFG::BroadPhaseHandler::`vftable{for `hkpWorldPostSimulationListener};
    v16->mCallback = 0i64;
  }
  else
  {
    v16 = 0i64;
  }
  v1->mBroadPhaseBorder = v16;
  v17 = *(_BYTE *)(v3 + 80);
  if ( v17 > 0 )
  {
    *(_BYTE *)(v3 + 80) = v17 - 1;
  }
  else
  {
    *(_BYTE *)(v3 + 80) = 0;
    *(_DWORD *)v3 = 3;
    *(_QWORD *)(v3 + 16) = 0i64;
    *(_QWORD *)(v3 + 48) = 0i64;
  }
  hkpWorld::setBroadPhaseBorder(v1->mWorld, (hkpBroadPhaseBorder *)&v1->mBroadPhaseBorder->vfptr);
  hkReferencedObject::removeReference((hkReferencedObject *)&v1->mBroadPhaseBorder->vfptr);
  UFG::BasePhysicsSystem::RegisterAgents(v1);
  v18 = ++*(_BYTE *)(v3 + 80);
  v19 = v18;
  *(_DWORD *)(v3 + 4 * v19) = 3;
  *(_QWORD *)(v3 + 8 * v19 + 16) = "CustomCollisionFilter";
  *(_QWORD *)(v3 + 8 * v19 + 48) = 0i64;
  v20 = *(_BYTE *)(v3 + 81);
  if ( v18 > v20 )
    v20 = v18;
  *(_BYTE *)(v3 + 81) = v20;
  v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = (UFG::CustomCollisionFilter *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v21[11] + 8i64))(
                                        v21[11],
                                        304i64);
  v66 = v22;
  if ( v22 )
    UFG::CustomCollisionFilter::CustomCollisionFilter(v22);
  else
    v23 = 0i64;
  v1->mCollisionFilter = v23;
  v24 = *(_BYTE *)(v3 + 80);
  if ( v24 > 0 )
  {
    *(_BYTE *)(v3 + 80) = v24 - 1;
  }
  else
  {
    *(_BYTE *)(v3 + 80) = 0;
    *(_DWORD *)v3 = 3;
    *(_QWORD *)(v3 + 16) = 0i64;
    *(_QWORD *)(v3 + 48) = 0i64;
  }
  hkpWorld::setCollisionFilter(
    v1->mWorld,
    (hkpCollisionFilter *)&v1->mCollisionFilter->vfptr,
    (hkBool)1,
    0,
    HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
  UFG::WorldCollisionListener::Initialize(v1->mWorld);
  if ( UFG::BasePhysicsSystem::mParam.numThreads > 1 )
  {
    v25 = (unsigned int)(UFG::BasePhysicsSystem::mParam.numThreads - 1);
    hkCpuJobThreadPoolCinfo::hkCpuJobThreadPoolCinfo(&ci);
    ci.m_numThreads = v25;
    *(_QWORD *)&ci.m_stackSize = 98304i64;
    v26 = ++*(_BYTE *)(v3 + 80);
    v27 = v26;
    *(_DWORD *)(v3 + 4 * v27) = 3;
    *(_QWORD *)(v3 + 8 * v27 + 16) = "hkCpuJobThreadPool";
    *(_QWORD *)(v3 + 8 * v27 + 48) = 0i64;
    v28 = *(_BYTE *)(v3 + 81);
    if ( v26 > v28 )
      v28 = v26;
    *(_BYTE *)(v3 + 81) = v28;
    v29 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v30 = (hkCpuJobThreadPool *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v29[11] + 8i64))(v29[11], 960i64);
    v66 = v30;
    if ( v30 )
      hkCpuJobThreadPool::hkCpuJobThreadPool(v30, &ci);
    else
      v31 = 0i64;
    v1->mThreadPool = v31;
    v32 = *(_BYTE *)(v3 + 80);
    if ( v32 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v32 - 1;
    }
    else
    {
      *(_BYTE *)(v3 + 80) = 0;
      *(_DWORD *)v3 = 3;
      *(_QWORD *)(v3 + 16) = 0i64;
      *(_QWORD *)(v3 + 48) = 0i64;
    }
    if ( (signed int)v25 > 0 )
    {
      v33 = (hkThread *)&v1->mThreadPool[2].m_memSizeAndFlags;
      do
      {
        v34 = hkThread::getHandle(v33);
        SetThreadPriority(v34, 2);
        v33 = (hkThread *)((char *)v33 + 72);
        --v25;
      }
      while ( v25 );
    }
    hkJobQueueHwSetup::hkJobQueueHwSetup(&v56);
    LODWORD(ci.m_threadName) = 20;
    v56.m_numCpuThreads = UFG::BasePhysicsSystem::mParam.numThreads;
    v35 = ++*(_BYTE *)(v3 + 80);
    v36 = v35;
    *(_DWORD *)(v3 + 4 * v36) = 3;
    *(_QWORD *)(v3 + 8 * v36 + 16) = "hkJobQueue";
    *(_QWORD *)(v3 + 8 * v36 + 48) = 0i64;
    v37 = *(_BYTE *)(v3 + 81);
    if ( v35 > v37 )
      v37 = v35;
    *(_BYTE *)(v3 + 81) = v37;
    v38 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v39 = (hkJobQueue *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v38[11] + 8i64))(v38[11], 1024i64);
    v66 = v39;
    if ( v39 )
      hkJobQueue::hkJobQueue(v39, (hkJobQueueCinfo *)&v56);
    else
      v40 = 0i64;
    v1->mJobQueue = v40;
    v41 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v42 = (hkExternalJobProfiler *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v41[11] + 8i64))(
                                     v41[11],
                                     8i64);
    v66 = v42;
    if ( v42 )
    {
      v42->vfptr = (hkExternalJobProfilerVtbl *)&hkExternalJobProfiler::`vftable;
      v42->vfptr = (hkExternalJobProfilerVtbl *)&HavokJobMemoryPoolTagger::`vftable;
    }
    else
    {
      v42 = 0i64;
    }
    v1->mMemoryPoolTagger = (HavokJobMemoryPoolTagger *)v42;
    hkJobQueue::setExternalProfiler(v1->mJobQueue, v42);
    v43 = *(_BYTE *)(v3 + 80);
    if ( v43 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v43 - 1;
    }
    else
    {
      *(_BYTE *)(v3 + 80) = 0;
      *(_DWORD *)v3 = 3;
      *(_QWORD *)(v3 + 16) = 0i64;
      *(_QWORD *)(v3 + 48) = 0i64;
    }
    v44 = (hkMonitorStream *)TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    hkMonitorStream::resize(v44, 0);
    hkpWorld::registerWithJobQueue(v1->mJobQueue);
    v45 = ++*(_BYTE *)(v3 + 80);
    v46 = v45;
    *(_DWORD *)(v3 + 4 * v46) = 3;
    *(_QWORD *)(v3 + 8 * v46 + 16) = "hkSemaphoreBusyWait";
    *(_QWORD *)(v3 + 8 * v46 + 48) = 0i64;
    v47 = *(_BYTE *)(v3 + 81);
    if ( v45 > v47 )
      v47 = v45;
    *(_BYTE *)(v3 + 81) = v47;
    v48 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v49 = (hkSemaphore *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v48[11] + 8i64))(v48[11], 8i64);
    v66 = v49;
    if ( v49 )
      hkSemaphore::hkSemaphore(v49, 0, 1000, 0);
    else
      v50 = 0i64;
    v1->mRayCastSemaphore = v50;
    hkpRayCastQueryJobQueueUtils::registerWithJobQueue(v1->mJobQueue);
    v51 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v52 = (hkSemaphore *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v51[11] + 8i64))(v51[11], 8i64);
    v66 = v52;
    if ( v52 )
      hkSemaphore::hkSemaphore(v52, 0, 1000, 0);
    else
      v53 = 0i64;
    v1->mShapeCastSemaphore = v53;
    hkpCollisionQueryJobQueueUtils::registerWithJobQueue(v1->mJobQueue);
    v54 = *(_BYTE *)(v3 + 80);
    if ( v54 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v54 - 1;
    }
    else
    {
      *(_BYTE *)(v3 + 80) = 0;
      *(_DWORD *)v3 = 3;
      *(_QWORD *)(v3 + 16) = 0i64;
      *(_QWORD *)(v3 + 48) = 0i64;
    }
    hkpFixedBufferCdPointCollector::registerDefaultAddCdPointFunction();
    hkJobQueueHwSetup::~hkJobQueueHwSetup(&v56);
    ci.m_hardwareThreadIds.m_size = 0;
    if ( ci.m_hardwareThreadIds.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        ci.m_hardwareThreadIds.m_data,
        4 * ci.m_hardwareThreadIds.m_capacityAndFlags);
    ci.m_hardwareThreadIds.m_data = 0i64;
    ci.m_hardwareThreadIds.m_capacityAndFlags = 2147483648;
  }
  hkpWorld::unlock(v1->mWorld);
  *(_QWORD *)&v56.m_spuSchedulePolicy = &hkpWorldCinfo::`vftable;
  if ( v64 )
    hkReferencedObject::removeReference(v64);
  v64 = 0i64;
  if ( v62 )
    hkReferencedObject::removeReference(v62);
  v62 = 0i64;
  if ( v61 )
    hkReferencedObject::removeReference(v61);
}edObject::removeReference(v62);
  v62 = 0i64;
  if ( v61 )
    hkReferencedObject::removeReference(v61);
}

// File Line: 363
// RVA: 0xA2710
void __fastcall UFG::BasePhysicsSystem::CloseWorld(UFG::BasePhysicsSystem *this)
{
  UFG::BasePhysicsSystem *v1; // rbx
  UFG::CustomCollisionFilter *v2; // rcx
  hkJobQueue *v3; // rdi
  _QWORD **v4; // rax
  HavokJobMemoryPoolTagger *v5; // rcx
  hkReferencedObject *v6; // rcx

  v1 = this;
  v2 = this->mCollisionFilter;
  if ( v2 )
    v2->vfptr->__vecDelDtor((hkBaseObject *)&v2->vfptr, 1u);
  hkReferencedObject::removeReference((hkReferencedObject *)&v1->mWorld->vfptr);
  v3 = v1->mJobQueue;
  if ( v3 )
  {
    hkJobQueue::~hkJobQueue(v1->mJobQueue);
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkJobQueue *, signed __int64))(*v4[11] + 16i64))(v4[11], v3, 1024i64);
  }
  v5 = v1->mMemoryPoolTagger;
  if ( v5 )
    v5->vfptr->__vecDelDtor((hkExternalJobProfiler *)&v5->vfptr, 1u);
  v6 = (hkReferencedObject *)&v1->mThreadPool->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
}

// File Line: 378
// RVA: 0xAE6D0
void __fastcall UFG::BasePhysicsSystem::RegisterAgents(UFG::BasePhysicsSystem *this)
{
  hkpCollisionDispatcher *v1; // rbx

  v1 = this->mWorld->m_collisionDispatcher;
  hkpCollisionDispatcher::registerAlternateShapeType(v1, 0, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, TRIANGLE, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, BOX, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, CAPSULE, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, CYLINDER, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, CONVEX_VERTICES, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, CONVEX_TRANSFORM, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, CONVEX_PIECE, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, TRIANGLE_COLLECTION, COLLECTION);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, LIST, COLLECTION);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, EXTENDED_MESH, COLLECTION);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, MOPP, BV_TREE);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, CONVEX, SPHERE_REP);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, SAMPLED_HEIGHT_FIELD, HEIGHT_FIELD);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE, BV_TREE);
  hkpBvAgent::registerAgent(v1);
  hkpAgentRegisterUtil::_registerBvTreeAgents(v1);
  hkpCollisionDispatcher::setEnableChecks(v1, 0);
  hkpShapeCollectionAgent::registerAgent(v1);
  hkpCollisionDispatcher::setEnableChecks(v1, (hkBool)1);
  hkpAgentRegisterUtil::_registerListAgents(v1);
  hkpTransformAgent::registerAgent(v1);
  hkpPhantomAgent::registerAgent(v1);
  hkpAgentRegisterUtil::_registerTerminalAgents(v1);
}

// File Line: 450
// RVA: 0xA01E0
void __fastcall UFG::BasePhysicsSystem::AddCollisionInstanceToWorld(UFG::BasePhysicsSystem *this, UFG::CollisionInstanceData *instance)
{
  UFG::CollisionInstanceData *v2; // rdi
  unsigned int v3; // edx
  UFG::BasePhysicsSystem *v4; // rbx
  UFG::qBaseTreeRB *v5; // rax
  UFG::qBaseNodeRB *v6; // rcx
  unsigned int v7; // ST20_4
  BOOL v8; // ST20_4

  v2 = instance;
  v3 = instance->mCollisionModelGuid;
  v4 = this;
  if ( v3 )
  {
    v5 = UFG::qBaseTreeRB::Get(&this->mCollisionModels.mTree, v3);
    if ( v5 )
    {
      v6 = v5[3].mNULL.mChild[0];
      if ( !v4->mBuildingAiData || LOBYTE(v6[4].mUID) )
      {
        if ( LODWORD(v6[6].mParent) == 1 )
        {
          v7 = 0;
          v4->vfptr->OnCollisionInstanceAddedToWorld(v4, v2, (UFG::CollisionMeshData *)v5, 1u, v7, 0i64);
        }
        else if ( UFG::RigidBody::mCount < UFG::BasePhysicsSystem::mParam.maxLoadedBodies )
        {
          v8 = LODWORD(v6[6].mChild[0]) == 0;
          v4->vfptr->OnCollisionInstanceAddedToWorld(v4, v2, (UFG::CollisionMeshData *)v5, 1u, v8, 0i64);
        }
      }
    }
  }
}

// File Line: 481
// RVA: 0xAF610
void __fastcall UFG::BasePhysicsSystem::RemoveCollisionInstanceFromWorld(UFG::BasePhysicsSystem *this, UFG::CollisionInstanceData *instance)
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
  UFG::BasePhysicsSystem *v3; // rdi
  __m128 v4; // xmm2
  signed int v5; // ecx
  float v6; // xmm6_4
  __int64 v7; // rbx
  hkpWorld *v8; // rcx
  hkJobThreadPool *v9; // rcx
  UFG::CollisionMeshData::DeferredBreakablePartsMark *v10; // rbx
  UFG::qList<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark,1,0> *v11; // rsi
  float v12; // xmm0_4
  UFG::RigidBody *v13; // rcx
  UFG::qNode<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark> *v14; // rax
  UFG::qNode<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark> *v15; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBody> *v16; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark> *v21; // rcx
  UFG::qNode<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark> *v22; // rax

  v2 = deltaTime;
  v3 = this;
  if ( deltaTime > 0.000001 )
  {
    if ( this->mWorld )
    {
      _mm_setcsr(_mm_getcsr() | 0x8000);
      v2 = deltaTime;
      v4 = (__m128)LODWORD(deltaTime);
      v4.m128_f32[0] = deltaTime * 29.999998;
      v5 = (signed int)(float)(deltaTime * 29.999998);
      if ( v5 != 0x80000000 && (float)v5 != v4.m128_f32[0] )
        v4.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v4, v4)) & 1 ^ 1) + v5);
      v6 = deltaTime / v4.m128_f32[0];
      if ( (signed int)v4.m128_f32[0] > 0 )
      {
        v7 = (unsigned int)(signed int)v4.m128_f32[0];
        do
        {
          v8 = v3->mWorld;
          if ( UFG::BasePhysicsSystem::mParam.numThreads <= 1 )
            hkpWorld::stepDeltaTime(v8, v6);
          else
            hkpWorld::stepMultithreaded(v8, v3->mJobQueue, v3->mThreadPool, v6);
          --v7;
        }
        while ( v7 );
      }
    }
    v9 = v3->mThreadPool;
    if ( v9 )
      ((void (__cdecl *)(hkJobThreadPool *))v9->vfptr[4].__first_virtual_table_function__)(v9);
  }
  v10 = (UFG::CollisionMeshData::DeferredBreakablePartsMark *)UFG::CollisionMeshData::mDeferredBreakableList.mNode.mNext;
  if ( (UFG::qList<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark,1,0> *)UFG::CollisionMeshData::mDeferredBreakableList.mNode.mNext != &UFG::CollisionMeshData::mDeferredBreakableList )
  {
    do
    {
      v11 = (UFG::qList<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark,1,0> *)v10->mNext;
      v12 = v10->timer - v2;
      v10->timer = v12;
      if ( v12 < 0.0 )
      {
        v13 = (UFG::RigidBody *)v10->rigidBody.m_pPointer;
        if ( !v13 )
        {
          v15 = v10->mPrev;
          v15->mNext = &v11->mNode;
          v11->mNode.mPrev = v15;
          v10->mPrev = (UFG::qNode<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark> *)&v10->mPrev;
          v10->mNext = (UFG::qNode<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark> *)&v10->mPrev;
          v16 = &v10->rigidBody;
          if ( v10->rigidBody.m_pPointer )
          {
            v17 = v16->mPrev;
            v18 = v10->rigidBody.mNext;
            v17->mNext = v18;
            v18->mPrev = v17;
            v16->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
            v10->rigidBody.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->rigidBody.mPrev;
          }
          v10->rigidBody.m_pPointer = 0i64;
          v19 = v16->mPrev;
          v20 = v10->rigidBody.mNext;
          v19->mNext = v20;
          v20->mPrev = v19;
          v16->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
          v10->rigidBody.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->rigidBody.mPrev;
          v21 = v10->mPrev;
          v22 = v10->mNext;
          v21->mNext = v22;
          v22->mPrev = v21;
          v10->mPrev = (UFG::qNode<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark> *)&v10->mPrev;
          v10->mNext = (UFG::qNode<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark> *)&v10->mPrev;
          goto LABEL_22;
        }
        if ( v13->mBody )
        {
          v14 = v10->mPrev;
          v14->mNext = &v11->mNode;
          v11->mNode.mPrev = v14;
          v10->mPrev = (UFG::qNode<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark> *)&v10->mPrev;
          v10->mNext = (UFG::qNode<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark> *)&v10->mPrev;
          UFG::CollisionMeshData::MarkBreakableParts(v13->mCollisionMeshData, v13, 0.0);
          UFG::SupplementaryAttackTarget::~SupplementaryAttackTarget(v10);
LABEL_22:
          operator delete[](v10);
          goto LABEL_23;
        }
      }
LABEL_23:
      v10 = (UFG::CollisionMeshData::DeferredBreakablePartsMark *)v11;
    }
    while ( v11 != &UFG::CollisionMeshData::mDeferredBreakableList );
  }
  ++v3->mFrameNumber;
}

// File Line: 594
// RVA: 0xA1650
char __fastcall UFG::BasePhysicsSystem::CastAsyncRay(UFG::BasePhysicsSystem *this, UFG::qVector3 *rayStart, UFG::qVector3 *rayEnd, unsigned int collisionFilter, void (__fastcall *callback)(UFG::RayCastData *, UFG::SimComponent *, void *), UFG::SimComponent *simComponent, void *userData)
{
  UFG::BasePhysicsSystem *v7; // r10
  UFG::BasePhysicsSystem::RaycastBatch *v8; // rcx
  unsigned int v9; // er11
  hkpWorld *v10; // rax
  __m128 v11; // xmm6
  __m128 v12; // xmm4
  __m128 v13; // xmm3
  __m128 *v14; // rax
  __m128 v15; // xmm0
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  char result; // al

  v7 = this;
  v8 = this->mRaycastBatchSubmitBuffer;
  v9 = v8->mCount;
  if ( v9 >= 0xA4 )
    return 0;
  v10 = v7->mWorld;
  v11 = v10->m_broadPhaseExtents[1].m_quad;
  v12 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(rayStart->x), (__m128)LODWORD(rayStart->z)),
          _mm_unpacklo_ps((__m128)LODWORD(rayStart->y), (__m128)(unsigned int)FLOAT_1_0));
  v13 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(rayEnd->x), (__m128)LODWORD(rayEnd->z)),
          _mm_unpacklo_ps((__m128)LODWORD(rayEnd->y), (__m128)(unsigned int)FLOAT_1_0));
  if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v12, v11), _mm_cmpleps(v10->m_broadPhaseExtents[0].m_quad, v12))) & 7) != 7
    || (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v13, v11), _mm_cmpleps(v10->m_broadPhaseExtents[0].m_quad, v13))) & 7) != 7 )
  {
    return 0;
  }
  v14 = &v8->mAsyncRayData[v9].mInput.m_from.m_quad;
  *v14 = _mm_unpacklo_ps(
           _mm_unpacklo_ps((__m128)LODWORD(rayStart->x), (__m128)LODWORD(rayStart->z)),
           _mm_unpacklo_ps((__m128)LODWORD(rayStart->y), (__m128)0i64));
  v15 = (__m128)LODWORD(rayEnd->z);
  v16 = (__m128)LODWORD(rayEnd->x);
  v17 = _mm_unpacklo_ps((__m128)LODWORD(rayEnd->y), (__m128)0i64);
  v14[2].m128_i32[1] = collisionFilter;
  v14[1] = _mm_unpacklo_ps(_mm_unpacklo_ps(v16, v15), v17);
  v14[2].m128_i8[0] = 1;
  v14[12].m128_i8[8] = 0;
  v14[11].m128_u64[1] = 0i64;
  v14[12].m128_u64[0] = 0i64;
  v18 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(&v7->mRaycastBatchSubmitBuffer->mAsyncRayData[0].simComponent.mPrev
                                                                                         + 34
                                                                                         * v7->mRaycastBatchSubmitBuffer->mCount);
  if ( v18[1].mPrev )
  {
    v19 = v18->mPrev;
    v20 = v18->mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    v18->mPrev = v18;
    v18->mNext = v18;
  }
  v18[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)simComponent;
  if ( simComponent )
  {
    v21 = simComponent->m_SafePointerList.mNode.mPrev;
    v21->mNext = v18;
    v18->mPrev = v21;
    v18->mNext = &simComponent->m_SafePointerList.mNode;
    simComponent->m_SafePointerList.mNode.mPrev = v18;
  }
  result = 1;
  v7->mRaycastBatchSubmitBuffer->mAsyncRayData[v7->mRaycastBatchSubmitBuffer->mCount].callbackUserData = userData;
  v7->mRaycastBatchSubmitBuffer->mAsyncRayData[v7->mRaycastBatchSubmitBuffer->mCount++].raycastCallback = callback;
  return result;
}

// File Line: 634
// RVA: 0xB3500
void __fastcall UFG::BasePhysicsSystem::StartAsyncRayCasts(UFG::BasePhysicsSystem *this)
{
  UFG::BasePhysicsSystem::RaycastBatch *v1; // rax
  UFG::BasePhysicsSystem::RaycastBatch *v2; // rdx
  UFG::BasePhysicsSystem *v3; // rbx
  unsigned int v4; // er11
  unsigned int v5; // esi
  unsigned int v6; // ebp
  signed __int64 v7; // r8
  __int64 v8; // r10
  __int64 v9; // r9
  signed __int64 v10; // r12
  unsigned int v11; // eax
  __int64 v12; // r15
  UFG::BasePhysicsSystem::RaycastBatch *v13; // rax
  UFG::BasePhysicsSystem::RaycastBatch *v14; // rdx
  hkpWorldRayCastCommand *v15; // rcx
  UFG::BasePhysicsSystem::RaycastBatch *v16; // rax
  UFG::BasePhysicsSystem::RaycastBatch *v17; // rdx
  hkpWorldRayCastCommand *v18; // rcx
  UFG::BasePhysicsSystem::RaycastBatch *v19; // rax
  UFG::BasePhysicsSystem::RaycastBatch *v20; // rdx
  hkpWorldRayCastCommand *v21; // rcx
  UFG::BasePhysicsSystem::RaycastBatch *v22; // rax
  UFG::BasePhysicsSystem::RaycastBatch *v23; // rdx
  hkpWorldRayCastCommand *v24; // rcx
  signed __int64 v25; // rcx
  signed __int64 v26; // r9
  signed __int64 v27; // r8
  signed __int64 v28; // r10
  __int64 v29; // rsi
  UFG::BasePhysicsSystem::RaycastBatch *v30; // rax
  UFG::BasePhysicsSystem::RaycastBatch *v31; // rdx
  hkpWorldRayCastCommand *v32; // rcx
  signed __int64 v33; // rcx
  float v34; // xmm0_4
  int v35; // er15
  int v36; // ebp
  __int64 v37; // r12
  hkpWorld *v38; // rax
  hkpProcessCollisionInput *v39; // rcx
  hkpBroadPhase *v40; // rdx
  hkSemaphore *v41; // rax
  int v42; // esi
  hkpCollisionQueryJobHeader *v43; // r8
  hkpWorldRayCastCommand *v44; // rcx
  int v45; // eax
  signed __int64 v46; // rdx
  hkpWorldRayCastJob v47; // [rsp+20h] [rbp-88h]

  v1 = this->mRaycastBatchSubmitBuffer;
  v2 = this->mRaycastBatchExecuteBuffer;
  v3 = this;
  this->mRaycastBatchExecuteBuffer = v1;
  this->mRaycastBatchSubmitBuffer = v2;
  if ( v1->mCount )
  {
    this->mRaycastCallbackActive = 1;
    v4 = UFG::BasePhysicsSystem::mParam.numThreads;
    v5 = 0;
    if ( UFG::BasePhysicsSystem::mParam.numThreads <= 1u )
    {
      if ( v1->mCount > 0 )
      {
        do
        {
          v46 = (signed __int64)&v3->mRaycastBatchExecuteBuffer->mAsyncRayData[v5];
          *(_QWORD *)(v46 + 128) = 0i64;
          *(_DWORD *)(v46 + 64) = 1065353216;
          *(_DWORD *)(v46 + 68) = -1;
          *(_DWORD *)(v46 + 112) = 0;
          *(_DWORD *)(v46 + 80) = -1;
          UFG::BasePhysicsSystem::CastRay(v3, (UFG::RayCastData *)v46);
          ++v5;
        }
        while ( v5 < v3->mRaycastBatchExecuteBuffer->mCount );
      }
    }
    else
    {
      v6 = v1->mCount;
      v7 = 0i64;
      if ( (signed int)v6 >= 4 )
      {
        v8 = 0i64;
        v9 = 0i64;
        v10 = 544i64;
        v11 = ((v6 - 4) >> 2) + 1;
        v12 = v11;
        v5 = 4 * v11;
        v7 = 4i64 * v11;
        do
        {
          v13 = v3->mRaycastBatchExecuteBuffer;
          v13->mAsyncRayData[v9].mOutput.m_rootCollidable = 0i64;
          v13->mAsyncRayData[v9].mOutput.m_hitFraction = 1.0;
          v13->mAsyncRayData[v9].mOutput.m_extraInfo = -1;
          v13->mAsyncRayData[v9].mOutput.m_shapeKeyIndex = 0;
          v13->mAsyncRayData[v9].mOutput.m_shapeKeys[0] = -1;
          v14 = v3->mRaycastBatchExecuteBuffer;
          v15 = v3->mRayCastCommands.m_data;
          v15[v8].m_rayInput.m_from = v14->mAsyncRayData[v9].mInput.m_from;
          v15[v8].m_rayInput.m_to = v14->mAsyncRayData[v9].mInput.m_to;
          v15[v8].m_rayInput.m_enableShapeCollectionFilter.m_bool = v14->mAsyncRayData[v9].mInput.m_enableShapeCollectionFilter.m_bool;
          v15[v8].m_rayInput.m_filterInfo = v14->mAsyncRayData[v9].mInput.m_filterInfo;
          v15[v8].m_rayInput.m_userData = v14->mAsyncRayData[v9].mInput.m_userData;
          v3->mRayCastCommands.m_data[v8].m_results = (hkpWorldRayCastOutput *)((char *)&v3->mRaycastBatchExecuteBuffer[-1].mAsyncRayData[162].mOutput.m_hitFraction
                                                                              + v10);
          v3->mRayCastCommands.m_data[v8].m_resultsCapacity = 1;
          v3->mRayCastCommands.m_data[v8].m_numResultsOut = 0;
          v3->mRayCastCommands.m_data[v8].m_rayInput.m_enableShapeCollectionFilter.m_bool = 1;
          v16 = v3->mRaycastBatchExecuteBuffer;
          v16->mAsyncRayData[v9 + 1].mOutput.m_rootCollidable = 0i64;
          v16->mAsyncRayData[v9 + 1].mOutput.m_hitFraction = 1.0;
          v16->mAsyncRayData[v9 + 1].mOutput.m_extraInfo = -1;
          v16->mAsyncRayData[v9 + 1].mOutput.m_shapeKeyIndex = 0;
          v16->mAsyncRayData[v9 + 1].mOutput.m_shapeKeys[0] = -1;
          v17 = v3->mRaycastBatchExecuteBuffer;
          v18 = v3->mRayCastCommands.m_data;
          v18[v8 + 1].m_rayInput.m_from = v17->mAsyncRayData[v9 + 1].mInput.m_from;
          v18[v8 + 1].m_rayInput.m_to = v17->mAsyncRayData[v9 + 1].mInput.m_to;
          v18[v8 + 1].m_rayInput.m_enableShapeCollectionFilter.m_bool = v17->mAsyncRayData[v9 + 1].mInput.m_enableShapeCollectionFilter.m_bool;
          v18[v8 + 1].m_rayInput.m_filterInfo = v17->mAsyncRayData[v9 + 1].mInput.m_filterInfo;
          v18[v8 + 1].m_rayInput.m_userData = v17->mAsyncRayData[v9 + 1].mInput.m_userData;
          v3->mRayCastCommands.m_data[v8 + 1].m_results = (hkpWorldRayCastOutput *)((char *)&v3->mRaycastBatchExecuteBuffer[-1].mAsyncRayData[163].mOutput.m_hitFraction
                                                                                  + v10);
          v3->mRayCastCommands.m_data[v8 + 1].m_resultsCapacity = 1;
          v3->mRayCastCommands.m_data[v8 + 1].m_numResultsOut = 0;
          v3->mRayCastCommands.m_data[v8 + 1].m_rayInput.m_enableShapeCollectionFilter.m_bool = 1;
          v19 = v3->mRaycastBatchExecuteBuffer;
          v19->mAsyncRayData[v9 + 2].mOutput.m_rootCollidable = 0i64;
          v19->mAsyncRayData[v9 + 2].mOutput.m_hitFraction = 1.0;
          v19->mAsyncRayData[v9 + 2].mOutput.m_extraInfo = -1;
          v19->mAsyncRayData[v9 + 2].mOutput.m_shapeKeyIndex = 0;
          v19->mAsyncRayData[v9 + 2].mOutput.m_shapeKeys[0] = -1;
          v20 = v3->mRaycastBatchExecuteBuffer;
          v21 = v3->mRayCastCommands.m_data;
          v21[v8 + 2].m_rayInput.m_from = v20->mAsyncRayData[v9 + 2].mInput.m_from;
          v21[v8 + 2].m_rayInput.m_to = v20->mAsyncRayData[v9 + 2].mInput.m_to;
          v21[v8 + 2].m_rayInput.m_enableShapeCollectionFilter.m_bool = v20->mAsyncRayData[v9 + 2].mInput.m_enableShapeCollectionFilter.m_bool;
          v21[v8 + 2].m_rayInput.m_filterInfo = v20->mAsyncRayData[v9 + 2].mInput.m_filterInfo;
          v21[v8 + 2].m_rayInput.m_userData = v20->mAsyncRayData[v9 + 2].mInput.m_userData;
          v3->mRayCastCommands.m_data[v8 + 2].m_results = (hkpWorldRayCastOutput *)((char *)&v3->mRaycastBatchExecuteBuffer->mAsyncRayData[0].mOutput
                                                                                  + v10);
          v8 += 4i64;
          v9 += 4i64;
          *((_DWORD *)&v3->mRayCastCommands.m_data[v8 - 1] - 6) = 1;
          *((_DWORD *)&v3->mRayCastCommands.m_data[v8 - 1] - 5) = 0;
          *((_BYTE *)&v3->mRayCastCommands.m_data[v8 - 1] - 48) = 1;
          v22 = v3->mRaycastBatchExecuteBuffer;
          *((_QWORD *)&v22->mAsyncRayData[v9] - 18) = 0i64;
          *((_DWORD *)&v22->mAsyncRayData[v9] - 52) = 1065353216;
          *((_DWORD *)&v22->mAsyncRayData[v9] - 51) = -1;
          *((_DWORD *)&v22->mAsyncRayData[v9] - 40) = 0;
          *((_DWORD *)&v22->mAsyncRayData[v9] - 48) = -1;
          v23 = v3->mRaycastBatchExecuteBuffer;
          v24 = v3->mRayCastCommands.m_data;
          v24[v8 - 1].m_rayInput.m_from = v23->mAsyncRayData[v9 - 1].mInput.m_from;
          *((_OWORD *)&v24[v8] - 4) = *((_OWORD *)&v23->mAsyncRayData[v9] - 16);
          *((_BYTE *)&v24[v8] - 48) = *((_BYTE *)&v23->mAsyncRayData[v9] - 240);
          *((_DWORD *)&v24[v8] - 11) = *((_DWORD *)&v23->mAsyncRayData[v9] - 59);
          *((_QWORD *)&v24[v8] - 5) = *((_QWORD *)&v23->mAsyncRayData[v9] - 29);
          v25 = (signed __int64)&v3->mRaycastBatchExecuteBuffer->mAsyncRayData[1].mOutput + v10;
          v10 += 1088i64;
          *((_QWORD *)&v3->mRayCastCommands.m_data[v8] - 4) = v25;
          *((_DWORD *)&v3->mRayCastCommands.m_data[v8] - 6) = 1;
          *((_DWORD *)&v3->mRayCastCommands.m_data[v8] - 5) = 0;
          *((_BYTE *)&v3->mRayCastCommands.m_data[v8] - 48) = 1;
          --v12;
        }
        while ( v12 );
      }
      if ( v5 < v6 )
      {
        v26 = v7;
        v27 = v7;
        v28 = 272i64 * v5;
        v29 = v6 - v5;
        do
        {
          v30 = v3->mRaycastBatchExecuteBuffer;
          ++v26;
          ++v27;
          *((_QWORD *)&v30->mAsyncRayData[v27] - 18) = 0i64;
          *((_DWORD *)&v30->mAsyncRayData[v27] - 52) = 1065353216;
          *((_DWORD *)&v30->mAsyncRayData[v27] - 51) = -1;
          *((_DWORD *)&v30->mAsyncRayData[v27] - 40) = 0;
          *((_DWORD *)&v30->mAsyncRayData[v27] - 48) = -1;
          v31 = v3->mRaycastBatchExecuteBuffer;
          v32 = v3->mRayCastCommands.m_data;
          v32[v26 - 1].m_rayInput.m_from = v31->mAsyncRayData[v27 - 1].mInput.m_from;
          *((_OWORD *)&v32[v26] - 4) = *((_OWORD *)&v31->mAsyncRayData[v27] - 16);
          *((_BYTE *)&v32[v26] - 48) = *((_BYTE *)&v31->mAsyncRayData[v27] - 240);
          *((_DWORD *)&v32[v26] - 11) = *((_DWORD *)&v31->mAsyncRayData[v27] - 59);
          *((_QWORD *)&v32[v26] - 5) = *((_QWORD *)&v31->mAsyncRayData[v27] - 29);
          v33 = (signed __int64)&v3->mRaycastBatchExecuteBuffer->mAsyncRayData[0].mOutput + v28;
          v28 += 272i64;
          *((_QWORD *)&v3->mRayCastCommands.m_data[v26] - 4) = v33;
          *((_DWORD *)&v3->mRayCastCommands.m_data[v26] - 6) = 1;
          *((_DWORD *)&v3->mRayCastCommands.m_data[v26] - 5) = 0;
          *((_BYTE *)&v3->mRayCastCommands.m_data[v26] - 48) = 1;
          --v29;
        }
        while ( v29 );
      }
      v34 = *(float *)&FLOAT_1_0;
      if ( v6 < v4 )
        v4 = v6;
      if ( (float)(signed int)(v6 / v4) >= 1.0 )
        v34 = (float)(signed int)(v6 / v4);
      v35 = 0;
      v36 = v6 - v4 * (signed int)v34;
      if ( v4 )
      {
        v37 = v4;
        do
        {
          v38 = v3->mWorld;
          v39 = v38->m_collisionInput;
          v40 = v38->m_broadPhase;
          v41 = v3->mRayCastSemaphore;
          v47.m_collisionInput = v39;
          v47.m_semaphore = v41;
          v42 = (signed int)v34 + (v36 > 0);
          v47.m_size = 96;
          v43 = v3->mRayCastJobHeader;
          --v36;
          *(_WORD *)&v47.m_jobSubType = 769;
          v47.m_threadAffinity = -1;
          v44 = &v3->mRayCastCommands.m_data[v35];
          v47.m_jobDoneFlag = 0i64;
          v47.m_jobSpuType.m_storage = 1;
          v47.m_sharedJobHeaderOnPpu = v43;
          v47.m_numCommandsPerTask = 64;
          v47.m_numCommands = v42;
          v47.m_commandArray = v44;
          v47.m_broadphase = v40;
          if ( v42 )
            v45 = (v42 - 1) / 64 + 1;
          else
            v45 = 1;
          v43->m_openJobs = v45;
          v47.m_bundleCommandArray = 0i64;
          v47.m_numBundleCommands = 0;
          hkpWorldRayCastJob::setRunsOnSpuOrPpu(&v47);
          hkJobQueue::addJob(v3->mJobQueue, (hkJob *)&v47.m_jobSubType, 0);
          v35 += v42;
          --v37;
        }
        while ( v37 );
      }
      ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, signed __int64))v3->mThreadPool->vfptr[5].__first_virtual_table_function__)(
        v3->mThreadPool,
        v3->mJobQueue,
        20i64);
    }
  }
}

// File Line: 702
// RVA: 0xB5D60
__int64 __fastcall UFG::BasePhysicsSystem::WaitForAsyncRayCastCompletion(UFG::BasePhysicsSystem *this)
{
  UFG::BasePhysicsSystem *v1; // rbx
  unsigned int v2; // edi
  signed __int64 v3; // rcx
  float v4; // xmm0_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm6_4
  float v8; // xmm5_4
  float v9; // xmm6_4
  int v10; // xmm0_4
  int v11; // xmm1_4
  __int64 v12; // rax
  __int64 v13; // r8
  __int64 v14; // rdx
  __int64 v15; // r9
  __int64 v16; // rax
  __int64 v17; // r10
  _DWORD *v18; // rdx
  __int64 v19; // rax
  __int64 v20; // r8
  _DWORD *v21; // rdx
  UFG::BasePhysicsSystem::RaycastBatch *v22; // rax

  v1 = this;
  if ( this->mRaycastBatchExecuteBuffer->mCount )
  {
    if ( UFG::BasePhysicsSystem::mParam.numThreads > 1 )
    {
      ((void (*)(void))this->mThreadPool->vfptr[2].__vecDelDtor)();
      hkSemaphore::acquire(v1->mRayCastSemaphore);
      v2 = 0;
      if ( v1->mRaycastBatchExecuteBuffer->mCount )
      {
        do
        {
          v3 = (signed __int64)&v1->mRaycastBatchExecuteBuffer->mAsyncRayData[v2];
          if ( !*(_QWORD *)(v3 + 128) )
          {
            *(_BYTE *)(v3 + 200) = 0;
            goto LABEL_27;
          }
          v4 = *(float *)(v3 + 64);
          *(_BYTE *)(v3 + 200) = 1;
          v5 = *(float *)(v3 + 16);
          v6 = *(float *)(v3 + 20);
          v7 = *(float *)(v3 + 24);
          *(float *)(v3 + 180) = v4;
          v8 = (float)((float)(v6 - *(float *)(v3 + 4)) * v4) + *(float *)(v3 + 4);
          v9 = (float)((float)(v7 - *(float *)(v3 + 8)) * v4) + *(float *)(v3 + 8);
          *(float *)(v3 + 156) = (float)((float)(v5 - *(float *)v3) * v4) + *(float *)v3;
          *(float *)(v3 + 160) = v8;
          *(float *)(v3 + 164) = v9;
          v10 = *(_DWORD *)(v3 + 52);
          v11 = *(_DWORD *)(v3 + 56);
          *(_DWORD *)(v3 + 168) = *(_DWORD *)(v3 + 48);
          *(_DWORD *)(v3 + 172) = v10;
          *(_DWORD *)(v3 + 176) = v11;
          v12 = *(_QWORD *)(v3 + 128);
          if ( *(_BYTE *)(v12 + 40) == 1 )
            v13 = v12 + *(char *)(v12 + 32);
          else
            v13 = 0i64;
          *(_QWORD *)(v3 + 184) = v13;
          if ( *(_BYTE *)(v12 + 40) == 2 )
            v14 = v12 + *(char *)(v12 + 32);
          else
            v14 = 0i64;
          *(_QWORD *)(v3 + 192) = v14;
          *(_QWORD *)(v3 + 208) = 0i64;
          *(_QWORD *)(v3 + 216) = 0i64;
          if ( v13 )
          {
            v15 = *(signed int *)(v13 + 192);
            v16 = 0i64;
            if ( v15 > 0 )
            {
              v17 = *(_QWORD *)(v13 + 184);
              v18 = *(_DWORD **)(v13 + 184);
              while ( *v18 != UFG::physicsObjectPropertyTypeUid )
              {
                ++v16;
                v18 += 4;
                if ( v16 >= v15 )
                  goto LABEL_16;
              }
LABEL_25:
              v19 = *(_QWORD *)(v17 + 16 * v16 + 8);
              goto LABEL_17;
            }
          }
          else
          {
            if ( !v14 )
              goto LABEL_18;
            v20 = *(signed int *)(v14 + 192);
            v16 = 0i64;
            if ( v20 > 0 )
            {
              v17 = *(_QWORD *)(v14 + 184);
              v21 = *(_DWORD **)(v14 + 184);
              while ( *v21 != UFG::physicsObjectPropertyTypeUid )
              {
                ++v16;
                v21 += 4;
                if ( v16 >= v20 )
                  goto LABEL_16;
              }
              goto LABEL_25;
            }
          }
LABEL_16:
          v19 = 0i64;
LABEL_17:
          *(_QWORD *)(v3 + 208) = v19;
LABEL_18:
          UFG::BasePhysicsSystem::DetermineRaycastSurfaceProperties(v1, (UFG::RayCastData *)v3);
LABEL_27:
          ++v2;
        }
        while ( v2 < v1->mRaycastBatchExecuteBuffer->mCount );
      }
    }
  }
  v22 = v1->mRaycastBatchExecuteBuffer;
  v1->mRaycastCallbackActive = 0;
  return v22->mCount;
}

// File Line: 772
// RVA: 0xA7050
void __fastcall UFG::BasePhysicsSystem::DetermineRaycastSurfaceProperties(UFG::BasePhysicsSystem *this, UFG::RayCastData *data)
{
  UFG::RayCastData *v2; // rbx
  hkpShape *v3; // r8
  signed int v4; // edi
  unsigned int v5; // ecx
  bool v6; // dl
  __int64 v7; // rsi
  __int64 v8; // rax
  __int64 v9; // rcx
  signed __int64 v10; // r8
  UFG::BaseProperty *v11; // rax
  UFG::qReflectObject *v12; // rax
  unsigned int v13; // eax
  UFG::qBaseTreeRB *v14; // r8
  UFG::qReflectHandleBase v15; // [rsp+28h] [rbp-30h]

  v2 = data;
  v3 = data->mOutput.m_rootCollidable->m_shape;
  v4 = data->mOutput.m_shapeKeys[0];
  v5 = data->mOutput.m_shapeKeys[1];
  v6 = v5 != -1;
  if ( v4 != -1 )
  {
    if ( !v6 )
      goto LABEL_26;
    if ( v5 )
      v4 = v5;
    if ( v6 )
    {
      v7 = *(_QWORD *)(v2->mHavokRigidBody->m_userData + 24);
      if ( UFG::SimComponent::IsType((UFG::SimComponent *)v7, UFG::RigidBody::_RigidBodyTypeUID) )
      {
        v8 = *(_QWORD *)(v7 + 160);
        v9 = *(_QWORD *)(v8 + 152);
        if ( v9 )
          v10 = v9 + v8 + 152;
        else
          v10 = 0i64;
        v2->mPhysicsObjectPropertyHandleUid = *(_QWORD *)(v10 + 48i64 * v4 + 16);
        v2->mCollisionModelName.mUID = *(_DWORD *)(v10 + 48i64 * v4 + 24);
        return;
      }
    }
    else
    {
LABEL_26:
      if ( v4 != -1 )
      {
        v11 = UFG::GetBaseProperty(v3, v4);
        if ( v11 )
        {
          v2->mPhysicsSurfacePropertyHandleUid = v11->surfacePropertyHandleId;
          v2->mPhysicsObjectPropertyHandleUid = v11->objectPropertyHandleId;
          v2->mCollisionModelName.mUID = v11->collisionModelName.mUID;
        }
      }
    }
  }
  if ( !v2->mPhysicsSurfacePropertyHandleUid )
  {
    UFG::qReflectHandleBase::qReflectHandleBase(&v15);
    v15.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v15, v15.mTypeUID, v2->mPhysicsObjectPropertyHandleUid);
    v12 = v15.mData;
    if ( !v15.mData )
    {
      if ( _S4_2 & 1 )
      {
        v13 = default_uid_1;
      }
      else
      {
        _S4_2 |= 1u;
        v13 = UFG::qStringHashUpper32("default", 0xFFFFFFFF);
        default_uid_1 = v13;
      }
      if ( v13 )
        v14 = UFG::qBaseTreeRB::Get(&UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree, v13);
      else
        v14 = 0i64;
      UFG::qReflectHandleBase::Init(&v15, v15.mTypeUID, *(_QWORD *)&v14->mNULL.mUID);
      v12 = v15.mData;
    }
    v2->mPhysicsSurfacePropertyHandleUid = *(_QWORD *)(v12[4].mBaseNode.mUID + 8);
    UFG::qReflectHandleBase::~qReflectHandleBase(&v15);
  }
}

// File Line: 832
// RVA: 0xA7760
void __fastcall UFG::BasePhysicsSystem::DispatchAsyncRayCastResultCallbacks(UFG::BasePhysicsSystem *this)
{
  UFG::BasePhysicsSystem::RaycastBatch *v1; // rdx
  unsigned int v2; // ebx
  UFG::BasePhysicsSystem *v3; // rdi

  v1 = this->mRaycastBatchExecuteBuffer;
  v2 = 0;
  v3 = this;
  if ( v1->mCount )
  {
    do
    {
      v1->mAsyncRayData[v2].raycastCallback(
        (UFG::RayCastData *)&v1->mAsyncRayData[v2].mInput,
        v1->mAsyncRayData[v2].simComponent.m_pPointer,
        v1->mAsyncRayData[v2].callbackUserData);
      v1 = v3->mRaycastBatchExecuteBuffer;
      ++v2;
    }
    while ( v2 < v1->mCount );
    v1->mCount = 0;
  }
  else
  {
    v1->mCount = 0;
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
  UFG::BasePhysicsSystem *v2; // rsi
  hkpWorld *v3; // rcx
  UFG::RayCastData *v4; // rbx
  __m128 v5; // xmm3
  bool v6; // al
  float v7; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm6_4
  float v12; // xmm5_4
  float v13; // eax
  float v14; // xmm1_4
  hkpCollidable *v15; // rax
  hkpWorldObject *v16; // rdi
  hkpPhantom *v17; // rcx
  unsigned __int64 v18; // rdi
  __int64 v19; // rdi

  data->mOutput.m_hitFraction = 1.0;
  data->mOutput.m_extraInfo = -1;
  data->mOutput.m_rootCollidable = 0i64;
  data->mOutput.m_shapeKeyIndex = 0;
  data->mOutput.m_shapeKeys[0] = -1;
  ++UFG::BasePhysicsSystem::mSyncRayCastCount;
  v2 = this;
  v3 = this->mWorld;
  v4 = data;
  if ( !v3 )
    return 0;
  v5 = v3->m_broadPhaseExtents[1].m_quad;
  if ( (_mm_movemask_ps(
          _mm_and_ps(
            _mm_cmpleps(v3->m_broadPhaseExtents[0].m_quad, data->mInput.m_from.m_quad),
            _mm_cmpleps(data->mInput.m_from.m_quad, v5))) & 7) != 7
    && (_mm_movemask_ps(
          _mm_and_ps(
            _mm_cmpleps(v3->m_broadPhaseExtents[0].m_quad, data->mInput.m_to.m_quad),
            _mm_cmpleps(data->mInput.m_to.m_quad, v5))) & 7) != 7 )
  {
    return 0;
  }
  hkpWorld::castRay(v3, &data->mInput, &data->mOutput);
  v6 = v4->mOutput.m_rootCollidable != 0i64;
  v4->hit = v6;
  if ( !v6 )
    return 0;
  v7 = v4->mOutput.m_hitFraction;
  v8 = v4->mInput.m_to.m_quad.m128_f32[0];
  v9 = v4->mInput.m_to.m_quad.m128_f32[1];
  v10 = v4->mInput.m_to.m_quad.m128_f32[2];
  v4->t = v7;
  v11 = (float)((float)(v10 - v4->mInput.m_from.m_quad.m128_f32[2]) * v7) + v4->mInput.m_from.m_quad.m128_f32[2];
  v12 = (float)((float)(v9 - v4->mInput.m_from.m_quad.m128_f32[1]) * v7) + v4->mInput.m_from.m_quad.m128_f32[1];
  v4->point.x = (float)((float)(v8 - v4->mInput.m_from.m_quad.m128_f32[0]) * v7) + v4->mInput.m_from.m_quad.m128_f32[0];
  v4->point.z = v11;
  v4->point.y = v12;
  v13 = v4->mOutput.m_normal.m_quad.m128_f32[0];
  v14 = v4->mOutput.m_normal.m_quad.m128_f32[2];
  v4->normal.y = v4->mOutput.m_normal.m_quad.m128_f32[1];
  v4->normal.x = v13;
  v4->normal.z = v14;
  v15 = v4->mOutput.m_rootCollidable;
  if ( v15->m_broadPhaseHandle.m_type == 1 )
    v16 = (hkpWorldObject *)((char *)v15 + v15->m_ownerOffset);
  else
    v16 = 0i64;
  v4->mHavokRigidBody = (hkpRigidBody *)v16;
  if ( v15->m_broadPhaseHandle.m_type == 2 )
    v17 = (hkpPhantom *)((char *)v15 + v15->m_ownerOffset);
  else
    v17 = 0i64;
  v4->mHavokPhantom = v17;
  v4->mPhysicsObjectPropertyHandleUid = 0i64;
  v4->mPhysicsSurfacePropertyHandleUid = 0i64;
  if ( v16 )
  {
    v4->mPhysicsObjectPropertyHandleUid = UFG::PhysicsPropertyManager::GetObjectPropertiesHandleUid(v16);
    v18 = v16->m_userData;
    if ( v18 )
    {
      v19 = *(_QWORD *)(v18 + 0x18);
      if ( v19 )
      {
        if ( UFG::SimComponent::IsType((UFG::SimComponent *)v19, UFG::RigidBody::_RigidBodyTypeUID) )
          v4->mCollisionModelName.mUID = *(_DWORD *)(*(_QWORD *)(v19 + 0xA0) + 0xD8i64);
      }
    }
  }
  UFG::BasePhysicsSystem::DetermineRaycastSurfaceProperties(v2, v4);
  return 1;
}

// File Line: 933
// RVA: 0xA1DD0
bool __fastcall UFG::BasePhysicsSystem::CastShape(UFG::BasePhysicsSystem *this, UFG::ShapeCasterCollector *sc, UFG::qVector3 *start, UFG::qVector3 *end)
{
  __m128 v4; // xmm0
  __m128 v5; // xmm2
  hkVector4f enda; // [rsp+30h] [rbp-28h]
  hkVector4f starta; // [rsp+40h] [rbp-18h]

  v4 = (__m128)LODWORD(end->z);
  v5 = _mm_unpacklo_ps((__m128)LODWORD(end->y), (__m128)(unsigned int)FLOAT_1_0);
  starta.m_quad = _mm_unpacklo_ps(
                    _mm_unpacklo_ps((__m128)LODWORD(start->x), (__m128)LODWORD(start->z)),
                    _mm_unpacklo_ps((__m128)LODWORD(start->y), (__m128)(unsigned int)FLOAT_1_0));
  enda.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)LODWORD(end->x), v4), v5);
  return UFG::BasePhysicsSystem::CastShape(this, sc, &starta, &enda);
}

// File Line: 941
// RVA: 0xA1B50
bool __fastcall UFG::BasePhysicsSystem::CastShape(UFG::BasePhysicsSystem *this, UFG::ShapeCasterCollector *sc, hkVector4f *start, hkVector4f *end)
{
  hkVector4f *v4; // rsi
  hkVector4f *v5; // r14
  hkpPhantom **v6; // rdi
  UFG::BasePhysicsSystem *v7; // rbx
  UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *v8; // r12
  hkpWorld *v9; // r13
  hkpPhantom *v11; // rdx
  int i; // ebx
  __int64 v13; // r8
  bool v14; // bl
  __m128 v15; // [rsp+30h] [rbp-A8h]
  __m128 v16; // [rsp+40h] [rbp-98h]
  int v17; // [rsp+50h] [rbp-88h]
  int v18; // [rsp+54h] [rbp-84h]
  __m128 v19; // [rsp+58h] [rbp-80h]
  __int64 v20; // [rsp+68h] [rbp-70h]
  char v21; // [rsp+70h] [rbp-68h]
  __int64 v22; // [rsp+98h] [rbp-40h]
  hkpAllCdPointCollector v23; // [rsp+A8h] [rbp-30h]
  hkInplaceArray<hkpRootCdPoint,8,hkContainerHeapAllocator> *v24; // [rsp+2F8h] [rbp+220h]
  void *retaddr; // [rsp+318h] [rbp+240h]
  char v26; // [rsp+320h] [rbp+248h]

  v22 = -2i64;
  v4 = end;
  v5 = start;
  v6 = (hkpPhantom **)sc;
  v7 = this;
  v8 = &sc->mHitList;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&sc->mHitList);
  v9 = v7->mWorld;
  if ( !v9 )
    return 0;
  v11 = v6[3];
  if ( !v11->m_world )
    hkpWorld::addPhantom(v7->mWorld, v11);
  v17 = 872415232;
  v18 = 872415232;
  v15 = v5->m_quad;
  v16 = v4->m_quad;
  if ( (_DWORD)retaddr )
  {
    if ( (unsigned int)((_DWORD)retaddr - 1) <= 1 )
    {
      v23.vfptr = (hkpCdPointCollectorVtbl *)&hkpAllCdPointCollector::`vftable;
      v24 = &v23.m_hits;
      v23.m_hits.m_data = v23.m_hits.m_storage;
      v23.m_hits.m_capacityAndFlags = -2147483640;
      v23.m_hits.m_size = 0;
      v23.m_earlyOutDistance = 3.40282e38;
      ((void (__fastcall *)(hkpPhantom *, __m128 *, __m128 *, hkpAllCdPointCollector *, hkpAllCdPointCollector *))v6[3]->vfptr[7].__first_virtual_table_function__)(
        v6[3],
        &v15,
        &v16,
        &v23,
        &v23);
      hkpAllCdPointCollector::sortHits(&v23);
      for ( i = 0; i < v23.m_hits.m_size; ++i )
        (*(void (__fastcall **)(hkpPhantom **, hkpRootCdPoint *, bool))&(*v6)->m_memSizeAndFlags)(
          v6,
          &v23.m_hits.m_data[(signed __int64)i],
          (_DWORD)retaddr == 1);
      v23.vfptr = (hkpCdPointCollectorVtbl *)&hkpAllCdPointCollector::`vftable;
      v24 = &v23.m_hits;
      v23.m_hits.m_size = 0;
      if ( v23.m_hits.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v23.m_hits.m_data,
          v23.m_hits.m_capacityAndFlags << 6);
      v23.m_hits.m_data = 0i64;
      v23.m_hits.m_capacityAndFlags = 2147483648;
      v23.vfptr = (hkpCdPointCollectorVtbl *)&hkpCdPointCollector::`vftable;
    }
  }
  else
  {
    v19.m128_u64[1] = (unsigned __int64)&hkpClosestCdPointCollector::`vftable;
    v20 = 0i64;
    v19 = _mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, (__m128)xmmword_141A712A0), 196);
    LODWORD(v20) = 2139095022;
    ((void (__fastcall *)(hkpPhantom *, __m128 *, __m128 *, char *, char *))v6[3]->vfptr[7].__first_virtual_table_function__)(
      v6[3],
      &v15,
      &v16,
      &v19.m128_i8[8],
      &v19.m128_i8[8]);
    if ( v20 )
    {
      LOBYTE(v13) = 1;
      (*(void (__fastcall **)(hkpPhantom **, char *, __int64))&(*v6)->m_memSizeAndFlags)(v6, &v21, v13);
    }
    v19.m128_u64[1] = (unsigned __int64)&hkpCdPointCollector::`vftable;
  }
  v14 = v8->mNode.mNext != (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)v8;
  if ( v26 )
    hkpWorld::removePhantom(v9, v6[3]);
  return v14;
}

// File Line: 1093
// RVA: 0xA1840
char __fastcall UFG::BasePhysicsSystem::CastAsyncShape(UFG::BasePhysicsSystem *this, UFG::AsyncShapeCasterCollector *caster, UFG::SimComponent *simComponent, void *userData)
{
  UFG::BasePhysicsSystem *v4; // rbx
  unsigned int v5; // ecx
  hkpWorld *v6; // rax
  __m128 v7; // xmm3
  __m128 v8; // xmm4
  hkVector4f v9; // xmm6
  __m128 v10; // xmm0
  hkVector4f position; // [rsp+20h] [rbp-28h]

  v4 = this;
  v5 = this->mShapecastBatch.mCount;
  if ( v5 >= 0x30 )
    return 0;
  v6 = v4->mWorld;
  v7 = v6->m_broadPhaseExtents[0].m_quad;
  v8 = v6->m_broadPhaseExtents[1].m_quad;
  v9.m_quad = (__m128)caster->m_to;
  v10 = v6->m_broadPhaseExtents[0].m_quad;
  position.m_quad = (__m128)caster->m_from;
  if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(position.m_quad, v8), _mm_cmpleps(v10, position.m_quad))) & 7) != 7
    || (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v9.m_quad, v8), _mm_cmpleps(v7, v9.m_quad))) & 7) != 7 )
  {
    return 0;
  }
  UFG::AsyncShapeCasterCollector::operator=(&v4->mShapecastBatch.mAsyncShapeData[v5], caster);
  v4->mShapecastBatch.mAsyncShapeData[v4->mShapecastBatch.mCount].mInput.m_to = (hkVector4f)v9.m_quad;
  hkpShapePhantom::setPosition(v4->mShapecastBatch.mAsyncShapeData[v4->mShapecastBatch.mCount].mPhantom, &position, 0.0);
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v4->mShapecastBatch.mAsyncShapeData[v4->mShapecastBatch.mCount].mHitList);
  ++v4->mShapecastBatch.mCount;
  return 1;
}

// File Line: 1380
// RVA: 0xA0460
void __fastcall UFG::BasePhysicsSystem::AddEntity(UFG::BasePhysicsSystem *this, hkpPhantom *p, bool addBatched)
{
  UFG::BasePhysicsSystem *v3; // r10
  signed __int64 v4; // rbx
  hkpPhantom *v5; // rsi
  char v6; // r9
  __int64 v7; // rax
  char v8; // cl
  signed __int64 v9; // rdi
  char v10; // al

  v3 = this;
  v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v5 = p;
  v6 = ++*(_BYTE *)(v4 + 80);
  v7 = v6;
  *(_DWORD *)(v4 + 4 * v7) = 3;
  *(_QWORD *)(v4 + 8 * v7 + 16) = "BasePhysicsSystem::AddEntity";
  *(_QWORD *)(v4 + 8 * v7 + 48) = 0i64;
  v8 = *(_BYTE *)(v4 + 81);
  if ( v6 > v8 )
    v8 = v6;
  *(_BYTE *)(v4 + 81) = v8;
  if ( addBatched )
  {
    v9 = (signed __int64)&v3->mPhantomsToAdd;
    if ( v3->mPhantomsToAdd.m_size == (v3->mPhantomsToAdd.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->mPhantomsToAdd, 8);
    *(_QWORD *)(*(_QWORD *)v9 + 8i64 * (signed int)(*(_DWORD *)(v9 + 8))++) = v5;
  }
  else
  {
    hkpWorld::addPhantom(v3->mWorld, p);
  }
  v10 = *(_BYTE *)(v4 + 80);
  if ( v10 > 0 )
  {
    *(_BYTE *)(v4 + 80) = v10 - 1;
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
  hkpRigidBody *v3; // rdi
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v4; // rbx

  v3 = rb;
  if ( addBatched )
  {
    v4 = &this->mEntitiesToAdd;
    if ( this->mEntitiesToAdd.m_size == (this->mEntitiesToAdd.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
    v4->m_data[v4->m_size++] = (hkpEntity *)&v3->vfptr;
  }
  else
  {
    hkpWorld::addEntity(this->mWorld, (hkpEntity *)&rb->vfptr, HK_ENTITY_ACTIVATION_DO_ACTIVATE);
  }
}

// File Line: 1468
// RVA: 0x9FDD0
void __fastcall UFG::BasePhysicsSystem::AddAction(UFG::BasePhysicsSystem *this, hkpAction *action)
{
  hkpAction *v2; // rdi
  __int64 v3; // rdx
  __int64 v4; // r8
  hkpAction **v5; // rax
  hkArray<hkpAction *,hkContainerHeapAllocator> *v6; // rbx

  v2 = action;
  v3 = this->mActionsToAdd.m_size;
  v4 = 0i64;
  if ( v3 <= 0 )
  {
LABEL_5:
    if ( !v2->m_world )
    {
      v6 = &this->mActionsToAdd;
      if ( this->mActionsToAdd.m_size == (this->mActionsToAdd.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 8);
      v6->m_data[v6->m_size++] = v2;
    }
  }
  else
  {
    v5 = this->mActionsToAdd.m_data;
    while ( *v5 != v2 )
    {
      ++v4;
      ++v5;
      if ( v4 >= v3 )
        goto LABEL_5;
    }
  }
}

// File Line: 1494
// RVA: 0xA02A0
void __fastcall UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem *this, hkpConstraintInstance *constraint)
{
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v2; // rbx
  hkpConstraintInstance *v3; // rdi

  if ( constraint )
  {
    v2 = &this->mConstraintsToAdd;
    v3 = constraint;
    if ( this->mConstraintsToAdd.m_size == (this->mConstraintsToAdd.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
    v2->m_data[v2->m_size++] = v3;
    hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
  }
}

// File Line: 1534
// RVA: 0x9FE50
void __fastcall UFG::BasePhysicsSystem::AddBatchedEntities(UFG::BasePhysicsSystem *this)
{
  UFG::BasePhysicsSystem *v1; // rbx
  signed __int64 v2; // rdi
  char v3; // dl
  __int64 v4; // rax
  char v5; // cl
  char v6; // al
  int v7; // er14
  __int64 v8; // rsi
  hkpEntity **v9; // rdx
  char v10; // cl
  char v11; // dl
  __int64 v12; // rax
  char v13; // cl
  _QWORD **v14; // rax
  hkpEasePenetrationAction *v15; // rax
  hkpAction *v16; // rax
  hkpAction *v17; // rbp
  char v18; // al
  int v19; // er8
  int v20; // edi
  __int64 v21; // rsi
  int v22; // esi
  __int64 v23; // rdi

  v1 = this;
  if ( this->mEntitiesToAdd.m_size > 0 )
  {
    v2 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v3 = ++*(_BYTE *)(v2 + 80);
    v4 = v3;
    *(_DWORD *)(v2 + 4 * v4) = 3;
    *(_QWORD *)(v2 + 8 * v4 + 16) = "addEntityBatch";
    *(_QWORD *)(v2 + 8 * v4 + 48) = 0i64;
    v5 = *(_BYTE *)(v2 + 81);
    if ( v3 > v5 )
      v5 = v3;
    *(_BYTE *)(v2 + 81) = v5;
    hkpWorld::addEntityBatch(
      v1->mWorld,
      v1->mEntitiesToAdd.m_data,
      v1->mEntitiesToAdd.m_size,
      HK_ENTITY_ACTIVATION_DO_ACTIVATE);
    v6 = *(_BYTE *)(v2 + 80);
    if ( v6 > 0 )
    {
      *(_BYTE *)(v2 + 80) = v6 - 1;
    }
    else
    {
      *(_BYTE *)(v2 + 80) = 0;
      *(_DWORD *)v2 = 3;
      *(_QWORD *)(v2 + 16) = 0i64;
      *(_QWORD *)(v2 + 48) = 0i64;
    }
    v7 = 0;
    if ( v1->mEntitiesToAdd.m_size > 0 )
    {
      v8 = 0i64;
      do
      {
        v9 = v1->mEntitiesToAdd.m_data;
        v10 = v9[v8]->m_motion.m_type.m_storage;
        if ( v10 != 5
          && v10 != 4
          && (unsigned int)(v9[v8]->m_collidable.m_broadPhaseHandle.m_objectQualityType - 4) <= 1 )
        {
          v11 = ++*(_BYTE *)(v2 + 80);
          v12 = v11;
          *(_DWORD *)(v2 + 4 * v12) = 3;
          *(_QWORD *)(v2 + 8 * v12 + 16) = "hkpEasePenetrationAction";
          *(_QWORD *)(v2 + 8 * v12 + 48) = 0i64;
          v13 = *(_BYTE *)(v2 + 81);
          if ( v11 > v13 )
            v13 = v11;
          *(_BYTE *)(v2 + 81) = v13;
          v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v15 = (hkpEasePenetrationAction *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(
                                              v14[11],
                                              88i64);
          if ( v15 )
          {
            hkpEasePenetrationAction::hkpEasePenetrationAction(v15, v1->mEntitiesToAdd.m_data[v8], 2.0);
            v17 = v16;
          }
          else
          {
            v17 = 0i64;
          }
          v18 = *(_BYTE *)(v2 + 80);
          if ( v18 > 0 )
          {
            *(_BYTE *)(v2 + 80) = v18 - 1;
          }
          else
          {
            *(_BYTE *)(v2 + 80) = 0;
            *(_DWORD *)v2 = 3;
            *(_QWORD *)(v2 + 16) = 0i64;
            *(_QWORD *)(v2 + 48) = 0i64;
          }
          hkpWorld::addAction(v1->mWorld, v17);
          hkReferencedObject::removeReference((hkReferencedObject *)&v17->vfptr);
        }
        ++v7;
        ++v8;
      }
      while ( v7 < v1->mEntitiesToAdd.m_size );
    }
    v1->mEntitiesToAdd.m_size = 0;
  }
  v19 = v1->mPhantomsToAdd.m_size;
  if ( v19 > 0 )
  {
    hkpWorld::addPhantomBatch(v1->mWorld, v1->mPhantomsToAdd.m_data, v19);
    v1->mPhantomsToAdd.m_size = 0;
  }
  v20 = 0;
  if ( v1->mActionsToAdd.m_size > 0 )
  {
    v21 = 0i64;
    do
    {
      hkpWorld::addAction(v1->mWorld, v1->mActionsToAdd.m_data[v21]);
      ++v20;
      ++v21;
    }
    while ( v20 < v1->mActionsToAdd.m_size );
  }
  v1->mActionsToAdd.m_size = 0;
  v22 = 0;
  if ( v1->mConstraintsToAdd.m_size > 0 )
  {
    v23 = 0i64;
    do
    {
      hkpWorld::addConstraint(v1->mWorld, v1->mConstraintsToAdd.m_data[v23]);
      hkReferencedObject::removeReference((hkReferencedObject *)&v1->mConstraintsToAdd.m_data[v23]->vfptr);
      ++v22;
      ++v23;
    }
    while ( v22 < v1->mConstraintsToAdd.m_size );
  }
  v1->mConstraintsToAdd.m_size = 0;
}[v23]->vfptr);
      ++v22;
      ++v23;
    }
    whi

// File Line: 1605
// RVA: 0xAF890
void __fastcall UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem *this, hkpRigidBody *rb, bool removeBatched)
{
  int v3; // er10
  UFG::BasePhysicsSystem *v4; // rbx
  __int64 v5; // rcx
  hkpRigidBody *v6; // rdi
  __int64 v7; // r9
  hkpRigidBody **v8; // rax
  __int64 v9; // rax
  hkpWorld *v10; // rcx
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v11; // rbx
  hkBool result; // [rsp+30h] [rbp+8h]

  v3 = 0;
  v4 = this;
  v5 = this->mEntitiesToAdd.m_size;
  v6 = rb;
  v7 = 0i64;
  if ( v5 > 0 )
  {
    v8 = (hkpRigidBody **)v4->mEntitiesToAdd.m_data;
    while ( *v8 != rb )
    {
      ++v7;
      ++v3;
      ++v8;
      if ( v7 >= v5 )
        goto LABEL_8;
    }
    v9 = --v4->mEntitiesToAdd.m_size;
    if ( (_DWORD)v9 != v3 )
      v4->mEntitiesToAdd.m_data[v3] = v4->mEntitiesToAdd.m_data[v9];
  }
LABEL_8:
  v10 = rb->m_world;
  if ( v10 )
  {
    if ( removeBatched || v4->mForceRemoveEntitiesToBeBatched )
    {
      v11 = &v4->mEntitiesToRemove;
      if ( v11->m_size == (v11->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v11, 8);
      v11->m_data[v11->m_size++] = (hkpEntity *)&v6->vfptr;
      hkReferencedObject::addReference((hkReferencedObject *)&v6->vfptr);
    }
    else
    {
      hkpWorld::removeEntity(v10, &result, (hkpEntity *)&rb->vfptr);
    }
  }
}

// File Line: 1651
// RVA: 0xAF770
void __fastcall UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem *this, hkpPhantom *p, __int64 removeBatched)
{
  __int64 v3; // r11
  hkpPhantom *v4; // rbx
  __int64 v5; // r9
  __int64 v6; // r10
  __int64 v7; // rax
  __int64 v8; // rdx
  hkpPhantom **v9; // rax
  hkArray<hkpPhantom *,hkContainerHeapAllocator> *v10; // rdi

  v3 = 0i64;
  v4 = p;
  v5 = 0i64;
  if ( this->mPhantomsToAdd.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      if ( this->mPhantomsToAdd.m_data[v6] == p )
      {
        v7 = --this->mPhantomsToAdd.m_size;
        if ( (_DWORD)v7 != (_DWORD)v5 )
          this->mPhantomsToAdd.m_data[v6] = this->mPhantomsToAdd.m_data[v7];
        LODWORD(v5) = v5 - 1;
        --v6;
      }
      v5 = (unsigned int)(v5 + 1);
      ++v6;
    }
    while ( (signed int)v5 < this->mPhantomsToAdd.m_size );
  }
  if ( p->m_world )
  {
    if ( (_BYTE)removeBatched || this->mForceRemoveEntitiesToBeBatched )
    {
      v8 = this->mPhantomsToRemove.m_size;
      if ( v8 <= 0 )
      {
LABEL_16:
        v10 = &this->mPhantomsToRemove;
        if ( this->mPhantomsToRemove.m_size == (this->mPhantomsToRemove.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 8);
        v10->m_data[v10->m_size++] = v4;
        hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
      }
      else
      {
        v9 = this->mPhantomsToRemove.m_data;
        while ( *v9 != v4 )
        {
          ++v3;
          ++v9;
          if ( v3 >= v8 )
            goto LABEL_16;
        }
        UFG::qPrintf("ignoring duplicate call to PhysicsSystem::RemoveEntity(hkpPhantom) %x\n", v4, removeBatched, v5);
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
  __int64 v1; // rsi
  UFG::BasePhysicsSystem *v2; // rbx
  __int64 i; // rdi
  __int64 v4; // rsi
  __int64 j; // rdi

  v1 = this->mEntitiesToRemove.m_size;
  v2 = this;
  this->mForceRemoveEntitiesToBeBatched = 0;
  if ( (_DWORD)v1 )
  {
    hkpWorld::removeEntityBatch(UFG::BasePhysicsSystem::mInstance->mWorld, this->mEntitiesToRemove.m_data, v1);
    for ( i = 0i64; i < v1; ++i )
      hkReferencedObject::removeReference((hkReferencedObject *)&v2->mEntitiesToRemove.m_data[i]->vfptr);
    v2->mEntitiesToRemove.m_size = 0;
  }
  v4 = v2->mPhantomsToRemove.m_size;
  if ( (_DWORD)v4 )
  {
    hkpWorld::removePhantomBatch(UFG::BasePhysicsSystem::mInstance->mWorld, v2->mPhantomsToRemove.m_data, v4);
    for ( j = 0i64; j < v4; ++j )
      hkReferencedObject::removeReference((hkReferencedObject *)&v2->mPhantomsToRemove.m_data[j]->vfptr);
    v2->mPhantomsToRemove.m_size = 0;
  }
}

// File Line: 1774
// RVA: 0xAF5B0
void __fastcall UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem *this, hkpAction *action)
{
  int v2; // eax
  UFG::BasePhysicsSystem *v3; // r10
  __int64 v4; // r9
  hkpAction **v5; // r8
  __int64 v6; // rcx

  v2 = 0;
  v3 = this;
  if ( this->mActionsToAdd.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = v3->mActionsToAdd.m_data;
      if ( v5[v4] == action )
      {
        v6 = --v3->mActionsToAdd.m_size;
        if ( (_DWORD)v6 != v2 )
          v5[v4] = v5[v6];
        --v2;
        --v4;
      }
      ++v2;
      ++v4;
    }
    while ( v2 < v3->mActionsToAdd.m_size );
  }
  JUMPOUT(action->m_world, 0i64, hkpWorld::removeAction);
}

// File Line: 1800
// RVA: 0xAF620
char __fastcall UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem *this, hkpConstraintInstance *constraint)
{
  char v2; // r10
  UFG::BasePhysicsSystem *v3; // r9
  int v4; // eax
  __int64 v5; // r8
  __int64 v6; // rcx
  hkBool result; // [rsp+38h] [rbp+10h]

  v2 = 0;
  v3 = this;
  if ( !constraint )
    return v2;
  v4 = 0;
  if ( this->mConstraintsToAdd.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      if ( v3->mConstraintsToAdd.m_data[v5] == constraint )
      {
        v6 = --v3->mConstraintsToAdd.m_size;
        if ( (_DWORD)v6 != v4 )
          v3->mConstraintsToAdd.m_data[v5] = v3->mConstraintsToAdd.m_data[v6];
        --v4;
        v2 = 1;
        --v5;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < v3->mConstraintsToAdd.m_size );
  }
  if ( !constraint->m_owner )
    return v2;
  hkpWorld::removeConstraint(v3->mWorld, &result, constraint);
  return 1;
}

// File Line: 1842
// RVA: 0xAFE20
bool __fastcall UFG::BasePhysicsSystem::RequestAnotherRigidBody(UFG::BasePhysicsSystem *this)
{
  return UFG::RigidBody::mCount < UFG::BasePhysicsSystem::mParam.maxLoadedBodies;
}


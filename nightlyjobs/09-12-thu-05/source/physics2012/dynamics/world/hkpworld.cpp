// File Line: 127
// RVA: 0xD556F0
void __fastcall hkpMultithreadConfig::hkpMultithreadConfig(hkpMultithreadConfig *this)
{
  this->m_maxNumConstraintsSolvedSingleThreaded = 70;
}

// File Line: 137
// RVA: 0xD5DA10
void __fastcall hkpWorld::hkpWorld(hkpWorld *this, hkFinishLoadedObjectFlag flag)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpWorld::`vftable;
  this->m_activeSimulationIslands.m_data = 0i64;
  this->m_activeSimulationIslands.m_size = 0;
  this->m_activeSimulationIslands.m_capacityAndFlags = 2147483648;
  this->m_inactiveSimulationIslands.m_data = 0i64;
  this->m_inactiveSimulationIslands.m_size = 0;
  this->m_inactiveSimulationIslands.m_capacityAndFlags = 2147483648;
  this->m_dirtySimulationIslands.m_data = 0i64;
  this->m_dirtySimulationIslands.m_size = 0;
  this->m_dirtySimulationIslands.m_capacityAndFlags = 2147483648;
  this->m_memoryWatchDog.m_pntr = 0i64;
  this->m_multiThreadCheck.m_threadId = -15;
  this->m_multiThreadCheck.m_markCount = -32768;
  this->m_actionListeners.m_data = 0i64;
  this->m_actionListeners.m_size = 0;
  this->m_actionListeners.m_capacityAndFlags = 2147483648;
  this->m_entityListeners.m_data = 0i64;
  this->m_entityListeners.m_size = 0;
  this->m_entityListeners.m_capacityAndFlags = 2147483648;
  this->m_phantomListeners.m_data = 0i64;
  this->m_phantomListeners.m_size = 0;
  this->m_phantomListeners.m_capacityAndFlags = 2147483648;
  this->m_constraintListeners.m_data = 0i64;
  this->m_constraintListeners.m_size = 0;
  this->m_constraintListeners.m_capacityAndFlags = 2147483648;
  this->m_worldDeletionListeners.m_data = 0i64;
  this->m_worldDeletionListeners.m_size = 0;
  this->m_worldDeletionListeners.m_capacityAndFlags = 2147483648;
  this->m_islandActivationListeners.m_data = 0i64;
  this->m_islandActivationListeners.m_size = 0;
  this->m_islandActivationListeners.m_capacityAndFlags = 2147483648;
  this->m_worldPostSimulationListeners.m_data = 0i64;
  this->m_worldPostSimulationListeners.m_size = 0;
  this->m_worldPostSimulationListeners.m_capacityAndFlags = 2147483648;
  this->m_worldPostIntegrateListeners.m_data = 0i64;
  this->m_worldPostIntegrateListeners.m_size = 0;
  this->m_worldPostIntegrateListeners.m_capacityAndFlags = 2147483648;
  this->m_worldPostCollideListeners.m_data = 0i64;
  this->m_worldPostCollideListeners.m_size = 0;
  this->m_worldPostCollideListeners.m_capacityAndFlags = 2147483648;
  this->m_islandPostIntegrateListeners.m_data = 0i64;
  this->m_islandPostIntegrateListeners.m_size = 0;
  this->m_islandPostIntegrateListeners.m_capacityAndFlags = 2147483648;
  this->m_islandPostCollideListeners.m_data = 0i64;
  this->m_islandPostCollideListeners.m_size = 0;
  this->m_islandPostCollideListeners.m_capacityAndFlags = 2147483648;
  this->m_contactListeners.m_data = 0i64;
  this->m_contactListeners.m_size = 0;
  this->m_contactListeners.m_capacityAndFlags = 2147483648;
  this->m_contactImpulseLimitBreachedListeners.m_data = 0i64;
  this->m_contactImpulseLimitBreachedListeners.m_size = 0;
  this->m_contactImpulseLimitBreachedListeners.m_capacityAndFlags = 2147483648;
  this->m_worldExtensions.m_data = 0i64;
  this->m_worldExtensions.m_size = 0;
  this->m_worldExtensions.m_capacityAndFlags = 2147483648;
}

// File Line: 141
// RVA: 0xD5D3C0
void __fastcall hkpWorld::removeAll(hkpWorld *this)
{
  hkpWorld *v1; // rbx
  int v2; // edi
  int v3; // esi
  hkpSimulationIsland *v4; // rax
  signed __int64 v5; // r10
  int v6; // er9
  signed __int64 v7; // r8
  hkpSimulationIsland **v8; // rcx
  unsigned __int64 v9; // rdx
  hkpSimulationIsland *v10; // rax
  int v11; // eax
  signed __int64 v12; // rdi
  int v13; // er8
  int v14; // er9
  int v15; // er10
  signed __int64 v16; // r11
  hkpSimulationIsland **v17; // rcx
  unsigned __int64 v18; // rdx
  hkpSimulationIsland *v19; // rax
  int v20; // er9
  int v21; // esi
  __int64 v22; // rdi
  int v23; // edi
  __int64 v24; // rsi
  hkpSimulationIsland *v25; // r10
  signed int v26; // edi
  __int64 v27; // rdx
  __int64 v28; // rcx
  hkpRigidBody **v29; // rax
  int v30; // edi
  int v31; // er8
  hkpSimulationIsland *v32; // rcx
  hkpEntity **array; // [rsp+30h] [rbp-18h]
  int numEntities; // [rsp+38h] [rbp-10h]
  int v35; // [rsp+3Ch] [rbp-Ch]
  hkResult result; // [rsp+50h] [rbp+8h]

  v1 = this;
  v2 = 0;
  v3 = 0;
  hkpWorld::removePhantomBatch(this, this->m_phantoms.m_data, this->m_phantoms.m_size);
  v4 = v1->m_fixedIsland;
  v5 = v1->m_activeSimulationIslands.m_size;
  array = 0i64;
  numEntities = 0;
  v35 = 2147483648;
  v6 = v4->m_entities.m_size;
  v7 = 0i64;
  if ( v5 >= 2 )
  {
    v8 = v1->m_activeSimulationIslands.m_data;
    v9 = ((unsigned __int64)(v5 - 2) >> 1) + 1;
    v7 = 2 * v9;
    do
    {
      v10 = *v8;
      v8 += 2;
      v2 += v10->m_entities.m_size;
      v3 += (*(v8 - 1))->m_entities.m_size;
      --v9;
    }
    while ( v9 );
  }
  if ( v7 < v5 )
    v6 += v1->m_activeSimulationIslands.m_data[v7]->m_entities.m_size;
  v11 = v2 + v3;
  v12 = v1->m_inactiveSimulationIslands.m_size;
  v13 = 0;
  v14 = v11 + v6;
  v15 = 0;
  v16 = 0i64;
  if ( v12 >= 2 )
  {
    v17 = v1->m_inactiveSimulationIslands.m_data;
    v18 = ((unsigned __int64)(v12 - 2) >> 1) + 1;
    v16 = 2 * v18;
    do
    {
      v19 = *v17;
      v17 += 2;
      v13 += v19->m_entities.m_size;
      v15 += (*(v17 - 1))->m_entities.m_size;
      --v18;
    }
    while ( v18 );
  }
  if ( v16 < v12 )
    v14 += v1->m_inactiveSimulationIslands.m_data[v16]->m_entities.m_size;
  v20 = v13 + v15 + v14;
  if ( v20 > 0 )
  {
    if ( v20 < 0 )
      v20 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v20, 8);
  }
  v21 = 0;
  if ( v1->m_activeSimulationIslands.m_size > 0 )
  {
    v22 = 0i64;
    do
    {
      hkArrayBase<unsigned __int64>::_append(
        (hkArrayBase<char *> *)&array,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        (char *const *)v1->m_activeSimulationIslands.m_data[v22]->m_entities.m_data,
        v1->m_activeSimulationIslands.m_data[v22]->m_entities.m_size);
      ++v21;
      ++v22;
    }
    while ( v21 < v1->m_activeSimulationIslands.m_size );
  }
  v23 = 0;
  if ( v1->m_inactiveSimulationIslands.m_size > 0 )
  {
    v24 = 0i64;
    do
    {
      hkArrayBase<unsigned __int64>::_append(
        (hkArrayBase<char *> *)&array,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        (char *const *)v1->m_inactiveSimulationIslands.m_data[v24]->m_entities.m_data,
        v1->m_inactiveSimulationIslands.m_data[v24]->m_entities.m_size);
      ++v23;
      ++v24;
    }
    while ( v23 < v1->m_inactiveSimulationIslands.m_size );
  }
  v25 = v1->m_fixedIsland;
  v26 = 0;
  v27 = v25->m_entities.m_size;
  v28 = 0i64;
  if ( v27 <= 0 )
  {
LABEL_25:
    v26 = -1;
  }
  else
  {
    v29 = (hkpRigidBody **)v25->m_entities.m_data;
    while ( *v29 != v1->m_fixedRigidBody )
    {
      ++v28;
      ++v26;
      ++v29;
      if ( v28 >= v27 )
        goto LABEL_25;
    }
  }
  v30 = numEntities + v26;
  hkArrayBase<unsigned __int64>::_append(
    (hkArrayBase<char *> *)&array,
    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
    (char *const *)v25->m_entities.m_data,
    v25->m_entities.m_size);
  v31 = numEntities - 1;
  numEntities = v31;
  if ( v31 != v30 )
  {
    array[v30] = array[v31];
    v31 = numEntities;
  }
  hkpWorld::removeEntityBatch(v1, array, v31);
  numEntities = 0;
  if ( v35 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      8 * v35);
  if ( !v1->m_wantSimulationIslands.m_bool )
  {
    hkpWorldOperationUtil::removeIslandFromDirtyList(
      v1,
      v1->m_activeSimulationIslands.m_data[v1->m_activeSimulationIslands.m_size - 1]);
    v32 = v1->m_activeSimulationIslands.m_data[v1->m_activeSimulationIslands.m_size - 1];
    if ( v32 )
      v32->vfptr->__vecDelDtor((hkBaseObject *)&v32->vfptr, 1u);
    --v1->m_activeSimulationIslands.m_size;
  }
  hkpWorldCallbackUtil::fireWorldRemoveAll(v1);
}

// File Line: 212
// RVA: 0xD5CB30
void __fastcall hkpWorld::~hkpWorld(hkpWorld *this)
{
  hkpMtThreadStructure *v1; // rdi
  hkpWorld *v2; // rbx
  _QWORD **v3; // rax
  _QWORD **v4; // rax
  _RTL_CRITICAL_SECTION *v5; // rdi
  _QWORD **v6; // rax
  hkCriticalSection *v7; // rdi
  _QWORD **v8; // rax
  hkReferencedObject *v9; // rcx
  hkpSimulationIsland *v10; // rdx
  hkpSimulationIsland *v11; // rcx
  _RTL_CRITICAL_SECTION *v12; // rdi
  _QWORD **v13; // rax
  __int64 v14; // rbp
  __int64 i; // rsi
  hkReferencedObject *v16; // rdi
  hkReferencedObject *v17; // rcx
  hkpTypedBroadPhaseDispatcher *v18; // rdi
  _QWORD **v19; // rax
  hkReferencedObject *v20; // rcx
  hkpPhantomBroadPhaseListener *v21; // rcx
  hkpEntityEntityBroadPhaseListener *v22; // rcx
  hkpBroadPhaseBorderListener *v23; // rcx
  hkpCollisionAgentConfig *v24; // rdi
  _QWORD **v25; // rax
  hkpProcessCollisionInput *v26; // rdi
  _QWORD **v27; // rax
  _QWORD **v28; // rax
  hkpWorldOperationQueue *v29; // rdi
  _QWORD **v30; // rax
  hkpViolatedConstraintArray *v31; // rdi
  _QWORD **v32; // rax
  int v33; // er8
  int v34; // er8
  int v35; // er8
  int v36; // er8
  int v37; // er8
  int v38; // er8
  int v39; // er8
  int v40; // er8
  int v41; // er8
  int v42; // er8
  int v43; // er8
  int v44; // er8
  int v45; // er8
  int v46; // er8
  int v47; // er8
  hkReferencedObject *v48; // rcx
  int v49; // er8
  int v50; // er8
  int v51; // er8
  hkBool result; // [rsp+40h] [rbp+8h]

  v1 = this->m_multithreadedSimulationJobData;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpWorld::`vftable;
  if ( v1 )
  {
    if ( v1->m_collisionInput.m_spareAgentSector )
    {
      v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, signed __int64))(*v3[11] + 16i64))(
        v3[11],
        v1->m_collisionInput.m_spareAgentSector,
        512i64);
    }
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpMtThreadStructure *, signed __int64))(*v4[11] + 16i64))(v4[11], v1, 352i64);
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_maintenanceMgr->vfptr);
  v5 = &v2->m_modifyConstraintCriticalSection->m_section;
  v2->m_maintenanceMgr = 0i64;
  if ( v5 )
  {
    DeleteCriticalSection(v5);
    v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, _RTL_CRITICAL_SECTION *, signed __int64))(*v6[11] + 16i64))(v6[11], v5, 40i64);
    v2->m_modifyConstraintCriticalSection = 0i64;
  }
  v7 = v2->m_propertyMasterLock;
  if ( v7 )
  {
    DeleteCriticalSection(&v2->m_propertyMasterLock->m_section);
    v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkCriticalSection *, signed __int64))(*v8[11] + 16i64))(v8[11], v7, 40i64);
    v2->m_propertyMasterLock = 0i64;
  }
  v9 = (hkReferencedObject *)&v2->m_memoryWatchDog.m_pntr->vfptr;
  if ( v9 )
    hkReferencedObject::removeReference(v9);
  v2->m_memoryWatchDog.m_pntr = 0i64;
  hkpWorld::removeAll(v2);
  hkpWorld::removeEntity(v2, &result, (hkpEntity *)&v2->m_fixedRigidBody->vfptr);
  v10 = v2->m_fixedIsland;
  v2->m_fixedRigidBody = 0i64;
  hkpWorldOperationUtil::removeIslandFromDirtyList(v2, v10);
  v11 = v2->m_fixedIsland;
  if ( v11 )
    v11->vfptr->__vecDelDtor((hkBaseObject *)&v11->vfptr, 1u);
  v12 = &v2->m_islandDirtyListCriticalSection->m_section;
  v2->m_fixedIsland = 0i64;
  if ( v12 )
  {
    DeleteCriticalSection(v12);
    v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, _RTL_CRITICAL_SECTION *, signed __int64))(*v13[11] + 16i64))(v13[11], v12, 40i64);
    v2->m_islandDirtyListCriticalSection = 0i64;
  }
  v14 = v2->m_worldExtensions.m_size;
  for ( i = 0i64; i < v14; ++i )
  {
    v16 = (hkReferencedObject *)&v2->m_worldExtensions.m_data[i]->vfptr;
    v16->vfptr[2].__vecDelDtor((hkBaseObject *)&v16->vfptr, (unsigned int)v2);
    v16[1].vfptr = 0i64;
    hkReferencedObject::removeReference(v16);
  }
  hkpWorldCallbackUtil::fireWorldDeleted(v2);
  hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_broadPhase->vfptr);
  v17 = (hkReferencedObject *)&v2->m_collisionDispatcher->vfptr;
  v2->m_broadPhase = 0i64;
  hkReferencedObject::removeReference(v17);
  v18 = v2->m_broadPhaseDispatcher;
  v2->m_collisionDispatcher = 0i64;
  if ( v18 )
  {
    hkpTypedBroadPhaseDispatcher::~hkpTypedBroadPhaseDispatcher(v18);
    v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpTypedBroadPhaseDispatcher *, signed __int64))(*v19[11] + 16i64))(
      v19[11],
      v18,
      536i64);
  }
  v20 = (hkReferencedObject *)&v2->m_broadPhaseBorder->vfptr;
  if ( v20 )
    hkReferencedObject::removeReference(v20);
  v21 = v2->m_phantomBroadPhaseListener;
  if ( v21 )
    v21->vfptr->__vecDelDtor((hkBaseObject *)&v21->vfptr, 1u);
  v22 = v2->m_entityEntityBroadPhaseListener;
  if ( v22 )
    v22->vfptr->__vecDelDtor((hkBaseObject *)&v22->vfptr, 1u);
  v23 = v2->m_broadPhaseBorderListener;
  if ( v23 )
    v23->vfptr->__vecDelDtor((hkBaseObject *)&v23->vfptr, 1u);
  hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_collisionFilter->vfptr);
  hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_convexListFilter->vfptr);
  v24 = v2->m_collisionInput->m_config;
  if ( v24 )
  {
    v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpCollisionAgentConfig *, signed __int64))(*v25[11] + 16i64))(
      v25[11],
      v24,
      16i64);
  }
  v26 = v2->m_collisionInput;
  if ( v26 )
  {
    if ( v26->m_spareAgentSector )
    {
      v27 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, signed __int64))(*v27[11] + 16i64))(
        v27[11],
        v26->m_spareAgentSector,
        512i64);
    }
    v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpProcessCollisionInput *, signed __int64))(*v28[11] + 16i64))(
      v28[11],
      v26,
      160i64);
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_simulation->vfptr);
  v29 = v2->m_pendingOperations;
  if ( v29 )
  {
    hkpWorldOperationQueue::~hkpWorldOperationQueue(v2->m_pendingOperations);
    v30 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpWorldOperationQueue *, signed __int64))(*v30[11] + 16i64))(v30[11], v29, 56i64);
  }
  v31 = v2->m_violatedConstraintArray;
  if ( v31 )
  {
    v32 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpViolatedConstraintArray *, signed __int64))(*v32[11] + 16i64))(
      v32[11],
      v31,
      1032i64);
  }
  v33 = v2->m_worldExtensions.m_capacityAndFlags;
  v2->m_worldExtensions.m_size = 0;
  if ( v33 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_worldExtensions.m_data,
      8 * v33);
  v2->m_worldExtensions.m_data = 0i64;
  v2->m_worldExtensions.m_capacityAndFlags = 2147483648;
  v34 = v2->m_contactImpulseLimitBreachedListeners.m_capacityAndFlags;
  v2->m_contactImpulseLimitBreachedListeners.m_size = 0;
  if ( v34 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_contactImpulseLimitBreachedListeners.m_data,
      8 * v34);
  v2->m_contactImpulseLimitBreachedListeners.m_data = 0i64;
  v2->m_contactImpulseLimitBreachedListeners.m_capacityAndFlags = 2147483648;
  v35 = v2->m_contactListeners.m_capacityAndFlags;
  v2->m_contactListeners.m_size = 0;
  if ( v35 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_contactListeners.m_data,
      8 * v35);
  v2->m_contactListeners.m_data = 0i64;
  v2->m_contactListeners.m_capacityAndFlags = 2147483648;
  v36 = v2->m_islandPostCollideListeners.m_capacityAndFlags;
  v2->m_islandPostCollideListeners.m_size = 0;
  if ( v36 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_islandPostCollideListeners.m_data,
      8 * v36);
  v2->m_islandPostCollideListeners.m_data = 0i64;
  v2->m_islandPostCollideListeners.m_capacityAndFlags = 2147483648;
  v37 = v2->m_islandPostIntegrateListeners.m_capacityAndFlags;
  v2->m_islandPostIntegrateListeners.m_size = 0;
  if ( v37 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_islandPostIntegrateListeners.m_data,
      8 * v37);
  v2->m_islandPostIntegrateListeners.m_data = 0i64;
  v2->m_islandPostIntegrateListeners.m_capacityAndFlags = 2147483648;
  v38 = v2->m_worldPostCollideListeners.m_capacityAndFlags;
  v2->m_worldPostCollideListeners.m_size = 0;
  if ( v38 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_worldPostCollideListeners.m_data,
      8 * v38);
  v2->m_worldPostCollideListeners.m_data = 0i64;
  v2->m_worldPostCollideListeners.m_capacityAndFlags = 2147483648;
  v39 = v2->m_worldPostIntegrateListeners.m_capacityAndFlags;
  v2->m_worldPostIntegrateListeners.m_size = 0;
  if ( v39 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_worldPostIntegrateListeners.m_data,
      8 * v39);
  v2->m_worldPostIntegrateListeners.m_data = 0i64;
  v2->m_worldPostIntegrateListeners.m_capacityAndFlags = 2147483648;
  v40 = v2->m_worldPostSimulationListeners.m_capacityAndFlags;
  v2->m_worldPostSimulationListeners.m_size = 0;
  if ( v40 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_worldPostSimulationListeners.m_data,
      8 * v40);
  v2->m_worldPostSimulationListeners.m_data = 0i64;
  v2->m_worldPostSimulationListeners.m_capacityAndFlags = 2147483648;
  v41 = v2->m_islandActivationListeners.m_capacityAndFlags;
  v2->m_islandActivationListeners.m_size = 0;
  if ( v41 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_islandActivationListeners.m_data,
      8 * v41);
  v2->m_islandActivationListeners.m_data = 0i64;
  v2->m_islandActivationListeners.m_capacityAndFlags = 2147483648;
  v42 = v2->m_worldDeletionListeners.m_capacityAndFlags;
  v2->m_worldDeletionListeners.m_size = 0;
  if ( v42 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_worldDeletionListeners.m_data,
      8 * v42);
  v2->m_worldDeletionListeners.m_data = 0i64;
  v2->m_worldDeletionListeners.m_capacityAndFlags = 2147483648;
  v43 = v2->m_constraintListeners.m_capacityAndFlags;
  v2->m_constraintListeners.m_size = 0;
  if ( v43 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_constraintListeners.m_data,
      8 * v43);
  v2->m_constraintListeners.m_data = 0i64;
  v2->m_constraintListeners.m_capacityAndFlags = 2147483648;
  v44 = v2->m_phantomListeners.m_capacityAndFlags;
  v2->m_phantomListeners.m_size = 0;
  if ( v44 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_phantomListeners.m_data,
      8 * v44);
  v2->m_phantomListeners.m_data = 0i64;
  v2->m_phantomListeners.m_capacityAndFlags = 2147483648;
  v45 = v2->m_entityListeners.m_capacityAndFlags;
  v2->m_entityListeners.m_size = 0;
  if ( v45 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_entityListeners.m_data,
      8 * v45);
  v2->m_entityListeners.m_data = 0i64;
  v2->m_entityListeners.m_capacityAndFlags = 2147483648;
  v46 = v2->m_actionListeners.m_capacityAndFlags;
  v2->m_actionListeners.m_size = 0;
  if ( v46 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_actionListeners.m_data,
      8 * v46);
  v2->m_actionListeners.m_data = 0i64;
  v2->m_actionListeners.m_capacityAndFlags = 2147483648;
  v47 = v2->m_phantoms.m_capacityAndFlags;
  v2->m_phantoms.m_size = 0;
  if ( v47 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_phantoms.m_data,
      8 * v47);
  v2->m_phantoms.m_data = 0i64;
  v2->m_phantoms.m_capacityAndFlags = 2147483648;
  v48 = (hkReferencedObject *)&v2->m_memoryWatchDog.m_pntr->vfptr;
  if ( v48 )
    hkReferencedObject::removeReference(v48);
  v2->m_memoryWatchDog.m_pntr = 0i64;
  v49 = v2->m_dirtySimulationIslands.m_capacityAndFlags;
  v2->m_dirtySimulationIslands.m_size = 0;
  if ( v49 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_dirtySimulationIslands.m_data,
      8 * v49);
  v2->m_dirtySimulationIslands.m_data = 0i64;
  v2->m_dirtySimulationIslands.m_capacityAndFlags = 2147483648;
  v50 = v2->m_inactiveSimulationIslands.m_capacityAndFlags;
  v2->m_inactiveSimulationIslands.m_size = 0;
  if ( v50 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_inactiveSimulationIslands.m_data,
      8 * v50);
  v2->m_inactiveSimulationIslands.m_data = 0i64;
  v2->m_inactiveSimulationIslands.m_capacityAndFlags = 2147483648;
  v51 = v2->m_activeSimulationIslands.m_capacityAndFlags;
  v2->m_activeSimulationIslands.m_size = 0;
  if ( v51 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_activeSimulationIslands.m_data,
      8 * v51);
  v2->m_activeSimulationIslands.m_data = 0i64;
  v2->m_activeSimulationIslands.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 304
// RVA: 0xD5DBC0
void __fastcall hkWorld_setupContactMgrFactories(hkpWorld *world, hkpCollisionDispatcher *dis)
{
  hkpWorld *v2; // rbx
  hkpCollisionDispatcher *v3; // rbp
  _QWORD **v4; // rax
  hkpSimpleConstraintContactMgr::Factory *v5; // rax
  hkpContactMgrFactory *v6; // rax
  hkpContactMgrFactory *v7; // rsi
  _QWORD **v8; // rax
  hkpReportContactMgr::Factory *v9; // rax
  hkpContactMgrFactory *v10; // rax
  hkpContactMgrFactory *v11; // rdi
  _QWORD **v12; // rax
  __int64 v13; // rax
  hkpContactMgrFactory *v14; // rbx

  v2 = world;
  v3 = dis;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkpSimpleConstraintContactMgr::Factory *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(
                                                   v4[11],
                                                   24i64);
  if ( v5 )
  {
    hkpSimpleConstraintContactMgr::Factory::Factory(v5, v2);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpReportContactMgr::Factory *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(
                                         v8[11],
                                         24i64);
  if ( v9 )
  {
    hkpReportContactMgr::Factory::Factory(v9, v2);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(v12[11], 40i64);
  v14 = (hkpContactMgrFactory *)v13;
  if ( v13 )
  {
    *(_DWORD *)(v13 + 8) = 0x1FFFF;
    *(_QWORD *)v13 = &hkpNullContactMgrFactory::`vftable;
    *(_DWORD *)(v13 + 24) = 0x1FFFF;
    *(_QWORD *)(v13 + 16) = &hkpNullContactMgr::`vftable;
    *(_DWORD *)(v13 + 32) = 3;
  }
  else
  {
    v14 = 0i64;
  }
  hkpCollisionDispatcher::registerContactMgrFactoryWithAll(v3, v7, 1);
  hkpCollisionDispatcher::registerContactMgrFactoryWithAll(v3, v11, 2);
  hkpCollisionDispatcher::registerContactMgrFactoryWithAll(v3, v14, 3);
  hkReferencedObject::removeReference((hkReferencedObject *)&v7->vfptr);
  hkReferencedObject::removeReference((hkReferencedObject *)&v11->vfptr);
  hkReferencedObject::removeReference((hkReferencedObject *)&v14->vfptr);
}

// File Line: 324
// RVA: 0xD59E80
void __fastcall hkpWorld::updateCollisionFilterOnWorld(hkpWorld *this, hkpUpdateCollisionFilterOnWorldMode updateMode, hkpUpdateCollectionFilterMode updateShapeCollectionFilter)
{
  __int64 v3; // r12
  hkpUpdateCollisionFilterOnWorldMode v4; // ebx
  hkpWorld *v5; // r13
  _QWORD *v6; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  signed __int64 v9; // rcx
  int v10; // edi
  int v11; // er14
  __int64 v12; // r15
  hkpSimulationIsland *v13; // rsi
  __int64 v14; // rbx
  int v15; // er14
  __int64 v16; // r15
  hkpSimulationIsland *v17; // rsi
  __int64 v18; // rbx
  __int64 v19; // rbx
  __int64 *v20; // rdi
  signed __int64 v21; // rsi
  __int64 v22; // rax
  signed __int64 v23; // rdx
  __int64 v24; // rdi
  signed __int64 v25; // rax
  unsigned __int16 *v26; // r15
  int v27; // edx
  int v28; // eax
  int v29; // er14
  __int64 v30; // rcx
  hkpAgentNnEntry *v31; // rbx
  unsigned __int64 v32; // rsi
  hkpCollisionDispatcher *v33; // rax
  signed __int64 v34; // rdx
  int v35; // ecx
  hkpAgentNnEntry *v36; // rcx
  bool v37; // zf
  _QWORD *v38; // r8
  _QWORD *v39; // rcx
  unsigned __int64 v40; // rax
  signed __int64 v41; // rcx
  signed __int64 v42; // [rsp+20h] [rbp-E0h]
  __int64 *v43; // [rsp+28h] [rbp-D8h]
  __int64 v44; // [rsp+30h] [rbp-D0h]
  signed __int64 v45; // [rsp+38h] [rbp-C8h]
  __int64 v46; // [rsp+40h] [rbp-C0h]
  __int64 v47; // [rsp+48h] [rbp-B8h]
  __int64 v48; // [rsp+50h] [rbp-B0h]
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *v49; // [rsp+58h] [rbp-A8h]
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *v50; // [rsp+60h] [rbp-A0h]
  char *array; // [rsp+70h] [rbp-90h]
  int v52; // [rsp+78h] [rbp-88h]
  int v53; // [rsp+7Ch] [rbp-84h]
  char v54; // [rsp+80h] [rbp-80h]
  hkWorldOperation::BaseOperation operation; // [rsp+1C0h] [rbp+C0h]
  char v56; // [rsp+1C1h] [rbp+C1h]
  char v57; // [rsp+1C2h] [rbp+C2h]
  int v58; // [rsp+1D8h] [rbp+D8h]

  v3 = (unsigned int)updateShapeCollectionFilter;
  v4 = updateMode;
  v5 = this;
  if ( this->m_criticalOperationsLockCount )
  {
    v56 = updateMode;
    operation.m_type.m_storage = 22;
    v57 = updateShapeCollectionFilter;
    hkpWorld::queueOperation(this, &operation);
  }
  else
  {
    this->m_blockExecutingPendingOperations.m_bool = 1;
    v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v7 = (_QWORD *)v6[1];
    if ( (unsigned __int64)v7 < v6[3] )
    {
      *v7 = "TtUpdateFilterOnWorld";
      v8 = __rdtsc();
      v9 = (signed __int64)(v7 + 2);
      *(_DWORD *)(v9 - 8) = v8;
      v6[1] = v9;
    }
    if ( v4 )
    {
      ++v5->m_criticalOperationsLockCount;
      v20 = (__int64 *)&v49;
      v49 = &v5->m_activeSimulationIslands;
      v21 = 2i64;
      v43 = (__int64 *)&v49;
      v50 = &v5->m_inactiveSimulationIslands;
      v42 = 2i64;
      do
      {
        v52 = 0;
        v53 = -2147483616;
        array = &v54;
        v22 = *v20;
        v58 = 0;
        if ( *(_DWORD *)(v22 + 8) > 0 )
        {
          v23 = 0i64;
          v44 = 0i64;
          do
          {
            v45 = 0i64;
            v24 = *(_QWORD *)(v23 + *(_QWORD *)v22);
            v47 = v24 + 152;
            v48 = v24 + 120;
            v25 = 0i64;
            do
            {
              v26 = (unsigned __int16 *)*(&v47 + v25);
              v52 = 0;
              v27 = 0;
              v28 = *((_DWORD *)v26 + 4);
              v29 = 0;
              if ( v28 > 0 )
              {
                v30 = 0i64;
                do
                {
                  v30 += 8i64;
                  ++v29;
                  v31 = *(hkpAgentNnEntry **)(v30 + *((_QWORD *)v26 + 1) - 8);
                  v46 = v30;
                  if ( v29 == v28 )
                    v32 = (unsigned __int64)v31 + *v26;
                  else
                    v32 = (unsigned __int64)&v31[24];
                  if ( (unsigned __int64)v31 < v32 )
                  {
                    do
                    {
                      if ( *(_BYTE *)v5->m_collisionFilter->vfptr->isCollisionEnabled(
                                       (hkpCollidableCollidableFilter *)&v5->m_collisionFilter->vfptr,
                                       (hkBool *)&operation,
                                       (hkpCollidable *)&v31->m_collidable[0]->m_shape,
                                       (hkpCollidable *)&v31->m_collidable[1]->m_shape)
                        && (v33 = v5->m_collisionDispatcher,
                            v34 = v31->m_collidable[1]->m_broadPhaseHandle.m_objectQualityType
                                + 10i64 * v31->m_collidable[0]->m_broadPhaseHandle.m_objectQualityType,
                            v33->m_collisionQualityTable[0][v34])
                        && v33->m_collisionQualityTable[0][v34] == (unsigned __int8)v31->m_collisionQualityIndex )
                      {
                        if ( (_DWORD)v3 == 1 )
                          hkAgentNnMachine_UpdateShapeCollectionFilter(
                            v31,
                            (hkpCollisionInput *)&v5->m_collisionInput->m_dispatcher,
                            (hkpConstraintOwner *)v24,
                            v3);
                      }
                      else
                      {
                        v35 = v52;
                        if ( v52 == (v53 & 0x3FFFFFFF) )
                        {
                          hkArrayUtil::_reserveMore(
                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                            &array,
                            8);
                          v35 = v52;
                        }
                        *(_QWORD *)&array[8 * v35] = v31;
                        ++v52;
                        *(_BYTE *)(v24 + 49) &= 0xFDu;
                        *(_BYTE *)(v24 + 49) |= 1u;
                      }
                      v31 = (hkpAgentNnEntry *)((char *)v31 + (unsigned __int8)v31->m_size);
                    }
                    while ( (unsigned __int64)v31 < v32 );
                    v27 = v52;
                    v30 = v46;
                  }
                  v28 = *((_DWORD *)v26 + 4);
                }
                while ( v29 < v28 );
              }
              v25 = v45 + 1;
              v45 = v25;
            }
            while ( v25 < 2 );
            if ( v27 )
            {
              do
              {
                v36 = *(hkpAgentNnEntry **)&array[8 * v27 - 8];
                v52 = v27 - 1;
                hkpWorldAgentUtil::removeAgentAndItsToiEvents(v36);
                v27 = v52;
              }
              while ( v52 );
            }
            v20 = v43;
            v22 = *v43;
            v23 = v44 + 8;
            ++v58;
            v44 += 8i64;
          }
          while ( v58 < *(_DWORD *)(v22 + 8) );
          v21 = v42;
        }
        v52 = 0;
        if ( v53 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            array,
            8 * v53);
        ++v20;
        v42 = --v21;
        v43 = v20;
      }
      while ( v21 );
      --v5->m_criticalOperationsLockCount;
    }
    else
    {
      v10 = 0;
      v11 = 0;
      if ( v5->m_activeSimulationIslands.m_size > 0 )
      {
        v12 = 0i64;
        do
        {
          v13 = v5->m_activeSimulationIslands.m_data[v12];
          if ( v13->m_entities.m_size > 0 )
          {
            v14 = 0i64;
            do
            {
              hkpWorld::updateCollisionFilterOnEntity(
                v5,
                v13->m_entities.m_data[v14],
                0,
                (hkpUpdateCollectionFilterMode)v3);
              ++v10;
              ++v14;
            }
            while ( v10 < v13->m_entities.m_size );
          }
          ++v11;
          ++v12;
          v10 = 0;
        }
        while ( v11 < v5->m_activeSimulationIslands.m_size );
      }
      v15 = 0;
      if ( v5->m_inactiveSimulationIslands.m_size > 0 )
      {
        v16 = 0i64;
        do
        {
          v17 = v5->m_inactiveSimulationIslands.m_data[v16];
          if ( v17->m_entities.m_size > 0 )
          {
            v18 = 0i64;
            do
            {
              hkpWorld::updateCollisionFilterOnEntity(
                v5,
                v17->m_entities.m_data[v18],
                0,
                (hkpUpdateCollectionFilterMode)v3);
              ++v10;
              ++v18;
            }
            while ( v10 < v17->m_entities.m_size );
          }
          ++v15;
          ++v16;
          v10 = 0;
        }
        while ( v15 < v5->m_inactiveSimulationIslands.m_size );
      }
      if ( v5->m_phantoms.m_size > 0 )
      {
        v19 = 0i64;
        do
        {
          hkpWorld::updateCollisionFilterOnPhantom(v5, v5->m_phantoms.m_data[v19], (hkpUpdateCollectionFilterMode)v3);
          ++v10;
          ++v19;
        }
        while ( v10 < v5->m_phantoms.m_size );
      }
    }
    v37 = v5->m_criticalOperationsLockCount == 0;
    v5->m_blockExecutingPendingOperations.m_bool = 0;
    if ( v37 )
    {
      if ( v5->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v5);
      if ( v5->m_pendingOperationQueueCount == 1 && v5->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v5);
    }
    v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v39 = (_QWORD *)v38[1];
    if ( (unsigned __int64)v39 < v38[3] )
    {
      *v39 = "Et";
      v40 = __rdtsc();
      v41 = (signed __int64)(v39 + 2);
      *(_DWORD *)(v41 - 8) = v40;
      v38[1] = v41;
    }
  }
}

// File Line: 476
// RVA: 0xD5DD00
void __fastcall hkWorld_updateFilterOnSinglePhantom(hkpPhantom *phantom, hkpCollidable *collidable, hkpCollisionFilter *filter)
{
  hkpCollisionFilter *v3; // rbx
  hkpCollidable *v4; // rdi
  hkpPhantom *v5; // rsi
  char v6; // [rsp+40h] [rbp+8h]
  char v7; // [rsp+50h] [rbp+18h]

  v3 = filter;
  v4 = collidable;
  v5 = phantom;
  ((void (__fastcall *)(hkpPhantom *, char *, hkpCollidable *))phantom->vfptr[4].__first_virtual_table_function__)(
    phantom,
    &v6,
    collidable);
  if ( *(_BYTE *)v3->vfptr->isCollisionEnabled(
                   (hkpCollidableCollidableFilter *)&v3->vfptr,
                   (hkBool *)&v7,
                   (hkpCollidable *)&v5->m_collidable.m_shape,
                   v4) )
  {
    if ( !v6 )
      v5->vfptr[4].__vecDelDtor((hkBaseObject *)&v5->vfptr, (unsigned int)v4);
    if ( v4->m_broadPhaseHandle.m_type == 2 )
    {
      (*(void (__fastcall **)(char *, char *, hkpLinkedCollidable *))&(*(hkpShape **)((char *)&v4->m_shape
                                                                                    + v4->m_ownerOffset))[2].m_memSizeAndFlags)(
        (char *)v4 + v4->m_ownerOffset,
        &v7,
        &v5->m_collidable);
      if ( !v7 )
        ((void (__fastcall *)(char *, hkpLinkedCollidable *))(*(hkpShape **)((char *)&v4->m_shape + v4->m_ownerOffset))[2].vfptr)(
          (char *)v4 + v4->m_ownerOffset,
          &v5->m_collidable);
    }
  }
  else
  {
    if ( v6 )
      v5->vfptr[5].__vecDelDtor((hkBaseObject *)&v5->vfptr, (unsigned int)v4);
    if ( v4->m_broadPhaseHandle.m_type == 2 )
    {
      (*(void (__fastcall **)(char *, char *, hkpLinkedCollidable *))&(*(hkpShape **)((char *)&v4->m_shape
                                                                                    + v4->m_ownerOffset))[2].m_memSizeAndFlags)(
        (char *)v4 + v4->m_ownerOffset,
        &v7,
        &v5->m_collidable);
      if ( v7 )
        (*(void (__fastcall **)(char *, hkpLinkedCollidable *))&(*(hkpShape **)((char *)&v4->m_shape + v4->m_ownerOffset))[2].m_type.m_storage)(
          (char *)v4 + v4->m_ownerOffset,
          &v5->m_collidable);
    }
  }
}

// File Line: 515
// RVA: 0xD59B60
void __fastcall hkpWorld::updateCollisionFilterOnPhantom(hkpWorld *this, hkpPhantom *phantom, hkpUpdateCollectionFilterMode updateShapeCollectionFilter)
{
  hkpUpdateCollectionFilterMode v3; // er12
  hkpPhantom *v4; // r14
  hkpWorld *v5; // rbx
  _QWORD *v6; // rax
  unsigned __int64 v7; // rcx
  _QWORD *v8; // r8
  unsigned __int64 v9; // rax
  int v10; // edi
  hkLifoAllocator *v11; // rax
  hkLifoAllocator *v12; // rcx
  char *v13; // rax
  int v14; // edx
  char *v15; // r8
  hkpBroadPhase *v16; // rcx
  _QWORD *v17; // r8
  _QWORD *v18; // rcx
  unsigned __int64 v19; // rax
  signed __int64 v20; // rcx
  int v21; // edx
  int v22; // edi
  __int64 v23; // rsi
  __int64 v24; // rcx
  unsigned __int64 v25; // rdx
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  signed __int64 v29; // rcx
  bool v30; // zf
  _QWORD *v31; // r8
  _QWORD *v32; // rcx
  unsigned __int64 v33; // rax
  signed __int64 v34; // rcx
  int v35; // eax
  char *v36; // rdi
  signed int v37; // ebx
  hkLifoAllocator *v38; // rax
  int v39; // er8
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-48h]
  hkpPhantom *v41; // [rsp+28h] [rbp-40h]
  char v42; // [rsp+30h] [rbp-38h]
  char *v43; // [rsp+38h] [rbp-30h]
  int v44; // [rsp+40h] [rbp-28h]
  int v45; // [rsp+44h] [rbp-24h]
  void *p; // [rsp+48h] [rbp-20h]
  int v47; // [rsp+50h] [rbp-18h]

  v3 = updateShapeCollectionFilter;
  v4 = phantom;
  v5 = this;
  if ( this->m_criticalOperationsLockCount )
  {
    v41 = phantom;
    operation.m_type.m_storage = 21;
    v42 = updateShapeCollectionFilter;
    hkpWorld::queueOperation(this, &operation);
  }
  else
  {
    this->m_criticalOperationsLockCount = 1;
    v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v7 = v6[1];
    v8 = v6;
    if ( v7 < v6[3] )
    {
      *(_QWORD *)v7 = "LtUpdateFilterOnPhantom";
      *(_QWORD *)(v7 + 16) = "Stbroadphase";
      v9 = __rdtsc();
      *(_DWORD *)(v7 + 8) = v9;
      v8[1] = v7 + 24;
    }
    v10 = v5->m_broadPhaseQuerySize;
    v45 = 2147483648;
    v43 = 0i64;
    v44 = 0;
    v47 = v10;
    if ( v10 )
    {
      v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v12 = v11;
      v13 = (char *)v11->m_cur;
      v14 = (16 * v10 + 127) & 0xFFFFFF80;
      v15 = &v13[v14];
      if ( v14 > v12->m_slabSize || v15 > v12->m_end )
        v13 = (char *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
      else
        v12->m_cur = v15;
    }
    else
    {
      v13 = 0i64;
    }
    v16 = v5->m_broadPhase;
    v43 = v13;
    p = v13;
    v45 = v10 | 0x80000000;
    ((void (__fastcall *)(hkpBroadPhase *, hkpTypedBroadPhaseHandle *, char **))v16->vfptr[9].__first_virtual_table_function__)(
      v16,
      &v4->m_collidable.m_broadPhaseHandle,
      &v43);
    v17 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v18 = (_QWORD *)v17[1];
    if ( (unsigned __int64)v18 < v17[3] )
    {
      *v18 = "StUpdateOverlaps";
      v19 = __rdtsc();
      v20 = (signed __int64)(v18 + 2);
      *(_DWORD *)(v20 - 8) = v19;
      v17[1] = v20;
    }
    v21 = v44;
    v22 = 0;
    if ( v44 > 0 )
    {
      v23 = 0i64;
      do
      {
        v24 = *(_QWORD *)&v43[v23 + 8];
        if ( (hkpTypedBroadPhaseHandle *)v24 != &v4->m_collidable.m_broadPhaseHandle )
        {
          hkWorld_updateFilterOnSinglePhantom(v4, (hkpCollidable *)(v24 + *(char *)(v24 + 5)), v5->m_collisionFilter);
          v21 = v44;
        }
        ++v22;
        v23 += 16i64;
      }
      while ( v22 < v21 );
    }
    if ( v3 )
    {
      v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v27 = (_QWORD *)v26[1];
      if ( (unsigned __int64)v27 < v26[3] )
      {
        *v27 = "StcollectionFilter";
        v28 = __rdtsc();
        v25 = (unsigned __int64)HIDWORD(v28) << 32;
        v29 = (signed __int64)(v27 + 2);
        *(_DWORD *)(v29 - 8) = v28;
        v26[1] = v29;
      }
      ((void (__fastcall *)(hkpPhantom *, unsigned __int64, LPVOID))v4->vfptr[6].__first_virtual_table_function__)(
        v4,
        v25,
        v26);
    }
    v30 = v5->m_criticalOperationsLockCount-- == 1;
    if ( v30 && !v5->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v5->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v5);
      if ( v5->m_pendingOperationQueueCount == 1 && v5->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v5);
    }
    v31 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v32 = (_QWORD *)v31[1];
    if ( (unsigned __int64)v32 < v31[3] )
    {
      *v32 = "lt";
      v33 = __rdtsc();
      v34 = (signed __int64)(v32 + 2);
      *(_DWORD *)(v34 - 8) = v33;
      v31[1] = v34;
    }
    v35 = v44;
    v36 = (char *)p;
    if ( p == v43 )
      v35 = 0;
    v44 = v35;
    v37 = (16 * v47 + 127) & 0xFFFFFF80;
    v38 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v39 = (v37 + 15) & 0xFFFFFFF0;
    if ( v37 > v38->m_slabSize || &v36[v39] != v38->m_cur || v38->m_firstNonLifoEnd == v36 )
      hkLifoAllocator::slowBlockFree(v38, v36, v39);
    else
      v38->m_cur = v36;
    v44 = 0;
    if ( v45 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v43,
        16 * v45);
  }
}

// File Line: 568
// RVA: 0xD59A70
void __fastcall hkpWorld::reenableCollisionBetweenEntityPair(hkpWorld *this, hkpEntity *entityA, hkpEntity *entityB)
{
  hkpEntity *v3; // rdi
  hkpEntity *v4; // rsi
  hkpWorld *v5; // rbx
  hkpBroadPhaseHandle *v6; // rbp
  hkpBroadPhaseHandle *v7; // r14
  hkpCollidableCollidableFilter *v8; // r9
  hkpTypedBroadPhaseHandlePair newPairs; // [rsp+20h] [rbp-48h]
  hkWorldOperation::BaseOperation operation; // [rsp+30h] [rbp-38h]
  hkpEntity *v11; // [rsp+38h] [rbp-30h]
  hkpEntity *v12; // [rsp+40h] [rbp-28h]
  char v13; // [rsp+70h] [rbp+8h]

  v3 = entityB;
  v4 = entityA;
  v5 = this;
  if ( this->m_criticalOperationsLockCount )
  {
    v11 = entityA;
    operation.m_type.m_storage = 20;
    v12 = entityB;
    hkpWorld::queueOperation(this, &operation);
  }
  else
  {
    v6 = (hkpBroadPhaseHandle *)&entityB->m_collidable.m_broadPhaseHandle.m_id;
    v7 = (hkpBroadPhaseHandle *)&entityA->m_collidable.m_broadPhaseHandle.m_id;
    if ( ((unsigned __int8 (__fastcall *)(hkpBroadPhase *, hkpTypedBroadPhaseHandle *, hkpTypedBroadPhaseHandle *))this->m_broadPhase->vfptr[10].__first_virtual_table_function__)(
           this->m_broadPhase,
           &entityA->m_collidable.m_broadPhaseHandle,
           &entityB->m_collidable.m_broadPhaseHandle)
      && *(_BYTE *)v5->m_collisionFilter->vfptr->isCollisionEnabled(
                     (hkpCollidableCollidableFilter *)&v5->m_collisionFilter->vfptr,
                     (hkBool *)&v13,
                     (hkpCollidable *)&v4->m_collidable.m_shape,
                     (hkpCollidable *)&v3->m_collidable.m_shape)
      && !hkAgentNnMachine_FindAgent(&v4->m_collidable, &v3->m_collidable) )
    {
      v8 = (hkpCollidableCollidableFilter *)v5->m_collisionFilter;
      newPairs.m_a = v7;
      newPairs.m_b = v6;
      if ( v8 )
        v8 += 2;
      hkpTypedBroadPhaseDispatcher::addPairs(v5->m_broadPhaseDispatcher, &newPairs, 1, v8);
    }
  }
}

// File Line: 612
// RVA: 0xD59430
void __fastcall hkpWorld::updateCollisionFilterOnEntity(hkpWorld *this, hkpEntity *entity, hkpUpdateCollisionFilterOnEntityMode updateMode, hkpUpdateCollectionFilterMode updateShapeCollectionFilter)
{
  hkpUpdateCollectionFilterMode v4; // er12
  hkpUpdateCollisionFilterOnEntityMode v5; // ebx
  hkpEntity *v6; // r13
  hkpWorld *v7; // r14
  _QWORD *v8; // r8
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // rax
  signed int v11; // er15
  _QWORD *v12; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx
  int v20; // edx
  int v21; // edi
  __int64 v22; // rsi
  char *v23; // rax
  hkpPhantom *v24; // rbx
  __int64 v25; // r8
  signed __int64 v26; // rdx
  hkpBroadPhaseHandlePair *v27; // rcx
  signed __int64 v28; // r8
  hkpBroadPhaseHandle *v29; // rax
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *v30; // rax
  int v31; // ecx
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *v32; // rdi
  int v33; // esi
  __int64 v34; // rbx
  signed __int64 v35; // rdx
  hkpAgentNnEntry *v36; // rcx
  char *v37; // rdx
  _QWORD *v38; // r8
  _QWORD *v39; // rcx
  unsigned __int64 v40; // rax
  signed __int64 v41; // rcx
  __int64 v42; // r12
  int v43; // edi
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *v44; // r15
  __int64 v45; // rbx
  hkpLinkedCollidable::CollisionEntry *v46; // rsi
  hkpLinkedCollidable *v47; // r8
  signed __int64 v48; // rdx
  hkpCollisionDispatcher *v49; // rax
  int v50; // ecx
  hkpBroadPhaseHandlePair *v51; // rdx
  _QWORD *v52; // r8
  _QWORD *v53; // rcx
  unsigned __int64 v54; // rax
  signed __int64 v55; // rcx
  hkpCollisionFilter *v56; // rax
  hkpCollidableCollidableFilter *v57; // r9
  bool v58; // zf
  _QWORD *v59; // r8
  _QWORD *v60; // rcx
  unsigned __int64 v61; // rax
  signed __int64 v62; // rcx
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-E0h]
  hkpEntity *v64; // [rsp+28h] [rbp-D8h]
  char v65; // [rsp+30h] [rbp-D0h]
  char v66; // [rsp+31h] [rbp-CFh]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> delPairs; // [rsp+40h] [rbp-C0h]
  char v68; // [rsp+50h] [rbp-B0h]
  char *array; // [rsp+850h] [rbp+750h]
  int v70; // [rsp+858h] [rbp+758h]
  int v71; // [rsp+85Ch] [rbp+75Ch]
  char v72; // [rsp+860h] [rbp+760h]
  char v73; // [rsp+10A0h] [rbp+FA0h]
  hkpUpdateCollectionFilterMode v74; // [rsp+10B8h] [rbp+FB8h]

  v74 = updateShapeCollectionFilter;
  v4 = updateShapeCollectionFilter;
  v5 = updateMode;
  v6 = entity;
  v7 = this;
  if ( this->m_criticalOperationsLockCount )
  {
    v64 = entity;
    operation.m_type.m_storage = 19;
    v65 = updateMode;
    v66 = updateShapeCollectionFilter;
    hkpWorld::queueOperation(this, &operation);
    return;
  }
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = v8[1];
  if ( v9 < v8[3] )
  {
    *(_QWORD *)v9 = "LtUpdateFilterOnEntity";
    *(_QWORD *)(v9 + 16) = "Stinit";
    v10 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v10;
    v8[1] = v9 + 24;
  }
  ++v7->m_criticalOperationsLockCount;
  if ( v6->m_motion.m_type.m_storage == 5 )
    hkpLinkedCollidable::sortEntries(&v6->m_collidable);
  v11 = -2147483520;
  delPairs.m_size = 0;
  delPairs.m_data = (hkpBroadPhaseHandlePair *)&v68;
  delPairs.m_capacityAndFlags = -2147483520;
  if ( v5 == HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK )
  {
    v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v13 = (_QWORD *)v12[1];
    if ( (unsigned __int64)v13 < v12[3] )
    {
      *v13 = "Stbroadphase";
      v14 = __rdtsc();
      v15 = (signed __int64)(v13 + 2);
      *(_DWORD *)(v15 - 8) = v14;
      v12[1] = v15;
    }
    ((void (__fastcall *)(hkpBroadPhase *, hkpTypedBroadPhaseHandle *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))v7->m_broadPhase->vfptr[9].__first_virtual_table_function__)(
      v7->m_broadPhase,
      &v6->m_collidable.m_broadPhaseHandle,
      &delPairs);
    v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v17 = (_QWORD *)v16[1];
    if ( (unsigned __int64)v17 < v16[3] )
    {
      *v17 = "Stphantom";
      v18 = __rdtsc();
      v19 = (signed __int64)(v17 + 2);
      *(_DWORD *)(v19 - 8) = v18;
      v16[1] = v19;
    }
    v20 = delPairs.m_size;
    v21 = 0;
    if ( delPairs.m_size > 0 )
    {
      v22 = 0i64;
      do
      {
        v23 = (char *)delPairs.m_data[v22].m_b + SBYTE1(delPairs.m_data[v22].m_b[1].m_id);
        if ( v23[40] == 2 )
        {
          v24 = (hkpPhantom *)&v23[v23[32]];
          if ( v24 )
          {
            hkWorld_updateFilterOnSinglePhantom(v24, (hkpCollidable *)&v6->m_collidable.m_shape, v7->m_collisionFilter);
            if ( v4 )
              v24->vfptr[6].__first_virtual_table_function__((hkBaseObject *)&v24->vfptr);
            v20 = delPairs.m_size - 1;
            delPairs.m_size = v20;
            if ( v20 != v21 )
            {
              v25 = v20;
              v26 = 2i64;
              v27 = &delPairs.m_data[v22];
              v28 = 16 * v25 - v22 * 16;
              do
              {
                v29 = *(hkpBroadPhaseHandle **)((char *)&v27->m_a + v28);
                v27 = (hkpBroadPhaseHandlePair *)((char *)v27 + 8);
                v27[-1].m_b = v29;
                --v26;
              }
              while ( v26 );
              v20 = delPairs.m_size;
            }
            --v21;
            --v22;
          }
        }
        ++v21;
        ++v22;
      }
      while ( v21 < v20 );
    }
    v30 = hkpLinkedCollidable::getCollisionEntriesDeterministicUnchecked(&v6->m_collidable);
    v31 = 0;
    v71 = -2147483520;
    v32 = v30;
    v70 = 0;
    array = &v72;
    v33 = 0;
    if ( v30->m_size > 0 )
    {
      v34 = 0i64;
      while ( 1 )
      {
        if ( v31 == (v11 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
          v31 = v70;
        }
        ++v33;
        v70 = v31 + 1;
        v35 = 16i64 * v31;
        v36 = v32->m_data[v34].m_agentEntry;
        v37 = &array[v35];
        ++v34;
        *(_QWORD *)v37 = (char *)v36->m_collidable[0] + 36;
        *((_QWORD *)v37 + 1) = (char *)v32->m_data[v34 - 1].m_agentEntry->m_collidable[1] + 36;
        if ( v33 >= v32->m_size )
          break;
        v11 = v71;
        v31 = v70;
      }
    }
    hkpTypedBroadPhaseDispatcher::removeDuplicates(
      (hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *)&array,
      &delPairs);
    v70 = 0;
    if ( v71 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        16 * v71);
  }
  v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v39 = (_QWORD *)v38[1];
  if ( (unsigned __int64)v39 < v38[3] )
  {
    *v39 = "StcheckAgts";
    v40 = __rdtsc();
    v41 = (signed __int64)(v39 + 2);
    *(_DWORD *)(v41 - 8) = v40;
    v38[1] = v41;
  }
  v42 = v6->m_collidable.m_broadPhaseHandle.m_objectQualityType;
  v43 = 0;
  v44 = hkpLinkedCollidable::getCollisionEntriesDeterministicUnchecked(&v6->m_collidable);
  if ( v44->m_size > 0 )
  {
    v45 = 0i64;
    do
    {
      v46 = &v44->m_data[v45];
      if ( *(_BYTE *)v7->m_collisionFilter->vfptr->isCollisionEnabled(
                       (hkpCollidableCollidableFilter *)&v7->m_collisionFilter->vfptr,
                       (hkBool *)&v73,
                       (hkpCollidable *)&v6->m_collidable.m_shape,
                       (hkpCollidable *)&v46->m_partner->m_shape) )
      {
        v47 = v46->m_partner;
        v48 = v47->m_broadPhaseHandle.m_objectQualityType + 10 * v42;
        v49 = v7->m_collisionDispatcher;
        if ( v49->m_collisionQualityTable[0][v48] )
        {
          if ( v49->m_collisionQualityTable[0][v48] == (unsigned __int8)v46->m_agentEntry->m_collisionQualityIndex )
          {
            if ( v74 == 1 )
            {
              if ( v6->m_motion.m_type.m_storage == 5 )
                hkAgentNnMachine_UpdateShapeCollectionFilter(
                  v46->m_agentEntry,
                  (hkpCollisionInput *)&v7->m_collisionInput->m_dispatcher,
                  *(hkpConstraintOwner **)(&v47[2].m_broadPhaseHandle.m_type + v47->m_ownerOffset),
                  v42);
              else
                hkAgentNnMachine_UpdateShapeCollectionFilter(
                  v46->m_agentEntry,
                  (hkpCollisionInput *)&v7->m_collisionInput->m_dispatcher,
                  (hkpConstraintOwner *)&v6->m_simulationIsland->vfptr,
                  v42);
            }
            goto LABEL_43;
          }
          v50 = delPairs.m_size;
          if ( delPairs.m_size == (delPairs.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &delPairs, 16);
            v50 = delPairs.m_size;
          }
          delPairs.m_size = v50 + 1;
          v51 = &delPairs.m_data[v50];
          v51->m_a = (hkpBroadPhaseHandle *)&v44->m_data[v45].m_agentEntry->m_collidable[0]->m_broadPhaseHandle.m_id;
          v51->m_b = (hkpBroadPhaseHandle *)&v44->m_data[v45].m_agentEntry->m_collidable[1]->m_broadPhaseHandle.m_id;
        }
      }
      hkpWorldAgentUtil::removeAgentAndItsToiEvents(v46->m_agentEntry);
      --v43;
      --v45;
      *((_BYTE *)v6->m_simulationIsland + 49) = *((_BYTE *)v6->m_simulationIsland + 49) & 0xFD | 1;
LABEL_43:
      ++v43;
      ++v45;
    }
    while ( v43 < v44->m_size );
  }
  if ( delPairs.m_size > 0 )
  {
    v52 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v53 = (_QWORD *)v52[1];
    if ( (unsigned __int64)v53 < v52[3] )
    {
      *v53 = "StaddAgts";
      v54 = __rdtsc();
      v55 = (signed __int64)(v53 + 2);
      *(_DWORD *)(v55 - 8) = v54;
      v52[1] = v55;
    }
    v56 = v7->m_collisionFilter;
    if ( v56 )
      v57 = (hkpCollidableCollidableFilter *)&v56->vfptr;
    else
      v57 = 0i64;
    hkpTypedBroadPhaseDispatcher::addPairs(
      v7->m_broadPhaseDispatcher,
      (hkpTypedBroadPhaseHandlePair *)delPairs.m_data,
      delPairs.m_size,
      v57);
  }
  v58 = v7->m_criticalOperationsLockCount-- == 1;
  if ( v58 && !v7->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v7->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v7);
    if ( v7->m_pendingOperationQueueCount == 1 && v7->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(v7);
  }
  delPairs.m_size = 0;
  if ( delPairs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      delPairs.m_data,
      16 * delPairs.m_capacityAndFlags);
  v59 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v60 = (_QWORD *)v59[1];
  if ( (unsigned __int64)v60 < v59[3] )
  {
    *v60 = "lt";
    v61 = __rdtsc();
    v62 = (signed __int64)(v60 + 2);
    *(_DWORD *)(v62 - 8) = v61;
    v59[1] = v62;
  }
}

// File Line: 794
// RVA: 0xD5A370
void __fastcall hkpWorld::reintegrateAndRecollideEntities(hkpWorld *this, hkpEntity **entityBatch, __int64 numEntities, hkpWorld::ReintegrationRecollideMode mode)
{
  hkpWorld::ReintegrationRecollideMode v4; // ST20_4
  hkWorldOperation::BaseOperation operation; // [rsp+30h] [rbp-28h]
  hkpEntity **v6; // [rsp+38h] [rbp-20h]
  __int16 v7; // [rsp+40h] [rbp-18h]
  char v8; // [rsp+42h] [rbp-16h]

  if ( this->m_criticalOperationsLockCount )
  {
    v6 = entityBatch;
    operation.m_type.m_storage = 24;
    v7 = numEntities;
    v8 = mode;
    hkpWorld::queueOperation(this, &operation);
  }
  else
  {
    v4 = mode;
    ((void (__fastcall *)(hkpSimulation *, hkpEntity **, __int64, hkpWorld *, hkpWorld::ReintegrationRecollideMode))this->m_simulation->vfptr[8].__vecDelDtor)(
      this->m_simulation,
      entityBatch,
      numEntities,
      this,
      v4);
  }
}

// File Line: 813
// RVA: 0xD56FC0
hkpEntity *__fastcall hkpWorld::addEntity(hkpWorld *this, hkpEntity *entity, hkpEntityActivation initialActivationState)
{
  hkpEntityActivation v3; // esi
  hkpEntity *v4; // rdi
  hkpWorld *v5; // rbx
  hkpEntity *result; // rax
  __int16 v7; // dx
  __int16 v8; // r8
  __int16 v9; // r8
  bool v10; // zf
  hkSimdFloat32 startTime; // [rsp+20h] [rbp-38h]
  hkWorldOperation::BaseOperation operation; // [rsp+30h] [rbp-28h]
  hkpEntity *v13; // [rsp+38h] [rbp-20h]
  hkpEntityActivation v14; // [rsp+40h] [rbp-18h]

  v3 = initialActivationState;
  v4 = entity;
  v5 = this;
  if ( this->m_criticalOperationsLockCount )
  {
    v13 = entity;
    operation.m_type.m_storage = 1;
    v14 = initialActivationState;
    hkpWorld::queueOperation(this, &operation);
    result = 0i64;
  }
  else
  {
    hkpEntity::setCachedShapeData(entity, this, entity->m_collidable.m_shape);
    if ( !v4->m_collidable.m_motion )
      v4->m_collidable.m_motion = (const void *)((__int64 (__fastcall *)(hkpEntity *))v4->vfptr[2].__first_virtual_table_function__)(v4);
    startTime.m_real = 0i64;
    hkSweptTransformUtil::setTimeInformation(&startTime, &startTime, &v4->m_motion.m_motionState);
    *(_DWORD *)v4->m_motion.m_deactivationNumInactiveFrames = 0;
    ++v5->m_lastEntityUid;
    v5->m_criticalOperationsAllowed.m_bool = 0;
    v4->m_uid = v5->m_lastEntityUid;
    hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
    hkpWorldOperationUtil::addEntitySI(v5, v4, v3);
    v7 = (unsigned __int8)v5->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1];
    v8 = (unsigned __int8)v5->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0];
    if ( (unsigned __int8)(v5->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter & 3) < (unsigned __int8)(v4->m_motion.m_deactivationIntegrateCounter & 3) )
      v8 = ~v8;
    v9 = v8 << 14;
    if ( (unsigned __int8)v5->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter < (signed int)(unsigned __int8)v4->m_motion.m_deactivationIntegrateCounter )
      v7 = ~v7;
    v4->m_motion.m_deactivationNumInactiveFrames[1] &= 0x3FFFu;
    v4->m_motion.m_deactivationNumInactiveFrames[1] |= v7 << 14;
    v4->m_motion.m_deactivationNumInactiveFrames[0] &= 0x3FFFu;
    v4->m_motion.m_deactivationNumInactiveFrames[0] |= v9;
    ++v5->m_criticalOperationsLockCount;
    v5->m_criticalOperationsAllowed.m_bool = 1;
    hkpWorldOperationUtil::addEntityBP(v5, v4);
    hkpWorldCallbackUtil::fireEntityAdded(v5, v4);
    hkpEntityCallbackUtil::fireEntityAdded(v4);
    v10 = v5->m_criticalOperationsLockCount-- == 1;
    if ( v10 && !v5->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v5->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v5);
      if ( v5->m_pendingOperationQueueCount == 1 )
      {
        if ( v5->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(v5);
      }
    }
    result = v4;
  }
  return result;
}

// File Line: 927
// RVA: 0xD57280
void __fastcall hkpWorld::addEntityBatch(hkpWorld *this, hkpEntity *const *entityBatch, int numEntities, hkpEntityActivation initialActivationState)
{
  hkpEntityActivation v4; // er12
  __int64 v5; // r15
  hkpEntity *const *v6; // r14
  hkpWorld *v7; // rdi
  _QWORD *v8; // r8
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // rax
  char v11; // bl
  _QWORD **v12; // rax
  hkpSimulationIsland *v13; // rax
  hkInplaceArray<hkpEntity *,1,hkContainerHeapAllocator> *v14; // r8
  hkpSimulationIsland *v15; // rax
  hkpSimulationIsland *v16; // rsi
  unsigned __int16 v17; // ax
  int v18; // eax
  int v19; // er9
  int v20; // eax
  __int128 v21; // xmm6
  hkpEntity *const *v22; // r12
  __int64 v23; // r14
  hkpEntity *v24; // rbx
  hkpShape *v25; // r13
  __int16 v26; // dx
  __int16 v27; // r8
  __int16 v28; // r8
  hkpSimulationIsland *v29; // rcx
  __int64 v30; // r9
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *v31; // rbx
  int v32; // ebx
  LPVOID v33; // rax
  hkLifoAllocator *v34; // rcx
  hkpTypedBroadPhaseHandlePair *v35; // rax
  int v36; // edx
  char *v37; // r8
  _QWORD *v38; // rax
  _QWORD *v39; // rcx
  _QWORD *v40; // r8
  unsigned __int64 v41; // rax
  signed __int64 v42; // rcx
  _QWORD *v43; // r8
  _QWORD *v44; // rcx
  unsigned __int64 v45; // rax
  signed __int64 v46; // rcx
  hkpCollisionFilter *v47; // rax
  hkpCollidableCollidableFilter *v48; // r9
  _QWORD *v49; // r8
  _QWORD *v50; // rcx
  unsigned __int64 v51; // rax
  signed __int64 v52; // rcx
  __int64 v53; // rsi
  hkpEntity *v54; // rbx
  bool v55; // zf
  _QWORD *v56; // r8
  _QWORD *v57; // rcx
  unsigned __int64 v58; // rax
  signed __int64 v59; // rcx
  int v60; // eax
  char *v61; // rdi
  signed int v62; // ebx
  hkLifoAllocator *v63; // rax
  int v64; // er8
  char v65; // [rsp+30h] [rbp-59h]
  hkResult result; // [rsp+34h] [rbp-55h]
  void *v67; // [rsp+38h] [rbp-51h]
  int v68; // [rsp+40h] [rbp-49h]
  int v69; // [rsp+44h] [rbp-45h]
  _QWORD *array; // [rsp+48h] [rbp-41h]
  int v71; // [rsp+50h] [rbp-39h]
  int v72; // [rsp+54h] [rbp-35h]
  hkWorldOperation::BaseOperation operation[16]; // [rsp+60h] [rbp-29h]
  __int16 v74; // [rsp+70h] [rbp-19h]
  char v75; // [rsp+72h] [rbp-17h]
  hkpTypedBroadPhaseHandlePair *newPairs; // [rsp+80h] [rbp-9h]
  int numNewPairs; // [rsp+88h] [rbp-1h]
  int v78; // [rsp+8Ch] [rbp+3h]
  void *p; // [rsp+90h] [rbp+7h]
  int v80; // [rsp+98h] [rbp+Fh]
  hkpEntity *const *v81; // [rsp+F8h] [rbp+6Fh]
  int v82; // [rsp+100h] [rbp+77h]
  hkpEntityActivation v83; // [rsp+108h] [rbp+7Fh]

  if ( numEntities > 0 )
  {
    v83 = initialActivationState;
    v82 = numEntities;
    v81 = entityBatch;
    v4 = initialActivationState;
    v5 = (unsigned int)numEntities;
    v6 = entityBatch;
    v7 = this;
    if ( this->m_criticalOperationsLockCount )
    {
      *(_QWORD *)&operation[8].m_type.m_storage = entityBatch;
      operation[0].m_type.m_storage = 7;
      v74 = numEntities;
      v75 = initialActivationState;
      hkpWorld::queueOperation(this, operation);
    }
    else
    {
      v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v9 = v8[1];
      if ( v9 < v8[3] )
      {
        *(_QWORD *)v9 = "LtAddEntities";
        *(_QWORD *)(v9 + 16) = "Stinit";
        v10 = __rdtsc();
        *(_DWORD *)(v9 + 8) = v10;
        v8[1] = v9 + 24;
      }
      ++v7->m_criticalOperationsLockCount;
      v72 = 2147483648;
      array = 0i64;
      v71 = 0;
      if ( (signed int)v5 > 0 )
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v5, 8);
      v67 = 0i64;
      v68 = 0;
      v69 = 2147483648;
      if ( (signed int)v5 > 0 )
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v67, v5, 32);
      v11 = 0;
      v65 = 0;
      if ( v7->m_wantSimulationIslands.m_bool )
      {
        v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v13 = (hkpSimulationIsland *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(
                                       v12[11],
                                       184i64);
        if ( v13 )
        {
          hkpSimulationIsland::hkpSimulationIsland(v13, v7);
          v16 = v15;
        }
        else
        {
          v16 = 0i64;
        }
        *((_BYTE *)v16 + 49) &= 0xFDu;
        *((_BYTE *)v16 + 49) |= 1u;
        if ( v4 == 1 )
        {
          v17 = v7->m_activeSimulationIslands.m_size;
          *((_BYTE *)v16 + 50) &= 0xF5u;
          *((_BYTE *)v16 + 50) |= 5u;
        }
        else
        {
          v17 = v7->m_inactiveSimulationIslands.m_size;
          *((_BYTE *)v16 + 50) &= 0xF0u;
        }
        v16->m_storageIndex = v17;
      }
      else
      {
        v16 = *v7->m_activeSimulationIslands.m_data;
        v14 = &v16->m_entities;
        v18 = v16->m_entities.m_capacityAndFlags & 0x3FFFFFFF;
        v19 = v5 + v16->m_entities.m_size;
        if ( v18 < v19 )
        {
          v20 = 2 * v18;
          if ( v19 < v20 )
            v19 = v20;
          hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v14, v19, 8);
        }
      }
      v21 = LODWORD(v7->m_collisionInput->m_tolerance.m_storage);
      *(_OWORD *)&operation[0].m_type.m_storage = 0i64;
      if ( (signed int)v5 > 0 )
      {
        v22 = v6;
        v23 = v5;
        do
        {
          v24 = *v22;
          v25 = (*v22)->m_collidable.m_shape;
          v24->m_uid = ++v7->m_lastEntityUid;
          hkReferencedObject::addReference((hkReferencedObject *)&v24->vfptr);
          if ( !v24->m_collidable.m_motion )
            v24->m_collidable.m_motion = (const void *)((__int64 (__fastcall *)(hkpEntity *))v24->vfptr[2].__first_virtual_table_function__)(v24);
          hkSweptTransformUtil::setTimeInformation(
            (hkSimdFloat32 *)operation,
            (hkSimdFloat32 *)operation,
            &v24->m_motion.m_motionState);
          *(_DWORD *)v24->m_motion.m_deactivationNumInactiveFrames = 0;
          v24->m_world = v7;
          v26 = (unsigned __int8)v7->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1];
          v27 = (unsigned __int8)v7->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0];
          if ( (unsigned __int8)(v7->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter & 3) < (unsigned __int8)(v24->m_motion.m_deactivationIntegrateCounter & 3) )
            v27 = ~v27;
          v28 = v27 << 14;
          if ( (unsigned __int8)v7->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter < (signed int)(unsigned __int8)v24->m_motion.m_deactivationIntegrateCounter )
            v26 = ~v26;
          v24->m_motion.m_deactivationNumInactiveFrames[0] &= 0x3FFFu;
          v24->m_motion.m_deactivationNumInactiveFrames[1] &= 0x3FFFu;
          v24->m_motion.m_deactivationNumInactiveFrames[1] |= v26 << 14;
          v24->m_motion.m_deactivationNumInactiveFrames[0] |= v28;
          if ( v24->m_motion.m_type.m_storage == 5 )
          {
            v29 = v7->m_fixedIsland;
          }
          else
          {
            v65 = 1;
            v29 = v16;
          }
          hkpSimulationIsland::internalAddEntity(v29, v24);
          v24->m_collidable.m_boundingVolumeData.m_min[0] = 1;
          v24->m_collidable.m_boundingVolumeData.m_max[0] = 0;
          if ( v25 )
          {
            v30 = v68++;
            ((void (__fastcall *)(hkpShape *, const void *, hkInplaceArray<hkpEntity *,1,hkContainerHeapAllocator> *, __int64))v24->m_collidable.m_shape->vfptr[2].__vecDelDtor)(
              v24->m_collidable.m_shape,
              v24->m_collidable.m_motion,
              v14,
              (__int64)v67 + 32 * v30);
            array[v71++] = (char *)v24 + 68;
            hkpEntity::setCachedShapeData(v24, v7, v25);
          }
          ++v22;
          --v23;
        }
        while ( v23 );
        v6 = v81;
        LODWORD(v5) = v82;
        v11 = v65;
        v4 = v83;
      }
      if ( v7->m_wantSimulationIslands.m_bool )
      {
        if ( v11 )
        {
          v31 = &v7->m_activeSimulationIslands;
          v16->m_splitCheckFrameCounter = (*v16->m_entities.m_data)->m_uid;
          if ( v4 != 1 )
            v31 = &v7->m_inactiveSimulationIslands;
          if ( v31->m_size == (v31->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v31, 8);
          v31->m_data[v31->m_size++] = v16;
        }
        else
        {
          ((void (__fastcall *)(hkpSimulationIsland *, signed __int64, hkInplaceArray<hkpEntity *,1,hkContainerHeapAllocator> *))v16->vfptr->__vecDelDtor)(
            v16,
            1i64,
            v14);
        }
      }
      v32 = v7->m_broadPhaseQuerySize;
      newPairs = 0i64;
      numNewPairs = 0;
      v78 = 2147483648;
      v80 = v32;
      if ( v32 )
      {
        v33 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v34 = (hkLifoAllocator *)v33;
        v35 = (hkpTypedBroadPhaseHandlePair *)*((_QWORD *)v33 + 3);
        v36 = (16 * v32 + 127) & 0xFFFFFF80;
        v37 = (char *)v35 + v36;
        if ( v36 > v34->m_slabSize || v37 > v34->m_end )
          v35 = (hkpTypedBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v34, v36);
        else
          v34->m_cur = v37;
      }
      else
      {
        v35 = 0i64;
      }
      newPairs = v35;
      v78 = v32 | 0x80000000;
      p = v35;
      v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v39 = (_QWORD *)v38[1];
      v40 = v38;
      if ( (unsigned __int64)v39 < v38[3] )
      {
        *v39 = "StBroadphase";
        v41 = __rdtsc();
        v42 = (signed __int64)(v39 + 2);
        *(_DWORD *)(v42 - 8) = v41;
        v40[1] = v42;
      }
      ((void (__fastcall *)(hkpBroadPhase *, _QWORD **, void **, hkpTypedBroadPhaseHandlePair **))v7->m_broadPhase->vfptr[3].__first_virtual_table_function__)(
        v7->m_broadPhase,
        &array,
        &v67,
        &newPairs);
      v43 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v44 = (_QWORD *)v43[1];
      if ( (unsigned __int64)v44 < v43[3] )
      {
        *v44 = "StCreateAgents";
        v45 = __rdtsc();
        v46 = (signed __int64)(v44 + 2);
        *(_DWORD *)(v46 - 8) = v45;
        v43[1] = v46;
      }
      v47 = v7->m_collisionFilter;
      v48 = (hkpCollidableCollidableFilter *)&v47->vfptr;
      if ( !v47 )
        v48 = 0i64;
      hkpTypedBroadPhaseDispatcher::addPairs(v7->m_broadPhaseDispatcher, newPairs, numNewPairs, v48);
      v49 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v50 = (_QWORD *)v49[1];
      if ( (unsigned __int64)v50 < v49[3] )
      {
        *v50 = "StAddedCb";
        v51 = __rdtsc();
        v52 = (signed __int64)(v50 + 2);
        *(_DWORD *)(v52 - 8) = v51;
        v49[1] = v52;
      }
      if ( (signed int)v5 > 0 )
      {
        v53 = (unsigned int)v5;
        do
        {
          v54 = *v6;
          hkpWorldCallbackUtil::fireEntityAdded(v7, *v6);
          hkpEntityCallbackUtil::fireEntityAdded(v54);
          ++v6;
          --v53;
        }
        while ( v53 );
      }
      v55 = v7->m_criticalOperationsLockCount-- == 1;
      if ( v55 && !v7->m_blockExecutingPendingOperations.m_bool )
      {
        if ( v7->m_pendingOperationsCount )
          hkpWorld::internal_executePendingOperations(v7);
        if ( v7->m_pendingOperationQueueCount == 1 && v7->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(v7);
      }
      v56 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v57 = (_QWORD *)v56[1];
      if ( (unsigned __int64)v57 < v56[3] )
      {
        *v57 = "lt";
        v58 = __rdtsc();
        v59 = (signed __int64)(v57 + 2);
        *(_DWORD *)(v59 - 8) = v58;
        v56[1] = v59;
      }
      v60 = numNewPairs;
      v61 = (char *)p;
      if ( p == newPairs )
        v60 = 0;
      numNewPairs = v60;
      v62 = (16 * v80 + 127) & 0xFFFFFF80;
      v63 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v64 = (v62 + 15) & 0xFFFFFFF0;
      if ( v62 > v63->m_slabSize || &v61[v64] != v63->m_cur || v63->m_firstNonLifoEnd == v61 )
        hkLifoAllocator::slowBlockFree(v63, v61, v64);
      else
        v63->m_cur = v61;
      numNewPairs = 0;
      if ( v78 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          newPairs,
          16 * v78);
      newPairs = 0i64;
      v78 = 2147483648;
      v68 = 0;
      if ( v69 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v67,
          32 * v69);
      v67 = 0i64;
      v71 = 0;
      v69 = 2147483648;
      if ( v72 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          8 * v72);
    }
  }
}

// File Line: 1093
// RVA: 0xD57170
hkBool *__fastcall hkpWorld::removeEntity(hkpWorld *this, hkBool *result, hkpEntity *entity)
{
  hkpEntity *v3; // rdi
  hkBool *v4; // rsi
  hkpWorld *v5; // rbx
  hkBool *v6; // rax
  bool v7; // zf
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-18h]
  hkpEntity *v9; // [rsp+28h] [rbp-10h]

  v3 = entity;
  v4 = result;
  v5 = this;
  if ( this->m_criticalOperationsLockCount )
  {
    operation.m_type.m_storage = 2;
    v9 = entity;
    hkpWorld::queueOperation(this, &operation);
    v4->m_bool = 0;
    v6 = v4;
  }
  else
  {
    this->m_criticalOperationsLockCount = 1;
    hkpWorldOperationUtil::removeEntityBP(this, entity);
    hkpWorldCallbackUtil::fireEntityRemoved(v5, v3);
    hkpEntityCallbackUtil::fireEntityRemoved(v3);
    v5->m_criticalOperationsAllowed.m_bool = 0;
    hkpWorldOperationUtil::removeEntitySI(v5, v3);
    if ( v3->m_collidable.m_boundingVolumeData.m_childShapeAabbs )
      hkpCollidable::BoundingVolumeData::deallocate(&v3->m_collidable.m_boundingVolumeData);
    if ( !v3->m_memSizeAndFlags )
      ((void (__fastcall *)(hkpEntity *))v3->vfptr[3].__vecDelDtor)(v3);
    hkReferencedObject::removeReference((hkReferencedObject *)&v3->vfptr);
    v7 = v5->m_criticalOperationsLockCount-- == 1;
    v5->m_criticalOperationsAllowed.m_bool = 1;
    if ( v7 && !v5->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v5->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v5);
      if ( v5->m_pendingOperationQueueCount == 1 )
      {
        if ( v5->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(v5);
      }
    }
    v4->m_bool = 1;
    v6 = v4;
  }
  return v6;
}

// File Line: 1174
// RVA: 0xD57980
void __fastcall hkpWorld::removeEntityBatch(hkpWorld *this, hkpEntity *const *entityBatch, int numEntities)
{
  __int64 v3; // rdi
  hkpEntity **v4; // rbx
  hkpWorld *v5; // rsi
  _QWORD *v6; // rax
  unsigned __int64 v7; // rcx
  _QWORD *v8; // r8
  unsigned __int64 v9; // rax
  int v10; // ecx
  signed __int64 v11; // r14
  hkpEntity **i; // r8
  _QWORD *v13; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  signed __int64 v16; // rcx
  int v17; // edi
  LPVOID v18; // rax
  hkLifoAllocator *v19; // rcx
  hkpTypedBroadPhaseHandlePair *v20; // rax
  int v21; // edx
  char *v22; // r8
  hkpBroadPhase *v23; // rcx
  _QWORD *v24; // r8
  _QWORD *v25; // rcx
  unsigned __int64 v26; // rax
  signed __int64 v27; // rcx
  int v28; // eax
  char *v29; // r15
  signed int v30; // edi
  hkLifoAllocator *v31; // rax
  int v32; // er8
  _QWORD *v33; // r8
  _QWORD *v34; // rcx
  unsigned __int64 v35; // rax
  signed __int64 v36; // rcx
  _QWORD *v37; // rax
  _QWORD *v38; // rcx
  _QWORD *v39; // r8
  unsigned __int64 v40; // rax
  signed __int64 v41; // rcx
  bool v42; // zf
  hkWorldOperation::BaseOperation operation[8]; // [rsp+30h] [rbp-48h]
  hkpEntity *const *v44; // [rsp+38h] [rbp-40h]
  __int16 v45; // [rsp+40h] [rbp-38h]
  hkpTypedBroadPhaseHandlePair *deletedPairs; // [rsp+48h] [rbp-30h]
  int numDeletedPairs; // [rsp+50h] [rbp-28h]
  int v48; // [rsp+54h] [rbp-24h]
  void *p; // [rsp+58h] [rbp-20h]
  int v50; // [rsp+60h] [rbp-18h]
  hkResult result; // [rsp+B0h] [rbp+38h]

  if ( numEntities > 0 )
  {
    v3 = numEntities;
    v4 = (hkpEntity **)entityBatch;
    v5 = this;
    if ( this->m_criticalOperationsLockCount )
    {
      v44 = entityBatch;
      operation[0].m_type.m_storage = 8;
      v45 = v3;
      hkpWorld::queueOperation(this, operation);
    }
    else
    {
      this->m_criticalOperationsLockCount = 1;
      v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = v6[1];
      v8 = v6;
      if ( v7 < v6[3] )
      {
        *(_QWORD *)v7 = "LtRemEntities";
        *(_QWORD *)(v7 + 16) = "StInit+CallBck";
        v9 = __rdtsc();
        *(_DWORD *)(v7 + 8) = v9;
        v8[1] = v7 + 24;
      }
      ((void (__fastcall *)(hkpSimulation *, hkpEntity **, _QWORD, hkpWorld *, signed int))v5->m_simulation->vfptr[6].__vecDelDtor)(
        v5->m_simulation,
        v4,
        (unsigned int)v3,
        v5,
        1);
      v10 = 0;
      *(_QWORD *)&operation[0].m_type.m_storage = 0i64;
      v44 = (hkpEntity *const *)0x8000000000000000i64;
      if ( (signed int)v3 > 0 )
      {
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, operation, v3, 8);
        v10 = (signed int)v44;
      }
      v11 = (signed __int64)&v4[v3];
      for ( i = v4; i != (hkpEntity **)v11; ++i )
      {
        if ( (*i)->m_collidable.m_shape )
        {
          *(_QWORD *)(*(_QWORD *)&operation[0].m_type.m_storage + 8i64 * v10) = (char *)*i + 68;
          v10 = (_DWORD)v44 + 1;
          LODWORD(v44) = (_DWORD)v44 + 1;
        }
      }
      if ( v10 )
      {
        v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v14 = (_QWORD *)v13[1];
        if ( (unsigned __int64)v14 < v13[3] )
        {
          *v14 = "StBroadPhase";
          v15 = __rdtsc();
          v16 = (signed __int64)(v14 + 2);
          *(_DWORD *)(v16 - 8) = v15;
          v13[1] = v16;
        }
        v17 = v5->m_broadPhaseQuerySize;
        deletedPairs = 0i64;
        numDeletedPairs = 0;
        v48 = 2147483648;
        v50 = v17;
        if ( v17 )
        {
          v18 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v19 = (hkLifoAllocator *)v18;
          v20 = (hkpTypedBroadPhaseHandlePair *)*((_QWORD *)v18 + 3);
          v21 = (16 * v17 + 127) & 0xFFFFFF80;
          v22 = (char *)v20 + v21;
          if ( v21 > v19->m_slabSize || v22 > v19->m_end )
            v20 = (hkpTypedBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v19, v21);
          else
            v19->m_cur = v22;
        }
        else
        {
          v20 = 0i64;
        }
        v23 = v5->m_broadPhase;
        deletedPairs = v20;
        p = v20;
        v48 = v17 | 0x80000000;
        ((void (__fastcall *)(hkpBroadPhase *, hkWorldOperation::BaseOperation *, hkpTypedBroadPhaseHandlePair **))v23->vfptr[4].__first_virtual_table_function__)(
          v23,
          operation,
          &deletedPairs);
        v24 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v25 = (_QWORD *)v24[1];
        if ( (unsigned __int64)v25 < v24[3] )
        {
          *v25 = "StDelAgents";
          v26 = __rdtsc();
          v27 = (signed __int64)(v25 + 2);
          *(_DWORD *)(v27 - 8) = v26;
          v24[1] = v27;
        }
        hkpTypedBroadPhaseDispatcher::removePairs(v5->m_broadPhaseDispatcher, deletedPairs, numDeletedPairs);
        v28 = numDeletedPairs;
        v29 = (char *)p;
        if ( p == deletedPairs )
          v28 = 0;
        numDeletedPairs = v28;
        v30 = (16 * v50 + 127) & 0xFFFFFF80;
        v31 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v32 = (v30 + 15) & 0xFFFFFFF0;
        if ( v30 > v31->m_slabSize || &v29[v32] != v31->m_cur || v31->m_firstNonLifoEnd == v29 )
          hkLifoAllocator::slowBlockFree(v31, v29, v32);
        else
          v31->m_cur = v29;
        numDeletedPairs = 0;
        if ( v48 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            deletedPairs,
            16 * v48);
      }
      LODWORD(v44) = 0;
      if ( SHIDWORD(v44) >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          *(void **)&operation[0].m_type.m_storage,
          8 * HIDWORD(v44));
      v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v34 = (_QWORD *)v33[1];
      if ( (unsigned __int64)v34 < v33[3] )
      {
        *v34 = "StRemoveCb";
        v35 = __rdtsc();
        v36 = (signed __int64)(v34 + 2);
        *(_DWORD *)(v36 - 8) = v35;
        v33[1] = v36;
      }
      for ( ; v4 != (hkpEntity **)v11; ++v4 )
      {
        hkpWorldCallbackUtil::fireEntityRemoved(v5, *v4);
        hkpEntityCallbackUtil::fireEntityRemoved(*v4);
        hkpWorldOperationUtil::removeEntitySI(v5, *v4);
        if ( (*v4)->m_collidable.m_boundingVolumeData.m_childShapeAabbs )
          hkpCollidable::BoundingVolumeData::deallocate(&(*v4)->m_collidable.m_boundingVolumeData);
        if ( !(*v4)->m_memSizeAndFlags )
          ((void (*)(void))(*v4)->vfptr[3].__vecDelDtor)();
        hkReferencedObject::removeReference((hkReferencedObject *)&(*v4)->vfptr);
      }
      v37 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v38 = (_QWORD *)v37[1];
      v39 = v37;
      if ( (unsigned __int64)v38 < v37[3] )
      {
        *v38 = "lt";
        v40 = __rdtsc();
        v41 = (signed __int64)(v38 + 2);
        *(_DWORD *)(v41 - 8) = v40;
        v39[1] = v41;
      }
      v42 = v5->m_criticalOperationsLockCount-- == 1;
      if ( v42 && !v5->m_blockExecutingPendingOperations.m_bool )
      {
        if ( v5->m_pendingOperationsCount )
          hkpWorld::internal_executePendingOperations(v5);
        if ( v5->m_pendingOperationQueueCount == 1 )
        {
          if ( v5->m_pendingBodyOperationsCount )
            hkpWorld::internal_executePendingBodyOperations(v5);
        }
      }
    }
  }
}

// File Line: 1266
// RVA: 0xD58FB0
void __fastcall hkpWorld::activateRegion(hkpWorld *this, hkAabb *aabb)
{
  hkAabb *v2; // rdi
  hkpWorld *v3; // rbx
  _QWORD **v4; // rax
  hkpBroadPhase *v5; // rcx
  int v6; // edx
  int v7; // ebx
  __int64 v8; // rdi
  __int64 v9; // rax
  hkpEntity *v10; // rcx
  char *v11; // [rsp+20h] [rbp-28h]
  int v12; // [rsp+28h] [rbp-20h]
  int v13; // [rsp+2Ch] [rbp-1Ch]
  hkWorldOperation::BaseOperation operation; // [rsp+30h] [rbp-18h]
  void *v15; // [rsp+38h] [rbp-10h]

  v2 = aabb;
  v3 = this;
  if ( this->m_criticalOperationsLockCount )
  {
    operation.m_type.m_storage = 33;
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (void *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 32i64);
    hkString::memCpy(v15, v2, 32);
    hkpWorld::queueOperation(v3, &operation);
  }
  else
  {
    v5 = this->m_broadPhase;
    v11 = 0i64;
    v12 = 0;
    v13 = 2147483648;
    ((void (__fastcall *)(hkpBroadPhase *, hkAabb *, char **))v5->vfptr[9].__vecDelDtor)(v5, aabb, &v11);
    v6 = v12;
    v7 = 0;
    if ( v12 > 0 )
    {
      v8 = 0i64;
      do
      {
        v9 = *(_QWORD *)&v11[v8 + 8] + *(char *)(*(_QWORD *)&v11[v8 + 8] + 5i64);
        if ( *(_BYTE *)(v9 + 40) == 1 )
        {
          v10 = (hkpEntity *)(v9 + *(char *)(v9 + 32));
          if ( v10 )
          {
            hkpEntity::activate(v10);
            v6 = v12;
          }
        }
        ++v7;
        v8 += 16i64;
      }
      while ( v7 < v6 );
    }
    v12 = 0;
    if ( v13 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v11,
        16 * v13);
  }
}

// File Line: 1399
// RVA: 0xD57DA0
hkpConstraintInstance *__fastcall hkpWorld::addConstraint(hkpWorld *this, hkpConstraintInstance *constraint)
{
  hkpConstraintInstance *v2; // rdi
  hkpWorld *v3; // rbx
  hkpConstraintInstance *result; // rax
  __int64 v5; // rdx
  hkpConstraintData *v6; // rsi
  hkpConstraintInstance *v7; // rsi
  hkpAction *v8; // rdx
  bool v9; // zf
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-18h]
  hkpConstraintInstance *v11; // [rsp+28h] [rbp-10h]
  __int16 v12; // [rsp+40h] [rbp+8h]
  __int16 v13; // [rsp+44h] [rbp+Ch]

  v2 = constraint;
  v3 = this;
  if ( this->m_criticalOperationsLockCount )
  {
    v11 = constraint;
    operation.m_type.m_storage = 9;
    hkpWorld::queueOperation(this, &operation);
    result = 0i64;
  }
  else
  {
    if ( ((unsigned int (*)(void))constraint->m_data->vfptr[1].__first_virtual_table_function__)() == 12 )
    {
      v6 = v2->m_data;
      if ( !LOWORD(v6[3].vfptr) )
      {
        LOBYTE(v5) = 1;
        (*(void (__fastcall **)(unsigned __int64, __int64, __int16 *))(*(_QWORD *)v6[2].m_userData + 136i64))(
          v6[2].m_userData,
          v5,
          &v12);
        LOWORD(v6[3].vfptr) = v12;
        WORD1(v6[3].vfptr) = v13;
      }
    }
    v3->m_blockExecutingPendingOperations.m_bool = 1;
    hkpConstraintInstance::pointNullsToFixedRigidBody(v2);
    v2->m_uid = ++v3->m_lastConstraintUid;
    v7 = hkpWorldOperationUtil::addConstraintImmediately(v3, v2, DO_FIRE_CALLBACKS);
    if ( ((unsigned int (__fastcall *)(hkpConstraintInstance *))v2->vfptr[3].__vecDelDtor)(v2) == 1 )
    {
      v8 = (hkpAction *)v2[1].m_owner;
      if ( !v8->m_world )
        hkpWorld::addAction(v3, v8);
      ((void (*)(void))v2->m_data->vfptr[11].__first_virtual_table_function__)();
    }
    v9 = v3->m_criticalOperationsLockCount == 0;
    v3->m_blockExecutingPendingOperations.m_bool = 0;
    if ( v9 )
    {
      if ( v3->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v3);
    }
    result = v7;
  }
  return result;
}

// File Line: 1519
// RVA: 0xD57FC0
hkpConstraintInstance *__fastcall hkpWorld::createAndAddConstraintInstance(hkpWorld *this, hkpRigidBody *bodyA, hkpRigidBody *bodyB, hkpConstraintData *constraintData)
{
  hkpWorld *v4; // rsi
  hkpConstraintData *v5; // rdi
  hkpRigidBody *v6; // rbx
  hkpRigidBody *v7; // rbp
  _QWORD **v8; // rax
  hkpConstraintInstance *v9; // rax
  hkpConstraintInstance *v10; // rax
  hkpConstraintInstance *v11; // rbx

  v4 = this;
  v5 = constraintData;
  v6 = bodyB;
  v7 = bodyA;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 112i64);
  if ( v9 )
  {
    hkpConstraintInstance::hkpConstraintInstance(v9, (hkpEntity *)&v7->vfptr, (hkpEntity *)&v6->vfptr, v5, PRIORITY_PSI);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v11->m_userData = v5->m_userData;
  hkpWorld::addConstraint(v4, v11);
  return v11;
}

// File Line: 1531
// RVA: 0xD57EC0
hkBool *__fastcall hkpWorld::removeConstraint(hkpWorld *this, hkBool *result, hkpConstraintInstance *constraint)
{
  hkpConstraintInstance *v3; // rdi
  hkBool *v4; // rsi
  hkpWorld *v5; // rbx
  hkBool *v6; // rax
  hkpAction *v7; // rdx
  bool v8; // zf
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-18h]
  hkpConstraintInstance *v10; // [rsp+28h] [rbp-10h]

  v3 = constraint;
  v4 = result;
  v5 = this;
  if ( this->m_criticalOperationsLockCount )
  {
    operation.m_type.m_storage = 10;
    v10 = constraint;
    hkpWorld::queueOperation(this, &operation);
    v4->m_bool = 0;
    v6 = v4;
  }
  else
  {
    this->m_criticalOperationsLockCount = 1;
    if ( ((unsigned int (__fastcall *)(hkpConstraintInstance *))constraint->vfptr[3].__vecDelDtor)(constraint) == 1 )
    {
      v7 = (hkpAction *)v3[1].m_owner;
      if ( v7->m_world == v5 )
        hkpWorld::removeActionImmediately(v5, v7);
    }
    hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
    hkpWorldOperationUtil::removeConstraintImmediately(v5, v3, DO_FIRE_CALLBACKS);
    hkpConstraintInstance::setFixedRigidBodyPointersToZero(v3, v5);
    hkReferencedObject::removeReference((hkReferencedObject *)&v3->vfptr);
    v8 = v5->m_criticalOperationsLockCount-- == 1;
    if ( v8 && !v5->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v5->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v5);
      if ( v5->m_pendingOperationQueueCount == 1 )
      {
        if ( v5->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(v5);
      }
    }
    v4->m_bool = 1;
    v6 = v4;
  }
  return v6;
}

// File Line: 1574
// RVA: 0xD58060
hkpAction *__fastcall hkpWorld::addAction(hkpWorld *this, hkpAction *action)
{
  hkpAction *v2; // r14
  hkpWorld *v3; // rbx
  hkpAction *result; // rax
  hkBaseObjectVtbl *v5; // rax
  hkpEntity *v6; // rsi
  int v7; // ebp
  __int64 v8; // r15
  signed __int64 v9; // rdi
  hkpEntity *v10; // r8
  hkpSimulationIsland *v11; // rax
  bool v12; // zf
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-68h]
  hkpAction *v14; // [rsp+28h] [rbp-60h]
  char *v15; // [rsp+30h] [rbp-58h]
  int v16; // [rsp+38h] [rbp-50h]
  int v17; // [rsp+3Ch] [rbp-4Ch]
  char v18; // [rsp+40h] [rbp-48h]

  v2 = action;
  v3 = this;
  if ( this->m_criticalOperationsLockCount )
  {
    v14 = action;
    operation.m_type.m_storage = 11;
    hkpWorld::queueOperation(this, &operation);
    result = 0i64;
  }
  else
  {
    hkReferencedObject::addReference((hkReferencedObject *)&action->vfptr);
    ++v3->m_criticalOperationsLockCount;
    v15 = &v18;
    v5 = v2->vfptr;
    v16 = 0;
    v17 = -2147483644;
    v5[2].__vecDelDtor((hkBaseObject *)&v2->vfptr, (unsigned int)&v15);
    v6 = 0i64;
    v2->m_world = v3;
    v7 = 0;
    if ( v16 <= 0 )
      goto LABEL_27;
    v8 = 0i64;
    do
    {
      v9 = *(_QWORD *)&v15[v8] + 672i64;
      if ( *(_WORD *)(*(_QWORD *)&v15[v8] + 680i64) == (*(_WORD *)(*(_QWORD *)&v15[v8] + 682i64) & 0x3FFF) )
        hkSmallArrayUtil::_reserveMore((void *)(*(_QWORD *)&v15[v8] + 672i64), 8);
      *(_QWORD *)(*(_QWORD *)v9 + 8i64 * (unsigned __int16)(*(_WORD *)(v9 + 8))++) = v2;
      v10 = *(hkpEntity **)&v15[v8];
      v11 = v10->m_simulationIsland;
      if ( v11->m_storageIndex != -1 )
      {
        if ( v6 )
        {
          if ( v6->m_simulationIsland != v11 )
            hkpWorldOperationUtil::mergeIslands(v3, v6, v10);
        }
        else
        {
          v6 = *(hkpEntity **)&v15[v8];
          hkpSimulationIsland::addAction(v10->m_simulationIsland, v2);
        }
      }
      ++v7;
      v8 += 8i64;
    }
    while ( v7 < v16 );
    if ( !v6 )
LABEL_27:
      hkpSimulationIsland::addAction(*(hkpSimulationIsland **)(*(_QWORD *)v15 + 296i64), v2);
    v12 = v3->m_criticalOperationsLockCount-- == 1;
    if ( v12 && !v3->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v3->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v3);
      if ( v3->m_pendingOperationQueueCount == 1 && v3->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v3);
    }
    hkpWorldCallbackUtil::fireActionAdded(v3, v2);
    v16 = 0;
    if ( v17 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v15,
        8 * v17);
    result = v2;
  }
  return result;
}

// File Line: 1644
// RVA: 0xD58280
void __fastcall hkpWorld::removeAction(hkpWorld *this, hkpAction *action)
{
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-18h]
  hkpAction *v3; // [rsp+28h] [rbp-10h]

  if ( this->m_criticalOperationsLockCount )
  {
    v3 = action;
    operation.m_type.m_storage = 12;
    hkpWorld::queueOperation(this, &operation);
  }
  else
  {
    hkpWorld::removeActionImmediately(this, action);
  }
}

// File Line: 1662
// RVA: 0xD582C0
void __fastcall hkpWorld::removeActionImmediately(hkpWorld *this, hkpAction *action)
{
  hkpWorld *v2; // rdi
  hkpAction *v3; // rbx
  hkBaseObjectVtbl *v4; // rax
  int v5; // er10
  __int64 v6; // r9
  __int64 v7; // r8
  signed __int64 v8; // rax
  signed __int64 v9; // rdx
  hkpAction **v10; // rcx
  hkpSimulationIsland *v11; // rbp
  hkpWorld *v12; // r14
  bool v13; // zf
  char *v14; // [rsp+20h] [rbp-38h]
  int v15; // [rsp+28h] [rbp-30h]
  int v16; // [rsp+2Ch] [rbp-2Ch]
  char v17; // [rsp+30h] [rbp-28h]

  v2 = this;
  v3 = action;
  hkReferencedObject::addReference((hkReferencedObject *)&action->vfptr);
  ++v2->m_criticalOperationsLockCount;
  hkpWorldCallbackUtil::fireActionRemoved(v2, v3);
  v14 = &v17;
  v4 = v3->vfptr;
  v15 = 0;
  v16 = -2147483644;
  v4[2].__vecDelDtor((hkBaseObject *)&v3->vfptr, (unsigned int)&v14);
  v5 = 0;
  if ( v15 > 0 )
  {
    v6 = 0i64;
    do
    {
      v7 = *(_QWORD *)&v14[v6];
      v8 = 0i64;
      v9 = *(unsigned __int16 *)(v7 + 680);
      if ( v9 <= 0 )
      {
LABEL_7:
        v8 = -1i64;
      }
      else
      {
        v10 = *(hkpAction ***)(v7 + 672);
        while ( *v10 != v3 )
        {
          ++v8;
          ++v10;
          if ( v8 >= v9 )
            goto LABEL_7;
        }
      }
      --*(_WORD *)(v7 + 680);
      ++v5;
      v6 += 8i64;
      *(_QWORD *)(*(_QWORD *)(v7 + 672) + 8 * v8) = *(_QWORD *)(*(_QWORD *)(v7 + 672)
                                                              + 8i64 * *(unsigned __int16 *)(v7 + 680));
    }
    while ( v5 < v15 );
  }
  v11 = v3->m_island;
  hkpSimulationIsland::removeAction(v3->m_island, v3);
  v3->m_world = 0i64;
  hkReferencedObject::removeReference((hkReferencedObject *)&v3->vfptr);
  v12 = v11->m_world;
  EnterCriticalSection(&v12->m_islandDirtyListCriticalSection->m_section);
  if ( v11->m_dirtyListIndex == -1 )
  {
    v11->m_dirtyListIndex = v12->m_dirtySimulationIslands.m_size;
    if ( v12->m_dirtySimulationIslands.m_size == (v12->m_dirtySimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v12->m_dirtySimulationIslands,
        8);
    v12->m_dirtySimulationIslands.m_data[v12->m_dirtySimulationIslands.m_size++] = v11;
  }
  LeaveCriticalSection(&v12->m_islandDirtyListCriticalSection->m_section);
  v15 = 0;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v14,
      8 * v16);
  v13 = v2->m_criticalOperationsLockCount-- == 1;
  if ( v13 && !v2->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v2->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v2);
    if ( v2->m_pendingOperationQueueCount == 1 && v2->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(v2);
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v3->vfptr);
}

// File Line: 1703
// RVA: 0xD5D690
void __fastcall hkpWorld::attachActionToEntity(hkpWorld *this, hkpAction *action, hkpEntity *entity)
{
  hkSmallArray<hkpAction *> *v3; // rdi
  hkpWorld *v4; // rbp
  hkpEntity *v5; // rbx
  hkpAction *v6; // rsi
  hkpSimulationIsland *v7; // r8

  v3 = &entity->m_actions;
  v4 = this;
  v5 = entity;
  v6 = action;
  if ( entity->m_actions.m_size == (entity->m_actions.m_capacityAndFlags & 0x3FFF) )
    hkSmallArrayUtil::_reserveMore(v3, 8);
  v3->m_data[v3->m_size++] = v6;
  v7 = v6->m_island;
  if ( v7->m_storageIndex != -1 || v5->m_motion.m_type.m_storage == 5 )
  {
    if ( v5->m_simulationIsland != v7 && v5->m_motion.m_type.m_storage != 5 )
      hkpWorldOperationUtil::mergeIslands(v4, v5, *v7->m_entities.m_data);
  }
  else
  {
    hkpSimulationIsland::removeAction(v6->m_island, v6);
    hkpSimulationIsland::addAction(v5->m_simulationIsland, v6);
  }
}

// File Line: 1729
// RVA: 0xD5D760
void __fastcall hkpWorld::detachActionFromEntity(hkpWorld *this, hkpAction *action, hkpEntity *entity)
{
  hkpAction *v3; // rdi
  __int64 v4; // rdx
  signed int v5; // er9
  __int64 v6; // rcx
  hkpEntity *v7; // rsi
  hkpAction **v8; // rax
  __int64 v9; // rax
  hkBaseObjectVtbl *v10; // rax
  char *v11; // r9
  hkpSimulationIsland *v12; // rbx
  int v13; // edx
  __int64 v14; // rax
  hkpSimulationIsland *v15; // rcx
  char *v16; // [rsp+20h] [rbp-38h]
  int v17; // [rsp+28h] [rbp-30h]
  int v18; // [rsp+2Ch] [rbp-2Ch]
  char v19; // [rsp+30h] [rbp-28h]

  v3 = action;
  v4 = entity->m_actions.m_size;
  v5 = 0;
  v6 = 0i64;
  v7 = entity;
  if ( v4 <= 0 )
  {
LABEL_5:
    v5 = -1;
  }
  else
  {
    v8 = entity->m_actions.m_data;
    while ( *v8 != v3 )
    {
      ++v6;
      ++v5;
      ++v8;
      if ( v6 >= v4 )
        goto LABEL_5;
    }
  }
  v9 = (unsigned __int16)(v4 - 1);
  entity->m_actions.m_size = v9;
  entity->m_actions.m_data[v5] = entity->m_actions.m_data[v9];
  *((_BYTE *)entity->m_simulationIsland + 49) = *((_BYTE *)entity->m_simulationIsland + 49) & 0xFD | 1;
  v16 = &v19;
  v10 = v3->vfptr;
  v17 = 0;
  v18 = -2147483644;
  v10[2].__vecDelDtor((hkBaseObject *)&v3->vfptr, (unsigned int)&v16);
  v11 = v16;
  v12 = 0i64;
  v13 = 0;
  if ( v17 > 0 )
  {
    v14 = (__int64)v16;
    do
    {
      if ( *(hkpEntity **)v14 != v7 )
      {
        v12 = *(hkpSimulationIsland **)(*(_QWORD *)v14 + 296i64);
        if ( v12->m_storageIndex != -1 )
          break;
      }
      ++v13;
      v14 += 8i64;
    }
    while ( v13 < v17 );
  }
  v15 = v3->m_island;
  if ( v12 != v15 )
  {
    hkpSimulationIsland::removeAction(v15, v3);
    hkpSimulationIsland::addAction(v12, v3);
    v11 = v16;
  }
  v17 = 0;
  if ( v18 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v11,
      8 * v18);
}

// File Line: 1772
// RVA: 0xD584B0
hkpPhantom *__fastcall hkpWorld::addPhantom(hkpWorld *this, hkpPhantom *phantom)
{
  hkpWorld *v2; // rbx
  int v3; // ecx
  hkpPhantom *v4; // rdi
  hkpPhantom *result; // rax
  bool v6; // zf
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-18h]
  hkpPhantom *v8; // [rsp+28h] [rbp-10h]

  v2 = this;
  v3 = this->m_criticalOperationsLockCount;
  v4 = phantom;
  if ( v3 + v2->m_criticalOperationsLockCountForPhantoms )
  {
    v8 = phantom;
    operation.m_type.m_storage = 14;
    hkpWorld::queueOperation(v2, &operation);
    result = 0i64;
  }
  else
  {
    v2->m_criticalOperationsLockCount = v3 + 1;
    if ( !phantom->m_collidable.m_motion )
      phantom->m_collidable.m_motion = (const void *)((__int64 (__fastcall *)(hkpPhantom *))phantom->vfptr[2].__first_virtual_table_function__)(phantom);
    v4->m_world = v2;
    hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
    if ( v2->m_phantoms.m_size == (v2->m_phantoms.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_phantoms, 8);
    v2->m_phantoms.m_data[v2->m_phantoms.m_size++] = v4;
    hkpWorldOperationUtil::addPhantomBP(v2, v4);
    hkpWorldCallbackUtil::firePhantomAdded(v2, v4);
    hkpPhantom::firePhantomAdded(v4);
    v6 = v2->m_criticalOperationsLockCount-- == 1;
    if ( v6 && !v2->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v2->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v2);
      if ( v2->m_pendingOperationQueueCount == 1 )
      {
        if ( v2->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(v2);
      }
    }
    result = v4;
  }
  return result;
}

// File Line: 1823
// RVA: 0xD585D0
void __fastcall hkpWorld::addPhantomBatch(hkpWorld *this, hkpPhantom *const *phantomBatch, int numPhantoms)
{
  hkpWorld *v3; // rdi
  int v4; // ecx
  __int64 v5; // rbx
  hkpPhantom *const *v6; // r13
  __int64 v7; // r15
  hkLifoAllocator *v8; // rax
  char *v9; // r8
  int v10; // edx
  char *v11; // rcx
  hkLifoAllocator *v12; // rax
  char *v13; // rcx
  int v14; // edx
  char *v15; // r8
  __int64 v16; // r14
  __int64 v17; // r12
  hkpPhantom *v18; // rbx
  int v19; // ebx
  LPVOID v20; // rax
  hkLifoAllocator *v21; // rcx
  hkpTypedBroadPhaseHandlePair *v22; // rax
  int v23; // edx
  char *v24; // r8
  hkpBroadPhase *v25; // rcx
  hkpCollisionFilter *v26; // r9
  hkpCollidableCollidableFilter *v27; // r9
  bool v28; // zf
  int v29; // eax
  char *v30; // rdi
  signed int v31; // ebx
  hkLifoAllocator *v32; // rax
  int v33; // er8
  int v34; // eax
  char *v35; // rdi
  signed int v36; // ebx
  hkLifoAllocator *v37; // rax
  int v38; // er8
  int v39; // eax
  char *v40; // rdi
  signed int v41; // ebx
  hkLifoAllocator *v42; // rax
  int v43; // er8
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-49h]
  hkpPhantom *const *v45; // [rsp+28h] [rbp-41h]
  __int16 v46; // [rsp+30h] [rbp-39h]
  hkpTypedBroadPhaseHandlePair *newPairs; // [rsp+38h] [rbp-31h]
  int numNewPairs; // [rsp+40h] [rbp-29h]
  int v49; // [rsp+44h] [rbp-25h]
  void *p; // [rsp+48h] [rbp-21h]
  int v51; // [rsp+50h] [rbp-19h]
  char *v52; // [rsp+58h] [rbp-11h]
  int v53; // [rsp+60h] [rbp-9h]
  int v54; // [rsp+64h] [rbp-5h]
  void *v55; // [rsp+68h] [rbp-1h]
  int v56; // [rsp+70h] [rbp+7h]
  char *v57; // [rsp+78h] [rbp+Fh]
  int v58; // [rsp+80h] [rbp+17h]
  int v59; // [rsp+84h] [rbp+1Bh]
  void *v60; // [rsp+88h] [rbp+1Fh]
  int v61; // [rsp+90h] [rbp+27h]

  if ( numPhantoms > 0 )
  {
    v3 = this;
    v4 = this->m_criticalOperationsLockCount;
    v5 = (unsigned int)numPhantoms;
    v6 = phantomBatch;
    if ( v4 + v3->m_criticalOperationsLockCountForPhantoms )
    {
      v45 = phantomBatch;
      operation.m_type.m_storage = 16;
      v46 = numPhantoms;
      hkpWorld::queueOperation(v3, &operation);
    }
    else
    {
      v3->m_criticalOperationsLockCount = v4 + 1;
      v7 = 0i64;
      v57 = 0i64;
      v58 = 0;
      v59 = 2147483648;
      v61 = numPhantoms;
      v8 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v9 = (char *)v8->m_cur;
      v10 = (8 * v5 + 127) & 0xFFFFFF80;
      v11 = &v9[v10];
      if ( v10 > v8->m_slabSize || v11 > v8->m_end )
        v9 = (char *)hkLifoAllocator::allocateFromNewSlab(v8, v10);
      else
        v8->m_cur = v11;
      v57 = v9;
      v60 = v9;
      v52 = 0i64;
      v53 = 0;
      v54 = 2147483648;
      v56 = v5;
      v59 = v5 | 0x80000000;
      v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v13 = (char *)v12->m_cur;
      v14 = (32 * v5 + 127) & 0xFFFFFF80;
      v15 = &v13[v14];
      if ( v14 > v12->m_slabSize || v15 > v12->m_end )
        v13 = (char *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
      else
        v12->m_cur = v15;
      v52 = v13;
      v54 = v5 | 0x80000000;
      v55 = v13;
      v53 = v5;
      v58 = v5;
      if ( (signed int)v5 > 0 )
      {
        v16 = 0i64;
        v17 = v5;
        do
        {
          v18 = v6[v16];
          if ( !v18->m_collidable.m_motion )
            v18->m_collidable.m_motion = (const void *)((__int64 (__fastcall *)(hkpPhantom *const ))v18->vfptr[2].__first_virtual_table_function__)(v6[v16]);
          v18->m_world = v3;
          *(_QWORD *)&v57[v16 * 8] = (char *)v18 + 68;
          ((void (__fastcall *)(hkpPhantom *, char *))v18->vfptr[3].__first_virtual_table_function__)(v18, &v52[v7]);
          hkpPhantom::setBoundingVolumeData(v18, (hkAabb *)&v52[v7]);
          hkReferencedObject::addReference((hkReferencedObject *)&v18->vfptr);
          if ( v3->m_phantoms.m_size == (v3->m_phantoms.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_phantoms, 8);
          v3->m_phantoms.m_data[v3->m_phantoms.m_size++] = v18;
          hkpWorldCallbackUtil::firePhantomAdded(v3, v18);
          hkpPhantom::firePhantomAdded(v18);
          v7 += 32i64;
          ++v16;
          --v17;
        }
        while ( v17 );
        LODWORD(v7) = 0;
      }
      v19 = v3->m_broadPhaseQuerySize;
      newPairs = 0i64;
      numNewPairs = 0;
      v49 = 2147483648;
      v51 = v19;
      if ( v19 )
      {
        v20 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v21 = (hkLifoAllocator *)v20;
        v22 = (hkpTypedBroadPhaseHandlePair *)*((_QWORD *)v20 + 3);
        v23 = (16 * v19 + 127) & 0xFFFFFF80;
        v24 = (char *)v22 + v23;
        if ( v23 > v21->m_slabSize || v24 > v21->m_end )
          v22 = (hkpTypedBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v21, v23);
        else
          v21->m_cur = v24;
      }
      else
      {
        v22 = 0i64;
      }
      v25 = v3->m_broadPhase;
      newPairs = v22;
      p = v22;
      v49 = v19 | 0x80000000;
      ((void (__fastcall *)(hkpBroadPhase *, char **, char **, hkpTypedBroadPhaseHandlePair **))v25->vfptr[3].__first_virtual_table_function__)(
        v25,
        &v57,
        &v52,
        &newPairs);
      v26 = v3->m_collisionFilter;
      if ( v26 )
        v27 = (hkpCollidableCollidableFilter *)&v26->vfptr;
      else
        v27 = 0i64;
      hkpTypedBroadPhaseDispatcher::addPairs(v3->m_broadPhaseDispatcher, newPairs, numNewPairs, v27);
      v28 = v3->m_criticalOperationsLockCount-- == 1;
      if ( v28 && !v3->m_blockExecutingPendingOperations.m_bool )
      {
        if ( v3->m_pendingOperationsCount )
          hkpWorld::internal_executePendingOperations(v3);
        if ( v3->m_pendingOperationQueueCount == 1 && v3->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(v3);
      }
      v29 = numNewPairs;
      v30 = (char *)p;
      if ( p == newPairs )
        v29 = v7;
      numNewPairs = v29;
      v31 = (16 * v51 + 127) & 0xFFFFFF80;
      v32 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v33 = (v31 + 15) & 0xFFFFFFF0;
      if ( v31 > v32->m_slabSize || &v30[v33] != v32->m_cur || v32->m_firstNonLifoEnd == v30 )
        hkLifoAllocator::slowBlockFree(v32, v30, v33);
      else
        v32->m_cur = v30;
      numNewPairs = v7;
      if ( v49 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          newPairs,
          16 * v49);
      v34 = v53;
      v35 = (char *)v55;
      newPairs = 0i64;
      if ( v55 == v52 )
        v34 = v7;
      v49 = 2147483648;
      v53 = v34;
      v36 = (32 * v56 + 127) & 0xFFFFFF80;
      v37 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v38 = (v36 + 15) & 0xFFFFFFF0;
      if ( v36 > v37->m_slabSize || &v35[v38] != v37->m_cur || v37->m_firstNonLifoEnd == v35 )
        hkLifoAllocator::slowBlockFree(v37, v35, v38);
      else
        v37->m_cur = v35;
      v53 = v7;
      if ( v54 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v52,
          32 * v54);
      v39 = v58;
      v40 = (char *)v60;
      v52 = 0i64;
      v54 = 2147483648;
      if ( v60 == v57 )
        v39 = v7;
      v58 = v39;
      v41 = (8 * v61 + 127) & 0xFFFFFF80;
      v42 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v43 = (v41 + 15) & 0xFFFFFFF0;
      if ( v41 > v42->m_slabSize || &v40[v43] != v42->m_cur || v42->m_firstNonLifoEnd == v40 )
        hkLifoAllocator::slowBlockFree(v42, v40, v43);
      else
        v42->m_cur = v40;
      v58 = v7;
      if ( v59 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v57,
          8 * v59);
    }
  }
}     v42->m_cur = v40;
      v58 = v7;
      if ( v59 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufF

// File Line: 1892
// RVA: 0xD58AB0
void __fastcall hkpWorld::removePhantom(hkpWorld *this, hkpPhantom *phantom)
{
  hkpWorld *v2; // rbx
  hkpPhantom *v3; // rdi
  int v4; // edx
  __int64 v5; // r9
  signed int v6; // er8
  __int64 v7; // rcx
  hkpPhantom **v8; // rax
  bool v9; // zf
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-18h]
  hkpPhantom *v11; // [rsp+28h] [rbp-10h]

  v2 = this;
  v3 = phantom;
  v4 = this->m_criticalOperationsLockCount;
  if ( v4 + this->m_criticalOperationsLockCountForPhantoms )
  {
    operation.m_type.m_storage = 15;
    v11 = v3;
    hkpWorld::queueOperation(this, &operation);
  }
  else
  {
    this->m_criticalOperationsLockCount = v4 + 1;
    hkpWorldCallbackUtil::firePhantomRemoved(this, v3);
    hkpPhantom::firePhantomRemoved(v3);
    hkpWorldOperationUtil::removePhantomBP(v2, v3);
    v5 = v2->m_phantoms.m_size;
    v6 = 0;
    v7 = 0i64;
    if ( (signed int)v5 <= 0 )
    {
LABEL_7:
      v6 = -1;
    }
    else
    {
      v8 = v2->m_phantoms.m_data;
      while ( *v8 != v3 )
      {
        ++v7;
        ++v6;
        ++v8;
        if ( v7 >= v5 )
          goto LABEL_7;
      }
    }
    v2->m_phantoms.m_size = v5 - 1;
    if ( (_DWORD)v5 - 1 != v6 )
      v2->m_phantoms.m_data[v6] = v2->m_phantoms.m_data[(signed int)v5 - 1];
    v9 = v3->m_memSizeAndFlags == 0;
    v3->m_world = 0i64;
    if ( v9 )
      ((void (__fastcall *)(hkpPhantom *))v3->vfptr[7].__vecDelDtor)(v3);
    hkReferencedObject::removeReference((hkReferencedObject *)&v3->vfptr);
    v9 = v2->m_criticalOperationsLockCount-- == 1;
    if ( v9 && !v2->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v2->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v2);
      if ( v2->m_pendingOperationQueueCount == 1 )
      {
        if ( v2->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(v2);
      }
    }
  }
}

// File Line: 1941
// RVA: 0xD58BE0
void __fastcall hkpWorld::removePhantomBatch(hkpWorld *this, hkpPhantom *const *phantomBatch, int numPhantoms)
{
  hkpWorld *v3; // rdi
  int v4; // ecx
  __int64 v5; // r14
  hkpPhantom *const *v6; // r12
  hkLifoAllocator *v7; // rax
  char *v8; // r8
  int v9; // edx
  char *v10; // rcx
  hkpPhantom **v11; // rsi
  __int64 v12; // r15
  hkpPhantom *v13; // rbx
  int v14; // ebx
  hkLifoAllocator *v15; // rax
  hkLifoAllocator *v16; // rcx
  char *v17; // rax
  int v18; // edx
  char *v19; // r8
  hkpBroadPhase *v20; // rcx
  int v21; // eax
  char *v22; // rsi
  signed int v23; // ebx
  hkLifoAllocator *v24; // rax
  int v25; // er8
  __int64 v26; // rsi
  hkReferencedObject *v27; // rbx
  signed int v28; // edx
  signed __int64 v29; // rax
  signed __int64 v30; // r9
  hkpPhantom **v31; // rcx
  bool v32; // zf
  int v33; // eax
  char *v34; // rdi
  signed int v35; // ebx
  hkLifoAllocator *v36; // rax
  int v37; // er8
  hkWorldOperation::BaseOperation operation[8]; // [rsp+20h] [rbp-48h]
  int numDeletedPairs[2]; // [rsp+28h] [rbp-40h]
  void *p; // [rsp+30h] [rbp-38h]
  int v41; // [rsp+38h] [rbp-30h]
  _QWORD *v42; // [rsp+40h] [rbp-28h]
  int v43; // [rsp+48h] [rbp-20h]
  int v44; // [rsp+4Ch] [rbp-1Ch]
  void *v45; // [rsp+50h] [rbp-18h]
  int v46; // [rsp+58h] [rbp-10h]

  if ( numPhantoms > 0 )
  {
    v3 = this;
    v4 = this->m_criticalOperationsLockCount;
    v5 = (unsigned int)numPhantoms;
    v6 = phantomBatch;
    if ( v4 + v3->m_criticalOperationsLockCountForPhantoms )
    {
      *(_QWORD *)numDeletedPairs = phantomBatch;
      operation[0].m_type.m_storage = 17;
      LOWORD(p) = numPhantoms;
      hkpWorld::queueOperation(v3, operation);
    }
    else
    {
      v3->m_criticalOperationsLockCount = v4 + 1;
      v42 = 0i64;
      v43 = 0;
      v44 = 2147483648;
      v46 = numPhantoms;
      v7 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v8 = (char *)v7->m_cur;
      v9 = (8 * v5 + 127) & 0xFFFFFF80;
      v10 = &v8[v9];
      if ( v9 > v7->m_slabSize || v10 > v7->m_end )
        v8 = (char *)hkLifoAllocator::allocateFromNewSlab(v7, v9);
      else
        v7->m_cur = v10;
      v42 = v8;
      v45 = v8;
      v44 = v5 | 0x80000000;
      if ( (signed int)v5 > 0 )
      {
        v11 = (hkpPhantom **)v6;
        v12 = v5;
        do
        {
          v13 = *v11;
          v42[v43++] = (char *)*v11 + 68;
          hkpWorldCallbackUtil::firePhantomRemoved(v3, v13);
          hkpPhantom::firePhantomRemoved(v13);
          ++v11;
          --v12;
        }
        while ( v12 );
      }
      if ( v43 )
      {
        v14 = v3->m_broadPhaseQuerySize;
        *(_QWORD *)&operation[0].m_type.m_storage = 0i64;
        numDeletedPairs[0] = 0;
        numDeletedPairs[1] = 2147483648;
        v41 = v14;
        if ( v14 )
        {
          v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v16 = v15;
          v17 = (char *)v15->m_cur;
          v18 = (16 * v14 + 127) & 0xFFFFFF80;
          v19 = &v17[v18];
          if ( v18 > v16->m_slabSize || v19 > v16->m_end )
            v17 = (char *)hkLifoAllocator::allocateFromNewSlab(v16, v18);
          else
            v16->m_cur = v19;
        }
        else
        {
          v17 = 0i64;
        }
        v20 = v3->m_broadPhase;
        *(_QWORD *)&operation[0].m_type.m_storage = v17;
        p = v17;
        numDeletedPairs[1] = v14 | 0x80000000;
        ((void (__fastcall *)(hkpBroadPhase *, _QWORD **, hkWorldOperation::BaseOperation *))v20->vfptr[4].__first_virtual_table_function__)(
          v20,
          &v42,
          operation);
        hkpTypedBroadPhaseDispatcher::removePairs(
          v3->m_broadPhaseDispatcher,
          *(hkpTypedBroadPhaseHandlePair **)&operation[0].m_type.m_storage,
          numDeletedPairs[0]);
        v21 = numDeletedPairs[0];
        v22 = (char *)p;
        if ( p == *(void **)&operation[0].m_type.m_storage )
          v21 = 0;
        numDeletedPairs[0] = v21;
        v23 = (16 * v41 + 127) & 0xFFFFFF80;
        v24 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v25 = (v23 + 15) & 0xFFFFFFF0;
        if ( v23 > v24->m_slabSize || &v22[v25] != v24->m_cur || v24->m_firstNonLifoEnd == v22 )
          hkLifoAllocator::slowBlockFree(v24, v22, v25);
        else
          v24->m_cur = v22;
        numDeletedPairs[0] = 0;
        if ( numDeletedPairs[1] >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)&operation[0].m_type.m_storage,
            16 * numDeletedPairs[1]);
      }
      if ( (signed int)v5 > 0 )
      {
        v26 = v5;
        do
        {
          v27 = (hkReferencedObject *)*v6;
          v28 = 0;
          v29 = 0i64;
          (*v6)->m_world = 0i64;
          v30 = v3->m_phantoms.m_size;
          if ( (signed int)v30 <= 0 )
          {
LABEL_33:
            v28 = -1;
            v29 = -1i64;
          }
          else
          {
            v31 = v3->m_phantoms.m_data;
            while ( *v31 != (hkpPhantom *)v27 )
            {
              ++v29;
              ++v28;
              ++v31;
              if ( v29 >= v30 )
                goto LABEL_33;
            }
          }
          v3->m_phantoms.m_size = v30 - 1;
          if ( (_DWORD)v30 - 1 != v28 )
            v3->m_phantoms.m_data[v29] = v3->m_phantoms.m_data[(signed int)v30 - 1];
          if ( !v27->m_memSizeAndFlags )
            ((void (__fastcall *)(hkReferencedObject *))v27->vfptr[7].__vecDelDtor)(v27);
          hkReferencedObject::removeReference(v27);
          ++v6;
          --v26;
        }
        while ( v26 );
      }
      v32 = v3->m_criticalOperationsLockCount-- == 1;
      if ( v32 && !v3->m_blockExecutingPendingOperations.m_bool )
      {
        if ( v3->m_pendingOperationsCount )
          hkpWorld::internal_executePendingOperations(v3);
        if ( v3->m_pendingOperationQueueCount == 1 && v3->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(v3);
      }
      v33 = v43;
      v34 = (char *)v45;
      if ( v45 == v42 )
        v33 = 0;
      v43 = v33;
      v35 = (8 * v46 + 127) & 0xFFFFFF80;
      v36 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v37 = (v35 + 15) & 0xFFFFFFF0;
      if ( v35 > v36->m_slabSize || &v34[v37] != v36->m_cur || v36->m_firstNonLifoEnd == v34 )
        hkLifoAllocator::slowBlockFree(v36, v34, v37);
      else
        v36->m_cur = v34;
      v43 = 0;
      if ( v44 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v42,
          8 * v44);
    }
  }
}

// File Line: 2009
// RVA: 0xD590D0
void __fastcall hkpWorld::addPhysicsSystem(hkpWorld *this, hkpPhysicsSystem *sys)
{
  int v2; // er10
  int v3; // edi
  hkpPhysicsSystem *v4; // rbx
  hkpWorld *v5; // rbp
  __int64 v6; // rcx
  int v7; // er8
  __int64 v8; // rdx
  hkpRigidBody **v9; // rax
  int v10; // er9
  int v11; // edx
  signed __int64 v12; // rcx
  hkpPhantom **v13; // rax
  int v14; // esi
  __int64 v15; // r14
  hkpAction *v16; // rdx
  __int64 v17; // rsi
  hkpConstraintInstance *v18; // rdx
  int v19; // esi
  __int64 v20; // r14
  hkpEntity *v21; // rdx
  int v22; // esi
  __int64 v23; // r14
  hkpPhantom *v24; // rdx

  v2 = sys->m_rigidBodies.m_size;
  v3 = 0;
  v4 = sys;
  v5 = this;
  if ( v2 > 0 )
  {
    v6 = sys->m_rigidBodies.m_size;
    v7 = 0;
    v8 = 0i64;
    if ( v6 <= 0 )
      goto LABEL_6;
    v9 = v4->m_rigidBodies.m_data;
    while ( *v9 )
    {
      ++v8;
      ++v7;
      ++v9;
      if ( v8 >= v6 )
        goto LABEL_6;
    }
    if ( v7 == -1 )
    {
LABEL_6:
      hkpWorld::addEntityBatch(
        v5,
        (hkpEntity *const *)v4->m_rigidBodies.m_data,
        v2,
        (hkpEntityActivation)(v4->m_active.m_bool != 0));
    }
    else
    {
      v19 = 0;
      if ( v2 > 0 )
      {
        v20 = 0i64;
        do
        {
          v21 = (hkpEntity *)&v4->m_rigidBodies.m_data[v20]->vfptr;
          if ( v21 )
            hkpWorld::addEntity(v5, v21, (hkpEntityActivation)(v4->m_active.m_bool != 0));
          ++v19;
          ++v20;
        }
        while ( v19 < v4->m_rigidBodies.m_size );
      }
    }
  }
  v10 = v4->m_phantoms.m_size;
  if ( v10 > 0 )
  {
    v11 = 0;
    v12 = 0i64;
    if ( v10 <= 0i64 )
      goto LABEL_12;
    v13 = v4->m_phantoms.m_data;
    while ( *v13 )
    {
      ++v12;
      ++v11;
      ++v13;
      if ( v12 >= v10 )
        goto LABEL_12;
    }
    if ( v11 == -1 )
    {
LABEL_12:
      hkpWorld::addPhantomBatch(v5, v4->m_phantoms.m_data, v10);
    }
    else
    {
      v22 = 0;
      if ( v10 > 0 )
      {
        v23 = 0i64;
        do
        {
          v24 = v4->m_phantoms.m_data[v23];
          if ( v24 )
            hkpWorld::addPhantom(v5, v24);
          ++v22;
          ++v23;
        }
        while ( v22 < v4->m_phantoms.m_size );
      }
    }
  }
  v14 = 0;
  if ( v4->m_actions.m_size > 0 )
  {
    v15 = 0i64;
    do
    {
      v16 = v4->m_actions.m_data[v15];
      if ( v16 )
        hkpWorld::addAction(v5, v16);
      ++v14;
      ++v15;
    }
    while ( v14 < v4->m_actions.m_size );
  }
  if ( v4->m_constraints.m_size > 0 )
  {
    v17 = 0i64;
    do
    {
      v18 = v4->m_constraints.m_data[v17];
      if ( v18 && (v18->m_entities[0] || v18->m_entities[1]) )
        hkpWorld::addConstraint(v5, v18);
      ++v3;
      ++v17;
    }
    while ( v3 < v4->m_constraints.m_size );
  }
}

// File Line: 2090
// RVA: 0xD592A0
void __fastcall hkpWorld::removePhysicsSystem(hkpWorld *this, hkpPhysicsSystem *sys)
{
  int v2; // edi
  hkpPhysicsSystem *v3; // rbx
  hkpWorld *v4; // rbp
  int v5; // esi
  __int64 v6; // r14
  hkpConstraintInstance *v7; // r8
  int v8; // esi
  __int64 v9; // r14
  hkpAction *v10; // rdx
  __int64 v11; // r8
  int v12; // edx
  __int64 v13; // rcx
  hkpRigidBody **v14; // rax
  __int64 v15; // r8
  int v16; // edx
  __int64 v17; // rcx
  hkpPhantom **v18; // rax
  int v19; // esi
  __int64 v20; // r14
  hkpEntity *v21; // r8
  __int64 v22; // rsi
  hkpPhantom *v23; // rdx
  hkBool result; // [rsp+48h] [rbp+10h]

  v2 = 0;
  v3 = sys;
  v4 = this;
  v5 = 0;
  if ( sys->m_constraints.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      v7 = v3->m_constraints.m_data[v6];
      if ( v7 && v7->m_owner )
        hkpWorld::removeConstraint(v4, &result, v7);
      ++v5;
      ++v6;
    }
    while ( v5 < v3->m_constraints.m_size );
  }
  v8 = 0;
  if ( v3->m_actions.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      v10 = v3->m_actions.m_data[v9];
      if ( v10 )
        hkpWorld::removeAction(v4, v10);
      ++v8;
      ++v9;
    }
    while ( v8 < v3->m_actions.m_size );
  }
  v11 = v3->m_rigidBodies.m_size;
  v12 = 0;
  v13 = 0i64;
  if ( v11 <= 0 )
    goto LABEL_16;
  v14 = v3->m_rigidBodies.m_data;
  while ( *v14 )
  {
    ++v13;
    ++v12;
    ++v14;
    if ( v13 >= v11 )
      goto LABEL_16;
  }
  if ( v12 == -1 )
  {
LABEL_16:
    hkpWorld::removeEntityBatch(v4, (hkpEntity *const *)v3->m_rigidBodies.m_data, v3->m_rigidBodies.m_size);
  }
  else
  {
    v19 = 0;
    if ( v3->m_rigidBodies.m_size > 0 )
    {
      v20 = 0i64;
      do
      {
        v21 = (hkpEntity *)&v3->m_rigidBodies.m_data[v20]->vfptr;
        if ( v21 )
          hkpWorld::removeEntity(v4, &result, v21);
        ++v19;
        ++v20;
      }
      while ( v19 < v3->m_rigidBodies.m_size );
    }
  }
  v15 = v3->m_phantoms.m_size;
  v16 = 0;
  v17 = 0i64;
  if ( v15 <= 0 )
    goto LABEL_21;
  v18 = v3->m_phantoms.m_data;
  while ( *v18 )
  {
    ++v17;
    ++v16;
    ++v18;
    if ( v17 >= v15 )
      goto LABEL_21;
  }
  if ( v16 == -1 )
  {
LABEL_21:
    hkpWorld::removePhantomBatch(v4, v3->m_phantoms.m_data, v3->m_phantoms.m_size);
  }
  else if ( v3->m_phantoms.m_size > 0 )
  {
    v22 = 0i64;
    do
    {
      v23 = v3->m_phantoms.m_data[v22];
      if ( v23 )
        hkpWorld::removePhantom(v4, v23);
      ++v2;
      ++v22;
    }
    while ( v2 < v3->m_phantoms.m_size );
  }
}

// File Line: 2158
// RVA: 0xD5A3D0
void __fastcall hkpWorld::setGravity(hkpWorld *this, hkVector4f *gravity)
{
  this->m_gravity = (hkVector4f)gravity->m_quad;
}

// File Line: 2171
// RVA: 0xD5A7A0
void __fastcall hkpWorld::addActionListener(hkpWorld *this, hkpActionListener *worldListener)
{
  hkArray<hkpActionListener *,hkContainerHeapAllocator> *v2; // rbx
  hkpActionListener *v3; // rdi

  v2 = &this->m_actionListeners;
  v3 = worldListener;
  if ( this->m_actionListeners.m_size == (this->m_actionListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
}

// File Line: 2179
// RVA: 0xD5A800
void __fastcall hkpWorld::removeActionListener(hkpWorld *this, hkpActionListener *worldListener)
{
  __int64 v2; // r10
  signed int v3; // er9
  __int64 v4; // r8
  hkpActionListener **v5; // rax

  v2 = this->m_actionListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v5 = this->m_actionListeners.m_data;
    while ( *v5 != worldListener )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        goto LABEL_5;
    }
  }
  this->m_actionListeners.m_data[v3] = 0i64;
}

// File Line: 2188
// RVA: 0xD5A860
void __fastcall hkpWorld::addConstraintListener(hkpWorld *this, hkpConstraintListener *worldListener)
{
  hkArray<hkpConstraintListener *,hkContainerHeapAllocator> *v2; // rbx
  hkpConstraintListener *v3; // rdi

  v2 = &this->m_constraintListeners;
  v3 = worldListener;
  if ( this->m_constraintListeners.m_size == (this->m_constraintListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
}

// File Line: 2196
// RVA: 0xD5A8C0
void __fastcall hkpWorld::removeConstraintListener(hkpWorld *this, hkpConstraintListener *worldListener)
{
  __int64 v2; // r10
  signed int v3; // er9
  __int64 v4; // r8
  hkpConstraintListener **v5; // rax

  v2 = this->m_constraintListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v5 = this->m_constraintListeners.m_data;
    while ( *v5 != worldListener )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        goto LABEL_5;
    }
  }
  this->m_constraintListeners.m_data[v3] = 0i64;
}

// File Line: 2204
// RVA: 0xD5A920
void __fastcall hkpWorld::addEntityListener(hkpWorld *this, hkpEntityListener *worldListener)
{
  hkArray<hkpEntityListener *,hkContainerHeapAllocator> *v2; // rbx
  hkpEntityListener *v3; // rdi

  v2 = &this->m_entityListeners;
  v3 = worldListener;
  if ( this->m_entityListeners.m_size == (this->m_entityListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
}

// File Line: 2211
// RVA: 0xD5A980
void __fastcall hkpWorld::removeEntityListener(hkpWorld *this, hkpEntityListener *worldListener)
{
  __int64 v2; // r10
  signed int v3; // er9
  __int64 v4; // r8
  hkpEntityListener **v5; // rax

  v2 = this->m_entityListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v5 = this->m_entityListeners.m_data;
    while ( *v5 != worldListener )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        goto LABEL_5;
    }
  }
  this->m_entityListeners.m_data[v3] = 0i64;
}

// File Line: 2219
// RVA: 0xD5A9E0
void __fastcall hkpWorld::addPhantomListener(hkpWorld *this, hkpPhantomListener *worldListener)
{
  hkArray<hkpPhantomListener *,hkContainerHeapAllocator> *v2; // rbx
  hkpPhantomListener *v3; // rdi

  v2 = &this->m_phantomListeners;
  v3 = worldListener;
  if ( this->m_phantomListeners.m_size == (this->m_phantomListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
}

// File Line: 2226
// RVA: 0xD5AA40
void __fastcall hkpWorld::removePhantomListener(hkpWorld *this, hkpPhantomListener *worldListener)
{
  __int64 v2; // r10
  signed int v3; // er9
  __int64 v4; // r8
  hkpPhantomListener **v5; // rax

  v2 = this->m_phantomListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v5 = this->m_phantomListeners.m_data;
    while ( *v5 != worldListener )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        goto LABEL_5;
    }
  }
  this->m_phantomListeners.m_data[v3] = 0i64;
}

// File Line: 2234
// RVA: 0xD5AAA0
void __fastcall hkpWorld::addIslandActivationListener(hkpWorld *this, hkpIslandActivationListener *worldListener)
{
  hkArray<hkpIslandActivationListener *,hkContainerHeapAllocator> *v2; // rbx
  hkpIslandActivationListener *v3; // rdi

  v2 = &this->m_islandActivationListeners;
  v3 = worldListener;
  if ( this->m_islandActivationListeners.m_size == (this->m_islandActivationListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
}

// File Line: 2241
// RVA: 0xD5AB00
void __fastcall hkpWorld::removeIslandActivationListener(hkpWorld *this, hkpIslandActivationListener *worldListener)
{
  __int64 v2; // r10
  signed int v3; // er9
  __int64 v4; // r8
  hkpIslandActivationListener **v5; // rax

  v2 = this->m_islandActivationListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v5 = this->m_islandActivationListeners.m_data;
    while ( *v5 != worldListener )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        goto LABEL_5;
    }
  }
  this->m_islandActivationListeners.m_data[v3] = 0i64;
}

// File Line: 2249
// RVA: 0xD5AB60
void __fastcall hkpWorld::addWorldPostCollideListener(hkpWorld *this, hkpWorldPostCollideListener *worldListener)
{
  hkArray<hkpWorldPostCollideListener *,hkContainerHeapAllocator> *v2; // rbx
  hkpWorldPostCollideListener *v3; // rdi

  v2 = &this->m_worldPostCollideListeners;
  v3 = worldListener;
  if ( this->m_worldPostCollideListeners.m_size == (this->m_worldPostCollideListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
}

// File Line: 2256
// RVA: 0xD5ABC0
void __fastcall hkpWorld::removeWorldPostCollideListener(hkpWorld *this, hkpWorldPostCollideListener *worldListener)
{
  __int64 v2; // r10
  signed int v3; // er9
  __int64 v4; // r8
  hkpWorldPostCollideListener **v5; // rax

  v2 = this->m_worldPostCollideListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v5 = this->m_worldPostCollideListeners.m_data;
    while ( *v5 != worldListener )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        goto LABEL_5;
    }
  }
  this->m_worldPostCollideListeners.m_data[v3] = 0i64;
}

// File Line: 2265
// RVA: 0xD5AC20
void __fastcall hkpWorld::addWorldPostSimulationListener(hkpWorld *this, hkpWorldPostSimulationListener *worldListener)
{
  hkArray<hkpWorldPostSimulationListener *,hkContainerHeapAllocator> *v2; // rbx
  hkpWorldPostSimulationListener *v3; // rdi

  v2 = &this->m_worldPostSimulationListeners;
  v3 = worldListener;
  if ( this->m_worldPostSimulationListeners.m_size == (this->m_worldPostSimulationListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
}

// File Line: 2272
// RVA: 0xD5AC80
void __fastcall hkpWorld::removeWorldPostSimulationListener(hkpWorld *this, hkpWorldPostSimulationListener *worldListener)
{
  __int64 v2; // r10
  signed int v3; // er9
  __int64 v4; // r8
  hkpWorldPostSimulationListener **v5; // rax

  v2 = this->m_worldPostSimulationListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v5 = this->m_worldPostSimulationListeners.m_data;
    while ( *v5 != worldListener )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        goto LABEL_5;
    }
  }
  this->m_worldPostSimulationListeners.m_data[v3] = 0i64;
}

// File Line: 2280
// RVA: 0xD5ACE0
void __fastcall hkpWorld::addWorldPostIntegrateListener(hkpWorld *this, hkpWorldPostIntegrateListener *worldListener)
{
  hkArray<hkpWorldPostIntegrateListener *,hkContainerHeapAllocator> *v2; // rbx
  hkpWorldPostIntegrateListener *v3; // rdi

  v2 = &this->m_worldPostIntegrateListeners;
  v3 = worldListener;
  if ( this->m_worldPostIntegrateListeners.m_size == (this->m_worldPostIntegrateListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
}

// File Line: 2287
// RVA: 0xD5AD40
void __fastcall hkpWorld::removeWorldPostIntegrateListener(hkpWorld *this, hkpWorldPostIntegrateListener *worldListener)
{
  __int64 v2; // r10
  signed int v3; // er9
  __int64 v4; // r8
  hkpWorldPostIntegrateListener **v5; // rax

  v2 = this->m_worldPostIntegrateListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v5 = this->m_worldPostIntegrateListeners.m_data;
    while ( *v5 != worldListener )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        goto LABEL_5;
    }
  }
  this->m_worldPostIntegrateListeners.m_data[v3] = 0i64;
}

// File Line: 2296
// RVA: 0xD5ADA0
void __fastcall hkpWorld::addIslandPostCollideListener(hkpWorld *this, hkpIslandPostCollideListener *islandListener)
{
  hkArray<hkpIslandPostCollideListener *,hkContainerHeapAllocator> *v2; // rbx
  hkpIslandPostCollideListener *v3; // rdi

  v2 = &this->m_islandPostCollideListeners;
  v3 = islandListener;
  if ( this->m_islandPostCollideListeners.m_size == (this->m_islandPostCollideListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
}

// File Line: 2303
// RVA: 0xD5AE00
void __fastcall hkpWorld::removeIslandPostCollideListener(hkpWorld *this, hkpIslandPostCollideListener *islandListener)
{
  __int64 v2; // r10
  signed int v3; // er9
  __int64 v4; // r8
  hkpIslandPostCollideListener **v5; // rax

  v2 = this->m_islandPostCollideListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v5 = this->m_islandPostCollideListeners.m_data;
    while ( *v5 != islandListener )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        goto LABEL_5;
    }
  }
  this->m_islandPostCollideListeners.m_data[v3] = 0i64;
}

// File Line: 2312
// RVA: 0xD5AE60
void __fastcall hkpWorld::addIslandPostIntegrateListener(hkpWorld *this, hkpIslandPostIntegrateListener *islandListener)
{
  hkArray<hkpIslandPostIntegrateListener *,hkContainerHeapAllocator> *v2; // rbx
  hkpIslandPostIntegrateListener *v3; // rdi

  v2 = &this->m_islandPostIntegrateListeners;
  v3 = islandListener;
  if ( this->m_islandPostIntegrateListeners.m_size == (this->m_islandPostIntegrateListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
}

// File Line: 2319
// RVA: 0xD5AEC0
void __fastcall hkpWorld::removeIslandPostIntegrateListener(hkpWorld *this, hkpIslandPostIntegrateListener *islandListener)
{
  __int64 v2; // r10
  signed int v3; // er9
  __int64 v4; // r8
  hkpIslandPostIntegrateListener **v5; // rax

  v2 = this->m_islandPostIntegrateListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v5 = this->m_islandPostIntegrateListeners.m_data;
    while ( *v5 != islandListener )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        goto LABEL_5;
    }
  }
  this->m_islandPostIntegrateListeners.m_data[v3] = 0i64;
}

// File Line: 2328
// RVA: 0xD5AF20
void __fastcall hkpWorld::addContactListener(hkpWorld *this, hkpContactListener *collisionListener)
{
  hkArray<hkpContactListener *,hkContainerHeapAllocator> *v2; // rbx
  hkpContactListener *v3; // rdi

  v2 = &this->m_contactListeners;
  v3 = collisionListener;
  if ( this->m_contactListeners.m_size == (this->m_contactListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
}

// File Line: 2336
// RVA: 0xD5AF80
void __fastcall hkpWorld::removeContactListener(hkpWorld *this, hkpContactListener *collisionListener)
{
  __int64 v2; // r10
  signed int v3; // er9
  __int64 v4; // r8
  hkpContactListener **v5; // rax

  v2 = this->m_contactListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v5 = this->m_contactListeners.m_data;
    while ( *v5 != collisionListener )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        goto LABEL_5;
    }
  }
  this->m_contactListeners.m_data[v3] = 0i64;
}

// File Line: 2345
// RVA: 0xD5AFE0
void __fastcall hkpWorld::addWorldDeletionListener(hkpWorld *this, hkpWorldDeletionListener *worldListener)
{
  hkArray<hkpWorldDeletionListener *,hkContainerHeapAllocator> *v2; // rbx
  hkpWorldDeletionListener *v3; // rdi

  v2 = &this->m_worldDeletionListeners;
  v3 = worldListener;
  if ( this->m_worldDeletionListeners.m_size == (this->m_worldDeletionListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
}

// File Line: 2352
// RVA: 0xD5B040
void __fastcall hkpWorld::removeWorldDeletionListener(hkpWorld *this, hkpWorldDeletionListener *worldListener)
{
  __int64 v2; // r10
  signed int v3; // er9
  __int64 v4; // r8
  hkpWorldDeletionListener **v5; // rax

  v2 = this->m_worldDeletionListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v5 = this->m_worldDeletionListeners.m_data;
    while ( *v5 != worldListener )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        goto LABEL_5;
    }
  }
  this->m_worldDeletionListeners.m_data[v3] = 0i64;
}

// File Line: 2360
// RVA: 0xD5B0A0
void __fastcall hkpWorld::addContactImpulseLimitBreachedListener(hkpWorld *this, hkpContactImpulseLimitBreachedListener *listener)
{
  hkArray<hkpContactImpulseLimitBreachedListener *,hkContainerHeapAllocator> *v2; // rbx
  hkpContactImpulseLimitBreachedListener *v3; // rdi

  v2 = &this->m_contactImpulseLimitBreachedListeners;
  v3 = listener;
  if ( this->m_contactImpulseLimitBreachedListeners.m_size == (this->m_contactImpulseLimitBreachedListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
}

// File Line: 2367
// RVA: 0xD5B100
void __fastcall hkpWorld::removeContactImpulseLimitBreachedListener(hkpWorld *this, hkpContactImpulseLimitBreachedListener *listener)
{
  __int64 v2; // r10
  signed int v3; // er9
  __int64 v4; // r8
  hkpContactImpulseLimitBreachedListener **v5; // rax

  v2 = this->m_contactImpulseLimitBreachedListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v5 = this->m_contactImpulseLimitBreachedListeners.m_data;
    while ( *v5 != listener )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        goto LABEL_5;
    }
  }
  this->m_contactImpulseLimitBreachedListeners.m_data[v3] = 0i64;
}

// File Line: 2375
// RVA: 0xD5B160
void __fastcall hkpWorld::addWorldExtension(hkpWorld *this, hkpWorldExtension *extension)
{
  hkArray<hkpWorldExtension *,hkContainerHeapAllocator> *v2; // rbx
  hkpWorldExtension *v3; // rdi
  hkpWorld *v4; // rsi
  hkBaseObjectVtbl *v5; // rax

  v2 = &this->m_worldExtensions;
  v3 = extension;
  v4 = this;
  if ( this->m_worldExtensions.m_size == (this->m_worldExtensions.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
  hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
  v5 = v3->vfptr;
  v3->m_world = v4;
  ((void (__fastcall *)(hkpWorldExtension *, hkpWorld *))v5[1].__first_virtual_table_function__)(v3, v4);
}

// File Line: 2385
// RVA: 0xD5B1E0
void __fastcall hkpWorld::removeWorldExtension(hkpWorld *this, hkpWorldExtension *extension)
{
  hkpWorldExtension *v2; // rdi
  __int64 v3; // rdx
  signed int v4; // ebx
  __int64 v5; // r8
  hkpWorld *v6; // rsi
  hkpWorldExtension **v7; // rax
  __int64 v8; // rax

  v2 = extension;
  v3 = this->m_worldExtensions.m_size;
  v4 = 0;
  v5 = 0i64;
  v6 = this;
  if ( v3 <= 0 )
  {
LABEL_5:
    v4 = -1;
  }
  else
  {
    v7 = this->m_worldExtensions.m_data;
    while ( *v7 != v2 )
    {
      ++v5;
      ++v4;
      ++v7;
      if ( v5 >= v3 )
        goto LABEL_5;
    }
  }
  ((void (__fastcall *)(hkpWorldExtension *, hkpWorld *, __int64))v2->vfptr[2].__vecDelDtor)(v2, this, v5);
  v2->m_world = 0i64;
  hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v8 = --v6->m_worldExtensions.m_size;
  if ( (_DWORD)v8 != v4 )
    v6->m_worldExtensions.m_data[v4] = v6->m_worldExtensions.m_data[v8];
}

// File Line: 2395
// RVA: 0xD5B290
hkpWorldExtension *__fastcall hkpWorld::findWorldExtension(hkpWorld *this, int id)
{
  __int64 v2; // r9
  __int64 v3; // r8
  hkpWorldExtension **v4; // rax

  v2 = this->m_worldExtensions.m_size;
  v3 = 0i64;
  if ( v2 <= 0 )
    return 0i64;
  v4 = this->m_worldExtensions.m_data;
  while ( (*v4)->m_id != id )
  {
    ++v3;
    ++v4;
    if ( v3 >= v2 )
      return 0i64;
  }
  return *v4;
}

// File Line: 2412
// RVA: 0xD5C900
float __fastcall hkpWorld::getCurrentTime(hkpWorld *this)
{
  return this->m_simulation->m_currentTime;
}

// File Line: 2418
// RVA: 0xD5C910
float __fastcall hkpWorld::getCurrentPsiTime(hkpWorld *this)
{
  return this->m_simulation->m_currentPsiTime;
}

// File Line: 2425
// RVA: 0xD5C620
__int64 __fastcall hkpWorld::stepDeltaTime(hkpWorld *this, float physicsDeltaTime)
{
  hkpWorld *v2; // rbx
  unsigned int v3; // edi
  int v4; // eax
  hkpBroadPhase *v5; // rcx

  v2 = this;
  hkpWorld::lock(this);
  hkpWorldMemoryUtil::watchHeapMemory(v2);
  v3 = ((__int64 (*)(void))v2->m_simulation->vfptr[1].__first_virtual_table_function__)();
  v4 = ((__int64 (*)(void))v2->m_broadPhase->vfptr[1].__first_virtual_table_function__)();
  v5 = v2->m_broadPhase;
  if ( v4 == 2 )
  {
    hkpBroadPhase::s_updateTreeBroadPhaseFunction(v5, physicsDeltaTime);
  }
  else if ( ((unsigned int (*)(void))v5->vfptr[1].__first_virtual_table_function__)() == 3 )
  {
    hkpBroadPhase::s_updateTreeBroadPhaseFunction32(v2->m_broadPhase, physicsDeltaTime);
  }
  hkpWorld::unlock(v2);
  return v3;
}

// File Line: 2458
// RVA: 0xD5C6B0
__int64 __fastcall hkpWorld::integrate(hkpWorld *this, float physicsDeltaTime)
{
  hkpWorld *v2; // rdi
  unsigned int v3; // ebx

  v2 = this;
  hkpWorld::lock(this);
  v3 = ((__int64 (*)(void))v2->m_simulation->vfptr[2].__vecDelDtor)();
  hkpWorld::unlock(v2);
  return v3;
}

// File Line: 2466
// RVA: 0xD5C700
__int64 __fastcall hkpWorld::collide(hkpWorld *this)
{
  hkpWorld *v1; // rdi
  unsigned int v2; // ebx

  v1 = this;
  hkpWorld::lock(this);
  v2 = ((__int64 (*)(void))v1->m_simulation->vfptr[2].__first_virtual_table_function__)();
  hkpWorld::unlock(v1);
  return v2;
}

// File Line: 2474
// RVA: 0xD5C740
__int64 __fastcall hkpWorld::advanceTime(hkpWorld *this)
{
  hkpWorld *v1; // rdi
  unsigned int v2; // ebx

  v1 = this;
  hkpWorld::lock(this);
  v2 = ((__int64 (*)(void))v1->m_simulation->vfptr[3].__vecDelDtor)();
  hkpWorld::unlock(v1);
  return v2;
}

// File Line: 2483
// RVA: 0xD5C780
void __fastcall hkpWorld::setFrameTimeMarker(hkpWorld *this, float frameDeltaTime)
{
  hkpSimulation::setFrameTimeMarker(this->m_simulation, frameDeltaTime);
}

// File Line: 2488
// RVA: 0xD5C790
bool __fastcall hkpWorld::isSimulationAtMarker(hkpWorld *this)
{
  return hkpSimulation::isSimulationAtMarker(this->m_simulation);
}

// File Line: 2493
// RVA: 0xD5C7A0
bool __fastcall hkpWorld::isSimulationAtPsi(hkpWorld *this)
{
  return hkpSimulation::isSimulationAtPsi(this->m_simulation);
}

// File Line: 2501
// RVA: 0xD5C7B0
hkpStepResult __fastcall hkpWorld::stepMultithreaded(hkpWorld *this, hkJobQueue *jobQueue, hkJobThreadPool *threadPool, float physicsDeltaTime)
{
  hkJobThreadPool *v4; // rbx
  hkJobQueue *v5; // rdi
  hkpWorld *v6; // rsi
  hkpStepResult result; // eax

  v4 = threadPool;
  v5 = jobQueue;
  v6 = this;
  result = hkpWorld::initMtStep(this, jobQueue, physicsDeltaTime);
  if ( result == HK_STEP_RESULT_SUCCESS )
  {
    ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, signed __int64))v4->vfptr[5].__first_virtual_table_function__)(
      v4,
      v5,
      20i64);
    hkJobQueue::processAllJobs(v5, 1);
    ((void (__fastcall *)(hkJobThreadPool *))v4->vfptr[2].__vecDelDtor)(v4);
    result = hkpWorld::finishMtStep(v6, v5, v4);
  }
  return result;
}

// File Line: 2525
// RVA: 0xD5C820
__int64 __fastcall hkpWorld::initMtStep(hkpWorld *this, hkJobQueue *jobQueue, float physicsDeltaTime)
{
  hkJobQueue *v3; // rdi
  hkpWorld *v4; // rbx

  v3 = jobQueue;
  v4 = this;
  if ( this->m_memoryWatchDog.m_pntr )
  {
    hkpWorld::lock(this);
    hkpWorldMemoryUtil::watchHeapMemory(v4);
    hkpWorld::unlock(v4);
  }
  return ((__int64 (__fastcall *)(hkpSimulation *, hkJobQueue *))v4->m_simulation->vfptr[3].__first_virtual_table_function__)(
           v4->m_simulation,
           v3);
}

// File Line: 2545
// RVA: 0xD5C880
__int64 __fastcall hkpWorld::finishMtStep(hkpWorld *this, hkJobQueue *jobQueue, hkJobThreadPool *threadPool)
{
  hkpWorld *v3; // rbx
  __int64 result; // rax
  int v5; // eax
  hkpBroadPhase *v6; // rcx

  v3 = this;
  result = ((__int64 (__fastcall *)(hkpSimulation *, hkJobQueue *, hkJobThreadPool *))this->m_simulation->vfptr[4].__vecDelDtor)(
             this->m_simulation,
             jobQueue,
             threadPool);
  if ( !(_DWORD)result )
  {
    v5 = ((__int64 (*)(void))v3->m_broadPhase->vfptr[1].__first_virtual_table_function__)();
    v6 = v3->m_broadPhase;
    if ( v5 == 2 )
    {
      hkpBroadPhase::s_updateTreeBroadPhaseFunction(v6, v3->m_simulation->m_physicsDeltaTime);
      result = 0i64;
    }
    else
    {
      if ( ((unsigned int (*)(void))v6->vfptr[1].__first_virtual_table_function__)() == 3 )
        hkpBroadPhase::s_updateTreeBroadPhaseFunction32(v3->m_broadPhase, v3->m_simulation->m_physicsDeltaTime);
      result = 0i64;
    }
  }
  return result;
}

// File Line: 2574
// RVA: 0xD5C920
void __fastcall hkpWorld::getMultithreadConfig(hkpWorld *this, hkpMultithreadConfig *config)
{
  ((void (__fastcall *)(hkpSimulation *, hkpMultithreadConfig *))this->m_simulation->vfptr[4].__first_virtual_table_function__)(
    this->m_simulation,
    config);
}

// File Line: 2580
// RVA: 0xD5C940
void __fastcall hkpWorld::setMultithreadConfig(hkpWorld *this, hkpMultithreadConfig *config, hkJobQueue *queue)
{
  ((void (__fastcall *)(hkpSimulation *, hkpMultithreadConfig *, hkJobQueue *))this->m_simulation->vfptr[5].__vecDelDtor)(
    this->m_simulation,
    config,
    queue);
}

// File Line: 2616
// RVA: 0xD5A5D0
void __fastcall hkpWorld::checkDeterminismOfIslandBroadPhase(hkpWorld *this, hkpSimulationIsland *island)
{
  ;
}

// File Line: 2641
// RVA: 0xD5A5C0
void __fastcall hkpWorld::checkDeterminism(hkpWorld *this)
{
  ;
}

// File Line: 2754
// RVA: 0xD56C40
void __fastcall hkpWorld::getCinfo(hkpWorld *this, hkpWorldCinfo *info)
{
  hkpWorldCinfo *v2; // rbx
  hkpWorld *v3; // rdi
  hkpCollisionFilter *v4; // rsi
  hkReferencedObject *v5; // rcx
  hkpConvexListFilter *v6; // rsi
  hkReferencedObject *v7; // rcx
  hkpBroadPhaseBorder *v8; // rax
  hkpWorldCinfo::BroadPhaseBorderBehaviour v9; // eax
  hkpBroadPhaseBorder *v10; // rax
  hkReferencedObject *v11; // rcx
  hkReferencedObject *v12; // rcx
  char v13; // [rsp+30h] [rbp+8h]

  v2 = info;
  v3 = this;
  info->m_gravity = this->m_gravity;
  info->m_broadPhaseQuerySize = this->m_broadPhaseQuerySize;
  info->m_broadPhaseWorldAabb.m_min = this->m_broadPhaseExtents[0];
  info->m_broadPhaseWorldAabb.m_max = this->m_broadPhaseExtents[1];
  info->m_collisionTolerance = this->m_collisionInput->m_tolerance.m_storage;
  v4 = this->m_collisionFilter;
  if ( v4 )
    hkReferencedObject::addReference((hkReferencedObject *)&this->m_collisionFilter->vfptr);
  v5 = (hkReferencedObject *)&v2->m_collisionFilter.m_pntr->vfptr;
  if ( v5 )
    hkReferencedObject::removeReference(v5);
  v2->m_collisionFilter.m_pntr = v4;
  v6 = v3->m_convexListFilter;
  if ( v6 )
    hkReferencedObject::addReference((hkReferencedObject *)&v3->m_convexListFilter->vfptr);
  v7 = (hkReferencedObject *)&v2->m_convexListFilter.m_pntr->vfptr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  v2->m_convexListFilter.m_pntr = v6;
  v2->m_broadPhaseType.m_storage = v3->m_broadPhaseType.m_storage;
  v8 = v3->m_broadPhaseBorder;
  if ( v8 )
    v9 = v8->m_type;
  else
    LOBYTE(v9) = 3;
  v2->m_broadPhaseBorderBehaviour.m_storage = v9;
  v10 = v3->m_broadPhaseBorder;
  if ( v10 )
    v13 = v10->m_postponeAndSortCallbacks.m_bool;
  else
    v13 = 0;
  v2->m_mtPostponeAndSortBroadPhaseBorderCallbacks.m_bool = v13;
  v2->m_expectedMaxLinearVelocity = v3->m_collisionDispatcher->m_expectedMaxLinearVelocity;
  v2->m_expectedMinPsiDeltaTime = v3->m_collisionDispatcher->m_expectedMinPsiDeltaTime;
  v2->m_snapCollisionToConvexEdgeThreshold = v3->m_snapCollisionToConvexEdgeThreshold;
  v2->m_snapCollisionToConvexEdgeThreshold = v3->m_snapCollisionToConcaveEdgeThreshold;
  v2->m_enableToiWeldRejection.m_bool = v3->m_enableToiWeldRejection.m_bool;
  v11 = (hkReferencedObject *)&v3->m_memoryWatchDog.m_pntr->vfptr;
  if ( v11 )
    hkReferencedObject::addReference(v11);
  v12 = (hkReferencedObject *)&v2->m_memoryWatchDog.m_pntr->vfptr;
  if ( v12 )
    hkReferencedObject::removeReference(v12);
  v2->m_memoryWatchDog.m_pntr = v3->m_memoryWatchDog.m_pntr;
  v2->m_broadPhaseNumMarkers = v3->m_broadPhaseNumMarkers;
  v2->m_sizeOfToiEventQueue = v3->m_sizeOfToiEventQueue;
  v2->m_contactPointGeneration.m_storage = v3->m_contactPointGeneration.m_storage;
  v2->m_allowToSkipConfirmedCallbacks.m_bool = v3->m_collisionInput->m_allowToSkipConfirmedCallbacks.m_bool;
  v2->m_contactRestingVelocity = v3->m_dynamicsStepInfo.m_solverInfo.m_contactRestingVelocity;
  v2->m_solverTau = v3->m_dynamicsStepInfo.m_solverInfo.m_tau;
  v2->m_solverDamp = v3->m_dynamicsStepInfo.m_solverInfo.m_damping;
  v2->m_solverIterations = v3->m_dynamicsStepInfo.m_solverInfo.m_numSteps;
  v2->m_solverMicrosteps = v3->m_dynamicsStepInfo.m_solverInfo.m_numMicroSteps;
  v2->m_maxConstraintViolation = fsqrt(v3->m_dynamicsStepInfo.m_solverInfo.m_maxConstraintViolationSqrd);
  v2->m_forceCoherentConstraintOrderingInSolver.m_bool = v3->m_dynamicsStepInfo.m_solverInfo.m_forceCoherentConstraintOrderingInSolver.m_bool;
  v2->m_deactivationNumInactiveFramesSelectFlag0 = v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0];
  v2->m_deactivationNumInactiveFramesSelectFlag1 = v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1];
  v2->m_deactivationIntegrateCounter = v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter;
  v2->m_iterativeLinearCastEarlyOutDistance = v3->m_collisionInput->m_config->m_iterativeLinearCastEarlyOutDistance;
  v2->m_iterativeLinearCastMaxIterations = v3->m_collisionInput->m_config->m_iterativeLinearCastMaxIterations;
  v2->m_enableDeprecatedWelding.m_bool = v3->m_collisionInput->m_enableDeprecatedWelding.m_bool;
  v2->m_shouldActivateOnRigidBodyTransformChange.m_bool = v3->m_shouldActivateOnRigidBodyTransformChange.m_bool;
  v2->m_toiCollisionResponseRotateNormal = v3->m_toiCollisionResponseRotateNormal;
  v2->m_useCompoundSpuElf.m_bool = v3->m_useCompoundSpuElf.m_bool;
  v2->m_maxSectorsPerMidphaseCollideTask = v3->m_maxSectorsPerMidphaseCollideTask;
  v2->m_maxSectorsPerNarrowphaseCollideTask = v3->m_maxSectorsPerNarrowphaseCollideTask;
  v2->m_processToisMultithreaded.m_bool = v3->m_processToisMultithreaded.m_bool;
  v2->m_maxEntriesPerToiMidphaseCollideTask = v3->m_maxEntriesPerToiMidphaseCollideTask;
  v2->m_maxEntriesPerToiNarrowphaseCollideTask = v3->m_maxEntriesPerToiNarrowphaseCollideTask;
  v2->m_maxNumToiCollisionPairsSinglethreaded = v3->m_maxNumToiCollisionPairsSinglethreaded;
  v2->m_deactivationReferenceDistance = v3->m_deactivationReferenceDistance;
  v2->m_numToisTillAllowedPenetrationSimplifiedToi = v3->m_numToisTillAllowedPenetrationSimplifiedToi;
  v2->m_numToisTillAllowedPenetrationToi = v3->m_numToisTillAllowedPenetrationToi;
  v2->m_numToisTillAllowedPenetrationToiHigher = v3->m_numToisTillAllowedPenetrationToiHigher;
  v2->m_numToisTillAllowedPenetrationToiForced = v3->m_numToisTillAllowedPenetrationToiForced;
  v2->m_enableDeactivation.m_bool = v3->m_wantDeactivation.m_bool;
  v2->m_simulationType.m_storage = v3->m_simulationType.m_storage;
  v2->m_frameMarkerPsiSnap = v3->m_simulation->m_frameMarkerPsiSnap;
  v2->m_enableSimulationIslands.m_bool = v3->m_wantSimulationIslands.m_bool;
  v2->m_processActionsInSingleThread.m_bool = v3->m_processActionsInSingleThread.m_bool;
  v2->m_allowIntegrationOfIslandsWithoutConstraintsInASeparateJob.m_bool = v3->m_allowIntegrationOfIslandsWithoutConstraintsInASeparateJob.m_bool;
  v2->m_minDesiredIslandSize = v3->m_minDesiredIslandSize;
  v2->m_fireCollisionCallbacks.m_bool = hkpWorld::findWorldExtension(v3, 1001) != 0i64;
}

// File Line: 2839
// RVA: 0xD5A5E0
hkWorldMemoryAvailableWatchDog *__fastcall hkpWorld::getMemoryWatchDog(hkpWorld *this)
{
  return this->m_memoryWatchDog.m_pntr;
}

// File Line: 2845
// RVA: 0xD5A5F0
void __fastcall hkpWorld::setMemoryWatchDog(hkpWorld *this, hkWorldMemoryAvailableWatchDog *watchDog)
{
  hkWorldMemoryAvailableWatchDog *v2; // rbx
  hkpWorld *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = watchDog;
  v3 = this;
  if ( watchDog )
    hkReferencedObject::addReference((hkReferencedObject *)&watchDog->vfptr);
  v4 = (hkReferencedObject *)&v3->m_memoryWatchDog.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_memoryWatchDog.m_pntr = v2;
}

// File Line: 2852
// RVA: 0xD55700
void __fastcall hkpWorld::hkpWorld(hkpWorld *this, hkpWorldCinfo *infoBase, unsigned int sdkversion)
{
  hkpWorld *v3; // rsi
  unsigned int v4; // edi
  _QWORD **v5; // rax
  hkpViolatedConstraintArray *v6; // rax
  _QWORD **v7; // rax
  hkpWorldOperationQueue *v8; // rax
  hkpWorldOperationQueue *v9; // rax
  __m128 v10; // xmm15
  __m128 v11; // xmm14
  int v12; // er8
  char v13; // al
  hkReferencedObject *v14; // rbx
  int v15; // eax
  hkOstream *v16; // rax
  hkOstream *v17; // rax
  hkOstream *v18; // rax
  hkOstream *v19; // rax
  float v20; // xmm6_4
  hkVector4f v21; // xmm7
  float v22; // xmm1_4
  float v23; // xmm0_4
  hkpConvexListFilter *v24; // kr00_8
  char v25; // di
  float v26; // xmm5_4
  __m128 v27; // xmm4
  int v28; // xmm0_4
  float v29; // xmm13_4
  char v30; // al
  float v31; // xmm5_4
  __int128 v32; // xmm1
  int v33; // eax
  float v34; // eax
  __m128 v35; // xmm0
  __m128i v36; // xmm0
  int v37; // eax
  __m128i v38; // xmm0
  __m128 v39; // xmm7
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  float v42; // xmm10_4
  float v43; // xmm0_4
  float v44; // xmm2_4
  float v45; // xmm7_4
  float v46; // xmm6_4
  float v47; // xmm5_4
  float v48; // xmm13_4
  float v49; // xmm1_4
  float v50; // xmm2_4
  hkReferencedObject *v51; // rbx
  float v52; // xmm2_4
  float v53; // xmm2_4
  float v54; // xmm1_4
  hkReferencedObject *v55; // rcx
  char v56; // al
  char v57; // cl
  _QWORD **v58; // rax
  hkpTypedBroadPhaseDispatcher *v59; // rax
  hkpTypedBroadPhaseDispatcher *v60; // rax
  _QWORD **v61; // rax
  __int64 v62; // rax
  _QWORD **v63; // rax
  hkpEntityEntityBroadPhaseListener *v64; // rax
  hkpEntityEntityBroadPhaseListener *v65; // rax
  _QWORD **v66; // rax
  __int64 v67; // rax
  hkpPhantomBroadPhaseListener *v68; // rax
  signed __int64 v69; // rcx
  hkpPhantomBroadPhaseListener *v70; // rcx
  signed __int64 v71; // rcx
  hkpPhantomBroadPhaseListener *v72; // rcx
  signed __int64 v73; // rcx
  hkpEntityEntityBroadPhaseListener *v74; // rcx
  signed __int64 v75; // rcx
  hkpBroadPhaseBorderListener *v76; // rcx
  signed __int64 v77; // rcx
  hkpBroadPhaseBorderListener *v78; // rcx
  signed __int64 v79; // rcx
  hkpBroadPhaseBorderListener *v80; // rcx
  signed __int64 v81; // rcx
  hkpBroadPhaseBorderListener *v82; // rcx
  signed __int64 v83; // rcx
  hkpBroadPhaseBorderListener *v84; // rax
  signed __int64 v85; // rcx
  _QWORD **v86; // rax
  hkpSimpleConstraintContactMgr::Factory *v87; // rax
  hkpContactMgrFactory *v88; // rax
  hkpContactMgrFactory *v89; // rbx
  _QWORD **v90; // rax
  hkpCollisionDispatcher *v91; // rax
  hkpCollisionDispatcher *v92; // rax
  hkReferencedObject *v93; // r13
  _QWORD **v94; // rax
  hkpCollisionFilter *v95; // rax
  hkpCollisionFilter *v96; // rbx
  hkReferencedObject *v97; // rcx
  hkReferencedObject *v98; // r12
  _QWORD **v99; // rax
  __int64 v100; // rax
  hkReferencedObject *v101; // rcx
  _QWORD **v102; // rax
  __int64 v103; // rax
  __m128i *v104; // r14
  int v105; // xmm0_4
  char v106; // bl
  char v107; // al
  _QWORD **v108; // rax
  _DWORD *v109; // rax
  int v110; // xmm0_4
  __m128 v111; // xmm14
  __m128 v112; // xmm1
  __int64 v113; // rax
  __m128 *v114; // r9
  _OWORD *v115; // rdx
  __m128 v116; // xmm2
  __m128 *v117; // r8
  __m128 v118; // xmm2
  bool v119; // zf
  char v120; // r14
  _QWORD **v121; // rax
  hkCriticalSection *v122; // rax
  _QWORD **v123; // rax
  hkCriticalSection *v124; // rax
  hkpSimulation *v125; // rax
  _QWORD **v126; // rax
  hkCriticalSection *v127; // rax
  int v128; // xmm0_4
  __m128 v129; // xmm1
  __m128 v130; // xmm2
  __m128 v131; // xmm1
  float v132; // xmm6_4
  unsigned int v133; // xmm5_4
  float v134; // xmm4_4
  float v135; // xmm3_4
  hkpProcessCollisionInput *v136; // rax
  hkpCollisionDispatcher *v137; // rcx
  int v138; // xmm2_4
  float v139; // xmm1_4
  float v140; // xmm0_4
  _QWORD **v141; // rax
  hkpSimulationIsland *v142; // rax
  hkpSimulationIsland *v143; // rax
  _QWORD **v144; // rax
  hkpSimulationIsland *v145; // rax
  hkpSimulationIsland *v146; // rax
  hkpSimulationIsland *v147; // rbx
  _QWORD **v148; // rax
  hkpRigidBody *v149; // rax
  hkpRigidBody *v150; // rax
  char v151; // bl
  _DWORD *v152; // rcx
  _QWORD **v153; // rax
  hkpBroadPhaseBorder *v154; // rax
  hkpBroadPhaseBorder *v155; // rax
  _QWORD **v156; // rax
  hkpDefaultWorldMaintenanceMgr *v157; // rax
  hkpWorldMaintenanceMgr *v158; // rax
  hkpWorldMaintenanceMgr *v159; // rcx
  hkpWorld *v160; // rdx
  _QWORD **v161; // rax
  __int64 v162; // rax
  hkReferencedObject *v163; // rcx
  hkErrStream v164; // [rsp+20h] [rbp-B8h]
  float v165; // [rsp+38h] [rbp-A0h]
  int v166; // [rsp+3Ch] [rbp-9Ch]
  int v167; // [rsp+40h] [rbp-98h]
  int v168; // [rsp+44h] [rbp-94h]
  bool v169; // [rsp+48h] [rbp-90h]
  bool v170; // [rsp+49h] [rbp-8Fh]
  bool v171; // [rsp+4Ah] [rbp-8Eh]
  char v172; // [rsp+4Bh] [rbp-8Dh]
  hkpWorldCinfo v173; // [rsp+50h] [rbp-88h]
  int v174; // [rsp+1B8h] [rbp+E0h]
  char v175; // [rsp+1DCh] [rbp+104h]
  char buf; // [rsp+208h] [rbp+130h]
  float v177; // [rsp+4E8h] [rbp+410h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v3 = this;
  v4 = sdkversion;
  this->vfptr = (hkBaseObjectVtbl *)&hkpWorld::`vftable;
  this->m_activeSimulationIslands.m_data = 0i64;
  this->m_activeSimulationIslands.m_size = 0;
  this->m_activeSimulationIslands.m_capacityAndFlags = 2147483648;
  this->m_inactiveSimulationIslands.m_data = 0i64;
  this->m_inactiveSimulationIslands.m_size = 0;
  this->m_inactiveSimulationIslands.m_capacityAndFlags = 2147483648;
  this->m_dirtySimulationIslands.m_data = 0i64;
  this->m_dirtySimulationIslands.m_size = 0;
  this->m_dirtySimulationIslands.m_capacityAndFlags = 2147483648;
  this->m_memoryWatchDog.m_pntr = 0i64;
  this->m_multiThreadCheck.m_threadId = -15;
  this->m_multiThreadCheck.m_markCount = -32768;
  this->m_phantoms.m_data = 0i64;
  this->m_phantoms.m_size = 0;
  this->m_phantoms.m_capacityAndFlags = 2147483648;
  this->m_actionListeners.m_data = 0i64;
  this->m_actionListeners.m_size = 0;
  this->m_actionListeners.m_capacityAndFlags = 2147483648;
  this->m_entityListeners.m_data = 0i64;
  this->m_entityListeners.m_size = 0;
  this->m_entityListeners.m_capacityAndFlags = 2147483648;
  this->m_phantomListeners.m_data = 0i64;
  this->m_phantomListeners.m_size = 0;
  this->m_phantomListeners.m_capacityAndFlags = 2147483648;
  this->m_constraintListeners.m_data = 0i64;
  this->m_constraintListeners.m_size = 0;
  this->m_constraintListeners.m_capacityAndFlags = 2147483648;
  this->m_worldDeletionListeners.m_data = 0i64;
  this->m_worldDeletionListeners.m_size = 0;
  this->m_worldDeletionListeners.m_capacityAndFlags = 2147483648;
  this->m_islandActivationListeners.m_data = 0i64;
  this->m_islandActivationListeners.m_size = 0;
  this->m_islandActivationListeners.m_capacityAndFlags = 2147483648;
  this->m_worldPostSimulationListeners.m_data = 0i64;
  this->m_worldPostSimulationListeners.m_size = 0;
  this->m_worldPostSimulationListeners.m_capacityAndFlags = 2147483648;
  this->m_worldPostIntegrateListeners.m_data = 0i64;
  this->m_worldPostIntegrateListeners.m_size = 0;
  this->m_worldPostIntegrateListeners.m_capacityAndFlags = 2147483648;
  this->m_worldPostCollideListeners.m_data = 0i64;
  this->m_worldPostCollideListeners.m_size = 0;
  this->m_worldPostCollideListeners.m_capacityAndFlags = 2147483648;
  this->m_islandPostIntegrateListeners.m_data = 0i64;
  this->m_islandPostIntegrateListeners.m_size = 0;
  this->m_islandPostIntegrateListeners.m_capacityAndFlags = 2147483648;
  this->m_islandPostCollideListeners.m_data = 0i64;
  this->m_islandPostCollideListeners.m_size = 0;
  this->m_islandPostCollideListeners.m_capacityAndFlags = 2147483648;
  this->m_contactListeners.m_data = 0i64;
  this->m_contactListeners.m_size = 0;
  this->m_contactListeners.m_capacityAndFlags = 2147483648;
  this->m_contactImpulseLimitBreachedListeners.m_data = 0i64;
  this->m_contactImpulseLimitBreachedListeners.m_size = 0;
  this->m_contactImpulseLimitBreachedListeners.m_capacityAndFlags = 2147483648;
  this->m_worldExtensions.m_data = 0i64;
  this->m_worldExtensions.m_size = 0;
  this->m_worldExtensions.m_capacityAndFlags = 2147483648;
  hkpWorldCinfo::hkpWorldCinfo(&v173, infoBase);
  v3->m_lastEntityUid = -1;
  v3->m_lastConstraintUid = -1;
  v3->m_isLocked = 0;
  v3->m_assertOnRunningOutOfSolverMemory.m_bool = 1;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkpViolatedConstraintArray *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(
                                       v5[11],
                                       1032i64);
  if ( v6 )
    v6->m_nextFreeElement = 0;
  else
    v6 = 0i64;
  v3->m_violatedConstraintArray = v6;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkpWorldOperationQueue *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 56i64);
  if ( v8 )
    hkpWorldOperationQueue::hkpWorldOperationQueue(v8, v3);
  else
    v9 = 0i64;
  v10 = *(__m128 *)&v173.m_memSizeAndFlags;
  v11 = *(__m128 *)((char *)&v173.m_gravity.m_quad + 8);
  v12 = (int)v173.m_collisionFilter.m_pntr;
  v3->m_pendingOperations = v9;
  v13 = v173.m_broadPhaseType.m_storage;
  v3->m_pendingOperationQueues = 0i64;
  *(_QWORD *)&v3->m_pendingOperationsCount = 0i64;
  *(_QWORD *)&v3->m_criticalOperationsLockCount = 0i64;
  *(_WORD *)&v3->m_blockExecutingPendingOperations.m_bool = 256;
  v3->m_modifyConstraintCriticalSection = 0i64;
  v3->m_propertyMasterLock = 0i64;
  v3->m_islandDirtyListCriticalSection = 0i64;
  v3->m_pendingOperationQueueCount = 1;
  v3->m_destructionWorld = 0i64;
  v3->m_broadPhaseExtents[0].m_quad = v10;
  v3->m_broadPhaseExtents[1].m_quad = v11;
  v3->m_broadPhaseNumMarkers = v12;
  v3->m_broadPhaseType.m_storage = v13;
  v3->m_broadPhase = 0i64;
  if ( v13 != 1 )
    v3->m_broadPhase = hkpBroadPhase::s_createSweepAndPruneBroadPhaseFunction(
                         v3->m_broadPhaseExtents,
                         &v3->m_broadPhaseExtents[1],
                         v12);
  if ( (unsigned __int8)(v3->m_broadPhaseType.m_storage - 1) <= 1u )
  {
    v14 = (hkReferencedObject *)&v3->m_broadPhase->vfptr;
    v3->m_broadPhase = hkpBroadPhase::s_createTreeBroadPhaseFunction(v3->m_broadPhase);
    if ( v14 )
      hkReferencedObject::removeReference(v14);
  }
  v15 = v173.m_broadPhaseQuerySize;
  v3->m_broadPhaseQuerySize = v173.m_broadPhaseQuerySize;
  v3->m_broadPhaseUpdateSize = v15 / 2;
  v3->m_sizeOfToiEventQueue = v173.m_broadPhaseWorldAabb.m_max.m_quad.m128_i32[1];
  if ( v4 != 20130200 )
  {
    hkErrStream::hkErrStream(&v164, &buf, 512);
    v16 = hkOstream::operator<<((hkOstream *)&v164.vfptr, "** Havok libs built with version [");
    v17 = hkOstream::operator<<(v16, 20130200, (int)v16);
    v18 = hkOstream::operator<<(v17, "], used with code built with [");
    v19 = hkOstream::operator<<(v18, v4, (int)v18);
    hkOstream::operator<<(v19, "]. **");
    if ( (unsigned int)hkError::messageError(1405700930, &buf, "World\\hkpWorld.cpp", 2962) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v164.vfptr);
  }
  v20 = *(float *)&v173.m_memoryWatchDog.m_pntr;
  v21.m_quad = (__m128)v173.m_gravity;
  v22 = *((float *)&v173.m_memoryWatchDog.m_pntr + 1);
  v23 = *(float *)&v173.m_memoryWatchDog.m_pntr;
  v3->m_gravity = v173.m_gravity;
  hkpWeldingUtility::initWeldingTable(v23, v22);
  v24 = v173.m_convexListFilter.m_pntr;
  v25 = v173.m_broadPhaseNumMarkers;
  v26 = *(float *)&v173.m_convexListFilter.m_pntr;
  v27 = (__m128)HIDWORD(v173.m_convexListFilter.m_pntr);
  v28 = v173.m_solverMicrosteps;
  v29 = *(float *)&v173.m_solverIterations;
  v3->m_shouldActivateOnRigidBodyTransformChange.m_bool = HIBYTE(v173.m_solverDamp);
  v30 = LOBYTE(v173.m_maxConstraintViolation);
  v3->m_enableToiWeldRejection.m_bool = v25;
  v31 = v26 * 0.5;
  v27.m128_f32[0] = v27.m128_f32[0] / *(float *)&v24;
  v32 = (unsigned int)FLOAT_1_0;
  LODWORD(v3->m_toiCollisionResponseRotateNormal) = v28;
  v3->m_snapCollisionToConvexEdgeThreshold = v20;
  v3->m_snapCollisionToConcaveEdgeThreshold = v20;
  v3->m_useCompoundSpuElf.m_bool = v30;
  v33 = *(_DWORD *)&v173.m_forceCoherentConstraintOrderingInSolver.m_bool;
  v3->m_deactivationReferenceDistance = v29;
  *(float *)&v32 = 1.0 / *((float *)&v24 + 1);
  v3->m_maxSectorsPerMidphaseCollideTask = v33;
  v3->m_maxSectorsPerNarrowphaseCollideTask = LODWORD(v173.m_snapCollisionToConvexEdgeThreshold);
  v3->m_processToisMultithreaded.m_bool = LOBYTE(v173.m_snapCollisionToConcaveEdgeThreshold);
  v3->m_maxEntriesPerToiMidphaseCollideTask = *(_DWORD *)&v173.m_enableToiWeldRejection.m_bool;
  v3->m_maxEntriesPerToiNarrowphaseCollideTask = LODWORD(v173.m_iterativeLinearCastEarlyOutDistance);
  v3->m_maxNumToiCollisionPairsSinglethreaded = v173.m_iterativeLinearCastMaxIterations;
  v34 = v173.m_expectedMaxLinearVelocity;
  v3->m_dynamicsStepInfo.m_solverInfo.m_dampDivFrictionTau = *((float *)&v24 + 1) / v31;
  v35 = (__m128)v32;
  v35.m128_f32[0] = (float)(1.0 / *((float *)&v24 + 1)) * *(float *)&v24;
  *(float *)&v3->m_dynamicsStepInfo.m_solverInfo.m_numSteps = v34;
  LODWORD(v3->m_dynamicsStepInfo.m_solverInfo.m_tau) = (_DWORD)v24;
  v3->m_dynamicsStepInfo.m_solverInfo.m_frictionTauDivDamp = (float)(1.0 / *((float *)&v24 + 1)) * v31;
  v3->m_dynamicsStepInfo.m_solverInfo.m_frictionTau = v31;
  v3->m_dynamicsStepInfo.m_solverInfo.m_damping = *((float *)&v24 + 1);
  LODWORD(v3->m_dynamicsStepInfo.m_solverInfo.m_tauDivDamp) = v35.m128_i32[0];
  LODWORD(v3->m_dynamicsStepInfo.m_solverInfo.m_dampDivTau) = v27.m128_i32[0];
  v3->m_dynamicsStepInfo.m_solverInfo.m_invIntegrateVelocityFactor.m_quad = _mm_shuffle_ps(v27, v27, 0);
  v3->m_dynamicsStepInfo.m_solverInfo.m_integrateVelocityFactor.m_quad = _mm_shuffle_ps(v35, v35, 0);
  v3->m_dynamicsStepInfo.m_solverInfo.m_contactRestingVelocity = v173.m_contactRestingVelocity;
  v36 = _mm_cvtsi32_si128(LODWORD(v34));
  v37 = v173.m_sizeOfToiEventQueue;
  v3->m_dynamicsStepInfo.m_solverInfo.m_numMicroSteps = v173.m_sizeOfToiEventQueue;
  *(float *)&v32 = 1.0 / COERCE_FLOAT(_mm_cvtepi32_ps(v36));
  *(float *)v36.m128i_i32 = v173.m_expectedMinPsiDeltaTime * v173.m_expectedMinPsiDeltaTime;
  LODWORD(v3->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps) = v32;
  LODWORD(v3->m_dynamicsStepInfo.m_solverInfo.m_maxConstraintViolationSqrd) = v36.m128i_i32[0];
  v38 = _mm_cvtsi32_si128(v37);
  v3->m_dynamicsStepInfo.m_solverInfo.m_forceCoherentConstraintOrderingInSolver.m_bool = *((_BYTE *)&v173.m_expectedMinPsiDeltaTime
                                                                                         + 4);
  LOBYTE(v37) = LOBYTE(v173.m_solverDamp);
  v3->m_dynamicsStepInfo.m_solverInfo.m_invNumMicroSteps = 1.0 / COERCE_FLOAT(_mm_cvtepi32_ps(v38));
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0] = v37;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1] = BYTE1(v173.m_solverDamp);
  v39 = _mm_mul_ps(v21.m_quad, v21.m_quad);
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter = BYTE2(v173.m_solverDamp);
  *(_QWORD *)&v3->m_dynamicsStepInfo.m_solverInfo.m_deltaTime = 0i64;
  v40 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)), _mm_shuffle_ps(v39, v39, 170));
  v41 = _mm_rsqrt_ps(v40);
  LODWORD(v42) = (unsigned __int128)_mm_andnot_ps(
                                      _mm_cmpleps(v40, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v41, v40), v41)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v41)),
                                        v40));
  if ( v42 == 0.0 )
    v42 = FLOAT_9_8100004;
  v43 = v3->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[0].m_relativeSleepVelocityThreshold = 2.1267625e37;
  v44 = 1.0 / (float)(v42 * 0.00000011920929);
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[0].m_linearVelocityThresholdInv = v44;
  v45 = v29 * v29;
  v46 = (float)(v29 * 4.0) * (float)(v29 * 4.0);
  v47 = (float)(v29 * 2.0) * (float)(v29 * 2.0);
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[0].m_slowObjectVelocityMultiplier = 1.0
                                                                                           - (float)((float)((float)(v42 * 0.0) * v44) * (float)(v43 * 0.016000001));
  v48 = (float)(v29 * 8.0) * (float)(v29 * 8.0);
  v49 = 1.0 / (float)(v42 * 0.00000011920929);
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[0].m_angularVelocityThresholdInv = 1.0
                                                                                          / (float)((float)(v42 * 0.00000011920929)
                                                                                                  * (float)(v42 * 0.1));
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[0].m_maxDistSqrd[0] = v45;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[0].m_maxDistSqrd[1] = v46;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[0].m_maxRotSqrd[0] = v47;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[0].m_maxRotSqrd[1] = v48;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[1].m_slowObjectVelocityMultiplier = 1.0
                                                                                           - (float)((float)((float)(v42 * 0.0) * v49) * (float)(v3->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps * 0.016000001));
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[1].m_linearVelocityThresholdInv = v49;
  v50 = 1.0 / (float)(v42 * 0.0099999998);
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[1].m_angularVelocityThresholdInv = 1.0
                                                                                          / (float)((float)(v42 * 0.00000011920929)
                                                                                                  * (float)(v42 * 0.1));
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[1].m_relativeSleepVelocityThreshold = 2.1267625e37;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[1].m_maxDistSqrd[0] = v45;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[1].m_maxDistSqrd[1] = v46;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[1].m_maxRotSqrd[0] = v47;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[1].m_maxRotSqrd[1] = v48;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[2].m_slowObjectVelocityMultiplier = 1.0
                                                                                           - (float)((float)((float)(v42 * 0.079999998) * v50) * (float)(v3->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps * 0.016000001));
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[2].m_linearVelocityThresholdInv = v50;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[2].m_angularVelocityThresholdInv = 1.0
                                                                                          / (float)((float)(v42 * 0.0099999998)
                                                                                                  * (float)(v42 * 0.1));
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[2].m_relativeSleepVelocityThreshold = (float)(v3->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps * 0.016000001)
                                                                                             * 12.5;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[2].m_maxDistSqrd[0] = v45;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[2].m_maxDistSqrd[1] = v46;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[2].m_maxRotSqrd[0] = v47;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[2].m_maxRotSqrd[1] = v48;
  v51 = *(hkReferencedObject **)&v173.m_collisionTolerance;
  v52 = 1.0 / (float)(v42 * 0.017000001);
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[3].m_slowObjectVelocityMultiplier = 1.0
                                                                                           - (float)((float)((float)(v42 * 0.2) * v52) * (float)(v3->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps * 0.016000001));
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[3].m_linearVelocityThresholdInv = v52;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[3].m_angularVelocityThresholdInv = 1.0
                                                                                          / (float)((float)(v42 * 0.017000001)
                                                                                                  * (float)(v42 * 0.1));
  v53 = 1.0 / (float)(v42 * 0.02);
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[3].m_relativeSleepVelocityThreshold = (float)(v3->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps * 0.016000001)
                                                                                             * 5.0;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[3].m_maxDistSqrd[0] = v45;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[3].m_maxDistSqrd[1] = v46;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[3].m_maxRotSqrd[0] = v47;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[3].m_maxRotSqrd[1] = v48;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[4].m_slowObjectVelocityMultiplier = 1.0
                                                                                           - (float)((float)((float)(v42 * 0.30000001) * v53) * (float)(v3->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps * 0.016000001));
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[4].m_linearVelocityThresholdInv = v53;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[4].m_angularVelocityThresholdInv = 1.0
                                                                                          / (float)((float)(v42 * 0.02)
                                                                                                  * (float)(v42 * 0.1));
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[4].m_relativeSleepVelocityThreshold = (float)(v3->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps * 0.016000001)
                                                                                             * 3.3333333;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[4].m_maxDistSqrd[0] = v45;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[4].m_maxDistSqrd[1] = v46;
  v54 = 1.0 / (float)(v42 * 0.025);
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[4].m_maxRotSqrd[0] = v47;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[4].m_maxRotSqrd[1] = v48;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[5].m_slowObjectVelocityMultiplier = 1.0
                                                                                           - (float)((float)((float)(v42 * 0.40000001) * v54) * (float)(v3->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps * 0.016000001));
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[5].m_linearVelocityThresholdInv = v54;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[5].m_angularVelocityThresholdInv = 1.0
                                                                                          / (float)((float)(v42 * 0.025)
                                                                                                  * (float)(v42 * 0.1));
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[5].m_relativeSleepVelocityThreshold = (float)(v3->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps * 0.016000001)
                                                                                             * 2.5;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[5].m_maxDistSqrd[0] = v45;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[5].m_maxDistSqrd[1] = v46;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[5].m_maxRotSqrd[0] = v47;
  v3->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[5].m_maxRotSqrd[1] = v48;
  if ( v51 )
    hkReferencedObject::addReference(v51);
  v55 = (hkReferencedObject *)&v3->m_memoryWatchDog.m_pntr->vfptr;
  if ( v55 )
    hkReferencedObject::removeReference(v55);
  v56 = BYTE2(v173.m_maxSectorsPerMidphaseCollideTask);
  v57 = v173.m_maxSectorsPerMidphaseCollideTask;
  v3->m_memoryWatchDog.m_pntr = (hkWorldMemoryAvailableWatchDog *)v51;
  v3->m_wantSimulationIslands.m_bool = v56;
  v3->m_wantDeactivation.m_bool = v57;
  if ( !v56 && v57 )
    v3->m_wantDeactivation.m_bool = 0;
  v3->m_processActionsInSingleThread.m_bool = v173.m_processToisMultithreaded.m_bool;
  v3->m_allowIntegrationOfIslandsWithoutConstraintsInASeparateJob.m_bool = *((_BYTE *)&v173.m_processToisMultithreaded
                                                                           + 1);
  v58 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v59 = (hkpTypedBroadPhaseDispatcher *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v58[11] + 8i64))(
                                          v58[11],
                                          536i64);
  if ( v59 )
    hkpTypedBroadPhaseDispatcher::hkpTypedBroadPhaseDispatcher(v59);
  else
    v60 = 0i64;
  v3->m_broadPhaseDispatcher = v60;
  v61 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v62 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v61[11] + 8i64))(v61[11], 24i64);
  if ( v62 )
  {
    *(_DWORD *)(v62 + 8) = 0x1FFFF;
    *(_QWORD *)v62 = &hkpPhantomBroadPhaseListener::`vftable{for `hkReferencedObject};
    *(_QWORD *)(v62 + 16) = &hkpPhantomBroadPhaseListener::`vftable{for `hkpBroadPhaseListener};
  }
  else
  {
    v62 = 0i64;
  }
  v3->m_phantomBroadPhaseListener = (hkpPhantomBroadPhaseListener *)v62;
  v63 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v64 = (hkpEntityEntityBroadPhaseListener *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v63[11] + 8i64))(
                                               v63[11],
                                               32i64);
  if ( v64 )
    hkpEntityEntityBroadPhaseListener::hkpEntityEntityBroadPhaseListener(v64, v3);
  else
    v65 = 0i64;
  v3->m_entityEntityBroadPhaseListener = v65;
  v66 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v67 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v66[11] + 8i64))(v66[11], 24i64);
  if ( v67 )
  {
    *(_DWORD *)(v67 + 8) = 0x1FFFF;
    *(_QWORD *)v67 = &hkpBroadPhaseBorderListener::`vftable{for `hkReferencedObject};
    *(_QWORD *)(v67 + 16) = &hkpBroadPhaseBorderListener::`vftable{for `hkpBroadPhaseListener};
  }
  else
  {
    v67 = 0i64;
  }
  v3->m_broadPhaseBorderListener = (hkpBroadPhaseBorderListener *)v67;
  v68 = v3->m_phantomBroadPhaseListener;
  v69 = (signed __int64)&v68->vfptr;
  if ( !v68 )
    v69 = 0i64;
  v3->m_broadPhaseDispatcher->m_broadPhaseListeners[1][2] = (hkpBroadPhaseListener *)v69;
  v70 = v3->m_phantomBroadPhaseListener;
  if ( v70 )
    v71 = (signed __int64)&v70->vfptr;
  else
    v71 = 0i64;
  v3->m_broadPhaseDispatcher->m_broadPhaseListeners[2][1] = (hkpBroadPhaseListener *)v71;
  v72 = v3->m_phantomBroadPhaseListener;
  if ( v72 )
    v73 = (signed __int64)&v72->vfptr;
  else
    v73 = 0i64;
  v3->m_broadPhaseDispatcher->m_broadPhaseListeners[2][2] = (hkpBroadPhaseListener *)v73;
  v74 = v3->m_entityEntityBroadPhaseListener;
  if ( v74 )
    v75 = (signed __int64)&v74->vfptr;
  else
    v75 = 0i64;
  v3->m_broadPhaseDispatcher->m_broadPhaseListeners[1][1] = (hkpBroadPhaseListener *)v75;
  v76 = v3->m_broadPhaseBorderListener;
  if ( v76 )
    v77 = (signed __int64)&v76->vfptr;
  else
    v77 = 0i64;
  v3->m_broadPhaseDispatcher->m_broadPhaseListeners[1][3] = (hkpBroadPhaseListener *)v77;
  v78 = v3->m_broadPhaseBorderListener;
  if ( v78 )
    v79 = (signed __int64)&v78->vfptr;
  else
    v79 = 0i64;
  v3->m_broadPhaseDispatcher->m_broadPhaseListeners[3][1] = (hkpBroadPhaseListener *)v79;
  v80 = v3->m_broadPhaseBorderListener;
  if ( v80 )
    v81 = (signed __int64)&v80->vfptr;
  else
    v81 = 0i64;
  v3->m_broadPhaseDispatcher->m_broadPhaseListeners[2][3] = (hkpBroadPhaseListener *)v81;
  v82 = v3->m_broadPhaseBorderListener;
  if ( v82 )
    v83 = (signed __int64)&v82->vfptr;
  else
    v83 = 0i64;
  v3->m_broadPhaseDispatcher->m_broadPhaseListeners[3][2] = (hkpBroadPhaseListener *)v83;
  v84 = v3->m_broadPhaseBorderListener;
  v85 = (signed __int64)&v84->vfptr;
  if ( !v84 )
    v85 = 0i64;
  v3->m_broadPhaseDispatcher->m_broadPhaseListeners[3][3] = (hkpBroadPhaseListener *)v85;
  v86 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v87 = (hkpSimpleConstraintContactMgr::Factory *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v86[11] + 8i64))(
                                                    v86[11],
                                                    24i64);
  if ( v87 )
  {
    hkpSimpleConstraintContactMgr::Factory::Factory(v87, v3);
    v89 = v88;
  }
  else
  {
    v89 = 0i64;
  }
  v90 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v91 = (hkpCollisionDispatcher *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v90[11] + 8i64))(
                                    v90[11],
                                    10880i64);
  if ( v91 )
    hkpCollisionDispatcher::hkpCollisionDispatcher(
      v91,
      (hkpCollisionAgent *(__fastcall *)(hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpContactMgr *))hkpNullAgent::createNullAgent,
      v89);
  else
    v92 = 0i64;
  v3->m_collisionDispatcher = v92;
  hkReferencedObject::removeReference((hkReferencedObject *)&v89->vfptr);
  v93 = (hkReferencedObject *)v173.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[0];
  if ( v173.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[0] )
  {
    v97 = (hkReferencedObject *)v173.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[0];
    v3->m_collisionFilter = (hkpCollisionFilter *)v173.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[0];
    hkReferencedObject::addReference(v97);
    ((void (__fastcall *)(hkpCollisionFilter *, hkpWorld *))v3->m_collisionFilter->vfptr[1].__first_virtual_table_function__)(
      v3->m_collisionFilter,
      v3);
  }
  else
  {
    v94 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v95 = (hkpCollisionFilter *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v94[11] + 8i64))(
                                  v94[11],
                                  (unsigned int)((_DWORD)v93 + 72));
    v96 = v95;
    if ( v95 )
    {
      hkpCollisionFilter::hkpCollisionFilter(v95);
      v96->m_type.m_storage = 1;
      v96->vfptr = (hkBaseObjectVtbl *)&hkpNullCollisionFilter::`vftable{for `hkReferencedObject};
      v96->vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
      v96->vfptr = (hkpShapeCollectionFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
      v96->vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
      v96->vfptr = (hkpRayCollidableFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpRayCollidableFilter};
      v3->m_collisionFilter = v96;
    }
    else
    {
      v3->m_collisionFilter = 0i64;
    }
  }
  v98 = (hkReferencedObject *)v173.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[1];
  if ( v173.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[1] )
  {
    v101 = (hkReferencedObject *)v173.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[1];
    v3->m_convexListFilter = (hkpConvexListFilter *)v173.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[1];
    hkReferencedObject::addReference(v101);
  }
  else
  {
    v99 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v100 = (*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v99[11] + 8i64))(v99[11], (unsigned int)((_DWORD)v98 + 16));
    if ( v100 )
    {
      *(_DWORD *)(v100 + 8) = 0x1FFFF;
      *(_QWORD *)v100 = &hkpDefaultConvexListFilter::`vftable;
      v3->m_convexListFilter = (hkpConvexListFilter *)v100;
    }
    else
    {
      v3->m_convexListFilter = 0i64;
    }
  }
  v102 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v103 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v102[11] + 8i64))(v102[11], 160i64);
  v104 = (__m128i *)v103;
  if ( v103 )
  {
    LODWORD(v103) = 0;
    HIDWORD(v104->m128i_i64[1]) = 0;
    v104[7].m128i_i64[1] = 0i64;
  }
  else
  {
    v104 = 0i64;
  }
  v105 = *(_DWORD *)&v173.m_broadPhaseType.m_storage;
  v106 = BYTE4(v173.m_collisionFilter.m_pntr);
  v3->m_collisionInput = (hkpProcessCollisionInput *)v104;
  LODWORD(v104->m128i_i64[1]) = v103;
  v104->m128i_i64[0] = (__int64)v3->m_collisionDispatcher;
  v104[1].m128i_i32[0] = v105;
  v104[1].m128i_i64[1] = (__int64)v3->m_collisionFilter;
  v104[2].m128i_i64[0] = (__int64)v3->m_convexListFilter;
  v107 = BYTE5(v173.m_collisionFilter.m_pntr);
  v3->m_contactPointGeneration.m_storage = v106;
  v104[8].m128i_i8[9] = v107;
  v108 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v109 = (_DWORD *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v108[11] + 8i64))(v108[11], 16i64);
  if ( v109 )
  {
    *v109 = 1008981770;
    v109[1] = 20;
  }
  v110 = *(_DWORD *)&v173.m_contactPointGeneration.m_storage;
  v104[9].m128i_i64[0] = (__int64)v109;
  *v109 = v110;
  v111 = _mm_sub_ps(v11, v10);
  *(float *)(v104[9].m128i_i64[0] + 4) = v173.m_solverTau;
  v112 = _mm_rcp_ps(v111);
  v104[8].m128i_i8[8] = BYTE1(v173.m_broadPhaseNumMarkers);
  v113 = v104->m128i_i64[0];
  v104[2].m128i_i32[2] = 0;
  v114 = (__m128 *)&v104[5];
  v115 = v104[3].m128i_i8;
  v116 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v111, v112)), v112);
  v104[7].m128i_i64[0] = v113 + 10368;
  v104[6].m128i_i64[0] = 0i64;
  v104[6].m128i_i64[1] = 0i64;
  v117 = (__m128 *)&v104[4];
  *v114 = _mm_mul_ps(
            _mm_shuffle_ps((__m128)LODWORD(FLOAT_2_1473526e9), (__m128)LODWORD(FLOAT_2_1473526e9), 0),
            _mm_shuffle_ps(v116, _mm_unpackhi_ps(v116, query.m_quad), 196));
  v177 = FLOAT_4_6568971eN10;
  v118 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v10);
  *v115 = v118;
  *v117 = _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps((__m128)LODWORD(FLOAT_4_6568971eN10), (__m128)LODWORD(FLOAT_4_6568971eN10), 0),
              v111),
            v118);
  *(__m128i *)v114 = _mm_srli_si128(_mm_slli_si128(_mm_load_si128(v104 + 5), 4), 4);
  *v115 = _mm_srli_si128(_mm_slli_si128(_mm_load_si128(v104 + 3), 4), 4);
  *(__m128i *)v117 = _mm_srli_si128(_mm_slli_si128(_mm_load_si128(v104 + 4), 4), 4);
  ((void (*)(void))v3->m_broadPhase->vfptr[15].__vecDelDtor)();
  hkWorld_setupContactMgrFactories(v3, v3->m_collisionDispatcher);
  v119 = hkpWorld::m_forceMultithreadedSimulation.m_bool == 0;
  v120 = BYTE1(v173.m_maxSectorsPerMidphaseCollideTask);
  v3->m_minDesiredIslandSize = 0;
  if ( !v119 )
    v120 = 3;
  v3->m_simulationType.m_storage = v120;
  switch ( v120 )
  {
    case 1:
      v125 = hkpSimulation::createDiscrete(v3);
      goto LABEL_95;
    case 2:
      v125 = hkpSimulation::createContinuous(v3);
LABEL_95:
      v3->m_simulation = v125;
      break;
    case 3:
      v121 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v122 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v121[11] + 8i64))(
                                    v121[11],
                                    40i64);
      if ( v122 )
        hkCriticalSection::hkCriticalSection(v122, 4000);
      v3->m_modifyConstraintCriticalSection = v122;
      v123 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v124 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v123[11] + 8i64))(
                                    v123[11],
                                    40i64);
      if ( v124 )
        hkCriticalSection::hkCriticalSection(v124, 4000);
      v3->m_propertyMasterLock = v124;
      v3->m_simulation = hkpSimulation::createMultithreaded(v3);
      v3->m_minDesiredIslandSize = v173.m_maxSectorsPerNarrowphaseCollideTask;
      break;
  }
  v126 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v127 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v126[11] + 8i64))(v126[11], 40i64);
  if ( v127 )
    hkCriticalSection::hkCriticalSection(v127, 4000);
  v128 = v173.m_maxEntriesPerToiMidphaseCollideTask;
  v3->m_islandDirtyListCriticalSection = v127;
  LODWORD(v3->m_simulation->m_frameMarkerPsiSnap) = v128;
  v129 = _mm_mul_ps(v3->m_gravity.m_quad, v3->m_gravity.m_quad);
  v130 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v129, v129, 85), _mm_shuffle_ps(v129, v129, 0)),
           _mm_shuffle_ps(v129, v129, 170));
  v131 = _mm_rsqrt_ps(v130);
  LODWORD(v132) = (unsigned __int128)_mm_andnot_ps(
                                       _mm_cmpleps(v130, (__m128)0i64),
                                       _mm_mul_ps(
                                         _mm_mul_ps(
                                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v131, v130), v131)),
                                           _mm_mul_ps(*(__m128 *)_xmm, v131)),
                                         v130));
  if ( v132 == 0.0 )
    v132 = FLOAT_9_8100004;
  v133 = *(_DWORD *)&v173.m_deactivationNumInactiveFramesSelectFlag0;
  v134 = v173.m_deactivationReferenceDistance;
  v135 = v173.m_toiCollisionResponseRotateNormal;
  v136 = v3->m_collisionInput;
  v137 = v3->m_collisionDispatcher;
  v138 = *(_DWORD *)&v173.m_useCompoundSpuElf.m_bool;
  v139 = v173.m_broadPhaseWorldAabb.m_max.m_quad.m128_f32[2];
  v3->m_numToisTillAllowedPenetrationSimplifiedToi = *(float *)&v173.m_deactivationNumInactiveFramesSelectFlag0;
  v3->m_numToisTillAllowedPenetrationToi = v134;
  v3->m_numToisTillAllowedPenetrationToiHigher = v135;
  LODWORD(v3->m_numToisTillAllowedPenetrationToiForced) = v138;
  *(float *)&v164.vfptr = v132;
  v140 = v136->m_tolerance.m_storage;
  *(float *)&v164.m_memSizeAndFlags = v139;
  v169 = v120 >= 2;
  v167 = 196609;
  v170 = v106 == 2;
  v168 = 327684;
  *((float *)&v164.vfptr + 1) = v140;
  v164.m_writer.m_pntr = (hkStreamWriter *)__PAIR__(LODWORD(v134), v133);
  v172 = v25;
  v171 = v106 >= 1;
  *(float *)(&v164.m_referenceCount + 1) = v173.m_broadPhaseWorldAabb.m_max.m_quad.m128_f32[0];
  v165 = v135;
  v166 = v138;
  hkpCollisionDispatcher::initCollisionQualityInfo(v137, (hkpCollisionDispatcher::InitCollisionQualityInfo *)&v164);
  v3->m_collisionInput->m_collisionQualityInfo.m_storage = &v3->m_collisionDispatcher->m_collisionQualityInfo[1];
  v141 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v142 = (hkpSimulationIsland *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v141[11] + 8i64))(
                                  v141[11],
                                  184i64);
  if ( v142 )
    hkpSimulationIsland::hkpSimulationIsland(v142, v3);
  else
    v143 = 0i64;
  v3->m_fixedIsland = v143;
  v143->m_storageIndex = -1;
  *((_BYTE *)v3->m_fixedIsland + 50) &= 0xF3u;
  *((_BYTE *)v3->m_fixedIsland + 50) &= 0xFCu;
  if ( !v3->m_wantSimulationIslands.m_bool )
  {
    v144 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v145 = (hkpSimulationIsland *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v144[11] + 8i64))(
                                    v144[11],
                                    184i64);
    if ( v145 )
    {
      hkpSimulationIsland::hkpSimulationIsland(v145, v3);
      v147 = v146;
    }
    else
    {
      v147 = 0i64;
    }
    if ( v3->m_activeSimulationIslands.m_size == (v3->m_activeSimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v3->m_activeSimulationIslands,
        8);
    v3->m_activeSimulationIslands.m_data[v3->m_activeSimulationIslands.m_size++] = v147;
    v147->m_storageIndex = 0;
  }
  hkpRigidBodyCinfo::hkpRigidBodyCinfo((hkpRigidBodyCinfo *)&v173.m_maxNumToiCollisionPairsSinglethreaded);
  v175 = 5;
  v174 = 0;
  v148 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v149 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v148[11] + 8i64))(v148[11], 720i64);
  if ( v149 )
    hkpRigidBody::hkpRigidBody(v149, (hkpRigidBodyCinfo *)&v173.m_maxNumToiCollisionPairsSinglethreaded);
  else
    v150 = 0i64;
  v3->m_fixedRigidBody = v150;
  v150->m_npData = 0;
  hkpWorld::addEntity(v3, (hkpEntity *)&v3->m_fixedRigidBody->vfptr, HK_ENTITY_ACTIVATION_DO_ACTIVATE);
  hkReferencedObject::removeReference((hkReferencedObject *)&v3->m_fixedRigidBody->vfptr);
  v151 = v173.m_broadPhaseBorderBehaviour.m_storage;
  v152 = (_DWORD *)&v3->m_dynamicsStepInfo.m_stepInfo.m_startTime.m_storage;
  *v152 = 0;
  v152[1] = 1015580809;
  v152[2] = 1015580809;
  v152[3] = 1114636287;
  v3->m_collisionInput->m_dynamicsInfo = &v3->m_dynamicsStepInfo;
  if ( v151 == 3 )
  {
    v3->m_broadPhaseBorder = 0i64;
  }
  else
  {
    v153 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v154 = (hkpBroadPhaseBorder *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v153[11] + 8i64))(
                                    v153[11],
                                    120i64);
    if ( v154 )
    {
      hkpBroadPhaseBorder::hkpBroadPhaseBorder(
        v154,
        v3,
        (hkpWorldCinfo::BroadPhaseBorderBehaviour)v151,
        v173.m_mtPostponeAndSortBroadPhaseBorderCallbacks);
      v3->m_broadPhaseBorder = v155;
    }
    else
    {
      v3->m_broadPhaseBorder = 0i64;
    }
  }
  v156 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v157 = (hkpDefaultWorldMaintenanceMgr *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v156[11] + 8i64))(
                                            v156[11],
                                            24i64);
  if ( v157 )
  {
    hkpDefaultWorldMaintenanceMgr::hkpDefaultWorldMaintenanceMgr(v157);
    v159 = v158;
  }
  else
  {
    v159 = 0i64;
  }
  v3->m_maintenanceMgr = v159;
  ((void (__fastcall *)(hkpWorldMaintenanceMgr *, hkpWorld *))v159->vfptr[1].__first_virtual_table_function__)(v159, v3);
  if ( LOBYTE(v173.m_maxEntriesPerToiNarrowphaseCollideTask) )
    hkpWorldExtension::requireExtension<hkpCollisionCallbackUtil>((hkpWorldExtension *)v3, v160);
  if ( v120 != 3 )
    hkMultiThreadCheck::disableChecks(&v3->m_multiThreadCheck);
  v161 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v162 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v161[11] + 8i64))(v161[11], 352i64);
  if ( v162 )
  {
    *(_QWORD *)(v162 + 152) = hkpBeginConstraints;
    *(_DWORD *)(v162 + 172) = 0;
    *(_QWORD *)(v162 + 280) = 0i64;
  }
  else
  {
    v162 = 0i64;
  }
  v163 = *(hkReferencedObject **)&v173.m_collisionTolerance;
  v3->m_multithreadedSimulationJobData = (hkpMtThreadStructure *)v162;
  if ( v163 )
    hkReferencedObject::removeReference(v163);
  if ( v98 )
    hkReferencedObject::removeReference(v98);
  if ( v93 )
    hkReferencedObject::removeReference(v93);
}ct::removeReference(v98);
  if ( v93 )
    hkReferencedObject::removeReference(v93);
}

// File Line: 3397
// RVA: 0xD5C1D0
void __fastcall hkpWorld::shiftBroadPhase(hkpWorld *this, hkVector4f *shiftDistance, hkVector4f *effectiveShiftDistanceOut, hkpWorld::CachedAabbUpdate updateAabbs)
{
  hkpWorld *v4; // r15
  hkpWorld::CachedAabbUpdate v5; // er12
  hkVector4f *v6; // rsi
  hkVector4f *v7; // rbx
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r8
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  hkpBroadPhase *v13; // rcx
  __int64 v14; // r13
  hkpCollisionFilter *v15; // r9
  hkpCollidableCollidableFilter *v16; // r9
  hkpBroadPhaseBorder *v17; // r14
  signed __int64 v18; // rdi
  __m128 *v19; // rbx
  int v20; // eax
  int v21; // eax
  __int64 v22; // rbx
  int v23; // er8
  bool v24; // zf
  unsigned int v25; // eax
  __int64 v26; // rdi
  __int64 v27; // rax
  char *v28; // rsi
  signed int v29; // er14
  __int64 *v30; // rdx
  BOOL v31; // eax
  _BOOL8 v32; // rbx
  __int64 v33; // r9
  hkpSimulationIsland **v34; // r10
  __int64 v35; // rdx
  hkpSimulationIsland *v36; // rax
  _BOOL8 v37; // rcx
  __int64 v38; // r9
  hkpSimulationIsland **v39; // r10
  __int64 v40; // r11
  __int64 v41; // rdx
  hkpSimulationIsland *v42; // rax
  __int64 v43; // rcx
  char *v44; // r12
  __int64 v45; // r14
  int v46; // ebx
  __int64 v47; // rdi
  __int64 v48; // rsi
  _QWORD *v49; // rax
  _QWORD *v50; // rcx
  _QWORD *v51; // r8
  unsigned __int64 v52; // rax
  signed __int64 v53; // rcx
  __int64 v54; // [rsp+20h] [rbp-60h]
  hkpEntity **array; // [rsp+28h] [rbp-58h]
  int v56; // [rsp+30h] [rbp-50h]
  int v57; // [rsp+34h] [rbp-4Ch]
  hkpTypedBroadPhaseHandlePair *newPairs; // [rsp+38h] [rbp-48h]
  int numNewPairs; // [rsp+40h] [rbp-40h]
  int v60; // [rsp+44h] [rbp-3Ch]
  signed int v61; // [rsp+90h] [rbp+10h]
  void *v62; // [rsp+A0h] [rbp+20h]
  int v63; // [rsp+A8h] [rbp+28h]

  v4 = this;
  v5 = updateAabbs;
  v6 = effectiveShiftDistanceOut;
  v7 = shiftDistance;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtBroadphase Shift";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = v4->m_broadPhase;
  LODWORD(v14) = 0;
  v60 = 2147483648;
  newPairs = 0i64;
  numNewPairs = 0;
  ((void (__fastcall *)(hkpBroadPhase *, hkVector4f *, hkVector4f *, hkpTypedBroadPhaseHandlePair **))v13->vfptr[11].__first_virtual_table_function__)(
    v13,
    v7,
    v6,
    &newPairs);
  ((void (__fastcall *)(hkpBroadPhase *, hkpCollisionInput::Aabb32Info *, hkVector4f *))v4->m_broadPhase->vfptr[12].__vecDelDtor)(
    v4->m_broadPhase,
    &v4->m_collisionInput->m_aabb32Info,
    &v4->m_collisionInput->m_aabb32Info.m_bitOffsetHigh);
  v4->m_broadPhaseExtents[0].m_quad = _mm_add_ps(v4->m_broadPhaseExtents[0].m_quad, v6->m_quad);
  v4->m_broadPhaseExtents[1].m_quad = _mm_add_ps(v6->m_quad, v4->m_broadPhaseExtents[1].m_quad);
  v15 = v4->m_collisionFilter;
  ++v4->m_criticalOperationsLockCount;
  if ( v15 )
    v16 = (hkpCollidableCollidableFilter *)&v15->vfptr;
  else
    v16 = 0i64;
  hkpTypedBroadPhaseDispatcher::addPairs(v4->m_broadPhaseDispatcher, newPairs, numNewPairs, v16);
  v17 = v4->m_broadPhaseBorder;
  if ( v17 )
  {
    v18 = 0i64;
    do
    {
      v19 = (__m128 *)v17->m_phantoms[v18];
      v20 = (*(__int64 (__fastcall **)(__m128 *))(v19->m128_u64[0] + 48))(v19);
      if ( v20 )
      {
        if ( (unsigned int)(v20 - 1) <= 1 )
          v19[18] = _mm_add_ps(v6->m_quad, v19[18]);
      }
      else
      {
        v19[15] = _mm_add_ps(v19[15], v6->m_quad);
        v19[16] = _mm_add_ps(v6->m_quad, v19[16]);
      }
      ++v18;
    }
    while ( v18 < 6 );
  }
  if ( v5 == SHIFT_BROADPHASE_UPDATE_ENTITY_AABBS )
  {
    v21 = v4->m_inactiveSimulationIslands.m_size;
    v22 = (__int64)v4->m_fixedIsland;
    array = 0i64;
    ++v21;
    v23 = 0;
    v56 = 0;
    v24 = v4->m_activeSimulationIslands.m_size + v21 == 0;
    v25 = v4->m_activeSimulationIslands.m_size + v21;
    v57 = 2147483648;
    v54 = v22;
    v26 = v25;
    if ( v24 )
    {
      v28 = 0i64;
    }
    else
    {
      v63 = 8 * v25;
      v27 = ((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
              &hkContainerHeapAllocator::s_alloc,
              &v63,
              0i64);
      v23 = v56;
      v28 = (char *)v27;
      v25 = v63 / 8;
    }
    v29 = 2147483648;
    v30 = &v54;
    if ( v25 )
      v29 = v25;
    v31 = v22 != 0;
    v62 = v28;
    if ( !v22 )
      v30 = 0i64;
    v61 = v29;
    v32 = v22 != 0;
    if ( v31 > 0 )
    {
      memmove(v28, v30, 8i64 * v31);
      v23 = v56;
    }
    v33 = v4->m_activeSimulationIslands.m_size;
    v34 = v4->m_activeSimulationIslands.m_data;
    v35 = 0i64;
    if ( v33 > 0 )
    {
      do
      {
        v36 = v34[v35];
        v37 = v32 + v35++;
        *(_QWORD *)&v28[8 * v37] = v36;
      }
      while ( v35 < v33 );
      v23 = v56;
    }
    v38 = v4->m_inactiveSimulationIslands.m_size;
    v39 = v4->m_inactiveSimulationIslands.m_data;
    v40 = v4->m_activeSimulationIslands.m_size;
    v41 = 0i64;
    if ( v38 > 0 )
    {
      do
      {
        v42 = v39[v41];
        v43 = v41++ + v40 + v32;
        *(_QWORD *)&v28[8 * v43] = v42;
      }
      while ( v41 < v38 );
      v23 = v56;
    }
    if ( (signed int)v26 > 0 )
    {
      v44 = v28;
      v14 = v26;
      do
      {
        v45 = *(_QWORD *)v44;
        v46 = 0;
        if ( *(_DWORD *)(*(_QWORD *)v44 + 104i64) > 0 )
        {
          v47 = 0i64;
          do
          {
            v48 = *(_QWORD *)(v45 + 96);
            if ( *(_QWORD *)(*(_QWORD *)(v48 + v47) + 32i64) )
            {
              if ( v23 == (v57 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
                v23 = v56;
              }
              array[v23] = *(hkpEntity **)(v48 + v47);
              v23 = v56++ + 1;
            }
            ++v46;
            v47 += 8i64;
          }
          while ( v46 < *(_DWORD *)(v45 + 104) );
        }
        v44 += 8;
        --v14;
      }
      while ( v14 );
      v29 = v61;
    }
    hkpEntityAabbUtil::entityBatchRecalcAabb((hkpCollisionInput *)&v4->m_collisionInput->m_dispatcher, array, v23);
    if ( v29 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v62,
        8 * v29);
    v56 = v14;
    if ( v57 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        8 * v57);
  }
  v24 = v4->m_criticalOperationsLockCount-- == 1;
  if ( v24 && !v4->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v4->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v4);
    if ( v4->m_pendingOperationQueueCount == 1 && v4->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(v4);
  }
  v49 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v50 = (_QWORD *)v49[1];
  v51 = v49;
  if ( (unsigned __int64)v50 < v49[3] )
  {
    *v50 = "Et";
    v52 = __rdtsc();
    v53 = (signed __int64)(v50 + 2);
    *(_DWORD *)(v53 - 8) = v52;
    v51[1] = v53;
  }
  numNewPairs = v14;
  if ( v60 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      newPairs,
      16 * v60);
}

// File Line: 3493
// RVA: 0xD5B2D0
void __fastcall hkpWorld::setCollisionFilter(hkpWorld *this, hkpCollisionFilter *filter, hkBool runUpdateCollisionFilterOnWorld, hkpUpdateCollisionFilterOnWorldMode updateMode, hkpUpdateCollectionFilterMode updateShapeCollectionFilter)
{
  hkpUpdateCollisionFilterOnWorldMode v5; // esi
  hkpCollisionFilter *v6; // rbx
  hkpWorld *v7; // rdi
  _QWORD **v8; // rax
  hkpNullCollisionFilter *v9; // rax
  hkpCollisionFilter *v10; // rax
  hkReferencedObject *v11; // rcx
  hkpProcessCollisionInput *v12; // rax
  char v13; // [rsp+40h] [rbp+18h]

  v13 = runUpdateCollisionFilterOnWorld.m_bool;
  v5 = updateMode;
  v6 = filter;
  v7 = this;
  if ( filter )
  {
    hkReferencedObject::addReference((hkReferencedObject *)&filter->vfptr);
  }
  else
  {
    v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v9 = (hkpNullCollisionFilter *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v8[11] + 8i64))(
                                     v8[11],
                                     (unsigned int)((_DWORD)v6 + 72));
    if ( v9 )
    {
      hkpNullCollisionFilter::hkpNullCollisionFilter(v9);
      v6 = v10;
    }
    else
    {
      v6 = 0i64;
    }
  }
  v11 = (hkReferencedObject *)&v7->m_collisionFilter->vfptr;
  if ( v11 )
    hkReferencedObject::removeReference(v11);
  v12 = v7->m_collisionInput;
  v7->m_collisionFilter = v6;
  v12->m_filter.m_storage = v6;
  ((void (__fastcall *)(hkpCollisionFilter *, hkpWorld *))v7->m_collisionFilter->vfptr[1].__first_virtual_table_function__)(
    v7->m_collisionFilter,
    v7);
  if ( v13 )
    hkpWorld::updateCollisionFilterOnWorld(v7, v5, updateShapeCollectionFilter);
}

// File Line: 3533
// RVA: 0xD5C960
void __fastcall hkpWorld::checkAccessGetActiveSimulationIslands(hkpWorld *this)
{
  ;
}

// File Line: 3545
// RVA: 0xD5C170
void __fastcall hkpWorld::setBroadPhaseBorder(hkpWorld *this, hkpBroadPhaseBorder *b)
{
  hkpWorld *v2; // rdi
  hkpBroadPhaseBorder *v3; // rcx
  hkpBroadPhaseBorder *v4; // rbx

  v2 = this;
  v3 = this->m_broadPhaseBorder;
  v4 = b;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr[2].__vecDelDtor)();
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_broadPhaseBorder->vfptr);
  }
  v2->m_broadPhaseBorder = v4;
  if ( v4 )
    hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
}

// File Line: 3561
// RVA: 0xD5C160
hkpBroadPhaseBorder *__fastcall hkpWorld::getBroadPhaseBorder(hkpWorld *this)
{
  return this->m_broadPhaseBorder;
}

// File Line: 3568
// RVA: 0xD5B490
void __fastcall hkpWorld::castRay(hkpWorld *this, hkpWorldRayCastInput *input, hkpRayHitCollector *collector)
{
  hkpWorld *v3; // rbx
  hkpRayHitCollector *v4; // rdi
  hkpWorldRayCastInput *v5; // rsi
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  hkpCollisionFilter *v11; // r9
  hkpBroadPhase *v12; // rdx
  _QWORD *v13; // rax
  _QWORD *v14; // rcx
  _QWORD *v15; // r8
  unsigned __int64 v16; // rax
  signed __int64 v17; // rcx
  hkpWorldRayCaster v18; // [rsp+30h] [rbp-78h]

  v3 = this;
  v4 = collector;
  v5 = input;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtworldCastRayCollector";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = v3->m_collisionFilter;
  v12 = v3->m_broadPhase;
  v18.vfptr = (hkpBroadPhaseCastCollectorVtbl *)&hkpWorldRayCaster::`vftable;
  v18.m_shapeInput.m_filterInfo = 0;
  v18.m_shapeInput.m_rayShapeCollectionFilter = 0i64;
  v18.m_shapeInput.m_collidable = 0i64;
  v18.m_shapeInput.m_userData = 0i64;
  hkpWorldRayCaster::castRay(&v18, v12, v5, v11, 0i64, v4);
  v18.vfptr = (hkpBroadPhaseCastCollectorVtbl *)&hkpBroadPhaseCastCollector::`vftable;
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = (_QWORD *)v13[1];
  v15 = v13;
  if ( (unsigned __int64)v14 < v13[3] )
  {
    *v14 = "Et";
    v16 = __rdtsc();
    v17 = (signed __int64)(v14 + 2);
    *(_DWORD *)(v17 - 8) = v16;
    v15[1] = v17;
  }
}

// File Line: 3576
// RVA: 0xD5B390
void __fastcall hkpWorld::castRay(hkpWorld *this, hkpWorldRayCastInput *input, hkpWorldRayCastOutput *output)
{
  hkpWorld *v3; // rbx
  hkpWorldRayCastOutput *v4; // rdi
  hkpWorldRayCastInput *v5; // rsi
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  hkpCollisionFilter *v11; // r9
  hkpBroadPhase *v12; // rdx
  _QWORD *v13; // rax
  _QWORD *v14; // rcx
  _QWORD *v15; // r8
  unsigned __int64 v16; // rax
  signed __int64 v17; // rcx
  hkpSimpleWorldRayCaster v18; // [rsp+30h] [rbp-68h]

  v3 = this;
  v4 = output;
  v5 = input;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtworldCastRay";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = v3->m_collisionFilter;
  v12 = v3->m_broadPhase;
  v18.vfptr = (hkpBroadPhaseCastCollectorVtbl *)&hkpSimpleWorldRayCaster::`vftable;
  v18.m_shapeInput.m_filterInfo = 0;
  v18.m_shapeInput.m_rayShapeCollectionFilter = 0i64;
  v18.m_shapeInput.m_collidable = 0i64;
  v18.m_shapeInput.m_userData = 0i64;
  hkpSimpleWorldRayCaster::castRay(&v18, v12, v5, v11, 0i64, v4);
  v18.vfptr = (hkpBroadPhaseCastCollectorVtbl *)&hkpBroadPhaseCastCollector::`vftable;
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = (_QWORD *)v13[1];
  v15 = v13;
  if ( (unsigned __int64)v14 < v13[3] )
  {
    *v14 = "Et";
    v16 = __rdtsc();
    v17 = (signed __int64)(v14 + 2);
    *(_DWORD *)(v17 - 8) = v16;
    v15[1] = v17;
  }
}

// File Line: 3584
// RVA: 0xD5B5A0
void __fastcall hkpWorld::castRayMt(hkpWorld *this, hkpWorldRayCastCommand *commandArray, int numCommands, hkJobQueue *jobQueue, hkJobThreadPool *jobThreadPool, hkSemaphore *semaphore, int numCommandsPerJob)
{
  hkpWorld *v7; // rdi
  hkJobQueue *v8; // rsi
  int v9; // er14
  hkpWorldRayCastCommand *v10; // rbx
  _QWORD **v11; // rax
  __int64 v12; // rax
  hkpProcessCollisionInput *v13; // rcx
  hkpCollisionQueryJobHeader *v14; // r15
  hkpBroadPhase *v15; // rax
  int v16; // eax
  int i; // ecx
  int v18; // eax
  __int128 v19; // xmm0
  _QWORD **v20; // rax
  hkpWorldRayCastJob v21; // [rsp+20h] [rbp-91h]
  hkJob job; // [rsp+80h] [rbp-31h]
  __int128 v23; // [rsp+90h] [rbp-21h]
  __int128 v24; // [rsp+A0h] [rbp-11h]
  __int128 v25; // [rsp+B0h] [rbp-1h]
  __int128 v26; // [rsp+C0h] [rbp+Fh]
  __int128 v27; // [rsp+D0h] [rbp+1Fh]

  v7 = this;
  v8 = jobQueue;
  v9 = numCommands;
  v10 = commandArray;
  v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(v11[11], 16i64);
  v13 = v7->m_collisionInput;
  v14 = (hkpCollisionQueryJobHeader *)v12;
  v21.m_size = 96;
  *(_WORD *)&v21.m_jobSubType = 769;
  v21.m_threadAffinity = -1;
  v15 = v7->m_broadPhase;
  v21.m_jobDoneFlag = 0i64;
  v21.m_jobSpuType.m_storage = 1;
  v21.m_collisionInput = v13;
  v21.m_sharedJobHeaderOnPpu = v14;
  v21.m_broadphase = v15;
  v21.m_numCommandsPerTask = 64;
  v21.m_semaphore = semaphore;
  v21.m_commandArray = v10;
  v21.m_numCommands = v9;
  if ( v9 )
    v16 = (v9 - 1) / 64 + 1;
  else
    v16 = 1;
  v14->m_openJobs = v16;
  v21.m_bundleCommandArray = 0i64;
  v21.m_numBundleCommands = 0;
  hkpWorldRayCastJob::setRunsOnSpuOrPpu(&v21);
  for ( i = v21.m_numCommands; v21.m_numCommands > 0; i = v21.m_numCommands )
  {
    v18 = numCommandsPerJob;
    if ( i < numCommandsPerJob )
      v18 = i;
    job = v21.0;
    v25 = *(_OWORD *)&v21.m_numCommandsPerTask;
    v24 = *(_OWORD *)&v21.m_jobDoneFlag;
    v19 = *(_OWORD *)&v21.m_numCommands;
    v23 = *(_OWORD *)&v21.m_semaphore;
    v21.m_numCommands = i - numCommandsPerJob;
    v26 = v19;
    LODWORD(v26) = v18;
    v21.m_commandArray = (hkpWorldRayCastCommand *)(80i64 * numCommandsPerJob
                                                  + *(unsigned __int128 *)&_mm_srli_si128(
                                                                             *(__m128i *)&v21.m_numCommandsPerTask,
                                                                             8));
    v27 = *(_OWORD *)&v21.m_numBundleCommands;
    hkJobQueue::addJob(v8, &job, JOB_LOW_PRIORITY);
  }
  ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, signed __int64))jobThreadPool->vfptr[5].__first_virtual_table_function__)(
    jobThreadPool,
    v8,
    20i64);
  hkJobQueue::processAllJobs(v8, 1);
  ((void (__fastcall *)(hkJobThreadPool *))jobThreadPool->vfptr[2].__vecDelDtor)(jobThreadPool);
  hkSemaphore::acquire(semaphore);
  v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkpCollisionQueryJobHeader *, signed __int64))(*v20[11] + 16i64))(
    v20[11],
    v14,
    16i64);
}

// File Line: 3608
// RVA: 0xD5BA80
void __fastcall hkpWorld::getClosestPoints(hkpWorld *this, hkpCollidable *collA, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpWorld *v4; // rbp
  hkpCollidable *v5; // r14
  hkpCdPointCollector *v6; // r13
  hkpCollisionInput *v7; // r15
  float v8; // xmm2_4
  _QWORD *v9; // r8
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rax
  hkpBroadPhase *v12; // rcx
  _QWORD *v13; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  signed __int64 v16; // rcx
  int v17; // esi
  __int64 v18; // r12
  __int64 v19; // rdi
  hkpCollidable *v20; // rbx
  _QWORD *v21; // rax
  _QWORD *v22; // rcx
  _QWORD *v23; // r8
  unsigned __int64 v24; // rax
  signed __int64 v25; // rcx
  char v26; // [rsp+20h] [rbp-858h]
  char *v27; // [rsp+40h] [rbp-838h]
  int v28; // [rsp+48h] [rbp-830h]
  int v29; // [rsp+4Ch] [rbp-82Ch]
  char v30; // [rsp+50h] [rbp-828h]
  char v31; // [rsp+880h] [rbp+8h]

  v4 = this;
  v5 = collA;
  v6 = collector;
  v7 = input;
  v8 = input->m_tolerance.m_storage - (float)(this->m_collisionInput->m_tolerance.m_storage * 0.5);
  ((void (__fastcall *)(hkpShape *, const void *, hkpCollisionInput *, char *))collA->m_shape->vfptr[2].__vecDelDtor)(
    collA->m_shape,
    collA->m_motion,
    input,
    &v26);
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = v9[1];
  if ( v10 < v9[3] )
  {
    *(_QWORD *)v10 = "LthkpWorld::getClosestPoints";
    *(_QWORD *)(v10 + 16) = "StBroadPhase";
    v11 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v11;
    v9[1] = v10 + 24;
  }
  v12 = v4->m_broadPhase;
  v28 = 0;
  v27 = &v30;
  v29 = -2147483520;
  ((void (__fastcall *)(hkpBroadPhase *, char *, char **))v12->vfptr[9].__vecDelDtor)(v12, &v26, &v27);
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = (_QWORD *)v13[1];
  if ( (unsigned __int64)v14 < v13[3] )
  {
    *v14 = "StNarrowPhase";
    v15 = __rdtsc();
    v16 = (signed __int64)(v14 + 2);
    *(_DWORD *)(v16 - 8) = v15;
    v13[1] = v16;
  }
  v17 = v28 - 1;
  v18 = (unsigned __int8)v5->m_shape->m_type.m_storage;
  if ( v28 - 1 >= 0 )
  {
    v19 = (__int64)(v27 + 8);
    do
    {
      v20 = (hkpCollidable *)(*(_QWORD *)v19 + *(char *)(*(_QWORD *)v19 + 5i64));
      if ( v5 != v20
        && *(_BYTE *)v4->m_collisionFilter->vfptr->isCollisionEnabled(
                       (hkpCollidableCollidableFilter *)&v4->m_collisionFilter->vfptr,
                       (hkBool *)&v31,
                       v5,
                       (hkpCollidable *)(*(_QWORD *)v19 + *(char *)(*(_QWORD *)v19 + 5i64)))
        && v20->m_shape )
      {
        (*((void (__fastcall **)(hkpCollidable *, hkpCollidable *, hkpCollisionInput *, hkpCdPointCollector *))&v7->m_dispatcher.m_storage->vfptr
         + 5
         * ((unsigned __int8)v7->m_dispatcher.m_storage->m_agent2Types[v18][(unsigned __int8)v20->m_shape->m_type.m_storage]
          + 79i64)))(
          v5,
          v20,
          v7,
          v6);
      }
      v19 += 16i64;
      --v17;
    }
    while ( v17 >= 0 );
  }
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  v23 = v21;
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "lt";
    v24 = __rdtsc();
    v25 = (signed __int64)(v22 + 2);
    *(_DWORD *)(v25 - 8) = v24;
    v23[1] = v25;
  }
  v28 = 0;
  if ( v29 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v27,
      16 * v29);
}

// File Line: 3657
// RVA: 0xD5BCF0
void __fastcall hkpWorld::getClosestPointsMt(hkpWorld *this, hkpWorldGetClosestPointsCommand *commandArray, int numCommands, hkJobQueue *jobQueue, hkJobThreadPool *jobThreadPool, hkSemaphore *semaphore, int numCommandsPerJob)
{
  hkpWorld *v7; // rbx
  hkJobQueue *v8; // rsi
  __int64 v9; // r14
  hkpWorldGetClosestPointsCommand *v10; // rdi
  _QWORD **v11; // rax
  __int64 v12; // rax
  hkpProcessCollisionInput *v13; // rdx
  hkpBroadPhase *v14; // r8
  float v15; // xmm0_4
  hkpCollisionQueryJobHeader *v16; // r12
  __int64 v17; // rcx
  unsigned int *v18; // rax
  int i; // ecx
  int v20; // eax
  __int128 v21; // xmm0
  _QWORD **v22; // rax
  hkpWorldGetClosestPointsJob v23; // [rsp+20h] [rbp-71h]
  hkJob job; // [rsp+70h] [rbp-21h]
  __int128 v25; // [rsp+80h] [rbp-11h]
  __int128 v26; // [rsp+90h] [rbp-1h]
  __int128 v27; // [rsp+A0h] [rbp+Fh]
  __int128 v28; // [rsp+B0h] [rbp+1Fh]

  v7 = this;
  v8 = jobQueue;
  v9 = numCommands;
  v10 = commandArray;
  v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(v11[11], 16i64);
  v13 = v7->m_collisionInput;
  v14 = v7->m_broadPhase;
  v15 = v13->m_tolerance.m_storage;
  v16 = (hkpCollisionQueryJobHeader *)v12;
  v23.m_size = 80;
  *(_WORD *)&v23.m_jobSubType = 514;
  v23.m_jobSpuType.m_storage = 2;
  v17 = v9;
  v23.m_threadAffinity = -1;
  v23.m_jobDoneFlag = 0i64;
  if ( (signed int)v9 > 0 )
  {
    v18 = &v10->m_numResultsOut;
    do
    {
      *v18 = 0;
      v18 += 6;
      --v17;
    }
    while ( v17 );
  }
  v23.m_collisionInput = v13;
  v23.m_tolerance = v15;
  v23.m_sharedJobHeaderOnPpu = v16;
  v23.m_numCommandsPerTask = 64;
  v23.m_broadphase = v14;
  v23.m_semaphore = semaphore;
  v23.m_commandArray = v10;
  v23.m_numCommands = v9;
  v16->m_openJobs = ((signed int)v9 - 1) / 64 + 1;
  hkpWorldGetClosestPointsJob::setRunsOnSpuOrPpu(&v23);
  for ( i = v23.m_numCommands; v23.m_numCommands > 0; i = v23.m_numCommands )
  {
    v20 = numCommandsPerJob;
    if ( i < numCommandsPerJob )
      v20 = i;
    job = v23.0;
    v25 = *(_OWORD *)&v23.m_semaphore;
    v26 = *(_OWORD *)&v23.m_collisionInput;
    v21 = *(_OWORD *)&v23.m_commandArray;
    v23.m_commandArray += numCommandsPerJob;
    v23.m_numCommands = i - numCommandsPerJob;
    v28 = v21;
    v27 = *(_OWORD *)&v23.m_broadphase;
    DWORD2(v28) = v20;
    hkJobQueue::addJob(v8, &job, JOB_LOW_PRIORITY);
  }
  ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, signed __int64))jobThreadPool->vfptr[5].__first_virtual_table_function__)(
    jobThreadPool,
    v8,
    20i64);
  hkJobQueue::processAllJobs(v8, 1);
  ((void (__fastcall *)(hkJobThreadPool *))jobThreadPool->vfptr[2].__vecDelDtor)(jobThreadPool);
  hkSemaphore::acquire(semaphore);
  v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkpCollisionQueryJobHeader *, signed __int64))(*v22[11] + 16i64))(
    v22[11],
    v16,
    16i64);
}

// File Line: 3681
// RVA: 0xD5BEC0
void __fastcall hkpWorld::getPenetrations(hkpWorld *this, hkpCollidable *collA, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpProcessCollisionInput *v4; // rax
  hkpWorld *v5; // r13
  hkpShape *v6; // rcx
  hkBaseObjectVtbl *v7; // rax
  hkpCollidable *v8; // r14
  const void *v9; // rdx
  hkpCdBodyPairCollector *v10; // rbp
  hkpCollisionInput *v11; // r15
  _QWORD *v12; // r8
  unsigned __int64 v13; // rcx
  unsigned __int64 v14; // rax
  hkpBroadPhase *v15; // rcx
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx
  int v20; // esi
  __int64 v21; // r12
  __int64 v22; // rdi
  hkpCollidable *v23; // rbx
  _QWORD *v24; // rax
  _QWORD *v25; // rcx
  _QWORD *v26; // r8
  unsigned __int64 v27; // rax
  signed __int64 v28; // rcx
  char v29; // [rsp+20h] [rbp-868h]
  char *v30; // [rsp+40h] [rbp-848h]
  int v31; // [rsp+48h] [rbp-840h]
  int v32; // [rsp+4Ch] [rbp-83Ch]
  char v33; // [rsp+50h] [rbp-838h]
  int v34; // [rsp+890h] [rbp+8h]
  float v35; // [rsp+898h] [rbp+10h]

  v4 = this->m_collisionInput;
  v5 = this;
  v6 = collA->m_shape;
  v35 = input->m_tolerance.m_storage - (float)(v4->m_tolerance.m_storage * 0.5);
  v7 = v6->vfptr;
  v8 = collA;
  v9 = collA->m_motion;
  v34 = 0;
  v10 = collector;
  v11 = input;
  ((void (__fastcall *)(hkpShape *, const void *, hkpCollisionInput *, char *))v7[2].__vecDelDtor)(v6, v9, input, &v29);
  v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = v12[1];
  if ( v13 < v12[3] )
  {
    *(_QWORD *)v13 = "LthkpWorld::getPenetrations";
    *(_QWORD *)(v13 + 16) = "StBroadPhase";
    v14 = __rdtsc();
    *(_DWORD *)(v13 + 8) = v14;
    v12[1] = v13 + 24;
  }
  v15 = v5->m_broadPhase;
  v31 = 0;
  v30 = &v33;
  v32 = -2147483520;
  ((void (__fastcall *)(hkpBroadPhase *, char *, char **))v15->vfptr[9].__vecDelDtor)(v15, &v29, &v30);
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "StNarrowPhase";
    v18 = __rdtsc();
    v19 = (signed __int64)(v17 + 2);
    *(_DWORD *)(v19 - 8) = v18;
    v16[1] = v19;
  }
  v20 = v31 - 1;
  v21 = (unsigned __int8)v8->m_shape->m_type.m_storage;
  if ( v31 - 1 >= 0 )
  {
    v22 = (__int64)(v30 + 8);
    do
    {
      v23 = (hkpCollidable *)(*(_QWORD *)v22 + *(char *)(*(_QWORD *)v22 + 5i64));
      if ( v8 != v23 )
      {
        if ( *(_BYTE *)v5->m_collisionFilter->vfptr->isCollisionEnabled(
                         (hkpCollidableCollidableFilter *)&v5->m_collisionFilter->vfptr,
                         (hkBool *)&v34,
                         v8,
                         (hkpCollidable *)(*(_QWORD *)v22 + *(char *)(*(_QWORD *)v22 + 5i64))) )
        {
          if ( v23->m_shape )
          {
            v11->m_dispatcher.m_storage->m_agent2Func[(unsigned __int8)v11->m_dispatcher.m_storage->m_agent2Types[v21][(unsigned __int8)v23->m_shape->m_type.m_storage]].m_getPenetrationsFunc(
              (hkpCdBody *)&v8->m_shape,
              (hkpCdBody *)&v23->m_shape,
              v11,
              v10);
            if ( v10->m_earlyOut.m_bool )
              break;
          }
        }
      }
      v22 += 16i64;
      --v20;
    }
    while ( v20 >= 0 );
  }
  v24 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v25 = (_QWORD *)v24[1];
  v26 = v24;
  if ( (unsigned __int64)v25 < v24[3] )
  {
    *v25 = "lt";
    v27 = __rdtsc();
    v28 = (signed __int64)(v25 + 2);
    *(_DWORD *)(v28 - 8) = v27;
    v26[1] = v28;
  }
  v31 = 0;
  if ( v32 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v30,
      16 * v32);
}

// File Line: 3732
// RVA: 0xD5B780
void __fastcall hkpWorld::linearCast(hkpWorld *this, hkpCollidable *collA, hkpLinearCastInput *input, hkpCdPointCollector *castCollector, hkpCdPointCollector *startPointCollector)
{
  hkpWorld *v5; // rbx
  hkpCdPointCollector *v6; // rdi
  hkpLinearCastInput *v7; // rsi
  hkpCollidable *v8; // rbp
  _QWORD *v9; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  hkpCollisionFilter *v14; // rax
  hkpCollidableCollidableFilter *filter; // rdx
  _QWORD *v16; // rax
  _QWORD *v17; // rcx
  _QWORD *v18; // r8
  unsigned __int64 v19; // rax
  signed __int64 v20; // rcx
  hkpWorldLinearCaster v21; // [rsp+50h] [rbp-C8h]

  v5 = this;
  v6 = castCollector;
  v7 = input;
  v8 = collA;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  v11 = v9;
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtworldLinCast";
    v12 = __rdtsc();
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  v21.vfptr = (hkpBroadPhaseCastCollectorVtbl *)&hkpWorldLinearCaster::`vftable;
  v14 = v5->m_collisionFilter;
  v21.m_shapeInput.m_maxExtraPenetration = FLOAT_1_1920929eN7;
  filter = (hkpCollidableCollidableFilter *)&v14->vfptr;
  v21.m_shapeInput.m_forceAcceptContactPoints.m_storage = 0;
  if ( !v14 )
    filter = 0i64;
  hkpWorldLinearCaster::linearCast(
    &v21,
    v5->m_broadPhase,
    v8,
    v7,
    filter,
    (hkpCollisionInput *)&v5->m_collisionInput->m_dispatcher,
    v5->m_collisionInput->m_config,
    0i64,
    v6,
    startPointCollector);
  v21.vfptr = (hkpBroadPhaseCastCollectorVtbl *)&hkpBroadPhaseCastCollector::`vftable;
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  v18 = v16;
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "Et";
    v19 = __rdtsc();
    v20 = (signed __int64)(v17 + 2);
    *(_DWORD *)(v20 - 8) = v19;
    v18[1] = v20;
  }
}

// File Line: 3742
// RVA: 0xD5B8D0
void __fastcall hkpWorld::linearCastMt(hkpWorld *this, hkpWorldLinearCastCommand *commandArray, int numCommands, hkJobQueue *jobQueue, hkJobThreadPool *jobThreadPool, hkSemaphore *semaphore, int numCommandsPerJob)
{
  hkpWorld *v7; // rdi
  hkJobQueue *v8; // r14
  int v9; // esi
  hkpWorldLinearCastCommand *v10; // rbx
  _QWORD **v11; // rax
  hkpCollisionQueryJobHeader *v12; // r15
  hkpBroadPhase *v13; // rax
  int i; // ecx
  int v15; // eax
  __int128 v16; // xmm0
  _QWORD **v17; // rax
  hkpWorldLinearCastJob v18; // [rsp+20h] [rbp-71h]
  hkJob job; // [rsp+70h] [rbp-21h]
  __int128 v20; // [rsp+80h] [rbp-11h]
  __int128 v21; // [rsp+90h] [rbp-1h]
  __int128 v22; // [rsp+A0h] [rbp+Fh]
  __int128 v23; // [rsp+B0h] [rbp+1Fh]

  v7 = this;
  v8 = jobQueue;
  v9 = numCommands;
  v10 = commandArray;
  v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkpCollisionQueryJobHeader *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(
                                        v11[11],
                                        16i64);
  v18.m_collisionInput = v7->m_collisionInput;
  v18.m_size = 80;
  *(_WORD *)&v18.m_jobSubType = 516;
  v18.m_threadAffinity = -1;
  v13 = v7->m_broadPhase;
  v18.m_jobSpuType.m_storage = 2;
  v18.m_broadphase = v13;
  v18.m_jobDoneFlag = 0i64;
  v18.m_sharedJobHeaderOnPpu = v12;
  v18.m_numCommandsPerTask = 64;
  v18.m_semaphore = semaphore;
  v18.m_commandArray = v10;
  v18.m_numCommands = v9;
  v12->m_openJobs = (v9 - 1) / 64 + 1;
  hkpWorldLinearCastJob::setRunsOnSpuOrPpu(&v18);
  for ( i = v18.m_numCommands; v18.m_numCommands > 0; i = v18.m_numCommands )
  {
    v15 = numCommandsPerJob;
    if ( i < numCommandsPerJob )
      v15 = i;
    job = v18.0;
    v20 = *(_OWORD *)&v18.m_semaphore;
    v21 = *(_OWORD *)&v18.m_collisionInput;
    v16 = *(_OWORD *)&v18.m_numCommands;
    v18.m_numCommands = i - numCommandsPerJob;
    v22 = *(_OWORD *)&v18.m_numCommandsPerTask;
    v23 = v16;
    LODWORD(v23) = v15;
    v18.m_commandArray = (hkpWorldLinearCastCommand *)(((signed __int64)numCommandsPerJob << 6)
                                                     + *(unsigned __int128 *)&_mm_srli_si128(
                                                                                *(__m128i *)&v18.m_numCommandsPerTask,
                                                                                8));
    hkJobQueue::addJob(v8, &job, JOB_LOW_PRIORITY);
  }
  ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, signed __int64))jobThreadPool->vfptr[5].__first_virtual_table_function__)(
    jobThreadPool,
    v8,
    20i64);
  hkJobQueue::processAllJobs(v8, 1);
  ((void (__fastcall *)(hkJobThreadPool *))jobThreadPool->vfptr[2].__vecDelDtor)(jobThreadPool);
  hkSemaphore::acquire(semaphore);
  v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkpCollisionQueryJobHeader *, signed __int64))(*v17[11] + 16i64))(
    v17[11],
    v12,
    16i64);
}

// File Line: 3772
// RVA: 0xD5DE10
hkBool *__fastcall enumerateAllInactiveEntitiesInWorld(hkBool *result, hkpWorld *world, hkpPhysicsSystem *sys)
{
  hkpSimulationIsland *v3; // rdi
  bool v4; // bl
  hkpWorld *v5; // r13
  hkBool *v6; // r12
  hkpPhysicsSystem *v7; // r15
  __int64 v8; // rbx
  int i; // esi
  hkpSimulationIsland **v10; // r14
  hkpSimulationIsland *v11; // rdi
  int v12; // ebp
  __int64 v13; // rsi
  hkBool *v14; // rax

  v3 = world->m_fixedIsland;
  v4 = 0;
  v5 = world;
  v6 = result;
  v7 = sys;
  if ( v3 )
  {
    v8 = 0i64;
    for ( i = 0; i < v3->m_entities.m_size; ++v8 )
    {
      if ( v8 || (*v3->m_entities.m_data)->m_collidable.m_shape )
        hkpPhysicsSystem::addRigidBody(v7, (hkpRigidBody *)v3->m_entities.m_data[v8]);
      ++i;
    }
    v4 = v3->m_entities.m_size > 0;
  }
  v10 = v5->m_inactiveSimulationIslands.m_data;
  if ( v10 != &v10[v5->m_inactiveSimulationIslands.m_size] )
  {
    do
    {
      v11 = *v10;
      v12 = 0;
      if ( (*v10)->m_entities.m_size > 0 )
      {
        v13 = 0i64;
        do
        {
          hkpPhysicsSystem::addRigidBody(v7, (hkpRigidBody *)v11->m_entities.m_data[v13]);
          ++v12;
          ++v13;
        }
        while ( v12 < v11->m_entities.m_size );
      }
      ++v10;
    }
    while ( v10 != &v5->m_inactiveSimulationIslands.m_data[v5->m_inactiveSimulationIslands.m_size] );
  }
  if ( v5->m_inactiveSimulationIslands.m_size > 0 || v4 )
  {
    v6->m_bool = 1;
    v14 = v6;
  }
  else
  {
    v6->m_bool = 0;
    v14 = v6;
  }
  return v14;
}

// File Line: 3803
// RVA: 0xD5DF30
hkBool *__fastcall enumerateAllActiveEntitiesInWorld(hkBool *result, hkpWorld *world, hkpPhysicsSystem *sys)
{
  hkpSimulationIsland **v3; // r14
  hkpPhysicsSystem *v4; // r15
  hkpWorld *v5; // rbp
  hkBool *v6; // r12
  hkpSimulationIsland *v7; // rbx
  int v8; // esi
  __int64 v9; // rdi

  v3 = world->m_activeSimulationIslands.m_data;
  v4 = sys;
  v5 = world;
  v6 = result;
  if ( v3 != &v3[world->m_activeSimulationIslands.m_size] )
  {
    do
    {
      v7 = *v3;
      v8 = 0;
      if ( (*v3)->m_entities.m_size > 0 )
      {
        v9 = 0i64;
        do
        {
          hkpPhysicsSystem::addRigidBody(v4, (hkpRigidBody *)v7->m_entities.m_data[v9]);
          ++v8;
          ++v9;
        }
        while ( v8 < v7->m_entities.m_size );
      }
      ++v3;
    }
    while ( v3 != &v5->m_activeSimulationIslands.m_data[v5->m_activeSimulationIslands.m_size] );
  }
  v6->m_bool = v5->m_activeSimulationIslands.m_size > 0;
  return v6;
}

// File Line: 3819
// RVA: 0xD5DFF0
void __fastcall enumerateAllEntitiesInWorld(hkpWorld *world, hkpPhysicsSystem *sys)
{
  hkpPhysicsSystem *v2; // rdi
  hkpWorld *v3; // rbx
  hkBool result; // [rsp+38h] [rbp+10h]

  v2 = sys;
  v3 = world;
  enumerateAllInactiveEntitiesInWorld(&result, world, sys);
  v2->m_active = (hkBool)enumerateAllActiveEntitiesInWorld(&result, v3, v2)->m_bool;
}

// File Line: 3825
// RVA: 0xD5E040
void __fastcall enumerateAllConstraintsInIsland(hkpSimulationIsland *island, hkpPhysicsSystem *sys)
{
  hkpPhysicsSystem *v2; // r15
  hkpSimulationIsland *v3; // r13
  int v4; // ebp
  __int64 v5; // r14
  signed int v6; // edi
  hkpEntity *v7; // rsi
  __int64 v8; // rbx
  hkConstraintInternal *v9; // rdx
  hkpConstraintAtom *i; // rax

  v2 = sys;
  v3 = island;
  v4 = 0;
  if ( island->m_entities.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = 0;
      v7 = v3->m_entities.m_data[v5];
      if ( v7->m_constraintsMaster.m_size > 0u )
      {
        v8 = 0i64;
        do
        {
          v9 = v7->m_constraintsMaster.m_data;
          for ( i = v9[v8].m_atoms; i->m_type.m_storage >= 0x1Eu; i = *(hkpConstraintAtom **)&i[12].m_type.m_storage )
            ;
          if ( i->m_type.m_storage != 29 )
            hkpPhysicsSystem::addConstraint(v2, v9[v8].m_constraint);
          ++v6;
          ++v8;
        }
        while ( v6 < v7->m_constraintsMaster.m_size );
      }
      ++v4;
      ++v5;
    }
    while ( v4 < v3->m_entities.m_size );
  }
}

// File Line: 3846
// RVA: 0xD5E120
void __fastcall enumerateAllConstraintsInWorld(hkpWorld *world, hkpPhysicsSystem *sys)
{
  hkpSimulationIsland **v2; // rbx
  hkpPhysicsSystem *v3; // rsi
  hkpWorld *v4; // rdi
  hkpSimulationIsland **v5; // rbx

  v2 = world->m_activeSimulationIslands.m_data;
  v3 = sys;
  v4 = world;
  if ( v2 != &v2[world->m_activeSimulationIslands.m_size] )
  {
    do
    {
      enumerateAllConstraintsInIsland(*v2, v3);
      ++v2;
    }
    while ( v2 != &v4->m_activeSimulationIslands.m_data[v4->m_activeSimulationIslands.m_size] );
  }
  v5 = v4->m_inactiveSimulationIslands.m_data;
  if ( v5 != &v5[v4->m_inactiveSimulationIslands.m_size] )
  {
    do
    {
      enumerateAllConstraintsInIsland(*v5, v3);
      ++v5;
    }
    while ( v5 != &v4->m_inactiveSimulationIslands.m_data[v4->m_inactiveSimulationIslands.m_size] );
  }
}

// File Line: 3864
// RVA: 0xD5E1C0
void __fastcall enumerateAllActionsInWorld(hkpWorld *world, hkpPhysicsSystem *sys)
{
  hkpSimulationIsland **v2; // r14
  hkpPhysicsSystem *v3; // rbp
  hkpWorld *v4; // r15
  hkpSimulationIsland *v5; // rbx
  int v6; // esi
  __int64 v7; // rdi
  hkpSimulationIsland **v8; // r14
  hkpSimulationIsland *v9; // rbx
  int v10; // esi
  __int64 v11; // rdi

  v2 = world->m_activeSimulationIslands.m_data;
  v3 = sys;
  v4 = world;
  if ( v2 != &v2[world->m_activeSimulationIslands.m_size] )
  {
    do
    {
      v5 = *v2;
      v6 = 0;
      if ( (*v2)->m_actions.m_size > 0 )
      {
        v7 = 0i64;
        do
        {
          hkpPhysicsSystem::addAction(v3, v5->m_actions.m_data[v7]);
          ++v6;
          ++v7;
        }
        while ( v6 < v5->m_actions.m_size );
      }
      ++v2;
    }
    while ( v2 != &v4->m_activeSimulationIslands.m_data[v4->m_activeSimulationIslands.m_size] );
  }
  v8 = v4->m_inactiveSimulationIslands.m_data;
  if ( v8 != &v8[v4->m_inactiveSimulationIslands.m_size] )
  {
    do
    {
      v9 = *v8;
      v10 = 0;
      if ( (*v8)->m_actions.m_size > 0 )
      {
        v11 = 0i64;
        do
        {
          hkpPhysicsSystem::addAction(v3, v9->m_actions.m_data[v11]);
          ++v10;
          ++v11;
        }
        while ( v10 < v9->m_actions.m_size );
      }
      ++v8;
    }
    while ( v8 != &v4->m_inactiveSimulationIslands.m_data[v4->m_inactiveSimulationIslands.m_size] );
  }
}

// File Line: 3890
// RVA: 0xD5E2A0
void __fastcall enumerateAllPhantomsInWorld(hkpWorld *world, hkpPhysicsSystem *sys)
{
  hkpPhysicsSystem *v2; // rbp
  hkpWorld *v3; // rsi
  int v4; // ebx
  hkpBroadPhaseBorder *v5; // rdi
  __int64 v6; // r14
  hkpPhantom *v7; // rdx
  __int64 v8; // rdi

  v2 = sys;
  v3 = world;
  v4 = 0;
  v5 = hkpWorld::getBroadPhaseBorder(world);
  if ( v5 )
  {
    if ( v3->m_phantoms.m_size > 0 )
    {
      v6 = 0i64;
      do
      {
        v7 = v3->m_phantoms.m_data[v6];
        if ( v7 != v5->m_phantoms[0]
          && v7 != v5->m_phantoms[1]
          && v7 != v5->m_phantoms[2]
          && v7 != v5->m_phantoms[3]
          && v7 != v5->m_phantoms[4]
          && v7 != v5->m_phantoms[5] )
        {
          hkpPhysicsSystem::addPhantom(v2, v7);
        }
        ++v4;
        ++v6;
      }
      while ( v4 < v3->m_phantoms.m_size );
    }
  }
  else if ( v3->m_phantoms.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      hkpPhysicsSystem::addPhantom(v2, v3->m_phantoms.m_data[v8]);
      ++v4;
      ++v8;
    }
    while ( v4 < v3->m_phantoms.m_size );
  }
}

// File Line: 3919
// RVA: 0xD5C970
hkpPhysicsSystem *__fastcall hkpWorld::getWorldAsOneSystem(hkpWorld *this)
{
  hkpWorld *v1; // rdi
  _QWORD **v2; // rax
  hkpPhysicsSystem *v3; // rax
  hkpPhysicsSystem *v4; // rax
  hkpPhysicsSystem *v5; // rbx

  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 104i64);
  if ( v3 )
  {
    hkpPhysicsSystem::hkpPhysicsSystem(v3);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  enumerateAllEntitiesInWorld(v1, v5);
  enumerateAllPhantomsInWorld(v1, v5);
  enumerateAllConstraintsInWorld(v1, v5);
  enumerateAllActionsInWorld(v1, v5);
  return v5;
}

// File Line: 3937
// RVA: 0xD5C9F0
void __fastcall hkpWorld::getWorldAsSystems(hkpWorld *this, hkArray<hkpPhysicsSystem *,hkContainerHeapAllocator> *systemsInOut)
{
  hkpWorld *v2; // rsi
  hkArray<hkpPhysicsSystem *,hkContainerHeapAllocator> *v3; // rbx
  _QWORD **v4; // rax
  hkpPhysicsSystem *v5; // rax
  hkpPhysicsSystem *v6; // rax
  hkpPhysicsSystem *v7; // rdi
  _QWORD **v8; // rax
  hkpPhysicsSystem *v9; // rax
  hkpPhysicsSystem *v10; // rax
  hkBool result; // [rsp+38h] [rbp+10h]

  v2 = this;
  v3 = systemsInOut;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 104i64);
  if ( v5 )
  {
    hkpPhysicsSystem::hkpPhysicsSystem(v5);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  if ( enumerateAllInactiveEntitiesInWorld(&result, v2, v7)->m_bool )
  {
    v7->m_active.m_bool = 0;
    if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 8);
    v3->m_data[v3->m_size++] = v7;
  }
  else if ( v7 )
  {
    goto LABEL_12;
  }
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 104i64);
  if ( v9 )
  {
    hkpPhysicsSystem::hkpPhysicsSystem(v9);
    v7 = v10;
  }
  else
  {
    v7 = 0i64;
  }
LABEL_12:
  if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 8);
  v3->m_data[v3->m_size++] = v7;
  enumerateAllActiveEntitiesInWorld(&result, v2, v7);
  enumerateAllPhantomsInWorld(v2, v7);
  enumerateAllConstraintsInWorld(v2, v7);
  enumerateAllActionsInWorld(v2, v7);
}

// File Line: 3972
// RVA: 0xD5D9D0
void __fastcall hkpWorld::internal_executePendingOperations(hkpWorld *this)
{
  this->m_pendingOperationsCount = 0;
  hkpWorldOperationQueue::executeAllPending(this->m_pendingOperations);
}

// File Line: 3981
// RVA: 0xD5D9F0
void __fastcall hkpWorld::internal_executePendingBodyOperations(hkpWorld *this)
{
  this->m_pendingBodyOperationsCount = 0;
  hkpWorldOperationQueue::executeAllPendingBodyOperations(this->m_pendingOperations);
}

// File Line: 3990
// RVA: 0xD5D940
void __fastcall hkpWorld::checkConstraintsViolated(hkpWorld *this)
{
  hkpWorld *v1; // rdi
  signed int v2; // edx
  __int64 v3; // rbx
  __int64 v4; // rsi

  v1 = this;
  v2 = this->m_violatedConstraintArray->m_nextFreeElement;
  if ( v2 >= 128 )
    v2 = 128;
  v3 = 0i64;
  v4 = v2;
  if ( v2 <= 0 )
  {
    this->m_violatedConstraintArray->m_nextFreeElement = 0;
  }
  else
  {
    do
      hkpWorldCallbackUtil::fireConstraintViolated(v1, v1->m_violatedConstraintArray->m_constraints[v3++]);
    while ( v3 < v4 );
    v1->m_violatedConstraintArray->m_nextFreeElement = 0;
  }
}

// File Line: 4006
// RVA: 0xD5D8B0
void __fastcall hkpWorld::queueOperation(hkpWorld *this, hkWorldOperation::BaseOperation *operation)
{
  hkpWorldOperationQueue::queueOperation(this->m_pendingOperations, operation);
}

// File Line: 4011
// RVA: 0xD5D920
void __fastcall hkpWorld::addBodyOperation(hkpWorld *this, hkpRigidBody *breakingBody, hkpBodyOperation *operation, int priority, int hint)
{
  hkpWorldOperationQueue::queueBodyOperation(
    this->m_pendingOperations,
    (hkpEntity *)&breakingBody->vfptr,
    operation,
    priority,
    (hkpBodyOperation::ExecutionState)hint);
}

// File Line: 4016
// RVA: 0xD5D8D0
hkWorldOperation::UserCallback *__fastcall hkpWorld::queueCallback(hkpWorld *this, hkWorldOperation::UserCallback *callback, unsigned __int64 userData)
{
  hkWorldOperation::UserCallback *v3; // rbx
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h]
  hkWorldOperation::UserCallback *v6; // [rsp+28h] [rbp-20h]
  unsigned __int64 v7; // [rsp+30h] [rbp-18h]

  v3 = callback;
  if ( this->m_criticalOperationsLockCount )
  {
    v6 = callback;
    operation.m_type.m_storage = 38;
    v7 = userData;
    hkpWorld::queueOperation(this, &operation);
  }
  else
  {
    ((void (__fastcall *)(hkWorldOperation::UserCallback *, unsigned __int64))callback->vfptr[1].__first_virtual_table_function__)(
      callback,
      userData);
  }
  return v3;
}

// File Line: 4032
// RVA: 0xD5A3E0
void __fastcall hkpWorld::findInitialContactPoints(hkpWorld *this, hkpEntity **entities, __int64 numEntities)
{
  hkpWorld *v3; // r9
  hkpSimulation *v4; // rcx
  float v5; // xmm0_4
  int v6; // xmm1_4
  float v7; // xmm1_4
  signed int v8; // ST28_4
  int v9; // [rsp+30h] [rbp-18h]
  int v10; // [rsp+34h] [rbp-14h]
  float v11; // [rsp+38h] [rbp-10h]
  float v12; // [rsp+3Ch] [rbp-Ch]

  v3 = this;
  v4 = this->m_simulation;
  v5 = 0.0;
  v6 = SLODWORD(v4->m_currentPsiTime);
  v9 = v6;
  v10 = v6;
  v7 = *(float *)&v6 - *(float *)&v6;
  v11 = v7;
  if ( v7 != 0.0 )
    v5 = 1.0 / v7;
  v12 = v5;
  v8 = 1;
  ((void (__fastcall *)(hkpSimulation *, hkpEntity **, __int64, hkpWorld *, int *, signed int, _QWORD, _QWORD))v4->vfptr[5].__first_virtual_table_function__)(
    v4,
    entities,
    numEntities,
    v3,
    &v9,
    v8,
    *(_QWORD *)&v9,
    *(_QWORD *)&v11);
}

// File Line: 4042
// RVA: 0xD5A450
void __fastcall hkpWorld::findInitialContactPointsOfAllEntities(hkpWorld *this)
{
  int v1; // edi
  hkpWorld *v2; // rbx
  int v3; // ebp
  __int64 v4; // rsi
  __int64 v5; // rsi

  v1 = 0;
  v2 = this;
  v3 = 0;
  if ( this->m_activeSimulationIslands.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      hkpWorld::findInitialContactPoints(
        v2,
        v2->m_activeSimulationIslands.m_data[v4]->m_entities.m_data,
        (unsigned int)v2->m_activeSimulationIslands.m_data[v4]->m_entities.m_size);
      ++v3;
      ++v4;
    }
    while ( v3 < v2->m_activeSimulationIslands.m_size );
  }
  if ( v2->m_inactiveSimulationIslands.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      hkpWorld::findInitialContactPoints(
        v2,
        v2->m_inactiveSimulationIslands.m_data[v5]->m_entities.m_data,
        (unsigned int)v2->m_inactiveSimulationIslands.m_data[v5]->m_entities.m_size);
      ++v1;
      ++v5;
    }
    while ( v1 < v2->m_inactiveSimulationIslands.m_size );
  }
}

// File Line: 4056
// RVA: 0xD5A4F0
void __fastcall hkpWorld::calcRequiredSolverBufferSize(hkpWorld *this, hkWorldMemoryAvailableWatchDog::MemUsageInfo *infoOut)
{
  hkWorldMemoryAvailableWatchDog::MemUsageInfo *v2; // rbx
  hkpWorld *v3; // rdi
  __int64 v4; // rdx
  __int64 v5; // r8
  int v6; // er11
  int v7; // eax
  __int64 i; // r9
  hkpSimulationIsland *v9; // r10
  int v10; // ecx
  int v11; // eax

  v2 = infoOut;
  v3 = this;
  hkpWorldOperationUtil::cleanupDirtyIslands(this);
  v6 = 0;
  *(_QWORD *)&v2->m_maxRuntimeBlockSize = 0i64;
  v2->m_largestSimulationIsland = 0i64;
  v7 = v3->m_activeSimulationIslands.m_size - 1;
  for ( i = v7; i >= 0; --i )
  {
    v9 = v3->m_activeSimulationIslands.m_data[i];
    v4 = (unsigned int)(2 * (v9->m_numConstraints / 80) + 8);
    v5 = 32 * ((_DWORD)v4 + 4 * v9->m_entities.m_size)
       + ((4 * (v9->m_constraintInfo.m_numSolverElemTemps + 3 * (_DWORD)v4) + 23) & 0xFFFFFFF0)
       + 176;
    v10 = v5 + v9->m_constraintInfo.m_sizeOfSchemas;
    v6 += v10;
    v2->m_sumRuntimeBlockSize = v6;
    if ( v10 > v2->m_maxRuntimeBlockSize )
    {
      v2->m_maxRuntimeBlockSize = v10;
      v2->m_largestSimulationIsland = v9;
    }
  }
  if ( (unsigned int)(v3->m_simulationType.m_storage - 2) <= 1 )
  {
    v11 = (*(__int64 (__fastcall **)(_QWORD, __int64, __int64, __int64))(**(_QWORD **)&v3->m_simulation[1].m_lastProcessingStep.m_storage
                                                                       + 56i64))(
            *(_QWORD *)&v3->m_simulation[1].m_lastProcessingStep.m_storage,
            v4,
            v5,
            i);
    if ( v2->m_sumRuntimeBlockSize > v11 )
      v11 = v2->m_sumRuntimeBlockSize;
    v2->m_sumRuntimeBlockSize = v11;
  }
}

// File Line: 4096
// RVA: 0xD5A630
void __fastcall hkpWorld::lock(hkpWorld *this)
{
  hkpWorld *v1; // rbx

  v1 = this;
  hkReferencedObject::lockAll();
  ++v1->m_isLocked;
}

// File Line: 4104
// RVA: 0xD5A660
void __fastcall hkpWorld::unlock(hkpWorld *this)
{
  --this->m_isLocked;
  hkReferencedObject::unlockAll();
}

// File Line: 4112
// RVA: 0xD5A650
void __fastcall hkpWorld::lockReadOnly(hkpWorld *this)
{
  ;
}

// File Line: 4117
// RVA: 0xD5A680
void __fastcall hkpWorld::unlockReadOnly(hkpWorld *this)
{
  ;
}

// File Line: 4122
// RVA: 0xD5A690
char __fastcall hkpWorld::checkUnmarked(hkpWorld *this)
{
  return 1;
}

// File Line: 4138
// RVA: 0xD5A6A0
void __fastcall hkpWorld::lockIslandForConstraintUpdate(hkpWorld *this, hkpSimulationIsland *island)
{
  hkCriticalSection *v2; // rcx

  v2 = this->m_modifyConstraintCriticalSection;
  if ( v2 )
    EnterCriticalSection(&v2->m_section);
}

// File Line: 4154
// RVA: 0xD5A6C0
void __fastcall hkpWorld::lockForIslandSplit(hkpWorld *this, hkpSimulationIsland *island)
{
  hkCriticalSection *v2; // rcx

  v2 = this->m_modifyConstraintCriticalSection;
  if ( v2 )
    EnterCriticalSection(&v2->m_section);
}

// File Line: 4166
// RVA: 0xD5A6E0
void __fastcall hkpWorld::unlockIslandForConstraintUpdate(hkpWorld *this, hkpSimulationIsland *island)
{
  hkCriticalSection *v2; // rcx

  v2 = this->m_modifyConstraintCriticalSection;
  if ( v2 )
    LeaveCriticalSection(&v2->m_section);
}

// File Line: 4181
// RVA: 0xD5A700
void __fastcall hkpWorld::unlockForIslandSplit(hkpWorld *this, hkpSimulationIsland *island)
{
  hkCriticalSection *v2; // rcx

  v2 = this->m_modifyConstraintCriticalSection;
  if ( v2 )
    LeaveCriticalSection(&v2->m_section);
}

// File Line: 4193
// RVA: 0xD5A720
void __fastcall hkpWorld::setMultithreadedAccessChecking(hkpWorld *this, hkpWorld::MtAccessChecking accessCheckState)
{
  hkpWorld *v2; // rbx
  hkMultiThreadCheck *v3; // rcx

  v2 = this;
  v3 = &this->m_multiThreadCheck;
  if ( accessCheckState )
  {
    hkMultiThreadCheck::disableChecks(v3);
    hkMultiThreadCheck::disableChecks(&v2->m_broadPhase->m_multiThreadCheck);
  }
  else
  {
    hkMultiThreadCheck::enableChecks(v3);
    hkMultiThreadCheck::enableChecks(&v2->m_broadPhase->m_multiThreadCheck);
  }
}

// File Line: 4207
// RVA: 0xD5A770
_BOOL8 __fastcall hkpWorld::getMultithreadedAccessChecking(hkpWorld *this)
{
  return (this->m_multiThreadCheck.m_markCount & 0x8000u) != 0 || !hkMultiThreadCheck::m_criticalSection;
}


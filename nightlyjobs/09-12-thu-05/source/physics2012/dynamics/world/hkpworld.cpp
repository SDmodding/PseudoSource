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
  this->m_activeSimulationIslands.m_capacityAndFlags = 0x80000000;
  this->m_inactiveSimulationIslands.m_data = 0i64;
  this->m_inactiveSimulationIslands.m_size = 0;
  this->m_inactiveSimulationIslands.m_capacityAndFlags = 0x80000000;
  this->m_dirtySimulationIslands.m_data = 0i64;
  this->m_dirtySimulationIslands.m_size = 0;
  this->m_dirtySimulationIslands.m_capacityAndFlags = 0x80000000;
  this->m_memoryWatchDog.m_pntr = 0i64;
  this->m_multiThreadCheck.m_threadId = -15;
  this->m_multiThreadCheck.m_markCount = 0x8000;
  this->m_actionListeners.m_data = 0i64;
  this->m_actionListeners.m_size = 0;
  this->m_actionListeners.m_capacityAndFlags = 0x80000000;
  this->m_entityListeners.m_data = 0i64;
  this->m_entityListeners.m_size = 0;
  this->m_entityListeners.m_capacityAndFlags = 0x80000000;
  this->m_phantomListeners.m_data = 0i64;
  this->m_phantomListeners.m_size = 0;
  this->m_phantomListeners.m_capacityAndFlags = 0x80000000;
  this->m_constraintListeners.m_data = 0i64;
  this->m_constraintListeners.m_size = 0;
  this->m_constraintListeners.m_capacityAndFlags = 0x80000000;
  this->m_worldDeletionListeners.m_data = 0i64;
  this->m_worldDeletionListeners.m_size = 0;
  this->m_worldDeletionListeners.m_capacityAndFlags = 0x80000000;
  this->m_islandActivationListeners.m_data = 0i64;
  this->m_islandActivationListeners.m_size = 0;
  this->m_islandActivationListeners.m_capacityAndFlags = 0x80000000;
  this->m_worldPostSimulationListeners.m_data = 0i64;
  this->m_worldPostSimulationListeners.m_size = 0;
  this->m_worldPostSimulationListeners.m_capacityAndFlags = 0x80000000;
  this->m_worldPostIntegrateListeners.m_data = 0i64;
  this->m_worldPostIntegrateListeners.m_size = 0;
  this->m_worldPostIntegrateListeners.m_capacityAndFlags = 0x80000000;
  this->m_worldPostCollideListeners.m_data = 0i64;
  this->m_worldPostCollideListeners.m_size = 0;
  this->m_worldPostCollideListeners.m_capacityAndFlags = 0x80000000;
  this->m_islandPostIntegrateListeners.m_data = 0i64;
  this->m_islandPostIntegrateListeners.m_size = 0;
  this->m_islandPostIntegrateListeners.m_capacityAndFlags = 0x80000000;
  this->m_islandPostCollideListeners.m_data = 0i64;
  this->m_islandPostCollideListeners.m_size = 0;
  this->m_islandPostCollideListeners.m_capacityAndFlags = 0x80000000;
  this->m_contactListeners.m_data = 0i64;
  this->m_contactListeners.m_size = 0;
  this->m_contactListeners.m_capacityAndFlags = 0x80000000;
  this->m_contactImpulseLimitBreachedListeners.m_data = 0i64;
  this->m_contactImpulseLimitBreachedListeners.m_size = 0;
  this->m_contactImpulseLimitBreachedListeners.m_capacityAndFlags = 0x80000000;
  this->m_worldExtensions.m_data = 0i64;
  this->m_worldExtensions.m_size = 0;
  this->m_worldExtensions.m_capacityAndFlags = 0x80000000;
}

// File Line: 141
// RVA: 0xD5D3C0
void __fastcall hkpWorld::removeAll(hkpWorld *this)
{
  int v2; // edi
  int v3; // esi
  hkpSimulationIsland *m_fixedIsland; // rax
  __int64 m_size; // r10
  int v6; // r9d
  __int64 v7; // r8
  hkpSimulationIsland **m_data; // rcx
  unsigned __int64 v9; // rdx
  hkpSimulationIsland *v10; // rax
  int v11; // eax
  __int64 v12; // rdi
  int v13; // r8d
  int v14; // r9d
  int v15; // r10d
  __int64 v16; // r11
  hkpSimulationIsland **v17; // rcx
  unsigned __int64 v18; // rdx
  hkpSimulationIsland *v19; // rax
  int v20; // r9d
  int v21; // esi
  __int64 v22; // rdi
  int v23; // edi
  __int64 v24; // rsi
  hkpSimulationIsland *v25; // r10
  int v26; // edi
  __int64 v27; // rdx
  __int64 v28; // rcx
  hkpRigidBody **v29; // rax
  int v30; // edi
  int v31; // r8d
  hkpSimulationIsland *v32; // rcx
  hkArrayBase<char *> array; // [rsp+30h] [rbp-18h] BYREF
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  v2 = 0;
  v3 = 0;
  hkpWorld::removePhantomBatch(this, this->m_phantoms.m_data, this->m_phantoms.m_size);
  m_fixedIsland = this->m_fixedIsland;
  m_size = this->m_activeSimulationIslands.m_size;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  v6 = m_fixedIsland->m_entities.m_size;
  v7 = 0i64;
  if ( m_size >= 2 )
  {
    m_data = this->m_activeSimulationIslands.m_data;
    v9 = ((unsigned __int64)(m_size - 2) >> 1) + 1;
    v7 = 2 * v9;
    do
    {
      v10 = *m_data;
      m_data += 2;
      v2 += v10->m_entities.m_size;
      v3 += (*(m_data - 1))->m_entities.m_size;
      --v9;
    }
    while ( v9 );
  }
  if ( v7 < m_size )
    v6 += this->m_activeSimulationIslands.m_data[v7]->m_entities.m_size;
  v11 = v2 + v3;
  v12 = this->m_inactiveSimulationIslands.m_size;
  v13 = 0;
  v14 = v11 + v6;
  v15 = 0;
  v16 = 0i64;
  if ( v12 >= 2 )
  {
    v17 = this->m_inactiveSimulationIslands.m_data;
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
    v14 += this->m_inactiveSimulationIslands.m_data[v16]->m_entities.m_size;
  v20 = v13 + v15 + v14;
  if ( v20 > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&array.m_data, v20, 8);
  v21 = 0;
  if ( this->m_activeSimulationIslands.m_size > 0 )
  {
    v22 = 0i64;
    do
    {
      hkArrayBase<unsigned __int64>::_append(
        &array,
        &hkContainerTempAllocator::s_alloc,
        (char *const *)this->m_activeSimulationIslands.m_data[v22]->m_entities.m_data,
        this->m_activeSimulationIslands.m_data[v22]->m_entities.m_size);
      ++v21;
      ++v22;
    }
    while ( v21 < this->m_activeSimulationIslands.m_size );
  }
  v23 = 0;
  if ( this->m_inactiveSimulationIslands.m_size > 0 )
  {
    v24 = 0i64;
    do
    {
      hkArrayBase<unsigned __int64>::_append(
        &array,
        &hkContainerTempAllocator::s_alloc,
        (char *const *)this->m_inactiveSimulationIslands.m_data[v24]->m_entities.m_data,
        this->m_inactiveSimulationIslands.m_data[v24]->m_entities.m_size);
      ++v23;
      ++v24;
    }
    while ( v23 < this->m_inactiveSimulationIslands.m_size );
  }
  v25 = this->m_fixedIsland;
  v26 = 0;
  v27 = v25->m_entities.m_size;
  v28 = 0i64;
  if ( v27 <= 0 )
  {
LABEL_23:
    v26 = -1;
  }
  else
  {
    v29 = (hkpRigidBody **)v25->m_entities.m_data;
    while ( *v29 != this->m_fixedRigidBody )
    {
      ++v28;
      ++v26;
      ++v29;
      if ( v28 >= v27 )
        goto LABEL_23;
    }
  }
  v30 = array.m_size + v26;
  hkArrayBase<unsigned __int64>::_append(
    &array,
    &hkContainerTempAllocator::s_alloc,
    (char *const *)v25->m_entities.m_data,
    v25->m_entities.m_size);
  v31 = array.m_size - 1;
  array.m_size = v31;
  if ( v31 != v30 )
  {
    array.m_data[v30] = array.m_data[v31];
    v31 = array.m_size;
  }
  hkpWorld::removeEntityBatch(this, (hkpEntity **)array.m_data, v31);
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      8 * array.m_capacityAndFlags);
  if ( !this->m_wantSimulationIslands.m_bool )
  {
    hkpWorldOperationUtil::removeIslandFromDirtyList(
      this,
      this->m_activeSimulationIslands.m_data[this->m_activeSimulationIslands.m_size - 1]);
    v32 = this->m_activeSimulationIslands.m_data[this->m_activeSimulationIslands.m_size - 1];
    if ( v32 )
      v32->vfptr->__vecDelDtor(v32, 1u);
    --this->m_activeSimulationIslands.m_size;
  }
  hkpWorldCallbackUtil::fireWorldRemoveAll(this);
}

// File Line: 212
// RVA: 0xD5CB30
void __fastcall hkpWorld::~hkpWorld(hkpWorld *this)
{
  hkpMtThreadStructure *m_multithreadedSimulationJobData; // rdi
  _QWORD **Value; // rax
  _QWORD **v4; // rax
  hkCriticalSection *m_modifyConstraintCriticalSection; // rdi
  _QWORD **v6; // rax
  hkCriticalSection *m_propertyMasterLock; // rdi
  _QWORD **v8; // rax
  hkWorldMemoryAvailableWatchDog *m_pntr; // rcx
  hkpSimulationIsland *m_fixedIsland; // rdx
  hkpSimulationIsland *v11; // rcx
  hkCriticalSection *m_islandDirtyListCriticalSection; // rdi
  _QWORD **v13; // rax
  __int64 m_size; // rbp
  __int64 i; // rsi
  hkpWorldExtension *v16; // rdi
  hkpCollisionDispatcher *m_collisionDispatcher; // rcx
  hkpTypedBroadPhaseDispatcher *m_broadPhaseDispatcher; // rdi
  _QWORD **v19; // rax
  hkpBroadPhaseBorder *m_broadPhaseBorder; // rcx
  hkpPhantomBroadPhaseListener *m_phantomBroadPhaseListener; // rcx
  hkpEntityEntityBroadPhaseListener *m_entityEntityBroadPhaseListener; // rcx
  hkpBroadPhaseBorderListener *m_broadPhaseBorderListener; // rcx
  hkpCollisionAgentConfig *m_config; // rdi
  _QWORD **v25; // rax
  hkpProcessCollisionInput *m_collisionInput; // rdi
  _QWORD **v27; // rax
  _QWORD **v28; // rax
  hkpWorldOperationQueue *m_pendingOperations; // rdi
  _QWORD **v30; // rax
  hkpViolatedConstraintArray *m_violatedConstraintArray; // rdi
  _QWORD **v32; // rax
  int m_capacityAndFlags; // r8d
  int v34; // r8d
  int v35; // r8d
  int v36; // r8d
  int v37; // r8d
  int v38; // r8d
  int v39; // r8d
  int v40; // r8d
  int v41; // r8d
  int v42; // r8d
  int v43; // r8d
  int v44; // r8d
  int v45; // r8d
  int v46; // r8d
  int v47; // r8d
  hkWorldMemoryAvailableWatchDog *v48; // rcx
  int v49; // r8d
  int v50; // r8d
  int v51; // r8d
  hkBool result; // [rsp+40h] [rbp+8h] BYREF

  m_multithreadedSimulationJobData = this->m_multithreadedSimulationJobData;
  this->vfptr = (hkBaseObjectVtbl *)&hkpWorld::`vftable;
  if ( m_multithreadedSimulationJobData )
  {
    if ( m_multithreadedSimulationJobData->m_collisionInput.m_spareAgentSector )
    {
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, __int64))(*Value[11] + 16i64))(
        Value[11],
        m_multithreadedSimulationJobData->m_collisionInput.m_spareAgentSector,
        512i64);
    }
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpMtThreadStructure *, __int64))(*v4[11] + 16i64))(
      v4[11],
      m_multithreadedSimulationJobData,
      352i64);
  }
  hkReferencedObject::removeReference(this->m_maintenanceMgr);
  m_modifyConstraintCriticalSection = this->m_modifyConstraintCriticalSection;
  this->m_maintenanceMgr = 0i64;
  if ( m_modifyConstraintCriticalSection )
  {
    DeleteCriticalSection(&m_modifyConstraintCriticalSection->m_section);
    v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkCriticalSection *, __int64))(*v6[11] + 16i64))(
      v6[11],
      m_modifyConstraintCriticalSection,
      40i64);
    this->m_modifyConstraintCriticalSection = 0i64;
  }
  m_propertyMasterLock = this->m_propertyMasterLock;
  if ( m_propertyMasterLock )
  {
    DeleteCriticalSection(&this->m_propertyMasterLock->m_section);
    v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkCriticalSection *, __int64))(*v8[11] + 16i64))(
      v8[11],
      m_propertyMasterLock,
      40i64);
    this->m_propertyMasterLock = 0i64;
  }
  m_pntr = this->m_memoryWatchDog.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_memoryWatchDog.m_pntr = 0i64;
  hkpWorld::removeAll(this);
  hkpWorld::removeEntity(this, &result, this->m_fixedRigidBody);
  m_fixedIsland = this->m_fixedIsland;
  this->m_fixedRigidBody = 0i64;
  hkpWorldOperationUtil::removeIslandFromDirtyList(this, m_fixedIsland);
  v11 = this->m_fixedIsland;
  if ( v11 )
    v11->vfptr->__vecDelDtor(v11, 1u);
  m_islandDirtyListCriticalSection = this->m_islandDirtyListCriticalSection;
  this->m_fixedIsland = 0i64;
  if ( m_islandDirtyListCriticalSection )
  {
    DeleteCriticalSection(&m_islandDirtyListCriticalSection->m_section);
    v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkCriticalSection *, __int64))(*v13[11] + 16i64))(
      v13[11],
      m_islandDirtyListCriticalSection,
      40i64);
    this->m_islandDirtyListCriticalSection = 0i64;
  }
  m_size = this->m_worldExtensions.m_size;
  for ( i = 0i64; i < m_size; ++i )
  {
    v16 = this->m_worldExtensions.m_data[i];
    v16->vfptr[2].__vecDelDtor(v16, (unsigned int)this);
    v16->m_world = 0i64;
    hkReferencedObject::removeReference(v16);
  }
  hkpWorldCallbackUtil::fireWorldDeleted(this);
  hkReferencedObject::removeReference(this->m_broadPhase);
  m_collisionDispatcher = this->m_collisionDispatcher;
  this->m_broadPhase = 0i64;
  hkReferencedObject::removeReference(m_collisionDispatcher);
  m_broadPhaseDispatcher = this->m_broadPhaseDispatcher;
  this->m_collisionDispatcher = 0i64;
  if ( m_broadPhaseDispatcher )
  {
    hkpTypedBroadPhaseDispatcher::~hkpTypedBroadPhaseDispatcher(m_broadPhaseDispatcher);
    v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpTypedBroadPhaseDispatcher *, __int64))(*v19[11] + 16i64))(
      v19[11],
      m_broadPhaseDispatcher,
      536i64);
  }
  m_broadPhaseBorder = this->m_broadPhaseBorder;
  if ( m_broadPhaseBorder )
    hkReferencedObject::removeReference(m_broadPhaseBorder);
  m_phantomBroadPhaseListener = this->m_phantomBroadPhaseListener;
  if ( m_phantomBroadPhaseListener )
    m_phantomBroadPhaseListener->hkReferencedObject::hkBaseObject::vfptr->__vecDelDtor(m_phantomBroadPhaseListener, 1u);
  m_entityEntityBroadPhaseListener = this->m_entityEntityBroadPhaseListener;
  if ( m_entityEntityBroadPhaseListener )
    m_entityEntityBroadPhaseListener->hkReferencedObject::hkBaseObject::vfptr->__vecDelDtor(
      m_entityEntityBroadPhaseListener,
      1u);
  m_broadPhaseBorderListener = this->m_broadPhaseBorderListener;
  if ( m_broadPhaseBorderListener )
    m_broadPhaseBorderListener->hkReferencedObject::hkBaseObject::vfptr->__vecDelDtor(m_broadPhaseBorderListener, 1u);
  hkReferencedObject::removeReference(this->m_collisionFilter);
  hkReferencedObject::removeReference(this->m_convexListFilter);
  m_config = this->m_collisionInput->m_config;
  if ( m_config )
  {
    v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpCollisionAgentConfig *, __int64))(*v25[11] + 16i64))(v25[11], m_config, 16i64);
  }
  m_collisionInput = this->m_collisionInput;
  if ( m_collisionInput )
  {
    if ( m_collisionInput->m_spareAgentSector )
    {
      v27 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, __int64))(*v27[11] + 16i64))(
        v27[11],
        m_collisionInput->m_spareAgentSector,
        512i64);
    }
    v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpProcessCollisionInput *, __int64))(*v28[11] + 16i64))(
      v28[11],
      m_collisionInput,
      160i64);
  }
  hkReferencedObject::removeReference(this->m_simulation);
  m_pendingOperations = this->m_pendingOperations;
  if ( m_pendingOperations )
  {
    hkpWorldOperationQueue::~hkpWorldOperationQueue(this->m_pendingOperations);
    v30 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpWorldOperationQueue *, __int64))(*v30[11] + 16i64))(
      v30[11],
      m_pendingOperations,
      56i64);
  }
  m_violatedConstraintArray = this->m_violatedConstraintArray;
  if ( m_violatedConstraintArray )
  {
    v32 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpViolatedConstraintArray *, __int64))(*v32[11] + 16i64))(
      v32[11],
      m_violatedConstraintArray,
      1032i64);
  }
  m_capacityAndFlags = this->m_worldExtensions.m_capacityAndFlags;
  this->m_worldExtensions.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_worldExtensions.m_data,
      8 * m_capacityAndFlags);
  this->m_worldExtensions.m_data = 0i64;
  this->m_worldExtensions.m_capacityAndFlags = 0x80000000;
  v34 = this->m_contactImpulseLimitBreachedListeners.m_capacityAndFlags;
  this->m_contactImpulseLimitBreachedListeners.m_size = 0;
  if ( v34 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_contactImpulseLimitBreachedListeners.m_data,
      8 * v34);
  this->m_contactImpulseLimitBreachedListeners.m_data = 0i64;
  this->m_contactImpulseLimitBreachedListeners.m_capacityAndFlags = 0x80000000;
  v35 = this->m_contactListeners.m_capacityAndFlags;
  this->m_contactListeners.m_size = 0;
  if ( v35 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_contactListeners.m_data,
      8 * v35);
  this->m_contactListeners.m_data = 0i64;
  this->m_contactListeners.m_capacityAndFlags = 0x80000000;
  v36 = this->m_islandPostCollideListeners.m_capacityAndFlags;
  this->m_islandPostCollideListeners.m_size = 0;
  if ( v36 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_islandPostCollideListeners.m_data,
      8 * v36);
  this->m_islandPostCollideListeners.m_data = 0i64;
  this->m_islandPostCollideListeners.m_capacityAndFlags = 0x80000000;
  v37 = this->m_islandPostIntegrateListeners.m_capacityAndFlags;
  this->m_islandPostIntegrateListeners.m_size = 0;
  if ( v37 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_islandPostIntegrateListeners.m_data,
      8 * v37);
  this->m_islandPostIntegrateListeners.m_data = 0i64;
  this->m_islandPostIntegrateListeners.m_capacityAndFlags = 0x80000000;
  v38 = this->m_worldPostCollideListeners.m_capacityAndFlags;
  this->m_worldPostCollideListeners.m_size = 0;
  if ( v38 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_worldPostCollideListeners.m_data,
      8 * v38);
  this->m_worldPostCollideListeners.m_data = 0i64;
  this->m_worldPostCollideListeners.m_capacityAndFlags = 0x80000000;
  v39 = this->m_worldPostIntegrateListeners.m_capacityAndFlags;
  this->m_worldPostIntegrateListeners.m_size = 0;
  if ( v39 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_worldPostIntegrateListeners.m_data,
      8 * v39);
  this->m_worldPostIntegrateListeners.m_data = 0i64;
  this->m_worldPostIntegrateListeners.m_capacityAndFlags = 0x80000000;
  v40 = this->m_worldPostSimulationListeners.m_capacityAndFlags;
  this->m_worldPostSimulationListeners.m_size = 0;
  if ( v40 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_worldPostSimulationListeners.m_data,
      8 * v40);
  this->m_worldPostSimulationListeners.m_data = 0i64;
  this->m_worldPostSimulationListeners.m_capacityAndFlags = 0x80000000;
  v41 = this->m_islandActivationListeners.m_capacityAndFlags;
  this->m_islandActivationListeners.m_size = 0;
  if ( v41 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_islandActivationListeners.m_data,
      8 * v41);
  this->m_islandActivationListeners.m_data = 0i64;
  this->m_islandActivationListeners.m_capacityAndFlags = 0x80000000;
  v42 = this->m_worldDeletionListeners.m_capacityAndFlags;
  this->m_worldDeletionListeners.m_size = 0;
  if ( v42 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_worldDeletionListeners.m_data,
      8 * v42);
  this->m_worldDeletionListeners.m_data = 0i64;
  this->m_worldDeletionListeners.m_capacityAndFlags = 0x80000000;
  v43 = this->m_constraintListeners.m_capacityAndFlags;
  this->m_constraintListeners.m_size = 0;
  if ( v43 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_constraintListeners.m_data,
      8 * v43);
  this->m_constraintListeners.m_data = 0i64;
  this->m_constraintListeners.m_capacityAndFlags = 0x80000000;
  v44 = this->m_phantomListeners.m_capacityAndFlags;
  this->m_phantomListeners.m_size = 0;
  if ( v44 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_phantomListeners.m_data,
      8 * v44);
  this->m_phantomListeners.m_data = 0i64;
  this->m_phantomListeners.m_capacityAndFlags = 0x80000000;
  v45 = this->m_entityListeners.m_capacityAndFlags;
  this->m_entityListeners.m_size = 0;
  if ( v45 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_entityListeners.m_data,
      8 * v45);
  this->m_entityListeners.m_data = 0i64;
  this->m_entityListeners.m_capacityAndFlags = 0x80000000;
  v46 = this->m_actionListeners.m_capacityAndFlags;
  this->m_actionListeners.m_size = 0;
  if ( v46 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_actionListeners.m_data,
      8 * v46);
  this->m_actionListeners.m_data = 0i64;
  this->m_actionListeners.m_capacityAndFlags = 0x80000000;
  v47 = this->m_phantoms.m_capacityAndFlags;
  this->m_phantoms.m_size = 0;
  if ( v47 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_phantoms.m_data,
      8 * v47);
  this->m_phantoms.m_data = 0i64;
  this->m_phantoms.m_capacityAndFlags = 0x80000000;
  v48 = this->m_memoryWatchDog.m_pntr;
  if ( v48 )
    hkReferencedObject::removeReference(v48);
  this->m_memoryWatchDog.m_pntr = 0i64;
  v49 = this->m_dirtySimulationIslands.m_capacityAndFlags;
  this->m_dirtySimulationIslands.m_size = 0;
  if ( v49 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_dirtySimulationIslands.m_data,
      8 * v49);
  this->m_dirtySimulationIslands.m_data = 0i64;
  this->m_dirtySimulationIslands.m_capacityAndFlags = 0x80000000;
  v50 = this->m_inactiveSimulationIslands.m_capacityAndFlags;
  this->m_inactiveSimulationIslands.m_size = 0;
  if ( v50 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_inactiveSimulationIslands.m_data,
      8 * v50);
  this->m_inactiveSimulationIslands.m_data = 0i64;
  this->m_inactiveSimulationIslands.m_capacityAndFlags = 0x80000000;
  v51 = this->m_activeSimulationIslands.m_capacityAndFlags;
  this->m_activeSimulationIslands.m_size = 0;
  if ( v51 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_activeSimulationIslands.m_data,
      8 * v51);
  this->m_activeSimulationIslands.m_data = 0i64;
  this->m_activeSimulationIslands.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 304
// RVA: 0xD5DBC0
void __fastcall hkWorld_setupContactMgrFactories(hkpWorld *world, hkpCollisionDispatcher *dis)
{
  _QWORD **Value; // rax
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

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkpSimpleConstraintContactMgr::Factory *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                   Value[11],
                                                   24i64);
  if ( v5 )
  {
    hkpSimpleConstraintContactMgr::Factory::Factory(v5, world);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpReportContactMgr::Factory *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v8[11] + 8i64))(v8[11], 24i64);
  if ( v9 )
  {
    hkpReportContactMgr::Factory::Factory(v9, world);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v12[11] + 8i64))(v12[11], 40i64);
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
  hkpCollisionDispatcher::registerContactMgrFactoryWithAll(dis, v7, 1);
  hkpCollisionDispatcher::registerContactMgrFactoryWithAll(dis, v11, 2);
  hkpCollisionDispatcher::registerContactMgrFactoryWithAll(dis, v14, 3);
  hkReferencedObject::removeReference(v7);
  hkReferencedObject::removeReference(v11);
  hkReferencedObject::removeReference(v14);
}

// File Line: 324
// RVA: 0xD59E80
void __fastcall hkpWorld::updateCollisionFilterOnWorld(
        hkpWorld *this,
        hkpUpdateCollisionFilterOnWorldMode updateMode,
        hkpUpdateCollectionFilterMode updateShapeCollectionFilter)
{
  _QWORD *Value; // r8
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  int v10; // edi
  int v11; // r14d
  __int64 v12; // r15
  hkpSimulationIsland *v13; // rsi
  __int64 v14; // rbx
  int v15; // r14d
  __int64 v16; // r15
  hkpSimulationIsland *v17; // rsi
  __int64 v18; // rbx
  __int64 v19; // rbx
  __int64 *v20; // rdi
  __int64 v21; // rsi
  __int64 v22; // rax
  __int64 v23; // rdx
  __int64 v24; // rdi
  __int64 i; // rax
  unsigned __int16 *v26; // r15
  int v27; // edx
  int v28; // eax
  int v29; // r14d
  __int64 v30; // rcx
  hkpAgentNnEntry *v31; // rbx
  hkpAgentNnEntry *v32; // rsi
  hkpCollisionDispatcher *m_collisionDispatcher; // rax
  __int64 v34; // rdx
  int v35; // ecx
  hkpAgentNnEntry *v36; // rcx
  bool v37; // zf
  _QWORD *v38; // r8
  _QWORD *v39; // rcx
  unsigned __int64 v40; // rax
  _QWORD *v41; // rcx
  __int64 v42; // [rsp+20h] [rbp-E0h]
  __int64 *v43; // [rsp+28h] [rbp-D8h]
  __int64 v44; // [rsp+30h] [rbp-D0h]
  __int64 v45; // [rsp+38h] [rbp-C8h]
  __int64 v46; // [rsp+40h] [rbp-C0h]
  __int64 v47[2]; // [rsp+48h] [rbp-B8h]
  __int64 v48[3]; // [rsp+58h] [rbp-A8h] BYREF
  char *array; // [rsp+70h] [rbp-90h] BYREF
  int v50; // [rsp+78h] [rbp-88h]
  int v51; // [rsp+7Ch] [rbp-84h]
  char v52; // [rsp+80h] [rbp-80h] BYREF
  hkWorldOperation::BaseOperation operation; // [rsp+1C0h] [rbp+C0h] BYREF
  char v54; // [rsp+1C1h] [rbp+C1h]
  char v55; // [rsp+1C2h] [rbp+C2h]
  int v56; // [rsp+1D8h] [rbp+D8h]

  if ( this->m_criticalOperationsLockCount )
  {
    v54 = updateMode;
    operation.m_type.m_storage = 22;
    v55 = updateShapeCollectionFilter;
    hkpWorld::queueOperation(this, &operation);
  }
  else
  {
    this->m_blockExecutingPendingOperations.m_bool = 1;
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v7 = (_QWORD *)Value[1];
    if ( (unsigned __int64)v7 < Value[3] )
    {
      *v7 = "TtUpdateFilterOnWorld";
      v8 = __rdtsc();
      v9 = v7 + 2;
      *((_DWORD *)v9 - 2) = v8;
      Value[1] = v9;
    }
    if ( updateMode )
    {
      ++this->m_criticalOperationsLockCount;
      v20 = v48;
      v48[0] = (__int64)&this->m_activeSimulationIslands;
      v21 = 2i64;
      v43 = v48;
      v48[1] = (__int64)&this->m_inactiveSimulationIslands;
      v42 = 2i64;
      do
      {
        v50 = 0;
        v51 = -2147483616;
        array = &v52;
        v22 = *v20;
        v56 = 0;
        if ( *(int *)(v22 + 8) > 0 )
        {
          v23 = 0i64;
          v44 = 0i64;
          do
          {
            v45 = 0i64;
            v24 = *(_QWORD *)(v23 + *(_QWORD *)v22);
            v47[0] = v24 + 152;
            v47[1] = v24 + 120;
            for ( i = 0i64; i < 2; v45 = i )
            {
              v26 = (unsigned __int16 *)v47[i];
              v50 = 0;
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
                    v32 = (hkpAgentNnEntry *)((char *)v31 + *v26);
                  else
                    v32 = v31 + 24;
                  if ( v31 < v32 )
                  {
                    do
                    {
                      if ( this->m_collisionFilter->vfptr->isCollisionEnabled(
                             &this->m_collisionFilter->hkpCollidableCollidableFilter,
                             &operation,
                             v31->m_collidable[0],
                             v31->m_collidable[1])->m_bool
                        && (m_collisionDispatcher = this->m_collisionDispatcher,
                            v34 = v31->m_collidable[1]->m_broadPhaseHandle.m_objectQualityType
                                + 10i64 * v31->m_collidable[0]->m_broadPhaseHandle.m_objectQualityType,
                            m_collisionDispatcher->m_collisionQualityTable[0][v34])
                        && m_collisionDispatcher->m_collisionQualityTable[0][v34] == (unsigned __int8)v31->m_collisionQualityIndex )
                      {
                        if ( updateShapeCollectionFilter == HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS )
                          hkAgentNnMachine_UpdateShapeCollectionFilter(
                            v31,
                            this->m_collisionInput,
                            (hkpConstraintOwner *)v24);
                      }
                      else
                      {
                        v35 = v50;
                        if ( v50 == (v51 & 0x3FFFFFFF) )
                        {
                          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
                          v35 = v50;
                        }
                        *(_QWORD *)&array[8 * v35] = v31;
                        ++v50;
                        *(_BYTE *)(v24 + 49) &= ~2u;
                        *(_BYTE *)(v24 + 49) |= 1u;
                      }
                      v31 = (hkpAgentNnEntry *)((char *)v31 + (unsigned __int8)v31->m_size);
                    }
                    while ( v31 < v32 );
                    v27 = v50;
                    v30 = v46;
                  }
                  v28 = *((_DWORD *)v26 + 4);
                }
                while ( v29 < v28 );
              }
              i = v45 + 1;
            }
            if ( v27 )
            {
              do
              {
                v36 = *(hkpAgentNnEntry **)&array[8 * v27 - 8];
                v50 = v27 - 1;
                hkpWorldAgentUtil::removeAgentAndItsToiEvents(v36);
                v27 = v50;
              }
              while ( v50 );
            }
            v20 = v43;
            v22 = *v43;
            v23 = v44 + 8;
            ++v56;
            v44 += 8i64;
          }
          while ( v56 < *(_DWORD *)(v22 + 8) );
          v21 = v42;
        }
        v50 = 0;
        if ( v51 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v51);
        ++v20;
        v42 = --v21;
        v43 = v20;
      }
      while ( v21 );
      --this->m_criticalOperationsLockCount;
    }
    else
    {
      v10 = 0;
      v11 = 0;
      if ( this->m_activeSimulationIslands.m_size > 0 )
      {
        v12 = 0i64;
        do
        {
          v13 = this->m_activeSimulationIslands.m_data[v12];
          if ( v13->m_entities.m_size > 0 )
          {
            v14 = 0i64;
            do
            {
              hkpWorld::updateCollisionFilterOnEntity(
                this,
                v13->m_entities.m_data[v14],
                HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
                updateShapeCollectionFilter);
              ++v10;
              ++v14;
            }
            while ( v10 < v13->m_entities.m_size );
          }
          ++v11;
          ++v12;
          v10 = 0;
        }
        while ( v11 < this->m_activeSimulationIslands.m_size );
      }
      v15 = 0;
      if ( this->m_inactiveSimulationIslands.m_size > 0 )
      {
        v16 = 0i64;
        do
        {
          v17 = this->m_inactiveSimulationIslands.m_data[v16];
          if ( v17->m_entities.m_size > 0 )
          {
            v18 = 0i64;
            do
            {
              hkpWorld::updateCollisionFilterOnEntity(
                this,
                v17->m_entities.m_data[v18],
                HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
                updateShapeCollectionFilter);
              ++v10;
              ++v18;
            }
            while ( v10 < v17->m_entities.m_size );
          }
          ++v15;
          ++v16;
          v10 = 0;
        }
        while ( v15 < this->m_inactiveSimulationIslands.m_size );
      }
      if ( this->m_phantoms.m_size > 0 )
      {
        v19 = 0i64;
        do
        {
          hkpWorld::updateCollisionFilterOnPhantom(this, this->m_phantoms.m_data[v19], updateShapeCollectionFilter);
          ++v10;
          ++v19;
        }
        while ( v10 < this->m_phantoms.m_size );
      }
    }
    v37 = this->m_criticalOperationsLockCount == 0;
    this->m_blockExecutingPendingOperations.m_bool = 0;
    if ( v37 )
    {
      if ( this->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(this);
      if ( this->m_pendingOperationQueueCount == 1 && this->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(this);
    }
    v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v39 = (_QWORD *)v38[1];
    if ( (unsigned __int64)v39 < v38[3] )
    {
      *v39 = "Et";
      v40 = __rdtsc();
      v41 = v39 + 2;
      *((_DWORD *)v41 - 2) = v40;
      v38[1] = v41;
    }
  }
}

// File Line: 476
// RVA: 0xD5DD00
void __fastcall hkWorld_updateFilterOnSinglePhantom(
        hkpPhantom *phantom,
        hkpCollidable *collidable,
        hkpCollisionFilter *filter)
{
  char v6; // [rsp+40h] [rbp+8h] BYREF
  char v7; // [rsp+50h] [rbp+18h] BYREF

  ((void (__fastcall *)(hkpPhantom *, char *, hkpCollidable *))phantom->vfptr[4].__first_virtual_table_function__)(
    phantom,
    &v6,
    collidable);
  if ( filter->hkpCollidableCollidableFilter::vfptr->isCollisionEnabled(
         &filter->hkpCollidableCollidableFilter,
         &v7,
         &phantom->m_collidable,
         collidable)->m_bool )
  {
    if ( !v6 )
      phantom->vfptr[4].__vecDelDtor(phantom, (unsigned int)collidable);
    if ( collidable->m_broadPhaseHandle.m_type == 2 )
    {
      (*(void (__fastcall **)(char *, char *, hkpLinkedCollidable *))&(*(hkpShape **)((char *)&collidable->m_shape
                                                                                    + collidable->m_ownerOffset))[2].m_memSizeAndFlags)(
        (char *)collidable + collidable->m_ownerOffset,
        &v7,
        &phantom->m_collidable);
      if ( !v7 )
        ((void (__fastcall *)(char *, hkpLinkedCollidable *))(*(hkpShape **)((char *)&collidable->m_shape
                                                                           + collidable->m_ownerOffset))[2].vfptr)(
          (char *)collidable + collidable->m_ownerOffset,
          &phantom->m_collidable);
    }
  }
  else
  {
    if ( v6 )
      phantom->vfptr[5].__vecDelDtor(phantom, (unsigned int)collidable);
    if ( collidable->m_broadPhaseHandle.m_type == 2 )
    {
      (*(void (__fastcall **)(char *, char *, hkpLinkedCollidable *))&(*(hkpShape **)((char *)&collidable->m_shape
                                                                                    + collidable->m_ownerOffset))[2].m_memSizeAndFlags)(
        (char *)collidable + collidable->m_ownerOffset,
        &v7,
        &phantom->m_collidable);
      if ( v7 )
        (*(void (__fastcall **)(char *, hkpLinkedCollidable *))&(*(hkpShape **)((char *)&collidable->m_shape
                                                                              + collidable->m_ownerOffset))[2].m_type.m_storage)(
          (char *)collidable + collidable->m_ownerOffset,
          &phantom->m_collidable);
    }
  }
}

// File Line: 515
// RVA: 0xD59B60
void __fastcall hkpWorld::updateCollisionFilterOnPhantom(
        hkpWorld *this,
        hkpPhantom *phantom,
        hkpUpdateCollectionFilterMode updateShapeCollectionFilter)
{
  _QWORD *Value; // rax
  unsigned __int64 v7; // rcx
  _QWORD *v8; // r8
  unsigned __int64 v9; // rax
  int m_broadPhaseQuerySize; // edi
  hkLifoAllocator *v11; // rcx
  char *m_cur; // rax
  int v13; // edx
  char *v14; // r8
  hkpBroadPhase *m_broadPhase; // rcx
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx
  int v20; // edx
  int v21; // edi
  __int64 v22; // rsi
  __int64 v23; // rcx
  unsigned __int64 v24; // rdx
  _QWORD *v25; // r8
  _QWORD *v26; // rcx
  unsigned __int64 v27; // rax
  _QWORD *v28; // rcx
  bool v29; // zf
  _QWORD *v30; // r8
  _QWORD *v31; // rcx
  unsigned __int64 v32; // rax
  _QWORD *v33; // rcx
  int v34; // eax
  char *v35; // rdi
  signed int v36; // ebx
  hkLifoAllocator *v37; // rax
  int v38; // r8d
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-48h] BYREF
  hkpPhantom *v40; // [rsp+28h] [rbp-40h]
  char v41; // [rsp+30h] [rbp-38h]
  char *v42; // [rsp+38h] [rbp-30h] BYREF
  int v43; // [rsp+40h] [rbp-28h]
  int v44; // [rsp+44h] [rbp-24h]
  void *p; // [rsp+48h] [rbp-20h]
  int v46; // [rsp+50h] [rbp-18h]

  if ( this->m_criticalOperationsLockCount )
  {
    v40 = phantom;
    operation.m_type.m_storage = 21;
    v41 = updateShapeCollectionFilter;
    hkpWorld::queueOperation(this, &operation);
  }
  else
  {
    this->m_criticalOperationsLockCount = 1;
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v7 = Value[1];
    v8 = Value;
    if ( v7 < Value[3] )
    {
      *(_QWORD *)v7 = "LtUpdateFilterOnPhantom";
      *(_QWORD *)(v7 + 16) = "Stbroadphase";
      v9 = __rdtsc();
      *(_DWORD *)(v7 + 8) = v9;
      v8[1] = v7 + 24;
    }
    m_broadPhaseQuerySize = this->m_broadPhaseQuerySize;
    v44 = 0x80000000;
    v42 = 0i64;
    v43 = 0;
    v46 = m_broadPhaseQuerySize;
    if ( m_broadPhaseQuerySize )
    {
      v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (char *)v11->m_cur;
      v13 = (16 * m_broadPhaseQuerySize + 127) & 0xFFFFFF80;
      v14 = &m_cur[v13];
      if ( v13 > v11->m_slabSize || v14 > v11->m_end )
        m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(v11, v13);
      else
        v11->m_cur = v14;
    }
    else
    {
      m_cur = 0i64;
    }
    m_broadPhase = this->m_broadPhase;
    v42 = m_cur;
    p = m_cur;
    v44 = m_broadPhaseQuerySize | 0x80000000;
    ((void (__fastcall *)(hkpBroadPhase *, hkpTypedBroadPhaseHandle *, char **))m_broadPhase->vfptr[9].__first_virtual_table_function__)(
      m_broadPhase,
      &phantom->m_collidable.m_broadPhaseHandle,
      &v42);
    v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v17 = (_QWORD *)v16[1];
    if ( (unsigned __int64)v17 < v16[3] )
    {
      *v17 = "StUpdateOverlaps";
      v18 = __rdtsc();
      v19 = v17 + 2;
      *((_DWORD *)v19 - 2) = v18;
      v16[1] = v19;
    }
    v20 = v43;
    v21 = 0;
    if ( v43 > 0 )
    {
      v22 = 0i64;
      do
      {
        v23 = *(_QWORD *)&v42[v22 + 8];
        if ( (hkpTypedBroadPhaseHandle *)v23 != &phantom->m_collidable.m_broadPhaseHandle )
        {
          hkWorld_updateFilterOnSinglePhantom(
            phantom,
            (hkpCollidable *)(v23 + *(char *)(v23 + 5)),
            this->m_collisionFilter);
          v20 = v43;
        }
        ++v21;
        v22 += 16i64;
      }
      while ( v21 < v20 );
    }
    if ( updateShapeCollectionFilter )
    {
      v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v26 = (_QWORD *)v25[1];
      if ( (unsigned __int64)v26 < v25[3] )
      {
        *v26 = "StcollectionFilter";
        v27 = __rdtsc();
        v24 = (unsigned __int64)HIDWORD(v27) << 32;
        v28 = v26 + 2;
        *((_DWORD *)v28 - 2) = v27;
        v25[1] = v28;
      }
      ((void (__fastcall *)(hkpPhantom *, unsigned __int64, _QWORD *))phantom->vfptr[6].__first_virtual_table_function__)(
        phantom,
        v24,
        v25);
    }
    v29 = this->m_criticalOperationsLockCount-- == 1;
    if ( v29 && !this->m_blockExecutingPendingOperations.m_bool )
    {
      if ( this->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(this);
      if ( this->m_pendingOperationQueueCount == 1 && this->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(this);
    }
    v30 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v31 = (_QWORD *)v30[1];
    if ( (unsigned __int64)v31 < v30[3] )
    {
      *v31 = "lt";
      v32 = __rdtsc();
      v33 = v31 + 2;
      *((_DWORD *)v33 - 2) = v32;
      v30[1] = v33;
    }
    v34 = v43;
    v35 = (char *)p;
    if ( p == v42 )
      v34 = 0;
    v43 = v34;
    v36 = (16 * v46 + 127) & 0xFFFFFF80;
    v37 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v38 = (v36 + 15) & 0xFFFFFFF0;
    if ( v36 > v37->m_slabSize || &v35[v38] != v37->m_cur || v37->m_firstNonLifoEnd == v35 )
      hkLifoAllocator::slowBlockFree(v37, v35, v38);
    else
      v37->m_cur = v35;
    v43 = 0;
    if ( v44 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v42, 16 * v44);
  }
}

// File Line: 568
// RVA: 0xD59A70
void __fastcall hkpWorld::reenableCollisionBetweenEntityPair(hkpWorld *this, hkpEntity *entityA, hkpEntity *entityB)
{
  hkpTypedBroadPhaseHandle *p_m_broadPhaseHandle; // rbp
  hkpTypedBroadPhaseHandle *v7; // r14
  hkpCollidableCollidableFilter *m_collisionFilter; // r9
  hkpTypedBroadPhaseHandlePair newPairs; // [rsp+20h] [rbp-48h] BYREF
  hkWorldOperation::BaseOperation operation; // [rsp+30h] [rbp-38h] BYREF
  hkpEntity *v11; // [rsp+38h] [rbp-30h]
  hkpEntity *v12; // [rsp+40h] [rbp-28h]
  char v13; // [rsp+70h] [rbp+8h] BYREF

  if ( this->m_criticalOperationsLockCount )
  {
    v11 = entityA;
    operation.m_type.m_storage = 20;
    v12 = entityB;
    hkpWorld::queueOperation(this, &operation);
  }
  else
  {
    p_m_broadPhaseHandle = &entityB->m_collidable.m_broadPhaseHandle;
    v7 = &entityA->m_collidable.m_broadPhaseHandle;
    if ( ((unsigned __int8 (__fastcall *)(hkpBroadPhase *, hkpTypedBroadPhaseHandle *, hkpTypedBroadPhaseHandle *))this->m_broadPhase->vfptr[10].__first_virtual_table_function__)(
           this->m_broadPhase,
           &entityA->m_collidable.m_broadPhaseHandle,
           &entityB->m_collidable.m_broadPhaseHandle)
      && this->m_collisionFilter->vfptr->isCollisionEnabled(
           &this->m_collisionFilter->hkpCollidableCollidableFilter,
           &v13,
           &entityA->m_collidable,
           &entityB->m_collidable)->m_bool
      && !hkAgentNnMachine_FindAgent(&entityA->m_collidable, &entityB->m_collidable) )
    {
      m_collisionFilter = (hkpCollidableCollidableFilter *)this->m_collisionFilter;
      newPairs.m_a = v7;
      newPairs.m_b = p_m_broadPhaseHandle;
      if ( m_collisionFilter )
        m_collisionFilter += 2;
      hkpTypedBroadPhaseDispatcher::addPairs(this->m_broadPhaseDispatcher, &newPairs, 1, m_collisionFilter);
    }
  }
}

// File Line: 612
// RVA: 0xD59430
void __fastcall hkpWorld::updateCollisionFilterOnEntity(
        hkpWorld *this,
        hkpEntity *entity,
        hkpUpdateCollisionFilterOnEntityMode updateMode,
        hkpUpdateCollectionFilterMode updateShapeCollectionFilter)
{
  _QWORD *Value; // r8
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // rax
  int m_capacityAndFlags; // r15d
  _QWORD *v12; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  _QWORD *v15; // rcx
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx
  int m_size; // edx
  int v21; // edi
  __int64 v22; // rsi
  char *v23; // rax
  hkpPhantom *v24; // rbx
  __int64 v25; // r8
  __int64 v26; // rdx
  hkpBroadPhaseHandlePair *v27; // rcx
  __int64 v28; // r8
  hkpBroadPhaseHandle *v29; // rax
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *CollisionEntriesDeterministicUnchecked; // rax
  int v31; // ecx
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *v32; // rdi
  int v33; // esi
  __int64 v34; // rbx
  __int64 v35; // rdx
  hkpAgentNnEntry *m_agentEntry; // rcx
  hkpBroadPhaseHandlePair *v37; // rdx
  _QWORD *v38; // r8
  _QWORD *v39; // rcx
  unsigned __int64 v40; // rax
  _QWORD *v41; // rcx
  __int64 m_objectQualityType; // r12
  int v43; // edi
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *v44; // r15
  __int64 v45; // rbx
  hkpLinkedCollidable::CollisionEntry *v46; // rsi
  hkpLinkedCollidable *m_partner; // r8
  __int64 v48; // rdx
  hkpCollisionDispatcher *m_collisionDispatcher; // rax
  int v50; // ecx
  hkpBroadPhaseHandlePair *v51; // rdx
  _QWORD *v52; // r8
  _QWORD *v53; // rcx
  unsigned __int64 v54; // rax
  _QWORD *v55; // rcx
  hkpCollisionFilter *m_collisionFilter; // rax
  hkpCollidableCollidableFilter *v57; // r9
  bool v58; // zf
  _QWORD *v59; // r8
  _QWORD *v60; // rcx
  unsigned __int64 v61; // rax
  _QWORD *v62; // rcx
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-E0h] BYREF
  hkpEntity *v64; // [rsp+28h] [rbp-D8h]
  char v65; // [rsp+30h] [rbp-D0h]
  char v66; // [rsp+31h] [rbp-CFh]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> delPairs; // [rsp+40h] [rbp-C0h] BYREF
  char v68; // [rsp+50h] [rbp-B0h] BYREF
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> array; // [rsp+850h] [rbp+750h] BYREF
  char v70; // [rsp+860h] [rbp+760h] BYREF
  char v71; // [rsp+10A0h] [rbp+FA0h] BYREF
  hkpUpdateCollectionFilterMode v72; // [rsp+10B8h] [rbp+FB8h]

  v72 = updateShapeCollectionFilter;
  if ( this->m_criticalOperationsLockCount )
  {
    v64 = entity;
    operation.m_type.m_storage = 19;
    v65 = updateMode;
    v66 = updateShapeCollectionFilter;
    hkpWorld::queueOperation(this, &operation);
    return;
  }
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = Value[1];
  if ( v9 < Value[3] )
  {
    *(_QWORD *)v9 = "LtUpdateFilterOnEntity";
    *(_QWORD *)(v9 + 16) = "Stinit";
    v10 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v10;
    Value[1] = v9 + 24;
  }
  ++this->m_criticalOperationsLockCount;
  if ( entity->m_motion.m_type.m_storage == 5 )
    hkpLinkedCollidable::sortEntries(&entity->m_collidable);
  m_capacityAndFlags = -2147483520;
  delPairs.m_size = 0;
  delPairs.m_data = (hkpBroadPhaseHandlePair *)&v68;
  delPairs.m_capacityAndFlags = -2147483520;
  if ( updateMode == HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK )
  {
    v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v13 = (_QWORD *)v12[1];
    if ( (unsigned __int64)v13 < v12[3] )
    {
      *v13 = "Stbroadphase";
      v14 = __rdtsc();
      v15 = v13 + 2;
      *((_DWORD *)v15 - 2) = v14;
      v12[1] = v15;
    }
    ((void (__fastcall *)(hkpBroadPhase *, hkpTypedBroadPhaseHandle *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))this->m_broadPhase->vfptr[9].__first_virtual_table_function__)(
      this->m_broadPhase,
      &entity->m_collidable.m_broadPhaseHandle,
      &delPairs);
    v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v17 = (_QWORD *)v16[1];
    if ( (unsigned __int64)v17 < v16[3] )
    {
      *v17 = "Stphantom";
      v18 = __rdtsc();
      v19 = v17 + 2;
      *((_DWORD *)v19 - 2) = v18;
      v16[1] = v19;
    }
    m_size = delPairs.m_size;
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
            hkWorld_updateFilterOnSinglePhantom(v24, &entity->m_collidable, this->m_collisionFilter);
            if ( updateShapeCollectionFilter )
              v24->vfptr[6].__first_virtual_table_function__(v24);
            m_size = delPairs.m_size - 1;
            delPairs.m_size = m_size;
            if ( m_size != v21 )
            {
              v25 = m_size;
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
              m_size = delPairs.m_size;
            }
            --v21;
            --v22;
          }
        }
        ++v21;
        ++v22;
      }
      while ( v21 < m_size );
    }
    CollisionEntriesDeterministicUnchecked = hkpLinkedCollidable::getCollisionEntriesDeterministicUnchecked(&entity->m_collidable);
    v31 = 0;
    array.m_capacityAndFlags = -2147483520;
    v32 = CollisionEntriesDeterministicUnchecked;
    array.m_size = 0;
    array.m_data = (hkpBroadPhaseHandlePair *)&v70;
    v33 = 0;
    if ( CollisionEntriesDeterministicUnchecked->m_size > 0 )
    {
      v34 = 0i64;
      while ( 1 )
      {
        if ( v31 == (m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 16);
          v31 = array.m_size;
        }
        ++v33;
        array.m_size = v31 + 1;
        v35 = v31;
        m_agentEntry = v32->m_data[v34].m_agentEntry;
        v37 = &array.m_data[v35];
        ++v34;
        v37->m_a = &m_agentEntry->m_collidable[0]->m_broadPhaseHandle;
        v37->m_b = &v32->m_data[v34 - 1].m_agentEntry->m_collidable[1]->m_broadPhaseHandle;
        if ( v33 >= v32->m_size )
          break;
        m_capacityAndFlags = array.m_capacityAndFlags;
        v31 = array.m_size;
      }
    }
    hkpTypedBroadPhaseDispatcher::removeDuplicates(&array, &delPairs);
    array.m_size = 0;
    if ( array.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        array.m_data,
        16 * array.m_capacityAndFlags);
  }
  v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v39 = (_QWORD *)v38[1];
  if ( (unsigned __int64)v39 < v38[3] )
  {
    *v39 = "StcheckAgts";
    v40 = __rdtsc();
    v41 = v39 + 2;
    *((_DWORD *)v41 - 2) = v40;
    v38[1] = v41;
  }
  m_objectQualityType = entity->m_collidable.m_broadPhaseHandle.m_objectQualityType;
  v43 = 0;
  v44 = hkpLinkedCollidable::getCollisionEntriesDeterministicUnchecked(&entity->m_collidable);
  if ( v44->m_size > 0 )
  {
    v45 = 0i64;
    do
    {
      v46 = &v44->m_data[v45];
      if ( this->m_collisionFilter->vfptr->isCollisionEnabled(
             &this->m_collisionFilter->hkpCollidableCollidableFilter,
             &v71,
             &entity->m_collidable,
             v46->m_partner)->m_bool )
      {
        m_partner = v46->m_partner;
        v48 = m_partner->m_broadPhaseHandle.m_objectQualityType + 10 * m_objectQualityType;
        m_collisionDispatcher = this->m_collisionDispatcher;
        if ( m_collisionDispatcher->m_collisionQualityTable[0][v48] )
        {
          if ( m_collisionDispatcher->m_collisionQualityTable[0][v48] == (unsigned __int8)v46->m_agentEntry->m_collisionQualityIndex )
          {
            if ( v72 == HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS )
            {
              if ( entity->m_motion.m_type.m_storage == 5 )
                hkAgentNnMachine_UpdateShapeCollectionFilter(
                  v46->m_agentEntry,
                  this->m_collisionInput,
                  *(hkpConstraintOwner **)(&m_partner[2].m_broadPhaseHandle.m_type + m_partner->m_ownerOffset));
              else
                hkAgentNnMachine_UpdateShapeCollectionFilter(
                  v46->m_agentEntry,
                  this->m_collisionInput,
                  entity->m_simulationIsland);
            }
            goto LABEL_43;
          }
          v50 = delPairs.m_size;
          if ( delPairs.m_size == (delPairs.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&delPairs.m_data, 16);
            v50 = delPairs.m_size;
          }
          delPairs.m_size = v50 + 1;
          v51 = &delPairs.m_data[v50];
          v51->m_a = &v44->m_data[v45].m_agentEntry->m_collidable[0]->m_broadPhaseHandle;
          v51->m_b = &v44->m_data[v45].m_agentEntry->m_collidable[1]->m_broadPhaseHandle;
        }
      }
      hkpWorldAgentUtil::removeAgentAndItsToiEvents(v46->m_agentEntry);
      --v43;
      --v45;
      *((_BYTE *)entity->m_simulationIsland + 49) = *((_BYTE *)entity->m_simulationIsland + 49) & 0xFC | 1;
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
      v55 = v53 + 2;
      *((_DWORD *)v55 - 2) = v54;
      v52[1] = v55;
    }
    m_collisionFilter = this->m_collisionFilter;
    if ( m_collisionFilter )
      v57 = &m_collisionFilter->hkpCollidableCollidableFilter;
    else
      v57 = 0i64;
    hkpTypedBroadPhaseDispatcher::addPairs(
      this->m_broadPhaseDispatcher,
      (hkpTypedBroadPhaseHandlePair *)delPairs.m_data,
      delPairs.m_size,
      v57);
  }
  v58 = this->m_criticalOperationsLockCount-- == 1;
  if ( v58 && !this->m_blockExecutingPendingOperations.m_bool )
  {
    if ( this->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(this);
    if ( this->m_pendingOperationQueueCount == 1 && this->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(this);
  }
  delPairs.m_size = 0;
  if ( delPairs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      delPairs.m_data,
      16 * delPairs.m_capacityAndFlags);
  v59 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v60 = (_QWORD *)v59[1];
  if ( (unsigned __int64)v60 < v59[3] )
  {
    *v60 = "lt";
    v61 = __rdtsc();
    v62 = v60 + 2;
    *((_DWORD *)v62 - 2) = v61;
    v59[1] = v62;
  }
}

// File Line: 794
// RVA: 0xD5A370
void __fastcall hkpWorld::reintegrateAndRecollideEntities(
        hkpWorld *this,
        hkpEntity **entityBatch,
        __int64 numEntities,
        hkpWorld::ReintegrationRecollideMode mode)
{
  hkWorldOperation::BaseOperation operation; // [rsp+30h] [rbp-28h] BYREF
  hkpEntity **v5; // [rsp+38h] [rbp-20h]
  __int16 v6; // [rsp+40h] [rbp-18h]
  char v7; // [rsp+42h] [rbp-16h]

  if ( this->m_criticalOperationsLockCount )
  {
    v5 = entityBatch;
    operation.m_type.m_storage = 24;
    v6 = numEntities;
    v7 = mode;
    hkpWorld::queueOperation(this, &operation);
  }
  else
  {
    ((void (__fastcall *)(hkpSimulation *, hkpEntity **, __int64, hkpWorld *, _BYTE))this->m_simulation->vfptr[8].__vecDelDtor)(
      this->m_simulation,
      entityBatch,
      numEntities,
      this,
      mode);
  }
}

// File Line: 813
// RVA: 0xD56FC0
hkpEntity *__fastcall hkpWorld::addEntity(
        hkpWorld *this,
        hkpEntity *entity,
        hkpEntityActivation initialActivationState)
{
  __int16 v7; // dx
  __int16 v8; // r8
  __int16 v9; // r8
  bool v10; // zf
  hkSimdFloat32 startTime; // [rsp+20h] [rbp-38h] BYREF
  hkWorldOperation::BaseOperation operation; // [rsp+30h] [rbp-28h] BYREF
  hkpEntity *v13; // [rsp+38h] [rbp-20h]
  hkpEntityActivation v14; // [rsp+40h] [rbp-18h]

  if ( this->m_criticalOperationsLockCount )
  {
    v13 = entity;
    operation.m_type.m_storage = 1;
    v14 = initialActivationState;
    hkpWorld::queueOperation(this, &operation);
    return 0i64;
  }
  else
  {
    hkpEntity::setCachedShapeData(entity, this, entity->m_collidable.m_shape);
    if ( !entity->m_collidable.m_motion )
      entity->m_collidable.m_motion = (const void *)((__int64 (__fastcall *)(hkpEntity *))entity->vfptr[2].__first_virtual_table_function__)(entity);
    startTime.m_real = 0i64;
    hkSweptTransformUtil::setTimeInformation(&startTime, &startTime, &entity->m_motion.m_motionState);
    *(_DWORD *)entity->m_motion.m_deactivationNumInactiveFrames = 0;
    ++this->m_lastEntityUid;
    this->m_criticalOperationsAllowed.m_bool = 0;
    entity->m_uid = this->m_lastEntityUid;
    hkReferencedObject::addReference(entity);
    hkpWorldOperationUtil::addEntitySI(this, entity, initialActivationState);
    v7 = (unsigned __int8)this->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1];
    v8 = (unsigned __int8)this->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0];
    if ( (unsigned __int8)(this->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter & 3) < (unsigned __int8)(entity->m_motion.m_deactivationIntegrateCounter & 3) )
      v8 = ~v8;
    v9 = v8 << 14;
    if ( (unsigned __int8)this->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter < (int)(unsigned __int8)entity->m_motion.m_deactivationIntegrateCounter )
      v7 = ~v7;
    entity->m_motion.m_deactivationNumInactiveFrames[1] &= 0x3FFFu;
    entity->m_motion.m_deactivationNumInactiveFrames[1] |= v7 << 14;
    entity->m_motion.m_deactivationNumInactiveFrames[0] &= 0x3FFFu;
    entity->m_motion.m_deactivationNumInactiveFrames[0] |= v9;
    ++this->m_criticalOperationsLockCount;
    this->m_criticalOperationsAllowed.m_bool = 1;
    hkpWorldOperationUtil::addEntityBP(this, entity);
    hkpWorldCallbackUtil::fireEntityAdded(this, entity);
    hkpEntityCallbackUtil::fireEntityAdded(entity);
    v10 = this->m_criticalOperationsLockCount-- == 1;
    if ( v10 && !this->m_blockExecutingPendingOperations.m_bool )
    {
      if ( this->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(this);
      if ( this->m_pendingOperationQueueCount == 1 )
      {
        if ( this->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(this);
      }
    }
    return entity;
  }
}

// File Line: 927
// RVA: 0xD57280
void __fastcall hkpWorld::addEntityBatch(
        hkpWorld *this,
        hkpEntity *const *entityBatch,
        unsigned int numEntities,
        hkpEntityActivation initialActivationState)
{
  __int64 v5; // r15
  _QWORD *Value; // r8
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD **v11; // rax
  hkpSimulationIsland *v12; // rax
  hkpSimulationIsland *v13; // rax
  hkpSimulationIsland *v14; // rsi
  unsigned __int16 m_size; // ax
  int v16; // eax
  int v17; // r9d
  int v18; // eax
  hkpEntity *const *v19; // r12
  __int64 v20; // r14
  hkpEntity *v21; // rbx
  hkpShape *m_shape; // r13
  __int16 v23; // dx
  __int16 v24; // r8
  __int16 v25; // r8
  hkpSimulationIsland *m_fixedIsland; // rcx
  __int64 v27; // r8
  __int64 v28; // r9
  hkpEntity *const *v29; // r14
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *p_m_activeSimulationIslands; // rbx
  int m_broadPhaseQuerySize; // ebx
  hkLifoAllocator *v32; // rcx
  hkpTypedBroadPhaseHandlePair *m_cur; // rax
  int v34; // edx
  char *v35; // r8
  _QWORD *v36; // rax
  _QWORD *v37; // rcx
  _QWORD *v38; // r8
  unsigned __int64 v39; // rax
  _QWORD *v40; // rcx
  _QWORD *v41; // r8
  _QWORD *v42; // rcx
  unsigned __int64 v43; // rax
  _QWORD *v44; // rcx
  hkpCollisionFilter *m_collisionFilter; // rax
  hkpCollidableCollidableFilter *v46; // r9
  _QWORD *v47; // r8
  _QWORD *v48; // rcx
  unsigned __int64 v49; // rax
  _QWORD *v50; // rcx
  __int64 v51; // rsi
  hkpEntity *v52; // rbx
  bool v53; // zf
  _QWORD *v54; // r8
  _QWORD *v55; // rcx
  unsigned __int64 v56; // rax
  _QWORD *v57; // rcx
  int v58; // eax
  char *v59; // rdi
  signed int v60; // ebx
  hkLifoAllocator *v61; // rax
  int v62; // r8d
  char v63; // [rsp+30h] [rbp-59h]
  hkResult result; // [rsp+34h] [rbp-55h] BYREF
  char *v65; // [rsp+38h] [rbp-51h] BYREF
  int v66; // [rsp+40h] [rbp-49h]
  int v67; // [rsp+44h] [rbp-45h]
  _QWORD *array; // [rsp+48h] [rbp-41h] BYREF
  int v69; // [rsp+50h] [rbp-39h]
  int v70; // [rsp+54h] [rbp-35h]
  hkWorldOperation::BaseOperation operation[16]; // [rsp+60h] [rbp-29h] BYREF
  __int16 v72; // [rsp+70h] [rbp-19h]
  char v73; // [rsp+72h] [rbp-17h]
  hkpTypedBroadPhaseHandlePair *newPairs; // [rsp+80h] [rbp-9h] BYREF
  int numNewPairs; // [rsp+88h] [rbp-1h]
  int v76; // [rsp+8Ch] [rbp+3h]
  void *p; // [rsp+90h] [rbp+7h]
  int v78; // [rsp+98h] [rbp+Fh]

  if ( (int)numEntities > 0 )
  {
    v5 = numEntities;
    if ( this->m_criticalOperationsLockCount )
    {
      *(_QWORD *)&operation[8].m_type.m_storage = entityBatch;
      operation[0].m_type.m_storage = 7;
      v72 = numEntities;
      v73 = initialActivationState;
      hkpWorld::queueOperation(this, operation);
    }
    else
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v9 = Value[1];
      if ( v9 < Value[3] )
      {
        *(_QWORD *)v9 = "LtAddEntities";
        *(_QWORD *)(v9 + 16) = "Stinit";
        v10 = __rdtsc();
        *(_DWORD *)(v9 + 8) = v10;
        Value[1] = v9 + 24;
      }
      ++this->m_criticalOperationsLockCount;
      v70 = 0x80000000;
      array = 0i64;
      v69 = 0;
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&array, v5, 8);
      v65 = 0i64;
      v66 = 0;
      v67 = 0x80000000;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v65, v5, 32);
      v63 = 0;
      if ( this->m_wantSimulationIslands.m_bool )
      {
        v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v12 = (hkpSimulationIsland *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v11[11] + 8i64))(v11[11], 184i64);
        if ( v12 )
        {
          hkpSimulationIsland::hkpSimulationIsland(v12, this);
          v14 = v13;
        }
        else
        {
          v14 = 0i64;
        }
        *((_BYTE *)v14 + 49) &= ~2u;
        *((_BYTE *)v14 + 49) |= 1u;
        if ( initialActivationState == HK_ENTITY_ACTIVATION_DO_ACTIVATE )
        {
          m_size = this->m_activeSimulationIslands.m_size;
          *((_BYTE *)v14 + 50) &= 0xF5u;
          *((_BYTE *)v14 + 50) |= 5u;
        }
        else
        {
          m_size = this->m_inactiveSimulationIslands.m_size;
          *((_BYTE *)v14 + 50) &= 0xF0u;
        }
        v14->m_storageIndex = m_size;
      }
      else
      {
        v14 = *this->m_activeSimulationIslands.m_data;
        v16 = v14->m_entities.m_capacityAndFlags & 0x3FFFFFFF;
        v17 = v5 + v14->m_entities.m_size;
        if ( v16 < v17 )
        {
          v18 = 2 * v16;
          if ( v17 < v18 )
            v17 = v18;
          hkArrayUtil::_reserve(
            &result,
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&v14->m_entities.m_data,
            v17,
            8);
        }
      }
      *(_OWORD *)&operation[0].m_type.m_storage = 0i64;
      v19 = entityBatch;
      v20 = v5;
      do
      {
        v21 = *v19;
        m_shape = (*v19)->m_collidable.m_shape;
        v21->m_uid = ++this->m_lastEntityUid;
        hkReferencedObject::addReference(v21);
        if ( !v21->m_collidable.m_motion )
          v21->m_collidable.m_motion = (const void *)((__int64 (__fastcall *)(hkpEntity *))v21->vfptr[2].__first_virtual_table_function__)(v21);
        hkSweptTransformUtil::setTimeInformation(
          (hkSimdFloat32 *)operation,
          (hkSimdFloat32 *)operation,
          &v21->m_motion.m_motionState);
        *(_DWORD *)v21->m_motion.m_deactivationNumInactiveFrames = 0;
        v21->m_world = this;
        v23 = (unsigned __int8)this->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1];
        v24 = (unsigned __int8)this->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0];
        if ( (unsigned __int8)(this->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter & 3) < (unsigned __int8)(v21->m_motion.m_deactivationIntegrateCounter & 3) )
          v24 = ~v24;
        v25 = v24 << 14;
        if ( (unsigned __int8)this->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter < (int)(unsigned __int8)v21->m_motion.m_deactivationIntegrateCounter )
          v23 = ~v23;
        v21->m_motion.m_deactivationNumInactiveFrames[0] &= 0x3FFFu;
        v21->m_motion.m_deactivationNumInactiveFrames[1] &= 0x3FFFu;
        v21->m_motion.m_deactivationNumInactiveFrames[1] |= v23 << 14;
        v21->m_motion.m_deactivationNumInactiveFrames[0] |= v25;
        if ( v21->m_motion.m_type.m_storage == 5 )
        {
          m_fixedIsland = this->m_fixedIsland;
        }
        else
        {
          v63 = 1;
          m_fixedIsland = v14;
        }
        hkpSimulationIsland::internalAddEntity(m_fixedIsland, v21);
        v21->m_collidable.m_boundingVolumeData.m_min[0] = 1;
        v21->m_collidable.m_boundingVolumeData.m_max[0] = 0;
        if ( m_shape )
        {
          v28 = v66++;
          ((void (__fastcall *)(hkpShape *, const void *, __int64, char *))v21->m_collidable.m_shape->hkpWorldObject::vfptr[2].__vecDelDtor)(
            v21->m_collidable.m_shape,
            v21->m_collidable.m_motion,
            v27,
            &v65[32 * v28]);
          array[v69++] = &v21->m_collidable.m_broadPhaseHandle;
          hkpEntity::setCachedShapeData(v21, this, m_shape);
        }
        ++v19;
        --v20;
      }
      while ( v20 );
      v29 = entityBatch;
      if ( this->m_wantSimulationIslands.m_bool )
      {
        if ( v63 )
        {
          p_m_activeSimulationIslands = &this->m_activeSimulationIslands;
          v14->m_splitCheckFrameCounter = (*v14->m_entities.m_data)->m_uid;
          if ( initialActivationState != HK_ENTITY_ACTIVATION_DO_ACTIVATE )
            p_m_activeSimulationIslands = &this->m_inactiveSimulationIslands;
          if ( p_m_activeSimulationIslands->m_size == (p_m_activeSimulationIslands->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&p_m_activeSimulationIslands->m_data,
              8);
          p_m_activeSimulationIslands->m_data[p_m_activeSimulationIslands->m_size++] = v14;
        }
        else
        {
          ((void (__fastcall *)(hkpSimulationIsland *, __int64, __int64))v14->vfptr->__vecDelDtor)(v14, 1i64, v27);
        }
      }
      m_broadPhaseQuerySize = this->m_broadPhaseQuerySize;
      newPairs = 0i64;
      numNewPairs = 0;
      v76 = 0x80000000;
      v78 = m_broadPhaseQuerySize;
      if ( m_broadPhaseQuerySize )
      {
        v32 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        m_cur = (hkpTypedBroadPhaseHandlePair *)v32->m_cur;
        v34 = (16 * m_broadPhaseQuerySize + 127) & 0xFFFFFF80;
        v35 = (char *)m_cur + v34;
        if ( v34 > v32->m_slabSize || v35 > v32->m_end )
          m_cur = (hkpTypedBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v32, v34);
        else
          v32->m_cur = v35;
      }
      else
      {
        m_cur = 0i64;
      }
      newPairs = m_cur;
      v76 = m_broadPhaseQuerySize | 0x80000000;
      p = m_cur;
      v36 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v37 = (_QWORD *)v36[1];
      v38 = v36;
      if ( (unsigned __int64)v37 < v36[3] )
      {
        *v37 = "StBroadphase";
        v39 = __rdtsc();
        v40 = v37 + 2;
        *((_DWORD *)v40 - 2) = v39;
        v38[1] = v40;
      }
      ((void (__fastcall *)(hkpBroadPhase *, _QWORD **, char **, hkpTypedBroadPhaseHandlePair **))this->m_broadPhase->vfptr[3].__first_virtual_table_function__)(
        this->m_broadPhase,
        &array,
        &v65,
        &newPairs);
      v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v42 = (_QWORD *)v41[1];
      if ( (unsigned __int64)v42 < v41[3] )
      {
        *v42 = "StCreateAgents";
        v43 = __rdtsc();
        v44 = v42 + 2;
        *((_DWORD *)v44 - 2) = v43;
        v41[1] = v44;
      }
      m_collisionFilter = this->m_collisionFilter;
      v46 = &m_collisionFilter->hkpCollidableCollidableFilter;
      if ( !m_collisionFilter )
        v46 = 0i64;
      hkpTypedBroadPhaseDispatcher::addPairs(this->m_broadPhaseDispatcher, newPairs, numNewPairs, v46);
      v47 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v48 = (_QWORD *)v47[1];
      if ( (unsigned __int64)v48 < v47[3] )
      {
        *v48 = "StAddedCb";
        v49 = __rdtsc();
        v50 = v48 + 2;
        *((_DWORD *)v50 - 2) = v49;
        v47[1] = v50;
      }
      if ( (int)numEntities > 0 )
      {
        v51 = numEntities;
        do
        {
          v52 = *v29;
          hkpWorldCallbackUtil::fireEntityAdded(this, *v29);
          hkpEntityCallbackUtil::fireEntityAdded(v52);
          ++v29;
          --v51;
        }
        while ( v51 );
      }
      v53 = this->m_criticalOperationsLockCount-- == 1;
      if ( v53 && !this->m_blockExecutingPendingOperations.m_bool )
      {
        if ( this->m_pendingOperationsCount )
          hkpWorld::internal_executePendingOperations(this);
        if ( this->m_pendingOperationQueueCount == 1 && this->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(this);
      }
      v54 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v55 = (_QWORD *)v54[1];
      if ( (unsigned __int64)v55 < v54[3] )
      {
        *v55 = "lt";
        v56 = __rdtsc();
        v57 = v55 + 2;
        *((_DWORD *)v57 - 2) = v56;
        v54[1] = v57;
      }
      v58 = numNewPairs;
      v59 = (char *)p;
      if ( p == newPairs )
        v58 = 0;
      numNewPairs = v58;
      v60 = (16 * v78 + 127) & 0xFFFFFF80;
      v61 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v62 = (v60 + 15) & 0xFFFFFFF0;
      if ( v60 > v61->m_slabSize || &v59[v62] != v61->m_cur || v61->m_firstNonLifoEnd == v59 )
        hkLifoAllocator::slowBlockFree(v61, v59, v62);
      else
        v61->m_cur = v59;
      numNewPairs = 0;
      if ( v76 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, newPairs, 16 * v76);
      newPairs = 0i64;
      v76 = 0x80000000;
      v66 = 0;
      if ( v67 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v65, 32 * v67);
      v65 = 0i64;
      v69 = 0;
      v67 = 0x80000000;
      if ( v70 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 8 * v70);
    }
  }
}

// File Line: 1093
// RVA: 0xD57170
hkBool *__fastcall hkpWorld::removeEntity(hkpWorld *this, hkBool *result, hkpEntity *entity)
{
  bool v7; // zf
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-18h] BYREF
  hkpEntity *v9; // [rsp+28h] [rbp-10h]

  if ( this->m_criticalOperationsLockCount )
  {
    operation.m_type.m_storage = 2;
    v9 = entity;
    hkpWorld::queueOperation(this, &operation);
    result->m_bool = 0;
    return result;
  }
  else
  {
    this->m_criticalOperationsLockCount = 1;
    hkpWorldOperationUtil::removeEntityBP(this, entity);
    hkpWorldCallbackUtil::fireEntityRemoved(this, entity);
    hkpEntityCallbackUtil::fireEntityRemoved(entity);
    this->m_criticalOperationsAllowed.m_bool = 0;
    hkpWorldOperationUtil::removeEntitySI(this, entity);
    if ( entity->m_collidable.m_boundingVolumeData.m_childShapeAabbs )
      hkpCollidable::BoundingVolumeData::deallocate(&entity->m_collidable.m_boundingVolumeData);
    if ( !entity->m_memSizeAndFlags )
      ((void (__fastcall *)(hkpEntity *))entity->vfptr[3].__vecDelDtor)(entity);
    hkReferencedObject::removeReference(entity);
    v7 = this->m_criticalOperationsLockCount-- == 1;
    this->m_criticalOperationsAllowed.m_bool = 1;
    if ( v7 && !this->m_blockExecutingPendingOperations.m_bool )
    {
      if ( this->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(this);
      if ( this->m_pendingOperationQueueCount == 1 )
      {
        if ( this->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(this);
      }
    }
    result->m_bool = 1;
    return result;
  }
}

// File Line: 1174
// RVA: 0xD57980
void __fastcall hkpWorld::removeEntityBatch(hkpWorld *this, hkpEntity **entityBatch, int numEntities)
{
  __int64 v3; // rdi
  hkpEntity **v4; // rbx
  _QWORD *Value; // rax
  unsigned __int64 v7; // rcx
  _QWORD *v8; // r8
  unsigned __int64 v9; // rax
  int v10; // ecx
  hkpEntity **v11; // r14
  hkpEntity **i; // r8
  _QWORD *v13; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  _QWORD *v16; // rcx
  int m_broadPhaseQuerySize; // edi
  hkLifoAllocator *v18; // rcx
  hkpTypedBroadPhaseHandlePair *m_cur; // rax
  int v20; // edx
  char *v21; // r8
  hkpBroadPhase *m_broadPhase; // rcx
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  _QWORD *v26; // rcx
  int v27; // eax
  char *v28; // r15
  signed int v29; // edi
  hkLifoAllocator *v30; // rax
  int v31; // r8d
  _QWORD *v32; // r8
  _QWORD *v33; // rcx
  unsigned __int64 v34; // rax
  _QWORD *v35; // rcx
  _QWORD *v36; // rax
  _QWORD *v37; // rcx
  _QWORD *v38; // r8
  unsigned __int64 v39; // rax
  _QWORD *v40; // rcx
  bool v41; // zf
  hkWorldOperation::BaseOperation operation[8]; // [rsp+30h] [rbp-48h] BYREF
  hkpEntity *const *v43; // [rsp+38h] [rbp-40h]
  __int16 v44; // [rsp+40h] [rbp-38h]
  hkpTypedBroadPhaseHandlePair *deletedPairs; // [rsp+48h] [rbp-30h] BYREF
  int numDeletedPairs; // [rsp+50h] [rbp-28h]
  int v47; // [rsp+54h] [rbp-24h]
  void *p; // [rsp+58h] [rbp-20h]
  int v49; // [rsp+60h] [rbp-18h]
  hkResult result; // [rsp+B0h] [rbp+38h] BYREF

  if ( numEntities > 0 )
  {
    v3 = numEntities;
    v4 = entityBatch;
    if ( this->m_criticalOperationsLockCount )
    {
      v43 = entityBatch;
      operation[0].m_type.m_storage = 8;
      v44 = numEntities;
      hkpWorld::queueOperation(this, operation);
    }
    else
    {
      this->m_criticalOperationsLockCount = 1;
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v7 = Value[1];
      v8 = Value;
      if ( v7 < Value[3] )
      {
        *(_QWORD *)v7 = "LtRemEntities";
        *(_QWORD *)(v7 + 16) = "StInit+CallBck";
        v9 = __rdtsc();
        *(_DWORD *)(v7 + 8) = v9;
        v8[1] = v7 + 24;
      }
      ((void (__fastcall *)(hkpSimulation *, hkpEntity **, _QWORD, hkpWorld *, int))this->m_simulation->vfptr[6].__vecDelDtor)(
        this->m_simulation,
        v4,
        (unsigned int)v3,
        this,
        1);
      *(_QWORD *)&operation[0].m_type.m_storage = 0i64;
      v43 = (hkpEntity *const *)0x8000000000000000i64;
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)operation, v3, 8);
      v10 = (int)v43;
      v11 = &v4[v3];
      for ( i = v4; i != v11; ++i )
      {
        if ( (*i)->m_collidable.m_shape )
        {
          *(_QWORD *)(*(_QWORD *)&operation[0].m_type.m_storage + 8i64 * v10) = &(*i)->m_collidable.m_broadPhaseHandle;
          v10 = (_DWORD)v43 + 1;
          LODWORD(v43) = (_DWORD)v43 + 1;
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
          v16 = v14 + 2;
          *((_DWORD *)v16 - 2) = v15;
          v13[1] = v16;
        }
        m_broadPhaseQuerySize = this->m_broadPhaseQuerySize;
        deletedPairs = 0i64;
        numDeletedPairs = 0;
        v47 = 0x80000000;
        v49 = m_broadPhaseQuerySize;
        if ( m_broadPhaseQuerySize )
        {
          v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          m_cur = (hkpTypedBroadPhaseHandlePair *)v18->m_cur;
          v20 = (16 * m_broadPhaseQuerySize + 127) & 0xFFFFFF80;
          v21 = (char *)m_cur + v20;
          if ( v20 > v18->m_slabSize || v21 > v18->m_end )
            m_cur = (hkpTypedBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v18, v20);
          else
            v18->m_cur = v21;
        }
        else
        {
          m_cur = 0i64;
        }
        m_broadPhase = this->m_broadPhase;
        deletedPairs = m_cur;
        p = m_cur;
        v47 = m_broadPhaseQuerySize | 0x80000000;
        ((void (__fastcall *)(hkpBroadPhase *, hkWorldOperation::BaseOperation *, hkpTypedBroadPhaseHandlePair **))m_broadPhase->vfptr[4].__first_virtual_table_function__)(
          m_broadPhase,
          operation,
          &deletedPairs);
        v23 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v24 = (_QWORD *)v23[1];
        if ( (unsigned __int64)v24 < v23[3] )
        {
          *v24 = "StDelAgents";
          v25 = __rdtsc();
          v26 = v24 + 2;
          *((_DWORD *)v26 - 2) = v25;
          v23[1] = v26;
        }
        hkpTypedBroadPhaseDispatcher::removePairs(this->m_broadPhaseDispatcher, deletedPairs, numDeletedPairs);
        v27 = numDeletedPairs;
        v28 = (char *)p;
        if ( p == deletedPairs )
          v27 = 0;
        numDeletedPairs = v27;
        v29 = (16 * v49 + 127) & 0xFFFFFF80;
        v30 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v31 = (v29 + 15) & 0xFFFFFFF0;
        if ( v29 > v30->m_slabSize || &v28[v31] != v30->m_cur || v30->m_firstNonLifoEnd == v28 )
          hkLifoAllocator::slowBlockFree(v30, v28, v31);
        else
          v30->m_cur = v28;
        numDeletedPairs = 0;
        if ( v47 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, deletedPairs, 16 * v47);
      }
      LODWORD(v43) = 0;
      if ( SHIDWORD(v43) >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          *(void **)&operation[0].m_type.m_storage,
          8 * HIDWORD(v43));
      v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v33 = (_QWORD *)v32[1];
      if ( (unsigned __int64)v33 < v32[3] )
      {
        *v33 = "StRemoveCb";
        v34 = __rdtsc();
        v35 = v33 + 2;
        *((_DWORD *)v35 - 2) = v34;
        v32[1] = v35;
      }
      for ( ; v4 != v11; ++v4 )
      {
        hkpWorldCallbackUtil::fireEntityRemoved(this, *v4);
        hkpEntityCallbackUtil::fireEntityRemoved(*v4);
        hkpWorldOperationUtil::removeEntitySI(this, *v4);
        if ( (*v4)->m_collidable.m_boundingVolumeData.m_childShapeAabbs )
          hkpCollidable::BoundingVolumeData::deallocate(&(*v4)->m_collidable.m_boundingVolumeData);
        if ( !(*v4)->m_memSizeAndFlags )
          ((void (__fastcall *)(hkpEntity *))(*v4)->vfptr[3].__vecDelDtor)(*v4);
        hkReferencedObject::removeReference(*v4);
      }
      v36 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v37 = (_QWORD *)v36[1];
      v38 = v36;
      if ( (unsigned __int64)v37 < v36[3] )
      {
        *v37 = "lt";
        v39 = __rdtsc();
        v40 = v37 + 2;
        *((_DWORD *)v40 - 2) = v39;
        v38[1] = v40;
      }
      v41 = this->m_criticalOperationsLockCount-- == 1;
      if ( v41 && !this->m_blockExecutingPendingOperations.m_bool )
      {
        if ( this->m_pendingOperationsCount )
          hkpWorld::internal_executePendingOperations(this);
        if ( this->m_pendingOperationQueueCount == 1 )
        {
          if ( this->m_pendingBodyOperationsCount )
            hkpWorld::internal_executePendingBodyOperations(this);
        }
      }
    }
  }
}

// File Line: 1266
// RVA: 0xD58FB0
void __fastcall hkpWorld::activateRegion(hkpWorld *this, hkAabb *aabb)
{
  _QWORD **Value; // rax
  hkpBroadPhase *m_broadPhase; // rcx
  int v6; // edx
  int v7; // ebx
  __int64 v8; // rdi
  __int64 v9; // rax
  hkpEntity *v10; // rcx
  char *v11; // [rsp+20h] [rbp-28h] BYREF
  int v12; // [rsp+28h] [rbp-20h]
  int v13; // [rsp+2Ch] [rbp-1Ch]
  hkWorldOperation::BaseOperation operation; // [rsp+30h] [rbp-18h] BYREF
  void *v15; // [rsp+38h] [rbp-10h]

  if ( this->m_criticalOperationsLockCount )
  {
    operation.m_type.m_storage = 33;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (void *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
    hkString::memCpy(v15, aabb, 0x20u);
    hkpWorld::queueOperation(this, &operation);
  }
  else
  {
    m_broadPhase = this->m_broadPhase;
    v11 = 0i64;
    v12 = 0;
    v13 = 0x80000000;
    ((void (__fastcall *)(hkpBroadPhase *, hkAabb *, char **))m_broadPhase->vfptr[9].__vecDelDtor)(
      m_broadPhase,
      aabb,
      &v11);
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
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v11, 16 * v13);
  }
}

// File Line: 1399
// RVA: 0xD57DA0
hkpConstraintInstance *__fastcall hkpWorld::addConstraint(hkpWorld *this, hkpConstraintInstance *constraint)
{
  __int64 v5; // rdx
  hkpConstraintData *m_data; // rsi
  hkpConstraintInstance *v7; // rsi
  hkpAction *m_owner; // rdx
  bool v9; // zf
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-18h] BYREF
  hkpConstraintInstance *v11; // [rsp+28h] [rbp-10h]
  __int16 v12; // [rsp+40h] [rbp+8h] BYREF
  __int16 v13; // [rsp+44h] [rbp+Ch]

  if ( this->m_criticalOperationsLockCount )
  {
    v11 = constraint;
    operation.m_type.m_storage = 9;
    hkpWorld::queueOperation(this, &operation);
    return 0i64;
  }
  else
  {
    if ( ((unsigned int (__fastcall *)(hkpConstraintData *))constraint->m_data->vfptr[1].__first_virtual_table_function__)(constraint->m_data) == 12 )
    {
      m_data = constraint->m_data;
      if ( !LOWORD(m_data[3].vfptr) )
      {
        LOBYTE(v5) = 1;
        (*(void (__fastcall **)(unsigned __int64, __int64, __int16 *))(*(_QWORD *)m_data[2].m_userData + 136i64))(
          m_data[2].m_userData,
          v5,
          &v12);
        LOWORD(m_data[3].vfptr) = v12;
        WORD1(m_data[3].vfptr) = v13;
      }
    }
    this->m_blockExecutingPendingOperations.m_bool = 1;
    hkpConstraintInstance::pointNullsToFixedRigidBody(constraint);
    constraint->m_uid = ++this->m_lastConstraintUid;
    v7 = hkpWorldOperationUtil::addConstraintImmediately(this, constraint, DO_FIRE_CALLBACKS);
    if ( ((unsigned int (__fastcall *)(hkpConstraintInstance *))constraint->vfptr[3].__vecDelDtor)(constraint) == 1 )
    {
      m_owner = (hkpAction *)constraint[1].m_owner;
      if ( !m_owner->m_world )
        hkpWorld::addAction(this, m_owner);
      constraint->m_data->vfptr[11].__first_virtual_table_function__(constraint->m_data);
    }
    v9 = this->m_criticalOperationsLockCount == 0;
    this->m_blockExecutingPendingOperations.m_bool = 0;
    if ( v9 )
    {
      if ( this->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(this);
    }
    return v7;
  }
}

// File Line: 1519
// RVA: 0xD57FC0
hkpConstraintInstance *__fastcall hkpWorld::createAndAddConstraintInstance(
        hkpWorld *this,
        hkpRigidBody *bodyA,
        hkpRigidBody *bodyB,
        hkpConstraintData *constraintData)
{
  _QWORD **Value; // rax
  hkpConstraintInstance *v9; // rax
  hkpConstraintInstance *v10; // rax
  hkpConstraintInstance *v11; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 112i64);
  if ( v9 )
  {
    hkpConstraintInstance::hkpConstraintInstance(v9, bodyA, bodyB, constraintData, PRIORITY_PSI);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v11->m_userData = constraintData->m_userData;
  hkpWorld::addConstraint(this, v11);
  return v11;
}

// File Line: 1531
// RVA: 0xD57EC0
hkBool *__fastcall hkpWorld::removeConstraint(hkpWorld *this, hkBool *result, hkpConstraintInstance *constraint)
{
  hkpAction *m_owner; // rdx
  bool v8; // zf
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-18h] BYREF
  hkpConstraintInstance *v10; // [rsp+28h] [rbp-10h]

  if ( this->m_criticalOperationsLockCount )
  {
    operation.m_type.m_storage = 10;
    v10 = constraint;
    hkpWorld::queueOperation(this, &operation);
    result->m_bool = 0;
    return result;
  }
  else
  {
    this->m_criticalOperationsLockCount = 1;
    if ( ((unsigned int (__fastcall *)(hkpConstraintInstance *))constraint->vfptr[3].__vecDelDtor)(constraint) == 1 )
    {
      m_owner = (hkpAction *)constraint[1].m_owner;
      if ( m_owner->m_world == this )
        hkpWorld::removeActionImmediately(this, m_owner);
    }
    hkReferencedObject::addReference(constraint);
    hkpWorldOperationUtil::removeConstraintImmediately(this, constraint, DO_FIRE_CALLBACKS);
    hkpConstraintInstance::setFixedRigidBodyPointersToZero(constraint, this);
    hkReferencedObject::removeReference(constraint);
    v8 = this->m_criticalOperationsLockCount-- == 1;
    if ( v8 && !this->m_blockExecutingPendingOperations.m_bool )
    {
      if ( this->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(this);
      if ( this->m_pendingOperationQueueCount == 1 )
      {
        if ( this->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(this);
      }
    }
    result->m_bool = 1;
    return result;
  }
}

// File Line: 1574
// RVA: 0xD58060
hkpAction *__fastcall hkpWorld::addAction(hkpWorld *this, hkpAction *action)
{
  hkBaseObjectVtbl *vfptr; // rax
  hkpEntity *v6; // rsi
  int v7; // ebp
  __int64 v8; // r15
  __int64 v9; // rdi
  hkpEntity *v10; // r8
  hkpSimulationIsland *m_simulationIsland; // rax
  bool v12; // zf
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-68h] BYREF
  hkpAction *v14; // [rsp+28h] [rbp-60h]
  char *v15; // [rsp+30h] [rbp-58h] BYREF
  int v16; // [rsp+38h] [rbp-50h]
  int v17; // [rsp+3Ch] [rbp-4Ch]
  char v18; // [rsp+40h] [rbp-48h] BYREF

  if ( this->m_criticalOperationsLockCount )
  {
    v14 = action;
    operation.m_type.m_storage = 11;
    hkpWorld::queueOperation(this, &operation);
    return 0i64;
  }
  else
  {
    hkReferencedObject::addReference(action);
    ++this->m_criticalOperationsLockCount;
    v15 = &v18;
    vfptr = action->vfptr;
    v16 = 0;
    v17 = -2147483644;
    vfptr[2].__vecDelDtor(action, (unsigned int)&v15);
    v6 = 0i64;
    action->m_world = this;
    v7 = 0;
    if ( v16 <= 0 )
      goto LABEL_14;
    v8 = 0i64;
    do
    {
      v9 = *(_QWORD *)&v15[v8] + 672i64;
      if ( *(_WORD *)(*(_QWORD *)&v15[v8] + 680i64) == (*(_WORD *)(*(_QWORD *)&v15[v8] + 682i64) & 0x3FFF) )
        hkSmallArrayUtil::_reserveMore((void *)(*(_QWORD *)&v15[v8] + 672i64), 8);
      *(_QWORD *)(*(_QWORD *)v9 + 8i64 * (unsigned __int16)(*(_WORD *)(v9 + 8))++) = action;
      v10 = *(hkpEntity **)&v15[v8];
      m_simulationIsland = v10->m_simulationIsland;
      if ( m_simulationIsland->m_storageIndex != 0xFFFF )
      {
        if ( v6 )
        {
          if ( v6->m_simulationIsland != m_simulationIsland )
            hkpWorldOperationUtil::mergeIslands(this, v6, v10);
        }
        else
        {
          v6 = *(hkpEntity **)&v15[v8];
          hkpSimulationIsland::addAction(v10->m_simulationIsland, action);
        }
      }
      ++v7;
      v8 += 8i64;
    }
    while ( v7 < v16 );
    if ( !v6 )
LABEL_14:
      hkpSimulationIsland::addAction(*(hkpSimulationIsland **)(*(_QWORD *)v15 + 296i64), action);
    v12 = this->m_criticalOperationsLockCount-- == 1;
    if ( v12 && !this->m_blockExecutingPendingOperations.m_bool )
    {
      if ( this->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(this);
      if ( this->m_pendingOperationQueueCount == 1 && this->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(this);
    }
    hkpWorldCallbackUtil::fireActionAdded(this, action);
    v16 = 0;
    if ( v17 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v15, 8 * v17);
    return action;
  }
}

// File Line: 1644
// RVA: 0xD58280
void __fastcall hkpWorld::removeAction(hkpWorld *this, hkpAction *action)
{
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-18h] BYREF
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
  hkBaseObjectVtbl *vfptr; // rax
  int v5; // r10d
  __int64 v6; // r9
  __int64 v7; // r8
  __int64 v8; // rax
  hkpAction **v9; // rcx
  hkpSimulationIsland *m_island; // rbp
  hkpWorld *m_world; // r14
  bool v12; // zf
  char *v13; // [rsp+20h] [rbp-38h] BYREF
  int v14; // [rsp+28h] [rbp-30h]
  int v15; // [rsp+2Ch] [rbp-2Ch]
  char v16; // [rsp+30h] [rbp-28h] BYREF

  hkReferencedObject::addReference(action);
  ++this->m_criticalOperationsLockCount;
  hkpWorldCallbackUtil::fireActionRemoved(this, action);
  v13 = &v16;
  vfptr = action->vfptr;
  v14 = 0;
  v15 = -2147483644;
  vfptr[2].__vecDelDtor(action, (unsigned int)&v13);
  v5 = 0;
  if ( v14 > 0 )
  {
    v6 = 0i64;
    do
    {
      v7 = *(_QWORD *)&v13[v6];
      v8 = 0i64;
      if ( *(_WORD *)(v7 + 680) )
      {
        v9 = *(hkpAction ***)(v7 + 672);
        while ( *v9 != action )
        {
          ++v8;
          ++v9;
          if ( v8 >= *(unsigned __int16 *)(v7 + 680) )
            goto LABEL_7;
        }
      }
      else
      {
LABEL_7:
        v8 = -1i64;
      }
      --*(_WORD *)(v7 + 680);
      ++v5;
      v6 += 8i64;
      *(_QWORD *)(*(_QWORD *)(v7 + 672) + 8 * v8) = *(_QWORD *)(*(_QWORD *)(v7 + 672)
                                                              + 8i64 * *(unsigned __int16 *)(v7 + 680));
    }
    while ( v5 < v14 );
  }
  m_island = action->m_island;
  hkpSimulationIsland::removeAction(m_island, action);
  action->m_world = 0i64;
  hkReferencedObject::removeReference(action);
  m_world = m_island->m_world;
  EnterCriticalSection(&m_world->m_islandDirtyListCriticalSection->m_section);
  if ( m_island->m_dirtyListIndex == 0xFFFF )
  {
    m_island->m_dirtyListIndex = m_world->m_dirtySimulationIslands.m_size;
    if ( m_world->m_dirtySimulationIslands.m_size == (m_world->m_dirtySimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&m_world->m_dirtySimulationIslands.m_data,
        8);
    m_world->m_dirtySimulationIslands.m_data[m_world->m_dirtySimulationIslands.m_size++] = m_island;
  }
  LeaveCriticalSection(&m_world->m_islandDirtyListCriticalSection->m_section);
  v14 = 0;
  if ( v15 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v13, 8 * v15);
  v12 = this->m_criticalOperationsLockCount-- == 1;
  if ( v12 && !this->m_blockExecutingPendingOperations.m_bool )
  {
    if ( this->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(this);
    if ( this->m_pendingOperationQueueCount == 1 && this->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(this);
  }
  hkReferencedObject::removeReference(action);
}

// File Line: 1703
// RVA: 0xD5D690
void __fastcall hkpWorld::attachActionToEntity(hkpWorld *this, hkpAction *action, hkpEntity *entity)
{
  hkSmallArray<hkpAction *> *p_m_actions; // rdi
  hkpSimulationIsland *m_island; // r8

  p_m_actions = &entity->m_actions;
  if ( entity->m_actions.m_size == (entity->m_actions.m_capacityAndFlags & 0x3FFF) )
    hkSmallArrayUtil::_reserveMore(p_m_actions, 8);
  p_m_actions->m_data[p_m_actions->m_size++] = action;
  m_island = action->m_island;
  if ( m_island->m_storageIndex != 0xFFFF || entity->m_motion.m_type.m_storage == 5 )
  {
    if ( entity->m_simulationIsland != m_island && entity->m_motion.m_type.m_storage != 5 )
      hkpWorldOperationUtil::mergeIslands(this, entity, *m_island->m_entities.m_data);
  }
  else
  {
    hkpSimulationIsland::removeAction(action->m_island, action);
    hkpSimulationIsland::addAction(entity->m_simulationIsland, action);
  }
}

// File Line: 1729
// RVA: 0xD5D760
void __fastcall hkpWorld::detachActionFromEntity(hkpWorld *this, hkpAction *action, hkpEntity *entity)
{
  __int64 m_size; // rdx
  int v5; // r9d
  __int64 v6; // rcx
  hkpAction **m_data; // rax
  __int64 v9; // rax
  hkBaseObjectVtbl *vfptr; // rax
  char *v11; // r9
  hkpSimulationIsland *v12; // rbx
  int v13; // edx
  __int64 v14; // rax
  hkpSimulationIsland *m_island; // rcx
  char *v16; // [rsp+20h] [rbp-38h] BYREF
  int v17; // [rsp+28h] [rbp-30h]
  int v18; // [rsp+2Ch] [rbp-2Ch]
  char v19; // [rsp+30h] [rbp-28h] BYREF

  m_size = entity->m_actions.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( entity->m_actions.m_size )
  {
    m_data = entity->m_actions.m_data;
    while ( *m_data != action )
    {
      ++v6;
      ++v5;
      ++m_data;
      if ( v6 >= m_size )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v5 = -1;
  }
  v9 = (unsigned __int16)(m_size - 1);
  entity->m_actions.m_size = v9;
  entity->m_actions.m_data[v5] = entity->m_actions.m_data[v9];
  *((_BYTE *)entity->m_simulationIsland + 49) = *((_BYTE *)entity->m_simulationIsland + 49) & 0xFC | 1;
  v16 = &v19;
  vfptr = action->vfptr;
  v17 = 0;
  v18 = -2147483644;
  vfptr[2].__vecDelDtor(action, (unsigned int)&v16);
  v11 = v16;
  v12 = 0i64;
  v13 = 0;
  if ( v17 > 0 )
  {
    v14 = (__int64)v16;
    do
    {
      if ( *(hkpEntity **)v14 != entity )
      {
        v12 = *(hkpSimulationIsland **)(*(_QWORD *)v14 + 296i64);
        if ( v12->m_storageIndex != 0xFFFF )
          break;
      }
      ++v13;
      v14 += 8i64;
    }
    while ( v13 < v17 );
  }
  m_island = action->m_island;
  if ( v12 != m_island )
  {
    hkpSimulationIsland::removeAction(m_island, action);
    hkpSimulationIsland::addAction(v12, action);
    v11 = v16;
  }
  v17 = 0;
  if ( v18 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v11, 8 * v18);
}

// File Line: 1772
// RVA: 0xD584B0
hkpPhantom *__fastcall hkpWorld::addPhantom(hkpWorld *this, hkpPhantom *phantom)
{
  int m_criticalOperationsLockCount; // ecx
  bool v6; // zf
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-18h] BYREF
  hkpPhantom *v8; // [rsp+28h] [rbp-10h]

  m_criticalOperationsLockCount = this->m_criticalOperationsLockCount;
  if ( m_criticalOperationsLockCount + this->m_criticalOperationsLockCountForPhantoms )
  {
    v8 = phantom;
    operation.m_type.m_storage = 14;
    hkpWorld::queueOperation(this, &operation);
    return 0i64;
  }
  else
  {
    this->m_criticalOperationsLockCount = m_criticalOperationsLockCount + 1;
    if ( !phantom->m_collidable.m_motion )
      phantom->m_collidable.m_motion = (const void *)((__int64 (__fastcall *)(hkpPhantom *))phantom->vfptr[2].__first_virtual_table_function__)(phantom);
    phantom->m_world = this;
    hkReferencedObject::addReference(phantom);
    if ( this->m_phantoms.m_size == (this->m_phantoms.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_phantoms.m_data, 8);
    this->m_phantoms.m_data[this->m_phantoms.m_size++] = phantom;
    hkpWorldOperationUtil::addPhantomBP(this, phantom);
    hkpWorldCallbackUtil::firePhantomAdded(this, phantom);
    hkpPhantom::firePhantomAdded(phantom);
    v6 = this->m_criticalOperationsLockCount-- == 1;
    if ( v6 && !this->m_blockExecutingPendingOperations.m_bool )
    {
      if ( this->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(this);
      if ( this->m_pendingOperationQueueCount == 1 )
      {
        if ( this->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(this);
      }
    }
    return phantom;
  }
}

// File Line: 1823
// RVA: 0xD585D0
void __fastcall hkpWorld::addPhantomBatch(hkpWorld *this, hkpPhantom *const *phantomBatch, unsigned int numPhantoms)
{
  int m_criticalOperationsLockCount; // ecx
  __int64 v5; // rbx
  __int64 v7; // r15
  hkLifoAllocator *Value; // rax
  char *m_cur; // r8
  int v10; // edx
  char *v11; // rcx
  hkLifoAllocator *v12; // rax
  char *v13; // rcx
  int v14; // edx
  char *v15; // r8
  __int64 v16; // r14
  __int64 v17; // r12
  hkpPhantom *v18; // rbx
  int m_broadPhaseQuerySize; // ebx
  hkLifoAllocator *v20; // rcx
  hkpTypedBroadPhaseHandlePair *v21; // rax
  int v22; // edx
  char *v23; // r8
  hkpBroadPhase *m_broadPhase; // rcx
  hkpCollisionFilter *m_collisionFilter; // r9
  hkpCollidableCollidableFilter *v26; // r9
  bool v27; // zf
  int v28; // eax
  char *v29; // rdi
  signed int v30; // ebx
  hkLifoAllocator *v31; // rax
  int v32; // r8d
  int v33; // eax
  char *v34; // rdi
  signed int v35; // ebx
  hkLifoAllocator *v36; // rax
  int v37; // r8d
  int v38; // eax
  char *v39; // rdi
  signed int v40; // ebx
  hkLifoAllocator *v41; // rax
  int v42; // r8d
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-49h] BYREF
  hkpPhantom *const *v44; // [rsp+28h] [rbp-41h]
  __int16 v45; // [rsp+30h] [rbp-39h]
  hkpTypedBroadPhaseHandlePair *newPairs; // [rsp+38h] [rbp-31h] BYREF
  int numNewPairs; // [rsp+40h] [rbp-29h]
  int v48; // [rsp+44h] [rbp-25h]
  void *p; // [rsp+48h] [rbp-21h]
  int v50; // [rsp+50h] [rbp-19h]
  char *v51; // [rsp+58h] [rbp-11h] BYREF
  int v52; // [rsp+60h] [rbp-9h]
  int v53; // [rsp+64h] [rbp-5h]
  void *v54; // [rsp+68h] [rbp-1h]
  int v55; // [rsp+70h] [rbp+7h]
  char *v56; // [rsp+78h] [rbp+Fh] BYREF
  int v57; // [rsp+80h] [rbp+17h]
  int v58; // [rsp+84h] [rbp+1Bh]
  void *v59; // [rsp+88h] [rbp+1Fh]
  unsigned int v60; // [rsp+90h] [rbp+27h]

  if ( (int)numPhantoms > 0 )
  {
    m_criticalOperationsLockCount = this->m_criticalOperationsLockCount;
    v5 = numPhantoms;
    if ( m_criticalOperationsLockCount + this->m_criticalOperationsLockCountForPhantoms )
    {
      v44 = phantomBatch;
      operation.m_type.m_storage = 16;
      v45 = numPhantoms;
      hkpWorld::queueOperation(this, &operation);
    }
    else
    {
      this->m_criticalOperationsLockCount = m_criticalOperationsLockCount + 1;
      v7 = 0i64;
      v56 = 0i64;
      v57 = 0;
      v58 = 0x80000000;
      v60 = numPhantoms;
      Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (char *)Value->m_cur;
      v10 = (8 * v5 + 127) & 0xFFFFFF80;
      v11 = &m_cur[v10];
      if ( v10 > Value->m_slabSize || v11 > Value->m_end )
        m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v10);
      else
        Value->m_cur = v11;
      v56 = m_cur;
      v59 = m_cur;
      v51 = 0i64;
      v52 = 0;
      v53 = 0x80000000;
      v55 = v5;
      v58 = v5 | 0x80000000;
      v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v13 = (char *)v12->m_cur;
      v14 = (32 * v5 + 127) & 0xFFFFFF80;
      v15 = &v13[v14];
      if ( v14 > v12->m_slabSize || v15 > v12->m_end )
        v13 = (char *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
      else
        v12->m_cur = v15;
      v51 = v13;
      v53 = v5 | 0x80000000;
      v54 = v13;
      v52 = v5;
      v57 = v5;
      v16 = 0i64;
      v17 = v5;
      do
      {
        v18 = phantomBatch[v16];
        if ( !v18->m_collidable.m_motion )
          v18->m_collidable.m_motion = (const void *)((__int64 (__fastcall *)(hkpPhantom *const))v18->vfptr[2].__first_virtual_table_function__)(phantomBatch[v16]);
        v18->m_world = this;
        *(_QWORD *)&v56[v16 * 8] = &v18->m_collidable.m_broadPhaseHandle;
        ((void (__fastcall *)(hkpPhantom *, char *))v18->vfptr[3].__first_virtual_table_function__)(v18, &v51[v7]);
        hkpPhantom::setBoundingVolumeData(v18, (hkAabb *)&v51[v7]);
        hkReferencedObject::addReference(v18);
        if ( this->m_phantoms.m_size == (this->m_phantoms.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_phantoms.m_data, 8);
        this->m_phantoms.m_data[this->m_phantoms.m_size++] = v18;
        hkpWorldCallbackUtil::firePhantomAdded(this, v18);
        hkpPhantom::firePhantomAdded(v18);
        v7 += 32i64;
        ++v16;
        --v17;
      }
      while ( v17 );
      m_broadPhaseQuerySize = this->m_broadPhaseQuerySize;
      newPairs = 0i64;
      numNewPairs = 0;
      v48 = 0x80000000;
      v50 = m_broadPhaseQuerySize;
      if ( m_broadPhaseQuerySize )
      {
        v20 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v21 = (hkpTypedBroadPhaseHandlePair *)v20->m_cur;
        v22 = (16 * m_broadPhaseQuerySize + 127) & 0xFFFFFF80;
        v23 = (char *)v21 + v22;
        if ( v22 > v20->m_slabSize || v23 > v20->m_end )
          v21 = (hkpTypedBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v20, v22);
        else
          v20->m_cur = v23;
      }
      else
      {
        v21 = 0i64;
      }
      m_broadPhase = this->m_broadPhase;
      newPairs = v21;
      p = v21;
      v48 = m_broadPhaseQuerySize | 0x80000000;
      ((void (__fastcall *)(hkpBroadPhase *, char **, char **, hkpTypedBroadPhaseHandlePair **))m_broadPhase->vfptr[3].__first_virtual_table_function__)(
        m_broadPhase,
        &v56,
        &v51,
        &newPairs);
      m_collisionFilter = this->m_collisionFilter;
      if ( m_collisionFilter )
        v26 = &m_collisionFilter->hkpCollidableCollidableFilter;
      else
        v26 = 0i64;
      hkpTypedBroadPhaseDispatcher::addPairs(this->m_broadPhaseDispatcher, newPairs, numNewPairs, v26);
      v27 = this->m_criticalOperationsLockCount-- == 1;
      if ( v27 && !this->m_blockExecutingPendingOperations.m_bool )
      {
        if ( this->m_pendingOperationsCount )
          hkpWorld::internal_executePendingOperations(this);
        if ( this->m_pendingOperationQueueCount == 1 && this->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(this);
      }
      v28 = numNewPairs;
      v29 = (char *)p;
      if ( p == newPairs )
        v28 = 0;
      numNewPairs = v28;
      v30 = (16 * v50 + 127) & 0xFFFFFF80;
      v31 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v32 = (v30 + 15) & 0xFFFFFFF0;
      if ( v30 > v31->m_slabSize || &v29[v32] != v31->m_cur || v31->m_firstNonLifoEnd == v29 )
        hkLifoAllocator::slowBlockFree(v31, v29, v32);
      else
        v31->m_cur = v29;
      numNewPairs = 0;
      if ( v48 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, newPairs, 16 * v48);
      v33 = v52;
      v34 = (char *)v54;
      newPairs = 0i64;
      if ( v54 == v51 )
        v33 = 0;
      v48 = 0x80000000;
      v52 = v33;
      v35 = (32 * v55 + 127) & 0xFFFFFF80;
      v36 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v37 = (v35 + 15) & 0xFFFFFFF0;
      if ( v35 > v36->m_slabSize || &v34[v37] != v36->m_cur || v36->m_firstNonLifoEnd == v34 )
        hkLifoAllocator::slowBlockFree(v36, v34, v37);
      else
        v36->m_cur = v34;
      v52 = 0;
      if ( v53 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v51, 32 * v53);
      v38 = v57;
      v39 = (char *)v59;
      v51 = 0i64;
      v53 = 0x80000000;
      if ( v59 == v56 )
        v38 = 0;
      v57 = v38;
      v40 = (8 * v60 + 127) & 0xFFFFFF80;
      v41 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v42 = (v40 + 15) & 0xFFFFFFF0;
      if ( v40 > v41->m_slabSize || &v39[v42] != v41->m_cur || v41->m_firstNonLifoEnd == v39 )
        hkLifoAllocator::slowBlockFree(v41, v39, v42);
      else
        v41->m_cur = v39;
      v57 = 0;
      if ( v58 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v56, 8 * v58);
    }
  }
}Free(v41, v39, v42);
      else
        v41->m_cur = v39;
      v57 = 0;
      if ( v58 >= 0 )
        hkContainerHe

// File Line: 1892
// RVA: 0xD58AB0
void __fastcall hkpWorld::removePhantom(hkpWorld *this, hkpPhantom *phantom)
{
  int m_criticalOperationsLockCount; // edx
  __int64 m_size; // r9
  int v6; // r8d
  __int64 v7; // rcx
  hkpPhantom **m_data; // rax
  bool v9; // zf
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-18h] BYREF
  hkpPhantom *v11; // [rsp+28h] [rbp-10h]

  m_criticalOperationsLockCount = this->m_criticalOperationsLockCount;
  if ( m_criticalOperationsLockCount + this->m_criticalOperationsLockCountForPhantoms )
  {
    operation.m_type.m_storage = 15;
    v11 = phantom;
    hkpWorld::queueOperation(this, &operation);
  }
  else
  {
    this->m_criticalOperationsLockCount = m_criticalOperationsLockCount + 1;
    hkpWorldCallbackUtil::firePhantomRemoved(this, phantom);
    hkpPhantom::firePhantomRemoved(phantom);
    hkpWorldOperationUtil::removePhantomBP(this, phantom);
    m_size = this->m_phantoms.m_size;
    v6 = 0;
    v7 = 0i64;
    if ( (int)m_size <= 0 )
    {
LABEL_7:
      v6 = -1;
    }
    else
    {
      m_data = this->m_phantoms.m_data;
      while ( *m_data != phantom )
      {
        ++v7;
        ++v6;
        ++m_data;
        if ( v7 >= m_size )
          goto LABEL_7;
      }
    }
    this->m_phantoms.m_size = m_size - 1;
    if ( (_DWORD)m_size - 1 != v6 )
      this->m_phantoms.m_data[v6] = this->m_phantoms.m_data[(int)m_size - 1];
    v9 = phantom->m_memSizeAndFlags == 0;
    phantom->m_world = 0i64;
    if ( v9 )
      ((void (__fastcall *)(hkpPhantom *))phantom->vfptr[7].__vecDelDtor)(phantom);
    hkReferencedObject::removeReference(phantom);
    v9 = this->m_criticalOperationsLockCount-- == 1;
    if ( v9 && !this->m_blockExecutingPendingOperations.m_bool )
    {
      if ( this->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(this);
      if ( this->m_pendingOperationQueueCount == 1 )
      {
        if ( this->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(this);
      }
    }
  }
}

// File Line: 1941
// RVA: 0xD58BE0
void __fastcall hkpWorld::removePhantomBatch(hkpWorld *this, hkpPhantom *const *phantomBatch, unsigned int numPhantoms)
{
  int m_criticalOperationsLockCount; // ecx
  __int64 v5; // r14
  hkpPhantom *const *v6; // r12
  hkLifoAllocator *Value; // rax
  char *m_cur; // r8
  int v9; // edx
  char *v10; // rcx
  hkpPhantom **v11; // rsi
  __int64 v12; // r15
  hkpPhantom *v13; // rbx
  int m_broadPhaseQuerySize; // ebx
  hkLifoAllocator *v15; // rcx
  char *v16; // rax
  int v17; // edx
  char *v18; // r8
  hkpBroadPhase *m_broadPhase; // rcx
  int v20; // eax
  char *v21; // rsi
  signed int v22; // ebx
  hkLifoAllocator *v23; // rax
  int v24; // r8d
  __int64 v25; // rsi
  hkReferencedObject *v26; // rbx
  int v27; // edx
  __int64 v28; // rax
  __int64 m_size; // r9
  hkpPhantom **m_data; // rcx
  bool v31; // zf
  int v32; // eax
  char *v33; // rdi
  signed int v34; // ebx
  hkLifoAllocator *v35; // rax
  int v36; // r8d
  hkWorldOperation::BaseOperation operation[8]; // [rsp+20h] [rbp-48h] BYREF
  int numDeletedPairs[2]; // [rsp+28h] [rbp-40h]
  void *p; // [rsp+30h] [rbp-38h]
  int v40; // [rsp+38h] [rbp-30h]
  _QWORD *v41; // [rsp+40h] [rbp-28h] BYREF
  int v42; // [rsp+48h] [rbp-20h]
  int v43; // [rsp+4Ch] [rbp-1Ch]
  void *v44; // [rsp+50h] [rbp-18h]
  unsigned int v45; // [rsp+58h] [rbp-10h]

  if ( (int)numPhantoms > 0 )
  {
    m_criticalOperationsLockCount = this->m_criticalOperationsLockCount;
    v5 = numPhantoms;
    v6 = phantomBatch;
    if ( m_criticalOperationsLockCount + this->m_criticalOperationsLockCountForPhantoms )
    {
      *(_QWORD *)numDeletedPairs = phantomBatch;
      operation[0].m_type.m_storage = 17;
      LOWORD(p) = numPhantoms;
      hkpWorld::queueOperation(this, operation);
    }
    else
    {
      this->m_criticalOperationsLockCount = m_criticalOperationsLockCount + 1;
      v41 = 0i64;
      v42 = 0;
      v43 = 0x80000000;
      v45 = numPhantoms;
      Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (char *)Value->m_cur;
      v9 = (8 * v5 + 127) & 0xFFFFFF80;
      v10 = &m_cur[v9];
      if ( v9 > Value->m_slabSize || v10 > Value->m_end )
        m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v9);
      else
        Value->m_cur = v10;
      v41 = m_cur;
      v44 = m_cur;
      v43 = v5 | 0x80000000;
      v11 = (hkpPhantom **)v6;
      v12 = v5;
      do
      {
        v13 = *v11;
        v41[v42++] = &(*v11)->m_collidable.m_broadPhaseHandle;
        hkpWorldCallbackUtil::firePhantomRemoved(this, v13);
        hkpPhantom::firePhantomRemoved(v13);
        ++v11;
        --v12;
      }
      while ( v12 );
      if ( v42 )
      {
        m_broadPhaseQuerySize = this->m_broadPhaseQuerySize;
        *(_QWORD *)&operation[0].m_type.m_storage = 0i64;
        numDeletedPairs[0] = 0;
        numDeletedPairs[1] = 0x80000000;
        v40 = m_broadPhaseQuerySize;
        if ( m_broadPhaseQuerySize )
        {
          v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v16 = (char *)v15->m_cur;
          v17 = (16 * m_broadPhaseQuerySize + 127) & 0xFFFFFF80;
          v18 = &v16[v17];
          if ( v17 > v15->m_slabSize || v18 > v15->m_end )
            v16 = (char *)hkLifoAllocator::allocateFromNewSlab(v15, v17);
          else
            v15->m_cur = v18;
        }
        else
        {
          v16 = 0i64;
        }
        m_broadPhase = this->m_broadPhase;
        *(_QWORD *)&operation[0].m_type.m_storage = v16;
        p = v16;
        numDeletedPairs[1] = m_broadPhaseQuerySize | 0x80000000;
        ((void (__fastcall *)(hkpBroadPhase *, _QWORD **, hkWorldOperation::BaseOperation *))m_broadPhase->vfptr[4].__first_virtual_table_function__)(
          m_broadPhase,
          &v41,
          operation);
        hkpTypedBroadPhaseDispatcher::removePairs(
          this->m_broadPhaseDispatcher,
          *(hkpTypedBroadPhaseHandlePair **)&operation[0].m_type.m_storage,
          numDeletedPairs[0]);
        v20 = numDeletedPairs[0];
        v21 = (char *)p;
        if ( p == *(void **)&operation[0].m_type.m_storage )
          v20 = 0;
        numDeletedPairs[0] = v20;
        v22 = (16 * v40 + 127) & 0xFFFFFF80;
        v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v24 = (v22 + 15) & 0xFFFFFFF0;
        if ( v22 > v23->m_slabSize || &v21[v24] != v23->m_cur || v23->m_firstNonLifoEnd == v21 )
          hkLifoAllocator::slowBlockFree(v23, v21, v24);
        else
          v23->m_cur = v21;
        numDeletedPairs[0] = 0;
        if ( numDeletedPairs[1] >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)&operation[0].m_type.m_storage,
            16 * numDeletedPairs[1]);
      }
      v25 = v5;
      do
      {
        v26 = *v6;
        v27 = 0;
        v28 = 0i64;
        (*v6)->m_world = 0i64;
        m_size = this->m_phantoms.m_size;
        if ( (int)m_size <= 0 )
        {
LABEL_31:
          v27 = -1;
          v28 = -1i64;
        }
        else
        {
          m_data = this->m_phantoms.m_data;
          while ( *m_data != v26 )
          {
            ++v28;
            ++v27;
            ++m_data;
            if ( v28 >= m_size )
              goto LABEL_31;
          }
        }
        this->m_phantoms.m_size = m_size - 1;
        if ( (_DWORD)m_size - 1 != v27 )
          this->m_phantoms.m_data[v28] = this->m_phantoms.m_data[(int)m_size - 1];
        if ( !v26->m_memSizeAndFlags )
          ((void (__fastcall *)(hkReferencedObject *))v26->vfptr[7].__vecDelDtor)(v26);
        hkReferencedObject::removeReference(v26);
        ++v6;
        --v25;
      }
      while ( v25 );
      v31 = this->m_criticalOperationsLockCount-- == 1;
      if ( v31 && !this->m_blockExecutingPendingOperations.m_bool )
      {
        if ( this->m_pendingOperationsCount )
          hkpWorld::internal_executePendingOperations(this);
        if ( this->m_pendingOperationQueueCount == 1 && this->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(this);
      }
      v32 = v42;
      v33 = (char *)v44;
      if ( v44 == v41 )
        v32 = 0;
      v42 = v32;
      v34 = (8 * v45 + 127) & 0xFFFFFF80;
      v35 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v36 = (v34 + 15) & 0xFFFFFFF0;
      if ( v34 > v35->m_slabSize || &v33[v36] != v35->m_cur || v35->m_firstNonLifoEnd == v33 )
        hkLifoAllocator::slowBlockFree(v35, v33, v36);
      else
        v35->m_cur = v33;
      v42 = 0;
      if ( v43 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v41, 8 * v43);
    }
  }
}

// File Line: 2009
// RVA: 0xD590D0
void __fastcall hkpWorld::addPhysicsSystem(hkpWorld *this, hkpPhysicsSystem *sys)
{
  int m_size; // r10d
  int v3; // edi
  __int64 v6; // rcx
  int v7; // r8d
  __int64 v8; // rdx
  hkpRigidBody **m_data; // rax
  int v10; // r9d
  int v11; // edx
  __int64 v12; // rcx
  hkpPhantom **v13; // rax
  int v14; // esi
  __int64 v15; // r14
  hkpAction *v16; // rdx
  __int64 v17; // rsi
  hkpConstraintInstance *v18; // rdx
  int v19; // esi
  __int64 v20; // r14
  hkpRigidBody *v21; // rdx
  int v22; // esi
  __int64 v23; // r14
  hkpPhantom *v24; // rdx

  m_size = sys->m_rigidBodies.m_size;
  v3 = 0;
  if ( m_size > 0 )
  {
    v6 = sys->m_rigidBodies.m_size;
    v7 = 0;
    v8 = 0i64;
    if ( v6 <= 0 )
      goto LABEL_6;
    m_data = sys->m_rigidBodies.m_data;
    while ( *m_data )
    {
      ++v8;
      ++v7;
      ++m_data;
      if ( v8 >= v6 )
        goto LABEL_6;
    }
    if ( v7 == -1 )
    {
LABEL_6:
      hkpWorld::addEntityBatch(
        this,
        sys->m_rigidBodies.m_data,
        m_size,
        (hkpEntityActivation)(sys->m_active.m_bool != 0));
    }
    else
    {
      v19 = 0;
      v20 = 0i64;
      do
      {
        v21 = sys->m_rigidBodies.m_data[v20];
        if ( v21 )
          hkpWorld::addEntity(this, v21, (hkpEntityActivation)(sys->m_active.m_bool != 0));
        ++v19;
        ++v20;
      }
      while ( v19 < sys->m_rigidBodies.m_size );
    }
  }
  v10 = sys->m_phantoms.m_size;
  if ( v10 > 0 )
  {
    v11 = 0;
    v12 = 0i64;
    v13 = sys->m_phantoms.m_data;
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
      hkpWorld::addPhantomBatch(this, sys->m_phantoms.m_data, v10);
      goto LABEL_13;
    }
    v22 = 0;
    v23 = 0i64;
    do
    {
      v24 = sys->m_phantoms.m_data[v23];
      if ( v24 )
        hkpWorld::addPhantom(this, v24);
      ++v22;
      ++v23;
    }
    while ( v22 < sys->m_phantoms.m_size );
  }
LABEL_13:
  v14 = 0;
  if ( sys->m_actions.m_size > 0 )
  {
    v15 = 0i64;
    do
    {
      v16 = sys->m_actions.m_data[v15];
      if ( v16 )
        hkpWorld::addAction(this, v16);
      ++v14;
      ++v15;
    }
    while ( v14 < sys->m_actions.m_size );
  }
  if ( sys->m_constraints.m_size > 0 )
  {
    v17 = 0i64;
    do
    {
      v18 = sys->m_constraints.m_data[v17];
      if ( v18 && (v18->m_entities[0] || v18->m_entities[1]) )
        hkpWorld::addConstraint(this, v18);
      ++v3;
      ++v17;
    }
    while ( v3 < sys->m_constraints.m_size );
  }
}

// File Line: 2090
// RVA: 0xD592A0
void __fastcall hkpWorld::removePhysicsSystem(hkpWorld *this, hkpPhysicsSystem *sys)
{
  int v2; // edi
  int v5; // esi
  __int64 v6; // r14
  hkpConstraintInstance *v7; // r8
  int v8; // esi
  __int64 v9; // r14
  hkpAction *v10; // rdx
  __int64 m_size; // r8
  int v12; // edx
  __int64 v13; // rcx
  hkpRigidBody **m_data; // rax
  __int64 v15; // r8
  int v16; // edx
  __int64 v17; // rcx
  hkpPhantom **v18; // rax
  int v19; // esi
  __int64 v20; // r14
  hkpRigidBody *v21; // r8
  __int64 v22; // rsi
  hkpPhantom *v23; // rdx
  hkBool result; // [rsp+48h] [rbp+10h] BYREF

  v2 = 0;
  v5 = 0;
  if ( sys->m_constraints.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      v7 = sys->m_constraints.m_data[v6];
      if ( v7 && v7->m_owner )
        hkpWorld::removeConstraint(this, &result, v7);
      ++v5;
      ++v6;
    }
    while ( v5 < sys->m_constraints.m_size );
  }
  v8 = 0;
  if ( sys->m_actions.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      v10 = sys->m_actions.m_data[v9];
      if ( v10 )
        hkpWorld::removeAction(this, v10);
      ++v8;
      ++v9;
    }
    while ( v8 < sys->m_actions.m_size );
  }
  m_size = sys->m_rigidBodies.m_size;
  v12 = 0;
  v13 = 0i64;
  if ( m_size <= 0 )
    goto LABEL_16;
  m_data = sys->m_rigidBodies.m_data;
  while ( *m_data )
  {
    ++v13;
    ++v12;
    ++m_data;
    if ( v13 >= m_size )
      goto LABEL_16;
  }
  if ( v12 == -1 )
  {
LABEL_16:
    hkpWorld::removeEntityBatch(this, sys->m_rigidBodies.m_data, sys->m_rigidBodies.m_size);
  }
  else
  {
    v19 = 0;
    if ( sys->m_rigidBodies.m_size > 0 )
    {
      v20 = 0i64;
      do
      {
        v21 = sys->m_rigidBodies.m_data[v20];
        if ( v21 )
          hkpWorld::removeEntity(this, &result, v21);
        ++v19;
        ++v20;
      }
      while ( v19 < sys->m_rigidBodies.m_size );
    }
  }
  v15 = sys->m_phantoms.m_size;
  v16 = 0;
  v17 = 0i64;
  if ( v15 <= 0 )
    goto LABEL_21;
  v18 = sys->m_phantoms.m_data;
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
    hkpWorld::removePhantomBatch(this, sys->m_phantoms.m_data, sys->m_phantoms.m_size);
  }
  else if ( sys->m_phantoms.m_size > 0 )
  {
    v22 = 0i64;
    do
    {
      v23 = sys->m_phantoms.m_data[v22];
      if ( v23 )
        hkpWorld::removePhantom(this, v23);
      ++v2;
      ++v22;
    }
    while ( v2 < sys->m_phantoms.m_size );
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
  hkArray<hkpActionListener *,hkContainerHeapAllocator> *p_m_actionListeners; // rbx

  p_m_actionListeners = &this->m_actionListeners;
  if ( this->m_actionListeners.m_size == (this->m_actionListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_actionListeners->m_data, 8);
  p_m_actionListeners->m_data[p_m_actionListeners->m_size++] = worldListener;
}

// File Line: 2179
// RVA: 0xD5A800
void __fastcall hkpWorld::removeActionListener(hkpWorld *this, hkpActionListener *worldListener)
{
  __int64 m_size; // r10
  int v3; // r9d
  __int64 v4; // r8
  hkpActionListener **m_data; // rax

  m_size = this->m_actionListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_data = this->m_actionListeners.m_data;
    while ( *m_data != worldListener )
    {
      ++v4;
      ++v3;
      ++m_data;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
  }
  this->m_actionListeners.m_data[v3] = 0i64;
}

// File Line: 2188
// RVA: 0xD5A860
void __fastcall hkpWorld::addConstraintListener(hkpWorld *this, hkpConstraintListener *worldListener)
{
  hkArray<hkpConstraintListener *,hkContainerHeapAllocator> *p_m_constraintListeners; // rbx

  p_m_constraintListeners = &this->m_constraintListeners;
  if ( this->m_constraintListeners.m_size == (this->m_constraintListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_constraintListeners->m_data, 8);
  p_m_constraintListeners->m_data[p_m_constraintListeners->m_size++] = worldListener;
}

// File Line: 2196
// RVA: 0xD5A8C0
void __fastcall hkpWorld::removeConstraintListener(hkpWorld *this, hkpConstraintListener *worldListener)
{
  __int64 m_size; // r10
  int v3; // r9d
  __int64 v4; // r8
  hkpConstraintListener **m_data; // rax

  m_size = this->m_constraintListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_data = this->m_constraintListeners.m_data;
    while ( *m_data != worldListener )
    {
      ++v4;
      ++v3;
      ++m_data;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
  }
  this->m_constraintListeners.m_data[v3] = 0i64;
}

// File Line: 2204
// RVA: 0xD5A920
void __fastcall hkpWorld::addEntityListener(hkpWorld *this, hkpEntityListener *worldListener)
{
  hkArray<hkpEntityListener *,hkContainerHeapAllocator> *p_m_entityListeners; // rbx

  p_m_entityListeners = &this->m_entityListeners;
  if ( this->m_entityListeners.m_size == (this->m_entityListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_entityListeners->m_data, 8);
  p_m_entityListeners->m_data[p_m_entityListeners->m_size++] = worldListener;
}

// File Line: 2211
// RVA: 0xD5A980
void __fastcall hkpWorld::removeEntityListener(hkpWorld *this, hkpEntityListener *worldListener)
{
  __int64 m_size; // r10
  int v3; // r9d
  __int64 v4; // r8
  hkpEntityListener **m_data; // rax

  m_size = this->m_entityListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_data = this->m_entityListeners.m_data;
    while ( *m_data != worldListener )
    {
      ++v4;
      ++v3;
      ++m_data;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
  }
  this->m_entityListeners.m_data[v3] = 0i64;
}

// File Line: 2219
// RVA: 0xD5A9E0
void __fastcall hkpWorld::addPhantomListener(hkpWorld *this, hkpPhantomListener *worldListener)
{
  hkArray<hkpPhantomListener *,hkContainerHeapAllocator> *p_m_phantomListeners; // rbx

  p_m_phantomListeners = &this->m_phantomListeners;
  if ( this->m_phantomListeners.m_size == (this->m_phantomListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_phantomListeners->m_data, 8);
  p_m_phantomListeners->m_data[p_m_phantomListeners->m_size++] = worldListener;
}

// File Line: 2226
// RVA: 0xD5AA40
void __fastcall hkpWorld::removePhantomListener(hkpWorld *this, hkpPhantomListener *worldListener)
{
  __int64 m_size; // r10
  int v3; // r9d
  __int64 v4; // r8
  hkpPhantomListener **m_data; // rax

  m_size = this->m_phantomListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_data = this->m_phantomListeners.m_data;
    while ( *m_data != worldListener )
    {
      ++v4;
      ++v3;
      ++m_data;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
  }
  this->m_phantomListeners.m_data[v3] = 0i64;
}

// File Line: 2234
// RVA: 0xD5AAA0
void __fastcall hkpWorld::addIslandActivationListener(hkpWorld *this, hkpIslandActivationListener *worldListener)
{
  hkArray<hkpIslandActivationListener *,hkContainerHeapAllocator> *p_m_islandActivationListeners; // rbx

  p_m_islandActivationListeners = &this->m_islandActivationListeners;
  if ( this->m_islandActivationListeners.m_size == (this->m_islandActivationListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&p_m_islandActivationListeners->m_data,
      8);
  p_m_islandActivationListeners->m_data[p_m_islandActivationListeners->m_size++] = worldListener;
}

// File Line: 2241
// RVA: 0xD5AB00
void __fastcall hkpWorld::removeIslandActivationListener(hkpWorld *this, hkpIslandActivationListener *worldListener)
{
  __int64 m_size; // r10
  int v3; // r9d
  __int64 v4; // r8
  hkpIslandActivationListener **m_data; // rax

  m_size = this->m_islandActivationListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_data = this->m_islandActivationListeners.m_data;
    while ( *m_data != worldListener )
    {
      ++v4;
      ++v3;
      ++m_data;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
  }
  this->m_islandActivationListeners.m_data[v3] = 0i64;
}

// File Line: 2249
// RVA: 0xD5AB60
void __fastcall hkpWorld::addWorldPostCollideListener(hkpWorld *this, hkpWorldPostCollideListener *worldListener)
{
  hkArray<hkpWorldPostCollideListener *,hkContainerHeapAllocator> *p_m_worldPostCollideListeners; // rbx

  p_m_worldPostCollideListeners = &this->m_worldPostCollideListeners;
  if ( this->m_worldPostCollideListeners.m_size == (this->m_worldPostCollideListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&p_m_worldPostCollideListeners->m_data,
      8);
  p_m_worldPostCollideListeners->m_data[p_m_worldPostCollideListeners->m_size++] = worldListener;
}

// File Line: 2256
// RVA: 0xD5ABC0
void __fastcall hkpWorld::removeWorldPostCollideListener(hkpWorld *this, hkpWorldPostCollideListener *worldListener)
{
  __int64 m_size; // r10
  int v3; // r9d
  __int64 v4; // r8
  hkpWorldPostCollideListener **m_data; // rax

  m_size = this->m_worldPostCollideListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_data = this->m_worldPostCollideListeners.m_data;
    while ( *m_data != worldListener )
    {
      ++v4;
      ++v3;
      ++m_data;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
  }
  this->m_worldPostCollideListeners.m_data[v3] = 0i64;
}

// File Line: 2265
// RVA: 0xD5AC20
void __fastcall hkpWorld::addWorldPostSimulationListener(hkpWorld *this, hkpWorldPostSimulationListener *worldListener)
{
  hkArray<hkpWorldPostSimulationListener *,hkContainerHeapAllocator> *p_m_worldPostSimulationListeners; // rbx

  p_m_worldPostSimulationListeners = &this->m_worldPostSimulationListeners;
  if ( this->m_worldPostSimulationListeners.m_size == (this->m_worldPostSimulationListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&p_m_worldPostSimulationListeners->m_data,
      8);
  p_m_worldPostSimulationListeners->m_data[p_m_worldPostSimulationListeners->m_size++] = worldListener;
}

// File Line: 2272
// RVA: 0xD5AC80
void __fastcall hkpWorld::removeWorldPostSimulationListener(
        hkpWorld *this,
        hkpWorldPostSimulationListener *worldListener)
{
  __int64 m_size; // r10
  int v3; // r9d
  __int64 v4; // r8
  hkpWorldPostSimulationListener **m_data; // rax

  m_size = this->m_worldPostSimulationListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_data = this->m_worldPostSimulationListeners.m_data;
    while ( *m_data != worldListener )
    {
      ++v4;
      ++v3;
      ++m_data;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
  }
  this->m_worldPostSimulationListeners.m_data[v3] = 0i64;
}

// File Line: 2280
// RVA: 0xD5ACE0
void __fastcall hkpWorld::addWorldPostIntegrateListener(hkpWorld *this, hkpWorldPostIntegrateListener *worldListener)
{
  hkArray<hkpWorldPostIntegrateListener *,hkContainerHeapAllocator> *p_m_worldPostIntegrateListeners; // rbx

  p_m_worldPostIntegrateListeners = &this->m_worldPostIntegrateListeners;
  if ( this->m_worldPostIntegrateListeners.m_size == (this->m_worldPostIntegrateListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&p_m_worldPostIntegrateListeners->m_data,
      8);
  p_m_worldPostIntegrateListeners->m_data[p_m_worldPostIntegrateListeners->m_size++] = worldListener;
}

// File Line: 2287
// RVA: 0xD5AD40
void __fastcall hkpWorld::removeWorldPostIntegrateListener(
        hkpWorld *this,
        hkpWorldPostIntegrateListener *worldListener)
{
  __int64 m_size; // r10
  int v3; // r9d
  __int64 v4; // r8
  hkpWorldPostIntegrateListener **m_data; // rax

  m_size = this->m_worldPostIntegrateListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_data = this->m_worldPostIntegrateListeners.m_data;
    while ( *m_data != worldListener )
    {
      ++v4;
      ++v3;
      ++m_data;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
  }
  this->m_worldPostIntegrateListeners.m_data[v3] = 0i64;
}

// File Line: 2296
// RVA: 0xD5ADA0
void __fastcall hkpWorld::addIslandPostCollideListener(hkpWorld *this, hkpIslandPostCollideListener *islandListener)
{
  hkArray<hkpIslandPostCollideListener *,hkContainerHeapAllocator> *p_m_islandPostCollideListeners; // rbx

  p_m_islandPostCollideListeners = &this->m_islandPostCollideListeners;
  if ( this->m_islandPostCollideListeners.m_size == (this->m_islandPostCollideListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&p_m_islandPostCollideListeners->m_data,
      8);
  p_m_islandPostCollideListeners->m_data[p_m_islandPostCollideListeners->m_size++] = islandListener;
}

// File Line: 2303
// RVA: 0xD5AE00
void __fastcall hkpWorld::removeIslandPostCollideListener(hkpWorld *this, hkpIslandPostCollideListener *islandListener)
{
  __int64 m_size; // r10
  int v3; // r9d
  __int64 v4; // r8
  hkpIslandPostCollideListener **m_data; // rax

  m_size = this->m_islandPostCollideListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_data = this->m_islandPostCollideListeners.m_data;
    while ( *m_data != islandListener )
    {
      ++v4;
      ++v3;
      ++m_data;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
  }
  this->m_islandPostCollideListeners.m_data[v3] = 0i64;
}

// File Line: 2312
// RVA: 0xD5AE60
void __fastcall hkpWorld::addIslandPostIntegrateListener(
        hkpWorld *this,
        hkpIslandPostIntegrateListener *islandListener)
{
  hkArray<hkpIslandPostIntegrateListener *,hkContainerHeapAllocator> *p_m_islandPostIntegrateListeners; // rbx

  p_m_islandPostIntegrateListeners = &this->m_islandPostIntegrateListeners;
  if ( this->m_islandPostIntegrateListeners.m_size == (this->m_islandPostIntegrateListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&p_m_islandPostIntegrateListeners->m_data,
      8);
  p_m_islandPostIntegrateListeners->m_data[p_m_islandPostIntegrateListeners->m_size++] = islandListener;
}

// File Line: 2319
// RVA: 0xD5AEC0
void __fastcall hkpWorld::removeIslandPostIntegrateListener(
        hkpWorld *this,
        hkpIslandPostIntegrateListener *islandListener)
{
  __int64 m_size; // r10
  int v3; // r9d
  __int64 v4; // r8
  hkpIslandPostIntegrateListener **m_data; // rax

  m_size = this->m_islandPostIntegrateListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_data = this->m_islandPostIntegrateListeners.m_data;
    while ( *m_data != islandListener )
    {
      ++v4;
      ++v3;
      ++m_data;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
  }
  this->m_islandPostIntegrateListeners.m_data[v3] = 0i64;
}

// File Line: 2328
// RVA: 0xD5AF20
void __fastcall hkpWorld::addContactListener(hkpWorld *this, hkpContactListener *collisionListener)
{
  hkArray<hkpContactListener *,hkContainerHeapAllocator> *p_m_contactListeners; // rbx

  p_m_contactListeners = &this->m_contactListeners;
  if ( this->m_contactListeners.m_size == (this->m_contactListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_contactListeners->m_data, 8);
  p_m_contactListeners->m_data[p_m_contactListeners->m_size++] = collisionListener;
}

// File Line: 2336
// RVA: 0xD5AF80
void __fastcall hkpWorld::removeContactListener(hkpWorld *this, hkpContactListener *collisionListener)
{
  __int64 m_size; // r10
  int v3; // r9d
  __int64 v4; // r8
  hkpContactListener **m_data; // rax

  m_size = this->m_contactListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_data = this->m_contactListeners.m_data;
    while ( *m_data != collisionListener )
    {
      ++v4;
      ++v3;
      ++m_data;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
  }
  this->m_contactListeners.m_data[v3] = 0i64;
}

// File Line: 2345
// RVA: 0xD5AFE0
void __fastcall hkpWorld::addWorldDeletionListener(hkpWorld *this, hkpWorldDeletionListener *worldListener)
{
  hkArray<hkpWorldDeletionListener *,hkContainerHeapAllocator> *p_m_worldDeletionListeners; // rbx

  p_m_worldDeletionListeners = &this->m_worldDeletionListeners;
  if ( this->m_worldDeletionListeners.m_size == (this->m_worldDeletionListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_worldDeletionListeners->m_data, 8);
  p_m_worldDeletionListeners->m_data[p_m_worldDeletionListeners->m_size++] = worldListener;
}

// File Line: 2352
// RVA: 0xD5B040
void __fastcall hkpWorld::removeWorldDeletionListener(hkpWorld *this, hkpWorldDeletionListener *worldListener)
{
  __int64 m_size; // r10
  int v3; // r9d
  __int64 v4; // r8
  hkpWorldDeletionListener **m_data; // rax

  m_size = this->m_worldDeletionListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_data = this->m_worldDeletionListeners.m_data;
    while ( *m_data != worldListener )
    {
      ++v4;
      ++v3;
      ++m_data;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
  }
  this->m_worldDeletionListeners.m_data[v3] = 0i64;
}

// File Line: 2360
// RVA: 0xD5B0A0
void __fastcall hkpWorld::addContactImpulseLimitBreachedListener(
        hkpWorld *this,
        hkpContactImpulseLimitBreachedListener *listener)
{
  hkArray<hkpContactImpulseLimitBreachedListener *,hkContainerHeapAllocator> *p_m_contactImpulseLimitBreachedListeners; // rbx

  p_m_contactImpulseLimitBreachedListeners = &this->m_contactImpulseLimitBreachedListeners;
  if ( this->m_contactImpulseLimitBreachedListeners.m_size == (this->m_contactImpulseLimitBreachedListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&p_m_contactImpulseLimitBreachedListeners->m_data,
      8);
  p_m_contactImpulseLimitBreachedListeners->m_data[p_m_contactImpulseLimitBreachedListeners->m_size++] = listener;
}

// File Line: 2367
// RVA: 0xD5B100
void __fastcall hkpWorld::removeContactImpulseLimitBreachedListener(
        hkpWorld *this,
        hkpContactImpulseLimitBreachedListener *listener)
{
  __int64 m_size; // r10
  int v3; // r9d
  __int64 v4; // r8
  hkpContactImpulseLimitBreachedListener **m_data; // rax

  m_size = this->m_contactImpulseLimitBreachedListeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_data = this->m_contactImpulseLimitBreachedListeners.m_data;
    while ( *m_data != listener )
    {
      ++v4;
      ++v3;
      ++m_data;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
  }
  this->m_contactImpulseLimitBreachedListeners.m_data[v3] = 0i64;
}

// File Line: 2375
// RVA: 0xD5B160
void __fastcall hkpWorld::addWorldExtension(hkpWorld *this, hkpWorldExtension *extension)
{
  hkArray<hkpWorldExtension *,hkContainerHeapAllocator> *p_m_worldExtensions; // rbx
  hkBaseObjectVtbl *vfptr; // rax

  p_m_worldExtensions = &this->m_worldExtensions;
  if ( this->m_worldExtensions.m_size == (this->m_worldExtensions.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_worldExtensions->m_data, 8);
  p_m_worldExtensions->m_data[p_m_worldExtensions->m_size++] = extension;
  hkReferencedObject::addReference(extension);
  vfptr = extension->vfptr;
  extension->m_world = this;
  ((void (__fastcall *)(hkpWorldExtension *, hkpWorld *))vfptr[1].__first_virtual_table_function__)(extension, this);
}

// File Line: 2385
// RVA: 0xD5B1E0
void __fastcall hkpWorld::removeWorldExtension(hkpWorld *this, hkpWorldExtension *extension)
{
  __int64 m_size; // rdx
  int v4; // ebx
  __int64 v5; // r8
  hkpWorldExtension **m_data; // rax
  __int64 v8; // rax

  m_size = this->m_worldExtensions.m_size;
  v4 = 0;
  v5 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    v4 = -1;
  }
  else
  {
    m_data = this->m_worldExtensions.m_data;
    while ( *m_data != extension )
    {
      ++v5;
      ++v4;
      ++m_data;
      if ( v5 >= m_size )
        goto LABEL_5;
    }
  }
  ((void (__fastcall *)(hkpWorldExtension *, hkpWorld *, __int64))extension->vfptr[2].__vecDelDtor)(extension, this, v5);
  extension->m_world = 0i64;
  hkReferencedObject::removeReference(extension);
  v8 = --this->m_worldExtensions.m_size;
  if ( (_DWORD)v8 != v4 )
    this->m_worldExtensions.m_data[v4] = this->m_worldExtensions.m_data[v8];
}

// File Line: 2395
// RVA: 0xD5B290
hkpWorldExtension *__fastcall hkpWorld::findWorldExtension(hkpWorld *this, int id)
{
  __int64 m_size; // r9
  __int64 v3; // r8
  hkpWorldExtension **i; // rax

  m_size = this->m_worldExtensions.m_size;
  v3 = 0i64;
  if ( m_size <= 0 )
    return 0i64;
  for ( i = this->m_worldExtensions.m_data; (*i)->m_id != id; ++i )
  {
    if ( ++v3 >= m_size )
      return 0i64;
  }
  return *i;
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
  unsigned int v3; // edi
  int v4; // eax
  hkpBroadPhase *m_broadPhase; // rcx

  hkpWorld::lock(this);
  hkpWorldMemoryUtil::watchHeapMemory(this);
  v3 = ((__int64 (__fastcall *)(hkpSimulation *))this->m_simulation->vfptr[1].__first_virtual_table_function__)(this->m_simulation);
  v4 = ((__int64 (__fastcall *)(hkpBroadPhase *))this->m_broadPhase->vfptr[1].__first_virtual_table_function__)(this->m_broadPhase);
  m_broadPhase = this->m_broadPhase;
  if ( v4 == 2 )
  {
    hkpBroadPhase::s_updateTreeBroadPhaseFunction(m_broadPhase, physicsDeltaTime);
  }
  else if ( ((unsigned int (__fastcall *)(hkpBroadPhase *))m_broadPhase->vfptr[1].__first_virtual_table_function__)(m_broadPhase) == 3 )
  {
    hkpBroadPhase::s_updateTreeBroadPhaseFunction32(this->m_broadPhase, physicsDeltaTime);
  }
  hkpWorld::unlock(this);
  return v3;
}

// File Line: 2458
// RVA: 0xD5C6B0
__int64 __fastcall hkpWorld::integrate(hkpWorld *this, float physicsDeltaTime)
{
  unsigned int v3; // ebx

  hkpWorld::lock(this);
  v3 = ((__int64 (__fastcall *)(hkpSimulation *))this->m_simulation->vfptr[2].__vecDelDtor)(this->m_simulation);
  hkpWorld::unlock(this);
  return v3;
}

// File Line: 2466
// RVA: 0xD5C700
__int64 __fastcall hkpWorld::collide(hkpWorld *this)
{
  unsigned int v2; // ebx

  hkpWorld::lock(this);
  v2 = ((__int64 (__fastcall *)(hkpSimulation *))this->m_simulation->vfptr[2].__first_virtual_table_function__)(this->m_simulation);
  hkpWorld::unlock(this);
  return v2;
}

// File Line: 2474
// RVA: 0xD5C740
__int64 __fastcall hkpWorld::advanceTime(hkpWorld *this)
{
  unsigned int v2; // ebx

  hkpWorld::lock(this);
  v2 = ((__int64 (__fastcall *)(hkpSimulation *))this->m_simulation->vfptr[3].__vecDelDtor)(this->m_simulation);
  hkpWorld::unlock(this);
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
hkpStepResult __fastcall hkpWorld::stepMultithreaded(
        hkpWorld *this,
        hkJobQueue *jobQueue,
        hkJobThreadPool *threadPool,
        float physicsDeltaTime)
{
  hkpStepResult result; // eax

  result = hkpWorld::initMtStep(this, jobQueue, physicsDeltaTime);
  if ( result == HK_STEP_RESULT_SUCCESS )
  {
    ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, __int64))threadPool->vfptr[5].__first_virtual_table_function__)(
      threadPool,
      jobQueue,
      20i64);
    hkJobQueue::processAllJobs(jobQueue, 1);
    ((void (__fastcall *)(hkJobThreadPool *))threadPool->vfptr[2].__vecDelDtor)(threadPool);
    return hkpWorld::finishMtStep(this, jobQueue, threadPool);
  }
  return result;
}

// File Line: 2525
// RVA: 0xD5C820
__int64 __fastcall hkpWorld::initMtStep(hkpWorld *this, hkJobQueue *jobQueue, float physicsDeltaTime)
{
  if ( this->m_memoryWatchDog.m_pntr )
  {
    hkpWorld::lock(this);
    hkpWorldMemoryUtil::watchHeapMemory(this);
    hkpWorld::unlock(this);
  }
  return ((__int64 (__fastcall *)(hkpSimulation *, hkJobQueue *))this->m_simulation->vfptr[3].__first_virtual_table_function__)(
           this->m_simulation,
           jobQueue);
}

// File Line: 2545
// RVA: 0xD5C880
__int64 __fastcall hkpWorld::finishMtStep(hkpWorld *this, hkJobQueue *jobQueue, hkJobThreadPool *threadPool)
{
  __int64 result; // rax
  int v5; // eax
  hkpBroadPhase *m_broadPhase; // rcx

  result = ((__int64 (__fastcall *)(hkpSimulation *, hkJobQueue *, hkJobThreadPool *))this->m_simulation->vfptr[4].__vecDelDtor)(
             this->m_simulation,
             jobQueue,
             threadPool);
  if ( !(_DWORD)result )
  {
    v5 = ((__int64 (__fastcall *)(hkpBroadPhase *))this->m_broadPhase->vfptr[1].__first_virtual_table_function__)(this->m_broadPhase);
    m_broadPhase = this->m_broadPhase;
    if ( v5 == 2 )
    {
      hkpBroadPhase::s_updateTreeBroadPhaseFunction(m_broadPhase, this->m_simulation->m_physicsDeltaTime);
      return 0i64;
    }
    else
    {
      if ( ((unsigned int (__fastcall *)(hkpBroadPhase *))m_broadPhase->vfptr[1].__first_virtual_table_function__)(m_broadPhase) == 3 )
        hkpBroadPhase::s_updateTreeBroadPhaseFunction32(this->m_broadPhase, this->m_simulation->m_physicsDeltaTime);
      return 0i64;
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
  hkpCollisionFilter *m_collisionFilter; // rsi
  hkpCollisionFilter *m_pntr; // rcx
  hkpConvexListFilter *m_convexListFilter; // rsi
  hkpConvexListFilter *v7; // rcx
  hkpBroadPhaseBorder *m_broadPhaseBorder; // rax
  hkpWorldCinfo::BroadPhaseBorderBehaviour m_type; // eax
  hkpBroadPhaseBorder *v10; // rax
  hkWorldMemoryAvailableWatchDog *v11; // rcx
  hkWorldMemoryAvailableWatchDog *v12; // rcx
  char m_bool; // [rsp+30h] [rbp+8h]

  info->m_gravity = this->m_gravity;
  info->m_broadPhaseQuerySize = this->m_broadPhaseQuerySize;
  info->m_broadPhaseWorldAabb = *(hkAabb *)this->m_broadPhaseExtents[0].m_quad.m128_i8;
  info->m_collisionTolerance = this->m_collisionInput->m_tolerance.m_storage;
  m_collisionFilter = this->m_collisionFilter;
  if ( m_collisionFilter )
    hkReferencedObject::addReference(this->m_collisionFilter);
  m_pntr = info->m_collisionFilter.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  info->m_collisionFilter.m_pntr = m_collisionFilter;
  m_convexListFilter = this->m_convexListFilter;
  if ( m_convexListFilter )
    hkReferencedObject::addReference(this->m_convexListFilter);
  v7 = info->m_convexListFilter.m_pntr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  info->m_convexListFilter.m_pntr = m_convexListFilter;
  info->m_broadPhaseType.m_storage = this->m_broadPhaseType.m_storage;
  m_broadPhaseBorder = this->m_broadPhaseBorder;
  if ( m_broadPhaseBorder )
    m_type = m_broadPhaseBorder->m_type;
  else
    LOBYTE(m_type) = 3;
  info->m_broadPhaseBorderBehaviour.m_storage = m_type;
  v10 = this->m_broadPhaseBorder;
  if ( v10 )
    m_bool = v10->m_postponeAndSortCallbacks.m_bool;
  else
    m_bool = 0;
  info->m_mtPostponeAndSortBroadPhaseBorderCallbacks.m_bool = m_bool;
  info->m_expectedMaxLinearVelocity = this->m_collisionDispatcher->m_expectedMaxLinearVelocity;
  info->m_expectedMinPsiDeltaTime = this->m_collisionDispatcher->m_expectedMinPsiDeltaTime;
  info->m_snapCollisionToConvexEdgeThreshold = this->m_snapCollisionToConvexEdgeThreshold;
  info->m_snapCollisionToConvexEdgeThreshold = this->m_snapCollisionToConcaveEdgeThreshold;
  info->m_enableToiWeldRejection.m_bool = this->m_enableToiWeldRejection.m_bool;
  v11 = this->m_memoryWatchDog.m_pntr;
  if ( v11 )
    hkReferencedObject::addReference(v11);
  v12 = info->m_memoryWatchDog.m_pntr;
  if ( v12 )
    hkReferencedObject::removeReference(v12);
  info->m_memoryWatchDog.m_pntr = this->m_memoryWatchDog.m_pntr;
  info->m_broadPhaseNumMarkers = this->m_broadPhaseNumMarkers;
  info->m_sizeOfToiEventQueue = this->m_sizeOfToiEventQueue;
  info->m_contactPointGeneration.m_storage = this->m_contactPointGeneration.m_storage;
  info->m_allowToSkipConfirmedCallbacks.m_bool = this->m_collisionInput->m_allowToSkipConfirmedCallbacks.m_bool;
  info->m_contactRestingVelocity = this->m_dynamicsStepInfo.m_solverInfo.m_contactRestingVelocity;
  info->m_solverTau = this->m_dynamicsStepInfo.m_solverInfo.m_tau;
  info->m_solverDamp = this->m_dynamicsStepInfo.m_solverInfo.m_damping;
  info->m_solverIterations = this->m_dynamicsStepInfo.m_solverInfo.m_numSteps;
  info->m_solverMicrosteps = this->m_dynamicsStepInfo.m_solverInfo.m_numMicroSteps;
  info->m_maxConstraintViolation = fsqrt(this->m_dynamicsStepInfo.m_solverInfo.m_maxConstraintViolationSqrd);
  info->m_forceCoherentConstraintOrderingInSolver.m_bool = this->m_dynamicsStepInfo.m_solverInfo.m_forceCoherentConstraintOrderingInSolver.m_bool;
  info->m_deactivationNumInactiveFramesSelectFlag0 = this->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0];
  info->m_deactivationNumInactiveFramesSelectFlag1 = this->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1];
  info->m_deactivationIntegrateCounter = this->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter;
  info->m_iterativeLinearCastEarlyOutDistance = this->m_collisionInput->m_config->m_iterativeLinearCastEarlyOutDistance;
  info->m_iterativeLinearCastMaxIterations = this->m_collisionInput->m_config->m_iterativeLinearCastMaxIterations;
  info->m_enableDeprecatedWelding.m_bool = this->m_collisionInput->m_enableDeprecatedWelding.m_bool;
  info->m_shouldActivateOnRigidBodyTransformChange.m_bool = this->m_shouldActivateOnRigidBodyTransformChange.m_bool;
  info->m_toiCollisionResponseRotateNormal = this->m_toiCollisionResponseRotateNormal;
  info->m_useCompoundSpuElf.m_bool = this->m_useCompoundSpuElf.m_bool;
  info->m_maxSectorsPerMidphaseCollideTask = this->m_maxSectorsPerMidphaseCollideTask;
  info->m_maxSectorsPerNarrowphaseCollideTask = this->m_maxSectorsPerNarrowphaseCollideTask;
  info->m_processToisMultithreaded.m_bool = this->m_processToisMultithreaded.m_bool;
  info->m_maxEntriesPerToiMidphaseCollideTask = this->m_maxEntriesPerToiMidphaseCollideTask;
  info->m_maxEntriesPerToiNarrowphaseCollideTask = this->m_maxEntriesPerToiNarrowphaseCollideTask;
  info->m_maxNumToiCollisionPairsSinglethreaded = this->m_maxNumToiCollisionPairsSinglethreaded;
  info->m_deactivationReferenceDistance = this->m_deactivationReferenceDistance;
  info->m_numToisTillAllowedPenetrationSimplifiedToi = this->m_numToisTillAllowedPenetrationSimplifiedToi;
  info->m_numToisTillAllowedPenetrationToi = this->m_numToisTillAllowedPenetrationToi;
  info->m_numToisTillAllowedPenetrationToiHigher = this->m_numToisTillAllowedPenetrationToiHigher;
  info->m_numToisTillAllowedPenetrationToiForced = this->m_numToisTillAllowedPenetrationToiForced;
  info->m_enableDeactivation.m_bool = this->m_wantDeactivation.m_bool;
  info->m_simulationType.m_storage = this->m_simulationType.m_storage;
  info->m_frameMarkerPsiSnap = this->m_simulation->m_frameMarkerPsiSnap;
  info->m_enableSimulationIslands.m_bool = this->m_wantSimulationIslands.m_bool;
  info->m_processActionsInSingleThread.m_bool = this->m_processActionsInSingleThread.m_bool;
  info->m_allowIntegrationOfIslandsWithoutConstraintsInASeparateJob.m_bool = this->m_allowIntegrationOfIslandsWithoutConstraintsInASeparateJob.m_bool;
  info->m_minDesiredIslandSize = this->m_minDesiredIslandSize;
  info->m_fireCollisionCallbacks.m_bool = hkpWorld::findWorldExtension(this, 1001) != 0i64;
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
  hkWorldMemoryAvailableWatchDog *m_pntr; // rcx

  if ( watchDog )
    hkReferencedObject::addReference(watchDog);
  m_pntr = this->m_memoryWatchDog.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_memoryWatchDog.m_pntr = watchDog;
}

// File Line: 2852
// RVA: 0xD55700
void __fastcall hkpWorld::hkpWorld(hkpWorld *this, hkpWorldCinfo *infoBase, unsigned int sdkversion)
{
  _QWORD **Value; // rax
  hkpViolatedConstraintArray *v6; // rax
  _QWORD **v7; // rax
  hkpWorldOperationQueue *v8; // rax
  hkpWorldOperationQueue *v9; // rax
  __m128 v10; // xmm15
  __m128 v11; // xmm14
  int m_pntr; // r8d
  char m_storage; // al
  hkpBroadPhase *m_broadPhase; // rbx
  int m_broadPhaseQuerySize; // eax
  hkOstream *v16; // rax
  hkOstream *v17; // rax
  hkOstream *v18; // rax
  hkOstream *v19; // rax
  float v20; // xmm6_4
  hkVector4f v21; // xmm7
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm3_4
  float v25; // xmm2_4
  char m_broadPhaseNumMarkers; // di
  float v27; // xmm5_4
  __m128 m_pntr_high; // xmm4
  int m_solverMicrosteps; // xmm0_4
  float v30; // xmm13_4
  char m_maxConstraintViolation_low; // al
  float v32; // xmm5_4
  __int128 v33; // xmm1
  int v34; // eax
  unsigned int m_expectedMaxLinearVelocity_low; // eax
  __m128 v36; // xmm0
  __m128i v37; // xmm0
  int m_sizeOfToiEventQueue; // eax
  __m128i v39; // xmm0
  __m128 v40; // xmm7
  __m128 v41; // xmm3
  __m128 v42; // xmm2
  float v43; // xmm10_4
  float m_invNumSteps; // xmm0_4
  float v45; // xmm2_4
  float v46; // xmm7_4
  float v47; // xmm6_4
  float v48; // xmm5_4
  float v49; // xmm13_4
  float v50; // xmm2_4
  hkWorldMemoryAvailableWatchDog *v51; // rbx
  float v52; // xmm2_4
  float v53; // xmm2_4
  float v54; // xmm1_4
  hkWorldMemoryAvailableWatchDog *v55; // rcx
  char v56; // al
  char m_maxSectorsPerMidphaseCollideTask; // cl
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
  hkpPhantomBroadPhaseListener *m_phantomBroadPhaseListener; // rax
  hkpBroadPhaseListener *v69; // rcx
  hkpPhantomBroadPhaseListener *v70; // rcx
  hkpBroadPhaseListener *v71; // rcx
  hkpPhantomBroadPhaseListener *v72; // rcx
  hkpBroadPhaseListener *v73; // rcx
  hkpEntityEntityBroadPhaseListener *m_entityEntityBroadPhaseListener; // rcx
  hkpBroadPhaseListener *v75; // rcx
  hkpBroadPhaseBorderListener *m_broadPhaseBorderListener; // rcx
  hkpBroadPhaseListener *v77; // rcx
  hkpBroadPhaseBorderListener *v78; // rcx
  hkpBroadPhaseListener *v79; // rcx
  hkpBroadPhaseBorderListener *v80; // rcx
  hkpBroadPhaseListener *v81; // rcx
  hkpBroadPhaseBorderListener *v82; // rcx
  hkpBroadPhaseListener *v83; // rcx
  hkpBroadPhaseBorderListener *v84; // rax
  hkpBroadPhaseListener *v85; // rcx
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
  __int64 v104; // r14
  int v105; // xmm0_4
  char v106; // bl
  char v107; // al
  _QWORD **v108; // rax
  _DWORD *v109; // rax
  int v110; // xmm0_4
  __m128 v111; // xmm14
  __m128 v112; // xmm1
  __int64 v113; // rax
  __m128 v114; // xmm2
  __m128 v115; // xmm2
  bool v116; // zf
  char v117; // r14
  _QWORD **v118; // rax
  hkCriticalSection *v119; // rax
  _QWORD **v120; // rax
  hkCriticalSection *v121; // rax
  hkpSimulation *Discrete; // rax
  _QWORD **v123; // rax
  hkCriticalSection *v124; // rax
  int m_maxEntriesPerToiMidphaseCollideTask; // xmm0_4
  __m128 v126; // xmm1
  __m128 v127; // xmm2
  __m128 v128; // xmm1
  float v129; // xmm6_4
  float v130; // xmm5_4
  float m_deactivationReferenceDistance; // xmm4_4
  float m_toiCollisionResponseRotateNormal; // xmm3_4
  hkpProcessCollisionInput *m_collisionInput; // rax
  hkpCollisionDispatcher *m_collisionDispatcher; // rcx
  float v135; // xmm2_4
  float v136; // xmm1_4
  float v137; // xmm0_4
  _QWORD **v138; // rax
  hkpSimulationIsland *v139; // rax
  hkpSimulationIsland *v140; // rax
  _QWORD **v141; // rax
  hkpSimulationIsland *v142; // rax
  hkpSimulationIsland *v143; // rax
  hkpSimulationIsland *v144; // rbx
  _QWORD **v145; // rax
  hkpRigidBody *v146; // rax
  hkpRigidBody *v147; // rax
  char v148; // bl
  _QWORD **v149; // rax
  hkpBroadPhaseBorder *v150; // rax
  hkpBroadPhaseBorder *v151; // rax
  _QWORD **v152; // rax
  hkpDefaultWorldMaintenanceMgr *v153; // rax
  hkpWorldMaintenanceMgr *v154; // rax
  hkpWorldMaintenanceMgr *v155; // rcx
  hkpWorld *v156; // rdx
  _QWORD **v157; // rax
  hkpMtThreadStructure *v158; // rax
  hkReferencedObject *v159; // rcx
  hkpCollisionDispatcher::InitCollisionQualityInfo v160; // [rsp+20h] [rbp-B8h] BYREF
  hkpWorldCinfo v161; // [rsp+50h] [rbp-88h] BYREF
  int v162; // [rsp+1B8h] [rbp+E0h]
  char v163; // [rsp+1DCh] [rbp+104h]
  char buf[712]; // [rsp+208h] [rbp+130h] BYREF
  float v165; // [rsp+4E8h] [rbp+410h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpWorld::`vftable;
  this->m_activeSimulationIslands.m_data = 0i64;
  this->m_activeSimulationIslands.m_size = 0;
  this->m_activeSimulationIslands.m_capacityAndFlags = 0x80000000;
  this->m_inactiveSimulationIslands.m_data = 0i64;
  this->m_inactiveSimulationIslands.m_size = 0;
  this->m_inactiveSimulationIslands.m_capacityAndFlags = 0x80000000;
  this->m_dirtySimulationIslands.m_data = 0i64;
  this->m_dirtySimulationIslands.m_size = 0;
  this->m_dirtySimulationIslands.m_capacityAndFlags = 0x80000000;
  this->m_memoryWatchDog.m_pntr = 0i64;
  this->m_multiThreadCheck.m_threadId = -15;
  this->m_multiThreadCheck.m_markCount = 0x8000;
  this->m_phantoms.m_data = 0i64;
  this->m_phantoms.m_size = 0;
  this->m_phantoms.m_capacityAndFlags = 0x80000000;
  this->m_actionListeners.m_data = 0i64;
  this->m_actionListeners.m_size = 0;
  this->m_actionListeners.m_capacityAndFlags = 0x80000000;
  this->m_entityListeners.m_data = 0i64;
  this->m_entityListeners.m_size = 0;
  this->m_entityListeners.m_capacityAndFlags = 0x80000000;
  this->m_phantomListeners.m_data = 0i64;
  this->m_phantomListeners.m_size = 0;
  this->m_phantomListeners.m_capacityAndFlags = 0x80000000;
  this->m_constraintListeners.m_data = 0i64;
  this->m_constraintListeners.m_size = 0;
  this->m_constraintListeners.m_capacityAndFlags = 0x80000000;
  this->m_worldDeletionListeners.m_data = 0i64;
  this->m_worldDeletionListeners.m_size = 0;
  this->m_worldDeletionListeners.m_capacityAndFlags = 0x80000000;
  this->m_islandActivationListeners.m_data = 0i64;
  this->m_islandActivationListeners.m_size = 0;
  this->m_islandActivationListeners.m_capacityAndFlags = 0x80000000;
  this->m_worldPostSimulationListeners.m_data = 0i64;
  this->m_worldPostSimulationListeners.m_size = 0;
  this->m_worldPostSimulationListeners.m_capacityAndFlags = 0x80000000;
  this->m_worldPostIntegrateListeners.m_data = 0i64;
  this->m_worldPostIntegrateListeners.m_size = 0;
  this->m_worldPostIntegrateListeners.m_capacityAndFlags = 0x80000000;
  this->m_worldPostCollideListeners.m_data = 0i64;
  this->m_worldPostCollideListeners.m_size = 0;
  this->m_worldPostCollideListeners.m_capacityAndFlags = 0x80000000;
  this->m_islandPostIntegrateListeners.m_data = 0i64;
  this->m_islandPostIntegrateListeners.m_size = 0;
  this->m_islandPostIntegrateListeners.m_capacityAndFlags = 0x80000000;
  this->m_islandPostCollideListeners.m_data = 0i64;
  this->m_islandPostCollideListeners.m_size = 0;
  this->m_islandPostCollideListeners.m_capacityAndFlags = 0x80000000;
  this->m_contactListeners.m_data = 0i64;
  this->m_contactListeners.m_size = 0;
  this->m_contactListeners.m_capacityAndFlags = 0x80000000;
  this->m_contactImpulseLimitBreachedListeners.m_data = 0i64;
  this->m_contactImpulseLimitBreachedListeners.m_size = 0;
  this->m_contactImpulseLimitBreachedListeners.m_capacityAndFlags = 0x80000000;
  this->m_worldExtensions.m_data = 0i64;
  this->m_worldExtensions.m_size = 0;
  this->m_worldExtensions.m_capacityAndFlags = 0x80000000;
  hkpWorldCinfo::hkpWorldCinfo(&v161, infoBase);
  this->m_lastEntityUid = -1;
  this->m_lastConstraintUid = -1;
  this->m_isLocked = 0;
  this->m_assertOnRunningOutOfSolverMemory.m_bool = 1;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkpViolatedConstraintArray *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                       Value[11],
                                       1032i64);
  if ( v6 )
    v6->m_nextFreeElement = 0;
  else
    v6 = 0i64;
  this->m_violatedConstraintArray = v6;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkpWorldOperationQueue *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v7[11] + 8i64))(v7[11], 56i64);
  if ( v8 )
    hkpWorldOperationQueue::hkpWorldOperationQueue(v8, this);
  else
    v9 = 0i64;
  v10 = *(__m128 *)&v161.m_memSizeAndFlags;
  v11 = *(__m128 *)((char *)&v161.m_gravity.m_quad + 8);
  m_pntr = (int)v161.m_collisionFilter.m_pntr;
  this->m_pendingOperations = v9;
  m_storage = v161.m_broadPhaseType.m_storage;
  this->m_pendingOperationQueues = 0i64;
  *(_QWORD *)&this->m_pendingOperationsCount = 0i64;
  *(_QWORD *)&this->m_criticalOperationsLockCount = 0i64;
  *(_WORD *)&this->m_blockExecutingPendingOperations.m_bool = 256;
  this->m_modifyConstraintCriticalSection = 0i64;
  this->m_propertyMasterLock = 0i64;
  this->m_islandDirtyListCriticalSection = 0i64;
  this->m_pendingOperationQueueCount = 1;
  this->m_destructionWorld = 0i64;
  this->m_broadPhaseExtents[0].m_quad = v10;
  this->m_broadPhaseExtents[1].m_quad = v11;
  this->m_broadPhaseNumMarkers = m_pntr;
  this->m_broadPhaseType.m_storage = m_storage;
  this->m_broadPhase = 0i64;
  if ( m_storage != 1 )
    this->m_broadPhase = hkpBroadPhase::s_createSweepAndPruneBroadPhaseFunction(
                           this->m_broadPhaseExtents,
                           &this->m_broadPhaseExtents[1],
                           m_pntr);
  if ( (unsigned __int8)(this->m_broadPhaseType.m_storage - 1) <= 1u )
  {
    m_broadPhase = this->m_broadPhase;
    this->m_broadPhase = hkpBroadPhase::s_createTreeBroadPhaseFunction(m_broadPhase);
    if ( m_broadPhase )
      hkReferencedObject::removeReference(m_broadPhase);
  }
  m_broadPhaseQuerySize = v161.m_broadPhaseQuerySize;
  this->m_broadPhaseQuerySize = v161.m_broadPhaseQuerySize;
  this->m_broadPhaseUpdateSize = m_broadPhaseQuerySize / 2;
  this->m_sizeOfToiEventQueue = v161.m_broadPhaseWorldAabb.m_max.m_quad.m128_i32[1];
  if ( sdkversion != 20130200 )
  {
    hkErrStream::hkErrStream((hkErrStream *)&v160, buf, 512);
    v16 = hkOstream::operator<<((hkOstream *)&v160, "** Havok libs built with version [");
    v17 = hkOstream::operator<<(v16, 0x1332998u);
    v18 = hkOstream::operator<<(v17, "], used with code built with [");
    v19 = hkOstream::operator<<(v18, sdkversion);
    hkOstream::operator<<(v19, "]. **");
    if ( (unsigned int)hkError::messageError(0x53C94B42u, buf, "World\\hkpWorld.cpp", 2962) )
      __debugbreak();
    hkOstream::~hkOstream((hkOstream *)&v160);
  }
  v20 = *(float *)&v161.m_memoryWatchDog.m_pntr;
  v21.m_quad = (__m128)v161.m_gravity;
  v22 = *((float *)&v161.m_memoryWatchDog.m_pntr + 1);
  v23 = *(float *)&v161.m_memoryWatchDog.m_pntr;
  this->m_gravity = v161.m_gravity;
  hkpWeldingUtility::initWeldingTable(v23, v22);
  v24 = *(float *)&v161.m_convexListFilter.m_pntr;
  v25 = *((float *)&v161.m_convexListFilter.m_pntr + 1);
  m_broadPhaseNumMarkers = v161.m_broadPhaseNumMarkers;
  v27 = *(float *)&v161.m_convexListFilter.m_pntr;
  m_pntr_high = (__m128)HIDWORD(v161.m_convexListFilter.m_pntr);
  m_solverMicrosteps = v161.m_solverMicrosteps;
  v30 = *(float *)&v161.m_solverIterations;
  this->m_shouldActivateOnRigidBodyTransformChange.m_bool = HIBYTE(v161.m_solverDamp);
  m_maxConstraintViolation_low = LOBYTE(v161.m_maxConstraintViolation);
  this->m_enableToiWeldRejection.m_bool = m_broadPhaseNumMarkers;
  v32 = v27 * 0.5;
  m_pntr_high.m128_f32[0] = m_pntr_high.m128_f32[0] / v24;
  v33 = (unsigned int)FLOAT_1_0;
  LODWORD(this->m_toiCollisionResponseRotateNormal) = m_solverMicrosteps;
  this->m_snapCollisionToConvexEdgeThreshold = v20;
  this->m_snapCollisionToConcaveEdgeThreshold = v20;
  this->m_useCompoundSpuElf.m_bool = m_maxConstraintViolation_low;
  v34 = *(_DWORD *)&v161.m_forceCoherentConstraintOrderingInSolver.m_bool;
  this->m_deactivationReferenceDistance = v30;
  *(float *)&v33 = 1.0 / v25;
  this->m_maxSectorsPerMidphaseCollideTask = v34;
  this->m_maxSectorsPerNarrowphaseCollideTask = LODWORD(v161.m_snapCollisionToConvexEdgeThreshold);
  this->m_processToisMultithreaded.m_bool = LOBYTE(v161.m_snapCollisionToConcaveEdgeThreshold);
  this->m_maxEntriesPerToiMidphaseCollideTask = *(_DWORD *)&v161.m_enableToiWeldRejection.m_bool;
  this->m_maxEntriesPerToiNarrowphaseCollideTask = LODWORD(v161.m_iterativeLinearCastEarlyOutDistance);
  this->m_maxNumToiCollisionPairsSinglethreaded = v161.m_iterativeLinearCastMaxIterations;
  m_expectedMaxLinearVelocity_low = LODWORD(v161.m_expectedMaxLinearVelocity);
  this->m_dynamicsStepInfo.m_solverInfo.m_dampDivFrictionTau = v25 / v32;
  v36 = (__m128)v33;
  v36.m128_f32[0] = (float)(1.0 / v25) * v24;
  this->m_dynamicsStepInfo.m_solverInfo.m_numSteps = m_expectedMaxLinearVelocity_low;
  this->m_dynamicsStepInfo.m_solverInfo.m_tau = v24;
  this->m_dynamicsStepInfo.m_solverInfo.m_frictionTauDivDamp = (float)(1.0 / v25) * v32;
  this->m_dynamicsStepInfo.m_solverInfo.m_frictionTau = v32;
  this->m_dynamicsStepInfo.m_solverInfo.m_damping = v25;
  LODWORD(this->m_dynamicsStepInfo.m_solverInfo.m_tauDivDamp) = v36.m128_i32[0];
  LODWORD(this->m_dynamicsStepInfo.m_solverInfo.m_dampDivTau) = m_pntr_high.m128_i32[0];
  this->m_dynamicsStepInfo.m_solverInfo.m_invIntegrateVelocityFactor.m_quad = _mm_shuffle_ps(
                                                                                m_pntr_high,
                                                                                m_pntr_high,
                                                                                0);
  this->m_dynamicsStepInfo.m_solverInfo.m_integrateVelocityFactor.m_quad = _mm_shuffle_ps(v36, v36, 0);
  this->m_dynamicsStepInfo.m_solverInfo.m_contactRestingVelocity = v161.m_contactRestingVelocity;
  v37 = _mm_cvtsi32_si128(m_expectedMaxLinearVelocity_low);
  m_sizeOfToiEventQueue = v161.m_sizeOfToiEventQueue;
  this->m_dynamicsStepInfo.m_solverInfo.m_numMicroSteps = v161.m_sizeOfToiEventQueue;
  *(float *)&v33 = 1.0 / _mm_cvtepi32_ps(v37).m128_f32[0];
  *(float *)v37.m128i_i32 = v161.m_expectedMinPsiDeltaTime * v161.m_expectedMinPsiDeltaTime;
  LODWORD(this->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps) = v33;
  LODWORD(this->m_dynamicsStepInfo.m_solverInfo.m_maxConstraintViolationSqrd) = v37.m128i_i32[0];
  v39 = _mm_cvtsi32_si128(m_sizeOfToiEventQueue);
  this->m_dynamicsStepInfo.m_solverInfo.m_forceCoherentConstraintOrderingInSolver.m_bool = *((_BYTE *)&v161.m_expectedMinPsiDeltaTime
                                                                                           + 4);
  LOBYTE(m_sizeOfToiEventQueue) = LOBYTE(v161.m_solverDamp);
  this->m_dynamicsStepInfo.m_solverInfo.m_invNumMicroSteps = 1.0 / _mm_cvtepi32_ps(v39).m128_f32[0];
  *(_WORD *)this->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag = __PAIR16__(
                                                                                                BYTE1(v161.m_solverDamp),
                                                                                                m_sizeOfToiEventQueue);
  v40 = _mm_mul_ps(v21.m_quad, v21.m_quad);
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter = BYTE2(v161.m_solverDamp);
  *(_QWORD *)&this->m_dynamicsStepInfo.m_solverInfo.m_deltaTime = 0i64;
  v41 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)), _mm_shuffle_ps(v40, v40, 170));
  v42 = _mm_rsqrt_ps(v41);
  v43 = _mm_andnot_ps(
          _mm_cmple_ps(v41, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v42, v41), v42)),
              _mm_mul_ps(*(__m128 *)_xmm, v42)),
            v41)).m128_f32[0];
  if ( v43 == 0.0 )
    v43 = FLOAT_9_8100004;
  m_invNumSteps = this->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[0].m_relativeSleepVelocityThreshold = 2.1267625e37;
  v45 = 1.0 / (float)(v43 * 0.00000011920929);
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[0].m_linearVelocityThresholdInv = v45;
  v46 = v30 * v30;
  v47 = (float)(v30 * 4.0) * (float)(v30 * 4.0);
  v48 = (float)(v30 * 2.0) * (float)(v30 * 2.0);
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[0].m_slowObjectVelocityMultiplier = 1.0
                                                                                             - (float)((float)((float)(v43 * 0.0) * v45) * (float)(m_invNumSteps * 0.016000001));
  v49 = (float)(v30 * 8.0) * (float)(v30 * 8.0);
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[0].m_angularVelocityThresholdInv = 1.0
                                                                                            / (float)((float)(v43 * 0.00000011920929) * (float)(v43 * 0.1));
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[0].m_maxDistSqrd[0] = v46;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[0].m_maxDistSqrd[1] = v47;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[0].m_maxRotSqrd[0] = v48;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[0].m_maxRotSqrd[1] = v49;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[1].m_slowObjectVelocityMultiplier = 1.0
                                                                                             - (float)((float)((float)(v43 * 0.0) * v45) * (float)(this->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps * 0.016000001));
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[1].m_linearVelocityThresholdInv = v45;
  v50 = 1.0 / (float)(v43 * 0.0099999998);
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[1].m_angularVelocityThresholdInv = 1.0
                                                                                            / (float)((float)(v43 * 0.00000011920929) * (float)(v43 * 0.1));
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[1].m_relativeSleepVelocityThreshold = 2.1267625e37;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[1].m_maxDistSqrd[0] = v46;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[1].m_maxDistSqrd[1] = v47;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[1].m_maxRotSqrd[0] = v48;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[1].m_maxRotSqrd[1] = v49;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[2].m_slowObjectVelocityMultiplier = 1.0
                                                                                             - (float)((float)((float)(v43 * 0.079999998) * v50) * (float)(this->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps * 0.016000001));
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[2].m_linearVelocityThresholdInv = v50;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[2].m_angularVelocityThresholdInv = 1.0
                                                                                            / (float)((float)(v43 * 0.0099999998) * (float)(v43 * 0.1));
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[2].m_relativeSleepVelocityThreshold = (float)(this->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps * 0.016000001)
                                                                                               * 12.5;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[2].m_maxDistSqrd[0] = v46;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[2].m_maxDistSqrd[1] = v47;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[2].m_maxRotSqrd[0] = v48;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[2].m_maxRotSqrd[1] = v49;
  v51 = *(hkWorldMemoryAvailableWatchDog **)&v161.m_collisionTolerance;
  v52 = 1.0 / (float)(v43 * 0.017000001);
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[3].m_slowObjectVelocityMultiplier = 1.0
                                                                                             - (float)((float)((float)(v43 * 0.2) * v52) * (float)(this->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps * 0.016000001));
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[3].m_linearVelocityThresholdInv = v52;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[3].m_angularVelocityThresholdInv = 1.0
                                                                                            / (float)((float)(v43 * 0.017000001) * (float)(v43 * 0.1));
  v53 = 1.0 / (float)(v43 * 0.02);
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[3].m_relativeSleepVelocityThreshold = (float)(this->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps * 0.016000001)
                                                                                               * 5.0;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[3].m_maxDistSqrd[0] = v46;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[3].m_maxDistSqrd[1] = v47;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[3].m_maxRotSqrd[0] = v48;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[3].m_maxRotSqrd[1] = v49;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[4].m_slowObjectVelocityMultiplier = 1.0
                                                                                             - (float)((float)((float)(v43 * 0.30000001) * v53) * (float)(this->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps * 0.016000001));
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[4].m_linearVelocityThresholdInv = v53;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[4].m_angularVelocityThresholdInv = 1.0
                                                                                            / (float)((float)(v43 * 0.02) * (float)(v43 * 0.1));
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[4].m_relativeSleepVelocityThreshold = (float)(this->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps * 0.016000001)
                                                                                               * 3.3333333;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[4].m_maxDistSqrd[0] = v46;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[4].m_maxDistSqrd[1] = v47;
  v54 = 1.0 / (float)(v43 * 0.025);
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[4].m_maxRotSqrd[0] = v48;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[4].m_maxRotSqrd[1] = v49;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[5].m_slowObjectVelocityMultiplier = 1.0
                                                                                             - (float)((float)((float)(v43 * 0.40000001) * v54) * (float)(this->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps * 0.016000001));
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[5].m_linearVelocityThresholdInv = v54;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[5].m_angularVelocityThresholdInv = 1.0
                                                                                            / (float)((float)(v43 * 0.025) * (float)(v43 * 0.1));
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[5].m_relativeSleepVelocityThreshold = (float)(this->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps * 0.016000001)
                                                                                               * 2.5;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[5].m_maxDistSqrd[0] = v46;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[5].m_maxDistSqrd[1] = v47;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[5].m_maxRotSqrd[0] = v48;
  this->m_dynamicsStepInfo.m_solverInfo.m_deactivationInfo[5].m_maxRotSqrd[1] = v49;
  if ( v51 )
    hkReferencedObject::addReference(v51);
  v55 = this->m_memoryWatchDog.m_pntr;
  if ( v55 )
    hkReferencedObject::removeReference(v55);
  v56 = BYTE2(v161.m_maxSectorsPerMidphaseCollideTask);
  m_maxSectorsPerMidphaseCollideTask = v161.m_maxSectorsPerMidphaseCollideTask;
  this->m_memoryWatchDog.m_pntr = v51;
  this->m_wantSimulationIslands.m_bool = v56;
  this->m_wantDeactivation.m_bool = m_maxSectorsPerMidphaseCollideTask;
  if ( !v56 && m_maxSectorsPerMidphaseCollideTask )
    this->m_wantDeactivation.m_bool = 0;
  this->m_processActionsInSingleThread.m_bool = v161.m_processToisMultithreaded.m_bool;
  this->m_allowIntegrationOfIslandsWithoutConstraintsInASeparateJob.m_bool = *((_BYTE *)&v161.m_processToisMultithreaded
                                                                             + 1);
  v58 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v59 = (hkpTypedBroadPhaseDispatcher *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v58[11] + 8i64))(
                                          v58[11],
                                          536i64);
  if ( v59 )
    hkpTypedBroadPhaseDispatcher::hkpTypedBroadPhaseDispatcher(v59);
  else
    v60 = 0i64;
  this->m_broadPhaseDispatcher = v60;
  v61 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v62 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v61[11] + 8i64))(v61[11], 24i64);
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
  this->m_phantomBroadPhaseListener = (hkpPhantomBroadPhaseListener *)v62;
  v63 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v64 = (hkpEntityEntityBroadPhaseListener *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v63[11] + 8i64))(
                                               v63[11],
                                               32i64);
  if ( v64 )
    hkpEntityEntityBroadPhaseListener::hkpEntityEntityBroadPhaseListener(v64, this);
  else
    v65 = 0i64;
  this->m_entityEntityBroadPhaseListener = v65;
  v66 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v67 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v66[11] + 8i64))(v66[11], 24i64);
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
  this->m_broadPhaseBorderListener = (hkpBroadPhaseBorderListener *)v67;
  m_phantomBroadPhaseListener = this->m_phantomBroadPhaseListener;
  v69 = &m_phantomBroadPhaseListener->hkpBroadPhaseListener;
  if ( !m_phantomBroadPhaseListener )
    v69 = 0i64;
  this->m_broadPhaseDispatcher->m_broadPhaseListeners[1][2] = v69;
  v70 = this->m_phantomBroadPhaseListener;
  if ( v70 )
    v71 = &v70->hkpBroadPhaseListener;
  else
    v71 = 0i64;
  this->m_broadPhaseDispatcher->m_broadPhaseListeners[2][1] = v71;
  v72 = this->m_phantomBroadPhaseListener;
  if ( v72 )
    v73 = &v72->hkpBroadPhaseListener;
  else
    v73 = 0i64;
  this->m_broadPhaseDispatcher->m_broadPhaseListeners[2][2] = v73;
  m_entityEntityBroadPhaseListener = this->m_entityEntityBroadPhaseListener;
  if ( m_entityEntityBroadPhaseListener )
    v75 = &m_entityEntityBroadPhaseListener->hkpBroadPhaseListener;
  else
    v75 = 0i64;
  this->m_broadPhaseDispatcher->m_broadPhaseListeners[1][1] = v75;
  m_broadPhaseBorderListener = this->m_broadPhaseBorderListener;
  if ( m_broadPhaseBorderListener )
    v77 = &m_broadPhaseBorderListener->hkpBroadPhaseListener;
  else
    v77 = 0i64;
  this->m_broadPhaseDispatcher->m_broadPhaseListeners[1][3] = v77;
  v78 = this->m_broadPhaseBorderListener;
  if ( v78 )
    v79 = &v78->hkpBroadPhaseListener;
  else
    v79 = 0i64;
  this->m_broadPhaseDispatcher->m_broadPhaseListeners[3][1] = v79;
  v80 = this->m_broadPhaseBorderListener;
  if ( v80 )
    v81 = &v80->hkpBroadPhaseListener;
  else
    v81 = 0i64;
  this->m_broadPhaseDispatcher->m_broadPhaseListeners[2][3] = v81;
  v82 = this->m_broadPhaseBorderListener;
  if ( v82 )
    v83 = &v82->hkpBroadPhaseListener;
  else
    v83 = 0i64;
  this->m_broadPhaseDispatcher->m_broadPhaseListeners[3][2] = v83;
  v84 = this->m_broadPhaseBorderListener;
  v85 = &v84->hkpBroadPhaseListener;
  if ( !v84 )
    v85 = 0i64;
  this->m_broadPhaseDispatcher->m_broadPhaseListeners[3][3] = v85;
  v86 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v87 = (hkpSimpleConstraintContactMgr::Factory *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v86[11] + 8i64))(
                                                    v86[11],
                                                    24i64);
  if ( v87 )
  {
    hkpSimpleConstraintContactMgr::Factory::Factory(v87, this);
    v89 = v88;
  }
  else
  {
    v89 = 0i64;
  }
  v90 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v91 = (hkpCollisionDispatcher *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v90[11] + 8i64))(v90[11], 10880i64);
  if ( v91 )
    hkpCollisionDispatcher::hkpCollisionDispatcher(
      v91,
      (hkpCollisionAgent *(__fastcall *)(hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpContactMgr *))hkpNullAgent::createNullAgent,
      v89);
  else
    v92 = 0i64;
  this->m_collisionDispatcher = v92;
  hkReferencedObject::removeReference(v89);
  v93 = (hkReferencedObject *)v161.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[0];
  if ( v161.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[0] )
  {
    v97 = (hkReferencedObject *)v161.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[0];
    this->m_collisionFilter = (hkpCollisionFilter *)v161.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[0];
    hkReferencedObject::addReference(v97);
    ((void (__fastcall *)(hkpCollisionFilter *, hkpWorld *))this->m_collisionFilter->vfptr[1].__first_virtual_table_function__)(
      this->m_collisionFilter,
      this);
  }
  else
  {
    v94 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v95 = (hkpCollisionFilter *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v94[11] + 8i64))(v94[11], 72i64);
    v96 = v95;
    if ( v95 )
    {
      hkpCollisionFilter::hkpCollisionFilter(v95);
      v96->m_type.m_storage = 1;
      v96->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpNullCollisionFilter::`vftable{for `hkReferencedObject};
      v96->hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
      v96->hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
      v96->hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
      v96->hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpRayCollidableFilter};
      this->m_collisionFilter = v96;
    }
    else
    {
      this->m_collisionFilter = 0i64;
    }
  }
  v98 = (hkReferencedObject *)v161.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[1];
  if ( v161.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[1] )
  {
    v101 = (hkReferencedObject *)v161.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[1];
    this->m_convexListFilter = (hkpConvexListFilter *)v161.m_broadPhaseWorldAabb.m_min.m_quad.m128_u64[1];
    hkReferencedObject::addReference(v101);
  }
  else
  {
    v99 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v100 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v99[11] + 8i64))(v99[11], 16i64);
    if ( v100 )
    {
      *(_DWORD *)(v100 + 8) = 0x1FFFF;
      *(_QWORD *)v100 = &hkpDefaultConvexListFilter::`vftable;
      this->m_convexListFilter = (hkpConvexListFilter *)v100;
    }
    else
    {
      this->m_convexListFilter = 0i64;
    }
  }
  v102 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v103 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v102[11] + 8i64))(v102[11], 160i64);
  v104 = v103;
  if ( v103 )
  {
    LODWORD(v103) = 0;
    *(_DWORD *)(v104 + 12) = 0;
    *(_QWORD *)(v104 + 120) = 0i64;
  }
  else
  {
    v104 = 0i64;
  }
  v105 = *(_DWORD *)&v161.m_broadPhaseType.m_storage;
  v106 = BYTE4(v161.m_collisionFilter.m_pntr);
  this->m_collisionInput = (hkpProcessCollisionInput *)v104;
  *(_DWORD *)(v104 + 8) = v103;
  *(_QWORD *)v104 = this->m_collisionDispatcher;
  *(_DWORD *)(v104 + 16) = v105;
  *(_QWORD *)(v104 + 24) = this->m_collisionFilter;
  *(_QWORD *)(v104 + 32) = this->m_convexListFilter;
  v107 = BYTE5(v161.m_collisionFilter.m_pntr);
  this->m_contactPointGeneration.m_storage = v106;
  *(_BYTE *)(v104 + 137) = v107;
  v108 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v109 = (_DWORD *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v108[11] + 8i64))(v108[11], 16i64);
  if ( v109 )
  {
    *v109 = 1008981770;
    v109[1] = 20;
  }
  v110 = *(_DWORD *)&v161.m_contactPointGeneration.m_storage;
  *(_QWORD *)(v104 + 144) = v109;
  *v109 = v110;
  v111 = _mm_sub_ps(v11, v10);
  *(float *)(*(_QWORD *)(v104 + 144) + 4i64) = v161.m_solverTau;
  v112 = _mm_rcp_ps(v111);
  *(_BYTE *)(v104 + 136) = BYTE1(v161.m_broadPhaseNumMarkers);
  v113 = *(_QWORD *)v104;
  *(_DWORD *)(v104 + 40) = 0;
  v114 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v111, v112)), v112);
  *(_QWORD *)(v104 + 112) = v113 + 10368;
  *(_QWORD *)(v104 + 96) = 0i64;
  *(_QWORD *)(v104 + 104) = 0i64;
  *(__m128 *)(v104 + 80) = _mm_mul_ps(
                             _mm_shuffle_ps((__m128)LODWORD(FLOAT_2_1473526e9), (__m128)LODWORD(FLOAT_2_1473526e9), 0),
                             _mm_shuffle_ps(v114, _mm_unpackhi_ps(v114, query.m_quad), 196));
  v165 = FLOAT_4_6568971eN10;
  v115 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v10);
  *(__m128 *)(v104 + 48) = v115;
  *(__m128 *)(v104 + 64) = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_shuffle_ps(
                                 (__m128)LODWORD(FLOAT_4_6568971eN10),
                                 (__m128)LODWORD(FLOAT_4_6568971eN10),
                                 0),
                               v111),
                             v115);
  *(__m128i *)(v104 + 80) = _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)(v104 + 80)), 4), 4);
  *(__m128i *)(v104 + 48) = _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)(v104 + 48)), 4), 4);
  *(__m128i *)(v104 + 64) = _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)(v104 + 64)), 4), 4);
  ((void (__fastcall *)(hkpBroadPhase *))this->m_broadPhase->vfptr[15].__vecDelDtor)(this->m_broadPhase);
  hkWorld_setupContactMgrFactories(this, this->m_collisionDispatcher);
  v116 = hkpWorld::m_forceMultithreadedSimulation.m_bool == 0;
  v117 = BYTE1(v161.m_maxSectorsPerMidphaseCollideTask);
  this->m_minDesiredIslandSize = 0;
  if ( !v116 )
    v117 = 3;
  this->m_simulationType.m_storage = v117;
  switch ( v117 )
  {
    case 1:
      Discrete = hkpSimulation::createDiscrete(this);
      goto LABEL_95;
    case 2:
      Discrete = hkpSimulation::createContinuous(this);
LABEL_95:
      this->m_simulation = Discrete;
      break;
    case 3:
      v118 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v119 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v118[11] + 8i64))(v118[11], 40i64);
      if ( v119 )
        hkCriticalSection::hkCriticalSection(v119, 0xFA0u);
      this->m_modifyConstraintCriticalSection = v119;
      v120 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v121 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v120[11] + 8i64))(v120[11], 40i64);
      if ( v121 )
        hkCriticalSection::hkCriticalSection(v121, 0xFA0u);
      this->m_propertyMasterLock = v121;
      this->m_simulation = hkpSimulation::createMultithreaded(this);
      this->m_minDesiredIslandSize = v161.m_maxSectorsPerNarrowphaseCollideTask;
      break;
  }
  v123 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v124 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v123[11] + 8i64))(v123[11], 40i64);
  if ( v124 )
    hkCriticalSection::hkCriticalSection(v124, 0xFA0u);
  m_maxEntriesPerToiMidphaseCollideTask = v161.m_maxEntriesPerToiMidphaseCollideTask;
  this->m_islandDirtyListCriticalSection = v124;
  LODWORD(this->m_simulation->m_frameMarkerPsiSnap) = m_maxEntriesPerToiMidphaseCollideTask;
  v126 = _mm_mul_ps(this->m_gravity.m_quad, this->m_gravity.m_quad);
  v127 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v126, v126, 85), _mm_shuffle_ps(v126, v126, 0)),
           _mm_shuffle_ps(v126, v126, 170));
  v128 = _mm_rsqrt_ps(v127);
  v129 = _mm_andnot_ps(
           _mm_cmple_ps(v127, (__m128)0i64),
           _mm_mul_ps(
             _mm_mul_ps(
               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v128, v127), v128)),
               _mm_mul_ps(*(__m128 *)_xmm, v128)),
             v127)).m128_f32[0];
  if ( v129 == 0.0 )
    v129 = FLOAT_9_8100004;
  v130 = *(float *)&v161.m_deactivationNumInactiveFramesSelectFlag0;
  m_deactivationReferenceDistance = v161.m_deactivationReferenceDistance;
  m_toiCollisionResponseRotateNormal = v161.m_toiCollisionResponseRotateNormal;
  m_collisionInput = this->m_collisionInput;
  m_collisionDispatcher = this->m_collisionDispatcher;
  v135 = *(float *)&v161.m_useCompoundSpuElf.m_bool;
  v136 = v161.m_broadPhaseWorldAabb.m_max.m_quad.m128_f32[2];
  this->m_numToisTillAllowedPenetrationSimplifiedToi = *(float *)&v161.m_deactivationNumInactiveFramesSelectFlag0;
  this->m_numToisTillAllowedPenetrationToi = m_deactivationReferenceDistance;
  this->m_numToisTillAllowedPenetrationToiHigher = m_toiCollisionResponseRotateNormal;
  this->m_numToisTillAllowedPenetrationToiForced = v135;
  v160.m_gravityLength = v129;
  v137 = m_collisionInput->m_tolerance.m_storage;
  v160.m_minDeltaTime = v136;
  v160.m_wantContinuousCollisionDetection.m_bool = v117 >= 2;
  *(_DWORD *)&v160.m_defaultConstraintPriority = 196609;
  v160.m_enableNegativeManifoldTims.m_bool = v106 == 2;
  *(_DWORD *)&v160.m_toiHigherConstraintPriority = 327684;
  v160.m_collisionTolerance = v137;
  v160.m_numToisTillAllowedPenetrationSimplifiedToi = v130;
  v160.m_enableToiWeldRejection.m_bool = m_broadPhaseNumMarkers;
  v160.m_enableNegativeToleranceToCreateNon4dContacts.m_bool = v106 >= 1;
  LODWORD(v160.m_maxLinearVelocity) = v161.m_broadPhaseWorldAabb.m_max.m_quad.m128_i32[0];
  v160.m_numToisTillAllowedPenetrationToi = m_deactivationReferenceDistance;
  v160.m_numToisTillAllowedPenetrationToiHigher = m_toiCollisionResponseRotateNormal;
  v160.m_numToisTillAllowedPenetrationToiForced = v135;
  hkpCollisionDispatcher::initCollisionQualityInfo(m_collisionDispatcher, &v160);
  this->m_collisionInput->m_collisionQualityInfo.m_storage = &this->m_collisionDispatcher->m_collisionQualityInfo[1];
  v138 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v139 = (hkpSimulationIsland *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v138[11] + 8i64))(v138[11], 184i64);
  if ( v139 )
    hkpSimulationIsland::hkpSimulationIsland(v139, this);
  else
    v140 = 0i64;
  this->m_fixedIsland = v140;
  v140->m_storageIndex = -1;
  *((_BYTE *)this->m_fixedIsland + 50) &= 0xF3u;
  *((_BYTE *)this->m_fixedIsland + 50) &= 0xFCu;
  if ( !this->m_wantSimulationIslands.m_bool )
  {
    v141 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v142 = (hkpSimulationIsland *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v141[11] + 8i64))(v141[11], 184i64);
    if ( v142 )
    {
      hkpSimulationIsland::hkpSimulationIsland(v142, this);
      v144 = v143;
    }
    else
    {
      v144 = 0i64;
    }
    if ( this->m_activeSimulationIslands.m_size == (this->m_activeSimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_activeSimulationIslands.m_data,
        8);
    this->m_activeSimulationIslands.m_data[this->m_activeSimulationIslands.m_size++] = v144;
    v144->m_storageIndex = 0;
  }
  hkpRigidBodyCinfo::hkpRigidBodyCinfo((hkpRigidBodyCinfo *)&v161.m_maxNumToiCollisionPairsSinglethreaded);
  v163 = 5;
  v162 = 0;
  v145 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v146 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v145[11] + 8i64))(v145[11], 720i64);
  if ( v146 )
    hkpRigidBody::hkpRigidBody(v146, (hkpRigidBodyCinfo *)&v161.m_maxNumToiCollisionPairsSinglethreaded);
  else
    v147 = 0i64;
  this->m_fixedRigidBody = v147;
  v147->m_npData = 0;
  hkpWorld::addEntity(this, this->m_fixedRigidBody, HK_ENTITY_ACTIVATION_DO_ACTIVATE);
  hkReferencedObject::removeReference(this->m_fixedRigidBody);
  v148 = v161.m_broadPhaseBorderBehaviour.m_storage;
  this->m_dynamicsStepInfo.m_stepInfo.m_startTime.m_storage = 0.0;
  this->m_dynamicsStepInfo.m_stepInfo.m_endTime.m_storage = 0.016666668;
  this->m_dynamicsStepInfo.m_stepInfo.m_deltaTime.m_storage = 0.016666668;
  this->m_dynamicsStepInfo.m_stepInfo.m_invDeltaTime.m_storage = 59.999996;
  this->m_collisionInput->m_dynamicsInfo = &this->m_dynamicsStepInfo;
  if ( v148 == 3 )
  {
    this->m_broadPhaseBorder = 0i64;
  }
  else
  {
    v149 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v150 = (hkpBroadPhaseBorder *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v149[11] + 8i64))(v149[11], 120i64);
    if ( v150 )
    {
      hkpBroadPhaseBorder::hkpBroadPhaseBorder(
        v150,
        this,
        (hkpWorldCinfo::BroadPhaseBorderBehaviour)v148,
        v161.m_mtPostponeAndSortBroadPhaseBorderCallbacks);
      this->m_broadPhaseBorder = v151;
    }
    else
    {
      this->m_broadPhaseBorder = 0i64;
    }
  }
  v152 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v153 = (hkpDefaultWorldMaintenanceMgr *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v152[11] + 8i64))(
                                            v152[11],
                                            24i64);
  if ( v153 )
  {
    hkpDefaultWorldMaintenanceMgr::hkpDefaultWorldMaintenanceMgr(v153);
    v155 = v154;
  }
  else
  {
    v155 = 0i64;
  }
  this->m_maintenanceMgr = v155;
  ((void (__fastcall *)(hkpWorldMaintenanceMgr *, hkpWorld *))v155->vfptr[1].__first_virtual_table_function__)(
    v155,
    this);
  if ( LOBYTE(v161.m_maxEntriesPerToiNarrowphaseCollideTask) )
    hkpWorldExtension::requireExtension<hkpCollisionCallbackUtil>((hkpWorldExtension *)this, v156);
  if ( v117 != 3 )
    hkMultiThreadCheck::disableChecks(&this->m_multiThreadCheck);
  v157 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v158 = (hkpMtThreadStructure *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v157[11] + 8i64))(v157[11], 352i64);
  if ( v158 )
  {
    v158->m_constraintQueryIn.m_beginConstraints = hkpBeginConstraints;
    v158->m_collisionInput.m_forceAcceptContactPoints.m_storage = 0;
    v158->m_collisionInput.m_spareAgentSector = 0i64;
  }
  else
  {
    v158 = 0i64;
  }
  v159 = *(hkReferencedObject **)&v161.m_collisionTolerance;
  this->m_multithreadedSimulationJobData = v158;
  if ( v159 )
    hkReferencedObject::removeReference(v159);
  if ( v98 )
    hkReferencedObject::removeReference(v98);
  if ( v93 )
    hkReferencedObject::removeReference(v93);
}CallbackUtil>((hkpWorldExtension *)this, v156);
  if ( v117 != 3 )
    hkMultiThreadCheck::disableChecks(&this->m_multiThreadCheck);
  v157 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v158 = (hkpMtThreadStructure *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v157[11] + 8i64))(v157[11], 352i64);
  if ( v158 )
  {
    v158->m_constraintQueryIn.m_beginConstraints = hkpBeginConstraints;
    v158->m_collisionInput.m_forceAcceptContactPoints.m_storage = 0;
    v158->m_collisionInput.m_spareAgentSector = 0i64;
  }
  else
  {
    v158 = 0i64;
  }
  v159 = *(hkReferencedObject **)&v161.m_collisionTolerance;
  this->m_multithreadedSimulationJobData = v158;
  if ( v159 )
    hkReferencedObject::removeReference(v159);
  if ( v98 )
    hkReferencedObject::removeR

// File Line: 3397
// RVA: 0xD5C1D0
void __fastcall hkpWorld::shiftBroadPhase(
        hkpWorld *this,
        hkVector4f *shiftDistance,
        hkVector4f *effectiveShiftDistanceOut,
        hkpWorld::CachedAabbUpdate updateAabbs)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r8
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkpBroadPhase *m_broadPhase; // rcx
  hkpCollisionFilter *m_collisionFilter; // r9
  hkpCollidableCollidableFilter *v15; // r9
  hkpBroadPhaseBorder *m_broadPhaseBorder; // r14
  __int64 i; // rdi
  __m128 *v18; // rbx
  int v19; // eax
  int m_size; // eax
  hkpSimulationIsland *m_fixedIsland; // rbx
  int v22; // r8d
  bool v23; // zf
  unsigned int v24; // eax
  __int64 v25; // rdi
  __int64 v26; // rax
  char *v27; // rsi
  int v28; // r14d
  __int64 *v29; // rdx
  BOOL v30; // eax
  _BOOL8 v31; // rbx
  __int64 v32; // r9
  hkpSimulationIsland **m_data; // r10
  __int64 v34; // rdx
  hkpSimulationIsland *v35; // rax
  _BOOL8 v36; // rcx
  __int64 v37; // r9
  hkpSimulationIsland **v38; // r10
  __int64 v39; // r11
  __int64 v40; // rdx
  hkpSimulationIsland *v41; // rax
  __int64 v42; // rcx
  char *v43; // r12
  __int64 v44; // r13
  __int64 v45; // r14
  int v46; // ebx
  __int64 v47; // rdi
  __int64 v48; // rsi
  _QWORD *v49; // rax
  _QWORD *v50; // rcx
  _QWORD *v51; // r8
  unsigned __int64 v52; // rax
  _QWORD *v53; // rcx
  hkpSimulationIsland *v54; // [rsp+20h] [rbp-60h] BYREF
  hkpEntity **array; // [rsp+28h] [rbp-58h] BYREF
  int v56; // [rsp+30h] [rbp-50h]
  int v57; // [rsp+34h] [rbp-4Ch]
  hkpTypedBroadPhaseHandlePair *newPairs; // [rsp+38h] [rbp-48h] BYREF
  int numNewPairs; // [rsp+40h] [rbp-40h]
  int v60; // [rsp+44h] [rbp-3Ch]
  int v61; // [rsp+90h] [rbp+10h]
  void *v62; // [rsp+A0h] [rbp+20h]
  int v63; // [rsp+A8h] [rbp+28h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtBroadphase Shift";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  m_broadPhase = this->m_broadPhase;
  v60 = 0x80000000;
  newPairs = 0i64;
  numNewPairs = 0;
  ((void (__fastcall *)(hkpBroadPhase *, hkVector4f *, hkVector4f *, hkpTypedBroadPhaseHandlePair **))m_broadPhase->vfptr[11].__first_virtual_table_function__)(
    m_broadPhase,
    shiftDistance,
    effectiveShiftDistanceOut,
    &newPairs);
  ((void (__fastcall *)(hkpBroadPhase *, hkpCollisionInput::Aabb32Info *, hkVector4f *))this->m_broadPhase->vfptr[12].__vecDelDtor)(
    this->m_broadPhase,
    &this->m_collisionInput->m_aabb32Info,
    &this->m_collisionInput->m_aabb32Info.m_bitOffsetHigh);
  this->m_broadPhaseExtents[0].m_quad = _mm_add_ps(
                                          this->m_broadPhaseExtents[0].m_quad,
                                          effectiveShiftDistanceOut->m_quad);
  this->m_broadPhaseExtents[1].m_quad = _mm_add_ps(
                                          effectiveShiftDistanceOut->m_quad,
                                          this->m_broadPhaseExtents[1].m_quad);
  m_collisionFilter = this->m_collisionFilter;
  ++this->m_criticalOperationsLockCount;
  if ( m_collisionFilter )
    v15 = &m_collisionFilter->hkpCollidableCollidableFilter;
  else
    v15 = 0i64;
  hkpTypedBroadPhaseDispatcher::addPairs(this->m_broadPhaseDispatcher, newPairs, numNewPairs, v15);
  m_broadPhaseBorder = this->m_broadPhaseBorder;
  if ( m_broadPhaseBorder )
  {
    for ( i = 0i64; i < 6; ++i )
    {
      v18 = (__m128 *)m_broadPhaseBorder->m_phantoms[i];
      v19 = (*(__int64 (__fastcall **)(__m128 *))(v18->m128_u64[0] + 48))(v18);
      if ( v19 )
      {
        if ( (unsigned int)(v19 - 1) <= 1 )
          v18[18] = _mm_add_ps(effectiveShiftDistanceOut->m_quad, v18[18]);
      }
      else
      {
        v18[15] = _mm_add_ps(v18[15], effectiveShiftDistanceOut->m_quad);
        v18[16] = _mm_add_ps(effectiveShiftDistanceOut->m_quad, v18[16]);
      }
    }
  }
  if ( updateAabbs == SHIFT_BROADPHASE_UPDATE_ENTITY_AABBS )
  {
    m_size = this->m_inactiveSimulationIslands.m_size;
    m_fixedIsland = this->m_fixedIsland;
    array = 0i64;
    ++m_size;
    v22 = 0;
    v56 = 0;
    v23 = this->m_activeSimulationIslands.m_size + m_size == 0;
    v24 = this->m_activeSimulationIslands.m_size + m_size;
    v57 = 0x80000000;
    v54 = m_fixedIsland;
    v25 = v24;
    if ( v23 )
    {
      v27 = 0i64;
    }
    else
    {
      v63 = 8 * v24;
      v26 = ((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
              &hkContainerHeapAllocator::s_alloc,
              &v63,
              0i64);
      v22 = v56;
      v27 = (char *)v26;
      v24 = v63 / 8;
    }
    v28 = 0x80000000;
    v29 = (__int64 *)&v54;
    if ( v24 )
      v28 = v24;
    v30 = m_fixedIsland != 0i64;
    v62 = v27;
    if ( !m_fixedIsland )
      v29 = 0i64;
    v61 = v28;
    v31 = m_fixedIsland != 0i64;
    if ( v30 > 0 )
    {
      memmove(v27, v29, 8i64 * v30);
      v22 = v56;
    }
    v32 = this->m_activeSimulationIslands.m_size;
    m_data = this->m_activeSimulationIslands.m_data;
    v34 = 0i64;
    if ( v32 > 0 )
    {
      do
      {
        v35 = m_data[v34];
        v36 = v31 + v34++;
        *(_QWORD *)&v27[8 * v36] = v35;
      }
      while ( v34 < v32 );
      v22 = v56;
    }
    v37 = this->m_inactiveSimulationIslands.m_size;
    v38 = this->m_inactiveSimulationIslands.m_data;
    v39 = this->m_activeSimulationIslands.m_size;
    v40 = 0i64;
    if ( v37 > 0 )
    {
      do
      {
        v41 = v38[v40];
        v42 = v40 + v39 + v31;
        ++v40;
        *(_QWORD *)&v27[8 * v42] = v41;
      }
      while ( v40 < v37 );
      v22 = v56;
    }
    if ( (int)v25 > 0 )
    {
      v43 = v27;
      v44 = v25;
      do
      {
        v45 = *(_QWORD *)v43;
        v46 = 0;
        if ( *(int *)(*(_QWORD *)v43 + 104i64) > 0 )
        {
          v47 = 0i64;
          do
          {
            v48 = *(_QWORD *)(v45 + 96);
            if ( *(_QWORD *)(*(_QWORD *)(v48 + v47) + 32i64) )
            {
              if ( v22 == (v57 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
                v22 = v56;
              }
              array[v22] = *(hkpEntity **)(v48 + v47);
              v22 = ++v56;
            }
            ++v46;
            v47 += 8i64;
          }
          while ( v46 < *(_DWORD *)(v45 + 104) );
        }
        v43 += 8;
        --v44;
      }
      while ( v44 );
      v28 = v61;
    }
    hkpEntityAabbUtil::entityBatchRecalcAabb(this->m_collisionInput, array, v22);
    if ( v28 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v62, 8 * v28);
    v56 = 0;
    if ( v57 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v57);
  }
  v23 = this->m_criticalOperationsLockCount-- == 1;
  if ( v23 && !this->m_blockExecutingPendingOperations.m_bool )
  {
    if ( this->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(this);
    if ( this->m_pendingOperationQueueCount == 1 && this->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(this);
  }
  v49 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v50 = (_QWORD *)v49[1];
  v51 = v49;
  if ( (unsigned __int64)v50 < v49[3] )
  {
    *v50 = "Et";
    v52 = __rdtsc();
    v53 = v50 + 2;
    *((_DWORD *)v53 - 2) = v52;
    v51[1] = v53;
  }
  numNewPairs = 0;
  if ( v60 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, newPairs, 16 * v60);
}

// File Line: 3493
// RVA: 0xD5B2D0
void __fastcall hkpWorld::setCollisionFilter(
        hkpWorld *this,
        hkpCollisionFilter *filter,
        hkBool runUpdateCollisionFilterOnWorld,
        hkpUpdateCollisionFilterOnWorldMode updateMode,
        hkpUpdateCollectionFilterMode updateShapeCollectionFilter)
{
  hkpCollisionFilter *v6; // rbx
  _QWORD **Value; // rax
  hkpNullCollisionFilter *v9; // rax
  hkpCollisionFilter *v10; // rax
  hkpCollisionFilter *m_collisionFilter; // rcx
  hkpProcessCollisionInput *m_collisionInput; // rax

  v6 = filter;
  if ( filter )
  {
    hkReferencedObject::addReference(filter);
  }
  else
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v9 = (hkpNullCollisionFilter *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 72i64);
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
  m_collisionFilter = this->m_collisionFilter;
  if ( m_collisionFilter )
    hkReferencedObject::removeReference(m_collisionFilter);
  m_collisionInput = this->m_collisionInput;
  this->m_collisionFilter = v6;
  m_collisionInput->m_filter.m_storage = v6;
  ((void (__fastcall *)(hkpCollisionFilter *, hkpWorld *))this->m_collisionFilter->vfptr[1].__first_virtual_table_function__)(
    this->m_collisionFilter,
    this);
  if ( runUpdateCollisionFilterOnWorld.m_bool )
    hkpWorld::updateCollisionFilterOnWorld(this, updateMode, updateShapeCollectionFilter);
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
  hkpBroadPhaseBorder *m_broadPhaseBorder; // rcx

  m_broadPhaseBorder = this->m_broadPhaseBorder;
  if ( m_broadPhaseBorder )
  {
    ((void (__fastcall *)(hkpBroadPhaseBorder *))m_broadPhaseBorder->hkReferencedObject::hkBaseObject::vfptr[2].__vecDelDtor)(m_broadPhaseBorder);
    hkReferencedObject::removeReference(this->m_broadPhaseBorder);
  }
  this->m_broadPhaseBorder = b;
  if ( b )
    hkReferencedObject::addReference(b);
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
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkpCollisionFilter *m_collisionFilter; // r9
  hkpBroadPhase *m_broadPhase; // rdx
  _QWORD *v13; // rax
  _QWORD *v14; // rcx
  _QWORD *v15; // r8
  unsigned __int64 v16; // rax
  _QWORD *v17; // rcx
  hkpWorldRayCaster v18; // [rsp+30h] [rbp-78h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtworldCastRayCollector";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  m_collisionFilter = this->m_collisionFilter;
  m_broadPhase = this->m_broadPhase;
  v18.vfptr = (hkpBroadPhaseCastCollectorVtbl *)&hkpWorldRayCaster::`vftable;
  v18.m_shapeInput.m_filterInfo = 0;
  memset(&v18.m_shapeInput.m_rayShapeCollectionFilter, 0, 24);
  hkpWorldRayCaster::castRay(&v18, m_broadPhase, input, m_collisionFilter, 0i64, collector);
  v18.vfptr = (hkpBroadPhaseCastCollectorVtbl *)&hkpBroadPhaseCastCollector::`vftable;
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = (_QWORD *)v13[1];
  v15 = v13;
  if ( (unsigned __int64)v14 < v13[3] )
  {
    *v14 = "Et";
    v16 = __rdtsc();
    v17 = v14 + 2;
    *((_DWORD *)v17 - 2) = v16;
    v15[1] = v17;
  }
}

// File Line: 3576
// RVA: 0xD5B390
void __fastcall hkpWorld::castRay(hkpWorld *this, hkpWorldRayCastInput *input, hkpWorldRayCastOutput *output)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkpCollisionFilter *m_collisionFilter; // r9
  hkpBroadPhase *m_broadPhase; // rdx
  _QWORD *v13; // rax
  _QWORD *v14; // rcx
  _QWORD *v15; // r8
  unsigned __int64 v16; // rax
  _QWORD *v17; // rcx
  hkpSimpleWorldRayCaster v18; // [rsp+30h] [rbp-68h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtworldCastRay";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  m_collisionFilter = this->m_collisionFilter;
  m_broadPhase = this->m_broadPhase;
  v18.vfptr = (hkpBroadPhaseCastCollectorVtbl *)&hkpSimpleWorldRayCaster::`vftable;
  v18.m_shapeInput.m_filterInfo = 0;
  memset(&v18.m_shapeInput.m_rayShapeCollectionFilter, 0, 24);
  hkpSimpleWorldRayCaster::castRay(&v18, m_broadPhase, input, m_collisionFilter, 0i64, output);
  v18.vfptr = (hkpBroadPhaseCastCollectorVtbl *)&hkpBroadPhaseCastCollector::`vftable;
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = (_QWORD *)v13[1];
  v15 = v13;
  if ( (unsigned __int64)v14 < v13[3] )
  {
    *v14 = "Et";
    v16 = __rdtsc();
    v17 = v14 + 2;
    *((_DWORD *)v17 - 2) = v16;
    v15[1] = v17;
  }
}

// File Line: 3584
// RVA: 0xD5B5A0
void __fastcall hkpWorld::castRayMt(
        hkpWorld *this,
        hkpWorldRayCastCommand *commandArray,
        int numCommands,
        hkJobQueue *jobQueue,
        hkJobThreadPool *jobThreadPool,
        hkSemaphore *semaphore,
        int numCommandsPerJob)
{
  _QWORD **Value; // rax
  __int64 v12; // rax
  hkpProcessCollisionInput *m_collisionInput; // rcx
  hkpCollisionQueryJobHeader *v14; // r15
  hkpBroadPhase *m_broadPhase; // rax
  int v16; // eax
  int i; // ecx
  int v18; // eax
  __int128 v19; // xmm0
  _QWORD **v20; // rax
  hkpWorldRayCastJob v21; // [rsp+20h] [rbp-91h] BYREF
  hkJob job; // [rsp+80h] [rbp-31h] BYREF
  __int128 v23; // [rsp+90h] [rbp-21h]
  __int128 v24; // [rsp+A0h] [rbp-11h]
  __int128 v25; // [rsp+B0h] [rbp-1h]
  __int128 v26; // [rsp+C0h] [rbp+Fh]
  __int128 v27; // [rsp+D0h] [rbp+1Fh]

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 16i64);
  m_collisionInput = this->m_collisionInput;
  v14 = (hkpCollisionQueryJobHeader *)v12;
  v21.m_size = 96;
  *(_WORD *)&v21.m_jobSubType = 769;
  v21.m_threadAffinity = -1;
  m_broadPhase = this->m_broadPhase;
  v21.m_jobDoneFlag = 0i64;
  v21.m_jobSpuType.m_storage = 1;
  v21.m_collisionInput = m_collisionInput;
  v21.m_sharedJobHeaderOnPpu = v14;
  v21.m_broadphase = m_broadPhase;
  v21.m_numCommandsPerTask = 64;
  v21.m_semaphore = semaphore;
  v21.m_commandArray = commandArray;
  v21.m_numCommands = numCommands;
  if ( numCommands )
    v16 = (numCommands - 1) / 64 + 1;
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
    job = v21.hkJob;
    v25 = *(_OWORD *)&v21.m_numCommandsPerTask;
    v24 = *(_OWORD *)&v21.m_jobDoneFlag;
    v19 = *(_OWORD *)&v21.m_numCommands;
    v23 = *(_OWORD *)&v21.m_semaphore;
    v21.m_numCommands = i - numCommandsPerJob;
    v26 = v19;
    LODWORD(v26) = v18;
    v21.m_commandArray = (hkpWorldRayCastCommand *)(80i64 * numCommandsPerJob
                                                  + _mm_srli_si128(*(__m128i *)&v21.m_numCommandsPerTask, 8).m128i_u64[0]);
    v27 = *(_OWORD *)&v21.m_numBundleCommands;
    hkJobQueue::addJob(jobQueue, &job, JOB_LOW_PRIORITY);
  }
  ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, __int64))jobThreadPool->vfptr[5].__first_virtual_table_function__)(
    jobThreadPool,
    jobQueue,
    20i64);
  hkJobQueue::processAllJobs(jobQueue, 1);
  ((void (__fastcall *)(hkJobThreadPool *))jobThreadPool->vfptr[2].__vecDelDtor)(jobThreadPool);
  hkSemaphore::acquire(semaphore);
  v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkpCollisionQueryJobHeader *, __int64))(*v20[11] + 16i64))(v20[11], v14, 16i64);
}

// File Line: 3608
// RVA: 0xD5BA80
void __fastcall hkpWorld::getClosestPoints(
        hkpWorld *this,
        hkpCollidable *collA,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  _QWORD *Value; // r8
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // rax
  hkpBroadPhase *m_broadPhase; // rcx
  _QWORD *v12; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  _QWORD *v15; // rcx
  int v16; // esi
  __int64 m_storage; // r12
  char *v18; // rdi
  hkpCollidable *v19; // rbx
  _QWORD *v20; // rax
  _QWORD *v21; // rcx
  _QWORD *v22; // r8
  unsigned __int64 v23; // rax
  _QWORD *v24; // rcx
  char v25[32]; // [rsp+20h] [rbp-858h] BYREF
  char *v26; // [rsp+40h] [rbp-838h] BYREF
  int v27; // [rsp+48h] [rbp-830h]
  int v28; // [rsp+4Ch] [rbp-82Ch]
  char v29; // [rsp+50h] [rbp-828h] BYREF
  char v30; // [rsp+880h] [rbp+8h] BYREF

  ((void (__fastcall *)(hkpShape *, const void *, hkpCollisionInput *, char *))collA->m_shape->vfptr[2].__vecDelDtor)(
    collA->m_shape,
    collA->m_motion,
    input,
    v25);
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = Value[1];
  if ( v9 < Value[3] )
  {
    *(_QWORD *)v9 = "LthkpWorld::getClosestPoints";
    *(_QWORD *)(v9 + 16) = "StBroadPhase";
    v10 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v10;
    Value[1] = v9 + 24;
  }
  m_broadPhase = this->m_broadPhase;
  v27 = 0;
  v26 = &v29;
  v28 = -2147483520;
  ((void (__fastcall *)(hkpBroadPhase *, char *, char **))m_broadPhase->vfptr[9].__vecDelDtor)(m_broadPhase, v25, &v26);
  v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = (_QWORD *)v12[1];
  if ( (unsigned __int64)v13 < v12[3] )
  {
    *v13 = "StNarrowPhase";
    v14 = __rdtsc();
    v15 = v13 + 2;
    *((_DWORD *)v15 - 2) = v14;
    v12[1] = v15;
  }
  v16 = v27 - 1;
  m_storage = (unsigned __int8)collA->m_shape->m_type.m_storage;
  if ( v27 - 1 >= 0 )
  {
    v18 = v26 + 8;
    do
    {
      v19 = (hkpCollidable *)(*(_QWORD *)v18 + *(char *)(*(_QWORD *)v18 + 5i64));
      if ( collA != v19
        && this->m_collisionFilter->vfptr->isCollisionEnabled(
             &this->m_collisionFilter->hkpCollidableCollidableFilter,
             &v30,
             collA,
             *(_QWORD *)v18 + *(char *)(*(_QWORD *)v18 + 5i64))->m_bool
        && v19->m_shape )
      {
        input->m_dispatcher.m_storage->m_agent2Func[(unsigned __int8)input->m_dispatcher.m_storage->m_agent2Types[m_storage][(unsigned __int8)v19->m_shape->m_type.m_storage]].m_getClosestPointFunc(
          collA,
          v19,
          input,
          collector);
      }
      v18 += 16;
      --v16;
    }
    while ( v16 >= 0 );
  }
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  v22 = v20;
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "lt";
    v23 = __rdtsc();
    v24 = v21 + 2;
    *((_DWORD *)v24 - 2) = v23;
    v22[1] = v24;
  }
  v27 = 0;
  if ( v28 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v26, 16 * v28);
}

// File Line: 3657
// RVA: 0xD5BCF0
void __fastcall hkpWorld::getClosestPointsMt(
        hkpWorld *this,
        hkpWorldGetClosestPointsCommand *commandArray,
        int numCommands,
        hkJobQueue *jobQueue,
        hkJobThreadPool *jobThreadPool,
        hkSemaphore *semaphore,
        int numCommandsPerJob)
{
  __int64 v9; // r14
  _QWORD **Value; // rax
  __int64 v12; // rax
  hkpProcessCollisionInput *m_collisionInput; // rdx
  hkpBroadPhase *m_broadPhase; // r8
  float m_storage; // xmm0_4
  hkpCollisionQueryJobHeader *v16; // r12
  __int64 v17; // rcx
  unsigned int *p_m_numResultsOut; // rax
  int i; // ecx
  int v20; // eax
  __int128 v21; // xmm0
  _QWORD **v22; // rax
  hkpWorldGetClosestPointsJob v23; // [rsp+20h] [rbp-71h] BYREF
  hkJob job; // [rsp+70h] [rbp-21h] BYREF
  __int128 v25; // [rsp+80h] [rbp-11h]
  __int128 v26; // [rsp+90h] [rbp-1h]
  __int128 v27; // [rsp+A0h] [rbp+Fh]
  __int128 v28; // [rsp+B0h] [rbp+1Fh]

  v9 = numCommands;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 16i64);
  m_collisionInput = this->m_collisionInput;
  m_broadPhase = this->m_broadPhase;
  m_storage = m_collisionInput->m_tolerance.m_storage;
  v16 = (hkpCollisionQueryJobHeader *)v12;
  v23.m_size = 80;
  *(_WORD *)&v23.m_jobSubType = 514;
  v23.m_jobSpuType.m_storage = 2;
  v17 = v9;
  v23.m_threadAffinity = -1;
  v23.m_jobDoneFlag = 0i64;
  if ( (int)v9 > 0 )
  {
    p_m_numResultsOut = &commandArray->m_numResultsOut;
    do
    {
      *p_m_numResultsOut = 0;
      p_m_numResultsOut += 6;
      --v17;
    }
    while ( v17 );
  }
  v23.m_collisionInput = m_collisionInput;
  v23.m_tolerance = m_storage;
  v23.m_sharedJobHeaderOnPpu = v16;
  v23.m_numCommandsPerTask = 64;
  v23.m_broadphase = m_broadPhase;
  v23.m_semaphore = semaphore;
  v23.m_commandArray = commandArray;
  v23.m_numCommands = v9;
  v16->m_openJobs = ((int)v9 - 1) / 64 + 1;
  hkpWorldGetClosestPointsJob::setRunsOnSpuOrPpu(&v23);
  for ( i = v23.m_numCommands; v23.m_numCommands > 0; i = v23.m_numCommands )
  {
    v20 = numCommandsPerJob;
    if ( i < numCommandsPerJob )
      v20 = i;
    job = v23.hkJob;
    v25 = *(_OWORD *)&v23.m_semaphore;
    v26 = *(_OWORD *)&v23.m_collisionInput;
    v21 = *(_OWORD *)&v23.m_commandArray;
    v23.m_commandArray += numCommandsPerJob;
    v23.m_numCommands = i - numCommandsPerJob;
    v28 = v21;
    v27 = *(_OWORD *)&v23.m_broadphase;
    DWORD2(v28) = v20;
    hkJobQueue::addJob(jobQueue, &job, JOB_LOW_PRIORITY);
  }
  ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, __int64))jobThreadPool->vfptr[5].__first_virtual_table_function__)(
    jobThreadPool,
    jobQueue,
    20i64);
  hkJobQueue::processAllJobs(jobQueue, 1);
  ((void (__fastcall *)(hkJobThreadPool *))jobThreadPool->vfptr[2].__vecDelDtor)(jobThreadPool);
  hkSemaphore::acquire(semaphore);
  v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkpCollisionQueryJobHeader *, __int64))(*v22[11] + 16i64))(v22[11], v16, 16i64);
}

// File Line: 3681
// RVA: 0xD5BEC0
void __fastcall hkpWorld::getPenetrations(
        hkpWorld *this,
        hkpCollidable *collA,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpProcessCollisionInput *m_collisionInput; // rax
  hkpShape *m_shape; // rcx
  hkBaseObjectVtbl *vfptr; // rax
  const void *m_motion; // rdx
  _QWORD *Value; // r8
  unsigned __int64 v13; // rcx
  unsigned __int64 v14; // rax
  hkpBroadPhase *m_broadPhase; // rcx
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx
  int v20; // esi
  __int64 m_storage; // r12
  char *v22; // rdi
  hkpCollidable *v23; // rbx
  _QWORD *v24; // rax
  _QWORD *v25; // rcx
  _QWORD *v26; // r8
  unsigned __int64 v27; // rax
  _QWORD *v28; // rcx
  char v29[32]; // [rsp+20h] [rbp-868h] BYREF
  char *v30; // [rsp+40h] [rbp-848h] BYREF
  int v31; // [rsp+48h] [rbp-840h]
  int v32; // [rsp+4Ch] [rbp-83Ch]
  char v33; // [rsp+50h] [rbp-838h] BYREF
  int v34; // [rsp+890h] [rbp+8h] BYREF
  float v35; // [rsp+898h] [rbp+10h]

  m_collisionInput = this->m_collisionInput;
  m_shape = collA->m_shape;
  v35 = input->m_tolerance.m_storage - (float)(m_collisionInput->m_tolerance.m_storage * 0.5);
  vfptr = m_shape->vfptr;
  m_motion = collA->m_motion;
  v34 = 0;
  ((void (__fastcall *)(hkpShape *, const void *, hkpCollisionInput *, char *))vfptr[2].__vecDelDtor)(
    m_shape,
    m_motion,
    input,
    v29);
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = Value[1];
  if ( v13 < Value[3] )
  {
    *(_QWORD *)v13 = "LthkpWorld::getPenetrations";
    *(_QWORD *)(v13 + 16) = "StBroadPhase";
    v14 = __rdtsc();
    *(_DWORD *)(v13 + 8) = v14;
    Value[1] = v13 + 24;
  }
  m_broadPhase = this->m_broadPhase;
  v31 = 0;
  v30 = &v33;
  v32 = -2147483520;
  ((void (__fastcall *)(hkpBroadPhase *, char *, char **))m_broadPhase->vfptr[9].__vecDelDtor)(m_broadPhase, v29, &v30);
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "StNarrowPhase";
    v18 = __rdtsc();
    v19 = v17 + 2;
    *((_DWORD *)v19 - 2) = v18;
    v16[1] = v19;
  }
  v20 = v31 - 1;
  m_storage = (unsigned __int8)collA->m_shape->m_type.m_storage;
  if ( v31 - 1 >= 0 )
  {
    v22 = v30 + 8;
    do
    {
      v23 = (hkpCollidable *)(*(_QWORD *)v22 + *(char *)(*(_QWORD *)v22 + 5i64));
      if ( collA != v23 )
      {
        if ( this->m_collisionFilter->vfptr->isCollisionEnabled(
               &this->m_collisionFilter->hkpCollidableCollidableFilter,
               &v34,
               collA,
               *(_QWORD *)v22 + *(char *)(*(_QWORD *)v22 + 5i64))->m_bool )
        {
          if ( v23->m_shape )
          {
            input->m_dispatcher.m_storage->m_agent2Func[(unsigned __int8)input->m_dispatcher.m_storage->m_agent2Types[m_storage][(unsigned __int8)v23->m_shape->m_type.m_storage]].m_getPenetrationsFunc(
              collA,
              v23,
              input,
              collector);
            if ( collector->m_earlyOut.m_bool )
              break;
          }
        }
      }
      v22 += 16;
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
    v28 = v25 + 2;
    *((_DWORD *)v28 - 2) = v27;
    v26[1] = v28;
  }
  v31 = 0;
  if ( v32 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v30, 16 * v32);
}

// File Line: 3732
// RVA: 0xD5B780
void __fastcall hkpWorld::linearCast(
        hkpWorld *this,
        hkpCollidable *collA,
        hkpLinearCastInput *input,
        hkpCdPointCollector *castCollector,
        hkpCdPointCollector *startPointCollector)
{
  _QWORD *Value; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  hkpCollisionFilter *m_collisionFilter; // rax
  hkpCollidableCollidableFilter *filter; // rdx
  _QWORD *v16; // rax
  _QWORD *v17; // rcx
  _QWORD *v18; // r8
  unsigned __int64 v19; // rax
  _QWORD *v20; // rcx
  hkpWorldLinearCaster v21; // [rsp+50h] [rbp-C8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtworldLinCast";
    v12 = __rdtsc();
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  v21.vfptr = (hkpBroadPhaseCastCollectorVtbl *)&hkpWorldLinearCaster::`vftable;
  m_collisionFilter = this->m_collisionFilter;
  v21.m_shapeInput.m_maxExtraPenetration = FLOAT_1_1920929eN7;
  filter = &m_collisionFilter->hkpCollidableCollidableFilter;
  v21.m_shapeInput.m_forceAcceptContactPoints.m_storage = 0;
  if ( !m_collisionFilter )
    filter = 0i64;
  hkpWorldLinearCaster::linearCast(
    &v21,
    this->m_broadPhase,
    collA,
    input,
    filter,
    this->m_collisionInput,
    this->m_collisionInput->m_config,
    0i64,
    castCollector,
    startPointCollector);
  v21.vfptr = (hkpBroadPhaseCastCollectorVtbl *)&hkpBroadPhaseCastCollector::`vftable;
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  v18 = v16;
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "Et";
    v19 = __rdtsc();
    v20 = v17 + 2;
    *((_DWORD *)v20 - 2) = v19;
    v18[1] = v20;
  }
}

// File Line: 3742
// RVA: 0xD5B8D0
void __fastcall hkpWorld::linearCastMt(
        hkpWorld *this,
        hkpWorldLinearCastCommand *commandArray,
        int numCommands,
        hkJobQueue *jobQueue,
        hkJobThreadPool *jobThreadPool,
        hkSemaphore *semaphore,
        int numCommandsPerJob)
{
  _QWORD **Value; // rax
  hkpCollisionQueryJobHeader *v12; // r15
  hkpBroadPhase *m_broadPhase; // rax
  int i; // ecx
  int v15; // eax
  __int128 v16; // xmm0
  _QWORD **v17; // rax
  hkpWorldLinearCastJob v18; // [rsp+20h] [rbp-71h] BYREF
  hkJob job; // [rsp+70h] [rbp-21h] BYREF
  __int128 v20; // [rsp+80h] [rbp-11h]
  __int128 v21; // [rsp+90h] [rbp-1h]
  __int128 v22; // [rsp+A0h] [rbp+Fh]
  __int128 v23; // [rsp+B0h] [rbp+1Fh]

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkpCollisionQueryJobHeader *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                        Value[11],
                                        16i64);
  v18.m_collisionInput = this->m_collisionInput;
  v18.m_size = 80;
  *(_WORD *)&v18.m_jobSubType = 516;
  v18.m_threadAffinity = -1;
  m_broadPhase = this->m_broadPhase;
  v18.m_jobSpuType.m_storage = 2;
  v18.m_broadphase = m_broadPhase;
  v18.m_jobDoneFlag = 0i64;
  v18.m_sharedJobHeaderOnPpu = v12;
  v18.m_numCommandsPerTask = 64;
  v18.m_semaphore = semaphore;
  v18.m_commandArray = commandArray;
  v18.m_numCommands = numCommands;
  v12->m_openJobs = (numCommands - 1) / 64 + 1;
  hkpWorldLinearCastJob::setRunsOnSpuOrPpu(&v18);
  for ( i = v18.m_numCommands; v18.m_numCommands > 0; i = v18.m_numCommands )
  {
    v15 = numCommandsPerJob;
    if ( i < numCommandsPerJob )
      v15 = i;
    job = v18.hkJob;
    v20 = *(_OWORD *)&v18.m_semaphore;
    v21 = *(_OWORD *)&v18.m_collisionInput;
    v16 = *(_OWORD *)&v18.m_numCommands;
    v18.m_numCommands = i - numCommandsPerJob;
    v22 = *(_OWORD *)&v18.m_numCommandsPerTask;
    v23 = v16;
    LODWORD(v23) = v15;
    v18.m_commandArray = (hkpWorldLinearCastCommand *)(((__int64)numCommandsPerJob << 6)
                                                     + _mm_srli_si128(*(__m128i *)&v18.m_numCommandsPerTask, 8).m128i_u64[0]);
    hkJobQueue::addJob(jobQueue, &job, JOB_LOW_PRIORITY);
  }
  ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, __int64))jobThreadPool->vfptr[5].__first_virtual_table_function__)(
    jobThreadPool,
    jobQueue,
    20i64);
  hkJobQueue::processAllJobs(jobQueue, 1);
  ((void (__fastcall *)(hkJobThreadPool *))jobThreadPool->vfptr[2].__vecDelDtor)(jobThreadPool);
  hkSemaphore::acquire(semaphore);
  v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkpCollisionQueryJobHeader *, __int64))(*v17[11] + 16i64))(v17[11], v12, 16i64);
}

// File Line: 3772
// RVA: 0xD5DE10
hkBool *__fastcall enumerateAllInactiveEntitiesInWorld(hkBool *result, hkpWorld *world, hkpPhysicsSystem *sys)
{
  hkpSimulationIsland *m_fixedIsland; // rdi
  bool v4; // bl
  __int64 v8; // rbx
  int i; // esi
  hkpSimulationIsland **m_data; // r14
  hkpSimulationIsland *v11; // rdi
  int v12; // ebp
  __int64 v13; // rsi

  m_fixedIsland = world->m_fixedIsland;
  v4 = 0;
  if ( m_fixedIsland )
  {
    v8 = 0i64;
    for ( i = 0; i < m_fixedIsland->m_entities.m_size; ++v8 )
    {
      if ( v8 || (*m_fixedIsland->m_entities.m_data)->m_collidable.m_shape )
        hkpPhysicsSystem::addRigidBody(sys, (hkpRigidBody *)m_fixedIsland->m_entities.m_data[v8]);
      ++i;
    }
    v4 = m_fixedIsland->m_entities.m_size > 0;
  }
  m_data = world->m_inactiveSimulationIslands.m_data;
  if ( m_data != &m_data[world->m_inactiveSimulationIslands.m_size] )
  {
    do
    {
      v11 = *m_data;
      v12 = 0;
      if ( (*m_data)->m_entities.m_size > 0 )
      {
        v13 = 0i64;
        do
        {
          hkpPhysicsSystem::addRigidBody(sys, (hkpRigidBody *)v11->m_entities.m_data[v13]);
          ++v12;
          ++v13;
        }
        while ( v12 < v11->m_entities.m_size );
      }
      ++m_data;
    }
    while ( m_data != &world->m_inactiveSimulationIslands.m_data[world->m_inactiveSimulationIslands.m_size] );
  }
  if ( world->m_inactiveSimulationIslands.m_size > 0 || v4 )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 3803
// RVA: 0xD5DF30
hkBool *__fastcall enumerateAllActiveEntitiesInWorld(hkBool *result, hkpWorld *world, hkpPhysicsSystem *sys)
{
  hkpSimulationIsland **m_data; // r14
  hkpSimulationIsland *v7; // rbx
  int v8; // esi
  __int64 v9; // rdi

  m_data = world->m_activeSimulationIslands.m_data;
  if ( m_data != &m_data[world->m_activeSimulationIslands.m_size] )
  {
    do
    {
      v7 = *m_data;
      v8 = 0;
      if ( (*m_data)->m_entities.m_size > 0 )
      {
        v9 = 0i64;
        do
        {
          hkpPhysicsSystem::addRigidBody(sys, (hkpRigidBody *)v7->m_entities.m_data[v9]);
          ++v8;
          ++v9;
        }
        while ( v8 < v7->m_entities.m_size );
      }
      ++m_data;
    }
    while ( m_data != &world->m_activeSimulationIslands.m_data[world->m_activeSimulationIslands.m_size] );
  }
  result->m_bool = world->m_activeSimulationIslands.m_size > 0;
  return result;
}

// File Line: 3819
// RVA: 0xD5DFF0
void __fastcall enumerateAllEntitiesInWorld(hkpWorld *world, hkpPhysicsSystem *sys)
{
  hkBool result; // [rsp+38h] [rbp+10h] BYREF

  enumerateAllInactiveEntitiesInWorld(&result, world, sys);
  sys->m_active = (hkBool)enumerateAllActiveEntitiesInWorld(&result, world, sys)->m_bool;
}

// File Line: 3825
// RVA: 0xD5E040
void __fastcall enumerateAllConstraintsInIsland(hkpSimulationIsland *island, hkpPhysicsSystem *sys)
{
  int v4; // ebp
  __int64 v5; // r14
  int v6; // edi
  hkpEntity *v7; // rsi
  __int64 v8; // rbx
  hkConstraintInternal *m_data; // rdx
  hkpConstraintAtom *i; // rax

  v4 = 0;
  if ( island->m_entities.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = 0;
      v7 = island->m_entities.m_data[v5];
      if ( v7->m_constraintsMaster.m_size )
      {
        v8 = 0i64;
        do
        {
          m_data = v7->m_constraintsMaster.m_data;
          for ( i = m_data[v8].m_atoms; i->m_type.m_storage >= 0x1Eu; i = *(hkpConstraintAtom **)&i[12].m_type.m_storage )
            ;
          if ( i->m_type.m_storage != 29 )
            hkpPhysicsSystem::addConstraint(sys, m_data[v8].m_constraint);
          ++v6;
          ++v8;
        }
        while ( v6 < v7->m_constraintsMaster.m_size );
      }
      ++v4;
      ++v5;
    }
    while ( v4 < island->m_entities.m_size );
  }
}

// File Line: 3846
// RVA: 0xD5E120
void __fastcall enumerateAllConstraintsInWorld(hkpWorld *world, hkpPhysicsSystem *sys)
{
  hkpSimulationIsland **m_data; // rbx
  hkpSimulationIsland **v5; // rbx

  m_data = world->m_activeSimulationIslands.m_data;
  if ( m_data != &m_data[world->m_activeSimulationIslands.m_size] )
  {
    do
      enumerateAllConstraintsInIsland(*m_data++, sys);
    while ( m_data != &world->m_activeSimulationIslands.m_data[world->m_activeSimulationIslands.m_size] );
  }
  v5 = world->m_inactiveSimulationIslands.m_data;
  if ( v5 != &v5[world->m_inactiveSimulationIslands.m_size] )
  {
    do
      enumerateAllConstraintsInIsland(*v5++, sys);
    while ( v5 != &world->m_inactiveSimulationIslands.m_data[world->m_inactiveSimulationIslands.m_size] );
  }
}

// File Line: 3864
// RVA: 0xD5E1C0
void __fastcall enumerateAllActionsInWorld(hkpWorld *world, hkpPhysicsSystem *sys)
{
  hkpSimulationIsland **m_data; // r14
  hkpSimulationIsland *v5; // rbx
  int v6; // esi
  __int64 v7; // rdi
  hkpSimulationIsland **v8; // r14
  hkpSimulationIsland *v9; // rbx
  int v10; // esi
  __int64 v11; // rdi

  m_data = world->m_activeSimulationIslands.m_data;
  if ( m_data != &m_data[world->m_activeSimulationIslands.m_size] )
  {
    do
    {
      v5 = *m_data;
      v6 = 0;
      if ( (*m_data)->m_actions.m_size > 0 )
      {
        v7 = 0i64;
        do
        {
          hkpPhysicsSystem::addAction(sys, v5->m_actions.m_data[v7]);
          ++v6;
          ++v7;
        }
        while ( v6 < v5->m_actions.m_size );
      }
      ++m_data;
    }
    while ( m_data != &world->m_activeSimulationIslands.m_data[world->m_activeSimulationIslands.m_size] );
  }
  v8 = world->m_inactiveSimulationIslands.m_data;
  if ( v8 != &v8[world->m_inactiveSimulationIslands.m_size] )
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
          hkpPhysicsSystem::addAction(sys, v9->m_actions.m_data[v11]);
          ++v10;
          ++v11;
        }
        while ( v10 < v9->m_actions.m_size );
      }
      ++v8;
    }
    while ( v8 != &world->m_inactiveSimulationIslands.m_data[world->m_inactiveSimulationIslands.m_size] );
  }
}

// File Line: 3890
// RVA: 0xD5E2A0
void __fastcall enumerateAllPhantomsInWorld(hkpWorld *world, hkpPhysicsSystem *sys)
{
  int v4; // ebx
  hkpBroadPhaseBorder *BroadPhaseBorder; // rdi
  __int64 v6; // r14
  hkpPhantom *v7; // rdx
  __int64 v8; // rdi

  v4 = 0;
  BroadPhaseBorder = hkpWorld::getBroadPhaseBorder(world);
  if ( BroadPhaseBorder )
  {
    if ( world->m_phantoms.m_size > 0 )
    {
      v6 = 0i64;
      do
      {
        v7 = world->m_phantoms.m_data[v6];
        if ( v7 != BroadPhaseBorder->m_phantoms[0]
          && v7 != BroadPhaseBorder->m_phantoms[1]
          && v7 != BroadPhaseBorder->m_phantoms[2]
          && v7 != BroadPhaseBorder->m_phantoms[3]
          && v7 != BroadPhaseBorder->m_phantoms[4]
          && v7 != BroadPhaseBorder->m_phantoms[5] )
        {
          hkpPhysicsSystem::addPhantom(sys, v7);
        }
        ++v4;
        ++v6;
      }
      while ( v4 < world->m_phantoms.m_size );
    }
  }
  else if ( world->m_phantoms.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      hkpPhysicsSystem::addPhantom(sys, world->m_phantoms.m_data[v8]);
      ++v4;
      ++v8;
    }
    while ( v4 < world->m_phantoms.m_size );
  }
}

// File Line: 3919
// RVA: 0xD5C970
hkpPhysicsSystem *__fastcall hkpWorld::getWorldAsOneSystem(hkpWorld *this)
{
  _QWORD **Value; // rax
  hkpPhysicsSystem *v3; // rax
  hkpPhysicsSystem *v4; // rax
  hkpPhysicsSystem *v5; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 104i64);
  if ( v3 )
  {
    hkpPhysicsSystem::hkpPhysicsSystem(v3);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  enumerateAllEntitiesInWorld(this, v5);
  enumerateAllPhantomsInWorld(this, v5);
  enumerateAllConstraintsInWorld(this, v5);
  enumerateAllActionsInWorld(this, v5);
  return v5;
}

// File Line: 3937
// RVA: 0xD5C9F0
void __fastcall hkpWorld::getWorldAsSystems(
        hkpWorld *this,
        hkArray<hkpPhysicsSystem *,hkContainerHeapAllocator> *systemsInOut)
{
  _QWORD **Value; // rax
  hkpPhysicsSystem *v5; // rax
  hkpPhysicsSystem *v6; // rax
  hkpPhysicsSystem *v7; // rdi
  _QWORD **v8; // rax
  hkpPhysicsSystem *v9; // rax
  hkpPhysicsSystem *v10; // rax
  hkBool result; // [rsp+38h] [rbp+10h] BYREF

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 104i64);
  if ( v5 )
  {
    hkpPhysicsSystem::hkpPhysicsSystem(v5);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  if ( enumerateAllInactiveEntitiesInWorld(&result, this, v7)->m_bool )
  {
    v7->m_active.m_bool = 0;
    if ( systemsInOut->m_size == (systemsInOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&systemsInOut->m_data, 8);
    systemsInOut->m_data[systemsInOut->m_size++] = v7;
  }
  else if ( v7 )
  {
    goto LABEL_12;
  }
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v8[11] + 8i64))(v8[11], 104i64);
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
  if ( systemsInOut->m_size == (systemsInOut->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&systemsInOut->m_data, 8);
  systemsInOut->m_data[systemsInOut->m_size++] = v7;
  enumerateAllActiveEntitiesInWorld(&result, this, v7);
  enumerateAllPhantomsInWorld(this, v7);
  enumerateAllConstraintsInWorld(this, v7);
  enumerateAllActionsInWorld(this, v7);
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
  signed int m_nextFreeElement; // edx
  __int64 v3; // rbx
  __int64 v4; // rsi

  m_nextFreeElement = this->m_violatedConstraintArray->m_nextFreeElement;
  if ( m_nextFreeElement >= 128 )
    m_nextFreeElement = 128;
  v3 = 0i64;
  v4 = m_nextFreeElement;
  if ( m_nextFreeElement <= 0 )
  {
    this->m_violatedConstraintArray->m_nextFreeElement = 0;
  }
  else
  {
    do
      hkpWorldCallbackUtil::fireConstraintViolated(this, this->m_violatedConstraintArray->m_constraints[v3++]);
    while ( v3 < v4 );
    this->m_violatedConstraintArray->m_nextFreeElement = 0;
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
void __fastcall hkpWorld::addBodyOperation(
        hkpWorld *this,
        hkpRigidBody *breakingBody,
        hkpBodyOperation *operation,
        int priority,
        int hint)
{
  hkpWorldOperationQueue::queueBodyOperation(
    this->m_pendingOperations,
    breakingBody,
    operation,
    priority,
    (hkpBodyOperation::ExecutionState)hint);
}

// File Line: 4016
// RVA: 0xD5D8D0
hkWorldOperation::UserCallback *__fastcall hkpWorld::queueCallback(
        hkpWorld *this,
        hkWorldOperation::UserCallback *callback,
        __int64 userData)
{
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h] BYREF
  hkWorldOperation::UserCallback *v6; // [rsp+28h] [rbp-20h]
  __int64 v7; // [rsp+30h] [rbp-18h]

  if ( this->m_criticalOperationsLockCount )
  {
    v6 = callback;
    operation.m_type.m_storage = 38;
    v7 = userData;
    hkpWorld::queueOperation(this, &operation);
  }
  else
  {
    ((void (__fastcall *)(hkWorldOperation::UserCallback *, __int64))callback->vfptr[1].__first_virtual_table_function__)(
      callback,
      userData);
  }
  return callback;
}

// File Line: 4032
// RVA: 0xD5A3E0
void __fastcall hkpWorld::findInitialContactPoints(hkpWorld *this, hkpEntity **entities, __int64 numEntities)
{
  hkpSimulation *m_simulation; // rcx
  float v5; // xmm0_4
  int v6[6]; // [rsp+30h] [rbp-18h] BYREF

  m_simulation = this->m_simulation;
  v5 = 0.0;
  v6[0] = LODWORD(m_simulation->m_currentPsiTime);
  v6[1] = v6[0];
  *(float *)&v6[2] = *(float *)v6 - *(float *)v6;
  if ( (float)(*(float *)v6 - *(float *)v6) != 0.0 )
    v5 = 1.0 / (float)(*(float *)v6 - *(float *)v6);
  *(float *)&v6[3] = v5;
  ((void (__fastcall *)(hkpSimulation *, hkpEntity **, __int64, hkpWorld *, int *, int))m_simulation->vfptr[5].__first_virtual_table_function__)(
    m_simulation,
    entities,
    numEntities,
    this,
    v6,
    1);
}

// File Line: 4042
// RVA: 0xD5A450
void __fastcall hkpWorld::findInitialContactPointsOfAllEntities(hkpWorld *this)
{
  int v1; // edi
  int v3; // ebp
  __int64 v4; // rsi
  __int64 v5; // rsi

  v1 = 0;
  v3 = 0;
  if ( this->m_activeSimulationIslands.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      hkpWorld::findInitialContactPoints(
        this,
        this->m_activeSimulationIslands.m_data[v4]->m_entities.m_data,
        (unsigned int)this->m_activeSimulationIslands.m_data[v4]->m_entities.m_size);
      ++v3;
      ++v4;
    }
    while ( v3 < this->m_activeSimulationIslands.m_size );
  }
  if ( this->m_inactiveSimulationIslands.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      hkpWorld::findInitialContactPoints(
        this,
        this->m_inactiveSimulationIslands.m_data[v5]->m_entities.m_data,
        (unsigned int)this->m_inactiveSimulationIslands.m_data[v5]->m_entities.m_size);
      ++v1;
      ++v5;
    }
    while ( v1 < this->m_inactiveSimulationIslands.m_size );
  }
}

// File Line: 4056
// RVA: 0xD5A4F0
void __fastcall hkpWorld::calcRequiredSolverBufferSize(
        hkpWorld *this,
        hkWorldMemoryAvailableWatchDog::MemUsageInfo *infoOut)
{
  __int64 v4; // rdx
  __int64 v5; // r8
  int v6; // r11d
  int v7; // eax
  __int64 i; // r9
  hkpSimulationIsland *v9; // r10
  int v10; // ecx
  int m_sumRuntimeBlockSize; // eax

  hkpWorldOperationUtil::cleanupDirtyIslands(this);
  v6 = 0;
  *(_QWORD *)&infoOut->m_maxRuntimeBlockSize = 0i64;
  infoOut->m_largestSimulationIsland = 0i64;
  v7 = this->m_activeSimulationIslands.m_size - 1;
  for ( i = v7; i >= 0; --i )
  {
    v9 = this->m_activeSimulationIslands.m_data[i];
    v4 = (unsigned int)(2 * (v9->m_numConstraints / 80) + 8);
    v5 = 32 * ((_DWORD)v4 + 4 * v9->m_entities.m_size)
       + ((4 * (v9->m_constraintInfo.m_numSolverElemTemps + 3 * (_DWORD)v4) + 23) & 0xFFFFFFF0)
       + 176;
    v10 = v5 + v9->m_constraintInfo.m_sizeOfSchemas;
    v6 += v10;
    infoOut->m_sumRuntimeBlockSize = v6;
    if ( v10 > infoOut->m_maxRuntimeBlockSize )
    {
      infoOut->m_maxRuntimeBlockSize = v10;
      infoOut->m_largestSimulationIsland = v9;
    }
  }
  if ( (unsigned int)(this->m_simulationType.m_storage - 2) <= 1 )
  {
    m_sumRuntimeBlockSize = (*(__int64 (__fastcall **)(_QWORD, __int64, __int64, __int64))(**(_QWORD **)&this->m_simulation[1].m_lastProcessingStep.m_storage
                                                                                         + 56i64))(
                              *(_QWORD *)&this->m_simulation[1].m_lastProcessingStep.m_storage,
                              v4,
                              v5,
                              i);
    if ( infoOut->m_sumRuntimeBlockSize > m_sumRuntimeBlockSize )
      m_sumRuntimeBlockSize = infoOut->m_sumRuntimeBlockSize;
    infoOut->m_sumRuntimeBlockSize = m_sumRuntimeBlockSize;
  }
}

// File Line: 4096
// RVA: 0xD5A630
void __fastcall hkpWorld::lock(hkpWorld *this)
{
  hkReferencedObject::lockAll();
  ++this->m_isLocked;
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
  hkCriticalSection *m_modifyConstraintCriticalSection; // rcx

  m_modifyConstraintCriticalSection = this->m_modifyConstraintCriticalSection;
  if ( m_modifyConstraintCriticalSection )
    EnterCriticalSection(&m_modifyConstraintCriticalSection->m_section);
}

// File Line: 4154
// RVA: 0xD5A6C0
void __fastcall hkpWorld::lockForIslandSplit(hkpWorld *this, hkpSimulationIsland *island)
{
  hkCriticalSection *m_modifyConstraintCriticalSection; // rcx

  m_modifyConstraintCriticalSection = this->m_modifyConstraintCriticalSection;
  if ( m_modifyConstraintCriticalSection )
    EnterCriticalSection(&m_modifyConstraintCriticalSection->m_section);
}

// File Line: 4166
// RVA: 0xD5A6E0
void __fastcall hkpWorld::unlockIslandForConstraintUpdate(hkpWorld *this, hkpSimulationIsland *island)
{
  hkCriticalSection *m_modifyConstraintCriticalSection; // rcx

  m_modifyConstraintCriticalSection = this->m_modifyConstraintCriticalSection;
  if ( m_modifyConstraintCriticalSection )
    LeaveCriticalSection(&m_modifyConstraintCriticalSection->m_section);
}

// File Line: 4181
// RVA: 0xD5A700
void __fastcall hkpWorld::unlockForIslandSplit(hkpWorld *this, hkpSimulationIsland *island)
{
  hkCriticalSection *m_modifyConstraintCriticalSection; // rcx

  m_modifyConstraintCriticalSection = this->m_modifyConstraintCriticalSection;
  if ( m_modifyConstraintCriticalSection )
    LeaveCriticalSection(&m_modifyConstraintCriticalSection->m_section);
}

// File Line: 4193
// RVA: 0xD5A720
void __fastcall hkpWorld::setMultithreadedAccessChecking(hkpWorld *this, hkpWorld::MtAccessChecking accessCheckState)
{
  hkMultiThreadCheck *p_m_multiThreadCheck; // rcx

  p_m_multiThreadCheck = &this->m_multiThreadCheck;
  if ( accessCheckState )
  {
    hkMultiThreadCheck::disableChecks(p_m_multiThreadCheck);
    hkMultiThreadCheck::disableChecks(&this->m_broadPhase->m_multiThreadCheck);
  }
  else
  {
    hkMultiThreadCheck::enableChecks(p_m_multiThreadCheck);
    hkMultiThreadCheck::enableChecks(&this->m_broadPhase->m_multiThreadCheck);
  }
}

// File Line: 4207
// RVA: 0xD5A770
_BOOL8 __fastcall hkpWorld::getMultithreadedAccessChecking(hkpWorld *this)
{
  return (this->m_multiThreadCheck.m_markCount & 0x8000u) != 0 || !hkMultiThreadCheck::m_criticalSection;
}


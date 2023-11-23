// File Line: 113
// RVA: 0xD73250
hkJobQueue::JobStatus __fastcall hkpMultiThreadedSimulation::processNextJob(
        hkJobQueue *jobQueue,
        hkJobQueue::JobQueueEntry *job)
{
  int m_jobSubType; // eax
  hkJobQueue::JobStatus result; // eax
  hkBool jobWasCancelledOut; // [rsp+38h] [rbp+10h] BYREF

  m_jobSubType = (unsigned __int8)job->m_jobSubType;
  jobWasCancelledOut.m_bool = 0;
  switch ( m_jobSubType )
  {
    case 0:
      result = integrateJob(*(hkpMtThreadStructure **)&job->m_data[24], jobQueue, job, &jobWasCancelledOut);
      break;
    case 1:
      result = hkCpuBuildAccumulatorsJob(*(hkpMtThreadStructure **)&job->m_data[24], jobQueue, job);
      break;
    case 3:
      result = hkpSingleThreadedJobsOnIsland::cpuFireJacobianSetupCallbackJob(
                 *(hkpMtThreadStructure **)&job->m_data[24],
                 jobQueue,
                 job);
      break;
    case 4:
      result = hkCpuBuildJacobiansJob(*(hkpMtThreadStructure **)&job->m_data[24], jobQueue, job);
      break;
    case 5:
      result = hkCpuSplitSimulationIslandJob(*(hkpMtThreadStructure **)&job->m_data[24], jobQueue, job);
      break;
    case 6:
      result = hkCpuSolveConstraintsJob(*(hkpMtThreadStructure **)&job->m_data[24], jobQueue, job);
      break;
    case 7:
      result = hkCpuSolveApplyGravityJob(*(hkpMtThreadStructure **)&job->m_data[24], jobQueue, job);
      break;
    case 8:
      result = hkCpuSolveConstraintBatchJob(*(hkpMtThreadStructure **)&job->m_data[24], jobQueue, job);
      break;
    case 9:
      result = hkCpuSolveIntegrateVelocitiesJob(*(hkpMtThreadStructure **)&job->m_data[24], jobQueue, job);
      break;
    case 10:
      result = hkCpuSolveExportResultsJob(*(hkpMtThreadStructure **)&job->m_data[24], jobQueue, job);
      break;
    case 11:
      result = hkCpuIntegrateMotionJob(*(hkpMtThreadStructure **)&job->m_data[24], jobQueue, job);
      break;
    case 12:
      result = hkpSingleThreadedJobsOnIsland::cpuBroadPhaseJob(
                 *(hkpMtThreadStructure **)&job->m_data[24],
                 jobQueue,
                 job);
      break;
    case 13:
    case 15:
      result = hkCpuAgentSectorJob(*(hkpMtThreadStructure **)&job->m_data[24], jobQueue, job);
      break;
    case 14:
      result = hkCpuPostCollideJob(*(hkpMtThreadStructure **)&job->m_data[24], jobQueue, job);
      break;
    default:
      result = NO_JOBS_AVAILABLE;
      break;
  }
  return result;
}

// File Line: 238
// RVA: 0xD74D90
void __fastcall hkpMultiThreadedSimulation::MtPhantomBroadPhaseListener::addCollisionPair(
        hkpMultiThreadedSimulation::MtPhantomBroadPhaseListener *this,
        hkpTypedBroadPhaseHandlePair *pair)
{
  char *v3; // rcx
  hkpBroadPhaseHandle *m_b; // rcx
  char *v5; // rcx

  if ( LOBYTE(pair->m_a[1].m_id) == 2 )
  {
    v3 = (char *)pair->m_a + SBYTE1(pair->m_a[1].m_id) + *((char *)&pair->m_a[8].m_id + SBYTE1(pair->m_a[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v3 + 64i64))(v3, (char *)pair->m_b + SBYTE1(pair->m_b[1].m_id));
  }
  m_b = pair->m_b;
  if ( LOBYTE(m_b[1].m_id) == 2 )
  {
    v5 = (char *)m_b + SBYTE1(m_b[1].m_id) + *((char *)&m_b[8].m_id + SBYTE1(m_b[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v5 + 64i64))(v5, (char *)pair->m_a + SBYTE1(pair->m_a[1].m_id));
  }
}

// File Line: 262
// RVA: 0xD74E10
void __fastcall hkpMultiThreadedSimulation::MtPhantomBroadPhaseListener::removeCollisionPair(
        hkpMultiThreadedSimulation::MtPhantomBroadPhaseListener *this,
        hkpTypedBroadPhaseHandlePair *pair)
{
  char *v3; // rcx
  hkpBroadPhaseHandle *m_b; // rcx
  char *v5; // rcx

  if ( LOBYTE(pair->m_a[1].m_id) == 2 )
  {
    v3 = (char *)pair->m_a + SBYTE1(pair->m_a[1].m_id) + *((char *)&pair->m_a[8].m_id + SBYTE1(pair->m_a[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v3 + 80i64))(v3, (char *)pair->m_b + SBYTE1(pair->m_b[1].m_id));
  }
  m_b = pair->m_b;
  if ( LOBYTE(m_b[1].m_id) == 2 )
  {
    v5 = (char *)m_b + SBYTE1(m_b[1].m_id) + *((char *)&m_b[8].m_id + SBYTE1(m_b[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v5 + 80i64))(v5, (char *)pair->m_a + SBYTE1(pair->m_a[1].m_id));
  }
}

// File Line: 298
// RVA: 0xD74BA0
void __fastcall hkpMultiThreadedSimulation::MtEntityEntityBroadPhaseListener::addCollisionPair(
        hkpMultiThreadedSimulation::MtEntityEntityBroadPhaseListener *this,
        hkpTypedBroadPhaseHandlePair *pair)
{
  hkpMultiThreadedSimulation *m_simulation; // r9
  hkpLinkedCollidable *v4; // r11
  __int64 m_ownerOffset; // r8
  hkpLinkedCollidable *v6; // rdx
  __int64 v7; // rax
  hkArray<hkpTypedBroadPhaseHandlePair,hkContainerHeapAllocator> *p_m_addedCrossIslandPairs; // rbx
  hkpBroadPhaseHandle **p_m_a; // rcx
  hkpProcessCollisionInput *m_collisionInput; // r8
  char v11; // al

  m_simulation = this->m_simulation;
  v4 = (hkpLinkedCollidable *)((char *)pair->m_a + SBYTE1(pair->m_a[1].m_id));
  m_ownerOffset = v4->m_ownerOffset;
  v6 = (hkpLinkedCollidable *)((char *)pair->m_b + SBYTE1(pair->m_b[1].m_id));
  v7 = v6->m_ownerOffset;
  if ( !m_simulation->m_crossIslandPairsCollectingActive.m_bool
    || *((_BYTE *)&v4[2].m_boundingVolumeData.m_childShapeKeys + m_ownerOffset) == 5
    || *((_BYTE *)&v6[2].m_boundingVolumeData.m_childShapeKeys + v7) == 5
    || *(_QWORD *)(&v4[2].m_broadPhaseHandle.m_type + m_ownerOffset) == *(_QWORD *)(&v6[2].m_broadPhaseHandle.m_type + v7) )
  {
    m_collisionInput = m_simulation->m_world->m_collisionInput;
    v11 = m_collisionInput->m_dispatcher.m_storage->m_collisionQualityTable[v4->m_broadPhaseHandle.m_objectQualityType][v6->m_broadPhaseHandle.m_objectQualityType];
    if ( v11 )
    {
      m_collisionInput->m_createPredictiveAgents.m_storage = m_collisionInput->m_dispatcher.m_storage->m_collisionQualityInfo[(__int64)v11].m_useContinuousPhysics.m_storage;
      hkpWorldAgentUtil::addAgent(v4, v6, m_collisionInput);
    }
  }
  else
  {
    p_m_addedCrossIslandPairs = &m_simulation->m_addedCrossIslandPairs;
    if ( m_simulation->m_addedCrossIslandPairs.m_size == (m_simulation->m_addedCrossIslandPairs.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&m_simulation->m_addedCrossIslandPairs.m_data,
        16);
    p_m_a = &p_m_addedCrossIslandPairs->m_data[p_m_addedCrossIslandPairs->m_size].m_a;
    if ( p_m_a )
    {
      *p_m_a = pair->m_a;
      p_m_a[1] = pair->m_b;
    }
    ++p_m_addedCrossIslandPairs->m_size;
  }
}

// File Line: 327
// RVA: 0xD74CB0
void __fastcall hkpMultiThreadedSimulation::MtEntityEntityBroadPhaseListener::removeCollisionPair(
        hkpMultiThreadedSimulation::MtEntityEntityBroadPhaseListener *this,
        hkpTypedBroadPhaseHandlePair *pair)
{
  hkpMultiThreadedSimulation *m_simulation; // rbx
  hkpLinkedCollidable *v4; // r9
  __int64 m_ownerOffset; // r8
  hkpLinkedCollidable *v6; // rdx
  __int64 v7; // rax
  hkArray<hkpTypedBroadPhaseHandlePair,hkContainerHeapAllocator> *p_m_removedCrossIslandPairs; // rbx
  hkpBroadPhaseHandle **p_m_a; // rcx
  hkpAgentNnEntry *Agent; // rax

  m_simulation = this->m_simulation;
  v4 = (hkpLinkedCollidable *)((char *)pair->m_a + SBYTE1(pair->m_a[1].m_id));
  m_ownerOffset = v4->m_ownerOffset;
  v6 = (hkpLinkedCollidable *)((char *)pair->m_b + SBYTE1(pair->m_b[1].m_id));
  v7 = v6->m_ownerOffset;
  if ( !m_simulation->m_crossIslandPairsCollectingActive.m_bool
    || *((_BYTE *)&v4[2].m_boundingVolumeData.m_childShapeKeys + m_ownerOffset) == 5
    || *((_BYTE *)&v6[2].m_boundingVolumeData.m_childShapeKeys + v7) == 5
    || *(_QWORD *)(&v4[2].m_broadPhaseHandle.m_type + m_ownerOffset) == *(_QWORD *)(&v6[2].m_broadPhaseHandle.m_type + v7) )
  {
    Agent = hkAgentNnMachine_FindAgent(v4, v6);
    if ( Agent )
      hkpWorldAgentUtil::removeAgent(Agent);
  }
  else
  {
    p_m_removedCrossIslandPairs = &m_simulation->m_removedCrossIslandPairs;
    if ( p_m_removedCrossIslandPairs->m_size == (p_m_removedCrossIslandPairs->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&p_m_removedCrossIslandPairs->m_data,
        16);
    p_m_a = &p_m_removedCrossIslandPairs->m_data[p_m_removedCrossIslandPairs->m_size].m_a;
    if ( p_m_a )
    {
      *p_m_a = pair->m_a;
      p_m_a[1] = pair->m_b;
    }
    ++p_m_removedCrossIslandPairs->m_size;
  }
}

// File Line: 369
// RVA: 0xD74E90
void __fastcall hkpMultiThreadedSimulation::MtBroadPhaseBorderListener::addCollisionPair(
        hkpMultiThreadedSimulation::MtBroadPhaseBorderListener *this,
        hkpTypedBroadPhaseHandlePair *pair)
{
  hkpBroadPhaseHandle *m_a; // rdx
  char *v4; // rax
  hkpBroadPhaseHandle *m_b; // rcx
  char *v6; // rcx

  m_a = pair->m_a;
  if ( LOBYTE(m_a[1].m_id) == 3 )
  {
    if ( LOBYTE(pair->m_b[1].m_id) == 3 )
      return;
    v4 = (char *)m_a + SBYTE1(m_a[1].m_id);
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)&v4[v4[32]] + 64i64))(
      &v4[v4[32]],
      (char *)pair->m_b + SBYTE1(pair->m_b[1].m_id));
  }
  m_b = pair->m_b;
  if ( LOBYTE(m_b[1].m_id) == 3 )
  {
    v6 = (char *)m_b + SBYTE1(m_b[1].m_id) + *((char *)&m_b[8].m_id + SBYTE1(m_b[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v6 + 64i64))(v6, (char *)pair->m_a + SBYTE1(pair->m_a[1].m_id));
  }
}

// File Line: 399
// RVA: 0xD74F20
void __fastcall hkpMultiThreadedSimulation::MtBroadPhaseBorderListener::removeCollisionPair(
        hkpMultiThreadedSimulation::MtBroadPhaseBorderListener *this,
        hkpTypedBroadPhaseHandlePair *pair)
{
  hkpBroadPhaseHandle *m_a; // rdx
  char *v4; // rax
  hkpBroadPhaseHandle *m_b; // rcx
  char *v6; // rcx

  m_a = pair->m_a;
  if ( LOBYTE(m_a[1].m_id) == 3 )
  {
    if ( LOBYTE(pair->m_b[1].m_id) == 3 )
      return;
    v4 = (char *)m_a + SBYTE1(m_a[1].m_id);
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)&v4[v4[32]] + 80i64))(
      &v4[v4[32]],
      (char *)pair->m_b + SBYTE1(pair->m_b[1].m_id));
  }
  m_b = pair->m_b;
  if ( LOBYTE(m_b[1].m_id) == 3 )
  {
    v6 = (char *)m_b + SBYTE1(m_b[1].m_id) + *((char *)&m_b[8].m_id + SBYTE1(m_b[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v6 + 80i64))(v6, (char *)pair->m_a + SBYTE1(pair->m_a[1].m_id));
  }
}

// File Line: 442
// RVA: 0xD72100
void __fastcall hkpMultiThreadedSimulation::hkpMultiThreadedSimulation(
        hkpMultiThreadedSimulation *this,
        hkpWorld *world)
{
  hkpContinuousSimulation::hkpContinuousSimulation(this, world);
  this->vfptr = (hkBaseObjectVtbl *)&hkpMultiThreadedSimulation::`vftable;
  this->m_entityEntityBroadPhaseListener.m_simulation = 0i64;
  this->m_entityEntityBroadPhaseListener.vfptr = (hkpBroadPhaseListenerVtbl *)&hkpMultiThreadedSimulation::MtEntityEntityBroadPhaseListener::`vftable;
  this->m_phantomBroadPhaseListener.vfptr = (hkpBroadPhaseListenerVtbl *)&hkpMultiThreadedSimulation::MtPhantomBroadPhaseListener::`vftable;
  this->m_phantomBroadPhaseListener.m_criticalSection = 0i64;
  this->m_broadPhaseBorderListener.m_criticalSection = 0i64;
  this->m_broadPhaseBorderListener.vfptr = (hkpBroadPhaseListenerVtbl *)&hkpMultiThreadedSimulation::MtBroadPhaseBorderListener::`vftable;
  this->m_addedCrossIslandPairs.m_data = 0i64;
  this->m_addedCrossIslandPairs.m_size = 0;
  this->m_addedCrossIslandPairs.m_capacityAndFlags = 0x80000000;
  hkCriticalSection::hkCriticalSection(&this->m_addCrossIslandPairCriticalSection, 0xFA0u);
  this->m_removedCrossIslandPairs.m_data = 0i64;
  this->m_removedCrossIslandPairs.m_size = 0;
  this->m_removedCrossIslandPairs.m_capacityAndFlags = 0x80000000;
  hkCriticalSection::hkCriticalSection(&this->m_removeCrossIslandPairCriticalSection, 0xFA0u);
  hkpMultithreadConfig::hkpMultithreadConfig(&this->m_multithreadConfig);
  hkCriticalSection::hkCriticalSection(&this->m_toiQueueCriticalSection, 0xFA0u);
  hkCriticalSection::hkCriticalSection(&this->m_phantomCriticalSection, 0xFA0u);
  this->m_jobQueueHandleForToiSolve = 0i64;
  this->m_crossIslandPairsCollectingActive.m_bool = 0;
  hkpBroadPhase::enableMultiThreading(this->m_world->m_broadPhase, 0x2710u);
  this->m_phantomBroadPhaseListener.m_criticalSection = &this->m_phantomCriticalSection;
  this->m_entityEntityBroadPhaseListener.m_simulation = this;
  world->m_broadPhaseDispatcher->m_broadPhaseListeners[1][1] = &this->m_entityEntityBroadPhaseListener;
  world->m_broadPhaseDispatcher->m_broadPhaseListeners[2][1] = &this->m_phantomBroadPhaseListener;
  world->m_broadPhaseDispatcher->m_broadPhaseListeners[1][2] = &this->m_phantomBroadPhaseListener;
  world->m_broadPhaseDispatcher->m_broadPhaseListeners[2][2] = &this->m_phantomBroadPhaseListener;
  this->m_broadPhaseBorderListener.m_criticalSection = &this->m_phantomCriticalSection;
  world->m_broadPhaseDispatcher->m_broadPhaseListeners[1][3] = &this->m_broadPhaseBorderListener;
  world->m_broadPhaseDispatcher->m_broadPhaseListeners[3][1] = &this->m_broadPhaseBorderListener;
  world->m_broadPhaseDispatcher->m_broadPhaseListeners[2][3] = &this->m_broadPhaseBorderListener;
  world->m_broadPhaseDispatcher->m_broadPhaseListeners[3][2] = &this->m_broadPhaseBorderListener;
  world->m_broadPhaseDispatcher->m_broadPhaseListeners[3][3] = &this->m_broadPhaseBorderListener;
}

// File Line: 470
// RVA: 0xD722D0
void __fastcall hkpMultiThreadedSimulation::~hkpMultiThreadedSimulation(hkpMultiThreadedSimulation *this)
{
  hkCriticalSection *p_m_phantomCriticalSection; // rcx
  int m_capacityAndFlags; // r8d
  int v4; // r8d

  p_m_phantomCriticalSection = &this->m_phantomCriticalSection;
  p_m_phantomCriticalSection[-10].m_section.OwningThread = &hkpMultiThreadedSimulation::`vftable;
  DeleteCriticalSection(&p_m_phantomCriticalSection->m_section);
  DeleteCriticalSection(&this->m_toiQueueCriticalSection.m_section);
  DeleteCriticalSection(&this->m_removeCrossIslandPairCriticalSection.m_section);
  m_capacityAndFlags = this->m_removedCrossIslandPairs.m_capacityAndFlags;
  this->m_removedCrossIslandPairs.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_removedCrossIslandPairs.m_data,
      16 * m_capacityAndFlags);
  this->m_removedCrossIslandPairs.m_data = 0i64;
  this->m_removedCrossIslandPairs.m_capacityAndFlags = 0x80000000;
  DeleteCriticalSection(&this->m_addCrossIslandPairCriticalSection.m_section);
  v4 = this->m_addedCrossIslandPairs.m_capacityAndFlags;
  this->m_addedCrossIslandPairs.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_addedCrossIslandPairs.m_data,
      16 * v4);
  this->m_addedCrossIslandPairs.m_data = 0i64;
  this->m_addedCrossIslandPairs.m_capacityAndFlags = 0x80000000;
  this->m_broadPhaseBorderListener.vfptr = (hkpBroadPhaseListenerVtbl *)&hkpBroadPhaseListener::`vftable;
  this->m_phantomBroadPhaseListener.vfptr = (hkpBroadPhaseListenerVtbl *)&hkpBroadPhaseListener::`vftable;
  this->m_entityEntityBroadPhaseListener.vfptr = (hkpBroadPhaseListenerVtbl *)&hkpBroadPhaseListener::`vftable;
  hkpContinuousSimulation::~hkpContinuousSimulation(this);
}

// File Line: 474
// RVA: 0xD723E0
void __fastcall hkpMultiThreadedSimulation::create(hkpWorld *world)
{
  _QWORD **Value; // rax
  hkpMultiThreadedSimulation *v3; // rax

  hkOptionalComponent_hkpMultiThreadedSimulation.m_isUsed.m_bool = 1;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpMultiThreadedSimulation *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                       Value[11],
                                       448i64);
  if ( v3 )
    hkpMultiThreadedSimulation::hkpMultiThreadedSimulation(v3, world);
}

// File Line: 489
// RVA: 0xD74FB0
void (__fastcall *hkpMultiThreadedSimulation_registerSelf())(hkpWorld *world)
{
  void (__fastcall *result)(hkpWorld *); // rax

  hkpSimulation::createContinuous = (hkpSimulation *(__fastcall *)(hkpWorld *))hkpContinuousSimulation::create;
  result = hkpMultiThreadedSimulation::create;
  hkpSimulation::createMultithreaded = (hkpSimulation *(__fastcall *)(hkpWorld *))hkpMultiThreadedSimulation::create;
  return result;
}

// File Line: 493
// RVA: 0x15D21C0
void dynamic_initializer_for__hkOptionalComponent_hkpMultiThreadedSimulation__()
{
  hkOptionalComponent::hkOptionalComponent(
    &hkOptionalComponent_hkpMultiThreadedSimulation,
    "hkpMultiThreadedSimulation",
    (void (__fastcall *)())hkpMultiThreadedSimulation_registerSelf);
}

// File Line: 497
// RVA: 0xD74FE0
bool __fastcall pairLessThan(hkpTypedBroadPhaseHandlePair *A, hkpTypedBroadPhaseHandlePair *B)
{
  char *v2; // r9
  char *v3; // r8
  int v4; // r10d
  int v5; // r9d
  char *v7; // r9

  v2 = (char *)A->m_a + SBYTE1(A->m_a[1].m_id);
  v3 = (char *)B->m_a + SBYTE1(B->m_a[1].m_id);
  v4 = *(_DWORD *)&v2[v2[32] + 308];
  v5 = *(_DWORD *)&v3[v3[32] + 308];
  if ( v4 < v5 )
    return 1;
  if ( v4 != v5 )
    return 0;
  v7 = (char *)A->m_b + SBYTE1(A->m_b[1].m_id);
  return *(_DWORD *)&v7[v7[32] + 308] < *(signed int *)((char *)&B->m_b[77].m_id
                                                      + SBYTE1(B->m_b[1].m_id)
                                                      + *((char *)&B->m_b[8].m_id + SBYTE1(B->m_b[1].m_id)));
}

// File Line: 520
// RVA: 0xD75060
void __fastcall sortPairList(hkArray<hkpTypedBroadPhaseHandlePair,hkContainerHeapAllocator> *pairs)
{
  hkpTypedBroadPhaseHandlePair *m_data; // rax
  hkpTypedBroadPhaseHandlePair *v2; // r8
  hkpBroadPhaseHandle *m_b; // r9
  hkpBroadPhaseHandle *m_a; // r10
  int m_size; // r8d

  m_data = pairs->m_data;
  v2 = &pairs->m_data[pairs->m_size];
  if ( pairs->m_data < v2 )
  {
    do
    {
      m_b = m_data->m_b;
      m_a = m_data->m_a;
      if ( *(signed int *)((char *)&m_data->m_a[9].m_id + SBYTE1(m_data->m_a[1].m_id)) > *(signed int *)((char *)&m_b[9].m_id + SBYTE1(m_b[1].m_id)) )
      {
        m_data->m_a = m_b;
        m_data->m_b = m_a;
      }
      ++m_data;
    }
    while ( m_data < v2 );
  }
  m_size = pairs->m_size;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkaiGeometryToEdgeGeometryConverter::TriangleArea,bool (*)(hkaiGeometryToEdgeGeometryConverter::TriangleArea const &,hkaiGeometryToEdgeGeometryConverter::TriangleArea const &)>(
      pairs->m_data,
      0,
      m_size - 1,
      pairLessThan);
}

// File Line: 571
// RVA: 0xD72450
__int64 __fastcall hkpMultiThreadedSimulation::stepBeginSt(
        hkpMultiThreadedSimulation *this,
        hkJobQueue *jobQueue,
        float physicsDeltaTime)
{
  _QWORD *Value; // rax
  unsigned __int64 v6; // rcx
  _QWORD *v7; // r8
  unsigned __int64 v8; // rax
  float m_currentPsiTime; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  hkpWorld *m_world; // rax
  hkMemorySystem *Instance; // rax
  hkWorldMemoryAvailableWatchDog *MemoryWatchDog; // rax
  hkpWorld *v15; // rdi
  bool v16; // zf
  hkpSolverInfo *p_m_solverInfo; // rcx
  float m_numSteps; // xmm1_4
  hkpWorld *v19; // rax
  hkpMtThreadStructure *m_multithreadedSimulationJobData; // r8
  hkpProcessCollisionInput *m_collisionInput; // rcx
  hkpWorld *v22; // rdx
  hkpViolatedConstraintArray *m_violatedConstraintArray; // rcx
  hkpWorld *v24; // rax
  int m_size; // edi
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  _QWORD *v29; // rcx
  hkpWorld *v30; // rax
  hkpWorld *v31; // rcx
  char v32; // al
  hkpSolverInfo *v33; // rcx
  hkpWorld *v34; // rcx
  _QWORD *v35; // r8
  _QWORD *v36; // rcx
  unsigned __int64 v37; // rax
  _QWORD *v38; // rcx
  hkStepInfo v40; // [rsp+20h] [rbp-29h] BYREF
  hkWorldMemoryAvailableWatchDog::MemUsageInfo infoOut; // [rsp+30h] [rbp-19h] BYREF
  hkJob job; // [rsp+40h] [rbp-9h] BYREF
  __int16 v43; // [rsp+50h] [rbp+7h]
  __int64 v44; // [rsp+58h] [rbp+Fh]
  __int64 v45; // [rsp+60h] [rbp+17h]
  hkpMtThreadStructure *v46; // [rsp+68h] [rbp+1Fh]
  int v47; // [rsp+70h] [rbp+27h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = Value[1];
  v7 = Value;
  if ( v6 < Value[3] )
  {
    *(_QWORD *)v6 = "LtPhysics 2012";
    *(_QWORD *)(v6 + 16) = "StInit";
    v8 = __rdtsc();
    *(_DWORD *)(v6 + 8) = v8;
    v7[1] = v6 + 24;
  }
  this->m_crossIslandPairsCollectingActive.m_bool = 1;
  ++this->m_world->m_criticalOperationsLockCount;
  m_currentPsiTime = this->m_currentPsiTime;
  this->m_physicsDeltaTime = physicsDeltaTime;
  v40.m_startTime.m_storage = m_currentPsiTime;
  v40.m_endTime.m_storage = m_currentPsiTime + physicsDeltaTime;
  v10 = (float)(m_currentPsiTime + physicsDeltaTime) - m_currentPsiTime;
  v11 = 0.0;
  v40.m_deltaTime.m_storage = v10;
  if ( v10 != 0.0 )
    v11 = 1.0 / v10;
  m_world = this->m_world;
  v40.m_invDeltaTime.m_storage = v11;
  m_world->m_dynamicsStepInfo.m_stepInfo = v40;
  this->m_world->m_collisionInput->m_stepInfo = v40;
  ((void (__fastcall *)(hkpWorldMaintenanceMgr *, hkpWorld *, hkStepInfo *))this->m_world->m_maintenanceMgr->vfptr[2].__first_virtual_table_function__)(
    this->m_world->m_maintenanceMgr,
    this->m_world,
    &v40);
  hkpWorld::calcRequiredSolverBufferSize(this->m_world, &infoOut);
  Instance = hkMemorySystem::getInstance();
  if ( Instance->vfptr->solverCanAllocSingleBlock(Instance, infoOut.m_maxRuntimeBlockSize) )
    goto LABEL_15;
  MemoryWatchDog = hkpWorld::getMemoryWatchDog(this->m_world);
  v15 = this->m_world;
  if ( MemoryWatchDog )
  {
    v16 = v15->m_criticalOperationsLockCount-- == 1;
    if ( v16 && !v15->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v15->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v15);
      if ( v15->m_pendingOperationQueueCount == 1 && v15->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v15);
    }
    hkpWorldMemoryUtil::checkMemoryForIntegration(this->m_world);
    ++this->m_world->m_criticalOperationsLockCount;
LABEL_15:
    this->m_world->m_dynamicsStepInfo.m_stepInfo = v40;
    p_m_solverInfo = &this->m_world->m_dynamicsStepInfo.m_solverInfo;
    m_numSteps = (float)this->m_world->m_dynamicsStepInfo.m_solverInfo.m_numSteps;
    p_m_solverInfo->m_deltaTime = v40.m_deltaTime.m_storage
                                * this->m_world->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
    p_m_solverInfo->m_invDeltaTime = m_numSteps * v40.m_invDeltaTime.m_storage;
    p_m_solverInfo->m_globalAccelerationPerSubStep.m_quad = _mm_mul_ps(
                                                              _mm_shuffle_ps(
                                                                (__m128)LODWORD(p_m_solverInfo->m_deltaTime),
                                                                (__m128)LODWORD(p_m_solverInfo->m_deltaTime),
                                                                0),
                                                              this->m_world->m_gravity.m_quad);
    p_m_solverInfo->m_globalAccelerationPerStep.m_quad = _mm_mul_ps(
                                                           _mm_shuffle_ps(
                                                             (__m128)LODWORD(v40.m_deltaTime.m_storage),
                                                             (__m128)LODWORD(v40.m_deltaTime.m_storage),
                                                             0),
                                                           this->m_world->m_gravity.m_quad);
    this->m_world->m_violatedConstraintArray->m_nextFreeElement = 0;
    v19 = this->m_world;
    m_multithreadedSimulationJobData = v19->m_multithreadedSimulationJobData;
    m_multithreadedSimulationJobData->m_dynamicsStepInfo.m_storage = &v19->m_dynamicsStepInfo;
    m_collisionInput = this->m_world->m_collisionInput;
    m_multithreadedSimulationJobData->m_collisionInput.m_dispatcher.m_storage = m_collisionInput->m_dispatcher.m_storage;
    m_multithreadedSimulationJobData->m_collisionInput.m_weldClosestPoints.m_storage = m_collisionInput->m_weldClosestPoints.m_storage;
    m_multithreadedSimulationJobData->m_collisionInput.m_forceAcceptContactPoints.m_storage = m_collisionInput->m_forceAcceptContactPoints.m_storage;
    m_multithreadedSimulationJobData->m_collisionInput.m_tolerance.m_storage = m_collisionInput->m_tolerance.m_storage;
    m_multithreadedSimulationJobData->m_collisionInput.m_filter.m_storage = m_collisionInput->m_filter.m_storage;
    m_multithreadedSimulationJobData->m_collisionInput.m_convexListFilter.m_storage = m_collisionInput->m_convexListFilter.m_storage;
    m_multithreadedSimulationJobData->m_collisionInput.m_createPredictiveAgents.m_storage = m_collisionInput->m_createPredictiveAgents.m_storage;
    m_multithreadedSimulationJobData->m_collisionInput.m_aabb32Info.m_bitOffsetLow = m_collisionInput->m_aabb32Info.m_bitOffsetLow;
    m_multithreadedSimulationJobData->m_collisionInput.m_aabb32Info.m_bitOffsetHigh = m_collisionInput->m_aabb32Info.m_bitOffsetHigh;
    m_multithreadedSimulationJobData->m_collisionInput.m_aabb32Info.m_bitScale = m_collisionInput->m_aabb32Info.m_bitScale;
    m_multithreadedSimulationJobData->m_collisionInput.m_stepInfo = m_collisionInput->m_stepInfo;
    m_multithreadedSimulationJobData->m_collisionInput.m_collisionQualityInfo.m_storage = m_collisionInput->m_collisionQualityInfo.m_storage;
    m_multithreadedSimulationJobData->m_collisionInput.m_dynamicsInfo = m_collisionInput->m_dynamicsInfo;
    m_multithreadedSimulationJobData->m_collisionInput.m_enableDeprecatedWelding.m_bool = m_collisionInput->m_enableDeprecatedWelding.m_bool;
    m_multithreadedSimulationJobData->m_collisionInput.m_allowToSkipConfirmedCallbacks.m_bool = m_collisionInput->m_allowToSkipConfirmedCallbacks.m_bool;
    m_multithreadedSimulationJobData->m_collisionInput.m_config = m_collisionInput->m_config;
    v22 = this->m_world;
    m_violatedConstraintArray = v22->m_violatedConstraintArray;
    m_multithreadedSimulationJobData->m_constraintQueryIn.m_subStepDeltaTime.m_storage = v22->m_dynamicsStepInfo.m_solverInfo.m_deltaTime;
    m_multithreadedSimulationJobData->m_constraintQueryIn.m_microStepDeltaTime.m_storage = v22->m_dynamicsStepInfo.m_solverInfo.m_invNumMicroSteps
                                                                                         * v22->m_dynamicsStepInfo.m_solverInfo.m_deltaTime;
    m_multithreadedSimulationJobData->m_constraintQueryIn.m_subStepInvDeltaTime.m_storage = v22->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
    m_multithreadedSimulationJobData->m_constraintQueryIn.m_invNumSteps.m_storage = v22->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
    m_multithreadedSimulationJobData->m_constraintQueryIn.m_invNumStepsTimesMicroSteps.m_storage = v22->m_dynamicsStepInfo.m_solverInfo.m_invNumMicroSteps
                                                                                                 * v22->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
    m_multithreadedSimulationJobData->m_constraintQueryIn.m_tau.m_storage = v22->m_dynamicsStepInfo.m_solverInfo.m_tau;
    *(float *)&v19 = v22->m_dynamicsStepInfo.m_solverInfo.m_damping;
    m_multithreadedSimulationJobData->m_constraintQueryIn.m_violatedConstraints.m_storage = m_violatedConstraintArray;
    LODWORD(m_multithreadedSimulationJobData->m_constraintQueryIn.m_damping.m_storage) = (_DWORD)v19;
    m_multithreadedSimulationJobData->m_constraintQueryIn.m_rhsFactor.m_storage = v22->m_dynamicsStepInfo.m_solverInfo.m_tauDivDamp
                                                                                * v22->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
    m_multithreadedSimulationJobData->m_constraintQueryIn.m_virtMassFactor.m_storage = v22->m_dynamicsStepInfo.m_solverInfo.m_damping;
    m_multithreadedSimulationJobData->m_constraintQueryIn.m_frictionRhsFactor.m_storage = v22->m_dynamicsStepInfo.m_solverInfo.m_frictionTauDivDamp
                                                                                        * v22->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
    m_multithreadedSimulationJobData->m_constraintQueryIn.m_frameDeltaTime.m_storage = v22->m_dynamicsStepInfo.m_stepInfo.m_deltaTime.m_storage;
    m_multithreadedSimulationJobData->m_constraintQueryIn.m_frameInvDeltaTime.m_storage = v22->m_dynamicsStepInfo.m_stepInfo.m_invDeltaTime.m_storage;
    m_multithreadedSimulationJobData->m_constraintQueryIn.m_maxConstraintViolationSqrd.m_real = _mm_shuffle_ps(
                                                                                                  (__m128)LODWORD(v22->m_dynamicsStepInfo.m_solverInfo.m_maxConstraintViolationSqrd),
                                                                                                  (__m128)LODWORD(v22->m_dynamicsStepInfo.m_solverInfo.m_maxConstraintViolationSqrd),
                                                                                                  0);
    m_multithreadedSimulationJobData->m_simulation.m_storage = this;
    m_multithreadedSimulationJobData->m_tolerance.m_storage = this->m_world->m_collisionInput->m_tolerance.m_storage;
    m_multithreadedSimulationJobData->m_weldingTable.m_storage = hkpWeldingUtility::m_sinCosTable;
    m_multithreadedSimulationJobData->m_world = this->m_world;
    v24 = this->m_world;
    m_size = v24->m_activeSimulationIslands.m_size;
    if ( m_size > 0 )
    {
      if ( v24->m_processActionsInSingleThread.m_bool )
      {
        v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v27 = (_QWORD *)v26[1];
        if ( (unsigned __int64)v27 < v26[3] )
        {
          *v27 = "StActions";
          v28 = __rdtsc();
          v29 = v27 + 2;
          *((_DWORD *)v29 - 2) = v28;
          v26[1] = v29;
        }
        --this->m_world->m_criticalOperationsLockCountForPhantoms;
        hkpSimulation::applyActions(this);
        ++this->m_world->m_criticalOperationsLockCountForPhantoms;
      }
      *(_WORD *)&job.m_jobSubType = 0;
      job.m_jobSpuType.m_storage = 2;
      job.m_size = 64;
      v44 = 0i64;
      job.m_threadAffinity = -1;
      v30 = this->m_world;
      v45 = 0i64;
      v43 = 0;
      v47 = m_size;
      v46 = v30->m_multithreadedSimulationJobData;
      hkJobQueue::setQueueCapacityForJobType(jobQueue, HK_JOB_TYPE_DYNAMICS, m_size);
      hkJobQueue::setQueueCapacityForJobType(jobQueue, HK_JOB_TYPE_COLLIDE, m_size);
      hkJobQueue::addJob(jobQueue, &job, JOB_LOW_PRIORITY);
    }
    v31 = this->m_world;
    v32 = ++v31->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter;
    v33 = &v31->m_dynamicsStepInfo.m_solverInfo;
    if ( ((v32 - 4) & 7) == 0 )
      v33->m_deactivationNumInactiveFramesSelectFlag[0] ^= 1u;
    if ( (v33->m_deactivationIntegrateCounter & 7) == 0 )
      v33->m_deactivationNumInactiveFramesSelectFlag[0] ^= 2u;
    if ( (v33->m_deactivationIntegrateCounter & 0xF) == 0 )
    {
      v33->m_deactivationNumInactiveFramesSelectFlag[1] = 1 - v33->m_deactivationNumInactiveFramesSelectFlag[1];
      v33->m_deactivationIntegrateCounter = 0;
    }
    v34 = this->m_world;
    this->m_numActiveIslandsAtBeginningOfStep = v34->m_activeSimulationIslands.m_size;
    this->m_numInactiveIslandsAtBeginningOfStep = v34->m_inactiveSimulationIslands.m_size;
    hkpWorld::checkDeterminism(v34);
    v35 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v36 = (_QWORD *)v35[1];
    if ( (unsigned __int64)v36 < v35[3] )
    {
      *v36 = "lt";
      v37 = __rdtsc();
      v38 = v36 + 2;
      *((_DWORD *)v38 - 2) = v37;
      v35[1] = v38;
    }
    return 0i64;
  }
  if ( v15->m_assertOnRunningOutOfSolverMemory.m_bool )
    __debugbreak();
  this->m_previousStepResult = 1;
  v16 = v15->m_criticalOperationsLockCount-- == 1;
  if ( v16 && !v15->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v15->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v15);
    if ( v15->m_pendingOperationQueueCount == 1 && v15->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(v15);
  }
  return 1i64;
}

// File Line: 707
// RVA: 0xD750E0
hkBool *__fastcall less_hkSimulationIslandPtr(hkBool *result, hkpSimulationIsland *a, hkpSimulationIsland *b)
{
  result->m_bool = (*a->m_entities.m_data)->m_uid < (*b->m_entities.m_data)->m_uid;
  return result;
}

// File Line: 712
// RVA: 0xD72A40
__int64 __fastcall hkpMultiThreadedSimulation::finishMtStep(
        hkpMultiThreadedSimulation *this,
        hkJobQueue *jobQueue,
        hkJobThreadPool *threadPool)
{
  hkJobThreadPool *v4; // r14
  hkJobQueue *v5; // rsi
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  unsigned int v11; // ebp
  hkpWorld *m_world; // rax
  __int64 m_numActiveIslandsAtBeginningOfStep; // rcx
  int v14; // r8d
  int i; // r8d
  float v16; // xmm7_4
  _QWORD *v17; // r8
  unsigned __int64 v18; // rcx
  unsigned __int64 v19; // rax
  hkArray<hkpTypedBroadPhaseHandlePair,hkContainerHeapAllocator> *p_m_removedCrossIslandPairs; // r15
  hkArray<hkpTypedBroadPhaseHandlePair,hkContainerHeapAllocator> *p_m_addedCrossIslandPairs; // r13
  _QWORD *v22; // r8
  _QWORD *v23; // rcx
  unsigned __int64 v24; // rax
  _QWORD *v25; // rcx
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  _QWORD *v29; // rcx
  int v30; // r14d
  __int64 v31; // r12
  hkpLinkedCollidable *v32; // rdi
  __int64 m_ownerOffset; // r15
  hkpConstraintOwner *v34; // rcx
  hkpLinkedCollidable *v35; // rsi
  hkpSimulationIsland *v36; // r8
  hkpWorld *v37; // rax
  hkpProcessCollisionInput *m_collisionInput; // r8
  char v39; // al
  hkpAgentNnEntry *v40; // rax
  hkpAgentNnEntry *v41; // rdi
  hkpLinkedCollidable *v42; // r15
  hkpLinkedCollidable *v43; // r13
  hkpProcessCollisionInput *v44; // rsi
  __int64 v45; // rdx
  _QWORD *v46; // rax
  _QWORD *v47; // rcx
  _QWORD *v48; // r8
  unsigned __int64 v49; // rax
  _QWORD *v50; // rcx
  int v51; // esi
  __int64 v52; // rdi
  hkpAgentNnEntry *Agent; // rax
  _QWORD *v54; // rax
  _QWORD *v55; // rcx
  _QWORD *v56; // r8
  unsigned __int64 v57; // rax
  _QWORD *v58; // rcx
  hkpWorld *v59; // rdi
  bool v60; // zf
  hkpWorld *v61; // rcx
  _QWORD *v62; // r8
  _QWORD *v63; // rcx
  unsigned __int64 v64; // rax
  _QWORD *v65; // rcx
  _QWORD *v66; // r8
  _QWORD *v67; // rcx
  unsigned __int64 v68; // rax
  _QWORD *v69; // rcx
  float v70; // xmm1_4
  hkpWorld *v71; // rcx
  _QWORD *v72; // r8
  _QWORD *v73; // rcx
  unsigned __int64 v74; // rax
  _QWORD *v75; // rcx
  _QWORD *v76; // r8
  _QWORD *v77; // rcx
  unsigned __int64 v78; // rax
  _QWORD *v79; // rcx
  hkpWorld *v80; // rcx
  _QWORD *v81; // r8
  _QWORD *v82; // rcx
  unsigned __int64 v83; // rax
  _QWORD *v84; // rcx
  _QWORD *v85; // r8
  _QWORD *v86; // rcx
  unsigned __int64 v87; // rax
  _QWORD *v88; // rcx
  hkStepInfo info; // [rsp+30h] [rbp-3108h] BYREF
  hkpProcessCollisionOutput output; // [rsp+40h] [rbp-30F8h] BYREF
  int flags; // [rsp+3140h] [rbp+8h]

  v4 = threadPool;
  v5 = jobQueue;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtPhysics 2012";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  hkpWorld::lock(this->m_world);
  v11 = 0;
  flags = 0;
  if ( v5 && v4 )
  {
    flags = hkJobQueue::getMasterThreadFinishingFlags(v5);
    hkJobQueue::setWaitPolicy(v5, WAIT_INDEFINITELY);
    hkJobQueue::setMasterThreadFinishingFlags(v5, 262146);
    ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, __int64))v4->vfptr[5].__first_virtual_table_function__)(
      v4,
      v5,
      20i64);
  }
  m_world = this->m_world;
  m_numActiveIslandsAtBeginningOfStep = this->m_numActiveIslandsAtBeginningOfStep;
  v14 = m_world->m_activeSimulationIslands.m_size - m_numActiveIslandsAtBeginningOfStep;
  if ( v14 > 1 )
    hkAlgorithm::quickSortRecursive<hkFreeList::Element *,hkBool (*)(hkFreeList::Element const *,hkFreeList::Element const *)>(
      (hkpRigidBody **)&m_world->m_activeSimulationIslands.m_data[m_numActiveIslandsAtBeginningOfStep],
      0,
      v14 - 1,
      (hkBool *(__fastcall *)(hkBool *, hkpRigidBody *, hkpRigidBody *))less_hkSimulationIslandPtr);
  for ( i = this->m_numActiveIslandsAtBeginningOfStep; i < this->m_world->m_activeSimulationIslands.m_size; ++i )
    this->m_world->m_activeSimulationIslands.m_data[i]->m_storageIndex = i;
  hkpWorld::checkDeterminism(this->m_world);
  v16 = 0.0;
  if ( this->m_addedCrossIslandPairs.m_size + this->m_removedCrossIslandPairs.m_size )
  {
    v17 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v18 = v17[1];
    if ( v18 < v17[3] )
    {
      *(_QWORD *)v18 = "LtInterIsland";
      *(_QWORD *)(v18 + 16) = "Stduplicates";
      v19 = __rdtsc();
      *(_DWORD *)(v18 + 8) = v19;
      v17[1] = v18 + 24;
    }
    p_m_removedCrossIslandPairs = &this->m_removedCrossIslandPairs;
    p_m_addedCrossIslandPairs = &this->m_addedCrossIslandPairs;
    hkpTypedBroadPhaseDispatcher::removeDuplicates(
      (hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *)&this->m_addedCrossIslandPairs,
      (hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *)&this->m_removedCrossIslandPairs);
    v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v23 = (_QWORD *)v22[1];
    if ( (unsigned __int64)v23 < v22[3] )
    {
      *v23 = "StsortPairs";
      v24 = __rdtsc();
      v25 = v23 + 2;
      *((_DWORD *)v25 - 2) = v24;
      v22[1] = v25;
    }
    sortPairList(&this->m_addedCrossIslandPairs);
    sortPairList(&this->m_removedCrossIslandPairs);
    v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v27 = (_QWORD *)v26[1];
    if ( (unsigned __int64)v27 < v26[3] )
    {
      *v27 = "StaddAgt";
      v28 = __rdtsc();
      v29 = v27 + 2;
      *((_DWORD *)v29 - 2) = v28;
      v26[1] = v29;
    }
    output.m_toi.m_time.m_storage = 3.40282e38;
    output.m_toi.m_properties.hkpSolverResults = 0i64;
    output.m_constraintOwner.m_storage = 0i64;
    v30 = 0;
    if ( this->m_addedCrossIslandPairs.m_size > 0 )
    {
      v31 = 0i64;
      do
      {
        v32 = (hkpLinkedCollidable *)((char *)p_m_addedCrossIslandPairs->m_data[v31].m_a
                                    + SBYTE1(p_m_addedCrossIslandPairs->m_data[v31].m_a[1].m_id));
        m_ownerOffset = v32->m_ownerOffset;
        v34 = *(hkpConstraintOwner **)(&v32[2].m_broadPhaseHandle.m_type + m_ownerOffset);
        v35 = (hkpLinkedCollidable *)((char *)p_m_addedCrossIslandPairs->m_data[v31].m_b
                                    + SBYTE1(p_m_addedCrossIslandPairs->m_data[v31].m_b[1].m_id));
        v36 = *(hkpSimulationIsland **)(&v35[2].m_broadPhaseHandle.m_type + v35->m_ownerOffset);
        if ( v34 != v36 )
        {
          hkpWorldOperationUtil::internalMergeTwoIslands(
            this->m_world,
            *(hkpSimulationIsland **)(&v32[2].m_broadPhaseHandle.m_type + m_ownerOffset),
            v36);
          v34 = *(hkpConstraintOwner **)(&v32[2].m_broadPhaseHandle.m_type + m_ownerOffset);
        }
        v37 = this->m_world;
        output.m_constraintOwner.m_storage = v34;
        m_collisionInput = v37->m_collisionInput;
        v39 = m_collisionInput->m_dispatcher.m_storage->m_collisionQualityTable[v32->m_broadPhaseHandle.m_objectQualityType][v35->m_broadPhaseHandle.m_objectQualityType];
        if ( v39 )
        {
          m_collisionInput->m_createPredictiveAgents.m_storage = m_collisionInput->m_dispatcher.m_storage->m_collisionQualityInfo[(__int64)v39].m_useContinuousPhysics.m_storage;
          v40 = hkpWorldAgentUtil::addAgent(v32, v35, m_collisionInput);
          v41 = v40;
          if ( v40 )
          {
            v42 = v40->m_collidable[0];
            v43 = v40->m_collidable[1];
            v44 = this->m_world->m_collisionInput;
            v45 = (__int64)&v44->m_dispatcher.m_storage->m_collisionQualityInfo[v40->m_collisionQualityIndex];
            v44->m_collisionQualityInfo.m_storage = (hkpCollisionQualityInfo *)v45;
            v44->m_createPredictiveAgents.m_storage = *(_DWORD *)(v45 + 16);
            output.m_toi.m_time.m_storage = 3.40282e38;
            output.m_firstFreeContactPoint.m_storage = output.m_contactPoints;
            output.m_potentialContacts.m_storage = 0i64;
            hkAgentNnMachine_ProcessAgent(v40, v44, &output, v40->m_contactMgr);
            if ( output.m_firstFreeContactPoint.m_storage != output.m_contactPoints )
              ((void (__fastcall *)(hkpContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))v41->m_contactMgr->vfptr[3].__vecDelDtor)(
                v41->m_contactMgr,
                v42,
                v43,
                v44,
                &output);
            if ( output.m_toi.m_time.m_storage != 3.40282e38 )
              hkpMultiThreadedSimulation::addToiEventWithCriticalSectionLock(
                this,
                &output,
                v41,
                &this->m_toiQueueCriticalSection);
            p_m_addedCrossIslandPairs = &this->m_addedCrossIslandPairs;
          }
        }
        if ( hkOutOfMemoryState == MEMORY_STATE_OUT_OF_MEMORY )
          break;
        ++v30;
        ++v31;
      }
      while ( v30 < this->m_addedCrossIslandPairs.m_size );
      p_m_removedCrossIslandPairs = &this->m_removedCrossIslandPairs;
    }
    p_m_addedCrossIslandPairs->m_size = 0;
    v46 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v47 = (_QWORD *)v46[1];
    v48 = v46;
    if ( (unsigned __int64)v47 < v46[3] )
    {
      *v47 = "StremoveAgt";
      v49 = __rdtsc();
      v50 = v47 + 2;
      *((_DWORD *)v50 - 2) = v49;
      v48[1] = v50;
    }
    v51 = 0;
    if ( this->m_removedCrossIslandPairs.m_size > 0 )
    {
      v52 = 0i64;
      do
      {
        Agent = hkAgentNnMachine_FindAgent(
                  (hkpLinkedCollidable *)((char *)p_m_removedCrossIslandPairs->m_data[v52].m_a
                                        + SBYTE1(p_m_removedCrossIslandPairs->m_data[v52].m_a[1].m_id)),
                  (hkpLinkedCollidable *)((char *)p_m_removedCrossIslandPairs->m_data[v52].m_b
                                        + SBYTE1(p_m_removedCrossIslandPairs->m_data[v52].m_b[1].m_id)));
        if ( Agent )
          hkpWorldAgentUtil::removeAgentAndItsToiEvents(Agent);
        ++v51;
        ++v52;
      }
      while ( v51 < this->m_removedCrossIslandPairs.m_size );
    }
    p_m_removedCrossIslandPairs->m_size = 0;
    v54 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v5 = jobQueue;
    v55 = (_QWORD *)v54[1];
    v4 = threadPool;
    v56 = v54;
    if ( (unsigned __int64)v55 < v54[3] )
    {
      *v55 = "lt";
      v57 = __rdtsc();
      v58 = v55 + 2;
      *((_DWORD *)v58 - 2) = v57;
      v56[1] = v58;
    }
  }
  this->m_crossIslandPairsCollectingActive.m_bool = 0;
  hkpWorld::checkConstraintsViolated(this->m_world);
  v59 = this->m_world;
  this->m_currentPsiTime = this->m_physicsDeltaTime + this->m_currentPsiTime;
  v60 = v59->m_criticalOperationsLockCount-- == 1;
  if ( v60 && !v59->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v59->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v59);
    if ( v59->m_pendingOperationQueueCount == 1 && v59->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(v59);
  }
  if ( hkOutOfMemoryState == MEMORY_STATE_OUT_OF_MEMORY )
  {
    v61 = this->m_world;
    v11 = 2;
    this->m_currentPsiTime = this->m_currentPsiTime - this->m_physicsDeltaTime;
    hkpWorld::unlock(v61);
    v62 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v63 = (_QWORD *)v62[1];
    if ( (unsigned __int64)v63 < v62[3] )
    {
      *v63 = "Et";
      v64 = __rdtsc();
      v65 = v63 + 2;
      *((_DWORD *)v65 - 2) = v64;
      v62[1] = v65;
    }
  }
  else
  {
    if ( this->m_world->m_worldPostCollideListeners.m_size )
    {
      v66 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v67 = (_QWORD *)v66[1];
      if ( (unsigned __int64)v67 < v66[3] )
      {
        *v67 = "TtPostCollideCB";
        v68 = __rdtsc();
        v69 = v67 + 2;
        *((_DWORD *)v69 - 2) = v68;
        v66[1] = v69;
      }
      info.m_endTime.m_storage = this->m_currentPsiTime;
      v70 = info.m_endTime.m_storage - (float)(info.m_endTime.m_storage - this->m_physicsDeltaTime);
      info.m_startTime.m_storage = info.m_endTime.m_storage - this->m_physicsDeltaTime;
      info.m_deltaTime.m_storage = v70;
      if ( v70 != 0.0 )
        v16 = 1.0 / v70;
      v71 = this->m_world;
      info.m_invDeltaTime.m_storage = v16;
      hkpWorldCallbackUtil::firePostCollideCallback(v71, &info);
      v72 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v73 = (_QWORD *)v72[1];
      if ( (unsigned __int64)v73 < v72[3] )
      {
        *v73 = "Et";
        v74 = __rdtsc();
        v75 = v73 + 2;
        *((_DWORD *)v75 - 2) = v74;
        v72[1] = v75;
      }
    }
    hkpWorld::checkDeterminism(this->m_world);
    v76 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v77 = (_QWORD *)v76[1];
    if ( (unsigned __int64)v77 < v76[3] )
    {
      *v77 = "Et";
      v78 = __rdtsc();
      v79 = v77 + 2;
      *((_DWORD *)v79 - 2) = v78;
      v76[1] = v79;
    }
    v80 = this->m_world;
    if ( v80->m_processToisMultithreaded.m_bool )
      this->m_jobQueueHandleForToiSolve = v5;
    hkpWorld::unlock(v80);
    ((void (__fastcall *)(hkpMultiThreadedSimulation *))this->vfptr[3].__vecDelDtor)(this);
    this->m_jobQueueHandleForToiSolve = 0i64;
    if ( hkOutOfMemoryState == MEMORY_STATE_OUT_OF_MEMORY )
      v11 = 3;
  }
  if ( v4 )
  {
    v81 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v82 = (_QWORD *)v81[1];
    if ( (unsigned __int64)v82 < v81[3] )
    {
      *v82 = "TtWaitForWorkerThreads";
      v83 = __rdtsc();
      v84 = v82 + 2;
      *((_DWORD *)v84 - 2) = v83;
      v81[1] = v84;
    }
    hkJobQueue::setWaitPolicy(v5, WAIT_UNTIL_ALL_WORK_COMPLETE);
    hkJobQueue::setMasterThreadFinishingFlags(v5, flags);
    ((void (__fastcall *)(hkJobThreadPool *))v4->vfptr[2].__vecDelDtor)(v4);
    v85 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v86 = (_QWORD *)v85[1];
    if ( (unsigned __int64)v86 < v85[3] )
    {
      *v86 = "Et";
      v87 = __rdtsc();
      v88 = v86 + 2;
      *((_DWORD *)v88 - 2) = v87;
      v85[1] = v88;
    }
  }
  this->m_previousStepResult = v11;
  if ( v11 && hkpWorld::getMemoryWatchDog(this->m_world) )
    hkpWorldMemoryUtil::tryToRecoverFromMemoryErrors(this->m_world);
  return this->m_previousStepResult;
}

// File Line: 1013
// RVA: 0xD73230
void __fastcall hkpMultiThreadedSimulation::getMultithreadConfig(
        hkpMultiThreadedSimulation *this,
        hkpMultithreadConfig *config)
{
  config->m_maxNumConstraintsSolvedSingleThreaded = (unsigned int)this->m_multithreadConfig;
}

// File Line: 1018
// RVA: 0xD73240
void __fastcall hkpMultiThreadedSimulation::setMultithreadConfig(
        hkpMultiThreadedSimulation *this,
        hkpMultithreadConfig *config,
        hkJobQueue *queue)
{
  this->m_multithreadConfig = (hkpMultithreadConfig)config->m_maxNumConstraintsSolvedSingleThreaded;
}

// File Line: 1024
// RVA: 0xD72440
void __fastcall hkpMultiThreadedSimulation::assertThereIsNoCollisionInformationForAgent(
        hkpMultiThreadedSimulation *this,
        hkpAgentNnEntry *agent)
{
  ;
}

// File Line: 1033
// RVA: 0xD72430
void __fastcall hkpMultiThreadedSimulation::assertThereIsNoCollisionInformationForEntities(
        hkpMultiThreadedSimulation *this,
        hkpEntity **entities,
        int numEntities,
        hkpWorld *world)
{
  ;
}

// File Line: 1044
// RVA: 0xD73DA0
void __fastcall hkpMultiThreadedSimulation::addToiEventWithCriticalSectionLock(
        hkpMultiThreadedSimulation *this,
        hkpProcessCollisionOutput *processOutput,
        hkpAgentNnEntry *entry,
        hkCriticalSection *criticalSection)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  __int64 m_size; // rcx
  hkpToiEvent *v14; // rbx
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  _QWORD *v18; // rcx
  hkErrStream v19; // [rsp+20h] [rbp-228h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtAgentJob.addToi";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  EnterCriticalSection(&criticalSection->m_section);
  if ( this->m_toiEvents.m_size < (this->m_toiEvents.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    m_size = this->m_toiEvents.m_size;
    this->m_toiEvents.m_size = m_size + 1;
    v14 = &this->m_toiEvents.m_data[m_size];
    LeaveCriticalSection(&criticalSection->m_section);
    v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v16 = (_QWORD *)v15[1];
    if ( (unsigned __int64)v16 < v15[3] )
    {
      *v16 = "Et";
      v17 = __rdtsc();
      v18 = v16 + 2;
      *((_DWORD *)v18 - 2) = v17;
      v15[1] = v18;
    }
    v14->m_time = processOutput->m_toi.m_time.m_storage;
    v14->m_useSimpleHandling.m_bool = this->m_world->m_collisionDispatcher->m_collisionQualityInfo[(__int64)entry->m_collisionQualityIndex].m_useSimpleToiHandling.m_bool;
    v14->m_seperatingVelocity = processOutput->m_toi.m_seperatingVelocity.m_storage;
    v14->m_contactPoint.m_position = processOutput->m_toi.m_contactPoint.m_position;
    v14->m_contactPoint.m_separatingNormal = processOutput->m_toi.m_contactPoint.m_separatingNormal;
    v14->m_entities[0] = (hkpEntity *)((char *)entry->m_collidable[0] + entry->m_collidable[0]->m_ownerOffset);
    v14->m_entities[1] = (hkpEntity *)((char *)entry->m_collidable[1] + entry->m_collidable[1]->m_ownerOffset);
    v14->m_properties.hkpSolverResults = processOutput->m_toi.m_properties.hkpSolverResults;
    v14->m_properties.m_userData = processOutput->m_toi.m_properties.m_userData;
    *(_QWORD *)&v14->m_properties.m_friction.m_value = *(_QWORD *)&processOutput->m_toi.m_properties.m_friction.m_value;
    *(_QWORD *)&v14->m_properties.m_internalDataA = *(_QWORD *)&processOutput->m_toi.m_properties.m_internalDataA;
    v14->m_contactMgr = (hkpDynamicsContactMgr *)entry->m_contactMgr;
    v14->m_extendedUserDatas[0] = processOutput->m_toi.m_properties.m_extendedUserDatas[0];
    v14->m_extendedUserDatas[1] = processOutput->m_toi.m_properties.m_extendedUserDatas[1];
    v14->m_extendedUserDatas[2] = processOutput->m_toi.m_properties.m_extendedUserDatas[2];
    v14->m_extendedUserDatas[3] = processOutput->m_toi.m_properties.m_extendedUserDatas[3];
    v14->m_extendedUserDatas[4] = processOutput->m_toi.m_properties.m_extendedUserDatas[4];
    v14->m_extendedUserDatas[5] = processOutput->m_toi.m_properties.m_extendedUserDatas[5];
    v14->m_extendedUserDatas[6] = processOutput->m_toi.m_properties.m_extendedUserDatas[6];
  }
  else
  {
    hkErrStream::hkErrStream(&v19, buf, 512);
    hkOstream::operator<<(
      &v19,
      "TOI event queue full, consider using HK_COLLIDABLE_QUALITY_DEBRIS for some objects or increase hkpWorldCinfo::m_si"
      "zeOfToiEventQueue");
    hkError::messageWarning(0xF0323454, buf, "World\\Simulation\\Multithreaded\\hkpMultithreadedSimulation.cpp", 1051);
    hkOstream::~hkOstream(&v19);
    LeaveCriticalSection(&criticalSection->m_section);
  }
}

// File Line: 1141
// RVA: 0xD73FD0
void __fastcall hkpMultiThreadedSimulation::collideEntitiesOfOneIslandNarrowPhaseContinuous_toiOnly(
        hkpMultiThreadedSimulation *this,
        hkpEntity **entities,
        int numEntities,
        hkpProcessCollisionInput *input,
        hkPointerMap<unsigned int,hkpEntity *,hkContainerHeapAllocator> *entitiesNeedingPsiCollisionDetection)
{
  __int64 v5; // rbx
  hkpEntity **v6; // r14
  hkpMultiThreadedSimulation *v7; // rdi
  hkpSimulationIsland *m_simulationIsland; // rsi
  unsigned int m_size; // r13d
  hkLifoAllocator *Value; // rax
  char *m_cur; // r15
  int v12; // edx
  char *v13; // rcx
  signed int v14; // r12d
  hkLifoAllocator *v15; // rax
  hkpIslandsAgentEntriesInfo *v16; // rcx
  hkpIslandsAgentEntriesInfo *v17; // rdx
  int m_capacityAndFlags; // r8d
  __int64 v19; // rax
  __int64 v20; // r13
  unsigned __int64 v21; // r14
  int v22; // edi
  __int64 v23; // r13
  __int64 v24; // rsi
  hkpLinkedCollidable::CollisionEntry *m_data; // rbx
  hkpSimulationIsland **v26; // rcx
  hkpAgentNnEntry *m_agentEntry; // r8
  __int64 v28; // rcx
  __int64 v29; // rdx
  __int64 v30; // rax
  char *v31; // rdi
  signed __int32 v32; // ebx
  hkLifoAllocator *v33; // rax
  int v34; // r8d
  signed int v35; // ebx
  hkLifoAllocator *v36; // rax
  int v37; // r8d
  hkpIslandsAgentEntriesInfo *array; // [rsp+10h] [rbp-51h] BYREF
  int numEntries; // [rsp+18h] [rbp-49h]
  int v40; // [rsp+1Ch] [rbp-45h]
  hkpIslandsAgentEntriesInfo *info; // [rsp+20h] [rbp-41h]
  hkpContinuousSimulation::CollisionQualityOverride collisionQualityOverride; // [rsp+28h] [rbp-39h]
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> entries; // [rsp+30h] [rbp-31h] BYREF
  unsigned int v44; // [rsp+40h] [rbp-21h]
  unsigned int v45; // [rsp+44h] [rbp-1Dh]
  __int64 v46; // [rsp+48h] [rbp-19h]
  hkpSimulationIsland *v47; // [rsp+50h] [rbp-11h]
  __int64 v48; // [rsp+58h] [rbp-9h]
  hkpIslandsAgentEntriesInfo v49; // [rsp+60h] [rbp-1h] BYREF
  hkpMultiThreadedSimulation *v50; // [rsp+C0h] [rbp+5Fh]
  hkpEntity **v51; // [rsp+C8h] [rbp+67h]
  hkpProcessCollisionInput *retaddr; // [rsp+D8h] [rbp+77h]

  v5 = numEntities;
  v6 = entities;
  v7 = this;
  if ( this->m_jobQueueHandleForToiSolve )
  {
    m_simulationIsland = (*entities)->m_simulationIsland;
    v47 = m_simulationIsland;
    m_size = m_simulationIsland->m_entities.m_size;
    v44 = m_size;
    if ( m_size )
    {
      Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (char *)Value->m_cur;
      v12 = (m_size + 127) & 0xFFFFFF80;
      v13 = &m_cur[v12];
      if ( v12 > Value->m_slabSize || v13 > Value->m_end )
        m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v12);
      else
        Value->m_cur = v13;
    }
    else
    {
      m_cur = 0i64;
    }
    v14 = m_size | 0x80000000;
    v45 = m_size | 0x80000000;
    hkString::memSet(m_cur, 0, m_size);
    collisionQualityOverride = 1000;
    v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v16 = (hkpIslandsAgentEntriesInfo *)v15->m_cur;
    v17 = v16 + 252;
    if ( v15->m_slabSize < 8064 || v17 > v15->m_end )
      v16 = (hkpIslandsAgentEntriesInfo *)hkLifoAllocator::allocateFromNewSlab(v15, 8064);
    else
      v15->m_cur = v17;
    array = v16;
    info = v16;
    m_capacityAndFlags = 0x80000000;
    v40 = -2147482648;
    entries.m_data = 0i64;
    entries.m_size = 0;
    v19 = 0i64;
    entries.m_capacityAndFlags = 0x80000000;
    do
    {
      v49.m_numEntries[v19] = 0;
      v49.m_firstEntryIdx[v19] = 0;
      v49.m_nextEntryIdx[v19++] = 0;
    }
    while ( v19 < 2 );
    v49.m_island = m_simulationIsland;
    v20 = 0i64;
    v46 = 0i64;
    v48 = v5;
    if ( (int)v5 > 0 )
    {
      do
      {
        v21 = (unsigned __int64)v6[v20];
        m_cur[*(unsigned __int16 *)(v21 + 244)] = 1;
        hkpLinkedCollidable::getCollisionEntriesSorted((hkpLinkedCollidable *)(v21 + 32), &entries);
        v22 = 0;
        if ( entries.m_size > 0 )
        {
          v23 = (__int64)v50;
          v24 = 0i64;
          do
          {
            m_data = entries.m_data;
            v26 = (hkpSimulationIsland **)((char *)entries.m_data[v24].m_partner
                                         + entries.m_data[v24].m_partner->m_ownerOffset);
            if ( v26[37] != v47 || !m_cur[*((unsigned __int16 *)v26 + 122)] )
            {
              m_agentEntry = entries.m_data[v24].m_agentEntry;
              v28 = *(_QWORD *)(*(_QWORD *)(v23 + 24) + 200i64);
              v29 = (__int64)m_agentEntry->m_collisionQualityIndex << 6;
              if ( !*(_DWORD *)(v29 + v28 + 10320) || *(_BYTE *)(v29 + v28 + 10324) )
              {
                if ( !hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)this,
                        *(unsigned int *)(v21 + 308),
                        0i64) )
                {
                  hkReferencedObject::addReference((hkReferencedObject *)v21);
                  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)this,
                    &hkContainerHeapAllocator::s_alloc,
                    *(unsigned int *)(v21 + 308),
                    v21);
                }
              }
              else
              {
                v30 = (unsigned __int8)m_agentEntry->m_nnTrackType.m_storage - 1;
                ++v49.m_numEntries[v30];
                if ( numEntries == (v40 & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
                *((_QWORD *)&array->m_island + numEntries++) = m_data[v24].m_agentEntry;
              }
            }
            ++v22;
            ++v24;
          }
          while ( v22 < entries.m_size );
          v20 = v46;
        }
        v6 = v51;
        v46 = ++v20;
      }
      while ( v20 < v48 );
      m_capacityAndFlags = entries.m_capacityAndFlags;
      v7 = v50;
      v14 = v45;
    }
    if ( numEntries )
    {
      hkpMultiThreadedSimulation::processAgentNnEntries(
        v7,
        (hkpAgentNnEntry **)array,
        numEntries,
        retaddr,
        &v49,
        PROCESS_NORMALLY);
      m_capacityAndFlags = entries.m_capacityAndFlags;
    }
    entries.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        entries.m_data,
        16 * m_capacityAndFlags);
    v31 = (char *)info;
    entries.m_data = 0i64;
    entries.m_capacityAndFlags = 0x80000000;
    v32 = (8 * collisionQualityOverride + 127) & 0xFFFFFF80;
    v33 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v34 = (v32 + 15) & 0xFFFFFFF0;
    if ( v32 > v33->m_slabSize || &v31[v34] != v33->m_cur || v33->m_firstNonLifoEnd == v31 )
      hkLifoAllocator::slowBlockFree(v33, v31, v34);
    else
      v33->m_cur = v31;
    numEntries = 0;
    if ( v40 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v40);
    v35 = (v44 + 127) & 0xFFFFFF80;
    v36 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v37 = (v35 + 15) & 0xFFFFFFF0;
    if ( v35 > v36->m_slabSize || &m_cur[v37] != v36->m_cur || v36->m_firstNonLifoEnd == m_cur )
      hkLifoAllocator::slowBlockFree(v36, m_cur, v37);
    else
      v36->m_cur = m_cur;
    if ( v14 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, m_cur, v14 & 0x3FFFFFFF);
  }
  else
  {
    hkpContinuousSimulation::collideEntitiesOfOneIslandNarrowPhaseContinuous_toiOnly(
      this,
      entities,
      numEntities,
      input,
      entitiesNeedingPsiCollisionDetection);
  }
}}
  else
  {
    hkpContinuousSimulation::collideEntitiesOfOneIslandNarrowPhaseContinuous_toiOnly(
      this,
      entities,
      numEntities,
      input,
   

// File Line: 1224
// RVA: 0xD75110
hkpIslandsAgentEntriesInfo *__fastcall getIslandEntriesInfo(
        hkpSimulationIsland *island,
        hkArray<hkpIslandsAgentEntriesInfo,hkContainerHeapAllocator> *islandEntriesInfos)
{
  int m_size; // edx
  int v5; // eax
  hkpIslandsAgentEntriesInfo *m_data; // r8
  __int64 v7; // rcx
  hkpIslandsAgentEntriesInfo *v8; // rax
  int *m_firstEntryIdx; // rax
  __int64 v10; // rdx
  __int64 v11; // rdx
  hkpIslandsAgentEntriesInfo *v12; // rdx
  int *v13; // rax

  m_size = islandEntriesInfos->m_size;
  v5 = 0;
  if ( m_size <= 0 )
  {
LABEL_5:
    if ( m_size == (islandEntriesInfos->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&islandEntriesInfos->m_data, 32);
    v7 = 2i64;
    v8 = &islandEntriesInfos->m_data[islandEntriesInfos->m_size];
    if ( v8 )
    {
      v8->m_island = 0i64;
      m_firstEntryIdx = v8->m_firstEntryIdx;
      v10 = 2i64;
      do
      {
        *(m_firstEntryIdx - 2) = 0;
        *m_firstEntryIdx = 0;
        m_firstEntryIdx[2] = 0;
        ++m_firstEntryIdx;
        --v10;
      }
      while ( v10 );
    }
    v11 = islandEntriesInfos->m_size;
    islandEntriesInfos->m_size = v11 + 1;
    v12 = &islandEntriesInfos->m_data[v11];
    if ( v12 )
    {
      v12->m_island = 0i64;
      v13 = v12->m_firstEntryIdx;
      do
      {
        *(v13 - 2) = 0;
        *v13 = 0;
        v13[2] = 0;
        ++v13;
        --v7;
      }
      while ( v7 );
    }
    islandEntriesInfos->m_data[islandEntriesInfos->m_size - 1].m_island = island;
    return &islandEntriesInfos->m_data[islandEntriesInfos->m_size - 1];
  }
  else
  {
    m_data = islandEntriesInfos->m_data;
    while ( island != m_data->m_island )
    {
      ++v5;
      ++m_data;
      if ( v5 >= m_size )
        goto LABEL_5;
    }
    return &islandEntriesInfos->m_data[v5];
  }
}

// File Line: 1250
// RVA: 0xD74430
void __fastcall hkpMultiThreadedSimulation::collideEntitiesNeedingPsiCollisionDetectionNarrowPhase_toiOnly(
        hkpMultiThreadedSimulation *this,
        hkpProcessCollisionInput *input,
        hkpMultiThreadedSimulation *entitiesNeedingPsiCollisionDetection)
{
  hkpMultiThreadedSimulation *v3; // r14
  _QWORD *Value; // rax
  unsigned __int64 v6; // r9
  _QWORD *v7; // r10
  unsigned __int64 v8; // rax
  __int64 v9; // r15
  __int64 v10; // r9
  int v11; // edi
  int v12; // edx
  __int64 v13; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *vfptr; // rax
  int v15; // r13d
  unsigned __int64 first_virtual_table_function; // rsi
  __int64 m_size; // r12
  hkpAgentNnEntry *m_agentEntry; // rbx
  hkpCollisionDispatcher *m_collisionDispatcher; // rcx
  __int64 v20; // rdx
  hkpSimulationIsland *v21; // rdi
  int v22; // edx
  char *v23; // r14
  int v24; // edx
  int v25; // ecx
  hkpIslandsAgentEntriesInfo *v26; // r8
  hkpIslandsAgentEntriesInfo *v27; // rax
  hkpIslandsAgentEntriesInfo *v28; // rax
  int *m_firstEntryIdx; // rax
  __int64 v30; // rcx
  __int64 v31; // rax
  int v32; // ecx
  hkpIslandsAgentEntriesInfo *v33; // rax
  int *v34; // rax
  __int64 v35; // rcx
  __int64 v36; // rcx
  __int64 v37; // rax
  __int64 v38; // r8
  int v39; // edx
  __int64 v40; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v41; // rax
  int v42; // ecx
  int v43; // r8d
  __int64 v44; // rdx
  hkpIslandsAgentEntriesInfo *v45; // rax
  int v46; // ecx
  hkLifoAllocator *v47; // rax
  int v48; // r13d
  hkpAgentNnEntry **m_cur; // rdi
  int v50; // r13d
  char *v51; // rcx
  int v52; // r14d
  __int64 v53; // rsi
  hkpIslandsAgentEntriesInfo *v54; // r8
  int v55; // edx
  hkpAgentNnEntry *v56; // r15
  hkpSimulationIsland *v57; // rbx
  __int64 v58; // r12
  int v59; // ecx
  hkpIslandsAgentEntriesInfo *v60; // rax
  hkpIslandsAgentEntriesInfo *v61; // rax
  int *v62; // rax
  __int64 v63; // rcx
  __int64 v64; // rax
  int v65; // ecx
  hkpIslandsAgentEntriesInfo *v66; // rax
  int *v67; // rax
  __int64 v68; // rcx
  __int64 v69; // rcx
  __int64 v70; // rdx
  hkpMultiThreadedSimulation *v71; // rbx
  hkpWorld *m_world; // rbx
  bool v73; // zf
  _QWORD *v74; // rax
  _QWORD *v75; // rcx
  _QWORD *v76; // r8
  unsigned __int64 v77; // rax
  _QWORD *v78; // rcx
  hkLifoAllocator *v79; // rax
  int v80; // r8d
  hkpContinuousSimulation::CollisionQualityOverride collisionQualityOverride[2]; // [rsp+30h] [rbp-19h] BYREF
  int numInfos; // [rsp+38h] [rbp-11h]
  int v83; // [rsp+3Ch] [rbp-Dh]
  char *array; // [rsp+40h] [rbp-9h] BYREF
  int v85; // [rsp+48h] [rbp-1h]
  int v86; // [rsp+4Ch] [rbp+3h]
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> entries; // [rsp+50h] [rbp+7h] BYREF
  AMD_HD3D v88; // [rsp+60h] [rbp+17h] BYREF
  hkpMultiThreadedSimulation *vars0; // [rsp+B0h] [rbp+67h]
  int numAllEntries; // [rsp+C8h] [rbp+7Fh]

  v3 = this;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = Value[1];
  v7 = Value;
  if ( v6 < Value[3] )
  {
    *(_QWORD *)v6 = "LtPhysics 2012";
    *(_QWORD *)(v6 + 16) = "StRecollide PSI";
    v8 = __rdtsc();
    *(_DWORD *)(v6 + 8) = v8;
    v7[1] = v6 + 24;
  }
  v9 = 0i64;
  ++v3->m_world->m_criticalOperationsLockCount;
  v10 = *(int *)(&entitiesNeedingPsiCollisionDetection->m_referenceCount + 1);
  *(_QWORD *)&v88.mEnableStereo = 0i64;
  v88.mWidth = 0;
  v88.mHeight = -1;
  array = 0i64;
  v85 = 0;
  v86 = 0x80000000;
  *(_QWORD *)collisionQualityOverride = 0i64;
  numInfos = 0;
  v83 = 0x80000000;
  v11 = 0;
  numAllEntries = 0;
  v12 = 0;
  v13 = 0i64;
  if ( (int)v10 >= 0 )
  {
    vfptr = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *)entitiesNeedingPsiCollisionDetection->vfptr;
    do
    {
      if ( vfptr->key != -1i64 )
        break;
      ++v13;
      ++v12;
      ++vfptr;
    }
    while ( v13 <= v10 );
  }
  v15 = v12;
  if ( v12 <= (int)v10 )
  {
    do
    {
      first_virtual_table_function = (unsigned __int64)entitiesNeedingPsiCollisionDetection->vfptr[v15].__first_virtual_table_function__;
      entries.m_data = 0i64;
      entries.m_size = 0;
      entries.m_capacityAndFlags = 0x80000000;
      hkpLinkedCollidable::getCollisionEntriesSorted(
        (hkpLinkedCollidable *)(first_virtual_table_function + 32),
        &entries);
      m_size = entries.m_size;
      if ( entries.m_size > 0 )
      {
        do
        {
          m_agentEntry = entries.m_data[v9].m_agentEntry;
          if ( !(unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v88,
                                (unsigned __int64)m_agentEntry,
                                0i64) )
          {
            m_collisionDispatcher = v3->m_world->m_collisionDispatcher;
            v20 = (__int64)m_agentEntry->m_collisionQualityIndex << 6;
            if ( !*(unsigned int *)((char *)&m_collisionDispatcher->m_collisionQualityInfo[0].m_useContinuousPhysics.m_storage
                                  + v20)
              || *(&m_collisionDispatcher->m_collisionQualityInfo[0].m_useSimpleToiHandling.m_bool + v20)
              && _mm_shuffle_ps(
                   *(__m128 *)(first_virtual_table_function + 448),
                   *(__m128 *)(first_virtual_table_function + 448),
                   255).m128_f32[0] == 0.0 )
            {
              v21 = *(hkpSimulationIsland **)(first_virtual_table_function + 296);
              if ( *(_BYTE *)(first_virtual_table_function + 352) == 5 )
                v21 = *(hkpSimulationIsland **)((first_virtual_table_function ^ ((__int64)m_agentEntry->m_collidable[1]
                                                                               + m_agentEntry->m_collidable[1]->m_ownerOffset) ^ ((__int64)m_agentEntry->m_collidable[0] + m_agentEntry->m_collidable[0]->m_ownerOffset))
                                              + 0x128);
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v88,
                &hkContainerHeapAllocator::s_alloc,
                (unsigned __int64)m_agentEntry,
                1ui64);
              v22 = v85;
              if ( v85 == (v86 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 24);
                v22 = v85;
              }
              v85 = v22 + 1;
              v23 = &array[24 * v22];
              v24 = 0;
              *(_QWORD *)v23 = m_agentEntry;
              *((_QWORD *)v23 + 1) = v21;
              *((_DWORD *)v23 + 4) = (unsigned __int8)m_agentEntry->m_nnTrackType.m_storage - 1;
              v25 = numInfos;
              v26 = *(hkpIslandsAgentEntriesInfo **)collisionQualityOverride;
              if ( numInfos <= 0 )
              {
LABEL_21:
                if ( numInfos == (v83 & 0x3FFFFFFF) )
                {
                  hkArrayUtil::_reserveMore(
                    &hkContainerHeapAllocator::s_alloc,
                    (const void **)collisionQualityOverride,
                    32);
                  v25 = numInfos;
                  v26 = *(hkpIslandsAgentEntriesInfo **)collisionQualityOverride;
                }
                v28 = &v26[v25];
                if ( v28 )
                {
                  v28->m_island = 0i64;
                  m_firstEntryIdx = v28->m_firstEntryIdx;
                  v30 = 2i64;
                  do
                  {
                    *(m_firstEntryIdx - 2) = 0;
                    *m_firstEntryIdx = 0;
                    m_firstEntryIdx[2] = 0;
                    ++m_firstEntryIdx;
                    --v30;
                  }
                  while ( v30 );
                  v25 = numInfos;
                  v26 = *(hkpIslandsAgentEntriesInfo **)collisionQualityOverride;
                }
                v31 = v25;
                v32 = v25 + 1;
                numInfos = v32;
                v33 = &v26[v31];
                if ( v33 )
                {
                  v33->m_island = 0i64;
                  v34 = v33->m_firstEntryIdx;
                  v35 = 2i64;
                  do
                  {
                    *(v34 - 2) = 0;
                    *v34 = 0;
                    v34[2] = 0;
                    ++v34;
                    --v35;
                  }
                  while ( v35 );
                  v32 = numInfos;
                  v26 = *(hkpIslandsAgentEntriesInfo **)collisionQualityOverride;
                }
                v26[v32 - 1].m_island = v21;
                v36 = *(_QWORD *)collisionQualityOverride + 32i64 * (numInfos - 1);
              }
              else
              {
                v27 = *(hkpIslandsAgentEntriesInfo **)collisionQualityOverride;
                while ( v21 != v27->m_island )
                {
                  ++v24;
                  ++v27;
                  if ( v24 >= numInfos )
                    goto LABEL_21;
                }
                v36 = *(_QWORD *)collisionQualityOverride + 32i64 * v24;
              }
              v37 = *((int *)v23 + 4);
              v3 = vars0;
              ++*(_DWORD *)(v36 + 4 * v37 + 8);
              v11 = ++numAllEntries;
            }
          }
          ++v9;
          --m_size;
        }
        while ( m_size );
        entitiesNeedingPsiCollisionDetection = this;
        v9 = 0i64;
      }
      hkReferencedObject::removeReference((hkReferencedObject *)first_virtual_table_function);
      v38 = *(int *)(&entitiesNeedingPsiCollisionDetection->m_referenceCount + 1);
      v39 = v15 + 1;
      v40 = v15 + 1;
      if ( v40 <= v38 )
      {
        v41 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *)&entitiesNeedingPsiCollisionDetection->vfptr[v39];
        do
        {
          if ( v41->key != -1i64 )
            break;
          ++v40;
          ++v39;
          ++v41;
        }
        while ( v40 <= v38 );
      }
      v15 = v39;
      entries.m_size = 0;
      if ( entries.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          entries.m_data,
          16 * entries.m_capacityAndFlags);
      entries.m_data = 0i64;
      entries.m_capacityAndFlags = 0x80000000;
    }
    while ( v15 <= *(_DWORD *)(&entitiesNeedingPsiCollisionDetection->m_referenceCount + 1) );
  }
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)entitiesNeedingPsiCollisionDetection);
  v42 = 0;
  v43 = 0;
  if ( numInfos > 0 )
  {
    v44 = 0i64;
    do
    {
      v45 = *(hkpIslandsAgentEntriesInfo **)collisionQualityOverride;
      ++v43;
      *(_DWORD *)(*(_QWORD *)collisionQualityOverride + ++v44 * 32 - 16) = v42;
      v45[v44 - 1].m_nextEntryIdx[0] = v42;
      v46 = v45[v44 - 1].m_numEntries[0] + v42;
      v45[v44 - 1].m_firstEntryIdx[1] = v46;
      v45[v44 - 1].m_nextEntryIdx[1] = v46;
      v42 = v45[v44 - 1].m_numEntries[1] + v46;
    }
    while ( v43 < numInfos );
  }
  v47 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v48 = 8 * v11 + 127;
  m_cur = (hkpAgentNnEntry **)v47->m_cur;
  v50 = v48 & 0xFFFFFF80;
  v51 = (char *)m_cur + v50;
  if ( v50 > v47->m_slabSize || v51 > v47->m_end )
    m_cur = (hkpAgentNnEntry **)hkLifoAllocator::allocateFromNewSlab(v47, v50);
  else
    v47->m_cur = v51;
  v52 = 0;
  if ( v85 > 0 )
  {
    v53 = 0i64;
    do
    {
      v54 = *(hkpIslandsAgentEntriesInfo **)collisionQualityOverride;
      v55 = 0;
      v56 = *(hkpAgentNnEntry **)&array[v53];
      v57 = *(hkpSimulationIsland **)&array[v53 + 8];
      v58 = *(int *)&array[v53 + 16];
      v59 = numInfos;
      if ( numInfos <= 0 )
      {
LABEL_56:
        if ( numInfos == (v83 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)collisionQualityOverride, 32);
          v59 = numInfos;
          v54 = *(hkpIslandsAgentEntriesInfo **)collisionQualityOverride;
        }
        v61 = &v54[v59];
        if ( v61 )
        {
          v61->m_island = 0i64;
          v62 = v61->m_firstEntryIdx;
          v63 = 2i64;
          do
          {
            *(v62 - 2) = 0;
            *v62 = 0;
            v62[2] = 0;
            ++v62;
            --v63;
          }
          while ( v63 );
          v59 = numInfos;
          v54 = *(hkpIslandsAgentEntriesInfo **)collisionQualityOverride;
        }
        v64 = v59;
        v65 = v59 + 1;
        numInfos = v65;
        v66 = &v54[v64];
        if ( v66 )
        {
          v66->m_island = 0i64;
          v67 = v66->m_firstEntryIdx;
          v68 = 2i64;
          do
          {
            *(v67 - 2) = 0;
            *v67 = 0;
            v67[2] = 0;
            ++v67;
            --v68;
          }
          while ( v68 );
          v65 = numInfos;
          v54 = *(hkpIslandsAgentEntriesInfo **)collisionQualityOverride;
        }
        v54[v65 - 1].m_island = v57;
        v69 = *(_QWORD *)collisionQualityOverride + 32i64 * (numInfos - 1);
      }
      else
      {
        v60 = *(hkpIslandsAgentEntriesInfo **)collisionQualityOverride;
        while ( v57 != v60->m_island )
        {
          ++v55;
          ++v60;
          if ( v55 >= numInfos )
            goto LABEL_56;
        }
        v69 = *(_QWORD *)collisionQualityOverride + 32i64 * v55;
      }
      v70 = *(int *)(v69 + 4 * v58 + 24);
      ++v52;
      v53 += 24i64;
      *(_DWORD *)(v69 + 4 * v58 + 24) = v70 + 1;
      m_cur[v70] = v56;
    }
    while ( v52 < v85 );
  }
  v71 = vars0;
  hkpMultiThreadedSimulation::processAgentNnEntriesFromMultipleIslands(
    vars0,
    m_cur,
    numAllEntries,
    *(hkpIslandsAgentEntriesInfo **)collisionQualityOverride,
    numInfos,
    vars0->m_world->m_collisionInput,
    DISABLE_TOIS);
  m_world = v71->m_world;
  v73 = m_world->m_criticalOperationsLockCount-- == 1;
  if ( v73 && !m_world->m_blockExecutingPendingOperations.m_bool )
  {
    if ( m_world->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(m_world);
    if ( m_world->m_pendingOperationQueueCount == 1 && m_world->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(m_world);
  }
  v74 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v75 = (_QWORD *)v74[1];
  v76 = v74;
  if ( (unsigned __int64)v75 < v74[3] )
  {
    *v75 = "lt";
    v77 = __rdtsc();
    v78 = v75 + 2;
    *((_DWORD *)v78 - 2) = v77;
    v76[1] = v78;
  }
  v79 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v80 = (v50 + 15) & 0xFFFFFFF0;
  if ( v50 > v79->m_slabSize || (char *)m_cur + v80 != v79->m_cur || v79->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v79, (char *)m_cur, v80);
  else
    v79->m_cur = m_cur;
  numInfos = 0;
  if ( v83 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)collisionQualityOverride,
      32 * v83);
  *(_QWORD *)collisionQualityOverride = 0i64;
  v83 = 0x80000000;
  v85 = 0;
  if ( v86 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 24 * (v86 & 0x3FFFFFFF));
  array = 0i64;
  v86 = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v88,
    &hkContainerHeapAllocator::s_alloc);
  _(&v88);
}83 = 0x80000000;
  v85 = 0;
  if ( v86 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 24 * (v86 & 0x3FFFFFFF));
  array = 0i64;
  v86 = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v88

// File Line: 1372
// RVA: 0xD73B60
void __fastcall hkpMultiThreadedSimulation::processAgentNnEntries_oneInfo(
        hkpMultiThreadedSimulation *this,
        hkpAgentNnEntry **allEntries,
        hkpProcessCollisionInput *collisionInput,
        hkpIslandsAgentEntriesInfo *info,
        hkpContinuousSimulation::CollisionQualityOverride collisionQualityOverride,
        hkpPostCollideJob *postCollideJobOut)
{
  hkLifoAllocator *Value; // rax
  __int64 m_cur; // rbx
  void *v12; // rcx
  int v13; // ecx
  int v14; // edi
  int v15; // edx
  int m_maxEntriesPerToiMidphaseCollideTask; // r8d
  __int64 v17; // rax
  hkpAgentNnEntry **v18; // rcx
  hkStepInfo m_stepInfo; // xmm0
  __int64 v20; // rax
  hkpWorld *m_world; // rax
  int m_maxEntriesPerToiNarrowphaseCollideTask; // edx
  hkpAgentSectorHeader *v23; // rax
  __int64 v24; // r14
  hkpAgentSectorHeader *v25; // r15
  hkpSimulationIsland **v26; // rdi
  hkLifoAllocator *v27; // rax

  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (__int64)Value->m_cur;
  v12 = (void *)(m_cur + 256);
  if ( Value->m_slabSize < 256 || v12 > Value->m_end )
    m_cur = hkLifoAllocator::allocateFromNewSlab(Value, 256);
  else
    Value->m_cur = v12;
  v13 = 0;
  v14 = 0;
  v15 = info->m_numEntries[0] + info->m_numEntries[1];
  if ( v15 )
  {
    m_maxEntriesPerToiMidphaseCollideTask = this->m_world->m_maxEntriesPerToiMidphaseCollideTask;
    if ( m_cur )
    {
      v17 = info->m_firstEntryIdx[0];
      *(_WORD *)m_cur = 15;
      *(_BYTE *)(m_cur + 2) = 1;
      v18 = &allEntries[v17];
      *(_WORD *)(m_cur + 6) = -1;
      *(_WORD *)(m_cur + 4) = 112;
      *(_QWORD *)(m_cur + 24) = 0i64;
      *(_WORD *)(m_cur + 16) = -1;
      *(_QWORD *)(m_cur + 32) = 0i64;
      m_stepInfo = collisionInput->m_stepInfo;
      *(_BYTE *)(m_cur + 104) = collisionQualityOverride;
      *(_WORD *)(m_cur + 16) = 0;
      *(_WORD *)(m_cur + 56) = 0;
      *(hkStepInfo *)(m_cur + 80) = m_stepInfo;
      v20 = m_cur;
      *(_QWORD *)(m_cur + 64) = v18;
      *(_WORD *)(m_cur + 58) = v15;
      *(_WORD *)(m_cur + 60) = m_maxEntriesPerToiMidphaseCollideTask;
      *(_BYTE *)(m_cur + 62) = 0;
      *(_QWORD *)(m_cur + 48) = 0i64;
      *(_BYTE *)(m_cur + 1) = 1;
    }
    else
    {
      v20 = 0i64;
    }
    *(_WORD *)(v20 + 56) = 0;
    v14 = 1;
    v13 = (v15 - 1) / m_maxEntriesPerToiMidphaseCollideTask + 1;
  }
  m_world = this->m_world;
  m_maxEntriesPerToiNarrowphaseCollideTask = m_world->m_maxEntriesPerToiNarrowphaseCollideTask;
  if ( m_world->m_maxEntriesPerToiMidphaseCollideTask > m_maxEntriesPerToiNarrowphaseCollideTask )
    m_maxEntriesPerToiNarrowphaseCollideTask = m_world->m_maxEntriesPerToiMidphaseCollideTask;
  v23 = hkpAgentSectorHeader::allocate(v13, m_maxEntriesPerToiNarrowphaseCollideTask);
  v24 = v14;
  v23->m_shapeKeyTracks = 0i64;
  v23->m_numShapeKeyTracks = 0;
  v25 = v23;
  if ( v14 > 0 )
  {
    v26 = (hkpSimulationIsland **)(m_cur + 24);
    do
    {
      v26[3] = (hkpSimulationIsland *)v25;
      *v26 = info->m_island;
      *((_WORD *)v26 - 4) = info->m_island->m_storageIndex;
      v26[2] = (hkpSimulationIsland *)this->m_world->m_multithreadedSimulationJobData;
      hkJobQueue::addJob(this->m_jobQueueHandleForToiSolve, (hkJob *)(v26 - 3), JOB_LOW_PRIORITY);
      v26 += 14;
      --v24;
    }
    while ( v24 );
  }
  if ( postCollideJobOut )
  {
    *(_WORD *)&postCollideJobOut->m_jobSubType = 14;
    postCollideJobOut->m_jobSpuType.m_storage = 2;
    postCollideJobOut->m_threadAffinity = -1;
    postCollideJobOut->m_size = 64;
    postCollideJobOut->m_islandIndex = *(_WORD *)(m_cur + 16);
    postCollideJobOut->m_island = *(hkpSimulationIsland **)(m_cur + 24);
    postCollideJobOut->m_taskHeader = *(hkpBuildJacobianTaskHeader **)(m_cur + 32);
    postCollideJobOut->m_mtThreadStructure = *(hkpMtThreadStructure **)(m_cur + 40);
    postCollideJobOut->m_islandIndex = *(_WORD *)(m_cur + 16);
    postCollideJobOut->m_header = *(hkpAgentSectorHeader **)(m_cur + 48);
  }
  postCollideJobOut->m_island = *(hkpSimulationIsland **)(m_cur + 24);
  v27 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v27->m_slabSize < 256 || (void *)(m_cur + 256) != v27->m_cur || v27->m_firstNonLifoEnd == (void *)m_cur )
    hkLifoAllocator::slowBlockFree(v27, (char *)m_cur, 256);
  else
    v27->m_cur = (void *)m_cur;
}

// File Line: 1467
// RVA: 0xD733F0
void __fastcall hkpMultiThreadedSimulation::processAgentNnEntries(
        hkpMultiThreadedSimulation *this,
        hkpAgentNnEntry **entries,
        int numEntries,
        hkpProcessCollisionInput *collisionInput,
        hkpIslandsAgentEntriesInfo *info,
        hkpContinuousSimulation::CollisionQualityOverride collisionQualityOverride)
{
  hkpContinuousSimulation::CollisionQualityOverride v6; // edi
  hkpSimulationIsland *m_island; // r12
  hkLifoAllocator *Value; // rax
  char *m_cur; // rdi
  int v14; // ebx
  char *v15; // rcx
  hkpWorld *m_world; // r8
  hkpProcessCollisionInput *m_collisionInput; // rcx
  hkpViolatedConstraintArray *m_violatedConstraintArray; // rax
  float m_damping; // xmm1_4
  __m128 m_maxConstraintViolationSqrd_low; // xmm0
  _QWORD **v21; // rax
  hkLifoAllocator *v22; // rax
  int v23; // r8d
  hkpMtThreadStructure tl; // [rsp+30h] [rbp-A8h] BYREF
  hkpIslandsAgentEntriesInfo *retaddr; // [rsp+1F8h] [rbp+120h]
  hkpContinuousSimulation::CollisionQualityOverride v26; // [rsp+200h] [rbp+128h]

  m_island = retaddr->m_island;
  if ( this->m_jobQueueHandleForToiSolve && numEntries > this->m_world->m_maxNumToiCollisionPairsSinglethreaded )
  {
    v26 = v6;
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)Value->m_cur;
    v14 = (8 * numEntries + 127) & 0xFFFFFF80;
    v15 = &m_cur[v14];
    if ( v14 > Value->m_slabSize || v15 > Value->m_end )
      m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v14);
    else
      Value->m_cur = v15;
    hkpMultiThreadedSimulation::processAgentNnEntries_oneInfo(
      this,
      entries,
      collisionInput,
      retaddr,
      v26,
      (hkpPostCollideJob *)(&tl.m_collisionInput.m_config + 1));
    hkJobQueue::processAllJobs(this->m_jobQueueHandleForToiSolve, 1);
    m_world = this->m_world;
    *(_QWORD *)&tl.m_tolerance.m_storage = m_island;
    tl.m_constraintQueryIn.m_maxConstraintViolationSqrd.m_real.m128_u64[0] = (unsigned __int64)hkpBeginConstraints;
    tl.m_collisionInput.m_dynamicsInfo = &m_world->m_dynamicsStepInfo;
    tl.m_collisionInput.m_aabb32Info.m_bitScale.m_quad.m128_u64[0] = 0i64;
    m_collisionInput = m_world->m_collisionInput;
    tl.m_constraintQueryIn.m_maxConstraintViolationSqrd.m_real.m128_u64[1] = (unsigned __int64)m_collisionInput->m_dispatcher.m_storage;
    tl.m_constraintQueryIn.m_constraintInstance.m_storage = (hkpConstraintInstance *)m_collisionInput->m_weldClosestPoints.m_storage;
    HIDWORD(tl.m_constraintQueryIn.m_constraintInstance.m_storage) = m_collisionInput->m_forceAcceptContactPoints.m_storage;
    *(float *)&tl.m_constraintQueryIn.m_violatedConstraints.m_storage = m_collisionInput->m_tolerance.m_storage;
    *(_QWORD *)&tl.m_constraintQueryIn.m_accumulatorAIndex.m_storage = m_collisionInput->m_filter.m_storage;
    tl.m_constraintQueryIn.m_beginConstraints = (void (__fastcall *)(hkpConstraintQueryIn *, hkpConstraintQueryOut *, hkpSolverResults *, int))m_collisionInput->m_convexListFilter.m_storage;
    LODWORD(tl.m_collisionInput.m_dispatcher.m_storage) = m_collisionInput->m_createPredictiveAgents.m_storage;
    *(hkVector4f *)&tl.m_collisionInput.m_weldClosestPoints.m_storage = m_collisionInput->m_aabb32Info.m_bitOffsetLow;
    *(hkVector4f *)&tl.m_collisionInput.m_filter.m_storage = m_collisionInput->m_aabb32Info.m_bitOffsetHigh;
    *(hkVector4f *)&tl.m_collisionInput.m_createPredictiveAgents.m_storage = m_collisionInput->m_aabb32Info.m_bitScale;
    *(hkVector4f *)((char *)&tl.m_collisionInput.m_aabb32Info.m_bitOffsetLow + 8) = (hkVector4f)m_collisionInput->m_stepInfo;
    tl.m_collisionInput.m_aabb32Info.m_bitOffsetHigh.m_quad.m128_u64[1] = (unsigned __int64)m_collisionInput->m_collisionQualityInfo.m_storage;
    tl.m_collisionInput.m_aabb32Info.m_bitScale.m_quad.m128_u64[1] = (unsigned __int64)m_collisionInput->m_dynamicsInfo;
    LOWORD(tl.m_collisionInput.m_stepInfo.m_startTime.m_storage) = *(_WORD *)&m_collisionInput->m_enableDeprecatedWelding.m_bool;
    *(_QWORD *)&tl.m_collisionInput.m_stepInfo.m_deltaTime.m_storage = m_collisionInput->m_config;
    m_violatedConstraintArray = m_world->m_violatedConstraintArray;
    tl.m_constraintQueryIn.m_subStepDeltaTime.m_storage = m_world->m_dynamicsStepInfo.m_solverInfo.m_deltaTime;
    tl.m_constraintQueryIn.m_microStepDeltaTime.m_storage = m_world->m_dynamicsStepInfo.m_solverInfo.m_deltaTime
                                                          * m_world->m_dynamicsStepInfo.m_solverInfo.m_invNumMicroSteps;
    tl.m_constraintQueryIn.m_subStepInvDeltaTime.m_storage = m_world->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
    tl.m_constraintQueryIn.m_invNumSteps.m_storage = m_world->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
    tl.m_constraintQueryIn.m_invNumStepsTimesMicroSteps.m_storage = m_world->m_dynamicsStepInfo.m_solverInfo.m_invNumMicroSteps
                                                                  * m_world->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
    tl.m_constraintQueryIn.m_frictionRhsFactor.m_storage = m_world->m_dynamicsStepInfo.m_solverInfo.m_tau;
    m_damping = m_world->m_dynamicsStepInfo.m_solverInfo.m_damping;
    *(_QWORD *)&tl.m_constraintQueryIn.m_tau.m_storage = m_violatedConstraintArray;
    *((float *)&tl.m_constraintQueryIn.m_frictionRhsFactor + 1) = m_damping;
    tl.m_constraintQueryIn.m_rhsFactor.m_storage = m_world->m_dynamicsStepInfo.m_solverInfo.m_tauDivDamp
                                                 * m_world->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
    tl.m_constraintQueryIn.m_virtMassFactor.m_storage = m_world->m_dynamicsStepInfo.m_solverInfo.m_damping;
    tl.m_constraintQueryIn.m_frictionRhsFactor.m_storage = m_world->m_dynamicsStepInfo.m_solverInfo.m_frictionTauDivDamp
                                                         * m_world->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
    tl.m_constraintQueryIn.m_frameDeltaTime.m_storage = m_world->m_dynamicsStepInfo.m_stepInfo.m_deltaTime.m_storage;
    tl.m_constraintQueryIn.m_frameInvDeltaTime.m_storage = m_world->m_dynamicsStepInfo.m_stepInfo.m_invDeltaTime.m_storage;
    m_maxConstraintViolationSqrd_low = (__m128)LODWORD(m_world->m_dynamicsStepInfo.m_solverInfo.m_maxConstraintViolationSqrd);
    tl.m_collisionInput.m_spareAgentSector = (hkpAgent1nSector *)this;
    *(__m128 *)&tl.m_constraintQueryIn.m_bodyB.m_storage = _mm_shuffle_ps(
                                                             m_maxConstraintViolationSqrd_low,
                                                             m_maxConstraintViolationSqrd_low,
                                                             0);
    m_maxConstraintViolationSqrd_low.m128_i32[0] = LODWORD(m_world->m_collisionInput->m_tolerance.m_storage);
    tl.m_world = m_world;
    tl.m_collisionInput.m_config = (hkpCollisionAgentConfig *)hkpWeldingUtility::m_sinCosTable;
    *(_DWORD *)&tl.m_collisionInput.m_enableDeprecatedWelding.m_bool = m_maxConstraintViolationSqrd_low.m128_i32[0];
    hkCpuPostCollideJob(&tl, 0i64, (hkJobQueue::JobQueueEntry *)(&tl.m_collisionInput.m_config + 1));
    if ( tl.m_collisionInput.m_aabb32Info.m_bitScale.m_quad.m128_u64[0] )
    {
      v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, unsigned __int64, __int64))(*v21[11] + 16i64))(
        v21[11],
        tl.m_collisionInput.m_aabb32Info.m_bitScale.m_quad.m128_u64[0],
        512i64);
    }
    v22 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v23 = (v14 + 15) & 0xFFFFFFF0;
    if ( v14 > v22->m_slabSize || &m_cur[v23] != v22->m_cur || v22->m_firstNonLifoEnd == m_cur )
      hkLifoAllocator::slowBlockFree(v22, m_cur, v23);
    else
      v22->m_cur = m_cur;
  }
  else
  {
    hkpContinuousSimulation::processAgentNnEntries(this, entries, numEntries, collisionInput, m_island, v26);
  }
}

// File Line: 1549
// RVA: 0xD73740
void __fastcall hkpMultiThreadedSimulation::processAgentNnEntriesFromMultipleIslands(
        hkpMultiThreadedSimulation *this,
        hkpAgentNnEntry **allEntries,
        int numAllEntries,
        hkpIslandsAgentEntriesInfo *islandEntriesInfos,
        unsigned int numInfos,
        hkpProcessCollisionInput *collisionInput,
        hkpContinuousSimulation::CollisionQualityOverride collisionQualityOverride)
{
  hkpIslandsAgentEntriesInfo *v7; // rbx
  hkpIslandsAgentEntriesInfo *v10; // r15
  __int64 v11; // rsi
  hkLifoAllocator *Value; // rcx
  __int64 m_cur; // rax
  int v14; // r14d
  void *v15; // rdx
  __int64 v16; // r13
  hkpPostCollideJob *postCollideJobOut; // rsi
  hkpWorld *m_world; // r8
  hkpProcessCollisionInput *m_collisionInput; // rcx
  hkpViolatedConstraintArray *m_violatedConstraintArray; // rax
  float m_damping; // xmm1_4
  __m128 m_maxConstraintViolationSqrd_low; // xmm0
  hkJobQueue::JobQueueEntry *v23; // rbx
  _QWORD **v24; // rax
  hkLifoAllocator *v25; // rax
  int v26; // r8d
  __int64 v27; // rsi
  int *m_numEntries; // rbx
  hkJobQueue::JobQueueEntry *nextJobOut; // [rsp+30h] [rbp-D0h]
  hkpMtThreadStructure tl; // [rsp+40h] [rbp-C0h] BYREF

  v7 = islandEntriesInfos;
  if ( this->m_jobQueueHandleForToiSolve && numAllEntries > this->m_world->m_maxNumToiCollisionPairsSinglethreaded )
  {
    v10 = 0i64;
    v11 = numInfos;
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (__int64)Value->m_cur;
    nextJobOut = (hkJobQueue::JobQueueEntry *)m_cur;
    v14 = ((numInfos << 6) + 127) & 0xFFFFFF80;
    v15 = (void *)(m_cur + v14);
    if ( v14 > Value->m_slabSize || v15 > Value->m_end )
    {
      m_cur = hkLifoAllocator::allocateFromNewSlab(Value, v14);
      nextJobOut = (hkJobQueue::JobQueueEntry *)m_cur;
    }
    else
    {
      Value->m_cur = v15;
    }
    if ( (int)numInfos > 0 )
    {
      v16 = numInfos;
      postCollideJobOut = (hkpPostCollideJob *)m_cur;
      do
      {
        if ( v7->m_island == this->m_world->m_fixedIsland )
          v10 = v7;
        else
          hkpMultiThreadedSimulation::processAgentNnEntries_oneInfo(
            this,
            allEntries,
            collisionInput,
            v7,
            collisionQualityOverride,
            postCollideJobOut);
        ++postCollideJobOut;
        ++v7;
        --v16;
      }
      while ( v16 );
      v14 = ((numInfos << 6) + 127) & 0xFFFFFF80;
      v11 = numInfos;
    }
    hkJobQueue::processAllJobs(this->m_jobQueueHandleForToiSolve, 1);
    m_world = this->m_world;
    tl.m_collisionInput.m_forceAcceptContactPoints.m_storage = 0;
    tl.m_collisionInput.m_spareAgentSector = 0i64;
    tl.m_constraintQueryIn.m_beginConstraints = hkpBeginConstraints;
    tl.m_dynamicsStepInfo.m_storage = &m_world->m_dynamicsStepInfo;
    m_collisionInput = m_world->m_collisionInput;
    tl.m_collisionInput.m_dispatcher.m_storage = m_collisionInput->m_dispatcher.m_storage;
    tl.m_collisionInput.m_weldClosestPoints.m_storage = m_collisionInput->m_weldClosestPoints.m_storage;
    tl.m_collisionInput.m_forceAcceptContactPoints.m_storage = m_collisionInput->m_forceAcceptContactPoints.m_storage;
    tl.m_collisionInput.m_tolerance.m_storage = m_collisionInput->m_tolerance.m_storage;
    tl.m_collisionInput.m_filter.m_storage = m_collisionInput->m_filter.m_storage;
    tl.m_collisionInput.m_convexListFilter.m_storage = m_collisionInput->m_convexListFilter.m_storage;
    tl.m_collisionInput.m_createPredictiveAgents.m_storage = m_collisionInput->m_createPredictiveAgents.m_storage;
    tl.m_collisionInput.m_aabb32Info = m_collisionInput->m_aabb32Info;
    tl.m_collisionInput.m_stepInfo = m_collisionInput->m_stepInfo;
    tl.m_collisionInput.m_collisionQualityInfo.m_storage = m_collisionInput->m_collisionQualityInfo.m_storage;
    tl.m_collisionInput.m_dynamicsInfo = m_collisionInput->m_dynamicsInfo;
    tl.m_collisionInput.m_enableDeprecatedWelding.m_bool = m_collisionInput->m_enableDeprecatedWelding.m_bool;
    tl.m_collisionInput.m_allowToSkipConfirmedCallbacks.m_bool = m_collisionInput->m_allowToSkipConfirmedCallbacks.m_bool;
    tl.m_collisionInput.m_config = m_collisionInput->m_config;
    m_violatedConstraintArray = m_world->m_violatedConstraintArray;
    tl.m_constraintQueryIn.m_subStepDeltaTime.m_storage = m_world->m_dynamicsStepInfo.m_solverInfo.m_deltaTime;
    tl.m_constraintQueryIn.m_microStepDeltaTime.m_storage = m_world->m_dynamicsStepInfo.m_solverInfo.m_deltaTime
                                                          * m_world->m_dynamicsStepInfo.m_solverInfo.m_invNumMicroSteps;
    tl.m_constraintQueryIn.m_subStepInvDeltaTime.m_storage = m_world->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
    tl.m_constraintQueryIn.m_invNumSteps.m_storage = m_world->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
    tl.m_constraintQueryIn.m_invNumStepsTimesMicroSteps.m_storage = m_world->m_dynamicsStepInfo.m_solverInfo.m_invNumMicroSteps
                                                                  * m_world->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
    tl.m_constraintQueryIn.m_tau.m_storage = m_world->m_dynamicsStepInfo.m_solverInfo.m_tau;
    m_damping = m_world->m_dynamicsStepInfo.m_solverInfo.m_damping;
    tl.m_constraintQueryIn.m_violatedConstraints.m_storage = m_violatedConstraintArray;
    tl.m_constraintQueryIn.m_damping.m_storage = m_damping;
    tl.m_constraintQueryIn.m_rhsFactor.m_storage = m_world->m_dynamicsStepInfo.m_solverInfo.m_tauDivDamp
                                                 * m_world->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
    tl.m_constraintQueryIn.m_virtMassFactor.m_storage = m_world->m_dynamicsStepInfo.m_solverInfo.m_damping;
    tl.m_constraintQueryIn.m_frictionRhsFactor.m_storage = m_world->m_dynamicsStepInfo.m_solverInfo.m_frictionTauDivDamp
                                                         * m_world->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
    tl.m_constraintQueryIn.m_frameDeltaTime.m_storage = m_world->m_dynamicsStepInfo.m_stepInfo.m_deltaTime.m_storage;
    tl.m_constraintQueryIn.m_frameInvDeltaTime.m_storage = m_world->m_dynamicsStepInfo.m_stepInfo.m_invDeltaTime.m_storage;
    m_maxConstraintViolationSqrd_low = (__m128)LODWORD(m_world->m_dynamicsStepInfo.m_solverInfo.m_maxConstraintViolationSqrd);
    tl.m_simulation.m_storage = this;
    tl.m_constraintQueryIn.m_maxConstraintViolationSqrd.m_real = _mm_shuffle_ps(
                                                                   m_maxConstraintViolationSqrd_low,
                                                                   m_maxConstraintViolationSqrd_low,
                                                                   0);
    tl.m_tolerance.m_storage = m_world->m_collisionInput->m_tolerance.m_storage;
    tl.m_weldingTable.m_storage = hkpWeldingUtility::m_sinCosTable;
    tl.m_world = m_world;
    if ( (int)v11 > 0 )
    {
      v23 = nextJobOut;
      do
      {
        hkCpuPostCollideJob(&tl, 0i64, v23);
        v23 = (hkJobQueue::JobQueueEntry *)((char *)v23 + 64);
        --v11;
      }
      while ( v11 );
      if ( tl.m_collisionInput.m_spareAgentSector )
      {
        v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, __int64))(*v24[11] + 16i64))(
          v24[11],
          tl.m_collisionInput.m_spareAgentSector,
          512i64);
      }
    }
    if ( v10 )
      hkpContinuousSimulation::processAgentNnEntries(
        this,
        &allEntries[v10->m_firstEntryIdx[0]],
        v10->m_numEntries[0] + v10->m_numEntries[1],
        collisionInput,
        v10->m_island,
        collisionQualityOverride);
    v25 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v26 = (v14 + 15) & 0xFFFFFFF0;
    if ( v14 > v25->m_slabSize || (char *)nextJobOut + v26 != v25->m_cur || v25->m_firstNonLifoEnd == nextJobOut )
      hkLifoAllocator::slowBlockFree(v25, &nextJobOut->m_jobSubType, v26);
    else
      v25->m_cur = nextJobOut;
  }
  else
  {
    v27 = (int)numInfos;
    if ( (int)numInfos > 0 )
    {
      m_numEntries = islandEntriesInfos->m_numEntries;
      do
      {
        hkpContinuousSimulation::processAgentNnEntries(
          this,
          &allEntries[m_numEntries[2]],
          *m_numEntries + m_numEntries[1],
          collisionInput,
          *((hkpSimulationIsland **)m_numEntries - 1),
          collisionQualityOverride);
        m_numEntries += 8;
        --v27;
      }
      while ( v27 );
    }
  }
}


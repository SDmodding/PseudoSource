// File Line: 113
// RVA: 0xD73250
hkJobQueue::JobStatus __fastcall hkpMultiThreadedSimulation::processNextJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *job)
{
  int v2; // eax
  hkJobQueue::JobStatus result; // eax
  hkBool jobWasCancelledOut; // [rsp+38h] [rbp+10h]

  v2 = (unsigned __int8)job->m_jobSubType;
  jobWasCancelledOut.m_bool = 0;
  switch ( v2 )
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
      result = 1;
      break;
  }
  return result;
}

// File Line: 238
// RVA: 0xD74D90
void __fastcall hkpMultiThreadedSimulation::MtPhantomBroadPhaseListener::addCollisionPair(hkpMultiThreadedSimulation::MtPhantomBroadPhaseListener *this, hkpTypedBroadPhaseHandlePair *pair)
{
  hkpTypedBroadPhaseHandlePair *v2; // rbx
  char *v3; // rcx
  hkpBroadPhaseHandle *v4; // rcx
  char *v5; // rcx

  v2 = pair;
  if ( LOBYTE(pair->m_a[1].m_id) == 2 )
  {
    v3 = (char *)pair->m_a + SBYTE1(pair->m_a[1].m_id) + *((char *)&pair->m_a[8].m_id + SBYTE1(pair->m_a[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v3 + 64i64))(v3, (char *)pair->m_b + SBYTE1(pair->m_b[1].m_id));
  }
  v4 = v2->m_b;
  if ( LOBYTE(v4[1].m_id) == 2 )
  {
    v5 = (char *)v4 + SBYTE1(v4[1].m_id) + *((char *)&v4[8].m_id + SBYTE1(v4[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v5 + 64i64))(v5, (char *)v2->m_a + SBYTE1(v2->m_a[1].m_id));
  }
}

// File Line: 262
// RVA: 0xD74E10
void __fastcall hkpMultiThreadedSimulation::MtPhantomBroadPhaseListener::removeCollisionPair(hkpMultiThreadedSimulation::MtPhantomBroadPhaseListener *this, hkpTypedBroadPhaseHandlePair *pair)
{
  hkpTypedBroadPhaseHandlePair *v2; // rbx
  char *v3; // rcx
  hkpBroadPhaseHandle *v4; // rcx
  char *v5; // rcx

  v2 = pair;
  if ( LOBYTE(pair->m_a[1].m_id) == 2 )
  {
    v3 = (char *)pair->m_a + SBYTE1(pair->m_a[1].m_id) + *((char *)&pair->m_a[8].m_id + SBYTE1(pair->m_a[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v3 + 80i64))(v3, (char *)pair->m_b + SBYTE1(pair->m_b[1].m_id));
  }
  v4 = v2->m_b;
  if ( LOBYTE(v4[1].m_id) == 2 )
  {
    v5 = (char *)v4 + SBYTE1(v4[1].m_id) + *((char *)&v4[8].m_id + SBYTE1(v4[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v5 + 80i64))(v5, (char *)v2->m_a + SBYTE1(v2->m_a[1].m_id));
  }
}

// File Line: 298
// RVA: 0xD74BA0
void __fastcall hkpMultiThreadedSimulation::MtEntityEntityBroadPhaseListener::addCollisionPair(hkpMultiThreadedSimulation::MtEntityEntityBroadPhaseListener *this, hkpTypedBroadPhaseHandlePair *pair)
{
  hkpMultiThreadedSimulation *v2; // r9
  hkpTypedBroadPhaseHandlePair *v3; // rdi
  hkpLinkedCollidable *v4; // r11
  __int64 v5; // r8
  hkpLinkedCollidable *v6; // rdx
  __int64 v7; // rax
  signed __int64 v8; // rbx
  hkpBroadPhaseHandle **v9; // rcx
  hkpProcessCollisionInput *v10; // r8
  char v11; // al

  v2 = this->m_simulation;
  v3 = pair;
  v4 = (hkpLinkedCollidable *)((char *)pair->m_a + SBYTE1(pair->m_a[1].m_id));
  v5 = v4->m_ownerOffset;
  v6 = (hkpLinkedCollidable *)((char *)pair->m_b + SBYTE1(pair->m_b[1].m_id));
  v7 = v6->m_ownerOffset;
  if ( v2->m_crossIslandPairsCollectingActive.m_bool
    && *((_BYTE *)&v4[2].m_boundingVolumeData.m_childShapeKeys + v5) != 5
    && *((_BYTE *)&v6[2].m_boundingVolumeData.m_childShapeKeys + v7) != 5
    && *(_QWORD *)(&v4[2].m_broadPhaseHandle.m_type + v5) != *(_QWORD *)(&v6[2].m_broadPhaseHandle.m_type + v7) )
  {
    v8 = (signed __int64)&v2->m_addedCrossIslandPairs;
    if ( v2->m_addedCrossIslandPairs.m_size == (v2->m_addedCrossIslandPairs.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v2->m_addedCrossIslandPairs,
        16);
    v9 = (hkpBroadPhaseHandle **)(*(_QWORD *)v8 + 16i64 * *(signed int *)(v8 + 8));
    if ( v9 )
    {
      *v9 = v3->m_a;
      v9[1] = v3->m_b;
    }
    ++*(_DWORD *)(v8 + 8);
  }
  else
  {
    v10 = v2->m_world->m_collisionInput;
    v11 = v10->m_dispatcher.m_storage->m_collisionQualityTable[v4->m_broadPhaseHandle.m_objectQualityType][v6->m_broadPhaseHandle.m_objectQualityType];
    if ( v11 )
    {
      v10->m_createPredictiveAgents.m_storage = v10->m_dispatcher.m_storage->m_collisionQualityInfo[(signed __int64)v11].m_useContinuousPhysics.m_storage;
      hkpWorldAgentUtil::addAgent(v4, v6, v10);
    }
  }
}

// File Line: 327
// RVA: 0xD74CB0
void __fastcall hkpMultiThreadedSimulation::MtEntityEntityBroadPhaseListener::removeCollisionPair(hkpMultiThreadedSimulation::MtEntityEntityBroadPhaseListener *this, hkpTypedBroadPhaseHandlePair *pair)
{
  hkpMultiThreadedSimulation *v2; // rbx
  hkpTypedBroadPhaseHandlePair *v3; // rdi
  hkpLinkedCollidable *v4; // r9
  __int64 v5; // r8
  hkpLinkedCollidable *v6; // rdx
  __int64 v7; // rax
  hkArray<hkpTypedBroadPhaseHandlePair,hkContainerHeapAllocator> *v8; // rbx
  hkpBroadPhaseHandle **v9; // rcx
  hkpAgentNnEntry *v10; // rax

  v2 = this->m_simulation;
  v3 = pair;
  v4 = (hkpLinkedCollidable *)((char *)pair->m_a + SBYTE1(pair->m_a[1].m_id));
  v5 = v4->m_ownerOffset;
  v6 = (hkpLinkedCollidable *)((char *)pair->m_b + SBYTE1(pair->m_b[1].m_id));
  v7 = v6->m_ownerOffset;
  if ( v2->m_crossIslandPairsCollectingActive.m_bool
    && *((_BYTE *)&v4[2].m_boundingVolumeData.m_childShapeKeys + v5) != 5
    && *((_BYTE *)&v6[2].m_boundingVolumeData.m_childShapeKeys + v7) != 5
    && *(_QWORD *)(&v4[2].m_broadPhaseHandle.m_type + v5) != *(_QWORD *)(&v6[2].m_broadPhaseHandle.m_type + v7) )
  {
    v8 = &v2->m_removedCrossIslandPairs;
    if ( v8->m_size == (v8->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, 16);
    v9 = &v8->m_data[v8->m_size].m_a;
    if ( v9 )
    {
      *v9 = v3->m_a;
      v9[1] = v3->m_b;
    }
    ++v8->m_size;
  }
  else
  {
    v10 = hkAgentNnMachine_FindAgent(v4, v6);
    if ( v10 )
      hkpWorldAgentUtil::removeAgent(v10);
  }
}

// File Line: 369
// RVA: 0xD74E90
void __fastcall hkpMultiThreadedSimulation::MtBroadPhaseBorderListener::addCollisionPair(hkpMultiThreadedSimulation::MtBroadPhaseBorderListener *this, hkpTypedBroadPhaseHandlePair *pair)
{
  hkpTypedBroadPhaseHandlePair *v2; // rbx
  hkpBroadPhaseHandle *v3; // rdx
  char *v4; // rax
  hkpBroadPhaseHandle *v5; // rcx
  char *v6; // rcx

  v2 = pair;
  v3 = pair->m_a;
  if ( LOBYTE(v3[1].m_id) == 3 )
  {
    if ( LOBYTE(v2->m_b[1].m_id) == 3 )
      return;
    v4 = (char *)v3 + SBYTE1(v3[1].m_id);
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)&v4[v4[32]] + 64i64))(
      &v4[v4[32]],
      (char *)v2->m_b + SBYTE1(v2->m_b[1].m_id));
  }
  v5 = v2->m_b;
  if ( LOBYTE(v5[1].m_id) == 3 )
  {
    v6 = (char *)v5 + SBYTE1(v5[1].m_id) + *((char *)&v5[8].m_id + SBYTE1(v5[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v6 + 64i64))(v6, (char *)v2->m_a + SBYTE1(v2->m_a[1].m_id));
  }
}

// File Line: 399
// RVA: 0xD74F20
void __fastcall hkpMultiThreadedSimulation::MtBroadPhaseBorderListener::removeCollisionPair(hkpMultiThreadedSimulation::MtBroadPhaseBorderListener *this, hkpTypedBroadPhaseHandlePair *pair)
{
  hkpTypedBroadPhaseHandlePair *v2; // rbx
  hkpBroadPhaseHandle *v3; // rdx
  char *v4; // rax
  hkpBroadPhaseHandle *v5; // rcx
  char *v6; // rcx

  v2 = pair;
  v3 = pair->m_a;
  if ( LOBYTE(v3[1].m_id) == 3 )
  {
    if ( LOBYTE(v2->m_b[1].m_id) == 3 )
      return;
    v4 = (char *)v3 + SBYTE1(v3[1].m_id);
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)&v4[v4[32]] + 80i64))(
      &v4[v4[32]],
      (char *)v2->m_b + SBYTE1(v2->m_b[1].m_id));
  }
  v5 = v2->m_b;
  if ( LOBYTE(v5[1].m_id) == 3 )
  {
    v6 = (char *)v5 + SBYTE1(v5[1].m_id) + *((char *)&v5[8].m_id + SBYTE1(v5[1].m_id));
    (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v6 + 80i64))(v6, (char *)v2->m_a + SBYTE1(v2->m_a[1].m_id));
  }
}

// File Line: 442
// RVA: 0xD72100
void __fastcall hkpMultiThreadedSimulation::hkpMultiThreadedSimulation(hkpMultiThreadedSimulation *this, hkpWorld *world)
{
  hkpWorld *v2; // rbp
  hkpMultiThreadedSimulation *v3; // r15
  hkpMultiThreadedSimulation::MtEntityEntityBroadPhaseListener *v4; // rdi
  hkpMultiThreadedSimulation::MtPhantomBroadPhaseListener *v5; // rsi
  hkpMultiThreadedSimulation::MtBroadPhaseBorderListener *v6; // r14

  v2 = world;
  v3 = this;
  hkpContinuousSimulation::hkpContinuousSimulation((hkpContinuousSimulation *)&this->vfptr, world);
  v4 = &v3->m_entityEntityBroadPhaseListener;
  v3->vfptr = (hkBaseObjectVtbl *)&hkpMultiThreadedSimulation::`vftable';
  v4->m_simulation = 0i64;
  v4->vfptr = (hkpBroadPhaseListenerVtbl *)&hkpMultiThreadedSimulation::MtEntityEntityBroadPhaseListener::`vftable';
  v5 = &v3->m_phantomBroadPhaseListener;
  v5->vfptr = (hkpBroadPhaseListenerVtbl *)&hkpMultiThreadedSimulation::MtPhantomBroadPhaseListener::`vftable';
  v5->m_criticalSection = 0i64;
  v6 = &v3->m_broadPhaseBorderListener;
  v6->m_criticalSection = 0i64;
  v6->vfptr = (hkpBroadPhaseListenerVtbl *)&hkpMultiThreadedSimulation::MtBroadPhaseBorderListener::`vftable';
  v3->m_addedCrossIslandPairs.m_data = 0i64;
  v3->m_addedCrossIslandPairs.m_size = 0;
  v3->m_addedCrossIslandPairs.m_capacityAndFlags = 2147483648;
  hkCriticalSection::hkCriticalSection(&v3->m_addCrossIslandPairCriticalSection, 4000);
  v3->m_removedCrossIslandPairs.m_data = 0i64;
  v3->m_removedCrossIslandPairs.m_size = 0;
  v3->m_removedCrossIslandPairs.m_capacityAndFlags = 2147483648;
  hkCriticalSection::hkCriticalSection(&v3->m_removeCrossIslandPairCriticalSection, 4000);
  hkpMultithreadConfig::hkpMultithreadConfig(&v3->m_multithreadConfig);
  hkCriticalSection::hkCriticalSection(&v3->m_toiQueueCriticalSection, 4000);
  hkCriticalSection::hkCriticalSection(&v3->m_phantomCriticalSection, 4000);
  v3->m_jobQueueHandleForToiSolve = 0i64;
  v3->m_crossIslandPairsCollectingActive.m_bool = 0;
  hkpBroadPhase::enableMultiThreading(v3->m_world->m_broadPhase, 10000);
  v3->m_phantomBroadPhaseListener.m_criticalSection = &v3->m_phantomCriticalSection;
  v3->m_entityEntityBroadPhaseListener.m_simulation = v3;
  v2->m_broadPhaseDispatcher->m_broadPhaseListeners[1][1] = (hkpBroadPhaseListener *)&v3->m_entityEntityBroadPhaseListener.vfptr;
  v2->m_broadPhaseDispatcher->m_broadPhaseListeners[2][1] = (hkpBroadPhaseListener *)&v3->m_phantomBroadPhaseListener.vfptr;
  v2->m_broadPhaseDispatcher->m_broadPhaseListeners[1][2] = (hkpBroadPhaseListener *)&v3->m_phantomBroadPhaseListener.vfptr;
  v2->m_broadPhaseDispatcher->m_broadPhaseListeners[2][2] = (hkpBroadPhaseListener *)&v3->m_phantomBroadPhaseListener.vfptr;
  v3->m_broadPhaseBorderListener.m_criticalSection = &v3->m_phantomCriticalSection;
  v2->m_broadPhaseDispatcher->m_broadPhaseListeners[1][3] = (hkpBroadPhaseListener *)&v3->m_broadPhaseBorderListener.vfptr;
  v2->m_broadPhaseDispatcher->m_broadPhaseListeners[3][1] = (hkpBroadPhaseListener *)&v3->m_broadPhaseBorderListener.vfptr;
  v2->m_broadPhaseDispatcher->m_broadPhaseListeners[2][3] = (hkpBroadPhaseListener *)&v3->m_broadPhaseBorderListener.vfptr;
  v2->m_broadPhaseDispatcher->m_broadPhaseListeners[3][2] = (hkpBroadPhaseListener *)&v3->m_broadPhaseBorderListener.vfptr;
  v2->m_broadPhaseDispatcher->m_broadPhaseListeners[3][3] = (hkpBroadPhaseListener *)&v3->m_broadPhaseBorderListener.vfptr;
}

// File Line: 470
// RVA: 0xD722D0
void __fastcall hkpMultiThreadedSimulation::~hkpMultiThreadedSimulation(hkpMultiThreadedSimulation *this)
{
  hkpMultiThreadedSimulation *v1; // rbx
  _RTL_CRITICAL_SECTION *v2; // rcx
  int v3; // er8
  int v4; // er8

  v1 = this;
  v2 = &this->m_phantomCriticalSection.m_section;
  v2[-10].OwningThread = &hkpMultiThreadedSimulation::`vftable';
  DeleteCriticalSection(v2);
  DeleteCriticalSection(&v1->m_toiQueueCriticalSection.m_section);
  DeleteCriticalSection(&v1->m_removeCrossIslandPairCriticalSection.m_section);
  v3 = v1->m_removedCrossIslandPairs.m_capacityAndFlags;
  v1->m_removedCrossIslandPairs.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_removedCrossIslandPairs.m_data,
      16 * v3);
  v1->m_removedCrossIslandPairs.m_data = 0i64;
  v1->m_removedCrossIslandPairs.m_capacityAndFlags = 2147483648;
  DeleteCriticalSection(&v1->m_addCrossIslandPairCriticalSection.m_section);
  v4 = v1->m_addedCrossIslandPairs.m_capacityAndFlags;
  v1->m_addedCrossIslandPairs.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_addedCrossIslandPairs.m_data,
      16 * v4);
  v1->m_addedCrossIslandPairs.m_data = 0i64;
  v1->m_addedCrossIslandPairs.m_capacityAndFlags = 2147483648;
  v1->m_broadPhaseBorderListener.vfptr = (hkpBroadPhaseListenerVtbl *)&hkpBroadPhaseListener::`vftable';
  v1->m_phantomBroadPhaseListener.vfptr = (hkpBroadPhaseListenerVtbl *)&hkpBroadPhaseListener::`vftable';
  v1->m_entityEntityBroadPhaseListener.vfptr = (hkpBroadPhaseListenerVtbl *)&hkpBroadPhaseListener::`vftable';
  hkpContinuousSimulation::~hkpContinuousSimulation((hkpContinuousSimulation *)&v1->vfptr);
}

// File Line: 474
// RVA: 0xD723E0
void __fastcall hkpMultiThreadedSimulation::create(hkpWorld *world)
{
  hkpWorld *v1; // rbx
  _QWORD **v2; // rax
  hkpMultiThreadedSimulation *v3; // rax

  v1 = world;
  hkOptionalComponent_hkpMultiThreadedSimulation.m_isUsed.m_bool = 1;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpMultiThreadedSimulation *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                       v2[11],
                                       448i64);
  if ( v3 )
    hkpMultiThreadedSimulation::hkpMultiThreadedSimulation(v3, v1);
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
  int v4; // er10
  int v5; // er9
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
  hkpTypedBroadPhaseHandlePair *v1; // rax
  hkpTypedBroadPhaseHandlePair *v2; // r8
  hkpBroadPhaseHandle *v3; // r9
  hkpBroadPhaseHandle *v4; // r10
  int v5; // er8

  v1 = pairs->m_data;
  v2 = &pairs->m_data[pairs->m_size];
  if ( pairs->m_data < v2 )
  {
    do
    {
      v3 = v1->m_b;
      v4 = v1->m_a;
      if ( *(signed int *)((char *)&v1->m_a[9].m_id + SBYTE1(v1->m_a[1].m_id)) > *(signed int *)((char *)&v3[9].m_id
                                                                                               + SBYTE1(v3[1].m_id)) )
      {
        v1->m_a = v3;
        v1->m_b = v4;
      }
      ++v1;
    }
    while ( v1 < v2 );
  }
  v5 = pairs->m_size;
  if ( v5 > 1 )
    hkAlgorithm::quickSortRecursive<hkaiGeometryToEdgeGeometryConverter::TriangleArea,bool (*)(hkaiGeometryToEdgeGeometryConverter::TriangleArea const &,hkaiGeometryToEdgeGeometryConverter::TriangleArea const &)>(
      pairs->m_data,
      0,
      v5 - 1,
      pairLessThan);
}

// File Line: 571
// RVA: 0xD72450
signed __int64 __fastcall hkpMultiThreadedSimulation::stepBeginSt(hkpMultiThreadedSimulation *this, hkJobQueue *jobQueue, float physicsDeltaTime)
{
  hkpMultiThreadedSimulation *v3; // rbx
  hkJobQueue *v4; // r14
  _QWORD *v5; // rax
  unsigned __int64 v6; // rcx
  _QWORD *v7; // r8
  unsigned __int64 v8; // rax
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  __m128i *v12; // rax
  hkMemorySystem *v13; // rax
  hkWorldMemoryAvailableWatchDog *v14; // rax
  hkpWorld *v15; // rdi
  bool v16; // zf
  __m128 *v17; // rcx
  float v18; // xmm1_4
  hkpWorld *v19; // rax
  hkpMtThreadStructure *v20; // r8
  hkpProcessCollisionInput *v21; // rcx
  hkpWorld *v22; // rdx
  hkpViolatedConstraintArray *v23; // rcx
  hkpWorld *v24; // rax
  int v25; // edi
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  signed __int64 v29; // rcx
  hkpWorld *v30; // rax
  hkpWorld *v31; // rcx
  char v32; // al
  hkpSolverInfo *v33; // rcx
  hkpWorld *v34; // rcx
  _QWORD *v35; // r8
  _QWORD *v36; // rcx
  unsigned __int64 v37; // rax
  signed __int64 v38; // rcx
  __m128i v40; // [rsp+20h] [rbp-29h]
  hkWorldMemoryAvailableWatchDog::MemUsageInfo infoOut; // [rsp+30h] [rbp-19h]
  hkJob job; // [rsp+40h] [rbp-9h]
  __int16 v43; // [rsp+50h] [rbp+7h]
  __int64 v44; // [rsp+58h] [rbp+Fh]
  __int64 v45; // [rsp+60h] [rbp+17h]
  hkpMtThreadStructure *v46; // [rsp+68h] [rbp+1Fh]
  int v47; // [rsp+70h] [rbp+27h]

  v3 = this;
  v4 = jobQueue;
  v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = v5[1];
  v7 = v5;
  if ( v6 < v5[3] )
  {
    *(_QWORD *)v6 = "LtPhysics 2012";
    *(_QWORD *)(v6 + 16) = "StInit";
    v8 = __rdtsc();
    *(_DWORD *)(v6 + 8) = v8;
    v7[1] = v6 + 24;
  }
  v3->m_crossIslandPairsCollectingActive.m_bool = 1;
  ++v3->m_world->m_criticalOperationsLockCount;
  v9 = v3->m_currentPsiTime;
  v3->m_physicsDeltaTime = physicsDeltaTime;
  *(float *)v40.m128i_i32 = v9;
  *(float *)&v40.m128i_i32[1] = v9 + physicsDeltaTime;
  v10 = (float)(v9 + physicsDeltaTime) - v9;
  v11 = 0.0;
  *(float *)&v40.m128i_i32[2] = v10;
  if ( v10 != 0.0 )
    v11 = 1.0 / v10;
  v12 = (__m128i *)v3->m_world;
  *(float *)&v40.m128i_i32[3] = v11;
  _mm_store_si128(v12 + 42, v40);
  _mm_store_si128((__m128i *)&v3->m_world->m_collisionInput->m_stepInfo, v40);
  ((void (__fastcall *)(hkpWorldMaintenanceMgr *, hkpWorld *, __m128i *))v3->m_world->m_maintenanceMgr->vfptr[2].__first_virtual_table_function__)(
    v3->m_world->m_maintenanceMgr,
    v3->m_world,
    &v40);
  hkpWorld::calcRequiredSolverBufferSize(v3->m_world, &infoOut);
  v13 = hkMemorySystem::getInstance();
  if ( v13->vfptr->solverCanAllocSingleBlock(v13, infoOut.m_maxRuntimeBlockSize) )
    goto LABEL_15;
  v14 = hkpWorld::getMemoryWatchDog(v3->m_world);
  v15 = v3->m_world;
  if ( v14 )
  {
    v16 = v15->m_criticalOperationsLockCount-- == 1;
    if ( v16 && !v15->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v15->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v15);
      if ( v15->m_pendingOperationQueueCount == 1 && v15->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v15);
    }
    hkpWorldMemoryUtil::checkMemoryForIntegration(v3->m_world);
    ++v3->m_world->m_criticalOperationsLockCount;
LABEL_15:
    _mm_store_si128((__m128i *)&v3->m_world->m_dynamicsStepInfo, v40);
    v17 = (__m128 *)&v3->m_world->m_dynamicsStepInfo.m_solverInfo;
    v18 = (float)v3->m_world->m_dynamicsStepInfo.m_solverInfo.m_numSteps;
    v17[18].m128_f32[1] = *(float *)&v40.m128i_i32[2] * v3->m_world->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
    v17[18].m128_f32[2] = v18 * *(float *)&v40.m128i_i32[3];
    v17[1] = _mm_mul_ps(
               _mm_shuffle_ps((__m128)v17[18].m128_u32[1], (__m128)v17[18].m128_u32[1], 0),
               v3->m_world->m_gravity.m_quad);
    v17[2] = _mm_mul_ps(
               _mm_shuffle_ps((__m128)v40.m128i_u32[2], (__m128)v40.m128i_u32[2], 0),
               v3->m_world->m_gravity.m_quad);
    v3->m_world->m_violatedConstraintArray->m_nextFreeElement = 0;
    v19 = v3->m_world;
    v20 = v19->m_multithreadedSimulationJobData;
    v20->m_dynamicsStepInfo.m_storage = &v19->m_dynamicsStepInfo;
    v21 = v3->m_world->m_collisionInput;
    v20->m_collisionInput.m_dispatcher.m_storage = v21->m_dispatcher.m_storage;
    v20->m_collisionInput.m_weldClosestPoints.m_storage = v21->m_weldClosestPoints.m_storage;
    v20->m_collisionInput.m_forceAcceptContactPoints.m_storage = v21->m_forceAcceptContactPoints.m_storage;
    v20->m_collisionInput.m_tolerance.m_storage = v21->m_tolerance.m_storage;
    v20->m_collisionInput.m_filter.m_storage = v21->m_filter.m_storage;
    v20->m_collisionInput.m_convexListFilter.m_storage = v21->m_convexListFilter.m_storage;
    v20->m_collisionInput.m_createPredictiveAgents.m_storage = v21->m_createPredictiveAgents.m_storage;
    v20->m_collisionInput.m_aabb32Info.m_bitOffsetLow = v21->m_aabb32Info.m_bitOffsetLow;
    v20->m_collisionInput.m_aabb32Info.m_bitOffsetHigh = v21->m_aabb32Info.m_bitOffsetHigh;
    v20->m_collisionInput.m_aabb32Info.m_bitScale = v21->m_aabb32Info.m_bitScale;
    _mm_store_si128((__m128i *)&v20->m_collisionInput.m_stepInfo, (__m128i)v21->m_stepInfo);
    v20->m_collisionInput.m_collisionQualityInfo.m_storage = v21->m_collisionQualityInfo.m_storage;
    v20->m_collisionInput.m_dynamicsInfo = v21->m_dynamicsInfo;
    v20->m_collisionInput.m_enableDeprecatedWelding.m_bool = v21->m_enableDeprecatedWelding.m_bool;
    v20->m_collisionInput.m_allowToSkipConfirmedCallbacks.m_bool = v21->m_allowToSkipConfirmedCallbacks.m_bool;
    v20->m_collisionInput.m_config = v21->m_config;
    v22 = v3->m_world;
    v23 = v22->m_violatedConstraintArray;
    v20->m_constraintQueryIn.m_subStepDeltaTime.m_storage = v22->m_dynamicsStepInfo.m_solverInfo.m_deltaTime;
    v20->m_constraintQueryIn.m_microStepDeltaTime.m_storage = v22->m_dynamicsStepInfo.m_solverInfo.m_invNumMicroSteps
                                                            * v22->m_dynamicsStepInfo.m_solverInfo.m_deltaTime;
    v20->m_constraintQueryIn.m_subStepInvDeltaTime.m_storage = v22->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
    v20->m_constraintQueryIn.m_invNumSteps.m_storage = v22->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
    v20->m_constraintQueryIn.m_invNumStepsTimesMicroSteps.m_storage = v22->m_dynamicsStepInfo.m_solverInfo.m_invNumMicroSteps
                                                                    * v22->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
    v20->m_constraintQueryIn.m_tau.m_storage = v22->m_dynamicsStepInfo.m_solverInfo.m_tau;
    *(float *)&v19 = v22->m_dynamicsStepInfo.m_solverInfo.m_damping;
    v20->m_constraintQueryIn.m_violatedConstraints.m_storage = v23;
    LODWORD(v20->m_constraintQueryIn.m_damping.m_storage) = (_DWORD)v19;
    v20->m_constraintQueryIn.m_rhsFactor.m_storage = v22->m_dynamicsStepInfo.m_solverInfo.m_tauDivDamp
                                                   * v22->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
    v20->m_constraintQueryIn.m_virtMassFactor.m_storage = v22->m_dynamicsStepInfo.m_solverInfo.m_damping;
    v20->m_constraintQueryIn.m_frictionRhsFactor.m_storage = v22->m_dynamicsStepInfo.m_solverInfo.m_frictionTauDivDamp
                                                           * v22->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
    v20->m_constraintQueryIn.m_frameDeltaTime.m_storage = v22->m_dynamicsStepInfo.m_stepInfo.m_deltaTime.m_storage;
    v20->m_constraintQueryIn.m_frameInvDeltaTime.m_storage = v22->m_dynamicsStepInfo.m_stepInfo.m_invDeltaTime.m_storage;
    v20->m_constraintQueryIn.m_maxConstraintViolationSqrd.m_real = _mm_shuffle_ps(
                                                                     (__m128)LODWORD(v22->m_dynamicsStepInfo.m_solverInfo.m_maxConstraintViolationSqrd),
                                                                     (__m128)LODWORD(v22->m_dynamicsStepInfo.m_solverInfo.m_maxConstraintViolationSqrd),
                                                                     0);
    v20->m_simulation.m_storage = v3;
    v20->m_tolerance.m_storage = v3->m_world->m_collisionInput->m_tolerance.m_storage;
    v20->m_weldingTable.m_storage = hkpWeldingUtility::m_sinCosTable;
    v20->m_world = v3->m_world;
    v24 = v3->m_world;
    v25 = v24->m_activeSimulationIslands.m_size;
    if ( v25 > 0 )
    {
      if ( v24->m_processActionsInSingleThread.m_bool )
      {
        v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v27 = (_QWORD *)v26[1];
        if ( (unsigned __int64)v27 < v26[3] )
        {
          *v27 = "StActions";
          v28 = __rdtsc();
          v29 = (signed __int64)(v27 + 2);
          *(_DWORD *)(v29 - 8) = v28;
          v26[1] = v29;
        }
        --v3->m_world->m_criticalOperationsLockCountForPhantoms;
        hkpSimulation::applyActions((hkpSimulation *)&v3->vfptr);
        ++v3->m_world->m_criticalOperationsLockCountForPhantoms;
      }
      *(_WORD *)&job.m_jobSubType = 0;
      job.m_jobSpuType.m_storage = 2;
      job.m_size = 64;
      v44 = 0i64;
      job.m_threadAffinity = -1;
      v30 = v3->m_world;
      v45 = 0i64;
      v43 = 0;
      v47 = v25;
      v46 = v30->m_multithreadedSimulationJobData;
      hkJobQueue::setQueueCapacityForJobType(v4, 0, v25);
      hkJobQueue::setQueueCapacityForJobType(v4, HK_JOB_TYPE_COLLIDE, v25);
      hkJobQueue::addJob(v4, &job, JOB_LOW_PRIORITY);
    }
    v31 = v3->m_world;
    v32 = ++v31->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter;
    v33 = &v31->m_dynamicsStepInfo.m_solverInfo;
    if ( !((v32 - 4) & 7) )
      v33->m_deactivationNumInactiveFramesSelectFlag[0] ^= 1u;
    if ( !(v33->m_deactivationIntegrateCounter & 7) )
      v33->m_deactivationNumInactiveFramesSelectFlag[0] ^= 2u;
    if ( !(v33->m_deactivationIntegrateCounter & 0xF) )
    {
      v33->m_deactivationNumInactiveFramesSelectFlag[1] = 1 - v33->m_deactivationNumInactiveFramesSelectFlag[1];
      v33->m_deactivationIntegrateCounter = 0;
    }
    v34 = v3->m_world;
    v3->m_numActiveIslandsAtBeginningOfStep = v34->m_activeSimulationIslands.m_size;
    v3->m_numInactiveIslandsAtBeginningOfStep = v34->m_inactiveSimulationIslands.m_size;
    hkpWorld::checkDeterminism(v34);
    v35 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v36 = (_QWORD *)v35[1];
    if ( (unsigned __int64)v36 < v35[3] )
    {
      *v36 = "lt";
      v37 = __rdtsc();
      v38 = (signed __int64)(v36 + 2);
      *(_DWORD *)(v38 - 8) = v37;
      v35[1] = v38;
    }
    return 0i64;
  }
  if ( v15->m_assertOnRunningOutOfSolverMemory.m_bool )
    __debugbreak();
  v3->m_previousStepResult = 1;
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
__int64 __fastcall hkpMultiThreadedSimulation::finishMtStep(hkpMultiThreadedSimulation *this, hkJobQueue *jobQueue, hkJobThreadPool *threadPool)
{
  hkpMultiThreadedSimulation *v3; // rbx
  hkJobThreadPool *v4; // r14
  hkJobQueue *v5; // rsi
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  signed int v11; // ebp
  hkpWorld *v12; // rax
  __int64 v13; // rcx
  signed int v14; // er8
  int i; // er8
  float v16; // xmm7_4
  _QWORD *v17; // r8
  unsigned __int64 v18; // rcx
  unsigned __int64 v19; // rax
  signed __int64 v20; // r15
  signed __int64 v21; // r13
  _QWORD *v22; // r8
  _QWORD *v23; // rcx
  unsigned __int64 v24; // rax
  signed __int64 v25; // rcx
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  signed __int64 v29; // rcx
  int v30; // er14
  __int64 v31; // r12
  hkpLinkedCollidable *v32; // rdi
  __int64 v33; // r15
  hkpConstraintOwner *v34; // rcx
  hkpLinkedCollidable *v35; // rsi
  hkpSimulationIsland *v36; // r8
  hkpWorld *v37; // rax
  hkpProcessCollisionInput *v38; // r8
  char v39; // al
  hkpAgentNnEntry *v40; // rax
  hkpAgentNnEntry *v41; // rdi
  hkpLinkedCollidable *v42; // r15
  hkpLinkedCollidable *v43; // r13
  hkpProcessCollisionInput *v44; // rsi
  signed __int64 v45; // rdx
  _QWORD *v46; // rax
  _QWORD *v47; // rcx
  _QWORD *v48; // r8
  unsigned __int64 v49; // rax
  signed __int64 v50; // rcx
  int v51; // esi
  __int64 v52; // rdi
  hkpAgentNnEntry *v53; // rax
  _QWORD *v54; // rax
  _QWORD *v55; // rcx
  _QWORD *v56; // r8
  unsigned __int64 v57; // rax
  signed __int64 v58; // rcx
  hkpWorld *v59; // rdi
  bool v60; // zf
  hkpWorld *v61; // rcx
  _QWORD *v62; // r8
  _QWORD *v63; // rcx
  unsigned __int64 v64; // rax
  signed __int64 v65; // rcx
  _QWORD *v66; // r8
  _QWORD *v67; // rcx
  unsigned __int64 v68; // rax
  signed __int64 v69; // rcx
  hkpWorld *v70; // rcx
  _QWORD *v71; // r8
  _QWORD *v72; // rcx
  unsigned __int64 v73; // rax
  signed __int64 v74; // rcx
  _QWORD *v75; // r8
  _QWORD *v76; // rcx
  unsigned __int64 v77; // rax
  signed __int64 v78; // rcx
  hkpWorld *v79; // rcx
  _QWORD *v80; // r8
  _QWORD *v81; // rcx
  unsigned __int64 v82; // rax
  signed __int64 v83; // rcx
  _QWORD *v84; // r8
  _QWORD *v85; // rcx
  unsigned __int64 v86; // rax
  signed __int64 v87; // rcx
  hkStepInfo info; // [rsp+30h] [rbp-3108h]
  hkpProcessCollisionOutput output; // [rsp+40h] [rbp-30F8h]
  int flags; // [rsp+3140h] [rbp+8h]
  hkJobQueue *v92; // [rsp+3148h] [rbp+10h]
  hkJobThreadPool *v93; // [rsp+3150h] [rbp+18h]

  v93 = threadPool;
  v92 = jobQueue;
  v3 = this;
  v4 = threadPool;
  v5 = jobQueue;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtPhysics 2012";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  hkpWorld::lock(v3->m_world);
  v11 = 0;
  flags = 0;
  if ( v5 && v4 )
  {
    flags = hkJobQueue::getMasterThreadFinishingFlags(v5);
    hkJobQueue::setWaitPolicy(v5, WAIT_INDEFINITELY);
    hkJobQueue::setMasterThreadFinishingFlags(v5, 262146);
    ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, signed __int64))v4->vfptr[5].__first_virtual_table_function__)(
      v4,
      v5,
      20i64);
  }
  v12 = v3->m_world;
  v13 = v3->m_numActiveIslandsAtBeginningOfStep;
  v14 = v12->m_activeSimulationIslands.m_size - v13;
  if ( v14 > 1 )
    hkAlgorithm::quickSortRecursive<hkFreeList::Element *,hkBool (*)(hkFreeList::Element const *,hkFreeList::Element const *)>(
      (hkpRigidBody **)&v12->m_activeSimulationIslands.m_data[v13],
      0,
      v14 - 1,
      (hkBool *(__fastcall *)(hkBool *, hkpRigidBody *, hkpRigidBody *))less_hkSimulationIslandPtr);
  for ( i = v3->m_numActiveIslandsAtBeginningOfStep; i < v3->m_world->m_activeSimulationIslands.m_size; ++i )
    v3->m_world->m_activeSimulationIslands.m_data[i]->m_storageIndex = i;
  hkpWorld::checkDeterminism(v3->m_world);
  v16 = 0.0;
  if ( v3->m_addedCrossIslandPairs.m_size + v3->m_removedCrossIslandPairs.m_size )
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
    v20 = (signed __int64)&v3->m_removedCrossIslandPairs;
    v21 = (signed __int64)&v3->m_addedCrossIslandPairs;
    hkpTypedBroadPhaseDispatcher::removeDuplicates(
      (hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *)&v3->m_addedCrossIslandPairs,
      (hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *)&v3->m_removedCrossIslandPairs);
    v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v23 = (_QWORD *)v22[1];
    if ( (unsigned __int64)v23 < v22[3] )
    {
      *v23 = "StsortPairs";
      v24 = __rdtsc();
      v25 = (signed __int64)(v23 + 2);
      *(_DWORD *)(v25 - 8) = v24;
      v22[1] = v25;
    }
    sortPairList(&v3->m_addedCrossIslandPairs);
    sortPairList(&v3->m_removedCrossIslandPairs);
    v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v27 = (_QWORD *)v26[1];
    if ( (unsigned __int64)v27 < v26[3] )
    {
      *v27 = "StaddAgt";
      v28 = __rdtsc();
      v29 = (signed __int64)(v27 + 2);
      *(_DWORD *)(v29 - 8) = v28;
      v26[1] = v29;
    }
    output.m_toi.m_time.m_storage = 3.40282e38;
    output.m_toi.m_properties.0 = 0i64;
    output.m_constraintOwner.m_storage = 0i64;
    v30 = 0;
    if ( v3->m_addedCrossIslandPairs.m_size > 0 )
    {
      v31 = 0i64;
      do
      {
        v32 = (hkpLinkedCollidable *)(*(_QWORD *)(*(_QWORD *)v21 + v31)
                                    + *(char *)(*(_QWORD *)(*(_QWORD *)v21 + v31) + 5i64));
        v33 = v32->m_ownerOffset;
        v34 = *(hkpConstraintOwner **)(&v32[2].m_broadPhaseHandle.m_type + v33);
        v35 = (hkpLinkedCollidable *)(*(_QWORD *)(*(_QWORD *)v21 + v31 + 8)
                                    + *(char *)(*(_QWORD *)(*(_QWORD *)v21 + v31 + 8) + 5i64));
        v36 = *(hkpSimulationIsland **)(&v35[2].m_broadPhaseHandle.m_type + v35->m_ownerOffset);
        if ( v34 != (hkpConstraintOwner *)v36 )
        {
          hkpWorldOperationUtil::internalMergeTwoIslands(
            v3->m_world,
            *(hkpSimulationIsland **)(&v32[2].m_broadPhaseHandle.m_type + v33),
            v36);
          v34 = *(hkpConstraintOwner **)(&v32[2].m_broadPhaseHandle.m_type + v33);
        }
        v37 = v3->m_world;
        output.m_constraintOwner.m_storage = v34;
        v38 = v37->m_collisionInput;
        v39 = v38->m_dispatcher.m_storage->m_collisionQualityTable[v32->m_broadPhaseHandle.m_objectQualityType][v35->m_broadPhaseHandle.m_objectQualityType];
        if ( v39 )
        {
          v38->m_createPredictiveAgents.m_storage = v38->m_dispatcher.m_storage->m_collisionQualityInfo[(signed __int64)v39].m_useContinuousPhysics.m_storage;
          v40 = hkpWorldAgentUtil::addAgent(v32, v35, v38);
          v41 = v40;
          if ( v40 )
          {
            v42 = v40->m_collidable[0];
            v43 = v40->m_collidable[1];
            v44 = v3->m_world->m_collisionInput;
            v45 = (signed __int64)v44->m_dispatcher.m_storage + 64 * (v40->m_collisionQualityIndex + 161i64);
            v44->m_collisionQualityInfo.m_storage = (hkpCollisionQualityInfo *)v45;
            v44->m_createPredictiveAgents.m_storage = *(_DWORD *)(v45 + 16);
            output.m_toi.m_time.m_storage = 3.40282e38;
            output.m_firstFreeContactPoint.m_storage = output.m_contactPoints;
            output.m_potentialContacts.m_storage = 0i64;
            hkAgentNnMachine_ProcessAgent(v40, v44, &output, v40->m_contactMgr, v31);
            if ( output.m_firstFreeContactPoint.m_storage != output.m_contactPoints )
              ((void (__fastcall *)(hkpContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))v41->m_contactMgr->vfptr[3].__vecDelDtor)(
                v41->m_contactMgr,
                v42,
                v43,
                v44,
                &output);
            if ( output.m_toi.m_time.m_storage != 3.40282e38 )
              hkpMultiThreadedSimulation::addToiEventWithCriticalSectionLock(
                v3,
                &output,
                v41,
                &v3->m_toiQueueCriticalSection);
            v21 = (signed __int64)&v3->m_addedCrossIslandPairs;
          }
        }
        if ( hkOutOfMemoryState == 1 )
          break;
        ++v30;
        v31 += 16i64;
      }
      while ( v30 < v3->m_addedCrossIslandPairs.m_size );
      v20 = (signed __int64)&v3->m_removedCrossIslandPairs;
    }
    *(_DWORD *)(v21 + 8) = 0;
    v46 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v47 = (_QWORD *)v46[1];
    v48 = v46;
    if ( (unsigned __int64)v47 < v46[3] )
    {
      *v47 = "StremoveAgt";
      v49 = __rdtsc();
      v50 = (signed __int64)(v47 + 2);
      *(_DWORD *)(v50 - 8) = v49;
      v48[1] = v50;
    }
    v51 = 0;
    if ( v3->m_removedCrossIslandPairs.m_size > 0 )
    {
      v52 = 0i64;
      do
      {
        v53 = hkAgentNnMachine_FindAgent(
                (hkpLinkedCollidable *)(*(_QWORD *)(v52 + *(_QWORD *)v20)
                                      + *(char *)(*(_QWORD *)(v52 + *(_QWORD *)v20) + 5i64)),
                (hkpLinkedCollidable *)(*(_QWORD *)(v52 + *(_QWORD *)v20 + 8)
                                      + *(char *)(*(_QWORD *)(v52 + *(_QWORD *)v20 + 8) + 5i64)));
        if ( v53 )
          hkpWorldAgentUtil::removeAgentAndItsToiEvents(v53);
        ++v51;
        v52 += 16i64;
      }
      while ( v51 < v3->m_removedCrossIslandPairs.m_size );
    }
    *(_DWORD *)(v20 + 8) = 0;
    v54 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v5 = v92;
    v55 = (_QWORD *)v54[1];
    v4 = v93;
    v56 = v54;
    if ( (unsigned __int64)v55 < v54[3] )
    {
      *v55 = "lt";
      v57 = __rdtsc();
      v58 = (signed __int64)(v55 + 2);
      *(_DWORD *)(v58 - 8) = v57;
      v56[1] = v58;
    }
  }
  v3->m_crossIslandPairsCollectingActive.m_bool = 0;
  hkpWorld::checkConstraintsViolated(v3->m_world);
  v59 = v3->m_world;
  v3->m_currentPsiTime = v3->m_physicsDeltaTime + v3->m_currentPsiTime;
  v60 = v59->m_criticalOperationsLockCount-- == 1;
  if ( v60 && !v59->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v59->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v59);
    if ( v59->m_pendingOperationQueueCount == 1 && v59->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(v59);
  }
  if ( hkOutOfMemoryState == 1 )
  {
    v61 = v3->m_world;
    v11 = 2;
    v3->m_currentPsiTime = v3->m_currentPsiTime - v3->m_physicsDeltaTime;
    hkpWorld::unlock(v61);
    v62 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v63 = (_QWORD *)v62[1];
    if ( (unsigned __int64)v63 < v62[3] )
    {
      *v63 = "Et";
      v64 = __rdtsc();
      v65 = (signed __int64)(v63 + 2);
      *(_DWORD *)(v65 - 8) = v64;
      v62[1] = v65;
    }
  }
  else
  {
    if ( v3->m_world->m_worldPostCollideListeners.m_size )
    {
      v66 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v67 = (_QWORD *)v66[1];
      if ( (unsigned __int64)v67 < v66[3] )
      {
        *v67 = "TtPostCollideCB";
        v68 = __rdtsc();
        v69 = (signed __int64)(v67 + 2);
        *(_DWORD *)(v69 - 8) = v68;
        v66[1] = v69;
      }
      info.m_endTime.m_storage = v3->m_currentPsiTime;
      info.m_startTime.m_storage = info.m_endTime.m_storage - v3->m_physicsDeltaTime;
      info.m_deltaTime.m_storage = info.m_endTime.m_storage - info.m_startTime.m_storage;
      if ( (float)(info.m_endTime.m_storage - info.m_startTime.m_storage) != 0.0 )
        v16 = 1.0 / (float)(info.m_endTime.m_storage - info.m_startTime.m_storage);
      v70 = v3->m_world;
      info.m_invDeltaTime.m_storage = v16;
      hkpWorldCallbackUtil::firePostCollideCallback(v70, &info);
      v71 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v72 = (_QWORD *)v71[1];
      if ( (unsigned __int64)v72 < v71[3] )
      {
        *v72 = "Et";
        v73 = __rdtsc();
        v74 = (signed __int64)(v72 + 2);
        *(_DWORD *)(v74 - 8) = v73;
        v71[1] = v74;
      }
    }
    hkpWorld::checkDeterminism(v3->m_world);
    v75 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v76 = (_QWORD *)v75[1];
    if ( (unsigned __int64)v76 < v75[3] )
    {
      *v76 = "Et";
      v77 = __rdtsc();
      v78 = (signed __int64)(v76 + 2);
      *(_DWORD *)(v78 - 8) = v77;
      v75[1] = v78;
    }
    v79 = v3->m_world;
    if ( v79->m_processToisMultithreaded.m_bool )
      v3->m_jobQueueHandleForToiSolve = v5;
    hkpWorld::unlock(v79);
    ((void (__fastcall *)(hkpMultiThreadedSimulation *))v3->vfptr[3].__vecDelDtor)(v3);
    v3->m_jobQueueHandleForToiSolve = 0i64;
    if ( hkOutOfMemoryState == 1 )
      v11 = 3;
  }
  if ( v4 )
  {
    v80 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v81 = (_QWORD *)v80[1];
    if ( (unsigned __int64)v81 < v80[3] )
    {
      *v81 = "TtWaitForWorkerThreads";
      v82 = __rdtsc();
      v83 = (signed __int64)(v81 + 2);
      *(_DWORD *)(v83 - 8) = v82;
      v80[1] = v83;
    }
    hkJobQueue::setWaitPolicy(v5, 0);
    hkJobQueue::setMasterThreadFinishingFlags(v5, flags);
    ((void (__fastcall *)(hkJobThreadPool *))v4->vfptr[2].__vecDelDtor)(v4);
    v84 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v85 = (_QWORD *)v84[1];
    if ( (unsigned __int64)v85 < v84[3] )
    {
      *v85 = "Et";
      v86 = __rdtsc();
      v87 = (signed __int64)(v85 + 2);
      *(_DWORD *)(v87 - 8) = v86;
      v84[1] = v87;
    }
  }
  v3->m_previousStepResult = v11;
  if ( v11 && hkpWorld::getMemoryWatchDog(v3->m_world) )
    hkpWorldMemoryUtil::tryToRecoverFromMemoryErrors(v3->m_world);
  return v3->m_previousStepResult;
}

// File Line: 1013
// RVA: 0xD73230
void __fastcall hkpMultiThreadedSimulation::getMultithreadConfig(hkpMultiThreadedSimulation *this, hkpMultithreadConfig *config)
{
  config->m_maxNumConstraintsSolvedSingleThreaded = (unsigned int)this->m_multithreadConfig;
}

// File Line: 1018
// RVA: 0xD73240
void __fastcall hkpMultiThreadedSimulation::setMultithreadConfig(hkpMultiThreadedSimulation *this, hkpMultithreadConfig *config, hkJobQueue *queue)
{
  this->m_multithreadConfig = (hkpMultithreadConfig)config->m_maxNumConstraintsSolvedSingleThreaded;
}

// File Line: 1024
// RVA: 0xD72440
void __fastcall hkpMultiThreadedSimulation::assertThereIsNoCollisionInformationForAgent(hkpMultiThreadedSimulation *this, hkpAgentNnEntry *agent)
{
  ;
}

// File Line: 1033
// RVA: 0xD72430
void __fastcall hkpMultiThreadedSimulation::assertThereIsNoCollisionInformationForEntities(hkpMultiThreadedSimulation *this, hkpEntity **entities, int numEntities, hkpWorld *world)
{
  ;
}

// File Line: 1044
// RVA: 0xD73DA0
void __fastcall hkpMultiThreadedSimulation::addToiEventWithCriticalSectionLock(hkpMultiThreadedSimulation *this, hkpProcessCollisionOutput *processOutput, hkpAgentNnEntry *entry, hkCriticalSection *criticalSection)
{
  hkpMultiThreadedSimulation *v4; // rdi
  hkCriticalSection *v5; // rsi
  hkpAgentNnEntry *v6; // r14
  hkpProcessCollisionOutput *v7; // rbp
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  __int64 v13; // rcx
  signed __int64 v14; // rbx
  _QWORD *v15; // r8
  _QWORD *v16; // rcx
  unsigned __int64 v17; // rax
  signed __int64 v18; // rcx
  hkErrStream v19; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v4 = this;
  v5 = criticalSection;
  v6 = entry;
  v7 = processOutput;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtAgentJob.addToi";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  EnterCriticalSection(&v5->m_section);
  if ( v4->m_toiEvents.m_size < (v4->m_toiEvents.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    v13 = v4->m_toiEvents.m_size;
    v4->m_toiEvents.m_size = v13 + 1;
    v14 = (signed __int64)&v4->m_toiEvents.m_data[v13];
    LeaveCriticalSection(&v5->m_section);
    v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v16 = (_QWORD *)v15[1];
    if ( (unsigned __int64)v16 < v15[3] )
    {
      *v16 = "Et";
      v17 = __rdtsc();
      v18 = (signed __int64)(v16 + 2);
      *(_DWORD *)(v18 - 8) = v17;
      v15[1] = v18;
    }
    *(float *)v14 = v7->m_toi.m_time.m_storage;
    *(_BYTE *)(v14 + 8) = v4->m_world->m_collisionDispatcher->m_collisionQualityInfo[(signed __int64)v6->m_collisionQualityIndex].m_useSimpleToiHandling.m_bool;
    *(float *)(v14 + 4) = v7->m_toi.m_seperatingVelocity.m_storage;
    *(hkVector4f *)(v14 + 112) = v7->m_toi.m_contactPoint.m_position;
    *(hkVector4f *)(v14 + 128) = v7->m_toi.m_contactPoint.m_separatingNormal;
    *(_QWORD *)(v14 + 16) = (char *)v6->m_collidable[0] + v6->m_collidable[0]->m_ownerOffset;
    *(_QWORD *)(v14 + 24) = (char *)v6->m_collidable[1] + v6->m_collidable[1]->m_ownerOffset;
    *(hkpSolverResults *)(v14 + 40) = v7->m_toi.m_properties.0;
    *(_QWORD *)(v14 + 48) = v7->m_toi.m_properties.m_userData;
    *(_QWORD *)(v14 + 56) = *(_QWORD *)&v7->m_toi.m_properties.m_friction.m_value;
    *(_QWORD *)(v14 + 64) = *(_QWORD *)&v7->m_toi.m_properties.m_internalDataA;
    *(_QWORD *)(v14 + 32) = v6->m_contactMgr;
    *(_DWORD *)(v14 + 72) = v7->m_toi.m_properties.m_extendedUserDatas[0];
    *(_DWORD *)(v14 + 76) = v7->m_toi.m_properties.m_extendedUserDatas[1];
    *(_DWORD *)(v14 + 80) = v7->m_toi.m_properties.m_extendedUserDatas[2];
    *(_DWORD *)(v14 + 84) = v7->m_toi.m_properties.m_extendedUserDatas[3];
    *(_DWORD *)(v14 + 88) = v7->m_toi.m_properties.m_extendedUserDatas[4];
    *(_DWORD *)(v14 + 92) = v7->m_toi.m_properties.m_extendedUserDatas[5];
    *(_DWORD *)(v14 + 96) = v7->m_toi.m_properties.m_extendedUserDatas[6];
  }
  else
  {
    hkErrStream::hkErrStream(&v19, &buf, 512);
    hkOstream::operator<<(
      (hkOstream *)&v19.vfptr,
      "TOI event queue full, consider using HK_COLLIDABLE_QUALITY_DEBRIS for some objects or increase hkpWorldCinfo::m_si"
      "zeOfToiEventQueue");
    hkError::messageWarning(-265145260, &buf, "World\\Simulation\\Multithreaded\\hkpMultithreadedSimulation.cpp", 1051);
    hkOstream::~hkOstream((hkOstream *)&v19.vfptr);
    LeaveCriticalSection(&v5->m_section);
  }
}

// File Line: 1141
// RVA: 0xD73FD0
void __fastcall hkpMultiThreadedSimulation::collideEntitiesOfOneIslandNarrowPhaseContinuous_toiOnly(hkpMultiThreadedSimulation *this, hkpEntity **entities, int numEntities, hkpProcessCollisionInput *input, hkPointerMap<unsigned int,hkpEntity *,hkContainerHeapAllocator> *entitiesNeedingPsiCollisionDetection)
{
  __int64 v5; // rbx
  hkpEntity **v6; // r14
  hkpMultiThreadedSimulation *v7; // rdi
  hkpSimulationIsland *v8; // rsi
  int v9; // er13
  hkLifoAllocator *v10; // rax
  char *v11; // r15
  int v12; // edx
  char *v13; // rcx
  signed int v14; // er12
  hkLifoAllocator *v15; // rax
  hkpIslandsAgentEntriesInfo *v16; // rcx
  unsigned __int64 v17; // rdx
  int v18; // er8
  signed __int64 v19; // rax
  __int64 v20; // r13
  unsigned __int64 v21; // r14
  int v22; // edi
  __int64 v23; // r13
  __int64 v24; // rsi
  hkpLinkedCollidable::CollisionEntry *v25; // rbx
  hkpSimulationIsland **v26; // rcx
  hkpAgentNnEntry *v27; // r8
  __int64 v28; // rcx
  signed __int64 v29; // rdx
  __int64 v30; // rax
  hkpIslandsAgentEntriesInfo *v31; // rdi
  signed __int32 v32; // ebx
  hkLifoAllocator *v33; // rax
  int v34; // er8
  signed int v35; // ebx
  hkLifoAllocator *v36; // rax
  int v37; // er8
  hkpAgentNnEntry **array; // [rsp+10h] [rbp-51h]
  int numEntries; // [rsp+18h] [rbp-49h]
  int v40; // [rsp+1Ch] [rbp-45h]
  hkpIslandsAgentEntriesInfo *info; // [rsp+20h] [rbp-41h]
  hkpContinuousSimulation::CollisionQualityOverride collisionQualityOverride; // [rsp+28h] [rbp-39h]
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> entries; // [rsp+30h] [rbp-31h]
  int v44; // [rsp+40h] [rbp-21h]
  unsigned int v45; // [rsp+44h] [rbp-1Dh]
  __int64 v46; // [rsp+48h] [rbp-19h]
  hkpSimulationIsland *v47; // [rsp+50h] [rbp-11h]
  __int64 v48; // [rsp+58h] [rbp-9h]
  hkpIslandsAgentEntriesInfo v49; // [rsp+60h] [rbp-1h]
  hkpMultiThreadedSimulation *v50; // [rsp+C0h] [rbp+5Fh]
  hkpEntity **v51; // [rsp+C8h] [rbp+67h]
  hkpProcessCollisionInput *retaddr; // [rsp+D8h] [rbp+77h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v53; // [rsp+E0h] [rbp+7Fh]

  v53 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)this;
  v5 = numEntities;
  v6 = entities;
  v7 = this;
  if ( this->m_jobQueueHandleForToiSolve )
  {
    v8 = (*entities)->m_simulationIsland;
    v47 = v8;
    v9 = v8->m_entities.m_size;
    v44 = v9;
    if ( v9 )
    {
      v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v11 = (char *)v10->m_cur;
      v12 = (v9 + 127) & 0xFFFFFF80;
      v13 = &v11[v12];
      if ( v12 > v10->m_slabSize || v13 > v10->m_end )
        v11 = (char *)hkLifoAllocator::allocateFromNewSlab(v10, v12);
      else
        v10->m_cur = v13;
    }
    else
    {
      v11 = 0i64;
    }
    v14 = v9 | 0x80000000;
    v45 = v9 | 0x80000000;
    hkString::memSet(v11, 0, v9);
    collisionQualityOverride = 1000;
    v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v16 = (hkpIslandsAgentEntriesInfo *)v15->m_cur;
    v17 = (unsigned __int64)&v16[252];
    if ( v15->m_slabSize < 8064 || (void *)v17 > v15->m_end )
      v16 = (hkpIslandsAgentEntriesInfo *)hkLifoAllocator::allocateFromNewSlab(v15, 8064);
    else
      v15->m_cur = (void *)v17;
    array = (hkpAgentNnEntry **)v16;
    info = v16;
    v18 = 2147483648;
    v40 = -2147482648;
    entries.m_data = 0i64;
    entries.m_size = 0;
    v19 = 0i64;
    entries.m_capacityAndFlags = 2147483648;
    do
    {
      v49.m_numEntries[v19] = 0;
      v49.m_firstEntryIdx[v19] = 0;
      v49.m_nextEntryIdx[v19++] = 0;
    }
    while ( v19 < 2 );
    v49.m_island = v8;
    v20 = 0i64;
    v46 = 0i64;
    v48 = v5;
    if ( (signed int)v5 > 0 )
    {
      do
      {
        v21 = (unsigned __int64)v6[v20];
        v11[*(unsigned __int16 *)(v21 + 244)] = 1;
        hkpLinkedCollidable::getCollisionEntriesSorted((hkpLinkedCollidable *)(v21 + 32), &entries);
        v22 = 0;
        if ( entries.m_size > 0 )
        {
          v23 = (__int64)v50;
          v24 = 0i64;
          do
          {
            v25 = entries.m_data;
            v26 = (hkpSimulationIsland **)((char *)entries.m_data[v24].m_partner
                                         + entries.m_data[v24].m_partner->m_ownerOffset);
            if ( v26[37] != v47 || !v11[*((unsigned __int16 *)v26 + 122)] )
            {
              v27 = entries.m_data[v24].m_agentEntry;
              v28 = *(_QWORD *)(*(_QWORD *)(v23 + 24) + 200i64);
              v29 = (signed __int64)v27->m_collisionQualityIndex << 6;
              if ( !*(_DWORD *)(v29 + v28 + 10320) || *(_BYTE *)(v29 + v28 + 10324) )
              {
                if ( !hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                        v53,
                        *(unsigned int *)(v21 + 308),
                        0i64) )
                {
                  hkReferencedObject::addReference((hkReferencedObject *)v21);
                  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                    v53,
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    *(unsigned int *)(v21 + 308),
                    v21);
                }
              }
              else
              {
                v30 = (unsigned __int8)v27->m_nnTrackType.m_storage - 1;
                ++v49.m_numEntries[v30];
                if ( numEntries == (v40 & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
                array[numEntries++] = v25[v24].m_agentEntry;
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
      v18 = entries.m_capacityAndFlags;
      v7 = v50;
      v14 = v45;
    }
    if ( numEntries )
    {
      hkpMultiThreadedSimulation::processAgentNnEntries(v7, array, numEntries, retaddr, (__int64)v7, &v49, 0);
      v18 = entries.m_capacityAndFlags;
    }
    entries.m_size = 0;
    if ( v18 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        entries.m_data,
        16 * v18);
    v31 = info;
    entries.m_data = 0i64;
    entries.m_capacityAndFlags = 2147483648;
    v32 = (8 * collisionQualityOverride + 127) & 0xFFFFFF80;
    v33 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v34 = (v32 + 15) & 0xFFFFFFF0;
    if ( v32 > v33->m_slabSize || (char *)v31 + v34 != v33->m_cur || v33->m_firstNonLifoEnd == v31 )
      hkLifoAllocator::slowBlockFree(v33, v31, v34);
    else
      v33->m_cur = v31;
    numEntries = 0;
    if ( v40 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        8 * v40);
    v35 = (v44 + 127) & 0xFFFFFF80;
    v36 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v37 = (v35 + 15) & 0xFFFFFFF0;
    if ( v35 > v36->m_slabSize || &v11[v37] != v36->m_cur || v36->m_firstNonLifoEnd == v11 )
      hkLifoAllocator::slowBlockFree(v36, v11, v37);
    else
      v36->m_cur = v11;
    if ( v14 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v11,
        v14 & 0x3FFFFFFF);
  }
  else
  {
    hkpContinuousSimulation::collideEntitiesOfOneIslandNarrowPhaseContinuous_toiOnly(
      (hkpContinuousSimulation *)&this->vfptr,
      entities,
      numEntities,
      input,
      entitiesNeedingPsiCollisionDetection);
  }
}      entities,
      numEntities,
      input,
      entitiesNeedingPsiCollisionDetection);
  }
}

// File Line: 1224
// RVA: 0xD75110
hkpIslandsAgentEntriesInfo *__fastcall getIslandEntriesInfo(hkpSimulationIsland *island, hkArray<hkpIslandsAgentEntriesInfo,hkContainerHeapAllocator> *islandEntriesInfos)
{
  hkArray<hkpIslandsAgentEntriesInfo,hkContainerHeapAllocator> *v2; // rbx
  int v3; // edx
  hkpSimulationIsland *v4; // rdi
  int v5; // eax
  hkpSimulationIsland **v6; // r8
  signed __int64 v7; // rcx
  hkpIslandsAgentEntriesInfo *v8; // rax
  int *v9; // rax
  signed __int64 v10; // rdx
  signed __int64 v11; // rdx
  hkpIslandsAgentEntriesInfo *v12; // rdx
  int *v13; // rax
  hkpIslandsAgentEntriesInfo *result; // rax

  v2 = islandEntriesInfos;
  v3 = islandEntriesInfos->m_size;
  v4 = island;
  v5 = 0;
  if ( v3 <= 0 )
  {
LABEL_5:
    if ( v3 == (v2->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 32);
    v7 = 2i64;
    v8 = &v2->m_data[v2->m_size];
    if ( v8 )
    {
      v8->m_island = 0i64;
      v9 = v8->m_firstEntryIdx;
      v10 = 2i64;
      do
      {
        *(v9 - 2) = 0;
        *v9 = 0;
        v9[2] = 0;
        ++v9;
        --v10;
      }
      while ( v10 );
    }
    v11 = v2->m_size++;
    v12 = &v2->m_data[v11];
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
    v2->m_data[v2->m_size - 1].m_island = v4;
    result = &v2->m_data[v2->m_size - 1];
  }
  else
  {
    v6 = &v2->m_data->m_island;
    while ( island != *v6 )
    {
      ++v5;
      v6 += 4;
      if ( v5 >= v3 )
        goto LABEL_5;
    }
    result = &v2->m_data[v5];
  }
  return result;
}

// File Line: 1250
// RVA: 0xD74430
void __fastcall hkpMultiThreadedSimulation::collideEntitiesNeedingPsiCollisionDetectionNarrowPhase_toiOnly(hkpMultiThreadedSimulation *this, hkpProcessCollisionInput *input, hkPointerMap<unsigned int,hkpEntity *,hkContainerHeapAllocator> *entitiesNeedingPsiCollisionDetection)
{
  hkpMultiThreadedSimulation *v3; // r14
  hkPointerMap<unsigned int,hkpEntity *,hkContainerHeapAllocator> *v4; // rbx
  _QWORD *v5; // rax
  unsigned __int64 v6; // r9
  _QWORD *v7; // r10
  unsigned __int64 v8; // rax
  __int64 v9; // r15
  __int64 v10; // r9
  int v11; // edi
  signed int v12; // edx
  __int64 v13; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v14; // rax
  int v15; // er13
  unsigned __int64 v16; // rsi
  __int64 v17; // r12
  hkpAgentNnEntry *v18; // rbx
  hkpCollisionDispatcher *v19; // rcx
  signed __int64 v20; // rdx
  hkpSimulationIsland *v21; // rdi
  int v22; // edx
  __int64 v23; // r14
  int v24; // edx
  int v25; // ecx
  hkpIslandsAgentEntriesInfo *v26; // r8
  hkpIslandsAgentEntriesInfo *v27; // rax
  hkpIslandsAgentEntriesInfo *v28; // rax
  int *v29; // rax
  signed __int64 v30; // rcx
  __int64 v31; // rax
  int v32; // ecx
  hkpIslandsAgentEntriesInfo *v33; // rax
  int *v34; // rax
  signed __int64 v35; // rcx
  signed __int64 v36; // rcx
  __int64 v37; // rax
  __int64 v38; // r8
  int v39; // edx
  __int64 v40; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v41; // rax
  int v42; // ecx
  int v43; // er8
  __int64 v44; // rdx
  hkpIslandsAgentEntriesInfo *v45; // rax
  int v46; // ecx
  hkLifoAllocator *v47; // rax
  int v48; // er13
  hkpAgentNnEntry **v49; // rdi
  int v50; // er13
  char *v51; // rcx
  int v52; // er14
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
  signed __int64 v63; // rcx
  __int64 v64; // rax
  int v65; // ecx
  hkpIslandsAgentEntriesInfo *v66; // rax
  int *v67; // rax
  signed __int64 v68; // rcx
  signed __int64 v69; // rcx
  __int64 v70; // rdx
  hkpMultiThreadedSimulation *v71; // rbx
  hkpWorld *v72; // rbx
  bool v73; // zf
  _QWORD *v74; // rax
  _QWORD *v75; // rcx
  _QWORD *v76; // r8
  unsigned __int64 v77; // rax
  signed __int64 v78; // rcx
  hkLifoAllocator *v79; // rax
  int v80; // er8
  hkpContinuousSimulation::CollisionQualityOverride collisionQualityOverride[2]; // [rsp+30h] [rbp-19h]
  int numInfos; // [rsp+38h] [rbp-11h]
  int v83; // [rsp+3Ch] [rbp-Dh]
  char *array; // [rsp+40h] [rbp-9h]
  int v85; // [rsp+48h] [rbp-1h]
  int v86; // [rsp+4Ch] [rbp+3h]
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> entries; // [rsp+50h] [rbp+7h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v88; // [rsp+60h] [rbp+17h]
  hkpMultiThreadedSimulation *vars0; // [rsp+B0h] [rbp+67h]
  hkpMultiThreadedSimulation *v90; // [rsp+C0h] [rbp+77h]
  int numAllEntries; // [rsp+C8h] [rbp+7Fh]

  v90 = this;
  v3 = this;
  v4 = entitiesNeedingPsiCollisionDetection;
  v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = v5[1];
  v7 = v5;
  if ( v6 < v5[3] )
  {
    *(_QWORD *)v6 = "LtPhysics 2012";
    *(_QWORD *)(v6 + 16) = "StRecollide PSI";
    v8 = __rdtsc();
    *(_DWORD *)(v6 + 8) = v8;
    v7[1] = v6 + 24;
  }
  v9 = 0i64;
  ++v3->m_world->m_criticalOperationsLockCount;
  v10 = v4->m_map.m_hashMod;
  v88.m_elem = 0i64;
  v88.m_numElems = 0;
  v88.m_hashMod = -1;
  array = 0i64;
  v85 = 0;
  v86 = 2147483648;
  *(_QWORD *)collisionQualityOverride = 0i64;
  numInfos = 0;
  v83 = 2147483648;
  v11 = 0;
  numAllEntries = 0;
  v12 = 0;
  v13 = 0i64;
  if ( (signed int)v10 >= 0 )
  {
    v14 = v4->m_map.m_elem;
    do
    {
      if ( v14->key != -1i64 )
        break;
      ++v13;
      ++v12;
      ++v14;
    }
    while ( v13 <= v10 );
  }
  v15 = v12;
  if ( v12 <= (signed int)v10 )
  {
    do
    {
      v16 = v4->m_map.m_elem[v15].val;
      entries.m_data = 0i64;
      entries.m_size = 0;
      entries.m_capacityAndFlags = 2147483648;
      hkpLinkedCollidable::getCollisionEntriesSorted((hkpLinkedCollidable *)(v16 + 32), &entries);
      v17 = entries.m_size;
      if ( entries.m_size > 0i64 )
      {
        do
        {
          v18 = entries.m_data[v9].m_agentEntry;
          if ( !(unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                &v88,
                                (unsigned __int64)entries.m_data[v9].m_agentEntry,
                                0i64) )
          {
            v19 = v3->m_world->m_collisionDispatcher;
            v20 = (signed __int64)v18->m_collisionQualityIndex << 6;
            if ( !*(unsigned int *)((char *)&v19->m_collisionQualityInfo[0].m_useContinuousPhysics.m_storage + v20)
              || *(&v19->m_collisionQualityInfo[0].m_useSimpleToiHandling.m_bool + v20)
              && COERCE_FLOAT(_mm_shuffle_ps(*(__m128 *)(v16 + 448), *(__m128 *)(v16 + 448), 255)) == 0.0 )
            {
              v21 = *(hkpSimulationIsland **)(v16 + 296);
              if ( *(_BYTE *)(v16 + 352) == 5 )
                v21 = *(hkpSimulationIsland **)((v16 ^ ((_QWORD)v18->m_collidable[1]
                                                      + v18->m_collidable[1]->m_ownerOffset) ^ ((_QWORD)v18->m_collidable[0]
                                                                                              + v18->m_collidable[0]->m_ownerOffset))
                                              + 0x128);
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                &v88,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                (unsigned __int64)v18,
                1ui64);
              v22 = v85;
              if ( v85 == (v86 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 24);
                v22 = v85;
              }
              v85 = v22 + 1;
              v23 = (__int64)&array[24 * v22];
              v24 = 0;
              *(_QWORD *)v23 = v18;
              *(_QWORD *)(v23 + 8) = v21;
              *(_DWORD *)(v23 + 16) = (unsigned __int8)v18->m_nnTrackType.m_storage - 1;
              v25 = numInfos;
              v26 = *(hkpIslandsAgentEntriesInfo **)collisionQualityOverride;
              if ( numInfos <= 0 )
              {
LABEL_21:
                if ( numInfos == (v83 & 0x3FFFFFFF) )
                {
                  hkArrayUtil::_reserveMore(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    collisionQualityOverride,
                    32);
                  v25 = numInfos;
                  v26 = *(hkpIslandsAgentEntriesInfo **)collisionQualityOverride;
                }
                v28 = &v26[v25];
                if ( v28 )
                {
                  v28->m_island = 0i64;
                  v29 = v28->m_firstEntryIdx;
                  v30 = 2i64;
                  do
                  {
                    *(v29 - 2) = 0;
                    *v29 = 0;
                    v29[2] = 0;
                    ++v29;
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
              v37 = *(signed int *)(v23 + 16);
              v3 = vars0;
              ++*(_DWORD *)(v36 + 4 * v37 + 8);
              v11 = numAllEntries++ + 1;
            }
          }
          ++v9;
          --v17;
        }
        while ( v17 );
        v4 = (hkPointerMap<unsigned int,hkpEntity *,hkContainerHeapAllocator> *)v90;
        v9 = 0i64;
      }
      hkReferencedObject::removeReference((hkReferencedObject *)v16);
      v38 = v4->m_map.m_hashMod;
      v39 = v15 + 1;
      v40 = v15 + 1;
      if ( v40 <= v38 )
      {
        v41 = &v4->m_map.m_elem[v39];
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
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          entries.m_data,
          16 * entries.m_capacityAndFlags);
      entries.m_data = 0i64;
      entries.m_capacityAndFlags = 2147483648;
    }
    while ( v15 <= v4->m_map.m_hashMod );
  }
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v4->m_map.m_elem);
  v42 = 0;
  v43 = 0;
  if ( numInfos > 0 )
  {
    v44 = 0i64;
    do
    {
      v45 = *(hkpIslandsAgentEntriesInfo **)collisionQualityOverride;
      ++v43;
      ++v44;
      *(_DWORD *)(*(_QWORD *)collisionQualityOverride + v44 * 32 - 16) = v42;
      *((_DWORD *)&v45[v44] - 2) = v42;
      v46 = *((_DWORD *)&v45[v44] - 6) + v42;
      *((_DWORD *)&v45[v44] - 3) = v46;
      *((_DWORD *)&v45[v44] - 1) = v46;
      v42 = *((_DWORD *)&v45[v44] - 5) + v46;
    }
    while ( v43 < numInfos );
  }
  v47 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v48 = 8 * v11 + 127;
  v49 = (hkpAgentNnEntry **)v47->m_cur;
  v50 = v48 & 0xFFFFFF80;
  v51 = (char *)v49 + v50;
  if ( v50 > v47->m_slabSize || v51 > v47->m_end )
    v49 = (hkpAgentNnEntry **)hkLifoAllocator::allocateFromNewSlab(v47, v50);
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
      v58 = *(signed int *)&array[v53 + 16];
      v59 = numInfos;
      if ( numInfos <= 0 )
      {
LABEL_56:
        if ( numInfos == (v83 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            collisionQualityOverride,
            32);
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
      v70 = *(signed int *)(v69 + 4 * v58 + 24);
      ++v52;
      v53 += 24i64;
      *(_DWORD *)(v69 + 4 * v58 + 24) = v70 + 1;
      v49[v70] = v56;
    }
    while ( v52 < v85 );
  }
  v71 = vars0;
  hkpMultiThreadedSimulation::processAgentNnEntriesFromMultipleIslands(
    vars0,
    v49,
    numAllEntries,
    *(hkpIslandsAgentEntriesInfo **)collisionQualityOverride,
    numInfos,
    vars0->m_world->m_collisionInput,
    DISABLE_TOIS);
  v72 = v71->m_world;
  v73 = v72->m_criticalOperationsLockCount-- == 1;
  if ( v73 && !v72->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v72->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v72);
    if ( v72->m_pendingOperationQueueCount == 1 && v72->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(v72);
  }
  v74 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v75 = (_QWORD *)v74[1];
  v76 = v74;
  if ( (unsigned __int64)v75 < v74[3] )
  {
    *v75 = "lt";
    v77 = __rdtsc();
    v78 = (signed __int64)(v75 + 2);
    *(_DWORD *)(v78 - 8) = v77;
    v76[1] = v78;
  }
  v79 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v80 = (v50 + 15) & 0xFFFFFFF0;
  if ( v50 > v79->m_slabSize || (char *)v49 + v80 != v79->m_cur || v79->m_firstNonLifoEnd == v49 )
    hkLifoAllocator::slowBlockFree(v79, v49, v80);
  else
    v79->m_cur = v49;
  numInfos = 0;
  if ( v83 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)collisionQualityOverride,
      32 * v83);
  *(_QWORD *)collisionQualityOverride = 0i64;
  v83 = 2147483648;
  v85 = 0;
  if ( v86 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      24 * (v86 & 0x3FFFFFFF));
  array = 0i64;
  v86 = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v88,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v88);
}

// File Line: 1372
// RVA: 0xD73B60
void __fastcall hkpMultiThreadedSimulation::processAgentNnEntries_oneInfo(hkpMultiThreadedSimulation *this, hkpAgentNnEntry **allEntries, hkpProcessCollisionInput *collisionInput, hkpIslandsAgentEntriesInfo *info, hkpContinuousSimulation::CollisionQualityOverride collisionQualityOverride, hkpPostCollideJob *postCollideJobOut)
{
  hkpMultiThreadedSimulation *v6; // rbp
  hkpIslandsAgentEntriesInfo *v7; // rsi
  hkpProcessCollisionInput *v8; // r14
  hkpAgentNnEntry **v9; // r15
  hkLifoAllocator *v10; // rax
  char *v11; // rbx
  unsigned __int64 v12; // rcx
  int v13; // ecx
  signed int v14; // edi
  int v15; // edx
  int v16; // er8
  __int64 v17; // rax
  signed __int64 v18; // rcx
  hkStepInfo v19; // xmm0
  char *v20; // rax
  hkpWorld *v21; // rax
  int v22; // edx
  hkpAgentSectorHeader *v23; // rax
  __int64 v24; // r14
  hkpAgentSectorHeader *v25; // r15
  hkpSimulationIsland **v26; // rdi
  hkLifoAllocator *v27; // rax

  v6 = this;
  v7 = info;
  v8 = collisionInput;
  v9 = allEntries;
  v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (char *)v10->m_cur;
  v12 = (unsigned __int64)(v11 + 256);
  if ( v10->m_slabSize < 256 || (void *)v12 > v10->m_end )
    v11 = (char *)hkLifoAllocator::allocateFromNewSlab(v10, 256);
  else
    v10->m_cur = (void *)v12;
  v13 = 0;
  v14 = 0;
  v15 = v7->m_numEntries[0] + v7->m_numEntries[1];
  if ( v15 )
  {
    v16 = v6->m_world->m_maxEntriesPerToiMidphaseCollideTask;
    if ( v11 )
    {
      v17 = v7->m_firstEntryIdx[0];
      *(_WORD *)v11 = 15;
      v11[2] = 1;
      v18 = (signed __int64)&v9[v17];
      *((_WORD *)v11 + 3) = -1;
      *((_WORD *)v11 + 2) = 112;
      *((_QWORD *)v11 + 3) = 0i64;
      *((_WORD *)v11 + 8) = -1;
      *((_QWORD *)v11 + 4) = 0i64;
      v19 = v8->m_stepInfo;
      v11[104] = collisionQualityOverride;
      *((_WORD *)v11 + 8) = 0;
      *((_WORD *)v11 + 28) = 0;
      *((hkStepInfo *)v11 + 5) = v19;
      v20 = v11;
      *((_QWORD *)v11 + 8) = v18;
      *((_WORD *)v11 + 29) = v15;
      *((_WORD *)v11 + 30) = v16;
      v11[62] = 0;
      *((_QWORD *)v11 + 6) = 0i64;
      v11[1] = 1;
    }
    else
    {
      v20 = 0i64;
    }
    *((_WORD *)v20 + 28) = 0;
    v14 = 1;
    v13 = (v15 - 1) / v16 + 1;
  }
  v21 = v6->m_world;
  v22 = v21->m_maxEntriesPerToiNarrowphaseCollideTask;
  if ( v21->m_maxEntriesPerToiMidphaseCollideTask > v22 )
    v22 = v21->m_maxEntriesPerToiMidphaseCollideTask;
  v23 = hkpAgentSectorHeader::allocate(v13, v22);
  v24 = v14;
  v23->m_shapeKeyTracks = 0i64;
  v23->m_numShapeKeyTracks = 0;
  v25 = v23;
  if ( v14 > 0 )
  {
    v26 = (hkpSimulationIsland **)(v11 + 24);
    do
    {
      v26[3] = (hkpSimulationIsland *)v25;
      *v26 = v7->m_island;
      *((_WORD *)v26 - 4) = v7->m_island->m_storageIndex;
      v26[2] = (hkpSimulationIsland *)v6->m_world->m_multithreadedSimulationJobData;
      hkJobQueue::addJob(v6->m_jobQueueHandleForToiSolve, (hkJob *)(v26 - 3), JOB_LOW_PRIORITY);
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
    postCollideJobOut->m_islandIndex = *((_WORD *)v11 + 8);
    postCollideJobOut->m_island = (hkpSimulationIsland *)*((_QWORD *)v11 + 3);
    postCollideJobOut->m_taskHeader = (hkpBuildJacobianTaskHeader *)*((_QWORD *)v11 + 4);
    postCollideJobOut->m_mtThreadStructure = (hkpMtThreadStructure *)*((_QWORD *)v11 + 5);
    postCollideJobOut->m_islandIndex = *((_WORD *)v11 + 8);
    postCollideJobOut->m_header = (hkpAgentSectorHeader *)*((_QWORD *)v11 + 6);
  }
  postCollideJobOut->m_island = (hkpSimulationIsland *)*((_QWORD *)v11 + 3);
  v27 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v27->m_slabSize < 256 || v11 + 256 != v27->m_cur || v27->m_firstNonLifoEnd == v11 )
    hkLifoAllocator::slowBlockFree(v27, v11, 256);
  else
    v27->m_cur = v11;
}v27->m_firstNonLifoEnd == v11 )
    hkLif

// File Line: 1467
// RVA: 0xD733F0
void __usercall hkpMultiThreadedSimulation::processAgentNnEntries(hkpMultiThreadedSimulation *this@<rcx>, hkpAgentNnEntry **entries@<rdx>, int numEntries@<r8d>, hkpProcessCollisionInput *collisionInput@<r9>, __int64 a5@<rdi>, hkpIslandsAgentEntriesInfo *info, hkpContinuousSimulation::CollisionQualityOverride collisionQualityOverride)
{
  hkpProcessCollisionInput *v7; // r14
  hkpSimulationIsland *v8; // r12
  int v9; // ebx
  hkpAgentNnEntry **v10; // r15
  hkpMultiThreadedSimulation *v11; // rsi
  hkLifoAllocator *v12; // rax
  char *v13; // rdi
  int v14; // ebx
  char *v15; // rcx
  hkpWorld *v16; // r8
  hkpProcessCollisionInput *v17; // rcx
  hkpViolatedConstraintArray *v18; // rax
  float v19; // xmm1_4
  __m128 v20; // xmm0
  _QWORD **v21; // rax
  hkLifoAllocator *v22; // rax
  int v23; // er8
  hkpMtThreadStructure tl; // [rsp+30h] [rbp-A8h]
  hkpIslandsAgentEntriesInfo *retaddr; // [rsp+1F8h] [rbp+120h]
  hkpContinuousSimulation::CollisionQualityOverride v26; // [rsp+200h] [rbp+128h]
  __int64 v27[4]; // [rsp+200h] [rbp+128h]

  v7 = collisionInput;
  v8 = retaddr->m_island;
  v9 = numEntries;
  v10 = entries;
  v11 = this;
  if ( this->m_jobQueueHandleForToiSolve && numEntries > this->m_world->m_maxNumToiCollisionPairsSinglethreaded )
  {
    v27[0] = a5;
    v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v13 = (char *)v12->m_cur;
    v14 = (8 * v9 + 127) & 0xFFFFFF80;
    v15 = &v13[v14];
    if ( v14 > v12->m_slabSize || v15 > v12->m_end )
      v13 = (char *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
    else
      v12->m_cur = v15;
    hkpMultiThreadedSimulation::processAgentNnEntries_oneInfo(
      v11,
      v10,
      v7,
      retaddr,
      v27[0],
      (hkpPostCollideJob *)(&tl.m_collisionInput.m_config + 1));
    hkJobQueue::processAllJobs(v11->m_jobQueueHandleForToiSolve, 1);
    v16 = v11->m_world;
    *(_QWORD *)&tl.m_tolerance.m_storage = v8;
    tl.m_constraintQueryIn.m_maxConstraintViolationSqrd.m_real.m128_u64[0] = (unsigned __int64)hkpBeginConstraints;
    tl.m_collisionInput.m_dynamicsInfo = &v16->m_dynamicsStepInfo;
    tl.m_collisionInput.m_aabb32Info.m_bitScale.m_quad.m128_u64[0] = 0i64;
    v17 = v16->m_collisionInput;
    tl.m_constraintQueryIn.m_maxConstraintViolationSqrd.m_real.m128_u64[1] = (unsigned __int64)v17->m_dispatcher.m_storage;
    tl.m_constraintQueryIn.m_constraintInstance.m_storage = (hkpConstraintInstance *)v17->m_weldClosestPoints.m_storage;
    HIDWORD(tl.m_constraintQueryIn.m_constraintInstance.m_storage) = v17->m_forceAcceptContactPoints.m_storage;
    *(float *)&tl.m_constraintQueryIn.m_violatedConstraints.m_storage = v17->m_tolerance.m_storage;
    *(_QWORD *)&tl.m_constraintQueryIn.m_accumulatorAIndex.m_storage = v17->m_filter.m_storage;
    tl.m_constraintQueryIn.m_beginConstraints = (void (__fastcall *)(hkpConstraintQueryIn *, hkpConstraintQueryOut *, hkpSolverResults *, int))v17->m_convexListFilter.m_storage;
    LODWORD(tl.m_collisionInput.m_dispatcher.m_storage) = v17->m_createPredictiveAgents.m_storage;
    *(hkVector4f *)&tl.m_collisionInput.m_weldClosestPoints.m_storage = v17->m_aabb32Info.m_bitOffsetLow;
    *(hkVector4f *)&tl.m_collisionInput.m_filter.m_storage = v17->m_aabb32Info.m_bitOffsetHigh;
    *(hkVector4f *)&tl.m_collisionInput.m_createPredictiveAgents.m_storage = v17->m_aabb32Info.m_bitScale;
    _mm_store_si128(
      (__m128i *)&tl.m_collisionInput.m_aabb32Info.m_bitOffsetLow.m_quad.m128_u16[4],
      (__m128i)v17->m_stepInfo);
    tl.m_collisionInput.m_aabb32Info.m_bitOffsetHigh.m_quad.m128_u64[1] = (unsigned __int64)v17->m_collisionQualityInfo.m_storage;
    tl.m_collisionInput.m_aabb32Info.m_bitScale.m_quad.m128_u64[1] = (unsigned __int64)v17->m_dynamicsInfo;
    LOWORD(tl.m_collisionInput.m_stepInfo.m_startTime.m_storage) = *(_WORD *)&v17->m_enableDeprecatedWelding.m_bool;
    *(_QWORD *)&tl.m_collisionInput.m_stepInfo.m_deltaTime.m_storage = v17->m_config;
    v18 = v16->m_violatedConstraintArray;
    tl.m_constraintQueryIn.m_subStepDeltaTime.m_storage = v16->m_dynamicsStepInfo.m_solverInfo.m_deltaTime;
    tl.m_constraintQueryIn.m_microStepDeltaTime.m_storage = v16->m_dynamicsStepInfo.m_solverInfo.m_deltaTime
                                                          * v16->m_dynamicsStepInfo.m_solverInfo.m_invNumMicroSteps;
    tl.m_constraintQueryIn.m_subStepInvDeltaTime.m_storage = v16->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
    tl.m_constraintQueryIn.m_invNumSteps.m_storage = v16->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
    tl.m_constraintQueryIn.m_invNumStepsTimesMicroSteps.m_storage = v16->m_dynamicsStepInfo.m_solverInfo.m_invNumMicroSteps
                                                                  * v16->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
    tl.m_constraintQueryIn.m_frictionRhsFactor.m_storage = v16->m_dynamicsStepInfo.m_solverInfo.m_tau;
    v19 = v16->m_dynamicsStepInfo.m_solverInfo.m_damping;
    *(_QWORD *)&tl.m_constraintQueryIn.m_tau.m_storage = v18;
    *((float *)&tl.m_constraintQueryIn.m_frictionRhsFactor + 1) = v19;
    tl.m_constraintQueryIn.m_rhsFactor.m_storage = v16->m_dynamicsStepInfo.m_solverInfo.m_tauDivDamp
                                                 * v16->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
    tl.m_constraintQueryIn.m_virtMassFactor.m_storage = v16->m_dynamicsStepInfo.m_solverInfo.m_damping;
    tl.m_constraintQueryIn.m_frictionRhsFactor.m_storage = v16->m_dynamicsStepInfo.m_solverInfo.m_frictionTauDivDamp
                                                         * v16->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
    tl.m_constraintQueryIn.m_frameDeltaTime.m_storage = v16->m_dynamicsStepInfo.m_stepInfo.m_deltaTime.m_storage;
    tl.m_constraintQueryIn.m_frameInvDeltaTime.m_storage = v16->m_dynamicsStepInfo.m_stepInfo.m_invDeltaTime.m_storage;
    v20 = (__m128)LODWORD(v16->m_dynamicsStepInfo.m_solverInfo.m_maxConstraintViolationSqrd);
    tl.m_collisionInput.m_spareAgentSector = (hkpAgent1nSector *)v11;
    *(__m128 *)&tl.m_constraintQueryIn.m_bodyB.m_storage = _mm_shuffle_ps(v20, v20, 0);
    v20.m128_i32[0] = LODWORD(v16->m_collisionInput->m_tolerance.m_storage);
    tl.m_world = v16;
    tl.m_collisionInput.m_config = (hkpCollisionAgentConfig *)hkpWeldingUtility::m_sinCosTable;
    *(_DWORD *)&tl.m_collisionInput.m_enableDeprecatedWelding.m_bool = v20.m128_i32[0];
    hkCpuPostCollideJob(&tl, 0i64, (hkJobQueue::JobQueueEntry *)(&tl.m_collisionInput.m_config + 1));
    if ( tl.m_collisionInput.m_aabb32Info.m_bitScale.m_quad.m128_u64[0] )
    {
      v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, unsigned __int64, signed __int64))(*v21[11] + 16i64))(
        v21[11],
        tl.m_collisionInput.m_aabb32Info.m_bitScale.m_quad.m128_u64[0],
        512i64);
    }
    v22 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v23 = (v14 + 15) & 0xFFFFFFF0;
    if ( v14 > v22->m_slabSize || &v13[v23] != v22->m_cur || v22->m_firstNonLifoEnd == v13 )
      hkLifoAllocator::slowBlockFree(v22, v13, v23);
    else
      v22->m_cur = v13;
  }
  else
  {
    hkpContinuousSimulation::processAgentNnEntries(
      (hkpContinuousSimulation *)&this->vfptr,
      entries,
      numEntries,
      collisionInput,
      v8,
      v26);
  }
}

// File Line: 1549
// RVA: 0xD73740
void __fastcall hkpMultiThreadedSimulation::processAgentNnEntriesFromMultipleIslands(hkpMultiThreadedSimulation *this, hkpAgentNnEntry **allEntries, int numAllEntries, hkpIslandsAgentEntriesInfo *islandEntriesInfos, int numInfos, hkpProcessCollisionInput *collisionInput, hkpContinuousSimulation::CollisionQualityOverride collisionQualityOverride)
{
  hkpIslandsAgentEntriesInfo *v7; // rbx
  hkpAgentNnEntry **v8; // r12
  hkpMultiThreadedSimulation *v9; // rdi
  hkpIslandsAgentEntriesInfo *v10; // r15
  hkLifoAllocator *v11; // rax
  __int64 v12; // rsi
  hkLifoAllocator *v13; // rcx
  hkJobQueue::JobQueueEntry *v14; // rax
  int v15; // er14
  char *v16; // rdx
  __int64 v17; // r13
  hkpPostCollideJob *postCollideJobOut; // rsi
  hkpWorld *v19; // r8
  hkpProcessCollisionInput *v20; // rcx
  hkpViolatedConstraintArray *v21; // rax
  float v22; // xmm1_4
  __m128 v23; // xmm0
  hkJobQueue::JobQueueEntry *v24; // rbx
  _QWORD **v25; // rax
  hkLifoAllocator *v26; // rax
  int v27; // er8
  __int64 v28; // rsi
  int *v29; // rbx
  hkJobQueue::JobQueueEntry *nextJobOut; // [rsp+30h] [rbp-D0h]
  hkpMtThreadStructure tl; // [rsp+40h] [rbp-C0h]

  v7 = islandEntriesInfos;
  v8 = allEntries;
  v9 = this;
  if ( this->m_jobQueueHandleForToiSolve && numAllEntries > this->m_world->m_maxNumToiCollisionPairsSinglethreaded )
  {
    v10 = 0i64;
    v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v12 = (unsigned int)numInfos;
    v13 = v11;
    v14 = (hkJobQueue::JobQueueEntry *)v11->m_cur;
    nextJobOut = v14;
    v15 = ((numInfos << 6) + 127) & 0xFFFFFF80;
    v16 = &v14->m_jobSubType + v15;
    if ( v15 > v13->m_slabSize || v16 > v13->m_end )
    {
      v14 = (hkJobQueue::JobQueueEntry *)hkLifoAllocator::allocateFromNewSlab(v13, v15);
      nextJobOut = v14;
    }
    else
    {
      v13->m_cur = v16;
    }
    if ( numInfos > 0 )
    {
      v17 = (unsigned int)numInfos;
      postCollideJobOut = (hkpPostCollideJob *)v14;
      do
      {
        if ( v7->m_island == v9->m_world->m_fixedIsland )
          v10 = v7;
        else
          hkpMultiThreadedSimulation::processAgentNnEntries_oneInfo(
            v9,
            v8,
            collisionInput,
            v7,
            collisionQualityOverride,
            postCollideJobOut);
        ++postCollideJobOut;
        ++v7;
        --v17;
      }
      while ( v17 );
      v15 = ((numInfos << 6) + 127) & 0xFFFFFF80;
      v12 = (unsigned int)numInfos;
    }
    hkJobQueue::processAllJobs(v9->m_jobQueueHandleForToiSolve, 1);
    v19 = v9->m_world;
    tl.m_collisionInput.m_forceAcceptContactPoints.m_storage = 0;
    tl.m_collisionInput.m_spareAgentSector = 0i64;
    tl.m_constraintQueryIn.m_beginConstraints = hkpBeginConstraints;
    tl.m_dynamicsStepInfo.m_storage = &v19->m_dynamicsStepInfo;
    v20 = v19->m_collisionInput;
    tl.m_collisionInput.m_dispatcher.m_storage = v20->m_dispatcher.m_storage;
    tl.m_collisionInput.m_weldClosestPoints.m_storage = v20->m_weldClosestPoints.m_storage;
    tl.m_collisionInput.m_forceAcceptContactPoints.m_storage = v20->m_forceAcceptContactPoints.m_storage;
    tl.m_collisionInput.m_tolerance.m_storage = v20->m_tolerance.m_storage;
    tl.m_collisionInput.m_filter.m_storage = v20->m_filter.m_storage;
    tl.m_collisionInput.m_convexListFilter.m_storage = v20->m_convexListFilter.m_storage;
    tl.m_collisionInput.m_createPredictiveAgents.m_storage = v20->m_createPredictiveAgents.m_storage;
    tl.m_collisionInput.m_aabb32Info.m_bitOffsetLow = v20->m_aabb32Info.m_bitOffsetLow;
    tl.m_collisionInput.m_aabb32Info.m_bitOffsetHigh = v20->m_aabb32Info.m_bitOffsetHigh;
    tl.m_collisionInput.m_aabb32Info.m_bitScale = v20->m_aabb32Info.m_bitScale;
    _mm_store_si128((__m128i *)&tl.m_collisionInput.m_stepInfo, (__m128i)v20->m_stepInfo);
    tl.m_collisionInput.m_collisionQualityInfo.m_storage = v20->m_collisionQualityInfo.m_storage;
    tl.m_collisionInput.m_dynamicsInfo = v20->m_dynamicsInfo;
    tl.m_collisionInput.m_enableDeprecatedWelding.m_bool = v20->m_enableDeprecatedWelding.m_bool;
    tl.m_collisionInput.m_allowToSkipConfirmedCallbacks.m_bool = v20->m_allowToSkipConfirmedCallbacks.m_bool;
    tl.m_collisionInput.m_config = v20->m_config;
    v21 = v19->m_violatedConstraintArray;
    tl.m_constraintQueryIn.m_subStepDeltaTime.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_deltaTime;
    tl.m_constraintQueryIn.m_microStepDeltaTime.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_deltaTime
                                                          * v19->m_dynamicsStepInfo.m_solverInfo.m_invNumMicroSteps;
    tl.m_constraintQueryIn.m_subStepInvDeltaTime.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
    tl.m_constraintQueryIn.m_invNumSteps.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
    tl.m_constraintQueryIn.m_invNumStepsTimesMicroSteps.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_invNumMicroSteps
                                                                  * v19->m_dynamicsStepInfo.m_solverInfo.m_invNumSteps;
    tl.m_constraintQueryIn.m_tau.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_tau;
    v22 = v19->m_dynamicsStepInfo.m_solverInfo.m_damping;
    tl.m_constraintQueryIn.m_violatedConstraints.m_storage = v21;
    tl.m_constraintQueryIn.m_damping.m_storage = v22;
    tl.m_constraintQueryIn.m_rhsFactor.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_tauDivDamp
                                                 * v19->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
    tl.m_constraintQueryIn.m_virtMassFactor.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_damping;
    tl.m_constraintQueryIn.m_frictionRhsFactor.m_storage = v19->m_dynamicsStepInfo.m_solverInfo.m_frictionTauDivDamp
                                                         * v19->m_dynamicsStepInfo.m_solverInfo.m_invDeltaTime;
    tl.m_constraintQueryIn.m_frameDeltaTime.m_storage = v19->m_dynamicsStepInfo.m_stepInfo.m_deltaTime.m_storage;
    tl.m_constraintQueryIn.m_frameInvDeltaTime.m_storage = v19->m_dynamicsStepInfo.m_stepInfo.m_invDeltaTime.m_storage;
    v23 = (__m128)LODWORD(v19->m_dynamicsStepInfo.m_solverInfo.m_maxConstraintViolationSqrd);
    tl.m_simulation.m_storage = v9;
    tl.m_constraintQueryIn.m_maxConstraintViolationSqrd.m_real = _mm_shuffle_ps(v23, v23, 0);
    tl.m_tolerance.m_storage = v19->m_collisionInput->m_tolerance.m_storage;
    tl.m_weldingTable.m_storage = hkpWeldingUtility::m_sinCosTable;
    tl.m_world = v19;
    if ( (signed int)v12 > 0 )
    {
      v24 = nextJobOut;
      do
      {
        hkCpuPostCollideJob(&tl, 0i64, v24);
        v24 = (hkJobQueue::JobQueueEntry *)((char *)v24 + 64);
        --v12;
      }
      while ( v12 );
      if ( tl.m_collisionInput.m_spareAgentSector )
      {
        v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, signed __int64))(*v25[11] + 16i64))(
          v25[11],
          tl.m_collisionInput.m_spareAgentSector,
          512i64);
      }
    }
    if ( v10 )
      hkpContinuousSimulation::processAgentNnEntries(
        (hkpContinuousSimulation *)&v9->vfptr,
        &v8[v10->m_firstEntryIdx[0]],
        v10->m_numEntries[0] + v10->m_numEntries[1],
        collisionInput,
        v10->m_island,
        collisionQualityOverride);
    v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v27 = (v15 + 15) & 0xFFFFFFF0;
    if ( v15 > v26->m_slabSize || (char *)nextJobOut + v27 != v26->m_cur || v26->m_firstNonLifoEnd == nextJobOut )
      hkLifoAllocator::slowBlockFree(v26, nextJobOut, v27);
    else
      v26->m_cur = nextJobOut;
  }
  else
  {
    v28 = numInfos;
    if ( numInfos > 0i64 )
    {
      v29 = islandEntriesInfos->m_numEntries;
      do
      {
        hkpContinuousSimulation::processAgentNnEntries(
          (hkpContinuousSimulation *)&v9->vfptr,
          &v8[v29[2]],
          *v29 + v29[1],
          collisionInput,
          *((hkpSimulationIsland **)v29 - 1),
          collisionQualityOverride);
        v29 += 8;
        --v28;
      }
      while ( v28 );
    }
  }
}isionInput,
          *(


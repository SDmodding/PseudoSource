// File Line: 27
// RVA: 0xD95850
void __fastcall deleteTaskHeaderResources(hkpBuildJacobianTaskHeader *taskHeader)
{
  hkpBuildJacobianTask *m_buildJacobianTasks; // rdi
  _QWORD **Value; // rax
  hkpSolveConstraintBatchTask *m_firstSolveJacobiansTask; // rdi
  _QWORD **v5; // rax
  void *m_buffer; // rsi
  unsigned int m_bufferCapacity; // edi
  _QWORD **v8; // rax
  int m_entitiesCapacity; // esi
  hkpEntity *const *m_allEntities; // rdi
  _QWORD **v11; // rax
  int m_capacityAndFlags; // r8d
  _QWORD **v13; // rax

  while ( taskHeader->m_tasks.m_buildJacobianTasks )
  {
    m_buildJacobianTasks = taskHeader->m_tasks.m_buildJacobianTasks;
    taskHeader->m_tasks.m_buildJacobianTasks = m_buildJacobianTasks->m_next;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpBuildJacobianTask *, __int64))(*Value[11] + 16i64))(
      Value[11],
      m_buildJacobianTasks,
      3968i64);
  }
  while ( taskHeader->m_solveTasks.m_firstSolveJacobiansTask )
  {
    m_firstSolveJacobiansTask = taskHeader->m_solveTasks.m_firstSolveJacobiansTask;
    taskHeader->m_solveTasks.m_firstSolveJacobiansTask = m_firstSolveJacobiansTask->m_next;
    v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpSolveConstraintBatchTask *, __int64))(*v5[11] + 16i64))(
      v5[11],
      m_firstSolveJacobiansTask,
      64i64);
  }
  m_buffer = taskHeader->m_buffer;
  if ( m_buffer )
  {
    m_bufferCapacity = taskHeader->m_bufferCapacity;
    v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*v8[13] + 32i64))(v8[13], m_buffer, m_bufferCapacity);
    taskHeader->m_buffer = 0i64;
  }
  if ( taskHeader->m_numIslandsAfterSplit > 1 )
  {
    m_entitiesCapacity = taskHeader->m_entitiesCapacity;
    m_allEntities = taskHeader->m_allEntities;
    v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpEntity *const *, _QWORD))(*v11[11] + 32i64))(
      v11[11],
      m_allEntities,
      (unsigned int)(8 * m_entitiesCapacity));
    taskHeader->m_allEntities = 0i64;
  }
  m_capacityAndFlags = taskHeader->m_newSplitIslands.m_capacityAndFlags;
  taskHeader->m_newSplitIslands.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      taskHeader->m_newSplitIslands.m_data,
      8 * m_capacityAndFlags);
  taskHeader->m_newSplitIslands.m_data = 0i64;
  taskHeader->m_newSplitIslands.m_capacityAndFlags = 0x80000000;
  v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkpBuildJacobianTaskHeader *, __int64))(*v13[11] + 16i64))(
    v13[11],
    taskHeader,
    208i64);
}

// File Line: 65
// RVA: 0xD94D40
__int64 __fastcall hkpSingleThreadedJobsOnIsland::cpuBroadPhaseJob(
        hkpMtThreadStructure *tl,
        hkJobQueue *jobQueue,
        hkJobQueue::JobQueueEntry *nextJobOut)
{
  __int64 v3; // r14
  hkJobQueue::JobQueueEntry *v5; // r15
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  signed __int32 v11; // r13d
  int m_broadPhaseUpdateSize; // edi
  _BYTE *v13; // rbx
  hkLifoAllocator *v14; // rcx
  hkpBroadPhaseHandlePair *m_cur; // rax
  int v16; // edx
  char *v17; // r8
  hkpWorld *m_world; // rax
  int v19; // edi
  hkLifoAllocator *v20; // rcx
  hkpBroadPhaseHandlePair *v21; // rax
  int v22; // edx
  char *v23; // r8
  hkpWorld *v24; // r9
  hkpMultiThreadedSimulation *m_storage; // rcx
  __int64 v26; // rsi
  signed __int32 v27; // ecx
  _QWORD *v28; // r8
  _QWORD *v29; // rcx
  unsigned __int64 v30; // rax
  _QWORD *v31; // rcx
  _QWORD *v32; // r8
  _QWORD *v33; // rcx
  unsigned __int64 v34; // rax
  _QWORD *v35; // rcx
  __int64 v36; // rax
  unsigned int v37; // edi
  hkLifoAllocator *v38; // rax
  hkpContactImpulseLimitBreachedListenerInfo *v39; // r14
  int v40; // r15d
  char *v41; // rcx
  __int64 v42; // r9
  int i; // r11d
  int *v44; // rcx
  __int64 v45; // rdx
  char *v46; // r10
  int v47; // eax
  hkLifoAllocator *v48; // rax
  int v49; // r8d
  _QWORD *v50; // r8
  _QWORD *v51; // rcx
  unsigned __int64 v52; // rax
  _QWORD *v53; // rcx
  _QWORD *v54; // r8
  _QWORD *v55; // rcx
  unsigned __int64 v56; // rax
  _QWORD *v57; // rcx
  _QWORD *v58; // r8
  unsigned __int64 v59; // rcx
  unsigned __int64 v60; // rax
  __int64 v61; // r14
  hkpWorld *v62; // rdi
  _QWORD *v63; // r8
  _QWORD *v64; // rcx
  unsigned __int64 v65; // rax
  _QWORD *v66; // rcx
  int m_size; // ebx
  hkMemorySystem *Instance; // rax
  _QWORD *v69; // r8
  _QWORD *v70; // rcx
  unsigned __int64 v71; // rax
  _QWORD *v72; // rcx
  hkpCollisionFilter *m_collisionFilter; // rax
  hkpCollidableCollidableFilter *v74; // r9
  _QWORD *v75; // r8
  _QWORD *v76; // rcx
  unsigned __int64 v77; // rax
  _QWORD *v78; // rcx
  _QWORD *v79; // rbx
  _QWORD **v80; // rax
  _QWORD *v81; // rbx
  _QWORD **v82; // rax
  __int64 v83; // rdi
  unsigned int v84; // ebx
  _QWORD **v85; // rax
  int v86; // edi
  __int64 v87; // rbx
  _QWORD **v88; // rax
  int v89; // r8d
  _QWORD **v90; // rax
  int v91; // r12d
  signed int v92; // r11d
  int v93; // r13d
  __int64 v94; // r9
  hkJobQueue::JobQueueEntry **v95; // r15
  __int64 v96; // rdi
  hkpWorld *v97; // r10
  int m_maxSectorsPerMidphaseCollideTask; // esi
  int v99; // r14d
  hkJobQueue::JobQueueEntry *v100; // r8
  bool v101; // zf
  __int16 v102; // dx
  __int16 v103; // ax
  char v104; // al
  hkpAgentSectorHeader *v105; // rax
  hkJobQueue *v106; // r15
  int v107; // edi
  __int64 v108; // rbx
  hkpAgentSectorHeader *j; // rsi
  hkJobQueue::JobQueueEntry *v110; // rdx
  hkJobQueue::JobQueueEntry *v111; // rbx
  _QWORD *v112; // r9
  _QWORD *v113; // rcx
  unsigned __int64 v114; // rax
  _QWORD *v115; // rcx
  unsigned int NextJob; // eax
  _QWORD *v117; // r8
  _QWORD *v118; // rcx
  unsigned __int64 v119; // rax
  _QWORD *v120; // rcx
  char *v121; // rdi
  unsigned int v122; // esi
  int v123; // eax
  signed int v124; // ebx
  hkLifoAllocator *v125; // rax
  int v126; // r8d
  int v127; // eax
  char *v128; // rdi
  signed int v129; // ebx
  hkLifoAllocator *v130; // rax
  int v131; // r8d
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> delPairs; // [rsp+30h] [rbp-D0h] BYREF
  void *p; // [rsp+40h] [rbp-C0h]
  int v135; // [rsp+48h] [rbp-B8h]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> newPairs; // [rsp+50h] [rbp-B0h] BYREF
  void *v137; // [rsp+60h] [rbp-A0h]
  int v138; // [rsp+68h] [rbp-98h]
  __int64 v139; // [rsp+70h] [rbp-90h]
  hkJobQueue::JobQueueEntry *job[2]; // [rsp+78h] [rbp-88h] BYREF
  __int64 v141[3]; // [rsp+88h] [rbp-78h]
  char v142; // [rsp+A0h] [rbp-60h] BYREF
  int v146; // [rsp+208h] [rbp+108h]
  __int64 v147; // [rsp+208h] [rbp+108h]

  v3 = *(_QWORD *)&nextJobOut->m_data[8];
  v139 = v3;
  v5 = nextJobOut;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtBroadphase";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  if ( *(_DWORD *)(*(_QWORD *)&v5->m_data[16] + 8i64)
    && tl->m_world->m_wantDeactivation.m_bool
    && (*(_BYTE *)(v3 + 50) & 0xC) != 0
    && (*(_BYTE *)(v3 + 49) & 0xC) == 0 )
  {
    hkpWorldOperationUtil::markIslandInactiveMt(tl->m_world, (hkpSimulationIsland *)v3);
  }
  v11 = 0;
  m_broadPhaseUpdateSize = tl->m_world->m_broadPhaseUpdateSize;
  v13 = (_BYTE *)(*(_QWORD *)&v5->m_data[16] + 40i64);
  newPairs.m_data = 0i64;
  newPairs.m_size = 0;
  newPairs.m_capacityAndFlags = 0x80000000;
  v138 = m_broadPhaseUpdateSize;
  if ( m_broadPhaseUpdateSize )
  {
    v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkpBroadPhaseHandlePair *)v14->m_cur;
    v16 = (16 * m_broadPhaseUpdateSize + 127) & 0xFFFFFF80;
    v17 = (char *)m_cur + v16;
    if ( v16 > v14->m_slabSize || v17 > v14->m_end )
      m_cur = (hkpBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v14, v16);
    else
      v14->m_cur = v17;
  }
  else
  {
    m_cur = 0i64;
  }
  newPairs.m_data = m_cur;
  v137 = m_cur;
  m_world = tl->m_world;
  newPairs.m_capacityAndFlags = m_broadPhaseUpdateSize | 0x80000000;
  v19 = m_world->m_broadPhaseUpdateSize;
  delPairs.m_data = 0i64;
  delPairs.m_size = 0;
  delPairs.m_capacityAndFlags = 0x80000000;
  v135 = v19;
  if ( v19 )
  {
    v20 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v21 = (hkpBroadPhaseHandlePair *)v20->m_cur;
    v22 = (16 * v19 + 127) & 0xFFFFFF80;
    v23 = (char *)v21 + v22;
    if ( v22 > v20->m_slabSize || v23 > v20->m_end )
      v21 = (hkpBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v20, v22);
    else
      v20->m_cur = v23;
  }
  else
  {
    v21 = 0i64;
  }
  v24 = tl->m_world;
  m_storage = tl->m_simulation.m_storage;
  v26 = *(_QWORD *)&v5->m_data[16];
  delPairs.m_data = v21;
  p = v21;
  delPairs.m_capacityAndFlags = v19 | 0x80000000;
  hkpContinuousSimulation::collideEntitiesBroadPhaseContinuousFindPairs(
    m_storage,
    *(hkpEntity ***)(v3 + 96),
    *(_DWORD *)(v3 + 104),
    v24,
    &newPairs,
    &delPairs);
  v146 = 1 - *(_DWORD *)(v26 + 16);
  if ( *(_DWORD *)(v26 + 16) == 1 )
  {
    v27 = *(_DWORD *)(v26 + 12);
    *(_DWORD *)(v26 + 12) = v27 - 1;
  }
  else
  {
    v27 = _InterlockedExchangeAdd((volatile signed __int32 *)(v26 + 12), 0xFFFFFFFF);
  }
  if ( v27 == *(_DWORD *)(v26 + 16) )
  {
    if ( v13 )
    {
      v28 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v29 = (_QWORD *)v28[1];
      if ( (unsigned __int64)v29 < v28[3] )
      {
        *v29 = "TtWaitForExport";
        v30 = __rdtsc();
        v31 = v29 + 2;
        *((_DWORD *)v31 - 2) = v30;
        v28[1] = v31;
      }
      while ( *v13 != 1 && *v13 != 2 )
        ;
      v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v33 = (_QWORD *)v32[1];
      if ( (unsigned __int64)v33 < v32[3] )
      {
        *v33 = "Et";
        v34 = __rdtsc();
        v35 = v33 + 2;
        *((_DWORD *)v35 - 2) = v34;
        v32[1] = v35;
      }
    }
    v36 = *(_QWORD *)(v26 + 48);
    if ( v36 )
    {
      v37 = 0;
      do
      {
        v37 += *(_DWORD *)v36;
        v36 = *(_QWORD *)(v36 + 8);
      }
      while ( v36 );
      v38 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v39 = (hkpContactImpulseLimitBreachedListenerInfo *)v38->m_cur;
      v40 = (32 * v37 + 127) & 0xFFFFFF80;
      v41 = (char *)v39 + v40;
      if ( v40 > v38->m_slabSize || v41 > v38->m_end )
        v39 = (hkpContactImpulseLimitBreachedListenerInfo *)hkLifoAllocator::allocateFromNewSlab(v38, v40);
      else
        v38->m_cur = v41;
      v42 = *(_QWORD *)(v26 + 48);
      for ( i = 0; v42; v42 = *(_QWORD *)(v42 + 8) )
      {
        v44 = (int *)(v42 + 16);
        v45 = (unsigned int)(8 * *(_DWORD *)v42);
        if ( (int)v45 > 0 )
        {
          v46 = (char *)v39 + 32i64 * i - (_QWORD)v44;
          do
          {
            v47 = *v44++;
            *(int *)((char *)v44 + (_QWORD)v46 - 4) = v47;
            --v45;
          }
          while ( v45 );
        }
        i += *(_DWORD *)v42;
      }
      hkpWorldCallbackUtil::fireContactImpulseLimitBreached(tl->m_world, v39, v37);
      v48 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v49 = (v40 + 15) & 0xFFFFFFF0;
      if ( v40 <= v48->m_slabSize && (char *)v39 + v49 == v48->m_cur && v48->m_firstNonLifoEnd != v39 )
      {
        v5 = nextJobOut;
        v48->m_cur = v39;
        v3 = v139;
        *v13 = 2;
        goto LABEL_57;
      }
      hkLifoAllocator::slowBlockFree(v48, (char *)v39, v49);
      v3 = v139;
      v5 = nextJobOut;
    }
    *v13 = 2;
  }
  else
  {
    if ( *v13 != 2 )
    {
      v50 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v51 = (_QWORD *)v50[1];
      if ( (unsigned __int64)v51 < v50[3] )
      {
        *v51 = "TtWaitForSolverCallbacks";
        v52 = __rdtsc();
        v53 = v51 + 2;
        *((_DWORD *)v53 - 2) = v52;
        v50[1] = v53;
      }
      while ( *v13 != 2 )
        ;
      v54 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v55 = (_QWORD *)v54[1];
      if ( (unsigned __int64)v55 < v54[3] )
      {
        *v55 = "Et";
        v56 = __rdtsc();
        v57 = v55 + 2;
        *((_DWORD *)v57 - 2) = v56;
        v54[1] = v57;
      }
    }
    v11 = -1;
    if ( *(int *)(v26 + 16) > 2 )
      v11 = _InterlockedDecrement((volatile signed __int32 *)(v26 + 12));
  }
LABEL_57:
  if ( delPairs.m_size + newPairs.m_size > 0 )
  {
    v58 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v59 = v58[1];
    if ( v59 < v58[3] )
    {
      *(_QWORD *)v59 = "LtAddRemoveAgnts";
      *(_QWORD *)(v59 + 16) = "StInit";
      v60 = __rdtsc();
      *(_DWORD *)(v59 + 8) = v60;
      v58[1] = v59 + 24;
    }
    v61 = *(_QWORD *)(v3 + 96);
    v62 = tl->m_world;
    if ( delPairs.m_size + newPairs.m_size > 0 )
    {
      v63 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v64 = (_QWORD *)v63[1];
      if ( (unsigned __int64)v64 < v63[3] )
      {
        *v64 = "StRemoveAgt";
        v65 = __rdtsc();
        v66 = v64 + 2;
        *((_DWORD *)v66 - 2) = v65;
        v63[1] = v66;
      }
      hkpWorld::lockIslandForConstraintUpdate(v62, *(hkpSimulationIsland **)(*(_QWORD *)v61 + 296i64));
      hkpTypedBroadPhaseDispatcher::removePairs(
        v62->m_broadPhaseDispatcher,
        (hkpTypedBroadPhaseHandlePair *)delPairs.m_data,
        delPairs.m_size);
      m_size = newPairs.m_size;
      Instance = hkMemorySystem::getInstance();
      if ( Instance->vfptr->heapCanAllocTotal(Instance, m_size << 10) )
      {
        v69 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v70 = (_QWORD *)v69[1];
        if ( (unsigned __int64)v70 < v69[3] )
        {
          *v70 = "StAddAgt";
          v71 = __rdtsc();
          v72 = v70 + 2;
          *((_DWORD *)v72 - 2) = v71;
          v69[1] = v72;
        }
        m_collisionFilter = v62->m_collisionFilter;
        if ( m_collisionFilter )
          v74 = &m_collisionFilter->hkpCollidableCollidableFilter;
        else
          v74 = 0i64;
        hkpTypedBroadPhaseDispatcher::addPairs(
          v62->m_broadPhaseDispatcher,
          (hkpTypedBroadPhaseHandlePair *)newPairs.m_data,
          newPairs.m_size,
          v74);
      }
      hkpWorld::unlockIslandForConstraintUpdate(v62, *(hkpSimulationIsland **)(*(_QWORD *)v61 + 296i64));
    }
    v75 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v76 = (_QWORD *)v75[1];
    if ( (unsigned __int64)v76 < v75[3] )
    {
      *v76 = "lt";
      v77 = __rdtsc();
      v78 = v76 + 2;
      *((_DWORD *)v78 - 2) = v77;
      v75[1] = v78;
    }
  }
  if ( v11 == v146 )
  {
    while ( *(_QWORD *)(v26 + 152) )
    {
      v79 = *(_QWORD **)(v26 + 152);
      *(_QWORD *)(v26 + 152) = *v79;
      v80 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, _QWORD *, __int64))(*v80[11] + 16i64))(v80[11], v79, 3968i64);
    }
    while ( *(_QWORD *)(v26 + 184) )
    {
      v81 = *(_QWORD **)(v26 + 184);
      *(_QWORD *)(v26 + 184) = *v81;
      v82 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, _QWORD *, __int64))(*v82[11] + 16i64))(v82[11], v81, 64i64);
    }
    v83 = *(_QWORD *)(v26 + 24);
    if ( v83 )
    {
      v84 = *(_DWORD *)(v26 + 36);
      v85 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, __int64, _QWORD))(*v85[13] + 32i64))(v85[13], v83, v84);
      *(_QWORD *)(v26 + 24) = 0i64;
    }
    if ( *(int *)(v26 + 16) > 1 )
    {
      v86 = *(unsigned __int16 *)(v26 + 130);
      v87 = *(_QWORD *)(v26 + 120);
      v88 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, __int64, _QWORD))(*v88[11] + 32i64))(v88[11], v87, (unsigned int)(8 * v86));
      *(_QWORD *)(v26 + 120) = 0i64;
    }
    v89 = *(_DWORD *)(v26 + 148);
    *(_DWORD *)(v26 + 144) = 0;
    if ( v89 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        *(void **)(v26 + 136),
        8 * v89);
    *(_QWORD *)(v26 + 136) = 0i64;
    *(_DWORD *)(v26 + 148) = 0x80000000;
    v90 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, __int64, __int64))(*v90[11] + 16i64))(v90[11], v26, 208i64);
  }
  job[0] = v5;
  job[1] = (hkJobQueue::JobQueueEntry *)&v142;
  v91 = 0;
  v141[0] = v139 + 152;
  v92 = 0;
  v93 = 0;
  v94 = 0i64;
  v95 = job;
  v141[1] = v139 + 120;
  do
  {
    v96 = v141[v94];
    v97 = tl->m_world;
    if ( v94 )
      m_maxSectorsPerMidphaseCollideTask = v97->m_maxSectorsPerMidphaseCollideTask;
    else
      m_maxSectorsPerMidphaseCollideTask = v97->m_maxSectorsPerNarrowphaseCollideTask;
    v99 = *(_DWORD *)(v96 + 16);
    v147 = *(_QWORD *)(v96 + 8);
    if ( v99 > 0 )
    {
      v100 = *v95;
      if ( *v95 )
      {
        v101 = v97->m_useCompoundSpuElf.m_bool == 0;
        v102 = *(_WORD *)v96;
        *(_WORD *)&v100->m_jobSubType = 13;
        v100->m_jobSpuType.m_storage = 1;
        v100->m_size = 112;
        v100->m_threadAffinity = -1;
        *(_WORD *)v100->m_data = *(_WORD *)nextJobOut->m_data;
        *(_QWORD *)&v100->m_data[8] = *(_QWORD *)&nextJobOut->m_data[8];
        *(_QWORD *)&v100->m_data[16] = *(_QWORD *)&nextJobOut->m_data[16];
        *(_QWORD *)&v100->m_data[24] = *(_QWORD *)&nextJobOut->m_data[24];
        *(hkStepInfo *)&v100->m_data[64] = v97->m_dynamicsStepInfo.m_stepInfo;
        v103 = *(_WORD *)nextJobOut->m_data;
        *(_WORD *)&v100->m_data[40] = 0;
        *(_WORD *)v100->m_data = v103;
        *(_WORD *)&v100->m_data[42] = v99;
        *(_QWORD *)&v100->m_data[48] = v147;
        *(_WORD *)&v100->m_data[44] = m_maxSectorsPerMidphaseCollideTask;
        v100->m_data[46] = (v93 == 0) + 1;
        v104 = 1;
        *(_QWORD *)&v100->m_data[32] = 0i64;
        if ( !v101 )
          v104 = 18;
        *(_QWORD *)&v100->m_data[80] = 0i64;
        *(_WORD *)&v100->m_data[88] = v102;
        v100->m_jobType.m_storage = v104;
      }
      else
      {
        v100 = 0i64;
      }
      *(_WORD *)&v100->m_data[40] = v92;
      ++v91;
      ++v95;
      v92 += (v99 - 1) / m_maxSectorsPerMidphaseCollideTask + 1;
    }
    ++v94;
    ++v93;
  }
  while ( v94 < 2 );
  if ( v91 )
  {
    if ( v92 <= 1 )
    {
      v111 = nextJobOut;
      v106 = jobQueue;
      *(_QWORD *)&nextJobOut->m_data[80] = 0i64;
    }
    else
    {
      v105 = hkpAgentSectorHeader::allocate(v92, 48);
      v106 = jobQueue;
      v107 = 0;
      v108 = 0i64;
      v105->m_shapeKeyTracks = 0i64;
      v105->m_numShapeKeyTracks = 0;
      for ( j = v105; v108 < v91; ++v107 )
      {
        v110 = job[v108];
        *(_QWORD *)&v110->m_data[32] = j;
        if ( v107 )
          hkJobQueue::addJob(jobQueue, v110, JOB_LOW_PRIORITY);
        ++v108;
      }
      v111 = nextJobOut;
    }
    v112 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v113 = (_QWORD *)v112[1];
    if ( (unsigned __int64)v113 < v112[3] )
    {
      *v113 = "Et";
      v114 = __rdtsc();
      v115 = v113 + 2;
      *((_DWORD *)v115 - 2) = v114;
      v112[1] = v115;
    }
    NextJob = hkJobQueue::finishAddAndGetNextJob(v106, HK_JOB_TYPE_DYNAMICS, JOB_LOW_PRIORITY, v111, WAIT_FOR_NEXT_JOB);
  }
  else
  {
    v117 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v118 = (_QWORD *)v117[1];
    if ( (unsigned __int64)v118 < v117[3] )
    {
      *v118 = "Et";
      v119 = __rdtsc();
      v120 = v118 + 2;
      *((_DWORD *)v120 - 2) = v119;
      v117[1] = v120;
    }
    NextJob = hkJobQueue::finishJobAndGetNextJob(jobQueue, nextJobOut, nextJobOut, WAIT_FOR_NEXT_JOB);
  }
  v121 = (char *)p;
  v122 = NextJob;
  v123 = delPairs.m_size;
  if ( p == delPairs.m_data )
    v123 = 0;
  delPairs.m_size = v123;
  v124 = (16 * v135 + 127) & 0xFFFFFF80;
  v125 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v126 = (v124 + 15) & 0xFFFFFFF0;
  if ( v124 > v125->m_slabSize || &v121[v126] != v125->m_cur || v125->m_firstNonLifoEnd == v121 )
    hkLifoAllocator::slowBlockFree(v125, v121, v126);
  else
    v125->m_cur = v121;
  delPairs.m_size = 0;
  if ( delPairs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      delPairs.m_data,
      16 * delPairs.m_capacityAndFlags);
  v127 = newPairs.m_size;
  v128 = (char *)v137;
  delPairs.m_data = 0i64;
  if ( v137 == newPairs.m_data )
    v127 = 0;
  delPairs.m_capacityAndFlags = 0x80000000;
  newPairs.m_size = v127;
  v129 = (16 * v138 + 127) & 0xFFFFFF80;
  v130 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v131 = (v129 + 15) & 0xFFFFFFF0;
  if ( v129 > v130->m_slabSize || &v128[v131] != v130->m_cur || v130->m_firstNonLifoEnd == v128 )
    hkLifoAllocator::slowBlockFree(v130, v128, v131);
  else
    v130->m_cur = v128;
  newPairs.m_size = 0;
  if ( newPairs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      newPairs.m_data,
      16 * newPairs.m_capacityAndFlags);
  return v122;
}


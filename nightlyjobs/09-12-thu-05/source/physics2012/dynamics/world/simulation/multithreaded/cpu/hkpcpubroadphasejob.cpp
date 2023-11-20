// File Line: 27
// RVA: 0xD95850
void __fastcall deleteTaskHeaderResources(hkpBuildJacobianTaskHeader *taskHeader)
{
  hkpBuildJacobianTaskHeader *v1; // rbx
  hkpBuildJacobianTask *v2; // rdi
  _QWORD **v3; // rax
  hkpSolveConstraintBatchTask *v4; // rdi
  _QWORD **v5; // rax
  void *v6; // rsi
  unsigned int v7; // edi
  _QWORD **v8; // rax
  int v9; // esi
  hkpEntity *const *v10; // rdi
  _QWORD **v11; // rax
  int v12; // er8
  _QWORD **v13; // rax

  v1 = taskHeader;
  while ( v1->m_tasks.m_buildJacobianTasks )
  {
    v2 = v1->m_tasks.m_buildJacobianTasks;
    v1->m_tasks.m_buildJacobianTasks = v2->m_next;
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpBuildJacobianTask *, signed __int64))(*v3[11] + 16i64))(v3[11], v2, 3968i64);
  }
  while ( v1->m_solveTasks.m_firstSolveJacobiansTask )
  {
    v4 = v1->m_solveTasks.m_firstSolveJacobiansTask;
    v1->m_solveTasks.m_firstSolveJacobiansTask = v4->m_next;
    v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpSolveConstraintBatchTask *, signed __int64))(*v5[11] + 16i64))(
      v5[11],
      v4,
      64i64);
  }
  v6 = v1->m_buffer;
  if ( v6 )
  {
    v7 = v1->m_bufferCapacity;
    v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*v8[13] + 32i64))(v8[13], v6, v7);
    v1->m_buffer = 0i64;
  }
  if ( v1->m_numIslandsAfterSplit > 1 )
  {
    v9 = v1->m_entitiesCapacity;
    v10 = v1->m_allEntities;
    v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpEntity *const *, _QWORD))(*v11[11] + 32i64))(
      v11[11],
      v10,
      (unsigned int)(8 * v9));
    v1->m_allEntities = 0i64;
  }
  v12 = v1->m_newSplitIslands.m_capacityAndFlags;
  v1->m_newSplitIslands.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_newSplitIslands.m_data,
      8 * v12);
  v1->m_newSplitIslands.m_data = 0i64;
  v1->m_newSplitIslands.m_capacityAndFlags = 2147483648;
  v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkpBuildJacobianTaskHeader *, signed __int64))(*v13[11] + 16i64))(
    v13[11],
    v1,
    208i64);
}

// File Line: 65
// RVA: 0xD94D40
__int64 __fastcall hkpSingleThreadedJobsOnIsland::cpuBroadPhaseJob(hkpMtThreadStructure *tl, hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  __int64 v3; // r14
  hkpMtThreadStructure *v4; // r12
  hkJobQueue::JobQueueEntry *v5; // r15
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  signed __int32 v11; // er13
  int v12; // edi
  _BYTE *v13; // rbx
  LPVOID v14; // rax
  hkLifoAllocator *v15; // rcx
  hkpBroadPhaseHandlePair *v16; // rax
  int v17; // edx
  char *v18; // r8
  hkpWorld *v19; // rax
  int v20; // edi
  LPVOID v21; // rax
  hkLifoAllocator *v22; // rcx
  hkpBroadPhaseHandlePair *v23; // rax
  int v24; // edx
  char *v25; // r8
  hkpWorld *v26; // r9
  hkpContinuousSimulation *v27; // rcx
  __int64 v28; // rsi
  signed __int32 v29; // ecx
  _QWORD *v30; // r8
  _QWORD *v31; // rcx
  unsigned __int64 v32; // rax
  signed __int64 v33; // rcx
  _QWORD *v34; // r8
  _QWORD *v35; // rcx
  unsigned __int64 v36; // rax
  signed __int64 v37; // rcx
  __int64 v38; // rax
  int v39; // edi
  hkLifoAllocator *v40; // rax
  hkpContactImpulseLimitBreachedListenerInfo *v41; // r14
  int v42; // er15
  char *v43; // rcx
  __int64 v44; // r9
  int i; // er11
  int *v46; // rcx
  __int64 v47; // rdx
  signed __int64 v48; // r10
  int v49; // eax
  hkLifoAllocator *v50; // rax
  int v51; // er8
  _QWORD *v52; // r8
  _QWORD *v53; // rcx
  unsigned __int64 v54; // rax
  signed __int64 v55; // rcx
  _QWORD *v56; // r8
  _QWORD *v57; // rcx
  unsigned __int64 v58; // rax
  signed __int64 v59; // rcx
  _QWORD *v60; // r8
  unsigned __int64 v61; // rcx
  unsigned __int64 v62; // rax
  __int64 v63; // r14
  hkpWorld *v64; // rdi
  _QWORD *v65; // r8
  _QWORD *v66; // rcx
  unsigned __int64 v67; // rax
  signed __int64 v68; // rcx
  int v69; // ebx
  hkMemorySystem *v70; // rax
  _QWORD *v71; // r8
  _QWORD *v72; // rcx
  unsigned __int64 v73; // rax
  signed __int64 v74; // rcx
  hkpCollisionFilter *v75; // rax
  hkpCollidableCollidableFilter *v76; // r9
  _QWORD *v77; // r8
  _QWORD *v78; // rcx
  unsigned __int64 v79; // rax
  signed __int64 v80; // rcx
  _QWORD *v81; // rbx
  _QWORD **v82; // rax
  _QWORD *v83; // rbx
  _QWORD **v84; // rax
  __int64 v85; // rdi
  unsigned int v86; // ebx
  _QWORD **v87; // rax
  int v88; // edi
  __int64 v89; // rbx
  _QWORD **v90; // rax
  int v91; // er8
  _QWORD **v92; // rax
  int v93; // er12
  int v94; // er11
  int v95; // er13
  signed __int64 v96; // r9
  hkJobQueue::JobQueueEntry **v97; // r15
  __int16 *v98; // rdi
  hkpWorld *v99; // r10
  int v100; // esi
  int v101; // er14
  hkJobQueue::JobQueueEntry *v102; // r8
  bool v103; // zf
  __int16 v104; // dx
  __int16 v105; // ax
  char v106; // al
  hkpAgentSectorHeader *v107; // rax
  hkJobQueue *v108; // r15
  int v109; // edi
  signed __int64 v110; // rbx
  hkpAgentSectorHeader *v111; // rsi
  __int64 v112; // rdx
  hkJobQueue::JobQueueEntry *v113; // rbx
  _QWORD *v114; // r9
  _QWORD *v115; // rcx
  unsigned __int64 v116; // rax
  signed __int64 v117; // rcx
  unsigned int v118; // eax
  _QWORD *v119; // r8
  _QWORD *v120; // rcx
  unsigned __int64 v121; // rax
  signed __int64 v122; // rcx
  char *v123; // rdi
  unsigned int v124; // esi
  int v125; // eax
  signed int v126; // ebx
  hkLifoAllocator *v127; // rax
  int v128; // er8
  int v129; // eax
  char *v130; // rdi
  signed int v131; // ebx
  hkLifoAllocator *v132; // rax
  int v133; // er8
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> delPairs; // [rsp+30h] [rbp-D0h]
  void *p; // [rsp+40h] [rbp-C0h]
  int v137; // [rsp+48h] [rbp-B8h]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> newPairs; // [rsp+50h] [rbp-B0h]
  void *v139; // [rsp+60h] [rbp-A0h]
  int v140; // [rsp+68h] [rbp-98h]
  __int64 v141; // [rsp+70h] [rbp-90h]
  hkJobQueue::JobQueueEntry *job; // [rsp+78h] [rbp-88h]
  char *v143; // [rsp+80h] [rbp-80h]
  __int64 v144; // [rsp+88h] [rbp-78h]
  __int64 v145; // [rsp+90h] [rbp-70h]
  char v146; // [rsp+A0h] [rbp-60h]
  hkpMtThreadStructure *v147; // [rsp+1F0h] [rbp+F0h]
  hkJobQueue *v148; // [rsp+1F8h] [rbp+F8h]
  hkJobQueue::JobQueueEntry *jobInOut; // [rsp+200h] [rbp+100h]
  int v150; // [rsp+208h] [rbp+108h]
  __int64 v151; // [rsp+208h] [rbp+108h]

  jobInOut = nextJobOut;
  v148 = jobQueue;
  v147 = tl;
  v3 = *(_QWORD *)&nextJobOut->m_data[8];
  v4 = tl;
  v141 = *(_QWORD *)&nextJobOut->m_data[8];
  v5 = nextJobOut;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtBroadphase";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  if ( *(_DWORD *)(*(_QWORD *)&v5->m_data[16] + 8i64)
    && v4->m_world->m_wantDeactivation.m_bool
    && *(_BYTE *)(v3 + 50) & 0xC
    && !(*(_BYTE *)(v3 + 49) & 0xC) )
  {
    hkpWorldOperationUtil::markIslandInactiveMt(v4->m_world, (hkpSimulationIsland *)v3);
  }
  v11 = 0;
  v12 = v4->m_world->m_broadPhaseUpdateSize;
  v13 = (_BYTE *)(*(_QWORD *)&v5->m_data[16] + 40i64);
  newPairs.m_data = 0i64;
  newPairs.m_size = 0;
  newPairs.m_capacityAndFlags = 2147483648;
  v140 = v12;
  if ( v12 )
  {
    v14 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (hkLifoAllocator *)v14;
    v16 = (hkpBroadPhaseHandlePair *)*((_QWORD *)v14 + 3);
    v17 = (16 * v12 + 127) & 0xFFFFFF80;
    v18 = (char *)v16 + v17;
    if ( v17 > v15->m_slabSize || v18 > v15->m_end )
      v16 = (hkpBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v15, v17);
    else
      v15->m_cur = v18;
  }
  else
  {
    v16 = 0i64;
  }
  newPairs.m_data = v16;
  v139 = v16;
  v19 = v4->m_world;
  newPairs.m_capacityAndFlags = v12 | 0x80000000;
  v20 = v19->m_broadPhaseUpdateSize;
  delPairs.m_data = 0i64;
  delPairs.m_size = 0;
  delPairs.m_capacityAndFlags = 2147483648;
  v137 = v20;
  if ( v20 )
  {
    v21 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v22 = (hkLifoAllocator *)v21;
    v23 = (hkpBroadPhaseHandlePair *)*((_QWORD *)v21 + 3);
    v24 = (16 * v20 + 127) & 0xFFFFFF80;
    v25 = (char *)v23 + v24;
    if ( v24 > v22->m_slabSize || v25 > v22->m_end )
      v23 = (hkpBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v22, v24);
    else
      v22->m_cur = v25;
  }
  else
  {
    v23 = 0i64;
  }
  v26 = v4->m_world;
  v27 = (hkpContinuousSimulation *)&v4->m_simulation.m_storage->vfptr;
  v28 = *(_QWORD *)&v5->m_data[16];
  delPairs.m_data = v23;
  p = v23;
  delPairs.m_capacityAndFlags = v20 | 0x80000000;
  hkpContinuousSimulation::collideEntitiesBroadPhaseContinuousFindPairs(
    v27,
    *(hkpEntity ***)(v3 + 96),
    *(_DWORD *)(v3 + 104),
    v26,
    &newPairs,
    &delPairs);
  v150 = 1 - *(_DWORD *)(v28 + 16);
  if ( *(_DWORD *)(v28 + 16) == 1 )
  {
    v29 = *(_DWORD *)(v28 + 12);
    *(_DWORD *)(v28 + 12) = v29 - 1;
  }
  else
  {
    v29 = _InterlockedExchangeAdd((volatile signed __int32 *)(v28 + 12), 0xFFFFFFFF);
  }
  if ( v29 == *(_DWORD *)(v28 + 16) )
  {
    if ( v13 )
    {
      v30 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v31 = (_QWORD *)v30[1];
      if ( (unsigned __int64)v31 < v30[3] )
      {
        *v31 = "TtWaitForExport";
        v32 = __rdtsc();
        v33 = (signed __int64)(v31 + 2);
        *(_DWORD *)(v33 - 8) = v32;
        v30[1] = v33;
      }
      while ( *v13 != 1 && *v13 != 2 )
        ;
      v34 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v35 = (_QWORD *)v34[1];
      if ( (unsigned __int64)v35 < v34[3] )
      {
        *v35 = "Et";
        v36 = __rdtsc();
        v37 = (signed __int64)(v35 + 2);
        *(_DWORD *)(v37 - 8) = v36;
        v34[1] = v37;
      }
    }
    v38 = *(_QWORD *)(v28 + 48);
    if ( v38 )
    {
      v39 = 0;
      do
      {
        v39 += *(_DWORD *)v38;
        v38 = *(_QWORD *)(v38 + 8);
      }
      while ( v38 );
      v40 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v41 = (hkpContactImpulseLimitBreachedListenerInfo *)v40->m_cur;
      v42 = (32 * v39 + 127) & 0xFFFFFF80;
      v43 = (char *)v41 + v42;
      if ( v42 > v40->m_slabSize || v43 > v40->m_end )
        v41 = (hkpContactImpulseLimitBreachedListenerInfo *)hkLifoAllocator::allocateFromNewSlab(v40, v42);
      else
        v40->m_cur = v43;
      v44 = *(_QWORD *)(v28 + 48);
      for ( i = 0; v44; v44 = *(_QWORD *)(v44 + 8) )
      {
        v46 = (int *)(v44 + 16);
        v47 = (unsigned int)(8 * *(_DWORD *)v44);
        if ( (signed int)v47 > 0 )
        {
          v48 = (signed __int64)v41 + 32i64 * i - (_QWORD)v46;
          do
          {
            v49 = *v46;
            ++v46;
            *(int *)((char *)v46 + v48 - 4) = v49;
            --v47;
          }
          while ( v47 );
        }
        i += *(_DWORD *)v44;
      }
      hkpWorldCallbackUtil::fireContactImpulseLimitBreached(v4->m_world, v41, v39);
      v50 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v51 = (v42 + 15) & 0xFFFFFFF0;
      if ( v42 <= v50->m_slabSize && (char *)v41 + v51 == v50->m_cur && v50->m_firstNonLifoEnd != v41 )
      {
        v5 = jobInOut;
        v50->m_cur = v41;
        v3 = v141;
        *v13 = 2;
        goto LABEL_57;
      }
      hkLifoAllocator::slowBlockFree(v50, v41, v51);
      v3 = v141;
      v5 = jobInOut;
    }
    *v13 = 2;
  }
  else
  {
    if ( *v13 != 2 )
    {
      v52 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v53 = (_QWORD *)v52[1];
      if ( (unsigned __int64)v53 < v52[3] )
      {
        *v53 = "TtWaitForSolverCallbacks";
        v54 = __rdtsc();
        v55 = (signed __int64)(v53 + 2);
        *(_DWORD *)(v55 - 8) = v54;
        v52[1] = v55;
      }
      while ( *v13 != 2 )
        ;
      v56 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v57 = (_QWORD *)v56[1];
      if ( (unsigned __int64)v57 < v56[3] )
      {
        *v57 = "Et";
        v58 = __rdtsc();
        v59 = (signed __int64)(v57 + 2);
        *(_DWORD *)(v59 - 8) = v58;
        v56[1] = v59;
      }
    }
    v11 = -1;
    if ( *(_DWORD *)(v28 + 16) > 2 )
      v11 = _InterlockedDecrement((volatile signed __int32 *)(v28 + 12));
  }
LABEL_57:
  if ( delPairs.m_size + newPairs.m_size > 0 )
  {
    v60 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v61 = v60[1];
    if ( v61 < v60[3] )
    {
      *(_QWORD *)v61 = "LtAddRemoveAgnts";
      *(_QWORD *)(v61 + 16) = "StInit";
      v62 = __rdtsc();
      *(_DWORD *)(v61 + 8) = v62;
      v60[1] = v61 + 24;
    }
    v63 = *(_QWORD *)(v3 + 96);
    v64 = v4->m_world;
    if ( delPairs.m_size + newPairs.m_size > 0 )
    {
      v65 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v66 = (_QWORD *)v65[1];
      if ( (unsigned __int64)v66 < v65[3] )
      {
        *v66 = "StRemoveAgt";
        v67 = __rdtsc();
        v68 = (signed __int64)(v66 + 2);
        *(_DWORD *)(v68 - 8) = v67;
        v65[1] = v68;
      }
      hkpWorld::lockIslandForConstraintUpdate(v64, *(hkpSimulationIsland **)(*(_QWORD *)v63 + 296i64));
      hkpTypedBroadPhaseDispatcher::removePairs(
        v64->m_broadPhaseDispatcher,
        (hkpTypedBroadPhaseHandlePair *)delPairs.m_data,
        delPairs.m_size);
      v69 = newPairs.m_size;
      v70 = hkMemorySystem::getInstance();
      if ( v70->vfptr->heapCanAllocTotal(v70, v69 << 10) )
      {
        v71 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v72 = (_QWORD *)v71[1];
        if ( (unsigned __int64)v72 < v71[3] )
        {
          *v72 = "StAddAgt";
          v73 = __rdtsc();
          v74 = (signed __int64)(v72 + 2);
          *(_DWORD *)(v74 - 8) = v73;
          v71[1] = v74;
        }
        v75 = v64->m_collisionFilter;
        if ( v75 )
          v76 = (hkpCollidableCollidableFilter *)&v75->vfptr;
        else
          v76 = 0i64;
        hkpTypedBroadPhaseDispatcher::addPairs(
          v64->m_broadPhaseDispatcher,
          (hkpTypedBroadPhaseHandlePair *)newPairs.m_data,
          newPairs.m_size,
          v76);
      }
      hkpWorld::unlockIslandForConstraintUpdate(v64, *(hkpSimulationIsland **)(*(_QWORD *)v63 + 296i64));
    }
    v77 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v78 = (_QWORD *)v77[1];
    if ( (unsigned __int64)v78 < v77[3] )
    {
      *v78 = "lt";
      v79 = __rdtsc();
      v80 = (signed __int64)(v78 + 2);
      *(_DWORD *)(v80 - 8) = v79;
      v77[1] = v80;
    }
  }
  if ( v11 == v150 )
  {
    while ( *(_QWORD *)(v28 + 152) )
    {
      v81 = *(_QWORD **)(v28 + 152);
      *(_QWORD *)(v28 + 152) = *v81;
      v82 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, _QWORD *, signed __int64))(*v82[11] + 16i64))(v82[11], v81, 3968i64);
    }
    while ( *(_QWORD *)(v28 + 184) )
    {
      v83 = *(_QWORD **)(v28 + 184);
      *(_QWORD *)(v28 + 184) = *v83;
      v84 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, _QWORD *, signed __int64))(*v84[11] + 16i64))(v84[11], v83, 64i64);
    }
    v85 = *(_QWORD *)(v28 + 24);
    if ( v85 )
    {
      v86 = *(_DWORD *)(v28 + 36);
      v87 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, __int64, _QWORD))(*v87[13] + 32i64))(v87[13], v85, v86);
      *(_QWORD *)(v28 + 24) = 0i64;
    }
    if ( *(_DWORD *)(v28 + 16) > 1 )
    {
      v88 = *(unsigned __int16 *)(v28 + 130);
      v89 = *(_QWORD *)(v28 + 120);
      v90 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, __int64, _QWORD))(*v90[11] + 32i64))(v90[11], v89, (unsigned int)(8 * v88));
      *(_QWORD *)(v28 + 120) = 0i64;
    }
    v91 = *(_DWORD *)(v28 + 148);
    *(_DWORD *)(v28 + 144) = 0;
    if ( v91 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)(v28 + 136),
        8 * v91);
    *(_QWORD *)(v28 + 136) = 0i64;
    *(_DWORD *)(v28 + 148) = 2147483648;
    v92 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v92[11] + 16i64))(v92[11], v28, 208i64);
  }
  job = v5;
  v143 = &v146;
  v93 = 0;
  v144 = v141 + 152;
  v94 = 0;
  v95 = 0;
  v96 = 0i64;
  v97 = &job;
  v145 = v141 + 120;
  do
  {
    v98 = (__int16 *)*(&v144 + v96);
    v99 = v147->m_world;
    if ( v96 )
      v100 = v99->m_maxSectorsPerMidphaseCollideTask;
    else
      v100 = v99->m_maxSectorsPerNarrowphaseCollideTask;
    v101 = *((_DWORD *)v98 + 4);
    v151 = *((_QWORD *)v98 + 1);
    if ( v101 > 0 )
    {
      v102 = *v97;
      if ( *v97 )
      {
        v103 = v99->m_useCompoundSpuElf.m_bool == 0;
        v104 = *v98;
        *(_WORD *)&v102->m_jobSubType = 13;
        v102->m_jobSpuType.m_storage = 1;
        v102->m_size = 112;
        v102->m_threadAffinity = -1;
        *(_WORD *)v102->m_data = *(_WORD *)jobInOut->m_data;
        *(_QWORD *)&v102->m_data[8] = *(_QWORD *)&jobInOut->m_data[8];
        *(_QWORD *)&v102->m_data[16] = *(_QWORD *)&jobInOut->m_data[16];
        *(_QWORD *)&v102->m_data[24] = *(_QWORD *)&jobInOut->m_data[24];
        *(hkStepInfo *)&v102->m_data[64] = v99->m_dynamicsStepInfo.m_stepInfo;
        v105 = *(_WORD *)jobInOut->m_data;
        *(_WORD *)&v102->m_data[40] = 0;
        *(_WORD *)v102->m_data = v105;
        *(_WORD *)&v102->m_data[42] = v101;
        *(_QWORD *)&v102->m_data[48] = v151;
        *(_WORD *)&v102->m_data[44] = v100;
        v102->m_data[46] = (v95 == 0) + 1;
        v106 = 1;
        *(_QWORD *)&v102->m_data[32] = 0i64;
        if ( !v103 )
          v106 = 18;
        *(_QWORD *)&v102->m_data[80] = 0i64;
        *(_WORD *)&v102->m_data[88] = v104;
        v102->m_jobType.m_storage = v106;
      }
      else
      {
        v102 = 0i64;
      }
      *(_WORD *)&v102->m_data[40] = v94;
      ++v93;
      ++v97;
      v94 += (v101 - 1) / v100 + 1;
    }
    ++v96;
    ++v95;
  }
  while ( v96 < 2 );
  if ( v93 )
  {
    if ( v94 <= 1 )
    {
      v113 = jobInOut;
      v108 = v148;
      *(_QWORD *)&jobInOut->m_data[80] = 0i64;
    }
    else
    {
      v107 = hkpAgentSectorHeader::allocate(v94, 48);
      v108 = v148;
      v109 = 0;
      v110 = 0i64;
      v107->m_shapeKeyTracks = 0i64;
      v107->m_numShapeKeyTracks = 0;
      v111 = v107;
      if ( v93 > 0 )
      {
        do
        {
          v112 = (__int64)*(&job + v110);
          *(_QWORD *)(v112 + 48) = v111;
          if ( v109 )
            hkJobQueue::addJob(v148, (hkJobQueue::JobQueueEntry *)v112, JOB_LOW_PRIORITY);
          ++v110;
          ++v109;
        }
        while ( v110 < v93 );
      }
      v113 = jobInOut;
    }
    v114 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v115 = (_QWORD *)v114[1];
    if ( (unsigned __int64)v115 < v114[3] )
    {
      *v115 = "Et";
      v116 = __rdtsc();
      v117 = (signed __int64)(v115 + 2);
      *(_DWORD *)(v117 - 8) = v116;
      v114[1] = v117;
    }
    v118 = hkJobQueue::finishAddAndGetNextJob(v108, 0, JOB_LOW_PRIORITY, v113, 0);
  }
  else
  {
    v119 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v120 = (_QWORD *)v119[1];
    if ( (unsigned __int64)v120 < v119[3] )
    {
      *v120 = "Et";
      v121 = __rdtsc();
      v122 = (signed __int64)(v120 + 2);
      *(_DWORD *)(v122 - 8) = v121;
      v119[1] = v122;
    }
    v118 = hkJobQueue::finishJobAndGetNextJob(v148, jobInOut, jobInOut, 0);
  }
  v123 = (char *)p;
  v124 = v118;
  v125 = delPairs.m_size;
  if ( p == delPairs.m_data )
    v125 = 0;
  delPairs.m_size = v125;
  v126 = (16 * v137 + 127) & 0xFFFFFF80;
  v127 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v128 = (v126 + 15) & 0xFFFFFFF0;
  if ( v126 > v127->m_slabSize || &v123[v128] != v127->m_cur || v127->m_firstNonLifoEnd == v123 )
    hkLifoAllocator::slowBlockFree(v127, v123, v128);
  else
    v127->m_cur = v123;
  delPairs.m_size = 0;
  if ( delPairs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      delPairs.m_data,
      16 * delPairs.m_capacityAndFlags);
  v129 = newPairs.m_size;
  v130 = (char *)v139;
  delPairs.m_data = 0i64;
  if ( v139 == newPairs.m_data )
    v129 = 0;
  delPairs.m_capacityAndFlags = 2147483648;
  newPairs.m_size = v129;
  v131 = (16 * v140 + 127) & 0xFFFFFF80;
  v132 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v133 = (v131 + 15) & 0xFFFFFFF0;
  if ( v131 > v132->m_slabSize || &v130[v133] != v132->m_cur || v132->m_firstNonLifoEnd == v130 )
    hkLifoAllocator::slowBlockFree(v132, v130, v133);
  else
    v132->m_cur = v130;
  newPairs.m_size = 0;
  if ( newPairs.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      newPairs.m_data,
      16 * newPairs.m_capacityAndFlags);
  return v124;
}


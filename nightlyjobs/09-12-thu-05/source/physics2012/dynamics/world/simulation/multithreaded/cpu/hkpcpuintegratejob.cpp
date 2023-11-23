// File Line: 68
// RVA: 0xD93A80
hkBool *__fastcall canSolveOnSingleProcessor(hkBool *result, hkpBuildJacobianTaskHeader *taskHeader)
{
  result->m_bool = 0;
  return result;
}

// File Line: 111
// RVA: 0xD93A90
void __fastcall createAndAppendNewTask(
        hkpBuildJacobianTaskHeader *taskHeader,
        hkpBuildJacobianTaskCollection *outBuildCollection,
        hkpSolveJacobiansTaskCollection *outSolveCollection,
        hkpBuildJacobianTask **prevBuildTask,
        hkpSolveConstraintBatchTask **prevSolveTask,
        hkpSolveConstraintBatchTask **firstTaskOfPreviousBatch,
        hkpSolveConstraintBatchTask **firstTaskOfCurrentBatch,
        hkpJacobianSchema **schemas,
        hkpSolverElemTemp **elemTemp,
        hkLocalArray<hkConstraintInternalInfo> *constraintsForThisTask,
        int *batchIndexOfLastTask,
        int currentBatchIndex,
        unsigned __int16 **ptrToBatchSize,
        hkBool putOnPpuOnlyBuildJacobianTaskList,
        hkBool generateSolveTasks,
        hkArray<hkConstraintInternalCallbackInfo,hkContainerHeapAllocator> *callbackConstraints)
{
  hkpBuildJacobianTaskHeader *v18; // r14
  hkpJacobianSchema *v19; // r12
  _QWORD **Value; // rax
  __int64 v23; // rax
  hkpBuildJacobianTask *v24; // r8
  hkpVelocityAccumulator *m_accumulatorsBase; // rax
  __int64 m_size; // rbp
  __int64 v27; // r14
  hkpConstraintInstance **p_m_instance; // r10
  hkConstraintInternalInfo *v29; // r11
  hkConstraintInternal *m_internal; // r9
  __int64 v31; // rcx
  hkConstraintInternalCallbackInfo *v32; // rdx
  __int16 v33; // cx
  _QWORD **v34; // rax
  __int64 v35; // rax
  hkpSolveConstraintBatchTask *v36; // rdx
  hkpSolveConstraintBatchTask *v37; // rax
  unsigned __int16 i; // r10
  hkpJacobianSchema **schemasa; // [rsp+98h] [rbp+40h]
  hkpSolverElemTemp **elemTempa; // [rsp+A0h] [rbp+48h]

  v18 = taskHeader;
  v19 = *schemas;
  schemasa = (hkpJacobianSchema **)*schemas;
  elemTempa = (hkpSolverElemTemp **)*elemTemp;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v23 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 3968i64);
  v24 = (hkpBuildJacobianTask *)v23;
  if ( v23 )
  {
    *(_DWORD *)(v23 + 40) = 0;
    *(_QWORD *)(v23 + 32) = 0i64;
    *(_QWORD *)v23 = 0i64;
  }
  else
  {
    v24 = 0i64;
  }
  if ( *prevBuildTask )
  {
    (*prevBuildTask)->m_next = v24;
    (*prevBuildTask)->m_schemasOfNextTask = *schemas;
  }
  else if ( !putOnPpuOnlyBuildJacobianTaskList.m_bool )
  {
    outBuildCollection->m_buildJacobianTasks = v24;
    outBuildCollection->m_numBuildJacobianTasks = 0;
  }
  ++outBuildCollection->m_numBuildJacobianTasks;
  v24->m_taskHeader = v18;
  v24->m_numAtomInfos = constraintsForThisTask->m_size;
  m_accumulatorsBase = v18->m_accumulatorsBase;
  v24->m_schemas = v19;
  v24->m_accumulators = m_accumulatorsBase;
  m_size = constraintsForThisTask->m_size;
  if ( m_size > 0 )
  {
    v27 = 0i64;
    p_m_instance = &v24->m_atomInfos[0].m_instance;
    do
    {
      v29 = &constraintsForThisTask->m_data[v27];
      m_internal = v29->m_internal;
      if ( (v29->m_internal->m_callbackRequest & 0xB) != 0 )
      {
        v31 = callbackConstraints->m_size;
        callbackConstraints->m_size = v31 + 1;
        v32 = &callbackConstraints->m_data[v31];
        v32->m_internal = v29->m_internal;
        *(_QWORD *)&v32->m_entityAIndex = *(_QWORD *)&v29->m_entityAIndex;
        v32->m_atomInfo = (hkpBuildJacobianTask::AtomInfo *)(p_m_instance - 1);
      }
      ++v27;
      p_m_instance += 6;
      *(p_m_instance - 7) = (hkpConstraintInstance *)m_internal->m_atoms;
      *((_WORD *)p_m_instance - 8) = m_internal->m_atomsSize;
      *(p_m_instance - 6) = m_internal->m_constraint;
      *(p_m_instance - 5) = (hkpConstraintInstance *)m_internal->m_runtime;
      *((_WORD *)p_m_instance - 7) = m_internal->m_runtimeSize;
      v33 = v29->m_entityBIndex + 1;
      *((_WORD *)p_m_instance - 6) = v29->m_entityAIndex + 1;
      *((_WORD *)p_m_instance - 5) = v33;
      *(p_m_instance - 4) = (hkpConstraintInstance *)&m_internal->m_entities[0]->m_motion.m_motionState;
      *(p_m_instance - 3) = (hkpConstraintInstance *)&m_internal->m_entities[1]->m_motion.m_motionState;
      *schemas += m_internal->m_sizeOfSchemas;
      *elemTemp += m_internal->m_numSolverElemTemps;
      --m_size;
    }
    while ( m_size );
    v18 = taskHeader;
    v19 = (hkpJacobianSchema *)schemasa;
  }
  constraintsForThisTask->m_size = 0;
  *schemas += 32;
  v24->m_schemasOfNextTask = *schemas;
  *elemTemp = (hkpSolverElemTemp *)(((unsigned __int64)&(*elemTemp)[3].m_usedImpulseFactor + 3) & 0xFFFFFFFFFFFFFFF0ui64);
  *prevBuildTask = v24;
  if ( generateSolveTasks.m_bool )
  {
    v34 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v35 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v34[11] + 8i64))(v34[11], 64i64);
    v36 = (hkpSolveConstraintBatchTask *)v35;
    if ( v35 )
    {
      *(_QWORD *)v35 = 0i64;
      *(_BYTE *)(v35 + 48) = 0;
      *(_WORD *)(v35 + 50) = 0;
      *(_QWORD *)(v35 + 56) = 0i64;
    }
    else
    {
      v36 = 0i64;
    }
    if ( *prevSolveTask )
      (*prevSolveTask)->m_next = v36;
    if ( currentBatchIndex != *batchIndexOfLastTask )
    {
      if ( !currentBatchIndex )
        outSolveCollection->m_firstSolveJacobiansTask = v36;
      *batchIndexOfLastTask = currentBatchIndex;
      if ( *prevSolveTask )
      {
        v37 = *firstTaskOfPreviousBatch;
        for ( i = **ptrToBatchSize; v37; v37 = v37->m_next )
        {
          if ( v37 == *firstTaskOfCurrentBatch )
            break;
          v37->m_sizeOfNextBatch = i;
          v37->m_firstTaskInNextBatch = *firstTaskOfCurrentBatch;
        }
        (*prevSolveTask)->m_isLastTaskInBatch.m_bool = 1;
        *ptrToBatchSize = &(*prevSolveTask)->m_sizeOfNextBatch;
      }
      *firstTaskOfPreviousBatch = *firstTaskOfCurrentBatch;
      *firstTaskOfCurrentBatch = v36;
    }
    ++**ptrToBatchSize;
    v36->m_taskHeader = v18;
    v36->m_accumulators = v18->m_accumulatorsBase;
    v36->m_schemas = v19;
    v36->m_solverElemTemp = (hkpSolverElemTemp *)elemTempa;
    v36->m_sizeOfSchemaBuffer = *(_DWORD *)schemas - (_DWORD)v19;
    v36->m_sizeOfSolverElemTempBuffer = *(_DWORD *)elemTemp - (_DWORD)elemTempa;
    *prevSolveTask = v36;
  }
}

// File Line: 338
// RVA: 0xD93DA0
void __fastcall createBuildJacobianAndSolveJacobianTaskCollection(
        hkpSimulationIsland *island,
        hkBool forceCoherentConstraintOrderingInSolver,
        hkpBuildJacobianTaskHeader *taskHeader,
        hkpBuildJacobianTaskCollection *outBuildCollection,
        hkpSolveJacobiansTaskCollection *outSolveCollection)
{
  hkpSimulationIsland *v5; // rsi
  _QWORD *Value; // rdi
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  __int64 m_size; // rbx
  unsigned __int64 v11; // r14
  int m_numConstraints; // r9d
  __int64 v13; // r13
  int v14; // r9d
  int v15; // r12d
  hkLifoAllocator *v16; // rax
  int v17; // edx
  char *v18; // rcx
  int v19; // edi
  int v20; // r15d
  __int64 v21; // rcx
  __int64 v22; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v23; // rax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v24; // r12
  int v25; // ebx
  __int64 i; // rdi
  int v27; // ebx
  int v28; // r13d
  __int16 v29; // r12
  __int64 v30; // rax
  unsigned __int64 v31; // rbx
  unsigned __int64 v32; // rsi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v33; // r14
  unsigned __int8 *v34; // rbx
  __int64 v35; // rcx
  int v36; // eax
  hkpSolverElemTemp **v37; // rcx
  int v38; // eax
  hkpSolverElemTemp **v39; // rcx
  _QWORD *v40; // rax
  int v41; // edi
  unsigned __int64 v42; // rcx
  unsigned __int64 v43; // rcx
  _QWORD *v44; // rax
  unsigned __int64 v45; // rcx
  unsigned __int64 v46; // rcx
  _QWORD *v47; // rax
  unsigned __int64 v48; // rcx
  unsigned __int64 v49; // rcx
  hkpSolveConstraintBatchTask *v50; // r12
  __int64 v51; // r14
  hkpJacobianSchema *m_schemasBase; // rax
  hkLifoAllocator *v53; // rax
  bool v54; // cc
  unsigned __int64 v55; // rcx
  __int64 *v56; // rcx
  unsigned int v57; // eax
  __int64 v58; // rdi
  bool v59; // r15
  _DWORD *v60; // rdi
  int v61; // eax
  char **p_array; // rdx
  bool v63; // zf
  __int64 v64; // rcx
  char *v65; // r12
  __int64 v66; // r8
  __int64 v67; // rdx
  int v68; // r13d
  unsigned __int64 v69; // r8
  unsigned __int16 v70; // ax
  unsigned __int16 v71; // ax
  int *v72; // rax
  hkpSolverElemTemp *v73; // r15
  hkpSolverElemTemp *v74; // rdi
  hkpSolverElemTemp *v75; // rbx
  hkpSolverElemTemp *v76; // rsi
  _QWORD **v77; // rax
  __int64 v78; // rax
  hkpBuildJacobianTask *v79; // r9
  hkpBuildJacobianTask *v80; // rax
  hkpBuildJacobianTaskCollection *v81; // rax
  hkpVelocityAccumulator *m_accumulatorsBase; // rax
  __int64 v83; // r10
  _QWORD *v84; // rdi
  hkpSolverElemTemp *v85; // r12
  _QWORD *v86; // rbx
  int v87; // esi
  hkpConstraintInstance **p_m_instance; // r8
  __int64 v89; // rdx
  __int64 v90; // rax
  __int64 v91; // rcx
  __int16 v92; // cx
  bool v93; // al
  hkpSolverElemTemp *v94; // r15
  hkpSolverElemTemp *v95; // rdi
  _QWORD **v96; // rax
  __int64 v97; // rax
  hkpSolveConstraintBatchTask *v98; // rcx
  hkpSolveConstraintBatchTask *v99; // r8
  int v100; // r9d
  unsigned __int16 v101; // ax
  __int64 v102; // rdx
  hkpVelocityAccumulator *v103; // rax
  __int64 v104; // rsi
  int v105; // edi
  __int64 v106; // rbx
  unsigned __int16 v107; // ax
  int v108; // ecx
  int *v109; // rdi
  int *v110; // rdx
  _QWORD *v111; // rcx
  __int64 v112; // rsi
  int v113; // ebx
  __int64 v114; // r12
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v115; // r14
  __int64 v116; // rdi
  unsigned __int16 v117; // ax
  int *v118; // rax
  _QWORD *v119; // rax
  __int64 *v120; // rax
  hkpSolverElemTemp *v121; // r13
  hkpSolverElemTemp *v122; // r12
  hkpSolverElemTemp *v123; // rbx
  hkpSolverElemTemp *v124; // rsi
  _QWORD **v125; // rax
  __int64 v126; // rax
  hkpBuildJacobianTask *v127; // r9
  hkpBuildJacobianTask *v128; // rax
  hkpBuildJacobianTaskCollection *v129; // rax
  hkpVelocityAccumulator *v130; // rax
  __int64 v131; // r10
  _QWORD *v132; // r8
  _QWORD *v133; // rbx
  int v134; // esi
  hkpConstraintInstance **v135; // rdi
  __int64 v136; // rdx
  __int64 v137; // rax
  __int64 v138; // rcx
  __int16 v139; // cx
  hkpSolverElemTemp *v140; // r12
  hkpSolverElemTemp *v141; // r13
  _QWORD **v142; // rax
  __int64 v143; // rax
  hkpSolveConstraintBatchTask *v144; // rcx
  hkpSolveConstraintBatchTask *v145; // rdi
  int v146; // eax
  unsigned __int16 v147; // ax
  __int64 v148; // rdx
  hkpVelocityAccumulator *v149; // rax
  __int64 v150; // rax
  _QWORD **v151; // rax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v152; // rdi
  _QWORD **v153; // rax
  _QWORD **v154; // rax
  unsigned __int16 v155; // ax
  __int64 v156; // rsi
  unsigned int v157; // ecx
  unsigned __int16 v158; // ax
  __int64 v159; // rdi
  _QWORD **v160; // rax
  hkpBuildJacobianTaskCollection::CallbackPair *v161; // rax
  char *v162; // r15
  hkpBuildJacobianTaskCollection::CallbackPair *v163; // rdx
  __int64 v164; // r8
  char *v165; // rdi
  hkConstraintInternal *v166; // rcx
  hkLifoAllocator *v167; // rax
  signed int v168; // edi
  hkLifoAllocator *v169; // rax
  int v170; // r8d
  _QWORD *v171; // rdi
  _QWORD *v172; // rcx
  unsigned __int64 v173; // rax
  _QWORD *v174; // rcx
  int v175; // [rsp+30h] [rbp-D0h]
  int v176; // [rsp+34h] [rbp-CCh] BYREF
  int v177; // [rsp+38h] [rbp-C8h]
  int v178; // [rsp+3Ch] [rbp-C4h]
  int v179; // [rsp+40h] [rbp-C0h]
  char *v180; // [rsp+48h] [rbp-B8h]
  hkResult result; // [rsp+50h] [rbp-B0h] BYREF
  unsigned __int16 *p_m_firstBatchSize; // [rsp+58h] [rbp-A8h]
  hkpSolveConstraintBatchTask *v183; // [rsp+60h] [rbp-A0h]
  hkpSolverElemTemp *m_solverTempBase; // [rsp+68h] [rbp-98h]
  void *m_cur; // [rsp+70h] [rbp-90h]
  hkpSolveConstraintBatchTask *v186; // [rsp+78h] [rbp-88h]
  char *array; // [rsp+80h] [rbp-80h] BYREF
  int v188; // [rsp+88h] [rbp-78h]
  int v189; // [rsp+8Ch] [rbp-74h]
  char *v190; // [rsp+90h] [rbp-70h] BYREF
  int v191; // [rsp+98h] [rbp-68h]
  int v192; // [rsp+9Ch] [rbp-64h]
  hkpSolverElemTemp *v193; // [rsp+A0h] [rbp-60h]
  void *p; // [rsp+A8h] [rbp-58h]
  unsigned __int64 v195; // [rsp+B0h] [rbp-50h]
  _DWORD *v196; // [rsp+B8h] [rbp-48h]
  unsigned __int64 m_data; // [rsp+C0h] [rbp-40h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v198; // [rsp+C8h] [rbp-38h]
  int v199; // [rsp+D0h] [rbp-30h]
  hkpBuildJacobianTask *v200; // [rsp+D8h] [rbp-28h]
  hkpSolverElemTemp *v201; // [rsp+E0h] [rbp-20h]
  hkpSolverElemTemp *v202; // [rsp+E8h] [rbp-18h]
  int *v203; // [rsp+F0h] [rbp-10h]
  int *v204; // [rsp+F8h] [rbp-8h]
  unsigned __int64 v205; // [rsp+100h] [rbp+0h]
  unsigned int v206; // [rsp+108h] [rbp+8h]
  int v207; // [rsp+10Ch] [rbp+Ch]
  unsigned int v208; // [rsp+110h] [rbp+10h]
  void *ptr; // [rsp+118h] [rbp+18h]
  char **v210; // [rsp+120h] [rbp+20h]
  __int64 v211; // [rsp+128h] [rbp+28h]
  bool v213; // [rsp+180h] [rbp+80h]

  v5 = island;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtBuildJacTask";
    v8 = __rdtsc();
    v9 = v7 + 2;
    *((_DWORD *)v9 - 2) = v8;
    Value[1] = v9;
  }
  m_size = v5->m_entities.m_size;
  m_numConstraints = v5->m_numConstraints;
  m_data = (unsigned __int64)v5->m_entities.m_data;
  v11 = m_data;
  v176 = m_size;
  v13 = m_size;
  v211 = m_size;
  v195 = m_data + 8 * m_size;
  array = 0i64;
  v188 = 0;
  v189 = 0x80000000;
  if ( m_numConstraints > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&array, m_numConstraints, 16);
  v14 = v5->m_numConstraints;
  v190 = 0i64;
  v191 = 0;
  v192 = 0x80000000;
  if ( v14 > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&v190, v14, 16);
  v15 = v5->m_numConstraints;
  v177 = 0;
  v207 = v15;
  if ( v15 )
  {
    v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (24 * v15 + 127) & 0xFFFFFF80;
    m_cur = v16->m_cur;
    v18 = (char *)m_cur + v17;
    if ( v17 > v16->m_slabSize || v18 > v16->m_end )
      m_cur = (void *)hkLifoAllocator::allocateFromNewSlab(v16, v17);
    else
      v16->m_cur = v18;
  }
  else
  {
    m_cur = 0i64;
  }
  v19 = 64;
  v20 = 0;
  for ( result.m_enum = v15 | 0x80000000; v19 < (int)m_size; v19 *= 2 )
    ;
  v21 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 10);
  v206 = 32 * v19;
  ptr = (void *)(*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v21 + 8i64))(v21, (unsigned int)(32 * v19));
  v22 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
  v23 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)(*(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v22 + 8i64))(
                                                                                             v22,
                                                                                             16i64);
  v24 = v23;
  v198 = v23;
  if ( v23 )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>(
      v23,
      ptr,
      32 * v19);
  }
  else
  {
    v24 = 0i64;
    v198 = 0i64;
  }
  v25 = 0;
  for ( i = 0i64; i < v13; ++v25 )
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      v24,
      &hkContainerHeapAllocator::s_alloc,
      *(_QWORD *)(v11 + 8 * i++),
      v25);
  v27 = 0;
  v28 = 128;
  v29 = 0;
  if ( v11 < v195 )
  {
    do
    {
      v30 = *(_QWORD *)v11;
      if ( v28 != *(_DWORD *)(*(_QWORD *)v11 + 240i64) )
        *(_DWORD *)(v30 + 240) = v28;
      v31 = *(_QWORD *)(v30 + 248);
      v28 += 128;
      v32 = v31 + ((unsigned __int64)*(unsigned __int16 *)(v30 + 256) << 6);
      if ( v31 < v32 )
      {
        v33 = v198;
        v34 = (unsigned __int8 *)(v31 + 42);
        do
        {
          v35 = *v34;
          v201 = (hkpSolverElemTemp *)(v34 - 42);
          *((_WORD *)&v202 + v35) = v29;
          *((_WORD *)&v202 + 1 - (int)v35) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                               v33,
                                               *(_QWORD *)&v34[8 * (1 - (int)v35) - 34],
                                               0xFFFFui64);
          v20 += v34[1];
          if ( *(v34 - 7) >= 4u )
          {
            v38 = v191;
            v39 = (hkpSolverElemTemp **)&v190[16 * v191];
            if ( v39 )
            {
              *v39 = v201;
              v39[1] = v202;
              v38 = v191;
            }
            v191 = v38 + 1;
          }
          else
          {
            v36 = v188;
            v37 = (hkpSolverElemTemp **)&array[16 * v188];
            if ( v37 )
            {
              *v37 = v201;
              v37[1] = v202;
              v36 = v188;
            }
            v188 = v36 + 1;
          }
          v34 += 64;
        }
        while ( (unsigned __int64)(v34 - 42) < v32 );
        v11 = m_data;
      }
      v11 += 8i64;
      ++v29;
      m_data = v11;
    }
    while ( v11 < v195 );
    v5 = island;
    v27 = 0;
  }
  v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v41 = v176;
  v42 = v40[1];
  if ( v42 < v40[3] )
  {
    v43 = v42 + 16;
    *(_QWORD *)(v43 - 16) = "MiNumEntities";
    *(float *)(v43 - 8) = (float)v41;
    v40[1] = v43;
  }
  v44 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v45 = v44[1];
  if ( v45 < v44[3] )
  {
    v46 = v45 + 16;
    *(_QWORD *)(v46 - 16) = "MiNumConstraints";
    *(float *)(v46 - 8) = (float)v5->m_numConstraints;
    v44[1] = v46;
  }
  v47 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v48 = v47[1];
  if ( v48 < v47[3] )
  {
    v49 = v48 + 16;
    *(_QWORD *)(v49 - 16) = "MiNumJacobians";
    *(float *)(v49 - 8) = (float)v5->m_constraintInfo.m_numSolverResults;
    v47[1] = v49;
  }
  v200 = 0i64;
  v50 = 0i64;
  taskHeader->m_solveInSingleThreadOnPpuOnly.m_bool = v20 != 0;
  v186 = 0i64;
  v51 = 0i64;
  m_data = 0i64;
  taskHeader->m_solveInSingleThread.m_bool = v20 != 0;
  m_schemasBase = taskHeader->m_schemasBase;
  v213 = v20 == 0;
  m_solverTempBase = taskHeader->m_solverTempBase;
  outSolveCollection->m_firstBatchSize = 0;
  v193 = (hkpSolverElemTemp *)m_schemasBase;
  p_m_firstBatchSize = &outSolveCollection->m_firstBatchSize;
  v183 = 0i64;
  v175 = 0;
  v178 = -1;
  v179 = -1;
  v53 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v54 = v53->m_slabSize < 1280;
  v55 = (unsigned __int64)v53->m_cur + 1280;
  p = v53->m_cur;
  if ( v54 || (void *)v55 > v53->m_end )
    p = (void *)hkLifoAllocator::allocateFromNewSlab(v53, 1280);
  else
    v53->m_cur = (void *)v55;
  v56 = (__int64 *)*((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 10);
  v57 = 4 * v41;
  v58 = *v56;
  v208 = v57;
  v59 = 0;
  v60 = (_DWORD *)(*(__int64 (__fastcall **)(__int64 *, _QWORD))(v58 + 8))(v56, v57);
  v196 = v60;
  v61 = 0;
  v199 = 0;
  do
  {
    if ( v61 )
    {
      p_array = &v190;
    }
    else
    {
      p_array = &array;
      v200 = 0i64;
    }
    v63 = *((_DWORD *)p_array + 2) == 0;
    v210 = p_array;
    if ( !v63 )
    {
      while ( 1 )
      {
        v64 = v211;
        if ( v211 > 0 )
        {
          while ( v64 )
          {
            *v60++ = 0;
            --v64;
          }
          v60 = v196;
        }
        v65 = *p_array;
        v66 = *((int *)p_array + 2);
        ++v178;
        v67 = (__int64)v65;
        v68 = 1;
        v69 = (unsigned __int64)&v65[16 * v66];
        v195 = (unsigned __int64)v65;
        v180 = v65;
        v205 = v69;
        if ( (unsigned __int64)v65 < v69 )
        {
          while ( 1 )
          {
            v70 = *((_WORD *)v65 + 4);
            v176 = 0;
            if ( v70 == 0xFFFF )
              v203 = &v176;
            else
              v203 = &v60[v70];
            v71 = *((_WORD *)v65 + 5);
            if ( v71 == 0xFFFF )
              v72 = &v176;
            else
              v72 = &v60[v71];
            v204 = v72;
            if ( v27 == 80 || v59 )
            {
              v73 = v193;
              v74 = m_solverTempBase;
              v75 = v193;
              v76 = m_solverTempBase;
              v201 = m_solverTempBase;
              v77 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              v78 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v77[11] + 8i64))(v77[11], 3968i64);
              v79 = (hkpBuildJacobianTask *)v78;
              if ( v78 )
              {
                *(_DWORD *)(v78 + 40) = 0;
                *(_QWORD *)(v78 + 32) = 0i64;
                *(_QWORD *)v78 = 0i64;
              }
              else
              {
                v79 = 0i64;
              }
              v80 = v200;
              if ( v200 )
              {
                v200->m_next = v79;
                v80->m_schemasOfNextTask = (hkpJacobianSchema *)v73;
                v81 = outBuildCollection;
              }
              else
              {
                v81 = outBuildCollection;
                outBuildCollection->m_buildJacobianTasks = v79;
                outBuildCollection->m_numBuildJacobianTasks = 0;
              }
              ++v81->m_numBuildJacobianTasks;
              v79->m_taskHeader = taskHeader;
              v79->m_numAtomInfos = v175;
              m_accumulatorsBase = taskHeader->m_accumulatorsBase;
              v79->m_schemas = (hkpJacobianSchema *)v73;
              v83 = v175;
              v79->m_accumulators = m_accumulatorsBase;
              if ( v175 > 0 )
              {
                v84 = p;
                v85 = m_solverTempBase;
                v86 = m_cur;
                v87 = v177;
                p_m_instance = &v79->m_atomInfos[0].m_instance;
                do
                {
                  v89 = *v84;
                  if ( (*(_BYTE *)(*v84 + 34i64) & 0xB) != 0 )
                  {
                    v90 = v87++;
                    v91 = 3 * v90;
                    v86[v91] = v89;
                    v86[v91 + 1] = v84[1];
                    v86[v91 + 2] = p_m_instance - 1;
                  }
                  v84 += 2;
                  p_m_instance += 6;
                  *(p_m_instance - 7) = *(hkpConstraintInstance **)(v89 + 24);
                  *((_WORD *)p_m_instance - 8) = *(_WORD *)(v89 + 32);
                  *(p_m_instance - 6) = *(hkpConstraintInstance **)v89;
                  *(p_m_instance - 5) = *(hkpConstraintInstance **)(v89 + 48);
                  *((_WORD *)p_m_instance - 7) = *(_WORD *)(v89 + 56);
                  v92 = *((_WORD *)v84 - 3) + 1;
                  *((_WORD *)p_m_instance - 6) = *((_WORD *)v84 - 4) + 1;
                  *((_WORD *)p_m_instance - 5) = v92;
                  *(p_m_instance - 4) = (hkpConstraintInstance *)(*(_QWORD *)(v89 + 8) + 368i64);
                  *(p_m_instance - 3) = (hkpConstraintInstance *)(*(_QWORD *)(v89 + 16) + 368i64);
                  v73 = (hkpSolverElemTemp *)((char *)v73 + *(unsigned __int16 *)(v89 + 36));
                  v85 += *(unsigned __int16 *)(v89 + 40);
                  --v83;
                }
                while ( v83 );
                v75 = v193;
                m_solverTempBase = v85;
                v65 = (char *)v195;
                v74 = m_solverTempBase;
                v177 = v87;
                v76 = v201;
              }
              v93 = v213;
              v94 = v73 + 8;
              v95 = (hkpSolverElemTemp *)(((unsigned __int64)&v74[3].m_usedImpulseFactor + 3) & 0xFFFFFFFFFFFFFFF0ui64);
              v175 = 0;
              v200 = v79;
              v193 = v94;
              v79->m_schemasOfNextTask = (hkpJacobianSchema *)v94;
              m_solverTempBase = v95;
              if ( v213 )
              {
                v96 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
                v97 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v96[11] + 8i64))(v96[11], 64i64);
                v98 = (hkpSolveConstraintBatchTask *)v97;
                if ( v97 )
                {
                  *(_QWORD *)v97 = 0i64;
                  *(_BYTE *)(v97 + 48) = 0;
                  *(_WORD *)(v97 + 50) = 0;
                  *(_QWORD *)(v97 + 56) = 0i64;
                }
                else
                {
                  v98 = 0i64;
                }
                v99 = v186;
                if ( v186 )
                  v186->m_next = v98;
                v100 = v178;
                if ( v178 != v179 )
                {
                  if ( !v178 )
                    outSolveCollection->m_firstSolveJacobiansTask = v98;
                  v179 = v100;
                  if ( v99 )
                  {
                    v101 = *p_m_firstBatchSize;
                    if ( v51 )
                    {
                      v102 = (__int64)v183;
                      do
                      {
                        if ( v51 == v102 )
                          break;
                        *(_WORD *)(v51 + 50) = v101;
                        *(_QWORD *)(v51 + 56) = v102;
                        v51 = *(_QWORD *)v51;
                      }
                      while ( v51 );
                    }
                    v99->m_isLastTaskInBatch.m_bool = 1;
                    p_m_firstBatchSize = &v99->m_sizeOfNextBatch;
                  }
                  v51 = (__int64)v183;
                  v183 = v98;
                  m_data = v51;
                }
                v186 = v98;
                ++*p_m_firstBatchSize;
                v98->m_taskHeader = taskHeader;
                v103 = taskHeader->m_accumulatorsBase;
                v98->m_schemas = (hkpJacobianSchema *)v75;
                v98->m_accumulators = v103;
                v98->m_solverElemTemp = v76;
                v98->m_sizeOfSchemaBuffer = (_DWORD)v94 - (_DWORD)v75;
                v98->m_sizeOfSolverElemTempBuffer = (_DWORD)v95 - (_DWORD)v76;
                v93 = v213;
              }
              v27 = 0;
              v67 = (__int64)v180;
              v69 = v205;
              v68 += v93;
              v59 = 0;
            }
            if ( forceCoherentConstraintOrderingInSolver.m_bool && v68 > 1 )
            {
              if ( (unsigned __int64)v65 < v69 )
              {
                do
                {
                  v120 = *(__int64 **)v65;
                  v65 += 16;
                  v67 += 16i64;
                  *(_QWORD *)(v67 - 16) = v120;
                  *(_QWORD *)(v67 - 8) = *((_QWORD *)v65 - 1);
                }
                while ( (unsigned __int64)v65 < v69 );
                v180 = (char *)v67;
              }
              break;
            }
            if ( *(_BYTE *)(*(_QWORD *)v65 + 43i64) == 1 )
            {
              v104 = **(_QWORD **)v65;
              v105 = 0;
              if ( *(int *)(v104 + 120) > 0 )
              {
                v106 = 0i64;
                while ( 1 )
                {
                  v107 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                           v198,
                           *(_QWORD *)(v106 + *(_QWORD *)(v104 + 112)),
                           0xFFFFui64);
                  if ( v107 != 0xFFFF )
                  {
                    v108 = v196[v107];
                    if ( v108 )
                    {
                      if ( v108 != v68 )
                        break;
                    }
                  }
                  ++v105;
                  v106 += 8i64;
                  if ( v105 >= *(_DWORD *)(v104 + 120) )
                  {
                    v27 = v175;
                    goto LABEL_104;
                  }
                }
LABEL_116:
                v67 = (__int64)v180;
LABEL_117:
                v27 = v175;
                v67 += 16i64;
                *(_QWORD *)(v67 - 16) = *(_QWORD *)v65;
                v119 = (_QWORD *)*((_QWORD *)v65 + 1);
                v180 = (char *)v67;
                *(_QWORD *)(v67 - 8) = v119;
                goto LABEL_124;
              }
LABEL_104:
              v109 = v203;
              v110 = v204;
            }
            else
            {
              v109 = v203;
              if ( *v203 && *v203 != v68 )
                goto LABEL_117;
              v110 = v204;
              if ( *v204 && *v204 != v68 )
                goto LABEL_116;
            }
            v111 = (char *)p + 16 * v27;
            if ( v111 )
            {
              *v111 = *(_QWORD *)v65;
              v111[1] = *((_QWORD *)v65 + 1);
            }
            v175 = ++v27;
            if ( *(_BYTE *)(*(_QWORD *)v65 + 43i64) == 1 )
            {
              v112 = **(_QWORD **)v65;
              v113 = 0;
              if ( *(int *)(v112 + 120) > 0 )
              {
                v114 = (__int64)v196;
                v115 = v198;
                v116 = 0i64;
                do
                {
                  v117 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                           v115,
                           *(_QWORD *)(v116 + *(_QWORD *)(v112 + 112)),
                           0xFFFFui64);
                  if ( v117 == 0xFFFF )
                    v118 = &v176;
                  else
                    v118 = (int *)(v114 + 4i64 * v117);
                  ++v113;
                  *v118 = v68;
                  v116 += 8i64;
                }
                while ( v113 < *(_DWORD *)(v112 + 120) );
                v51 = m_data;
                v65 = (char *)v195;
              }
              v59 = v213;
              v27 = v175;
            }
            else
            {
              *v109 = v68;
              *v110 = v68;
            }
            v67 = (__int64)v180;
LABEL_124:
            v69 = v205;
            v65 += 16;
            v195 = (unsigned __int64)v65;
            if ( (unsigned __int64)v65 >= v205 )
              break;
            v60 = v196;
          }
        }
        if ( v27 )
        {
          v121 = m_solverTempBase;
          v122 = v193;
          v123 = v193;
          v124 = m_solverTempBase;
          v205 = (unsigned __int64)m_solverTempBase;
          v201 = v193;
          v125 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v126 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v125[11] + 8i64))(v125[11], 3968i64);
          v127 = (hkpBuildJacobianTask *)v126;
          if ( v126 )
          {
            *(_DWORD *)(v126 + 40) = 0;
            *(_QWORD *)(v126 + 32) = 0i64;
            *(_QWORD *)v126 = 0i64;
          }
          else
          {
            v127 = 0i64;
          }
          v128 = v200;
          if ( v200 )
          {
            v200->m_next = v127;
            v128->m_schemasOfNextTask = (hkpJacobianSchema *)v122;
            v129 = outBuildCollection;
          }
          else
          {
            v129 = outBuildCollection;
            outBuildCollection->m_buildJacobianTasks = v127;
            outBuildCollection->m_numBuildJacobianTasks = 0;
          }
          ++v129->m_numBuildJacobianTasks;
          v127->m_taskHeader = taskHeader;
          v127->m_numAtomInfos = v175;
          v130 = taskHeader->m_accumulatorsBase;
          v127->m_schemas = (hkpJacobianSchema *)v122;
          v131 = v175;
          v127->m_accumulators = v130;
          if ( v175 > 0 )
          {
            v132 = p;
            v133 = m_cur;
            v134 = v177;
            v135 = &v127->m_atomInfos[0].m_instance;
            do
            {
              v136 = *v132;
              if ( (*(_BYTE *)(*v132 + 34i64) & 0xB) != 0 )
              {
                v137 = v134++;
                v138 = 3 * v137;
                v133[v138] = v136;
                v133[v138 + 1] = v132[1];
                v133[v138 + 2] = v135 - 1;
              }
              v132 += 2;
              v135 += 6;
              *(v135 - 7) = *(hkpConstraintInstance **)(v136 + 24);
              *((_WORD *)v135 - 8) = *(_WORD *)(v136 + 32);
              *(v135 - 6) = *(hkpConstraintInstance **)v136;
              *(v135 - 5) = *(hkpConstraintInstance **)(v136 + 48);
              *((_WORD *)v135 - 7) = *(_WORD *)(v136 + 56);
              v139 = *((_WORD *)v132 - 3) + 1;
              *((_WORD *)v135 - 6) = *((_WORD *)v132 - 4) + 1;
              *((_WORD *)v135 - 5) = v139;
              *(v135 - 4) = (hkpConstraintInstance *)(*(_QWORD *)(v136 + 8) + 368i64);
              *(v135 - 3) = (hkpConstraintInstance *)(*(_QWORD *)(v136 + 16) + 368i64);
              v122 = (hkpSolverElemTemp *)((char *)v122 + *(unsigned __int16 *)(v136 + 36));
              v121 += *(unsigned __int16 *)(v136 + 40);
              --v131;
            }
            while ( v131 );
            v123 = v201;
            v177 = v134;
            v124 = (hkpSolverElemTemp *)v205;
          }
          v140 = v122 + 8;
          v141 = (hkpSolverElemTemp *)(((unsigned __int64)&v121[3].m_usedImpulseFactor + 3) & 0xFFFFFFFFFFFFFFF0ui64);
          v175 = 0;
          v193 = v140;
          v127->m_schemasOfNextTask = (hkpJacobianSchema *)v140;
          v200 = v127;
          m_solverTempBase = v141;
          if ( v213 )
          {
            v142 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v143 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v142[11] + 8i64))(v142[11], 64i64);
            v144 = (hkpSolveConstraintBatchTask *)v143;
            if ( v143 )
            {
              *(_QWORD *)v143 = 0i64;
              *(_BYTE *)(v143 + 48) = 0;
              *(_WORD *)(v143 + 50) = 0;
              *(_QWORD *)(v143 + 56) = 0i64;
            }
            else
            {
              v144 = 0i64;
            }
            v145 = v186;
            if ( v186 )
              v186->m_next = v144;
            v146 = v178;
            if ( v178 != v179 )
            {
              if ( !v178 )
                outSolveCollection->m_firstSolveJacobiansTask = v144;
              v179 = v146;
              if ( v145 )
              {
                v147 = *p_m_firstBatchSize;
                if ( v51 )
                {
                  v148 = (__int64)v183;
                  do
                  {
                    if ( v51 == v148 )
                      break;
                    *(_WORD *)(v51 + 50) = v147;
                    *(_QWORD *)(v51 + 56) = v148;
                    v51 = *(_QWORD *)v51;
                  }
                  while ( v51 );
                }
                v145->m_isLastTaskInBatch.m_bool = 1;
                p_m_firstBatchSize = &v145->m_sizeOfNextBatch;
              }
              v51 = (__int64)v183;
              v183 = v144;
              m_data = v51;
            }
            v186 = v144;
            ++*p_m_firstBatchSize;
            v144->m_taskHeader = taskHeader;
            v149 = taskHeader->m_accumulatorsBase;
            v144->m_schemas = (hkpJacobianSchema *)v123;
            v144->m_accumulators = v149;
            v144->m_solverElemTemp = v124;
            LODWORD(v149) = (_DWORD)v140 - (_DWORD)v123;
            v27 = 0;
            v50 = v144;
            v144->m_sizeOfSchemaBuffer = (int)v149;
            v144->m_sizeOfSolverElemTempBuffer = (_DWORD)v141 - (_DWORD)v124;
            goto LABEL_161;
          }
          v27 = 0;
        }
        v50 = v186;
LABEL_161:
        p_array = v210;
        v60 = v196;
        v150 = (v180 - *v210) >> 4;
        *((_DWORD *)v210 + 2) = v150;
        if ( !(_DWORD)v150 )
        {
          v61 = v199;
          break;
        }
      }
    }
    v199 = ++v61;
  }
  while ( v61 < 2 );
  v151 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, _DWORD *, _QWORD))(*v151[10] + 16i64))(v151[10], v60, v208);
  v152 = v198;
  if ( v198 )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      v198,
      &hkContainerHeapAllocator::s_alloc);
    _((AMD_HD3D *)v152);
    v153 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *, __int64))(*v153[11] + 16i64))(
      v153[11],
      v152,
      16i64);
  }
  v154 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*v154[10] + 16i64))(v154[10], ptr, v206);
  if ( v213 )
  {
    v155 = *p_m_firstBatchSize;
    if ( v51 )
    {
      v156 = (__int64)v183;
      do
      {
        if ( v51 == v156 )
          break;
        *(_WORD *)(v51 + 50) = v155;
        *(_QWORD *)(v51 + 56) = v156;
        v51 = *(_QWORD *)v51;
      }
      while ( v51 );
    }
    v50->m_isLastTaskInBatch.m_bool = 1;
    v157 = taskHeader->m_numAllEntities + 1;
    taskHeader->m_accumulatorsEnd = &taskHeader->m_accumulatorsBase[(unsigned __int64)v157];
    v158 = ((v157 - 1) >> 7) + 1;
    taskHeader->m_numApplyGravityJobs = v158;
    taskHeader->m_numIntegrateVelocitiesJobs = v158;
  }
  v159 = v177;
  outBuildCollection->m_numCallbackConstraints = 0;
  outBuildCollection->m_callbackConstraints = 0i64;
  if ( (_DWORD)v159 )
  {
    v160 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v161 = (hkpBuildJacobianTaskCollection::CallbackPair *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v160[11] + 8i64))(
                                                             v160[11],
                                                             (unsigned int)(16 * v159));
    v162 = (char *)m_cur;
    outBuildCollection->m_numCallbackConstraints = v159;
    v163 = v161;
    outBuildCollection->m_callbackConstraints = v161;
    v164 = v159;
    if ( (int)v159 > 0 )
    {
      v165 = v162;
      do
      {
        v166 = *(hkConstraintInternal **)v165;
        ++v163;
        v165 += 24;
        v163[-1].m_callbackConstraints = v166;
        v163[-1].m_atomInfo = (hkpBuildJacobianTask::AtomInfo *)*((_QWORD *)v165 - 1);
        --v164;
      }
      while ( v164 );
    }
  }
  else
  {
    v162 = (char *)m_cur;
  }
  v167 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v167->m_slabSize < 1280 || (char *)p + 1280 != v167->m_cur || v167->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(v167, (char *)p, 1280);
  else
    v167->m_cur = p;
  v168 = (24 * v207 + 127) & 0xFFFFFF80;
  v169 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v170 = (v168 + 15) & 0xFFFFFFF0;
  if ( v168 > v169->m_slabSize || &v162[v170] != v169->m_cur || v169->m_firstNonLifoEnd == v162 )
    hkLifoAllocator::slowBlockFree(v169, v162, v170);
  else
    v169->m_cur = v162;
  if ( result.m_enum >= HK_SUCCESS )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v162,
      24 * (result.m_enum & 0x3FFFFFFF));
  v191 = 0;
  if ( v192 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v190, 16 * v192);
  v190 = 0i64;
  v192 = 0x80000000;
  v188 = 0;
  if ( v189 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 16 * v189);
  array = 0i64;
  v189 = 0x80000000;
  v171 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v172 = (_QWORD *)v171[1];
  if ( (unsigned __int64)v172 < v171[3] )
  {
    *v172 = "Et";
    v173 = __rdtsc();
    v174 = v172 + 2;
    *((_DWORD *)v174 - 2) = v173;
    v171[1] = v174;
  }
}

// File Line: 834
// RVA: 0xD93060
__int64 __fastcall integrateJob(
        hkpMtThreadStructure *tl,
        hkJobQueue *jobQueue,
        hkJobQueue::JobQueueEntry *nextJobOut,
        hkBool *jobWasCancelledOut)
{
  __int64 v4; // r14
  hkJobQueue::JobQueueEntry *v5; // rsi
  hkpMtThreadStructure *v7; // rbx
  __int64 v8; // rcx
  __int64 v9; // rax
  int v10; // r13d
  hkpVelocityAccumulator *v11; // r15
  signed int v12; // edi
  hkJobQueue::JobStatus NextJob; // ebx
  int i; // eax
  _QWORD **v15; // rax
  __int64 v16; // rax
  int v17; // r12d
  _QWORD *Value; // r8
  unsigned __int64 v19; // rcx
  unsigned __int64 v20; // rax
  __int64 p_m_dynamicsStepInfo; // r13
  _QWORD *v22; // r8
  _QWORD *v23; // rcx
  unsigned __int64 v24; // rax
  _QWORD *v25; // rcx
  int v26; // edi
  __int64 v27; // rbx
  __int64 v28; // rcx
  _QWORD **v29; // rax
  __int64 v30; // rax
  __int64 v31; // rdi
  hkJobQueue::JobQueueEntry *p_job; // rcx
  __int64 v33; // rax
  hkJob v34; // xmm0
  __int128 v35; // xmm1
  __int128 v36; // xmm0
  __int128 v37; // xmm1
  __int128 v38; // xmm0
  __int128 v39; // xmm1
  __int128 v40; // xmm0
  __int128 v41; // xmm1
  _QWORD *v43; // r8
  _QWORD *v44; // rcx
  unsigned __int64 v45; // rax
  _QWORD *v46; // rcx
  hkpEntity **v47; // rcx
  int v48; // eax
  _QWORD *v49; // r8
  _QWORD *v50; // rcx
  unsigned __int64 v51; // rax
  _QWORD *v52; // rcx
  char v53; // dl
  char v54; // r8
  signed int v55; // ecx
  int v56; // eax
  unsigned int v57; // ecx
  __int64 v58; // rax
  __int64 v59; // rax
  _QWORD *v60; // r9
  unsigned __int64 v61; // r8
  unsigned __int64 v62; // rax
  hkJobQueue::DynamicData *v63; // rax
  _QWORD *v64; // r8
  _QWORD *v65; // rcx
  unsigned __int64 v66; // rax
  _QWORD *v67; // rcx
  int v68; // ebx
  unsigned int v69; // ecx
  _QWORD *v70; // r8
  _QWORD *v71; // rcx
  unsigned __int64 v72; // rax
  _QWORD *v73; // rcx
  __int128 v74; // xmm1
  __int128 v75; // xmm0
  __int128 v76; // xmm1
  hkSimdFloat32 v77; // xmm0
  __int128 v78; // xmm1
  __int128 v79; // xmm0
  __int128 v80; // xmm1
  _QWORD **v81; // rax
  _QWORD *v82; // r9
  unsigned __int64 v83; // r8
  unsigned __int64 v84; // rax
  _QWORD *v85; // r8
  _QWORD *v86; // rcx
  unsigned __int64 v87; // rax
  _QWORD *v88; // rcx
  int v89; // eax
  unsigned int v90; // ecx
  hkpEntity **v91; // rax
  hkBool v92; // dl
  _QWORD *v93; // r9
  unsigned __int64 v94; // r8
  unsigned __int64 v95; // rax
  __int16 v96; // ax
  int preallocatedBufferSize; // [rsp+40h] [rbp-C0h]
  int v98; // [rsp+44h] [rbp-BCh] BYREF
  int v99; // [rsp+48h] [rbp-B8h] BYREF
  hkpEntity **v100; // [rsp+50h] [rbp-B0h]
  hkpSolveJacobiansTaskCollection outSolveCollection; // [rsp+58h] [rbp-A8h] BYREF
  hkpBuildJacobianTaskCollection outBuildCollection; // [rsp+68h] [rbp-98h] BYREF
  hkJobQueue::JobQueueEntry v103; // [rsp+90h] [rbp-70h] BYREF
  hkJobQueue::JobQueueEntry job; // [rsp+190h] [rbp+90h] BYREF
  hkJobQueue::JobQueueEntry oldJob; // [rsp+290h] [rbp+190h] BYREF
  char dynamicDataStorage[736]; // [rsp+390h] [rbp+290h] BYREF
  unsigned int v109; // [rsp+690h] [rbp+590h]
  int v111; // [rsp+698h] [rbp+598h]

  v4 = *(_QWORD *)&nextJobOut->m_data[8];
  jobWasCancelledOut->m_bool = 0;
  v5 = nextJobOut;
  v7 = tl;
  if ( !*(_DWORD *)(v4 + 20) )
  {
    v17 = 0;
    preallocatedBufferSize = 0;
    v109 = 0;
    v11 = 0i64;
LABEL_9:
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v19 = Value[1];
    if ( v19 < Value[3] )
    {
      *(_QWORD *)v19 = "LtIntegrate";
      *(_QWORD *)(v19 + 16) = "StInit";
      v20 = __rdtsc();
      *(_DWORD *)(v19 + 8) = v20;
      Value[1] = v19 + 24;
    }
    p_m_dynamicsStepInfo = (__int64)&v7->m_world->m_dynamicsStepInfo;
    if ( !v7->m_world->m_processActionsInSingleThread.m_bool )
    {
      v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v23 = (_QWORD *)v22[1];
      if ( (unsigned __int64)v23 < v22[3] )
      {
        *v23 = "StActions";
        v24 = __rdtsc();
        v25 = v23 + 2;
        *((_DWORD *)v25 - 2) = v24;
        v22[1] = v25;
      }
      v26 = 0;
      if ( *(int *)(v4 + 80) > 0 )
      {
        v27 = 0i64;
        do
        {
          v28 = *(_QWORD *)(v27 + *(_QWORD *)(v4 + 72));
          if ( v28 )
            (*(void (__fastcall **)(__int64, __int64, _QWORD *))(*(_QWORD *)v28 + 24i64))(
              v28,
              p_m_dynamicsStepInfo,
              v22);
          ++v26;
          v27 += 8i64;
        }
        while ( v26 < *(_DWORD *)(v4 + 80) );
        v7 = tl;
      }
    }
    v29 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v30 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v29[11] + 8i64))(v29[11], 208i64);
    v31 = v30;
    if ( v30 )
    {
      *(_QWORD *)(v30 + 24) = 0i64;
      *(_QWORD *)(v30 + 32) = 0i64;
      *(_DWORD *)(v30 + 12) = 1;
      *(_DWORD *)(v30 + 16) = 1;
      *(_QWORD *)(v30 + 136) = 0i64;
      *(_DWORD *)(v30 + 144) = 0;
      *(_DWORD *)(v30 + 148) = 0x80000000;
      *(_QWORD *)(v30 + 152) = 0i64;
      *(_DWORD *)(v30 + 160) = 0;
      *(_QWORD *)(v30 + 168) = 0i64;
      *(_DWORD *)(v30 + 176) = 0;
      *(_QWORD *)(v30 + 184) = 0i64;
      *(_WORD *)(v30 + 192) = 0;
    }
    else
    {
      v31 = 0i64;
    }
    v43 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v44 = (_QWORD *)v43[1];
    if ( (unsigned __int64)v44 < v43[3] )
    {
      *v44 = "StIsland Splitting";
      v45 = __rdtsc();
      v46 = v44 + 2;
      *((_DWORD *)v46 - 2) = v45;
      v43[1] = v46;
    }
    v47 = *(hkpEntity ***)(v4 + 96);
    v48 = *(_DWORD *)(v4 + 104);
    *(_WORD *)(v31 + 128) = v48;
    *(_QWORD *)(v31 + 120) = v47;
    v111 = v48;
    LOWORD(v48) = *(_WORD *)(v4 + 108);
    v100 = v47;
    *(_DWORD *)(v31 + 4) = 0;
    *(_DWORD *)(v31 + 8) = 1;
    *(_QWORD *)(v31 + 24) = 0i64;
    *(_DWORD *)(v31 + 32) = 0;
    *(_WORD *)(v31 + 130) = v48;
    *(_QWORD *)(v31 + 48) = 0i64;
    *(_QWORD *)(v31 + 152) = 0i64;
    *(_QWORD *)(v31 + 64) = 0i64;
    v49 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v50 = (_QWORD *)v49[1];
    if ( (unsigned __int64)v50 < v49[3] )
    {
      *v50 = "StSplitIslands";
      v51 = __rdtsc();
      v52 = v50 + 2;
      *((_DWORD *)v52 - 2) = v51;
      v49[1] = v52;
    }
    ++*(_BYTE *)(v4 + 48);
    v53 = *(_BYTE *)(v4 + 49);
    v54 = *(_BYTE *)(v4 + 48);
    if ( (v53 & 0xC) != 0 )
    {
      v55 = *(_DWORD *)(v4 + 40);
      if ( *(_DWORD *)(v4 + 104) > v55 )
        v55 = *(_DWORD *)(v4 + 104);
      if ( v55 < (signed int)v7->m_world->m_minDesiredIslandSize )
      {
        if ( (v54 & 7) == 0 )
          v17 = 1;
      }
      else
      {
        *(_BYTE *)(v4 + 49) = v53 & 0xF3;
        if ( (v54 & 3) == 0 )
          v17 = 1;
      }
    }
    else if ( (v53 & 3) != 0 && (v54 & 7) == 0 && v7->m_world->m_wantSimulationIslands.m_bool )
    {
      v17 = 1;
    }
    if ( *(_DWORD *)(v4 + 20) )
    {
      v69 = *(_DWORD *)(v4 + 104);
      if ( *(_DWORD *)(v4 + 40) > (signed int)v69 )
        v69 = *(_DWORD *)(v4 + 40);
      if ( v69 >= v7->m_simulation.m_storage->m_multithreadConfig.m_maxNumConstraintsSolvedSingleThreaded )
      {
        v85 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v86 = (_QWORD *)v85[1];
        if ( (unsigned __int64)v86 < v85[3] )
        {
          *v86 = "StSetupJobs";
          v87 = __rdtsc();
          v88 = v86 + 2;
          *((_DWORD *)v88 - 2) = v87;
          v85[1] = v88;
        }
        hkpConstraintSolverSetup::calcBufferOffsetsForSolve(
          (hkpSimulationIsland *)v4,
          v11,
          preallocatedBufferSize,
          (hkpBuildJacobianTaskHeader *)v31);
        *(_DWORD *)(v31 + 104) = *(_DWORD *)(v4 + 24);
        v89 = *(_DWORD *)(v4 + 28);
        *(_DWORD *)(v31 + 36) = v109;
        *(_BYTE *)(v31 + 40) = 0;
        *(_DWORD *)(v31 + 108) = v89;
        *(_BYTE *)(v31 + 41) = v17;
        v90 = (unsigned int)(v111 - 1) >> 7;
        *(_QWORD *)(v31 + 112) = &v7->m_constraintQueryIn;
        *(_DWORD *)(v31 + 4) = v17 + v90 + 1;
        *(_DWORD *)v31 = v90 + 2;
        v91 = v100;
        *(_WORD *)&v5->m_data[42] = v111;
        v5->m_jobSubType = 1;
        *(_QWORD *)&v5->m_data[16] = v31;
        *(_QWORD *)&v5->m_data[32] = v91;
        *(_WORD *)&v5->m_data[40] = 0;
        v5->m_jobSpuType.m_storage = 1;
        hkJobQueue::addJob(jobQueue, v5, JOB_HIGH_PRIORITY);
        v92.m_bool = *(_BYTE *)(p_m_dynamicsStepInfo + 332);
        outBuildCollection.m_buildJacobianTasks = 0i64;
        outBuildCollection.m_numBuildJacobianTasks = 0;
        outBuildCollection.m_callbackConstraints = 0i64;
        outBuildCollection.m_numCallbackConstraints = 0;
        outSolveCollection.m_firstSolveJacobiansTask = 0i64;
        outSolveCollection.m_firstBatchSize = 0;
        createBuildJacobianAndSolveJacobianTaskCollection(
          (hkpSimulationIsland *)v4,
          v92,
          (hkpBuildJacobianTaskHeader *)v31,
          &outBuildCollection,
          &outSolveCollection);
        v93 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v94 = v93[1];
        if ( v94 < v93[3] )
        {
          *(_QWORD *)v94 = "lt";
          v95 = __rdtsc();
          *(_DWORD *)(v94 + 8) = v95;
          v93[1] = v94 + 16;
        }
        *(hkpBuildJacobianTaskCollection *)(v31 + 152) = outBuildCollection;
        *(_WORD *)&v103.m_data[32] = 2;
        *(_QWORD *)(v31 + 184) = outSolveCollection.m_firstSolveJacobiansTask;
        v103.m_data[34] = 1;
        *(_QWORD *)(v31 + 192) = *(_QWORD *)&outSolveCollection.m_firstBatchSize;
        *(_WORD *)&v103.m_data[38] = -1;
        strcpy(&v103.m_data[36], "@");
        v96 = *(_WORD *)v5->m_data;
        *(_QWORD *)&v103.m_data[64] = v31;
        *(_WORD *)&v103.m_data[48] = v96;
        *(_QWORD *)&v103.m_data[56] = *(_QWORD *)&v5->m_data[8];
        *(_QWORD *)&v103.m_data[72] = *(_QWORD *)&v5->m_data[24];
        return hkJobQueue::finishJobAndGetNextJob(
                 jobQueue,
                 (hkJobQueue::JobQueueEntry *)&v103.m_data[32],
                 v5,
                 WAIT_FOR_NEXT_JOB);
      }
      v70 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v71 = (_QWORD *)v70[1];
      if ( (unsigned __int64)v71 < v70[3] )
      {
        *v71 = "StSolver 1Cpu";
        v72 = __rdtsc();
        v73 = v71 + 2;
        *((_DWORD *)v73 - 2) = v72;
        v70[1] = v73;
      }
      v74 = *(_OWORD *)&v7->m_constraintQueryIn.m_frameInvDeltaTime.m_storage;
      *(_OWORD *)&v103.m_data[96] = *(_OWORD *)&v7->m_constraintQueryIn.m_subStepDeltaTime.m_storage;
      v75 = *(_OWORD *)&v7->m_constraintQueryIn.m_rhsFactor.m_storage;
      *(_OWORD *)&v103.m_data[112] = v74;
      v76 = *(_OWORD *)&v7->m_constraintQueryIn.m_bodyA.m_storage;
      *(_OWORD *)&v103.m_data[128] = v75;
      *(_OWORD *)&v103.m_data[160] = *(_OWORD *)&v7->m_constraintQueryIn.m_transformA.m_storage;
      v77.m_real = (__m128)v7->m_constraintQueryIn.m_maxConstraintViolationSqrd;
      *(_OWORD *)&v103.m_data[144] = v76;
      v78 = *(_OWORD *)&v7->m_constraintQueryIn.m_tau.m_storage;
      *(hkSimdFloat32 *)&v103.m_data[192] = (hkSimdFloat32)v77.m_real;
      v79 = *(_OWORD *)&v7->m_constraintQueryIn.m_accumulatorAIndex.m_storage;
      *(_OWORD *)&v103.m_data[176] = v78;
      v80 = *(_OWORD *)&v7->m_constraintQueryIn.m_constraintInstance.m_storage;
      *(_OWORD *)&v103.m_data[224] = v79;
      *(_OWORD *)&v103.m_data[208] = v80;
      if ( (int)hkpConstraintSolverSetup::solve(
                  (hkStepInfo *)p_m_dynamicsStepInfo,
                  (hkpSolverInfo *)(p_m_dynamicsStepInfo + 16),
                  (hkpConstraintQueryIn *)&v103.m_data[96],
                  (hkpSimulationIsland *)v4) <= 5 )
        *(_DWORD *)(v31 + 8) = 0;
      v81 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpVelocityAccumulator *, _QWORD))(*v81[13] + 32i64))(v81[13], v11, v109);
    }
    else
    {
      if ( v7->m_world->m_allowIntegrationOfIslandsWithoutConstraintsInASeparateJob.m_bool )
      {
        *(_QWORD *)(v31 + 24) = 0i64;
        *(_QWORD *)(v31 + 32) = 0i64;
        *(_QWORD *)(v31 + 64) = 0i64;
        *(_QWORD *)(v31 + 88) = 0i64;
        *(_QWORD *)(v31 + 96) = 0i64;
        *(_DWORD *)(v31 + 104) = *(_DWORD *)(v4 + 24);
        v56 = *(_DWORD *)(v4 + 28);
        *(_QWORD *)(v31 + 184) = 0i64;
        *(_DWORD *)(v31 + 108) = v56;
        *(_DWORD *)(v31 + 36) = v109;
        *(_BYTE *)(v31 + 41) = v17;
        *(_QWORD *)(v31 + 112) = &v7->m_constraintQueryIn;
        v57 = ((unsigned int)(v111 - 1) >> 7) + 1;
        *(_DWORD *)(v31 + 4) = v57 + v17;
        *(_WORD *)&v5->m_jobSubType = 11;
        v5->m_jobSpuType.m_storage = 2;
        v5->m_threadAffinity = -1;
        v5->m_size = 112;
        v58 = *(_QWORD *)(v31 + 184);
        *(_WORD *)&v5->m_data[74] = 0;
        *(_QWORD *)&v5->m_data[32] = v58;
        *(_WORD *)&v5->m_data[72] = *(_WORD *)(v31 + 128);
        v59 = *(_QWORD *)(v31 + 24);
        *(_QWORD *)&v5->m_data[16] = v31;
        *(_QWORD *)&v5->m_data[64] = v59;
        v5->m_data[80] = 1;
        v5->m_jobSpuType.m_storage = 1;
        *(_BYTE *)(v31 + 40) = 1;
        *(_DWORD *)v31 = v57;
        v60 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v61 = v60[1];
        if ( v61 < v60[3] )
        {
          *(_QWORD *)v61 = "lt";
          v62 = __rdtsc();
          *(_DWORD *)(v61 + 8) = v62;
          v60[1] = v61 + 16;
        }
        if ( v17 )
        {
          v63 = hkJobQueue::lockQueue(jobQueue, dynamicDataStorage);
          *(_WORD *)v103.m_data = *(_WORD *)v5->m_data;
          *(_QWORD *)&v103.m_data[8] = *(_QWORD *)&v5->m_data[8];
          *(_QWORD *)&v103.m_data[16] = *(_QWORD *)&v5->m_data[16];
          *(_QWORD *)&v103.m_data[24] = *(_QWORD *)&v5->m_data[24];
          *(_WORD *)&v103.m_jobSubType = 5;
          v103.m_jobSpuType.m_storage = 2;
          v103.m_size = 48;
          v103.m_threadAffinity = -1;
          hkJobQueue::addJobQueueLocked(jobQueue, v63, &v103, JOB_HIGH_PRIORITY);
          hkJobQueue::unlockQueue(&jobQueue->m_criticalSection.m_section);
        }
        return hkJobQueue::finishAddAndGetNextJob(
                 jobQueue,
                 HK_JOB_TYPE_DYNAMICS,
                 JOB_HIGH_PRIORITY,
                 v5,
                 WAIT_FOR_NEXT_JOB);
      }
      v64 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v65 = (_QWORD *)v64[1];
      if ( (unsigned __int64)v65 < v64[3] )
      {
        *v65 = "StSingleObj";
        v66 = __rdtsc();
        v67 = v65 + 2;
        *((_DWORD *)v67 - 2) = v66;
        v64[1] = v67;
      }
      v68 = hkRigidMotionUtilApplyForcesAndStep(
              (hkpSolverInfo *)(p_m_dynamicsStepInfo + 16),
              (hkStepInfo *)p_m_dynamicsStepInfo,
              (hkVector4f *)(p_m_dynamicsStepInfo + 48),
              *(hkpMotion *const **)(v4 + 96),
              *(_DWORD *)(v4 + 104),
              336);
      hkpEntityAabbUtil::entityBatchRecalcAabb(
        *(hkpCollisionInput **)(*(_QWORD *)(v4 + 32) + 184i64),
        *(hkpEntity *const **)(v4 + 96),
        *(unsigned int *)(v4 + 104));
      if ( v68 <= 5 )
        *(_DWORD *)(v31 + 8) = 0;
    }
    if ( v17 )
      hkCpuSplitSimulationIslandJobImpl(
        (hkpSimulationIsland *)v4,
        (hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *)(v31 + 136));
    v82 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v83 = v82[1];
    if ( v83 < v82[3] )
    {
      *(_QWORD *)v83 = "lt";
      v84 = __rdtsc();
      *(_DWORD *)(v83 + 8) = v84;
      v82[1] = v83 + 16;
    }
    *(_BYTE *)(v31 + 40) = 1;
    *(_WORD *)&v5->m_jobSubType = 12;
    v5->m_jobSpuType.m_storage = 2;
    v5->m_size = 64;
    *(_QWORD *)&v5->m_data[16] = v31;
    *(_WORD *)&v5->m_data[32] = 1;
    v5->m_threadAffinity = -1;
    hkJobQueue::finishAddAndGetNextJob(jobQueue, HK_JOB_TYPE_DYNAMICS, JOB_HIGH_PRIORITY, v5, WAIT_FOR_NEXT_JOB);
    return 0i64;
  }
  preallocatedBufferSize = hkpConstraintSolverSetup::calcBufferSize((hkpSimulationIsland *)v4);
  v8 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 13);
  v99 = preallocatedBufferSize;
  v9 = (*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v8 + 24i64))(v8, &v99);
  v10 = v99;
  v109 = v99;
  v11 = (hkpVelocityAccumulator *)v9;
  if ( v9 )
  {
LABEL_8:
    v17 = 0;
    goto LABEL_9;
  }
  while ( 1 )
  {
    v12 = (unsigned int)TlsGetValue(hkThreadNumber.m_slotID);
    TlsSetValue(hkThreadNumber.m_slotID, (LPVOID)1);
    NextJob = hkJobQueue::getNextJob(jobQueue, &job, DO_NOT_WAIT_FOR_NEXT_JOB);
    TlsSetValue(hkThreadNumber.m_slotID, (LPVOID)v12);
    if ( NextJob == GOT_NEXT_JOB )
      break;
    for ( i = 0; i < 4000; ++i )
      ;
    v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v98 = v10;
    v16 = (*(__int64 (__fastcall **)(_QWORD *, int *))(*v15[13] + 24i64))(v15[13], &v98);
    v10 = v98;
    v109 = v98;
    v11 = (hkpVelocityAccumulator *)v16;
    if ( v16 )
    {
      v7 = tl;
      goto LABEL_8;
    }
  }
  hkJobQueue::addJob(jobQueue, v5, JOB_LOW_PRIORITY);
  *(_WORD *)&oldJob.m_jobSubType = 16;
  hkJobQueue::finishJob(jobQueue, &oldJob, FINISH_FLAG_NORMAL);
  p_job = &job;
  if ( (((unsigned __int8)v5 | (unsigned __int8)&job) & 0xF) != 0 )
  {
    memmove(v5, &job, 0x100ui64);
    jobWasCancelledOut->m_bool = 1;
    return 0i64;
  }
  else
  {
    v33 = 2i64;
    do
    {
      v34 = p_job->hkJob;
      v35 = *(_OWORD *)p_job->m_data;
      v5 = (hkJobQueue::JobQueueEntry *)((char *)v5 + 128);
      p_job = (hkJobQueue::JobQueueEntry *)((char *)p_job + 128);
      *((hkJob *)v5 - 8) = v34;
      v36 = *(_OWORD *)&p_job[-1].m_data[144];
      *(_OWORD *)&v5[-1].m_data[128] = v35;
      v37 = *(_OWORD *)&p_job[-1].m_data[160];
      *(_OWORD *)&v5[-1].m_data[144] = v36;
      v38 = *(_OWORD *)&p_job[-1].m_data[176];
      *(_OWORD *)&v5[-1].m_data[160] = v37;
      v39 = *(_OWORD *)&p_job[-1].m_data[192];
      *(_OWORD *)&v5[-1].m_data[176] = v38;
      v40 = *(_OWORD *)&p_job[-1].m_data[208];
      *(_OWORD *)&v5[-1].m_data[192] = v39;
      v41 = *(_OWORD *)&p_job[-1].m_data[224];
      *(_OWORD *)&v5[-1].m_data[208] = v40;
      *(_OWORD *)&v5[-1].m_data[224] = v41;
      --v33;
    }
    while ( v33 );
    jobWasCancelledOut->m_bool = 1;
    return 0i64;
  }
}


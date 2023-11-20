// File Line: 68
// RVA: 0xD93A80
hkBool *__fastcall canSolveOnSingleProcessor(hkBool *result, hkpBuildJacobianTaskHeader *taskHeader)
{
  result->m_bool = 0;
  return result;
}

// File Line: 111
// RVA: 0xD93A90
void __fastcall createAndAppendNewTask(hkpBuildJacobianTaskHeader *taskHeader, hkpBuildJacobianTaskCollection *outBuildCollection, hkpSolveJacobiansTaskCollection *outSolveCollection, hkpBuildJacobianTask **prevBuildTask, hkpSolveConstraintBatchTask **prevSolveTask, hkpSolveConstraintBatchTask **firstTaskOfPreviousBatch, hkpSolveConstraintBatchTask **firstTaskOfCurrentBatch, hkpJacobianSchema **schemas, hkpSolverElemTemp **elemTemp, hkLocalArray<hkConstraintInternalInfo> *constraintsForThisTask, int *batchIndexOfLastTask, int currentBatchIndex, unsigned __int16 **ptrToBatchSize, hkBool putOnPpuOnlyBuildJacobianTaskList, hkBool generateSolveTasks, hkArray<hkConstraintInternalCallbackInfo,hkContainerHeapAllocator> *callbackConstraints)
{
  hkpJacobianSchema **v16; // rsi
  hkpSolverElemTemp **v17; // r15
  hkpBuildJacobianTaskHeader *v18; // r14
  hkpJacobianSchema *v19; // r12
  hkpBuildJacobianTask **v20; // r13
  hkpBuildJacobianTaskCollection *v21; // rdi
  _QWORD **v22; // rax
  __int64 v23; // rax
  hkpBuildJacobianTask *v24; // r8
  hkpVelocityAccumulator *v25; // rax
  __int64 v26; // rbp
  __int64 v27; // r14
  signed __int64 v28; // r10
  hkConstraintInternalInfo *v29; // r11
  hkConstraintInternal *v30; // r9
  __int64 v31; // rcx
  hkConstraintInternalCallbackInfo *v32; // rdx
  __int16 v33; // cx
  _QWORD **v34; // rax
  __int64 v35; // rax
  hkpSolveConstraintBatchTask *v36; // rdx
  hkpSolveConstraintBatchTask *v37; // rax
  unsigned __int16 i; // r10
  hkpBuildJacobianTaskHeader *v39; // [rsp+60h] [rbp+8h]
  hkpSolveJacobiansTaskCollection *v40; // [rsp+70h] [rbp+18h]
  hkpJacobianSchema **schemasa; // [rsp+98h] [rbp+40h]
  hkpSolverElemTemp **elemTempa; // [rsp+A0h] [rbp+48h]

  v40 = outSolveCollection;
  v39 = taskHeader;
  v16 = schemas;
  v17 = elemTemp;
  v18 = taskHeader;
  v19 = *schemas;
  schemasa = (hkpJacobianSchema **)*schemas;
  elemTempa = (hkpSolverElemTemp **)*elemTemp;
  v20 = prevBuildTask;
  v21 = outBuildCollection;
  v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v23 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v22[11] + 8i64))(v22[11], 3968i64);
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
  if ( *v20 )
  {
    (*v20)->m_next = v24;
    (*v20)->m_schemasOfNextTask = *v16;
  }
  else if ( !putOnPpuOnlyBuildJacobianTaskList.m_bool )
  {
    v21->m_buildJacobianTasks = v24;
    v21->m_numBuildJacobianTasks = 0;
  }
  ++v21->m_numBuildJacobianTasks;
  v24->m_taskHeader = v18;
  v24->m_numAtomInfos = constraintsForThisTask->m_size;
  v25 = v18->m_accumulatorsBase;
  v24->m_schemas = v19;
  v24->m_accumulators = v25;
  v26 = constraintsForThisTask->m_size;
  if ( v26 > 0 )
  {
    v27 = 0i64;
    v28 = (signed __int64)&v24->m_atomInfos[0].m_instance;
    do
    {
      v29 = &constraintsForThisTask->m_data[v27];
      v30 = v29->m_internal;
      if ( v29->m_internal->m_callbackRequest & 0xB )
      {
        v31 = callbackConstraints->m_size;
        callbackConstraints->m_size = v31 + 1;
        v32 = &callbackConstraints->m_data[v31];
        v32->m_internal = v29->m_internal;
        *(_QWORD *)&v32->m_entityAIndex = *(_QWORD *)&v29->m_entityAIndex;
        v32->m_atomInfo = (hkpBuildJacobianTask::AtomInfo *)(v28 - 8);
      }
      ++v27;
      v28 += 48i64;
      *(_QWORD *)(v28 - 56) = v30->m_atoms;
      *(_WORD *)(v28 - 16) = v30->m_atomsSize;
      *(_QWORD *)(v28 - 48) = v30->m_constraint;
      *(_QWORD *)(v28 - 40) = v30->m_runtime;
      *(_WORD *)(v28 - 14) = v30->m_runtimeSize;
      v33 = v29->m_entityBIndex + 1;
      *(_WORD *)(v28 - 12) = v29->m_entityAIndex + 1;
      *(_WORD *)(v28 - 10) = v33;
      *(_QWORD *)(v28 - 32) = (char *)v30->m_entities[0] + 368;
      *(_QWORD *)(v28 - 24) = (char *)v30->m_entities[1] + 368;
      *v16 += v30->m_sizeOfSchemas;
      *v17 += v30->m_numSolverElemTemps;
      --v26;
    }
    while ( v26 );
    v18 = v39;
    v19 = (hkpJacobianSchema *)schemasa;
  }
  constraintsForThisTask->m_size = 0;
  *v16 += 32;
  v24->m_schemasOfNextTask = *v16;
  *v17 = (hkpSolverElemTemp *)(((unsigned __int64)&(*v17)[3].m_usedImpulseFactor + 3) & 0xFFFFFFFFFFFFFFF0ui64);
  *v20 = v24;
  if ( generateSolveTasks.m_bool )
  {
    v34 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v35 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v34[11] + 8i64))(v34[11], 64i64);
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
        v40->m_firstSolveJacobiansTask = v36;
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
    v36->m_sizeOfSchemaBuffer = *(_DWORD *)v16 - (_DWORD)v19;
    v36->m_sizeOfSolverElemTempBuffer = *(_DWORD *)v17 - (_DWORD)elemTempa;
    *prevSolveTask = v36;
  }
}

// File Line: 338
// RVA: 0xD93DA0
void __fastcall createBuildJacobianAndSolveJacobianTaskCollection(hkpSimulationIsland *island, hkBool forceCoherentConstraintOrderingInSolver, hkpBuildJacobianTaskHeader *taskHeader, hkpBuildJacobianTaskCollection *outBuildCollection, hkpSolveJacobiansTaskCollection *outSolveCollection)
{
  hkpSimulationIsland *v5; // rsi
  _QWORD *v6; // rdi
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  signed __int64 v9; // rcx
  __int64 v10; // rbx
  unsigned __int64 v11; // r14
  int v12; // er9
  __int64 v13; // r13
  int v14; // er9
  int v15; // er12
  hkLifoAllocator *v16; // rax
  int v17; // edx
  char *v18; // rcx
  signed int v19; // edi
  int v20; // er15
  int v21; // edi
  __int64 v22; // rcx
  __int64 v23; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v24; // rax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v25; // r12
  int v26; // ebx
  __int64 i; // rdi
  int v28; // ebx
  signed int v29; // er13
  __int16 v30; // r12
  __int64 v31; // rax
  unsigned __int64 v32; // rbx
  unsigned __int64 v33; // rsi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v34; // r14
  unsigned __int8 *v35; // rbx
  __int64 v36; // rcx
  int v37; // eax
  unsigned __int8 **v38; // rcx
  int v39; // eax
  unsigned __int8 **v40; // rcx
  _QWORD *v41; // rax
  signed int v42; // edi
  unsigned __int64 v43; // rcx
  signed __int64 v44; // rcx
  _QWORD *v45; // rax
  unsigned __int64 v46; // rcx
  signed __int64 v47; // rcx
  _QWORD *v48; // rax
  unsigned __int64 v49; // rcx
  signed __int64 v50; // rcx
  hkpSolveConstraintBatchTask *v51; // r12
  __int64 v52; // r14
  __int64 v53; // rax
  hkLifoAllocator *v54; // rax
  bool v55; // sf
  unsigned __int8 v56; // of
  unsigned __int64 v57; // rcx
  __int64 *v58; // rcx
  unsigned int v59; // eax
  __int64 v60; // rdi
  __int64 v61; // rax
  bool v62; // r15
  _DWORD *v63; // rdi
  signed int v64; // eax
  void **v65; // rdx
  bool v66; // zf
  __int64 v67; // rcx
  char *v68; // r12
  __int64 v69; // r8
  __int64 v70; // rdx
  signed int v71; // er13
  unsigned __int64 v72; // r8
  unsigned __int16 v73; // ax
  unsigned __int16 v74; // ax
  int *v75; // rax
  __int64 v76; // r15
  unsigned __int64 v77; // rdi
  __int64 v78; // rbx
  __int64 v79; // rsi
  _QWORD **v80; // rax
  __int64 v81; // rax
  hkpBuildJacobianTask *v82; // r9
  hkpBuildJacobianTask *v83; // rax
  hkpBuildJacobianTaskCollection *v84; // rax
  hkpVelocityAccumulator *v85; // rax
  __int64 v86; // r10
  _QWORD *v87; // rdi
  unsigned __int64 v88; // r12
  _QWORD *v89; // rbx
  int v90; // esi
  signed __int64 v91; // r8
  __int64 v92; // rdx
  __int64 v93; // rax
  signed __int64 v94; // rcx
  __int16 v95; // cx
  bool v96; // al
  signed __int64 v97; // r15
  unsigned __int64 v98; // rdi
  _QWORD **v99; // rax
  __int64 v100; // rax
  hkpSolveConstraintBatchTask *v101; // rcx
  hkpSolveConstraintBatchTask *v102; // r8
  int v103; // er9
  unsigned __int16 v104; // ax
  __int64 v105; // rdx
  hkpVelocityAccumulator *v106; // rax
  __int64 v107; // rsi
  int v108; // edi
  __int64 v109; // rbx
  unsigned __int16 v110; // ax
  int v111; // ecx
  int *v112; // rdi
  signed int *v113; // rdx
  _QWORD *v114; // rcx
  __int64 v115; // rsi
  int v116; // ebx
  __int64 v117; // r12
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v118; // r14
  __int64 v119; // rdi
  unsigned __int16 v120; // ax
  int *v121; // rax
  _QWORD *v122; // rax
  __int64 *v123; // rax
  unsigned __int64 v124; // r13
  __int64 v125; // r12
  __int64 v126; // rbx
  unsigned __int64 v127; // rsi
  _QWORD **v128; // rax
  __int64 v129; // rax
  hkpBuildJacobianTask *v130; // r9
  hkpBuildJacobianTask *v131; // rax
  hkpBuildJacobianTaskCollection *v132; // rax
  hkpVelocityAccumulator *v133; // rax
  __int64 v134; // r10
  _QWORD *v135; // r8
  _QWORD *v136; // rbx
  int v137; // esi
  signed __int64 v138; // rdi
  __int64 v139; // rdx
  __int64 v140; // rax
  signed __int64 v141; // rcx
  __int16 v142; // cx
  signed __int64 v143; // r12
  unsigned __int64 v144; // r13
  _QWORD **v145; // rax
  __int64 v146; // rax
  hkpSolveConstraintBatchTask *v147; // rcx
  hkpSolveConstraintBatchTask *v148; // rdi
  int v149; // eax
  unsigned __int16 v150; // ax
  __int64 v151; // rdx
  hkpVelocityAccumulator *v152; // rax
  __int64 v153; // rax
  _QWORD **v154; // rax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v155; // rdi
  _QWORD **v156; // rax
  _QWORD **v157; // rax
  unsigned __int16 v158; // ax
  __int64 v159; // rsi
  unsigned int v160; // ecx
  unsigned __int16 v161; // ax
  __int64 v162; // rdi
  _QWORD **v163; // rax
  __int64 v164; // rax
  __int64 *v165; // r15
  __int64 v166; // rdx
  __int64 v167; // r8
  __int64 *v168; // rdi
  __int64 v169; // rcx
  hkLifoAllocator *v170; // rax
  signed int v171; // edi
  hkLifoAllocator *v172; // rax
  int v173; // er8
  _QWORD *v174; // rdi
  _QWORD *v175; // rcx
  unsigned __int64 v176; // rax
  signed __int64 v177; // rcx
  int v178; // [rsp+30h] [rbp-D0h]
  int v179; // [rsp+34h] [rbp-CCh]
  int v180; // [rsp+38h] [rbp-C8h]
  int v181; // [rsp+3Ch] [rbp-C4h]
  int v182; // [rsp+40h] [rbp-C0h]
  char *v183; // [rsp+48h] [rbp-B8h]
  hkResult result; // [rsp+50h] [rbp-B0h]
  unsigned __int16 *v185; // [rsp+58h] [rbp-A8h]
  hkpSolveConstraintBatchTask *v186; // [rsp+60h] [rbp-A0h]
  unsigned __int64 v187; // [rsp+68h] [rbp-98h]
  void *v188; // [rsp+70h] [rbp-90h]
  hkpSolveConstraintBatchTask *v189; // [rsp+78h] [rbp-88h]
  char *array; // [rsp+80h] [rbp-80h]
  int v191; // [rsp+88h] [rbp-78h]
  int v192; // [rsp+8Ch] [rbp-74h]
  char *v193; // [rsp+90h] [rbp-70h]
  int v194; // [rsp+98h] [rbp-68h]
  int v195; // [rsp+9Ch] [rbp-64h]
  unsigned __int8 *v196; // [rsp+A0h] [rbp-60h]
  void *p; // [rsp+A8h] [rbp-58h]
  unsigned __int64 v198; // [rsp+B0h] [rbp-50h]
  _DWORD *v199; // [rsp+B8h] [rbp-48h]
  unsigned __int64 v200; // [rsp+C0h] [rbp-40h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v201; // [rsp+C8h] [rbp-38h]
  int v202; // [rsp+D0h] [rbp-30h]
  hkpBuildJacobianTask *v203; // [rsp+D8h] [rbp-28h]
  unsigned __int8 *v204; // [rsp+E0h] [rbp-20h]
  unsigned __int8 *v205; // [rsp+E8h] [rbp-18h]
  int *v206; // [rsp+F0h] [rbp-10h]
  int *v207; // [rsp+F8h] [rbp-8h]
  unsigned __int64 v208; // [rsp+100h] [rbp+0h]
  unsigned int v209; // [rsp+108h] [rbp+8h]
  int v210; // [rsp+10Ch] [rbp+Ch]
  unsigned int v211; // [rsp+110h] [rbp+10h]
  void *ptr; // [rsp+118h] [rbp+18h]
  void **v213; // [rsp+120h] [rbp+20h]
  __int64 v214; // [rsp+128h] [rbp+28h]
  hkpSimulationIsland *v215; // [rsp+180h] [rbp+80h]
  bool v216; // [rsp+180h] [rbp+80h]
  char v217; // [rsp+188h] [rbp+88h]
  hkpBuildJacobianTaskHeader *v218; // [rsp+190h] [rbp+90h]
  hkpBuildJacobianTaskCollection *v219; // [rsp+198h] [rbp+98h]

  v219 = outBuildCollection;
  v218 = taskHeader;
  v217 = forceCoherentConstraintOrderingInSolver.m_bool;
  v215 = island;
  v5 = island;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtBuildJacTask";
    v8 = __rdtsc();
    v9 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v9 - 8) = v8;
    v6[1] = v9;
  }
  v10 = v5->m_entities.m_size;
  v12 = v5->m_numConstraints;
  v200 = (unsigned __int64)v5->m_entities.m_data;
  v11 = v200;
  v179 = v10;
  v13 = v10;
  v214 = v10;
  v198 = v200 + 8 * v10;
  array = 0i64;
  v191 = 0;
  v192 = 2147483648;
  if ( v12 > 0 )
  {
    if ( v12 < 0 )
      v12 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v12, 16);
  }
  v14 = v5->m_numConstraints;
  v193 = 0i64;
  v194 = 0;
  v195 = 2147483648;
  if ( v14 > 0 )
  {
    if ( v14 < 0 )
      v14 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v193, v14, 16);
  }
  v15 = v5->m_numConstraints;
  v180 = 0;
  v210 = v15;
  if ( v15 )
  {
    v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (24 * v15 + 127) & 0xFFFFFF80;
    v188 = v16->m_cur;
    v18 = (char *)v188 + v17;
    if ( v17 > v16->m_slabSize || v18 > v16->m_end )
      v188 = hkLifoAllocator::allocateFromNewSlab(v16, v17);
    else
      v16->m_cur = v18;
  }
  else
  {
    v188 = 0i64;
  }
  v19 = 64;
  v20 = 0;
  for ( result.m_enum = v15 | 0x80000000; v19 < (signed int)v10; v19 *= 2 )
    ;
  v21 = 4 * v19;
  v22 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 10);
  v209 = 8 * v21;
  ptr = (void *)(*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v22 + 8i64))(v22, (unsigned int)(8 * v21));
  v23 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
  v24 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)(*(__int64 (__fastcall **)(__int64, signed __int64))(*(_QWORD *)v23 + 8i64))(
                                                                                             v23,
                                                                                             16i64);
  v25 = v24;
  v201 = v24;
  if ( v24 )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>(
      v24,
      ptr,
      8 * v21);
  }
  else
  {
    v25 = 0i64;
    v201 = 0i64;
  }
  v26 = 0;
  for ( i = 0i64; i < v13; ++v26 )
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      v25,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      *(_QWORD *)(v11 + 8 * i++),
      v26);
  v28 = 0;
  v29 = 128;
  v30 = 0;
  if ( v11 < v198 )
  {
    do
    {
      v31 = *(_QWORD *)v11;
      if ( v29 != *(_DWORD *)(*(_QWORD *)v11 + 240i64) )
        *(_DWORD *)(v31 + 240) = v29;
      v32 = *(_QWORD *)(v31 + 248);
      v29 += 128;
      v33 = v32 + ((unsigned __int64)*(unsigned __int16 *)(v31 + 256) << 6);
      if ( v32 < v33 )
      {
        v34 = v201;
        v35 = (unsigned __int8 *)(v32 + 42);
        do
        {
          v36 = *v35;
          v204 = v35 - 42;
          *((_WORD *)&v205 + v36) = v30;
          *((_WORD *)&v205 + 1 - (signed int)v36) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                                      v34,
                                                      *(_QWORD *)&v35[8 * (1 - (signed int)v36) - 34],
                                                      0xFFFFui64);
          v20 += v35[1];
          if ( *(v35 - 7) >= 4u )
          {
            v39 = v194;
            v40 = (unsigned __int8 **)&v193[16 * v194];
            if ( v40 )
            {
              *v40 = v204;
              v40[1] = v205;
              v39 = v194;
            }
            v194 = v39 + 1;
          }
          else
          {
            v37 = v191;
            v38 = (unsigned __int8 **)&array[16 * v191];
            if ( v38 )
            {
              *v38 = v204;
              v38[1] = v205;
              v37 = v191;
            }
            v191 = v37 + 1;
          }
          v35 += 64;
        }
        while ( (unsigned __int64)(v35 - 42) < v33 );
        v11 = v200;
      }
      v11 += 8i64;
      ++v30;
      v200 = v11;
    }
    while ( v11 < v198 );
    v5 = v215;
    v28 = 0;
  }
  v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v42 = v179;
  v43 = v41[1];
  if ( v43 < v41[3] )
  {
    v44 = v43 + 16;
    *(_QWORD *)(v44 - 16) = "MiNumEntities";
    *(float *)(v44 - 8) = (float)v42;
    v41[1] = v44;
  }
  v45 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v46 = v45[1];
  if ( v46 < v45[3] )
  {
    v47 = v46 + 16;
    *(_QWORD *)(v47 - 16) = "MiNumConstraints";
    *(float *)(v47 - 8) = (float)v5->m_numConstraints;
    v45[1] = v47;
  }
  v48 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v49 = v48[1];
  if ( v49 < v48[3] )
  {
    v50 = v49 + 16;
    *(_QWORD *)(v50 - 16) = "MiNumJacobians";
    *(float *)(v50 - 8) = (float)v5->m_constraintInfo.m_numSolverResults;
    v48[1] = v50;
  }
  v203 = 0i64;
  v51 = 0i64;
  v218->m_solveInSingleThreadOnPpuOnly.m_bool = v20 != 0;
  v189 = 0i64;
  v52 = 0i64;
  v200 = 0i64;
  v218->m_solveInSingleThread.m_bool = v20 != 0;
  v53 = (__int64)v218->m_schemasBase;
  v216 = v20 == 0;
  v187 = (unsigned __int64)v218->m_solverTempBase;
  outSolveCollection->m_firstBatchSize = 0;
  v196 = (unsigned __int8 *)v53;
  v185 = &outSolveCollection->m_firstBatchSize;
  v186 = 0i64;
  v178 = 0;
  v181 = -1;
  v182 = -1;
  v54 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v56 = __OFSUB__(v54->m_slabSize, 1280);
  v55 = v54->m_slabSize - 1280 < 0;
  v57 = (unsigned __int64)v54->m_cur + 1280;
  p = v54->m_cur;
  if ( v55 ^ v56 || (void *)v57 > v54->m_end )
    p = hkLifoAllocator::allocateFromNewSlab(v54, 1280);
  else
    v54->m_cur = (void *)v57;
  v58 = (__int64 *)*((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 10);
  v59 = 4 * v42;
  v60 = *v58;
  v211 = v59;
  v61 = (*(__int64 (__fastcall **)(__int64 *, _QWORD))(v60 + 8))(v58, v59);
  v62 = 0;
  v63 = (_DWORD *)v61;
  v199 = (_DWORD *)v61;
  v64 = 0;
  v202 = 0;
  do
  {
    if ( v64 )
    {
      v65 = (void **)&v193;
    }
    else
    {
      v65 = (void **)&array;
      v203 = 0i64;
    }
    v66 = *((_DWORD *)v65 + 2) == 0;
    v213 = v65;
    if ( !v66 )
    {
      while ( 1 )
      {
        v67 = v214;
        if ( v214 > 0 )
        {
          while ( v67 )
          {
            *v63 = 0;
            ++v63;
            --v67;
          }
          v63 = v199;
        }
        v68 = (char *)*v65;
        v69 = *((signed int *)v65 + 2);
        ++v181;
        v70 = (__int64)v68;
        v71 = 1;
        v72 = (unsigned __int64)&v68[16 * v69];
        v198 = (unsigned __int64)v68;
        v183 = v68;
        v208 = v72;
        if ( (unsigned __int64)v68 < v72 )
        {
          while ( 1 )
          {
            v73 = *((_WORD *)v68 + 4);
            v179 = 0;
            if ( v73 == -1 )
              v206 = &v179;
            else
              v206 = &v63[v73];
            v74 = *((_WORD *)v68 + 5);
            if ( v74 == -1 )
              v75 = &v179;
            else
              v75 = &v63[v74];
            v207 = v75;
            if ( v28 == 80 || v62 )
            {
              v76 = (__int64)v196;
              v77 = v187;
              v78 = (__int64)v196;
              v79 = v187;
              v204 = (unsigned __int8 *)v187;
              v80 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              v81 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v80[11] + 8i64))(v80[11], 3968i64);
              v82 = (hkpBuildJacobianTask *)v81;
              if ( v81 )
              {
                *(_DWORD *)(v81 + 40) = 0;
                *(_QWORD *)(v81 + 32) = 0i64;
                *(_QWORD *)v81 = 0i64;
              }
              else
              {
                v82 = 0i64;
              }
              v83 = v203;
              if ( v203 )
              {
                v203->m_next = v82;
                v83->m_schemasOfNextTask = (hkpJacobianSchema *)v76;
                v84 = v219;
              }
              else
              {
                v84 = v219;
                v219->m_buildJacobianTasks = v82;
                v219->m_numBuildJacobianTasks = 0;
              }
              ++v84->m_numBuildJacobianTasks;
              v82->m_taskHeader = v218;
              v82->m_numAtomInfos = v178;
              v85 = v218->m_accumulatorsBase;
              v82->m_schemas = (hkpJacobianSchema *)v76;
              v86 = v178;
              v82->m_accumulators = v85;
              if ( v178 > 0 )
              {
                v87 = p;
                v88 = v187;
                v89 = v188;
                v90 = v180;
                v91 = (signed __int64)&v82->m_atomInfos[0].m_instance;
                do
                {
                  v92 = *v87;
                  if ( *(_BYTE *)(*v87 + 34i64) & 0xB )
                  {
                    v93 = v90++;
                    v94 = 3 * v93;
                    v89[v94] = v92;
                    v89[v94 + 1] = v87[1];
                    v89[v94 + 2] = v91 - 8;
                  }
                  v87 += 2;
                  v91 += 48i64;
                  *(_QWORD *)(v91 - 56) = *(_QWORD *)(v92 + 24);
                  *(_WORD *)(v91 - 16) = *(_WORD *)(v92 + 32);
                  *(_QWORD *)(v91 - 48) = *(_QWORD *)v92;
                  *(_QWORD *)(v91 - 40) = *(_QWORD *)(v92 + 48);
                  *(_WORD *)(v91 - 14) = *(_WORD *)(v92 + 56);
                  v95 = *((_WORD *)v87 - 3) + 1;
                  *(_WORD *)(v91 - 12) = *((_WORD *)v87 - 4) + 1;
                  *(_WORD *)(v91 - 10) = v95;
                  *(_QWORD *)(v91 - 32) = *(_QWORD *)(v92 + 8) + 368i64;
                  *(_QWORD *)(v91 - 24) = *(_QWORD *)(v92 + 16) + 368i64;
                  v76 += *(unsigned __int16 *)(v92 + 36);
                  v88 += 4i64 * *(unsigned __int16 *)(v92 + 40);
                  --v86;
                }
                while ( v86 );
                v78 = (__int64)v196;
                v187 = v88;
                v68 = (char *)v198;
                v77 = v187;
                v180 = v90;
                v79 = (__int64)v204;
              }
              v96 = v216;
              v97 = v76 + 32;
              v98 = (v77 + 15) & 0xFFFFFFFFFFFFFFF0ui64;
              v178 = 0;
              v203 = v82;
              v196 = (unsigned __int8 *)v97;
              v82->m_schemasOfNextTask = (hkpJacobianSchema *)v97;
              v187 = v98;
              if ( v216 )
              {
                v99 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
                v100 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v99[11] + 8i64))(v99[11], 64i64);
                v101 = (hkpSolveConstraintBatchTask *)v100;
                if ( v100 )
                {
                  *(_QWORD *)v100 = 0i64;
                  *(_BYTE *)(v100 + 48) = 0;
                  *(_WORD *)(v100 + 50) = 0;
                  *(_QWORD *)(v100 + 56) = 0i64;
                }
                else
                {
                  v101 = 0i64;
                }
                v102 = v189;
                if ( v189 )
                  v189->m_next = v101;
                v103 = v181;
                if ( v181 != v182 )
                {
                  if ( !v181 )
                    outSolveCollection->m_firstSolveJacobiansTask = v101;
                  v182 = v103;
                  if ( v102 )
                  {
                    v104 = *v185;
                    if ( v52 )
                    {
                      v105 = (__int64)v186;
                      do
                      {
                        if ( v52 == v105 )
                          break;
                        *(_WORD *)(v52 + 50) = v104;
                        *(_QWORD *)(v52 + 56) = v105;
                        v52 = *(_QWORD *)v52;
                      }
                      while ( v52 );
                    }
                    v102->m_isLastTaskInBatch.m_bool = 1;
                    v185 = &v102->m_sizeOfNextBatch;
                  }
                  v52 = (__int64)v186;
                  v186 = v101;
                  v200 = v52;
                }
                v189 = v101;
                ++*v185;
                v101->m_taskHeader = v218;
                v106 = v218->m_accumulatorsBase;
                v101->m_schemas = (hkpJacobianSchema *)v78;
                v101->m_accumulators = v106;
                v101->m_solverElemTemp = (hkpSolverElemTemp *)v79;
                v101->m_sizeOfSchemaBuffer = v97 - v78;
                v101->m_sizeOfSolverElemTempBuffer = v98 - v79;
                v96 = v216;
              }
              v28 = 0;
              v70 = (__int64)v183;
              v72 = v208;
              v71 += v96;
              v62 = 0;
            }
            if ( v217 && v71 > 1 )
            {
              if ( (unsigned __int64)v68 < v72 )
              {
                do
                {
                  v123 = *(__int64 **)v68;
                  v68 += 16;
                  v70 += 16i64;
                  *(_QWORD *)(v70 - 16) = v123;
                  *(_QWORD *)(v70 - 8) = *((_QWORD *)v68 - 1);
                }
                while ( (unsigned __int64)v68 < v72 );
                v183 = (char *)v70;
              }
              break;
            }
            if ( *(_BYTE *)(*(_QWORD *)v68 + 43i64) == 1 )
            {
              v107 = **(_QWORD **)v68;
              v108 = 0;
              if ( *(_DWORD *)(v107 + 120) > 0 )
              {
                v109 = 0i64;
                while ( 1 )
                {
                  v110 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                           v201,
                           *(_QWORD *)(v109 + *(_QWORD *)(v107 + 112)),
                           0xFFFFui64);
                  if ( v110 != -1 )
                  {
                    v111 = v199[v110];
                    if ( v111 )
                    {
                      if ( v111 != v71 )
                        break;
                    }
                  }
                  ++v108;
                  v109 += 8i64;
                  if ( v108 >= *(_DWORD *)(v107 + 120) )
                  {
                    v28 = v178;
                    goto LABEL_108;
                  }
                }
LABEL_120:
                v70 = (__int64)v183;
LABEL_121:
                v28 = v178;
                v70 += 16i64;
                *(_QWORD *)(v70 - 16) = *(_QWORD *)v68;
                v122 = (_QWORD *)*((_QWORD *)v68 + 1);
                v183 = (char *)v70;
                *(_QWORD *)(v70 - 8) = v122;
                goto LABEL_128;
              }
LABEL_108:
              v112 = v206;
              v113 = v207;
            }
            else
            {
              v112 = v206;
              if ( *v206 && *v206 != v71 )
                goto LABEL_121;
              v113 = v207;
              if ( *v207 && *v207 != v71 )
                goto LABEL_120;
            }
            v114 = (char *)p + 16 * v28;
            if ( v114 )
            {
              *v114 = *(_QWORD *)v68;
              v114[1] = *((_QWORD *)v68 + 1);
            }
            v178 = ++v28;
            if ( *(_BYTE *)(*(_QWORD *)v68 + 43i64) == 1 )
            {
              v115 = **(_QWORD **)v68;
              v116 = 0;
              if ( *(_DWORD *)(v115 + 120) > 0 )
              {
                v117 = (__int64)v199;
                v118 = v201;
                v119 = 0i64;
                do
                {
                  v120 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                           v118,
                           *(_QWORD *)(v119 + *(_QWORD *)(v115 + 112)),
                           0xFFFFui64);
                  if ( v120 == -1 )
                    v121 = &v179;
                  else
                    v121 = (int *)(v117 + 4i64 * v120);
                  ++v116;
                  *v121 = v71;
                  v119 += 8i64;
                }
                while ( v116 < *(_DWORD *)(v115 + 120) );
                v52 = v200;
                v68 = (char *)v198;
              }
              v62 = v216;
              v28 = v178;
            }
            else
            {
              *v112 = v71;
              *v113 = v71;
            }
            v70 = (__int64)v183;
LABEL_128:
            v72 = v208;
            v68 += 16;
            v198 = (unsigned __int64)v68;
            if ( (unsigned __int64)v68 >= v208 )
              break;
            v63 = v199;
          }
        }
        if ( v28 )
        {
          v124 = v187;
          v125 = (__int64)v196;
          v126 = (__int64)v196;
          v127 = v187;
          v208 = v187;
          v204 = v196;
          v128 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v129 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v128[11] + 8i64))(v128[11], 3968i64);
          v130 = (hkpBuildJacobianTask *)v129;
          if ( v129 )
          {
            *(_DWORD *)(v129 + 40) = 0;
            *(_QWORD *)(v129 + 32) = 0i64;
            *(_QWORD *)v129 = 0i64;
          }
          else
          {
            v130 = 0i64;
          }
          v131 = v203;
          if ( v203 )
          {
            v203->m_next = v130;
            v131->m_schemasOfNextTask = (hkpJacobianSchema *)v125;
            v132 = v219;
          }
          else
          {
            v132 = v219;
            v219->m_buildJacobianTasks = v130;
            v219->m_numBuildJacobianTasks = 0;
          }
          ++v132->m_numBuildJacobianTasks;
          v130->m_taskHeader = v218;
          v130->m_numAtomInfos = v178;
          v133 = v218->m_accumulatorsBase;
          v130->m_schemas = (hkpJacobianSchema *)v125;
          v134 = v178;
          v130->m_accumulators = v133;
          if ( v178 > 0 )
          {
            v135 = p;
            v136 = v188;
            v137 = v180;
            v138 = (signed __int64)&v130->m_atomInfos[0].m_instance;
            do
            {
              v139 = *v135;
              if ( *(_BYTE *)(*v135 + 34i64) & 0xB )
              {
                v140 = v137++;
                v141 = 3 * v140;
                v136[v141] = v139;
                v136[v141 + 1] = v135[1];
                v136[v141 + 2] = v138 - 8;
              }
              v135 += 2;
              v138 += 48i64;
              *(_QWORD *)(v138 - 56) = *(_QWORD *)(v139 + 24);
              *(_WORD *)(v138 - 16) = *(_WORD *)(v139 + 32);
              *(_QWORD *)(v138 - 48) = *(_QWORD *)v139;
              *(_QWORD *)(v138 - 40) = *(_QWORD *)(v139 + 48);
              *(_WORD *)(v138 - 14) = *(_WORD *)(v139 + 56);
              v142 = *((_WORD *)v135 - 3) + 1;
              *(_WORD *)(v138 - 12) = *((_WORD *)v135 - 4) + 1;
              *(_WORD *)(v138 - 10) = v142;
              *(_QWORD *)(v138 - 32) = *(_QWORD *)(v139 + 8) + 368i64;
              *(_QWORD *)(v138 - 24) = *(_QWORD *)(v139 + 16) + 368i64;
              v125 += *(unsigned __int16 *)(v139 + 36);
              v124 += 4i64 * *(unsigned __int16 *)(v139 + 40);
              --v134;
            }
            while ( v134 );
            v126 = (__int64)v204;
            v180 = v137;
            v127 = v208;
          }
          v143 = v125 + 32;
          v144 = (v124 + 15) & 0xFFFFFFFFFFFFFFF0ui64;
          v178 = 0;
          v196 = (unsigned __int8 *)v143;
          v130->m_schemasOfNextTask = (hkpJacobianSchema *)v143;
          v203 = v130;
          v187 = v144;
          if ( v216 )
          {
            v145 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v146 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v145[11] + 8i64))(v145[11], 64i64);
            v147 = (hkpSolveConstraintBatchTask *)v146;
            if ( v146 )
            {
              *(_QWORD *)v146 = 0i64;
              *(_BYTE *)(v146 + 48) = 0;
              *(_WORD *)(v146 + 50) = 0;
              *(_QWORD *)(v146 + 56) = 0i64;
            }
            else
            {
              v147 = 0i64;
            }
            v148 = v189;
            if ( v189 )
              v189->m_next = v147;
            v149 = v181;
            if ( v181 != v182 )
            {
              if ( !v181 )
                outSolveCollection->m_firstSolveJacobiansTask = v147;
              v182 = v149;
              if ( v148 )
              {
                v150 = *v185;
                if ( v52 )
                {
                  v151 = (__int64)v186;
                  do
                  {
                    if ( v52 == v151 )
                      break;
                    *(_WORD *)(v52 + 50) = v150;
                    *(_QWORD *)(v52 + 56) = v151;
                    v52 = *(_QWORD *)v52;
                  }
                  while ( v52 );
                }
                v148->m_isLastTaskInBatch.m_bool = 1;
                v185 = &v148->m_sizeOfNextBatch;
              }
              v52 = (__int64)v186;
              v186 = v147;
              v200 = v52;
            }
            v189 = v147;
            ++*v185;
            v147->m_taskHeader = v218;
            v152 = v218->m_accumulatorsBase;
            v147->m_schemas = (hkpJacobianSchema *)v126;
            v147->m_accumulators = v152;
            v147->m_solverElemTemp = (hkpSolverElemTemp *)v127;
            LODWORD(v152) = v143 - v126;
            v28 = 0;
            v51 = v147;
            v147->m_sizeOfSchemaBuffer = (signed int)v152;
            v147->m_sizeOfSolverElemTempBuffer = v144 - v127;
            goto LABEL_165;
          }
          v28 = 0;
        }
        v51 = v189;
LABEL_165:
        v65 = v213;
        v63 = v199;
        v153 = (v183 - (_BYTE *)*v213) >> 4;
        *((_DWORD *)v213 + 2) = v153;
        if ( !(_DWORD)v153 )
        {
          v64 = v202;
          break;
        }
      }
    }
    v202 = ++v64;
  }
  while ( v64 < 2 );
  v154 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, _DWORD *, _QWORD))(*v154[10] + 16i64))(v154[10], v63, v211);
  v155 = v201;
  if ( v201 )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      v201,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)v155);
    v156 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *, signed __int64))(*v156[11] + 16i64))(
      v156[11],
      v155,
      16i64);
  }
  v157 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*v157[10] + 16i64))(v157[10], ptr, v209);
  if ( v216 )
  {
    v158 = *v185;
    if ( v52 )
    {
      v159 = (__int64)v186;
      do
      {
        if ( v52 == v159 )
          break;
        *(_WORD *)(v52 + 50) = v158;
        *(_QWORD *)(v52 + 56) = v159;
        v52 = *(_QWORD *)v52;
      }
      while ( v52 );
    }
    v51->m_isLastTaskInBatch.m_bool = 1;
    v160 = v218->m_numAllEntities + 1;
    v218->m_accumulatorsEnd = &v218->m_accumulatorsBase[(unsigned __int64)v160];
    v161 = ((v160 - 1) >> 7) + 1;
    v218->m_numApplyGravityJobs = v161;
    v218->m_numIntegrateVelocitiesJobs = v161;
  }
  v162 = v180;
  v219->m_numCallbackConstraints = 0;
  v219->m_callbackConstraints = 0i64;
  if ( (_DWORD)v162 )
  {
    v163 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v164 = (*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v163[11] + 8i64))(v163[11], (unsigned int)(16 * v162));
    v165 = (__int64 *)v188;
    v219->m_numCallbackConstraints = v162;
    v166 = v164;
    v219->m_callbackConstraints = (hkpBuildJacobianTaskCollection::CallbackPair *)v164;
    v167 = v162;
    if ( (signed int)v162 > 0 )
    {
      v168 = v165;
      do
      {
        v169 = *v168;
        v166 += 16i64;
        v168 += 3;
        *(_QWORD *)(v166 - 16) = v169;
        *(_QWORD *)(v166 - 8) = *(v168 - 1);
        --v167;
      }
      while ( v167 );
    }
  }
  else
  {
    v165 = (__int64 *)v188;
  }
  v170 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v170->m_slabSize < 1280 || (char *)p + 1280 != v170->m_cur || v170->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(v170, p, 1280);
  else
    v170->m_cur = p;
  v171 = (24 * v210 + 127) & 0xFFFFFF80;
  v172 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v173 = (v171 + 15) & 0xFFFFFFF0;
  if ( v171 > v172->m_slabSize || (char *)v165 + v173 != v172->m_cur || v172->m_firstNonLifoEnd == v165 )
    hkLifoAllocator::slowBlockFree(v172, v165, v173);
  else
    v172->m_cur = v165;
  if ( (signed int)result.m_enum >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v165,
      24 * (result.m_enum & 0x3FFFFFFF));
  v194 = 0;
  if ( v195 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v193,
      16 * v195);
  v193 = 0i64;
  v195 = 2147483648;
  v191 = 0;
  if ( v192 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      16 * v192);
  array = 0i64;
  v192 = 2147483648;
  v174 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v175 = (_QWORD *)v174[1];
  if ( (unsigned __int64)v175 < v174[3] )
  {
    *v175 = "Et";
    v176 = __rdtsc();
    v177 = (signed __int64)(v175 + 2);
    *(_DWORD *)(v177 - 8) = v176;
    v174[1] = v177;
  }
}

// File Line: 834
// RVA: 0xD93060
__int64 __fastcall integrateJob(hkpMtThreadStructure *tl, hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut, hkBool *jobWasCancelledOut)
{
  __int64 v4; // r14
  hkJobQueue::JobQueueEntry *v5; // rsi
  hkJobQueue *v6; // r12
  hkpMtThreadStructure *v7; // rbx
  __int64 v8; // rcx
  __int64 v9; // rax
  int v10; // er13
  char *v11; // r15
  int v12; // edi
  hkJobQueue::JobStatus v13; // ebx
  signed int v14; // eax
  _QWORD **v15; // rax
  __int64 v16; // rax
  signed int v17; // er12
  _QWORD *v18; // r8
  unsigned __int64 v19; // rcx
  unsigned __int64 v20; // rax
  signed __int64 v21; // r13
  _QWORD *v22; // r8
  _QWORD *v23; // rcx
  unsigned __int64 v24; // rax
  signed __int64 v25; // rcx
  int v26; // edi
  __int64 v27; // rbx
  __int64 v28; // rcx
  _QWORD **v29; // rax
  __int64 v30; // rax
  hkpBuildJacobianTaskHeader *v31; // rdi
  hkJobQueue::JobQueueEntry *v32; // rcx
  signed __int64 v33; // rax
  hkJob v34; // xmm0
  __int128 v35; // xmm1
  __int128 v36; // xmm0
  __int128 v37; // xmm1
  __int128 v38; // xmm0
  __int128 v39; // xmm1
  __int128 v40; // xmm0
  __int128 v41; // xmm1
  __int64 result; // rax
  _QWORD *v43; // r8
  _QWORD *v44; // rcx
  unsigned __int64 v45; // rax
  signed __int64 v46; // rcx
  hkpEntity **v47; // rcx
  int v48; // eax
  _QWORD *v49; // r8
  _QWORD *v50; // rcx
  unsigned __int64 v51; // rax
  signed __int64 v52; // rcx
  char v53; // dl
  char v54; // r8
  signed int v55; // ecx
  int v56; // eax
  unsigned int v57; // ecx
  hkpSolveConstraintBatchTask *v58; // rax
  void *v59; // rax
  _QWORD *v60; // r9
  unsigned __int64 v61; // r8
  unsigned __int64 v62; // rax
  hkJobQueue::DynamicData *v63; // rax
  _QWORD *v64; // r8
  _QWORD *v65; // rcx
  unsigned __int64 v66; // rax
  signed __int64 v67; // rcx
  signed int v68; // ebx
  unsigned int v69; // ecx
  _QWORD *v70; // r8
  _QWORD *v71; // rcx
  unsigned __int64 v72; // rax
  signed __int64 v73; // rcx
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
  signed __int64 v88; // rcx
  int v89; // eax
  unsigned int v90; // ecx
  hkpEntity **v91; // rax
  hkBool v92; // dl
  _QWORD *v93; // r9
  unsigned __int64 v94; // r8
  unsigned __int64 v95; // rax
  __int16 v96; // ax
  int preallocatedBufferSize; // [rsp+40h] [rbp-C0h]
  int v98; // [rsp+44h] [rbp-BCh]
  int v99; // [rsp+48h] [rbp-B8h]
  hkpEntity **v100; // [rsp+50h] [rbp-B0h]
  hkpSolveJacobiansTaskCollection outSolveCollection; // [rsp+58h] [rbp-A8h]
  hkpBuildJacobianTaskCollection outBuildCollection; // [rsp+68h] [rbp-98h]
  hkJobQueue::JobQueueEntry v103; // [rsp+90h] [rbp-70h]
  hkJobQueue::JobQueueEntry job; // [rsp+190h] [rbp+90h]
  hkJobQueue::JobQueueEntry oldJob; // [rsp+290h] [rbp+190h]
  char dynamicDataStorage; // [rsp+390h] [rbp+290h]
  hkpMtThreadStructure *v107; // [rsp+680h] [rbp+580h]
  hkJobQueue *lpCriticalSection; // [rsp+688h] [rbp+588h]
  unsigned int v109; // [rsp+690h] [rbp+590h]
  hkBool *v110; // [rsp+698h] [rbp+598h]
  int v111; // [rsp+698h] [rbp+598h]

  v110 = jobWasCancelledOut;
  lpCriticalSection = jobQueue;
  v107 = tl;
  v4 = *(_QWORD *)&nextJobOut->m_data[8];
  jobWasCancelledOut->m_bool = 0;
  v5 = nextJobOut;
  v6 = jobQueue;
  v7 = tl;
  if ( !*(_DWORD *)(v4 + 20) )
  {
    v17 = 0;
    preallocatedBufferSize = 0;
    v109 = 0;
    v11 = 0i64;
LABEL_9:
    v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v19 = v18[1];
    if ( v19 < v18[3] )
    {
      *(_QWORD *)v19 = "LtIntegrate";
      *(_QWORD *)(v19 + 16) = "StInit";
      v20 = __rdtsc();
      *(_DWORD *)(v19 + 8) = v20;
      v18[1] = v19 + 24;
    }
    v21 = (signed __int64)&v7->m_world->m_dynamicsStepInfo;
    if ( !v7->m_world->m_processActionsInSingleThread.m_bool )
    {
      v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v23 = (_QWORD *)v22[1];
      if ( (unsigned __int64)v23 < v22[3] )
      {
        *v23 = "StActions";
        v24 = __rdtsc();
        v25 = (signed __int64)(v23 + 2);
        *(_DWORD *)(v25 - 8) = v24;
        v22[1] = v25;
      }
      v26 = 0;
      if ( *(_DWORD *)(v4 + 80) > 0 )
      {
        v27 = 0i64;
        do
        {
          v28 = *(_QWORD *)(v27 + *(_QWORD *)(v4 + 72));
          if ( v28 )
            (*(void (__fastcall **)(__int64, signed __int64, _QWORD *))(*(_QWORD *)v28 + 24i64))(v28, v21, v22);
          ++v26;
          v27 += 8i64;
        }
        while ( v26 < *(_DWORD *)(v4 + 80) );
        v7 = v107;
      }
    }
    v29 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v30 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v29[11] + 8i64))(v29[11], 208i64);
    v31 = (hkpBuildJacobianTaskHeader *)v30;
    if ( v30 )
    {
      *(_QWORD *)(v30 + 24) = 0i64;
      *(_QWORD *)(v30 + 32) = 0i64;
      *(_DWORD *)(v30 + 12) = 1;
      *(_DWORD *)(v30 + 16) = 1;
      *(_QWORD *)(v30 + 136) = 0i64;
      *(_DWORD *)(v30 + 144) = 0;
      *(_DWORD *)(v30 + 148) = 2147483648;
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
      v46 = (signed __int64)(v44 + 2);
      *(_DWORD *)(v46 - 8) = v45;
      v43[1] = v46;
    }
    v47 = *(hkpEntity ***)(v4 + 96);
    v48 = *(_DWORD *)(v4 + 104);
    v31->m_numAllEntities = v48;
    v31->m_allEntities = v47;
    v111 = v48;
    LOWORD(v48) = *(_WORD *)(v4 + 108);
    v100 = v47;
    v31->m_numUnfinishedJobsForBroadphase = 0;
    v31->m_islandShouldBeDeactivated = 1;
    v31->m_buffer = 0i64;
    v31->m_bufferSize = 0;
    v31->m_entitiesCapacity = v48;
    v31->m_impulseLimitsBreached = 0i64;
    v31->m_tasks.m_buildJacobianTasks = 0i64;
    v31->m_accumulatorsBase = 0i64;
    v49 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v50 = (_QWORD *)v49[1];
    if ( (unsigned __int64)v50 < v49[3] )
    {
      *v50 = "StSplitIslands";
      v51 = __rdtsc();
      v52 = (signed __int64)(v50 + 2);
      *(_DWORD *)(v52 - 8) = v51;
      v49[1] = v52;
    }
    ++*(_BYTE *)(v4 + 48);
    v53 = *(_BYTE *)(v4 + 49);
    v54 = *(_BYTE *)(v4 + 48);
    if ( v53 & 0xC )
    {
      v55 = *(_DWORD *)(v4 + 40);
      if ( *(_DWORD *)(v4 + 104) > v55 )
        v55 = *(_DWORD *)(v4 + 104);
      if ( v55 < (signed int)v7->m_world->m_minDesiredIslandSize )
      {
        if ( !(v54 & 7) )
          v17 = 1;
      }
      else
      {
        *(_BYTE *)(v4 + 49) = v53 & 0xF3;
        if ( !(v54 & 3) )
          v17 = 1;
      }
    }
    else if ( v53 & 3 && !(v54 & 7) && v7->m_world->m_wantSimulationIslands.m_bool )
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
          v88 = (signed __int64)(v86 + 2);
          *(_DWORD *)(v88 - 8) = v87;
          v85[1] = v88;
        }
        hkpConstraintSolverSetup::calcBufferOffsetsForSolve((hkpSimulationIsland *)v4, v11, preallocatedBufferSize, v31);
        v31->m_numSolverResults = *(_DWORD *)(v4 + 24);
        v89 = *(_DWORD *)(v4 + 28);
        v31->m_bufferCapacity = v109;
        v31->m_exportFinished = 0;
        v31->m_numSolverElemTemps = v89;
        v31->m_splitCheckRequested = v17;
        v90 = (unsigned int)(v111 - 1) >> 7;
        v31->m_constraintQueryIn = &v7->m_constraintQueryIn;
        v31->m_numUnfinishedJobsForBroadphase = v17 + v90 + 1;
        v31->m_openJobs = v90 + 2;
        v91 = v100;
        *(_WORD *)&v5->m_data[42] = v111;
        v5->m_jobSubType = 1;
        *(_QWORD *)&v5->m_data[16] = v31;
        *(_QWORD *)&v5->m_data[32] = v91;
        *(_WORD *)&v5->m_data[40] = 0;
        v5->m_jobSpuType.m_storage = 1;
        hkJobQueue::addJob(lpCriticalSection, v5, 0);
        v92.m_bool = *(_BYTE *)(v21 + 332);
        outBuildCollection.m_buildJacobianTasks = 0i64;
        outBuildCollection.m_numBuildJacobianTasks = 0;
        outBuildCollection.m_callbackConstraints = 0i64;
        outBuildCollection.m_numCallbackConstraints = 0;
        outSolveCollection.m_firstSolveJacobiansTask = 0i64;
        outSolveCollection.m_firstBatchSize = 0;
        createBuildJacobianAndSolveJacobianTaskCollection(
          (hkpSimulationIsland *)v4,
          v92,
          v31,
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
        v31->m_tasks = outBuildCollection;
        *(_WORD *)&v103.m_data[32] = 2;
        v31->m_solveTasks = outSolveCollection;
        v103.m_data[34] = 1;
        *(_WORD *)&v103.m_data[38] = -1;
        *(_WORD *)&v103.m_data[36] = 64;
        v96 = *(_WORD *)v5->m_data;
        *(_QWORD *)&v103.m_data[64] = v31;
        *(_WORD *)&v103.m_data[48] = v96;
        *(_QWORD *)&v103.m_data[56] = *(_QWORD *)&v5->m_data[8];
        *(_QWORD *)&v103.m_data[72] = *(_QWORD *)&v5->m_data[24];
        return hkJobQueue::finishJobAndGetNextJob(
                 lpCriticalSection,
                 (hkJobQueue::JobQueueEntry *)((char *)&v103 + 48),
                 v5,
                 0);
      }
      v70 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v71 = (_QWORD *)v70[1];
      if ( (unsigned __int64)v71 < v70[3] )
      {
        *v71 = "StSolver 1Cpu";
        v72 = __rdtsc();
        v73 = (signed __int64)(v71 + 2);
        *(_DWORD *)(v73 - 8) = v72;
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
      if ( (signed int)hkpConstraintSolverSetup::solve(
                         (hkStepInfo *)v21,
                         (hkpSolverInfo *)(v21 + 16),
                         (hkpConstraintQueryIn *)&v103.m_data[96],
                         (hkpSimulationIsland *)v4) <= 5 )
        v31->m_islandShouldBeDeactivated = 0;
      v81 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v81[13] + 32i64))(v81[13], v11, v109);
    }
    else
    {
      if ( v7->m_world->m_allowIntegrationOfIslandsWithoutConstraintsInASeparateJob.m_bool )
      {
        v31->m_buffer = 0i64;
        *(_QWORD *)&v31->m_bufferSize = 0i64;
        v31->m_accumulatorsBase = 0i64;
        v31->m_schemasBase = 0i64;
        v31->m_solverTempBase = 0i64;
        v31->m_numSolverResults = *(_DWORD *)(v4 + 24);
        v56 = *(_DWORD *)(v4 + 28);
        v31->m_solveTasks.m_firstSolveJacobiansTask = 0i64;
        v31->m_numSolverElemTemps = v56;
        v31->m_bufferCapacity = v109;
        v31->m_splitCheckRequested = v17;
        v31->m_constraintQueryIn = &v7->m_constraintQueryIn;
        v57 = ((unsigned int)(v111 - 1) >> 7) + 1;
        v31->m_numUnfinishedJobsForBroadphase = v57 + v17;
        *(_WORD *)&v5->m_jobSubType = 11;
        v5->m_jobSpuType.m_storage = 2;
        v5->m_threadAffinity = -1;
        v5->m_size = 112;
        v58 = v31->m_solveTasks.m_firstSolveJacobiansTask;
        *(_WORD *)&v5->m_data[74] = 0;
        *(_QWORD *)&v5->m_data[32] = v58;
        *(_WORD *)&v5->m_data[72] = v31->m_numAllEntities;
        v59 = v31->m_buffer;
        *(_QWORD *)&v5->m_data[16] = v31;
        *(_QWORD *)&v5->m_data[64] = v59;
        v5->m_data[80] = 1;
        v5->m_jobSpuType.m_storage = 1;
        v31->m_exportFinished = 1;
        v31->m_openJobs = v57;
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
          v63 = hkJobQueue::lockQueue(lpCriticalSection, &dynamicDataStorage);
          *(_WORD *)v103.m_data = *(_WORD *)v5->m_data;
          *(_QWORD *)&v103.m_data[8] = *(_QWORD *)&v5->m_data[8];
          *(_QWORD *)&v103.m_data[16] = *(_QWORD *)&v5->m_data[16];
          *(_QWORD *)&v103.m_data[24] = *(_QWORD *)&v5->m_data[24];
          *(_WORD *)&v103.m_jobSubType = 5;
          v103.m_jobSpuType.m_storage = 2;
          v103.m_size = 48;
          v103.m_threadAffinity = -1;
          hkJobQueue::addJobQueueLocked(lpCriticalSection, v63, &v103, 0);
          hkJobQueue::unlockQueue(&lpCriticalSection->m_criticalSection.m_section);
        }
        return hkJobQueue::finishAddAndGetNextJob(lpCriticalSection, 0, 0, v5, 0);
      }
      v64 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v65 = (_QWORD *)v64[1];
      if ( (unsigned __int64)v65 < v64[3] )
      {
        *v65 = "StSingleObj";
        v66 = __rdtsc();
        v67 = (signed __int64)(v65 + 2);
        *(_DWORD *)(v67 - 8) = v66;
        v64[1] = v67;
      }
      v68 = hkRigidMotionUtilApplyForcesAndStep(
              (hkpSolverInfo *)(v21 + 16),
              (hkStepInfo *)v21,
              (hkVector4f *)(v21 + 48),
              *(hkpMotion *const **)(v4 + 96),
              *(_DWORD *)(v4 + 104),
              336);
      hkpEntityAabbUtil::entityBatchRecalcAabb(
        *(hkpCollisionInput **)(*(_QWORD *)(v4 + 32) + 184i64),
        *(hkpEntity *const **)(v4 + 96),
        *(unsigned int *)(v4 + 104));
      if ( v68 <= 5 )
        v31->m_islandShouldBeDeactivated = 0;
    }
    if ( v17 )
      hkCpuSplitSimulationIslandJobImpl((hkpSimulationIsland *)v4, &v31->m_newSplitIslands);
    v82 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v83 = v82[1];
    if ( v83 < v82[3] )
    {
      *(_QWORD *)v83 = "lt";
      v84 = __rdtsc();
      *(_DWORD *)(v83 + 8) = v84;
      v82[1] = v83 + 16;
    }
    v31->m_exportFinished = 1;
    *(_WORD *)&v5->m_jobSubType = 12;
    v5->m_jobSpuType.m_storage = 2;
    v5->m_size = 64;
    *(_QWORD *)&v5->m_data[16] = v31;
    *(_WORD *)&v5->m_data[32] = 1;
    v5->m_threadAffinity = -1;
    hkJobQueue::finishAddAndGetNextJob(lpCriticalSection, 0, 0, v5, 0);
    return 0i64;
  }
  preallocatedBufferSize = hkpConstraintSolverSetup::calcBufferSize((hkpSimulationIsland *)v4);
  v8 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 13);
  v99 = preallocatedBufferSize;
  v9 = (*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v8 + 24i64))(v8, &v99);
  v10 = v99;
  v109 = v99;
  v11 = (char *)v9;
  if ( v9 )
  {
LABEL_8:
    v17 = 0;
    goto LABEL_9;
  }
  while ( 1 )
  {
    v12 = (unsigned __int64)TlsGetValue(hkThreadNumber.m_slotID);
    TlsSetValue(hkThreadNumber.m_slotID, (LPVOID)1);
    v13 = hkJobQueue::getNextJob(v6, &job, DO_NOT_WAIT_FOR_NEXT_JOB);
    TlsSetValue(hkThreadNumber.m_slotID, (LPVOID)v12);
    if ( v13 == GOT_NEXT_JOB )
      break;
    v14 = 0;
    do
      ++v14;
    while ( v14 < 4000 );
    v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v98 = v10;
    v16 = (*(__int64 (__fastcall **)(_QWORD *, int *))(*v15[13] + 24i64))(v15[13], &v98);
    v10 = v98;
    v109 = v98;
    v11 = (char *)v16;
    if ( v16 )
    {
      v7 = v107;
      goto LABEL_8;
    }
  }
  hkJobQueue::addJob(v6, v5, JOB_LOW_PRIORITY);
  *(_WORD *)&oldJob.m_jobSubType = 16;
  hkJobQueue::finishJob(v6, &oldJob, 0);
  v32 = &job;
  if ( ((unsigned __int8)v5 | (unsigned __int8)&job) & 0xF )
  {
    memmove(v5, &job, 0x100ui64);
    v110->m_bool = 1;
    result = 0i64;
  }
  else
  {
    v33 = 2i64;
    do
    {
      v34 = v32->0;
      v35 = *(_OWORD *)v32->m_data;
      v5 = (hkJobQueue::JobQueueEntry *)((char *)v5 + 128);
      v32 = (hkJobQueue::JobQueueEntry *)((char *)v32 + 128);
      *(hkJob *)&v5[-1].m_data[112] = v34;
      v36 = *(_OWORD *)&v32[-1].m_data[144];
      *(_OWORD *)&v5[-1].m_data[128] = v35;
      v37 = *(_OWORD *)&v32[-1].m_data[160];
      *(_OWORD *)&v5[-1].m_data[144] = v36;
      v38 = *(_OWORD *)&v32[-1].m_data[176];
      *(_OWORD *)&v5[-1].m_data[160] = v37;
      v39 = *(_OWORD *)&v32[-1].m_data[192];
      *(_OWORD *)&v5[-1].m_data[176] = v38;
      v40 = *(_OWORD *)&v32[-1].m_data[208];
      *(_OWORD *)&v5[-1].m_data[192] = v39;
      v41 = *(_OWORD *)&v32[-1].m_data[224];
      *(_OWORD *)&v5[-1].m_data[208] = v40;
      *(_OWORD *)&v5[-1].m_data[224] = v41;
      --v33;
    }
    while ( v33 );
    v110->m_bool = 1;
    result = 0i64;
  }
  return result;
}


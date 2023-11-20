// File Line: 43
// RVA: 0xD915F0
__int64 __fastcall hkpConstraintSolverSetup::calcBufferOffsetsForSolve(hkpSimulationIsland *island, char *buffer, int bufferSize, hkpBuildJacobianTaskHeader *taskHeader)
{
  __int64 v4; // r11
  hkpJacobianSchema *v5; // r10
  unsigned int v6; // edx
  int v7; // edx
  hkpSolverElemTemp *v8; // r10
  int v9; // eax
  unsigned int v10; // er10
  bool v11; // zf
  hkpVelocityAccumulator *v12; // rcx

  taskHeader->m_buffer = buffer;
  v4 = island->m_entities.m_size;
  taskHeader->m_accumulatorsBase = (hkpVelocityAccumulator *)buffer;
  v5 = (hkpJacobianSchema *)&buffer[128 * island->m_entities.m_size + 144];
  v6 = (unsigned __int64)(1717986919i64 * island->m_numConstraints) >> 32;
  taskHeader->m_schemasBase = v5;
  v7 = 2 * ((v6 >> 31) + ((signed int)v6 >> 5)) + 8;
  v8 = (hkpSolverElemTemp *)&v5[32 * v7 + 32 + island->m_constraintInfo.m_sizeOfSchemas];
  v9 = island->m_constraintInfo.m_numSolverElemTemps + 3 * v7;
  taskHeader->m_solverTempBase = v8;
  v10 = ((4 * v9 + 23) & 0xFFFFFFF0) + (_DWORD)v8 - LODWORD(taskHeader->m_buffer);
  v11 = taskHeader->m_buffer == 0i64;
  taskHeader->m_bufferSize = v10;
  if ( !v11 )
  {
    v12 = taskHeader->m_accumulatorsBase;
    *(_WORD *)&v12->m_type.m_storage = 1;
    v12->m_gravityFactor = 0.0;
    v12->m_invMasses = 0i64;
    v12->m_linearVel = 0i64;
    v12->m_angularVel = 0i64;
    v12->m_scratch3 = 0i64;
    v12->m_scratch0 = (hkVector4f)transform.m_quad;
    v12->m_scratch1 = (hkVector4f)direction.m_quad;
    v12->m_scratch2 = (hkVector4f)stru_141A71280.m_quad;
    v12[v4 + 1].m_type.m_storage = 3;
  }
  return v10;
}

// File Line: 114
// RVA: 0xD91540
int __fastcall hkpConstraintSolverSetup::calcBufferSize(hkpSimulationIsland *island)
{
  int result; // eax
  int v2; // ebx
  hkpBuildJacobianTaskHeader taskHeader; // [rsp+20h] [rbp-D8h]

  taskHeader.m_referenceCount = 1;
  taskHeader.m_numIslandsAfterSplit = 1;
  taskHeader.m_buffer = 0i64;
  *(_QWORD *)&taskHeader.m_bufferSize = 0i64;
  taskHeader.m_newSplitIslands.m_data = 0i64;
  taskHeader.m_newSplitIslands.m_size = 0;
  taskHeader.m_newSplitIslands.m_capacityAndFlags = 2147483648;
  taskHeader.m_tasks.m_buildJacobianTasks = 0i64;
  taskHeader.m_tasks.m_numBuildJacobianTasks = 0;
  taskHeader.m_tasks.m_callbackConstraints = 0i64;
  taskHeader.m_tasks.m_numCallbackConstraints = 0;
  taskHeader.m_solveTasks.m_firstSolveJacobiansTask = 0i64;
  taskHeader.m_solveTasks.m_firstBatchSize = 0;
  result = hkpConstraintSolverSetup::calcBufferOffsetsForSolve(island, 0i64, 0, &taskHeader);
  v2 = result;
  if ( taskHeader.m_newSplitIslands.m_capacityAndFlags >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      taskHeader.m_newSplitIslands.m_data,
      8 * taskHeader.m_newSplitIslands.m_capacityAndFlags);
    result = v2;
  }
  return result;
}

// File Line: 120
// RVA: 0xD926A0
__int64 __fastcall hkpConstraintSolverSetup_calcBufferSize(hkpSimulationIsland *island)
{
  __int64 result; // rax
  unsigned int v2; // ebx
  hkpBuildJacobianTaskHeader taskHeader; // [rsp+20h] [rbp-D8h]

  taskHeader.m_referenceCount = 1;
  taskHeader.m_numIslandsAfterSplit = 1;
  taskHeader.m_buffer = 0i64;
  *(_QWORD *)&taskHeader.m_bufferSize = 0i64;
  taskHeader.m_newSplitIslands.m_data = 0i64;
  taskHeader.m_newSplitIslands.m_size = 0;
  taskHeader.m_newSplitIslands.m_capacityAndFlags = 2147483648;
  taskHeader.m_tasks.m_buildJacobianTasks = 0i64;
  taskHeader.m_tasks.m_numBuildJacobianTasks = 0;
  taskHeader.m_tasks.m_callbackConstraints = 0i64;
  taskHeader.m_tasks.m_numCallbackConstraints = 0;
  taskHeader.m_solveTasks.m_firstSolveJacobiansTask = 0i64;
  taskHeader.m_solveTasks.m_firstBatchSize = 0;
  result = hkpConstraintSolverSetup::calcBufferOffsetsForSolve(island, 0i64, 0, &taskHeader);
  v2 = result;
  if ( taskHeader.m_newSplitIslands.m_capacityAndFlags >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      taskHeader.m_newSplitIslands.m_data,
      8 * taskHeader.m_newSplitIslands.m_capacityAndFlags);
    result = v2;
  }
  return result;
}

// File Line: 310
// RVA: 0xD92770
__int64 __fastcall hkConstraintSolverSetup_integrate2(hkpSolverInfo *si, hkStepInfo *info, hkpVelocityAccumulator *accumulators, hkpEntity *const *bodies, int numBodies)
{
  hkpEntity *const *v5; // rsi
  unsigned int v6; // ebx

  v5 = bodies;
  v6 = hkRigidMotionUtilApplyAccumulators(si, info, accumulators + 1, (hkpMotion *const *)bodies, numBodies, 336);
  hkpEntityAabbUtil::entityBatchRecalcAabb(
    (hkpCollisionInput *)&(*v5)->m_world->m_collisionInput->m_dispatcher,
    v5,
    (unsigned int)numBodies);
  return v6;
}

// File Line: 326
// RVA: 0xD92400
void __fastcall hkpConstraintSolverSetup::oneStepIntegrate(hkpSolverInfo *si, hkStepInfo *info, hkpVelocityAccumulator *accumulatorsBase, hkpEntity *const *entities, int numEntities)
{
  hkpEntity *const *v5; // r14
  hkpVelocityAccumulator *v6; // rbp
  hkStepInfo *v7; // r15
  hkpSolverInfo *v8; // r12
  signed __int64 i; // rdi
  hkVector4f *v10; // rcx
  hkVector4f v11; // xmm0
  char v12; // bl
  hkpMotion *motions; // [rsp+30h] [rbp-B8h]
  hkpEntity *entityBatch; // [rsp+38h] [rbp-B0h]
  hkpVelocityAccumulator accumulators; // [rsp+40h] [rbp-A8h]

  v5 = entities;
  v6 = accumulatorsBase;
  v7 = info;
  v8 = si;
  for ( i = 0i64; i < numEntities; motions->m_deactivationIntegrateCounter = v12 )
  {
    entityBatch = v5[i];
    motions = (hkpMotion *)&entityBatch->m_motion.vfptr;
    v10 = (hkVector4f *)(&v6->m_type.m_storage + entityBatch->m_solverData);
    accumulators.m_type.m_storage = v10->m_quad.m128_i8[0];
    accumulators.m_context.m_storage = v10->m_quad.m128_i8[1];
    accumulators.m_deactivationClass = v10->m_quad.m128_u32[1];
    accumulators.m_gravityFactor = v10->m_quad.m128_f32[2];
    accumulators.m_linearVel = (hkVector4f)v10[1].m_quad;
    accumulators.m_angularVel = (hkVector4f)v10[2].m_quad;
    accumulators.m_invMasses = (hkVector4f)v10[3].m_quad;
    accumulators.m_scratch0 = (hkVector4f)v10[4].m_quad;
    accumulators.m_scratch1 = (hkVector4f)v10[5].m_quad;
    accumulators.m_scratch2 = (hkVector4f)v10[6].m_quad;
    v11.m_quad = (__m128)v10[7];
    accumulators.m_scratch0 = accumulators.m_linearVel;
    accumulators.m_scratch3 = (hkVector4f)v11.m_quad;
    accumulators.m_scratch1 = accumulators.m_angularVel;
    v12 = entityBatch->m_motion.m_deactivationIntegrateCounter;
    motions->m_deactivationIntegrateCounter = -1;
    hkRigidMotionUtilApplyAccumulators(v8, v7, &accumulators, &motions, 1, 0);
    hkpEntityAabbUtil::entityBatchRecalcAabb(
      (hkpCollisionInput *)&entityBatch->m_world->m_collisionInput->m_dispatcher,
      &entityBatch,
      1i64);
    ++i;
  }
}

// File Line: 357
// RVA: 0xD90BE0
__int64 __fastcall hkpConstraintSolverSetup::solve(hkStepInfo *stepInfo, hkpSolverInfo *solverInfo, hkpConstraintQueryIn *constraintQueryIn, hkpSimulationIsland *island)
{
  __int64 v4; // r13
  hkpJacobianSchema *v5; // rax
  int v6; // er14
  signed int v7; // er15
  int v8; // edi
  char *v9; // rsi
  _QWORD **v10; // rax
  unsigned __int64 v11; // rbx
  struct hkpConstraintRuntime *v12; // rcx
  hkpJacobianSchema *v13; // rdx
  __int64 v14; // rdi
  hkpJacobianSchema *v15; // rax
  unsigned __int64 v16; // rcx
  char *v17; // rax
  unsigned __int64 v18; // r12
  char *v19; // r14
  char *v20; // rax
  int v21; // er14
  int v22; // eax
  int v23; // edi
  int v24; // er15
  int v25; // er12
  _QWORD **v26; // rax
  __int64 v27; // rax
  bool v28; // sf
  unsigned __int64 v29; // r12
  __int64 v30; // rax
  hkLifoAllocator *v31; // rax
  int v32; // edx
  char *v33; // rcx
  int v34; // er13
  _QWORD **v35; // rax
  __int64 v36; // rbx
  hkpVelocityAccumulator *v37; // r8
  hkpConstraintQueryIn *v38; // r13
  hkpMotion **v39; // rbx
  hkpMotion **v40; // rcx
  signed int v41; // eax
  __int64 v42; // rdi
  __int64 v43; // rcx
  char *v44; // rdi
  hkpJacobianSchema *v45; // r15
  unsigned __int64 v46; // rdx
  unsigned __int64 v47; // rcx
  hkpJacobianSchema *v48; // rdi
  signed __int64 v49; // r9
  hkpJacobianSchema *v50; // r14
  hkpVelocityAccumulator *v51; // rsi
  struct hkpConstraintRuntime **v52; // rbx
  unsigned __int64 v53; // r15
  __int64 v54; // rcx
  __int64 v55; // rdx
  float v56; // xmm0_4
  unsigned __int16 v58; // cx
  struct hkpConstraintRuntime *v59; // rdx
  struct hkpConstraintRuntime *v60; // rdi
  struct hkpConstraintRuntime *v61; // rcx
  unsigned int v62; // eax
  hkpSimpleContactConstraintAtom *v63; // rcx
  signed int v64; // er14
  hkpJacobianSchema *v65; // rsi
  hkpVelocityAccumulator *v66; // r15
  __int64 v67; // rbx
  hkpVelocityAccumulator *v68; // r8
  float v69; // xmm0_4
  unsigned __int16 v71; // cx
  __int64 v72; // rdx
  unsigned __int64 v73; // rdi
  struct hkpConstraintRuntime *v74; // rcx
  unsigned int v75; // eax
  hkpSimpleContactConstraintAtom *v76; // rcx
  unsigned int v77; // er12
  hkpSolverElemTemp *v78; // r13
  hkpVelocityAccumulator *v79; // r14
  bool v80; // di
  _QWORD *v81; // rax
  __int64 v82; // rbx
  _QWORD *v83; // rcx
  unsigned __int64 v84; // rax
  signed __int64 v85; // rax
  _QWORD *v86; // rax
  _QWORD *v87; // rcx
  unsigned __int64 v88; // rax
  signed __int64 v89; // rax
  hkpMotion **v90; // r14
  int v91; // edi
  _QWORD **v92; // rax
  hkpJacobianSchema *v93; // rbx
  __int64 v94; // rcx
  int v96; // [rsp+30h] [rbp-90h]
  signed int v97; // [rsp+34h] [rbp-8Ch]
  char *v98; // [rsp+38h] [rbp-88h]
  hkpJacobianSchema *schemas; // [rsp+40h] [rbp-80h]
  hkpJacobianSchema *schemasa; // [rsp+40h] [rbp-80h]
  hkpConstraintQueryOut out; // [rsp+48h] [rbp-78h]
  hkpVelocityAccumulator **array; // [rsp+60h] [rbp-60h]
  __int64 v103; // [rsp+68h] [rbp-58h]
  hkpVelocityAccumulator *accumulators; // [rsp+70h] [rbp-50h]
  hkpJacobianSchema *v105; // [rsp+78h] [rbp-48h]
  hkStepInfo *info; // [rsp+8D0h] [rbp+810h]
  hkpSolverInfo *i; // [rsp+8D8h] [rbp+818h]
  hkpConstraintQueryIn *in; // [rsp+8E0h] [rbp+820h]
  __int64 v109; // [rsp+8E8h] [rbp+828h]
  hkpJacobianSchema *v110; // [rsp+8F0h] [rbp+830h]
  int v111; // [rsp+8F8h] [rbp+838h]
  hkpMotion **motions; // [rsp+900h] [rbp+840h]
  void *retaddr; // [rsp+908h] [rbp+848h]

  v4 = v109;
  v5 = v110;
  v6 = *(_DWORD *)(v109 + 20) + 32;
  v7 = (4 * *(_DWORD *)(v109 + 28) + 23) & 0xFFFFFFF0;
  v8 = ((_DWORD)retaddr << 7) + 144;
  v9 = 0i64;
  v96 = 0;
  v105 = 0i64;
  v97 = v7;
  LODWORD(array) = v8 + v7 + v6;
  if ( v110 )
  {
    out.m_jacobianSchemas.m_storage = 0i64;
    v11 = (unsigned __int64)&v110[v111];
  }
  else
  {
    v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    LODWORD(v110) = v8 + v7 + v6;
    v5 = (hkpJacobianSchema *)(*(__int64 (__fastcall **)(_QWORD *, hkpJacobianSchema **))(*v10[13] + 24i64))(
                                v10[13],
                                &v110);
    v11 = (unsigned __int64)&v5[(signed int)v110];
    out.m_jacobianSchemas.m_storage = v5;
    LODWORD(array) = (_DWORD)v110;
  }
  v12 = (struct hkpConstraintRuntime *)v8;
  v13 = (hkpJacobianSchema *)v6;
  v14 = v7;
  v103 = v7;
  out.m_constraintRuntime.m_storage = v12;
$redoAll:
  accumulators = (hkpVelocityAccumulator *)v5;
  v15 = &v5[(_QWORD)v12];
  v16 = (unsigned __int64)v15;
  schemas = v15;
  v17 = (char *)&v15[(_QWORD)v13];
LABEL_6:
  v18 = (unsigned __int64)v17;
  while ( 1 )
  {
    v19 = v17;
    out.m_constraintRuntimeInMainMemory.m_storage = v17;
    v20 = &v17[v14];
    if ( (unsigned __int64)v20 <= v11 )
      break;
    if ( v16 >= v11 )
    {
      v34 = (_DWORD)v20 - LODWORD(out.m_jacobianSchemas.m_storage);
      v96 = (_DWORD)v20 - LODWORD(out.m_jacobianSchemas.m_storage);
      v35 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v5 = (hkpJacobianSchema *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v35[10] + 8i64))(
                                  v35[10],
                                  (unsigned int)v34);
      v12 = out.m_constraintRuntime.m_storage;
      v13 = schemas;
      v36 = v34;
      v4 = v109;
      v9 = (char *)v5;
      v11 = (unsigned __int64)&v5[v36];
      goto $redoAll;
    }
    v21 = *(_DWORD *)(v4 + 16) + 16;
    if ( v18 < v11 )
    {
      v31 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v9 = (char *)v31->m_cur;
      v32 = (v7 + 127) & 0xFFFFFF80;
      v33 = &v9[v32];
      if ( v32 > v31->m_slabSize || v33 > v31->m_end )
      {
        v17 = (char *)hkLifoAllocator::allocateFromNewSlab(v31, v32);
        v16 = (unsigned __int64)schemas;
        v11 = (unsigned __int64)&v17[v14];
        v9 = v17;
      }
      else
      {
        v31->m_cur = v33;
        v16 = (unsigned __int64)schemas;
        v11 = (unsigned __int64)&v9[v14];
        v17 = v9;
      }
    }
    else
    {
      v22 = 0;
      v23 = v11 - v16 - v21;
      if ( v23 > 0 )
        v22 = v11 - v16 - v21;
      v24 = v21 + *(_DWORD *)(v4 + 20) - v22;
      v25 = v24 + v97;
      v96 = v24 + v97;
      v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v27 = (*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v26[10] + 8i64))(v26[10], (unsigned int)(v24 + v97));
      v28 = v23 < 0;
      v14 = v103;
      v9 = (char *)v27;
      if ( v28 )
      {
        v7 = v97;
        v16 = v27;
        schemas = (hkpJacobianSchema *)v27;
        v11 = v27 + v25;
        v17 = (char *)(v27 + *(_DWORD *)(v4 + 20) + 32);
        v105 = 0i64;
        goto LABEL_6;
      }
      v16 = (unsigned __int64)schemas;
      v29 = v11;
      v11 = v27 + v96;
      v105 = (hkpJacobianSchema *)v27;
      v18 = v29 - v21;
      v30 = v24;
      v7 = v97;
      v17 = &v9[v30];
    }
  }
  v37 = accumulators;
  v38 = in;
  v39 = motions;
  *(_WORD *)&accumulators->m_type.m_storage = 1;
  v37->m_gravityFactor = 0.0;
  v37->m_invMasses = 0i64;
  v37->m_linearVel = 0i64;
  v37->m_angularVel = 0i64;
  v37->m_scratch3 = 0i64;
  v98 = v9;
  v37->m_scratch0 = (hkVector4f)transform.m_quad;
  v37->m_scratch1 = (hkVector4f)direction.m_quad;
  v37->m_scratch2 = (hkVector4f)stru_141A71280.m_quad;
  if ( (signed int)retaddr > 0 )
  {
    v40 = v39;
    v41 = 128;
    v42 = (unsigned int)retaddr;
    do
    {
      if ( v41 != (*v40)->m_angularVelocity.m_quad.m128_i32[0] )
        (*v40)->m_angularVelocity.m_quad.m128_i32[0] = v41;
      v41 += 128;
      ++v40;
      --v42;
    }
    while ( v42 );
  }
  out.m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)&v37[1];
  hkRigidMotionUtilApplyForcesAndBuildAccumulators(info, v39, (int)retaddr, 336, v37 + 1)->m_type.m_storage = 3;
  if ( *(_DWORD *)(v109 + 28) - 1 >= 0 )
  {
    v43 = *(unsigned int *)(v109 + 28);
    v44 = v19;
    while ( v43 )
    {
      *(_DWORD *)v44 = 0;
      v44 += 4;
      --v43;
    }
  }
  v45 = schemas;
  v46 = (unsigned __int64)&v39[(signed int)retaddr];
  v47 = (unsigned __int64)v39;
  array = &accumulators;
  v48 = schemas;
  out.m_jacobianSchemas.m_storage = schemas;
  schemasa = (hkpJacobianSchema *)v46;
  v103 = -9223370937343148032i64;
  v49 = 256i64;
  if ( (unsigned __int64)v39 < v46 )
  {
    v50 = v105;
    v51 = accumulators;
    do
    {
      v52 = *(struct hkpConstraintRuntime ***)(*(_QWORD *)v47 + 248i64);
      v53 = (unsigned __int64)&v52[8 * (unsigned __int64)*(unsigned __int16 *)(*(_QWORD *)v47 + 256i64)];
      if ( (unsigned __int64)v52 < v53 )
      {
        do
        {
          if ( *((_BYTE *)v52 + 34) & 0xD )
          {
            v38->m_constraintInstance.m_storage = (hkpConstraintInstance *)*v52;
            out.m_constraintRuntime.m_storage = v52[6];
            v54 = *((_QWORD *)*v52 + 5);
            v55 = *((_QWORD *)*v52 + 6);
            v38->m_bodyA.m_storage = (hkpVelocityAccumulator *)((char *)v51 + *(unsigned int *)(v54 + 240));
            v38->m_bodyB.m_storage = (hkpVelocityAccumulator *)((char *)v51 + *(unsigned int *)(v55 + 240));
            v38->m_transformA.m_storage = *(hkTransformf **)(v54 + 48);
            v38->m_transformB.m_storage = *(hkTransformf **)(v55 + 48);
            if ( *((_BYTE *)v52 + 34) & 9 )
            {
              hkSimpleContactConstraintData_fireCallbacks(
                *((hkpSimpleContactConstraintData **)*v52 + 3),
                v38,
                *(hkpSimpleContactConstraintAtom **)(*((_QWORD *)*v52 + 3) + 64i64),
                (hkpContactPointEvent::Type)2);
              v48 = out.m_jacobianSchemas.m_storage;
            }
            if ( *((_BYTE *)v52 + 34) & 4 )
            {
              (*(void (__fastcall **)(_QWORD, hkpConstraintQueryIn *, hkpConstraintQueryOut *, signed __int64))(**((_QWORD **)*v52 + 3) + 176i64))(
                *((_QWORD *)*v52 + 3),
                v38,
                &out,
                v49);
              v48 = out.m_jacobianSchemas.m_storage;
            }
          }
          if ( *((_BYTE *)v52 + 35) < 4u )
          {
            if ( (unsigned __int64)v48 >= v18 )
            {
              v56 = *(float *)v48 + 0.00000011920929;
              v18 = -1i64;
              *(_QWORD *)&v48[8] = v50 - v48;
              *(float *)v48 = v56;
              *v48 = (hkpJacobianSchema)2;
              out.m_jacobianSchemas.m_storage = v50;
            }
            _RAX = v52[3];
            __asm
            {
              prefetchnta byte ptr [rax]; Prefetch to L1 cache
              prefetchnta byte ptr [rax+40h]; Prefetch to L1 cache
              prefetchnta byte ptr [rax+80h]; Prefetch to L1 cache
              prefetchnta byte ptr [rax+0C0h]; Prefetch to L1 cache
            }
            v58 = *((_WORD *)v52 + 16);
            if ( v58 > 0x100u )
            {
              __asm
              {
                prefetchnta byte ptr [rax+100h]; Prefetch to L1 cache
                prefetchnta byte ptr [rax+140h]; Prefetch to L1 cache
                prefetchnta byte ptr [rax+180h]; Prefetch to L1 cache
                prefetchnta byte ptr [rax+1C0h]; Prefetch to L1 cache
              }
              if ( v58 > 0x200u )
              {
                __asm
                {
                  prefetchnta byte ptr [rax+200h]; Prefetch to L1 cache
                  prefetchnta byte ptr [rax+240h]; Prefetch to L1 cache
                  prefetchnta byte ptr [rax+280h]; Prefetch to L1 cache
                  prefetchnta byte ptr [rax+2C0h]; Prefetch to L1 cache
                }
              }
            }
            v59 = v52[1];
            v60 = v52[2];
            v38->m_bodyA.m_storage = (hkpVelocityAccumulator *)((char *)v51 + *((unsigned int *)v59 + 60));
            v38->m_bodyB.m_storage = (hkpVelocityAccumulator *)((char *)v51 + *((unsigned int *)v60 + 60));
            v38->m_transformA.m_storage = (hkTransformf *)((char *)v59 + 368);
            v38->m_transformB.m_storage = (hkTransformf *)((char *)v60 + 368);
            v38->m_constraintInstance.m_storage = (hkpConstraintInstance *)*v52;
            out.m_constraintRuntime.m_storage = v52[6];
            v61 = out.m_constraintRuntime.m_storage;
            v38->m_accumulatorAIndex.m_storage = (unsigned __int16)(*((_DWORD *)v59 + 60) >> 7);
            v62 = *((_DWORD *)v60 + 60);
            out.m_constraintRuntimeInMainMemory.m_storage = (void *)v61;
            v38->m_accumulatorBIndex.m_storage = (unsigned __int16)(v62 >> 7);
            v63 = (hkpSimpleContactConstraintAtom *)v52[3];
            if ( v63->m_type.m_storage == 29 )
              hkSimpleContactConstraintDataBuildJacobian(v63, v38, (hkBool)1, &out);
            else
              hkSolverBuildJacobianFromAtomsNotContact(
                (hkpConstraintAtom *)&v63->m_type,
                *((unsigned __int16 *)v52 + 16),
                v38,
                &out);
          }
          else
          {
            if ( (_DWORD)v103 == (HIDWORD(v103) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
            array[(signed int)v103] = (hkpVelocityAccumulator *)v52;
            LODWORD(v103) = v103 + 1;
          }
          v48 = out.m_jacobianSchemas.m_storage;
          v52 += 8;
        }
        while ( (unsigned __int64)v52 < v53 );
        v47 = v103;
        v46 = (unsigned __int64)schemasa;
      }
      v47 += 8i64;
      v103 = v47;
    }
    while ( v47 < v46 );
    v9 = v98;
    v45 = schemasa;
    v49 = 256i64;
  }
  v64 = 0;
  if ( (signed int)v103 > 0 )
  {
    v65 = v105;
    v66 = accumulators;
    v67 = 0i64;
    while ( 1 )
    {
      v68 = array[v67];
      if ( (unsigned __int64)v48 >= v18 )
      {
        v69 = *(float *)v48 + 0.00000011920929;
        v18 = -1i64;
        *(_QWORD *)&v48[8] = v65 - v48;
        *(float *)v48 = v69;
        *v48 = (hkpJacobianSchema)2;
        out.m_jacobianSchemas.m_storage = v65;
      }
      _RAX = v68->m_linearVel.m_quad.m128_u64[1];
      __asm
      {
        prefetchnta byte ptr [rax]; Prefetch to L1 cache
        prefetchnta byte ptr [rax+40h]; Prefetch to L1 cache
        prefetchnta byte ptr [rax+80h]; Prefetch to L1 cache
        prefetchnta byte ptr [rax+0C0h]; Prefetch to L1 cache
      }
      v71 = v68->m_angularVel.m_quad.m128_u16[0];
      if ( v71 > (unsigned __int16)v49 )
      {
        __asm
        {
          prefetchnta byte ptr [rax+100h]; Prefetch to L1 cache
          prefetchnta byte ptr [rax+140h]; Prefetch to L1 cache
          prefetchnta byte ptr [rax+180h]; Prefetch to L1 cache
          prefetchnta byte ptr [rax+1C0h]; Prefetch to L1 cache
        }
        if ( v71 > 0x200u )
        {
          __asm
          {
            prefetchnta byte ptr [rax+200h]; Prefetch to L1 cache
            prefetchnta byte ptr [rax+240h]; Prefetch to L1 cache
            prefetchnta byte ptr [rax+280h]; Prefetch to L1 cache
            prefetchnta byte ptr [rax+2C0h]; Prefetch to L1 cache
          }
        }
      }
      v72 = *(_QWORD *)&v68->m_gravityFactor;
      v73 = v68->m_linearVel.m_quad.m128_u64[0];
      v38->m_bodyA.m_storage = (hkpVelocityAccumulator *)((char *)v66 + *(unsigned int *)(v72 + 240));
      v38->m_bodyB.m_storage = (hkpVelocityAccumulator *)((char *)v66 + *(unsigned int *)(v73 + 240));
      v38->m_transformA.m_storage = (hkTransformf *)(v72 + 368);
      v38->m_transformB.m_storage = (hkTransformf *)(v73 + 368);
      v38->m_constraintInstance.m_storage = *(hkpConstraintInstance **)&v68->m_type.m_storage;
      out.m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)v68->m_invMasses.m_quad.m128_u64[0];
      v74 = out.m_constraintRuntime.m_storage;
      v38->m_accumulatorAIndex.m_storage = (unsigned __int16)(*(_DWORD *)(v72 + 240) >> 7);
      v75 = *(_DWORD *)(v73 + 240);
      out.m_constraintRuntimeInMainMemory.m_storage = (void *)v74;
      v38->m_accumulatorBIndex.m_storage = (unsigned __int16)(v75 >> 7);
      v76 = (hkpSimpleContactConstraintAtom *)v68->m_linearVel.m_quad.m128_u64[1];
      if ( v76->m_type.m_storage == 29 )
        hkSimpleContactConstraintDataBuildJacobian(v76, v38, (hkBool)1, &out);
      else
        hkSolverBuildJacobianFromAtomsNotContact(
          (hkpConstraintAtom *)&v76->m_type,
          v68->m_angularVel.m_quad.m128_u16[0],
          v38,
          &out);
      v48 = out.m_jacobianSchemas.m_storage;
      ++v64;
      ++v67;
      if ( v64 >= (signed int)v103 )
        break;
      LOWORD(v49) = 256;
    }
    v9 = v98;
    v45 = schemasa;
  }
  v77 = 0;
  *(_DWORD *)v48 = 0;
  LODWORD(v103) = 0;
  if ( v103 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkpVelocityAccumulator **, _QWORD, signed __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      array,
      (unsigned int)(8 * HIDWORD(v103)),
      v49);
  v78 = (hkpSolverElemTemp *)out.m_constraintRuntimeInMainMemory.m_storage;
  v79 = accumulators;
  v80 = hkSolveConstraints(i, v45, accumulators, (hkpSolverElemTemp *)out.m_constraintRuntimeInMainMemory.m_storage);
  v81 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v82 = v109;
  v83 = v81;
  v84 = v81[1];
  if ( v84 < v83[3] )
  {
    v85 = v84 + 16;
    *(_QWORD *)(v85 - 16) = "MiNumJacobians";
    *(float *)(v85 - 8) = (float)*(signed int *)(v82 + 24);
    v83[1] = v85;
  }
  v86 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v87 = v86;
  v88 = v86[1];
  if ( v88 < v87[3] )
  {
    v89 = v88 + 16;
    *(_QWORD *)(v89 - 16) = "MiNumEntities";
    *(float *)(v89 - 8) = (float)(signed int)retaddr;
    v87[1] = v89;
  }
  if ( v80 )
  {
    hkExportImpulsesAndRhs(i, v78, v45, v79);
    v90 = motions;
    v91 = hkRigidMotionUtilApplyAccumulators(
            i,
            info,
            (hkpVelocityAccumulator *)out.m_constraintRuntime.m_storage,
            motions,
            (int)retaddr,
            336);
    hkpEntityAabbUtil::entityBatchRecalcAabb(
      *(hkpCollisionInput **)(*(_QWORD *)&(*v90)->m_type.m_storage + 184i64),
      (hkpEntity *const *)v90,
      (unsigned int)retaddr);
    v77 = v91;
    if ( *(_DWORD *)v45 )
      hkpWorldCallbackUtil::fireContactImpulseLimitBreached(
        *(hkpWorld **)(v82 + 32),
        (hkpContactImpulseLimitBreachedListenerInfo *)&v45[16],
        *(_DWORD *)v45);
  }
  if ( v9 )
  {
    v92 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v92[10] + 16i64))(v92[10], v9, (unsigned int)v96);
  }
  v93 = out.m_jacobianSchemas.m_storage;
  if ( out.m_jacobianSchemas.m_storage )
  {
    v94 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 13);
    (*(void (__fastcall **)(__int64, hkpJacobianSchema *, _QWORD))(*(_QWORD *)v94 + 32i64))(
      v94,
      v93,
      (unsigned int)array);
  }
  return v77;
}

// File Line: 582
// RVA: 0xD916D0
void __fastcall hkpConstraintSolverSetup::initializeSolverState(hkStepInfo *stepInfo, hkpSolverInfo *solverInfo, hkpConstraintQueryIn *constraintQueryIn, char *buffer, int bufferSize, const char *priorityClassMap, const float *priorityClassRatios, hkpConstraintSolverResources *s)
{
  char *v8; // rdi
  int v9; // er11
  hkpVelocityAccumulator *v10; // r8
  hkpVelocityAccumulator *v11; // r9
  hkpConstraintSolverResources::VelocityAccumTransformBackup *v12; // r8
  float v13; // xmm2_4
  float v14; // xmm0_4
  hkpJacobianSchema *v15; // rcx
  float v16; // xmm0_4
  hkpJacobianSchema *v17; // rdx
  float v18; // xmm2_4
  hkpJacobianSchema *v19; // rcx
  hkpVelocityAccumulator *v20; // rax

  v8 = buffer;
  s->m_solverInfo = solverInfo;
  s->m_stepInfo = stepInfo;
  s->m_constraintQueryInput = constraintQueryIn;
  hkMemUtil::memCpy(s->m_priorityClassMap, priorityClassMap, 6);
  v9 = bufferSize - bufferSize % 16;
  v10 = (hkpVelocityAccumulator *)((unsigned __int64)(v8 + 15) & 0xFFFFFFFFFFFFFFF0ui64);
  s->m_accumulators = v10;
  v11 = (hkpVelocityAccumulator *)(((unsigned __int64)v10 + 10 * v9 / 65) & 0xFFFFFFFFFFFFFFF0ui64);
  s->m_accumulatorsEnd = v11;
  s->m_accumulatorsBackup = (hkpConstraintSolverResources::VelocityAccumTransformBackup *)v11;
  v12 = (hkpConstraintSolverResources::VelocityAccumTransformBackup *)(((unsigned __int64)v11 + 5 * v9 / 65) & 0xFFFFFFFFFFFFFFF0ui64);
  s->m_accumulatorsBackupEnd = v12;
  s->m_schemas[0].m_begin = (hkpJacobianSchema *)v12;
  v13 = (float)(40 * (v9 - 48));
  v14 = v13 * *priorityClassRatios;
  s->m_schemas[0].m_current = (hkpJacobianSchema *)v12;
  s->m_schemas[0].m_lastProcessed = (hkpJacobianSchema *)v12;
  v15 = (hkpJacobianSchema *)(((unsigned __int64)&v12->m_coreTworldRotation.m_col1
                             + (signed int)(float)(v14 * 0.015384615)) & 0xFFFFFFFFFFFFFFF0ui64);
  s->m_schemas[0].m_end = v15;
  s->m_schemas[1].m_begin = v15;
  v16 = v13 * priorityClassRatios[1];
  s->m_schemas[1].m_current = v15;
  s->m_schemas[1].m_lastProcessed = v15;
  v17 = (hkpJacobianSchema *)((unsigned __int64)&v15[(signed int)(float)(v16 * 0.015384615) + 16] & 0xFFFFFFFFFFFFFFF0ui64);
  s->m_schemas[1].m_end = v17;
  s->m_schemas[2].m_begin = v17;
  v18 = v13 * priorityClassRatios[2];
  s->m_schemas[2].m_current = v17;
  s->m_schemas[2].m_lastProcessed = v17;
  v19 = (hkpJacobianSchema *)((unsigned __int64)&v17[(signed int)(float)(v18 * 0.015384615) + 16] & 0xFFFFFFFFFFFFFFF0ui64);
  s->m_schemas[2].m_end = v19;
  v20 = s->m_accumulators;
  s->m_elemTemp = (hkpSolverElemTemp *)v19;
  s->m_elemTempEnd = (hkpSolverElemTemp *)&v8[v9];
  s->m_elemTempCurrent = (hkpSolverElemTemp *)v19;
  s->m_elemTempLastProcessed = (hkpSolverElemTemp *)v19;
  s->m_accumulatorsCurrent = v20;
}

// File Line: 675
// RVA: 0xD91870
void __fastcall hkpConstraintSolverSetup::shutdownSolver(hkpConstraintSolverResources *s)
{
  ;
}

// File Line: 680
// RVA: 0xD91880
void __fastcall hkpConstraintSolverSetup::internalAddAccumulators(hkpConstraintSolverResources *s, hkpEntity *const *entities, int numEntities)
{
  hkpVelocityAccumulator *v3; // r11
  __int64 v4; // rsi
  hkpEntity *const *v5; // r14
  hkpConstraintSolverResources *v6; // rdi
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  signed int v15; // edx
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r9
  float v19; // xmm0_4
  __int128 v20; // xmm0
  hkpConstraintSolverResources::VelocityAccumTransformBackup *v21; // rax
  int v22; // edx
  hkpEntity *const *v23; // r8
  __int64 v24; // r9
  hkpEntity *v25; // rax
  int v26; // ecx
  hkpVelocityAccumulator *v27; // r15
  unsigned __int64 v28; // rcx
  signed __int64 v29; // rbx
  signed __int64 v30; // r11
  _OWORD *v31; // rbx
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm3_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  signed __int64 v40; // r10
  __int64 v41; // r8
  __int64 v42; // r9
  float v43; // xmm0_4
  __int128 v44; // [rsp+10h] [rbp-29h]
  hkpVelocityAccumulator *accumulatorsOut[2]; // [rsp+20h] [rbp-19h]
  hkpConstraintSolverResources *v46; // [rsp+A0h] [rbp+67h]
  float vars0; // [rsp+B0h] [rbp+77h]

  if ( numEntities )
  {
    v3 = s->m_accumulatorsCurrent;
    v4 = (unsigned int)numEntities;
    v5 = entities;
    v6 = s;
    if ( v3 == s->m_accumulators )
    {
      *(_WORD *)&v3->m_type.m_storage = 1;
      v3->m_gravityFactor = 0.0;
      v3->m_invMasses = 0i64;
      v3->m_linearVel = 0i64;
      v3->m_angularVel = 0i64;
      v3->m_scratch3 = 0i64;
      v3->m_scratch0 = (hkVector4f)transform.m_quad;
      v3->m_scratch1 = (hkVector4f)direction.m_quad;
      v3->m_context.m_storage = 1;
      v3->m_scratch2 = (hkVector4f)stru_141A71280.m_quad;
      v7 = v3->m_scratch0.m_quad.m128_f32[0];
      v8 = v3->m_scratch1.m_quad.m128_f32[1];
      v9 = v3->m_scratch2.m_quad.m128_f32[2];
      v10 = (float)(v3->m_scratch0.m_quad.m128_f32[0] + v8) + v9;
      if ( v10 <= 0.0 )
      {
        LODWORD(v44) = 1;
        *(_QWORD *)((char *)&v44 + 4) = 2i64;
        v15 = 0;
        if ( v8 > v7 )
          v15 = 1;
        if ( v9 > v3->m_scratch0.m_quad.m128_f32[5 * v15] )
          v15 = 2;
        v16 = v15;
        v17 = *((signed int *)&v44 + v15);
        v18 = *((signed int *)&v44 + v17);
        vars0 = (float)(v3->m_scratch0.m_quad.m128_f32[5 * v15]
                      - (float)(v3->m_scratch0.m_quad.m128_f32[5 * v18] + v3->m_scratch0.m_quad.m128_f32[5 * v17]))
              + 1.0;
        v19 = fsqrt(vars0);
        *((float *)&v44 + v16) = v19 * 0.5;
        *((float *)&v44 + 3) = (float)(v3->m_scratch0.m_quad.m128_f32[v18 + 4 * v17]
                                     - v3->m_scratch0.m_quad.m128_f32[v17 + 4 * v18])
                             * (float)(0.5 / v19);
        *((float *)&v44 + v17) = (float)(v3->m_scratch0.m_quad.m128_f32[v16 + 4 * v17]
                                       + v3->m_scratch0.m_quad.m128_f32[v17 + 4 * v16])
                               * (float)(0.5 / v19);
        *((float *)&v44 + v18) = (float)(v3->m_scratch0.m_quad.m128_f32[v15 + 4 * v18]
                                       + v3->m_scratch0.m_quad.m128_f32[v18 + 4i64 * v15])
                               * (float)(0.5 / v19);
      }
      else
      {
        v11 = v3->m_scratch2.m_quad.m128_f32[0] - v3->m_scratch0.m_quad.m128_f32[2];
        vars0 = v10 + 1.0;
        v12 = fsqrt(v10 + 1.0);
        v13 = v3->m_scratch1.m_quad.m128_f32[2] - v3->m_scratch2.m_quad.m128_f32[1];
        *((float *)&v44 + 3) = v12 * 0.5;
        *(float *)&v44 = v13 * (float)(0.5 / v12);
        v14 = v3->m_scratch0.m_quad.m128_f32[1];
        *((float *)&v44 + 1) = v11 * (float)(0.5 / v12);
        *((float *)&v44 + 2) = (float)(v14 - v3->m_scratch1.m_quad.m128_f32[0]) * (float)(0.5 / v12);
      }
      v20 = v44;
      v3->m_scratch0 = 0i64;
      v3->m_scratch1 = 0i64;
      v3->m_scratch2 = (hkVector4f)v20;
      s->m_accumulatorsCurrent = v3 + 1;
      v21 = s->m_accumulatorsBackup;
      v21->m_coreTworldRotation.m_col0 = (hkVector4f)transform.m_quad;
      v21->m_coreTworldRotation.m_col1 = (hkVector4f)direction.m_quad;
      v21->m_coreTworldRotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    }
    if ( (_DWORD)v4 )
    {
      v22 = 0;
      v23 = v5;
      v24 = v4;
      do
      {
        v25 = *v23;
        v26 = v22;
        v22 += 128;
        ++v23;
        v25->m_solverData = LODWORD(v6->m_accumulatorsCurrent) + v26 - LODWORD(v6->m_accumulators);
        --v24;
      }
      while ( v24 );
    }
    v27 = v6->m_accumulatorsCurrent;
    v28 = (unsigned __int64)(*v5)->m_solverData >> 7;
    accumulatorsOut[0] = v6->m_accumulatorsCurrent;
    v29 = (signed __int64)&v6->m_accumulatorsBackup[v28];
    v6->m_accumulatorsCurrent = hkRigidMotionUtilApplyForcesAndBuildAccumulators(
                                  v6->m_stepInfo,
                                  (hkpMotion *const *)v5,
                                  v4,
                                  336,
                                  accumulatorsOut[0]);
    if ( (_DWORD)v4 )
    {
      v30 = (signed __int64)&v27->m_scratch0;
      v31 = (_OWORD *)(v29 + 32);
      do
      {
        *(v31 - 2) = *(_OWORD *)v30;
        *(v31 - 1) = *(_OWORD *)(v30 + 16);
        *v31 = *(_OWORD *)(v30 + 32);
        *(_BYTE *)(v30 - 63) = 1;
        v32 = *(float *)v30;
        v33 = *(float *)(v30 + 20);
        v34 = *(float *)(v30 + 40);
        v35 = (float)(*(float *)v30 + v33) + v34;
        if ( v35 <= 0.0 )
        {
          LODWORD(v44) = 1;
          *(_QWORD *)((char *)&v44 + 4) = 2i64;
          v40 = 0i64;
          if ( v33 > v32 )
            v40 = 1i64;
          if ( v34 > *(float *)(v30 + 20 * v40) )
            v40 = 2i64;
          v41 = *((signed int *)&v44 + v40);
          v42 = *((signed int *)&v44 + v41);
          vars0 = (float)(*(float *)(v30 + 20 * v40) - (float)(*(float *)(v30 + 20 * v42) + *(float *)(v30 + 20 * v41)))
                + 1.0;
          v43 = fsqrt(vars0);
          *((float *)accumulatorsOut + v40) = v43 * 0.5;
          *((float *)&accumulatorsOut[1] + 1) = (float)(*(float *)(v30 + 4 * (v42 + 4 * v41))
                                                      - *(float *)(v30 + 4 * (v41 + 4 * v42)))
                                              * (float)(0.5 / v43);
          *((float *)accumulatorsOut + v41) = (float)(*(float *)(v30 + 4 * (v40 + 4 * v41))
                                                    + *(float *)(v30 + 4 * (v41 + 4 * v40)))
                                            * (float)(0.5 / v43);
          *((float *)accumulatorsOut + v42) = (float)(*(float *)(v30 + 4 * (v40 + 4 * v42))
                                                    + *(float *)(v30 + 4 * (v42 + 4 * v40)))
                                            * (float)(0.5 / v43);
        }
        else
        {
          v36 = *(float *)(v30 + 32) - *(float *)(v30 + 8);
          vars0 = v35 + 1.0;
          v37 = fsqrt(v35 + 1.0);
          v38 = *(float *)(v30 + 24) - *(float *)(v30 + 36);
          *((float *)&accumulatorsOut[1] + 1) = v37 * 0.5;
          *(float *)accumulatorsOut = v38 * (float)(0.5 / v37);
          v39 = *(float *)(v30 + 4);
          *((float *)accumulatorsOut + 1) = v36 * (float)(0.5 / v37);
          *(float *)&accumulatorsOut[1] = (float)(v39 - *(float *)(v30 + 16)) * (float)(0.5 / v37);
        }
        v30 += 128i64;
        v31 += 3;
        *(_OWORD *)(v30 - 96) = *(_OWORD *)accumulatorsOut;
        *(_OWORD *)(v30 - 128) = 0i64;
        *(_OWORD *)(v30 - 112) = 0i64;
        --v4;
      }
      while ( v4 );
      v6 = v46;
    }
    v6->m_accumulatorsCurrent->m_type.m_storage = 3;
  }
}  while ( v4 );
      v6 = v46;
    }
    v6->m_accumulatorsCurrent->m_type.m_storage = 3;
  }
}

// File Line: 732
// RVA: 0xD91D40
void __fastcall hkpConstraintSolverSetup::internalAddJacobianSchemas(hkpConstraintSolverResources *s, hkpConstraintInstance **constraints, int numConstraints, hkArray<hkpConstraintSchemaInfo,hkContainerHeapAllocator> *constraintStatus)
{
  hkpConstraintQueryIn *v4; // r15
  hkArray<hkpConstraintSchemaInfo,hkContainerHeapAllocator> *v5; // r13
  hkpConstraintInstance **v6; // r12
  hkpConstraintSolverResources *v7; // r14
  hkpConstraintInstance *v8; // rsi
  hkConstraintInternal *v9; // r11
  hkpEntity *v10; // r10
  hkpEntity *v11; // r9
  hkpVelocityAccumulator *v12; // rdi
  hkpVelocityAccumulator *v13; // rbx
  hkpEntity **v14; // r11
  hkpConstraintSolverResources::VelocityAccumTransformBackup *v15; // rdx
  hkpEntity *v16; // rax
  unsigned __int64 v17; // r8
  unsigned __int64 v18; // rcx
  hkVector4f v19; // xmm0
  hkVector4f v20; // xmm1
  hkVector4f v21; // xmm0
  hkVector4f v22; // xmm1
  hkVector4f v23; // xmm0
  hkVector4f v24; // xmm1
  hkpEntity *v25; // rax
  signed __int64 v26; // rcx
  hkpConstraintSchemaInfo *v27; // rdx
  signed __int64 v28; // r8
  signed __int64 v29; // r13
  hkConstraintInternal *v30; // rax
  hkpSimpleContactConstraintAtom *v31; // rcx
  hkpJacobianSchema *v32; // rax
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm3_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm3_4
  float v39; // xmm0_4
  float v40; // xmm0_4
  signed __int64 v41; // r10
  __int64 v42; // r8
  __int64 v43; // r9
  float v44; // xmm0_4
  __int128 v45; // xmm0
  float v46; // xmm2_4
  float v47; // xmm1_4
  float v48; // xmm3_4
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm3_4
  float v52; // xmm0_4
  float v53; // xmm0_4
  signed __int64 v54; // r10
  __int64 v55; // r8
  __int64 v56; // r9
  float v57; // xmm0_4
  int v58; // [rsp+20h] [rbp-89h]
  __int64 v59; // [rsp+24h] [rbp-85h]
  int v60; // [rsp+30h] [rbp-79h]
  __int64 v61; // [rsp+34h] [rbp-75h]
  __int128 v62; // [rsp+40h] [rbp-69h]
  hkVector4f v63; // [rsp+50h] [rbp-59h]
  hkpConstraintQueryOut out; // [rsp+60h] [rbp-49h]
  hkpEntity **v65; // [rsp+110h] [rbp+67h]
  hkpConstraintInstance **v66; // [rsp+118h] [rbp+6Fh]
  int v67; // [rsp+120h] [rbp+77h]
  hkArray<hkpConstraintSchemaInfo,hkContainerHeapAllocator> *v68; // [rsp+128h] [rbp+7Fh]

  v68 = constraintStatus;
  v4 = s->m_constraintQueryInput;
  v5 = constraintStatus;
  v6 = constraints;
  v7 = s;
  v66 = &constraints[numConstraints];
  if ( constraints < v66 )
  {
    do
    {
      v8 = *v6;
      v9 = (*v6)->m_internal;
      v10 = v9->m_entities[0];
      v11 = v9->m_entities[1];
      v67 = (unsigned __int8)v7->m_priorityClassMap[(unsigned __int8)(*v6)->m_priority.m_storage];
      v12 = (hkpVelocityAccumulator *)((char *)v7->m_accumulators + v10->m_solverData);
      v13 = (hkpVelocityAccumulator *)((char *)v7->m_accumulators + v11->m_solverData);
      v14 = v9->m_entities;
      v4->m_bodyA.m_storage = v12;
      v4->m_bodyB.m_storage = v13;
      v15 = v7->m_accumulatorsBackup;
      v16 = *v14;
      v12->m_context.m_storage = 0;
      v13->m_context.m_storage = 0;
      v65 = v14;
      v17 = 3 * ((unsigned __int64)v16->m_solverData >> 7);
      v18 = v14[1]->m_solverData;
      v4->m_constraintInstance.m_storage = v8;
      v17 *= 2i64;
      v19.m_quad = *(__m128 *)((char *)&v15->m_coreTworldRotation.m_col0 + 8 * v17);
      v20.m_quad = *(__m128 *)((char *)&v15->m_coreTworldRotation.m_col1 + 8 * v17);
      v4->m_transformB.m_storage = &v11->m_motion.m_motionState.m_transform;
      v12->m_scratch0 = (hkVector4f)v19.m_quad;
      v21.m_quad = *(__m128 *)((char *)&v15->m_coreTworldRotation.m_col2 + 8 * v17);
      v12->m_scratch1 = (hkVector4f)v20.m_quad;
      v22.m_quad = (__m128)v15[v18 >> 7].m_coreTworldRotation.m_col0;
      v12->m_scratch2 = (hkVector4f)v21.m_quad;
      v23.m_quad = (__m128)v15[v18 >> 7].m_coreTworldRotation.m_col1;
      v13->m_scratch0 = (hkVector4f)v22.m_quad;
      v24.m_quad = (__m128)v15[v18 >> 7].m_coreTworldRotation.m_col2;
      v13->m_scratch1 = (hkVector4f)v23.m_quad;
      v4->m_transformA.m_storage = &v10->m_motion.m_motionState.m_transform;
      out.m_constraintRuntime.m_storage = v8->m_internal->m_runtime;
      v25 = *v14;
      v13->m_scratch2 = (hkVector4f)v24.m_quad;
      v4->m_accumulatorAIndex.m_storage = (unsigned __int16)(v25->m_solverData >> 7);
      v4->m_accumulatorBIndex.m_storage = (unsigned __int16)(v14[1]->m_solverData >> 7);
      LODWORD(v25) = v5->m_capacityAndFlags & 0x3FFFFFFF;
      out.m_constraintRuntimeInMainMemory.m_storage = (void *)v8->m_internal->m_runtime;
      if ( v5->m_size == (_DWORD)v25 )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 24);
        v14 = v65;
      }
      v26 = v5->m_size;
      v27 = v5->m_data;
      v28 = v26;
      v5->m_size = v26 + 1;
      v27[v28].m_constraint = v8;
      v29 = v67;
      v27[v28].m_schema = v7->m_schemas[v29].m_current;
      v27[v28].m_allowedPenetrationDepth = fminf(
                                             (*v14)->m_collidable.m_allowedPenetrationDepth,
                                             v14[1]->m_collidable.m_allowedPenetrationDepth);
      out.m_jacobianSchemas.m_storage = v7->m_schemas[v29].m_current;
      if ( ((unsigned int (__cdecl *)(hkpConstraintData *, hkpConstraintSchemaInfo *, signed __int64, hkpEntity *))v8->m_data->vfptr[1].__first_virtual_table_function__)(
             v8->m_data,
             v27,
             3 * v26,
             v11) == 11 )
        hkSimpleContactConstraintData_fireCallbacks(
          (hkpSimpleContactConstraintData *)v8->m_data,
          v4,
          (hkpSimpleContactConstraintAtom *)v8->m_data[2].m_userData,
          TYPE_MANIFOLD);
      if ( v8->m_internal->m_callbackRequest & 4 )
        ((void (__fastcall *)(hkpConstraintData *, hkpConstraintQueryIn *, hkpConstraintQueryOut *))v8->m_data->vfptr[11].__vecDelDtor)(
          v8->m_data,
          v4,
          &out);
      v30 = v8->m_internal;
      v31 = (hkpSimpleContactConstraintAtom *)v30->m_atoms;
      if ( v31->m_type.m_storage == 29 )
        hkSimpleContactConstraintDataBuildJacobian(v31, v4, (hkBool)1, &out);
      else
        hkSolverBuildJacobianFromAtomsNotContact((hkpConstraintAtom *)&v31->m_type, v30->m_atomsSize, v4, &out);
      v32 = out.m_jacobianSchemas.m_storage;
      v12->m_context.m_storage = 1;
      v33 = v12->m_scratch0.m_quad.m128_f32[0];
      v34 = v12->m_scratch1.m_quad.m128_f32[1];
      v35 = v12->m_scratch2.m_quad.m128_f32[2];
      v7->m_schemas[v29].m_current = v32;
      v36 = (float)(v33 + v34) + v35;
      v7->m_elemTempCurrent += v8->m_internal->m_numSolverElemTemps;
      if ( v36 <= 0.0 )
      {
        v58 = 1;
        v59 = 2i64;
        v41 = 0i64;
        if ( v34 > v33 )
          v41 = 1i64;
        if ( v35 > v12->m_scratch0.m_quad.m128_f32[5 * v41] )
          v41 = 2i64;
        v42 = *(&v58 + v41);
        v43 = *(&v58 + v42);
        v44 = fsqrt(
                (float)(v12->m_scratch0.m_quad.m128_f32[5 * v41]
                      - (float)(v12->m_scratch0.m_quad.m128_f32[5 * v43] + v12->m_scratch0.m_quad.m128_f32[5 * v42]))
              + 1.0);
        *((float *)&v62 + v41) = v44 * 0.5;
        *((float *)&v62 + 3) = (float)(v12->m_scratch0.m_quad.m128_f32[v43 + 4 * v42]
                                     - v12->m_scratch0.m_quad.m128_f32[v42 + 4 * v43])
                             * (float)(0.5 / v44);
        *((float *)&v62 + v42) = (float)(v12->m_scratch0.m_quad.m128_f32[v42 + 4 * v41]
                                       + v12->m_scratch0.m_quad.m128_f32[v41 + 4 * v42])
                               * (float)(0.5 / v44);
        *((float *)&v62 + v43) = (float)(v12->m_scratch0.m_quad.m128_f32[v43 + 4 * v41]
                                       + v12->m_scratch0.m_quad.m128_f32[v41 + 4 * v43])
                               * (float)(0.5 / v44);
      }
      else
      {
        v37 = v12->m_scratch2.m_quad.m128_f32[0] - v12->m_scratch0.m_quad.m128_f32[2];
        v38 = fsqrt(v36 + 1.0);
        v39 = v12->m_scratch1.m_quad.m128_f32[2] - v12->m_scratch2.m_quad.m128_f32[1];
        *((float *)&v62 + 3) = v38 * 0.5;
        *(float *)&v62 = v39 * (float)(0.5 / v38);
        v40 = v12->m_scratch0.m_quad.m128_f32[1];
        *((float *)&v62 + 1) = v37 * (float)(0.5 / v38);
        *((float *)&v62 + 2) = (float)(v40 - v12->m_scratch1.m_quad.m128_f32[0]) * (float)(0.5 / v38);
      }
      v45 = v62;
      v13->m_context.m_storage = 1;
      v46 = v13->m_scratch0.m_quad.m128_f32[0];
      v47 = v13->m_scratch1.m_quad.m128_f32[1];
      v48 = v13->m_scratch2.m_quad.m128_f32[2];
      v12->m_scratch2 = (hkVector4f)v45;
      v12->m_scratch0 = 0i64;
      v12->m_scratch1 = 0i64;
      v49 = (float)(v46 + v47) + v48;
      if ( v49 <= 0.0 )
      {
        v60 = 1;
        v61 = 2i64;
        v54 = 0i64;
        if ( v47 > v46 )
          v54 = 1i64;
        if ( v48 > v13->m_scratch0.m_quad.m128_f32[5 * v54] )
          v54 = 2i64;
        v55 = *(&v60 + v54);
        v56 = *(&v60 + v55);
        v57 = fsqrt(
                (float)(v13->m_scratch0.m_quad.m128_f32[5 * v54]
                      - (float)(v13->m_scratch0.m_quad.m128_f32[5 * v56] + v13->m_scratch0.m_quad.m128_f32[5 * v55]))
              + 1.0);
        v63.m_quad.m128_f32[v54] = v57 * 0.5;
        v63.m_quad.m128_f32[3] = (float)(v13->m_scratch0.m_quad.m128_f32[v56 + 4 * v55]
                                       - v13->m_scratch0.m_quad.m128_f32[v55 + 4 * v56])
                               * (float)(0.5 / v57);
        v63.m_quad.m128_f32[v55] = (float)(v13->m_scratch0.m_quad.m128_f32[v54 + 4 * v55]
                                         + v13->m_scratch0.m_quad.m128_f32[v55 + 4 * v54])
                                 * (float)(0.5 / v57);
        v63.m_quad.m128_f32[v56] = (float)(v13->m_scratch0.m_quad.m128_f32[v54 + 4 * v56]
                                         + v13->m_scratch0.m_quad.m128_f32[v56 + 4 * v54])
                                 * (float)(0.5 / v57);
      }
      else
      {
        v50 = v13->m_scratch2.m_quad.m128_f32[0] - v13->m_scratch0.m_quad.m128_f32[2];
        v51 = fsqrt(v49 + 1.0);
        v52 = v13->m_scratch1.m_quad.m128_f32[2] - v13->m_scratch2.m_quad.m128_f32[1];
        v63.m_quad.m128_f32[3] = v51 * 0.5;
        v63.m_quad.m128_f32[0] = v52 * (float)(0.5 / v51);
        v53 = v13->m_scratch0.m_quad.m128_f32[1];
        v63.m_quad.m128_f32[1] = v50 * (float)(0.5 / v51);
        v63.m_quad.m128_f32[2] = (float)(v53 - v13->m_scratch1.m_quad.m128_f32[0]) * (float)(0.5 / v51);
      }
      v5 = v68;
      ++v6;
      v13->m_scratch2 = (hkVector4f)v63.m_quad;
      v13->m_scratch0 = 0i64;
      v13->m_scratch1 = 0i64;
    }
    while ( v6 < v66 );
  }
  *(_DWORD *)v7->m_schemas[0].m_current = 0;
  *(_DWORD *)v7->m_schemas[1].m_current = 0;
  *(_DWORD *)v7->m_schemas[2].m_current = 0;
}

// File Line: 855
// RVA: 0xD92580
hkBool *__fastcall hkpConstraintSolverSetup::internalIsMemoryOkForNewAccumulators(hkBool *result, hkpConstraintSolverResources *s, hkpEntity **entities, int numEntities)
{
  hkBool *v4; // rax

  if ( s->m_accumulatorsCurrent == s->m_accumulators )
    ++numEntities;
  v4 = result;
  result->m_bool = numEntities << 7 <= LODWORD(s->m_accumulatorsEnd) - LODWORD(s->m_accumulatorsCurrent) - 16;
  return v4;
}

// File Line: 874
// RVA: 0xD925C0
hkBool *__fastcall hkpConstraintSolverSetup::internalIsMemoryOkForNewJacobianSchemas(hkBool *result, hkpConstraintSolverResources *s, hkpConstraintInstance **constraints, int numConstraints)
{
  hkpSolverElemTemp *v4; // rdi
  hkpConstraintInstance **v5; // r11
  hkpConstraintSolverResources *v6; // rbx
  hkBool *v7; // r10
  hkpConstraintInstance **v8; // r9
  hkpConstraintInstance *v9; // rcx
  hkConstraintInternal *v10; // r8
  hkpJacobianSchema **v11; // rdx
  signed __int64 v12; // rax
  bool v13; // cl
  hkpJacobianSchema *v15; // [rsp+0h] [rbp-28h]
  hkpJacobianSchema *v16; // [rsp+8h] [rbp-20h]
  hkpJacobianSchema *v17; // [rsp+10h] [rbp-18h]

  v4 = s->m_elemTempCurrent;
  v5 = constraints;
  v15 = s->m_schemas[0].m_current;
  v6 = s;
  v16 = s->m_schemas[1].m_current;
  v7 = result;
  v17 = s->m_schemas[2].m_current;
  v8 = &constraints[numConstraints];
  if ( constraints < v8 )
  {
    do
    {
      v9 = *v5;
      ++v5;
      v10 = v9->m_internal;
      v4 += v10->m_numSolverElemTemps;
      (&v15)[(unsigned __int8)s->m_priorityClassMap[(unsigned __int8)v9->m_priority.m_storage]] += v10->m_sizeOfSchemas;
    }
    while ( v5 < v8 );
  }
  v11 = &s->m_schemas[0].m_end;
  v7->m_bool = v4 <= v6->m_elemTempEnd;
  v12 = 0i64;
  do
  {
    v13 = v7->m_bool && &(&v15)[v12++][4] <= *v11;
    v11 += 4;
    v7->m_bool = v13;
  }
  while ( v12 < 3 );
  return v7;
}

// File Line: 915
// RVA: 0xD92340
void __fastcall hkpConstraintSolverSetup::subSolve(hkpConstraintSolverResources *s, hkpConstraintSolverSetup::SolverMode mode)
{
  hkpConstraintSolverResources *v2; // rbx
  hkpSolverElemTemp *v3; // rdi
  __int64 i; // rcx
  hkpJacobianSchema **v5; // rdi
  signed __int64 v6; // rsi
  hkpJacobianSchema *v7; // rax

  v2 = s;
  if ( mode == SOLVER_MODE_PROCESS_ALL )
  {
    s->m_schemas[0].m_lastProcessed = s->m_schemas[0].m_begin;
    s->m_schemas[1].m_lastProcessed = s->m_schemas[1].m_begin;
    s->m_schemas[2].m_lastProcessed = s->m_schemas[2].m_begin;
  }
  if ( ((LODWORD(s->m_elemTempCurrent) - LODWORD(s->m_elemTempLastProcessed)) >> 2) - 1 >= 0 )
  {
    v3 = s->m_elemTempLastProcessed;
    for ( i = (unsigned int)((LODWORD(s->m_elemTempCurrent) - LODWORD(s->m_elemTempLastProcessed)) >> 2); i; --i )
    {
      v3->m_impulseApplied = 0.0;
      ++v3;
    }
  }
  v5 = &v2->m_schemas[0].m_lastProcessed;
  v6 = 3i64;
  v2->m_elemTempLastProcessed = v2->m_elemTempCurrent;
  do
  {
    if ( *v5 != *(v5 - 1) )
      hkSolveStepJacobians(v2->m_solverInfo, *v5, v2->m_accumulators, v2->m_elemTemp);
    v7 = *(v5 - 1);
    v5 += 4;
    *(v5 - 4) = v7;
    --v6;
  }
  while ( v6 );
}


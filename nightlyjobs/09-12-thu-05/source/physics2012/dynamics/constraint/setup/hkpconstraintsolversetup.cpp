// File Line: 43
// RVA: 0xD915F0
__int64 __fastcall hkpConstraintSolverSetup::calcBufferOffsetsForSolve(
        hkpSimulationIsland *island,
        hkpVelocityAccumulator *buffer,
        int bufferSize,
        hkpBuildJacobianTaskHeader *taskHeader)
{
  __int64 m_size; // r11
  hkpJacobianSchema *p_m_linearVel; // r10
  int v6; // edx
  int v7; // edx
  hkpSolverElemTemp *v8; // r10
  int v9; // eax
  unsigned int v10; // r10d
  bool v11; // zf
  hkpVelocityAccumulator *m_accumulatorsBase; // rcx

  taskHeader->m_buffer = buffer;
  m_size = island->m_entities.m_size;
  taskHeader->m_accumulatorsBase = buffer;
  p_m_linearVel = (hkpJacobianSchema *)&buffer[island->m_entities.m_size + 1].m_linearVel;
  v6 = (unsigned __int64)(1717986919i64 * island->m_numConstraints) >> 32;
  taskHeader->m_schemasBase = p_m_linearVel;
  v7 = 2 * (((unsigned int)v6 >> 31) + (v6 >> 5)) + 8;
  v8 = (hkpSolverElemTemp *)&p_m_linearVel[32 * v7 + 32 + island->m_constraintInfo.m_sizeOfSchemas];
  v9 = island->m_constraintInfo.m_numSolverElemTemps + 3 * v7;
  taskHeader->m_solverTempBase = v8;
  v10 = ((4 * v9 + 23) & 0xFFFFFFF0) + (_DWORD)v8 - LODWORD(taskHeader->m_buffer);
  v11 = taskHeader->m_buffer == 0i64;
  taskHeader->m_bufferSize = v10;
  if ( !v11 )
  {
    m_accumulatorsBase = taskHeader->m_accumulatorsBase;
    *(_WORD *)&m_accumulatorsBase->m_type.m_storage = 1;
    m_accumulatorsBase->m_gravityFactor = 0.0;
    m_accumulatorsBase->m_invMasses = 0i64;
    m_accumulatorsBase->m_linearVel = 0i64;
    m_accumulatorsBase->m_angularVel = 0i64;
    m_accumulatorsBase->m_scratch3 = 0i64;
    m_accumulatorsBase->m_scratch0 = (hkVector4f)transform.m_quad;
    m_accumulatorsBase->m_scratch1 = (hkVector4f)direction.m_quad;
    m_accumulatorsBase->m_scratch2 = (hkVector4f)stru_141A71280.m_quad;
    m_accumulatorsBase[m_size + 1].m_type.m_storage = 3;
  }
  return v10;
}

// File Line: 114
// RVA: 0xD91540
int __fastcall hkpConstraintSolverSetup::calcBufferSize(hkpSimulationIsland *island)
{
  int result; // eax
  int v2; // ebx
  hkpBuildJacobianTaskHeader taskHeader; // [rsp+20h] [rbp-D8h] BYREF

  taskHeader.m_referenceCount = 1;
  taskHeader.m_numIslandsAfterSplit = 1;
  taskHeader.m_buffer = 0i64;
  *(_QWORD *)&taskHeader.m_bufferSize = 0i64;
  taskHeader.m_newSplitIslands.m_data = 0i64;
  taskHeader.m_newSplitIslands.m_size = 0;
  taskHeader.m_newSplitIslands.m_capacityAndFlags = 0x80000000;
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
      &hkContainerHeapAllocator::s_alloc,
      taskHeader.m_newSplitIslands.m_data,
      8 * taskHeader.m_newSplitIslands.m_capacityAndFlags);
    return v2;
  }
  return result;
}

// File Line: 120
// RVA: 0xD926A0
__int64 __fastcall hkpConstraintSolverSetup_calcBufferSize(hkpSimulationIsland *island)
{
  __int64 result; // rax
  unsigned int v2; // ebx
  hkpBuildJacobianTaskHeader taskHeader; // [rsp+20h] [rbp-D8h] BYREF

  taskHeader.m_referenceCount = 1;
  taskHeader.m_numIslandsAfterSplit = 1;
  taskHeader.m_buffer = 0i64;
  *(_QWORD *)&taskHeader.m_bufferSize = 0i64;
  taskHeader.m_newSplitIslands.m_data = 0i64;
  taskHeader.m_newSplitIslands.m_size = 0;
  taskHeader.m_newSplitIslands.m_capacityAndFlags = 0x80000000;
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
      &hkContainerHeapAllocator::s_alloc,
      taskHeader.m_newSplitIslands.m_data,
      8 * taskHeader.m_newSplitIslands.m_capacityAndFlags);
    return v2;
  }
  return result;
}

// File Line: 310
// RVA: 0xD92770
__int64 __fastcall hkConstraintSolverSetup_integrate2(
        hkpSolverInfo *si,
        hkStepInfo *info,
        hkpVelocityAccumulator *accumulators,
        hkpMotion *const *bodies,
        unsigned int numBodies)
{
  unsigned int v6; // ebx

  v6 = hkRigidMotionUtilApplyAccumulators(si, info, accumulators + 1, bodies, numBodies, 336);
  hkpEntityAabbUtil::entityBatchRecalcAabb(
    *(hkpCollisionInput **)(*(_QWORD *)&(*bodies)->m_type.m_storage + 184i64),
    (hkpEntity *const *)bodies,
    numBodies);
  return v6;
}

// File Line: 326
// RVA: 0xD92400
void __fastcall hkpConstraintSolverSetup::oneStepIntegrate(
        hkpSolverInfo *si,
        hkStepInfo *info,
        hkpVelocityAccumulator *accumulatorsBase,
        hkpEntity *const *entities,
        int numEntities)
{
  __int64 i; // rdi
  char *v10; // rcx
  hkVector4f v11; // xmm0
  char m_deactivationIntegrateCounter; // bl
  hkpMotion *motions; // [rsp+30h] [rbp-B8h] BYREF
  hkpEntity *entityBatch; // [rsp+38h] [rbp-B0h] BYREF
  hkpVelocityAccumulator accumulators; // [rsp+40h] [rbp-A8h] BYREF

  for ( i = 0i64; i < numEntities; motions->m_deactivationIntegrateCounter = m_deactivationIntegrateCounter )
  {
    entityBatch = entities[i];
    motions = &entityBatch->m_motion;
    v10 = &accumulatorsBase->m_type.m_storage + entityBatch->m_solverData;
    accumulators.m_type.m_storage = *v10;
    accumulators.m_context.m_storage = v10[1];
    accumulators.m_deactivationClass = *((_DWORD *)v10 + 1);
    accumulators.m_gravityFactor = *((float *)v10 + 2);
    accumulators.m_linearVel = (hkVector4f)*((_OWORD *)v10 + 1);
    accumulators.m_angularVel = (hkVector4f)*((_OWORD *)v10 + 2);
    accumulators.m_invMasses = (hkVector4f)*((_OWORD *)v10 + 3);
    accumulators.m_scratch0 = (hkVector4f)*((_OWORD *)v10 + 4);
    accumulators.m_scratch1 = (hkVector4f)*((_OWORD *)v10 + 5);
    accumulators.m_scratch2 = (hkVector4f)*((_OWORD *)v10 + 6);
    v11.m_quad = (__m128)*((_OWORD *)v10 + 7);
    accumulators.m_scratch0 = accumulators.m_linearVel;
    accumulators.m_scratch3 = (hkVector4f)v11.m_quad;
    accumulators.m_scratch1 = accumulators.m_angularVel;
    m_deactivationIntegrateCounter = entityBatch->m_motion.m_deactivationIntegrateCounter;
    entityBatch->m_motion.m_deactivationIntegrateCounter = -1;
    hkRigidMotionUtilApplyAccumulators(si, info, &accumulators, &motions, 1, 0);
    hkpEntityAabbUtil::entityBatchRecalcAabb(entityBatch->m_world->m_collisionInput, &entityBatch, 1i64);
    ++i;
  }
}

// File Line: 357
// RVA: 0xD90BE0
__int64 __fastcall hkpConstraintSolverSetup::solve(
        hkStepInfo *stepInfo,
        hkpSolverInfo *solverInfo,
        hkpConstraintQueryIn *constraintQueryIn,
        hkpSimulationIsland *island)
{
  __int64 v4; // r13
  hkpJacobianSchema *v5; // rax
  int v6; // r14d
  signed int v7; // r15d
  int v8; // edi
  char *m_cur; // rsi
  _QWORD **Value; // rax
  hkpJacobianSchema *v11; // rbx
  struct hkpConstraintRuntime *m_storage; // rcx
  hkpJacobianSchema *v13; // rdx
  __int64 v14; // rdi
  hkpJacobianSchema *v15; // rcx
  char *v16; // rax
  unsigned __int64 v17; // r12
  char *v18; // r14
  char *v19; // rax
  int v20; // r14d
  int v21; // eax
  int v22; // edi
  int v23; // r15d
  int v24; // r12d
  _QWORD **v25; // rax
  __int64 v26; // rax
  bool v27; // sf
  hkpJacobianSchema *v28; // r12
  __int64 v29; // rax
  hkLifoAllocator *v30; // rax
  int v31; // edx
  char *v32; // rcx
  int v33; // r13d
  _QWORD **v34; // rax
  __int64 v35; // rbx
  hkpVelocityAccumulator *v36; // r8
  hkpConstraintQueryIn *v37; // r13
  hkpMotion **v38; // rbx
  hkpMotion **v39; // rcx
  int v40; // eax
  __int64 v41; // rdi
  __int64 v42; // rcx
  char *v43; // rdi
  hkpJacobianSchema *v44; // r15
  hkpJacobianSchema *v45; // rdx
  unsigned __int64 v46; // rcx
  hkpJacobianSchema *v47; // rdi
  __int64 v48; // r9
  hkpJacobianSchema *v49; // r14
  hkpVelocityAccumulator *v50; // rsi
  struct hkpConstraintRuntime **v51; // rbx
  struct hkpConstraintRuntime **v52; // r15
  __int64 v53; // rcx
  __int64 v54; // rdx
  float v55; // xmm0_4
  const char *v56; // rax
  unsigned __int16 v57; // cx
  struct hkpConstraintRuntime *v58; // rdx
  struct hkpConstraintRuntime *v59; // rdi
  struct hkpConstraintRuntime *v60; // rcx
  unsigned int v61; // eax
  hkpSimpleContactConstraintAtom *v62; // rcx
  int v63; // r14d
  hkpJacobianSchema *v64; // rsi
  hkpVelocityAccumulator *v65; // r15
  __int64 v66; // rbx
  hkpVelocityAccumulator *v67; // r8
  float v68; // xmm0_4
  const char *v69; // rax
  __int16 v70; // cx
  __int64 v71; // rdx
  unsigned __int64 v72; // rdi
  struct hkpConstraintRuntime *v73; // rcx
  unsigned int v74; // eax
  hkpSimpleContactConstraintAtom *v75; // rcx
  unsigned int v76; // r12d
  hkpSolverElemTemp *v77; // r13
  hkpVelocityAccumulator *v78; // r14
  bool v79; // di
  _QWORD *v80; // rax
  __int64 v81; // rbx
  _QWORD *v82; // rcx
  unsigned __int64 v83; // rax
  unsigned __int64 v84; // rax
  _QWORD *v85; // rcx
  unsigned __int64 v86; // rax
  unsigned __int64 v87; // rax
  hkpMotion **v88; // r14
  int v89; // edi
  _QWORD **v90; // rax
  hkpJacobianSchema *v91; // rbx
  __int64 v92; // rcx
  int v94; // [rsp+30h] [rbp-90h]
  signed int v95; // [rsp+34h] [rbp-8Ch]
  char *v96; // [rsp+38h] [rbp-88h]
  hkpJacobianSchema *schemas; // [rsp+40h] [rbp-80h]
  hkpJacobianSchema *schemasa; // [rsp+40h] [rbp-80h]
  hkpConstraintQueryOut out; // [rsp+48h] [rbp-78h] BYREF
  hkpVelocityAccumulator **array; // [rsp+60h] [rbp-60h] BYREF
  __int64 v101; // [rsp+68h] [rbp-58h]
  hkpVelocityAccumulator *accumulators; // [rsp+70h] [rbp-50h] BYREF
  hkpJacobianSchema *v103; // [rsp+78h] [rbp-48h]
  hkStepInfo *info; // [rsp+8D0h] [rbp+810h]
  hkpSolverInfo *i; // [rsp+8D8h] [rbp+818h]
  hkpConstraintQueryIn *in; // [rsp+8E0h] [rbp+820h]
  __int64 v107; // [rsp+8E8h] [rbp+828h]
  hkpJacobianSchema *v108; // [rsp+8F0h] [rbp+830h] BYREF
  int v109; // [rsp+8F8h] [rbp+838h]
  hkpMotion **motions; // [rsp+900h] [rbp+840h]
  void *retaddr; // [rsp+908h] [rbp+848h]

  v4 = v107;
  v5 = v108;
  v6 = *(_DWORD *)(v107 + 20) + 32;
  v7 = (4 * *(_DWORD *)(v107 + 28) + 23) & 0xFFFFFFF0;
  v8 = ((_DWORD)retaddr << 7) + 144;
  m_cur = 0i64;
  v94 = 0;
  v103 = 0i64;
  v95 = v7;
  LODWORD(array) = v8 + v7 + v6;
  if ( v108 )
  {
    out.m_jacobianSchemas.m_storage = 0i64;
    v11 = &v108[v109];
  }
  else
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    LODWORD(v108) = v8 + v7 + v6;
    v5 = (hkpJacobianSchema *)(*(__int64 (__fastcall **)(_QWORD *, hkpJacobianSchema **))(*Value[13] + 24i64))(
                                Value[13],
                                &v108);
    v11 = &v5[(int)v108];
    out.m_jacobianSchemas.m_storage = v5;
    LODWORD(array) = (_DWORD)v108;
  }
  m_storage = (struct hkpConstraintRuntime *)v8;
  v13 = (hkpJacobianSchema *)v6;
  v14 = v7;
  v101 = v7;
  out.m_constraintRuntime.m_storage = m_storage;
$redoAll:
  accumulators = (hkpVelocityAccumulator *)v5;
  v15 = &v5[(_QWORD)m_storage];
  schemas = v15;
  v16 = (char *)&v15[(_QWORD)v13];
LABEL_6:
  v17 = (unsigned __int64)v16;
  while ( 1 )
  {
    v18 = v16;
    out.m_constraintRuntimeInMainMemory.m_storage = v16;
    v19 = &v16[v14];
    if ( v19 <= (char *)v11 )
      break;
    if ( v15 >= v11 )
    {
      v33 = (_DWORD)v19 - LODWORD(out.m_jacobianSchemas.m_storage);
      v94 = (_DWORD)v19 - LODWORD(out.m_jacobianSchemas.m_storage);
      v34 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v5 = (hkpJacobianSchema *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v34[10] + 8i64))(
                                  v34[10],
                                  (unsigned int)v33);
      m_storage = out.m_constraintRuntime.m_storage;
      v13 = schemas;
      v35 = v33;
      v4 = v107;
      m_cur = (char *)v5;
      v11 = &v5[v35];
      goto $redoAll;
    }
    v20 = *(_DWORD *)(v4 + 16) + 16;
    if ( v17 < (unsigned __int64)v11 )
    {
      v30 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (char *)v30->m_cur;
      v31 = (v7 + 127) & 0xFFFFFF80;
      v32 = &m_cur[v31];
      if ( v31 > v30->m_slabSize || v32 > v30->m_end )
      {
        v16 = (char *)hkLifoAllocator::allocateFromNewSlab(v30, v31);
        v15 = schemas;
        v11 = (hkpJacobianSchema *)&v16[v14];
        m_cur = v16;
      }
      else
      {
        v30->m_cur = v32;
        v15 = schemas;
        v11 = (hkpJacobianSchema *)&m_cur[v14];
        v16 = m_cur;
      }
    }
    else
    {
      v21 = 0;
      v22 = (_DWORD)v11 - (_DWORD)v15 - v20;
      if ( v22 > 0 )
        v21 = (_DWORD)v11 - (_DWORD)v15 - v20;
      v23 = v20 + *(_DWORD *)(v4 + 20) - v21;
      v24 = v23 + v95;
      v94 = v23 + v95;
      v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v26 = (*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v25[10] + 8i64))(v25[10], (unsigned int)(v23 + v95));
      v27 = v22 < 0;
      v14 = v101;
      m_cur = (char *)v26;
      if ( v27 )
      {
        v7 = v95;
        v15 = (hkpJacobianSchema *)v26;
        schemas = (hkpJacobianSchema *)v26;
        v11 = (hkpJacobianSchema *)(v26 + v24);
        v16 = (char *)(v26 + *(_DWORD *)(v4 + 20) + 32);
        v103 = 0i64;
        goto LABEL_6;
      }
      v15 = schemas;
      v28 = v11;
      v11 = (hkpJacobianSchema *)(v26 + v94);
      v103 = (hkpJacobianSchema *)v26;
      v17 = (unsigned __int64)&v28[-v20];
      v29 = v23;
      v7 = v95;
      v16 = &m_cur[v29];
    }
  }
  v36 = accumulators;
  v37 = in;
  v38 = motions;
  *(_WORD *)&accumulators->m_type.m_storage = 1;
  v36->m_gravityFactor = 0.0;
  v36->m_invMasses = 0i64;
  v36->m_linearVel = 0i64;
  v36->m_angularVel = 0i64;
  v36->m_scratch3 = 0i64;
  v96 = m_cur;
  v36->m_scratch0 = (hkVector4f)transform.m_quad;
  v36->m_scratch1 = (hkVector4f)direction.m_quad;
  v36->m_scratch2 = (hkVector4f)stru_141A71280.m_quad;
  if ( (int)retaddr > 0 )
  {
    v39 = v38;
    v40 = 128;
    v41 = (unsigned int)retaddr;
    do
    {
      if ( v40 != (*v39)->m_angularVelocity.m_quad.m128_i32[0] )
        (*v39)->m_angularVelocity.m_quad.m128_i32[0] = v40;
      v40 += 128;
      ++v39;
      --v41;
    }
    while ( v41 );
  }
  out.m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)&v36[1];
  hkRigidMotionUtilApplyForcesAndBuildAccumulators(info, v38, (int)retaddr, 336, v36 + 1)->m_type.m_storage = 3;
  if ( *(_DWORD *)(v107 + 28) - 1 >= 0 )
  {
    v42 = *(unsigned int *)(v107 + 28);
    v43 = v18;
    while ( v42 )
    {
      *(_DWORD *)v43 = 0;
      v43 += 4;
      --v42;
    }
  }
  v44 = schemas;
  v45 = (hkpJacobianSchema *)&v38[(int)retaddr];
  v46 = (unsigned __int64)v38;
  array = &accumulators;
  v47 = schemas;
  out.m_jacobianSchemas.m_storage = schemas;
  schemasa = v45;
  v101 = 0x8000010000000000ui64;
  v48 = 256i64;
  if ( v38 < (hkpMotion **)v45 )
  {
    v49 = v103;
    v50 = accumulators;
    do
    {
      v51 = *(struct hkpConstraintRuntime ***)(*(_QWORD *)v46 + 248i64);
      v52 = &v51[8 * (unsigned __int64)*(unsigned __int16 *)(*(_QWORD *)v46 + 256i64)];
      if ( v51 < v52 )
      {
        do
        {
          if ( (*((_BYTE *)v51 + 34) & 0xD) != 0 )
          {
            v37->m_constraintInstance.m_storage = (hkpConstraintInstance *)*v51;
            out.m_constraintRuntime.m_storage = v51[6];
            v53 = *((_QWORD *)*v51 + 5);
            v54 = *((_QWORD *)*v51 + 6);
            v37->m_bodyA.m_storage = (hkpVelocityAccumulator *)((char *)v50 + *(unsigned int *)(v53 + 240));
            v37->m_bodyB.m_storage = (hkpVelocityAccumulator *)((char *)v50 + *(unsigned int *)(v54 + 240));
            v37->m_transformA.m_storage = *(hkTransformf **)(v53 + 48);
            v37->m_transformB.m_storage = *(hkTransformf **)(v54 + 48);
            if ( (*((_BYTE *)v51 + 34) & 9) != 0 )
            {
              hkSimpleContactConstraintData_fireCallbacks(
                *((hkpSimpleContactConstraintData **)*v51 + 3),
                v37,
                *(hkpSimpleContactConstraintAtom **)(*((_QWORD *)*v51 + 3) + 64i64),
                (hkpContactPointEvent::Type)2);
              v47 = out.m_jacobianSchemas.m_storage;
            }
            if ( (*((_BYTE *)v51 + 34) & 4) != 0 )
            {
              (*(void (__fastcall **)(_QWORD, hkpConstraintQueryIn *, hkpConstraintQueryOut *, __int64))(**((_QWORD **)*v51 + 3) + 176i64))(
                *((_QWORD *)*v51 + 3),
                v37,
                &out,
                v48);
              v47 = out.m_jacobianSchemas.m_storage;
            }
          }
          if ( *((_BYTE *)v51 + 35) < 4u )
          {
            if ( (unsigned __int64)v47 >= v17 )
            {
              v55 = *(float *)v47 + 0.00000011920929;
              v17 = -1i64;
              *(_QWORD *)&v47[8] = v49 - v47;
              *(float *)v47 = v55;
              *v47 = (hkpJacobianSchema)2;
              out.m_jacobianSchemas.m_storage = v49;
            }
            v56 = (const char *)v51[3];
            _mm_prefetch(v56, 0);
            _mm_prefetch(v56 + 64, 0);
            _mm_prefetch(v56 + 128, 0);
            _mm_prefetch(v56 + 192, 0);
            v57 = *((_WORD *)v51 + 16);
            if ( v57 > 0x100u )
            {
              _mm_prefetch(v56 + 256, 0);
              _mm_prefetch(v56 + 320, 0);
              _mm_prefetch(v56 + 384, 0);
              _mm_prefetch(v56 + 448, 0);
              if ( v57 > 0x200u )
              {
                _mm_prefetch(v56 + 512, 0);
                _mm_prefetch(v56 + 576, 0);
                _mm_prefetch(v56 + 640, 0);
                _mm_prefetch(v56 + 704, 0);
              }
            }
            v58 = v51[1];
            v59 = v51[2];
            v37->m_bodyA.m_storage = (hkpVelocityAccumulator *)((char *)v50 + *((unsigned int *)v58 + 60));
            v37->m_bodyB.m_storage = (hkpVelocityAccumulator *)((char *)v50 + *((unsigned int *)v59 + 60));
            v37->m_transformA.m_storage = (hkTransformf *)((char *)v58 + 368);
            v37->m_transformB.m_storage = (hkTransformf *)((char *)v59 + 368);
            v37->m_constraintInstance.m_storage = (hkpConstraintInstance *)*v51;
            out.m_constraintRuntime.m_storage = v51[6];
            v60 = out.m_constraintRuntime.m_storage;
            v37->m_accumulatorAIndex.m_storage = (unsigned __int16)(*((_DWORD *)v58 + 60) >> 7);
            v61 = *((_DWORD *)v59 + 60);
            out.m_constraintRuntimeInMainMemory.m_storage = v60;
            v37->m_accumulatorBIndex.m_storage = (unsigned __int16)(v61 >> 7);
            v62 = (hkpSimpleContactConstraintAtom *)v51[3];
            if ( v62->m_type.m_storage == 29 )
              hkSimpleContactConstraintDataBuildJacobian(v62, v37, (hkBool)1, &out);
            else
              hkSolverBuildJacobianFromAtomsNotContact(v62, *((unsigned __int16 *)v51 + 16), v37, &out);
          }
          else
          {
            if ( (_DWORD)v101 == (HIDWORD(v101) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
            array[(int)v101] = (hkpVelocityAccumulator *)v51;
            LODWORD(v101) = v101 + 1;
          }
          v47 = out.m_jacobianSchemas.m_storage;
          v51 += 8;
        }
        while ( v51 < v52 );
        v46 = v101;
        v45 = schemasa;
      }
      v46 += 8i64;
      v101 = v46;
    }
    while ( v46 < (unsigned __int64)v45 );
    m_cur = v96;
    v44 = schemasa;
    v48 = 256i64;
  }
  v63 = 0;
  if ( (int)v101 > 0 )
  {
    v64 = v103;
    v65 = accumulators;
    v66 = 0i64;
    do
    {
      v67 = array[v66];
      if ( (unsigned __int64)v47 >= v17 )
      {
        v68 = *(float *)v47 + 0.00000011920929;
        v17 = -1i64;
        *(_QWORD *)&v47[8] = v64 - v47;
        *(float *)v47 = v68;
        *v47 = (hkpJacobianSchema)2;
        out.m_jacobianSchemas.m_storage = v64;
      }
      v69 = (const char *)v67->m_linearVel.m_quad.m128_u64[1];
      _mm_prefetch(v69, 0);
      _mm_prefetch(v69 + 64, 0);
      _mm_prefetch(v69 + 128, 0);
      _mm_prefetch(v69 + 192, 0);
      v70 = v67->m_angularVel.m_quad.m128_i16[0];
      if ( (unsigned __int16)v70 > 0x100u )
      {
        _mm_prefetch(v69 + 256, 0);
        _mm_prefetch(v69 + 320, 0);
        _mm_prefetch(v69 + 384, 0);
        _mm_prefetch(v69 + 448, 0);
        if ( (unsigned __int16)v70 > 0x200u )
        {
          _mm_prefetch(v69 + 512, 0);
          _mm_prefetch(v69 + 576, 0);
          _mm_prefetch(v69 + 640, 0);
          _mm_prefetch(v69 + 704, 0);
        }
      }
      v71 = *(_QWORD *)&v67->m_gravityFactor;
      v72 = v67->m_linearVel.m_quad.m128_u64[0];
      v37->m_bodyA.m_storage = (hkpVelocityAccumulator *)((char *)v65 + *(unsigned int *)(v71 + 240));
      v37->m_bodyB.m_storage = (hkpVelocityAccumulator *)((char *)v65 + *(unsigned int *)(v72 + 240));
      v37->m_transformA.m_storage = (hkTransformf *)(v71 + 368);
      v37->m_transformB.m_storage = (hkTransformf *)(v72 + 368);
      v37->m_constraintInstance.m_storage = *(hkpConstraintInstance **)&v67->m_type.m_storage;
      out.m_constraintRuntime.m_storage = (struct hkpConstraintRuntime *)v67->m_invMasses.m_quad.m128_u64[0];
      v73 = out.m_constraintRuntime.m_storage;
      v37->m_accumulatorAIndex.m_storage = (unsigned __int16)(*(_DWORD *)(v71 + 240) >> 7);
      v74 = *(_DWORD *)(v72 + 240);
      out.m_constraintRuntimeInMainMemory.m_storage = v73;
      v37->m_accumulatorBIndex.m_storage = (unsigned __int16)(v74 >> 7);
      v75 = (hkpSimpleContactConstraintAtom *)v67->m_linearVel.m_quad.m128_u64[1];
      if ( v75->m_type.m_storage == 29 )
        hkSimpleContactConstraintDataBuildJacobian(v75, v37, (hkBool)1, &out);
      else
        hkSolverBuildJacobianFromAtomsNotContact(v75, v67->m_angularVel.m_quad.m128_u16[0], v37, &out);
      v47 = out.m_jacobianSchemas.m_storage;
      ++v63;
      ++v66;
    }
    while ( v63 < (int)v101 );
    m_cur = v96;
    v44 = schemasa;
  }
  v76 = 0;
  *(_DWORD *)v47 = 0;
  LODWORD(v101) = 0;
  if ( v101 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkpVelocityAccumulator **, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      array,
      (unsigned int)(8 * HIDWORD(v101)),
      v48);
  v77 = (hkpSolverElemTemp *)out.m_constraintRuntimeInMainMemory.m_storage;
  v78 = accumulators;
  v79 = hkSolveConstraints(i, v44, accumulators, (hkpSolverElemTemp *)out.m_constraintRuntimeInMainMemory.m_storage);
  v80 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v81 = v107;
  v82 = v80;
  v83 = v80[1];
  if ( v83 < v82[3] )
  {
    v84 = v83 + 16;
    *(_QWORD *)(v84 - 16) = "MiNumJacobians";
    *(float *)(v84 - 8) = (float)*(int *)(v81 + 24);
    v82[1] = v84;
  }
  v85 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v86 = v85[1];
  if ( v86 < v85[3] )
  {
    v87 = v86 + 16;
    *(_QWORD *)(v87 - 16) = "MiNumEntities";
    *(float *)(v87 - 8) = (float)(int)retaddr;
    v85[1] = v87;
  }
  if ( v79 )
  {
    hkExportImpulsesAndRhs(i, v77, v44, v78);
    v88 = motions;
    v89 = hkRigidMotionUtilApplyAccumulators(
            i,
            info,
            (hkpVelocityAccumulator *)out.m_constraintRuntime.m_storage,
            motions,
            (int)retaddr,
            336);
    hkpEntityAabbUtil::entityBatchRecalcAabb(
      *(hkpCollisionInput **)(*(_QWORD *)&(*v88)->m_type.m_storage + 184i64),
      (hkpEntity *const *)v88,
      (unsigned int)retaddr);
    v76 = v89;
    if ( *(_DWORD *)v44 )
      hkpWorldCallbackUtil::fireContactImpulseLimitBreached(
        *(hkpWorld **)(v81 + 32),
        (hkpContactImpulseLimitBreachedListenerInfo *)&v44[16],
        *(_DWORD *)v44);
  }
  if ( m_cur )
  {
    v90 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v90[10] + 16i64))(v90[10], m_cur, (unsigned int)v94);
  }
  v91 = out.m_jacobianSchemas.m_storage;
  if ( out.m_jacobianSchemas.m_storage )
  {
    v92 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 13);
    (*(void (__fastcall **)(__int64, hkpJacobianSchema *, _QWORD))(*(_QWORD *)v92 + 32i64))(
      v92,
      v91,
      (unsigned int)array);
  }
  return v76;
}

// File Line: 582
// RVA: 0xD916D0
void __fastcall hkpConstraintSolverSetup::initializeSolverState(
        hkStepInfo *stepInfo,
        hkpSolverInfo *solverInfo,
        hkpConstraintQueryIn *constraintQueryIn,
        char *buffer,
        int bufferSize,
        const char *priorityClassMap,
        const float *priorityClassRatios,
        hkpConstraintSolverResources *s)
{
  int v9; // r11d
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
  hkpVelocityAccumulator *m_accumulators; // rax

  s->m_solverInfo = solverInfo;
  s->m_stepInfo = stepInfo;
  s->m_constraintQueryInput = constraintQueryIn;
  hkMemUtil::memCpy(s->m_priorityClassMap, priorityClassMap, 6);
  v9 = bufferSize - bufferSize % 16;
  v10 = (hkpVelocityAccumulator *)((unsigned __int64)(buffer + 15) & 0xFFFFFFFFFFFFFFF0ui64);
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
  v15 = (hkpJacobianSchema *)(((unsigned __int64)&v12->m_coreTworldRotation.m_col1 + (int)(float)(v14 * 0.015384615)) & 0xFFFFFFFFFFFFFFF0ui64);
  s->m_schemas[0].m_end = v15;
  s->m_schemas[1].m_begin = v15;
  v16 = v13 * priorityClassRatios[1];
  s->m_schemas[1].m_current = v15;
  s->m_schemas[1].m_lastProcessed = v15;
  v17 = (hkpJacobianSchema *)((unsigned __int64)&v15[(int)(float)(v16 * 0.015384615) + 16] & 0xFFFFFFFFFFFFFFF0ui64);
  s->m_schemas[1].m_end = v17;
  s->m_schemas[2].m_begin = v17;
  v18 = v13 * priorityClassRatios[2];
  s->m_schemas[2].m_current = v17;
  s->m_schemas[2].m_lastProcessed = v17;
  v19 = (hkpJacobianSchema *)((unsigned __int64)&v17[(int)(float)(v18 * 0.015384615) + 16] & 0xFFFFFFFFFFFFFFF0ui64);
  s->m_schemas[2].m_end = v19;
  m_accumulators = s->m_accumulators;
  s->m_elemTemp = (hkpSolverElemTemp *)v19;
  s->m_elemTempEnd = (hkpSolverElemTemp *)&buffer[v9];
  s->m_elemTempCurrent = (hkpSolverElemTemp *)v19;
  s->m_elemTempLastProcessed = (hkpSolverElemTemp *)v19;
  s->m_accumulatorsCurrent = m_accumulators;
}

// File Line: 675
// RVA: 0xD91870
void __fastcall hkpConstraintSolverSetup::shutdownSolver(hkpConstraintSolverResources *s)
{
  ;
}

// File Line: 680
// RVA: 0xD91880
void __fastcall hkpConstraintSolverSetup::internalAddAccumulators(
        hkpConstraintSolverResources *s,
        hkpMotion *const *entities,
        unsigned int numEntities)
{
  hkpVelocityAccumulator *m_accumulatorsCurrent; // r11
  __int64 v4; // rsi
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  int v15; // edx
  __int64 v16; // r8
  __int64 v17; // r9
  float v18; // xmm0_4
  __int128 v19; // xmm0
  hkpConstraintSolverResources::VelocityAccumTransformBackup *m_accumulatorsBackup; // rax
  int v21; // edx
  hkpMotion *const *v22; // r8
  __int64 v23; // r9
  hkpMotion *v24; // rax
  int v25; // ecx
  hkpVelocityAccumulator *v26; // r15
  unsigned __int64 v27; // rcx
  hkpConstraintSolverResources::VelocityAccumTransformBackup *v28; // rbx
  hkVector4f *p_m_scratch0; // r11
  _OWORD *m128_f32; // rbx
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm3_4
  float v37; // xmm0_4
  float v38; // xmm0_4
  __int64 v39; // r10
  __int64 v40; // r8
  __int64 v41; // r9
  float v42; // xmm0_4
  __int128 v43; // [rsp+10h] [rbp-29h]
  hkpVelocityAccumulator *accumulatorsOut[2]; // [rsp+20h] [rbp-19h]
  __int64 v45; // [rsp+A0h] [rbp+67h]
  float vars0; // [rsp+B0h] [rbp+77h]

  if ( numEntities )
  {
    m_accumulatorsCurrent = s->m_accumulatorsCurrent;
    v4 = numEntities;
    if ( m_accumulatorsCurrent == s->m_accumulators )
    {
      *(_WORD *)&m_accumulatorsCurrent->m_type.m_storage = 1;
      m_accumulatorsCurrent->m_gravityFactor = 0.0;
      m_accumulatorsCurrent->m_invMasses = 0i64;
      m_accumulatorsCurrent->m_linearVel = 0i64;
      m_accumulatorsCurrent->m_angularVel = 0i64;
      m_accumulatorsCurrent->m_scratch3 = 0i64;
      m_accumulatorsCurrent->m_scratch0 = (hkVector4f)transform.m_quad;
      m_accumulatorsCurrent->m_scratch1 = (hkVector4f)direction.m_quad;
      m_accumulatorsCurrent->m_context.m_storage = 1;
      m_accumulatorsCurrent->m_scratch2 = (hkVector4f)stru_141A71280.m_quad;
      v7 = m_accumulatorsCurrent->m_scratch0.m_quad.m128_f32[0];
      v8 = m_accumulatorsCurrent->m_scratch1.m_quad.m128_f32[1];
      v9 = m_accumulatorsCurrent->m_scratch2.m_quad.m128_f32[2];
      v10 = (float)(v7 + v8) + v9;
      if ( v10 <= 0.0 )
      {
        LODWORD(v43) = 1;
        *(_QWORD *)((char *)&v43 + 4) = 2i64;
        v15 = v8 > v7;
        if ( v9 > m_accumulatorsCurrent->m_scratch0.m_quad.m128_f32[5 * (v8 > v7)] )
          v15 = 2;
        v16 = *((int *)&accumulatorsOut[-2] + v15);
        v17 = *((int *)&accumulatorsOut[-2] + v16);
        vars0 = (float)(m_accumulatorsCurrent->m_scratch0.m_quad.m128_f32[5 * v15]
                      - (float)(m_accumulatorsCurrent->m_scratch0.m_quad.m128_f32[5 * v17]
                              + m_accumulatorsCurrent->m_scratch0.m_quad.m128_f32[5 * v16]))
              + 1.0;
        v18 = fsqrt(vars0);
        *((float *)&accumulatorsOut[-2] + v15) = v18 * 0.5;
        *((float *)&v43 + 3) = (float)(m_accumulatorsCurrent->m_scratch0.m_quad.m128_f32[4 * v16 + v17]
                                     - m_accumulatorsCurrent->m_scratch0.m_quad.m128_f32[4 * v17 + v16])
                             * (float)(0.5 / v18);
        *((float *)&accumulatorsOut[-2] + v16) = (float)(m_accumulatorsCurrent->m_scratch0.m_quad.m128_f32[4 * v16 + v15]
                                                       + m_accumulatorsCurrent->m_scratch0.m_quad.m128_f32[4 * v15 + v16])
                                               * (float)(0.5 / v18);
        *((float *)&accumulatorsOut[-2] + v17) = (float)(m_accumulatorsCurrent->m_scratch0.m_quad.m128_f32[4 * v17 + v15]
                                                       + m_accumulatorsCurrent->m_scratch0.m_quad.m128_f32[4 * v15 + v17])
                                               * (float)(0.5 / v18);
      }
      else
      {
        v11 = m_accumulatorsCurrent->m_scratch2.m_quad.m128_f32[0]
            - m_accumulatorsCurrent->m_scratch0.m_quad.m128_f32[2];
        vars0 = v10 + 1.0;
        v12 = fsqrt(v10 + 1.0);
        v13 = m_accumulatorsCurrent->m_scratch1.m_quad.m128_f32[2]
            - m_accumulatorsCurrent->m_scratch2.m_quad.m128_f32[1];
        *((float *)&v43 + 3) = v12 * 0.5;
        *(float *)&v43 = v13 * (float)(0.5 / v12);
        v14 = m_accumulatorsCurrent->m_scratch0.m_quad.m128_f32[1];
        *((float *)&v43 + 1) = v11 * (float)(0.5 / v12);
        *((float *)&v43 + 2) = (float)(v14 - m_accumulatorsCurrent->m_scratch1.m_quad.m128_f32[0]) * (float)(0.5 / v12);
      }
      v19 = v43;
      m_accumulatorsCurrent->m_scratch0 = 0i64;
      m_accumulatorsCurrent->m_scratch1 = 0i64;
      m_accumulatorsCurrent->m_scratch2 = (hkVector4f)v19;
      s->m_accumulatorsCurrent = m_accumulatorsCurrent + 1;
      m_accumulatorsBackup = s->m_accumulatorsBackup;
      m_accumulatorsBackup->m_coreTworldRotation.m_col0 = (hkVector4f)transform.m_quad;
      m_accumulatorsBackup->m_coreTworldRotation.m_col1 = (hkVector4f)direction.m_quad;
      m_accumulatorsBackup->m_coreTworldRotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    }
    v21 = 0;
    v22 = entities;
    v23 = v4;
    do
    {
      v24 = *v22;
      v25 = v21;
      v21 += 128;
      ++v22;
      v24->m_angularVelocity.m_quad.m128_i32[0] = LODWORD(s->m_accumulatorsCurrent) + v25 - LODWORD(s->m_accumulators);
      --v23;
    }
    while ( v23 );
    v27 = (unsigned __int64)(*entities)->m_angularVelocity.m_quad.m128_u32[0] >> 7;
    accumulatorsOut[0] = s->m_accumulatorsCurrent;
    v26 = accumulatorsOut[0];
    v28 = &s->m_accumulatorsBackup[v27];
    s->m_accumulatorsCurrent = hkRigidMotionUtilApplyForcesAndBuildAccumulators(
                                 s->m_stepInfo,
                                 entities,
                                 v4,
                                 336,
                                 accumulatorsOut[0]);
    p_m_scratch0 = &v26->m_scratch0;
    m128_f32 = (_OWORD *)v28->m_coreTworldRotation.m_col2.m_quad.m128_f32;
    do
    {
      *(m128_f32 - 2) = p_m_scratch0->m_quad;
      *(m128_f32 - 1) = p_m_scratch0[1];
      *m128_f32 = p_m_scratch0[2];
      p_m_scratch0[-4].m_quad.m128_i8[1] = 1;
      v31 = p_m_scratch0->m_quad.m128_f32[0];
      v32 = p_m_scratch0[1].m_quad.m128_f32[1];
      v33 = p_m_scratch0[2].m_quad.m128_f32[2];
      v34 = (float)(p_m_scratch0->m_quad.m128_f32[0] + v32) + v33;
      if ( v34 <= 0.0 )
      {
        LODWORD(v43) = 1;
        *(_QWORD *)((char *)&v43 + 4) = 2i64;
        v39 = v32 > v31;
        if ( v33 > p_m_scratch0->m_quad.m128_f32[5 * v39] )
          v39 = 2i64;
        v40 = *((int *)&accumulatorsOut[-2] + v39);
        v41 = *((int *)&accumulatorsOut[-2] + v40);
        vars0 = (float)(p_m_scratch0->m_quad.m128_f32[5 * v39]
                      - (float)(p_m_scratch0->m_quad.m128_f32[5 * v41] + p_m_scratch0->m_quad.m128_f32[5 * v40]))
              + 1.0;
        v42 = fsqrt(vars0);
        *((float *)accumulatorsOut + v39) = v42 * 0.5;
        *((float *)&accumulatorsOut[1] + 1) = (float)(p_m_scratch0[v40].m_quad.m128_f32[v41]
                                                    - p_m_scratch0[v41].m_quad.m128_f32[v40])
                                            * (float)(0.5 / v42);
        *((float *)accumulatorsOut + v40) = (float)(p_m_scratch0[v40].m_quad.m128_f32[v39]
                                                  + p_m_scratch0[v39].m_quad.m128_f32[v40])
                                          * (float)(0.5 / v42);
        *((float *)accumulatorsOut + v41) = (float)(p_m_scratch0[v41].m_quad.m128_f32[v39]
                                                  + p_m_scratch0[v39].m_quad.m128_f32[v41])
                                          * (float)(0.5 / v42);
      }
      else
      {
        v35 = p_m_scratch0[2].m_quad.m128_f32[0] - p_m_scratch0->m_quad.m128_f32[2];
        vars0 = v34 + 1.0;
        v36 = fsqrt(v34 + 1.0);
        v37 = p_m_scratch0[1].m_quad.m128_f32[2] - p_m_scratch0[2].m_quad.m128_f32[1];
        *((float *)&accumulatorsOut[1] + 1) = v36 * 0.5;
        *(float *)accumulatorsOut = v37 * (float)(0.5 / v36);
        v38 = p_m_scratch0->m_quad.m128_f32[1];
        *((float *)accumulatorsOut + 1) = v35 * (float)(0.5 / v36);
        *(float *)&accumulatorsOut[1] = (float)(v38 - p_m_scratch0[1].m_quad.m128_f32[0]) * (float)(0.5 / v36);
      }
      p_m_scratch0 += 8;
      m128_f32 += 3;
      p_m_scratch0[-6] = *(hkVector4f *)accumulatorsOut;
      p_m_scratch0[-8] = 0i64;
      p_m_scratch0[-7] = 0i64;
      --v4;
    }
    while ( v4 );
    **(_BYTE **)(v45 + 40) = 3;
  }
}

// File Line: 732
// RVA: 0xD91D40
void __fastcall hkpConstraintSolverSetup::internalAddJacobianSchemas(
        hkpConstraintSolverResources *s,
        hkpConstraintInstance **constraints,
        int numConstraints,
        hkArray<hkpConstraintSchemaInfo,hkContainerHeapAllocator> *constraintStatus)
{
  hkpConstraintQueryIn *m_constraintQueryInput; // r15
  hkArray<hkpConstraintSchemaInfo,hkContainerHeapAllocator> *v5; // r13
  hkpConstraintInstance **v6; // r12
  hkpConstraintInstance *v8; // rsi
  hkConstraintInternal *m_internal; // r11
  hkpEntity *v10; // r10
  hkpEntity *v11; // r9
  hkpVelocityAccumulator *v12; // rdi
  hkpVelocityAccumulator *v13; // rbx
  hkpEntity **m_entities; // r11
  hkpConstraintSolverResources::VelocityAccumTransformBackup *m_accumulatorsBackup; // rdx
  hkpEntity *v16; // rax
  unsigned __int64 v17; // r8
  unsigned __int64 m_solverData; // rcx
  hkVector4f v19; // xmm0
  hkVector4f v20; // xmm1
  hkVector4f v21; // xmm0
  hkVector4f v22; // xmm1
  hkVector4f v23; // xmm0
  hkVector4f v24; // xmm1
  hkpEntity *v25; // rax
  __int64 m_size; // rcx
  hkpConstraintSchemaInfo *m_data; // rdx
  __int64 v28; // r8
  __int64 v29; // r13
  hkConstraintInternal *v30; // rax
  hkpSimpleContactConstraintAtom *m_atoms; // rcx
  hkpJacobianSchema *m_storage; // rax
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm3_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm3_4
  float v39; // xmm0_4
  float v40; // xmm0_4
  __int64 v41; // r10
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
  __int64 v54; // r10
  __int64 v55; // r8
  __int64 v56; // r9
  float v57; // xmm0_4
  int v58; // [rsp+20h] [rbp-89h]
  __int64 v59; // [rsp+24h] [rbp-85h]
  int v60; // [rsp+30h] [rbp-79h]
  __int64 v61; // [rsp+34h] [rbp-75h]
  __int128 v62; // [rsp+40h] [rbp-69h]
  hkVector4f v63; // [rsp+50h] [rbp-59h]
  hkpConstraintQueryOut out; // [rsp+60h] [rbp-49h] BYREF
  hkpEntity **v65; // [rsp+110h] [rbp+67h]
  hkpConstraintInstance **v66; // [rsp+118h] [rbp+6Fh]
  int v67; // [rsp+120h] [rbp+77h]

  m_constraintQueryInput = s->m_constraintQueryInput;
  v5 = constraintStatus;
  v6 = constraints;
  v66 = &constraints[numConstraints];
  if ( constraints < v66 )
  {
    do
    {
      v8 = *v6;
      m_internal = (*v6)->m_internal;
      v10 = m_internal->m_entities[0];
      v11 = m_internal->m_entities[1];
      v67 = (unsigned __int8)s->m_priorityClassMap[(unsigned __int8)(*v6)->m_priority.m_storage];
      v12 = (hkpVelocityAccumulator *)((char *)s->m_accumulators + v10->m_solverData);
      v13 = (hkpVelocityAccumulator *)((char *)s->m_accumulators + v11->m_solverData);
      m_entities = m_internal->m_entities;
      m_constraintQueryInput->m_bodyA.m_storage = v12;
      m_constraintQueryInput->m_bodyB.m_storage = v13;
      m_accumulatorsBackup = s->m_accumulatorsBackup;
      v16 = *m_entities;
      v12->m_context.m_storage = 0;
      v13->m_context.m_storage = 0;
      v65 = m_entities;
      v17 = 3 * ((unsigned __int64)v16->m_solverData >> 7);
      m_solverData = m_entities[1]->m_solverData;
      m_constraintQueryInput->m_constraintInstance.m_storage = v8;
      v17 *= 2i64;
      v19.m_quad = *(__m128 *)((char *)&m_accumulatorsBackup->m_coreTworldRotation.m_col0 + 8 * v17);
      v20.m_quad = *(__m128 *)((char *)&m_accumulatorsBackup->m_coreTworldRotation.m_col1 + 8 * v17);
      m_constraintQueryInput->m_transformB.m_storage = &v11->m_motion.m_motionState.m_transform;
      v12->m_scratch0 = (hkVector4f)v19.m_quad;
      v21.m_quad = *(__m128 *)((char *)&m_accumulatorsBackup->m_coreTworldRotation.m_col2 + 8 * v17);
      v12->m_scratch1 = (hkVector4f)v20.m_quad;
      v22.m_quad = (__m128)m_accumulatorsBackup[m_solverData >> 7].m_coreTworldRotation.m_col0;
      v12->m_scratch2 = (hkVector4f)v21.m_quad;
      v23.m_quad = (__m128)m_accumulatorsBackup[m_solverData >> 7].m_coreTworldRotation.m_col1;
      v13->m_scratch0 = (hkVector4f)v22.m_quad;
      v24.m_quad = (__m128)m_accumulatorsBackup[m_solverData >> 7].m_coreTworldRotation.m_col2;
      v13->m_scratch1 = (hkVector4f)v23.m_quad;
      m_constraintQueryInput->m_transformA.m_storage = &v10->m_motion.m_motionState.m_transform;
      out.m_constraintRuntime.m_storage = v8->m_internal->m_runtime;
      v25 = *m_entities;
      v13->m_scratch2 = (hkVector4f)v24.m_quad;
      m_constraintQueryInput->m_accumulatorAIndex.m_storage = (unsigned __int16)(v25->m_solverData >> 7);
      m_constraintQueryInput->m_accumulatorBIndex.m_storage = (unsigned __int16)(m_entities[1]->m_solverData >> 7);
      LODWORD(v25) = v5->m_capacityAndFlags & 0x3FFFFFFF;
      out.m_constraintRuntimeInMainMemory.m_storage = v8->m_internal->m_runtime;
      if ( v5->m_size == (_DWORD)v25 )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v5->m_data, 24);
        m_entities = v65;
      }
      m_size = v5->m_size;
      m_data = v5->m_data;
      v28 = m_size;
      v5->m_size = m_size + 1;
      m_data[v28].m_constraint = v8;
      v29 = v67;
      m_data[v28].m_schema = s->m_schemas[v29].m_current;
      m_data[v28].m_allowedPenetrationDepth = fminf(
                                                (*m_entities)->m_collidable.m_allowedPenetrationDepth,
                                                m_entities[1]->m_collidable.m_allowedPenetrationDepth);
      out.m_jacobianSchemas.m_storage = s->m_schemas[v29].m_current;
      if ( ((unsigned int (__fastcall *)(hkpConstraintData *))v8->m_data->vfptr[1].__first_virtual_table_function__)(v8->m_data) == 11 )
        hkSimpleContactConstraintData_fireCallbacks(
          (hkpSimpleContactConstraintData *)v8->m_data,
          m_constraintQueryInput,
          (hkpSimpleContactConstraintAtom *)v8->m_data[2].m_userData,
          TYPE_MANIFOLD);
      if ( (v8->m_internal->m_callbackRequest & 4) != 0 )
        ((void (__fastcall *)(hkpConstraintData *, hkpConstraintQueryIn *, hkpConstraintQueryOut *))v8->m_data->vfptr[11].__vecDelDtor)(
          v8->m_data,
          m_constraintQueryInput,
          &out);
      v30 = v8->m_internal;
      m_atoms = (hkpSimpleContactConstraintAtom *)v30->m_atoms;
      if ( m_atoms->m_type.m_storage == 29 )
        hkSimpleContactConstraintDataBuildJacobian(m_atoms, m_constraintQueryInput, (hkBool)1, &out);
      else
        hkSolverBuildJacobianFromAtomsNotContact(m_atoms, v30->m_atomsSize, m_constraintQueryInput, &out);
      m_storage = out.m_jacobianSchemas.m_storage;
      v12->m_context.m_storage = 1;
      v33 = v12->m_scratch0.m_quad.m128_f32[0];
      v34 = v12->m_scratch1.m_quad.m128_f32[1];
      v35 = v12->m_scratch2.m_quad.m128_f32[2];
      s->m_schemas[v29].m_current = m_storage;
      v36 = (float)(v33 + v34) + v35;
      s->m_elemTempCurrent += v8->m_internal->m_numSolverElemTemps;
      if ( v36 <= 0.0 )
      {
        v58 = 1;
        v59 = 2i64;
        v41 = v34 > v33;
        if ( v35 > v12->m_scratch0.m_quad.m128_f32[5 * v41] )
          v41 = 2i64;
        v42 = *(&v58 + v41);
        v43 = *(&v58 + v42);
        v44 = fsqrt(
                (float)(v12->m_scratch0.m_quad.m128_f32[5 * v41]
                      - (float)(v12->m_scratch0.m_quad.m128_f32[5 * v43] + v12->m_scratch0.m_quad.m128_f32[5 * v42]))
              + 1.0);
        *((float *)&v62 + v41) = v44 * 0.5;
        *((float *)&v62 + 3) = (float)(v12->m_scratch0.m_quad.m128_f32[4 * v42 + v43]
                                     - v12->m_scratch0.m_quad.m128_f32[4 * v43 + v42])
                             * (float)(0.5 / v44);
        *((float *)&v62 + v42) = (float)(v12->m_scratch0.m_quad.m128_f32[4 * v41 + v42]
                                       + v12->m_scratch0.m_quad.m128_f32[4 * v42 + v41])
                               * (float)(0.5 / v44);
        *((float *)&v62 + v43) = (float)(v12->m_scratch0.m_quad.m128_f32[4 * v41 + v43]
                                       + v12->m_scratch0.m_quad.m128_f32[4 * v43 + v41])
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
        v54 = v47 > v46;
        if ( v48 > v13->m_scratch0.m_quad.m128_f32[5 * v54] )
          v54 = 2i64;
        v55 = *(&v60 + v54);
        v56 = *(&v60 + v55);
        v57 = fsqrt(
                (float)(v13->m_scratch0.m_quad.m128_f32[5 * v54]
                      - (float)(v13->m_scratch0.m_quad.m128_f32[5 * v56] + v13->m_scratch0.m_quad.m128_f32[5 * v55]))
              + 1.0);
        v63.m_quad.m128_f32[v54] = v57 * 0.5;
        v63.m_quad.m128_f32[3] = (float)(v13->m_scratch0.m_quad.m128_f32[4 * v55 + v56]
                                       - v13->m_scratch0.m_quad.m128_f32[4 * v56 + v55])
                               * (float)(0.5 / v57);
        v63.m_quad.m128_f32[v55] = (float)(v13->m_scratch0.m_quad.m128_f32[4 * v55 + v54]
                                         + v13->m_scratch0.m_quad.m128_f32[4 * v54 + v55])
                                 * (float)(0.5 / v57);
        v63.m_quad.m128_f32[v56] = (float)(v13->m_scratch0.m_quad.m128_f32[4 * v56 + v54]
                                         + v13->m_scratch0.m_quad.m128_f32[4 * v54 + v56])
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
      v5 = constraintStatus;
      ++v6;
      v13->m_scratch2 = (hkVector4f)v63.m_quad;
      v13->m_scratch0 = 0i64;
      v13->m_scratch1 = 0i64;
    }
    while ( v6 < v66 );
  }
  *(_DWORD *)s->m_schemas[0].m_current = 0;
  *(_DWORD *)s->m_schemas[1].m_current = 0;
  *(_DWORD *)s->m_schemas[2].m_current = 0;
}

// File Line: 855
// RVA: 0xD92580
hkBool *__fastcall hkpConstraintSolverSetup::internalIsMemoryOkForNewAccumulators(
        hkBool *result,
        hkpConstraintSolverResources *s,
        hkpEntity **entities,
        int numEntities)
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
hkBool *__fastcall hkpConstraintSolverSetup::internalIsMemoryOkForNewJacobianSchemas(
        hkBool *result,
        hkpConstraintSolverResources *s,
        hkpConstraintInstance **constraints,
        int numConstraints)
{
  hkpSolverElemTemp *m_elemTempCurrent; // rdi
  hkpConstraintInstance **v5; // r11
  hkpConstraintInstance **v8; // r9
  __int64 v9; // rcx
  __int64 v10; // r8
  hkpJacobianSchema **p_m_end; // rdx
  __int64 i; // rax
  bool v13; // cl
  __int64 v15[5]; // [rsp+0h] [rbp-28h]

  m_elemTempCurrent = s->m_elemTempCurrent;
  v5 = constraints;
  v15[0] = (__int64)s->m_schemas[0].m_current;
  v15[1] = (__int64)s->m_schemas[1].m_current;
  v15[2] = (__int64)s->m_schemas[2].m_current;
  v8 = &constraints[numConstraints];
  if ( constraints < v8 )
  {
    do
    {
      v9 = (__int64)*v5++;
      v10 = *(_QWORD *)(v9 + 96);
      m_elemTempCurrent += *(unsigned __int16 *)(v10 + 40);
      v15[(unsigned __int8)s->m_priorityClassMap[*(unsigned __int8 *)(v9 + 56)]] += *(unsigned __int16 *)(v10 + 36);
    }
    while ( v5 < v8 );
  }
  p_m_end = &s->m_schemas[0].m_end;
  result->m_bool = m_elemTempCurrent <= s->m_elemTempEnd;
  for ( i = 0i64; i < 3; ++i )
  {
    v13 = result->m_bool && v15[i] + 4 <= (unsigned __int64)*p_m_end;
    p_m_end += 4;
    result->m_bool = v13;
  }
  return result;
}

// File Line: 915
// RVA: 0xD92340
void __fastcall hkpConstraintSolverSetup::subSolve(
        hkpConstraintSolverResources *s,
        hkpConstraintSolverSetup::SolverMode mode)
{
  hkpSolverElemTemp *m_elemTempLastProcessed; // rdi
  __int64 i; // rcx
  hkpJacobianSchema **p_m_lastProcessed; // rdi
  __int64 v6; // rsi
  hkpJacobianSchema *v7; // rax

  if ( mode == SOLVER_MODE_PROCESS_ALL )
  {
    s->m_schemas[0].m_lastProcessed = s->m_schemas[0].m_begin;
    s->m_schemas[1].m_lastProcessed = s->m_schemas[1].m_begin;
    s->m_schemas[2].m_lastProcessed = s->m_schemas[2].m_begin;
  }
  if ( ((LODWORD(s->m_elemTempCurrent) - LODWORD(s->m_elemTempLastProcessed)) >> 2) - 1 >= 0 )
  {
    m_elemTempLastProcessed = s->m_elemTempLastProcessed;
    for ( i = (unsigned int)((LODWORD(s->m_elemTempCurrent) - LODWORD(s->m_elemTempLastProcessed)) >> 2); i; --i )
    {
      m_elemTempLastProcessed->m_impulseApplied = 0.0;
      ++m_elemTempLastProcessed;
    }
  }
  p_m_lastProcessed = &s->m_schemas[0].m_lastProcessed;
  v6 = 3i64;
  s->m_elemTempLastProcessed = s->m_elemTempCurrent;
  do
  {
    if ( *p_m_lastProcessed != *(p_m_lastProcessed - 1) )
      hkSolveStepJacobians(s->m_solverInfo, *p_m_lastProcessed, s->m_accumulators, s->m_elemTemp);
    v7 = *(p_m_lastProcessed - 1);
    p_m_lastProcessed += 4;
    *(p_m_lastProcessed - 4) = v7;
    --v6;
  }
  while ( v6 );
}


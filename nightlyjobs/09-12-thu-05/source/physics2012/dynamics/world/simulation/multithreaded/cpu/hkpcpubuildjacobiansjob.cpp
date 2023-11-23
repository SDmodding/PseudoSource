// File Line: 46
// RVA: 0xD95F90
void __fastcall hkCpuBuildJacobiansFromTask(hkBuildJacobiansFromTaskInput *input, hkpConstraintQueryIn *queryIn)
{
  __int64 m_numAtomInfos; // rdi
  hkpJacobianSchema *m_schemas; // rax
  hkpBuildJacobianTask::AtomInfo *m_atomInfos; // rbp
  hkpBuildJacobianTask::AtomInfo *v7; // rcx
  int m_atomsSize; // edx
  hkpSimpleContactConstraintAtom *m_atoms; // rcx
  float v10; // xmm0_4
  hkpConstraintQueryOut out; // [rsp+20h] [rbp-28h] BYREF

  m_numAtomInfos = input->m_numAtomInfos;
  m_schemas = input->m_schemas;
  m_atomInfos = input->m_atomInfos;
  out.m_jacobianSchemas.m_storage = m_schemas;
  if ( m_numAtomInfos > 0 )
  {
    do
    {
      v7 = m_atomInfos++;
      queryIn->m_transformA.m_storage = v7->m_transformA;
      queryIn->m_transformB.m_storage = v7->m_transformB;
      queryIn->m_bodyA.m_storage = &input->m_accumulators[(unsigned __int64)v7->m_accumulatorIndexA];
      queryIn->m_bodyB.m_storage = &input->m_accumulators[(unsigned __int64)v7->m_accumulatorIndexB];
      queryIn->m_accumulatorAIndex.m_storage = v7->m_accumulatorIndexA;
      queryIn->m_accumulatorBIndex.m_storage = v7->m_accumulatorIndexB;
      queryIn->m_constraintInstance.m_storage = v7->m_instance;
      out.m_constraintRuntime.m_storage = v7->m_runtime;
      out.m_constraintRuntimeInMainMemory.m_storage = v7->m_runtime;
      m_atomsSize = v7->m_atomsSize;
      m_atoms = (hkpSimpleContactConstraintAtom *)v7->m_atoms;
      if ( m_atoms->m_type.m_storage == 29 )
        hkSimpleContactConstraintDataBuildJacobian(m_atoms, queryIn, (hkBool)1, &out);
      else
        hkSolverBuildJacobianFromAtomsNotContact(m_atoms, m_atomsSize, queryIn, &out);
      --m_numAtomInfos;
    }
    while ( m_numAtomInfos );
    m_schemas = out.m_jacobianSchemas.m_storage;
  }
  if ( input->m_finishSchemasWithGoto.m_bool )
  {
    if ( input->m_schemasOfNextTask - m_schemas > 0 )
    {
      v10 = *(float *)m_schemas;
      *(_QWORD *)&m_schemas[8] = input->m_schemasOfNextTask - m_schemas;
      *(float *)m_schemas = v10 + 0.00000011920929;
      *m_schemas = (hkpJacobianSchema)2;
    }
  }
  else
  {
    *(_DWORD *)m_schemas = 0;
  }
}

// File Line: 131
// RVA: 0xD95D60
__int64 __fastcall hkCpuBuildJacobiansJob(
        hkpMtThreadStructure *tl,
        hkJobQueue *jobQueue,
        hkJobQueue::JobQueueEntry *jobInOut)
{
  _QWORD *Value; // rax
  unsigned __int64 v7; // r9
  _QWORD *v8; // rcx
  unsigned __int64 v9; // rax
  bool v10; // zf
  __int64 v11; // rcx
  __int128 v12; // xmm1
  __int64 v13; // rsi
  __int128 v14; // xmm0
  __int128 v15; // xmm1
  hkSimdFloat32 v16; // xmm0
  __int128 v17; // xmm1
  __int128 v18; // xmm0
  __int128 v19; // xmm1
  __int64 v20; // r12
  hkpJacobianSchema *m_storage; // rax
  __int64 v22; // rdi
  bool v23; // r15
  __int64 v24; // rbx
  __int64 v25; // rcx
  int v26; // edx
  hkpSimpleContactConstraintAtom *v27; // rcx
  __int64 v28; // rdi
  float v29; // xmm0_4
  _QWORD *v30; // r8
  _QWORD *v31; // rcx
  unsigned __int64 v32; // rax
  _QWORD *v33; // rcx
  hkpConstraintQueryOut out; // [rsp+20h] [rbp-79h] BYREF
  hkpConstraintQueryIn in; // [rsp+40h] [rbp-59h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = Value[1];
  v8 = Value;
  if ( v7 < Value[3] )
  {
    *(_QWORD *)v7 = "LtIntegrate";
    *(_QWORD *)(v7 + 16) = "StBuildJacobians";
    v9 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v9;
    v8[1] = v7 + 24;
  }
  v10 = jobInOut->m_data[48] == 0;
  v11 = *(_QWORD *)&jobInOut->m_data[32];
  v12 = *(_OWORD *)&tl->m_constraintQueryIn.m_frameInvDeltaTime.m_storage;
  *(_OWORD *)&in.m_subStepDeltaTime.m_storage = *(_OWORD *)&tl->m_constraintQueryIn.m_subStepDeltaTime.m_storage;
  v13 = v11 + 48;
  *(_OWORD *)&in.m_rhsFactor.m_storage = *(_OWORD *)&tl->m_constraintQueryIn.m_rhsFactor.m_storage;
  v14 = *(_OWORD *)&tl->m_constraintQueryIn.m_transformA.m_storage;
  *(_OWORD *)&in.m_frameInvDeltaTime.m_storage = v12;
  v15 = *(_OWORD *)&tl->m_constraintQueryIn.m_bodyA.m_storage;
  *(_OWORD *)&in.m_transformA.m_storage = v14;
  v16.m_real = (__m128)tl->m_constraintQueryIn.m_maxConstraintViolationSqrd;
  *(_OWORD *)&in.m_bodyA.m_storage = v15;
  v17 = *(_OWORD *)&tl->m_constraintQueryIn.m_tau.m_storage;
  in.m_maxConstraintViolationSqrd = (hkSimdFloat32)v16.m_real;
  v18 = *(_OWORD *)&tl->m_constraintQueryIn.m_accumulatorAIndex.m_storage;
  *(_OWORD *)&in.m_tau.m_storage = v17;
  v19 = *(_OWORD *)&tl->m_constraintQueryIn.m_constraintInstance.m_storage;
  *(_OWORD *)&in.m_accumulatorAIndex.m_storage = v18;
  *(_OWORD *)&in.m_constraintInstance.m_storage = v19;
  v20 = *(_QWORD *)(v11 + 16);
  m_storage = *(hkpJacobianSchema **)(v11 + 24);
  v22 = *(_QWORD *)(v11 + 32);
  v23 = !v10 && *(_QWORD *)v11;
  v24 = *(int *)(v11 + 40);
  out.m_jacobianSchemas.m_storage = *(hkpJacobianSchema **)(v11 + 24);
  if ( v24 > 0 )
  {
    do
    {
      v25 = v13;
      v13 += 48i64;
      in.m_transformA.m_storage = *(hkTransformf **)(v25 + 24);
      in.m_transformB.m_storage = *(hkTransformf **)(v25 + 32);
      in.m_bodyA.m_storage = (hkpVelocityAccumulator *)(v20 + ((unsigned __int64)*(unsigned __int16 *)(v25 + 44) << 7));
      in.m_bodyB.m_storage = (hkpVelocityAccumulator *)(v20 + ((unsigned __int64)*(unsigned __int16 *)(v25 + 46) << 7));
      in.m_accumulatorAIndex.m_storage = *(unsigned __int16 *)(v25 + 44);
      in.m_accumulatorBIndex.m_storage = *(unsigned __int16 *)(v25 + 46);
      in.m_constraintInstance.m_storage = *(hkpConstraintInstance **)(v25 + 8);
      out.m_constraintRuntime.m_storage = *(struct hkpConstraintRuntime **)(v25 + 16);
      out.m_constraintRuntimeInMainMemory.m_storage = *(void **)(v25 + 16);
      v26 = *(unsigned __int16 *)(v25 + 40);
      v27 = *(hkpSimpleContactConstraintAtom **)v25;
      if ( v27->m_type.m_storage == 29 )
        hkSimpleContactConstraintDataBuildJacobian(v27, &in, (hkBool)1, &out);
      else
        hkSolverBuildJacobianFromAtomsNotContact(v27, v26, &in, &out);
      --v24;
    }
    while ( v24 );
    m_storage = out.m_jacobianSchemas.m_storage;
  }
  if ( v23 )
  {
    v28 = v22 - (_QWORD)m_storage;
    if ( v28 > 0 )
    {
      v29 = *(float *)m_storage;
      *(_QWORD *)&m_storage[8] = v28;
      *(float *)m_storage = v29 + 0.00000011920929;
      *m_storage = (hkpJacobianSchema)2;
    }
  }
  else
  {
    *(_DWORD *)m_storage = 0;
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
  return hkJobQueue::finishJobAndGetNextJob(jobQueue, jobInOut, jobInOut, WAIT_FOR_NEXT_JOB);
}


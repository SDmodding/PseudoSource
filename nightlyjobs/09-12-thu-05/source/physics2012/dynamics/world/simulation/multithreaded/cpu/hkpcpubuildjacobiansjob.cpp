// File Line: 46
// RVA: 0xD95F90
void __fastcall hkCpuBuildJacobiansFromTask(hkBuildJacobiansFromTaskInput *input, hkpConstraintQueryIn *queryIn)
{
  __int64 v2; // rdi
  hkpJacobianSchema *v3; // rax
  hkpBuildJacobianTask::AtomInfo *v4; // rbp
  hkpConstraintQueryIn *v5; // rbx
  hkBuildJacobiansFromTaskInput *v6; // rsi
  hkpBuildJacobianTask::AtomInfo *v7; // rcx
  int v8; // edx
  hkpSimpleContactConstraintAtom *v9; // rcx
  float v10; // xmm0_4
  hkpConstraintQueryOut out; // [rsp+20h] [rbp-28h]

  v2 = input->m_numAtomInfos;
  v3 = input->m_schemas;
  v4 = input->m_atomInfos;
  v5 = queryIn;
  v6 = input;
  out.m_jacobianSchemas.m_storage = input->m_schemas;
  if ( v2 > 0 )
  {
    do
    {
      v7 = v4;
      ++v4;
      v5->m_transformA.m_storage = v7->m_transformA;
      v5->m_transformB.m_storage = v7->m_transformB;
      v5->m_bodyA.m_storage = &v6->m_accumulators[(unsigned __int64)v7->m_accumulatorIndexA];
      v5->m_bodyB.m_storage = &v6->m_accumulators[(unsigned __int64)v7->m_accumulatorIndexB];
      v5->m_accumulatorAIndex.m_storage = v7->m_accumulatorIndexA;
      v5->m_accumulatorBIndex.m_storage = v7->m_accumulatorIndexB;
      v5->m_constraintInstance.m_storage = v7->m_instance;
      out.m_constraintRuntime.m_storage = v7->m_runtime;
      out.m_constraintRuntimeInMainMemory.m_storage = (void *)v7->m_runtime;
      v8 = v7->m_atomsSize;
      v9 = (hkpSimpleContactConstraintAtom *)v7->m_atoms;
      if ( v9->m_type.m_storage == 29 )
        hkSimpleContactConstraintDataBuildJacobian(v9, v5, (hkBool)1, &out);
      else
        hkSolverBuildJacobianFromAtomsNotContact((hkpConstraintAtom *)&v9->m_type, v8, v5, &out);
      --v2;
    }
    while ( v2 );
    v3 = out.m_jacobianSchemas.m_storage;
  }
  if ( v6->m_finishSchemasWithGoto.m_bool )
  {
    if ( (_QWORD)(v6->m_schemasOfNextTask - v3) > 0i64 )
    {
      v10 = *(float *)v3;
      *(_QWORD *)&v3[8] = v6->m_schemasOfNextTask - v3;
      *(float *)v3 = v10 + 0.00000011920929;
      *v3 = (hkpJacobianSchema)2;
    }
  }
  else
  {
    *(_DWORD *)v3 = 0;
  }
}

// File Line: 131
// RVA: 0xD95D60
__int64 __fastcall hkCpuBuildJacobiansJob(hkpMtThreadStructure *tl, hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *jobInOut)
{
  hkpMtThreadStructure *v3; // rbx
  hkJobQueue::JobQueueEntry *v4; // r14
  hkJobQueue *v5; // r13
  _QWORD *v6; // rax
  unsigned __int64 v7; // r9
  _QWORD *v8; // rcx
  unsigned __int64 v9; // rax
  bool v10; // zf
  __int64 v11; // rcx
  __int128 v12; // xmm1
  signed __int64 v13; // rsi
  __int128 v14; // xmm0
  __int128 v15; // xmm1
  hkSimdFloat32 v16; // xmm0
  __int128 v17; // xmm1
  __int128 v18; // xmm0
  __int128 v19; // xmm1
  __int64 v20; // r12
  hkpJacobianSchema *v21; // rax
  __int64 v22; // rdi
  bool v23; // r15
  __int64 v24; // rbx
  signed __int64 v25; // rcx
  int v26; // edx
  hkpSimpleContactConstraintAtom *v27; // rcx
  __int64 v28; // rdi
  float v29; // xmm0_4
  _QWORD *v30; // r8
  _QWORD *v31; // rcx
  unsigned __int64 v32; // rax
  signed __int64 v33; // rcx
  hkpConstraintQueryOut out; // [rsp+20h] [rbp-79h]
  hkpConstraintQueryIn in; // [rsp+40h] [rbp-59h]

  v3 = tl;
  v4 = jobInOut;
  v5 = jobQueue;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = v6[1];
  v8 = v6;
  if ( v7 < v6[3] )
  {
    *(_QWORD *)v7 = "LtIntegrate";
    *(_QWORD *)(v7 + 16) = "StBuildJacobians";
    v9 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v9;
    v8[1] = v7 + 24;
  }
  v10 = v4->m_data[48] == 0;
  v11 = *(_QWORD *)&v4->m_data[32];
  v12 = *(_OWORD *)&v3->m_constraintQueryIn.m_frameInvDeltaTime.m_storage;
  *(_OWORD *)&in.m_subStepDeltaTime.m_storage = *(_OWORD *)&v3->m_constraintQueryIn.m_subStepDeltaTime.m_storage;
  v13 = v11 + 48;
  *(_OWORD *)&in.m_rhsFactor.m_storage = *(_OWORD *)&v3->m_constraintQueryIn.m_rhsFactor.m_storage;
  v14 = *(_OWORD *)&v3->m_constraintQueryIn.m_transformA.m_storage;
  *(_OWORD *)&in.m_frameInvDeltaTime.m_storage = v12;
  v15 = *(_OWORD *)&v3->m_constraintQueryIn.m_bodyA.m_storage;
  *(_OWORD *)&in.m_transformA.m_storage = v14;
  v16.m_real = (__m128)v3->m_constraintQueryIn.m_maxConstraintViolationSqrd;
  *(_OWORD *)&in.m_bodyA.m_storage = v15;
  v17 = *(_OWORD *)&v3->m_constraintQueryIn.m_tau.m_storage;
  in.m_maxConstraintViolationSqrd = (hkSimdFloat32)v16.m_real;
  v18 = *(_OWORD *)&v3->m_constraintQueryIn.m_accumulatorAIndex.m_storage;
  *(_OWORD *)&in.m_tau.m_storage = v17;
  v19 = *(_OWORD *)&v3->m_constraintQueryIn.m_constraintInstance.m_storage;
  *(_OWORD *)&in.m_accumulatorAIndex.m_storage = v18;
  *(_OWORD *)&in.m_constraintInstance.m_storage = v19;
  v20 = *(_QWORD *)(v11 + 16);
  v21 = *(hkpJacobianSchema **)(v11 + 24);
  v22 = *(_QWORD *)(v11 + 32);
  v23 = !v10 && *(_QWORD *)v11;
  v24 = *(signed int *)(v11 + 40);
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
        hkSolverBuildJacobianFromAtomsNotContact((hkpConstraintAtom *)&v27->m_type, v26, &in, &out);
      --v24;
    }
    while ( v24 );
    v21 = out.m_jacobianSchemas.m_storage;
  }
  if ( v23 )
  {
    v28 = v22 - (_QWORD)v21;
    if ( v28 > 0 )
    {
      v29 = *(float *)v21;
      *(_QWORD *)&v21[8] = v28;
      *(float *)v21 = v29 + 0.00000011920929;
      *v21 = (hkpJacobianSchema)2;
    }
  }
  else
  {
    *(_DWORD *)v21 = 0;
  }
  v30 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v31 = (_QWORD *)v30[1];
  if ( (unsigned __int64)v31 < v30[3] )
  {
    *v31 = "lt";
    v32 = __rdtsc();
    v33 = (signed __int64)(v31 + 2);
    *(_DWORD *)(v33 - 8) = v32;
    v30[1] = v33;
  }
  return hkJobQueue::finishJobAndGetNextJob(v5, v4, v4, 0);
}


// File Line: 20
// RVA: 0xD960B0
__int64 __fastcall hkCpuSolveConstraintsJob(hkpMtThreadStructure *tl, hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *jobInOut)
{
  hkpMtThreadStructure *v3; // r14
  hkJobQueue::JobQueueEntry *v4; // rbx
  hkJobQueue *v5; // rsi
  _QWORD *v6; // rax
  unsigned __int64 v7; // r8
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  __int64 v10; // rax
  hkpVelocityAccumulator *v11; // r8
  hkpJacobianSchema *v12; // rdx
  hkpSolverElemTemp *v13; // r9
  __int64 v14; // rcx
  _QWORD *v15; // rax
  __int64 v16; // rdi
  __int64 v17; // rax
  __int64 v18; // rax
  __int64 v19; // rax
  _QWORD *v20; // r8
  _QWORD *v21; // rcx
  unsigned __int64 v22; // rax
  signed __int64 v23; // rcx
  _QWORD *v24; // r8
  _QWORD *v25; // rcx
  unsigned __int64 v26; // rax
  signed __int64 v27; // rcx
  hkJobQueue::JobQueueEntry job; // [rsp+20h] [rbp-108h]

  v3 = tl;
  v4 = jobInOut;
  v5 = jobQueue;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = v6[1];
  v8 = v6;
  if ( v7 < v6[3] )
  {
    *(_QWORD *)v7 = "LtIntegrate";
    *(_QWORD *)(v7 + 16) = "StSolve";
    v9 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v9;
    v8[1] = v7 + 24;
  }
  v10 = *(_QWORD *)&v4->m_data[32];
  v11 = (hkpVelocityAccumulator *)(v10 + *(unsigned int *)&v4->m_data[44]);
  v12 = (hkpJacobianSchema *)(v10 + *(unsigned int *)&v4->m_data[48]);
  v13 = (hkpSolverElemTemp *)(v10 + *(unsigned int *)&v4->m_data[52]);
  v14 = ((4 * *(_DWORD *)&v4->m_data[60] + 15) & 0xFFFFFFF0) >> 4;
  if ( (signed int)v14 > 0 )
  {
    v15 = (_QWORD *)&v13[2].m_impulseApplied;
    do
    {
      *(v15 - 1) = 0i64;
      *v15 = 0i64;
      v15 += 2;
      --v14;
    }
    while ( v14 );
  }
  hkSolveConstraints(&v3->m_world->m_dynamicsStepInfo.m_solverInfo, v12, v11, v13);
  v16 = *(_QWORD *)&v4->m_data[16];
  job.m_size = 112;
  job.m_threadAffinity = -1;
  *(_WORD *)job.m_data = *(_WORD *)v4->m_data;
  *(_QWORD *)&job.m_data[8] = *(_QWORD *)&v4->m_data[8];
  v17 = *(_QWORD *)&v4->m_data[24];
  *(_WORD *)&job.m_jobSubType = 11;
  *(_QWORD *)&job.m_data[24] = v17;
  v18 = *(_QWORD *)(v16 + 184);
  job.m_jobSpuType.m_storage = 2;
  *(_QWORD *)&job.m_data[32] = v18;
  LOWORD(v18) = *(_WORD *)(v16 + 128);
  *(_QWORD *)&job.m_data[16] = v16;
  *(_WORD *)&job.m_data[72] = v18;
  v19 = *(_QWORD *)(v16 + 24);
  *(_WORD *)&job.m_data[74] = 0;
  *(_QWORD *)&job.m_data[64] = v19;
  job.m_data[80] = 0;
  hkJobQueue::addJob(v5, &job, 0);
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "StSolverExport";
    v22 = __rdtsc();
    v23 = (signed __int64)(v21 + 2);
    *(_DWORD *)(v23 - 8) = v22;
    v20[1] = v23;
  }
  hkExportImpulsesAndRhs(
    &v3->m_world->m_dynamicsStepInfo.m_solverInfo,
    *(hkpSolverElemTemp **)(v16 + 96),
    *(hkpJacobianSchema **)(v16 + 88),
    *(hkpVelocityAccumulator **)(v16 + 64));
  v24 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v25 = (_QWORD *)v24[1];
  if ( (unsigned __int64)v25 < v24[3] )
  {
    *v25 = "lt";
    v26 = __rdtsc();
    v27 = (signed __int64)(v25 + 2);
    *(_DWORD *)(v27 - 8) = v26;
    v24[1] = v27;
  }
  return hkJobQueue::finishJobAndGetNextJob(v5, v4, v4, 0);
}

// File Line: 74
// RVA: 0xD962B0
__int64 __fastcall hkCpuSolveApplyGravityJob(hkpMtThreadStructure *tl, hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *jobInOut)
{
  hkpMtThreadStructure *v3; // rsi
  hkJobQueue::JobQueueEntry *v4; // rbx
  hkJobQueue *v5; // rdi
  _QWORD *v6; // rax
  unsigned __int64 v7; // r8
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx

  v3 = tl;
  v4 = jobInOut;
  v5 = jobQueue;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = v6[1];
  v8 = v6;
  if ( v7 < v6[3] )
  {
    *(_QWORD *)v7 = "LtIntegrate";
    *(_QWORD *)(v7 + 16) = "StAppGrav";
    v9 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v9;
    v8[1] = v7 + 24;
  }
  hkSolveApplyGravityByTheSteps(
    &v3->m_world->m_dynamicsStepInfo.m_solverInfo,
    *(hkpVelocityAccumulator **)&v4->m_data[32],
    *(hkpVelocityAccumulator **)&v4->m_data[40]);
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "lt";
    v12 = __rdtsc();
    v13 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v10[1] = v13;
  }
  return hkJobQueue::finishJobAndGetNextJob(v5, v4, v4, 0);
}

// File Line: 97
// RVA: 0xD96380
__int64 __fastcall hkCpuSolveConstraintBatchJob(hkpMtThreadStructure *tl, hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *jobInOut)
{
  hkpMtThreadStructure *v3; // rdi
  hkJobQueue::JobQueueEntry *v4; // rbx
  hkJobQueue *v5; // rsi
  _QWORD *v6; // rax
  unsigned __int64 v7; // r8
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  bool v10; // zf
  __int64 v11; // rdx
  hkpVelocityAccumulator *accumulators; // r10
  hkpJacobianSchema *v13; // r9
  hkpSolverElemTemp *elemTemp; // r8
  __int64 v15; // rcx
  _QWORD *v16; // rax
  _QWORD *v17; // r8
  _QWORD *v18; // rcx
  unsigned __int64 v19; // rax
  signed __int64 v20; // rcx

  v3 = tl;
  v4 = jobInOut;
  v5 = jobQueue;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = v6[1];
  v8 = v6;
  if ( v7 < v6[3] )
  {
    *(_QWORD *)v7 = "LtIntegrate";
    *(_QWORD *)(v7 + 16) = "StSolve";
    v9 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v9;
    v8[1] = v7 + 24;
  }
  v10 = *(_DWORD *)&v4->m_data[32] == 0;
  v11 = *(_QWORD *)&v4->m_data[48];
  accumulators = *(hkpVelocityAccumulator **)(v11 + 16);
  v13 = *(hkpJacobianSchema **)(v11 + 24);
  elemTemp = *(hkpSolverElemTemp **)(v11 + 32);
  *(_DWORD *)&v4->m_data[36] = v3->m_world->m_dynamicsStepInfo.m_solverInfo.m_numMicroSteps;
  if ( v10 && !*(_DWORD *)&v4->m_data[40] )
  {
    v15 = ((*(_DWORD *)(v11 + 44) + 15) & 0xFFFFFFF0) >> 4;
    if ( (signed int)v15 > 0 )
    {
      v16 = (_QWORD *)&elemTemp[2].m_impulseApplied;
      do
      {
        *(v16 - 1) = 0i64;
        *v16 = 0i64;
        v16 += 2;
        --v15;
      }
      while ( v15 );
    }
  }
  hkSolveConstraintsByTheSteps(
    &v3->m_world->m_dynamicsStepInfo.m_solverInfo,
    *(_DWORD *)&v4->m_data[32],
    *(_DWORD *)&v4->m_data[40],
    v13,
    accumulators,
    elemTemp);
  v17 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v18 = (_QWORD *)v17[1];
  if ( (unsigned __int64)v18 < v17[3] )
  {
    *v18 = "lt";
    v19 = __rdtsc();
    v20 = (signed __int64)(v18 + 2);
    *(_DWORD *)(v20 - 8) = v19;
    v17[1] = v20;
  }
  return hkJobQueue::finishJobAndGetNextJob(v5, v4, v4, 0);
}

// File Line: 178
// RVA: 0xD964B0
__int64 __fastcall hkCpuSolveIntegrateVelocitiesJob(hkpMtThreadStructure *tl, hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *jobInOut)
{
  hkpMtThreadStructure *v3; // rsi
  hkJobQueue::JobQueueEntry *v4; // rbx
  hkJobQueue *v5; // rdi
  _QWORD *v6; // rax
  unsigned __int64 v7; // r9
  _QWORD *v8; // r8
  unsigned __int64 v9; // rax
  hkpVelocityAccumulator *v10; // r9
  hkpVelocityAccumulator *v11; // r8
  int v12; // edx
  hkpSolverInfo *v13; // rcx
  _QWORD *v14; // r8
  _QWORD *v15; // rcx
  unsigned __int64 v16; // rax
  signed __int64 v17; // rcx
  hkBool outSolveFinished; // [rsp+40h] [rbp+8h]

  v3 = tl;
  v4 = jobInOut;
  v5 = jobQueue;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = v6[1];
  v8 = v6;
  if ( v7 < v6[3] )
  {
    *(_QWORD *)v7 = "LtIntegrate";
    *(_QWORD *)(v7 + 16) = "StIntVel";
    v9 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v9;
    v8[1] = v7 + 24;
  }
  v10 = *(hkpVelocityAccumulator **)&v4->m_data[40];
  v11 = *(hkpVelocityAccumulator **)&v4->m_data[32];
  v12 = *(_DWORD *)&v4->m_data[48];
  v13 = &v3->m_world->m_dynamicsStepInfo.m_solverInfo;
  outSolveFinished.m_bool = 0;
  hkSolveIntegrateVelocitiesByTheSteps(v13, v12, v11, v10, &outSolveFinished);
  v4->m_data[52] = outSolveFinished.m_bool;
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)v14[1];
  if ( (unsigned __int64)v15 < v14[3] )
  {
    *v15 = "lt";
    v16 = __rdtsc();
    v17 = (signed __int64)(v15 + 2);
    *(_DWORD *)(v17 - 8) = v16;
    v14[1] = v17;
  }
  return hkJobQueue::finishJobAndGetNextJob(v5, v4, v4, 0);
}

// File Line: 198
// RVA: 0xD965A0
__int64 __fastcall hkCpuSolveExportResultsJob(hkpMtThreadStructure *tl, hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *jobInOut)
{
  hkpMtThreadStructure *v3; // rsi
  hkJobQueue::JobQueueEntry *v4; // rbx
  hkJobQueue *v5; // rdi
  _QWORD *v6; // rax
  unsigned __int64 v7; // r9
  _QWORD *v8; // r8
  unsigned __int64 v9; // rax
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx

  v3 = tl;
  v4 = jobInOut;
  v5 = jobQueue;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = v6[1];
  v8 = v6;
  if ( v7 < v6[3] )
  {
    *(_QWORD *)v7 = "LtIntegrate";
    *(_QWORD *)(v7 + 16) = "StSolverExport";
    v9 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v9;
    v8[1] = v7 + 24;
  }
  hkExportImpulsesAndRhs(
    &v3->m_world->m_dynamicsStepInfo.m_solverInfo,
    *(hkpSolverElemTemp **)(*(_QWORD *)&v4->m_data[32] + 32i64),
    *(hkpJacobianSchema **)(*(_QWORD *)&v4->m_data[32] + 24i64),
    *(hkpVelocityAccumulator **)(*(_QWORD *)&v4->m_data[32] + 16i64));
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "lt";
    v12 = __rdtsc();
    v13 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v10[1] = v13;
  }
  return hkJobQueue::finishJobAndGetNextJob(v5, v4, v4, 0);
}


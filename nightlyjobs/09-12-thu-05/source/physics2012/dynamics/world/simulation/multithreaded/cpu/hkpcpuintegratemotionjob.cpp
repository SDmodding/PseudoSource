// File Line: 24
// RVA: 0xD96680
__int64 __fastcall hkCpuIntegrateMotionJob(
        hkpMtThreadStructure *tl,
        hkJobQueue *jobQueue,
        hkJobQueue::JobQueueEntry *jobInOut)
{
  _QWORD *Value; // rax
  unsigned __int64 v7; // r8
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  __int64 v10; // rcx
  __int64 v11; // rdx
  unsigned int numMotions; // edi
  __int64 v13; // r8
  hkpMotion *const *v14; // rsi
  hkpWorld *m_world; // rcx
  hkpVelocityAccumulator *v16; // r8
  hkpWorldDynamicsStepInfo *p_m_dynamicsStepInfo; // rdx
  int v18; // eax
  _QWORD *v19; // r8
  _QWORD *v20; // rcx
  unsigned __int64 v21; // rax
  _QWORD *v22; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = Value[1];
  v8 = Value;
  if ( v7 < Value[3] )
  {
    *(_QWORD *)v7 = "LtIntegrate";
    *(_QWORD *)(v7 + 16) = "StIntegrateMotions";
    v9 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v9;
    v8[1] = v7 + 24;
  }
  v10 = *(unsigned __int16 *)&jobInOut->m_data[74];
  v11 = *(_QWORD *)&jobInOut->m_data[16];
  numMotions = *(unsigned __int16 *)&jobInOut->m_data[72];
  v13 = (int)v10 + 1;
  v14 = (hkpMotion *const *)(*(_QWORD *)(v11 + 120) + 8 * v10);
  m_world = tl->m_world;
  v16 = (hkpVelocityAccumulator *)(*(_QWORD *)(v11 + 64) + (v13 << 7));
  p_m_dynamicsStepInfo = &tl->m_world->m_dynamicsStepInfo;
  if ( jobInOut->m_data[80] )
    v18 = hkRigidMotionUtilApplyForcesAndStep(
            &m_world->m_dynamicsStepInfo.m_solverInfo,
            &p_m_dynamicsStepInfo->m_stepInfo,
            &m_world->m_dynamicsStepInfo.m_solverInfo.m_globalAccelerationPerStep,
            v14,
            numMotions,
            336);
  else
    v18 = hkRigidMotionUtilApplyAccumulators(
            &m_world->m_dynamicsStepInfo.m_solverInfo,
            &p_m_dynamicsStepInfo->m_stepInfo,
            v16,
            v14,
            numMotions,
            336);
  *(_DWORD *)&jobInOut->m_data[76] = v18;
  hkpEntityAabbUtil::entityBatchRecalcAabb(tl->m_world->m_collisionInput, (hkpEntity *const *)v14, numMotions);
  v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v20 = (_QWORD *)v19[1];
  if ( (unsigned __int64)v20 < v19[3] )
  {
    *v20 = "lt";
    v21 = __rdtsc();
    v22 = v20 + 2;
    *((_DWORD *)v22 - 2) = v21;
    v19[1] = v22;
  }
  return hkJobQueue::finishJobAndGetNextJob(jobQueue, jobInOut, jobInOut, WAIT_FOR_NEXT_JOB);
}


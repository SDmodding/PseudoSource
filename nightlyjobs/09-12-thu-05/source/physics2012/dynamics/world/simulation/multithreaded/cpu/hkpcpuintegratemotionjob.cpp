// File Line: 24
// RVA: 0xD96680
__int64 __fastcall hkCpuIntegrateMotionJob(hkpMtThreadStructure *tl, hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *jobInOut)
{
  hkpMtThreadStructure *v3; // r14
  hkJobQueue::JobQueueEntry *v4; // rbx
  hkJobQueue *v5; // rbp
  _QWORD *v6; // rax
  unsigned __int64 v7; // r8
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  __int64 v10; // rcx
  __int64 v11; // rdx
  unsigned int v12; // edi
  __int64 v13; // r8
  hkpMotion *const *v14; // rsi
  hkpWorld *v15; // rcx
  hkpVelocityAccumulator *v16; // r8
  hkStepInfo *v17; // rdx
  int v18; // eax
  _QWORD *v19; // r8
  _QWORD *v20; // rcx
  unsigned __int64 v21; // rax
  signed __int64 v22; // rcx
  int numMotions; // [rsp+20h] [rbp-18h]

  v3 = tl;
  v4 = jobInOut;
  v5 = jobQueue;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = v6[1];
  v8 = v6;
  if ( v7 < v6[3] )
  {
    *(_QWORD *)v7 = "LtIntegrate";
    *(_QWORD *)(v7 + 16) = "StIntegrateMotions";
    v9 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v9;
    v8[1] = v7 + 24;
  }
  v10 = *(unsigned __int16 *)&v4->m_data[74];
  v11 = *(_QWORD *)&v4->m_data[16];
  v12 = *(unsigned __int16 *)&v4->m_data[72];
  numMotions = *(unsigned __int16 *)&v4->m_data[72];
  v13 = (signed int)v10 + 1;
  v14 = (hkpMotion *const *)(*(_QWORD *)(v11 + 120) + 8 * v10);
  v15 = v3->m_world;
  v16 = (hkpVelocityAccumulator *)(*(_QWORD *)(v11 + 64) + (v13 << 7));
  v17 = &v3->m_world->m_dynamicsStepInfo.m_stepInfo;
  if ( v4->m_data[80] )
    v18 = hkRigidMotionUtilApplyForcesAndStep(
            &v15->m_dynamicsStepInfo.m_solverInfo,
            v17,
            &v15->m_dynamicsStepInfo.m_solverInfo.m_globalAccelerationPerStep,
            v14,
            numMotions,
            336);
  else
    v18 = hkRigidMotionUtilApplyAccumulators(&v15->m_dynamicsStepInfo.m_solverInfo, v17, v16, v14, numMotions, 336);
  *(_DWORD *)&v4->m_data[76] = v18;
  hkpEntityAabbUtil::entityBatchRecalcAabb(
    (hkpCollisionInput *)&v3->m_world->m_collisionInput->m_dispatcher,
    (hkpEntity *const *)v14,
    v12);
  v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v20 = (_QWORD *)v19[1];
  if ( (unsigned __int64)v20 < v19[3] )
  {
    *v20 = "lt";
    v21 = __rdtsc();
    v22 = (signed __int64)(v20 + 2);
    *(_DWORD *)(v22 - 8) = v21;
    v19[1] = v22;
  }
  return hkJobQueue::finishJobAndGetNextJob(v5, v4, v4, 0);
}


// File Line: 23
// RVA: 0xD95C70
__int64 __fastcall hkCpuBuildAccumulatorsJob(
        hkpMtThreadStructure *tl,
        hkJobQueue *jobQueue,
        hkJobQueue::JobQueueEntry *nextJobOut)
{
  _QWORD *Value; // rax
  unsigned __int64 v7; // r9
  _QWORD *v8; // r8
  unsigned __int64 v9; // rax
  _QWORD *v10; // r8
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = Value[1];
  v8 = Value;
  if ( v7 < Value[3] )
  {
    *(_QWORD *)v7 = "LtIntegrate";
    *(_QWORD *)(v7 + 16) = "StBuildAccumulators";
    v9 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v9;
    v8[1] = v7 + 24;
  }
  hkRigidMotionUtilApplyForcesAndBuildAccumulators(
    &tl->m_collisionInput.m_stepInfo,
    (hkpMotion *const *)(*(_QWORD *)&nextJobOut->m_data[32] + 8i64 * *(unsigned __int16 *)&nextJobOut->m_data[40]),
    *(unsigned __int16 *)&nextJobOut->m_data[42],
    336,
    (hkpVelocityAccumulator *)(*(_QWORD *)(*(_QWORD *)&nextJobOut->m_data[16] + 64i64)
                             + ((*(unsigned __int16 *)&nextJobOut->m_data[40] + 1i64) << 7)));
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "lt";
    v12 = __rdtsc();
    v13 = v11 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v10[1] = v13;
  }
  return hkJobQueue::finishJobAndGetNextJob(jobQueue, nextJobOut, nextJobOut, WAIT_FOR_NEXT_JOB);
}


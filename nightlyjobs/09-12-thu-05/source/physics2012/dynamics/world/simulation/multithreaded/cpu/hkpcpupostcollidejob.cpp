// File Line: 23
// RVA: 0xD971E0
__int64 __fastcall hkCpuPostCollideJob(
        hkpMtThreadStructure *tl,
        hkJobQueue *jobQueue,
        hkJobQueue::JobQueueEntry *nextJobOut)
{
  hkJobQueue *v5; // r13
  _QWORD *Value; // r9
  unsigned __int64 v7; // r8
  unsigned __int64 v8; // rax
  hkpSimulationIsland *v9; // rbp
  int v10; // ebx
  int v11; // r14d
  hkpPhysicsCommand *v12; // rdi
  int m_maxSizeOfSchema; // ecx
  _QWORD *v14; // rax
  unsigned __int64 v15; // rdx
  __int64 v16; // rbx
  int v17; // edi
  __int64 v18; // rbx
  _QWORD **v19; // rax
  _QWORD *v20; // rax
  _QWORD *v21; // rcx
  _QWORD *v22; // r8
  unsigned __int64 v23; // rax
  _QWORD *v24; // rcx

  v5 = jobQueue;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = Value[1];
  if ( v7 < Value[3] )
  {
    *(_QWORD *)v7 = "LtNarrowPhase";
    *(_QWORD *)(v7 + 16) = "StPostCollide";
    v8 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v8;
    Value[1] = v7 + 24;
  }
  v9 = *(hkpSimulationIsland **)&nextJobOut->m_data[8];
  hkpWorld::lockIslandForConstraintUpdate(tl->m_world, v9);
  v10 = 0;
  v11 = **(_DWORD **)&nextJobOut->m_data[32];
  if ( v11 > 0 )
  {
    do
    {
      if ( v10 < v11 - 4 )
        _mm_prefetch(*(const char **)(*(_QWORD *)&nextJobOut->m_data[32] + 8i64 * (__int16)(v10 + 4) + 32), 0);
      v12 = *(hkpPhysicsCommand **)(*(_QWORD *)&nextJobOut->m_data[32] + 8i64 * (__int16)v10 + 32);
      m_maxSizeOfSchema = *(_DWORD *)&v12->m_type.m_storage;
      if ( v9->m_constraintInfo.m_maxSizeOfSchema > *(_DWORD *)&v12->m_type.m_storage )
        m_maxSizeOfSchema = v9->m_constraintInfo.m_maxSizeOfSchema;
      v9->m_constraintInfo.m_maxSizeOfSchema = m_maxSizeOfSchema;
      v9->m_constraintInfo.m_sizeOfSchemas += *(_DWORD *)&v12[4].m_type.m_storage;
      v9->m_constraintInfo.m_numSolverResults += *(_DWORD *)&v12[8].m_type.m_storage;
      v9->m_constraintInfo.m_numSolverElemTemps += *(_DWORD *)&v12[12].m_type.m_storage;
      if ( *(_DWORD *)&v12[20].m_type.m_storage )
      {
        v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v15 = v14[1];
        if ( v15 < v14[3] )
        {
          *(_QWORD *)v15 = "MinumCmds";
          *(float *)(v15 + 8) = (float)(*(_DWORD *)&v12[20].m_type.m_storage >> 4);
          v14[1] = v15 + 16;
        }
        hkPhysicsCommandMachineProcess(
          tl->m_world,
          &v12[*(unsigned int *)&v12[16].m_type.m_storage + 16],
          *(_DWORD *)&v12[20].m_type.m_storage);
      }
      ++v10;
    }
    while ( v10 < v11 );
    v5 = jobQueue;
  }
  v16 = *(_QWORD *)&nextJobOut->m_data[32];
  v17 = *(_DWORD *)(v16 + 24);
  if ( v17 )
  {
    v18 = *(_QWORD *)(v16 + 16);
    v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, __int64, _QWORD))(*v19[11] + 16i64))(v19[11], v18, (unsigned int)(16 * v17));
  }
  hkpAgentSectorHeader::deallocate(*(hkpAgentSectorHeader **)&nextJobOut->m_data[32]);
  hkpWorld::unlockIslandForConstraintUpdate(tl->m_world, v9);
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  v22 = v20;
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "lt";
    v23 = __rdtsc();
    v24 = v21 + 2;
    *((_DWORD *)v24 - 2) = v23;
    v22[1] = v24;
  }
  if ( v5 )
    return hkJobQueue::finishJobAndGetNextJob(v5, nextJobOut, nextJobOut, WAIT_FOR_NEXT_JOB);
  else
    return 2i64;
}


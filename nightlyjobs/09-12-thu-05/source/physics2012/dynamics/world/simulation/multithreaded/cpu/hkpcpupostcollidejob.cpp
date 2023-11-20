// File Line: 23
// RVA: 0xD971E0
__int64 __fastcall hkCpuPostCollideJob(hkpMtThreadStructure *tl, hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  hkpMtThreadStructure *v3; // r15
  hkJobQueue::JobQueueEntry *v4; // rsi
  hkJobQueue *v5; // r13
  _QWORD *v6; // r9
  unsigned __int64 v7; // r8
  unsigned __int64 v8; // rax
  hkpSimulationIsland *v9; // rbp
  int v10; // ebx
  int v11; // er14
  hkpPhysicsCommand *v13; // rdi
  int v14; // ecx
  _QWORD *v15; // rax
  unsigned __int64 v16; // rdx
  __int64 v17; // rbx
  int v18; // edi
  __int64 v19; // rbx
  _QWORD **v20; // rax
  _QWORD *v21; // rax
  _QWORD *v22; // rcx
  _QWORD *v23; // r8
  unsigned __int64 v24; // rax
  signed __int64 v25; // rcx
  __int64 result; // rax
  hkJobQueue *v27; // [rsp+58h] [rbp+10h]

  v27 = jobQueue;
  v3 = tl;
  v4 = nextJobOut;
  v5 = jobQueue;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = v6[1];
  if ( v7 < v6[3] )
  {
    *(_QWORD *)v7 = "LtNarrowPhase";
    *(_QWORD *)(v7 + 16) = "StPostCollide";
    v8 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v8;
    v6[1] = v7 + 24;
  }
  v9 = *(hkpSimulationIsland **)&v4->m_data[8];
  hkpWorld::lockIslandForConstraintUpdate(v3->m_world, *(hkpSimulationIsland **)&v4->m_data[8]);
  v10 = 0;
  v11 = **(_DWORD **)&v4->m_data[32];
  if ( v11 > 0 )
  {
    do
    {
      if ( v10 < v11 - 4 )
      {
        _RCX = *(_QWORD *)(*(_QWORD *)&v4->m_data[32] + 8i64 * (signed __int16)(v10 + 4) + 32);
        __asm { prefetchnta byte ptr [rcx]; Prefetch to L1 cache }
      }
      v13 = *(hkpPhysicsCommand **)(*(_QWORD *)&v4->m_data[32] + 8i64 * (signed __int16)v10 + 32);
      v14 = *(_DWORD *)&v13->m_type.m_storage;
      if ( v9->m_constraintInfo.m_maxSizeOfSchema > *(_DWORD *)&v13->m_type.m_storage )
        v14 = v9->m_constraintInfo.m_maxSizeOfSchema;
      v9->m_constraintInfo.m_maxSizeOfSchema = v14;
      v9->m_constraintInfo.m_sizeOfSchemas += *(_DWORD *)&v13[4].m_type.m_storage;
      v9->m_constraintInfo.m_numSolverResults += *(_DWORD *)&v13[8].m_type.m_storage;
      v9->m_constraintInfo.m_numSolverElemTemps += *(_DWORD *)&v13[12].m_type.m_storage;
      if ( *(_DWORD *)&v13[20].m_type.m_storage )
      {
        v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v16 = v15[1];
        if ( v16 < v15[3] )
        {
          *(_QWORD *)v16 = "MinumCmds";
          *(float *)(v16 + 8) = (float)(signed int)(*(_DWORD *)&v13[20].m_type.m_storage >> 4);
          v15[1] = v16 + 16;
        }
        hkPhysicsCommandMachineProcess(
          v3->m_world,
          &v13[*(unsigned int *)&v13[16].m_type.m_storage + 16],
          *(_DWORD *)&v13[20].m_type.m_storage);
      }
      ++v10;
    }
    while ( v10 < v11 );
    v5 = v27;
  }
  v17 = *(_QWORD *)&v4->m_data[32];
  v18 = *(_DWORD *)(v17 + 24);
  if ( v18 )
  {
    v19 = *(_QWORD *)(v17 + 16);
    v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, __int64, _QWORD))(*v20[11] + 16i64))(v20[11], v19, (unsigned int)(16 * v18));
  }
  hkpAgentSectorHeader::deallocate(*(hkpAgentSectorHeader **)&v4->m_data[32]);
  hkpWorld::unlockIslandForConstraintUpdate(v3->m_world, v9);
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  v23 = v21;
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "lt";
    v24 = __rdtsc();
    v25 = (signed __int64)(v22 + 2);
    *(_DWORD *)(v25 - 8) = v24;
    v23[1] = v25;
  }
  if ( v5 )
    result = hkJobQueue::finishJobAndGetNextJob(v5, v4, v4, 0);
  else
    result = 2i64;
  return result;
}


// File Line: 27
// RVA: 0xD967D0
void __fastcall hkCpuSplitSimulationIslandJobImpl(hkpSimulationIsland *island, hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *newSplitIslands)
{
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *v2; // rbx
  hkpSimulationIsland *v3; // rdi
  hkArray<hkpEntity *,hkContainerHeapAllocator> oldEntitiesOut; // [rsp+20h] [rbp-18h]

  *((_BYTE *)island + 49) &= 0xFCu;
  v2 = newSplitIslands;
  v3 = island;
  oldEntitiesOut.m_capacityAndFlags = 2147483648;
  oldEntitiesOut.m_data = 0i64;
  oldEntitiesOut.m_size = 0;
  hkpSimulationIsland::markForWrite(island);
  hkpWorldOperationUtil::splitSimulationIsland(v3, v3->m_world, v2, &oldEntitiesOut);
}

// File Line: 63
// RVA: 0xD96830
__int64 __fastcall hkCpuSplitSimulationIslandJob(hkpMtThreadStructure *tl, hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *jobInOut)
{
  hkJobQueue::JobQueueEntry *v3; // rbx
  hkJobQueue *v4; // rdi
  _QWORD *v5; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  _QWORD *v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx

  v3 = jobInOut;
  v4 = jobQueue;
  v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = (_QWORD *)v5[1];
  if ( (unsigned __int64)v6 < v5[3] )
  {
    *v6 = "TtSplitIsle";
    v7 = __rdtsc();
    v8 = (signed __int64)(v6 + 2);
    *(_DWORD *)(v8 - 8) = v7;
    v5[1] = v8;
  }
  hkCpuSplitSimulationIslandJobImpl(
    *(hkpSimulationIsland **)&v3->m_data[8],
    (hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *)(*(_QWORD *)&v3->m_data[16] + 136i64));
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "Et";
    v11 = __rdtsc();
    v12 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v9[1] = v12;
  }
  return hkJobQueue::finishJobAndGetNextJob(v4, v3, v3, 0);
}


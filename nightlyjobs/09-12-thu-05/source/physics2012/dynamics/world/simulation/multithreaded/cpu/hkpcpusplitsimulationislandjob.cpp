// File Line: 27
// RVA: 0xD967D0
void __fastcall hkCpuSplitSimulationIslandJobImpl(
        hkpSimulationIsland *island,
        hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *newSplitIslands)
{
  hkArray<hkpEntity *,hkContainerHeapAllocator> oldEntitiesOut; // [rsp+20h] [rbp-18h] BYREF

  *((_BYTE *)island + 49) &= 0xFCu;
  oldEntitiesOut.m_capacityAndFlags = 0x80000000;
  oldEntitiesOut.m_data = 0i64;
  oldEntitiesOut.m_size = 0;
  hkpSimulationIsland::markForWrite(island);
  hkpWorldOperationUtil::splitSimulationIsland(
    (hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *)island,
    (hkArray<hkpEntity *,hkContainerHeapAllocator> *)island->m_world,
    newSplitIslands,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&oldEntitiesOut);
}

// File Line: 63
// RVA: 0xD96830
__int64 __fastcall hkCpuSplitSimulationIslandJob(
        hkpMtThreadStructure *tl,
        hkJobQueue *jobQueue,
        hkJobQueue::JobQueueEntry *jobInOut)
{
  _QWORD *Value; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v6 < Value[3] )
  {
    *v6 = "TtSplitIsle";
    v7 = __rdtsc();
    v8 = v6 + 2;
    *((_DWORD *)v8 - 2) = v7;
    Value[1] = v8;
  }
  hkCpuSplitSimulationIslandJobImpl(
    *(hkpSimulationIsland **)&jobInOut->m_data[8],
    (hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *)(*(_QWORD *)&jobInOut->m_data[16] + 136i64));
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "Et";
    v11 = __rdtsc();
    v12 = v10 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v9[1] = v12;
  }
  return hkJobQueue::finishJobAndGetNextJob(jobQueue, jobInOut, jobInOut, WAIT_FOR_NEXT_JOB);
}


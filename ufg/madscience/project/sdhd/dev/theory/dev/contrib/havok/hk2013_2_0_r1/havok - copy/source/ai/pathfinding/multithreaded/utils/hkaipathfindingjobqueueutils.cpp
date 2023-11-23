// File Line: 23
// RVA: 0xBD8980
__int64 __fastcall hkaiPathfindingJobQueueUtils::popPathfindingJob(
        hkJobQueue *queue,
        hkJobQueue::DynamicData *data,
        hkJobQueue::JobQueueEntry *jobIn,
        hkJobQueue::JobQueueEntry *jobOut)
{
  hkJobQueue::JobQueueEntry *v4; // rax
  __int64 v5; // rcx
  hkJob v6; // xmm0

  v4 = jobIn;
  if ( (((unsigned __int8)jobOut | (unsigned __int8)jobIn) & 0xF) != 0 )
  {
    memmove(jobOut, jobIn, 0x100ui64);
    return 0i64;
  }
  else
  {
    v5 = 2i64;
    do
    {
      v6 = v4->hkJob;
      jobOut = (hkJobQueue::JobQueueEntry *)((char *)jobOut + 128);
      v4 = (hkJobQueue::JobQueueEntry *)((char *)v4 + 128);
      *((hkJob *)jobOut - 8) = v6;
      *(_OWORD *)&jobOut[-1].m_data[128] = *(_OWORD *)&v4[-1].m_data[128];
      *(_OWORD *)&jobOut[-1].m_data[144] = *(_OWORD *)&v4[-1].m_data[144];
      *(_OWORD *)&jobOut[-1].m_data[160] = *(_OWORD *)&v4[-1].m_data[160];
      *(_OWORD *)&jobOut[-1].m_data[176] = *(_OWORD *)&v4[-1].m_data[176];
      *(_OWORD *)&jobOut[-1].m_data[192] = *(_OWORD *)&v4[-1].m_data[192];
      *(_OWORD *)&jobOut[-1].m_data[208] = *(_OWORD *)&v4[-1].m_data[208];
      *(_OWORD *)&jobOut[-1].m_data[224] = *(_OWORD *)&v4[-1].m_data[224];
      --v5;
    }
    while ( v5 );
    return 0i64;
  }
}

// File Line: 30
// RVA: 0xBD8A20
__int64 __fastcall hkaiPathfindingJobQueueUtils::finishPathfindingJob(
        hkJobQueue *queue,
        hkJobQueue::DynamicData *data,
        hkJobQueue::JobQueueEntry *jobIn,
        hkJobQueue::JobQueueEntryInput *newJobCreatedOut)
{
  volatile signed __int32 *v4; // rax
  hkSemaphore *v5; // rcx

  if ( jobIn->m_jobSubType <= 2u )
  {
    v4 = *(volatile signed __int32 **)&jobIn->m_data[8];
    if ( v4 )
      _InterlockedExchangeAdd(v4, 1u);
    v5 = *(hkSemaphore **)jobIn->m_data;
    if ( v5 )
      hkSemaphore::release(v5, 1);
  }
  return 1i64;
}

// File Line: 61
// RVA: 0xBD8A60
void __fastcall hkaiPathfindingJobQueueUtils::registerWithJobQueue(hkJobQueue *queue)
{
  hkJobQueue::hkJobHandlerFuncs v1; // [rsp+20h] [rbp-48h]
  hkJobQueue::hkJobHandlerFuncs v2; // [rsp+40h] [rbp-28h] BYREF

  v1.m_numProcessJobFuncs = 3;
  v1.m_popJobFunc = (hkJobQueue::JobPopFuncResult (__fastcall *)(hkJobQueue *, hkJobQueue::DynamicData *, hkJobQueue::JobQueueEntry *, hkJobQueue::JobQueueEntry *))hkaiPathfindingJobQueueUtils::popPathfindingJob;
  v1.m_finishJobFunc = (hkJobQueue::JobCreationStatus (__fastcall *)(hkJobQueue *, hkJobQueue::DynamicData *, hkJobQueue::JobQueueEntry *, hkJobQueue::JobQueueEntryInput *))hkaiPathfindingJobQueueUtils::finishPathfindingJob;
  v1.m_processJobFuncs = s_PathfindingProcessFuncs;
  s_PathfindingProcessFuncs[0] = hkaiProcessDirectedGraphAStarJob;
  v2 = v1;
  qword_1424A3EA8 = (__int64)hkaiProcessNavMeshAStarJob;
  qword_1424A3EB0 = (__int64)hkaiProcessNavMeshLineOfSightJob;
  hkJobQueue::registerJobHandler(queue, HK_JOB_TYPE_AI_PATHFINDING, &v2);
}


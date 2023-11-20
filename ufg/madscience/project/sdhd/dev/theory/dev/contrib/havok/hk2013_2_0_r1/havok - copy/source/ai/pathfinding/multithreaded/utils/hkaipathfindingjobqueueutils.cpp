// File Line: 23
// RVA: 0xBD8980
__int64 __fastcall hkaiPathfindingJobQueueUtils::popPathfindingJob(hkJobQueue *queue, hkJobQueue::DynamicData *data, hkJobQueue::JobQueueEntry *jobIn, hkJobQueue::JobQueueEntry *jobOut)
{
  hkJobQueue::JobQueueEntry *v4; // rax
  signed __int64 v5; // rcx
  hkJob v6; // xmm0
  __int64 result; // rax

  v4 = jobIn;
  if ( ((unsigned __int8)jobOut | (unsigned __int8)jobIn) & 0xF )
  {
    memmove(jobOut, jobIn, 0x100ui64);
    result = 0i64;
  }
  else
  {
    v5 = 2i64;
    do
    {
      v6 = v4->0;
      jobOut = (hkJobQueue::JobQueueEntry *)((char *)jobOut + 128);
      v4 = (hkJobQueue::JobQueueEntry *)((char *)v4 + 128);
      *(hkJob *)&jobOut[-1].m_data[112] = v6;
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
    result = 0i64;
  }
  return result;
}

// File Line: 30
// RVA: 0xBD8A20
signed __int64 __fastcall hkaiPathfindingJobQueueUtils::finishPathfindingJob(hkJobQueue *queue, hkJobQueue::DynamicData *data, hkJobQueue::JobQueueEntry *jobIn, hkJobQueue::JobQueueEntryInput *newJobCreatedOut)
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
  __int128 v1; // ST30_16
  __int128 v2; // [rsp+20h] [rbp-48h]
  __int128 v3; // [rsp+40h] [rbp-28h]
  __int128 v4; // [rsp+50h] [rbp-18h]

  DWORD2(v2) = 3;
  *(_QWORD *)&v1 = hkaiPathfindingJobQueueUtils::popPathfindingJob;
  *((_QWORD *)&v1 + 1) = hkaiPathfindingJobQueueUtils::finishPathfindingJob;
  *(_QWORD *)&v2 = s_PathfindingProcessFuncs;
  s_PathfindingProcessFuncs[0] = hkaiProcessDirectedGraphAStarJob;
  v4 = v1;
  qword_1424A3EA8 = (__int64)hkaiProcessNavMeshAStarJob;
  v3 = v2;
  qword_1424A3EB0 = (__int64)hkaiProcessNavMeshLineOfSightJob;
  hkJobQueue::registerJobHandler(queue, HK_JOB_TYPE_AI_PATHFINDING, (hkJobQueue::hkJobHandlerFuncs *)&v3);
}


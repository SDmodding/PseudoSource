// File Line: 20
// RVA: 0xBD8820
__int64 __fastcall hkaiLocalSteeringJobQueueUtils::popPathfindingJob(hkJobQueue *queue, hkJobQueue::DynamicData *data, hkJobQueue::JobQueueEntry *jobIn, hkJobQueue::JobQueueEntry *jobOut)
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

// File Line: 27
// RVA: 0xBD88C0
signed __int64 __fastcall hkaiLocalSteeringJobQueueUtils::finishPathfindingJob(hkJobQueue *queue, hkJobQueue::DynamicData *data, hkJobQueue::JobQueueEntry *jobIn, hkJobQueue::JobQueueEntryInput *newJobCreatedOut)
{
  volatile signed __int32 *v4; // rax
  hkSemaphore *v5; // rcx

  if ( jobIn->m_jobSubType <= 1u )
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

// File Line: 57
// RVA: 0xBD8900
void __fastcall hkaiLocalSteeringJobQueueUtils::registerWithJobQueue(hkJobQueue *queue)
{
  __int128 v1; // ST30_16
  __int128 v2; // [rsp+20h] [rbp-48h]
  __int128 v3; // [rsp+40h] [rbp-28h]
  __int128 v4; // [rsp+50h] [rbp-18h]

  DWORD2(v2) = 2;
  *(_QWORD *)&v1 = hkaiLocalSteeringJobQueueUtils::popPathfindingJob;
  *((_QWORD *)&v1 + 1) = hkaiLocalSteeringJobQueueUtils::finishPathfindingJob;
  *(_QWORD *)&v2 = s_localSteeringProcessFuncs;
  s_localSteeringProcessFuncs[0] = hkaiProcessAvoidanceSolverJob;
  v4 = v1;
  qword_1424A3E98 = (__int64)hkaiProcessBehaviorCalcVelocitiesJob;
  v3 = v2;
  hkJobQueue::registerJobHandler(queue, HK_JOB_TYPE_AI_LOCAL_STEERING, (hkJobQueue::hkJobHandlerFuncs *)&v3);
}


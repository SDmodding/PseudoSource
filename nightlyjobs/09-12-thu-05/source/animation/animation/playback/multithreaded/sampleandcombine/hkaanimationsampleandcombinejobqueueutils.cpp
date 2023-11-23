// File Line: 21
// RVA: 0xB2ED50
__int64 __fastcall hkaAnimationSampleAndCombineJobQueueUtils::popAnimationJob(
        hkJobQueue *queue,
        hkJobQueue::DynamicData *data,
        hkJobQueue::JobQueueEntry *jobIn,
        hkJobQueue::JobQueueEntry *jobOut)
{
  hkJobQueue::JobQueueEntry *v4; // rax
  __int64 v5; // rcx
  hkJob v6; // xmm0

  v4 = jobIn;
  if ( jobIn->m_jobSubType > 2u )
    return 0i64;
  if ( (((unsigned __int8)jobOut | (unsigned __int8)jobIn) & 0xF) != 0 )
  {
    memmove(jobOut, jobIn, 0x100ui64);
    return 0i64;
  }
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

// File Line: 46
// RVA: 0xB2EDF0
__int64 __fastcall hkaAnimationSampleAndCombineJobQueueUtils::finishAnimationJob(
        hkJobQueue *queue,
        hkJobQueue::DynamicData *data,
        hkJobQueue::JobQueueEntry *jobIn,
        hkJobQueue::JobQueueEntryInput *newJobCreated)
{
  return 1i64;
}

// File Line: 72
// RVA: 0xB2EE10
void __fastcall hkaAnimationSampleAndCombineJobQueueUtils::registerWithJobQueue(hkJobQueue *jobQueue)
{
  hkJobQueue::hkJobHandlerFuncs v1; // [rsp+20h] [rbp-48h]
  hkJobQueue::hkJobHandlerFuncs v2; // [rsp+40h] [rbp-28h] BYREF

  v1.m_numProcessJobFuncs = 3;
  v1.m_popJobFunc = (hkJobQueue::JobPopFuncResult (__fastcall *)(hkJobQueue *, hkJobQueue::DynamicData *, hkJobQueue::JobQueueEntry *, hkJobQueue::JobQueueEntry *))hkaAnimationSampleAndCombineJobQueueUtils::popAnimationJob;
  v1.m_finishJobFunc = (hkJobQueue::JobCreationStatus (__fastcall *)(hkJobQueue *, hkJobQueue::DynamicData *, hkJobQueue::JobQueueEntry *, hkJobQueue::JobQueueEntryInput *))hkaAnimationSampleAndCombineJobQueueUtils::finishAnimationJob;
  v1.m_processJobFuncs = s_animationSampleAndCombineProcessFuncs;
  s_animationSampleAndCombineProcessFuncs[0] = hkaCpuSampleAnimationJob;
  v2 = v1;
  qword_1424A0E78 = (__int64)hkaCpuSampleAndCombineJob;
  qword_1424A0E80 = (__int64)hkaCpuQuantizedSampleAndCombineJob;
  hkJobQueue::registerJobHandler(jobQueue, HK_JOB_TYPE_ANIMATION_SAMPLE_AND_COMBINE, &v2);
}


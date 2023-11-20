// File Line: 21
// RVA: 0xB2ED50
__int64 __fastcall hkaAnimationSampleAndCombineJobQueueUtils::popAnimationJob(hkJobQueue *queue, hkJobQueue::DynamicData *data, hkJobQueue::JobQueueEntry *jobIn, hkJobQueue::JobQueueEntry *jobOut)
{
  hkJobQueue::JobQueueEntry *v4; // rax
  signed __int64 v5; // rcx
  hkJob v6; // xmm0

  v4 = jobIn;
  if ( jobIn->m_jobSubType > 2u )
    return 0i64;
  if ( ((unsigned __int8)jobOut | (unsigned __int8)jobIn) & 0xF )
  {
    memmove(jobOut, jobIn, 0x100ui64);
    return 0i64;
  }
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
  return 0i64;
}

// File Line: 46
// RVA: 0xB2EDF0
signed __int64 __fastcall hkaAnimationSampleAndCombineJobQueueUtils::finishAnimationJob(hkJobQueue *queue, hkJobQueue::DynamicData *data, hkJobQueue::JobQueueEntry *jobIn, hkJobQueue::JobQueueEntryInput *newJobCreated)
{
  char v5; // [rsp+18h] [rbp+18h]

  v5 = jobIn->m_jobSubType;
  return 1i64;
}

// File Line: 72
// RVA: 0xB2EE10
void __fastcall hkaAnimationSampleAndCombineJobQueueUtils::registerWithJobQueue(hkJobQueue *jobQueue)
{
  __int128 v1; // ST30_16
  __int128 v2; // [rsp+20h] [rbp-48h]
  __int128 v3; // [rsp+40h] [rbp-28h]
  __int128 v4; // [rsp+50h] [rbp-18h]

  DWORD2(v2) = 3;
  *(_QWORD *)&v1 = hkaAnimationSampleAndCombineJobQueueUtils::popAnimationJob;
  *((_QWORD *)&v1 + 1) = hkaAnimationSampleAndCombineJobQueueUtils::finishAnimationJob;
  *(_QWORD *)&v2 = s_animationSampleAndCombineProcessFuncs;
  s_animationSampleAndCombineProcessFuncs[0] = hkaCpuSampleAnimationJob;
  v4 = v1;
  qword_1424A0E78 = (__int64)hkaCpuSampleAndCombineJob;
  v3 = v2;
  qword_1424A0E80 = (__int64)hkaCpuQuantizedSampleAndCombineJob;
  hkJobQueue::registerJobHandler(
    jobQueue,
    HK_JOB_TYPE_ANIMATION_SAMPLE_AND_COMBINE,
    (hkJobQueue::hkJobHandlerFuncs *)&v3);
}


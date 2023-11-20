// File Line: 23
// RVA: 0xD5EA90
void __fastcall hkpWorld::registerWithJobQueue(hkJobQueue *jobQueue)
{
  hkJobQueue::JobStatus (__fastcall **v1)(hkJobQueue *, hkJobQueue::JobQueueEntry *); // rax
  hkJobQueue *v2; // rbx
  signed __int64 v3; // rdx
  __int128 v4; // ST30_16
  __int128 v5; // [rsp+20h] [rbp-40h]
  __int128 v6; // [rsp+40h] [rbp-20h]
  __int128 v7; // [rsp+50h] [rbp-10h]

  v1 = s_dynamicsProcessFuncs;
  v2 = jobQueue;
  DWORD2(v5) = 17;
  v3 = 2i64;
  *(_QWORD *)&v5 = s_dynamicsProcessFuncs;
  do
  {
    *v1 = hkpMultiThreadedSimulation::processNextJob;
    v1[1] = hkpMultiThreadedSimulation::processNextJob;
    v1[2] = hkpMultiThreadedSimulation::processNextJob;
    v1 += 8;
    *(v1 - 5) = hkpMultiThreadedSimulation::processNextJob;
    *(v1 - 4) = hkpMultiThreadedSimulation::processNextJob;
    *(v1 - 3) = hkpMultiThreadedSimulation::processNextJob;
    *(v1 - 2) = hkpMultiThreadedSimulation::processNextJob;
    *(v1 - 1) = hkpMultiThreadedSimulation::processNextJob;
    --v3;
  }
  while ( v3 );
  *v1 = hkpMultiThreadedSimulation::processNextJob;
  if ( jobQueue->m_hwSetup.m_numCpuThreads < 2 )
    jobQueue->m_hwSetup.m_numCpuThreads = 2;
  hkJobQueue::registerJobWithCpuThread(jobQueue, 0, 12, 1);
  *(_QWORD *)&v4 = hkpJobQueueUtils::popIntegrateJob;
  v6 = v5;
  *((_QWORD *)&v4 + 1) = hkpJobQueueUtils::finishIntegrateJob;
  v7 = v4;
  hkJobQueue::registerJobHandler(v2, 0, (hkJobQueue::hkJobHandlerFuncs *)&v6);
  v6 = v5;
  *(_QWORD *)&v4 = hkpJobQueueUtils::popCollideJob;
  *((_QWORD *)&v4 + 1) = hkpJobQueueUtils::finishCollideJob;
  v7 = v4;
  hkJobQueue::registerJobHandler(v2, HK_JOB_TYPE_COLLIDE, (hkJobQueue::hkJobHandlerFuncs *)&v6);
  v6 = v5;
  v7 = v4;
  hkJobQueue::registerJobHandler(v2, HK_JOB_TYPE_COLLIDE_STATIC_COMPOUND, (hkJobQueue::hkJobHandlerFuncs *)&v6);
  hkpCollisionQueryJobQueueUtils::registerWithJobQueue(v2);
  hkpRayCastQueryJobQueueUtils::registerWithJobQueue(v2);
}


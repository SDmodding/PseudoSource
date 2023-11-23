// File Line: 23
// RVA: 0xD5EA90
void __fastcall hkpWorld::registerWithJobQueue(hkJobQueue *jobQueue)
{
  hkJobQueue::JobStatus (__fastcall **v1)(hkJobQueue *, hkJobQueue::JobQueueEntry *); // rax
  __int64 v3; // rdx
  hkJobQueue::hkJobHandlerFuncs v4; // [rsp+20h] [rbp-40h]
  hkJobQueue::hkJobHandlerFuncs v5; // [rsp+40h] [rbp-20h] BYREF

  v1 = s_dynamicsProcessFuncs;
  v4.m_numProcessJobFuncs = 17;
  v3 = 2i64;
  v4.m_processJobFuncs = s_dynamicsProcessFuncs;
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
  hkJobQueue::registerJobWithCpuThread(jobQueue, HK_JOB_TYPE_DYNAMICS, 12, 1);
  v4.m_popJobFunc = hkpJobQueueUtils::popIntegrateJob;
  v4.m_finishJobFunc = hkpJobQueueUtils::finishIntegrateJob;
  v5 = v4;
  hkJobQueue::registerJobHandler(jobQueue, HK_JOB_TYPE_DYNAMICS, &v5);
  v4.m_popJobFunc = hkpJobQueueUtils::popCollideJob;
  v4.m_finishJobFunc = hkpJobQueueUtils::finishCollideJob;
  v5 = v4;
  hkJobQueue::registerJobHandler(jobQueue, HK_JOB_TYPE_COLLIDE, &v5);
  v5 = v4;
  hkJobQueue::registerJobHandler(jobQueue, HK_JOB_TYPE_COLLIDE_STATIC_COMPOUND, &v5);
  hkpCollisionQueryJobQueueUtils::registerWithJobQueue(jobQueue);
  hkpRayCastQueryJobQueueUtils::registerWithJobQueue(jobQueue);
}


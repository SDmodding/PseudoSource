// File Line: 29
// RVA: 0xCF35B0
void __fastcall hkpCollisionQueryJobQueueUtils::registerWithJobQueue(hkJobQueue *queue)
{
  hkJobQueue::hkJobHandlerFuncs v1; // [rsp+20h] [rbp-48h]
  hkJobQueue::hkJobHandlerFuncs v2; // [rsp+40h] [rbp-28h] BYREF

  v1.m_numProcessJobFuncs = 5;
  v1.m_popJobFunc = hkpCollisionQueryJobQueueUtils::popCollisionJob;
  v1.m_finishJobFunc = hkpCollisionQueryJobQueueUtils::finishCollisionJob;
  v1.m_processJobFuncs = s_collisionQueryProcessFuncs;
  qword_1424A9F60 = (__int64)hkCpuPairLinearCastJob;
  v2 = v1;
  qword_1424A9F68 = (__int64)hkCpuWorldLinearCastJob;
  s_collisionQueryProcessFuncs[0] = hkCpuMoppAabbQueryJob;
  qword_1424A9F50 = (__int64)hkCpuPairGetClosestPointsJob;
  qword_1424A9F58 = (__int64)hkCpuWorldGetClosestPointsJob;
  hkJobQueue::registerJobHandler(queue, HK_JOB_TYPE_COLLISION_QUERY, &v2);
}

// File Line: 59
// RVA: 0xCF3660
void __fastcall hkpRayCastQueryJobQueueUtils::registerWithJobQueue(hkJobQueue *queue)
{
  hkJobQueue::hkJobHandlerFuncs v1; // [rsp+20h] [rbp-48h]
  hkJobQueue::hkJobHandlerFuncs v2; // [rsp+40h] [rbp-28h] BYREF

  v1.m_numProcessJobFuncs = 2;
  v1.m_popJobFunc = hkpRayCastQueryJobQueueUtils::popRayCastQueryJob;
  v1.m_finishJobFunc = hkpRayCastQueryJobQueueUtils::finishRayCastQueryJob;
  v1.m_processJobFuncs = s_raycastQueryProcessFuncs;
  s_raycastQueryProcessFuncs[0] = hkCpuShapeRayCastJob;
  v2 = v1;
  qword_1424A9F78 = (__int64)hkCpuWorldRayCastJob;
  hkJobQueue::registerJobHandler(queue, HK_JOB_TYPE_RAYCAST_QUERY, &v2);
}


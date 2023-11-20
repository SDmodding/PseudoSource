// File Line: 29
// RVA: 0xCF35B0
void __fastcall hkpCollisionQueryJobQueueUtils::registerWithJobQueue(hkJobQueue *queue)
{
  __int128 v1; // ST30_16
  __int128 v2; // [rsp+20h] [rbp-48h]
  __int128 v3; // [rsp+40h] [rbp-28h]
  __int128 v4; // [rsp+50h] [rbp-18h]

  DWORD2(v2) = 5;
  *(_QWORD *)&v1 = hkpCollisionQueryJobQueueUtils::popCollisionJob;
  *((_QWORD *)&v1 + 1) = hkpCollisionQueryJobQueueUtils::finishCollisionJob;
  *(_QWORD *)&v2 = s_collisionQueryProcessFuncs;
  qword_1424A9F60 = (__int64)hkCpuPairLinearCastJob;
  v4 = v1;
  qword_1424A9F68 = (__int64)hkCpuWorldLinearCastJob;
  v3 = v2;
  s_collisionQueryProcessFuncs[0] = hkCpuMoppAabbQueryJob;
  qword_1424A9F50 = (__int64)hkCpuPairGetClosestPointsJob;
  qword_1424A9F58 = (__int64)hkCpuWorldGetClosestPointsJob;
  hkJobQueue::registerJobHandler(queue, HK_JOB_TYPE_COLLISION_QUERY, (hkJobQueue::hkJobHandlerFuncs *)&v3);
}

// File Line: 59
// RVA: 0xCF3660
void __fastcall hkpRayCastQueryJobQueueUtils::registerWithJobQueue(hkJobQueue *queue)
{
  __int128 v1; // ST30_16
  __int128 v2; // [rsp+20h] [rbp-48h]
  __int128 v3; // [rsp+40h] [rbp-28h]
  __int128 v4; // [rsp+50h] [rbp-18h]

  DWORD2(v2) = 2;
  *(_QWORD *)&v1 = hkpRayCastQueryJobQueueUtils::popRayCastQueryJob;
  *((_QWORD *)&v1 + 1) = hkpRayCastQueryJobQueueUtils::finishRayCastQueryJob;
  *(_QWORD *)&v2 = s_raycastQueryProcessFuncs;
  s_raycastQueryProcessFuncs[0] = hkCpuShapeRayCastJob;
  v4 = v1;
  qword_1424A9F78 = (__int64)hkCpuWorldRayCastJob;
  v3 = v2;
  hkJobQueue::registerJobHandler(queue, HK_JOB_TYPE_RAYCAST_QUERY, (hkJobQueue::hkJobHandlerFuncs *)&v3);
}


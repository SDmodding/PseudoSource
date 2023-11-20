// File Line: 17
// RVA: 0xF5940
void __fastcall hkaiDynamicNavMeshJobQueueUtils::registerWithJobQueue(hkJobQueue *queue)
{
  __int128 v1; // ST30_16
  __int128 v2; // [rsp+20h] [rbp-48h]
  __int128 v3; // [rsp+40h] [rbp-28h]
  __int128 v4; // [rsp+50h] [rbp-18h]

  DWORD2(v2) = 1;
  *(_QWORD *)&v1 = hkaiDynamicNavMeshJobQueueUtils::popAiJob;
  *((_QWORD *)&v1 + 1) = hkaiDynamicNavMeshJobQueueUtils::finishAiJob;
  *(_QWORD *)&v2 = s_dynamicNavMeshProcessFuncs;
  s_dynamicNavMeshProcessFuncs[0] = hkaiProcessNavMeshCutFaceJob;
  v4 = v1;
  v3 = v2;
  hkJobQueue::registerJobHandler(queue, HK_JOB_TYPE_AI_DYNAMIC, (hkJobQueue::hkJobHandlerFuncs *)&v3);
  hkaiPointCloudSilhouetteGenerator::registerMtFunctions();
}


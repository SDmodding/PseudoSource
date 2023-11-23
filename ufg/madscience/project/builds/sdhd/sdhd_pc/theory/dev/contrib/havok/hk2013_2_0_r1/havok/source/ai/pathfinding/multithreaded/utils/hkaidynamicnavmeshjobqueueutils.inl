// File Line: 17
// RVA: 0xF5940
void __fastcall hkaiDynamicNavMeshJobQueueUtils::registerWithJobQueue(hkJobQueue *queue)
{
  hkJobQueue::hkJobHandlerFuncs v1; // [rsp+20h] [rbp-48h]
  hkJobQueue::hkJobHandlerFuncs v2; // [rsp+40h] [rbp-28h] BYREF

  v1.m_numProcessJobFuncs = 1;
  v1.m_popJobFunc = hkaiDynamicNavMeshJobQueueUtils::popAiJob;
  v1.m_finishJobFunc = hkaiDynamicNavMeshJobQueueUtils::finishAiJob;
  v1.m_processJobFuncs = s_dynamicNavMeshProcessFuncs;
  s_dynamicNavMeshProcessFuncs[0] = hkaiProcessNavMeshCutFaceJob;
  v2 = v1;
  hkJobQueue::registerJobHandler(queue, HK_JOB_TYPE_AI_DYNAMIC, &v2);
  hkaiPointCloudSilhouetteGenerator::registerMtFunctions();
}


// File Line: 150
// RVA: 0xE4990
void __fastcall UFG::HavokNavManager::HavokNavManager(UFG::HavokNavManager *this)
{
  UFG::HavokNavManager *v1; // rbx
  hkaiStreamingManager *v2; // rax
  hkaiUFGNavMeshCostModifier *v3; // rax
  hkaiUFGAStarEdgeFilter *v4; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::NavManager::NavManager((UFG::NavManager *)&this->vfptr);
  v1->vfptr = (UFG::NavManagerVtbl *)&UFG::HavokNavManager::`vftable';
  v2 = &v1->m_manager;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  v2->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable';
  *(_DWORD *)&v1->m_manager.m_memSizeAndFlags = 0x1FFFF;
  v2->vfptr = (hkBaseObjectVtbl *)&hkaiStreamingManager::`vftable';
  v1->m_world = 0i64;
  v1->m_cells.m_data = 0i64;
  v1->m_cells.m_size = 0;
  v1->m_cells.m_capacityAndFlags = 2147483648;
  v1->m_StitchInstances.m_data = 0i64;
  v1->m_StitchInstances.m_size = 0;
  v1->m_StitchInstances.m_capacityAndFlags = 2147483648;
  v1->m_listener.m_pntr = 0i64;
  v3 = &v1->m_costModifier;
  v3->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  v3->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable';
  *(_DWORD *)&v1->m_costModifier.m_memSizeAndFlags = 0x1FFFF;
  v3->vfptr = (hkBaseObjectVtbl *)&hkaiAstarCostModifier::`vftable';
  v1->m_costModifier.m_type.m_storage = 1;
  v3->vfptr = (hkBaseObjectVtbl *)&hkaiUFGNavMeshCostModifier::`vftable';
  v4 = &v1->m_edgeFilter;
  v4->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  v4->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable';
  *(_DWORD *)&v1->m_edgeFilter.m_memSizeAndFlags = 0x1FFFF;
  v4->vfptr = (hkBaseObjectVtbl *)&hkaiAstarEdgeFilter::`vftable';
  v1->m_edgeFilter.m_type.m_storage = 1;
  v4->vfptr = (hkBaseObjectVtbl *)&hkaiUFGAStarEdgeFilter::`vftable';
  v1->m_dynamicOutlines.p = 0i64;
  *(_QWORD *)&v1->m_dynamicOutlines.size = 0i64;
  v1->m_dynamicOutlinesAdditionQueue.p = 0i64;
  *(_QWORD *)&v1->m_dynamicOutlinesAdditionQueue.size = 0i64;
  v1->m_dynamicOutlinesDeletionQueue.p = 0i64;
  *(_QWORD *)&v1->m_dynamicOutlinesDeletionQueue.size = 0i64;
  v1->m_dynamicEdges.m_data = 0i64;
  v1->m_dynamicEdges.m_size = 0;
  v1->m_dynamicEdges.m_capacityAndFlags = 2147483648;
  v1->m_dynamicEdgesNew.m_data = 0i64;
  v1->m_dynamicEdgesNew.m_size = 0;
  v1->m_dynamicEdgesNew.m_capacityAndFlags = 2147483648;
  v1->m_aTesselationData.p = 0i64;
  *(_QWORD *)&v1->m_aTesselationData.size = 0i64;
  v1->m_aTmpTesselationData.p = 0i64;
  *(_QWORD *)&v1->m_aTmpTesselationData.size = 0i64;
  UFG::HavokNavManager::Init(v1);
}

// File Line: 155
// RVA: 0xE5DE0
void __fastcall UFG::HavokNavManager::~HavokNavManager(UFG::HavokNavManager *this)
{
  UFG::HavokNavManager *v1; // rbx
  UFG::qVector3 *v2; // rcx
  UFG::qVector3 *v3; // rcx
  int v4; // eax
  int v5; // eax
  UFG::HavokNavDynamicOutline **v6; // rcx
  UFG::HavokNavDynamicOutline **v7; // rcx
  UFG::HavokNavDynamicOutline **v8; // rcx
  hkReferencedObject *v9; // rcx
  int v10; // er8
  int v11; // er8
  hkaiUFGAStarEdgeFilter *v12; // [rsp+58h] [rbp+10h]
  hkaiUFGNavMeshCostModifier *v13; // [rsp+58h] [rbp+10h]
  hkaiStreamingManager *v14; // [rsp+58h] [rbp+10h]

  v1 = this;
  this->vfptr = (UFG::NavManagerVtbl *)&UFG::HavokNavManager::`vftable';
  v2 = this->m_aTmpTesselationData.p;
  if ( v2 )
    operator delete[](v2);
  v1->m_aTmpTesselationData.p = 0i64;
  *(_QWORD *)&v1->m_aTmpTesselationData.size = 0i64;
  v3 = v1->m_aTesselationData.p;
  if ( v3 )
    operator delete[](v3);
  v1->m_aTesselationData.p = 0i64;
  *(_QWORD *)&v1->m_aTesselationData.size = 0i64;
  v1->m_dynamicEdgesNew.m_size = 0;
  v4 = v1->m_dynamicEdgesNew.m_capacityAndFlags;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_dynamicEdgesNew.m_data,
      80 * (v4 & 0x3FFFFFFF));
  v1->m_dynamicEdgesNew.m_data = 0i64;
  v1->m_dynamicEdgesNew.m_capacityAndFlags = 2147483648;
  v1->m_dynamicEdges.m_size = 0;
  v5 = v1->m_dynamicEdges.m_capacityAndFlags;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_dynamicEdges.m_data,
      80 * (v5 & 0x3FFFFFFF));
  v1->m_dynamicEdges.m_data = 0i64;
  v1->m_dynamicEdges.m_capacityAndFlags = 2147483648;
  v6 = v1->m_dynamicOutlinesDeletionQueue.p;
  if ( v6 )
    operator delete[](v6);
  v1->m_dynamicOutlinesDeletionQueue.p = 0i64;
  *(_QWORD *)&v1->m_dynamicOutlinesDeletionQueue.size = 0i64;
  v7 = v1->m_dynamicOutlinesAdditionQueue.p;
  if ( v7 )
    operator delete[](v7);
  v1->m_dynamicOutlinesAdditionQueue.p = 0i64;
  *(_QWORD *)&v1->m_dynamicOutlinesAdditionQueue.size = 0i64;
  v8 = v1->m_dynamicOutlines.p;
  if ( v8 )
    operator delete[](v8);
  v1->m_dynamicOutlines.p = 0i64;
  *(_QWORD *)&v1->m_dynamicOutlines.size = 0i64;
  v12 = &v1->m_edgeFilter;
  v12->vfptr = (hkBaseObjectVtbl *)&hkaiUFGAStarEdgeFilter::`vftable';
  v12->vfptr = (hkBaseObjectVtbl *)&hkaiAstarEdgeFilter::`vftable';
  v12->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable';
  v12->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  v13 = &v1->m_costModifier;
  v13->vfptr = (hkBaseObjectVtbl *)&hkaiAstarCostModifier::`vftable';
  v13->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable';
  v13->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  v9 = (hkReferencedObject *)&v1->m_listener.m_pntr->vfptr;
  if ( v9 )
    hkReferencedObject::removeReference(v9);
  v1->m_listener.m_pntr = 0i64;
  v1->m_StitchInstances.m_size = 0;
  v10 = v1->m_StitchInstances.m_capacityAndFlags;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_StitchInstances.m_data,
      8 * v10);
  v1->m_StitchInstances.m_data = 0i64;
  v1->m_StitchInstances.m_capacityAndFlags = 2147483648;
  v1->m_cells.m_size = 0;
  v11 = v1->m_cells.m_capacityAndFlags;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_cells.m_data,
      8 * v11);
  v1->m_cells.m_data = 0i64;
  v1->m_cells.m_capacityAndFlags = 2147483648;
  v14 = &v1->m_manager;
  v14->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable';
  v14->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  UFG::NavManager::~NavManager((UFG::NavManager *)&v1->vfptr);
}

// File Line: 169
// RVA: 0xEE940
void __fastcall UFG::HavokNavManager::Init(UFG::HavokNavManager *this)
{
  UFG::HavokNavManager *v1; // rbx
  signed __int64 v2; // rdi
  char v3; // dl
  __int64 v4; // rax
  char v5; // cl
  _QWORD **v6; // rax
  hkaiWorld *v7; // rax
  hkaiWorld *v8; // rax
  char v9; // al
  char v10; // dl
  __int64 v11; // rax
  char v12; // cl
  _QWORD **v13; // rax
  hkJobQueue *v14; // rax
  hkJobQueue *v15; // rax
  char v16; // al
  char v17; // dl
  __int64 v18; // rax
  char v19; // cl
  _QWORD **v20; // rax
  HavokJobMemoryPoolTagger *v21; // rax
  char v22; // al
  char v23; // dl
  __int64 v24; // rax
  char v25; // cl
  char v26; // al
  char v27; // dl
  __int64 v28; // rax
  char v29; // cl
  _QWORD **v30; // rax
  __int64 v31; // rsi
  hkReferencedObject *v32; // rcx
  UFG::HavokNavManager::AiListener *v33; // rdx
  hkaiWorld::Listener *v34; // rdx
  char v35; // al
  unsigned __int64 v36; // rax
  char *v37; // rax
  char *v38; // rdi
  unsigned int i; // er9
  unsigned __int64 v40; // rax
  char *v41; // rax
  char *v42; // rdi
  unsigned int j; // er9
  unsigned __int64 v44; // rax
  char *v45; // rax
  char *v46; // rdi
  unsigned int k; // er9
  int v48; // edi
  int v49; // eax
  int v50; // eax
  hkJobQueueHwSetup v51; // [rsp+30h] [rbp-1F8h]
  int v52; // [rsp+50h] [rbp-1D8h]
  __int64 v53; // [rsp+58h] [rbp-1D0h]
  hkaiWorld::Cinfo cInfo; // [rsp+60h] [rbp-1C8h]
  HavokJobMemoryPoolTagger *result; // [rsp+230h] [rbp+8h]

  v53 = -2i64;
  v1 = this;
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    2117862912i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1099969314i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1829661816i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    660317406i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1093109332i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    926677201i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1211889873i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1000824113i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1261170549i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1062566140i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    862692426i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    862692427i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1470720914i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    2551363397i64,
    0i64);
  ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1882590634i64,
    0i64);
  hkaiWorld::Cinfo::Cinfo(&cInfo);
  cInfo.m_up.m_quad = _xmm;
  cInfo.m_fallbackToOldCutter.m_bool = 1;
  cInfo.m_numBehaviorUpdatesPerJob = 3;
  cInfo.m_numPathRequestsPerJob = 4;
  cInfo.m_numCharactersPerAvoidanceJob = 3;
  cInfo.m_performValidationChecks.m_bool = 0;
  v2 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v3 = ++*(_BYTE *)(v2 + 80);
  v4 = v3;
  *(_DWORD *)(v2 + 4 * v4) = 1;
  *(_QWORD *)(v2 + 8 * v4 + 16) = "AI::hkaiWorld";
  *(_QWORD *)(v2 + 8 * v4 + 48) = 0i64;
  v5 = *(_BYTE *)(v2 + 81);
  if ( v3 > v5 )
    v5 = v3;
  *(_BYTE *)(v2 + 81) = v5;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkaiWorld *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 640i64);
  result = (HavokJobMemoryPoolTagger *)v7;
  if ( v7 )
    hkaiWorld::hkaiWorld(v7, &cInfo);
  else
    v8 = 0i64;
  v1->m_world = v8;
  v9 = *(_BYTE *)(v2 + 80);
  if ( v9 > 0 )
  {
    *(_BYTE *)(v2 + 80) = v9 - 1;
  }
  else
  {
    *(_BYTE *)(v2 + 80) = 0;
    *(_DWORD *)v2 = 3;
    *(_QWORD *)(v2 + 16) = 0i64;
    *(_QWORD *)(v2 + 48) = 0i64;
  }
  v1->m_jobThreadPool = UFG::BasePhysicsSystem::mInstance->mThreadPool;
  hkJobQueueHwSetup::hkJobQueueHwSetup(&v51);
  v51.m_noSpu.m_bool = 1;
  v52 = 20;
  v10 = ++*(_BYTE *)(v2 + 80);
  v11 = v10;
  *(_DWORD *)(v2 + 4 * v11) = 1;
  *(_QWORD *)(v2 + 8 * v11 + 16) = "AI::JobQueue";
  *(_QWORD *)(v2 + 8 * v11 + 48) = 0i64;
  v12 = *(_BYTE *)(v2 + 81);
  if ( v10 > v12 )
    v12 = v10;
  *(_BYTE *)(v2 + 81) = v12;
  v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (hkJobQueue *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v13[11] + 8i64))(v13[11], 1024i64);
  result = (HavokJobMemoryPoolTagger *)v14;
  if ( v14 )
    hkJobQueue::hkJobQueue(v14, (hkJobQueueCinfo *)&v51);
  else
    v15 = 0i64;
  v1->m_jobQueue = v15;
  v16 = *(_BYTE *)(v2 + 80);
  if ( v16 > 0 )
  {
    *(_BYTE *)(v2 + 80) = v16 - 1;
  }
  else
  {
    *(_BYTE *)(v2 + 80) = 0;
    *(_DWORD *)v2 = 3;
    *(_QWORD *)(v2 + 16) = 0i64;
    *(_QWORD *)(v2 + 48) = 0i64;
  }
  v17 = ++*(_BYTE *)(v2 + 80);
  v18 = v17;
  *(_DWORD *)(v2 + 4 * v18) = 1;
  *(_QWORD *)(v2 + 8 * v18 + 16) = "AI::JobMemoryPoolTagger";
  *(_QWORD *)(v2 + 8 * v18 + 48) = 0i64;
  v19 = *(_BYTE *)(v2 + 81);
  if ( v17 > v19 )
    v19 = v17;
  *(_BYTE *)(v2 + 81) = v19;
  v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v21 = (HavokJobMemoryPoolTagger *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v20[11] + 8i64))(
                                      v20[11],
                                      8i64);
  result = v21;
  if ( v21 )
  {
    v21->vfptr = (hkExternalJobProfilerVtbl *)&hkExternalJobProfiler::`vftable';
    v21->vfptr = (hkExternalJobProfilerVtbl *)&HavokJobMemoryPoolTagger::`vftable';
  }
  else
  {
    v21 = 0i64;
  }
  v1->m_jobMemoryPoolTagger = v21;
  v22 = *(_BYTE *)(v2 + 80);
  if ( v22 > 0 )
  {
    *(_BYTE *)(v2 + 80) = v22 - 1;
  }
  else
  {
    *(_BYTE *)(v2 + 80) = 0;
    *(_DWORD *)v2 = 3;
    *(_QWORD *)(v2 + 16) = 0i64;
    *(_QWORD *)(v2 + 48) = 0i64;
  }
  v23 = ++*(_BYTE *)(v2 + 80);
  v24 = v23;
  *(_DWORD *)(v2 + 4 * v24) = 1;
  *(_QWORD *)(v2 + 8 * v24 + 16) = "AI::JobQueueRegistration";
  *(_QWORD *)(v2 + 8 * v24 + 48) = 0i64;
  v25 = *(_BYTE *)(v2 + 81);
  if ( v23 > v25 )
    v25 = v23;
  *(_BYTE *)(v2 + 81) = v25;
  hkaiPathfindingJobQueueUtils::registerWithJobQueue(v1->m_jobQueue);
  hkaiLocalSteeringJobQueueUtils::registerWithJobQueue(v1->m_jobQueue);
  hkaiDynamicNavMeshJobQueueUtils::registerWithJobQueue(v1->m_jobQueue);
  hkJobQueue::setExternalProfiler(v1->m_jobQueue, (hkExternalJobProfiler *)&v1->m_jobMemoryPoolTagger->vfptr);
  v26 = *(_BYTE *)(v2 + 80);
  if ( v26 > 0 )
  {
    *(_BYTE *)(v2 + 80) = v26 - 1;
  }
  else
  {
    *(_BYTE *)(v2 + 80) = 0;
    *(_DWORD *)v2 = 3;
    *(_QWORD *)(v2 + 16) = 0i64;
    *(_QWORD *)(v2 + 48) = 0i64;
  }
  v27 = ++*(_BYTE *)(v2 + 80);
  v28 = v27;
  *(_DWORD *)(v2 + 4 * v28) = 1;
  *(_QWORD *)(v2 + 8 * v28 + 16) = "AI::AiListener";
  *(_QWORD *)(v2 + 8 * v28 + 48) = 0i64;
  v29 = *(_BYTE *)(v2 + 81);
  if ( v27 > v29 )
    v29 = v27;
  *(_BYTE *)(v2 + 81) = v29;
  v30 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v31 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v30[11] + 8i64))(v30[11], 32i64);
  result = (HavokJobMemoryPoolTagger *)v31;
  if ( v31 )
  {
    *(_QWORD *)v31 = &hkBaseObject::`vftable';
    *(_QWORD *)v31 = &hkReferencedObject::`vftable';
    *(_DWORD *)(v31 + 8) = 0x1FFFF;
    *(_QWORD *)(v31 + 16) = &hkaiWorld::Listener::`vftable';
    *(_QWORD *)v31 = &UFG::HavokNavManager::AiListener::`vftable'{for `hkReferencedObject'};
    *(_QWORD *)(v31 + 16) = &UFG::HavokNavManager::AiListener::`vftable'{for `hkaiWorld::Listener'};
    *(_QWORD *)(v31 + 24) = v1;
  }
  else
  {
    v31 = 0i64;
  }
  if ( v31 )
    hkReferencedObject::addReference((hkReferencedObject *)v31);
  v32 = (hkReferencedObject *)&v1->m_listener.m_pntr->vfptr;
  if ( v32 )
    hkReferencedObject::removeReference(v32);
  v1->m_listener.m_pntr = (UFG::HavokNavManager::AiListener *)v31;
  hkReferencedObject::removeReference((hkReferencedObject *)v31);
  v33 = v1->m_listener.m_pntr;
  if ( v33 )
    v34 = (hkaiWorld::Listener *)&v33->vfptr;
  else
    v34 = 0i64;
  hkaiWorld::addListener(v1->m_world, v34);
  v35 = *(_BYTE *)(v2 + 80);
  if ( v35 > 0 )
  {
    *(_BYTE *)(v2 + 80) = v35 - 1;
  }
  else
  {
    *(_BYTE *)(v2 + 80) = 0;
    *(_DWORD *)v2 = 3;
    *(_QWORD *)(v2 + 16) = 0i64;
    *(_QWORD *)(v2 + 48) = 0i64;
  }
  if ( v1->m_dynamicOutlines.capacity < 0xC8 && v1->m_dynamicOutlines.size != 200 )
  {
    v36 = 1600i64;
    if ( !is_mul_ok(0xC8ui64, 8ui64) )
      v36 = -1i64;
    v37 = UFG::qMalloc(v36, "qArray.Reallocate(Reserve)", 0i64);
    v38 = v37;
    if ( v1->m_dynamicOutlines.p )
    {
      for ( i = 0; i < v1->m_dynamicOutlines.size; ++i )
        *(_QWORD *)&v37[8 * i] = v1->m_dynamicOutlines.p[i];
      operator delete[](v1->m_dynamicOutlines.p);
    }
    v1->m_dynamicOutlines.p = (UFG::HavokNavDynamicOutline **)v38;
    v1->m_dynamicOutlines.capacity = 200;
  }
  if ( v1->m_dynamicOutlinesAdditionQueue.capacity < 0xC8 && v1->m_dynamicOutlinesAdditionQueue.size != 200 )
  {
    v40 = 1600i64;
    if ( !is_mul_ok(0xC8ui64, 8ui64) )
      v40 = -1i64;
    v41 = UFG::qMalloc(v40, "qArray.Reallocate(Reserve)", 0i64);
    v42 = v41;
    if ( v1->m_dynamicOutlinesAdditionQueue.p )
    {
      for ( j = 0; j < v1->m_dynamicOutlinesAdditionQueue.size; ++j )
        *(_QWORD *)&v41[8 * j] = v1->m_dynamicOutlinesAdditionQueue.p[j];
      operator delete[](v1->m_dynamicOutlinesAdditionQueue.p);
    }
    v1->m_dynamicOutlinesAdditionQueue.p = (UFG::HavokNavDynamicOutline **)v42;
    v1->m_dynamicOutlinesAdditionQueue.capacity = 200;
  }
  if ( v1->m_dynamicOutlinesDeletionQueue.capacity < 0xC8 && v1->m_dynamicOutlinesDeletionQueue.size != 200 )
  {
    v44 = 1600i64;
    if ( !is_mul_ok(0xC8ui64, 8ui64) )
      v44 = -1i64;
    v45 = UFG::qMalloc(v44, "qArray.Reallocate(Reserve)", 0i64);
    v46 = v45;
    if ( v1->m_dynamicOutlinesDeletionQueue.p )
    {
      for ( k = 0; k < v1->m_dynamicOutlinesDeletionQueue.size; ++k )
        *(_QWORD *)&v45[8 * k] = v1->m_dynamicOutlinesDeletionQueue.p[k];
      operator delete[](v1->m_dynamicOutlinesDeletionQueue.p);
    }
    v1->m_dynamicOutlinesDeletionQueue.p = (UFG::HavokNavDynamicOutline **)v46;
    v1->m_dynamicOutlinesDeletionQueue.capacity = 200;
  }
  v48 = 128;
  if ( v1->m_aTesselationData.capacity < 0x80 )
    UFG::qArray<UFG::qVector3,0>::Reallocate(&v1->m_aTesselationData, 0x80u, "qArray.Reallocate(Reserve)");
  v49 = v1->m_StitchInstances.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v49 < 128 )
  {
    v50 = 2 * v49;
    if ( v50 > 128 )
      v48 = v50;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_StitchInstances,
      v48,
      8);
  }
  v1->m_StitchingDelay = 0;
  v1->m_highspeedMode = 0;
  hkJobQueueHwSetup::~hkJobQueueHwSetup(&v51);
  hkaiVolumePathfindingUtil::FindPathInput::~FindPathInput(&cInfo.m_volumePathfindingInput);
  hkaiPathfindingUtil::FindPathInput::~FindPathInput(&cInfo.m_pathfindingInput);
}

// File Line: 316
// RVA: 0xF0B00
void __fastcall UFG::HavokNavManager::RequeueAdditionQueue(UFG::HavokNavManager *this, bool forceUpdate)
{
  unsigned int v2; // eax
  UFG::HavokNavManager *v3; // rdi
  unsigned int v4; // er8
  signed __int64 v5; // r14
  __int64 v6; // r12
  char v7; // dl
  __int64 v8; // rax
  char v9; // cl
  UFG::HavokNavDynamicOutline **v10; // rax
  UFG::HavokNavDynamicOutline *v11; // r13
  __int64 v12; // r15
  unsigned int v13; // ebx
  unsigned int v14; // esi
  unsigned int v15; // ebx
  unsigned __int64 v16; // rax
  char *v17; // rax
  char *v18; // rbp
  signed __int64 v19; // r9
  signed __int64 v20; // r8
  UFG::HavokNavDynamicOutline **v21; // rax
  unsigned int v22; // eax
  char v23; // al

  v2 = this->m_dynamicOutlines.size;
  v3 = this;
  v4 = 0;
  if ( v2 > 5 || forceUpdate && (v4 = this->m_dynamicOutlines.size, v2 > 5) )
    v4 = 5;
  if ( v4 )
  {
    v5 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v6 = v4;
    do
    {
      v7 = ++*(_BYTE *)(v5 + 80);
      v8 = v7;
      *(_DWORD *)(v5 + 4 * v8) = 1;
      *(_QWORD *)(v5 + 8 * v8 + 16) = "AI::HavokNavManager::RequeueDynamicOutline";
      *(_QWORD *)(v5 + 8 * v8 + 48) = 0i64;
      v9 = *(_BYTE *)(v5 + 81);
      if ( v7 > v9 )
        v9 = v7;
      *(_BYTE *)(v5 + 81) = v9;
      v10 = v3->m_dynamicOutlines.p;
      v11 = *v10;
      hkaiWorld::removeSilhouetteGenerator(v3->m_world, (hkaiSilhouetteGenerator *)&(*v10)->m_pSilhouette->vfptr);
      v12 = v3->m_dynamicOutlinesAdditionQueue.size;
      v13 = v3->m_dynamicOutlinesAdditionQueue.capacity;
      v14 = v12 + 1;
      if ( (signed int)v12 + 1 > v13 )
      {
        if ( v13 )
          v15 = 2 * v13;
        else
          v15 = 1;
        for ( ; v15 < v14; v15 *= 2 )
          ;
        if ( v15 <= 2 )
          v15 = 2;
        if ( v15 - v14 > 0x10000 )
          v15 = v12 + 65537;
        if ( v15 != (_DWORD)v12 )
        {
          v16 = 8i64 * v15;
          if ( !is_mul_ok(v15, 8ui64) )
            v16 = -1i64;
          v17 = UFG::qMalloc(v16, "qArray.Add", 0i64);
          v18 = v17;
          if ( v3->m_dynamicOutlinesAdditionQueue.p )
          {
            v19 = 0i64;
            if ( v3->m_dynamicOutlinesAdditionQueue.size )
            {
              do
              {
                v20 = v19;
                v19 = (unsigned int)(v19 + 1);
                *(_QWORD *)&v17[v20 * 8] = v3->m_dynamicOutlinesAdditionQueue.p[v20];
              }
              while ( (unsigned int)v19 < v3->m_dynamicOutlinesAdditionQueue.size );
            }
            operator delete[](v3->m_dynamicOutlinesAdditionQueue.p);
          }
          v3->m_dynamicOutlinesAdditionQueue.p = (UFG::HavokNavDynamicOutline **)v18;
          v3->m_dynamicOutlinesAdditionQueue.capacity = v15;
        }
      }
      v21 = v3->m_dynamicOutlinesAdditionQueue.p;
      v3->m_dynamicOutlinesAdditionQueue.size = v14;
      v21[v12] = v11;
      *v3->m_dynamicOutlines.p = v3->m_dynamicOutlines.p[v3->m_dynamicOutlines.size - 1];
      v22 = v3->m_dynamicOutlines.size;
      if ( v22 > 1 )
        v3->m_dynamicOutlines.size = v22 - 1;
      else
        v3->m_dynamicOutlines.size = 0;
      v23 = *(_BYTE *)(v5 + 80);
      if ( v23 > 0 )
      {
        *(_BYTE *)(v5 + 80) = v23 - 1;
      }
      else
      {
        *(_BYTE *)(v5 + 80) = 0;
        *(_DWORD *)v5 = 3;
        *(_QWORD *)(v5 + 16) = 0i64;
        *(_QWORD *)(v5 + 48) = 0i64;
      }
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 338
// RVA: 0xE7EC0
void __fastcall UFG::HavokNavManager::ApplyAdditionQueue(UFG::HavokNavManager *this, bool forceUpdate)
{
  unsigned int v2; // eax
  UFG::HavokNavManager *v3; // rdi
  unsigned int v4; // er8
  signed __int64 v5; // r14
  __int64 v6; // r12
  char v7; // dl
  __int64 v8; // rax
  char v9; // cl
  UFG::HavokNavDynamicOutline **v10; // rax
  UFG::HavokNavDynamicOutline *v11; // r13
  __int64 v12; // r15
  unsigned int v13; // ebx
  unsigned int v14; // esi
  unsigned int v15; // ebx
  unsigned __int64 v16; // rax
  char *v17; // rax
  char *v18; // rbp
  signed __int64 v19; // r9
  signed __int64 v20; // r8
  UFG::HavokNavDynamicOutline **v21; // rax
  unsigned int v22; // eax
  char v23; // al

  v2 = this->m_dynamicOutlinesAdditionQueue.size;
  v3 = this;
  v4 = 0;
  if ( v2 > 5 || forceUpdate && (v4 = this->m_dynamicOutlinesAdditionQueue.size, v2 > 5) )
    v4 = 5;
  if ( v4 )
  {
    v5 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v6 = v4;
    do
    {
      v7 = ++*(_BYTE *)(v5 + 80);
      v8 = v7;
      *(_DWORD *)(v5 + 4 * v8) = 1;
      *(_QWORD *)(v5 + 8 * v8 + 16) = "AI::HavokNavManager::ApplyAdditionQueue";
      *(_QWORD *)(v5 + 8 * v8 + 48) = 0i64;
      v9 = *(_BYTE *)(v5 + 81);
      if ( v7 > v9 )
        v9 = v7;
      *(_BYTE *)(v5 + 81) = v9;
      v10 = v3->m_dynamicOutlinesAdditionQueue.p;
      v11 = *v10;
      hkaiWorld::addSilhouetteGenerator(v3->m_world, (hkaiSilhouetteGenerator *)&(*v10)->m_pSilhouette->vfptr);
      v12 = v3->m_dynamicOutlines.size;
      v13 = v3->m_dynamicOutlines.capacity;
      v14 = v12 + 1;
      if ( (signed int)v12 + 1 > v13 )
      {
        if ( v13 )
          v15 = 2 * v13;
        else
          v15 = 1;
        for ( ; v15 < v14; v15 *= 2 )
          ;
        if ( v15 <= 2 )
          v15 = 2;
        if ( v15 - v14 > 0x10000 )
          v15 = v12 + 65537;
        if ( v15 != (_DWORD)v12 )
        {
          v16 = 8i64 * v15;
          if ( !is_mul_ok(v15, 8ui64) )
            v16 = -1i64;
          v17 = UFG::qMalloc(v16, "qArray.Add", 0i64);
          v18 = v17;
          if ( v3->m_dynamicOutlines.p )
          {
            v19 = 0i64;
            if ( v3->m_dynamicOutlines.size )
            {
              do
              {
                v20 = v19;
                v19 = (unsigned int)(v19 + 1);
                *(_QWORD *)&v17[v20 * 8] = v3->m_dynamicOutlines.p[v20];
              }
              while ( (unsigned int)v19 < v3->m_dynamicOutlines.size );
            }
            operator delete[](v3->m_dynamicOutlines.p);
          }
          v3->m_dynamicOutlines.p = (UFG::HavokNavDynamicOutline **)v18;
          v3->m_dynamicOutlines.capacity = v15;
        }
      }
      v21 = v3->m_dynamicOutlines.p;
      v3->m_dynamicOutlines.size = v14;
      v21[v12] = v11;
      *v3->m_dynamicOutlinesAdditionQueue.p = v3->m_dynamicOutlinesAdditionQueue.p[v3->m_dynamicOutlinesAdditionQueue.size
                                                                                 - 1];
      v22 = v3->m_dynamicOutlinesAdditionQueue.size;
      if ( v22 > 1 )
        v3->m_dynamicOutlinesAdditionQueue.size = v22 - 1;
      else
        v3->m_dynamicOutlinesAdditionQueue.size = 0;
      v23 = *(_BYTE *)(v5 + 80);
      if ( v23 > 0 )
      {
        *(_BYTE *)(v5 + 80) = v23 - 1;
      }
      else
      {
        *(_BYTE *)(v5 + 80) = 0;
        *(_DWORD *)v5 = 3;
        *(_QWORD *)(v5 + 16) = 0i64;
        *(_QWORD *)(v5 + 48) = 0i64;
      }
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 360
// RVA: 0xE8100
void __fastcall UFG::HavokNavManager::ApplyDeletionQueue(UFG::HavokNavManager *this, bool forceUpdate)
{
  unsigned int v2; // eax
  UFG::HavokNavManager *v3; // rsi
  unsigned int v4; // er8
  signed __int64 v5; // rbx
  __int64 v6; // rbp
  char v7; // dl
  __int64 v8; // rax
  char v9; // cl
  UFG::HavokNavDynamicOutline **v10; // rax
  UFG::HavokNavDynamicOutline *v11; // rdi
  unsigned int v12; // eax
  char v13; // al

  v2 = this->m_dynamicOutlinesDeletionQueue.size;
  v3 = this;
  v4 = 0;
  if ( v2 > 5 || forceUpdate && (v4 = this->m_dynamicOutlinesDeletionQueue.size, v2 > 5) )
    v4 = 5;
  if ( v4 )
  {
    v5 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v6 = v4;
    do
    {
      v7 = ++*(_BYTE *)(v5 + 80);
      v8 = v7;
      *(_DWORD *)(v5 + 4 * v8) = 1;
      *(_QWORD *)(v5 + 8 * v8 + 16) = "AI::HavokNavManager::CommitDeletionQueue";
      *(_QWORD *)(v5 + 8 * v8 + 48) = 0i64;
      v9 = *(_BYTE *)(v5 + 81);
      if ( v7 > v9 )
        v9 = v7;
      *(_BYTE *)(v5 + 81) = v9;
      v10 = v3->m_dynamicOutlinesDeletionQueue.p;
      v11 = *v10;
      hkaiWorld::removeSilhouetteGenerator(v3->m_world, (hkaiSilhouetteGenerator *)&(*v10)->m_pSilhouette->vfptr);
      v11->vfptr->__vecDelDtor((UFG::NavDynamicOutline *)&v11->vfptr, 1u);
      *v3->m_dynamicOutlinesDeletionQueue.p = v3->m_dynamicOutlinesDeletionQueue.p[v3->m_dynamicOutlinesDeletionQueue.size
                                                                                 - 1];
      v12 = v3->m_dynamicOutlinesDeletionQueue.size;
      if ( v12 > 1 )
        v3->m_dynamicOutlinesDeletionQueue.size = v12 - 1;
      else
        v3->m_dynamicOutlinesDeletionQueue.size = 0;
      v13 = *(_BYTE *)(v5 + 80);
      if ( v13 > 0 )
      {
        *(_BYTE *)(v5 + 80) = v13 - 1;
      }
      else
      {
        *(_BYTE *)(v5 + 80) = 0;
        *(_DWORD *)v5 = 3;
        *(_QWORD *)(v5 + 16) = 0i64;
        *(_QWORD *)(v5 + 48) = 0i64;
      }
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 382
// RVA: 0xEFF90
void __fastcall UFG::HavokNavManager::LowHealthDefrag(UFG::HavokNavManager *this)
{
  UFG::HavokNavManager *v1; // rbx
  signed __int64 v2; // rax
  float v3; // xmm6_4
  signed __int64 v4; // rax
  float v5; // xmm0_4

  v1 = this;
  v2 = UFG::qMemoryPool::GetLargestFree(&gAIMemoryPool, 0i64);
  v3 = (float)(signed int)v2;
  if ( v2 < 0 )
    v3 = v3 + 1.8446744e19;
  v4 = UFG::qMemoryPool::GetTotalFreeBytes(&gAIMemoryPool);
  v5 = (float)(signed int)v4;
  if ( v4 < 0 )
    v5 = v5 + 1.8446744e19;
  if ( (float)((float)(v3 / v5) * 100.0) < 0.30000001 )
    UFG::HavokNavManager::Defrag(v1, DefragVerbosity_Hide);
}

// File Line: 392
// RVA: 0xF39B0
void __fastcall UFG::HavokNavManager::UpdateDynamicObstaclesPre(UFG::HavokNavManager *this)
{
  UFG::HavokNavManager *v1; // rbx
  UFG::SimObjectCharacter *v2; // rax
  UFG::CharacterOccupantComponent *v3; // rcx
  UFG::VehicleOccupantComponent *v4; // rax
  UFG::PhysicsMoverInterface *v5; // rcx
  bool v6; // di
  unsigned __int64 v7; // rax
  signed __int64 v8; // rdi
  char v9; // dl
  __int64 v10; // rax
  char v11; // cl
  hkJobThreadPool *v12; // r9
  hkJobQueue *v13; // r8
  char v14; // al
  int v15; // eax

  v1 = this;
  if ( !(_S6_2 & 1) )
  {
    _S6_2 |= 1u;
    sLastUpdatedTick = UFG::qGetTicks();
  }
  UFG::qGetTicks();
  v1->m_highspeedMode = 0;
  v2 = UFG::GetLocalPlayer();
  if ( v2 )
  {
    v3 = (UFG::CharacterOccupantComponent *)v2->m_Components.p[44].m_pComponent;
    if ( v3 )
    {
      v4 = UFG::CharacterOccupantComponent::GetCurrentVehicle(v3);
      if ( v4 )
      {
        v5 = (UFG::PhysicsMoverInterface *)v4->mpDriver.m_pPointer[4].m_SafePointerWithCallbackList.mNode.mNext;
        if ( v5 )
        {
          if ( UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH(v5) > 60.0 )
            v1->m_highspeedMode = 1;
        }
      }
    }
  }
  v6 = 0;
  v7 = UFG::qGetTicks();
  if ( UFG::qGetTickTime(sLastUpdatedTick, v7) > 1.0 )
  {
    sLastUpdatedTick = UFG::qGetTicks();
    v6 = 1;
  }
  UFG::qGetTicks();
  if ( v1->m_highspeedMode )
    UFG::HavokNavManager::RequeueAdditionQueue(v1, v6);
  else
    UFG::HavokNavManager::ApplyAdditionQueue(v1, v6);
  UFG::HavokNavManager::ApplyDeletionQueue(v1, v6);
  v8 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v9 = ++*(_BYTE *)(v8 + 80);
  v10 = v9;
  *(_DWORD *)(v8 + 4 * v10) = 1;
  *(_QWORD *)(v8 + 8 * v10 + 16) = "AI::HavokNavManager::UpdateDynamicObstacles";
  *(_QWORD *)(v8 + 8 * v10 + 48) = 1i64;
  v11 = *(_BYTE *)(v8 + 81);
  if ( v9 > v11 )
    v11 = v9;
  *(_BYTE *)(v8 + 81) = v11;
  if ( UFG::HavokNavManager::ms_bEnableOutlineMT )
  {
    v12 = v1->m_jobThreadPool;
    v13 = v1->m_jobQueue;
  }
  else
  {
    v12 = 0i64;
    v13 = 0i64;
  }
  hkaiWorld::stepSilhouettesMT(v1->m_world, 0i64, v13, v12);
  v14 = *(_BYTE *)(v8 + 80);
  if ( v14 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v14 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  if ( v1->m_StitchInstances.m_size )
  {
    v15 = v1->m_StitchingDelay;
    if ( v15 <= 0 )
      ((void (__fastcall *)(UFG::HavokNavManager *, _QWORD, _QWORD))v1->vfptr[1].ExitGame)(v1, 0i64, 0i64);
    else
      v1->m_StitchingDelay = v15 - 1;
  }
}

// File Line: 509
// RVA: 0xE95D0
void __fastcall UFG::HavokNavManager::Defrag(UFG::HavokNavManager *this, UFG::HavokNavManager::DefragVerbosity verbosity)
{
  UFG::HavokNavManager *v2; // rbx
  signed __int64 v3; // r14
  char v4; // r8
  UFG::HavokNavManager::DefragVerbosity v5; // edi
  __int64 v6; // rax
  char v7; // cl
  unsigned int v8; // eax
  __int64 v9; // rdi
  __int64 v10; // r12
  UFG::HavokNavManager::MeshCell *v11; // rsi
  unsigned int v12; // eax
  __int64 v13; // r15
  __int64 v14; // r13
  void **v15; // rbx
  unsigned int v16; // eax
  __int64 v17; // rdi
  __int64 v18; // r12
  UFG::HavokNavManager::MeshCell *v19; // rsi
  unsigned int v20; // eax
  __int64 v21; // r15
  __int64 v22; // r13
  void **v23; // rbx
  char v24; // al
  UFG::HavokNavManager *v25; // [rsp+25E0h] [rbp+24E0h]
  UFG::HavokNavManager::DefragVerbosity v26; // [rsp+25E8h] [rbp+24E8h]

  v26 = verbosity;
  v25 = this;
  v2 = this;
  v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v4 = ++*(_BYTE *)(v3 + 80);
  v5 = verbosity;
  v6 = v4;
  *(_DWORD *)(v3 + 4 * v6) = 1;
  *(_QWORD *)(v3 + 8 * v6 + 16) = "AI::HavokNavManagerDefrag";
  *(_QWORD *)(v3 + 8 * v6 + 48) = 0i64;
  v7 = *(_BYTE *)(v3 + 81);
  if ( v4 > v7 )
    v7 = v4;
  *(_BYTE *)(v3 + 81) = v7;
  UFG::qGetTicks();
  if ( v5 == DefragVerbosity_Show )
    _((AMD_HD3D *)&gAIMemoryPool);
  v8 = v2->m_cells.m_size;
  if ( v8 )
  {
    v9 = 0i64;
    v10 = v8;
    do
    {
      v11 = v2->m_cells.m_data[v9];
      v12 = v11->m_Instances.m_size;
      if ( v12 )
      {
        v13 = 0i64;
        v14 = v12;
        do
        {
          v15 = (void **)&v11->m_Instances.m_data[v13]->vfptr;
          UFG::qMemoryPool::Size(&gAIMemoryPool, v15[26]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v15[28]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v15[30]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v15[32]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v15[34]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v15[36]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v15[38]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v15[40]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v15[52]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v15[54]);
          ++v13;
          UFG::qMemoryPool::Size(&gAIMemoryPool, v15[56]);
          --v14;
        }
        while ( v14 );
        v2 = v25;
      }
      ++v9;
      --v10;
    }
    while ( v10 );
    v5 = v26;
  }
  if ( v5 == DefragVerbosity_Show )
    _((AMD_HD3D *)&gAIMemoryPool);
  v16 = v2->m_cells.m_size;
  if ( v16 )
  {
    v17 = 0i64;
    v18 = v16;
    do
    {
      v19 = v2->m_cells.m_data[v17];
      v20 = v19->m_Instances.m_size;
      if ( v20 )
      {
        v21 = 0i64;
        v22 = v20;
        do
        {
          v23 = (void **)&v19->m_Instances.m_data[v21]->vfptr;
          UFG::qMemoryPool::Size(&gAIMemoryPool, v23[26]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v23[28]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v23[30]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v23[32]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v23[34]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v23[36]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v23[38]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v23[40]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v23[52]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v23[54]);
          ++v21;
          UFG::qMemoryPool::Size(&gAIMemoryPool, v23[56]);
          --v22;
        }
        while ( v22 );
        v2 = v25;
      }
      ++v17;
      --v18;
    }
    while ( v18 );
    v5 = v26;
  }
  if ( v5 == DefragVerbosity_Show )
    _((AMD_HD3D *)&gAIMemoryPool);
  v24 = *(_BYTE *)(v3 + 80);
  if ( v24 > 0 )
  {
    *(_BYTE *)(v3 + 80) = v24 - 1;
  }
  else
  {
    *(_BYTE *)(v3 + 80) = 0;
    *(_DWORD *)v3 = 3;
    *(_QWORD *)(v3 + 16) = 0i64;
    *(_QWORD *)(v3 + 48) = 0i64;
  }
}

// File Line: 863
// RVA: 0xF45A0
void __fastcall UFG::HavokNavManager::AiListener::dynamicNavMeshModifiedCallback(UFG::HavokNavManager::AiListener *this, hkaiWorld::NavMeshModifiedCallbackContext *context)
{
  UFG::HavokNavManager::AiListener *v2; // rbp
  hkaiWorld::NavMeshModifiedCallbackContext *v3; // r14
  unsigned int v4; // ecx
  __int64 v5; // r15
  __int64 v6; // rsi
  __int64 v7; // rdi
  _QWORD *v8; // rax
  __int64 v9; // rbx
  signed __int64 v10; // rbx
  char v11; // dl
  __int64 v12; // rax
  char v13; // cl
  char v14; // al
  hkaiUserEdgeUtils::CutMeshUpdateParameters params; // [rsp+60h] [rbp+8h]

  v2 = this;
  v3 = context;
  v4 = *(_DWORD *)(*(_QWORD *)&this->m_memSizeAndFlags + 40i64);
  if ( v4 )
  {
    v5 = tls_index;
    v6 = v4;
    v7 = 0i64;
    do
    {
      if ( *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)&v2->m_memSizeAndFlags + 32i64) + v7) + 48i64) )
      {
        v8 = NtCurrentTeb()->Reserved1[11];
        *(_WORD *)&params.m_clearanceResetMode.m_storage = 256;
        params.m_minEdgeLength = 0.050000001;
        v9 = v8[v5];
        params.m_compactHierarchyGraphs.m_bool = 1;
        v10 = v9 + 16;
        v11 = ++*(_BYTE *)(v10 + 80);
        v12 = v11;
        *(_DWORD *)(v10 + 4 * v12) = 1;
        *(_QWORD *)(v10 + 8 * v12 + 16) = "HavokNavManager";
        *(_QWORD *)(v10 + 8 * v12 + 48) = 0i64;
        v13 = *(_BYTE *)(v10 + 81);
        if ( v11 > v13 )
          v13 = v11;
        *(_BYTE *)(v10 + 81) = v13;
        hkaiUserEdgeUtils::selectiveAddUserEdgePairsToCutMesh(
          *(hkaiStreamingCollection **)(*(_QWORD *)(*(_QWORD *)&v2->m_memSizeAndFlags + 24i64) + 32i64),
          (hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)&v2->m_memSizeAndFlags
                                                                                             + 32i64)
                                                                                 + v7)
                                                                     + 48i64)
                                                         + 16i64),
          *(hkaiNavMeshCutter **)(*(_QWORD *)(*(_QWORD *)&v2->m_memSizeAndFlags + 24i64) + 40i64),
          v3->m_cutFaceKeys,
          v3->m_uncutFaceKeys,
          &params);
        v14 = *(_BYTE *)(v10 + 80);
        if ( v14 > 0 )
        {
          *(_BYTE *)(v10 + 80) = v14 - 1;
        }
        else
        {
          *(_BYTE *)(v10 + 80) = 0;
          *(_DWORD *)v10 = 3;
          *(_QWORD *)(v10 + 16) = 0i64;
          *(_QWORD *)(v10 + 48) = 0i64;
        }
      }
      v7 += 8i64;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 945
// RVA: 0xEA0F0
void __fastcall UFG::HavokNavManager::ExitGame(UFG::HavokNavManager *this)
{
  UFG::HavokNavManager *v1; // rbx
  signed __int64 v2; // rsi
  char v3; // dl
  __int64 v4; // rax
  char v5; // cl
  unsigned int v6; // eax
  __int64 v7; // rdi
  __int64 v8; // rbp
  UFG::HavokNavDynamicOutline *v9; // rcx
  UFG::HavokNavDynamicOutline **v10; // rcx
  unsigned int v11; // eax
  __int64 v12; // r14
  __int64 v13; // rbp
  UFG::HavokNavDynamicOutline *v14; // rdi
  UFG::HavokNavDynamicOutline **v15; // rcx
  unsigned int v16; // eax
  __int64 v17; // r14
  __int64 v18; // rbp
  UFG::HavokNavDynamicOutline *v19; // rdi
  UFG::HavokNavDynamicOutline **v20; // rcx
  char v21; // al
  char v22; // dl
  __int64 v23; // rax
  char v24; // cl
  char v25; // al

  v1 = this;
  v2 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v3 = ++*(_BYTE *)(v2 + 80);
  v4 = v3;
  *(_DWORD *)(v2 + 4 * v4) = 1;
  *(_QWORD *)(v2 + 8 * v4 + 16) = "AI::HavokNavManager::ExitGameDeleteQueue";
  *(_QWORD *)(v2 + 8 * v4 + 48) = 0i64;
  v5 = *(_BYTE *)(v2 + 81);
  if ( v3 > v5 )
    v5 = v3;
  *(_BYTE *)(v2 + 81) = v5;
  v6 = v1->m_dynamicOutlinesAdditionQueue.size;
  if ( v6 )
  {
    v7 = 0i64;
    v8 = v6;
    do
    {
      v9 = v1->m_dynamicOutlinesAdditionQueue.p[v7];
      if ( v9 )
        v9->vfptr->__vecDelDtor((UFG::NavDynamicOutline *)&v9->vfptr, 1u);
      ++v7;
      --v8;
    }
    while ( v8 );
  }
  v10 = v1->m_dynamicOutlinesAdditionQueue.p;
  if ( v10 )
    operator delete[](v10);
  v1->m_dynamicOutlinesAdditionQueue.p = 0i64;
  *(_QWORD *)&v1->m_dynamicOutlinesAdditionQueue.size = 0i64;
  v11 = v1->m_dynamicOutlines.size;
  if ( v11 )
  {
    v12 = 0i64;
    v13 = v11;
    do
    {
      v14 = v1->m_dynamicOutlines.p[v12];
      hkaiWorld::removeSilhouetteGenerator(v1->m_world, (hkaiSilhouetteGenerator *)&v14->m_pSilhouette->vfptr);
      v14->vfptr->__vecDelDtor((UFG::NavDynamicOutline *)&v14->vfptr, 1u);
      ++v12;
      --v13;
    }
    while ( v13 );
  }
  v15 = v1->m_dynamicOutlines.p;
  if ( v15 )
    operator delete[](v15);
  v1->m_dynamicOutlines.p = 0i64;
  *(_QWORD *)&v1->m_dynamicOutlines.size = 0i64;
  v16 = v1->m_dynamicOutlinesDeletionQueue.size;
  if ( v16 )
  {
    v17 = 0i64;
    v18 = v16;
    do
    {
      v19 = v1->m_dynamicOutlinesDeletionQueue.p[v17];
      hkaiWorld::removeSilhouetteGenerator(v1->m_world, (hkaiSilhouetteGenerator *)&v19->m_pSilhouette->vfptr);
      v19->vfptr->__vecDelDtor((UFG::NavDynamicOutline *)&v19->vfptr, 1u);
      ++v17;
      --v18;
    }
    while ( v18 );
  }
  v20 = v1->m_dynamicOutlinesDeletionQueue.p;
  if ( v20 )
    operator delete[](v20);
  v1->m_dynamicOutlinesDeletionQueue.p = 0i64;
  *(_QWORD *)&v1->m_dynamicOutlinesDeletionQueue.size = 0i64;
  v21 = *(_BYTE *)(v2 + 80);
  if ( v21 > 0 )
  {
    *(_BYTE *)(v2 + 80) = v21 - 1;
  }
  else
  {
    *(_BYTE *)(v2 + 80) = 0;
    *(_DWORD *)v2 = 3;
    *(_QWORD *)(v2 + 16) = 0i64;
    *(_QWORD *)(v2 + 48) = 0i64;
  }
  v22 = ++*(_BYTE *)(v2 + 80);
  v23 = v22;
  *(_DWORD *)(v2 + 4 * v23) = 1;
  *(_QWORD *)(v2 + 8 * v23 + 16) = "AI::HavokNavManager::ExitGameUpdateObstacles";
  *(_QWORD *)(v2 + 8 * v23 + 48) = 1i64;
  v24 = *(_BYTE *)(v2 + 81);
  if ( v22 > v24 )
    v24 = v22;
  *(_BYTE *)(v2 + 81) = v24;
  hkaiWorld::stepSilhouettesMT(v1->m_world, 0i64, 0i64, 0i64);
  v25 = *(_BYTE *)(v2 + 80);
  if ( v25 > 0 )
  {
    *(_BYTE *)(v2 + 80) = v25 - 1;
  }
  else
  {
    *(_BYTE *)(v2 + 80) = 0;
    *(_DWORD *)v2 = 3;
    *(_QWORD *)(v2 + 16) = 0i64;
    *(_QWORD *)(v2 + 48) = 0i64;
  }
  UFG::HavokNavManager::Defrag(v1, DefragVerbosity_Hide);
}

// File Line: 985
// RVA: 0xF26D0
void __usercall UFG::HavokNavManager::Update(UFG::HavokNavManager *this@<rcx>, float delta_sec@<xmm1>, __int64 a3@<rdx>)
{
  UFG::HavokNavManager *v3; // rbx

  v3 = this;
  if ( tester )
  {
    LOBYTE(a3) = 1;
    ((void (__fastcall *)(UFG::HavokNavManager *, __int64, _QWORD))this->vfptr[1].ExitGame)(this, a3, 0i64);
    tester = 0;
  }
  if ( doPrint )
  {
    UFG::HavokNavManager::PrintMeshInstances(v3);
    doPrint = 0;
  }
}

// File Line: 1062
// RVA: 0xEF6D0
__int64 __fastcall UFG::HavokNavManager::IsInsideAIMesh(UFG::HavokNavManager *this, UFG::qVector3 *position, float tolerance)
{
  char v4; // [rsp+20h] [rbp-18h]

  return ((__int64 (__fastcall *)(UFG::HavokNavManager *, UFG::qVector3 *, char *))this->vfptr->GetClosestAIMesh)(
           this,
           position,
           &v4);
}

// File Line: 1069
// RVA: 0xECE70
bool __fastcall UFG::HavokNavManager::GetClosestAIMesh(UFG::HavokNavManager *this, UFG::qVector3 *position, UFG::qVector3 *closestPosition, float tolerance)
{
  UFG::qVector3 *v4; // rdi
  float v5; // xmm6_4
  UFG::qVector3 *v6; // rsi
  hkaiNavMeshQueryMediator *v7; // rax
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  hkBaseObjectVtbl *v10; // r9
  __m128 v11; // xmm3
  int v12; // xmm1_4
  int v13; // xmm0_4
  float v15; // [rsp+20h] [rbp-88h]
  int v16; // [rsp+24h] [rbp-84h]
  int v17; // [rsp+28h] [rbp-80h]
  int v18; // [rsp+30h] [rbp-78h]
  __int64 v19; // [rsp+38h] [rbp-70h]
  __int128 v20; // [rsp+40h] [rbp-68h]
  __int64 v21; // [rsp+50h] [rbp-58h]
  __m128 v22; // [rsp+60h] [rbp-48h]
  __int128 v23; // [rsp+70h] [rbp-38h]
  __int64 v24; // [rsp+80h] [rbp-28h]

  v4 = closestPosition;
  v5 = tolerance;
  v6 = position;
  v7 = hkaiWorld::getDynamicQueryMediator(this->m_world);
  if ( v7 )
  {
    v8 = (__m128)LODWORD(v6->y);
    v9 = (__m128)LODWORD(v6->x);
    v10 = v7->vfptr;
    _mm_store_si128((__m128i *)&v20, (__m128i)0i64);
    v18 = 0;
    v11 = _mm_unpacklo_ps(v9, (__m128)LODWORD(v6->z));
    v19 = 0i64;
    v21 = 0i64;
    v24 = 0i64;
    _mm_store_si128((__m128i *)&v23, (__m128i)_mm_shuffle_ps((__m128)LODWORD(v5), (__m128)LODWORD(v5), 0));
    v22 = _mm_unpacklo_ps(v11, _mm_unpacklo_ps(v8, (__m128)(unsigned int)FLOAT_1_0));
    LODWORD(v7) = ((__int64 (__fastcall *)(hkaiNavMeshQueryMediator *, int *, float *))v10[1].__first_virtual_table_function__)(
                    v7,
                    &v18,
                    &v15);
    v12 = v16;
    LOBYTE(v7) = (_DWORD)v7 != -1;
    v4->x = v15;
    v13 = v17;
    LODWORD(v4->y) = v12;
    LODWORD(v4->z) = v13;
  }
  return (char)v7;
}

// File Line: 1089
// RVA: 0xEF4C0
char __fastcall UFG::HavokNavManager::IsAIMeshLoadedAt(UFG::HavokNavManager *this, UFG::qVector3 *position)
{
  unsigned int v2; // eax

  v2 = UFG::SectionChooser::GetVisIndexAtPosition(position, 0);
  return UFG::SectionChooser::IsSectionVisible_VisIndex(v2, SCENERY_LAYER_STD, 0);
}

// File Line: 1100
// RVA: 0xF1AB0
char __fastcall UFG::HavokNavManager::TesselateFace(UFG::HavokNavManager *this, unsigned int faceKey, float spacing, float border, bool resizeVectorIfNeeded)
{
  float v5; // xmm6_4
  float v6; // xmm5_4
  UFG::HavokNavManager *v7; // rdi
  signed int v8; // er10
  hkaiNavMeshInstance *v9; // rbx
  int v10; // eax
  signed __int64 v11; // r14
  signed int v12; // edx
  UFG::qArray<UFG::qVector3,0> *v13; // r15
  signed __int64 v14; // r13
  signed int v15; // er12
  int v16; // edx
  int v17; // eax
  signed __int64 v18; // rcx
  hkaiNavMesh::Edge *v19; // rax
  int v20; // er8
  __int64 v21; // rax
  signed int v22; // ecx
  __m128 *v23; // rax
  signed __int64 v24; // rbp
  unsigned int v25; // esi
  unsigned int v26; // edx
  unsigned int v27; // edx
  signed __int64 v28; // rcx
  UFG::qVector3 *v29; // rax
  int v30; // er8
  unsigned int v31; // er12
  float v32; // xmm9_4
  float v33; // xmm7_4
  unsigned int v34; // edx
  signed __int64 v35; // r11
  signed int v36; // eax
  float *v37; // rcx
  unsigned __int64 v38; // r9
  float v39; // xmm0_4
  float v40; // xmm0_4
  float v41; // xmm0_4
  float *v42; // r9
  signed __int64 v43; // r10
  unsigned int v44; // er11
  UFG::qVector3 *v45; // r10
  float v46; // xmm15_4
  float v47; // xmm8_4
  float v48; // xmm3_4
  __int64 v49; // rdx
  float v50; // xmm0_4
  float v51; // xmm11_4
  float v52; // xmm1_4
  float v53; // xmm10_4
  float v54; // xmm14_4
  float v55; // xmm4_4
  __int64 v56; // rdx
  float v57; // xmm13_4
  float v58; // xmm12_4
  float v59; // xmm7_4
  float v60; // xmm9_4
  float v61; // xmm6_4
  int v62; // er9
  unsigned int v63; // ecx
  UFG::qVector3 *v64; // r8
  unsigned int v65; // edi
  signed __int64 v66; // rcx
  __int64 v67; // rdx
  int v68; // er9
  unsigned int v69; // ecx
  UFG::qVector3 *v70; // r8
  signed __int64 v71; // rcx
  __int64 v72; // rdx
  float v73; // xmm6_4
  float v74; // xmm5_4
  float v75; // xmm6_4
  float v76; // xmm1_4
  float v77; // xmm4_4
  float v78; // xmm2_4
  float v79; // xmm13_4
  float v80; // xmm14_4
  float v81; // xmm13_4
  float v82; // xmm13_4
  float v83; // xmm0_4
  float v84; // xmm10_4
  signed int v85; // er15
  signed __int64 v86; // r14
  unsigned int v87; // ebp
  unsigned int v88; // ebx
  unsigned int v89; // ebx
  unsigned __int64 v90; // rax
  char *v91; // rsi
  __int64 v92; // rdx
  signed __int64 v93; // rcx
  UFG::qVector3 *v94; // rax
  float v95; // xmm0_4
  float v96; // xmm1_4
  signed __int64 v97; // rcx
  UFG::qVector3 *v98; // rax
  float v100; // [rsp+20h] [rbp-138h]
  float v101; // [rsp+24h] [rbp-134h]
  float v102; // [rsp+28h] [rbp-130h]
  unsigned int v103; // [rsp+2Ch] [rbp-12Ch]
  float v104; // [rsp+30h] [rbp-128h]
  float v105; // [rsp+34h] [rbp-124h]
  float v106; // [rsp+38h] [rbp-120h]
  float v107; // [rsp+3Ch] [rbp-11Ch]
  float v108; // [rsp+40h] [rbp-118h]
  float v109; // [rsp+44h] [rbp-114h]
  signed int v110; // [rsp+48h] [rbp-110h]
  float v111; // [rsp+4Ch] [rbp-10Ch]
  __m128 v112; // [rsp+50h] [rbp-108h]
  UFG::HavokNavManager *v113; // [rsp+160h] [rbp+8h]
  float v114; // [rsp+168h] [rbp+10h]
  float v115; // [rsp+170h] [rbp+18h]
  float v116; // [rsp+178h] [rbp+20h]

  v116 = border;
  v115 = spacing;
  v113 = this;
  v5 = border;
  v6 = spacing;
  v7 = this;
  this->m_aTesselationData.size = 0;
  v8 = faceKey & 0x3FFFFF;
  v9 = this->m_world->m_streamingCollection.m_pntr->m_instances.m_data[faceKey >> 22].m_instancePtr;
  if ( !v9 )
    return 0;
  v10 = v9->m_numOriginalFaces;
  if ( v8 < v10 )
  {
    if ( v9->m_faceMap.m_size )
      v12 = v9->m_faceMap.m_data[v8];
    else
      v12 = faceKey & 0x3FFFFF;
    if ( v12 == -1 )
      v11 = (signed __int64)&v9->m_originalFaces[v8];
    else
      v11 = (signed __int64)&v9->m_instancedFaces.m_data[v12];
  }
  else
  {
    v11 = (signed __int64)&v9->m_ownedFaces.m_data[v8 - v10];
  }
  v13 = &this->m_aTmpTesselationData;
  this->m_aTmpTesselationData.size = 0;
  v14 = *(signed __int16 *)(v11 + 8);
  v15 = 0;
  if ( (signed int)v14 > 0 )
  {
    do
    {
      v16 = v15 + *(_DWORD *)v11;
      v17 = v9->m_numOriginalEdges;
      if ( v16 < v17 )
      {
        if ( v9->m_edgeMap.m_size )
          v20 = v9->m_edgeMap.m_data[v16];
        else
          v20 = v15 + *(_DWORD *)v11;
        if ( v20 == -1 )
        {
          v18 = v16;
          v19 = v9->m_originalEdges;
        }
        else
        {
          v18 = v20;
          v19 = v9->m_instancedEdges.m_data;
        }
      }
      else
      {
        v18 = v16 - v17;
        v19 = v9->m_ownedEdges.m_data;
      }
      v21 = v19[v18].m_a;
      v22 = v9->m_numOriginalVertices;
      if ( (signed int)v21 >= v22 )
        v23 = &v9->m_ownedVertices.m_data[(signed int)v21 - v22].m_quad;
      else
        v23 = &v9->m_originalVertices[v21].m_quad;
      v112 = _mm_add_ps(
               v9->m_referenceFrame.m_transform.m_translation.m_quad,
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(*v23, *v23, 85), v9->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                   _mm_mul_ps(_mm_shuffle_ps(*v23, *v23, 0), v9->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                 _mm_mul_ps(_mm_shuffle_ps(*v23, *v23, 170), v9->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)));
      v24 = v13->size;
      v25 = v24 + 1;
      v26 = v7->m_aTmpTesselationData.capacity;
      if ( (signed int)v24 + 1 > v26 )
      {
        if ( v26 )
          v27 = 2 * v26;
        else
          v27 = 1;
        for ( ; v27 < v25; v27 *= 2 )
          ;
        if ( v27 - v25 > 0x10000 )
          v27 = v24 + 65537;
        UFG::qArray<UFG::qVector3,0>::Reallocate(&v7->m_aTmpTesselationData, v27, "qArray.Add");
      }
      v13->size = v25;
      v28 = v24;
      v29 = v7->m_aTmpTesselationData.p;
      *(_QWORD *)&v29[v28].x = v112.m128_u64[0];
      v29[v28].z = v112.m128_f32[2];
      ++v15;
    }
    while ( v15 < (signed int)v14 );
    v6 = spacing;
  }
  v30 = -1;
  v31 = -1;
  v32 = FLOAT_N9_9999998e10;
  v33 = FLOAT_9_9999998e10;
  v34 = 0;
  v35 = 0i64;
  if ( v14 >= 4 )
  {
    v36 = 2;
    v37 = &v7->m_aTmpTesselationData.p[1].y;
    v38 = ((unsigned __int64)(v14 - 4) >> 2) + 1;
    v35 = 4 * v38;
    do
    {
      v39 = *(v37 - 3);
      if ( v39 > v32 )
      {
        v32 = *(v37 - 3);
        v30 = v34;
      }
      if ( v39 < v33 )
      {
        v33 = *(v37 - 3);
        v31 = v34;
      }
      if ( *v37 > v32 )
      {
        v32 = *v37;
        v30 = v36 - 1;
      }
      if ( *v37 < v33 )
      {
        v33 = *v37;
        v31 = v36 - 1;
      }
      v40 = v37[3];
      if ( v40 > v32 )
      {
        v32 = v37[3];
        v30 = v36;
      }
      if ( v40 < v33 )
      {
        v33 = v37[3];
        v31 = v36;
      }
      v41 = v37[6];
      if ( v41 > v32 )
      {
        v32 = v37[6];
        v30 = v36 + 1;
      }
      if ( v41 < v33 )
      {
        v33 = v37[6];
        v31 = v36 + 1;
      }
      v34 += 4;
      v36 += 4;
      v37 += 12;
      --v38;
    }
    while ( v38 );
  }
  if ( v35 < v14 )
  {
    v42 = &v7->m_aTmpTesselationData.p->x + v35 + 2 * v35 + 1;
    v43 = v14 - v35;
    do
    {
      if ( *v42 > v32 )
      {
        v32 = *v42;
        v30 = v34;
      }
      if ( *v42 < v33 )
      {
        v33 = *v42;
        v31 = v34;
      }
      ++v34;
      v42 += 3;
      --v43;
    }
    while ( v43 );
  }
  if ( v30 == -1 || v31 == -1 )
    return 0;
  v44 = v31;
  v103 = v31;
  v45 = v7->m_aTmpTesselationData.p;
  v46 = v45[v31].x;
  v47 = v45[v31].y;
  v106 = v47;
  v48 = v45[v31].z;
  v114 = v48;
  v49 = (unsigned int)((signed int)(v31 + v14 + 1) >> 31);
  LODWORD(v49) = (signed int)(v31 + v14 + 1) % (signed int)v14;
  v50 = v45[v49].x;
  v107 = v45[v49].x;
  v51 = v45[v49].y;
  v52 = v45[v49].z;
  v101 = v45[v49].z;
  v53 = v46;
  v104 = v45[v31].x;
  v54 = v47;
  v108 = v45[v31].y;
  v55 = v48;
  v100 = v45[v31].z;
  v56 = (unsigned int)((signed int)(v31 + v14 - 1) >> 31);
  LODWORD(v56) = (signed int)(v31 + v14 - 1) % (signed int)v14;
  v57 = v45[v56].x;
  v102 = v45[v56].x;
  v58 = v45[v56].y;
  v105 = v45[v56].z;
  v59 = v33 + v5;
  v60 = v32 - v5;
  if ( v59 >= v60 )
    return v7->m_aTesselationData.size != 0;
  v109 = v5 * 2.0;
  v61 = *(float *)&FLOAT_1_0;
  v111 = 1.0 / v6;
  while ( 1 )
  {
    if ( v51 < v59 )
    {
      v62 = v14 + 1;
      v63 = (signed int)(v14 + 1 + v44) % (signed int)v14;
      v64 = v7->m_aTmpTesselationData.p;
      do
      {
        v65 = v63;
        v103 = v63;
        v66 = v63;
        v46 = v64[v66].x;
        v47 = v64[v66].y;
        v106 = v64[v66].y;
        v48 = v64[v66].z;
        v114 = v64[v66].z;
        v67 = (unsigned int)((signed int)(v62 + v65) >> 31);
        LODWORD(v67) = (signed int)(v62 + v65) % (signed int)v14;
        v63 = (signed int)(v62 + v65) % (signed int)v14;
        v50 = v64[v67].x;
        v107 = v64[v67].x;
        v51 = v64[v67].y;
        v52 = v64[v67].z;
        v101 = v64[v67].z;
      }
      while ( v51 < v59 );
      v7 = v113;
    }
    if ( v58 < v59 )
    {
      v68 = v14 - 1;
      v69 = (signed int)(v14 - 1 + v31) % (signed int)v14;
      v70 = v7->m_aTmpTesselationData.p;
      do
      {
        v31 = v69;
        v71 = v69;
        v53 = v70[v71].x;
        v104 = v70[v71].x;
        v54 = v70[v71].y;
        v108 = v70[v71].y;
        v55 = v70[v71].z;
        v100 = v70[v71].z;
        v72 = (unsigned int)((signed int)(v68 + v31) >> 31);
        LODWORD(v72) = (signed int)(v68 + v31) % (signed int)v14;
        v69 = (signed int)(v68 + v31) % (signed int)v14;
        v57 = v70[v72].x;
        v102 = v70[v72].x;
        v58 = v70[v72].y;
        v105 = v70[v72].z;
      }
      while ( v58 < v59 );
    }
    v73 = v61 / (float)(v51 - v47);
    v74 = v73 * (float)(v50 - v46);
    v75 = v73 * (float)(v52 - v48);
    v76 = v105 - v55;
    v77 = 1.0 / (float)(v58 - v54);
    v78 = v77 * (float)(v57 - v53);
    v79 = v59 - v54;
    v80 = (float)((float)(v59 - v54) * v78) + v53;
    v81 = v79 * (float)(v77 * v76);
    v55 = v100;
    v82 = v81 + v100;
    v48 = v114;
    v83 = (float)((float)((float)((float)((float)(v59 - v47) * v74) + v46) - v80) - v109) * v111;
    v110 = (signed int)v83;
    if ( (signed int)v83 > 0 )
      break;
LABEL_92:
    v59 = v59 + v115;
    if ( v59 >= v60 )
      return v7->m_aTesselationData.size != 0;
    v53 = v104;
    v54 = v108;
    v50 = v107;
    v52 = v101;
    v57 = v102;
    v61 = *(float *)&FLOAT_1_0;
    v44 = v103;
  }
  v84 = (float)((float)((float)((float)(v59 - v47) * v75) + v114) - v82) / (float)(signed int)v83;
  v85 = 0;
  while ( !resizeVectorIfNeeded || v7->m_aTesselationData.size != v7->m_aTesselationData.capacity )
  {
    v86 = v7->m_aTesselationData.size;
    v87 = v86 + 1;
    v88 = v7->m_aTesselationData.capacity;
    if ( (signed int)v86 + 1 > v88 )
    {
      if ( v88 )
        v89 = 2 * v88;
      else
        v89 = 1;
      for ( ; v89 < v87; v89 *= 2 )
        ;
      if ( v89 - v87 > 0x10000 )
        v89 = v86 + 65537;
      if ( v89 != (_DWORD)v86 )
      {
        v90 = 12i64 * v89;
        if ( !is_mul_ok(v89, 0xCui64) )
          v90 = -1i64;
        v91 = UFG::qMalloc(v90, "qArray.Add", 0i64);
        if ( v7->m_aTesselationData.p )
        {
          v92 = 0i64;
          if ( v7->m_aTesselationData.size )
          {
            do
            {
              v93 = 3 * v92;
              v94 = v7->m_aTesselationData.p;
              v95 = v94[v92].y;
              v96 = v94[v92].z;
              *(float *)&v91[4 * v93] = v94[v92].x;
              *(float *)&v91[4 * v93 + 4] = v95;
              *(float *)&v91[4 * v93 + 8] = v96;
              v92 = (unsigned int)(v92 + 1);
            }
            while ( (unsigned int)v92 < v7->m_aTesselationData.size );
          }
          operator delete[](v7->m_aTesselationData.p);
        }
        v7->m_aTesselationData.p = (UFG::qVector3 *)v91;
        v7->m_aTesselationData.capacity = v89;
      }
    }
    v7->m_aTesselationData.size = v87;
    v97 = v86;
    v98 = v7->m_aTesselationData.p;
    v98[v97].x = (float)((float)v85 * v115) + (float)(v80 + v116);
    v98[v97].y = v59;
    v98[v97].z = (float)((float)v85++ * v84) + v82;
    if ( v85 >= v110 )
    {
      v47 = v106;
      v48 = v114;
      v55 = v100;
      goto LABEL_92;
    }
  }
  return 1;
}

// File Line: 1235
// RVA: 0xEC510
__int64 __fastcall UFG::HavokNavManager::FindPointOnNavmesh(UFG::HavokNavManager *this, UFG::qVector3 *aabbMin, UFG::qVector3 *aabbMax, unsigned int materialFlags)
{
  unsigned int v4; // er13
  UFG::qVector3 *v5; // rsi
  UFG::qVector3 *v6; // r15
  UFG::HavokNavManager *v7; // rbx
  __m128 v8; // xmm7
  __m128 v9; // xmm6
  hkaiNavMeshQueryMediator *v10; // rax
  int v11; // er8
  bool v12; // zf
  int v13; // er14
  __int64 v14; // rdi
  hkaiStreamingCollection *v15; // rsi
  int v16; // edx
  hkaiNavMeshInstance *v17; // r9
  int v18; // er11
  int v19; // eax
  __int64 v20; // rcx
  _DWORD *v21; // rax
  int v22; // er10
  int v23; // eax
  int v24; // er12
  int v25; // er14
  __int64 v26; // rdi
  int v27; // eax
  int v28; // er8
  int v29; // edi
  __int64 v30; // r14
  float v31; // xmm6_4
  float v32; // xmm7_4
  unsigned int v33; // er9
  unsigned int v34; // ecx
  UFG::qVector3 *v35; // rax
  float v36; // xmm0_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  unsigned int v40; // eax
  int v41; // ecx
  signed __int64 v42; // rdx
  UFG::qVector3 *v43; // rax
  float v44; // xmm1_4
  float v45; // xmm2_4
  unsigned __int8 v46; // bl
  _DWORD *v48; // [rsp+0h] [rbp-79h]
  int range; // [rsp+8h] [rbp-71h]
  int v50; // [rsp+Ch] [rbp-6Dh]
  int v51; // [rsp+18h] [rbp-61h]
  bool resizeVectorIfNeeded[8]; // [rsp+20h] [rbp-59h]
  __int64 v53; // [rsp+28h] [rbp-51h]
  __int64 v54; // [rsp+30h] [rbp-49h]
  __int64 v55; // [rsp+38h] [rbp-41h]
  __m128 v56; // [rsp+48h] [rbp-31h]
  __m128 v57; // [rsp+58h] [rbp-21h]
  UFG::qVector3 *v58; // [rsp+D8h] [rbp+5Fh]
  float v59; // [rsp+E8h] [rbp+6Fh]
  float border; // [rsp+F0h] [rbp+77h]
  float *retaddr; // [rsp+F8h] [rbp+7Fh]

  v54 = -2i64;
  v4 = materialFlags;
  v5 = aabbMax;
  v6 = aabbMin;
  v7 = this;
  v48 = 0i64;
  range = 0;
  v50 = 2147483648;
  v8 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(aabbMax->x), (__m128)LODWORD(aabbMax->z)),
         _mm_unpacklo_ps((__m128)LODWORD(aabbMax->y), (__m128)0i64));
  v9 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(aabbMin->x), (__m128)LODWORD(aabbMin->z)),
         _mm_unpacklo_ps((__m128)LODWORD(aabbMin->y), (__m128)0i64));
  v10 = hkaiWorld::getDynamicQueryMediator(this->m_world);
  if ( !v10 )
    goto LABEL_42;
  v51 = 0;
  *(_QWORD *)resizeVectorIfNeeded = 0i64;
  _mm_store_si128((__m128i *)&v53, (__m128i)0i64);
  v55 = 0i64;
  v56 = v9;
  v57 = v8;
  ((void (__fastcall *)(hkaiNavMeshQueryMediator *, int *, _DWORD **))v10->vfptr[3].__first_virtual_table_function__)(
    v10,
    &v51,
    &v48);
  v11 = range;
  v12 = range == 0;
  if ( !range )
    goto LABEL_42;
  v13 = 0;
  if ( range > 0 )
  {
    v14 = 0i64;
    v15 = v7->m_world->m_streamingCollection.m_pntr;
    do
    {
      v16 = v48[v14] & 0x3FFFFF;
      v17 = v15->m_instances.m_data[v48[v14] >> 22].m_instancePtr;
      v18 = v17->m_faceDataStriding;
      if ( v18 )
      {
        v19 = v17->m_numOriginalFaces;
        if ( v16 < v19 )
        {
          if ( v17->m_faceMap.m_size )
            v22 = v17->m_faceMap.m_data[v16];
          else
            v22 = v48[v14] & 0x3FFFFF;
          if ( v22 == -1 )
          {
            v20 = v16 * v18;
            v21 = v17->m_originalFaceData;
          }
          else
          {
            v20 = v18 * v22;
            v21 = v17->m_instancedFaceData.m_data;
          }
        }
        else
        {
          v20 = v18 * (v16 - v19);
          v21 = v17->m_ownedFaceData.m_data;
        }
        v23 = v21[v20];
      }
      else
      {
        v23 = 0;
      }
      if ( v23 & v4 )
      {
        ++v13;
        ++v14;
      }
      else
      {
        v48[v14] = v48[v11 - 1];
        v11 = range-- - 1;
      }
    }
    while ( v13 < v11 );
    v5 = v58;
    v12 = v11 == 0;
  }
  if ( v12 )
    goto LABEL_42;
  v24 = v11;
  v25 = 0;
  if ( v11 > 0 )
  {
    v26 = 0i64;
    do
    {
      v27 = UFG::qRandom(v24, &UFG::qDefaultSeed);
      v28 = v48[v26];
      v48[v26] = v48[v27];
      v48[v27] = v28;
      ++v25;
      ++v26;
      v11 = range;
    }
    while ( v25 < range );
  }
  v29 = 0;
  if ( v11 > 0 )
  {
    v30 = 0i64;
    v31 = border;
    v32 = v59;
    while ( 1 )
    {
      resizeVectorIfNeeded[0] = 0;
      if ( UFG::HavokNavManager::TesselateFace(v7, v48[v30], v32, v31, 0) )
      {
        v33 = 0;
        v34 = v7->m_aTesselationData.size;
        if ( v34 )
        {
          do
          {
            v35 = v7->m_aTesselationData.p;
            v36 = v35[v33].x;
            if ( v36 < v6->x || v36 > v5->x || (v37 = v35[v33].y, v37 < v6->y) || v37 > v5->y )
            {
              v38 = v35[v34 - 1].y;
              v39 = v35[v34 - 1].z;
              v35[v33].x = v35[v34 - 1].x;
              v35[v33].y = v38;
              v35[v33].z = v39;
              v40 = v7->m_aTesselationData.size;
              if ( v40 > 1 )
                v7->m_aTesselationData.size = v40 - 1;
              else
                v7->m_aTesselationData.size = 0;
            }
            else
            {
              ++v33;
            }
            v34 = v7->m_aTesselationData.size;
          }
          while ( v33 < v34 );
        }
        v41 = v7->m_aTesselationData.size;
        if ( v41 > 0 )
          break;
      }
      ++v29;
      ++v30;
      if ( v29 >= range )
        goto LABEL_42;
    }
    v42 = (unsigned int)UFG::qRandom(v41, &UFG::qDefaultSeed);
    v43 = v7->m_aTesselationData.p;
    v44 = v43[v42].y;
    v45 = v43[v42].z;
    *retaddr = v43[v42].x;
    retaddr[1] = v44;
    retaddr[2] = v45;
    v46 = 1;
  }
  else
  {
LABEL_42:
    v46 = 0;
  }
  range = 0;
  if ( v50 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v48,
      4 * v50);
  return v46;
}

// File Line: 1329
// RVA: 0xE7960
__int64 __fastcall UFG::HavokNavManager::AIRayCastHits(UFG::HavokNavManager *this, UFG::HavokNavPosition *positionStart, UFG::qVector3 *vEnd, UFG::NavParams *navParams, UFG::qVector3 *pCollisionPoint)
{
  __m128 v5; // xmm3
  __m128 v6; // xmm2
  __m128 v7; // xmm0
  UFG::NavManagerVtbl *v8; // r10
  void **v10; // [rsp+30h] [rbp-48h]
  int v11; // [rsp+38h] [rbp-40h]
  int v12; // [rsp+3Ch] [rbp-3Ch]
  int v13; // [rsp+40h] [rbp-38h]
  char v14; // [rsp+48h] [rbp-30h]
  __m128 v15; // [rsp+50h] [rbp-28h]
  __int64 v16; // [rsp+60h] [rbp-18h]

  v5 = (__m128)LODWORD(vEnd->x);
  v6 = (__m128)LODWORD(vEnd->y);
  v7 = (__m128)LODWORD(vEnd->z);
  v8 = this->vfptr;
  v10 = &UFG::HavokNavPosition::`vftable';
  v14 = 0;
  v11 = v5.m128_i32[0];
  v12 = v6.m128_i32[0];
  v13 = v7.m128_i32[0];
  v16 = -1i64;
  v15 = _mm_unpacklo_ps(_mm_unpacklo_ps(v5, v7), _mm_unpacklo_ps(v6, (__m128)(unsigned int)FLOAT_1_0));
  return v8->AIRayCastHits(
           (UFG::NavManager *)&this->vfptr,
           positionStart,
           (UFG::HavokNavPosition *)&v10,
           navParams,
           pCollisionPoint);
}

// File Line: 1336
// RVA: 0xE7280
bool __fastcall UFG::HavokNavManager::AIRayCastHits(UFG::HavokNavManager *this, UFG::HavokNavPosition *positionStart, UFG::HavokNavPosition *positionEnd, UFG::NavParams *navParams)
{
  UFG::NavParams *v4; // r14
  unsigned int *v5; // rbx
  UFG::HavokNavPosition *v6; // rsi
  UFG::HavokNavManager *v7; // r13
  float v8; // xmm10_4
  float *v9; // rax
  bool result; // al
  __m128 v11; // xmm7
  unsigned int v12; // er12
  __m128 v13; // xmm2
  __m128 v14; // xmm3
  float v15; // xmm0_4
  char v16; // di
  float v17; // xmm4_4
  __m128 v18; // xmm0
  float v19; // xmm9_4
  __m128 v20; // xmm0
  __m128 v21; // xmm6
  __m128 v22; // xmm3
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  hkVector4f v25; // xmm4
  __m128 v26; // xmm4
  signed __int64 v27; // rbx
  char v28; // dl
  __int64 v29; // rax
  char v30; // cl
  hkaiLineOfSightUtil::LineOfSightResult v31; // er15
  char v32; // cl
  __m128 v33; // xmm2
  __m128 v34; // xmm2
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  unsigned int v37; // er8
  unsigned int v38; // eax
  unsigned int v39; // ebx
  hkaiDynamicNavMeshQueryMediator *v40; // rax
  unsigned int v41; // er14
  bool v42; // zf
  __m128 v43; // xmm0
  float v44; // xmm12_4
  unsigned int v45; // xmm4_4
  float v46; // xmm5_4
  int v47; // xmm6_4
  float v48; // xmm2_4
  __m128 v49; // xmm3
  float v50; // xmm8_4
  float *v51; // rax
  float *v52; // rax
  float *v53; // rcx
  unsigned int v54; // [rsp+40h] [rbp-88h]
  float v55; // [rsp+44h] [rbp-84h]
  void **v56; // [rsp+48h] [rbp-80h]
  unsigned int v57; // [rsp+50h] [rbp-78h]
  float v58; // [rsp+54h] [rbp-74h]
  float v59; // [rsp+58h] [rbp-70h]
  unsigned int v60; // [rsp+60h] [rbp-68h]
  float v61; // [rsp+64h] [rbp-64h]
  hkVector4f hkvPreviousPoint; // [rsp+68h] [rbp-60h]
  int v63; // [rsp+78h] [rbp-50h]
  unsigned int meshUid; // [rsp+7Ch] [rbp-4Ch]
  hkVector4f hkvPosition; // [rsp+88h] [rbp-40h]
  hkVector4f hkvPoint; // [rsp+98h] [rbp-30h]
  __int64 v67; // [rsp+A8h] [rbp-20h]
  hkVector4f hkvNewPosition; // [rsp+B8h] [rbp-10h]
  hkaiLineOfSightUtil::DirectPathInput input; // [rsp+C8h] [rbp+0h]
  hkaiLineOfSightUtil::LineOfSightOutput output; // [rsp+128h] [rbp+60h]
  unsigned int v71; // [rsp+240h] [rbp+178h]
  UFG::NavParams *v72; // [rsp+250h] [rbp+188h]
  float *v73; // [rsp+258h] [rbp+190h]

  v67 = -2i64;
  v4 = navParams;
  v5 = (unsigned int *)positionEnd;
  v6 = positionStart;
  v7 = this;
  v8 = navParams->m_fRadius;
  positionStart->vfptr->GetMeshPosition((UFG::NavPositionBase *)positionStart, (UFG::qVector3 *)&v54);
  v60 = v54;
  v61 = v55;
  hkvPreviousPoint.m_quad.m128_i32[0] = (signed int)v56;
  if ( v6->vfptr->IsMeshPositionValid((UFG::NavPositionBase *)&v6->vfptr) )
  {
    v6->vfptr->GetMeshPosition((UFG::NavPositionBase *)&v6->vfptr, (UFG::qVector3 *)&v60);
    if ( hkaiWorld::getDynamicQueryMediator(v7->m_world) )
    {
      v11 = v6->m_hkvMeshPosition.m_quad;
      hkvPosition.m_quad = (__m128)v6->m_hkvMeshPosition;
      v12 = v6->m_packedKey;
      if ( (*(unsigned __int8 (__fastcall **)(unsigned int *))(*(_QWORD *)v5 + 32i64))(v5) )
      {
        (*(void (__fastcall **)(unsigned int *, unsigned int *))(*(_QWORD *)v5 + 40i64))(v5, &v57);
        v13 = (__m128)LODWORD(v58);
        v14 = (__m128)v57;
      }
      else
      {
        v14 = (__m128)v5[2];
        v13 = (__m128)v5[3];
        v15 = *((float *)v5 + 4);
        v57 = v5[2];
        v58 = v13.m128_f32[0];
        v59 = v15;
      }
      v16 = 0;
      while ( 1 )
      {
        v17 = v55;
        v18 = (__m128)v54;
        v18.m128_f32[0] = (float)((float)(*(float *)&v54 - v14.m128_f32[0]) * (float)(*(float *)&v54 - v14.m128_f32[0]))
                        + (float)((float)(v55 - v13.m128_f32[0]) * (float)(v55 - v13.m128_f32[0]));
        LODWORD(v19) = (unsigned __int128)_mm_sqrt_ps(v18);
        if ( v19 == 0.0 )
        {
          v52 = v73;
          if ( v73 )
          {
            *v73 = *(float *)&v54;
            v52[1] = v17;
            *((_DWORD *)v52 + 2) = (_DWORD)v56;
          }
          return 1;
        }
        v20 = (__m128)LODWORD(v59);
        v20.m128_f32[0] = v59 - *(float *)&v56;
        v13.m128_f32[0] = v13.m128_f32[0] - v55;
        v14.m128_f32[0] = v14.m128_f32[0] - *(float *)&v54;
        v21 = _mm_unpacklo_ps(_mm_unpacklo_ps(v14, v20), _mm_unpacklo_ps(v13, (__m128)0i64));
        hkaiLineOfSightUtil::DirectPathInput::DirectPathInput(&input);
        hkaiLineOfSightUtil::LineOfSightOutput::LineOfSightOutput(&output);
        input.m_startFaceKey = v12;
        input.m_startPoint.m_quad = v11;
        input.m_maxNumberOfIterations = 4096;
        input.m_up.m_quad = _xmm;
        input.m_agentInfo.m_diameter = v8 * 2.0;
        input.m_agentInfo.m_filterInfo = v4->m_flags;
        v22 = _mm_mul_ps(v21, v21);
        v23 = _mm_add_ps(
                _mm_shuffle_ps(v22, v22, 170),
                _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)));
        v24 = _mm_rsqrt_ps(v23);
        v25.m_quad = _mm_mul_ps(
                       _mm_andnot_ps(
                         _mm_cmpleps(v23, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
                           _mm_mul_ps(v24, *(__m128 *)_xmm))),
                       v21);
        input.m_direction = (hkVector4f)v25.m_quad;
        input.m_searchRadius = (float)(v8 + 0.5) + v19;
        input.m_costModifier = (hkaiAstarCostModifier *)&v7->m_costModifier.vfptr;
        v71 = 953267991;
        if ( _mm_movemask_ps(_mm_cmpunordps(v25.m_quad, v25.m_quad)) & 7
          || (v26 = _mm_mul_ps(v25.m_quad, v25.m_quad),
              COERCE_FLOAT((unsigned int)(2
                                        * COERCE_SIGNED_INT(
                                            (float)(COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 170))
                                                  + (float)(COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 85))
                                                          + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 0))))
                                          - 1.0)) >> 1) >= COERCE_FLOAT(_mm_shuffle_ps((__m128)v71, (__m128)v71, 0))) )
        {
          v51 = v73;
          if ( v73 )
          {
            *v73 = *(float *)&v54;
            v51[1] = v55;
            *((_DWORD *)v51 + 2) = (_DWORD)v56;
          }
          hkaiLineOfSightUtil::LineOfSightOutput::~LineOfSightOutput(&output);
          return 1;
        }
        v27 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
        v28 = ++*(_BYTE *)(v27 + 80);
        v29 = v28;
        *(_DWORD *)(v27 + 4 * v29) = 1;
        *(_QWORD *)(v27 + 8 * v29 + 16) = "AI::hkaiLineOfSightUtil::findDirectPath";
        *(_QWORD *)(v27 + 8 * v29 + 48) = 0i64;
        v30 = *(_BYTE *)(v27 + 81);
        if ( v28 > v30 )
          v30 = v28;
        *(_BYTE *)(v27 + 81) = v30;
        v31 = hkaiLineOfSightUtil::findDirectPath(v7->m_world->m_streamingCollection.m_pntr, &input, &output);
        v32 = *(_BYTE *)(v27 + 80);
        if ( v32 > 0 )
        {
          *(_BYTE *)(v27 + 80) = v32 - 1;
        }
        else
        {
          *(_BYTE *)(v27 + 80) = 0;
          *(_DWORD *)v27 = 3;
          *(_QWORD *)(v27 + 16) = 0i64;
          *(_QWORD *)(v27 + 48) = 0i64;
        }
        *(hkVector4f *)((char *)&hkvPreviousPoint + 8) = output.m_finalPoint;
        if ( v16 )
        {
          v16 = 0;
        }
        else if ( v31 == 4 )
        {
          v33 = _mm_sub_ps(v11, output.m_finalPoint.m_quad);
          v34 = _mm_mul_ps(v33, v33);
          if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 170))
                     + (float)(COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 0)))) < v8
            && UFG::HavokAIUtilGame::FindMeshPositionAwayFromWall(&hkvPosition, &hkvNewPosition, v8) )
          {
            v11 = hkvNewPosition.m_quad;
            hkvPosition.m_quad = hkvNewPosition.m_quad;
            v54 = hkvNewPosition.m_quad.m128_u32[0];
            v35 = _mm_shuffle_ps(hkvNewPosition.m_quad, hkvNewPosition.m_quad, 85);
            v55 = v35.m128_f32[0];
            v36 = _mm_shuffle_ps(hkvNewPosition.m_quad, hkvNewPosition.m_quad, 170);
            v56 = &UFG::HavokNavPosition::`vftable';
            hkvPreviousPoint.m_quad = (__m128)v6->m_hkvMeshPosition;
            v37 = v6->m_packedKey;
            v63 = v37;
            meshUid = -1;
            v57 = hkvNewPosition.m_quad.m128_u32[0];
            v58 = v35.m128_f32[0];
            v59 = v36.m128_f32[0];
            LOBYTE(v60) = 0;
            hkvPoint.m_quad = _mm_unpacklo_ps(
                                _mm_unpacklo_ps(hkvNewPosition.m_quad, v36),
                                _mm_unpacklo_ps(v35, (__m128)(unsigned int)FLOAT_1_0));
            v38 = v37 == -1 ? UFG::HavokAIUtilGame::FindClosestMeshPosition2d(
                                &hkvPoint,
                                0.0099999998,
                                1.0,
                                &hkvPreviousPoint,
                                &meshUid) : UFG::HavokAIUtilGame::FindClosestMeshPosition2dCoherent(
                                              &hkvPoint,
                                              &hkvPreviousPoint,
                                              v37,
                                              0xFFFFFFFF,
                                              0.0099999998,
                                              1.0,
                                              &hkvPreviousPoint,
                                              &meshUid);
            v39 = v38;
            if ( v38 != -1 )
            {
              v40 = (hkaiDynamicNavMeshQueryMediator *)hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
              if ( v40 )
              {
                v41 = meshUid;
                if ( UFG::HavokAIUtilGame::IsFaceKeyValid(v40, v39, meshUid) )
                {
                  v42 = v41 == -1;
                  v4 = v72;
                  if ( !v42 )
                  {
                    v12 = v39;
                    v60 = v54;
                    v61 = v55;
                    hkvPreviousPoint.m_quad.m128_i32[0] = (signed int)v56;
                    v16 = 1;
                  }
                }
                else
                {
                  v4 = v72;
                }
              }
            }
          }
        }
        hkaiLineOfSightUtil::LineOfSightOutput::~LineOfSightOutput(&output);
        if ( !v16 )
          break;
        v13 = (__m128)LODWORD(v58);
        v14 = (__m128)v57;
      }
      if ( v31 == RESULT_INVALID_INPUT )
        goto LABEL_48;
      v43 = (__m128)LODWORD(v55);
      v43.m128_f32[0] = (float)((float)(v55 - hkvPreviousPoint.m_quad.m128_f32[3])
                              * (float)(v55 - hkvPreviousPoint.m_quad.m128_f32[3]))
                      + (float)((float)(*(float *)&v54 - hkvPreviousPoint.m_quad.m128_f32[2])
                              * (float)(*(float *)&v54 - hkvPreviousPoint.m_quad.m128_f32[2]));
      LODWORD(v44) = (unsigned __int128)_mm_sqrt_ps(v43);
      v45 = v57;
      v46 = v58;
      v49 = (__m128)LODWORD(v58);
      v47 = LODWORD(v59);
      v48 = v59 - *(float *)&v56;
      v49.m128_f32[0] = (float)((float)((float)(v58 - v55) * (float)(v58 - v55))
                              + (float)((float)(*(float *)&v57 - *(float *)&v54)
                                      * (float)(*(float *)&v57 - *(float *)&v54)))
                      + (float)(v48 * v48);
      if ( v49.m128_f32[0] == 0.0 )
        v50 = 0.0;
      else
        v50 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v49));
      if ( v44 >= (float)(v19 - 0.0099999998) && COERCE_FLOAT(COERCE_UNSIGNED_INT(v48 * v50) & _xmm) <= 0.70710677 )
      {
        result = 0;
        goto LABEL_50;
      }
      v46 = hkvPreviousPoint.m_quad.m128_f32[3];
      v45 = hkvPreviousPoint.m_quad.m128_u32[2];
      v47 = v63;
    }
    else
    {
LABEL_48:
      v47 = hkvPreviousPoint.m_quad.m128_i32[0];
      v46 = v61;
      v45 = v60;
    }
    result = 1;
LABEL_50:
    v53 = v73;
    if ( v73 )
    {
      *(_DWORD *)v73 = v45;
      v53[1] = v46;
      *((_DWORD *)v53 + 2) = v47;
    }
  }
  else
  {
    v9 = v73;
    if ( v73 )
    {
      *v73 = *(float *)&v54;
      v9[1] = v55;
      *((_DWORD *)v9 + 2) = (_DWORD)v56;
    }
    result = 1;
  }
  return result;
}

// File Line: 1572
// RVA: 0xEF940
void __fastcall UFG::HavokNavManager::LoadNavMesh(UFG::HavokNavManager *this, unsigned int meshUid, const char *meshName, const char *navmeshData, unsigned int navmeshSize, const char *mediatorTreeData, unsigned int mediatorTreeSize, const char *userEdgesData, unsigned int userEdgesSize)
{
  char *v9; // rdi
  signed __int64 v10; // rbx
  char v11; // dl
  __int64 v12; // rax
  hkaiNavMeshInstance *v13; // rbp
  char v14; // cl
  char *v15; // rax
  UFG::NativePackfileUtils::Fixups *v16; // r15
  char *v17; // rdi
  char v18; // cl
  char v19; // dl
  __int64 v20; // rax
  char v21; // cl
  char *v22; // rax
  UFG::NativePackfileUtils::Fixups *v23; // r14
  char *v24; // rsi
  _QWORD **v25; // rax
  hkaiStaticTreeNavMeshQueryMediator *v26; // rax
  hkaiStaticTreeNavMeshQueryMediator *v27; // rax
  hkaiStaticTreeNavMeshQueryMediator *v28; // r12
  char v29; // al
  char v30; // r9
  __int64 v31; // rax
  char v32; // r8
  char *v33; // rax
  UFG::NativePackfileUtils::Fixups *v34; // rsi
  unsigned int v35; // er13
  char v36; // cl
  char v37; // dl
  __int64 v38; // rax
  char v39; // cl
  _QWORD **v40; // rax
  hkaiNavMeshInstance *v41; // rax
  hkaiNavMeshInstance *v42; // rax
  unsigned int v43; // er8
  char v44; // al
  char v45; // dl
  __int64 v46; // rax
  char v47; // cl
  char *v48; // rax
  UFG::HavokNavManager::MeshCell *v49; // rax
  UFG::HavokNavManager::MeshCell *v50; // rdi
  char v51; // al
  char v52; // dl
  __int64 v53; // rax
  char v54; // cl
  char v55; // al
  hkaiUserEdgePairArray *v56; // rax
  unsigned int v57; // er9
  unsigned int v58; // ecx
  __int64 v59; // rdx
  __int64 v60; // r8
  hkaiUserEdgeUtils::UserEdgePair *v61; // rcx
  char v62; // dl
  __int64 v63; // rax
  char v64; // cl
  char v65; // al
  hkaiUserEdgePairArray *userEdges; // [rsp+50h] [rbp-58h]
  UFG::HavokNavManager *v67; // [rsp+B0h] [rbp+8h]
  unsigned int id; // [rsp+B8h] [rbp+10h]
  const char *v69; // [rsp+C8h] [rbp+20h]

  v69 = navmeshData;
  id = meshUid;
  v67 = this;
  v9 = (char *)navmeshData;
  UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_AIHavok, OUTPUT_LEVEL_DEBUG, "[AIHavok] LoadNavMesh(0x%x) (%s)...\n");
  v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v11 = ++*(_BYTE *)(v10 + 80);
  v12 = v11;
  *(_DWORD *)(v10 + 4 * v12) = 1;
  *(_QWORD *)(v10 + 8 * v12 + 16) = "HavokNavManager";
  v13 = 0i64;
  *(_QWORD *)(v10 + 8 * v12 + 48) = 0i64;
  v14 = *(_BYTE *)(v10 + 81);
  if ( v11 > v14 )
    v14 = v11;
  *(_BYTE *)(v10 + 81) = v14;
  v15 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x20ui64, "NativePackfileUtils::meshFixups", 0i64, 1u);
  v16 = (UFG::NativePackfileUtils::Fixups *)v15;
  if ( v15 )
  {
    *(_QWORD *)v15 = 0i64;
    *((_DWORD *)v15 + 2) = 0;
    *((_DWORD *)v15 + 3) = 2147483648;
    *((_QWORD *)v15 + 2) = 0i64;
    *((_DWORD *)v15 + 6) = 0;
    *((_DWORD *)v15 + 7) = 2147483648;
  }
  else
  {
    v16 = 0i64;
  }
  v17 = UFG::NativePackfileUtils::loadInPlace(v9, navmeshSize, v16);
  v18 = *(_BYTE *)(v10 + 80);
  if ( v18 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v18 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  v19 = ++*(_BYTE *)(v10 + 80);
  v20 = v19;
  *(_DWORD *)(v10 + 4 * v20) = 1;
  *(_QWORD *)(v10 + 8 * v20 + 16) = "HavokNavManager";
  *(_QWORD *)(v10 + 8 * v20 + 48) = 1i64;
  v21 = *(_BYTE *)(v10 + 81);
  if ( v19 > v21 )
    v21 = v19;
  *(_BYTE *)(v10 + 81) = v21;
  v22 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x20ui64, "NativePackfileUtils::meshFixups", 0i64, 1u);
  v23 = (UFG::NativePackfileUtils::Fixups *)v22;
  if ( v22 )
  {
    *(_QWORD *)v22 = 0i64;
    *((_DWORD *)v22 + 2) = 0;
    *((_DWORD *)v22 + 3) = 2147483648;
    *((_QWORD *)v22 + 2) = 0i64;
    *((_DWORD *)v22 + 6) = 0;
    *((_DWORD *)v22 + 7) = 2147483648;
  }
  else
  {
    v23 = 0i64;
  }
  v24 = UFG::NativePackfileUtils::loadInPlace((void *)mediatorTreeData, mediatorTreeSize, v23);
  v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v26 = (hkaiStaticTreeNavMeshQueryMediator *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v25[11] + 8i64))(
                                                v25[11],
                                                32i64);
  if ( v26 )
  {
    hkaiStaticTreeNavMeshQueryMediator::hkaiStaticTreeNavMeshQueryMediator(v26);
    v28 = v27;
  }
  else
  {
    v28 = 0i64;
  }
  hkaiStaticTreeNavMeshQueryMediator::setNavMeshAndTree(v28, (hkaiNavMesh *)v17, (hkcdStaticAabbTree *)v24);
  hkReferencedObject::removeReference((hkReferencedObject *)v24);
  v29 = *(_BYTE *)(v10 + 80);
  if ( v29 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v29 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  v30 = ++*(_BYTE *)(v10 + 80);
  v31 = v30;
  *(_DWORD *)(v10 + 4 * v31) = 1;
  *(_QWORD *)(v10 + 8 * v31 + 16) = "HavokNavManager";
  *(_QWORD *)(v10 + 8 * v31 + 48) = 0i64;
  v32 = *(_BYTE *)(v10 + 81);
  if ( v30 > v32 )
    v32 = v30;
  *(_BYTE *)(v10 + 81) = v32;
  v33 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x20ui64, "NativePackfileUtils::edgesFixups", 0i64, 1u);
  v34 = (UFG::NativePackfileUtils::Fixups *)v33;
  if ( v33 )
  {
    *(_QWORD *)v33 = 0i64;
    *((_DWORD *)v33 + 2) = 0;
    *((_DWORD *)v33 + 3) = 2147483648;
    *((_QWORD *)v33 + 2) = 0i64;
    *((_DWORD *)v33 + 6) = 0;
    *((_DWORD *)v33 + 7) = 2147483648;
  }
  else
  {
    v34 = 0i64;
  }
  v35 = userEdgesSize;
  userEdges = (hkaiUserEdgePairArray *)UFG::NativePackfileUtils::loadInPlace((void *)userEdgesData, userEdgesSize, v34);
  v36 = *(_BYTE *)(v10 + 80);
  if ( v36 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v36 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  if ( *((_QWORD *)v17 + 21) != 1i64 )
  {
    v37 = ++*(_BYTE *)(v10 + 80);
    v38 = v37;
    *(_DWORD *)(v10 + 4 * v38) = 1;
    *(_QWORD *)(v10 + 8 * v38 + 16) = "HavokNavManager";
    *(_QWORD *)(v10 + 8 * v38 + 48) = 0i64;
    v39 = *(_BYTE *)(v10 + 81);
    if ( v37 > v39 )
      v39 = v37;
    *(_BYTE *)(v10 + 81) = v39;
    v40 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v41 = (hkaiNavMeshInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v40[11] + 8i64))(
                                   v40[11],
                                   480i64);
    if ( v41 )
    {
      hkaiNavMeshInstance::hkaiNavMeshInstance(v41);
      v13 = v42;
    }
    else
    {
      v13 = 0i64;
    }
    v43 = id;
    if ( *((_DWORD *)v17 + 18) > 0 )
      v43 = **((_DWORD **)v17 + 8);
    hkaiNavMeshInstance::init(v13, (hkaiNavMesh *)v17, v43, 1);
    v44 = *(_BYTE *)(v10 + 80);
    if ( v44 > 0 )
    {
      *(_BYTE *)(v10 + 80) = v44 - 1;
    }
    else
    {
      *(_BYTE *)(v10 + 80) = 0;
      *(_DWORD *)v10 = 3;
      *(_QWORD *)(v10 + 16) = 0i64;
      *(_QWORD *)(v10 + 48) = 0i64;
    }
  }
  hkReferencedObject::addReference((hkReferencedObject *)v17);
  v45 = ++*(_BYTE *)(v10 + 80);
  v46 = v45;
  *(_DWORD *)(v10 + 4 * v46) = 1;
  *(_QWORD *)(v10 + 8 * v46 + 16) = "AI::LoadNavMesh::MeshCell";
  *(_QWORD *)(v10 + 8 * v46 + 48) = 0i64;
  v47 = *(_BYTE *)(v10 + 81);
  if ( v45 > v47 )
    v47 = v45;
  *(_BYTE *)(v10 + 81) = v47;
  v48 = UFG::qMalloc(0xB0ui64, "AI::MeshCell", 0i64);
  if ( v48 )
  {
    UFG::HavokNavManager::MeshCell::MeshCell(
      (UFG::HavokNavManager::MeshCell *)v48,
      (hkaiNavMesh *)v17,
      v13,
      0i64,
      (hkaiNavMeshQueryMediator *)&v28->vfptr,
      userEdges,
      (hkAabb *)v17 + 4,
      id,
      0i64);
    v50 = v49;
  }
  else
  {
    v50 = 0i64;
  }
  v50->m_meshFixups = v16;
  v50->m_mediatorTreeFixups = v23;
  v50->m_edgesFixups = v34;
  v50->m_meshBuffer = (void *)v69;
  v50->m_meshBufferSize = navmeshSize;
  v50->m_mediatorTreeBuffer = (void *)mediatorTreeData;
  v50->m_mediatorTreeBufferSize = mediatorTreeSize;
  v50->m_edgesBuffer = (void *)userEdgesData;
  v50->m_edgesBufferSize = v35;
  if ( v67->m_cells.m_size == (v67->m_cells.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v67->m_cells, 8);
  v67->m_cells.m_data[v67->m_cells.m_size++] = v50;
  v51 = *(_BYTE *)(v10 + 80);
  if ( v51 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v51 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  if ( v13 )
  {
    ((void (__fastcall *)(UFG::HavokNavManager *, _QWORD, hkaiNavMeshInstance *))v67->vfptr[1].ExitGame)(v67, 0i64, v13);
    v52 = ++*(_BYTE *)(v10 + 80);
    v53 = v52;
    *(_DWORD *)(v10 + 4 * v53) = 1;
    *(_QWORD *)(v10 + 8 * v53 + 16) = "HavokNavManager";
    *(_QWORD *)(v10 + 8 * v53 + 48) = 1i64;
    v54 = *(_BYTE *)(v10 + 81);
    if ( v52 > v54 )
      v54 = v52;
    *(_BYTE *)(v10 + 81) = v54;
    hkaiWorld::loadNavMeshInstance(v67->m_world, v13, (hkaiNavMeshQueryMediator *)&v28->vfptr, 0i64);
    v55 = *(_BYTE *)(v10 + 80);
    if ( v55 > 0 )
    {
      *(_BYTE *)(v10 + 80) = v55 - 1;
    }
    else
    {
      *(_BYTE *)(v10 + 80) = 0;
      *(_DWORD *)v10 = 3;
      *(_QWORD *)(v10 + 16) = 0i64;
      *(_QWORD *)(v10 + 48) = 0i64;
    }
    v56 = v50->m_userEdges;
    if ( v56 )
    {
      v57 = v13->m_sectionUid;
      v58 = v56->m_edgePairs.m_size;
      if ( v58 )
      {
        v59 = 0i64;
        v60 = v58;
        do
        {
          v61 = v50->m_userEdges->m_edgePairs.m_data;
          v61[v59].m_instanceUidA = v57;
          v61[v59].m_instanceUidB = v57;
          ++v59;
          --v60;
        }
        while ( v60 );
      }
      v62 = ++*(_BYTE *)(v10 + 80);
      v63 = v62;
      *(_DWORD *)(v10 + 4 * v63) = 1;
      *(_QWORD *)(v10 + 8 * v63 + 16) = "HavokNavManager";
      *(_QWORD *)(v10 + 8 * v63 + 48) = 0i64;
      v64 = *(_BYTE *)(v10 + 81);
      if ( v62 > v64 )
        v64 = v62;
      *(_BYTE *)(v10 + 81) = v64;
      LOWORD(navmeshSize) = 256;
      BYTE2(navmeshSize) = 0;
      hkaiUserEdgeUtils::addUserEdgePairsBatch(
        v67->m_world->m_streamingCollection.m_pntr,
        (hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> *)&v50->m_userEdges->m_edgePairs.m_data,
        (hkaiUserEdgeUtils::UpdateParameters *)&navmeshSize);
      v65 = *(_BYTE *)(v10 + 80);
      if ( v65 > 0 )
      {
        *(_BYTE *)(v10 + 80) = v65 - 1;
      }
      else
      {
        *(_BYTE *)(v10 + 80) = 0;
        *(_DWORD *)v10 = 3;
        *(_QWORD *)(v10 + 16) = 0i64;
        *(_QWORD *)(v10 + 48) = 0i64;
      }
    }
  }
  UFG::HavokNavManager::Defrag(v67, DefragVerbosity_Hide);
}

// File Line: 1725
// RVA: 0xF2360
void __fastcall UFG::HavokNavManager::UnloadNavMesh(UFG::HavokNavManager *this, unsigned int meshUid)
{
  UFG::HavokNavManager *v2; // rdi
  unsigned int v3; // ecx
  unsigned int v4; // er14
  unsigned int v5; // ebp
  UFG::HavokNavManager::MeshCell **v6; // r8
  signed __int64 v7; // r12
  UFG::HavokNavManager::MeshCell *v8; // rbx
  signed __int64 v9; // r15
  char v10; // dl
  __int64 v11; // rax
  char v12; // cl
  hkaiStreamingCollection *v13; // rsi
  __int64 v14; // r10
  int v15; // ecx
  __int64 v16; // rdx
  hkaiNavMeshInstance **v17; // rax
  int v18; // eax
  hkaiDirectedGraphInstance *v19; // r8
  bool v20; // zf
  UFG::NativePackfileUtils::Fixups *v21; // rsi
  UFG::NativePackfileUtils::Fixups *v22; // rsi
  UFG::NativePackfileUtils::Fixups *v23; // rsi
  hkaiDirectedGraphExplicitCost *v24; // rcx
  hkaiNavMeshQueryMediator *v25; // rcx
  __int64 v26; // rax
  char v27; // al
  UFG::NavComponent *v28; // rax

  v2 = this;
  v3 = this->m_cells.m_size;
  v4 = meshUid;
  v5 = 0;
  if ( v3 )
  {
    v6 = v2->m_cells.m_data;
    while ( (*v6)->m_id != meshUid )
    {
      ++v5;
      ++v6;
      if ( v5 >= v3 )
        return;
    }
    v7 = (signed int)v5;
    v8 = v2->m_cells.m_data[v7];
    v9 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v10 = ++*(_BYTE *)(v9 + 80);
    v11 = v10;
    *(_DWORD *)(v9 + 4 * v11) = 1;
    *(_QWORD *)(v9 + 8 * v11 + 16) = "AI::UnloadNavMesh";
    *(_QWORD *)(v9 + 8 * v11 + 48) = 0i64;
    v12 = *(_BYTE *)(v9 + 81);
    if ( v10 > v12 )
      v12 = v10;
    *(_BYTE *)(v9 + 81) = v12;
    if ( v8->m_Instances.m_size )
    {
      hkaiUserEdgeUtils::removeUserEdges(*v8->m_Instances.m_data, v2->m_world->m_streamingCollection.m_pntr);
      v13 = v2->m_world->m_streamingCollection.m_pntr;
      while ( v8->m_Instances.m_size )
      {
        v14 = v2->m_StitchInstances.m_size;
        v15 = 0;
        v16 = 0i64;
        if ( (signed int)v14 > 0 )
        {
          v17 = v2->m_StitchInstances.m_data;
          while ( *v17 != *v8->m_Instances.m_data )
          {
            ++v16;
            ++v15;
            ++v17;
            if ( v16 >= v14 )
              goto LABEL_18;
          }
          if ( v16 != -1 )
          {
            v2->m_StitchInstances.m_size = v14 - 1;
            if ( (_DWORD)v14 - 1 != v15 )
              v2->m_StitchInstances.m_data[v16] = v2->m_StitchInstances.m_data[(signed int)v14 - 1];
          }
        }
LABEL_18:
        v18 = hkaiStreamingCollection::findSectionIdByUid(v13, (*v8->m_Instances.m_data)->m_sectionUid);
        if ( v18 != -1 )
        {
          if ( v18 >= 0 )
            v19 = v13->m_instances.m_data[v18].m_clusterGraphInstance;
          else
            v19 = 0i64;
          hkaiWorld::unloadNavMeshInstance(v2->m_world, *v8->m_Instances.m_data, v19);
        }
        hkReferencedObject::removeReference(*(hkReferencedObject **)v8->m_Instances.m_data);
        v20 = v8->m_Instances.m_size-- == 1;
        if ( !v20 )
          *v8->m_Instances.m_data = v8->m_Instances.m_data[v8->m_Instances.m_size];
      }
    }
    v21 = (UFG::NativePackfileUtils::Fixups *)v8->m_mediatorTreeFixups;
    UFG::NativePackfileUtils::unloadInPlace(
      v8->m_mediatorTreeBuffer,
      v8->m_mediatorTreeBufferSize,
      (UFG::NativePackfileUtils::Fixups *)v8->m_mediatorTreeFixups);
    if ( v21 )
    {
      UFG::NativePackfileUtils::Fixups::~Fixups(v21);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v21);
    }
    v22 = (UFG::NativePackfileUtils::Fixups *)v8->m_meshFixups;
    UFG::NativePackfileUtils::unloadInPlace(
      v8->m_meshBuffer,
      v8->m_meshBufferSize,
      (UFG::NativePackfileUtils::Fixups *)v8->m_meshFixups);
    if ( v22 )
    {
      UFG::NativePackfileUtils::Fixups::~Fixups(v22);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v22);
    }
    v23 = (UFG::NativePackfileUtils::Fixups *)v8->m_edgesFixups;
    UFG::NativePackfileUtils::unloadInPlace(
      v8->m_edgesBuffer,
      v8->m_edgesBufferSize,
      (UFG::NativePackfileUtils::Fixups *)v8->m_edgesFixups);
    if ( v23 )
    {
      UFG::NativePackfileUtils::Fixups::~Fixups(v23);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v23);
    }
    v24 = v8->m_clusterGraph;
    if ( v24 )
      v24->vfptr->__vecDelDtor((hkBaseObject *)&v24->vfptr, 1u);
    v25 = v8->m_mediator;
    if ( v25 )
      v25->vfptr->__vecDelDtor((hkBaseObject *)&v25->vfptr, 1u);
    hkReferencedObject::removeReference((hkReferencedObject *)&v8->m_mesh->vfptr);
    UFG::HavokNavManager::MeshCell::~MeshCell(v8);
    operator delete[](v8);
    v26 = --v2->m_cells.m_size;
    if ( (_DWORD)v26 != v5 )
      v2->m_cells.m_data[v7] = v2->m_cells.m_data[v26];
    v27 = *(_BYTE *)(v9 + 80);
    if ( v27 > 0 )
    {
      *(_BYTE *)(v9 + 80) = v27 - 1;
    }
    else
    {
      *(_BYTE *)(v9 + 80) = 0;
      *(_DWORD *)v9 = 3;
      *(_QWORD *)(v9 + 16) = 0i64;
      *(_QWORD *)(v9 + 48) = 0i64;
    }
    UFG::HavokNavManager::Defrag(v2, DefragVerbosity_Hide);
    v28 = (UFG::NavComponent *)&UFG::NavComponent::s_NavComponentList.mNode.mNext[-4];
    for ( UFG::NavComponent::s_NavComponentpCurrentIterator = (UFG::NavComponent *)&UFG::NavComponent::s_NavComponentList.mNode.mNext[-4];
          v28 != (UFG::NavComponent *)(&UFG::NavComponent::s_NavComponentList - 4);
          UFG::NavComponent::s_NavComponentpCurrentIterator = v28 )
    {
      if ( v28->m_navPosition.m_aiMeshUid == v4 )
      {
        ((void (*)(void))v28->m_navPosition.vfptr->SetInvalidMeshPosition)();
        v28 = UFG::NavComponent::s_NavComponentpCurrentIterator;
      }
      v28 = (UFG::NavComponent *)&v28->mNext[-4];
    }
    UFG::NavComponent::s_NavComponentpCurrentIterator = 0i64;
  }
}

// File Line: 1847
// RVA: 0xF0FA0
void __fastcall UFG::HavokNavManager::SpawnNavMeshInstance(UFG::HavokNavManager *this, UFG::qMatrix44 *transform, unsigned int meshUid, unsigned int meshInstanceUid)
{
  unsigned int v4; // er15
  UFG::qMatrix44 *v5; // r12
  UFG::HavokNavManager *v6; // rbp
  UFG::HavokNavManager::MeshCell *v7; // r14
  signed __int64 v8; // rsi
  char v9; // dl
  __int64 v10; // rcx
  int v11; // ebx
  char v12; // cl
  _QWORD **v13; // rax
  hkaiNavMeshInstance *v14; // rax
  hkaiNavMeshInstance *v15; // rax
  hkaiNavMeshInstance *v16; // rdi
  hkArray<hkaiNavMeshInstance *,hkContainerHeapAllocator> *v17; // r14
  char v18; // al
  __int64 v19; // r8
  __int64 v20; // rcx
  hkaiNavMeshInstance **v21; // rax
  hkTransformf out; // [rsp+30h] [rbp-58h]

  v4 = meshInstanceUid;
  v5 = transform;
  v6 = this;
  v7 = UFG::HavokNavManager::FindLoadedCell(this, meshUid);
  if ( v7 )
  {
    v8 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v9 = ++*(_BYTE *)(v8 + 80);
    v10 = v9;
    *(_DWORD *)(v8 + 4 * v10) = 1;
    *(_QWORD *)(v8 + 8 * v10 + 16) = "AI::SpawnNavMeshInstance";
    v11 = 0;
    *(_QWORD *)(v8 + 8 * v10 + 48) = 0i64;
    v12 = *(_BYTE *)(v8 + 81);
    if ( v9 > v12 )
      v12 = v9;
    *(_BYTE *)(v8 + 81) = v12;
    v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = (hkaiNavMeshInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v13[11] + 8i64))(
                                   v13[11],
                                   480i64);
    if ( v14 )
    {
      hkaiNavMeshInstance::hkaiNavMeshInstance(v14);
      v16 = v15;
    }
    else
    {
      v16 = 0i64;
    }
    hkaiNavMeshInstance::init(v16, v7->m_mesh, v4, 1);
    v17 = &v7->m_Instances;
    if ( v17->m_size == (v17->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v17, 8);
    v17->m_data[v17->m_size++] = v16;
    v18 = *(_BYTE *)(v8 + 80);
    if ( v18 > 0 )
    {
      *(_BYTE *)(v8 + 80) = v18 - 1;
    }
    else
    {
      *(_BYTE *)(v8 + 80) = 0;
      *(_DWORD *)v8 = 3;
      *(_QWORD *)(v8 + 16) = 0i64;
      *(_QWORD *)(v8 + 48) = 0i64;
    }
    UFG::qMatrix44_To_hkTransform(&out, v5);
    v16->m_referenceFrame.m_transform.m_rotation.m_col0 = out.m_rotation.m_col0;
    v16->m_referenceFrame.m_transform.m_rotation.m_col1 = out.m_rotation.m_col1;
    v16->m_referenceFrame.m_transform.m_rotation.m_col2 = out.m_rotation.m_col2;
    v16->m_referenceFrame.m_transform.m_translation = out.m_translation;
    v19 = v6->m_StitchInstances.m_size;
    v20 = 0i64;
    if ( (signed int)v19 <= 0 )
      goto LABEL_18;
    v21 = v6->m_StitchInstances.m_data;
    while ( *v21 != v16 )
    {
      ++v11;
      ++v20;
      ++v21;
      if ( v20 >= v19 )
        goto LABEL_18;
    }
    if ( v11 == -1 )
    {
LABEL_18:
      if ( (_DWORD)v19 == (v6->m_StitchInstances.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v6->m_StitchInstances,
          8);
      v6->m_StitchInstances.m_data[v6->m_StitchInstances.m_size++] = v16;
      v6->m_StitchingDelay = 100;
    }
  }
}

// File Line: 1875
// RVA: 0xE9AB0
void __fastcall UFG::HavokNavManager::DespawnNavMeshInstance(UFG::HavokNavManager *this, unsigned int meshUid, unsigned int meshInstanceUid)
{
  unsigned int v3; // er14
  UFG::HavokNavManager *v4; // r15
  UFG::HavokNavManager::MeshCell *v5; // rax
  UFG::HavokNavManager::MeshCell *v6; // rbp
  __int64 v7; // rdx
  int v8; // edi
  int v9; // esi
  __int64 v10; // rbx
  hkaiNavMeshInstance **v11; // rcx
  hkaiWorld *v12; // rax
  hkaiStreamingCollection *v13; // r13
  int v14; // eax
  hkaiDirectedGraphInstance *v15; // r8
  __int64 v16; // r9
  __int64 v17; // rcx
  hkaiNavMeshInstance **v18; // rax
  __int64 v19; // rax

  v3 = meshInstanceUid;
  v4 = this;
  v5 = UFG::HavokNavManager::FindLoadedCell(this, meshUid);
  v6 = v5;
  if ( v5 )
  {
    v7 = v5->m_Instances.m_size;
    v8 = 0;
    v9 = 0;
    v10 = 0i64;
    if ( v7 > 0 )
    {
      v11 = v5->m_Instances.m_data;
      while ( (*v11)->m_sectionUid != v3 )
      {
        ++v10;
        ++v9;
        ++v11;
        if ( v10 >= v7 )
          return;
      }
      v12 = v4->m_world;
      v13 = v12->m_streamingCollection.m_pntr;
      v14 = hkaiStreamingCollection::findSectionIdByUid(v12->m_streamingCollection.m_pntr, v3);
      if ( v14 != -1 )
      {
        if ( v14 >= 0 )
          v15 = v13->m_instances.m_data[v14].m_clusterGraphInstance;
        else
          v15 = 0i64;
        hkaiWorld::unloadNavMeshInstance(v4->m_world, v6->m_Instances.m_data[v9], v15);
      }
      v16 = v4->m_StitchInstances.m_size;
      v17 = 0i64;
      if ( (signed int)v16 > 0 )
      {
        v18 = v4->m_StitchInstances.m_data;
        while ( *v18 != v6->m_Instances.m_data[v10] )
        {
          ++v17;
          ++v8;
          ++v18;
          if ( v17 >= v16 )
            goto LABEL_20;
        }
        if ( v8 != -1 )
        {
          v4->m_StitchInstances.m_size = v16 - 1;
          if ( (_DWORD)v16 - 1 != v8 )
            v4->m_StitchInstances.m_data[v8] = v4->m_StitchInstances.m_data[(signed int)v16 - 1];
        }
      }
LABEL_20:
      hkReferencedObject::removeReference((hkReferencedObject *)&v6->m_Instances.m_data[v9]->vfptr);
      v19 = --v6->m_Instances.m_size;
      if ( (_DWORD)v19 != v9 )
        v6->m_Instances.m_data[v9] = v6->m_Instances.m_data[v19];
    }
  }
}

// File Line: 1920
// RVA: 0xEAB50
UFG::HavokNavManager::MeshCell *__fastcall UFG::HavokNavManager::FindLoadedCell(UFG::HavokNavManager *this, unsigned int uniqueId)
{
  __int64 v2; // rdi
  int v3; // ebx
  __int64 v4; // r11
  unsigned int v5; // er9
  UFG::HavokNavManager::MeshCell **v6; // r10
  UFG::HavokNavManager::MeshCell *v7; // rax
  __int64 v8; // r8
  __int64 v9; // rdx
  hkaiNavMeshInstance **v10; // rax

  v2 = this->m_cells.m_size;
  v3 = 0;
  v4 = 0i64;
  v5 = uniqueId;
  if ( v2 <= 0 )
    return 0i64;
  v6 = this->m_cells.m_data;
  while ( 1 )
  {
    v7 = *v6;
    if ( (*v6)->m_id == v5 )
      return this->m_cells.m_data[v3];
    v8 = v7->m_Instances.m_size;
    v9 = 0i64;
    if ( v8 > 0 )
    {
      v10 = v7->m_Instances.m_data;
      while ( (*v10)->m_sectionUid != v5 )
      {
        ++v9;
        ++v10;
        if ( v9 >= v8 )
          goto LABEL_8;
      }
      return this->m_cells.m_data[v3];
    }
LABEL_8:
    ++v4;
    ++v3;
    ++v6;
    if ( v4 >= v2 )
      return 0i64;
  }
}

// File Line: 1940
// RVA: 0xF0010
void __fastcall UFG::HavokNavManager::PrintMeshInstances(UFG::HavokNavManager *this)
{
  UFG::HavokNavManager *v1; // r15
  int v2; // er13
  __int64 v3; // r14
  UFG::HavokNavManager::MeshCell *v4; // rcx
  int v5; // eax
  int v6; // edx
  __int64 v7; // rsi
  __int64 v8; // r12
  int v9; // er11
  int v10; // edi
  UFG::HavokNavManager::MeshCell **v11; // rbx
  int v12; // eax
  int v13; // er8
  hkaiNavMeshInstance **v14; // rdx
  hkaiStreamingSet *v15; // rcx
  __int64 v16; // [rsp+20h] [rbp-68h]
  UFG::qString v17; // [rsp+38h] [rbp-50h]

  v1 = this;
  v2 = 0;
  if ( this->m_cells.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = v1->m_cells.m_data[v3];
      v5 = 0;
      v6 = v4->m_Instances.m_size;
      if ( v6 > 0 )
      {
        do
          ++v5;
        while ( v5 < v6 );
      }
      if ( v4->m_mesh->m_streamingSets.m_size )
      {
        v7 = 0i64;
        v8 = (unsigned int)v4->m_mesh->m_streamingSets.m_size;
        do
        {
          UFG::qString::qString(&v17, "notFound");
          v9 = 0;
          v10 = v1->m_cells.m_size;
          if ( v10 > 0 )
          {
            v11 = v1->m_cells.m_data;
            while ( 1 )
            {
              v12 = 0;
              v13 = (*v11)->m_Instances.m_size;
              if ( v13 > 0 )
                break;
LABEL_13:
              ++v9;
              ++v11;
              if ( v9 >= v10 )
                goto LABEL_14;
            }
            v14 = (*v11)->m_Instances.m_data;
            while ( (*v14)->m_sectionUid != v1->m_cells.m_data[v3]->m_mesh->m_streamingSets.m_data[v7].m_oppositeUid )
            {
              ++v12;
              ++v14;
              if ( v12 >= v13 )
                goto LABEL_13;
            }
          }
LABEL_14:
          v15 = v1->m_cells.m_data[v3]->m_mesh->m_streamingSets.m_data;
          if ( v15[v7].m_meshConnections.m_size )
          {
            LODWORD(v16) = v15[v7].m_meshConnections.m_size;
            UFG::qPrintf(
              "\tStitch Pair %u and %u Name %s NumConns %u\n",
              v15[v7].m_thisUid,
              v15[v7].m_oppositeUid,
              v17.mData,
              v16);
          }
          UFG::qString::~qString(&v17);
          ++v7;
          --v8;
        }
        while ( v8 );
      }
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_cells.m_size );
  }
}

// File Line: 1999
// RVA: 0xE8C30
void __fastcall UFG::HavokNavManager::CalculateStitches(UFG::HavokNavManager *this, bool stitchEverything, hkaiNavMeshInstance *stitchInstance)
{
  hkaiNavMeshInstance *v3; // r12
  UFG::HavokNavManager *v4; // r13
  unsigned __int64 v5; // rax
  int v9; // er9
  __int64 v10; // rsi
  int v11; // er8
  __int64 v12; // r14
  int v13; // edx
  __int64 v14; // rbx
  __int64 v15; // rdi
  int v16; // eax
  UFG::HavokNavManager::MeshCell **v17; // rcx
  UFG::HavokNavManager::MeshCell *v18; // r15
  hkaiNavMeshInstance *v19; // r14
  UFG::HavokNavManager::MeshCell *v20; // r12
  hkaiNavMeshInstance *v21; // rsi
  __int64 v22; // r9
  int v23; // edx
  __int64 v24; // rcx
  hkaiNavMeshInstance **v25; // rax
  int v26; // edx
  __int64 v27; // rcx
  hkaiNavMeshInstance **v28; // rax
  unsigned int v29; // edi
  UFG::qBaseNodeRB *v30; // rbx
  unsigned int v31; // edi
  UFG::qBaseNodeRB *v32; // rbx
  UFG::HavokNavManager::MeshCell **v33; // rdx
  int v34; // ecx
  signed __int64 v35; // rcx
  bool v36; // zf
  __int64 v37; // rcx
  hkVector4f v38; // xmm2
  hkVector4f v39; // xmm1
  hkVector4f v40; // xmm3
  hkVector4f v41; // xmm1
  hkVector4f v42; // xmm2
  hkVector4f v43; // xmm3
  signed __int64 v44; // r14
  char v45; // dl
  __int64 v46; // rax
  char v47; // cl
  int i; // ebx
  unsigned int v49; // eax
  __int64 v50; // rdi
  __int64 v51; // r15
  UFG::HavokNavManager::MeshCell *v52; // rcx
  unsigned int v53; // eax
  __int64 v54; // rbx
  __int64 v55; // rsi
  hkaiNavMeshInstance *v56; // rdx
  char v57; // al
  Render::SkinningCacheNode *v58; // rbx
  unsigned __int64 v59; // rax
  Render::SkinningCacheNode *v60; // rbx
  __int64 v61; // [rsp+30h] [rbp-D0h]
  __int64 v62; // [rsp+38h] [rbp-C8h]
  hkaiStreamingUtils::FindEdgeOverlapInput *array; // [rsp+40h] [rbp-C0h]
  int v64; // [rsp+48h] [rbp-B8h]
  int v65; // [rsp+4Ch] [rbp-B4h]
  int v66; // [rsp+50h] [rbp-B0h]
  int v67; // [rsp+54h] [rbp-ACh]
  __int64 v68; // [rsp+58h] [rbp-A8h]
  __int64 v69; // [rsp+60h] [rbp-A0h]
  __int64 v70; // [rsp+68h] [rbp-98h]
  UFG::qBaseTreeRB v71; // [rsp+70h] [rbp-90h]
  hkaiStreamingUtils::FindEdgeOverlapInput v72; // [rsp+C0h] [rbp-40h]
  __int64 v73; // [rsp+1D0h] [rbp+D0h]
  __int64 v74; // [rsp+1D8h] [rbp+D8h]
  hkAabb aabbOut; // [rsp+1E0h] [rbp+E0h]
  hkAabb v76; // [rsp+200h] [rbp+100h]
  UFG::qBaseTreeRB *result; // [rsp+270h] [rbp+170h]
  bool v78; // [rsp+278h] [rbp+178h]
  hkaiNavMeshInstance *v79; // [rsp+280h] [rbp+180h]
  int v80; // [rsp+288h] [rbp+188h]

  v79 = stitchInstance;
  v78 = stitchEverything;
  v73 = -2i64;
  v3 = stitchInstance;
  v4 = this;
  v5 = UFG::qGetTicks();
  UFG::qConvertTicksToMillisecs(v5);
  result = &v71;
  UFG::qBaseTreeRB::qBaseTreeRB(&v71);
  array = 0i64;
  v64 = 0;
  v65 = 2147483648;
  v9 = 0;
  v66 = 0;
  v10 = 0i64;
  v61 = 0i64;
  if ( v4->m_cells.m_size > 0 )
  {
    while ( 1 )
    {
      v11 = 0;
      v67 = 0;
      v12 = 0i64;
      v62 = 0i64;
      if ( v4->m_cells.m_data[v10]->m_Instances.m_size <= 0 )
        goto LABEL_57;
      do
      {
        v13 = v9;
        v80 = v9;
        v14 = v10;
        v70 = v10;
        if ( v9 >= v4->m_cells.m_size )
          goto LABEL_56;
        do
        {
          LODWORD(result) = 0;
          v15 = 0i64;
          v68 = 0i64;
          if ( v4->m_cells.m_data[v14]->m_Instances.m_size <= 0 )
            goto LABEL_54;
          v16 = 0;
          do
          {
            if ( v10 != v14 || v12 != v15 )
            {
              hkaiStreamingUtils::FindEdgeOverlapInput::FindEdgeOverlapInput(&v72);
              v17 = v4->m_cells.m_data;
              v18 = v17[v10];
              v19 = v18->m_Instances.m_data[v12];
              v20 = v17[v14];
              v21 = v20->m_Instances.m_data[v15];
              if ( v19 && v21 )
              {
                if ( v78 )
                  goto LABEL_31;
                if ( v79 )
                {
                  if ( v19 == v79 || v21 == v79 )
                    goto LABEL_31;
                }
                else
                {
                  v22 = v4->m_StitchInstances.m_size;
                  v23 = 0;
                  v24 = 0i64;
                  if ( (signed int)v22 <= 0 )
                    goto LABEL_25;
                  v25 = v4->m_StitchInstances.m_data;
                  while ( *v25 != v19 )
                  {
                    ++v23;
                    ++v24;
                    ++v25;
                    if ( v24 >= v22 )
                      goto LABEL_25;
                  }
                  if ( v23 == -1 )
                  {
LABEL_25:
                    v26 = 0;
                    v27 = 0i64;
                    if ( (signed int)v22 <= 0 )
                      goto LABEL_51;
                    v28 = v4->m_StitchInstances.m_data;
                    while ( *v28 != v21 )
                    {
                      ++v26;
                      ++v27;
                      ++v28;
                      if ( v27 >= v22 )
                        goto LABEL_51;
                    }
                    if ( v26 == -1 )
                      goto LABEL_51;
                  }
LABEL_31:
                  if ( v18->m_mesh->m_userData == 1 || v20->m_mesh->m_userData == 1 )
                  {
                    hkaiNavMeshInstance::getAabb(v19, &aabbOut);
                    hkaiNavMeshInstance::getAabb(v21, &v76);
                    if ( (_mm_movemask_ps(
                            _mm_and_ps(
                              _mm_cmpleps(v76.m_min.m_quad, aabbOut.m_max.m_quad),
                              _mm_cmpleps(aabbOut.m_min.m_quad, v76.m_max.m_quad))) & 7) == 7 )
                    {
                      v29 = v19->m_sectionUid;
                      v72.m_uidA = v29;
                      v72.m_uidB = v21->m_sectionUid;
                      if ( !v29 || (v30 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::Get(&v71, v29)) == 0i64 )
                      {
                        v30 = (UFG::qBaseNodeRB *)UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
                        v69 = (__int64)v30;
                        if ( v30 )
                        {
                          v30->mParent = 0i64;
                          v30->mChild[0] = 0i64;
                          v30->mChild[1] = 0i64;
                          v30->mUID = v29;
                          v30[1].mParent = (UFG::qBaseNodeRB *)v18;
                        }
                        else
                        {
                          v30 = 0i64;
                        }
                        UFG::qBaseTreeRB::Add(&v71, v30);
                      }
                      v30[1].mParent = (UFG::qBaseNodeRB *)v18;
                      v31 = v72.m_uidB;
                      if ( !v72.m_uidB || (v32 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::Get(&v71, v72.m_uidB)) == 0i64 )
                      {
                        v32 = (UFG::qBaseNodeRB *)UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
                        v69 = (__int64)v32;
                        if ( v32 )
                        {
                          v32->mParent = 0i64;
                          v32->mChild[0] = 0i64;
                          v32->mChild[1] = 0i64;
                          v32->mUID = v31;
                          v32[1].mParent = (UFG::qBaseNodeRB *)v20;
                        }
                        else
                        {
                          v32 = 0i64;
                        }
                        UFG::qBaseTreeRB::Add(&v71, v32);
                      }
                      v32[1].mParent = (UFG::qBaseNodeRB *)v20;
                      v72.m_meshA = v19->m_originalMesh.m_pntr;
                      v72.m_meshB = v21->m_originalMesh.m_pntr;
                      v33 = v4->m_cells.m_data;
                      v72.m_mediatorA = v33[v61]->m_mediator;
                      v14 = v70;
                      v72.m_mediatorB = v33[v70]->m_mediator;
                      v72.m_transformA.m_rotation.m_col0 = v19->m_referenceFrame.m_transform.m_rotation.m_col0;
                      v72.m_transformA.m_rotation.m_col1 = v19->m_referenceFrame.m_transform.m_rotation.m_col1;
                      v72.m_transformA.m_rotation.m_col2 = v19->m_referenceFrame.m_transform.m_rotation.m_col2;
                      v72.m_transformA.m_translation = v19->m_referenceFrame.m_transform.m_translation;
                      v72.m_transformB.m_rotation.m_col0 = v21->m_referenceFrame.m_transform.m_rotation.m_col0;
                      v72.m_transformB.m_rotation.m_col1 = v21->m_referenceFrame.m_transform.m_rotation.m_col1;
                      v72.m_transformB.m_rotation.m_col2 = v21->m_referenceFrame.m_transform.m_rotation.m_col2;
                      v72.m_transformB.m_translation = v21->m_referenceFrame.m_transform.m_translation;
                      v72.m_graphA = 0i64;
                      v72.m_graphB = 0i64;
                      v72.m_edgeMatchTolerance = 0.2;
                      v72.m_edgeMatchingParams.m_maxOverhang = 0.2;
                      v72.m_edgeMatchingParams.m_maxStepHeight = 0.2;
                      v72.m_edgeMatchingParams.m_maxSeparation = 0.2;
                      v72.m_edgeMatchingParams.m_behindFaceTolerance = 0.2;
                      v72.m_edgeMatchingParams.m_minEdgeOverlap = 0.0;
                      v34 = v64;
                      if ( v64 == (v65 & 0x3FFFFFFF) )
                      {
                        hkArrayUtil::_reserveMore(
                          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
                          &array,
                          272);
                        v34 = v64;
                      }
                      v35 = v34;
                      v36 = &array[v35] == 0i64;
                      v37 = (__int64)&array[v35];
                      v69 = v37;
                      v74 = v37;
                      if ( !v36 )
                      {
                        *(_QWORD *)v37 = v72.m_meshA;
                        *(_QWORD *)(v37 + 8) = v72.m_meshB;
                        *(_DWORD *)(v37 + 16) = v72.m_uidA;
                        *(_DWORD *)(v37 + 20) = v72.m_uidB;
                        *(_QWORD *)(v37 + 24) = v72.m_mediatorA;
                        *(_QWORD *)(v37 + 32) = v72.m_mediatorB;
                        *(_QWORD *)(v37 + 40) = v72.m_graphA;
                        *(_QWORD *)(v37 + 48) = v72.m_graphB;
                        *(float *)(v37 + 56) = v72.m_edgeMatchTolerance;
                        *(hkVector4f *)(v37 + 64) = v72.m_up;
                        *(_OWORD *)(v37 + 80) = *(_OWORD *)&v72.m_edgeMatchingParams.m_maxStepHeight;
                        *(_OWORD *)(v37 + 96) = *(_OWORD *)&v72.m_edgeMatchingParams.m_cosPlanarAlignmentAngle;
                        *(_OWORD *)(v37 + 112) = *(_OWORD *)&v72.m_edgeMatchingParams.m_edgeTraversibilityVerticalEpsilon;
                        *(_QWORD *)(v37 + 128) = *(_QWORD *)&v72.m_edgeMatchingParams.m_edgeParallelTolerance;
                        v38.m_quad = (__m128)v72.m_transformA.m_rotation.m_col1;
                        v39.m_quad = (__m128)v72.m_transformA.m_rotation.m_col2;
                        v40.m_quad = (__m128)v72.m_transformA.m_translation;
                        *(hkVector4f *)(v37 + 144) = v72.m_transformA.m_rotation.m_col0;
                        *(hkVector4f *)(v37 + 160) = (hkVector4f)v38.m_quad;
                        *(hkVector4f *)(v37 + 176) = (hkVector4f)v39.m_quad;
                        *(hkVector4f *)(v37 + 192) = (hkVector4f)v40.m_quad;
                        v41.m_quad = (__m128)v72.m_transformB.m_rotation.m_col1;
                        v42.m_quad = (__m128)v72.m_transformB.m_rotation.m_col2;
                        v43.m_quad = (__m128)v72.m_transformB.m_translation;
                        *(hkVector4f *)(v37 + 208) = v72.m_transformB.m_rotation.m_col0;
                        *(hkVector4f *)(v37 + 224) = (hkVector4f)v41.m_quad;
                        *(hkVector4f *)(v37 + 240) = (hkVector4f)v42.m_quad;
                        *(hkVector4f *)(v37 + 256) = (hkVector4f)v43.m_quad;
                      }
                      ++v64;
                      v15 = v68;
                    }
                  }
                }
              }
LABEL_51:
              v16 = (signed int)result;
              v10 = v61;
              v12 = v62;
            }
            LODWORD(result) = v16 + 1;
            v68 = ++v15;
            ++v16;
          }
          while ( v16 < v4->m_cells.m_data[v14]->m_Instances.m_size );
          v13 = v80;
LABEL_54:
          v80 = ++v13;
          v70 = ++v14;
        }
        while ( v13 < v4->m_cells.m_size );
        v11 = v67;
        v9 = v66;
LABEL_56:
        v67 = ++v11;
        v62 = ++v12;
      }
      while ( v11 < v4->m_cells.m_data[v10]->m_Instances.m_size );
LABEL_57:
      v66 = ++v9;
      v61 = ++v10;
      if ( v9 >= v4->m_cells.m_size )
      {
        v3 = v79;
        break;
      }
    }
  }
  v44 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v45 = ++*(_BYTE *)(v44 + 80);
  v46 = v45;
  *(_DWORD *)(v44 + 4 * v46) = 1;
  *(_QWORD *)(v44 + 8 * v46 + 16) = "AI::CalculateStitches";
  *(_QWORD *)(v44 + 8 * v46 + 48) = 0i64;
  v47 = *(_BYTE *)(v44 + 81);
  if ( v45 > v47 )
    v47 = v45;
  *(_BYTE *)(v44 + 81) = v47;
  for ( i = 0; i < v64; ++i )
    hkaiStreamingUtils::generateStreamingInfo(&array[i]);
  if ( !v3 )
  {
    v49 = v4->m_cells.m_size;
    if ( v49 )
    {
      v50 = 0i64;
      v51 = v49;
      do
      {
        v52 = v4->m_cells.m_data[v50];
        if ( v52->m_mesh->m_userData == 1 )
        {
          v53 = v52->m_Instances.m_size;
          if ( v53 )
          {
            v54 = 0i64;
            v55 = v53;
            do
            {
              if ( hkaiStreamingCollection::findSectionIdByUid(
                     v4->m_world->m_streamingCollection.m_pntr,
                     v4->m_cells.m_data[v50]->m_Instances.m_data[v54]->m_sectionUid) == -1 )
              {
                hkaiWorld::loadNavMeshInstance(
                  v4->m_world,
                  v4->m_cells.m_data[v50]->m_Instances.m_data[v54],
                  v4->m_cells.m_data[v50]->m_mediator,
                  0i64);
                v56 = v4->m_cells.m_data[v50]->m_Instances.m_data[v54];
                hkaiStreamingCollection::setSectionTransform(
                  v4->m_world->m_streamingCollection.m_pntr,
                  v56,
                  &v56->m_referenceFrame.m_transform);
              }
              ++v54;
              --v55;
            }
            while ( v55 );
          }
        }
        ++v50;
        --v51;
      }
      while ( v51 );
    }
  }
  hkaiStreamingCollection::validate(v4->m_world->m_streamingCollection.m_pntr, 1, 1);
  v57 = *(_BYTE *)(v44 + 80);
  if ( v57 > 0 )
  {
    *(_BYTE *)(v44 + 80) = v57 - 1;
  }
  else
  {
    *(_BYTE *)(v44 + 80) = 0;
    *(_DWORD *)v44 = 3;
    *(_QWORD *)(v44 + 16) = 0i64;
    *(_QWORD *)(v44 + 48) = 0i64;
  }
  while ( v71.mCount )
  {
    v58 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v71);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)&v71, &v58->mNode);
    operator delete[](v58);
  }
  if ( !v3 )
    v4->m_StitchInstances.m_size = 0;
  v59 = UFG::qGetTicks();
  UFG::qConvertTicksToMillisecs(v59);
  v64 = 0;
  if ( v65 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      272 * (v65 & 0x3FFFFFFF));
  array = 0i64;
  v65 = 2147483648;
  v79 = (hkaiNavMeshInstance *)&v71;
  while ( v71.mCount )
  {
    v60 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v71);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)&v71, &v60->mNode);
    operator delete[](v60);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v71);
}  v79 = (hkaiNavMeshInstance *)&v71;
  while ( v71.mCount )
  {
    v60 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v71)

// File Line: 2207
// RVA: 0xE7D40
UFG::HavokNavDynamicOutline *__fastcall UFG::HavokNavManager::AddDynamicOutline(UFG::HavokNavManager *this, UFG::qMatrix44 *transform, UFG::qVector3 *aabbMin, UFG::qVector3 *aabbMax, UFG::DynamicUserEdgeInfo *edgesInfo, unsigned int edgesCount)
{
  UFG::qVector3 *v6; // rdi
  UFG::qVector3 *v7; // rbp
  UFG::qMatrix44 *v8; // r15
  UFG::HavokNavManager *v9; // r14
  signed __int64 v10; // rsi
  char v11; // r10
  __int64 v12; // rax
  unsigned int v13; // ebx
  char v14; // cl
  char *v15; // rax
  UFG::HavokNavDynamicOutline *v16; // rax
  UFG::HavokNavDynamicOutline *v17; // rbp
  __int64 v18; // r15
  unsigned int v19; // edi
  unsigned int v20; // eax
  char v21; // al

  v6 = aabbMax;
  v7 = aabbMin;
  v8 = transform;
  v9 = this;
  v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v11 = ++*(_BYTE *)(v10 + 80);
  v12 = v11;
  v13 = 1;
  *(_DWORD *)(v10 + 4 * v12) = 1;
  *(_QWORD *)(v10 + 8 * v12 + 16) = "AI::HavokNavManager::AddDynamicOutline";
  *(_QWORD *)(v10 + 8 * v12 + 48) = 0i64;
  v14 = *(_BYTE *)(v10 + 81);
  if ( v11 > v14 )
    v14 = v11;
  *(_BYTE *)(v10 + 81) = v14;
  v15 = UFG::qMalloc(0x80ui64, "HavokNavDynamicOutline", 0i64);
  if ( v15 )
  {
    UFG::HavokNavDynamicOutline::HavokNavDynamicOutline(
      (UFG::HavokNavDynamicOutline *)v15,
      v8,
      v7,
      v6,
      edgesInfo,
      edgesCount);
    v17 = v16;
  }
  else
  {
    v17 = 0i64;
  }
  v18 = v9->m_dynamicOutlinesAdditionQueue.size;
  v19 = v18 + 1;
  v20 = v9->m_dynamicOutlinesAdditionQueue.capacity;
  if ( (signed int)v18 + 1 > v20 )
  {
    if ( v20 )
      v13 = 2 * v20;
    for ( ; v13 < v19; v13 *= 2 )
      ;
    if ( v13 <= 2 )
      v13 = 2;
    if ( v13 - v19 > 0x10000 )
      v13 = v18 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v9->m_dynamicOutlinesAdditionQueue,
      v13,
      "qArray.Add");
  }
  v9->m_dynamicOutlinesAdditionQueue.size = v19;
  v9->m_dynamicOutlinesAdditionQueue.p[v18] = v17;
  v21 = *(_BYTE *)(v10 + 80);
  if ( v21 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v21 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  return v17;
}

// File Line: 2221
// RVA: 0xF07F0
char __fastcall UFG::HavokNavManager::RemoveDynamicOutline(UFG::HavokNavManager *this, UFG::NavDynamicOutline *outline)
{
  UFG::HavokNavManager *v2; // rbx
  unsigned int v3; // ecx
  UFG::NavDynamicOutline *v4; // rsi
  unsigned int v5; // er8
  UFG::NavDynamicOutline **v6; // rax
  unsigned int v7; // er9
  unsigned int v8; // er8
  UFG::NavDynamicOutline **v9; // rax
  char result; // al
  signed __int64 v11; // r14
  char v12; // dl
  __int64 v13; // rax
  char v14; // cl
  unsigned int v15; // eax
  char v16; // al
  unsigned int v17; // edi
  signed __int64 v18; // r14
  char v19; // dl
  __int64 v20; // rax
  char v21; // cl
  unsigned int v22; // eax
  __int64 v23; // r13
  unsigned int v24; // eax
  unsigned int v25; // ebp
  unsigned __int64 v26; // rax
  char *v27; // rax
  char *v28; // r15
  unsigned int i; // er9
  __int64 v30; // rcx
  UFG::HavokNavDynamicOutline **v31; // rax
  char v32; // al

  v2 = this;
  v3 = this->m_dynamicOutlinesAdditionQueue.size;
  v4 = outline;
  v5 = 0;
  if ( v3 )
  {
    v6 = (UFG::NavDynamicOutline **)v2->m_dynamicOutlinesAdditionQueue.p;
    while ( *v6 != outline )
    {
      ++v5;
      ++v6;
      if ( v5 >= v3 )
        goto LABEL_5;
    }
    v11 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v12 = ++*(_BYTE *)(v11 + 80);
    v13 = v12;
    *(_DWORD *)(v11 + 4 * v13) = 1;
    *(_QWORD *)(v11 + 8 * v13 + 16) = "AI::HavokNavManager::RemoveFromAdditionQueue";
    *(_QWORD *)(v11 + 8 * v13 + 48) = 0i64;
    v14 = *(_BYTE *)(v11 + 81);
    if ( v12 > v14 )
      v14 = v12;
    *(_BYTE *)(v11 + 81) = v14;
    v2->m_dynamicOutlinesAdditionQueue.p[v5] = v2->m_dynamicOutlinesAdditionQueue.p[v2->m_dynamicOutlinesAdditionQueue.size
                                                                                  - 1];
    v15 = v2->m_dynamicOutlinesAdditionQueue.size;
    if ( v15 > 1 )
      v2->m_dynamicOutlinesAdditionQueue.size = v15 - 1;
    else
      v2->m_dynamicOutlinesAdditionQueue.size = 0;
    if ( v4 )
      v4->vfptr->__vecDelDtor(v4, 1u);
    v16 = *(_BYTE *)(v11 + 80);
    if ( v16 > 0 )
    {
      *(_BYTE *)(v11 + 80) = v16 - 1;
      result = 1;
    }
    else
    {
      *(_BYTE *)(v11 + 80) = 0;
      result = 1;
      *(_DWORD *)v11 = 3;
      *(_QWORD *)(v11 + 16) = 0i64;
      *(_QWORD *)(v11 + 48) = 0i64;
    }
  }
  else
  {
LABEL_5:
    v7 = v2->m_dynamicOutlines.size;
    v8 = 0;
    if ( v7 )
    {
      v9 = (UFG::NavDynamicOutline **)v2->m_dynamicOutlines.p;
      while ( *v9 != outline )
      {
        ++v8;
        ++v9;
        if ( v8 >= v7 )
          goto LABEL_9;
      }
      v17 = 1;
      v18 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
      v19 = ++*(_BYTE *)(v18 + 80);
      v20 = v19;
      *(_DWORD *)(v18 + 4 * v20) = 1;
      *(_QWORD *)(v18 + 8 * v20 + 16) = "AI::HavokNavManager::RemoveDynamicOutline";
      *(_QWORD *)(v18 + 8 * v20 + 48) = 0i64;
      v21 = *(_BYTE *)(v18 + 81);
      if ( v19 > v21 )
        v21 = v19;
      *(_BYTE *)(v18 + 81) = v21;
      v2->m_dynamicOutlines.p[v8] = v2->m_dynamicOutlines.p[v7 - 1];
      v22 = v2->m_dynamicOutlines.size;
      if ( v22 > 1 )
        v2->m_dynamicOutlines.size = v22 - 1;
      else
        v2->m_dynamicOutlines.size = 0;
      v23 = v2->m_dynamicOutlinesDeletionQueue.size;
      v24 = v2->m_dynamicOutlinesDeletionQueue.capacity;
      v25 = v23 + 1;
      if ( (signed int)v23 + 1 > v24 )
      {
        if ( v24 )
          v17 = 2 * v24;
        for ( ; v17 < v25; v17 *= 2 )
          ;
        if ( v17 <= 2 )
          v17 = 2;
        if ( v17 - v25 > 0x10000 )
          v17 = v23 + 65537;
        if ( v17 != (_DWORD)v23 )
        {
          v26 = 8i64 * v17;
          if ( !is_mul_ok(v17, 8ui64) )
            v26 = -1i64;
          v27 = UFG::qMalloc(v26, "qArray.Add", 0i64);
          v28 = v27;
          if ( v2->m_dynamicOutlinesDeletionQueue.p )
          {
            for ( i = 0;
                  i < v2->m_dynamicOutlinesDeletionQueue.size;
                  *(_QWORD *)&v27[8 * v30] = v2->m_dynamicOutlinesDeletionQueue.p[v30] )
            {
              v30 = i++;
            }
            operator delete[](v2->m_dynamicOutlinesDeletionQueue.p);
          }
          v2->m_dynamicOutlinesDeletionQueue.p = (UFG::HavokNavDynamicOutline **)v28;
          v2->m_dynamicOutlinesDeletionQueue.capacity = v17;
        }
      }
      v31 = v2->m_dynamicOutlinesDeletionQueue.p;
      v2->m_dynamicOutlinesDeletionQueue.size = v25;
      v31[v23] = (UFG::HavokNavDynamicOutline *)v4;
      v32 = *(_BYTE *)(v18 + 80);
      if ( v32 > 0 )
      {
        *(_BYTE *)(v18 + 80) = v32 - 1;
        result = 1;
      }
      else
      {
        *(_BYTE *)(v18 + 80) = 0;
        result = 1;
        *(_DWORD *)v18 = 3;
        *(_QWORD *)(v18 + 16) = 0i64;
        *(_QWORD *)(v18 + 48) = 0i64;
      }
    }
    else
    {
LABEL_9:
      result = 0;
    }
  }
  return result;
}

// File Line: 2261
// RVA: 0xEF4E0
bool __fastcall UFG::HavokNavManager::IsAnyAIMeshAvailable(UFG::HavokNavManager *this)
{
  return hkaiWorld::getDynamicQueryMediator(this->m_world) != 0i64;
}

// File Line: 2315
// RVA: 0xE4B00
void __fastcall UFG::HavokNavManager::MeshCell::MeshCell(UFG::HavokNavManager::MeshCell *this, hkaiNavMesh *mesh, hkaiNavMeshInstance *instance, hkaiDirectedGraphExplicitCost *cost, hkaiNavMeshQueryMediator *mediator, hkaiUserEdgePairArray *userEdges, hkAabb *aabb, unsigned int id, struct UFG::HavokNavManager::MeshCellDebugStrings *debugStrings)
{
  hkaiNavMeshInstance *v9; // rsi
  UFG::HavokNavManager::MeshCell *v10; // rdi
  hkArray<hkaiNavMeshInstance *,hkContainerHeapAllocator> *v11; // rbx

  v9 = instance;
  v10 = this;
  this->m_meshFixups = 0i64;
  this->m_edgesFixups = 0i64;
  this->m_mesh = mesh;
  this->m_clusterGraph = cost;
  this->m_mediator = mediator;
  this->m_userEdges = userEdges;
  this->m_aabb.m_min = aabb->m_min;
  this->m_aabb.m_max = aabb->m_max;
  this->m_id = id;
  this->m_meshBuffer = 0i64;
  this->m_meshBufferSize = -1;
  this->m_mediatorTreeBuffer = 0i64;
  this->m_mediatorTreeBufferSize = -1;
  this->m_edgesBuffer = 0i64;
  this->m_edgesBufferSize = -1;
  v11 = &this->m_Instances;
  v11->m_data = 0i64;
  v11->m_size = 0;
  v11->m_capacityAndFlags = 2147483648;
  this->m_debugStrings = debugStrings;
  if ( instance )
  {
    if ( this->m_Instances.m_size == (this->m_Instances.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &this->m_Instances, 8);
    v11->m_data[v10->m_Instances.m_size++] = v9;
  }
}


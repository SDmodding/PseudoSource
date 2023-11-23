// File Line: 150
// RVA: 0xE4990
void __fastcall UFG::HavokNavManager::HavokNavManager(UFG::HavokNavManager *this)
{
  UFG::NavManager::NavManager(this);
  this->vfptr = (UFG::NavManagerVtbl *)&UFG::HavokNavManager::`vftable;
  this->m_manager.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  this->m_manager.vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  *(_DWORD *)&this->m_manager.m_memSizeAndFlags = 0x1FFFF;
  this->m_manager.vfptr = (hkBaseObjectVtbl *)&hkaiStreamingManager::`vftable;
  this->m_world = 0i64;
  this->m_cells.m_data = 0i64;
  this->m_cells.m_size = 0;
  this->m_cells.m_capacityAndFlags = 0x80000000;
  this->m_StitchInstances.m_data = 0i64;
  this->m_StitchInstances.m_size = 0;
  this->m_StitchInstances.m_capacityAndFlags = 0x80000000;
  this->m_listener.m_pntr = 0i64;
  this->m_costModifier.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  this->m_costModifier.vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  *(_DWORD *)&this->m_costModifier.m_memSizeAndFlags = 0x1FFFF;
  this->m_costModifier.vfptr = (hkBaseObjectVtbl *)&hkaiAstarCostModifier::`vftable;
  this->m_costModifier.m_type.m_storage = 1;
  this->m_costModifier.vfptr = (hkBaseObjectVtbl *)&hkaiUFGNavMeshCostModifier::`vftable;
  this->m_edgeFilter.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  this->m_edgeFilter.vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  *(_DWORD *)&this->m_edgeFilter.m_memSizeAndFlags = 0x1FFFF;
  this->m_edgeFilter.vfptr = (hkBaseObjectVtbl *)&hkaiAstarEdgeFilter::`vftable;
  this->m_edgeFilter.m_type.m_storage = 1;
  this->m_edgeFilter.vfptr = (hkBaseObjectVtbl *)&hkaiUFGAStarEdgeFilter::`vftable;
  this->m_dynamicOutlines.p = 0i64;
  *(_QWORD *)&this->m_dynamicOutlines.size = 0i64;
  this->m_dynamicOutlinesAdditionQueue.p = 0i64;
  *(_QWORD *)&this->m_dynamicOutlinesAdditionQueue.size = 0i64;
  this->m_dynamicOutlinesDeletionQueue.p = 0i64;
  *(_QWORD *)&this->m_dynamicOutlinesDeletionQueue.size = 0i64;
  this->m_dynamicEdges.m_data = 0i64;
  this->m_dynamicEdges.m_size = 0;
  this->m_dynamicEdges.m_capacityAndFlags = 0x80000000;
  this->m_dynamicEdgesNew.m_data = 0i64;
  this->m_dynamicEdgesNew.m_size = 0;
  this->m_dynamicEdgesNew.m_capacityAndFlags = 0x80000000;
  this->m_aTesselationData.p = 0i64;
  *(_QWORD *)&this->m_aTesselationData.size = 0i64;
  this->m_aTmpTesselationData.p = 0i64;
  *(_QWORD *)&this->m_aTmpTesselationData.size = 0i64;
  UFG::HavokNavManager::Init(this);
}

// File Line: 155
// RVA: 0xE5DE0
void __fastcall UFG::HavokNavManager::~HavokNavManager(UFG::HavokNavManager *this)
{
  UFG::qVector3 *p; // rcx
  UFG::qVector3 *v3; // rcx
  int m_capacityAndFlags; // eax
  int v5; // eax
  UFG::HavokNavDynamicOutline **v6; // rcx
  UFG::HavokNavDynamicOutline **v7; // rcx
  UFG::HavokNavDynamicOutline **v8; // rcx
  UFG::HavokNavManager::AiListener *m_pntr; // rcx
  int v10; // r8d
  int v11; // r8d

  this->vfptr = (UFG::NavManagerVtbl *)&UFG::HavokNavManager::`vftable;
  p = this->m_aTmpTesselationData.p;
  if ( p )
    operator delete[](p);
  this->m_aTmpTesselationData.p = 0i64;
  *(_QWORD *)&this->m_aTmpTesselationData.size = 0i64;
  v3 = this->m_aTesselationData.p;
  if ( v3 )
    operator delete[](v3);
  this->m_aTesselationData.p = 0i64;
  *(_QWORD *)&this->m_aTesselationData.size = 0i64;
  this->m_dynamicEdgesNew.m_size = 0;
  m_capacityAndFlags = this->m_dynamicEdgesNew.m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_dynamicEdgesNew.m_data,
      80 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_dynamicEdgesNew.m_data = 0i64;
  this->m_dynamicEdgesNew.m_capacityAndFlags = 0x80000000;
  this->m_dynamicEdges.m_size = 0;
  v5 = this->m_dynamicEdges.m_capacityAndFlags;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_dynamicEdges.m_data,
      80 * (v5 & 0x3FFFFFFF));
  this->m_dynamicEdges.m_data = 0i64;
  this->m_dynamicEdges.m_capacityAndFlags = 0x80000000;
  v6 = this->m_dynamicOutlinesDeletionQueue.p;
  if ( v6 )
    operator delete[](v6);
  this->m_dynamicOutlinesDeletionQueue.p = 0i64;
  *(_QWORD *)&this->m_dynamicOutlinesDeletionQueue.size = 0i64;
  v7 = this->m_dynamicOutlinesAdditionQueue.p;
  if ( v7 )
    operator delete[](v7);
  this->m_dynamicOutlinesAdditionQueue.p = 0i64;
  *(_QWORD *)&this->m_dynamicOutlinesAdditionQueue.size = 0i64;
  v8 = this->m_dynamicOutlines.p;
  if ( v8 )
    operator delete[](v8);
  this->m_dynamicOutlines.p = 0i64;
  *(_QWORD *)&this->m_dynamicOutlines.size = 0i64;
  this->m_edgeFilter.vfptr = (hkBaseObjectVtbl *)&hkaiUFGAStarEdgeFilter::`vftable;
  this->m_edgeFilter.vfptr = (hkBaseObjectVtbl *)&hkaiAstarEdgeFilter::`vftable;
  this->m_edgeFilter.vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  this->m_edgeFilter.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  this->m_costModifier.vfptr = (hkBaseObjectVtbl *)&hkaiAstarCostModifier::`vftable;
  this->m_costModifier.vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  this->m_costModifier.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  m_pntr = this->m_listener.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_listener.m_pntr = 0i64;
  this->m_StitchInstances.m_size = 0;
  v10 = this->m_StitchInstances.m_capacityAndFlags;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_StitchInstances.m_data,
      8 * v10);
  this->m_StitchInstances.m_data = 0i64;
  this->m_StitchInstances.m_capacityAndFlags = 0x80000000;
  this->m_cells.m_size = 0;
  v11 = this->m_cells.m_capacityAndFlags;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_cells.m_data, 8 * v11);
  this->m_cells.m_data = 0i64;
  this->m_cells.m_capacityAndFlags = 0x80000000;
  this->m_manager.vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  this->m_manager.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  UFG::NavManager::~NavManager(this);
}

// File Line: 169
// RVA: 0xEE940
void __fastcall UFG::HavokNavManager::Init(UFG::HavokNavManager *this)
{
  __int64 v2; // rdi
  char v3; // dl
  char v4; // cl
  _QWORD **Value; // rax
  hkaiWorld *v6; // rax
  hkaiWorld *v7; // rax
  char v8; // al
  char v9; // dl
  char v10; // cl
  _QWORD **v11; // rax
  hkJobQueue *v12; // rax
  hkJobQueue *v13; // rax
  char v14; // al
  char v15; // dl
  char v16; // cl
  _QWORD **v17; // rax
  HavokJobMemoryPoolTagger *v18; // rax
  char v19; // al
  char v20; // dl
  char v21; // cl
  char v22; // al
  char v23; // dl
  char v24; // cl
  _QWORD **v25; // rax
  __int64 v26; // rsi
  UFG::HavokNavManager::AiListener *m_pntr; // rcx
  UFG::HavokNavManager::AiListener *v28; // rdx
  hkaiWorld::Listener *v29; // rdx
  char v30; // al
  unsigned __int64 v31; // rax
  char *v32; // rax
  UFG::HavokNavDynamicOutline **v33; // rdi
  unsigned int i; // r9d
  unsigned __int64 v35; // rax
  char *v36; // rax
  UFG::HavokNavDynamicOutline **v37; // rdi
  unsigned int j; // r9d
  unsigned __int64 v39; // rax
  char *v40; // rax
  UFG::HavokNavDynamicOutline **v41; // rdi
  unsigned int k; // r9d
  int v43; // edi
  hkJobQueueCinfo v44; // [rsp+30h] [rbp-1F8h] BYREF
  __int64 v45; // [rsp+58h] [rbp-1D0h]
  hkaiWorld::Cinfo cInfo; // [rsp+60h] [rbp-1C8h] BYREF
  __int64 result; // [rsp+230h] [rbp+8h] BYREF

  v45 = -2i64;
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    2117862912i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1099969314i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1829661816i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    660317406i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1093109332i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    926677201i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1211889873i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1000824113i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1261170549i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1062566140i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    862692426i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    862692427i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    1470720914i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
    hkSingleton<hkError>::s_instance,
    2551363397i64,
    0i64);
  ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
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
  *(_DWORD *)(v2 + 4i64 * v3) = 1;
  *(_QWORD *)(v2 + 8i64 * v3 + 16) = "AI::hkaiWorld";
  *(_QWORD *)(v2 + 8i64 * v3 + 48) = 0i64;
  v4 = *(_BYTE *)(v2 + 81);
  if ( v3 > v4 )
    v4 = v3;
  *(_BYTE *)(v2 + 81) = v4;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkaiWorld *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 640i64);
  result = (__int64)v6;
  if ( v6 )
    hkaiWorld::hkaiWorld(v6, &cInfo);
  else
    v7 = 0i64;
  this->m_world = v7;
  v8 = *(_BYTE *)(v2 + 80);
  if ( v8 > 0 )
  {
    *(_BYTE *)(v2 + 80) = v8 - 1;
  }
  else
  {
    *(_BYTE *)(v2 + 80) = 0;
    *(_DWORD *)v2 = 3;
    *(_QWORD *)(v2 + 16) = 0i64;
    *(_QWORD *)(v2 + 48) = 0i64;
  }
  this->m_jobThreadPool = UFG::BasePhysicsSystem::mInstance->mThreadPool;
  hkJobQueueHwSetup::hkJobQueueHwSetup(&v44.m_jobQueueHwSetup);
  v44.m_jobQueueHwSetup.m_noSpu.m_bool = 1;
  v44.m_maxNumJobTypes = 20;
  v9 = ++*(_BYTE *)(v2 + 80);
  *(_DWORD *)(v2 + 4i64 * v9) = 1;
  *(_QWORD *)(v2 + 8i64 * v9 + 16) = "AI::JobQueue";
  *(_QWORD *)(v2 + 8i64 * v9 + 48) = 0i64;
  v10 = *(_BYTE *)(v2 + 81);
  if ( v9 > v10 )
    v10 = v9;
  *(_BYTE *)(v2 + 81) = v10;
  v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkJobQueue *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v11[11] + 8i64))(v11[11], 1024i64);
  result = (__int64)v12;
  if ( v12 )
    hkJobQueue::hkJobQueue(v12, &v44);
  else
    v13 = 0i64;
  this->m_jobQueue = v13;
  v14 = *(_BYTE *)(v2 + 80);
  if ( v14 > 0 )
  {
    *(_BYTE *)(v2 + 80) = v14 - 1;
  }
  else
  {
    *(_BYTE *)(v2 + 80) = 0;
    *(_DWORD *)v2 = 3;
    *(_QWORD *)(v2 + 16) = 0i64;
    *(_QWORD *)(v2 + 48) = 0i64;
  }
  v15 = ++*(_BYTE *)(v2 + 80);
  *(_DWORD *)(v2 + 4i64 * v15) = 1;
  *(_QWORD *)(v2 + 8i64 * v15 + 16) = "AI::JobMemoryPoolTagger";
  *(_QWORD *)(v2 + 8i64 * v15 + 48) = 0i64;
  v16 = *(_BYTE *)(v2 + 81);
  if ( v15 > v16 )
    v16 = v15;
  *(_BYTE *)(v2 + 81) = v16;
  v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v18 = (HavokJobMemoryPoolTagger *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v17[11] + 8i64))(v17[11], 8i64);
  result = (__int64)v18;
  if ( v18 )
  {
    v18->vfptr = (hkExternalJobProfilerVtbl *)&hkExternalJobProfiler::`vftable;
    v18->vfptr = (hkExternalJobProfilerVtbl *)&HavokJobMemoryPoolTagger::`vftable;
  }
  else
  {
    v18 = 0i64;
  }
  this->m_jobMemoryPoolTagger = v18;
  v19 = *(_BYTE *)(v2 + 80);
  if ( v19 > 0 )
  {
    *(_BYTE *)(v2 + 80) = v19 - 1;
  }
  else
  {
    *(_BYTE *)(v2 + 80) = 0;
    *(_DWORD *)v2 = 3;
    *(_QWORD *)(v2 + 16) = 0i64;
    *(_QWORD *)(v2 + 48) = 0i64;
  }
  v20 = ++*(_BYTE *)(v2 + 80);
  *(_DWORD *)(v2 + 4i64 * v20) = 1;
  *(_QWORD *)(v2 + 8i64 * v20 + 16) = "AI::JobQueueRegistration";
  *(_QWORD *)(v2 + 8i64 * v20 + 48) = 0i64;
  v21 = *(_BYTE *)(v2 + 81);
  if ( v20 > v21 )
    v21 = v20;
  *(_BYTE *)(v2 + 81) = v21;
  hkaiPathfindingJobQueueUtils::registerWithJobQueue(this->m_jobQueue);
  hkaiLocalSteeringJobQueueUtils::registerWithJobQueue(this->m_jobQueue);
  hkaiDynamicNavMeshJobQueueUtils::registerWithJobQueue(this->m_jobQueue);
  hkJobQueue::setExternalProfiler(this->m_jobQueue, this->m_jobMemoryPoolTagger);
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
  *(_DWORD *)(v2 + 4i64 * v23) = 1;
  *(_QWORD *)(v2 + 8i64 * v23 + 16) = "AI::AiListener";
  *(_QWORD *)(v2 + 8i64 * v23 + 48) = 0i64;
  v24 = *(_BYTE *)(v2 + 81);
  if ( v23 > v24 )
    v24 = v23;
  *(_BYTE *)(v2 + 81) = v24;
  v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v26 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v25[11] + 8i64))(v25[11], 32i64);
  result = v26;
  if ( v26 )
  {
    *(_QWORD *)v26 = &hkBaseObject::`vftable;
    *(_QWORD *)v26 = &hkReferencedObject::`vftable;
    *(_DWORD *)(v26 + 8) = 0x1FFFF;
    *(_QWORD *)(v26 + 16) = &hkaiWorld::Listener::`vftable;
    *(_QWORD *)v26 = &UFG::HavokNavManager::AiListener::`vftable{for `hkReferencedObject};
    *(_QWORD *)(v26 + 16) = &UFG::HavokNavManager::AiListener::`vftable{for `hkaiWorld::Listener};
    *(_QWORD *)(v26 + 24) = this;
  }
  else
  {
    v26 = 0i64;
  }
  if ( v26 )
    hkReferencedObject::addReference((hkReferencedObject *)v26);
  m_pntr = this->m_listener.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_listener.m_pntr = (UFG::HavokNavManager::AiListener *)v26;
  hkReferencedObject::removeReference((hkReferencedObject *)v26);
  v28 = this->m_listener.m_pntr;
  if ( v28 )
    v29 = &v28->hkaiWorld::Listener;
  else
    v29 = 0i64;
  hkaiWorld::addListener(this->m_world, v29);
  v30 = *(_BYTE *)(v2 + 80);
  if ( v30 > 0 )
  {
    *(_BYTE *)(v2 + 80) = v30 - 1;
  }
  else
  {
    *(_BYTE *)(v2 + 80) = 0;
    *(_DWORD *)v2 = 3;
    *(_QWORD *)(v2 + 16) = 0i64;
    *(_QWORD *)(v2 + 48) = 0i64;
  }
  if ( this->m_dynamicOutlines.capacity < 0xC8 && this->m_dynamicOutlines.size != 200 )
  {
    v31 = 1600i64;
    if ( !is_mul_ok(0xC8ui64, 8ui64) )
      v31 = -1i64;
    v32 = UFG::qMalloc(v31, "qArray.Reallocate(Reserve)", 0i64);
    v33 = (UFG::HavokNavDynamicOutline **)v32;
    if ( this->m_dynamicOutlines.p )
    {
      for ( i = 0; i < this->m_dynamicOutlines.size; ++i )
        *(_QWORD *)&v32[8 * i] = this->m_dynamicOutlines.p[i];
      operator delete[](this->m_dynamicOutlines.p);
    }
    this->m_dynamicOutlines.p = v33;
    this->m_dynamicOutlines.capacity = 200;
  }
  if ( this->m_dynamicOutlinesAdditionQueue.capacity < 0xC8 && this->m_dynamicOutlinesAdditionQueue.size != 200 )
  {
    v35 = 1600i64;
    if ( !is_mul_ok(0xC8ui64, 8ui64) )
      v35 = -1i64;
    v36 = UFG::qMalloc(v35, "qArray.Reallocate(Reserve)", 0i64);
    v37 = (UFG::HavokNavDynamicOutline **)v36;
    if ( this->m_dynamicOutlinesAdditionQueue.p )
    {
      for ( j = 0; j < this->m_dynamicOutlinesAdditionQueue.size; ++j )
        *(_QWORD *)&v36[8 * j] = this->m_dynamicOutlinesAdditionQueue.p[j];
      operator delete[](this->m_dynamicOutlinesAdditionQueue.p);
    }
    this->m_dynamicOutlinesAdditionQueue.p = v37;
    this->m_dynamicOutlinesAdditionQueue.capacity = 200;
  }
  if ( this->m_dynamicOutlinesDeletionQueue.capacity < 0xC8 && this->m_dynamicOutlinesDeletionQueue.size != 200 )
  {
    v39 = 1600i64;
    if ( !is_mul_ok(0xC8ui64, 8ui64) )
      v39 = -1i64;
    v40 = UFG::qMalloc(v39, "qArray.Reallocate(Reserve)", 0i64);
    v41 = (UFG::HavokNavDynamicOutline **)v40;
    if ( this->m_dynamicOutlinesDeletionQueue.p )
    {
      for ( k = 0; k < this->m_dynamicOutlinesDeletionQueue.size; ++k )
        *(_QWORD *)&v40[8 * k] = this->m_dynamicOutlinesDeletionQueue.p[k];
      operator delete[](this->m_dynamicOutlinesDeletionQueue.p);
    }
    this->m_dynamicOutlinesDeletionQueue.p = v41;
    this->m_dynamicOutlinesDeletionQueue.capacity = 200;
  }
  v43 = 128;
  if ( this->m_aTesselationData.capacity < 0x80 )
    UFG::qArray<UFG::qVector3,0>::Reallocate(&this->m_aTesselationData, 0x80u, "qArray.Reallocate(Reserve)");
  if ( (this->m_StitchInstances.m_capacityAndFlags & 0x3FFFFFFFu) < 0x80 )
  {
    if ( 2 * (this->m_StitchInstances.m_capacityAndFlags & 0x3FFFFFFF) > 128 )
      v43 = 2 * (this->m_StitchInstances.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, &this->m_StitchInstances, v43, 8);
  }
  this->m_StitchingDelay = 0;
  this->m_highspeedMode = 0;
  hkJobQueueHwSetup::~hkJobQueueHwSetup(&v44.m_jobQueueHwSetup);
  hkaiVolumePathfindingUtil::FindPathInput::~FindPathInput(&cInfo.m_volumePathfindingInput);
  hkaiPathfindingUtil::FindPathInput::~FindPathInput(&cInfo.m_pathfindingInput);
}, &this->m_StitchInstances

// File Line: 316
// RVA: 0xF0B00
void __fastcall UFG::HavokNavManager::RequeueAdditionQueue(UFG::HavokNavManager *this, bool forceUpdate)
{
  unsigned int size; // r8d
  __int64 v4; // r14
  __int64 v5; // r12
  char v6; // dl
  char v7; // cl
  UFG::HavokNavDynamicOutline **p; // rax
  UFG::HavokNavDynamicOutline *v9; // r13
  __int64 v10; // r15
  unsigned int capacity; // ebx
  unsigned int v12; // esi
  unsigned int v13; // ebx
  unsigned __int64 v14; // rax
  char *v15; // rax
  UFG::HavokNavDynamicOutline **v16; // rbp
  __int64 i; // r9
  __int64 v18; // r8
  UFG::HavokNavDynamicOutline **v19; // rax
  unsigned int v20; // eax
  char v21; // al

  size = 0;
  if ( this->m_dynamicOutlines.size > 5 )
  {
    size = 5;
  }
  else if ( forceUpdate )
  {
    size = this->m_dynamicOutlines.size;
  }
  if ( size )
  {
    v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v5 = size;
    do
    {
      v6 = ++*(_BYTE *)(v4 + 80);
      *(_DWORD *)(v4 + 4i64 * v6) = 1;
      *(_QWORD *)(v4 + 8i64 * v6 + 16) = "AI::HavokNavManager::RequeueDynamicOutline";
      *(_QWORD *)(v4 + 8i64 * v6 + 48) = 0i64;
      v7 = *(_BYTE *)(v4 + 81);
      if ( v6 > v7 )
        v7 = v6;
      *(_BYTE *)(v4 + 81) = v7;
      p = this->m_dynamicOutlines.p;
      v9 = *p;
      hkaiWorld::removeSilhouetteGenerator(this->m_world, (*p)->m_pSilhouette);
      v10 = this->m_dynamicOutlinesAdditionQueue.size;
      capacity = this->m_dynamicOutlinesAdditionQueue.capacity;
      v12 = v10 + 1;
      if ( (int)v10 + 1 > capacity )
      {
        if ( capacity )
          v13 = 2 * capacity;
        else
          v13 = 1;
        for ( ; v13 < v12; v13 *= 2 )
          ;
        if ( v13 <= 2 )
          v13 = 2;
        if ( v13 - v12 > 0x10000 )
          v13 = v10 + 65537;
        if ( v13 != (_DWORD)v10 )
        {
          v14 = 8i64 * v13;
          if ( !is_mul_ok(v13, 8ui64) )
            v14 = -1i64;
          v15 = UFG::qMalloc(v14, "qArray.Add", 0i64);
          v16 = (UFG::HavokNavDynamicOutline **)v15;
          if ( this->m_dynamicOutlinesAdditionQueue.p )
          {
            for ( i = 0i64;
                  (unsigned int)i < this->m_dynamicOutlinesAdditionQueue.size;
                  *(_QWORD *)&v15[v18 * 8] = this->m_dynamicOutlinesAdditionQueue.p[v18] )
            {
              v18 = i;
              i = (unsigned int)(i + 1);
            }
            operator delete[](this->m_dynamicOutlinesAdditionQueue.p);
          }
          this->m_dynamicOutlinesAdditionQueue.p = v16;
          this->m_dynamicOutlinesAdditionQueue.capacity = v13;
        }
      }
      v19 = this->m_dynamicOutlinesAdditionQueue.p;
      this->m_dynamicOutlinesAdditionQueue.size = v12;
      v19[v10] = v9;
      *this->m_dynamicOutlines.p = this->m_dynamicOutlines.p[this->m_dynamicOutlines.size - 1];
      v20 = this->m_dynamicOutlines.size;
      if ( v20 > 1 )
        this->m_dynamicOutlines.size = v20 - 1;
      else
        this->m_dynamicOutlines.size = 0;
      v21 = *(_BYTE *)(v4 + 80);
      if ( v21 > 0 )
      {
        *(_BYTE *)(v4 + 80) = v21 - 1;
      }
      else
      {
        *(_BYTE *)(v4 + 80) = 0;
        *(_DWORD *)v4 = 3;
        *(_QWORD *)(v4 + 16) = 0i64;
        *(_QWORD *)(v4 + 48) = 0i64;
      }
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 338
// RVA: 0xE7EC0
void __fastcall UFG::HavokNavManager::ApplyAdditionQueue(UFG::HavokNavManager *this, bool forceUpdate)
{
  unsigned int size; // r8d
  __int64 v4; // r14
  __int64 v5; // r12
  char v6; // dl
  char v7; // cl
  UFG::HavokNavDynamicOutline **p; // rax
  UFG::HavokNavDynamicOutline *v9; // r13
  __int64 v10; // r15
  unsigned int capacity; // ebx
  unsigned int v12; // esi
  unsigned int v13; // ebx
  unsigned __int64 v14; // rax
  char *v15; // rax
  UFG::HavokNavDynamicOutline **v16; // rbp
  __int64 i; // r9
  __int64 v18; // r8
  UFG::HavokNavDynamicOutline **v19; // rax
  unsigned int v20; // eax
  char v21; // al

  size = 0;
  if ( this->m_dynamicOutlinesAdditionQueue.size > 5 )
  {
    size = 5;
  }
  else if ( forceUpdate )
  {
    size = this->m_dynamicOutlinesAdditionQueue.size;
  }
  if ( size )
  {
    v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v5 = size;
    do
    {
      v6 = ++*(_BYTE *)(v4 + 80);
      *(_DWORD *)(v4 + 4i64 * v6) = 1;
      *(_QWORD *)(v4 + 8i64 * v6 + 16) = "AI::HavokNavManager::ApplyAdditionQueue";
      *(_QWORD *)(v4 + 8i64 * v6 + 48) = 0i64;
      v7 = *(_BYTE *)(v4 + 81);
      if ( v6 > v7 )
        v7 = v6;
      *(_BYTE *)(v4 + 81) = v7;
      p = this->m_dynamicOutlinesAdditionQueue.p;
      v9 = *p;
      hkaiWorld::addSilhouetteGenerator(this->m_world, (*p)->m_pSilhouette);
      v10 = this->m_dynamicOutlines.size;
      capacity = this->m_dynamicOutlines.capacity;
      v12 = v10 + 1;
      if ( (int)v10 + 1 > capacity )
      {
        if ( capacity )
          v13 = 2 * capacity;
        else
          v13 = 1;
        for ( ; v13 < v12; v13 *= 2 )
          ;
        if ( v13 <= 2 )
          v13 = 2;
        if ( v13 - v12 > 0x10000 )
          v13 = v10 + 65537;
        if ( v13 != (_DWORD)v10 )
        {
          v14 = 8i64 * v13;
          if ( !is_mul_ok(v13, 8ui64) )
            v14 = -1i64;
          v15 = UFG::qMalloc(v14, "qArray.Add", 0i64);
          v16 = (UFG::HavokNavDynamicOutline **)v15;
          if ( this->m_dynamicOutlines.p )
          {
            for ( i = 0i64;
                  (unsigned int)i < this->m_dynamicOutlines.size;
                  *(_QWORD *)&v15[v18 * 8] = this->m_dynamicOutlines.p[v18] )
            {
              v18 = i;
              i = (unsigned int)(i + 1);
            }
            operator delete[](this->m_dynamicOutlines.p);
          }
          this->m_dynamicOutlines.p = v16;
          this->m_dynamicOutlines.capacity = v13;
        }
      }
      v19 = this->m_dynamicOutlines.p;
      this->m_dynamicOutlines.size = v12;
      v19[v10] = v9;
      *this->m_dynamicOutlinesAdditionQueue.p = this->m_dynamicOutlinesAdditionQueue.p[this->m_dynamicOutlinesAdditionQueue.size
                                                                                     - 1];
      v20 = this->m_dynamicOutlinesAdditionQueue.size;
      if ( v20 > 1 )
        this->m_dynamicOutlinesAdditionQueue.size = v20 - 1;
      else
        this->m_dynamicOutlinesAdditionQueue.size = 0;
      v21 = *(_BYTE *)(v4 + 80);
      if ( v21 > 0 )
      {
        *(_BYTE *)(v4 + 80) = v21 - 1;
      }
      else
      {
        *(_BYTE *)(v4 + 80) = 0;
        *(_DWORD *)v4 = 3;
        *(_QWORD *)(v4 + 16) = 0i64;
        *(_QWORD *)(v4 + 48) = 0i64;
      }
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 360
// RVA: 0xE8100
void __fastcall UFG::HavokNavManager::ApplyDeletionQueue(UFG::HavokNavManager *this, bool forceUpdate)
{
  unsigned int size; // r8d
  __int64 v4; // rbx
  __int64 v5; // rbp
  char v6; // dl
  char v7; // cl
  UFG::HavokNavDynamicOutline **p; // rax
  UFG::HavokNavDynamicOutline *v9; // rdi
  unsigned int v10; // eax
  char v11; // al

  size = 0;
  if ( this->m_dynamicOutlinesDeletionQueue.size > 5 )
  {
    size = 5;
  }
  else if ( forceUpdate )
  {
    size = this->m_dynamicOutlinesDeletionQueue.size;
  }
  if ( size )
  {
    v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v5 = size;
    do
    {
      v6 = ++*(_BYTE *)(v4 + 80);
      *(_DWORD *)(v4 + 4i64 * v6) = 1;
      *(_QWORD *)(v4 + 8i64 * v6 + 16) = "AI::HavokNavManager::CommitDeletionQueue";
      *(_QWORD *)(v4 + 8i64 * v6 + 48) = 0i64;
      v7 = *(_BYTE *)(v4 + 81);
      if ( v6 > v7 )
        v7 = v6;
      *(_BYTE *)(v4 + 81) = v7;
      p = this->m_dynamicOutlinesDeletionQueue.p;
      v9 = *p;
      hkaiWorld::removeSilhouetteGenerator(this->m_world, (*p)->m_pSilhouette);
      v9->vfptr->__vecDelDtor(v9, 1u);
      *this->m_dynamicOutlinesDeletionQueue.p = this->m_dynamicOutlinesDeletionQueue.p[this->m_dynamicOutlinesDeletionQueue.size
                                                                                     - 1];
      v10 = this->m_dynamicOutlinesDeletionQueue.size;
      if ( v10 > 1 )
        this->m_dynamicOutlinesDeletionQueue.size = v10 - 1;
      else
        this->m_dynamicOutlinesDeletionQueue.size = 0;
      v11 = *(_BYTE *)(v4 + 80);
      if ( v11 > 0 )
      {
        *(_BYTE *)(v4 + 80) = v11 - 1;
      }
      else
      {
        *(_BYTE *)(v4 + 80) = 0;
        *(_DWORD *)v4 = 3;
        *(_QWORD *)(v4 + 16) = 0i64;
        *(_QWORD *)(v4 + 48) = 0i64;
      }
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 382
// RVA: 0xEFF90
void __fastcall UFG::HavokNavManager::LowHealthDefrag(UFG::HavokNavManager *this)
{
  __int64 LargestFree; // rax
  float v3; // xmm6_4
  __int64 TotalFreeBytes; // rax
  float v5; // xmm0_4

  LargestFree = UFG::qMemoryPool::GetLargestFree(&gAIMemoryPool, 0i64);
  v3 = (float)(int)LargestFree;
  if ( LargestFree < 0 )
    v3 = v3 + 1.8446744e19;
  TotalFreeBytes = UFG::qMemoryPool::GetTotalFreeBytes(&gAIMemoryPool);
  v5 = (float)(int)TotalFreeBytes;
  if ( TotalFreeBytes < 0 )
    v5 = v5 + 1.8446744e19;
  if ( (float)((float)(v3 / v5) * 100.0) < 0.30000001 )
    UFG::HavokNavManager::Defrag(this, DefragVerbosity_Hide);
}

// File Line: 392
// RVA: 0xF39B0
void __fastcall UFG::HavokNavManager::UpdateDynamicObstaclesPre(UFG::HavokNavManager *this)
{
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::CharacterOccupantComponent *m_pComponent; // rcx
  UFG::VehicleOccupantComponent *CurrentVehicle; // rax
  UFG::PhysicsMoverInterface *mNext; // rcx
  bool v6; // di
  unsigned __int64 Ticks; // rax
  __int64 v8; // rdi
  char v9; // dl
  char v10; // cl
  hkJobThreadPool *m_jobThreadPool; // r9
  hkJobQueue *m_jobQueue; // r8
  char v13; // al
  int m_StitchingDelay; // eax

  if ( (_S6_2 & 1) == 0 )
  {
    _S6_2 |= 1u;
    sLastUpdatedTick = UFG::qGetTicks();
  }
  UFG::qGetTicks();
  this->m_highspeedMode = 0;
  LocalPlayer = UFG::GetLocalPlayer();
  if ( LocalPlayer )
  {
    m_pComponent = (UFG::CharacterOccupantComponent *)LocalPlayer->m_Components.p[44].m_pComponent;
    if ( m_pComponent )
    {
      CurrentVehicle = UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
      if ( CurrentVehicle )
      {
        mNext = (UFG::PhysicsMoverInterface *)CurrentVehicle->mpDriver.m_pPointer[4].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext;
        if ( mNext )
        {
          if ( UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH(mNext) > 60.0 )
            this->m_highspeedMode = 1;
        }
      }
    }
  }
  v6 = 0;
  Ticks = UFG::qGetTicks();
  if ( UFG::qGetTickTime(sLastUpdatedTick, Ticks) > 1.0 )
  {
    sLastUpdatedTick = UFG::qGetTicks();
    v6 = 1;
  }
  UFG::qGetTicks();
  if ( this->m_highspeedMode )
    UFG::HavokNavManager::RequeueAdditionQueue(this, v6);
  else
    UFG::HavokNavManager::ApplyAdditionQueue(this, v6);
  UFG::HavokNavManager::ApplyDeletionQueue(this, v6);
  v8 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v9 = ++*(_BYTE *)(v8 + 80);
  *(_DWORD *)(v8 + 4i64 * v9) = 1;
  *(_QWORD *)(v8 + 8i64 * v9 + 16) = "AI::HavokNavManager::UpdateDynamicObstacles";
  *(_QWORD *)(v8 + 8i64 * v9 + 48) = 1i64;
  v10 = *(_BYTE *)(v8 + 81);
  if ( v9 > v10 )
    v10 = v9;
  *(_BYTE *)(v8 + 81) = v10;
  if ( UFG::HavokNavManager::ms_bEnableOutlineMT )
  {
    m_jobThreadPool = this->m_jobThreadPool;
    m_jobQueue = this->m_jobQueue;
  }
  else
  {
    m_jobThreadPool = 0i64;
    m_jobQueue = 0i64;
  }
  hkaiWorld::stepSilhouettesMT(this->m_world, 0i64, m_jobQueue, m_jobThreadPool);
  v13 = *(_BYTE *)(v8 + 80);
  if ( v13 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v13 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  if ( this->m_StitchInstances.m_size )
  {
    m_StitchingDelay = this->m_StitchingDelay;
    if ( m_StitchingDelay <= 0 )
      ((void (__fastcall *)(UFG::HavokNavManager *, _QWORD, _QWORD))this->vfptr[1].ExitGame)(this, 0i64, 0i64);
    else
      this->m_StitchingDelay = m_StitchingDelay - 1;
  }
}

// File Line: 509
// RVA: 0xE95D0
void __fastcall UFG::HavokNavManager::Defrag(
        UFG::HavokNavManager *this,
        UFG::HavokNavManager::DefragVerbosity verbosity)
{
  UFG::HavokNavManager *v2; // rbx
  __int64 v3; // r14
  char v4; // r8
  UFG::HavokNavManager::DefragVerbosity v5; // edi
  char v6; // cl
  unsigned int m_size; // eax
  __int64 v8; // rdi
  __int64 v9; // r12
  UFG::HavokNavManager::MeshCell *v10; // rsi
  unsigned int v11; // eax
  __int64 v12; // r15
  __int64 v13; // r13
  void **p_vfptr; // rbx
  unsigned int v15; // eax
  __int64 v16; // rdi
  __int64 v17; // r12
  UFG::HavokNavManager::MeshCell *v18; // rsi
  unsigned int v19; // eax
  __int64 v20; // r15
  __int64 v21; // r13
  void **v22; // rbx
  char v23; // al

  v2 = this;
  v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v4 = ++*(_BYTE *)(v3 + 80);
  v5 = verbosity;
  *(_DWORD *)(v3 + 4i64 * v4) = 1;
  *(_QWORD *)(v3 + 8i64 * v4 + 16) = "AI::HavokNavManagerDefrag";
  *(_QWORD *)(v3 + 8i64 * v4 + 48) = 0i64;
  v6 = *(_BYTE *)(v3 + 81);
  if ( v4 > v6 )
    v6 = v4;
  *(_BYTE *)(v3 + 81) = v6;
  UFG::qGetTicks();
  if ( v5 == DefragVerbosity_Show )
    _((AMD_HD3D *)&gAIMemoryPool);
  m_size = v2->m_cells.m_size;
  if ( m_size )
  {
    v8 = 0i64;
    v9 = m_size;
    do
    {
      v10 = v2->m_cells.m_data[v8];
      v11 = v10->m_Instances.m_size;
      if ( v11 )
      {
        v12 = 0i64;
        v13 = v11;
        do
        {
          p_vfptr = (void **)&v10->m_Instances.m_data[v12]->vfptr;
          UFG::qMemoryPool::Size(&gAIMemoryPool, p_vfptr[26]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, p_vfptr[28]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, p_vfptr[30]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, p_vfptr[32]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, p_vfptr[34]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, p_vfptr[36]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, p_vfptr[38]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, p_vfptr[40]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, p_vfptr[52]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, p_vfptr[54]);
          ++v12;
          UFG::qMemoryPool::Size(&gAIMemoryPool, p_vfptr[56]);
          --v13;
        }
        while ( v13 );
        v2 = this;
      }
      ++v8;
      --v9;
    }
    while ( v9 );
    v5 = verbosity;
  }
  if ( v5 == DefragVerbosity_Show )
    _((AMD_HD3D *)&gAIMemoryPool);
  v15 = v2->m_cells.m_size;
  if ( v15 )
  {
    v16 = 0i64;
    v17 = v15;
    do
    {
      v18 = v2->m_cells.m_data[v16];
      v19 = v18->m_Instances.m_size;
      if ( v19 )
      {
        v20 = 0i64;
        v21 = v19;
        do
        {
          v22 = (void **)&v18->m_Instances.m_data[v20]->vfptr;
          UFG::qMemoryPool::Size(&gAIMemoryPool, v22[26]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v22[28]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v22[30]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v22[32]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v22[34]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v22[36]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v22[38]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v22[40]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v22[52]);
          UFG::qMemoryPool::Size(&gAIMemoryPool, v22[54]);
          ++v20;
          UFG::qMemoryPool::Size(&gAIMemoryPool, v22[56]);
          --v21;
        }
        while ( v21 );
        v2 = this;
      }
      ++v16;
      --v17;
    }
    while ( v17 );
    v5 = verbosity;
  }
  if ( v5 == DefragVerbosity_Show )
    _((AMD_HD3D *)&gAIMemoryPool);
  v23 = *(_BYTE *)(v3 + 80);
  if ( v23 > 0 )
  {
    *(_BYTE *)(v3 + 80) = v23 - 1;
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
void __fastcall UFG::HavokNavManager::AiListener::dynamicNavMeshModifiedCallback(
        UFG::HavokNavManager::AiListener *this,
        hkaiWorld::NavMeshModifiedCallbackContext *context)
{
  unsigned int v4; // ecx
  __int64 v5; // r15
  __int64 v6; // rsi
  __int64 v7; // rdi
  _QWORD *v8; // rax
  __int64 v9; // rbx
  __int64 v10; // rbx
  char v11; // dl
  char v12; // cl
  char v13; // al
  hkaiUserEdgeUtils::CutMeshUpdateParameters params; // [rsp+60h] [rbp+8h] BYREF

  v4 = *(_DWORD *)(*(_QWORD *)&this->m_memSizeAndFlags + 40i64);
  if ( v4 )
  {
    v5 = tls_index;
    v6 = v4;
    v7 = 0i64;
    do
    {
      if ( *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)&this->m_memSizeAndFlags + 32i64) + v7) + 48i64) )
      {
        v8 = NtCurrentTeb()->Reserved1[11];
        *(_WORD *)&params.m_clearanceResetMode.m_storage = 256;
        params.m_minEdgeLength = 0.050000001;
        v9 = v8[v5];
        params.m_compactHierarchyGraphs.m_bool = 1;
        v10 = v9 + 16;
        v11 = ++*(_BYTE *)(v10 + 80);
        *(_DWORD *)(v10 + 4i64 * v11) = 1;
        *(_QWORD *)(v10 + 8i64 * v11 + 16) = "HavokNavManager";
        *(_QWORD *)(v10 + 8i64 * v11 + 48) = 0i64;
        v12 = *(_BYTE *)(v10 + 81);
        if ( v11 > v12 )
          v12 = v11;
        *(_BYTE *)(v10 + 81) = v12;
        hkaiUserEdgeUtils::selectiveAddUserEdgePairsToCutMesh(
          *(hkaiStreamingCollection **)(*(_QWORD *)(*(_QWORD *)&this->m_memSizeAndFlags + 24i64) + 32i64),
          (hkArrayBase<hkaiUserEdgeUtils::UserEdgePair> *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)&this->m_memSizeAndFlags
                                                                                             + 32i64)
                                                                                 + v7)
                                                                     + 48i64)
                                                         + 16i64),
          *(hkaiNavMeshCutter **)(*(_QWORD *)(*(_QWORD *)&this->m_memSizeAndFlags + 24i64) + 40i64),
          context->m_cutFaceKeys,
          context->m_uncutFaceKeys,
          &params);
        v13 = *(_BYTE *)(v10 + 80);
        if ( v13 > 0 )
        {
          *(_BYTE *)(v10 + 80) = v13 - 1;
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
  __int64 v2; // rsi
  char v3; // dl
  char v4; // cl
  unsigned int size; // eax
  __int64 v6; // rdi
  __int64 v7; // rbp
  UFG::HavokNavDynamicOutline *v8; // rcx
  UFG::HavokNavDynamicOutline **p; // rcx
  unsigned int v10; // eax
  __int64 v11; // r14
  __int64 v12; // rbp
  UFG::HavokNavDynamicOutline *v13; // rdi
  UFG::HavokNavDynamicOutline **v14; // rcx
  unsigned int v15; // eax
  __int64 v16; // r14
  __int64 v17; // rbp
  UFG::HavokNavDynamicOutline *v18; // rdi
  UFG::HavokNavDynamicOutline **v19; // rcx
  char v20; // al
  char v21; // dl
  char v22; // cl
  char v23; // al

  v2 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v3 = ++*(_BYTE *)(v2 + 80);
  *(_DWORD *)(v2 + 4i64 * v3) = 1;
  *(_QWORD *)(v2 + 8i64 * v3 + 16) = "AI::HavokNavManager::ExitGameDeleteQueue";
  *(_QWORD *)(v2 + 8i64 * v3 + 48) = 0i64;
  v4 = *(_BYTE *)(v2 + 81);
  if ( v3 > v4 )
    v4 = v3;
  *(_BYTE *)(v2 + 81) = v4;
  size = this->m_dynamicOutlinesAdditionQueue.size;
  if ( size )
  {
    v6 = 0i64;
    v7 = size;
    do
    {
      v8 = this->m_dynamicOutlinesAdditionQueue.p[v6];
      if ( v8 )
        v8->vfptr->__vecDelDtor(v8, 1u);
      ++v6;
      --v7;
    }
    while ( v7 );
  }
  p = this->m_dynamicOutlinesAdditionQueue.p;
  if ( p )
    operator delete[](p);
  this->m_dynamicOutlinesAdditionQueue.p = 0i64;
  *(_QWORD *)&this->m_dynamicOutlinesAdditionQueue.size = 0i64;
  v10 = this->m_dynamicOutlines.size;
  if ( v10 )
  {
    v11 = 0i64;
    v12 = v10;
    do
    {
      v13 = this->m_dynamicOutlines.p[v11];
      hkaiWorld::removeSilhouetteGenerator(this->m_world, v13->m_pSilhouette);
      v13->vfptr->__vecDelDtor(v13, 1u);
      ++v11;
      --v12;
    }
    while ( v12 );
  }
  v14 = this->m_dynamicOutlines.p;
  if ( v14 )
    operator delete[](v14);
  this->m_dynamicOutlines.p = 0i64;
  *(_QWORD *)&this->m_dynamicOutlines.size = 0i64;
  v15 = this->m_dynamicOutlinesDeletionQueue.size;
  if ( v15 )
  {
    v16 = 0i64;
    v17 = v15;
    do
    {
      v18 = this->m_dynamicOutlinesDeletionQueue.p[v16];
      hkaiWorld::removeSilhouetteGenerator(this->m_world, v18->m_pSilhouette);
      v18->vfptr->__vecDelDtor(v18, 1u);
      ++v16;
      --v17;
    }
    while ( v17 );
  }
  v19 = this->m_dynamicOutlinesDeletionQueue.p;
  if ( v19 )
    operator delete[](v19);
  this->m_dynamicOutlinesDeletionQueue.p = 0i64;
  *(_QWORD *)&this->m_dynamicOutlinesDeletionQueue.size = 0i64;
  v20 = *(_BYTE *)(v2 + 80);
  if ( v20 > 0 )
  {
    *(_BYTE *)(v2 + 80) = v20 - 1;
  }
  else
  {
    *(_BYTE *)(v2 + 80) = 0;
    *(_DWORD *)v2 = 3;
    *(_QWORD *)(v2 + 16) = 0i64;
    *(_QWORD *)(v2 + 48) = 0i64;
  }
  v21 = ++*(_BYTE *)(v2 + 80);
  *(_DWORD *)(v2 + 4i64 * v21) = 1;
  *(_QWORD *)(v2 + 8i64 * v21 + 16) = "AI::HavokNavManager::ExitGameUpdateObstacles";
  *(_QWORD *)(v2 + 8i64 * v21 + 48) = 1i64;
  v22 = *(_BYTE *)(v2 + 81);
  if ( v21 > v22 )
    v22 = v21;
  *(_BYTE *)(v2 + 81) = v22;
  hkaiWorld::stepSilhouettesMT(this->m_world, 0i64, 0i64, 0i64);
  v23 = *(_BYTE *)(v2 + 80);
  if ( v23 > 0 )
  {
    *(_BYTE *)(v2 + 80) = v23 - 1;
  }
  else
  {
    *(_BYTE *)(v2 + 80) = 0;
    *(_DWORD *)v2 = 3;
    *(_QWORD *)(v2 + 16) = 0i64;
    *(_QWORD *)(v2 + 48) = 0i64;
  }
  UFG::HavokNavManager::Defrag(this, DefragVerbosity_Hide);
}

// File Line: 985
// RVA: 0xF26D0
void __fastcall UFG::HavokNavManager::Update(UFG::HavokNavManager *this, float delta_sec)
{
  __int64 v2; // rdx

  if ( tester )
  {
    LOBYTE(v2) = 1;
    ((void (__fastcall *)(UFG::HavokNavManager *, __int64, _QWORD))this->vfptr[1].ExitGame)(this, v2, 0i64);
    tester = 0;
  }
  if ( doPrint )
  {
    UFG::HavokNavManager::PrintMeshInstances(this);
    doPrint = 0;
  }
}

// File Line: 1062
// RVA: 0xEF6D0
__int64 __fastcall UFG::HavokNavManager::IsInsideAIMesh(
        UFG::HavokNavManager *this,
        UFG::qVector3 *position,
        float tolerance)
{
  char v4[24]; // [rsp+20h] [rbp-18h] BYREF

  return ((__int64 (__fastcall *)(UFG::HavokNavManager *, UFG::qVector3 *, char *))this->vfptr->GetClosestAIMesh)(
           this,
           position,
           v4);
}

// File Line: 1069
// RVA: 0xECE70
bool __fastcall UFG::HavokNavManager::GetClosestAIMesh(
        UFG::HavokNavManager *this,
        UFG::qVector3 *position,
        UFG::qVector3 *closestPosition,
        float tolerance)
{
  hkaiNavMeshQueryMediator *DynamicQueryMediator; // rax
  __m128 y_low; // xmm2
  __m128 x_low; // xmm3
  hkBaseObjectVtbl *vfptr; // r9
  __m128 v11; // xmm3
  float v12; // xmm1_4
  float v13; // xmm0_4
  int v15[4]; // [rsp+20h] [rbp-88h] BYREF
  int v16; // [rsp+30h] [rbp-78h] BYREF
  __int64 v17; // [rsp+38h] [rbp-70h]
  __int128 v18; // [rsp+40h] [rbp-68h]
  __int64 v19; // [rsp+50h] [rbp-58h]
  __m128 v20; // [rsp+60h] [rbp-48h]
  __m128 v21; // [rsp+70h] [rbp-38h]
  __int64 v22; // [rsp+80h] [rbp-28h]

  DynamicQueryMediator = hkaiWorld::getDynamicQueryMediator(this->m_world);
  if ( DynamicQueryMediator )
  {
    y_low = (__m128)LODWORD(position->y);
    x_low = (__m128)LODWORD(position->x);
    vfptr = DynamicQueryMediator->vfptr;
    v18 = 0i64;
    v16 = 0;
    v11 = _mm_unpacklo_ps(x_low, (__m128)LODWORD(position->z));
    v17 = 0i64;
    v19 = 0i64;
    v22 = 0i64;
    v21 = _mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0);
    v20 = _mm_unpacklo_ps(v11, _mm_unpacklo_ps(y_low, (__m128)(unsigned int)FLOAT_1_0));
    LODWORD(DynamicQueryMediator) = ((__int64 (__fastcall *)(hkaiNavMeshQueryMediator *, int *, int *))vfptr[1].__first_virtual_table_function__)(
                                      DynamicQueryMediator,
                                      &v16,
                                      v15);
    v12 = *(float *)&v15[1];
    LOBYTE(DynamicQueryMediator) = (_DWORD)DynamicQueryMediator != -1;
    LODWORD(closestPosition->x) = v15[0];
    v13 = *(float *)&v15[2];
    closestPosition->y = v12;
    closestPosition->z = v13;
  }
  return (char)DynamicQueryMediator;
}

// File Line: 1089
// RVA: 0xEF4C0
char __fastcall UFG::HavokNavManager::IsAIMeshLoadedAt(UFG::HavokNavManager *this, UFG::qVector3 *position)
{
  unsigned int VisIndexAtPosition; // eax

  VisIndexAtPosition = UFG::SectionChooser::GetVisIndexAtPosition(position, 0);
  return UFG::SectionChooser::IsSectionVisible_VisIndex(VisIndexAtPosition, SCENERY_LAYER_STD, 0);
}

// File Line: 1100
// RVA: 0xF1AB0
char __fastcall UFG::HavokNavManager::TesselateFace(
        UFG::HavokNavManager *this,
        unsigned int faceKey,
        float spacing,
        float border,
        bool resizeVectorIfNeeded)
{
  float v6; // xmm5_4
  UFG::HavokNavManager *v7; // rdi
  signed int v8; // r10d
  hkaiNavMeshInstance *m_instancePtr; // rbx
  int m_numOriginalFaces; // eax
  __int64 v11; // r14
  signed int v12; // edx
  UFG::qArray<UFG::qVector3,0> *p_m_aTmpTesselationData; // r15
  __int64 v14; // r13
  int v15; // r12d
  int v16; // edx
  int m_numOriginalEdges; // eax
  __int64 v18; // rcx
  hkaiNavMesh::Edge *m_originalEdges; // rax
  int v20; // r8d
  __int64 m_a; // rax
  int m_numOriginalVertices; // ecx
  __m128 *p_m_quad; // rax
  __int64 size; // rbp
  unsigned int v25; // esi
  unsigned int capacity; // edx
  unsigned int v27; // edx
  __int64 v28; // rcx
  UFG::qVector3 *p; // rax
  int v30; // r8d
  unsigned int v31; // r12d
  float v32; // xmm9_4
  float v33; // xmm7_4
  unsigned int v34; // edx
  __int64 v35; // r11
  int v36; // eax
  float *p_y; // rcx
  unsigned __int64 v38; // r9
  float v39; // xmm0_4
  float v40; // xmm0_4
  float v41; // xmm0_4
  float *v42; // r9
  __int64 v43; // r10
  unsigned int v44; // r11d
  UFG::qVector3 *v45; // r10
  float x; // xmm15_4
  float y; // xmm8_4
  float z; // xmm3_4
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
  int v62; // r9d
  unsigned int v63; // ecx
  UFG::qVector3 *v64; // r8
  unsigned int v65; // edi
  __int64 v66; // rcx
  __int64 v67; // rdx
  int v68; // r9d
  unsigned int v69; // ecx
  UFG::qVector3 *v70; // r8
  __int64 v71; // rcx
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
  int v83; // eax
  float v84; // xmm10_4
  int v85; // r15d
  __int64 v86; // r14
  unsigned int v87; // ebp
  unsigned int v88; // ebx
  unsigned int v89; // ebx
  unsigned __int64 v90; // rax
  char *v91; // rsi
  __int64 i; // rdx
  __int64 v93; // rcx
  UFG::qVector3 *v94; // rax
  float v95; // xmm0_4
  float v96; // xmm1_4
  __int64 v97; // rcx
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
  int v110; // [rsp+48h] [rbp-110h]
  float v111; // [rsp+4Ch] [rbp-10Ch]
  __m128 v112; // [rsp+50h] [rbp-108h]
  float v114; // [rsp+168h] [rbp+10h]

  v6 = spacing;
  v7 = this;
  this->m_aTesselationData.size = 0;
  v8 = faceKey & 0x3FFFFF;
  m_instancePtr = this->m_world->m_streamingCollection.m_pntr->m_instances.m_data[faceKey >> 22].m_instancePtr;
  if ( !m_instancePtr )
    return 0;
  m_numOriginalFaces = m_instancePtr->m_numOriginalFaces;
  if ( v8 < m_numOriginalFaces )
  {
    if ( m_instancePtr->m_faceMap.m_size )
      v12 = m_instancePtr->m_faceMap.m_data[v8];
    else
      v12 = faceKey & 0x3FFFFF;
    if ( v12 == -1 )
      v11 = (__int64)&m_instancePtr->m_originalFaces[v8];
    else
      v11 = (__int64)&m_instancePtr->m_instancedFaces.m_data[v12];
  }
  else
  {
    v11 = (__int64)&m_instancePtr->m_ownedFaces.m_data[v8 - m_numOriginalFaces];
  }
  p_m_aTmpTesselationData = &this->m_aTmpTesselationData;
  this->m_aTmpTesselationData.size = 0;
  v14 = *(__int16 *)(v11 + 8);
  v15 = 0;
  if ( (int)v14 > 0 )
  {
    do
    {
      v16 = v15 + *(_DWORD *)v11;
      m_numOriginalEdges = m_instancePtr->m_numOriginalEdges;
      if ( v16 < m_numOriginalEdges )
      {
        if ( m_instancePtr->m_edgeMap.m_size )
          v20 = m_instancePtr->m_edgeMap.m_data[v16];
        else
          v20 = v15 + *(_DWORD *)v11;
        if ( v20 == -1 )
        {
          v18 = v16;
          m_originalEdges = m_instancePtr->m_originalEdges;
        }
        else
        {
          v18 = v20;
          m_originalEdges = m_instancePtr->m_instancedEdges.m_data;
        }
      }
      else
      {
        v18 = v16 - m_numOriginalEdges;
        m_originalEdges = m_instancePtr->m_ownedEdges.m_data;
      }
      m_a = m_originalEdges[v18].m_a;
      m_numOriginalVertices = m_instancePtr->m_numOriginalVertices;
      if ( (int)m_a >= m_numOriginalVertices )
        p_m_quad = &m_instancePtr->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices].m_quad;
      else
        p_m_quad = &m_instancePtr->m_originalVertices[m_a].m_quad;
      v112 = _mm_add_ps(
               m_instancePtr->m_referenceFrame.m_transform.m_translation.m_quad,
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_shuffle_ps(*p_m_quad, *p_m_quad, 85),
                     m_instancePtr->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                   _mm_mul_ps(
                     _mm_shuffle_ps(*p_m_quad, *p_m_quad, 0),
                     m_instancePtr->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                 _mm_mul_ps(
                   _mm_shuffle_ps(*p_m_quad, *p_m_quad, 170),
                   m_instancePtr->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)));
      size = p_m_aTmpTesselationData->size;
      v25 = size + 1;
      capacity = v7->m_aTmpTesselationData.capacity;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v27 = 2 * capacity;
        else
          v27 = 1;
        for ( ; v27 < v25; v27 *= 2 )
          ;
        if ( v27 - v25 > 0x10000 )
          v27 = size + 65537;
        UFG::qArray<UFG::qVector3,0>::Reallocate(&v7->m_aTmpTesselationData, v27, "qArray.Add");
      }
      p_m_aTmpTesselationData->size = v25;
      v28 = size;
      p = v7->m_aTmpTesselationData.p;
      *(_QWORD *)&p[v28].x = v112.m128_u64[0];
      LODWORD(p[v28].z) = v112.m128_i32[2];
      ++v15;
    }
    while ( v15 < (int)v14 );
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
    p_y = &v7->m_aTmpTesselationData.p[1].y;
    v38 = ((unsigned __int64)(v14 - 4) >> 2) + 1;
    v35 = 4 * v38;
    do
    {
      v39 = *(p_y - 3);
      if ( v39 > v32 )
      {
        v32 = *(p_y - 3);
        v30 = v34;
      }
      if ( v39 < v33 )
      {
        v33 = *(p_y - 3);
        v31 = v34;
      }
      if ( *p_y > v32 )
      {
        v32 = *p_y;
        v30 = v36 - 1;
      }
      if ( *p_y < v33 )
      {
        v33 = *p_y;
        v31 = v36 - 1;
      }
      v40 = p_y[3];
      if ( v40 > v32 )
      {
        v32 = p_y[3];
        v30 = v36;
      }
      if ( v40 < v33 )
      {
        v33 = p_y[3];
        v31 = v36;
      }
      v41 = p_y[6];
      if ( v41 > v32 )
      {
        v32 = p_y[6];
        v30 = v36 + 1;
      }
      if ( v41 < v33 )
      {
        v33 = p_y[6];
        v31 = v36 + 1;
      }
      v34 += 4;
      v36 += 4;
      p_y += 12;
      --v38;
    }
    while ( v38 );
  }
  if ( v35 < v14 )
  {
    v42 = &v7->m_aTmpTesselationData.p->y + 2 * v35 + v35;
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
  x = v45[v31].x;
  y = v45[v31].y;
  v106 = y;
  z = v45[v31].z;
  v114 = z;
  v49 = (unsigned int)((int)(v31 + v14 + 1) >> 31);
  LODWORD(v49) = (int)(v31 + v14 + 1) % (int)v14;
  v50 = v45[v49].x;
  v107 = v50;
  v51 = v45[v49].y;
  v52 = v45[v49].z;
  v101 = v52;
  v53 = x;
  v104 = x;
  v54 = y;
  v108 = y;
  v55 = z;
  v100 = z;
  v56 = (unsigned int)((int)(v31 + v14 - 1) >> 31);
  LODWORD(v56) = (int)(v31 + v14 - 1) % (int)v14;
  v57 = v45[v56].x;
  v102 = v57;
  v58 = v45[v56].y;
  v105 = v45[v56].z;
  v59 = v33 + border;
  v60 = v32 - border;
  if ( v59 >= v60 )
    return v7->m_aTesselationData.size != 0;
  v109 = border * 2.0;
  v61 = *(float *)&FLOAT_1_0;
  v111 = 1.0 / v6;
  while ( 1 )
  {
    if ( v51 < v59 )
    {
      v62 = v14 + 1;
      v63 = (int)(v14 + 1 + v44) % (int)v14;
      v64 = v7->m_aTmpTesselationData.p;
      do
      {
        v65 = v63;
        v103 = v63;
        v66 = v63;
        x = v64[v66].x;
        y = v64[v66].y;
        v106 = y;
        z = v64[v66].z;
        v114 = z;
        v67 = (unsigned int)((int)(v62 + v65) >> 31);
        LODWORD(v67) = (int)(v62 + v65) % (int)v14;
        v63 = v67;
        v50 = v64[v67].x;
        v107 = v50;
        v51 = v64[v67].y;
        v52 = v64[v67].z;
        v101 = v52;
      }
      while ( v51 < v59 );
      v7 = this;
    }
    if ( v58 < v59 )
    {
      v68 = v14 - 1;
      v69 = (int)(v14 - 1 + v31) % (int)v14;
      v70 = v7->m_aTmpTesselationData.p;
      do
      {
        v31 = v69;
        v71 = v69;
        v53 = v70[v71].x;
        v104 = v53;
        v54 = v70[v71].y;
        v108 = v54;
        v55 = v70[v71].z;
        v100 = v55;
        v72 = (unsigned int)((int)(v68 + v31) >> 31);
        LODWORD(v72) = (int)(v68 + v31) % (int)v14;
        v69 = v72;
        v57 = v70[v72].x;
        v102 = v57;
        v58 = v70[v72].y;
        v105 = v70[v72].z;
      }
      while ( v58 < v59 );
    }
    v73 = v61 / (float)(v51 - y);
    v74 = v73 * (float)(v50 - x);
    v75 = v73 * (float)(v52 - z);
    v76 = v105 - v55;
    v77 = 1.0 / (float)(v58 - v54);
    v78 = v77 * (float)(v57 - v53);
    v79 = v59 - v54;
    v80 = (float)((float)(v59 - v54) * v78) + v53;
    v81 = v79 * (float)(v77 * v76);
    v55 = v100;
    v82 = v81 + v100;
    z = v114;
    v83 = (int)(float)((float)((float)((float)((float)((float)(v59 - y) * v74) + x) - v80) - v109) * v111);
    v110 = v83;
    if ( v83 > 0 )
      break;
LABEL_92:
    v59 = v59 + spacing;
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
  v84 = (float)((float)((float)((float)(v59 - y) * v75) + v114) - v82) / (float)v83;
  v85 = 0;
  while ( !resizeVectorIfNeeded || v7->m_aTesselationData.size != v7->m_aTesselationData.capacity )
  {
    v86 = v7->m_aTesselationData.size;
    v87 = v86 + 1;
    v88 = v7->m_aTesselationData.capacity;
    if ( (int)v86 + 1 > v88 )
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
          for ( i = 0i64; (unsigned int)i < v7->m_aTesselationData.size; i = (unsigned int)(i + 1) )
          {
            v93 = 3 * i;
            v94 = v7->m_aTesselationData.p;
            v95 = v94[i].y;
            v96 = v94[i].z;
            *(float *)&v91[4 * v93] = v94[i].x;
            *(float *)&v91[4 * v93 + 4] = v95;
            *(float *)&v91[4 * v93 + 8] = v96;
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
    v98[v97].x = (float)((float)v85 * spacing) + (float)(v80 + border);
    v98[v97].y = v59;
    v98[v97].z = (float)((float)v85++ * v84) + v82;
    if ( v85 >= v110 )
    {
      y = v106;
      z = v114;
      v55 = v100;
      goto LABEL_92;
    }
  }
  return 1;
}

// File Line: 1235
// RVA: 0xEC510
__int64 __fastcall UFG::HavokNavManager::FindPointOnNavmesh(
        UFG::HavokNavManager *this,
        UFG::qVector3 *aabbMin,
        UFG::qVector3 *aabbMax,
        unsigned int materialFlags)
{
  UFG::qVector3 *v5; // rsi
  __m128 v8; // xmm7
  __m128 v9; // xmm6
  hkaiNavMeshQueryMediator *DynamicQueryMediator; // rax
  int v11; // r8d
  bool v12; // zf
  int v13; // r14d
  __int64 v14; // rdi
  hkaiStreamingCollection *m_pntr; // rsi
  int v16; // edx
  hkaiNavMeshInstance *m_instancePtr; // r9
  int m_faceDataStriding; // r11d
  int m_numOriginalFaces; // eax
  __int64 v20; // rcx
  _DWORD *m_originalFaceData; // rax
  int v22; // r10d
  int v23; // eax
  int v24; // r12d
  int v25; // r14d
  __int64 v26; // rdi
  int v27; // eax
  int v28; // r8d
  int v29; // edi
  __int64 v30; // r14
  float v31; // xmm6_4
  float v32; // xmm7_4
  unsigned int v33; // r9d
  unsigned int size; // ecx
  UFG::qVector3 *p; // rax
  float x; // xmm0_4
  float v37; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  unsigned int v40; // eax
  int v41; // ecx
  __int64 v42; // rdx
  UFG::qVector3 *v43; // rax
  float v44; // xmm1_4
  float v45; // xmm2_4
  unsigned __int8 v46; // bl
  _DWORD *v48; // [rsp+0h] [rbp-79h] BYREF
  int range; // [rsp+8h] [rbp-71h]
  int v50; // [rsp+Ch] [rbp-6Dh]
  int v51; // [rsp+18h] [rbp-61h] BYREF
  bool resizeVectorIfNeeded[8]; // [rsp+20h] [rbp-59h]
  __int128 v53; // [rsp+28h] [rbp-51h]
  __int64 v54; // [rsp+38h] [rbp-41h]
  __m128 v55; // [rsp+48h] [rbp-31h]
  __m128 v56; // [rsp+58h] [rbp-21h]
  UFG::qVector3 *v57; // [rsp+D8h] [rbp+5Fh]
  float v58; // [rsp+E8h] [rbp+6Fh]
  float border; // [rsp+F0h] [rbp+77h]
  float *retaddr; // [rsp+F8h] [rbp+7Fh]

  *((_QWORD *)&v53 + 1) = -2i64;
  v5 = aabbMax;
  v48 = 0i64;
  range = 0;
  v50 = 0x80000000;
  v8 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(aabbMax->x), (__m128)LODWORD(aabbMax->z)),
         _mm_unpacklo_ps((__m128)LODWORD(aabbMax->y), (__m128)0i64));
  v9 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(aabbMin->x), (__m128)LODWORD(aabbMin->z)),
         _mm_unpacklo_ps((__m128)LODWORD(aabbMin->y), (__m128)0i64));
  DynamicQueryMediator = hkaiWorld::getDynamicQueryMediator(this->m_world);
  if ( !DynamicQueryMediator )
    goto LABEL_42;
  v51 = 0;
  *(_QWORD *)resizeVectorIfNeeded = 0i64;
  v53 = 0i64;
  v54 = 0i64;
  v55 = v9;
  v56 = v8;
  ((void (__fastcall *)(hkaiNavMeshQueryMediator *, int *, _DWORD **))DynamicQueryMediator->vfptr[3].__first_virtual_table_function__)(
    DynamicQueryMediator,
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
    m_pntr = this->m_world->m_streamingCollection.m_pntr;
    do
    {
      v16 = v48[v14] & 0x3FFFFF;
      m_instancePtr = m_pntr->m_instances.m_data[v48[v14] >> 22].m_instancePtr;
      m_faceDataStriding = m_instancePtr->m_faceDataStriding;
      if ( m_faceDataStriding )
      {
        m_numOriginalFaces = m_instancePtr->m_numOriginalFaces;
        if ( v16 < m_numOriginalFaces )
        {
          if ( m_instancePtr->m_faceMap.m_size )
            v22 = m_instancePtr->m_faceMap.m_data[v16];
          else
            v22 = v48[v14] & 0x3FFFFF;
          if ( v22 == -1 )
          {
            v20 = v16 * m_faceDataStriding;
            m_originalFaceData = m_instancePtr->m_originalFaceData;
          }
          else
          {
            v20 = m_faceDataStriding * v22;
            m_originalFaceData = m_instancePtr->m_instancedFaceData.m_data;
          }
        }
        else
        {
          v20 = m_faceDataStriding * (v16 - m_numOriginalFaces);
          m_originalFaceData = m_instancePtr->m_ownedFaceData.m_data;
        }
        v23 = m_originalFaceData[v20];
      }
      else
      {
        v23 = 0;
      }
      if ( (v23 & materialFlags) != 0 )
      {
        ++v13;
        ++v14;
      }
      else
      {
        v48[v14] = v48[v11 - 1];
        v11 = --range;
      }
    }
    while ( v13 < v11 );
    v5 = v57;
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
    v32 = v58;
    while ( 1 )
    {
      if ( UFG::HavokNavManager::TesselateFace(this, v48[v30], v32, v31, 0) )
      {
        v33 = 0;
        size = this->m_aTesselationData.size;
        if ( size )
        {
          do
          {
            p = this->m_aTesselationData.p;
            x = p[v33].x;
            if ( x < aabbMin->x || x > v5->x || (v37 = p[v33].y, v37 < aabbMin->y) || v37 > v5->y )
            {
              y = p[size - 1].y;
              z = p[size - 1].z;
              p[v33].x = p[size - 1].x;
              p[v33].y = y;
              p[v33].z = z;
              v40 = this->m_aTesselationData.size;
              if ( v40 > 1 )
                this->m_aTesselationData.size = v40 - 1;
              else
                this->m_aTesselationData.size = 0;
            }
            else
            {
              ++v33;
            }
            size = this->m_aTesselationData.size;
          }
          while ( v33 < size );
        }
        v41 = this->m_aTesselationData.size;
        if ( v41 > 0 )
          break;
      }
      ++v29;
      ++v30;
      if ( v29 >= range )
        goto LABEL_42;
    }
    v42 = (unsigned int)UFG::qRandom(v41, &UFG::qDefaultSeed);
    v43 = this->m_aTesselationData.p;
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
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v48, 4 * v50);
  return v46;
}

// File Line: 1329
// RVA: 0xE7960
__int64 __fastcall UFG::HavokNavManager::AIRayCastHits(
        UFG::HavokNavManager *this,
        UFG::HavokNavPosition *positionStart,
        UFG::qVector3 *vEnd,
        UFG::NavParams *navParams,
        UFG::qVector3 *pCollisionPoint)
{
  __m128 x_low; // xmm3
  __m128 y_low; // xmm2
  __m128 z_low; // xmm0
  UFG::NavManagerVtbl *vfptr; // r10
  void **v10; // [rsp+30h] [rbp-48h] BYREF
  int v11; // [rsp+38h] [rbp-40h]
  int v12; // [rsp+3Ch] [rbp-3Ch]
  int v13; // [rsp+40h] [rbp-38h]
  char v14; // [rsp+48h] [rbp-30h]
  __m128 v15; // [rsp+50h] [rbp-28h]
  __int64 v16; // [rsp+60h] [rbp-18h]

  x_low = (__m128)LODWORD(vEnd->x);
  y_low = (__m128)LODWORD(vEnd->y);
  z_low = (__m128)LODWORD(vEnd->z);
  vfptr = this->vfptr;
  v10 = &UFG::HavokNavPosition::`vftable;
  v14 = 0;
  v11 = x_low.m128_i32[0];
  v12 = y_low.m128_i32[0];
  v13 = z_low.m128_i32[0];
  v16 = -1i64;
  v15 = _mm_unpacklo_ps(_mm_unpacklo_ps(x_low, z_low), _mm_unpacklo_ps(y_low, (__m128)(unsigned int)FLOAT_1_0));
  return ((__int64 (__fastcall *)(UFG::HavokNavManager *, UFG::HavokNavPosition *, void ***, UFG::NavParams *, UFG::qVector3 *))vfptr->AIRayCastHits)(
           this,
           positionStart,
           &v10,
           navParams,
           pCollisionPoint);
}

// File Line: 1336
// RVA: 0xE7280
bool __fastcall UFG::HavokNavManager::AIRayCastHits(
        UFG::HavokNavManager *this,
        UFG::HavokNavPosition *positionStart,
        UFG::HavokNavPosition *positionEnd,
        UFG::NavParams *navParams)
{
  UFG::NavParams *v4; // r14
  float m_fRadius; // xmm10_4
  float *v9; // rax
  bool result; // al
  __m128 m_quad; // xmm7
  unsigned int m_packedKey; // r12d
  __m128 y_low; // xmm2
  __m128 x_low; // xmm3
  float z; // xmm0_4
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
  __int64 v27; // rbx
  char v28; // dl
  char v29; // cl
  hkaiLineOfSightUtil::LineOfSightResult DirectPath; // r15d
  char v31; // cl
  __m128 v32; // xmm2
  __m128 v33; // xmm2
  __m128 v34; // xmm3
  __m128 v35; // xmm2
  unsigned int v36; // r8d
  unsigned int v37; // eax
  unsigned int v38; // ebx
  hkaiDynamicNavMeshQueryMediator *DynamicQueryMediator; // rax
  int v40; // r14d
  bool v41; // zf
  __m128 v42; // xmm0
  float v43; // xmm12_4
  unsigned int v44; // xmm4_4
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm2_4
  __m128 v48; // xmm3
  float v49; // xmm8_4
  float *v50; // rax
  float *v51; // rax
  float *v52; // rcx
  unsigned int v53; // [rsp+40h] [rbp-88h] BYREF
  float v54; // [rsp+44h] [rbp-84h]
  void **v55; // [rsp+48h] [rbp-80h]
  unsigned int v56; // [rsp+50h] [rbp-78h] BYREF
  float v57; // [rsp+54h] [rbp-74h]
  float v58; // [rsp+58h] [rbp-70h]
  unsigned int v59; // [rsp+60h] [rbp-68h] BYREF
  float v60; // [rsp+64h] [rbp-64h]
  _BYTE hkvPreviousPoint[24]; // [rsp+68h] [rbp-60h] BYREF
  hkVector4f hkvPosition; // [rsp+88h] [rbp-40h] BYREF
  hkVector4f hkvPoint; // [rsp+98h] [rbp-30h] BYREF
  __int64 v64; // [rsp+A8h] [rbp-20h]
  hkVector4f hkvNewPosition; // [rsp+B8h] [rbp-10h] BYREF
  hkaiLineOfSightUtil::DirectPathInput input; // [rsp+C8h] [rbp+0h] BYREF
  hkaiLineOfSightUtil::LineOfSightOutput output; // [rsp+128h] [rbp+60h] BYREF
  unsigned int v68; // [rsp+240h] [rbp+178h]
  UFG::NavParams *v69; // [rsp+250h] [rbp+188h]
  float *v70; // [rsp+258h] [rbp+190h]

  v64 = -2i64;
  v4 = navParams;
  m_fRadius = navParams->m_fRadius;
  positionStart->vfptr->GetMeshPosition(positionStart, (UFG::qVector3 *)&v53);
  v59 = v53;
  v60 = v54;
  *(_DWORD *)hkvPreviousPoint = (_DWORD)v55;
  if ( positionStart->vfptr->IsMeshPositionValid(positionStart) )
  {
    positionStart->vfptr->GetMeshPosition(positionStart, (UFG::qVector3 *)&v59);
    if ( hkaiWorld::getDynamicQueryMediator(this->m_world) )
    {
      m_quad = positionStart->m_hkvMeshPosition.m_quad;
      hkvPosition.m_quad = m_quad;
      m_packedKey = positionStart->m_packedKey;
      if ( positionEnd->vfptr->IsMeshPositionValid(positionEnd) )
      {
        positionEnd->vfptr->GetMeshPosition(positionEnd, (UFG::qVector3 *)&v56);
        y_low = (__m128)LODWORD(v57);
        x_low = (__m128)v56;
      }
      else
      {
        x_low = (__m128)LODWORD(positionEnd->m_vPosition.x);
        y_low = (__m128)LODWORD(positionEnd->m_vPosition.y);
        z = positionEnd->m_vPosition.z;
        v56 = LODWORD(positionEnd->m_vPosition.x);
        v57 = y_low.m128_f32[0];
        v58 = z;
      }
      v16 = 0;
      while ( 1 )
      {
        v17 = v54;
        v18 = (__m128)v53;
        v18.m128_f32[0] = (float)((float)(*(float *)&v53 - x_low.m128_f32[0])
                                * (float)(*(float *)&v53 - x_low.m128_f32[0]))
                        + (float)((float)(v54 - y_low.m128_f32[0]) * (float)(v54 - y_low.m128_f32[0]));
        v19 = _mm_sqrt_ps(v18).m128_f32[0];
        if ( v19 == 0.0 )
        {
          v51 = v70;
          if ( v70 )
          {
            *v70 = *(float *)&v53;
            v51[1] = v17;
            *((_DWORD *)v51 + 2) = (_DWORD)v55;
          }
          return 1;
        }
        v20 = (__m128)LODWORD(v58);
        v20.m128_f32[0] = v58 - *(float *)&v55;
        y_low.m128_f32[0] = y_low.m128_f32[0] - v54;
        x_low.m128_f32[0] = x_low.m128_f32[0] - *(float *)&v53;
        v21 = _mm_unpacklo_ps(_mm_unpacklo_ps(x_low, v20), _mm_unpacklo_ps(y_low, (__m128)0i64));
        hkaiLineOfSightUtil::DirectPathInput::DirectPathInput(&input);
        hkaiLineOfSightUtil::LineOfSightOutput::LineOfSightOutput(&output);
        input.m_startFaceKey = m_packedKey;
        input.m_startPoint.m_quad = m_quad;
        input.m_maxNumberOfIterations = 4096;
        input.m_up.m_quad = _xmm;
        input.m_agentInfo.m_diameter = m_fRadius * 2.0;
        input.m_agentInfo.m_filterInfo = v4->m_flags;
        v22 = _mm_mul_ps(v21, v21);
        v23 = _mm_add_ps(
                _mm_shuffle_ps(v22, v22, 170),
                _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)));
        v24 = _mm_rsqrt_ps(v23);
        v25.m_quad = _mm_mul_ps(
                       _mm_andnot_ps(
                         _mm_cmple_ps(v23, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
                           _mm_mul_ps(v24, *(__m128 *)_xmm))),
                       v21);
        input.m_direction = (hkVector4f)v25.m_quad;
        input.m_searchRadius = (float)(m_fRadius + 0.5) + v19;
        input.m_costModifier = &this->m_costModifier;
        v68 = 953267991;
        if ( (_mm_movemask_ps(_mm_cmpunord_ps(v25.m_quad, v25.m_quad)) & 7) != 0
          || (v26 = _mm_mul_ps(v25.m_quad, v25.m_quad),
              COERCE_FLOAT((unsigned int)(2
                                        * COERCE_INT(
                                            (float)(_mm_shuffle_ps(v26, v26, 170).m128_f32[0]
                                                  + (float)(_mm_shuffle_ps(v26, v26, 85).m128_f32[0]
                                                          + _mm_shuffle_ps(v26, v26, 0).m128_f32[0]))
                                          - 1.0)) >> 1) >= _mm_shuffle_ps((__m128)v68, (__m128)v68, 0).m128_f32[0]) )
        {
          v50 = v70;
          if ( v70 )
          {
            *v70 = *(float *)&v53;
            v50[1] = v54;
            *((_DWORD *)v50 + 2) = (_DWORD)v55;
          }
          hkaiLineOfSightUtil::LineOfSightOutput::~LineOfSightOutput(&output);
          return 1;
        }
        v27 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
        v28 = ++*(_BYTE *)(v27 + 80);
        *(_DWORD *)(v27 + 4i64 * v28) = 1;
        *(_QWORD *)(v27 + 8i64 * v28 + 16) = "AI::hkaiLineOfSightUtil::findDirectPath";
        *(_QWORD *)(v27 + 8i64 * v28 + 48) = 0i64;
        v29 = *(_BYTE *)(v27 + 81);
        if ( v28 > v29 )
          v29 = v28;
        *(_BYTE *)(v27 + 81) = v29;
        DirectPath = hkaiLineOfSightUtil::findDirectPath(this->m_world->m_streamingCollection.m_pntr, &input, &output);
        v31 = *(_BYTE *)(v27 + 80);
        if ( v31 > 0 )
        {
          *(_BYTE *)(v27 + 80) = v31 - 1;
        }
        else
        {
          *(_BYTE *)(v27 + 80) = 0;
          *(_DWORD *)v27 = 3;
          *(_QWORD *)(v27 + 16) = 0i64;
          *(_QWORD *)(v27 + 48) = 0i64;
        }
        *(hkVector4f *)&hkvPreviousPoint[8] = output.m_finalPoint;
        if ( v16 )
        {
          v16 = 0;
        }
        else if ( DirectPath == RESULT_HIT_BOUNDARY_EDGE )
        {
          v32 = _mm_sub_ps(m_quad, output.m_finalPoint.m_quad);
          v33 = _mm_mul_ps(v32, v32);
          if ( (float)(_mm_shuffle_ps(v33, v33, 170).m128_f32[0]
                     + (float)(_mm_shuffle_ps(v33, v33, 85).m128_f32[0] + _mm_shuffle_ps(v33, v33, 0).m128_f32[0])) < m_fRadius
            && UFG::HavokAIUtilGame::FindMeshPositionAwayFromWall(&hkvPosition, &hkvNewPosition, m_fRadius) )
          {
            m_quad = hkvNewPosition.m_quad;
            hkvPosition.m_quad = hkvNewPosition.m_quad;
            v53 = hkvNewPosition.m_quad.m128_u32[0];
            v34 = _mm_shuffle_ps(hkvNewPosition.m_quad, hkvNewPosition.m_quad, 85);
            v54 = v34.m128_f32[0];
            v35 = _mm_shuffle_ps(hkvNewPosition.m_quad, hkvNewPosition.m_quad, 170);
            v55 = &UFG::HavokNavPosition::`vftable;
            *(hkVector4f *)hkvPreviousPoint = positionStart->m_hkvMeshPosition;
            v36 = positionStart->m_packedKey;
            *(_DWORD *)&hkvPreviousPoint[16] = v36;
            *(_DWORD *)&hkvPreviousPoint[20] = -1;
            v56 = hkvNewPosition.m_quad.m128_u32[0];
            v57 = v34.m128_f32[0];
            v58 = v35.m128_f32[0];
            LOBYTE(v59) = 0;
            hkvPoint.m_quad = _mm_unpacklo_ps(
                                _mm_unpacklo_ps(hkvNewPosition.m_quad, v35),
                                _mm_unpacklo_ps(v34, (__m128)(unsigned int)FLOAT_1_0));
            v37 = v36 == -1
                ? UFG::HavokAIUtilGame::FindClosestMeshPosition2d(
                    &hkvPoint,
                    0.0099999998,
                    1.0,
                    (hkVector4f *)hkvPreviousPoint,
                    (unsigned int *)&hkvPreviousPoint[20])
                : UFG::HavokAIUtilGame::FindClosestMeshPosition2dCoherent(
                    &hkvPoint,
                    (hkVector4f *)hkvPreviousPoint,
                    v36,
                    0xFFFFFFFF,
                    0.0099999998,
                    1.0,
                    (hkVector4f *)hkvPreviousPoint,
                    (unsigned int *)&hkvPreviousPoint[20]);
            v38 = v37;
            if ( v37 != -1 )
            {
              DynamicQueryMediator = (hkaiDynamicNavMeshQueryMediator *)hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
              if ( DynamicQueryMediator )
              {
                v40 = *(_DWORD *)&hkvPreviousPoint[20];
                if ( UFG::HavokAIUtilGame::IsFaceKeyValid(
                       DynamicQueryMediator,
                       v38,
                       *(unsigned int *)&hkvPreviousPoint[20]) )
                {
                  v41 = v40 == -1;
                  v4 = v69;
                  if ( !v41 )
                  {
                    m_packedKey = v38;
                    v59 = v53;
                    v60 = v54;
                    *(_DWORD *)hkvPreviousPoint = (_DWORD)v55;
                    v16 = 1;
                  }
                }
                else
                {
                  v4 = v69;
                }
              }
            }
          }
        }
        hkaiLineOfSightUtil::LineOfSightOutput::~LineOfSightOutput(&output);
        if ( !v16 )
          break;
        y_low = (__m128)LODWORD(v57);
        x_low = (__m128)v56;
      }
      if ( DirectPath == RESULT_INVALID_INPUT )
        goto LABEL_48;
      v42 = (__m128)LODWORD(v54);
      v42.m128_f32[0] = (float)((float)(v54 - *(float *)&hkvPreviousPoint[12])
                              * (float)(v54 - *(float *)&hkvPreviousPoint[12]))
                      + (float)((float)(*(float *)&v53 - *(float *)&hkvPreviousPoint[8])
                              * (float)(*(float *)&v53 - *(float *)&hkvPreviousPoint[8]));
      LODWORD(v43) = _mm_sqrt_ps(v42).m128_u32[0];
      v44 = v56;
      v45 = v57;
      v48 = (__m128)LODWORD(v57);
      v46 = v58;
      v47 = v58 - *(float *)&v55;
      v48.m128_f32[0] = (float)((float)((float)(v57 - v54) * (float)(v57 - v54))
                              + (float)((float)(*(float *)&v56 - *(float *)&v53)
                                      * (float)(*(float *)&v56 - *(float *)&v53)))
                      + (float)(v47 * v47);
      if ( v48.m128_f32[0] == 0.0 )
        v49 = 0.0;
      else
        v49 = 1.0 / _mm_sqrt_ps(v48).m128_f32[0];
      if ( v43 >= (float)(v19 - 0.0099999998) && COERCE_FLOAT(COERCE_UNSIGNED_INT(v47 * v49) & _xmm) <= 0.70710677 )
      {
        result = 0;
        goto LABEL_50;
      }
      v44 = *(_DWORD *)&hkvPreviousPoint[8];
      v45 = *(float *)&hkvPreviousPoint[12];
      v46 = *(float *)&hkvPreviousPoint[16];
    }
    else
    {
LABEL_48:
      v46 = *(float *)hkvPreviousPoint;
      v45 = v60;
      v44 = v59;
    }
    result = 1;
LABEL_50:
    v52 = v70;
    if ( v70 )
    {
      *(_DWORD *)v70 = v44;
      v52[1] = v45;
      v52[2] = v46;
    }
  }
  else
  {
    v9 = v70;
    if ( v70 )
    {
      *v70 = *(float *)&v53;
      v9[1] = v54;
      *((_DWORD *)v9 + 2) = (_DWORD)v55;
    }
    return 1;
  }
  return result;
}

// File Line: 1572
// RVA: 0xEF940
void __fastcall UFG::HavokNavManager::LoadNavMesh(
        UFG::HavokNavManager *this,
        unsigned int meshUid,
        const char *meshName,
        hkPackfileSectionHeader *navmeshData,
        int navmeshSize,
        hkPackfileSectionHeader *mediatorTreeData,
        int mediatorTreeSize,
        hkPackfileSectionHeader *userEdgesData,
        int userEdgesSize)
{
  __int64 v10; // rbx
  char v11; // dl
  hkaiNavMeshInstance *v12; // rbp
  char v13; // cl
  char *v14; // rax
  UFG::NativePackfileUtils::Fixups *v15; // r15
  hkaiNavMesh *v16; // rdi
  char v17; // cl
  char v18; // dl
  char v19; // cl
  char *v20; // rax
  UFG::NativePackfileUtils::Fixups *v21; // r14
  char *v22; // rsi
  _QWORD **Value; // rax
  hkaiStaticTreeNavMeshQueryMediator *v24; // rax
  hkaiStaticTreeNavMeshQueryMediator *v25; // rax
  hkaiStaticTreeNavMeshQueryMediator *v26; // r12
  char v27; // al
  char v28; // r9
  char v29; // r8
  char *v30; // rax
  UFG::NativePackfileUtils::Fixups *v31; // rsi
  int v32; // r13d
  char v33; // cl
  char v34; // dl
  char v35; // cl
  _QWORD **v36; // rax
  hkaiNavMeshInstance *v37; // rax
  hkaiNavMeshInstance *v38; // rax
  unsigned int m_thisUid; // r8d
  char v40; // al
  char v41; // dl
  char v42; // cl
  char *v43; // rax
  UFG::HavokNavManager::MeshCell *v44; // rax
  UFG::HavokNavManager::MeshCell *v45; // rdi
  char v46; // al
  char v47; // dl
  char v48; // cl
  char v49; // al
  hkaiUserEdgePairArray *m_userEdges; // rax
  unsigned int m_sectionUid; // r9d
  unsigned int m_size; // ecx
  __int64 v53; // rdx
  __int64 v54; // r8
  hkaiUserEdgeUtils::UserEdgePair *m_data; // rcx
  char v56; // dl
  char v57; // cl
  char v58; // al
  hkaiUserEdgePairArray *userEdges; // [rsp+50h] [rbp-58h]

  UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_AIHavok, OUTPUT_LEVEL_DEBUG, "[AIHavok] LoadNavMesh(0x%x) (%s)...\n");
  v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v11 = ++*(_BYTE *)(v10 + 80);
  *(_DWORD *)(v10 + 4i64 * v11) = 1;
  *(_QWORD *)(v10 + 8i64 * v11 + 16) = "HavokNavManager";
  v12 = 0i64;
  *(_QWORD *)(v10 + 8i64 * v11 + 48) = 0i64;
  v13 = *(_BYTE *)(v10 + 81);
  if ( v11 > v13 )
    v13 = v11;
  *(_BYTE *)(v10 + 81) = v13;
  v14 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x20ui64, "NativePackfileUtils::meshFixups", 0i64, 1u);
  v15 = (UFG::NativePackfileUtils::Fixups *)v14;
  if ( v14 )
  {
    *(_QWORD *)v14 = 0i64;
    *((_DWORD *)v14 + 2) = 0;
    *((_DWORD *)v14 + 3) = 0x80000000;
    *((_QWORD *)v14 + 2) = 0i64;
    *((_DWORD *)v14 + 6) = 0;
    *((_DWORD *)v14 + 7) = 0x80000000;
  }
  else
  {
    v15 = 0i64;
  }
  v16 = (hkaiNavMesh *)UFG::NativePackfileUtils::loadInPlace(navmeshData, navmeshSize, v15);
  v17 = *(_BYTE *)(v10 + 80);
  if ( v17 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v17 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  v18 = ++*(_BYTE *)(v10 + 80);
  *(_DWORD *)(v10 + 4i64 * v18) = 1;
  *(_QWORD *)(v10 + 8i64 * v18 + 16) = "HavokNavManager";
  *(_QWORD *)(v10 + 8i64 * v18 + 48) = 1i64;
  v19 = *(_BYTE *)(v10 + 81);
  if ( v18 > v19 )
    v19 = v18;
  *(_BYTE *)(v10 + 81) = v19;
  v20 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x20ui64, "NativePackfileUtils::meshFixups", 0i64, 1u);
  v21 = (UFG::NativePackfileUtils::Fixups *)v20;
  if ( v20 )
  {
    *(_QWORD *)v20 = 0i64;
    *((_DWORD *)v20 + 2) = 0;
    *((_DWORD *)v20 + 3) = 0x80000000;
    *((_QWORD *)v20 + 2) = 0i64;
    *((_DWORD *)v20 + 6) = 0;
    *((_DWORD *)v20 + 7) = 0x80000000;
  }
  else
  {
    v21 = 0i64;
  }
  v22 = UFG::NativePackfileUtils::loadInPlace(mediatorTreeData, mediatorTreeSize, v21);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v24 = (hkaiStaticTreeNavMeshQueryMediator *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                Value[11],
                                                32i64);
  if ( v24 )
  {
    hkaiStaticTreeNavMeshQueryMediator::hkaiStaticTreeNavMeshQueryMediator(v24);
    v26 = v25;
  }
  else
  {
    v26 = 0i64;
  }
  hkaiStaticTreeNavMeshQueryMediator::setNavMeshAndTree(v26, v16, (hkcdStaticAabbTree *)v22);
  hkReferencedObject::removeReference((hkReferencedObject *)v22);
  v27 = *(_BYTE *)(v10 + 80);
  if ( v27 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v27 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  v28 = ++*(_BYTE *)(v10 + 80);
  *(_DWORD *)(v10 + 4i64 * v28) = 1;
  *(_QWORD *)(v10 + 8i64 * v28 + 16) = "HavokNavManager";
  *(_QWORD *)(v10 + 8i64 * v28 + 48) = 0i64;
  v29 = *(_BYTE *)(v10 + 81);
  if ( v28 > v29 )
    v29 = v28;
  *(_BYTE *)(v10 + 81) = v29;
  v30 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x20ui64, "NativePackfileUtils::edgesFixups", 0i64, 1u);
  v31 = (UFG::NativePackfileUtils::Fixups *)v30;
  if ( v30 )
  {
    *(_QWORD *)v30 = 0i64;
    *((_DWORD *)v30 + 2) = 0;
    *((_DWORD *)v30 + 3) = 0x80000000;
    *((_QWORD *)v30 + 2) = 0i64;
    *((_DWORD *)v30 + 6) = 0;
    *((_DWORD *)v30 + 7) = 0x80000000;
  }
  else
  {
    v31 = 0i64;
  }
  v32 = userEdgesSize;
  userEdges = (hkaiUserEdgePairArray *)UFG::NativePackfileUtils::loadInPlace(userEdgesData, userEdgesSize, v31);
  v33 = *(_BYTE *)(v10 + 80);
  if ( v33 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v33 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  if ( v16->m_userData != 1 )
  {
    v34 = ++*(_BYTE *)(v10 + 80);
    *(_DWORD *)(v10 + 4i64 * v34) = 1;
    *(_QWORD *)(v10 + 8i64 * v34 + 16) = "HavokNavManager";
    *(_QWORD *)(v10 + 8i64 * v34 + 48) = 0i64;
    v35 = *(_BYTE *)(v10 + 81);
    if ( v34 > v35 )
      v35 = v34;
    *(_BYTE *)(v10 + 81) = v35;
    v36 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v37 = (hkaiNavMeshInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v36[11] + 8i64))(v36[11], 480i64);
    if ( v37 )
    {
      hkaiNavMeshInstance::hkaiNavMeshInstance(v37);
      v12 = v38;
    }
    else
    {
      v12 = 0i64;
    }
    m_thisUid = meshUid;
    if ( v16->m_streamingSets.m_size > 0 )
      m_thisUid = v16->m_streamingSets.m_data->m_thisUid;
    hkaiNavMeshInstance::init(v12, v16, m_thisUid, 1);
    v40 = *(_BYTE *)(v10 + 80);
    if ( v40 > 0 )
    {
      *(_BYTE *)(v10 + 80) = v40 - 1;
    }
    else
    {
      *(_BYTE *)(v10 + 80) = 0;
      *(_DWORD *)v10 = 3;
      *(_QWORD *)(v10 + 16) = 0i64;
      *(_QWORD *)(v10 + 48) = 0i64;
    }
  }
  hkReferencedObject::addReference(v16);
  v41 = ++*(_BYTE *)(v10 + 80);
  *(_DWORD *)(v10 + 4i64 * v41) = 1;
  *(_QWORD *)(v10 + 8i64 * v41 + 16) = "AI::LoadNavMesh::MeshCell";
  *(_QWORD *)(v10 + 8i64 * v41 + 48) = 0i64;
  v42 = *(_BYTE *)(v10 + 81);
  if ( v41 > v42 )
    v42 = v41;
  *(_BYTE *)(v10 + 81) = v42;
  v43 = UFG::qMalloc(0xB0ui64, "AI::MeshCell", 0i64);
  if ( v43 )
  {
    UFG::HavokNavManager::MeshCell::MeshCell(
      (UFG::HavokNavManager::MeshCell *)v43,
      v16,
      v12,
      0i64,
      v26,
      userEdges,
      &v16->m_aabb,
      meshUid,
      0i64);
    v45 = v44;
  }
  else
  {
    v45 = 0i64;
  }
  v45->m_meshFixups = v15;
  v45->m_mediatorTreeFixups = v21;
  v45->m_edgesFixups = v31;
  v45->m_meshBuffer = navmeshData;
  v45->m_meshBufferSize = navmeshSize;
  v45->m_mediatorTreeBuffer = mediatorTreeData;
  v45->m_mediatorTreeBufferSize = mediatorTreeSize;
  v45->m_edgesBuffer = userEdgesData;
  v45->m_edgesBufferSize = v32;
  if ( this->m_cells.m_size == (this->m_cells.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_cells, 8);
  this->m_cells.m_data[this->m_cells.m_size++] = v45;
  v46 = *(_BYTE *)(v10 + 80);
  if ( v46 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v46 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  if ( v12 )
  {
    ((void (__fastcall *)(UFG::HavokNavManager *, _QWORD, hkaiNavMeshInstance *))this->vfptr[1].ExitGame)(
      this,
      0i64,
      v12);
    v47 = ++*(_BYTE *)(v10 + 80);
    *(_DWORD *)(v10 + 4i64 * v47) = 1;
    *(_QWORD *)(v10 + 8i64 * v47 + 16) = "HavokNavManager";
    *(_QWORD *)(v10 + 8i64 * v47 + 48) = 1i64;
    v48 = *(_BYTE *)(v10 + 81);
    if ( v47 > v48 )
      v48 = v47;
    *(_BYTE *)(v10 + 81) = v48;
    hkaiWorld::loadNavMeshInstance(this->m_world, v12, v26, 0i64);
    v49 = *(_BYTE *)(v10 + 80);
    if ( v49 > 0 )
    {
      *(_BYTE *)(v10 + 80) = v49 - 1;
    }
    else
    {
      *(_BYTE *)(v10 + 80) = 0;
      *(_DWORD *)v10 = 3;
      *(_QWORD *)(v10 + 16) = 0i64;
      *(_QWORD *)(v10 + 48) = 0i64;
    }
    m_userEdges = v45->m_userEdges;
    if ( m_userEdges )
    {
      m_sectionUid = v12->m_sectionUid;
      m_size = m_userEdges->m_edgePairs.m_size;
      if ( m_size )
      {
        v53 = 0i64;
        v54 = m_size;
        do
        {
          m_data = v45->m_userEdges->m_edgePairs.m_data;
          m_data[v53].m_instanceUidA = m_sectionUid;
          m_data[v53++].m_instanceUidB = m_sectionUid;
          --v54;
        }
        while ( v54 );
      }
      v56 = ++*(_BYTE *)(v10 + 80);
      *(_DWORD *)(v10 + 4i64 * v56) = 1;
      *(_QWORD *)(v10 + 8i64 * v56 + 16) = "HavokNavManager";
      *(_QWORD *)(v10 + 8i64 * v56 + 48) = 0i64;
      v57 = *(_BYTE *)(v10 + 81);
      if ( v56 > v57 )
        v57 = v56;
      *(_BYTE *)(v10 + 81) = v57;
      LOWORD(navmeshSize) = 256;
      BYTE2(navmeshSize) = 0;
      hkaiUserEdgeUtils::addUserEdgePairsBatch(
        this->m_world->m_streamingCollection.m_pntr,
        &v45->m_userEdges->m_edgePairs,
        (hkaiUserEdgeUtils::UpdateParameters *)&navmeshSize);
      v58 = *(_BYTE *)(v10 + 80);
      if ( v58 > 0 )
      {
        *(_BYTE *)(v10 + 80) = v58 - 1;
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
  UFG::HavokNavManager::Defrag(this, DefragVerbosity_Hide);
}

// File Line: 1725
// RVA: 0xF2360
void __fastcall UFG::HavokNavManager::UnloadNavMesh(UFG::HavokNavManager *this, unsigned int meshUid)
{
  unsigned int m_size; // ecx
  int v5; // ebp
  UFG::HavokNavManager::MeshCell **i; // r8
  __int64 v7; // r12
  UFG::HavokNavManager::MeshCell *v8; // rbx
  __int64 v9; // r15
  char v10; // dl
  char v11; // cl
  hkaiStreamingCollection *m_pntr; // rsi
  __int64 v13; // r10
  int v14; // ecx
  __int64 v15; // rdx
  hkaiNavMeshInstance **m_data; // rax
  int SectionIdByUid; // eax
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // r8
  UFG::NativePackfileUtils::Fixups *m_mediatorTreeFixups; // rsi
  UFG::NativePackfileUtils::Fixups *m_meshFixups; // rsi
  UFG::NativePackfileUtils::Fixups *m_edgesFixups; // rsi
  hkaiDirectedGraphExplicitCost *m_clusterGraph; // rcx
  hkaiNavMeshQueryMediator *m_mediator; // rcx
  __int64 v25; // rax
  char v26; // al
  UFG::NavComponent *v27; // rax

  m_size = this->m_cells.m_size;
  v5 = 0;
  if ( m_size )
  {
    for ( i = this->m_cells.m_data; (*i)->m_id != meshUid; ++i )
    {
      if ( ++v5 >= m_size )
        return;
    }
    v7 = v5;
    v8 = this->m_cells.m_data[v7];
    v9 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v10 = ++*(_BYTE *)(v9 + 80);
    *(_DWORD *)(v9 + 4i64 * v10) = 1;
    *(_QWORD *)(v9 + 8i64 * v10 + 16) = "AI::UnloadNavMesh";
    *(_QWORD *)(v9 + 8i64 * v10 + 48) = 0i64;
    v11 = *(_BYTE *)(v9 + 81);
    if ( v10 > v11 )
      v11 = v10;
    *(_BYTE *)(v9 + 81) = v11;
    if ( v8->m_Instances.m_size )
    {
      hkaiUserEdgeUtils::removeUserEdges(*v8->m_Instances.m_data, this->m_world->m_streamingCollection.m_pntr);
      m_pntr = this->m_world->m_streamingCollection.m_pntr;
      while ( v8->m_Instances.m_size )
      {
        v13 = this->m_StitchInstances.m_size;
        v14 = 0;
        v15 = 0i64;
        if ( (int)v13 > 0 )
        {
          m_data = this->m_StitchInstances.m_data;
          while ( *m_data != *v8->m_Instances.m_data )
          {
            ++v15;
            ++v14;
            ++m_data;
            if ( v15 >= v13 )
              goto LABEL_18;
          }
          if ( v15 != -1 )
          {
            this->m_StitchInstances.m_size = v13 - 1;
            if ( (_DWORD)v13 - 1 != v14 )
              this->m_StitchInstances.m_data[v15] = this->m_StitchInstances.m_data[(int)v13 - 1];
          }
        }
LABEL_18:
        SectionIdByUid = hkaiStreamingCollection::findSectionIdByUid(m_pntr, (*v8->m_Instances.m_data)->m_sectionUid);
        if ( SectionIdByUid != -1 )
        {
          if ( SectionIdByUid >= 0 )
            m_clusterGraphInstance = m_pntr->m_instances.m_data[SectionIdByUid].m_clusterGraphInstance;
          else
            m_clusterGraphInstance = 0i64;
          hkaiWorld::unloadNavMeshInstance(this->m_world, *v8->m_Instances.m_data, m_clusterGraphInstance);
        }
        hkReferencedObject::removeReference(*v8->m_Instances.m_data);
        if ( v8->m_Instances.m_size-- != 1 )
          *v8->m_Instances.m_data = v8->m_Instances.m_data[v8->m_Instances.m_size];
      }
    }
    m_mediatorTreeFixups = (UFG::NativePackfileUtils::Fixups *)v8->m_mediatorTreeFixups;
    UFG::NativePackfileUtils::unloadInPlace(
      (_DWORD *)v8->m_mediatorTreeBuffer,
      v8->m_mediatorTreeBufferSize,
      m_mediatorTreeFixups);
    if ( m_mediatorTreeFixups )
    {
      UFG::NativePackfileUtils::Fixups::~Fixups(m_mediatorTreeFixups);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, m_mediatorTreeFixups);
    }
    m_meshFixups = (UFG::NativePackfileUtils::Fixups *)v8->m_meshFixups;
    UFG::NativePackfileUtils::unloadInPlace(
      (_DWORD *)v8->m_meshBuffer,
      v8->m_meshBufferSize,
      (UFG::NativePackfileUtils::Fixups *)v8->m_meshFixups);
    if ( m_meshFixups )
    {
      UFG::NativePackfileUtils::Fixups::~Fixups(m_meshFixups);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, m_meshFixups);
    }
    m_edgesFixups = (UFG::NativePackfileUtils::Fixups *)v8->m_edgesFixups;
    UFG::NativePackfileUtils::unloadInPlace((_DWORD *)v8->m_edgesBuffer, v8->m_edgesBufferSize, m_edgesFixups);
    if ( m_edgesFixups )
    {
      UFG::NativePackfileUtils::Fixups::~Fixups(m_edgesFixups);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, m_edgesFixups);
    }
    m_clusterGraph = v8->m_clusterGraph;
    if ( m_clusterGraph )
      m_clusterGraph->vfptr->__vecDelDtor(m_clusterGraph, 1u);
    m_mediator = v8->m_mediator;
    if ( m_mediator )
      m_mediator->vfptr->__vecDelDtor(m_mediator, 1u);
    hkReferencedObject::removeReference(v8->m_mesh);
    UFG::HavokNavManager::MeshCell::~MeshCell(v8);
    operator delete[](v8);
    v25 = --this->m_cells.m_size;
    if ( (_DWORD)v25 != v5 )
      this->m_cells.m_data[v7] = this->m_cells.m_data[v25];
    v26 = *(_BYTE *)(v9 + 80);
    if ( v26 > 0 )
    {
      *(_BYTE *)(v9 + 80) = v26 - 1;
    }
    else
    {
      *(_BYTE *)(v9 + 80) = 0;
      *(_DWORD *)v9 = 3;
      *(_QWORD *)(v9 + 16) = 0i64;
      *(_QWORD *)(v9 + 48) = 0i64;
    }
    UFG::HavokNavManager::Defrag(this, DefragVerbosity_Hide);
    v27 = (UFG::NavComponent *)&UFG::NavComponent::s_NavComponentList.mNode.mNext[-4];
    for ( UFG::NavComponent::s_NavComponentpCurrentIterator = (UFG::NavComponent *)&UFG::NavComponent::s_NavComponentList.mNode.mNext[-4];
          v27 != (UFG::NavComponent *)(&UFG::NavComponent::s_NavComponentList - 4);
          UFG::NavComponent::s_NavComponentpCurrentIterator = v27 )
    {
      if ( v27->m_navPosition.m_aiMeshUid == meshUid )
      {
        v27->m_navPosition.vfptr->SetInvalidMeshPosition(&v27->m_navPosition);
        v27 = UFG::NavComponent::s_NavComponentpCurrentIterator;
      }
      v27 = (UFG::NavComponent *)&v27->mNext[-4];
    }
    UFG::NavComponent::s_NavComponentpCurrentIterator = 0i64;
  }
}

// File Line: 1847
// RVA: 0xF0FA0
void __fastcall UFG::HavokNavManager::SpawnNavMeshInstance(
        UFG::HavokNavManager *this,
        UFG::qMatrix44 *transform,
        unsigned int meshUid,
        unsigned int meshInstanceUid)
{
  UFG::HavokNavManager::MeshCell *LoadedCell; // r14
  __int64 v8; // rsi
  char v9; // dl
  int v10; // ebx
  char v11; // cl
  _QWORD **Value; // rax
  hkaiNavMeshInstance *v13; // rax
  hkaiNavMeshInstance *v14; // rax
  hkaiNavMeshInstance *v15; // rdi
  hkArray<hkaiNavMeshInstance *,hkContainerHeapAllocator> *p_m_Instances; // r14
  char v17; // al
  __int64 m_size; // r8
  __int64 v19; // rcx
  hkaiNavMeshInstance **m_data; // rax
  hkTransformf out; // [rsp+30h] [rbp-58h] BYREF

  LoadedCell = UFG::HavokNavManager::FindLoadedCell(this, meshUid);
  if ( LoadedCell )
  {
    v8 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v9 = ++*(_BYTE *)(v8 + 80);
    *(_DWORD *)(v8 + 4i64 * v9) = 1;
    *(_QWORD *)(v8 + 8i64 * v9 + 16) = "AI::SpawnNavMeshInstance";
    v10 = 0;
    *(_QWORD *)(v8 + 8i64 * v9 + 48) = 0i64;
    v11 = *(_BYTE *)(v8 + 81);
    if ( v9 > v11 )
      v11 = v9;
    *(_BYTE *)(v8 + 81) = v11;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v13 = (hkaiNavMeshInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 480i64);
    if ( v13 )
    {
      hkaiNavMeshInstance::hkaiNavMeshInstance(v13);
      v15 = v14;
    }
    else
    {
      v15 = 0i64;
    }
    hkaiNavMeshInstance::init(v15, LoadedCell->m_mesh, meshInstanceUid, 1);
    p_m_Instances = &LoadedCell->m_Instances;
    if ( p_m_Instances->m_size == (p_m_Instances->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_Instances, 8);
    p_m_Instances->m_data[p_m_Instances->m_size++] = v15;
    v17 = *(_BYTE *)(v8 + 80);
    if ( v17 > 0 )
    {
      *(_BYTE *)(v8 + 80) = v17 - 1;
    }
    else
    {
      *(_BYTE *)(v8 + 80) = 0;
      *(_DWORD *)v8 = 3;
      *(_QWORD *)(v8 + 16) = 0i64;
      *(_QWORD *)(v8 + 48) = 0i64;
    }
    UFG::qMatrix44_To_hkTransform(&out, transform);
    v15->m_referenceFrame.m_transform = out;
    m_size = this->m_StitchInstances.m_size;
    v19 = 0i64;
    if ( (int)m_size <= 0 )
      goto LABEL_18;
    m_data = this->m_StitchInstances.m_data;
    while ( *m_data != v15 )
    {
      ++v10;
      ++v19;
      ++m_data;
      if ( v19 >= m_size )
        goto LABEL_18;
    }
    if ( v10 == -1 )
    {
LABEL_18:
      if ( (_DWORD)m_size == (this->m_StitchInstances.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_StitchInstances, 8);
      this->m_StitchInstances.m_data[this->m_StitchInstances.m_size++] = v15;
      this->m_StitchingDelay = 100;
    }
  }
}

// File Line: 1875
// RVA: 0xE9AB0
void __fastcall UFG::HavokNavManager::DespawnNavMeshInstance(
        UFG::HavokNavManager *this,
        unsigned int meshUid,
        unsigned int meshInstanceUid)
{
  UFG::HavokNavManager::MeshCell *LoadedCell; // rax
  UFG::HavokNavManager::MeshCell *v6; // rbp
  __int64 m_size; // rdx
  int v8; // edi
  int v9; // esi
  __int64 v10; // rbx
  hkaiNavMeshInstance **i; // rcx
  hkaiStreamingCollection *m_pntr; // r13
  int SectionIdByUid; // eax
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // r8
  __int64 v15; // r9
  __int64 v16; // rcx
  hkaiNavMeshInstance **m_data; // rax
  __int64 v18; // rax

  LoadedCell = UFG::HavokNavManager::FindLoadedCell(this, meshUid);
  v6 = LoadedCell;
  if ( LoadedCell )
  {
    m_size = LoadedCell->m_Instances.m_size;
    v8 = 0;
    v9 = 0;
    v10 = 0i64;
    if ( m_size > 0 )
    {
      for ( i = LoadedCell->m_Instances.m_data; (*i)->m_sectionUid != meshInstanceUid; ++i )
      {
        ++v10;
        ++v9;
        if ( v10 >= m_size )
          return;
      }
      m_pntr = this->m_world->m_streamingCollection.m_pntr;
      SectionIdByUid = hkaiStreamingCollection::findSectionIdByUid(m_pntr, meshInstanceUid);
      if ( SectionIdByUid != -1 )
      {
        if ( SectionIdByUid >= 0 )
          m_clusterGraphInstance = m_pntr->m_instances.m_data[SectionIdByUid].m_clusterGraphInstance;
        else
          m_clusterGraphInstance = 0i64;
        hkaiWorld::unloadNavMeshInstance(this->m_world, v6->m_Instances.m_data[v9], m_clusterGraphInstance);
      }
      v15 = this->m_StitchInstances.m_size;
      v16 = 0i64;
      if ( (int)v15 > 0 )
      {
        m_data = this->m_StitchInstances.m_data;
        while ( *m_data != v6->m_Instances.m_data[v10] )
        {
          ++v16;
          ++v8;
          ++m_data;
          if ( v16 >= v15 )
            goto LABEL_20;
        }
        if ( v8 != -1 )
        {
          this->m_StitchInstances.m_size = v15 - 1;
          if ( (_DWORD)v15 - 1 != v8 )
            this->m_StitchInstances.m_data[v8] = this->m_StitchInstances.m_data[(int)v15 - 1];
        }
      }
LABEL_20:
      hkReferencedObject::removeReference(v6->m_Instances.m_data[v9]);
      v18 = --v6->m_Instances.m_size;
      if ( (_DWORD)v18 != v9 )
        v6->m_Instances.m_data[v9] = v6->m_Instances.m_data[v18];
    }
  }
}

// File Line: 1920
// RVA: 0xEAB50
UFG::HavokNavManager::MeshCell *__fastcall UFG::HavokNavManager::FindLoadedCell(
        UFG::HavokNavManager *this,
        unsigned int uniqueId)
{
  __int64 m_size; // rdi
  int v3; // ebx
  __int64 v4; // r11
  UFG::HavokNavManager::MeshCell **i; // r10
  UFG::HavokNavManager::MeshCell *v7; // rax
  __int64 v8; // r8
  __int64 v9; // rdx
  hkaiNavMeshInstance **m_data; // rax

  m_size = this->m_cells.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
    return 0i64;
  for ( i = this->m_cells.m_data; ; ++i )
  {
    v7 = *i;
    if ( (*i)->m_id == uniqueId )
      break;
    v8 = v7->m_Instances.m_size;
    v9 = 0i64;
    if ( v8 > 0 )
    {
      m_data = v7->m_Instances.m_data;
      while ( (*m_data)->m_sectionUid != uniqueId )
      {
        ++v9;
        ++m_data;
        if ( v9 >= v8 )
          goto LABEL_8;
      }
      return this->m_cells.m_data[v3];
    }
LABEL_8:
    ++v4;
    ++v3;
    if ( v4 >= m_size )
      return 0i64;
  }
  return this->m_cells.m_data[v3];
}

// File Line: 1940
// RVA: 0xF0010
void __fastcall UFG::HavokNavManager::PrintMeshInstances(UFG::HavokNavManager *this)
{
  int v2; // r13d
  __int64 v3; // r14
  UFG::HavokNavManager::MeshCell *v4; // rcx
  int v5; // eax
  int m_size; // edx
  __int64 v7; // rsi
  __int64 v8; // r12
  int v9; // r11d
  int v10; // edi
  UFG::HavokNavManager::MeshCell **m_data; // rbx
  int v12; // eax
  int v13; // r8d
  hkaiNavMeshInstance **v14; // rdx
  hkaiStreamingSet *v15; // rcx
  __int64 v16; // [rsp+20h] [rbp-68h]
  UFG::qString v17; // [rsp+38h] [rbp-50h] BYREF

  v2 = 0;
  if ( this->m_cells.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = this->m_cells.m_data[v3];
      v5 = 0;
      m_size = v4->m_Instances.m_size;
      if ( m_size > 0 )
      {
        do
          ++v5;
        while ( v5 < m_size );
      }
      if ( v4->m_mesh->m_streamingSets.m_size )
      {
        v7 = 0i64;
        v8 = (unsigned int)v4->m_mesh->m_streamingSets.m_size;
        do
        {
          UFG::qString::qString(&v17, "notFound");
          v9 = 0;
          v10 = this->m_cells.m_size;
          if ( v10 > 0 )
          {
            m_data = this->m_cells.m_data;
            while ( 1 )
            {
              v12 = 0;
              v13 = (*m_data)->m_Instances.m_size;
              if ( v13 > 0 )
                break;
LABEL_13:
              ++v9;
              ++m_data;
              if ( v9 >= v10 )
                goto LABEL_14;
            }
            v14 = (*m_data)->m_Instances.m_data;
            while ( (*v14)->m_sectionUid != this->m_cells.m_data[v3]->m_mesh->m_streamingSets.m_data[v7].m_oppositeUid )
            {
              ++v12;
              ++v14;
              if ( v12 >= v13 )
                goto LABEL_13;
            }
          }
LABEL_14:
          v15 = this->m_cells.m_data[v3]->m_mesh->m_streamingSets.m_data;
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
    while ( v2 < this->m_cells.m_size );
  }
}

// File Line: 1999
// RVA: 0xE8C30
void __fastcall UFG::HavokNavManager::CalculateStitches(
        UFG::HavokNavManager *this,
        bool stitchEverything,
        hkaiNavMeshInstance *stitchInstance)
{
  hkaiNavMeshInstance *v3; // r12
  unsigned __int64 Ticks; // rax
  int v6; // r9d
  __int64 v7; // rsi
  int v8; // r8d
  __int64 v9; // r14
  int v10; // edx
  __int64 v11; // rbx
  __int64 v12; // rdi
  int m_enum; // eax
  UFG::HavokNavManager::MeshCell **m_data; // rcx
  UFG::HavokNavManager::MeshCell *v15; // r15
  hkaiNavMeshInstance *v16; // r14
  UFG::HavokNavManager::MeshCell *v17; // r12
  hkaiNavMeshInstance *v18; // rsi
  __int64 m_size; // r9
  int v20; // edx
  __int64 v21; // rcx
  hkaiNavMeshInstance **v22; // rax
  int v23; // edx
  __int64 v24; // rcx
  hkaiNavMeshInstance **v25; // rax
  unsigned int m_sectionUid; // edi
  UFG::qBaseNodeRB *v27; // rbx
  unsigned int m_uidB; // edi
  UFG::qBaseNodeRB *v29; // rbx
  UFG::HavokNavManager::MeshCell **v30; // rdx
  int v31; // ecx
  __int64 v32; // rcx
  bool v33; // zf
  __int64 v34; // rcx
  hkVector4f v35; // xmm2
  hkVector4f v36; // xmm1
  hkVector4f v37; // xmm3
  hkVector4f v38; // xmm1
  hkVector4f v39; // xmm2
  hkVector4f v40; // xmm3
  __int64 v41; // r14
  char v42; // dl
  char v43; // cl
  int i; // ebx
  unsigned int v45; // eax
  __int64 v46; // rdi
  __int64 v47; // r15
  UFG::HavokNavManager::MeshCell *v48; // rcx
  unsigned int v49; // eax
  __int64 v50; // rbx
  __int64 v51; // rsi
  hkaiNavMeshInstance *v52; // rdx
  char v53; // al
  Render::SkinningCacheNode *Head; // rbx
  unsigned __int64 v55; // rax
  Render::SkinningCacheNode *v56; // rbx
  __int64 v57; // [rsp+30h] [rbp-D0h]
  __int64 v58; // [rsp+38h] [rbp-C8h]
  hkaiStreamingUtils::FindEdgeOverlapInput *array; // [rsp+40h] [rbp-C0h] BYREF
  int v60; // [rsp+48h] [rbp-B8h]
  int v61; // [rsp+4Ch] [rbp-B4h]
  int v62; // [rsp+50h] [rbp-B0h]
  int v63; // [rsp+54h] [rbp-ACh]
  __int64 v64; // [rsp+58h] [rbp-A8h]
  __int64 v65; // [rsp+60h] [rbp-A0h]
  __int64 v66; // [rsp+68h] [rbp-98h]
  UFG::qBaseTreeRB v67; // [rsp+70h] [rbp-90h] BYREF
  hkaiStreamingUtils::FindEdgeOverlapInput v68; // [rsp+C0h] [rbp-40h] BYREF
  __int64 v69; // [rsp+1D0h] [rbp+D0h]
  __int64 v70; // [rsp+1D8h] [rbp+D8h]
  hkAabb aabbOut; // [rsp+1E0h] [rbp+E0h] BYREF
  hkAabb v72; // [rsp+200h] [rbp+100h] BYREF
  hkResult result; // [rsp+270h] [rbp+170h]
  int v76; // [rsp+288h] [rbp+188h]

  v69 = -2i64;
  v3 = stitchInstance;
  Ticks = UFG::qGetTicks();
  UFG::qConvertTicksToMillisecs(Ticks);
  UFG::qBaseTreeRB::qBaseTreeRB(&v67);
  array = 0i64;
  v60 = 0;
  v61 = 0x80000000;
  v6 = 0;
  v62 = 0;
  v7 = 0i64;
  v57 = 0i64;
  if ( this->m_cells.m_size > 0 )
  {
    while ( 1 )
    {
      v8 = 0;
      v63 = 0;
      v9 = 0i64;
      v58 = 0i64;
      if ( this->m_cells.m_data[v7]->m_Instances.m_size <= 0 )
        goto LABEL_53;
      do
      {
        v10 = v6;
        v76 = v6;
        v11 = v7;
        v66 = v7;
        if ( v6 >= this->m_cells.m_size )
          goto LABEL_52;
        do
        {
          result.m_enum = HK_SUCCESS;
          v12 = 0i64;
          v64 = 0i64;
          if ( this->m_cells.m_data[v11]->m_Instances.m_size <= 0 )
            goto LABEL_50;
          m_enum = 0;
          do
          {
            if ( v7 != v11 || v9 != v12 )
            {
              hkaiStreamingUtils::FindEdgeOverlapInput::FindEdgeOverlapInput(&v68);
              m_data = this->m_cells.m_data;
              v15 = m_data[v7];
              v16 = v15->m_Instances.m_data[v9];
              v17 = m_data[v11];
              v18 = v17->m_Instances.m_data[v12];
              if ( v16 && v18 )
              {
                if ( stitchEverything )
                  goto LABEL_27;
                if ( stitchInstance )
                {
                  if ( v16 == stitchInstance || v18 == stitchInstance )
                    goto LABEL_27;
                }
                else
                {
                  m_size = this->m_StitchInstances.m_size;
                  v20 = 0;
                  v21 = 0i64;
                  if ( (int)m_size <= 0 )
                    goto LABEL_21;
                  v22 = this->m_StitchInstances.m_data;
                  while ( *v22 != v16 )
                  {
                    ++v20;
                    ++v21;
                    ++v22;
                    if ( v21 >= m_size )
                      goto LABEL_21;
                  }
                  if ( v20 == -1 )
                  {
LABEL_21:
                    v23 = 0;
                    v24 = 0i64;
                    if ( (int)m_size <= 0 )
                      goto LABEL_47;
                    v25 = this->m_StitchInstances.m_data;
                    while ( *v25 != v18 )
                    {
                      ++v23;
                      ++v24;
                      ++v25;
                      if ( v24 >= m_size )
                        goto LABEL_47;
                    }
                    if ( v23 == -1 )
                      goto LABEL_47;
                  }
LABEL_27:
                  if ( v15->m_mesh->m_userData == 1 || v17->m_mesh->m_userData == 1 )
                  {
                    hkaiNavMeshInstance::getAabb(v16, &aabbOut);
                    hkaiNavMeshInstance::getAabb(v18, &v72);
                    if ( (_mm_movemask_ps(
                            _mm_and_ps(
                              _mm_cmple_ps(v72.m_min.m_quad, aabbOut.m_max.m_quad),
                              _mm_cmple_ps(aabbOut.m_min.m_quad, v72.m_max.m_quad))) & 7) == 7 )
                    {
                      m_sectionUid = v16->m_sectionUid;
                      v68.m_uidA = m_sectionUid;
                      v68.m_uidB = v18->m_sectionUid;
                      if ( !m_sectionUid
                        || (v27 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::Get(&v67, m_sectionUid)) == 0i64 )
                      {
                        v27 = (UFG::qBaseNodeRB *)UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
                        v65 = (__int64)v27;
                        if ( v27 )
                        {
                          v27->mParent = 0i64;
                          v27->mChild[0] = 0i64;
                          v27->mChild[1] = 0i64;
                          v27->mUID = m_sectionUid;
                          v27[1].mParent = (UFG::qBaseNodeRB *)v15;
                        }
                        else
                        {
                          v27 = 0i64;
                        }
                        UFG::qBaseTreeRB::Add(&v67, v27);
                      }
                      v27[1].mParent = (UFG::qBaseNodeRB *)v15;
                      m_uidB = v68.m_uidB;
                      if ( !v68.m_uidB || (v29 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::Get(&v67, v68.m_uidB)) == 0i64 )
                      {
                        v29 = (UFG::qBaseNodeRB *)UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
                        v65 = (__int64)v29;
                        if ( v29 )
                        {
                          v29->mParent = 0i64;
                          v29->mChild[0] = 0i64;
                          v29->mChild[1] = 0i64;
                          v29->mUID = m_uidB;
                          v29[1].mParent = (UFG::qBaseNodeRB *)v17;
                        }
                        else
                        {
                          v29 = 0i64;
                        }
                        UFG::qBaseTreeRB::Add(&v67, v29);
                      }
                      v29[1].mParent = (UFG::qBaseNodeRB *)v17;
                      v68.m_meshA = v16->m_originalMesh.m_pntr;
                      v68.m_meshB = v18->m_originalMesh.m_pntr;
                      v30 = this->m_cells.m_data;
                      v68.m_mediatorA = v30[v57]->m_mediator;
                      v11 = v66;
                      v68.m_mediatorB = v30[v66]->m_mediator;
                      v68.m_transformA = v16->m_referenceFrame.m_transform;
                      v68.m_transformB = v18->m_referenceFrame.m_transform;
                      v68.m_graphA = 0i64;
                      v68.m_graphB = 0i64;
                      v68.m_edgeMatchTolerance = 0.2;
                      v68.m_edgeMatchingParams.m_maxOverhang = 0.2;
                      v68.m_edgeMatchingParams.m_maxStepHeight = 0.2;
                      v68.m_edgeMatchingParams.m_maxSeparation = 0.2;
                      v68.m_edgeMatchingParams.m_behindFaceTolerance = 0.2;
                      v68.m_edgeMatchingParams.m_minEdgeOverlap = 0.0;
                      v31 = v60;
                      if ( v60 == (v61 & 0x3FFFFFFF) )
                      {
                        hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 272);
                        v31 = v60;
                      }
                      v32 = v31;
                      v33 = &array[v32] == 0i64;
                      v34 = (__int64)&array[v32];
                      v65 = v34;
                      v70 = v34;
                      if ( !v33 )
                      {
                        *(_QWORD *)v34 = v68.m_meshA;
                        *(_QWORD *)(v34 + 8) = v68.m_meshB;
                        *(_DWORD *)(v34 + 16) = v68.m_uidA;
                        *(_DWORD *)(v34 + 20) = v68.m_uidB;
                        *(_QWORD *)(v34 + 24) = v68.m_mediatorA;
                        *(_QWORD *)(v34 + 32) = v68.m_mediatorB;
                        *(_QWORD *)(v34 + 40) = v68.m_graphA;
                        *(_QWORD *)(v34 + 48) = v68.m_graphB;
                        *(float *)(v34 + 56) = v68.m_edgeMatchTolerance;
                        *(hkVector4f *)(v34 + 64) = v68.m_up;
                        *(hkaiNavMeshEdgeMatchingParameters *)(v34 + 80) = v68.m_edgeMatchingParams;
                        v35.m_quad = (__m128)v68.m_transformA.m_rotation.m_col1;
                        v36.m_quad = (__m128)v68.m_transformA.m_rotation.m_col2;
                        v37.m_quad = (__m128)v68.m_transformA.m_translation;
                        *(hkVector4f *)(v34 + 144) = v68.m_transformA.m_rotation.m_col0;
                        *(hkVector4f *)(v34 + 160) = (hkVector4f)v35.m_quad;
                        *(hkVector4f *)(v34 + 176) = (hkVector4f)v36.m_quad;
                        *(hkVector4f *)(v34 + 192) = (hkVector4f)v37.m_quad;
                        v38.m_quad = (__m128)v68.m_transformB.m_rotation.m_col1;
                        v39.m_quad = (__m128)v68.m_transformB.m_rotation.m_col2;
                        v40.m_quad = (__m128)v68.m_transformB.m_translation;
                        *(hkVector4f *)(v34 + 208) = v68.m_transformB.m_rotation.m_col0;
                        *(hkVector4f *)(v34 + 224) = (hkVector4f)v38.m_quad;
                        *(hkVector4f *)(v34 + 240) = (hkVector4f)v39.m_quad;
                        *(hkVector4f *)(v34 + 256) = (hkVector4f)v40.m_quad;
                      }
                      ++v60;
                      v12 = v64;
                    }
                  }
                }
              }
LABEL_47:
              m_enum = result.m_enum;
              v7 = v57;
              v9 = v58;
            }
            result.m_enum = m_enum + 1;
            v64 = ++v12;
            ++m_enum;
          }
          while ( m_enum < this->m_cells.m_data[v11]->m_Instances.m_size );
          v10 = v76;
LABEL_50:
          v76 = ++v10;
          v66 = ++v11;
        }
        while ( v10 < this->m_cells.m_size );
        v8 = v63;
        v6 = v62;
LABEL_52:
        v63 = ++v8;
        v58 = ++v9;
      }
      while ( v8 < this->m_cells.m_data[v7]->m_Instances.m_size );
LABEL_53:
      v62 = ++v6;
      v57 = ++v7;
      if ( v6 >= this->m_cells.m_size )
      {
        v3 = stitchInstance;
        break;
      }
    }
  }
  v41 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v42 = ++*(_BYTE *)(v41 + 80);
  *(_DWORD *)(v41 + 4i64 * v42) = 1;
  *(_QWORD *)(v41 + 8i64 * v42 + 16) = "AI::CalculateStitches";
  *(_QWORD *)(v41 + 8i64 * v42 + 48) = 0i64;
  v43 = *(_BYTE *)(v41 + 81);
  if ( v42 > v43 )
    v43 = v42;
  *(_BYTE *)(v41 + 81) = v43;
  for ( i = 0; i < v60; ++i )
    hkaiStreamingUtils::generateStreamingInfo(&array[i]);
  if ( !v3 )
  {
    v45 = this->m_cells.m_size;
    if ( v45 )
    {
      v46 = 0i64;
      v47 = v45;
      do
      {
        v48 = this->m_cells.m_data[v46];
        if ( v48->m_mesh->m_userData == 1 )
        {
          v49 = v48->m_Instances.m_size;
          if ( v49 )
          {
            v50 = 0i64;
            v51 = v49;
            do
            {
              if ( hkaiStreamingCollection::findSectionIdByUid(
                     this->m_world->m_streamingCollection.m_pntr,
                     this->m_cells.m_data[v46]->m_Instances.m_data[v50]->m_sectionUid) == -1 )
              {
                hkaiWorld::loadNavMeshInstance(
                  this->m_world,
                  this->m_cells.m_data[v46]->m_Instances.m_data[v50],
                  this->m_cells.m_data[v46]->m_mediator,
                  0i64);
                v52 = this->m_cells.m_data[v46]->m_Instances.m_data[v50];
                hkaiStreamingCollection::setSectionTransform(
                  this->m_world->m_streamingCollection.m_pntr,
                  v52,
                  &v52->m_referenceFrame.m_transform);
              }
              ++v50;
              --v51;
            }
            while ( v51 );
          }
        }
        ++v46;
        --v47;
      }
      while ( v47 );
    }
  }
  hkaiStreamingCollection::validate(this->m_world->m_streamingCollection.m_pntr, 1, 1);
  v53 = *(_BYTE *)(v41 + 80);
  if ( v53 > 0 )
  {
    *(_BYTE *)(v41 + 80) = v53 - 1;
  }
  else
  {
    *(_BYTE *)(v41 + 80) = 0;
    *(_DWORD *)v41 = 3;
    *(_QWORD *)(v41 + 16) = 0i64;
    *(_QWORD *)(v41 + 48) = 0i64;
  }
  while ( v67.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v67);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)&v67, &Head->mNode);
    operator delete[](Head);
  }
  if ( !v3 )
    this->m_StitchInstances.m_size = 0;
  v55 = UFG::qGetTicks();
  UFG::qConvertTicksToMillisecs(v55);
  v60 = 0;
  if ( v61 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array,
      272 * (v61 & 0x3FFFFFFF));
  array = 0i64;
  v61 = 0x80000000;
  while ( v67.mCount )
  {
    v56 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v67);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)&v67, &v56->mNode);
    operator delete[](v56);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v67);
}

// File Line: 2207
// RVA: 0xE7D40
UFG::HavokNavDynamicOutline *__fastcall UFG::HavokNavManager::AddDynamicOutline(
        UFG::HavokNavManager *this,
        UFG::qMatrix44 *transform,
        UFG::qVector3 *aabbMin,
        UFG::qVector3 *aabbMax,
        UFG::DynamicUserEdgeInfo *edgesInfo,
        unsigned int edgesCount)
{
  __int64 v10; // rsi
  char v11; // r10
  unsigned int v12; // ebx
  char v13; // cl
  char *v14; // rax
  UFG::HavokNavDynamicOutline *v15; // rax
  UFG::HavokNavDynamicOutline *v16; // rbp
  __int64 size; // r15
  unsigned int v18; // edi
  unsigned int capacity; // eax
  char v20; // al

  v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v11 = ++*(_BYTE *)(v10 + 80);
  v12 = 1;
  *(_DWORD *)(v10 + 4i64 * v11) = 1;
  *(_QWORD *)(v10 + 8i64 * v11 + 16) = "AI::HavokNavManager::AddDynamicOutline";
  *(_QWORD *)(v10 + 8i64 * v11 + 48) = 0i64;
  v13 = *(_BYTE *)(v10 + 81);
  if ( v11 > v13 )
    v13 = v11;
  *(_BYTE *)(v10 + 81) = v13;
  v14 = UFG::qMalloc(0x80ui64, "HavokNavDynamicOutline", 0i64);
  if ( v14 )
  {
    UFG::HavokNavDynamicOutline::HavokNavDynamicOutline(
      (UFG::HavokNavDynamicOutline *)v14,
      transform,
      aabbMin,
      aabbMax,
      edgesInfo,
      edgesCount);
    v16 = v15;
  }
  else
  {
    v16 = 0i64;
  }
  size = this->m_dynamicOutlinesAdditionQueue.size;
  v18 = size + 1;
  capacity = this->m_dynamicOutlinesAdditionQueue.capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v12 = 2 * capacity;
    for ( ; v12 < v18; v12 *= 2 )
      ;
    if ( v12 <= 2 )
      v12 = 2;
    if ( v12 - v18 > 0x10000 )
      v12 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_dynamicOutlinesAdditionQueue,
      v12,
      "qArray.Add");
  }
  this->m_dynamicOutlinesAdditionQueue.size = v18;
  this->m_dynamicOutlinesAdditionQueue.p[size] = v16;
  v20 = *(_BYTE *)(v10 + 80);
  if ( v20 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v20 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  return v16;
}

// File Line: 2221
// RVA: 0xF07F0
char __fastcall UFG::HavokNavManager::RemoveDynamicOutline(
        UFG::HavokNavManager *this,
        UFG::HavokNavDynamicOutline *outline)
{
  unsigned int size; // ecx
  unsigned int v5; // r8d
  UFG::HavokNavDynamicOutline **p; // rax
  unsigned int v7; // r9d
  int v8; // r8d
  UFG::HavokNavDynamicOutline **i; // rax
  char result; // al
  __int64 v11; // r14
  char v12; // dl
  char v13; // cl
  unsigned int v14; // eax
  char v15; // al
  unsigned int v16; // edi
  __int64 v17; // r14
  char v18; // dl
  char v19; // cl
  unsigned int v20; // eax
  __int64 v21; // r13
  unsigned int capacity; // eax
  unsigned int v23; // ebp
  unsigned __int64 v24; // rax
  char *v25; // rax
  UFG::HavokNavDynamicOutline **v26; // r15
  unsigned int j; // r9d
  __int64 v28; // rcx
  UFG::HavokNavDynamicOutline **v29; // rax
  char v30; // al

  size = this->m_dynamicOutlinesAdditionQueue.size;
  v5 = 0;
  if ( size )
  {
    p = this->m_dynamicOutlinesAdditionQueue.p;
    while ( *p != outline )
    {
      ++v5;
      ++p;
      if ( v5 >= size )
        goto LABEL_5;
    }
    v11 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v12 = ++*(_BYTE *)(v11 + 80);
    *(_DWORD *)(v11 + 4i64 * v12) = 1;
    *(_QWORD *)(v11 + 8i64 * v12 + 16) = "AI::HavokNavManager::RemoveFromAdditionQueue";
    *(_QWORD *)(v11 + 8i64 * v12 + 48) = 0i64;
    v13 = *(_BYTE *)(v11 + 81);
    if ( v12 > v13 )
      v13 = v12;
    *(_BYTE *)(v11 + 81) = v13;
    this->m_dynamicOutlinesAdditionQueue.p[v5] = this->m_dynamicOutlinesAdditionQueue.p[this->m_dynamicOutlinesAdditionQueue.size
                                                                                      - 1];
    v14 = this->m_dynamicOutlinesAdditionQueue.size;
    if ( v14 > 1 )
      this->m_dynamicOutlinesAdditionQueue.size = v14 - 1;
    else
      this->m_dynamicOutlinesAdditionQueue.size = 0;
    if ( outline )
      outline->vfptr->__vecDelDtor(outline, 1i64);
    v15 = *(_BYTE *)(v11 + 80);
    if ( v15 > 0 )
    {
      *(_BYTE *)(v11 + 80) = v15 - 1;
      return 1;
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
    v7 = this->m_dynamicOutlines.size;
    v8 = 0;
    if ( v7 )
    {
      for ( i = this->m_dynamicOutlines.p; *i != outline; ++i )
      {
        if ( ++v8 >= v7 )
          return 0;
      }
      v16 = 1;
      v17 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
      v18 = ++*(_BYTE *)(v17 + 80);
      *(_DWORD *)(v17 + 4i64 * v18) = 1;
      *(_QWORD *)(v17 + 8i64 * v18 + 16) = "AI::HavokNavManager::RemoveDynamicOutline";
      *(_QWORD *)(v17 + 8i64 * v18 + 48) = 0i64;
      v19 = *(_BYTE *)(v17 + 81);
      if ( v18 > v19 )
        v19 = v18;
      *(_BYTE *)(v17 + 81) = v19;
      this->m_dynamicOutlines.p[v8] = this->m_dynamicOutlines.p[v7 - 1];
      v20 = this->m_dynamicOutlines.size;
      if ( v20 > 1 )
        this->m_dynamicOutlines.size = v20 - 1;
      else
        this->m_dynamicOutlines.size = 0;
      v21 = this->m_dynamicOutlinesDeletionQueue.size;
      capacity = this->m_dynamicOutlinesDeletionQueue.capacity;
      v23 = v21 + 1;
      if ( (int)v21 + 1 > capacity )
      {
        if ( capacity )
          v16 = 2 * capacity;
        for ( ; v16 < v23; v16 *= 2 )
          ;
        if ( v16 <= 2 )
          v16 = 2;
        if ( v16 - v23 > 0x10000 )
          v16 = v21 + 65537;
        if ( v16 != (_DWORD)v21 )
        {
          v24 = 8i64 * v16;
          if ( !is_mul_ok(v16, 8ui64) )
            v24 = -1i64;
          v25 = UFG::qMalloc(v24, "qArray.Add", 0i64);
          v26 = (UFG::HavokNavDynamicOutline **)v25;
          if ( this->m_dynamicOutlinesDeletionQueue.p )
          {
            for ( j = 0;
                  j < this->m_dynamicOutlinesDeletionQueue.size;
                  *(_QWORD *)&v25[8 * v28] = this->m_dynamicOutlinesDeletionQueue.p[v28] )
            {
              v28 = j++;
            }
            operator delete[](this->m_dynamicOutlinesDeletionQueue.p);
          }
          this->m_dynamicOutlinesDeletionQueue.p = v26;
          this->m_dynamicOutlinesDeletionQueue.capacity = v16;
        }
      }
      v29 = this->m_dynamicOutlinesDeletionQueue.p;
      this->m_dynamicOutlinesDeletionQueue.size = v23;
      v29[v21] = outline;
      v30 = *(_BYTE *)(v17 + 80);
      if ( v30 > 0 )
      {
        *(_BYTE *)(v17 + 80) = v30 - 1;
        return 1;
      }
      else
      {
        *(_BYTE *)(v17 + 80) = 0;
        result = 1;
        *(_DWORD *)v17 = 3;
        *(_QWORD *)(v17 + 16) = 0i64;
        *(_QWORD *)(v17 + 48) = 0i64;
      }
    }
    else
    {
      return 0;
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
void __fastcall UFG::HavokNavManager::MeshCell::MeshCell(
        UFG::HavokNavManager::MeshCell *this,
        hkaiNavMesh *mesh,
        hkaiNavMeshInstance *instance,
        hkaiDirectedGraphExplicitCost *cost,
        hkaiNavMeshQueryMediator *mediator,
        hkaiUserEdgePairArray *userEdges,
        hkAabb *aabb,
        unsigned int id,
        struct UFG::HavokNavManager::MeshCellDebugStrings *debugStrings)
{
  hkArray<hkaiNavMeshInstance *,hkContainerHeapAllocator> *p_m_Instances; // rbx

  this->m_meshFixups = 0i64;
  this->m_edgesFixups = 0i64;
  this->m_mesh = mesh;
  this->m_clusterGraph = cost;
  this->m_mediator = mediator;
  this->m_userEdges = userEdges;
  this->m_aabb = *aabb;
  this->m_id = id;
  this->m_meshBuffer = 0i64;
  this->m_meshBufferSize = -1;
  this->m_mediatorTreeBuffer = 0i64;
  this->m_mediatorTreeBufferSize = -1;
  this->m_edgesBuffer = 0i64;
  this->m_edgesBufferSize = -1;
  p_m_Instances = &this->m_Instances;
  this->m_Instances.m_data = 0i64;
  this->m_Instances.m_size = 0;
  this->m_Instances.m_capacityAndFlags = 0x80000000;
  this->m_debugStrings = debugStrings;
  if ( instance )
  {
    if ( this->m_Instances.m_size == (this->m_Instances.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_Instances, 8);
    p_m_Instances->m_data[this->m_Instances.m_size++] = instance;
  }
}


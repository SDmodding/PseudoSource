// File Line: 47
// RVA: 0xBCD270
void __fastcall hkaiWorld::Cinfo::Cinfo(hkaiWorld::Cinfo *this)
{
  *(_WORD *)&this->m_clearanceResetMethod.m_storage = 256;
  this->m_silhouetteExtrusion = 1.5;
  this->m_bevelThreshold = 0.40000001;
  this->m_maxSilhouetteSize = 50.0;
  this->m_simplify2dConvexHullThreshold = 0.0049999999;
  this->m_maxCutFacesPerStep = -1;
  this->m_avoidancePairProps = 0i64;
  this->m_maxRequestsPerStep = 100;
  this->m_maxEstimatedIterationsPerStep = -1;
  this->m_priorityThreshold = 1024;
  this->m_numPathRequestsPerJob = 16;
  this->m_numBehaviorUpdatesPerJob = 16;
  this->m_numCharactersPerAvoidanceJob = 16;
  this->m_maxPathSearchEdgesOut = 64;
  this->m_maxPathSearchPointsOut = 32;
  *(_WORD *)&this->m_fallbackToOldCutter.m_bool = 0;
  hkaiPathfindingUtil::FindPathInput::FindPathInput(&this->m_pathfindingInput, 0);
  hkaiVolumePathfindingUtil::FindPathInput::FindPathInput(&this->m_volumePathfindingInput, 0);
  this->m_up.m_quad = _xmm;
  this->m_pathfindingInput.m_searchParameters.m_useHierarchicalHeuristic.m_bool = 1;
}

// File Line: 54
// RVA: 0xBCD330
void __fastcall hkaiWorld::hkaiWorld(hkaiWorld *this, hkaiWorld::Cinfo *cInfo)
{
  hkaiDynamicNavVolumeMediator *v2; // rdi
  hkaiAvoidancePairProperties *m_avoidancePairProps; // rbp
  hkaiAvoidancePairProperties *m_pntr; // rcx
  int m_maxPathSearchPointsOut; // eax
  _QWORD **Value; // rax
  hkaiStreamingCollection *v9; // rax
  hkaiStreamingCollection *v10; // rax
  hkaiStreamingCollection *v11; // rbp
  hkaiStreamingCollection *v12; // rcx
  _QWORD **v13; // rax
  hkaiNavMeshCutter *v14; // rax
  hkaiNavMeshCutter *v15; // rax
  hkaiNavMeshCutter *v16; // rbp
  hkaiNavMeshCutter *v17; // rcx
  char m_bool; // al
  hkaiNavMeshCutter *v19; // rcx
  __m128i si128; // xmm4
  __m128 v21; // xmm3
  __m128 v22; // xmm4
  float m_maxSilhouetteSize; // eax
  float m_erosionRadius; // eax
  _QWORD **v25; // rax
  hkaiOverlapManager *v26; // rax
  hkaiOverlapManager *v27; // rax
  hkaiOverlapManager *v28; // rbp
  hkaiOverlapManager *v29; // rcx
  _QWORD **v30; // rax
  hkaiDynamicNavMeshQueryMediator *v31; // rax
  hkaiDynamicNavMeshQueryMediator *v32; // rax
  hkaiDynamicNavMeshQueryMediator *v33; // rsi
  hkaiDynamicNavMeshQueryMediator *v34; // rcx
  _QWORD **v35; // rax
  hkaiDynamicNavVolumeMediator *v36; // rax
  hkaiDynamicNavVolumeMediator *v37; // rax
  hkaiDynamicNavVolumeMediator *v38; // rcx
  hkaiReferenceFrameAndExtrusion referenceAxis; // [rsp+20h] [rbp-48h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiWorld::`vftable;
  this->m_streamingCollection.m_pntr = 0i64;
  this->m_cutter.m_pntr = 0i64;
  this->m_dynamicNavMeshMediator.m_pntr = 0i64;
  this->m_dynamicNavVolumeMediator.m_pntr = 0i64;
  this->m_overlapManager.m_pntr = 0i64;
  this->m_silhouetteGenerationParameters.m_referenceFrame.m_up = 0i64;
  this->m_silhouetteGenerationParameters.m_referenceFrame.m_referenceAxis = 0i64;
  this->m_silhouetteGenerationParameters.m_extraExpansion = 0.0;
  this->m_silhouetteGenerationParameters.m_bevelThreshold = 0.40000001;
  this->m_silhouetteGenerationParameters.m_simplify2dConvexHullThreshold = 0.0049999999;
  this->m_silhouetteGenerationParameters.m_maxSilhouetteSize = 50.0;
  this->m_listeners.m_data = 0i64;
  this->m_listeners.m_size = 0;
  this->m_listeners.m_capacityAndFlags = 0x80000000;
  this->m_silhouetteGenerators.m_data = 0i64;
  this->m_silhouetteGenerators.m_size = 0;
  this->m_silhouetteGenerators.m_capacityAndFlags = 0x80000000;
  this->m_obstacleGenerators.m_data = 0i64;
  this->m_obstacleGenerators.m_size = 0;
  this->m_obstacleGenerators.m_capacityAndFlags = 0x80000000;
  this->m_avoidancePairProps.m_pntr = 0i64;
  this->m_navMeshPathRequests.m_data = 0i64;
  this->m_navMeshPathRequests.m_size = 0;
  this->m_navMeshPathRequests.m_capacityAndFlags = 0x80000000;
  this->m_navVolumePathRequests.m_data = 0i64;
  this->m_navVolumePathRequests.m_size = 0;
  this->m_navVolumePathRequests.m_capacityAndFlags = 0x80000000;
  hkaiPathfindingUtil::FindPathInput::FindPathInput(&this->m_defaultPathfindingInput, 0);
  hkaiVolumePathfindingUtil::FindPathInput::FindPathInput(&this->m_defaultVolumePathfindingInput, 0);
  this->m_up = cInfo->m_up;
  this->m_performValidationChecks.m_bool = cInfo->m_performValidationChecks.m_bool;
  this->m_silhouetteExtrusion = cInfo->m_silhouetteExtrusion;
  this->m_forceSilhouetteUpdates.m_bool = 0;
  m_avoidancePairProps = cInfo->m_avoidancePairProps;
  if ( m_avoidancePairProps )
    hkReferencedObject::addReference(cInfo->m_avoidancePairProps);
  m_pntr = this->m_avoidancePairProps.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_avoidancePairProps.m_pntr = m_avoidancePairProps;
  this->m_maxRequestsPerStep = cInfo->m_maxRequestsPerStep;
  this->m_maxEstimatedIterationsPerStep = cInfo->m_maxEstimatedIterationsPerStep;
  this->m_priorityThreshold = cInfo->m_priorityThreshold;
  this->m_numPathRequestsPerJob = cInfo->m_numPathRequestsPerJob;
  this->m_numBehaviorUpdatesPerJob = cInfo->m_numBehaviorUpdatesPerJob;
  this->m_numCharactersPerAvoidanceJob = cInfo->m_numCharactersPerAvoidanceJob;
  this->m_maxPathSearchEdgesOut = cInfo->m_maxPathSearchEdgesOut;
  m_maxPathSearchPointsOut = cInfo->m_maxPathSearchPointsOut;
  this->m_erosionRadius = 0.0;
  this->m_maxPathSearchPointsOut = m_maxPathSearchPointsOut;
  this->m_precomputeNavMeshClearance.m_bool = cInfo->m_precomputeNavMeshClearance.m_bool;
  this->m_isPathRequestArrayLocked.m_bool = 0;
  hkaiPathfindingUtil::FindPathInput::operator=(&this->m_defaultPathfindingInput, &cInfo->m_pathfindingInput);
  hkaiVolumePathfindingUtil::FindPathInput::operator=(
    &this->m_defaultVolumePathfindingInput,
    &cInfo->m_volumePathfindingInput);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkaiStreamingCollection *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  if ( v9 )
  {
    hkaiStreamingCollection::hkaiStreamingCollection(v9);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = this->m_streamingCollection.m_pntr;
  if ( v12 && v12 != v11 )
    hkReferencedObject::removeReference(v12);
  this->m_streamingCollection.m_pntr = v11;
  v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (hkaiNavMeshCutter *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v13[11] + 8i64))(v13[11], 192i64);
  if ( v14 )
  {
    hkaiNavMeshCutter::hkaiNavMeshCutter(v14);
    v16 = v15;
  }
  else
  {
    v16 = 0i64;
  }
  v17 = this->m_cutter.m_pntr;
  if ( v17 && v17 != v16 )
    hkReferencedObject::removeReference(v17);
  this->m_cutter.m_pntr = v16;
  hkaiNavMeshCutter::init(v16, &this->m_up, this->m_streamingCollection.m_pntr);
  m_bool = this->m_performValidationChecks.m_bool;
  v19 = this->m_cutter.m_pntr;
  referenceAxis.m_up = 0i64;
  v19->m_performValidationChecks.m_bool = m_bool;
  this->m_cutter.m_pntr->m_clearanceResetMethod.m_storage = cInfo->m_clearanceResetMethod.m_storage;
  this->m_cutter.m_pntr->m_useNewCutter.m_bool = cInfo->m_fallbackToOldCutter.m_bool == 0;
  this->m_cutter.m_pntr->m_recomputeClearanceAfterCutting.m_bool = this->m_precomputeNavMeshClearance.m_bool;
  si128 = _mm_load_si128((const __m128i *)&this->m_up);
  v21 = (__m128)_mm_srli_epi32(_mm_slli_epi32(si128, 1u), 1u);
  referenceAxis.m_up.m_quad.m128_i32[((unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                                             _mm_and_ps(
                                                                                               _mm_cmple_ps(
                                                                                                 _mm_max_ps(
                                                                                                   _mm_shuffle_ps(
                                                                                                     v21,
                                                                                                     v21,
                                                                                                     170),
                                                                                                   _mm_max_ps(
                                                                                                     _mm_shuffle_ps(v21, v21, 85),
                                                                                                     _mm_shuffle_ps(v21, v21, 0))),
                                                                                                 v21),
                                                                                               (__m128)xmmword_141A5C140))]
                                    + 2)
                                   % 3] = 1065353216;
  v22 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)si128, (__m128)si128, 201), referenceAxis.m_up.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(referenceAxis.m_up.m_quad, referenceAxis.m_up.m_quad, 201), (__m128)si128));
  referenceAxis.m_up.m_quad = _mm_shuffle_ps(v22, v22, 201);
  hkaiSilhouetteReferenceFrame::set(
    &this->m_silhouetteGenerationParameters.m_referenceFrame,
    &this->m_up,
    &referenceAxis.m_up);
  this->m_silhouetteGenerationParameters.m_bevelThreshold = cInfo->m_bevelThreshold;
  m_maxSilhouetteSize = cInfo->m_maxSilhouetteSize;
  referenceAxis.m_up = 0i64;
  this->m_silhouetteGenerationParameters.m_maxSilhouetteSize = m_maxSilhouetteSize;
  this->m_silhouetteGenerationParameters.m_simplify2dConvexHullThreshold = cInfo->m_simplify2dConvexHullThreshold;
  m_erosionRadius = this->m_erosionRadius;
  referenceAxis.m_cellExtrusion = -1.0;
  this->m_silhouetteGenerationParameters.m_extraExpansion = m_erosionRadius;
  referenceAxis.m_silhouetteRadiusExpasion = -1.0;
  hkaiWorld::setupReferenceFrame(this, &referenceAxis);
  v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v26 = (hkaiOverlapManager *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v25[11] + 8i64))(v25[11], 128i64);
  if ( v26 )
  {
    hkaiOverlapManager::hkaiOverlapManager(v26, this->m_streamingCollection.m_pntr, &referenceAxis);
    v28 = v27;
  }
  else
  {
    v28 = 0i64;
  }
  v29 = this->m_overlapManager.m_pntr;
  if ( v29 && v29 != v28 )
    hkReferencedObject::removeReference(v29);
  this->m_overlapManager.m_pntr = v28;
  v28->m_maxCutFacesPerStep = cInfo->m_maxCutFacesPerStep;
  hkaiStreamingCollection::setupTree(this->m_streamingCollection.m_pntr);
  v30 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v31 = (hkaiDynamicNavMeshQueryMediator *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v30[11] + 8i64))(
                                             v30[11],
                                             48i64);
  if ( v31 )
  {
    hkaiDynamicNavMeshQueryMediator::hkaiDynamicNavMeshQueryMediator(
      v31,
      this->m_streamingCollection.m_pntr,
      this->m_streamingCollection.m_pntr->m_tree.m_pntr,
      this->m_cutter.m_pntr);
    v33 = v32;
  }
  else
  {
    v33 = 0i64;
  }
  v34 = this->m_dynamicNavMeshMediator.m_pntr;
  if ( v34 && v34 != v33 )
    hkReferencedObject::removeReference(v34);
  this->m_dynamicNavMeshMediator.m_pntr = v33;
  v35 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v36 = (hkaiDynamicNavVolumeMediator *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v35[11] + 8i64))(v35[11], 32i64);
  if ( v36 )
  {
    hkaiDynamicNavVolumeMediator::hkaiDynamicNavVolumeMediator(
      v36,
      this->m_streamingCollection.m_pntr,
      this->m_streamingCollection.m_pntr->m_tree.m_pntr);
    v2 = v37;
  }
  v38 = this->m_dynamicNavVolumeMediator.m_pntr;
  if ( v38 && v38 != v2 )
    hkReferencedObject::removeReference(v38);
  this->m_dynamicNavVolumeMediator.m_pntr = v2;
}

// File Line: 138
// RVA: 0xBCD7F0
void __fastcall hkaiWorld::hkaiWorld(hkaiWorld *this, hkFinishLoadedObjectFlag f)
{
  hkaiPathfindingUtil::FindPathInput *p_m_defaultPathfindingInput; // rcx

  p_m_defaultPathfindingInput = &this->m_defaultPathfindingInput;
  p_m_defaultPathfindingInput[-2].m_searchParameters.m_costModifier = (hkaiAstarCostModifier *)&hkaiWorld::`vftable;
  p_m_defaultPathfindingInput[-1].m_goalFaceKeys.m_capacityAndFlags = 0x80000000;
  p_m_defaultPathfindingInput[-1].m_goalFaceKeys.m_data = 0i64;
  p_m_defaultPathfindingInput[-1].m_goalFaceKeys.m_size = 0;
  *(_QWORD *)&p_m_defaultPathfindingInput[-1].m_searchParameters.m_validateInputs.m_bool = 0i64;
  p_m_defaultPathfindingInput[-1].m_searchParameters.m_heuristicWeight = 0.0;
  p_m_defaultPathfindingInput[-1].m_searchParameters.m_simpleRadiusThreshold = -0.0;
  *(_QWORD *)&p_m_defaultPathfindingInput[-1].m_searchParameters.m_maximumPathLength = 0i64;
  p_m_defaultPathfindingInput[-1].m_searchParameters.m_searchCapsuleRadius = 0.0;
  p_m_defaultPathfindingInput[-1].m_searchParameters.m_bufferSizes.m_maxOpenSetSizeBytes = 0x80000000;
  hkaiPathfindingUtil::FindPathInput::FindPathInput(p_m_defaultPathfindingInput, f);
  hkaiVolumePathfindingUtil::FindPathInput::FindPathInput(&this->m_defaultVolumePathfindingInput, f);
}

// File Line: 143
// RVA: 0xBCD870
void __fastcall hkaiWorld::~hkaiWorld(hkaiWorld *this)
{
  int v1; // edi
  int i; // edi
  int v4; // eax
  __int64 j; // rdi
  hkaiWorld::Listener *v6; // rcx
  int v7; // edi
  hkaiNavVolumePathRequestInfo *v8; // rsi
  hkaiNavVolumePathRequestInfo *v9; // rbp
  int m_capacityAndFlags; // r8d
  int v11; // edi
  hkaiNavMeshPathRequestInfo *v12; // rsi
  hkaiNavMeshPathRequestInfo *v13; // rbp
  int v14; // r8d
  hkaiAvoidancePairProperties *m_pntr; // rcx
  hkRefPtr<hkaiObstacleGenerator> *m_data; // rsi
  int v17; // eax
  __int64 k; // rdi
  hkReferencedObject *v19; // rcx
  int v20; // r8d
  hkRefPtr<hkaiSilhouetteGenerator> *v21; // rsi
  int v22; // eax
  __int64 m; // rdi
  hkReferencedObject *v24; // rcx
  int v25; // r8d
  int v26; // r8d
  hkaiOverlapManager *v27; // rcx
  hkaiDynamicNavVolumeMediator *v28; // rcx
  hkaiDynamicNavMeshQueryMediator *v29; // rcx
  hkaiNavMeshCutter *v30; // rcx
  hkaiStreamingCollection *v31; // rcx

  v1 = this->m_navMeshPathRequests.m_size - 1;
  for ( this->vfptr = (hkBaseObjectVtbl *)&hkaiWorld::`vftable; v1 >= 0; --v1 )
    hkaiWorld::_deleteNavMeshPathRequestAt(this, v1);
  for ( i = this->m_navVolumePathRequests.m_size - 1; i >= 0; --i )
    hkaiWorld::_deleteNavVolumePathRequestAt(this, i);
  v4 = this->m_listeners.m_size - 1;
  for ( j = v4; j >= 0; --j )
  {
    v6 = this->m_listeners.m_data[j];
    v6->vfptr->worldDeletedCallback(v6, this);
  }
  hkaiVolumePathfindingUtil::FindPathInput::~FindPathInput(&this->m_defaultVolumePathfindingInput);
  hkaiPathfindingUtil::FindPathInput::~FindPathInput(&this->m_defaultPathfindingInput);
  v7 = this->m_navVolumePathRequests.m_size - 1;
  if ( v7 >= 0 )
  {
    v8 = &this->m_navVolumePathRequests.m_data[v7];
    v9 = v8;
    do
    {
      v8->vfptr->__vecDelDtor(v9--, 0i64);
      --v7;
      --v8;
    }
    while ( v7 >= 0 );
  }
  m_capacityAndFlags = this->m_navVolumePathRequests.m_capacityAndFlags;
  this->m_navVolumePathRequests.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_navVolumePathRequests.m_data,
      56 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_navVolumePathRequests.m_data = 0i64;
  this->m_navVolumePathRequests.m_capacityAndFlags = 0x80000000;
  v11 = this->m_navMeshPathRequests.m_size - 1;
  if ( v11 >= 0 )
  {
    v12 = &this->m_navMeshPathRequests.m_data[v11];
    v13 = v12;
    do
    {
      v12->vfptr->__vecDelDtor(v13--, 0i64);
      --v11;
      --v12;
    }
    while ( v11 >= 0 );
  }
  v14 = this->m_navMeshPathRequests.m_capacityAndFlags;
  this->m_navMeshPathRequests.m_size = 0;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_navMeshPathRequests.m_data,
      56 * (v14 & 0x3FFFFFFF));
  this->m_navMeshPathRequests.m_data = 0i64;
  this->m_navMeshPathRequests.m_capacityAndFlags = 0x80000000;
  m_pntr = this->m_avoidancePairProps.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_avoidancePairProps.m_pntr = 0i64;
  m_data = this->m_obstacleGenerators.m_data;
  v17 = this->m_obstacleGenerators.m_size - 1;
  for ( k = v17; k >= 0; m_data[k--].m_pntr = 0i64 )
  {
    v19 = m_data[k].m_pntr;
    if ( v19 )
      hkReferencedObject::removeReference(v19);
  }
  v20 = this->m_obstacleGenerators.m_capacityAndFlags;
  this->m_obstacleGenerators.m_size = 0;
  if ( v20 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_obstacleGenerators.m_data,
      8 * v20);
  this->m_obstacleGenerators.m_data = 0i64;
  this->m_obstacleGenerators.m_capacityAndFlags = 0x80000000;
  v21 = this->m_silhouetteGenerators.m_data;
  v22 = this->m_silhouetteGenerators.m_size - 1;
  for ( m = v22; m >= 0; v21[m--].m_pntr = 0i64 )
  {
    v24 = v21[m].m_pntr;
    if ( v24 )
      hkReferencedObject::removeReference(v24);
  }
  v25 = this->m_silhouetteGenerators.m_capacityAndFlags;
  this->m_silhouetteGenerators.m_size = 0;
  if ( v25 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_silhouetteGenerators.m_data,
      8 * v25);
  this->m_silhouetteGenerators.m_data = 0i64;
  this->m_silhouetteGenerators.m_capacityAndFlags = 0x80000000;
  v26 = this->m_listeners.m_capacityAndFlags;
  this->m_listeners.m_size = 0;
  if ( v26 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_listeners.m_data,
      8 * v26);
  this->m_listeners.m_data = 0i64;
  this->m_listeners.m_capacityAndFlags = 0x80000000;
  v27 = this->m_overlapManager.m_pntr;
  if ( v27 )
    hkReferencedObject::removeReference(v27);
  this->m_overlapManager.m_pntr = 0i64;
  v28 = this->m_dynamicNavVolumeMediator.m_pntr;
  if ( v28 )
    hkReferencedObject::removeReference(v28);
  this->m_dynamicNavVolumeMediator.m_pntr = 0i64;
  v29 = this->m_dynamicNavMeshMediator.m_pntr;
  if ( v29 )
    hkReferencedObject::removeReference(v29);
  this->m_dynamicNavMeshMediator.m_pntr = 0i64;
  v30 = this->m_cutter.m_pntr;
  if ( v30 )
    hkReferencedObject::removeReference(v30);
  this->m_cutter.m_pntr = 0i64;
  v31 = this->m_streamingCollection.m_pntr;
  if ( v31 )
    hkReferencedObject::removeReference(v31);
  this->m_streamingCollection.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 162
// RVA: 0xBCDCB0
void __fastcall hkaiWorld::setNavMesh(
        hkaiWorld *this,
        hkaiNavMesh *navMesh,
        hkaiNavMeshQueryMediator *mediator,
        hkaiDirectedGraphExplicitCost *hierarchyInfo,
        bool setupClearanceInfo)
{
  _QWORD **Value; // rax
  hkaiNavMeshInstance *v10; // rax
  hkaiDirectedGraphInstance *v11; // rbx
  hkaiNavMeshInstance *v12; // rax
  hkaiNavMeshInstance *v13; // rdi
  _QWORD **v14; // rax
  hkaiDirectedGraphInstance *v15; // rax
  hkaiDirectedGraphInstance *v16; // rax
  float m_erosionRadius; // xmm0_4

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkaiNavMeshInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 480i64);
  v11 = 0i64;
  if ( v10 )
  {
    hkaiNavMeshInstance::hkaiNavMeshInstance(v10);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  hkaiNavMeshInstance::init(v13, navMesh, 0, setupClearanceInfo);
  if ( hierarchyInfo )
  {
    v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (hkaiDirectedGraphInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v14[11] + 8i64))(v14[11], 272i64);
    if ( v15 )
    {
      hkaiDirectedGraphInstance::hkaiDirectedGraphInstance(v15);
      v11 = v16;
    }
    hkaiDirectedGraphInstance::init(v11, hierarchyInfo, 0);
  }
  m_erosionRadius = v13->m_originalMesh.m_pntr->m_erosionRadius;
  this->m_erosionRadius = m_erosionRadius;
  this->m_silhouetteGenerationParameters.m_extraExpansion = m_erosionRadius;
  hkaiWorld::loadNavMeshInstance(this, v13, mediator, v11);
  if ( v11 )
    hkReferencedObject::removeReference(v11);
  hkReferencedObject::removeReference(v13);
}

// File Line: 191
// RVA: 0xBCDDF0
void __fastcall hkaiWorld::loadNavMeshInstance(
        hkaiWorld *this,
        hkaiNavMeshInstance *navMeshInstance,
        hkaiNavMeshQueryMediator *mediator,
        hkaiDirectedGraphInstance *hierarchyGraphInstance)
{
  int v4; // esi
  __int64 v9; // r14

  v4 = 0;
  if ( this->m_listeners.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      this->m_listeners.m_data[v9]->vfptr->navMeshInstanceAdded(
        this->m_listeners.m_data[v9],
        this,
        navMeshInstance,
        mediator,
        hierarchyGraphInstance);
      ++v4;
      ++v9;
    }
    while ( v4 < this->m_listeners.m_size );
  }
  if ( navMeshInstance->m_clearanceCache.m_size > 0 || navMeshInstance->m_globalClearanceCache.m_size > 0 )
  {
    hkaiNavMeshInstance::initClearanceCache(navMeshInstance);
    hkaiNavMeshInstance::resetVertexClearances(navMeshInstance);
  }
  hkaiStreamingCollection::addInstance(
    this->m_streamingCollection.m_pntr,
    navMeshInstance,
    mediator,
    hierarchyGraphInstance);
  hkaiOverlapManager::loadSection(
    this->m_overlapManager.m_pntr,
    navMeshInstance->m_runtimeId,
    &this->m_silhouetteGenerators);
  hkaiNavMeshCutter::initSection(this->m_cutter.m_pntr, navMeshInstance->m_runtimeId, navMeshInstance, 1);
  if ( this->m_precomputeNavMeshClearance.m_bool )
    hkaiNavMeshCutter::recomputeDirtyGlobalClearances(this->m_cutter.m_pntr, navMeshInstance);
}

// File Line: 239
// RVA: 0xBCDF00
void __fastcall hkaiWorld::unloadNavMeshInstance(
        hkaiWorld *this,
        hkaiNavMeshInstance *navMeshInstance,
        hkaiDirectedGraphInstance *hierarchyGraphInstance)
{
  int v3; // edi
  __int64 v7; // rsi

  v3 = 0;
  if ( this->m_listeners.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      this->m_listeners.m_data[v7]->vfptr->navMeshInstanceRemoved(
        this->m_listeners.m_data[v7],
        this,
        navMeshInstance,
        hierarchyGraphInstance);
      ++v3;
      ++v7;
    }
    while ( v3 < this->m_listeners.m_size );
  }
  hkaiNavMeshCutter::uncutSection(this->m_cutter.m_pntr, navMeshInstance->m_runtimeId, 1);
  hkaiOverlapManager::unloadSection(this->m_overlapManager.m_pntr, navMeshInstance->m_runtimeId);
  hkaiStreamingCollection::removeInstance(this->m_streamingCollection.m_pntr, navMeshInstance, hierarchyGraphInstance);
}

// File Line: 269
// RVA: 0xBCDFB0
void __fastcall hkaiWorld::loadNavMeshGraph(hkaiWorld *this, hkaiDirectedGraphInstance *graphInstance)
{
  int v2; // edi
  __int64 v5; // rsi

  v2 = 0;
  if ( this->m_listeners.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      this->m_listeners.m_data[v5]->vfptr->graphAdded(this->m_listeners.m_data[v5], this, graphInstance);
      ++v2;
      ++v5;
    }
    while ( v2 < this->m_listeners.m_size );
  }
  hkaiStreamingCollection::addMeshGraph(this->m_streamingCollection.m_pntr, graphInstance);
}

// File Line: 280
// RVA: 0xBCE030
void __fastcall hkaiWorld::unloadNavMeshGraph(hkaiWorld *this, hkaiDirectedGraphInstance *graphInstance)
{
  int v2; // edi
  __int64 v5; // rsi

  v2 = 0;
  if ( this->m_listeners.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      this->m_listeners.m_data[v5]->vfptr->graphRemoved(this->m_listeners.m_data[v5], this, graphInstance);
      ++v2;
      ++v5;
    }
    while ( v2 < this->m_listeners.m_size );
  }
  hkaiStreamingCollection::removeMeshGraph(this->m_streamingCollection.m_pntr, graphInstance);
}

// File Line: 300
// RVA: 0xBCE0B0
void __fastcall hkaiWorld::loadNavVolume(
        hkaiWorld *this,
        hkaiNavVolumeInstance *navVolume,
        hkaiNavVolumeMediator *mediator)
{
  int v3; // edi
  __int64 v7; // rsi

  v3 = 0;
  if ( this->m_listeners.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      this->m_listeners.m_data[v7]->vfptr->navVolumeAdded(this->m_listeners.m_data[v7], this, navVolume, mediator);
      ++v3;
      ++v7;
    }
    while ( v3 < this->m_listeners.m_size );
  }
  hkaiStreamingCollection::addVolume(this->m_streamingCollection.m_pntr, navVolume, mediator);
}

// File Line: 320
// RVA: 0xBCE140
void __fastcall hkaiWorld::unloadNavVolume(hkaiWorld *this, hkaiNavVolumeInstance *navVolume)
{
  int v2; // esi
  __int64 v5; // r14

  v2 = 0;
  if ( this->m_listeners.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      this->m_listeners.m_data[v5]->vfptr->navVolumeRemoved(this->m_listeners.m_data[v5], this, navVolume);
      ++v2;
      ++v5;
    }
    while ( v2 < this->m_listeners.m_size );
  }
  if ( navVolume )
    hkReferencedObject::addReference(navVolume);
  hkaiStreamingCollection::removeVolume(this->m_streamingCollection.m_pntr, navVolume);
  if ( navVolume )
    hkReferencedObject::removeReference(navVolume);
}

// File Line: 341
// RVA: 0xBCE2A0
void __fastcall hkaiWorld::shiftWorldSpace(hkaiWorld *this, hkVector4f *shift)
{
  hkaiStreamingCollection *m_pntr; // rdi
  int v3; // ebp
  int v6; // r14d
  __int64 v7; // rsi
  hkaiNavMeshInstance *m_instancePtr; // rdx
  hkVector4f v9; // xmm1
  hkVector4f v10; // xmm0
  __m128 m_quad; // xmm1
  hkaiNavVolumeInstance *m_volumeInstancePtr; // rdx
  int v13; // edi
  __int64 v14; // rsi
  __int64 v15; // rdi
  hkVector4f translation; // [rsp+20h] [rbp-68h] BYREF
  hkTransformf transform; // [rsp+30h] [rbp-58h] BYREF

  m_pntr = this->m_streamingCollection.m_pntr;
  v3 = 0;
  v6 = 0;
  if ( m_pntr->m_instances.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      m_instancePtr = m_pntr->m_instances.m_data[v7].m_instancePtr;
      if ( m_instancePtr )
      {
        v9.m_quad = (__m128)m_instancePtr->m_referenceFrame.m_transform.m_rotation.m_col1;
        transform.m_rotation.m_col0 = m_instancePtr->m_referenceFrame.m_transform.m_rotation.m_col0;
        v10.m_quad = (__m128)m_instancePtr->m_referenceFrame.m_transform.m_rotation.m_col2;
        transform.m_rotation.m_col1 = (hkVector4f)v9.m_quad;
        m_quad = m_instancePtr->m_referenceFrame.m_transform.m_translation.m_quad;
        transform.m_rotation.m_col2 = (hkVector4f)v10.m_quad;
        transform.m_translation.m_quad = _mm_add_ps(shift->m_quad, m_quad);
        hkaiStreamingCollection::setSectionTransform(m_pntr, m_instancePtr, &transform);
      }
      m_volumeInstancePtr = m_pntr->m_instances.m_data[v7].m_volumeInstancePtr;
      if ( m_volumeInstancePtr )
      {
        translation.m_quad = _mm_add_ps(shift->m_quad, m_volumeInstancePtr->m_translation.m_quad);
        hkaiStreamingCollection::setVolumeTranslation(m_pntr, m_volumeInstancePtr, &translation);
      }
      ++v6;
      ++v7;
    }
    while ( v6 < m_pntr->m_instances.m_size );
  }
  v13 = 0;
  if ( this->m_silhouetteGenerators.m_size > 0 )
  {
    v14 = 0i64;
    do
    {
      ((void (__fastcall *)(hkaiSilhouetteGenerator *, hkVector4f *))this->m_silhouetteGenerators.m_data[v14].m_pntr->vfptr[5].__first_virtual_table_function__)(
        this->m_silhouetteGenerators.m_data[v14].m_pntr,
        shift);
      ++v13;
      ++v14;
    }
    while ( v13 < this->m_silhouetteGenerators.m_size );
  }
  if ( this->m_obstacleGenerators.m_size > 0 )
  {
    v15 = 0i64;
    do
    {
      this->m_obstacleGenerators.m_data[v15].m_pntr->vfptr[3].__vecDelDtor(
        this->m_obstacleGenerators.m_data[v15].m_pntr,
        (unsigned int)shift);
      ++v3;
      ++v15;
    }
    while ( v3 < this->m_obstacleGenerators.m_size );
  }
  hkaiWorld::shiftPathRequests(this, shift);
}

// File Line: 400
// RVA: 0xBCDBE0
void __fastcall hkaiWorld::addListener(hkaiWorld *this, hkaiWorld::Listener *listener)
{
  hkArray<hkaiWorld::Listener *,hkContainerHeapAllocator> *p_m_listeners; // rbx

  p_m_listeners = &this->m_listeners;
  if ( this->m_listeners.m_size == (this->m_listeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_listeners, 8);
  p_m_listeners->m_data[p_m_listeners->m_size++] = listener;
}

// File Line: 407
// RVA: 0xBCDC40
void __fastcall hkaiWorld::removeListener(hkaiWorld *this, hkaiWorld::Listener *listener)
{
  __int64 m_size; // r11
  int v3; // r8d
  __int64 v4; // r9
  hkaiWorld::Listener **i; // rax

  m_size = this->m_listeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( (int)m_size > 0 )
  {
    for ( i = this->m_listeners.m_data; *i != listener; ++i )
    {
      ++v4;
      ++v3;
      if ( v4 >= m_size )
        return;
    }
    if ( v3 != -1 )
    {
      this->m_listeners.m_size = m_size - 1;
      if ( (_DWORD)m_size - 1 != v3 )
        this->m_listeners.m_data[v3] = this->m_listeners.m_data[(int)m_size - 1];
    }
  }
}

// File Line: 418
// RVA: 0xBCE230
void __fastcall hkaiWorld::firePostStepCallbacks(hkaiWorld *this, hkArrayBase<hkaiBehavior *> *behaviors)
{
  int v2; // ebx
  __int64 v5; // rsi

  v2 = 0;
  if ( this->m_listeners.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      this->m_listeners.m_data[v5]->vfptr->postStepCallback(this->m_listeners.m_data[v5], this, behaviors);
      ++v2;
      ++v5;
    }
    while ( v2 < this->m_listeners.m_size );
  }
}

// File Line: 427
// RVA: 0xBCDDC0
hkaiDynamicNavMeshQueryMediator *__fastcall hkaiWorld::getDynamicQueryMediator(hkaiWorld *this)
{
  return this->m_dynamicNavMeshMediator.m_pntr;
}

// File Line: 432
// RVA: 0xBCDDD0
hkaiDynamicNavMeshQueryMediator *__fastcall hkaiWorld::getDynamicQueryMediator(hkaiWorld *this)
{
  return this->m_dynamicNavMeshMediator.m_pntr;
}

// File Line: 437
// RVA: 0xBCDDE0
hkaiDynamicNavVolumeMediator *__fastcall hkaiWorld::getDynamicNavVolumeMediator(hkaiWorld *this)
{
  return this->m_dynamicNavVolumeMediator.m_pntr;
}

// File Line: 442
// RVA: 0xBCE1E0
void __fastcall hkaiWorld::setAvoidancePairProperties(hkaiWorld *this, hkaiAvoidancePairProperties *props)
{
  hkaiAvoidancePairProperties *m_pntr; // rcx

  if ( props )
    hkReferencedObject::addReference(props);
  m_pntr = this->m_avoidancePairProps.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_avoidancePairProps.m_pntr = props;
}

// File Line: 448
// RVA: 0xBCD250
void __fastcall hkaiNavMeshPathRequestInfo::checkDeterminism(hkaiNavMeshPathRequestInfo *this)
{
  ;
}

// File Line: 468
// RVA: 0xBCD260
void __fastcall hkaiNavVolumePathRequestInfo::checkDeterminism(hkaiNavVolumePathRequestInfo *this)
{
  ;
}


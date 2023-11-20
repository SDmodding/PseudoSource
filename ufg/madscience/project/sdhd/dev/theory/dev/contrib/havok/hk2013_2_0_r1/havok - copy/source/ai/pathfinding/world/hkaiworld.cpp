// File Line: 47
// RVA: 0xBCD270
void __fastcall hkaiWorld::Cinfo::Cinfo(hkaiWorld::Cinfo *this)
{
  hkaiWorld::Cinfo *v1; // rbx

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
  v1 = this;
  hkaiPathfindingUtil::FindPathInput::FindPathInput(&this->m_pathfindingInput, 0);
  hkaiVolumePathfindingUtil::FindPathInput::FindPathInput(&v1->m_volumePathfindingInput, 0);
  v1->m_up.m_quad = _xmm;
  v1->m_pathfindingInput.m_searchParameters.m_useHierarchicalHeuristic.m_bool = 1;
}

// File Line: 54
// RVA: 0xBCD330
void __fastcall hkaiWorld::hkaiWorld(hkaiWorld *this, hkaiWorld::Cinfo *cInfo)
{
  hkaiDynamicNavVolumeMediator *v2; // rdi
  hkaiWorld::Cinfo *v3; // rsi
  hkaiWorld *v4; // rbx
  hkaiAvoidancePairProperties *v5; // rbp
  hkReferencedObject *v6; // rcx
  int v7; // eax
  _QWORD **v8; // rax
  hkaiStreamingCollection *v9; // rax
  hkaiStreamingCollection *v10; // rax
  hkaiStreamingCollection *v11; // rbp
  hkReferencedObject *v12; // rcx
  _QWORD **v13; // rax
  hkaiNavMeshCutter *v14; // rax
  hkaiNavMeshCutter *v15; // rax
  hkaiNavMeshCutter *v16; // rbp
  hkReferencedObject *v17; // rcx
  char v18; // al
  hkaiNavMeshCutter *v19; // rcx
  __m128i v20; // xmm4
  __m128 v21; // xmm3
  __m128 v22; // xmm4
  float v23; // eax
  float v24; // eax
  _QWORD **v25; // rax
  hkaiOverlapManager *v26; // rax
  hkaiOverlapManager *v27; // rax
  hkaiOverlapManager *v28; // rbp
  hkReferencedObject *v29; // rcx
  _QWORD **v30; // rax
  hkaiDynamicNavMeshQueryMediator *v31; // rax
  hkaiDynamicNavMeshQueryMediator *v32; // rax
  hkaiDynamicNavMeshQueryMediator *v33; // rsi
  hkReferencedObject *v34; // rcx
  _QWORD **v35; // rax
  hkaiDynamicNavVolumeMediator *v36; // rax
  hkaiDynamicNavVolumeMediator *v37; // rax
  hkReferencedObject *v38; // rcx
  hkVector4f referenceAxis; // [rsp+20h] [rbp-48h]
  int v40; // [rsp+30h] [rbp-38h]
  int v41; // [rsp+34h] [rbp-34h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiWorld::`vftable';
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
  this->m_listeners.m_capacityAndFlags = 2147483648;
  this->m_silhouetteGenerators.m_data = 0i64;
  this->m_silhouetteGenerators.m_size = 0;
  this->m_silhouetteGenerators.m_capacityAndFlags = 2147483648;
  this->m_obstacleGenerators.m_data = 0i64;
  this->m_obstacleGenerators.m_size = 0;
  this->m_obstacleGenerators.m_capacityAndFlags = 2147483648;
  this->m_avoidancePairProps.m_pntr = 0i64;
  this->m_navMeshPathRequests.m_data = 0i64;
  this->m_navMeshPathRequests.m_size = 0;
  this->m_navMeshPathRequests.m_capacityAndFlags = 2147483648;
  v3 = cInfo;
  this->m_navVolumePathRequests.m_data = 0i64;
  this->m_navVolumePathRequests.m_size = 0;
  this->m_navVolumePathRequests.m_capacityAndFlags = 2147483648;
  v4 = this;
  hkaiPathfindingUtil::FindPathInput::FindPathInput(&this->m_defaultPathfindingInput, 0);
  hkaiVolumePathfindingUtil::FindPathInput::FindPathInput(&v4->m_defaultVolumePathfindingInput, 0);
  v4->m_up = v3->m_up;
  v4->m_performValidationChecks.m_bool = v3->m_performValidationChecks.m_bool;
  v4->m_silhouetteExtrusion = v3->m_silhouetteExtrusion;
  v4->m_forceSilhouetteUpdates.m_bool = 0;
  v5 = v3->m_avoidancePairProps;
  if ( v5 )
    hkReferencedObject::addReference((hkReferencedObject *)&v3->m_avoidancePairProps->vfptr);
  v6 = (hkReferencedObject *)&v4->m_avoidancePairProps.m_pntr->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v4->m_avoidancePairProps.m_pntr = v5;
  v4->m_maxRequestsPerStep = v3->m_maxRequestsPerStep;
  v4->m_maxEstimatedIterationsPerStep = v3->m_maxEstimatedIterationsPerStep;
  v4->m_priorityThreshold = v3->m_priorityThreshold;
  v4->m_numPathRequestsPerJob = v3->m_numPathRequestsPerJob;
  v4->m_numBehaviorUpdatesPerJob = v3->m_numBehaviorUpdatesPerJob;
  v4->m_numCharactersPerAvoidanceJob = v3->m_numCharactersPerAvoidanceJob;
  v4->m_maxPathSearchEdgesOut = v3->m_maxPathSearchEdgesOut;
  v7 = v3->m_maxPathSearchPointsOut;
  v4->m_erosionRadius = 0.0;
  v4->m_maxPathSearchPointsOut = v7;
  v4->m_precomputeNavMeshClearance.m_bool = v3->m_precomputeNavMeshClearance.m_bool;
  v4->m_isPathRequestArrayLocked.m_bool = 0;
  hkaiPathfindingUtil::FindPathInput::operator=(&v4->m_defaultPathfindingInput, &v3->m_pathfindingInput);
  hkaiVolumePathfindingUtil::FindPathInput::operator=(
    &v4->m_defaultVolumePathfindingInput,
    &v3->m_volumePathfindingInput);
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkaiStreamingCollection *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 48i64);
  if ( v9 )
  {
    hkaiStreamingCollection::hkaiStreamingCollection(v9);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = (hkReferencedObject *)&v4->m_streamingCollection.m_pntr->vfptr;
  if ( v12 && v12 != (hkReferencedObject *)v11 )
    hkReferencedObject::removeReference(v12);
  v4->m_streamingCollection.m_pntr = v11;
  v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (hkaiNavMeshCutter *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v13[11] + 8i64))(v13[11], 192i64);
  if ( v14 )
  {
    hkaiNavMeshCutter::hkaiNavMeshCutter(v14);
    v16 = v15;
  }
  else
  {
    v16 = 0i64;
  }
  v17 = (hkReferencedObject *)&v4->m_cutter.m_pntr->vfptr;
  if ( v17 && v17 != (hkReferencedObject *)v16 )
    hkReferencedObject::removeReference(v17);
  v4->m_cutter.m_pntr = v16;
  hkaiNavMeshCutter::init(v16, &v4->m_up, v4->m_streamingCollection.m_pntr);
  v18 = v4->m_performValidationChecks.m_bool;
  v19 = v4->m_cutter.m_pntr;
  referenceAxis.m_quad = 0i64;
  v19->m_performValidationChecks.m_bool = v18;
  v4->m_cutter.m_pntr->m_clearanceResetMethod.m_storage = v3->m_clearanceResetMethod.m_storage;
  v4->m_cutter.m_pntr->m_useNewCutter.m_bool = v3->m_fallbackToOldCutter.m_bool == 0;
  v4->m_cutter.m_pntr->m_recomputeClearanceAfterCutting.m_bool = v4->m_precomputeNavMeshClearance.m_bool;
  v20 = _mm_load_si128((const __m128i *)&v4->m_up);
  v21 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v20, 1u), 1u);
  referenceAxis.m_quad.m128_i32[((unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                                        _mm_and_ps(
                                                                                          _mm_cmpleps(
                                                                                            _mm_max_ps(
                                                                                              _mm_shuffle_ps(
                                                                                                v21,
                                                                                                v21,
                                                                                                170),
                                                                                              _mm_max_ps(
                                                                                                _mm_shuffle_ps(
                                                                                                  v21,
                                                                                                  v21,
                                                                                                  85),
                                                                                                _mm_shuffle_ps(
                                                                                                  v21,
                                                                                                  v21,
                                                                                                  0))),
                                                                                            v21),
                                                                                          (__m128)xmmword_141A5C140))]
                               + 2)
                              % 3] = 1065353216;
  v22 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)v20, (__m128)v20, 201), referenceAxis.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(referenceAxis.m_quad, referenceAxis.m_quad, 201), (__m128)v20));
  referenceAxis.m_quad = _mm_shuffle_ps(v22, v22, 201);
  hkaiSilhouetteReferenceFrame::set(&v4->m_silhouetteGenerationParameters.m_referenceFrame, &v4->m_up, &referenceAxis);
  v4->m_silhouetteGenerationParameters.m_bevelThreshold = v3->m_bevelThreshold;
  v23 = v3->m_maxSilhouetteSize;
  referenceAxis.m_quad = 0i64;
  v4->m_silhouetteGenerationParameters.m_maxSilhouetteSize = v23;
  v4->m_silhouetteGenerationParameters.m_simplify2dConvexHullThreshold = v3->m_simplify2dConvexHullThreshold;
  v24 = v4->m_erosionRadius;
  v40 = -1082130432;
  v4->m_silhouetteGenerationParameters.m_extraExpansion = v24;
  v41 = -1082130432;
  hkaiWorld::setupReferenceFrame(v4, (hkaiReferenceFrameAndExtrusion *)&referenceAxis);
  v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v26 = (hkaiOverlapManager *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v25[11] + 8i64))(v25[11], 128i64);
  if ( v26 )
  {
    hkaiOverlapManager::hkaiOverlapManager(
      v26,
      v4->m_streamingCollection.m_pntr,
      (hkaiReferenceFrameAndExtrusion *)&referenceAxis);
    v28 = v27;
  }
  else
  {
    v28 = 0i64;
  }
  v29 = (hkReferencedObject *)&v4->m_overlapManager.m_pntr->vfptr;
  if ( v29 && v29 != (hkReferencedObject *)v28 )
    hkReferencedObject::removeReference(v29);
  v4->m_overlapManager.m_pntr = v28;
  v28->m_maxCutFacesPerStep = v3->m_maxCutFacesPerStep;
  hkaiStreamingCollection::setupTree(v4->m_streamingCollection.m_pntr);
  v30 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v31 = (hkaiDynamicNavMeshQueryMediator *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v30[11] + 8i64))(
                                             v30[11],
                                             48i64);
  if ( v31 )
  {
    hkaiDynamicNavMeshQueryMediator::hkaiDynamicNavMeshQueryMediator(
      v31,
      v4->m_streamingCollection.m_pntr,
      v4->m_streamingCollection.m_pntr->m_tree.m_pntr,
      v4->m_cutter.m_pntr);
    v33 = v32;
  }
  else
  {
    v33 = 0i64;
  }
  v34 = (hkReferencedObject *)&v4->m_dynamicNavMeshMediator.m_pntr->vfptr;
  if ( v34 && v34 != (hkReferencedObject *)v33 )
    hkReferencedObject::removeReference(v34);
  v4->m_dynamicNavMeshMediator.m_pntr = v33;
  v35 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v36 = (hkaiDynamicNavVolumeMediator *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v35[11] + 8i64))(
                                          v35[11],
                                          32i64);
  if ( v36 )
  {
    hkaiDynamicNavVolumeMediator::hkaiDynamicNavVolumeMediator(
      v36,
      v4->m_streamingCollection.m_pntr,
      v4->m_streamingCollection.m_pntr->m_tree.m_pntr);
    v2 = v37;
  }
  v38 = (hkReferencedObject *)&v4->m_dynamicNavVolumeMediator.m_pntr->vfptr;
  if ( v38 && v38 != (hkReferencedObject *)v2 )
    hkReferencedObject::removeReference(v38);
  v4->m_dynamicNavVolumeMediator.m_pntr = v2;
}

// File Line: 138
// RVA: 0xBCD7F0
void __fastcall hkaiWorld::hkaiWorld(hkaiWorld *this, hkFinishLoadedObjectFlag f)
{
  hkaiWorld *v2; // rbx
  hkaiPathfindingUtil::FindPathInput *v3; // rcx
  int fa; // [rsp+38h] [rbp+10h]

  fa = f.m_finishing;
  v2 = this;
  v3 = &this->m_defaultPathfindingInput;
  v3[-2].m_searchParameters.m_costModifier = (hkaiAstarCostModifier *)&hkaiWorld::`vftable';
  v3[-1].m_goalFaceKeys.m_capacityAndFlags = 2147483648;
  v3[-1].m_goalFaceKeys.m_data = 0i64;
  v3[-1].m_goalFaceKeys.m_size = 0;
  *(_QWORD *)&v3[-1].m_searchParameters.m_validateInputs.m_bool = 0i64;
  v3[-1].m_searchParameters.m_heuristicWeight = 0.0;
  v3[-1].m_searchParameters.m_simpleRadiusThreshold = -0.0;
  *(_QWORD *)&v3[-1].m_searchParameters.m_maximumPathLength = 0i64;
  v3[-1].m_searchParameters.m_searchCapsuleRadius = 0.0;
  v3[-1].m_searchParameters.m_bufferSizes.m_maxOpenSetSizeBytes = 2147483648;
  hkaiPathfindingUtil::FindPathInput::FindPathInput(v3, f);
  hkaiVolumePathfindingUtil::FindPathInput::FindPathInput(
    &v2->m_defaultVolumePathfindingInput,
    (hkFinishLoadedObjectFlag)fa);
}

// File Line: 143
// RVA: 0xBCD870
void __fastcall hkaiWorld::~hkaiWorld(hkaiWorld *this)
{
  int v1; // edi
  hkaiWorld *v2; // rbx
  int i; // edi
  int v4; // eax
  __int64 j; // rdi
  hkaiWorld::Listener *v6; // rcx
  hkaiNavVolumePathRequestInfo *v7; // rcx
  int v8; // edi
  signed __int64 v9; // rax
  hkaiNavVolumePathRequestInfo *v10; // rsi
  signed __int64 v11; // rbp
  int v12; // er8
  hkaiNavMeshPathRequestInfo *v13; // rcx
  int v14; // edi
  signed __int64 v15; // rax
  hkaiNavMeshPathRequestInfo *v16; // rsi
  signed __int64 v17; // rbp
  int v18; // er8
  hkReferencedObject *v19; // rcx
  hkRefPtr<hkaiObstacleGenerator> *v20; // rsi
  int v21; // eax
  __int64 k; // rdi
  hkReferencedObject *v23; // rcx
  int v24; // er8
  hkRefPtr<hkaiSilhouetteGenerator> *v25; // rsi
  int v26; // eax
  __int64 l; // rdi
  hkReferencedObject *v28; // rcx
  int v29; // er8
  int v30; // er8
  hkReferencedObject *v31; // rcx
  hkReferencedObject *v32; // rcx
  hkReferencedObject *v33; // rcx
  hkReferencedObject *v34; // rcx
  hkReferencedObject *v35; // rcx

  v1 = this->m_navMeshPathRequests.m_size - 1;
  v2 = this;
  for ( this->vfptr = (hkBaseObjectVtbl *)&hkaiWorld::`vftable'; v1 >= 0; --v1 )
    hkaiWorld::_deleteNavMeshPathRequestAt(v2, v1);
  for ( i = v2->m_navVolumePathRequests.m_size - 1; i >= 0; --i )
    hkaiWorld::_deleteNavVolumePathRequestAt(v2, i);
  v4 = v2->m_listeners.m_size - 1;
  for ( j = v4; j >= 0; --j )
  {
    v6 = v2->m_listeners.m_data[j];
    v6->vfptr->worldDeletedCallback(v6, v2);
  }
  hkaiVolumePathfindingUtil::FindPathInput::~FindPathInput(&v2->m_defaultVolumePathfindingInput);
  hkaiPathfindingUtil::FindPathInput::~FindPathInput(&v2->m_defaultPathfindingInput);
  v7 = v2->m_navVolumePathRequests.m_data;
  v8 = v2->m_navVolumePathRequests.m_size - 1;
  if ( v8 >= 0 )
  {
    v9 = v8;
    v10 = &v7[v9];
    v11 = (signed __int64)&v7[v9];
    do
    {
      v10->vfptr->__vecDelDtor((hkBaseObject *)v11, 0);
      v11 -= 56i64;
      --v8;
      --v10;
    }
    while ( v8 >= 0 );
  }
  v12 = v2->m_navVolumePathRequests.m_capacityAndFlags;
  v2->m_navVolumePathRequests.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_navVolumePathRequests.m_data,
      56 * (v12 & 0x3FFFFFFF));
  v2->m_navVolumePathRequests.m_data = 0i64;
  v2->m_navVolumePathRequests.m_capacityAndFlags = 2147483648;
  v13 = v2->m_navMeshPathRequests.m_data;
  v14 = v2->m_navMeshPathRequests.m_size - 1;
  if ( v14 >= 0 )
  {
    v15 = v14;
    v16 = &v13[v15];
    v17 = (signed __int64)&v13[v15];
    do
    {
      v16->vfptr->__vecDelDtor((hkBaseObject *)v17, 0);
      v17 -= 56i64;
      --v14;
      --v16;
    }
    while ( v14 >= 0 );
  }
  v18 = v2->m_navMeshPathRequests.m_capacityAndFlags;
  v2->m_navMeshPathRequests.m_size = 0;
  if ( v18 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_navMeshPathRequests.m_data,
      56 * (v18 & 0x3FFFFFFF));
  v2->m_navMeshPathRequests.m_data = 0i64;
  v2->m_navMeshPathRequests.m_capacityAndFlags = 2147483648;
  v19 = (hkReferencedObject *)&v2->m_avoidancePairProps.m_pntr->vfptr;
  if ( v19 )
    hkReferencedObject::removeReference(v19);
  v2->m_avoidancePairProps.m_pntr = 0i64;
  v20 = v2->m_obstacleGenerators.m_data;
  v21 = v2->m_obstacleGenerators.m_size - 1;
  for ( k = v21; k >= 0; v20[k--].m_pntr = 0i64 )
  {
    v23 = (hkReferencedObject *)&v20[k].m_pntr->vfptr;
    if ( v23 )
      hkReferencedObject::removeReference(v23);
  }
  v24 = v2->m_obstacleGenerators.m_capacityAndFlags;
  v2->m_obstacleGenerators.m_size = 0;
  if ( v24 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_obstacleGenerators.m_data,
      8 * v24);
  v2->m_obstacleGenerators.m_data = 0i64;
  v2->m_obstacleGenerators.m_capacityAndFlags = 2147483648;
  v25 = v2->m_silhouetteGenerators.m_data;
  v26 = v2->m_silhouetteGenerators.m_size - 1;
  for ( l = v26; l >= 0; v25[l--].m_pntr = 0i64 )
  {
    v28 = (hkReferencedObject *)&v25[l].m_pntr->vfptr;
    if ( v28 )
      hkReferencedObject::removeReference(v28);
  }
  v29 = v2->m_silhouetteGenerators.m_capacityAndFlags;
  v2->m_silhouetteGenerators.m_size = 0;
  if ( v29 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_silhouetteGenerators.m_data,
      8 * v29);
  v2->m_silhouetteGenerators.m_data = 0i64;
  v2->m_silhouetteGenerators.m_capacityAndFlags = 2147483648;
  v30 = v2->m_listeners.m_capacityAndFlags;
  v2->m_listeners.m_size = 0;
  if ( v30 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_listeners.m_data,
      8 * v30);
  v2->m_listeners.m_data = 0i64;
  v2->m_listeners.m_capacityAndFlags = 2147483648;
  v31 = (hkReferencedObject *)&v2->m_overlapManager.m_pntr->vfptr;
  if ( v31 )
    hkReferencedObject::removeReference(v31);
  v2->m_overlapManager.m_pntr = 0i64;
  v32 = (hkReferencedObject *)&v2->m_dynamicNavVolumeMediator.m_pntr->vfptr;
  if ( v32 )
    hkReferencedObject::removeReference(v32);
  v2->m_dynamicNavVolumeMediator.m_pntr = 0i64;
  v33 = (hkReferencedObject *)&v2->m_dynamicNavMeshMediator.m_pntr->vfptr;
  if ( v33 )
    hkReferencedObject::removeReference(v33);
  v2->m_dynamicNavMeshMediator.m_pntr = 0i64;
  v34 = (hkReferencedObject *)&v2->m_cutter.m_pntr->vfptr;
  if ( v34 )
    hkReferencedObject::removeReference(v34);
  v2->m_cutter.m_pntr = 0i64;
  v35 = (hkReferencedObject *)&v2->m_streamingCollection.m_pntr->vfptr;
  if ( v35 )
    hkReferencedObject::removeReference(v35);
  v2->m_streamingCollection.m_pntr = 0i64;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 162
// RVA: 0xBCDCB0
void __fastcall hkaiWorld::setNavMesh(hkaiWorld *this, hkaiNavMesh *navMesh, hkaiNavMeshQueryMediator *mediator, hkaiDirectedGraphExplicitCost *hierarchyInfo, bool setupClearanceInfo)
{
  hkaiWorld *v5; // rsi
  hkaiDirectedGraphExplicitCost *v6; // rbp
  hkaiNavMeshQueryMediator *v7; // r15
  hkaiNavMesh *v8; // r14
  _QWORD **v9; // rax
  hkaiNavMeshInstance *v10; // rax
  hkaiDirectedGraphInstance *v11; // rbx
  hkaiNavMeshInstance *v12; // rax
  hkaiNavMeshInstance *v13; // rdi
  _QWORD **v14; // rax
  hkaiDirectedGraphInstance *v15; // rax
  hkaiDirectedGraphInstance *v16; // rax
  float v17; // xmm0_4

  v5 = this;
  v6 = hierarchyInfo;
  v7 = mediator;
  v8 = navMesh;
  v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkaiNavMeshInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v9[11] + 8i64))(v9[11], 480i64);
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
  hkaiNavMeshInstance::init(v13, v8, 0, setupClearanceInfo);
  if ( v6 )
  {
    v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (hkaiDirectedGraphInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(
                                         v14[11],
                                         272i64);
    if ( v15 )
    {
      hkaiDirectedGraphInstance::hkaiDirectedGraphInstance(v15);
      v11 = v16;
    }
    hkaiDirectedGraphInstance::init(v11, v6, 0);
  }
  v17 = v13->m_originalMesh.m_pntr->m_erosionRadius;
  v5->m_erosionRadius = v17;
  v5->m_silhouetteGenerationParameters.m_extraExpansion = v17;
  hkaiWorld::loadNavMeshInstance(v5, v13, v7, v11);
  if ( v11 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v11->vfptr);
  hkReferencedObject::removeReference((hkReferencedObject *)&v13->vfptr);
}

// File Line: 191
// RVA: 0xBCDDF0
void __fastcall hkaiWorld::loadNavMeshInstance(hkaiWorld *this, hkaiNavMeshInstance *navMeshInstance, hkaiNavMeshQueryMediator *mediator, hkaiDirectedGraphInstance *hierarchyGraphInstance)
{
  int v4; // esi
  hkaiDirectedGraphInstance *v5; // rbp
  hkaiNavMeshInstance *v6; // rbx
  hkaiWorld *v7; // rdi
  hkaiNavMeshQueryMediator *v8; // r15
  __int64 v9; // r14

  v4 = 0;
  v5 = hierarchyGraphInstance;
  v6 = navMeshInstance;
  v7 = this;
  v8 = mediator;
  if ( this->m_listeners.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      v7->m_listeners.m_data[v9]->vfptr->navMeshInstanceAdded(v7->m_listeners.m_data[v9], v7, v6, v8, v5);
      ++v4;
      ++v9;
    }
    while ( v4 < v7->m_listeners.m_size );
  }
  if ( v6->m_clearanceCache.m_size > 0 || v6->m_globalClearanceCache.m_size > 0 )
  {
    hkaiNavMeshInstance::initClearanceCache(v6);
    hkaiNavMeshInstance::resetVertexClearances(v6);
  }
  hkaiStreamingCollection::addInstance(v7->m_streamingCollection.m_pntr, v6, v8, v5);
  hkaiOverlapManager::loadSection(v7->m_overlapManager.m_pntr, v6->m_runtimeId, &v7->m_silhouetteGenerators);
  hkaiNavMeshCutter::initSection(v7->m_cutter.m_pntr, v6->m_runtimeId, v6, 1);
  if ( v7->m_precomputeNavMeshClearance.m_bool )
    hkaiNavMeshCutter::recomputeDirtyGlobalClearances(v7->m_cutter.m_pntr, v6);
}

// File Line: 239
// RVA: 0xBCDF00
void __fastcall hkaiWorld::unloadNavMeshInstance(hkaiWorld *this, hkaiNavMeshInstance *navMeshInstance, hkaiDirectedGraphInstance *hierarchyGraphInstance)
{
  int v3; // edi
  hkaiDirectedGraphInstance *v4; // r14
  hkaiNavMeshInstance *v5; // rbp
  hkaiWorld *v6; // rbx
  __int64 v7; // rsi

  v3 = 0;
  v4 = hierarchyGraphInstance;
  v5 = navMeshInstance;
  v6 = this;
  if ( this->m_listeners.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v6->m_listeners.m_data[v7]->vfptr->navMeshInstanceRemoved(v6->m_listeners.m_data[v7], v6, v5, v4);
      ++v3;
      ++v7;
    }
    while ( v3 < v6->m_listeners.m_size );
  }
  hkaiNavMeshCutter::uncutSection(v6->m_cutter.m_pntr, v5->m_runtimeId, 1);
  hkaiOverlapManager::unloadSection(v6->m_overlapManager.m_pntr, v5->m_runtimeId);
  hkaiStreamingCollection::removeInstance(v6->m_streamingCollection.m_pntr, v5, v4);
}

// File Line: 269
// RVA: 0xBCDFB0
void __fastcall hkaiWorld::loadNavMeshGraph(hkaiWorld *this, hkaiDirectedGraphInstance *graphInstance)
{
  int v2; // edi
  hkaiDirectedGraphInstance *v3; // rbp
  hkaiWorld *v4; // rbx
  __int64 v5; // rsi

  v2 = 0;
  v3 = graphInstance;
  v4 = this;
  if ( this->m_listeners.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v4->m_listeners.m_data[v5]->vfptr->graphAdded(v4->m_listeners.m_data[v5], v4, v3);
      ++v2;
      ++v5;
    }
    while ( v2 < v4->m_listeners.m_size );
  }
  hkaiStreamingCollection::addMeshGraph(v4->m_streamingCollection.m_pntr, v3);
}

// File Line: 280
// RVA: 0xBCE030
void __fastcall hkaiWorld::unloadNavMeshGraph(hkaiWorld *this, hkaiDirectedGraphInstance *graphInstance)
{
  int v2; // edi
  hkaiDirectedGraphInstance *v3; // rbp
  hkaiWorld *v4; // rbx
  __int64 v5; // rsi

  v2 = 0;
  v3 = graphInstance;
  v4 = this;
  if ( this->m_listeners.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v4->m_listeners.m_data[v5]->vfptr->graphRemoved(v4->m_listeners.m_data[v5], v4, v3);
      ++v2;
      ++v5;
    }
    while ( v2 < v4->m_listeners.m_size );
  }
  hkaiStreamingCollection::removeMeshGraph(v4->m_streamingCollection.m_pntr, v3);
}

// File Line: 300
// RVA: 0xBCE0B0
void __fastcall hkaiWorld::loadNavVolume(hkaiWorld *this, hkaiNavVolumeInstance *navVolume, hkaiNavVolumeMediator *mediator)
{
  int v3; // edi
  hkaiNavVolumeMediator *v4; // rbp
  hkaiNavVolumeInstance *v5; // r14
  hkaiWorld *v6; // rbx
  __int64 v7; // rsi

  v3 = 0;
  v4 = mediator;
  v5 = navVolume;
  v6 = this;
  if ( this->m_listeners.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v6->m_listeners.m_data[v7]->vfptr->navVolumeAdded(v6->m_listeners.m_data[v7], v6, v5, v4);
      ++v3;
      ++v7;
    }
    while ( v3 < v6->m_listeners.m_size );
  }
  hkaiStreamingCollection::addVolume(v6->m_streamingCollection.m_pntr, v5, v4);
}

// File Line: 320
// RVA: 0xBCE140
void __fastcall hkaiWorld::unloadNavVolume(hkaiWorld *this, hkaiNavVolumeInstance *navVolume)
{
  int v2; // esi
  hkaiNavVolumeInstance *v3; // rbx
  hkaiWorld *v4; // rdi
  __int64 v5; // r14

  v2 = 0;
  v3 = navVolume;
  v4 = this;
  if ( this->m_listeners.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v4->m_listeners.m_data[v5]->vfptr->navVolumeRemoved(v4->m_listeners.m_data[v5], v4, v3);
      ++v2;
      ++v5;
    }
    while ( v2 < v4->m_listeners.m_size );
  }
  if ( v3 )
    hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
  hkaiStreamingCollection::removeVolume(v4->m_streamingCollection.m_pntr, v3);
  if ( v3 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v3->vfptr);
}

// File Line: 341
// RVA: 0xBCE2A0
void __fastcall hkaiWorld::shiftWorldSpace(hkaiWorld *this, hkVector4f *shift)
{
  hkaiStreamingCollection *v2; // rdi
  int v3; // ebp
  hkVector4f *v4; // r15
  hkaiWorld *v5; // rbx
  int v6; // er14
  __int64 v7; // rsi
  hkaiNavMeshInstance *v8; // rdx
  hkVector4f v9; // xmm1
  hkVector4f v10; // xmm0
  __m128 v11; // xmm1
  hkaiNavVolumeInstance *v12; // rdx
  int v13; // edi
  __int64 v14; // rsi
  __int64 v15; // rdi
  hkVector4f translation; // [rsp+20h] [rbp-68h]
  hkTransformf transform; // [rsp+30h] [rbp-58h]

  v2 = this->m_streamingCollection.m_pntr;
  v3 = 0;
  v4 = shift;
  v5 = this;
  v6 = 0;
  if ( v2->m_instances.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = v2->m_instances.m_data[v7].m_instancePtr;
      if ( v8 )
      {
        v9.m_quad = (__m128)v8->m_referenceFrame.m_transform.m_rotation.m_col1;
        transform.m_rotation.m_col0 = v8->m_referenceFrame.m_transform.m_rotation.m_col0;
        v10.m_quad = (__m128)v8->m_referenceFrame.m_transform.m_rotation.m_col2;
        transform.m_rotation.m_col1 = (hkVector4f)v9.m_quad;
        v11 = v8->m_referenceFrame.m_transform.m_translation.m_quad;
        transform.m_rotation.m_col2 = (hkVector4f)v10.m_quad;
        transform.m_translation.m_quad = _mm_add_ps(v4->m_quad, v11);
        hkaiStreamingCollection::setSectionTransform(v2, v8, &transform);
      }
      v12 = v2->m_instances.m_data[v7].m_volumeInstancePtr;
      if ( v12 )
      {
        translation.m_quad = _mm_add_ps(v4->m_quad, v12->m_translation.m_quad);
        hkaiStreamingCollection::setVolumeTranslation(v2, v12, &translation);
      }
      ++v6;
      ++v7;
    }
    while ( v6 < v2->m_instances.m_size );
  }
  v13 = 0;
  if ( v5->m_silhouetteGenerators.m_size > 0 )
  {
    v14 = 0i64;
    do
    {
      ((void (__fastcall *)(hkaiSilhouetteGenerator *, hkVector4f *))v5->m_silhouetteGenerators.m_data[v14].m_pntr->vfptr[5].__first_virtual_table_function__)(
        v5->m_silhouetteGenerators.m_data[v14].m_pntr,
        v4);
      ++v13;
      ++v14;
    }
    while ( v13 < v5->m_silhouetteGenerators.m_size );
  }
  if ( v5->m_obstacleGenerators.m_size > 0 )
  {
    v15 = 0i64;
    do
    {
      v5->m_obstacleGenerators.m_data[v15].m_pntr->vfptr[3].__vecDelDtor(
        (hkBaseObject *)&v5->m_obstacleGenerators.m_data[v15].m_pntr->vfptr,
        (unsigned int)v4);
      ++v3;
      ++v15;
    }
    while ( v3 < v5->m_obstacleGenerators.m_size );
  }
  hkaiWorld::shiftPathRequests(v5, v4);
}

// File Line: 400
// RVA: 0xBCDBE0
void __fastcall hkaiWorld::addListener(hkaiWorld *this, hkaiWorld::Listener *listener)
{
  hkArray<hkaiWorld::Listener *,hkContainerHeapAllocator> *v2; // rbx
  hkaiWorld::Listener *v3; // rdi

  v2 = &this->m_listeners;
  v3 = listener;
  if ( this->m_listeners.m_size == (this->m_listeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
}

// File Line: 407
// RVA: 0xBCDC40
void __fastcall hkaiWorld::removeListener(hkaiWorld *this, hkaiWorld::Listener *listener)
{
  __int64 v2; // r11
  int v3; // er8
  __int64 v4; // r9
  hkaiWorld::Listener **v5; // rax

  v2 = this->m_listeners.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( (signed int)v2 > 0 )
  {
    v5 = this->m_listeners.m_data;
    while ( *v5 != listener )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        return;
    }
    if ( v3 != -1 )
    {
      this->m_listeners.m_size = v2 - 1;
      if ( (_DWORD)v2 - 1 != v3 )
        this->m_listeners.m_data[v3] = this->m_listeners.m_data[(signed int)v2 - 1];
    }
  }
}

// File Line: 418
// RVA: 0xBCE230
void __fastcall hkaiWorld::firePostStepCallbacks(hkaiWorld *this, hkArrayBase<hkaiBehavior *> *behaviors)
{
  int v2; // ebx
  hkArrayBase<hkaiBehavior *> *v3; // rbp
  hkaiWorld *v4; // rdi
  __int64 v5; // rsi

  v2 = 0;
  v3 = behaviors;
  v4 = this;
  if ( this->m_listeners.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v4->m_listeners.m_data[v5]->vfptr->postStepCallback(v4->m_listeners.m_data[v5], v4, v3);
      ++v2;
      ++v5;
    }
    while ( v2 < v4->m_listeners.m_size );
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
  hkaiAvoidancePairProperties *v2; // rbx
  hkaiWorld *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = props;
  v3 = this;
  if ( props )
    hkReferencedObject::addReference((hkReferencedObject *)&props->vfptr);
  v4 = (hkReferencedObject *)&v3->m_avoidancePairProps.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_avoidancePairProps.m_pntr = v2;
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


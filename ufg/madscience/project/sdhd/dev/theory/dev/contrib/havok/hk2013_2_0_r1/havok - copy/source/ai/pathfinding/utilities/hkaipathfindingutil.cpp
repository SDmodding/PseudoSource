// File Line: 48
// RVA: 0xBBC6B0
void __fastcall hkaiPathfindingUtil::FindPathInput::FindPathInput(
        hkaiPathfindingUtil::FindPathInput *this,
        int numGoals)
{
  int v4; // eax
  int v5; // eax
  int v6; // r9d
  int v7; // eax
  int v8; // eax
  int v9; // r9d
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPathfindingUtil::FindPathInput::`vftable;
  *(_QWORD *)&this->m_goalPoints.m_capacityAndFlags = 0xFFFFFFFF80000000ui64;
  this->m_goalPoints.m_data = 0i64;
  this->m_goalPoints.m_size = 0;
  this->m_goalFaceKeys.m_data = 0i64;
  this->m_goalFaceKeys.m_size = 0;
  this->m_goalFaceKeys.m_capacityAndFlags = 0x80000000;
  *(_QWORD *)&this->m_maxNumberOfIterations = 100000i64;
  this->m_agentInfo.m_filterInfo = 0;
  this->m_searchParameters.m_costModifier = 0i64;
  this->m_searchParameters.m_edgeFilter = 0i64;
  *(_DWORD *)&this->m_searchParameters.m_validateInputs.m_bool = 66305;
  *(_WORD *)&this->m_searchParameters.m_projectedRadiusCheck.m_bool = 1;
  this->m_searchParameters.m_useGrandparentDistanceCalculation.m_bool = 1;
  this->m_searchParameters.m_heuristicWeight = 1.0;
  this->m_searchParameters.m_simpleRadiusThreshold = 0.0099999998;
  this->m_searchParameters.m_maximumPathLength = 3.40282e38;
  this->m_searchParameters.m_searchSphereRadius = -1.0;
  this->m_searchParameters.m_searchCapsuleRadius = -1.0;
  this->m_searchParameters.m_bufferSizes = 0i64;
  this->m_searchParameters.m_hierarchyBufferSizes = 0i64;
  *(_DWORD *)this->m_searchParameters.m_up.m_vec = -2147450880;
  this->m_searchParameters.m_up.m_vec[2] = 0x8000;
  this->m_searchBuffers.m_openSetBuffer = 0i64;
  this->m_searchBuffers.m_searchStateBuffer = 0i64;
  this->m_hierarchySearchBuffers.m_openSetBuffer = 0i64;
  this->m_hierarchySearchBuffers.m_searchStateBuffer = 0i64;
  this->m_startPoint = 0i64;
  if ( numGoals > 0 )
  {
    v4 = this->m_goalFaceKeys.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v4 < numGoals )
    {
      v5 = 2 * v4;
      v6 = numGoals;
      if ( numGoals < v5 )
        v6 = v5;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_goalFaceKeys, v6, 4);
    }
    this->m_goalFaceKeys.m_size = numGoals;
    v7 = this->m_goalPoints.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v7 < numGoals )
    {
      v8 = 2 * v7;
      v9 = numGoals;
      if ( numGoals < v8 )
        v9 = v8;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_goalPoints, v9, 16);
    }
    this->m_goalPoints.m_size = numGoals;
  }
}

// File Line: 65
// RVA: 0xBBC820
void __fastcall hkaiPathfindingUtil::FindPathInput::FindPathInput(
        hkaiPathfindingUtil::FindPathInput *this,
        hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPathfindingUtil::FindPathInput::`vftable;
  this->m_searchBuffers.m_openSetBuffer = 0i64;
  this->m_searchBuffers.m_searchStateBuffer = 0i64;
  this->m_hierarchySearchBuffers.m_openSetBuffer = 0i64;
  this->m_hierarchySearchBuffers.m_searchStateBuffer = 0i64;
}

// File Line: 73
// RVA: 0xBBC870
void __fastcall hkaiPathfindingUtil::FindPathOutput::FindPathOutput(
        hkaiPathfindingUtil::FindPathOutput *this,
        hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPathfindingUtil::FindPathOutput::`vftable;
}

// File Line: 84
// RVA: 0xBBC8A0
void __fastcall hkaiPathfindingUtil::NearestFeatureInput::NearestFeatureInput(
        hkaiPathfindingUtil::NearestFeatureInput *this)
{
  this->m_startFaceKey = -1;
  *(_QWORD *)&this->m_maxNumberOfIterations = 100000i64;
  *(_QWORD *)&this->m_bufferSizes.m_maxSearchStateSizeBytes = 0i64;
  this->m_agentInfo.m_filterInfo = 0;
  this->m_costModifier = 0i64;
  this->m_edgeFilter = 0i64;
  this->m_searchRadius = -1.0;
  this->m_projectedRadiusCheck.m_bool = 1;
  this->m_simpleRadiusThreshold = 0.0099999998;
  this->m_startPoint = 0i64;
  this->m_up = 0i64;
}

// File Line: 91
// RVA: 0xBBC8F0
void __fastcall hkaiPathfindingUtil::FindGraphPathInput::FindGraphPathInput(
        hkaiPathfindingUtil::FindGraphPathInput *this)
{
  this->m_startNodeKeys.m_capacityAndFlags = 0x80000000;
  this->m_startNodeKeys.m_data = 0i64;
  this->m_startNodeKeys.m_size = 0;
  this->m_initialCosts.m_data = 0i64;
  this->m_initialCosts.m_size = 0;
  this->m_initialCosts.m_capacityAndFlags = 0x80000000;
  this->m_goalNodeKeys.m_data = 0i64;
  this->m_goalNodeKeys.m_size = 0;
  this->m_goalNodeKeys.m_capacityAndFlags = 0x80000000;
  this->m_finalCosts.m_data = 0i64;
  this->m_finalCosts.m_size = 0;
  this->m_finalCosts.m_capacityAndFlags = 0x80000000;
  *(_QWORD *)&this->m_maxNumberOfIterations = 100000i64;
  this->m_agentInfo.m_filterInfo = 0;
  this->m_searchParameters.m_heuristicWeight = 1.0;
  this->m_searchParameters.m_useHierarchicalHeuristic.m_bool = 1;
  this->m_searchParameters.m_costModifier = 0i64;
  this->m_searchParameters.m_edgeFilter = 0i64;
  this->m_searchParameters.m_bufferSizes = 0i64;
  this->m_searchParameters.m_hierarchyBufferSizes = 0i64;
  this->m_searchBuffers.m_openSetBuffer = 0i64;
  this->m_searchBuffers.m_searchStateBuffer = 0i64;
  this->m_hierarchySearchBuffers.m_openSetBuffer = 0i64;
  this->m_hierarchySearchBuffers.m_searchStateBuffer = 0i64;
}

// File Line: 101
// RVA: 0xBBC980
void __fastcall hkaiPathfindingUtil::FindGraphPathInput::FindGraphPathInput(
        hkaiPathfindingUtil::FindGraphPathInput *this,
        hkFinishLoadedObjectFlag f)
{
  this->m_searchBuffers.m_openSetBuffer = 0i64;
  this->m_searchBuffers.m_searchStateBuffer = 0i64;
  this->m_hierarchySearchBuffers.m_openSetBuffer = 0i64;
  this->m_hierarchySearchBuffers.m_searchStateBuffer = 0i64;
}

// File Line: 105
// RVA: 0xBBC9B0
void __fastcall hkaiPathfindingUtil::FindGraphPathInput::setStartNode(
        hkaiPathfindingUtil::FindGraphPathInput *this,
        unsigned int startNode)
{
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  if ( (this->m_startNodeKeys.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, this, 1, 4);
  this->m_startNodeKeys.m_size = 1;
  *this->m_startNodeKeys.m_data = startNode;
  if ( (this->m_initialCosts.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_initialCosts, 1, 4);
  this->m_initialCosts.m_size = 1;
  *this->m_initialCosts.m_data = 0.0;
}

// File Line: 114
// RVA: 0xBBCBE0
void __fastcall hkaiPathfindingUtil::FindGraphPathInput::setGoalNode(
        hkaiPathfindingUtil::FindGraphPathInput *this,
        unsigned int goalNode)
{
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  if ( (this->m_goalNodeKeys.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_goalNodeKeys, 1, 4);
  this->m_goalNodeKeys.m_size = 1;
  *this->m_goalNodeKeys.m_data = goalNode;
  this->m_finalCosts.m_size = 0;
}

// File Line: 122
// RVA: 0xBBCA60
void __fastcall hkaiPathfindingUtil::FindGraphPathInput::setStartEdge(
        hkaiPathfindingUtil::FindGraphPathInput *this,
        hkaiStreamingCollection *collection,
        unsigned int startNodeKey,
        unsigned int startEdgeKey,
        float fraction)
{
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // rsi
  hkaiDirectedGraphExplicitCost::Edge *GraphEdgeFromPacked; // rdi
  unsigned int m_target; // eax
  unsigned int v11; // ecx
  int v12; // esi
  unsigned int EdgeBetween; // eax
  hkaiDirectedGraphExplicitCost::Edge *v14; // rbp
  int v15; // r9d
  int v16; // r9d
  float v17; // xmm1_4
  float *m_data; // rcx
  hkResult result; // [rsp+60h] [rbp+18h] BYREF

  m_clusterGraphInstance = collection->m_instances.m_data[startNodeKey >> 22].m_clusterGraphInstance;
  GraphEdgeFromPacked = hkaiStreamingCollection::getGraphEdgeFromPacked(collection, startEdgeKey);
  m_target = GraphEdgeFromPacked->m_target;
  if ( (GraphEdgeFromPacked->m_flags.m_storage & 0x40) != 0 )
    v11 = m_target & 0xFFC00000;
  else
    v11 = m_clusterGraphInstance->m_runtimeId << 22;
  v12 = v11 | m_target & 0x3FFFFF;
  if ( m_target == -1 )
    v12 = -1;
  EdgeBetween = hkaiGraphUtils::getEdgeBetween(collection, v12, startNodeKey);
  v14 = hkaiStreamingCollection::getGraphEdgeFromPacked(collection, EdgeBetween);
  if ( (this->m_startNodeKeys.m_capacityAndFlags & 0x3FFFFFFFu) < 2 )
  {
    v15 = 2;
    if ( 2 * (this->m_startNodeKeys.m_capacityAndFlags & 0x3FFFFFFF) > 2 )
      v15 = 2 * (this->m_startNodeKeys.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, this, v15, 4);
  }
  this->m_startNodeKeys.m_size = 2;
  *this->m_startNodeKeys.m_data = startNodeKey;
  this->m_startNodeKeys.m_data[1] = v12;
  if ( (this->m_initialCosts.m_capacityAndFlags & 0x3FFFFFFFu) < 2 )
  {
    v16 = 2;
    if ( 2 * (this->m_initialCosts.m_capacityAndFlags & 0x3FFFFFFF) > 2 )
      v16 = 2 * (this->m_initialCosts.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_initialCosts, v16, 4);
  }
  v17 = fraction;
  this->m_initialCosts.m_size = 2;
  m_data = this->m_initialCosts.m_data;
  result.m_enum = v14->m_cost.m_value << 16;
  *m_data = *(float *)&result.m_enum * v17;
  LODWORD(fraction) = GraphEdgeFromPacked->m_cost.m_value << 16;
  m_data[1] = (float)(1.0 - v17) * fraction;
}

// File Line: 148
// RVA: 0xBBCC60
void __fastcall hkaiPathfindingUtil::FindGraphPathInput::setGoalEdge(
        hkaiPathfindingUtil::FindGraphPathInput *this,
        hkaiStreamingCollection *collection,
        unsigned int goalNodeKey,
        unsigned int goalEdgeKey,
        float fraction)
{
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // rbx
  hkaiDirectedGraphExplicitCost::Edge *GraphEdgeFromPacked; // rdi
  unsigned int m_target; // eax
  unsigned int v11; // ecx
  int v12; // r14d
  unsigned int EdgeBetween; // eax
  hkaiDirectedGraphExplicitCost::Edge *v14; // rsi
  int v15; // r9d
  int v16; // r9d
  float v17; // xmm1_4
  float *m_data; // rcx
  hkResult result; // [rsp+60h] [rbp+18h] BYREF

  m_clusterGraphInstance = collection->m_instances.m_data[goalNodeKey >> 22].m_clusterGraphInstance;
  GraphEdgeFromPacked = hkaiStreamingCollection::getGraphEdgeFromPacked(collection, goalEdgeKey);
  m_target = GraphEdgeFromPacked->m_target;
  if ( (GraphEdgeFromPacked->m_flags.m_storage & 0x40) != 0 )
    v11 = m_target & 0xFFC00000;
  else
    v11 = m_clusterGraphInstance->m_runtimeId << 22;
  v12 = v11 | m_target & 0x3FFFFF;
  if ( m_target == -1 )
    v12 = -1;
  EdgeBetween = hkaiGraphUtils::getEdgeBetween(collection, v12, goalNodeKey);
  v14 = hkaiStreamingCollection::getGraphEdgeFromPacked(collection, EdgeBetween);
  if ( (this->m_goalNodeKeys.m_capacityAndFlags & 0x3FFFFFFFu) < 2 )
  {
    v15 = 2;
    if ( 2 * (this->m_goalNodeKeys.m_capacityAndFlags & 0x3FFFFFFF) > 2 )
      v15 = 2 * (this->m_goalNodeKeys.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_goalNodeKeys, v15, 4);
  }
  this->m_goalNodeKeys.m_size = 2;
  *this->m_goalNodeKeys.m_data = goalNodeKey;
  this->m_goalNodeKeys.m_data[1] = v12;
  if ( (this->m_finalCosts.m_capacityAndFlags & 0x3FFFFFFFu) < 2 )
  {
    v16 = 2;
    if ( 2 * (this->m_finalCosts.m_capacityAndFlags & 0x3FFFFFFF) > 2 )
      v16 = 2 * (this->m_finalCosts.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_finalCosts, v16, 4);
  }
  v17 = fraction;
  this->m_finalCosts.m_size = 2;
  m_data = this->m_finalCosts.m_data;
  result.m_enum = GraphEdgeFromPacked->m_cost.m_value << 16;
  *m_data = *(float *)&result.m_enum * v17;
  LODWORD(fraction) = v14->m_cost.m_value << 16;
  m_data[1] = (float)(1.0 - v17) * fraction;
}

// File Line: 178
// RVA: 0xBBD720
void __fastcall hkaiPathfindingUtil::findPath(
        hkaiNavMesh *navMesh,
        hkaiPathfindingUtil::FindPathInput *input,
        hkaiPathfindingUtil::FindPathOutput *output)
{
  hkaiStreamingCollection::InstanceInfo *m_data; // r8
  __int64 v7; // rdx
  hkaiDirectedGraphInstance **p_m_clusterGraphInstance; // rax
  hkaiStreamingCollection array; // [rsp+30h] [rbp-218h] BYREF
  hkaiNavMeshInstance v10; // [rsp+60h] [rbp-1E8h] BYREF
  hkResult result; // [rsp+268h] [rbp+20h] BYREF

  hkaiNavMeshInstance::hkaiNavMeshInstance(&v10);
  hkaiNavMeshInstance::tempInit(&v10, navMesh, 1);
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array.m_instances, 1, 48);
  m_data = array.m_instances.m_data;
  v7 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    p_m_clusterGraphInstance = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( p_m_clusterGraphInstance != (hkaiDirectedGraphInstance **)16 )
      {
        *(p_m_clusterGraphInstance - 2) = 0i64;
        *(p_m_clusterGraphInstance - 1) = 0i64;
        *p_m_clusterGraphInstance = 0i64;
        p_m_clusterGraphInstance[1] = 0i64;
        p_m_clusterGraphInstance[2] = 0i64;
        *((_DWORD *)p_m_clusterGraphInstance + 6) = -1;
      }
      p_m_clusterGraphInstance += 6;
      --v7;
    }
    while ( v7 );
    m_data = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  m_data->m_instancePtr = &v10;
  array.m_instances.m_data->m_clusterGraphInstance = 0i64;
  array.m_instances.m_data->m_mediator = 0i64;
  hkaiPathfindingUtil::findPath(&array, input, output);
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
  hkaiNavMeshInstance::~hkaiNavMeshInstance(&v10);
}

// File Line: 191
// RVA: 0xBBCDF0
void __fastcall hkaiPathfindingUtil::findPath(
        hkaiStreamingCollection *collection,
        hkaiPathfindingUtil::FindPathInput *input,
        hkaiPathfindingUtil::FindPathOutput *output)
{
  int m_maxOpenSetSizeBytes; // ebx
  char m_storage; // al
  __m128 v8; // xmm1
  int v9; // r12d
  int v10; // r15d
  unsigned int v11; // eax
  int v12; // eax
  _QWORD *Value; // r8
  unsigned __int64 v14; // rcx
  const char *v15; // rax
  unsigned __int64 v16; // rax
  char *m_openSetBuffer; // rdx
  int v18; // r8d
  int m_maxSearchStateSizeBytes; // ebx
  char *v20; // rdx
  int v21; // r8d
  int v22; // ebx
  hkaiStreamingCollection::InstanceInfo *m_data; // rax
  float m_simpleRadiusThreshold; // xmm1_4
  int v25; // ecx
  bool v26; // zf
  bool v27; // zf
  float m_searchSphereRadius; // xmm2_4
  float m_searchCapsuleRadius; // xmm3_4
  int m_size; // eax
  hkVector4f v31; // xmm4
  unsigned int m_startFaceKey; // r8d
  hkVector4f *v33; // r9
  unsigned int *v34; // r10
  int v35; // eax
  hkSimdFloat32 v36; // xmm0
  float m_heuristicWeight; // xmm0_4
  float m_maximumPathLength; // xmm0_4
  int m_maxNumberOfIterations; // r12d
  _QWORD *v40; // r8
  _QWORD *v41; // rcx
  unsigned __int64 v42; // rax
  _QWORD *v43; // rcx
  char v44; // r15
  int v45; // ebx
  hkaiAstarOutputParameters::SearchStatus v46; // eax
  int v47; // ecx
  unsigned int m_bestNode; // ebx
  BOOL v49; // r12d
  _QWORD *v50; // r9
  _QWORD *v51; // rcx
  unsigned __int64 v52; // rax
  _QWORD *v53; // rcx
  hkArray<unsigned int,hkContainerHeapAllocator> *p_m_visitedEdges; // r15
  __m128 m_quad; // xmm0
  unsigned int v56; // edx
  _QWORD *v57; // r8
  _QWORD *v58; // rcx
  unsigned __int64 v59; // rax
  _QWORD *v60; // rcx
  int v61; // r9d
  char v62; // bl
  int m_capacityAndFlags; // eax
  float radius; // xmm6_4
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *pathArrayOut; // r14
  int v66; // eax
  int project; // r12d
  int computeNormals; // ebx
  int v69; // eax
  _QWORD *v70; // r8
  _QWORD *v71; // rcx
  unsigned __int64 v72; // rax
  _QWORD *v73; // rcx
  _QWORD *v74; // r8
  _QWORD *v75; // rcx
  unsigned __int64 v76; // rax
  _QWORD *v77; // rcx
  char v78; // r15
  float v79; // xmm6_4
  int v80; // r9d
  int v81; // eax
  int v82; // r12d
  int v83; // r15d
  int v84; // eax
  hkResult result; // [rsp+70h] [rbp-90h] BYREF
  float v86; // [rsp+78h] [rbp-88h]
  hkaiSearchMemoryStorage hierarchyMemInfo; // [rsp+80h] [rbp-80h] BYREF
  hkaiSearchMemoryStorage memInfo; // [rsp+B8h] [rbp-48h] BYREF
  hkVector4f endPoint; // [rsp+F0h] [rbp-10h] BYREF
  unsigned int validGoalsMask[4]; // [rsp+100h] [rbp+0h] BYREF
  hkVector4f up; // [rsp+110h] [rbp+10h] BYREF
  hkVector4f edgeB; // [rsp+120h] [rbp+20h] BYREF
  hkaiNavMeshSearch::StartGoalInfo goalInfo; // [rsp+130h] [rbp+30h] BYREF
  hkVector4f edgeA; // [rsp+160h] [rbp+60h] BYREF
  hkaiNavMeshSectionGraph graph; // [rsp+170h] [rbp+70h] BYREF
  hkaiNavMeshSearch v96; // [rsp+3B0h] [rbp+2B0h] BYREF
  hkaiSearchParameters::BufferSizes closestGoalIndex; // [rsp+938h] [rbp+838h] BYREF

  if ( !hkaiNavMeshSearchValidationUtils::validateFindPathInput(collection, input, validGoalsMask) )
  {
    output->m_outputParameters.m_goalIndex = -1;
    output->m_outputParameters.m_numIterations = 0;
    output->m_outputParameters.m_status.m_storage = 5;
    return;
  }
  m_maxOpenSetSizeBytes = -1;
  result.m_enum = input->m_goalPoints.m_size;
  m_storage = input->m_searchParameters.m_lineOfSightFlags.m_storage;
  v8 = _mm_cvtepi32_ps(
         _mm_add_epi32(
           _mm_unpacklo_epi16((__m128i)0i64, _mm_loadl_epi64((const __m128i *)&input->m_searchParameters)),
           _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset)));
  closestGoalIndex.m_maxOpenSetSizeBytes = -1;
  v9 = 1;
  up.m_quad = _mm_mul_ps(v8, (__m128)xmmword_141A713A0);
  if ( (m_storage & 4) != 0 || (m_storage & 1) != 0 && !input->m_searchParameters.m_costModifier )
  {
    v10 = 1;
    v11 = hkaiPathfindingUtil::_checkInitialFace(collection, input, (int *)&closestGoalIndex);
    m_maxOpenSetSizeBytes = closestGoalIndex.m_maxOpenSetSizeBytes;
    if ( v11 )
      goto LABEL_9;
  }
  else
  {
    v10 = 0;
  }
  v9 = 0;
  if ( !v10 )
  {
LABEL_11:
    v12 = 0;
    goto LABEL_12;
  }
LABEL_9:
  if ( !hkaiPathfindingUtil::checkLineOfSight(collection, input, m_maxOpenSetSizeBytes, output) )
    goto LABEL_11;
  v12 = 1;
LABEL_12:
  if ( !v9 && !v12 )
  {
    if ( input->m_searchParameters.m_useHierarchicalHeuristic.m_bool )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v14 = Value[1];
      if ( v14 < Value[3] )
      {
        v15 = "LtHierarchyFindPath";
LABEL_19:
        *(_QWORD *)v14 = v15;
        *(_QWORD *)(v14 + 16) = "Stinit";
        v16 = __rdtsc();
        *(_DWORD *)(v14 + 8) = v16;
        Value[1] = v14 + 24;
      }
    }
    else
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v14 = Value[1];
      if ( v14 < Value[3] )
      {
        v15 = "LtFindPath";
        goto LABEL_19;
      }
    }
    hierarchyMemInfo.m_openSetStorage.m_data = 0i64;
    hierarchyMemInfo.m_openSetStorage.m_size = 0;
    hierarchyMemInfo.m_openSetStorage.m_capacityAndFlags = 0x80000000;
    hierarchyMemInfo.m_searchStateStorage.m_data = 0i64;
    hierarchyMemInfo.m_searchStateStorage.m_size = 0;
    hierarchyMemInfo.m_searchStateStorage.m_capacityAndFlags = 0x80000000;
    if ( input->m_searchParameters.m_useHierarchicalHeuristic.m_bool )
    {
      m_openSetBuffer = input->m_hierarchySearchBuffers.m_openSetBuffer;
      closestGoalIndex = input->m_searchParameters.m_hierarchyBufferSizes;
      v18 = closestGoalIndex.m_maxOpenSetSizeBytes;
      m_maxSearchStateSizeBytes = closestGoalIndex.m_maxSearchStateSizeBytes;
      if ( closestGoalIndex.m_maxOpenSetSizeBytes <= 0 )
        v18 = 0x8000;
      if ( closestGoalIndex.m_maxSearchStateSizeBytes <= 0 )
        m_maxSearchStateSizeBytes = 147968;
      hkaiSearchMemoryStorage::_setupArray(&hierarchyMemInfo.m_openSetStorage, m_openSetBuffer, v18);
      hkaiSearchMemoryStorage::_setupArray(
        &hierarchyMemInfo.m_searchStateStorage,
        input->m_hierarchySearchBuffers.m_searchStateBuffer,
        m_maxSearchStateSizeBytes);
      hierarchyMemInfo.m_openSetBuffer = hierarchyMemInfo.m_openSetStorage.m_data;
      hierarchyMemInfo.m_openSetSize = hierarchyMemInfo.m_openSetStorage.m_capacityAndFlags & 0x3FFFFFFF;
      hierarchyMemInfo.m_searchStateBuffer = hierarchyMemInfo.m_searchStateStorage.m_data;
      hierarchyMemInfo.m_searchStateSize = hierarchyMemInfo.m_searchStateStorage.m_capacityAndFlags & 0x3FFFFFFF;
    }
    else
    {
      memset(&hierarchyMemInfo, 0, 24);
    }
    v20 = input->m_searchBuffers.m_openSetBuffer;
    closestGoalIndex = input->m_searchParameters.m_bufferSizes;
    v21 = closestGoalIndex.m_maxOpenSetSizeBytes;
    v22 = closestGoalIndex.m_maxSearchStateSizeBytes;
    memInfo.m_openSetStorage.m_data = 0i64;
    if ( closestGoalIndex.m_maxOpenSetSizeBytes <= 0 )
      v21 = 0x20000;
    memInfo.m_openSetStorage.m_size = 0;
    memInfo.m_openSetStorage.m_capacityAndFlags = 0x80000000;
    memInfo.m_searchStateStorage.m_data = 0i64;
    if ( closestGoalIndex.m_maxSearchStateSizeBytes <= 0 )
      v22 = 590336;
    memInfo.m_searchStateStorage.m_size = 0;
    memInfo.m_searchStateStorage.m_capacityAndFlags = 0x80000000;
    hkaiSearchMemoryStorage::_setupArray(&memInfo.m_openSetStorage, v20, v21);
    hkaiSearchMemoryStorage::_setupArray(&memInfo.m_searchStateStorage, input->m_searchBuffers.m_searchStateBuffer, v22);
    memInfo.m_openSetBuffer = memInfo.m_openSetStorage.m_data;
    memInfo.m_openSetSize = memInfo.m_openSetStorage.m_capacityAndFlags & 0x3FFFFFFF;
    memInfo.m_searchStateBuffer = memInfo.m_searchStateStorage.m_data;
    memInfo.m_searchStateSize = memInfo.m_searchStateStorage.m_capacityAndFlags & 0x3FFFFFFF;
    hkaiNavMeshSearch::hkaiNavMeshSearch(&v96, &memInfo, &hierarchyMemInfo);
    m_data = collection->m_instances.m_data;
    m_simpleRadiusThreshold = input->m_searchParameters.m_simpleRadiusThreshold;
    graph.m_up = (hkVector4f)up.m_quad;
    graph.m_streamingInfo = m_data;
    v25 = 0;
    v26 = input->m_searchParameters.m_useGrandparentDistanceCalculation.m_bool == 0;
    graph.m_costModifier = input->m_searchParameters.m_costModifier;
    graph.m_edgeFilter = input->m_searchParameters.m_edgeFilter;
    graph.m_info = input->m_agentInfo;
    *(_QWORD *)&graph.m_cachedIncomingEdge.m_oppositeEdge = -1i64;
    *(_DWORD *)&graph.m_cachedIncomingEdge.m_flags.m_storage = 4;
    *(_QWORD *)&graph.m_cachedOutgoingEdge.m_oppositeEdge = -1i64;
    *(_DWORD *)&graph.m_cachedOutgoingEdge.m_flags.m_storage = 4;
    *(_QWORD *)&graph.m_cachedOppositeEdge.m_oppositeEdge = -1i64;
    *(_DWORD *)&graph.m_cachedOppositeEdge.m_flags.m_storage = 4;
    graph.m_cachedEdgePairInfo.m_incomingEdgeInfo.m_edgeKey = -1;
    graph.m_cachedEdgePairInfo.m_incomingEdgeInfo.m_edge = 0i64;
    graph.m_cachedEdgePairInfo.m_outgoingEdgeInfo.m_edgeKey = -1;
    graph.m_cachedEdgePairInfo.m_outgoingEdgeInfo.m_edge = 0i64;
    graph.m_cachedEdgePairInfo.m_faceKey = -1;
    graph.m_cachedEdgePairInfo.m_face = 0i64;
    graph.m_cachedIncomingNavMesh = 0i64;
    graph.m_cachedOutgoingNavMesh = 0i64;
    *(_QWORD *)&graph.m_cachedIncomingSectionId = -1i64;
    if ( graph.m_info.m_diameter > (float)(m_simpleRadiusThreshold * 2.0) )
    {
      v25 = 4;
      if ( input->m_searchParameters.m_userEdgeTraversalTestType.m_storage == 1 )
        v25 = 12;
    }
    if ( !v26 )
      v25 |= 0x20u;
    v27 = input->m_searchParameters.m_projectedRadiusCheck.m_bool == 0;
    m_searchSphereRadius = input->m_searchParameters.m_searchSphereRadius;
    m_searchCapsuleRadius = input->m_searchParameters.m_searchCapsuleRadius;
    m_size = input->m_goalPoints.m_size;
    v31.m_quad = (__m128)input->m_startPoint;
    m_startFaceKey = input->m_startFaceKey;
    graph.m_startPoint = (hkVector4f)v31.m_quad;
    *(float *)&closestGoalIndex.m_maxOpenSetSizeBytes = m_searchSphereRadius;
    v86 = m_searchCapsuleRadius;
    v33 = input->m_goalPoints.m_data;
    v34 = input->m_goalFaceKeys.m_data;
    graph.m_searchSphereRadius.m_real = _mm_shuffle_ps(
                                          (__m128)LODWORD(m_searchSphereRadius),
                                          (__m128)LODWORD(m_searchSphereRadius),
                                          0);
    graph.m_numGoals = m_size;
    v35 = 0;
    graph.m_startFaceKey = m_startFaceKey;
    v36.m_real = _mm_shuffle_ps((__m128)LODWORD(m_searchCapsuleRadius), (__m128)LODWORD(m_searchCapsuleRadius), 0);
    if ( m_searchSphereRadius >= 0.0 )
      v35 = 1;
    graph.m_endPoints = v33;
    graph.m_endFaceKeys = v34;
    graph.m_searchCapsuleRadius = (hkSimdFloat32)v36.m_real;
    if ( m_searchCapsuleRadius >= 0.0 )
      v35 |= 2u;
    if ( !v27 )
      v35 |= 0x10u;
    m_heuristicWeight = input->m_searchParameters.m_heuristicWeight;
    goalInfo.m_startFaceKey = m_startFaceKey;
    v26 = input->m_searchParameters.m_useHierarchicalHeuristic.m_bool == 0;
    v96.m_state.m_heuristicWeight = m_heuristicWeight;
    m_maximumPathLength = input->m_searchParameters.m_maximumPathLength;
    goalInfo.m_startPoint = (hkVector4f)v31.m_quad;
    v96.m_state.m_maxPathCost = m_maximumPathLength;
    v96.m_graph.m_storage = &graph;
    graph.m_flags = v35 | v25 & 0xFFFFFFEC;
    graph.m_searchState = &v96.m_state;
    goalInfo.m_goalPoints = v33;
    goalInfo.m_numGoals = result.m_enum;
    goalInfo.m_goalFaceKeys = v34;
    hkaiNavMeshSearch::init(&v96, &graph, &input->m_agentInfo, &goalInfo, !v26);
    m_maxNumberOfIterations = input->m_maxNumberOfIterations;
    v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v41 = (_QWORD *)v40[1];
    if ( (unsigned __int64)v41 < v40[3] )
    {
      *v41 = "StAStar";
      v42 = __rdtsc();
      v43 = v41 + 2;
      *((_DWORD *)v43 - 2) = v42;
      v40[1] = v43;
    }
    v44 = 0;
    v45 = 0;
    while ( v45 < m_maxNumberOfIterations )
    {
      ++v45;
      v46 = hkaiNavMeshSearch::iteration(&v96);
      v47 = v46;
      if ( v46 == SEARCH_TERMINATED )
      {
        v44 = (v96.m_openset.m_heapSize < v96.m_openset.m_maxSize) + 2;
        goto LABEL_51;
      }
      if ( v46 )
        goto LABEL_51;
    }
    v47 = 3;
    v44 = 1;
LABEL_51:
    output->m_outputParameters.m_numIterations = v45;
    output->m_outputParameters.m_status.m_storage = v47;
    output->m_outputParameters.m_terminationCause.m_storage = v44;
    output->m_outputParameters.m_goalIndex = -1;
    if ( ((v47 - 1) & 0xFFFFFFFD) != 0 )
      goto LABEL_71;
    m_bestNode = v96.m_state.m_bestNode;
    v49 = v47 == 1;
    output->m_outputParameters.m_goalIndex = v96.m_goalFoundIndex;
    if ( v47 == 1 )
      m_bestNode = v96.m_lastClosedNode;
    v96.m_state.m_currentNodeState = hkaiHashSearchState::getNodeState(&v96.m_state, m_bestNode);
    v96.m_state.m_parentNodeState = v96.m_state.m_currentNodeState;
    v96.m_state.m_parentIndex = (__int16)(v96.m_state.m_currentNodeState - v96.m_state.m_nodes);
    output->m_outputParameters.m_pathLength = v96.m_state.m_currentNodeState->m_gCost;
    v50 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v51 = (_QWORD *)v50[1];
    if ( (unsigned __int64)v51 < v50[3] )
    {
      *v51 = "Stoutput";
      v52 = __rdtsc();
      v53 = v51 + 2;
      *((_DWORD *)v53 - 2) = v52;
      v50[1] = v53;
    }
    p_m_visitedEdges = &output->m_visitedEdges;
    hkaiSearchStateUtils::getPath(
      &v96.m_state,
      m_bestNode,
      GET_PATH_IGNORE_START_AND_END,
      &output->m_visitedEdges,
      0x7FFFFFFF);
    if ( v49 )
    {
      m_quad = input->m_goalPoints.m_data[output->m_outputParameters.m_goalIndex].m_quad;
    }
    else
    {
      if ( output->m_visitedEdges.m_size )
      {
        v56 = output->m_visitedEdges.m_data[output->m_visitedEdges.m_size - 1];
        hkaiNavMeshInstance::getEdgePoints(
          collection->m_instances.m_data[v56 >> 22].m_instancePtr,
          v56 & 0x3FFFFF,
          &edgeA,
          &edgeB);
        endPoint.m_quad = _mm_add_ps(
                            _mm_mul_ps(_mm_sub_ps(edgeB.m_quad, edgeA.m_quad), (__m128)xmmword_141A711B0),
                            edgeA.m_quad);
        goto LABEL_62;
      }
      m_quad = input->m_startPoint.m_quad;
    }
    endPoint.m_quad = m_quad;
LABEL_62:
    if ( (input->m_searchParameters.m_outputPathFlags.m_storage & 1) != 0 )
    {
      v57 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v58 = (_QWORD *)v57[1];
      if ( (unsigned __int64)v58 < v57[3] )
      {
        *v58 = "Ttsmooth";
        v59 = __rdtsc();
        v60 = v58 + 2;
        *((_DWORD *)v60 - 2) = v59;
        v57[1] = v60;
      }
      v61 = output->m_visitedEdges.m_size;
      v62 = input->m_searchParameters.m_outputPathFlags.m_storage;
      m_capacityAndFlags = output->m_pathOut.m_capacityAndFlags;
      radius = input->m_agentInfo.m_diameter * 0.5;
      LOBYTE(closestGoalIndex.m_maxOpenSetSizeBytes) = radius <= input->m_searchParameters.m_simpleRadiusThreshold;
      pathArrayOut = &output->m_pathOut;
      v66 = m_capacityAndFlags & 0x3FFFFFFF;
      project = v62 & 2;
      computeNormals = v62 & 4;
      if ( v66 < v61 )
      {
        v69 = 2 * v66;
        if ( v61 < v69 )
          v61 = v69;
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, pathArrayOut, v61, 48);
      }
      hkaiNavMeshPathSmoothingUtil::findSmoothedPathMain(
        collection->m_instances.m_data,
        p_m_visitedEdges,
        input->m_startFaceKey,
        &input->m_startPoint,
        &endPoint,
        project,
        computeNormals,
        &up,
        radius,
        closestGoalIndex.m_maxOpenSetSizeBytes,
        pathArrayOut,
        0i64,
        0,
        0i64);
      v70 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v71 = (_QWORD *)v70[1];
      if ( (unsigned __int64)v71 < v70[3] )
      {
        *v71 = "Et";
        v72 = __rdtsc();
        v73 = v71 + 2;
        *((_DWORD *)v73 - 2) = v72;
        v70[1] = v73;
      }
    }
LABEL_71:
    v74 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v75 = (_QWORD *)v74[1];
    if ( (unsigned __int64)v75 < v74[3] )
    {
      *v75 = "lt";
      v76 = __rdtsc();
      v77 = v75 + 2;
      *((_DWORD *)v77 - 2) = v76;
      v74[1] = v77;
    }
    hkaiSearchMemoryStorage::~hkaiSearchMemoryStorage(&memInfo);
    hkaiSearchMemoryStorage::~hkaiSearchMemoryStorage(&hierarchyMemInfo);
    return;
  }
  output->m_outputParameters.m_status.m_storage = 1;
  output->m_outputParameters.m_numIterations = 0;
  output->m_outputParameters.m_goalIndex = m_maxOpenSetSizeBytes;
  if ( (input->m_searchParameters.m_outputPathFlags.m_storage & 1) != 0 )
  {
    v78 = input->m_searchParameters.m_outputPathFlags.m_storage;
    v79 = input->m_agentInfo.m_diameter * 0.5;
    v80 = output->m_visitedEdges.m_size + 2;
    v81 = output->m_pathOut.m_capacityAndFlags & 0x3FFFFFFF;
    v82 = v78 & 2;
    v83 = v78 & 4;
    if ( v81 < v80 )
    {
      v84 = 2 * v81;
      if ( v80 < v84 )
        v80 = v84;
      hkArrayUtil::_reserve(
        (hkResult *)&closestGoalIndex,
        &hkContainerHeapAllocator::s_alloc,
        &output->m_pathOut,
        v80,
        48);
    }
    hkaiNavMeshPathSmoothingUtil::projectStraightPath(
      collection->m_instances.m_data,
      &output->m_visitedEdges,
      input->m_startFaceKey,
      &input->m_startPoint,
      &input->m_goalPoints.m_data[m_maxOpenSetSizeBytes],
      v82,
      v83,
      &up,
      v79,
      &output->m_pathOut,
      0i64,
      0);
  }
}

// File Line: 436
// RVA: 0xBBDAA0
_BOOL8 __fastcall hkaiPathfindingUtil::_checkInitialFace(
        hkaiStreamingCollection *collection,
        hkaiPathfindingUtil::FindPathInput *input,
        int *closestGoalIndex)
{
  __m128 m_quad; // xmm0
  int m_size; // edx
  hkVector4f *m_data; // rcx
  int v9; // eax
  unsigned int m_startFaceKey; // ebx
  __int64 v11; // rdx
  hkVector4f v12; // xmm0
  hkaiNavMeshInstance *m_instancePtr; // r11
  hkVector4f *v14; // rax
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rbp
  hkaiNavMesh::Face *v16; // rax
  hkArray<int,hkContainerHeapAllocator> *v17; // r11
  int striding; // ecx
  __int64 v19; // r15
  int *v20; // rax
  hkaiAstarEdgeFilter *m_edgeFilter; // rcx
  hkVector4UtilImpl<float>::DistanceToPoint evalFunc; // [rsp+40h] [rbp-B8h] BYREF
  int *v24; // [rsp+50h] [rbp-A8h]
  char v25; // [rsp+58h] [rbp-A0h]
  int v26; // [rsp+60h] [rbp-98h] BYREF
  __int64 v27; // [rsp+68h] [rbp-90h]
  __int64 v28; // [rsp+70h] [rbp-88h]
  __m128 v29; // [rsp+80h] [rbp-78h]
  int v30; // [rsp+90h] [rbp-68h]
  __int64 v31; // [rsp+98h] [rbp-60h]
  __int64 v32; // [rsp+A0h] [rbp-58h]
  hkVector4f v33; // [rsp+B0h] [rbp-48h]
  unsigned int v34; // [rsp+C0h] [rbp-38h]
  __int64 v35; // [rsp+C8h] [rbp-30h]
  int *v36; // [rsp+D0h] [rbp-28h]

  m_quad = input->m_startPoint.m_quad;
  m_size = input->m_goalPoints.m_size;
  m_data = input->m_goalPoints.m_data;
  evalFunc.m_p.m_quad = m_quad;
  v9 = hkAlgorithm::findMinimumIndex<hkVector4f,hkVector4UtilImpl<float>::DistanceToPoint>(m_data, m_size, &evalFunc);
  *closestGoalIndex = v9;
  m_startFaceKey = input->m_startFaceKey;
  v11 = v9;
  if ( m_startFaceKey != input->m_goalFaceKeys.m_data[v9] )
    return 0i64;
  v12.m_quad = (__m128)input->m_startPoint;
  m_instancePtr = collection->m_instances.m_data[m_startFaceKey >> 22].m_instancePtr;
  v14 = input->m_goalPoints.m_data;
  v34 = -1;
  v29 = v12.m_quad;
  v35 = 0i64;
  v26 = -1;
  v27 = 0i64;
  v28 = 0i64;
  v30 = -1;
  v31 = 0i64;
  v32 = 0i64;
  instanceMap = &m_instancePtr->m_faceMap;
  v33.m_quad = (__m128)v14[v11];
  v16 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__2(
          m_instancePtr->m_originalFaces,
          m_instancePtr->m_numOriginalFaces,
          &m_instancePtr->m_instancedFaces,
          &m_instancePtr->m_ownedFaces,
          &m_instancePtr->m_faceMap,
          m_startFaceKey & 0x3FFFFF);
  striding = v17[4].m_size;
  v19 = (__int64)v16;
  v20 = striding
      ? hkaiNavMeshInstance_getWithStriding_int__0(
          v17[4].m_data,
          v17[1].m_size,
          v17 + 22,
          v17 + 24,
          instanceMap,
          m_startFaceKey & 0x3FFFFF,
          striding)
      : 0i64;
  v36 = v20;
  v24 = &v26;
  m_edgeFilter = input->m_searchParameters.m_edgeFilter;
  v35 = v19;
  v34 = m_startFaceKey;
  evalFunc.m_p.m_quad.m128_u64[0] = (unsigned __int64)v17;
  evalFunc.m_p.m_quad.m128_u64[1] = (unsigned __int64)&input->m_agentInfo;
  v25 = 17;
  return !m_edgeFilter
      || ((unsigned __int8 (__fastcall *)(hkaiAstarEdgeFilter *, hkVector4UtilImpl<float>::DistanceToPoint *))m_edgeFilter->vfptr[2].__first_virtual_table_function__)(
           m_edgeFilter,
           &evalFunc);
}

// File Line: 472
// RVA: 0xBBD870
bool __fastcall hkaiPathfindingUtil::checkLineOfSight(
        hkaiStreamingCollection *navMeshCollection,
        hkaiPathfindingUtil::FindPathInput *input,
        int goalIndex,
        hkaiPathfindingUtil::FindPathOutput *output)
{
  __int64 v6; // rbx
  hkVector4f *m_data; // rax
  hkVector4f v9; // xmm0
  unsigned int *v10; // rax
  unsigned int v11; // ecx
  hkaiAgentTraversalInfo m_agentInfo; // rax
  hkaiStreamingCollection::InstanceInfo *v13; // rcx
  unsigned int v14; // eax
  unsigned int v15; // ebx
  int m_size; // edx
  unsigned int *v17; // r9
  unsigned int *v18; // r10
  __int64 v19; // rcx
  unsigned int v20; // eax
  float m_accumulatedDistance; // xmm0_4
  hkaiLineOfSightUtil::LineOfSightInput inputa; // [rsp+20h] [rbp-79h] BYREF
  hkaiLineOfSightUtil::LineOfSightOutput outputa; // [rsp+90h] [rbp-9h] BYREF
  int v25; // [rsp+110h] [rbp+77h] BYREF

  v6 = goalIndex;
  hkaiLineOfSightUtil::LineOfSightInput::LineOfSightInput(&inputa);
  m_data = input->m_goalPoints.m_data;
  inputa.m_startPoint = input->m_startPoint;
  v9.m_quad = (__m128)m_data[v6];
  inputa.m_startFaceKey = input->m_startFaceKey;
  v10 = input->m_goalFaceKeys.m_data;
  inputa.m_goalPoint = (hkVector4f)v9.m_quad;
  v9.m_quad.m128_i32[0] = LODWORD(input->m_searchParameters.m_searchSphereRadius);
  inputa.m_up.m_quad = _mm_mul_ps(
                         _mm_cvtepi32_ps(
                           _mm_add_epi32(
                             _mm_unpacklo_epi16(
                               (__m128i)0i64,
                               _mm_loadl_epi64((const __m128i *)&input->m_searchParameters)),
                             _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset))),
                         (__m128)xmmword_141A713A0);
  v11 = v10[v6];
  inputa.m_maxNumberOfIterations = input->m_maxNumberOfIterations;
  m_agentInfo = input->m_agentInfo;
  LODWORD(inputa.m_searchRadius) = v9.m_quad.m128_i32[0];
  inputa.m_maximumPathLength = input->m_searchParameters.m_maximumPathLength;
  inputa.m_agentInfo = m_agentInfo;
  LOBYTE(m_agentInfo.m_diameter) = input->m_searchParameters.m_projectedRadiusCheck.m_bool;
  inputa.m_goalFaceKey = v11;
  inputa.m_projectedRadiusCheck.m_bool = LOBYTE(m_agentInfo.m_diameter);
  inputa.m_costModifier = input->m_searchParameters.m_costModifier;
  inputa.m_edgeFilter = input->m_searchParameters.m_edgeFilter;
  inputa.m_exactInternalVertexHandling.m_bool = (input->m_searchParameters.m_lineOfSightFlags.m_storage & 2) != 0;
  hkaiLineOfSightUtil::LineOfSightOutput::LineOfSightOutput(&outputa);
  v13 = navMeshCollection->m_instances.m_data;
  outputa.m_doNotExceedArrayCapacity.m_bool = 0;
  v14 = hkaiLineOfSightUtil::checkLineOfSight(v13, &inputa, &outputa);
  v15 = v14;
  if ( output )
  {
    m_size = outputa.m_visitedEdgesOut.m_size;
    output->m_outputParameters.m_status.m_storage = (v14 == 0) + 1;
    if ( (output->m_visitedEdges.m_capacityAndFlags & 0x3FFFFFFF) < m_size )
    {
      if ( output->m_visitedEdges.m_capacityAndFlags >= 0 )
      {
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          output->m_visitedEdges.m_data,
          4 * output->m_visitedEdges.m_capacityAndFlags);
        m_size = outputa.m_visitedEdgesOut.m_size;
      }
      v25 = 4 * m_size;
      output->m_visitedEdges.m_data = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                        &hkContainerHeapAllocator::s_alloc,
                                                        &v25);
      m_size = outputa.m_visitedEdgesOut.m_size;
      output->m_visitedEdges.m_capacityAndFlags = v25 / 4;
    }
    v17 = outputa.m_visitedEdgesOut.m_data;
    v18 = output->m_visitedEdges.m_data;
    v19 = 0i64;
    for ( output->m_visitedEdges.m_size = m_size; v19 < m_size; v18[v19 - 1] = v20 )
      v20 = v17[v19++];
    if ( v15 )
      m_accumulatedDistance = outputa.m_accumulatedDistance;
    else
      m_accumulatedDistance = output->m_outputParameters.m_pathLength;
    output->m_outputParameters.m_pathLength = m_accumulatedDistance;
  }
  hkaiLineOfSightUtil::LineOfSightOutput::~LineOfSightOutput(&outputa);
  return v15 != 0;
}

// File Line: 509
// RVA: 0xBBDA60
void __fastcall hkaiPathfindingUtil::findNearestEdges(
        hkaiStreamingCollection *navMeshCollection,
        hkaiPathfindingUtil::NearestFeatureInput *input,
        hkaiPathfindingUtil::NearestFeatureCallback *callback,
        hkaiAstarOutputParameters *output)
{
  hkaiPathfindingUtil::_findNearestFeature(navMeshCollection, input, callback, CALLBACK_EDGE, output);
}

// File Line: 514
// RVA: 0xBBDA80
void __fastcall hkaiPathfindingUtil::findNearestFaces(
        hkaiStreamingCollection *navMeshCollection,
        hkaiPathfindingUtil::NearestFeatureInput *input,
        hkaiPathfindingUtil::NearestFeatureCallback *callback,
        hkaiAstarOutputParameters *output)
{
  hkaiPathfindingUtil::_findNearestFeature(navMeshCollection, input, callback, CALLBACK_FACE, output);
}

// File Line: 534
// RVA: 0xBBF190
hkSimdFloat32 *__fastcall FaceCallbackCostModifierWrapper::getModifiedCost(
        FaceCallbackCostModifierWrapper *this,
        hkSimdFloat32 *result,
        hkaiAstarCostModifier::NavMeshGetModifiedCostCallbackContext *context)
{
  hkaiNavMeshEdgePairInfo *m_edgeFaceInfo; // rax
  int v5; // r8d
  unsigned int m_oppositeFace; // ebx
  unsigned int *m_data; // r8
  int v10; // r9d
  int v11; // r10d
  int v12; // ecx
  unsigned int v13; // edx
  hkaiAstarCostModifier *m_costModifier; // rcx
  hkResult resulta; // [rsp+40h] [rbp+8h] BYREF

  m_edgeFaceInfo = context->m_edgeFaceInfo;
  v5 = this->m_visitedFaceKeys.m_elem.m_size - 1;
  m_oppositeFace = m_edgeFaceInfo->m_outgoingEdgeInfo.m_edge->m_oppositeFace;
  if ( 2 * this->m_visitedFaceKeys.m_numElems > v5 )
    hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
      &this->m_visitedFaceKeys,
      &resulta,
      2 * v5 + 2);
  m_data = this->m_visitedFaceKeys.m_elem.m_data;
  v10 = this->m_visitedFaceKeys.m_elem.m_size - 1;
  v11 = 1;
  v12 = v10 & (-1640531535 * (m_oppositeFace >> 4));
  v13 = m_data[v12];
  if ( v13 != -1 )
  {
    while ( v13 != m_oppositeFace )
    {
      v12 = v10 & (v12 + 1);
      v13 = m_data[v12];
      if ( v13 == -1 )
        goto LABEL_8;
    }
    v11 = 0;
  }
LABEL_8:
  this->m_visitedFaceKeys.m_numElems += v11;
  m_data[v12] = m_oppositeFace;
  if ( v11 )
    this->m_callback->vfptr->faceTraversed(this->m_callback, m_oppositeFace, context->m_agentInfo);
  m_costModifier = this->m_costModifier;
  if ( m_costModifier )
    ((void (__fastcall *)(hkaiAstarCostModifier *, hkSimdFloat32 *, hkaiAstarCostModifier::NavMeshGetModifiedCostCallbackContext *))m_costModifier->vfptr[2].__first_virtual_table_function__)(
      m_costModifier,
      result,
      context);
  else
    *result = context->m_originalCost;
  return result;
}

// File Line: 556
// RVA: 0xBBF280
hkSimdFloat32 *__fastcall FaceCallbackCostModifierWrapper::getModifiedCost(
        FaceCallbackCostModifierWrapper *this,
        hkSimdFloat32 *result,
        hkaiAstarCostModifier::NavVolumeGetModifiedCostCallbackContext *context)
{
  hkaiAstarCostModifier::getModifiedCost(this, result, context);
  return result;
}

// File Line: 561
// RVA: 0xBBF170
hkSimdFloat32 *__fastcall FaceCallbackCostModifierWrapper::getModifiedCost(
        FaceCallbackCostModifierWrapper *this,
        hkSimdFloat32 *result,
        hkaiAstarCostModifier::DirectedGraphGetModifiedCostCallbackContext *context)
{
  hkaiAstarCostModifier::getModifiedCost(this, result, context);
  return result;
}

// File Line: 586
// RVA: 0xBBF2B0
char __fastcall FaceCallbackEdgeFilterWrapper::isEnabled(
        FaceCallbackEdgeFilterWrapper *this,
        hkaiAstarEdgeFilter::NavMeshIsEnabledCallbackContext *context)
{
  hkaiAstarEdgeFilter *m_edgeFilter; // rcx
  char v5; // si
  hkaiNavMesh::Edge *m_edge; // rdx
  hkVector4f v7; // xmm7
  __m128 m_quad; // xmm6
  __m128 v9; // xmm4
  hkVector4f v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm6
  __m128 v18; // xmm5
  __m128 v19; // xmm1
  __m128 v20; // xmm4
  __m128 v21; // xmm1
  __m128 v22; // xmm0
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm6
  __m128 v26; // xmm6
  hkVector4f edgeB; // [rsp+20h] [rbp-58h] BYREF
  hkVector4f edgeA; // [rsp+30h] [rbp-48h] BYREF

  m_edgeFilter = this->m_edgeFilter;
  v5 = 1;
  if ( m_edgeFilter )
  {
    v5 = ((__int64 (__fastcall *)(hkaiAstarEdgeFilter *))m_edgeFilter->vfptr[2].__first_virtual_table_function__)(m_edgeFilter);
    if ( !v5 )
      return v5;
  }
  m_edge = context->m_edgeFaceInfo->m_outgoingEdgeInfo.m_edge;
  if ( !m_edge || COERCE_FLOAT(*(_OWORD *)&this->m_searchSphereRadius) <= 0.0 )
    return v5;
  v7.m_quad = (__m128)this->m_startPoint;
  hkaiNavMeshInstance::getEdgePoints(context->m_meshAccessor, m_edge, &edgeA, &edgeB);
  m_quad = edgeA.m_quad;
  v9 = edgeB.m_quad;
  if ( this->m_projectedRadiusCheck )
  {
    v10.m_quad = (__m128)this->m_up;
    v11 = _mm_mul_ps(v10.m_quad, v7.m_quad);
    v12 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170));
    v13 = _mm_mul_ps(v10.m_quad, edgeA.m_quad);
    v7.m_quad = _mm_sub_ps(v7.m_quad, _mm_mul_ps(v12, v10.m_quad));
    v14 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170));
    v15 = _mm_mul_ps(v10.m_quad, edgeB.m_quad);
    m_quad = _mm_sub_ps(edgeA.m_quad, _mm_mul_ps(v14, v10.m_quad));
    v9 = _mm_sub_ps(
           edgeB.m_quad,
           _mm_mul_ps(
             _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
               _mm_shuffle_ps(v15, v15, 170)),
             v10.m_quad));
  }
  v16 = m_quad;
  v17 = _mm_sub_ps(m_quad, v7.m_quad);
  v18 = _mm_sub_ps(v16, v9);
  v19 = _mm_mul_ps(v18, v18);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_mul_ps(v17, v18);
  v22 = _mm_rcp_ps(v20);
  v23 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v20, v22)), v22),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
            _mm_shuffle_ps(v21, v21, 170)));
  v24 = _mm_cmplt_ps(v23, query.m_quad);
  v25 = _mm_sub_ps(
          v17,
          _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v23, v24), _mm_andnot_ps(v24, query.m_quad))), v18));
  v26 = _mm_mul_ps(v25, v25);
  if ( (float)((float)(_mm_shuffle_ps(v26, v26, 85).m128_f32[0] + _mm_shuffle_ps(v26, v26, 0).m128_f32[0])
             + _mm_shuffle_ps(v26, v26, 170).m128_f32[0]) > (float)(this->m_searchSphereRadius.m_real.m128_f32[0]
                                                                  * this->m_searchSphereRadius.m_real.m128_f32[0]) )
    return 0;
  else
    return v5;
}

// File Line: 622
// RVA: 0xBBF480
// attributes: thunk
bool __fastcall FaceCallbackEdgeFilterWrapper::isEnabled(
        FaceCallbackEdgeFilterWrapper *this,
        hkaiAstarEdgeFilter::NavVolumeIsEnabledCallbackContext *context)
{
  return hkaiAstarEdgeFilter::isEnabled(this, context);
}

// File Line: 627
// RVA: 0xBBF2A0
// attributes: thunk
bool __fastcall hkaiDefaultAstarEdgeFilter::isEnabled(
        FaceCallbackEdgeFilterWrapper *this,
        hkaiAstarEdgeFilter::DirectedGraphIsEnabledCallbackContext *context)
{
  return hkaiAstarEdgeFilter::isEnabled(this, context);
}

// File Line: 640
// RVA: 0xBBE590
void __fastcall hkaiPathfindingUtil::_findNearestFeature(
        hkaiStreamingCollection *navMeshCollection,
        hkaiPathfindingUtil::NearestFeatureInput *input,
        hkaiPathfindingUtil::NearestFeatureCallback *callback,
        hkaiPathfindingUtil::NearestFeatureType callbackType,
        hkaiAstarOutputParameters *output)
{
  _QWORD *v9; // r9
  unsigned __int64 v10; // r8
  unsigned __int64 v11; // rax
  _QWORD *Value; // r8
  unsigned __int64 v13; // rcx
  unsigned __int64 v14; // rax
  int m_maxOpenSetSizeBytes; // r8d
  int m_maxSearchStateSizeBytes; // ebx
  char m_bool; // r8
  __m128 m_quad; // xmm0
  float m_searchRadius; // xmm2_4
  __int128 m_up; // xmm1
  hkaiAstarCostModifier *m_costModifier; // rcx
  hkaiAstarEdgeFilter *m_edgeFilter; // rdx
  hkaiStreamingCollection::InstanceInfo *m_data; // rax
  float m_simpleRadiusThreshold; // xmm1_4
  hkaiAgentTraversalInfo m_agentInfo; // rax
  hkaiAgentTraversalInfo *p_m_agentInfo; // r12
  int v27; // ecx
  int v28; // edx
  unsigned int m_startFaceKey; // ebx
  hkVector4f v30; // xmm6
  int m_maxNumberOfIterations; // r13d
  _QWORD *v32; // r8
  _QWORD *v33; // rcx
  unsigned __int64 v34; // rax
  _QWORD *v35; // rcx
  int v36; // esi
  char v37; // bl
  hkaiAstarOutputParameters::SearchStatus v38; // edi
  _QWORD *v39; // r8
  _QWORD *v40; // rcx
  unsigned __int64 v41; // rax
  _QWORD *v42; // rcx
  hkaiSearchMemoryInfo memInfo; // [rsp+38h] [rbp-A0h] BYREF
  hkArray<char,hkContainerTempAllocator> array; // [rsp+50h] [rbp-88h] BYREF
  hkArray<char,hkContainerTempAllocator> v45; // [rsp+60h] [rbp-78h] BYREF
  hkaiSearchMemoryInfo hierarchyMemInfo; // [rsp+70h] [rbp-68h] BYREF
  void **v47; // [rsp+88h] [rbp-50h] BYREF
  int v48; // [rsp+90h] [rbp-48h]
  char v49; // [rsp+98h] [rbp-40h]
  hkaiAstarCostModifier *v50; // [rsp+A0h] [rbp-38h]
  hkaiPathfindingUtil::NearestFeatureCallback *v51; // [rsp+A8h] [rbp-30h]
  void *v52; // [rsp+B0h] [rbp-28h]
  int v53; // [rsp+B8h] [rbp-20h]
  int v54; // [rsp+BCh] [rbp-1Ch]
  int v55; // [rsp+C0h] [rbp-18h]
  hkaiNavMeshSearch::StartGoalInfo goalInfo; // [rsp+C8h] [rbp-10h] BYREF
  __int128 v57; // [rsp+F8h] [rbp+20h] BYREF
  void **v58; // [rsp+108h] [rbp+30h] BYREF
  int v59; // [rsp+110h] [rbp+38h]
  char v60; // [rsp+118h] [rbp+40h]
  hkaiAstarEdgeFilter *v61; // [rsp+120h] [rbp+48h]
  BOOL v62; // [rsp+128h] [rbp+50h]
  hkVector4f v63; // [rsp+138h] [rbp+60h]
  __int128 v64; // [rsp+148h] [rbp+70h]
  __m128 v65; // [rsp+158h] [rbp+80h]
  hkaiNavMeshSectionGraph graph; // [rsp+168h] [rbp+90h] BYREF
  hkaiNavMeshSearch v67; // [rsp+3A8h] [rbp+2D0h] BYREF
  hkaiSearchParameters::BufferSizes m_bufferSizes; // [rsp+910h] [rbp+838h] BYREF
  _BYTE *retaddr; // [rsp+928h] [rbp+850h]

  if ( input->m_startFaceKey != -1 )
  {
    if ( callbackType )
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v13 = Value[1];
      if ( v13 < Value[3] )
      {
        *(_QWORD *)v13 = "LtfindNearestFaces";
        *(_QWORD *)(v13 + 16) = "Stinit";
        v14 = __rdtsc();
        *(_DWORD *)(v13 + 8) = v14;
        Value[1] = v13 + 24;
      }
    }
    else
    {
      v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v10 = v9[1];
      if ( v10 < v9[3] )
      {
        *(_QWORD *)v10 = "LtfindNearestEdges";
        *(_QWORD *)(v10 + 16) = "Stinit";
        v11 = __rdtsc();
        *(_DWORD *)(v10 + 8) = v11;
        v9[1] = v10 + 24;
      }
    }
    m_bufferSizes = input->m_bufferSizes;
    m_maxOpenSetSizeBytes = m_bufferSizes.m_maxOpenSetSizeBytes;
    m_maxSearchStateSizeBytes = m_bufferSizes.m_maxSearchStateSizeBytes;
    v45.m_data = 0i64;
    if ( m_bufferSizes.m_maxOpenSetSizeBytes <= 0 )
      m_maxOpenSetSizeBytes = 0x20000;
    if ( m_bufferSizes.m_maxSearchStateSizeBytes <= 0 )
      m_maxSearchStateSizeBytes = 590336;
    hierarchyMemInfo.m_openSetBuffer = 0i64;
    hierarchyMemInfo.m_searchStateBuffer = 0i64;
    array.m_data = 0i64;
    array.m_size = 0;
    array.m_capacityAndFlags = 0x80000000;
    v45.m_data = 0i64;
    v45.m_size = 0;
    v45.m_capacityAndFlags = 0x80000000;
    hkaiSearchMemoryStorage::_setupArray(&array, 0i64, m_maxOpenSetSizeBytes);
    hkaiSearchMemoryStorage::_setupArray(&v45, 0i64, m_maxSearchStateSizeBytes);
    memInfo.m_openSetBuffer = array.m_data;
    memInfo.m_openSetSize = array.m_capacityAndFlags & 0x3FFFFFFF;
    memInfo.m_searchStateBuffer = v45.m_data;
    memInfo.m_searchStateSize = v45.m_capacityAndFlags & 0x3FFFFFFF;
    hkaiNavMeshSearch::hkaiNavMeshSearch(&v67, &memInfo, &hierarchyMemInfo);
    m_bool = input->m_projectedRadiusCheck.m_bool;
    m_searchRadius = input->m_searchRadius;
    m_up = (__int128)input->m_up;
    m_costModifier = input->m_costModifier;
    m_edgeFilter = input->m_edgeFilter;
    v63.m_quad = (__m128)input->m_startPoint;
    m_quad = v63.m_quad;
    v64 = m_up;
    m_quad.m128_f32[0] = m_searchRadius;
    v65 = _mm_shuffle_ps(m_quad, m_quad, 0);
    v48 = 0x1FFFF;
    v47 = &FaceCallbackCostModifierWrapper::`vftable;
    v49 = 1;
    v58 = &FaceCallbackEdgeFilterWrapper::`vftable;
    v50 = m_costModifier;
    v51 = callback;
    v52 = 0i64;
    v53 = 0;
    v54 = 0x80000000;
    v55 = 0;
    v59 = 0x1FFFF;
    v60 = 1;
    v61 = m_edgeFilter;
    v62 = m_bool != 0;
    if ( callbackType == CALLBACK_FACE )
    {
      m_costModifier = (hkaiAstarCostModifier *)&v47;
      m_edgeFilter = (hkaiAstarEdgeFilter *)&v58;
    }
    m_data = navMeshCollection->m_instances.m_data;
    graph.m_up = (hkVector4f)m_up;
    m_simpleRadiusThreshold = input->m_simpleRadiusThreshold;
    graph.m_streamingInfo = m_data;
    m_agentInfo = input->m_agentInfo;
    graph.m_costModifier = m_costModifier;
    *(float *)&m_bufferSizes.m_maxOpenSetSizeBytes = m_searchRadius;
    graph.m_info = m_agentInfo;
    p_m_agentInfo = &input->m_agentInfo;
    graph.m_edgeFilter = m_edgeFilter;
    v27 = 0;
    v28 = 0;
    *(_QWORD *)&graph.m_cachedIncomingEdge.m_oppositeEdge = -1i64;
    if ( m_agentInfo.m_diameter > (float)(m_simpleRadiusThreshold * 2.0) )
      v27 = 4;
    v67.m_graph.m_storage = &graph;
    *(_DWORD *)&graph.m_cachedIncomingEdge.m_flags.m_storage = 4;
    graph.m_searchSphereRadius.m_real = _mm_shuffle_ps(
                                          (__m128)LODWORD(m_searchRadius),
                                          (__m128)LODWORD(m_searchRadius),
                                          0);
    graph.m_searchCapsuleRadius.m_real = _mm_shuffle_ps((__m128)LODWORD(FLOAT_N1_0), (__m128)LODWORD(FLOAT_N1_0), 0);
    graph.m_searchState = &v67.m_state;
    *(_QWORD *)&graph.m_cachedOutgoingEdge.m_oppositeEdge = -1i64;
    if ( m_searchRadius >= 0.0 )
      v28 = 1;
    *(_DWORD *)&graph.m_cachedOutgoingEdge.m_flags.m_storage = 4;
    *(_QWORD *)&graph.m_cachedOppositeEdge.m_oppositeEdge = -1i64;
    *(_DWORD *)&graph.m_cachedOppositeEdge.m_flags.m_storage = 4;
    graph.m_cachedEdgePairInfo.m_incomingEdgeInfo.m_edgeKey = -1;
    graph.m_cachedEdgePairInfo.m_incomingEdgeInfo.m_edge = 0i64;
    graph.m_cachedEdgePairInfo.m_outgoingEdgeInfo.m_edgeKey = -1;
    graph.m_cachedEdgePairInfo.m_outgoingEdgeInfo.m_edge = 0i64;
    graph.m_cachedEdgePairInfo.m_faceKey = -1;
    graph.m_cachedEdgePairInfo.m_face = 0i64;
    graph.m_startFaceKey = -1;
    graph.m_numGoals = 0;
    graph.m_cachedIncomingNavMesh = 0i64;
    graph.m_cachedOutgoingNavMesh = 0i64;
    *(_QWORD *)&graph.m_cachedIncomingSectionId = -1i64;
    v67.m_state.m_heuristicWeight = 0.0;
    if ( m_bool )
      v28 |= 0x10u;
    m_startFaceKey = input->m_startFaceKey;
    v30.m_quad = (__m128)input->m_startPoint;
    goalInfo.m_goalPoints = (hkVector4f *)&v57;
    v57 = 0i64;
    goalInfo.m_startPoint = (hkVector4f)v30.m_quad;
    m_bufferSizes.m_maxOpenSetSizeBytes = -1;
    goalInfo.m_startFaceKey = m_startFaceKey;
    goalInfo.m_numGoals = 1;
    goalInfo.m_goalFaceKeys = (const unsigned int *)&m_bufferSizes;
    graph.m_flags = v28 | v27 & 0xFFFFFFEC;
    if ( callbackType == CALLBACK_FACE )
      callback->vfptr->faceTraversed(callback, m_startFaceKey, &input->m_agentInfo);
    graph.m_startPoint = (hkVector4f)v30.m_quad;
    graph.m_startFaceKey = m_startFaceKey;
    hkaiNavMeshSearch::init(&v67, &graph, &input->m_agentInfo, &goalInfo, 0);
    m_maxNumberOfIterations = input->m_maxNumberOfIterations;
    v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v33 = (_QWORD *)v32[1];
    if ( (unsigned __int64)v33 < v32[3] )
    {
      *v33 = "StAStar";
      v34 = __rdtsc();
      v35 = v33 + 2;
      *((_DWORD *)v35 - 2) = v34;
      v32[1] = v35;
    }
    v36 = 0;
    v37 = 0;
    while ( v36 < m_maxNumberOfIterations )
    {
      ++v36;
      v38 = hkaiNavMeshSearch::iteration(&v67);
      if ( v38 == SEARCH_TERMINATED )
        v37 = (v67.m_openset.m_heapSize < v67.m_openset.m_maxSize) + 2;
      if ( callbackType == CALLBACK_EDGE
        && (v67.m_lastClosedNode >> 22) - 1021 > 1
        && !callback->vfptr->edgeTraversed(callback, v67.m_lastClosedNode, p_m_agentInfo) )
      {
        v37 = 4;
        goto LABEL_34;
      }
      if ( v38 )
        goto LABEL_35;
    }
    v37 = 1;
LABEL_34:
    LOBYTE(v38) = 3;
LABEL_35:
    if ( retaddr )
    {
      *(_DWORD *)retaddr = v36;
      retaddr[12] = v38;
      retaddr[13] = v37;
    }
    v39 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v40 = (_QWORD *)v39[1];
    if ( (unsigned __int64)v40 < v39[3] )
    {
      *v40 = "lt";
      v41 = __rdtsc();
      v42 = v40 + 2;
      *((_DWORD *)v42 - 2) = v41;
      v39[1] = v42;
    }
    v58 = &hkBaseObject::`vftable;
    v53 = 0;
    if ( v54 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v52, 4 * v54);
    v52 = 0i64;
    v54 = 0x80000000;
    v47 = &hkBaseObject::`vftable;
    v45.m_size = 0;
    if ( v45.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v45.m_data,
        v45.m_capacityAndFlags & 0x3FFFFFFF);
    v45.m_data = 0i64;
    v45.m_capacityAndFlags = 0x80000000;
    array.m_size = 0;
    if ( array.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        array.m_data,
        array.m_capacityAndFlags & 0x3FFFFFFF);
    array.m_data = 0i64;
    array.m_capacityAndFlags = 0x80000000;
    LODWORD(hierarchyMemInfo.m_searchStateBuffer) = 0;
    if ( SHIDWORD(hierarchyMemInfo.m_searchStateBuffer) >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        hierarchyMemInfo.m_openSetBuffer,
        HIDWORD(hierarchyMemInfo.m_searchStateBuffer) & 0x3FFFFFFF);
    hierarchyMemInfo.m_openSetBuffer = 0i64;
    v45.m_size = 0;
    HIDWORD(hierarchyMemInfo.m_searchStateBuffer) = 0x80000000;
    if ( v45.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v45.m_data,
        v45.m_capacityAndFlags & 0x3FFFFFFF);
  }
}

// File Line: 793
// RVA: 0xBBDC60
void __fastcall hkaiPathfindingUtil::findGraphPath(
        hkaiStreamingCollection *collection,
        hkaiPathfindingUtil::FindGraphPathInput *input,
        hkaiPathfindingUtil::FindGraphPathOutput *output,
        hkaiStreamingCollection *hierarchyCollection)
{
  char v5; // r10
  char v6; // dl
  unsigned int *m_data; // r9
  __int64 m_size; // r11
  bool v11; // zf
  unsigned int *v12; // rcx
  __int64 v13; // r8
  _QWORD *Value; // rax
  unsigned __int64 v15; // rcx
  _QWORD *v16; // r8
  unsigned __int64 v17; // rax
  char m_bool; // al
  bool v19; // r12
  unsigned int v20; // ecx
  int m_maxOpenSetSizeBytes; // edi
  int m_maxSearchStateSizeBytes; // r14d
  int v23; // r9d
  hkaiSearchParameters::BufferSizes m_bufferSizes; // rax
  unsigned int v25; // ecx
  int v26; // edi
  int v27; // r14d
  char *m_openSetBuffer; // rax
  int v29; // r9d
  hkaiStreamingCollection::InstanceInfo *v30; // rax
  hkaiAstarEdgeFilter *m_edgeFilter; // rax
  hkaiStreamingCollection::InstanceInfo *v32; // r8
  _QWORD *v33; // r8
  _QWORD *v34; // rcx
  unsigned __int64 v35; // rax
  _QWORD *v36; // rcx
  int m_maxNumberOfIterations; // r12d
  char v38; // r14
  int v39; // edi
  hkaiAstarOutputParameters::SearchStatus v40; // eax
  int v41; // ecx
  __int64 v42; // r9
  int v43; // r8d
  __int64 v44; // rdx
  unsigned int *v45; // rax
  unsigned int m_bestNode; // edi
  _QWORD *v47; // r8
  _QWORD *v48; // rcx
  unsigned __int64 v49; // rax
  _QWORD *v50; // rcx
  _QWORD *v51; // rax
  _QWORD *v52; // rcx
  _QWORD *v53; // r8
  unsigned __int64 v54; // rax
  _QWORD *v55; // rcx
  hkaiSearchMemoryInfo hierarchyMemInfo; // [rsp+30h] [rbp-D0h] BYREF
  char *array; // [rsp+48h] [rbp-B8h] BYREF
  int v58; // [rsp+50h] [rbp-B0h]
  int v59; // [rsp+54h] [rbp-ACh]
  char *m_searchStateBuffer; // [rsp+58h] [rbp-A8h] BYREF
  int v61; // [rsp+60h] [rbp-A0h]
  int v62; // [rsp+64h] [rbp-9Ch]
  hkaiSearchMemoryInfo memInfo; // [rsp+68h] [rbp-98h] BYREF
  char *v64; // [rsp+80h] [rbp-80h] BYREF
  int v65; // [rsp+88h] [rbp-78h]
  int v66; // [rsp+8Ch] [rbp-74h]
  char *v67; // [rsp+90h] [rbp-70h] BYREF
  int v68; // [rsp+98h] [rbp-68h]
  int v69; // [rsp+9Ch] [rbp-64h]
  hkaiDirectedGraphSearch::StartGoalInfo goalInfo; // [rsp+A0h] [rbp-60h] BYREF
  hkaiDirectedGraphVisitor graph; // [rsp+D0h] [rbp-30h] BYREF
  hkaiDirectedGraphSearch v72; // [rsp+2F0h] [rbp+1F0h] BYREF
  hkaiSearchParameters::BufferSizes result; // [rsp+928h] [rbp+828h] BYREF

  v5 = 0;
  v6 = 0;
  if ( input->m_startNodeKeys.m_size > 0 )
  {
    m_data = input->m_startNodeKeys.m_data;
    m_size = input->m_startNodeKeys.m_size;
    do
    {
      v11 = *m_data++ == -1;
      v6 |= !v11;
      --m_size;
    }
    while ( m_size );
  }
  if ( input->m_goalNodeKeys.m_size > 0 )
  {
    v12 = input->m_goalNodeKeys.m_data;
    v13 = input->m_goalNodeKeys.m_size;
    do
    {
      v11 = *v12++ == -1;
      v5 |= !v11;
      --v13;
    }
    while ( v13 );
  }
  if ( !v6 || !v5 )
  {
    output->m_outputParameters.m_goalIndex = -1;
    output->m_outputParameters.m_status.m_storage = 5;
    output->m_outputParameters.m_numIterations = 0;
    return;
  }
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = Value[1];
  v16 = Value;
  if ( v15 < Value[3] )
  {
    *(_QWORD *)v15 = "LtFindGraphPath";
    *(_QWORD *)(v15 + 16) = "Stinit";
    v17 = __rdtsc();
    *(_DWORD *)(v15 + 8) = v17;
    v16[1] = v15 + 24;
  }
  m_bool = input->m_searchParameters.m_useHierarchicalHeuristic.m_bool;
  v19 = m_bool && hierarchyCollection;
  v20 = 0x80000000;
  v59 = 0x80000000;
  array = 0i64;
  v58 = 0;
  m_searchStateBuffer = 0i64;
  v61 = 0;
  v62 = 0x80000000;
  if ( m_bool )
  {
    result = input->m_searchParameters.m_hierarchyBufferSizes;
    m_maxOpenSetSizeBytes = result.m_maxOpenSetSizeBytes;
    m_maxSearchStateSizeBytes = result.m_maxSearchStateSizeBytes;
    if ( result.m_maxOpenSetSizeBytes <= 0 )
      m_maxOpenSetSizeBytes = 0x8000;
    if ( result.m_maxSearchStateSizeBytes <= 0 )
      m_maxSearchStateSizeBytes = 147968;
    if ( input->m_hierarchySearchBuffers.m_openSetBuffer )
    {
      array = input->m_hierarchySearchBuffers.m_openSetBuffer;
      v58 = 0;
      v59 = m_maxOpenSetSizeBytes | 0x80000000;
    }
    else
    {
      if ( m_maxOpenSetSizeBytes > 0 )
      {
        hkArrayUtil::_reserve((hkResult *)&result, &hkContainerTempAllocator::s_alloc, &array, m_maxOpenSetSizeBytes, 1);
        v20 = v62;
      }
      v58 = m_maxOpenSetSizeBytes;
    }
    if ( input->m_hierarchySearchBuffers.m_searchStateBuffer )
    {
      m_searchStateBuffer = input->m_hierarchySearchBuffers.m_searchStateBuffer;
      v61 = 0;
      v20 = m_maxSearchStateSizeBytes | 0x80000000;
      v62 = m_maxSearchStateSizeBytes | 0x80000000;
    }
    else
    {
      if ( (int)(v20 & 0x3FFFFFFF) < m_maxSearchStateSizeBytes )
      {
        v23 = m_maxSearchStateSizeBytes;
        if ( m_maxSearchStateSizeBytes < (int)(2 * (v20 & 0x3FFFFFFF)) )
          v23 = 2 * (v20 & 0x3FFFFFFF);
        hkArrayUtil::_reserve((hkResult *)&result, &hkContainerTempAllocator::s_alloc, &m_searchStateBuffer, v23, 1);
        v20 = v62;
      }
      v61 = m_maxSearchStateSizeBytes;
    }
    hierarchyMemInfo.m_openSetBuffer = array;
    hierarchyMemInfo.m_openSetSize = v59 & 0x3FFFFFFF;
    hierarchyMemInfo.m_searchStateSize = v20 & 0x3FFFFFFF;
    hierarchyMemInfo.m_searchStateBuffer = m_searchStateBuffer;
  }
  else
  {
    memset(&hierarchyMemInfo, 0, sizeof(hierarchyMemInfo));
  }
  m_bufferSizes = input->m_searchParameters.m_bufferSizes;
  v25 = 0x80000000;
  v64 = 0i64;
  v26 = m_bufferSizes.m_maxOpenSetSizeBytes;
  result = m_bufferSizes;
  v27 = m_bufferSizes.m_maxSearchStateSizeBytes;
  v65 = 0;
  if ( m_bufferSizes.m_maxOpenSetSizeBytes <= 0 )
    v26 = 0x20000;
  if ( m_bufferSizes.m_maxSearchStateSizeBytes <= 0 )
    v27 = 590336;
  m_openSetBuffer = input->m_searchBuffers.m_openSetBuffer;
  v66 = 0x80000000;
  v67 = 0i64;
  v68 = 0;
  v69 = 0x80000000;
  if ( m_openSetBuffer )
  {
    v64 = m_openSetBuffer;
    v65 = 0;
    v66 = v26 | 0x80000000;
  }
  else
  {
    if ( v26 > 0 )
    {
      hkArrayUtil::_reserve((hkResult *)&result, &hkContainerTempAllocator::s_alloc, &v64, v26, 1);
      v25 = v69;
    }
    v65 = v26;
  }
  if ( input->m_searchBuffers.m_searchStateBuffer )
  {
    v67 = input->m_searchBuffers.m_searchStateBuffer;
    v68 = 0;
    v25 = v27 | 0x80000000;
    v69 = v27 | 0x80000000;
  }
  else
  {
    if ( (int)(v25 & 0x3FFFFFFF) < v27 )
    {
      v29 = v27;
      if ( v27 < (int)(2 * (v25 & 0x3FFFFFFF)) )
        v29 = 2 * (v25 & 0x3FFFFFFF);
      hkArrayUtil::_reserve((hkResult *)&result, &hkContainerTempAllocator::s_alloc, &v67, v29, 1);
      v25 = v69;
    }
    v68 = v27;
  }
  memInfo.m_openSetBuffer = v64;
  memInfo.m_searchStateSize = v25 & 0x3FFFFFFF;
  memInfo.m_openSetSize = v66 & 0x3FFFFFFF;
  memInfo.m_searchStateBuffer = v67;
  hkaiDirectedGraphSearch::hkaiDirectedGraphSearch(&v72, &memInfo, &hierarchyMemInfo);
  *(__m128i *)&graph.m_cachedNode.m_startEdgeIndex = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
  v72.m_state.m_heuristicWeight = input->m_searchParameters.m_heuristicWeight;
  v30 = collection->m_instances.m_data;
  *(_QWORD *)&graph.m_cachedIncomingSectionId = -1i64;
  graph.m_cachedGeneralSectionId = -1;
  graph.m_streamingInfo = v30;
  graph.m_costModifier = input->m_searchParameters.m_costModifier;
  m_edgeFilter = input->m_searchParameters.m_edgeFilter;
  memset(&graph.m_goalNodes, 0, 20);
  graph.m_edgeFilter = m_edgeFilter;
  graph.m_agentInfo = input->m_agentInfo;
  graph.m_searchState = &v72.m_state;
  goalInfo.m_startNodeKeys = input->m_startNodeKeys.m_data;
  goalInfo.m_numStartNodeKeys = input->m_startNodeKeys.m_size;
  goalInfo.m_initialCosts = input->m_initialCosts.m_data;
  goalInfo.m_goalNodeKeys = input->m_goalNodeKeys.m_data;
  goalInfo.m_numGoals = input->m_goalNodeKeys.m_size;
  goalInfo.m_finalCosts = input->m_finalCosts.m_data;
  if ( v19 )
    v32 = hierarchyCollection->m_instances.m_data;
  else
    v32 = 0i64;
  hkaiDirectedGraphSearch::init(&v72, &graph, v32, &goalInfo);
  v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v34 = (_QWORD *)v33[1];
  if ( (unsigned __int64)v34 < v33[3] )
  {
    *v34 = "StAStar";
    v35 = __rdtsc();
    v36 = v34 + 2;
    *((_DWORD *)v36 - 2) = v35;
    v33[1] = v36;
  }
  m_maxNumberOfIterations = input->m_maxNumberOfIterations;
  v38 = 0;
  v39 = 0;
  while ( v39 < m_maxNumberOfIterations )
  {
    ++v39;
    v40 = hkaiDirectedGraphSearch::iteration(&v72);
    v41 = v40;
    if ( v40 == SEARCH_TERMINATED )
    {
      v38 = (v72.m_openSet.m_heapSize < v72.m_openSet.m_maxSize) + 2;
      goto LABEL_62;
    }
    if ( v40 )
      goto LABEL_62;
  }
  v41 = 3;
  v38 = 1;
LABEL_62:
  output->m_outputParameters.m_terminationCause.m_storage = v38;
  output->m_outputParameters.m_numIterations = v39;
  output->m_outputParameters.m_status.m_storage = v41;
  v42 = input->m_goalNodeKeys.m_size;
  v43 = 0;
  v44 = 0i64;
  if ( v42 <= 0 )
  {
LABEL_66:
    v43 = -1;
  }
  else
  {
    v45 = input->m_goalNodeKeys.m_data;
    while ( *v45 != v72.m_lastClosedNode )
    {
      ++v44;
      ++v43;
      ++v45;
      if ( v44 >= v42 )
        goto LABEL_66;
    }
  }
  output->m_outputParameters.m_goalIndex = v43;
  if ( v41 == 1 )
  {
    m_bestNode = input->m_goalNodeKeys.m_data[v43];
    goto LABEL_71;
  }
  if ( v41 == 3 )
  {
    m_bestNode = v72.m_state.m_bestNode;
LABEL_71:
    v72.m_state.m_currentNodeState = hkaiHashSearchState::getNodeState(&v72.m_state, m_bestNode);
    v72.m_state.m_parentNodeState = v72.m_state.m_currentNodeState;
    v72.m_state.m_parentIndex = (__int16)(v72.m_state.m_currentNodeState - v72.m_state.m_nodes);
    output->m_outputParameters.m_pathLength = v72.m_state.m_currentNodeState->m_gCost;
    v47 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v48 = (_QWORD *)v47[1];
    if ( (unsigned __int64)v48 < v47[3] )
    {
      *v48 = "Stoutput";
      v49 = __rdtsc();
      v50 = v48 + 2;
      *((_DWORD *)v50 - 2) = v49;
      v47[1] = v50;
    }
    hkaiSearchStateUtils::getPath(&v72.m_state, m_bestNode, GET_PATH_PRESERVE_ALL, &output->m_pathNodes, 0x7FFFFFFF);
  }
  v51 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v52 = (_QWORD *)v51[1];
  v53 = v51;
  if ( (unsigned __int64)v52 < v51[3] )
  {
    *v52 = "lt";
    v54 = __rdtsc();
    v55 = v52 + 2;
    *((_DWORD *)v55 - 2) = v54;
    v53[1] = v55;
  }
  v68 = 0;
  if ( v69 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v67, v69 & 0x3FFFFFFF);
  v67 = 0i64;
  v69 = 0x80000000;
  v65 = 0;
  if ( v66 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v64, v66 & 0x3FFFFFFF);
  v64 = 0i64;
  v66 = 0x80000000;
  v61 = 0;
  if ( v62 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      m_searchStateBuffer,
      v62 & 0x3FFFFFFF);
  m_searchStateBuffer = 0i64;
  v62 = 0x80000000;
  v58 = 0;
  if ( v59 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, v59 & 0x3FFFFFFF);
}

// File Line: 924
// RVA: 0xBBE350
void __fastcall hkaiPathfindingUtil::findGraphPath(
        hkaiDirectedGraphExplicitCost *graph,
        hkaiPathfindingUtil::FindGraphPathInput *input,
        hkaiPathfindingUtil::FindGraphPathOutput *output,
        hkaiDirectedGraphExplicitCost *clusterGraph)
{
  hkaiStreamingCollection::InstanceInfo *m_data; // rax
  __int64 v9; // rdx
  hkaiDirectedGraphInstance **p_m_clusterGraphInstance; // rax
  hkaiStreamingCollection::InstanceInfo *v11; // r8
  __int64 v12; // rdx
  hkaiDirectedGraphInstance **v13; // rax
  hkaiStreamingCollection array; // [rsp+30h] [rbp-D0h] BYREF
  hkaiStreamingCollection hierarchyCollection; // [rsp+60h] [rbp-A0h] BYREF
  hkaiDirectedGraphInstance v16; // [rsp+90h] [rbp-70h] BYREF
  hkaiDirectedGraphInstance v17; // [rsp+1A0h] [rbp+A0h] BYREF
  hkResult result; // [rsp+2E8h] [rbp+1E8h] BYREF

  hkaiDirectedGraphInstance::hkaiDirectedGraphInstance(&v17);
  hkaiDirectedGraphInstance::tempInit(&v17, graph);
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array.m_instances, 1, 48);
  m_data = array.m_instances.m_data;
  v9 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    p_m_clusterGraphInstance = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( p_m_clusterGraphInstance != (hkaiDirectedGraphInstance **)16 )
      {
        *(p_m_clusterGraphInstance - 2) = 0i64;
        *(p_m_clusterGraphInstance - 1) = 0i64;
        *p_m_clusterGraphInstance = 0i64;
        p_m_clusterGraphInstance[1] = 0i64;
        p_m_clusterGraphInstance[2] = 0i64;
        *((_DWORD *)p_m_clusterGraphInstance + 6) = -1;
      }
      p_m_clusterGraphInstance += 6;
      --v9;
    }
    while ( v9 );
    m_data = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  m_data->m_clusterGraphInstance = &v17;
  if ( clusterGraph )
  {
    hkaiDirectedGraphInstance::hkaiDirectedGraphInstance(&v16);
    hkaiDirectedGraphInstance::tempInit(&v16, clusterGraph);
    hkaiStreamingCollection::hkaiStreamingCollection(&hierarchyCollection);
    hierarchyCollection.m_isTemporary.m_bool = 1;
    if ( (hierarchyCollection.m_instances.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &hierarchyCollection.m_instances, 1, 48);
    v11 = hierarchyCollection.m_instances.m_data;
    v12 = 1 - hierarchyCollection.m_instances.m_size;
    if ( 1 - hierarchyCollection.m_instances.m_size > 0 )
    {
      v13 = &hierarchyCollection.m_instances.m_data[hierarchyCollection.m_instances.m_size].m_clusterGraphInstance;
      do
      {
        if ( v13 != (hkaiDirectedGraphInstance **)16 )
        {
          *(v13 - 2) = 0i64;
          *(v13 - 1) = 0i64;
          *v13 = 0i64;
          v13[1] = 0i64;
          v13[2] = 0i64;
          *((_DWORD *)v13 + 6) = -1;
        }
        v13 += 6;
        --v12;
      }
      while ( v12 );
      v11 = hierarchyCollection.m_instances.m_data;
    }
    hierarchyCollection.m_instances.m_size = 1;
    v11->m_clusterGraphInstance = &v16;
    hkaiPathfindingUtil::findGraphPath(&array, input, output, &hierarchyCollection);
    hkaiStreamingCollection::~hkaiStreamingCollection(&hierarchyCollection);
    hkaiDirectedGraphInstance::~hkaiDirectedGraphInstance(&v16);
  }
  else
  {
    hkaiPathfindingUtil::findGraphPath(&array, input, output, 0i64);
  }
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
  hkaiDirectedGraphInstance::~hkaiDirectedGraphInstance(&v17);
}

// File Line: 954
// RVA: 0xBBC860
void __fastcall hkaiPathfindingUtil::FindPathInput::checkDeterminism(hkaiPathfindingUtil::FindPathInput *this)
{
  ;
}

// File Line: 968
// RVA: 0xBBC890
void __fastcall hkaiPathfindingUtil::FindPathOutput::checkDeterminism(hkaiPathfindingUtil::FindPathOutput *this)
{
  ;
}


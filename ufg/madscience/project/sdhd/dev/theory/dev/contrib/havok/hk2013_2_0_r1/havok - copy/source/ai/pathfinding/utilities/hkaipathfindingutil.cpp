// File Line: 48
// RVA: 0xBBC6B0
void __fastcall hkaiPathfindingUtil::FindPathInput::FindPathInput(hkaiPathfindingUtil::FindPathInput *this, int numGoals)
{
  hkaiPathfindingUtil::FindPathInput *v2; // rbx
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // er9
  int v7; // eax
  int v8; // eax
  int v9; // er9
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPathfindingUtil::FindPathInput::`vftable;
  *(_QWORD *)&this->m_goalPoints.m_capacityAndFlags = -2147483648i64;
  this->m_goalPoints.m_data = 0i64;
  this->m_goalPoints.m_size = 0;
  this->m_goalFaceKeys.m_data = 0i64;
  this->m_goalFaceKeys.m_size = 0;
  this->m_goalFaceKeys.m_capacityAndFlags = 2147483648;
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
  this->m_searchParameters.m_up.m_vec[2] = -32768;
  this->m_searchBuffers.m_openSetBuffer = 0i64;
  this->m_searchBuffers.m_searchStateBuffer = 0i64;
  this->m_hierarchySearchBuffers.m_openSetBuffer = 0i64;
  this->m_hierarchySearchBuffers.m_searchStateBuffer = 0i64;
  v3 = numGoals;
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
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &this->m_goalFaceKeys,
        v6,
        4);
    }
    v2->m_goalFaceKeys.m_size = v3;
    v7 = v2->m_goalPoints.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v7 < v3 )
    {
      v8 = 2 * v7;
      v9 = v3;
      if ( v3 < v8 )
        v9 = v8;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v2->m_goalPoints,
        v9,
        16);
    }
    v2->m_goalPoints.m_size = v3;
  }
}

// File Line: 65
// RVA: 0xBBC820
void __fastcall hkaiPathfindingUtil::FindPathInput::FindPathInput(hkaiPathfindingUtil::FindPathInput *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPathfindingUtil::FindPathInput::`vftable;
  this->m_searchBuffers.m_openSetBuffer = 0i64;
  this->m_searchBuffers.m_searchStateBuffer = 0i64;
  this->m_hierarchySearchBuffers.m_openSetBuffer = 0i64;
  this->m_hierarchySearchBuffers.m_searchStateBuffer = 0i64;
}

// File Line: 73
// RVA: 0xBBC870
void __fastcall hkaiPathfindingUtil::FindPathOutput::FindPathOutput(hkaiPathfindingUtil::FindPathOutput *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPathfindingUtil::FindPathOutput::`vftable;
}

// File Line: 84
// RVA: 0xBBC8A0
void __fastcall hkaiPathfindingUtil::NearestFeatureInput::NearestFeatureInput(hkaiPathfindingUtil::NearestFeatureInput *this)
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
void __fastcall hkaiPathfindingUtil::FindGraphPathInput::FindGraphPathInput(hkaiPathfindingUtil::FindGraphPathInput *this)
{
  this->m_startNodeKeys.m_capacityAndFlags = 2147483648;
  this->m_startNodeKeys.m_data = 0i64;
  this->m_startNodeKeys.m_size = 0;
  this->m_initialCosts.m_data = 0i64;
  this->m_initialCosts.m_size = 0;
  this->m_initialCosts.m_capacityAndFlags = 2147483648;
  this->m_goalNodeKeys.m_data = 0i64;
  this->m_goalNodeKeys.m_size = 0;
  this->m_goalNodeKeys.m_capacityAndFlags = 2147483648;
  this->m_finalCosts.m_data = 0i64;
  this->m_finalCosts.m_size = 0;
  this->m_finalCosts.m_capacityAndFlags = 2147483648;
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
void __fastcall hkaiPathfindingUtil::FindGraphPathInput::FindGraphPathInput(hkaiPathfindingUtil::FindGraphPathInput *this, hkFinishLoadedObjectFlag f)
{
  this->m_searchBuffers.m_openSetBuffer = 0i64;
  this->m_searchBuffers.m_searchStateBuffer = 0i64;
  this->m_hierarchySearchBuffers.m_openSetBuffer = 0i64;
  this->m_hierarchySearchBuffers.m_searchStateBuffer = 0i64;
}

// File Line: 105
// RVA: 0xBBC9B0
void __fastcall hkaiPathfindingUtil::FindGraphPathInput::setStartNode(hkaiPathfindingUtil::FindGraphPathInput *this, unsigned int startNode)
{
  unsigned int v2; // edi
  hkaiPathfindingUtil::FindGraphPathInput *v3; // rbx
  int v4; // eax
  int v5; // eax
  int v6; // er9
  int v7; // eax
  int v8; // eax
  int v9; // er9
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = startNode;
  v3 = this;
  v4 = this->m_startNodeKeys.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < 1 )
  {
    v5 = 2 * v4;
    v6 = 1;
    if ( v5 > 1 )
      v6 = v5;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, v6, 4);
  }
  v3->m_startNodeKeys.m_size = 1;
  *v3->m_startNodeKeys.m_data = v2;
  v7 = v3->m_initialCosts.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < 1 )
  {
    v8 = 2 * v7;
    v9 = 1;
    if ( v8 > 1 )
      v9 = v8;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v3->m_initialCosts,
      v9,
      4);
  }
  v3->m_initialCosts.m_size = 1;
  *v3->m_initialCosts.m_data = 0.0;
}

// File Line: 114
// RVA: 0xBBCBE0
void __fastcall hkaiPathfindingUtil::FindGraphPathInput::setGoalNode(hkaiPathfindingUtil::FindGraphPathInput *this, unsigned int goalNode)
{
  unsigned int v2; // esi
  hkaiPathfindingUtil::FindGraphPathInput *v3; // rdi
  int v4; // eax
  int v5; // eax
  int v6; // er9
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = goalNode;
  v3 = this;
  v4 = this->m_goalNodeKeys.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < 1 )
  {
    v5 = 2 * v4;
    v6 = 1;
    if ( v5 > 1 )
      v6 = v5;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_goalNodeKeys,
      v6,
      4);
  }
  v3->m_goalNodeKeys.m_size = 1;
  *v3->m_goalNodeKeys.m_data = v2;
  v3->m_finalCosts.m_size = 0;
}

// File Line: 122
// RVA: 0xBBCA60
void __fastcall hkaiPathfindingUtil::FindGraphPathInput::setStartEdge(hkaiPathfindingUtil::FindGraphPathInput *this, hkaiStreamingCollection *collection, unsigned int startNodeKey, unsigned int startEdgeKey, float fraction)
{
  unsigned int v5; // er14
  hkaiStreamingCollection *v6; // rbp
  __int64 v7; // rax
  hkaiPathfindingUtil::FindGraphPathInput *v8; // rbx
  hkaiDirectedGraphInstance *v9; // rsi
  hkaiDirectedGraphExplicitCost::Edge *v10; // rdi
  unsigned int v11; // eax
  unsigned int v12; // ecx
  int v13; // esi
  unsigned int v14; // eax
  hkaiDirectedGraphExplicitCost::Edge *v15; // rax
  int v16; // ecx
  hkaiDirectedGraphExplicitCost::Edge *v17; // rbp
  int v18; // ecx
  int v19; // er9
  int v20; // eax
  int v21; // eax
  int v22; // er9
  float v23; // xmm1_4
  float *v24; // rcx
  hkResult result; // [rsp+60h] [rbp+18h]

  v5 = startNodeKey;
  v6 = collection;
  v7 = startNodeKey >> 22;
  v8 = this;
  if ( (signed int)v7 >= 0 )
    v9 = collection->m_instances.m_data[v7].m_clusterGraphInstance;
  else
    v9 = 0i64;
  v10 = hkaiStreamingCollection::getGraphEdgeFromPacked(collection, startEdgeKey);
  v11 = v10->m_target;
  if ( v10->m_flags.m_storage & 0x40 )
    v12 = v11 & 0xFFC00000;
  else
    v12 = v9->m_runtimeId << 22;
  v13 = v12 | v11 & 0x3FFFFF;
  if ( v11 == -1 )
    v13 = -1;
  v14 = hkaiGraphUtils::getEdgeBetween(v6, v13, v5);
  v15 = hkaiStreamingCollection::getGraphEdgeFromPacked(v6, v14);
  v16 = v8->m_startNodeKeys.m_capacityAndFlags & 0x3FFFFFFF;
  v17 = v15;
  if ( v16 < 2 )
  {
    v18 = 2 * v16;
    v19 = 2;
    if ( v18 > 2 )
      v19 = v18;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, v19, 4);
  }
  v8->m_startNodeKeys.m_size = 2;
  *v8->m_startNodeKeys.m_data = v5;
  v8->m_startNodeKeys.m_data[1] = v13;
  v20 = v8->m_initialCosts.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v20 < 2 )
  {
    v21 = 2 * v20;
    v22 = 2;
    if ( v21 > 2 )
      v22 = v21;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v8->m_initialCosts,
      v22,
      4);
  }
  v23 = fraction;
  v8->m_initialCosts.m_size = 2;
  v24 = v8->m_initialCosts.m_data;
  result.m_enum = v17->m_cost.m_value << 16;
  *v24 = *(float *)&result.m_enum * v23;
  LODWORD(fraction) = v10->m_cost.m_value << 16;
  v24[1] = (float)(1.0 - v23) * fraction;
}

// File Line: 148
// RVA: 0xBBCC60
void __fastcall hkaiPathfindingUtil::FindGraphPathInput::setGoalEdge(hkaiPathfindingUtil::FindGraphPathInput *this, hkaiStreamingCollection *collection, unsigned int goalNodeKey, unsigned int goalEdgeKey, float fraction)
{
  unsigned int v5; // ebp
  hkaiStreamingCollection *v6; // rsi
  __int64 v7; // rax
  hkaiPathfindingUtil::FindGraphPathInput *v8; // r15
  hkaiDirectedGraphInstance *v9; // rbx
  hkaiDirectedGraphExplicitCost::Edge *v10; // rdi
  unsigned int v11; // eax
  unsigned int v12; // ecx
  int v13; // er14
  unsigned int v14; // eax
  hkaiDirectedGraphExplicitCost::Edge *v15; // rax
  int v16; // ecx
  hkaiDirectedGraphExplicitCost::Edge *v17; // rsi
  int v18; // ecx
  int v19; // er9
  int v20; // eax
  int v21; // eax
  int v22; // er9
  float v23; // xmm1_4
  float *v24; // rcx
  hkResult result; // [rsp+60h] [rbp+18h]

  v5 = goalNodeKey;
  v6 = collection;
  v7 = goalNodeKey >> 22;
  v8 = this;
  if ( (signed int)v7 >= 0 )
    v9 = collection->m_instances.m_data[v7].m_clusterGraphInstance;
  else
    v9 = 0i64;
  v10 = hkaiStreamingCollection::getGraphEdgeFromPacked(collection, goalEdgeKey);
  v11 = v10->m_target;
  if ( v10->m_flags.m_storage & 0x40 )
    v12 = v11 & 0xFFC00000;
  else
    v12 = v9->m_runtimeId << 22;
  v13 = v12 | v11 & 0x3FFFFF;
  if ( v11 == -1 )
    v13 = -1;
  v14 = hkaiGraphUtils::getEdgeBetween(v6, v13, v5);
  v15 = hkaiStreamingCollection::getGraphEdgeFromPacked(v6, v14);
  v16 = v8->m_goalNodeKeys.m_capacityAndFlags & 0x3FFFFFFF;
  v17 = v15;
  if ( v16 < 2 )
  {
    v18 = 2 * v16;
    v19 = 2;
    if ( v18 > 2 )
      v19 = v18;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v8->m_goalNodeKeys,
      v19,
      4);
  }
  v8->m_goalNodeKeys.m_size = 2;
  *v8->m_goalNodeKeys.m_data = v5;
  v8->m_goalNodeKeys.m_data[1] = v13;
  v20 = v8->m_finalCosts.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v20 < 2 )
  {
    v21 = 2 * v20;
    v22 = 2;
    if ( v21 > 2 )
      v22 = v21;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v8->m_finalCosts,
      v22,
      4);
  }
  v23 = fraction;
  v8->m_finalCosts.m_size = 2;
  v24 = v8->m_finalCosts.m_data;
  result.m_enum = v10->m_cost.m_value << 16;
  *v24 = *(float *)&result.m_enum * v23;
  LODWORD(fraction) = v17->m_cost.m_value << 16;
  v24[1] = (float)(1.0 - v23) * fraction;
}

// File Line: 178
// RVA: 0xBBD720
void __fastcall hkaiPathfindingUtil::findPath(hkaiNavMesh *navMesh, hkaiPathfindingUtil::FindPathInput *input, hkaiPathfindingUtil::FindPathOutput *output)
{
  hkaiNavMesh *v3; // rbx
  hkaiPathfindingUtil::FindPathOutput *v4; // rdi
  hkaiPathfindingUtil::FindPathInput *v5; // rsi
  int v6; // er9
  hkaiStreamingCollection::InstanceInfo *v7; // r8
  __int64 v8; // rdx
  hkaiDirectedGraphInstance **v9; // rax
  hkaiStreamingCollection array; // [rsp+30h] [rbp-218h]
  hkaiNavMeshInstance v11; // [rsp+60h] [rbp-1E8h]
  hkResult result; // [rsp+268h] [rbp+20h]

  v3 = navMesh;
  v4 = output;
  v5 = input;
  hkaiNavMeshInstance::hkaiNavMeshInstance(&v11);
  hkaiNavMeshInstance::tempInit(&v11, v3, 1);
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) < 1 )
  {
    v6 = 1;
    if ( 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) > 1 )
      v6 = 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array.m_instances,
      v6,
      48);
  }
  v7 = array.m_instances.m_data;
  v8 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    v9 = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( v9 != (hkaiDirectedGraphInstance **)16 )
      {
        *(v9 - 2) = 0i64;
        *(v9 - 1) = 0i64;
        *v9 = 0i64;
        v9[1] = 0i64;
        v9[2] = 0i64;
        *((_DWORD *)v9 + 6) = -1;
      }
      v9 += 6;
      --v8;
    }
    while ( v8 );
    v7 = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  v7->m_instancePtr = &v11;
  array.m_instances.m_data->m_clusterGraphInstance = 0i64;
  array.m_instances.m_data->m_mediator = 0i64;
  hkaiPathfindingUtil::findPath(&array, v5, v4);
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
  hkaiNavMeshInstance::~hkaiNavMeshInstance(&v11);
}

// File Line: 191
// RVA: 0xBBCDF0
void __fastcall hkaiPathfindingUtil::findPath(hkaiStreamingCollection *collection, hkaiPathfindingUtil::FindPathInput *input, hkaiPathfindingUtil::FindPathOutput *output)
{
  hkaiPathfindingUtil::FindPathOutput *v3; // r14
  hkaiPathfindingUtil::FindPathInput *v4; // rdi
  hkaiStreamingCollection *v5; // r13
  int v6; // ebx
  char v7; // al
  __m128 v8; // xmm1
  signed int v9; // er12
  signed int v10; // er15
  unsigned int v11; // eax
  signed int v12; // eax
  _QWORD *v13; // r8
  unsigned __int64 v14; // rcx
  const char *v15; // rax
  unsigned __int64 v16; // rax
  char *v17; // rdx
  int v18; // ebx
  int v19; // er8
  char *v20; // rdx
  int v21; // ebx
  int v22; // er8
  hkaiStreamingCollection::InstanceInfo *v23; // rax
  float v24; // xmm1_4
  signed int v25; // ecx
  bool v26; // zf
  bool v27; // zf
  float v28; // xmm2_4
  float v29; // xmm3_4
  int v30; // eax
  hkVector4f v31; // xmm4
  unsigned int v32; // er8
  hkVector4f *v33; // r9
  const unsigned int *v34; // r10
  signed int v35; // eax
  hkSimdFloat32 v36; // xmm0
  float v37; // xmm0_4
  float v38; // xmm0_4
  int v39; // er12
  _QWORD *v40; // r8
  _QWORD *v41; // rcx
  unsigned __int64 v42; // rax
  signed __int64 v43; // rcx
  char v44; // r15
  int v45; // ebx
  hkaiAstarOutputParameters::SearchStatus v46; // eax
  signed int v47; // ecx
  unsigned int v48; // ebx
  BOOL v49; // er12
  _QWORD *v50; // r9
  _QWORD *v51; // rcx
  unsigned __int64 v52; // rax
  signed __int64 v53; // rcx
  hkArray<unsigned int,hkContainerHeapAllocator> *v54; // r15
  __m128 v55; // xmm0
  unsigned int v56; // edx
  _QWORD *v57; // r8
  _QWORD *v58; // rcx
  unsigned __int64 v59; // rax
  signed __int64 v60; // rcx
  int v61; // er9
  char v62; // bl
  int v63; // eax
  char v64; // r12
  float radius; // xmm6_4
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *pathArrayOut; // r14
  int v67; // eax
  int project; // er12
  int computeNormals; // ebx
  int v70; // eax
  _QWORD *v71; // r8
  _QWORD *v72; // rcx
  unsigned __int64 v73; // rax
  signed __int64 v74; // rcx
  _QWORD *v75; // r8
  _QWORD *v76; // rcx
  unsigned __int64 v77; // rax
  signed __int64 v78; // rcx
  char v79; // r15
  float v80; // xmm6_4
  int v81; // er9
  int v82; // eax
  int v83; // er12
  int v84; // er15
  int v85; // eax
  hkResult result; // [rsp+70h] [rbp-90h]
  float v87; // [rsp+78h] [rbp-88h]
  hkaiSearchMemoryInfo hierarchyMemInfo; // [rsp+80h] [rbp-80h]
  hkArray<char,hkContainerTempAllocator> array; // [rsp+98h] [rbp-68h]
  hkArray<char,hkContainerTempAllocator> v90; // [rsp+A8h] [rbp-58h]
  hkaiSearchMemoryInfo memInfo; // [rsp+B8h] [rbp-48h]
  hkArray<char,hkContainerTempAllocator> v92; // [rsp+D0h] [rbp-30h]
  hkArray<char,hkContainerTempAllocator> v93; // [rsp+E0h] [rbp-20h]
  hkVector4f endPoint; // [rsp+F0h] [rbp-10h]
  unsigned int validGoalsMask; // [rsp+100h] [rbp+0h]
  hkVector4f up; // [rsp+110h] [rbp+10h]
  hkVector4f edgeB; // [rsp+120h] [rbp+20h]
  hkaiNavMeshSearch::StartGoalInfo goalInfo; // [rsp+130h] [rbp+30h]
  hkVector4f edgeA; // [rsp+160h] [rbp+60h]
  hkaiNavMeshSectionGraph graph; // [rsp+170h] [rbp+70h]
  hkaiNavMeshSearch v101; // [rsp+3B0h] [rbp+2B0h]
  hkaiStreamingCollection *v102; // [rsp+920h] [rbp+820h]
  hkaiSearchParameters::BufferSizes closestGoalIndex; // [rsp+938h] [rbp+838h]

  v102 = collection;
  v3 = output;
  v4 = input;
  v5 = collection;
  if ( !hkaiNavMeshSearchValidationUtils::validateFindPathInput(collection, input, &validGoalsMask) )
  {
    v3->m_outputParameters.m_goalIndex = -1;
    v3->m_outputParameters.m_numIterations = 0;
    v3->m_outputParameters.m_status.m_storage = 5;
    return;
  }
  v6 = -1;
  result.m_enum = v4->m_goalPoints.m_size;
  v7 = v4->m_searchParameters.m_lineOfSightFlags.m_storage;
  v8 = _mm_cvtepi32_ps(
         _mm_add_epi32(
           _mm_unpacklo_epi16((__m128i)0i64, _mm_loadl_epi64((const __m128i *)&v4->m_searchParameters)),
           _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset)));
  closestGoalIndex.m_maxOpenSetSizeBytes = -1;
  v9 = 1;
  up.m_quad = _mm_mul_ps(v8, (__m128)xmmword_141A713A0);
  if ( v7 & 4 || v7 & 1 && !v4->m_searchParameters.m_costModifier )
  {
    v10 = 1;
    v11 = hkaiPathfindingUtil::_checkInitialFace(v5, v4, (int *)&closestGoalIndex);
    v6 = closestGoalIndex.m_maxOpenSetSizeBytes;
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
  if ( !hkaiPathfindingUtil::checkLineOfSight(v5, v4, v6, v3) )
    goto LABEL_11;
  v12 = 1;
LABEL_12:
  if ( !v9 && !v12 )
  {
    if ( v4->m_searchParameters.m_useHierarchicalHeuristic.m_bool )
    {
      v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v14 = v13[1];
      if ( v14 < v13[3] )
      {
        v15 = "LtHierarchyFindPath";
LABEL_19:
        *(_QWORD *)v14 = v15;
        *(_QWORD *)(v14 + 16) = "Stinit";
        v16 = __rdtsc();
        *(_DWORD *)(v14 + 8) = v16;
        v13[1] = v14 + 24;
        goto LABEL_20;
      }
    }
    else
    {
      v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v14 = v13[1];
      if ( v14 < v13[3] )
      {
        v15 = "LtFindPath";
        goto LABEL_19;
      }
    }
LABEL_20:
    array.m_data = 0i64;
    array.m_size = 0;
    array.m_capacityAndFlags = 2147483648;
    v90.m_data = 0i64;
    v90.m_size = 0;
    v90.m_capacityAndFlags = 2147483648;
    if ( v4->m_searchParameters.m_useHierarchicalHeuristic.m_bool )
    {
      v17 = v4->m_hierarchySearchBuffers.m_openSetBuffer;
      closestGoalIndex = v4->m_searchParameters.m_hierarchyBufferSizes;
      v18 = closestGoalIndex.m_maxSearchStateSizeBytes;
      v19 = closestGoalIndex.m_maxOpenSetSizeBytes;
      if ( closestGoalIndex.m_maxOpenSetSizeBytes <= 0 )
        v19 = 0x8000;
      if ( closestGoalIndex.m_maxSearchStateSizeBytes <= 0 )
        v18 = 147968;
      hkaiSearchMemoryStorage::_setupArray(&array, v17, v19);
      hkaiSearchMemoryStorage::_setupArray(&v90, v4->m_hierarchySearchBuffers.m_searchStateBuffer, v18);
      hierarchyMemInfo.m_openSetBuffer = array.m_data;
      hierarchyMemInfo.m_openSetSize = array.m_capacityAndFlags & 0x3FFFFFFF;
      hierarchyMemInfo.m_searchStateBuffer = v90.m_data;
      hierarchyMemInfo.m_searchStateSize = v90.m_capacityAndFlags & 0x3FFFFFFF;
    }
    else
    {
      hierarchyMemInfo.m_openSetBuffer = 0i64;
      *(_QWORD *)&hierarchyMemInfo.m_openSetSize = 0i64;
      hierarchyMemInfo.m_searchStateBuffer = 0i64;
    }
    v20 = v4->m_searchBuffers.m_openSetBuffer;
    closestGoalIndex = v4->m_searchParameters.m_bufferSizes;
    v21 = closestGoalIndex.m_maxSearchStateSizeBytes;
    v22 = closestGoalIndex.m_maxOpenSetSizeBytes;
    v92.m_data = 0i64;
    if ( closestGoalIndex.m_maxOpenSetSizeBytes <= 0 )
      v22 = 0x20000;
    v92.m_size = 0;
    v92.m_capacityAndFlags = 2147483648;
    v93.m_data = 0i64;
    if ( closestGoalIndex.m_maxSearchStateSizeBytes <= 0 )
      v21 = 590336;
    v93.m_size = 0;
    v93.m_capacityAndFlags = 2147483648;
    hkaiSearchMemoryStorage::_setupArray(&v92, v20, v22);
    hkaiSearchMemoryStorage::_setupArray(&v93, v4->m_searchBuffers.m_searchStateBuffer, v21);
    memInfo.m_openSetBuffer = v92.m_data;
    memInfo.m_openSetSize = v92.m_capacityAndFlags & 0x3FFFFFFF;
    memInfo.m_searchStateBuffer = v93.m_data;
    memInfo.m_searchStateSize = v93.m_capacityAndFlags & 0x3FFFFFFF;
    hkaiNavMeshSearch::hkaiNavMeshSearch(&v101, &memInfo, &hierarchyMemInfo);
    v23 = v5->m_instances.m_data;
    v24 = v4->m_searchParameters.m_simpleRadiusThreshold;
    graph.m_up = (hkVector4f)up.m_quad;
    graph.m_streamingInfo = v23;
    v25 = 0;
    v26 = v4->m_searchParameters.m_useGrandparentDistanceCalculation.m_bool == 0;
    graph.m_costModifier = v4->m_searchParameters.m_costModifier;
    graph.m_edgeFilter = v4->m_searchParameters.m_edgeFilter;
    graph.m_info = v4->m_agentInfo;
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
    if ( graph.m_info.m_diameter > (float)(v24 * 2.0) )
    {
      v25 = 4;
      if ( v4->m_searchParameters.m_userEdgeTraversalTestType.m_storage == 1 )
        v25 = 12;
    }
    if ( !v26 )
      v25 |= 0x20u;
    v27 = v4->m_searchParameters.m_projectedRadiusCheck.m_bool == 0;
    v28 = v4->m_searchParameters.m_searchSphereRadius;
    v29 = v4->m_searchParameters.m_searchCapsuleRadius;
    v30 = v4->m_goalPoints.m_size;
    v31.m_quad = (__m128)v4->m_startPoint;
    v32 = v4->m_startFaceKey;
    graph.m_startPoint = v4->m_startPoint;
    *(float *)&closestGoalIndex.m_maxOpenSetSizeBytes = v28;
    v87 = v29;
    v33 = v4->m_goalPoints.m_data;
    v34 = v4->m_goalFaceKeys.m_data;
    graph.m_searchSphereRadius.m_real = _mm_shuffle_ps((__m128)LODWORD(v28), (__m128)LODWORD(v28), 0);
    graph.m_numGoals = v30;
    v35 = 0;
    graph.m_startFaceKey = v32;
    v36.m_real = _mm_shuffle_ps((__m128)LODWORD(v29), (__m128)LODWORD(v29), 0);
    if ( v28 >= 0.0 )
      v35 = 1;
    graph.m_endPoints = v33;
    graph.m_endFaceKeys = v34;
    graph.m_searchCapsuleRadius = (hkSimdFloat32)v36.m_real;
    if ( v29 >= 0.0 )
      v35 |= 2u;
    if ( !v27 )
      v35 |= 0x10u;
    v37 = v4->m_searchParameters.m_heuristicWeight;
    goalInfo.m_startFaceKey = v32;
    v26 = v4->m_searchParameters.m_useHierarchicalHeuristic.m_bool == 0;
    v101.m_state.m_heuristicWeight = v37;
    v38 = v4->m_searchParameters.m_maximumPathLength;
    goalInfo.m_startPoint = (hkVector4f)v31.m_quad;
    v101.m_state.m_maxPathCost = v38;
    v101.m_graph.m_storage = &graph;
    graph.m_flags = v35 | v25 & 0xFFFFFFEC;
    graph.m_searchState = &v101.m_state;
    goalInfo.m_goalPoints = v33;
    goalInfo.m_numGoals = result.m_enum;
    goalInfo.m_goalFaceKeys = v34;
    hkaiNavMeshSearch::init(&v101, &graph, &v4->m_agentInfo, &goalInfo, !v26);
    v39 = v4->m_maxNumberOfIterations;
    v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v41 = (_QWORD *)v40[1];
    if ( (unsigned __int64)v41 < v40[3] )
    {
      *v41 = "StAStar";
      v42 = __rdtsc();
      v43 = (signed __int64)(v41 + 2);
      *(_DWORD *)(v43 - 8) = v42;
      v40[1] = v43;
    }
    v44 = 0;
    v45 = 0;
    while ( v45 < v39 )
    {
      ++v45;
      v46 = hkaiNavMeshSearch::iteration(&v101);
      v47 = v46;
      if ( v46 == 3 )
      {
        v44 = (v101.m_openset.m_heapSize < v101.m_openset.m_maxSize) + 2;
        goto LABEL_51;
      }
      if ( v46 )
        goto LABEL_51;
    }
    v47 = 3;
    v44 = 1;
LABEL_51:
    v3->m_outputParameters.m_numIterations = v45;
    v3->m_outputParameters.m_status.m_storage = v47;
    v3->m_outputParameters.m_terminationCause.m_storage = v44;
    v3->m_outputParameters.m_goalIndex = -1;
    if ( (v47 - 1) & 0xFFFFFFFD )
      goto LABEL_71;
    v48 = v101.m_state.m_bestNode;
    v49 = v47 == 1;
    v3->m_outputParameters.m_goalIndex = v101.m_goalFoundIndex;
    if ( v47 == 1 )
      v48 = v101.m_lastClosedNode;
    v101.m_state.m_currentNodeState = hkaiHashSearchState::getNodeState(&v101.m_state, v48);
    v101.m_state.m_parentNodeState = v101.m_state.m_currentNodeState;
    v101.m_state.m_parentIndex = (signed __int16)((_QWORD)((char *)v101.m_state.m_currentNodeState
                                                         - (char *)v101.m_state.m_nodes) >> 4);
    v3->m_outputParameters.m_pathLength = v101.m_state.m_currentNodeState->m_gCost;
    v50 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v51 = (_QWORD *)v50[1];
    if ( (unsigned __int64)v51 < v50[3] )
    {
      *v51 = "Stoutput";
      v52 = __rdtsc();
      v53 = (signed __int64)(v51 + 2);
      *(_DWORD *)(v53 - 8) = v52;
      v50[1] = v53;
    }
    v54 = &v3->m_visitedEdges;
    hkaiSearchStateUtils::getPath(&v101.m_state, v48, GET_PATH_IGNORE_START_AND_END, &v3->m_visitedEdges, 0x7FFFFFFF);
    if ( v49 )
    {
      v55 = v4->m_goalPoints.m_data[v3->m_outputParameters.m_goalIndex].m_quad;
    }
    else
    {
      if ( v3->m_visitedEdges.m_size )
      {
        v56 = v3->m_visitedEdges.m_data[v3->m_visitedEdges.m_size - 1];
        hkaiNavMeshInstance::getEdgePoints(
          v5->m_instances.m_data[v56 >> 22].m_instancePtr,
          v56 & 0x3FFFFF,
          &edgeA,
          &edgeB);
        endPoint.m_quad = _mm_add_ps(
                            _mm_mul_ps(_mm_sub_ps(edgeB.m_quad, edgeA.m_quad), (__m128)xmmword_141A711B0),
                            edgeA.m_quad);
        goto LABEL_62;
      }
      v55 = v4->m_startPoint.m_quad;
    }
    endPoint.m_quad = v55;
LABEL_62:
    if ( v4->m_searchParameters.m_outputPathFlags.m_storage & 1 )
    {
      v57 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v58 = (_QWORD *)v57[1];
      if ( (unsigned __int64)v58 < v57[3] )
      {
        *v58 = "Ttsmooth";
        v59 = __rdtsc();
        v60 = (signed __int64)(v58 + 2);
        *(_DWORD *)(v60 - 8) = v59;
        v57[1] = v60;
      }
      v61 = v3->m_visitedEdges.m_size;
      v62 = v4->m_searchParameters.m_outputPathFlags.m_storage;
      v63 = v3->m_pathOut.m_capacityAndFlags;
      v64 = v4->m_searchParameters.m_outputPathFlags.m_storage;
      radius = v4->m_agentInfo.m_diameter * 0.5;
      LOBYTE(closestGoalIndex.m_maxOpenSetSizeBytes) = radius <= v4->m_searchParameters.m_simpleRadiusThreshold;
      pathArrayOut = &v3->m_pathOut;
      v67 = v63 & 0x3FFFFFFF;
      project = v64 & 2;
      computeNormals = v62 & 4;
      if ( v67 < v61 )
      {
        v70 = 2 * v67;
        if ( v61 < v70 )
          v61 = v70;
        hkArrayUtil::_reserve(
          &result,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          pathArrayOut,
          v61,
          48);
      }
      hkaiNavMeshPathSmoothingUtil::findSmoothedPathMain(
        v5->m_instances.m_data,
        v54,
        v4->m_startFaceKey,
        &v4->m_startPoint,
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
      v71 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v72 = (_QWORD *)v71[1];
      if ( (unsigned __int64)v72 < v71[3] )
      {
        *v72 = "Et";
        v73 = __rdtsc();
        v74 = (signed __int64)(v72 + 2);
        *(_DWORD *)(v74 - 8) = v73;
        v71[1] = v74;
      }
    }
LABEL_71:
    v75 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v76 = (_QWORD *)v75[1];
    if ( (unsigned __int64)v76 < v75[3] )
    {
      *v76 = "lt";
      v77 = __rdtsc();
      v78 = (signed __int64)(v76 + 2);
      *(_DWORD *)(v78 - 8) = v77;
      v75[1] = v78;
    }
    hkaiSearchMemoryStorage::~hkaiSearchMemoryStorage((hkaiSearchMemoryStorage *)&memInfo);
    hkaiSearchMemoryStorage::~hkaiSearchMemoryStorage((hkaiSearchMemoryStorage *)&hierarchyMemInfo);
    return;
  }
  v3->m_outputParameters.m_status.m_storage = 1;
  v3->m_outputParameters.m_numIterations = 0;
  v3->m_outputParameters.m_goalIndex = v6;
  if ( v4->m_searchParameters.m_outputPathFlags.m_storage & 1 )
  {
    v79 = v4->m_searchParameters.m_outputPathFlags.m_storage;
    v80 = v4->m_agentInfo.m_diameter * 0.5;
    v81 = v3->m_visitedEdges.m_size + 2;
    v82 = v3->m_pathOut.m_capacityAndFlags & 0x3FFFFFFF;
    v83 = v79 & 2;
    v84 = v79 & 4;
    if ( v82 < v81 )
    {
      v85 = 2 * v82;
      if ( v81 < v85 )
        v81 = v85;
      hkArrayUtil::_reserve(
        (hkResult *)&closestGoalIndex,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v3->m_pathOut,
        v81,
        48);
    }
    hkaiNavMeshPathSmoothingUtil::projectStraightPath(
      v102->m_instances.m_data,
      &v3->m_visitedEdges,
      v4->m_startFaceKey,
      &v4->m_startPoint,
      &v4->m_goalPoints.m_data[v6],
      v83,
      v84,
      &up,
      v80,
      &v3->m_pathOut,
      0i64,
      0);
  }
}

// File Line: 436
// RVA: 0xBBDAA0
signed __int64 __fastcall hkaiPathfindingUtil::_checkInitialFace(hkaiStreamingCollection *collection, hkaiPathfindingUtil::FindPathInput *input, int *closestGoalIndex)
{
  hkVector4f v3; // xmm0
  hkaiPathfindingUtil::FindPathInput *v4; // rdi
  int v5; // edx
  hkaiStreamingCollection *v6; // rsi
  hkVector4f *v7; // rcx
  int *v8; // rbx
  int v9; // eax
  unsigned int v10; // ebx
  __int128 v11; // xmm0
  signed __int64 v12; // rdx
  hkaiNavMeshInstance *v13; // r11
  hkVector4f *v14; // rax
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rbp
  hkaiNavMesh::Face *v16; // rax
  hkArray<int,hkContainerHeapAllocator> *v17; // r11
  int striding; // ecx
  __int64 v19; // r15
  int *v20; // rax
  hkaiAstarEdgeFilter *v21; // rcx
  signed __int64 result; // rax
  hkVector4UtilImpl<float>::DistanceToPoint evalFunc; // [rsp+40h] [rbp-B8h]
  int *v24; // [rsp+50h] [rbp-A8h]
  char v25; // [rsp+58h] [rbp-A0h]
  int v26; // [rsp+60h] [rbp-98h]
  __int64 v27; // [rsp+68h] [rbp-90h]
  __int64 v28; // [rsp+70h] [rbp-88h]
  __int128 v29; // [rsp+80h] [rbp-78h]
  int v30; // [rsp+90h] [rbp-68h]
  __int64 v31; // [rsp+98h] [rbp-60h]
  __int64 v32; // [rsp+A0h] [rbp-58h]
  hkVector4f v33; // [rsp+B0h] [rbp-48h]
  unsigned int v34; // [rsp+C0h] [rbp-38h]
  __int64 v35; // [rsp+C8h] [rbp-30h]
  int *v36; // [rsp+D0h] [rbp-28h]

  v3.m_quad = (__m128)input->m_startPoint;
  v4 = input;
  v5 = input->m_goalPoints.m_size;
  v6 = collection;
  v7 = v4->m_goalPoints.m_data;
  v8 = closestGoalIndex;
  _mm_store_si128((__m128i *)&evalFunc, (__m128i)v3.m_quad);
  v9 = hkAlgorithm::findMinimumIndex<hkVector4f,hkVector4UtilImpl<float>::DistanceToPoint>(v7, v5, &evalFunc);
  *v8 = v9;
  v10 = v4->m_startFaceKey;
  if ( v10 != v4->m_goalFaceKeys.m_data[v9] )
    goto LABEL_11;
  v11 = (__int128)v4->m_startPoint;
  v12 = v9;
  v13 = v6->m_instances.m_data[v10 >> 22].m_instancePtr;
  v14 = v4->m_goalPoints.m_data;
  v34 = -1;
  v29 = v11;
  v35 = 0i64;
  v26 = -1;
  v27 = 0i64;
  v28 = 0i64;
  v30 = -1;
  v31 = 0i64;
  v32 = 0i64;
  instanceMap = &v13->m_faceMap;
  v33.m_quad = (__m128)v14[v12];
  v16 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__2(
          v13->m_originalFaces,
          v13->m_numOriginalFaces,
          &v13->m_instancedFaces,
          &v13->m_ownedFaces,
          &v13->m_faceMap,
          v10 & 0x3FFFFF);
  striding = v17[4].m_size;
  v19 = (__int64)v16;
  v20 = striding ? hkaiNavMeshInstance_getWithStriding_int__0(
                     v17[4].m_data,
                     v17[1].m_size,
                     v17 + 22,
                     v17 + 24,
                     instanceMap,
                     v10 & 0x3FFFFF,
                     striding) : 0i64;
  v36 = v20;
  v24 = &v26;
  v21 = v4->m_searchParameters.m_edgeFilter;
  v35 = v19;
  v34 = v10;
  evalFunc.m_p.m_quad.m128_u64[0] = (unsigned __int64)v17;
  evalFunc.m_p.m_quad.m128_u64[1] = (unsigned __int64)&v4->m_agentInfo;
  v25 = 17;
  if ( !v21 )
    goto LABEL_12;
  if ( !((unsigned __int8 (__fastcall *)(hkaiAstarEdgeFilter *, hkVector4UtilImpl<float>::DistanceToPoint *))v21->vfptr[2].__first_virtual_table_function__)(
          v21,
          &evalFunc) )
LABEL_11:
    result = 0i64;
  else
LABEL_12:
    result = 1i64;
  return result;
}

// File Line: 472
// RVA: 0xBBD870
bool __fastcall hkaiPathfindingUtil::checkLineOfSight(hkaiStreamingCollection *navMeshCollection, hkaiPathfindingUtil::FindPathInput *input, int goalIndex, hkaiPathfindingUtil::FindPathOutput *output)
{
  hkaiStreamingCollection *v4; // rsi
  hkaiPathfindingUtil::FindPathOutput *v5; // r14
  __int64 v6; // rbx
  hkaiPathfindingUtil::FindPathInput *v7; // rdi
  hkVector4f *v8; // rax
  hkVector4f v9; // xmm0
  unsigned int *v10; // rax
  unsigned int v11; // ecx
  hkaiAgentTraversalInfo v12; // rax
  hkaiStreamingCollection::InstanceInfo *v13; // rcx
  unsigned int v14; // eax
  unsigned int v15; // ebx
  int v16; // edx
  unsigned int *v17; // r9
  unsigned int *v18; // r10
  signed __int64 v19; // rcx
  unsigned int v20; // eax
  float v21; // xmm0_4
  hkaiLineOfSightUtil::LineOfSightInput inputa; // [rsp+20h] [rbp-79h]
  hkaiLineOfSightUtil::LineOfSightOutput outputa; // [rsp+90h] [rbp-9h]
  int v25; // [rsp+110h] [rbp+77h]

  v4 = navMeshCollection;
  v5 = output;
  v6 = goalIndex;
  v7 = input;
  hkaiLineOfSightUtil::LineOfSightInput::LineOfSightInput(&inputa);
  v8 = v7->m_goalPoints.m_data;
  inputa.m_startPoint = v7->m_startPoint;
  v9.m_quad = (__m128)v8[v6];
  inputa.m_startFaceKey = v7->m_startFaceKey;
  v10 = v7->m_goalFaceKeys.m_data;
  inputa.m_goalPoint = (hkVector4f)v9.m_quad;
  v9.m_quad.m128_i32[0] = LODWORD(v7->m_searchParameters.m_searchSphereRadius);
  inputa.m_up.m_quad = _mm_mul_ps(
                         _mm_cvtepi32_ps(
                           _mm_add_epi32(
                             _mm_unpacklo_epi16(
                               (__m128i)0i64,
                               _mm_loadl_epi64((const __m128i *)&v7->m_searchParameters)),
                             _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset))),
                         (__m128)xmmword_141A713A0);
  v11 = v10[v6];
  inputa.m_maxNumberOfIterations = v7->m_maxNumberOfIterations;
  v12 = v7->m_agentInfo;
  LODWORD(inputa.m_searchRadius) = v9.m_quad.m128_i32[0];
  inputa.m_maximumPathLength = v7->m_searchParameters.m_maximumPathLength;
  inputa.m_agentInfo = v12;
  LOBYTE(v12.m_diameter) = v7->m_searchParameters.m_projectedRadiusCheck.m_bool;
  inputa.m_goalFaceKey = v11;
  inputa.m_projectedRadiusCheck.m_bool = LOBYTE(v12.m_diameter);
  inputa.m_costModifier = v7->m_searchParameters.m_costModifier;
  inputa.m_edgeFilter = v7->m_searchParameters.m_edgeFilter;
  inputa.m_exactInternalVertexHandling.m_bool = ((unsigned __int8)v7->m_searchParameters.m_lineOfSightFlags.m_storage >> 1) & 1;
  hkaiLineOfSightUtil::LineOfSightOutput::LineOfSightOutput(&outputa);
  v13 = v4->m_instances.m_data;
  outputa.m_doNotExceedArrayCapacity.m_bool = 0;
  v14 = hkaiLineOfSightUtil::checkLineOfSight(v13, &inputa, &outputa);
  v15 = v14;
  if ( v5 )
  {
    v16 = outputa.m_visitedEdgesOut.m_size;
    v5->m_outputParameters.m_status.m_storage = (v14 == 0) + 1;
    if ( (v5->m_visitedEdges.m_capacityAndFlags & 0x3FFFFFFF) < v16 )
    {
      if ( v5->m_visitedEdges.m_capacityAndFlags >= 0 )
      {
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v5->m_visitedEdges.m_data,
          4 * v5->m_visitedEdges.m_capacityAndFlags);
        v16 = outputa.m_visitedEdgesOut.m_size;
      }
      v25 = 4 * v16;
      v5->m_visitedEdges.m_data = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                    &v25);
      v16 = outputa.m_visitedEdgesOut.m_size;
      v5->m_visitedEdges.m_capacityAndFlags = v25 / 4;
    }
    v17 = outputa.m_visitedEdgesOut.m_data;
    v18 = v5->m_visitedEdges.m_data;
    v19 = 0i64;
    v5->m_visitedEdges.m_size = v16;
    if ( v16 > 0 )
    {
      do
      {
        v20 = v17[v19++];
        v18[v19 - 1] = v20;
      }
      while ( v19 < v16 );
    }
    if ( v15 )
      v21 = outputa.m_accumulatedDistance;
    else
      v21 = v5->m_outputParameters.m_pathLength;
    v5->m_outputParameters.m_pathLength = v21;
  }
  hkaiLineOfSightUtil::LineOfSightOutput::~LineOfSightOutput(&outputa);
  return v15 != 0;
}

// File Line: 509
// RVA: 0xBBDA60
void __fastcall hkaiPathfindingUtil::findNearestEdges(hkaiStreamingCollection *navMeshCollection, hkaiPathfindingUtil::NearestFeatureInput *input, hkaiPathfindingUtil::NearestFeatureCallback *callback, hkaiAstarOutputParameters *output)
{
  hkaiPathfindingUtil::_findNearestFeature(navMeshCollection, input, callback, 0, output);
}

// File Line: 514
// RVA: 0xBBDA80
void __fastcall hkaiPathfindingUtil::findNearestFaces(hkaiStreamingCollection *navMeshCollection, hkaiPathfindingUtil::NearestFeatureInput *input, hkaiPathfindingUtil::NearestFeatureCallback *callback, hkaiAstarOutputParameters *output)
{
  hkaiPathfindingUtil::_findNearestFeature(navMeshCollection, input, callback, CALLBACK_FACE, output);
}

// File Line: 534
// RVA: 0xBBF190
__m128i *__fastcall FaceCallbackCostModifierWrapper::getModifiedCost(FaceCallbackCostModifierWrapper *this, hkSimdFloat32 *result, hkaiAstarCostModifier::NavMeshGetModifiedCostCallbackContext *context)
{
  hkaiNavMeshEdgePairInfo *v3; // rax
  __m128i *v4; // rbp
  int v5; // er8
  __m128i *v6; // rdi
  unsigned int v7; // ebx
  FaceCallbackCostModifierWrapper *v8; // r14
  unsigned int *v9; // r8
  int v10; // er9
  signed int v11; // er10
  int v12; // ecx
  unsigned int v13; // edx
  hkaiAstarCostModifier *v14; // rcx
  hkResult resulta; // [rsp+40h] [rbp+8h]

  v3 = context->m_edgeFaceInfo;
  v4 = (__m128i *)context;
  v5 = this->m_visitedFaceKeys.m_elem.m_size - 1;
  v6 = (__m128i *)result;
  v7 = v3->m_outgoingEdgeInfo.m_edge->m_oppositeFace;
  v8 = this;
  if ( 2 * this->m_visitedFaceKeys.m_numElems > v5 )
    hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
      &this->m_visitedFaceKeys,
      &resulta,
      2 * v5 + 2);
  v9 = v8->m_visitedFaceKeys.m_elem.m_data;
  v10 = v8->m_visitedFaceKeys.m_elem.m_size - 1;
  v11 = 1;
  v12 = v10 & -1640531535 * (v7 >> 4);
  v13 = v9[v12];
  if ( v13 != -1 )
  {
    while ( v13 != v7 )
    {
      v12 = v10 & (v12 + 1);
      v13 = v9[v12];
      if ( v13 == -1 )
        goto LABEL_8;
    }
    v11 = 0;
  }
LABEL_8:
  v8->m_visitedFaceKeys.m_numElems += v11;
  v9[v12] = v7;
  if ( v11 )
    v8->m_callback->vfptr->faceTraversed(v8->m_callback, v7, (hkaiAgentTraversalInfo *)v4->m128i_i64[1]);
  v14 = v8->m_costModifier;
  if ( v14 )
    ((void (__fastcall *)(hkaiAstarCostModifier *, __m128i *, __m128i *))v14->vfptr[2].__first_virtual_table_function__)(
      v14,
      v6,
      v4);
  else
    _mm_store_si128(v6, v4[3]);
  return v6;
}

// File Line: 556
// RVA: 0xBBF280
hkSimdFloat32 *__fastcall FaceCallbackCostModifierWrapper::getModifiedCost(FaceCallbackCostModifierWrapper *this, hkSimdFloat32 *result, hkaiAstarCostModifier::NavVolumeGetModifiedCostCallbackContext *context)
{
  hkSimdFloat32 *v3; // rbx

  v3 = result;
  hkaiAstarCostModifier::getModifiedCost((hkaiAstarCostModifier *)&this->vfptr, result, context);
  return v3;
}

// File Line: 561
// RVA: 0xBBF170
hkSimdFloat32 *__fastcall FaceCallbackCostModifierWrapper::getModifiedCost(FaceCallbackCostModifierWrapper *this, hkSimdFloat32 *result, hkaiAstarCostModifier::DirectedGraphGetModifiedCostCallbackContext *context)
{
  hkSimdFloat32 *v3; // rbx

  v3 = result;
  hkaiAstarCostModifier::getModifiedCost((hkaiAstarCostModifier *)&this->vfptr, result, context);
  return v3;
}

// File Line: 586
// RVA: 0xBBF2B0
char __fastcall FaceCallbackEdgeFilterWrapper::isEnabled(FaceCallbackEdgeFilterWrapper *this, hkaiAstarEdgeFilter::NavMeshIsEnabledCallbackContext *context)
{
  FaceCallbackEdgeFilterWrapper *v2; // rbx
  hkaiAstarEdgeFilter *v3; // rcx
  hkaiAstarEdgeFilter::NavMeshIsEnabledCallbackContext *v4; // rdi
  char v5; // si
  hkaiNavMesh::Edge *v6; // rdx
  __m128 v7; // xmm7
  __m128 v8; // xmm6
  __m128 v9; // xmm4
  __m128 v10; // xmm3
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
  char result; // al
  hkVector4f edgeB; // [rsp+20h] [rbp-58h]
  hkVector4f edgeA; // [rsp+30h] [rbp-48h]

  v2 = this;
  v3 = this->m_edgeFilter;
  v4 = context;
  v5 = 1;
  if ( v3 )
  {
    v5 = ((__int64 (*)(void))v3->vfptr[2].__first_virtual_table_function__)();
    if ( !v5 )
      goto LABEL_12;
  }
  v6 = v4->m_edgeFaceInfo->m_outgoingEdgeInfo.m_edge;
  if ( !v6 || COERCE_FLOAT(*(_OWORD *)&v2->m_searchSphereRadius) <= 0.0 )
    goto LABEL_12;
  v7 = v2->m_startPoint.m_quad;
  hkaiNavMeshInstance::getEdgePoints(v4->m_meshAccessor, v6, &edgeA, &edgeB);
  v8 = edgeA.m_quad;
  v9 = edgeB.m_quad;
  if ( v2->m_projectedRadiusCheck )
  {
    v10 = v2->m_up.m_quad;
    v11 = _mm_mul_ps(v2->m_up.m_quad, v7);
    v12 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170));
    v13 = _mm_mul_ps(v2->m_up.m_quad, edgeA.m_quad);
    v7 = _mm_sub_ps(v7, _mm_mul_ps(v12, v10));
    v14 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170));
    v15 = _mm_mul_ps(v2->m_up.m_quad, edgeB.m_quad);
    v8 = _mm_sub_ps(edgeA.m_quad, _mm_mul_ps(v14, v10));
    v9 = _mm_sub_ps(
           edgeB.m_quad,
           _mm_mul_ps(
             _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
               _mm_shuffle_ps(v15, v15, 170)),
             v10));
  }
  v16 = v8;
  v17 = _mm_sub_ps(v8, v7);
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
  v24 = _mm_cmpltps(v23, query.m_quad);
  v25 = _mm_sub_ps(
          v17,
          _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v23, v24), _mm_andnot_ps(v24, query.m_quad))), v18));
  v26 = _mm_mul_ps(v25, v25);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 170))) > (float)(v2->m_searchSphereRadius.m_real.m128_f32[0]
                                                                    * v2->m_searchSphereRadius.m_real.m128_f32[0]) )
    result = 0;
  else
LABEL_12:
    result = v5;
  return result;
}

// File Line: 622
// RVA: 0xBBF480
bool __fastcall FaceCallbackEdgeFilterWrapper::isEnabled(FaceCallbackEdgeFilterWrapper *this, hkaiAstarEdgeFilter::NavVolumeIsEnabledCallbackContext *context)
{
  return hkaiAstarEdgeFilter::isEnabled((hkaiAstarEdgeFilter *)&this->vfptr, context);
}

// File Line: 627
// RVA: 0xBBF2A0
bool __fastcall hkaiDefaultAstarEdgeFilter::isEnabled(FaceCallbackEdgeFilterWrapper *this, hkaiAstarEdgeFilter::DirectedGraphIsEnabledCallbackContext *context)
{
  return hkaiAstarEdgeFilter::isEnabled((hkaiAstarEdgeFilter *)&this->vfptr, context);
}

// File Line: 640
// RVA: 0xBBE590
void __fastcall hkaiPathfindingUtil::_findNearestFeature(hkaiStreamingCollection *navMeshCollection, hkaiPathfindingUtil::NearestFeatureInput *input, hkaiPathfindingUtil::NearestFeatureCallback *callback, hkaiPathfindingUtil::NearestFeatureType callbackType, hkaiAstarOutputParameters *output)
{
  hkaiPathfindingUtil::NearestFeatureType v5; // er15
  hkaiPathfindingUtil::NearestFeatureCallback *v6; // r14
  hkaiPathfindingUtil::NearestFeatureInput *v7; // rdi
  hkaiStreamingCollection *v8; // rsi
  _QWORD *v9; // r9
  unsigned __int64 v10; // r8
  unsigned __int64 v11; // rax
  _QWORD *v12; // r8
  unsigned __int64 v13; // rcx
  unsigned __int64 v14; // rax
  int v15; // ebx
  int v16; // er8
  char v17; // r8
  __m128 v18; // xmm0
  float v19; // xmm2_4
  hkVector4f v20; // xmm1
  hkaiAstarCostModifier *v21; // rcx
  hkaiAstarEdgeFilter *v22; // rdx
  hkaiStreamingCollection::InstanceInfo *v23; // rax
  float v24; // xmm1_4
  hkaiAgentTraversalInfo v25; // rax
  signed __int64 v26; // r12
  signed int v27; // ecx
  signed int v28; // edx
  unsigned int v29; // ebx
  hkVector4f v30; // xmm6
  int v31; // er13
  _QWORD *v32; // r8
  _QWORD *v33; // rcx
  unsigned __int64 v34; // rax
  signed __int64 v35; // rcx
  int v36; // esi
  char v37; // bl
  hkaiAstarOutputParameters::SearchStatus v38; // edi
  _QWORD *v39; // r8
  _QWORD *v40; // rcx
  unsigned __int64 v41; // rax
  signed __int64 v42; // rcx
  hkaiSearchMemoryInfo memInfo; // [rsp+38h] [rbp-A0h]
  hkArray<char,hkContainerTempAllocator> array; // [rsp+50h] [rbp-88h]
  hkArray<char,hkContainerTempAllocator> v45; // [rsp+60h] [rbp-78h]
  hkaiSearchMemoryInfo hierarchyMemInfo; // [rsp+70h] [rbp-68h]
  void **v47; // [rsp+88h] [rbp-50h]
  int v48; // [rsp+90h] [rbp-48h]
  char v49; // [rsp+98h] [rbp-40h]
  hkaiAstarCostModifier *v50; // [rsp+A0h] [rbp-38h]
  hkaiPathfindingUtil::NearestFeatureCallback *v51; // [rsp+A8h] [rbp-30h]
  void *v52; // [rsp+B0h] [rbp-28h]
  int v53; // [rsp+B8h] [rbp-20h]
  int v54; // [rsp+BCh] [rbp-1Ch]
  int v55; // [rsp+C0h] [rbp-18h]
  hkaiNavMeshSearch::StartGoalInfo goalInfo; // [rsp+C8h] [rbp-10h]
  __int128 v57; // [rsp+F8h] [rbp+20h]
  void **v58; // [rsp+108h] [rbp+30h]
  int v59; // [rsp+110h] [rbp+38h]
  char v60; // [rsp+118h] [rbp+40h]
  hkaiAstarEdgeFilter *v61; // [rsp+120h] [rbp+48h]
  BOOL v62; // [rsp+128h] [rbp+50h]
  hkVector4f v63; // [rsp+138h] [rbp+60h]
  __m128 v64; // [rsp+148h] [rbp+70h]
  __m128 v65; // [rsp+158h] [rbp+80h]
  hkaiNavMeshSectionGraph graph; // [rsp+168h] [rbp+90h]
  hkaiNavMeshSearch v67; // [rsp+3A8h] [rbp+2D0h]
  hkaiSearchParameters::BufferSizes v68; // [rsp+910h] [rbp+838h]
  _BYTE *retaddr; // [rsp+928h] [rbp+850h]

  v5 = callbackType;
  v6 = callback;
  v7 = input;
  v8 = navMeshCollection;
  if ( input->m_startFaceKey != -1 )
  {
    if ( callbackType )
    {
      v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v13 = v12[1];
      if ( v13 < v12[3] )
      {
        *(_QWORD *)v13 = "LtfindNearestFaces";
        *(_QWORD *)(v13 + 16) = "Stinit";
        v14 = __rdtsc();
        *(_DWORD *)(v13 + 8) = v14;
        v12[1] = v13 + 24;
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
    v68 = v7->m_bufferSizes;
    v15 = v68.m_maxSearchStateSizeBytes;
    v16 = v68.m_maxOpenSetSizeBytes;
    v45.m_data = 0i64;
    if ( v68.m_maxOpenSetSizeBytes <= 0 )
      v16 = 0x20000;
    if ( v68.m_maxSearchStateSizeBytes <= 0 )
      v15 = 590336;
    hierarchyMemInfo.m_openSetBuffer = 0i64;
    hierarchyMemInfo.m_searchStateBuffer = 0i64;
    array.m_data = 0i64;
    array.m_size = 0;
    array.m_capacityAndFlags = 2147483648;
    v45.m_data = 0i64;
    v45.m_size = 0;
    v45.m_capacityAndFlags = 2147483648;
    hkaiSearchMemoryStorage::_setupArray(&array, 0i64, v16);
    hkaiSearchMemoryStorage::_setupArray(&v45, 0i64, v15);
    memInfo.m_openSetBuffer = array.m_data;
    memInfo.m_openSetSize = array.m_capacityAndFlags & 0x3FFFFFFF;
    memInfo.m_searchStateBuffer = v45.m_data;
    memInfo.m_searchStateSize = v45.m_capacityAndFlags & 0x3FFFFFFF;
    hkaiNavMeshSearch::hkaiNavMeshSearch(&v67, &memInfo, &hierarchyMemInfo);
    v17 = v7->m_projectedRadiusCheck.m_bool;
    v18 = v7->m_startPoint.m_quad;
    v19 = v7->m_searchRadius;
    v20.m_quad = (__m128)v7->m_up;
    v21 = v7->m_costModifier;
    v22 = v7->m_edgeFilter;
    v63.m_quad = (__m128)v7->m_startPoint;
    v64 = v20.m_quad;
    v18.m128_f32[0] = v19;
    v65 = _mm_shuffle_ps(v18, v18, 0);
    v48 = 0x1FFFF;
    v47 = &FaceCallbackCostModifierWrapper::`vftable;
    v49 = 1;
    v58 = &FaceCallbackEdgeFilterWrapper::`vftable;
    v50 = v21;
    v51 = v6;
    v52 = 0i64;
    v53 = 0;
    v54 = 2147483648;
    v55 = 0;
    v59 = 0x1FFFF;
    v60 = 1;
    v61 = v22;
    v62 = v17 != 0;
    if ( v5 == 1 )
    {
      v21 = (hkaiAstarCostModifier *)&v47;
      v22 = (hkaiAstarEdgeFilter *)&v58;
    }
    v23 = v8->m_instances.m_data;
    graph.m_up = (hkVector4f)v20.m_quad;
    v24 = v7->m_simpleRadiusThreshold;
    graph.m_streamingInfo = v23;
    v25 = v7->m_agentInfo;
    graph.m_costModifier = v21;
    *(float *)&v68.m_maxOpenSetSizeBytes = v19;
    graph.m_info = v25;
    v26 = (signed __int64)&v7->m_agentInfo;
    graph.m_edgeFilter = v22;
    v27 = 0;
    v28 = 0;
    *(_QWORD *)&graph.m_cachedIncomingEdge.m_oppositeEdge = -1i64;
    if ( v25.m_diameter > (float)(v24 * 2.0) )
      v27 = 4;
    v67.m_graph.m_storage = &graph;
    *(_DWORD *)&graph.m_cachedIncomingEdge.m_flags.m_storage = 4;
    graph.m_searchSphereRadius.m_real = _mm_shuffle_ps((__m128)LODWORD(v19), (__m128)LODWORD(v19), 0);
    graph.m_searchCapsuleRadius.m_real = _mm_shuffle_ps((__m128)LODWORD(FLOAT_N1_0), (__m128)LODWORD(FLOAT_N1_0), 0);
    graph.m_searchState = &v67.m_state;
    *(_QWORD *)&graph.m_cachedOutgoingEdge.m_oppositeEdge = -1i64;
    if ( v19 >= 0.0 )
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
    if ( v17 )
      v28 |= 0x10u;
    v29 = v7->m_startFaceKey;
    v30.m_quad = (__m128)v7->m_startPoint;
    goalInfo.m_goalPoints = (hkVector4f *)&v57;
    v57 = 0i64;
    goalInfo.m_startPoint = (hkVector4f)v30.m_quad;
    v68.m_maxOpenSetSizeBytes = -1;
    goalInfo.m_startFaceKey = v29;
    goalInfo.m_numGoals = 1;
    goalInfo.m_goalFaceKeys = (const unsigned int *)&v68;
    graph.m_flags = v28 | v27 & 0xFFFFFFEC;
    if ( v5 == 1 )
      v6->vfptr->faceTraversed(v6, v29, &v7->m_agentInfo);
    graph.m_startPoint = (hkVector4f)v30.m_quad;
    graph.m_startFaceKey = v29;
    hkaiNavMeshSearch::init(&v67, &graph, &v7->m_agentInfo, &goalInfo, 0);
    v31 = v7->m_maxNumberOfIterations;
    v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v33 = (_QWORD *)v32[1];
    if ( (unsigned __int64)v33 < v32[3] )
    {
      *v33 = "StAStar";
      v34 = __rdtsc();
      v35 = (signed __int64)(v33 + 2);
      *(_DWORD *)(v35 - 8) = v34;
      v32[1] = v35;
    }
    v36 = 0;
    v37 = 0;
    while ( v36 < v31 )
    {
      ++v36;
      v38 = hkaiNavMeshSearch::iteration(&v67);
      if ( v38 == 3 )
        v37 = (v67.m_openset.m_heapSize < v67.m_openset.m_maxSize) + 2;
      if ( v5 == CALLBACK_EDGE
        && (v67.m_lastClosedNode >> 22) - 1021 > 1
        && !v6->vfptr->edgeTraversed(v6, v67.m_lastClosedNode, (hkaiAgentTraversalInfo *)v26) )
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
      v42 = (signed __int64)(v40 + 2);
      *(_DWORD *)(v42 - 8) = v41;
      v39[1] = v42;
    }
    v58 = &hkBaseObject::`vftable;
    v53 = 0;
    if ( v54 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v52,
        4 * v54);
    v52 = 0i64;
    v54 = 2147483648;
    v47 = &hkBaseObject::`vftable;
    v45.m_size = 0;
    if ( v45.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v45.m_data,
        v45.m_capacityAndFlags & 0x3FFFFFFF);
    v45.m_data = 0i64;
    v45.m_capacityAndFlags = 2147483648;
    array.m_size = 0;
    if ( array.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array.m_data,
        array.m_capacityAndFlags & 0x3FFFFFFF);
    array.m_data = 0i64;
    array.m_capacityAndFlags = 2147483648;
    LODWORD(hierarchyMemInfo.m_searchStateBuffer) = 0;
    if ( SHIDWORD(hierarchyMemInfo.m_searchStateBuffer) >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        hierarchyMemInfo.m_openSetBuffer,
        HIDWORD(hierarchyMemInfo.m_searchStateBuffer) & 0x3FFFFFFF);
    hierarchyMemInfo.m_openSetBuffer = 0i64;
    v45.m_size = 0;
    HIDWORD(hierarchyMemInfo.m_searchStateBuffer) = 2147483648;
    if ( v45.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v45.m_data,
        v45.m_capacityAndFlags & 0x3FFFFFFF);
  }
}

// File Line: 793
// RVA: 0xBBDC60
void __fastcall hkaiPathfindingUtil::findGraphPath(hkaiStreamingCollection *collection, hkaiPathfindingUtil::FindGraphPathInput *input, hkaiPathfindingUtil::FindGraphPathOutput *output, hkaiStreamingCollection *hierarchyCollection)
{
  hkaiPathfindingUtil::FindGraphPathInput *v4; // rsi
  char v5; // r10
  char v6; // dl
  hkaiStreamingCollection *v7; // r13
  hkaiPathfindingUtil::FindGraphPathOutput *v8; // r15
  const unsigned int *v9; // r9
  __int64 v10; // r11
  bool v11; // zf
  unsigned int *v12; // rcx
  __int64 v13; // r8
  _QWORD *v14; // rax
  unsigned __int64 v15; // rcx
  _QWORD *v16; // r8
  unsigned __int64 v17; // rax
  char v18; // al
  bool v19; // r12
  unsigned int v20; // ecx
  signed int v21; // edi
  int v22; // er14
  int v23; // er9
  int v24; // er9
  __int64 v25; // rax
  unsigned int v26; // ecx
  signed int v27; // edi
  int v28; // er14
  char *v29; // rax
  int v30; // er9
  int v31; // er9
  hkaiStreamingCollection::InstanceInfo *v32; // rax
  hkaiAstarCostModifier *v33; // rax
  hkaiAstarEdgeFilter *v34; // rax
  hkaiAgentTraversalInfo v35; // rax
  hkaiStreamingCollection::InstanceInfo *v36; // r8
  _QWORD *v37; // r8
  _QWORD *v38; // rcx
  unsigned __int64 v39; // rax
  signed __int64 v40; // rcx
  int v41; // er12
  char v42; // r14
  int v43; // edi
  hkaiAstarOutputParameters::SearchStatus v44; // eax
  signed int v45; // ecx
  __int64 v46; // r9
  signed int v47; // er8
  __int64 v48; // rdx
  unsigned int *v49; // rax
  unsigned int v50; // edi
  _QWORD *v51; // r8
  _QWORD *v52; // rcx
  unsigned __int64 v53; // rax
  signed __int64 v54; // rcx
  _QWORD *v55; // rax
  _QWORD *v56; // rcx
  _QWORD *v57; // r8
  unsigned __int64 v58; // rax
  signed __int64 v59; // rcx
  hkaiSearchMemoryInfo hierarchyMemInfo; // [rsp+30h] [rbp-D0h]
  char *array; // [rsp+48h] [rbp-B8h]
  int v62; // [rsp+50h] [rbp-B0h]
  int v63; // [rsp+54h] [rbp-ACh]
  char *v64; // [rsp+58h] [rbp-A8h]
  int v65; // [rsp+60h] [rbp-A0h]
  int v66; // [rsp+64h] [rbp-9Ch]
  hkaiSearchMemoryInfo memInfo; // [rsp+68h] [rbp-98h]
  char *v68; // [rsp+80h] [rbp-80h]
  int v69; // [rsp+88h] [rbp-78h]
  int v70; // [rsp+8Ch] [rbp-74h]
  char *v71; // [rsp+90h] [rbp-70h]
  int v72; // [rsp+98h] [rbp-68h]
  int v73; // [rsp+9Ch] [rbp-64h]
  hkaiDirectedGraphSearch::StartGoalInfo goalInfo; // [rsp+A0h] [rbp-60h]
  hkaiDirectedGraphVisitor graph; // [rsp+D0h] [rbp-30h]
  hkaiDirectedGraphSearch v76; // [rsp+2F0h] [rbp+1F0h]
  hkaiStreamingCollection *v77; // [rsp+920h] [rbp+820h]
  __int64 result; // [rsp+928h] [rbp+828h]

  v77 = collection;
  v4 = input;
  v5 = 0;
  v6 = 0;
  v7 = hierarchyCollection;
  v8 = output;
  if ( v4->m_startNodeKeys.m_size > 0 )
  {
    v9 = v4->m_startNodeKeys.m_data;
    v10 = v4->m_startNodeKeys.m_size;
    do
    {
      v11 = *v9 == -1;
      ++v9;
      v6 |= !v11;
      --v10;
    }
    while ( v10 );
  }
  if ( v4->m_goalNodeKeys.m_size > 0 )
  {
    v12 = v4->m_goalNodeKeys.m_data;
    v13 = v4->m_goalNodeKeys.m_size;
    do
    {
      v11 = *v12 == -1;
      ++v12;
      v5 |= !v11;
      --v13;
    }
    while ( v13 );
  }
  if ( !v6 || !v5 )
  {
    v8->m_outputParameters.m_goalIndex = -1;
    v8->m_outputParameters.m_status.m_storage = 5;
    v8->m_outputParameters.m_numIterations = 0;
    return;
  }
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = v14[1];
  v16 = v14;
  if ( v15 < v14[3] )
  {
    *(_QWORD *)v15 = "LtFindGraphPath";
    *(_QWORD *)(v15 + 16) = "Stinit";
    v17 = __rdtsc();
    *(_DWORD *)(v15 + 8) = v17;
    v16[1] = v15 + 24;
  }
  v18 = v4->m_searchParameters.m_useHierarchicalHeuristic.m_bool;
  v19 = v18 && v7;
  v20 = 2147483648;
  v63 = 2147483648;
  array = 0i64;
  v62 = 0;
  v64 = 0i64;
  v65 = 0;
  v66 = 2147483648;
  if ( v18 )
  {
    result = (__int64)v4->m_searchParameters.m_hierarchyBufferSizes;
    v22 = HIDWORD(result);
    v21 = result;
    if ( (signed int)result <= 0 )
      v21 = 0x8000;
    if ( SHIDWORD(result) <= 0 )
      v22 = 147968;
    if ( v4->m_hierarchySearchBuffers.m_openSetBuffer )
    {
      array = v4->m_hierarchySearchBuffers.m_openSetBuffer;
      v62 = 0;
      v63 = v21 | 0x80000000;
    }
    else
    {
      if ( v21 > 0 )
      {
        v23 = v21;
        if ( v21 < 0 )
          v23 = 0;
        hkArrayUtil::_reserve(
          (hkResult *)&result,
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
          &array,
          v23,
          1);
        v20 = v66;
      }
      v62 = v21;
    }
    if ( v4->m_hierarchySearchBuffers.m_searchStateBuffer )
    {
      v64 = v4->m_hierarchySearchBuffers.m_searchStateBuffer;
      v65 = 0;
      v20 = v22 | 0x80000000;
      v66 = v22 | 0x80000000;
    }
    else
    {
      if ( (signed int)(v20 & 0x3FFFFFFF) < v22 )
      {
        v24 = v22;
        if ( v22 < (signed int)(2 * (v20 & 0x3FFFFFFF)) )
          v24 = 2 * (v20 & 0x3FFFFFFF);
        hkArrayUtil::_reserve(
          (hkResult *)&result,
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
          &v64,
          v24,
          1);
        v20 = v66;
      }
      v65 = v22;
    }
    hierarchyMemInfo.m_openSetBuffer = array;
    hierarchyMemInfo.m_openSetSize = v63 & 0x3FFFFFFF;
    hierarchyMemInfo.m_searchStateSize = v20 & 0x3FFFFFFF;
    hierarchyMemInfo.m_searchStateBuffer = v64;
  }
  else
  {
    hierarchyMemInfo.m_openSetBuffer = 0i64;
    *(_QWORD *)&hierarchyMemInfo.m_openSetSize = 0i64;
    hierarchyMemInfo.m_searchStateBuffer = 0i64;
  }
  v25 = (__int64)v4->m_searchParameters.m_bufferSizes;
  v26 = 2147483648;
  v68 = 0i64;
  v27 = v25;
  result = v25;
  v28 = HIDWORD(v25);
  v69 = 0;
  if ( (signed int)v25 <= 0 )
    v27 = 0x20000;
  if ( SHIDWORD(v25) <= 0 )
    v28 = 590336;
  v29 = v4->m_searchBuffers.m_openSetBuffer;
  v70 = 2147483648;
  v71 = 0i64;
  v72 = 0;
  v73 = 2147483648;
  if ( v29 )
  {
    v68 = v29;
    v69 = 0;
    v70 = v27 | 0x80000000;
  }
  else
  {
    if ( v27 > 0 )
    {
      v30 = v27;
      if ( v27 < 0 )
        v30 = 0;
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        &v68,
        v30,
        1);
      v26 = v73;
    }
    v69 = v27;
  }
  if ( v4->m_searchBuffers.m_searchStateBuffer )
  {
    v71 = v4->m_searchBuffers.m_searchStateBuffer;
    v72 = 0;
    v26 = v28 | 0x80000000;
    v73 = v28 | 0x80000000;
  }
  else
  {
    if ( (signed int)(v26 & 0x3FFFFFFF) < v28 )
    {
      v31 = v28;
      if ( v28 < (signed int)(2 * (v26 & 0x3FFFFFFF)) )
        v31 = 2 * (v26 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        &v71,
        v31,
        1);
      v26 = v73;
    }
    v72 = v28;
  }
  memInfo.m_openSetBuffer = v68;
  memInfo.m_searchStateSize = v26 & 0x3FFFFFFF;
  memInfo.m_openSetSize = v70 & 0x3FFFFFFF;
  memInfo.m_searchStateBuffer = v71;
  hkaiDirectedGraphSearch::hkaiDirectedGraphSearch(&v76, &memInfo, &hierarchyMemInfo);
  _mm_store_si128(
    (__m128i *)&graph.m_cachedNode,
    _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff));
  v76.m_state.m_heuristicWeight = v4->m_searchParameters.m_heuristicWeight;
  v32 = v77->m_instances.m_data;
  *(_QWORD *)&graph.m_cachedIncomingSectionId = -1i64;
  graph.m_cachedGeneralSectionId = -1;
  graph.m_streamingInfo = v32;
  v33 = v4->m_searchParameters.m_costModifier;
  graph.m_numGoals = 0;
  graph.m_costModifier = v33;
  v34 = v4->m_searchParameters.m_edgeFilter;
  graph.m_goalNodes = 0i64;
  graph.m_edgeFilter = v34;
  v35 = v4->m_agentInfo;
  graph.m_finalCosts = 0i64;
  graph.m_agentInfo = v35;
  graph.m_searchState = &v76.m_state;
  goalInfo.m_startNodeKeys = v4->m_startNodeKeys.m_data;
  goalInfo.m_numStartNodeKeys = v4->m_startNodeKeys.m_size;
  goalInfo.m_initialCosts = v4->m_initialCosts.m_data;
  goalInfo.m_goalNodeKeys = v4->m_goalNodeKeys.m_data;
  goalInfo.m_numGoals = v4->m_goalNodeKeys.m_size;
  goalInfo.m_finalCosts = v4->m_finalCosts.m_data;
  if ( v19 )
    v36 = v7->m_instances.m_data;
  else
    v36 = 0i64;
  hkaiDirectedGraphSearch::init(&v76, &graph, v36, &goalInfo);
  v37 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v38 = (_QWORD *)v37[1];
  if ( (unsigned __int64)v38 < v37[3] )
  {
    *v38 = "StAStar";
    v39 = __rdtsc();
    v40 = (signed __int64)(v38 + 2);
    *(_DWORD *)(v40 - 8) = v39;
    v37[1] = v40;
  }
  v41 = v4->m_maxNumberOfIterations;
  v42 = 0;
  v43 = 0;
  while ( v43 < v41 )
  {
    ++v43;
    v44 = hkaiDirectedGraphSearch::iteration(&v76);
    v45 = v44;
    if ( v44 == 3 )
    {
      v42 = (v76.m_openSet.m_heapSize < v76.m_openSet.m_maxSize) + 2;
      goto LABEL_66;
    }
    if ( v44 )
      goto LABEL_66;
  }
  v45 = 3;
  v42 = 1;
LABEL_66:
  v8->m_outputParameters.m_terminationCause.m_storage = v42;
  v8->m_outputParameters.m_numIterations = v43;
  v8->m_outputParameters.m_status.m_storage = v45;
  v46 = v4->m_goalNodeKeys.m_size;
  v47 = 0;
  v48 = 0i64;
  if ( v46 <= 0 )
  {
LABEL_70:
    v47 = -1;
  }
  else
  {
    v49 = v4->m_goalNodeKeys.m_data;
    while ( *v49 != v76.m_lastClosedNode )
    {
      ++v48;
      ++v47;
      ++v49;
      if ( v48 >= v46 )
        goto LABEL_70;
    }
  }
  v8->m_outputParameters.m_goalIndex = v47;
  if ( v45 == 1 )
  {
    v50 = v4->m_goalNodeKeys.m_data[v47];
    goto LABEL_75;
  }
  if ( v45 == 3 )
  {
    v50 = v76.m_state.m_bestNode;
LABEL_75:
    v76.m_state.m_currentNodeState = hkaiHashSearchState::getNodeState(&v76.m_state, v50);
    v76.m_state.m_parentNodeState = v76.m_state.m_currentNodeState;
    v76.m_state.m_parentIndex = (signed __int16)((_QWORD)((char *)v76.m_state.m_currentNodeState
                                                        - (char *)v76.m_state.m_nodes) >> 4);
    v8->m_outputParameters.m_pathLength = v76.m_state.m_currentNodeState->m_gCost;
    v51 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v52 = (_QWORD *)v51[1];
    if ( (unsigned __int64)v52 < v51[3] )
    {
      *v52 = "Stoutput";
      v53 = __rdtsc();
      v54 = (signed __int64)(v52 + 2);
      *(_DWORD *)(v54 - 8) = v53;
      v51[1] = v54;
    }
    hkaiSearchStateUtils::getPath(&v76.m_state, v50, 0, &v8->m_pathNodes, 0x7FFFFFFF);
  }
  v55 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v56 = (_QWORD *)v55[1];
  v57 = v55;
  if ( (unsigned __int64)v56 < v55[3] )
  {
    *v56 = "lt";
    v58 = __rdtsc();
    v59 = (signed __int64)(v56 + 2);
    *(_DWORD *)(v59 - 8) = v58;
    v57[1] = v59;
  }
  v72 = 0;
  if ( v73 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v71,
      v73 & 0x3FFFFFFF);
  v71 = 0i64;
  v73 = 2147483648;
  v69 = 0;
  if ( v70 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v68,
      v70 & 0x3FFFFFFF);
  v68 = 0i64;
  v70 = 2147483648;
  v65 = 0;
  if ( v66 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v64,
      v66 & 0x3FFFFFFF);
  v64 = 0i64;
  v66 = 2147483648;
  v62 = 0;
  if ( v63 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      v63 & 0x3FFFFFFF);
}

// File Line: 924
// RVA: 0xBBE350
void __fastcall hkaiPathfindingUtil::findGraphPath(hkaiDirectedGraphExplicitCost *graph, hkaiPathfindingUtil::FindGraphPathInput *input, hkaiPathfindingUtil::FindGraphPathOutput *output, hkaiDirectedGraphExplicitCost *clusterGraph)
{
  hkaiDirectedGraphExplicitCost *v4; // rbx
  hkaiDirectedGraphExplicitCost *v5; // rdi
  hkaiPathfindingUtil::FindGraphPathOutput *v6; // rsi
  hkaiPathfindingUtil::FindGraphPathInput *v7; // r14
  int v8; // er9
  hkaiStreamingCollection::InstanceInfo *v9; // rax
  __int64 v10; // rdx
  hkaiDirectedGraphInstance **v11; // rax
  int v12; // er9
  hkaiStreamingCollection::InstanceInfo *v13; // r8
  __int64 v14; // rdx
  hkaiDirectedGraphInstance **v15; // rax
  hkaiStreamingCollection array; // [rsp+30h] [rbp-D0h]
  hkaiStreamingCollection hierarchyCollection; // [rsp+60h] [rbp-A0h]
  hkaiDirectedGraphInstance v18; // [rsp+90h] [rbp-70h]
  hkaiDirectedGraphInstance v19; // [rsp+1A0h] [rbp+A0h]
  hkResult result; // [rsp+2E8h] [rbp+1E8h]

  v4 = graph;
  v5 = clusterGraph;
  v6 = output;
  v7 = input;
  hkaiDirectedGraphInstance::hkaiDirectedGraphInstance(&v19);
  hkaiDirectedGraphInstance::tempInit(&v19, v4);
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) < 1 )
  {
    v8 = 1;
    if ( 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) > 1 )
      v8 = 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array.m_instances,
      v8,
      48);
  }
  v9 = array.m_instances.m_data;
  v10 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    v11 = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( v11 != (hkaiDirectedGraphInstance **)16 )
      {
        *(v11 - 2) = 0i64;
        *(v11 - 1) = 0i64;
        *v11 = 0i64;
        v11[1] = 0i64;
        v11[2] = 0i64;
        *((_DWORD *)v11 + 6) = -1;
      }
      v11 += 6;
      --v10;
    }
    while ( v10 );
    v9 = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  v9->m_clusterGraphInstance = &v19;
  if ( v5 )
  {
    hkaiDirectedGraphInstance::hkaiDirectedGraphInstance(&v18);
    hkaiDirectedGraphInstance::tempInit(&v18, v5);
    hkaiStreamingCollection::hkaiStreamingCollection(&hierarchyCollection);
    hierarchyCollection.m_isTemporary.m_bool = 1;
    if ( (hierarchyCollection.m_instances.m_capacityAndFlags & 0x3FFFFFFF) < 1 )
    {
      v12 = 1;
      if ( 2 * (hierarchyCollection.m_instances.m_capacityAndFlags & 0x3FFFFFFF) > 1 )
        v12 = 2 * (hierarchyCollection.m_instances.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &hierarchyCollection.m_instances,
        v12,
        48);
    }
    v13 = hierarchyCollection.m_instances.m_data;
    v14 = 1 - hierarchyCollection.m_instances.m_size;
    if ( 1 - hierarchyCollection.m_instances.m_size > 0 )
    {
      v15 = &hierarchyCollection.m_instances.m_data[hierarchyCollection.m_instances.m_size].m_clusterGraphInstance;
      do
      {
        if ( v15 != (hkaiDirectedGraphInstance **)16 )
        {
          *(v15 - 2) = 0i64;
          *(v15 - 1) = 0i64;
          *v15 = 0i64;
          v15[1] = 0i64;
          v15[2] = 0i64;
          *((_DWORD *)v15 + 6) = -1;
        }
        v15 += 6;
        --v14;
      }
      while ( v14 );
      v13 = hierarchyCollection.m_instances.m_data;
    }
    hierarchyCollection.m_instances.m_size = 1;
    v13->m_clusterGraphInstance = &v18;
    hkaiPathfindingUtil::findGraphPath(&array, v7, v6, &hierarchyCollection);
    hkaiStreamingCollection::~hkaiStreamingCollection(&hierarchyCollection);
    hkaiDirectedGraphInstance::~hkaiDirectedGraphInstance(&v18);
  }
  else
  {
    hkaiPathfindingUtil::findGraphPath(&array, v7, v6, 0i64);
  }
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
  hkaiDirectedGraphInstance::~hkaiDirectedGraphInstance(&v19);
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


// File Line: 30
// RVA: 0xBF9440
void __fastcall hkaiHierarchyUtils::ClusterSettings::ClusterSettings(hkaiHierarchyUtils::ClusterSettings *this)
{
  this->m_desiredFacesPerCluster = 20;
  this->m_ensureClusterPerRegion.m_bool = 1;
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
  this->m_agentInfo = 0i64;
}

// File Line: 36
// RVA: 0xBF94B0
void __fastcall hkaiHierarchyUtils::ClusterSettings::ClusterSettings(hkaiHierarchyUtils::ClusterSettings *this, hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 42
// RVA: 0xBF9A60
signed __int64 __fastcall hkaiHierarchyUtils::SemiSparse2dArraySorted::indexOf(hkaiHierarchyUtils::SemiSparse2dArraySorted *this, hkArray<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost,hkContainerHeapAllocator> *a, int y, int *greaterThanIndex)
{
  __int64 v4; // rbx
  unsigned int v5; // er10
  __int64 v6; // rcx
  hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost *v7; // rax
  signed __int64 result; // rax

  v4 = a->m_size;
  v5 = 0;
  v6 = 0i64;
  if ( (signed int)v4 <= 0 )
  {
LABEL_6:
    *greaterThanIndex = v4;
    result = 0xFFFFFFFFi64;
  }
  else
  {
    v7 = a->m_data;
    while ( y != v7->t )
    {
      if ( y < v7->t )
      {
        *greaterThanIndex = v5;
        return 0xFFFFFFFFi64;
      }
      ++v6;
      ++v5;
      ++v7;
      if ( v6 >= v4 )
        goto LABEL_6;
    }
    result = v5;
  }
  return result;
}

// File Line: 62
// RVA: 0xBF9AC0
signed __int64 __fastcall hkaiHierarchyUtils::SemiSparse2dArraySorted::indexOf_binarySearch(hkaiHierarchyUtils::SemiSparse2dArraySorted *this, hkArray<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost,hkContainerHeapAllocator> *a, int y, int *greaterThanIndex)
{
  int v4; // edi
  hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost *v5; // rbx
  int v6; // er11
  int v7; // edx
  int v8; // er10
  signed __int64 result; // rax
  int v10; // eax
  int v11; // edx

  v4 = a->m_size;
  v5 = a->m_data;
  v6 = 0;
  v7 = a->m_data->t;
  v8 = v4 - 1;
  if ( v7 == y )
    return 0i64;
  v10 = v5[v8].t;
  if ( v10 == y )
    return (unsigned int)v8;
  if ( v10 >= y )
  {
    if ( v7 <= y )
    {
      if ( v8 <= 1 )
      {
LABEL_15:
        *greaterThanIndex = v8;
        result = 0xFFFFFFFFi64;
      }
      else
      {
        while ( 1 )
        {
          result = (v8 + v6) / 2;
          v11 = v5[(signed int)result].t;
          if ( y == v11 )
            break;
          if ( y >= v11 )
            v6 = result;
          else
            v8 = result;
          if ( v8 - v6 <= 1 )
            goto LABEL_15;
        }
      }
    }
    else
    {
      *greaterThanIndex = 0;
      result = 0xFFFFFFFFi64;
    }
  }
  else
  {
    *greaterThanIndex = v4;
    result = 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 105
// RVA: 0xBF9B80
void __fastcall hkaiHierarchyUtils::SemiSparse2dArraySorted::setSize(hkaiHierarchyUtils::SemiSparse2dArraySorted *this, int n, float r)
{
  hkArray<hkArray<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost,hkContainerHeapAllocator>,hkContainerHeapAllocator> *v3; // r14
  __int64 v4; // rbp
  int v5; // eax
  hkaiHierarchyUtils::SemiSparse2dArraySorted *v6; // r15
  int v7; // eax
  int v8; // er9
  int v9; // eax
  __int64 v10; // rsi
  __int64 v11; // rdi
  int *v12; // rbx
  int v13; // er8
  signed __int64 v14; // rax
  int v15; // ecx
  signed __int64 v16; // rdx
  __int64 v17; // rax
  signed __int64 v18; // rdx
  __int64 v19; // rbx
  hkArray<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost,hkContainerHeapAllocator> *v20; // rdi
  int v21; // er8
  hkResult result; // [rsp+78h] [rbp+10h]

  v3 = &this->m_costs;
  v4 = n;
  v5 = this->m_costs.m_capacityAndFlags & 0x3FFFFFFF;
  v6 = this;
  if ( v5 < n )
  {
    v7 = 2 * v5;
    v8 = v4;
    if ( (signed int)v4 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v8, 16);
  }
  v9 = v3->m_size - v4 - 1;
  v10 = v4;
  v11 = v9;
  if ( v9 >= 0 )
  {
    v12 = &v3->m_data[v4].m_capacityAndFlags + 4 * v9;
    do
    {
      v13 = *v12;
      *(v12 - 1) = 0;
      if ( v13 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v12 - 3),
          8 * v13);
      *(_QWORD *)(v12 - 3) = 0i64;
      *v12 = 2147483648;
      v12 -= 4;
      --v11;
    }
    while ( v11 >= 0 );
  }
  v14 = v3->m_size;
  v15 = v4 - v14;
  v16 = v14;
  v17 = (signed int)v4 - (signed int)v14;
  v18 = (signed __int64)&v3->m_data[v16];
  if ( v15 > 0 )
  {
    do
    {
      if ( v18 )
      {
        *(_QWORD *)v18 = 0i64;
        *(_DWORD *)(v18 + 8) = 0;
        *(_DWORD *)(v18 + 12) = 2147483648;
      }
      v18 += 16i64;
      --v17;
    }
    while ( v17 );
  }
  v3->m_size = v4;
  v6->m_default = r;
  v6->m_n = v4;
  if ( v4 > 0 )
  {
    v19 = 0i64;
    do
    {
      v20 = v3->m_data;
      v21 = v3->m_data[v19].m_capacityAndFlags;
      v3->m_data[v19].m_size = 0;
      if ( v21 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v20[v19].m_data,
          8 * v21);
      v20[v19].m_data = 0i64;
      v20[v19].m_capacityAndFlags = 2147483648;
      ++v19;
      --v10;
    }
    while ( v10 );
  }
}

// File Line: 116
// RVA: 0xBF9D10
float __fastcall hkaiHierarchyUtils::SemiSparse2dArraySorted::get(hkaiHierarchyUtils::SemiSparse2dArraySorted *this, int x, int y)
{
  hkaiHierarchyUtils::SemiSparse2dArraySorted *v3; // rdi
  hkArray<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost,hkContainerHeapAllocator> *v4; // rbx
  int v5; // eax
  float result; // xmm0_4
  int greaterThanIndex; // [rsp+38h] [rbp+10h]

  v3 = this;
  v4 = &this->m_costs.m_data[x];
  v5 = hkaiHierarchyUtils::SemiSparse2dArraySorted::indexOf_binarySearch(this, v4, y, &greaterThanIndex);
  if ( v5 == -1 )
    result = v3->m_default;
  else
    result = v4->m_data[v5].r;
  return result;
}

// File Line: 129
// RVA: 0xBF9D70
void __fastcall hkaiHierarchyUtils::SemiSparse2dArraySorted::set(hkaiHierarchyUtils::SemiSparse2dArraySorted *this, int x, int y, float r)
{
  int v4; // edi
  hkArray<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost,hkContainerHeapAllocator> *v5; // rbx
  __int64 v6; // rax
  hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost *v7; // rcx
  hkArray<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost,hkContainerHeapAllocator> *v8; // rdx
  int v9; // eax
  hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost t; // [rsp+40h] [rbp+8h]
  int greaterThanIndex; // [rsp+48h] [rbp+10h]

  v4 = y;
  v5 = &this->m_costs.m_data[x];
  if ( v5->m_size )
  {
    v8 = &this->m_costs.m_data[x];
    greaterThanIndex = -1;
    v9 = hkaiHierarchyUtils::SemiSparse2dArraySorted::indexOf_binarySearch(this, v8, y, &greaterThanIndex);
    if ( v9 == -1 )
    {
      t.r = r;
      t.t = v4;
      hkArrayBase<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost>::_insertAt(
        (hkArrayBase<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost> *)&v5->m_data,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        greaterThanIndex,
        &t);
    }
    else
    {
      v5->m_data[v9].r = r;
    }
  }
  else
  {
    if ( !(v5->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 8);
    v6 = v5->m_size;
    v7 = v5->m_data;
    v5->m_size = v6 + 1;
    v7[v6].t = v4;
    v7[v6].r = r;
  }
}

// File Line: 159
// RVA: 0xBF9F10
void __fastcall hkaiHierarchyUtils::SemiSparse2dArraySorted::validate(hkaiHierarchyUtils::SemiSparse2dArraySorted *this)
{
  ;
}

// File Line: 169
// RVA: 0xBF9F20
void __fastcall hkaiHierarchyUtils::SemiSparse2dArraySorted::validateSub(hkaiHierarchyUtils::SemiSparse2dArraySorted *this, int i)
{
  ;
}

// File Line: 182
// RVA: 0xBF9E50
void __fastcall hkaiHierarchyUtils::SemiSparse2dArraySorted::findMinValFromSet(hkaiHierarchyUtils::SemiSparse2dArraySorted *this, int x, hkArrayBase<hkaiHierarchyUtils::RepGroupPair> *sortedReps, int *minIndex, float *minCost)
{
  int v5; // er10
  int *v6; // r14
  hkArrayBase<hkaiHierarchyUtils::RepGroupPair> *v7; // rbx
  hkArray<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost,hkContainerHeapAllocator> *v8; // rdi
  int v9; // er9
  __int64 v10; // r8
  __int64 v11; // rdx
  int v12; // er11
  int v13; // eax
  float v14; // xmm0_4

  *minIndex = -1;
  *minCost = this->m_default;
  v5 = 0;
  v6 = minIndex;
  v7 = sortedReps;
  v8 = &this->m_costs.m_data[x];
  v9 = 0;
  if ( v8->m_size > 0 )
  {
    v10 = 0i64;
    v11 = 0i64;
    do
    {
      if ( v9 >= v7->m_size )
        return;
      v12 = v8->m_data[v11].t;
      v13 = v7->m_data[v10].m_representative;
      if ( v12 == v13 )
      {
        v14 = v8->m_data[v11].r;
        if ( v14 < *minCost )
        {
          *minCost = v14;
          *v6 = v7->m_data[v10].m_group;
        }
        ++v5;
        ++v11;
      }
      else if ( v12 < v13 )
      {
        ++v5;
        ++v11;
        continue;
      }
      ++v9;
      ++v10;
    }
    while ( v5 < v8->m_size );
  }
}

// File Line: 225
// RVA: 0xBF9F30
void __fastcall hkaiHierarchyUtils::CostAdaptor::CostAdaptor(hkaiHierarchyUtils::CostAdaptor *this, hkaiHierarchyUtils::SemiSparse2dArraySorted *costs, int sourceNid)
{
  this->m_costs = costs;
  this->m_sourceNid = sourceNid;
}

// File Line: 228
// RVA: 0xBF9F50
void __fastcall hkaiHierarchyUtils::CostAdaptor::getCost(hkaiHierarchyUtils::CostAdaptor *this, int nid)
{
  hkaiHierarchyUtils::SemiSparse2dArraySorted::get(this->m_costs, this->m_sourceNid, nid);
}

// File Line: 232
// RVA: 0xBF9F70
void __fastcall hkaiHierarchyUtils::CostAdaptor::setCost(hkaiHierarchyUtils::CostAdaptor *this, hkaiGraphMultiDistanceHeuristic<hkaiNavMeshFaceGraph> *h_unused, int nid, float d)
{
  hkaiHierarchyUtils::SemiSparse2dArraySorted::set(this->m_costs, this->m_sourceNid, nid, d);
}

// File Line: 236
// RVA: 0xBF9F90
bool __fastcall hkaiHierarchyUtils::CostAdaptor::estimatedCostLess(hkaiHierarchyUtils::CostAdaptor *this, int a, int b)
{
  int v3; // ebx
  hkaiHierarchyUtils::SemiSparse2dArraySorted *v4; // rdi
  int v5; // esi
  float v6; // xmm6_4

  v3 = this->m_sourceNid;
  v4 = this->m_costs;
  v5 = b;
  v6 = hkaiHierarchyUtils::SemiSparse2dArraySorted::get(this->m_costs, this->m_sourceNid, a);
  return hkaiHierarchyUtils::SemiSparse2dArraySorted::get(v4, v3, v5) > v6;
}

// File Line: 241
// RVA: 0xBF9FF0
void __fastcall hkaiHierarchyUtils::CostAdaptor::estimatedCost(hkaiHierarchyUtils::CostAdaptor *this, int a)
{
  hkaiHierarchyUtils::SemiSparse2dArraySorted::get(this->m_costs, this->m_sourceNid, a);
}

// File Line: 246
// RVA: 0xBFA010
void __fastcall hkaiHierarchyUtils::CostAdaptor::estimatedCostCurrent(hkaiHierarchyUtils::CostAdaptor *this, int a)
{
  hkaiHierarchyUtils::CostAdaptor::estimatedCost(this, a);
}

// File Line: 254
// RVA: 0xBFADE0
float __fastcall getCostBetweenFaces(hkaiNavMeshFaceGraph *graph, __int64 nstart, int nend, hkaiNavMeshPathSearchParameters *searchParams, hkaiAgentTraversalInfo *agentInfo)
{
  unsigned int v5; // er14
  hkaiNavMeshFaceGraph *v6; // rsi
  hkaiNavMeshInstance *v7; // rdi
  hkaiNavMeshPathSearchParameters *v8; // rbx
  unsigned int v9; // er15
  hkVector4f *v10; // r9
  __m128i v11; // xmm1
  hkaiAgentTraversalInfo v12; // rcx
  hkaiAstarCostModifier *v13; // rax
  __m128 v14; // xmm2
  __m128 v15; // xmm2
  __m128 v16; // xmm4
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  __m128i v22; // xmm1
  hkaiStreamingCollection *v23; // rcx
  float v24; // xmm6_4
  hkaiPathfindingUtil::FindPathOutput output; // [rsp+20h] [rbp-E0h]
  hkaiPathfindingUtil::FindPathInput input; // [rsp+60h] [rbp-A0h]
  int v28[4]; // [rsp+120h] [rbp+20h]
  char v29; // [rsp+130h] [rbp+30h]
  int v30[4]; // [rsp+140h] [rbp+40h]
  int faceIndex[4]; // [rsp+150h] [rbp+50h]
  int v32[4]; // [rsp+160h] [rbp+60h]

  v5 = nend;
  v6 = graph;
  v7 = graph->m_collection->m_instances.m_data->m_instancePtr;
  v8 = searchParams;
  v9 = nstart;
  hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
    (hkaiNavMeshUtils *)v7,
    (hkaiNavMeshInstance *)nstart,
    (__int64)faceIndex,
    (hkVector4f *)searchParams);
  hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
    (hkaiNavMeshUtils *)v7,
    (hkaiNavMeshInstance *)v5,
    (__int64)v30,
    v10);
  hkaiPathfindingUtil::FindPathInput::FindPathInput(&input, 1);
  input.m_startFaceKey = v9;
  *input.m_goalFaceKeys.m_data = v5;
  input.m_startPoint = *(hkVector4f *)faceIndex;
  *input.m_goalPoints.m_data = *(hkVector4f *)v30;
  v11 = _mm_unpacklo_epi16((__m128i)0i64, _mm_loadl_epi64((const __m128i *)v8));
  v12 = *agentInfo;
  *(_QWORD *)input.m_searchParameters.m_up.m_vec = *(_QWORD *)v8->m_up.m_vec;
  v13 = v8->m_costModifier;
  input.m_agentInfo = v12;
  input.m_searchParameters.m_costModifier = v13;
  v14 = _mm_mul_ps(
          _mm_cvtepi32_ps(_mm_add_epi32(v11, _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset))),
          (__m128)xmmword_141A713A0);
  v15 = _mm_mul_ps(v14, v14);
  input.m_searchParameters.m_edgeFilter = v8->m_edgeFilter;
  *(_QWORD *)&input.m_searchParameters.m_validateInputs.m_bool = *(_QWORD *)&v8->m_validateInputs.m_bool;
  *(_QWORD *)&input.m_searchParameters.m_heuristicWeight = *(_QWORD *)&v8->m_heuristicWeight;
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  *(_QWORD *)&input.m_searchParameters.m_maximumPathLength = *(_QWORD *)&v8->m_maximumPathLength;
  v17 = _mm_rsqrt_ps(v16);
  *(_QWORD *)&input.m_searchParameters.m_searchCapsuleRadius = *(_QWORD *)&v8->m_searchCapsuleRadius;
  *(_QWORD *)&input.m_searchParameters.m_bufferSizes.m_maxSearchStateSizeBytes = *(_QWORD *)&v8->m_bufferSizes.m_maxSearchStateSizeBytes;
  *(_QWORD *)&input.m_searchParameters.m_hierarchyBufferSizes.m_maxSearchStateSizeBytes = *(_QWORD *)&v8->m_hierarchyBufferSizes.m_maxSearchStateSizeBytes;
  if ( COERCE_FLOAT(
         _mm_andnot_ps(
           _mm_cmpleps(v16, (__m128)0i64),
           _mm_mul_ps(
             _mm_mul_ps(
               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
               _mm_mul_ps(*(__m128 *)_xmm, v17)),
             v16))) < 0.5 )
  {
    hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)&v29,
      (hkSimdFloat32 *)v7,
      (hkaiNavMeshInstance *)v9,
      (__int64)v32);
    hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)&v29,
      (hkSimdFloat32 *)v7,
      (hkaiNavMeshInstance *)v5,
      (__int64)v28);
    v18 = _mm_add_ps(*(__m128 *)v32, *(__m128 *)v28);
    v19 = _mm_mul_ps(v18, v18);
    v20 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
            _mm_shuffle_ps(v19, v19, 170));
    v21 = _mm_mul_ps(
            _mm_mul_ps(_mm_andnot_ps(_mm_cmpleps(v20, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v20))), v18),
            (__m128)xmmword_141A71390);
    v22 = _mm_add_epi32(
            _mm_xor_si128(
              (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v21),
              _mm_cvttps_epi32(v21)),
            _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset));
    input.m_searchParameters.m_up.m_vec[0] = _mm_extract_epi16(v22, 1);
    input.m_searchParameters.m_up.m_vec[1] = _mm_extract_epi16(v22, 3);
    input.m_searchParameters.m_up.m_vec[2] = _mm_extract_epi16(v22, 5);
  }
  v23 = v6->m_collection;
  output.m_outputParameters.m_pathLength = FLOAT_3_40282e38;
  input.m_searchParameters.m_outputPathFlags.m_storage = 0;
  *(_DWORD *)&output.m_memSizeAndFlags = 0x1FFFF;
  output.m_visitedEdges.m_data = 0i64;
  output.vfptr = (hkBaseObjectVtbl *)&hkaiPathfindingUtil::FindPathOutput::`vftable';
  output.m_visitedEdges.m_size = 0;
  output.m_visitedEdges.m_capacityAndFlags = 2147483648;
  output.m_pathOut.m_data = 0i64;
  output.m_pathOut.m_size = 0;
  output.m_pathOut.m_capacityAndFlags = 2147483648;
  output.m_outputParameters.m_numIterations = 0;
  output.m_outputParameters.m_goalIndex = -1;
  *(_WORD *)&output.m_outputParameters.m_status.m_storage = 0;
  hkaiPathfindingUtil::findPath(v23, &input, &output);
  output.m_pathOut.m_size = 0;
  v24 = output.m_outputParameters.m_pathLength;
  if ( output.m_pathOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      output.m_pathOut.m_data,
      48 * (output.m_pathOut.m_capacityAndFlags & 0x3FFFFFFF));
  output.m_pathOut.m_data = 0i64;
  output.m_pathOut.m_capacityAndFlags = 2147483648;
  output.m_visitedEdges.m_size = 0;
  if ( output.m_visitedEdges.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      output.m_visitedEdges.m_data,
      4 * output.m_visitedEdges.m_capacityAndFlags);
  output.m_visitedEdges.m_data = 0i64;
  output.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  output.m_visitedEdges.m_capacityAndFlags = 2147483648;
  input.m_goalFaceKeys.m_size = 0;
  input.vfptr = (hkBaseObjectVtbl *)&hkaiPathfindingUtil::FindPathInput::`vftable';
  if ( input.m_goalFaceKeys.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      input.m_goalFaceKeys.m_data,
      4 * input.m_goalFaceKeys.m_capacityAndFlags);
  input.m_goalFaceKeys.m_data = 0i64;
  input.m_goalFaceKeys.m_capacityAndFlags = 2147483648;
  input.m_goalPoints.m_size = 0;
  if ( input.m_goalPoints.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      input.m_goalPoints.m_data,
      16 * input.m_goalPoints.m_capacityAndFlags);
  return v24;
}

// File Line: 332
// RVA: 0xBFD400
void __fastcall hkaiSimpleClusterGenerator::getNearestNeighborCosts(hkaiNavMeshFaceGraph *graph, hkArrayBase<int> *nodesForRegion, hkaiHierarchyUtils::SemiSparse2dArraySorted *costs, int numToFill)
{
  hkArrayBase<int> *v4; // r14
  hkaiNavMeshFaceGraph *listener; // rdi
  __int64 v6; // r15
  hkaiHierarchyUtils::SemiSparse2dArraySorted *v7; // r13
  __int64 v8; // rbx
  int v9; // esi
  int v10; // er12
  __int64 v11; // r15
  unsigned int v12; // esi
  hkVector4f *v13; // r9
  int v14; // er9
  hkaiNavMeshUtils **v15; // rcx
  hkaiHeapOpenSet::IndexCostPair *v16; // rax
  int v17; // er8
  hkaiSearchStateNode *v18; // rax
  hkaiSearchStateNode *v19; // rbx
  float v20; // xmm0_4
  hkaiHeapOpenSet::IndexCostPair *v21; // rax
  __int64 v22; // r8
  int v23; // er10
  hkaiHeapOpenSet::IndexCostPair *v24; // rdx
  int v25; // ebx
  float v26; // er11
  __int64 i; // r9
  __int64 v28; // rcx
  bool v29; // zf
  bool v30; // sf
  __int64 v31; // rcx
  hkaiHeapOpenSet::IndexCostPair *v32; // [rsp+40h] [rbp-C0h]
  int v33; // [rsp+48h] [rbp-B8h]
  int v34; // [rsp+4Ch] [rbp-B4h]
  hkaiHeapOpenSet openset; // [rsp+50h] [rbp-B0h]
  char *array; // [rsp+60h] [rbp-A0h]
  int size; // [rsp+68h] [rbp-98h]
  int v38; // [rsp+6Ch] [rbp-94h]
  hkResult result; // [rsp+70h] [rbp-90h]
  __int64 v40; // [rsp+78h] [rbp-88h]
  hkaiHashSearchState flags; // [rsp+80h] [rbp-80h]
  hkaiHierarchyUtils::CostAdaptor pathCost; // [rsp+E0h] [rbp-20h]
  int faceIndex[4]; // [rsp+F0h] [rbp-10h]
  hkaiGraphMultiDistanceHeuristic<hkaiNavMeshFaceGraph> heuristic; // [rsp+100h] [rbp+0h]
  char v45; // [rsp+1D0h] [rbp+D0h]
  hkResult v46; // [rsp+1D8h] [rbp+D8h]

  v4 = nodesForRegion;
  listener = graph;
  v6 = numToFill;
  v7 = costs;
  hkaiHierarchyUtils::SemiSparse2dArraySorted::setSize(
    costs,
    graph->m_collection->m_instances.m_data->m_instancePtr->m_numOriginalFaces
  + graph->m_collection->m_instances.m_data->m_instancePtr->m_ownedFaces.m_size,
    1000000.0);
  v8 = 0i64;
  v9 = 0;
  if ( v4->m_size > 0 )
  {
    do
    {
      hkaiHierarchyUtils::SemiSparse2dArraySorted::set(
        v7,
        *(int *)((char *)v4->m_data + v8),
        *(int *)((char *)v4->m_data + v8),
        0.0);
      ++v9;
      v8 += 4i64;
    }
    while ( v9 < v4->m_size );
    LODWORD(v8) = 0;
  }
  v10 = v8;
  if ( v4->m_size > 0 )
  {
    v40 = v6;
    v11 = 0i64;
    do
    {
      v12 = v4->m_data[v11];
      array = 0i64;
      size = 0;
      v38 = 2147483648;
      v32 = 0i64;
      v33 = 0;
      v34 = 2147483648;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 2816, 1);
      size = 2816;
      if ( (v34 & 0x3FFFFFFF) >= 1024 )
      {
        v46.m_enum = (signed int)v8;
      }
      else
      {
        v14 = 1024;
        if ( 2 * (v34 & 0x3FFFFFFF) > 1024 )
          v14 = 2 * (v34 & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&v46, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v32, v14, 1);
      }
      v33 = 1024;
      v15 = (hkaiNavMeshUtils **)listener->m_collection->m_instances.m_data;
      heuristic.m_graph = listener;
      hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(*v15, 0i64, (__int64)faceIndex, v13);
      heuristic.m_goals[0].m_position = *(hkVector4f *)faceIndex;
      heuristic.m_goals[0].m_index.m_storage = 0;
      heuristic.m_numGoals = 1;
      hkaiHierarchyUtils::CostAdaptor::CostAdaptor(&pathCost, v7, v12);
      v16 = v32;
      v17 = size;
      _mm_store_si128((__m128i *)&flags, (__m128i)0i64);
      openset.m_heap = v16;
      openset.m_heapSize = 0;
      openset.m_maxSize = (unsigned __int64)v33 >> 3;
      flags.m_hashFirst = 0i64;
      *(_QWORD *)&flags.m_nodeCapacity = 0i64;
      flags.m_heuristicWeight = 1.0;
      flags.m_bestNode = -1;
      flags.m_dummyNode.m_parentIndex = -1;
      flags.m_bestNodeCost = 3.40282e38;
      flags.m_maxPathCost = 3.40282e38;
      flags.m_dummyNode.m_gCost = 3.40282e38;
      flags.m_dummyNode.m_hCost = 3.40282e38;
      flags.m_dummyNode.m_index = -1;
      flags.m_dummyNode.m_flags.m_storage = 0;
      hkaiHashSearchState::setStorage(&flags, array, v17);
      flags.m_heuristicWeight = 0.0;
      v18 = hkaiHashSearchState::getNodeState(&flags, v12);
      v18->m_gCost = 0.0;
      v19 = v18;
      v20 = hkaiGraphMultiDistanceHeuristic<hkaiNavMeshFaceGraph>::getHeuristic(&heuristic, v12);
      v19->m_hCost = v20;
      v19->m_flags.m_storage |= 5u;
      if ( v20 < flags.m_bestNodeCost )
      {
        flags.m_bestNodeCost = v20;
        flags.m_bestNode = v12;
      }
      listener->m_searchState = &flags;
      hkaiHierarchyUtils::CostAdaptor::estimatedCost(&pathCost, v12);
      v21 = openset.m_heap;
      v22 = openset.m_heapSize;
      v23 = openset.m_heapSize++;
      openset.m_heap[v22].m_idx = v12;
      v21[v22].m_cost.m_floatCost = v20;
      v24 = openset.m_heap;
      v25 = openset.m_heap[v22].m_idx;
      v26 = openset.m_heap[v22].m_cost.m_floatCost;
      for ( i = (v23 - 1) / 2; v23 > 0; i = ((signed int)i - 1) / 2 )
      {
        if ( v24[(signed int)i].m_cost.m_intCost <= SLODWORD(v26) )
          break;
        v28 = v23;
        v23 = i;
        v24[v28] = v24[(signed int)i];
        v24 = openset.m_heap;
      }
      v29 = v40 == 0;
      v30 = v40 < 0;
      v31 = v23;
      v24[v31].m_idx = v25;
      openset.m_heap[v31].m_cost.m_floatCost = v26;
      if ( !v30 && !v29 )
      {
        while ( openset.m_heapSize && openset.m_heapSize < openset.m_maxSize && flags.m_nodeSize < flags.m_nodeCapacity )
          hkaiAstarSearchIteration_hkaiNavMeshFaceGraph_hkaiNavMeshFaceGraph_hkaiHeapOpenSet_hkaiHashSearchState_hkaiNullSearchParent_hkaiGraphMultiDistanceHeuristic_hkaiNavMeshFaceGraph__hkaiHierarchyUtils::CostAdaptor_hkaiNavMeshFaceGraph_(
            listener,
            listener,
            &openset,
            &flags,
            v20,
            (hkaiNullSearchParent *)&v45,
            &heuristic,
            &pathCost,
            listener);
      }
      LODWORD(v8) = 0;
      v33 = 0;
      if ( v34 >= 0 )
        ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkaiHeapOpenSet::IndexCostPair *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerTempAllocator::s_alloc,
          v32,
          v34 & 0x3FFFFFFF,
          i);
      v32 = 0i64;
      v34 = 2147483648;
      size = 0;
      if ( v38 >= 0 )
        ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, char *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerTempAllocator::s_alloc,
          array,
          v38 & 0x3FFFFFFF,
          i);
      ++v10;
      ++v11;
      array = 0i64;
      v38 = 2147483648;
    }
    while ( v10 < v4->m_size );
  }
}

// File Line: 415
// RVA: 0xBFD2A0
void __fastcall hkaiSimpleClusterGenerator::getInitialSeeding(hkaiNavMeshFaceGraph *graph, hkArrayBase<int> *nodesForRegion, hkArray<int,hkContainerHeapAllocator> *groupRepresentative, int numGroupsForRegion, hkPseudoRandomGenerator *prng)
{
  int v5; // eax
  hkArray<int,hkContainerHeapAllocator> *v6; // rbx
  int v7; // esi
  hkArrayBase<int> *v8; // rdi
  int v9; // er8
  __int64 v10; // rax
  char *v11; // rcx
  __int64 v12; // rdx
  signed __int64 v13; // r8
  int v14; // eax
  __int64 v15; // r8
  int *v16; // r11
  hkPseudoRandomGenerator *v17; // r10
  signed __int64 v18; // r9
  unsigned int v19; // eax
  signed int v20; // edx
  __int64 v21; // rax
  int v22; // edx
  int v23; // eax
  int v24; // eax
  int v25; // er9
  hkResult result; // [rsp+58h] [rbp+20h]

  v5 = groupRepresentative->m_capacityAndFlags;
  v6 = groupRepresentative;
  v7 = numGroupsForRegion;
  v8 = nodesForRegion;
  v9 = groupRepresentative->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < nodesForRegion->m_size )
  {
    if ( v5 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v6->m_data,
        4 * v9);
    result.m_enum = 4 * v8->m_size;
    v6->m_data = (int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                          (int *)&result);
    v6->m_capacityAndFlags = result.m_enum / 4;
  }
  v10 = v8->m_size;
  v11 = (char *)v6->m_data;
  v6->m_size = v10;
  v12 = v10;
  if ( (signed int)v10 > 0 )
  {
    v13 = (char *)v8->m_data - v11;
    do
    {
      v14 = *(_DWORD *)&v11[v13];
      v11 += 4;
      *((_DWORD *)v11 - 1) = v14;
      --v12;
    }
    while ( v12 );
  }
  v15 = v6->m_size;
  v16 = v6->m_data;
  if ( (signed int)v15 >= 2 )
  {
    v17 = prng;
    v18 = (signed __int64)&v16[v15 - 1];
    do
    {
      v19 = 1664525 * v17->m_current + 1013904223;
      v17->m_current = v19;
      if ( (signed int)v15 < 0x10000 )
        v19 >>= 11;
      v20 = v19 % (unsigned int)v15;
      LODWORD(v15) = v15 - 1;
      v18 -= 4i64;
      v21 = v20;
      v22 = v16[v20];
      v16[v21] = *(_DWORD *)(v18 + 4);
      *(_DWORD *)(v18 + 4) = v22;
    }
    while ( (signed int)v15 >= 2 );
  }
  v23 = v6->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v23 < v7 )
  {
    v24 = 2 * v23;
    v25 = v7;
    if ( v7 < v24 )
      v25 = v24;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, v25, 4);
  }
  v6->m_size = v7;
}

// File Line: 427
// RVA: 0xBFC2D0
__int64 __fastcall hkaiSimpleClusterGenerator::findClosestGroupRepForNode(hkaiNavMeshFaceGraph *graph, int ni, hkaiHierarchyUtils::SemiSparse2dArraySorted *costs, hkArray<int,hkContainerHeapAllocator> *groupRepresentatives, hkArrayBase<hkaiHierarchyUtils::RepGroupPair> *sortedReps)
{
  hkaiHierarchyUtils::SemiSparse2dArraySorted *v5; // r12
  hkArray<int,hkContainerHeapAllocator> *v6; // r15
  unsigned int v7; // er14
  _QWORD *v8; // rax
  unsigned __int64 v9; // r10
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  float v12; // xmm0_4
  int v13; // edi
  __int64 v14; // r8
  int v15; // edx
  __int64 v16; // rcx
  hkaiHierarchyUtils::RepGroupPair *v17; // rax
  unsigned int v18; // ebp
  _QWORD *v19; // r8
  _QWORD *v20; // rcx
  unsigned __int64 v21; // rax
  signed __int64 v22; // rcx
  float v23; // xmm7_4
  __int64 v24; // rsi
  unsigned int v25; // ebx
  hkVector4f *v26; // r9
  __m128 v27; // xmm1
  __m128 v28; // xmm1
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  float v31; // xmm6_4
  _QWORD *v32; // rax
  _QWORD *v33; // rcx
  _QWORD *v34; // r8
  unsigned __int64 v35; // rax
  signed __int64 v36; // rcx
  float minCost; // [rsp+30h] [rbp-B8h]
  int faceIndex[4]; // [rsp+40h] [rbp-A8h]
  int v40[4]; // [rsp+50h] [rbp-98h]
  hkaiNavMeshFaceGraph *v41; // [rsp+F0h] [rbp+8h]
  int minIndex; // [rsp+100h] [rbp+18h]

  v41 = graph;
  v5 = costs;
  v6 = groupRepresentatives;
  v7 = ni;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = v8[1];
  v10 = v8;
  if ( v9 < v8[3] )
  {
    *(_QWORD *)v9 = "LtclosestRep";
    *(_QWORD *)(v9 + 16) = "StsparseSearch";
    v11 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v11;
    v10[1] = v9 + 24;
  }
  v12 = v5->m_default;
  v13 = 0;
  v14 = sortedReps->m_size;
  minIndex = -1;
  minCost = v12;
  v15 = 0;
  v16 = 0i64;
  if ( v14 <= 0 )
  {
LABEL_7:
    hkaiHierarchyUtils::SemiSparse2dArraySorted::findMinValFromSet(v5, v7, sortedReps, &minIndex, &minCost);
    v18 = minIndex;
    if ( minIndex == -1 )
    {
      v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v20 = (_QWORD *)v19[1];
      if ( (unsigned __int64)v20 < v19[3] )
      {
        *v20 = "StEuclidean";
        v21 = __rdtsc();
        v22 = (signed __int64)(v20 + 2);
        *(_DWORD *)(v22 - 8) = v21;
        v19[1] = v22;
      }
      if ( v6->m_size > 0 )
      {
        v23 = minCost;
        v24 = 0i64;
        sortedReps = (hkArrayBase<hkaiHierarchyUtils::RepGroupPair> *)(48i64 * (v7 >> 22));
        do
        {
          v25 = v6->m_data[v24];
          hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
            (hkaiNavMeshUtils *)v41->m_collection->m_instances.m_data[v25 >> 22].m_instancePtr,
            (hkaiNavMeshInstance *)(v6->m_data[v24] & 0x3FFFFF),
            (__int64)faceIndex,
            (hkVector4f *)(6i64 * (v25 >> 22)));
          hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
            *(hkaiNavMeshUtils **)((char *)&v41->m_collection->m_instances.m_data->m_instancePtr
                                 + (unsigned __int64)sortedReps),
            (hkaiNavMeshInstance *)(v7 & 0x3FFFFF),
            (__int64)v40,
            v26);
          v27 = _mm_sub_ps(*(__m128 *)faceIndex, *(__m128 *)v40);
          v28 = _mm_mul_ps(v27, v27);
          v29 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                  _mm_shuffle_ps(v28, v28, 170));
          v30 = _mm_rsqrt_ps(v29);
          LODWORD(v31) = (unsigned __int128)_mm_andnot_ps(
                                              _mm_cmpleps(v29, (__m128)0i64),
                                              _mm_mul_ps(
                                                _mm_mul_ps(
                                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v30), v30)),
                                                  _mm_mul_ps(*(__m128 *)_xmm, v30)),
                                                v29));
          hkaiHierarchyUtils::SemiSparse2dArraySorted::set(v5, v25, v7, v31);
          if ( v31 < v23 )
          {
            v23 = v31;
            v18 = v13;
          }
          ++v13;
          ++v24;
        }
        while ( v13 < v6->m_size );
      }
    }
  }
  else
  {
    v17 = sortedReps->m_data;
    while ( v17->m_representative != v7 )
    {
      ++v16;
      ++v15;
      ++v17;
      if ( v16 >= v14 )
        goto LABEL_7;
    }
    v18 = sortedReps->m_data[v15].m_group;
  }
  v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v33 = (_QWORD *)v32[1];
  v34 = v32;
  if ( (unsigned __int64)v33 < v32[3] )
  {
    *v33 = "lt";
    v35 = __rdtsc();
    v36 = (signed __int64)(v33 + 2);
    *(_DWORD *)(v36 - 8) = v35;
    v34[1] = v36;
  }
  return v18;
}

// File Line: 477
// RVA: 0xBFD920
__int64 __fastcall hkaiSimpleClusterGenerator::updateGroupReps(hkaiNavMeshFaceGraph *graph, hkArrayBase<int> *nodes, hkArray<int,hkContainerHeapAllocator> *groupRepresentatives, hkArray<int,hkContainerHeapAllocator> *groupFromNode)
{
  __int64 v4; // rbx
  __int64 v5; // rsi
  int v6; // er14
  hkArrayBase<int> *v7; // r13
  hkArray<int,hkContainerHeapAllocator> *v8; // r15
  int v9; // edi
  int v10; // er9
  __int64 v11; // rcx
  _DWORD *v12; // rdi
  int v13; // er9
  __int64 v14; // rcx
  signed __int64 v15; // rdx
  __int64 v16; // r12
  __int64 v17; // r14
  __int64 v18; // rbx
  __int64 v19; // rsi
  signed __int64 v20; // rdi
  __int64 v21; // rdx
  __m128 v22; // xmm2
  int v23; // ebx
  int v24; // edx
  int v25; // er9
  _DWORD *v26; // rdi
  __int64 v27; // rcx
  int v28; // eax
  int v29; // er13
  __int64 v30; // r8
  __int64 v31; // rdx
  __int64 v32; // rcx
  char *v33; // rdi
  int v34; // eax
  __int64 v35; // rbx
  _QWORD *v36; // r13
  __int64 v37; // rcx
  __int64 v38; // r14
  __m128 v39; // xmm6
  __m128 v40; // xmm6
  __m128 v41; // xmm6
  __m128 v42; // xmm4
  __m128 v43; // xmm3
  float v44; // xmm5_4
  __int64 v45; // r9
  __int64 v46; // rdx
  _DWORD *v47; // rcx
  unsigned int v48; // ebx
  int v50; // [rsp+18h] [rbp-59h]
  int v51; // [rsp+18h] [rbp-59h]
  int sizeElem[2]; // [rsp+20h] [rbp-51h]
  int v53; // [rsp+28h] [rbp-49h]
  int v54; // [rsp+2Ch] [rbp-45h]
  __int64 v55; // [rsp+30h] [rbp-41h]
  int v56; // [rsp+38h] [rbp-39h]
  int v57; // [rsp+3Ch] [rbp-35h]
  __int64 array; // [rsp+40h] [rbp-31h]
  int v59; // [rsp+48h] [rbp-29h]
  int v60; // [rsp+4Ch] [rbp-25h]
  hkResult result[2]; // [rsp+50h] [rbp-21h]
  int faceIndex[4]; // [rsp+58h] [rbp-19h]
  int v63[4]; // [rsp+68h] [rbp-9h]
  __int64 v64; // [rsp+D8h] [rbp+67h]
  __int64 vars0; // [rsp+E0h] [rbp+6Fh]
  hkArray<int,hkContainerHeapAllocator> *retaddr; // [rsp+E8h] [rbp+77h]
  hkaiNavMeshFaceGraph *v67; // [rsp+F0h] [rbp+7Fh]

  v67 = graph;
  v4 = nodes->m_size;
  v5 = 0i64;
  v6 = groupRepresentatives->m_size;
  v7 = nodes;
  v8 = groupRepresentatives;
  array = 0i64;
  v9 = 0;
  v59 = 0;
  v60 = 2147483648;
  *(_QWORD *)sizeElem = 0i64;
  v53 = 0;
  v54 = 2147483648;
  if ( v6 > 0 )
  {
    v10 = v6;
    if ( v6 < 0 )
      v10 = 0;
    hkArrayUtil::_reserve(result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v10, 4);
    v9 = v59;
  }
  v11 = v6 - v9;
  if ( v6 - v9 > 0 )
  {
    v12 = (_DWORD *)(array + 4i64 * v9);
    while ( v11 )
    {
      *v12 = 0;
      ++v12;
      --v11;
    }
  }
  v59 = v6;
  if ( (v54 & 0x3FFFFFFF) < v6 )
  {
    v13 = v6;
    if ( v6 < 2 * (v54 & 0x3FFFFFFF) )
      v13 = 2 * (v54 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, sizeElem, v13, 16);
  }
  v14 = v6 - v53;
  v15 = *(_QWORD *)sizeElem + 16i64 * v53;
  if ( v6 - v53 > 0 )
  {
    do
    {
      v15 += 16i64;
      *(hkVector4f *)(v15 - 16) = (hkVector4f)aabbOut.m_quad;
      --v14;
    }
    while ( v14 );
  }
  v53 = v6;
  v16 = v4;
  if ( (signed int)v4 > 0 )
  {
    v17 = v64;
    do
    {
      v18 = *((signed int *)&v67->m_collection->vfptr + v5);
      hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
        *(hkaiNavMeshUtils **)(*(_QWORD *)(*(_QWORD *)v17 + 32i64) + 48i64 * ((unsigned int)v7->m_data[v5] >> 22)),
        (hkaiNavMeshInstance *)(v7->m_data[v5] & 0x3FFFFF),
        (__int64)faceIndex,
        (hkVector4f *)groupFromNode);
      ++v5;
      *(__m128 *)(*(_QWORD *)sizeElem + 16 * v18) = _mm_add_ps(
                                                      *(__m128 *)(*(_QWORD *)sizeElem + 16 * v18),
                                                      *(__m128 *)faceIndex);
      ++*(_DWORD *)(array + 4 * v18);
    }
    while ( v5 < v16 );
    v6 = v50;
    v8 = retaddr;
  }
  v19 = v6;
  v20 = 0i64;
  *(_QWORD *)faceIndex = v6;
  if ( v6 > 0 )
  {
    v21 = 0i64;
    do
    {
      v22 = (__m128)(unsigned int)FLOAT_1_0;
      ++v20;
      v21 += 16i64;
      v22.m128_f32[0] = 1.0 / (float)*(signed int *)(array + 4 * v20 - 4);
      *(__m128 *)(v21 + *(_QWORD *)sizeElem - 16) = _mm_mul_ps(
                                                      _mm_shuffle_ps(v22, v22, 0),
                                                      *(__m128 *)(v21 + *(_QWORD *)sizeElem - 16));
    }
    while ( v20 < v6 );
  }
  v23 = v8->m_size;
  v24 = 0;
  v55 = 0i64;
  v56 = 0;
  v57 = 2147483648;
  if ( v23 > 0 )
  {
    v25 = v23;
    if ( v23 < 0 )
      v25 = 0;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      &v55,
      v25,
      4);
    v24 = v56;
  }
  v26 = (_DWORD *)(v55 + 4i64 * v24);
  v27 = v23 - v24;
  if ( v23 - v24 > 0 )
  {
    while ( v27 )
    {
      *v26 = 2139095022;
      ++v26;
      --v27;
    }
  }
  v28 = v8->m_size;
  v29 = 2147483648;
  v56 = v23;
  v30 = 0i64;
  *(_QWORD *)&result[0].m_enum = 0i64;
  v51 = 2147483648;
  if ( v28 > 0 )
  {
    LODWORD(retaddr) = 4 * v28;
    v30 = ((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, hkArray<int,hkContainerHeapAllocator> **, _QWORD))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
            &hkContainerTempAllocator::s_alloc,
            &retaddr,
            0i64);
    *(_QWORD *)&result[0].m_enum = v30;
    v29 = (signed int)retaddr / 4;
    v51 = (signed int)retaddr / 4;
  }
  v31 = v8->m_size;
  if ( v31 > 0 )
  {
    v32 = v30;
    v33 = (char *)v8->m_data - v30;
    do
    {
      v34 = *(_DWORD *)&v33[v32];
      v32 += 4i64;
      *(_DWORD *)(v32 - 4) = v34;
      --v31;
    }
    while ( v31 );
  }
  v35 = 0i64;
  if ( v16 > 0 )
  {
    v36 = (_QWORD *)vars0;
    do
    {
      v37 = *((signed int *)&v67->m_collection->vfptr + v35);
      if ( (_DWORD)v37 != -1 )
      {
        v38 = *((signed int *)&v67->m_collection->vfptr + v35);
        v39 = *(__m128 *)(*(_QWORD *)sizeElem + 16 * v37);
        LODWORD(vars0) = *(_DWORD *)(*v36 + 4 * v35);
        hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
          *(hkaiNavMeshUtils **)(*(_QWORD *)(*(_QWORD *)v64 + 32i64) + 48i64 * ((unsigned int)vars0 >> 22)),
          (hkaiNavMeshInstance *)(vars0 & 0x3FFFFF),
          (__int64)v63,
          (hkVector4f *)groupFromNode);
        v40 = _mm_sub_ps(v39, *(__m128 *)v63);
        v41 = _mm_mul_ps(v40, v40);
        v42 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
                _mm_shuffle_ps(v41, v41, 170));
        v43 = _mm_rsqrt_ps(v42);
        LODWORD(v44) = (unsigned __int128)_mm_andnot_ps(
                                            _mm_cmpleps(v42, (__m128)0i64),
                                            _mm_mul_ps(
                                              _mm_mul_ps(
                                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v43, v42), v43)),
                                                _mm_mul_ps(*(__m128 *)_xmm, v43)),
                                              v42));
        if ( v44 < *(float *)(v55 + 4 * v38) )
        {
          v8->m_data[v38] = vars0;
          *(float *)(v55 + 4 * v38) = v44;
        }
      }
      ++v35;
    }
    while ( v35 < v16 );
    v19 = *(_QWORD *)faceIndex;
    v29 = v51;
  }
  v45 = *(_QWORD *)&result[0].m_enum;
  v46 = 0i64;
  if ( v19 <= 0 )
  {
LABEL_45:
    v48 = 0;
  }
  else
  {
    v47 = *(_DWORD **)&result[0].m_enum;
    while ( *(int *)((char *)v8->m_data + (unsigned __int64)v47 - *(_QWORD *)&result[0].m_enum) == *v47 )
    {
      ++v46;
      ++v47;
      if ( v46 >= v19 )
        goto LABEL_45;
    }
    v48 = 1;
  }
  if ( v29 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      *(void **)&result[0].m_enum,
      4 * v29);
  v56 = 0;
  if ( v57 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v55,
      (unsigned int)(4 * v57),
      v45);
  v55 = 0i64;
  v57 = 2147483648;
  v53 = 0;
  if ( v54 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _QWORD, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      *(_QWORD *)sizeElem,
      (unsigned int)(16 * v54),
      v45);
  *(_QWORD *)sizeElem = 0i64;
  v59 = 0;
  v54 = 2147483648;
  if ( v60 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      array,
      (unsigned int)(4 * v60),
      v45);
  return v48;
}

// File Line: 544
// RVA: 0xBFC610
void __fastcall hkaiSimpleClusterGenerator::generateClusters(hkaiNavMeshFaceGraph *graph, int targetNumGroups, int blockSize, bool ensureClusterPerNode, hkArray<int,hkContainerHeapAllocator> *groupFromNode, hkArray<int,hkContainerHeapAllocator> *groupRepresentatives, int randSeed)
{
  int v7; // er15
  hkaiNavMeshFaceGraph *v8; // r13
  hkaiNavMeshInstance *v9; // rbx
  int v10; // eax
  int v11; // er14
  int v12; // eax
  int v13; // er9
  int v14; // eax
  int v15; // eax
  int v16; // er9
  __int64 v17; // rdx
  _DWORD *v18; // rdi
  __int64 v19; // rcx
  int v20; // esi
  _QWORD *v21; // rdi
  unsigned __int64 v22; // rcx
  unsigned __int64 v23; // rax
  int v24; // edi
  int v25; // er9
  __int64 v26; // r12
  int v27; // er9
  int *v28; // rdx
  int *v29; // rdi
  __int64 v30; // rcx
  __int64 v31; // rdi
  int v32; // ecx
  int v33; // er8
  int *v34; // rax
  __int64 v35; // rdi
  int v36; // eax
  unsigned int v37; // esi
  _QWORD *v38; // rdi
  _QWORD *v39; // rcx
  unsigned __int64 v40; // rax
  signed __int64 v41; // rcx
  __int64 v42; // r15
  int v43; // ebx
  __int64 v44; // rcx
  signed int v45; // edx
  __int64 v46; // r12
  __m128i v47; // xmm1
  int v48; // esi
  signed int v49; // eax
  _QWORD *v50; // rax
  unsigned __int64 v51; // rcx
  _QWORD *v52; // rdi
  unsigned __int64 v53; // rax
  int v54; // ecx
  int v55; // er9
  int v56; // edi
  __int64 i; // rdx
  _QWORD *v58; // rdi
  _QWORD *v59; // rcx
  unsigned __int64 v60; // rax
  signed __int64 v61; // rcx
  _QWORD *v62; // rdi
  _QWORD *v63; // rcx
  unsigned __int64 v64; // rax
  signed __int64 v65; // rcx
  int *v66; // rdx
  int v67; // ecx
  int v68; // er9
  int *v69; // rdi
  int v70; // eax
  __int64 v71; // rcx
  _QWORD *v72; // rdi
  _QWORD *v73; // rcx
  unsigned __int64 v74; // rax
  signed __int64 v75; // rcx
  signed int v76; // er15
  int v77; // er9
  signed int v78; // er8
  int v79; // edi
  __int64 v80; // rdx
  __int64 v81; // r8
  _QWORD *v82; // rdi
  _QWORD *v83; // rcx
  unsigned __int64 v84; // rax
  signed __int64 v85; // rcx
  __int64 v86; // rdi
  int v87; // eax
  _QWORD *v88; // rdi
  _QWORD *v89; // rcx
  unsigned __int64 v90; // rax
  signed __int64 v91; // rcx
  _QWORD *v92; // rdi
  _QWORD *v93; // rcx
  unsigned __int64 v94; // rax
  signed __int64 v95; // rcx
  unsigned int v96; // ebx
  _QWORD *v97; // rax
  _QWORD *v98; // rcx
  _QWORD *v99; // rdi
  unsigned __int64 v100; // rax
  signed __int64 v101; // rcx
  _QWORD *v102; // rdi
  _QWORD *v103; // rcx
  unsigned __int64 v104; // rax
  signed __int64 v105; // rcx
  int v106; // ebx
  __int64 v107; // rdi
  signed int v108; // eax
  __int64 v109; // rbx
  int *v110; // rdi
  int v111; // er8
  _QWORD *v112; // rax
  _QWORD *v113; // rcx
  _QWORD *v114; // rdi
  unsigned __int64 v115; // rax
  signed __int64 v116; // rcx
  _QWORD *v117; // rdi
  _QWORD *v118; // rcx
  unsigned __int64 v119; // rax
  signed __int64 v120; // rcx
  hkResult result; // [rsp+30h] [rbp-C8h]
  hkaiHierarchyUtils::RepGroupPair *pArr; // [rsp+38h] [rbp-C0h]
  int v123; // [rsp+40h] [rbp-B8h]
  int v124; // [rsp+44h] [rbp-B4h]
  hkArrayBase<int> nodesForRegion; // [rsp+48h] [rbp-B0h]
  int v126; // [rsp+58h] [rbp-A0h]
  int *v127; // [rsp+60h] [rbp-98h]
  int v128; // [rsp+68h] [rbp-90h]
  int v129; // [rsp+6Ch] [rbp-8Ch]
  hkArray<int,hkContainerHeapAllocator> v130; // [rsp+70h] [rbp-88h]
  int v131; // [rsp+80h] [rbp-78h]
  int v132; // [rsp+84h] [rbp-74h]
  hkArrayBase<int> regions; // [rsp+88h] [rbp-70h]
  hkResult v134; // [rsp+98h] [rbp-60h]
  __int64 v135; // [rsp+A0h] [rbp-58h]
  hkResult v136; // [rsp+A8h] [rbp-50h]
  __int64 v137; // [rsp+B0h] [rbp-48h]
  hkaiHierarchyUtils::SemiSparse2dArraySorted costs; // [rsp+B8h] [rbp-40h]
  hkPseudoRandomGenerator prng; // [rsp+D8h] [rbp-20h]
  __int64 v140; // [rsp+E0h] [rbp-18h]
  hkaiNavMeshFaceGraph *retaddr; // [rsp+148h] [rbp+50h]
  hkaiNavMeshFaceGraph *v142; // [rsp+150h] [rbp+58h]
  int v143; // [rsp+158h] [rbp+60h]
  int v144; // [rsp+160h] [rbp+68h]
  signed int *array; // [rsp+168h] [rbp+70h]

  LOBYTE(array) = ensureClusterPerNode;
  v144 = blockSize;
  v143 = targetNumGroups;
  v142 = graph;
  v7 = blockSize;
  v8 = graph;
  v9 = graph->m_collection->m_instances.m_data->m_instancePtr;
  v10 = groupFromNode->m_capacityAndFlags & 0x3FFFFFFF;
  v11 = v9->m_numOriginalFaces + v9->m_ownedFaces.m_size;
  if ( v10 < targetNumGroups )
  {
    v12 = 2 * v10;
    v13 = targetNumGroups;
    if ( targetNumGroups < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, groupFromNode, v13, 4);
  }
  v14 = array[3] & 0x3FFFFFFF;
  if ( v14 < v11 )
  {
    v15 = 2 * v14;
    v16 = v11;
    if ( v11 < v15 )
      v16 = v15;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, array, v16, 4);
  }
  v17 = array[2];
  v18 = (_DWORD *)(*(_QWORD *)array + 4 * v17);
  v19 = v11 - (signed int)v17;
  if ( v19 > 0 )
  {
    while ( v19 )
    {
      *v18 = -1;
      ++v18;
      --v19;
    }
  }
  array[2] = v11;
  v20 = 0;
  v127 = 0i64;
  v128 = 0;
  v129 = 2147483648;
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = v21[1];
  if ( v22 < v21[3] )
  {
    *(_QWORD *)v22 = "LtgenerateClusters";
    *(_QWORD *)(v22 + 16) = "StregionCount";
    v23 = __rdtsc();
    *(_DWORD *)(v22 + 8) = v23;
    v21[1] = v22 + 24;
  }
  regions.m_data = 0i64;
  regions.m_size = 0;
  regions.m_capacityAndFlags = 2147483648;
  v24 = v9->m_numOriginalFaces + v9->m_ownedFaces.m_size;
  if ( v24 > 0 )
  {
    v25 = v9->m_numOriginalFaces + v9->m_ownedFaces.m_size;
    if ( v24 < 0 )
      v25 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &regions, v25, 4);
  }
  regions.m_size = v24;
  v26 = (signed int)hkaiNavMeshUtils::computeRegions(v9, 1, &regions, 0i64);
  prng.m_seed = (unsigned int)groupRepresentatives;
  if ( (_BYTE)v144 )
    v7 = -1;
  prng.m_current = (unsigned int)groupRepresentatives;
  if ( (v129 & 0x3FFFFFFF) < (signed int)v26 )
  {
    v27 = v26;
    if ( (signed int)v26 < 2 * (v129 & 0x3FFFFFFF) )
      v27 = 2 * (v129 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      (hkResult *)&groupRepresentatives,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v127,
      v27,
      4);
  }
  v28 = v127;
  v29 = &v127[v128];
  v30 = (signed int)v26 - v128;
  if ( (signed int)v26 - v128 > 0 )
  {
    while ( v30 )
    {
      *v29 = 0;
      ++v29;
      --v30;
    }
    v28 = v127;
  }
  v31 = 0i64;
  v32 = v26;
  v128 = v26;
  v33 = 0;
  if ( v9->m_numOriginalFaces + v9->m_ownedFaces.m_size > 0 )
  {
    do
    {
      ++v33;
      ++v31;
      ++v28[regions.m_data[v31 - 1]];
      v28 = v127;
    }
    while ( v33 < v9->m_numOriginalFaces + v9->m_ownedFaces.m_size );
    v32 = v128;
  }
  if ( v32 > 0 )
  {
    v34 = v28;
    v35 = (unsigned int)v32;
    do
    {
      if ( *v34 < v7 )
        v20 += *v34;
      ++v34;
      --v35;
    }
    while ( v35 );
  }
  v36 = v11 - v20;
  LODWORD(groupRepresentatives) = v11 - v20;
  if ( v11 == v20 )
  {
    v36 = *v28;
    v143 = *v28;
    LODWORD(groupRepresentatives) = *v28;
  }
  v37 = v36;
  v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v39 = (_QWORD *)v38[1];
  if ( (unsigned __int64)v39 < v38[3] )
  {
    *v39 = "Stregions";
    v40 = __rdtsc();
    v41 = (signed __int64)(v39 + 2);
    *(_DWORD *)(v41 - 8) = v40;
    v38[1] = v41;
  }
  v42 = v11;
  v140 = v26;
  v43 = 0;
  v44 = 0i64;
  v137 = v11;
  v126 = 0;
  v135 = 0i64;
  if ( (signed int)v26 > 0 )
  {
    v45 = v143;
    do
    {
      v46 = v127[v44];
      if ( ((_BYTE)v144 || (signed int)v46 >= v45) && v37 && (_DWORD)v142 )
      {
        v47 = _mm_cvtsi32_si128(v37);
        v48 = 1;
        v49 = (signed int)(float)((float)((float)((float)(signed int)v46 * (float)(signed int)v142)
                                        / COERCE_FLOAT(_mm_cvtepi32_ps(v47)))
                                + 0.5);
        if ( v49 > 1 )
          v48 = v49;
        if ( v48 > (signed int)v46 )
          v48 = v46;
        v50 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v51 = v50[1];
        v52 = v50;
        if ( v51 < v50[3] )
        {
          *(_QWORD *)v51 = "Ltregion";
          *(_QWORD *)(v51 + 16) = "Stgather";
          v53 = __rdtsc();
          *(_DWORD *)(v51 + 8) = v53;
          v52[1] = v51 + 24;
        }
        nodesForRegion.m_capacityAndFlags = 2147483648;
        v54 = 0;
        nodesForRegion.m_data = 0i64;
        nodesForRegion.m_size = 0;
        if ( (signed int)v46 <= 0 )
        {
          v134.m_enum = 0;
        }
        else
        {
          v55 = v46;
          if ( (signed int)v46 < 0 )
            v55 = 0;
          hkArrayUtil::_reserve(
            &v134,
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
            &nodesForRegion,
            v55,
            4);
          v54 = nodesForRegion.m_size;
        }
        v56 = 0;
        for ( i = 0i64; i < v42; ++v56 )
        {
          if ( regions.m_data[i] == v43 )
          {
            nodesForRegion.m_data[v54] = v56;
            v54 = nodesForRegion.m_size++ + 1;
          }
          ++i;
        }
        v58 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v59 = (_QWORD *)v58[1];
        if ( (unsigned __int64)v59 < v58[3] )
        {
          *v59 = "StnearestNeighbors";
          v60 = __rdtsc();
          v61 = (signed __int64)(v59 + 2);
          *(_DWORD *)(v61 - 8) = v60;
          v58[1] = v61;
        }
        costs.m_costs.m_data = 0i64;
        costs.m_costs.m_size = 0;
        costs.m_costs.m_capacityAndFlags = 2147483648;
        hkaiSimpleClusterGenerator::getNearestNeighborCosts(v8, &nodesForRegion, &costs, 6 * v143);
        v62 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v63 = (_QWORD *)v62[1];
        if ( (unsigned __int64)v63 < v62[3] )
        {
          *v63 = "StinitSeeding";
          v64 = __rdtsc();
          v65 = (signed __int64)(v63 + 2);
          *(_DWORD *)(v65 - 8) = v64;
          v62[1] = v65;
        }
        *(_QWORD *)&v130.m_size = 0i64;
        v131 = 0;
        v132 = 2147483648;
        hkaiSimpleClusterGenerator::getInitialSeeding(
          v8,
          &nodesForRegion,
          (hkArray<int,hkContainerHeapAllocator> *)((char *)&v130 + 8),
          v48,
          &prng);
        v66 = 0i64;
        v130.m_data = 0i64;
        v67 = 0;
        v130.m_size = 0;
        v130.m_capacityAndFlags = 2147483648;
        if ( (signed int)v46 <= 0 )
        {
          v136.m_enum = 0;
        }
        else
        {
          v68 = v46;
          if ( (signed int)v46 < 0 )
            v68 = 0;
          hkArrayUtil::_reserve(&v136, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v130, v68, 4);
          v67 = v130.m_size;
          v66 = v130.m_data;
        }
        v69 = &v66[v67];
        v70 = v46 - v67;
        v71 = (signed int)v46 - v67;
        if ( v70 > 0 )
        {
          while ( v71 )
          {
            *v69 = -1;
            ++v69;
            --v71;
          }
        }
        v130.m_size = v46;
        v72 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v73 = (_QWORD *)v72[1];
        if ( (unsigned __int64)v73 < v72[3] )
        {
          *v73 = "StkMeans";
          v74 = __rdtsc();
          v75 = (signed __int64)(v73 + 2);
          *(_DWORD *)(v75 - 8) = v74;
          v72[1] = v75;
        }
        v76 = 0;
        while ( 1 )
        {
          pArr = 0i64;
          v123 = 0;
          v124 = 2147483648;
          if ( v48 <= 0 )
          {
            result.m_enum = 0;
          }
          else
          {
            v77 = v48;
            if ( v48 < 0 )
              v77 = 0;
            hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &pArr, v77, 8);
          }
          v78 = v48;
          v123 = v48;
          v79 = 0;
          if ( v48 > 0 )
          {
            v80 = 0i64;
            v81 = 0i64;
            do
            {
              v81 += 4i64;
              ++v80;
              pArr[v80 - 1].m_representative = *(_DWORD *)(*(_QWORD *)&v130.m_size + v81 - 4);
              *((_DWORD *)&pArr[v80] - 1) = v79++;
            }
            while ( v79 < v48 );
            v78 = v123;
          }
          if ( v78 > 1 )
            hkAlgorithm::quickSortRecursive<hkaiHierarchyUtils::RepGroupPair,hkAlgorithm::less<hkaiHierarchyUtils::RepGroupPair>>(
              pArr,
              0,
              v78 - 1,
              0);
          v82 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v83 = (_QWORD *)v82[1];
          if ( (unsigned __int64)v83 < v82[3] )
          {
            *v83 = "TtfindClosestRep";
            v84 = __rdtsc();
            v85 = (signed __int64)(v83 + 2);
            *(_DWORD *)(v85 - 8) = v84;
            v82[1] = v85;
          }
          v86 = 0i64;
          if ( (signed int)v46 > 0 )
          {
            do
            {
              v87 = hkaiSimpleClusterGenerator::findClosestGroupRepForNode(
                      v8,
                      nodesForRegion.m_data[v86++],
                      &costs,
                      (hkArray<int,hkContainerHeapAllocator> *)((char *)&v130 + 8),
                      (hkArrayBase<hkaiHierarchyUtils::RepGroupPair> *)&pArr);
              v130.m_data[v86 - 1] = v87;
            }
            while ( v86 < v46 );
          }
          v88 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v89 = (_QWORD *)v88[1];
          if ( (unsigned __int64)v89 < v88[3] )
          {
            *v89 = "Et";
            v90 = __rdtsc();
            v91 = (signed __int64)(v89 + 2);
            *(_DWORD *)(v91 - 8) = v90;
            v88[1] = v91;
          }
          v92 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v93 = (_QWORD *)v92[1];
          if ( (unsigned __int64)v93 < v92[3] )
          {
            *v93 = "TtupdateRep";
            v94 = __rdtsc();
            v95 = (signed __int64)(v93 + 2);
            *(_DWORD *)(v95 - 8) = v94;
            v92[1] = v95;
          }
          v96 = hkaiSimpleClusterGenerator::updateGroupReps(
                  v8,
                  &nodesForRegion,
                  (hkArray<int,hkContainerHeapAllocator> *)((char *)&v130 + 8),
                  &v130);
          v97 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v98 = (_QWORD *)v97[1];
          v99 = v97;
          if ( (unsigned __int64)v98 < v97[3] )
          {
            *v98 = "Et";
            v100 = __rdtsc();
            v101 = (signed __int64)(v98 + 2);
            *(_DWORD *)(v101 - 8) = v100;
            v99[1] = v101;
          }
          if ( !v96 )
            break;
          v123 = 0;
          if ( v124 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              pArr,
              8 * v124);
          ++v76;
          pArr = 0i64;
          v124 = 2147483648;
          if ( v76 >= 10 )
            goto LABEL_105;
        }
        v123 = 0;
        if ( v124 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            pArr,
            8 * v124);
        pArr = 0i64;
        v124 = 2147483648;
LABEL_105:
        v102 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v103 = (_QWORD *)v102[1];
        if ( (unsigned __int64)v103 < v102[3] )
        {
          *v103 = "StupdateGroupFromNode";
          v104 = __rdtsc();
          v105 = (signed __int64)(v103 + 2);
          *(_DWORD *)(v105 - 8) = v104;
          v102[1] = v105;
        }
        v106 = groupFromNode->m_size;
        hkArrayBase<unsigned int>::_append(
          (hkArrayBase<unsigned int> *)groupFromNode,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          *(const unsigned int **)&v130.m_size,
          v131);
        v107 = 0i64;
        if ( (signed int)v46 > 0 )
        {
          do
          {
            ++v107;
            *(_DWORD *)(*(_QWORD *)array + 4i64 * nodesForRegion.m_data[v107 - 1]) = v106 + v130.m_data[v107 - 1];
          }
          while ( v107 < v46 );
          v8 = retaddr;
        }
        v108 = 1;
        v130.m_size = 0;
        if ( (signed int)v142 - v48 > 1 )
          v108 = (_DWORD)v142 - v48;
        v37 = (_DWORD)groupRepresentatives - v46;
        LODWORD(groupRepresentatives) = (_DWORD)groupRepresentatives - v46;
        LODWORD(v142) = v108;
        if ( v130.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v130.m_data,
            4 * v130.m_capacityAndFlags);
        v130.m_data = 0i64;
        v130.m_capacityAndFlags = 2147483648;
        v131 = 0;
        if ( v132 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)&v130.m_size,
            4 * v132);
        *(_QWORD *)&v130.m_size = 0i64;
        v132 = 2147483648;
        v109 = costs.m_costs.m_size - 1;
        if ( costs.m_costs.m_size - 1 >= 0 )
        {
          v110 = &costs.m_costs.m_data->m_capacityAndFlags + 4 * (costs.m_costs.m_size - 1);
          do
          {
            v111 = *v110;
            *(v110 - 1) = 0;
            if ( v111 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                *(void **)(v110 - 3),
                8 * v111);
            *(_QWORD *)(v110 - 3) = 0i64;
            *v110 = 2147483648;
            v110 -= 4;
            --v109;
          }
          while ( v109 >= 0 );
        }
        costs.m_costs.m_size = 0;
        if ( costs.m_costs.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            costs.m_costs.m_data,
            16 * costs.m_costs.m_capacityAndFlags);
        costs.m_costs.m_data = 0i64;
        costs.m_costs.m_capacityAndFlags = 2147483648;
        nodesForRegion.m_size = 0;
        if ( nodesForRegion.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            nodesForRegion.m_data,
            4 * nodesForRegion.m_capacityAndFlags);
        nodesForRegion.m_data = 0i64;
        nodesForRegion.m_capacityAndFlags = 2147483648;
        v112 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v43 = v126;
        v42 = v137;
        v113 = (_QWORD *)v112[1];
        v114 = v112;
        if ( (unsigned __int64)v113 < v112[3] )
        {
          *v113 = "lt";
          v115 = __rdtsc();
          v116 = (signed __int64)(v113 + 2);
          *(_DWORD *)(v116 - 8) = v115;
          v114[1] = v116;
        }
        v44 = v135;
        v45 = v143;
      }
      ++v44;
      v126 = ++v43;
      v135 = v44;
    }
    while ( v44 < v140 );
  }
  regions.m_size = 0;
  if ( regions.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      regions.m_data,
      4 * regions.m_capacityAndFlags);
  regions.m_data = 0i64;
  regions.m_capacityAndFlags = 2147483648;
  v117 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v118 = (_QWORD *)v117[1];
  if ( (unsigned __int64)v118 < v117[3] )
  {
    *v118 = "lt";
    v119 = __rdtsc();
    v120 = (signed __int64)(v118 + 2);
    *(_DWORD *)(v120 - 8) = v119;
    v117[1] = v120;
  }
  v128 = 0;
  if ( v129 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v127,
      4 * v129);
}.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      regions.m_data,
      4 * regions.m_capacityAndFlags);
  regions.m_data = 0i64;
  regions.m_capacityAndFlags = 2147483648;
  v117 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v118 = (_QWORD *)v117[1];
  if ( (unsigned __int64)v118 < v117[3] )
  {
    *v118 = "lt";
    v

// File Line: 713
// RVA: 0xBFA020
void __fastcall hkaiHierarchyUtils::buildAbstractGraphFromClusterInfo(hkaiNavMeshFaceGraph *graph, hkaiDirectedGraphExplicitCost *graphOut, hkArray<int,hkContainerHeapAllocator> *groupFromNode, hkArray<int,hkContainerHeapAllocator> *groupRepresentative, hkArray<hkVector4f,hkContainerHeapAllocator> *centroids, hkaiNavMeshPathSearchParameters *searchParams, hkaiAgentTraversalInfo *agentInfo)
{
  __int64 v7; // r13
  hkaiNavMeshFaceGraph *v8; // rdi
  hkArray<int,hkContainerHeapAllocator> *v9; // r15
  int v10; // ebx
  int i; // er14
  unsigned int v12; // edx
  int index; // er14
  __int64 v14; // rbx
  hkaiNavMeshInstance *v15; // rcx
  int v16; // er12
  hkLifoAllocator *v17; // rax
  char *v18; // rsi
  int v19; // edx
  char *v20; // rcx
  signed int v21; // er12
  hkaiStreamingCollection::InstanceInfo *v22; // rcx
  hkaiNavMesh::Face *v23; // rax
  char *v24; // r8
  signed int v25; // edx
  __int64 v26; // r9
  int v27; // ebx
  int v28; // ecx
  __m128 v29; // xmm15
  unsigned int v30; // esi
  __int64 v31; // rax
  int v32; // esi
  __int64 v33; // rbx
  hkaiNavMesh::Edge *v34; // rax
  unsigned int v35; // ecx
  unsigned int v36; // eax
  int v37; // er14
  hkaiNavMesh::Edge *v38; // rax
  hkaiNavMesh::Edge *v39; // rax
  signed int v40; // edx
  __int64 v41; // rcx
  __m128 *v42; // rcx
  __m128 v43; // xmm2
  __m128 v44; // xmm3
  __int64 v45; // rax
  __m128 v46; // xmm4
  __m128 v47; // xmm5
  __m128 v48; // xmm11
  __m128 *v49; // rax
  hkSimdFloat32 v50; // xmm7
  __m128 v51; // xmm10
  __m128 v52; // xmm6
  __m128 v53; // xmm5
  __m128 v54; // xmm1
  __m128 v55; // xmm4
  __m128 v56; // xmm1
  __m128 v57; // xmm0
  __m128 v58; // xmm2
  __m128 v59; // xmm0
  __m128 v60; // xmm6
  __m128 v61; // xmm6
  __m128 v62; // xmm3
  __int64 v63; // r9
  int v64; // ecx
  __int64 v65; // rax
  __m128 v66; // xmm14
  __m128 v67; // xmm5
  __m128 v68; // xmm6
  __m128 *v69; // rdx
  __m128 v70; // xmm4
  __m128 v71; // xmm1
  __m128 v72; // xmm13
  __m128 v73; // xmm1
  __m128 v74; // xmm12
  __m128 v75; // xmm1
  __m128 v76; // xmm9
  __m128 v77; // xmm1
  __m128 v78; // xmm8
  __m128 v79; // xmm1
  __m128 v80; // xmm7
  __m128 v81; // xmm1
  __m128 v82; // xmm2
  __m128 v83; // xmm5
  __m128 v84; // xmm1
  __m128 v85; // xmm3
  __m128 v86; // xmm4
  __m128 v87; // xmm1
  __m128 v88; // xmm6
  __m128 v89; // xmm2
  __m128 v90; // xmm0
  __m128 v91; // xmm2
  __m128 v92; // xmm1
  __m128 v93; // xmm3
  __m128 v94; // xmm8
  __m128 v95; // xmm1
  __m128 v96; // xmm2
  __m128 v97; // xmm2
  hkaiAstarEdgeFilter *v98; // r15
  int striding; // ecx
  __m128 v100; // xmm10
  hkaiNavMesh::Face *v101; // rax
  __int64 v102; // r11
  const int *v103; // r12
  hkaiNavMesh::Edge *v104; // rax
  int v105; // ecx
  __int64 v106; // rsi
  __int64 v107; // r14
  int v108; // ebx
  int v109; // eax
  float v110; // xmm0_4
  signed int v111; // ebx
  hkLifoAllocator *v112; // rax
  int v113; // er8
  int v114; // [rsp+40h] [rbp-B8h]
  char *v115; // [rsp+48h] [rbp-B0h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v116; // [rsp+50h] [rbp-A8h]
  __int64 v117; // [rsp+60h] [rbp-98h]
  int v118; // [rsp+68h] [rbp-90h]
  int v119; // [rsp+6Ch] [rbp-8Ch]
  hkaiDirectedGraphExplicitCostBuilder v120; // [rsp+70h] [rbp-88h]
  __int64 v121; // [rsp+A0h] [rbp-58h]
  __int64 v122; // [rsp+A8h] [rbp-50h]
  hkaiAgentTraversalInfo *v123; // [rsp+B0h] [rbp-48h]
  int *v124; // [rsp+B8h] [rbp-40h]
  char v125; // [rsp+C0h] [rbp-38h]
  __m128 v126; // [rsp+C8h] [rbp-30h]
  __m128 v127; // [rsp+D8h] [rbp-20h]
  __m128 v128; // [rsp+E8h] [rbp-10h]
  __m128 v129; // [rsp+F8h] [rbp+0h]
  __m128 v130; // [rsp+108h] [rbp+10h]
  int v131; // [rsp+118h] [rbp+20h]
  __int64 v132; // [rsp+120h] [rbp+28h]
  int v133; // [rsp+148h] [rbp+50h]
  hkaiNavMesh::Edge *v134; // [rsp+150h] [rbp+58h]
  const int *v135; // [rsp+158h] [rbp+60h]
  __m128 v136; // [rsp+168h] [rbp+70h]
  int v137; // [rsp+178h] [rbp+80h]
  hkaiNavMesh::Face *v138; // [rsp+180h] [rbp+88h]
  __int64 v139; // [rsp+188h] [rbp+90h]
  int retaddr; // [rsp+288h] [rbp+190h]
  hkaiDirectedGraphExplicitCost *d; // [rsp+290h] [rbp+198h]
  hkaiDirectedGraphExplicitCost *v142; // [rsp+298h] [rbp+1A0h]
  hkArray<int,hkContainerHeapAllocator> *v143; // [rsp+2A0h] [rbp+1A8h]
  hkArray<int,hkContainerHeapAllocator> *v144; // [rsp+2A8h] [rbp+1B0h]

  v144 = groupRepresentative;
  v143 = groupFromNode;
  v142 = graphOut;
  v7 = 0i64;
  v8 = graph;
  v9 = groupRepresentative;
  v120.vfptr = (hkaiGraphBuilderVtbl *)&hkaiDirectedGraphExplicitCostBuilder::`vftable';
  v120.m_positions.m_data = (hkVector4f *)0x8000000000000000i64;
  *(_QWORD *)&v120.m_positions.m_size = 0i64;
  v120.m_links.m_data = (hkaiDirectedGraphExplicitCostBuilder::Link *)0x8000000000000000i64;
  hkaiDirectedGraphExplicitCostBuilder::BuildOptions::BuildOptions((hkaiDirectedGraphExplicitCostBuilder::BuildOptions *)&v120.m_links.m_size);
  v10 = 0;
  for ( i = v8->m_collection->m_instances.m_data->m_instancePtr->m_numOriginalFaces
          + v8->m_collection->m_instances.m_data->m_instancePtr->m_ownedFaces.m_size; v10 < v9->m_size; ++v10 )
    hkaiDirectedGraphExplicitCostBuilder::addPosition(&v120, (hkVector4f *)&v144->m_data[4 * v10]);
  v12 = 0;
  v116.m_elem = 0i64;
  v116.m_hashMod = -1;
  v116.m_numElems = 0;
  retaddr = 0;
  v117 = 0i64;
  *(_QWORD *)&v120.m_options.m_allowDuplicateEdges.m_bool = i;
  if ( i > 0 )
  {
    while ( 1 )
    {
      index = v12 & 0x3FFFFF;
      v14 = v12 >> 22;
      v114 = v12 & 0x3FFFFF;
      v15 = v8->m_collection->m_instances.m_data[v14].m_instancePtr;
      v16 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__10(
              v15->m_originalFaces,
              v15->m_numOriginalFaces,
              &v15->m_instancedFaces,
              &v15->m_ownedFaces,
              &v15->m_faceMap,
              v12 & 0x3FFFFF)->m_numEdges;
      v118 = v16;
      if ( v16 )
      {
        v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v18 = (char *)v17->m_cur;
        v19 = (4 * v16 + 127) & 0xFFFFFF80;
        v115 = v18;
        v20 = &v18[v19];
        if ( v19 > v17->m_slabSize || v20 > v17->m_end )
        {
          v18 = (char *)hkLifoAllocator::allocateFromNewSlab(v17, v19);
          v115 = v18;
        }
        else
        {
          v17->m_cur = v20;
        }
      }
      else
      {
        v18 = 0i64;
        v115 = 0i64;
      }
      v21 = v16 | 0x80000000;
      v22 = v8->m_collection->m_instances.m_data;
      v119 = v21;
      v23 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__10(
              v22[v14].m_instancePtr->m_originalFaces,
              v22[v14].m_instancePtr->m_numOriginalFaces,
              &v22[v14].m_instancePtr->m_instancedFaces,
              &v22[v14].m_instancePtr->m_ownedFaces,
              &v22[v14].m_instancePtr->m_faceMap,
              index);
      v24 = v18;
      v25 = v7;
      v26 = v23->m_numEdges;
      if ( (signed int)v26 > 0 )
      {
        v27 = (_DWORD)v14 << 22;
        do
        {
          v24 += 4;
          v28 = v25++ + v23->m_startEdgeIndex;
          *((_DWORD *)v24 - 1) = v27 | v28;
        }
        while ( v25 < (signed int)v26 );
      }
      v121 = v26;
      if ( (signed int)v26 > 0 )
        break;
LABEL_53:
      v111 = (4 * v118 + 127) & 0xFFFFFF80;
      v112 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v113 = (v111 + 15) & 0xFFFFFFF0;
      if ( v111 > v112->m_slabSize || &v18[v113] != v112->m_cur || v112->m_firstNonLifoEnd == v18 )
        hkLifoAllocator::slowBlockFree(v112, v18, v113);
      else
        v112->m_cur = v18;
      if ( v21 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v18,
          4 * v21);
      v7 = 0i64;
      v12 = retaddr++ + 1;
      if ( ++v117 >= *(_QWORD *)&v120.m_options.m_allowDuplicateEdges.m_bool )
        goto LABEL_61;
    }
    v29 = query.m_quad;
    while ( 1 )
    {
      v30 = *(_DWORD *)&v18[4 * v7];
      v31 = v30 >> 22;
      v32 = v30 & 0x3FFFFF;
      v33 = (__int64)v8->m_collection->m_instances.m_data[v31].m_instancePtr;
      v34 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__10(
              *(hkaiNavMesh::Edge **)(v33 + 32),
              *(_DWORD *)(v33 + 40),
              (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v33 + 256),
              (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v33 + 288),
              (hkArray<int,hkContainerHeapAllocator> *)(v33 + 208),
              v32);
      v35 = v34->m_oppositeFace;
      if ( v34->m_flags.m_storage & 0x40 )
        v36 = v35 & 0xFFC00000;
      else
        v36 = *(_DWORD *)(v33 + 472) << 22;
      v37 = v36 | v35 & 0x3FFFFF;
      if ( v35 == -1 )
        v37 = -1;
      v38 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__10(
              *(hkaiNavMesh::Edge **)(v33 + 32),
              *(_DWORD *)(v33 + 40),
              (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v33 + 256),
              (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v33 + 288),
              (hkArray<int,hkContainerHeapAllocator> *)(v33 + 208),
              v32);
      if ( v38->m_oppositeEdge == -1 || v38->m_flags.m_storage & 0x20 )
        goto LABEL_51;
      v39 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__10(
              *(hkaiNavMesh::Edge **)(v33 + 32),
              *(_DWORD *)(v33 + 40),
              (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v33 + 256),
              (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v33 + 288),
              (hkArray<int,hkContainerHeapAllocator> *)(v33 + 208),
              v32);
      v40 = *(_DWORD *)(v33 + 56);
      v41 = v39->m_a;
      v42 = (__m128 *)((signed int)v41 >= v40 ? *(_QWORD *)(v33 + 304) + 16i64 * ((signed int)v41 - v40) : *(_QWORD *)(v33 + 48) + 16 * v41);
      v43 = *(__m128 *)(v33 + 128);
      v44 = *(__m128 *)(v33 + 112);
      v45 = v39->m_b;
      v46 = *(__m128 *)(v33 + 144);
      v47 = *(__m128 *)(v33 + 160);
      v48 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v42, *v42, 0), v44),
                  _mm_mul_ps(_mm_shuffle_ps(*v42, *v42, 85), v43)),
                _mm_mul_ps(_mm_shuffle_ps(*v42, *v42, 170), v46)),
              v47);
      v49 = (__m128 *)((signed int)v45 >= v40 ? *(_QWORD *)(v33 + 304) + 16i64 * ((signed int)v45 - v40) : *(_QWORD *)(v33 + 48) + 16 * v45);
      v50.m_real = (__m128)v8->m_searchSphereRadius;
      v51 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v49, *v49, 0), v44),
                  _mm_mul_ps(_mm_shuffle_ps(*v49, *v49, 85), v43)),
                _mm_mul_ps(_mm_shuffle_ps(*v49, *v49, 170), v46)),
              v47);
      v130 = v51;
      if ( v50.m_real.m128_f32[0] >= 0.0 )
      {
        v52 = _mm_sub_ps(v48, v8->m_startPoint.m_quad);
        v53 = _mm_sub_ps(v48, v51);
        v54 = _mm_mul_ps(v53, v53);
        v55 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), _mm_shuffle_ps(v54, v54, 0)),
                _mm_shuffle_ps(v54, v54, 170));
        v56 = _mm_mul_ps(v52, v53);
        v57 = _mm_rcp_ps(v55);
        v58 = _mm_mul_ps(
                _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v55, v57)), v57),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
                  _mm_shuffle_ps(v56, v56, 170)));
        v59 = _mm_cmpltps(v58, v29);
        v60 = _mm_sub_ps(
                v52,
                _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v59, v58), _mm_andnot_ps(v59, v29))), v53));
        v61 = _mm_mul_ps(v60, v60);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 170))) > (float)(v50.m_real.m128_f32[0]
                                                                          * v50.m_real.m128_f32[0]) )
          goto LABEL_51;
      }
      v62 = v8->m_searchCapsuleRadius.m_real;
      if ( v62.m128_f32[0] >= 0.0 )
      {
        v63 = v8->m_numGoals;
        v64 = 0;
        v65 = 0i64;
        v66 = _mm_sub_ps(v51, v48);
        if ( (signed int)v63 > 0 )
        {
          v67 = v8->m_startPoint.m_quad;
          v68 = (__m128)_xmm;
          v69 = &v8->m_endPoints->m_quad;
          v129 = _mm_mul_ps(v62, v62);
          v70 = _mm_sub_ps(v48, v67);
          v128 = v70;
          v71 = _mm_mul_ps(v70, v66);
          v72 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v71, v71, 85), _mm_shuffle_ps(v71, v71, 0)),
                  _mm_shuffle_ps(v71, v71, 170));
          v73 = _mm_mul_ps(v66, v66);
          v74 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
                  _mm_shuffle_ps(v73, v73, 170));
          v75 = _mm_rcp_ps(v74);
          v127 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v75, v74)), v75);
          v126 = _mm_mul_ps(v72, v127);
          do
          {
            v76 = _mm_sub_ps(*v69, v67);
            v77 = _mm_mul_ps(v76, v66);
            v78 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v77, v77, 85), _mm_shuffle_ps(v77, v77, 0)),
                    _mm_shuffle_ps(v77, v77, 170));
            v79 = _mm_mul_ps(v70, v76);
            v80 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v79, v79, 85), _mm_shuffle_ps(v79, v79, 0)),
                    _mm_shuffle_ps(v79, v79, 170));
            v81 = _mm_mul_ps(v76, v76);
            v82 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v81, v81, 85), _mm_shuffle_ps(v81, v81, 0)),
                    _mm_shuffle_ps(v81, v81, 170));
            v83 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v74, v82), _mm_mul_ps(v78, v78)), *(__m128 *)&epsilon);
            v84 = _mm_rcp_ps(v83);
            v85 = _mm_cmpleps(v83, *(__m128 *)&epsilon);
            v86 = _mm_mul_ps(_mm_sub_ps(v68, _mm_mul_ps(v84, v83)), v84);
            v87 = _mm_rcp_ps(v82);
            v88 = _mm_mul_ps(_mm_sub_ps(v68, _mm_mul_ps(v87, v82)), v87);
            v89 = _mm_sub_ps(_mm_mul_ps(v74, v80), _mm_mul_ps(v72, v78));
            v90 = _mm_cmpltps(v89, v83);
            v91 = _mm_sub_ps(
                    _mm_mul_ps(
                      _mm_or_ps(
                        _mm_andnot_ps(
                          v85,
                          _mm_mul_ps(
                            _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v90, v83), _mm_and_ps(v90, v89))),
                            v86)),
                        _mm_and_ps(v85, v29)),
                      _mm_mul_ps(v78, v127)),
                    v126);
            v92 = _mm_cmpltps(v91, v29);
            v93 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v92, v29), _mm_and_ps(v92, v91)));
            v67 = v8->m_startPoint.m_quad;
            v94 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v78, v88), v93), _mm_mul_ps(v80, v88));
            v95 = _mm_cmpltps(v94, v29);
            v96 = _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v95, v29), _mm_and_ps(v95, v94))),
                        v76),
                      v67),
                    _mm_add_ps(_mm_mul_ps(v93, v66), v48));
            v97 = _mm_mul_ps(v96, v96);
            if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v97, v97, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v97, v97, 0)))
                       + COERCE_FLOAT(_mm_shuffle_ps(v97, v97, 170))) <= v129.m128_f32[0] )
              break;
            v70 = v128;
            v68 = (__m128)_xmm;
            ++v65;
            ++v64;
            ++v69;
          }
          while ( v65 < v63 );
          v51 = v130;
        }
        if ( v64 == (_DWORD)v63 )
          goto LABEL_51;
      }
      v98 = v8->m_edgeFilter;
      if ( v98 )
      {
        v131 = -1;
        v132 = 0i64;
        v133 = -1;
        v134 = 0i64;
        v137 = -1;
        v138 = 0i64;
        striding = *(_DWORD *)(v33 + 72);
        v100 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v51, v48), (__m128)xmmword_141A711B0), v48);
        if ( striding )
          hkaiNavMeshInstance_getWithStriding_int__3(
            *(const int **)(v33 + 64),
            *(_DWORD *)(v33 + 24),
            (hkArray<int,hkContainerHeapAllocator> *)(v33 + 352),
            (hkArray<int,hkContainerHeapAllocator> *)(v33 + 384),
            (hkArray<int,hkContainerHeapAllocator> *)(v33 + 224),
            v114,
            striding);
        v101 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__10(
                 *(hkaiNavMesh::Face **)(v33 + 16),
                 *(_DWORD *)(v33 + 24),
                 (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v33 + 240),
                 (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v33 + 272),
                 (hkArray<int,hkContainerHeapAllocator> *)(v33 + 224),
                 v114);
        v139 = v102;
        v137 = retaddr;
        v138 = v101;
        if ( *(_DWORD *)(v33 + 88) )
          v103 = hkaiNavMeshInstance_getWithStriding_int__3(
                   *(const int **)(v33 + 80),
                   *(_DWORD *)(v33 + 40),
                   (hkArray<int,hkContainerHeapAllocator> *)(v33 + 368),
                   (hkArray<int,hkContainerHeapAllocator> *)(v33 + 400),
                   (hkArray<int,hkContainerHeapAllocator> *)(v33 + 208),
                   v32,
                   *(_DWORD *)(v33 + 88));
        else
          v103 = 0i64;
        v104 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__10(
                 *(hkaiNavMesh::Edge **)(v33 + 32),
                 *(_DWORD *)(v33 + 40),
                 (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v33 + 256),
                 (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v33 + 288),
                 (hkArray<int,hkContainerHeapAllocator> *)(v33 + 208),
                 v32);
        v136 = v100;
        v105 = *(_DWORD *)&v115[4 * v7];
        v134 = v104;
        v123 = &v8->m_info;
        v133 = v105;
        v135 = v103;
        v122 = v33;
        v125 = 33;
        v124 = &v131;
        if ( !((unsigned __int8 (__fastcall *)(hkaiAstarEdgeFilter *, __int64 *))v98->vfptr[2].__first_virtual_table_function__)(
                v98,
                &v122) )
          goto LABEL_50;
        v29 = query.m_quad;
      }
      v106 = *((signed int *)&v142->vfptr->__vecDelDtor + v117);
      v107 = *((signed int *)&v142->vfptr->__vecDelDtor + v37);
      if ( (_DWORD)v106 == (_DWORD)v107 || (_DWORD)v106 == -1 || (_DWORD)v107 == -1 )
        goto LABEL_51;
      v108 = v107 | ((_DWORD)v106 << 16);
      v109 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                 &v116,
                                 v108);
      if ( v109 > v116.m_hashMod )
      {
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &v116,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v108,
          0i64);
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &v116,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          ((signed __int64)v108 >> 16) | (v108 << 16),
          0i64);
        v110 = getCostBetweenFaces(
                 v8,
                 v143->m_data[v106],
                 v143->m_data[v107],
                 (hkaiNavMeshPathSearchParameters *)centroids,
                 (hkaiAgentTraversalInfo *)searchParams);
        hkaiDirectedGraphExplicitCostBuilder::addEdge(&v120, v106, v107, v110);
        hkaiDirectedGraphExplicitCostBuilder::addEdge(&v120, v107, v106, v110);
      }
LABEL_50:
      v29 = query.m_quad;
LABEL_51:
      v18 = v115;
      if ( ++v7 >= v121 )
      {
        v21 = v119;
        goto LABEL_53;
      }
    }
  }
LABEL_61:
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v116,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v116);
  hkaiDirectedGraphExplicitCostBuilder::build(&v120, d);
  LODWORD(v120.m_links.m_data) = v7;
  if ( SHIDWORD(v120.m_links.m_data) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)&v120.m_positions.m_size,
      12 * (HIDWORD(v120.m_links.m_data) & 0x3FFFFFFF));
  *(_QWORD *)&v120.m_positions.m_size = 0i64;
  LODWORD(v120.m_positions.m_data) = 0;
  HIDWORD(v120.m_links.m_data) = 2147483648;
  if ( SHIDWORD(v120.m_positions.m_data) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v120.m_positions.m_data,
      16 * HIDWORD(v120.m_positions.m_data));
}

// File Line: 791
// RVA: 0xBF99F0
void __fastcall hkaiHierarchyUtils::clusterNavMesh(hkaiNavMesh *mesh, hkaiDirectedGraphExplicitCost *graphOut, int numGroups, bool ensureClusterPerNode, hkaiAstarCostModifier *costModifier, hkaiAstarEdgeFilter *edgeFilter)
{
  hkaiNavMesh *v6; // rsi
  int v7; // ebx
  hkaiDirectedGraphExplicitCost *v8; // rdi
  hkaiHierarchyUtils::ClusterSettings settings; // [rsp+20h] [rbp-68h]

  v6 = mesh;
  v7 = ensureClusterPerNode;
  v8 = graphOut;
  hkaiHierarchyUtils::ClusterSettings::ClusterSettings(&settings);
  settings.m_searchParameters.m_costModifier = costModifier;
  settings.m_desiredFacesPerCluster = v7;
  settings.m_searchParameters.m_edgeFilter = edgeFilter;
  hkaiHierarchyUtils::clusterNavMesh(v6, v8, &settings);
}

// File Line: 801
// RVA: 0xBF94C0
void __fastcall hkaiHierarchyUtils::clusterNavMesh(hkaiNavMesh *mesh, hkaiDirectedGraphExplicitCost *graphOut, hkaiHierarchyUtils::ClusterSettings *settings)
{
  hkaiDirectedGraphExplicitCost *v3; // rbx
  int v4; // esi
  hkaiHierarchyUtils::ClusterSettings *v5; // r13
  hkaiNavMesh *v6; // r14
  int v7; // eax
  int v8; // er8
  int v9; // er8
  int v10; // er8
  int v11; // er9
  hkaiStreamingCollection::InstanceInfo *v12; // r9
  __int64 v13; // rdx
  hkaiDirectedGraphInstance **v14; // rax
  __int64 v15; // r15
  _QWORD *v16; // rax
  unsigned __int64 v17; // rcx
  _QWORD *v18; // r9
  unsigned __int64 v19; // rax
  _QWORD *v20; // r8
  _QWORD *v21; // rcx
  unsigned __int64 v22; // rax
  signed __int64 v23; // rcx
  int v24; // ecx
  int v25; // edi
  int v26; // edi
  __int64 v27; // rsi
  __int64 v28; // r8
  __int64 v29; // r9
  _QWORD *v30; // r8
  _QWORD *v31; // rcx
  unsigned __int64 v32; // rax
  signed __int64 v33; // rcx
  hkArray<int,hkContainerHeapAllocator> groupRepresentative; // [rsp+40h] [rbp-C0h]
  hkArray<hkVector4f,hkContainerHeapAllocator> centroids; // [rsp+50h] [rbp-B0h]
  hkArray<int,hkContainerHeapAllocator> groupFromNode; // [rsp+60h] [rbp-A0h]
  hkaiStreamingCollection array; // [rsp+70h] [rbp-90h]
  hkaiNavMeshFaceGraph graph; // [rsp+A0h] [rbp-60h]
  hkaiNavMeshInstance v39; // [rsp+110h] [rbp+10h]
  hkResult result; // [rsp+320h] [rbp+220h]

  v3 = graphOut;
  v4 = 1;
  v5 = settings;
  v6 = mesh;
  v7 = mesh->m_faces.m_size / settings->m_desiredFacesPerCluster;
  v8 = graphOut->m_positions.m_capacityAndFlags;
  if ( v7 > 1 )
    v4 = v7;
  graphOut->m_positions.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      graphOut->m_positions.m_data,
      16 * v8);
  v3->m_positions.m_data = 0i64;
  v3->m_positions.m_capacityAndFlags = 2147483648;
  v9 = v3->m_nodes.m_capacityAndFlags;
  v3->m_nodes.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v3->m_nodes.m_data,
      8 * v9);
  v3->m_nodes.m_data = 0i64;
  v3->m_nodes.m_capacityAndFlags = 2147483648;
  v10 = v3->m_edges.m_capacityAndFlags;
  v3->m_edges.m_size = 0;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v3->m_edges.m_data,
      8 * v10);
  v3->m_edges.m_data = 0i64;
  v3->m_edges.m_capacityAndFlags = 2147483648;
  if ( v6->m_faces.m_size )
  {
    graph.m_collection = 0i64;
    graph.m_info.m_filterInfo = 0;
    graph.m_info.m_diameter = 0.0;
    _mm_store_si128((__m128i *)&graph.m_costModifier, (__m128i)0i64);
    graph.m_searchState = 0i64;
    graph.m_searchSphereRadius.m_real = _mm_sub_ps((__m128)0i64, query.m_quad);
    graph.m_searchCapsuleRadius = graph.m_searchSphereRadius;
    hkaiNavMeshInstance::hkaiNavMeshInstance(&v39);
    hkaiNavMeshInstance::tempInit(&v39, v6, 1);
    hkaiStreamingCollection::hkaiStreamingCollection(&array);
    array.m_isTemporary.m_bool = 1;
    if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) < 1 )
    {
      v11 = 1;
      if ( 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) > 1 )
        v11 = 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &array.m_instances,
        v11,
        48);
    }
    v12 = array.m_instances.m_data;
    v13 = 1 - array.m_instances.m_size;
    if ( 1 - array.m_instances.m_size > 0 )
    {
      v14 = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
      do
      {
        if ( v14 != (hkaiDirectedGraphInstance **)16 )
        {
          *(v14 - 2) = 0i64;
          *(v14 - 1) = 0i64;
          *v14 = 0i64;
          v14[1] = 0i64;
          v14[2] = 0i64;
          *((_DWORD *)v14 + 6) = -1;
        }
        v14 += 6;
        --v13;
      }
      while ( v13 );
      v12 = array.m_instances.m_data;
    }
    array.m_instances.m_size = 1;
    v12->m_instancePtr = &v39;
    array.m_instances.m_data->m_clusterGraphInstance = 0i64;
    array.m_instances.m_data->m_mediator = 0i64;
    v15 = v6->m_faces.m_size;
    groupFromNode.m_data = 0i64;
    groupFromNode.m_size = 0;
    graph.m_collection = &array;
    groupFromNode.m_capacityAndFlags = 2147483648;
    groupRepresentative.m_data = 0i64;
    groupRepresentative.m_size = 0;
    groupRepresentative.m_capacityAndFlags = 2147483648;
    centroids.m_data = 0i64;
    centroids.m_size = 0;
    centroids.m_capacityAndFlags = 2147483648;
    v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v17 = v16[1];
    v18 = v16;
    if ( v17 < v16[3] )
    {
      *(_QWORD *)v17 = "LtclusterNavMesh";
      *(_QWORD *)(v17 + 16) = "StgenerateClusters";
      v19 = __rdtsc();
      *(_DWORD *)(v17 + 8) = v19;
      v18[1] = v17 + 24;
    }
    hkaiSimpleClusterGenerator::generateClusters(
      &graph,
      v4,
      (signed int)v15 / v4 + 1,
      v5->m_ensureClusterPerRegion.m_bool != 0,
      &groupFromNode,
      &groupRepresentative,
      413);
    v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v21 = (_QWORD *)v20[1];
    if ( (unsigned __int64)v21 < v20[3] )
    {
      *v21 = "StgenerateGraph";
      v22 = __rdtsc();
      v23 = (signed __int64)(v21 + 2);
      *(_DWORD *)(v23 - 8) = v22;
      v20[1] = v23;
    }
    v24 = groupRepresentative.m_size;
    v25 = groupRepresentative.m_size;
    if ( (centroids.m_capacityAndFlags & 0x3FFFFFFF) < groupRepresentative.m_size )
    {
      if ( groupRepresentative.m_size < 2 * (centroids.m_capacityAndFlags & 0x3FFFFFFF) )
        v24 = 2 * (centroids.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &centroids, v24, 16);
      v24 = groupRepresentative.m_size;
    }
    centroids.m_size = v25;
    v26 = 0;
    if ( v24 > 0 )
    {
      v27 = 0i64;
      do
      {
        hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)graph.m_collection->m_instances.m_data[(unsigned int)groupRepresentative.m_data[v27] >> 22].m_instancePtr,
          (hkaiNavMeshInstance *)(groupRepresentative.m_data[v27] & 0x3FFFFF),
          (__int64)&centroids.m_data[v26++],
          (hkVector4f *)(6i64 * ((unsigned int)groupRepresentative.m_data[v27] >> 22)));
        ++v27;
      }
      while ( v26 < groupRepresentative.m_size );
    }
    hkaiHierarchyUtils::buildAbstractGraphFromClusterInfo(
      &graph,
      v3,
      &groupFromNode,
      &groupRepresentative,
      &centroids,
      &v5->m_searchParameters,
      &v5->m_agentInfo);
    v28 = 0i64;
    if ( v15 > 0 )
    {
      v29 = 0i64;
      do
      {
        ++v28;
        ++v29;
        *((_WORD *)&v6->m_faces.m_data[v29] - 2) = groupFromNode.m_data[v28 - 1];
      }
      while ( v28 < v15 );
    }
    v30 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v31 = (_QWORD *)v30[1];
    if ( (unsigned __int64)v31 < v30[3] )
    {
      *v31 = "lt";
      v32 = __rdtsc();
      v33 = (signed __int64)(v31 + 2);
      *(_DWORD *)(v33 - 8) = v32;
      v30[1] = v33;
    }
    centroids.m_size = 0;
    if ( centroids.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        centroids.m_data,
        16 * centroids.m_capacityAndFlags);
    centroids.m_data = 0i64;
    centroids.m_capacityAndFlags = 2147483648;
    groupRepresentative.m_size = 0;
    if ( groupRepresentative.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        groupRepresentative.m_data,
        4 * groupRepresentative.m_capacityAndFlags);
    groupRepresentative.m_data = 0i64;
    groupRepresentative.m_capacityAndFlags = 2147483648;
    groupFromNode.m_size = 0;
    if ( groupFromNode.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        groupFromNode.m_data,
        4 * groupFromNode.m_capacityAndFlags);
    groupFromNode.m_data = 0i64;
    groupFromNode.m_capacityAndFlags = 2147483648;
    hkaiStreamingCollection::~hkaiStreamingCollection(&array);
    hkaiNavMeshInstance::~hkaiNavMeshInstance(&v39);
  }
}


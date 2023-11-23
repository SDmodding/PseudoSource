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
  this->m_searchParameters.m_up.m_vec[2] = 0x8000;
  this->m_agentInfo = 0i64;
}

// File Line: 36
// RVA: 0xBF94B0
void __fastcall hkaiHierarchyUtils::ClusterSettings::ClusterSettings(
        hkaiHierarchyUtils::ClusterSettings *this,
        hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 42
// RVA: 0xBF9A60
__int64 __fastcall hkaiHierarchyUtils::SemiSparse2dArraySorted::indexOf(
        hkaiHierarchyUtils::SemiSparse2dArraySorted *this,
        hkArray<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost,hkContainerHeapAllocator> *a,
        int y,
        unsigned int *greaterThanIndex)
{
  __int64 m_size; // rbx
  unsigned int v5; // r10d
  __int64 v6; // rcx
  hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost *m_data; // rax

  m_size = a->m_size;
  v5 = 0;
  v6 = 0i64;
  if ( (int)m_size <= 0 )
  {
LABEL_6:
    *greaterThanIndex = m_size;
    return 0xFFFFFFFFi64;
  }
  else
  {
    m_data = a->m_data;
    while ( y != m_data->t )
    {
      if ( y < m_data->t )
      {
        *greaterThanIndex = v5;
        return 0xFFFFFFFFi64;
      }
      ++v6;
      ++v5;
      ++m_data;
      if ( v6 >= m_size )
        goto LABEL_6;
    }
    return v5;
  }
}

// File Line: 62
// RVA: 0xBF9AC0
__int64 __fastcall hkaiHierarchyUtils::SemiSparse2dArraySorted::indexOf_binarySearch(
        hkaiHierarchyUtils::SemiSparse2dArraySorted *this,
        hkArray<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost,hkContainerHeapAllocator> *a,
        int y,
        int *greaterThanIndex)
{
  int m_size; // edi
  hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost *m_data; // rbx
  int v6; // r11d
  int t; // edx
  int v8; // r10d
  __int64 result; // rax
  int v10; // eax
  int v11; // edx

  m_size = a->m_size;
  m_data = a->m_data;
  v6 = 0;
  t = a->m_data->t;
  v8 = m_size - 1;
  if ( t == y )
    return 0i64;
  v10 = m_data[v8].t;
  if ( v10 == y )
    return (unsigned int)v8;
  if ( v10 >= y )
  {
    if ( t <= y )
    {
      if ( v8 <= 1 )
      {
LABEL_15:
        *greaterThanIndex = v8;
        return 0xFFFFFFFFi64;
      }
      else
      {
        while ( 1 )
        {
          result = (unsigned int)((v8 + v6) / 2);
          v11 = m_data[(int)result].t;
          if ( y == v11 )
            break;
          if ( y >= v11 )
            v6 = (v8 + v6) / 2;
          else
            v8 = (v8 + v6) / 2;
          if ( v8 - v6 <= 1 )
            goto LABEL_15;
        }
      }
    }
    else
    {
      *greaterThanIndex = 0;
      return 0xFFFFFFFFi64;
    }
  }
  else
  {
    *greaterThanIndex = m_size;
    return 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 105
// RVA: 0xBF9B80
void __fastcall hkaiHierarchyUtils::SemiSparse2dArraySorted::setSize(
        hkaiHierarchyUtils::SemiSparse2dArraySorted *this,
        int n,
        float r)
{
  hkArray<hkArray<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost,hkContainerHeapAllocator>,hkContainerHeapAllocator> *p_m_costs; // r14
  __int64 v4; // rbp
  int v5; // eax
  int v7; // eax
  int v8; // r9d
  int v9; // eax
  __int64 v10; // rsi
  __int64 v11; // rdi
  int *v12; // rbx
  int v13; // r8d
  __int64 m_size; // rdx
  int v15; // ecx
  __int64 v16; // rax
  __int64 v17; // rdx
  __int64 v18; // rbx
  hkArray<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost,hkContainerHeapAllocator> *m_data; // rdi
  int m_capacityAndFlags; // r8d
  hkResult result; // [rsp+78h] [rbp+10h] BYREF

  p_m_costs = &this->m_costs;
  v4 = n;
  v5 = this->m_costs.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < n )
  {
    v7 = 2 * v5;
    v8 = n;
    if ( n < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_costs, v8, 16);
  }
  v9 = p_m_costs->m_size - v4 - 1;
  v10 = v4;
  v11 = v9;
  if ( v9 >= 0 )
  {
    v12 = &p_m_costs->m_data[v4].m_capacityAndFlags + 4 * v9;
    do
    {
      v13 = *v12;
      *(v12 - 1) = 0;
      if ( v13 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v12 - 3),
          8 * v13);
      *(_QWORD *)(v12 - 3) = 0i64;
      *v12 = 0x80000000;
      v12 -= 4;
      --v11;
    }
    while ( v11 >= 0 );
  }
  m_size = p_m_costs->m_size;
  v15 = v4 - m_size;
  v16 = (int)v4 - (int)m_size;
  v17 = (__int64)&p_m_costs->m_data[m_size];
  if ( v15 > 0 )
  {
    do
    {
      if ( v17 )
      {
        *(_QWORD *)v17 = 0i64;
        *(_DWORD *)(v17 + 8) = 0;
        *(_DWORD *)(v17 + 12) = 0x80000000;
      }
      v17 += 16i64;
      --v16;
    }
    while ( v16 );
  }
  p_m_costs->m_size = v4;
  this->m_default = r;
  this->m_n = v4;
  if ( v4 > 0 )
  {
    v18 = 0i64;
    do
    {
      m_data = p_m_costs->m_data;
      m_capacityAndFlags = p_m_costs->m_data[v18].m_capacityAndFlags;
      p_m_costs->m_data[v18].m_size = 0;
      if ( m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          m_data[v18].m_data,
          8 * m_capacityAndFlags);
      m_data[v18].m_data = 0i64;
      m_data[v18++].m_capacityAndFlags = 0x80000000;
      --v10;
    }
    while ( v10 );
  }
}

// File Line: 116
// RVA: 0xBF9D10
float __fastcall hkaiHierarchyUtils::SemiSparse2dArraySorted::get(
        hkaiHierarchyUtils::SemiSparse2dArraySorted *this,
        int x,
        int y)
{
  hkArray<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost,hkContainerHeapAllocator> *v4; // rbx
  int v5; // eax
  int greaterThanIndex; // [rsp+38h] [rbp+10h] BYREF

  v4 = &this->m_costs.m_data[x];
  v5 = hkaiHierarchyUtils::SemiSparse2dArraySorted::indexOf_binarySearch(this, v4, y, &greaterThanIndex);
  if ( v5 == -1 )
    return this->m_default;
  else
    return v4->m_data[v5].r;
}

// File Line: 129
// RVA: 0xBF9D70
void __fastcall hkaiHierarchyUtils::SemiSparse2dArraySorted::set(
        hkaiHierarchyUtils::SemiSparse2dArraySorted *this,
        int x,
        int y,
        float r)
{
  hkArray<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost,hkContainerHeapAllocator> *v5; // rbx
  hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost *m_data; // rcx
  __int64 m_size; // rdx
  hkArray<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost,hkContainerHeapAllocator> *v8; // rdx
  int v9; // eax
  hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost t; // [rsp+40h] [rbp+8h] BYREF
  int greaterThanIndex; // [rsp+48h] [rbp+10h] BYREF

  v5 = &this->m_costs.m_data[x];
  if ( v5->m_size )
  {
    v8 = &this->m_costs.m_data[x];
    greaterThanIndex = -1;
    v9 = hkaiHierarchyUtils::SemiSparse2dArraySorted::indexOf_binarySearch(this, v8, y, &greaterThanIndex);
    if ( v9 == -1 )
    {
      t.r = r;
      t.t = y;
      hkArrayBase<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost>::_insertAt(
        v5,
        &hkContainerHeapAllocator::s_alloc,
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
    if ( (v5->m_capacityAndFlags & 0x3FFFFFFF) == 0 )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v5, 8);
    m_data = v5->m_data;
    m_size = v5->m_size;
    v5->m_size = m_size + 1;
    m_data[m_size].t = y;
    m_data[m_size].r = r;
  }
}

// File Line: 159
// RVA: 0xBF9F10
void __fastcall hkaiHierarchyUtils::SemiSparse2dArraySorted::validate(
        hkaiHierarchyUtils::SemiSparse2dArraySorted *this)
{
  ;
}

// File Line: 169
// RVA: 0xBF9F20
void __fastcall hkaiHierarchyUtils::SemiSparse2dArraySorted::validateSub(
        hkaiHierarchyUtils::SemiSparse2dArraySorted *this,
        int i)
{
  ;
}

// File Line: 182
// RVA: 0xBF9E50
void __fastcall hkaiHierarchyUtils::SemiSparse2dArraySorted::findMinValFromSet(
        hkaiHierarchyUtils::SemiSparse2dArraySorted *this,
        int x,
        hkArrayBase<hkaiHierarchyUtils::RepGroupPair> *sortedReps,
        int *minIndex,
        float *minCost)
{
  int v5; // r10d
  hkArray<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost,hkContainerHeapAllocator> *v8; // rdi
  int v9; // r9d
  __int64 v10; // r8
  __int64 v11; // rdx
  int t; // r11d
  int m_representative; // eax
  float r; // xmm0_4

  *minIndex = -1;
  *minCost = this->m_default;
  v5 = 0;
  v8 = &this->m_costs.m_data[x];
  v9 = 0;
  if ( v8->m_size > 0 )
  {
    v10 = 0i64;
    v11 = 0i64;
    do
    {
      if ( v9 >= sortedReps->m_size )
        return;
      t = v8->m_data[v11].t;
      m_representative = sortedReps->m_data[v10].m_representative;
      if ( t == m_representative )
      {
        r = v8->m_data[v11].r;
        if ( r < *minCost )
        {
          *minCost = r;
          *minIndex = sortedReps->m_data[v10].m_group;
        }
        ++v5;
        ++v11;
      }
      else if ( t < m_representative )
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
void __fastcall hkaiHierarchyUtils::CostAdaptor::CostAdaptor(
        hkaiHierarchyUtils::CostAdaptor *this,
        hkaiHierarchyUtils::SemiSparse2dArraySorted *costs,
        int sourceNid)
{
  this->m_costs = costs;
  this->m_sourceNid = sourceNid;
}

// File Line: 228
// RVA: 0xBF9F50
double __fastcall hkaiHierarchyUtils::CostAdaptor::getCost(hkaiHierarchyUtils::CostAdaptor *this, int nid)
{
  double result; // xmm0_8

  *(float *)&result = hkaiHierarchyUtils::SemiSparse2dArraySorted::get(this->m_costs, this->m_sourceNid, nid);
  return result;
}

// File Line: 232
// RVA: 0xBF9F70
void __fastcall hkaiHierarchyUtils::CostAdaptor::setCost(
        hkaiHierarchyUtils::CostAdaptor *this,
        hkaiGraphMultiDistanceHeuristic<hkaiNavMeshFaceGraph> *h_unused,
        int nid,
        float d)
{
  hkaiHierarchyUtils::SemiSparse2dArraySorted::set(this->m_costs, this->m_sourceNid, nid, d);
}

// File Line: 236
// RVA: 0xBF9F90
_BOOL8 __fastcall hkaiHierarchyUtils::CostAdaptor::estimatedCostLess(
        hkaiHierarchyUtils::CostAdaptor *this,
        int a,
        int b)
{
  int m_sourceNid; // ebx
  hkaiHierarchyUtils::SemiSparse2dArraySorted *m_costs; // rdi
  float v6; // xmm6_4

  m_sourceNid = this->m_sourceNid;
  m_costs = this->m_costs;
  v6 = hkaiHierarchyUtils::SemiSparse2dArraySorted::get(this->m_costs, m_sourceNid, a);
  return hkaiHierarchyUtils::SemiSparse2dArraySorted::get(m_costs, m_sourceNid, b) > v6;
}

// File Line: 241
// RVA: 0xBF9FF0
double __fastcall hkaiHierarchyUtils::CostAdaptor::estimatedCost(hkaiHierarchyUtils::CostAdaptor *this, int a)
{
  double result; // xmm0_8

  *(float *)&result = hkaiHierarchyUtils::SemiSparse2dArraySorted::get(this->m_costs, this->m_sourceNid, a);
  return result;
}

// File Line: 246
// RVA: 0xBFA010
// attributes: thunk
double __fastcall hkaiHierarchyUtils::CostAdaptor::estimatedCostCurrent(hkaiHierarchyUtils::CostAdaptor *this, int a)
{
  return hkaiHierarchyUtils::CostAdaptor::estimatedCost(this, a);
}

// File Line: 254
// RVA: 0xBFADE0
float __fastcall getCostBetweenFaces(
        hkaiNavMeshFaceGraph *graph,
        hkaiNavMeshInstance *nstart,
        unsigned int nend,
        hkVector4f *searchParams,
        hkaiAgentTraversalInfo *agentInfo)
{
  hkaiNavMeshInstance *m_instancePtr; // rdi
  unsigned int v9; // r15d
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
  hkaiStreamingCollection *m_collection; // rcx
  float m_pathLength; // xmm6_4
  hkaiPathfindingUtil::FindPathOutput output; // [rsp+20h] [rbp-E0h] BYREF
  hkaiPathfindingUtil::FindPathInput input; // [rsp+60h] [rbp-A0h] BYREF
  int v28[4]; // [rsp+120h] [rbp+20h] BYREF
  hkaiNavMeshUtils v29[16]; // [rsp+130h] [rbp+30h] BYREF
  int v30[4]; // [rsp+140h] [rbp+40h] BYREF
  int faceIndex[4]; // [rsp+150h] [rbp+50h] BYREF
  __m128 v32[2]; // [rsp+160h] [rbp+60h] BYREF

  m_instancePtr = graph->m_collection->m_instances.m_data->m_instancePtr;
  v9 = (unsigned int)nstart;
  hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
    (hkaiNavMeshUtils *)m_instancePtr,
    nstart,
    (__m128 *)faceIndex,
    searchParams);
  hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
    (hkaiNavMeshUtils *)m_instancePtr,
    (hkaiNavMeshInstance *)nend,
    (__m128 *)v30,
    v10);
  hkaiPathfindingUtil::FindPathInput::FindPathInput(&input, 1);
  input.m_startFaceKey = v9;
  *input.m_goalFaceKeys.m_data = nend;
  input.m_startPoint = *(hkVector4f *)faceIndex;
  *input.m_goalPoints.m_data = *(hkVector4f *)v30;
  v11 = _mm_unpacklo_epi16((__m128i)0i64, _mm_loadl_epi64((const __m128i *)searchParams));
  v12 = *agentInfo;
  *(_QWORD *)input.m_searchParameters.m_up.m_vec = searchParams->m_quad.m128_u64[0];
  v13 = (hkaiAstarCostModifier *)searchParams->m_quad.m128_u64[1];
  input.m_agentInfo = v12;
  input.m_searchParameters.m_costModifier = v13;
  v14 = _mm_mul_ps(
          _mm_cvtepi32_ps(_mm_add_epi32(v11, _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset))),
          (__m128)xmmword_141A713A0);
  v15 = _mm_mul_ps(v14, v14);
  input.m_searchParameters.m_edgeFilter = (hkaiAstarEdgeFilter *)searchParams[1].m_quad.m128_u64[0];
  *(_QWORD *)&input.m_searchParameters.m_validateInputs.m_bool = searchParams[1].m_quad.m128_u64[1];
  *(_QWORD *)&input.m_searchParameters.m_heuristicWeight = searchParams[2].m_quad.m128_u64[0];
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  *(_QWORD *)&input.m_searchParameters.m_maximumPathLength = searchParams[2].m_quad.m128_u64[1];
  v17 = _mm_rsqrt_ps(v16);
  *(_QWORD *)&input.m_searchParameters.m_searchCapsuleRadius = searchParams[3].m_quad.m128_u64[0];
  *(_QWORD *)&input.m_searchParameters.m_bufferSizes.m_maxSearchStateSizeBytes = searchParams[3].m_quad.m128_u64[1];
  *(_QWORD *)&input.m_searchParameters.m_hierarchyBufferSizes.m_maxSearchStateSizeBytes = searchParams[4].m_quad.m128_u64[0];
  if ( _mm_andnot_ps(
         _mm_cmple_ps(v16, (__m128)0i64),
         _mm_mul_ps(
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)), _mm_mul_ps(*(__m128 *)_xmm, v17)),
           v16)).m128_f32[0] < 0.5 )
  {
    hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
      v29,
      (hkSimdFloat32 *)m_instancePtr,
      (hkaiNavMeshInstance *)v9,
      v32);
    hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
      v29,
      (hkSimdFloat32 *)m_instancePtr,
      (hkaiNavMeshInstance *)nend,
      (__m128 *)v28);
    v18 = _mm_add_ps(v32[0], *(__m128 *)v28);
    v19 = _mm_mul_ps(v18, v18);
    v20 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
            _mm_shuffle_ps(v19, v19, 170));
    v21 = _mm_mul_ps(
            _mm_mul_ps(_mm_andnot_ps(_mm_cmple_ps(v20, (__m128)0i64), _mm_div_ps(query.m_quad, _mm_sqrt_ps(v20))), v18),
            (__m128)xmmword_141A71390);
    v22 = _mm_add_epi32(
            _mm_xor_si128(
              (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v21),
              _mm_cvttps_epi32(v21)),
            _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset));
    input.m_searchParameters.m_up.m_vec[0] = _mm_extract_epi16(v22, 1);
    input.m_searchParameters.m_up.m_vec[1] = _mm_extract_epi16(v22, 3);
    input.m_searchParameters.m_up.m_vec[2] = _mm_extract_epi16(v22, 5);
  }
  m_collection = graph->m_collection;
  output.m_outputParameters.m_pathLength = FLOAT_3_40282e38;
  input.m_searchParameters.m_outputPathFlags.m_storage = 0;
  *(_DWORD *)&output.m_memSizeAndFlags = 0x1FFFF;
  output.m_visitedEdges.m_data = 0i64;
  output.vfptr = (hkBaseObjectVtbl *)&hkaiPathfindingUtil::FindPathOutput::`vftable;
  output.m_visitedEdges.m_size = 0;
  output.m_visitedEdges.m_capacityAndFlags = 0x80000000;
  output.m_pathOut.m_data = 0i64;
  output.m_pathOut.m_size = 0;
  output.m_pathOut.m_capacityAndFlags = 0x80000000;
  output.m_outputParameters.m_numIterations = 0;
  output.m_outputParameters.m_goalIndex = -1;
  *(_WORD *)&output.m_outputParameters.m_status.m_storage = 0;
  hkaiPathfindingUtil::findPath(m_collection, &input, &output);
  output.m_pathOut.m_size = 0;
  m_pathLength = output.m_outputParameters.m_pathLength;
  if ( output.m_pathOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      output.m_pathOut.m_data,
      48 * (output.m_pathOut.m_capacityAndFlags & 0x3FFFFFFF));
  output.m_pathOut.m_data = 0i64;
  output.m_pathOut.m_capacityAndFlags = 0x80000000;
  output.m_visitedEdges.m_size = 0;
  if ( output.m_visitedEdges.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      output.m_visitedEdges.m_data,
      4 * output.m_visitedEdges.m_capacityAndFlags);
  output.m_visitedEdges.m_data = 0i64;
  output.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  output.m_visitedEdges.m_capacityAndFlags = 0x80000000;
  input.m_goalFaceKeys.m_size = 0;
  input.vfptr = (hkBaseObjectVtbl *)&hkaiPathfindingUtil::FindPathInput::`vftable;
  if ( input.m_goalFaceKeys.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      input.m_goalFaceKeys.m_data,
      4 * input.m_goalFaceKeys.m_capacityAndFlags);
  input.m_goalFaceKeys.m_data = 0i64;
  input.m_goalFaceKeys.m_capacityAndFlags = 0x80000000;
  input.m_goalPoints.m_size = 0;
  if ( input.m_goalPoints.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      input.m_goalPoints.m_data,
      16 * input.m_goalPoints.m_capacityAndFlags);
  return m_pathLength;
}

// File Line: 332
// RVA: 0xBFD400
void __fastcall hkaiSimpleClusterGenerator::getNearestNeighborCosts(
        hkaiNavMeshFaceGraph *graph,
        hkArrayBase<int> *nodesForRegion,
        hkaiHierarchyUtils::SemiSparse2dArraySorted *costs,
        int numToFill)
{
  __int64 v6; // r15
  __int64 v8; // rbx
  int i; // esi
  int v10; // r12d
  __int64 v11; // r15
  int v12; // esi
  hkVector4f *v13; // r9
  int v14; // r9d
  hkaiNavMeshUtils **m_data; // rcx
  hkaiSearchStateNode *NodeState; // rax
  hkaiSearchStateNode *v17; // rbx
  float v18; // xmm0_4
  double v19; // xmm0_8
  hkaiHeapOpenSet::IndexCostPair *m_heap; // rax
  __int64 m_heapSize; // r8
  int v22; // r10d
  hkaiHeapOpenSet::IndexCostPair *v23; // rdx
  int m_idx; // ebx
  hkaiHeapOpenSet::IndexCostPair::CostUnion v25; // r11d
  __int64 j; // r9
  __int64 v27; // rcx
  bool v28; // cc
  hkaiHeapOpenSet::IndexCostPair *v29; // [rsp+40h] [rbp-C0h] BYREF
  int v30; // [rsp+48h] [rbp-B8h]
  int v31; // [rsp+4Ch] [rbp-B4h]
  hkaiHeapOpenSet openset; // [rsp+50h] [rbp-B0h] BYREF
  char *array; // [rsp+60h] [rbp-A0h] BYREF
  int size; // [rsp+68h] [rbp-98h]
  int v35; // [rsp+6Ch] [rbp-94h]
  hkResult result; // [rsp+70h] [rbp-90h] BYREF
  __int64 v37; // [rsp+78h] [rbp-88h]
  hkaiHashSearchState flags; // [rsp+80h] [rbp-80h] BYREF
  hkaiHierarchyUtils::CostAdaptor pathCost; // [rsp+E0h] [rbp-20h] BYREF
  int faceIndex[4]; // [rsp+F0h] [rbp-10h] BYREF
  hkaiGraphMultiDistanceHeuristic<hkaiNavMeshFaceGraph> heuristic; // [rsp+100h] [rbp+0h] BYREF
  hkaiNullSearchParent v42; // [rsp+1D0h] [rbp+D0h] BYREF
  hkResult v43; // [rsp+1D8h] [rbp+D8h] BYREF

  v6 = numToFill;
  hkaiHierarchyUtils::SemiSparse2dArraySorted::setSize(
    costs,
    graph->m_collection->m_instances.m_data->m_instancePtr->m_numOriginalFaces
  + graph->m_collection->m_instances.m_data->m_instancePtr->m_ownedFaces.m_size,
    1000000.0);
  v8 = 0i64;
  for ( i = 0; i < nodesForRegion->m_size; ++v8 )
  {
    hkaiHierarchyUtils::SemiSparse2dArraySorted::set(costs, nodesForRegion->m_data[v8], nodesForRegion->m_data[v8], 0.0);
    ++i;
  }
  v10 = 0;
  if ( nodesForRegion->m_size > 0 )
  {
    v37 = v6;
    v11 = 0i64;
    do
    {
      v12 = nodesForRegion->m_data[v11];
      array = 0i64;
      size = 0;
      v35 = 0x80000000;
      v29 = 0i64;
      v30 = 0;
      v31 = 0x80000000;
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, 2816, 1);
      size = 2816;
      if ( (v31 & 0x3FFFFFFFu) >= 0x400 )
      {
        v43.m_enum = HK_SUCCESS;
      }
      else
      {
        v14 = 1024;
        if ( 2 * (v31 & 0x3FFFFFFF) > 1024 )
          v14 = 2 * (v31 & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&v43, &hkContainerTempAllocator::s_alloc, &v29, v14, 1);
      }
      v30 = 1024;
      m_data = (hkaiNavMeshUtils **)graph->m_collection->m_instances.m_data;
      heuristic.m_graph = graph;
      hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(*m_data, 0i64, (__m128 *)faceIndex, v13);
      heuristic.m_goals[0].m_position = *(hkVector4f *)faceIndex;
      heuristic.m_goals[0].m_index.m_storage = 0;
      heuristic.m_numGoals = 1;
      hkaiHierarchyUtils::CostAdaptor::CostAdaptor(&pathCost, costs, v12);
      memset(&flags, 0, 32);
      openset.m_heap = v29;
      openset.m_heapSize = 0;
      openset.m_maxSize = (unsigned __int64)v30 >> 3;
      flags.m_heuristicWeight = 1.0;
      flags.m_bestNode = -1;
      flags.m_dummyNode.m_parentIndex = -1;
      flags.m_bestNodeCost = 3.40282e38;
      flags.m_maxPathCost = 3.40282e38;
      flags.m_dummyNode.m_gCost = 3.40282e38;
      flags.m_dummyNode.m_hCost = 3.40282e38;
      flags.m_dummyNode.m_index = -1;
      flags.m_dummyNode.m_flags.m_storage = 0;
      hkaiHashSearchState::setStorage(&flags, array, size);
      flags.m_heuristicWeight = 0.0;
      NodeState = hkaiHashSearchState::getNodeState(&flags, v12);
      NodeState->m_gCost = 0.0;
      v17 = NodeState;
      v18 = hkaiGraphMultiDistanceHeuristic<hkaiNavMeshFaceGraph>::getHeuristic(&heuristic, v12);
      v17->m_hCost = v18;
      v17->m_flags.m_storage |= 5u;
      if ( v18 < flags.m_bestNodeCost )
      {
        flags.m_bestNodeCost = v18;
        flags.m_bestNode = v12;
      }
      graph->m_searchState = &flags;
      v19 = hkaiHierarchyUtils::CostAdaptor::estimatedCost(&pathCost, v12);
      m_heap = openset.m_heap;
      m_heapSize = openset.m_heapSize;
      v22 = openset.m_heapSize++;
      openset.m_heap[m_heapSize].m_idx = v12;
      m_heap[m_heapSize].m_cost.m_intCost = LODWORD(v19);
      v23 = openset.m_heap;
      m_idx = openset.m_heap[m_heapSize].m_idx;
      LODWORD(v25.m_floatCost) = openset.m_heap[m_heapSize].m_cost;
      for ( j = (unsigned int)((v22 - 1) / 2); v22 > 0; j = (unsigned int)(((int)j - 1) / 2) )
      {
        if ( v23[(int)j].m_cost.m_intCost <= v25.m_intCost )
          break;
        v27 = v22;
        v22 = j;
        v23[v27] = v23[(int)j];
        v23 = openset.m_heap;
      }
      v28 = v37 <= 0;
      v23[v22].m_idx = m_idx;
      openset.m_heap[v22].m_cost = v25;
      if ( !v28 )
      {
        while ( openset.m_heapSize && openset.m_heapSize < openset.m_maxSize && flags.m_nodeSize < flags.m_nodeCapacity )
          hkaiAstarSearchIteration_hkaiNavMeshFaceGraph_hkaiNavMeshFaceGraph_hkaiHeapOpenSet_hkaiHashSearchState_hkaiNullSearchParent_hkaiGraphMultiDistanceHeuristic_hkaiNavMeshFaceGraph__hkaiHierarchyUtils::CostAdaptor_hkaiNavMeshFaceGraph_(
            graph,
            graph,
            &openset,
            (hkaiHierarchyUtils::CostAdaptor *)&flags,
            &v42,
            &heuristic,
            &pathCost,
            graph);
      }
      v30 = 0;
      if ( v31 >= 0 )
        ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkaiHeapOpenSet::IndexCostPair *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerTempAllocator::s_alloc,
          v29,
          v31 & 0x3FFFFFFF,
          j);
      v29 = 0i64;
      v31 = 0x80000000;
      size = 0;
      if ( v35 >= 0 )
        ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, char *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerTempAllocator::s_alloc,
          array,
          v35 & 0x3FFFFFFF,
          j);
      ++v10;
      ++v11;
      array = 0i64;
      v35 = 0x80000000;
    }
    while ( v10 < nodesForRegion->m_size );
  }
}

// File Line: 415
// RVA: 0xBFD2A0
void __fastcall hkaiSimpleClusterGenerator::getInitialSeeding(
        hkaiNavMeshFaceGraph *graph,
        hkArrayBase<int> *nodesForRegion,
        hkArray<int,hkContainerHeapAllocator> *groupRepresentative,
        int numGroupsForRegion,
        hkPseudoRandomGenerator *prng)
{
  int m_capacityAndFlags; // eax
  __int64 m_size; // rax
  int *m_data; // rcx
  __int64 v11; // rdx
  char *v12; // r8
  int v13; // eax
  __int64 v14; // r8
  int *v15; // r11
  hkPseudoRandomGenerator *v16; // r10
  __int64 v17; // r9
  unsigned int v18; // eax
  signed int v19; // edx
  __int64 v20; // rax
  int v21; // edx
  int v22; // eax
  int v23; // eax
  int v24; // r9d
  hkResult result; // [rsp+58h] [rbp+20h] BYREF

  m_capacityAndFlags = groupRepresentative->m_capacityAndFlags;
  if ( (m_capacityAndFlags & 0x3FFFFFFF) < nodesForRegion->m_size )
  {
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        groupRepresentative->m_data,
        4 * m_capacityAndFlags);
    result.m_enum = 4 * nodesForRegion->m_size;
    groupRepresentative->m_data = (int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                           &hkContainerHeapAllocator::s_alloc,
                                           &result);
    groupRepresentative->m_capacityAndFlags = result.m_enum / 4;
  }
  m_size = nodesForRegion->m_size;
  m_data = groupRepresentative->m_data;
  groupRepresentative->m_size = m_size;
  v11 = m_size;
  if ( (int)m_size > 0 )
  {
    v12 = (char *)((char *)nodesForRegion->m_data - (char *)m_data);
    do
    {
      v13 = *(int *)((char *)m_data++ + (_QWORD)v12);
      *(m_data - 1) = v13;
      --v11;
    }
    while ( v11 );
  }
  v14 = groupRepresentative->m_size;
  v15 = groupRepresentative->m_data;
  if ( (int)v14 >= 2 )
  {
    v16 = prng;
    v17 = (__int64)&v15[v14 - 1];
    do
    {
      v18 = 1664525 * v16->m_current + 1013904223;
      v16->m_current = v18;
      if ( (int)v14 < 0x10000 )
        v18 >>= 11;
      v19 = v18 % (unsigned int)v14;
      LODWORD(v14) = v14 - 1;
      v17 -= 4i64;
      v20 = v19;
      v21 = v15[v19];
      v15[v20] = *(_DWORD *)(v17 + 4);
      *(_DWORD *)(v17 + 4) = v21;
    }
    while ( (int)v14 >= 2 );
  }
  v22 = groupRepresentative->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v22 < numGroupsForRegion )
  {
    v23 = 2 * v22;
    v24 = numGroupsForRegion;
    if ( numGroupsForRegion < v23 )
      v24 = v23;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, groupRepresentative, v24, 4);
  }
  groupRepresentative->m_size = numGroupsForRegion;
}

// File Line: 427
// RVA: 0xBFC2D0
__int64 __fastcall hkaiSimpleClusterGenerator::findClosestGroupRepForNode(
        hkaiNavMeshFaceGraph *graph,
        unsigned int ni,
        hkaiHierarchyUtils::SemiSparse2dArraySorted *costs,
        hkArray<int,hkContainerHeapAllocator> *groupRepresentatives,
        __int64 sortedReps)
{
  _QWORD *Value; // rax
  unsigned __int64 v9; // r10
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  float m_default; // xmm0_4
  int v13; // edi
  __int64 v14; // r8
  int v15; // edx
  __int64 v16; // rcx
  hkaiHierarchyUtils::RepGroupPair *v17; // rax
  unsigned int v18; // ebp
  _QWORD *v19; // r8
  _QWORD *v20; // rcx
  unsigned __int64 v21; // rax
  _QWORD *v22; // rcx
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
  _QWORD *v36; // rcx
  float minCost[4]; // [rsp+30h] [rbp-B8h] BYREF
  int faceIndex[4]; // [rsp+40h] [rbp-A8h] BYREF
  int v40[4]; // [rsp+50h] [rbp-98h] BYREF
  int minIndex; // [rsp+100h] [rbp+18h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = Value[1];
  v10 = Value;
  if ( v9 < Value[3] )
  {
    *(_QWORD *)v9 = "LtclosestRep";
    *(_QWORD *)(v9 + 16) = "StsparseSearch";
    v11 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v11;
    v10[1] = v9 + 24;
  }
  m_default = costs->m_default;
  v13 = 0;
  v14 = *(int *)(sortedReps + 8);
  minIndex = -1;
  minCost[0] = m_default;
  v15 = 0;
  v16 = 0i64;
  if ( v14 <= 0 )
  {
LABEL_7:
    hkaiHierarchyUtils::SemiSparse2dArraySorted::findMinValFromSet(
      costs,
      ni,
      (hkArrayBase<hkaiHierarchyUtils::RepGroupPair> *)sortedReps,
      &minIndex,
      minCost);
    v18 = minIndex;
    if ( minIndex == -1 )
    {
      v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v20 = (_QWORD *)v19[1];
      if ( (unsigned __int64)v20 < v19[3] )
      {
        *v20 = "StEuclidean";
        v21 = __rdtsc();
        v22 = v20 + 2;
        *((_DWORD *)v22 - 2) = v21;
        v19[1] = v22;
      }
      if ( groupRepresentatives->m_size > 0 )
      {
        v23 = minCost[0];
        v24 = 0i64;
        sortedReps = 48i64 * (ni >> 22);
        do
        {
          v25 = groupRepresentatives->m_data[v24];
          hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
            (hkaiNavMeshUtils *)graph->m_collection->m_instances.m_data[v25 >> 22].m_instancePtr,
            (hkaiNavMeshInstance *)(v25 & 0x3FFFFF),
            (__m128 *)faceIndex,
            (hkVector4f *)(6i64 * (v25 >> 22)));
          hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
            (hkaiNavMeshUtils *)graph->m_collection->m_instances.m_data[(unsigned __int64)sortedReps / 0x30].m_instancePtr,
            (hkaiNavMeshInstance *)(ni & 0x3FFFFF),
            (__m128 *)v40,
            v26);
          v27 = _mm_sub_ps(*(__m128 *)faceIndex, *(__m128 *)v40);
          v28 = _mm_mul_ps(v27, v27);
          v29 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                  _mm_shuffle_ps(v28, v28, 170));
          v30 = _mm_rsqrt_ps(v29);
          v31 = _mm_andnot_ps(
                  _mm_cmple_ps(v29, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v30), v30)),
                      _mm_mul_ps(*(__m128 *)_xmm, v30)),
                    v29)).m128_f32[0];
          hkaiHierarchyUtils::SemiSparse2dArraySorted::set(costs, v25, ni, v31);
          if ( v31 < v23 )
          {
            v23 = v31;
            v18 = v13;
          }
          ++v13;
          ++v24;
        }
        while ( v13 < groupRepresentatives->m_size );
      }
    }
  }
  else
  {
    v17 = *(hkaiHierarchyUtils::RepGroupPair **)sortedReps;
    while ( v17->m_representative != ni )
    {
      ++v16;
      ++v15;
      ++v17;
      if ( v16 >= v14 )
        goto LABEL_7;
    }
    v18 = *(_DWORD *)(*(_QWORD *)sortedReps + 8i64 * v15 + 4);
  }
  v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v33 = (_QWORD *)v32[1];
  v34 = v32;
  if ( (unsigned __int64)v33 < v32[3] )
  {
    *v33 = "lt";
    v35 = __rdtsc();
    v36 = v33 + 2;
    *((_DWORD *)v36 - 2) = v35;
    v34[1] = v36;
  }
  return v18;
}

// File Line: 477
// RVA: 0xBFD920
__int64 __fastcall hkaiSimpleClusterGenerator::updateGroupReps(
        hkaiNavMeshFaceGraph *graph,
        hkArrayBase<int> *nodes,
        hkArray<int,hkContainerHeapAllocator> *groupRepresentatives,
        hkVector4f *groupFromNode)
{
  __int64 m_size; // rbx
  __int64 v5; // rsi
  int v6; // r14d
  hkArray<int,hkContainerHeapAllocator> *v8; // r15
  int v9; // edi
  __int64 v10; // rcx
  _DWORD *v11; // rdi
  int v12; // r9d
  __int64 v13; // rcx
  __int64 v14; // rdx
  __int64 v15; // r12
  __int64 v16; // r14
  __int64 v17; // rbx
  __int64 v18; // rsi
  __int64 v19; // rdi
  __int64 v20; // rdx
  __m128 v21; // xmm2
  int v22; // ebx
  int v23; // edx
  _DWORD *v24; // rdi
  __int64 v25; // rcx
  int v26; // eax
  int v27; // r13d
  __int64 v28; // r8
  __int64 v29; // rdx
  __int64 v30; // rcx
  char *v31; // rdi
  int v32; // eax
  __int64 v33; // rbx
  _QWORD *v34; // r13
  __int64 v35; // rcx
  __int64 v36; // r14
  __m128 v37; // xmm6
  __m128 v38; // xmm6
  __m128 v39; // xmm6
  __m128 v40; // xmm4
  __m128 v41; // xmm3
  float v42; // xmm5_4
  __int64 v43; // r9
  __int64 v44; // rdx
  _DWORD *v45; // rcx
  unsigned int v46; // ebx
  int v48; // [rsp+18h] [rbp-59h]
  int v49; // [rsp+18h] [rbp-59h]
  int sizeElem[2]; // [rsp+20h] [rbp-51h] BYREF
  int v51; // [rsp+28h] [rbp-49h]
  int v52; // [rsp+2Ch] [rbp-45h]
  __int64 v53; // [rsp+30h] [rbp-41h] BYREF
  int v54; // [rsp+38h] [rbp-39h]
  int v55; // [rsp+3Ch] [rbp-35h]
  __int64 array; // [rsp+40h] [rbp-31h] BYREF
  int v57; // [rsp+48h] [rbp-29h]
  int v58; // [rsp+4Ch] [rbp-25h]
  hkResult result[2]; // [rsp+50h] [rbp-21h] BYREF
  int faceIndex[4]; // [rsp+58h] [rbp-19h] BYREF
  __m128 v61[2]; // [rsp+68h] [rbp-9h] BYREF
  __int64 v62; // [rsp+D8h] [rbp+67h]
  __int64 vars0; // [rsp+E0h] [rbp+6Fh]
  hkArray<int,hkContainerHeapAllocator> *retaddr; // [rsp+E8h] [rbp+77h] BYREF

  m_size = nodes->m_size;
  v5 = 0i64;
  v6 = groupRepresentatives->m_size;
  v8 = groupRepresentatives;
  array = 0i64;
  v9 = 0;
  v57 = 0;
  v58 = 0x80000000;
  *(_QWORD *)sizeElem = 0i64;
  v51 = 0;
  v52 = 0x80000000;
  if ( v6 > 0 )
  {
    hkArrayUtil::_reserve(result, &hkContainerHeapAllocator::s_alloc, &array, v6, 4);
    v9 = v57;
  }
  v10 = v6 - v9;
  if ( v6 - v9 > 0 )
  {
    v11 = (_DWORD *)(array + 4i64 * v9);
    while ( v10 )
    {
      *v11++ = 0;
      --v10;
    }
  }
  v57 = v6;
  if ( (v52 & 0x3FFFFFFF) < v6 )
  {
    v12 = v6;
    if ( v6 < 2 * (v52 & 0x3FFFFFFF) )
      v12 = 2 * (v52 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(result, &hkContainerHeapAllocator::s_alloc, sizeElem, v12, 16);
  }
  v13 = v6 - v51;
  v14 = *(_QWORD *)sizeElem + 16i64 * v51;
  if ( v6 - v51 > 0 )
  {
    do
    {
      v14 += 16i64;
      *(hkVector4f *)(v14 - 16) = (hkVector4f)aabbOut.m_quad;
      --v13;
    }
    while ( v13 );
  }
  v51 = v6;
  v15 = m_size;
  if ( (int)m_size > 0 )
  {
    v16 = v62;
    do
    {
      v17 = *((int *)&graph->m_collection->vfptr + v5);
      hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
        *(hkaiNavMeshUtils **)(*(_QWORD *)(*(_QWORD *)v16 + 32i64) + 48i64 * ((unsigned int)nodes->m_data[v5] >> 22)),
        (hkaiNavMeshInstance *)(nodes->m_data[v5] & 0x3FFFFF),
        (__m128 *)faceIndex,
        groupFromNode);
      ++v5;
      *(__m128 *)(*(_QWORD *)sizeElem + 16 * v17) = _mm_add_ps(
                                                      *(__m128 *)(*(_QWORD *)sizeElem + 16 * v17),
                                                      *(__m128 *)faceIndex);
      ++*(_DWORD *)(array + 4 * v17);
    }
    while ( v5 < v15 );
    v6 = v48;
    v8 = retaddr;
  }
  v18 = v6;
  v19 = 0i64;
  *(_QWORD *)faceIndex = v6;
  if ( v6 > 0 )
  {
    v20 = 0i64;
    do
    {
      v21 = (__m128)(unsigned int)FLOAT_1_0;
      ++v19;
      v20 += 16i64;
      v21.m128_f32[0] = 1.0 / (float)*(int *)(array + 4 * v19 - 4);
      *(__m128 *)(v20 + *(_QWORD *)sizeElem - 16) = _mm_mul_ps(
                                                      _mm_shuffle_ps(v21, v21, 0),
                                                      *(__m128 *)(v20 + *(_QWORD *)sizeElem - 16));
    }
    while ( v19 < v6 );
  }
  v22 = v8->m_size;
  v23 = 0;
  v53 = 0i64;
  v54 = 0;
  v55 = 0x80000000;
  if ( v22 > 0 )
  {
    hkArrayUtil::_reserve((hkResult *)&retaddr, &hkContainerTempAllocator::s_alloc, &v53, v22, 4);
    v23 = v54;
  }
  v24 = (_DWORD *)(v53 + 4i64 * v23);
  v25 = v22 - v23;
  if ( v22 - v23 > 0 )
  {
    while ( v25 )
    {
      *v24++ = 2139095022;
      --v25;
    }
  }
  v26 = v8->m_size;
  v27 = 0x80000000;
  v54 = v22;
  v28 = 0i64;
  *(_QWORD *)&result[0].m_enum = 0i64;
  v49 = 0x80000000;
  if ( v26 > 0 )
  {
    LODWORD(retaddr) = 4 * v26;
    v28 = ((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, hkArray<int,hkContainerHeapAllocator> **, _QWORD))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
            &hkContainerTempAllocator::s_alloc,
            &retaddr,
            0i64);
    *(_QWORD *)&result[0].m_enum = v28;
    v27 = (int)retaddr / 4;
    v49 = (int)retaddr / 4;
  }
  v29 = v8->m_size;
  if ( v29 > 0 )
  {
    v30 = v28;
    v31 = (char *)v8->m_data - v28;
    do
    {
      v32 = *(_DWORD *)&v31[v30];
      v30 += 4i64;
      *(_DWORD *)(v30 - 4) = v32;
      --v29;
    }
    while ( v29 );
  }
  v33 = 0i64;
  if ( v15 > 0 )
  {
    v34 = (_QWORD *)vars0;
    do
    {
      v35 = *((int *)&graph->m_collection->vfptr + v33);
      if ( (_DWORD)v35 != -1 )
      {
        v36 = *((int *)&graph->m_collection->vfptr + v33);
        v37 = *(__m128 *)(*(_QWORD *)sizeElem + 16 * v35);
        LODWORD(vars0) = *(_DWORD *)(*v34 + 4 * v33);
        hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
          *(hkaiNavMeshUtils **)(*(_QWORD *)(*(_QWORD *)v62 + 32i64) + 48i64 * ((unsigned int)vars0 >> 22)),
          (hkaiNavMeshInstance *)(vars0 & 0x3FFFFF),
          v61,
          groupFromNode);
        v38 = _mm_sub_ps(v37, v61[0]);
        v39 = _mm_mul_ps(v38, v38);
        v40 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                _mm_shuffle_ps(v39, v39, 170));
        v41 = _mm_rsqrt_ps(v40);
        v42 = _mm_andnot_ps(
                _mm_cmple_ps(v40, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v41, v40), v41)),
                    _mm_mul_ps(*(__m128 *)_xmm, v41)),
                  v40)).m128_f32[0];
        if ( v42 < *(float *)(v53 + 4 * v36) )
        {
          v8->m_data[v36] = vars0;
          *(float *)(v53 + 4 * v36) = v42;
        }
      }
      ++v33;
    }
    while ( v33 < v15 );
    v18 = *(_QWORD *)faceIndex;
    v27 = v49;
  }
  v43 = *(_QWORD *)&result[0].m_enum;
  v44 = 0i64;
  if ( v18 <= 0 )
  {
LABEL_41:
    v46 = 0;
  }
  else
  {
    v45 = *(_DWORD **)&result[0].m_enum;
    while ( *(int *)((char *)v8->m_data + (unsigned __int64)v45 - *(_QWORD *)&result[0].m_enum) == *v45 )
    {
      ++v44;
      ++v45;
      if ( v44 >= v18 )
        goto LABEL_41;
    }
    v46 = 1;
  }
  if ( v27 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      *(void **)&result[0].m_enum,
      4 * v27);
  v54 = 0;
  if ( v55 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v53,
      (unsigned int)(4 * v55),
      v43);
  v53 = 0i64;
  v55 = 0x80000000;
  v51 = 0;
  if ( v52 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _QWORD, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      *(_QWORD *)sizeElem,
      (unsigned int)(16 * v52),
      v43);
  *(_QWORD *)sizeElem = 0i64;
  v57 = 0;
  v52 = 0x80000000;
  if ( v58 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      array,
      (unsigned int)(4 * v58),
      v43);
  return v46;
}

// File Line: 544
// RVA: 0xBFC610
void __fastcall hkaiSimpleClusterGenerator::generateClusters(
        hkaiNavMeshFaceGraph *graph,
        int targetNumGroups,
        int blockSize,
        bool ensureClusterPerNode,
        hkArrayBase<unsigned int> *groupFromNode,
        hkArray<int,hkContainerHeapAllocator> *groupRepresentatives,
        int randSeed)
{
  int v7; // r15d
  hkaiNavMeshFaceGraph *v8; // r13
  hkaiNavMeshInstance *m_instancePtr; // rbx
  int v10; // eax
  int v11; // r14d
  int v12; // eax
  int v13; // r9d
  int v14; // eax
  int v15; // eax
  int v16; // r9d
  __int64 v17; // rdx
  _DWORD *v18; // rdi
  __int64 v19; // rcx
  int v20; // esi
  _QWORD *Value; // rdi
  unsigned __int64 v22; // rcx
  unsigned __int64 v23; // rax
  int v24; // edi
  __int64 v25; // r12
  int v26; // r9d
  int *v27; // rdx
  int *v28; // rdi
  __int64 v29; // rcx
  __int64 v30; // rdi
  int v31; // ecx
  int v32; // r8d
  int *v33; // rax
  __int64 v34; // rdi
  unsigned int v35; // eax
  unsigned int v36; // esi
  _QWORD *v37; // rdi
  _QWORD *v38; // rcx
  unsigned __int64 v39; // rax
  _QWORD *v40; // rcx
  __int64 v41; // r15
  int v42; // ebx
  __int64 v43; // rcx
  int v44; // edx
  __int64 v45; // r12
  __m128i v46; // xmm1
  int v47; // esi
  int v48; // eax
  _QWORD *v49; // rax
  unsigned __int64 v50; // rcx
  _QWORD *v51; // rdi
  unsigned __int64 v52; // rax
  int m_size; // ecx
  int v54; // edi
  __int64 i; // rdx
  _QWORD *v56; // rdi
  _QWORD *v57; // rcx
  unsigned __int64 v58; // rax
  _QWORD *v59; // rcx
  _QWORD *v60; // rdi
  _QWORD *v61; // rcx
  unsigned __int64 v62; // rax
  _QWORD *v63; // rcx
  int *m_data; // rdx
  int v65; // ecx
  int *v66; // rdi
  int v67; // eax
  __int64 v68; // rcx
  _QWORD *v69; // rdi
  _QWORD *v70; // rcx
  unsigned __int64 v71; // rax
  _QWORD *v72; // rcx
  int v73; // r15d
  int v74; // r8d
  int v75; // edi
  __int64 v76; // rdx
  __int64 v77; // r8
  _QWORD *v78; // rdi
  _QWORD *v79; // rcx
  unsigned __int64 v80; // rax
  _QWORD *v81; // rcx
  __int64 v82; // rdi
  int ClosestGroupRepForNode; // eax
  _QWORD *v84; // rdi
  _QWORD *v85; // rcx
  unsigned __int64 v86; // rax
  _QWORD *v87; // rcx
  _QWORD *v88; // rdi
  _QWORD *v89; // rcx
  unsigned __int64 v90; // rax
  _QWORD *v91; // rcx
  unsigned int updated; // ebx
  _QWORD *v93; // rax
  _QWORD *v94; // rcx
  _QWORD *v95; // rdi
  unsigned __int64 v96; // rax
  _QWORD *v97; // rcx
  _QWORD *v98; // rdi
  _QWORD *v99; // rcx
  unsigned __int64 v100; // rax
  _QWORD *v101; // rcx
  int v102; // ebx
  __int64 v103; // rdi
  int v104; // eax
  __int64 v105; // rbx
  int *v106; // rdi
  int v107; // r8d
  _QWORD *v108; // rax
  _QWORD *v109; // rcx
  _QWORD *v110; // rdi
  unsigned __int64 v111; // rax
  _QWORD *v112; // rcx
  _QWORD *v113; // rdi
  _QWORD *v114; // rcx
  unsigned __int64 v115; // rax
  _QWORD *v116; // rcx
  hkResult result; // [rsp+30h] [rbp-C8h] BYREF
  hkaiHierarchyUtils::RepGroupPair *pArr; // [rsp+38h] [rbp-C0h] BYREF
  int v119; // [rsp+40h] [rbp-B8h]
  int v120; // [rsp+44h] [rbp-B4h]
  hkArrayBase<int> nodesForRegion; // [rsp+48h] [rbp-B0h] BYREF
  int v122; // [rsp+58h] [rbp-A0h]
  int *v123; // [rsp+60h] [rbp-98h] BYREF
  int v124; // [rsp+68h] [rbp-90h]
  int v125; // [rsp+6Ch] [rbp-8Ch]
  hkArray<int,hkContainerHeapAllocator> v126; // [rsp+70h] [rbp-88h] BYREF
  int v127; // [rsp+80h] [rbp-78h]
  int v128; // [rsp+84h] [rbp-74h]
  hkArrayBase<int> regions; // [rsp+88h] [rbp-70h] BYREF
  hkResult v130; // [rsp+98h] [rbp-60h] BYREF
  __int64 v131; // [rsp+A0h] [rbp-58h]
  hkResult v132; // [rsp+A8h] [rbp-50h] BYREF
  __int64 v133; // [rsp+B0h] [rbp-48h]
  hkaiHierarchyUtils::SemiSparse2dArraySorted costs; // [rsp+B8h] [rbp-40h] BYREF
  hkPseudoRandomGenerator prng; // [rsp+D8h] [rbp-20h] BYREF
  __int64 v136; // [rsp+E0h] [rbp-18h]
  hkaiNavMeshFaceGraph *retaddr; // [rsp+148h] [rbp+50h]
  int v138; // [rsp+150h] [rbp+58h]
  int v139; // [rsp+158h] [rbp+60h]
  char v140; // [rsp+160h] [rbp+68h]
  int *array; // [rsp+168h] [rbp+70h]

  LOBYTE(array) = ensureClusterPerNode;
  v140 = blockSize;
  v139 = targetNumGroups;
  v138 = (int)graph;
  v7 = blockSize;
  v8 = graph;
  m_instancePtr = graph->m_collection->m_instances.m_data->m_instancePtr;
  v10 = groupFromNode->m_capacityAndFlags & 0x3FFFFFFF;
  v11 = m_instancePtr->m_numOriginalFaces + m_instancePtr->m_ownedFaces.m_size;
  if ( v10 < targetNumGroups )
  {
    v12 = 2 * v10;
    v13 = targetNumGroups;
    if ( targetNumGroups < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, groupFromNode, v13, 4);
  }
  v14 = array[3] & 0x3FFFFFFF;
  if ( v14 < v11 )
  {
    v15 = 2 * v14;
    v16 = v11;
    if ( v11 < v15 )
      v16 = v15;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, array, v16, 4);
  }
  v17 = array[2];
  v18 = (_DWORD *)(*(_QWORD *)array + 4 * v17);
  v19 = v11 - (int)v17;
  if ( v19 > 0 )
  {
    while ( v19 )
    {
      *v18++ = -1;
      --v19;
    }
  }
  array[2] = v11;
  v20 = 0;
  v123 = 0i64;
  v124 = 0;
  v125 = 0x80000000;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = Value[1];
  if ( v22 < Value[3] )
  {
    *(_QWORD *)v22 = "LtgenerateClusters";
    *(_QWORD *)(v22 + 16) = "StregionCount";
    v23 = __rdtsc();
    *(_DWORD *)(v22 + 8) = v23;
    Value[1] = v22 + 24;
  }
  regions.m_data = 0i64;
  regions.m_size = 0;
  regions.m_capacityAndFlags = 0x80000000;
  v24 = m_instancePtr->m_numOriginalFaces + m_instancePtr->m_ownedFaces.m_size;
  if ( v24 > 0 )
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      &regions,
      m_instancePtr->m_numOriginalFaces + m_instancePtr->m_ownedFaces.m_size,
      4);
  regions.m_size = v24;
  v25 = (int)hkaiNavMeshUtils::computeRegions(m_instancePtr, 1, &regions, 0i64);
  prng.m_seed = (unsigned int)groupRepresentatives;
  if ( v140 )
    v7 = -1;
  prng.m_current = (unsigned int)groupRepresentatives;
  if ( (v125 & 0x3FFFFFFF) < (int)v25 )
  {
    v26 = v25;
    if ( (int)v25 < 2 * (v125 & 0x3FFFFFFF) )
      v26 = 2 * (v125 & 0x3FFFFFFF);
    hkArrayUtil::_reserve((hkResult *)&groupRepresentatives, &hkContainerHeapAllocator::s_alloc, &v123, v26, 4);
  }
  v27 = v123;
  v28 = &v123[v124];
  v29 = (int)v25 - v124;
  if ( (int)v25 - v124 > 0 )
  {
    while ( v29 )
    {
      *v28++ = 0;
      --v29;
    }
    v27 = v123;
  }
  v30 = 0i64;
  v31 = v25;
  v124 = v25;
  v32 = 0;
  if ( m_instancePtr->m_numOriginalFaces + m_instancePtr->m_ownedFaces.m_size > 0 )
  {
    do
    {
      ++v32;
      ++v27[regions.m_data[v30++]];
      v27 = v123;
    }
    while ( v32 < m_instancePtr->m_numOriginalFaces + m_instancePtr->m_ownedFaces.m_size );
    v31 = v124;
  }
  if ( v31 > 0 )
  {
    v33 = v27;
    v34 = (unsigned int)v31;
    do
    {
      if ( *v33 < v7 )
        v20 += *v33;
      ++v33;
      --v34;
    }
    while ( v34 );
  }
  v35 = v11 - v20;
  LODWORD(groupRepresentatives) = v11 - v20;
  if ( v11 == v20 )
  {
    v35 = *v27;
    v139 = *v27;
    LODWORD(groupRepresentatives) = *v27;
  }
  v36 = v35;
  v37 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v38 = (_QWORD *)v37[1];
  if ( (unsigned __int64)v38 < v37[3] )
  {
    *v38 = "Stregions";
    v39 = __rdtsc();
    v40 = v38 + 2;
    *((_DWORD *)v40 - 2) = v39;
    v37[1] = v40;
  }
  v41 = v11;
  v136 = v25;
  v42 = 0;
  v43 = 0i64;
  v133 = v11;
  v122 = 0;
  v131 = 0i64;
  if ( (int)v25 > 0 )
  {
    v44 = v139;
    do
    {
      v45 = v123[v43];
      if ( (v140 || (int)v45 >= v44) && v36 && v138 )
      {
        v46 = _mm_cvtsi32_si128(v36);
        v47 = 1;
        v48 = (int)(float)((float)((float)((float)(int)v45 * (float)v138) / _mm_cvtepi32_ps(v46).m128_f32[0]) + 0.5);
        if ( v48 > 1 )
          v47 = v48;
        if ( v47 > (int)v45 )
          v47 = v123[v43];
        v49 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v50 = v49[1];
        v51 = v49;
        if ( v50 < v49[3] )
        {
          *(_QWORD *)v50 = "Ltregion";
          *(_QWORD *)(v50 + 16) = "Stgather";
          v52 = __rdtsc();
          *(_DWORD *)(v50 + 8) = v52;
          v51[1] = v50 + 24;
        }
        nodesForRegion.m_capacityAndFlags = 0x80000000;
        m_size = 0;
        nodesForRegion.m_data = 0i64;
        nodesForRegion.m_size = 0;
        if ( (int)v45 <= 0 )
        {
          v130.m_enum = HK_SUCCESS;
        }
        else
        {
          hkArrayUtil::_reserve(&v130, &hkContainerTempAllocator::s_alloc, &nodesForRegion, v45, 4);
          m_size = nodesForRegion.m_size;
        }
        v54 = 0;
        for ( i = 0i64; i < v41; ++v54 )
        {
          if ( regions.m_data[i] == v42 )
          {
            nodesForRegion.m_data[m_size] = v54;
            m_size = ++nodesForRegion.m_size;
          }
          ++i;
        }
        v56 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v57 = (_QWORD *)v56[1];
        if ( (unsigned __int64)v57 < v56[3] )
        {
          *v57 = "StnearestNeighbors";
          v58 = __rdtsc();
          v59 = v57 + 2;
          *((_DWORD *)v59 - 2) = v58;
          v56[1] = v59;
        }
        costs.m_costs.m_data = 0i64;
        costs.m_costs.m_size = 0;
        costs.m_costs.m_capacityAndFlags = 0x80000000;
        hkaiSimpleClusterGenerator::getNearestNeighborCosts(v8, &nodesForRegion, &costs, 6 * v139);
        v60 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v61 = (_QWORD *)v60[1];
        if ( (unsigned __int64)v61 < v60[3] )
        {
          *v61 = "StinitSeeding";
          v62 = __rdtsc();
          v63 = v61 + 2;
          *((_DWORD *)v63 - 2) = v62;
          v60[1] = v63;
        }
        *(_QWORD *)&v126.m_size = 0i64;
        v127 = 0;
        v128 = 0x80000000;
        hkaiSimpleClusterGenerator::getInitialSeeding(
          v8,
          &nodesForRegion,
          (hkArray<int,hkContainerHeapAllocator> *)&v126.m_size,
          v47,
          &prng);
        m_data = 0i64;
        v126.m_data = 0i64;
        v65 = 0;
        v126.m_size = 0;
        v126.m_capacityAndFlags = 0x80000000;
        if ( (int)v45 <= 0 )
        {
          v132.m_enum = HK_SUCCESS;
        }
        else
        {
          hkArrayUtil::_reserve(&v132, &hkContainerHeapAllocator::s_alloc, &v126, v45, 4);
          v65 = v126.m_size;
          m_data = v126.m_data;
        }
        v66 = &m_data[v65];
        v67 = v45 - v65;
        v68 = (int)v45 - v65;
        if ( v67 > 0 )
        {
          while ( v68 )
          {
            *v66++ = -1;
            --v68;
          }
        }
        v126.m_size = v45;
        v69 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v70 = (_QWORD *)v69[1];
        if ( (unsigned __int64)v70 < v69[3] )
        {
          *v70 = "StkMeans";
          v71 = __rdtsc();
          v72 = v70 + 2;
          *((_DWORD *)v72 - 2) = v71;
          v69[1] = v72;
        }
        v73 = 0;
        while ( 1 )
        {
          pArr = 0i64;
          v119 = 0;
          v120 = 0x80000000;
          if ( v47 <= 0 )
            result.m_enum = HK_SUCCESS;
          else
            hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &pArr, v47, 8);
          v74 = v47;
          v119 = v47;
          v75 = 0;
          if ( v47 > 0 )
          {
            v76 = 0i64;
            v77 = 0i64;
            do
            {
              v77 += 4i64;
              pArr[v76++].m_representative = *(_DWORD *)(*(_QWORD *)&v126.m_size + v77 - 4);
              pArr[v76 - 1].m_group = v75++;
            }
            while ( v75 < v47 );
            v74 = v119;
          }
          if ( v74 > 1 )
            hkAlgorithm::quickSortRecursive<hkaiHierarchyUtils::RepGroupPair,hkAlgorithm::less<hkaiHierarchyUtils::RepGroupPair>>(
              pArr,
              0,
              v74 - 1,
              0);
          v78 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v79 = (_QWORD *)v78[1];
          if ( (unsigned __int64)v79 < v78[3] )
          {
            *v79 = "TtfindClosestRep";
            v80 = __rdtsc();
            v81 = v79 + 2;
            *((_DWORD *)v81 - 2) = v80;
            v78[1] = v81;
          }
          v82 = 0i64;
          if ( (int)v45 > 0 )
          {
            do
            {
              ClosestGroupRepForNode = hkaiSimpleClusterGenerator::findClosestGroupRepForNode(
                                         v8,
                                         nodesForRegion.m_data[v82++],
                                         &costs,
                                         (hkArray<int,hkContainerHeapAllocator> *)&v126.m_size,
                                         (__int64)&pArr);
              v126.m_data[v82 - 1] = ClosestGroupRepForNode;
            }
            while ( v82 < v45 );
          }
          v84 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v85 = (_QWORD *)v84[1];
          if ( (unsigned __int64)v85 < v84[3] )
          {
            *v85 = "Et";
            v86 = __rdtsc();
            v87 = v85 + 2;
            *((_DWORD *)v87 - 2) = v86;
            v84[1] = v87;
          }
          v88 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v89 = (_QWORD *)v88[1];
          if ( (unsigned __int64)v89 < v88[3] )
          {
            *v89 = "TtupdateRep";
            v90 = __rdtsc();
            v91 = v89 + 2;
            *((_DWORD *)v91 - 2) = v90;
            v88[1] = v91;
          }
          updated = hkaiSimpleClusterGenerator::updateGroupReps(
                      v8,
                      &nodesForRegion,
                      (hkArray<int,hkContainerHeapAllocator> *)&v126.m_size,
                      &v126);
          v93 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v94 = (_QWORD *)v93[1];
          v95 = v93;
          if ( (unsigned __int64)v94 < v93[3] )
          {
            *v94 = "Et";
            v96 = __rdtsc();
            v97 = v94 + 2;
            *((_DWORD *)v97 - 2) = v96;
            v95[1] = v97;
          }
          if ( !updated )
            break;
          v119 = 0;
          if ( v120 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, pArr, 8 * v120);
          ++v73;
          pArr = 0i64;
          v120 = 0x80000000;
          if ( v73 >= 10 )
            goto LABEL_97;
        }
        v119 = 0;
        if ( v120 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, pArr, 8 * v120);
        pArr = 0i64;
        v120 = 0x80000000;
LABEL_97:
        v98 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v99 = (_QWORD *)v98[1];
        if ( (unsigned __int64)v99 < v98[3] )
        {
          *v99 = "StupdateGroupFromNode";
          v100 = __rdtsc();
          v101 = v99 + 2;
          *((_DWORD *)v101 - 2) = v100;
          v98[1] = v101;
        }
        v102 = groupFromNode->m_size;
        hkArrayBase<unsigned int>::_append(
          groupFromNode,
          &hkContainerHeapAllocator::s_alloc,
          *(char **)&v126.m_size,
          v127);
        v103 = 0i64;
        if ( (int)v45 > 0 )
        {
          do
          {
            ++v103;
            *(_DWORD *)(*(_QWORD *)array + 4i64 * nodesForRegion.m_data[v103 - 1]) = v102 + v126.m_data[v103 - 1];
          }
          while ( v103 < v45 );
          v8 = retaddr;
        }
        v104 = 1;
        v126.m_size = 0;
        if ( v138 - v47 > 1 )
          v104 = v138 - v47;
        v36 = (_DWORD)groupRepresentatives - v45;
        LODWORD(groupRepresentatives) = (_DWORD)groupRepresentatives - v45;
        v138 = v104;
        if ( v126.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v126.m_data,
            4 * v126.m_capacityAndFlags);
        v126.m_data = 0i64;
        v126.m_capacityAndFlags = 0x80000000;
        v127 = 0;
        if ( v128 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)&v126.m_size,
            4 * v128);
        *(_QWORD *)&v126.m_size = 0i64;
        v128 = 0x80000000;
        v105 = costs.m_costs.m_size - 1;
        if ( costs.m_costs.m_size - 1 >= 0 )
        {
          v106 = &costs.m_costs.m_data->m_capacityAndFlags + 4 * costs.m_costs.m_size - 4;
          do
          {
            v107 = *v106;
            *(v106 - 1) = 0;
            if ( v107 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                *(void **)(v106 - 3),
                8 * v107);
            *(_QWORD *)(v106 - 3) = 0i64;
            *v106 = 0x80000000;
            v106 -= 4;
            --v105;
          }
          while ( v105 >= 0 );
        }
        costs.m_costs.m_size = 0;
        if ( costs.m_costs.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            costs.m_costs.m_data,
            16 * costs.m_costs.m_capacityAndFlags);
        costs.m_costs.m_data = 0i64;
        costs.m_costs.m_capacityAndFlags = 0x80000000;
        nodesForRegion.m_size = 0;
        if ( nodesForRegion.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            nodesForRegion.m_data,
            4 * nodesForRegion.m_capacityAndFlags);
        nodesForRegion.m_data = 0i64;
        nodesForRegion.m_capacityAndFlags = 0x80000000;
        v108 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v42 = v122;
        v41 = v133;
        v109 = (_QWORD *)v108[1];
        v110 = v108;
        if ( (unsigned __int64)v109 < v108[3] )
        {
          *v109 = "lt";
          v111 = __rdtsc();
          v112 = v109 + 2;
          *((_DWORD *)v112 - 2) = v111;
          v110[1] = v112;
        }
        v43 = v131;
        v44 = v139;
      }
      ++v43;
      v122 = ++v42;
      v131 = v43;
    }
    while ( v43 < v136 );
  }
  regions.m_size = 0;
  if ( regions.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      regions.m_data,
      4 * regions.m_capacityAndFlags);
  regions.m_data = 0i64;
  regions.m_capacityAndFlags = 0x80000000;
  v113 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v114 = (_QWORD *)v113[1];
  if ( (unsigned __int64)v114 < v113[3] )
  {
    *v114 = "lt";
    v115 = __rdtsc();
    v116 = v114 + 2;
    *((_DWORD *)v116 - 2) = v115;
    v113[1] = v116;
  }
  v124 = 0;
  if ( v125 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v123, 4 * v125);
}

// File Line: 713
// RVA: 0xBFA020
void __fastcall hkaiHierarchyUtils::buildAbstractGraphFromClusterInfo(
        hkaiNavMeshFaceGraph *graph,
        hkaiDirectedGraphExplicitCost *graphOut,
        hkArray<int,hkContainerHeapAllocator> *groupFromNode,
        hkArray<int,hkContainerHeapAllocator> *groupRepresentative,
        hkArray<hkVector4f,hkContainerHeapAllocator> *centroids,
        hkaiAgentTraversalInfo *searchParams,
        hkaiAgentTraversalInfo *agentInfo)
{
  __int64 v7; // r13
  int v10; // ebx
  int i; // r14d
  unsigned int v12; // edx
  int index; // r14d
  __int64 v14; // rbx
  hkaiNavMeshInstance *m_instancePtr; // rcx
  int m_numEdges; // r12d
  hkLifoAllocator *Value; // rax
  char *m_cur; // rsi
  int v19; // edx
  char *v20; // rcx
  signed int mExtension_high; // r12d
  hkaiStreamingCollection::InstanceInfo *m_data; // rcx
  hkaiNavMesh::Face *v23; // rax
  char *v24; // r8
  int v25; // edx
  __int64 v26; // r9
  int v27; // ebx
  int v28; // ecx
  __m128 m_quad; // xmm15
  unsigned int v30; // esi
  __int64 v31; // rax
  int v32; // esi
  hkaiNavMeshInstance *v33; // rbx
  hkaiNavMesh::Edge *v34; // rax
  unsigned int m_oppositeFace; // ecx
  unsigned int v36; // eax
  int v37; // r14d
  hkaiNavMesh::Edge *v38; // rax
  hkaiNavMesh::Edge *v39; // rax
  int m_numOriginalVertices; // edx
  __int64 m_a; // rcx
  __m128 *v42; // rcx
  __m128 v43; // xmm2
  __m128 v44; // xmm3
  __int64 m_b; // rax
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
  __m128 v59; // xmm1
  __m128 v60; // xmm6
  __m128 v61; // xmm6
  hkSimdFloat32 v62; // xmm3
  __int64 m_numGoals; // r9
  int v64; // ecx
  __int64 v65; // rax
  __m128 v66; // xmm14
  hkVector4f v67; // xmm5
  __m128 v68; // xmm6
  hkVector4f *m_endPoints; // rdx
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
  __m128 v85; // xmm4
  __m128 v86; // xmm1
  __m128 v87; // xmm6
  __m128 v88; // xmm2
  __m128 v89; // xmm1
  __m128 v90; // xmm0
  __m128 v91; // xmm2
  __m128 v92; // xmm2
  __m128 v93; // xmm0
  __m128 v94; // xmm3
  __m128 v95; // xmm8
  __m128 v96; // xmm0
  __m128 v97; // xmm2
  __m128 v98; // xmm2
  hkaiAstarEdgeFilter *m_edgeFilter; // r15
  int striding; // ecx
  __m128 v101; // xmm10
  hkaiNavMesh::Face *v102; // rax
  __int64 v103; // r11
  const int *v104; // r12
  hkaiNavMesh::Edge *v105; // rax
  int v106; // ecx
  __int64 v107; // rsi
  __int64 v108; // r14
  int v109; // ebx
  int Key; // eax
  float CostBetweenFaces; // xmm0_4
  signed int v112; // ebx
  hkLifoAllocator *v113; // rax
  int v114; // r8d
  int v115; // [rsp+40h] [rbp-B8h]
  char *v116; // [rsp+48h] [rbp-B0h]
  AMD_HD3D v117; // [rsp+50h] [rbp-A8h] BYREF
  hkaiDirectedGraphExplicitCostBuilder v118; // [rsp+70h] [rbp-88h] BYREF
  __int64 v119; // [rsp+A0h] [rbp-58h]
  __int64 v120[3]; // [rsp+A8h] [rbp-50h] BYREF
  char v121; // [rsp+C0h] [rbp-38h]
  __m128 v122; // [rsp+C8h] [rbp-30h]
  __m128 v123; // [rsp+D8h] [rbp-20h]
  __m128 v124; // [rsp+E8h] [rbp-10h]
  __m128 v125; // [rsp+F8h] [rbp+0h]
  __m128 v126; // [rsp+108h] [rbp+10h]
  int v127; // [rsp+118h] [rbp+20h] BYREF
  __int64 v128; // [rsp+120h] [rbp+28h]
  int v129; // [rsp+148h] [rbp+50h]
  hkaiNavMesh::Edge *v130; // [rsp+150h] [rbp+58h]
  const int *v131; // [rsp+158h] [rbp+60h]
  __m128 v132; // [rsp+168h] [rbp+70h]
  int v133; // [rsp+178h] [rbp+80h]
  hkaiNavMesh::Face *v134; // [rsp+180h] [rbp+88h]
  __int64 v135; // [rsp+188h] [rbp+90h]
  void *retaddr; // [rsp+288h] [rbp+190h]
  hkaiDirectedGraphExplicitCost *d; // [rsp+290h] [rbp+198h]

  v7 = 0i64;
  v118.vfptr = (hkaiGraphBuilderVtbl *)&hkaiDirectedGraphExplicitCostBuilder::`vftable;
  v118.m_positions.m_data = (hkVector4f *)0x8000000000000000i64;
  *(_QWORD *)&v118.m_positions.m_size = 0i64;
  v118.m_links.m_data = (hkaiDirectedGraphExplicitCostBuilder::Link *)0x8000000000000000i64;
  hkaiDirectedGraphExplicitCostBuilder::BuildOptions::BuildOptions((hkaiDirectedGraphExplicitCostBuilder::BuildOptions *)&v118.m_links.m_size);
  v10 = 0;
  for ( i = graph->m_collection->m_instances.m_data->m_instancePtr->m_numOriginalFaces
          + graph->m_collection->m_instances.m_data->m_instancePtr->m_ownedFaces.m_size;
        v10 < groupRepresentative->m_size;
        ++v10 )
  {
    hkaiDirectedGraphExplicitCostBuilder::addPosition(&v118, (hkVector4f *)&groupRepresentative->m_data[4 * v10]);
  }
  v12 = 0;
  *(_QWORD *)&v117.mEnableStereo = 0i64;
  v117.mHeight = -1;
  v117.mWidth = 0;
  LODWORD(retaddr) = 0;
  v117.mStereo = 0i64;
  *(_QWORD *)&v118.m_options.m_allowDuplicateEdges.m_bool = i;
  if ( i > 0 )
  {
    while ( 1 )
    {
      index = v12 & 0x3FFFFF;
      v14 = v12 >> 22;
      v115 = v12 & 0x3FFFFF;
      m_instancePtr = graph->m_collection->m_instances.m_data[v14].m_instancePtr;
      m_numEdges = hkaiNavMeshInstance_get_hkaiNavMesh::Face__10(
                     m_instancePtr->m_originalFaces,
                     m_instancePtr->m_numOriginalFaces,
                     &m_instancePtr->m_instancedFaces,
                     &m_instancePtr->m_ownedFaces,
                     &m_instancePtr->m_faceMap,
                     v12 & 0x3FFFFF)->m_numEdges;
      LODWORD(v117.mExtension) = m_numEdges;
      if ( m_numEdges )
      {
        Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        m_cur = (char *)Value->m_cur;
        v19 = (4 * m_numEdges + 127) & 0xFFFFFF80;
        v116 = m_cur;
        v20 = &m_cur[v19];
        if ( v19 > Value->m_slabSize || v20 > Value->m_end )
        {
          m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v19);
          v116 = m_cur;
        }
        else
        {
          Value->m_cur = v20;
        }
      }
      else
      {
        m_cur = 0i64;
        v116 = 0i64;
      }
      mExtension_high = m_numEdges | 0x80000000;
      m_data = graph->m_collection->m_instances.m_data;
      HIDWORD(v117.mExtension) = mExtension_high;
      v23 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__10(
              m_data[v14].m_instancePtr->m_originalFaces,
              m_data[v14].m_instancePtr->m_numOriginalFaces,
              &m_data[v14].m_instancePtr->m_instancedFaces,
              &m_data[v14].m_instancePtr->m_ownedFaces,
              &m_data[v14].m_instancePtr->m_faceMap,
              index);
      v24 = m_cur;
      v25 = 0;
      v26 = v23->m_numEdges;
      if ( (int)v26 > 0 )
      {
        v27 = (_DWORD)v14 << 22;
        do
        {
          v24 += 4;
          v28 = v25 + v23->m_startEdgeIndex;
          ++v25;
          *((_DWORD *)v24 - 1) = v27 | v28;
        }
        while ( v25 < (int)v26 );
      }
      v119 = v26;
      if ( (int)v26 > 0 )
        break;
LABEL_53:
      v112 = (4 * LODWORD(v117.mExtension) + 127) & 0xFFFFFF80;
      v113 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v114 = (v112 + 15) & 0xFFFFFFF0;
      if ( v112 > v113->m_slabSize || &m_cur[v114] != v113->m_cur || v113->m_firstNonLifoEnd == m_cur )
        hkLifoAllocator::slowBlockFree(v113, m_cur, v114);
      else
        v113->m_cur = m_cur;
      if ( mExtension_high >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, m_cur, 4 * mExtension_high);
      v7 = 0i64;
      v12 = (_DWORD)retaddr + 1;
      LODWORD(retaddr) = (_DWORD)retaddr + 1;
      if ( (__int64)++v117.mStereo >= *(__int64 *)&v118.m_options.m_allowDuplicateEdges.m_bool )
        goto LABEL_61;
    }
    m_quad = query.m_quad;
    while ( 1 )
    {
      v30 = *(_DWORD *)&m_cur[4 * v7];
      v31 = v30 >> 22;
      v32 = v30 & 0x3FFFFF;
      v33 = graph->m_collection->m_instances.m_data[v31].m_instancePtr;
      v34 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__10(
              v33->m_originalEdges,
              v33->m_numOriginalEdges,
              &v33->m_instancedEdges,
              &v33->m_ownedEdges,
              &v33->m_edgeMap,
              v32);
      m_oppositeFace = v34->m_oppositeFace;
      if ( (v34->m_flags.m_storage & 0x40) != 0 )
        v36 = m_oppositeFace & 0xFFC00000;
      else
        v36 = v33->m_runtimeId << 22;
      v37 = v36 | m_oppositeFace & 0x3FFFFF;
      if ( m_oppositeFace == -1 )
        v37 = -1;
      v38 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__10(
              v33->m_originalEdges,
              v33->m_numOriginalEdges,
              &v33->m_instancedEdges,
              &v33->m_ownedEdges,
              &v33->m_edgeMap,
              v32);
      if ( v38->m_oppositeEdge == -1 || (v38->m_flags.m_storage & 0x20) != 0 )
        goto LABEL_51;
      v39 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__10(
              v33->m_originalEdges,
              v33->m_numOriginalEdges,
              &v33->m_instancedEdges,
              &v33->m_ownedEdges,
              &v33->m_edgeMap,
              v32);
      m_numOriginalVertices = v33->m_numOriginalVertices;
      m_a = v39->m_a;
      v42 = (__m128 *)((int)m_a >= m_numOriginalVertices
                     ? &v33->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices]
                     : &v33->m_originalVertices[m_a]);
      v43 = v33->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
      v44 = v33->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
      m_b = v39->m_b;
      v46 = v33->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
      v47 = v33->m_referenceFrame.m_transform.m_translation.m_quad;
      v48 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v42, *v42, 0), v44),
                  _mm_mul_ps(_mm_shuffle_ps(*v42, *v42, 85), v43)),
                _mm_mul_ps(_mm_shuffle_ps(*v42, *v42, 170), v46)),
              v47);
      v49 = (__m128 *)((int)m_b >= m_numOriginalVertices
                     ? &v33->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices]
                     : &v33->m_originalVertices[m_b]);
      v50.m_real = (__m128)graph->m_searchSphereRadius;
      v51 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v49, *v49, 0), v44),
                  _mm_mul_ps(_mm_shuffle_ps(*v49, *v49, 85), v43)),
                _mm_mul_ps(_mm_shuffle_ps(*v49, *v49, 170), v46)),
              v47);
      v126 = v51;
      if ( v50.m_real.m128_f32[0] >= 0.0 )
      {
        v52 = _mm_sub_ps(v48, graph->m_startPoint.m_quad);
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
        v59 = _mm_cmplt_ps(v58, m_quad);
        v60 = _mm_sub_ps(
                v52,
                _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v59, v58), _mm_andnot_ps(v59, m_quad))), v53));
        v61 = _mm_mul_ps(v60, v60);
        if ( (float)((float)(_mm_shuffle_ps(v61, v61, 85).m128_f32[0] + _mm_shuffle_ps(v61, v61, 0).m128_f32[0])
                   + _mm_shuffle_ps(v61, v61, 170).m128_f32[0]) > (float)(v50.m_real.m128_f32[0] * v50.m_real.m128_f32[0]) )
          goto LABEL_51;
      }
      v62.m_real = (__m128)graph->m_searchCapsuleRadius;
      if ( v62.m_real.m128_f32[0] >= 0.0 )
      {
        m_numGoals = graph->m_numGoals;
        v64 = 0;
        v65 = 0i64;
        v66 = _mm_sub_ps(v51, v48);
        if ( (int)m_numGoals > 0 )
        {
          v67.m_quad = (__m128)graph->m_startPoint;
          v68 = (__m128)_xmm;
          m_endPoints = graph->m_endPoints;
          v125 = _mm_mul_ps(v62.m_real, v62.m_real);
          v70 = _mm_sub_ps(v48, v67.m_quad);
          v124 = v70;
          v71 = _mm_mul_ps(v70, v66);
          v72 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v71, v71, 85), _mm_shuffle_ps(v71, v71, 0)),
                  _mm_shuffle_ps(v71, v71, 170));
          v73 = _mm_mul_ps(v66, v66);
          v74 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
                  _mm_shuffle_ps(v73, v73, 170));
          v75 = _mm_rcp_ps(v74);
          v123 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v75, v74)), v75);
          v122 = _mm_mul_ps(v72, v123);
          do
          {
            v76 = _mm_sub_ps(m_endPoints->m_quad, v67.m_quad);
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
            v85 = _mm_mul_ps(_mm_sub_ps(v68, _mm_mul_ps(v84, v83)), v84);
            v86 = _mm_rcp_ps(v82);
            v87 = _mm_mul_ps(_mm_sub_ps(v68, _mm_mul_ps(v86, v82)), v86);
            v88 = _mm_sub_ps(_mm_mul_ps(v74, v80), _mm_mul_ps(v72, v78));
            v89 = _mm_cmplt_ps(v88, v83);
            v90 = _mm_and_ps(v89, v88);
            v91 = _mm_cmple_ps(v83, *(__m128 *)&epsilon);
            v92 = _mm_sub_ps(
                    _mm_mul_ps(
                      _mm_or_ps(
                        _mm_andnot_ps(
                          v91,
                          _mm_mul_ps(_mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v89, v83), v90)), v85)),
                        _mm_and_ps(v91, m_quad)),
                      _mm_mul_ps(v78, v123)),
                    v122);
            v93 = _mm_cmplt_ps(v92, m_quad);
            v94 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v93, m_quad), _mm_and_ps(v93, v92)));
            v67.m_quad = (__m128)graph->m_startPoint;
            v95 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v78, v87), v94), _mm_mul_ps(v80, v87));
            v96 = _mm_cmplt_ps(v95, m_quad);
            v97 = _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v96, m_quad), _mm_and_ps(v96, v95))),
                        v76),
                      v67.m_quad),
                    _mm_add_ps(_mm_mul_ps(v94, v66), v48));
            v98 = _mm_mul_ps(v97, v97);
            if ( (float)((float)(_mm_shuffle_ps(v98, v98, 85).m128_f32[0] + _mm_shuffle_ps(v98, v98, 0).m128_f32[0])
                       + _mm_shuffle_ps(v98, v98, 170).m128_f32[0]) <= v125.m128_f32[0] )
              break;
            v70 = v124;
            v68 = (__m128)_xmm;
            ++v65;
            ++v64;
            ++m_endPoints;
          }
          while ( v65 < m_numGoals );
          v51 = v126;
        }
        if ( v64 == (_DWORD)m_numGoals )
          goto LABEL_51;
      }
      m_edgeFilter = graph->m_edgeFilter;
      if ( m_edgeFilter )
      {
        v127 = -1;
        v128 = 0i64;
        v129 = -1;
        v130 = 0i64;
        v133 = -1;
        v134 = 0i64;
        striding = v33->m_faceDataStriding;
        v101 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v51, v48), (__m128)xmmword_141A711B0), v48);
        if ( striding )
          hkaiNavMeshInstance_getWithStriding_int__3(
            v33->m_originalFaceData,
            v33->m_numOriginalFaces,
            &v33->m_instancedFaceData,
            &v33->m_ownedFaceData,
            &v33->m_faceMap,
            v115,
            striding);
        v102 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__10(
                 v33->m_originalFaces,
                 v33->m_numOriginalFaces,
                 &v33->m_instancedFaces,
                 &v33->m_ownedFaces,
                 &v33->m_faceMap,
                 v115);
        v135 = v103;
        v133 = (int)retaddr;
        v134 = v102;
        if ( v33->m_edgeDataStriding )
          v104 = hkaiNavMeshInstance_getWithStriding_int__3(
                   v33->m_originalEdgeData,
                   v33->m_numOriginalEdges,
                   &v33->m_instancedEdgeData,
                   &v33->m_ownedEdgeData,
                   &v33->m_edgeMap,
                   v32,
                   v33->m_edgeDataStriding);
        else
          v104 = 0i64;
        v105 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__10(
                 v33->m_originalEdges,
                 v33->m_numOriginalEdges,
                 &v33->m_instancedEdges,
                 &v33->m_ownedEdges,
                 &v33->m_edgeMap,
                 v32);
        v132 = v101;
        v106 = *(_DWORD *)&v116[4 * v7];
        v130 = v105;
        v120[1] = (__int64)&graph->m_info;
        v129 = v106;
        v131 = v104;
        v120[0] = (__int64)v33;
        v121 = 33;
        v120[2] = (__int64)&v127;
        if ( !((unsigned __int8 (__fastcall *)(hkaiAstarEdgeFilter *, __int64 *))m_edgeFilter->vfptr[2].__first_virtual_table_function__)(
                m_edgeFilter,
                v120) )
          goto LABEL_50;
        m_quad = query.m_quad;
      }
      v107 = *((int *)&graphOut->vfptr->__vecDelDtor + (__int64)v117.mStereo);
      v108 = *((int *)&graphOut->vfptr->__vecDelDtor + v37);
      if ( (_DWORD)v107 == (_DWORD)v108 || (_DWORD)v107 == -1 || (_DWORD)v108 == -1 )
        goto LABEL_51;
      v109 = v108 | ((_DWORD)v107 << 16);
      Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v117,
                            v109);
      if ( Key > (int)v117.mHeight )
      {
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v117,
          &hkContainerHeapAllocator::s_alloc,
          v109,
          0i64);
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v117,
          &hkContainerHeapAllocator::s_alloc,
          ((__int64)v109 >> 16) | (v109 << 16),
          0i64);
        CostBetweenFaces = getCostBetweenFaces(
                             graph,
                             groupFromNode->m_data[v107],
                             groupFromNode->m_data[v108],
                             (hkaiNavMeshPathSearchParameters *)centroids,
                             searchParams);
        hkaiDirectedGraphExplicitCostBuilder::addEdge(&v118, v107, v108, CostBetweenFaces);
        hkaiDirectedGraphExplicitCostBuilder::addEdge(&v118, v108, v107, CostBetweenFaces);
      }
LABEL_50:
      m_quad = query.m_quad;
LABEL_51:
      m_cur = v116;
      if ( ++v7 >= v119 )
      {
        mExtension_high = HIDWORD(v117.mExtension);
        goto LABEL_53;
      }
    }
  }
LABEL_61:
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v117,
    &hkContainerHeapAllocator::s_alloc);
  _(&v117);
  hkaiDirectedGraphExplicitCostBuilder::build(&v118, d);
  LODWORD(v118.m_links.m_data) = 0;
  if ( SHIDWORD(v118.m_links.m_data) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)&v118.m_positions.m_size,
      12 * (HIDWORD(v118.m_links.m_data) & 0x3FFFFFFF));
  *(_QWORD *)&v118.m_positions.m_size = 0i64;
  LODWORD(v118.m_positions.m_data) = 0;
  HIDWORD(v118.m_links.m_data) = 0x80000000;
  if ( SHIDWORD(v118.m_positions.m_data) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v118.m_positions.m_data,
      16 * HIDWORD(v118.m_positions.m_data));
}

// File Line: 791
// RVA: 0xBF99F0
void __fastcall hkaiHierarchyUtils::clusterNavMesh(
        hkaiNavMesh *mesh,
        hkaiDirectedGraphExplicitCost *graphOut,
        int numGroups,
        bool ensureClusterPerNode,
        hkaiAstarCostModifier *costModifier,
        hkaiAstarEdgeFilter *edgeFilter)
{
  int v7; // ebx
  hkaiHierarchyUtils::ClusterSettings settings; // [rsp+20h] [rbp-68h] BYREF

  v7 = ensureClusterPerNode;
  hkaiHierarchyUtils::ClusterSettings::ClusterSettings(&settings);
  settings.m_searchParameters.m_costModifier = costModifier;
  settings.m_desiredFacesPerCluster = v7;
  settings.m_searchParameters.m_edgeFilter = edgeFilter;
  hkaiHierarchyUtils::clusterNavMesh(mesh, graphOut, &settings);
}

// File Line: 801
// RVA: 0xBF94C0
void __fastcall hkaiHierarchyUtils::clusterNavMesh(
        hkaiNavMesh *mesh,
        hkaiDirectedGraphExplicitCost *graphOut,
        hkaiHierarchyUtils::ClusterSettings *settings)
{
  int v4; // esi
  int v7; // eax
  int m_capacityAndFlags; // r8d
  int v9; // r8d
  int v10; // r8d
  hkaiStreamingCollection::InstanceInfo *m_data; // r9
  __int64 v12; // rdx
  hkaiDirectedGraphInstance **p_m_clusterGraphInstance; // rax
  __int64 m_size; // r15
  _QWORD *Value; // rax
  unsigned __int64 v16; // rcx
  _QWORD *v17; // r9
  unsigned __int64 v18; // rax
  _QWORD *v19; // r8
  _QWORD *v20; // rcx
  unsigned __int64 v21; // rax
  _QWORD *v22; // rcx
  int v23; // ecx
  int v24; // edi
  int v25; // edi
  __int64 v26; // rsi
  __int64 v27; // r8
  __int64 v28; // r9
  _QWORD *v29; // r8
  _QWORD *v30; // rcx
  unsigned __int64 v31; // rax
  _QWORD *v32; // rcx
  hkArray<int,hkContainerHeapAllocator> groupRepresentative; // [rsp+40h] [rbp-C0h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> centroids; // [rsp+50h] [rbp-B0h] BYREF
  hkArray<int,hkContainerHeapAllocator> groupFromNode; // [rsp+60h] [rbp-A0h] BYREF
  hkaiStreamingCollection array; // [rsp+70h] [rbp-90h] BYREF
  hkaiNavMeshFaceGraph graph; // [rsp+A0h] [rbp-60h] BYREF
  hkaiNavMeshInstance v38; // [rsp+110h] [rbp+10h] BYREF
  hkResult result; // [rsp+320h] [rbp+220h] BYREF

  v4 = 1;
  v7 = mesh->m_faces.m_size / settings->m_desiredFacesPerCluster;
  m_capacityAndFlags = graphOut->m_positions.m_capacityAndFlags;
  if ( v7 > 1 )
    v4 = v7;
  graphOut->m_positions.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      graphOut->m_positions.m_data,
      16 * m_capacityAndFlags);
  graphOut->m_positions.m_data = 0i64;
  graphOut->m_positions.m_capacityAndFlags = 0x80000000;
  v9 = graphOut->m_nodes.m_capacityAndFlags;
  graphOut->m_nodes.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      graphOut->m_nodes.m_data,
      8 * v9);
  graphOut->m_nodes.m_data = 0i64;
  graphOut->m_nodes.m_capacityAndFlags = 0x80000000;
  v10 = graphOut->m_edges.m_capacityAndFlags;
  graphOut->m_edges.m_size = 0;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      graphOut->m_edges.m_data,
      8 * v10);
  graphOut->m_edges.m_data = 0i64;
  graphOut->m_edges.m_capacityAndFlags = 0x80000000;
  if ( mesh->m_faces.m_size )
  {
    memset(&graph, 0, 40);
    graph.m_searchSphereRadius.m_real = _mm_sub_ps((__m128)0i64, query.m_quad);
    graph.m_searchCapsuleRadius = graph.m_searchSphereRadius;
    hkaiNavMeshInstance::hkaiNavMeshInstance(&v38);
    hkaiNavMeshInstance::tempInit(&v38, mesh, 1);
    hkaiStreamingCollection::hkaiStreamingCollection(&array);
    array.m_isTemporary.m_bool = 1;
    if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array.m_instances, 1, 48);
    m_data = array.m_instances.m_data;
    v12 = 1 - array.m_instances.m_size;
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
        --v12;
      }
      while ( v12 );
      m_data = array.m_instances.m_data;
    }
    array.m_instances.m_size = 1;
    m_data->m_instancePtr = &v38;
    array.m_instances.m_data->m_clusterGraphInstance = 0i64;
    array.m_instances.m_data->m_mediator = 0i64;
    m_size = mesh->m_faces.m_size;
    groupFromNode.m_data = 0i64;
    groupFromNode.m_size = 0;
    graph.m_collection = &array;
    groupFromNode.m_capacityAndFlags = 0x80000000;
    groupRepresentative.m_data = 0i64;
    groupRepresentative.m_size = 0;
    groupRepresentative.m_capacityAndFlags = 0x80000000;
    centroids.m_data = 0i64;
    centroids.m_size = 0;
    centroids.m_capacityAndFlags = 0x80000000;
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v16 = Value[1];
    v17 = Value;
    if ( v16 < Value[3] )
    {
      *(_QWORD *)v16 = "LtclusterNavMesh";
      *(_QWORD *)(v16 + 16) = "StgenerateClusters";
      v18 = __rdtsc();
      *(_DWORD *)(v16 + 8) = v18;
      v17[1] = v16 + 24;
    }
    hkaiSimpleClusterGenerator::generateClusters(
      &graph,
      v4,
      (int)m_size / v4 + 1,
      settings->m_ensureClusterPerRegion.m_bool != 0,
      &groupFromNode,
      &groupRepresentative,
      413);
    v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v20 = (_QWORD *)v19[1];
    if ( (unsigned __int64)v20 < v19[3] )
    {
      *v20 = "StgenerateGraph";
      v21 = __rdtsc();
      v22 = v20 + 2;
      *((_DWORD *)v22 - 2) = v21;
      v19[1] = v22;
    }
    v23 = groupRepresentative.m_size;
    v24 = groupRepresentative.m_size;
    if ( (centroids.m_capacityAndFlags & 0x3FFFFFFF) < groupRepresentative.m_size )
    {
      if ( groupRepresentative.m_size < 2 * (centroids.m_capacityAndFlags & 0x3FFFFFFF) )
        v23 = 2 * (centroids.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &centroids, v23, 16);
      v23 = groupRepresentative.m_size;
    }
    centroids.m_size = v24;
    v25 = 0;
    if ( v23 > 0 )
    {
      v26 = 0i64;
      do
      {
        hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)graph.m_collection->m_instances.m_data[(unsigned int)groupRepresentative.m_data[v26] >> 22].m_instancePtr,
          (hkaiNavMeshInstance *)(groupRepresentative.m_data[v26] & 0x3FFFFF),
          &centroids.m_data[v25++].m_quad,
          (hkVector4f *)(6i64 * ((unsigned int)groupRepresentative.m_data[v26] >> 22)));
        ++v26;
      }
      while ( v25 < groupRepresentative.m_size );
    }
    hkaiHierarchyUtils::buildAbstractGraphFromClusterInfo(
      &graph,
      graphOut,
      &groupFromNode,
      &groupRepresentative,
      &centroids,
      &settings->m_searchParameters,
      &settings->m_agentInfo);
    v27 = 0i64;
    if ( m_size > 0 )
    {
      v28 = 0i64;
      do
        mesh->m_faces.m_data[v28++].m_clusterIndex = groupFromNode.m_data[v27++];
      while ( v27 < m_size );
    }
    v29 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v30 = (_QWORD *)v29[1];
    if ( (unsigned __int64)v30 < v29[3] )
    {
      *v30 = "lt";
      v31 = __rdtsc();
      v32 = v30 + 2;
      *((_DWORD *)v32 - 2) = v31;
      v29[1] = v32;
    }
    centroids.m_size = 0;
    if ( centroids.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        centroids.m_data,
        16 * centroids.m_capacityAndFlags);
    centroids.m_data = 0i64;
    centroids.m_capacityAndFlags = 0x80000000;
    groupRepresentative.m_size = 0;
    if ( groupRepresentative.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        groupRepresentative.m_data,
        4 * groupRepresentative.m_capacityAndFlags);
    groupRepresentative.m_data = 0i64;
    groupRepresentative.m_capacityAndFlags = 0x80000000;
    groupFromNode.m_size = 0;
    if ( groupFromNode.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        groupFromNode.m_data,
        4 * groupFromNode.m_capacityAndFlags);
    groupFromNode.m_data = 0i64;
    groupFromNode.m_capacityAndFlags = 0x80000000;
    hkaiStreamingCollection::~hkaiStreamingCollection(&array);
    hkaiNavMeshInstance::~hkaiNavMeshInstance(&v38);
  }
}cityAndFlags);
    groupFromNode.m_data = 0i64;
   


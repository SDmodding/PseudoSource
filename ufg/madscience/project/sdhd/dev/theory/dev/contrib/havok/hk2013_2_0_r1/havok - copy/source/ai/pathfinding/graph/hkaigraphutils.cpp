// File Line: 18
// RVA: 0xC03770
__int64 __fastcall hkaiGraphUtils::getEdgeBetween(
        hkaiDirectedGraphExplicitCost *graph,
        int nodeIn,
        unsigned int targetNode)
{
  hkaiDirectedGraphExplicitCost::Node *m_data; // rax
  int m_numEdges; // r9d
  hkaiDirectedGraphExplicitCost::Node *v5; // r11
  int v6; // edx
  __int64 result; // rax

  m_data = graph->m_nodes.m_data;
  m_numEdges = m_data[nodeIn].m_numEdges;
  v5 = &m_data[nodeIn];
  v6 = 0;
  if ( m_numEdges <= 0 )
    return 0xFFFFFFFFi64;
  result = (unsigned int)v5->m_startEdgeIndex;
  while ( graph->m_edges.m_data[(int)result].m_target != targetNode )
  {
    ++v6;
    result = (unsigned int)(result + 1);
    if ( v6 >= m_numEdges )
      return 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 33
// RVA: 0xC037B0
__int64 __fastcall hkaiGraphUtils::getEdgeBetween(
        hkaiStreamingCollection *collection,
        unsigned int nodeIn,
        unsigned int targetNode)
{
  int v4; // ebp
  signed int v5; // edx
  __int64 v6; // r11
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // r8
  hkaiDirectedGraphExplicitCost::Node *m_originalNodes; // rax
  __int64 v10; // r14
  int m_numEdges; // esi
  int v12; // ebx
  int m_numOriginalEdges; // edi
  int m_startEdgeIndex; // edx
  hkaiDirectedGraphExplicitCost::Edge *m_data; // rax
  __int64 v16; // rcx
  unsigned int m_target; // r10d
  unsigned int v18; // ecx
  int v19; // eax
  __int64 v20; // rcx
  hkaiDirectedGraphExplicitCost::Node v21; // rax
  int v23; // ebx
  int v24; // edi
  hkaiDirectedGraphExplicitCost::Edge *m_originalEdges; // rax
  __int64 v26; // rcx
  unsigned int v27; // r10d
  unsigned int v28; // ecx
  int v29; // eax

  v4 = 0;
  v5 = nodeIn & 0x3FFFFF;
  v6 = nodeIn >> 22;
  if ( (int)v6 >= 0 )
    m_clusterGraphInstance = collection->m_instances.m_data[v6].m_clusterGraphInstance;
  else
    m_clusterGraphInstance = 0i64;
  m_originalNodes = m_clusterGraphInstance->m_originalNodes;
  v10 = v5;
  m_numEdges = m_originalNodes[v5].m_numEdges;
  v12 = 0;
  if ( m_numEdges > 0 )
  {
    m_numOriginalEdges = m_clusterGraphInstance->m_numOriginalEdges;
    m_startEdgeIndex = m_originalNodes[v5].m_startEdgeIndex;
    do
    {
      if ( m_startEdgeIndex >= m_numOriginalEdges )
      {
        v16 = m_startEdgeIndex - m_numOriginalEdges;
        m_data = m_clusterGraphInstance->m_ownedEdges.m_data;
      }
      else
      {
        m_data = m_clusterGraphInstance->m_originalEdges;
        v16 = m_startEdgeIndex;
      }
      m_target = m_data[v16].m_target;
      if ( (m_data[v16].m_flags.m_storage & 0x40) != 0 )
        v18 = m_target & 0xFFC00000;
      else
        v18 = m_clusterGraphInstance->m_runtimeId << 22;
      v19 = v18 | m_target & 0x3FFFFF;
      if ( m_target == -1 )
        v19 = -1;
      if ( v19 == targetNode )
        return (unsigned int)m_startEdgeIndex | ((_DWORD)v6 << 22);
      ++v12;
      ++m_startEdgeIndex;
    }
    while ( v12 < m_numEdges );
  }
  if ( !m_clusterGraphInstance->m_nodeMap.m_size
    || (v20 = m_clusterGraphInstance->m_nodeMap.m_data[v10], (_DWORD)v20 == -1) )
  {
    m_startEdgeIndex = -1;
    v21.m_numEdges = 0;
  }
  else
  {
    v21 = m_clusterGraphInstance->m_instancedNodes.m_data[v20];
    v4 = v21.m_numEdges;
    m_startEdgeIndex = v21.m_startEdgeIndex;
  }
  if ( v21.m_numEdges > 0 )
  {
    v23 = m_clusterGraphInstance->m_numOriginalEdges;
    v24 = -m_startEdgeIndex;
    while ( 1 )
    {
      if ( m_startEdgeIndex >= v23 )
      {
        v26 = m_startEdgeIndex - v23;
        m_originalEdges = m_clusterGraphInstance->m_ownedEdges.m_data;
      }
      else
      {
        m_originalEdges = m_clusterGraphInstance->m_originalEdges;
        v26 = m_startEdgeIndex;
      }
      v27 = m_originalEdges[v26].m_target;
      v28 = (m_originalEdges[v26].m_flags.m_storage & 0x40) != 0
          ? v27 & 0xFFC00000
          : m_clusterGraphInstance->m_runtimeId << 22;
      v29 = v28 | v27 & 0x3FFFFF;
      if ( v27 == -1 )
        v29 = -1;
      if ( v29 == targetNode )
        break;
      ++m_startEdgeIndex;
      if ( v24 + m_startEdgeIndex >= v4 )
        return 0xFFFFFFFFi64;
    }
    return (unsigned int)m_startEdgeIndex | ((_DWORD)v6 << 22);
  }
  return 0xFFFFFFFFi64;
}

// File Line: 65
// RVA: 0xC03940
void __fastcall hkaiGraphUtils::checkSymmetric(hkaiDirectedGraphExplicitCost *graph)
{
  __int64 m_size; // rbp
  int v2; // r9d
  __int64 v3; // rbx
  hkaiDirectedGraphExplicitCost::Node *m_data; // rdi
  int m_numEdges; // ecx
  hkaiDirectedGraphExplicitCost::Edge *v7; // rsi
  __int64 v8; // r11
  unsigned int *p_m_target; // r10
  __int64 v10; // rax
  __int64 v11; // rdx
  __int64 v12; // r8
  unsigned int *v13; // rax

  m_size = graph->m_nodes.m_size;
  v2 = 0;
  v3 = 0i64;
  if ( m_size > 0 )
  {
    m_data = graph->m_nodes.m_data;
    do
    {
      m_numEdges = m_data[v3].m_numEdges;
      if ( m_numEdges > 0 )
      {
        v7 = graph->m_edges.m_data;
        v8 = (unsigned int)m_numEdges;
        p_m_target = &v7[m_data[v3].m_startEdgeIndex].m_target;
        do
        {
          if ( *p_m_target != -1 )
          {
            v10 = *p_m_target & 0x3FFFFF;
            v11 = 0i64;
            v12 = m_data[v10].m_numEdges;
            if ( v12 > 0 )
            {
              v13 = &v7[m_data[v10].m_startEdgeIndex].m_target;
              do
              {
                if ( (*v13 & 0x3FFFFF) == v2 )
                  break;
                ++v11;
                v13 += 2;
              }
              while ( v11 < v12 );
            }
          }
          p_m_target += 2;
          --v8;
        }
        while ( v8 );
      }
      ++v3;
      ++v2;
    }
    while ( v3 < m_size );
  }
}

// File Line: 92
// RVA: 0xC03A10
void __fastcall hkaiGraphUtils::addDirectedGraphEdgeForUserEdge(
        unsigned int startFaceKey,
        unsigned int userEdgeKey,
        hkaiStreamingCollection *collection)
{
  hkaiGraphUtils::_adjustDirectedGraphEdge(startFaceKey, userEdgeKey, collection, GRAPH_ADD_EDGE);
}

// File Line: 98
// RVA: 0xC03A30
void __fastcall hkaiGraphUtils::removeDirectedGraphEdgeForUserEdge(
        unsigned int startFaceKey,
        unsigned int userEdgeKey,
        hkaiStreamingCollection *collection)
{
  hkaiGraphUtils::_adjustDirectedGraphEdge(startFaceKey, userEdgeKey, collection, GRAPH_REMOVE_EDGE);
}

// File Line: 103
// RVA: 0xC04B50
void __fastcall hkaiGraphUtils::_adjustDirectedGraphEdge(
        unsigned int startFaceKey,
        unsigned int userEdgeKey,
        hkaiStreamingCollection *collection,
        hkaiGraphUtils::Adjustment adj)
{
  hkaiStreamingCollection::InstanceInfo *m_data; // rbx
  __int64 v6; // rdi
  hkaiNavMeshInstance *m_instancePtr; // rsi
  int m_clusterIndex; // ebp
  int index; // r12d
  hkaiNavMesh::Edge *v10; // rax
  char m_storage; // cl
  unsigned int m_oppositeFace; // edx
  unsigned int v13; // eax
  unsigned int v14; // ecx
  __int64 v15; // r14
  hkaiNavMeshInstance *v16; // r13
  __int64 v17; // r11
  __int64 v18; // r15
  int v19; // edi
  hkaiDirectedGraphInstance *v20; // r9
  hkaiDirectedGraphExplicitCost::Node *m_originalNodes; // rax
  int m_startEdgeIndex; // r8d
  int v23; // ebx
  int m_numOriginalEdges; // r10d
  hkaiDirectedGraphExplicitCost::Edge *v25; // rax
  __int64 v26; // rcx
  unsigned int v27; // r11d
  hkaiDirectedGraphExplicitCost::Edge *v28; // rdx
  unsigned int v29; // ecx
  int v30; // eax
  __int64 v31; // rcx
  hkaiDirectedGraphExplicitCost::Node v32; // rax
  unsigned __int16 v33; // ax
  int v34; // eax
  hkaiDirectedGraphExplicitCost::Edge *m_originalEdges; // rcx
  __int64 v36; // rdx
  unsigned int m_target; // ebx
  hkaiDirectedGraphExplicitCost::Edge *v38; // r11
  unsigned int v39; // edx
  int v40; // ecx
  hkaiDirectedGraphExplicitCost::Edge *v41; // rbx
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm3
  __m128 v45; // xmm3
  __m128 v46; // xmm5
  __m128 v47; // xmm3
  __int64 v48; // rdx
  hkVector4f v49; // [rsp+30h] [rbp-88h] BYREF
  hkVector4f v50; // [rsp+40h] [rbp-78h] BYREF
  hkVector4f edgeB; // [rsp+50h] [rbp-68h] BYREF
  hkVector4f edgeA; // [rsp+60h] [rbp-58h] BYREF
  float v53; // [rsp+C0h] [rbp+8h]
  unsigned int v54; // [rsp+C8h] [rbp+10h]

  m_data = collection->m_instances.m_data;
  v6 = userEdgeKey >> 22;
  v54 = userEdgeKey >> 22;
  m_instancePtr = m_data[v6].m_instancePtr;
  m_clusterIndex = hkaiNavMeshInstance_get_hkaiNavMesh::Face__11(
                     m_instancePtr->m_originalFaces,
                     m_instancePtr->m_numOriginalFaces,
                     &m_instancePtr->m_instancedFaces,
                     &m_instancePtr->m_ownedFaces,
                     &m_instancePtr->m_faceMap,
                     startFaceKey & 0x3FFFFF)->m_clusterIndex;
  if ( m_clusterIndex != -1 )
  {
    index = userEdgeKey & 0x3FFFFF;
    v10 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__12(
            m_instancePtr->m_originalEdges,
            m_instancePtr->m_numOriginalEdges,
            &m_instancePtr->m_instancedEdges,
            &m_instancePtr->m_ownedEdges,
            &m_instancePtr->m_edgeMap,
            index);
    v49.m_quad.m128_u64[0] = (unsigned __int64)v10;
    if ( v10->m_oppositeEdge != -1 )
    {
      m_storage = v10->m_flags.m_storage;
      if ( (m_storage & 0x20) == 0 )
      {
        m_oppositeFace = v10->m_oppositeFace;
        if ( (m_storage & 0x40) != 0 )
          v13 = m_oppositeFace & 0xFFC00000;
        else
          v13 = m_instancePtr->m_runtimeId << 22;
        v14 = v13 | m_oppositeFace & 0x3FFFFF;
        if ( m_oppositeFace == -1 )
          v14 = -1;
        v15 = v14 >> 22;
        v16 = m_data[v15].m_instancePtr;
        v18 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__11(
                v16->m_originalFaces,
                v16->m_numOriginalFaces,
                &v16->m_instancedFaces,
                &v16->m_ownedFaces,
                &v16->m_faceMap,
                v14 & 0x3FFFFF)->m_clusterIndex;
        if ( (_DWORD)v18 != -1 )
        {
          v19 = m_clusterIndex | ((_DWORD)v6 << 22);
          if ( v19 != ((unsigned int)v18 | ((_DWORD)v15 << 22)) && (int)v15 >= 0 )
          {
            v20 = (hkaiDirectedGraphInstance *)*((_QWORD *)&m_data->m_clusterGraphInstance + v17);
            if ( v20 )
            {
              m_originalNodes = v20->m_originalNodes;
              m_startEdgeIndex = m_originalNodes[v18].m_startEdgeIndex;
              v23 = m_startEdgeIndex + m_originalNodes[v18].m_numEdges;
              if ( m_startEdgeIndex >= v23 )
              {
LABEL_25:
                if ( !v20->m_nodeMap.m_size || (v31 = v20->m_nodeMap.m_data[v18], (_DWORD)v31 == -1) )
                {
                  m_startEdgeIndex = -1;
                  v32.m_numEdges = 0;
                }
                else
                {
                  v32 = v20->m_instancedNodes.m_data[v31];
                  m_startEdgeIndex = v32.m_startEdgeIndex;
                }
                v32.m_startEdgeIndex = m_startEdgeIndex + v32.m_numEdges;
                if ( m_startEdgeIndex >= m_startEdgeIndex + v32.m_numEdges )
                {
LABEL_42:
                  if ( adj == GRAPH_ADD_EDGE )
                  {
                    v41 = hkaiDirectedGraphInstance::addEdgeForNode(v20, v18, 0i64);
                    hkaiNavMeshInstance::getEdgePoints(m_instancePtr, index, &edgeA, &edgeB);
                    hkaiNavMeshInstance::getEdgePoints(
                      v16,
                      *(_DWORD *)(v49.m_quad.m128_u64[0] + 8) & 0x3FFFFF,
                      &v50,
                      &v49);
                    v42 = _mm_mul_ps(_mm_sub_ps(v49.m_quad, v50.m_quad), (__m128)xmmword_141A711B0);
                    v43 = _mm_mul_ps(_mm_sub_ps(edgeB.m_quad, edgeA.m_quad), (__m128)xmmword_141A711B0);
                    v41->m_target = v19;
                    v44 = _mm_sub_ps(_mm_add_ps(v43, edgeA.m_quad), _mm_add_ps(v42, v50.m_quad));
                    v45 = _mm_mul_ps(v44, v44);
                    v46 = _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
                            _mm_shuffle_ps(v45, v45, 170));
                    v47 = _mm_rsqrt_ps(v46);
                    v53 = _mm_andnot_ps(
                            _mm_cmple_ps(v46, (__m128)0i64),
                            _mm_mul_ps(
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v46, v47), v47)),
                                _mm_mul_ps(*(__m128 *)_xmm, v47)),
                              v46)).m128_f32[0]
                        * 1.0039062;
                    v41->m_cost.m_value = HIWORD(v53);
                    v41->m_flags.m_storage = 2;
                    if ( v54 != (_DWORD)v15 )
                      v41->m_flags.m_storage = 66;
                  }
                  return;
                }
                m_numOriginalEdges = v20->m_numOriginalEdges;
                while ( 1 )
                {
                  if ( m_startEdgeIndex >= m_numOriginalEdges )
                  {
                    v36 = m_startEdgeIndex - m_numOriginalEdges;
                    m_originalEdges = v20->m_ownedEdges.m_data;
                  }
                  else
                  {
                    m_originalEdges = v20->m_originalEdges;
                    v36 = m_startEdgeIndex;
                  }
                  m_target = m_originalEdges[v36].m_target;
                  v38 = &m_originalEdges[v36];
                  if ( (v38->m_flags.m_storage & 0x40) != 0 )
                    v39 = m_target & 0xFFC00000;
                  else
                    v39 = v20->m_runtimeId << 22;
                  v40 = v39 | m_target & 0x3FFFFF;
                  if ( m_target == -1 )
                    v40 = -1;
                  if ( v40 == v19 )
                    break;
                  if ( ++m_startEdgeIndex >= v34 )
                    goto LABEL_42;
                }
                v33 = v38->m_flags.m_storage;
              }
              else
              {
                m_numOriginalEdges = v20->m_numOriginalEdges;
                while ( 1 )
                {
                  if ( m_startEdgeIndex >= m_numOriginalEdges )
                  {
                    v26 = m_startEdgeIndex - m_numOriginalEdges;
                    v25 = v20->m_ownedEdges.m_data;
                  }
                  else
                  {
                    v25 = v20->m_originalEdges;
                    v26 = m_startEdgeIndex;
                  }
                  v27 = v25[v26].m_target;
                  v28 = &v25[v26];
                  if ( (v28->m_flags.m_storage & 0x40) != 0 )
                    v29 = v27 & 0xFFC00000;
                  else
                    v29 = v20->m_runtimeId << 22;
                  v30 = v29 | v27 & 0x3FFFFF;
                  if ( v27 == -1 )
                    v30 = -1;
                  if ( v30 == v19 )
                    break;
                  if ( ++m_startEdgeIndex >= v23 )
                    goto LABEL_25;
                }
                v33 = v28->m_flags.m_storage;
              }
              if ( (v33 & 2) != 0 && m_startEdgeIndex >= m_numOriginalEdges )
              {
                v48 = m_startEdgeIndex - m_numOriginalEdges;
                v20->m_userEdgeCount.m_data[v48] += adj;
                if ( !v20->m_userEdgeCount.m_data[v48] )
                  hkaiDirectedGraphInstance::removeOwnedEdgeForNode(v20, v18, m_startEdgeIndex);
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 238
// RVA: 0xC03C00
void __fastcall hkaiGraphUtils::compactOwnedEdges(hkaiDirectedGraphInstance *graph)
{
  __int64 m_size; // r14
  int v3; // edi
  hkLifoAllocator *Value; // rax
  unsigned int *m_cur; // rcx
  int v6; // edx
  char *v7; // r8
  int v8; // r9d
  int v9; // eax
  unsigned int *m_data; // rdi
  __int64 i; // rcx
  hkResultEnum m_numOriginalEdges; // edi
  int v13; // r11d
  __int64 v14; // rsi
  __int64 v15; // rcx
  hkaiDirectedGraphExplicitCost::Node v16; // rax
  int m_startEdgeIndex; // edx
  int v18; // eax
  int v19; // r10d
  __int64 v20; // r9
  __int64 v21; // rdi
  char v22; // cl
  hkaiDirectedGraphExplicitCost::Edge *v23; // rax
  int *v24; // rdi
  int v25; // r11d
  int v26; // esi
  int v27; // r8d
  __int64 v28; // r9
  __int64 v29; // r13
  hkaiDirectedGraphExplicitCost::Edge *v30; // r14
  hkaiDirectedGraphExplicitCost::Edge *v31; // rdx
  __int64 v32; // rdi
  hkaiDirectedGraphExplicitCost::Edge *v33; // rcx
  __int64 m_edgeDataStriding; // r10
  unsigned int *v35; // rcx
  char *v36; // rdi
  char *v37; // rdx
  int v38; // eax
  __int64 v39; // rcx
  signed __int64 v40; // rdi
  int v41; // eax
  int v42; // r14d
  int v43; // eax
  int v44; // eax
  int v45; // r9d
  int v46; // eax
  int v47; // eax
  int v48; // r9d
  int v49; // edi
  int v50; // eax
  int v51; // eax
  int v52; // r9d
  __int64 m_enum; // r10
  int v54; // r8d
  __int64 v55; // rdi
  __int64 v56; // rcx
  hkaiDirectedGraphExplicitCost::Node *v57; // rdx
  __int64 v58; // rax
  int v59; // eax
  __int64 v60; // rsi
  int *v61; // rdi
  int v62; // r8d
  int v63; // r8d
  __int64 v64; // [rsp+30h] [rbp-40h] BYREF
  int v65; // [rsp+38h] [rbp-38h]
  int v66; // [rsp+3Ch] [rbp-34h]
  hkBitFieldStorage<hkLocalArray<unsigned int> > array; // [rsp+40h] [rbp-30h] BYREF
  hkResult result; // [rsp+B0h] [rbp+40h] BYREF
  hkResult v69; // [rsp+B8h] [rbp+48h] BYREF
  __int64 v70; // [rsp+C0h] [rbp+50h] BYREF

  m_size = graph->m_ownedEdges.m_size;
  array.m_words.m_data = 0i64;
  array.m_words.m_size = 0;
  v3 = ((int)m_size + 31) >> 5;
  array.m_words.m_capacityAndFlags = 0x80000000;
  array.m_words.m_initialCapacity = v3;
  if ( v3 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (unsigned int *)Value->m_cur;
    v6 = (4 * v3 + 127) & 0xFFFFFF80;
    v7 = (char *)m_cur + v6;
    if ( v6 > Value->m_slabSize || v7 > Value->m_end )
      m_cur = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(Value, v6);
    else
      Value->m_cur = v7;
  }
  else
  {
    m_cur = 0i64;
  }
  array.m_words.m_data = m_cur;
  array.m_words.m_localMemory = m_cur;
  array.m_numBits = m_size;
  array.m_words.m_capacityAndFlags = v3 | 0x80000000;
  if ( (v3 & 0x3FFFFFFF) < v3 )
  {
    v8 = ((int)m_size + 31) >> 5;
    if ( v3 < 2 * (v3 & 0x3FFFFFFF) )
      v8 = 2 * (v3 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array, v8, 4);
  }
  v9 = v3 - 1;
  array.m_words.m_size = ((int)m_size + 31) >> 5;
  if ( v3 - 1 >= 0 )
  {
    m_data = array.m_words.m_data;
    for ( i = (unsigned int)(v9 + 1); i; --i )
      *m_data++ = 0;
  }
  m_numOriginalEdges = graph->m_numOriginalEdges;
  v13 = 0;
  result.m_enum = m_numOriginalEdges;
  if ( graph->m_numOriginalNodes > 0 )
  {
    v14 = 0i64;
    do
    {
      if ( !graph->m_nodeMap.m_size || (v15 = graph->m_nodeMap.m_data[v14], (_DWORD)v15 == -1) )
      {
        m_startEdgeIndex = -1;
        v70 = 0xFFFFFFFFi64;
        v16.m_numEdges = 0;
      }
      else
      {
        v16 = graph->m_instancedNodes.m_data[v15];
        v70 = (__int64)v16;
        m_startEdgeIndex = v16.m_startEdgeIndex;
      }
      v16.m_startEdgeIndex = m_startEdgeIndex + v16.m_numEdges;
      if ( m_startEdgeIndex < m_startEdgeIndex + v16.m_numEdges )
      {
        v19 = -m_numOriginalEdges;
        v20 = m_startEdgeIndex - m_numOriginalEdges;
        do
        {
          v21 = v20++;
          v22 = (v19 + m_startEdgeIndex++) & 0x1F;
          array.m_words.m_data[v21 >> 5] |= 1 << v22;
        }
        while ( m_startEdgeIndex < v18 );
        m_numOriginalEdges = result.m_enum;
      }
      ++v13;
      ++v14;
    }
    while ( v13 < graph->m_numOriginalNodes );
  }
  v64 = 0i64;
  v65 = 0;
  v66 = 0x80000000;
  if ( (int)m_size > 0 )
    hkArrayUtil::_reserve((hkResult *)&v70, &hkContainerTempAllocator::s_alloc, &v64, m_size, 4);
  v23 = graph->m_ownedEdges.m_data;
  v24 = graph->m_userEdgeCount.m_data;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 0i64;
  v65 = m_size;
  v29 = m_size;
  if ( (int)m_size > 0 )
  {
    v30 = v23;
    do
    {
      *(_DWORD *)(v64 + 4 * v28) = v27 - v25;
      if ( ((array.m_words.m_data[(__int64)v27 >> 5] >> (v27 & 0x1F)) & 1) != 0 )
      {
        v31 = v30;
        v32 = (__int64)(v24 + 1);
        v33 = &graph->m_ownedEdges.m_data[v28];
        v70 = v32;
        ++v30;
        v31->m_cost.m_value = v33->m_cost.m_value;
        v31->m_flags.m_storage = v33->m_flags.m_storage;
        v31->m_target = v33->m_target;
        *(_DWORD *)(v32 - 4) = graph->m_userEdgeCount.m_data[v28];
        m_edgeDataStriding = graph->m_edgeDataStriding;
        v35 = graph->m_ownedEdgeData.m_data;
        v36 = (char *)&v35[v27 * graph->m_edgeDataStriding];
        v37 = (char *)&v35[v26 * graph->m_edgeDataStriding];
        if ( (_DWORD)m_edgeDataStriding == 1 )
        {
          v38 = *(_DWORD *)v36;
          v24 = (int *)v70;
          ++v26;
          *(_DWORD *)v37 = v38;
        }
        else
        {
          v39 = graph->m_edgeDataStriding;
          if ( m_edgeDataStriding >= 1 )
          {
            v40 = v36 - v37;
            do
            {
              v41 = *(_DWORD *)&v37[v40];
              v37 += 4;
              *((_DWORD *)v37 - 1) = v41;
              --v39;
            }
            while ( v39 );
          }
          v24 = (int *)v70;
          ++v26;
        }
      }
      else
      {
        ++v25;
      }
      ++v28;
      ++v27;
    }
    while ( v28 < v29 );
    LODWORD(m_size) = v29;
  }
  v42 = m_size - v25;
  v43 = graph->m_ownedEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v43 < v42 )
  {
    v44 = 2 * v43;
    v45 = v42;
    if ( v42 < v44 )
      v45 = v44;
    hkArrayUtil::_reserve(&v69, &hkContainerHeapAllocator::s_alloc, &graph->m_ownedEdges, v45, 8);
  }
  graph->m_ownedEdges.m_size = v42;
  v46 = graph->m_userEdgeCount.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v46 < v42 )
  {
    v47 = 2 * v46;
    v48 = v42;
    if ( v42 < v47 )
      v48 = v47;
    hkArrayUtil::_reserve(&v69, &hkContainerHeapAllocator::s_alloc, &graph->m_userEdgeCount, v48, 4);
  }
  graph->m_userEdgeCount.m_size = v42;
  v49 = v42 * graph->m_edgeDataStriding;
  v50 = graph->m_ownedEdgeData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v50 < v49 )
  {
    v51 = 2 * v50;
    v52 = v42 * graph->m_edgeDataStriding;
    if ( v49 < v51 )
      v52 = v51;
    hkArrayUtil::_reserve(&v69, &hkContainerHeapAllocator::s_alloc, &graph->m_ownedEdgeData, v52, 4);
  }
  m_enum = result.m_enum;
  graph->m_ownedEdgeData.m_size = v49;
  v54 = 0;
  if ( graph->m_numOriginalNodes > 0 )
  {
    v55 = 0i64;
    do
    {
      if ( graph->m_nodeMap.m_size )
      {
        v56 = graph->m_nodeMap.m_data[v55];
        if ( (_DWORD)v56 != -1 )
        {
          v57 = &graph->m_instancedNodes.m_data[v56];
          if ( v57 )
          {
            v58 = v57->m_startEdgeIndex;
            if ( (int)v58 > 0 )
              v57->m_startEdgeIndex = m_enum + *(_DWORD *)(v64 + 4 * (v58 - m_enum));
          }
        }
      }
      ++v54;
      ++v55;
    }
    while ( v54 < graph->m_numOriginalNodes );
  }
  v59 = graph->m_freeEdgeBlocks.m_size - 1;
  v60 = v59;
  if ( v59 >= 0 )
  {
    v61 = &graph->m_freeEdgeBlocks.m_data->m_blocks.m_capacityAndFlags + 4 * v59;
    do
    {
      v62 = *v61;
      *(v61 - 1) = 0;
      if ( v62 >= 0 )
        ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _QWORD, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerHeapAllocator::s_alloc,
          *(_QWORD *)(v61 - 3),
          (unsigned int)(4 * v62),
          v28);
      *(_QWORD *)(v61 - 3) = 0i64;
      *v61 = 0x80000000;
      v61 -= 4;
      --v60;
    }
    while ( v60 >= 0 );
  }
  v63 = v66;
  graph->m_freeEdgeBlocks.m_size = 0;
  v65 = 0;
  if ( v63 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v64,
      (unsigned int)(4 * v63),
      v28);
  v64 = 0i64;
  v66 = 0x80000000;
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>(&array);
}

// File Line: 302
// RVA: 0xC03A40
void __fastcall hkaiGraphUtils::removeDirectedUserEdgesToSection(hkaiStreamingCollection *collection, int sectionIndex)
{
  hkaiStreamingCollection *v2; // r8
  int v3; // ecx
  __int64 v4; // r13
  __int64 v6; // rdx
  hkaiDirectedGraphInstance *v7; // rdi
  int v8; // r14d
  __int64 v9; // r15
  __int64 v10; // rcx
  hkaiDirectedGraphExplicitCost::Node *v11; // rdx
  int m_startEdgeIndex; // ebp
  int v13; // ebx
  __int64 v14; // rsi
  int m_numOriginalEdges; // ecx
  __int64 v16; // rcx
  __int16 v17; // ax
  int v18; // edx
  unsigned int v19; // eax
  unsigned int v20; // ecx
  int v22; // [rsp+70h] [rbp+18h]
  __int64 v23; // [rsp+78h] [rbp+20h]

  v2 = collection;
  v3 = 0;
  v4 = 0i64;
  v22 = 0;
  if ( v2->m_instances.m_size > 0 )
  {
    v6 = 0i64;
    v23 = 0i64;
    do
    {
      if ( v4 >= 0 )
      {
        v7 = *(hkaiDirectedGraphInstance **)((char *)&v2->m_instances.m_data->m_clusterGraphInstance + v6);
        if ( v7 )
        {
          v8 = 0;
          if ( v7->m_numOriginalNodes > 0 )
          {
            v9 = 0i64;
            do
            {
              if ( v7->m_nodeMap.m_size )
              {
                v10 = v7->m_nodeMap.m_data[v9];
                if ( (_DWORD)v10 != -1 )
                {
                  v11 = &v7->m_instancedNodes.m_data[v10];
                  if ( v11 )
                  {
                    m_startEdgeIndex = v11->m_startEdgeIndex;
                    if ( v11->m_startEdgeIndex != -1 )
                    {
                      v13 = v11->m_numEdges + m_startEdgeIndex - 1;
                      if ( v13 >= m_startEdgeIndex )
                      {
                        v14 = v13;
                        do
                        {
                          m_numOriginalEdges = v7->m_numOriginalEdges;
                          if ( v13 >= m_numOriginalEdges )
                            v16 = (__int64)&v7->m_ownedEdges.m_data[v13 - m_numOriginalEdges];
                          else
                            v16 = (__int64)&v7->m_originalEdges[v14];
                          v17 = *(_WORD *)(v16 + 2);
                          if ( (v17 & 2) != 0 && (v17 & 0x40) != 0 )
                          {
                            v18 = *(_DWORD *)(v16 + 4);
                            if ( (v17 & 0x40) != 0 )
                              v19 = v18 & 0xFFC00000;
                            else
                              v19 = v7->m_runtimeId << 22;
                            v20 = v19 | v18 & 0x3FFFFF;
                            if ( v18 == -1 )
                              v20 = -1;
                            if ( v20 >> 22 == sectionIndex )
                              hkaiDirectedGraphInstance::removeOwnedEdgeForNode(v7, v8, v13);
                          }
                          --v13;
                          --v14;
                        }
                        while ( v13 >= m_startEdgeIndex );
                      }
                    }
                  }
                }
              }
              ++v8;
              ++v9;
            }
            while ( v8 < v7->m_numOriginalNodes );
            v3 = v22;
            v6 = v23;
            v2 = collection;
          }
        }
      }
      ++v3;
      v6 += 48i64;
      ++v4;
      v22 = v3;
      v23 = v6;
    }
    while ( v3 < v2->m_instances.m_size );
  }
}

// File Line: 341
// RVA: 0xC05200
void __fastcall copyStructAndData_hkVector4f_int_(
        hkVector4f *dstT,
        char *dstData,
        hkVector4f *srcT,
        char *srcData,
        int dataStride)
{
  __int64 v5; // rcx
  signed __int64 v6; // r9
  int v7; // eax

  *dstT = (hkVector4f)srcT->m_quad;
  if ( dataStride == 1 )
  {
    *(_DWORD *)dstData = *(_DWORD *)srcData;
  }
  else
  {
    v5 = dataStride;
    if ( dataStride >= 1i64 )
    {
      v6 = srcData - dstData;
      do
      {
        v7 = *(_DWORD *)&dstData[v6];
        dstData += 4;
        *((_DWORD *)dstData - 1) = v7;
        --v5;
      }
      while ( v5 );
    }
  }
}

// File Line: 347
// RVA: 0xC05040
void __fastcall copyEdgeAndData_0(hkaiDirectedGraphExplicitCost *graph, int dstIdx, int srcIdx)
{
  int dataStride; // r10d
  __int64 v4; // rbx
  unsigned int *v5; // rdx
  const unsigned int *v6; // r9

  dataStride = graph->m_edgeDataStriding;
  v4 = dstIdx;
  v5 = 0i64;
  if ( dataStride )
    v6 = &graph->m_edgeData.m_data[srcIdx * dataStride];
  else
    v6 = 0i64;
  if ( dataStride )
    v5 = &graph->m_edgeData.m_data[(int)v4 * dataStride];
  copyStructAndData_hkaiDirectedGraphExplicitCost::Edge_unsigned_int_(
    &graph->m_edges.m_data[v4],
    v5,
    &graph->m_edges.m_data[srcIdx],
    v6,
    dataStride);
}

// File Line: 352
// RVA: 0xC05110
void __fastcall copyNodeAndData(hkaiDirectedGraphExplicitCost *graph, int dstIdx, int srcIdx)
{
  int dataStride; // r10d
  __int64 v4; // rbx
  const unsigned int *v6; // r9
  unsigned int *v7; // rdx
  __int64 v8; // r11

  dataStride = graph->m_nodeDataStriding;
  v4 = dstIdx;
  if ( dataStride )
    v6 = &graph->m_nodeData.m_data[srcIdx * dataStride];
  else
    v6 = 0i64;
  if ( dataStride )
    v7 = &graph->m_nodeData.m_data[dstIdx * dataStride];
  else
    v7 = 0i64;
  copyStructAndData_hkaiDirectedGraphExplicitCost::Node_unsigned_int_(
    &graph->m_nodes.m_data[v4],
    v7,
    &graph->m_nodes.m_data[srcIdx],
    v6,
    dataStride);
  copyStructAndData_hkVector4f_int_(&graph->m_positions.m_data[v4], 0i64, &graph->m_positions.m_data[v8], 0i64, 0);
}

// File Line: 358
// RVA: 0xC05250
void __fastcall getNodes(
        hkaiDirectedGraphExplicitCost *graph,
        const int n,
        hkArrayBase<hkaiDirectedGraphExplicitCost::Node> *nodesOut)
{
  nodesOut->m_data[nodesOut->m_size++] = graph->m_nodes.m_data[n];
}

// File Line: 365
// RVA: 0xC05280
void __fastcall getNodes_0(
        hkaiDirectedGraphInstance *graphInstance,
        const int n,
        hkArrayBase<hkaiDirectedGraphExplicitCost::Node> *nodesOut)
{
  __int64 v3; // rbx
  __int64 v5; // rcx
  hkaiDirectedGraphExplicitCost::Node *v6; // rdx
  __int64 v7; // rcx

  v3 = n;
  nodesOut->m_data[nodesOut->m_size] = graphInstance->m_originalNodes[n];
  v5 = nodesOut->m_size + 1;
  nodesOut->m_size += 2;
  v6 = &nodesOut->m_data[v5];
  if ( !graphInstance->m_nodeMap.m_size || (v7 = graphInstance->m_nodeMap.m_data[v3], (_DWORD)v7 == -1) )
  {
    v6->m_startEdgeIndex = -1;
    v6->m_numEdges = 0;
  }
  else
  {
    *v6 = graphInstance->m_instancedNodes.m_data[v7];
  }
}

// File Line: 376
// RVA: 0xC05500
void __fastcall _createEdgeToNodeMap<hkaiDirectedGraphInstance>(
        hkaiDirectedGraphInstance *graph,
        hkArray<int,hkContainerHeapAllocator> *nodeIndices)
{
  int m_capacityAndFlags; // eax
  int v4; // eax
  int v5; // ebx
  int v7; // eax
  int v8; // r9d
  __int64 m_size; // rdx
  int *v10; // rdi
  __int64 v11; // rcx
  int i; // ebx
  int v13; // ecx
  __int64 v14; // r9
  __int64 v15; // r10
  hkaiDirectedGraphExplicitCost::Node *m_data; // r8
  __int64 v17; // rax
  int v18; // edi
  __int64 v19; // rdx
  hkArrayBase<hkaiDirectedGraphExplicitCost::Node> nodesOut; // [rsp+30h] [rbp-38h] BYREF
  char v21; // [rsp+40h] [rbp-28h] BYREF
  hkResult result; // [rsp+70h] [rbp+8h] BYREF

  m_capacityAndFlags = nodeIndices->m_capacityAndFlags;
  nodeIndices->m_size = 0;
  v4 = m_capacityAndFlags & 0x3FFFFFFF;
  v5 = graph->m_numOriginalEdges + graph->m_ownedEdges.m_size;
  if ( v4 < v5 )
  {
    v7 = 2 * v4;
    v8 = graph->m_numOriginalEdges + graph->m_ownedEdges.m_size;
    if ( v5 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, nodeIndices, v8, 4);
  }
  m_size = nodeIndices->m_size;
  v10 = &nodeIndices->m_data[m_size];
  v11 = v5 - (int)m_size;
  if ( v5 - (int)m_size > 0 )
  {
    while ( v11 )
    {
      *v10++ = -1;
      --v11;
    }
  }
  nodeIndices->m_size = v5;
  for ( i = 0; i < graph->m_numOriginalNodes; ++i )
  {
    nodesOut.m_size = 0;
    nodesOut.m_capacityAndFlags = -2147483646;
    nodesOut.m_data = (hkaiDirectedGraphExplicitCost::Node *)&v21;
    getNodes_0(graph, i, &nodesOut);
    v13 = nodesOut.m_size;
    v14 = 0i64;
    if ( nodesOut.m_size > 0 )
    {
      v15 = 0i64;
      do
      {
        m_data = nodesOut.m_data;
        v17 = 0i64;
        v18 = 0;
        if ( nodesOut.m_data[v15].m_numEdges > 0 )
        {
          do
          {
            ++v18;
            v19 = v17 + m_data[v15].m_startEdgeIndex;
            ++v17;
            nodeIndices->m_data[v19] = i;
          }
          while ( v18 < m_data[v15].m_numEdges );
          v13 = nodesOut.m_size;
        }
        v14 = (unsigned int)(v14 + 1);
        ++v15;
      }
      while ( (int)v14 < v13 );
    }
    nodesOut.m_size = 0;
    if ( nodesOut.m_capacityAndFlags >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkaiDirectedGraphExplicitCost::Node *, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        nodesOut.m_data,
        (unsigned int)(8 * nodesOut.m_capacityAndFlags),
        v14);
  }
}

// File Line: 396
// RVA: 0xC04B30
// attributes: thunk
void __fastcall hkaiGraphUtils::createEdgeToNodeMap(
        hkaiDirectedGraphExplicitCost *graph,
        hkArray<int,hkContainerHeapAllocator> *nodeIndices)
{
  _createEdgeToNodeMap<hkaiDirectedGraphExplicitCost>(graph, nodeIndices);
}

// File Line: 401
// RVA: 0xC04B40
// attributes: thunk
void __fastcall hkaiGraphUtils::createEdgeToNodeMap(
        hkaiDirectedGraphInstance *graphInstance,
        hkArray<int,hkContainerHeapAllocator> *nodeIndices)
{
  _createEdgeToNodeMap<hkaiDirectedGraphInstance>(graphInstance, nodeIndices);
}

// File Line: 406
// RVA: 0xC05300
void __fastcall reindexStreamingSets(
        hkaiStreamingSet *thisSet,
        hkaiStreamingSet *otherSet,
        hkArrayBase<int> *nodeRemap)
{
  int v3; // r9d
  int v6; // ebx
  __int64 v8; // r11
  hkaiStreamingSet::GraphConnection *m_data; // rdx
  __int64 m_nodeIndex; // rcx
  __int64 v11; // r8
  hkaiStreamingSet::GraphConnection *v12; // rdx
  __int64 m_oppositeNodeIndex; // rcx

  v3 = 0;
  v6 = 0;
  if ( thisSet->m_graphConnections.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      m_data = thisSet->m_graphConnections.m_data;
      ++v6;
      m_nodeIndex = m_data[v8++].m_nodeIndex;
      m_data[v8 - 1].m_nodeIndex = nodeRemap->m_data[m_nodeIndex];
    }
    while ( v6 < thisSet->m_graphConnections.m_size );
  }
  if ( otherSet->m_graphConnections.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      v12 = otherSet->m_graphConnections.m_data;
      ++v3;
      m_oppositeNodeIndex = v12[v11++].m_oppositeNodeIndex;
      v12[v11 - 1].m_oppositeNodeIndex = nodeRemap->m_data[m_oppositeNodeIndex];
    }
    while ( v3 < otherSet->m_graphConnections.m_size );
  }
}

// File Line: 421
// RVA: 0xC041D0
hkResult *__fastcall hkaiGraphUtils::removeNodes(
        hkResult *result,
        hkaiDirectedGraphExplicitCost *graph,
        hkArray<int,hkContainerTempAllocator> *nodesToRemove,
        bool invalidateOppEdges,
        hkArray<hkaiDirectedGraphExplicitCost *,hkContainerHeapAllocator> *otherGraphs)
{
  hkArray<int,hkContainerTempAllocator> *v5; // rsi
  int m_size; // r8d
  hkResult *v10; // rax
  int v11; // r9d
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // r9d
  __int64 v16; // r10
  int v17; // edx
  hkaiDirectedGraphExplicitCost::Node *v18; // r8
  hkaiDirectedGraphExplicitCost::Edge *m_data; // rdi
  unsigned int m_target; // ecx
  int v21; // edi
  unsigned int v22; // eax
  int v23; // edi
  int v24; // eax
  int v25; // eax
  int v26; // r9d
  int v27; // r9d
  int m_capacityAndFlags; // r8d
  int v29; // ebx
  int v30; // edi
  __int32 v31; // ecx
  _DWORD *v32; // r8
  int v33; // eax
  int v34; // ecx
  int v35; // r9d
  int v36; // edi
  __int64 v37; // rcx
  _DWORD *v38; // rdi
  int *v39; // r9
  int v40; // r8d
  int *v41; // r12
  int v42; // ebx
  int m_enum; // r8d
  __int64 v44; // r11
  hkResultEnum m_numEdges; // edi
  __int64 v46; // r14
  __int64 v47; // r10
  signed int v48; // edx
  __m128i si128; // xmm3
  __m128i v50; // xmm2
  __m128i v51; // xmm1
  int v52; // eax
  __m128i v53; // xmm0
  __int64 v54; // rsi
  char *v55; // rdi
  unsigned int v56; // r11d
  __int64 v57; // rdi
  unsigned int v58; // edx
  __int64 v59; // r8
  int v60; // edi
  int v61; // ecx
  int *v62; // rbx
  int v63; // r14d
  int v64; // edi
  hkArray<int,hkContainerTempAllocator> *v65; // r12
  __int64 v66; // rsi
  unsigned __int64 v67; // r9
  int v68; // r10d
  hkaiDirectedGraphExplicitCost::Node *v69; // rdi
  int v70; // r8d
  int v71; // edx
  hkaiDirectedGraphExplicitCost::Edge *v72; // r8
  unsigned int v73; // ecx
  hkArray<hkaiDirectedGraphExplicitCost *,hkContainerHeapAllocator> *v74; // rdx
  int v75; // ecx
  __int64 v76; // rdi
  int v77; // r12d
  hkaiStreamingSet *v78; // rsi
  __int64 v79; // rcx
  int v80; // ebx
  __int64 v81; // r14
  __int64 v82; // rdi
  hkaiStreamingSet *v83; // rdx
  int v84; // r8d
  hkResult resulta[2]; // [rsp+30h] [rbp-41h] BYREF
  char *v86; // [rsp+38h] [rbp-39h] BYREF
  int v87; // [rsp+40h] [rbp-31h]
  int v88; // [rsp+44h] [rbp-2Dh]
  unsigned int v89; // [rsp+48h] [rbp-29h]
  hkArray<int,hkContainerHeapAllocator> nodeIndices; // [rsp+50h] [rbp-21h] BYREF
  hkArrayBase<int> array; // [rsp+60h] [rbp-11h] BYREF
  hkResult v92[2]; // [rsp+70h] [rbp-1h] BYREF
  _DWORD *v93; // [rsp+78h] [rbp+7h] BYREF
  int v94; // [rsp+80h] [rbp+Fh]
  int v95; // [rsp+84h] [rbp+13h]
  int v96; // [rsp+88h] [rbp+17h]
  hkArray<int,hkContainerTempAllocator> *v98; // [rsp+E0h] [rbp+6Fh] BYREF

  v98 = nodesToRemove;
  v5 = nodesToRemove;
  m_size = nodesToRemove->m_size;
  if ( !m_size )
  {
    v10 = result;
    result->m_enum = HK_SUCCESS;
    return v10;
  }
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<int,hkAlgorithm::less<int>>(v5->m_data, 0, m_size - 1, 0);
  v11 = v5->m_size + 1;
  v12 = v5->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v12 >= v11 )
  {
    resulta[0].m_enum = HK_SUCCESS;
  }
  else
  {
    v13 = 2 * v12;
    if ( v11 < v13 )
      v11 = v13;
    hkArrayUtil::_reserve(resulta, &hkContainerTempAllocator::s_alloc, v5, v11, 4);
    if ( resulta[0].m_enum )
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, v5, 4);
  v5->m_data[v5->m_size] = -1;
  v14 = v5->m_size;
  v5->m_size = v14;
  if ( invalidateOppEdges )
  {
    v15 = 0;
    if ( v14 > 0 )
    {
      v16 = 0i64;
      do
      {
        v17 = 0;
        v18 = &graph->m_nodes.m_data[v5->m_data[v16]];
        if ( v18->m_numEdges > 0 )
        {
          do
          {
            m_data = graph->m_edges.m_data;
            m_target = m_data[v17 + v18->m_startEdgeIndex].m_target;
            if ( m_target != -1 )
              m_data[m_target & 0x3FFFFF].m_target = -1;
            ++v17;
          }
          while ( v17 < v18->m_numEdges );
        }
        ++v15;
        ++v16;
      }
      while ( v15 < v5->m_size );
    }
  }
  v21 = graph->m_nodes.m_size;
  v22 = 0x80000000;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  v86 = 0i64;
  v87 = 0;
  v88 = 0x80000000;
  if ( v21 <= 0 )
  {
    resulta[0].m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(resulta, &hkContainerTempAllocator::s_alloc, &array, v21, 4);
    if ( resulta[0].m_enum )
    {
LABEL_24:
      result->m_enum = HK_FAILURE;
LABEL_25:
      v87 = 0;
      if ( v88 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v86, 4 * v88);
      v86 = 0i64;
      v88 = 0x80000000;
      array.m_size = 0;
      if ( array.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          array.m_data,
          4 * array.m_capacityAndFlags);
      return result;
    }
    v22 = v88;
  }
  array.m_size = v21;
  v23 = graph->m_edges.m_size;
  v24 = v22 & 0x3FFFFFFF;
  if ( v24 < v23 )
  {
    v25 = 2 * v24;
    v26 = graph->m_edges.m_size;
    if ( v23 < v25 )
      v26 = v25;
    hkArrayUtil::_reserve(v92, &hkContainerTempAllocator::s_alloc, &v86, v26, 4);
    if ( v92[0].m_enum )
      goto LABEL_24;
  }
  v27 = graph->m_edges.m_size;
  v87 = v23;
  nodeIndices.m_data = 0i64;
  nodeIndices.m_size = 0;
  nodeIndices.m_capacityAndFlags = 0x80000000;
  if ( v27 > 0 )
  {
    hkArrayUtil::_reserve(resulta, &hkContainerHeapAllocator::s_alloc, &nodeIndices, v27, 4);
    if ( resulta[0].m_enum )
    {
      m_capacityAndFlags = nodeIndices.m_capacityAndFlags;
      result->m_enum = HK_FAILURE;
      nodeIndices.m_size = 0;
      if ( m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          nodeIndices.m_data,
          4 * m_capacityAndFlags);
      nodeIndices.m_data = 0i64;
      nodeIndices.m_capacityAndFlags = 0x80000000;
      goto LABEL_25;
    }
  }
  hkaiGraphUtils::createEdgeToNodeMap(graph, &nodeIndices);
  v29 = graph->m_nodes.m_size;
  v89 = 0;
  v93 = 0i64;
  v94 = 0;
  v30 = (v29 + 31) >> 5;
  v95 = 0x80000000;
  v31 = v30;
  if ( v30 )
  {
    resulta[0].m_enum = 4 * v30;
    v32 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, resulta);
    v31 = resulta[0].m_enum / 4;
  }
  else
  {
    v32 = 0i64;
  }
  v33 = 0x80000000;
  v93 = v32;
  if ( v31 )
    v33 = v31;
  v94 = (v29 + 31) >> 5;
  v96 = v29;
  v95 = v33;
  v34 = v33 & 0x3FFFFFFF;
  if ( (v33 & 0x3FFFFFFF) < v30 )
  {
    v35 = (v29 + 31) >> 5;
    if ( v30 < 2 * v34 )
      v35 = 2 * v34;
    hkArrayUtil::_reserve(resulta, &hkContainerHeapAllocator::s_alloc, &v93, v35, 4);
    v33 = v95;
  }
  v94 = (v29 + 31) >> 5;
  if ( v93 )
  {
    v36 = v30 - 1;
    if ( v36 >= 0 )
    {
      v37 = (unsigned int)(v36 + 1);
      v38 = v93;
      while ( v37 )
      {
        *v38++ = 0;
        --v37;
      }
      v33 = v95;
    }
    v39 = v5->m_data;
    v40 = 0;
    if ( graph->m_nodes.m_size > 0 )
    {
      do
      {
        if ( v40 == *v39 )
        {
          v93[(__int64)v40 >> 5] |= 1 << (v40 & 0x1F);
          ++v39;
        }
        ++v40;
      }
      while ( v40 < graph->m_nodes.m_size );
      v33 = v95;
    }
    v41 = nodeIndices.m_data;
    v42 = 0;
    m_enum = 0;
    resulta[0].m_enum = HK_SUCCESS;
    if ( graph->m_edges.m_size > 0 )
    {
      do
      {
        v44 = m_enum;
        m_numEdges = HK_FAILURE;
        v46 = m_enum;
        v92[0].m_enum = HK_FAILURE;
        v47 = nodeIndices.m_data[v46];
        if ( (int)v47 >= 0 )
        {
          m_numEdges = graph->m_nodes.m_data[v47].m_numEdges;
          v92[0].m_enum = m_numEdges;
        }
        v48 = 0;
        v39 = 0i64;
        if ( m_numEdges >= 4 )
        {
          si128 = _mm_load_si128((const __m128i *)&_xmm);
          v50 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v89), 0);
          v51 = _mm_shuffle_epi32(_mm_cvtsi32_si128(m_enum), 0);
          do
          {
            v52 = v48 + m_enum;
            v53 = _mm_cvtsi32_si128(v48);
            v48 += 4;
            ++v39;
            *(__m128i *)&v86[4 * v52] = _mm_sub_epi32(
                                          _mm_add_epi32(_mm_add_epi32(_mm_shuffle_epi32(v53, 0), si128), v51),
                                          v50);
          }
          while ( v48 < (int)(m_numEdges - (m_numEdges & 0x80000003)) );
          v44 = m_enum;
        }
        v54 = m_numEdges;
        if ( (__int64)v39 >= (int)m_numEdges )
        {
          v56 = v89;
        }
        else
        {
          v55 = (char *)v39 + v44;
          v56 = v89;
          v57 = 4i64 * (_QWORD)v55;
          v58 = m_enum + v48 - v89;
          v59 = v54 - (_QWORD)v39;
          do
          {
            v57 += 4i64;
            *(_DWORD *)&v86[v57 - 4] = v58++;
            --v59;
          }
          while ( v59 );
          m_numEdges = v92[0].m_enum;
          m_enum = resulta[0].m_enum;
        }
        if ( (int)v47 < 0 || ((v93[v47 >> 5] >> (v47 & 0x1F)) & 1) != 0 )
        {
          v89 = m_numEdges + v56;
        }
        else if ( v54 > 0 )
        {
          v60 = m_enum - v42;
          do
          {
            copyEdgeAndData_0(graph, v42, v60 + v42);
            ++v41;
            v61 = nodeIndices.m_data[v46];
            ++v42;
            ++v46;
            *(v41 - 1) = v61;
            --v54;
          }
          while ( v54 );
          m_enum = resulta[0].m_enum;
        }
        m_enum += v92[0].m_enum;
        resulta[0].m_enum = m_enum;
      }
      while ( m_enum < graph->m_edges.m_size );
      v33 = v95;
      v5 = v98;
    }
    v62 = v5->m_data;
    v63 = 0;
    v64 = 0;
    if ( graph->m_nodes.m_size > 0 )
    {
      v65 = v98;
      v66 = 0i64;
      do
      {
        array.m_data[v66] = v64 - (v62 - v65->m_data);
        if ( v64 == *v62 )
          ++v62;
        else
          copyNodeAndData(graph, v63++, v64);
        ++v64;
        ++v66;
      }
      while ( v64 < graph->m_nodes.m_size );
      v33 = v95;
      v5 = v98;
    }
    v94 = 0;
    if ( v33 >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _DWORD *, _QWORD, int *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        v93,
        (unsigned int)(4 * v33),
        v39);
    hkaiDirectedGraphExplicitCost::setNodesSize(graph, (hkResult *)&v98, graph->m_nodes.m_size - v5->m_size);
    hkaiDirectedGraphExplicitCost::setEdgesSize(graph, (hkResult *)&v98, graph->m_edges.m_size - v89);
    v68 = 0;
    if ( graph->m_nodes.m_size > 0 )
    {
      v67 = 0i64;
      do
      {
        v69 = &graph->m_nodes.m_data[v67 / 8];
        v70 = v69->m_numEdges;
        if ( v70 )
        {
          v71 = 0;
          v69->m_startEdgeIndex = *(_DWORD *)&v86[4 * v69->m_startEdgeIndex];
          if ( v70 > 0 )
          {
            do
            {
              v72 = &graph->m_edges.m_data[v71 + v69->m_startEdgeIndex];
              v73 = v72->m_target;
              if ( v73 != -1 )
                v72->m_target = array.m_data[v73 & 0x3FFFFF];
              ++v71;
            }
            while ( v71 < v69->m_numEdges );
          }
        }
        ++v68;
        v67 += 8i64;
      }
      while ( v68 < graph->m_nodes.m_size );
    }
    v74 = otherGraphs;
    if ( otherGraphs )
    {
      v75 = 0;
      LODWORD(v98) = 0;
      if ( graph->m_streamingSets.m_size > 0 )
      {
        v76 = 0i64;
        *(_QWORD *)&v92[0].m_enum = 0i64;
        do
        {
          v77 = 0;
          v78 = (hkaiStreamingSet *)((char *)graph->m_streamingSets.m_data + v76);
          if ( v74->m_size > 0 )
          {
            v79 = 0i64;
            *(_QWORD *)&resulta[0].m_enum = 0i64;
            do
            {
              v80 = 0;
              v81 = *(__int64 *)((char *)v74->m_data + v79);
              if ( *(int *)(v81 + 112) > 0 )
              {
                v82 = 0i64;
                do
                {
                  v83 = (hkaiStreamingSet *)(v82 + *(_QWORD *)(v81 + 104));
                  if ( v78->m_thisUid == v83->m_oppositeUid && v78->m_oppositeUid == v83->m_thisUid )
                    reindexStreamingSets(v78, v83, &array);
                  ++v80;
                  v82 += 56i64;
                }
                while ( v80 < *(_DWORD *)(v81 + 112) );
                v79 = *(_QWORD *)&resulta[0].m_enum;
                v74 = otherGraphs;
              }
              v79 += 8i64;
              ++v77;
              *(_QWORD *)&resulta[0].m_enum = v79;
            }
            while ( v77 < v74->m_size );
            v75 = (int)v98;
            v76 = *(_QWORD *)&v92[0].m_enum;
          }
          ++v75;
          v76 += 56i64;
          LODWORD(v98) = v75;
          *(_QWORD *)&v92[0].m_enum = v76;
        }
        while ( v75 < graph->m_streamingSets.m_size );
      }
    }
    v84 = nodeIndices.m_capacityAndFlags;
    result->m_enum = HK_SUCCESS;
    nodeIndices.m_size = 0;
    if ( v84 >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, _QWORD, unsigned __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        nodeIndices.m_data,
        (unsigned int)(4 * v84),
        v67);
    nodeIndices.m_data = 0i64;
    nodeIndices.m_capacityAndFlags = 0x80000000;
    v87 = 0;
    if ( v88 >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, char *, _QWORD, unsigned __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        v86,
        (unsigned int)(4 * v88),
        v67);
    v86 = 0i64;
    v88 = 0x80000000;
    array.m_size = 0;
    if ( array.m_capacityAndFlags >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, int *, _QWORD, unsigned __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        array.m_data,
        (unsigned int)(4 * array.m_capacityAndFlags),
        v67);
    return result;
  }
  else
  {
    result->m_enum = HK_FAILURE;
    v94 = 0;
    if ( v33 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, 0i64, 4 * v33);
    v93 = 0i64;
    v95 = 0x80000000;
    nodeIndices.m_size = 0;
    if ( nodeIndices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        nodeIndices.m_data,
        4 * nodeIndices.m_capacityAndFlags);
    nodeIndices.m_data = 0i64;
    nodeIndices.m_capacityAndFlags = 0x80000000;
    v87 = 0;
    if ( v88 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v86, 4 * v88);
    v86 = 0i64;
    v88 = 0x80000000;
    array.m_size = 0;
    if ( array.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        array.m_data,
        4 * array.m_capacityAndFlags);
    return result;
  }
}r::s_alloc,
        array.m_data,
        4 * array.m_capacityAndFlags);
    return result;
  }
}

// File Line: 623
// RVA: 0xC040C0
hkResult *__fastcall hkaiGraphUtils::removeEmptyNodes(
        hkResult *result,
        hkaiDirectedGraphExplicitCost *graph,
        hkArray<hkaiDirectedGraphExplicitCost *,hkContainerHeapAllocator> *otherGraphs)
{
  int m_size; // r9d
  int v4; // ebx
  int m_capacityAndFlags; // r10d
  __int64 v9; // rdi
  hkArray<int,hkContainerTempAllocator> array; // [rsp+30h] [rbp-18h] BYREF

  m_size = 0;
  v4 = 0;
  m_capacityAndFlags = 0x80000000;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  if ( graph->m_nodes.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      if ( !graph->m_nodes.m_data[v9].m_numEdges )
      {
        if ( m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 4);
          m_size = array.m_size;
        }
        array.m_data[m_size] = v4;
        m_capacityAndFlags = array.m_capacityAndFlags;
        m_size = ++array.m_size;
      }
      ++v4;
      ++v9;
    }
    while ( v4 < graph->m_nodes.m_size );
  }
  hkaiGraphUtils::removeNodes(result, graph, &array, 1, otherGraphs);
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      4 * array.m_capacityAndFlags);
  return result;
}


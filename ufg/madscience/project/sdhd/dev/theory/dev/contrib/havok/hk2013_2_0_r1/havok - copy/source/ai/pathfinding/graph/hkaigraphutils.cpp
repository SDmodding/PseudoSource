// File Line: 18
// RVA: 0xC03770
signed __int64 __fastcall hkaiGraphUtils::getEdgeBetween(hkaiDirectedGraphExplicitCost *graph, unsigned int nodeIn, unsigned int targetNode)
{
  hkaiDirectedGraphExplicitCost::Node *v3; // rax
  int v4; // er9
  hkaiDirectedGraphExplicitCost::Node *v5; // r11
  int v6; // edx
  signed __int64 result; // rax

  v3 = graph->m_nodes.m_data;
  v4 = v3[nodeIn].m_numEdges;
  v5 = &v3[nodeIn];
  v6 = 0;
  if ( v4 <= 0 )
    return 0xFFFFFFFFi64;
  result = (unsigned int)v5->m_startEdgeIndex;
  while ( graph->m_edges.m_data[(signed int)result].m_target != targetNode )
  {
    ++v6;
    result = (unsigned int)(result + 1);
    if ( v6 >= v4 )
      return 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 33
// RVA: 0xC037B0
signed __int64 __fastcall hkaiGraphUtils::getEdgeBetween(hkaiStreamingCollection *collection, unsigned int nodeIn, unsigned int targetNode)
{
  unsigned int v3; // er11
  int v4; // ebp
  signed int v5; // edx
  __int64 v6; // r11
  unsigned int v7; // er15
  hkaiDirectedGraphInstance *v8; // r8
  hkaiDirectedGraphExplicitCost::Node *v9; // rax
  __int64 v10; // r14
  int v11; // esi
  int v12; // ebx
  int v13; // edi
  signed int v14; // edx
  hkaiDirectedGraphExplicitCost::Edge *v15; // rax
  __int64 v16; // rcx
  unsigned int v17; // er10
  unsigned int v18; // ecx
  int v19; // eax
  __int64 v20; // rcx
  hkaiDirectedGraphExplicitCost::Node v21; // rax
  int v23; // ebx
  int v24; // edi
  hkaiDirectedGraphExplicitCost::Edge *v25; // rax
  __int64 v26; // rcx
  unsigned int v27; // er10
  unsigned int v28; // ecx
  int v29; // eax

  v3 = nodeIn;
  v4 = 0;
  v5 = nodeIn & 0x3FFFFF;
  v6 = v3 >> 22;
  v7 = targetNode;
  if ( (signed int)v6 >= 0 )
    v8 = collection->m_instances.m_data[v6].m_clusterGraphInstance;
  else
    v8 = 0i64;
  v9 = v8->m_originalNodes;
  v10 = v5;
  v11 = v9[v5].m_numEdges;
  v12 = 0;
  if ( v11 > 0 )
  {
    v13 = v8->m_numOriginalEdges;
    v14 = v9[v5].m_startEdgeIndex;
    do
    {
      if ( v14 >= v13 )
      {
        v16 = v14 - v13;
        v15 = v8->m_ownedEdges.m_data;
      }
      else
      {
        v15 = v8->m_originalEdges;
        v16 = v14;
      }
      v17 = v15[v16].m_target;
      if ( v15[v16].m_flags.m_storage & 0x40 )
        v18 = v17 & 0xFFC00000;
      else
        v18 = v8->m_runtimeId << 22;
      v19 = v18 | v17 & 0x3FFFFF;
      if ( v17 == -1 )
        v19 = -1;
      if ( v19 == v7 )
        return (unsigned int)v14 | ((_DWORD)v6 << 22);
      ++v12;
      ++v14;
    }
    while ( v12 < v11 );
  }
  if ( v8->m_nodeMap.m_size && (v20 = v8->m_nodeMap.m_data[v10], (_DWORD)v20 != -1) )
  {
    v21 = v8->m_instancedNodes.m_data[v20];
    v4 = *(_QWORD *)&v8->m_instancedNodes.m_data[v20] >> 32;
    v14 = (signed int)v8->m_instancedNodes.m_data[v20];
  }
  else
  {
    v14 = -1;
    v21.m_numEdges = 0;
  }
  if ( v21.m_numEdges > 0 )
  {
    v23 = v8->m_numOriginalEdges;
    v24 = -v14;
    while ( 1 )
    {
      if ( v14 >= v23 )
      {
        v26 = v14 - v23;
        v25 = v8->m_ownedEdges.m_data;
      }
      else
      {
        v25 = v8->m_originalEdges;
        v26 = v14;
      }
      v27 = v25[v26].m_target;
      v28 = v25[v26].m_flags.m_storage & 0x40 ? v27 & 0xFFC00000 : v8->m_runtimeId << 22;
      v29 = v28 | v27 & 0x3FFFFF;
      if ( v27 == -1 )
        v29 = -1;
      if ( v29 == v7 )
        break;
      if ( v24 + ++v14 >= v4 )
        return 0xFFFFFFFFi64;
    }
    return (unsigned int)v14 | ((_DWORD)v6 << 22);
  }
  return 0xFFFFFFFFi64;
}

// File Line: 65
// RVA: 0xC03940
void __fastcall hkaiGraphUtils::checkSymmetric(hkaiDirectedGraphExplicitCost *graph)
{
  __int64 v1; // rbp
  int v2; // er9
  __int64 v3; // rbx
  hkaiDirectedGraphExplicitCost *v4; // r14
  hkaiDirectedGraphExplicitCost::Node *v5; // rdi
  int v6; // ecx
  hkaiDirectedGraphExplicitCost::Edge *v7; // rsi
  __int64 v8; // r11
  unsigned int *v9; // r10
  unsigned int v10; // eax
  __int64 v11; // rax
  __int64 v12; // rdx
  __int64 v13; // r8
  unsigned int *v14; // rax

  v1 = graph->m_nodes.m_size;
  v2 = 0;
  v3 = 0i64;
  v4 = graph;
  if ( v1 > 0 )
  {
    v5 = graph->m_nodes.m_data;
    do
    {
      v6 = v5[v3].m_numEdges;
      if ( v6 > 0 )
      {
        v7 = v4->m_edges.m_data;
        v8 = (unsigned int)v6;
        v9 = &v7[v5[v3].m_startEdgeIndex].m_target;
        do
        {
          v10 = *v9;
          if ( *v9 != -1 )
          {
            v11 = v10 & 0x3FFFFF;
            v12 = 0i64;
            v13 = v5[v11].m_numEdges;
            if ( v13 > 0 )
            {
              v14 = &v7[v5[v11].m_startEdgeIndex].m_target;
              do
              {
                if ( (*v14 & 0x3FFFFF) == v2 )
                  break;
                ++v12;
                v14 += 2;
              }
              while ( v12 < v13 );
            }
          }
          v9 += 2;
          --v8;
        }
        while ( v8 );
      }
      ++v3;
      ++v2;
    }
    while ( v3 < v1 );
  }
}

// File Line: 92
// RVA: 0xC03A10
void __fastcall hkaiGraphUtils::addDirectedGraphEdgeForUserEdge(unsigned int startFaceKey, unsigned int userEdgeKey, hkaiStreamingCollection *collection)
{
  hkaiGraphUtils::_adjustDirectedGraphEdge(startFaceKey, userEdgeKey, collection, GRAPH_ADD_EDGE);
}

// File Line: 98
// RVA: 0xC03A30
void __fastcall hkaiGraphUtils::removeDirectedGraphEdgeForUserEdge(unsigned int startFaceKey, unsigned int userEdgeKey, hkaiStreamingCollection *collection)
{
  hkaiGraphUtils::_adjustDirectedGraphEdge(startFaceKey, userEdgeKey, collection, GRAPH_REMOVE_EDGE);
}

// File Line: 103
// RVA: 0xC04B50
void __fastcall hkaiGraphUtils::_adjustDirectedGraphEdge(unsigned int startFaceKey, unsigned int userEdgeKey, hkaiStreamingCollection *collection, hkaiGraphUtils::Adjustment adj)
{
  hkaiStreamingCollection::InstanceInfo *v4; // rbx
  unsigned int v5; // er12
  __int64 v6; // rdi
  hkaiNavMeshInstance *v7; // rsi
  int v8; // ebp
  int index; // er12
  hkaiNavMesh::Edge *v10; // rax
  char v11; // cl
  unsigned int v12; // edx
  unsigned int v13; // eax
  unsigned int v14; // ecx
  __int64 v15; // r14
  hkaiNavMeshInstance *v16; // r13
  __int64 v17; // r11
  __int64 v18; // r15
  int v19; // edi
  hkaiDirectedGraphInstance *v20; // r9
  hkaiDirectedGraphExplicitCost::Node *v21; // rax
  int v22; // er8
  int v23; // ebx
  int v24; // er10
  hkaiDirectedGraphExplicitCost::Edge *v25; // rax
  __int64 v26; // rcx
  unsigned int v27; // er11
  signed __int64 v28; // rdx
  unsigned int v29; // ecx
  int v30; // eax
  __int64 v31; // rcx
  hkaiDirectedGraphExplicitCost::Node v32; // rax
  __int16 v33; // ax
  int v34; // eax
  hkaiDirectedGraphExplicitCost::Edge *v35; // rcx
  __int64 v36; // rdx
  unsigned int v37; // ebx
  signed __int64 v38; // r11
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
  hkVector4f v49; // [rsp+30h] [rbp-88h]
  hkVector4f v50; // [rsp+40h] [rbp-78h]
  hkVector4f edgeB; // [rsp+50h] [rbp-68h]
  hkVector4f edgeA; // [rsp+60h] [rbp-58h]
  float v53; // [rsp+C0h] [rbp+8h]
  unsigned int v54; // [rsp+C8h] [rbp+10h]
  hkaiGraphUtils::Adjustment v55; // [rsp+D8h] [rbp+20h]

  v55 = adj;
  v4 = collection->m_instances.m_data;
  v5 = userEdgeKey;
  v6 = userEdgeKey >> 22;
  v54 = userEdgeKey >> 22;
  v7 = v4[v6].m_instancePtr;
  v8 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__11(
         v7->m_originalFaces,
         v7->m_numOriginalFaces,
         &v7->m_instancedFaces,
         &v7->m_ownedFaces,
         &v7->m_faceMap,
         startFaceKey & 0x3FFFFF)->m_clusterIndex;
  if ( v8 != -1 )
  {
    index = v5 & 0x3FFFFF;
    v10 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__12(
            v7->m_originalEdges,
            v7->m_numOriginalEdges,
            &v7->m_instancedEdges,
            &v7->m_ownedEdges,
            &v7->m_edgeMap,
            index);
    v49.m_quad.m128_u64[0] = (unsigned __int64)v10;
    if ( v10->m_oppositeEdge != -1 )
    {
      v11 = v10->m_flags.m_storage;
      if ( !(v11 & 0x20) )
      {
        v12 = v10->m_oppositeFace;
        if ( v11 & 0x40 )
          v13 = v12 & 0xFFC00000;
        else
          v13 = v7->m_runtimeId << 22;
        v14 = v13 | v12 & 0x3FFFFF;
        if ( v12 == -1 )
          v14 = -1;
        v15 = v14 >> 22;
        v16 = v4[v15].m_instancePtr;
        v18 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__11(
                v16->m_originalFaces,
                v16->m_numOriginalFaces,
                &v16->m_instancedFaces,
                &v16->m_ownedFaces,
                &v16->m_faceMap,
                v14 & 0x3FFFFF)->m_clusterIndex;
        if ( (_DWORD)v18 != -1 )
        {
          v19 = v8 | ((_DWORD)v6 << 22);
          if ( v19 != ((unsigned int)v18 | ((_DWORD)v15 << 22)) && (signed int)v15 >= 0 )
          {
            v20 = (hkaiDirectedGraphInstance *)*((_QWORD *)&v4->m_clusterGraphInstance + v17);
            if ( v20 )
            {
              v21 = v20->m_originalNodes;
              v22 = v21[v18].m_startEdgeIndex;
              v23 = v22 + v21[v18].m_numEdges;
              if ( v22 >= v23 )
              {
LABEL_25:
                if ( v20->m_nodeMap.m_size && (v31 = v20->m_nodeMap.m_data[v18], (_DWORD)v31 != -1) )
                {
                  v32 = v20->m_instancedNodes.m_data[v31];
                  v22 = (int)v20->m_instancedNodes.m_data[v31];
                }
                else
                {
                  v22 = -1;
                  v32.m_numEdges = 0;
                }
                v32.m_startEdgeIndex = v22 + v32.m_numEdges;
                if ( v22 >= v22 + v32.m_numEdges )
                {
LABEL_42:
                  if ( v55 == 1 )
                  {
                    v41 = hkaiDirectedGraphInstance::addEdgeForNode(v20, (unsigned int)v18, 0i64);
                    hkaiNavMeshInstance::getEdgePoints(v7, index, &edgeA, &edgeB);
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
                    v53 = COERCE_FLOAT(
                            _mm_andnot_ps(
                              _mm_cmpleps(v46, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v46, v47), v47)),
                                  _mm_mul_ps(*(__m128 *)_xmm, v47)),
                                v46)))
                        * 1.0039062;
                    v41->m_cost.m_value = HIWORD(v53);
                    v41->m_flags.m_storage = 2;
                    if ( v54 != (_DWORD)v15 )
                      v41->m_flags.m_storage = 66;
                  }
                  return;
                }
                v24 = v20->m_numOriginalEdges;
                while ( 1 )
                {
                  if ( v22 >= v24 )
                  {
                    v36 = v22 - v24;
                    v35 = v20->m_ownedEdges.m_data;
                  }
                  else
                  {
                    v35 = v20->m_originalEdges;
                    v36 = v22;
                  }
                  v37 = v35[v36].m_target;
                  v38 = (signed __int64)&v35[v36];
                  if ( v35[v36].m_flags.m_storage & 0x40 )
                    v39 = v37 & 0xFFC00000;
                  else
                    v39 = v20->m_runtimeId << 22;
                  v40 = v39 | v37 & 0x3FFFFF;
                  if ( v37 == -1 )
                    v40 = -1;
                  if ( v40 == v19 )
                    break;
                  if ( ++v22 >= v34 )
                    goto LABEL_42;
                }
                v33 = *(_WORD *)(v38 + 2);
              }
              else
              {
                v24 = v20->m_numOriginalEdges;
                while ( 1 )
                {
                  if ( v22 >= v24 )
                  {
                    v26 = v22 - v24;
                    v25 = v20->m_ownedEdges.m_data;
                  }
                  else
                  {
                    v25 = v20->m_originalEdges;
                    v26 = v22;
                  }
                  v27 = v25[v26].m_target;
                  v28 = (signed __int64)&v25[v26];
                  if ( v25[v26].m_flags.m_storage & 0x40 )
                    v29 = v27 & 0xFFC00000;
                  else
                    v29 = v20->m_runtimeId << 22;
                  v30 = v29 | v27 & 0x3FFFFF;
                  if ( v27 == -1 )
                    v30 = -1;
                  if ( v30 == v19 )
                    break;
                  if ( ++v22 >= v23 )
                    goto LABEL_25;
                }
                v33 = *(_WORD *)(v28 + 2);
              }
              if ( v33 & 2 )
              {
                if ( v22 >= v24 )
                {
                  v48 = v22 - v24;
                  v20->m_userEdgeCount.m_data[v48] += v55;
                  if ( !v20->m_userEdgeCount.m_data[v48] )
                    hkaiDirectedGraphInstance::removeOwnedEdgeForNode(v20, (unsigned int)v18, v22);
                }
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
  __int64 v1; // r14
  hkaiDirectedGraphInstance *v2; // rbx
  int v3; // edi
  hkLifoAllocator *v4; // rax
  char *v5; // rcx
  int v6; // edx
  char *v7; // r8
  signed int v8; // eax
  int v9; // eax
  int v10; // er9
  int v11; // eax
  _DWORD *v12; // rdi
  __int64 i; // rcx
  hkResultEnum v14; // edi
  int v15; // er11
  __int64 v16; // rsi
  __int64 v17; // rcx
  hkaiDirectedGraphExplicitCost::Node v18; // rax
  int v19; // edx
  int v20; // eax
  int v21; // er10
  __int64 v22; // r9
  __int64 v23; // rdi
  char v24; // cl
  int v25; // er9
  hkaiDirectedGraphExplicitCost::Edge *v26; // rax
  __int64 v27; // rdi
  int v28; // er11
  int v29; // esi
  int v30; // er8
  __int64 v31; // r9
  __int64 v32; // r13
  hkaiDirectedGraphExplicitCost::Edge *v33; // r14
  hkaiDirectedGraphExplicitCost::Edge *v34; // rdx
  signed __int64 v35; // rdi
  signed __int64 v36; // rcx
  signed __int64 v37; // r10
  unsigned int *v38; // rcx
  char *v39; // rdi
  char *v40; // rdx
  int v41; // eax
  __int64 v42; // rcx
  signed __int64 v43; // rdi
  int v44; // eax
  int v45; // er14
  int v46; // eax
  int v47; // eax
  int v48; // er9
  int v49; // eax
  int v50; // eax
  int v51; // er9
  int v52; // edi
  int v53; // eax
  int v54; // eax
  int v55; // er9
  __int64 v56; // r10
  int v57; // er8
  __int64 v58; // rdi
  __int64 v59; // rcx
  hkaiDirectedGraphExplicitCost::Node *v60; // rdx
  __int64 v61; // rax
  int v62; // eax
  __int64 v63; // rsi
  int *v64; // rdi
  int v65; // er8
  int v66; // er8
  __int64 v67; // [rsp+30h] [rbp-40h]
  int v68; // [rsp+38h] [rbp-38h]
  int v69; // [rsp+3Ch] [rbp-34h]
  _DWORD *array; // [rsp+40h] [rbp-30h]
  int v71; // [rsp+48h] [rbp-28h]
  unsigned int v72; // [rsp+4Ch] [rbp-24h]
  char *v73; // [rsp+50h] [rbp-20h]
  int v74; // [rsp+58h] [rbp-18h]
  int v75; // [rsp+60h] [rbp-10h]
  hkResult result; // [rsp+B0h] [rbp+40h]
  hkResult v77; // [rsp+B8h] [rbp+48h]
  __int64 v78; // [rsp+C0h] [rbp+50h]

  v1 = graph->m_ownedEdges.m_size;
  v2 = graph;
  array = 0i64;
  v71 = 0;
  v3 = ((signed int)v1 + 31) >> 5;
  v72 = 2147483648;
  v74 = v3;
  if ( v3 )
  {
    v4 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (char *)v4->m_cur;
    v6 = (4 * v3 + 127) & 0xFFFFFF80;
    v7 = &v5[v6];
    if ( v6 > v4->m_slabSize || v7 > v4->m_end )
      v5 = (char *)hkLifoAllocator::allocateFromNewSlab(v4, v6);
    else
      v4->m_cur = v7;
  }
  else
  {
    v5 = 0i64;
  }
  array = v5;
  v73 = v5;
  v75 = v1;
  v72 = v3 | 0x80000000;
  v8 = (v3 | 0x80000000) & 0x3FFFFFFF;
  if ( v8 < v3 )
  {
    v9 = 2 * v8;
    v10 = ((signed int)v1 + 31) >> 5;
    if ( v3 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v10, 4);
  }
  v11 = v3 - 1;
  v71 = ((signed int)v1 + 31) >> 5;
  if ( v3 - 1 >= 0 )
  {
    v12 = array;
    for ( i = (unsigned int)(v11 + 1); i; --i )
    {
      *v12 = 0;
      ++v12;
    }
  }
  v14 = v2->m_numOriginalEdges;
  v15 = 0;
  result.m_enum = v2->m_numOriginalEdges;
  if ( v2->m_numOriginalNodes > 0 )
  {
    v16 = 0i64;
    do
    {
      if ( v2->m_nodeMap.m_size && (v17 = v2->m_nodeMap.m_data[v16], (_DWORD)v17 != -1) )
      {
        v18 = v2->m_instancedNodes.m_data[v17];
        v78 = (__int64)v2->m_instancedNodes.m_data[v17];
        v19 = v78;
      }
      else
      {
        v19 = -1;
        v78 = 0xFFFFFFFFi64;
        v18.m_numEdges = 0;
      }
      v18.m_startEdgeIndex = v19 + v18.m_numEdges;
      if ( v19 < v19 + v18.m_numEdges )
      {
        v21 = -(signed int)v14;
        v22 = v19 - v14;
        do
        {
          v23 = v22++;
          v24 = (v21 + v19++) & 0x1F;
          array[v23 >> 5] |= 1 << v24;
        }
        while ( v19 < v20 );
        v14 = result.m_enum;
      }
      ++v15;
      ++v16;
    }
    while ( v15 < v2->m_numOriginalNodes );
  }
  v67 = 0i64;
  v68 = 0;
  v69 = 2147483648;
  if ( (signed int)v1 > 0 )
  {
    v25 = v1;
    if ( (signed int)v1 < 0 )
      v25 = 0;
    hkArrayUtil::_reserve((hkResult *)&v78, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v67, v25, 4);
  }
  v26 = v2->m_ownedEdges.m_data;
  v27 = (__int64)v2->m_userEdgeCount.m_data;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0i64;
  v68 = v1;
  v32 = v1;
  if ( (signed int)v1 > 0 )
  {
    v33 = v26;
    do
    {
      *(_DWORD *)(v67 + 4 * v31) = v30 - v28;
      if ( (array[(signed __int64)v30 >> 5] >> (v30 & 0x1F)) & 1 )
      {
        v34 = v33;
        v35 = v27 + 4;
        v36 = (signed __int64)&v2->m_ownedEdges.m_data[v31];
        v78 = v35;
        ++v33;
        v34->m_cost.m_value = *(_WORD *)v36;
        v34->m_flags.m_storage = *(_WORD *)(v36 + 2);
        v34->m_target = *(_DWORD *)(v36 + 4);
        *(_DWORD *)(v35 - 4) = v2->m_userEdgeCount.m_data[v31];
        v37 = v2->m_edgeDataStriding;
        v38 = v2->m_ownedEdgeData.m_data;
        v39 = (char *)&v38[v30 * v2->m_edgeDataStriding];
        v40 = (char *)&v38[v29 * v2->m_edgeDataStriding];
        if ( (_DWORD)v37 == 1 )
        {
          v41 = *(_DWORD *)v39;
          v27 = v78;
          ++v29;
          *(_DWORD *)v40 = v41;
        }
        else
        {
          v42 = v2->m_edgeDataStriding;
          if ( v37 >= 1 )
          {
            v43 = v39 - v40;
            do
            {
              v44 = *(_DWORD *)&v40[v43];
              v40 += 4;
              *((_DWORD *)v40 - 1) = v44;
              --v42;
            }
            while ( v42 );
          }
          v27 = v78;
          ++v29;
        }
      }
      else
      {
        ++v28;
      }
      ++v31;
      ++v30;
    }
    while ( v31 < v32 );
    LODWORD(v1) = v32;
  }
  v45 = v1 - v28;
  v46 = v2->m_ownedEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v46 < v45 )
  {
    v47 = 2 * v46;
    v48 = v45;
    if ( v45 < v47 )
      v48 = v47;
    hkArrayUtil::_reserve(
      &v77,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v2->m_ownedEdges,
      v48,
      8);
  }
  v2->m_ownedEdges.m_size = v45;
  v49 = v2->m_userEdgeCount.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v49 < v45 )
  {
    v50 = 2 * v49;
    v51 = v45;
    if ( v45 < v50 )
      v51 = v50;
    hkArrayUtil::_reserve(
      &v77,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v2->m_userEdgeCount,
      v51,
      4);
  }
  v2->m_userEdgeCount.m_size = v45;
  v52 = v45 * v2->m_edgeDataStriding;
  v53 = v2->m_ownedEdgeData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v53 < v52 )
  {
    v54 = 2 * v53;
    v55 = v45 * v2->m_edgeDataStriding;
    if ( v52 < v54 )
      v55 = v54;
    hkArrayUtil::_reserve(
      &v77,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v2->m_ownedEdgeData,
      v55,
      4);
  }
  v56 = result.m_enum;
  v2->m_ownedEdgeData.m_size = v52;
  v57 = 0;
  if ( v2->m_numOriginalNodes > 0 )
  {
    v58 = 0i64;
    do
    {
      if ( v2->m_nodeMap.m_size )
      {
        v59 = v2->m_nodeMap.m_data[v58];
        if ( (_DWORD)v59 != -1 )
        {
          v60 = &v2->m_instancedNodes.m_data[v59];
          if ( v60 )
          {
            v61 = v60->m_startEdgeIndex;
            if ( (signed int)v61 > 0 )
              v60->m_startEdgeIndex = v56 + *(_DWORD *)(v67 + 4 * (v61 - v56));
          }
        }
      }
      ++v57;
      ++v58;
    }
    while ( v57 < v2->m_numOriginalNodes );
  }
  v62 = v2->m_freeEdgeBlocks.m_size - 1;
  v63 = v62;
  if ( v62 >= 0 )
  {
    v64 = &v2->m_freeEdgeBlocks.m_data->m_blocks.m_capacityAndFlags + 4 * v62;
    do
    {
      v65 = *v64;
      *(v64 - 1) = 0;
      if ( v65 >= 0 )
        ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _QWORD, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerHeapAllocator::s_alloc,
          *(_QWORD *)(v64 - 3),
          (unsigned int)(4 * v65),
          v31);
      *(_QWORD *)(v64 - 3) = 0i64;
      *v64 = 2147483648;
      v64 -= 4;
      --v63;
    }
    while ( v63 >= 0 );
  }
  v66 = v69;
  v2->m_freeEdgeBlocks.m_size = 0;
  v68 = 0;
  if ( v66 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v67,
      (unsigned int)(4 * v66),
      v31);
  v67 = 0i64;
  v69 = 2147483648;
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>((hkBitFieldStorage<hkLocalArray<unsigned int> > *)&array);
}

// File Line: 302
// RVA: 0xC03A40
void __fastcall hkaiGraphUtils::removeDirectedUserEdgesToSection(hkaiStreamingCollection *collection, int sectionIndex)
{
  hkaiStreamingCollection *v2; // r8
  int v3; // ecx
  __int64 v4; // r13
  int v5; // er12
  __int64 v6; // rdx
  hkaiDirectedGraphInstance *v7; // rdi
  int v8; // er14
  __int64 v9; // r15
  __int64 v10; // rcx
  hkaiDirectedGraphExplicitCost::Node *v11; // rdx
  int v12; // ebp
  int v13; // ebx
  signed __int64 v14; // rsi
  int v15; // ecx
  signed __int64 v16; // rcx
  __int16 v17; // ax
  int v18; // edx
  unsigned int v19; // eax
  unsigned int v20; // ecx
  hkaiStreamingCollection *v21; // [rsp+60h] [rbp+8h]
  int v22; // [rsp+70h] [rbp+18h]
  __int64 v23; // [rsp+78h] [rbp+20h]

  v21 = collection;
  v2 = collection;
  v3 = 0;
  v4 = 0i64;
  v5 = sectionIndex;
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
                    v12 = v11->m_startEdgeIndex;
                    if ( v11->m_startEdgeIndex != -1 )
                    {
                      v13 = v11->m_numEdges + v12 - 1;
                      if ( v13 >= v12 )
                      {
                        v14 = v13;
                        do
                        {
                          v15 = v7->m_numOriginalEdges;
                          if ( v13 >= v15 )
                            v16 = (signed __int64)&v7->m_ownedEdges.m_data[v13 - v15];
                          else
                            v16 = (signed __int64)&v7->m_originalEdges[v14];
                          v17 = *(_WORD *)(v16 + 2);
                          if ( v17 & 2 && v17 & 0x40 )
                          {
                            v18 = *(_DWORD *)(v16 + 4);
                            if ( v17 & 0x40 )
                              v19 = v18 & 0xFFC00000;
                            else
                              v19 = v7->m_runtimeId << 22;
                            v20 = v19 | v18 & 0x3FFFFF;
                            if ( v18 == -1 )
                              v20 = -1;
                            if ( v20 >> 22 == v5 )
                              hkaiDirectedGraphInstance::removeOwnedEdgeForNode(v7, (unsigned int)v8, v13);
                          }
                          --v13;
                          --v14;
                        }
                        while ( v13 >= v12 );
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
            v2 = v21;
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
void __fastcall copyStructAndData_hkVector4f_int_(hkVector4f *dstT, int *dstData, hkVector4f *srcT, const int *srcData, int dataStride)
{
  __int64 v5; // rcx
  signed __int64 v6; // r9
  int v7; // eax

  *dstT = (hkVector4f)srcT->m_quad;
  if ( dataStride == 1 )
  {
    *dstData = *srcData;
  }
  else
  {
    v5 = dataStride;
    if ( dataStride >= 1i64 )
    {
      v6 = (char *)srcData - (char *)dstData;
      do
      {
        v7 = *(int *)((char *)dstData + v6);
        ++dstData;
        *(dstData - 1) = v7;
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
  int dataStride; // er10
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
    v5 = &graph->m_edgeData.m_data[(signed int)v4 * dataStride];
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
  int dataStride; // er10
  __int64 v4; // rbx
  hkaiDirectedGraphExplicitCost *v5; // rdi
  const unsigned int *v6; // r9
  unsigned int *v7; // rdx
  __int64 v8; // r11

  dataStride = graph->m_nodeDataStriding;
  v4 = dstIdx;
  v5 = graph;
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
  copyStructAndData_hkVector4f_int_(&v5->m_positions.m_data[v4], 0i64, &v5->m_positions.m_data[v8], 0i64, 0);
}

// File Line: 358
// RVA: 0xC05250
void __fastcall getNodes(hkaiDirectedGraphExplicitCost *graph, const int n, hkArrayBase<hkaiDirectedGraphExplicitCost::Node> *nodesOut)
{
  nodesOut->m_data[nodesOut->m_size++] = graph->m_nodes.m_data[n];
}

// File Line: 365
// RVA: 0xC05280
void __fastcall getNodes_0(hkaiDirectedGraphInstance *graphInstance, const int n, hkArrayBase<hkaiDirectedGraphExplicitCost::Node> *nodesOut)
{
  __int64 v3; // rbx
  hkaiDirectedGraphInstance *v4; // r11
  __int64 v5; // rcx
  hkaiDirectedGraphExplicitCost::Node *v6; // rdx
  __int64 v7; // rcx

  v3 = n;
  v4 = graphInstance;
  nodesOut->m_data[nodesOut->m_size] = graphInstance->m_originalNodes[n];
  v5 = nodesOut->m_size + 1;
  nodesOut->m_size += 2;
  v6 = &nodesOut->m_data[v5];
  if ( v4->m_nodeMap.m_size && (v7 = v4->m_nodeMap.m_data[v3], (_DWORD)v7 != -1) )
  {
    *v6 = v4->m_instancedNodes.m_data[v7];
  }
  else
  {
    v6->m_startEdgeIndex = -1;
    v6->m_numEdges = 0;
  }
}

// File Line: 376
// RVA: 0xC05500
void __fastcall _createEdgeToNodeMap<hkaiDirectedGraphInstance>(hkaiDirectedGraphInstance *graph, hkArray<int,hkContainerHeapAllocator> *nodeIndices)
{
  int v2; // eax
  hkArray<int,hkContainerHeapAllocator> *v3; // rsi
  int v4; // eax
  int v5; // ebx
  hkaiDirectedGraphInstance *v6; // rbp
  int v7; // eax
  int v8; // er9
  __int64 v9; // rdx
  int *v10; // rdi
  __int64 v11; // rcx
  int i; // ebx
  int v13; // ecx
  __int64 v14; // r9
  __int64 v15; // r10
  hkaiDirectedGraphExplicitCost::Node *v16; // r8
  __int64 v17; // rax
  int v18; // edi
  __int64 v19; // rdx
  hkArrayBase<hkaiDirectedGraphExplicitCost::Node> nodesOut; // [rsp+30h] [rbp-38h]
  char v21; // [rsp+40h] [rbp-28h]
  hkResult result; // [rsp+70h] [rbp+8h]

  v2 = nodeIndices->m_capacityAndFlags;
  v3 = nodeIndices;
  nodeIndices->m_size = 0;
  v4 = v2 & 0x3FFFFFFF;
  v5 = graph->m_numOriginalEdges + graph->m_ownedEdges.m_size;
  v6 = graph;
  if ( v4 < v5 )
  {
    v7 = 2 * v4;
    v8 = graph->m_numOriginalEdges + graph->m_ownedEdges.m_size;
    if ( v5 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, nodeIndices, v8, 4);
  }
  v9 = v3->m_size;
  v10 = &v3->m_data[v9];
  v11 = v5 - (signed int)v9;
  if ( v5 - (signed int)v9 > 0 )
  {
    while ( v11 )
    {
      *v10 = -1;
      ++v10;
      --v11;
    }
  }
  v3->m_size = v5;
  for ( i = 0; i < v6->m_numOriginalNodes; ++i )
  {
    nodesOut.m_size = 0;
    nodesOut.m_capacityAndFlags = -2147483646;
    nodesOut.m_data = (hkaiDirectedGraphExplicitCost::Node *)&v21;
    getNodes_0(v6, i, &nodesOut);
    v13 = nodesOut.m_size;
    v14 = 0i64;
    if ( nodesOut.m_size > 0 )
    {
      v15 = 0i64;
      do
      {
        v16 = nodesOut.m_data;
        v17 = 0i64;
        v18 = 0;
        if ( nodesOut.m_data[v15].m_numEdges > 0 )
        {
          do
          {
            ++v18;
            v19 = v17++ + v16[v15].m_startEdgeIndex;
            v3->m_data[v19] = i;
          }
          while ( v18 < v16[v15].m_numEdges );
          v13 = nodesOut.m_size;
        }
        v14 = (unsigned int)(v14 + 1);
        ++v15;
      }
      while ( (signed int)v14 < v13 );
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
void __fastcall hkaiGraphUtils::createEdgeToNodeMap(hkaiDirectedGraphExplicitCost *graph, hkArray<int,hkContainerHeapAllocator> *nodeIndices)
{
  _createEdgeToNodeMap<hkaiDirectedGraphExplicitCost>(graph, nodeIndices);
}

// File Line: 401
// RVA: 0xC04B40
void __fastcall hkaiGraphUtils::createEdgeToNodeMap(hkaiDirectedGraphInstance *graphInstance, hkArray<int,hkContainerHeapAllocator> *nodeIndices)
{
  _createEdgeToNodeMap<hkaiDirectedGraphInstance>(graphInstance, nodeIndices);
}

// File Line: 406
// RVA: 0xC05300
void __fastcall reindexStreamingSets(hkaiStreamingSet *thisSet, hkaiStreamingSet *otherSet, hkArrayBase<int> *nodeRemap)
{
  int v3; // er9
  hkArrayBase<int> *v4; // rsi
  hkaiStreamingSet *v5; // r10
  int v6; // ebx
  hkaiStreamingSet *v7; // rdi
  __int64 v8; // r11
  hkaiStreamingSet::GraphConnection *v9; // rdx
  __int64 v10; // rcx
  __int64 v11; // r8
  hkaiStreamingSet::GraphConnection *v12; // rdx
  __int64 v13; // rcx

  v3 = 0;
  v4 = nodeRemap;
  v5 = otherSet;
  v6 = 0;
  v7 = thisSet;
  if ( thisSet->m_graphConnections.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      v9 = v7->m_graphConnections.m_data;
      ++v6;
      v10 = v9[v8].m_nodeIndex;
      ++v8;
      v9[v8 - 1].m_nodeIndex = nodeRemap->m_data[v10];
    }
    while ( v6 < v7->m_graphConnections.m_size );
  }
  if ( v5->m_graphConnections.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      v12 = v5->m_graphConnections.m_data;
      ++v3;
      v13 = v12[v11].m_oppositeNodeIndex;
      ++v11;
      *((_DWORD *)&v12[v11] - 3) = v4->m_data[v13];
    }
    while ( v3 < v5->m_graphConnections.m_size );
  }
}

// File Line: 421
// RVA: 0xC041D0
hkResult *__fastcall hkaiGraphUtils::removeNodes(hkResult *result, hkaiDirectedGraphExplicitCost *graph, hkArray<int,hkContainerTempAllocator> *nodesToRemove, bool invalidateOppEdges, hkArray<hkaiDirectedGraphExplicitCost *,hkContainerHeapAllocator> *otherGraphs)
{
  hkArray<int,hkContainerTempAllocator> *v5; // rsi
  int v6; // er8
  bool v7; // di
  hkaiDirectedGraphExplicitCost *v8; // r13
  hkResult *v9; // r14
  hkResult *v10; // rax
  int v11; // er9
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // er9
  __int64 v16; // r10
  int v17; // edx
  hkaiDirectedGraphExplicitCost::Node *v18; // r8
  hkaiDirectedGraphExplicitCost::Edge *v19; // rdi
  unsigned int v20; // ecx
  int v21; // edi
  unsigned int v22; // eax
  int v23; // er9
  int v24; // edi
  int v25; // eax
  int v26; // eax
  int v27; // er9
  int v28; // er9
  int v29; // er8
  int v30; // ebx
  int v31; // edi
  __int32 v32; // ecx
  _DWORD *v33; // r8
  signed int v34; // eax
  int v35; // ecx
  int v36; // er9
  int v37; // edi
  __int64 v38; // rcx
  _DWORD *v39; // rdi
  int *v40; // r9
  int v41; // er8
  int *v42; // r12
  int v43; // ebx
  hkResultEnum v44; // er8
  __int64 v45; // r11
  hkResultEnum v46; // edi
  __int64 v47; // r14
  __int64 v48; // r10
  hkaiDirectedGraphExplicitCost::Node *v49; // rax
  signed int v50; // edx
  __m128i v51; // xmm3
  __m128i v52; // xmm2
  __m128i v53; // xmm1
  int v54; // eax
  __m128i v55; // xmm0
  __int64 v56; // rsi
  char *v57; // rdi
  unsigned int v58; // er11
  signed __int64 v59; // rdi
  int v60; // edx
  __int64 v61; // r8
  int v62; // edi
  int v63; // ecx
  int *v64; // rbx
  int v65; // er14
  int v66; // edi
  hkArray<int,hkContainerTempAllocator> *v67; // r12
  __int64 v68; // rsi
  unsigned __int64 v69; // r9
  int v70; // er10
  hkaiDirectedGraphExplicitCost::Node *v71; // rdi
  signed int v72; // er8
  signed int v73; // edx
  signed __int64 v74; // r8
  int v75; // ecx
  hkArray<hkaiDirectedGraphExplicitCost *,hkContainerHeapAllocator> *v76; // rdx
  int v77; // ecx
  __int64 v78; // rdi
  int v79; // er12
  hkaiStreamingSet *v80; // rsi
  __int64 v81; // rcx
  int v82; // ebx
  __int64 v83; // r14
  __int64 v84; // rdi
  hkaiStreamingSet *v85; // rdx
  int v86; // er8
  hkResult resulta[2]; // [rsp+30h] [rbp-41h]
  char *v88; // [rsp+38h] [rbp-39h]
  int v89; // [rsp+40h] [rbp-31h]
  int v90; // [rsp+44h] [rbp-2Dh]
  unsigned int v91; // [rsp+48h] [rbp-29h]
  hkArray<int,hkContainerHeapAllocator> nodeIndices; // [rsp+50h] [rbp-21h]
  char *array; // [rsp+60h] [rbp-11h]
  int v94; // [rsp+68h] [rbp-9h]
  int v95; // [rsp+6Ch] [rbp-5h]
  hkResult v96[2]; // [rsp+70h] [rbp-1h]
  _DWORD *v97; // [rsp+78h] [rbp+7h]
  int v98; // [rsp+80h] [rbp+Fh]
  int v99; // [rsp+84h] [rbp+13h]
  int v100; // [rsp+88h] [rbp+17h]
  hkResult *v101; // [rsp+D0h] [rbp+5Fh]
  hkArray<int,hkContainerTempAllocator> *v102; // [rsp+E0h] [rbp+6Fh]

  v102 = nodesToRemove;
  v101 = result;
  v5 = nodesToRemove;
  v6 = nodesToRemove->m_size;
  v7 = invalidateOppEdges;
  v8 = graph;
  v9 = result;
  if ( !v6 )
  {
    v10 = result;
    result->m_enum = 0;
    return v10;
  }
  if ( v6 > 1 )
    hkAlgorithm::quickSortRecursive<int,hkAlgorithm::less<int>>(v5->m_data, 0, v6 - 1, 0);
  v11 = v5->m_size + 1;
  v12 = v5->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v12 >= v11 )
  {
    resulta[0].m_enum = 0;
  }
  else
  {
    v13 = 2 * v12;
    if ( v11 < v13 )
      v11 = v13;
    hkArrayUtil::_reserve(resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v5, v11, 4);
    if ( resulta[0].m_enum )
    {
      v9->m_enum = 1;
      return v9;
    }
  }
  if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v5, 4);
  v5->m_data[v5->m_size] = -1;
  v14 = v5->m_size;
  v5->m_size = v14;
  if ( v7 )
  {
    v15 = 0;
    if ( v14 > 0 )
    {
      v16 = 0i64;
      do
      {
        v17 = 0;
        v18 = &v8->m_nodes.m_data[v5->m_data[v16]];
        if ( v18->m_numEdges > 0 )
        {
          do
          {
            v19 = v8->m_edges.m_data;
            v20 = v19[v17 + v18->m_startEdgeIndex].m_target;
            if ( v20 != -1 )
              v19[v20 & 0x3FFFFF].m_target = -1;
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
  v21 = v8->m_nodes.m_size;
  v22 = 2147483648;
  array = 0i64;
  v94 = 0;
  v95 = 2147483648;
  v88 = 0i64;
  v89 = 0;
  v90 = 2147483648;
  if ( v21 <= 0 )
  {
    resulta[0].m_enum = 0;
  }
  else
  {
    v23 = v21;
    if ( v21 < 0 )
      v23 = 0;
    hkArrayUtil::_reserve(resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v23, 4);
    if ( resulta[0].m_enum )
      goto LABEL_26;
    v22 = v90;
  }
  v94 = v21;
  v24 = v8->m_edges.m_size;
  v25 = v22 & 0x3FFFFFFF;
  if ( v25 < v24 )
  {
    v26 = 2 * v25;
    v27 = v8->m_edges.m_size;
    if ( v24 < v26 )
      v27 = v26;
    hkArrayUtil::_reserve(v96, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v88, v27, 4);
    if ( v96[0].m_enum )
    {
LABEL_26:
      v9->m_enum = 1;
LABEL_27:
      v89 = 0;
      if ( v90 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v88,
          4 * v90);
      v88 = 0i64;
      v90 = 2147483648;
      v94 = 0;
      if ( v95 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          4 * v95);
      return v9;
    }
  }
  v28 = v8->m_edges.m_size;
  v89 = v24;
  nodeIndices.m_data = 0i64;
  nodeIndices.m_size = 0;
  nodeIndices.m_capacityAndFlags = 2147483648;
  if ( v28 > 0 )
  {
    if ( v28 < 0 )
      v28 = 0;
    hkArrayUtil::_reserve(resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &nodeIndices, v28, 4);
    if ( resulta[0].m_enum )
    {
      v29 = nodeIndices.m_capacityAndFlags;
      v9->m_enum = 1;
      nodeIndices.m_size = 0;
      if ( v29 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          nodeIndices.m_data,
          4 * v29);
      nodeIndices.m_data = 0i64;
      nodeIndices.m_capacityAndFlags = 2147483648;
      goto LABEL_27;
    }
  }
  hkaiGraphUtils::createEdgeToNodeMap(v8, &nodeIndices);
  v30 = v8->m_nodes.m_size;
  v91 = 0;
  v97 = 0i64;
  v98 = 0;
  v31 = (v30 + 31) >> 5;
  v99 = 2147483648;
  v32 = v31;
  if ( v31 )
  {
    resulta[0].m_enum = 4 * v31;
    v33 = (_DWORD *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                      (int *)resulta);
    v32 = resulta[0].m_enum / 4;
  }
  else
  {
    v33 = 0i64;
  }
  v34 = 2147483648;
  v97 = v33;
  if ( v32 )
    v34 = v32;
  v98 = (v30 + 31) >> 5;
  v100 = v30;
  v99 = v34;
  v35 = v34 & 0x3FFFFFFF;
  if ( (v34 & 0x3FFFFFFF) < v31 )
  {
    v36 = (v30 + 31) >> 5;
    if ( v31 < 2 * v35 )
      v36 = 2 * v35;
    hkArrayUtil::_reserve(resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v97, v36, 4);
    v34 = v99;
  }
  v98 = (v30 + 31) >> 5;
  if ( v97 )
  {
    v37 = v31 - 1;
    if ( v37 >= 0 )
    {
      v38 = (unsigned int)(v37 + 1);
      v39 = v97;
      while ( v38 )
      {
        *v39 = 0;
        ++v39;
        --v38;
      }
      v34 = v99;
    }
    v40 = v5->m_data;
    v41 = 0;
    if ( v8->m_nodes.m_size > 0 )
    {
      do
      {
        if ( v41 == *v40 )
        {
          v97[(signed __int64)v41 >> 5] |= 1 << (v41 & 0x1F);
          ++v40;
        }
        ++v41;
      }
      while ( v41 < v8->m_nodes.m_size );
      v34 = v99;
    }
    v42 = nodeIndices.m_data;
    v43 = 0;
    v44 = 0;
    resulta[0].m_enum = 0;
    if ( v8->m_edges.m_size > 0 )
    {
      do
      {
        v45 = v44;
        v46 = 1;
        v47 = v44;
        v96[0].m_enum = 1;
        v48 = nodeIndices.m_data[v47];
        if ( (signed int)v48 >= 0 )
        {
          v49 = v8->m_nodes.m_data;
          v46 = v49[v48].m_numEdges;
          v96[0] = (hkResult)v49[v48].m_numEdges;
        }
        v50 = 0;
        v40 = 0i64;
        if ( (signed int)v46 > 0 && (unsigned int)v46 >= 4 )
        {
          v51 = _mm_load_si128((const __m128i *)&_xmm);
          v52 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v91), 0);
          v53 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v44), 0);
          do
          {
            v54 = v50 + v44;
            v55 = _mm_cvtsi32_si128(v50);
            v50 += 4;
            ++v40;
            _mm_storeu_si128(
              (__m128i *)&v88[4 * v54],
              _mm_sub_epi32(_mm_add_epi32(_mm_add_epi32(_mm_shuffle_epi32(v55, 0), v51), v53), v52));
          }
          while ( v50 < v46 - v46 % 4 );
          v45 = v44;
        }
        v56 = v46;
        if ( (signed __int64)v40 >= (signed int)v46 )
        {
          v58 = v91;
        }
        else
        {
          v57 = (char *)v40 + v45;
          v58 = v91;
          v59 = 4i64 * (_QWORD)v57;
          v60 = v44 + v50 - v91;
          v61 = v56 - (_QWORD)v40;
          do
          {
            v59 += 4i64;
            *(_DWORD *)&v88[v59 - 4] = v60++;
            --v61;
          }
          while ( v61 );
          v46 = v96[0].m_enum;
          v44 = resulta[0].m_enum;
        }
        if ( (signed int)v48 < 0 || (v97[v48 >> 5] >> (v48 & 0x1F)) & 1 )
        {
          v91 = v46 + v58;
        }
        else if ( v56 > 0 )
        {
          v62 = v44 - v43;
          do
          {
            copyEdgeAndData_0(v8, v43, v62 + v43);
            ++v42;
            v63 = nodeIndices.m_data[v47];
            ++v43;
            ++v47;
            *(v42 - 1) = v63;
            --v56;
          }
          while ( v56 );
          v44 = resulta[0].m_enum;
        }
        v44 += v96[0].m_enum;
        resulta[0].m_enum = v44;
      }
      while ( v44 < v8->m_edges.m_size );
      v34 = v99;
      v5 = v102;
    }
    v64 = v5->m_data;
    v65 = 0;
    v66 = 0;
    if ( v8->m_nodes.m_size > 0 )
    {
      v67 = v102;
      v68 = 0i64;
      do
      {
        *(_DWORD *)&array[v68] = v66 - (unsigned __int64)(v64 - v67->m_data);
        if ( v66 == *v64 )
          ++v64;
        else
          copyNodeAndData(v8, v65++, v66);
        ++v66;
        v68 += 4i64;
      }
      while ( v66 < v8->m_nodes.m_size );
      v34 = v99;
      v5 = v102;
    }
    v98 = 0;
    if ( v34 >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _DWORD *, _QWORD, int *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        v97,
        (unsigned int)(4 * v34),
        v40);
    hkaiDirectedGraphExplicitCost::setNodesSize(v8, (hkResult *)&v102, v8->m_nodes.m_size - v5->m_size);
    hkaiDirectedGraphExplicitCost::setEdgesSize(v8, (hkResult *)&v102, v8->m_edges.m_size - v91);
    v70 = 0;
    if ( v8->m_nodes.m_size > 0 )
    {
      v69 = 0i64;
      do
      {
        v71 = &v8->m_nodes.m_data[v69 / 8];
        v72 = v71->m_numEdges;
        if ( v72 )
        {
          v73 = 0;
          v71->m_startEdgeIndex = *(_DWORD *)&v88[4 * v71->m_startEdgeIndex];
          if ( v72 > 0 )
          {
            do
            {
              v74 = (signed __int64)&v8->m_edges.m_data[v73 + v71->m_startEdgeIndex];
              v75 = *(_DWORD *)(v74 + 4);
              if ( v75 != -1 )
                *(_DWORD *)(v74 + 4) = *(_DWORD *)&array[4 * (v75 & 0x3FFFFF)];
              ++v73;
            }
            while ( v73 < v71->m_numEdges );
          }
        }
        ++v70;
        v69 += 8i64;
      }
      while ( v70 < v8->m_nodes.m_size );
    }
    v76 = otherGraphs;
    if ( otherGraphs )
    {
      v77 = 0;
      LODWORD(v102) = 0;
      if ( v8->m_streamingSets.m_size > 0 )
      {
        v78 = 0i64;
        *(_QWORD *)&v96[0].m_enum = 0i64;
        do
        {
          v79 = 0;
          v80 = (hkaiStreamingSet *)((char *)v8->m_streamingSets.m_data + v78);
          if ( v76->m_size > 0 )
          {
            v81 = 0i64;
            *(_QWORD *)&resulta[0].m_enum = 0i64;
            do
            {
              v82 = 0;
              v83 = *(__int64 *)((char *)v76->m_data + v81);
              if ( *(_DWORD *)(v83 + 112) > 0 )
              {
                v84 = 0i64;
                do
                {
                  v85 = (hkaiStreamingSet *)(v84 + *(_QWORD *)(v83 + 104));
                  if ( v80->m_thisUid == v85->m_oppositeUid && v80->m_oppositeUid == v85->m_thisUid )
                    reindexStreamingSets(v80, v85, (hkArrayBase<int> *)&array);
                  ++v82;
                  v84 += 56i64;
                }
                while ( v82 < *(_DWORD *)(v83 + 112) );
                v81 = *(_QWORD *)&resulta[0].m_enum;
                v76 = otherGraphs;
              }
              v81 += 8i64;
              ++v79;
              *(_QWORD *)&resulta[0].m_enum = v81;
            }
            while ( v79 < v76->m_size );
            v77 = (signed int)v102;
            v78 = *(_QWORD *)&v96[0].m_enum;
          }
          ++v77;
          v78 += 56i64;
          LODWORD(v102) = v77;
          *(_QWORD *)&v96[0].m_enum = v78;
        }
        while ( v77 < v8->m_streamingSets.m_size );
      }
    }
    v86 = nodeIndices.m_capacityAndFlags;
    v101->m_enum = 0;
    nodeIndices.m_size = 0;
    if ( v86 >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, _QWORD, unsigned __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        nodeIndices.m_data,
        (unsigned int)(4 * v86),
        v69);
    nodeIndices.m_data = 0i64;
    nodeIndices.m_capacityAndFlags = 2147483648;
    v89 = 0;
    if ( v90 >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, char *, _QWORD, unsigned __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        v88,
        (unsigned int)(4 * v90),
        v69);
    v88 = 0i64;
    v90 = 2147483648;
    v94 = 0;
    if ( v95 >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, char *, _QWORD, unsigned __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        array,
        (unsigned int)(4 * v95),
        v69);
    v10 = v101;
  }
  else
  {
    v9->m_enum = 1;
    v98 = 0;
    if ( v34 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        0i64,
        4 * v34);
    v97 = 0i64;
    v99 = 2147483648;
    nodeIndices.m_size = 0;
    if ( nodeIndices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        nodeIndices.m_data,
        4 * nodeIndices.m_capacityAndFlags);
    nodeIndices.m_data = 0i64;
    nodeIndices.m_capacityAndFlags = 2147483648;
    v89 = 0;
    if ( v90 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v88,
        4 * v90);
    v88 = 0i64;
    v90 = 2147483648;
    v94 = 0;
    if ( v95 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        4 * v95);
    v10 = v9;
  }
  return v10;
}yAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        4 * v95);
    v10 = v9;
  }
  return v10;
}

// File Line: 623
// RVA: 0xC040C0
hkResult *__fastcall hkaiGraphUtils::removeEmptyNodes(hkResult *result, hkaiDirectedGraphExplicitCost *graph, hkArray<hkaiDirectedGraphExplicitCost *,hkContainerHeapAllocator> *otherGraphs)
{
  int v3; // er9
  int v4; // ebx
  unsigned int v5; // er10
  hkaiDirectedGraphExplicitCost *v6; // rsi
  hkResult *v7; // rbp
  hkArray<hkaiDirectedGraphExplicitCost *,hkContainerHeapAllocator> *v8; // r14
  __int64 v9; // rdi
  _DWORD *array; // [rsp+30h] [rbp-18h]
  int v12; // [rsp+38h] [rbp-10h]
  int v13; // [rsp+3Ch] [rbp-Ch]

  v3 = 0;
  v4 = 0;
  v5 = 2147483648;
  v6 = graph;
  v7 = result;
  array = 0i64;
  v8 = otherGraphs;
  v12 = 0;
  v13 = 2147483648;
  if ( graph->m_nodes.m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      if ( !v6->m_nodes.m_data[v9].m_numEdges )
      {
        if ( v3 == (v5 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 4);
          v3 = v12;
        }
        array[v3] = v4;
        v5 = v13;
        v3 = v12++ + 1;
      }
      ++v4;
      ++v9;
    }
    while ( v4 < v6->m_nodes.m_size );
  }
  hkaiGraphUtils::removeNodes(v7, v6, (hkArray<int,hkContainerTempAllocator> *)&array, 1, v8);
  v12 = 0;
  if ( v13 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v13);
  return v7;
}


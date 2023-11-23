// File Line: 29
// RVA: 0xBFE430
void __fastcall hkaiStreamingManager::loadVolumeInstance(
        hkaiNavVolumeInstance *volumeInstance,
        hkaiStreamingCollection *collection)
{
  int v2; // ebx
  hkaiStreamingCollection *v3; // rsi
  hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *p_m_streamingSets; // rax
  hkaiNavVolumeInstance *v5; // rbp
  __int64 v6; // rdi
  char *v7; // r15
  int v8; // r14d
  __int64 v9; // r12
  __int64 v10; // rax
  __int64 v11; // rbx
  __int64 v12; // r13
  int v13; // edx
  hkaiNavVolumeInstance *m_volumeInstancePtr; // rsi
  int v15; // ebp
  int v16; // edi
  hkaiNavVolume::Edge *v17; // rax
  hkaiNavVolume::Edge *v18; // rax
  hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *v19; // [rsp+20h] [rbp-58h]
  int v22; // [rsp+90h] [rbp+18h]
  __int64 v23; // [rsp+98h] [rbp+20h]

  v2 = 0;
  v3 = collection;
  p_m_streamingSets = &volumeInstance->m_originalVolume.m_pntr->m_streamingSets;
  v5 = volumeInstance;
  v22 = 0;
  v19 = p_m_streamingSets;
  if ( volumeInstance->m_originalVolume.m_pntr->m_streamingSets.m_size > 0 )
  {
    v6 = 0i64;
    v23 = 0i64;
    do
    {
      v7 = (char *)p_m_streamingSets->m_data + v6;
      if ( *(_DWORD *)v7 == v5->m_sectionUid )
      {
        LODWORD(v10) = hkaiStreamingCollection::findVolumeIdByUid(v3, *((_DWORD *)v7 + 1));
        v8 = 0;
        v9 = (int)v10;
        v10 = (int)v10;
        if ( *((int *)v7 + 12) > 0 )
        {
          v11 = 0i64;
          do
          {
            v12 = *((_QWORD *)v7 + 5);
            if ( (_DWORD)v9 != -1 )
            {
              v13 = *(_DWORD *)(v12 + v11);
              m_volumeInstancePtr = v3->m_instances.m_data[v10].m_volumeInstancePtr;
              v15 = v13 | (v5->m_runtimeId << 22);
              v16 = *(_DWORD *)(v12 + v11 + 4) | ((_DWORD)v9 << 22);
              v17 = hkaiNavVolumeInstance::addEdgeForCell(volumeInstance, v13);
              v17->m_oppositeCell = v16;
              v17->m_flags.m_storage = 64;
              v18 = hkaiNavVolumeInstance::addEdgeForCell(m_volumeInstancePtr, *(_DWORD *)(v12 + v11 + 4));
              v3 = collection;
              v18->m_oppositeCell = v15;
              v5 = volumeInstance;
              v18->m_flags.m_storage = 64;
              v10 = v9;
            }
            ++v8;
            v11 += 8i64;
          }
          while ( v8 < *((_DWORD *)v7 + 12) );
          v2 = v22;
          v6 = v23;
        }
      }
      p_m_streamingSets = v19;
      ++v2;
      v6 += 56i64;
      v22 = v2;
      v23 = v6;
    }
    while ( v2 < v19->m_size );
  }
}

// File Line: 73
// RVA: 0xBFE5A0
void __fastcall hkaiStreamingManager::unloadVolumeInstance(
        hkaiNavVolumeInstance *volumeInstance,
        hkaiStreamingCollection *collection)
{
  int v2; // r9d
  hkaiStreamingCollection *v3; // rbx
  __int64 v5; // r8
  int v6; // r12d
  hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *p_m_streamingSets; // rax
  __int64 v8; // rdi
  char *v9; // r15
  int VolumeIdByUid; // eax
  int v11; // ebp
  hkaiNavVolumeInstance *m_volumeInstancePtr; // rbx
  __int64 v13; // r14
  __int64 v14; // rsi
  __int64 v15; // rdx
  hkaiNavVolumeInstance::CellInstance v16; // rax
  int m_numEdges; // edx
  int m_startEdgeIndex; // r8d
  hkaiNavVolume::Edge *m_data; // rdi
  int v20; // r10d
  __int64 v22; // [rsp+80h] [rbp+18h]
  hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *v23; // [rsp+88h] [rbp+20h]

  v2 = 0;
  v3 = collection;
  volumeInstance->m_ownedEdges.m_size = 0;
  if ( volumeInstance->m_instancedCells.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      ++v2;
      volumeInstance->m_instancedCells.m_data[v5++].m_startEdgeIndex = -1;
      volumeInstance->m_instancedCells.m_data[v5 - 1].m_numEdges = 0;
    }
    while ( v2 < volumeInstance->m_instancedCells.m_size );
  }
  v6 = 0;
  p_m_streamingSets = &volumeInstance->m_originalVolume.m_pntr->m_streamingSets;
  v23 = p_m_streamingSets;
  if ( volumeInstance->m_originalVolume.m_pntr->m_streamingSets.m_size > 0 )
  {
    v8 = 0i64;
    v22 = 0i64;
    do
    {
      v9 = (char *)p_m_streamingSets->m_data + v8;
      if ( *(_DWORD *)v9 == volumeInstance->m_sectionUid )
      {
        VolumeIdByUid = hkaiStreamingCollection::findVolumeIdByUid(v3, *((_DWORD *)v9 + 1));
        if ( VolumeIdByUid != -1 )
        {
          v11 = 0;
          m_volumeInstancePtr = v3->m_instances.m_data[VolumeIdByUid].m_volumeInstancePtr;
          if ( *((int *)v9 + 12) > 0 )
          {
            v13 = 0i64;
            do
            {
              v14 = *((_QWORD *)v9 + 5);
              if ( !m_volumeInstancePtr->m_cellMap.m_size
                || (v15 = m_volumeInstancePtr->m_cellMap.m_data[*(int *)(v14 + v13 + 4)], (_DWORD)v15 == -1) )
              {
                m_startEdgeIndex = -1;
                m_numEdges = 0;
                v16.m_numEdges = 0;
              }
              else
              {
                v16 = m_volumeInstancePtr->m_instancedCells.m_data[v15];
                m_numEdges = v16.m_numEdges;
                m_startEdgeIndex = v16.m_startEdgeIndex;
              }
              if ( v16.m_numEdges > 0 )
              {
                m_data = m_volumeInstancePtr->m_ownedEdges.m_data;
                v20 = -m_startEdgeIndex;
                while ( (m_data[m_startEdgeIndex - m_volumeInstancePtr->m_numOriginalEdges].m_flags.m_storage & 0x40) == 0
                     || m_data[m_startEdgeIndex - m_volumeInstancePtr->m_numOriginalEdges].m_oppositeCell != (*(_DWORD *)(v14 + v13) | (volumeInstance->m_runtimeId << 22)) )
                {
                  ++m_startEdgeIndex;
                  if ( v20 + m_startEdgeIndex >= m_numEdges )
                    goto LABEL_21;
                }
                hkaiNavVolumeInstance::removeOwnedEdgeForCell(
                  m_volumeInstancePtr,
                  *(_DWORD *)(v14 + v13 + 4),
                  m_startEdgeIndex);
              }
LABEL_21:
              ++v11;
              v13 += 8i64;
            }
            while ( v11 < *((_DWORD *)v9 + 12) );
            v8 = v22;
          }
          v3 = collection;
        }
      }
      p_m_streamingSets = v23;
      v8 += 56i64;
      ++v6;
      v22 = v8;
    }
    while ( v6 < v23->m_size );
  }
}

// File Line: 129
// RVA: 0xBFDE60
void __fastcall hkaiStreamingManager::loadGraphInstance(
        hkaiDirectedGraphInstance *graphInstance,
        hkaiStreamingCollection *collection)
{
  int v2; // r15d
  hkaiStreamingCollection *v3; // rbx
  hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *p_m_streamingSets; // rax
  hkaiDirectedGraphInstance *v5; // r9
  __int64 v6; // rsi
  hkaiStreamingSet *m_data; // rbp
  int GraphIdByUid; // eax
  int v9; // r12d
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // rax
  hkaiDirectedGraphExplicitCost *m_pntr; // rbx
  int v12; // edi
  hkaiStreamingSet *v13; // r14
  int v14; // r12d
  __int64 v15; // rbx
  hkaiStreamingSet::GraphConnection *v16; // r13
  int v17; // eax
  int m_nodeIndex; // edx
  __int64 v19; // r15
  hkaiDirectedGraphExplicitCost::Edge *v20; // r14
  hkaiDirectedGraphExplicitCost::Edge *v21; // rax
  __m128 m_quad; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm4
  __m128 v26; // xmm3
  __m128 v27; // xmm1
  unsigned int v28; // xmm4_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  int v31; // [rsp+20h] [rbp-D8h]
  hkaiDirectedGraphInstance *v32; // [rsp+28h] [rbp-D0h]
  int v33; // [rsp+30h] [rbp-C8h]
  float v34; // [rsp+34h] [rbp-C4h]
  float v35; // [rsp+38h] [rbp-C0h]
  unsigned int *edgeDataPtrOut; // [rsp+40h] [rbp-B8h] BYREF
  unsigned int *v37; // [rsp+48h] [rbp-B0h] BYREF
  hkaiStreamingSet *v38; // [rsp+50h] [rbp-A8h]
  hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *v39; // [rsp+58h] [rbp-A0h]
  int v42; // [rsp+110h] [rbp+18h]

  v2 = 0;
  v3 = collection;
  p_m_streamingSets = &graphInstance->m_originalGraph.m_pntr->m_streamingSets;
  v5 = graphInstance;
  v42 = 0;
  v39 = p_m_streamingSets;
  if ( p_m_streamingSets->m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      m_data = p_m_streamingSets->m_data;
      if ( p_m_streamingSets->m_data[v6].m_thisUid == v5->m_sectionUid )
      {
        GraphIdByUid = hkaiStreamingCollection::findGraphIdByUid(v3, m_data[v6].m_oppositeUid);
        v9 = GraphIdByUid;
        if ( GraphIdByUid != -1 )
        {
          if ( GraphIdByUid >= 0 )
            m_clusterGraphInstance = v3->m_instances.m_data[GraphIdByUid].m_clusterGraphInstance;
          else
            m_clusterGraphInstance = 0i64;
          m_pntr = m_clusterGraphInstance->m_originalGraph.m_pntr;
          v32 = m_clusterGraphInstance;
          v12 = 0;
          v13 = &m_pntr->m_streamingSets.m_data[(int)hkaiStreamingSet::indexOfStreamingSet(
                                                       &m_pntr->m_streamingSets,
                                                       m_data[v6].m_oppositeUid,
                                                       m_data[v6].m_thisUid)];
          v38 = v13;
          if ( m_data[v6].m_graphConnections.m_size > 0 )
          {
            v14 = v9 << 22;
            v15 = 0i64;
            do
            {
              v16 = m_data[v6].m_graphConnections.m_data;
              v17 = hkaiStreamingSet::indexOfGraphConnection(v13, v16[v15].m_oppositeNodeIndex, v16[v15].m_nodeIndex);
              m_nodeIndex = v16[v15].m_nodeIndex;
              v19 = (__int64)&v13->m_graphConnections.m_data[v17];
              v31 = m_nodeIndex | (graphInstance->m_runtimeId << 22);
              v33 = v16[v15].m_oppositeNodeIndex | v14;
              edgeDataPtrOut = 0i64;
              v37 = 0i64;
              v20 = hkaiDirectedGraphInstance::addEdgeForNode(graphInstance, m_nodeIndex, &edgeDataPtrOut);
              v21 = hkaiDirectedGraphInstance::addEdgeForNode(v32, v16[v15].m_oppositeNodeIndex, &v37);
              v5 = graphInstance;
              m_quad = graphInstance->m_originalPositions[v16[v15].m_nodeIndex].m_quad;
              v23 = v32->m_originalPositions[v16[v15].m_oppositeNodeIndex].m_quad;
              v24 = _mm_sub_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(m_quad, m_quad, 0),
                              graphInstance->m_transform.m_rotation.m_col0.m_quad),
                            _mm_mul_ps(
                              _mm_shuffle_ps(m_quad, m_quad, 85),
                              graphInstance->m_transform.m_rotation.m_col1.m_quad)),
                          _mm_mul_ps(
                            _mm_shuffle_ps(m_quad, m_quad, 170),
                            graphInstance->m_transform.m_rotation.m_col2.m_quad)),
                        graphInstance->m_transform.m_translation.m_quad),
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v32->m_transform.m_rotation.m_col0.m_quad),
                            _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v32->m_transform.m_rotation.m_col1.m_quad)),
                          _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v32->m_transform.m_rotation.m_col2.m_quad)),
                        v32->m_transform.m_translation.m_quad));
              v25 = _mm_mul_ps(v24, v24);
              v26 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                      _mm_shuffle_ps(v25, v25, 170));
              v27 = _mm_rsqrt_ps(v26);
              v28 = _mm_andnot_ps(
                      _mm_cmple_ps(v26, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v27), v27)),
                          _mm_mul_ps(*(__m128 *)_xmm, v27)),
                        v26)).m128_u32[0];
              LODWORD(v29) = v16[v15].m_edgeCost.m_value << 16;
              if ( v29 < 0.0 )
                v29 = *(float *)&v28;
              v20->m_flags.m_storage = 64;
              v34 = v29 * 1.0039062;
              v20->m_cost.m_value = HIWORD(v34);
              v20->m_target = v33;
              if ( edgeDataPtrOut )
                *edgeDataPtrOut = v16[v15].m_edgeData;
              LODWORD(v30) = *(__int16 *)(v19 + 12) << 16;
              if ( v30 < 0.0 )
                v30 = *(float *)&v28;
              v21->m_flags.m_storage = 64;
              v35 = v30 * 1.0039062;
              v21->m_cost.m_value = HIWORD(v35);
              v21->m_target = v31;
              if ( v37 )
                *v37 = *(_DWORD *)(v19 + 8);
              v13 = v38;
              ++v12;
              ++v15;
            }
            while ( v12 < m_data[v6].m_graphConnections.m_size );
            v2 = v42;
            v3 = collection;
            goto LABEL_22;
          }
          v3 = collection;
        }
        v5 = graphInstance;
      }
LABEL_22:
      p_m_streamingSets = v39;
      ++v2;
      ++v6;
      v42 = v2;
    }
    while ( v2 < v39->m_size );
  }
}

// File Line: 210
// RVA: 0xBFE230
void __fastcall hkaiStreamingManager::unloadGraphInstance(
        hkaiDirectedGraphInstance *graphInstance,
        hkaiStreamingCollection *collection)
{
  hkaiStreamingCollection *v2; // rbx
  int v4; // r9d
  __int64 v5; // r8
  int v6; // r12d
  hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *p_m_streamingSets; // rax
  __int64 v8; // rdi
  char *v9; // r15
  int GraphIdByUid; // eax
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // rbx
  int v12; // esi
  __int64 v13; // r14
  __int64 v14; // rbp
  __int64 v15; // rdx
  hkaiDirectedGraphExplicitCost::Node v16; // rax
  int m_numEdges; // edx
  int m_startEdgeIndex; // r8d
  hkaiDirectedGraphExplicitCost::Edge *m_data; // rdi
  int v20; // r10d
  __int64 v22; // [rsp+80h] [rbp+18h]
  hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *v23; // [rsp+88h] [rbp+20h]

  v2 = collection;
  hkaiDirectedGraphInstance::clearOwnedEdges(graphInstance);
  v4 = 0;
  if ( graphInstance->m_instancedNodes.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      ++v4;
      graphInstance->m_instancedNodes.m_data[v5++].m_startEdgeIndex = -1;
      graphInstance->m_instancedNodes.m_data[v5 - 1].m_numEdges = 0;
    }
    while ( v4 < graphInstance->m_instancedNodes.m_size );
  }
  v6 = 0;
  p_m_streamingSets = &graphInstance->m_originalGraph.m_pntr->m_streamingSets;
  v23 = p_m_streamingSets;
  if ( graphInstance->m_originalGraph.m_pntr->m_streamingSets.m_size > 0 )
  {
    v8 = 0i64;
    v22 = 0i64;
    do
    {
      v9 = (char *)p_m_streamingSets->m_data + v8;
      if ( *(_DWORD *)v9 == graphInstance->m_sectionUid )
      {
        GraphIdByUid = hkaiStreamingCollection::findGraphIdByUid(v2, *((_DWORD *)v9 + 1));
        if ( GraphIdByUid != -1 )
        {
          if ( GraphIdByUid >= 0 )
            m_clusterGraphInstance = v2->m_instances.m_data[GraphIdByUid].m_clusterGraphInstance;
          else
            m_clusterGraphInstance = 0i64;
          v12 = 0;
          if ( *((int *)v9 + 8) > 0 )
          {
            v13 = 0i64;
            do
            {
              v14 = *((_QWORD *)v9 + 3);
              if ( !m_clusterGraphInstance->m_nodeMap.m_size
                || (v15 = m_clusterGraphInstance->m_nodeMap.m_data[*(int *)(v14 + v13 + 4)], (_DWORD)v15 == -1) )
              {
                m_startEdgeIndex = -1;
                m_numEdges = 0;
                v16.m_numEdges = 0;
              }
              else
              {
                v16 = m_clusterGraphInstance->m_instancedNodes.m_data[v15];
                m_numEdges = v16.m_numEdges;
                m_startEdgeIndex = v16.m_startEdgeIndex;
              }
              if ( v16.m_numEdges > 0 )
              {
                m_data = m_clusterGraphInstance->m_ownedEdges.m_data;
                v20 = -m_startEdgeIndex;
                while ( (m_data[m_startEdgeIndex - m_clusterGraphInstance->m_numOriginalEdges].m_flags.m_storage & 0x40) == 0
                     || m_data[m_startEdgeIndex - m_clusterGraphInstance->m_numOriginalEdges].m_target != (*(_DWORD *)(v14 + v13) | (graphInstance->m_runtimeId << 22)) )
                {
                  ++m_startEdgeIndex;
                  if ( v20 + m_startEdgeIndex >= m_numEdges )
                    goto LABEL_24;
                }
                hkaiDirectedGraphInstance::removeOwnedEdgeForNode(
                  m_clusterGraphInstance,
                  *(_DWORD *)(v14 + v13 + 4),
                  m_startEdgeIndex);
              }
LABEL_24:
              ++v12;
              v13 += 16i64;
            }
            while ( v12 < *((_DWORD *)v9 + 8) );
            v8 = v22;
          }
          v2 = collection;
        }
      }
      p_m_streamingSets = v23;
      v8 += 56i64;
      ++v6;
      v22 = v8;
    }
    while ( v6 < v23->m_size );
  }
}


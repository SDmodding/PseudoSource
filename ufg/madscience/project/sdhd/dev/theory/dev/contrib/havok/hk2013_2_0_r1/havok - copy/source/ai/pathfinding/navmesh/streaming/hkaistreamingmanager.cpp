// File Line: 29
// RVA: 0xBFE430
void __fastcall hkaiStreamingManager::loadVolumeInstance(hkaiNavVolumeInstance *volumeInstance, hkaiStreamingCollection *collection)
{
  int v2; // ebx
  hkaiStreamingCollection *v3; // rsi
  hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *v4; // rax
  hkaiNavVolumeInstance *v5; // rbp
  __int64 v6; // rdi
  char *v7; // r15
  int v8; // er14
  __int64 v9; // r12
  __int64 v10; // rax
  __int64 v11; // rbx
  __int64 v12; // r13
  __int64 v13; // rdx
  hkaiNavVolumeInstance *v14; // rsi
  unsigned int v15; // ebp
  int v16; // edi
  hkaiNavVolume::Edge *v17; // rax
  hkaiNavVolume::Edge *v18; // rax
  hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *v19; // [rsp+20h] [rbp-58h]
  hkaiNavVolumeInstance *v20; // [rsp+80h] [rbp+8h]
  hkaiStreamingCollection *v21; // [rsp+88h] [rbp+10h]
  int v22; // [rsp+90h] [rbp+18h]
  __int64 v23; // [rsp+98h] [rbp+20h]

  v21 = collection;
  v20 = volumeInstance;
  v2 = 0;
  v3 = collection;
  v4 = &volumeInstance->m_originalVolume.m_pntr->m_streamingSets;
  v5 = volumeInstance;
  v22 = 0;
  v19 = &volumeInstance->m_originalVolume.m_pntr->m_streamingSets;
  if ( volumeInstance->m_originalVolume.m_pntr->m_streamingSets.m_size > 0 )
  {
    v6 = 0i64;
    v23 = 0i64;
    do
    {
      v7 = (char *)v4->m_data + v6;
      if ( *(_DWORD *)v7 == v5->m_sectionUid )
      {
        LODWORD(v10) = hkaiStreamingCollection::findVolumeIdByUid(v3, *((_DWORD *)v7 + 1));
        v8 = 0;
        v9 = (signed int)v10;
        v10 = (signed int)v10;
        if ( *((_DWORD *)v7 + 12) > 0 )
        {
          v11 = 0i64;
          do
          {
            v12 = *((_QWORD *)v7 + 5);
            if ( (_DWORD)v9 != -1 )
            {
              v13 = *(unsigned int *)(v12 + v11);
              v14 = v3->m_instances.m_data[v10].m_volumeInstancePtr;
              v15 = v13 | (v5->m_runtimeId << 22);
              v16 = *(_DWORD *)(v12 + v11 + 4) | ((_DWORD)v9 << 22);
              v17 = hkaiNavVolumeInstance::addEdgeForCell(v20, v13);
              v17->m_oppositeCell = v16;
              v17->m_flags.m_storage = 64;
              v18 = hkaiNavVolumeInstance::addEdgeForCell(v14, *(unsigned int *)(v12 + v11 + 4));
              v3 = v21;
              v18->m_oppositeCell = v15;
              v5 = v20;
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
      v4 = v19;
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
void __fastcall hkaiStreamingManager::unloadVolumeInstance(hkaiNavVolumeInstance *volumeInstance, hkaiStreamingCollection *collection)
{
  int v2; // er9
  hkaiStreamingCollection *v3; // rbx
  hkaiNavVolumeInstance *v4; // r13
  __int64 v5; // r8
  int v6; // er12
  hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *v7; // rax
  __int64 v8; // rdi
  char *v9; // r15
  int v10; // eax
  int v11; // ebp
  hkaiNavVolumeInstance *v12; // rbx
  __int64 v13; // r14
  __int64 v14; // rsi
  __int64 v15; // rdx
  hkaiNavVolumeInstance::CellInstance v16; // rax
  int v17; // edx
  int v18; // er8
  hkaiNavVolume::Edge *v19; // rdi
  int v20; // er10
  hkaiNavVolumeInstance::CellInstance v21; // [rsp+70h] [rbp+8h]
  hkaiStreamingCollection *v22; // [rsp+78h] [rbp+10h]
  __int64 v23; // [rsp+80h] [rbp+18h]
  hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *v24; // [rsp+88h] [rbp+20h]

  v22 = collection;
  v2 = 0;
  v3 = collection;
  v4 = volumeInstance;
  volumeInstance->m_ownedEdges.m_size = 0;
  if ( volumeInstance->m_instancedCells.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      ++v2;
      ++v5;
      volumeInstance->m_instancedCells.m_data[v5 - 1].m_startEdgeIndex = -1;
      *((_DWORD *)&volumeInstance->m_instancedCells.m_data[v5] - 1) = 0;
    }
    while ( v2 < volumeInstance->m_instancedCells.m_size );
  }
  v6 = 0;
  v7 = &volumeInstance->m_originalVolume.m_pntr->m_streamingSets;
  v24 = &volumeInstance->m_originalVolume.m_pntr->m_streamingSets;
  if ( volumeInstance->m_originalVolume.m_pntr->m_streamingSets.m_size > 0 )
  {
    v8 = 0i64;
    v23 = 0i64;
    do
    {
      v9 = (char *)v7->m_data + v8;
      if ( *(_DWORD *)v9 == v4->m_sectionUid )
      {
        v10 = hkaiStreamingCollection::findVolumeIdByUid(v3, *((_DWORD *)v9 + 1));
        if ( v10 != -1 )
        {
          v11 = 0;
          v12 = v3->m_instances.m_data[v10].m_volumeInstancePtr;
          if ( *((_DWORD *)v9 + 12) > 0 )
          {
            v13 = 0i64;
            do
            {
              v14 = *((_QWORD *)v9 + 5);
              if ( v12->m_cellMap.m_size
                && (v15 = v12->m_cellMap.m_data[*(signed int *)(v14 + v13 + 4)], (_DWORD)v15 != -1) )
              {
                v16 = v12->m_instancedCells.m_data[v15];
                v21 = v12->m_instancedCells.m_data[v15];
                v17 = *(_QWORD *)&v12->m_instancedCells.m_data[v15] >> 32;
                v18 = v21.m_startEdgeIndex;
              }
              else
              {
                v18 = -1;
                v17 = 0;
                v16.m_numEdges = 0;
              }
              if ( v16.m_numEdges > 0 )
              {
                v19 = v12->m_ownedEdges.m_data;
                v20 = -v18;
                while ( !(v19[v18 - v12->m_numOriginalEdges].m_flags.m_storage & 0x40)
                     || v19[v18 - v12->m_numOriginalEdges].m_oppositeCell != (*(_DWORD *)(v14 + v13) | (v4->m_runtimeId << 22)) )
                {
                  if ( v20 + ++v18 >= v17 )
                    goto LABEL_21;
                }
                hkaiNavVolumeInstance::removeOwnedEdgeForCell(v12, *(unsigned int *)(v14 + v13 + 4), v18);
              }
LABEL_21:
              ++v11;
              v13 += 8i64;
            }
            while ( v11 < *((_DWORD *)v9 + 12) );
            v8 = v23;
          }
          v3 = v22;
        }
      }
      v7 = v24;
      v8 += 56i64;
      ++v6;
      v23 = v8;
    }
    while ( v6 < v24->m_size );
  }
}

// File Line: 129
// RVA: 0xBFDE60
void __fastcall hkaiStreamingManager::loadGraphInstance(hkaiDirectedGraphInstance *graphInstance, hkaiStreamingCollection *collection)
{
  int v2; // er15
  hkaiStreamingCollection *v3; // rbx
  hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *v4; // rax
  hkaiDirectedGraphInstance *v5; // r9
  __int64 v6; // rsi
  hkaiStreamingSet *v7; // rbp
  int v8; // eax
  int v9; // er12
  hkaiDirectedGraphInstance *v10; // rax
  hkaiDirectedGraphExplicitCost *v11; // rbx
  int v12; // eax
  int v13; // edi
  hkaiStreamingSet *v14; // r14
  int v15; // er12
  __int64 v16; // rbx
  hkaiStreamingSet::GraphConnection *v17; // r13
  int v18; // eax
  __int64 v19; // rdx
  signed __int64 v20; // r15
  hkaiDirectedGraphExplicitCost::Edge *v21; // r14
  hkaiDirectedGraphExplicitCost::Edge *v22; // rax
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm4
  __m128 v26; // xmm4
  __m128 v27; // xmm3
  __m128 v28; // xmm1
  float v29; // xmm4_4
  float v30; // xmm0_4
  float v31; // ST34_4
  float v32; // xmm0_4
  float v33; // ST38_4
  unsigned int v34; // [rsp+20h] [rbp-D8h]
  hkaiDirectedGraphInstance *v35; // [rsp+28h] [rbp-D0h]
  int v36; // [rsp+30h] [rbp-C8h]
  unsigned int *edgeDataPtrOut; // [rsp+40h] [rbp-B8h]
  unsigned int *v38; // [rsp+48h] [rbp-B0h]
  hkaiStreamingSet *v39; // [rsp+50h] [rbp-A8h]
  hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *v40; // [rsp+58h] [rbp-A0h]
  hkaiDirectedGraphInstance *v41; // [rsp+100h] [rbp+8h]
  hkaiStreamingCollection *v42; // [rsp+108h] [rbp+10h]
  int v43; // [rsp+110h] [rbp+18h]

  v42 = collection;
  v41 = graphInstance;
  v2 = 0;
  v3 = collection;
  v4 = &graphInstance->m_originalGraph.m_pntr->m_streamingSets;
  v5 = graphInstance;
  v43 = 0;
  v40 = v4;
  if ( v4->m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      v7 = v4->m_data;
      if ( v4->m_data[v6].m_thisUid == v5->m_sectionUid )
      {
        v8 = hkaiStreamingCollection::findGraphIdByUid(v3, v7[v6].m_oppositeUid);
        v9 = v8;
        if ( v8 != -1 )
        {
          if ( v8 >= 0 )
            v10 = v3->m_instances.m_data[v8].m_clusterGraphInstance;
          else
            v10 = 0i64;
          v11 = v10->m_originalGraph.m_pntr;
          v35 = v10;
          v12 = hkaiStreamingSet::indexOfStreamingSet(
                  (hkArrayBase<hkaiStreamingSet> *)&v11->m_streamingSets.m_data,
                  v7[v6].m_oppositeUid,
                  v7[v6].m_thisUid);
          v13 = 0;
          v14 = &v11->m_streamingSets.m_data[v12];
          v39 = &v11->m_streamingSets.m_data[v12];
          if ( v7[v6].m_graphConnections.m_size > 0 )
          {
            v15 = v9 << 22;
            v16 = 0i64;
            do
            {
              v17 = v7[v6].m_graphConnections.m_data;
              v18 = hkaiStreamingSet::indexOfGraphConnection(v14, v17[v16].m_oppositeNodeIndex, v17[v16].m_nodeIndex);
              v19 = (unsigned int)v17[v16].m_nodeIndex;
              v20 = (signed __int64)&v14->m_graphConnections.m_data[v18];
              v34 = v19 | (v41->m_runtimeId << 22);
              v36 = v17[v16].m_oppositeNodeIndex | v15;
              edgeDataPtrOut = 0i64;
              v38 = 0i64;
              v21 = hkaiDirectedGraphInstance::addEdgeForNode(v41, v19, &edgeDataPtrOut);
              v22 = hkaiDirectedGraphInstance::addEdgeForNode(v35, (unsigned int)v17[v16].m_oppositeNodeIndex, &v38);
              v5 = v41;
              v23 = v41->m_originalPositions[v17[v16].m_nodeIndex].m_quad;
              v24 = v35->m_originalPositions[v17[v16].m_oppositeNodeIndex].m_quad;
              v25 = _mm_sub_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v41->m_transform.m_rotation.m_col0.m_quad),
                            _mm_mul_ps(
                              _mm_shuffle_ps(v41->m_originalPositions[v17[v16].m_nodeIndex].m_quad, v23, 85),
                              v41->m_transform.m_rotation.m_col1.m_quad)),
                          _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v41->m_transform.m_rotation.m_col2.m_quad)),
                        v41->m_transform.m_translation.m_quad),
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v35->m_transform.m_rotation.m_col0.m_quad),
                            _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v35->m_transform.m_rotation.m_col1.m_quad)),
                          _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v35->m_transform.m_rotation.m_col2.m_quad)),
                        v35->m_transform.m_translation.m_quad));
              v26 = _mm_mul_ps(v25, v25);
              v27 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                      _mm_shuffle_ps(v26, v26, 170));
              v28 = _mm_rsqrt_ps(v27);
              LODWORD(v29) = (unsigned __int128)_mm_andnot_ps(
                                                  _mm_cmpleps(v27, (__m128)0i64),
                                                  _mm_mul_ps(
                                                    _mm_mul_ps(
                                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v28), v28)),
                                                      _mm_mul_ps(*(__m128 *)_xmm, v28)),
                                                    v27));
              LODWORD(v30) = v17[v16].m_edgeCost.m_value << 16;
              if ( v30 < 0.0 )
                v30 = v29;
              v21->m_flags.m_storage = 64;
              v31 = v30 * 1.0039062;
              v21->m_cost.m_value = HIWORD(v31);
              v21->m_target = v36;
              if ( edgeDataPtrOut )
                *edgeDataPtrOut = v17[v16].m_edgeData;
              LODWORD(v32) = *(signed __int16 *)(v20 + 12) << 16;
              if ( v32 < 0.0 )
                v32 = v29;
              v22->m_flags.m_storage = 64;
              v33 = v32 * 1.0039062;
              v22->m_cost.m_value = HIWORD(v33);
              v22->m_target = v34;
              if ( v38 )
                *v38 = *(_DWORD *)(v20 + 8);
              v14 = v39;
              ++v13;
              ++v16;
            }
            while ( v13 < v7[v6].m_graphConnections.m_size );
            v2 = v43;
            v3 = v42;
            goto LABEL_22;
          }
          v3 = v42;
        }
        v5 = v41;
      }
LABEL_22:
      v4 = v40;
      ++v2;
      ++v6;
      v43 = v2;
    }
    while ( v2 < v40->m_size );
  }
}

// File Line: 210
// RVA: 0xBFE230
void __fastcall hkaiStreamingManager::unloadGraphInstance(hkaiDirectedGraphInstance *graphInstance, hkaiStreamingCollection *collection)
{
  hkaiStreamingCollection *v2; // rbx
  hkaiDirectedGraphInstance *v3; // r13
  int v4; // er9
  __int64 v5; // r8
  int v6; // er12
  _QWORD *v7; // rax
  __int64 v8; // rdi
  __int64 v9; // r15
  int v10; // eax
  hkaiDirectedGraphInstance *v11; // rbx
  int v12; // esi
  __int64 v13; // r14
  __int64 v14; // rbp
  __int64 v15; // rdx
  hkaiDirectedGraphExplicitCost::Node v16; // rax
  int v17; // edx
  int v18; // er8
  hkaiDirectedGraphExplicitCost::Edge *v19; // rdi
  int v20; // er10
  hkaiDirectedGraphExplicitCost::Node v21; // [rsp+70h] [rbp+8h]
  hkaiStreamingCollection *v22; // [rsp+78h] [rbp+10h]
  __int64 v23; // [rsp+80h] [rbp+18h]
  signed __int64 v24; // [rsp+88h] [rbp+20h]

  v22 = collection;
  v2 = collection;
  v3 = graphInstance;
  hkaiDirectedGraphInstance::clearOwnedEdges(graphInstance);
  v4 = 0;
  if ( v3->m_instancedNodes.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      ++v4;
      ++v5;
      v3->m_instancedNodes.m_data[v5 - 1].m_startEdgeIndex = -1;
      *((_DWORD *)&v3->m_instancedNodes.m_data[v5] - 1) = 0;
    }
    while ( v4 < v3->m_instancedNodes.m_size );
  }
  v6 = 0;
  v7 = &v3->m_originalGraph.m_pntr->m_streamingSets.m_data;
  v24 = (signed __int64)&v3->m_originalGraph.m_pntr->m_streamingSets;
  if ( v3->m_originalGraph.m_pntr->m_streamingSets.m_size > 0 )
  {
    v8 = 0i64;
    v23 = 0i64;
    do
    {
      v9 = v8 + *v7;
      if ( *(_DWORD *)v9 == v3->m_sectionUid )
      {
        v10 = hkaiStreamingCollection::findGraphIdByUid(v2, *(_DWORD *)(v9 + 4));
        if ( v10 != -1 )
        {
          if ( v10 >= 0 )
            v11 = v2->m_instances.m_data[v10].m_clusterGraphInstance;
          else
            v11 = 0i64;
          v12 = 0;
          if ( *(_DWORD *)(v9 + 32) > 0 )
          {
            v13 = 0i64;
            do
            {
              v14 = *(_QWORD *)(v9 + 24);
              if ( v11->m_nodeMap.m_size
                && (v15 = v11->m_nodeMap.m_data[*(signed int *)(v14 + v13 + 4)], (_DWORD)v15 != -1) )
              {
                v16 = v11->m_instancedNodes.m_data[v15];
                v21 = v11->m_instancedNodes.m_data[v15];
                v17 = *(_QWORD *)&v11->m_instancedNodes.m_data[v15] >> 32;
                v18 = v21.m_startEdgeIndex;
              }
              else
              {
                v18 = -1;
                v17 = 0;
                v16.m_numEdges = 0;
              }
              if ( v16.m_numEdges > 0 )
              {
                v19 = v11->m_ownedEdges.m_data;
                v20 = -v18;
                while ( !(v19[v18 - v11->m_numOriginalEdges].m_flags.m_storage & 0x40)
                     || v19[v18 - v11->m_numOriginalEdges].m_target != (*(_DWORD *)(v14 + v13) | (v3->m_runtimeId << 22)) )
                {
                  if ( v20 + ++v18 >= v17 )
                    goto LABEL_24;
                }
                hkaiDirectedGraphInstance::removeOwnedEdgeForNode(v11, *(unsigned int *)(v14 + v13 + 4), v18);
              }
LABEL_24:
              ++v12;
              v13 += 16i64;
            }
            while ( v12 < *(_DWORD *)(v9 + 32) );
            v8 = v23;
          }
          v2 = v22;
        }
      }
      v7 = (_QWORD *)v24;
      v8 += 56i64;
      ++v6;
      v23 = v8;
    }
    while ( v6 < *(_DWORD *)(v24 + 8) );
  }
}


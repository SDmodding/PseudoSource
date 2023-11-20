// File Line: 28
// RVA: 0xC1F420
__int64 __fastcall hkaiAstarSearchIteration_hkaiDirectedGraphVisitor_hkaiDirectedGraphVisitor_hkaiHeapOpenSet_hkaiHashSearchState_hkaiHashSearchState_hkaiGraphDistanceHeuristic_hkaiDirectedGraphVisitor__hkaiHashSearchState_hkaiDirectedGraphVisitor_(hkaiDirectedGraphVisitor *graph, hkaiDirectedGraphVisitor *edgeCost, hkaiHeapOpenSet *openset, hkaiHashSearchState *flags, hkaiHashSearchState *parent, hkaiGraphDistanceHeuristic<hkaiDirectedGraphVisitor> *heuristic, hkaiHashSearchState *pathCost, hkaiDirectedGraphVisitor *listener)
{
  hkaiDirectedGraphVisitor *v8; // r14
  hkaiHashSearchState *v9; // r15
  hkaiHeapOpenSet *v10; // rbp
  unsigned int v11; // eax
  hkaiDirectedGraphVisitor *v12; // rdi
  unsigned int v13; // esi
  hkaiStreamingCollection::InstanceInfo *v14; // r9
  __int64 v15; // r8
  __m128 *v16; // rdx
  __int64 v17; // r9
  __int64 v18; // rcx
  unsigned __int64 v19; // rax
  signed int v20; // ecx
  __m128 *v21; // r8
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm0
  int v25; // er9
  __m128 v26; // xmm2
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  hkaiDirectedGraphExplicitCost::Edge *v30; // rdx
  hkaiDirectedGraphExplicitCost::Edge *v31; // rbx
  float v32; // er11
  int arraySize; // ST20_4
  int v34; // er9
  hkaiDirectedGraphInstance *v35; // r10
  int v36; // ST20_4
  int v37; // eax
  __int64 v38; // rdx
  unsigned int *v39; // rcx
  hkaiHashSearchState *v40; // rbx
  hkaiSearchStateNode *v41; // rax
  hkaiHashSearchState *v42; // rsi
  bool v43; // zf
  int v44; // ebx
  float v45; // xmm6_4
  hkLifoAllocator *v46; // rax
  int *v47; // r12
  int v48; // edx
  char *v49; // rcx
  signed int v50; // er8
  signed int v51; // er9
  unsigned int v52; // er11
  signed int v53; // edx
  int *v54; // rcx
  signed int v55; // er13
  __m128i v56; // xmm2
  __m128i v57; // xmm1
  __m128i v58; // xmm0
  int v59; // eax
  unsigned int v60; // er10
  signed int v61; // edx
  __m128i v62; // xmm2
  __m128i v63; // xmm1
  __m128i v64; // xmm0
  int v65; // eax
  int *v66; // r14
  hkaiDirectedGraphVisitor *v67; // r12
  int v68; // er13
  hkaiHashSearchState *v69; // rbx
  signed __int64 v70; // rax
  unsigned int v71; // edx
  __int64 v72; // rcx
  hkaiDirectedGraphInstance *v73; // rax
  __int64 v74; // r9
  __int64 v75; // r10
  int v76; // ebx
  int v77; // eax
  __int128 v78; // xmm0
  __m128 *v79; // r8
  __int64 v80; // rdx
  __m128 v81; // xmm1
  __m128 v82; // xmm2
  __int64 v83; // rax
  float v84; // xmm0_4
  hkaiSearchStateNode *v85; // rcx
  int v86; // edx
  float v87; // xmm2_4
  hkaiSearchStateNode *v88; // rax
  int v89; // ebx
  signed int v90; // ebx
  hkLifoAllocator *v91; // rax
  int v92; // er8
  int *v94; // [rsp+30h] [rbp-C8h]
  unsigned __int64 v95; // [rsp+38h] [rbp-C0h]
  __int64 v96; // [rsp+40h] [rbp-B8h]
  __int64 v97; // [rsp+48h] [rbp-B0h]
  int *v98; // [rsp+50h] [rbp-A8h]
  int v99; // [rsp+60h] [rbp-98h]
  __int64 v100; // [rsp+68h] [rbp-90h]
  __int128 v101; // [rsp+70h] [rbp-88h]
  int v102; // [rsp+80h] [rbp-78h]
  hkaiDirectedGraphVisitor **v103; // [rsp+88h] [rbp-70h]
  __m128 v104; // [rsp+90h] [rbp-68h]
  int v105; // [rsp+A0h] [rbp-58h]
  __int64 v106; // [rsp+A8h] [rbp-50h]
  hkaiDirectedGraphVisitor *v107; // [rsp+100h] [rbp+8h]
  hkaiDirectedGraphVisitor *v108; // [rsp+108h] [rbp+10h]
  unsigned int nit; // [rsp+118h] [rbp+20h]

  v108 = edgeCost;
  v107 = graph;
  v8 = graph;
  v9 = flags;
  v10 = openset;
  v11 = hkaiHeapOpenSet::popNextSearchIndex(openset);
  v12 = listener;
  v13 = v11;
  v14 = listener->m_streamingInfo;
  v15 = v11 >> 22;
  nit = v11;
  listener->m_cachedNodeKey = v11;
  if ( v14 && v12->m_cachedIncomingSectionId != (_DWORD)v15 )
    v12->m_incomingGraph = v14[v15].m_clusterGraphInstance;
  v16 = (__m128 *)v12->m_incomingGraph;
  v12->m_cachedIncomingSectionId = v15;
  v17 = v11 & 0x3FFFFF;
  v12->m_cachedNode = *(hkaiDirectedGraphExplicitCost::Node *)(v16[1].m128_u64[0] + 8 * v17);
  if ( v16[7].m128_i32[0] && (v18 = *(signed int *)(v16[6].m128_u64[1] + 4 * v17), (_DWORD)v18 != -1) )
  {
    v12->m_cachedInstanceNode = *(hkaiDirectedGraphExplicitCost::Node *)(v16[7].m128_u64[1] + 8 * v18);
  }
  else
  {
    v12->m_cachedInstanceNode.m_startEdgeIndex = -1;
    v12->m_cachedInstanceNode.m_numEdges = 0;
  }
  v19 = v16[3].m128_u64[0];
  v20 = 24;
  v21 = v16;
  v22 = *(__m128 *)(v19 + 16 * v17);
  v23 = *(__m128 *)(v19 + 16 * v17);
  v24 = *(__m128 *)(v19 + 16 * v17);
  v25 = 24;
  if ( v12->m_cachedNode.m_numEdges < 24 )
    v25 = v12->m_cachedNode.m_numEdges;
  v26 = _mm_shuffle_ps(v23, v22, 85);
  v27 = _mm_shuffle_ps(v24, v22, 0);
  v28 = _mm_shuffle_ps(v22, v22, 170);
  if ( v12->m_cachedInstanceNode.m_numEdges < 24 )
    v20 = v12->m_cachedInstanceNode.m_numEdges;
  v29 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v26, v16[14]), _mm_mul_ps(v27, v16[13])), _mm_mul_ps(v28, v16[15])),
          v16[16]);
  v12->m_cachedNode.m_numEdges = v25;
  v12->m_cachedInstanceNode.m_numEdges = v20;
  v12->m_cachedPosition.m_quad = v29;
  v30 = (hkaiDirectedGraphExplicitCost::Edge *)v16[2].m128_u64[0];
  v31 = (hkaiDirectedGraphExplicitCost::Edge *)v21[8].m128_u64[1];
  v32 = v21[5].m128_f32[2];
  if ( v30 )
  {
    arraySize = v21[2].m128_i32[2];
    copyEdges_0(v12->m_localEdges, v30, v12->m_cachedNode.m_startEdgeIndex, v25);
  }
  if ( v31 )
  {
    v34 = v12->m_cachedInstanceNode.m_numEdges;
    if ( v34 > 0 )
    {
      v35 = v12->m_incomingGraph;
      v36 = v35->m_ownedEdges.m_size;
      copyEdges_0(
        (hkaiDirectedGraphExplicitCost::Edge *)&v12->m_streamingInfo + v12->m_cachedNode.m_numEdges + 18i64,
        v31,
        v12->m_cachedInstanceNode.m_startEdgeIndex - v35->m_numOriginalEdges,
        v34);
    }
  }
  v12->m_currentEdge = (hkaiDirectedGraphExplicitCost::Edge *)&v12->m_numGoals;
  v37 = v12->m_cachedNode.m_numEdges + v12->m_cachedInstanceNode.m_numEdges;
  v38 = v37;
  if ( v37 > 0 )
  {
    v39 = &v12->m_localEdges[0].m_target;
    do
    {
      if ( !(*((_BYTE *)v39 - 2) & 0x40) )
      {
        *v39 &= 0x3FFFFFu;
        *v39 |= LODWORD(v32) << 22;
      }
      v39 += 2;
      --v38;
    }
    while ( v38 );
  }
  v40 = v12->m_searchState;
  v41 = hkaiHashSearchState::getNodeState(v12->m_searchState, v13);
  v42 = pathCost;
  v40->m_currentNodeState = v41;
  v40->m_parentNodeState = v41;
  v40->m_parentIndex = (signed __int16)((signed __int64)(unsigned int)((_DWORD)v41 - LODWORD(v40->m_nodes)) >> 4);
  LODWORD(v40) = v8->m_cachedInstanceNode.m_numEdges;
  v43 = v8->m_cachedNode.m_numEdges + (_DWORD)v40 == 0;
  v44 = v8->m_cachedNode.m_numEdges + (_DWORD)v40;
  v45 = v42->m_currentNodeState->m_gCost;
  LODWORD(pathCost) = v44;
  if ( v43 )
  {
    v47 = 0i64;
    v94 = 0i64;
  }
  else
  {
    v46 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v47 = (int *)v46->m_cur;
    v48 = (4 * v44 + 127) & 0xFFFFFF80;
    v94 = v47;
    v49 = (char *)v47 + v48;
    if ( v48 > v46->m_slabSize || v49 > v46->m_end )
    {
      v47 = (int *)hkLifoAllocator::allocateFromNewSlab(v46, v48);
      v94 = v47;
    }
    else
    {
      v46->m_cur = v49;
    }
  }
  v50 = v8->m_cachedNode.m_numEdges;
  v51 = v8->m_cachedInstanceNode.m_numEdges;
  v52 = v8->m_cachedNode.m_startEdgeIndex;
  v53 = 0;
  v54 = v47;
  v55 = v44 | 0x80000000;
  LODWORD(listener) = v44 | 0x80000000;
  if ( v50 > 0 )
  {
    if ( (unsigned int)v50 >= 4 )
    {
      v56 = _mm_load_si128((const __m128i *)&_xmm);
      v57 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v52), 0);
      do
      {
        v58 = _mm_cvtsi32_si128(v53);
        v53 += 4;
        v54 += 4;
        _mm_storeu_si128((__m128i *)v54 - 1, _mm_add_epi32(_mm_add_epi32(_mm_shuffle_epi32(v58, 0), v56), v57));
      }
      while ( v53 < v50 - v50 % 4 );
    }
    for ( ; v53 < v50; *(v54 - 1) = v59 )
    {
      v59 = v53++ + v52;
      ++v54;
    }
  }
  v60 = v8->m_cachedInstanceNode.m_startEdgeIndex;
  v61 = 0;
  if ( v51 > 0 )
  {
    if ( (unsigned int)v51 >= 4 )
    {
      v62 = _mm_load_si128((const __m128i *)&_xmm);
      v63 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v60), 0);
      do
      {
        v64 = _mm_cvtsi32_si128(v61);
        v61 += 4;
        v54 += 4;
        _mm_storeu_si128((__m128i *)v54 - 1, _mm_add_epi32(_mm_add_epi32(_mm_shuffle_epi32(v64, 0), v62), v63));
      }
      while ( v61 < v51 - v51 % 4 );
    }
    for ( ; v61 < v51; *(v54 - 1) = v65 )
    {
      v65 = v61++ + v60;
      ++v54;
    }
  }
  v66 = v47;
  v95 = (unsigned __int64)&v47[v51 + v50];
  if ( (unsigned __int64)v47 < v95 )
  {
    v67 = v107;
    while ( 1 )
    {
      v68 = *v66;
      if ( v9->m_nodeSize >= v9->m_nodeCapacity )
      {
LABEL_62:
        v47 = v94;
        v55 = (signed int)listener;
        goto LABEL_63;
      }
      v69 = v12->m_searchState;
      v70 = (signed __int64)&v12->m_currentEdge[1];
      v12->m_currentEdge = (hkaiDirectedGraphExplicitCost::Edge *)v70;
      v71 = *(_DWORD *)(v70 + 4);
      v69->m_currentNodeState = v71 == -1 ? 0i64 : hkaiHashSearchState::getNodeState(v69, v71);
      v72 = v12->m_currentEdge->m_target >> 22;
      if ( !v12->m_streamingInfo )
        break;
      if ( v12->m_cachedOutgoingSectionId != (_DWORD)v72 )
      {
        v73 = v12->m_streamingInfo[v72].m_clusterGraphInstance;
LABEL_50:
        v12->m_outgoingGraph = v73;
      }
      v74 = (__int64)v108;
      v12->m_cachedOutgoingSectionId = v72;
      v75 = *(_QWORD *)(v74 + 40);
      v76 = v67->m_currentEdge->m_target;
      if ( !v75 )
        goto LABEL_73;
      v77 = *(_DWORD *)(v74 + 116);
      v78 = *(_OWORD *)(v74 + 64);
      v103 = 0i64;
      v99 = v77;
      v106 = 0i64;
      v79 = *(__m128 **)(v74 + 16);
      v101 = v78;
      v102 = -1;
      v105 = -1;
      v100 = v74 + 48;
      v80 = v76 & 0x3FFFFF;
      v107 = *(hkaiDirectedGraphVisitor **)(v79[1].m128_u64[0] + 8 * v80);
      v81 = *(__m128 *)(v79[3].m128_u64[0] + 16 * v80);
      v82 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v81, v81, 85), v79[14]),
                  _mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), v79[13])),
                _mm_mul_ps(_mm_shuffle_ps(v81, v81, 170), v79[15])),
              v79[16]);
      v103 = &v107;
      v83 = *(_QWORD *)(v74 + 96);
      v102 = v76;
      v106 = v83;
      LODWORD(v83) = *(_DWORD *)(v74 + 104);
      v104 = v82;
      v105 = v68 | ((_DWORD)v83 << 22);
      v96 = *(_QWORD *)v74;
      v97 = v74 + 80;
      v98 = &v99;
      if ( (*(unsigned __int8 (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v75 + 24i64))(v75, &v96) )
      {
LABEL_73:
        v84 = hkaiDirectedGraphVisitor::getTotalCost(v67, nit, v76, v68);
        if ( v84 <= v42->m_maxPathCost
          && (!(v9->m_currentNodeState->m_flags.m_storage & 3) || v84 < v42->m_currentNodeState->m_gCost) )
        {
          hkaiHashSearchState::setCost<hkaiGraphDistanceHeuristic<hkaiDirectedGraphVisitor>>(v42, heuristic, v76, v84);
          parent->m_currentNodeState->m_parentIndex = parent->m_parentIndex;
          v85 = v9->m_currentNodeState;
          v86 = v85->m_flags.m_storage & 1;
          v87 = (float)(v42->m_currentNodeState->m_hCost * v42->m_heuristicWeight) + v42->m_currentNodeState->m_gCost;
          if ( v87 <= v42->m_maxPathCost )
          {
            v85->m_flags.m_storage &= 0xFFFDu;
            v85->m_flags.m_storage |= 1u;
            if ( v86 )
            {
              hkaiHeapOpenSet::adjustValue(v10, v76, v87);
            }
            else
            {
              if ( v10->m_heapSize >= v10->m_maxSize )
                goto LABEL_62;
              hkaiHeapOpenSet::insertSearchIndex(v10, v76, v87);
            }
          }
        }
      }
      ++v66;
      if ( (unsigned __int64)v66 >= v95 )
        goto LABEL_62;
    }
    v73 = v12->m_incomingGraph;
    goto LABEL_50;
  }
LABEL_63:
  v88 = v9->m_parentNodeState;
  v89 = (signed int)pathCost;
  v88->m_flags.m_storage &= 0xFFFEu;
  v88->m_flags.m_storage |= 2u;
  v90 = (4 * v89 + 127) & 0xFFFFFF80;
  v91 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v92 = (v90 + 15) & 0xFFFFFFF0;
  if ( v90 > v91->m_slabSize || (char *)v47 + v92 != v91->m_cur || v91->m_firstNonLifoEnd == v47 )
    hkLifoAllocator::slowBlockFree(v91, v47, v92);
  else
    v91->m_cur = v47;
  if ( v55 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v47,
      4 * v55);
  return nit;
}


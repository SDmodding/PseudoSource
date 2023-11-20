// File Line: 21
// RVA: 0xC0E410
hkJobQueue::JobStatus __fastcall hkaiProcessDirectedGraphAStarJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  _QWORD *v2; // r15
  hkJobQueue::JobQueueEntry *v3; // r13
  bool v4; // r8
  signed int v5; // eax
  signed int v6; // eax
  char v7; // si
  __int64 v8; // rax
  unsigned int v9; // eax
  __int64 v10; // r12
  _QWORD *v11; // r8
  unsigned __int64 v12; // rcx
  unsigned __int64 v13; // rax
  __int64 v14; // rbx
  __int64 v15; // r14
  __int64 v16; // rax
  __m128i *v17; // rax
  void *v18; // rax
  LPVOID v19; // rax
  hkLifoAllocator *v20; // rcx
  unsigned int *v21; // rax
  int v22; // edx
  char *v23; // r8
  hkaiStreamingCollection::InstanceInfo *v24; // rax
  hkaiStreamingCollection::InstanceInfo *v25; // r8
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  signed __int64 v29; // rcx
  signed int v30; // ebx
  int v31; // eax
  int v32; // edi
  _QWORD *v33; // r8
  _QWORD *v34; // rcx
  unsigned __int64 v35; // rax
  signed __int64 v36; // rcx
  unsigned int v37; // er14
  signed int v38; // ebx
  signed int v39; // eax
  int v40; // edx
  _QWORD *v41; // r8
  _QWORD *v42; // rcx
  unsigned __int64 v43; // rax
  signed __int64 v44; // rcx
  int v45; // edx
  char v46; // al
  _QWORD *v47; // r8
  _QWORD *v48; // rcx
  unsigned __int64 v49; // rax
  signed __int64 v50; // rcx
  int v51; // eax
  char *v52; // rdi
  signed int v53; // ebx
  hkLifoAllocator *v54; // rax
  int v55; // er8
  hkArray<unsigned int,hkContainerHeapAllocator> statesOut; // [rsp+30h] [rbp-D0h]
  void *p; // [rsp+40h] [rbp-C0h]
  int v59; // [rsp+48h] [rbp-B8h]
  __m128i v60; // [rsp+50h] [rbp-B0h]
  unsigned int sid[2]; // [rsp+60h] [rbp-A0h]
  __int64 v62; // [rsp+68h] [rbp-98h]
  __int64 v63; // [rsp+70h] [rbp-90h]
  __m128i *v64; // [rsp+78h] [rbp-88h]
  void *dst; // [rsp+80h] [rbp-80h]
  __int64 v66; // [rsp+88h] [rbp-78h]
  hkaiDirectedGraphSearch::StartGoalInfo goalInfo; // [rsp+90h] [rbp-70h]
  hkaiSearchMemoryLocalStorage v68; // [rsp+C0h] [rbp-40h]
  hkaiSearchMemoryLocalStorage v69; // [rsp+120h] [rbp+20h]
  hkaiDirectedGraphVisitor graph; // [rsp+180h] [rbp+80h]
  hkaiDirectedGraphSearch v71; // [rsp+3A0h] [rbp+2A0h]
  hkJobQueue *v72; // [rsp+9D0h] [rbp+8D0h]
  hkaiSearchParameters::BufferSizes v73; // [rsp+9D8h] [rbp+8D8h]
  hkaiSearchParameters::BufferSizes bufferSizes; // [rsp+9E0h] [rbp+8E0h]

  v72 = jobQueue;
  v2 = *(_QWORD **)&nextJobOut->m_data[72];
  v3 = nextJobOut;
  v4 = nextJobOut->m_data[20] && *(_QWORD *)&nextJobOut->m_data[56];
  bufferSizes = *(hkaiSearchParameters::BufferSizes *)&nextJobOut->m_data[40];
  v5 = bufferSizes.m_maxOpenSetSizeBytes;
  if ( bufferSizes.m_maxOpenSetSizeBytes <= 0 )
    v5 = 0x2000;
  bufferSizes.m_maxOpenSetSizeBytes = v5;
  v6 = bufferSizes.m_maxSearchStateSizeBytes;
  if ( bufferSizes.m_maxSearchStateSizeBytes <= 0 )
    v6 = 37376;
  v7 = 0;
  bufferSizes.m_maxSearchStateSizeBytes = v6;
  v8 = *(_QWORD *)&nextJobOut->m_data[48];
  v73 = *(hkaiSearchParameters::BufferSizes *)&nextJobOut->m_data[48];
  if ( v4 )
  {
    if ( (signed int)v8 <= 0 )
      LODWORD(v8) = 2048;
    v73.m_maxOpenSetSizeBytes = v8;
    if ( v73.m_maxSearchStateSizeBytes <= 0 )
      v73.m_maxSearchStateSizeBytes = 9728;
  }
  else
  {
    v73 = 0i64;
  }
  v9 = *(_DWORD *)&nextJobOut->m_data[80];
  if ( (signed int)v9 > 0 )
  {
    v10 = v9;
    do
    {
      v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = v11[1];
      if ( v12 < v11[3] )
      {
        *(_QWORD *)v12 = "LtMtPath";
        *(_QWORD *)(v12 + 16) = "StInit";
        v13 = __rdtsc();
        *(_DWORD *)(v12 + 8) = v13;
        v11[1] = v12 + 24;
      }
      v14 = v2[5];
      v15 = v2[1];
      *(_QWORD *)sid = *v2;
      v16 = v2[2];
      v2 += 6;
      v63 = v16;
      v17 = (__m128i *)*(v2 - 3);
      v62 = v15;
      v64 = v17;
      v18 = (void *)*(v2 - 2);
      v66 = v14;
      v60.m128i_i32[2] = 2139095022;
      statesOut.m_data = 0i64;
      statesOut.m_size = 0;
      dst = v18;
      statesOut.m_capacityAndFlags = 2147483648;
      v59 = v14;
      if ( (_DWORD)v14 )
      {
        v19 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v20 = (hkLifoAllocator *)v19;
        v21 = (unsigned int *)*((_QWORD *)v19 + 3);
        v22 = (4 * v14 + 127) & 0xFFFFFF80;
        v23 = (char *)v21 + v22;
        if ( v22 > v20->m_slabSize || v23 > v20->m_end )
          v21 = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v20, v22);
        else
          v20->m_cur = v23;
      }
      else
      {
        v21 = 0i64;
      }
      statesOut.m_data = v21;
      p = v21;
      statesOut.m_capacityAndFlags = v14 | 0x80000000;
      hkaiSearchMemoryLocalStorage::hkaiSearchMemoryLocalStorage(&v68, &bufferSizes);
      hkaiSearchMemoryLocalStorage::hkaiSearchMemoryLocalStorage(&v69, &v73);
      hkaiDirectedGraphSearch::hkaiDirectedGraphSearch(
        &v71,
        (hkaiSearchMemoryInfo *)&v68.m_openSetBuffer,
        (hkaiSearchMemoryInfo *)&v69.m_openSetBuffer);
      v24 = *(hkaiStreamingCollection::InstanceInfo **)&v3->m_data[56];
      v25 = *(hkaiStreamingCollection::InstanceInfo **)&v3->m_data[64];
      _mm_store_si128(
        (__m128i *)&graph.m_cachedNode,
        _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff));
      v71.m_state.m_heuristicWeight = *(float *)&v3->m_data[16];
      graph.m_streamingInfo = v24;
      graph.m_costModifier = *(hkaiAstarCostModifier **)&v3->m_data[24];
      graph.m_edgeFilter = *(hkaiAstarEdgeFilter **)&v3->m_data[32];
      graph.m_agentInfo = *(hkaiAgentTraversalInfo *)((char *)&v62 + 4);
      *(_QWORD *)&graph.m_cachedIncomingSectionId = -1i64;
      graph.m_searchState = &v71.m_state;
      graph.m_cachedGeneralSectionId = -1;
      goalInfo.m_startNodeKeys = sid;
      graph.m_numGoals = 0;
      graph.m_goalNodes = 0i64;
      graph.m_finalCosts = 0i64;
      goalInfo.m_numStartNodeKeys = 1;
      goalInfo.m_goalNodeKeys = &sid[1];
      goalInfo.m_initialCosts = 0i64;
      goalInfo.m_numGoals = 1;
      goalInfo.m_finalCosts = 0i64;
      hkaiDirectedGraphSearch::init(&v71, &graph, v25, &goalInfo);
      v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v27 = (_QWORD *)v26[1];
      if ( (unsigned __int64)v27 < v26[3] )
      {
        *v27 = "StAStar";
        v28 = __rdtsc();
        v29 = (signed __int64)(v27 + 2);
        *(_DWORD *)(v29 - 8) = v28;
        v26[1] = v29;
      }
      v30 = 0;
      while ( v30 < (signed int)v15 )
      {
        ++v30;
        v31 = hkaiDirectedGraphSearch::iteration(&v71);
        v32 = v31;
        if ( v31 == 3 )
        {
          v7 = (v71.m_openSet.m_heapSize < v71.m_openSet.m_maxSize) + 2;
          goto LABEL_34;
        }
        if ( v31 )
          goto LABEL_34;
      }
      v32 = 3;
      v7 = 1;
LABEL_34:
      v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v34 = (_QWORD *)v33[1];
      if ( (unsigned __int64)v34 < v33[3] )
      {
        *v34 = "StBacktrack";
        v35 = __rdtsc();
        v36 = (signed __int64)(v34 + 2);
        *(_DWORD *)(v36 - 8) = v35;
        v33[1] = v36;
      }
      v37 = v71.m_state.m_bestNode;
      if ( !v32 )
        v32 = (v71.m_state.m_bestNode != -1) + 2;
      v60.m128i_i8[13] = v7;
      v7 = 0;
      v60.m128i_i64[0] = __PAIR__(-1, v30);
      v60.m128i_i8[12] = v32;
      v38 = 1;
      if ( !((v32 - 1) & 0xFFFFFFFD) )
      {
        if ( v32 == 1 )
          v37 = sid[1];
        v71.m_state.m_currentNodeState = hkaiHashSearchState::getNodeState(&v71.m_state, v37);
        v71.m_state.m_parentNodeState = v71.m_state.m_currentNodeState;
        v71.m_state.m_parentIndex = (signed __int16)((_QWORD)((char *)v71.m_state.m_currentNodeState
                                                            - (char *)v71.m_state.m_nodes) >> 4);
        v60.m128i_i32[2] = LODWORD(v71.m_state.m_currentNodeState->m_gCost);
        v60.m128i_i32[1] = (v32 == 1) - 1;
        v39 = hkaiSearchStateUtils::getPath(
                &v71.m_state,
                v37,
                0,
                &statesOut,
                (statesOut.m_capacityAndFlags & 0x3FFFFFFFu) - 1);
        v40 = statesOut.m_size;
        v38 = v39;
        if ( statesOut.m_size == (statesOut.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &statesOut, 4);
          v40 = statesOut.m_size;
        }
        statesOut.m_data[v40] = -1;
        ++statesOut.m_size;
      }
      v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v42 = (_QWORD *)v41[1];
      if ( (unsigned __int64)v42 < v41[3] )
      {
        *v42 = "StOutput";
        v43 = __rdtsc();
        v44 = (signed __int64)(v42 + 2);
        *(_DWORD *)(v44 - 8) = v43;
        v41[1] = v44;
      }
      if ( (_BYTE)v32 == 2 )
      {
        hkaiDirectedGraphAStarJob_failure((hkaiDirectedGraphAStarCommand *)sid);
      }
      else if ( !(((_BYTE)v32 - 1) & 0xFD) && dst )
      {
        v45 = v66;
        if ( statesOut.m_size < (signed int)v66 )
          v45 = statesOut.m_size;
        hkString::memCpy(dst, statesOut.m_data, 4 * v45);
      }
      if ( !v38 )
      {
        v46 = v32;
        if ( (_BYTE)v32 == 1 )
          v46 = 4;
        v60.m128i_i8[12] = v46;
      }
      if ( v64 )
        _mm_store_si128(v64, v60);
      v47 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v48 = (_QWORD *)v47[1];
      if ( (unsigned __int64)v48 < v47[3] )
      {
        *v48 = "lt";
        v49 = __rdtsc();
        v50 = (signed __int64)(v48 + 2);
        *(_DWORD *)(v50 - 8) = v49;
        v47[1] = v50;
      }
      hkaiSearchMemoryLocalStorage::~hkaiSearchMemoryLocalStorage(&v69);
      hkaiSearchMemoryLocalStorage::~hkaiSearchMemoryLocalStorage(&v68);
      v51 = statesOut.m_size;
      v52 = (char *)p;
      if ( p == statesOut.m_data )
        v51 = 0;
      statesOut.m_size = v51;
      v53 = (4 * v59 + 127) & 0xFFFFFF80;
      v54 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v55 = (v53 + 15) & 0xFFFFFFF0;
      if ( v53 > v54->m_slabSize || &v52[v55] != v54->m_cur || v54->m_firstNonLifoEnd == v52 )
        hkLifoAllocator::slowBlockFree(v54, v52, v55);
      else
        v54->m_cur = v52;
      statesOut.m_size = 0;
      if ( statesOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          statesOut.m_data,
          4 * statesOut.m_capacityAndFlags);
      --v10;
    }
    while ( v10 );
  }
  return hkJobQueue::finishJobAndGetNextJob(v72, v3, v3, 0);
}

// File Line: 175
// RVA: 0xC0EA50
void __fastcall hkaiDirectedGraphAStarJob_failure(hkaiDirectedGraphAStarCommand *command)
{
  unsigned int *v1; // rax

  v1 = command->m_nodesOut;
  if ( v1 )
  {
    if ( command->m_maxNodesOut > 0 )
      *v1 = -1;
  }
}


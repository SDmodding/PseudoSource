// File Line: 21
// RVA: 0xC0E410
hkJobQueue::JobStatus __fastcall hkaiProcessDirectedGraphAStarJob(
        hkJobQueue *jobQueue,
        hkJobQueue::JobQueueEntry *nextJobOut)
{
  _QWORD *v2; // r15
  bool v4; // r8
  int m_maxOpenSetSizeBytes; // eax
  int m_maxSearchStateSizeBytes; // eax
  char v7; // si
  __int64 v8; // rax
  int v9; // eax
  __int64 v10; // r12
  _QWORD *Value; // r8
  unsigned __int64 v12; // rcx
  unsigned __int64 v13; // rax
  __int64 v14; // rbx
  __int64 v15; // r14
  __int64 v16; // rax
  hkaiAstarOutputParameters *v17; // rax
  unsigned int *v18; // rax
  hkLifoAllocator *v19; // rcx
  unsigned int *m_cur; // rax
  int v21; // edx
  char *v22; // r8
  hkaiStreamingCollection::InstanceInfo *v23; // rax
  hkaiDirectedGraphVisitor *v24; // r8
  _QWORD *v25; // r8
  _QWORD *v26; // rcx
  unsigned __int64 v27; // rax
  _QWORD *v28; // rcx
  int v29; // ebx
  int v30; // eax
  int v31; // edi
  _QWORD *v32; // r8
  _QWORD *v33; // rcx
  unsigned __int64 v34; // rax
  _QWORD *v35; // rcx
  unsigned int m_bestNode; // r14d
  int v37; // ebx
  int Path; // eax
  int m_size; // edx
  _QWORD *v40; // r8
  _QWORD *v41; // rcx
  unsigned __int64 v42; // rax
  _QWORD *v43; // rcx
  int m_maxNodesOut; // edx
  char v45; // al
  _QWORD *v46; // r8
  _QWORD *v47; // rcx
  unsigned __int64 v48; // rax
  _QWORD *v49; // rcx
  int v50; // eax
  char *v51; // rdi
  signed int v52; // ebx
  hkLifoAllocator *v53; // rax
  int v54; // r8d
  hkArray<unsigned int,hkContainerHeapAllocator> statesOut; // [rsp+30h] [rbp-D0h] BYREF
  void *p; // [rsp+40h] [rbp-C0h]
  int v58; // [rsp+48h] [rbp-B8h]
  hkaiAstarOutputParameters v59; // [rsp+50h] [rbp-B0h]
  hkaiDirectedGraphAStarCommand sid; // [rsp+60h] [rbp-A0h] BYREF
  hkaiDirectedGraphSearch::StartGoalInfo goalInfo; // [rsp+90h] [rbp-70h] BYREF
  hkaiSearchMemoryLocalStorage v62; // [rsp+C0h] [rbp-40h] BYREF
  hkaiSearchMemoryLocalStorage v63; // [rsp+120h] [rbp+20h] BYREF
  hkaiDirectedGraphVisitor graph; // [rsp+180h] [rbp+80h] BYREF
  hkaiDirectedGraphSearch v65; // [rsp+3A0h] [rbp+2A0h] BYREF
  hkaiSearchParameters::BufferSizes v67; // [rsp+9D8h] [rbp+8D8h] BYREF
  hkaiSearchParameters::BufferSizes bufferSizes; // [rsp+9E0h] [rbp+8E0h] BYREF

  v2 = *(_QWORD **)&nextJobOut->m_data[72];
  v4 = nextJobOut->m_data[20] && *(_QWORD *)&nextJobOut->m_data[56];
  bufferSizes = *(hkaiSearchParameters::BufferSizes *)&nextJobOut->m_data[40];
  m_maxOpenSetSizeBytes = bufferSizes.m_maxOpenSetSizeBytes;
  if ( bufferSizes.m_maxOpenSetSizeBytes <= 0 )
    m_maxOpenSetSizeBytes = 0x2000;
  bufferSizes.m_maxOpenSetSizeBytes = m_maxOpenSetSizeBytes;
  m_maxSearchStateSizeBytes = bufferSizes.m_maxSearchStateSizeBytes;
  if ( bufferSizes.m_maxSearchStateSizeBytes <= 0 )
    m_maxSearchStateSizeBytes = 37376;
  v7 = 0;
  bufferSizes.m_maxSearchStateSizeBytes = m_maxSearchStateSizeBytes;
  v8 = *(_QWORD *)&nextJobOut->m_data[48];
  v67 = (hkaiSearchParameters::BufferSizes)v8;
  if ( v4 )
  {
    if ( (int)v8 <= 0 )
      LODWORD(v8) = 2048;
    v67.m_maxOpenSetSizeBytes = v8;
    if ( v67.m_maxSearchStateSizeBytes <= 0 )
      v67.m_maxSearchStateSizeBytes = 9728;
  }
  else
  {
    v67 = 0i64;
  }
  v9 = *(_DWORD *)&nextJobOut->m_data[80];
  if ( v9 > 0 )
  {
    v10 = (unsigned int)v9;
    do
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v12 = Value[1];
      if ( v12 < Value[3] )
      {
        *(_QWORD *)v12 = "LtMtPath";
        *(_QWORD *)(v12 + 16) = "StInit";
        v13 = __rdtsc();
        *(_DWORD *)(v12 + 8) = v13;
        Value[1] = v12 + 24;
      }
      v14 = v2[5];
      v15 = v2[1];
      *(_QWORD *)&sid.m_startNodeKey = *v2;
      v16 = v2[2];
      v2 += 6;
      *(_QWORD *)&sid.m_agentInfo.m_filterInfo = v16;
      v17 = (hkaiAstarOutputParameters *)*(v2 - 3);
      *(_QWORD *)&sid.m_maxNumberOfIterations = v15;
      sid.m_AStarOutput = v17;
      v18 = (unsigned int *)*(v2 - 2);
      *(_QWORD *)&sid.m_maxNodesOut = v14;
      v59.m_pathLength = 3.40282e38;
      statesOut.m_data = 0i64;
      statesOut.m_size = 0;
      sid.m_nodesOut = v18;
      statesOut.m_capacityAndFlags = 0x80000000;
      v58 = v14;
      if ( (_DWORD)v14 )
      {
        v19 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        m_cur = (unsigned int *)v19->m_cur;
        v21 = (4 * v14 + 127) & 0xFFFFFF80;
        v22 = (char *)m_cur + v21;
        if ( v21 > v19->m_slabSize || v22 > v19->m_end )
          m_cur = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v19, v21);
        else
          v19->m_cur = v22;
      }
      else
      {
        m_cur = 0i64;
      }
      statesOut.m_data = m_cur;
      p = m_cur;
      statesOut.m_capacityAndFlags = v14 | 0x80000000;
      hkaiSearchMemoryLocalStorage::hkaiSearchMemoryLocalStorage(&v62, &bufferSizes);
      hkaiSearchMemoryLocalStorage::hkaiSearchMemoryLocalStorage(&v63, &v67);
      hkaiDirectedGraphSearch::hkaiDirectedGraphSearch(&v65, &v62, &v63);
      v23 = *(hkaiStreamingCollection::InstanceInfo **)&nextJobOut->m_data[56];
      v24 = *(hkaiDirectedGraphVisitor **)&nextJobOut->m_data[64];
      *(__m128i *)&graph.m_cachedNode.m_startEdgeIndex = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
      v65.m_state.m_heuristicWeight = *(float *)&nextJobOut->m_data[16];
      graph.m_streamingInfo = v23;
      graph.m_costModifier = *(hkaiAstarCostModifier **)&nextJobOut->m_data[24];
      graph.m_edgeFilter = *(hkaiAstarEdgeFilter **)&nextJobOut->m_data[32];
      graph.m_agentInfo = sid.m_agentInfo;
      *(_QWORD *)&graph.m_cachedIncomingSectionId = -1i64;
      graph.m_searchState = &v65.m_state;
      graph.m_cachedGeneralSectionId = -1;
      goalInfo.m_startNodeKeys = (const unsigned int *)&sid;
      memset(&graph.m_goalNodes, 0, 20);
      goalInfo.m_numStartNodeKeys = 1;
      goalInfo.m_goalNodeKeys = &sid.m_goalNodeKey;
      goalInfo.m_initialCosts = 0i64;
      goalInfo.m_numGoals = 1;
      goalInfo.m_finalCosts = 0i64;
      hkaiDirectedGraphSearch::init(&v65, &graph, v24, &goalInfo);
      v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v26 = (_QWORD *)v25[1];
      if ( (unsigned __int64)v26 < v25[3] )
      {
        *v26 = "StAStar";
        v27 = __rdtsc();
        v28 = v26 + 2;
        *((_DWORD *)v28 - 2) = v27;
        v25[1] = v28;
      }
      v29 = 0;
      while ( v29 < (int)v15 )
      {
        ++v29;
        v30 = hkaiDirectedGraphSearch::iteration(&v65);
        v31 = v30;
        if ( v30 == 3 )
        {
          v7 = (v65.m_openSet.m_heapSize < v65.m_openSet.m_maxSize) + 2;
          goto LABEL_34;
        }
        if ( v30 )
          goto LABEL_34;
      }
      v31 = 3;
      v7 = 1;
LABEL_34:
      v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v33 = (_QWORD *)v32[1];
      if ( (unsigned __int64)v33 < v32[3] )
      {
        *v33 = "StBacktrack";
        v34 = __rdtsc();
        v35 = v33 + 2;
        *((_DWORD *)v35 - 2) = v34;
        v32[1] = v35;
      }
      m_bestNode = v65.m_state.m_bestNode;
      if ( !v31 )
        v31 = (v65.m_state.m_bestNode != -1) + 2;
      v59.m_terminationCause.m_storage = v7;
      v7 = 0;
      *(_QWORD *)&v59.m_numIterations = (unsigned int)v29 | 0xFFFFFFFF00000000ui64;
      v59.m_status.m_storage = v31;
      v37 = 1;
      if ( ((v31 - 1) & 0xFFFFFFFD) == 0 )
      {
        if ( v31 == 1 )
          m_bestNode = sid.m_goalNodeKey;
        v65.m_state.m_currentNodeState = hkaiHashSearchState::getNodeState(&v65.m_state, m_bestNode);
        v65.m_state.m_parentNodeState = v65.m_state.m_currentNodeState;
        v65.m_state.m_parentIndex = (__int16)(v65.m_state.m_currentNodeState - v65.m_state.m_nodes);
        v59.m_pathLength = v65.m_state.m_currentNodeState->m_gCost;
        v59.m_goalIndex = (v31 == 1) - 1;
        Path = hkaiSearchStateUtils::getPath(
                 &v65.m_state,
                 m_bestNode,
                 GET_PATH_PRESERVE_ALL,
                 &statesOut,
                 (statesOut.m_capacityAndFlags & 0x3FFFFFFFu) - 1);
        m_size = statesOut.m_size;
        v37 = Path;
        if ( statesOut.m_size == (statesOut.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &statesOut, 4);
          m_size = statesOut.m_size;
        }
        statesOut.m_data[m_size] = -1;
        ++statesOut.m_size;
      }
      v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v41 = (_QWORD *)v40[1];
      if ( (unsigned __int64)v41 < v40[3] )
      {
        *v41 = "StOutput";
        v42 = __rdtsc();
        v43 = v41 + 2;
        *((_DWORD *)v43 - 2) = v42;
        v40[1] = v43;
      }
      if ( (_BYTE)v31 == 2 )
      {
        hkaiDirectedGraphAStarJob_failure(&sid);
      }
      else if ( (((_BYTE)v31 - 1) & 0xFD) == 0 && sid.m_nodesOut )
      {
        m_maxNodesOut = sid.m_maxNodesOut;
        if ( statesOut.m_size < sid.m_maxNodesOut )
          m_maxNodesOut = statesOut.m_size;
        hkString::memCpy(sid.m_nodesOut, statesOut.m_data, 4 * m_maxNodesOut);
      }
      if ( !v37 )
      {
        v45 = v31;
        if ( (_BYTE)v31 == 1 )
          v45 = 4;
        v59.m_status.m_storage = v45;
      }
      if ( sid.m_AStarOutput )
        *sid.m_AStarOutput = v59;
      v46 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v47 = (_QWORD *)v46[1];
      if ( (unsigned __int64)v47 < v46[3] )
      {
        *v47 = "lt";
        v48 = __rdtsc();
        v49 = v47 + 2;
        *((_DWORD *)v49 - 2) = v48;
        v46[1] = v49;
      }
      hkaiSearchMemoryLocalStorage::~hkaiSearchMemoryLocalStorage(&v63);
      hkaiSearchMemoryLocalStorage::~hkaiSearchMemoryLocalStorage(&v62);
      v50 = statesOut.m_size;
      v51 = (char *)p;
      if ( p == statesOut.m_data )
        v50 = 0;
      statesOut.m_size = v50;
      v52 = (4 * v58 + 127) & 0xFFFFFF80;
      v53 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v54 = (v52 + 15) & 0xFFFFFFF0;
      if ( v52 > v53->m_slabSize || &v51[v54] != v53->m_cur || v53->m_firstNonLifoEnd == v51 )
        hkLifoAllocator::slowBlockFree(v53, v51, v54);
      else
        v53->m_cur = v51;
      statesOut.m_size = 0;
      if ( statesOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          statesOut.m_data,
          4 * statesOut.m_capacityAndFlags);
      --v10;
    }
    while ( v10 );
  }
  return hkJobQueue::finishJobAndGetNextJob(jobQueue, nextJobOut, nextJobOut, WAIT_FOR_NEXT_JOB);
}

// File Line: 175
// RVA: 0xC0EA50
void __fastcall hkaiDirectedGraphAStarJob_failure(hkaiDirectedGraphAStarCommand *command)
{
  unsigned int *m_nodesOut; // rax

  m_nodesOut = command->m_nodesOut;
  if ( m_nodesOut )
  {
    if ( command->m_maxNodesOut > 0 )
      *m_nodesOut = -1;
  }
}


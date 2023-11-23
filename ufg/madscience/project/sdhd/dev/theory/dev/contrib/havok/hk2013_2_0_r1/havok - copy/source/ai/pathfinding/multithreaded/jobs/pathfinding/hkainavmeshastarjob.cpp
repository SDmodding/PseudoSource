// File Line: 38
// RVA: 0xC0ECF0
hkJobQueue::JobStatus __fastcall hkaiProcessNavMeshAStarJob(
        hkJobQueue *jobQueue,
        hkJobQueue::JobQueueEntry *nextJobOut)
{
  __int64 v2; // rdi
  bool v4; // zf
  hkaiAstarEdgeFilter *v5; // rcx
  hkaiAstarCostModifier *v6; // rdx
  float v7; // xmm2_4
  hkaiStreamingCollection::InstanceInfo *v8; // rax
  unsigned int v9; // eax
  hkSimdFloat32 v10; // xmm0
  int m_maxOpenSetSizeBytes; // eax
  int m_maxSearchStateSizeBytes; // eax
  __int64 v13; // rax
  __int64 v14; // rsi
  __int64 v15; // rax
  int v16; // ebx
  float v17; // xmm8_4
  _QWORD *Value; // r8
  unsigned __int64 v19; // rcx
  unsigned __int64 v20; // rax
  __m128i v21; // xmm2
  hkVector4f v22; // xmm0
  hkVector4f v23; // xmm3
  __int128 v24; // xmm1
  __int128 v25; // xmm0
  int v26; // r13d
  int v27; // r15d
  int v28; // ecx
  __int128 v29; // xmm0
  hkVector4f *p_m_goalPoint; // rdx
  hkVector4f *p_m_goalFaceKey; // r12
  unsigned int v32; // ecx
  bool v33; // zf
  int m_maxEdgesOut; // ebx
  int m_goalFoundIndex; // esi
  int v36; // edi
  hkLifoAllocator *v37; // rcx
  unsigned int *m_cur; // rax
  int v39; // edx
  char *v40; // r8
  _QWORD *v41; // rax
  _QWORD *v42; // rcx
  _QWORD *v43; // r8
  unsigned __int64 v44; // rax
  _QWORD *v45; // rcx
  BOOL v46; // ebx
  char v47; // al
  hkVector4f v48; // xmm0
  char v49; // al
  hkaiAstarCostModifier *v50; // rax
  unsigned int v51; // ecx
  hkaiStreamingCollection::InstanceInfo *v52; // rcx
  BOOL v53; // eax
  _QWORD *v54; // r8
  _QWORD *v55; // rcx
  unsigned __int64 v56; // rax
  _QWORD *v57; // rcx
  BOOL v58; // ebx
  float v59; // xmm1_4
  float v60; // xmm0_4
  char v61; // si
  int v62; // ebx
  int v63; // eax
  unsigned int m_bestNode; // ebx
  hkaiSearchStateNode *NodeState; // rax
  _QWORD *v66; // r8
  _QWORD *v67; // rcx
  unsigned __int64 v68; // rax
  _QWORD *v69; // rcx
  hkaiPath::PathPoint *m_pointsOut; // r9
  int m_maxPointsOut; // r8d
  char v72; // al
  __m128 m_quad; // xmm0
  char v74; // al
  char v75; // al
  unsigned int *m_edgesOut; // r9
  int m_size; // r8d
  _QWORD *v78; // r8
  _QWORD *v79; // rcx
  unsigned __int64 v80; // rax
  _QWORD *v81; // rcx
  int v82; // eax
  char *v83; // rdi
  signed int v84; // ebx
  hkLifoAllocator *v85; // rax
  int v86; // r8d
  hkaiAstarOutputParameters v88; // [rsp+70h] [rbp-90h]
  hkaiSearchParameters::BufferSizes v89; // [rsp+80h] [rbp-80h] BYREF
  hkArray<unsigned int,hkContainerHeapAllocator> statesOut; // [rsp+88h] [rbp-78h] BYREF
  void *p; // [rsp+98h] [rbp-68h]
  int v92; // [rsp+A0h] [rbp-60h]
  hkVector4f *pArr; // [rsp+A8h] [rbp-58h]
  hkaiSearchParameters::BufferSizes bufferSizes; // [rsp+B0h] [rbp-50h] BYREF
  int v95; // [rsp+B8h] [rbp-48h]
  int Path; // [rsp+BCh] [rbp-44h]
  BOOL v97; // [rsp+C0h] [rbp-40h]
  __int64 v98; // [rsp+C8h] [rbp-38h]
  hkaiNavMeshAStarCommand command; // [rsp+D0h] [rbp-30h] BYREF
  hkVector4f up; // [rsp+140h] [rbp+40h] BYREF
  __int64 v101; // [rsp+150h] [rbp+50h]
  __int64 v102; // [rsp+158h] [rbp+58h]
  hkVector4f endPoint; // [rsp+160h] [rbp+60h] BYREF
  hkaiLineOfSightUtil::LineOfSightOutput output; // [rsp+170h] [rbp+70h] BYREF
  hkaiLineOfSightUtil::LineOfSightInput input; // [rsp+1C0h] [rbp+C0h] BYREF
  hkVector4UtilImpl<float>::DistanceToPoint evalFunc; // [rsp+230h] [rbp+130h] BYREF
  hkVector4f ea; // [rsp+240h] [rbp+140h] BYREF
  hkVector4f eb; // [rsp+250h] [rbp+150h] BYREF
  hkaiNavMeshSectionGraph graph; // [rsp+260h] [rbp+160h] BYREF
  hkaiSearchMemoryLocalStorage v110; // [rsp+4A0h] [rbp+3A0h] BYREF
  hkaiNavMeshSearch v111; // [rsp+500h] [rbp+400h] BYREF
  BOOL v113; // [rsp+AA8h] [rbp+9A8h]
  int v114; // [rsp+AB0h] [rbp+9B0h]
  int v115; // [rsp+AB8h] [rbp+9B8h]

  v2 = *(_QWORD *)&nextJobOut->m_data[104];
  v4 = nextJobOut->m_data[44] == 0;
  v5 = *(hkaiAstarEdgeFilter **)&nextJobOut->m_data[32];
  v6 = *(hkaiAstarCostModifier **)&nextJobOut->m_data[24];
  v7 = *(float *)&nextJobOut->m_data[64];
  v8 = *(hkaiStreamingCollection::InstanceInfo **)&nextJobOut->m_data[96];
  graph.m_edgeFilter = v5;
  graph.m_streamingInfo = v8;
  graph.m_costModifier = v6;
  v9 = 0;
  *(_QWORD *)&graph.m_cachedIncomingEdge.m_oppositeEdge = -1i64;
  *(_DWORD *)&graph.m_cachedIncomingEdge.m_flags.m_storage = 4;
  up.m_quad = _mm_mul_ps(
                _mm_cvtepi32_ps(
                  _mm_add_epi32(
                    _mm_unpacklo_epi16((__m128i)0i64, _mm_loadl_epi64((const __m128i *)&nextJobOut->m_data[16])),
                    _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset))),
                (__m128)xmmword_141A713A0);
  graph.m_up = (hkVector4f)up.m_quad;
  v10.m_real = _mm_shuffle_ps(
                 (__m128)*(unsigned int *)&nextJobOut->m_data[60],
                 (__m128)*(unsigned int *)&nextJobOut->m_data[60],
                 0);
  if ( *(float *)&nextJobOut->m_data[60] >= 0.0 )
    v9 = 1;
  *(_QWORD *)&graph.m_cachedOutgoingEdge.m_oppositeEdge = -1i64;
  graph.m_searchSphereRadius = (hkSimdFloat32)v10.m_real;
  *(_DWORD *)&graph.m_cachedOutgoingEdge.m_flags.m_storage = 4;
  *(_QWORD *)&graph.m_cachedOppositeEdge.m_oppositeEdge = -1i64;
  *(_DWORD *)&graph.m_cachedOppositeEdge.m_flags.m_storage = 4;
  graph.m_searchCapsuleRadius.m_real = _mm_shuffle_ps((__m128)LODWORD(v7), (__m128)LODWORD(v7), 0);
  graph.m_cachedEdgePairInfo.m_incomingEdgeInfo.m_edgeKey = -1;
  graph.m_cachedEdgePairInfo.m_incomingEdgeInfo.m_edge = 0i64;
  graph.m_cachedEdgePairInfo.m_outgoingEdgeInfo.m_edgeKey = -1;
  graph.m_cachedEdgePairInfo.m_outgoingEdgeInfo.m_edge = 0i64;
  graph.m_cachedEdgePairInfo.m_faceKey = -1;
  graph.m_cachedEdgePairInfo.m_face = 0i64;
  graph.m_info = 0i64;
  graph.m_startFaceKey = -1;
  graph.m_numGoals = 0;
  *(_QWORD *)&graph.m_cachedIncomingSectionId = -1i64;
  memset(&graph.m_searchState, 0, 24);
  if ( v7 >= 0.0 )
    v9 |= 2u;
  if ( !v4 )
    v9 |= 0x10u;
  graph.m_flags = v9;
  bufferSizes = *(hkaiSearchParameters::BufferSizes *)&nextJobOut->m_data[68];
  m_maxOpenSetSizeBytes = bufferSizes.m_maxOpenSetSizeBytes;
  if ( bufferSizes.m_maxOpenSetSizeBytes <= 0 )
    m_maxOpenSetSizeBytes = 0x2000;
  bufferSizes.m_maxOpenSetSizeBytes = m_maxOpenSetSizeBytes;
  m_maxSearchStateSizeBytes = bufferSizes.m_maxSearchStateSizeBytes;
  if ( bufferSizes.m_maxSearchStateSizeBytes <= 0 )
    m_maxSearchStateSizeBytes = 37376;
  bufferSizes.m_maxSearchStateSizeBytes = m_maxSearchStateSizeBytes;
  v13 = *(_QWORD *)&nextJobOut->m_data[76];
  v89 = (hkaiSearchParameters::BufferSizes)v13;
  if ( nextJobOut->m_data[43] )
  {
    if ( (int)v13 <= 0 )
      LODWORD(v13) = 2048;
    v89.m_maxOpenSetSizeBytes = v13;
    if ( v89.m_maxSearchStateSizeBytes <= 0 )
      v89.m_maxSearchStateSizeBytes = 9728;
  }
  else
  {
    v89 = 0i64;
  }
  v14 = *(unsigned int *)&nextJobOut->m_data[112];
  v15 = (unsigned __int8)nextJobOut->m_data[45];
  v16 = *(_DWORD *)&nextJobOut->m_data[88];
  v17 = *(float *)&nextJobOut->m_data[52];
  v95 = v14;
  v115 = v16;
  v101 = v15;
  if ( (int)v14 > 0 )
  {
    v98 = v14;
    do
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v19 = Value[1];
      if ( v19 < Value[3] )
      {
        *(_QWORD *)v19 = "LtMtPathAStar";
        *(_QWORD *)(v19 + 16) = "StInit";
        v20 = __rdtsc();
        *(_DWORD *)(v19 + 8) = v20;
        Value[1] = v19 + 24;
      }
      v21 = *(__m128i *)(v2 + 48);
      v22.m_quad = *(__m128 *)(v2 + 16);
      v23.m_quad = *(__m128 *)v2;
      *(_OWORD *)&command.m_startFaceKey = *(_OWORD *)(v2 + 32);
      v24 = *(_OWORD *)(v2 + 80);
      v102 = v2 + 112;
      *(_OWORD *)&command.m_edgesOut = v24;
      command.m_goalPoint = (hkVector4f)v22.m_quad;
      v25 = *(_OWORD *)(v2 + 64);
      *(__m128i *)&command.m_multipleGoalFaceKeys = v21;
      v26 = _mm_cvtsi128_si32(_mm_srli_si128(v21, 8));
      v27 = v16 / (int)v14;
      v28 = _mm_cvtsi128_si32(_mm_srli_si128(v21, 12));
      *(_OWORD *)&command.m_agentInfo.m_diameter = v25;
      v29 = *(_OWORD *)(v2 + 96);
      if ( v28 < v16 / (int)v14 )
        v27 = v28;
      command.m_startPoint = (hkVector4f)v23.m_quad;
      *(_OWORD *)&command.m_pointsOut = v29;
      if ( v26 <= 1 )
      {
        p_m_goalPoint = &command.m_goalPoint;
        p_m_goalFaceKey = (hkVector4f *)&command.m_goalFaceKey;
      }
      else
      {
        p_m_goalPoint = command.m_multipleGoalPoints;
        p_m_goalFaceKey = (hkVector4f *)command.m_multipleGoalFaceKeys;
      }
      pArr = p_m_goalPoint;
      graph.m_startPoint = (hkVector4f)v23.m_quad;
      v32 = 0;
      graph.m_startFaceKey = command.m_startFaceKey;
      v33 = nextJobOut->m_data[46] == 0;
      graph.m_info = command.m_agentInfo;
      graph.m_endPoints = p_m_goalPoint;
      graph.m_flags = 0;
      graph.m_numGoals = v26;
      graph.m_endFaceKeys = (const unsigned int *)p_m_goalFaceKey;
      if ( command.m_agentInfo.m_diameter > (float)(v17 * 2.0) )
      {
        v32 = 4;
        if ( v101 == 1 )
          v32 = 12;
        graph.m_flags = v32;
      }
      if ( !v33 )
        graph.m_flags = v32 | 0x20;
      m_maxEdgesOut = command.m_maxEdgesOut;
      m_goalFoundIndex = -1;
      *(_WORD *)&v88.m_status.m_storage = 2;
      v88.m_numIterations = 0;
      LOBYTE(v36) = 2;
      *(_QWORD *)&v88.m_goalIndex = 0x7F7FFFEEFFFFFFFFi64;
      statesOut.m_data = 0i64;
      statesOut.m_size = 0;
      statesOut.m_capacityAndFlags = 0x80000000;
      v92 = command.m_maxEdgesOut;
      if ( command.m_maxEdgesOut )
      {
        v37 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        m_cur = (unsigned int *)v37->m_cur;
        v39 = (4 * m_maxEdgesOut + 127) & 0xFFFFFF80;
        v40 = (char *)m_cur + v39;
        if ( v39 > v37->m_slabSize || v40 > v37->m_end )
          m_cur = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v37, v39);
        else
          v37->m_cur = v40;
      }
      else
      {
        m_cur = 0i64;
      }
      statesOut.m_data = m_cur;
      statesOut.m_capacityAndFlags = m_maxEdgesOut | 0x80000000;
      p = m_cur;
      v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v42 = (_QWORD *)v41[1];
      v43 = v41;
      if ( (unsigned __int64)v42 < v41[3] )
      {
        *v42 = "StLineOfSight";
        v44 = __rdtsc();
        v45 = v42 + 2;
        *((_DWORD *)v45 - 2) = v44;
        v43[1] = v45;
      }
      v46 = command.m_startFaceKey != -1 && command.m_numGoals > 0;
      v113 = 0;
      v97 = 0;
      Path = 0;
      v114 = -1;
      if ( v46 )
      {
        v47 = nextJobOut->m_data[42];
        if ( (v47 & 4) != 0 || (v47 & 1) != 0 && !*(_QWORD *)&nextJobOut->m_data[24] )
        {
          evalFunc.m_p.m_quad = (__m128)command.m_startPoint;
          v114 = hkAlgorithm::findMinimumIndex<hkVector4f,hkVector4UtilImpl<float>::DistanceToPoint>(
                   pArr,
                   v26,
                   &evalFunc);
          hkaiLineOfSightUtil::LineOfSightInput::LineOfSightInput(&input);
          input.m_maxNumberOfIterations = v27;
          input.m_startPoint = command.m_startPoint;
          input.m_up = (hkVector4f)up.m_quad;
          v48.m_quad = (__m128)pArr[v114];
          input.m_agentInfo = graph.m_info;
          v49 = nextJobOut->m_data[44];
          input.m_goalPoint = (hkVector4f)v48.m_quad;
          input.m_searchRadius = *(float *)&nextJobOut->m_data[60];
          v48.m_quad.m128_i32[0] = *(_DWORD *)&nextJobOut->m_data[56];
          input.m_projectedRadiusCheck.m_bool = v49;
          v50 = *(hkaiAstarCostModifier **)&nextJobOut->m_data[24];
          input.m_startFaceKey = command.m_startFaceKey;
          LODWORD(input.m_maximumPathLength) = v48.m_quad.m128_i32[0];
          v51 = p_m_goalFaceKey->m_quad.m128_u32[v114];
          input.m_costModifier = v50;
          input.m_edgeFilter = *(hkaiAstarEdgeFilter **)&nextJobOut->m_data[32];
          LOBYTE(v50) = nextJobOut->m_data[42];
          input.m_goalFaceKey = v51;
          input.m_exactInternalVertexHandling.m_bool = ((unsigned __int8)v50 & 2) != 0;
          hkaiLineOfSightUtil::LineOfSightOutput::LineOfSightOutput(&output);
          v52 = *(hkaiStreamingCollection::InstanceInfo **)&nextJobOut->m_data[96];
          output.m_visitedEdgesOut.m_data = statesOut.m_data;
          output.m_doNotExceedArrayCapacity.m_bool = 1;
          output.m_visitedEdgesOut.m_size = 0;
          output.m_visitedEdgesOut.m_capacityAndFlags = statesOut.m_capacityAndFlags & 0x3FFFFFFF | 0x80000000;
          v53 = hkaiLineOfSightUtil::checkLineOfSight(v52, &input, &output);
          statesOut.m_size = output.m_visitedEdgesOut.m_size;
          v113 = v53;
          if ( v53 )
          {
            m_goalFoundIndex = v114;
            LOBYTE(v36) = 1;
            v88.m_goalIndex = v114;
            v88.m_pathLength = output.m_accumulatedDistance;
            v88.m_numIterations = 0;
            v88.m_status.m_storage = 1;
          }
          hkaiLineOfSightUtil::LineOfSightOutput::~LineOfSightOutput(&output);
        }
      }
      v54 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v55 = (_QWORD *)v54[1];
      if ( (unsigned __int64)v55 < v54[3] )
      {
        *v55 = "StAStar";
        v56 = __rdtsc();
        v57 = v55 + 2;
        *((_DWORD *)v57 - 2) = v56;
        v54[1] = v57;
      }
      v4 = !v46;
      v58 = v113;
      if ( !v4 && !v113 )
      {
        hkaiSearchMemoryLocalStorage::hkaiSearchMemoryLocalStorage((hkaiSearchMemoryLocalStorage *)&input, &bufferSizes);
        hkaiSearchMemoryLocalStorage::hkaiSearchMemoryLocalStorage(&v110, &v89);
        hkaiNavMeshSearch::hkaiNavMeshSearch(&v111, (hkaiSearchMemoryInfo *)&input, &v110);
        v4 = nextJobOut->m_data[43] == 0;
        v59 = *(float *)&nextJobOut->m_data[56];
        output.m_visitedEdgesOut = (hkArray<unsigned int,hkContainerHeapAllocator>)command.m_startPoint;
        v111.m_state.m_maxPathCost = v59;
        v60 = *(float *)&nextJobOut->m_data[48];
        graph.m_searchState = &v111.m_state;
        v111.m_state.m_heuristicWeight = v60;
        output.m_distancesOut.m_size = command.m_startFaceKey;
        output.m_distancesOut.m_data = (float *)pArr;
        output.m_pointsOut.m_data = p_m_goalFaceKey;
        output.m_pointsOut.m_size = v26;
        hkaiNavMeshSearch::init(&v111, &graph, &graph.m_info, (hkaiNavMeshSearch::StartGoalInfo *)&output, !v4);
        v61 = 0;
        v62 = 0;
        while ( v62 < v27 )
        {
          --v115;
          ++v62;
          v63 = hkaiNavMeshSearch::iteration(&v111);
          v36 = v63;
          if ( v63 == 3 )
          {
            v61 = (v111.m_openset.m_heapSize < v111.m_openset.m_maxSize) + 2;
            goto LABEL_59;
          }
          if ( v63 )
            goto LABEL_59;
        }
        v36 = 3;
        v61 = 1;
LABEL_59:
        v88.m_terminationCause.m_storage = v61;
        m_goalFoundIndex = -1;
        *(_QWORD *)&v88.m_numIterations = (unsigned int)v62 | 0xFFFFFFFF00000000ui64;
        v88.m_status.m_storage = v36;
        if ( ((v36 - 1) & 0xFFFFFFFD) == 0 )
        {
          m_bestNode = v111.m_state.m_bestNode;
          v97 = v36 == 1;
          if ( v36 == 1 )
            m_bestNode = v111.m_lastClosedNode;
          NodeState = hkaiHashSearchState::getNodeState(&v111.m_state, m_bestNode);
          m_goalFoundIndex = v111.m_goalFoundIndex;
          v111.m_state.m_currentNodeState = NodeState;
          v111.m_state.m_parentNodeState = NodeState;
          v88.m_goalIndex = v111.m_goalFoundIndex;
          v111.m_state.m_parentIndex = (__int16)(NodeState - v111.m_state.m_nodes);
          v88.m_pathLength = NodeState->m_gCost;
          Path = hkaiSearchStateUtils::getPath(
                   &v111.m_state,
                   m_bestNode,
                   GET_PATH_IGNORE_START_AND_END,
                   &statesOut,
                   command.m_maxEdgesOut);
        }
        hkaiSearchMemoryLocalStorage::~hkaiSearchMemoryLocalStorage(&v110);
        hkaiSearchMemoryLocalStorage::~hkaiSearchMemoryLocalStorage((hkaiSearchMemoryLocalStorage *)&input);
        v58 = v113;
      }
      v66 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v67 = (_QWORD *)v66[1];
      if ( (unsigned __int64)v67 < v66[3] )
      {
        *v67 = "StOutput+Smooth";
        v68 = __rdtsc();
        v69 = v67 + 2;
        *((_DWORD *)v69 - 2) = v68;
        v66[1] = v69;
      }
      if ( (_BYTE)v36 == 2 )
      {
        hkaiNavMeshAStarJob_failure(&command);
      }
      else if ( (((_BYTE)v36 - 1) & 0xFD) == 0 )
      {
        m_pointsOut = command.m_pointsOut;
        if ( !command.m_pointsOut || (m_maxPointsOut = command.m_maxPointsOut, command.m_maxPointsOut <= 0) )
        {
LABEL_91:
          m_edgesOut = command.m_edgesOut;
          if ( command.m_edgesOut )
          {
            if ( statesOut.m_size < (statesOut.m_capacityAndFlags & 0x3FFFFFFF) )
            {
              statesOut.m_data[statesOut.m_size++] = -1;
              m_edgesOut = command.m_edgesOut;
            }
            m_size = command.m_maxEdgesOut;
            if ( statesOut.m_size < command.m_maxEdgesOut )
              m_size = statesOut.m_size;
            hkString::memCpy(m_edgesOut, statesOut.m_data, 4 * m_size);
          }
          goto LABEL_97;
        }
        if ( v58 )
        {
          v72 = nextJobOut->m_data[41];
          if ( (v72 & 1) != 0
            && !hkaiNavMeshPathSmoothingUtil::projectStraightPath(
                  graph.m_streamingInfo,
                  &statesOut,
                  command.m_startFaceKey,
                  &command.m_startPoint,
                  &pArr[v114],
                  v72 & 2,
                  v72 & 4,
                  &up,
                  graph.m_info.m_diameter * 0.5,
                  0i64,
                  command.m_pointsOut,
                  command.m_maxPointsOut)
            && (_BYTE)v36 == 1 )
          {
            v88.m_status.m_storage = 4;
          }
          goto LABEL_91;
        }
        if ( v97 && Path )
        {
          m_quad = pArr[m_goalFoundIndex].m_quad;
          goto LABEL_85;
        }
        if ( statesOut.m_size )
        {
          hkaiStreamingCollection::getEdgePoints(
            *(hkaiStreamingCollection::InstanceInfo **)&nextJobOut->m_data[96],
            statesOut.m_data[statesOut.m_size - 1],
            &ea,
            &eb);
          m_maxPointsOut = command.m_maxPointsOut;
          m_pointsOut = command.m_pointsOut;
          endPoint.m_quad = _mm_add_ps(
                              _mm_mul_ps(_mm_sub_ps(eb.m_quad, ea.m_quad), (__m128)xmmword_141A711B0),
                              ea.m_quad);
          if ( (_BYTE)v36 == 1 )
          {
            LOBYTE(v36) = 4;
            v88.m_status.m_storage = 4;
          }
        }
        else
        {
          m_quad = command.m_startPoint.m_quad;
LABEL_85:
          endPoint.m_quad = m_quad;
        }
        v74 = nextJobOut->m_data[41];
        if ( (v74 & 1) != 0
          && !(unsigned int)hkaiNavMeshPathSmoothingUtil::findSmoothedPathMain(
                              graph.m_streamingInfo,
                              &statesOut,
                              command.m_startFaceKey,
                              &command.m_startPoint,
                              &endPoint,
                              v74 & 2,
                              v74 & 4,
                              &up,
                              graph.m_info.m_diameter * 0.5,
                              v17 >= (float)(graph.m_info.m_diameter * 0.5),
                              0i64,
                              m_pointsOut,
                              m_maxPointsOut,
                              0i64) )
        {
          v75 = v36;
          if ( (_BYTE)v36 == 1 )
            v75 = 4;
          v88.m_status.m_storage = v75;
        }
        goto LABEL_91;
      }
LABEL_97:
      if ( command.m_AStarOutput )
        *command.m_AStarOutput = v88;
      v78 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v79 = (_QWORD *)v78[1];
      if ( (unsigned __int64)v79 < v78[3] )
      {
        *v79 = "lt";
        v80 = __rdtsc();
        v81 = v79 + 2;
        *((_DWORD *)v81 - 2) = v80;
        v78[1] = v81;
      }
      v82 = statesOut.m_size;
      v83 = (char *)p;
      if ( p == statesOut.m_data )
        v82 = 0;
      statesOut.m_size = v82;
      v84 = (4 * v92 + 127) & 0xFFFFFF80;
      v85 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v86 = (v84 + 15) & 0xFFFFFFF0;
      if ( v84 > v85->m_slabSize || &v83[v86] != v85->m_cur || v85->m_firstNonLifoEnd == v83 )
        hkLifoAllocator::slowBlockFree(v85, v83, v86);
      else
        v85->m_cur = v83;
      statesOut.m_size = 0;
      if ( statesOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          statesOut.m_data,
          4 * statesOut.m_capacityAndFlags);
      v16 = v115;
      v2 = v102;
      LODWORD(v14) = v95 - 1;
      v4 = v98-- == 1;
      --v95;
    }
    while ( !v4 );
  }
  return hkJobQueue::finishJobAndGetNextJob(jobQueue, nextJobOut, nextJobOut, WAIT_FOR_NEXT_JOB);
}

// File Line: 473
// RVA: 0xC0F8D0
void __fastcall hkaiNavMeshAStarJob_failure(hkaiNavMeshAStarCommand *command)
{
  unsigned int *m_edgesOut; // rax
  hkaiPathWriter v3; // [rsp+20h] [rbp-48h] BYREF

  m_edgesOut = command->m_edgesOut;
  if ( m_edgesOut && command->m_maxEdgesOut > 0 )
    *m_edgesOut = -1;
  if ( command->m_maxPointsOut > 0 )
  {
    hkaiPathWriter::hkaiPathWriter(&v3);
    hkaiPathWriter::init(&v3, 0i64, command->m_pointsOut, command->m_maxPointsOut);
    hkaiPathWriter::addTerminatorToPathPointer(&v3);
  }
}


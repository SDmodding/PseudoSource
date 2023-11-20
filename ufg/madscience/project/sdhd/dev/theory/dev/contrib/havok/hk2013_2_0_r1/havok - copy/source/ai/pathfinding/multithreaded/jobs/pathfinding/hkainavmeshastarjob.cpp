// File Line: 38
// RVA: 0xC0ECF0
hkJobQueue::JobStatus __fastcall hkaiProcessNavMeshAStarJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  __int64 v2; // rdi
  hkJobQueue::JobQueueEntry *v3; // r14
  bool v4; // zf
  hkaiAstarEdgeFilter *v5; // rcx
  hkaiAstarCostModifier *v6; // rdx
  float v7; // xmm2_4
  __m128i v8; // xmm1
  hkaiStreamingCollection::InstanceInfo *v9; // rax
  unsigned int v10; // eax
  hkSimdFloat32 v11; // xmm0
  signed int v12; // eax
  signed int v13; // eax
  __int64 v14; // rax
  __int64 v15; // rsi
  __int64 v16; // rax
  int v17; // ebx
  float v18; // xmm8_4
  _QWORD *v19; // r8
  unsigned __int64 v20; // rcx
  unsigned __int64 v21; // rax
  __m128i v22; // xmm2
  hkVector4f v23; // xmm0
  hkVector4f v24; // xmm3
  __int128 v25; // xmm1
  __int128 v26; // xmm0
  int v27; // er13
  int v28; // er15
  int v29; // ecx
  __int128 v30; // xmm0
  hkVector4f *v31; // rdx
  hkVector4f *v32; // r12
  unsigned int v33; // ecx
  bool v34; // zf
  int v35; // ebx
  int v36; // esi
  signed int v37; // edi
  LPVOID v38; // rax
  hkLifoAllocator *v39; // rcx
  unsigned int *v40; // rax
  int v41; // edx
  char *v42; // r8
  _QWORD *v43; // rax
  _QWORD *v44; // rcx
  _QWORD *v45; // r8
  unsigned __int64 v46; // rax
  signed __int64 v47; // rcx
  BOOL v48; // ebx
  char v49; // al
  hkVector4f *v50; // rcx
  hkVector4f v51; // xmm0
  char v52; // al
  hkaiAstarCostModifier *v53; // rax
  unsigned int v54; // ecx
  hkaiStreamingCollection::InstanceInfo *v55; // rcx
  int v56; // eax
  _QWORD *v57; // r8
  _QWORD *v58; // rcx
  unsigned __int64 v59; // rax
  signed __int64 v60; // rcx
  int v61; // ebx
  float v62; // xmm1_4
  float v63; // xmm0_4
  char v64; // si
  int v65; // ebx
  signed int v66; // eax
  unsigned int v67; // ebx
  hkaiSearchStateNode *v68; // rax
  _QWORD *v69; // r8
  _QWORD *v70; // rcx
  unsigned __int64 v71; // rax
  signed __int64 v72; // rcx
  hkaiPath::PathPoint *v73; // r9
  int v74; // er8
  char v75; // al
  __m128 v76; // xmm0
  char v77; // al
  char v78; // al
  unsigned int *v79; // r9
  int v80; // er8
  _QWORD *v81; // r8
  _QWORD *v82; // rcx
  unsigned __int64 v83; // rax
  signed __int64 v84; // rcx
  int v85; // eax
  char *v86; // rdi
  signed int v87; // ebx
  hkLifoAllocator *v88; // rax
  int v89; // er8
  __m128i v91; // [rsp+70h] [rbp-90h]
  hkaiSearchParameters::BufferSizes v92; // [rsp+80h] [rbp-80h]
  hkArray<unsigned int,hkContainerHeapAllocator> statesOut; // [rsp+88h] [rbp-78h]
  void *p; // [rsp+98h] [rbp-68h]
  int v95; // [rsp+A0h] [rbp-60h]
  hkVector4f *pArr; // [rsp+A8h] [rbp-58h]
  hkaiSearchParameters::BufferSizes bufferSizes; // [rsp+B0h] [rbp-50h]
  int v98; // [rsp+B8h] [rbp-48h]
  int v99; // [rsp+BCh] [rbp-44h]
  BOOL v100; // [rsp+C0h] [rbp-40h]
  __int64 v101; // [rsp+C8h] [rbp-38h]
  hkaiNavMeshAStarCommand command; // [rsp+D0h] [rbp-30h]
  hkVector4f up; // [rsp+140h] [rbp+40h]
  __int64 v104; // [rsp+150h] [rbp+50h]
  __int64 v105; // [rsp+158h] [rbp+58h]
  hkVector4f endPoint; // [rsp+160h] [rbp+60h]
  hkaiLineOfSightUtil::LineOfSightOutput output; // [rsp+170h] [rbp+70h]
  hkaiLineOfSightUtil::LineOfSightInput input; // [rsp+1C0h] [rbp+C0h]
  hkVector4UtilImpl<float>::DistanceToPoint evalFunc; // [rsp+230h] [rbp+130h]
  hkVector4f ea; // [rsp+240h] [rbp+140h]
  hkVector4f eb; // [rsp+250h] [rbp+150h]
  hkaiNavMeshSectionGraph graph; // [rsp+260h] [rbp+160h]
  hkaiSearchMemoryLocalStorage v113; // [rsp+4A0h] [rbp+3A0h]
  hkaiNavMeshSearch v114; // [rsp+500h] [rbp+400h]
  hkJobQueue *v115; // [rsp+AA0h] [rbp+9A0h]
  int v116; // [rsp+AA8h] [rbp+9A8h]
  unsigned int v117; // [rsp+AB0h] [rbp+9B0h]
  int v118; // [rsp+AB0h] [rbp+9B0h]
  int v119; // [rsp+AB8h] [rbp+9B8h]

  v115 = jobQueue;
  v2 = *(_QWORD *)&nextJobOut->m_data[104];
  v3 = nextJobOut;
  v4 = nextJobOut->m_data[44] == 0;
  v5 = *(hkaiAstarEdgeFilter **)&nextJobOut->m_data[32];
  v6 = *(hkaiAstarCostModifier **)&nextJobOut->m_data[24];
  v7 = *(float *)&v3->m_data[64];
  v8 = _mm_unpacklo_epi16((__m128i)0i64, _mm_loadl_epi64((const __m128i *)&v3->m_data[16]));
  v117 = *(_DWORD *)&v3->m_data[64];
  v9 = *(hkaiStreamingCollection::InstanceInfo **)&v3->m_data[96];
  graph.m_edgeFilter = v5;
  graph.m_streamingInfo = v9;
  graph.m_costModifier = v6;
  v10 = 0;
  *(_QWORD *)&graph.m_cachedIncomingEdge.m_oppositeEdge = -1i64;
  *(_DWORD *)&graph.m_cachedIncomingEdge.m_flags.m_storage = 4;
  up.m_quad = _mm_mul_ps(
                _mm_cvtepi32_ps(_mm_add_epi32(v8, _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset))),
                (__m128)xmmword_141A713A0);
  graph.m_up = (hkVector4f)up.m_quad;
  v11.m_real = _mm_shuffle_ps((__m128)*(unsigned int *)&v3->m_data[60], (__m128)*(unsigned int *)&v3->m_data[60], 0);
  if ( *(float *)&v3->m_data[60] >= 0.0 )
    v10 = 1;
  *(_QWORD *)&graph.m_cachedOutgoingEdge.m_oppositeEdge = -1i64;
  graph.m_searchSphereRadius = (hkSimdFloat32)v11.m_real;
  *(_DWORD *)&graph.m_cachedOutgoingEdge.m_flags.m_storage = 4;
  *(_QWORD *)&graph.m_cachedOppositeEdge.m_oppositeEdge = -1i64;
  *(_DWORD *)&graph.m_cachedOppositeEdge.m_flags.m_storage = 4;
  graph.m_searchCapsuleRadius.m_real = _mm_shuffle_ps((__m128)v117, (__m128)v117, 0);
  graph.m_cachedEdgePairInfo.m_incomingEdgeInfo.m_edgeKey = -1;
  graph.m_cachedEdgePairInfo.m_incomingEdgeInfo.m_edge = 0i64;
  graph.m_cachedEdgePairInfo.m_outgoingEdgeInfo.m_edgeKey = -1;
  graph.m_cachedEdgePairInfo.m_outgoingEdgeInfo.m_edge = 0i64;
  graph.m_cachedEdgePairInfo.m_faceKey = -1;
  graph.m_cachedEdgePairInfo.m_face = 0i64;
  graph.m_info = 0i64;
  graph.m_startFaceKey = -1;
  graph.m_numGoals = 0;
  graph.m_cachedIncomingNavMesh = 0i64;
  graph.m_cachedOutgoingNavMesh = 0i64;
  *(_QWORD *)&graph.m_cachedIncomingSectionId = -1i64;
  graph.m_searchState = 0i64;
  if ( v7 >= 0.0 )
    v10 |= 2u;
  if ( !v4 )
    v10 |= 0x10u;
  graph.m_flags = v10;
  bufferSizes = *(hkaiSearchParameters::BufferSizes *)&v3->m_data[68];
  v12 = bufferSizes.m_maxOpenSetSizeBytes;
  if ( bufferSizes.m_maxOpenSetSizeBytes <= 0 )
    v12 = 0x2000;
  bufferSizes.m_maxOpenSetSizeBytes = v12;
  v13 = bufferSizes.m_maxSearchStateSizeBytes;
  if ( bufferSizes.m_maxSearchStateSizeBytes <= 0 )
    v13 = 37376;
  bufferSizes.m_maxSearchStateSizeBytes = v13;
  v14 = *(_QWORD *)&v3->m_data[76];
  v92 = *(hkaiSearchParameters::BufferSizes *)&v3->m_data[76];
  if ( v3->m_data[43] )
  {
    if ( (signed int)v14 <= 0 )
      LODWORD(v14) = 2048;
    v92.m_maxOpenSetSizeBytes = v14;
    if ( v92.m_maxSearchStateSizeBytes <= 0 )
      v92.m_maxSearchStateSizeBytes = 9728;
  }
  else
  {
    v92 = 0i64;
  }
  v15 = *(unsigned int *)&v3->m_data[112];
  v16 = (unsigned __int8)v3->m_data[45];
  v17 = *(_DWORD *)&v3->m_data[88];
  v18 = *(float *)&v3->m_data[52];
  v98 = v15;
  v119 = v17;
  v104 = v16;
  if ( (signed int)v15 > 0 )
  {
    v101 = v15;
    do
    {
      v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v20 = v19[1];
      if ( v20 < v19[3] )
      {
        *(_QWORD *)v20 = "LtMtPathAStar";
        *(_QWORD *)(v20 + 16) = "StInit";
        v21 = __rdtsc();
        *(_DWORD *)(v20 + 8) = v21;
        v19[1] = v20 + 24;
      }
      v22 = *(__m128i *)(v2 + 48);
      v23.m_quad = *(__m128 *)(v2 + 16);
      v24.m_quad = *(__m128 *)v2;
      *(_OWORD *)&command.m_startFaceKey = *(_OWORD *)(v2 + 32);
      v25 = *(_OWORD *)(v2 + 80);
      v105 = v2 + 112;
      *(_OWORD *)&command.m_edgesOut = v25;
      command.m_goalPoint = (hkVector4f)v23.m_quad;
      v26 = *(_OWORD *)(v2 + 64);
      *(__m128i *)&command.m_multipleGoalFaceKeys = v22;
      v27 = _mm_cvtsi128_si32(_mm_srli_si128(v22, 8));
      v28 = v17 / (signed int)v15;
      v29 = _mm_cvtsi128_si32(_mm_srli_si128(v22, 12));
      *(_OWORD *)&command.m_agentInfo.m_diameter = v26;
      v30 = *(_OWORD *)(v2 + 96);
      if ( v29 < v17 / (signed int)v15 )
        v28 = v29;
      command.m_startPoint = (hkVector4f)v24.m_quad;
      *(_OWORD *)&command.m_pointsOut = v30;
      if ( v27 <= 1 )
      {
        v31 = &command.m_goalPoint;
        v32 = (hkVector4f *)&command.m_goalFaceKey;
      }
      else
      {
        v31 = command.m_multipleGoalPoints;
        v32 = (hkVector4f *)command.m_multipleGoalFaceKeys;
      }
      pArr = v31;
      graph.m_startPoint = (hkVector4f)v24.m_quad;
      v33 = 0;
      graph.m_startFaceKey = command.m_startFaceKey;
      v34 = v3->m_data[46] == 0;
      graph.m_info = command.m_agentInfo;
      graph.m_endPoints = v31;
      graph.m_flags = 0;
      graph.m_numGoals = v27;
      graph.m_endFaceKeys = (const unsigned int *)v32;
      if ( command.m_agentInfo.m_diameter > (float)(v18 * 2.0) )
      {
        v33 = 4;
        if ( v104 == 1 )
          v33 = 12;
        graph.m_flags = v33;
      }
      if ( !v34 )
        graph.m_flags = v33 | 0x20;
      v35 = command.m_maxEdgesOut;
      v36 = -1;
      v91.m128i_i16[6] = 2;
      v91.m128i_i32[0] = 0;
      LOBYTE(v37) = 2;
      *(__int64 *)((char *)v91.m128i_i64 + 4) = 9187343166821367807i64;
      statesOut.m_data = 0i64;
      statesOut.m_size = 0;
      statesOut.m_capacityAndFlags = 2147483648;
      v95 = command.m_maxEdgesOut;
      if ( command.m_maxEdgesOut )
      {
        v38 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v39 = (hkLifoAllocator *)v38;
        v40 = (unsigned int *)*((_QWORD *)v38 + 3);
        v41 = (4 * v35 + 127) & 0xFFFFFF80;
        v42 = (char *)v40 + v41;
        if ( v41 > v39->m_slabSize || v42 > v39->m_end )
          v40 = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v39, v41);
        else
          v39->m_cur = v42;
      }
      else
      {
        v40 = 0i64;
      }
      statesOut.m_data = v40;
      statesOut.m_capacityAndFlags = v35 | 0x80000000;
      p = v40;
      v43 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v44 = (_QWORD *)v43[1];
      v45 = v43;
      if ( (unsigned __int64)v44 < v43[3] )
      {
        *v44 = "StLineOfSight";
        v46 = __rdtsc();
        v47 = (signed __int64)(v44 + 2);
        *(_DWORD *)(v47 - 8) = v46;
        v45[1] = v47;
      }
      v48 = command.m_startFaceKey != -1 && command.m_numGoals > 0;
      v116 = 0;
      v100 = 0;
      v99 = 0;
      v118 = -1;
      if ( v48 )
      {
        v49 = v3->m_data[42];
        if ( v49 & 4 || v49 & 1 && !*(_QWORD *)&v3->m_data[24] )
        {
          v50 = pArr;
          _mm_store_si128((__m128i *)&evalFunc, (__m128i)command.m_startPoint.m_quad);
          v118 = hkAlgorithm::findMinimumIndex<hkVector4f,hkVector4UtilImpl<float>::DistanceToPoint>(
                   v50,
                   v27,
                   &evalFunc);
          hkaiLineOfSightUtil::LineOfSightInput::LineOfSightInput(&input);
          input.m_maxNumberOfIterations = v28;
          input.m_startPoint = command.m_startPoint;
          input.m_up = (hkVector4f)up.m_quad;
          v51.m_quad = (__m128)pArr[v118];
          input.m_agentInfo = graph.m_info;
          v52 = v3->m_data[44];
          input.m_goalPoint = (hkVector4f)v51.m_quad;
          input.m_searchRadius = *(float *)&v3->m_data[60];
          v51.m_quad.m128_i32[0] = *(_DWORD *)&v3->m_data[56];
          input.m_projectedRadiusCheck.m_bool = v52;
          v53 = *(hkaiAstarCostModifier **)&v3->m_data[24];
          input.m_startFaceKey = command.m_startFaceKey;
          LODWORD(input.m_maximumPathLength) = v51.m_quad.m128_i32[0];
          v54 = v32->m_quad.m128_u32[v118];
          input.m_costModifier = v53;
          input.m_edgeFilter = *(hkaiAstarEdgeFilter **)&v3->m_data[32];
          LOBYTE(v53) = v3->m_data[42];
          input.m_goalFaceKey = v54;
          input.m_exactInternalVertexHandling.m_bool = ((unsigned __int8)v53 >> 1) & 1;
          hkaiLineOfSightUtil::LineOfSightOutput::LineOfSightOutput(&output);
          v55 = *(hkaiStreamingCollection::InstanceInfo **)&v3->m_data[96];
          output.m_visitedEdgesOut.m_data = statesOut.m_data;
          output.m_doNotExceedArrayCapacity.m_bool = 1;
          output.m_visitedEdgesOut.m_size = 0;
          output.m_visitedEdgesOut.m_capacityAndFlags = statesOut.m_capacityAndFlags & 0x3FFFFFFF | 0x80000000;
          v56 = hkaiLineOfSightUtil::checkLineOfSight(v55, &input, &output);
          statesOut.m_size = output.m_visitedEdgesOut.m_size;
          v116 = v56;
          if ( v56 )
          {
            v36 = v118;
            LOBYTE(v37) = 1;
            v91.m128i_i32[1] = v118;
            v91.m128i_i32[2] = LODWORD(output.m_accumulatedDistance);
            v91.m128i_i32[0] = 0;
            v91.m128i_i8[12] = 1;
          }
          hkaiLineOfSightUtil::LineOfSightOutput::~LineOfSightOutput(&output);
        }
      }
      v57 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v58 = (_QWORD *)v57[1];
      if ( (unsigned __int64)v58 < v57[3] )
      {
        *v58 = "StAStar";
        v59 = __rdtsc();
        v60 = (signed __int64)(v58 + 2);
        *(_DWORD *)(v60 - 8) = v59;
        v57[1] = v60;
      }
      v4 = v48 == 0;
      v61 = v116;
      if ( !v4 && !v116 )
      {
        hkaiSearchMemoryLocalStorage::hkaiSearchMemoryLocalStorage((hkaiSearchMemoryLocalStorage *)&input, &bufferSizes);
        hkaiSearchMemoryLocalStorage::hkaiSearchMemoryLocalStorage(&v113, &v92);
        hkaiNavMeshSearch::hkaiNavMeshSearch(
          &v114,
          (hkaiSearchMemoryInfo *)&input,
          (hkaiSearchMemoryInfo *)&v113.m_openSetBuffer);
        v4 = v3->m_data[43] == 0;
        v62 = *(float *)&v3->m_data[56];
        output.m_visitedEdgesOut = (hkArray<unsigned int,hkContainerHeapAllocator>)command.m_startPoint;
        v114.m_state.m_maxPathCost = v62;
        v63 = *(float *)&v3->m_data[48];
        graph.m_searchState = &v114.m_state;
        v114.m_state.m_heuristicWeight = v63;
        output.m_distancesOut.m_size = command.m_startFaceKey;
        output.m_distancesOut.m_data = (float *)pArr;
        output.m_pointsOut.m_data = v32;
        output.m_pointsOut.m_size = v27;
        hkaiNavMeshSearch::init(&v114, &graph, &graph.m_info, (hkaiNavMeshSearch::StartGoalInfo *)&output, !v4);
        v64 = 0;
        v65 = 0;
        while ( v65 < v28 )
        {
          --v119;
          ++v65;
          v66 = hkaiNavMeshSearch::iteration(&v114);
          v37 = v66;
          if ( v66 == 3 )
          {
            v64 = (v114.m_openset.m_heapSize < v114.m_openset.m_maxSize) + 2;
            goto LABEL_59;
          }
          if ( v66 )
            goto LABEL_59;
        }
        v37 = 3;
        v64 = 1;
LABEL_59:
        v91.m128i_i8[13] = v64;
        v36 = -1;
        v91.m128i_i64[0] = __PAIR__(-1, v65);
        v91.m128i_i8[12] = v37;
        if ( !((v37 - 1) & 0xFFFFFFFD) )
        {
          v67 = v114.m_state.m_bestNode;
          v100 = v37 == 1;
          if ( v37 == 1 )
            v67 = v114.m_lastClosedNode;
          v68 = hkaiHashSearchState::getNodeState(&v114.m_state, v67);
          v36 = v114.m_goalFoundIndex;
          v114.m_state.m_currentNodeState = v68;
          v114.m_state.m_parentNodeState = v68;
          v91.m128i_i32[1] = v114.m_goalFoundIndex;
          v114.m_state.m_parentIndex = (signed __int16)(v68 - v114.m_state.m_nodes);
          v91.m128i_i32[2] = LODWORD(v68->m_gCost);
          v99 = hkaiSearchStateUtils::getPath(
                  &v114.m_state,
                  v67,
                  GET_PATH_IGNORE_START_AND_END,
                  &statesOut,
                  command.m_maxEdgesOut);
        }
        hkaiSearchMemoryLocalStorage::~hkaiSearchMemoryLocalStorage(&v113);
        hkaiSearchMemoryLocalStorage::~hkaiSearchMemoryLocalStorage((hkaiSearchMemoryLocalStorage *)&input);
        v61 = v116;
      }
      v69 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v70 = (_QWORD *)v69[1];
      if ( (unsigned __int64)v70 < v69[3] )
      {
        *v70 = "StOutput+Smooth";
        v71 = __rdtsc();
        v72 = (signed __int64)(v70 + 2);
        *(_DWORD *)(v72 - 8) = v71;
        v69[1] = v72;
      }
      if ( (_BYTE)v37 == 2 )
      {
        hkaiNavMeshAStarJob_failure(&command);
      }
      else if ( !(((_BYTE)v37 - 1) & 0xFD) )
      {
        v73 = command.m_pointsOut;
        if ( !command.m_pointsOut || (v74 = command.m_maxPointsOut, command.m_maxPointsOut <= 0) )
        {
LABEL_91:
          v79 = command.m_edgesOut;
          if ( command.m_edgesOut )
          {
            if ( statesOut.m_size < (statesOut.m_capacityAndFlags & 0x3FFFFFFF) )
            {
              statesOut.m_data[statesOut.m_size] = -1;
              ++statesOut.m_size;
              v79 = command.m_edgesOut;
            }
            v80 = command.m_maxEdgesOut;
            if ( statesOut.m_size < command.m_maxEdgesOut )
              v80 = statesOut.m_size;
            hkString::memCpy(v79, statesOut.m_data, 4 * v80);
          }
          goto LABEL_97;
        }
        if ( v61 )
        {
          v75 = v3->m_data[41];
          if ( v75 & 1
            && !(unsigned int)hkaiNavMeshPathSmoothingUtil::projectStraightPath(
                                graph.m_streamingInfo,
                                &statesOut,
                                command.m_startFaceKey,
                                &command.m_startPoint,
                                &pArr[v118],
                                v75 & 2,
                                v75 & 4,
                                &up,
                                graph.m_info.m_diameter * 0.5,
                                0i64,
                                command.m_pointsOut,
                                command.m_maxPointsOut)
            && (_BYTE)v37 == 1 )
          {
            v91.m128i_i8[12] = 4;
          }
          goto LABEL_91;
        }
        if ( v100 && v99 )
        {
          v76 = pArr[v36].m_quad;
          goto LABEL_85;
        }
        if ( statesOut.m_size )
        {
          hkaiStreamingCollection::getEdgePoints(
            *(hkaiStreamingCollection::InstanceInfo **)&v3->m_data[96],
            statesOut.m_data[statesOut.m_size - 1],
            &ea,
            &eb);
          v74 = command.m_maxPointsOut;
          v73 = command.m_pointsOut;
          endPoint.m_quad = _mm_add_ps(
                              _mm_mul_ps(_mm_sub_ps(eb.m_quad, ea.m_quad), (__m128)xmmword_141A711B0),
                              ea.m_quad);
          if ( (_BYTE)v37 == 1 )
          {
            LOBYTE(v37) = 4;
            v91.m128i_i8[12] = 4;
          }
        }
        else
        {
          v76 = command.m_startPoint.m_quad;
LABEL_85:
          endPoint.m_quad = v76;
        }
        v77 = v3->m_data[41];
        if ( v77 & 1
          && !(unsigned int)hkaiNavMeshPathSmoothingUtil::findSmoothedPathMain(
                              graph.m_streamingInfo,
                              &statesOut,
                              command.m_startFaceKey,
                              &command.m_startPoint,
                              &endPoint,
                              v77 & 2,
                              v77 & 4,
                              &up,
                              graph.m_info.m_diameter * 0.5,
                              v18 >= (float)(graph.m_info.m_diameter * 0.5),
                              0i64,
                              v73,
                              v74,
                              0i64) )
        {
          v78 = v37;
          if ( (_BYTE)v37 == 1 )
            v78 = 4;
          v91.m128i_i8[12] = v78;
        }
        goto LABEL_91;
      }
LABEL_97:
      if ( command.m_AStarOutput )
        _mm_store_si128((__m128i *)command.m_AStarOutput, v91);
      v81 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v82 = (_QWORD *)v81[1];
      if ( (unsigned __int64)v82 < v81[3] )
      {
        *v82 = "lt";
        v83 = __rdtsc();
        v84 = (signed __int64)(v82 + 2);
        *(_DWORD *)(v84 - 8) = v83;
        v81[1] = v84;
      }
      v85 = statesOut.m_size;
      v86 = (char *)p;
      if ( p == statesOut.m_data )
        v85 = 0;
      statesOut.m_size = v85;
      v87 = (4 * v95 + 127) & 0xFFFFFF80;
      v88 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v89 = (v87 + 15) & 0xFFFFFFF0;
      if ( v87 > v88->m_slabSize || &v86[v89] != v88->m_cur || v88->m_firstNonLifoEnd == v86 )
        hkLifoAllocator::slowBlockFree(v88, v86, v89);
      else
        v88->m_cur = v86;
      statesOut.m_size = 0;
      if ( statesOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          statesOut.m_data,
          4 * statesOut.m_capacityAndFlags);
      v17 = v119;
      v2 = v105;
      LODWORD(v15) = v98 - 1;
      v4 = v101-- == 1;
      --v98;
    }
    while ( !v4 );
  }
  return hkJobQueue::finishJobAndGetNextJob(v115, v3, v3, 0);
}

// File Line: 473
// RVA: 0xC0F8D0
void __fastcall hkaiNavMeshAStarJob_failure(hkaiNavMeshAStarCommand *command)
{
  unsigned int *v1; // rax
  hkaiNavMeshAStarCommand *v2; // rbx
  hkaiPathWriter v3; // [rsp+20h] [rbp-48h]

  v1 = command->m_edgesOut;
  v2 = command;
  if ( v1 && command->m_maxEdgesOut > 0 )
    *v1 = -1;
  if ( command->m_maxPointsOut > 0 )
  {
    hkaiPathWriter::hkaiPathWriter(&v3);
    hkaiPathWriter::init(&v3, 0i64, v2->m_pointsOut, v2->m_maxPointsOut);
    hkaiPathWriter::addTerminatorToPathPointer(&v3);
  }
}


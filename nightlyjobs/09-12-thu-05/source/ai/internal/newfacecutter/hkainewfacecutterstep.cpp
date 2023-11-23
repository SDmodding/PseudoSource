// File Line: 20
// RVA: 0x12F8020
void __fastcall hkaiNewFaceCutterUtil::Step::popInvalidEvents(hkaiNewFaceCutterUtil::State *state)
{
  while ( state->m_eventQueue.m_heap.m_size != 1 )
  {
    if ( hkaiNewFaceCutterUtil::eventIsValid(state, state->m_eventQueue.m_heap.m_data + 1) )
      break;
    hkaiNewFaceCutterUtil::EventQueue::popFront(&state->m_eventQueue);
  }
}

// File Line: 31
// RVA: 0x12F7400
void __fastcall hkaiNewFaceCutterUtil::Step::gatherSegmentsForEvent(
        hkaiNewFaceCutterUtil::State *state,
        hkaiNewFaceCutterUtil::Vec2 eventPos,
        __int16 *lowerBoundIndexOut,
        __int16 *upperBoundIndexOut)
{
  __int16 v4; // r12
  hkaiNewFaceCutterUtil::EventQueue *p_m_eventQueue; // rsi
  char v6; // r14
  __int16 *v7; // rbp
  int v10; // edi
  __int16 v11; // r15
  hkaiNewFaceCutterUtil::Event v12; // xmm0
  hkaiNewFaceCutterUtil::Segment *v13; // r9
  __int64 v14; // rcx
  __int16 m_followingSegment; // r8
  hkaiNewFaceCutterUtil::Event *v16; // rcx
  int v17; // eax
  __int64 m_startingSegmentA; // rdx
  hkaiNewFaceCutterUtil::Segment *v19; // rax
  hkaiNewFaceCutterUtil::Event *m_data; // rcx
  __int16 m_startingSegmentB; // bp
  __int64 v22; // r8
  __int16 m_nextSegment; // cx
  __int16 v24; // dx
  hkaiNewFaceCutterUtil::Segment *v25; // r8
  __int16 v26; // cx
  __int16 v27; // dx
  hkaiNewFaceCutterUtil::Segment *v28; // r8
  hkaiNewFaceCutterUtil::Segment *v29; // rbp
  __int16 i; // r11
  hkaiNewFaceCutterUtil::Segment *v31; // rsi
  int v32; // r10d
  int v33; // r8d
  signed int v34; // r9d
  int v35; // eax
  int v36; // ecx
  int v37; // r9d
  int v38; // ecx
  hkaiNewFaceCutterUtil::Segment *v39; // rbp
  __int16 j; // r11
  hkaiNewFaceCutterUtil::Segment *v41; // rsi
  int v42; // r10d
  int v43; // r8d
  signed int v44; // r9d
  int v45; // eax
  int v46; // ecx
  int v47; // r9d
  int v48; // ecx
  hkaiNewFaceCutterUtil::Segment *v49; // rdx
  unsigned __int16 m_generation; // ax
  __int16 m_firstSegment; // r9
  hkaiNewFaceCutterUtil::Segment *v52; // r10
  unsigned int v53; // edx
  int v54; // ecx
  unsigned __int16 v55; // ax
  hkaiNewFaceCutterUtil::Event event; // [rsp+20h] [rbp-48h] BYREF

  v4 = -1;
  p_m_eventQueue = &state->m_eventQueue;
  state->m_incomingSegments.m_size = 0;
  v6 = 0;
  state->m_outgoingSegments.m_size = 0;
  v7 = upperBoundIndexOut;
  LOWORD(v10) = -1;
  v11 = -1;
  if ( state->m_eventQueue.m_heap.m_size == 1 )
    goto LABEL_57;
  while ( p_m_eventQueue->m_heap.m_data[1].m_posAndType >> 2 == eventPos.m_xy )
  {
    v12 = p_m_eventQueue->m_heap.m_data[1];
    event = v12;
    if ( (v12.m_posAndType & 3) != 0 )
    {
      if ( (v12.m_posAndType & 3) == 1 )
      {
        m_startingSegmentA = event.m_data.m_startSegmentData.m_startingSegmentA;
        state->m_outgoingSegments.m_data[state->m_outgoingSegments.m_size++] = event.m_data.m_startSegmentData.m_startingSegmentA;
        v19 = &state->m_segments.m_data[m_startingSegmentA];
        if ( v19->m_generation )
        {
          hkaiNewFaceCutterUtil::EventQueue::popFront(p_m_eventQueue);
        }
        else
        {
          m_data = p_m_eventQueue->m_heap.m_data;
          m_data[1].m_data.m_startSegmentData.m_startingSegmentA = m_startingSegmentA;
          m_data[1].m_posAndType = (4 * v19->m_b.m_xy) | 2;
          hkaiNewFaceCutterUtil::EventQueue::heapifyFirst(p_m_eventQueue);
        }
        m_startingSegmentB = event.m_data.m_startSegmentData.m_startingSegmentB;
        if ( event.m_data.m_startSegmentData.m_startingSegmentB != -1 )
        {
          state->m_outgoingSegments.m_data[state->m_outgoingSegments.m_size++] = event.m_data.m_startSegmentData.m_startingSegmentB;
          if ( p_m_eventQueue->m_heap.m_size == (p_m_eventQueue->m_heap.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&p_m_eventQueue->m_heap.m_data,
              16);
          v22 = (__int64)&p_m_eventQueue->m_heap.m_data[p_m_eventQueue->m_heap.m_size++];
          *(_WORD *)(v22 + 4) = m_startingSegmentB;
          *(_DWORD *)v22 = (4 * state->m_segments.m_data[m_startingSegmentB].m_b.m_xy) | 2;
          hkaiNewFaceCutterUtil::EventQueue::heapifyLast(p_m_eventQueue);
        }
      }
      else if ( (v12.m_posAndType & 3) == 2 )
      {
        v13 = state->m_segments.m_data;
        v14 = v12.m_data.m_startSegmentData.m_startingSegmentA;
        if ( (_WORD)v10 == 0xFFFF && v13[v14].m_a.m_xy != v13[v14].m_b.m_xy )
        {
          LOWORD(v10) = v12.m_data.m_startSegmentData.m_startingSegmentA;
          v11 = v12.m_data.m_startSegmentData.m_startingSegmentA;
        }
        m_followingSegment = v13[v14].m_followingSegment;
        if ( m_followingSegment == -1 )
        {
          hkaiNewFaceCutterUtil::EventQueue::popFront(p_m_eventQueue);
        }
        else
        {
          state->m_outgoingSegments.m_data[state->m_outgoingSegments.m_size++] = m_followingSegment;
          v16 = p_m_eventQueue->m_heap.m_data;
          v17 = (4 * v13[m_followingSegment].m_b.m_xy) | 2;
          v16[1].m_data.m_startSegmentData.m_startingSegmentA = m_followingSegment;
          v16[1].m_posAndType = v17;
          hkaiNewFaceCutterUtil::EventQueue::heapifyFirst(p_m_eventQueue);
        }
      }
      goto LABEL_37;
    }
    hkaiNewFaceCutterUtil::EventQueue::popFront(p_m_eventQueue);
    if ( hkaiNewFaceCutterUtil::eventIsValid(state, &event) )
    {
      if ( !v6 )
        goto LABEL_27;
      m_nextSegment = event.m_data.m_startSegmentData.m_startingSegmentA;
      v24 = v10;
      if ( (__int16)v10 != event.m_data.m_startSegmentData.m_startingSegmentA )
      {
        while ( m_nextSegment != (_WORD)v10 )
        {
          v25 = state->m_segments.m_data;
          m_nextSegment = v25[m_nextSegment].m_nextSegment;
          if ( m_nextSegment == -1 )
            goto LABEL_28;
          v24 = v25[v24].m_nextSegment;
          if ( v24 == -1 )
            break;
          if ( v24 == event.m_data.m_startSegmentData.m_startingSegmentA )
            goto LABEL_28;
        }
LABEL_27:
        LOWORD(v10) = event.m_data.m_startSegmentData.m_startingSegmentA;
      }
LABEL_28:
      if ( v6 )
      {
        v26 = v11;
        v27 = event.m_data.m_startSegmentData.m_startingSegmentB;
        if ( event.m_data.m_startSegmentData.m_startingSegmentB != v11 )
        {
          while ( v26 != event.m_data.m_startSegmentData.m_startingSegmentB )
          {
            v28 = state->m_segments.m_data;
            v26 = v28[v26].m_nextSegment;
            if ( v26 == -1 )
              goto LABEL_36;
            v27 = v28[v27].m_nextSegment;
            if ( v27 == -1 )
              break;
            if ( v27 == v11 )
              goto LABEL_36;
          }
          goto LABEL_35;
        }
      }
      else
      {
LABEL_35:
        v11 = event.m_data.m_startSegmentData.m_startingSegmentB;
      }
LABEL_36:
      v6 = 1;
    }
LABEL_37:
    if ( p_m_eventQueue->m_heap.m_size == 1 )
      break;
  }
  if ( (_WORD)v10 != 0xFFFF )
  {
    v29 = state->m_segments.m_data;
    for ( i = v29[(__int16)v10].m_prevSegment; i != -1; i = v31->m_prevSegment )
    {
      v31 = &v29[i];
      v32 = v31->m_a.m_xy - v31->m_b.m_xy + 2 * ((LOWORD(v31->m_a.m_xy) - LOWORD(v31->m_b.m_xy)) & 0x8000);
      v33 = (__int16)v32;
      v32 >>= 16;
      v34 = eventPos.m_xy - v31->m_b.m_xy + 2 * ((LOWORD(eventPos.m_xy) - LOWORD(v31->m_b.m_xy)) & 0x8000);
      v35 = v34 >> 16;
      v36 = v32 * (__int16)v34;
      v37 = v33 * (__int16)v34 + v32 * (v34 >> 16);
      v38 = v36 - v33 * v35;
      if ( !v38 )
        v38 = v37;
      if ( v38 < 0 )
        break;
      LOWORD(v10) = i;
    }
    *lowerBoundIndexOut = i;
    v39 = state->m_segments.m_data;
    for ( j = v39[v11].m_nextSegment; j != -1; j = v41->m_nextSegment )
    {
      v41 = &v39[j];
      v42 = v41->m_b.m_xy - v41->m_a.m_xy + 2 * ((LOWORD(v41->m_b.m_xy) - LOWORD(v41->m_a.m_xy)) & 0x8000);
      v43 = (__int16)v42;
      v42 >>= 16;
      v44 = eventPos.m_xy - v41->m_a.m_xy + 2 * ((LOWORD(eventPos.m_xy) - LOWORD(v41->m_a.m_xy)) & 0x8000);
      v45 = v44 >> 16;
      v46 = v42 * (__int16)v44;
      v47 = v43 * (__int16)v44 + v42 * (v44 >> 16);
      v48 = v46 - v43 * v45;
      if ( !v48 )
        v48 = v47;
      if ( v48 < 0 )
        break;
    }
    *upperBoundIndexOut = j;
    if ( (__int16)v10 != j )
    {
      do
      {
        v49 = &state->m_segments.m_data[(__int16)v10];
        state->m_incomingSegments.m_data[state->m_incomingSegments.m_size++] = v10;
        m_generation = v49->m_generation;
        if ( m_generation < 0xFF00u )
        {
          if ( v49->m_b.m_xy != eventPos.m_xy )
            state->m_outgoingSegments.m_data[state->m_outgoingSegments.m_size++] = v10;
        }
        else
        {
          v49->m_generation = m_generation + 1;
        }
        v10 = v49->m_nextSegment;
      }
      while ( v10 != j );
    }
    return;
  }
  v7 = upperBoundIndexOut;
LABEL_57:
  m_firstSegment = state->m_sweepState.m_firstSegment;
  if ( m_firstSegment != -1 )
  {
    while ( 1 )
    {
      v52 = &state->m_segments.m_data[m_firstSegment];
      v53 = eventPos.m_xy - v52->m_a.m_xy + 2 * ((LOWORD(eventPos.m_xy) - LOWORD(v52->m_a.m_xy)) & 0x8000);
      v54 = (__int16)v53
          * ((signed int)(v52->m_b.m_xy - v52->m_a.m_xy + 2 * ((LOWORD(v52->m_b.m_xy) - LOWORD(v52->m_a.m_xy)) & 0x8000)) >> 16)
          - (__int16)(LOWORD(v52->m_b.m_xy)
                    - LOWORD(v52->m_a.m_xy)
                    + 2 * ((LOWORD(v52->m_b.m_xy) - LOWORD(v52->m_a.m_xy)) & 0x8000))
          * SHIWORD(v53);
      if ( v54 <= 0 )
        break;
      v4 = m_firstSegment;
      m_firstSegment = v52->m_nextSegment;
      if ( m_firstSegment == -1 )
        goto LABEL_66;
    }
    if ( !v54 )
    {
      state->m_incomingSegments.m_data[state->m_incomingSegments.m_size++] = m_firstSegment;
      v55 = v52->m_generation;
      if ( v55 < 0xFF00u )
        state->m_outgoingSegments.m_data[state->m_outgoingSegments.m_size++] = m_firstSegment;
      else
        v52->m_generation = v55 + 1;
      m_firstSegment = v52->m_nextSegment;
    }
  }
LABEL_66:
  *lowerBoundIndexOut = v4;
  *v7 = m_firstSegment;
}

// File Line: 287
// RVA: 0x12F79C0
void __fastcall hkaiNewFaceCutterUtil::Step::getBoundingRegions(
        hkaiNewFaceCutterUtil::State *state,
        __int16 lowerBoundIndex,
        __int16 upperBoundIndex,
        __int16 *bottomRegionIndexOut,
        __int16 *topRegionIndexOut)
{
  __int16 m_aboveRegion; // cx

  if ( lowerBoundIndex == -1 )
    *bottomRegionIndexOut = -1;
  else
    *bottomRegionIndexOut = state->m_segments.m_data[lowerBoundIndex].m_aboveRegion;
  if ( state->m_incomingSegments.m_size )
    m_aboveRegion = state->m_segments.m_data[state->m_incomingSegments.m_data[state->m_incomingSegments.m_size - 1]].m_aboveRegion;
  else
    m_aboveRegion = *bottomRegionIndexOut;
  *topRegionIndexOut = m_aboveRegion;
}

// File Line: 309
// RVA: 0x12F8080
void __fastcall hkaiNewFaceCutterUtil::Step::growRegions(
        hkaiNewFaceCutterUtil::State *state,
        __int16 bottomRegionIndex,
        hkaiNewFaceCutterUtil::Vec2 eventPos)
{
  int m_size; // eax
  unsigned int v5; // r9d
  __int64 v6; // rbp
  __int16 v7; // r14
  __int64 v8; // r15
  unsigned int aboveConnectivity; // ebx
  hkaiNewFaceCutterUtil::Segment *v10; // rsi
  __int16 m_originalEdgeIndex; // cx
  hkaiNewFaceCutterUtil::Region *v12; // rdx
  __int16 v13; // ax
  hkaiNewFaceCutterUtil::RegionEdge *v14; // rdx
  hkaiNewFaceCutterUtil::RegionEdgeConnectivity *p_m_connectivity; // rdx
  __int16 v16; // ax
  hkaiNewFaceCutterUtil::RegionEdge *m_data; // rcx
  __int64 v18; // rcx
  hkaiNewFaceCutterUtil::RegionEdge *v19; // rax
  unsigned int bottomEdgeIndexOut; // [rsp+80h] [rbp+8h] BYREF
  hkaiNewFaceCutterUtil::Vec2 eventPosa; // [rsp+90h] [rbp+18h]
  __int16 topEdgeIndexOut; // [rsp+98h] [rbp+20h] BYREF

  eventPosa.m_xy = eventPos.m_xy;
  m_size = state->m_incomingSegments.m_size;
  if ( m_size )
  {
    v5 = bottomEdgeIndexOut & 0xFFFF0000 | 1;
    v6 = 0i64;
    v7 = -1;
    v8 = state->m_incomingSegments.m_size;
    if ( m_size > 0 )
    {
      aboveConnectivity = bottomEdgeIndexOut;
      do
      {
        v10 = &state->m_segments.m_data[state->m_incomingSegments.m_data[v6]];
        m_originalEdgeIndex = v10->m_originalEdgeIndex;
        if ( m_originalEdgeIndex == -1 )
          aboveConnectivity = aboveConnectivity & 0xFFFF0000 | 1;
        else
          aboveConnectivity = aboveConnectivity & 0xFFFF0000 | (4 * (m_originalEdgeIndex & 0x3FFF));
        if ( bottomRegionIndex == -1 )
        {
          v7 = -1;
        }
        else
        {
          v12 = &state->m_regions.m_data[bottomRegionIndex];
          if ( v6 )
          {
            hkaiNewFaceCutterUtil::closeRegionAt(
              state,
              v12,
              eventPos,
              (hkaiNewFaceCutterUtil::RegionEdgeConnectivity)v5,
              (hkaiNewFaceCutterUtil::RegionEdgeConnectivity)aboveConnectivity,
              (__int16 *)&bottomEdgeIndexOut,
              &topEdgeIndexOut);
            if ( v7 != -1 && (_WORD)bottomEdgeIndexOut != 0xFFFF )
            {
              v14 = &state->m_regionEdges.m_data[v7];
              v14->m_connectivity = (hkaiNewFaceCutterUtil::RegionEdgeConnectivity)(*(_DWORD *)&v14->m_connectivity & 0xFFFF0002 | (4 * (bottomEdgeIndexOut & 0x3FFF)) | 2);
              p_m_connectivity = &state->m_regionEdges.m_data[(__int16)bottomEdgeIndexOut].m_connectivity;
              *(_DWORD *)p_m_connectivity &= 0xFFFF0002;
              *(_DWORD *)p_m_connectivity |= (4 * (v7 & 0x3FFF)) | 2;
            }
            v7 = topEdgeIndexOut;
            eventPos.m_xy = eventPosa.m_xy;
          }
          else
          {
            v13 = hkaiNewFaceCutterUtil::addTopEdgeToRegion(
                    state,
                    v12,
                    eventPos,
                    (hkaiNewFaceCutterUtil::RegionEdgeConnectivity)aboveConnectivity);
            eventPos.m_xy = eventPosa.m_xy;
            topEdgeIndexOut = v13;
            v7 = v13;
          }
        }
        bottomRegionIndex = v10->m_aboveRegion;
        ++v6;
        v5 = aboveConnectivity;
      }
      while ( v6 < v8 );
    }
    if ( bottomRegionIndex != -1 )
    {
      v16 = hkaiNewFaceCutterUtil::addBottomEdgeToRegion(
              state,
              &state->m_regions.m_data[bottomRegionIndex],
              eventPos,
              (hkaiNewFaceCutterUtil::RegionEdgeConnectivity)v5);
      if ( v7 != -1 && v16 != -1 )
      {
        m_data = state->m_regionEdges.m_data;
        *(_DWORD *)&m_data[v7].m_connectivity &= 0xFFFF0002;
        *(_DWORD *)&m_data[v7].m_connectivity |= (4 * (v16 & 0x3FFF)) | 2;
        v18 = v16;
        v19 = state->m_regionEdges.m_data;
        *(_DWORD *)&v19[v18].m_connectivity &= 0xFFFF0002;
        *(_DWORD *)&v19[v18].m_connectivity |= (4 * (v7 & 0x3FFF)) | 2;
      }
    }
  }
} 0xFFFF0002;
        *(_DWORD *)&v19[v18].m_connectivity |= (4 * (v7 & 0x3FFF)) | 2;
      }
   

// File Line: 394
// RVA: 0x12F7A40
void __fastcall hkaiNewFaceCutterUtil::Step::sortOutgoingSegmentsBySlope(
        hkaiNewFaceCutterUtil::State *state,
        bool *equalSlopeFoundOut)
{
  int m_size; // r8d
  hkaiNewFaceCutterUtil::OutgoingSegmentLessComparator v3; // [rsp+20h] [rbp-18h] BYREF

  *equalSlopeFoundOut = 0;
  m_size = state->m_outgoingSegments.m_size;
  if ( m_size )
  {
    v3.m_state = state;
    v3.m_equalSlopeFoundOut = equalSlopeFoundOut;
    if ( m_size > 1 )
      hkAlgorithm::quickSortRecursive<short,hkaiNewFaceCutterUtil::OutgoingSegmentLessComparator>(
        state->m_outgoingSegments.m_data,
        0,
        m_size - 1,
        &v3);
  }
}

// File Line: 408
// RVA: 0x12F82D0
void __fastcall hkaiNewFaceCutterUtil::Step::processRegionSplit(
        hkaiNewFaceCutterUtil::State *state,
        __int16 *bottomRegionIndexInOut,
        __int16 *topRegionIndexInOut)
{
  __int64 v3; // r12
  hkArray<short,hkContainerHeapAllocator> *p_m_outgoingSegments; // r15
  hkArray<hkaiNewFaceCutterUtil::Segment,hkContainerHeapAllocator> *p_m_segments; // r14
  hkaiNewFaceCutterUtil::Vec2 *m_data; // r8
  hkaiNewFaceCutterUtil::Region *v8; // r11
  __int16 *v9; // r9
  hkaiNewFaceCutterUtil::RegionEdge *v11; // rdx
  hkaiNewFaceCutterUtil::Segment *v12; // rax
  hkaiNewFaceCutterUtil::Vec2 v13; // ebx
  unsigned int m_xy; // esi
  unsigned int v15; // edi
  __int16 v16; // r12
  int v17; // r8d
  __int16 v18; // di
  __int64 v19; // rax
  int v20; // edx
  int v21; // edx
  __int16 m_size; // di
  __int64 v23; // rax
  unsigned int t; // [rsp+80h] [rbp+8h] BYREF
  hkaiNewFaceCutterUtil::Segment *v25; // [rsp+88h] [rbp+10h]
  __int16 *topRegionIndexOut; // [rsp+90h] [rbp+18h]
  hkaiNewFaceCutterUtil::Segment *v27; // [rsp+98h] [rbp+20h]

  topRegionIndexOut = topRegionIndexInOut;
  v3 = *bottomRegionIndexInOut;
  p_m_outgoingSegments = &state->m_outgoingSegments;
  p_m_segments = &state->m_segments;
  m_data = state->m_outputVertices.m_data;
  v8 = &state->m_regions.m_data[v3];
  v9 = state->m_outgoingSegments.m_data;
  v11 = state->m_regionEdges.m_data;
  v12 = &state->m_segments.m_data[v9[state->m_outgoingSegments.m_size - 1]];
  v27 = &state->m_segments.m_data[*v9];
  v13.m_xy = v27->m_a.m_xy;
  v25 = v12;
  m_xy = m_data[v11[v8->m_head].m_outputVertexIndex].m_xy;
  v15 = m_data[v11[v8->m_tail].m_outputVertexIndex].m_xy;
  t = v13.m_xy - m_xy;
  LODWORD(m_data) = v27->m_b.m_xy - m_xy + 2 * ((LOWORD(v27->m_b.m_xy) - (_WORD)m_xy) & 0x8000);
  if ( (__int16)m_data * ((int)(v13.m_xy - m_xy + 2 * ((LOWORD(v13.m_xy) - (_WORD)m_xy) & 0x8000)) >> 16)
     - (__int16)(LOWORD(v13.m_xy) - m_xy + 2 * ((LOWORD(v13.m_xy) - m_xy) & 0x8000)) * ((int)m_data >> 16) > 0 )
  {
    v20 = v25->m_b.m_xy - v15 + 2 * ((LOWORD(v25->m_b.m_xy) - (_WORD)v15) & 0x8000);
    if ( (__int16)v20 * ((int)(v13.m_xy - v15 + 2 * ((LOWORD(v13.m_xy) - (_WORD)v15) & 0x8000)) >> 16)
       - (__int16)(LOWORD(v13.m_xy) - v15 + 2 * ((LOWORD(v13.m_xy) - v15) & 0x8000)) * (v20 >> 16) < 0 )
    {
      hkaiNewFaceCutterUtil::splitRegionAtBothEdges(state, v3, v13, bottomRegionIndexInOut, topRegionIndexOut);
    }
    else
    {
      *bottomRegionIndexInOut = hkaiNewFaceCutterUtil::splitRegionAtNewBottomEdge(state, v3, v13);
      v21 = v27->m_b.m_xy - v15 + 2 * ((LOWORD(v27->m_b.m_xy) - (_WORD)v15) & 0x8000);
      if ( (__int16)v21 * ((int)(v13.m_xy - v15 + 2 * ((LOWORD(v13.m_xy) - (_WORD)v15) & 0x8000)) >> 16)
         - (__int16)(LOWORD(v13.m_xy) - v15 + 2 * ((LOWORD(v13.m_xy) - v15) & 0x8000)) * (v21 >> 16) > 0 )
      {
        m_size = state->m_segments.m_size;
        if ( p_m_segments->m_size == (p_m_segments->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_segments->m_data, 28);
        ++p_m_segments->m_size;
        v23 = (__int64)&p_m_segments->m_data[m_size];
        LOWORD(t) = m_size;
        *(hkaiNewFaceCutterUtil::Vec2 *)v23 = v13;
        *(_WORD *)(v23 + 14) = -256;
        *(_DWORD *)(v23 + 8) = 0;
        *(_WORD *)(v23 + 22) = -1;
        *(_WORD *)(v23 + 16) = -1;
        *(_DWORD *)(v23 + 4) = (HIWORD(v13.m_xy) + 1) << 16;
        hkArrayBase<short>::_insertAt(p_m_outgoingSegments, &hkContainerHeapAllocator::s_alloc, 0, (const __int16 *)&t);
      }
    }
  }
  else
  {
    v16 = hkaiNewFaceCutterUtil::splitRegionAtNewTopEdge(state, v3, v13);
    *topRegionIndexOut = v16;
    v17 = v25->m_b.m_xy - m_xy + 2 * ((LOWORD(v25->m_b.m_xy) - (_WORD)m_xy) & 0x8000);
    if ( (__int16)v17 * ((int)(t + 2 * (t & 0x8000)) >> 16) - (__int16)(t + 2 * (t & 0x8000)) * (v17 >> 16) < 0 )
    {
      v18 = state->m_segments.m_size;
      if ( p_m_segments->m_size == (p_m_segments->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_segments->m_data, 28);
      ++p_m_segments->m_size;
      v19 = (__int64)&p_m_segments->m_data[v18];
      *(hkaiNewFaceCutterUtil::Vec2 *)v19 = v13;
      *(_WORD *)(v19 + 14) = -256;
      *(_DWORD *)(v19 + 8) = 0;
      *(_WORD *)(v19 + 22) = v16;
      *(_WORD *)(v19 + 16) = -1;
      *(_DWORD *)(v19 + 4) = v13.m_xy & 0xFFFF0000 | 0x3FFF;
      if ( p_m_outgoingSegments->m_size == (p_m_outgoingSegments->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_outgoingSegments->m_data, 2);
      p_m_outgoingSegments->m_data[p_m_outgoingSegments->m_size++] = v18;
    }
  }
}

// File Line: 460
// RVA: 0x12F8610
void __fastcall hkaiNewFaceCutterUtil::Step::resolveRegionJoinOrSplit(
        hkaiNewFaceCutterUtil::State *state,
        __int16 *bottomRegionIndex,
        __int16 *topRegionIndex,
        hkaiNewFaceCutterUtil::Vec2 eventPos,
        bool *slopeSorted,
        bool *equalSlopeFound)
{
  __int16 v10; // r14
  hkArray<hkaiNewFaceCutterUtil::Segment,hkContainerHeapAllocator> *p_m_segments; // rsi
  __int16 m_size; // bp
  __int64 v13; // rcx

  if ( *bottomRegionIndex != -1 )
  {
    if ( state->m_outgoingSegments.m_size )
    {
      if ( !state->m_incomingSegments.m_size )
      {
        hkaiNewFaceCutterUtil::Step::sortOutgoingSegmentsBySlope(state, equalSlopeFound);
        *slopeSorted = 1;
        hkaiNewFaceCutterUtil::Step::processRegionSplit(state, bottomRegionIndex, topRegionIndex);
      }
    }
    else
    {
      v10 = *topRegionIndex;
      p_m_segments = &state->m_segments;
      m_size = state->m_segments.m_size;
      if ( state->m_segments.m_size == (state->m_segments.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_segments->m_data, 28);
      ++p_m_segments->m_size;
      v13 = (__int64)&p_m_segments->m_data[m_size];
      *(_DWORD *)(v13 + 4) = LOWORD(eventPos.m_xy) | 0x3FFF0000;
      *(hkaiNewFaceCutterUtil::Vec2 *)v13 = eventPos;
      *(_DWORD *)(v13 + 8) = 0;
      *(_WORD *)(v13 + 22) = v10;
      *(_WORD *)(v13 + 14) = -256;
      *(_WORD *)(v13 + 16) = -1;
      state->m_outgoingSegments.m_data[state->m_outgoingSegments.m_size++] = m_size;
      *slopeSorted = 1;
    }
  }
}

// File Line: 490
// RVA: 0x12F8730
void __fastcall hkaiNewFaceCutterUtil::Step::setOutgoingSegmentStartPoints(
        hkaiNewFaceCutterUtil::State *state,
        hkaiNewFaceCutterUtil::Vec2 pos)
{
  __int64 m_size; // rdi
  __int64 v3; // r11
  hkaiNewFaceCutterUtil::Segment *v5; // rcx
  hkaiNewFaceCutterUtil::Vec2 v6; // eax
  signed int v7; // r9d
  unsigned int m_xy; // [rsp+10h] [rbp+10h]

  m_size = state->m_outgoingSegments.m_size;
  v3 = 0i64;
  m_xy = pos.m_xy;
  if ( m_size > 0 )
  {
    while ( 1 )
    {
      v5 = &state->m_segments.m_data[state->m_outgoingSegments.m_data[v3]];
      v6.m_xy = v5->m_a.m_xy;
      if ( v5->m_a.m_xy != pos.m_xy )
      {
        v7 = pos.m_xy - v6.m_xy + 2 * ((LOWORD(pos.m_xy) - LOWORD(v6.m_xy)) & 0x8000);
        if ( (__int16)v7
           * ((signed int)(v5->m_b.m_xy - v6.m_xy + 2 * ((LOWORD(v5->m_b.m_xy) - LOWORD(v6.m_xy)) & 0x8000)) >> 16) != (__int16)(LOWORD(v5->m_b.m_xy) - LOWORD(v6.m_xy) + 2 * ((LOWORD(v5->m_b.m_xy) - LOWORD(v6.m_xy)) & 0x8000)) * (v7 >> 16) )
        {
          ++v5->m_generation;
          pos.m_xy = m_xy;
        }
      }
      ++v3;
      v5->m_a = pos;
      if ( v3 >= m_size )
        break;
      pos.m_xy = m_xy;
    }
  }
}

// File Line: 518
// RVA: 0x12F87E0
void __fastcall hkaiNewFaceCutterUtil::Step::resolveOuterReflexVertices(
        hkaiNewFaceCutterUtil::State *state,
        __int16 *topRegionIndex,
        __int16 *bottomRegionIndex,
        hkaiNewFaceCutterUtil::Vec2 eventPos)
{
  unsigned int v4; // ebx
  __int64 m_size; // r9
  hkArray<short,hkContainerHeapAllocator> *p_m_outgoingSegments; // r14
  __int16 v10; // bp
  hkArray<hkaiNewFaceCutterUtil::Segment,hkContainerHeapAllocator> *p_m_segments; // rsi
  hkaiNewFaceCutterUtil::Segment *m_data; // rdx
  __int64 v13; // r8
  int v14; // r12d
  int v15; // r11d
  __int64 v16; // r9
  unsigned int v17; // eax
  int v18; // edx
  __int16 v19; // r12
  __int64 v20; // rax
  hkArray<hkaiNewFaceCutterUtil::Segment,hkContainerHeapAllocator> *v21; // rsi
  hkaiNewFaceCutterUtil::Segment *v22; // r9
  hkaiNewFaceCutterUtil::Segment *v23; // rdx
  unsigned int v24; // r11d
  int v25; // r8d
  unsigned int v26; // eax
  int v27; // ecx
  __int16 v28; // di
  __int64 v29; // rax
  __int16 t; // [rsp+60h] [rbp+8h] BYREF
  unsigned int m_xy; // [rsp+78h] [rbp+20h]

  m_xy = eventPos.m_xy;
  v4 = eventPos.m_xy;
  m_size = state->m_incomingSegments.m_size;
  p_m_outgoingSegments = &state->m_outgoingSegments;
  if ( (_DWORD)m_size )
  {
    v10 = *topRegionIndex;
    if ( *topRegionIndex != -1 )
    {
      p_m_segments = &state->m_segments;
      m_data = state->m_segments.m_data;
      v13 = 28i64 * state->m_outgoingSegments.m_data[state->m_outgoingSegments.m_size - 1];
      v14 = *(unsigned int *)((char *)&m_data->m_b.m_xy + v13);
      v15 = *(unsigned int *)((char *)&m_data->m_a.m_xy + v13);
      v16 = state->m_incomingSegments.m_data[m_size - 1];
      LODWORD(v13) = v14 - v15 + 2 * ((*(_WORD *)((char *)&m_data->m_b.m_xy + v13) - (_WORD)v15) & 0x8000);
      LODWORD(m_data) = m_data[v16].m_b.m_xy
                      - m_data[v16].m_a.m_xy
                      + 2 * ((LOWORD(m_data[v16].m_b.m_xy) - LOWORD(m_data[v16].m_a.m_xy)) & 0x8000);
      if ( (__int16)v13 * ((int)m_data >> 16) < (__int16)m_data * ((int)v13 >> 16) )
      {
        v17 = state->m_outputVertices.m_data[state->m_regionEdges.m_data[state->m_regions.m_data[v10].m_head].m_outputVertexIndex].m_xy;
        v18 = v14 - v17 + 2 * (((_WORD)v14 - (_WORD)v17) & 0x8000);
        if ( (__int16)v18 * ((int)(v15 - v17 + 2 * (((_WORD)v15 - (_WORD)v17) & 0x8000)) >> 16)
           - (__int16)(v15 - v17 + 2 * ((v15 - v17) & 0x8000)) * (v18 >> 16) < 0 )
        {
          v19 = state->m_segments.m_size;
          if ( state->m_segments.m_size == (state->m_segments.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_segments->m_data, 28);
          ++p_m_segments->m_size;
          v20 = (__int64)&p_m_segments->m_data[v19];
          *(_DWORD *)v20 = v4;
          *(_DWORD *)(v20 + 8) = 0;
          *(_WORD *)(v20 + 14) = -256;
          *(_WORD *)(v20 + 22) = v10;
          *(_WORD *)(v20 + 16) = -1;
          *(_DWORD *)(v20 + 4) = v4 & 0xFFFF0000 | 0x3FFF;
          p_m_outgoingSegments->m_data[p_m_outgoingSegments->m_size++] = v19;
        }
        else
        {
          hkaiNewFaceCutterUtil::splitRegionAtTopMouth(state, topRegionIndex);
        }
        v4 = m_xy;
      }
    }
    if ( *bottomRegionIndex != -1 )
    {
      v21 = &state->m_segments;
      v22 = &state->m_segments.m_data[*p_m_outgoingSegments->m_data];
      v23 = &state->m_segments.m_data[*state->m_incomingSegments.m_data];
      v24 = v22->m_a.m_xy;
      v25 = v23->m_b.m_xy - v23->m_a.m_xy + 2 * ((LOWORD(v23->m_b.m_xy) - LOWORD(v23->m_a.m_xy)) & 0x8000);
      LODWORD(v23) = v22->m_b.m_xy - v24 + 2 * ((LOWORD(v22->m_b.m_xy) - (_WORD)v24) & 0x8000);
      if ( (__int16)v25 * ((int)v23 >> 16) < (__int16)v23 * (v25 >> 16) )
      {
        v26 = state->m_outputVertices.m_data[state->m_regionEdges.m_data[state->m_regions.m_data[*bottomRegionIndex].m_tail].m_outputVertexIndex].m_xy;
        v27 = v22->m_b.m_xy - v26 + 2 * (((unsigned __int16)v22->m_b.m_xy - (_WORD)v26) & 0x8000);
        if ( (__int16)v27 * ((int)(v24 - v26 + 2 * (((_WORD)v24 - (_WORD)v26) & 0x8000)) >> 16)
           - (__int16)(v24 - v26 + 2 * ((v24 - v26) & 0x8000)) * (v27 >> 16) > 0 )
        {
          v28 = state->m_segments.m_size;
          if ( v21->m_size == (v21->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v21->m_data, 28);
          ++v21->m_size;
          v29 = (__int64)&v21->m_data[v28];
          t = v28;
          *(_DWORD *)v29 = v4;
          *(_WORD *)(v29 + 14) = -256;
          *(_DWORD *)(v29 + 8) = 0;
          *(_WORD *)(v29 + 22) = -1;
          *(_WORD *)(v29 + 16) = -1;
          *(_DWORD *)(v29 + 4) = (HIWORD(v4) + 1) << 16;
          hkArrayBase<short>::_insertAt(p_m_outgoingSegments, &hkContainerHeapAllocator::s_alloc, 0, &t);
        }
        else
        {
          hkaiNewFaceCutterUtil::splitRegionAtBottomMouth(state, bottomRegionIndex);
        }
      }
    }
  }
}

// File Line: 593
// RVA: 0x12F7A90
void __fastcall hkaiNewFaceCutterUtil::Step::mergeEqualSlopeOutgoingSegments(hkaiNewFaceCutterUtil::State *state)
{
  __int64 m_size; // rsi
  __int64 v2; // r9
  int v3; // ebp
  hkaiNewFaceCutterUtil::Segment *v5; // rdx
  unsigned int m_xy; // edi
  unsigned int v7; // r11d
  __int64 v8; // rdx
  __int64 v9; // r15
  unsigned int v10; // ebx
  int v11; // r12d
  hkaiNewFaceCutterUtil::Segment *m_data; // r14
  unsigned int v13; // r11d
  __int16 *v14; // r10
  int v15; // r8d
  __int64 v16; // r14
  __int16 *v17; // rax
  hkaiNewFaceCutterUtil::Segment *v18; // rcx
  __int16 v19; // dx
  hkaiNewFaceCutterUtil::Segment *v20; // rbp
  hkaiNewFaceCutterUtil::Vec2 v21; // r8d
  hkaiNewFaceCutterUtil::Segment *v22; // rsi
  int v23; // eax
  int v24; // [rsp+70h] [rbp+8h]
  __int64 v25; // [rsp+78h] [rbp+10h]
  __int64 v26; // [rsp+80h] [rbp+18h]
  __int64 v27; // [rsp+88h] [rbp+20h]

  m_size = state->m_outgoingSegments.m_size;
  v2 = 0i64;
  v3 = 0;
  v26 = 0i64;
  v27 = m_size;
  v5 = &state->m_segments.m_data[*state->m_outgoingSegments.m_data];
  v24 = 0;
  m_xy = v5->m_a.m_xy;
  v7 = v5->m_b.m_xy;
  if ( m_size <= 0 )
  {
    state->m_outgoingSegments.m_size = 0;
  }
  else
  {
    v8 = 0i64;
    v25 = 0i64;
    do
    {
      v9 = v2 + 1;
      v10 = 0;
      v11 = v3 + 1;
      if ( v2 + 1 < m_size )
      {
        m_data = state->m_segments.m_data;
        v13 = v7 - m_xy;
        v14 = &state->m_outgoingSegments.m_data[v9];
        while ( 1 )
        {
          v15 = m_data[*v14].m_b.m_xy - m_xy + 2 * ((LOWORD(m_data[*v14].m_b.m_xy) - (_WORD)m_xy) & 0x8000);
          if ( (__int16)v15 * ((int)(v13 + 2 * (v13 & 0x8000)) >> 16) != (__int16)(v13 + 2 * (v13 & 0x8000))
                                                                       * (v15 >> 16) )
            break;
          ++v9;
          ++v11;
          ++v14;
          if ( v9 >= m_size )
            goto LABEL_9;
        }
        v10 = m_data[*v14].m_b.m_xy;
LABEL_9:
        v8 = v25;
        v2 = v26;
      }
      if ( v11 - v3 > 1 )
      {
        v16 = v9 - 1;
        if ( v9 - 1 != v2 )
        {
          do
          {
            v17 = state->m_outgoingSegments.m_data;
            v18 = state->m_segments.m_data;
            v19 = v17[v16];
            v20 = &v18[v17[v16 - 1]];
            v21.m_xy = v20->m_b.m_xy;
            v22 = &v18[v19];
            v22->m_a = v21;
            if ( v22->m_b.m_xy != v21.m_xy )
            {
              ++v22->m_generation;
              hkaiNewFaceCutterUtil::enqueueStartSegmentEvent(state, v19, v21);
              v2 = v26;
            }
            v20->m_difference.m_data = (unsigned __int16)(LOWORD(v20->m_difference.m_data) ^ v22->m_difference.m_data) | ((v20->m_difference.m_data & 0xFFFF0000) + (v22->m_difference.m_data & 0xFFFF0000));
            if ( v20->m_originalEdgeIndex == -1 )
              v20->m_originalEdgeIndex = v22->m_originalEdgeIndex;
            --v16;
          }
          while ( v16 != v2 );
          m_size = v27;
          v8 = v25;
        }
      }
      v8 += 2i64;
      v3 = v11;
      v26 = v9;
      v7 = v10;
      *(__int16 *)((char *)state->m_outgoingSegments.m_data + v8 - 2) = state->m_outgoingSegments.m_data[v2];
      v25 = v8;
      v23 = v24 + 1;
      v2 = v9;
      ++v24;
    }
    while ( v9 < m_size );
    state->m_outgoingSegments.m_size = v23;
  }
}

// File Line: 672
// RVA: 0x12F7CE0
void __fastcall hkaiNewFaceCutterUtil::Step::updateOutgoingSegmentData(
        hkaiNewFaceCutterUtil::State *state,
        __int16 lowerBound,
        __int16 upperBound)
{
  __int64 v3; // rbp
  unsigned int m_data; // eax
  __int16 *v7; // rcx
  int m_size; // r9d
  __int64 v9; // r14
  hkaiNewFaceCutterUtil::Segment *v10; // rdi
  __int64 v11; // r15
  char EffectivePainterIndex; // al
  __int64 v13; // rcx
  __int16 v14; // ax
  __int16 *v15; // rax
  hkaiNewFaceCutterUtil::Membership v16; // [rsp+58h] [rbp+10h] BYREF

  v3 = 0i64;
  if ( lowerBound == -1 )
    m_data = 0;
  else
    m_data = state->m_segments.m_data[lowerBound].m_aboveMembership.m_data;
  if ( state->m_outgoingSegments.m_size )
  {
    v7 = state->m_outgoingSegments.m_data;
    if ( lowerBound == -1 )
      state->m_sweepState.m_firstSegment = *v7;
    else
      state->m_segments.m_data[lowerBound].m_nextSegment = *v7;
    m_size = state->m_outgoingSegments.m_size;
    v9 = *state->m_outgoingSegments.m_data;
    v16.m_data = m_data;
    v10 = &state->m_segments.m_data[v9];
    v10->m_prevSegment = lowerBound;
    v16.m_data = (unsigned __int16)(LOWORD(v16.m_data) ^ v10->m_difference.m_data) | ((v16.m_data & 0xFFFF0000)
                                                                                    + (v10->m_difference.m_data & 0xFFFF0000));
    v10->m_aboveMembership = v16;
    v11 = m_size - 1;
    if ( m_size != 1 )
    {
      do
      {
        if ( (v16.m_data & 0xFFFF0001) == 1 )
        {
          EffectivePainterIndex = hkaiNewFaceCutterUtil::Membership::getEffectivePainterIndex(&v16);
          v10->m_aboveRegion = hkaiNewFaceCutterUtil::makeNewRegion(state, v10->m_a, EffectivePainterIndex);
        }
        else
        {
          v10->m_aboveRegion = -1;
        }
        v13 = state->m_outgoingSegments.m_data[++v3];
        v14 = v9;
        v10->m_nextSegment = v13;
        LOWORD(v9) = v13;
        v10 = &state->m_segments.m_data[v13];
        v10->m_prevSegment = v14;
        v16.m_data = (unsigned __int16)(LOWORD(v16.m_data) ^ v10->m_difference.m_data) | ((v16.m_data & 0xFFFF0000)
                                                                                        + (v10->m_difference.m_data & 0xFFFF0000));
        v10->m_aboveMembership = v16;
      }
      while ( v3 != v11 );
    }
    v10->m_nextSegment = upperBound;
    v15 = state->m_outgoingSegments.m_data;
    if ( upperBound == -1 )
      state->m_sweepState.m_lastSegment = v15[state->m_outgoingSegments.m_size - 1];
    else
      state->m_segments.m_data[upperBound].m_prevSegment = v15[state->m_outgoingSegments.m_size - 1];
  }
  else
  {
    if ( lowerBound == -1 )
      state->m_sweepState.m_firstSegment = upperBound;
    else
      state->m_segments.m_data[lowerBound].m_nextSegment = upperBound;
    if ( upperBound == -1 )
      state->m_sweepState.m_lastSegment = lowerBound;
    else
      state->m_segments.m_data[upperBound].m_prevSegment = lowerBound;
  }
}

// File Line: 769
// RVA: 0x12F8B30
void __fastcall hkaiNewFaceCutterUtil::Step::addIntersectionEvent(
        hkaiNewFaceCutterUtil::State *state,
        __int16 lowerSegmentIndex,
        __int16 upperSegmentIndex,
        hkaiNewFaceCutterUtil::Vec2 curEventPos)
{
  hkaiNewFaceCutterUtil::Segment *m_data; // rax
  hkaiNewFaceCutterUtil::Segment *v7; // rdi
  hkaiNewFaceCutterUtil::Segment *v8; // rsi
  unsigned int m_xy; // r8d
  unsigned int v10; // eax
  unsigned int v11; // edx
  unsigned int v12; // ecx
  int v13; // r11d
  int v14; // ebp
  int v15; // r11d
  int v16; // r10d
  int v17; // r11d
  int v18; // r15d
  int v19; // r11d
  int v20; // r14d
  int v21; // r10d
  int v22; // r10d

  m_data = state->m_segments.m_data;
  v7 = &m_data[upperSegmentIndex];
  v8 = &m_data[lowerSegmentIndex];
  m_xy = v7->m_b.m_xy;
  v10 = v8->m_b.m_xy;
  v11 = v7->m_a.m_xy;
  v12 = v8->m_a.m_xy;
  if ( v10 != m_xy )
  {
    v13 = m_xy - v12 + 2 * (((_WORD)m_xy - (_WORD)v12) & 0x8000);
    v14 = (__int16)v13 * ((int)(v10 - v12 + 2 * (((_WORD)v10 - (_WORD)v12) & 0x8000)) >> 16)
        - (__int16)(v10 - v12 + 2 * ((v10 - v12) & 0x8000)) * (v13 >> 16);
    if ( v14 )
    {
      v15 = v11 - v12 + 2 * (((_WORD)v11 - (_WORD)v12) & 0x8000);
      v16 = (__int16)v15 * ((int)(v10 - v12 + 2 * (((_WORD)v10 - (_WORD)v12) & 0x8000)) >> 16)
          - (__int16)(v10 - v12 + 2 * ((v10 - v12) & 0x8000)) * (v15 >> 16);
      if ( !v16 || (v14 ^ v16) < 0 )
      {
        v17 = v10 - v11 + 2 * (((_WORD)v10 - (_WORD)v11) & 0x8000);
        v18 = (__int16)v17 * ((int)(m_xy - v11 + 2 * (((_WORD)m_xy - (_WORD)v11) & 0x8000)) >> 16)
            - (__int16)(m_xy - v11 + 2 * ((m_xy - v11) & 0x8000)) * (v17 >> 16);
        if ( v18 )
        {
          v19 = v12 - v11 + 2 * (((_WORD)v12 - (_WORD)v11) & 0x8000);
          v20 = (__int16)v19 * ((int)(m_xy - v11 + 2 * (((_WORD)m_xy - (_WORD)v11) & 0x8000)) >> 16)
              - (__int16)(m_xy - v11 + 2 * ((m_xy - v11) & 0x8000)) * (v19 >> 16);
          if ( !v20 || (v18 ^ v20) < 0 )
          {
            m_xy = ((unsigned __int16)v12
                  + (unsigned int)((__int64)(v20 * (__int64)((unsigned __int16)v10 - (unsigned __int16)v12)
                                           - ((v20 - v18 - (((v20 - v18) >> 31) | 1)) & (unsigned __int64)((__int64)(v20 ^ ((unsigned __int16)v10 - (unsigned __int16)v12) ^ (unsigned __int64)(v20 - v18)) >> 31)))
                                 / (v20 - v18))) | ((HIWORD(v12)
                                                   + (unsigned int)((__int64)((int)(HIWORD(v10) - HIWORD(v12))
                                                                            * (__int64)v20
                                                                            - ((v20 - v18 - (((v20 - v18) >> 31) | 1)) & (unsigned __int64)((__int64)((int)(HIWORD(v10) - HIWORD(v12)) ^ v20 ^ (unsigned __int64)(v20 - v18)) >> 31)))
                                                                  / (v20 - v18))) << 16);
LABEL_18:
            hkaiNewFaceCutterUtil::enqueueIntersectionEvent(
              state,
              lowerSegmentIndex,
              upperSegmentIndex,
              (hkaiNewFaceCutterUtil::Vec2)m_xy);
            return;
          }
        }
      }
    }
  }
  if ( v8->m_generation < 0xFF00u )
  {
    if ( v7->m_generation >= 0xFF00u )
    {
      v22 = m_xy - v12 + 2 * (((_WORD)m_xy - (_WORD)v12) & 0x8000);
      if ( (__int16)v22 * ((int)(v10 - v12 + 2 * (((_WORD)v10 - (_WORD)v12) & 0x8000)) >> 16) == (__int16)(v10 - v12 + 2 * ((v10 - v12) & 0x8000))
                                                                                               * (v22 >> 16)
        && v12 < m_xy
        && m_xy < v10 )
      {
        goto LABEL_18;
      }
    }
  }
  else
  {
    v21 = v10 - v11 + 2 * (((_WORD)v10 - (_WORD)v11) & 0x8000);
    if ( (__int16)v21 * ((int)(m_xy - v11 + 2 * (((_WORD)m_xy - (_WORD)v11) & 0x8000)) >> 16) == (__int16)(m_xy - v11 + 2 * ((m_xy - v11) & 0x8000))
                                                                                               * (v21 >> 16)
      && v11 < v10
      && v10 < m_xy )
    {
      m_xy = v8->m_b.m_xy;
      goto LABEL_18;
    }
  }
}

// File Line: 820
// RVA: 0x12F7F30
void __fastcall hkaiNewFaceCutterUtil::Step::addIntersectionEvents(
        hkaiNewFaceCutterUtil::State *state,
        __int16 lowerBoundIndex,
        __int16 upperBoundIndex,
        hkaiNewFaceCutterUtil::Vec2 curEventPos)
{
  hkaiNewFaceCutterUtil::Segment *m_data; // r8
  hkaiNewFaceCutterUtil::Segment *v8; // rdx
  __int16 v9; // dx
  hkaiNewFaceCutterUtil::Vec2 curEventPosa; // [rsp+48h] [rbp+20h]

  curEventPosa.m_xy = curEventPos.m_xy;
  if ( state->m_outgoingSegments.m_size )
  {
    if ( lowerBoundIndex != -1 )
    {
      hkaiNewFaceCutterUtil::Step::addIntersectionEvent(
        state,
        lowerBoundIndex,
        *state->m_outgoingSegments.m_data,
        curEventPos);
      curEventPos.m_xy = curEventPosa.m_xy;
    }
    if ( upperBoundIndex != -1 )
    {
      v9 = state->m_outgoingSegments.m_data[state->m_outgoingSegments.m_size - 1];
      goto LABEL_10;
    }
  }
  else if ( lowerBoundIndex != -1 && upperBoundIndex != -1 )
  {
    m_data = state->m_segments.m_data;
    v8 = &m_data[lowerBoundIndex];
    LODWORD(m_data) = m_data[upperBoundIndex].m_b.m_xy
                    - m_data[upperBoundIndex].m_a.m_xy
                    + 2
                    * ((LOWORD(m_data[upperBoundIndex].m_b.m_xy) - LOWORD(m_data[upperBoundIndex].m_a.m_xy)) & 0x8000);
    LODWORD(v8) = v8->m_b.m_xy - v8->m_a.m_xy + 2 * ((LOWORD(v8->m_b.m_xy) - LOWORD(v8->m_a.m_xy)) & 0x8000);
    if ( (__int16)m_data * ((int)v8 >> 16) < (__int16)v8 * ((int)m_data >> 16) )
    {
      v9 = lowerBoundIndex;
LABEL_10:
      hkaiNewFaceCutterUtil::Step::addIntersectionEvent(state, v9, upperBoundIndex, curEventPos);
    }
  }
}

// File Line: 854
// RVA: 0x12F7270
void __fastcall hkaiNewFaceCutterUtil::step(hkaiNewFaceCutterUtil::State *state)
{
  unsigned int v2; // ebx
  __int16 v3; // si
  __int64 m_size; // rax
  __int16 upperBoundIndexOut[8]; // [rsp+30h] [rbp-28h] BYREF
  bool equalSlopeFoundOut; // [rsp+60h] [rbp+8h] BYREF
  __int16 lowerBoundIndexOut; // [rsp+68h] [rbp+10h] BYREF
  __int16 bottomRegionIndexOut; // [rsp+70h] [rbp+18h] BYREF
  __int16 topRegionIndex; // [rsp+78h] [rbp+20h] BYREF

  hkaiNewFaceCutterUtil::Step::popInvalidEvents(state);
  if ( state->m_eventQueue.m_heap.m_size != 1 )
  {
    v2 = state->m_eventQueue.m_heap.m_data[1].m_posAndType >> 2;
    hkaiNewFaceCutterUtil::checkState(state, (hkaiNewFaceCutterUtil::Vec2)v2);
    hkaiNewFaceCutterUtil::Step::gatherSegmentsForEvent(
      state,
      (hkaiNewFaceCutterUtil::Vec2)v2,
      &lowerBoundIndexOut,
      upperBoundIndexOut);
    v3 = lowerBoundIndexOut;
    hkaiNewFaceCutterUtil::Step::getBoundingRegions(
      state,
      lowerBoundIndexOut,
      upperBoundIndexOut[0],
      &bottomRegionIndexOut,
      &topRegionIndex);
    hkaiNewFaceCutterUtil::Step::growRegions(state, bottomRegionIndexOut, (hkaiNewFaceCutterUtil::Vec2)v2);
    LOBYTE(lowerBoundIndexOut) = 0;
    equalSlopeFoundOut = 0;
    hkaiNewFaceCutterUtil::Step::resolveRegionJoinOrSplit(
      state,
      &bottomRegionIndexOut,
      &topRegionIndex,
      (hkaiNewFaceCutterUtil::Vec2)v2,
      (bool *)&lowerBoundIndexOut,
      &equalSlopeFoundOut);
    if ( !(_BYTE)lowerBoundIndexOut )
    {
      hkaiNewFaceCutterUtil::Step::setOutgoingSegmentStartPoints(state, (hkaiNewFaceCutterUtil::Vec2)v2);
      hkaiNewFaceCutterUtil::Step::sortOutgoingSegmentsBySlope(state, &equalSlopeFoundOut);
    }
    if ( equalSlopeFoundOut )
      hkaiNewFaceCutterUtil::Step::mergeEqualSlopeOutgoingSegments(state);
    hkaiNewFaceCutterUtil::Step::resolveOuterReflexVertices(
      state,
      &topRegionIndex,
      &bottomRegionIndexOut,
      (hkaiNewFaceCutterUtil::Vec2)v2);
    m_size = state->m_outgoingSegments.m_size;
    if ( (_DWORD)m_size )
      state->m_segments.m_data[state->m_outgoingSegments.m_data[m_size - 1]].m_aboveRegion = topRegionIndex;
    if ( v3 != -1 )
      state->m_segments.m_data[v3].m_aboveRegion = bottomRegionIndexOut;
    hkaiNewFaceCutterUtil::Step::updateOutgoingSegmentData(state, v3, upperBoundIndexOut[0]);
    hkaiNewFaceCutterUtil::Step::addIntersectionEvents(
      state,
      v3,
      upperBoundIndexOut[0],
      (hkaiNewFaceCutterUtil::Vec2)v2);
  }
}


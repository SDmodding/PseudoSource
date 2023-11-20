// File Line: 20
// RVA: 0x12F8020
void __fastcall hkaiNewFaceCutterUtil::Step::popInvalidEvents(hkaiNewFaceCutterUtil::State *state)
{
  hkaiNewFaceCutterUtil::State *i; // rbx

  for ( i = state; i->m_eventQueue.m_heap.m_size != 1; hkaiNewFaceCutterUtil::EventQueue::popFront(&i->m_eventQueue) )
  {
    if ( hkaiNewFaceCutterUtil::eventIsValid(i, i->m_eventQueue.m_heap.m_data + 1) )
      break;
  }
}

// File Line: 31
// RVA: 0x12F7400
void __fastcall hkaiNewFaceCutterUtil::Step::gatherSegmentsForEvent(hkaiNewFaceCutterUtil::State *state, hkaiNewFaceCutterUtil::Vec2 eventPos, __int16 *lowerBoundIndexOut, __int16 *upperBoundIndexOut)
{
  signed __int16 v4; // r12
  hkaiNewFaceCutterUtil::EventQueue *v5; // rsi
  char v6; // r14
  __int16 *v7; // rbp
  __int16 *v8; // r13
  hkaiNewFaceCutterUtil::State *v9; // rbx
  int v10; // edi
  __int16 v11; // r15
  hkaiNewFaceCutterUtil::Event v12; // xmm0
  hkaiNewFaceCutterUtil::Segment *v13; // r9
  signed __int64 v14; // rcx
  __int16 v15; // r8
  hkaiNewFaceCutterUtil::Event *v16; // rcx
  int v17; // eax
  __int64 v18; // rdx
  signed __int64 v19; // rax
  hkaiNewFaceCutterUtil::Event *v20; // rcx
  __int16 v21; // bp
  signed __int64 v22; // r8
  __int16 v23; // cx
  __int16 v24; // dx
  hkaiNewFaceCutterUtil::Segment *v25; // r8
  __int16 v26; // cx
  __int16 v27; // dx
  hkaiNewFaceCutterUtil::Segment *v28; // r8
  hkaiNewFaceCutterUtil::Segment *v29; // rbp
  __int16 i; // r11
  signed __int64 v31; // rsi
  int v32; // edx
  int v33; // ecx
  int v34; // er9
  int v35; // ecx
  hkaiNewFaceCutterUtil::Segment *v36; // rbp
  __int16 j; // r11
  signed __int64 v38; // rsi
  int v39; // edx
  int v40; // ecx
  int v41; // er9
  int v42; // ecx
  signed __int64 v43; // rdx
  unsigned __int16 v44; // ax
  __int16 v45; // r9
  signed __int64 v46; // r10
  int v47; // edx
  unsigned __int16 v48; // ax
  hkaiNewFaceCutterUtil::Event event; // [rsp+20h] [rbp-48h]
  unsigned int v50; // [rsp+78h] [rbp+10h]
  __int16 *v51; // [rsp+88h] [rbp+20h]

  v51 = upperBoundIndexOut;
  v50 = eventPos.m_xy;
  v4 = -1;
  v5 = &state->m_eventQueue;
  state->m_incomingSegments.m_size = 0;
  v6 = 0;
  state->m_outgoingSegments.m_size = 0;
  v7 = upperBoundIndexOut;
  v8 = lowerBoundIndexOut;
  v9 = state;
  LOWORD(v10) = -1;
  v11 = -1;
  if ( state->m_eventQueue.m_heap.m_size == 1 )
    goto LABEL_57;
  while ( v5->m_heap.m_data[1].m_posAndType >> 2 == v50 )
  {
    v12 = v5->m_heap.m_data[1];
    event = v12;
    if ( v12.m_posAndType & 3 )
    {
      if ( (v12.m_posAndType & 3) == 1 )
      {
        v18 = event.m_data.m_startSegmentData.m_startingSegmentA;
        v9->m_outgoingSegments.m_data[v9->m_outgoingSegments.m_size++] = event.m_data.m_startSegmentData.m_startingSegmentA;
        v19 = (signed __int64)&v9->m_segments.m_data[v18];
        if ( *(_WORD *)(v19 + 14) )
        {
          hkaiNewFaceCutterUtil::EventQueue::popFront(v5);
        }
        else
        {
          v20 = v5->m_heap.m_data;
          v20[1].m_data.m_startSegmentData.m_startingSegmentA = v18;
          v20[1].m_posAndType = 4 * *(_DWORD *)(v19 + 4) | 2;
          hkaiNewFaceCutterUtil::EventQueue::heapifyFirst(v5);
        }
        v21 = event.m_data.m_startSegmentData.m_startingSegmentB;
        if ( event.m_data.m_startSegmentData.m_startingSegmentB != -1 )
        {
          v9->m_outgoingSegments.m_data[v9->m_outgoingSegments.m_size++] = event.m_data.m_startSegmentData.m_startingSegmentB;
          if ( v5->m_heap.m_size == (v5->m_heap.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 16);
          v22 = (signed __int64)&v5->m_heap.m_data[v5->m_heap.m_size++];
          *(_WORD *)(v22 + 4) = v21;
          *(_DWORD *)v22 = 4 * v9->m_segments.m_data[v21].m_b.m_xy | 2;
          hkaiNewFaceCutterUtil::EventQueue::heapifyLast(v5);
        }
      }
      else if ( (v12.m_posAndType & 3) == 2 )
      {
        v13 = v9->m_segments.m_data;
        v14 = v12.m_data.m_startSegmentData.m_startingSegmentA;
        if ( (_WORD)v10 == -1 && v13[v14].m_a.m_xy != v13[v14].m_b.m_xy )
        {
          LOWORD(v10) = v12.m_data.m_startSegmentData.m_startingSegmentA;
          v11 = v12.m_data.m_startSegmentData.m_startingSegmentA;
        }
        v15 = v13[v14].m_followingSegment;
        if ( v15 == -1 )
        {
          hkaiNewFaceCutterUtil::EventQueue::popFront(v5);
        }
        else
        {
          v9->m_outgoingSegments.m_data[v9->m_outgoingSegments.m_size++] = v15;
          v16 = v5->m_heap.m_data;
          v17 = 4 * v13[v15].m_b.m_xy | 2;
          v16[1].m_data.m_startSegmentData.m_startingSegmentA = v15;
          v16[1].m_posAndType = v17;
          hkaiNewFaceCutterUtil::EventQueue::heapifyFirst(v5);
        }
      }
      goto LABEL_37;
    }
    hkaiNewFaceCutterUtil::EventQueue::popFront(v5);
    if ( hkaiNewFaceCutterUtil::eventIsValid(v9, &event) )
    {
      if ( !v6 )
        goto LABEL_27;
      v23 = event.m_data.m_startSegmentData.m_startingSegmentA;
      v24 = v10;
      if ( (signed __int16)v10 != event.m_data.m_startSegmentData.m_startingSegmentA )
      {
        while ( v23 != (_WORD)v10 )
        {
          v25 = v9->m_segments.m_data;
          v23 = v25[v23].m_nextSegment;
          if ( v23 == -1 )
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
            v28 = v9->m_segments.m_data;
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
    if ( v5->m_heap.m_size == 1 )
      break;
  }
  if ( (_WORD)v10 != -1 )
  {
    v29 = v9->m_segments.m_data;
    for ( i = v29[(signed __int16)v10].m_prevSegment; i != -1; i = *(_WORD *)(v31 + 18) )
    {
      v31 = (signed __int64)&v29[i];
      v32 = *(_DWORD *)v31 - *(_DWORD *)(v31 + 4) + 2 * ((*(_WORD *)v31 - *(_WORD *)(v31 + 4)) & 0x8000);
      v33 = v50 - *(_DWORD *)(v31 + 4) + 2 * (((_WORD)v50 - *(_WORD *)(v31 + 4)) & 0x8000);
      v34 = (signed __int16)v32 * (signed __int16)v33 + SHIWORD(v32) * (v33 >> 16);
      v35 = SHIWORD(v32) * (signed __int16)v33 - (signed __int16)v32 * (v33 >> 16);
      if ( !v35 )
        v35 = v34;
      if ( v35 < 0 )
        break;
      LOWORD(v10) = i;
    }
    *v8 = i;
    v36 = v9->m_segments.m_data;
    for ( j = v36[v11].m_nextSegment; j != -1; j = *(_WORD *)(v38 + 20) )
    {
      v38 = (signed __int64)&v36[j];
      v39 = *(_DWORD *)(v38 + 4) - *(_DWORD *)v38 + 2 * ((*(_WORD *)(v38 + 4) - *(_WORD *)v38) & 0x8000);
      v40 = v50 - *(_DWORD *)v38 + 2 * (((_WORD)v50 - *(_WORD *)v38) & 0x8000);
      v41 = (signed __int16)v39 * (signed __int16)v40 + SHIWORD(v39) * (v40 >> 16);
      v42 = SHIWORD(v39) * (signed __int16)v40 - (signed __int16)v39 * (v40 >> 16);
      if ( !v42 )
        v42 = v41;
      if ( v42 < 0 )
        break;
    }
    *v51 = j;
    if ( (signed __int16)v10 != j )
    {
      do
      {
        v43 = (signed __int64)&v9->m_segments.m_data[(signed __int16)v10];
        v9->m_incomingSegments.m_data[v9->m_incomingSegments.m_size++] = v10;
        v44 = *(_WORD *)(v43 + 14);
        if ( v44 < 0xFF00u )
        {
          if ( *(_DWORD *)(v43 + 4) != v50 )
            v9->m_outgoingSegments.m_data[v9->m_outgoingSegments.m_size++] = v10;
        }
        else
        {
          *(_WORD *)(v43 + 14) = v44 + 1;
        }
        v10 = *(signed __int16 *)(v43 + 20);
      }
      while ( v10 != j );
    }
    return;
  }
  v7 = v51;
LABEL_57:
  v45 = v9->m_sweepState.m_firstSegment;
  if ( v45 != -1 )
  {
    while ( 1 )
    {
      v46 = (signed __int64)&v9->m_segments.m_data[v45];
      v47 = v50 - *(_DWORD *)v46 + 2 * (((_WORD)v50 - *(_WORD *)v46) & 0x8000);
      if ( (signed __int16)v47
         * ((*(_DWORD *)(v46 + 4) - *(_DWORD *)v46 + 2 * ((*(_WORD *)(v46 + 4) - *(_WORD *)v46) & 0x8000)) >> 16)
         - (signed __int16)(*(_WORD *)(v46 + 4) - *(_WORD *)v46 + 2 * ((*(_WORD *)(v46 + 4) - *(_WORD *)v46) & 0x8000))
         * SHIWORD(v47) <= 0 )
        break;
      v4 = v45;
      v45 = *(_WORD *)(v46 + 20);
      if ( v45 == -1 )
        goto LABEL_66;
    }
    if ( (signed __int16)v47
       * ((*(_DWORD *)(v46 + 4) - *(_DWORD *)v46 + 2 * ((*(_WORD *)(v46 + 4) - *(_WORD *)v46) & 0x8000)) >> 16) == (signed __int16)(*(_WORD *)(v46 + 4) - *(_WORD *)v46 + 2 * ((*(_WORD *)(v46 + 4) - *(_WORD *)v46) & 0x8000)) * SHIWORD(v47) )
    {
      v9->m_incomingSegments.m_data[v9->m_incomingSegments.m_size++] = v45;
      v48 = *(_WORD *)(v46 + 14);
      if ( v48 < 0xFF00u )
        v9->m_outgoingSegments.m_data[v9->m_outgoingSegments.m_size++] = v45;
      else
        *(_WORD *)(v46 + 14) = v48 + 1;
      v45 = *(_WORD *)(v46 + 20);
    }
  }
LABEL_66:
  *v8 = v4;
  *v7 = v45;
}

// File Line: 287
// RVA: 0x12F79C0
void __fastcall hkaiNewFaceCutterUtil::Step::getBoundingRegions(hkaiNewFaceCutterUtil::State *state, __int16 lowerBoundIndex, __int16 upperBoundIndex, __int16 *bottomRegionIndexOut, __int16 *topRegionIndexOut)
{
  __int16 v5; // cx

  if ( lowerBoundIndex == -1 )
    *bottomRegionIndexOut = -1;
  else
    *bottomRegionIndexOut = state->m_segments.m_data[lowerBoundIndex].m_aboveRegion;
  if ( state->m_incomingSegments.m_size )
    v5 = state->m_segments.m_data[state->m_incomingSegments.m_data[state->m_incomingSegments.m_size - 1]].m_aboveRegion;
  else
    v5 = *bottomRegionIndexOut;
  *topRegionIndexOut = v5;
}

// File Line: 309
// RVA: 0x12F8080
void __fastcall hkaiNewFaceCutterUtil::Step::growRegions(hkaiNewFaceCutterUtil::State *state, __int16 bottomRegionIndex, hkaiNewFaceCutterUtil::Vec2 eventPos)
{
  int v3; // eax
  hkaiNewFaceCutterUtil::State *v4; // rdi
  unsigned int v5; // er9
  __int64 v6; // rbp
  __int16 v7; // r14
  __int64 v8; // r15
  unsigned int aboveConnectivity; // ebx
  signed __int64 v10; // rsi
  __int16 v11; // cx
  hkaiNewFaceCutterUtil::Region *v12; // rdx
  __int16 v13; // ax
  signed __int64 v14; // rdx
  hkaiNewFaceCutterUtil::RegionEdgeConnectivity *v15; // rdx
  __int16 v16; // ax
  hkaiNewFaceCutterUtil::RegionEdge *v17; // rcx
  __int64 v18; // rcx
  hkaiNewFaceCutterUtil::RegionEdge *v19; // rax
  unsigned int bottomEdgeIndexOut; // [rsp+80h] [rbp+8h]
  hkaiNewFaceCutterUtil::Vec2 eventPosa; // [rsp+90h] [rbp+18h]
  __int16 topEdgeIndexOut; // [rsp+98h] [rbp+20h]

  eventPosa.m_xy = eventPos.m_xy;
  v3 = state->m_incomingSegments.m_size;
  v4 = state;
  if ( v3 )
  {
    v5 = bottomEdgeIndexOut & 0xFFFF0001 | 1;
    v6 = 0i64;
    v7 = -1;
    v8 = state->m_incomingSegments.m_size;
    if ( v3 > 0 )
    {
      aboveConnectivity = bottomEdgeIndexOut;
      do
      {
        v10 = (signed __int64)&v4->m_segments.m_data[v4->m_incomingSegments.m_data[v6]];
        v11 = *(_WORD *)(v10 + 12);
        if ( v11 == -1 )
          aboveConnectivity = aboveConnectivity & 0xFFFF0001 | 1;
        else
          aboveConnectivity = aboveConnectivity & 0xFFFF0000 | 4 * (v11 & 0x3FFF);
        if ( bottomRegionIndex == -1 )
        {
          v7 = -1;
        }
        else
        {
          v12 = &v4->m_regions.m_data[bottomRegionIndex];
          if ( v6 )
          {
            hkaiNewFaceCutterUtil::closeRegionAt(
              v4,
              v12,
              eventPos,
              (hkaiNewFaceCutterUtil::RegionEdgeConnectivity)v5,
              (hkaiNewFaceCutterUtil::RegionEdgeConnectivity)aboveConnectivity,
              (__int16 *)&bottomEdgeIndexOut,
              &topEdgeIndexOut);
            if ( v7 != -1 && (_WORD)bottomEdgeIndexOut != -1 )
            {
              v14 = (signed __int64)&v4->m_regionEdges.m_data[v7];
              *(_DWORD *)(v14 + 4) = *(_DWORD *)(v14 + 4) & 0xFFFF0002 | 4 * (bottomEdgeIndexOut & 0x3FFF) | 2;
              v15 = &v4->m_regionEdges.m_data[(signed __int16)bottomEdgeIndexOut].m_connectivity;
              *(_DWORD *)v15 &= 0xFFFF0002;
              *(_DWORD *)v15 |= 4 * (v7 & 0x3FFF) | 2;
            }
            v7 = topEdgeIndexOut;
            eventPos.m_xy = eventPosa.m_xy;
          }
          else
          {
            v13 = hkaiNewFaceCutterUtil::addTopEdgeToRegion(
                    v4,
                    v12,
                    eventPos,
                    (hkaiNewFaceCutterUtil::RegionEdgeConnectivity)aboveConnectivity);
            eventPos.m_xy = eventPosa.m_xy;
            topEdgeIndexOut = v13;
            v7 = v13;
          }
        }
        bottomRegionIndex = *(_WORD *)(v10 + 22);
        ++v6;
        v5 = aboveConnectivity;
      }
      while ( v6 < v8 );
    }
    if ( bottomRegionIndex != -1 )
    {
      v16 = hkaiNewFaceCutterUtil::addBottomEdgeToRegion(
              v4,
              &v4->m_regions.m_data[bottomRegionIndex],
              eventPos,
              (hkaiNewFaceCutterUtil::RegionEdgeConnectivity)v5);
      if ( v7 != -1 && v16 != -1 )
      {
        v17 = v4->m_regionEdges.m_data;
        *(_DWORD *)&v17[v7].m_connectivity &= 0xFFFF0002;
        *(_DWORD *)&v17[v7].m_connectivity |= 4 * (v16 & 0x3FFF) | 2;
        v18 = v16;
        v19 = v4->m_regionEdges.m_data;
        *(_DWORD *)&v19[v18].m_connectivity &= 0xFFFF0002;
        *(_DWORD *)&v19[v18].m_connectivity |= 4 * (v7 & 0x3FFF) | 2;
      }
    }
  }
}

// File Line: 394
// RVA: 0x12F7A40
void __fastcall hkaiNewFaceCutterUtil::Step::sortOutgoingSegmentsBySlope(hkaiNewFaceCutterUtil::State *state, bool *equalSlopeFoundOut)
{
  int v2; // er8
  __int16 *v3; // rcx
  hkaiNewFaceCutterUtil::OutgoingSegmentLessComparator v4; // [rsp+20h] [rbp-18h]

  *equalSlopeFoundOut = 0;
  v2 = state->m_outgoingSegments.m_size;
  if ( v2 )
  {
    v4.m_state = state;
    v4.m_equalSlopeFoundOut = equalSlopeFoundOut;
    if ( v2 > 1 )
    {
      v3 = state->m_outgoingSegments.m_data;
      _mm_store_si128((__m128i *)&v4, (__m128i)v4);
      hkAlgorithm::quickSortRecursive<short,hkaiNewFaceCutterUtil::OutgoingSegmentLessComparator>(v3, 0, v2 - 1, &v4);
    }
  }
}

// File Line: 408
// RVA: 0x12F82D0
void __fastcall hkaiNewFaceCutterUtil::Step::processRegionSplit(hkaiNewFaceCutterUtil::State *state, __int16 *bottomRegionIndexInOut, __int16 *topRegionIndexInOut)
{
  __int64 v3; // r12
  hkArrayBase<short> *v4; // r15
  hkaiNewFaceCutterUtil::State *v5; // rbp
  hkArray<hkaiNewFaceCutterUtil::Segment,hkContainerHeapAllocator> *v6; // r14
  hkaiNewFaceCutterUtil::Vec2 *v7; // r8
  hkaiNewFaceCutterUtil::Region *v8; // r11
  __int16 *v9; // r9
  __int16 *v10; // r13
  hkaiNewFaceCutterUtil::RegionEdge *v11; // rdx
  hkaiNewFaceCutterUtil::Segment *v12; // rax
  hkaiNewFaceCutterUtil::Vec2 v13; // ebx
  unsigned int v14; // esi
  unsigned int v15; // edi
  __int16 v16; // r12
  int v17; // er8
  __int16 v18; // di
  signed __int64 v19; // rax
  int v20; // edx
  int v21; // edx
  __int16 v22; // di
  signed __int64 v23; // rax
  unsigned int t; // [rsp+80h] [rbp+8h]
  hkaiNewFaceCutterUtil::Segment *v25; // [rsp+88h] [rbp+10h]
  __int16 *topRegionIndexOut; // [rsp+90h] [rbp+18h]
  hkaiNewFaceCutterUtil::Segment *v27; // [rsp+98h] [rbp+20h]

  topRegionIndexOut = topRegionIndexInOut;
  v3 = *bottomRegionIndexInOut;
  v4 = (hkArrayBase<short> *)&state->m_outgoingSegments.m_data;
  v5 = state;
  v6 = &state->m_segments;
  v7 = state->m_outputVertices.m_data;
  v8 = &state->m_regions.m_data[v3];
  v9 = state->m_outgoingSegments.m_data;
  v10 = bottomRegionIndexInOut;
  v11 = state->m_regionEdges.m_data;
  v12 = &state->m_segments.m_data[v9[state->m_outgoingSegments.m_size - 1]];
  v27 = &state->m_segments.m_data[*v9];
  v13.m_xy = v27->m_a.m_xy;
  v25 = v12;
  v14 = v7[v11[v8->m_head].m_outputVertexIndex].m_xy;
  v15 = v7[v11[v8->m_tail].m_outputVertexIndex].m_xy;
  t = v13.m_xy - v14;
  LODWORD(v7) = v27->m_b.m_xy - v14 + 2 * ((LOWORD(v27->m_b.m_xy) - (_WORD)v14) & 0x8000);
  if ( (signed __int16)v7 * ((signed int)(v13.m_xy - v14 + 2 * ((LOWORD(v13.m_xy) - (_WORD)v14) & 0x8000)) >> 16)
     - (signed __int16)(LOWORD(v13.m_xy) - v14 + 2 * ((LOWORD(v13.m_xy) - v14) & 0x8000)) * ((signed int)v7 >> 16) > 0 )
  {
    v20 = v25->m_b.m_xy - v15 + 2 * ((LOWORD(v25->m_b.m_xy) - (_WORD)v15) & 0x8000);
    if ( (signed __int16)v20 * ((signed int)(v13.m_xy - v15 + 2 * ((LOWORD(v13.m_xy) - (_WORD)v15) & 0x8000)) >> 16)
       - (signed __int16)(LOWORD(v13.m_xy) - v15 + 2 * ((LOWORD(v13.m_xy) - v15) & 0x8000)) * (v20 >> 16) < 0 )
    {
      hkaiNewFaceCutterUtil::splitRegionAtBothEdges(state, v3, v13, v10, topRegionIndexOut);
    }
    else
    {
      *v10 = hkaiNewFaceCutterUtil::splitRegionAtNewBottomEdge(state, v3, v13);
      v21 = v27->m_b.m_xy - v15 + 2 * ((LOWORD(v27->m_b.m_xy) - (_WORD)v15) & 0x8000);
      if ( (signed __int16)v21 * ((signed int)(v13.m_xy - v15 + 2 * ((LOWORD(v13.m_xy) - (_WORD)v15) & 0x8000)) >> 16)
         - (signed __int16)(LOWORD(v13.m_xy) - v15 + 2 * ((LOWORD(v13.m_xy) - v15) & 0x8000)) * (v21 >> 16) > 0 )
      {
        v22 = v5->m_segments.m_size;
        if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 28);
        ++v6->m_size;
        v23 = (signed __int64)&v6->m_data[v22];
        LOWORD(t) = v22;
        *(hkaiNewFaceCutterUtil::Vec2 *)v23 = v13;
        *(_WORD *)(v23 + 14) = -256;
        *(_DWORD *)(v23 + 8) = 0;
        *(_WORD *)(v23 + 22) = -1;
        *(_WORD *)(v23 + 16) = -1;
        *(_DWORD *)(v23 + 4) = ((v13.m_xy >> 16) + 1) << 16;
        hkArrayBase<short>::_insertAt(
          v4,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          0,
          (const __int16 *)&t);
      }
    }
  }
  else
  {
    v16 = hkaiNewFaceCutterUtil::splitRegionAtNewTopEdge(state, v3, v13);
    *topRegionIndexOut = v16;
    v17 = v25->m_b.m_xy - v14 + 2 * ((LOWORD(v25->m_b.m_xy) - (_WORD)v14) & 0x8000);
    if ( (signed __int16)v17 * ((signed int)(t + 2 * (t & 0x8000)) >> 16)
       - (signed __int16)(t + 2 * (t & 0x8000)) * (v17 >> 16) < 0 )
    {
      v18 = v5->m_segments.m_size;
      if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 28);
      ++v6->m_size;
      v19 = (signed __int64)&v6->m_data[v18];
      *(hkaiNewFaceCutterUtil::Vec2 *)v19 = v13;
      *(_WORD *)(v19 + 14) = -256;
      *(_DWORD *)(v19 + 8) = 0;
      *(_WORD *)(v19 + 22) = v16;
      *(_WORD *)(v19 + 16) = -1;
      *(_DWORD *)(v19 + 4) = v13.m_xy & 0xFFFF3FFF | 0x3FFF;
      if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 2);
      v4->m_data[v4->m_size++] = v18;
    }
  }
}

// File Line: 460
// RVA: 0x12F8610
void __fastcall hkaiNewFaceCutterUtil::Step::resolveRegionJoinOrSplit(hkaiNewFaceCutterUtil::State *state, __int16 *bottomRegionIndex, __int16 *topRegionIndex, hkaiNewFaceCutterUtil::Vec2 eventPos, bool *slopeSorted, bool *equalSlopeFound)
{
  unsigned int v6; // ebx
  __int16 *v7; // r14
  __int16 *v8; // rsi
  hkaiNewFaceCutterUtil::State *v9; // rdi
  __int16 v10; // r14
  hkArray<hkaiNewFaceCutterUtil::Segment,hkContainerHeapAllocator> *v11; // rsi
  __int16 v12; // bp
  signed __int64 v13; // rcx

  v6 = eventPos.m_xy;
  v7 = topRegionIndex;
  v8 = bottomRegionIndex;
  v9 = state;
  if ( *bottomRegionIndex != -1 )
  {
    if ( state->m_outgoingSegments.m_size )
    {
      if ( !state->m_incomingSegments.m_size )
      {
        hkaiNewFaceCutterUtil::Step::sortOutgoingSegmentsBySlope(state, equalSlopeFound);
        *slopeSorted = 1;
        hkaiNewFaceCutterUtil::Step::processRegionSplit(v9, v8, v7);
      }
    }
    else
    {
      v10 = *topRegionIndex;
      v11 = &state->m_segments;
      v12 = state->m_segments.m_size;
      if ( state->m_segments.m_size == (state->m_segments.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v11, 28);
      ++v11->m_size;
      v13 = (signed __int64)&v11->m_data[v12];
      *(_DWORD *)(v13 + 4) = (unsigned __int16)v6 | 0x3FFF0000;
      *(_DWORD *)v13 = v6;
      *(_DWORD *)(v13 + 8) = 0;
      *(_WORD *)(v13 + 22) = v10;
      *(_WORD *)(v13 + 14) = -256;
      *(_WORD *)(v13 + 16) = -1;
      v9->m_outgoingSegments.m_data[v9->m_outgoingSegments.m_size++] = v12;
      *slopeSorted = 1;
    }
  }
}

// File Line: 490
// RVA: 0x12F8730
void __fastcall hkaiNewFaceCutterUtil::Step::setOutgoingSegmentStartPoints(hkaiNewFaceCutterUtil::State *state, hkaiNewFaceCutterUtil::Vec2 pos)
{
  __int64 v2; // rdi
  __int64 v3; // r11
  hkaiNewFaceCutterUtil::State *v4; // rbx
  signed __int64 v5; // rcx
  hkaiNewFaceCutterUtil::Vec2 v6; // eax
  signed int v7; // er9
  unsigned int v8; // [rsp+10h] [rbp+10h]

  v2 = state->m_outgoingSegments.m_size;
  v3 = 0i64;
  v8 = pos.m_xy;
  v4 = state;
  if ( v2 > 0 )
  {
    while ( 1 )
    {
      v5 = (signed __int64)&v4->m_segments.m_data[v4->m_outgoingSegments.m_data[v3]];
      v6.m_xy = *(_DWORD *)v5;
      if ( *(_DWORD *)v5 != pos.m_xy )
      {
        v7 = pos.m_xy - v6.m_xy + 2 * ((LOWORD(pos.m_xy) - LOWORD(v6.m_xy)) & 0x8000);
        if ( (signed __int16)v7
           * ((signed int)(*(_DWORD *)(v5 + 4) - v6.m_xy + 2 * ((*(_WORD *)(v5 + 4) - LOWORD(v6.m_xy)) & 0x8000)) >> 16) != (signed __int16)(*(_WORD *)(v5 + 4) - LOWORD(v6.m_xy) + 2 * ((*(_WORD *)(v5 + 4) - LOWORD(v6.m_xy)) & 0x8000)) * (v7 >> 16) )
        {
          ++*(_WORD *)(v5 + 14);
          pos.m_xy = v8;
        }
      }
      ++v3;
      *(hkaiNewFaceCutterUtil::Vec2 *)v5 = pos;
      if ( v3 >= v2 )
        break;
      pos.m_xy = v8;
    }
  }
}

// File Line: 518
// RVA: 0x12F87E0
void __fastcall hkaiNewFaceCutterUtil::Step::resolveOuterReflexVertices(hkaiNewFaceCutterUtil::State *state, __int16 *topRegionIndex, __int16 *bottomRegionIndex, hkaiNewFaceCutterUtil::Vec2 eventPos)
{
  unsigned int v4; // ebx
  __int64 v5; // r9
  __int16 *v6; // r15
  __int16 *v7; // r10
  hkaiNewFaceCutterUtil::State *v8; // rdi
  hkArrayBase<short> *v9; // r14
  __int16 v10; // bp
  hkArray<hkaiNewFaceCutterUtil::Segment,hkContainerHeapAllocator> *v11; // rsi
  hkaiNewFaceCutterUtil::Segment *v12; // rdx
  signed __int64 v13; // r8
  int v14; // er12
  int v15; // er11
  signed __int64 v16; // r9
  unsigned int v17; // eax
  int v18; // edx
  __int16 v19; // r12
  signed __int64 v20; // rax
  hkArray<hkaiNewFaceCutterUtil::Segment,hkContainerHeapAllocator> *v21; // rsi
  hkaiNewFaceCutterUtil::Segment *v22; // r9
  hkaiNewFaceCutterUtil::Segment *v23; // rdx
  unsigned int v24; // er11
  int v25; // er8
  unsigned int v26; // eax
  int v27; // ecx
  __int16 v28; // di
  signed __int64 v29; // rax
  __int16 t; // [rsp+60h] [rbp+8h]
  unsigned int v31; // [rsp+78h] [rbp+20h]

  v31 = eventPos.m_xy;
  v4 = eventPos.m_xy;
  v5 = state->m_incomingSegments.m_size;
  v6 = bottomRegionIndex;
  v7 = topRegionIndex;
  v8 = state;
  v9 = (hkArrayBase<short> *)&state->m_outgoingSegments.m_data;
  if ( (_DWORD)v5 )
  {
    v10 = *topRegionIndex;
    if ( *topRegionIndex != -1 )
    {
      v11 = &state->m_segments;
      v12 = state->m_segments.m_data;
      v13 = 28i64 * state->m_outgoingSegments.m_data[state->m_outgoingSegments.m_size - 1];
      v14 = *(unsigned int *)((char *)&v12->m_b.m_xy + v13);
      v15 = *(unsigned int *)((char *)&v12->m_a.m_xy + v13);
      v16 = state->m_incomingSegments.m_data[v5 - 1];
      LODWORD(v13) = *(unsigned int *)((char *)&v12->m_b.m_xy + v13)
                   - v15
                   + 2 * ((*(_WORD *)((char *)&v12->m_b.m_xy + v13) - (_WORD)v15) & 0x8000);
      LODWORD(v12) = v12[v16].m_b.m_xy
                   - v12[v16].m_a.m_xy
                   + 2 * ((LOWORD(v12[v16].m_b.m_xy) - LOWORD(v12[v16].m_a.m_xy)) & 0x8000);
      if ( (signed __int16)v13 * ((signed int)v12 >> 16) < (signed __int16)v12 * ((signed int)v13 >> 16) )
      {
        v17 = state->m_outputVertices.m_data[state->m_regionEdges.m_data[state->m_regions.m_data[v10].m_head].m_outputVertexIndex].m_xy;
        v18 = v14 - v17 + 2 * (((_WORD)v14 - (_WORD)v17) & 0x8000);
        if ( (signed __int16)v18 * ((signed int)(v15 - v17 + 2 * (((_WORD)v15 - (_WORD)v17) & 0x8000)) >> 16)
           - (signed __int16)(v15 - v17 + 2 * ((v15 - v17) & 0x8000)) * (v18 >> 16) < 0 )
        {
          v19 = state->m_segments.m_size;
          if ( state->m_segments.m_size == (state->m_segments.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v11, 28);
          ++v11->m_size;
          v20 = (signed __int64)&v11->m_data[v19];
          *(_DWORD *)v20 = v4;
          *(_DWORD *)(v20 + 8) = 0;
          *(_WORD *)(v20 + 14) = -256;
          *(_WORD *)(v20 + 22) = v10;
          *(_WORD *)(v20 + 16) = -1;
          *(_DWORD *)(v20 + 4) = v4 & 0xFFFF3FFF | 0x3FFF;
          v9->m_data[v9->m_size++] = v19;
        }
        else
        {
          hkaiNewFaceCutterUtil::splitRegionAtTopMouth(state, v7);
        }
        v4 = v31;
      }
    }
    if ( *v6 != -1 )
    {
      v21 = &v8->m_segments;
      v22 = &v8->m_segments.m_data[*v9->m_data];
      v23 = &v8->m_segments.m_data[*v8->m_incomingSegments.m_data];
      v24 = v22->m_a.m_xy;
      v25 = v23->m_b.m_xy - v23->m_a.m_xy + 2 * ((LOWORD(v23->m_b.m_xy) - LOWORD(v23->m_a.m_xy)) & 0x8000);
      LODWORD(v23) = v22->m_b.m_xy - v24 + 2 * ((LOWORD(v22->m_b.m_xy) - (_WORD)v24) & 0x8000);
      if ( (signed __int16)v25 * ((signed int)v23 >> 16) < (signed __int16)v23 * (v25 >> 16) )
      {
        v26 = v8->m_outputVertices.m_data[v8->m_regionEdges.m_data[v8->m_regions.m_data[*v6].m_tail].m_outputVertexIndex].m_xy;
        v27 = v22->m_b.m_xy - v26 + 2 * (((unsigned __int16)v22->m_b.m_xy - (_WORD)v26) & 0x8000);
        if ( (signed __int16)v27 * ((signed int)(v24 - v26 + 2 * (((_WORD)v24 - (_WORD)v26) & 0x8000)) >> 16)
           - (signed __int16)(v24 - v26 + 2 * ((v24 - v26) & 0x8000)) * (v27 >> 16) > 0 )
        {
          v28 = v8->m_segments.m_size;
          if ( v21->m_size == (v21->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v21, 28);
          ++v21->m_size;
          v29 = (signed __int64)&v21->m_data[v28];
          t = v28;
          *(_DWORD *)v29 = v4;
          *(_WORD *)(v29 + 14) = -256;
          *(_DWORD *)(v29 + 8) = 0;
          *(_WORD *)(v29 + 22) = -1;
          *(_WORD *)(v29 + 16) = -1;
          *(_DWORD *)(v29 + 4) = ((v4 >> 16) + 1) << 16;
          hkArrayBase<short>::_insertAt(v9, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, 0, &t);
        }
        else
        {
          hkaiNewFaceCutterUtil::splitRegionAtBottomMouth(v8, v6);
        }
      }
    }
  }
}

// File Line: 593
// RVA: 0x12F7A90
void __fastcall hkaiNewFaceCutterUtil::Step::mergeEqualSlopeOutgoingSegments(hkaiNewFaceCutterUtil::State *state)
{
  signed __int64 v1; // rsi
  signed __int64 v2; // r9
  int v3; // ebp
  hkaiNewFaceCutterUtil::State *v4; // r13
  hkaiNewFaceCutterUtil::Segment *v5; // rdx
  unsigned int v6; // edi
  unsigned int v7; // er11
  __int64 v8; // rdx
  signed __int64 v9; // r15
  unsigned int v10; // ebx
  int v11; // er12
  hkaiNewFaceCutterUtil::Segment *v12; // r14
  int v13; // er11
  __int16 *v14; // r10
  int v15; // er8
  signed __int64 v16; // r14
  __int16 *v17; // rax
  hkaiNewFaceCutterUtil::Segment *v18; // rcx
  __int16 v19; // dx
  signed __int64 v20; // rbp
  hkaiNewFaceCutterUtil::Vec2 v21; // er8
  signed __int64 v22; // rsi
  int v23; // eax
  int v24; // [rsp+70h] [rbp+8h]
  __int64 v25; // [rsp+78h] [rbp+10h]
  signed __int64 v26; // [rsp+80h] [rbp+18h]
  signed __int64 v27; // [rsp+88h] [rbp+20h]

  v1 = state->m_outgoingSegments.m_size;
  v2 = 0i64;
  v3 = 0;
  v4 = state;
  v26 = 0i64;
  v27 = v1;
  v5 = &state->m_segments.m_data[*state->m_outgoingSegments.m_data];
  v24 = 0;
  v6 = v5->m_a.m_xy;
  v7 = v5->m_b.m_xy;
  if ( v1 <= 0 )
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
      if ( v2 + 1 < v1 )
      {
        v12 = v4->m_segments.m_data;
        v13 = v7 - v6;
        v14 = &v4->m_outgoingSegments.m_data[v9];
        while ( 1 )
        {
          v15 = v12[*v14].m_b.m_xy - v6 + 2 * ((LOWORD(v12[*v14].m_b.m_xy) - (_WORD)v6) & 0x8000);
          if ( (signed __int16)v15 * ((v13 + 2 * (v13 & 0x8000)) >> 16) != (signed __int16)(v13 + 2 * (v13 & 0x8000))
                                                                         * (v15 >> 16) )
            break;
          ++v9;
          ++v11;
          ++v14;
          if ( v9 >= v1 )
            goto LABEL_9;
        }
        v10 = v12[*v14].m_b.m_xy;
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
            v17 = v4->m_outgoingSegments.m_data;
            v18 = v4->m_segments.m_data;
            v19 = v17[v16];
            v20 = (signed __int64)&v18[v17[v16 - 1]];
            v21.m_xy = *(_DWORD *)(v20 + 4);
            v22 = (signed __int64)&v18[v17[v16]];
            *(hkaiNewFaceCutterUtil::Vec2 *)v22 = v21;
            if ( *(_DWORD *)(v22 + 4) != v21.m_xy )
            {
              ++*(_WORD *)(v22 + 14);
              hkaiNewFaceCutterUtil::enqueueStartSegmentEvent(v4, v19, v21);
              v2 = v26;
            }
            *(_DWORD *)(v20 + 8) = (unsigned __int16)(*(_WORD *)(v20 + 8) ^ *(unsigned int *)(v22 + 8)) | ((*(_DWORD *)(v20 + 8) & 0xFFFF0000) + (*(_DWORD *)(v22 + 8) & 0xFFFF0000));
            if ( *(_WORD *)(v20 + 12) == -1 )
              *(_WORD *)(v20 + 12) = *(_WORD *)(v22 + 12);
            --v16;
          }
          while ( v16 != v2 );
          v1 = v27;
          v8 = v25;
        }
      }
      v8 += 2i64;
      v3 = v11;
      v26 = v9;
      v7 = v10;
      *(__int16 *)((char *)v4->m_outgoingSegments.m_data + v8 - 2) = v4->m_outgoingSegments.m_data[v2];
      v25 = v8;
      v23 = v24 + 1;
      v2 = v9;
      ++v24;
    }
    while ( v9 < v1 );
    v4->m_outgoingSegments.m_size = v23;
  }
}

// File Line: 672
// RVA: 0x12F7CE0
void __fastcall hkaiNewFaceCutterUtil::Step::updateOutgoingSegmentData(hkaiNewFaceCutterUtil::State *state, __int16 lowerBound, __int16 upperBound)
{
  __int64 v3; // rbp
  __int16 v4; // si
  hkaiNewFaceCutterUtil::State *v5; // rbx
  unsigned int v6; // eax
  __int16 *v7; // rcx
  int v8; // er9
  __int64 v9; // r14
  signed __int64 v10; // rdi
  __int64 v11; // r15
  char v12; // al
  __int64 v13; // rcx
  __int16 v14; // ax
  __int16 *v15; // rax
  hkaiNewFaceCutterUtil::Membership v16; // [rsp+58h] [rbp+10h]

  v3 = 0i64;
  v4 = upperBound;
  v5 = state;
  if ( lowerBound == -1 )
    v6 = 0;
  else
    v6 = state->m_segments.m_data[lowerBound].m_aboveMembership.m_data;
  if ( state->m_outgoingSegments.m_size )
  {
    v7 = state->m_outgoingSegments.m_data;
    if ( lowerBound == -1 )
      v5->m_sweepState.m_firstSegment = *v7;
    else
      v5->m_segments.m_data[lowerBound].m_nextSegment = *v7;
    v8 = v5->m_outgoingSegments.m_size;
    v9 = *v5->m_outgoingSegments.m_data;
    v16.m_data = v6;
    v10 = (signed __int64)&v5->m_segments.m_data[v9];
    *(_WORD *)(v10 + 18) = lowerBound;
    v16.m_data = (unsigned __int16)(LOWORD(v16.m_data) ^ *(unsigned int *)(v10 + 8)) | ((v16.m_data & 0xFFFF0000)
                                                                                      + (*(_DWORD *)(v10 + 8) & 0xFFFF0000));
    *(hkaiNewFaceCutterUtil::Membership *)(v10 + 24) = v16;
    v11 = v8 - 1;
    if ( v8 != 1 )
    {
      do
      {
        if ( (v16.m_data & 0xFFFF0001) == 1 )
        {
          v12 = hkaiNewFaceCutterUtil::Membership::getEffectivePainterIndex(&v16);
          *(_WORD *)(v10 + 22) = hkaiNewFaceCutterUtil::makeNewRegion(v5, *(hkaiNewFaceCutterUtil::Vec2 *)v10, v12);
        }
        else
        {
          *(_WORD *)(v10 + 22) = -1;
        }
        v13 = v5->m_outgoingSegments.m_data[++v3];
        v14 = v9;
        *(_WORD *)(v10 + 20) = v13;
        LOWORD(v9) = v13;
        v10 = (signed __int64)&v5->m_segments.m_data[v13];
        *(_WORD *)(v10 + 18) = v14;
        v16.m_data = (unsigned __int16)(LOWORD(v16.m_data) ^ *(unsigned int *)(v10 + 8)) | ((v16.m_data & 0xFFFF0000)
                                                                                          + (*(_DWORD *)(v10 + 8) & 0xFFFF0000));
        *(hkaiNewFaceCutterUtil::Membership *)(v10 + 24) = v16;
      }
      while ( v3 != v11 );
    }
    *(_WORD *)(v10 + 20) = v4;
    v15 = v5->m_outgoingSegments.m_data;
    if ( v4 == -1 )
      v5->m_sweepState.m_lastSegment = v15[v5->m_outgoingSegments.m_size - 1];
    else
      v5->m_segments.m_data[v4].m_prevSegment = v15[v5->m_outgoingSegments.m_size - 1];
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
void __fastcall hkaiNewFaceCutterUtil::Step::addIntersectionEvent(hkaiNewFaceCutterUtil::State *state, __int16 lowerSegmentIndex, __int16 upperSegmentIndex, hkaiNewFaceCutterUtil::Vec2 curEventPos)
{
  hkaiNewFaceCutterUtil::Segment *v4; // rax
  __int16 v5; // r12
  __int16 v6; // r13
  signed __int64 v7; // rdi
  signed __int64 v8; // rsi
  unsigned int v9; // er8
  unsigned int v10; // eax
  unsigned int v11; // edx
  unsigned int v12; // ecx
  int v13; // er14
  int v14; // er11
  int v15; // ebp
  int v16; // er11
  int v17; // er11
  int v18; // er15
  int v19; // er11
  int v20; // er14
  unsigned int v21; // edi
  int v22; // esi
  int v23; // er10
  int v24; // er10
  hkaiNewFaceCutterUtil::State *statea; // [rsp+50h] [rbp+8h]

  statea = state;
  v4 = state->m_segments.m_data;
  v5 = upperSegmentIndex;
  v6 = lowerSegmentIndex;
  v7 = (signed __int64)&v4[upperSegmentIndex];
  v8 = (signed __int64)&v4[lowerSegmentIndex];
  v9 = *(_DWORD *)(v7 + 4);
  v10 = *(_DWORD *)(v8 + 4);
  v11 = *(_DWORD *)v7;
  v12 = *(_DWORD *)v8;
  if ( v10 != v9 )
  {
    v13 = v10 - v12;
    v14 = v9 - v12 + 2 * (((_WORD)v9 - (_WORD)v12) & 0x8000);
    v15 = (signed __int16)v14 * ((signed int)(v10 - v12 + 2 * (((_WORD)v10 - (_WORD)v12) & 0x8000)) >> 16)
        - (signed __int16)(v10 - v12 + 2 * ((v10 - v12) & 0x8000)) * (v14 >> 16);
    if ( (signed __int16)v14 * ((signed int)(v10 - v12 + 2 * (((_WORD)v10 - (_WORD)v12) & 0x8000)) >> 16) != (signed __int16)(v10 - v12 + 2 * ((v10 - v12) & 0x8000)) * (v14 >> 16) )
    {
      v16 = v11 - v12 + 2 * (((_WORD)v11 - (_WORD)v12) & 0x8000);
      if ( (signed __int16)v16 * ((v13 + 2 * (v13 & 0x8000)) >> 16) == (signed __int16)(v13 + 2 * (v13 & 0x8000))
                                                                     * (v16 >> 16)
        || (v15 ^ ((signed __int16)v16 * ((v13 + 2 * (v13 & 0x8000)) >> 16)
                 - (signed __int16)(v13 + 2 * (v13 & 0x8000)) * (v16 >> 16))) < 0 )
      {
        v17 = v10 - v11 + 2 * (((_WORD)v10 - (_WORD)v11) & 0x8000);
        v18 = (signed __int16)v17 * ((signed int)(v9 - v11 + 2 * (((_WORD)v9 - (_WORD)v11) & 0x8000)) >> 16)
            - (signed __int16)(v9 - v11 + 2 * ((v9 - v11) & 0x8000)) * (v17 >> 16);
        if ( (signed __int16)v17 * ((signed int)(v9 - v11 + 2 * (((_WORD)v9 - (_WORD)v11) & 0x8000)) >> 16) != (signed __int16)(v9 - v11 + 2 * ((v9 - v11) & 0x8000)) * (v17 >> 16) )
        {
          v19 = v12 - v11 + 2 * (((_WORD)v12 - (_WORD)v11) & 0x8000);
          v20 = (signed __int16)v19 * ((signed int)(v9 - v11 + 2 * (((_WORD)v9 - (_WORD)v11) & 0x8000)) >> 16)
              - (signed __int16)(v9 - v11 + 2 * ((v9 - v11) & 0x8000)) * (v19 >> 16);
          if ( (signed __int16)v19 * ((signed int)(v9 - v11 + 2 * (((_WORD)v9 - (_WORD)v11) & 0x8000)) >> 16) == (signed __int16)(v9 - v11 + 2 * ((v9 - v11) & 0x8000)) * (v19 >> 16)
            || (v18 ^ v20) < 0 )
          {
            v21 = v12 >> 16;
            v22 = v20 - v18;
            v9 = ((unsigned __int16)v12
                + (unsigned int)((signed __int64)(v20 * (signed __int64)((unsigned __int16)v10 - (unsigned __int16)v12)
                                                - ((v22 - (((v20 - v18) >> 31) | 1)) & (unsigned __int64)((signed __int64)(v20 ^ ((unsigned __int16)v10 - (unsigned __int16)v12) ^ (unsigned __int64)v22) >> 31)))
                               / v22)) | ((v21
                                         + (unsigned int)((signed __int64)((signed int)((v10 >> 16) - v21)
                                                                         * (signed __int64)v20
                                                                         - ((v20 - v18 - (((v20 - v18) >> 31) | 1)) & (unsigned __int64)((signed __int64)((signed int)((v10 >> 16) - v21) ^ v20 ^ (unsigned __int64)(v20 - v18)) >> 31)))
                                                        / v22)) << 16);
LABEL_18:
            hkaiNewFaceCutterUtil::enqueueIntersectionEvent(statea, v6, v5, (hkaiNewFaceCutterUtil::Vec2)v9);
            return;
          }
        }
      }
    }
  }
  if ( *(_WORD *)(v8 + 14) < 0xFF00u )
  {
    if ( *(_WORD *)(v7 + 14) >= 0xFF00u )
    {
      v24 = v9 - v12 + 2 * (((_WORD)v9 - (_WORD)v12) & 0x8000);
      if ( (signed __int16)v24 * ((signed int)(v10 - v12 + 2 * (((_WORD)v10 - (_WORD)v12) & 0x8000)) >> 16) == (signed __int16)(v10 - v12 + 2 * ((v10 - v12) & 0x8000)) * (v24 >> 16)
        && v12 < v9
        && v9 < v10 )
      {
        goto LABEL_18;
      }
    }
  }
  else
  {
    v23 = v10 - v11 + 2 * (((_WORD)v10 - (_WORD)v11) & 0x8000);
    if ( (signed __int16)v23 * ((signed int)(v9 - v11 + 2 * (((_WORD)v9 - (_WORD)v11) & 0x8000)) >> 16) == (signed __int16)(v9 - v11 + 2 * ((v9 - v11) & 0x8000)) * (v23 >> 16)
      && v11 < v10
      && v10 < v9 )
    {
      v9 = *(_DWORD *)(v8 + 4);
      goto LABEL_18;
    }
  }
}

// File Line: 820
// RVA: 0x12F7F30
void __fastcall hkaiNewFaceCutterUtil::Step::addIntersectionEvents(hkaiNewFaceCutterUtil::State *state, __int16 lowerBoundIndex, __int16 upperBoundIndex, hkaiNewFaceCutterUtil::Vec2 curEventPos)
{
  __int16 v4; // di
  __int16 v5; // r10
  hkaiNewFaceCutterUtil::State *v6; // rbx
  hkaiNewFaceCutterUtil::Segment *v7; // r8
  hkaiNewFaceCutterUtil::Segment *v8; // rdx
  __int16 v9; // dx
  hkaiNewFaceCutterUtil::Vec2 curEventPosa; // [rsp+48h] [rbp+20h]

  curEventPosa.m_xy = curEventPos.m_xy;
  v4 = upperBoundIndex;
  v5 = lowerBoundIndex;
  v6 = state;
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
    if ( v4 != -1 )
    {
      v9 = v6->m_outgoingSegments.m_data[v6->m_outgoingSegments.m_size - 1];
      goto LABEL_10;
    }
  }
  else if ( lowerBoundIndex != -1 && upperBoundIndex != -1 )
  {
    v7 = state->m_segments.m_data;
    v8 = &v7[lowerBoundIndex];
    LODWORD(v7) = v7[v4].m_b.m_xy - v7[v4].m_a.m_xy + 2 * ((LOWORD(v7[v4].m_b.m_xy) - LOWORD(v7[v4].m_a.m_xy)) & 0x8000);
    LODWORD(v8) = v8->m_b.m_xy - v8->m_a.m_xy + 2 * ((LOWORD(v8->m_b.m_xy) - LOWORD(v8->m_a.m_xy)) & 0x8000);
    if ( (signed __int16)v7 * ((signed int)v8 >> 16) < (signed __int16)v8 * ((signed int)v7 >> 16) )
    {
      v9 = v5;
LABEL_10:
      hkaiNewFaceCutterUtil::Step::addIntersectionEvent(v6, v9, v4, curEventPos);
      return;
    }
  }
}

// File Line: 854
// RVA: 0x12F7270
void __fastcall hkaiNewFaceCutterUtil::step(hkaiNewFaceCutterUtil::State *state)
{
  hkaiNewFaceCutterUtil::State *v1; // rdi
  hkaiNewFaceCutterUtil::Vec2 v2; // ebx
  __int16 v3; // si
  __int64 v4; // rax
  __int16 upperBoundIndexOut; // [rsp+30h] [rbp-28h]
  bool equalSlopeFoundOut; // [rsp+60h] [rbp+8h]
  __int16 lowerBoundIndexOut; // [rsp+68h] [rbp+10h]
  __int16 bottomRegionIndexOut; // [rsp+70h] [rbp+18h]
  __int16 topRegionIndex; // [rsp+78h] [rbp+20h]

  v1 = state;
  hkaiNewFaceCutterUtil::Step::popInvalidEvents(state);
  if ( v1->m_eventQueue.m_heap.m_size != 1 )
  {
    v2.m_xy = v1->m_eventQueue.m_heap.m_data[1].m_posAndType >> 2;
    hkaiNewFaceCutterUtil::checkState(v1, v2);
    hkaiNewFaceCutterUtil::Step::gatherSegmentsForEvent(v1, v2, &lowerBoundIndexOut, &upperBoundIndexOut);
    v3 = lowerBoundIndexOut;
    hkaiNewFaceCutterUtil::Step::getBoundingRegions(
      v1,
      lowerBoundIndexOut,
      upperBoundIndexOut,
      &bottomRegionIndexOut,
      &topRegionIndex);
    hkaiNewFaceCutterUtil::Step::growRegions(v1, bottomRegionIndexOut, v2);
    LOBYTE(lowerBoundIndexOut) = 0;
    equalSlopeFoundOut = 0;
    hkaiNewFaceCutterUtil::Step::resolveRegionJoinOrSplit(
      v1,
      &bottomRegionIndexOut,
      &topRegionIndex,
      v2,
      (bool *)&lowerBoundIndexOut,
      &equalSlopeFoundOut);
    if ( !(_BYTE)lowerBoundIndexOut )
    {
      hkaiNewFaceCutterUtil::Step::setOutgoingSegmentStartPoints(v1, v2);
      hkaiNewFaceCutterUtil::Step::sortOutgoingSegmentsBySlope(v1, &equalSlopeFoundOut);
    }
    if ( equalSlopeFoundOut )
      hkaiNewFaceCutterUtil::Step::mergeEqualSlopeOutgoingSegments(v1);
    hkaiNewFaceCutterUtil::Step::resolveOuterReflexVertices(v1, &topRegionIndex, &bottomRegionIndexOut, v2);
    v4 = v1->m_outgoingSegments.m_size;
    if ( (_DWORD)v4 )
      v1->m_segments.m_data[v1->m_outgoingSegments.m_data[v4 - 1]].m_aboveRegion = topRegionIndex;
    if ( v3 != -1 )
      v1->m_segments.m_data[v3].m_aboveRegion = bottomRegionIndexOut;
    hkaiNewFaceCutterUtil::Step::updateOutgoingSegmentData(v1, v3, upperBoundIndexOut);
    hkaiNewFaceCutterUtil::Step::addIntersectionEvents(v1, v3, upperBoundIndexOut, v2);
  }
}


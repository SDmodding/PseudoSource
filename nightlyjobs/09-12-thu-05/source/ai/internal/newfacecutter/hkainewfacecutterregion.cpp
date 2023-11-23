// File Line: 18
// RVA: 0x12FA010
__int64 __fastcall hkaiNewFaceCutterUtil::makeNewRegion(
        hkaiNewFaceCutterUtil::State *state,
        hkaiNewFaceCutterUtil::Vec2 leftmostPoint,
        char painterIndex)
{
  __int16 v5; // di
  __int16 m_size; // bp
  hkArray<hkaiNewFaceCutterUtil::RegionEdge,hkContainerHeapAllocator> *p_m_regionEdges; // rsi
  hkArray<hkaiNewFaceCutterUtil::Region,hkContainerHeapAllocator> *p_m_regions; // rbx
  __int64 v9; // rdx
  unsigned __int16 v10; // di
  __int64 v11; // rdx
  hkaiNewFaceCutterUtil::Region *m_data; // rcx
  __int64 result; // rax

  if ( state->m_outputVertices.m_size
    && state->m_outputVertices.m_data[state->m_outputVertices.m_size - 1].m_xy == leftmostPoint.m_xy )
  {
    v5 = LOWORD(state->m_outputVertices.m_size) - 1;
  }
  else
  {
    v5 = hkaiNewFaceCutterUtil::State::_addOutputVertex(state, leftmostPoint);
  }
  m_size = state->m_regionEdges.m_size;
  p_m_regionEdges = &state->m_regionEdges;
  if ( state->m_regionEdges.m_size == (state->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&state->m_regionEdges.m_data, 8);
  ++state->m_regionEdges.m_size;
  p_m_regions = &state->m_regions;
  v9 = (__int64)&p_m_regionEdges->m_data[m_size];
  *(_WORD *)(v9 + 2) = -1;
  *(_WORD *)v9 = v5;
  *(_DWORD *)(v9 + 4) = *(_DWORD *)(v9 + 4) & 0xFFFF0000 | 3;
  v10 = p_m_regions->m_size;
  if ( p_m_regions->m_size == (p_m_regions->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_regions->m_data, 6);
  ++p_m_regions->m_size;
  v11 = (__int16)v10;
  m_data = p_m_regions->m_data;
  result = v10;
  m_data[v11].m_head = m_size;
  m_data[v11].m_tail = m_size;
  m_data[v11].m_painterIndex = painterIndex;
  return result;
}

// File Line: 36
// RVA: 0x12FA130
__int64 __fastcall hkaiNewFaceCutterUtil::splitRegionAtNewTopEdge(
        hkaiNewFaceCutterUtil::State *state,
        __int16 regionAIndex,
        hkaiNewFaceCutterUtil::Vec2 p)
{
  __int16 m_size; // r15
  hkArray<hkaiNewFaceCutterUtil::RegionEdge,hkContainerHeapAllocator> *p_m_regionEdges; // rdi
  int v7; // r9d
  int v8; // eax
  int v9; // eax
  hkArray<hkaiNewFaceCutterUtil::Region,hkContainerHeapAllocator> *p_m_regions; // rsi
  __int16 v11; // bp
  __int16 v12; // r14
  bool v13; // zf
  __int64 v14; // r13
  hkaiNewFaceCutterUtil::RegionEdge *m_data; // rcx
  hkaiNewFaceCutterUtil::RegionEdge *v16; // rdi
  hkaiNewFaceCutterUtil::RegionEdge *v17; // r12
  __int64 v18; // rdx
  __int16 v19; // cx
  __int16 v20; // ax
  __int16 m_enum; // ax
  __int16 m_outputVertexIndex; // ax
  __int64 v23; // rax
  __int64 v24; // r8
  hkaiNewFaceCutterUtil::RegionEdge *v25; // [rsp+30h] [rbp-58h]
  __int16 v26; // [rsp+90h] [rbp+8h]
  hkResult result; // [rsp+98h] [rbp+10h] BYREF
  unsigned int m_xy; // [rsp+A0h] [rbp+18h]
  __int64 v29; // [rsp+A8h] [rbp+20h]

  m_xy = p.m_xy;
  m_size = state->m_regionEdges.m_size;
  p_m_regionEdges = &state->m_regionEdges;
  v7 = state->m_regionEdges.m_size + 3;
  v8 = state->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v7 )
  {
    v9 = 2 * v8;
    if ( v7 < v9 )
      v7 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_regionEdges->m_data, v7, 8);
    p.m_xy = m_xy;
  }
  p_m_regionEdges->m_size += 3;
  p_m_regions = &state->m_regions;
  v26 = state->m_regions.m_size;
  v11 = m_size + 1;
  v12 = m_size + 2;
  if ( state->m_regions.m_size == (state->m_regions.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&state->m_regions.m_data, 6);
    p.m_xy = m_xy;
  }
  ++state->m_regions.m_size;
  v13 = state->m_outputVertices.m_size == 0;
  v14 = (__int64)&p_m_regions->m_data[regionAIndex];
  m_data = p_m_regionEdges->m_data;
  LOWORD(result.m_enum) = *(_WORD *)v14;
  v25 = &m_data[SLOWORD(result.m_enum)];
  v16 = &m_data[m_size];
  v17 = &m_data[v11];
  v18 = (__int64)&m_data[v12];
  v29 = v18;
  if ( v13 || state->m_outputVertices.m_data[state->m_outputVertices.m_size - 1].m_xy != p.m_xy )
  {
    v20 = hkaiNewFaceCutterUtil::State::_addOutputVertex(state, p);
    v18 = v29;
    v19 = v20;
  }
  else
  {
    v19 = LOWORD(state->m_outputVertices.m_size) - 1;
  }
  m_enum = result.m_enum;
  v16->m_outputVertexIndex = v19;
  v16->m_next = m_enum;
  *(_DWORD *)&v16->m_connectivity &= 0xFFFF0002;
  *(_DWORD *)&v16->m_connectivity |= (4 * (v11 & 0x3FFF)) | 2;
  m_outputVertexIndex = v25->m_outputVertexIndex;
  v17->m_next = v12;
  v17->m_outputVertexIndex = m_outputVertexIndex;
  *(_DWORD *)&v17->m_connectivity &= 0xFFFF0002;
  *(_DWORD *)&v17->m_connectivity |= (4 * (m_size & 0x3FFF)) | 2;
  *(_WORD *)v18 = v19;
  *(_WORD *)(v18 + 2) = -1;
  v23 = v26;
  *(_DWORD *)(v18 + 4) = *(_DWORD *)(v18 + 4) & 0xFFFF0000 | 3;
  *(_WORD *)v14 = m_size;
  v24 = (__int64)&p_m_regions->m_data[v26];
  *(_WORD *)v24 = v11;
  *(_WORD *)(v24 + 2) = v12;
  *(_BYTE *)(v24 + 4) = *(_BYTE *)(v14 + 4);
  return v23;
}

// File Line: 92
// RVA: 0x12FA330
__int64 __fastcall hkaiNewFaceCutterUtil::splitRegionAtNewBottomEdge(
        hkaiNewFaceCutterUtil::State *state,
        __int16 regionAIndex,
        hkaiNewFaceCutterUtil::Vec2 p)
{
  __int16 m_size; // r15
  hkArray<hkaiNewFaceCutterUtil::RegionEdge,hkContainerHeapAllocator> *p_m_regionEdges; // rdi
  int v7; // r9d
  int v8; // eax
  int v9; // eax
  hkArray<hkaiNewFaceCutterUtil::Region,hkContainerHeapAllocator> *p_m_regions; // rsi
  __int16 v11; // bp
  __int16 v12; // r14
  bool v13; // zf
  __int64 v14; // r13
  hkaiNewFaceCutterUtil::RegionEdge *m_data; // rcx
  hkaiNewFaceCutterUtil::RegionEdge *v16; // rdi
  __int64 v17; // rdx
  hkaiNewFaceCutterUtil::RegionEdge *v18; // r9
  hkaiNewFaceCutterUtil::RegionEdge *v19; // r12
  __int16 v20; // cx
  __int16 v21; // ax
  __int16 m_outputVertexIndex; // ax
  __int64 v23; // rax
  __int16 m_enum; // cx
  __int64 v25; // r8
  hkaiNewFaceCutterUtil::RegionEdge *v26; // [rsp+30h] [rbp-58h]
  __int16 v27; // [rsp+90h] [rbp+8h]
  hkResult result; // [rsp+98h] [rbp+10h] BYREF
  unsigned int m_xy; // [rsp+A0h] [rbp+18h]
  __int64 v30; // [rsp+A8h] [rbp+20h]

  m_xy = p.m_xy;
  m_size = state->m_regionEdges.m_size;
  p_m_regionEdges = &state->m_regionEdges;
  v7 = state->m_regionEdges.m_size + 3;
  v8 = state->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v7 )
  {
    v9 = 2 * v8;
    if ( v7 < v9 )
      v7 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_regionEdges->m_data, v7, 8);
    p.m_xy = m_xy;
  }
  p_m_regionEdges->m_size += 3;
  p_m_regions = &state->m_regions;
  v27 = state->m_regions.m_size;
  v11 = m_size + 1;
  v12 = m_size + 2;
  if ( state->m_regions.m_size == (state->m_regions.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&state->m_regions.m_data, 6);
    p.m_xy = m_xy;
  }
  ++state->m_regions.m_size;
  v13 = state->m_outputVertices.m_size == 0;
  v14 = (__int64)&p_m_regions->m_data[regionAIndex];
  m_data = p_m_regionEdges->m_data;
  LOWORD(result.m_enum) = *(_WORD *)(v14 + 2);
  v16 = &m_data[SLOWORD(result.m_enum)];
  v17 = (__int64)&m_data[m_size];
  v18 = &m_data[v11];
  v30 = v17;
  v26 = v18;
  v19 = &m_data[v12];
  if ( v13 || state->m_outputVertices.m_data[state->m_outputVertices.m_size - 1].m_xy != p.m_xy )
  {
    v21 = hkaiNewFaceCutterUtil::State::_addOutputVertex(state, p);
    v17 = v30;
    v18 = v26;
    v20 = v21;
  }
  else
  {
    v20 = LOWORD(state->m_outputVertices.m_size) - 1;
  }
  v16->m_next = m_size;
  *(_DWORD *)&v16->m_connectivity &= 0xFFFF0002;
  *(_DWORD *)&v16->m_connectivity |= (4 * (v12 & 0x3FFF)) | 2;
  *(_WORD *)v17 = v20;
  *(_WORD *)(v17 + 2) = -1;
  *(_DWORD *)(v17 + 4) = *(_DWORD *)(v17 + 4) & 0xFFFF0000 | 3;
  m_outputVertexIndex = v16->m_outputVertexIndex;
  v18->m_next = -1;
  v18->m_outputVertexIndex = m_outputVertexIndex;
  v18->m_connectivity = (hkaiNewFaceCutterUtil::RegionEdgeConnectivity)(*(_DWORD *)&v18->m_connectivity & 0xFFFF0000 | 3);
  v23 = v27;
  v19->m_outputVertexIndex = v20;
  m_enum = result.m_enum;
  v19->m_next = v11;
  *(_DWORD *)&v19->m_connectivity &= 0xFFFF0002;
  *(_DWORD *)&v19->m_connectivity |= (4 * (m_enum & 0x3FFF)) | 2;
  *(_WORD *)(v14 + 2) = m_size;
  v25 = (__int64)&p_m_regions->m_data[v27];
  *(_WORD *)v25 = v12;
  *(_WORD *)(v25 + 2) = v11;
  *(_BYTE *)(v25 + 4) = *(_BYTE *)(v14 + 4);
  return v23;
}

// File Line: 151
// RVA: 0x12FA540
void __fastcall hkaiNewFaceCutterUtil::splitRegionAtBothEdges(
        hkaiNewFaceCutterUtil::State *state,
        __int16 regionAIndex,
        hkaiNewFaceCutterUtil::Vec2 p,
        __int16 *bottomRegionIndexOut,
        __int16 *topRegionIndexOut)
{
  __int16 m_size; // bp
  hkArray<hkaiNewFaceCutterUtil::RegionEdge,hkContainerHeapAllocator> *p_m_regionEdges; // rsi
  int v8; // r9d
  int v9; // eax
  int v10; // eax
  hkArray<hkaiNewFaceCutterUtil::Region,hkContainerHeapAllocator> *p_m_regions; // rbx
  __int16 v12; // r14
  __int16 v13; // r15
  __int16 v14; // r12
  __int16 v15; // r13
  bool v16; // zf
  hkaiNewFaceCutterUtil::Region *v17; // r8
  hkaiNewFaceCutterUtil::RegionEdge *m_data; // rcx
  __int64 m_head; // rax
  hkaiNewFaceCutterUtil::RegionEdge *v20; // rsi
  hkaiNewFaceCutterUtil::RegionEdge *v21; // r9
  hkaiNewFaceCutterUtil::RegionEdge *v22; // r10
  hkaiNewFaceCutterUtil::RegionEdge *v23; // r11
  __int16 v24; // dx
  __int16 v25; // ax
  __int16 v26; // ax
  __int16 m_enum; // ax
  __int16 m_outputVertexIndex; // ax
  __int64 v29; // rdx
  hkaiNewFaceCutterUtil::Region *v30; // rax
  hkaiNewFaceCutterUtil::Region *v31; // rdx
  __int16 v32; // [rsp+30h] [rbp-88h]
  __int16 v33; // [rsp+32h] [rbp-86h]
  hkaiNewFaceCutterUtil::RegionEdge *v34; // [rsp+38h] [rbp-80h]
  hkaiNewFaceCutterUtil::RegionEdge *v35; // [rsp+40h] [rbp-78h]
  hkaiNewFaceCutterUtil::RegionEdge *v36; // [rsp+48h] [rbp-70h]
  hkaiNewFaceCutterUtil::Region *v37; // [rsp+50h] [rbp-68h]
  hkaiNewFaceCutterUtil::RegionEdge *v38; // [rsp+58h] [rbp-60h]
  hkaiNewFaceCutterUtil::RegionEdge *v39; // [rsp+60h] [rbp-58h]
  hkaiNewFaceCutterUtil::RegionEdge *v40; // [rsp+68h] [rbp-50h]
  hkResult result; // [rsp+C0h] [rbp+8h] BYREF
  __int16 v42; // [rsp+C8h] [rbp+10h]
  hkaiNewFaceCutterUtil::Vec2 v; // [rsp+D0h] [rbp+18h]
  __int16 *v44; // [rsp+D8h] [rbp+20h]

  v44 = bottomRegionIndexOut;
  v.m_xy = p.m_xy;
  v42 = regionAIndex;
  m_size = state->m_regionEdges.m_size;
  p_m_regionEdges = &state->m_regionEdges;
  v8 = state->m_regionEdges.m_size + 5;
  v9 = state->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < v8 )
  {
    v10 = 2 * v9;
    if ( v8 < v10 )
      v8 = v10;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_regionEdges->m_data, v8, 8);
  }
  p_m_regionEdges->m_size += 5;
  p_m_regions = &state->m_regions;
  v32 = state->m_regions.m_size;
  v12 = m_size + 1;
  v13 = m_size + 2;
  v14 = m_size + 3;
  v15 = m_size + 4;
  if ( state->m_regions.m_size == (state->m_regions.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&state->m_regions.m_data, 6);
  ++state->m_regions.m_size;
  v33 = state->m_regions.m_size;
  if ( state->m_regions.m_size == (state->m_regions.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&state->m_regions.m_data, 6);
  ++state->m_regions.m_size;
  v16 = state->m_outputVertices.m_size == 0;
  v17 = &p_m_regions->m_data[v42];
  m_data = p_m_regionEdges->m_data;
  m_head = v17->m_head;
  LOWORD(result.m_enum) = v17->m_tail;
  v20 = &m_data[SLOWORD(result.m_enum)];
  v42 = m_head;
  v37 = v17;
  v38 = &m_data[m_head];
  v21 = &m_data[m_size];
  v39 = v21;
  v22 = &m_data[v13];
  v36 = &m_data[v12];
  v23 = &m_data[v14];
  v34 = v22;
  v35 = v23;
  v40 = &m_data[v15];
  if ( v16 || state->m_outputVertices.m_data[state->m_outputVertices.m_size - 1].m_xy != v.m_xy )
  {
    v25 = hkaiNewFaceCutterUtil::State::_addOutputVertex(state, v);
    v17 = v37;
    v21 = v39;
    v22 = v34;
    v23 = v35;
    v24 = v25;
  }
  else
  {
    v24 = LOWORD(state->m_outputVertices.m_size) - 1;
  }
  v20->m_next = m_size;
  *(_DWORD *)&v20->m_connectivity &= 0xFFFF0002;
  v26 = v42;
  *(_DWORD *)&v20->m_connectivity |= (4 * (v13 & 0x3FFF)) | 2;
  v21->m_next = v26;
  v21->m_outputVertexIndex = v24;
  *(_DWORD *)&v21->m_connectivity &= 0xFFFF0002;
  *(_DWORD *)&v21->m_connectivity |= (4 * (v14 & 0x3FFF)) | 2;
  v36->m_outputVertexIndex = v20->m_outputVertexIndex;
  v36->m_next = -1;
  v36->m_connectivity = (hkaiNewFaceCutterUtil::RegionEdgeConnectivity)(*(_DWORD *)&v36->m_connectivity & 0xFFFF0000 | 3);
  m_enum = result.m_enum;
  v22->m_outputVertexIndex = v24;
  v22->m_next = v12;
  *(_DWORD *)&v22->m_connectivity &= 0xFFFF0002;
  *(_DWORD *)&v22->m_connectivity |= (4 * (m_enum & 0x3FFF)) | 2;
  m_outputVertexIndex = v38->m_outputVertexIndex;
  v23->m_next = v15;
  v23->m_outputVertexIndex = m_outputVertexIndex;
  *(_DWORD *)&v23->m_connectivity &= 0xFFFF0002;
  *(_DWORD *)&v23->m_connectivity |= (4 * (m_size & 0x3FFF)) | 2;
  v40->m_outputVertexIndex = v24;
  v40->m_next = -1;
  v40->m_connectivity = (hkaiNewFaceCutterUtil::RegionEdgeConnectivity)(*(_DWORD *)&v40->m_connectivity & 0xFFFF0000 | 3);
  v17->m_tail = m_size;
  v17->m_head = m_size;
  v29 = (__int64)&p_m_regions->m_data[v32];
  *(_WORD *)v29 = v13;
  *(_WORD *)(v29 + 2) = v12;
  *(_BYTE *)(v29 + 4) = v17->m_painterIndex;
  v30 = p_m_regions->m_data;
  v30[v33].m_head = v14;
  v31 = &v30[v33];
  v31->m_tail = v15;
  v31->m_painterIndex = v17->m_painterIndex;
  *v44 = v32;
  *topRegionIndexOut = v33;
}

// File Line: 240
// RVA: 0x12FA860
void __fastcall hkaiNewFaceCutterUtil::closeRegionAt(
        hkaiNewFaceCutterUtil::State *state,
        hkaiNewFaceCutterUtil::Region *region,
        hkaiNewFaceCutterUtil::Vec2 eventPos,
        hkaiNewFaceCutterUtil::RegionEdgeConnectivity belowConnectivity,
        hkaiNewFaceCutterUtil::RegionEdgeConnectivity aboveConnectivity,
        __int16 *bottomEdgeIndexOut,
        __int16 *topEdgeIndexOut)
{
  hkArray<hkaiNewFaceCutterUtil::RegionEdge,hkContainerHeapAllocator> *p_m_regionEdges; // r15
  int v9; // r9d
  int v11; // eax
  int v12; // eax
  __int16 v13; // si
  __int64 m_head; // rbp
  __int64 m_tail; // r14
  __int64 v16; // rbx
  __int16 *v17; // rax
  __int16 *v18; // rax
  __int16 m_size; // di
  hkaiNewFaceCutterUtil::RegionEdge *m_data; // rax
  hkaiNewFaceCutterUtil::RegionEdge *v21; // rdx
  __int16 *v22; // rax
  hkResult result; // [rsp+70h] [rbp+8h] BYREF
  unsigned int m_xy; // [rsp+80h] [rbp+18h]
  hkaiNewFaceCutterUtil::RegionEdgeConnectivity v25; // [rsp+88h] [rbp+20h]

  v25 = belowConnectivity;
  m_xy = eventPos.m_xy;
  p_m_regionEdges = &state->m_regionEdges;
  v9 = state->m_regionEdges.m_size + 1;
  v11 = state->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < v9 )
  {
    v12 = 2 * v11;
    if ( v9 < v12 )
      v9 = v12;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_regionEdges->m_data, v9, 8);
    eventPos.m_xy = m_xy;
  }
  if ( state->m_outputVertices.m_size
    && state->m_outputVertices.m_data[state->m_outputVertices.m_size - 1].m_xy == eventPos.m_xy )
  {
    v13 = LOWORD(state->m_outputVertices.m_size) - 1;
  }
  else
  {
    v13 = hkaiNewFaceCutterUtil::State::_addOutputVertex(state, eventPos);
  }
  m_head = region->m_head;
  m_tail = region->m_tail;
  v16 = (__int64)&p_m_regionEdges->m_data[m_tail];
  if ( p_m_regionEdges->m_data[m_head].m_outputVertexIndex == v13 )
  {
    *(_WORD *)(v16 + 2) = m_head;
    *(hkaiNewFaceCutterUtil::RegionEdgeConnectivity *)(v16 + 4) = v25;
    v17 = bottomEdgeIndexOut;
    region->m_tail = m_head;
    *v17 = m_tail;
    *topEdgeIndexOut = -1;
  }
  else if ( *(_WORD *)v16 == v13 )
  {
    *(_WORD *)(v16 + 2) = m_head;
    *(hkaiNewFaceCutterUtil::RegionEdgeConnectivity *)(v16 + 4) = aboveConnectivity;
    v18 = bottomEdgeIndexOut;
    region->m_head = m_tail;
    *v18 = -1;
    *topEdgeIndexOut = m_tail;
  }
  else
  {
    m_size = state->m_regionEdges.m_size;
    if ( p_m_regionEdges->m_size == (p_m_regionEdges->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_regionEdges->m_data, 8);
    ++p_m_regionEdges->m_size;
    m_data = p_m_regionEdges->m_data;
    *(_WORD *)(v16 + 2) = m_size;
    v21 = &m_data[m_size];
    *(hkaiNewFaceCutterUtil::RegionEdgeConnectivity *)(v16 + 4) = v25;
    v21->m_outputVertexIndex = v13;
    v21->m_next = m_head;
    v21->m_connectivity = aboveConnectivity;
    v22 = bottomEdgeIndexOut;
    region->m_head = m_size;
    region->m_tail = m_size;
    *v22 = m_tail;
    *topEdgeIndexOut = m_size;
  }
}

// File Line: 288
// RVA: 0x12FAA30
__int64 __fastcall hkaiNewFaceCutterUtil::addTopEdgeToRegion(
        hkaiNewFaceCutterUtil::State *state,
        hkaiNewFaceCutterUtil::Region *belowRegion,
        hkaiNewFaceCutterUtil::Vec2 p,
        hkaiNewFaceCutterUtil::RegionEdgeConnectivity regionEdgeConnectivity)
{
  __int16 m_head; // bp
  __int16 v7; // si
  hkArray<hkaiNewFaceCutterUtil::RegionEdge,hkContainerHeapAllocator> *p_m_regionEdges; // rdi
  __int64 result; // rax
  __int16 m_size; // bx
  __int64 v11; // r8

  m_head = belowRegion->m_head;
  if ( state->m_outputVertices.m_size
    && state->m_outputVertices.m_data[state->m_outputVertices.m_size - 1].m_xy == p.m_xy )
  {
    v7 = LOWORD(state->m_outputVertices.m_size) - 1;
  }
  else
  {
    v7 = hkaiNewFaceCutterUtil::State::_addOutputVertex(state, p);
  }
  p_m_regionEdges = &state->m_regionEdges;
  if ( state->m_regionEdges.m_data[m_head].m_outputVertexIndex == v7 )
    return 0xFFFFFFFFi64;
  m_size = state->m_regionEdges.m_size;
  if ( p_m_regionEdges->m_size == (p_m_regionEdges->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_regionEdges->m_data, 8);
  ++p_m_regionEdges->m_size;
  v11 = (__int64)&p_m_regionEdges->m_data[m_size];
  result = (unsigned __int16)m_size;
  *(_WORD *)v11 = v7;
  *(_WORD *)(v11 + 2) = m_head;
  *(hkaiNewFaceCutterUtil::RegionEdgeConnectivity *)(v11 + 4) = regionEdgeConnectivity;
  belowRegion->m_head = m_size;
  return result;
}

// File Line: 310
// RVA: 0x12FAB10
__int64 __fastcall hkaiNewFaceCutterUtil::addBottomEdgeToRegion(
        hkaiNewFaceCutterUtil::State *state,
        hkaiNewFaceCutterUtil::Region *aboveRegion,
        hkaiNewFaceCutterUtil::Vec2 p,
        hkaiNewFaceCutterUtil::RegionEdgeConnectivity regionEdgeConnectivity)
{
  hkArray<hkaiNewFaceCutterUtil::RegionEdge,hkContainerHeapAllocator> *p_m_regionEdges; // rbx
  int v6; // r9d
  int v8; // eax
  int v9; // eax
  __int64 m_tail; // r14
  __int64 v11; // rbp
  __int16 v12; // si
  __int64 v13; // rax
  __int16 m_size; // di
  hkaiNewFaceCutterUtil::RegionEdge *m_data; // rax
  hkaiNewFaceCutterUtil::RegionEdge *v16; // rdx
  hkResult result; // [rsp+60h] [rbp+8h] BYREF
  unsigned int m_xy; // [rsp+70h] [rbp+18h]
  hkaiNewFaceCutterUtil::RegionEdgeConnectivity v19; // [rsp+78h] [rbp+20h]

  v19 = regionEdgeConnectivity;
  m_xy = p.m_xy;
  p_m_regionEdges = &state->m_regionEdges;
  v6 = state->m_regionEdges.m_size + 1;
  v8 = state->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v6 )
  {
    v9 = 2 * v8;
    if ( v6 < v9 )
      v6 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_regionEdges->m_data, v6, 8);
    p.m_xy = m_xy;
  }
  m_tail = aboveRegion->m_tail;
  v11 = (__int64)&p_m_regionEdges->m_data[m_tail];
  if ( state->m_outputVertices.m_size
    && state->m_outputVertices.m_data[state->m_outputVertices.m_size - 1].m_xy == p.m_xy )
  {
    v12 = LOWORD(state->m_outputVertices.m_size) - 1;
  }
  else
  {
    v12 = hkaiNewFaceCutterUtil::State::_addOutputVertex(state, p);
  }
  if ( *(_WORD *)v11 == v12 )
    return 0xFFFFFFFFi64;
  m_size = state->m_regionEdges.m_size;
  if ( p_m_regionEdges->m_size == (p_m_regionEdges->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_regionEdges->m_data, 8);
  ++p_m_regionEdges->m_size;
  m_data = p_m_regionEdges->m_data;
  *(_WORD *)(v11 + 2) = m_size;
  v16 = &m_data[m_size];
  *(hkaiNewFaceCutterUtil::RegionEdgeConnectivity *)(v11 + 4) = v19;
  v16->m_next = -1;
  v16->m_outputVertexIndex = v12;
  v13 = (unsigned __int16)m_tail;
  v16->m_connectivity = (hkaiNewFaceCutterUtil::RegionEdgeConnectivity)(*(_DWORD *)&v16->m_connectivity & 0xFFFF0000 | 3);
  aboveRegion->m_tail = m_size;
  return v13;
}

// File Line: 337
// RVA: 0x12FAC60
void __fastcall hkaiNewFaceCutterUtil::splitRegionAtTopMouth(
        hkaiNewFaceCutterUtil::State *state,
        __int16 *topRegionIndex)
{
  __int16 m_size; // r14
  hkArray<hkaiNewFaceCutterUtil::RegionEdge,hkContainerHeapAllocator> *p_m_regionEdges; // rsi
  int v6; // r9d
  int v7; // eax
  int v8; // eax
  __int16 v9; // r15
  hkArray<hkaiNewFaceCutterUtil::Region,hkContainerHeapAllocator> *p_m_regions; // rbx
  __int16 v11; // bp
  __int64 m_tail; // r10
  __int64 m_head; // r8
  __int64 v14; // rdi
  __int64 v15; // rbx
  hkaiNewFaceCutterUtil::RegionEdge *m_data; // rcx
  hkaiNewFaceCutterUtil::RegionEdge *v17; // r9
  hkaiNewFaceCutterUtil::RegionEdge *v18; // r11
  hkaiNewFaceCutterUtil::RegionEdge *v19; // rdx
  hkaiNewFaceCutterUtil::RegionEdge *v20; // rcx
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  m_size = state->m_regionEdges.m_size;
  p_m_regionEdges = &state->m_regionEdges;
  v6 = state->m_regionEdges.m_size + 2;
  v7 = state->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v6 )
  {
    v8 = 2 * v7;
    if ( v6 < v8 )
      v6 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_regionEdges->m_data, v6, 8);
  }
  p_m_regionEdges->m_size += 2;
  v9 = state->m_regions.m_size;
  p_m_regions = &state->m_regions;
  v11 = m_size + 1;
  if ( p_m_regions->m_size == (p_m_regions->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_regions->m_data, 6);
  ++p_m_regions->m_size;
  m_tail = p_m_regions->m_data[*topRegionIndex].m_tail;
  m_head = p_m_regions->m_data[*topRegionIndex].m_head;
  v14 = (__int64)&p_m_regions->m_data[*topRegionIndex];
  v15 = (__int64)&p_m_regions->m_data[v9];
  m_data = p_m_regionEdges->m_data;
  *(_DWORD *)&m_data[m_tail].m_connectivity &= 0xFFFF0002;
  v17 = &m_data[m_size];
  v18 = &m_data[m_tail];
  v19 = &m_data[m_head];
  v20 = &m_data[v11];
  *(_DWORD *)&v18->m_connectivity |= (4 * (m_size & 0x3FFF)) | 2;
  v18->m_next = m_head;
  v17->m_outputVertexIndex = v19->m_outputVertexIndex;
  v17->m_next = v11;
  *(_DWORD *)&v17->m_connectivity &= 0xFFFF0002;
  *(_DWORD *)&v17->m_connectivity |= (4 * (m_tail & 0x3FFF)) | 2;
  v20->m_outputVertexIndex = v18->m_outputVertexIndex;
  v20->m_next = -1;
  v20->m_connectivity = (hkaiNewFaceCutterUtil::RegionEdgeConnectivity)(*(_DWORD *)&v20->m_connectivity & 0xFFFF0000 | 3);
  *(_WORD *)(v14 + 2) = *(_WORD *)v14;
  *(_WORD *)(v15 + 2) = v11;
  *(_WORD *)v15 = m_size;
  *(_BYTE *)(v15 + 4) = *(_BYTE *)(v14 + 4);
  *topRegionIndex = v9;
}

// File Line: 375
// RVA: 0x12FADE0
void __fastcall hkaiNewFaceCutterUtil::splitRegionAtBottomMouth(
        hkaiNewFaceCutterUtil::State *state,
        __int16 *bottomRegionIndex)
{
  __int16 m_size; // r14
  hkArray<hkaiNewFaceCutterUtil::RegionEdge,hkContainerHeapAllocator> *p_m_regionEdges; // rbx
  int v6; // r9d
  int v7; // eax
  int v8; // eax
  __int16 v9; // r15
  hkArray<hkaiNewFaceCutterUtil::Region,hkContainerHeapAllocator> *p_m_regions; // rdi
  __int16 v11; // bp
  __int64 m_tail; // r10
  hkaiNewFaceCutterUtil::Region *v13; // rsi
  __int64 v14; // rdi
  hkaiNewFaceCutterUtil::RegionEdge *m_data; // rcx
  __int64 m_head; // rdx
  hkaiNewFaceCutterUtil::RegionEdge *v17; // r11
  hkaiNewFaceCutterUtil::RegionEdge *v18; // rbx
  hkaiNewFaceCutterUtil::RegionEdge *v19; // r9
  __int16 m_outputVertexIndex; // ax
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  m_size = state->m_regionEdges.m_size;
  p_m_regionEdges = &state->m_regionEdges;
  v6 = state->m_regionEdges.m_size + 2;
  v7 = state->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v6 )
  {
    v8 = 2 * v7;
    if ( v6 < v8 )
      v6 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_regionEdges->m_data, v6, 8);
  }
  p_m_regionEdges->m_size += 2;
  v9 = state->m_regions.m_size;
  p_m_regions = &state->m_regions;
  v11 = m_size + 1;
  if ( p_m_regions->m_size == (p_m_regions->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_regions->m_data, 6);
  ++p_m_regions->m_size;
  m_tail = p_m_regions->m_data[*bottomRegionIndex].m_tail;
  v13 = &p_m_regions->m_data[*bottomRegionIndex];
  v14 = (__int64)&p_m_regions->m_data[v9];
  m_data = p_m_regionEdges->m_data;
  m_head = v13->m_head;
  m_data[m_tail].m_next = m_head;
  *(_DWORD *)&m_data[m_tail].m_connectivity &= 0xFFFF0002;
  v17 = &m_data[m_tail];
  v18 = &m_data[m_size];
  v19 = &m_data[v11];
  *(_DWORD *)&v17->m_connectivity |= (4 * (v11 & 0x3FFF)) | 2;
  m_outputVertexIndex = m_data[m_head].m_outputVertexIndex;
  v19->m_next = m_size;
  v19->m_outputVertexIndex = m_outputVertexIndex;
  *(_DWORD *)&v19->m_connectivity &= 0xFFFF0002;
  *(_DWORD *)&v19->m_connectivity |= (4 * (m_tail & 0x3FFF)) | 2;
  v18->m_outputVertexIndex = v17->m_outputVertexIndex;
  v18->m_next = -1;
  v18->m_connectivity = (hkaiNewFaceCutterUtil::RegionEdgeConnectivity)(*(_DWORD *)&v18->m_connectivity & 0xFFFF0000 | 3);
  v13->m_tail = v13->m_head;
  *(_WORD *)v14 = v11;
  *(_WORD *)(v14 + 2) = m_size;
  *(_BYTE *)(v14 + 4) = v13->m_painterIndex;
  *bottomRegionIndex = v9;
}

// File Line: 413
// RVA: 0x12F9FC0
void __fastcall hkaiNewFaceCutterUtil::shiftOutputVertexIndicesInRegionEdges(
        hkaiNewFaceCutterUtil::State *state,
        __int16 startIndex)
{
  int m_size; // r10d
  int i; // eax
  hkaiNewFaceCutterUtil::RegionEdge *m_data; // r8
  __int16 m_outputVertexIndex; // dx

  m_size = state->m_regionEdges.m_size;
  for ( i = 0; i < m_size; ++i )
  {
    m_data = state->m_regionEdges.m_data;
    m_outputVertexIndex = m_data[(__int16)i].m_outputVertexIndex;
    if ( m_outputVertexIndex >= startIndex )
      m_data[(__int16)i].m_outputVertexIndex = m_outputVertexIndex + 1;
  }
}


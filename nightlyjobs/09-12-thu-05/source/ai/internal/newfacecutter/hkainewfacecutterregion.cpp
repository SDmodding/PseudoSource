// File Line: 18
// RVA: 0x12FA010
__int64 __fastcall hkaiNewFaceCutterUtil::makeNewRegion(hkaiNewFaceCutterUtil::State *state, hkaiNewFaceCutterUtil::Vec2 leftmostPoint, char painterIndex)
{
  char v3; // r14
  hkaiNewFaceCutterUtil::State *v4; // rbx
  __int16 v5; // di
  __int16 v6; // bp
  hkArray<hkaiNewFaceCutterUtil::RegionEdge,hkContainerHeapAllocator> *v7; // rsi
  hkArray<hkaiNewFaceCutterUtil::Region,hkContainerHeapAllocator> *v8; // rbx
  signed __int64 v9; // rdx
  unsigned __int16 v10; // di
  signed __int64 v11; // rdx
  hkaiNewFaceCutterUtil::Region *v12; // rcx
  __int64 result; // rax

  v3 = painterIndex;
  v4 = state;
  if ( state->m_outputVertices.m_size
    && state->m_outputVertices.m_data[state->m_outputVertices.m_size - 1].m_xy == leftmostPoint.m_xy )
  {
    v5 = LOWORD(state->m_outputVertices.m_size) - 1;
  }
  else
  {
    v5 = hkaiNewFaceCutterUtil::State::_addOutputVertex(state, leftmostPoint);
  }
  v6 = v4->m_regionEdges.m_size;
  v7 = &v4->m_regionEdges;
  if ( v4->m_regionEdges.m_size == (v4->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_regionEdges, 8);
  ++v4->m_regionEdges.m_size;
  v8 = &v4->m_regions;
  v9 = (signed __int64)&v7->m_data[v6];
  *(_WORD *)(v9 + 2) = -1;
  *(_WORD *)v9 = v5;
  *(_DWORD *)(v9 + 4) = *(_DWORD *)(v9 + 4) & 0xFFFF0003 | 3;
  v10 = v8->m_size;
  if ( v8->m_size == (v8->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, 6);
  ++v8->m_size;
  v11 = (signed __int16)v10;
  v12 = v8->m_data;
  result = v10;
  v12[v11].m_head = v6;
  v12[v11].m_tail = v6;
  v12[v11].m_painterIndex = v3;
  return result;
}

// File Line: 36
// RVA: 0x12FA130
__int64 __fastcall hkaiNewFaceCutterUtil::splitRegionAtNewTopEdge(hkaiNewFaceCutterUtil::State *state, __int16 regionAIndex, hkaiNewFaceCutterUtil::Vec2 p)
{
  __int16 v3; // r15
  hkArray<hkaiNewFaceCutterUtil::RegionEdge,hkContainerHeapAllocator> *v4; // rdi
  __int16 v5; // r12
  hkaiNewFaceCutterUtil::State *v6; // rbx
  int v7; // er9
  int v8; // eax
  int v9; // eax
  hkArray<hkaiNewFaceCutterUtil::Region,hkContainerHeapAllocator> *v10; // rsi
  __int16 v11; // bp
  __int16 v12; // r14
  bool v13; // zf
  signed __int64 v14; // r13
  hkaiNewFaceCutterUtil::RegionEdge *v15; // rcx
  signed __int64 v16; // rdi
  signed __int64 v17; // r12
  signed __int64 v18; // rdx
  __int16 v19; // cx
  __int16 v20; // ax
  __int16 v21; // ax
  __int16 v22; // ax
  __int64 v23; // rax
  signed __int64 v24; // r8
  hkaiNewFaceCutterUtil::RegionEdge *v25; // [rsp+30h] [rbp-58h]
  __int16 v26; // [rsp+90h] [rbp+8h]
  hkResult result; // [rsp+98h] [rbp+10h]
  unsigned int v28; // [rsp+A0h] [rbp+18h]
  hkaiNewFaceCutterUtil::RegionEdge *v29; // [rsp+A8h] [rbp+20h]

  v28 = p.m_xy;
  v3 = state->m_regionEdges.m_size;
  v4 = &state->m_regionEdges;
  v5 = regionAIndex;
  v6 = state;
  v7 = state->m_regionEdges.m_size + 3;
  v8 = state->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v7 )
  {
    v9 = 2 * v8;
    if ( v7 < v9 )
      v7 = v9;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v7, 8);
    p.m_xy = v28;
  }
  v4->m_size += 3;
  v10 = &v6->m_regions;
  v26 = v6->m_regions.m_size;
  v11 = v3 + 1;
  v12 = v3 + 2;
  if ( v6->m_regions.m_size == (v6->m_regions.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_regions, 6);
    p.m_xy = v28;
  }
  ++v6->m_regions.m_size;
  v13 = v6->m_outputVertices.m_size == 0;
  v14 = (signed __int64)&v10->m_data[v5];
  v15 = v4->m_data;
  LOWORD(result.m_enum) = *(_WORD *)v14;
  v25 = &v15[SLOWORD(result.m_enum)];
  v16 = (signed __int64)&v15[v3];
  v17 = (signed __int64)&v15[v11];
  v18 = (signed __int64)&v15[v12];
  v29 = &v15[v12];
  if ( v13 || v6->m_outputVertices.m_data[v6->m_outputVertices.m_size - 1].m_xy != p.m_xy )
  {
    v20 = hkaiNewFaceCutterUtil::State::_addOutputVertex(v6, p);
    v18 = (signed __int64)v29;
    v19 = v20;
  }
  else
  {
    v19 = LOWORD(v6->m_outputVertices.m_size) - 1;
  }
  v21 = result.m_enum;
  *(_WORD *)v16 = v19;
  *(_WORD *)(v16 + 2) = v21;
  *(_DWORD *)(v16 + 4) &= 0xFFFF0002;
  *(_DWORD *)(v16 + 4) |= 4 * (v11 & 0x3FFF) | 2;
  v22 = v25->m_outputVertexIndex;
  *(_WORD *)(v17 + 2) = v12;
  *(_WORD *)v17 = v22;
  *(_DWORD *)(v17 + 4) &= 0xFFFF0002;
  *(_DWORD *)(v17 + 4) |= 4 * (v3 & 0x3FFF) | 2;
  *(_WORD *)v18 = v19;
  *(_WORD *)(v18 + 2) = -1;
  v23 = v26;
  *(_DWORD *)(v18 + 4) = *(_DWORD *)(v18 + 4) & 0xFFFF0003 | 3;
  *(_WORD *)v14 = v3;
  v24 = (signed __int64)&v10->m_data[v26];
  *(_WORD *)v24 = v11;
  *(_WORD *)(v24 + 2) = v12;
  *(_BYTE *)(v24 + 4) = *(_BYTE *)(v14 + 4);
  return v23;
}

// File Line: 92
// RVA: 0x12FA330
__int64 __fastcall hkaiNewFaceCutterUtil::splitRegionAtNewBottomEdge(hkaiNewFaceCutterUtil::State *state, __int16 regionAIndex, hkaiNewFaceCutterUtil::Vec2 p)
{
  __int16 v3; // r15
  hkArray<hkaiNewFaceCutterUtil::RegionEdge,hkContainerHeapAllocator> *v4; // rdi
  __int16 v5; // r12
  hkaiNewFaceCutterUtil::State *v6; // rbx
  int v7; // er9
  int v8; // eax
  int v9; // eax
  hkArray<hkaiNewFaceCutterUtil::Region,hkContainerHeapAllocator> *v10; // rsi
  __int16 v11; // bp
  __int16 v12; // r14
  bool v13; // zf
  signed __int64 v14; // r13
  hkaiNewFaceCutterUtil::RegionEdge *v15; // rcx
  signed __int64 v16; // rdi
  signed __int64 v17; // rdx
  signed __int64 v18; // r9
  signed __int64 v19; // r12
  __int16 v20; // cx
  __int16 v21; // ax
  __int16 v22; // ax
  __int64 v23; // rax
  __int16 v24; // cx
  signed __int64 v25; // r8
  signed __int64 v26; // [rsp+30h] [rbp-58h]
  __int16 v27; // [rsp+90h] [rbp+8h]
  hkResult result; // [rsp+98h] [rbp+10h]
  unsigned int v29; // [rsp+A0h] [rbp+18h]
  hkaiNewFaceCutterUtil::RegionEdge *v30; // [rsp+A8h] [rbp+20h]

  v29 = p.m_xy;
  v3 = state->m_regionEdges.m_size;
  v4 = &state->m_regionEdges;
  v5 = regionAIndex;
  v6 = state;
  v7 = state->m_regionEdges.m_size + 3;
  v8 = state->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v7 )
  {
    v9 = 2 * v8;
    if ( v7 < v9 )
      v7 = v9;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v7, 8);
    p.m_xy = v29;
  }
  v4->m_size += 3;
  v10 = &v6->m_regions;
  v27 = v6->m_regions.m_size;
  v11 = v3 + 1;
  v12 = v3 + 2;
  if ( v6->m_regions.m_size == (v6->m_regions.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_regions, 6);
    p.m_xy = v29;
  }
  ++v6->m_regions.m_size;
  v13 = v6->m_outputVertices.m_size == 0;
  v14 = (signed __int64)&v10->m_data[v5];
  v15 = v4->m_data;
  LOWORD(result.m_enum) = *(_WORD *)(v14 + 2);
  v16 = (signed __int64)&v15[SLOWORD(result.m_enum)];
  v17 = (signed __int64)&v15[v3];
  v18 = (signed __int64)&v15[v11];
  v30 = &v15[v3];
  v26 = (signed __int64)&v15[v11];
  v19 = (signed __int64)&v15[v12];
  if ( v13 || v6->m_outputVertices.m_data[v6->m_outputVertices.m_size - 1].m_xy != p.m_xy )
  {
    v21 = hkaiNewFaceCutterUtil::State::_addOutputVertex(v6, p);
    v17 = (signed __int64)v30;
    v18 = v26;
    v20 = v21;
  }
  else
  {
    v20 = LOWORD(v6->m_outputVertices.m_size) - 1;
  }
  *(_WORD *)(v16 + 2) = v3;
  *(_DWORD *)(v16 + 4) &= 0xFFFF0002;
  *(_DWORD *)(v16 + 4) |= 4 * (v12 & 0x3FFF) | 2;
  *(_WORD *)v17 = v20;
  *(_WORD *)(v17 + 2) = -1;
  *(_DWORD *)(v17 + 4) = *(_DWORD *)(v17 + 4) & 0xFFFF0003 | 3;
  v22 = *(_WORD *)v16;
  *(_WORD *)(v18 + 2) = -1;
  *(_WORD *)v18 = v22;
  *(_DWORD *)(v18 + 4) = *(_DWORD *)(v18 + 4) & 0xFFFF0003 | 3;
  v23 = v27;
  *(_WORD *)v19 = v20;
  v24 = result.m_enum;
  *(_WORD *)(v19 + 2) = v11;
  *(_DWORD *)(v19 + 4) &= 0xFFFF0002;
  *(_DWORD *)(v19 + 4) |= 4 * (v24 & 0x3FFF) | 2;
  *(_WORD *)(v14 + 2) = v3;
  v25 = (signed __int64)&v10->m_data[v27];
  *(_WORD *)v25 = v12;
  *(_WORD *)(v25 + 2) = v11;
  *(_BYTE *)(v25 + 4) = *(_BYTE *)(v14 + 4);
  return v23;
}

// File Line: 151
// RVA: 0x12FA540
void __fastcall hkaiNewFaceCutterUtil::splitRegionAtBothEdges(hkaiNewFaceCutterUtil::State *state, __int16 regionAIndex, hkaiNewFaceCutterUtil::Vec2 p, __int16 *bottomRegionIndexOut, __int16 *topRegionIndexOut)
{
  signed __int16 v5; // bp
  hkArray<hkaiNewFaceCutterUtil::RegionEdge,hkContainerHeapAllocator> *v6; // rsi
  hkaiNewFaceCutterUtil::State *v7; // rdi
  int v8; // er9
  int v9; // eax
  int v10; // eax
  hkArray<hkaiNewFaceCutterUtil::Region,hkContainerHeapAllocator> *v11; // rbx
  __int16 v12; // r14
  __int16 v13; // r15
  __int16 v14; // r12
  __int16 v15; // r13
  bool v16; // zf
  hkaiNewFaceCutterUtil::Region *v17; // r8
  hkaiNewFaceCutterUtil::RegionEdge *v18; // rcx
  __int64 v19; // rax
  signed __int64 v20; // rsi
  signed __int64 v21; // r9
  signed __int64 v22; // r10
  signed __int64 v23; // r11
  __int16 v24; // dx
  __int16 v25; // ax
  __int16 v26; // ax
  __int16 v27; // ax
  __int16 v28; // ax
  signed __int64 v29; // rdx
  hkaiNewFaceCutterUtil::Region *v30; // rax
  signed __int64 v31; // rdx
  __int16 v32; // [rsp+30h] [rbp-88h]
  __int16 v33; // [rsp+32h] [rbp-86h]
  signed __int64 v34; // [rsp+38h] [rbp-80h]
  signed __int64 v35; // [rsp+40h] [rbp-78h]
  signed __int64 v36; // [rsp+48h] [rbp-70h]
  hkaiNewFaceCutterUtil::Region *v37; // [rsp+50h] [rbp-68h]
  hkaiNewFaceCutterUtil::RegionEdge *v38; // [rsp+58h] [rbp-60h]
  signed __int64 v39; // [rsp+60h] [rbp-58h]
  signed __int64 v40; // [rsp+68h] [rbp-50h]
  hkResult result; // [rsp+C0h] [rbp+8h]
  __int16 v42; // [rsp+C8h] [rbp+10h]
  hkaiNewFaceCutterUtil::Vec2 v; // [rsp+D0h] [rbp+18h]
  __int16 *v44; // [rsp+D8h] [rbp+20h]

  v44 = bottomRegionIndexOut;
  v.m_xy = p.m_xy;
  v42 = regionAIndex;
  v5 = state->m_regionEdges.m_size;
  v6 = &state->m_regionEdges;
  v7 = state;
  v8 = state->m_regionEdges.m_size + 5;
  v9 = state->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < v8 )
  {
    v10 = 2 * v9;
    if ( v8 < v10 )
      v8 = v10;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, v8, 8);
  }
  v6->m_size += 5;
  v11 = &v7->m_regions;
  v32 = v7->m_regions.m_size;
  v12 = v5 + 1;
  v13 = v5 + 2;
  v14 = v5 + 3;
  v15 = v5 + 4;
  if ( v7->m_regions.m_size == (v7->m_regions.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_regions, 6);
  ++v7->m_regions.m_size;
  v33 = v7->m_regions.m_size;
  if ( v7->m_regions.m_size == (v7->m_regions.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_regions, 6);
  ++v7->m_regions.m_size;
  v16 = v7->m_outputVertices.m_size == 0;
  v17 = &v11->m_data[v42];
  v18 = v6->m_data;
  v19 = v17->m_head;
  LOWORD(result.m_enum) = v17->m_tail;
  v20 = (signed __int64)&v18[SLOWORD(result.m_enum)];
  v42 = v19;
  v37 = v17;
  v38 = &v18[v19];
  v21 = (signed __int64)&v18[v5];
  v39 = (signed __int64)&v18[v5];
  v22 = (signed __int64)&v18[v13];
  v36 = (signed __int64)&v18[v12];
  v23 = (signed __int64)&v18[v14];
  v34 = (signed __int64)&v18[v13];
  v35 = (signed __int64)&v18[v14];
  v40 = (signed __int64)&v18[v15];
  if ( v16 || v7->m_outputVertices.m_data[v7->m_outputVertices.m_size - 1].m_xy != v.m_xy )
  {
    v25 = hkaiNewFaceCutterUtil::State::_addOutputVertex(v7, v);
    v17 = v37;
    v21 = v39;
    v22 = v34;
    v23 = v35;
    v24 = v25;
  }
  else
  {
    v24 = LOWORD(v7->m_outputVertices.m_size) - 1;
  }
  *(_WORD *)(v20 + 2) = v5;
  *(_DWORD *)(v20 + 4) &= 0xFFFF0002;
  v26 = v42;
  *(_DWORD *)(v20 + 4) |= 4 * (v13 & 0x3FFF) | 2;
  *(_WORD *)(v21 + 2) = v26;
  *(_WORD *)v21 = v24;
  *(_DWORD *)(v21 + 4) &= 0xFFFF0002;
  *(_DWORD *)(v21 + 4) |= 4 * (v14 & 0x3FFF) | 2;
  *(_WORD *)v36 = *(_WORD *)v20;
  *(_WORD *)(v36 + 2) = -1;
  *(_DWORD *)(v36 + 4) = *(_DWORD *)(v36 + 4) & 0xFFFF0003 | 3;
  v27 = result.m_enum;
  *(_WORD *)v22 = v24;
  *(_WORD *)(v22 + 2) = v12;
  *(_DWORD *)(v22 + 4) &= 0xFFFF0002;
  *(_DWORD *)(v22 + 4) |= 4 * (v27 & 0x3FFF) | 2;
  v28 = v38->m_outputVertexIndex;
  *(_WORD *)(v23 + 2) = v15;
  *(_WORD *)v23 = v28;
  *(_DWORD *)(v23 + 4) &= 0xFFFF0002;
  *(_DWORD *)(v23 + 4) |= 4 * (v5 & 0x3FFF) | 2;
  *(_WORD *)v40 = v24;
  *(_WORD *)(v40 + 2) = -1;
  *(_DWORD *)(v40 + 4) = *(_DWORD *)(v40 + 4) & 0xFFFF0003 | 3;
  v17->m_tail = v5;
  v17->m_head = v5;
  v29 = (signed __int64)&v11->m_data[v32];
  *(_WORD *)v29 = v13;
  *(_WORD *)(v29 + 2) = v12;
  *(_BYTE *)(v29 + 4) = v17->m_painterIndex;
  v30 = v11->m_data;
  v30[v33].m_head = v14;
  v31 = (signed __int64)&v30[v33];
  *(_WORD *)(v31 + 2) = v15;
  *(_BYTE *)(v31 + 4) = v17->m_painterIndex;
  *v44 = v32;
  *topRegionIndexOut = v33;
}

// File Line: 240
// RVA: 0x12FA860
void __fastcall hkaiNewFaceCutterUtil::closeRegionAt(hkaiNewFaceCutterUtil::State *state, hkaiNewFaceCutterUtil::Region *region, hkaiNewFaceCutterUtil::Vec2 eventPos, hkaiNewFaceCutterUtil::RegionEdgeConnectivity belowConnectivity, hkaiNewFaceCutterUtil::RegionEdgeConnectivity aboveConnectivity, __int16 *bottomEdgeIndexOut, __int16 *topEdgeIndexOut)
{
  hkArray<hkaiNewFaceCutterUtil::RegionEdge,hkContainerHeapAllocator> *v7; // r15
  hkaiNewFaceCutterUtil::Region *v8; // r12
  int v9; // er9
  hkaiNewFaceCutterUtil::State *v10; // rdi
  int v11; // eax
  int v12; // eax
  __int16 v13; // si
  __int64 v14; // rbp
  __int64 v15; // r14
  signed __int64 v16; // rbx
  __int16 *v17; // rax
  __int16 *v18; // rax
  __int16 v19; // di
  hkaiNewFaceCutterUtil::RegionEdge *v20; // rax
  signed __int64 v21; // rdx
  __int16 *v22; // rax
  hkResult result; // [rsp+70h] [rbp+8h]
  unsigned int v24; // [rsp+80h] [rbp+18h]
  hkaiNewFaceCutterUtil::RegionEdgeConnectivity v25; // [rsp+88h] [rbp+20h]

  v25 = belowConnectivity;
  v24 = eventPos.m_xy;
  v7 = &state->m_regionEdges;
  v8 = region;
  v9 = state->m_regionEdges.m_size + 1;
  v10 = state;
  v11 = state->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < v9 )
  {
    v12 = 2 * v11;
    if ( v9 < v12 )
      v9 = v12;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, v9, 8);
    eventPos.m_xy = v24;
  }
  if ( v10->m_outputVertices.m_size
    && v10->m_outputVertices.m_data[v10->m_outputVertices.m_size - 1].m_xy == eventPos.m_xy )
  {
    v13 = LOWORD(v10->m_outputVertices.m_size) - 1;
  }
  else
  {
    v13 = hkaiNewFaceCutterUtil::State::_addOutputVertex(v10, eventPos);
  }
  v14 = v8->m_head;
  v15 = v8->m_tail;
  v16 = (signed __int64)&v7->m_data[v15];
  if ( v7->m_data[v14].m_outputVertexIndex == v13 )
  {
    *(_WORD *)(v16 + 2) = v14;
    *(hkaiNewFaceCutterUtil::RegionEdgeConnectivity *)(v16 + 4) = v25;
    v17 = bottomEdgeIndexOut;
    v8->m_tail = v14;
    *v17 = v15;
    *topEdgeIndexOut = -1;
  }
  else if ( *(_WORD *)v16 == v13 )
  {
    *(_WORD *)(v16 + 2) = v14;
    *(hkaiNewFaceCutterUtil::RegionEdgeConnectivity *)(v16 + 4) = aboveConnectivity;
    v18 = bottomEdgeIndexOut;
    v8->m_head = v15;
    *v18 = -1;
    *topEdgeIndexOut = v15;
  }
  else
  {
    v19 = v10->m_regionEdges.m_size;
    if ( v7->m_size == (v7->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 8);
    ++v7->m_size;
    v20 = v7->m_data;
    *(_WORD *)(v16 + 2) = v19;
    v21 = (signed __int64)&v20[v19];
    *(hkaiNewFaceCutterUtil::RegionEdgeConnectivity *)(v16 + 4) = v25;
    *(_WORD *)v21 = v13;
    *(_WORD *)(v21 + 2) = v14;
    *(hkaiNewFaceCutterUtil::RegionEdgeConnectivity *)(v21 + 4) = aboveConnectivity;
    v22 = bottomEdgeIndexOut;
    v8->m_head = v19;
    v8->m_tail = v19;
    *v22 = v15;
    *topEdgeIndexOut = v19;
  }
}

// File Line: 288
// RVA: 0x12FAA30
signed __int64 __fastcall hkaiNewFaceCutterUtil::addTopEdgeToRegion(hkaiNewFaceCutterUtil::State *state, hkaiNewFaceCutterUtil::Region *belowRegion, hkaiNewFaceCutterUtil::Vec2 p, hkaiNewFaceCutterUtil::RegionEdgeConnectivity regionEdgeConnectivity)
{
  __int16 v4; // bp
  hkaiNewFaceCutterUtil::Region *v5; // r14
  hkaiNewFaceCutterUtil::State *v6; // rbx
  __int16 v7; // si
  hkArray<hkaiNewFaceCutterUtil::RegionEdge,hkContainerHeapAllocator> *v8; // rdi
  signed __int64 result; // rax
  __int16 v10; // bx
  signed __int64 v11; // r8
  hkaiNewFaceCutterUtil::RegionEdgeConnectivity v12; // [rsp+58h] [rbp+20h]

  v12 = regionEdgeConnectivity;
  v4 = belowRegion->m_head;
  v5 = belowRegion;
  v6 = state;
  if ( state->m_outputVertices.m_size
    && state->m_outputVertices.m_data[state->m_outputVertices.m_size - 1].m_xy == p.m_xy )
  {
    v7 = LOWORD(state->m_outputVertices.m_size) - 1;
  }
  else
  {
    v7 = hkaiNewFaceCutterUtil::State::_addOutputVertex(state, p);
  }
  v8 = &v6->m_regionEdges;
  if ( v6->m_regionEdges.m_data[v4].m_outputVertexIndex == v7 )
    return 0xFFFFFFFFi64;
  v10 = v6->m_regionEdges.m_size;
  if ( v8->m_size == (v8->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, 8);
  ++v8->m_size;
  v11 = (signed __int64)&v8->m_data[v10];
  result = (unsigned __int16)v10;
  *(_WORD *)v11 = v7;
  *(_WORD *)(v11 + 2) = v4;
  *(hkaiNewFaceCutterUtil::RegionEdgeConnectivity *)(v11 + 4) = v12;
  v5->m_head = v10;
  return result;
}

// File Line: 310
// RVA: 0x12FAB10
signed __int64 __fastcall hkaiNewFaceCutterUtil::addBottomEdgeToRegion(hkaiNewFaceCutterUtil::State *state, hkaiNewFaceCutterUtil::Region *aboveRegion, hkaiNewFaceCutterUtil::Vec2 p, hkaiNewFaceCutterUtil::RegionEdgeConnectivity regionEdgeConnectivity)
{
  hkArray<hkaiNewFaceCutterUtil::RegionEdge,hkContainerHeapAllocator> *v4; // rbx
  hkaiNewFaceCutterUtil::Region *v5; // r15
  int v6; // er9
  hkaiNewFaceCutterUtil::State *v7; // rdi
  int v8; // eax
  int v9; // eax
  __int64 v10; // r14
  signed __int64 v11; // rbp
  __int16 v12; // si
  signed __int64 v13; // rax
  __int16 v14; // di
  hkaiNewFaceCutterUtil::RegionEdge *v15; // rax
  signed __int64 v16; // rdx
  hkResult result; // [rsp+60h] [rbp+8h]
  unsigned int v18; // [rsp+70h] [rbp+18h]
  hkaiNewFaceCutterUtil::RegionEdgeConnectivity v19; // [rsp+78h] [rbp+20h]

  v19 = regionEdgeConnectivity;
  v18 = p.m_xy;
  v4 = &state->m_regionEdges;
  v5 = aboveRegion;
  v6 = state->m_regionEdges.m_size + 1;
  v7 = state;
  v8 = state->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v6 )
  {
    v9 = 2 * v8;
    if ( v6 < v9 )
      v6 = v9;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v6, 8);
    p.m_xy = v18;
  }
  v10 = v5->m_tail;
  v11 = (signed __int64)&v4->m_data[v10];
  if ( v7->m_outputVertices.m_size && v7->m_outputVertices.m_data[v7->m_outputVertices.m_size - 1].m_xy == p.m_xy )
    v12 = LOWORD(v7->m_outputVertices.m_size) - 1;
  else
    v12 = hkaiNewFaceCutterUtil::State::_addOutputVertex(v7, p);
  if ( *(_WORD *)v11 == v12 )
    return 0xFFFFFFFFi64;
  v14 = v7->m_regionEdges.m_size;
  if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
  ++v4->m_size;
  v15 = v4->m_data;
  *(_WORD *)(v11 + 2) = v14;
  v16 = (signed __int64)&v15[v14];
  *(hkaiNewFaceCutterUtil::RegionEdgeConnectivity *)(v11 + 4) = v19;
  *(_WORD *)(v16 + 2) = -1;
  *(_WORD *)v16 = v12;
  v13 = (unsigned __int16)v10;
  *(_DWORD *)(v16 + 4) = *(_DWORD *)(v16 + 4) & 0xFFFF0003 | 3;
  v5->m_tail = v14;
  return v13;
}

// File Line: 337
// RVA: 0x12FAC60
void __fastcall hkaiNewFaceCutterUtil::splitRegionAtTopMouth(hkaiNewFaceCutterUtil::State *state, __int16 *topRegionIndex)
{
  __int16 v2; // r14
  hkArray<hkaiNewFaceCutterUtil::RegionEdge,hkContainerHeapAllocator> *v3; // rsi
  __int16 *v4; // r12
  hkaiNewFaceCutterUtil::State *v5; // rbx
  int v6; // er9
  int v7; // eax
  int v8; // eax
  __int16 v9; // r15
  hkArray<hkaiNewFaceCutterUtil::Region,hkContainerHeapAllocator> *v10; // rbx
  __int16 v11; // bp
  __int64 v12; // r10
  __int64 v13; // r8
  signed __int64 v14; // rdi
  signed __int64 v15; // rbx
  hkaiNewFaceCutterUtil::RegionEdge *v16; // rcx
  signed __int64 v17; // r9
  signed __int64 v18; // r11
  hkaiNewFaceCutterUtil::RegionEdge *v19; // rdx
  signed __int64 v20; // rcx
  hkResult result; // [rsp+60h] [rbp+8h]

  v2 = state->m_regionEdges.m_size;
  v3 = &state->m_regionEdges;
  v4 = topRegionIndex;
  v5 = state;
  v6 = state->m_regionEdges.m_size + 2;
  v7 = state->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v6 )
  {
    v8 = 2 * v7;
    if ( v6 < v8 )
      v6 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v6, 8);
  }
  v3->m_size += 2;
  v9 = v5->m_regions.m_size;
  v10 = &v5->m_regions;
  v11 = v2 + 1;
  if ( v10->m_size == (v10->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 6);
  ++v10->m_size;
  v12 = v10->m_data[*v4].m_tail;
  v13 = v10->m_data[*v4].m_head;
  v14 = (signed __int64)&v10->m_data[*v4];
  v15 = (signed __int64)&v10->m_data[v9];
  v16 = v3->m_data;
  *(_DWORD *)&v16[v12].m_connectivity &= 0xFFFF0002;
  v17 = (signed __int64)&v16[v2];
  v18 = (signed __int64)&v16[v12];
  v19 = &v16[v13];
  v20 = (signed __int64)&v16[v11];
  *(_DWORD *)(v18 + 4) |= 4 * (v2 & 0x3FFF) | 2;
  *(_WORD *)(v18 + 2) = v13;
  *(_WORD *)v17 = v19->m_outputVertexIndex;
  *(_WORD *)(v17 + 2) = v11;
  *(_DWORD *)(v17 + 4) &= 0xFFFF0002;
  *(_DWORD *)(v17 + 4) |= 4 * (v12 & 0x3FFF) | 2;
  *(_WORD *)v20 = *(_WORD *)v18;
  *(_WORD *)(v20 + 2) = -1;
  *(_DWORD *)(v20 + 4) = *(_DWORD *)(v20 + 4) & 0xFFFF0003 | 3;
  *(_WORD *)(v14 + 2) = *(_WORD *)v14;
  *(_WORD *)(v15 + 2) = v11;
  *(_WORD *)v15 = v2;
  *(_BYTE *)(v15 + 4) = *(_BYTE *)(v14 + 4);
  *v4 = v9;
}

// File Line: 375
// RVA: 0x12FADE0
void __fastcall hkaiNewFaceCutterUtil::splitRegionAtBottomMouth(hkaiNewFaceCutterUtil::State *state, __int16 *bottomRegionIndex)
{
  __int16 v2; // r14
  hkArray<hkaiNewFaceCutterUtil::RegionEdge,hkContainerHeapAllocator> *v3; // rbx
  __int16 *v4; // r12
  hkaiNewFaceCutterUtil::State *v5; // rdi
  int v6; // er9
  int v7; // eax
  int v8; // eax
  __int16 v9; // r15
  hkArray<hkaiNewFaceCutterUtil::Region,hkContainerHeapAllocator> *v10; // rdi
  __int16 v11; // bp
  __int64 v12; // r10
  hkaiNewFaceCutterUtil::Region *v13; // rsi
  signed __int64 v14; // rdi
  hkaiNewFaceCutterUtil::RegionEdge *v15; // rcx
  __int64 v16; // rdx
  signed __int64 v17; // r11
  signed __int64 v18; // rbx
  signed __int64 v19; // r9
  __int16 v20; // ax
  hkResult result; // [rsp+60h] [rbp+8h]

  v2 = state->m_regionEdges.m_size;
  v3 = &state->m_regionEdges;
  v4 = bottomRegionIndex;
  v5 = state;
  v6 = state->m_regionEdges.m_size + 2;
  v7 = state->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v6 )
  {
    v8 = 2 * v7;
    if ( v6 < v8 )
      v6 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v6, 8);
  }
  v3->m_size += 2;
  v9 = v5->m_regions.m_size;
  v10 = &v5->m_regions;
  v11 = v2 + 1;
  if ( v10->m_size == (v10->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 6);
  ++v10->m_size;
  v12 = v10->m_data[*v4].m_tail;
  v13 = &v10->m_data[*v4];
  v14 = (signed __int64)&v10->m_data[v9];
  v15 = v3->m_data;
  v16 = v13->m_head;
  v15[v12].m_next = v16;
  *(_DWORD *)&v15[v12].m_connectivity &= 0xFFFF0002;
  v17 = (signed __int64)&v15[v12];
  v18 = (signed __int64)&v15[v2];
  v19 = (signed __int64)&v15[v11];
  *(_DWORD *)(v17 + 4) |= 4 * (v11 & 0x3FFF) | 2;
  v20 = v15[v16].m_outputVertexIndex;
  *(_WORD *)(v19 + 2) = v2;
  *(_WORD *)v19 = v20;
  *(_DWORD *)(v19 + 4) &= 0xFFFF0002;
  *(_DWORD *)(v19 + 4) |= 4 * (v12 & 0x3FFF) | 2;
  *(_WORD *)v18 = *(_WORD *)v17;
  *(_WORD *)(v18 + 2) = -1;
  *(_DWORD *)(v18 + 4) = *(_DWORD *)(v18 + 4) & 0xFFFF0003 | 3;
  v13->m_tail = v13->m_head;
  *(_WORD *)v14 = v11;
  *(_WORD *)(v14 + 2) = v2;
  *(_BYTE *)(v14 + 4) = v13->m_painterIndex;
  *v4 = v9;
}

// File Line: 413
// RVA: 0x12F9FC0
void __fastcall hkaiNewFaceCutterUtil::shiftOutputVertexIndicesInRegionEdges(hkaiNewFaceCutterUtil::State *state, __int16 startIndex)
{
  int v2; // er10
  int v3; // eax
  __int16 i; // r11
  hkaiNewFaceCutterUtil::RegionEdge *v5; // r8
  __int16 v6; // dx

  v2 = state->m_regionEdges.m_size;
  v3 = 0;
  for ( i = startIndex; v3 < v2; ++v3 )
  {
    v5 = state->m_regionEdges.m_data;
    v6 = v5[(signed __int16)v3].m_outputVertexIndex;
    if ( v6 >= i )
      v5[(signed __int16)v3].m_outputVertexIndex = v6 + 1;
  }
}


// File Line: 17
// RVA: 0x12F9240
void __fastcall hkaiNewFaceCutterUtil::outputRegion(hkaiNewFaceCutterUtil::State *state, hkaiNewFaceCutterUtil::Region *region, hkArrayBase<unsigned int> *regionEdgeIndices, hkaiFaceCutResults *results, unsigned int **output)
{
  int v5; // er15
  unsigned int v6; // ebx
  hkaiNewFaceCutterUtil::Region *v7; // r12
  hkaiNewFaceCutterUtil::State *v8; // r13
  hkLifoAllocator *v9; // rax
  unsigned int *v10; // rbp
  int v11; // edx
  char *v12; // rcx
  hkLifoAllocator *v13; // rax
  _DWORD *v14; // r14
  int v15; // edx
  char *v16; // rcx
  hkLifoAllocator *v17; // rax
  hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char> *v18; // rsi
  int v19; // edx
  hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char> *v20; // rcx
  __int16 v21; // r11
  hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char> *v22; // r10
  _DWORD *v23; // r8
  unsigned __int64 v24; // rax
  hkaiNewFaceCutterUtil::RegionEdge v25; // rax
  int v26; // er9
  int v27; // ecx
  char v28; // al
  unsigned int v29; // ecx
  unsigned int **v30; // rdx
  unsigned int *v31; // r8
  unsigned int *v32; // rcx
  __int64 v33; // r9
  unsigned int v34; // eax
  unsigned int *v35; // r8
  __int64 v36; // r9
  unsigned int v37; // eax
  signed int v38; // ebx
  hkLifoAllocator *v39; // rax
  int v40; // er8
  signed int v41; // esi
  hkLifoAllocator *v42; // rax
  int v43; // ebx
  hkLifoAllocator *v44; // rax
  signed int v45; // [rsp+70h] [rbp+8h]
  hkaiNewFaceCutterUtil::Region *v46; // [rsp+78h] [rbp+10h]
  hkArrayBase<unsigned int> *v47; // [rsp+80h] [rbp+18h]
  hkaiFaceCutResults *v48; // [rsp+88h] [rbp+20h]

  v48 = results;
  v47 = regionEdgeIndices;
  v46 = region;
  v5 = state->m_regionEdges.m_size;
  v6 = 0;
  v7 = region;
  v8 = state;
  if ( v5 )
  {
    v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (unsigned int *)v9->m_cur;
    v11 = (4 * v5 + 127) & 0xFFFFFF80;
    v12 = (char *)v10 + v11;
    if ( v11 > v9->m_slabSize || v12 > v9->m_end )
      v10 = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v9, v11);
    else
      v9->m_cur = v12;
  }
  else
  {
    v10 = 0i64;
  }
  if ( v5 )
  {
    v13 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = v13->m_cur;
    v15 = (4 * v5 + 127) & 0xFFFFFF80;
    v16 = (char *)v14 + v15;
    if ( v15 > v13->m_slabSize || v16 > v13->m_end )
      v14 = hkLifoAllocator::allocateFromNewSlab(v13, v15);
    else
      v13->m_cur = v16;
  }
  else
  {
    v14 = 0i64;
  }
  if ( v5 )
  {
    v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = (hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char> *)v17->m_cur;
    v19 = (v5 + 127) & 0xFFFFFF80;
    v20 = &v18[v19];
    if ( v19 > v17->m_slabSize || v20 > v17->m_end )
      v18 = (hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char> *)hkLifoAllocator::allocateFromNewSlab(
                                                                                   v17,
                                                                                   v19);
    else
      v17->m_cur = v20;
  }
  else
  {
    v18 = 0i64;
  }
  v21 = v7->m_head;
  v22 = v18;
  v23 = v14;
  LOWORD(v24) = v7->m_head;
  do
  {
    v25 = v8->m_regionEdges.m_data[(signed __int16)v24];
    *(_DWORD *)((char *)v23 + (char *)v10 - (char *)v14) = v25.m_outputVertexIndex;
    v26 = *(_BYTE *)&v25.m_connectivity & 3;
    v27 = *(_DWORD *)&v25.m_connectivity << 16 >> 18;
    if ( v26 == 2 )
      *v23 = v47->m_data[(signed __int16)v27];
    else
      *v23 = v27;
    v24 = *(unsigned __int64 *)&v25 >> 16;
    (++v22)[-1].m_storage = v26 | 4;
    ++v6;
    ++v23;
  }
  while ( (_WORD)v24 != v21 );
  v28 = v46->m_painterIndex;
  if ( v28 == -1 )
    v29 = v8->m_faceMaterial;
  else
    v29 = v8->m_painterMaterials.m_data[v28];
  v30 = output;
  v45 = v5 | 0x80000000;
  v31 = v10;
  **output = v6;
  ++*v30;
  **output = v29;
  ++*v30;
  v32 = *output;
  if ( (signed int)v6 > 0 )
  {
    v33 = v6;
    do
    {
      v34 = *v31;
      ++v31;
      *v32 = v34;
      ++*output;
      v32 = *output;
      --v33;
    }
    while ( v33 );
  }
  v35 = v14;
  if ( (signed int)v6 > 0 )
  {
    v36 = v6;
    do
    {
      v37 = *v35;
      ++v35;
      *v32 = v37;
      ++*output;
      v32 = *output;
      --v36;
    }
    while ( v36 );
  }
  hkaiFaceCutResults::writeFlags(v48, output, v18, v6);
  v38 = (v5 + 127) & 0xFFFFFF80;
  v39 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v40 = (v38 + 15) & 0xFFFFFFF0;
  if ( v38 > v39->m_slabSize || &v18[v40] != v39->m_cur || v39->m_firstNonLifoEnd == v18 )
    hkLifoAllocator::slowBlockFree(v39, v18, v40);
  else
    v39->m_cur = v18;
  if ( v45 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v18,
      v45 & 0x3FFFFFFF);
  v41 = (4 * v5 + 127) & 0xFFFFFF80;
  v42 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v43 = (v41 + 15) & 0xFFFFFFF0;
  if ( v41 > v42->m_slabSize || (char *)v14 + v43 != v42->m_cur || v42->m_firstNonLifoEnd == v14 )
    hkLifoAllocator::slowBlockFree(v42, v14, v43);
  else
    v42->m_cur = v14;
  if ( v45 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v14,
      4 * v45);
  v44 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v41 > v44->m_slabSize || (char *)v10 + v43 != v44->m_cur || v44->m_firstNonLifoEnd == v10 )
    hkLifoAllocator::slowBlockFree(v44, v10, v43);
  else
    v44->m_cur = v10;
  if ( v45 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v10,
      4 * v45);
}

// File Line: 54
// RVA: 0x12F95B0
void __fastcall hkaiNewFaceCutterUtil::translateRegionEdgeIndices(hkaiNewFaceCutterUtil::State *state, hkArrayBase<unsigned int> *regionEdgeIndices)
{
  hkaiNewFaceCutterUtil::State *v2; // r10
  int v3; // ebx
  unsigned int v4; // eax
  int i; // er8
  __int16 v6; // r9
  __int16 v7; // cx

  v2 = state;
  regionEdgeIndices->m_size = state->m_regionEdges.m_size;
  v3 = state->m_regions.m_size;
  v4 = 0;
  for ( i = 0; i < v3; ++i )
  {
    v6 = v2->m_regions.m_data[(signed __int16)i].m_head;
    v7 = v2->m_regions.m_data[(signed __int16)i].m_head;
    do
    {
      regionEdgeIndices->m_data[v7] = v4++;
      v7 = v2->m_regionEdges.m_data[v7].m_next;
    }
    while ( v7 != v6 );
  }
}

// File Line: 73
// RVA: 0x12F9640
void __fastcall hkaiNewFaceCutterUtil::transferNeighbors(hkaiNewFaceCutterUtil::State *state, __int16 firstEdgeIndex, __int16 secondEdgeIndex)
{
  hkaiNewFaceCutterUtil::RegionEdge *v3; // r9
  __int64 v4; // rax
  hkaiNewFaceCutterUtil::RegionEdgeConnectivity v5; // edx
  signed __int64 v6; // r8

  v3 = state->m_regionEdges.m_data;
  v4 = firstEdgeIndex;
  v5 = v3[firstEdgeIndex].m_connectivity;
  v6 = (signed __int64)&v3[secondEdgeIndex];
  if ( (*(_BYTE *)&v5 & 3) == 2 )
    v3[(signed __int16)((signed int)(*(_DWORD *)&v5 << 16) >> 18)].m_connectivity = *(hkaiNewFaceCutterUtil::RegionEdgeConnectivity *)(v6 + 4);
  if ( (*(_DWORD *)(v6 + 4) & 3) == 2 )
    state->m_regionEdges.m_data[(signed __int16)(*(_DWORD *)(v6 + 4) << 16 >> 18)].m_connectivity = v3[v4].m_connectivity;
}

// File Line: 96
// RVA: 0x12F96B0
char __fastcall hkaiNewFaceCutterUtil::clipDegenerateEarsFromRegion(hkaiNewFaceCutterUtil::State *state, __int16 regionIndex)
{
  hkaiNewFaceCutterUtil::State *v2; // r14
  __int64 v3; // rdx
  hkaiNewFaceCutterUtil::Region *v4; // rax
  __int64 v5; // rsi
  hkaiNewFaceCutterUtil::RegionEdge *v6; // rcx
  __int64 v7; // rbx
  hkaiNewFaceCutterUtil::RegionEdge *v8; // rdx
  __int64 v9; // rbp
  __int16 v10; // dx
  __int16 v11; // r15
  __int16 v12; // di
  __int16 v13; // r8
  char v14; // r9
  hkaiNewFaceCutterUtil::RegionEdge *v15; // rax
  __int16 v16; // r13
  signed __int64 v17; // r12
  hkaiNewFaceCutterUtil::RegionEdge *v18; // rax
  hkaiNewFaceCutterUtil::Region *v20; // [rsp+50h] [rbp+8h]

  v2 = state;
  v3 = regionIndex;
  v4 = &state->m_regions.m_data[v3];
  v20 = &state->m_regions.m_data[v3];
LABEL_2:
  while ( 2 )
  {
    v5 = v4->m_head;
    v6 = v2->m_regionEdges.m_data;
    v7 = v6[v5].m_next;
    v8 = &v6[v7];
    if ( (_WORD)v7 == (_WORD)v5 )
      return 0;
    v9 = v8->m_next;
    v10 = v8->m_outputVertexIndex;
    v11 = v4->m_head;
    v12 = v6[v9].m_next;
    v13 = v6[v9].m_outputVertexIndex;
    v14 = 0;
    do
    {
      v15 = v2->m_regionEdges.m_data;
      v16 = v15[v12].m_outputVertexIndex;
      v17 = (signed __int64)&v15[v12];
      if ( v10 == v16 )
      {
        hkaiNewFaceCutterUtil::transferNeighbors(v2, v7, v9);
        if ( (_WORD)v7 == v12 )
          return 0;
        v14 = 1;
        v2->m_regionEdges.m_data[v11].m_next = v12;
        if ( (_WORD)v7 == (_WORD)v5 || (_WORD)v9 == (_WORD)v5 )
        {
          v4 = v20;
          v20->m_head = v11;
          v20->m_tail = v11;
          goto LABEL_2;
        }
        v9 = *(signed __int16 *)(v17 + 2);
        v18 = v2->m_regionEdges.m_data;
        LOWORD(v7) = v12;
        v13 = v18[v9].m_outputVertexIndex;
        v12 = v18[v9].m_next;
        v10 = v16;
      }
      else
      {
        v11 = v7;
        LOWORD(v7) = v9;
        v10 = v13;
        LOWORD(v9) = v12;
        v12 = *(_WORD *)(v17 + 2);
        v13 = v16;
      }
    }
    while ( v11 != (_WORD)v5 );
    if ( v14 )
    {
      v4 = v20;
      continue;
    }
    return 1;
  }
}

// File Line: 180
// RVA: 0x12F9190
void __fastcall hkaiNewFaceCutterUtil::clipDegenerateEars(hkaiNewFaceCutterUtil::State *state)
{
  __int16 v1; // di
  hkaiNewFaceCutterUtil::State *v2; // rbx
  __int64 v3; // rax
  hkaiNewFaceCutterUtil::Region *v4; // rdx
  signed __int64 v5; // r8
  signed __int64 v6; // rax
  signed __int64 v7; // rdx
  signed __int64 v8; // r8
  __int16 v9; // cx

  v1 = 0;
  v2 = state;
  if ( state->m_regions.m_size > 0 )
  {
    do
    {
      if ( hkaiNewFaceCutterUtil::clipDegenerateEarsFromRegion(v2, v1) )
      {
        ++v1;
      }
      else
      {
        v3 = --v2->m_regions.m_size;
        if ( (_DWORD)v3 != v1 )
        {
          v4 = v2->m_regions.m_data;
          v5 = (signed __int64)&v4[v3];
          v6 = (signed __int64)&v4[v1];
          v7 = 3i64;
          v8 = v5 - v6;
          do
          {
            v9 = *(_WORD *)(v8 + v6);
            v6 += 2i64;
            *(_WORD *)(v6 - 2) = v9;
            --v7;
          }
          while ( v7 );
        }
      }
    }
    while ( v1 < v2->m_regions.m_size );
  }
}


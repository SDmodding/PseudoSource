// File Line: 17
// RVA: 0x12F9240
void __fastcall hkaiNewFaceCutterUtil::outputRegion(
        hkaiNewFaceCutterUtil::State *state,
        hkaiNewFaceCutterUtil::Region *region,
        hkArrayBase<unsigned int> *regionEdgeIndices,
        hkaiFaceCutResults *results,
        unsigned int **output)
{
  int m_size; // r15d
  int v6; // ebx
  hkLifoAllocator *Value; // rax
  char *m_cur; // rbp
  int v11; // edx
  char *v12; // rcx
  hkLifoAllocator *v13; // rax
  char *v14; // r14
  int v15; // edx
  char *v16; // rcx
  hkLifoAllocator *v17; // rax
  hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char> *v18; // rsi
  int v19; // edx
  hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char> *v20; // rcx
  __int16 m_head; // r11
  hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char> *v22; // r10
  _DWORD *v23; // r8
  unsigned __int64 v24; // rax
  hkaiNewFaceCutterUtil::RegionEdge v25; // rax
  int v26; // r9d
  int v27; // ecx
  char m_painterIndex; // al
  int m_faceMaterial; // ecx
  unsigned int *v30; // r8
  unsigned int *v31; // rcx
  __int64 v32; // r9
  unsigned int v33; // eax
  unsigned int *v34; // r8
  __int64 v35; // r9
  unsigned int v36; // eax
  signed int v37; // ebx
  hkLifoAllocator *v38; // rax
  int v39; // r8d
  signed int v40; // esi
  hkLifoAllocator *v41; // rax
  int v42; // ebx
  hkLifoAllocator *v43; // rax

  m_size = state->m_regionEdges.m_size;
  v6 = 0;
  if ( m_size )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)Value->m_cur;
    v11 = (4 * m_size + 127) & 0xFFFFFF80;
    v12 = &m_cur[v11];
    if ( v11 > Value->m_slabSize || v12 > Value->m_end )
      m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v11);
    else
      Value->m_cur = v12;
  }
  else
  {
    m_cur = 0i64;
  }
  if ( m_size )
  {
    v13 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = (char *)v13->m_cur;
    v15 = (4 * m_size + 127) & 0xFFFFFF80;
    v16 = &v14[v15];
    if ( v15 > v13->m_slabSize || v16 > v13->m_end )
      v14 = (char *)hkLifoAllocator::allocateFromNewSlab(v13, v15);
    else
      v13->m_cur = v16;
  }
  else
  {
    v14 = 0i64;
  }
  if ( m_size )
  {
    v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = (hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char> *)v17->m_cur;
    v19 = (m_size + 127) & 0xFFFFFF80;
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
  m_head = region->m_head;
  v22 = v18;
  v23 = v14;
  LOWORD(v24) = region->m_head;
  do
  {
    v25 = state->m_regionEdges.m_data[(__int16)v24];
    *(_DWORD *)((char *)v23 + m_cur - v14) = v25.m_outputVertexIndex;
    v26 = *(_BYTE *)&v25.m_connectivity & 3;
    v27 = *(_WORD *)&v25.m_connectivity >> 2;
    if ( v26 == 2 )
      *v23 = regionEdgeIndices->m_data[(__int16)v27];
    else
      *v23 = v27;
    v24 = *(unsigned __int64 *)&v25 >> 16;
    (v22++)->m_storage = v26 | 4;
    ++v6;
    ++v23;
  }
  while ( (_WORD)v24 != m_head );
  m_painterIndex = region->m_painterIndex;
  if ( m_painterIndex == -1 )
    m_faceMaterial = state->m_faceMaterial;
  else
    m_faceMaterial = state->m_painterMaterials.m_data[m_painterIndex];
  v30 = (unsigned int *)m_cur;
  *(*output)++ = v6;
  *(*output)++ = m_faceMaterial;
  v31 = *output;
  if ( v6 > 0 )
  {
    v32 = (unsigned int)v6;
    do
    {
      v33 = *v30++;
      *v31 = v33;
      v31 = ++*output;
      --v32;
    }
    while ( v32 );
  }
  v34 = (unsigned int *)v14;
  if ( v6 > 0 )
  {
    v35 = (unsigned int)v6;
    do
    {
      v36 = *v34++;
      *v31 = v36;
      v31 = ++*output;
      --v35;
    }
    while ( v35 );
  }
  hkaiFaceCutResults::writeFlags(results, output, v18, v6);
  v37 = (m_size + 127) & 0xFFFFFF80;
  v38 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v39 = (v37 + 15) & 0xFFFFFFF0;
  if ( v37 > v38->m_slabSize || &v18[v39] != v38->m_cur || v38->m_firstNonLifoEnd == v18 )
    hkLifoAllocator::slowBlockFree(v38, &v18->m_storage, v39);
  else
    v38->m_cur = v18;
  v40 = (4 * m_size + 127) & 0xFFFFFF80;
  v41 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v42 = (v40 + 15) & 0xFFFFFFF0;
  if ( v40 > v41->m_slabSize || &v14[v42] != v41->m_cur || v41->m_firstNonLifoEnd == v14 )
    hkLifoAllocator::slowBlockFree(v41, v14, v42);
  else
    v41->m_cur = v14;
  v43 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v40 > v43->m_slabSize || &m_cur[v42] != v43->m_cur || v43->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v43, m_cur, v42);
  else
    v43->m_cur = m_cur;
}

// File Line: 54
// RVA: 0x12F95B0
void __fastcall hkaiNewFaceCutterUtil::translateRegionEdgeIndices(
        hkaiNewFaceCutterUtil::State *state,
        hkArrayBase<unsigned int> *regionEdgeIndices)
{
  int m_size; // ebx
  unsigned int v4; // eax
  int i; // r8d
  __int16 m_head; // r9
  __int16 m_next; // cx

  regionEdgeIndices->m_size = state->m_regionEdges.m_size;
  m_size = state->m_regions.m_size;
  v4 = 0;
  for ( i = 0; i < m_size; ++i )
  {
    m_head = state->m_regions.m_data[(__int16)i].m_head;
    m_next = m_head;
    do
    {
      regionEdgeIndices->m_data[m_next] = v4++;
      m_next = state->m_regionEdges.m_data[m_next].m_next;
    }
    while ( m_next != m_head );
  }
}

// File Line: 73
// RVA: 0x12F9640
void __fastcall hkaiNewFaceCutterUtil::transferNeighbors(
        hkaiNewFaceCutterUtil::State *state,
        __int16 firstEdgeIndex,
        __int16 secondEdgeIndex)
{
  hkaiNewFaceCutterUtil::RegionEdge *m_data; // r9
  __int64 v4; // rax
  hkaiNewFaceCutterUtil::RegionEdgeConnectivity m_connectivity; // edx
  hkaiNewFaceCutterUtil::RegionEdge *v7; // r8
  hkaiNewFaceCutterUtil::RegionEdgeConnectivity v8; // ecx

  m_data = state->m_regionEdges.m_data;
  v4 = firstEdgeIndex;
  m_connectivity = m_data[firstEdgeIndex].m_connectivity;
  v7 = &m_data[secondEdgeIndex];
  if ( (*(_BYTE *)&m_connectivity & 3) == 2 )
    m_data[*(_WORD *)&m_connectivity >> 2].m_connectivity = v7->m_connectivity;
  v8 = v7->m_connectivity;
  if ( (*(_BYTE *)&v8 & 3) == 2 )
    state->m_regionEdges.m_data[*(_WORD *)&v8 >> 2].m_connectivity = m_data[v4].m_connectivity;
}

// File Line: 96
// RVA: 0x12F96B0
char __fastcall hkaiNewFaceCutterUtil::clipDegenerateEarsFromRegion(
        hkaiNewFaceCutterUtil::State *state,
        __int16 regionIndex)
{
  hkaiNewFaceCutterUtil::Region *v3; // rax
  __int64 m_head; // rsi
  hkaiNewFaceCutterUtil::RegionEdge *m_data; // rcx
  __int64 m_next; // rbx
  hkaiNewFaceCutterUtil::RegionEdge *v7; // rdx
  __int64 v8; // rbp
  __int16 m_outputVertexIndex; // dx
  __int16 v10; // r15
  __int16 v11; // di
  __int16 v12; // r8
  char v13; // r9
  hkaiNewFaceCutterUtil::RegionEdge *v14; // rax
  __int16 v15; // r13
  hkaiNewFaceCutterUtil::RegionEdge *v16; // r12
  hkaiNewFaceCutterUtil::RegionEdge *v17; // rax
  hkaiNewFaceCutterUtil::Region *v19; // [rsp+50h] [rbp+8h]

  v3 = &state->m_regions.m_data[regionIndex];
  v19 = v3;
LABEL_2:
  while ( 2 )
  {
    m_head = v3->m_head;
    m_data = state->m_regionEdges.m_data;
    m_next = m_data[m_head].m_next;
    v7 = &m_data[m_next];
    if ( (_WORD)m_next == (_WORD)m_head )
      return 0;
    v8 = v7->m_next;
    m_outputVertexIndex = v7->m_outputVertexIndex;
    v10 = v3->m_head;
    v11 = m_data[v8].m_next;
    v12 = m_data[v8].m_outputVertexIndex;
    v13 = 0;
    do
    {
      v14 = state->m_regionEdges.m_data;
      v15 = v14[v11].m_outputVertexIndex;
      v16 = &v14[v11];
      if ( m_outputVertexIndex == v15 )
      {
        hkaiNewFaceCutterUtil::transferNeighbors(state, m_next, v8);
        if ( (_WORD)m_next == v11 )
          return 0;
        v13 = 1;
        state->m_regionEdges.m_data[v10].m_next = v11;
        if ( (_WORD)m_next == (_WORD)m_head || (_WORD)v8 == (_WORD)m_head )
        {
          v3 = v19;
          v19->m_head = v10;
          v19->m_tail = v10;
          goto LABEL_2;
        }
        v8 = v16->m_next;
        v17 = state->m_regionEdges.m_data;
        LOWORD(m_next) = v11;
        v12 = v17[v8].m_outputVertexIndex;
        v11 = v17[v8].m_next;
        m_outputVertexIndex = v15;
      }
      else
      {
        v10 = m_next;
        LOWORD(m_next) = v8;
        m_outputVertexIndex = v12;
        LOWORD(v8) = v11;
        v11 = v16->m_next;
        v12 = v15;
      }
    }
    while ( v10 != (_WORD)m_head );
    if ( v13 )
    {
      v3 = v19;
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
  __int64 v3; // rax
  hkaiNewFaceCutterUtil::Region *m_data; // rdx
  hkaiNewFaceCutterUtil::Region *v5; // r8
  hkaiNewFaceCutterUtil::Region *v6; // rax
  __int64 v7; // rdx
  signed __int64 v8; // r8
  __int16 v9; // cx

  v1 = 0;
  while ( v1 < state->m_regions.m_size )
  {
    if ( hkaiNewFaceCutterUtil::clipDegenerateEarsFromRegion(state, v1) )
    {
      ++v1;
    }
    else
    {
      v3 = --state->m_regions.m_size;
      if ( (_DWORD)v3 != v1 )
      {
        m_data = state->m_regions.m_data;
        v5 = &m_data[v3];
        v6 = &m_data[v1];
        v7 = 3i64;
        v8 = (char *)v5 - (char *)v6;
        do
        {
          v9 = *(__int16 *)((char *)&v6->m_head + v8);
          v6 = (hkaiNewFaceCutterUtil::Region *)((char *)v6 + 2);
          *(_WORD *)&v6[-1].m_painterIndex = v9;
          --v7;
        }
        while ( v7 );
      }
    }
  }
}


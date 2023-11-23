// File Line: 27
// RVA: 0xC2D6C0
__int64 __fastcall cutter_splitEdges(
        hkaiStreamingCollection *collection,
        unsigned int faceKey,
        hkaiNavMeshGenerationUtils::EdgeSplit *splits,
        bool markOrphanedEdges)
{
  hkaiStreamingCollection::InstanceInfo *m_data; // rax
  hkaiNavMeshInstance *m_instancePtr; // r14
  hkaiNavMesh::Face *v6; // rcx
  __int64 v8; // rdx
  int m_startEdgeIndex; // r12d
  int v10; // esi
  int v11; // r9d
  int m_size; // ecx
  __int64 v13; // rdx
  unsigned int *p_m_oppositeEdge; // rcx
  int v15; // edi
  __int64 v16; // rbx
  signed int m_oppositeEdge; // edx
  _DWORD *v18; // rdi
  __int64 v19; // rcx
  hkaiNavMeshGenerationUtils::EdgeSplit *v20; // r15
  hkResultEnum v21; // edi
  __m128 m_tS_low; // xmm0
  hkaiNavMesh::Edge *v23; // r13
  __int64 v24; // r12
  __int64 m_a; // rax
  int m_numOriginalVertices; // ecx
  __m128 *p_m_quad; // rax
  __m128 v28; // xmm2
  __int64 m_b; // rax
  __m128 *v30; // rax
  int v31; // esi
  int v32; // edi
  __int64 v33; // rbx
  hkaiNavMeshInstance::AddEdgeContext *v34; // rdx
  unsigned __int64 v35; // rcx
  unsigned __int64 v36; // rax
  __m128 m_tE_low; // xmm0
  __int64 v38; // rax
  int v39; // ecx
  __m128 *v40; // rax
  __m128 v41; // xmm2
  __int64 v42; // rax
  __m128 *v43; // rax
  int v44; // esi
  int v45; // edi
  unsigned __int64 v46; // rbx
  hkaiNavMeshInstance::AddEdgeContext *v47; // rdx
  int v48; // eax
  hkResultEnum m_enum; // edi
  hkResultEnum v50; // r13d
  int v51; // r12d
  __int32 v52; // esi
  int v53; // eax
  int v54; // eax
  int v55; // r9d
  __int64 v56; // rdx
  hkHalf *v57; // rdi
  __int64 v58; // rcx
  hkaiNavMesh::Edge *appended; // rax
  __int64 v60; // r9
  int v61; // r12d
  int v62; // r10d
  __int64 v63; // r11
  unsigned int *v64; // rdi
  unsigned int v65; // edx
  int m_runtimeId; // eax
  __int64 v67; // r8
  hkResult *v68; // rax
  int v69; // eax
  int v70; // edx
  __int64 v71; // rcx
  __int64 v72; // rax
  __int64 v73; // rdx
  int m_numOriginalFaces; // eax
  hkaiNavMesh::Face *v75; // rcx
  signed __int64 v76; // r15
  hkResult result; // [rsp+30h] [rbp-98h] BYREF
  hkArrayBase<hkaiNavMeshInstance::AddEdgeContext> array; // [rsp+38h] [rbp-90h] BYREF
  int v80; // [rsp+48h] [rbp-80h]
  int v81; // [rsp+4Ch] [rbp-7Ch]
  hkaiNavMeshInstance::AddEdgeContext v82; // [rsp+50h] [rbp-78h] BYREF
  hkaiNavMeshInstance::AddEdgeContext t; // [rsp+78h] [rbp-50h] BYREF
  int v84; // [rsp+A0h] [rbp-28h]
  int v85; // [rsp+A8h] [rbp-20h]
  hkVector4f v; // [rsp+B8h] [rbp-10h] BYREF
  hkVector4f v87; // [rsp+C8h] [rbp+0h] BYREF
  __int64 v88; // [rsp+128h] [rbp+60h] BYREF
  hkResult v89; // [rsp+130h] [rbp+68h] BYREF
  hkaiNavMeshGenerationUtils::EdgeSplit *v90; // [rsp+138h] [rbp+70h]

  *(_DWORD *)&v82.m_edge.m_flags.m_storage = faceKey >> 22;
  m_data = collection->m_instances.m_data;
  v81 = faceKey & 0x3FFFFF;
  m_instancePtr = m_data[faceKey >> 22].m_instancePtr;
  *(_QWORD *)&v82.m_data[3] = faceKey & 0x3FFFFF;
  v6 = m_instancePtr->m_ownedFaces.m_data;
  v8 = *(_QWORD *)&v82.m_data[3] - m_instancePtr->m_numOriginalFaces;
  m_startEdgeIndex = v6[*(_QWORD *)&v82.m_data[3] - m_instancePtr->m_numOriginalFaces].m_startEdgeIndex;
  t.m_edge.m_b = v6[*(_QWORD *)&v82.m_data[3] - m_instancePtr->m_numOriginalFaces].m_startUserEdgeIndex;
  LODWORD(m_data) = *(_DWORD *)&v6[v8].m_numEdges;
  v82.m_data[0] = m_startEdgeIndex;
  v80 = (int)m_data;
  v10 = (__int16)m_data;
  v81 = *(_DWORD *)&v6[v8].m_clusterIndex;
  v11 = 2 * (__int16)m_data;
  v82.m_data[2] = v6[v8].m_startUserEdgeIndex;
  LODWORD(m_data) = *(_DWORD *)&v6[v8].m_numEdges;
  v84 = m_startEdgeIndex;
  v85 = (int)m_data;
  LODWORD(m_data) = *(_DWORD *)&v6[v8].m_clusterIndex;
  m_size = 0;
  v82.m_data[1] = (int)m_data;
  LODWORD(m_data) = m_instancePtr->m_numOriginalEdges + m_instancePtr->m_ownedEdges.m_size;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  v80 = (int)m_data;
  if ( v11 > 0 )
  {
    if ( (v10 & 0x40000000) != 0 )
      v11 = 0;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, v11, 40);
    m_size = array.m_size;
  }
  v13 = v10 - m_size;
  if ( v10 - m_size > 0 )
  {
    p_m_oppositeEdge = &array.m_data[m_size].m_edge.m_oppositeEdge;
    do
    {
      if ( p_m_oppositeEdge != (unsigned int *)8 )
      {
        *(_QWORD *)p_m_oppositeEdge = -1i64;
        p_m_oppositeEdge[2] = 4;
        *((_WORD *)p_m_oppositeEdge + 14) = -1;
        *(_QWORD *)(p_m_oppositeEdge + 3) = 0i64;
        *(_QWORD *)(p_m_oppositeEdge + 5) = 0i64;
      }
      p_m_oppositeEdge += 10;
      --v13;
    }
    while ( v13 );
  }
  array.m_size = v10;
  v15 = 0;
  if ( v10 > 0 )
  {
    v16 = 0i64;
    do
      hkaiNavMeshInstance::getEdgeContext(m_instancePtr, m_startEdgeIndex + v15++, &array.m_data[v16++]);
    while ( v15 < v10 );
    splits = v90;
  }
  m_oppositeEdge = 0;
  *(_QWORD *)&v82.m_edge.m_a = 0i64;
  v82.m_edge.m_oppositeFace = 0x80000000;
  v82.m_edge.m_oppositeEdge = 0;
  if ( v10 > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &v82, v10, 4);
    m_oppositeEdge = v82.m_edge.m_oppositeEdge;
  }
  v18 = (_DWORD *)(*(_QWORD *)&v82.m_edge.m_a + 4i64 * m_oppositeEdge);
  v19 = v10 - m_oppositeEdge;
  if ( v10 - m_oppositeEdge > 0 )
  {
    while ( v19 )
    {
      *v18++ = 0;
      --v19;
    }
  }
  v82.m_edge.m_oppositeEdge = v10;
  v20 = splits;
  v21 = HK_SUCCESS;
  result.m_enum = HK_SUCCESS;
  do
  {
    m_tS_low = (__m128)LODWORD(v20->m_tS);
    v23 = m_instancePtr->m_ownedEdges.m_data;
    v24 = m_startEdgeIndex + v20->m_edgeIdx - m_instancePtr->m_numOriginalEdges;
    if ( m_tS_low.m128_f32[0] > *(float *)(*(_QWORD *)&v82.m_edge.m_a + 4i64 * v20->m_edgeIdx) )
    {
      m_a = v23[v24].m_a;
      m_numOriginalVertices = m_instancePtr->m_numOriginalVertices;
      if ( (int)m_a >= m_numOriginalVertices )
        p_m_quad = &m_instancePtr->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices].m_quad;
      else
        p_m_quad = &m_instancePtr->m_originalVertices[m_a].m_quad;
      v28 = *p_m_quad;
      m_b = v23[v24].m_b;
      if ( (int)m_b >= m_numOriginalVertices )
        v30 = &m_instancePtr->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices].m_quad;
      else
        v30 = &m_instancePtr->m_originalVertices[m_b].m_quad;
      v31 = m_numOriginalVertices + m_instancePtr->m_ownedVertices.m_size;
      v.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*v30, v28), _mm_shuffle_ps(m_tS_low, m_tS_low, 0)), v28);
      hkaiNavMeshInstance::appendVertices(m_instancePtr, &v, 1);
      v32 = v20->m_edgeIdx + v21;
      v33 = v32;
      t = array.m_data[v32];
      hkArrayBase<hkaiNavMeshInstance::AddEdgeContext>::_insertAt(&array, &hkContainerTempAllocator::s_alloc, v32, &t);
      v34 = array.m_data;
      v35 = v32 + 1;
      v21 = result.m_enum + 1;
      v36 = v35;
      ++result.m_enum;
      array.m_data[v36].m_edge.m_a = v31;
      *(_QWORD *)&v34[v36].m_edge.m_oppositeEdge = -1i64;
      v34[v33].m_edge.m_b = v31;
    }
    *(float *)(*(_QWORD *)&v82.m_edge.m_a + 4i64 * v20->m_edgeIdx) = v20->m_tE;
    *v20->m_sharedPairEdgeIdx = *v20->m_sharedPairEdgeIdx & 0xFFC00000 | (v20->m_edgeIdx + v21 + v80);
    m_tE_low = (__m128)LODWORD(v20->m_tE);
    if ( m_tE_low.m128_f32[0] < 1.0 )
    {
      v38 = v23[v24].m_a;
      v39 = m_instancePtr->m_numOriginalVertices;
      if ( (int)v38 >= v39 )
        v40 = &m_instancePtr->m_ownedVertices.m_data[(int)v38 - v39].m_quad;
      else
        v40 = &m_instancePtr->m_originalVertices[v38].m_quad;
      v41 = *v40;
      v42 = v23[v24].m_b;
      if ( (int)v42 >= v39 )
        v43 = &m_instancePtr->m_ownedVertices.m_data[(int)v42 - v39].m_quad;
      else
        v43 = &m_instancePtr->m_originalVertices[v42].m_quad;
      v44 = v39 + m_instancePtr->m_ownedVertices.m_size;
      v87.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*v43, v41), _mm_shuffle_ps(m_tE_low, m_tE_low, 0)), v41);
      hkaiNavMeshInstance::appendVertices(m_instancePtr, &v87, 1);
      v45 = v20->m_edgeIdx + v21;
      v46 = v45;
      v82 = array.m_data[v45];
      hkArrayBase<hkaiNavMeshInstance::AddEdgeContext>::_insertAt(&array, &hkContainerTempAllocator::s_alloc, v45, &v82);
      v47 = array.m_data;
      v48 = v45 + 1;
      m_enum = result.m_enum;
      array.m_data[v46].m_edge.m_b = v44;
      v21 = m_enum + 1;
      *(_QWORD *)&v47[v46].m_edge.m_oppositeEdge = -1i64;
      result.m_enum = v21;
      v47[v48].m_edge.m_a = v44;
    }
    v50 = v89.m_enum;
    m_startEdgeIndex = v82.m_data[0];
    ++v20;
  }
  while ( v20->m_faceIdx == v89.m_enum );
  v51 = v81;
  if ( (_WORD)v80 != LOWORD(array.m_size) && v81 < m_instancePtr->m_faceClearanceIndices.m_size )
    m_instancePtr->m_faceClearanceIndices.m_data[*(_QWORD *)&v82.m_data[3]] = -1;
  v52 = v21 + m_instancePtr->m_globalClearanceCache.m_size;
  v53 = m_instancePtr->m_globalClearanceCache.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v53 < v52 )
  {
    v54 = 2 * v53;
    v55 = v21 + m_instancePtr->m_globalClearanceCache.m_size;
    if ( v52 < v54 )
      v55 = v54;
    hkArrayUtil::_reserve(&v89, &hkContainerHeapAllocator::s_alloc, &m_instancePtr->m_globalClearanceCache, v55, 2);
  }
  v56 = m_instancePtr->m_globalClearanceCache.m_size;
  v57 = &m_instancePtr->m_globalClearanceCache.m_data[v56];
  v58 = v52 - (int)v56;
  if ( v52 - (int)v56 > 0 )
  {
    while ( v58 )
    {
      v57->m_value = 32639;
      ++v57;
      --v58;
    }
  }
  m_instancePtr->m_globalClearanceCache.m_size = v52;
  LOWORD(v85) = array.m_size;
  appended = hkaiNavMeshInstance::appendEdges(m_instancePtr, array.m_data, array.m_size);
  v60 = 0i64;
  if ( array.m_size > 0 )
  {
    v61 = v80;
    v62 = *(_DWORD *)&v82.m_edge.m_flags.m_storage;
    v63 = v88;
    v64 = &appended->m_oppositeEdge;
    while ( 1 )
    {
      v65 = *v64;
      if ( *v64 == -1 )
      {
        *(_QWORD *)v64 = -1i64;
        *((_BYTE *)v64 + 8) = 4;
        goto LABEL_69;
      }
      if ( (v64[2] & 0x40) != 0 )
        m_runtimeId = v65 >> 22;
      else
        m_runtimeId = m_instancePtr->m_runtimeId;
      if ( v65 == -1 )
        m_runtimeId = -1;
      v67 = *(_QWORD *)(*(_QWORD *)(v63 + 32) + 48i64 * m_runtimeId);
      if ( *(_DWORD *)(v67 + 328) )
      {
        v68 = &v89;
        LOBYTE(v89.m_enum) = *(_BYTE *)((v64[1] & 0x3FFFFF) + *(_QWORD *)(v67 + 320));
      }
      else
      {
        LOBYTE(v88) = 0;
        v68 = (hkResult *)&v88;
      }
      if ( (v68->m_enum & 1) != 0 )
        goto LABEL_69;
      v69 = *(_DWORD *)(v67 + 40);
      v70 = v65 & 0x3FFFFF;
      if ( v70 >= v69 )
        break;
      if ( *(_DWORD *)(v67 + 216) )
        v70 = *(_DWORD *)(*(_QWORD *)(v67 + 208) + 4i64 * v70);
      if ( v70 != -1 )
      {
        v71 = 5i64 * v70;
        v72 = *(_QWORD *)(v67 + 256);
        goto LABEL_66;
      }
      v73 = 0i64;
LABEL_67:
      *(_DWORD *)(v73 + 12) = v50;
      *(_DWORD *)(v73 + 8) = (v62 << 22) | (v60 + v61);
LABEL_69:
      v60 = (unsigned int)(v60 + 1);
      v64 += 5;
      if ( (int)v60 >= array.m_size )
      {
        v51 = v81;
        goto LABEL_71;
      }
    }
    v71 = 5i64 * (v70 - v69);
    v72 = *(_QWORD *)(v67 + 288);
LABEL_66:
    v73 = v72 + 4 * v71;
    goto LABEL_67;
  }
LABEL_71:
  m_numOriginalFaces = m_instancePtr->m_numOriginalFaces;
  if ( v51 < m_numOriginalFaces )
  {
    if ( m_instancePtr->m_faceMap.m_size )
      v51 = m_instancePtr->m_faceMap.m_data[*(_QWORD *)&v82.m_data[3]];
    if ( v51 == -1 )
      v75 = 0i64;
    else
      v75 = &m_instancePtr->m_instancedFaces.m_data[v51];
  }
  else
  {
    v75 = &m_instancePtr->m_ownedFaces.m_data[v51 - m_numOriginalFaces];
  }
  v76 = (char *)v20 - (char *)v90;
  v75->m_startEdgeIndex = v80;
  v75->m_startUserEdgeIndex = v82.m_data[2];
  *(_DWORD *)&v75->m_numEdges = v85;
  *(_DWORD *)&v75->m_clusterIndex = v82.m_data[1];
  v82.m_edge.m_oppositeEdge = 0;
  if ( (v82.m_edge.m_oppositeFace & 0x80000000) == 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, _QWORD, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      *(_QWORD *)&v82.m_edge.m_a,
      4 * v82.m_edge.m_oppositeFace,
      v60);
  *(_QWORD *)&v82.m_edge.m_a = 0i64;
  v82.m_edge.m_oppositeFace = 0x80000000;
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkaiNavMeshInstance::AddEdgeContext *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      40 * (array.m_capacityAndFlags & 0x3FFFFFFFu),
      v60);
  return (unsigned int)(v76 / 24);
}

// File Line: 183
// RVA: 0xC2CD80
void __fastcall hkaiNavMeshCutter::matchNewEdgesFromOriginalEdge(
        hkaiNavMeshCutter *this,
        hkaiStreamingCollection *collection,
        hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *pairsA,
        hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *pairsB)
{
  int m_size; // esi
  hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *v6; // r14
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_ownedEdges; // r9
  hkaiStreamingCollection::InstanceInfo *m_data; // r8
  float v9; // xmm6_4
  hkaiNavMeshInstance *m_instancePtr; // r13
  int v11; // esi
  hkaiNavMeshInstance *v12; // r12
  __int64 v13; // r15
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_instancedEdges; // r8
  char *v15; // rbx
  hkaiNavMesh::Edge *v16; // rax
  __int64 m_a; // rcx
  int m_numOriginalVertices; // edx
  __m128 *p_m_quad; // rcx
  __int64 m_b; // rax
  __m128 *v21; // rax
  __m128 v22; // xmm2
  __m128 v23; // xmm2
  __int64 v24; // rax
  __int64 v25; // rcx
  signed __int64 v26; // rdx
  int v27; // eax
  int v28; // esi
  __int64 v29; // r15
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v30; // r8
  hkaiNavMeshCutter::FaceEdgePair *v31; // rbx
  hkaiNavMesh::Edge *v32; // rax
  __int64 v33; // rcx
  int v34; // edx
  __m128 *v35; // rcx
  __int64 v36; // rax
  __m128 *v37; // rax
  __m128 v38; // xmm2
  __m128 v39; // xmm2
  __int64 v40; // rax
  __int64 v41; // rcx
  char *v42; // rdx
  unsigned int v43; // eax
  __m128 *v44; // rdx
  hkaiNavMeshEdgeMatchingParameters *v45; // r11
  hkaiNavMesh *m_pntr; // rax
  float v47; // xmm6_4
  hkResultEnum v48; // ebx
  __int64 v49; // r15
  hkResultEnum m_enum; // eax
  int v51; // esi
  __int64 v52; // rbx
  int m_numOriginalEdges; // eax
  int v54; // ecx
  __int64 v55; // rcx
  hkaiNavMesh::Edge *v56; // rax
  hkaiNavMesh::Edge *v57; // r10
  int v58; // eax
  signed int v59; // ecx
  __int64 v60; // rcx
  hkaiNavMesh::Edge *v61; // rax
  __int64 v62; // rax
  __int64 v63; // rdx
  __int64 v64; // rcx
  char *v65; // r8
  int v66; // eax
  __int64 v67; // rax
  hkaiNavMeshCutter::FaceEdgePair *v68; // rdx
  __int64 v69; // rcx
  char *v70; // r8
  unsigned int v71; // eax
  int v72; // eax
  hkResultEnum v73; // ecx
  __int64 v74; // r15
  int v75; // esi
  int faceAIdx; // r8d
  hkaiNavMeshGenerationUtils *v77; // r10
  __int64 v78; // rbx
  hkaiNavMeshCutter::FaceEdgePair *v79; // rcx
  hkaiNavMeshCutter::FaceEdgePair *v80; // rax
  int m_edgeKey; // edx
  int v82; // ecx
  hkaiNavMeshGenerationUtils::EdgePair *v83; // rcx
  hkaiStreamingCollection *v84; // rdi
  int i; // ebx
  int v86; // ebx
  unsigned __int64 v87; // r8
  unsigned int m_edgeAIdx; // edx
  __int64 v89; // rcx
  int v90; // edx
  hkaiNavMeshInstance *v91; // r10
  int v92; // eax
  __int64 v93; // rcx
  hkaiNavMesh::Edge *v94; // rax
  hkaiNavMesh::Edge *v95; // r10
  unsigned int m_data_high; // edx
  __int64 v97; // rcx
  int v98; // edx
  hkaiNavMeshInstance *v99; // r11
  int v100; // eax
  __int64 v101; // rcx
  hkaiNavMesh::Edge *v102; // rax
  hkaiNavMesh::Edge *v103; // rdx
  hkArrayBase<hkaiNavMeshGenerationUtils::EdgePair> array; // [rsp+50h] [rbp-90h] BYREF
  unsigned int v105; // [rsp+60h] [rbp-80h]
  hkaiNavMeshGenerationUtils::EdgePair edgePair; // [rsp+68h] [rbp-78h] BYREF
  hkVector4f up; // [rsp+A0h] [rbp-40h] BYREF
  hkSimdFloat32 result; // [rsp+B0h] [rbp-30h] BYREF
  __m128 *v109; // [rsp+110h] [rbp+30h]
  hkaiStreamingCollection *collectiona; // [rsp+118h] [rbp+38h]
  hkResult vars0[2]; // [rsp+120h] [rbp+40h] BYREF

  m_size = pairsA->m_size;
  v6 = pairsA;
  p_m_ownedEdges = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)this;
  if ( m_size && pairsB->m_size )
  {
    m_data = collection->m_instances.m_data;
    *(float *)&v105 = this->m_minEdgeMatchingLength * this->m_minEdgeMatchingLength;
    LODWORD(v9) = _mm_shuffle_ps((__m128)v105, (__m128)v105, 0).m128_u32[0];
    m_instancePtr = m_data[v6->m_data->m_edgeKey >> 22].m_instancePtr;
    v11 = m_size - 1;
    v12 = m_data[pairsB->m_data->m_edgeKey >> 22].m_instancePtr;
    v13 = v11;
    *(_QWORD *)&edgePair.m_edgeAIdx = v12;
    if ( v11 >= 0 )
    {
      p_m_ownedEdges = &m_instancePtr->m_ownedEdges;
      p_m_instancedEdges = &m_instancePtr->m_instancedEdges;
      do
      {
        v15 = (char *)&v6->m_data[v13];
        v16 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__20(
                m_instancePtr->m_originalEdges,
                m_instancePtr->m_numOriginalEdges,
                p_m_instancedEdges,
                p_m_ownedEdges,
                &m_instancePtr->m_edgeMap,
                *(_DWORD *)v15 & 0x3FFFFF);
        m_a = v16->m_a;
        m_numOriginalVertices = m_instancePtr->m_numOriginalVertices;
        if ( (int)m_a >= m_numOriginalVertices )
          p_m_quad = &m_instancePtr->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices].m_quad;
        else
          p_m_quad = &m_instancePtr->m_originalVertices[m_a].m_quad;
        m_b = v16->m_b;
        if ( (int)m_b >= m_numOriginalVertices )
          v21 = &m_instancePtr->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices].m_quad;
        else
          v21 = &m_instancePtr->m_originalVertices[m_b].m_quad;
        v22 = _mm_sub_ps(*p_m_quad, *v21);
        v23 = _mm_mul_ps(v22, v22);
        if ( (float)((float)(_mm_shuffle_ps(v23, v23, 85).m128_f32[0] + _mm_shuffle_ps(v23, v23, 0).m128_f32[0])
                   + _mm_shuffle_ps(v23, v23, 170).m128_f32[0]) < v9 )
        {
          v24 = --v6->m_size;
          if ( (_DWORD)v24 != v11 )
          {
            v25 = 2i64;
            v26 = (char *)&v6->m_data[v24] - v15;
            do
            {
              v27 = *(_DWORD *)&v15[v26];
              v15 += 4;
              *((_DWORD *)v15 - 1) = v27;
              --v25;
            }
            while ( v25 );
          }
        }
        --v11;
        --v13;
      }
      while ( v13 >= 0 );
      v12 = *(hkaiNavMeshInstance **)&edgePair.m_edgeAIdx;
    }
    v28 = pairsB->m_size - 1;
    v29 = v28;
    if ( v28 >= 0 )
    {
      p_m_ownedEdges = &v12->m_ownedEdges;
      v30 = &v12->m_instancedEdges;
      do
      {
        v31 = &pairsB->m_data[v29];
        v32 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__20(
                v12->m_originalEdges,
                v12->m_numOriginalEdges,
                v30,
                p_m_ownedEdges,
                &v12->m_edgeMap,
                v31->m_edgeKey & 0x3FFFFF);
        v33 = v32->m_a;
        v34 = v12->m_numOriginalVertices;
        if ( (int)v33 >= v34 )
          v35 = &v12->m_ownedVertices.m_data[(int)v33 - v34].m_quad;
        else
          v35 = &v12->m_originalVertices[v33].m_quad;
        v36 = v32->m_b;
        if ( (int)v36 >= v34 )
          v37 = &v12->m_ownedVertices.m_data[(int)v36 - v34].m_quad;
        else
          v37 = &v12->m_originalVertices[v36].m_quad;
        v38 = _mm_sub_ps(*v35, *v37);
        v39 = _mm_mul_ps(v38, v38);
        if ( (float)((float)(_mm_shuffle_ps(v39, v39, 85).m128_f32[0] + _mm_shuffle_ps(v39, v39, 0).m128_f32[0])
                   + _mm_shuffle_ps(v39, v39, 170).m128_f32[0]) < v9 )
        {
          v40 = --pairsB->m_size;
          if ( (_DWORD)v40 != v28 )
          {
            v41 = 2i64;
            v42 = (char *)((char *)&pairsB->m_data[v40] - (char *)v31);
            do
            {
              v43 = *(unsigned int *)((char *)&v31->m_edgeKey + (_QWORD)v42);
              v31 = (hkaiNavMeshCutter::FaceEdgePair *)((char *)v31 + 4);
              v31[-1].m_faceKey = v43;
              --v41;
            }
            while ( v41 );
          }
        }
        --v28;
        --v29;
      }
      while ( v29 >= 0 );
      v6 = *(hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> **)&vars0[0].m_enum;
    }
    v44 = v109;
    array.m_data = 0i64;
    array.m_size = 0;
    v45 = (hkaiNavMeshEdgeMatchingParameters *)&v109[6];
    array.m_capacityAndFlags = 0x80000000;
    m_pntr = m_instancePtr->m_originalMesh.m_pntr;
    LODWORD(v47) = _mm_shuffle_ps((__m128)v109[10].m128_u32[2], (__m128)v109[10].m128_u32[2], 0).m128_u32[0];
    *(_QWORD *)&edgePair.m_edgeAIdx = v109 + 6;
    up.m_quad = v109[6];
    if ( (m_pntr->m_flags.m_storage & 1) != 0 || (v12->m_originalMesh.m_pntr->m_flags.m_storage & 1) != 0 )
      up.m_quad = 0i64;
    v48 = v6->m_size - 1;
    vars0[0].m_enum = v48;
    v49 = v48;
    if ( v48 >= HK_SUCCESS )
    {
      m_enum = v48;
      while ( 1 )
      {
        v51 = pairsB->m_size - 1;
        v52 = v51;
        if ( v51 >= 0 )
          break;
LABEL_65:
        --m_enum;
        --v49;
        vars0[0].m_enum = m_enum;
        if ( v49 < 0 )
        {
          v45 = *(hkaiNavMeshEdgeMatchingParameters **)&edgePair.m_edgeAIdx;
          v44 = v109;
          goto LABEL_67;
        }
      }
      while ( 1 )
      {
        hkaiNavMeshCutterHelper::edgeEndpointDistance(
          &result,
          m_instancePtr,
          v12,
          &up,
          v6->m_data[v49].m_edgeKey & 0x3FFFFF,
          pairsB->m_data[v52].m_edgeKey & 0x3FFFFF);
        if ( result.m_real.m128_f32[0] < v47 )
          break;
        --v51;
        if ( --v52 < 0 )
          goto LABEL_64;
      }
      m_numOriginalEdges = m_instancePtr->m_numOriginalEdges;
      v54 = v6->m_data[v49].m_edgeKey & 0x3FFFFF;
      if ( v54 < m_numOriginalEdges )
      {
        if ( m_instancePtr->m_edgeMap.m_size )
          v54 = m_instancePtr->m_edgeMap.m_data[v54];
        if ( v54 == -1 )
        {
          v57 = 0i64;
          goto LABEL_48;
        }
        v55 = v54;
        v56 = m_instancePtr->m_instancedEdges.m_data;
      }
      else
      {
        v55 = v54 - m_numOriginalEdges;
        v56 = m_instancePtr->m_ownedEdges.m_data;
      }
      v57 = &v56[v55];
LABEL_48:
      v57->m_oppositeEdge = pairsB->m_data[v51].m_edgeKey;
      v57->m_oppositeFace = pairsB->m_data[v51].m_faceKey;
      v58 = v12->m_numOriginalEdges;
      v59 = pairsB->m_data[v51].m_edgeKey & 0x3FFFFF;
      if ( v59 < v58 )
      {
        if ( v12->m_edgeMap.m_size )
          v59 = v12->m_edgeMap.m_data[v59];
        if ( v59 == -1 )
        {
          p_m_ownedEdges = 0i64;
          goto LABEL_56;
        }
        v60 = v59;
        v61 = v12->m_instancedEdges.m_data;
      }
      else
      {
        v60 = v59 - v58;
        v61 = v12->m_ownedEdges.m_data;
      }
      p_m_ownedEdges = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&v61[v60];
LABEL_56:
      p_m_ownedEdges->m_size = v6->m_data[v49].m_edgeKey;
      p_m_ownedEdges->m_capacityAndFlags = v6->m_data[v49].m_faceKey;
      v62 = --v6->m_size;
      if ( (_DWORD)v62 != vars0[0].m_enum )
      {
        v63 = (__int64)&v6->m_data[v49];
        v64 = 2i64;
        v65 = (char *)&v6->m_data[v62] - v63;
        do
        {
          v66 = *(_DWORD *)&v65[v63];
          v63 += 4i64;
          *(_DWORD *)(v63 - 4) = v66;
          --v64;
        }
        while ( v64 );
      }
      v67 = --pairsB->m_size;
      if ( (_DWORD)v67 != v51 )
      {
        v68 = &pairsB->m_data[v51];
        v69 = 2i64;
        v70 = (char *)((char *)&pairsB->m_data[v67] - (char *)v68);
        do
        {
          v71 = *(unsigned int *)((char *)&v68->m_edgeKey + (_QWORD)v70);
          v68 = (hkaiNavMeshCutter::FaceEdgePair *)((char *)v68 + 4);
          v68[-1].m_faceKey = v71;
          --v69;
        }
        while ( v69 );
      }
      if ( m_instancePtr->m_sectionUid != v12->m_sectionUid )
      {
        v57->m_flags.m_storage |= 0x40u;
        LOBYTE(p_m_ownedEdges[1].m_data) |= 0x40u;
      }
LABEL_64:
      m_enum = vars0[0].m_enum;
      goto LABEL_65;
    }
LABEL_67:
    v72 = v6->m_size;
    if ( v72 && pairsB->m_size )
    {
      v73 = HK_SUCCESS;
      vars0[0].m_enum = HK_SUCCESS;
      if ( v72 > 0 )
      {
        v74 = 0i64;
        do
        {
          v75 = 0;
          faceAIdx = v6->m_data[v74].m_faceKey & 0x3FFFFF;
          p_m_ownedEdges = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v6->m_data[v74].m_edgeKey & 0x3FFFFF);
          v105 = v6->m_data[v74].m_edgeKey & 0x3FFFFF;
          if ( pairsB->m_size > 0 )
          {
            v77 = (hkaiNavMeshGenerationUtils *)&v44[7];
            v78 = 0i64;
            up.m_quad.m128_u64[0] = (unsigned __int64)&v44[7];
            do
            {
              if ( hkaiNavMeshGenerationUtils::calculateConnectivity(
                     v77,
                     v45,
                     (hkSimdFloat32 *)m_instancePtr,
                     v12,
                     (int)p_m_ownedEdges,
                     pairsB->m_data[v78].m_edgeKey & 0x3FFFFF,
                     faceAIdx,
                     pairsB->m_data[v78].m_faceKey & 0x3FFFFF,
                     &edgePair) == CONNECT_SUCCESS )
              {
                v79 = pairsB->m_data;
                v80 = v6->m_data;
                m_edgeKey = v6->m_data[v74].m_edgeKey;
                edgePair.m_edgeAIdx = m_edgeKey;
                edgePair.m_faceAIdx = v80[v74].m_faceKey;
                edgePair.m_edgeBIdx = v79[v78].m_edgeKey;
                LODWORD(v80) = v79[v78].m_faceKey;
                v82 = array.m_size;
                edgePair.m_faceBIdx = (int)v80;
                if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
                {
                  hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 48);
                  v82 = array.m_size;
                  m_edgeKey = edgePair.m_edgeAIdx;
                }
                v83 = &array.m_data[v82];
                v83->m_edgeAIdx = m_edgeKey;
                v83->m_edgeBIdx = edgePair.m_edgeBIdx;
                v83->m_faceAIdx = edgePair.m_faceAIdx;
                v83->m_faceBIdx = edgePair.m_faceBIdx;
                v83->m_distanceSquared = edgePair.m_distanceSquared;
                v83->m_edgeAlignment = edgePair.m_edgeAlignment;
                v83->m_overlap = edgePair.m_overlap;
                *(_DWORD *)&v83->m_isValid = *(_DWORD *)&edgePair.m_isValid;
                v83->m_tStartA = edgePair.m_tStartA;
                v83->m_tEndA = edgePair.m_tEndA;
                v83->m_tStartB = edgePair.m_tStartB;
                v83->m_tEndB = edgePair.m_tEndB;
                ++array.m_size;
              }
              faceAIdx = v105;
              p_m_ownedEdges = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)v105;
              v77 = (hkaiNavMeshGenerationUtils *)up.m_quad.m128_u64[0];
              v45 = *(hkaiNavMeshEdgeMatchingParameters **)&edgePair.m_edgeAIdx;
              ++v75;
              ++v78;
            }
            while ( v75 < pairsB->m_size );
            v73 = vars0[0].m_enum;
          }
          v45 = *(hkaiNavMeshEdgeMatchingParameters **)&edgePair.m_edgeAIdx;
          v44 = v109;
          ++v73;
          ++v74;
          vars0[0].m_enum = v73;
        }
        while ( v73 < v6->m_size );
      }
      if ( array.m_size )
      {
        if ( array.m_size > 1 )
          hkAlgorithm::quickSortRecursive<hkaiNavMeshGenerationUtils::EdgePair,hkAlgorithm::less<hkaiNavMeshGenerationUtils::EdgePair>>(
            array.m_data,
            0,
            array.m_size - 1,
            0);
        hkaiNavMeshGenerationUtils::_resolveConflictingEdgePairs(vars0, &array);
        *(_QWORD *)&edgePair.m_faceAIdx = 0i64;
        edgePair.m_distanceSquared = 0.0;
        edgePair.m_edgeAlignment = -0.0;
        hkaiNavMeshGenerationUtils::_gatherAndSortSplits<hkaiNavMeshInstance>(
          (hkaiNavMeshGenerationUtils *)vars0,
          (hkResult *)m_instancePtr,
          v12,
          (hkaiNavMeshInstance *)&array,
          (hkArrayBase<hkaiNavMeshGenerationUtils::EdgePair> *)&edgePair.m_faceAIdx);
        v84 = collectiona;
        for ( i = 0;
              i < SLODWORD(edgePair.m_distanceSquared);
              i += cutter_splitEdges(
                     v84,
                     *(_DWORD *)(*(_QWORD *)&edgePair.m_faceAIdx + 24i64 * i),
                     (hkaiNavMeshGenerationUtils::EdgeSplit *)(*(_QWORD *)&edgePair.m_faceAIdx + 24i64 * i),
                     1) )
        {
          ;
        }
        v86 = 0;
        if ( array.m_size > 0 )
        {
          v87 = 0i64;
          while ( 1 )
          {
            p_m_ownedEdges = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)array.m_data;
            if ( array.m_data[v87 / 3].m_isValid )
              break;
LABEL_106:
            ++v86;
            v87 += 3i64;
            if ( v86 >= array.m_size )
              goto LABEL_107;
          }
          m_edgeAIdx = array.m_data[v87 / 3].m_edgeAIdx;
          v89 = m_edgeAIdx >> 22;
          v90 = m_edgeAIdx & 0x3FFFFF;
          v91 = v84->m_instances.m_data[v89].m_instancePtr;
          v92 = v91->m_numOriginalEdges;
          if ( v90 < v92 )
          {
            if ( v91->m_edgeMap.m_size )
              v90 = v91->m_edgeMap.m_data[v90];
            if ( v90 == -1 )
            {
              v95 = 0i64;
              goto LABEL_96;
            }
            v93 = v90;
            v94 = v91->m_instancedEdges.m_data;
          }
          else
          {
            v93 = v90 - v92;
            v94 = v91->m_ownedEdges.m_data;
          }
          v95 = &v94[v93];
LABEL_96:
          v95->m_oppositeEdge = array.m_data[v87 / 3].m_edgeBIdx;
          v95->m_oppositeFace = p_m_ownedEdges[v87].m_capacityAndFlags;
          m_data_high = HIDWORD(p_m_ownedEdges[v87].m_data);
          v97 = m_data_high >> 22;
          v98 = m_data_high & 0x3FFFFF;
          v99 = v84->m_instances.m_data[v97].m_instancePtr;
          v100 = v99->m_numOriginalEdges;
          if ( v98 < v100 )
          {
            if ( v99->m_edgeMap.m_size )
              v98 = v99->m_edgeMap.m_data[v98];
            if ( v98 == -1 )
            {
              v103 = 0i64;
              goto LABEL_104;
            }
            v101 = v98;
            v102 = v99->m_instancedEdges.m_data;
          }
          else
          {
            v101 = v98 - v100;
            v102 = v99->m_ownedEdges.m_data;
          }
          v103 = &v102[v101];
LABEL_104:
          v103->m_oppositeEdge = (unsigned int)p_m_ownedEdges[v87].m_data;
          v103->m_oppositeFace = p_m_ownedEdges[v87].m_size;
          if ( m_instancePtr->m_sectionUid != v12->m_sectionUid )
          {
            v95->m_flags.m_storage |= 0x40u;
            v103->m_flags.m_storage |= 0x40u;
          }
          goto LABEL_106;
        }
LABEL_107:
        edgePair.m_distanceSquared = 0.0;
        if ( edgePair.m_edgeAlignment >= 0.0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            *(void **)&edgePair.m_faceAIdx,
            24 * (LODWORD(edgePair.m_edgeAlignment) & 0x3FFFFFFF));
        *(_QWORD *)&edgePair.m_faceAIdx = 0i64;
        edgePair.m_edgeAlignment = -0.0;
      }
    }
    array.m_size = 0;
    if ( array.m_capacityAndFlags >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkaiNavMeshGenerationUtils::EdgePair *, _QWORD, hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        array.m_data,
        48 * (array.m_capacityAndFlags & 0x3FFFFFFFu),
        p_m_ownedEdges);
  }
}


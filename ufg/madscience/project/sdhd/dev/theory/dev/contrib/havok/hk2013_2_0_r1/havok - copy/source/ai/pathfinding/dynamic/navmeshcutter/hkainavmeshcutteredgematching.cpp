// File Line: 27
// RVA: 0xC2D6C0
unsigned __int64 __fastcall cutter_splitEdges(hkaiStreamingCollection *collection, int faceKey, hkaiNavMeshGenerationUtils::EdgeSplit *splits, bool markOrphanedEdges)
{
  hkaiStreamingCollection::InstanceInfo *v4; // rax
  __int64 v5; // rcx
  hkaiNavMeshInstance *v6; // r14
  __int64 v7; // rdx
  hkaiNavMesh::Face *v8; // rcx
  hkaiNavMeshGenerationUtils::EdgeSplit *v9; // rbx
  __int64 v10; // rdx
  int v11; // er12
  signed int v12; // esi
  int v13; // er9
  int v14; // ecx
  __int64 v15; // rdx
  __int64 v16; // rcx
  signed int v17; // edi
  __int64 v18; // rbx
  signed int v19; // edx
  int v20; // er9
  _DWORD *v21; // rdi
  __int64 v22; // rcx
  hkaiNavMeshGenerationUtils::EdgeSplit *v23; // r15
  hkResultEnum v24; // edi
  __m128 v25; // xmm0
  hkaiNavMesh::Edge *v26; // r13
  signed __int64 v27; // r12
  __int64 v28; // rax
  signed int v29; // ecx
  __m128 *v30; // rax
  __m128 v31; // xmm2
  __int64 v32; // rax
  __m128 *v33; // rax
  int v34; // esi
  int v35; // edi
  signed __int64 v36; // rbx
  hkaiNavMeshInstance::AddEdgeContext *v37; // rdx
  int v38; // eax
  signed __int64 v39; // rax
  __m128 v40; // xmm0
  __int64 v41; // rax
  signed int v42; // ecx
  __m128 *v43; // rax
  __m128 v44; // xmm2
  __int64 v45; // rax
  __m128 *v46; // rax
  int v47; // esi
  int v48; // edi
  signed __int64 v49; // rbx
  hkaiNavMeshInstance::AddEdgeContext *v50; // rdx
  int v51; // eax
  hkResultEnum v52; // edi
  hkResultEnum v53; // er13
  int v54; // er12
  int v55; // esi
  int v56; // eax
  int v57; // eax
  int v58; // er9
  __int64 v59; // rdx
  hkHalf *v60; // rdi
  __int64 v61; // rcx
  hkaiNavMesh::Edge *v62; // rax
  __int64 v63; // r9
  int v64; // er12
  int v65; // er10
  __int64 v66; // r11
  signed __int64 v67; // rdi
  unsigned int v68; // edx
  signed int v69; // eax
  __int64 v70; // r8
  hkResult *v71; // rax
  int v72; // eax
  int v73; // edx
  signed __int64 v74; // rcx
  __int64 v75; // rax
  signed __int64 v76; // rdx
  int v77; // eax
  hkaiNavMesh::Face *v78; // rcx
  __int64 v79; // r15
  hkResult result; // [rsp+30h] [rbp-98h]
  hkaiNavMeshInstance::AddEdgeContext *array; // [rsp+38h] [rbp-90h]
  int numEdges; // [rsp+40h] [rbp-88h]
  int v84; // [rsp+44h] [rbp-84h]
  int v85; // [rsp+48h] [rbp-80h]
  int v86; // [rsp+4Ch] [rbp-7Ch]
  hkaiNavMeshInstance::AddEdgeContext v87; // [rsp+50h] [rbp-78h]
  hkaiNavMeshInstance::AddEdgeContext t; // [rsp+78h] [rbp-50h]
  int v89; // [rsp+A0h] [rbp-28h]
  int v90; // [rsp+A8h] [rbp-20h]
  hkVector4f v; // [rsp+B8h] [rbp-10h]
  hkVector4f v92; // [rsp+C8h] [rbp+0h]
  __int64 v93; // [rsp+128h] [rbp+60h]
  hkResult v94; // [rsp+130h] [rbp+68h]
  hkaiNavMeshGenerationUtils::EdgeSplit *v95; // [rsp+138h] [rbp+70h]

  *(_DWORD *)&v87.m_edge.m_flags.m_storage = (unsigned int)faceKey >> 22;
  v4 = collection->m_instances.m_data;
  v5 = faceKey & 0x3FFFFF;
  v86 = faceKey & 0x3FFFFF;
  v6 = v4[(unsigned int)faceKey >> 22].m_instancePtr;
  v7 = v5;
  *(_QWORD *)&v87.m_data[3] = v5;
  v8 = v6->m_ownedFaces.m_data;
  v9 = splits;
  v10 = v7 - v6->m_numOriginalFaces;
  v11 = v8[v10].m_startEdgeIndex;
  t.m_edge.m_b = v8[v10].m_startUserEdgeIndex;
  LODWORD(v4) = *(_DWORD *)&v8[v10].m_numEdges;
  v87.m_data[0] = v11;
  v85 = (signed int)v4;
  v12 = (signed __int16)v4;
  v86 = *(_DWORD *)&v8[v10].m_clusterIndex;
  v13 = 2 * (signed __int16)v4;
  v87.m_data[2] = v8[v10].m_startUserEdgeIndex;
  LODWORD(v4) = *(_DWORD *)&v8[v10].m_numEdges;
  v89 = v11;
  v90 = (signed int)v4;
  LODWORD(v4) = *(_DWORD *)&v8[v10].m_clusterIndex;
  v14 = 0;
  v87.m_data[1] = (signed int)v4;
  LODWORD(v4) = v6->m_numOriginalEdges + v6->m_ownedEdges.m_size;
  array = 0i64;
  numEdges = 0;
  v84 = 2147483648;
  v85 = (signed int)v4;
  if ( v13 > 0 )
  {
    if ( v13 < 0 )
      v13 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v13, 40);
    v14 = numEdges;
  }
  v15 = v12 - v14;
  if ( v12 - v14 > 0 )
  {
    v16 = (__int64)&array[v14].m_edge.m_oppositeEdge;
    do
    {
      if ( v16 != 8 )
      {
        *(_QWORD *)v16 = -1i64;
        *(_DWORD *)(v16 + 8) = 4;
        *(_WORD *)(v16 + 28) = -1;
        *(_QWORD *)(v16 + 12) = 0i64;
        *(_QWORD *)(v16 + 20) = 0i64;
      }
      v16 += 40i64;
      --v15;
    }
    while ( v15 );
  }
  numEdges = v12;
  v17 = 0;
  if ( v12 > 0 )
  {
    v18 = 0i64;
    do
    {
      hkaiNavMeshInstance::getEdgeContext(v6, v11 + v17++, &array[v18]);
      ++v18;
    }
    while ( v17 < v12 );
    v9 = v95;
  }
  v19 = 0;
  *(_QWORD *)&v87.m_edge.m_a = 0i64;
  v87.m_edge.m_oppositeFace = 2147483648;
  v87.m_edge.m_oppositeEdge = 0;
  if ( v12 > 0 )
  {
    v20 = v12;
    if ( v12 < 0 )
      v20 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v87, v20, 4);
    v19 = v87.m_edge.m_oppositeEdge;
  }
  v21 = (_DWORD *)(*(_QWORD *)&v87.m_edge.m_a + 4i64 * v19);
  v22 = v12 - v19;
  if ( v12 - v19 > 0 )
  {
    while ( v22 )
    {
      *v21 = 0;
      ++v21;
      --v22;
    }
  }
  v87.m_edge.m_oppositeEdge = v12;
  v23 = v9;
  v24 = 0;
  result.m_enum = 0;
  do
  {
    v25 = (__m128)LODWORD(v23->m_tS);
    v26 = v6->m_ownedEdges.m_data;
    v27 = v11 + v23->m_edgeIdx - v6->m_numOriginalEdges;
    if ( v25.m128_f32[0] > *(float *)(*(_QWORD *)&v87.m_edge.m_a + 4i64 * v23->m_edgeIdx) )
    {
      v28 = v26[v27].m_a;
      v29 = v6->m_numOriginalVertices;
      if ( (signed int)v28 >= v29 )
        v30 = &v6->m_ownedVertices.m_data[(signed int)v28 - v29].m_quad;
      else
        v30 = &v6->m_originalVertices[v28].m_quad;
      v31 = *v30;
      v32 = v26[v27].m_b;
      if ( (signed int)v32 >= v29 )
        v33 = &v6->m_ownedVertices.m_data[(signed int)v32 - v29].m_quad;
      else
        v33 = &v6->m_originalVertices[v32].m_quad;
      v34 = v29 + v6->m_ownedVertices.m_size;
      v.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*v33, v31), _mm_shuffle_ps(v25, v25, 0)), v31);
      hkaiNavMeshInstance::appendVertices(v6, &v, 1);
      v35 = v23->m_edgeIdx + v24;
      v36 = v35;
      t.m_edge.m_a = array[v35].m_edge.m_a;
      t.m_edge.m_b = array[v35].m_edge.m_b;
      t.m_edge.m_oppositeEdge = array[v35].m_edge.m_oppositeEdge;
      t.m_edge.m_oppositeFace = array[v35].m_edge.m_oppositeFace;
      *(_DWORD *)&t.m_edge.m_flags.m_storage = *(_DWORD *)&array[v35].m_edge.m_flags.m_storage;
      t.m_data[0] = array[v35].m_data[0];
      t.m_data[1] = array[v35].m_data[1];
      t.m_data[2] = array[v35].m_data[2];
      t.m_data[3] = array[v35].m_data[3];
      *(_DWORD *)&t.m_cutInfo = *(_DWORD *)&array[v35].m_cutInfo;
      hkArrayBase<hkaiNavMeshInstance::AddEdgeContext>::_insertAt(
        (hkArrayBase<hkaiNavMeshInstance::AddEdgeContext> *)&array,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        v35,
        &t);
      v37 = array;
      v38 = v35 + 1;
      v24 = result.m_enum + 1;
      v39 = v38;
      ++result.m_enum;
      array[v39].m_edge.m_a = v34;
      *(_QWORD *)&v37[v39].m_edge.m_oppositeEdge = -1i64;
      v37[v36].m_edge.m_b = v34;
    }
    *(float *)(*(_QWORD *)&v87.m_edge.m_a + 4i64 * v23->m_edgeIdx) = v23->m_tE;
    *v23->m_sharedPairEdgeIdx = *v23->m_sharedPairEdgeIdx & 0xFFC00000 | (v23->m_edgeIdx + v24 + v85);
    v40 = (__m128)LODWORD(v23->m_tE);
    if ( v40.m128_f32[0] < 1.0 )
    {
      v41 = v26[v27].m_a;
      v42 = v6->m_numOriginalVertices;
      if ( (signed int)v41 >= v42 )
        v43 = &v6->m_ownedVertices.m_data[(signed int)v41 - v42].m_quad;
      else
        v43 = &v6->m_originalVertices[v41].m_quad;
      v44 = *v43;
      v45 = v26[v27].m_b;
      if ( (signed int)v45 >= v42 )
        v46 = &v6->m_ownedVertices.m_data[(signed int)v45 - v42].m_quad;
      else
        v46 = &v6->m_originalVertices[v45].m_quad;
      v47 = v42 + v6->m_ownedVertices.m_size;
      v92.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*v46, v44), _mm_shuffle_ps(v40, v40, 0)), v44);
      hkaiNavMeshInstance::appendVertices(v6, &v92, 1);
      v48 = v23->m_edgeIdx + v24;
      v49 = v48;
      v87.m_edge.m_a = array[v48].m_edge.m_a;
      v87.m_edge.m_b = array[v48].m_edge.m_b;
      v87.m_edge.m_oppositeEdge = array[v48].m_edge.m_oppositeEdge;
      v87.m_edge.m_oppositeFace = array[v48].m_edge.m_oppositeFace;
      *(_DWORD *)&v87.m_edge.m_flags.m_storage = *(_DWORD *)&array[v48].m_edge.m_flags.m_storage;
      v87.m_data[0] = array[v48].m_data[0];
      v87.m_data[1] = array[v48].m_data[1];
      v87.m_data[2] = array[v48].m_data[2];
      v87.m_data[3] = array[v48].m_data[3];
      *(_DWORD *)&v87.m_cutInfo = *(_DWORD *)&array[v48].m_cutInfo;
      hkArrayBase<hkaiNavMeshInstance::AddEdgeContext>::_insertAt(
        (hkArrayBase<hkaiNavMeshInstance::AddEdgeContext> *)&array,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        v48,
        &v87);
      v50 = array;
      v51 = v48 + 1;
      v52 = result.m_enum;
      array[v49].m_edge.m_b = v47;
      v24 = v52 + 1;
      *(_QWORD *)&v50[v49].m_edge.m_oppositeEdge = -1i64;
      result.m_enum = v24;
      v50[v51].m_edge.m_a = v47;
    }
    v53 = v94.m_enum;
    v11 = v87.m_data[0];
    ++v23;
  }
  while ( v23->m_faceIdx == v94.m_enum );
  v54 = v86;
  if ( (_WORD)v85 != (_WORD)numEdges && v86 < v6->m_faceClearanceIndices.m_size )
    v6->m_faceClearanceIndices.m_data[*(_QWORD *)&v87.m_data[3]] = -1;
  v55 = v24 + v6->m_globalClearanceCache.m_size;
  v56 = v6->m_globalClearanceCache.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v56 < v55 )
  {
    v57 = 2 * v56;
    v58 = v24 + v6->m_globalClearanceCache.m_size;
    if ( v55 < v57 )
      v58 = v57;
    hkArrayUtil::_reserve(
      &v94,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_globalClearanceCache,
      v58,
      2);
  }
  v59 = v6->m_globalClearanceCache.m_size;
  v60 = &v6->m_globalClearanceCache.m_data[v59];
  v61 = v55 - (signed int)v59;
  if ( v55 - (signed int)v59 > 0 )
  {
    while ( v61 )
    {
      v60->m_value = 32639;
      ++v60;
      --v61;
    }
  }
  v6->m_globalClearanceCache.m_size = v55;
  LOWORD(v90) = numEdges;
  v62 = hkaiNavMeshInstance::appendEdges(v6, array, numEdges);
  v63 = 0i64;
  if ( numEdges > 0 )
  {
    v64 = v85;
    v65 = *(_DWORD *)&v87.m_edge.m_flags.m_storage;
    v66 = v93;
    v67 = (signed __int64)&v62->m_oppositeEdge;
    while ( 1 )
    {
      v68 = *(_DWORD *)v67;
      if ( *(_DWORD *)v67 == -1 )
      {
        *(_QWORD *)v67 = -1i64;
        *(_BYTE *)(v67 + 8) = 4;
        goto LABEL_71;
      }
      if ( *(_BYTE *)(v67 + 8) & 0x40 )
        v69 = v68 >> 22;
      else
        v69 = v6->m_runtimeId;
      if ( v68 == -1 )
        v69 = -1;
      v70 = *(_QWORD *)(*(_QWORD *)(v66 + 32) + 48i64 * v69);
      if ( *(_DWORD *)(v70 + 328) )
      {
        v71 = &v94;
        LOBYTE(v94.m_enum) = *(_BYTE *)((*(_DWORD *)(v67 + 4) & 0x3FFFFF) + *(_QWORD *)(v70 + 320));
      }
      else
      {
        LOBYTE(v93) = 0;
        v71 = (hkResult *)&v93;
      }
      if ( v71->m_enum & 1 )
        goto LABEL_71;
      v72 = *(_DWORD *)(v70 + 40);
      v73 = v68 & 0x3FFFFF;
      if ( v73 >= v72 )
        break;
      if ( *(_DWORD *)(v70 + 216) )
        v73 = *(_DWORD *)(*(_QWORD *)(v70 + 208) + 4i64 * v73);
      if ( v73 != -1 )
      {
        v74 = 5i64 * v73;
        v75 = *(_QWORD *)(v70 + 256);
        goto LABEL_68;
      }
      v76 = 0i64;
LABEL_69:
      *(_DWORD *)(v76 + 12) = v53;
      *(_DWORD *)(v76 + 8) = (v65 << 22) | (v63 + v64);
LABEL_71:
      v63 = (unsigned int)(v63 + 1);
      v67 += 20i64;
      if ( (signed int)v63 >= numEdges )
      {
        v54 = v86;
        goto LABEL_73;
      }
    }
    v74 = 5i64 * (v73 - v72);
    v75 = *(_QWORD *)(v70 + 288);
LABEL_68:
    v76 = v75 + 4 * v74;
    goto LABEL_69;
  }
LABEL_73:
  v77 = v6->m_numOriginalFaces;
  if ( v54 < v77 )
  {
    if ( v6->m_faceMap.m_size )
      v54 = v6->m_faceMap.m_data[*(_QWORD *)&v87.m_data[3]];
    if ( v54 == -1 )
      v78 = 0i64;
    else
      v78 = &v6->m_instancedFaces.m_data[v54];
  }
  else
  {
    v78 = &v6->m_ownedFaces.m_data[v54 - v77];
  }
  v79 = (char *)v23 - (char *)v95;
  v78->m_startEdgeIndex = v85;
  v78->m_startUserEdgeIndex = v87.m_data[2];
  *(_DWORD *)&v78->m_numEdges = v90;
  *(_DWORD *)&v78->m_clusterIndex = v87.m_data[1];
  v87.m_edge.m_oppositeEdge = 0;
  if ( (v87.m_edge.m_oppositeFace & 0x80000000) == 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, _QWORD, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      *(_QWORD *)&v87.m_edge.m_a,
      4 * v87.m_edge.m_oppositeFace,
      v63);
  *(_QWORD *)&v87.m_edge.m_a = 0i64;
  v87.m_edge.m_oppositeFace = 2147483648;
  numEdges = 0;
  if ( v84 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkaiNavMeshInstance::AddEdgeContext *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      array,
      40 * (v84 & 0x3FFFFFFFu),
      v63);
  return ((unsigned __int64)((unsigned __int128)(v79 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
       + (unsigned int)((signed __int64)((unsigned __int128)(v79 * (signed __int128)3074457345618258603i64) >> 64) >> 2);
}

// File Line: 183
// RVA: 0xC2CD80
void __fastcall hkaiNavMeshCutter::matchNewEdgesFromOriginalEdge(hkaiNavMeshCutter *this, hkaiStreamingCollection *collection, hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *pairsA, hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *pairsB)
{
  int v4; // esi
  hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *v5; // rdi
  hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *v6; // r14
  signed __int64 v7; // r9
  hkaiStreamingCollection::InstanceInfo *v8; // r8
  float v9; // xmm6_4
  hkaiNavMeshInstance *v10; // r13
  __int64 v11; // rax
  int v12; // esi
  hkaiNavMeshInstance *v13; // r12
  __int64 v14; // r15
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v15; // r8
  char *v16; // rbx
  hkaiNavMesh::Edge *v17; // rax
  __int64 v18; // rcx
  signed int v19; // edx
  __m128 *v20; // rcx
  __int64 v21; // rax
  __m128 *v22; // rax
  __m128 v23; // xmm2
  __m128 v24; // xmm2
  __int64 v25; // rax
  signed __int64 v26; // rcx
  signed __int64 v27; // rdx
  int v28; // eax
  int v29; // esi
  __int64 v30; // r15
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v31; // r8
  char *v32; // rbx
  hkaiNavMesh::Edge *v33; // rax
  __int64 v34; // rcx
  signed int v35; // edx
  __m128 *v36; // rcx
  __int64 v37; // rax
  __m128 *v38; // rax
  __m128 v39; // xmm2
  __m128 v40; // xmm2
  __int64 v41; // rax
  signed __int64 v42; // rcx
  signed __int64 v43; // rdx
  int v44; // eax
  __m128i *v45; // rdx
  hkVector4f *v46; // r11
  hkaiNavMesh *v47; // rax
  float v48; // xmm6_4
  hkResultEnum v49; // ebx
  __int64 v50; // r15
  hkResultEnum v51; // eax
  int v52; // esi
  __int64 v53; // rbx
  int v54; // eax
  int v55; // ecx
  signed __int64 v56; // rcx
  hkaiNavMesh::Edge *v57; // rax
  signed __int64 v58; // r10
  int v59; // eax
  int v60; // ecx
  signed __int64 v61; // rcx
  hkaiNavMesh::Edge *v62; // rax
  __int64 v63; // rax
  signed __int64 v64; // rdx
  signed __int64 v65; // rcx
  signed __int64 v66; // r8
  int v67; // eax
  __int64 v68; // rax
  signed __int64 v69; // rdx
  signed __int64 v70; // rcx
  signed __int64 v71; // r8
  int v72; // eax
  int v73; // eax
  hkResultEnum v74; // ecx
  __int64 v75; // r15
  int v76; // esi
  int faceAIdx; // er8
  hkaiNavMeshEdgeMatchingParameters *v78; // r10
  __int64 v79; // rbx
  hkaiNavMeshCutter::FaceEdgePair *v80; // rcx
  hkaiNavMeshCutter::FaceEdgePair *v81; // rax
  int v82; // edx
  int v83; // ecx
  __int64 v84; // rcx
  hkaiStreamingCollection *v85; // rdi
  int i; // ebx
  int v87; // ebx
  __int64 v88; // r8
  unsigned int v89; // eax
  int v90; // edx
  hkaiNavMeshInstance *v91; // r10
  int v92; // eax
  signed __int64 v93; // rcx
  hkaiNavMesh::Edge *v94; // rax
  signed __int64 v95; // r10
  unsigned int v96; // eax
  int v97; // edx
  hkaiNavMeshInstance *v98; // r11
  int v99; // eax
  signed __int64 v100; // rcx
  hkaiNavMesh::Edge *v101; // rax
  signed __int64 v102; // rdx
  hkaiNavMeshGenerationUtils::EdgePair *array; // [rsp+50h] [rbp-90h]
  int v104; // [rsp+58h] [rbp-88h]
  int v105; // [rsp+5Ch] [rbp-84h]
  unsigned int v106; // [rsp+60h] [rbp-80h]
  hkaiNavMeshGenerationUtils::EdgePair edgePair; // [rsp+68h] [rbp-78h]
  hkVector4f up; // [rsp+A0h] [rbp-40h]
  hkSimdFloat32 result; // [rsp+B0h] [rbp-30h]
  __m128i *v110; // [rsp+110h] [rbp+30h]
  hkaiStreamingCollection *collectiona; // [rsp+118h] [rbp+38h]
  hkResult vars0[2]; // [rsp+120h] [rbp+40h]

  v4 = pairsA->m_size;
  v5 = pairsB;
  v6 = pairsA;
  v7 = (signed __int64)this;
  if ( v4 && v5->m_size )
  {
    v8 = collection->m_instances.m_data;
    *(float *)&v106 = this->m_minEdgeMatchingLength * this->m_minEdgeMatchingLength;
    LODWORD(v9) = (unsigned __int128)_mm_shuffle_ps((__m128)v106, (__m128)v106, 0);
    v10 = v8[v6->m_data->m_edgeKey >> 22].m_instancePtr;
    v11 = v5->m_data->m_edgeKey >> 22;
    v12 = v4 - 1;
    v13 = v8[v11].m_instancePtr;
    v14 = v12;
    *(_QWORD *)&edgePair.m_edgeAIdx = v8[v11].m_instancePtr;
    if ( v12 >= 0 )
    {
      v7 = (signed __int64)&v10->m_ownedEdges;
      v15 = &v10->m_instancedEdges;
      do
      {
        v16 = (char *)&v6->m_data[v14];
        v17 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__20(
                v10->m_originalEdges,
                v10->m_numOriginalEdges,
                v15,
                (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)v7,
                &v10->m_edgeMap,
                *(_DWORD *)v16 & 0x3FFFFF);
        v18 = v17->m_a;
        v19 = v10->m_numOriginalVertices;
        if ( (signed int)v18 >= v19 )
          v20 = &v10->m_ownedVertices.m_data[(signed int)v18 - v19].m_quad;
        else
          v20 = &v10->m_originalVertices[v18].m_quad;
        v21 = v17->m_b;
        if ( (signed int)v21 >= v19 )
          v22 = &v10->m_ownedVertices.m_data[(signed int)v21 - v19].m_quad;
        else
          v22 = &v10->m_originalVertices[v21].m_quad;
        v23 = _mm_sub_ps(*v20, *v22);
        v24 = _mm_mul_ps(v23, v23);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 170))) < v9 )
        {
          v25 = --v6->m_size;
          if ( (_DWORD)v25 != v12 )
          {
            v26 = 2i64;
            v27 = (char *)&v6->m_data[v25] - v16;
            do
            {
              v28 = *(_DWORD *)&v16[v27];
              v16 += 4;
              *((_DWORD *)v16 - 1) = v28;
              --v26;
            }
            while ( v26 );
          }
        }
        --v12;
        --v14;
      }
      while ( v14 >= 0 );
      v13 = *(hkaiNavMeshInstance **)&edgePair.m_edgeAIdx;
    }
    v29 = v5->m_size - 1;
    v30 = v29;
    if ( v29 >= 0 )
    {
      v7 = (signed __int64)&v13->m_ownedEdges;
      v31 = &v13->m_instancedEdges;
      do
      {
        v32 = (char *)&v5->m_data[v30];
        v33 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__20(
                v13->m_originalEdges,
                v13->m_numOriginalEdges,
                v31,
                (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)v7,
                &v13->m_edgeMap,
                *(_DWORD *)v32 & 0x3FFFFF);
        v34 = v33->m_a;
        v35 = v13->m_numOriginalVertices;
        if ( (signed int)v34 >= v35 )
          v36 = &v13->m_ownedVertices.m_data[(signed int)v34 - v35].m_quad;
        else
          v36 = &v13->m_originalVertices[v34].m_quad;
        v37 = v33->m_b;
        if ( (signed int)v37 >= v35 )
          v38 = &v13->m_ownedVertices.m_data[(signed int)v37 - v35].m_quad;
        else
          v38 = &v13->m_originalVertices[v37].m_quad;
        v39 = _mm_sub_ps(*v36, *v38);
        v40 = _mm_mul_ps(v39, v39);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 170))) < v9 )
        {
          v41 = --v5->m_size;
          if ( (_DWORD)v41 != v29 )
          {
            v42 = 2i64;
            v43 = (char *)&v5->m_data[v41] - v32;
            do
            {
              v44 = *(_DWORD *)&v32[v43];
              v32 += 4;
              *((_DWORD *)v32 - 1) = v44;
              --v42;
            }
            while ( v42 );
          }
        }
        --v29;
        --v30;
      }
      while ( v30 >= 0 );
      v6 = *(hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> **)&vars0[0].m_enum;
    }
    v45 = v110;
    array = 0i64;
    v104 = 0;
    v46 = (hkVector4f *)&v110[6];
    v105 = 2147483648;
    v47 = v10->m_originalMesh.m_pntr;
    LODWORD(v48) = (unsigned __int128)_mm_shuffle_ps((__m128)v110[10].m128i_u32[2], (__m128)v110[10].m128i_u32[2], 0);
    *(_QWORD *)&edgePair.m_edgeAIdx = v110 + 6;
    _mm_store_si128((__m128i *)&up, v110[6]);
    if ( v47->m_flags.m_storage & 1 || v13->m_originalMesh.m_pntr->m_flags.m_storage & 1 )
      up.m_quad = 0i64;
    v49 = v6->m_size - 1;
    vars0[0].m_enum = v49;
    v50 = v49;
    if ( (signed int)v49 >= 0 )
    {
      v51 = v49;
      while ( 1 )
      {
        v52 = v5->m_size - 1;
        v53 = v52;
        if ( v52 >= 0 )
          break;
LABEL_65:
        --v51;
        --v50;
        vars0[0].m_enum = v51;
        if ( v50 < 0 )
        {
          v46 = *(hkVector4f **)&edgePair.m_edgeAIdx;
          v45 = v110;
          goto LABEL_67;
        }
      }
      while ( 1 )
      {
        hkaiNavMeshCutterHelper::edgeEndpointDistance(
          &result,
          v10,
          v13,
          &up,
          v6->m_data[v50].m_edgeKey & 0x3FFFFF,
          v5->m_data[v53].m_edgeKey & 0x3FFFFF);
        if ( result.m_real.m128_f32[0] < v48 )
          break;
        --v52;
        if ( --v53 < 0 )
          goto LABEL_64;
      }
      v54 = v10->m_numOriginalEdges;
      v55 = v6->m_data[v50].m_edgeKey & 0x3FFFFF;
      if ( v55 < v54 )
      {
        if ( v10->m_edgeMap.m_size )
          v55 = v10->m_edgeMap.m_data[v55];
        if ( v55 == -1 )
        {
          v58 = 0i64;
          goto LABEL_48;
        }
        v56 = v55;
        v57 = v10->m_instancedEdges.m_data;
      }
      else
      {
        v56 = v55 - v54;
        v57 = v10->m_ownedEdges.m_data;
      }
      v58 = (signed __int64)&v57[v56];
LABEL_48:
      *(_DWORD *)(v58 + 8) = v5->m_data[v52].m_edgeKey;
      *(_DWORD *)(v58 + 12) = v5->m_data[v52].m_faceKey;
      v59 = v13->m_numOriginalEdges;
      v60 = v5->m_data[v52].m_edgeKey & 0x3FFFFF;
      if ( v60 < v59 )
      {
        if ( v13->m_edgeMap.m_size )
          v60 = v13->m_edgeMap.m_data[v60];
        if ( v60 == -1 )
        {
          v7 = 0i64;
          goto LABEL_56;
        }
        v61 = v60;
        v62 = v13->m_instancedEdges.m_data;
      }
      else
      {
        v61 = v60 - v59;
        v62 = v13->m_ownedEdges.m_data;
      }
      v7 = (signed __int64)&v62[v61];
LABEL_56:
      *(_DWORD *)(v7 + 8) = v6->m_data[v50].m_edgeKey;
      *(_DWORD *)(v7 + 12) = v6->m_data[v50].m_faceKey;
      v63 = --v6->m_size;
      if ( (_DWORD)v63 != vars0[0].m_enum )
      {
        v64 = (signed __int64)&v6->m_data[v50];
        v65 = 2i64;
        v66 = (signed __int64)&v6->m_data[v63] - v64;
        do
        {
          v67 = *(_DWORD *)(v66 + v64);
          v64 += 4i64;
          *(_DWORD *)(v64 - 4) = v67;
          --v65;
        }
        while ( v65 );
      }
      v68 = --v5->m_size;
      if ( (_DWORD)v68 != v52 )
      {
        v69 = (signed __int64)&v5->m_data[v52];
        v70 = 2i64;
        v71 = (signed __int64)&v5->m_data[v68] - v69;
        do
        {
          v72 = *(_DWORD *)(v71 + v69);
          v69 += 4i64;
          *(_DWORD *)(v69 - 4) = v72;
          --v70;
        }
        while ( v70 );
      }
      if ( v10->m_sectionUid != v13->m_sectionUid )
      {
        *(_BYTE *)(v58 + 16) |= 0x40u;
        *(_BYTE *)(v7 + 16) |= 0x40u;
      }
LABEL_64:
      v51 = vars0[0].m_enum;
      goto LABEL_65;
    }
LABEL_67:
    v73 = v6->m_size;
    if ( v73 && v5->m_size )
    {
      v74 = 0;
      vars0[0].m_enum = 0;
      if ( v73 > 0 )
      {
        v75 = 0i64;
        do
        {
          v76 = 0;
          faceAIdx = v6->m_data[v75].m_faceKey & 0x3FFFFF;
          v7 = v6->m_data[v75].m_edgeKey & 0x3FFFFF;
          v106 = v6->m_data[v75].m_edgeKey & 0x3FFFFF;
          if ( v5->m_size > 0 )
          {
            v78 = (hkaiNavMeshEdgeMatchingParameters *)&v45[7];
            v79 = 0i64;
            up.m_quad.m128_u64[0] = (unsigned __int64)&v45[7];
            do
            {
              if ( hkaiNavMeshGenerationUtils::calculateConnectivity(
                     v78,
                     v46,
                     v10,
                     v13,
                     v7,
                     v5->m_data[v79].m_edgeKey & 0x3FFFFF,
                     faceAIdx,
                     v5->m_data[v79].m_faceKey & 0x3FFFFF,
                     &edgePair) == -1 )
              {
                v80 = v5->m_data;
                v81 = v6->m_data;
                v82 = v6->m_data[v75].m_edgeKey;
                edgePair.m_edgeAIdx = v6->m_data[v75].m_edgeKey;
                edgePair.m_faceAIdx = v81[v75].m_faceKey;
                edgePair.m_edgeBIdx = v80[v79].m_edgeKey;
                LODWORD(v81) = v80[v79].m_faceKey;
                v83 = v104;
                edgePair.m_faceBIdx = (signed int)v81;
                if ( v104 == (v105 & 0x3FFFFFFF) )
                {
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 48);
                  v83 = v104;
                  v82 = edgePair.m_edgeAIdx;
                }
                v84 = (__int64)&array[v83];
                *(_DWORD *)v84 = v82;
                *(_DWORD *)(v84 + 4) = edgePair.m_edgeBIdx;
                *(_DWORD *)(v84 + 8) = edgePair.m_faceAIdx;
                *(_DWORD *)(v84 + 12) = edgePair.m_faceBIdx;
                *(float *)(v84 + 16) = edgePair.m_distanceSquared;
                *(float *)(v84 + 20) = edgePair.m_edgeAlignment;
                *(float *)(v84 + 24) = edgePair.m_overlap;
                *(_DWORD *)(v84 + 28) = *(_DWORD *)&edgePair.m_isValid;
                *(float *)(v84 + 32) = edgePair.m_tStartA;
                *(float *)(v84 + 36) = edgePair.m_tEndA;
                *(float *)(v84 + 40) = edgePair.m_tStartB;
                *(float *)(v84 + 44) = edgePair.m_tEndB;
                ++v104;
              }
              faceAIdx = v106;
              v7 = v106;
              v78 = (hkaiNavMeshEdgeMatchingParameters *)up.m_quad.m128_u64[0];
              v46 = *(hkVector4f **)&edgePair.m_edgeAIdx;
              ++v76;
              ++v79;
            }
            while ( v76 < v5->m_size );
            v74 = vars0[0].m_enum;
          }
          v46 = *(hkVector4f **)&edgePair.m_edgeAIdx;
          v45 = v110;
          ++v74;
          ++v75;
          vars0[0].m_enum = v74;
        }
        while ( v74 < v6->m_size );
      }
      if ( v104 )
      {
        if ( v104 > 1 )
          hkAlgorithm::quickSortRecursive<hkaiNavMeshGenerationUtils::EdgePair,hkAlgorithm::less<hkaiNavMeshGenerationUtils::EdgePair>>(
            array,
            0,
            v104 - 1,
            0);
        hkaiNavMeshGenerationUtils::_resolveConflictingEdgePairs(
          vars0,
          (hkArrayBase<hkaiNavMeshGenerationUtils::EdgePair> *)&array);
        *(_QWORD *)&edgePair.m_faceAIdx = 0i64;
        edgePair.m_distanceSquared = 0.0;
        edgePair.m_edgeAlignment = -0.0;
        hkaiNavMeshGenerationUtils::_gatherAndSortSplits<hkaiNavMeshInstance>(
          (hkaiNavMeshGenerationUtils *)vars0,
          (hkResult *)v10,
          v13,
          (hkaiNavMeshInstance *)&array,
          (hkArrayBase<hkaiNavMeshGenerationUtils::EdgePair> *)&edgePair.m_faceAIdx);
        v85 = collectiona;
        for ( i = 0;
              i < SLODWORD(edgePair.m_distanceSquared);
              i += cutter_splitEdges(
                     v85,
                     *(_DWORD *)(*(_QWORD *)&edgePair.m_faceAIdx + 24i64 * i),
                     (hkaiNavMeshGenerationUtils::EdgeSplit *)(*(_QWORD *)&edgePair.m_faceAIdx + 24i64 * i),
                     1) )
        {
          ;
        }
        v87 = 0;
        if ( v104 > 0 )
        {
          v88 = 0i64;
          while ( 1 )
          {
            v7 = (signed __int64)array;
            if ( array[v88].m_isValid )
              break;
LABEL_106:
            ++v87;
            ++v88;
            if ( v87 >= v104 )
              goto LABEL_107;
          }
          v89 = array[v88].m_edgeAIdx;
          v90 = v89 & 0x3FFFFF;
          v91 = v85->m_instances.m_data[v89 >> 22].m_instancePtr;
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
          v95 = (signed __int64)&v94[v93];
LABEL_96:
          *(_DWORD *)(v95 + 8) = array[v88].m_edgeBIdx;
          *(_DWORD *)(v95 + 12) = *(_DWORD *)(v88 * 48 + v7 + 12);
          v96 = *(_DWORD *)(v88 * 48 + v7 + 4);
          v97 = v96 & 0x3FFFFF;
          v98 = v85->m_instances.m_data[v96 >> 22].m_instancePtr;
          v99 = v98->m_numOriginalEdges;
          if ( v97 < v99 )
          {
            if ( v98->m_edgeMap.m_size )
              v97 = v98->m_edgeMap.m_data[v97];
            if ( v97 == -1 )
            {
              v102 = 0i64;
              goto LABEL_104;
            }
            v100 = v97;
            v101 = v98->m_instancedEdges.m_data;
          }
          else
          {
            v100 = v97 - v99;
            v101 = v98->m_ownedEdges.m_data;
          }
          v102 = (signed __int64)&v101[v100];
LABEL_104:
          *(_DWORD *)(v102 + 8) = *(_DWORD *)(v88 * 48 + v7);
          *(_DWORD *)(v102 + 12) = *(_DWORD *)(v88 * 48 + v7 + 8);
          if ( v10->m_sectionUid != v13->m_sectionUid )
          {
            *(_BYTE *)(v95 + 16) |= 0x40u;
            *(_BYTE *)(v102 + 16) |= 0x40u;
          }
          goto LABEL_106;
        }
LABEL_107:
        edgePair.m_distanceSquared = 0.0;
        if ( edgePair.m_edgeAlignment >= 0.0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            *(void **)&edgePair.m_faceAIdx,
            24 * (LODWORD(edgePair.m_edgeAlignment) & 0x3FFFFFFF));
        *(_QWORD *)&edgePair.m_faceAIdx = 0i64;
        edgePair.m_edgeAlignment = -0.0;
      }
    }
    v104 = 0;
    if ( v105 >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkaiNavMeshGenerationUtils::EdgePair *, _QWORD, signed __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        array,
        48 * (v105 & 0x3FFFFFFFu),
        v7);
  }
}


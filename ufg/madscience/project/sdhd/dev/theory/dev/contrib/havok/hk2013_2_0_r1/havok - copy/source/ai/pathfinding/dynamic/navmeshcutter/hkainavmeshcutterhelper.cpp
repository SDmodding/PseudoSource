// File Line: 17
// RVA: 0xC1AF60
void __fastcall hkaiNavMeshCutterHelper::connectCutFaceToUncutFace(
        hkaiStreamingCollection *collection,
        hkaiNavMeshCutter::SavedConnectivity *connectivityInfo,
        unsigned int uncutEdgeKey,
        unsigned int originalCutEdgeKey,
        hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *cutPairs)
{
  hkaiNavMesh::Edge *v9; // r14
  hkaiNavMeshInstance *m_instancePtr; // rcx
  hkaiNavMesh::Edge *v11; // rbx
  unsigned int m_edgeKey; // r8d
  int v13; // edx
  hkaiNavMeshInstance *v14; // r8
  int m_numOriginalEdges; // eax
  __int64 v16; // rcx
  hkaiNavMesh::Edge *m_data; // rax
  hkaiNavMesh::Edge *v18; // rdx

  v9 = hkaiNavMeshInstance::instanceEdge(
         collection->m_instances.m_data[uncutEdgeKey >> 22].m_instancePtr,
         uncutEdgeKey & 0x3FFFFF);
  m_instancePtr = collection->m_instances.m_data[originalCutEdgeKey >> 22].m_instancePtr;
  v11 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__18(
          m_instancePtr->m_originalEdges,
          m_instancePtr->m_numOriginalEdges,
          &m_instancePtr->m_instancedEdges,
          &m_instancePtr->m_ownedEdges,
          &m_instancePtr->m_edgeMap,
          originalCutEdgeKey & 0x3FFFFF);
  hkaiNavMeshCutter::SavedConnectivity::addConnectivity(connectivityInfo, uncutEdgeKey);
  m_edgeKey = cutPairs->m_data->m_edgeKey;
  v9->m_oppositeEdge = m_edgeKey;
  v9->m_oppositeFace = cutPairs->m_data->m_faceKey;
  v13 = m_edgeKey & 0x3FFFFF;
  v14 = collection->m_instances.m_data[m_edgeKey >> 22].m_instancePtr;
  m_numOriginalEdges = v14->m_numOriginalEdges;
  if ( v13 >= m_numOriginalEdges )
  {
    v16 = v13 - m_numOriginalEdges;
    m_data = v14->m_ownedEdges.m_data;
LABEL_8:
    v18 = &m_data[v16];
    goto LABEL_9;
  }
  if ( v14->m_edgeMap.m_size )
    v13 = v14->m_edgeMap.m_data[v13];
  if ( v13 != -1 )
  {
    v16 = v13;
    m_data = v14->m_instancedEdges.m_data;
    goto LABEL_8;
  }
  v18 = 0i64;
LABEL_9:
  v18->m_oppositeEdge = v11->m_oppositeEdge;
  v18->m_oppositeFace = v11->m_oppositeFace;
  v18->m_flags.m_storage ^= (v18->m_flags.m_storage ^ v9->m_flags.m_storage) & 0x40;
}

// File Line: 47
// RVA: 0xC1B0C0
void __fastcall hkaiNavMeshCutterHelper::replaceFaceWithCutFace(
        hkaiStreamingCollection *collection,
        unsigned int faceKey,
        unsigned int skipEdgeKey,
        hkaiNavMeshCutter::SavedConnectivity *connectivityInfo,
        hkArray<int,hkContainerHeapAllocator> *magic,
        hkPointerMap<unsigned int,hkArray<unsigned int,hkContainerHeapAllocator> *,hkContainerTempAllocator> *edgeMap)
{
  __int64 v6; // rbx
  int index; // ebp
  hkaiNavMeshInstance *m_instancePtr; // rsi
  hkaiNavMesh::Face *v10; // rax
  int v11; // edi
  hkaiNavMesh::Face *v12; // r12
  __int64 m_numEdges; // r14
  int v14; // edx
  hkaiNavMeshInstance::AddEdgeContext *v15; // rcx
  int v16; // r13d
  __int64 v17; // rdx
  unsigned int *p_m_oppositeEdge; // rcx
  hkaiNavMeshInstance::AddEdgeContext *v19; // r13
  hkArray<int,hkContainerHeapAllocator> *v20; // rbx
  int v21; // ebp
  int v22; // r13d
  int m_numOriginalEdges; // eax
  int v24; // ecx
  int v25; // r8d
  __int64 v26; // rcx
  hkaiNavMesh::Edge *m_data; // rax
  hkaiNavMesh::Edge *v28; // rdi
  unsigned int m_oppositeEdge; // ecx
  unsigned int v30; // eax
  unsigned int v31; // ebx
  __int64 v32; // r14
  hkaiNavMeshInstance *v33; // rax
  char m_storage; // cl
  hkaiUserEdgeUtils::RemoveParameters *v35; // rax
  int v36; // ebx
  hkaiNavMeshInstance *v37; // rdx
  int v38; // eax
  __int64 v39; // rcx
  hkaiNavMesh::Edge *v40; // rax
  hkaiNavMesh::Edge *v41; // rdx
  int m_startEdgeIndex; // edi
  unsigned int v43; // ecx
  hkPointerMap<unsigned int,hkArray<unsigned int,hkContainerHeapAllocator> *,hkContainerTempAllocator> *v44; // r15
  unsigned int v45; // r13d
  _QWORD **Value; // rax
  _DWORD *v47; // rbx
  int v48; // ebp
  int v49; // [rsp+30h] [rbp-88h]
  int v50; // [rsp+34h] [rbp-84h] BYREF
  unsigned int v51; // [rsp+38h] [rbp-80h]
  int v52; // [rsp+3Ch] [rbp-7Ch]
  hkaiNavMeshInstance::AddEdgeContext *ctxs; // [rsp+40h] [rbp-78h]
  hkaiNavMeshInstance::AddFaceContext ctx; // [rsp+48h] [rbp-70h] BYREF
  unsigned int v56; // [rsp+C0h] [rbp+8h]
  hkaiUserEdgeUtils::RemoveParameters v57; // [rsp+C8h] [rbp+10h] BYREF
  char v58; // [rsp+D0h] [rbp+18h] BYREF
  hkaiNavMeshCutter::SavedConnectivity *v59; // [rsp+D8h] [rbp+20h]

  v59 = connectivityInfo;
  v6 = faceKey >> 22;
  index = faceKey & 0x3FFFFF;
  v57.m_updateHierarchyGraphs.m_bool = 1;
  v51 = faceKey >> 22;
  hkaiUserEdgeUtils::removeUserEdgesFromFace(collection, faceKey, &v57);
  m_instancePtr = collection->m_instances.m_data[v6].m_instancePtr;
  v10 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__16(
          m_instancePtr->m_originalFaces,
          m_instancePtr->m_numOriginalFaces,
          &m_instancePtr->m_instancedFaces,
          &m_instancePtr->m_ownedFaces,
          &m_instancePtr->m_faceMap,
          index);
  v11 = 0;
  *(_QWORD *)ctx.m_data = 0i64;
  *(_QWORD *)&ctx.m_data[2] = 0i64;
  v12 = v10;
  v52 = m_instancePtr->m_numOriginalFaces + m_instancePtr->m_ownedFaces.m_size;
  hkaiNavMeshInstance::getFaceContext(m_instancePtr, index, &ctx);
  m_numEdges = ctx.m_face.m_numEdges;
  ctx.m_face.m_startEdgeIndex = m_instancePtr->m_numOriginalEdges + m_instancePtr->m_ownedEdges.m_size;
  ctx.m_flags.m_storage = 2;
  hkaiNavMeshInstance::appendFaces(m_instancePtr, &ctx, 1);
  if ( m_instancePtr->m_faceClearanceIndices.m_size == (m_instancePtr->m_faceClearanceIndices.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &m_instancePtr->m_faceClearanceIndices, 4);
  v14 = m_numEdges;
  m_instancePtr->m_faceClearanceIndices.m_data[m_instancePtr->m_faceClearanceIndices.m_size++] = -1;
  if ( (_DWORD)m_numEdges )
  {
    v50 = 40 * m_numEdges;
    v15 = (hkaiNavMeshInstance::AddEdgeContext *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                                   &hkContainerTempAllocator::s_alloc,
                                                   &v50);
    v14 = v50 / 40;
  }
  else
  {
    v15 = 0i64;
  }
  v16 = 0x80000000;
  ctxs = v15;
  if ( v14 )
    v16 = v14;
  v17 = m_numEdges;
  v49 = v16;
  if ( (int)m_numEdges > 0 )
  {
    p_m_oppositeEdge = &v15->m_edge.m_oppositeEdge;
    do
    {
      if ( p_m_oppositeEdge != (unsigned int *)8 )
      {
        p_m_oppositeEdge[1] = -1;
        *p_m_oppositeEdge = -1;
        p_m_oppositeEdge[2] = 4;
        *((_WORD *)p_m_oppositeEdge + 14) = -1;
        *(_QWORD *)(p_m_oppositeEdge + 3) = 0i64;
        *(_QWORD *)(p_m_oppositeEdge + 5) = 0i64;
      }
      p_m_oppositeEdge += 10;
      --v17;
    }
    while ( v17 );
  }
  if ( v12->m_numEdges > 0 )
  {
    v19 = ctxs;
    do
    {
      hkaiNavMeshInstance::getEdgeContext(m_instancePtr, v11 + v12->m_startEdgeIndex, &v19[v11]);
      v19[v11].m_cutInfo = v11;
      ++v11;
    }
    while ( v11 < v12->m_numEdges );
    v16 = v49;
  }
  hkaiNavMeshInstance::appendEdges(m_instancePtr, ctxs, m_numEdges);
  v20 = magic;
  m_instancePtr->m_faceFlags.m_data[index].m_storage = 1;
  v20->m_data[index] = v20->m_size;
  if ( v20->m_size == (v20->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v20, 4);
  v20->m_data[v20->m_size++] = index;
  v21 = 0;
  if ( ctx.m_face.m_numEdges > 0 )
  {
    v22 = v51 << 22;
    while ( 1 )
    {
      m_numOriginalEdges = m_instancePtr->m_numOriginalEdges;
      v24 = v21 + ctx.m_face.m_startEdgeIndex;
      v25 = v22 | (v21 + v12->m_startEdgeIndex);
      if ( v21 + ctx.m_face.m_startEdgeIndex < m_numOriginalEdges )
      {
        if ( m_instancePtr->m_edgeMap.m_size )
          v24 = m_instancePtr->m_edgeMap.m_data[v24];
        if ( v24 == -1 )
        {
          v28 = 0i64;
          goto LABEL_29;
        }
        v26 = v24;
        m_data = m_instancePtr->m_instancedEdges.m_data;
      }
      else
      {
        v26 = v24 - m_numOriginalEdges;
        m_data = m_instancePtr->m_ownedEdges.m_data;
      }
      v28 = &m_data[v26];
LABEL_29:
      m_oppositeEdge = v28->m_oppositeEdge;
      if ( m_oppositeEdge == -1 )
      {
        hkaiNavMeshCutter::SavedConnectivity::popConnectivityForEdgeAndFace(v59, collection, v25);
      }
      else
      {
        if ( (v28->m_flags.m_storage & 0x40) != 0 )
          v30 = m_oppositeEdge & 0xFFC00000;
        else
          v30 = m_instancePtr->m_runtimeId << 22;
        v31 = v30 | m_oppositeEdge & 0x3FFFFF;
        v32 = v31 >> 22;
        v33 = collection->m_instances.m_data[v31 >> 22].m_instancePtr;
        if ( v33->m_faceFlags.m_size )
        {
          m_storage = v33->m_faceFlags.m_data[v28->m_oppositeFace & 0x3FFFFF].m_storage;
          v35 = &v57;
          v57.m_updateHierarchyGraphs.m_bool = m_storage;
        }
        else
        {
          v58 = 0;
          v35 = (hkaiUserEdgeUtils::RemoveParameters *)&v58;
        }
        if ( (v35->m_updateHierarchyGraphs.m_bool & 2) == 0 )
          goto LABEL_46;
        hkaiNavMeshCutter::SavedConnectivity::popConnectivityForEdgeAndFace(v59, collection, v25);
        v36 = v31 & 0x3FFFFF;
        v37 = collection->m_instances.m_data[v32].m_instancePtr;
        v38 = v37->m_numOriginalEdges;
        if ( v36 >= v38 )
        {
          v39 = v36 - v38;
          v40 = v37->m_ownedEdges.m_data;
LABEL_45:
          v41 = &v40[v39];
          v41->m_oppositeFace = -1;
          v41->m_oppositeEdge = -1;
          goto LABEL_46;
        }
        if ( v37->m_edgeMap.m_size )
          v36 = v37->m_edgeMap.m_data[v36];
        if ( v36 != -1 )
        {
          v39 = v36;
          v40 = v37->m_instancedEdges.m_data;
          goto LABEL_45;
        }
        MEMORY[0xC] = -1;
        MEMORY[8] = -1;
      }
LABEL_46:
      v28->m_oppositeEdge = -1;
      v28->m_oppositeFace = -1;
      if ( ++v21 >= ctx.m_face.m_numEdges )
      {
        v16 = v49;
        break;
      }
    }
  }
  m_startEdgeIndex = v12->m_startEdgeIndex;
  v43 = skipEdgeKey & 0x3FFFFF;
  v56 = skipEdgeKey & 0x3FFFFF;
  if ( m_startEdgeIndex < m_startEdgeIndex + v12->m_numEdges )
  {
    v44 = edgeMap;
    v45 = v51;
    do
    {
      if ( m_startEdgeIndex != v43 )
      {
        if ( hkaiNavMeshInstance_get_hkaiNavMesh::Edge__18(
               m_instancePtr->m_originalEdges,
               m_instancePtr->m_numOriginalEdges,
               &m_instancePtr->m_instancedEdges,
               &m_instancePtr->m_ownedEdges,
               &m_instancePtr->m_edgeMap,
               m_startEdgeIndex)->m_oppositeEdge != -1 )
        {
          Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v47 = (_DWORD *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 16i64);
          if ( v47 )
          {
            v47[3] = 0x80000000;
            *(_QWORD *)v47 = 0i64;
            v47[2] = 0;
          }
          else
          {
            v47 = 0i64;
          }
          v48 = v52 | (v45 << 22);
          if ( v47[2] == (v47[3] & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v47, 4);
          *(_DWORD *)(*(_QWORD *)v47 + 4i64 * (int)v47[2]++) = v48;
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            &v44->m_map,
            &hkContainerTempAllocator::s_alloc,
            (v45 << 22) | m_startEdgeIndex,
            (unsigned __int64)v47);
        }
        v43 = v56;
      }
      ++m_startEdgeIndex;
    }
    while ( m_startEdgeIndex < v12->m_startEdgeIndex + v12->m_numEdges );
    v16 = v49;
  }
  if ( v16 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, ctxs, 40 * (v16 & 0x3FFFFFFF));
}

// File Line: 155
// RVA: 0xC1B640
hkSimdFloat32 *__fastcall hkaiNavMeshCutterHelper::edgeEndpointDistance(
        hkSimdFloat32 *result,
        hkaiNavMeshInstance *meshA,
        hkaiNavMeshInstance *meshB,
        hkVector4f *up,
        int edgeA,
        int edgeB)
{
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm0
  __m128 v13; // xmm2
  __m128 v14; // xmm4
  __m128 v15; // xmm0
  __m128 v16; // xmm2
  __m128 v17; // xmm4
  __m128 v18; // xmm4
  __m128 v19; // xmm9
  hkSimdFloat32 *v20; // rax
  __m128 v21; // xmm9
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm6
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  hkVector4f v27; // [rsp+20h] [rbp-88h] BYREF
  hkVector4f v28; // [rsp+30h] [rbp-78h] BYREF
  hkVector4f v29; // [rsp+40h] [rbp-68h] BYREF
  hkVector4f v30; // [rsp+50h] [rbp-58h] BYREF

  hkaiNavMeshInstance::getEdgePoints(meshA, edgeA, &v27, &v28);
  hkaiNavMeshInstance::getEdgePoints(meshB, edgeB, &v29, &v30);
  v9 = _mm_mul_ps(up->m_quad, v27.m_quad);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_mul_ps(up->m_quad, v28.m_quad);
  v12 = _mm_sub_ps(
          (__m128)0i64,
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170)));
  v13 = _mm_mul_ps(up->m_quad, v29.m_quad);
  v14 = _mm_add_ps(v28.m_quad, _mm_mul_ps(v12, up->m_quad));
  v15 = _mm_sub_ps(
          (__m128)0i64,
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170)));
  v16 = _mm_mul_ps(up->m_quad, v30.m_quad);
  v17 = _mm_sub_ps(v14, _mm_add_ps(v29.m_quad, _mm_mul_ps(v15, up->m_quad)));
  v18 = _mm_mul_ps(v17, v17);
  v19 = _mm_sub_ps(
          _mm_add_ps(v27.m_quad, _mm_mul_ps(_mm_sub_ps((__m128)0i64, v10), up->m_quad)),
          _mm_add_ps(
            v30.m_quad,
            _mm_mul_ps(
              _mm_sub_ps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                  _mm_shuffle_ps(v16, v16, 170))),
              up->m_quad)));
  v20 = result;
  v21 = _mm_mul_ps(v19, v19);
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v23 = _mm_rsqrt_ps(v22);
  v24 = _mm_andnot_ps(
          _mm_cmple_ps(v22, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v23), v23)),
              _mm_mul_ps(*(__m128 *)_xmm, v23)),
            v22));
  v25 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v26 = _mm_rsqrt_ps(v25);
  result->m_real = _mm_add_ps(
                     _mm_andnot_ps(
                       _mm_cmple_ps(v25, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v25, v26), v26)),
                           _mm_mul_ps(*(__m128 *)_xmm, v26)),
                         v25)),
                     v24);
  return v20;
}

// File Line: 172
// RVA: 0xC1BD30
void __fastcall handleBoundary(int eIdx, hkArray<int,hkContainerTempAllocator> *edgeBlocks)
{
  int m_size; // edx

  m_size = edgeBlocks->m_size;
  if ( !(m_size % 2) )
  {
    if ( m_size == (edgeBlocks->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, edgeBlocks, 4);
    edgeBlocks->m_data[edgeBlocks->m_size++] = eIdx;
  }
}

// File Line: 180
// RVA: 0xC1BDA0
void __fastcall handleNonBoundary(int eIdx, hkArray<int,hkContainerTempAllocator> *edgeBlocks)
{
  __int64 m_size; // r8

  m_size = edgeBlocks->m_size;
  if ( edgeBlocks->m_size % 2 == 1 )
  {
    if ( eIdx == edgeBlocks->m_data[m_size - 1] + 1 )
    {
      edgeBlocks->m_size = m_size - 1;
    }
    else
    {
      if ( (_DWORD)m_size == (edgeBlocks->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, edgeBlocks, 4);
      edgeBlocks->m_data[edgeBlocks->m_size++] = eIdx;
    }
  }
}

// File Line: 196
// RVA: 0xC1B850
void __fastcall hkaiNavMeshCutterHelper::mergeContiguousBoundaryEdges(
        hkaiStreamingCollection *collection,
        hkaiNavMesh::Face *originalFace,
        unsigned int originalEdgeKey,
        int cutFaceIndex)
{
  unsigned int v4; // r15d
  hkaiNavMeshInstance *m_instancePtr; // rsi
  int m_numOriginalFaces; // eax
  hkaiNavMesh::Face *v7; // r14
  __int64 m_startEdgeIndex; // rbx
  __int64 v9; // rdi
  hkResultEnum m_enum; // eax
  __int64 v11; // r12
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_ownedEdges; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_instancedEdges; // rcx
  __int64 m_numOriginalEdges; // r14
  hkaiNavMesh::Edge *v15; // r9
  unsigned __int16 v16; // r8
  int *m_data; // rdx
  int v18; // r8d
  int *v19; // rcx
  __int64 v20; // r9
  int v21; // eax
  int v22; // edi
  int v23; // r15d
  int v24; // r12d
  __int64 v25; // rbx
  __int64 v26; // r13
  int v27; // edx
  hkaiNavMesh::Edge *v28; // r8
  hkaiNavMesh::Edge *v29; // r9
  __int64 v30; // rdx
  int v31; // ecx
  int m_size; // eax
  int v33; // ebx
  hkResultEnum v34; // r14d
  int v35; // edi
  int v36; // r15d
  int v37; // ebx
  int v38; // r13d
  hkaiNavMesh::Edge *v39; // rax
  hkaiNavMesh::Edge *v40; // r9
  unsigned int m_oppositeEdge; // edx
  signed int v42; // ecx
  __int64 v43; // r8
  hkResult *p_result; // rax
  int v45; // eax
  int v46; // edx
  __int64 v47; // rcx
  __int64 v48; // rax
  __int64 v49; // rdx
  int index; // [rsp+28h] [rbp-19h]
  hkaiNavMesh::Face *v51; // [rsp+30h] [rbp-11h]
  __int64 v52; // [rsp+38h] [rbp-9h]
  hkArray<int,hkContainerTempAllocator> array[2]; // [rsp+40h] [rbp-1h] BYREF
  _QWORD *retaddr; // [rsp+A8h] [rbp+67h]
  int v55; // [rsp+B0h] [rbp+6Fh]
  hkResult result; // [rsp+B8h] [rbp+77h] BYREF
  int v57; // [rsp+C0h] [rbp+7Fh] BYREF

  v4 = (originalEdgeKey & 0x3FFFFF) - originalFace->m_startEdgeIndex;
  index = originalEdgeKey >> 22;
  m_instancePtr = collection->m_instances.m_data[originalEdgeKey >> 22].m_instancePtr;
  m_numOriginalFaces = m_instancePtr->m_numOriginalFaces;
  if ( cutFaceIndex < m_numOriginalFaces )
  {
    if ( m_instancePtr->m_faceMap.m_size )
      cutFaceIndex = m_instancePtr->m_faceMap.m_data[cutFaceIndex];
    if ( cutFaceIndex == -1 )
      v7 = 0i64;
    else
      v7 = &m_instancePtr->m_instancedFaces.m_data[cutFaceIndex];
  }
  else
  {
    v7 = &m_instancePtr->m_ownedFaces.m_data[cutFaceIndex - m_numOriginalFaces];
  }
  v51 = v7;
  array[0].m_data = 0i64;
  array[0].m_size = 0;
  array[0].m_capacityAndFlags = 0x80000000;
  hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, array, 8, 4);
  m_startEdgeIndex = v7->m_startEdgeIndex;
  v9 = m_startEdgeIndex;
  m_enum = m_startEdgeIndex + v7->m_numEdges;
  v11 = m_enum;
  result.m_enum = m_enum;
  if ( m_startEdgeIndex < (int)m_enum )
  {
    p_m_ownedEdges = &m_instancePtr->m_ownedEdges;
    p_m_instancedEdges = &m_instancePtr->m_instancedEdges;
    do
    {
      m_numOriginalEdges = m_instancePtr->m_numOriginalEdges;
      v15 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__18(
              m_instancePtr->m_originalEdges,
              m_instancePtr->m_numOriginalEdges,
              p_m_instancedEdges,
              p_m_ownedEdges,
              &m_instancePtr->m_edgeMap,
              m_startEdgeIndex);
      if ( (int)m_startEdgeIndex < (int)m_numOriginalEdges )
        v16 = -1;
      else
        v16 = m_instancePtr->m_cuttingInfo.m_data[v9 - m_numOriginalEdges];
      if ( v16 == v4 && v15->m_oppositeFace == -1 )
        handleBoundary(m_startEdgeIndex, array);
      else
        handleNonBoundary(m_startEdgeIndex, array);
      ++v9;
      LODWORD(m_startEdgeIndex) = m_startEdgeIndex + 1;
      p_m_ownedEdges = &m_instancePtr->m_ownedEdges;
      p_m_instancedEdges = &m_instancePtr->m_instancedEdges;
    }
    while ( v9 < v11 );
    v7 = v51;
    m_enum = result.m_enum;
  }
  handleNonBoundary(m_enum, array);
  m_data = array[0].m_data;
  if ( array[0].m_size )
  {
    v18 = 0;
    if ( array[0].m_size > 0 )
    {
      v19 = array[0].m_data;
      v20 = ((unsigned int)(array[0].m_size - 1) >> 1) + 1;
      do
      {
        v21 = v19[1];
        v19 += 2;
        v18 = v21 - *(v19 - 2) + v18 - 1;
        --v20;
      }
      while ( v20 );
    }
    if ( v7->m_numEdges - (__int16)v18 >= 3 )
    {
      v22 = 0;
      v7->m_numEdges -= v18;
      m_data = array[0].m_data;
      v23 = m_instancePtr->m_numOriginalEdges;
      v24 = *array[0].m_data;
      v55 = v23;
      v25 = *array[0].m_data;
      if ( array[0].m_size > 0 )
      {
        v26 = 0i64;
        do
        {
          hkaiNavMeshInstance::copyOwnedEdge(m_instancePtr, v24 - v23, m_data[v26] - v23);
          v27 = m_instancePtr->m_numOriginalEdges;
          v28 = m_instancePtr->m_ownedEdges.m_data;
          v29 = &v28[array[0].m_data[v26 + 1] - v27 - 1];
          if ( v24 < v27 )
          {
            if ( m_instancePtr->m_edgeMap.m_size )
              v31 = m_instancePtr->m_edgeMap.m_data[v25];
            else
              v31 = v24;
            if ( v31 == -1 )
              v30 = 0i64;
            else
              v30 = (__int64)&m_instancePtr->m_instancedEdges.m_data[v31];
          }
          else
          {
            v30 = (__int64)&v28[v24 - v27];
          }
          v22 += 2;
          *(_DWORD *)(v30 + 4) = v29->m_b;
          m_data = array[0].m_data;
          m_size = array[0].m_size;
          ++v24;
          v52 = v25 + 1;
          v33 = array[0].m_data[v26 + 1];
          v57 = v22;
          if ( v22 >= array[0].m_size )
            v34 = result.m_enum;
          else
            v34 = array[0].m_data[v26 + 2];
          if ( v33 < v34 )
          {
            v35 = v24 - v23;
            v36 = -v23;
            v24 += v34 - v33;
            v52 += (unsigned int)(v34 - v33);
            do
              hkaiNavMeshInstance::copyOwnedEdge(m_instancePtr, v35++, v36 + v33++);
            while ( v33 < v34 );
            m_size = array[0].m_size;
            m_data = array[0].m_data;
            v22 = v57;
            v23 = v55;
          }
          v25 = v52;
          v26 += 2i64;
        }
        while ( v22 < m_size );
        v7 = v51;
      }
      v37 = v7->m_startEdgeIndex;
      if ( v7->m_startEdgeIndex < v7->m_startEdgeIndex + v7->m_numEdges )
      {
        v38 = index;
        while ( 1 )
        {
          v39 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__18(
                  m_instancePtr->m_originalEdges,
                  m_instancePtr->m_numOriginalEdges,
                  &m_instancePtr->m_instancedEdges,
                  &m_instancePtr->m_ownedEdges,
                  &m_instancePtr->m_edgeMap,
                  v37);
          v40 = v39;
          m_oppositeEdge = v39->m_oppositeEdge;
          if ( m_oppositeEdge == -1 )
            goto LABEL_62;
          v42 = (v39->m_flags.m_storage & 0x40) != 0 ? m_oppositeEdge >> 22 : m_instancePtr->m_runtimeId;
          v43 = *(_QWORD *)(retaddr[4] + 48i64 * v42);
          if ( *(_DWORD *)(v43 + 328) )
          {
            p_result = &result;
            LOBYTE(result.m_enum) = *(_BYTE *)((v40->m_oppositeFace & 0x3FFFFF) + *(_QWORD *)(v43 + 320));
          }
          else
          {
            LOBYTE(v57) = 0;
            p_result = (hkResult *)&v57;
          }
          if ( (p_result->m_enum & 1) != 0 )
            goto LABEL_62;
          v45 = *(_DWORD *)(v43 + 40);
          v46 = m_oppositeEdge & 0x3FFFFF;
          if ( v46 >= v45 )
            break;
          if ( *(_DWORD *)(v43 + 216) )
            v46 = *(_DWORD *)(*(_QWORD *)(v43 + 208) + 4i64 * v46);
          if ( v46 != -1 )
          {
            v47 = 5i64 * v46;
            v48 = *(_QWORD *)(v43 + 256);
            goto LABEL_60;
          }
          v49 = 0i64;
LABEL_61:
          *(_DWORD *)(v49 + 8) = v37 | (v38 << 22);
LABEL_62:
          if ( ++v37 >= v7->m_startEdgeIndex + v7->m_numEdges )
          {
            m_data = array[0].m_data;
            goto LABEL_64;
          }
        }
        v47 = 5i64 * (v46 - v45);
        v48 = *(_QWORD *)(v43 + 288);
LABEL_60:
        v49 = v48 + 4 * v47;
        goto LABEL_61;
      }
    }
  }
LABEL_64:
  array[0].m_size = 0;
  if ( array[0].m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      m_data,
      4 * array[0].m_capacityAndFlags);
}


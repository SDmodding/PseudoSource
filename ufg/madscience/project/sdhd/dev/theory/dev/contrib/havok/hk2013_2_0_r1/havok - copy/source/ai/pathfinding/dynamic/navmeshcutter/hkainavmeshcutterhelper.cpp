// File Line: 17
// RVA: 0xC1AF60
void __fastcall hkaiNavMeshCutterHelper::connectCutFaceToUncutFace(hkaiStreamingCollection *collection, hkaiNavMeshCutter::SavedConnectivity *connectivityInfo, unsigned int uncutEdgeKey, unsigned int originalCutEdgeKey, hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *cutPairs)
{
  hkaiNavMeshCutter::SavedConnectivity *v5; // rsi
  hkaiStreamingCollection *v6; // rbp
  unsigned int v7; // ebx
  unsigned int v8; // edi
  hkaiNavMesh::Edge *v9; // r14
  hkaiNavMeshInstance *v10; // rcx
  hkaiNavMesh::Edge *v11; // rbx
  unsigned int v12; // er8
  int v13; // edx
  hkaiNavMeshInstance *v14; // r8
  int v15; // eax
  signed __int64 v16; // rcx
  hkaiNavMesh::Edge *v17; // rax
  signed __int64 v18; // rdx

  v5 = connectivityInfo;
  v6 = collection;
  v7 = originalCutEdgeKey;
  v8 = uncutEdgeKey;
  v9 = hkaiNavMeshInstance::instanceEdge(
         collection->m_instances.m_data[uncutEdgeKey >> 22].m_instancePtr,
         uncutEdgeKey & 0x3FFFFF);
  v10 = v6->m_instances.m_data[v7 >> 22].m_instancePtr;
  v11 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__18(
          v10->m_originalEdges,
          v10->m_numOriginalEdges,
          &v10->m_instancedEdges,
          &v10->m_ownedEdges,
          &v10->m_edgeMap,
          v7 & 0x3FFFFF);
  hkaiNavMeshCutter::SavedConnectivity::addConnectivity(v5, v8);
  v12 = cutPairs->m_data->m_edgeKey;
  v9->m_oppositeEdge = v12;
  v9->m_oppositeFace = cutPairs->m_data->m_faceKey;
  v13 = v12 & 0x3FFFFF;
  v14 = v6->m_instances.m_data[v12 >> 22].m_instancePtr;
  v15 = v14->m_numOriginalEdges;
  if ( v13 >= v15 )
  {
    v16 = v13 - v15;
    v17 = v14->m_ownedEdges.m_data;
LABEL_8:
    v18 = (signed __int64)&v17[v16];
    goto LABEL_9;
  }
  if ( v14->m_edgeMap.m_size )
    v13 = v14->m_edgeMap.m_data[v13];
  if ( v13 != -1 )
  {
    v16 = v13;
    v17 = v14->m_instancedEdges.m_data;
    goto LABEL_8;
  }
  v18 = 0i64;
LABEL_9:
  *(_DWORD *)(v18 + 8) = v11->m_oppositeEdge;
  *(_DWORD *)(v18 + 12) = v11->m_oppositeFace;
  *(_BYTE *)(v18 + 16) ^= (*(_BYTE *)(v18 + 16) ^ v9->m_flags.m_storage) & 0x40;
}

// File Line: 47
// RVA: 0xC1B0C0
void __fastcall hkaiNavMeshCutterHelper::replaceFaceWithCutFace(hkaiStreamingCollection *collection, unsigned int faceKey, unsigned int skipEdgeKey, hkaiNavMeshCutter::SavedConnectivity *connectivityInfo, hkArray<int,hkContainerHeapAllocator> *magic, hkPointerMap<unsigned int,hkArray<unsigned int,hkContainerHeapAllocator> *,hkContainerTempAllocator> *edgeMap)
{
  __int64 v6; // rbx
  hkaiStreamingCollection *v7; // r15
  int index; // ebp
  hkaiNavMeshInstance *v9; // rsi
  hkaiNavMesh::Face *v10; // rax
  signed int v11; // edi
  hkaiNavMesh::Face *v12; // r12
  __int64 v13; // r14
  int v14; // edx
  hkaiNavMeshInstance::AddEdgeContext *v15; // rcx
  signed int v16; // er13
  __int64 v17; // rdx
  signed __int64 v18; // rcx
  hkaiNavMeshInstance::AddEdgeContext *v19; // r13
  hkArray<int,hkContainerHeapAllocator> *v20; // rbx
  __int64 v21; // rdx
  int v22; // ebp
  int v23; // er13
  int v24; // eax
  int v25; // ecx
  int v26; // er8
  signed __int64 v27; // rcx
  hkaiNavMesh::Edge *v28; // rax
  signed __int64 v29; // rdi
  int v30; // ecx
  unsigned int v31; // eax
  unsigned int v32; // ebx
  signed __int64 v33; // r14
  hkaiNavMeshInstance *v34; // rax
  char v35; // cl
  char *v36; // rax
  int v37; // ebx
  hkaiNavMeshInstance *v38; // rdx
  int v39; // eax
  signed __int64 v40; // rcx
  hkaiNavMesh::Edge *v41; // rax
  signed __int64 v42; // rdx
  int v43; // edi
  int v44; // ecx
  hkPointerMap<unsigned int,hkArray<unsigned int,hkContainerHeapAllocator> *,hkContainerTempAllocator> *v45; // r15
  unsigned int v46; // er13
  _QWORD **v47; // rax
  _DWORD *v48; // rbx
  int v49; // ebp
  signed int v50; // [rsp+30h] [rbp-88h]
  int v51; // [rsp+34h] [rbp-84h]
  unsigned int v52; // [rsp+38h] [rbp-80h]
  int v53; // [rsp+3Ch] [rbp-7Ch]
  hkaiNavMeshInstance::AddEdgeContext *ctxs; // [rsp+40h] [rbp-78h]
  hkaiNavMeshInstance::AddFaceContext ctx; // [rsp+48h] [rbp-70h]
  unsigned int v56; // [rsp+C0h] [rbp+8h]
  int v57; // [rsp+C0h] [rbp+8h]
  char v58; // [rsp+C8h] [rbp+10h]
  char v59; // [rsp+D0h] [rbp+18h]
  hkaiNavMeshCutter::SavedConnectivity *v60; // [rsp+D8h] [rbp+20h]

  v60 = connectivityInfo;
  v56 = skipEdgeKey;
  v6 = faceKey >> 22;
  v7 = collection;
  index = faceKey & 0x3FFFFF;
  v58 = 1;
  v52 = faceKey >> 22;
  hkaiUserEdgeUtils::removeUserEdgesFromFace(collection, faceKey, (hkaiUserEdgeUtils::RemoveParameters *)&v58);
  v9 = v7->m_instances.m_data[v6].m_instancePtr;
  v10 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__16(
          v9->m_originalFaces,
          v9->m_numOriginalFaces,
          &v9->m_instancedFaces,
          &v9->m_ownedFaces,
          &v9->m_faceMap,
          index);
  v11 = 0;
  *(_QWORD *)ctx.m_data = 0i64;
  *(_QWORD *)&ctx.m_data[2] = 0i64;
  v12 = v10;
  v53 = v9->m_numOriginalFaces + v9->m_ownedFaces.m_size;
  hkaiNavMeshInstance::getFaceContext(v9, index, &ctx);
  v13 = ctx.m_face.m_numEdges;
  ctx.m_face.m_startEdgeIndex = v9->m_numOriginalEdges + v9->m_ownedEdges.m_size;
  ctx.m_flags.m_storage = 2;
  hkaiNavMeshInstance::appendFaces(v9, &ctx, 1);
  if ( v9->m_faceClearanceIndices.m_size == (v9->m_faceClearanceIndices.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v9->m_faceClearanceIndices,
      4);
  v14 = v13;
  v9->m_faceClearanceIndices.m_data[v9->m_faceClearanceIndices.m_size++] = -1;
  if ( (_DWORD)v13 )
  {
    v51 = 40 * v13;
    v15 = (hkaiNavMeshInstance::AddEdgeContext *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                                   (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                                   &v51);
    v14 = v51 / 40;
  }
  else
  {
    v15 = 0i64;
  }
  v16 = 2147483648;
  ctxs = v15;
  if ( v14 )
    v16 = v14;
  v17 = v13;
  v50 = v16;
  if ( (signed int)v13 > 0 )
  {
    v18 = (signed __int64)&v15->m_edge.m_oppositeEdge;
    do
    {
      if ( v18 != 8 )
      {
        *(_DWORD *)(v18 + 4) = -1;
        *(_DWORD *)v18 = -1;
        *(_DWORD *)(v18 + 8) = 4;
        *(_WORD *)(v18 + 28) = -1;
        *(_QWORD *)(v18 + 12) = 0i64;
        *(_QWORD *)(v18 + 20) = 0i64;
      }
      v18 += 40i64;
      --v17;
    }
    while ( v17 );
  }
  if ( v12->m_numEdges > 0 )
  {
    v19 = ctxs;
    do
    {
      hkaiNavMeshInstance::getEdgeContext(v9, v11 + v12->m_startEdgeIndex, &v19[v11]);
      v19[v11].m_cutInfo = v11;
      ++v11;
    }
    while ( v11 < v12->m_numEdges );
    v16 = v50;
  }
  hkaiNavMeshInstance::appendEdges(v9, ctxs, v13);
  v20 = magic;
  v21 = index;
  v9->m_faceFlags.m_data[v21].m_storage = 1;
  v20->m_data[v21] = v20->m_size;
  if ( v20->m_size == (v20->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v20, 4);
  v20->m_data[v20->m_size++] = index;
  v22 = 0;
  if ( ctx.m_face.m_numEdges > 0 )
  {
    v23 = v52 << 22;
    while ( 1 )
    {
      v24 = v9->m_numOriginalEdges;
      v25 = v22 + ctx.m_face.m_startEdgeIndex;
      v26 = v23 | (v22 + v12->m_startEdgeIndex);
      if ( v22 + ctx.m_face.m_startEdgeIndex < v24 )
      {
        if ( v9->m_edgeMap.m_size )
          v25 = v9->m_edgeMap.m_data[v25];
        if ( v25 == -1 )
        {
          v29 = 0i64;
          goto LABEL_29;
        }
        v27 = v25;
        v28 = v9->m_instancedEdges.m_data;
      }
      else
      {
        v27 = v25 - v24;
        v28 = v9->m_ownedEdges.m_data;
      }
      v29 = (signed __int64)&v28[v27];
LABEL_29:
      v30 = *(_DWORD *)(v29 + 8);
      if ( v30 == -1 )
      {
        hkaiNavMeshCutter::SavedConnectivity::popConnectivityForEdgeAndFace(v60, v7, v26);
      }
      else
      {
        if ( *(_BYTE *)(v29 + 16) & 0x40 )
          v31 = v30 & 0xFFC00000;
        else
          v31 = v9->m_runtimeId << 22;
        v32 = v31 | v30 & 0x3FFFFF;
        if ( v30 == -1 )
          v32 = -1;
        v33 = v32 >> 22;
        v34 = v7->m_instances.m_data[v32 >> 22].m_instancePtr;
        if ( v34->m_faceFlags.m_size )
        {
          v35 = v34->m_faceFlags.m_data[*(_DWORD *)(v29 + 12) & 0x3FFFFF].m_storage;
          v36 = &v58;
          v58 = v35;
        }
        else
        {
          v59 = 0;
          v36 = &v59;
        }
        if ( !(*v36 & 2) )
          goto LABEL_48;
        hkaiNavMeshCutter::SavedConnectivity::popConnectivityForEdgeAndFace(v60, v7, v26);
        v37 = v32 & 0x3FFFFF;
        v38 = v7->m_instances.m_data[v33].m_instancePtr;
        v39 = v38->m_numOriginalEdges;
        if ( v37 >= v39 )
        {
          v40 = v37 - v39;
          v41 = v38->m_ownedEdges.m_data;
LABEL_47:
          v42 = (signed __int64)&v41[v40];
          *(_DWORD *)(v42 + 12) = -1;
          *(_DWORD *)(v42 + 8) = -1;
          goto LABEL_48;
        }
        if ( v38->m_edgeMap.m_size )
          v37 = v38->m_edgeMap.m_data[v37];
        if ( v37 != -1 )
        {
          v40 = v37;
          v41 = v38->m_instancedEdges.m_data;
          goto LABEL_47;
        }
        MEMORY[0xC] = -1;
        MEMORY[8] = -1;
      }
LABEL_48:
      *(_DWORD *)(v29 + 8) = -1;
      *(_DWORD *)(v29 + 12) = -1;
      if ( ++v22 >= ctx.m_face.m_numEdges )
      {
        v16 = v50;
        break;
      }
    }
  }
  v43 = v12->m_startEdgeIndex;
  v44 = v56 & 0x3FFFFF;
  v57 = v56 & 0x3FFFFF;
  if ( v43 < v43 + v12->m_numEdges )
  {
    v45 = edgeMap;
    v46 = v52;
    do
    {
      if ( v43 != v44 )
      {
        if ( hkaiNavMeshInstance_get_hkaiNavMesh::Edge__18(
               v9->m_originalEdges,
               v9->m_numOriginalEdges,
               &v9->m_instancedEdges,
               &v9->m_ownedEdges,
               &v9->m_edgeMap,
               v43)->m_oppositeEdge != -1 )
        {
          v47 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v48 = (_DWORD *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v47[11] + 8i64))(v47[11], 16i64);
          if ( v48 )
          {
            v48[3] = 2147483648;
            *(_QWORD *)v48 = 0i64;
            v48[2] = 0;
          }
          else
          {
            v48 = 0i64;
          }
          v49 = v53 | (v46 << 22);
          if ( v48[2] == (v48[3] & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v48, 4);
          *(_DWORD *)(*(_QWORD *)v48 + 4i64 * (signed int)v48[2]++) = v49;
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v45->m_map.m_elem,
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
            (v46 << 22) | v43,
            (unsigned __int64)v48);
        }
        v44 = v57;
      }
      ++v43;
    }
    while ( v43 < v12->m_startEdgeIndex + v12->m_numEdges );
    v16 = v50;
  }
  if ( v16 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      ctxs,
      40 * (v16 & 0x3FFFFFFF));
}

// File Line: 155
// RVA: 0xC1B640
hkSimdFloat32 *__fastcall hkaiNavMeshCutterHelper::edgeEndpointDistance(hkSimdFloat32 *result, hkaiNavMeshInstance *meshA, hkaiNavMeshInstance *meshB, hkVector4f *up, int edgeA, int edgeB)
{
  hkVector4f *v6; // rdi
  hkaiNavMeshInstance *v7; // rbx
  hkSimdFloat32 *v8; // rsi
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
  hkVector4f v27; // [rsp+20h] [rbp-88h]
  hkVector4f v28; // [rsp+30h] [rbp-78h]
  hkVector4f v29; // [rsp+40h] [rbp-68h]
  hkVector4f v30; // [rsp+50h] [rbp-58h]

  v6 = up;
  v7 = meshB;
  v8 = result;
  hkaiNavMeshInstance::getEdgePoints(meshA, edgeA, &v27, &v28);
  hkaiNavMeshInstance::getEdgePoints(v7, edgeB, &v29, &v30);
  v9 = _mm_mul_ps(v6->m_quad, v27.m_quad);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_mul_ps(v6->m_quad, v28.m_quad);
  v12 = _mm_sub_ps(
          (__m128)0i64,
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170)));
  v13 = _mm_mul_ps(v6->m_quad, v29.m_quad);
  v14 = _mm_add_ps(v28.m_quad, _mm_mul_ps(v12, v6->m_quad));
  v15 = _mm_sub_ps(
          (__m128)0i64,
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170)));
  v16 = _mm_mul_ps(v6->m_quad, v30.m_quad);
  v17 = _mm_sub_ps(v14, _mm_add_ps(v29.m_quad, _mm_mul_ps(v15, v6->m_quad)));
  v18 = _mm_mul_ps(v17, v17);
  v19 = _mm_sub_ps(
          _mm_add_ps(v27.m_quad, _mm_mul_ps(_mm_sub_ps((__m128)0i64, v10), v6->m_quad)),
          _mm_add_ps(
            v30.m_quad,
            _mm_mul_ps(
              _mm_sub_ps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                  _mm_shuffle_ps(v16, v16, 170))),
              v6->m_quad)));
  v20 = v8;
  v21 = _mm_mul_ps(v19, v19);
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v23 = _mm_rsqrt_ps(v22);
  v24 = _mm_andnot_ps(
          _mm_cmpleps(v22, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v23), v23)),
              _mm_mul_ps(*(__m128 *)_xmm, v23)),
            v22));
  v25 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v26 = _mm_rsqrt_ps(v25);
  v8->m_real = _mm_add_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v25, (__m128)0i64),
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
  hkArray<int,hkContainerTempAllocator> *v2; // rbx
  int v3; // edx
  int v4; // edi

  v2 = edgeBlocks;
  v3 = edgeBlocks->m_size;
  v4 = eIdx;
  if ( !(v3 % 2) )
  {
    if ( v3 == (v2->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v2, 4);
    v2->m_data[v2->m_size++] = v4;
  }
}

// File Line: 180
// RVA: 0xC1BDA0
void __fastcall handleNonBoundary(int eIdx, hkArray<int,hkContainerTempAllocator> *edgeBlocks)
{
  __int64 v2; // r8
  hkArray<int,hkContainerTempAllocator> *v3; // rbx
  int v4; // edi

  v2 = edgeBlocks->m_size;
  v3 = edgeBlocks;
  v4 = eIdx;
  if ( edgeBlocks->m_size % 2 == 1 )
  {
    if ( eIdx == edgeBlocks->m_data[v2 - 1] + 1 )
    {
      edgeBlocks->m_size = v2 - 1;
    }
    else
    {
      if ( (_DWORD)v2 == (edgeBlocks->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, edgeBlocks, 4);
      v3->m_data[v3->m_size++] = v4;
    }
  }
}

// File Line: 196
// RVA: 0xC1B850
void __fastcall hkaiNavMeshCutterHelper::mergeContiguousBoundaryEdges(hkaiStreamingCollection *collection, hkaiNavMesh::Face *originalFace, unsigned int originalEdgeKey, int cutFaceIndex)
{
  unsigned int v4; // er15
  hkaiNavMeshInstance *v5; // rsi
  int v6; // eax
  hkaiNavMesh::Face *v7; // r14
  signed __int64 v8; // rbx
  signed __int64 v9; // rdi
  int v10; // eax
  signed __int64 v11; // r12
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v12; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v13; // rcx
  __int64 v14; // r14
  hkaiNavMesh::Edge *v15; // r9
  unsigned __int16 v16; // r8
  char *v17; // rdx
  int v18; // er8
  signed int *v19; // rcx
  __int64 v20; // r9
  signed int v21; // eax
  int v22; // edi
  int v23; // er15
  int v24; // er12
  signed __int64 v25; // rbx
  __int64 v26; // r13
  int v27; // edx
  hkaiNavMesh::Edge *v28; // r8
  signed __int64 v29; // r9
  signed __int64 v30; // rdx
  int v31; // ecx
  int v32; // eax
  hkResultEnum v33; // ebx
  hkResultEnum v34; // er14
  int v35; // edi
  int v36; // er15
  int v37; // ebx
  int v38; // er13
  hkaiNavMesh::Edge *v39; // rax
  hkaiNavMesh::Edge *v40; // r9
  unsigned int v41; // edx
  signed int v42; // ecx
  __int64 v43; // r8
  hkResult *v44; // rax
  int v45; // eax
  int v46; // edx
  signed __int64 v47; // rcx
  __int64 v48; // rax
  signed __int64 v49; // rdx
  int index; // [rsp+28h] [rbp-19h]
  hkaiNavMesh::Face *v51; // [rsp+30h] [rbp-11h]
  signed __int64 v52; // [rsp+38h] [rbp-9h]
  int *array; // [rsp+40h] [rbp-1h]
  int v54; // [rsp+48h] [rbp+7h]
  int v55; // [rsp+4Ch] [rbp+Bh]
  _QWORD *retaddr; // [rsp+A8h] [rbp+67h]
  int v57; // [rsp+B0h] [rbp+6Fh]
  hkResult result; // [rsp+B8h] [rbp+77h]
  int v59; // [rsp+C0h] [rbp+7Fh]

  v4 = (originalEdgeKey & 0x3FFFFF) - originalFace->m_startEdgeIndex;
  index = originalEdgeKey >> 22;
  v5 = collection->m_instances.m_data[originalEdgeKey >> 22].m_instancePtr;
  v6 = v5->m_numOriginalFaces;
  if ( cutFaceIndex < v6 )
  {
    if ( v5->m_faceMap.m_size )
      cutFaceIndex = v5->m_faceMap.m_data[cutFaceIndex];
    if ( cutFaceIndex == -1 )
      v7 = 0i64;
    else
      v7 = &v5->m_instancedFaces.m_data[cutFaceIndex];
  }
  else
  {
    v7 = &v5->m_ownedFaces.m_data[cutFaceIndex - v6];
  }
  v51 = v7;
  array = 0i64;
  v54 = 0;
  v55 = 2147483648;
  hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 8, 4);
  v8 = v7->m_startEdgeIndex;
  v9 = v8;
  v10 = v8 + v7->m_numEdges;
  v11 = v10;
  result.m_enum = v8 + v7->m_numEdges;
  if ( v8 < v10 )
  {
    v12 = &v5->m_ownedEdges;
    v13 = &v5->m_instancedEdges;
    do
    {
      v14 = v5->m_numOriginalEdges;
      v15 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__18(
              v5->m_originalEdges,
              v5->m_numOriginalEdges,
              v13,
              v12,
              &v5->m_edgeMap,
              v8);
      if ( (signed int)v8 < (signed int)v14 )
        v16 = -1;
      else
        v16 = v5->m_cuttingInfo.m_data[v9 - v14];
      if ( v16 != v4 || v15->m_oppositeFace != -1 )
        handleNonBoundary(v8, (hkArray<int,hkContainerTempAllocator> *)&array);
      else
        handleBoundary(v8, (hkArray<int,hkContainerTempAllocator> *)&array);
      ++v9;
      LODWORD(v8) = v8 + 1;
      v12 = &v5->m_ownedEdges;
      v13 = &v5->m_instancedEdges;
    }
    while ( v9 < v11 );
    v7 = v51;
    v10 = result.m_enum;
  }
  handleNonBoundary(v10, (hkArray<int,hkContainerTempAllocator> *)&array);
  v17 = (char *)array;
  if ( v54 )
  {
    v18 = 0;
    if ( v54 > 0 )
    {
      v19 = array;
      v20 = ((unsigned int)(v54 - 1) >> 1) + 1;
      do
      {
        v21 = v19[1];
        v19 += 2;
        v18 = v21 - *(v19 - 2) + v18 - 1;
        --v20;
      }
      while ( v20 );
    }
    if ( v7->m_numEdges - (signed __int16)v18 >= 3 )
    {
      v22 = 0;
      v7->m_numEdges -= v18;
      v17 = (char *)array;
      v23 = v5->m_numOriginalEdges;
      v24 = *array;
      v57 = v5->m_numOriginalEdges;
      v25 = *array;
      if ( v54 > 0 )
      {
        v26 = 0i64;
        do
        {
          hkaiNavMeshInstance::copyOwnedEdge(v5, v24 - v23, *(_DWORD *)&v17[v26 * 4] - v23);
          v27 = v5->m_numOriginalEdges;
          v28 = v5->m_ownedEdges.m_data;
          v29 = (signed __int64)&v28[array[v26 + 1] - v27 - 1];
          if ( v24 < v27 )
          {
            if ( v5->m_edgeMap.m_size )
              v31 = v5->m_edgeMap.m_data[v25];
            else
              v31 = v24;
            if ( v31 == -1 )
              v30 = 0i64;
            else
              v30 = (signed __int64)&v5->m_instancedEdges.m_data[v31];
          }
          else
          {
            v30 = (signed __int64)&v28[v24 - v27];
          }
          v22 += 2;
          *(_DWORD *)(v30 + 4) = *(_DWORD *)(v29 + 4);
          v17 = (char *)array;
          v32 = v54;
          ++v24;
          v52 = v25 + 1;
          v33 = array[v26 + 1];
          v59 = v22;
          if ( v22 >= v54 )
            v34 = result.m_enum;
          else
            v34 = array[v26 + 2];
          if ( v33 < v34 )
          {
            v35 = v24 - v23;
            v36 = -v23;
            v24 += v34 - v33;
            v52 += (unsigned int)(v34 - v33);
            do
              hkaiNavMeshInstance::copyOwnedEdge(v5, v35++, v36 + v33++);
            while ( v33 < v34 );
            v32 = v54;
            v17 = (char *)array;
            v22 = v59;
            v23 = v57;
          }
          v25 = v52;
          v26 += 2i64;
        }
        while ( v22 < v32 );
        v7 = v51;
      }
      v37 = v7->m_startEdgeIndex;
      if ( v7->m_startEdgeIndex < v7->m_startEdgeIndex + v7->m_numEdges )
      {
        v38 = index;
        while ( 1 )
        {
          v39 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__18(
                  v5->m_originalEdges,
                  v5->m_numOriginalEdges,
                  &v5->m_instancedEdges,
                  &v5->m_ownedEdges,
                  &v5->m_edgeMap,
                  v37);
          v40 = v39;
          v41 = v39->m_oppositeEdge;
          if ( v41 == -1 )
            goto LABEL_64;
          if ( v39->m_flags.m_storage & 0x40 )
            v42 = v41 >> 22;
          else
            v42 = v5->m_runtimeId;
          if ( v41 == -1 )
            v42 = -1;
          v43 = *(_QWORD *)(retaddr[4] + 48i64 * v42);
          if ( *(_DWORD *)(v43 + 328) )
          {
            v44 = &result;
            LOBYTE(result.m_enum) = *(_BYTE *)((v40->m_oppositeFace & 0x3FFFFF) + *(_QWORD *)(v43 + 320));
          }
          else
          {
            LOBYTE(v59) = 0;
            v44 = (hkResult *)&v59;
          }
          if ( v44->m_enum & 1 )
            goto LABEL_64;
          v45 = *(_DWORD *)(v43 + 40);
          v46 = v41 & 0x3FFFFF;
          if ( v46 >= v45 )
            break;
          if ( *(_DWORD *)(v43 + 216) )
            v46 = *(_DWORD *)(*(_QWORD *)(v43 + 208) + 4i64 * v46);
          if ( v46 != -1 )
          {
            v47 = 5i64 * v46;
            v48 = *(_QWORD *)(v43 + 256);
            goto LABEL_62;
          }
          v49 = 0i64;
LABEL_63:
          *(_DWORD *)(v49 + 8) = v37 | (v38 << 22);
LABEL_64:
          if ( ++v37 >= v7->m_startEdgeIndex + v7->m_numEdges )
          {
            v17 = (char *)array;
            goto LABEL_66;
          }
        }
        v47 = 5i64 * (v46 - v45);
        v48 = *(_QWORD *)(v43 + 288);
LABEL_62:
        v49 = v48 + 4 * v47;
        goto LABEL_63;
      }
    }
  }
LABEL_66:
  v54 = 0;
  if ( v55 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v17,
      4 * v55);
}


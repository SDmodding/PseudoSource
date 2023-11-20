// File Line: 17
// RVA: 0xC183F0
void __fastcall hkaiNavMeshCutter::calcNewConnectivity(hkaiNavMeshCutter *this, hkArrayBase<unsigned int> *uncutFaceKeys, hkArrayBase<unsigned int> *cutFaceKeys, hkaiNavMeshCutter::SavedConnectivity *tempConnectivity, hkArray<unsigned int,hkContainerTempAllocator> *forceRecutFaceKeys)
{
  int v5; // esi
  hkArrayBase<unsigned int> *v6; // rax
  hkaiNavMeshCutter *v7; // r11
  __int64 v8; // rcx
  unsigned int v9; // er10
  hkaiStreamingCollection::InstanceInfo *v10; // rcx
  __int64 v11; // rbx
  hkaiNavMeshInstance *v12; // r14
  __int64 index; // rbp
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v14; // rcx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v15; // r8
  hkaiNavMesh::Edge *v16; // rax
  unsigned int v17; // edx
  unsigned int v18; // er8
  unsigned int v19; // er12
  char v20; // cl
  unsigned int v21; // eax
  int v22; // ebx
  unsigned int v23; // eax
  unsigned int v24; // er15
  hkaiNavMeshInstance *v25; // rsi
  char *v26; // rax
  __int64 v27; // r8
  int v28; // edx
  __int64 v29; // rcx
  unsigned int *v30; // rax
  __int64 v31; // r8
  int v32; // edx
  __int64 v33; // rcx
  unsigned int *v34; // rax
  hkaiNavMesh::Edge *v35; // rax
  unsigned int v36; // edx
  unsigned int v37; // ecx
  unsigned int v38; // eax
  int v39; // edx
  hkaiNavMeshInstance *v40; // r8
  int v41; // eax
  signed __int64 v42; // rbx
  signed int v43; // ecx
  signed __int64 v44; // rcx
  hkaiNavMesh::Edge *v45; // rax
  int v46; // ecx
  hkaiNavMesh::Edge *v47; // rax
  char v48; // [rsp+40h] [rbp-88h]
  char v49; // [rsp+41h] [rbp-87h]
  unsigned int v50; // [rsp+44h] [rbp-84h]
  int v51; // [rsp+48h] [rbp-80h]
  unsigned __int64 v52; // [rsp+50h] [rbp-78h]
  __int64 v53; // [rsp+58h] [rbp-70h]
  hkaiNavMesh::Face *v54; // [rsp+60h] [rbp-68h]
  hkArray<hkaiNavMeshCutter::FaceEdgePair,hkContainerTempAllocator> cutPairs; // [rsp+68h] [rbp-60h]
  hkaiNavMeshCutter *v56; // [rsp+D0h] [rbp+8h]
  hkArrayBase<unsigned int> *v57; // [rsp+D8h] [rbp+10h]
  hkArrayBase<unsigned int> *v58; // [rsp+E0h] [rbp+18h]
  hkaiNavMeshCutter::SavedConnectivity *connectivityInfo; // [rsp+E8h] [rbp+20h]

  connectivityInfo = tempConnectivity;
  v58 = cutFaceKeys;
  v57 = uncutFaceKeys;
  v56 = this;
  v5 = 0;
  v6 = uncutFaceKeys;
  v7 = this;
  v51 = 0;
  if ( uncutFaceKeys->m_size <= 0 )
    return;
  v8 = 0i64;
  v53 = 0i64;
  do
  {
    v9 = *(unsigned int *)((char *)v6->m_data + v8);
    v10 = v7->m_streamingCollection.m_pntr->m_instances.m_data;
    v11 = v9 >> 22;
    v50 = v9 >> 22;
    v12 = v10[v11].m_instancePtr;
    v54 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__14(
            v12->m_originalFaces,
            v12->m_numOriginalFaces,
            &v12->m_instancedFaces,
            &v12->m_ownedFaces,
            &v12->m_faceMap,
            v9 & 0x3FFFFF);
    index = v54->m_startEdgeIndex;
    if ( (signed int)index >= (signed int)index + v54->m_numEdges )
      goto LABEL_69;
    v14 = &v12->m_instancedEdges;
    v15 = &v12->m_ownedEdges;
    v52 = 4 * index;
    do
    {
      v16 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__16(
              v12->m_originalEdges,
              v12->m_numOriginalEdges,
              v14,
              v15,
              &v12->m_edgeMap,
              index);
      v17 = v16->m_oppositeEdge;
      if ( v17 == -1 )
      {
        v7 = v56;
        goto LABEL_67;
      }
      v18 = v16->m_oppositeFace;
      v19 = index | ((_DWORD)v11 << 22);
      v20 = v16->m_flags.m_storage & 0x40;
      if ( v20 )
        v21 = v18 & 0xFFC00000;
      else
        v21 = v12->m_runtimeId << 22;
      v22 = v21 | v18 & 0x3FFFFF;
      if ( v18 == -1 )
        v22 = -1;
      if ( v20 )
        v23 = v17 & 0xFFC00000;
      else
        v23 = v12->m_runtimeId << 22;
      v7 = v56;
      v24 = v23 | v17 & 0x3FFFFF;
      if ( v17 == -1 )
        v24 = -1;
      v25 = v56->m_streamingCollection.m_pntr->m_instances.m_data[v24 >> 22].m_instancePtr;
      if ( v25->m_faceFlags.m_size )
      {
        v26 = &v48;
        v48 = v25->m_faceFlags.m_data[v18 & 0x3FFFFF].m_storage;
      }
      else
      {
        v49 = 0;
        v26 = &v49;
      }
      if ( *v26 & 1 )
      {
        v27 = v58->m_size;
        v28 = 0;
        v29 = 0i64;
        if ( v27 <= 0 )
          goto LABEL_26;
        v30 = v58->m_data;
        while ( *v30 != v22 )
        {
          ++v29;
          ++v28;
          ++v30;
          if ( v29 >= v27 )
            goto LABEL_26;
        }
        if ( v28 == -1 )
        {
LABEL_26:
          v31 = forceRecutFaceKeys->m_size;
          v32 = 0;
          v33 = 0i64;
          if ( v31 > 0 )
          {
            v34 = forceRecutFaceKeys->m_data;
            while ( *v34 != v22 )
            {
              ++v33;
              ++v32;
              ++v34;
              if ( v33 >= v31 )
                goto LABEL_32;
            }
            if ( v32 != -1 )
              goto LABEL_66;
          }
LABEL_32:
          cutPairs.m_data = 0i64;
          cutPairs.m_size = 0;
          cutPairs.m_capacityAndFlags = 2147483648;
          hkaiNavMeshCutter::gatherCutEdges(v56, v24, v22, &cutPairs, 0);
          if ( cutPairs.m_size > 1 )
          {
LABEL_33:
            if ( forceRecutFaceKeys->m_size == (forceRecutFaceKeys->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
                forceRecutFaceKeys,
                4);
            forceRecutFaceKeys->m_data[forceRecutFaceKeys->m_size++] = v22;
            goto LABEL_62;
          }
          if ( cutPairs.m_size == 1 )
          {
            v35 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__16(
                    v25->m_originalEdges,
                    v25->m_numOriginalEdges,
                    &v25->m_instancedEdges,
                    &v25->m_ownedEdges,
                    &v25->m_edgeMap,
                    cutPairs.m_data->m_edgeKey & 0x3FFFFF);
            v36 = v35->m_oppositeEdge;
            if ( v36 == -1 )
              goto LABEL_33;
            if ( v35->m_flags.m_storage & 0x40 )
              v37 = v36 & 0xFFC00000;
            else
              v37 = v25->m_runtimeId << 22;
            v38 = v37 | v36 & 0x3FFFFF;
            if ( v36 == -1 )
              v38 = -1;
            v39 = v38 & 0x3FFFFF;
            v40 = v56->m_streamingCollection.m_pntr->m_instances.m_data[v38 >> 22].m_instancePtr;
            v41 = v40->m_numOriginalEdges;
            if ( v39 < v41 )
            {
              if ( v40->m_edgeMap.m_size )
                v39 = v40->m_edgeMap.m_data[v39];
              if ( v39 == -1 )
                v42 = 0i64;
              else
                v42 = (signed __int64)&v40->m_instancedEdges.m_data[v39];
            }
            else
            {
              v42 = (signed __int64)&v40->m_ownedEdges.m_data[v39 - v41];
            }
            hkaiNavMeshCutterHelper::connectCutFaceToUncutFace(
              v56->m_streamingCollection.m_pntr,
              connectivityInfo,
              v19,
              v24,
              (hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *)&cutPairs.m_data);
            if ( cutPairs.m_size == 1 )
            {
              *(_DWORD *)(v42 + 12) = -1;
              *(_DWORD *)(v42 + 8) = -1;
            }
LABEL_62:
            cutPairs.m_size = 0;
            if ( cutPairs.m_capacityAndFlags >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                cutPairs.m_data,
                8 * cutPairs.m_capacityAndFlags);
            v7 = v56;
            cutPairs.m_data = 0i64;
            cutPairs.m_capacityAndFlags = 2147483648;
            goto LABEL_66;
          }
          hkaiNavMeshCutter::SavedConnectivity::addConnectivity(connectivityInfo, v19);
          v43 = v12->m_numOriginalEdges;
          if ( (signed int)index >= v43 )
          {
            v44 = (signed int)index - v43;
            v45 = v12->m_ownedEdges.m_data;
            goto LABEL_60;
          }
          if ( v12->m_edgeMap.m_size )
            v46 = v12->m_edgeMap.m_data[v52 / 4];
          else
            v46 = index;
          if ( v46 == -1 )
          {
            v47 = hkaiNavMeshInstance_instance_hkaiNavMesh::Edge_int__3(
                    v12->m_originalEdges,
                    &v12->m_instancedEdges,
                    v12->m_originalEdgeData,
                    &v12->m_instancedEdgeData,
                    &v12->m_edgeMap,
                    index,
                    v12->m_edgeDataStriding);
          }
          else
          {
            v44 = v46;
            v45 = v12->m_instancedEdges.m_data;
LABEL_60:
            v47 = &v45[v44];
          }
          v47->m_oppositeFace = -1;
          v47->m_oppositeEdge = -1;
          goto LABEL_62;
        }
      }
LABEL_66:
      LODWORD(v11) = v50;
LABEL_67:
      v52 += 4i64;
      LODWORD(index) = index + 1;
      v15 = &v12->m_ownedEdges;
      v14 = &v12->m_instancedEdges;
    }
    while ( (signed int)index < v54->m_startEdgeIndex + v54->m_numEdges );
    v5 = v51;
LABEL_69:
    v6 = v57;
    ++v5;
    v8 = v53 + 4;
    v51 = v5;
    v53 += 4i64;
  }
  while ( v5 < v57->m_size );
}

// File Line: 94
// RVA: 0xC18970
void __fastcall hkaiNavMeshCutter::restoreConnectivity(hkaiStreamingCollection *collection, hkArrayBase<unsigned int> *updatedFaceKeys, hkaiNavMeshCutter::SavedConnectivity *connectivity)
{
  int v3; // edi
  hkaiNavMeshCutter::SavedConnectivity *v4; // rbp
  hkArrayBase<unsigned int> *v5; // r14
  hkaiStreamingCollection *v6; // r15
  __int64 v7; // rsi
  unsigned int v8; // ebx

  v3 = 0;
  v4 = connectivity;
  v5 = updatedFaceKeys;
  v6 = collection;
  if ( updatedFaceKeys->m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = v5->m_data[v7];
      hkaiNavMeshCutter::SavedConnectivity::popConnectivityForFace(v4, v6, v5->m_data[v7]);
      hkaiNavMeshCutter::SavedConnectivity::popConnectivityForOppositeFace(v4, v6, v8);
      ++v3;
      ++v7;
    }
    while ( v3 < v5->m_size );
  }
}

// File Line: 106
// RVA: 0xC17F90
void __fastcall hkaiNavMeshCutter::removeCutFacesFromOriginals(hkaiNavMeshCutter *this, hkArrayBase<int> *updatedSections, hkArrayBase<unsigned int> *updatedFaceKeys, hkaiNavMeshUtils::RemoveOwnedFacesMode rofMode)
{
  int v4; // er11
  int v5; // er14
  __int64 v6; // r13
  hkArrayBase<unsigned int> *v7; // r10
  hkArrayBase<int> *v8; // r15
  hkaiNavMeshCutter *v9; // rsi
  __int64 v10; // r12
  __int64 v11; // r8
  int v12; // edx
  __int64 v13; // r9
  unsigned int *v14; // rcx
  unsigned int *v15; // rbp
  hkaiStreamingCollection::InstanceInfo *v16; // rax
  hkaiNavMeshCutter::MeshInfo *v17; // r15
  hkaiNavMeshInstance *v18; // rsi
  unsigned int v19; // ebx
  signed int v20; // edi
  unsigned int *v21; // rdx
  __int64 v22; // r8
  int *v23; // rax
  int v24; // edi
  signed __int64 v25; // rbp
  signed __int64 v26; // r14
  int v27; // esi
  signed __int64 v28; // rbx
  char *v29; // rax
  int v30; // esi
  __int64 v31; // rbp
  hkaiNavMeshCutter::MeshInfo *v32; // rcx
  signed __int64 v33; // r8
  hkArray<int,hkContainerHeapAllocator> *v34; // rdi
  __int64 v35; // rcx
  int v36; // ebx
  signed __int64 v37; // rdx
  signed __int64 v38; // r9
  int v39; // ecx
  int *v40; // r10
  int v41; // eax
  int v42; // eax
  int v43; // er9
  char v44; // [rsp+30h] [rbp-98h]
  char v45; // [rsp+31h] [rbp-97h]
  _DWORD *array; // [rsp+38h] [rbp-90h]
  int v47; // [rsp+40h] [rbp-88h]
  int v48; // [rsp+44h] [rbp-84h]
  int v49; // [rsp+48h] [rbp-80h]
  int v50; // [rsp+4Ch] [rbp-7Ch]
  unsigned int v51; // [rsp+50h] [rbp-78h]
  hkaiNavMeshInstance *v52; // [rsp+58h] [rbp-70h]
  __int64 v53; // [rsp+60h] [rbp-68h]
  unsigned int *v54; // [rsp+68h] [rbp-60h]
  __int64 v55; // [rsp+70h] [rbp-58h]
  unsigned int *v56; // [rsp+78h] [rbp-50h]
  hkaiNavMeshCutter *v57; // [rsp+D0h] [rbp+8h]
  hkArrayBase<int> *result; // [rsp+D8h] [rbp+10h]
  hkArrayBase<unsigned int> *v59; // [rsp+E0h] [rbp+18h]
  hkaiNavMeshUtils::RemoveOwnedFacesMode mode; // [rsp+E8h] [rbp+20h]

  mode = rofMode;
  v59 = updatedFaceKeys;
  result = updatedSections;
  v57 = this;
  v4 = 0;
  v5 = 0;
  v6 = 0i64;
  v7 = updatedFaceKeys;
  v8 = updatedSections;
  v9 = this;
  v49 = 0;
  if ( updatedSections->m_size > 0 )
  {
    v10 = 0i64;
    v53 = 0i64;
    do
    {
      v11 = v7->m_size;
      v12 = v4;
      v13 = *(int *)((char *)v8->m_data + v10);
      if ( v6 < v11 )
      {
        v14 = &v7->m_data[v6];
        do
        {
          if ( *v14 >> 22 != (_DWORD)v13 )
            break;
          ++v6;
          ++v12;
          ++v14;
        }
        while ( v6 < v11 );
      }
      v15 = &v7->m_data[v4];
      v16 = v9->m_streamingCollection.m_pntr->m_instances.m_data;
      v17 = &v9->m_meshInfos.m_data[v13];
      v56 = &v7->m_data[v4];
      v18 = v16[v13].m_instancePtr;
      v19 = v12 - v4;
      LODWORD(v16) = v17->m_magic.m_capacityAndFlags & 0x3FFFFFFF;
      v50 = v12;
      v20 = (v12 - v4) | 0x80000000;
      v52 = v18;
      v51 = (v12 - v4) | 0x80000000;
      if ( v17->m_magic.m_size == (_DWORD)v16 )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v17->m_magic, 4);
      v17->m_magic.m_data[v17->m_magic.m_size++] = -1;
      array = 0i64;
      v47 = 0;
      v48 = 2147483648;
      if ( (signed int)v19 > 0 )
      {
        v21 = v15;
        v22 = v19;
        v54 = v15;
        v55 = v19;
        do
        {
          v23 = v17->m_magic.m_data;
          v24 = *v21 & 0x3FFFFF;
          v25 = v23[v24];
          if ( (signed int)v25 >= 0 )
          {
            v26 = v25;
            v27 = v23[v24];
            v28 = v23[v24];
            if ( v23[v25] == v24 )
            {
              do
              {
                if ( v47 == (v48 & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 4);
                ++v28;
                array[v47++] = v27;
                v17->m_magic.m_data[v26] = -1;
                v26 = v28;
                ++v27;
              }
              while ( v17->m_magic.m_data[v28] == v24 );
              v21 = v54;
              v22 = v55;
            }
            v18 = v52;
          }
          if ( (_DWORD)v25 != -1 )
          {
            if ( v18->m_faceFlags.m_size )
            {
              v29 = &v45;
              v45 = v18->m_faceFlags.m_data[v24].m_storage;
            }
            else
            {
              v44 = 0;
              v29 = &v44;
            }
            v18->m_faceFlags.m_data[v24].m_storage = *v29 & 0xFC;
            v17->m_magic.m_data[v24] = -1;
          }
          ++v21;
          v55 = --v22;
          v54 = v21;
        }
        while ( v22 );
        v20 = v51;
        v15 = v56;
        v5 = v49;
        v10 = v53;
      }
      hkaiNavMeshUtils::removeOwnedFaces(
        v18,
        v57->m_streamingCollection.m_pntr,
        (hkArray<int,hkContainerTempAllocator> *)&array,
        mode);
      hkaiNavMeshUtils::compactOwnedVertices(v18);
      v47 = 0;
      if ( v48 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          4 * v48);
      array = 0i64;
      v48 = 2147483648;
      if ( v20 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v15,
          4 * v20);
      v8 = result;
      v7 = v59;
      v4 = v50;
      v9 = v57;
      ++v5;
      v10 += 4i64;
      v49 = v5;
      v53 = v10;
    }
    while ( v5 < result->m_size );
  }
  hkaiNavMeshCutter::restoreConnectivity(v9->m_streamingCollection.m_pntr, v7, &v9->m_connectivityInfo);
  v30 = 0;
  if ( v8->m_size > 0 )
  {
    v31 = 0i64;
    do
    {
      v32 = &v57->m_meshInfos.m_data[v8->m_data[v31]];
      v33 = v32->m_originalNumFaces;
      v34 = &v32->m_magic;
      v35 = 0i64;
      if ( (signed int)v33 > 0 )
      {
        do
        {
          if ( v34->m_data[v35] != -1 )
            v34->m_data[v35] = -2;
          ++v35;
        }
        while ( v35 < v33 );
      }
      v36 = v33;
      if ( (signed int)v33 < v34->m_size )
      {
        v37 = v33;
        v38 = v33;
        do
        {
          v39 = v34->m_data[v38];
          if ( v39 != -1 )
          {
            v34->m_data[v37] = v39;
            v40 = &v34->m_data[v34->m_data[v37]];
            if ( *v40 == -2 || *v40 > v36 )
              *v40 = v36;
            ++v36;
            ++v37;
          }
          LODWORD(v33) = v33 + 1;
          ++v38;
        }
        while ( (signed int)v33 < v34->m_size );
      }
      v41 = v34->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v41 >= v36 )
      {
        LODWORD(result) = 0;
      }
      else
      {
        v42 = 2 * v41;
        v43 = v36;
        if ( v36 < v42 )
          v43 = v42;
        hkArrayUtil::_reserve(
          (hkResult *)&result,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v34,
          v43,
          4);
      }
      ++v30;
      v34->m_size = v36;
      ++v31;
    }
    while ( v30 < v8->m_size );
  }
}


// File Line: 17
// RVA: 0xC183F0
void __fastcall hkaiNavMeshCutter::calcNewConnectivity(
        hkaiNavMeshCutter *this,
        hkArrayBase<unsigned int> *uncutFaceKeys,
        hkArrayBase<unsigned int> *cutFaceKeys,
        hkaiNavMeshCutter::SavedConnectivity *tempConnectivity,
        hkArray<unsigned int,hkContainerTempAllocator> *forceRecutFaceKeys)
{
  int v5; // esi
  hkArrayBase<unsigned int> *v6; // rax
  hkaiNavMeshCutter *v7; // r11
  __int64 v8; // rcx
  unsigned int v9; // r10d
  hkaiStreamingCollection::InstanceInfo *m_data; // rcx
  __int64 v11; // rbx
  hkaiNavMeshInstance *m_instancePtr; // r14
  __int64 index; // rbp
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_instancedEdges; // rcx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_ownedEdges; // r8
  hkaiNavMesh::Edge *v16; // rax
  unsigned int m_oppositeEdge; // edx
  unsigned int m_oppositeFace; // r8d
  unsigned int v19; // r12d
  char v20; // cl
  unsigned int v21; // eax
  int v22; // ebx
  unsigned int v23; // eax
  unsigned int v24; // r15d
  hkaiNavMeshInstance *v25; // rsi
  char *v26; // rax
  __int64 m_size; // r8
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
  int m_numOriginalEdges; // eax
  __int64 v42; // rbx
  int v43; // ecx
  __int64 v44; // rcx
  hkaiNavMesh::Edge *v45; // rax
  int v46; // ecx
  hkaiNavMesh::Edge *v47; // rax
  char m_storage; // [rsp+40h] [rbp-88h] BYREF
  char v49; // [rsp+41h] [rbp-87h] BYREF
  unsigned int v50; // [rsp+44h] [rbp-84h]
  int v51; // [rsp+48h] [rbp-80h]
  unsigned __int64 v52; // [rsp+50h] [rbp-78h]
  __int64 v53; // [rsp+58h] [rbp-70h]
  hkaiNavMesh::Face *v54; // [rsp+60h] [rbp-68h]
  hkArray<hkaiNavMeshCutter::FaceEdgePair,hkContainerTempAllocator> cutPairs; // [rsp+68h] [rbp-60h] BYREF

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
    m_data = v7->m_streamingCollection.m_pntr->m_instances.m_data;
    v11 = v9 >> 22;
    v50 = v9 >> 22;
    m_instancePtr = m_data[v11].m_instancePtr;
    v54 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__14(
            m_instancePtr->m_originalFaces,
            m_instancePtr->m_numOriginalFaces,
            &m_instancePtr->m_instancedFaces,
            &m_instancePtr->m_ownedFaces,
            &m_instancePtr->m_faceMap,
            v9 & 0x3FFFFF);
    index = v54->m_startEdgeIndex;
    if ( (int)index >= (int)index + v54->m_numEdges )
      goto LABEL_65;
    p_m_instancedEdges = &m_instancePtr->m_instancedEdges;
    p_m_ownedEdges = &m_instancePtr->m_ownedEdges;
    v52 = 4 * index;
    do
    {
      v16 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__16(
              m_instancePtr->m_originalEdges,
              m_instancePtr->m_numOriginalEdges,
              p_m_instancedEdges,
              p_m_ownedEdges,
              &m_instancePtr->m_edgeMap,
              index);
      m_oppositeEdge = v16->m_oppositeEdge;
      if ( m_oppositeEdge == -1 )
      {
        v7 = this;
        goto LABEL_63;
      }
      m_oppositeFace = v16->m_oppositeFace;
      v19 = index | ((_DWORD)v11 << 22);
      v20 = v16->m_flags.m_storage & 0x40;
      if ( v20 )
        v21 = m_oppositeFace & 0xFFC00000;
      else
        v21 = m_instancePtr->m_runtimeId << 22;
      v22 = v21 | m_oppositeFace & 0x3FFFFF;
      if ( m_oppositeFace == -1 )
        v22 = -1;
      if ( v20 )
        v23 = m_oppositeEdge & 0xFFC00000;
      else
        v23 = m_instancePtr->m_runtimeId << 22;
      v7 = this;
      v24 = v23 | m_oppositeEdge & 0x3FFFFF;
      v25 = this->m_streamingCollection.m_pntr->m_instances.m_data[v24 >> 22].m_instancePtr;
      if ( v25->m_faceFlags.m_size )
      {
        v26 = &m_storage;
        m_storage = v25->m_faceFlags.m_data[m_oppositeFace & 0x3FFFFF].m_storage;
      }
      else
      {
        v49 = 0;
        v26 = &v49;
      }
      if ( (*v26 & 1) != 0 )
      {
        m_size = cutFaceKeys->m_size;
        v28 = 0;
        v29 = 0i64;
        if ( m_size <= 0 )
          goto LABEL_24;
        v30 = cutFaceKeys->m_data;
        while ( *v30 != v22 )
        {
          ++v29;
          ++v28;
          ++v30;
          if ( v29 >= m_size )
            goto LABEL_24;
        }
        if ( v28 == -1 )
        {
LABEL_24:
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
                goto LABEL_30;
            }
            if ( v32 != -1 )
              goto LABEL_62;
          }
LABEL_30:
          cutPairs.m_data = 0i64;
          cutPairs.m_size = 0;
          cutPairs.m_capacityAndFlags = 0x80000000;
          hkaiNavMeshCutter::gatherCutEdges(this, v24, v22, &cutPairs, GATHER_ALL_EDGES);
          if ( cutPairs.m_size > 1 )
          {
LABEL_31:
            if ( forceRecutFaceKeys->m_size == (forceRecutFaceKeys->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, forceRecutFaceKeys, 4);
            forceRecutFaceKeys->m_data[forceRecutFaceKeys->m_size++] = v22;
            goto LABEL_58;
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
              goto LABEL_31;
            if ( (v35->m_flags.m_storage & 0x40) != 0 )
              v37 = v36 & 0xFFC00000;
            else
              v37 = v25->m_runtimeId << 22;
            v38 = v37 | v36 & 0x3FFFFF;
            v39 = v37 & 0x3FFFFF | v36 & 0x3FFFFF;
            v40 = this->m_streamingCollection.m_pntr->m_instances.m_data[v38 >> 22].m_instancePtr;
            m_numOriginalEdges = v40->m_numOriginalEdges;
            if ( v39 < m_numOriginalEdges )
            {
              if ( v40->m_edgeMap.m_size )
                v39 = v40->m_edgeMap.m_data[v39];
              if ( v39 == -1 )
                v42 = 0i64;
              else
                v42 = (__int64)&v40->m_instancedEdges.m_data[v39];
            }
            else
            {
              v42 = (__int64)&v40->m_ownedEdges.m_data[v39 - m_numOriginalEdges];
            }
            hkaiNavMeshCutterHelper::connectCutFaceToUncutFace(
              this->m_streamingCollection.m_pntr,
              tempConnectivity,
              v19,
              v24,
              &cutPairs);
            if ( cutPairs.m_size == 1 )
            {
              *(_DWORD *)(v42 + 12) = -1;
              *(_DWORD *)(v42 + 8) = -1;
            }
LABEL_58:
            cutPairs.m_size = 0;
            if ( cutPairs.m_capacityAndFlags >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                &hkContainerTempAllocator::s_alloc,
                cutPairs.m_data,
                8 * cutPairs.m_capacityAndFlags);
            v7 = this;
            cutPairs.m_data = 0i64;
            cutPairs.m_capacityAndFlags = 0x80000000;
            goto LABEL_62;
          }
          hkaiNavMeshCutter::SavedConnectivity::addConnectivity(tempConnectivity, v19);
          v43 = m_instancePtr->m_numOriginalEdges;
          if ( (int)index >= v43 )
          {
            v44 = (int)index - v43;
            v45 = m_instancePtr->m_ownedEdges.m_data;
            goto LABEL_56;
          }
          if ( m_instancePtr->m_edgeMap.m_size )
            v46 = m_instancePtr->m_edgeMap.m_data[v52 / 4];
          else
            v46 = index;
          if ( v46 == -1 )
          {
            v47 = hkaiNavMeshInstance_instance_hkaiNavMesh::Edge_int__3(
                    m_instancePtr->m_originalEdges,
                    &m_instancePtr->m_instancedEdges,
                    m_instancePtr->m_originalEdgeData,
                    &m_instancePtr->m_instancedEdgeData,
                    &m_instancePtr->m_edgeMap,
                    index,
                    m_instancePtr->m_edgeDataStriding);
          }
          else
          {
            v44 = v46;
            v45 = m_instancePtr->m_instancedEdges.m_data;
LABEL_56:
            v47 = &v45[v44];
          }
          v47->m_oppositeFace = -1;
          v47->m_oppositeEdge = -1;
          goto LABEL_58;
        }
      }
LABEL_62:
      LODWORD(v11) = v50;
LABEL_63:
      v52 += 4i64;
      LODWORD(index) = index + 1;
      p_m_ownedEdges = &m_instancePtr->m_ownedEdges;
      p_m_instancedEdges = &m_instancePtr->m_instancedEdges;
    }
    while ( (int)index < v54->m_startEdgeIndex + v54->m_numEdges );
    v5 = v51;
LABEL_65:
    v6 = uncutFaceKeys;
    ++v5;
    v8 = v53 + 4;
    v51 = v5;
    v53 += 4i64;
  }
  while ( v5 < uncutFaceKeys->m_size );
}

// File Line: 94
// RVA: 0xC18970
void __fastcall hkaiNavMeshCutter::restoreConnectivity(
        hkaiStreamingCollection *collection,
        hkArrayBase<unsigned int> *updatedFaceKeys,
        hkaiNavMeshCutter::SavedConnectivity *connectivity)
{
  int v3; // edi
  __int64 v7; // rsi
  unsigned int v8; // ebx

  v3 = 0;
  if ( updatedFaceKeys->m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = updatedFaceKeys->m_data[v7];
      hkaiNavMeshCutter::SavedConnectivity::popConnectivityForFace(connectivity, collection, v8);
      hkaiNavMeshCutter::SavedConnectivity::popConnectivityForOppositeFace(connectivity, collection, v8);
      ++v3;
      ++v7;
    }
    while ( v3 < updatedFaceKeys->m_size );
  }
}

// File Line: 106
// RVA: 0xC17F90
void __fastcall hkaiNavMeshCutter::removeCutFacesFromOriginals(
        hkaiNavMeshCutter *this,
        hkArrayBase<int> *updatedSections,
        hkArrayBase<unsigned int> *updatedFaceKeys,
        hkaiNavMeshUtils::RemoveOwnedFacesMode rofMode)
{
  int v4; // r11d
  int v5; // r14d
  __int64 v6; // r13
  hkArrayBase<unsigned int> *v7; // r10
  hkArrayBase<int> *v8; // r15
  hkaiNavMeshCutter *v9; // rsi
  __int64 v10; // r12
  __int64 m_size; // r8
  int v12; // edx
  __int64 v13; // r9
  unsigned int *v14; // rcx
  unsigned int *v15; // rbp
  hkaiStreamingCollection::InstanceInfo *m_data; // rax
  hkaiNavMeshCutter::MeshInfo *v17; // r15
  hkaiNavMeshInstance *m_instancePtr; // rsi
  int v19; // ebx
  signed int v20; // edi
  unsigned int *v21; // rdx
  __int64 v22; // r8
  int *v23; // rax
  int v24; // edi
  __int64 v25; // rbp
  __int64 v26; // r14
  int v27; // esi
  __int64 v28; // rbx
  char *v29; // rax
  int v30; // esi
  __int64 v31; // rbp
  hkaiNavMeshCutter::MeshInfo *v32; // rcx
  __int64 m_originalNumFaces; // r8
  hkArray<int,hkContainerHeapAllocator> *p_m_magic; // rdi
  __int64 v35; // rcx
  int v36; // ebx
  __int64 v37; // rdx
  __int64 v38; // r9
  int v39; // ecx
  int *v40; // r10
  int v41; // eax
  int v42; // eax
  int v43; // r9d
  char v44; // [rsp+30h] [rbp-98h] BYREF
  char m_storage; // [rsp+31h] [rbp-97h] BYREF
  hkArray<int,hkContainerTempAllocator> array; // [rsp+38h] [rbp-90h] BYREF
  int v47; // [rsp+48h] [rbp-80h]
  int v48; // [rsp+4Ch] [rbp-7Ch]
  int v49; // [rsp+50h] [rbp-78h]
  hkaiNavMeshInstance *v50; // [rsp+58h] [rbp-70h]
  __int64 v51; // [rsp+60h] [rbp-68h]
  unsigned int *v52; // [rsp+68h] [rbp-60h]
  __int64 v53; // [rsp+70h] [rbp-58h]
  unsigned int *v54; // [rsp+78h] [rbp-50h]
  hkArrayBase<int> *result; // [rsp+D8h] [rbp+10h] BYREF
  hkArrayBase<unsigned int> *v57; // [rsp+E0h] [rbp+18h]
  hkaiNavMeshUtils::RemoveOwnedFacesMode mode; // [rsp+E8h] [rbp+20h]

  mode = rofMode;
  v57 = updatedFaceKeys;
  result = updatedSections;
  v4 = 0;
  v5 = 0;
  v6 = 0i64;
  v7 = updatedFaceKeys;
  v8 = updatedSections;
  v9 = this;
  v47 = 0;
  if ( updatedSections->m_size > 0 )
  {
    v10 = 0i64;
    v51 = 0i64;
    do
    {
      m_size = v7->m_size;
      v12 = v4;
      v13 = *(int *)((char *)v8->m_data + v10);
      if ( v6 < m_size )
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
        while ( v6 < m_size );
      }
      v15 = &v7->m_data[v4];
      m_data = v9->m_streamingCollection.m_pntr->m_instances.m_data;
      v17 = &v9->m_meshInfos.m_data[v13];
      v54 = v15;
      m_instancePtr = m_data[v13].m_instancePtr;
      v19 = v12 - v4;
      LODWORD(m_data) = v17->m_magic.m_capacityAndFlags & 0x3FFFFFFF;
      v48 = v12;
      v20 = (v12 - v4) | 0x80000000;
      v50 = m_instancePtr;
      v49 = v20;
      if ( v17->m_magic.m_size == (_DWORD)m_data )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v17->m_magic, 4);
      v17->m_magic.m_data[v17->m_magic.m_size++] = -1;
      array.m_data = 0i64;
      array.m_size = 0;
      array.m_capacityAndFlags = 0x80000000;
      if ( v19 > 0 )
      {
        v21 = v15;
        v22 = (unsigned int)v19;
        v52 = v15;
        v53 = (unsigned int)v19;
        do
        {
          v23 = v17->m_magic.m_data;
          v24 = *v21 & 0x3FFFFF;
          v25 = v23[v24];
          if ( (int)v25 >= 0 )
          {
            v26 = v25;
            v27 = v23[v24];
            v28 = v27;
            if ( v23[v25] == v24 )
            {
              do
              {
                if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 4);
                ++v28;
                array.m_data[array.m_size++] = v27;
                v17->m_magic.m_data[v26] = -1;
                v26 = v28;
                ++v27;
              }
              while ( v17->m_magic.m_data[v28] == v24 );
              v21 = v52;
              v22 = v53;
            }
            m_instancePtr = v50;
          }
          if ( (_DWORD)v25 != -1 )
          {
            if ( m_instancePtr->m_faceFlags.m_size )
            {
              v29 = &m_storage;
              m_storage = m_instancePtr->m_faceFlags.m_data[v24].m_storage;
            }
            else
            {
              v44 = 0;
              v29 = &v44;
            }
            m_instancePtr->m_faceFlags.m_data[v24].m_storage = *v29 & 0xFC;
            v17->m_magic.m_data[v24] = -1;
          }
          ++v21;
          v53 = --v22;
          v52 = v21;
        }
        while ( v22 );
        v20 = v49;
        v15 = v54;
        v5 = v47;
        v10 = v51;
      }
      hkaiNavMeshUtils::removeOwnedFaces(m_instancePtr, this->m_streamingCollection.m_pntr, &array, mode);
      hkaiNavMeshUtils::compactOwnedVertices(m_instancePtr);
      array.m_size = 0;
      if ( array.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          array.m_data,
          4 * array.m_capacityAndFlags);
      array.m_data = 0i64;
      array.m_capacityAndFlags = 0x80000000;
      if ( v20 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v15, 4 * v20);
      v8 = result;
      v7 = v57;
      v4 = v48;
      v9 = this;
      ++v5;
      v10 += 4i64;
      v47 = v5;
      v51 = v10;
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
      v32 = &this->m_meshInfos.m_data[v8->m_data[v31]];
      m_originalNumFaces = v32->m_originalNumFaces;
      p_m_magic = &v32->m_magic;
      v35 = 0i64;
      if ( (int)m_originalNumFaces > 0 )
      {
        do
        {
          if ( p_m_magic->m_data[v35] != -1 )
            p_m_magic->m_data[v35] = -2;
          ++v35;
        }
        while ( v35 < m_originalNumFaces );
      }
      v36 = m_originalNumFaces;
      if ( (int)m_originalNumFaces < p_m_magic->m_size )
      {
        v37 = m_originalNumFaces;
        v38 = m_originalNumFaces;
        do
        {
          v39 = p_m_magic->m_data[v38];
          if ( v39 != -1 )
          {
            p_m_magic->m_data[v37] = v39;
            v40 = &p_m_magic->m_data[p_m_magic->m_data[v37]];
            if ( *v40 == -2 || *v40 > v36 )
              *v40 = v36;
            ++v36;
            ++v37;
          }
          LODWORD(m_originalNumFaces) = m_originalNumFaces + 1;
          ++v38;
        }
        while ( (int)m_originalNumFaces < p_m_magic->m_size );
      }
      v41 = p_m_magic->m_capacityAndFlags & 0x3FFFFFFF;
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
        hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, p_m_magic, v43, 4);
      }
      ++v30;
      p_m_magic->m_size = v36;
      ++v31;
    }
    while ( v30 < v8->m_size );
  }
}


// File Line: 46
// RVA: 0xBED730
void __fastcall hkaiNavMeshCutter::hkaiNavMeshCutter(hkaiNavMeshCutter *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshCutter::`vftable;
  this->m_meshInfos.m_data = 0i64;
  this->m_meshInfos.m_size = 0;
  this->m_meshInfos.m_capacityAndFlags = 0x80000000;
  hkaiNavMeshCutter::SavedConnectivity::SavedConnectivity(&this->m_connectivityInfo);
  this->m_streamingCollection.m_pntr = 0i64;
  this->m_forceRecutFaceKeys.m_data = 0i64;
  this->m_forceRecutFaceKeys.m_size = 0;
  this->m_forceRecutFaceKeys.m_capacityAndFlags = 0x80000000;
  this->m_forceClearanceCalcFaceKeys.m_data = 0i64;
  this->m_forceClearanceCalcFaceKeys.m_size = 0;
  this->m_forceClearanceCalcFaceKeys.m_capacityAndFlags = 0x80000000;
  hkaiNavMeshEdgeMatchingParameters::hkaiNavMeshEdgeMatchingParameters(&this->m_edgeMatchParams);
  this->m_cutEdgeTolerance = 0.000099999997;
  this->m_minEdgeMatchingLength = 0.0099999998;
  *(_WORD *)&this->m_useNewCutter.m_bool = 1;
  this->m_edgeMatchParams.m_maxOverhang = 3.40282e38;
  this->m_edgeMatchParams.m_cosPlanarAlignmentAngle = 0.99026805;
  this->m_edgeMatchParams.m_behindFaceTolerance = -3.40282e38;
  this->m_up = (hkVector4f)stru_141A71280.m_quad;
  *(_WORD *)&this->m_performValidationChecks.m_bool = 1;
}

// File Line: 64
// RVA: 0xBEF2C0
void __fastcall hkaiNavMeshCutter::hkaiNavMeshCutter(hkaiNavMeshCutter *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshCutter::`vftable;
}

// File Line: 72
// RVA: 0xBED1D0
void __fastcall hkaiNavMeshCutter::SavedConnectivity::SavedConnectivity(hkaiNavMeshCutter::SavedConnectivity *this)
{
  this->m_storage.m_elem.m_capacityAndFlags = 0x80000000;
  this->m_storage.m_elem.m_data = 0i64;
  this->m_storage.m_elem.m_size = 0;
  this->m_storage.m_numElems = 0;
}

// File Line: 76
// RVA: 0xBED1F0
void __fastcall hkaiNavMeshCutter::SavedConnectivity::~SavedConnectivity(hkaiNavMeshCutter::SavedConnectivity *this)
{
  int m_capacityAndFlags; // r8d

  m_capacityAndFlags = this->m_storage.m_elem.m_capacityAndFlags;
  this->m_storage.m_elem.m_size = 0;
  if ( m_capacityAndFlags < 0 )
  {
    this->m_storage.m_elem.m_data = 0i64;
    this->m_storage.m_elem.m_capacityAndFlags = 0x80000000;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_storage.m_elem.m_data,
      4 * m_capacityAndFlags);
    this->m_storage.m_elem.m_data = 0i64;
    this->m_storage.m_elem.m_capacityAndFlags = 0x80000000;
  }
}

// File Line: 81
// RVA: 0xBED260
void __fastcall hkaiNavMeshCutter::SavedConnectivity::addConnectivity(
        hkaiNavMeshCutter::SavedConnectivity *this,
        unsigned int edgeKey)
{
  int v3; // r8d
  int v4; // ecx
  unsigned int *m_data; // r8
  int v7; // r9d
  int v8; // r10d
  signed int v9; // eax
  unsigned int v10; // edx
  hkResult result; // [rsp+38h] [rbp+10h] BYREF

  v3 = this->m_storage.m_numElems & 0x7FFFFFFF;
  v4 = this->m_storage.m_elem.m_size - 1;
  if ( 2 * v3 > v4 )
    hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
      &this->m_storage,
      &result,
      2 * v4 + 2);
  m_data = this->m_storage.m_elem.m_data;
  v7 = this->m_storage.m_elem.m_size - 1;
  v8 = 1;
  v9 = v7 & (-1640531535 * (edgeKey >> 4));
  v10 = this->m_storage.m_elem.m_data[v9];
  if ( v10 != -1 )
  {
    while ( v10 != edgeKey )
    {
      v9 = v7 & (v9 + 1);
      v10 = m_data[v9];
      if ( v10 == -1 )
        goto LABEL_8;
    }
    v8 = 0;
  }
LABEL_8:
  this->m_storage.m_numElems += v8;
  m_data[v9] = edgeKey;
}

// File Line: 87
// RVA: 0xBED300
void __fastcall hkaiNavMeshCutter::SavedConnectivity::popConnectivityForFace(
        hkaiNavMeshCutter::SavedConnectivity *this,
        hkaiStreamingCollection *collection,
        unsigned int faceKey)
{
  __int64 v5; // rsi
  hkaiNavMeshInstance *m_instancePtr; // rcx
  hkaiNavMesh::Face *v7; // rdi
  int m_startEdgeIndex; // ebx
  int v9; // esi

  v5 = faceKey >> 22;
  m_instancePtr = collection->m_instances.m_data[v5].m_instancePtr;
  v7 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
         m_instancePtr->m_originalFaces,
         m_instancePtr->m_numOriginalFaces,
         &m_instancePtr->m_instancedFaces,
         &m_instancePtr->m_ownedFaces,
         &m_instancePtr->m_faceMap,
         faceKey & 0x3FFFFF);
  m_startEdgeIndex = v7->m_startEdgeIndex;
  if ( v7->m_startEdgeIndex < v7->m_startEdgeIndex + v7->m_numEdges )
  {
    v9 = (_DWORD)v5 << 22;
    do
      hkaiNavMeshCutter::SavedConnectivity::popConnectivityForEdgeAndFace(this, collection, m_startEdgeIndex++ | v9);
    while ( m_startEdgeIndex < v7->m_startEdgeIndex + v7->m_numEdges );
  }
}

// File Line: 97
// RVA: 0xBED3C0
__int64 __fastcall hkaiNavMeshCutter::SavedConnectivity::popConnectivityForEdgeAndFace(
        hkaiNavMeshCutter::SavedConnectivity *this,
        hkaiStreamingCollection *collection,
        unsigned int edgeKey)
{
  int v5; // r10d
  unsigned int *m_data; // rdx
  unsigned int v7; // r9d
  unsigned int v8; // ecx
  Dummy *v9; // rbx

  v5 = this->m_storage.m_elem.m_size - 1;
  if ( v5 <= 0
    || (m_data = this->m_storage.m_elem.m_data,
        v7 = v5 & (-1640531535 * (edgeKey >> 4)),
        v8 = this->m_storage.m_elem.m_data[v7],
        v8 == -1) )
  {
LABEL_5:
    v9 = (Dummy *)(v5 + 1);
  }
  else
  {
    while ( v8 != edgeKey )
    {
      v7 = v5 & (v7 + 1);
      v8 = m_data[v7];
      if ( v8 == -1 )
        goto LABEL_5;
    }
    v9 = (Dummy *)v7;
  }
  if ( (int)v9 > v5 )
    return 0i64;
  hkaiNavMeshCutter::SavedConnectivity::restore(this, collection, edgeKey);
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::remove(&this->m_storage, v9);
  return 1i64;
}

// File Line: 112
// RVA: 0xBED460
void __fastcall hkaiNavMeshCutter::SavedConnectivity::popConnectivityForOppositeFace(
        hkaiNavMeshCutter::SavedConnectivity *this,
        hkaiStreamingCollection *collection,
        unsigned int faceKey)
{
  hkaiNavMeshInstance *m_instancePtr; // rdi
  hkaiNavMesh::Face *v6; // rsi
  __int64 m_startEdgeIndex; // rbp
  __int64 v8; // rbx
  hkaiNavMesh::Edge *m_originalEdges; // rax
  unsigned int m_oppositeEdge; // ecx
  unsigned int v11; // eax
  int v12; // r8d

  m_instancePtr = collection->m_instances.m_data[faceKey >> 22].m_instancePtr;
  v6 = &m_instancePtr->m_originalFaces[faceKey & 0x3FFFFF];
  m_startEdgeIndex = v6->m_startEdgeIndex;
  if ( (int)m_startEdgeIndex < (int)m_startEdgeIndex + v6->m_numEdges )
  {
    v8 = m_startEdgeIndex;
    do
    {
      m_originalEdges = m_instancePtr->m_originalEdges;
      m_oppositeEdge = m_originalEdges[v8].m_oppositeEdge;
      if ( (m_originalEdges[v8].m_flags.m_storage & 0x40) != 0 )
        v11 = m_oppositeEdge & 0xFFC00000;
      else
        v11 = m_instancePtr->m_runtimeId << 22;
      v12 = v11 | m_oppositeEdge & 0x3FFFFF;
      if ( m_oppositeEdge == -1 )
        v12 = -1;
      hkaiNavMeshCutter::SavedConnectivity::popConnectivityForEdgeAndFace(this, collection, v12);
      LODWORD(m_startEdgeIndex) = m_startEdgeIndex + 1;
      ++v8;
    }
    while ( (int)m_startEdgeIndex < v6->m_startEdgeIndex + v6->m_numEdges );
  }
}

// File Line: 123
// RVA: 0xBED550
void __fastcall hkaiNavMeshCutter::SavedConnectivity::restore(
        hkaiNavMeshCutter::SavedConnectivity *this,
        hkaiStreamingCollection *collection,
        unsigned int edgeKey)
{
  signed int v4; // r8d
  hkaiNavMeshInstance *m_instancePtr; // rdx
  __int64 v6; // r9
  int m_numOriginalEdges; // eax
  __int64 v8; // rcx
  hkaiNavMesh::Edge *m_data; // rax
  hkaiNavMesh::Edge *v10; // rdx

  v4 = edgeKey & 0x3FFFFF;
  m_instancePtr = collection->m_instances.m_data[edgeKey >> 22].m_instancePtr;
  v6 = (__int64)&m_instancePtr->m_originalEdges[v4];
  m_numOriginalEdges = m_instancePtr->m_numOriginalEdges;
  if ( v4 >= m_numOriginalEdges )
  {
    v8 = v4 - m_numOriginalEdges;
    m_data = m_instancePtr->m_ownedEdges.m_data;
LABEL_8:
    v10 = &m_data[v8];
    goto LABEL_9;
  }
  if ( m_instancePtr->m_edgeMap.m_size )
    v4 = m_instancePtr->m_edgeMap.m_data[v4];
  if ( v4 != -1 )
  {
    v8 = v4;
    m_data = m_instancePtr->m_instancedEdges.m_data;
    goto LABEL_8;
  }
  v10 = 0i64;
LABEL_9:
  v10->m_oppositeEdge = *(_DWORD *)(v6 + 8);
  v10->m_oppositeFace = *(_DWORD *)(v6 + 12);
  v10->m_flags.m_storage = *(_BYTE *)(v6 + 16);
}

// File Line: 136
// RVA: 0xBED5F0
void __fastcall hkaiNavMeshCutter::SavedConnectivity::append(
        hkaiNavMeshCutter::SavedConnectivity *this,
        hkaiNavMeshCutter::SavedConnectivity *other)
{
  int v2; // r9d
  __int64 v3; // r8
  int v4; // r11d
  unsigned int *m_data; // rax
  int v8; // edi
  int m_size; // r8d
  unsigned int v10; // ebx
  unsigned int *v11; // r9
  int v12; // r8d
  int v13; // r10d
  int v14; // eax
  unsigned int v15; // edx
  int v16; // r8d
  __int64 v17; // rcx
  int v18; // r10d
  unsigned int *v19; // rdx
  hkResult result; // [rsp+38h] [rbp+10h] BYREF

  v2 = 0;
  v3 = 0i64;
  v4 = other->m_storage.m_elem.m_size - 1;
  if ( v4 >= 0 )
  {
    m_data = other->m_storage.m_elem.m_data;
    do
    {
      if ( *m_data != -1 )
        break;
      ++v3;
      ++v2;
      ++m_data;
    }
    while ( v3 <= v4 );
  }
  v8 = v2;
  if ( v2 <= v4 )
  {
    do
    {
      m_size = this->m_storage.m_elem.m_size;
      v10 = other->m_storage.m_elem.m_data[v8];
      if ( 2 * this->m_storage.m_numElems > m_size - 1 )
        hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
          &this->m_storage,
          &result,
          2 * m_size);
      v11 = this->m_storage.m_elem.m_data;
      v12 = this->m_storage.m_elem.m_size - 1;
      v13 = 1;
      v14 = v12 & (-1640531535 * (v10 >> 4));
      v15 = this->m_storage.m_elem.m_data[v14];
      if ( v15 != -1 )
      {
        while ( v15 != v10 )
        {
          v14 = v12 & (v14 + 1);
          v15 = v11[v14];
          if ( v15 == -1 )
            goto LABEL_13;
        }
        v13 = 0;
      }
LABEL_13:
      this->m_storage.m_numElems += v13;
      v16 = v8 + 1;
      v11[v14] = v10;
      v17 = v8 + 1;
      v18 = other->m_storage.m_elem.m_size - 1;
      if ( v17 <= v18 )
      {
        v19 = &other->m_storage.m_elem.m_data[v16];
        do
        {
          if ( *v19 != -1 )
            break;
          ++v17;
          ++v16;
          ++v19;
        }
        while ( v17 <= v18 );
      }
      v8 = v16;
    }
    while ( v16 <= v18 );
  }
}

// File Line: 148
// RVA: 0xBF2330
__int64 __fastcall hkaiNavMeshCutter::MeshInfo::isValid(
        hkaiNavMeshCutter::MeshInfo *this,
        hkaiNavMeshInstance *meshInstance,
        hkaiNavMeshCutter::SavedConnectivity *connectivityInfo)
{
  __int64 m_originalNumFaces; // rsi
  hkaiNavMeshCutter::MeshInfo *v5; // r13
  unsigned int v6; // r14d
  int v7; // r8d
  __int64 v8; // rbx
  __int64 m_size; // rdi
  int *m_data; // r11
  __int64 v11; // r9
  int v12; // edx
  __int64 v13; // rax
  int *v14; // rcx
  bool v15; // zf
  __int64 v16; // rdx
  __int64 v17; // rax
  int *v18; // rcx
  int v19; // edx
  __int64 v20; // rax
  int *v21; // rcx
  int *v22; // rcx
  int m_numOriginalFaces; // r11d
  int v24; // r8d
  int v25; // eax
  __int64 v26; // rdx
  __int64 v27; // r9
  int v28; // r10d
  int *v29; // rax
  __int16 v30; // cx
  int index; // ebp
  int *v32; // rsi
  int *v33; // rbx
  __int64 v34; // rdi
  hkaiNavMesh::Face *v35; // rax
  hkaiNavMesh::Face *m_originalFaces; // rcx
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_instancedFaces; // r8
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_ownedFaces; // r9
  int v39; // r13d
  hkaiNavMesh::Face *v40; // r12
  int *v41; // rsi
  hkaiNavMesh::Face *v42; // rax
  __int16 m_numUserEdges; // bx
  hkaiNavMesh::Face *v44; // r9
  int m_startEdgeIndex; // eax
  __int64 m_numOriginalEdges; // r11
  int m_startUserEdgeIndex; // r10d
  unsigned __int16 v48; // r8
  int *v50; // [rsp+30h] [rbp-48h]
  int *v51; // [rsp+38h] [rbp-40h]
  int v53; // [rsp+88h] [rbp+10h] BYREF
  int v54; // [rsp+98h] [rbp+20h] BYREF

  m_originalNumFaces = this->m_originalNumFaces;
  v5 = this;
  v6 = 1;
  v7 = 0;
  v8 = 0i64;
  if ( (int)m_originalNumFaces > 0 )
  {
    m_size = this->m_magic.m_size;
    m_data = this->m_magic.m_data;
    do
    {
      v11 = m_data[v8];
      v12 = m_originalNumFaces;
      v13 = m_originalNumFaces;
      if ( (_DWORD)v11 == -1 )
      {
        if ( m_originalNumFaces < m_size )
        {
          v22 = &m_data[m_originalNumFaces];
          while ( *v22 != v7 )
          {
            ++v13;
            ++v12;
            ++v22;
            if ( v13 >= m_size )
              goto LABEL_30;
          }
          if ( v12 != -1 )
            v6 = 0;
        }
      }
      else if ( m_originalNumFaces < m_size )
      {
        v14 = &m_data[m_originalNumFaces];
        while ( *v14 != v7 )
        {
          ++v13;
          ++v12;
          ++v14;
          if ( v13 >= m_size )
            goto LABEL_30;
        }
        if ( v12 != -1 )
        {
          v15 = (_DWORD)v11 == v12;
          v16 = v5->m_magic.m_size;
          v17 = m_data[v8];
          if ( !v15 )
            v6 = 0;
          if ( v11 < v16 )
          {
            v18 = &m_data[v11];
            do
            {
              if ( *v18 != v7 )
                break;
              ++v17;
              LODWORD(v11) = v11 + 1;
              ++v18;
            }
            while ( v17 < v16 );
          }
          v19 = m_size - 1;
          v20 = (int)m_size - 1;
          if ( (int)m_size - 1 < 0 )
          {
LABEL_20:
            v19 = -1;
          }
          else
          {
            v21 = &m_data[v19];
            while ( *v21 != v7 )
            {
              --v19;
              --v21;
              if ( --v20 < 0 )
                goto LABEL_20;
            }
          }
          if ( (_DWORD)v11 != v19 + 1 )
            v6 = 0;
        }
      }
LABEL_30:
      ++v8;
      ++v7;
    }
    while ( v8 < m_originalNumFaces );
  }
  m_numOriginalFaces = meshInstance->m_numOriginalFaces;
  v24 = 0;
  v25 = m_numOriginalFaces + meshInstance->m_ownedFaces.m_size;
  v26 = 0i64;
  v27 = v25;
  if ( v25 > 0 )
  {
    v28 = meshInstance->m_faceFlags.m_size;
    do
    {
      if ( v28 )
      {
        v29 = &v53;
        LOBYTE(v53) = meshInstance->m_faceFlags.m_data[v26].m_storage;
      }
      else
      {
        LOBYTE(v54) = 0;
        v29 = &v54;
      }
      v30 = *(_BYTE *)v29 & 0xFB;
      if ( v24 >= (int)m_originalNumFaces )
      {
        if ( v30 != 2 )
          v6 = 0;
      }
      else if ( v5->m_magic.m_data[v26] == -1 )
      {
        if ( (*(_BYTE *)v29 & 0xFB) != 0 )
          v6 = 0;
      }
      else if ( v30 != 1 )
      {
        v6 = 0;
      }
      ++v26;
      ++v24;
    }
    while ( v26 < v27 );
  }
  index = 0;
  v53 = 0;
  if ( m_numOriginalFaces > 0 )
  {
    v32 = v5->m_magic.m_data;
    v33 = v32;
    v51 = v32;
    v50 = v32;
    do
    {
      v34 = *v33;
      if ( (int)v34 >= 0 )
      {
        v35 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
                meshInstance->m_originalFaces,
                m_numOriginalFaces,
                &meshInstance->m_instancedFaces,
                &meshInstance->m_ownedFaces,
                &meshInstance->m_faceMap,
                index);
        v39 = v5->m_magic.m_size;
        v40 = v35;
        v54 = v39;
        if ( (int)v34 < v39 )
        {
          v41 = &v32[v34];
          while ( *v41 == index )
          {
            v42 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
                    m_originalFaces,
                    m_numOriginalFaces,
                    p_m_instancedFaces,
                    p_m_ownedFaces,
                    &meshInstance->m_faceMap,
                    v34);
            m_numUserEdges = v42->m_numUserEdges;
            v44 = v42;
            if ( m_numUserEdges <= 0 )
              m_startEdgeIndex = v42->m_startEdgeIndex;
            else
              m_startEdgeIndex = v42->m_startUserEdgeIndex;
            if ( m_startEdgeIndex != -1 )
            {
              m_numOriginalEdges = meshInstance->m_numOriginalEdges;
              m_startUserEdgeIndex = v44->m_startUserEdgeIndex;
              while ( 1 )
              {
                if ( m_startEdgeIndex >= (int)m_numOriginalEdges )
                {
                  v48 = meshInstance->m_cuttingInfo.m_data[m_startEdgeIndex - m_numOriginalEdges];
                  if ( v48 != 0xFFFF && v48 >= v40->m_numEdges )
                    v6 = 0;
                }
                if ( m_startEdgeIndex >= m_startUserEdgeIndex
                  && m_startEdgeIndex < m_numUserEdges + m_startUserEdgeIndex - 1 )
                {
                  goto LABEL_66;
                }
                if ( m_startEdgeIndex != m_numUserEdges + m_startUserEdgeIndex - 1 )
                  break;
                m_startEdgeIndex = v44->m_startEdgeIndex;
LABEL_67:
                if ( m_startEdgeIndex == -1 )
                  goto LABEL_68;
              }
              if ( m_startEdgeIndex < v44->m_startEdgeIndex
                || m_startEdgeIndex >= v44->m_numEdges + v44->m_startEdgeIndex - 1 )
              {
LABEL_68:
                index = v53;
                v39 = v54;
                m_numOriginalFaces = meshInstance->m_numOriginalFaces;
                m_originalFaces = meshInstance->m_originalFaces;
                p_m_instancedFaces = &meshInstance->m_instancedFaces;
                goto LABEL_69;
              }
LABEL_66:
              ++m_startEdgeIndex;
              goto LABEL_67;
            }
LABEL_69:
            LODWORD(v34) = v34 + 1;
            ++v41;
            p_m_ownedFaces = &meshInstance->m_ownedFaces;
            if ( (int)v34 >= v39 )
              break;
          }
          v33 = v50;
          v32 = v51;
        }
        v5 = this;
      }
      ++index;
      ++v33;
      v53 = index;
      v50 = v33;
    }
    while ( index < m_numOriginalFaces );
  }
  return v6;
}

// File Line: 226
// RVA: 0xBF0920
__int64 __fastcall hkaiNavMeshCutter::isValid(hkaiNavMeshCutter *this)
{
  _QWORD *Value; // r8
  _QWORD *v3; // rcx
  unsigned __int64 v4; // rax
  _QWORD *v5; // rcx
  hkaiStreamingCollection *m_pntr; // rbx
  unsigned int v7; // ebp
  __int64 m_size; // rsi
  int v9; // edi
  hkaiNavMeshInstance **p_m_instancePtr; // rbx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v3 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v3 < Value[3] )
  {
    *v3 = "TtisValid";
    v4 = __rdtsc();
    v5 = v3 + 2;
    *((_DWORD *)v5 - 2) = v4;
    Value[1] = v5;
  }
  m_pntr = this->m_streamingCollection.m_pntr;
  v7 = 1;
  m_size = m_pntr->m_instances.m_size;
  v9 = 0;
  if ( m_size > 0 )
  {
    p_m_instancePtr = &m_pntr->m_instances.m_data->m_instancePtr;
    do
    {
      if ( *p_m_instancePtr
        && !hkaiNavMeshCutter::MeshInfo::isValid(
              &this->m_meshInfos.m_data[v9],
              *p_m_instancePtr,
              &this->m_connectivityInfo) )
      {
        v7 = 0;
      }
      ++v9;
      p_m_instancePtr += 6;
      --m_size;
    }
    while ( m_size );
  }
  v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)v11[1];
  if ( (unsigned __int64)v12 < v11[3] )
  {
    *v12 = "Et";
    v13 = __rdtsc();
    v14 = v12 + 2;
    *((_DWORD *)v14 - 2) = v13;
    v11[1] = v14;
  }
  return v7;
}

// File Line: 248
// RVA: 0xBF2240
void __fastcall hkaiNavMeshCutter::MeshInfo::init(hkaiNavMeshCutter::MeshInfo *this, hkaiNavMeshInstance *meshInstance)
{
  hkArray<int,hkContainerHeapAllocator> *p_m_magic; // rbx
  int m_numOriginalFaces; // esi
  int v5; // eax
  int v6; // eax
  int v7; // r9d
  int v8; // edx
  int *v9; // rdi
  __int64 v10; // rcx
  int m_capacityAndFlags; // r8d
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  if ( meshInstance )
  {
    p_m_magic = &this->m_magic;
    this->m_originalNumFaces = meshInstance->m_numOriginalFaces;
    this->m_originalNumEdges = meshInstance->m_numOriginalEdges;
    this->m_originalNumVertices = meshInstance->m_numOriginalVertices;
    m_numOriginalFaces = meshInstance->m_numOriginalFaces;
    v5 = this->m_magic.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v5 < m_numOriginalFaces )
    {
      v6 = 2 * v5;
      v7 = meshInstance->m_numOriginalFaces;
      if ( m_numOriginalFaces < v6 )
        v7 = v6;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_magic, v7, 4);
    }
    v8 = m_numOriginalFaces - p_m_magic->m_size;
    v9 = &p_m_magic->m_data[p_m_magic->m_size];
    v10 = v8;
    if ( v8 > 0 )
    {
      while ( v10 )
      {
        *v9++ = -1;
        --v10;
      }
    }
    p_m_magic->m_size = m_numOriginalFaces;
  }
  else
  {
    *(_QWORD *)&this->m_originalNumFaces = 0i64;
    this->m_originalNumVertices = 0;
    m_capacityAndFlags = this->m_magic.m_capacityAndFlags;
    this->m_magic.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_magic.m_data,
        4 * m_capacityAndFlags);
    this->m_magic.m_data = 0i64;
    this->m_magic.m_capacityAndFlags = 0x80000000;
  }
}

// File Line: 266
// RVA: 0xBED7F0
void __fastcall hkaiNavMeshCutter::init(hkaiNavMeshCutter *this, hkVector4f *up, hkaiStreamingCollection *collection)
{
  hkaiStreamingCollection *m_pntr; // rcx
  int v6; // ebx
  int m_size; // r12d
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  __int64 v11; // r15
  int v12; // eax
  __int64 v13; // rsi
  int *p_m_capacityAndFlags; // rdi
  int v15; // r8d
  int v16; // eax
  __int64 v17; // rdx
  int *v18; // rcx
  __int64 v19; // rdi
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  this->m_up = (hkVector4f)up->m_quad;
  if ( collection )
    hkReferencedObject::addReference(collection);
  m_pntr = this->m_streamingCollection.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  v6 = 0;
  this->m_streamingCollection.m_pntr = collection;
  if ( collection )
    m_size = collection->m_instances.m_size;
  else
    m_size = 0;
  v8 = this->m_meshInfos.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < m_size )
  {
    v9 = 2 * v8;
    v10 = m_size;
    if ( m_size < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_meshInfos, v10, 32);
  }
  v11 = m_size;
  v12 = this->m_meshInfos.m_size - m_size - 1;
  v13 = v12;
  if ( v12 >= 0 )
  {
    p_m_capacityAndFlags = &this->m_meshInfos.m_data[m_size + v12].m_magic.m_capacityAndFlags;
    do
    {
      v15 = *p_m_capacityAndFlags;
      *(p_m_capacityAndFlags - 1) = 0;
      if ( v15 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(p_m_capacityAndFlags - 3),
          4 * v15);
      *(_QWORD *)(p_m_capacityAndFlags - 3) = 0i64;
      *p_m_capacityAndFlags = 0x80000000;
      p_m_capacityAndFlags -= 8;
      --v13;
    }
    while ( v13 >= 0 );
  }
  v16 = this->m_meshInfos.m_size;
  v17 = m_size - v16;
  if ( m_size - v16 > 0 )
  {
    v18 = &this->m_meshInfos.m_data[this->m_meshInfos.m_size].m_magic.m_capacityAndFlags;
    do
    {
      if ( v18 != (int *)28 )
      {
        *(_QWORD *)(v18 - 3) = 0i64;
        *(v18 - 1) = 0;
        *v18 = 0x80000000;
      }
      v18 += 8;
      --v17;
    }
    while ( v17 );
  }
  this->m_meshInfos.m_size = m_size;
  if ( m_size > 0i64 )
  {
    v19 = 0i64;
    do
    {
      hkaiNavMeshCutter::MeshInfo::init(
        &this->m_meshInfos.m_data[v6++],
        collection->m_instances.m_data[v19++].m_instancePtr);
      --v11;
    }
    while ( v11 );
  }
}

// File Line: 281
// RVA: 0xBF2160
void __fastcall hkaiNavMeshCutter::setFaceAsStreaming(hkaiNavMeshCutter *this, unsigned int forceCutKey)
{
  signed int v3; // r11d
  hkaiNavMeshInstance *m_instancePtr; // r10
  char m_storage; // [rsp+38h] [rbp+10h]
  char v7; // [rsp+38h] [rbp+10h]

  v3 = forceCutKey & 0x3FFFFF;
  m_instancePtr = this->m_streamingCollection.m_pntr->m_instances.m_data[forceCutKey >> 22].m_instancePtr;
  if ( m_instancePtr->m_faceFlags.m_size )
    m_storage = m_instancePtr->m_faceFlags.m_data[v3].m_storage;
  else
    m_storage = 0;
  m_instancePtr->m_faceFlags.m_data[v3].m_storage = m_storage | 4;
  if ( m_instancePtr->m_faceFlags.m_size )
    v7 = m_instancePtr->m_faceFlags.m_data[v3].m_storage;
  else
    v7 = 0;
  if ( (v7 & 1) == 0 )
  {
    if ( this->m_forceRecutFaceKeys.m_size == (this->m_forceRecutFaceKeys.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_forceRecutFaceKeys, 4);
    this->m_forceRecutFaceKeys.m_data[this->m_forceRecutFaceKeys.m_size++] = forceCutKey;
  }
}

// File Line: 299
// RVA: 0xBED990
void __fastcall hkaiNavMeshCutter::initSection(
        hkaiNavMeshCutter *this,
        int sectionIdx,
        hkaiNavMeshInstance *meshInstance,
        bool doChecks)
{
  __int64 v4; // r15
  __int64 v5; // rdi
  int v6; // esi
  hkaiNavMeshInstance *v7; // r12
  hkaiNavMeshCutter *v8; // r13
  int v9; // eax
  int v10; // eax
  int v11; // r9d
  int v12; // eax
  __int64 v13; // rdi
  int *v14; // rbx
  int v15; // r8d
  int v16; // eax
  __int64 v17; // rdx
  int *p_m_capacityAndFlags; // rcx
  hkaiNavMesh *m_pntr; // r15
  int v20; // ebx
  bool v21; // cc
  int *v22; // r10
  unsigned int *v23; // r9
  __int64 v24; // r14
  hkaiStreamingSet *m_data; // rcx
  int SectionIdByUid; // eax
  int v27; // esi
  hkaiStreamingSet *v28; // rdx
  __int64 v29; // r12
  hkaiStreamingSet::NavMeshConnection *v30; // rcx
  int m_numElems; // r10d
  int m_size; // edx
  int m_faceIndex; // ebx
  int v34; // r9d
  int v35; // ecx
  int v36; // r11d
  int v37; // edx
  hkaiNavMeshInstance *m_instancePtr; // rdx
  __int64 m_oppositeFaceIndex; // r8
  hkaiNavMeshCutter **p_result; // rax
  int v41; // r10d
  int v42; // edx
  unsigned int v43; // ebx
  int v44; // r9d
  int v45; // r11d
  int v46; // eax
  unsigned int v47; // edx
  int v48; // r8d
  int v49; // edx
  __int64 i; // rcx
  int v51; // ebx
  int v52; // r8d
  int v53; // edx
  __int64 v54; // rcx
  int v55; // edx
  int v56; // r8d
  __int64 j; // rcx
  int v58; // ebx
  int v59; // r8d
  int v60; // edx
  __int64 v61; // rcx
  char v62; // [rsp+28h] [rbp-19h] BYREF
  int v63; // [rsp+2Ch] [rbp-15h]
  hkResult v64; // [rsp+30h] [rbp-11h] BYREF
  hkResult v65; // [rsp+34h] [rbp-Dh] BYREF
  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > v66; // [rsp+38h] [rbp-9h] BYREF
  hkSet<int,hkContainerTempAllocator,hkMapOperations<int> > v67; // [rsp+50h] [rbp+Fh] BYREF
  hkaiNavMeshCutter *retaddr; // [rsp+A8h] [rbp+67h]
  hkaiNavMeshCutter *result; // [rsp+B0h] [rbp+6Fh] BYREF
  hkaiNavMeshInstance *v70; // [rsp+B8h] [rbp+77h]
  hkaiNavMeshInstance *v71; // [rsp+C0h] [rbp+7Fh]

  v71 = meshInstance;
  result = this;
  v4 = sectionIdx;
  v5 = 0i64;
  v6 = sectionIdx + 1;
  v7 = meshInstance;
  v8 = this;
  if ( this->m_meshInfos.m_size < sectionIdx + 1 )
  {
    v9 = this->m_meshInfos.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 < v6 )
    {
      v10 = 2 * v9;
      v11 = sectionIdx + 1;
      if ( v6 < v10 )
        v11 = v10;
      hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, &this->m_meshInfos, v11, 32);
    }
    v12 = v8->m_meshInfos.m_size - v6 - 1;
    v13 = v12;
    if ( v12 >= 0 )
    {
      v14 = &v8->m_meshInfos.m_data[v6].m_magic.m_capacityAndFlags + 8 * v12;
      do
      {
        v15 = *v14;
        *(v14 - 1) = 0;
        if ( v15 >= 0 )
          ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _QWORD, _QWORD, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
            &hkContainerHeapAllocator::s_alloc,
            *(_QWORD *)(v14 - 3),
            (unsigned int)(4 * v15),
            0i64);
        *(_QWORD *)(v14 - 3) = 0i64;
        *v14 = 0x80000000;
        v14 -= 8;
        --v13;
      }
      while ( v13 >= 0 );
    }
    v16 = v6 - v8->m_meshInfos.m_size;
    v17 = v16;
    if ( v16 > 0 )
    {
      p_m_capacityAndFlags = &v8->m_meshInfos.m_data[v8->m_meshInfos.m_size].m_magic.m_capacityAndFlags;
      do
      {
        if ( p_m_capacityAndFlags != (int *)28 )
        {
          *(_QWORD *)(p_m_capacityAndFlags - 3) = 0i64;
          *(p_m_capacityAndFlags - 1) = 0;
          *p_m_capacityAndFlags = 0x80000000;
        }
        p_m_capacityAndFlags += 8;
        --v17;
      }
      while ( v17 );
    }
    v8->m_meshInfos.m_size = v6;
    v5 = 0i64;
  }
  hkaiNavMeshCutter::MeshInfo::init(&v8->m_meshInfos.m_data[v4], v7);
  m_pntr = v7->m_originalMesh.m_pntr;
  v20 = 0;
  v67.m_elem.m_data = 0i64;
  v67.m_elem.m_size = 0;
  v67.m_elem.m_capacityAndFlags = 0x80000000;
  v67.m_numElems = 0;
  v66.m_elem.m_data = 0i64;
  v66.m_elem.m_size = 0;
  v66.m_elem.m_capacityAndFlags = 0x80000000;
  v66.m_numElems = 0;
  v21 = m_pntr->m_streamingSets.m_size <= 0;
  v22 = 0i64;
  v23 = 0i64;
  v63 = 0;
  if ( !v21 )
  {
    v24 = 0i64;
    do
    {
      m_data = m_pntr->m_streamingSets.m_data;
      if ( m_data[v24].m_thisUid == v7->m_sectionUid )
      {
        SectionIdByUid = hkaiStreamingCollection::findSectionIdByUid(
                           v8->m_streamingCollection.m_pntr,
                           m_data[v24].m_oppositeUid);
        v27 = 0;
        v28 = &m_pntr->m_streamingSets.m_data[v24];
        v29 = SectionIdByUid;
        if ( v28->m_meshConnections.m_size > 0 )
        {
          do
          {
            v30 = v28->m_meshConnections.m_data;
            m_numElems = v67.m_numElems;
            m_size = v67.m_elem.m_size;
            m_faceIndex = v30[v5].m_faceIndex;
            if ( 2 * v67.m_numElems > v67.m_elem.m_size - 1 )
            {
              hkSet<int,hkContainerTempAllocator,hkMapOperations<int>>::resizeTable(&v67, &v64, 2 * v67.m_elem.m_size);
              m_numElems = v67.m_numElems;
              m_size = v67.m_elem.m_size;
            }
            v34 = m_size - 1;
            v35 = (m_size - 1) & (-1640531535 * m_faceIndex);
            v36 = 1;
            v37 = v67.m_elem.m_data[v35];
            if ( v37 != -1 )
            {
              while ( v37 != m_faceIndex )
              {
                v35 = v34 & (v35 + 1);
                v37 = v67.m_elem.m_data[v35];
                if ( v37 == -1 )
                  goto LABEL_28;
              }
              v36 = 0;
            }
LABEL_28:
            v67.m_numElems = v36 + m_numElems;
            v67.m_elem.m_data[v35] = m_faceIndex;
            if ( (_DWORD)v29 != -1 )
            {
              m_instancePtr = retaddr->m_streamingCollection.m_pntr->m_instances.m_data[v29].m_instancePtr;
              m_oppositeFaceIndex = m_pntr->m_streamingSets.m_data[v24].m_meshConnections.m_data[v5].m_oppositeFaceIndex;
              if ( m_instancePtr->m_faceFlags.m_size )
              {
                p_result = &result;
                LOBYTE(result) = m_instancePtr->m_faceFlags.m_data[m_oppositeFaceIndex].m_storage;
              }
              else
              {
                v62 = 0;
                p_result = (hkaiNavMeshCutter **)&v62;
              }
              if ( (*(_BYTE *)p_result & 4) == 0 )
              {
                v41 = v66.m_numElems;
                v42 = v66.m_elem.m_size;
                v43 = m_oppositeFaceIndex | ((_DWORD)v29 << 22);
                if ( 2 * v66.m_numElems > v66.m_elem.m_size - 1 )
                {
                  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int>>::resizeTable(
                    &v66,
                    &v65,
                    2 * v66.m_elem.m_size);
                  v41 = v66.m_numElems;
                  v42 = v66.m_elem.m_size;
                }
                v44 = v42 - 1;
                v45 = 1;
                v46 = (v42 - 1) & (-1640531535 * (v43 >> 4));
                v47 = v66.m_elem.m_data[v46];
                if ( v47 != -1 )
                {
                  while ( v47 != v43 )
                  {
                    v46 = v44 & (v46 + 1);
                    v47 = v66.m_elem.m_data[v46];
                    if ( v47 == -1 )
                      goto LABEL_40;
                  }
                  v45 = 0;
                }
LABEL_40:
                v66.m_numElems = v45 + v41;
                v66.m_elem.m_data[v46] = v43;
              }
            }
            ++v27;
            ++v5;
            v28 = &m_pntr->m_streamingSets.m_data[v24];
          }
          while ( v27 < v28->m_meshConnections.m_size );
          v20 = v63;
          v5 = 0i64;
        }
        v7 = v70;
        v8 = retaddr;
        v23 = v66.m_elem.m_data;
        v22 = v67.m_elem.m_data;
      }
      ++v20;
      ++v24;
      v63 = v20;
    }
    while ( v20 < m_pntr->m_streamingSets.m_size );
  }
  v48 = v67.m_elem.m_size - 1;
  v49 = 0;
  for ( i = 0i64; i <= v48; ++v49 )
  {
    if ( v22[i] != -1 )
      break;
    ++i;
  }
  v51 = v49;
  if ( v49 <= v48 )
  {
    do
    {
      hkaiNavMeshCutter::setFaceAsStreaming(v8, (v7->m_runtimeId << 22) | v22[v51]);
      v22 = v67.m_elem.m_data;
      v52 = v67.m_elem.m_size - 1;
      v53 = v51 + 1;
      v54 = v51 + 1;
      if ( v54 <= v67.m_elem.m_size - 1 )
      {
        do
        {
          if ( v67.m_elem.m_data[v54] != -1 )
            break;
          ++v54;
          ++v53;
        }
        while ( v54 <= v52 );
      }
      v51 = v53;
    }
    while ( v53 <= v52 );
    v23 = v66.m_elem.m_data;
  }
  v55 = 0;
  v56 = v66.m_elem.m_size - 1;
  for ( j = 0i64; j <= v56; ++v55 )
  {
    if ( v23[j] != -1 )
      break;
    ++j;
  }
  v58 = v55;
  if ( v55 <= v56 )
  {
    do
    {
      hkaiNavMeshCutter::setFaceAsStreaming(v8, v23[v58]);
      v23 = v66.m_elem.m_data;
      v59 = v66.m_elem.m_size - 1;
      v60 = v58 + 1;
      v61 = v58 + 1;
      if ( v61 <= v66.m_elem.m_size - 1 )
      {
        do
        {
          if ( v66.m_elem.m_data[v61] != -1 )
            break;
          ++v61;
          ++v60;
        }
        while ( v61 <= v59 );
      }
      v58 = v60;
    }
    while ( v60 <= v59 );
    v22 = v67.m_elem.m_data;
  }
  v66.m_elem.m_size = 0;
  if ( v66.m_elem.m_capacityAndFlags >= 0 )
  {
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v23,
      4 * v66.m_elem.m_capacityAndFlags);
    v22 = v67.m_elem.m_data;
  }
  v66.m_elem.m_data = 0i64;
  v67.m_elem.m_size = 0;
  v66.m_elem.m_capacityAndFlags = 0x80000000;
  if ( v67.m_elem.m_capacityAndFlags >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, int *, _QWORD, unsigned int *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v22,
      (unsigned int)(4 * v67.m_elem.m_capacityAndFlags),
      v23);
}

// File Line: 370
// RVA: 0xBF0A20
void __fastcall hkaiNavMeshCutter::intersectMeshWithSilhouettes(
        hkaiNavMeshCutter *this,
        hkArrayBase<unsigned int> *faceKeys,
        hkaiNavMeshSilhouetteSelector *selector,
        hkaiSilhouetteGenerationParameters *genParams,
        hkArrayBase<hkaiFaceCutResults> *results)
{
  hkaiNavMeshCutter *v5; // r15
  hkArrayBase<unsigned int> *v6; // rbx
  hkaiSilhouetteGenerationParameters *v7; // rsi
  hkaiNavMeshSilhouetteSelector *v8; // r12
  int v9; // r14d
  __int64 v10; // rcx
  unsigned int v11; // edi
  _QWORD *Value; // rax
  _QWORD *v13; // rcx
  _QWORD *v14; // r8
  unsigned __int64 v15; // rax
  _QWORD *v16; // rcx
  _QWORD *v17; // r8
  _QWORD *v18; // rcx
  unsigned __int64 v19; // rax
  _QWORD *v20; // rcx
  hkaiNavMeshInstance *m_instancePtr; // rsi
  int m_numOriginalFaces; // edx
  hkaiNavMesh::Face *m_originalFaces; // rcx
  int m_numEdges; // ebx
  hkVector4f *m_cur; // rax
  int v26; // ebx
  hkLifoAllocator *v27; // rcx
  int v28; // edx
  char *v29; // r8
  int v30; // ebx
  hkLifoAllocator *v31; // rcx
  int *v32; // rax
  int v33; // edx
  char *v34; // r8
  int v35; // ebx
  __int64 v36; // rdi
  __int64 v37; // rsi
  int v38; // r9d
  int m_size; // eax
  char *v40; // rdi
  signed int v41; // ebx
  hkLifoAllocator *v42; // rax
  int v43; // r8d
  int v44; // eax
  char *v45; // rdi
  signed int v46; // ebx
  hkLifoAllocator *v47; // rax
  int v48; // r8d
  __int64 v49; // rdi
  int *v50; // rbx
  int v51; // r8d
  bool v52; // [rsp+40h] [rbp-C0h]
  char *v53; // [rsp+48h] [rbp-B8h] BYREF
  int v54; // [rsp+50h] [rbp-B0h]
  int v55; // [rsp+54h] [rbp-ACh]
  int v56; // [rsp+58h] [rbp-A8h]
  char *v57; // [rsp+60h] [rbp-A0h] BYREF
  int v58; // [rsp+68h] [rbp-98h]
  int v59; // [rsp+6Ch] [rbp-94h]
  hkArrayBase<int> indexRemap; // [rsp+70h] [rbp-90h] BYREF
  void *p; // [rsp+80h] [rbp-80h]
  int v62; // [rsp+88h] [rbp-78h]
  hkArrayBase<hkVector4f> faceVertices; // [rsp+90h] [rbp-70h] BYREF
  void *v64; // [rsp+A0h] [rbp-60h]
  int v65; // [rsp+A8h] [rbp-58h]
  __int64 v66; // [rsp+B0h] [rbp-50h]
  hkaiFaceCutResults *v67; // [rsp+B8h] [rbp-48h]
  hkaiAbstractFaceCutter v68; // [rsp+C0h] [rbp-40h] BYREF
  hkSimdFloat32 regionExpansion; // [rsp+F0h] [rbp-10h] BYREF

  v5 = this;
  v6 = faceKeys;
  v7 = genParams;
  v8 = selector;
  hkaiAbstractFaceCutter::hkaiAbstractFaceCutter(&v68, this->m_useNewCutter.m_bool != 0);
  v9 = 0;
  v56 = 0;
  if ( v6->m_size > 0 )
  {
    v10 = 0i64;
    v66 = 0i64;
    do
    {
      v11 = *(unsigned int *)((char *)v6->m_data + v10);
      v53 = 0i64;
      v54 = 0;
      v55 = 0x80000000;
      v57 = 0i64;
      v58 = 0;
      v59 = 0x80000000;
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v13 = (_QWORD *)Value[1];
      v14 = Value;
      if ( (unsigned __int64)v13 < Value[3] )
      {
        *v13 = "TtgatherSilhouettes";
        v15 = __rdtsc();
        v16 = v13 + 2;
        *((_DWORD *)v16 - 2) = v15;
        v14[1] = v16;
      }
      v8->vfptr->gatherSilhouettesForFace(
        v8,
        v11,
        v7,
        (hkArray<hkArray<hkVector4f,hkContainerTempAllocator>,hkContainerTempAllocator> *)&v53,
        (hkArray<int,hkContainerTempAllocator> *)&v57);
      v17 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v18 = (_QWORD *)v17[1];
      if ( (unsigned __int64)v18 < v17[3] )
      {
        *v18 = "Et";
        v19 = __rdtsc();
        v20 = v18 + 2;
        *((_DWORD *)v20 - 2) = v19;
        v17[1] = v20;
      }
      m_instancePtr = v5->m_streamingCollection.m_pntr->m_instances.m_data[v11 >> 22].m_instancePtr;
      m_numOriginalFaces = m_instancePtr->m_numOriginalFaces;
      m_originalFaces = m_instancePtr->m_originalFaces;
      v67 = &results->m_data[v9];
      v52 = m_instancePtr->m_originalMesh.m_pntr->m_flags.m_storage & 1;
      m_numEdges = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
                     m_originalFaces,
                     m_numOriginalFaces,
                     &m_instancePtr->m_instancedFaces,
                     &m_instancePtr->m_ownedFaces,
                     &m_instancePtr->m_faceMap,
                     v11 & 0x3FFFFF)->m_numEdges;
      m_cur = 0i64;
      faceVertices.m_capacityAndFlags = 0x80000000;
      v26 = m_numEdges + 1;
      faceVertices.m_data = 0i64;
      faceVertices.m_size = 0;
      v65 = v26;
      if ( v26 )
      {
        v27 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        m_cur = (hkVector4f *)v27->m_cur;
        v28 = (16 * v26 + 127) & 0xFFFFFF80;
        v29 = (char *)m_cur + v28;
        if ( v28 > v27->m_slabSize || v29 > v27->m_end )
          m_cur = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v27, v28);
        else
          v27->m_cur = v29;
      }
      faceVertices.m_data = m_cur;
      v64 = m_cur;
      faceVertices.m_capacityAndFlags = v26 | 0x80000000;
      v30 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
              m_instancePtr->m_originalFaces,
              m_instancePtr->m_numOriginalFaces,
              &m_instancePtr->m_instancedFaces,
              &m_instancePtr->m_ownedFaces,
              &m_instancePtr->m_faceMap,
              v11 & 0x3FFFFF)->m_numEdges;
      indexRemap.m_data = 0i64;
      indexRemap.m_size = 0;
      indexRemap.m_capacityAndFlags = 0x80000000;
      v62 = v30;
      if ( v30 )
      {
        v31 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v32 = (int *)v31->m_cur;
        v33 = (4 * v30 + 127) & 0xFFFFFF80;
        v34 = (char *)v32 + v33;
        if ( v33 > v31->m_slabSize || v34 > v31->m_end )
          v32 = (int *)hkLifoAllocator::allocateFromNewSlab(v31, v33);
        else
          v31->m_cur = v34;
      }
      else
      {
        v32 = 0i64;
      }
      indexRemap.m_data = v32;
      p = v32;
      indexRemap.m_capacityAndFlags = v30 | 0x80000000;
      if ( v54 <= 0 )
      {
        hkaiAbstractFaceCutter::reset(&v68, v11);
        v5 = this;
      }
      else
      {
        v5 = this;
        regionExpansion.m_real = _mm_shuffle_ps(
                                   (__m128)LODWORD(genParams->m_maxSilhouetteSize),
                                   (__m128)LODWORD(genParams->m_maxSilhouetteSize),
                                   0);
        hkaiAbstractFaceCutter::setFace(
          &v68,
          m_instancePtr,
          &this->m_up,
          v52,
          v11,
          &regionExpansion,
          &faceVertices,
          &indexRemap);
      }
      v35 = 0;
      if ( v54 > 0 )
      {
        v36 = 0i64;
        v37 = 0i64;
        do
        {
          if ( v58 <= v35 )
            v38 = -1;
          else
            v38 = *(_DWORD *)&v57[v37];
          hkaiAbstractFaceCutter::addSilhouette(&v68, *(hkVector4f **)&v53[v36], *(_DWORD *)&v53[v36 + 8], v38);
          ++v35;
          v37 += 4i64;
          v36 += 16i64;
        }
        while ( v35 < v54 );
      }
      hkaiAbstractFaceCutter::computeConvexDecomposition(&v68, v67, &faceVertices, &indexRemap);
      m_size = indexRemap.m_size;
      v40 = (char *)p;
      if ( p == indexRemap.m_data )
        m_size = 0;
      indexRemap.m_size = m_size;
      v41 = (4 * v62 + 127) & 0xFFFFFF80;
      v42 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v43 = (v41 + 15) & 0xFFFFFFF0;
      if ( v41 > v42->m_slabSize || &v40[v43] != v42->m_cur || v42->m_firstNonLifoEnd == v40 )
        hkLifoAllocator::slowBlockFree(v42, v40, v43);
      else
        v42->m_cur = v40;
      indexRemap.m_size = 0;
      if ( indexRemap.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          indexRemap.m_data,
          4 * indexRemap.m_capacityAndFlags);
      v44 = faceVertices.m_size;
      v45 = (char *)v64;
      indexRemap.m_data = 0i64;
      if ( v64 == faceVertices.m_data )
        v44 = 0;
      indexRemap.m_capacityAndFlags = 0x80000000;
      faceVertices.m_size = v44;
      v46 = (16 * v65 + 127) & 0xFFFFFF80;
      v47 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v48 = (v46 + 15) & 0xFFFFFFF0;
      if ( v46 > v47->m_slabSize || &v45[v48] != v47->m_cur || v47->m_firstNonLifoEnd == v45 )
        hkLifoAllocator::slowBlockFree(v47, v45, v48);
      else
        v47->m_cur = v45;
      faceVertices.m_size = 0;
      if ( faceVertices.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          faceVertices.m_data,
          16 * faceVertices.m_capacityAndFlags);
      faceVertices.m_data = 0i64;
      faceVertices.m_capacityAndFlags = 0x80000000;
      v58 = 0;
      if ( v59 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v57, 4 * v59);
      v57 = 0i64;
      v59 = 0x80000000;
      v49 = v54 - 1;
      if ( v54 - 1 >= 0 )
      {
        v50 = (int *)&v53[16 * v54 - 4];
        do
        {
          v51 = *v50;
          *(v50 - 1) = 0;
          if ( v51 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              &hkContainerTempAllocator::s_alloc,
              *(void **)(v50 - 3),
              16 * v51);
          *(_QWORD *)(v50 - 3) = 0i64;
          *v50 = 0x80000000;
          v50 -= 4;
          --v49;
        }
        while ( v49 >= 0 );
      }
      v54 = 0;
      if ( v55 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v53, 16 * v55);
      v6 = faceKeys;
      v7 = genParams;
      v8 = selector;
      v9 = v56 + 1;
      v10 = v66 + 4;
      v53 = 0i64;
      v55 = 0x80000000;
      v56 = v9;
      v66 += 4i64;
    }
    while ( v9 < faceKeys->m_size );
  }
  hkaiAbstractFaceCutter::~hkaiAbstractFaceCutter(&v68);
}

// File Line: 434
// RVA: 0xBF0FE0
void __fastcall hkaiNavMeshCutter::intersectMeshWithSilhouettesMT(
        hkaiNavMeshCutter *this,
        hkArrayBase<unsigned int> *faceKeys,
        hkaiNavMeshSilhouetteSelector *selector,
        hkaiSilhouetteGenerationParameters *genParams,
        hkJobQueue *jobQueue,
        hkJobThreadPool *threadPool,
        hkArrayBase<hkaiFaceCutResults> *results)
{
  int v11; // ebx
  __int64 v12; // r14
  unsigned int *m_data; // rax
  __int64 v14; // rdx
  hkJob job; // [rsp+20h] [rbp-A8h] BYREF
  __int128 v16; // [rsp+30h] [rbp-98h]
  __int64 v17; // [rsp+40h] [rbp-88h]
  int v18; // [rsp+48h] [rbp-80h]
  __int64 v19; // [rsp+50h] [rbp-78h]
  int v20; // [rsp+58h] [rbp-70h]
  int v21; // [rsp+5Ch] [rbp-6Ch]
  __int128 v22; // [rsp+60h] [rbp-68h]
  __int64 v23; // [rsp+70h] [rbp-58h]
  char v24; // [rsp+78h] [rbp-50h]
  char m_bool; // [rsp+79h] [rbp-4Fh]
  __int128 v26; // [rsp+80h] [rbp-48h]

  v11 = 0;
  if ( faceKeys->m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      v17 = 0i64;
      v19 = 0i64;
      m_data = faceKeys->m_data;
      v22 = 0i64;
      v26 = 0i64;
      v16 = 0i64;
      job.m_threadAffinity = -1;
      v20 = -1;
      v21 = -1;
      *(_WORD *)&job.m_jobSubType = 2816;
      job.m_jobSpuType.m_storage = 1;
      job.m_size = 112;
      v18 = -1;
      v23 = 0i64;
      v24 = 0;
      v14 = m_data[v12];
      *((_QWORD *)&v26 + 1) = genParams;
      *(_QWORD *)&v26 = &results->m_data[v11];
      m_bool = this->m_useNewCutter.m_bool;
      selector->vfptr->setupJobForFace(selector, v14, (hkaiNavMeshCutFaceJob *)&job);
      hkJobQueue::addJob(jobQueue, &job, JOB_HIGH_PRIORITY);
      ++v11;
      ++v12;
    }
    while ( v11 < faceKeys->m_size );
  }
  ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, __int64))threadPool->vfptr[5].__first_virtual_table_function__)(
    threadPool,
    jobQueue,
    11i64);
  hkJobQueue::processAllJobs(jobQueue, 1);
  ((void (__fastcall *)(hkJobThreadPool *))threadPool->vfptr[2].__vecDelDtor)(threadPool);
}

// File Line: 459
// RVA: 0xBEE5D0
__int64 __fastcall hkaiNavMeshCutter::getCutKeysFromOriginal(
        hkaiNavMeshCutter *this,
        unsigned int origKey,
        hkArray<unsigned int,hkContainerHeapAllocator> *cutOut)
{
  unsigned int v4; // r12d
  unsigned int v5; // r15d
  hkaiNavMeshCutter::MeshInfo *v6; // rbp
  __int64 v7; // rsi
  __int64 v8; // r14
  unsigned int v9; // edi

  v4 = origKey >> 22;
  v5 = origKey & 0x3FFFFF;
  v6 = &this->m_meshInfos.m_data[origKey >> 22];
  v7 = v6->m_magic.m_data[origKey & 0x3FFFFF];
  if ( (int)v7 < 0 )
    return 0i64;
  if ( (int)v7 < v6->m_magic.m_size )
  {
    v8 = v7;
    do
    {
      if ( v6->m_magic.m_data[v8] != v5 )
        break;
      v9 = v7 | (v4 << 22);
      if ( cutOut->m_size == (cutOut->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, cutOut, 4);
      LODWORD(v7) = v7 + 1;
      cutOut->m_data[cutOut->m_size++] = v9;
      ++v8;
    }
    while ( (int)v7 < v6->m_magic.m_size );
  }
  return 1i64;
}

// File Line: 491
// RVA: 0xBEE590
__int64 __fastcall hkaiNavMeshCutter::getFirstCutKeyFromOriginal(hkaiNavMeshCutter *this, unsigned int orig)
{
  signed int v3; // edx
  unsigned int v4; // eax
  hkaiNavMeshCutter::MeshInfo *v5; // r8
  int v6; // r8d

  v3 = orig & 0x3FFFFF;
  v4 = orig >> 22;
  v5 = &this->m_meshInfos.m_data[v4];
  if ( v3 >= v5->m_originalNumFaces )
    return 0xFFFFFFFFi64;
  v6 = v5->m_magic.m_data[v3];
  if ( v6 < 0 )
    return 0xFFFFFFFFi64;
  else
    return v6 | (v4 << 22);
}

// File Line: 514
// RVA: 0xBEE6B0
_BOOL8 __fastcall hkaiNavMeshCutter::getCutKeyRangeFromOriginal(
        hkaiNavMeshCutter *this,
        unsigned int origKey,
        int *faceStartOut,
        int *faceEndOut)
{
  unsigned int v5; // r10d
  hkaiNavMeshCutter::MeshInfo *v7; // r11
  __int64 v8; // r8
  __int64 m_size; // r9
  __int64 v10; // rax
  int *v11; // rdx

  v5 = origKey & 0x3FFFFF;
  v7 = &this->m_meshInfos.m_data[origKey >> 22];
  v8 = v7->m_magic.m_data[origKey & 0x3FFFFF];
  if ( (int)v8 < 0 )
  {
    *faceStartOut = -1;
    *faceEndOut = -1;
    return (_DWORD)v8 == -2;
  }
  else
  {
    *faceStartOut = v8;
    m_size = v7->m_magic.m_size;
    v10 = v8;
    if ( v8 < m_size )
    {
      v11 = &v7->m_magic.m_data[v8];
      do
      {
        if ( *v11 != v5 )
          break;
        ++v10;
        LODWORD(v8) = v8 + 1;
        ++v11;
      }
      while ( v10 < m_size );
    }
    *faceEndOut = v8 - 1;
    return 1i64;
  }
}

// File Line: 548
// RVA: 0xBEE760
__int64 __fastcall hkaiNavMeshCutter::getNumCutKeysFromOriginal(hkaiNavMeshCutter *this, unsigned int origKey)
{
  __int64 v2; // r8
  signed int v3; // r9d
  unsigned int v4; // edx
  hkaiNavMeshCutter::MeshInfo *v5; // r8
  int *m_data; // r10
  __int64 v7; // rcx
  __int64 m_size; // r8
  int *v9; // rax

  v2 = origKey >> 22;
  v3 = origKey & 0x3FFFFF;
  v4 = 0;
  v5 = &this->m_meshInfos.m_data[v2];
  m_data = v5->m_magic.m_data;
  v7 = m_data[v3];
  if ( (int)v7 >= 0 )
  {
    m_size = v5->m_magic.m_size;
    if ( v7 < m_size )
    {
      v9 = &m_data[v7];
      do
      {
        if ( *v9 != v3 )
          break;
        ++v7;
        ++v4;
        ++v9;
      }
      while ( v7 < m_size );
    }
  }
  return v4;
}

// File Line: 571
// RVA: 0xBEE7C0
__int64 __fastcall hkaiNavMeshCutter::getOriginalFromCutKey(hkaiNavMeshCutter *this, unsigned int cutFaceKey)
{
  signed int v3; // edx
  unsigned int v4; // r8d
  hkaiNavMeshCutter::MeshInfo *v5; // rax

  v3 = cutFaceKey & 0x3FFFFF;
  v4 = cutFaceKey >> 22;
  v5 = &this->m_meshInfos.m_data[v4];
  if ( v3 >= v5->m_originalNumFaces )
    return (v4 << 22) | v5->m_magic.m_data[v3];
  else
    return 0xFFFFFFFFi64;
}

// File Line: 589
// RVA: 0xBF26B0
void __fastcall getUpdatedSections(
        hkArrayBase<unsigned int> *updatedFaceKeys,
        hkArray<int,hkContainerTempAllocator> *updatedSections)
{
  int v3; // esi
  int v4; // ecx
  __int64 v6; // r14
  unsigned int v7; // edi

  v3 = 0;
  v4 = -1;
  if ( updatedFaceKeys->m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      v7 = updatedFaceKeys->m_data[v6] >> 22;
      if ( v7 != v4 )
      {
        if ( updatedSections->m_size == (updatedSections->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, updatedSections, 4);
        updatedSections->m_data[updatedSections->m_size++] = v7;
        v4 = v7;
      }
      ++v3;
      ++v6;
    }
    while ( v3 < updatedFaceKeys->m_size );
  }
}

// File Line: 617
// RVA: 0xBEDED0
__int64 __fastcall hkaiNavMeshCutter::cutSilhouettesIncremental(
        hkaiNavMeshCutter *this,
        hkaiNavMeshSilhouetteSelector *selector,
        hkaiSilhouetteGenerationParameters *genParams,
        hkArray<unsigned int,hkContainerTempAllocator> *cutFaceKeys,
        hkBitField *uncutFaceKeys,
        hkJobQueue *sectionsToStep,
        hkJobQueue *jobQueue,
        hkJobThreadPool *threadPool)
{
  hkaiSilhouetteGenerationParameters *v8; // rbx
  _QWORD *Value; // rax
  unsigned __int64 v14; // r9
  _QWORD *v15; // r10
  unsigned __int64 v16; // rax
  __int64 v17; // rsi
  int v18; // r8d
  __int64 i; // r9
  char *v20; // r11
  unsigned int v21; // r10d
  hkaiNavMeshInstance *m_instancePtr; // rax
  char m_storage; // cl
  hkArray<unsigned int,hkContainerTempAllocator> **p_params; // rax
  __int64 v25; // rax
  int m_size; // eax
  __int64 v27; // r12
  int v28; // r15d
  unsigned int v29; // ebx
  __int64 v30; // r10
  int v31; // edx
  __int64 v32; // rcx
  char *v33; // r9
  char *v34; // rax
  __int64 v35; // r8
  int v36; // edx
  __int64 v37; // rcx
  unsigned int *m_data; // rax
  bool v39; // zf
  hkaiStreamingCollection *m_pntr; // rcx
  int v41; // ebx
  _QWORD *v42; // rax
  _QWORD *v43; // rcx
  _QWORD *v44; // r8
  unsigned __int64 v45; // rax
  _QWORD *v46; // rcx
  int v47; // r9d
  unsigned int *v48; // r8
  hkaiStreamingCollection *v49; // rcx
  int v50; // ebx
  hkaiFaceCutResults *v51; // rax
  int v52; // edx
  hkaiFaceCutResults *v53; // rcx
  int v54; // eax
  __int64 v55; // rdx
  char **p_m_data; // rcx
  hkJobQueue *v57; // rsi
  hkJobThreadPool *v58; // rbx
  _QWORD *v59; // r8
  _QWORD *v60; // rcx
  unsigned __int64 v61; // rax
  _QWORD *v62; // rcx
  _QWORD *v63; // r8
  _QWORD *v64; // rcx
  unsigned __int64 v65; // rax
  _QWORD *v66; // rcx
  _QWORD *v67; // rax
  _QWORD *v68; // rcx
  _QWORD *v69; // r8
  unsigned __int64 v70; // rax
  _QWORD *v71; // rcx
  _QWORD *v72; // rax
  _QWORD *v73; // rcx
  _QWORD *v74; // r8
  unsigned __int64 v75; // rax
  _QWORD *v76; // rcx
  hkArrayBase<unsigned int> cutFaceKeysa; // [rsp+38h] [rbp-59h] BYREF
  hkArray<unsigned int,hkContainerTempAllocator> forceRecutFaceKeys; // [rsp+48h] [rbp-49h] BYREF
  hkArrayBase<hkaiFaceCutResults> array; // [rsp+58h] [rbp-39h] BYREF
  hkArray<int,hkContainerTempAllocator> updatedSections; // [rsp+68h] [rbp-29h] BYREF
  hkaiNavMeshCutter::SavedConnectivity tempConnectivity; // [rsp+78h] [rbp-19h] BYREF
  void *retaddr; // [rsp+D8h] [rbp+47h] BYREF
  hkaiSilhouetteGenerationParameters *v84; // [rsp+E8h] [rbp+57h]
  hkArray<unsigned int,hkContainerTempAllocator> *params; // [rsp+F8h] [rbp+67h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = Value[1];
  v15 = Value;
  if ( v14 < Value[3] )
  {
    *(_QWORD *)v14 = "LtcutSilhouettes";
    *(_QWORD *)(v14 + 16) = "StgetUpdatedFaces";
    v16 = __rdtsc();
    *(_DWORD *)(v14 + 8) = v16;
    v15[1] = v14 + 24;
  }
  v17 = (__int64)params;
  selector->vfptr->getUpdatedFaces(selector, this, cutFaceKeys, params, uncutFaceKeys);
  v18 = *(_DWORD *)(v17 + 8) - 1;
  for ( i = v18; i >= 0; --i )
  {
    v20 = *(char **)v17;
    v21 = *(_DWORD *)(*(_QWORD *)v17 + 4 * i);
    m_instancePtr = this->m_streamingCollection.m_pntr->m_instances.m_data[v21 >> 22].m_instancePtr;
    if ( m_instancePtr->m_faceFlags.m_size )
    {
      m_storage = m_instancePtr->m_faceFlags.m_data[v21 & 0x3FFFFF].m_storage;
      p_params = &params;
      LOBYTE(params) = m_storage;
    }
    else
    {
      LOBYTE(retaddr) = 0;
      p_params = (hkArray<unsigned int,hkContainerTempAllocator> **)&retaddr;
    }
    if ( (*(_BYTE *)p_params & 1) == 0 )
    {
      v25 = (int)--*(_DWORD *)(v17 + 8);
      if ( (_DWORD)v25 != v18 )
        *(_DWORD *)&v20[4 * i] = *(_DWORD *)&v20[4 * v25];
    }
    --v18;
  }
  m_size = this->m_forceRecutFaceKeys.m_size;
  v27 = 0i64;
  v84 = v8;
  if ( m_size )
  {
    v28 = 0;
    if ( m_size > 0 )
    {
      do
      {
        v29 = this->m_forceRecutFaceKeys.m_data[v27];
        if ( this->m_streamingCollection.m_pntr->m_instances.m_data[v29 >> 22].m_instancePtr )
        {
          v30 = *(int *)(v17 + 8);
          v31 = 0;
          v32 = 0i64;
          if ( (int)v30 <= 0 )
            goto LABEL_18;
          v33 = *(char **)v17;
          v34 = *(char **)v17;
          while ( *(_DWORD *)v34 != v29 )
          {
            ++v32;
            ++v31;
            v34 += 4;
            if ( v32 >= v30 )
              goto LABEL_18;
          }
          if ( v32 == -1 )
          {
LABEL_18:
            v35 = cutFaceKeys->m_size;
            v36 = 0;
            v37 = 0i64;
            if ( v35 > 0 )
            {
              m_data = cutFaceKeys->m_data;
              while ( *m_data != v29 )
              {
                ++v37;
                ++v36;
                ++m_data;
                if ( v37 >= v35 )
                  goto LABEL_27;
              }
              if ( v36 != -1 )
                goto LABEL_30;
            }
          }
          else
          {
            *(_DWORD *)(v17 + 8) = v30 - 1;
            if ( (_DWORD)v30 - 1 != v31 )
              *(_DWORD *)&v33[4 * v32] = *(_DWORD *)&v33[4 * (int)v30 - 4];
          }
LABEL_27:
          if ( cutFaceKeys->m_size == (cutFaceKeys->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, cutFaceKeys, 4);
          cutFaceKeys->m_data[cutFaceKeys->m_size++] = v29;
        }
LABEL_30:
        ++v28;
        ++v27;
      }
      while ( v28 < this->m_forceRecutFaceKeys.m_size );
    }
    genParams = v84;
    this->m_forceRecutFaceKeys.m_size = 0;
  }
  v39 = cutFaceKeys->m_size == 0;
  updatedSections.m_data = 0i64;
  updatedSections.m_size = 0;
  updatedSections.m_capacityAndFlags = 0x80000000;
  if ( !v39 || *(_DWORD *)(v17 + 8) )
  {
    m_pntr = this->m_streamingCollection.m_pntr;
    LOBYTE(params) = 1;
    v41 = hkaiUserEdgeUtils::removeUserEdgesFromFaces(
            m_pntr,
            cutFaceKeys,
            (hkaiUserEdgeUtils::RemoveParameters *)&params);
    v42 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v43 = (_QWORD *)v42[1];
    v44 = v42;
    if ( (unsigned __int64)v43 < v42[3] )
    {
      *v43 = "Stuncut";
      v45 = __rdtsc();
      v46 = v43 + 2;
      *((_DWORD *)v46 - 2) = v45;
      v44[1] = v46;
    }
    v47 = cutFaceKeys->m_size;
    v48 = cutFaceKeys->m_data;
    cutFaceKeysa.m_data = 0i64;
    cutFaceKeysa.m_size = 0;
    cutFaceKeysa.m_capacityAndFlags = 0x80000000;
    hkArrayBase<unsigned int>::_append(&cutFaceKeysa, &hkContainerTempAllocator::s_alloc, (char *)v48, v47);
    hkArrayBase<unsigned int>::_append(
      &cutFaceKeysa,
      &hkContainerTempAllocator::s_alloc,
      *(char **)v17,
      *(_DWORD *)(v17 + 8));
    if ( cutFaceKeysa.m_size > 1 )
      hkAlgorithm::quickSortRecursive<unsigned int,hkAlgorithm::less<unsigned int>>(
        cutFaceKeysa.m_data,
        0,
        cutFaceKeysa.m_size - 1,
        0);
    hkaiNavMeshCutter::SavedConnectivity::SavedConnectivity(&tempConnectivity);
    forceRecutFaceKeys.m_data = 0i64;
    forceRecutFaceKeys.m_size = 0;
    forceRecutFaceKeys.m_capacityAndFlags = 0x80000000;
    hkaiNavMeshCutter::calcNewConnectivity(
      this,
      (hkArrayBase<unsigned int> *)v17,
      &cutFaceKeysa,
      &tempConnectivity,
      &forceRecutFaceKeys);
    if ( forceRecutFaceKeys.m_size )
    {
      hkArrayBase<unsigned int>::_append(
        cutFaceKeys,
        &hkContainerTempAllocator::s_alloc,
        (char *)forceRecutFaceKeys.m_data,
        forceRecutFaceKeys.m_size);
      hkArrayBase<unsigned int>::_append(
        &cutFaceKeysa,
        &hkContainerTempAllocator::s_alloc,
        (char *)forceRecutFaceKeys.m_data,
        forceRecutFaceKeys.m_size);
      v49 = this->m_streamingCollection.m_pntr;
      LOBYTE(params) = 1;
      v41 += hkaiUserEdgeUtils::removeUserEdgesFromFaces(
               v49,
               &forceRecutFaceKeys,
               (hkaiUserEdgeUtils::RemoveParameters *)&params);
      if ( cutFaceKeysa.m_size > 1 )
        hkAlgorithm::quickSortRecursive<unsigned int,hkAlgorithm::less<unsigned int>>(
          cutFaceKeysa.m_data,
          0,
          cutFaceKeysa.m_size - 1,
          0);
    }
    getUpdatedSections(&cutFaceKeysa, &updatedSections);
    hkaiNavMeshCutter::removeCutFacesFromOriginals(
      this,
      &updatedSections,
      &cutFaceKeysa,
      (hkaiNavMeshUtils::RemoveOwnedFacesMode)(v41 == 0));
    hkaiNavMeshCutter::restoreConnectivity(this->m_streamingCollection.m_pntr, &forceRecutFaceKeys, &tempConnectivity);
    hkaiNavMeshCutter::SavedConnectivity::append(&this->m_connectivityInfo, &tempConnectivity);
    forceRecutFaceKeys.m_size = 0;
    if ( forceRecutFaceKeys.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        forceRecutFaceKeys.m_data,
        4 * forceRecutFaceKeys.m_capacityAndFlags);
    forceRecutFaceKeys.m_data = 0i64;
    forceRecutFaceKeys.m_capacityAndFlags = 0x80000000;
    hkaiNavMeshCutter::SavedConnectivity::~SavedConnectivity(&tempConnectivity);
    cutFaceKeysa.m_size = 0;
    if ( cutFaceKeysa.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        cutFaceKeysa.m_data,
        4 * cutFaceKeysa.m_capacityAndFlags);
    v50 = cutFaceKeys->m_size;
    v51 = 0i64;
    v52 = 0;
    array.m_data = 0i64;
    array.m_size = 0;
    array.m_capacityAndFlags = 0x80000000;
    if ( v50 > 0 )
    {
      hkArrayUtil::_reserve((hkResult *)&params, &hkContainerTempAllocator::s_alloc, &array, v50, 32);
      v52 = array.m_size;
      v51 = array.m_data;
    }
    v53 = &v51[v52];
    v54 = v50 - v52;
    v55 = v50 - v52;
    if ( v54 > 0 )
    {
      p_m_data = &v53->m_data;
      do
      {
        if ( p_m_data != (char **)24 )
        {
          *((_BYTE *)p_m_data - 8) = 0;
          *p_m_data = 0i64;
        }
        p_m_data += 4;
        --v55;
      }
      while ( v55 );
    }
    v57 = sectionsToStep;
    array.m_size = v50;
    if ( sectionsToStep && (v58 = (hkJobThreadPool *)jobQueue) != 0i64 )
    {
      v59 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v60 = (_QWORD *)v59[1];
      if ( (unsigned __int64)v60 < v59[3] )
      {
        *v60 = "StintersectMT";
        v61 = __rdtsc();
        v62 = v60 + 2;
        *((_DWORD *)v62 - 2) = v61;
        v59[1] = v62;
      }
      hkaiNavMeshCutter::intersectMeshWithSilhouettesMT(this, cutFaceKeys, selector, genParams, v57, v58, &array);
    }
    else
    {
      v63 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v64 = (_QWORD *)v63[1];
      if ( (unsigned __int64)v64 < v63[3] )
      {
        *v64 = "StintersectST";
        v65 = __rdtsc();
        v66 = v64 + 2;
        *((_DWORD *)v66 - 2) = v65;
        v63[1] = v66;
      }
      hkaiNavMeshCutter::intersectMeshWithSilhouettes(this, cutFaceKeys, selector, genParams, &array);
    }
    hkaiNavMeshCutter::applyCutResults(
      this,
      &updatedSections,
      (hkArray<hkaiFaceCutResults,hkContainerTempAllocator> *)&array,
      cutFaceKeys);
    array.m_size = 0;
    if ( array.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        array.m_data,
        32 * array.m_capacityAndFlags);
  }
  v67 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v68 = (_QWORD *)v67[1];
  v69 = v67;
  if ( (unsigned __int64)v68 < v67[3] )
  {
    *v68 = "Streset clearance cache";
    v70 = __rdtsc();
    v71 = v68 + 2;
    *((_DWORD *)v71 - 2) = v70;
    v69[1] = v71;
  }
  hkaiNavMeshCutter::resetClearanceForCutFaces(this, &updatedSections, cutFaceKeys);
  updatedSections.m_size = 0;
  if ( updatedSections.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      updatedSections.m_data,
      4 * updatedSections.m_capacityAndFlags);
  updatedSections.m_data = 0i64;
  updatedSections.m_capacityAndFlags = 0x80000000;
  v72 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v73 = (_QWORD *)v72[1];
  v74 = v72;
  if ( (unsigned __int64)v73 < v72[3] )
  {
    *v73 = "lt";
    v75 = __rdtsc();
    v76 = v73 + 2;
    *((_DWORD *)v76 - 2) = v75;
    v74[1] = v76;
  }
  return 1i64;
}

// File Line: 758
// RVA: 0xBEF6E0
void __fastcall hkaiNavMeshCutter::gatherCutEdgesFromCutFaces(
        hkaiNavMeshCutter *this,
        unsigned int originalEdgeKey,
        hkArrayBase<unsigned int> *cutFaceKeys,
        hkArray<hkaiNavMeshCutter::FaceEdgePair,hkContainerTempAllocator> *cutPairs)
{
  hkArrayBase<unsigned int> *v4; // rdi
  __int64 v6; // r11
  hkaiNavMeshInstance *m_instancePtr; // rbp
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // r14
  int v9; // r13d
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_instancedFaces; // r8
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_ownedFaces; // r9
  __int64 v12; // rcx
  int index; // r12d
  hkaiNavMesh::Face *v14; // rax
  int m_startEdgeIndex; // ebx
  hkaiNavMesh::Face *v16; // r15
  __int64 v17; // r14
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_ownedEdges; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_instancedEdges; // rcx
  __int64 m_numOriginalEdges; // rdi
  hkaiNavMesh::Edge *v21; // rax
  unsigned __int16 v22; // r8
  __int64 m_size; // rdx
  hkaiNavMeshCutter::FaceEdgePair *v24; // r8
  int v25; // [rsp+30h] [rbp-48h]
  __int64 v26; // [rsp+38h] [rbp-40h]
  unsigned int v27; // [rsp+80h] [rbp+8h]
  unsigned int v28; // [rsp+88h] [rbp+10h]

  v4 = cutFaceKeys;
  v6 = originalEdgeKey >> 22;
  v27 = originalEdgeKey >> 22;
  m_instancePtr = this->m_streamingCollection.m_pntr->m_instances.m_data[v6].m_instancePtr;
  instanceMap = &m_instancePtr->m_faceMap;
  v9 = 0;
  v25 = 0;
  v28 = (originalEdgeKey & 0x3FFFFF)
      - hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
          m_instancePtr->m_originalFaces,
          m_instancePtr->m_numOriginalFaces,
          &m_instancePtr->m_instancedFaces,
          &m_instancePtr->m_ownedFaces,
          &m_instancePtr->m_faceMap,
          this->m_meshInfos.m_data[v6].m_magic.m_data[*cutFaceKeys->m_data & 0x3FFFFF])->m_startEdgeIndex;
  if ( v4->m_size > 0 )
  {
    v12 = 0i64;
    v26 = 0i64;
    do
    {
      index = *(unsigned int *)((_BYTE *)v4->m_data + v12) & 0x3FFFFF;
      v14 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
              m_instancePtr->m_originalFaces,
              m_instancePtr->m_numOriginalFaces,
              p_m_instancedFaces,
              p_m_ownedFaces,
              instanceMap,
              index);
      m_startEdgeIndex = v14->m_startEdgeIndex;
      v16 = v14;
      v17 = v14->m_startEdgeIndex;
      if ( v14->m_startEdgeIndex < v14->m_startEdgeIndex + v14->m_numEdges )
      {
        p_m_ownedEdges = &m_instancePtr->m_ownedEdges;
        p_m_instancedEdges = &m_instancePtr->m_instancedEdges;
        do
        {
          m_numOriginalEdges = m_instancePtr->m_numOriginalEdges;
          v21 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__8(
                  m_instancePtr->m_originalEdges,
                  m_instancePtr->m_numOriginalEdges,
                  p_m_instancedEdges,
                  p_m_ownedEdges,
                  &m_instancePtr->m_edgeMap,
                  m_startEdgeIndex);
          if ( m_startEdgeIndex < (int)m_numOriginalEdges )
            v22 = -1;
          else
            v22 = m_instancePtr->m_cuttingInfo.m_data[v17 - m_numOriginalEdges];
          if ( (v21->m_flags.m_storage & 4) != 0 && v22 == v28 )
          {
            if ( cutPairs->m_size == (cutPairs->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, cutPairs, 8);
            m_size = cutPairs->m_size;
            v24 = &cutPairs->m_data[m_size];
            cutPairs->m_size = m_size + 1;
            v24->m_edgeKey = m_startEdgeIndex | (v27 << 22);
            v24->m_faceKey = index | (v27 << 22);
          }
          ++m_startEdgeIndex;
          ++v17;
          p_m_instancedEdges = &m_instancePtr->m_instancedEdges;
          p_m_ownedEdges = &m_instancePtr->m_ownedEdges;
        }
        while ( m_startEdgeIndex < v16->m_startEdgeIndex + v16->m_numEdges );
        v9 = v25;
        v4 = cutFaceKeys;
        p_m_ownedFaces = &m_instancePtr->m_ownedFaces;
        p_m_instancedFaces = &m_instancePtr->m_instancedFaces;
      }
      ++v9;
      instanceMap = &m_instancePtr->m_faceMap;
      v12 = v26 + 4;
      v25 = v9;
      v26 += 4i64;
    }
    while ( v9 < v4->m_size );
  }
}

// File Line: 799
// RVA: 0xBEF2E0
void __fastcall hkaiNavMeshCutter::gatherCutEdges(
        hkaiNavMeshCutter *this,
        unsigned int originalEdgeKey,
        unsigned int originalFaceKey,
        hkArray<hkaiNavMeshCutter::FaceEdgePair,hkContainerTempAllocator> *cutPairs,
        hkaiNavMeshCutter::GatherCutEdgesMode gatherMode)
{
  signed int v7; // r12d
  hkaiNavMeshInstance *m_instancePtr; // rbp
  unsigned int v11; // r15d
  hkaiNavMesh::Face *v12; // rax
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_ownedFaces; // r9
  int v14; // r11d
  hkaiNavMeshCutter::MeshInfo *v15; // r8
  __int64 v16; // rdx
  hkaiNavMeshCutter::FaceEdgePair *v17; // r8
  __int64 index; // r12
  int v19; // edx
  __int64 v20; // r13
  hkaiNavMesh::Face *v21; // r15
  int m_startEdgeIndex; // ebx
  __int64 v23; // r14
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_ownedEdges; // rcx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_instancedEdges; // rdx
  __int64 m_numOriginalEdges; // rdi
  hkaiNavMesh::Edge *v28; // rax
  __int16 v29; // dx
  __int64 m_size; // rdx
  hkaiNavMeshCutter::FaceEdgePair *v31; // r8
  unsigned int v32; // [rsp+30h] [rbp-58h]
  __int64 v33; // [rsp+38h] [rbp-50h]
  hkaiNavMeshCutter::MeshInfo *v34; // [rsp+38h] [rbp-50h]
  __int64 v35; // [rsp+40h] [rbp-48h]
  __int64 i; // [rsp+48h] [rbp-40h]
  unsigned int v37; // [rsp+90h] [rbp+8h]
  char m_storage; // [rsp+98h] [rbp+10h]
  unsigned int v39; // [rsp+A0h] [rbp+18h]

  v32 = originalEdgeKey >> 22;
  v7 = originalFaceKey & 0x3FFFFF;
  v33 = originalEdgeKey >> 22;
  m_instancePtr = this->m_streamingCollection.m_pntr->m_instances.m_data[v33].m_instancePtr;
  v11 = originalEdgeKey & 0x3FFFFF;
  v39 = originalFaceKey & 0x3FFFFF;
  v12 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
          m_instancePtr->m_originalFaces,
          m_instancePtr->m_numOriginalFaces,
          &m_instancePtr->m_instancedFaces,
          &m_instancePtr->m_ownedFaces,
          &m_instancePtr->m_faceMap,
          originalFaceKey & 0x3FFFFF);
  if ( m_instancePtr->m_faceFlags.m_size )
    m_storage = m_instancePtr->m_faceFlags.m_data[v7].m_storage;
  else
    m_storage = 0;
  v37 = v11 - v12->m_startEdgeIndex;
  v15 = &this->m_meshInfos.m_data[v33];
  v34 = v15;
  if ( (m_storage & 1) != 0 )
  {
    index = v15->m_magic.m_data[v7];
    v19 = v14 + m_instancePtr->m_ownedFaces.m_size;
    if ( (int)index >= 0 )
    {
      v35 = index;
      v20 = index;
      for ( i = v19; v20 < i; v35 = v20 )
      {
        if ( v15->m_magic.m_data[v20] != v39 )
          break;
        v21 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
                m_instancePtr->m_originalFaces,
                m_instancePtr->m_numOriginalFaces,
                &m_instancePtr->m_instancedFaces,
                p_m_ownedFaces,
                &m_instancePtr->m_faceMap,
                index);
        m_startEdgeIndex = v21->m_startEdgeIndex;
        v23 = v21->m_startEdgeIndex;
        if ( v21->m_startEdgeIndex < v21->m_startEdgeIndex + v21->m_numEdges )
        {
          instanceMap = &m_instancePtr->m_edgeMap;
          p_m_ownedEdges = &m_instancePtr->m_ownedEdges;
          p_m_instancedEdges = &m_instancePtr->m_instancedEdges;
          do
          {
            m_numOriginalEdges = m_instancePtr->m_numOriginalEdges;
            v28 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__8(
                    m_instancePtr->m_originalEdges,
                    m_instancePtr->m_numOriginalEdges,
                    p_m_instancedEdges,
                    p_m_ownedEdges,
                    instanceMap,
                    m_startEdgeIndex);
            if ( (v28->m_oppositeEdge == -1 || gatherMode != GATHER_BOUNDARY_EDGES) && (v28->m_flags.m_storage & 4) != 0 )
            {
              v29 = m_startEdgeIndex < (int)m_numOriginalEdges
                  ? -1
                  : m_instancePtr->m_cuttingInfo.m_data[v23 - m_numOriginalEdges];
              if ( v29 == (unsigned __int8)v37 )
              {
                if ( cutPairs->m_size == (cutPairs->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, cutPairs, 8);
                m_size = cutPairs->m_size;
                v31 = &cutPairs->m_data[m_size];
                cutPairs->m_size = m_size + 1;
                v31->m_edgeKey = m_startEdgeIndex | (v32 << 22);
                v31->m_faceKey = index | (v32 << 22);
              }
            }
            ++m_startEdgeIndex;
            ++v23;
            p_m_ownedEdges = &m_instancePtr->m_ownedEdges;
            p_m_instancedEdges = &m_instancePtr->m_instancedEdges;
            instanceMap = &m_instancePtr->m_edgeMap;
          }
          while ( m_startEdgeIndex < v21->m_startEdgeIndex + v21->m_numEdges );
          v20 = v35;
          p_m_ownedFaces = &m_instancePtr->m_ownedFaces;
        }
        v15 = v34;
        ++v20;
        LODWORD(index) = index + 1;
      }
    }
  }
  else
  {
    if ( cutPairs->m_size == (cutPairs->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, cutPairs, 8);
    v16 = cutPairs->m_size;
    v17 = &cutPairs->m_data[v16];
    cutPairs->m_size = v16 + 1;
    v17->m_faceKey = originalFaceKey;
    v17->m_edgeKey = originalEdgeKey;
  }
}

// File Line: 853
// RVA: 0xBEEB60
void __fastcall hkaiNavMeshCutter::uncutSection(hkaiNavMeshCutter *this, int sectionIndex, bool doChecks)
{
  hkaiStreamingCollection *m_pntr; // rax
  __int64 v4; // r9
  int m_size; // r11d
  int index; // esi
  __int64 v7; // r12
  int m_capacityAndFlags; // edx
  hkaiNavMeshCutter::MeshInfo *v9; // r12
  hkaiStreamingCollection::InstanceInfo *m_data; // rax
  hkaiNavMeshInstance *m_instancePtr; // r13
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_ownedFaces; // r14
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_instancedFaces; // r15
  hkResultEnum m_enum; // eax
  int v15; // ebx
  hkaiNavMesh::Face *v16; // rdi
  int m_startEdgeIndex; // ebx
  hkaiNavMeshCutter *v18; // rsi
  hkaiNavMesh::Edge *v19; // rax
  unsigned int m_oppositeEdge; // r8d
  hkaiNavMesh::Edge *v21; // r10
  hkaiNavMeshInstance *v22; // r9
  char *v23; // rax
  int m_numOriginalEdges; // eax
  int v25; // r8d
  __int64 v26; // rcx
  hkaiNavMesh::Edge *v27; // rax
  hkaiNavMesh::Edge *v28; // rdx
  unsigned int *v29; // rdi
  int v30; // r14d
  int m_numElems; // r15d
  int m_originalNumFaces; // r8d
  int m_numOriginalFaces; // edx
  int v34; // ecx
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rax
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v36; // rcx
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v37; // r10
  hkaiNavMesh::Face *v38; // rbx
  int v39; // r12d
  hkArray<int,hkContainerHeapAllocator> *p_m_edgeMap; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_ownedEdges; // rcx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_instancedEdges; // rdx
  hkaiNavMesh::Edge *v43; // r8
  unsigned int v44; // eax
  hkaiNavMeshInstance *v45; // rax
  char v46; // cl
  char *p_m_storage; // rax
  unsigned int m_oppositeFace; // ebx
  unsigned int OriginalFromCutKey; // esi
  int v50; // r9d
  int v51; // eax
  unsigned int v52; // edx
  bool v53; // cc
  hkaiNavMeshCutter *v54; // r13
  __int64 v55; // rsi
  int v56; // r9d
  int v57; // eax
  int v58; // eax
  unsigned int *v59; // rax
  int v60; // r14d
  unsigned int *v61; // r10
  int v62; // ecx
  __int64 i; // rax
  int v64; // edx
  __int64 v65; // rax
  int v66; // r9d
  __int64 v67; // rcx
  int v68; // edi
  int v69; // esi
  __int64 v70; // rdi
  hkaiStreamingCollection *v71; // rcx
  int v72; // edx
  __int64 j; // r8
  __int64 v74; // rax
  int v75; // r8d
  __int64 k; // r9
  __int64 v77; // rax
  char v78[4]; // [rsp+30h] [rbp-39h] BYREF
  int v79; // [rsp+34h] [rbp-35h]
  hkArrayBase<unsigned int> array; // [rsp+38h] [rbp-31h] BYREF
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > v81; // [rsp+48h] [rbp-21h] BYREF
  hkArrayBase<int> updatedSections; // [rsp+60h] [rbp-9h] BYREF
  hkResult result; // [rsp+70h] [rbp+7h] BYREF
  hkaiNavMeshCutter::MeshInfo *v84; // [rsp+78h] [rbp+Fh]
  hkaiNavMesh::Face *v85; // [rsp+80h] [rbp+17h]
  hkaiNavMeshCutter *v86; // [rsp+D0h] [rbp+67h] BYREF
  int sectionIndexa; // [rsp+D8h] [rbp+6Fh]
  char m_storage; // [rsp+E8h] [rbp+7Fh] BYREF

  sectionIndexa = sectionIndex;
  v86 = this;
  m_pntr = this->m_streamingCollection.m_pntr;
  v4 = sectionIndex;
  array.m_data = 0i64;
  m_size = 0;
  index = 0;
  array.m_size = 0;
  v7 = sectionIndex;
  m_capacityAndFlags = 0x80000000;
  v9 = &this->m_meshInfos.m_data[v7];
  array.m_capacityAndFlags = 0x80000000;
  m_data = m_pntr->m_instances.m_data;
  v84 = v9;
  v79 = 0;
  m_instancePtr = m_data[v4].m_instancePtr;
  if ( v9->m_originalNumFaces > 0 )
  {
    p_m_ownedFaces = &m_instancePtr->m_ownedFaces;
    p_m_instancedFaces = &m_instancePtr->m_instancedFaces;
    m_enum = (_DWORD)v4 << 22;
    for ( result.m_enum = (_DWORD)v4 << 22; ; m_enum = result.m_enum )
    {
      v15 = index | m_enum;
      if ( m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 4);
        m_size = array.m_size;
      }
      array.m_data[m_size] = v15;
      ++array.m_size;
      v16 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
              m_instancePtr->m_originalFaces,
              m_instancePtr->m_numOriginalFaces,
              p_m_instancedFaces,
              p_m_ownedFaces,
              &m_instancePtr->m_faceMap,
              index);
      m_startEdgeIndex = v16->m_startEdgeIndex;
      if ( m_startEdgeIndex < m_startEdgeIndex + v16->m_numEdges )
        break;
LABEL_24:
      v79 = ++index;
      if ( index >= v9->m_originalNumFaces )
        goto LABEL_26;
      m_capacityAndFlags = array.m_capacityAndFlags;
    }
    v18 = v86;
    while ( 1 )
    {
      v19 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__8(
              m_instancePtr->m_originalEdges,
              m_instancePtr->m_numOriginalEdges,
              &m_instancePtr->m_instancedEdges,
              &m_instancePtr->m_ownedEdges,
              &m_instancePtr->m_edgeMap,
              m_startEdgeIndex);
      m_oppositeEdge = v19->m_oppositeEdge;
      v21 = v19;
      if ( m_oppositeEdge == -1 || (v19->m_flags.m_storage & 0x40) == 0 )
        goto LABEL_22;
      v22 = v18->m_streamingCollection.m_pntr->m_instances.m_data[m_oppositeEdge >> 22].m_instancePtr;
      if ( v22->m_faceFlags.m_size )
      {
        v23 = &m_storage;
        m_storage = v22->m_faceFlags.m_data[v21->m_oppositeFace & 0x3FFFFF].m_storage;
      }
      else
      {
        v78[0] = 0;
        v23 = v78;
      }
      if ( (*v23 & 2) == 0 )
        goto LABEL_22;
      m_numOriginalEdges = v22->m_numOriginalEdges;
      v25 = m_oppositeEdge & 0x3FFFFF;
      if ( v25 >= m_numOriginalEdges )
        break;
      if ( v22->m_edgeMap.m_size )
        v25 = v22->m_edgeMap.m_data[v25];
      if ( v25 != -1 )
      {
        v26 = v25;
        v27 = v22->m_instancedEdges.m_data;
        goto LABEL_20;
      }
      v28 = 0i64;
LABEL_21:
      v28->m_oppositeFace = -1;
      v28->m_oppositeEdge = -1;
LABEL_22:
      if ( ++m_startEdgeIndex >= v16->m_startEdgeIndex + v16->m_numEdges )
      {
        index = v79;
        m_size = array.m_size;
        v9 = v84;
        p_m_ownedFaces = &m_instancePtr->m_ownedFaces;
        p_m_instancedFaces = &m_instancePtr->m_instancedFaces;
        goto LABEL_24;
      }
    }
    v26 = v25 - m_numOriginalEdges;
    v27 = v22->m_ownedEdges.m_data;
LABEL_20:
    v28 = &v27[v26];
    goto LABEL_21;
  }
LABEL_26:
  v81.m_elem.m_capacityAndFlags = 0x80000000;
  v29 = 0i64;
  v30 = 0;
  v81.m_elem.m_data = 0i64;
  v81.m_elem.m_size = 0;
  m_numElems = 0;
  v81.m_numElems = 0;
  m_originalNumFaces = v9->m_originalNumFaces;
  m_numOriginalFaces = m_instancePtr->m_numOriginalFaces;
  v34 = m_instancePtr->m_ownedFaces.m_size;
  v79 = m_originalNumFaces;
  if ( m_originalNumFaces < m_numOriginalFaces + v34 )
  {
    instanceMap = &m_instancePtr->m_faceMap;
    v36 = &m_instancePtr->m_ownedFaces;
    v37 = &m_instancePtr->m_instancedFaces;
    do
    {
      v38 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
              m_instancePtr->m_originalFaces,
              m_numOriginalFaces,
              v37,
              v36,
              instanceMap,
              m_originalNumFaces);
      v85 = v38;
      v39 = v38->m_startEdgeIndex;
      if ( v38->m_startEdgeIndex < v38->m_startEdgeIndex + v38->m_numEdges )
      {
        p_m_edgeMap = &m_instancePtr->m_edgeMap;
        p_m_ownedEdges = &m_instancePtr->m_ownedEdges;
        p_m_instancedEdges = &m_instancePtr->m_instancedEdges;
        do
        {
          v43 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__8(
                  m_instancePtr->m_originalEdges,
                  m_instancePtr->m_numOriginalEdges,
                  p_m_instancedEdges,
                  p_m_ownedEdges,
                  p_m_edgeMap,
                  v39);
          v44 = v43->m_oppositeEdge;
          if ( v44 != -1 && (v43->m_flags.m_storage & 0x40) != 0 )
          {
            v45 = v86->m_streamingCollection.m_pntr->m_instances.m_data[v44 >> 22].m_instancePtr;
            if ( v45->m_faceFlags.m_size )
            {
              v46 = v45->m_faceFlags.m_data[v43->m_oppositeFace & 0x3FFFFF].m_storage;
              p_m_storage = &m_storage;
              m_storage = v46;
            }
            else
            {
              v78[0] = 0;
              p_m_storage = v78;
            }
            if ( (*p_m_storage & 2) != 0 )
            {
              m_oppositeFace = v43->m_oppositeFace;
              if ( m_oppositeFace == -1 )
                m_oppositeFace = -1;
              OriginalFromCutKey = hkaiNavMeshCutter::getOriginalFromCutKey(v86, m_oppositeFace);
              if ( OriginalFromCutKey == -1 )
                OriginalFromCutKey = m_oppositeFace;
              if ( 2 * m_numElems > v30 - 1 )
              {
                hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
                  &v81,
                  &result,
                  2 * v30);
                m_numElems = v81.m_numElems;
                v30 = v81.m_elem.m_size;
                v29 = v81.m_elem.m_data;
              }
              v50 = 1;
              v51 = (v30 - 1) & (-1640531535 * (OriginalFromCutKey >> 4));
              v52 = v29[v51];
              if ( v52 != -1 )
              {
                while ( v52 != OriginalFromCutKey )
                {
                  v51 = (v30 - 1) & (v51 + 1);
                  v52 = v29[v51];
                  if ( v52 == -1 )
                    goto LABEL_47;
                }
                v50 = 0;
              }
LABEL_47:
              v38 = v85;
              v81.m_numElems = v50 + m_numElems;
              v29[v51] = OriginalFromCutKey;
              m_numElems = v81.m_numElems;
              v30 = v81.m_elem.m_size;
              v29 = v81.m_elem.m_data;
            }
          }
          ++v39;
          p_m_ownedEdges = &m_instancePtr->m_ownedEdges;
          p_m_instancedEdges = &m_instancePtr->m_instancedEdges;
          p_m_edgeMap = &m_instancePtr->m_edgeMap;
        }
        while ( v39 < v38->m_startEdgeIndex + v38->m_numEdges );
      }
      m_numOriginalFaces = m_instancePtr->m_numOriginalFaces;
      m_originalNumFaces = v79 + 1;
      instanceMap = &m_instancePtr->m_faceMap;
      v53 = v79 + 1 < m_numOriginalFaces + m_instancePtr->m_ownedFaces.m_size;
      v36 = &m_instancePtr->m_ownedFaces;
      ++v79;
      v37 = &m_instancePtr->m_instancedFaces;
    }
    while ( v53 );
    v9 = v84;
  }
  v54 = v86;
  v55 = v86->m_forceClearanceCalcFaceKeys.m_size;
  v56 = v55 + m_numElems;
  v57 = v86->m_forceClearanceCalcFaceKeys.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v57 < (int)v55 + m_numElems )
  {
    v58 = 2 * v57;
    if ( v56 < v58 )
      v56 = v58;
    hkArrayUtil::_reserve(
      (hkResult *)&v86,
      &hkContainerHeapAllocator::s_alloc,
      &v86->m_forceClearanceCalcFaceKeys,
      v56,
      4);
    v30 = v81.m_elem.m_size;
    v29 = v81.m_elem.m_data;
  }
  v59 = v54->m_forceClearanceCalcFaceKeys.m_data;
  v54->m_forceClearanceCalcFaceKeys.m_size += m_numElems;
  v60 = v30 - 1;
  v61 = &v59[v55];
  v62 = 0;
  for ( i = 0i64; i <= v60; ++v62 )
  {
    if ( v29[i] != -1 )
      break;
    ++i;
  }
  v64 = v62;
  if ( v62 <= v60 )
  {
    do
    {
      v65 = v64++;
      *v61++ = v29[v65];
      v29 = v81.m_elem.m_data;
      v66 = v81.m_elem.m_size - 1;
      v67 = v64;
      if ( v64 <= (__int64)(v81.m_elem.m_size - 1) )
      {
        do
        {
          if ( v81.m_elem.m_data[v67] != -1 )
            break;
          ++v67;
          ++v64;
        }
        while ( v67 <= v66 );
      }
    }
    while ( v64 <= v66 );
  }
  v68 = sectionIndexa;
  hkaiGraphUtils::removeDirectedUserEdgesToSection(v54->m_streamingCollection.m_pntr, sectionIndexa);
  updatedSections.m_data = 0i64;
  updatedSections.m_size = 0;
  updatedSections.m_capacityAndFlags = 0x80000000;
  hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &updatedSections, 4);
  v69 = 0;
  updatedSections.m_data[updatedSections.m_size++] = v68;
  if ( array.m_size > 0 )
  {
    v70 = 0i64;
    do
    {
      v71 = v54->m_streamingCollection.m_pntr;
      LOBYTE(v86) = 0;
      hkaiUserEdgeUtils::removeUserEdgesFromFace(v71, array.m_data[v70], (hkaiUserEdgeUtils::RemoveParameters *)&v86);
      ++v69;
      ++v70;
    }
    while ( v69 < array.m_size );
    v68 = sectionIndexa;
  }
  hkaiNavMeshCutter::removeCutFacesFromOriginals(v54, &updatedSections, &array, EXIT_IF_NO_FACES_TO_REMOVE);
  v72 = v54->m_forceRecutFaceKeys.m_size - 1;
  for ( j = v72; j >= 0; --j )
  {
    if ( v54->m_forceRecutFaceKeys.m_data[j] >> 22 == v68 )
    {
      v74 = --v54->m_forceRecutFaceKeys.m_size;
      if ( (_DWORD)v74 != v72 )
        v54->m_forceRecutFaceKeys.m_data[j] = v54->m_forceRecutFaceKeys.m_data[v74];
    }
    --v72;
  }
  v75 = v54->m_forceClearanceCalcFaceKeys.m_size - 1;
  for ( k = v75; k >= 0; --k )
  {
    if ( v54->m_forceClearanceCalcFaceKeys.m_data[k] >> 22 == v68 )
    {
      v77 = --v54->m_forceClearanceCalcFaceKeys.m_size;
      if ( (_DWORD)v77 != v75 )
        v54->m_forceClearanceCalcFaceKeys.m_data[k] = v54->m_forceClearanceCalcFaceKeys.m_data[v77];
    }
    --v75;
  }
  hkaiNavMeshCutter::MeshInfo::init(v9, 0i64);
  updatedSections.m_size = 0;
  if ( updatedSections.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      updatedSections.m_data,
      4 * updatedSections.m_capacityAndFlags);
  updatedSections.m_data = 0i64;
  updatedSections.m_capacityAndFlags = 0x80000000;
  v81.m_elem.m_size = 0;
  if ( v81.m_elem.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v81.m_elem.m_data,
      4 * v81.m_elem.m_capacityAndFlags);
  v81.m_elem.m_data = 0i64;
  v81.m_elem.m_capacityAndFlags = 0x80000000;
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      4 * array.m_capacityAndFlags);
}

// File Line: 1001
// RVA: 0xBEE800
__int64 __fastcall hkaiNavMeshCutter::getOriginalNumberOfFaces(hkaiNavMeshCutter *this, int sectionIdx)
{
  return (unsigned int)this->m_meshInfos.m_data[sectionIdx].m_originalNumFaces;
}

// File Line: 1006
// RVA: 0xBF1160
_BOOL8 __fastcall hkaiNavMeshCutter::doEdgesMatch(hkaiNavMeshCutter *this, unsigned int keyA, unsigned int keyB)
{
  hkSimdFloat32 result; // [rsp+30h] [rbp-18h] BYREF

  return COERCE_FLOAT(*hkaiNavMeshCutterHelper::edgeEndpointDistance(
                         &result,
                         this->m_streamingCollection.m_pntr->m_instances.m_data[keyA >> 22].m_instancePtr,
                         this->m_streamingCollection.m_pntr->m_instances.m_data[keyB >> 22].m_instancePtr,
                         &this->m_up,
                         keyA & 0x3FFFFF,
                         keyB & 0x3FFFFF)) < this->m_cutEdgeTolerance;
}

// File Line: 1018
// RVA: 0xBF2750
_BOOL8 __fastcall AabbCompare(hkAabb *first, hkAabb *second)
{
  return _mm_shuffle_ps(first->m_min.m_quad, first->m_min.m_quad, 0).m128_f32[0] < _mm_shuffle_ps(
                                                                                     second->m_min.m_quad,
                                                                                     second->m_min.m_quad,
                                                                                     0).m128_f32[0];
}

// File Line: 1024
// RVA: 0xBF2780
void __fastcall simpleAabbMerge(hkArrayBase<hkAabb> *aabbs)
{
  int m_size; // r8d
  int v3; // r9d
  __int64 v4; // r10
  __int64 v5; // rcx
  __int64 v6; // r11
  __m128 *v7; // rdx
  __m128 *v8; // r8
  __m128 v9; // xmm1
  __int64 v10; // rdx
  char *v11; // rax
  char *v12; // r8
  __int64 v13; // rcx

  m_size = aabbs->m_size;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkAabb,unsigned int (*)(hkAabb const &,hkAabb const &)>(
      aabbs->m_data,
      0,
      m_size - 1,
      (unsigned int (__fastcall *)(hkAabb *, hkAabb *))AabbCompare);
  v3 = aabbs->m_size - 1;
  v4 = v3;
  if ( v3 >= 1i64 )
  {
    v5 = 32i64 * v3;
    do
    {
      v6 = v5 - 32;
      v7 = (__m128 *)((char *)&aabbs->m_data[-1].m_min.m_quad + v5);
      v8 = (__m128 *)((char *)&aabbs->m_data->m_min.m_quad + v5);
      if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(*v7, v8[1]), _mm_cmple_ps(*v8, v7[1]))) & 7) == 7 )
      {
        v9 = v7[1];
        *v7 = _mm_min_ps(*v7, *v8);
        v7[1] = _mm_max_ps(v9, v8[1]);
        if ( --aabbs->m_size != v3 )
        {
          v10 = 4i64;
          v11 = (char *)aabbs->m_data + v5;
          v12 = (char *)((char *)&aabbs->m_data[aabbs->m_size] - v11);
          do
          {
            v13 = *(_QWORD *)&v11[(_QWORD)v12];
            v11 += 8;
            *((_QWORD *)v11 - 1) = v13;
            --v10;
          }
          while ( v10 );
        }
      }
      --v3;
      v5 = v6;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 1038
// RVA: 0xBF11E0
void __fastcall hkaiNavMeshCutter::getFacesForResetByMediator(
        hkaiNavMeshCutter *this,
        hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *facesToReset,
        hkArrayBase<hkAabb> *faceAabbs)
{
  hkArrayBase<hkAabb> *v3; // rbx
  hkArrayBase<hkAabb> *v5; // rbx
  _QWORD *Value; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r9
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  int v12; // r15d
  __int64 v13; // r12
  __m128 v14; // xmm6
  hkAabb *m_data; // rax
  hkVector4f v16; // xmm1
  int v17; // r14d
  __int64 v18; // rsi
  unsigned int v19; // ebx
  int v20; // r8d
  unsigned int *v21; // r9
  int v22; // r8d
  int v23; // r10d
  int v24; // ecx
  unsigned int v25; // edx
  unsigned int OriginalFromCutKey; // ebx
  int v27; // r8d
  unsigned int *v28; // r9
  int v29; // r8d
  int v30; // r10d
  int v31; // eax
  unsigned int v32; // edx
  _QWORD *v33; // rax
  _QWORD *v34; // rcx
  _QWORD *v35; // r8
  unsigned __int64 v36; // rax
  _QWORD *v37; // rcx
  hkArray<unsigned int,hkContainerTempAllocator> hits; // [rsp+18h] [rbp-79h] BYREF
  hkaiNavMeshQueryMediator::AabbQueryInput input; // [rsp+28h] [rbp-69h] BYREF
  hkaiDynamicNavMeshQueryMediator v40; // [rsp+78h] [rbp-19h] BYREF
  void *retaddr; // [rsp+F8h] [rbp+67h] BYREF
  hkArrayBase<hkAabb> *v42; // [rsp+108h] [rbp+77h]
  hkArrayBase<hkAabb> *result; // [rsp+110h] [rbp+7Fh] BYREF

  result = faceAabbs;
  v42 = v3;
  v5 = faceAabbs;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)Value[1];
  v9 = Value;
  if ( (unsigned __int64)v8 < Value[3] )
  {
    *v8 = "Ttmediator";
    v10 = __rdtsc();
    v11 = v8 + 2;
    *((_DWORD *)v11 - 2) = v10;
    v9[1] = v11;
  }
  hkaiDynamicNavMeshQueryMediator::hkaiDynamicNavMeshQueryMediator(
    &v40,
    this->m_streamingCollection.m_pntr,
    this->m_streamingCollection.m_pntr->m_tree.m_pntr,
    this);
  v12 = 0;
  if ( v5->m_size > 0 )
  {
    v13 = 0i64;
    v14 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      m_data = v5->m_data;
      input.m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
      input.m_filterInfo = 0;
      memset(&input.m_userData, 0, 32);
      input.m_aabb.m_max.m_quad = _mm_xor_ps(v14, (__m128)xmmword_141A712A0);
      input.m_aabb.m_min = m_data[v13].m_min;
      v16.m_quad = (__m128)m_data[v13].m_max;
      hits.m_size = 0;
      hits.m_capacityAndFlags = 0x80000000;
      input.m_aabb.m_max = (hkVector4f)v16.m_quad;
      hkaiDynamicNavMeshQueryMediator::queryAabb(&v40, &input, &hits);
      v17 = 0;
      if ( hits.m_size > 0 )
      {
        v18 = 0i64;
        do
        {
          v19 = hits.m_data[v18];
          v20 = facesToReset->m_elem.m_size - 1;
          if ( 2 * facesToReset->m_numElems > v20 )
            hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
              facesToReset,
              (hkResult *)&retaddr,
              2 * v20 + 2);
          v21 = facesToReset->m_elem.m_data;
          v22 = facesToReset->m_elem.m_size - 1;
          v23 = 1;
          v24 = v22 & (-1640531535 * (v19 >> 4));
          v25 = facesToReset->m_elem.m_data[v24];
          if ( v25 != -1 )
          {
            while ( v25 != v19 )
            {
              v24 = v22 & (v24 + 1);
              v25 = v21[v24];
              if ( v25 == -1 )
                goto LABEL_14;
            }
            v23 = 0;
          }
LABEL_14:
          facesToReset->m_numElems += v23;
          v21[v24] = v19;
          OriginalFromCutKey = hkaiNavMeshCutter::getOriginalFromCutKey(this, hits.m_data[v18]);
          if ( OriginalFromCutKey != -1 )
          {
            v27 = facesToReset->m_elem.m_size - 1;
            if ( 2 * facesToReset->m_numElems > v27 )
              hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
                facesToReset,
                (hkResult *)&result,
                2 * v27 + 2);
            v28 = facesToReset->m_elem.m_data;
            v29 = facesToReset->m_elem.m_size - 1;
            v30 = 1;
            v31 = v29 & (-1640531535 * (OriginalFromCutKey >> 4));
            v32 = facesToReset->m_elem.m_data[v31];
            if ( v32 != -1 )
            {
              while ( v32 != OriginalFromCutKey )
              {
                v31 = v29 & (v31 + 1);
                v32 = v28[v31];
                if ( v32 == -1 )
                  goto LABEL_22;
              }
              v30 = 0;
            }
LABEL_22:
            facesToReset->m_numElems += v30;
            v28[v31] = OriginalFromCutKey;
          }
          ++v17;
          ++v18;
        }
        while ( v17 < hits.m_size );
        v5 = v42;
      }
      hits.m_size = 0;
      if ( hits.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          hits.m_data,
          4 * hits.m_capacityAndFlags);
      ++v12;
      ++v13;
      hits.m_data = 0i64;
      hits.m_capacityAndFlags = 0x80000000;
    }
    while ( v12 < v5->m_size );
  }
  hkaiDynamicNavMeshQueryMediator::~hkaiDynamicNavMeshQueryMediator(&v40);
  v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v34 = (_QWORD *)v33[1];
  v35 = v33;
  if ( (unsigned __int64)v34 < v33[3] )
  {
    *v34 = "Et";
    v36 = __rdtsc();
    v37 = v34 + 2;
    *((_DWORD *)v37 - 2) = v36;
    v35[1] = v37;
  }
}

// File Line: 1065
// RVA: 0xBF1530
void __fastcall hkaiNavMeshCutter::getFacesForResetByFloodFill(
        hkaiNavMeshCutter *this,
        hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *facesToReset,
        hkArrayBase<unsigned int> *cutFaceKeys,
        hkArrayBase<hkAabb> *faceAabbs)
{
  hkaiNavMeshCutter *v4; // rdi
  hkArrayBase<hkAabb> *v5; // rsi
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *v7; // r15
  _QWORD *Value; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  int m_size; // edx
  __int64 v13; // r10
  unsigned int *m_data; // r8
  _DWORD *v15; // r9
  __int64 v16; // rcx
  bool v17; // zf
  unsigned int v18; // eax
  unsigned int *v19; // r9
  unsigned int v20; // r13d
  int v21; // r8d
  int v22; // ecx
  unsigned int v23; // edx
  int v24; // eax
  __int64 m_instancePtr; // rbx
  int v26; // r10d
  int v27; // r11d
  int v28; // ecx
  unsigned int v29; // edx
  int v30; // r14d
  __int64 v31; // r8
  __int64 v32; // rdx
  __m128 *p_m_quad; // rcx
  int m_numElems; // r9d
  int v35; // r10d
  int v36; // r10d
  int v37; // r11d
  int v38; // ecx
  unsigned int v39; // edx
  _DWORD *v40; // rsi
  __int64 v41; // rdi
  int v42; // r8d
  unsigned int v43; // ebx
  unsigned int *v44; // r9
  int v45; // r8d
  int v46; // r10d
  int v47; // ecx
  unsigned int v48; // edx
  int v49; // r8d
  unsigned int *v50; // r9
  int v51; // r8d
  int v52; // r10d
  int v53; // ecx
  unsigned int v54; // edx
  unsigned int *v55; // rdi
  __int64 v56; // r12
  int *v57; // r15
  __int64 v58; // r14
  int v59; // r9d
  __int64 v60; // rsi
  __int64 v61; // rcx
  int v62; // edx
  unsigned int v63; // eax
  unsigned int v64; // ebx
  int v65; // r8d
  int v66; // ecx
  unsigned int v67; // edx
  int v68; // eax
  int v69; // edx
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > **v70; // rax
  char *v71; // rax
  int v72; // r14d
  int v73; // r15d
  int v74; // r8d
  __int64 v75; // rcx
  hkArray<int,hkContainerHeapAllocator> *v76; // rdx
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v77; // r8
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v78; // r10
  int v79; // r11d
  hkaiNavMesh::Face *v80; // r13
  int index; // r12d
  hkArray<int,hkContainerHeapAllocator> *v82; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v83; // rcx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v84; // rdx
  hkaiNavMesh::Edge *v85; // rax
  unsigned int m_oppositeFace; // edx
  unsigned int OriginalFromCutKey; // eax
  int v88; // r8d
  unsigned int v89; // ebx
  int v90; // edx
  unsigned int v91; // eax
  int v92; // eax
  int v93; // r9d
  int v94; // ecx
  int v95; // edx
  int v96; // r9d
  int v97; // ecx
  __int64 i; // rax
  int v99; // ebx
  int v100; // r8d
  int v101; // edi
  int v102; // edx
  int v103; // r9d
  __int64 v104; // rcx
  int v105; // r9d
  int v106; // r10d
  int v107; // ecx
  unsigned int v108; // edx
  _QWORD *v109; // r8
  _QWORD *v110; // rcx
  unsigned __int64 v111; // rax
  _QWORD *v112; // rcx
  hkAabb *instanceMap; // [rsp+20h] [rbp-D8h]
  _DWORD *array; // [rsp+30h] [rbp-C8h] BYREF
  int v115; // [rsp+38h] [rbp-C0h]
  int v116; // [rsp+3Ch] [rbp-BCh]
  char v117; // [rsp+40h] [rbp-B8h] BYREF
  char v118; // [rsp+41h] [rbp-B7h] BYREF
  char v119; // [rsp+42h] [rbp-B6h] BYREF
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > v120; // [rsp+48h] [rbp-B0h] BYREF
  __int64 v121; // [rsp+60h] [rbp-98h]
  int v122; // [rsp+68h] [rbp-90h]
  hkArray<unsigned int,hkContainerHeapAllocator> cutOut; // [rsp+70h] [rbp-88h] BYREF
  int v124; // [rsp+80h] [rbp-78h]
  int v125; // [rsp+84h] [rbp-74h]
  hkSimdFloat32 extraRadius; // [rsp+88h] [rbp-70h] BYREF
  __m128 v127; // [rsp+98h] [rbp-60h]
  unsigned int v128; // [rsp+A8h] [rbp-50h]
  unsigned int v129; // [rsp+ACh] [rbp-4Ch]
  __int64 v130; // [rsp+B0h] [rbp-48h]
  hkResult v131; // [rsp+B8h] [rbp-40h] BYREF
  hkResult v132; // [rsp+BCh] [rbp-3Ch] BYREF
  hkResult result; // [rsp+C0h] [rbp-38h] BYREF
  hkResult v134; // [rsp+C4h] [rbp-34h] BYREF
  hkResult v135; // [rsp+C8h] [rbp-30h] BYREF
  hkResult v136; // [rsp+CCh] [rbp-2Ch] BYREF
  __m128 faceIndex[2]; // [rsp+D8h] [rbp-20h] BYREF
  hkaiNavMeshCutter *retaddr; // [rsp+138h] [rbp+40h]
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *v140; // [rsp+148h] [rbp+50h] BYREF
  hkArrayBase<hkAabb> *v141; // [rsp+150h] [rbp+58h]
  hkArrayBase<hkAabb> *v142; // [rsp+158h] [rbp+60h]

  v142 = faceAabbs;
  v140 = facesToReset;
  v4 = this;
  v5 = faceAabbs;
  v7 = facesToReset;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "Ttfloodfill";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  m_size = cutFaceKeys->m_size;
  array = 0i64;
  v115 = 0;
  v116 = 0x80000000;
  v120.m_elem.m_data = 0i64;
  v120.m_elem.m_size = 0;
  v120.m_elem.m_capacityAndFlags = 0x80000000;
  v120.m_numElems = 0;
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::reserve(&v120, 4 * m_size);
  if ( cutFaceKeys->m_size > 0 )
  {
    LODWORD(v140) = 4 * cutFaceKeys->m_size;
    array = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v140);
    v116 = (int)v140 / 4;
  }
  v13 = cutFaceKeys->m_size;
  m_data = cutFaceKeys->m_data;
  v15 = array;
  v16 = 0i64;
  v115 = v13;
  v17 = (_DWORD)v13 == 0;
  if ( (int)v13 > 0 )
  {
    do
    {
      v18 = m_data[v16++];
      v15[v16 - 1] = v18;
    }
    while ( v16 < v13 );
    LODWORD(v13) = v115;
    v17 = v115 == 0;
  }
  v19 = v120.m_elem.m_data;
  if ( !v17 )
  {
    do
    {
      v20 = array[(int)v13 - 1];
      LODWORD(v13) = v13 - 1;
      v21 = v120.m_elem.m_size - 1;
      v128 = v20;
      v115 = v13;
      if ( v120.m_elem.m_size - 1 <= 0 || (v22 = v21 & (-1640531535 * (v20 >> 4)), v23 = v19[v22], v23 == -1) )
      {
LABEL_13:
        v24 = v120.m_elem.m_size;
      }
      else
      {
        while ( v23 != v20 )
        {
          v22 = v21 & (v22 + 1);
          v23 = v19[v22];
          if ( v23 == -1 )
            goto LABEL_13;
        }
        v24 = v22;
      }
      if ( v24 > v21 )
      {
        m_instancePtr = (__int64)v4->m_streamingCollection.m_pntr->m_instances.m_data[v20 >> 22].m_instancePtr;
        v121 = m_instancePtr;
        if ( m_instancePtr )
        {
          v30 = v20 & 0x3FFFFF;
          faceIndex[0] = 0i64;
          hkaiNavMeshUtils::calcFaceAabb<hkaiNavMeshInstance>(
            (hkaiNavMeshUtils *)m_instancePtr,
            (hkaiNavMeshInstance *)(v20 & 0x3FFFFF),
            faceIndex,
            &extraRadius,
            instanceMap);
          v31 = v5->m_size;
          v32 = 0i64;
          if ( v31 <= 0 )
          {
LABEL_29:
            m_numElems = v120.m_numElems;
            v35 = v120.m_elem.m_size;
            if ( 2 * v120.m_numElems > v120.m_elem.m_size - 1 )
            {
              hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
                &v120,
                &v132,
                2 * v120.m_elem.m_size);
              m_numElems = v120.m_numElems;
              v35 = v120.m_elem.m_size;
            }
            v36 = v35 - 1;
            v37 = 1;
            v38 = v36 & (-1640531535 * (v20 >> 4));
            v39 = v120.m_elem.m_data[v38];
            if ( v39 != -1 )
            {
              while ( v39 != v20 )
              {
                v38 = v36 & (v38 + 1);
                v39 = v120.m_elem.m_data[v38];
                if ( v39 == -1 )
                  goto LABEL_138;
              }
              v37 = 0;
            }
LABEL_138:
            v120.m_numElems = v37 + m_numElems;
            v120.m_elem.m_data[v38] = v20;
          }
          else
          {
            p_m_quad = &v5->m_data->m_min.m_quad;
            while ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(extraRadius.m_real, p_m_quad[1]), _mm_cmple_ps(*p_m_quad, v127))) & 7) != 7 )
            {
              ++v32;
              p_m_quad += 2;
              if ( v32 >= v31 )
                goto LABEL_29;
            }
            v40 = 0i64;
            cutOut.m_capacityAndFlags = 0x80000000;
            cutOut.m_data = 0i64;
            cutOut.m_size = 0;
            if ( (unsigned int)hkaiNavMeshCutter::getCutKeysFromOriginal(v4, v20, &cutOut) && cutOut.m_size > 0 )
            {
              v41 = 0i64;
              do
              {
                v42 = v7->m_elem.m_size;
                v43 = cutOut.m_data[v41];
                if ( 2 * v7->m_numElems > v42 - 1 )
                  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
                    v7,
                    &v136,
                    2 * v42);
                v44 = v7->m_elem.m_data;
                v45 = v7->m_elem.m_size - 1;
                v46 = 1;
                v47 = v45 & (-1640531535 * (v43 >> 4));
                v48 = v7->m_elem.m_data[v47];
                if ( v48 != -1 )
                {
                  while ( v48 != v43 )
                  {
                    v47 = v45 & (v47 + 1);
                    v48 = v44[v47];
                    if ( v48 == -1 )
                      goto LABEL_45;
                  }
                  v46 = 0;
                }
LABEL_45:
                v7->m_numElems += v46;
                LODWORD(v40) = (_DWORD)v40 + 1;
                v44[v47] = v43;
                ++v41;
              }
              while ( (int)v40 < cutOut.m_size );
              m_instancePtr = v121;
              v40 = 0i64;
            }
            v49 = v7->m_elem.m_size;
            if ( 2 * v7->m_numElems > v49 - 1 )
              hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
                v7,
                &v135,
                2 * v49);
            v50 = v7->m_elem.m_data;
            v51 = v7->m_elem.m_size - 1;
            v52 = 1;
            v53 = (-1640531535 * (v20 >> 4)) & v51;
            v129 = -1640531535 * (v20 >> 4);
            v54 = v50[v53];
            if ( v54 != -1 )
            {
              while ( v54 != v20 )
              {
                v53 = v51 & (v53 + 1);
                v54 = v50[v53];
                if ( v54 == -1 )
                  goto LABEL_54;
              }
              v52 = 0;
            }
LABEL_54:
            v7->m_numElems += v52;
            v50[v53] = v20;
            cutOut.m_size = 0;
            if ( cutOut.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                cutOut.m_data,
                4 * cutOut.m_capacityAndFlags);
            v55 = v120.m_elem.m_data;
            v56 = v30;
            cutOut.m_data = 0i64;
            cutOut.m_capacityAndFlags = 0x80000000;
            v57 = (int *)(*(_QWORD *)(m_instancePtr + 16) + 16i64 * v30);
            v58 = *v57;
            if ( (int)v58 < (int)v58 + *((__int16 *)v57 + 4) )
            {
              v59 = v115;
              v60 = 20 * v58;
              do
              {
                v61 = *(_QWORD *)(m_instancePtr + 32);
                v62 = *(_DWORD *)(v60 + v61 + 12);
                if ( (*(_BYTE *)(v60 + v61 + 16) & 0x40) != 0 )
                  v63 = v62 & 0xFFC00000;
                else
                  v63 = *(_DWORD *)(m_instancePtr + 472) << 22;
                v64 = v63 | v62 & 0x3FFFFF;
                if ( v62 == -1 )
                  v64 = -1;
                if ( *(_DWORD *)(v60 + v61 + 8) != -1 )
                {
                  v65 = v120.m_elem.m_size - 1;
                  if ( v120.m_elem.m_size - 1 <= 0
                    || (v66 = v65 & (-1640531535 * (v64 >> 4)), v67 = v55[v66], v67 == -1) )
                  {
LABEL_68:
                    v68 = v120.m_elem.m_size;
                  }
                  else
                  {
                    while ( v67 != v64 )
                    {
                      v66 = v65 & (v66 + 1);
                      v67 = v55[v66];
                      if ( v67 == -1 )
                        goto LABEL_68;
                    }
                    v68 = v66;
                  }
                  if ( v68 > v65 )
                  {
                    if ( v59 == (v116 & 0x3FFFFFFF) )
                    {
                      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 4);
                      v59 = v115;
                    }
                    array[v59] = v64;
                    v55 = v120.m_elem.m_data;
                    v59 = ++v115;
                  }
                }
                m_instancePtr = v121;
                LODWORD(v58) = v58 + 1;
                v60 += 20i64;
              }
              while ( (int)v58 < *v57 + *((__int16 *)v57 + 4) );
              v40 = 0i64;
            }
            v69 = *(_DWORD *)(m_instancePtr + 328);
            if ( v69 )
            {
              v70 = &v140;
              LOBYTE(v140) = *(_BYTE *)(v56 + *(_QWORD *)(m_instancePtr + 320));
            }
            else
            {
              v117 = 0;
              v70 = (hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > **)&v117;
            }
            if ( (*(_BYTE *)v70 & 4) != 0 )
            {
              if ( v69 )
              {
                v71 = &v119;
                v119 = *(_BYTE *)(v56 + *(_QWORD *)(m_instancePtr + 320));
              }
              else
              {
                v118 = 0;
                v71 = &v118;
              }
              if ( (*v71 & 1) != 0 )
              {
                *(_QWORD *)&cutOut.m_size = 0i64;
                v124 = 0;
                v125 = 0x80000000;
                hkaiNavMeshCutter::getCutKeysFromOriginal(
                  retaddr,
                  v20,
                  (hkArray<unsigned int,hkContainerHeapAllocator> *)&cutOut.m_size);
                v55 = v120.m_elem.m_data;
                v72 = 0;
                v73 = 0;
                v74 = 0x80000000;
                extraRadius.m_real.m128_u64[0] = 0i64;
                extraRadius.m_real.m128_u64[1] = 0x8000000000000000ui64;
                v127.m128_i32[0] = 0;
                v122 = 0;
                if ( v124 > 0 )
                {
                  v75 = 0i64;
                  v76 = (hkArray<int,hkContainerHeapAllocator> *)(m_instancePtr + 224);
                  v77 = (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(m_instancePtr + 272);
                  v130 = 0i64;
                  v78 = (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(m_instancePtr + 240);
                  do
                  {
                    v80 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
                            *(hkaiNavMesh::Face **)(m_instancePtr + 16),
                            *(_DWORD *)(m_instancePtr + 24),
                            v78,
                            v77,
                            v76,
                            *(_DWORD *)(*(_QWORD *)&cutOut.m_size + v75) & 0x3FFFFF);
                    index = v80->m_startEdgeIndex;
                    if ( index < index + v80->m_numEdges )
                    {
                      v82 = (hkArray<int,hkContainerHeapAllocator> *)(m_instancePtr + 208);
                      v83 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(m_instancePtr + 288);
                      v84 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(m_instancePtr + 256);
                      do
                      {
                        v85 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__8(
                                *(hkaiNavMesh::Edge **)(m_instancePtr + 32),
                                *(_DWORD *)(m_instancePtr + 40),
                                v84,
                                v83,
                                v82,
                                index);
                        if ( (v85->m_flags.m_storage & 0x40) != 0 && v85->m_oppositeEdge != -1 )
                        {
                          m_oppositeFace = v85->m_oppositeFace;
                          if ( m_oppositeFace == -1 )
                            m_oppositeFace = -1;
                          OriginalFromCutKey = hkaiNavMeshCutter::getOriginalFromCutKey(retaddr, m_oppositeFace);
                          v88 = v120.m_elem.m_size - 1;
                          v89 = OriginalFromCutKey;
                          if ( v120.m_elem.m_size - 1 <= 0
                            || (v90 = v88 & (-1640531535 * (OriginalFromCutKey >> 4)), v91 = v55[v90], v91 == -1) )
                          {
LABEL_96:
                            v92 = v120.m_elem.m_size;
                          }
                          else
                          {
                            while ( v91 != v89 )
                            {
                              v90 = v88 & (v90 + 1);
                              v91 = v55[v90];
                              if ( v91 == -1 )
                                goto LABEL_96;
                            }
                            v92 = v90;
                          }
                          if ( v92 > v88 )
                          {
                            if ( 2 * v73 > v72 - 1 )
                            {
                              hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int>>::resizeTable(
                                (hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > *)&extraRadius,
                                &v131,
                                2 * v72);
                              v73 = v127.m128_i32[0];
                              v72 = extraRadius.m_real.m128_i32[2];
                              v40 = (_DWORD *)extraRadius.m_real.m128_u64[0];
                            }
                            v93 = 1;
                            v94 = (v72 - 1) & (-1640531535 * (v89 >> 4));
                            v95 = v40[v94];
                            if ( v95 != -1 )
                            {
                              while ( v95 != v89 )
                              {
                                v94 = (v72 - 1) & (v94 + 1);
                                v95 = v40[v94];
                                if ( v95 == -1 )
                                  goto LABEL_106;
                              }
                              v93 = 0;
                            }
LABEL_106:
                            v127.m128_i32[0] = v93 + v73;
                            v40[v94] = v89;
                            v55 = v120.m_elem.m_data;
                            v73 = v127.m128_i32[0];
                            v72 = extraRadius.m_real.m128_i32[2];
                            v40 = (_DWORD *)extraRadius.m_real.m128_u64[0];
                          }
                          m_instancePtr = v121;
                        }
                        ++index;
                        v83 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(m_instancePtr + 288);
                        v84 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(m_instancePtr + 256);
                        v82 = (hkArray<int,hkContainerHeapAllocator> *)(m_instancePtr + 208);
                      }
                      while ( index < v80->m_startEdgeIndex + v80->m_numEdges );
                      v79 = v124;
                    }
                    v76 = (hkArray<int,hkContainerHeapAllocator> *)(m_instancePtr + 224);
                    v75 = v130 + 4;
                    v77 = (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(m_instancePtr + 272);
                    ++v122;
                    v130 += 4i64;
                    v78 = (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(m_instancePtr + 240);
                  }
                  while ( v122 < v79 );
                  v74 = extraRadius.m_real.m128_i32[3];
                  v20 = v128;
                }
                v96 = v72 - 1;
                v97 = 0;
                for ( i = 0i64; i <= v96; ++v97 )
                {
                  if ( v40[i] != -1 )
                    break;
                  ++i;
                }
                v99 = v97;
                if ( v97 <= v96 )
                {
                  v100 = v115;
                  do
                  {
                    v101 = v40[v99];
                    if ( v100 == (v116 & 0x3FFFFFFF) )
                    {
                      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 4);
                      v100 = v115;
                    }
                    v102 = v99 + 1;
                    array[v100] = v101;
                    v40 = (_DWORD *)extraRadius.m_real.m128_u64[0];
                    v103 = extraRadius.m_real.m128_i32[2] - 1;
                    v100 = v115 + 1;
                    v104 = v99 + 1;
                    ++v115;
                    if ( v104 <= extraRadius.m_real.m128_i32[2] - 1 )
                    {
                      do
                      {
                        if ( *(_DWORD *)(extraRadius.m_real.m128_u64[0] + 4 * v104) != -1 )
                          break;
                        ++v104;
                        ++v102;
                      }
                      while ( v104 <= v103 );
                    }
                    v99 = v102;
                  }
                  while ( v102 <= v103 );
                  v55 = v120.m_elem.m_data;
                  v74 = extraRadius.m_real.m128_i32[3];
                }
                extraRadius.m_real.m128_i32[2] = 0;
                if ( v74 >= 0 )
                {
                  hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v40, 4 * v74);
                  v55 = v120.m_elem.m_data;
                }
                extraRadius.m_real.m128_i32[3] = 0x80000000;
                extraRadius.m_real.m128_u64[0] = 0i64;
                v124 = 0;
                if ( v125 >= 0 )
                {
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    &hkContainerHeapAllocator::s_alloc,
                    *(void **)&cutOut.m_size,
                    4 * v125);
                  v55 = v120.m_elem.m_data;
                }
                *(_QWORD *)&cutOut.m_size = 0i64;
                v125 = 0x80000000;
              }
            }
            v105 = v120.m_numElems;
            if ( 2 * v120.m_numElems > v120.m_elem.m_size - 1 )
            {
              hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
                &v120,
                &v134,
                2 * v120.m_elem.m_size);
              v105 = v120.m_numElems;
              v55 = v120.m_elem.m_data;
            }
            v106 = 1;
            v107 = v129 & (v120.m_elem.m_size - 1);
            v108 = v55[v107];
            if ( v108 != -1 )
            {
              while ( v108 != v20 )
              {
                v107 = (v120.m_elem.m_size - 1) & (v107 + 1);
                v108 = v55[v107];
                if ( v108 == -1 )
                  goto LABEL_136;
              }
              v106 = 0;
            }
LABEL_136:
            v7 = (hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *)this;
            v5 = v141;
            v120.m_numElems = v106 + v105;
            v55[v107] = v20;
            v4 = retaddr;
          }
        }
        else
        {
          v26 = v120.m_numElems;
          if ( 2 * v120.m_numElems > v21 )
          {
            hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
              &v120,
              &result,
              2 * v120.m_elem.m_size);
            v26 = v120.m_numElems;
            v19 = v120.m_elem.m_data;
          }
          v27 = 1;
          v28 = (v120.m_elem.m_size - 1) & (-1640531535 * (v20 >> 4));
          v29 = v19[v28];
          if ( v29 != -1 )
          {
            while ( v29 != v20 )
            {
              v28 = (v120.m_elem.m_size - 1) & (v28 + 1);
              v29 = v19[v28];
              if ( v29 == -1 )
              {
                v120.m_numElems = v26 + 1;
                v19[v28] = v20;
                goto LABEL_139;
              }
            }
            v27 = 0;
          }
          v120.m_numElems = v27 + v26;
          v19[v28] = v20;
        }
LABEL_139:
        LODWORD(v13) = v115;
        v19 = v120.m_elem.m_data;
      }
    }
    while ( (_DWORD)v13 );
  }
  v120.m_elem.m_size = 0;
  if ( v120.m_elem.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v19,
      4 * v120.m_elem.m_capacityAndFlags);
  v120.m_elem.m_data = 0i64;
  v120.m_elem.m_capacityAndFlags = 0x80000000;
  v115 = 0;
  if ( v116 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _DWORD *, _QWORD, unsigned int *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      array,
      (unsigned int)(4 * v116),
      v19);
  array = 0i64;
  v116 = 0x80000000;
  v109 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v110 = (_QWORD *)v109[1];
  if ( (unsigned __int64)v110 < v109[3] )
  {
    *v110 = "Et";
    v111 = __rdtsc();
    v112 = v110 + 2;
    *((_DWORD *)v112 - 2) = v111;
    v109[1] = v112;
  }
}

// File Line: 1196
// RVA: 0xBEF910
void __fastcall hkaiNavMeshCutter::resetClearanceForCutFaces(
        hkaiNavMeshCutter *this,
        hkArrayBase<int> *updatedSections,
        hkArrayBase<unsigned int> *cutFaceKeys)
{
  __m128 v3; // xmm2
  int m_size; // r14d
  int v8; // edi
  hkLifoAllocator *Value; // rax
  unsigned int *m_cur; // rcx
  int v11; // edx
  char *v12; // r8
  int v13; // r9d
  int v14; // eax
  unsigned int *m_data; // rdi
  __int64 i; // rcx
  int v17; // r8d
  __int64 v18; // r9
  __int64 v19; // rcx
  int v20; // r14d
  __int64 v21; // r15
  hkaiStreamingCollection *m_pntr; // rdx
  hkaiNavMeshInstance *m_instancePtr; // rbx
  int m_capacityAndFlags; // eax
  int v25; // r9d
  unsigned int *v26; // rdi
  __int64 v27; // rdx
  unsigned int *v28; // r9
  __int64 v29; // rcx
  unsigned int v30; // eax
  __int64 v31; // rcx
  unsigned int *v32; // rdi
  int v33; // r8d
  int v34; // edi
  _QWORD *v35; // rdi
  _QWORD *v36; // rcx
  unsigned __int64 v37; // rax
  _QWORD *v38; // rcx
  float v39; // xmm6_4
  int v40; // r14d
  __int64 v41; // rbx
  __int64 v42; // r15
  unsigned int v43; // eax
  hkaiNavMeshInstance *v44; // rdi
  hkAabb *v45; // rax
  float v46; // xmm6_4
  int v47; // edx
  __int64 v48; // rcx
  __m128 v49; // xmm2
  hkAabb *v50; // rax
  __m128 v51; // xmm1
  _QWORD *v52; // rdi
  _QWORD *v53; // rcx
  unsigned __int64 v54; // rax
  _QWORD *v55; // rcx
  char m_storage; // al
  unsigned int *v57; // rdi
  int v58; // edx
  int v59; // r8d
  __int64 j; // rcx
  int v61; // ebx
  int v62; // r8d
  int v63; // edx
  __int64 v64; // rcx
  hkAabb *sizeElem; // [rsp+20h] [rbp-99h]
  hkArrayBase<unsigned int> cutFaceKeysa; // [rsp+30h] [rbp-89h] BYREF
  hkArrayBase<hkAabb> aabbs; // [rsp+40h] [rbp-79h] BYREF
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > facesToReset; // [rsp+50h] [rbp-69h] BYREF
  hkBitFieldStorage<hkLocalArray<unsigned int> > array; // [rsp+68h] [rbp-51h] BYREF
  int faceIndex[4]; // [rsp+90h] [rbp-29h] BYREF
  hkSimdFloat32 extraRadius; // [rsp+A0h] [rbp-19h] BYREF
  hkVector4f v72; // [rsp+B0h] [rbp-9h]
  hkResult result; // [rsp+120h] [rbp+67h] BYREF
  float m_maxGlobalClearance; // [rsp+128h] [rbp+6Fh]

  m_size = this->m_streamingCollection.m_pntr->m_instances.m_size;
  array.m_words.m_data = 0i64;
  array.m_words.m_size = 0;
  v8 = (m_size + 31) >> 5;
  array.m_words.m_capacityAndFlags = 0x80000000;
  array.m_words.m_initialCapacity = v8;
  if ( v8 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (unsigned int *)Value->m_cur;
    v11 = (4 * v8 + 127) & 0xFFFFFF80;
    v12 = (char *)m_cur + v11;
    if ( v11 > Value->m_slabSize || v12 > Value->m_end )
      m_cur = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(Value, v11);
    else
      Value->m_cur = v12;
  }
  else
  {
    m_cur = 0i64;
  }
  array.m_words.m_data = m_cur;
  array.m_words.m_localMemory = m_cur;
  array.m_numBits = m_size;
  array.m_words.m_capacityAndFlags = v8 | 0x80000000;
  if ( (v8 & 0x3FFFFFFF) < v8 )
  {
    v13 = (m_size + 31) >> 5;
    if ( v8 < 2 * (v8 & 0x3FFFFFFF) )
      v13 = 2 * (v8 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array, v13, 4);
  }
  v14 = v8 - 1;
  array.m_words.m_size = (m_size + 31) >> 5;
  if ( v8 - 1 >= 0 )
  {
    m_data = array.m_words.m_data;
    for ( i = (unsigned int)(v14 + 1); i; --i )
      *m_data++ = 0;
  }
  v17 = 0;
  if ( updatedSections->m_size > 0 )
  {
    v18 = 0i64;
    do
    {
      ++v17;
      v19 = updatedSections->m_data[v18++];
      array.m_words.m_data[v19 >> 5] |= 1 << (v19 & 0x1F);
    }
    while ( v17 < updatedSections->m_size );
  }
  v20 = 0;
  if ( this->m_streamingCollection.m_pntr->m_instances.m_size > 0 )
  {
    v21 = 0i64;
    do
    {
      m_pntr = this->m_streamingCollection.m_pntr;
      m_instancePtr = m_pntr->m_instances.m_data[v21].m_instancePtr;
      if ( m_instancePtr )
      {
        if ( ((array.m_words.m_data[(__int64)v20 >> 5] >> (v20 & 0x1F)) & 1) == 0 )
        {
          hkaiNavMeshUtils::compactOwnedEdges(m_instancePtr, m_pntr);
          hkaiNavMeshUtils::compactOwnedVertices(m_instancePtr);
        }
        if ( m_instancePtr->m_clearanceCache.m_size > 0 || m_instancePtr->m_globalClearanceCache.m_size > 0 )
        {
          if ( this->m_clearanceResetMethod.m_storage )
          {
            hkaiNavMeshUtils::compactClearanceCache(m_instancePtr);
            hkaiNavMeshInstance::initGlobalClearanceCache(m_instancePtr);
          }
          else
          {
            hkaiNavMeshInstance::initClearanceCache(m_instancePtr);
            hkaiNavMeshInstance::resetVertexClearances(m_instancePtr);
            if ( this->m_recomputeClearanceAfterCutting.m_bool )
              hkaiNavMeshCutter::recomputeDirtyGlobalClearances(this, m_instancePtr);
            this->m_forceClearanceCalcFaceKeys.m_size = 0;
          }
        }
      }
      ++v20;
      ++v21;
    }
    while ( v20 < this->m_streamingCollection.m_pntr->m_instances.m_size );
  }
  if ( this->m_clearanceResetMethod.m_storage )
  {
    m_capacityAndFlags = 0x80000000;
    v25 = cutFaceKeys->m_size + this->m_forceClearanceCalcFaceKeys.m_size;
    v26 = 0i64;
    cutFaceKeysa.m_data = 0i64;
    cutFaceKeysa.m_size = 0;
    cutFaceKeysa.m_capacityAndFlags = 0x80000000;
    if ( v25 > 0 )
    {
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &cutFaceKeysa, v25, 4);
      m_capacityAndFlags = cutFaceKeysa.m_capacityAndFlags;
      v26 = cutFaceKeysa.m_data;
    }
    if ( (m_capacityAndFlags & 0x3FFFFFFF) < cutFaceKeys->m_size )
    {
      if ( m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          v26,
          4 * m_capacityAndFlags);
      result.m_enum = 4 * cutFaceKeys->m_size;
      v26 = (unsigned int *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                              &hkContainerTempAllocator::s_alloc,
                              &result);
      cutFaceKeysa.m_data = v26;
      cutFaceKeysa.m_capacityAndFlags = result.m_enum / 4;
    }
    v27 = cutFaceKeys->m_size;
    v28 = cutFaceKeys->m_data;
    v29 = 0i64;
    cutFaceKeysa.m_size = v27;
    if ( (int)v27 > 0 )
    {
      do
      {
        v30 = v28[v29++];
        v26[v29 - 1] = v30;
      }
      while ( v29 < v27 );
      LODWORD(v27) = cutFaceKeysa.m_size;
    }
    if ( this->m_forceClearanceCalcFaceKeys.m_size )
    {
      hkArrayBase<unsigned int>::_append(
        &cutFaceKeysa,
        &hkContainerTempAllocator::s_alloc,
        (char *)this->m_forceClearanceCalcFaceKeys.m_data,
        this->m_forceClearanceCalcFaceKeys.m_size);
      LODWORD(v27) = cutFaceKeysa.m_size;
      if ( cutFaceKeysa.m_size > 1 )
      {
        hkAlgorithm::quickSortRecursive<unsigned int,hkAlgorithm::less<unsigned int>>(
          cutFaceKeysa.m_data,
          0,
          cutFaceKeysa.m_size - 1,
          0);
        LODWORD(v27) = cutFaceKeysa.m_size;
      }
      v31 = (int)v27 - 2;
      if ( (int)v27 - 2 >= 0 )
      {
        v32 = cutFaceKeysa.m_data;
        v33 = v27 - 2 + 1;
        do
        {
          if ( v32[v31] == v32[v31 + 1] )
          {
            LODWORD(v27) = v27 - 1;
            cutFaceKeysa.m_size = v27;
            if ( (_DWORD)v27 != v33 )
            {
              v32[v31 + 1] = v32[(int)v27];
              LODWORD(v27) = cutFaceKeysa.m_size;
              v32 = cutFaceKeysa.m_data;
            }
          }
          --v33;
          --v31;
        }
        while ( v31 >= 0 );
      }
      this->m_forceClearanceCalcFaceKeys.m_size = 0;
    }
    facesToReset.m_elem.m_data = 0i64;
    facesToReset.m_elem.m_size = 0;
    facesToReset.m_elem.m_capacityAndFlags = 0x80000000;
    facesToReset.m_numElems = 0;
    hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::reserve(&facesToReset, 4 * v27);
    v34 = cutFaceKeysa.m_size;
    aabbs.m_data = 0i64;
    aabbs.m_size = 0;
    aabbs.m_capacityAndFlags = 0x80000000;
    if ( cutFaceKeysa.m_size > 0 )
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &aabbs, cutFaceKeysa.m_size, 32);
    aabbs.m_size = v34;
    v35 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v36 = (_QWORD *)v35[1];
    if ( (unsigned __int64)v36 < v35[3] )
    {
      *v36 = "Ttaabbs";
      v37 = __rdtsc();
      v38 = v36 + 2;
      *((_DWORD *)v38 - 2) = v37;
      v35[1] = v38;
    }
    v39 = 0.0;
    v40 = 0;
    if ( cutFaceKeysa.m_size > 0 )
    {
      v41 = 0i64;
      v42 = 0i64;
      do
      {
        *(_OWORD *)faceIndex = 0i64;
        v43 = cutFaceKeysa.m_data[v42];
        v44 = this->m_streamingCollection.m_pntr->m_instances.m_data[v43 >> 22].m_instancePtr;
        hkaiNavMeshUtils::calcFaceAabb<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)v44,
          (hkaiNavMeshInstance *)(v43 & 0x3FFFFF),
          (__m128 *)faceIndex,
          &extraRadius,
          sizeElem);
        v45 = aabbs.m_data;
        ++v40;
        result.m_enum = LODWORD(v39);
        ++v42;
        aabbs.m_data[v41++].m_min = (hkVector4f)extraRadius.m_real;
        v45[v41 - 1].m_max = (hkVector4f)v72.m_quad;
        m_maxGlobalClearance = v44->m_maxGlobalClearance;
        v39 = fmaxf(v39, m_maxGlobalClearance);
      }
      while ( v40 < cutFaceKeysa.m_size );
    }
    v46 = v39 * 2.0;
    simpleAabbMerge(&aabbs);
    v47 = 0;
    if ( aabbs.m_size > 0 )
    {
      v3.m128_f32[0] = v46;
      v48 = 0i64;
      v49 = _mm_shuffle_ps(v3, v3, 0);
      do
      {
        v50 = aabbs.m_data;
        ++v47;
        v51 = _mm_sub_ps(aabbs.m_data[v48++].m_min.m_quad, v49);
        aabbs.m_data[v48 - 1].m_max.m_quad = _mm_add_ps(v49, aabbs.m_data[v48 - 1].m_max.m_quad);
        v50[v48 - 1].m_min.m_quad = v51;
      }
      while ( v47 < aabbs.m_size );
    }
    v52 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v53 = (_QWORD *)v52[1];
    if ( (unsigned __int64)v53 < v52[3] )
    {
      *v53 = "Et";
      v54 = __rdtsc();
      v55 = v53 + 2;
      *((_DWORD *)v55 - 2) = v54;
      v52[1] = v55;
    }
    m_storage = this->m_clearanceResetMethod.m_storage;
    if ( m_storage == 1 )
    {
      hkaiNavMeshCutter::getFacesForResetByMediator(this, &facesToReset, &aabbs);
    }
    else if ( m_storage == 2 )
    {
      hkaiNavMeshCutter::getFacesForResetByFloodFill(this, &facesToReset, &cutFaceKeysa, &aabbs);
    }
    if ( this->m_recomputeClearanceAfterCutting.m_bool )
    {
      hkaiNavMeshCutter::recomputeGlobalClearancesForFaces(this, &facesToReset);
      v57 = facesToReset.m_elem.m_data;
    }
    else
    {
      v57 = facesToReset.m_elem.m_data;
      v58 = 0;
      v59 = facesToReset.m_elem.m_size - 1;
      for ( j = 0i64; j <= v59; ++v58 )
      {
        if ( facesToReset.m_elem.m_data[j] != -1 )
          break;
        ++j;
      }
      v61 = v58;
      if ( v58 <= v59 )
      {
        do
        {
          hkaiNavMeshTraversalUtils::resetClearanceForFace(
            this->m_streamingCollection.m_pntr->m_instances.m_data[v57[v61] >> 22].m_instancePtr,
            v57[v61] & 0x3FFFFF,
            1,
            1);
          v57 = facesToReset.m_elem.m_data;
          v62 = facesToReset.m_elem.m_size - 1;
          v63 = v61 + 1;
          v64 = v61 + 1;
          if ( v64 <= facesToReset.m_elem.m_size - 1 )
          {
            do
            {
              if ( facesToReset.m_elem.m_data[v64] != -1 )
                break;
              ++v64;
              ++v63;
            }
            while ( v64 <= v62 );
          }
          v61 = v63;
        }
        while ( v63 <= v62 );
      }
    }
    aabbs.m_size = 0;
    if ( aabbs.m_capacityAndFlags >= 0 )
    {
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        aabbs.m_data,
        32 * aabbs.m_capacityAndFlags);
      v57 = facesToReset.m_elem.m_data;
    }
    aabbs.m_data = 0i64;
    aabbs.m_capacityAndFlags = 0x80000000;
    facesToReset.m_elem.m_size = 0;
    if ( facesToReset.m_elem.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v57,
        4 * facesToReset.m_elem.m_capacityAndFlags);
    facesToReset.m_elem.m_data = 0i64;
    facesToReset.m_elem.m_capacityAndFlags = 0x80000000;
    cutFaceKeysa.m_size = 0;
    if ( cutFaceKeysa.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        cutFaceKeysa.m_data,
        4 * cutFaceKeysa.m_capacityAndFlags);
  }
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>(&array);
}

// File Line: 1336
// RVA: 0xBF0260
void __fastcall hkaiNavMeshCutter::recomputeGlobalClearancesForFaces(
        hkaiNavMeshCutter *this,
        hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *facesToReset)
{
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *v2; // rbx
  hkaiStreamingCollection *m_pntr; // rdx
  hkaiNavMeshCutter *v4; // rsi
  int m_capacityAndFlags; // r8d
  int v6; // r11d
  unsigned int *v7; // r9
  int v8; // edx
  __int64 v9; // rcx
  unsigned int *m_data; // rax
  int v11; // r15d
  unsigned int v12; // ebx
  hkaiNavMeshInstance *m_instancePtr; // rdi
  int index; // ebx
  hkaiNavMesh::Face *v15; // rax
  int m_startEdgeIndex; // esi
  int v17; // r14d
  hkaiNavMesh::Edge *v18; // rax
  int m_numElems; // r10d
  int m_size; // edx
  unsigned int v21; // ebx
  int v22; // r9d
  int v23; // r11d
  int v24; // eax
  unsigned int v25; // edx
  int v26; // r8d
  __int64 v27; // rcx
  int v28; // r11d
  unsigned int *v29; // rdx
  int v30; // edx
  int v31; // r10d
  __int64 i; // rcx
  int v33; // edi
  unsigned int v34; // ebx
  hkaiNavMeshInstance *v35; // rsi
  int v36; // ebx
  int v37; // edx
  int v38; // r8d
  __int64 v39; // rcx
  hkSimdFloat32 instanceMap; // [rsp+20h] [rbp-59h] BYREF
  hkVector4f up; // [rsp+30h] [rbp-49h] BYREF
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > v42; // [rsp+40h] [rbp-39h] BYREF
  hkaiDynamicNavMeshQueryMediator v43; // [rsp+58h] [rbp-21h] BYREF
  hkaiNavMeshCutter *vars0; // [rsp+E0h] [rbp+67h]
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *retaddr; // [rsp+E8h] [rbp+6Fh]
  hkaiNavMeshCutter *result; // [rsp+F0h] [rbp+77h] BYREF
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *v47; // [rsp+F8h] [rbp+7Fh]

  v47 = facesToReset;
  result = this;
  v2 = facesToReset;
  m_pntr = this->m_streamingCollection.m_pntr;
  up.m_quad = (__m128)this->m_up;
  v4 = this;
  hkaiDynamicNavMeshQueryMediator::hkaiDynamicNavMeshQueryMediator(&v43, m_pntr, m_pntr->m_tree.m_pntr, this);
  m_capacityAndFlags = 0x80000000;
  v6 = v2->m_elem.m_size - 1;
  v7 = 0i64;
  v42.m_elem.m_data = 0i64;
  v42.m_elem.m_size = 0;
  v42.m_numElems = 0;
  v42.m_elem.m_capacityAndFlags = 0x80000000;
  v8 = 0;
  v9 = 0i64;
  if ( v6 >= 0 )
  {
    m_data = v2->m_elem.m_data;
    do
    {
      if ( *m_data != -1 )
        break;
      ++v9;
      ++v8;
      ++m_data;
    }
    while ( v9 <= v6 );
  }
  v11 = v8;
  v47 = (hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *)v8;
  if ( v8 <= v6 )
  {
    do
    {
      v12 = v2->m_elem.m_data[v11];
      m_instancePtr = v4->m_streamingCollection.m_pntr->m_instances.m_data[v12 >> 22].m_instancePtr;
      if ( m_instancePtr )
      {
        index = v12 & 0x3FFFFF;
        hkaiNavMeshTraversalUtils::resetClearanceForFace(m_instancePtr, index, 1, 0);
        v15 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
                m_instancePtr->m_originalFaces,
                m_instancePtr->m_numOriginalFaces,
                &m_instancePtr->m_instancedFaces,
                &m_instancePtr->m_ownedFaces,
                &m_instancePtr->m_faceMap,
                index);
        m_startEdgeIndex = v15->m_startEdgeIndex;
        instanceMap.m_real.m128_i32[1] = v15->m_startUserEdgeIndex;
        instanceMap.m_real.m128_u64[1] = *(_QWORD *)&v15->m_numEdges;
        v17 = m_startEdgeIndex + instanceMap.m_real.m128_i16[4];
        if ( m_startEdgeIndex < v17 )
        {
          do
          {
            v18 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__8(
                    m_instancePtr->m_originalEdges,
                    m_instancePtr->m_numOriginalEdges,
                    &m_instancePtr->m_instancedEdges,
                    &m_instancePtr->m_ownedEdges,
                    &m_instancePtr->m_edgeMap,
                    m_startEdgeIndex);
            if ( v18->m_oppositeEdge == -1 || (v18->m_flags.m_storage & 0x20) != 0 )
            {
              m_instancePtr->m_globalClearanceCache.m_data[v18->m_a].m_value = -16512;
              m_instancePtr->m_globalClearanceCache.m_data[v18->m_b].m_value = -16512;
            }
            else
            {
              m_numElems = v42.m_numElems;
              m_size = v42.m_elem.m_size;
              v21 = v18->m_a | (m_instancePtr->m_runtimeId << 22);
              if ( 2 * v42.m_numElems > v42.m_elem.m_size - 1 )
              {
                hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
                  &v42,
                  (hkResult *)&result,
                  2 * v42.m_elem.m_size);
                m_numElems = v42.m_numElems;
                m_size = v42.m_elem.m_size;
              }
              v22 = m_size - 1;
              v23 = 1;
              v24 = (m_size - 1) & (-1640531535 * (v21 >> 4));
              v25 = v42.m_elem.m_data[v24];
              if ( v25 != -1 )
              {
                while ( v25 != v21 )
                {
                  v24 = v22 & (v24 + 1);
                  v25 = v42.m_elem.m_data[v24];
                  if ( v25 == -1 )
                  {
                    v42.m_numElems = m_numElems + 1;
                    v42.m_elem.m_data[v24] = v21;
                    goto LABEL_19;
                  }
                }
                v23 = 0;
              }
              v42.m_numElems = v23 + m_numElems;
              v42.m_elem.m_data[v24] = v21;
            }
LABEL_19:
            ++m_startEdgeIndex;
          }
          while ( m_startEdgeIndex < v17 );
          v11 = (int)v47;
        }
        v4 = vars0;
        v7 = v42.m_elem.m_data;
      }
      v2 = retaddr;
      v26 = v11 + 1;
      v27 = v11 + 1;
      v28 = retaddr->m_elem.m_size - 1;
      if ( v27 <= v28 )
      {
        v29 = &retaddr->m_elem.m_data[v26];
        do
        {
          if ( *v29 != -1 )
            break;
          ++v27;
          ++v26;
          ++v29;
        }
        while ( v27 <= v28 );
      }
      v11 = v26;
      v47 = (hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *)v26;
    }
    while ( v26 <= v28 );
    m_capacityAndFlags = v42.m_elem.m_capacityAndFlags;
  }
  v30 = 0;
  v31 = v42.m_elem.m_size - 1;
  for ( i = 0i64; i <= v31; ++v30 )
  {
    if ( v7[i] != -1 )
      break;
    ++i;
  }
  v33 = v30;
  if ( v30 <= v31 )
  {
    do
    {
      v34 = v7[v33];
      v35 = v4->m_streamingCollection.m_pntr->m_instances.m_data[v34 >> 22].m_instancePtr;
      if ( v35 )
      {
        v36 = v34 & 0x3FFFFF;
        if ( v35->m_globalClearanceCache.m_data[v36].m_value != -16512 )
        {
          hkaiNavMeshTraversalUtils::computeGlobalClearance(&instanceMap, v35, &v43, v36, &up);
          hkaiNavMeshTraversalUtils::updateGlobalClearance(v35, v36, &instanceMap);
          v7 = v42.m_elem.m_data;
        }
      }
      v37 = v33 + 1;
      v38 = v42.m_elem.m_size - 1;
      v39 = v33 + 1;
      if ( v39 <= v42.m_elem.m_size - 1 )
      {
        do
        {
          if ( v7[v39] != -1 )
            break;
          ++v39;
          ++v37;
        }
        while ( v39 <= v38 );
      }
      v4 = vars0;
      v33 = v37;
    }
    while ( v37 <= v38 );
    m_capacityAndFlags = v42.m_elem.m_capacityAndFlags;
  }
  v42.m_elem.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v7, 4 * m_capacityAndFlags);
  v42.m_elem.m_data = 0i64;
  v42.m_elem.m_capacityAndFlags = 0x80000000;
  hkaiDynamicNavMeshQueryMediator::~hkaiDynamicNavMeshQueryMediator(&v43);
}

// File Line: 1427
// RVA: 0xBF0010
void __fastcall hkaiNavMeshCutter::recomputeDirtyGlobalClearances(
        hkaiNavMeshCutter *this,
        hkaiNavMeshInstance *meshInstance)
{
  hkaiStreamingCollection *m_pntr; // rdx
  int m_numOriginalFaces; // edx
  int v5; // esi
  int index; // ebp
  __int64 i; // r15
  unsigned int *v8; // rax
  int v9; // edi
  hkaiNavMesh::Face *v10; // r14
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_ownedEdges; // r9
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_instancedEdges; // r8
  hkaiNavMesh::Edge *v13; // rax
  int v14; // eax
  float v15; // xmm6_4
  __int64 v16; // rdi
  hkVector4f up; // [rsp+30h] [rbp-98h] BYREF
  hkSimdFloat32 result; // [rsp+40h] [rbp-88h] BYREF
  hkaiDynamicNavMeshQueryMediator worldMediator; // [rsp+50h] [rbp-78h] BYREF
  unsigned int m_maxGlobalClearance_low; // [rsp+D0h] [rbp+8h] BYREF
  char v21; // [rsp+D8h] [rbp+10h] BYREF

  m_pntr = this->m_streamingCollection.m_pntr;
  up.m_quad = (__m128)this->m_up;
  hkaiDynamicNavMeshQueryMediator::hkaiDynamicNavMeshQueryMediator(&worldMediator, m_pntr, m_pntr->m_tree.m_pntr, this);
  m_numOriginalFaces = meshInstance->m_numOriginalFaces;
  v5 = 0;
  index = 0;
  for ( i = 0i64; index < m_numOriginalFaces + meshInstance->m_ownedFaces.m_size; ++i )
  {
    if ( meshInstance->m_faceFlags.m_size )
    {
      v8 = &m_maxGlobalClearance_low;
      LOBYTE(m_maxGlobalClearance_low) = meshInstance->m_faceFlags.m_data[i].m_storage;
    }
    else
    {
      v21 = 0;
      v8 = (unsigned int *)&v21;
    }
    if ( (*(_BYTE *)v8 & 1) == 0 )
    {
      v9 = 0;
      v10 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
              meshInstance->m_originalFaces,
              m_numOriginalFaces,
              &meshInstance->m_instancedFaces,
              &meshInstance->m_ownedFaces,
              &meshInstance->m_faceMap,
              index);
      if ( v10->m_numEdges > 0 )
      {
        p_m_ownedEdges = &meshInstance->m_ownedEdges;
        p_m_instancedEdges = &meshInstance->m_instancedEdges;
        do
        {
          v13 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__8(
                  meshInstance->m_originalEdges,
                  meshInstance->m_numOriginalEdges,
                  p_m_instancedEdges,
                  p_m_ownedEdges,
                  &meshInstance->m_edgeMap,
                  v9 + v10->m_startEdgeIndex);
          if ( v13->m_oppositeEdge == -1 || (v13->m_flags.m_storage & 0x20) != 0 )
          {
            meshInstance->m_globalClearanceCache.m_data[v13->m_a].m_value = -16512;
            meshInstance->m_globalClearanceCache.m_data[v13->m_b].m_value = -16512;
          }
          ++v9;
        }
        while ( v9 < v10->m_numEdges );
      }
    }
    m_numOriginalFaces = meshInstance->m_numOriginalFaces;
    ++index;
  }
  v14 = meshInstance->m_ownedVertices.m_size + meshInstance->m_numOriginalVertices;
  m_maxGlobalClearance_low = LODWORD(meshInstance->m_maxGlobalClearance);
  LODWORD(v15) = _mm_shuffle_ps((__m128)m_maxGlobalClearance_low, (__m128)m_maxGlobalClearance_low, 0).m128_u32[0];
  if ( v14 > 0 )
  {
    v16 = 0i64;
    do
    {
      m_maxGlobalClearance_low = meshInstance->m_globalClearanceCache.m_data[v16].m_value << 16;
      if ( _mm_shuffle_ps((__m128)m_maxGlobalClearance_low, (__m128)m_maxGlobalClearance_low, 0).m128_f32[0] > v15 )
      {
        hkaiNavMeshTraversalUtils::computeGlobalClearance(&result, meshInstance, &worldMediator, v5, &up);
        hkaiNavMeshTraversalUtils::updateGlobalClearance(meshInstance, v5, &result);
      }
      ++v5;
      ++v16;
    }
    while ( v5 < meshInstance->m_ownedVertices.m_size + meshInstance->m_numOriginalVertices );
  }
  hkaiDynamicNavMeshQueryMediator::~hkaiDynamicNavMeshQueryMediator(&worldMediator);
}

// File Line: 1472
// RVA: 0xBEF5C0
void __fastcall hkaiNavMeshCutter::mergeCutBoundaryEdges(
        hkaiNavMeshCutter *this,
        unsigned int originalFaceKey,
        unsigned int originalEdgeKey)
{
  __int64 v3; // r14
  int index; // esi
  hkaiNavMeshInstance *m_instancePtr; // r11
  int m_numOriginalFaces; // edi
  hkaiNavMeshCutter::MeshInfo *v9; // r14
  __int64 v10; // r11
  hkaiNavMesh::Face *v11; // r13
  int v12; // eax
  __int64 v13; // rdi
  __int64 v14; // rbp
  __int64 v15; // rbx
  char m_storage; // [rsp+68h] [rbp+10h]

  v3 = originalEdgeKey >> 22;
  index = originalFaceKey & 0x3FFFFF;
  m_instancePtr = this->m_streamingCollection.m_pntr->m_instances.m_data[v3].m_instancePtr;
  if ( m_instancePtr->m_faceFlags.m_size )
    m_storage = m_instancePtr->m_faceFlags.m_data[index].m_storage;
  else
    m_storage = 0;
  m_numOriginalFaces = m_instancePtr->m_numOriginalFaces;
  v9 = &this->m_meshInfos.m_data[v3];
  v11 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
          m_instancePtr->m_originalFaces,
          m_numOriginalFaces,
          &m_instancePtr->m_instancedFaces,
          &m_instancePtr->m_ownedFaces,
          &m_instancePtr->m_faceMap,
          index);
  if ( (m_storage & 1) != 0 )
  {
    v12 = m_numOriginalFaces + *(_DWORD *)(v10 + 280);
    v13 = v9->m_magic.m_data[index];
    if ( (int)v13 >= 0 )
    {
      v14 = v12;
      v15 = v9->m_magic.m_data[index];
      if ( v13 < v12 )
      {
        do
        {
          if ( v9->m_magic.m_data[v15] != index )
            break;
          hkaiNavMeshCutterHelper::mergeContiguousBoundaryEdges(
            this->m_streamingCollection.m_pntr,
            v11,
            originalEdgeKey,
            v13);
          ++v15;
          LODWORD(v13) = v13 + 1;
        }
        while ( v15 < v14 );
      }
    }
  }
}

// File Line: 1507
// RVA: 0xBEE820
__int64 __fastcall hkaiNavMeshCutter::getClosestPointOnFaceLocal(
        hkaiNavMeshCutter *this,
        hkVector4f *position,
        unsigned int faceKey,
        hkVector4f *closestPointOut)
{
  __int64 v5; // rsi
  int v7; // r8d
  hkaiNavMeshInstance *m_instancePtr; // r14
  __m128 m_quad; // xmm6
  float v12; // xmm7_4
  unsigned int v13; // edi
  int v14; // ebx
  int v15; // ebp
  __m128 v16; // xmm1
  __m128 v17; // xmm1
  float v18; // xmm2_4
  hkVector4f closestPointOuta; // [rsp+20h] [rbp-58h] BYREF
  int faceEndOut; // [rsp+80h] [rbp+8h] BYREF
  int faceStartOut; // [rsp+90h] [rbp+18h] BYREF

  v5 = faceKey >> 22;
  v7 = faceKey & 0x3FFFFF;
  m_instancePtr = this->m_streamingCollection.m_pntr->m_instances.m_data[v5].m_instancePtr;
  if ( m_instancePtr->m_faceFlags.m_size )
    LOBYTE(faceStartOut) = m_instancePtr->m_faceFlags.m_data[v7].m_storage;
  else
    LOBYTE(faceStartOut) = 0;
  if ( (faceStartOut & 1) != 0 )
  {
    m_quad = closestPointOut->m_quad;
    v12 = 3.40282e38;
    v13 = -1;
    faceStartOut = -1;
    faceEndOut = -1;
    hkaiNavMeshCutter::getCutKeyRangeFromOriginal(this, faceKey, &faceStartOut, &faceEndOut);
    v14 = faceStartOut;
    if ( faceStartOut != -1 )
    {
      v15 = faceEndOut;
      if ( faceStartOut <= faceEndOut )
      {
        do
        {
          hkaiNavMeshUtils::getClosestPointOnFaceLocal(m_instancePtr, position, v14, &closestPointOuta);
          v16 = _mm_sub_ps(closestPointOuta.m_quad, position->m_quad);
          v17 = _mm_mul_ps(v16, v16);
          v18 = (float)(_mm_shuffle_ps(v17, v17, 85).m128_f32[0] + _mm_shuffle_ps(v17, v17, 0).m128_f32[0])
              + _mm_shuffle_ps(v17, v17, 170).m128_f32[0];
          if ( v18 < v12 )
          {
            v12 = v18;
            m_quad = closestPointOuta.m_quad;
            v13 = v14 | ((_DWORD)v5 << 22);
          }
          ++v14;
        }
        while ( v14 <= v15 );
      }
    }
    *closestPointOut = (hkVector4f)m_quad;
    return v13;
  }
  else
  {
    hkaiNavMeshUtils::getClosestPointOnFace(m_instancePtr->m_originalMesh.m_pntr, position, v7, closestPointOut);
    return faceKey;
  }
}

// File Line: 1554
// RVA: 0xBEE9B0
__int64 __fastcall hkaiNavMeshCutter::getClosestBoundaryOnFaceLocal(
        hkaiNavMeshCutter *this,
        hkVector4f *position,
        unsigned int faceKey,
        hkVector4f *up,
        hkVector4f *closestPointOut)
{
  __int64 v6; // rbp
  int v8; // r8d
  hkaiNavMeshInstance *m_instancePtr; // r14
  int ClosestBoundaryOnFace; // eax
  unsigned int v12; // ebx
  hkVector4f *v13; // r13
  __m128 v14; // xmm7
  __m128 m_quad; // xmm6
  int v16; // edi
  int v17; // esi
  int ClosestBoundaryOnFaceLocal; // eax
  __m128 v19; // xmm0
  hkVector4f v21; // [rsp+30h] [rbp-68h] BYREF
  int faceEndOut; // [rsp+A0h] [rbp+8h] BYREF
  int faceStartOut; // [rsp+B0h] [rbp+18h] BYREF

  v6 = faceKey >> 22;
  v8 = faceKey & 0x3FFFFF;
  m_instancePtr = this->m_streamingCollection.m_pntr->m_instances.m_data[v6].m_instancePtr;
  if ( m_instancePtr->m_faceFlags.m_size )
    LOBYTE(faceStartOut) = m_instancePtr->m_faceFlags.m_data[v8].m_storage;
  else
    LOBYTE(faceStartOut) = 0;
  if ( (faceStartOut & 1) != 0 )
  {
    v13 = closestPointOut;
    v14 = (__m128)xmmword_141A712A0;
    m_quad = closestPointOut->m_quad;
    v12 = -1;
    faceStartOut = -1;
    faceEndOut = -1;
    hkaiNavMeshCutter::getCutKeyRangeFromOriginal(this, faceKey, &faceStartOut, &faceEndOut);
    v16 = faceStartOut;
    if ( faceStartOut != -1 )
    {
      v17 = faceEndOut;
      if ( faceStartOut <= faceEndOut )
      {
        do
        {
          ClosestBoundaryOnFaceLocal = hkaiNavMeshUtils::getClosestBoundaryOnFaceLocal(
                                         m_instancePtr,
                                         position,
                                         v16,
                                         up,
                                         &v21);
          v19 = _mm_shuffle_ps(v21.m_quad, v21.m_quad, 255);
          if ( v19.m128_f32[0] < v14.m128_f32[0] )
          {
            v14 = v19;
            m_quad = v21.m_quad;
            v12 = ClosestBoundaryOnFaceLocal | ((_DWORD)v6 << 22);
          }
          ++v16;
        }
        while ( v16 <= v17 );
      }
    }
    v13->m_quad = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, v14), 196);
  }
  else
  {
    ClosestBoundaryOnFace = hkaiNavMeshUtils::getClosestBoundaryOnFace(
                              m_instancePtr->m_originalMesh.m_pntr,
                              position,
                              v8,
                              up,
                              closestPointOut);
    if ( ClosestBoundaryOnFace == -1 )
      return (unsigned int)-1;
    else
      return (unsigned int)ClosestBoundaryOnFace | ((_DWORD)v6 << 22);
  }
  return v12;
}

// File Line: 1601
// RVA: 0xBF0680
void __fastcall hkaiNavMeshCutter::makePersistentFaceKey(
        hkaiNavMeshCutter *this,
        unsigned int key,
        hkaiPersistentFaceKey *persistentFaceKeyOut)
{
  unsigned int OriginalFromCutKey; // eax
  unsigned int v7; // esi
  int FirstCutKeyFromOriginal; // eax

  OriginalFromCutKey = hkaiNavMeshCutter::getOriginalFromCutKey(this, key);
  v7 = OriginalFromCutKey;
  if ( OriginalFromCutKey == -1 )
  {
    persistentFaceKeyOut->m_key = key;
LABEL_3:
    persistentFaceKeyOut->m_offset = -1;
    return;
  }
  FirstCutKeyFromOriginal = hkaiNavMeshCutter::getFirstCutKeyFromOriginal(this, OriginalFromCutKey);
  persistentFaceKeyOut->m_key = v7;
  if ( FirstCutKeyFromOriginal == -1 )
    goto LABEL_3;
  persistentFaceKeyOut->m_offset = key - FirstCutKeyFromOriginal;
}

// File Line: 1633
// RVA: 0xBF07E0
void __fastcall hkaiNavMeshCutter::makePersistentFaceKey(
        hkaiNavMeshCutter *cutter,
        unsigned int key,
        hkaiPersistentFaceKey *persistentFaceKeyOut)
{
  if ( cutter )
  {
    hkaiNavMeshCutter::makePersistentFaceKey(cutter, key, persistentFaceKeyOut);
  }
  else
  {
    persistentFaceKeyOut->m_key = key;
    persistentFaceKeyOut->m_offset = -1;
  }
}

// File Line: 1646
// RVA: 0xBF06F0
void __fastcall hkaiNavMeshCutter::makePersistentEdgeKey(
        hkaiNavMeshCutter *this,
        unsigned int edgeKey,
        unsigned int faceKey,
        hkaiPersistentEdgeKey *persistentEdgeKeyOut)
{
  hkaiStreamingCollection::InstanceInfo *m_data; // r10
  hkaiGeneralAccessor accessor; // [rsp+30h] [rbp-28h] BYREF

  m_data = this->m_streamingCollection.m_pntr->m_instances.m_data;
  accessor.m_currentSection = -1;
  accessor.m_accessor = 0i64;
  accessor.m_sectionInfo = m_data;
  hkaiNavMeshCutter::makePersistentEdgeKey(this, &accessor, edgeKey, faceKey, persistentEdgeKeyOut);
}

// File Line: 1652
// RVA: 0xBF0800
void __fastcall hkaiNavMeshCutter::makePersistentEdgeKey(
        hkaiNavMeshCutter *cutter,
        hkaiGeneralAccessor *accessor,
        __int16 edgeKey,
        unsigned int faceKey,
        hkaiPersistentEdgeKey *persistentEdgeKeyOut)
{
  hkaiNavMeshCutter::makePersistentFaceKey(cutter, faceKey, &persistentEdgeKeyOut->m_faceKey);
  persistentEdgeKeyOut->m_edgeOffset = edgeKey
                                     - LOWORD(hkaiGeneralAccessor::getFaceFromPacked(accessor, faceKey)->m_startEdgeIndex);
}

// File Line: 1675
// RVA: 0xBF0740
__int64 __fastcall hkaiNavMeshCutter::resolvePersistentFaceKey(
        hkaiNavMeshCutter *this,
        hkaiPersistentFaceKey *persistentFaceKey)
{
  __int16 m_offset; // si
  unsigned int m_key; // ebx
  int v5; // eax
  int faceStartOut; // [rsp+38h] [rbp+10h] BYREF
  int faceEndOut; // [rsp+40h] [rbp+18h] BYREF

  m_offset = persistentFaceKey->m_offset;
  m_key = persistentFaceKey->m_key;
  if ( (m_offset != -1) != hkaiNavMeshCutter::getCutKeyRangeFromOriginal(
                             this,
                             persistentFaceKey->m_key,
                             &faceStartOut,
                             &faceEndOut) )
    return 0xFFFFFFFFi64;
  if ( m_offset == -1 )
    return m_key;
  if ( faceStartOut == -1 )
    return 0xFFFFFFFFi64;
  v5 = faceStartOut + m_offset;
  if ( v5 > faceEndOut )
    return 0xFFFFFFFFi64;
  return m_key & 0xFFC00000 | v5;
}

// File Line: 1707
// RVA: 0xBF0860
__int64 __fastcall hkaiNavMeshCutter::resolvePersistentFaceKey(
        hkaiNavMeshCutter *cutter,
        hkaiPersistentFaceKey *persistentFaceKey)
{
  if ( cutter )
    return hkaiNavMeshCutter::resolvePersistentFaceKey(cutter, persistentFaceKey);
  else
    return persistentFaceKey->m_key;
}

// File Line: 1720
// RVA: 0xBF0880
unsigned int __fastcall hkaiNavMeshCutter::resolvePersistentEdgeKey(
        hkaiNavMeshCutter *cutter,
        hkaiGeneralAccessor *accessor,
        hkaiPersistentEdgeKey *persistentEdgeKey)
{
  unsigned int faceKeyOut; // [rsp+48h] [rbp+20h] BYREF

  return hkaiNavMeshCutter::resolvePersistentEdgeKey(cutter, accessor, persistentEdgeKey, &faceKeyOut);
}

// File Line: 1727
// RVA: 0xBF08A0
__int64 __fastcall hkaiNavMeshCutter::resolvePersistentEdgeKey(
        hkaiNavMeshCutter *cutter,
        hkaiGeneralAccessor *accessor,
        hkaiPersistentEdgeKey *persistentEdgeKey,
        unsigned int *faceKeyOut)
{
  unsigned int v7; // eax
  unsigned int v8; // ebx
  hkaiNavMesh::Face *FaceFromPacked; // rax
  __int16 m_edgeOffset; // cx

  v7 = hkaiNavMeshCutter::resolvePersistentFaceKey(cutter, &persistentEdgeKey->m_faceKey);
  v8 = v7;
  *faceKeyOut = v7;
  if ( v7 == -1 )
    return 0xFFFFFFFFi64;
  FaceFromPacked = hkaiGeneralAccessor::getFaceFromPacked(accessor, v7);
  m_edgeOffset = persistentEdgeKey->m_edgeOffset;
  if ( m_edgeOffset == -1 )
    return 0xFFFFFFFFi64;
  if ( m_edgeOffset >= FaceFromPacked->m_numEdges )
  {
    *faceKeyOut = -1;
    return 0xFFFFFFFFi64;
  }
  return v8 & 0xFFC00000 | (FaceFromPacked->m_startEdgeIndex + m_edgeOffset);
}


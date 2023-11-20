// File Line: 46
// RVA: 0xBED730
void __fastcall hkaiNavMeshCutter::hkaiNavMeshCutter(hkaiNavMeshCutter *this)
{
  hkaiNavMeshCutter *v1; // rbx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshCutter::`vftable;
  this->m_meshInfos.m_data = 0i64;
  this->m_meshInfos.m_size = 0;
  this->m_meshInfos.m_capacityAndFlags = 2147483648;
  v1 = this;
  hkaiNavMeshCutter::SavedConnectivity::SavedConnectivity(&this->m_connectivityInfo);
  v1->m_streamingCollection.m_pntr = 0i64;
  v1->m_forceRecutFaceKeys.m_data = 0i64;
  v1->m_forceRecutFaceKeys.m_size = 0;
  v1->m_forceRecutFaceKeys.m_capacityAndFlags = 2147483648;
  v1->m_forceClearanceCalcFaceKeys.m_data = 0i64;
  v1->m_forceClearanceCalcFaceKeys.m_size = 0;
  v1->m_forceClearanceCalcFaceKeys.m_capacityAndFlags = 2147483648;
  hkaiNavMeshEdgeMatchingParameters::hkaiNavMeshEdgeMatchingParameters(&v1->m_edgeMatchParams);
  v1->m_cutEdgeTolerance = 0.000099999997;
  v1->m_minEdgeMatchingLength = 0.0099999998;
  *(_WORD *)&v1->m_useNewCutter.m_bool = 1;
  v1->m_edgeMatchParams.m_maxOverhang = 3.40282e38;
  v1->m_edgeMatchParams.m_cosPlanarAlignmentAngle = 0.99026805;
  v1->m_edgeMatchParams.m_behindFaceTolerance = -3.40282e38;
  v1->m_up = (hkVector4f)stru_141A71280.m_quad;
  *(_WORD *)&v1->m_performValidationChecks.m_bool = 1;
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
  this->m_storage.m_elem.m_capacityAndFlags = 2147483648;
  this->m_storage.m_elem.m_data = 0i64;
  this->m_storage.m_elem.m_size = 0;
  this->m_storage.m_numElems = 0;
}

// File Line: 76
// RVA: 0xBED1F0
void __fastcall hkaiNavMeshCutter::SavedConnectivity::~SavedConnectivity(hkaiNavMeshCutter::SavedConnectivity *this)
{
  int v1; // er8
  hkaiNavMeshCutter::SavedConnectivity *v2; // rbx

  v1 = this->m_storage.m_elem.m_capacityAndFlags;
  v2 = this;
  this->m_storage.m_elem.m_size = 0;
  if ( v1 < 0 )
  {
    this->m_storage.m_elem.m_data = 0i64;
    this->m_storage.m_elem.m_capacityAndFlags = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_storage.m_elem.m_data,
      4 * v1);
    v2->m_storage.m_elem.m_data = 0i64;
    v2->m_storage.m_elem.m_capacityAndFlags = 2147483648;
  }
}

// File Line: 81
// RVA: 0xBED260
void __fastcall hkaiNavMeshCutter::SavedConnectivity::addConnectivity(hkaiNavMeshCutter::SavedConnectivity *this, unsigned int edgeKey)
{
  hkaiNavMeshCutter::SavedConnectivity *v2; // rdi
  int v3; // er8
  int v4; // ecx
  unsigned int v5; // ebx
  unsigned int *v6; // r8
  int v7; // er9
  signed int v8; // er10
  int v9; // eax
  unsigned int v10; // edx
  hkResult result; // [rsp+38h] [rbp+10h]

  v2 = this;
  v3 = this->m_storage.m_numElems & 0x7FFFFFFF;
  v4 = this->m_storage.m_elem.m_size - 1;
  v5 = edgeKey;
  if ( 2 * v3 > v4 )
    hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
      (hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *)&v2->m_storage.m_elem,
      &result,
      2 * v4 + 2);
  v6 = v2->m_storage.m_elem.m_data;
  v7 = v2->m_storage.m_elem.m_size - 1;
  v8 = 1;
  v9 = v7 & -1640531535 * (v5 >> 4);
  v10 = v2->m_storage.m_elem.m_data[v9];
  if ( v10 != -1 )
  {
    while ( v10 != v5 )
    {
      v9 = v7 & (v9 + 1);
      v10 = v6[v9];
      if ( v10 == -1 )
        goto LABEL_8;
    }
    v8 = 0;
  }
LABEL_8:
  v2->m_storage.m_numElems += v8;
  v6[v9] = v5;
}

// File Line: 87
// RVA: 0xBED300
void __fastcall hkaiNavMeshCutter::SavedConnectivity::popConnectivityForFace(hkaiNavMeshCutter::SavedConnectivity *this, hkaiStreamingCollection *collection, unsigned int faceKey)
{
  hkaiNavMeshCutter::SavedConnectivity *v3; // r14
  hkaiStreamingCollection *v4; // rbp
  __int64 v5; // rsi
  hkaiNavMeshInstance *v6; // rcx
  hkaiNavMesh::Face *v7; // rdi
  int v8; // ebx
  int v9; // esi

  v3 = this;
  v4 = collection;
  v5 = faceKey >> 22;
  v6 = collection->m_instances.m_data[v5].m_instancePtr;
  v7 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
         v6->m_originalFaces,
         v6->m_numOriginalFaces,
         &v6->m_instancedFaces,
         &v6->m_ownedFaces,
         &v6->m_faceMap,
         faceKey & 0x3FFFFF);
  v8 = v7->m_startEdgeIndex;
  if ( v7->m_startEdgeIndex < v7->m_startEdgeIndex + v7->m_numEdges )
  {
    v9 = (_DWORD)v5 << 22;
    do
      hkaiNavMeshCutter::SavedConnectivity::popConnectivityForEdgeAndFace(v3, v4, v8++ | v9);
    while ( v8 < v7->m_startEdgeIndex + v7->m_numEdges );
  }
}

// File Line: 97
// RVA: 0xBED3C0
signed __int64 __fastcall hkaiNavMeshCutter::SavedConnectivity::popConnectivityForEdgeAndFace(hkaiNavMeshCutter::SavedConnectivity *this, hkaiStreamingCollection *collection, unsigned int edgeKey)
{
  hkaiStreamingCollection *v3; // r11
  hkaiNavMeshCutter::SavedConnectivity *v4; // rdi
  int v5; // er10
  unsigned int *v6; // rdx
  unsigned int v7; // er9
  unsigned int v8; // ecx
  Dummy *v9; // rbx

  v3 = collection;
  v4 = this;
  v5 = this->m_storage.m_elem.m_size - 1;
  if ( v5 <= 0
    || (v6 = this->m_storage.m_elem.m_data,
        v7 = v5 & -1640531535 * (edgeKey >> 4),
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
      v8 = v6[v7];
      if ( v8 == -1 )
        goto LABEL_5;
    }
    v9 = (Dummy *)v7;
  }
  if ( (signed int)v9 > v5 )
    return 0i64;
  hkaiNavMeshCutter::SavedConnectivity::restore(v4, v3, edgeKey);
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::remove(
    (hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *)&v4->m_storage.m_elem,
    v9);
  return 1i64;
}

// File Line: 112
// RVA: 0xBED460
void __fastcall hkaiNavMeshCutter::SavedConnectivity::popConnectivityForOppositeFace(hkaiNavMeshCutter::SavedConnectivity *this, hkaiStreamingCollection *collection, unsigned int faceKey)
{
  hkaiStreamingCollection *v3; // r14
  hkaiNavMeshCutter::SavedConnectivity *v4; // r15
  hkaiNavMeshInstance *v5; // rdi
  hkaiNavMesh::Face *v6; // rsi
  signed __int64 v7; // rbp
  signed __int64 v8; // rbx
  hkaiNavMesh::Edge *v9; // rax
  unsigned int v10; // ecx
  unsigned int v11; // eax
  int v12; // er8

  v3 = collection;
  v4 = this;
  v5 = collection->m_instances.m_data[faceKey >> 22].m_instancePtr;
  v6 = &v5->m_originalFaces[faceKey & 0x3FFFFF];
  v7 = v6->m_startEdgeIndex;
  if ( (signed int)v7 < (signed int)v7 + v6->m_numEdges )
  {
    v8 = v7;
    do
    {
      v9 = v5->m_originalEdges;
      v10 = v9[v8].m_oppositeEdge;
      if ( v9[v8].m_flags.m_storage & 0x40 )
        v11 = v10 & 0xFFC00000;
      else
        v11 = v5->m_runtimeId << 22;
      v12 = v11 | v10 & 0x3FFFFF;
      if ( v10 == -1 )
        v12 = -1;
      hkaiNavMeshCutter::SavedConnectivity::popConnectivityForEdgeAndFace(v4, v3, v12);
      LODWORD(v7) = v7 + 1;
      ++v8;
    }
    while ( (signed int)v7 < v6->m_startEdgeIndex + v6->m_numEdges );
  }
}

// File Line: 123
// RVA: 0xBED550
void __fastcall hkaiNavMeshCutter::SavedConnectivity::restore(hkaiNavMeshCutter::SavedConnectivity *this, hkaiStreamingCollection *collection, unsigned int edgeKey)
{
  unsigned int v3; // eax
  signed int v4; // er8
  hkaiNavMeshInstance *v5; // rdx
  signed __int64 v6; // r9
  int v7; // eax
  signed __int64 v8; // rcx
  hkaiNavMesh::Edge *v9; // rax
  signed __int64 v10; // rdx

  v3 = edgeKey;
  v4 = edgeKey & 0x3FFFFF;
  v5 = collection->m_instances.m_data[v3 >> 22].m_instancePtr;
  v6 = (signed __int64)&v5->m_originalEdges[v4];
  v7 = v5->m_numOriginalEdges;
  if ( v4 >= v7 )
  {
    v8 = v4 - v7;
    v9 = v5->m_ownedEdges.m_data;
LABEL_8:
    v10 = (signed __int64)&v9[v8];
    goto LABEL_9;
  }
  if ( v5->m_edgeMap.m_size )
    v4 = v5->m_edgeMap.m_data[v4];
  if ( v4 != -1 )
  {
    v8 = v4;
    v9 = v5->m_instancedEdges.m_data;
    goto LABEL_8;
  }
  v10 = 0i64;
LABEL_9:
  *(_DWORD *)(v10 + 8) = *(_DWORD *)(v6 + 8);
  *(_DWORD *)(v10 + 12) = *(_DWORD *)(v6 + 12);
  *(_BYTE *)(v10 + 16) = *(_BYTE *)(v6 + 16);
}

// File Line: 136
// RVA: 0xBED5F0
void __fastcall hkaiNavMeshCutter::SavedConnectivity::append(hkaiNavMeshCutter::SavedConnectivity *this, hkaiNavMeshCutter::SavedConnectivity *other)
{
  int v2; // er9
  signed __int64 v3; // r8
  int v4; // er11
  hkaiNavMeshCutter::SavedConnectivity *v5; // r14
  hkaiNavMeshCutter::SavedConnectivity *v6; // rsi
  unsigned int *v7; // rax
  int v8; // edi
  int v9; // er8
  unsigned int v10; // ebx
  unsigned int *v11; // r9
  int v12; // er8
  signed int v13; // er10
  int v14; // eax
  unsigned int v15; // edx
  int v16; // er8
  signed __int64 v17; // rcx
  int v18; // er10
  unsigned int *v19; // rdx
  hkResult result; // [rsp+38h] [rbp+10h]

  v2 = 0;
  v3 = 0i64;
  v4 = other->m_storage.m_elem.m_size - 1;
  v5 = other;
  v6 = this;
  if ( v4 >= 0 )
  {
    v7 = other->m_storage.m_elem.m_data;
    do
    {
      if ( *v7 != -1 )
        break;
      ++v3;
      ++v2;
      ++v7;
    }
    while ( v3 <= v4 );
  }
  v8 = v2;
  if ( v2 <= v4 )
  {
    do
    {
      v9 = v6->m_storage.m_elem.m_size;
      v10 = v5->m_storage.m_elem.m_data[v8];
      if ( 2 * v6->m_storage.m_numElems > v9 - 1 )
        hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
          (hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *)&v6->m_storage.m_elem,
          &result,
          2 * v9);
      v11 = v6->m_storage.m_elem.m_data;
      v12 = v6->m_storage.m_elem.m_size - 1;
      v13 = 1;
      v14 = v12 & -1640531535 * (v10 >> 4);
      v15 = v6->m_storage.m_elem.m_data[v14];
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
      v6->m_storage.m_numElems += v13;
      v16 = v8 + 1;
      v11[v14] = v10;
      v17 = v8 + 1;
      v18 = v5->m_storage.m_elem.m_size - 1;
      if ( v17 <= v18 )
      {
        v19 = &v5->m_storage.m_elem.m_data[v16];
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
__int64 __fastcall hkaiNavMeshCutter::MeshInfo::isValid(hkaiNavMeshCutter::MeshInfo *this, hkaiNavMeshInstance *meshInstance, hkaiNavMeshCutter::SavedConnectivity *connectivityInfo)
{
  __int64 v3; // rsi
  hkaiNavMeshInstance *v4; // r15
  hkaiNavMeshCutter::MeshInfo *v5; // r13
  unsigned int v6; // er14
  int v7; // er8
  __int64 v8; // rbx
  __int64 v9; // rdi
  int *v10; // r11
  __int64 v11; // r9
  int v12; // edx
  __int64 v13; // rax
  int *v14; // rcx
  bool v15; // zf
  __int64 v16; // rdx
  __int64 v17; // rax
  int *v18; // rcx
  signed int v19; // edx
  __int64 v20; // rax
  int *v21; // rcx
  int *v22; // rcx
  int v23; // er11
  signed int v24; // er8
  int v25; // eax
  __int64 v26; // rdx
  __int64 v27; // r9
  int v28; // er10
  int *v29; // rax
  __int16 v30; // cx
  int index; // ebp
  int *v32; // rsi
  int *v33; // rbx
  __int64 v34; // rdi
  hkaiNavMesh::Face *v35; // rax
  hkaiNavMesh::Face *v36; // rcx
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v37; // r8
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v38; // r9
  signed int v39; // er13
  hkaiNavMesh::Face *v40; // r12
  int *v41; // rsi
  hkaiNavMesh::Face *v42; // rax
  __int16 v43; // bx
  hkaiNavMesh::Face *v44; // r9
  int v45; // eax
  __int64 v46; // r11
  int v47; // er10
  unsigned __int16 v48; // r8
  int *v50; // [rsp+30h] [rbp-48h]
  int *v51; // [rsp+38h] [rbp-40h]
  hkaiNavMeshCutter::MeshInfo *v52; // [rsp+80h] [rbp+8h]
  int v53; // [rsp+88h] [rbp+10h]
  int v54; // [rsp+98h] [rbp+20h]

  v52 = this;
  v3 = this->m_originalNumFaces;
  v4 = meshInstance;
  v5 = this;
  v6 = 1;
  v7 = 0;
  v8 = 0i64;
  if ( (signed int)v3 > 0 )
  {
    v9 = this->m_magic.m_size;
    v10 = this->m_magic.m_data;
    do
    {
      v11 = v10[v8];
      v12 = v3;
      v13 = v3;
      if ( (_DWORD)v11 == -1 )
      {
        if ( v3 < v9 )
        {
          v22 = &v10[v3];
          while ( *v22 != v7 )
          {
            ++v13;
            ++v12;
            ++v22;
            if ( v13 >= v9 )
              goto LABEL_30;
          }
          if ( v12 != -1 )
            v6 = 0;
        }
      }
      else if ( v3 < v9 )
      {
        v14 = &v10[v3];
        while ( *v14 != v7 )
        {
          ++v13;
          ++v12;
          ++v14;
          if ( v13 >= v9 )
            goto LABEL_30;
        }
        if ( v12 != -1 )
        {
          v15 = (_DWORD)v11 == v12;
          v16 = v5->m_magic.m_size;
          v17 = v10[v8];
          if ( !v15 )
            v6 = 0;
          if ( v11 < v16 )
          {
            v18 = &v10[v11];
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
          v19 = v9 - 1;
          v20 = (signed int)v9 - 1;
          if ( (signed int)v9 - 1 < 0 )
          {
LABEL_20:
            v19 = -1;
          }
          else
          {
            v21 = &v10[v19];
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
    while ( v8 < v3 );
  }
  v23 = v4->m_numOriginalFaces;
  v24 = 0;
  v25 = v23 + v4->m_ownedFaces.m_size;
  v26 = 0i64;
  v27 = v25;
  if ( v25 > 0 )
  {
    v28 = v4->m_faceFlags.m_size;
    do
    {
      if ( v28 )
      {
        v29 = &v53;
        LOBYTE(v53) = v4->m_faceFlags.m_data[v26].m_storage;
      }
      else
      {
        LOBYTE(v54) = 0;
        v29 = &v54;
      }
      v30 = *(_BYTE *)v29 & 0xFB;
      if ( v24 >= (signed int)v3 )
      {
        if ( v30 != 2 )
          v6 = 0;
      }
      else if ( v5->m_magic.m_data[v26] == -1 )
      {
        if ( *(_BYTE *)v29 & 0xFB )
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
  if ( v23 > 0 )
  {
    v32 = v5->m_magic.m_data;
    v33 = v5->m_magic.m_data;
    v51 = v5->m_magic.m_data;
    v50 = v5->m_magic.m_data;
    do
    {
      v34 = *v33;
      if ( (signed int)v34 >= 0 )
      {
        v35 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
                v4->m_originalFaces,
                v23,
                &v4->m_instancedFaces,
                &v4->m_ownedFaces,
                &v4->m_faceMap,
                index);
        v39 = v5->m_magic.m_size;
        v40 = v35;
        v54 = v39;
        if ( (signed int)v34 < v39 )
        {
          v41 = &v32[v34];
          while ( *v41 == index )
          {
            v42 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(v36, v23, v37, v38, &v4->m_faceMap, v34);
            v43 = v42->m_numUserEdges;
            v44 = v42;
            if ( v43 <= 0 )
              v45 = v42->m_startEdgeIndex;
            else
              v45 = v42->m_startUserEdgeIndex;
            if ( v45 != -1 )
            {
              v46 = v4->m_numOriginalEdges;
              v47 = v44->m_startUserEdgeIndex;
              while ( 1 )
              {
                if ( v45 >= (signed int)v46 )
                {
                  v48 = v4->m_cuttingInfo.m_data[v45 - v46];
                  if ( v48 != -1 && v48 >= (signed int)v40->m_numEdges )
                    v6 = 0;
                }
                if ( v45 >= v47 && v45 < v43 + v47 - 1 )
                  goto LABEL_66;
                if ( v45 != v43 + v47 - 1 )
                  break;
                v45 = v44->m_startEdgeIndex;
LABEL_67:
                if ( v45 == -1 )
                  goto LABEL_68;
              }
              if ( v45 < v44->m_startEdgeIndex || v45 >= v44->m_numEdges + v44->m_startEdgeIndex - 1 )
              {
LABEL_68:
                index = v53;
                v39 = v54;
                v23 = v4->m_numOriginalFaces;
                v36 = v4->m_originalFaces;
                v37 = &v4->m_instancedFaces;
                goto LABEL_69;
              }
LABEL_66:
              ++v45;
              goto LABEL_67;
            }
LABEL_69:
            LODWORD(v34) = v34 + 1;
            ++v41;
            v38 = &v4->m_ownedFaces;
            if ( (signed int)v34 >= v39 )
              break;
          }
          v33 = v50;
          v32 = v51;
        }
        v5 = v52;
      }
      ++index;
      ++v33;
      v53 = index;
      v50 = v33;
    }
    while ( index < v23 );
  }
  return v6;
}

// File Line: 226
// RVA: 0xBF0920
__int64 __fastcall hkaiNavMeshCutter::isValid(hkaiNavMeshCutter *this)
{
  hkaiNavMeshCutter *v1; // r14
  _QWORD *v2; // r8
  _QWORD *v3; // rcx
  unsigned __int64 v4; // rax
  signed __int64 v5; // rcx
  hkaiStreamingCollection *v6; // rbx
  unsigned int v7; // ebp
  __int64 v8; // rsi
  int v9; // edi
  hkaiNavMeshInstance **v10; // rbx
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx

  v1 = this;
  v2 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v3 = (_QWORD *)v2[1];
  if ( (unsigned __int64)v3 < v2[3] )
  {
    *v3 = "TtisValid";
    v4 = __rdtsc();
    v5 = (signed __int64)(v3 + 2);
    *(_DWORD *)(v5 - 8) = v4;
    v2[1] = v5;
  }
  v6 = v1->m_streamingCollection.m_pntr;
  v7 = 1;
  v8 = v6->m_instances.m_size;
  v9 = 0;
  if ( v8 > 0 )
  {
    v10 = &v6->m_instances.m_data->m_instancePtr;
    do
    {
      if ( *v10 && !hkaiNavMeshCutter::MeshInfo::isValid(&v1->m_meshInfos.m_data[v9], *v10, &v1->m_connectivityInfo) )
        v7 = 0;
      ++v9;
      v10 += 6;
      --v8;
    }
    while ( v8 );
  }
  v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)v11[1];
  if ( (unsigned __int64)v12 < v11[3] )
  {
    *v12 = "Et";
    v13 = __rdtsc();
    v14 = (signed __int64)(v12 + 2);
    *(_DWORD *)(v14 - 8) = v13;
    v11[1] = v14;
  }
  return v7;
}

// File Line: 248
// RVA: 0xBF2240
void __fastcall hkaiNavMeshCutter::MeshInfo::init(hkaiNavMeshCutter::MeshInfo *this, hkaiNavMeshInstance *meshInstance)
{
  hkaiNavMeshCutter::MeshInfo *v2; // rdi
  hkArray<int,hkContainerHeapAllocator> *v3; // rbx
  int v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // er9
  int v8; // edx
  int *v9; // rdi
  __int64 v10; // rcx
  int v11; // er8
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = this;
  if ( meshInstance )
  {
    v3 = &this->m_magic;
    this->m_originalNumFaces = meshInstance->m_numOriginalFaces;
    this->m_originalNumEdges = meshInstance->m_numOriginalEdges;
    this->m_originalNumVertices = meshInstance->m_numOriginalVertices;
    v4 = meshInstance->m_numOriginalFaces;
    v5 = this->m_magic.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v5 < v4 )
    {
      v6 = 2 * v5;
      v7 = meshInstance->m_numOriginalFaces;
      if ( v4 < v6 )
        v7 = v6;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v7, 4);
    }
    v8 = v4 - v3->m_size;
    v9 = &v3->m_data[v3->m_size];
    v10 = v8;
    if ( v8 > 0 )
    {
      while ( v10 )
      {
        *v9 = -1;
        ++v9;
        --v10;
      }
    }
    v3->m_size = v4;
  }
  else
  {
    *(_QWORD *)&this->m_originalNumFaces = 0i64;
    this->m_originalNumVertices = 0;
    v11 = this->m_magic.m_capacityAndFlags;
    this->m_magic.m_size = 0;
    if ( v11 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        this->m_magic.m_data,
        4 * v11);
    v2->m_magic.m_data = 0i64;
    v2->m_magic.m_capacityAndFlags = 2147483648;
  }
}

// File Line: 266
// RVA: 0xBED7F0
void __fastcall hkaiNavMeshCutter::init(hkaiNavMeshCutter *this, hkVector4f *up, hkaiStreamingCollection *collection)
{
  hkaiStreamingCollection *v3; // rbp
  hkaiNavMeshCutter *v4; // r14
  hkReferencedObject *v5; // rcx
  int v6; // ebx
  int v7; // er12
  int v8; // eax
  int v9; // eax
  int v10; // er9
  __int64 v11; // r15
  int v12; // eax
  __int64 v13; // rsi
  int *v14; // rdi
  int v15; // er8
  int v16; // eax
  __int64 v17; // rdx
  int *v18; // rcx
  __int64 v19; // rdi
  hkResult result; // [rsp+60h] [rbp+8h]

  v3 = collection;
  v4 = this;
  this->m_up = (hkVector4f)up->m_quad;
  if ( collection )
    hkReferencedObject::addReference((hkReferencedObject *)&collection->vfptr);
  v5 = (hkReferencedObject *)&v4->m_streamingCollection.m_pntr->vfptr;
  if ( v5 )
    hkReferencedObject::removeReference(v5);
  v6 = 0;
  v4->m_streamingCollection.m_pntr = v3;
  if ( v3 )
    v7 = v3->m_instances.m_size;
  else
    v7 = 0;
  v8 = v4->m_meshInfos.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v7 )
  {
    v9 = 2 * v8;
    v10 = v7;
    if ( v7 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v4->m_meshInfos,
      v10,
      32);
  }
  v11 = v7;
  v12 = v4->m_meshInfos.m_size - v7 - 1;
  v13 = v12;
  if ( v12 >= 0 )
  {
    v14 = &v4->m_meshInfos.m_data[v7 + v12].m_magic.m_capacityAndFlags;
    do
    {
      v15 = *v14;
      *(v14 - 1) = 0;
      if ( v15 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v14 - 3),
          4 * v15);
      *(_QWORD *)(v14 - 3) = 0i64;
      *v14 = 2147483648;
      v14 -= 8;
      --v13;
    }
    while ( v13 >= 0 );
  }
  v16 = v4->m_meshInfos.m_size;
  v17 = v7 - v16;
  if ( v7 - v16 > 0 )
  {
    v18 = &v4->m_meshInfos.m_data[v4->m_meshInfos.m_size].m_magic.m_capacityAndFlags;
    do
    {
      if ( v18 != (int *)28 )
      {
        *(_QWORD *)(v18 - 3) = 0i64;
        *(v18 - 1) = 0;
        *v18 = 2147483648;
      }
      v18 += 8;
      --v17;
    }
    while ( v17 );
  }
  v4->m_meshInfos.m_size = v7;
  if ( v7 > 0i64 )
  {
    v19 = 0i64;
    do
    {
      hkaiNavMeshCutter::MeshInfo::init(&v4->m_meshInfos.m_data[v6++], v3->m_instances.m_data[v19].m_instancePtr);
      ++v19;
      --v11;
    }
    while ( v11 );
  }
}

// File Line: 281
// RVA: 0xBF2160
void __fastcall hkaiNavMeshCutter::setFaceAsStreaming(hkaiNavMeshCutter *this, unsigned int forceCutKey)
{
  unsigned int v2; // edi
  signed int v3; // er11
  hkaiNavMeshCutter *v4; // rbx
  hkaiNavMeshInstance *v5; // r10
  char v6; // [rsp+38h] [rbp+10h]

  v2 = forceCutKey;
  v3 = forceCutKey & 0x3FFFFF;
  v4 = this;
  v5 = this->m_streamingCollection.m_pntr->m_instances.m_data[forceCutKey >> 22].m_instancePtr;
  if ( v5->m_faceFlags.m_size )
    v6 = v5->m_faceFlags.m_data[v3].m_storage;
  else
    v6 = 0;
  v5->m_faceFlags.m_data[v3].m_storage = v6 | 4;
  if ( v5->m_faceFlags.m_size )
    v6 = v5->m_faceFlags.m_data[v3].m_storage;
  else
    v6 = 0;
  if ( !(v6 & 1) )
  {
    if ( this->m_forceRecutFaceKeys.m_size == (this->m_forceRecutFaceKeys.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &this->m_forceRecutFaceKeys,
        4);
    v4->m_forceRecutFaceKeys.m_data[v4->m_forceRecutFaceKeys.m_size++] = v2;
  }
}

// File Line: 299
// RVA: 0xBED990
void __fastcall hkaiNavMeshCutter::initSection(hkaiNavMeshCutter *this, int sectionIdx, hkaiNavMeshInstance *meshInstance, bool doChecks)
{
  __int64 v4; // r15
  __int64 v5; // rdi
  int v6; // esi
  hkaiNavMeshInstance *v7; // r12
  hkaiNavMeshCutter *v8; // r13
  int v9; // eax
  int v10; // eax
  int v11; // er9
  int v12; // eax
  __int64 v13; // rdi
  int *v14; // rbx
  int v15; // er8
  int v16; // eax
  __int64 v17; // rdx
  int *v18; // rcx
  hkaiNavMesh *v19; // r15
  int v20; // ebx
  bool v21; // zf
  bool v22; // sf
  int *v23; // r10
  unsigned int *v24; // r9
  __int64 v25; // r14
  hkaiStreamingSet *v26; // rcx
  int v27; // eax
  int v28; // esi
  hkaiStreamingSet *v29; // rdx
  __int64 v30; // r12
  hkaiStreamingSet::NavMeshConnection *v31; // rcx
  int v32; // er10
  int v33; // edx
  int v34; // ebx
  int v35; // er9
  int v36; // ecx
  signed int v37; // er11
  int v38; // edx
  hkaiNavMeshInstance *v39; // rdx
  __int64 v40; // r8
  hkaiNavMeshCutter **v41; // rax
  int v42; // er10
  int v43; // edx
  unsigned int v44; // ebx
  int v45; // er9
  signed int v46; // er11
  int v47; // eax
  unsigned int v48; // edx
  int v49; // er8
  int v50; // edx
  signed __int64 v51; // rcx
  int v52; // ebx
  int v53; // er8
  int v54; // edx
  signed __int64 v55; // rcx
  int v56; // edx
  int v57; // er8
  signed __int64 v58; // rcx
  int v59; // ebx
  int v60; // er8
  int v61; // edx
  signed __int64 v62; // rcx
  char v63; // [rsp+28h] [rbp-19h]
  int v64; // [rsp+2Ch] [rbp-15h]
  hkResult v65; // [rsp+30h] [rbp-11h]
  hkResult v66; // [rsp+34h] [rbp-Dh]
  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > v67; // [rsp+38h] [rbp-9h]
  hkSet<int,hkContainerTempAllocator,hkMapOperations<int> > v68; // [rsp+50h] [rbp+Fh]
  hkaiNavMeshCutter *retaddr; // [rsp+A8h] [rbp+67h]
  hkaiNavMeshCutter *result; // [rsp+B0h] [rbp+6Fh]
  hkaiNavMeshInstance *v71; // [rsp+B8h] [rbp+77h]
  hkaiNavMeshInstance *v72; // [rsp+C0h] [rbp+7Fh]

  v72 = meshInstance;
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
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &this->m_meshInfos,
        v11,
        32);
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
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)(v14 - 3),
            4 * v15);
        *(_QWORD *)(v14 - 3) = 0i64;
        *v14 = 2147483648;
        v14 -= 8;
        --v13;
      }
      while ( v13 >= 0 );
    }
    v16 = v6 - v8->m_meshInfos.m_size;
    v17 = v16;
    if ( v16 > 0 )
    {
      v18 = &v8->m_meshInfos.m_data[v8->m_meshInfos.m_size].m_magic.m_capacityAndFlags;
      do
      {
        if ( v18 != (int *)28 )
        {
          *(_QWORD *)(v18 - 3) = 0i64;
          *(v18 - 1) = 0;
          *v18 = 2147483648;
        }
        v18 += 8;
        --v17;
      }
      while ( v17 );
    }
    v8->m_meshInfos.m_size = v6;
    v5 = 0i64;
  }
  hkaiNavMeshCutter::MeshInfo::init(&v8->m_meshInfos.m_data[v4], v7);
  v19 = v7->m_originalMesh.m_pntr;
  v20 = 0;
  v68.m_elem.m_data = 0i64;
  v68.m_elem.m_size = 0;
  v68.m_elem.m_capacityAndFlags = 2147483648;
  v68.m_numElems = 0;
  v67.m_elem.m_data = 0i64;
  v67.m_elem.m_size = 0;
  v67.m_elem.m_capacityAndFlags = 2147483648;
  v67.m_numElems = 0;
  v21 = v19->m_streamingSets.m_size == 0;
  v22 = v19->m_streamingSets.m_size < 0;
  v23 = 0i64;
  v24 = 0i64;
  v64 = 0;
  if ( !v22 && !v21 )
  {
    v25 = 0i64;
    do
    {
      v26 = v19->m_streamingSets.m_data;
      if ( v26[v25].m_thisUid == v7->m_sectionUid )
      {
        v27 = hkaiStreamingCollection::findSectionIdByUid(v8->m_streamingCollection.m_pntr, v26[v25].m_oppositeUid);
        v28 = 0;
        v29 = &v19->m_streamingSets.m_data[v25];
        v30 = v27;
        if ( v29->m_meshConnections.m_size > 0 )
        {
          do
          {
            v31 = v29->m_meshConnections.m_data;
            v32 = v68.m_numElems;
            v33 = v68.m_elem.m_size;
            v34 = v31[v5].m_faceIndex;
            if ( 2 * v68.m_numElems > v68.m_elem.m_size - 1 )
            {
              hkSet<int,hkContainerTempAllocator,hkMapOperations<int>>::resizeTable(&v68, &v65, 2 * v68.m_elem.m_size);
              v32 = v68.m_numElems;
              v33 = v68.m_elem.m_size;
            }
            v35 = v33 - 1;
            v36 = (v33 - 1) & -1640531535 * v34;
            v37 = 1;
            v38 = v68.m_elem.m_data[v36];
            if ( v38 != -1 )
            {
              while ( v38 != v34 )
              {
                v36 = v35 & (v36 + 1);
                v38 = v68.m_elem.m_data[v36];
                if ( v38 == -1 )
                  goto LABEL_28;
              }
              v37 = 0;
            }
LABEL_28:
            v68.m_numElems = v37 + v32;
            v68.m_elem.m_data[v36] = v34;
            if ( (_DWORD)v30 != -1 )
            {
              v39 = retaddr->m_streamingCollection.m_pntr->m_instances.m_data[v30].m_instancePtr;
              v40 = v19->m_streamingSets.m_data[v25].m_meshConnections.m_data[v5].m_oppositeFaceIndex;
              if ( v39->m_faceFlags.m_size )
              {
                v41 = &result;
                LOBYTE(result) = v39->m_faceFlags.m_data[v40].m_storage;
              }
              else
              {
                v63 = 0;
                v41 = (hkaiNavMeshCutter **)&v63;
              }
              if ( !(*(_BYTE *)v41 & 4) )
              {
                v42 = v67.m_numElems;
                v43 = v67.m_elem.m_size;
                v44 = v40 | ((_DWORD)v30 << 22);
                if ( 2 * v67.m_numElems > v67.m_elem.m_size - 1 )
                {
                  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int>>::resizeTable(
                    &v67,
                    &v66,
                    2 * v67.m_elem.m_size);
                  v42 = v67.m_numElems;
                  v43 = v67.m_elem.m_size;
                }
                v45 = v43 - 1;
                v46 = 1;
                v47 = (v43 - 1) & -1640531535 * (v44 >> 4);
                v48 = v67.m_elem.m_data[v47];
                if ( v48 != -1 )
                {
                  while ( v48 != v44 )
                  {
                    v47 = v45 & (v47 + 1);
                    v48 = v67.m_elem.m_data[v47];
                    if ( v48 == -1 )
                      goto LABEL_40;
                  }
                  v46 = 0;
                }
LABEL_40:
                v67.m_numElems = v46 + v42;
                v67.m_elem.m_data[v47] = v44;
              }
            }
            ++v28;
            ++v5;
            v29 = &v19->m_streamingSets.m_data[v25];
          }
          while ( v28 < v29->m_meshConnections.m_size );
          v20 = v64;
          v5 = 0i64;
        }
        v7 = v71;
        v8 = retaddr;
        v24 = v67.m_elem.m_data;
        v23 = v68.m_elem.m_data;
      }
      ++v20;
      ++v25;
      v64 = v20;
    }
    while ( v20 < v19->m_streamingSets.m_size );
  }
  v49 = v68.m_elem.m_size - 1;
  v50 = 0;
  v51 = 0i64;
  if ( v68.m_elem.m_size - 1 >= 0 )
  {
    do
    {
      if ( v23[v51] != -1 )
        break;
      ++v51;
      ++v50;
    }
    while ( v51 <= v49 );
  }
  v52 = v50;
  if ( v50 <= v49 )
  {
    do
    {
      hkaiNavMeshCutter::setFaceAsStreaming(v8, (v7->m_runtimeId << 22) | v23[v52]);
      v23 = v68.m_elem.m_data;
      v53 = v68.m_elem.m_size - 1;
      v54 = v52 + 1;
      v55 = v52 + 1;
      if ( v55 <= v68.m_elem.m_size - 1 )
      {
        do
        {
          if ( v68.m_elem.m_data[v55] != -1 )
            break;
          ++v55;
          ++v54;
        }
        while ( v55 <= v53 );
      }
      v52 = v54;
    }
    while ( v54 <= v53 );
    v24 = v67.m_elem.m_data;
  }
  v56 = 0;
  v57 = v67.m_elem.m_size - 1;
  v58 = 0i64;
  if ( v67.m_elem.m_size - 1 >= 0 )
  {
    do
    {
      if ( v24[v58] != -1 )
        break;
      ++v58;
      ++v56;
    }
    while ( v58 <= v57 );
  }
  v59 = v56;
  if ( v56 <= v57 )
  {
    do
    {
      hkaiNavMeshCutter::setFaceAsStreaming(v8, v24[v59]);
      v24 = v67.m_elem.m_data;
      v60 = v67.m_elem.m_size - 1;
      v61 = v59 + 1;
      v62 = v59 + 1;
      if ( v62 <= v67.m_elem.m_size - 1 )
      {
        do
        {
          if ( v67.m_elem.m_data[v62] != -1 )
            break;
          ++v62;
          ++v61;
        }
        while ( v62 <= v60 );
      }
      v59 = v61;
    }
    while ( v61 <= v60 );
    v23 = v68.m_elem.m_data;
  }
  v67.m_elem.m_size = 0;
  if ( v67.m_elem.m_capacityAndFlags >= 0 )
  {
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v24,
      4 * v67.m_elem.m_capacityAndFlags);
    v23 = v68.m_elem.m_data;
  }
  v67.m_elem.m_data = 0i64;
  v68.m_elem.m_size = 0;
  v67.m_elem.m_capacityAndFlags = 2147483648;
  if ( v68.m_elem.m_capacityAndFlags >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, int *, _QWORD, unsigned int *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v23,
      (unsigned int)(4 * v68.m_elem.m_capacityAndFlags),
      v24);
}

// File Line: 370
// RVA: 0xBF0A20
void __fastcall hkaiNavMeshCutter::intersectMeshWithSilhouettes(hkaiNavMeshCutter *this, hkArrayBase<unsigned int> *faceKeys, hkaiNavMeshSilhouetteSelector *selector, hkaiSilhouetteGenerationParameters *genParams, hkArrayBase<hkaiFaceCutResults> *results)
{
  hkaiNavMeshCutter *v5; // r15
  hkArrayBase<unsigned int> *v6; // rbx
  hkaiSilhouetteGenerationParameters *v7; // rsi
  hkaiNavMeshSilhouetteSelector *v8; // r12
  int v9; // er14
  __int64 v10; // rcx
  unsigned int v11; // edi
  _QWORD *v12; // rax
  _QWORD *v13; // rcx
  _QWORD *v14; // r8
  unsigned __int64 v15; // rax
  signed __int64 v16; // rcx
  _QWORD *v17; // r8
  _QWORD *v18; // rcx
  unsigned __int64 v19; // rax
  signed __int64 v20; // rcx
  hkaiNavMeshInstance *v21; // rsi
  int v22; // edx
  hkaiNavMesh::Face *v23; // rcx
  int v24; // ebx
  hkVector4f *v25; // rax
  int v26; // ebx
  LPVOID v27; // rax
  hkLifoAllocator *v28; // rcx
  int v29; // edx
  char *v30; // r8
  int v31; // ebx
  LPVOID v32; // rax
  hkLifoAllocator *v33; // rcx
  int *v34; // rax
  int v35; // edx
  char *v36; // r8
  int v37; // ebx
  __int64 v38; // rdi
  __int64 v39; // rsi
  int v40; // er9
  int v41; // eax
  char *v42; // rdi
  signed int v43; // ebx
  hkLifoAllocator *v44; // rax
  int v45; // er8
  int v46; // eax
  char *v47; // rdi
  signed int v48; // ebx
  hkLifoAllocator *v49; // rax
  int v50; // er8
  __int64 v51; // rdi
  char *v52; // rbx
  int v53; // er8
  bool v54; // [rsp+40h] [rbp-C0h]
  char *v55; // [rsp+48h] [rbp-B8h]
  int v56; // [rsp+50h] [rbp-B0h]
  int v57; // [rsp+54h] [rbp-ACh]
  int v58; // [rsp+58h] [rbp-A8h]
  char *v59; // [rsp+60h] [rbp-A0h]
  int v60; // [rsp+68h] [rbp-98h]
  int v61; // [rsp+6Ch] [rbp-94h]
  hkArrayBase<int> indexRemap; // [rsp+70h] [rbp-90h]
  void *p; // [rsp+80h] [rbp-80h]
  int v64; // [rsp+88h] [rbp-78h]
  hkArrayBase<hkVector4f> faceVertices; // [rsp+90h] [rbp-70h]
  void *v66; // [rsp+A0h] [rbp-60h]
  int v67; // [rsp+A8h] [rbp-58h]
  __int64 v68; // [rsp+B0h] [rbp-50h]
  hkaiFaceCutResults *v69; // [rsp+B8h] [rbp-48h]
  hkaiAbstractFaceCutter v70; // [rsp+C0h] [rbp-40h]
  hkSimdFloat32 regionExpansion; // [rsp+F0h] [rbp-10h]
  hkaiNavMeshCutter *v72; // [rsp+150h] [rbp+50h]
  hkArrayBase<unsigned int> *v73; // [rsp+158h] [rbp+58h]
  hkaiNavMeshSilhouetteSelector *v74; // [rsp+160h] [rbp+60h]
  hkaiSilhouetteGenerationParameters *v75; // [rsp+168h] [rbp+68h]

  v75 = genParams;
  v74 = selector;
  v73 = faceKeys;
  v72 = this;
  v5 = this;
  v6 = faceKeys;
  v7 = genParams;
  v8 = selector;
  hkaiAbstractFaceCutter::hkaiAbstractFaceCutter(&v70, this->m_useNewCutter.m_bool != 0);
  v9 = 0;
  v58 = 0;
  if ( v6->m_size > 0 )
  {
    v10 = 0i64;
    v68 = 0i64;
    do
    {
      v11 = *(unsigned int *)((char *)v6->m_data + v10);
      v55 = 0i64;
      v56 = 0;
      v57 = 2147483648;
      v59 = 0i64;
      v60 = 0;
      v61 = 2147483648;
      v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v13 = (_QWORD *)v12[1];
      v14 = v12;
      if ( (unsigned __int64)v13 < v12[3] )
      {
        *v13 = "TtgatherSilhouettes";
        v15 = __rdtsc();
        v16 = (signed __int64)(v13 + 2);
        *(_DWORD *)(v16 - 8) = v15;
        v14[1] = v16;
      }
      v8->vfptr->gatherSilhouettesForFace(
        v8,
        v11,
        v7,
        (hkArray<hkArray<hkVector4f,hkContainerTempAllocator>,hkContainerTempAllocator> *)&v55,
        (hkArray<int,hkContainerTempAllocator> *)&v59);
      v17 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v18 = (_QWORD *)v17[1];
      if ( (unsigned __int64)v18 < v17[3] )
      {
        *v18 = "Et";
        v19 = __rdtsc();
        v20 = (signed __int64)(v18 + 2);
        *(_DWORD *)(v20 - 8) = v19;
        v17[1] = v20;
      }
      v21 = v5->m_streamingCollection.m_pntr->m_instances.m_data[v11 >> 22].m_instancePtr;
      v22 = v21->m_numOriginalFaces;
      v23 = v21->m_originalFaces;
      v69 = &results->m_data[v9];
      v54 = v21->m_originalMesh.m_pntr->m_flags.m_storage & 1;
      v24 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
              v23,
              v22,
              &v21->m_instancedFaces,
              &v21->m_ownedFaces,
              &v21->m_faceMap,
              v11 & 0x3FFFFF)->m_numEdges;
      v25 = 0i64;
      faceVertices.m_capacityAndFlags = 2147483648;
      v26 = v24 + 1;
      faceVertices.m_data = 0i64;
      faceVertices.m_size = 0;
      v67 = v26;
      if ( v26 )
      {
        v27 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v28 = (hkLifoAllocator *)v27;
        v25 = (hkVector4f *)*((_QWORD *)v27 + 3);
        v29 = (16 * v26 + 127) & 0xFFFFFF80;
        v30 = (char *)v25 + v29;
        if ( v29 > v28->m_slabSize || v30 > v28->m_end )
          v25 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v28, v29);
        else
          v28->m_cur = v30;
      }
      faceVertices.m_data = v25;
      v66 = v25;
      faceVertices.m_capacityAndFlags = v26 | 0x80000000;
      v31 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
              v21->m_originalFaces,
              v21->m_numOriginalFaces,
              &v21->m_instancedFaces,
              &v21->m_ownedFaces,
              &v21->m_faceMap,
              v11 & 0x3FFFFF)->m_numEdges;
      indexRemap.m_data = 0i64;
      indexRemap.m_size = 0;
      indexRemap.m_capacityAndFlags = 2147483648;
      v64 = v31;
      if ( v31 )
      {
        v32 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v33 = (hkLifoAllocator *)v32;
        v34 = (int *)*((_QWORD *)v32 + 3);
        v35 = (4 * v31 + 127) & 0xFFFFFF80;
        v36 = (char *)v34 + v35;
        if ( v35 > v33->m_slabSize || v36 > v33->m_end )
          v34 = (int *)hkLifoAllocator::allocateFromNewSlab(v33, v35);
        else
          v33->m_cur = v36;
      }
      else
      {
        v34 = 0i64;
      }
      indexRemap.m_data = v34;
      p = v34;
      indexRemap.m_capacityAndFlags = v31 | 0x80000000;
      if ( v56 <= 0 )
      {
        hkaiAbstractFaceCutter::reset(&v70, v11);
        v5 = v72;
      }
      else
      {
        v5 = v72;
        regionExpansion.m_real = _mm_shuffle_ps(
                                   (__m128)LODWORD(v75->m_maxSilhouetteSize),
                                   (__m128)LODWORD(v75->m_maxSilhouetteSize),
                                   0);
        hkaiAbstractFaceCutter::setFace(&v70, v21, &v72->m_up, v54, v11, &regionExpansion, &faceVertices, &indexRemap);
      }
      v37 = 0;
      if ( v56 > 0 )
      {
        v38 = 0i64;
        v39 = 0i64;
        do
        {
          if ( v60 <= v37 )
            v40 = -1;
          else
            v40 = *(_DWORD *)&v59[v39];
          hkaiAbstractFaceCutter::addSilhouette(&v70, *(hkVector4f **)&v55[v38], *(_DWORD *)&v55[v38 + 8], v40);
          ++v37;
          v39 += 4i64;
          v38 += 16i64;
        }
        while ( v37 < v56 );
      }
      hkaiAbstractFaceCutter::computeConvexDecomposition(&v70, v69, &faceVertices, &indexRemap);
      v41 = indexRemap.m_size;
      v42 = (char *)p;
      if ( p == indexRemap.m_data )
        v41 = 0;
      indexRemap.m_size = v41;
      v43 = (4 * v64 + 127) & 0xFFFFFF80;
      v44 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v45 = (v43 + 15) & 0xFFFFFFF0;
      if ( v43 > v44->m_slabSize || &v42[v45] != v44->m_cur || v44->m_firstNonLifoEnd == v42 )
        hkLifoAllocator::slowBlockFree(v44, v42, v45);
      else
        v44->m_cur = v42;
      indexRemap.m_size = 0;
      if ( indexRemap.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          indexRemap.m_data,
          4 * indexRemap.m_capacityAndFlags);
      v46 = faceVertices.m_size;
      v47 = (char *)v66;
      indexRemap.m_data = 0i64;
      if ( v66 == faceVertices.m_data )
        v46 = 0;
      indexRemap.m_capacityAndFlags = 2147483648;
      faceVertices.m_size = v46;
      v48 = (16 * v67 + 127) & 0xFFFFFF80;
      v49 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v50 = (v48 + 15) & 0xFFFFFFF0;
      if ( v48 > v49->m_slabSize || &v47[v50] != v49->m_cur || v49->m_firstNonLifoEnd == v47 )
        hkLifoAllocator::slowBlockFree(v49, v47, v50);
      else
        v49->m_cur = v47;
      faceVertices.m_size = 0;
      if ( faceVertices.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          faceVertices.m_data,
          16 * faceVertices.m_capacityAndFlags);
      faceVertices.m_data = 0i64;
      faceVertices.m_capacityAndFlags = 2147483648;
      v60 = 0;
      if ( v61 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v59,
          4 * v61);
      v59 = 0i64;
      v61 = 2147483648;
      v51 = v56 - 1;
      if ( v56 - 1 >= 0 )
      {
        v52 = &v55[16 * (v56 - 1) + 12];
        do
        {
          v53 = *(_DWORD *)v52;
          *((_DWORD *)v52 - 1) = 0;
          if ( v53 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              *(void **)(v52 - 12),
              16 * v53);
          *(_QWORD *)(v52 - 12) = 0i64;
          *(_DWORD *)v52 = 2147483648;
          v52 -= 16;
          --v51;
        }
        while ( v51 >= 0 );
      }
      v56 = 0;
      if ( v57 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v55,
          16 * v57);
      v6 = v73;
      v7 = v75;
      v8 = v74;
      v9 = v58 + 1;
      v10 = v68 + 4;
      v55 = 0i64;
      v57 = 2147483648;
      v58 = v9;
      v68 += 4i64;
    }
    while ( v9 < v73->m_size );
  }
  hkaiAbstractFaceCutter::~hkaiAbstractFaceCutter(&v70);
}

// File Line: 434
// RVA: 0xBF0FE0
void __fastcall hkaiNavMeshCutter::intersectMeshWithSilhouettesMT(hkaiNavMeshCutter *this, hkArrayBase<unsigned int> *faceKeys, hkaiNavMeshSilhouetteSelector *selector, hkaiSilhouetteGenerationParameters *genParams, hkJobQueue *jobQueue, hkJobThreadPool *threadPool, hkArrayBase<hkaiFaceCutResults> *results)
{
  hkaiSilhouetteGenerationParameters *v7; // rbp
  hkaiNavMeshSilhouetteSelector *v8; // r15
  hkArrayBase<unsigned int> *v9; // rsi
  hkaiNavMeshCutter *v10; // r13
  int v11; // ebx
  __int64 v12; // r14
  unsigned int *v13; // rax
  __int64 v14; // rdx
  hkJob job; // [rsp+20h] [rbp-A8h]
  __int128 v16; // [rsp+30h] [rbp-98h]
  __int64 v17; // [rsp+40h] [rbp-88h]
  int v18; // [rsp+48h] [rbp-80h]
  __int64 v19; // [rsp+50h] [rbp-78h]
  int v20; // [rsp+58h] [rbp-70h]
  int v21; // [rsp+5Ch] [rbp-6Ch]
  __int128 v22; // [rsp+60h] [rbp-68h]
  __int64 v23; // [rsp+70h] [rbp-58h]
  char v24; // [rsp+78h] [rbp-50h]
  char v25; // [rsp+79h] [rbp-4Fh]
  __int128 v26; // [rsp+80h] [rbp-48h]

  v7 = genParams;
  v8 = selector;
  v9 = faceKeys;
  v10 = this;
  v11 = 0;
  if ( faceKeys->m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      v17 = 0i64;
      v19 = 0i64;
      v13 = v9->m_data;
      v22 = 0i64;
      _mm_store_si128((__m128i *)&v26, (__m128i)0i64);
      _mm_store_si128((__m128i *)&v16, (__m128i)0i64);
      job.m_threadAffinity = -1;
      v20 = -1;
      v21 = -1;
      *(_WORD *)&job.m_jobSubType = 2816;
      job.m_jobSpuType.m_storage = 1;
      job.m_size = 112;
      v18 = -1;
      v23 = 0i64;
      v24 = 0;
      v14 = v13[v12];
      *((_QWORD *)&v26 + 1) = v7;
      *(_QWORD *)&v26 = &results->m_data[v11];
      v25 = v10->m_useNewCutter.m_bool;
      v8->vfptr->setupJobForFace(v8, v14, (hkaiNavMeshCutFaceJob *)&job);
      hkJobQueue::addJob(jobQueue, &job, 0);
      ++v11;
      ++v12;
    }
    while ( v11 < v9->m_size );
  }
  ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, signed __int64))threadPool->vfptr[5].__first_virtual_table_function__)(
    threadPool,
    jobQueue,
    11i64);
  hkJobQueue::processAllJobs(jobQueue, 1);
  ((void (__fastcall *)(hkJobThreadPool *))threadPool->vfptr[2].__vecDelDtor)(threadPool);
}

// File Line: 459
// RVA: 0xBEE5D0
signed __int64 __fastcall hkaiNavMeshCutter::getCutKeysFromOriginal(hkaiNavMeshCutter *this, unsigned int origKey, hkArray<unsigned int,hkContainerHeapAllocator> *cutOut)
{
  hkArray<unsigned int,hkContainerHeapAllocator> *v3; // rbx
  unsigned int v4; // er12
  unsigned int v5; // er15
  hkaiNavMeshCutter::MeshInfo *v6; // rbp
  signed __int64 v7; // rsi
  signed __int64 v8; // r14
  unsigned int v9; // edi

  v3 = cutOut;
  v4 = origKey >> 22;
  v5 = origKey & 0x3FFFFF;
  v6 = &this->m_meshInfos.m_data[origKey >> 22];
  v7 = v6->m_magic.m_data[origKey & 0x3FFFFF];
  if ( (signed int)v7 < 0 )
    return 0i64;
  if ( (signed int)v7 < v6->m_magic.m_size )
  {
    v8 = v7;
    do
    {
      if ( v6->m_magic.m_data[v8] != v5 )
        break;
      v9 = v7 | (v4 << 22);
      if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 4);
      LODWORD(v7) = v7 + 1;
      v3->m_data[v3->m_size++] = v9;
      ++v8;
    }
    while ( (signed int)v7 < v6->m_magic.m_size );
  }
  return 1i64;
}

// File Line: 491
// RVA: 0xBEE590
signed __int64 __fastcall hkaiNavMeshCutter::getFirstCutKeyFromOriginal(hkaiNavMeshCutter *this, unsigned int orig)
{
  unsigned int v2; // eax
  signed int v3; // edx
  unsigned int v4; // eax
  hkaiNavMeshCutter::MeshInfo *v5; // r8
  int v6; // er8
  signed __int64 result; // rax

  v2 = orig;
  v3 = orig & 0x3FFFFF;
  v4 = v2 >> 22;
  v5 = &this->m_meshInfos.m_data[v4];
  if ( v3 >= v5->m_originalNumFaces || (v6 = v5->m_magic.m_data[v3], v6 < 0) )
    result = 0xFFFFFFFFi64;
  else
    result = v6 | (v4 << 22);
  return result;
}

// File Line: 514
// RVA: 0xBEE6B0
_BOOL8 __fastcall hkaiNavMeshCutter::getCutKeyRangeFromOriginal(hkaiNavMeshCutter *this, unsigned int origKey, int *faceStartOut, int *faceEndOut)
{
  int *v4; // rbx
  unsigned int v5; // er10
  int *v6; // rdi
  hkaiNavMeshCutter::MeshInfo *v7; // r11
  __int64 v8; // r8
  __int64 v9; // r9
  __int64 v10; // rax
  int *v11; // rdx
  _BOOL8 result; // rax

  v4 = faceStartOut;
  v5 = origKey & 0x3FFFFF;
  v6 = faceEndOut;
  v7 = &this->m_meshInfos.m_data[origKey >> 22];
  v8 = v7->m_magic.m_data[origKey & 0x3FFFFF];
  if ( (signed int)v8 < 0 )
  {
    *v4 = -1;
    *faceEndOut = -1;
    result = (_DWORD)v8 == -2;
  }
  else
  {
    *v4 = v8;
    v9 = v7->m_magic.m_size;
    v10 = v8;
    if ( v8 < v9 )
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
      while ( v10 < v9 );
    }
    *v6 = v8 - 1;
    result = 1i64;
  }
  return result;
}

// File Line: 548
// RVA: 0xBEE760
__int64 __fastcall hkaiNavMeshCutter::getNumCutKeysFromOriginal(hkaiNavMeshCutter *this, unsigned int origKey)
{
  __int64 v2; // r8
  signed int v3; // er9
  unsigned int v4; // edx
  hkaiNavMeshCutter::MeshInfo *v5; // r8
  int *v6; // r10
  __int64 v7; // rcx
  __int64 v8; // r8
  int *v9; // rax

  v2 = origKey >> 22;
  v3 = origKey & 0x3FFFFF;
  v4 = 0;
  v5 = &this->m_meshInfos.m_data[v2];
  v6 = v5->m_magic.m_data;
  v7 = v6[v3];
  if ( (signed int)v7 >= 0 )
  {
    v8 = v5->m_magic.m_size;
    if ( v7 < v8 )
    {
      v9 = &v6[v7];
      do
      {
        if ( *v9 != v3 )
          break;
        ++v7;
        ++v4;
        ++v9;
      }
      while ( v7 < v8 );
    }
  }
  return v4;
}

// File Line: 571
// RVA: 0xBEE7C0
signed __int64 __fastcall hkaiNavMeshCutter::getOriginalFromCutKey(hkaiNavMeshCutter *this, unsigned int cutFaceKey)
{
  unsigned int v2; // er8
  signed int v3; // edx
  unsigned int v4; // er8
  hkaiNavMeshCutter::MeshInfo *v5; // rax
  signed __int64 result; // rax

  v2 = cutFaceKey;
  v3 = cutFaceKey & 0x3FFFFF;
  v4 = v2 >> 22;
  v5 = &this->m_meshInfos.m_data[v4];
  if ( v3 >= v5->m_originalNumFaces )
    result = (v4 << 22) | v5->m_magic.m_data[v3];
  else
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 589
// RVA: 0xBF26B0
void __fastcall getUpdatedSections(hkArrayBase<unsigned int> *updatedFaceKeys, hkArray<int,hkContainerTempAllocator> *updatedSections)
{
  hkArrayBase<unsigned int> *v2; // r15
  int v3; // esi
  signed int v4; // ecx
  hkArray<int,hkContainerTempAllocator> *v5; // rbx
  __int64 v6; // r14
  signed int v7; // edi

  v2 = updatedFaceKeys;
  v3 = 0;
  v4 = -1;
  v5 = updatedSections;
  if ( v2->m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      v7 = v2->m_data[v6] >> 22;
      if ( v7 != v4 )
      {
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v5, 4);
        v5->m_data[v5->m_size++] = v7;
        v4 = v7;
      }
      ++v3;
      ++v6;
    }
    while ( v3 < v2->m_size );
  }
}

// File Line: 617
// RVA: 0xBEDED0
signed __int64 __usercall hkaiNavMeshCutter::cutSilhouettesIncremental@<rax>(hkaiNavMeshCutter *this@<rcx>, hkaiNavMeshSilhouetteSelector *selector@<rdx>, hkaiSilhouetteGenerationParameters *genParams@<r8>, hkArray<unsigned int,hkContainerTempAllocator> *cutFaceKeys@<r9>, hkaiSilhouetteGenerationParameters *a5@<rbx>, hkArray<unsigned int,hkContainerTempAllocator> *uncutFaceKeys, hkBitField *sectionsToStep, hkJobQueue *jobQueue, hkJobThreadPool *threadPool)
{
  hkaiNavMeshCutter *v9; // r14
  hkArray<unsigned int,hkContainerTempAllocator> *v10; // rdi
  hkaiSilhouetteGenerationParameters *v11; // r15
  hkaiNavMeshSilhouetteSelector *v12; // r13
  _QWORD *v13; // rax
  unsigned __int64 v14; // r9
  _QWORD *v15; // r10
  unsigned __int64 v16; // rax
  hkArrayBase<unsigned int> *v17; // rsi
  int v18; // er8
  __int64 i; // r9
  const unsigned int *v20; // r11
  unsigned int v21; // er10
  hkaiNavMeshInstance *v22; // rax
  char v23; // cl
  __int64 *v24; // rax
  __int64 v25; // rax
  int v26; // eax
  __int64 v27; // r12
  int v28; // er15
  unsigned int v29; // ebx
  __int64 v30; // r10
  int v31; // edx
  __int64 v32; // rcx
  unsigned int *v33; // r9
  unsigned int *v34; // rax
  __int64 v35; // r8
  int v36; // edx
  __int64 v37; // rcx
  unsigned int *v38; // rax
  bool v39; // zf
  hkaiStreamingCollection *v40; // rcx
  int v41; // ebx
  _QWORD *v42; // rax
  _QWORD *v43; // rcx
  _QWORD *v44; // r8
  unsigned __int64 v45; // rax
  signed __int64 v46; // rcx
  int v47; // er9
  const unsigned int *v48; // r8
  hkaiStreamingCollection *v49; // rcx
  int v50; // ebx
  char *v51; // rax
  int v52; // edx
  int v53; // er9
  signed __int64 v54; // rcx
  int v55; // eax
  __int64 v56; // rdx
  _QWORD *v57; // rcx
  hkJobQueue *v58; // rsi
  hkJobQueue *v59; // rbx
  _QWORD *v60; // r8
  _QWORD *v61; // rcx
  unsigned __int64 v62; // rax
  signed __int64 v63; // rcx
  _QWORD *v64; // r8
  _QWORD *v65; // rcx
  unsigned __int64 v66; // rax
  signed __int64 v67; // rcx
  _QWORD *v68; // rax
  _QWORD *v69; // rcx
  _QWORD *v70; // r8
  unsigned __int64 v71; // rax
  signed __int64 v72; // rcx
  _QWORD *v73; // rax
  _QWORD *v74; // rcx
  _QWORD *v75; // r8
  unsigned __int64 v76; // rax
  signed __int64 v77; // rcx
  hkArrayBase<unsigned int> cutFaceKeysa; // [rsp+38h] [rbp-59h]
  hkArray<unsigned int,hkContainerTempAllocator> forceRecutFaceKeys; // [rsp+48h] [rbp-49h]
  char *array; // [rsp+58h] [rbp-39h]
  int v82; // [rsp+60h] [rbp-31h]
  int v83; // [rsp+64h] [rbp-2Dh]
  hkArray<int,hkContainerTempAllocator> updatedSections; // [rsp+68h] [rbp-29h]
  hkaiNavMeshCutter::SavedConnectivity tempConnectivity; // [rsp+78h] [rbp-19h]
  char retaddr; // [rsp+D8h] [rbp+47h]
  hkaiSilhouetteGenerationParameters *v87; // [rsp+E8h] [rbp+57h]
  hkArray<unsigned int,hkContainerTempAllocator> *params; // [rsp+F8h] [rbp+67h]

  v9 = this;
  v10 = cutFaceKeys;
  v11 = genParams;
  v12 = selector;
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = v13[1];
  v15 = v13;
  if ( v14 < v13[3] )
  {
    *(_QWORD *)v14 = "LtcutSilhouettes";
    *(_QWORD *)(v14 + 16) = "StgetUpdatedFaces";
    v16 = __rdtsc();
    *(_DWORD *)(v14 + 8) = v16;
    v15[1] = v14 + 24;
  }
  v17 = (hkArrayBase<unsigned int> *)&params->m_data;
  v12->vfptr->getUpdatedFaces(v12, v9, v10, params, (hkBitField *)uncutFaceKeys);
  v18 = v17->m_size - 1;
  for ( i = v18; i >= 0; --i )
  {
    v20 = v17->m_data;
    v21 = v17->m_data[i];
    v22 = v9->m_streamingCollection.m_pntr->m_instances.m_data[v17->m_data[i] >> 22].m_instancePtr;
    if ( v22->m_faceFlags.m_size )
    {
      v23 = v22->m_faceFlags.m_data[v21 & 0x3FFFFF].m_storage;
      v24 = (__int64 *)&params;
      LOBYTE(params) = v23;
    }
    else
    {
      retaddr = 0;
      v24 = (__int64 *)&retaddr;
    }
    if ( !(*(_BYTE *)v24 & 1) )
    {
      v25 = --v17->m_size;
      if ( (_DWORD)v25 != v18 )
        v20[i] = v20[v25];
    }
    --v18;
  }
  v26 = v9->m_forceRecutFaceKeys.m_size;
  v27 = 0i64;
  v87 = a5;
  if ( !v26 )
    goto LABEL_33;
  v28 = 0;
  if ( v26 <= 0 )
    goto LABEL_32;
  do
  {
    v29 = *(unsigned int *)((char *)v9->m_forceRecutFaceKeys.m_data + v27);
    if ( !v9->m_streamingCollection.m_pntr->m_instances.m_data[*(unsigned int *)((char *)v9->m_forceRecutFaceKeys.m_data
                                                                               + v27) >> 22].m_instancePtr )
      goto LABEL_30;
    v30 = v17->m_size;
    v31 = 0;
    v32 = 0i64;
    if ( (signed int)v30 > 0 )
    {
      v33 = v17->m_data;
      v34 = v17->m_data;
      while ( *v34 != v29 )
      {
        ++v32;
        ++v31;
        ++v34;
        if ( v32 >= v30 )
          goto LABEL_18;
      }
      if ( v32 != -1 )
      {
        v17->m_size = v30 - 1;
        if ( (_DWORD)v30 - 1 != v31 )
          v33[v32] = v33[(signed int)v30 - 1];
LABEL_27:
        if ( v10->m_size == (v10->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v10, 4);
        v10->m_data[v10->m_size++] = v29;
        goto LABEL_30;
      }
    }
LABEL_18:
    v35 = v10->m_size;
    v36 = 0;
    v37 = 0i64;
    if ( v35 <= 0 )
      goto LABEL_27;
    v38 = v10->m_data;
    while ( *v38 != v29 )
    {
      ++v37;
      ++v36;
      ++v38;
      if ( v37 >= v35 )
        goto LABEL_27;
    }
    if ( v36 == -1 )
      goto LABEL_27;
LABEL_30:
    ++v28;
    v27 += 4i64;
  }
  while ( v28 < v9->m_forceRecutFaceKeys.m_size );
  LODWORD(v27) = 0;
LABEL_32:
  v11 = v87;
  v9->m_forceRecutFaceKeys.m_size = v27;
LABEL_33:
  v39 = v10->m_size == 0;
  updatedSections.m_data = 0i64;
  updatedSections.m_size = 0;
  updatedSections.m_capacityAndFlags = 2147483648;
  if ( !v39 || v17->m_size )
  {
    v40 = v9->m_streamingCollection.m_pntr;
    LOBYTE(params) = 1;
    v41 = hkaiUserEdgeUtils::removeUserEdgesFromFaces(
            v40,
            (hkArrayBase<unsigned int> *)&v10->m_data,
            (hkaiUserEdgeUtils::RemoveParameters *)&params);
    v42 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v43 = (_QWORD *)v42[1];
    v44 = v42;
    if ( (unsigned __int64)v43 < v42[3] )
    {
      *v43 = "Stuncut";
      v45 = __rdtsc();
      v46 = (signed __int64)(v43 + 2);
      *(_DWORD *)(v46 - 8) = v45;
      v44[1] = v46;
    }
    v47 = v10->m_size;
    v48 = v10->m_data;
    cutFaceKeysa.m_data = 0i64;
    cutFaceKeysa.m_size = 0;
    cutFaceKeysa.m_capacityAndFlags = 2147483648;
    hkArrayBase<unsigned int>::_append(
      &cutFaceKeysa,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      v48,
      v47);
    hkArrayBase<unsigned int>::_append(
      &cutFaceKeysa,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      v17->m_data,
      v17->m_size);
    if ( cutFaceKeysa.m_size > 1 )
      hkAlgorithm::quickSortRecursive<unsigned int,hkAlgorithm::less<unsigned int>>(
        cutFaceKeysa.m_data,
        0,
        cutFaceKeysa.m_size - 1,
        0);
    hkaiNavMeshCutter::SavedConnectivity::SavedConnectivity(&tempConnectivity);
    forceRecutFaceKeys.m_data = 0i64;
    forceRecutFaceKeys.m_size = 0;
    forceRecutFaceKeys.m_capacityAndFlags = 2147483648;
    hkaiNavMeshCutter::calcNewConnectivity(v9, v17, &cutFaceKeysa, &tempConnectivity, &forceRecutFaceKeys);
    if ( forceRecutFaceKeys.m_size )
    {
      hkArrayBase<unsigned int>::_append(
        (hkArrayBase<unsigned int> *)&v10->m_data,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        forceRecutFaceKeys.m_data,
        forceRecutFaceKeys.m_size);
      hkArrayBase<unsigned int>::_append(
        &cutFaceKeysa,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        forceRecutFaceKeys.m_data,
        forceRecutFaceKeys.m_size);
      v49 = v9->m_streamingCollection.m_pntr;
      LOBYTE(params) = 1;
      v41 += hkaiUserEdgeUtils::removeUserEdgesFromFaces(
               v49,
               (hkArrayBase<unsigned int> *)&forceRecutFaceKeys.m_data,
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
      v9,
      (hkArrayBase<int> *)&updatedSections.m_data,
      &cutFaceKeysa,
      (hkaiNavMeshUtils::RemoveOwnedFacesMode)(v41 == 0));
    hkaiNavMeshCutter::restoreConnectivity(
      v9->m_streamingCollection.m_pntr,
      (hkArrayBase<unsigned int> *)&forceRecutFaceKeys.m_data,
      &tempConnectivity);
    hkaiNavMeshCutter::SavedConnectivity::append(&v9->m_connectivityInfo, &tempConnectivity);
    forceRecutFaceKeys.m_size = v27;
    if ( forceRecutFaceKeys.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        forceRecutFaceKeys.m_data,
        4 * forceRecutFaceKeys.m_capacityAndFlags);
    forceRecutFaceKeys.m_data = 0i64;
    forceRecutFaceKeys.m_capacityAndFlags = 2147483648;
    hkaiNavMeshCutter::SavedConnectivity::~SavedConnectivity(&tempConnectivity);
    cutFaceKeysa.m_size = v27;
    if ( cutFaceKeysa.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        cutFaceKeysa.m_data,
        4 * cutFaceKeysa.m_capacityAndFlags);
    v50 = v10->m_size;
    v51 = 0i64;
    v52 = 0;
    array = 0i64;
    v82 = 0;
    v83 = 2147483648;
    if ( v50 > 0 )
    {
      v53 = v50;
      if ( v50 < 0 )
        v53 = v27;
      hkArrayUtil::_reserve(
        (hkResult *)&params,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        &array,
        v53,
        32);
      v52 = v82;
      v51 = array;
    }
    v54 = (signed __int64)&v51[32 * v52];
    v55 = v50 - v52;
    v56 = v50 - v52;
    if ( v55 > 0 )
    {
      v57 = (_QWORD *)(v54 + 24);
      do
      {
        if ( v57 != (_QWORD *)24 )
        {
          *((_BYTE *)v57 - 8) = 0;
          *v57 = 0i64;
        }
        v57 += 4;
        --v56;
      }
      while ( v56 );
    }
    v58 = (hkJobQueue *)sectionsToStep;
    v82 = v50;
    if ( sectionsToStep && (v59 = jobQueue) != 0i64 )
    {
      v60 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v61 = (_QWORD *)v60[1];
      if ( (unsigned __int64)v61 < v60[3] )
      {
        *v61 = "StintersectMT";
        v62 = __rdtsc();
        v63 = (signed __int64)(v61 + 2);
        *(_DWORD *)(v63 - 8) = v62;
        v60[1] = v63;
      }
      hkaiNavMeshCutter::intersectMeshWithSilhouettesMT(
        v9,
        (hkArrayBase<unsigned int> *)&v10->m_data,
        v12,
        v11,
        v58,
        (hkJobThreadPool *)v59,
        (hkArrayBase<hkaiFaceCutResults> *)&array);
    }
    else
    {
      v64 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v65 = (_QWORD *)v64[1];
      if ( (unsigned __int64)v65 < v64[3] )
      {
        *v65 = "StintersectST";
        v66 = __rdtsc();
        v67 = (signed __int64)(v65 + 2);
        *(_DWORD *)(v67 - 8) = v66;
        v64[1] = v67;
      }
      hkaiNavMeshCutter::intersectMeshWithSilhouettes(
        v9,
        (hkArrayBase<unsigned int> *)&v10->m_data,
        v12,
        v11,
        (hkArrayBase<hkaiFaceCutResults> *)&array);
    }
    hkaiNavMeshCutter::applyCutResults(
      v9,
      (hkArrayBase<int> *)&updatedSections.m_data,
      (hkArray<hkaiFaceCutResults,hkContainerTempAllocator> *)&array,
      v10);
    v82 = v27;
    if ( v83 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        32 * v83);
  }
  v68 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v69 = (_QWORD *)v68[1];
  v70 = v68;
  if ( (unsigned __int64)v69 < v68[3] )
  {
    *v69 = "Streset clearance cache";
    v71 = __rdtsc();
    v72 = (signed __int64)(v69 + 2);
    *(_DWORD *)(v72 - 8) = v71;
    v70[1] = v72;
  }
  hkaiNavMeshCutter::resetClearanceForCutFaces(
    v9,
    (hkArrayBase<int> *)&updatedSections.m_data,
    (hkArrayBase<unsigned int> *)&v10->m_data);
  updatedSections.m_size = v27;
  if ( updatedSections.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      updatedSections.m_data,
      4 * updatedSections.m_capacityAndFlags);
  updatedSections.m_data = 0i64;
  updatedSections.m_capacityAndFlags = 2147483648;
  v73 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v74 = (_QWORD *)v73[1];
  v75 = v73;
  if ( (unsigned __int64)v74 < v73[3] )
  {
    *v74 = "lt";
    v76 = __rdtsc();
    v77 = (signed __int64)(v74 + 2);
    *(_DWORD *)(v77 - 8) = v76;
    v75[1] = v77;
  }
  return 1i64;
}

// File Line: 758
// RVA: 0xBEF6E0
void __fastcall hkaiNavMeshCutter::gatherCutEdgesFromCutFaces(hkaiNavMeshCutter *this, unsigned int originalEdgeKey, hkArrayBase<unsigned int> *cutFaceKeys, hkArray<hkaiNavMeshCutter::FaceEdgePair,hkContainerTempAllocator> *cutPairs)
{
  hkArrayBase<unsigned int> *v4; // rdi
  hkArray<hkaiNavMeshCutter::FaceEdgePair,hkContainerTempAllocator> *v5; // rsi
  hkaiNavMeshInstance *v6; // rbp
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // r14
  int v8; // er13
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v9; // r8
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v10; // r9
  signed __int64 v11; // rcx
  int index; // er12
  hkaiNavMesh::Face *v13; // rax
  int v14; // ebx
  hkaiNavMesh::Face *v15; // r15
  __int64 v16; // r14
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v17; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v18; // rcx
  __int64 v19; // rdi
  hkaiNavMesh::Edge *v20; // rax
  unsigned __int16 v21; // r8
  __int64 v22; // rdx
  hkaiNavMeshCutter::FaceEdgePair *v23; // r8
  int v24; // eax
  bool v25; // sf
  unsigned __int8 v26; // of
  int v27; // [rsp+30h] [rbp-48h]
  __int64 v28; // [rsp+38h] [rbp-40h]
  unsigned int v29; // [rsp+80h] [rbp+8h]
  unsigned int v30; // [rsp+88h] [rbp+10h]
  hkArrayBase<unsigned int> *v31; // [rsp+90h] [rbp+18h]

  v31 = cutFaceKeys;
  v4 = cutFaceKeys;
  v5 = cutPairs;
  v29 = originalEdgeKey >> 22;
  v6 = this->m_streamingCollection.m_pntr->m_instances.m_data[originalEdgeKey >> 22].m_instancePtr;
  instanceMap = &v6->m_faceMap;
  v8 = 0;
  v27 = 0;
  v30 = (originalEdgeKey & 0x3FFFFF)
      - hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
          v6->m_originalFaces,
          v6->m_numOriginalFaces,
          &v6->m_instancedFaces,
          &v6->m_ownedFaces,
          &v6->m_faceMap,
          this->m_meshInfos.m_data[originalEdgeKey >> 22].m_magic.m_data[*cutFaceKeys->m_data & 0x3FFFFF])->m_startEdgeIndex;
  if ( v4->m_size > 0 )
  {
    v11 = 0i64;
    v28 = 0i64;
    do
    {
      index = *(unsigned int *)((_BYTE *)v4->m_data + v11) & 0x3FFFFF;
      v13 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
              v6->m_originalFaces,
              v6->m_numOriginalFaces,
              v9,
              v10,
              instanceMap,
              index);
      v14 = v13->m_startEdgeIndex;
      v15 = v13;
      v16 = v13->m_startEdgeIndex;
      if ( v13->m_startEdgeIndex < v13->m_startEdgeIndex + v13->m_numEdges )
      {
        v17 = &v6->m_ownedEdges;
        v18 = &v6->m_instancedEdges;
        do
        {
          v19 = v6->m_numOriginalEdges;
          v20 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__8(
                  v6->m_originalEdges,
                  v6->m_numOriginalEdges,
                  v18,
                  v17,
                  &v6->m_edgeMap,
                  v14);
          if ( v14 < (signed int)v19 )
            v21 = -1;
          else
            v21 = v6->m_cuttingInfo.m_data[v16 - v19];
          if ( v20->m_flags.m_storage & 4 && v21 == v30 )
          {
            if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v5, 8);
            v22 = v5->m_size;
            v23 = &v5->m_data[v22];
            v5->m_size = v22 + 1;
            v23->m_edgeKey = v14 | (v29 << 22);
            v23->m_faceKey = index | (v29 << 22);
          }
          ++v14;
          ++v16;
          v24 = v15->m_startEdgeIndex + v15->m_numEdges;
          v18 = &v6->m_instancedEdges;
          v26 = __OFSUB__(v14, v24);
          v25 = v14 - v24 < 0;
          v17 = &v6->m_ownedEdges;
        }
        while ( v25 ^ v26 );
        v8 = v27;
        v4 = v31;
        v10 = &v6->m_ownedFaces;
        v9 = &v6->m_instancedFaces;
      }
      ++v8;
      instanceMap = &v6->m_faceMap;
      v11 = v28 + 4;
      v27 = v8;
      v28 += 4i64;
    }
    while ( v8 < v4->m_size );
  }
}

// File Line: 799
// RVA: 0xBEF2E0
void __fastcall hkaiNavMeshCutter::gatherCutEdges(hkaiNavMeshCutter *this, unsigned int originalEdgeKey, unsigned int originalFaceKey, hkArray<hkaiNavMeshCutter::FaceEdgePair,hkContainerTempAllocator> *cutPairs, hkaiNavMeshCutter::GatherCutEdgesMode gatherMode)
{
  unsigned int v5; // ebx
  hkaiNavMeshCutter *v6; // r14
  signed int v7; // er12
  hkArray<hkaiNavMeshCutter::FaceEdgePair,hkContainerTempAllocator> *v8; // rsi
  hkaiNavMeshInstance *v9; // rbp
  unsigned int v10; // edi
  unsigned int v11; // er15
  hkaiNavMesh::Face *v12; // rax
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v13; // r9
  int v14; // er11
  signed __int64 v15; // r8
  __int64 v16; // rdx
  hkaiNavMeshCutter::FaceEdgePair *v17; // r8
  __int64 index; // r12
  int v19; // edx
  __int64 v20; // r13
  hkaiNavMesh::Face *v21; // r15
  int v22; // ebx
  __int64 v23; // r14
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v25; // rcx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v26; // rdx
  __int64 v27; // rdi
  hkaiNavMesh::Edge *v28; // rax
  signed __int16 v29; // dx
  __int64 v30; // rdx
  hkaiNavMeshCutter::FaceEdgePair *v31; // r8
  int v32; // eax
  bool v33; // sf
  unsigned __int8 v34; // of
  unsigned int v35; // [rsp+30h] [rbp-58h]
  __int64 v36; // [rsp+38h] [rbp-50h]
  signed __int64 v37; // [rsp+38h] [rbp-50h]
  __int64 v38; // [rsp+40h] [rbp-48h]
  __int64 i; // [rsp+48h] [rbp-40h]
  int v40; // [rsp+90h] [rbp+8h]
  char v41; // [rsp+98h] [rbp+10h]
  unsigned int v42; // [rsp+A0h] [rbp+18h]

  v5 = originalEdgeKey;
  v6 = this;
  v35 = originalEdgeKey >> 22;
  v7 = originalFaceKey & 0x3FFFFF;
  v36 = originalEdgeKey >> 22;
  v8 = cutPairs;
  v9 = this->m_streamingCollection.m_pntr->m_instances.m_data[v36].m_instancePtr;
  v10 = originalFaceKey;
  v11 = originalEdgeKey & 0x3FFFFF;
  v42 = originalFaceKey & 0x3FFFFF;
  v12 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
          v9->m_originalFaces,
          v9->m_numOriginalFaces,
          &v9->m_instancedFaces,
          &v9->m_ownedFaces,
          &v9->m_faceMap,
          originalFaceKey & 0x3FFFFF);
  if ( v9->m_faceFlags.m_size )
    v41 = v9->m_faceFlags.m_data[v7].m_storage;
  else
    v41 = 0;
  v40 = v11 - v12->m_startEdgeIndex;
  v15 = (signed __int64)&v6->m_meshInfos.m_data[v36];
  v37 = (signed __int64)&v6->m_meshInfos.m_data[v36];
  if ( v41 & 1 )
  {
    index = *(signed int *)(*(_QWORD *)(v15 + 16) + 4i64 * v7);
    v19 = v14 + v9->m_ownedFaces.m_size;
    if ( (signed int)index >= 0 )
    {
      v38 = index;
      v20 = index;
      for ( i = v19; v20 < i; v38 = v20 )
      {
        if ( *(_DWORD *)(*(_QWORD *)(v15 + 16) + 4 * v20) != v42 )
          break;
        v21 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
                v9->m_originalFaces,
                v9->m_numOriginalFaces,
                &v9->m_instancedFaces,
                v13,
                &v9->m_faceMap,
                index);
        v22 = v21->m_startEdgeIndex;
        v23 = v21->m_startEdgeIndex;
        if ( v21->m_startEdgeIndex < v21->m_startEdgeIndex + v21->m_numEdges )
        {
          instanceMap = &v9->m_edgeMap;
          v25 = &v9->m_ownedEdges;
          v26 = &v9->m_instancedEdges;
          do
          {
            v27 = v9->m_numOriginalEdges;
            v28 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__8(
                    v9->m_originalEdges,
                    v9->m_numOriginalEdges,
                    v26,
                    v25,
                    instanceMap,
                    v22);
            if ( v28->m_oppositeEdge == -1 || gatherMode != 1 )
            {
              if ( v28->m_flags.m_storage & 4 )
              {
                v29 = v22 < (signed int)v27 ? -1 : v9->m_cuttingInfo.m_data[v23 - v27];
                if ( v29 == (unsigned __int8)v40 )
                {
                  if ( v8->m_size == (v8->m_capacityAndFlags & 0x3FFFFFFF) )
                    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v8, 8);
                  v30 = v8->m_size;
                  v31 = &v8->m_data[v30];
                  v8->m_size = v30 + 1;
                  v31->m_edgeKey = v22 | (v35 << 22);
                  v31->m_faceKey = index | (v35 << 22);
                }
              }
            }
            ++v22;
            ++v23;
            v32 = v21->m_startEdgeIndex + v21->m_numEdges;
            v25 = &v9->m_ownedEdges;
            v26 = &v9->m_instancedEdges;
            v34 = __OFSUB__(v22, v32);
            v33 = v22 - v32 < 0;
            instanceMap = &v9->m_edgeMap;
          }
          while ( v33 ^ v34 );
          v20 = v38;
          v13 = &v9->m_ownedFaces;
        }
        v15 = v37;
        ++v20;
        LODWORD(index) = index + 1;
      }
    }
  }
  else
  {
    if ( v8->m_size == (v8->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v8, 8);
    v16 = v8->m_size;
    v17 = &v8->m_data[v16];
    v8->m_size = v16 + 1;
    v17->m_faceKey = v10;
    v17->m_edgeKey = v5;
  }
}

// File Line: 853
// RVA: 0xBEEB60
void __fastcall hkaiNavMeshCutter::uncutSection(hkaiNavMeshCutter *this, int sectionIndex, bool doChecks)
{
  hkaiStreamingCollection *v3; // rax
  __int64 v4; // r9
  int v5; // er11
  int index; // esi
  __int64 v7; // r12
  unsigned int v8; // edx
  hkaiNavMeshCutter::MeshInfo *v9; // r12
  hkaiStreamingCollection::InstanceInfo *v10; // rax
  hkaiNavMeshInstance *v11; // r13
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v12; // r14
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v13; // r15
  hkResultEnum v14; // eax
  int v15; // ebx
  hkaiNavMesh::Face *v16; // rdi
  int v17; // ebx
  hkaiNavMeshCutter *v18; // rsi
  hkaiNavMesh::Edge *v19; // rax
  unsigned int v20; // er8
  hkaiNavMesh::Edge *v21; // r10
  signed int v22; // ecx
  hkaiNavMeshInstance *v23; // r9
  char *v24; // rax
  int v25; // eax
  int v26; // er8
  signed __int64 v27; // rcx
  hkaiNavMesh::Edge *v28; // rax
  signed __int64 v29; // rdx
  unsigned int *v30; // rdi
  int v31; // er14
  int v32; // er15
  int v33; // er8
  int v34; // edx
  int v35; // ecx
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rax
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v37; // rcx
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v38; // r10
  hkaiNavMesh::Face *v39; // rbx
  int v40; // er12
  hkArray<int,hkContainerHeapAllocator> *v41; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v42; // rcx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v43; // rdx
  hkaiNavMesh::Edge *v44; // rax
  hkaiNavMesh::Edge *v45; // r8
  unsigned int v46; // eax
  signed int v47; // ecx
  hkaiNavMeshInstance *v48; // rax
  char v49; // cl
  char *v50; // rax
  unsigned int v51; // ecx
  signed int v52; // ebx
  unsigned int v53; // esi
  signed int v54; // er9
  int v55; // eax
  unsigned int v56; // edx
  int v57; // eax
  bool v58; // sf
  unsigned __int8 v59; // of
  int v60; // ecx
  hkaiNavMeshCutter *v61; // r13
  __int64 v62; // rsi
  int v63; // er9
  int v64; // eax
  int v65; // eax
  unsigned int *v66; // rax
  int v67; // er14
  signed __int64 v68; // r10
  int v69; // ecx
  signed __int64 v70; // rax
  int v71; // edx
  __int64 v72; // rax
  int v73; // er9
  signed __int64 i; // rcx
  int v75; // edi
  int v76; // esi
  __int64 v77; // rdi
  hkaiStreamingCollection *v78; // rcx
  int v79; // edx
  __int64 j; // r8
  __int64 v81; // rax
  int v82; // er8
  __int64 k; // r9
  __int64 v84; // rax
  char v85; // [rsp+30h] [rbp-39h]
  int v86; // [rsp+34h] [rbp-35h]
  _DWORD *array; // [rsp+38h] [rbp-31h]
  int v88; // [rsp+40h] [rbp-29h]
  int v89; // [rsp+44h] [rbp-25h]
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > v90; // [rsp+48h] [rbp-21h]
  hkArrayBase<int> updatedSections; // [rsp+60h] [rbp-9h]
  hkResult result; // [rsp+70h] [rbp+7h]
  hkaiNavMeshCutter::MeshInfo *v93; // [rsp+78h] [rbp+Fh]
  hkaiNavMesh::Face *v94; // [rsp+80h] [rbp+17h]
  hkaiNavMeshCutter *v95; // [rsp+D0h] [rbp+67h]
  int sectionIndexa; // [rsp+D8h] [rbp+6Fh]
  char v97; // [rsp+E8h] [rbp+7Fh]

  sectionIndexa = sectionIndex;
  v95 = this;
  v3 = this->m_streamingCollection.m_pntr;
  v4 = sectionIndex;
  array = 0i64;
  v5 = 0;
  index = 0;
  v88 = 0;
  v7 = sectionIndex;
  v8 = 2147483648;
  v9 = &this->m_meshInfos.m_data[v7];
  v89 = 2147483648;
  v10 = v3->m_instances.m_data;
  v93 = v9;
  v86 = 0;
  v11 = v10[v4].m_instancePtr;
  if ( v9->m_originalNumFaces > 0 )
  {
    v12 = &v11->m_ownedFaces;
    v13 = &v11->m_instancedFaces;
    v14 = (_DWORD)v4 << 22;
    for ( result.m_enum = (_DWORD)v4 << 22; ; v14 = result.m_enum )
    {
      v15 = index | v14;
      if ( v5 == (v8 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 4);
        v5 = v88;
      }
      array[v5] = v15;
      ++v88;
      v16 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
              v11->m_originalFaces,
              v11->m_numOriginalFaces,
              v13,
              v12,
              &v11->m_faceMap,
              index);
      v17 = v16->m_startEdgeIndex;
      if ( v17 < v17 + v16->m_numEdges )
        break;
LABEL_26:
      v86 = ++index;
      if ( index >= v9->m_originalNumFaces )
        goto LABEL_28;
      v8 = v89;
    }
    v18 = v95;
    while ( 1 )
    {
      v19 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__8(
              v11->m_originalEdges,
              v11->m_numOriginalEdges,
              &v11->m_instancedEdges,
              &v11->m_ownedEdges,
              &v11->m_edgeMap,
              v17);
      v20 = v19->m_oppositeEdge;
      v21 = v19;
      if ( v20 == -1 || !(v19->m_flags.m_storage & 0x40) )
        goto LABEL_24;
      v22 = v20 >> 22;
      if ( v20 == -1 )
        v22 = -1;
      v23 = v18->m_streamingCollection.m_pntr->m_instances.m_data[v22].m_instancePtr;
      if ( v23->m_faceFlags.m_size )
      {
        v24 = &v97;
        v97 = v23->m_faceFlags.m_data[v21->m_oppositeFace & 0x3FFFFF].m_storage;
      }
      else
      {
        v85 = 0;
        v24 = &v85;
      }
      if ( !(*v24 & 2) )
        goto LABEL_24;
      v25 = v23->m_numOriginalEdges;
      v26 = v20 & 0x3FFFFF;
      if ( v26 >= v25 )
        break;
      if ( v23->m_edgeMap.m_size )
        v26 = v23->m_edgeMap.m_data[v26];
      if ( v26 != -1 )
      {
        v27 = v26;
        v28 = v23->m_instancedEdges.m_data;
        goto LABEL_22;
      }
      v29 = 0i64;
LABEL_23:
      *(_DWORD *)(v29 + 12) = -1;
      *(_DWORD *)(v29 + 8) = -1;
LABEL_24:
      if ( ++v17 >= v16->m_startEdgeIndex + v16->m_numEdges )
      {
        index = v86;
        v5 = v88;
        v9 = v93;
        v12 = &v11->m_ownedFaces;
        v13 = &v11->m_instancedFaces;
        goto LABEL_26;
      }
    }
    v27 = v26 - v25;
    v28 = v23->m_ownedEdges.m_data;
LABEL_22:
    v29 = (signed __int64)&v28[v27];
    goto LABEL_23;
  }
LABEL_28:
  v90.m_elem.m_capacityAndFlags = 2147483648;
  v30 = 0i64;
  v31 = 0;
  v90.m_elem.m_data = 0i64;
  v90.m_elem.m_size = 0;
  v32 = 0;
  v90.m_numElems = 0;
  v33 = v9->m_originalNumFaces;
  v34 = v11->m_numOriginalFaces;
  v35 = v11->m_ownedFaces.m_size;
  v86 = v33;
  if ( v33 < v34 + v35 )
  {
    instanceMap = &v11->m_faceMap;
    v37 = &v11->m_ownedFaces;
    v38 = &v11->m_instancedFaces;
    do
    {
      v39 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(v11->m_originalFaces, v34, v38, v37, instanceMap, v33);
      v94 = v39;
      v40 = v39->m_startEdgeIndex;
      if ( v39->m_startEdgeIndex < v39->m_startEdgeIndex + v39->m_numEdges )
      {
        v41 = &v11->m_edgeMap;
        v42 = &v11->m_ownedEdges;
        v43 = &v11->m_instancedEdges;
        do
        {
          v44 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__8(
                  v11->m_originalEdges,
                  v11->m_numOriginalEdges,
                  v43,
                  v42,
                  v41,
                  v40);
          v45 = v44;
          v46 = v44->m_oppositeEdge;
          if ( v46 != -1 && v45->m_flags.m_storage & 0x40 )
          {
            v47 = v46 >> 22;
            if ( v46 == -1 )
              v47 = -1;
            v48 = v95->m_streamingCollection.m_pntr->m_instances.m_data[v47].m_instancePtr;
            if ( v48->m_faceFlags.m_size )
            {
              v49 = v48->m_faceFlags.m_data[v45->m_oppositeFace & 0x3FFFFF].m_storage;
              v50 = &v97;
              v97 = v49;
            }
            else
            {
              v85 = 0;
              v50 = &v85;
            }
            if ( *v50 & 2 )
            {
              v51 = v45->m_oppositeFace;
              v52 = v51 & 0xFFC00000 | v45->m_oppositeFace & 0x3FFFFF;
              if ( v51 == -1 )
                v52 = -1;
              v53 = hkaiNavMeshCutter::getOriginalFromCutKey(v95, v52);
              if ( v53 == -1 )
                v53 = v52;
              if ( 2 * v32 > v31 - 1 )
              {
                hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
                  &v90,
                  &result,
                  2 * v31);
                v32 = v90.m_numElems;
                v31 = v90.m_elem.m_size;
                v30 = v90.m_elem.m_data;
              }
              v54 = 1;
              v55 = (v31 - 1) & -1640531535 * (v53 >> 4);
              v56 = v30[v55];
              if ( v56 != -1 )
              {
                while ( v56 != v53 )
                {
                  v55 = (v31 - 1) & (v55 + 1);
                  v56 = v30[v55];
                  if ( v56 == -1 )
                    goto LABEL_51;
                }
                v54 = 0;
              }
LABEL_51:
              v39 = v94;
              v90.m_numElems = v54 + v32;
              v30[v55] = v53;
              v32 = v90.m_numElems;
              v31 = v90.m_elem.m_size;
              v30 = v90.m_elem.m_data;
            }
          }
          ++v40;
          v42 = &v11->m_ownedEdges;
          v57 = v39->m_startEdgeIndex + v39->m_numEdges;
          v43 = &v11->m_instancedEdges;
          v59 = __OFSUB__(v40, v57);
          v58 = v40 - v57 < 0;
          v41 = &v11->m_edgeMap;
        }
        while ( v58 ^ v59 );
      }
      v34 = v11->m_numOriginalFaces;
      v33 = v86 + 1;
      v60 = v34 + v11->m_ownedFaces.m_size;
      instanceMap = &v11->m_faceMap;
      v59 = __OFSUB__(v86 + 1, v60);
      v58 = v86 + 1 - v60 < 0;
      v37 = &v11->m_ownedFaces;
      ++v86;
      v38 = &v11->m_instancedFaces;
    }
    while ( v58 ^ v59 );
    v9 = v93;
  }
  v61 = v95;
  v62 = v95->m_forceClearanceCalcFaceKeys.m_size;
  v63 = v62 + v32;
  v64 = v95->m_forceClearanceCalcFaceKeys.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v64 < (signed int)v62 + v32 )
  {
    v65 = 2 * v64;
    if ( v63 < v65 )
      v63 = v65;
    hkArrayUtil::_reserve(
      (hkResult *)&v95,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v95->m_forceClearanceCalcFaceKeys,
      v63,
      4);
    v31 = v90.m_elem.m_size;
    v30 = v90.m_elem.m_data;
  }
  v66 = v61->m_forceClearanceCalcFaceKeys.m_data;
  v61->m_forceClearanceCalcFaceKeys.m_size += v32;
  v67 = v31 - 1;
  v68 = (signed __int64)&v66[v62];
  v69 = 0;
  v70 = 0i64;
  if ( v67 >= 0 )
  {
    do
    {
      if ( v30[v70] != -1 )
        break;
      ++v70;
      ++v69;
    }
    while ( v70 <= v67 );
  }
  v71 = v69;
  if ( v69 <= v67 )
  {
    do
    {
      v72 = v71++;
      v68 += 4i64;
      *(_DWORD *)(v68 - 4) = v30[v72];
      v30 = v90.m_elem.m_data;
      v73 = v90.m_elem.m_size - 1;
      for ( i = v71; i <= v73; ++v71 )
      {
        if ( v90.m_elem.m_data[i] != -1 )
          break;
        ++i;
      }
    }
    while ( v71 <= v73 );
  }
  v75 = sectionIndexa;
  hkaiGraphUtils::removeDirectedUserEdgesToSection(v61->m_streamingCollection.m_pntr, sectionIndexa);
  updatedSections.m_data = 0i64;
  updatedSections.m_size = 0;
  updatedSections.m_capacityAndFlags = 2147483648;
  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &updatedSections, 4);
  v76 = 0;
  updatedSections.m_data[updatedSections.m_size] = v75;
  ++updatedSections.m_size;
  if ( v88 > 0 )
  {
    v77 = 0i64;
    do
    {
      v78 = v61->m_streamingCollection.m_pntr;
      LOBYTE(v95) = 0;
      hkaiUserEdgeUtils::removeUserEdgesFromFace(v78, array[v77], (hkaiUserEdgeUtils::RemoveParameters *)&v95);
      ++v76;
      ++v77;
    }
    while ( v76 < v88 );
    v75 = sectionIndexa;
  }
  hkaiNavMeshCutter::removeCutFacesFromOriginals(
    v61,
    &updatedSections,
    (hkArrayBase<unsigned int> *)&array,
    EXIT_IF_NO_FACES_TO_REMOVE);
  v79 = v61->m_forceRecutFaceKeys.m_size - 1;
  for ( j = v79; j >= 0; --j )
  {
    if ( v61->m_forceRecutFaceKeys.m_data[j] >> 22 == v75 )
    {
      v81 = --v61->m_forceRecutFaceKeys.m_size;
      if ( (_DWORD)v81 != v79 )
        v61->m_forceRecutFaceKeys.m_data[j] = v61->m_forceRecutFaceKeys.m_data[v81];
    }
    --v79;
  }
  v82 = v61->m_forceClearanceCalcFaceKeys.m_size - 1;
  for ( k = v82; k >= 0; --k )
  {
    if ( v61->m_forceClearanceCalcFaceKeys.m_data[k] >> 22 == v75 )
    {
      v84 = --v61->m_forceClearanceCalcFaceKeys.m_size;
      if ( (_DWORD)v84 != v82 )
        v61->m_forceClearanceCalcFaceKeys.m_data[k] = v61->m_forceClearanceCalcFaceKeys.m_data[v84];
    }
    --v82;
  }
  hkaiNavMeshCutter::MeshInfo::init(v9, 0i64);
  updatedSections.m_size = 0;
  if ( updatedSections.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      updatedSections.m_data,
      4 * updatedSections.m_capacityAndFlags);
  updatedSections.m_data = 0i64;
  updatedSections.m_capacityAndFlags = 2147483648;
  v90.m_elem.m_size = 0;
  if ( v90.m_elem.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v90.m_elem.m_data,
      4 * v90.m_elem.m_capacityAndFlags);
  v90.m_elem.m_data = 0i64;
  v90.m_elem.m_capacityAndFlags = 2147483648;
  v88 = 0;
  if ( v89 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v89);
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
  hkSimdFloat32 result; // [rsp+30h] [rbp-18h]

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
signed __int64 __fastcall AabbCompare(hkAabb *first, hkAabb *second)
{
  signed __int64 result; // rax

  result = 0i64;
  if ( COERCE_FLOAT(_mm_shuffle_ps(first->m_min.m_quad, first->m_min.m_quad, 0)) < COERCE_FLOAT(
                                                                                     _mm_shuffle_ps(
                                                                                       second->m_min.m_quad,
                                                                                       second->m_min.m_quad,
                                                                                       0)) )
    result = 1i64;
  return result;
}

// File Line: 1024
// RVA: 0xBF2780
void __fastcall simpleAabbMerge(hkArrayBase<hkAabb> *aabbs)
{
  int v1; // er8
  hkArrayBase<hkAabb> *v2; // rbx
  int v3; // er9
  __int64 v4; // r10
  signed __int64 v5; // rcx
  signed __int64 v6; // r11
  __m128 *v7; // rdx
  __m128 *v8; // r8
  __m128 v9; // xmm1
  signed __int64 v10; // rdx
  char *v11; // rax
  signed __int64 v12; // r8
  __int64 v13; // rcx

  v1 = aabbs->m_size;
  v2 = aabbs;
  if ( v1 > 1 )
    hkAlgorithm::quickSortRecursive<hkAabb,unsigned int (*)(hkAabb const &,hkAabb const &)>(
      aabbs->m_data,
      0,
      v1 - 1,
      (unsigned int (__fastcall *)(hkAabb *, hkAabb *))AabbCompare);
  v3 = v2->m_size - 1;
  v4 = v3;
  if ( v3 >= 1i64 )
  {
    v5 = 32i64 * v3;
    do
    {
      v6 = v5 - 32;
      v7 = (__m128 *)((char *)&v2->m_data[-1].m_min.m_quad + v5);
      v8 = (__m128 *)((char *)&v2->m_data->m_min.m_quad + v5);
      if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(*v7, v8[1]), _mm_cmpleps(*v8, v7[1]))) & 7) == 7 )
      {
        v9 = v7[1];
        *v7 = _mm_min_ps(*v7, *v8);
        v7[1] = _mm_max_ps(v9, v8[1]);
        if ( --v2->m_size != v3 )
        {
          v10 = 4i64;
          v11 = (char *)v2->m_data + v5;
          v12 = (char *)&v2->m_data[v2->m_size] - v11;
          do
          {
            v13 = *(_QWORD *)&v11[v12];
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
void __usercall hkaiNavMeshCutter::getFacesForResetByMediator(hkaiNavMeshCutter *this@<rcx>, hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *facesToReset@<rdx>, hkArrayBase<hkAabb> *faceAabbs@<r8>, hkArrayBase<hkAabb> *a4@<rbx>)
{
  hkaiNavMeshCutter *v4; // r13
  hkArrayBase<hkAabb> *v5; // rbx
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *v6; // rdi
  _QWORD *v7; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r9
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  int v12; // er15
  __int64 v13; // r12
  __m128 v14; // xmm6
  hkAabb *v15; // rax
  hkVector4f v16; // xmm1
  int v17; // er14
  __int64 v18; // rsi
  unsigned int v19; // ebx
  int v20; // er8
  unsigned int *v21; // r9
  int v22; // er8
  signed int v23; // er10
  int v24; // ecx
  unsigned int v25; // edx
  unsigned int v26; // ebx
  int v27; // er8
  unsigned int *v28; // r9
  int v29; // er8
  signed int v30; // er10
  int v31; // eax
  unsigned int v32; // edx
  _QWORD *v33; // rax
  _QWORD *v34; // rcx
  _QWORD *v35; // r8
  unsigned __int64 v36; // rax
  signed __int64 v37; // rcx
  hkArray<unsigned int,hkContainerTempAllocator> hits; // [rsp+18h] [rbp-79h]
  hkaiNavMeshQueryMediator::AabbQueryInput input; // [rsp+28h] [rbp-69h]
  hkaiDynamicNavMeshQueryMediator v40; // [rsp+78h] [rbp-19h]
  void *retaddr; // [rsp+F8h] [rbp+67h]
  hkArrayBase<hkAabb> *v42; // [rsp+108h] [rbp+77h]
  hkArrayBase<hkAabb> *result; // [rsp+110h] [rbp+7Fh]

  result = faceAabbs;
  v42 = a4;
  v4 = this;
  v5 = faceAabbs;
  v6 = facesToReset;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)v7[1];
  v9 = v7;
  if ( (unsigned __int64)v8 < v7[3] )
  {
    *v8 = "Ttmediator";
    v10 = __rdtsc();
    v11 = (signed __int64)(v8 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v9[1] = v11;
  }
  hkaiDynamicNavMeshQueryMediator::hkaiDynamicNavMeshQueryMediator(
    &v40,
    v4->m_streamingCollection.m_pntr,
    v4->m_streamingCollection.m_pntr->m_tree.m_pntr,
    v4);
  v12 = 0;
  if ( v5->m_size > 0 )
  {
    v13 = 0i64;
    v14 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      v15 = v5->m_data;
      _mm_store_si128((__m128i *)&input.m_hitFilter, (__m128i)0i64);
      input.m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
      input.m_filterInfo = 0;
      input.m_userData = 0i64;
      input.m_localToWorldTransform = 0i64;
      input.m_aabb.m_max.m_quad = _mm_xor_ps(v14, (__m128)xmmword_141A712A0);
      input.m_aabb.m_min = v15[v13].m_min;
      v16.m_quad = (__m128)v15[v13].m_max;
      hits.m_size = 0;
      hits.m_capacityAndFlags = 2147483648;
      input.m_aabb.m_max = (hkVector4f)v16.m_quad;
      hkaiDynamicNavMeshQueryMediator::queryAabb(&v40, &input, &hits);
      v17 = 0;
      if ( hits.m_size > 0 )
      {
        v18 = 0i64;
        do
        {
          v19 = hits.m_data[v18];
          v20 = v6->m_elem.m_size - 1;
          if ( 2 * v6->m_numElems > v20 )
            hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
              v6,
              (hkResult *)&retaddr,
              2 * v20 + 2);
          v21 = v6->m_elem.m_data;
          v22 = v6->m_elem.m_size - 1;
          v23 = 1;
          v24 = v22 & -1640531535 * (v19 >> 4);
          v25 = v6->m_elem.m_data[v24];
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
          v6->m_numElems += v23;
          v21[v24] = v19;
          v26 = hkaiNavMeshCutter::getOriginalFromCutKey(v4, hits.m_data[v18]);
          if ( v26 != -1 )
          {
            v27 = v6->m_elem.m_size - 1;
            if ( 2 * v6->m_numElems > v27 )
              hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
                v6,
                (hkResult *)&result,
                2 * v27 + 2);
            v28 = v6->m_elem.m_data;
            v29 = v6->m_elem.m_size - 1;
            v30 = 1;
            v31 = v29 & -1640531535 * (v26 >> 4);
            v32 = v6->m_elem.m_data[v31];
            if ( v32 != -1 )
            {
              while ( v32 != v26 )
              {
                v31 = v29 & (v31 + 1);
                v32 = v28[v31];
                if ( v32 == -1 )
                  goto LABEL_22;
              }
              v30 = 0;
            }
LABEL_22:
            v6->m_numElems += v30;
            v28[v31] = v26;
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
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          hits.m_data,
          4 * hits.m_capacityAndFlags);
      ++v12;
      ++v13;
      hits.m_data = 0i64;
      hits.m_capacityAndFlags = 2147483648;
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
    v37 = (signed __int64)(v34 + 2);
    *(_DWORD *)(v37 - 8) = v36;
    v35[1] = v37;
  }
}

// File Line: 1065
// RVA: 0xBF1530
void __fastcall hkaiNavMeshCutter::getFacesForResetByFloodFill(hkaiNavMeshCutter *this, hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *facesToReset, hkArrayBase<unsigned int> *cutFaceKeys, hkArrayBase<hkAabb> *faceAabbs)
{
  hkaiNavMeshCutter *v4; // rdi
  hkArrayBase<hkAabb> *v5; // rsi
  hkArrayBase<unsigned int> *v6; // rbx
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *v7; // r15
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  int v12; // edx
  __int64 v13; // r10
  unsigned int *v14; // r8
  __int64 v15; // r9
  __int64 v16; // rcx
  bool v17; // zf
  unsigned int v18; // eax
  unsigned int *v19; // r9
  unsigned int v20; // er13
  int v21; // er8
  int v22; // ecx
  unsigned int v23; // edx
  int v24; // eax
  __int64 v25; // rbx
  int v26; // er10
  signed int v27; // er11
  int v28; // ecx
  unsigned int v29; // edx
  int v30; // er14
  __int64 v31; // r8
  __int64 v32; // rdx
  __m128 *v33; // rcx
  int v34; // er9
  int v35; // er10
  int v36; // er10
  signed int v37; // er11
  int v38; // ecx
  unsigned int v39; // edx
  _DWORD *v40; // rsi
  __int64 v41; // rdi
  int v42; // er8
  unsigned int v43; // ebx
  unsigned int *v44; // r9
  int v45; // er8
  signed int v46; // er10
  int v47; // ecx
  unsigned int v48; // edx
  int v49; // er8
  unsigned int *v50; // r9
  int v51; // er8
  signed int v52; // er10
  int v53; // ecx
  unsigned int v54; // edx
  unsigned int *v55; // rdi
  __int64 v56; // r12
  signed int *v57; // r15
  __int64 v58; // r14
  int v59; // er9
  signed __int64 v60; // rsi
  __int64 v61; // rcx
  int v62; // edx
  unsigned int v63; // eax
  unsigned int v64; // ebx
  int v65; // er8
  int v66; // ecx
  unsigned int v67; // edx
  int v68; // eax
  int v69; // edx
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > **v70; // rax
  char *v71; // rax
  float v72; // er14
  int v73; // er15
  float v74; // er8
  __int64 v75; // rcx
  hkArray<int,hkContainerHeapAllocator> *v76; // rdx
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v77; // r8
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v78; // r10
  int v79; // er11
  hkaiNavMesh::Face *v80; // r13
  int index; // er12
  hkArray<int,hkContainerHeapAllocator> *v82; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v83; // rcx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v84; // rdx
  hkaiNavMesh::Edge *v85; // rax
  unsigned int v86; // ecx
  signed int v87; // edx
  unsigned int v88; // eax
  int v89; // er8
  unsigned int v90; // ebx
  int v91; // edx
  unsigned int v92; // eax
  int v93; // eax
  signed int v94; // er9
  int v95; // ecx
  int v96; // edx
  int v97; // eax
  bool v98; // sf
  unsigned __int8 v99; // of
  int v100; // er9
  int v101; // ecx
  signed __int64 v102; // rax
  int v103; // ebx
  int v104; // er8
  int v105; // edi
  int v106; // edx
  int v107; // er9
  signed __int64 v108; // rcx
  int v109; // er9
  signed int v110; // er10
  int v111; // ecx
  unsigned int v112; // edx
  _QWORD *v113; // r8
  _QWORD *v114; // rcx
  unsigned __int64 v115; // rax
  signed __int64 v116; // rcx
  hkAabb *instanceMap; // [rsp+20h] [rbp-D8h]
  __int64 array; // [rsp+30h] [rbp-C8h]
  int v119; // [rsp+38h] [rbp-C0h]
  int v120; // [rsp+3Ch] [rbp-BCh]
  char v121; // [rsp+40h] [rbp-B8h]
  char v122; // [rsp+41h] [rbp-B7h]
  char v123; // [rsp+42h] [rbp-B6h]
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > v124; // [rsp+48h] [rbp-B0h]
  __int64 v125; // [rsp+60h] [rbp-98h]
  int v126; // [rsp+68h] [rbp-90h]
  hkArray<unsigned int,hkContainerHeapAllocator> cutOut; // [rsp+70h] [rbp-88h]
  int v128; // [rsp+80h] [rbp-78h]
  int v129; // [rsp+84h] [rbp-74h]
  hkSimdFloat32 extraRadius; // [rsp+88h] [rbp-70h]
  __m128 v131; // [rsp+98h] [rbp-60h]
  unsigned int v132; // [rsp+A8h] [rbp-50h]
  unsigned int v133; // [rsp+ACh] [rbp-4Ch]
  __int64 v134; // [rsp+B0h] [rbp-48h]
  hkResult v135; // [rsp+B8h] [rbp-40h]
  hkResult v136; // [rsp+BCh] [rbp-3Ch]
  hkResult result; // [rsp+C0h] [rbp-38h]
  hkResult v138; // [rsp+C4h] [rbp-34h]
  hkResult v139; // [rsp+C8h] [rbp-30h]
  hkResult v140; // [rsp+CCh] [rbp-2Ch]
  int faceIndex[4]; // [rsp+D8h] [rbp-20h]
  hkaiNavMeshCutter *retaddr; // [rsp+138h] [rbp+40h]
  hkaiNavMeshCutter *v143; // [rsp+140h] [rbp+48h]
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *v144; // [rsp+148h] [rbp+50h]
  hkArrayBase<hkAabb> *v145; // [rsp+150h] [rbp+58h]
  hkArrayBase<hkAabb> *v146; // [rsp+158h] [rbp+60h]

  v146 = faceAabbs;
  v144 = facesToReset;
  v143 = this;
  v4 = this;
  v5 = faceAabbs;
  v6 = cutFaceKeys;
  v7 = facesToReset;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "Ttfloodfill";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = v6->m_size;
  array = 0i64;
  v119 = 0;
  v120 = 2147483648;
  v124.m_elem.m_data = 0i64;
  v124.m_elem.m_size = 0;
  v124.m_elem.m_capacityAndFlags = 2147483648;
  v124.m_numElems = 0;
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::reserve(&v124, 4 * v12);
  if ( v6->m_size > 0 )
  {
    LODWORD(v144) = 4 * v6->m_size;
    array = (__int64)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                       (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                       (int *)&v144);
    v120 = (signed int)v144 / 4;
  }
  v13 = v6->m_size;
  v14 = v6->m_data;
  v15 = array;
  v16 = 0i64;
  v119 = v13;
  v17 = (_DWORD)v13 == 0;
  if ( (signed int)v13 > 0 )
  {
    do
    {
      v18 = v14[v16++];
      *(_DWORD *)(v15 + 4 * v16 - 4) = v18;
    }
    while ( v16 < v13 );
    LODWORD(v13) = v119;
    v17 = v119 == 0;
  }
  v19 = v124.m_elem.m_data;
  if ( !v17 )
  {
    do
    {
      v20 = *(_DWORD *)(array + 4i64 * (signed int)v13 - 4);
      LODWORD(v13) = v13 - 1;
      v21 = v124.m_elem.m_size - 1;
      v132 = v20;
      v119 = v13;
      if ( v124.m_elem.m_size - 1 <= 0 || (v22 = v21 & -1640531535 * (v20 >> 4), v23 = v19[v22], v23 == -1) )
      {
LABEL_13:
        v24 = v124.m_elem.m_size;
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
        v25 = (__int64)v4->m_streamingCollection.m_pntr->m_instances.m_data[v20 >> 22].m_instancePtr;
        v125 = v25;
        if ( v25 )
        {
          v30 = v20 & 0x3FFFFF;
          *(_OWORD *)faceIndex = 0i64;
          hkaiNavMeshUtils::calcFaceAabb<hkaiNavMeshInstance>(
            (hkaiNavMeshUtils *)v25,
            (hkaiNavMeshInstance *)(v20 & 0x3FFFFF),
            (__int64)faceIndex,
            &extraRadius,
            instanceMap);
          v31 = v5->m_size;
          v32 = 0i64;
          if ( v31 <= 0 )
          {
LABEL_29:
            v34 = v124.m_numElems;
            v35 = v124.m_elem.m_size;
            if ( 2 * v124.m_numElems > v124.m_elem.m_size - 1 )
            {
              hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
                &v124,
                &v136,
                2 * v124.m_elem.m_size);
              v34 = v124.m_numElems;
              v35 = v124.m_elem.m_size;
            }
            v36 = v35 - 1;
            v37 = 1;
            v38 = v36 & -1640531535 * (v20 >> 4);
            v39 = v124.m_elem.m_data[v38];
            if ( v39 != -1 )
            {
              while ( v39 != v20 )
              {
                v38 = v36 & (v38 + 1);
                v39 = v124.m_elem.m_data[v38];
                if ( v39 == -1 )
                  goto LABEL_138;
              }
              v37 = 0;
            }
LABEL_138:
            v124.m_numElems = v37 + v34;
            v124.m_elem.m_data[v38] = v20;
          }
          else
          {
            v33 = &v5->m_data->m_min.m_quad;
            while ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(extraRadius.m_real, v33[1]), _mm_cmpleps(*v33, v131))) & 7) != 7 )
            {
              ++v32;
              v33 += 2;
              if ( v32 >= v31 )
                goto LABEL_29;
            }
            v40 = 0i64;
            cutOut.m_capacityAndFlags = 2147483648;
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
                    &v140,
                    2 * v42);
                v44 = v7->m_elem.m_data;
                v45 = v7->m_elem.m_size - 1;
                v46 = 1;
                v47 = v45 & -1640531535 * (v43 >> 4);
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
              while ( (signed int)v40 < cutOut.m_size );
              v25 = v125;
              v40 = 0i64;
            }
            v49 = v7->m_elem.m_size;
            if ( 2 * v7->m_numElems > v49 - 1 )
              hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
                v7,
                &v139,
                2 * v49);
            v50 = v7->m_elem.m_data;
            v51 = v7->m_elem.m_size - 1;
            v52 = 1;
            v53 = -1640531535 * (v20 >> 4) & v51;
            v133 = -1640531535 * (v20 >> 4);
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
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                cutOut.m_data,
                4 * cutOut.m_capacityAndFlags);
            v55 = v124.m_elem.m_data;
            v56 = v30;
            cutOut.m_data = 0i64;
            cutOut.m_capacityAndFlags = 2147483648;
            v57 = (signed int *)(*(_QWORD *)(v25 + 16) + 16i64 * v30);
            v58 = *v57;
            if ( (signed int)v58 < (signed int)v58 + *((signed __int16 *)v57 + 4) )
            {
              v59 = v119;
              v60 = 20 * v58;
              do
              {
                v61 = *(_QWORD *)(v25 + 32);
                v62 = *(_DWORD *)(v60 + v61 + 12);
                if ( *(_BYTE *)(v60 + v61 + 16) & 0x40 )
                  v63 = v62 & 0xFFC00000;
                else
                  v63 = *(_DWORD *)(v25 + 472) << 22;
                v64 = v63 | v62 & 0x3FFFFF;
                if ( v62 == -1 )
                  v64 = -1;
                if ( *(_DWORD *)(v60 + v61 + 8) != -1 )
                {
                  v65 = v124.m_elem.m_size - 1;
                  if ( v124.m_elem.m_size - 1 <= 0 || (v66 = v65 & -1640531535 * (v64 >> 4), v67 = v55[v66], v67 == -1) )
                  {
LABEL_68:
                    v68 = v124.m_elem.m_size;
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
                    if ( v59 == (v120 & 0x3FFFFFFF) )
                    {
                      hkArrayUtil::_reserveMore(
                        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                        &array,
                        4);
                      v59 = v119;
                    }
                    *(_DWORD *)(array + 4i64 * v59) = v64;
                    v55 = v124.m_elem.m_data;
                    v59 = v119++ + 1;
                  }
                }
                v25 = v125;
                LODWORD(v58) = v58 + 1;
                v60 += 20i64;
              }
              while ( (signed int)v58 < *v57 + *((signed __int16 *)v57 + 4) );
              v40 = 0i64;
            }
            v69 = *(_DWORD *)(v25 + 328);
            if ( v69 )
            {
              v70 = &v144;
              LOBYTE(v144) = *(_BYTE *)(v56 + *(_QWORD *)(v25 + 320));
            }
            else
            {
              v121 = 0;
              v70 = (hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > **)&v121;
            }
            if ( *(_BYTE *)v70 & 4 )
            {
              if ( v69 )
              {
                v71 = &v123;
                v123 = *(_BYTE *)(v56 + *(_QWORD *)(v25 + 320));
              }
              else
              {
                v122 = 0;
                v71 = &v122;
              }
              if ( *v71 & 1 )
              {
                *(_QWORD *)&cutOut.m_size = 0i64;
                v128 = 0;
                v129 = 2147483648;
                hkaiNavMeshCutter::getCutKeysFromOriginal(
                  retaddr,
                  v20,
                  (hkArray<unsigned int,hkContainerHeapAllocator> *)((char *)&cutOut + 8));
                v55 = v124.m_elem.m_data;
                v72 = 0.0;
                v73 = 0;
                v74 = -0.0;
                extraRadius.m_real.m128_u64[0] = 0i64;
                extraRadius.m_real.m128_u64[1] = 0x8000000000000000i64;
                v131.m128_i32[0] = 0;
                v126 = 0;
                if ( v128 > 0 )
                {
                  v75 = 0i64;
                  v76 = (hkArray<int,hkContainerHeapAllocator> *)(v25 + 224);
                  v77 = (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v25 + 272);
                  v134 = 0i64;
                  v78 = (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v25 + 240);
                  do
                  {
                    v80 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
                            *(hkaiNavMesh::Face **)(v25 + 16),
                            *(_DWORD *)(v25 + 24),
                            v78,
                            v77,
                            v76,
                            *(_DWORD *)(*(_QWORD *)&cutOut.m_size + v75) & 0x3FFFFF);
                    index = v80->m_startEdgeIndex;
                    if ( index < index + v80->m_numEdges )
                    {
                      v82 = (hkArray<int,hkContainerHeapAllocator> *)(v25 + 208);
                      v83 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v25 + 288);
                      v84 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v25 + 256);
                      do
                      {
                        v85 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__8(
                                *(hkaiNavMesh::Edge **)(v25 + 32),
                                *(_DWORD *)(v25 + 40),
                                v84,
                                v83,
                                v82,
                                index);
                        if ( v85->m_flags.m_storage & 0x40 && v85->m_oppositeEdge != -1 )
                        {
                          v86 = v85->m_oppositeFace;
                          v87 = v86 & 0xFFC00000 | v86 & 0x3FFFFF;
                          if ( v86 == -1 )
                            v87 = -1;
                          v88 = hkaiNavMeshCutter::getOriginalFromCutKey(retaddr, v87);
                          v89 = v124.m_elem.m_size - 1;
                          v90 = v88;
                          if ( v124.m_elem.m_size - 1 <= 0
                            || (v91 = v89 & -1640531535 * (v88 >> 4), v92 = v55[v91], v92 == -1) )
                          {
LABEL_96:
                            v93 = v124.m_elem.m_size;
                          }
                          else
                          {
                            while ( v92 != v90 )
                            {
                              v91 = v89 & (v91 + 1);
                              v92 = v55[v91];
                              if ( v92 == -1 )
                                goto LABEL_96;
                            }
                            v93 = v91;
                          }
                          if ( v93 > v89 )
                          {
                            if ( 2 * v73 > LODWORD(v72) - 1 )
                            {
                              hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int>>::resizeTable(
                                (hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > *)&extraRadius,
                                &v135,
                                2 * LODWORD(v72));
                              v73 = v131.m128_i32[0];
                              v72 = extraRadius.m_real.m128_f32[2];
                              v40 = (_DWORD *)extraRadius.m_real.m128_u64[0];
                            }
                            v94 = 1;
                            v95 = (LODWORD(v72) - 1) & -1640531535 * (v90 >> 4);
                            v96 = v40[v95];
                            if ( v96 != -1 )
                            {
                              while ( v96 != v90 )
                              {
                                v95 = (LODWORD(v72) - 1) & (v95 + 1);
                                v96 = v40[v95];
                                if ( v96 == -1 )
                                  goto LABEL_106;
                              }
                              v94 = 0;
                            }
LABEL_106:
                            v131.m128_i32[0] = v94 + v73;
                            v40[v95] = v90;
                            v55 = v124.m_elem.m_data;
                            v73 = v131.m128_i32[0];
                            v72 = extraRadius.m_real.m128_f32[2];
                            v40 = (_DWORD *)extraRadius.m_real.m128_u64[0];
                          }
                          v25 = v125;
                        }
                        ++index;
                        v83 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v25 + 288);
                        v97 = v80->m_startEdgeIndex + v80->m_numEdges;
                        v84 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v25 + 256);
                        v99 = __OFSUB__(index, v97);
                        v98 = index - v97 < 0;
                        v82 = (hkArray<int,hkContainerHeapAllocator> *)(v25 + 208);
                      }
                      while ( v98 ^ v99 );
                      v79 = v128;
                    }
                    v76 = (hkArray<int,hkContainerHeapAllocator> *)(v25 + 224);
                    v75 = v134 + 4;
                    v77 = (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v25 + 272);
                    ++v126;
                    v134 += 4i64;
                    v78 = (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v25 + 240);
                  }
                  while ( v126 < v79 );
                  v74 = extraRadius.m_real.m128_f32[3];
                  v20 = v132;
                }
                v100 = LODWORD(v72) - 1;
                v101 = 0;
                v102 = 0i64;
                if ( LODWORD(v72) - 1 >= 0 )
                {
                  do
                  {
                    if ( v40[v102] != -1 )
                      break;
                    ++v102;
                    ++v101;
                  }
                  while ( v102 <= v100 );
                }
                v103 = v101;
                if ( v101 <= v100 )
                {
                  v104 = v119;
                  do
                  {
                    v105 = v40[v103];
                    if ( v104 == (v120 & 0x3FFFFFFF) )
                    {
                      hkArrayUtil::_reserveMore(
                        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                        &array,
                        4);
                      v104 = v119;
                    }
                    v106 = v103 + 1;
                    *(_DWORD *)(array + 4i64 * v104) = v105;
                    v40 = (_DWORD *)extraRadius.m_real.m128_u64[0];
                    v107 = extraRadius.m_real.m128_i32[2] - 1;
                    v104 = v119 + 1;
                    v108 = v103 + 1;
                    ++v119;
                    if ( v108 <= extraRadius.m_real.m128_i32[2] - 1 )
                    {
                      do
                      {
                        if ( *(_DWORD *)(extraRadius.m_real.m128_u64[0] + 4 * v108) != -1 )
                          break;
                        ++v108;
                        ++v106;
                      }
                      while ( v108 <= v107 );
                    }
                    v103 = v106;
                  }
                  while ( v106 <= v107 );
                  v55 = v124.m_elem.m_data;
                  v74 = extraRadius.m_real.m128_f32[3];
                }
                extraRadius.m_real.m128_i32[2] = 0;
                if ( v74 >= 0.0 )
                {
                  hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                    v40,
                    4 * LODWORD(v74));
                  v55 = v124.m_elem.m_data;
                }
                LODWORD(v40) = 0;
                extraRadius.m_real.m128_i32[3] = 2147483648;
                extraRadius.m_real.m128_u64[0] = 0i64;
                v128 = 0;
                if ( v129 >= 0 )
                {
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    *(void **)&cutOut.m_size,
                    4 * v129);
                  v55 = v124.m_elem.m_data;
                }
                *(_QWORD *)&cutOut.m_size = 0i64;
                v129 = 2147483648;
              }
            }
            v109 = v124.m_numElems;
            if ( 2 * v124.m_numElems > v124.m_elem.m_size - 1 )
            {
              hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
                &v124,
                &v138,
                2 * v124.m_elem.m_size);
              v109 = v124.m_numElems;
              v55 = v124.m_elem.m_data;
            }
            v110 = 1;
            v111 = v133 & (v124.m_elem.m_size - 1);
            v112 = v55[v111];
            if ( v112 != -1 )
            {
              while ( v112 != v20 )
              {
                v111 = (v124.m_elem.m_size - 1) & (v111 + 1);
                v112 = v55[v111];
                if ( v112 == -1 )
                  goto LABEL_136;
              }
              v110 = (signed int)v40;
            }
LABEL_136:
            v7 = (hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *)v143;
            v5 = v145;
            v124.m_numElems = v110 + v109;
            v55[v111] = v20;
            v4 = retaddr;
          }
        }
        else
        {
          v26 = v124.m_numElems;
          if ( 2 * v124.m_numElems > v21 )
          {
            hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
              &v124,
              &result,
              2 * v124.m_elem.m_size);
            v26 = v124.m_numElems;
            v19 = v124.m_elem.m_data;
          }
          v27 = 1;
          v28 = (v124.m_elem.m_size - 1) & -1640531535 * (v20 >> 4);
          v29 = v19[v28];
          if ( v29 != -1 )
          {
            while ( v29 != v20 )
            {
              v28 = (v124.m_elem.m_size - 1) & (v28 + 1);
              v29 = v19[v28];
              if ( v29 == -1 )
              {
                v124.m_numElems = v26 + 1;
                v19[v28] = v20;
                goto LABEL_139;
              }
            }
            v27 = 0;
          }
          v124.m_numElems = v27 + v26;
          v19[v28] = v20;
        }
LABEL_139:
        LODWORD(v13) = v119;
        v19 = v124.m_elem.m_data;
      }
    }
    while ( (_DWORD)v13 );
  }
  v124.m_elem.m_size = 0;
  if ( v124.m_elem.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v19,
      4 * v124.m_elem.m_capacityAndFlags);
  v124.m_elem.m_data = 0i64;
  v124.m_elem.m_capacityAndFlags = 2147483648;
  v119 = 0;
  if ( v120 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, __int64, _QWORD, unsigned int *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      array,
      (unsigned int)(4 * v120),
      v19);
  array = 0i64;
  v120 = 2147483648;
  v113 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v114 = (_QWORD *)v113[1];
  if ( (unsigned __int64)v114 < v113[3] )
  {
    *v114 = "Et";
    v115 = __rdtsc();
    v116 = (signed __int64)(v114 + 2);
    *(_DWORD *)(v116 - 8) = v115;
    v113[1] = v116;
  }
}

// File Line: 1196
// RVA: 0xBEF910
void __usercall hkaiNavMeshCutter::resetClearanceForCutFaces(hkaiNavMeshCutter *this@<rcx>, hkArrayBase<int> *updatedSections@<rdx>, hkArrayBase<unsigned int> *cutFaceKeys@<r8>, __m128 a4@<xmm2>)
{
  hkArrayBase<unsigned int> *v4; // r12
  int v5; // er14
  hkArrayBase<int> *v6; // rbx
  hkaiNavMeshCutter *v7; // rsi
  int v8; // edi
  hkLifoAllocator *v9; // rax
  char *v10; // rcx
  int v11; // edx
  char *v12; // r8
  signed int v13; // eax
  int v14; // eax
  int v15; // er9
  int v16; // eax
  _DWORD *v17; // rdi
  __int64 i; // rcx
  int v19; // er8
  __int64 v20; // r9
  __int64 v21; // rcx
  int v22; // er14
  __int64 v23; // r15
  hkaiStreamingCollection *v24; // rdx
  hkaiNavMeshInstance *v25; // rbx
  int v26; // eax
  int v27; // er9
  unsigned int *v28; // rdi
  __int64 v29; // rdx
  unsigned int *v30; // r9
  __int64 v31; // rcx
  unsigned int v32; // eax
  __int64 v33; // rcx
  unsigned int *v34; // rdi
  int v35; // er8
  int v36; // edi
  int v37; // er9
  _QWORD *v38; // rdi
  _QWORD *v39; // rcx
  unsigned __int64 v40; // rax
  signed __int64 v41; // rcx
  float v42; // xmm6_4
  int v43; // er14
  __int64 v44; // rbx
  __int64 v45; // r15
  unsigned int v46; // eax
  hkaiNavMeshInstance *v47; // rdi
  hkAabb *v48; // rax
  float v49; // xmm6_4
  int v50; // edx
  __int64 v51; // rcx
  __m128 v52; // xmm2
  hkAabb *v53; // rax
  __m128 v54; // xmm1
  _QWORD *v55; // rdi
  _QWORD *v56; // rcx
  unsigned __int64 v57; // rax
  signed __int64 v58; // rcx
  char v59; // al
  unsigned int *v60; // rdi
  int v61; // edx
  int v62; // er8
  signed __int64 v63; // rcx
  int v64; // ebx
  int v65; // er8
  int v66; // edx
  signed __int64 v67; // rcx
  hkAabb *sizeElem; // [rsp+20h] [rbp-99h]
  hkArrayBase<unsigned int> cutFaceKeysa; // [rsp+30h] [rbp-89h]
  hkArrayBase<hkAabb> aabbs; // [rsp+40h] [rbp-79h]
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > facesToReset; // [rsp+50h] [rbp-69h]
  _DWORD *array; // [rsp+68h] [rbp-51h]
  int v73; // [rsp+70h] [rbp-49h]
  unsigned int v74; // [rsp+74h] [rbp-45h]
  char *v75; // [rsp+78h] [rbp-41h]
  int v76; // [rsp+80h] [rbp-39h]
  int v77; // [rsp+88h] [rbp-31h]
  int faceIndex[4]; // [rsp+90h] [rbp-29h]
  hkSimdFloat32 extraRadius; // [rsp+A0h] [rbp-19h]
  __int128 v80; // [rsp+B0h] [rbp-9h]
  hkResult result; // [rsp+120h] [rbp+67h]
  float v82; // [rsp+128h] [rbp+6Fh]

  v4 = cutFaceKeys;
  v5 = this->m_streamingCollection.m_pntr->m_instances.m_size;
  v6 = updatedSections;
  v7 = this;
  array = 0i64;
  v73 = 0;
  v8 = (v5 + 31) >> 5;
  v74 = 2147483648;
  v76 = v8;
  if ( v8 )
  {
    v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (char *)v9->m_cur;
    v11 = (4 * v8 + 127) & 0xFFFFFF80;
    v12 = &v10[v11];
    if ( v11 > v9->m_slabSize || v12 > v9->m_end )
      v10 = (char *)hkLifoAllocator::allocateFromNewSlab(v9, v11);
    else
      v9->m_cur = v12;
  }
  else
  {
    v10 = 0i64;
  }
  array = v10;
  v75 = v10;
  v77 = v5;
  v74 = v8 | 0x80000000;
  v13 = (v8 | 0x80000000) & 0x3FFFFFFF;
  if ( v13 < v8 )
  {
    v14 = 2 * v13;
    v15 = (v5 + 31) >> 5;
    if ( v8 < v14 )
      v15 = v14;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v15, 4);
  }
  v16 = v8 - 1;
  v73 = (v5 + 31) >> 5;
  if ( v8 - 1 >= 0 )
  {
    v17 = array;
    for ( i = (unsigned int)(v16 + 1); i; --i )
    {
      *v17 = 0;
      ++v17;
    }
  }
  v19 = 0;
  if ( v6->m_size > 0 )
  {
    v20 = 0i64;
    do
    {
      ++v19;
      v21 = v6->m_data[v20];
      ++v20;
      array[v21 >> 5] |= 1 << (v21 & 0x1F);
    }
    while ( v19 < v6->m_size );
  }
  v22 = 0;
  if ( v7->m_streamingCollection.m_pntr->m_instances.m_size > 0 )
  {
    v23 = 0i64;
    do
    {
      v24 = v7->m_streamingCollection.m_pntr;
      v25 = v24->m_instances.m_data[v23].m_instancePtr;
      if ( v25 )
      {
        if ( !((array[(signed __int64)v22 >> 5] >> (v22 & 0x1F)) & 1) )
        {
          hkaiNavMeshUtils::compactOwnedEdges(v25, v24);
          hkaiNavMeshUtils::compactOwnedVertices(v25);
        }
        if ( v25->m_clearanceCache.m_size > 0 || v25->m_globalClearanceCache.m_size > 0 )
        {
          if ( v7->m_clearanceResetMethod.m_storage )
          {
            hkaiNavMeshUtils::compactClearanceCache(v25);
            hkaiNavMeshInstance::initGlobalClearanceCache(v25);
          }
          else
          {
            hkaiNavMeshInstance::initClearanceCache(v25);
            hkaiNavMeshInstance::resetVertexClearances(v25);
            if ( v7->m_recomputeClearanceAfterCutting.m_bool )
              hkaiNavMeshCutter::recomputeDirtyGlobalClearances(v7, v25);
            v7->m_forceClearanceCalcFaceKeys.m_size = 0;
          }
        }
      }
      ++v22;
      ++v23;
    }
    while ( v22 < v7->m_streamingCollection.m_pntr->m_instances.m_size );
  }
  if ( v7->m_clearanceResetMethod.m_storage )
  {
    v26 = 2147483648;
    v27 = v4->m_size + v7->m_forceClearanceCalcFaceKeys.m_size;
    v28 = 0i64;
    cutFaceKeysa.m_data = 0i64;
    cutFaceKeysa.m_size = 0;
    cutFaceKeysa.m_capacityAndFlags = 2147483648;
    if ( v27 > 0 )
    {
      if ( v27 < 0 )
        v27 = 0;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        &cutFaceKeysa,
        v27,
        4);
      v26 = cutFaceKeysa.m_capacityAndFlags;
      v28 = cutFaceKeysa.m_data;
    }
    if ( (v26 & 0x3FFFFFFF) < v4->m_size )
    {
      if ( v26 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v28,
          4 * v26);
      result.m_enum = 4 * v4->m_size;
      v28 = (unsigned int *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                              (int *)&result);
      cutFaceKeysa.m_data = v28;
      cutFaceKeysa.m_capacityAndFlags = result.m_enum / 4;
    }
    v29 = v4->m_size;
    v30 = v4->m_data;
    v31 = 0i64;
    cutFaceKeysa.m_size = v29;
    if ( (signed int)v29 > 0 )
    {
      do
      {
        v32 = v30[v31++];
        v28[v31 - 1] = v32;
      }
      while ( v31 < v29 );
      LODWORD(v29) = cutFaceKeysa.m_size;
    }
    if ( v7->m_forceClearanceCalcFaceKeys.m_size )
    {
      hkArrayBase<unsigned int>::_append(
        &cutFaceKeysa,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        v7->m_forceClearanceCalcFaceKeys.m_data,
        v7->m_forceClearanceCalcFaceKeys.m_size);
      LODWORD(v29) = cutFaceKeysa.m_size;
      if ( cutFaceKeysa.m_size > 1 )
      {
        hkAlgorithm::quickSortRecursive<unsigned int,hkAlgorithm::less<unsigned int>>(
          cutFaceKeysa.m_data,
          0,
          cutFaceKeysa.m_size - 1,
          0);
        LODWORD(v29) = cutFaceKeysa.m_size;
      }
      v33 = (signed int)v29 - 2;
      if ( (signed int)v29 - 2 >= 0 )
      {
        v34 = cutFaceKeysa.m_data;
        v35 = v29 - 2 + 1;
        do
        {
          if ( v34[v33] == v34[v33 + 1] )
          {
            LODWORD(v29) = v29 - 1;
            cutFaceKeysa.m_size = v29;
            if ( (_DWORD)v29 != v35 )
            {
              v34[v33 + 1] = v34[(signed int)v29];
              LODWORD(v29) = cutFaceKeysa.m_size;
              v34 = cutFaceKeysa.m_data;
            }
          }
          --v35;
          --v33;
        }
        while ( v33 >= 0 );
      }
      v7->m_forceClearanceCalcFaceKeys.m_size = 0;
    }
    facesToReset.m_elem.m_data = 0i64;
    facesToReset.m_elem.m_size = 0;
    facesToReset.m_elem.m_capacityAndFlags = 2147483648;
    facesToReset.m_numElems = 0;
    hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::reserve(&facesToReset, 4 * v29);
    v36 = cutFaceKeysa.m_size;
    aabbs.m_data = 0i64;
    aabbs.m_size = 0;
    aabbs.m_capacityAndFlags = 2147483648;
    if ( cutFaceKeysa.m_size > 0 )
    {
      v37 = cutFaceKeysa.m_size;
      if ( cutFaceKeysa.m_size < 0 )
        v37 = 0;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &aabbs, v37, 32);
    }
    aabbs.m_size = v36;
    v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v39 = (_QWORD *)v38[1];
    if ( (unsigned __int64)v39 < v38[3] )
    {
      *v39 = "Ttaabbs";
      v40 = __rdtsc();
      v41 = (signed __int64)(v39 + 2);
      *(_DWORD *)(v41 - 8) = v40;
      v38[1] = v41;
    }
    v42 = 0.0;
    v43 = 0;
    if ( cutFaceKeysa.m_size > 0 )
    {
      v44 = 0i64;
      v45 = 0i64;
      do
      {
        *(_OWORD *)faceIndex = 0i64;
        v46 = cutFaceKeysa.m_data[v45];
        v47 = v7->m_streamingCollection.m_pntr->m_instances.m_data[v46 >> 22].m_instancePtr;
        hkaiNavMeshUtils::calcFaceAabb<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)v7->m_streamingCollection.m_pntr->m_instances.m_data[v46 >> 22].m_instancePtr,
          (hkaiNavMeshInstance *)(v46 & 0x3FFFFF),
          (__int64)faceIndex,
          &extraRadius,
          sizeElem);
        v48 = aabbs.m_data;
        ++v43;
        result.m_enum = LODWORD(v42);
        ++v45;
        ++v44;
        aabbs.m_data[v44 - 1].m_min = (hkVector4f)extraRadius.m_real;
        *((_OWORD *)&v48[v44] - 1) = v80;
        v82 = v47->m_maxGlobalClearance;
        v42 = fmaxf(v42, v82);
      }
      while ( v43 < cutFaceKeysa.m_size );
    }
    v49 = v42 * 2.0;
    simpleAabbMerge(&aabbs);
    v50 = 0;
    if ( aabbs.m_size > 0 )
    {
      a4.m128_f32[0] = v49;
      v51 = 0i64;
      v52 = _mm_shuffle_ps(a4, a4, 0);
      do
      {
        v53 = aabbs.m_data;
        ++v50;
        ++v51;
        v54 = _mm_sub_ps(aabbs.m_data[v51 - 1].m_min.m_quad, v52);
        *((__m128 *)&aabbs.m_data[v51] - 1) = _mm_add_ps(v52, *((__m128 *)&aabbs.m_data[v51] - 1));
        v53[v51 - 1].m_min.m_quad = v54;
      }
      while ( v50 < aabbs.m_size );
    }
    v55 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v56 = (_QWORD *)v55[1];
    if ( (unsigned __int64)v56 < v55[3] )
    {
      *v56 = "Et";
      v57 = __rdtsc();
      v58 = (signed __int64)(v56 + 2);
      *(_DWORD *)(v58 - 8) = v57;
      v55[1] = v58;
    }
    v59 = v7->m_clearanceResetMethod.m_storage;
    if ( v59 == 1 )
    {
      hkaiNavMeshCutter::getFacesForResetByMediator(v7, &facesToReset, &aabbs);
    }
    else if ( v59 == 2 )
    {
      hkaiNavMeshCutter::getFacesForResetByFloodFill(v7, &facesToReset, &cutFaceKeysa, &aabbs);
    }
    if ( v7->m_recomputeClearanceAfterCutting.m_bool )
    {
      hkaiNavMeshCutter::recomputeGlobalClearancesForFaces(v7, &facesToReset);
      v60 = facesToReset.m_elem.m_data;
    }
    else
    {
      v60 = facesToReset.m_elem.m_data;
      v61 = 0;
      v62 = facesToReset.m_elem.m_size - 1;
      v63 = 0i64;
      if ( facesToReset.m_elem.m_size - 1 >= 0 )
      {
        do
        {
          if ( facesToReset.m_elem.m_data[v63] != -1 )
            break;
          ++v63;
          ++v61;
        }
        while ( v63 <= v62 );
      }
      v64 = v61;
      if ( v61 <= v62 )
      {
        do
        {
          hkaiNavMeshTraversalUtils::resetClearanceForFace(
            v7->m_streamingCollection.m_pntr->m_instances.m_data[v60[v64] >> 22].m_instancePtr,
            v60[v64] & 0x3FFFFF,
            1,
            1);
          v60 = facesToReset.m_elem.m_data;
          v65 = facesToReset.m_elem.m_size - 1;
          v66 = v64 + 1;
          v67 = v64 + 1;
          if ( v67 <= facesToReset.m_elem.m_size - 1 )
          {
            do
            {
              if ( facesToReset.m_elem.m_data[v67] != -1 )
                break;
              ++v67;
              ++v66;
            }
            while ( v67 <= v65 );
          }
          v64 = v66;
        }
        while ( v66 <= v65 );
      }
    }
    aabbs.m_size = 0;
    if ( aabbs.m_capacityAndFlags >= 0 )
    {
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        aabbs.m_data,
        32 * aabbs.m_capacityAndFlags);
      v60 = facesToReset.m_elem.m_data;
    }
    aabbs.m_data = 0i64;
    aabbs.m_capacityAndFlags = 2147483648;
    facesToReset.m_elem.m_size = 0;
    if ( facesToReset.m_elem.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v60,
        4 * facesToReset.m_elem.m_capacityAndFlags);
    facesToReset.m_elem.m_data = 0i64;
    facesToReset.m_elem.m_capacityAndFlags = 2147483648;
    cutFaceKeysa.m_size = 0;
    if ( cutFaceKeysa.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        cutFaceKeysa.m_data,
        4 * cutFaceKeysa.m_capacityAndFlags);
  }
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>((hkBitFieldStorage<hkLocalArray<unsigned int> > *)&array);
}

// File Line: 1336
// RVA: 0xBF0260
void __fastcall hkaiNavMeshCutter::recomputeGlobalClearancesForFaces(hkaiNavMeshCutter *this, hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *facesToReset)
{
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *v2; // rbx
  hkaiStreamingCollection *v3; // rdx
  hkaiNavMeshCutter *v4; // rsi
  int v5; // er8
  int v6; // er11
  unsigned int *v7; // r9
  int v8; // edx
  signed __int64 v9; // rcx
  unsigned int *v10; // rax
  int v11; // er15
  unsigned int v12; // ebx
  hkaiNavMeshInstance *v13; // rdi
  int v14; // ebx
  int *v15; // rax
  int v16; // esi
  int v17; // ecx
  int v18; // er14
  hkaiNavMesh::Edge *v19; // rax
  int v20; // er10
  int v21; // edx
  unsigned int v22; // ebx
  int v23; // er9
  signed int v24; // er11
  int v25; // eax
  unsigned int v26; // edx
  int v27; // er8
  signed __int64 v28; // rcx
  int v29; // er11
  unsigned int *v30; // rdx
  int v31; // edx
  int v32; // er10
  signed __int64 v33; // rcx
  int v34; // edi
  hkaiNavMeshInstance *v35; // rsi
  int v36; // ebx
  int v37; // edx
  int v38; // er8
  signed __int64 v39; // rcx
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // [rsp+20h] [rbp-59h]
  int index; // [rsp+28h] [rbp-51h]
  int v42; // [rsp+2Ch] [rbp-4Dh]
  hkVector4f up; // [rsp+30h] [rbp-49h]
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > v44; // [rsp+40h] [rbp-39h]
  hkaiDynamicNavMeshQueryMediator v45; // [rsp+58h] [rbp-21h]
  hkaiNavMeshCutter *vars0; // [rsp+E0h] [rbp+67h]
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *retaddr; // [rsp+E8h] [rbp+6Fh]
  hkaiNavMeshCutter *result; // [rsp+F0h] [rbp+77h]
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *v49; // [rsp+F8h] [rbp+7Fh]

  v49 = facesToReset;
  result = this;
  v2 = facesToReset;
  v3 = this->m_streamingCollection.m_pntr;
  _mm_store_si128((__m128i *)&up, (__m128i)this->m_up.m_quad);
  v4 = this;
  hkaiDynamicNavMeshQueryMediator::hkaiDynamicNavMeshQueryMediator(&v45, v3, v3->m_tree.m_pntr, this);
  v5 = 2147483648;
  v6 = v2->m_elem.m_size - 1;
  v7 = 0i64;
  v44.m_elem.m_data = 0i64;
  v44.m_elem.m_size = 0;
  v44.m_numElems = 0;
  v44.m_elem.m_capacityAndFlags = 2147483648;
  v8 = 0;
  v9 = 0i64;
  if ( v6 >= 0 )
  {
    v10 = v2->m_elem.m_data;
    do
    {
      if ( *v10 != -1 )
        break;
      ++v9;
      ++v8;
      ++v10;
    }
    while ( v9 <= v6 );
  }
  v11 = v8;
  v49 = (hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *)v8;
  if ( v8 <= v6 )
  {
    do
    {
      v12 = v2->m_elem.m_data[v11];
      v13 = v4->m_streamingCollection.m_pntr->m_instances.m_data[v12 >> 22].m_instancePtr;
      if ( v13 )
      {
        v14 = v12 & 0x3FFFFF;
        hkaiNavMeshTraversalUtils::resetClearanceForFace(v13, v14, 1, 0);
        v15 = (int *)hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
                       v13->m_originalFaces,
                       v13->m_numOriginalFaces,
                       &v13->m_instancedFaces,
                       &v13->m_ownedFaces,
                       &v13->m_faceMap,
                       v14);
        v16 = *v15;
        HIDWORD(instanceMap) = v15[1];
        v17 = v15[2];
        LODWORD(v15) = v15[3];
        index = v17;
        v42 = (signed int)v15;
        v18 = v16 + (signed __int16)v17;
        if ( v16 < v18 )
        {
          do
          {
            v19 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__8(
                    v13->m_originalEdges,
                    v13->m_numOriginalEdges,
                    &v13->m_instancedEdges,
                    &v13->m_ownedEdges,
                    &v13->m_edgeMap,
                    v16);
            if ( v19->m_oppositeEdge == -1 || v19->m_flags.m_storage & 0x20 )
            {
              v13->m_globalClearanceCache.m_data[v19->m_a].m_value = -16512;
              v13->m_globalClearanceCache.m_data[v19->m_b].m_value = -16512;
            }
            else
            {
              v20 = v44.m_numElems;
              v21 = v44.m_elem.m_size;
              v22 = v19->m_a | (v13->m_runtimeId << 22);
              if ( 2 * v44.m_numElems > v44.m_elem.m_size - 1 )
              {
                hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
                  &v44,
                  (hkResult *)&result,
                  2 * v44.m_elem.m_size);
                v20 = v44.m_numElems;
                v21 = v44.m_elem.m_size;
              }
              v23 = v21 - 1;
              v24 = 1;
              v25 = (v21 - 1) & -1640531535 * (v22 >> 4);
              v26 = v44.m_elem.m_data[v25];
              if ( v26 != -1 )
              {
                while ( v26 != v22 )
                {
                  v25 = v23 & (v25 + 1);
                  v26 = v44.m_elem.m_data[v25];
                  if ( v26 == -1 )
                  {
                    v44.m_numElems = v20 + 1;
                    v44.m_elem.m_data[v25] = v22;
                    goto LABEL_19;
                  }
                }
                v24 = 0;
              }
              v44.m_numElems = v24 + v20;
              v44.m_elem.m_data[v25] = v22;
            }
LABEL_19:
            ++v16;
          }
          while ( v16 < v18 );
          v11 = (signed int)v49;
        }
        v4 = vars0;
        v7 = v44.m_elem.m_data;
      }
      v2 = retaddr;
      v27 = v11 + 1;
      v28 = v11 + 1;
      v29 = retaddr->m_elem.m_size - 1;
      if ( v28 <= v29 )
      {
        v30 = &retaddr->m_elem.m_data[v27];
        do
        {
          if ( *v30 != -1 )
            break;
          ++v28;
          ++v27;
          ++v30;
        }
        while ( v28 <= v29 );
      }
      v11 = v27;
      v49 = (hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > *)v27;
    }
    while ( v27 <= v29 );
    v5 = v44.m_elem.m_capacityAndFlags;
  }
  v31 = 0;
  v32 = v44.m_elem.m_size - 1;
  v33 = 0i64;
  if ( v44.m_elem.m_size - 1 >= 0 )
  {
    do
    {
      if ( v7[v33] != -1 )
        break;
      ++v33;
      ++v31;
    }
    while ( v33 <= v32 );
  }
  v34 = v31;
  if ( v31 <= v32 )
  {
    do
    {
      v35 = v4->m_streamingCollection.m_pntr->m_instances.m_data[v7[v34] >> 22].m_instancePtr;
      if ( v35 )
      {
        v36 = v7[v34] & 0x3FFFFF;
        if ( v35->m_globalClearanceCache.m_data[v36].m_value != -16512 )
        {
          hkaiNavMeshTraversalUtils::computeGlobalClearance(
            (hkSimdFloat32 *)&instanceMap,
            v35,
            (hkaiNavMeshQueryMediator *)&v45.vfptr,
            v36,
            &up);
          hkaiNavMeshTraversalUtils::updateGlobalClearance(v35, v36, (hkSimdFloat32 *)&instanceMap);
          v7 = v44.m_elem.m_data;
        }
      }
      v37 = v34 + 1;
      v38 = v44.m_elem.m_size - 1;
      v39 = v34 + 1;
      if ( v39 <= v44.m_elem.m_size - 1 )
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
      v34 = v37;
    }
    while ( v37 <= v38 );
    v5 = v44.m_elem.m_capacityAndFlags;
  }
  v44.m_elem.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v7,
      4 * v5);
  v44.m_elem.m_data = 0i64;
  v44.m_elem.m_capacityAndFlags = 2147483648;
  hkaiDynamicNavMeshQueryMediator::~hkaiDynamicNavMeshQueryMediator(&v45);
}

// File Line: 1427
// RVA: 0xBF0010
void __fastcall hkaiNavMeshCutter::recomputeDirtyGlobalClearances(hkaiNavMeshCutter *this, hkaiNavMeshInstance *meshInstance)
{
  hkaiNavMeshInstance *v2; // rbx
  hkaiStreamingCollection *v3; // rdx
  int v4; // edx
  int v5; // esi
  int index; // ebp
  __int64 i; // r15
  unsigned int *v8; // rax
  signed int v9; // edi
  hkaiNavMesh::Face *v10; // r14
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v11; // r9
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v12; // r8
  hkaiNavMesh::Edge *v13; // rax
  int v14; // eax
  float v15; // xmm6_4
  __int64 v16; // rdi
  hkVector4f up; // [rsp+30h] [rbp-98h]
  hkSimdFloat32 result; // [rsp+40h] [rbp-88h]
  hkaiNavMeshQueryMediator worldMediator; // [rsp+50h] [rbp-78h]
  unsigned int v20; // [rsp+D0h] [rbp+8h]
  char v21; // [rsp+D8h] [rbp+10h]

  v2 = meshInstance;
  v3 = this->m_streamingCollection.m_pntr;
  _mm_store_si128((__m128i *)&up, (__m128i)this->m_up.m_quad);
  hkaiDynamicNavMeshQueryMediator::hkaiDynamicNavMeshQueryMediator(
    (hkaiDynamicNavMeshQueryMediator *)&worldMediator,
    v3,
    v3->m_tree.m_pntr,
    this);
  v4 = v2->m_numOriginalFaces;
  v5 = 0;
  index = 0;
  for ( i = 0i64; index < v4 + v2->m_ownedFaces.m_size; ++i )
  {
    if ( v2->m_faceFlags.m_size )
    {
      v8 = &v20;
      LOBYTE(v20) = v2->m_faceFlags.m_data[i].m_storage;
    }
    else
    {
      v21 = 0;
      v8 = (unsigned int *)&v21;
    }
    if ( !(*(_BYTE *)v8 & 1) )
    {
      v9 = 0;
      v10 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
              v2->m_originalFaces,
              v4,
              &v2->m_instancedFaces,
              &v2->m_ownedFaces,
              &v2->m_faceMap,
              index);
      if ( v10->m_numEdges > 0 )
      {
        v11 = &v2->m_ownedEdges;
        v12 = &v2->m_instancedEdges;
        do
        {
          v13 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__8(
                  v2->m_originalEdges,
                  v2->m_numOriginalEdges,
                  v12,
                  v11,
                  &v2->m_edgeMap,
                  v9 + v10->m_startEdgeIndex);
          if ( v13->m_oppositeEdge == -1 || v13->m_flags.m_storage & 0x20 )
          {
            v2->m_globalClearanceCache.m_data[v13->m_a].m_value = -16512;
            v2->m_globalClearanceCache.m_data[v13->m_b].m_value = -16512;
          }
          ++v9;
        }
        while ( v9 < v10->m_numEdges );
      }
    }
    v4 = v2->m_numOriginalFaces;
    ++index;
  }
  v14 = v2->m_ownedVertices.m_size + v2->m_numOriginalVertices;
  v20 = LODWORD(v2->m_maxGlobalClearance);
  LODWORD(v15) = (unsigned __int128)_mm_shuffle_ps((__m128)v20, (__m128)v20, 0);
  if ( v14 > 0 )
  {
    v16 = 0i64;
    do
    {
      v20 = v2->m_globalClearanceCache.m_data[v16].m_value << 16;
      if ( COERCE_FLOAT(_mm_shuffle_ps((__m128)v20, (__m128)v20, 0)) > v15 )
      {
        hkaiNavMeshTraversalUtils::computeGlobalClearance(&result, v2, &worldMediator, v5, &up);
        hkaiNavMeshTraversalUtils::updateGlobalClearance(v2, v5, &result);
      }
      ++v5;
      ++v16;
    }
    while ( v5 < v2->m_ownedVertices.m_size + v2->m_numOriginalVertices );
  }
  hkaiDynamicNavMeshQueryMediator::~hkaiDynamicNavMeshQueryMediator((hkaiDynamicNavMeshQueryMediator *)&worldMediator);
}

// File Line: 1472
// RVA: 0xBEF5C0
void __fastcall hkaiNavMeshCutter::mergeCutBoundaryEdges(hkaiNavMeshCutter *this, unsigned int originalFaceKey, unsigned int originalEdgeKey)
{
  __int64 v3; // r14
  int index; // esi
  unsigned int v5; // er12
  hkaiNavMeshCutter *v6; // r15
  hkaiNavMeshInstance *v7; // r11
  int v8; // edi
  hkaiNavMeshCutter::MeshInfo *v9; // r14
  __int64 v10; // r11
  hkaiNavMesh::Face *v11; // r13
  int v12; // eax
  signed __int64 v13; // rdi
  __int64 v14; // rbp
  __int64 v15; // rbx
  char v16; // [rsp+68h] [rbp+10h]

  v3 = originalEdgeKey >> 22;
  index = originalFaceKey & 0x3FFFFF;
  v5 = originalEdgeKey;
  v6 = this;
  v7 = this->m_streamingCollection.m_pntr->m_instances.m_data[v3].m_instancePtr;
  if ( v7->m_faceFlags.m_size )
    v16 = v7->m_faceFlags.m_data[index].m_storage;
  else
    v16 = 0;
  v8 = v7->m_numOriginalFaces;
  v9 = &this->m_meshInfos.m_data[v3];
  v11 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__8(
          v7->m_originalFaces,
          v7->m_numOriginalFaces,
          &v7->m_instancedFaces,
          &v7->m_ownedFaces,
          &v7->m_faceMap,
          index);
  if ( v16 & 1 )
  {
    v12 = v8 + *(_DWORD *)(v10 + 280);
    v13 = v9->m_magic.m_data[index];
    if ( (signed int)v13 >= 0 )
    {
      v14 = v12;
      v15 = v9->m_magic.m_data[index];
      if ( v13 < v12 )
      {
        do
        {
          if ( v9->m_magic.m_data[v15] != index )
            break;
          hkaiNavMeshCutterHelper::mergeContiguousBoundaryEdges(v6->m_streamingCollection.m_pntr, v11, v5, v13);
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
__int64 __fastcall hkaiNavMeshCutter::getClosestPointOnFaceLocal(hkaiNavMeshCutter *this, hkVector4f *position, unsigned int faceKey, hkVector4f *closestPointOut)
{
  hkVector4f *v4; // r15
  __int64 v5; // rsi
  unsigned int v6; // ebx
  int v7; // er8
  hkVector4f *v8; // r12
  hkaiNavMeshInstance *v9; // r14
  __int64 result; // rax
  __m128 v11; // xmm6
  float v12; // xmm7_4
  unsigned int v13; // edi
  int v14; // ebx
  int v15; // ebp
  __m128 v16; // xmm1
  __m128 v17; // xmm1
  float v18; // xmm2_4
  hkVector4f closestPointOuta; // [rsp+20h] [rbp-58h]
  int faceEndOut; // [rsp+80h] [rbp+8h]
  int faceStartOut; // [rsp+90h] [rbp+18h]

  v4 = closestPointOut;
  v5 = faceKey >> 22;
  v6 = faceKey;
  v7 = faceKey & 0x3FFFFF;
  v8 = position;
  v9 = this->m_streamingCollection.m_pntr->m_instances.m_data[v5].m_instancePtr;
  if ( v9->m_faceFlags.m_size )
    LOBYTE(faceStartOut) = v9->m_faceFlags.m_data[v7].m_storage;
  else
    LOBYTE(faceStartOut) = 0;
  if ( faceStartOut & 1 )
  {
    v11 = closestPointOut->m_quad;
    v12 = *(float *)&xmmword_141A712A0;
    v13 = -1;
    faceStartOut = -1;
    faceEndOut = -1;
    hkaiNavMeshCutter::getCutKeyRangeFromOriginal(this, v6, &faceStartOut, &faceEndOut);
    v14 = faceStartOut;
    if ( faceStartOut != -1 )
    {
      v15 = faceEndOut;
      if ( faceStartOut <= faceEndOut )
      {
        do
        {
          hkaiNavMeshUtils::getClosestPointOnFaceLocal(v9, v8, v14, &closestPointOuta);
          v16 = _mm_sub_ps(closestPointOuta.m_quad, v8->m_quad);
          v17 = _mm_mul_ps(v16, v16);
          v18 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 170));
          if ( v18 < v12 )
          {
            v12 = v18;
            v11 = closestPointOuta.m_quad;
            v13 = v14 | ((_DWORD)v5 << 22);
          }
          ++v14;
        }
        while ( v14 <= v15 );
      }
    }
    *v4 = (hkVector4f)v11;
    result = v13;
  }
  else
  {
    hkaiNavMeshUtils::getClosestPointOnFace(v9->m_originalMesh.m_pntr, position, v7, closestPointOut);
    result = v6;
  }
  return result;
}

// File Line: 1554
// RVA: 0xBEE9B0
__int64 __fastcall hkaiNavMeshCutter::getClosestBoundaryOnFaceLocal(hkaiNavMeshCutter *this, hkVector4f *position, unsigned int faceKey, hkVector4f *up, hkVector4f *closestPointOut)
{
  hkVector4f *v5; // r15
  __int64 v6; // rbp
  unsigned int v7; // er11
  signed int v8; // er8
  hkVector4f *v9; // r12
  hkaiNavMeshInstance *v10; // r14
  int v11; // eax
  unsigned int v12; // ebx
  hkVector4f *v13; // r13
  __m128 v14; // xmm7
  __m128 v15; // xmm6
  int v16; // edi
  int v17; // esi
  int v18; // eax
  __m128 v19; // xmm0
  hkVector4f v21; // [rsp+30h] [rbp-68h]
  int faceEndOut; // [rsp+A0h] [rbp+8h]
  int faceStartOut; // [rsp+B0h] [rbp+18h]

  v5 = up;
  v6 = faceKey >> 22;
  v7 = faceKey;
  v8 = faceKey & 0x3FFFFF;
  v9 = position;
  v10 = this->m_streamingCollection.m_pntr->m_instances.m_data[v6].m_instancePtr;
  if ( v10->m_faceFlags.m_size )
    LOBYTE(faceStartOut) = v10->m_faceFlags.m_data[v8].m_storage;
  else
    LOBYTE(faceStartOut) = 0;
  if ( faceStartOut & 1 )
  {
    v13 = closestPointOut;
    v14 = (__m128)xmmword_141A712A0;
    v15 = closestPointOut->m_quad;
    v12 = -1;
    faceStartOut = -1;
    faceEndOut = -1;
    hkaiNavMeshCutter::getCutKeyRangeFromOriginal(this, v7, &faceStartOut, &faceEndOut);
    v16 = faceStartOut;
    if ( faceStartOut != -1 )
    {
      v17 = faceEndOut;
      if ( faceStartOut <= faceEndOut )
      {
        do
        {
          v18 = hkaiNavMeshUtils::getClosestBoundaryOnFaceLocal(v10, v9, v16, v5, &v21);
          v19 = _mm_shuffle_ps(v21.m_quad, v21.m_quad, 255);
          if ( v19.m128_f32[0] < v14.m128_f32[0] )
          {
            v14 = v19;
            v15 = v21.m_quad;
            v12 = v18 | ((_DWORD)v6 << 22);
          }
          ++v16;
        }
        while ( v16 <= v17 );
      }
    }
    v13->m_quad = _mm_shuffle_ps(v15, _mm_unpackhi_ps(v15, v14), 196);
  }
  else
  {
    v11 = hkaiNavMeshUtils::getClosestBoundaryOnFace(v10->m_originalMesh.m_pntr, position, v8, up, closestPointOut);
    if ( v11 == -1 )
      v12 = -1;
    else
      v12 = v11 | ((_DWORD)v6 << 22);
  }
  return v12;
}

// File Line: 1601
// RVA: 0xBF0680
void __fastcall hkaiNavMeshCutter::makePersistentFaceKey(hkaiNavMeshCutter *this, unsigned int key, hkaiPersistentFaceKey *persistentFaceKeyOut)
{
  hkaiPersistentFaceKey *v3; // rbx
  unsigned int v4; // edi
  hkaiNavMeshCutter *v5; // rbp
  unsigned int v6; // eax
  unsigned int v7; // esi
  int v8; // eax

  v3 = persistentFaceKeyOut;
  v4 = key;
  v5 = this;
  v6 = hkaiNavMeshCutter::getOriginalFromCutKey(this, key);
  v7 = v6;
  if ( v6 == -1 )
  {
    v3->m_key = v4;
LABEL_3:
    v3->m_offset = -1;
    return;
  }
  v8 = hkaiNavMeshCutter::getFirstCutKeyFromOriginal(v5, v6);
  v3->m_key = v7;
  if ( v8 == -1 )
    goto LABEL_3;
  v3->m_offset = v4 - v8;
}

// File Line: 1633
// RVA: 0xBF07E0
void __fastcall hkaiNavMeshCutter::makePersistentFaceKey(hkaiNavMeshCutter *cutter, unsigned int key, hkaiPersistentFaceKey *persistentFaceKeyOut)
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
void __fastcall hkaiNavMeshCutter::makePersistentEdgeKey(hkaiNavMeshCutter *this, unsigned int edgeKey, unsigned int faceKey, hkaiPersistentEdgeKey *persistentEdgeKeyOut)
{
  hkaiStreamingCollection::InstanceInfo *v4; // r10
  hkaiGeneralAccessor accessor; // [rsp+30h] [rbp-28h]

  v4 = this->m_streamingCollection.m_pntr->m_instances.m_data;
  accessor.m_currentSection = -1;
  accessor.m_accessor = 0i64;
  accessor.m_sectionInfo = v4;
  hkaiNavMeshCutter::makePersistentEdgeKey(this, &accessor, edgeKey, faceKey, persistentEdgeKeyOut);
}

// File Line: 1652
// RVA: 0xBF0800
void __fastcall hkaiNavMeshCutter::makePersistentEdgeKey(hkaiNavMeshCutter *cutter, hkaiGeneralAccessor *accessor, unsigned int edgeKey, unsigned int faceKey, hkaiPersistentEdgeKey *persistentEdgeKeyOut)
{
  __int16 v5; // bp
  hkaiGeneralAccessor *v6; // rbx
  unsigned int v7; // edi

  v5 = edgeKey;
  v6 = accessor;
  v7 = faceKey;
  hkaiNavMeshCutter::makePersistentFaceKey(cutter, faceKey, &persistentEdgeKeyOut->m_faceKey);
  persistentEdgeKeyOut->m_edgeOffset = v5 - LOWORD(hkaiGeneralAccessor::getFaceFromPacked(v6, v7)->m_startEdgeIndex);
}

// File Line: 1675
// RVA: 0xBF0740
signed __int64 __fastcall hkaiNavMeshCutter::resolvePersistentFaceKey(hkaiNavMeshCutter *this, hkaiPersistentFaceKey *persistentFaceKey)
{
  __int16 v2; // si
  unsigned int v3; // ebx
  bool v4; // di
  int v6; // eax
  int faceStartOut; // [rsp+38h] [rbp+10h]
  int faceEndOut; // [rsp+40h] [rbp+18h]

  v2 = persistentFaceKey->m_offset;
  v3 = persistentFaceKey->m_key;
  v4 = v2 != -1;
  if ( v4 != ((unsigned int)hkaiNavMeshCutter::getCutKeyRangeFromOriginal(
                              this,
                              persistentFaceKey->m_key,
                              &faceStartOut,
                              &faceEndOut) != 0) )
    return 0xFFFFFFFFi64;
  if ( !v4 )
    return v3;
  if ( faceStartOut == -1 )
    return 0xFFFFFFFFi64;
  v6 = faceStartOut + v2;
  if ( v6 > faceEndOut )
    return 0xFFFFFFFFi64;
  return v3 & 0xFFC00000 | v6;
}

// File Line: 1707
// RVA: 0xBF0860
signed __int64 __fastcall hkaiNavMeshCutter::resolvePersistentFaceKey(hkaiNavMeshCutter *cutter, hkaiPersistentFaceKey *persistentFaceKey)
{
  signed __int64 result; // rax

  if ( cutter )
    result = hkaiNavMeshCutter::resolvePersistentFaceKey(cutter, persistentFaceKey);
  else
    result = persistentFaceKey->m_key;
  return result;
}

// File Line: 1720
// RVA: 0xBF0880
unsigned int __fastcall hkaiNavMeshCutter::resolvePersistentEdgeKey(hkaiNavMeshCutter *cutter, hkaiGeneralAccessor *accessor, hkaiPersistentEdgeKey *persistentEdgeKey)
{
  unsigned int faceKeyOut; // [rsp+48h] [rbp+20h]

  return hkaiNavMeshCutter::resolvePersistentEdgeKey(cutter, accessor, persistentEdgeKey, &faceKeyOut);
}

// File Line: 1727
// RVA: 0xBF08A0
signed __int64 __fastcall hkaiNavMeshCutter::resolvePersistentEdgeKey(hkaiNavMeshCutter *cutter, hkaiGeneralAccessor *accessor, hkaiPersistentEdgeKey *persistentEdgeKey, unsigned int *faceKeyOut)
{
  hkaiGeneralAccessor *v4; // rbp
  unsigned int *v5; // rdi
  hkaiPersistentEdgeKey *v6; // rsi
  unsigned int v7; // eax
  unsigned int v8; // ebx
  hkaiNavMesh::Face *v9; // rax
  __int16 v10; // cx

  v4 = accessor;
  v5 = faceKeyOut;
  v6 = persistentEdgeKey;
  v7 = hkaiNavMeshCutter::resolvePersistentFaceKey(cutter, &persistentEdgeKey->m_faceKey);
  v8 = v7;
  *v5 = v7;
  if ( v7 == -1 )
    return 0xFFFFFFFFi64;
  v9 = hkaiGeneralAccessor::getFaceFromPacked(v4, v7);
  v10 = v6->m_edgeOffset;
  if ( v10 == -1 )
    return 0xFFFFFFFFi64;
  if ( v10 >= v9->m_numEdges )
  {
    *v5 = -1;
    return 0xFFFFFFFFi64;
  }
  return v8 & 0xFFC00000 | (v9->m_startEdgeIndex + v10);
}


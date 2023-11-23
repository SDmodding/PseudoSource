// File Line: 116
// RVA: 0xC19D80
void __fastcall gatherEdgeMap(
        hkaiStreamingCollection *collection,
        hkArrayBase<hkaiFaceCutResults> *results,
        hkPointerMap<unsigned int,hkArray<unsigned int,hkContainerHeapAllocator> *,hkContainerTempAllocator> *edgeMap,
        hkArray<unsigned int,hkContainerTempAllocator> *unmappedEdges)
{
  int v4; // ebp
  hkArray<unsigned int,hkContainerTempAllocator> *v5; // r15
  hkaiStreamingCollection *v6; // r8
  unsigned int v7; // edi
  __int64 v8; // rcx
  hkaiStreamingCollection::InstanceInfo *m_data; // rax
  char *v10; // rsi
  int v11; // edx
  hkaiNavMeshInstance *m_instancePtr; // r13
  int m_size; // ebp
  hkaiNavMesh::Face *m_originalFaces; // rcx
  int m_numOriginalFaces; // edx
  hkaiNavMesh::Face *v16; // rax
  unsigned int v17; // r11d
  char v18; // r12
  int v19; // ecx
  int m_numEdges; // ebx
  int v21; // r12d
  __int64 v22; // r8
  char *v23; // rdi
  int v24; // eax
  unsigned __int64 v25; // rcx
  int *v26; // r14
  int v27; // eax
  __int64 v28; // rdx
  int v29; // esi
  int v30; // r15d
  int v31; // ebp
  int v32; // edi
  char *v33; // rax
  unsigned int v34; // ebx
  unsigned int v35; // edi
  int v36; // ebx
  unsigned __int64 v37; // rsi
  _DWORD *v38; // rdi
  _QWORD **Value; // rax
  __int64 v40; // rax
  __int64 v41; // r9
  int v42; // edx
  __int64 v43; // rcx
  _DWORD *v44; // rax
  __int64 v45; // r14
  int v46; // ebx
  __int64 v47; // rsi
  unsigned int v48; // r12d
  int v49; // ebp
  bool v50; // cc
  int index; // [rsp+28h] [rbp-A0h]
  int indexa; // [rsp+28h] [rbp-A0h]
  char v53; // [rsp+30h] [rbp-98h] BYREF
  char v54; // [rsp+31h] [rbp-97h] BYREF
  unsigned int v55; // [rsp+34h] [rbp-94h]
  int v56; // [rsp+38h] [rbp-90h]
  int v57; // [rsp+3Ch] [rbp-8Ch]
  _BYTE *array; // [rsp+40h] [rbp-88h] BYREF
  int v59; // [rsp+48h] [rbp-80h]
  int v60; // [rsp+4Ch] [rbp-7Ch]
  int v61; // [rsp+50h] [rbp-78h]
  int v62; // [rsp+54h] [rbp-74h]
  hkaiNavMesh::Face *v63; // [rsp+58h] [rbp-70h]
  unsigned int v64; // [rsp+60h] [rbp-68h]
  hkResult result; // [rsp+64h] [rbp-64h] BYREF
  __int64 v66; // [rsp+68h] [rbp-60h]
  __int64 v67; // [rsp+70h] [rbp-58h]
  hkArrayBase<hkaiFaceCutResults> *v69; // [rsp+D8h] [rbp+10h]

  v69 = results;
  v4 = -1;
  v5 = unmappedEdges;
  v6 = collection;
  v61 = -1;
  v57 = -1;
  v7 = -1;
  v62 = 0;
  if ( results->m_size > 0 )
  {
    v8 = 0i64;
    v67 = 0i64;
    while ( 1 )
    {
      m_data = v6->m_instances.m_data;
      v10 = (char *)results->m_data + v8;
      v11 = *(_DWORD *)v10;
      v55 = *(_DWORD *)v10 >> 22;
      m_instancePtr = m_data[v55].m_instancePtr;
      if ( v55 != v7 )
      {
        m_size = m_instancePtr->m_ownedFaces.m_size;
        v57 = 0;
        v4 = m_instancePtr->m_numOriginalFaces + m_size;
        v61 = v4;
      }
      m_originalFaces = m_instancePtr->m_originalFaces;
      index = v11 & 0x3FFFFF;
      m_numOriginalFaces = m_instancePtr->m_numOriginalFaces;
      v64 = v55;
      v16 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__15(
              m_originalFaces,
              m_numOriginalFaces,
              &m_instancePtr->m_instancedFaces,
              &m_instancePtr->m_ownedFaces,
              &m_instancePtr->m_faceMap,
              index);
      v18 = v10[16];
      v19 = 0;
      array = 0i64;
      v60 = 0x80000000;
      v59 = 0;
      m_numEdges = v16->m_numEdges;
      v21 = v18 & 1;
      v22 = (__int64)v16;
      v63 = v16;
      if ( m_numEdges <= 0 )
      {
        result.m_enum = HK_SUCCESS;
      }
      else
      {
        hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, m_numEdges, 1);
        v19 = v59;
        v22 = (__int64)v63;
        v17 = v55;
      }
      v23 = &array[v19];
      v24 = m_numEdges - v19;
      v25 = m_numEdges - v19;
      if ( v24 > 0 )
        memset(v23, 0, v25);
      v59 = m_numEdges;
      v26 = 0i64;
      if ( v21 )
        break;
      v27 = *((__int16 *)v10 + 2);
      v26 = (int *)*((_QWORD *)v10 + 3);
      if ( v27 > 0 )
        goto LABEL_12;
LABEL_45:
      v45 = (__int64)v63;
      v46 = 0;
      v47 = 0i64;
      if ( v63->m_numEdges > 0 )
      {
        v48 = v55;
        do
        {
          v49 = v46 + *(_DWORD *)v45;
          if ( !array[v47]
            && hkaiNavMeshInstance_get_hkaiNavMesh::Edge__17(
                 m_instancePtr->m_originalEdges,
                 m_instancePtr->m_numOriginalEdges,
                 &m_instancePtr->m_instancedEdges,
                 &m_instancePtr->m_ownedEdges,
                 &m_instancePtr->m_edgeMap,
                 v46 + *(_DWORD *)v45)->m_oppositeEdge != -1 )
          {
            if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, v5, 4);
            v5->m_data[v5->m_size++] = v49 | (v48 << 22);
          }
          ++v46;
          ++v47;
        }
        while ( v46 < *(__int16 *)(v45 + 8) );
      }
      v59 = 0;
      if ( v60 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, v60 & 0x3FFFFFFF);
      results = v69;
      v4 = v61;
      v6 = collection;
      v8 = v67 + 32;
      v50 = ++v62 < v69->m_size;
      v7 = v64;
      array = 0i64;
      v60 = 0x80000000;
      v67 += 32i64;
      if ( !v50 )
        return;
    }
    v27 = 1;
LABEL_12:
    v28 = (unsigned int)v27;
    v29 = v57 + v4;
    v66 = (unsigned int)v27;
    v56 = v57 + v4;
    v57 += v27;
    do
    {
      if ( v21 )
        v30 = *(__int16 *)(v22 + 8);
      else
        v30 = *v26;
      v31 = 0;
      if ( v30 > 0 )
      {
        do
        {
          if ( v21 )
          {
            v32 = v31;
            v53 = 0;
            v33 = &v53;
          }
          else
          {
            v32 = v26[*v26 + 2 + v31];
            v54 = *((_BYTE *)&v26[2 * *v26 + 2] + v31) & 3;
            v33 = &v54;
          }
          if ( !*v33 )
          {
            array[v32] = 1;
            v34 = v17 << 22;
            indexa = v32 + *(_DWORD *)v22;
            v35 = indexa | (v17 << 22);
            if ( hkaiNavMeshInstance_get_hkaiNavMesh::Edge__17(
                   m_instancePtr->m_originalEdges,
                   m_instancePtr->m_numOriginalEdges,
                   &m_instancePtr->m_instancedEdges,
                   &m_instancePtr->m_ownedEdges,
                   &m_instancePtr->m_edgeMap,
                   indexa)->m_oppositeEdge != -1 )
            {
              v36 = v29 | v34;
              v37 = v35;
              v38 = (_DWORD *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                &edgeMap->m_map,
                                v35,
                                0i64);
              if ( !v38 )
              {
                Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
                v40 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 16i64);
                v38 = (_DWORD *)v40;
                if ( v40 )
                {
                  *(_QWORD *)v40 = 0i64;
                  *(_DWORD *)(v40 + 8) = 0;
                  *(_DWORD *)(v40 + 12) = 0x80000000;
                }
                else
                {
                  v38 = 0i64;
                }
                hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                  &edgeMap->m_map,
                  &hkContainerTempAllocator::s_alloc,
                  v37,
                  (unsigned __int64)v38);
              }
              v41 = (int)v38[2];
              v42 = 0;
              v43 = 0i64;
              if ( (int)v41 <= 0 )
                goto LABEL_34;
              v44 = *(_DWORD **)v38;
              while ( *v44 != v36 )
              {
                ++v43;
                ++v42;
                ++v44;
                if ( v43 >= v41 )
                  goto LABEL_34;
              }
              if ( v42 == -1 )
              {
LABEL_34:
                if ( (_DWORD)v41 == (v38[3] & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v38, 4);
                *(_DWORD *)(*(_QWORD *)v38 + 4i64 * (int)v38[2]++) = v36;
              }
              v29 = v56;
            }
          }
          v22 = (__int64)v63;
          v17 = v55;
          ++v31;
        }
        while ( v31 < v30 );
        v28 = v66;
      }
      if ( v21 )
        v26 = 0i64;
      else
        v26 = (int *)((char *)v26 + (int)(((*v26 + 3) & 0xFFFFFFFC) + 8 * *v26 + 8));
      v22 = (__int64)v63;
      v17 = v55;
      ++v29;
      --v28;
      v56 = v29;
      v66 = v28;
    }
    while ( v28 );
    v5 = unmappedEdges;
    goto LABEL_45;
  }
}

// File Line: 216
// RVA: 0xC1A270
void __fastcall addFacesForCut(
        hkaiNavMeshInstance *meshInstance,
        hkaiFaceCutResults *res,
        hkArray<int,hkContainerHeapAllocator> *magic,
        hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > *exactEdges)
{
  unsigned int m_originalFace; // edi
  char m_storage; // r13
  int m_numOriginalFaces; // edx
  int v8; // eax
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_ownedFaces; // r9
  int index; // edi
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rax
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_instancedFaces; // r8
  hkaiNavMesh::Face *m_originalFaces; // rcx
  int v15; // r13d
  hkArrayBase<hkVector4f> *v16; // r9
  hkaiNavMeshUtils *v17; // r11
  char *m_data; // r12
  int m_numEdges; // edi
  int m_numPolys; // esi
  __int64 v21; // rdx
  int i; // edi
  __int64 v23; // rcx
  char v24; // bl
  __int64 m_size; // rdi
  int v26; // eax
  int v27; // eax
  int *v28; // rax
  __int64 v29; // rcx
  int *v30; // rdi
  int v31; // eax
  hkaiNavMeshInstance *v32; // r14
  int m_memSizeAndFlags; // edi
  int v34; // edi
  hkLifoAllocator *Value; // rcx
  char *m_cur; // rax
  int v37; // edx
  char *v38; // r8
  hkaiNavMeshInstance *v39; // rdi
  hkVector4f *v40; // rdx
  int m_numVertices; // r8d
  int v42; // r15d
  int v43; // r13d
  int v44; // esi
  int v45; // edi
  __int16 v46; // ax
  int v47; // eax
  int v48; // edx
  hkaiNavMeshInstance::AddEdgeContext *v49; // r9
  int v50; // edi
  __int64 v51; // rdx
  unsigned int *p_m_oppositeEdge; // rcx
  int v53; // esi
  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > *v54; // rbx
  int *v55; // rax
  unsigned int *p_m_oppositeFace; // r14
  int v57; // edi
  int v58; // edx
  int v59; // r13d
  int v60; // ecx
  int v61; // edx
  hkaiNavMeshInstance **p_result; // rax
  char v63; // di
  int v64; // edi
  __int64 v65; // rdx
  int v66; // ecx
  int v67; // eax
  int v68; // r15d
  int v69; // edx
  char v70; // cl
  __int64 v71; // rax
  int v72; // esi
  int v73; // edx
  char *v74; // rax
  int v75; // r8d
  unsigned int v76; // edi
  unsigned int *v77; // r9
  int v78; // r8d
  int v79; // eax
  unsigned int v80; // edx
  bool v81; // zf
  int v82; // eax
  char *v83; // rbx
  signed int v84; // edi
  hkLifoAllocator *v85; // rax
  int v86; // r8d
  char v87; // [rsp+30h] [rbp-C8h]
  char v88; // [rsp+31h] [rbp-C7h] BYREF
  char v89; // [rsp+32h] [rbp-C6h] BYREF
  char v90; // [rsp+33h] [rbp-C5h] BYREF
  int fIdx; // [rsp+34h] [rbp-C4h]
  int v92; // [rsp+38h] [rbp-C0h]
  hkaiNavMeshInstance *mesh; // [rsp+40h] [rbp-B8h]
  int v94; // [rsp+48h] [rbp-B0h] BYREF
  int v95; // [rsp+4Ch] [rbp-ACh]
  int v96; // [rsp+50h] [rbp-A8h]
  hkaiNavMesh::Face face; // [rsp+58h] [rbp-A0h] BYREF
  void *p; // [rsp+68h] [rbp-90h]
  int v99; // [rsp+70h] [rbp-88h]
  hkaiNavMeshInstance::AddEdgeContext *array; // [rsp+78h] [rbp-80h] BYREF
  int v101; // [rsp+80h] [rbp-78h]
  int v102; // [rsp+84h] [rbp-74h]
  int v103; // [rsp+88h] [rbp-70h]
  int v104; // [rsp+8Ch] [rbp-6Ch]
  int v105; // [rsp+90h] [rbp-68h]
  int v106; // [rsp+94h] [rbp-64h]
  int eIdx; // [rsp+98h] [rbp-60h]
  int v108; // [rsp+9Ch] [rbp-5Ch]
  hkaiNavMeshInstance::AddFaceContext ctx; // [rsp+A0h] [rbp-58h] BYREF
  char *v110; // [rsp+C8h] [rbp-30h]
  __int64 v111; // [rsp+D0h] [rbp-28h]
  hkResult v112; // [rsp+D8h] [rbp-20h] BYREF
  hkaiNavMeshUtils *retaddr; // [rsp+128h] [rbp+30h]
  hkaiNavMeshInstance *result; // [rsp+130h] [rbp+38h] BYREF
  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > *v115; // [rsp+140h] [rbp+48h]
  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > *v116; // [rsp+148h] [rbp+50h]

  v116 = exactEdges;
  result = meshInstance;
  m_originalFace = res->m_originalFace;
  m_storage = res->m_flags.m_storage;
  m_numOriginalFaces = meshInstance->m_numOriginalFaces;
  v8 = m_originalFace >> 22;
  p_m_ownedFaces = &meshInstance->m_ownedFaces;
  index = m_originalFace & 0x3FFFFF;
  v95 = v8;
  instanceMap = &meshInstance->m_faceMap;
  p_m_instancedFaces = &meshInstance->m_instancedFaces;
  m_originalFaces = meshInstance->m_originalFaces;
  v15 = m_storage & 1;
  fIdx = index;
  v92 = v15;
  v102 = 0x80000000;
  mesh = (hkaiNavMeshInstance *)hkaiNavMeshInstance_get_hkaiNavMesh::Face__15(
                                  m_originalFaces,
                                  m_numOriginalFaces,
                                  p_m_instancedFaces,
                                  p_m_ownedFaces,
                                  instanceMap,
                                  index);
  array = 0i64;
  v101 = 0;
  m_data = 0i64;
  if ( v15 )
  {
    m_numPolys = 1;
  }
  else
  {
    m_numEdges = res->m_numEdges;
    m_data = res->m_data;
    m_numPolys = res->m_numPolys;
    if ( m_numEdges > 0 )
    {
      hkArrayUtil::_reserve((hkResult *)&result, &hkContainerTempAllocator::s_alloc, &array, res->m_numEdges, 4);
      v17 = retaddr;
    }
    v101 = m_numEdges;
    v21 = 0i64;
    for ( i = 0; i < m_numPolys; m_data += (int)(((*(_DWORD *)m_data + 3) & 0xFFFFFFFC) + 8 * *(_DWORD *)m_data + 8) )
    {
      if ( *(int *)m_data > 0 )
      {
        v23 = *(unsigned int *)m_data;
        do
        {
          *((_DWORD *)array + v21++) = i;
          --v23;
        }
        while ( v23 );
      }
      ++i;
    }
    index = fIdx;
  }
  if ( *(_DWORD *)&v17[328] )
    LOBYTE(result) = *(_BYTE *)(index + *(_QWORD *)&v17[320]);
  else
    LOBYTE(result) = 0;
  v24 = (unsigned __int8)result ^ 2;
  v87 = (unsigned __int8)result ^ 2;
  *(_BYTE *)(index + *(_QWORD *)&v17[320]) = (unsigned __int8)result ^ 1;
  v103 = *(_DWORD *)&v17[40] + *(_DWORD *)&v17[296];
  v106 = *(_DWORD *)&v17[24] + *(_DWORD *)&v17[280];
  if ( m_numPolys )
  {
    magic->m_data[index] = magic->m_size;
    m_size = magic->m_size;
    v16 = (hkArrayBase<hkVector4f> *)(unsigned int)(m_size + m_numPolys);
    v26 = magic->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v26 < (int)v16 )
    {
      v27 = 2 * v26;
      if ( (int)v16 < v27 )
        LODWORD(v16) = v27;
      hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, magic, (int)v16, 4);
    }
    v28 = magic->m_data;
    magic->m_size += m_numPolys;
    v29 = m_numPolys;
    v30 = &v28[m_size];
    if ( m_numPolys > 0 )
    {
      v31 = fIdx;
      while ( v29 )
      {
        *v30++ = v31;
        --v29;
      }
    }
  }
  else
  {
    magic->m_data[index] = -2;
  }
  v32 = (hkaiNavMeshInstance *)retaddr;
  v104 = *(_DWORD *)&retaddr[56] + *(_DWORD *)&retaddr[312];
  m_memSizeAndFlags = (__int16)mesh->m_memSizeAndFlags;
  *(_QWORD *)&face.m_startEdgeIndex = 0i64;
  *(_DWORD *)&face.m_numEdges = 0;
  v34 = m_memSizeAndFlags + 1;
  *(_DWORD *)&face.m_clusterIndex = 0x80000000;
  v99 = v34;
  if ( v34 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)Value->m_cur;
    v37 = (16 * v34 + 127) & 0xFFFFFF80;
    v38 = &m_cur[v37];
    if ( v37 > Value->m_slabSize || v38 > Value->m_end )
      m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v37);
    else
      Value->m_cur = v38;
  }
  else
  {
    m_cur = 0i64;
  }
  *(_QWORD *)&face.m_startEdgeIndex = m_cur;
  p = m_cur;
  *(_DWORD *)&face.m_clusterIndex = v34 | 0x80000000;
  v39 = mesh;
  if ( v15 )
  {
    *(_DWORD *)&face.m_numEdges = (__int16)mesh->m_memSizeAndFlags + 1;
    hkaiNavMeshUtils::getFaceLocalVertices<hkaiNavMeshInstance>(retaddr, mesh, &face, v16);
    v40 = *(hkVector4f **)&face.m_startEdgeIndex;
    m_numVertices = (__int16)mesh->m_memSizeAndFlags;
  }
  else
  {
    m_data = res->m_data;
    m_numVertices = res->m_numVertices;
    v40 = (hkVector4f *)&m_data[(9 * res->m_numEdges + 11 * res->m_numPolys + 15i64) & 0xFFFFFFFFFFFFFFF0ui64];
  }
  hkaiNavMeshInstance::appendVertices((hkaiNavMeshInstance *)retaddr, v40, m_numVertices);
  if ( m_numPolys > 0 )
  {
    v42 = v15;
    v111 = (unsigned int)m_numPolys;
    do
    {
      if ( v42 )
      {
        v43 = (__int16)v39->m_memSizeAndFlags;
        v44 = -1;
      }
      else
      {
        v43 = *(_DWORD *)m_data;
        v44 = *((_DWORD *)m_data + 1);
      }
      v45 = v32->m_numOriginalEdges + v32->m_ownedEdges.m_size;
      v96 = v43;
      *(_QWORD *)ctx.m_data = 0i64;
      *(_QWORD *)&ctx.m_data[2] = 0i64;
      hkaiNavMeshInstance::getFaceDataForContext(v32, fIdx, &ctx);
      ctx.m_face.m_numUserEdges = 0;
      ctx.m_face.m_padding = -12851;
      v46 = *(&mesh->m_referenceCount + 1);
      ctx.m_face.m_startUserEdgeIndex = -1;
      ctx.m_face.m_clusterIndex = v46;
      v47 = ctx.m_data[0];
      ctx.m_flags.m_storage = v24;
      if ( v44 != -1 )
        v47 = v44;
      ctx.m_face.m_numEdges = v43;
      ctx.m_face.m_startEdgeIndex = v45;
      ctx.m_data[0] = v47;
      hkaiNavMeshInstance::appendFaces(v32, &ctx, 1);
      v48 = v43;
      if ( v43 )
      {
        v94 = 40 * v43;
        v49 = (hkaiNavMeshInstance::AddEdgeContext *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                                       &hkContainerTempAllocator::s_alloc,
                                                       &v94);
        v48 = v94 / 40;
      }
      else
      {
        v49 = 0i64;
      }
      v50 = 0x80000000;
      array = v49;
      if ( v48 )
        v50 = v48;
      v51 = v43;
      v105 = v50;
      if ( v43 > 0 )
      {
        p_m_oppositeEdge = &v49->m_edge.m_oppositeEdge;
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
          --v51;
        }
        while ( v51 );
        v42 = v92;
      }
      v53 = 0;
      if ( v43 > 0 )
      {
        v54 = v115;
        v55 = (int *)(m_data + 8);
        p_m_oppositeFace = &v49->m_edge.m_oppositeFace;
        v110 = m_data + 8;
        do
        {
          v57 = v53;
          if ( !v42 )
            v57 = *v55;
          v108 = v53 + 1;
          v58 = (v53 + 1) % v43;
          v59 = v58;
          if ( v42 )
            v60 = v58;
          else
            v60 = *(_DWORD *)&m_data[4 * v58 + 8];
          v61 = v104;
          *(_QWORD *)(p_m_oppositeFace - 1) = -1i64;
          p_m_oppositeFace[1] = 4;
          *(p_m_oppositeFace - 3) = v57 + v61;
          *(p_m_oppositeFace - 2) = v60 + v61;
          if ( v42 )
          {
            LOBYTE(result) = 0;
            p_result = &result;
          }
          else
          {
            p_result = (hkaiNavMeshInstance **)&v89;
            v89 = m_data[8 * *(_DWORD *)m_data + 8 + v53];
          }
          v63 = *(_BYTE *)p_result;
          if ( (*(_BYTE *)p_result & 3) == 2 )
          {
            v64 = v95 << 22;
            v65 = *(int *)&m_data[4 * v53 + 8 + 4 * *(_DWORD *)m_data];
            v66 = *(&array->m_edge.m_a + v65);
            v67 = v103;
            *((_BYTE *)p_m_oppositeFace + 4) = 6;
            *p_m_oppositeFace = (v106 + v66) | v64;
            *(p_m_oppositeFace - 1) = v64 | (v65 + v67);
          }
          else if ( (v63 & 3) == 1 )
          {
            *(_QWORD *)(p_m_oppositeFace - 1) = -1i64;
            *((_BYTE *)p_m_oppositeFace + 4) = 5;
          }
          else
          {
            if ( v42 )
              v68 = v53;
            else
              v68 = *(_DWORD *)&m_data[4 * v53 + 8 + 4 * *(_DWORD *)m_data];
            v69 = *(_DWORD *)&retaddr[40];
            eIdx = v68 + LODWORD(mesh->vfptr);
            v70 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__17(
                    *(hkaiNavMesh::Edge **)&retaddr[32],
                    v69,
                    (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&retaddr[256],
                    (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&retaddr[288],
                    (hkArray<int,hkContainerHeapAllocator> *)&retaddr[208],
                    eIdx)->m_flags.m_storage;
            v71 = v53;
            v72 = eIdx;
            v73 = eIdx;
            *((_BYTE *)p_m_oppositeFace + 4) = v70 & 0x40 | 4;
            hkaiNavMeshInstance::getEdgeDataForContext((hkaiNavMeshInstance *)retaddr, v73, &array[v71]);
            *((_WORD *)p_m_oppositeFace + 12) = v68;
            v42 = v92;
            if ( v92 )
            {
              v88 = 0;
              v74 = &v88;
            }
            else
            {
              v74 = &v90;
              v90 = m_data[8 * *(_DWORD *)m_data + 8 + v59];
            }
            if ( (v63 & 4) == 0 && (*v74 & 4) == 0 )
            {
              v75 = v54->m_elem.m_size;
              v76 = v72 | (v95 << 22);
              if ( 2 * v54->m_numElems > v75 - 1 )
                hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int>>::resizeTable(
                  v54,
                  &v112,
                  2 * v75);
              v77 = v54->m_elem.m_data;
              v78 = v54->m_elem.m_size - 1;
              v79 = v78 & (-1640531535 * (v76 >> 4));
              v80 = v54->m_elem.m_data[v79];
              if ( v80 == -1 )
              {
LABEL_78:
                ++v54->m_numElems;
                v77[v79] = v76;
              }
              else
              {
                while ( v80 != v76 )
                {
                  v79 = v78 & (v79 + 1);
                  v80 = v77[v79];
                  if ( v80 == -1 )
                    goto LABEL_78;
                }
                v54->m_numElems = v54->m_numElems;
                v77[v79] = v76;
              }
            }
          }
          v53 = v108;
          v43 = v96;
          v55 = (int *)(v110 + 4);
          p_m_oppositeFace += 10;
          v110 += 4;
        }
        while ( v108 < v96 );
        v24 = v87;
        v32 = (hkaiNavMeshInstance *)retaddr;
        v50 = v105;
        v49 = array;
      }
      hkaiNavMeshInstance::appendEdges(v32, v49, v43);
      if ( v42 )
        m_data = 0i64;
      else
        m_data += (int)(((*(_DWORD *)m_data + 3) & 0xFFFFFFFC) + 8 * *(_DWORD *)m_data + 8);
      if ( v50 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          array,
          40 * (v50 & 0x3FFFFFFF));
      v81 = v111-- == 1;
      v39 = mesh;
    }
    while ( !v81 );
  }
  v82 = *(_DWORD *)&face.m_numEdges;
  v83 = (char *)p;
  if ( p == *(void **)&face.m_startEdgeIndex )
    v82 = 0;
  *(_DWORD *)&face.m_numEdges = v82;
  v84 = (16 * v99 + 127) & 0xFFFFFF80;
  v85 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v86 = (v84 + 15) & 0xFFFFFFF0;
  if ( v84 > v85->m_slabSize || &v83[v86] != v85->m_cur || v85->m_firstNonLifoEnd == v83 )
    hkLifoAllocator::slowBlockFree(v85, v83, v86);
  else
    v85->m_cur = v83;
  *(_DWORD *)&face.m_numEdges = 0;
  if ( *(int *)&face.m_clusterIndex >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)&face.m_startEdgeIndex,
      16 * *(_DWORD *)&face.m_clusterIndex);
  *(_QWORD *)&face.m_startEdgeIndex = 0i64;
  v101 = 0;
  *(_DWORD *)&face.m_clusterIndex = 0x80000000;
  if ( v102 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v102);
}hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v102);
}

// File Line: 394
// RVA: 0xC18C50
void __fastcall hkaiNavMeshCutter::removeUnusedCutEdges(hkaiNavMeshCutter *this, hkArrayBase<int> *cutSections)
{
  int v2; // ebx
  __int64 v5; // rdi
  hkaiNavMeshInstance *m_instancePtr; // rcx

  v2 = 0;
  if ( cutSections->m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      m_instancePtr = this->m_streamingCollection.m_pntr->m_instances.m_data[cutSections->m_data[v5]].m_instancePtr;
      if ( m_instancePtr )
        hkaiNavMeshUtils::compactInstancedEdges(m_instancePtr);
      ++v2;
      ++v5;
    }
    while ( v2 < cutSections->m_size );
  }
}

// File Line: 476
// RVA: 0xC1AE40
_BOOL8 __fastcall CutResultCompare(hkaiFaceCutResults *res1, hkaiFaceCutResults *res2)
{
  return res1->m_originalFace < res2->m_originalFace;
}

// File Line: 481
// RVA: 0xC199A0
void __fastcall hkaiNavMeshCutter::matchStreamingFaces(
        hkaiNavMeshCutter *this,
        hkArrayBase<int> *cutSections,
        hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > *cutFaces)
{
  int v4; // r8d
  hkArrayBase<int> *v5; // rax
  __int64 v7; // rcx
  int v8; // r15d
  __int64 v9; // rax
  hkaiNavMeshInstance *m_instancePtr; // rdx
  __int64 p_m_streamingSets; // r13
  __int64 v12; // rdi
  int SectionIdByUid; // r14d
  int v14; // r12d
  __int64 v15; // rdx
  int v16; // r11d
  __int64 v17; // r13
  _DWORD *v18; // r10
  int v19; // r8d
  unsigned int v20; // edi
  int v21; // eax
  unsigned int v22; // edx
  int v23; // ecx
  int v24; // esi
  int v25; // eax
  int v26; // r14d
  int v27; // r15d
  bool v28; // bl
  bool v29; // al
  __int64 v30; // rdx
  hkArray<hkaiNavMeshCutter::FaceEdgePair,hkContainerTempAllocator> v31; // [rsp+18h] [rbp-49h] BYREF
  hkArray<hkaiNavMeshCutter::FaceEdgePair,hkContainerTempAllocator> cutPairs; // [rsp+28h] [rbp-39h] BYREF
  int v33; // [rsp+38h] [rbp-29h]
  int v34; // [rsp+3Ch] [rbp-25h]
  int v35; // [rsp+40h] [rbp-21h]
  hkaiNavMeshInstance *v36; // [rsp+48h] [rbp-19h]
  int v37; // [rsp+50h] [rbp-11h]
  __int64 v38; // [rsp+58h] [rbp-9h]
  __int64 v39; // [rsp+60h] [rbp-1h]
  __int64 *v40; // [rsp+68h] [rbp+7h]
  hkaiNavMeshCutter *v41; // [rsp+C8h] [rbp+67h]
  hkArrayBase<int> *vars0; // [rsp+D0h] [rbp+6Fh]
  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > *retaddr; // [rsp+D8h] [rbp+77h]
  int v44; // [rsp+E0h] [rbp+7Fh]

  v4 = 0;
  v5 = cutSections;
  v33 = 0;
  if ( cutSections->m_size > 0 )
  {
    v7 = 0i64;
    v38 = 0i64;
    do
    {
      v8 = 0;
      v9 = *(int *)((char *)v5->m_data + v7);
      v35 = 0;
      v37 = v9;
      m_instancePtr = this->m_streamingCollection.m_pntr->m_instances.m_data[v9].m_instancePtr;
      v36 = m_instancePtr;
      p_m_streamingSets = (__int64)&m_instancePtr->m_originalMesh.m_pntr->m_streamingSets;
      v40 = (__int64 *)p_m_streamingSets;
      if ( *(int *)(p_m_streamingSets + 8) > 0 )
      {
        v12 = 0i64;
        v39 = 0i64;
        do
        {
          if ( m_instancePtr->m_sectionUid == *(_DWORD *)(*(_QWORD *)p_m_streamingSets + v12) )
          {
            SectionIdByUid = hkaiStreamingCollection::findSectionIdByUid(
                               this->m_streamingCollection.m_pntr,
                               *(_DWORD *)(*(_QWORD *)p_m_streamingSets + v12 + 4));
            v34 = SectionIdByUid;
            if ( SectionIdByUid != -1 )
            {
              v14 = 0;
              v15 = v12 + *(_QWORD *)p_m_streamingSets;
              if ( *(int *)(v15 + 16) > 0 )
              {
                v16 = v37 << 22;
                v17 = 0i64;
                v44 = v37 << 22;
                do
                {
                  v18 = (_DWORD *)(v17 + *(_QWORD *)(v15 + 8));
                  v19 = cutFaces->m_elem.m_size - 1;
                  cutPairs.m_data = 0i64;
                  cutPairs.m_size = 0;
                  cutPairs.m_capacityAndFlags = 0x80000000;
                  v31.m_data = 0i64;
                  v31.m_size = 0;
                  v31.m_capacityAndFlags = 0x80000000;
                  v20 = *v18 | v16;
                  if ( v19 <= 0
                    || (v21 = v19 & (-1640531535 * (v20 >> 4)), v22 = cutFaces->m_elem.m_data[v21], v22 == -1) )
                  {
LABEL_13:
                    v23 = v19 + 1;
                  }
                  else
                  {
                    while ( v22 != v20 )
                    {
                      v21 = v19 & (v21 + 1);
                      v22 = cutFaces->m_elem.m_data[v21];
                      if ( v22 == -1 )
                        goto LABEL_13;
                    }
                    v23 = v21;
                  }
                  if ( v23 <= v19 )
                  {
                    v24 = v16 | v18[1];
                    v25 = SectionIdByUid << 22;
                    v26 = (SectionIdByUid << 22) | v18[2];
                    v27 = v25 | v18[3];
                    v28 = hkaiStreamingCollection::areKeysConsistent(this->m_streamingCollection.m_pntr, v20, v24);
                    v29 = hkaiStreamingCollection::areKeysConsistent(v41->m_streamingCollection.m_pntr, v26, v27);
                    if ( v28 && v29 )
                    {
                      this = v41;
                      hkaiNavMeshCutter::mergeCutBoundaryEdges(v41, v20, v24);
                      hkaiNavMeshCutter::mergeCutBoundaryEdges(this, v26, v27);
                      hkaiNavMeshCutter::gatherCutEdges(this, v24, v20, &cutPairs, GATHER_BOUNDARY_EDGES);
                      hkaiNavMeshCutter::gatherCutEdges(this, v27, v26, &v31, GATHER_BOUNDARY_EDGES);
                      hkaiNavMeshCutter::matchNewEdgesFromOriginalEdge(
                        this,
                        this->m_streamingCollection.m_pntr,
                        &cutPairs,
                        &v31);
                      v31.m_size = 0;
                      if ( v31.m_capacityAndFlags >= 0 )
                        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                          &hkContainerTempAllocator::s_alloc,
                          v31.m_data,
                          8 * v31.m_capacityAndFlags);
                      v31.m_data = 0i64;
                      v31.m_capacityAndFlags = 0x80000000;
                      cutPairs.m_size = 0;
                      if ( cutPairs.m_capacityAndFlags >= 0 )
                        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                          &hkContainerTempAllocator::s_alloc,
                          cutPairs.m_data,
                          8 * cutPairs.m_capacityAndFlags);
                    }
                    else
                    {
                      v31.m_size = 0;
                      if ( v31.m_capacityAndFlags >= 0 )
                        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                          &hkContainerTempAllocator::s_alloc,
                          v31.m_data,
                          8 * v31.m_capacityAndFlags);
                      v31.m_data = 0i64;
                      v31.m_capacityAndFlags = 0x80000000;
                      cutPairs.m_size = 0;
                      if ( cutPairs.m_capacityAndFlags >= 0 )
                        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                          &hkContainerTempAllocator::s_alloc,
                          cutPairs.m_data,
                          8 * cutPairs.m_capacityAndFlags);
                      this = v41;
                    }
                    SectionIdByUid = v34;
                    cutFaces = retaddr;
                    v16 = v44;
                  }
                  else
                  {
                    v31.m_size = 0;
                    v31.m_data = 0i64;
                    v31.m_capacityAndFlags = 0x80000000;
                    cutPairs.m_size = 0;
                  }
                  v12 = v39;
                  ++v14;
                  v30 = *v40;
                  v17 += 16i64;
                  cutPairs.m_data = 0i64;
                  v15 = v39 + v30;
                  cutPairs.m_capacityAndFlags = 0x80000000;
                }
                while ( v14 < *(_DWORD *)(v15 + 16) );
                v8 = v35;
                p_m_streamingSets = (__int64)v40;
              }
            }
            m_instancePtr = v36;
          }
          ++v8;
          v12 += 56i64;
          v35 = v8;
          v39 = v12;
        }
        while ( v8 < *(_DWORD *)(p_m_streamingSets + 8) );
        v4 = v33;
      }
      v5 = vars0;
      ++v4;
      v7 = v38 + 4;
      v33 = v4;
      v38 += 4i64;
    }
    while ( v4 < vars0->m_size );
  }
}

// File Line: 542
// RVA: 0xC18CD0
void __fastcall hkaiNavMeshCutter::applyCutResults(
        hkaiNavMeshCutter *this,
        hkArrayBase<int> *cutSections,
        hkArray<hkaiFaceCutResults,hkContainerTempAllocator> *results,
        hkArray<unsigned int,hkContainerTempAllocator> *cutFaces)
{
  hkArray<unsigned int,hkContainerTempAllocator> *v5; // r14
  hkArrayBase<int> *v7; // r12
  _QWORD *Value; // rax
  unsigned __int64 v9; // r8
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  int v12; // r8d
  int m_size; // r8d
  _QWORD *v14; // r8
  _QWORD *v15; // rcx
  unsigned __int64 v16; // rax
  _QWORD *v17; // rcx
  int v18; // edi
  __int64 v19; // r14
  char *m_data; // r15
  unsigned int m_allocatedSize; // ebx
  _QWORD **v22; // rax
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  _QWORD *v26; // rcx
  int v27; // edx
  int v28; // esi
  __int64 v29; // rdi
  int m_numElems; // r9d
  int v31; // edx
  unsigned int v32; // ebx
  int v33; // r10d
  int v34; // r11d
  int v35; // ecx
  unsigned int v36; // edx
  _QWORD *v37; // r8
  _QWORD *v38; // rcx
  unsigned __int64 v39; // rax
  _QWORD *v40; // rcx
  signed int mHeight; // r9d
  __int64 v42; // r10
  int v43; // edx
  __int64 v44; // rcx
  _QWORD *v45; // rax
  int v46; // ebx
  hkArrayBase<unsigned int> *v47; // r12
  unsigned int v48; // r15d
  int v49; // edx
  __int64 v50; // rcx
  _QWORD *v51; // rax
  hkaiNavMeshInstance *m_instancePtr; // rbx
  hkaiNavMesh::Edge *v53; // rax
  unsigned int m_oppositeEdge; // edx
  char v55; // r8
  unsigned int v56; // ecx
  unsigned int v57; // edi
  unsigned int m_oppositeFace; // ecx
  unsigned int v59; // eax
  unsigned int v60; // esi
  int Key; // eax
  __int64 v62; // r14
  __int64 v63; // rbx
  hkArrayBase<unsigned int> *v64; // r8
  int v65; // r8d
  _QWORD **v66; // rax
  char m_enum; // bl
  __int64 v68; // rbx
  hkaiNavMeshInstance *v69; // rax
  char m_storage; // cl
  char *v71; // rax
  int v72; // r8d
  int v73; // ecx
  unsigned int v74; // edx
  int v75; // eax
  int v76; // r10d
  __int64 v77; // r11
  unsigned int m_edgeKey; // r8d
  __int64 v79; // rdx
  int v80; // r8d
  hkaiNavMeshInstance *v81; // r9
  int m_numOriginalEdges; // eax
  __int64 v83; // rcx
  hkaiNavMesh::Edge *v84; // rax
  hkaiNavMesh::Edge *v85; // rdx
  int m_capacityAndFlags; // r8d
  _QWORD **v87; // rax
  int v88; // edx
  __int64 v89; // rcx
  _QWORD *v90; // rax
  __int64 v91; // rcx
  _QWORD *v92; // rax
  int v93; // r14d
  __int64 v94; // r15
  hkaiStreamingCollection::InstanceInfo *v95; // rsi
  unsigned int v96; // eax
  hkaiNavMeshInstance *v97; // rbx
  hkaiNavMesh::Edge *v98; // rax
  hkaiNavMesh::Edge *v99; // r8
  unsigned int v100; // edx
  char v101; // r9
  unsigned int v102; // ecx
  unsigned int v103; // edi
  hkaiNavMeshInstance *v104; // r10
  hkResult *p_result; // rax
  char v106; // al
  hkaiNavMesh::Edge *v107; // rbx
  _QWORD *v108; // r8
  _QWORD *v109; // rcx
  unsigned __int64 v110; // rax
  _QWORD *v111; // rcx
  _QWORD *v112; // r8
  _QWORD *v113; // rcx
  unsigned __int64 v114; // rax
  _QWORD *v115; // rcx
  unsigned int v116; // ecx
  unsigned int v117; // eax
  int v118; // r8d
  int v119; // r10d
  __int64 v120; // r11
  unsigned int v121; // eax
  __int64 v122; // r8
  int v123; // eax
  hkaiNavMeshInstance *v124; // r9
  int v125; // ecx
  __int64 v126; // rcx
  hkaiNavMesh::Edge *v127; // rax
  hkaiNavMesh::Edge *v128; // rcx
  char v129; // [rsp+30h] [rbp-89h] BYREF
  hkArray<hkaiNavMeshCutter::FaceEdgePair,hkContainerTempAllocator> v130; // [rsp+38h] [rbp-81h] BYREF
  AMD_HD3D v131; // [rsp+48h] [rbp-71h] BYREF
  hkArray<unsigned int,hkContainerTempAllocator> unmappedEdges; // [rsp+68h] [rbp-51h] BYREF
  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > cutFacesa; // [rsp+78h] [rbp-41h] BYREF
  hkArray<hkaiNavMeshCutter::FaceEdgePair,hkContainerTempAllocator> v134; // [rsp+90h] [rbp-29h] BYREF
  __int64 v135; // [rsp+A0h] [rbp-19h]
  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > exactEdges; // [rsp+A8h] [rbp-11h] BYREF
  hkArrayBase<unsigned int> *v137; // [rsp+C0h] [rbp+7h]
  hkResult result; // [rsp+120h] [rbp+67h] BYREF
  hkArrayBase<int> *v139; // [rsp+128h] [rbp+6Fh]
  char v140; // [rsp+130h] [rbp+77h] BYREF
  hkArray<unsigned int,hkContainerTempAllocator> *v141; // [rsp+138h] [rbp+7Fh] BYREF

  v141 = cutFaces;
  v139 = cutSections;
  v5 = cutFaces;
  v7 = cutSections;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = Value[1];
  v10 = Value;
  if ( v9 < Value[3] )
  {
    *(_QWORD *)v9 = "LtapplyCuts";
    *(_QWORD *)(v9 + 16) = "StGatherEdges";
    v11 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v11;
    v10[1] = v9 + 24;
  }
  v12 = 2 * results->m_size;
  *(_QWORD *)&v131.mEnableStereo = 0i64;
  v131.mWidth = 0;
  v131.mHeight = -1;
  exactEdges.m_elem.m_data = 0i64;
  exactEdges.m_elem.m_size = 0;
  exactEdges.m_elem.m_capacityAndFlags = 0x80000000;
  exactEdges.m_numElems = 0;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v131,
    &hkContainerTempAllocator::s_alloc,
    v12);
  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int>>::reserve(&exactEdges, results->m_size);
  m_size = results->m_size;
  unmappedEdges.m_data = 0i64;
  unmappedEdges.m_size = 0;
  unmappedEdges.m_capacityAndFlags = 0x80000000;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkaiFaceCutResults,unsigned int (*)(hkaiFaceCutResults const &,hkaiFaceCutResults const &)>(
      results->m_data,
      0,
      m_size - 1,
      CutResultCompare);
  gatherEdgeMap(
    this->m_streamingCollection.m_pntr,
    results,
    (hkPointerMap<unsigned int,hkArray<unsigned int,hkContainerHeapAllocator> *,hkContainerTempAllocator> *)&v131,
    &unmappedEdges);
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)v14[1];
  if ( (unsigned __int64)v15 < v14[3] )
  {
    *v15 = "StAddFaces";
    v16 = __rdtsc();
    v17 = v15 + 2;
    *((_DWORD *)v17 - 2) = v16;
    v14[1] = v17;
  }
  v18 = 0;
  if ( results->m_size > 0 )
  {
    v19 = 0i64;
    do
    {
      addFacesForCut(
        this->m_streamingCollection.m_pntr->m_instances.m_data[results->m_data[v19].m_originalFace >> 22].m_instancePtr,
        &results->m_data[v18],
        &this->m_meshInfos.m_data[results->m_data[v19].m_originalFace >> 22].m_magic,
        &exactEdges);
      m_data = results->m_data[v19].m_data;
      if ( m_data )
      {
        m_allocatedSize = results->m_data[v19].m_allocatedSize;
        v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v22[11] + 16i64))(v22[11], m_data, m_allocatedSize);
      }
      ++v18;
      ++v19;
    }
    while ( v18 < results->m_size );
    v5 = v141;
  }
  v23 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v24 = (_QWORD *)v23[1];
  if ( (unsigned __int64)v24 < v23[3] )
  {
    *v24 = "StMatchStreaming";
    v25 = __rdtsc();
    v26 = v24 + 2;
    *((_DWORD *)v26 - 2) = v25;
    v23[1] = v26;
  }
  v27 = v5->m_size;
  cutFacesa.m_elem.m_data = 0i64;
  cutFacesa.m_elem.m_size = 0;
  cutFacesa.m_elem.m_capacityAndFlags = 0x80000000;
  cutFacesa.m_numElems = 0;
  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int>>::reserve(&cutFacesa, v27);
  v28 = 0;
  if ( v5->m_size > 0 )
  {
    v29 = 0i64;
    do
    {
      m_numElems = cutFacesa.m_numElems;
      v31 = cutFacesa.m_elem.m_size;
      v32 = v5->m_data[v29];
      if ( 2 * cutFacesa.m_numElems > cutFacesa.m_elem.m_size - 1 )
      {
        hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int>>::resizeTable(
          &cutFacesa,
          &result,
          2 * cutFacesa.m_elem.m_size);
        m_numElems = cutFacesa.m_numElems;
        v31 = cutFacesa.m_elem.m_size;
      }
      v33 = v31 - 1;
      v34 = 1;
      v35 = (v31 - 1) & (-1640531535 * (v32 >> 4));
      v36 = cutFacesa.m_elem.m_data[v35];
      if ( v36 != -1 )
      {
        while ( v36 != v32 )
        {
          v35 = v33 & (v35 + 1);
          v36 = cutFacesa.m_elem.m_data[v35];
          if ( v36 == -1 )
            goto LABEL_24;
        }
        v34 = 0;
      }
LABEL_24:
      ++v28;
      cutFacesa.m_numElems = v34 + m_numElems;
      cutFacesa.m_elem.m_data[v35] = v32;
      ++v29;
    }
    while ( v28 < v5->m_size );
  }
  hkaiNavMeshCutter::matchStreamingFaces(this, v7, &cutFacesa);
  v37 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v38 = (_QWORD *)v37[1];
  if ( (unsigned __int64)v38 < v37[3] )
  {
    *v38 = "StFixUpEdges";
    v39 = __rdtsc();
    v40 = v38 + 2;
    *((_DWORD *)v40 - 2) = v39;
    v37[1] = v40;
  }
  mHeight = v131.mHeight;
  v42 = *(_QWORD *)&v131.mEnableStereo;
  v43 = 0;
  v44 = 0i64;
  if ( (v131.mHeight & 0x80000000) == 0 )
  {
    v45 = *(_QWORD **)&v131.mEnableStereo;
    do
    {
      if ( *v45 != -1i64 )
        break;
      ++v44;
      ++v43;
      v45 += 2;
    }
    while ( v44 <= (int)v131.mHeight );
  }
  v46 = v43;
  v135 = v43;
  if ( v43 <= (int)v131.mHeight )
  {
LABEL_32:
    LOBYTE(result.m_enum) = 0;
    v47 = *(hkArrayBase<unsigned int> **)(v42 + 16i64 * v46 + 8);
    v48 = *(_DWORD *)(v42 + 16i64 * v46);
    v137 = v47;
    if ( !v47 )
    {
      v49 = v46 + 1;
      v50 = v46 + 1;
      if ( v50 <= mHeight )
      {
        v51 = (_QWORD *)(v42 + 16i64 * v49);
        do
        {
          if ( *v51 != -1i64 )
            break;
          ++v50;
          ++v49;
          v51 += 2;
        }
        while ( v50 <= mHeight );
      }
      v46 = v49;
      v135 = v49;
      goto LABEL_104;
    }
    *(_QWORD *)(v42 + 16i64 * v46 + 8) = 0i64;
    v131.mStereo = 0i64;
    v131.mExtension = (IAmdDxExt *)0x8000000000000000i64;
    hkaiNavMeshCutter::gatherCutEdgesFromCutFaces(
      this,
      v48,
      v47,
      (hkArray<hkaiNavMeshCutter::FaceEdgePair,hkContainerTempAllocator> *)&v131.mStereo);
    m_instancePtr = this->m_streamingCollection.m_pntr->m_instances.m_data[v48 >> 22].m_instancePtr;
    v53 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__17(
            m_instancePtr->m_originalEdges,
            m_instancePtr->m_numOriginalEdges,
            &m_instancePtr->m_instancedEdges,
            &m_instancePtr->m_ownedEdges,
            &m_instancePtr->m_edgeMap,
            v48 & 0x3FFFFF);
    m_oppositeEdge = v53->m_oppositeEdge;
    v55 = v53->m_flags.m_storage & 0x40;
    if ( v55 )
      v56 = m_oppositeEdge & 0xFFC00000;
    else
      v56 = m_instancePtr->m_runtimeId << 22;
    v57 = v56 | m_oppositeEdge & 0x3FFFFF;
    m_oppositeFace = v53->m_oppositeFace;
    if ( m_oppositeEdge == -1 )
      v57 = -1;
    if ( v55 )
      v59 = m_oppositeFace & 0xFFC00000;
    else
      v59 = m_instancePtr->m_runtimeId << 22;
    v60 = v59 | m_oppositeFace & 0x3FFFFF;
    if ( m_oppositeFace == -1 )
      v60 = -1;
    Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v131,
                          v57);
    if ( Key <= (int)v131.mHeight )
    {
      v62 = 2i64 * Key;
      v63 = *(_QWORD *)(*(_QWORD *)&v131.mEnableStereo + 16i64 * Key + 8);
      if ( v63 )
      {
        v64 = *(hkArrayBase<unsigned int> **)(*(_QWORD *)&v131.mEnableStereo + 16i64 * Key + 8);
        v134.m_capacityAndFlags = 0x80000000;
        v134.m_data = 0i64;
        v134.m_size = 0;
        hkaiNavMeshCutter::gatherCutEdgesFromCutFaces(this, v57, v64, &v134);
        hkaiNavMeshCutter::matchNewEdgesFromOriginalEdge(
          this,
          this->m_streamingCollection.m_pntr,
          (hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *)&v131.mStereo,
          &v134);
        v65 = *(_DWORD *)(v63 + 12);
        *(_DWORD *)(v63 + 8) = 0;
        if ( v65 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)v63, 4 * v65);
        *(_QWORD *)v63 = 0i64;
        *(_DWORD *)(v63 + 12) = 0x80000000;
        v66 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, __int64, __int64))(*v66[11] + 16i64))(v66[11], v63, 16i64);
        *(_QWORD *)(*(_QWORD *)&v131.mEnableStereo + 8 * v62 + 8) = 0i64;
        v134.m_size = 0;
        if ( v134.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            v134.m_data,
            8 * v134.m_capacityAndFlags);
        v134.m_data = 0i64;
        v134.m_capacityAndFlags = 0x80000000;
        m_enum = 0;
        goto LABEL_89;
      }
      v5 = v141;
    }
    v68 = v60 >> 22;
    v69 = this->m_streamingCollection.m_pntr->m_instances.m_data[v68].m_instancePtr;
    if ( v69->m_faceFlags.m_size )
    {
      m_storage = v69->m_faceFlags.m_data[v60 & 0x3FFFFF].m_storage;
      v71 = &v140;
      v140 = m_storage;
    }
    else
    {
      v129 = 0;
      v71 = &v129;
    }
    if ( (*v71 & 1) != 0 )
    {
      m_enum = result.m_enum;
    }
    else
    {
      if ( LODWORD(v131.mExtension) == 1 )
      {
        v72 = exactEdges.m_elem.m_size - 1;
        if ( exactEdges.m_elem.m_size - 1 <= 0
          || (v73 = v72 & (-1640531535 * (v48 >> 4)), v74 = exactEdges.m_elem.m_data[v73], v74 == -1) )
        {
LABEL_65:
          v75 = exactEdges.m_elem.m_size;
        }
        else
        {
          while ( v74 != v48 )
          {
            v73 = v72 & (v73 + 1);
            v74 = exactEdges.m_elem.m_data[v73];
            if ( v74 == -1 )
              goto LABEL_65;
          }
          v75 = v73;
        }
        if ( v75 <= v72 || hkaiNavMeshCutter::doEdgesMatch(this, v57, (unsigned int)v131.mStereo->vfptr) )
        {
          hkaiNavMeshCutterHelper::connectCutFaceToUncutFace(
            this->m_streamingCollection.m_pntr,
            &this->m_connectivityInfo,
            v57,
            v48,
            (hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *)&v131.mStereo);
          m_enum = result.m_enum;
          goto LABEL_89;
        }
      }
      hkaiNavMeshCutterHelper::replaceFaceWithCutFace(
        this->m_streamingCollection.m_pntr,
        v60,
        v57,
        &this->m_connectivityInfo,
        &this->m_meshInfos.m_data[v68].m_magic,
        (hkPointerMap<unsigned int,hkArray<unsigned int,hkContainerHeapAllocator> *,hkContainerTempAllocator> *)&v131);
      if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, v5, 4);
      m_enum = 1;
      v5->m_data[v5->m_size++] = v60;
    }
    hkaiNavMeshCutter::mergeCutBoundaryEdges(this, v60, v57);
    v130.m_data = 0i64;
    v130.m_size = 0;
    v130.m_capacityAndFlags = 0x80000000;
    hkaiNavMeshCutter::gatherCutEdges(this, v57, v60, &v130, GATHER_ALL_EDGES);
    v76 = 0;
    if ( v130.m_size <= 0 )
      goto LABEL_86;
    v77 = 0i64;
    while ( 1 )
    {
      m_edgeKey = v130.m_data[v77].m_edgeKey;
      v79 = m_edgeKey >> 22;
      v80 = m_edgeKey & 0x3FFFFF;
      v81 = this->m_streamingCollection.m_pntr->m_instances.m_data[v79].m_instancePtr;
      m_numOriginalEdges = v81->m_numOriginalEdges;
      if ( v80 >= m_numOriginalEdges )
        break;
      if ( v81->m_edgeMap.m_size )
        v80 = v81->m_edgeMap.m_data[v80];
      if ( v80 != -1 )
      {
        v83 = v80;
        v84 = v81->m_instancedEdges.m_data;
        goto LABEL_83;
      }
      v85 = 0i64;
LABEL_84:
      ++v76;
      v85->m_oppositeFace = -1;
      v85->m_oppositeEdge = -1;
      ++v77;
      if ( v76 >= v130.m_size )
      {
        v47 = v137;
LABEL_86:
        hkaiNavMeshCutter::matchNewEdgesFromOriginalEdge(
          this,
          this->m_streamingCollection.m_pntr,
          (hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *)&v131.mStereo,
          &v130);
        v130.m_size = 0;
        if ( v130.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            v130.m_data,
            8 * v130.m_capacityAndFlags);
        v130.m_data = 0i64;
        v130.m_capacityAndFlags = 0x80000000;
LABEL_89:
        m_capacityAndFlags = v47->m_capacityAndFlags;
        v47->m_size = 0;
        if ( m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v47->m_data,
            4 * m_capacityAndFlags);
        v47->m_data = 0i64;
        v47->m_capacityAndFlags = 0x80000000;
        v87 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkArrayBase<unsigned int> *, __int64))(*v87[11] + 16i64))(v87[11], v47, 16i64);
        mHeight = v131.mHeight;
        v42 = *(_QWORD *)&v131.mEnableStereo;
        if ( m_enum )
        {
          v88 = 0;
          v89 = 0i64;
          if ( (v131.mHeight & 0x80000000) == 0 )
          {
            v90 = *(_QWORD **)&v131.mEnableStereo;
            do
            {
              if ( *v90 != -1i64 )
                break;
              ++v89;
              ++v88;
              v90 += 2;
            }
            while ( v89 <= (int)v131.mHeight );
          }
        }
        else
        {
          v88 = v135 + 1;
          v91 = (int)v135 + 1;
          if ( v91 <= (int)v131.mHeight )
          {
            v92 = (_QWORD *)(*(_QWORD *)&v131.mEnableStereo + 16i64 * v88);
            do
            {
              if ( *v92 != -1i64 )
                break;
              ++v91;
              ++v88;
              v92 += 2;
            }
            while ( v91 <= (int)v131.mHeight );
          }
        }
        v46 = v88;
        LODWORD(v131.mExtension) = 0;
        v135 = v88;
        if ( SHIDWORD(v131.mExtension) >= 0 )
        {
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            v131.mStereo,
            8 * HIDWORD(v131.mExtension));
          mHeight = v131.mHeight;
          v42 = *(_QWORD *)&v131.mEnableStereo;
        }
        v5 = v141;
        v131.mStereo = 0i64;
        HIDWORD(v131.mExtension) = 0x80000000;
LABEL_104:
        if ( v46 > mHeight )
        {
          v7 = v139;
          goto LABEL_106;
        }
        goto LABEL_32;
      }
    }
    v83 = v80 - m_numOriginalEdges;
    v84 = v81->m_ownedEdges.m_data;
LABEL_83:
    v85 = &v84[v83];
    goto LABEL_84;
  }
LABEL_106:
  v93 = 0;
  if ( unmappedEdges.m_size > 0 )
  {
    v94 = 0i64;
    while ( 1 )
    {
      v95 = this->m_streamingCollection.m_pntr->m_instances.m_data;
      v96 = unmappedEdges.m_data[v94];
      v97 = v95[v96 >> 22].m_instancePtr;
      v98 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__17(
              v97->m_originalEdges,
              v97->m_numOriginalEdges,
              &v97->m_instancedEdges,
              &v97->m_ownedEdges,
              &v97->m_edgeMap,
              v96 & 0x3FFFFF);
      v99 = v98;
      v100 = v98->m_oppositeEdge;
      if ( v100 != -1 )
      {
        v101 = v98->m_flags.m_storage & 0x40;
        if ( v101 )
          v102 = v100 & 0xFFC00000;
        else
          v102 = v97->m_runtimeId << 22;
        v103 = v102 | v100 & 0x3FFFFF;
        v104 = v95[v103 >> 22].m_instancePtr;
        if ( v104->m_faceFlags.m_size )
        {
          p_result = (hkResult *)&v141;
          LOBYTE(v141) = v104->m_faceFlags.m_data[v99->m_oppositeFace & 0x3FFFFF].m_storage;
        }
        else
        {
          LOBYTE(result.m_enum) = 0;
          p_result = &result;
        }
        v106 = p_result->m_enum & 0xFB;
        if ( v106 )
        {
          if ( v106 == 1 )
          {
            v116 = v99->m_oppositeFace;
            if ( v101 )
              v117 = v116 & 0xFFC00000;
            else
              v117 = v97->m_runtimeId << 22;
            v118 = v117 | v116 & 0x3FFFFF;
            if ( v116 == -1 )
              v118 = -1;
            v130.m_data = 0i64;
            v130.m_size = 0;
            v130.m_capacityAndFlags = 0x80000000;
            hkaiNavMeshCutter::gatherCutEdges(this, v103, v118, &v130, GATHER_ALL_EDGES);
            v119 = 0;
            if ( v130.m_size <= 0 )
            {
LABEL_147:
              v130.m_size = 0;
              if ( v130.m_capacityAndFlags >= 0 )
                hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                  &hkContainerTempAllocator::s_alloc,
                  v130.m_data,
                  8 * v130.m_capacityAndFlags);
              v130.m_data = 0i64;
              v130.m_capacityAndFlags = 0x80000000;
              goto LABEL_117;
            }
            v120 = 0i64;
            while ( 2 )
            {
              v121 = v130.m_data[v120].m_edgeKey;
              v122 = v121 >> 22;
              v123 = v121 & 0x3FFFFF;
              v124 = this->m_streamingCollection.m_pntr->m_instances.m_data[v122].m_instancePtr;
              v125 = v124->m_numOriginalEdges;
              if ( v123 >= v125 )
              {
                v126 = v123 - v125;
                v127 = v124->m_ownedEdges.m_data;
                goto LABEL_145;
              }
              if ( v124->m_edgeMap.m_size )
                v123 = v124->m_edgeMap.m_data[v123];
              if ( v123 == -1 )
              {
                v128 = 0i64;
              }
              else
              {
                v126 = v123;
                v127 = v124->m_instancedEdges.m_data;
LABEL_145:
                v128 = &v127[v126];
              }
              ++v119;
              v128->m_oppositeFace = -1;
              v128->m_oppositeEdge = -1;
              ++v120;
              if ( v119 >= v130.m_size )
                goto LABEL_147;
              continue;
            }
          }
        }
        else
        {
          v107 = hkaiNavMeshInstance::instanceEdge(v104, v100 & 0x3FFFFF);
          hkaiNavMeshCutter::SavedConnectivity::addConnectivity(&this->m_connectivityInfo, v103);
          v107->m_oppositeFace = -1;
          v107->m_oppositeEdge = -1;
        }
      }
LABEL_117:
      ++v93;
      ++v94;
      if ( v93 >= unmappedEdges.m_size )
      {
        v7 = v139;
        break;
      }
    }
  }
  v108 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v109 = (_QWORD *)v108[1];
  if ( (unsigned __int64)v109 < v108[3] )
  {
    *v109 = "StcompactEdges";
    v110 = __rdtsc();
    v111 = v109 + 2;
    *((_DWORD *)v111 - 2) = v110;
    v108[1] = v111;
  }
  hkaiNavMeshCutter::removeUnusedCutEdges(this, v7);
  cutFacesa.m_elem.m_size = 0;
  if ( cutFacesa.m_elem.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      cutFacesa.m_elem.m_data,
      4 * cutFacesa.m_elem.m_capacityAndFlags);
  cutFacesa.m_elem.m_data = 0i64;
  cutFacesa.m_elem.m_capacityAndFlags = 0x80000000;
  unmappedEdges.m_size = 0;
  if ( unmappedEdges.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      unmappedEdges.m_data,
      4 * unmappedEdges.m_capacityAndFlags);
  unmappedEdges.m_data = 0i64;
  unmappedEdges.m_capacityAndFlags = 0x80000000;
  exactEdges.m_elem.m_size = 0;
  if ( exactEdges.m_elem.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      exactEdges.m_elem.m_data,
      4 * exactEdges.m_elem.m_capacityAndFlags);
  exactEdges.m_elem.m_data = 0i64;
  exactEdges.m_elem.m_capacityAndFlags = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v131,
    &hkContainerTempAllocator::s_alloc);
  _(&v131);
  v112 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v113 = (_QWORD *)v112[1];
  if ( (unsigned __int64)v113 < v112[3] )
  {
    *v113 = "lt";
    v114 = __rdtsc();
    v115 = v113 + 2;
    *((_DWORD *)v115 - 2) = v114;
    v112[1] = v115;
  }
}rTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      exactEdges.m_elem.m_data,
      4 * exactEdges.m_elem.m_capacityAndFlags);
  exactEdges.m_elem.m_data = 0i64;
  exactEdges.m_elem.m_capacityAndFlags = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned _


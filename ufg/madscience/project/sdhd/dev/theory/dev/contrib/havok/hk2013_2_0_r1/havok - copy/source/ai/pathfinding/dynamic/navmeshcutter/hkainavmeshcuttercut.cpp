// File Line: 116
// RVA: 0xC19D80
void __fastcall gatherEdgeMap(hkaiStreamingCollection *collection, hkArrayBase<hkaiFaceCutResults> *results, hkPointerMap<unsigned int,hkArray<unsigned int,hkContainerHeapAllocator> *,hkContainerTempAllocator> *edgeMap, hkArray<unsigned int,hkContainerTempAllocator> *unmappedEdges)
{
  int v4; // ebp
  hkArray<unsigned int,hkContainerTempAllocator> *v5; // r15
  hkaiStreamingCollection *v6; // r8
  signed int v7; // edi
  __int64 v8; // rcx
  hkaiStreamingCollection::InstanceInfo *v9; // rax
  char *v10; // rsi
  int v11; // edx
  hkaiNavMeshInstance *v12; // r13
  int v13; // ebp
  hkaiNavMesh::Face *v14; // rcx
  int index; // ST28_4
  int v16; // edx
  hkaiNavMesh::Face *v17; // rax
  unsigned int v18; // er11
  char v19; // r12
  int v20; // ecx
  int v21; // ebx
  int v22; // er12
  __int64 v23; // r8
  int v24; // er9
  char *v25; // rdi
  int v26; // eax
  unsigned __int64 v27; // rcx
  int *v28; // r14
  unsigned int v29; // eax
  __int64 v30; // rdx
  int v31; // esi
  int v32; // er15
  int v33; // ebp
  int v34; // edi
  char *v35; // rax
  unsigned int v36; // ebx
  int v37; // ST28_4
  unsigned int v38; // edi
  int v39; // ebx
  unsigned __int64 v40; // rsi
  _DWORD *v41; // rdi
  _QWORD **v42; // rax
  __int64 v43; // rax
  __int64 v44; // r9
  int v45; // edx
  __int64 v46; // rcx
  _DWORD *v47; // rax
  __int64 v48; // r14
  signed int v49; // ebx
  __int64 v50; // rsi
  unsigned int v51; // er12
  int v52; // ebp
  bool v53; // sf
  unsigned __int8 v54; // of
  char v55; // [rsp+30h] [rbp-98h]
  char v56; // [rsp+31h] [rbp-97h]
  unsigned int v57; // [rsp+34h] [rbp-94h]
  int v58; // [rsp+38h] [rbp-90h]
  int v59; // [rsp+3Ch] [rbp-8Ch]
  _BYTE *array; // [rsp+40h] [rbp-88h]
  int v61; // [rsp+48h] [rbp-80h]
  int v62; // [rsp+4Ch] [rbp-7Ch]
  int v63; // [rsp+50h] [rbp-78h]
  int v64; // [rsp+54h] [rbp-74h]
  hkaiNavMesh::Face *v65; // [rsp+58h] [rbp-70h]
  unsigned int v66; // [rsp+60h] [rbp-68h]
  hkResult result; // [rsp+64h] [rbp-64h]
  __int64 v68; // [rsp+68h] [rbp-60h]
  __int64 v69; // [rsp+70h] [rbp-58h]
  hkaiStreamingCollection *v70; // [rsp+D0h] [rbp+8h]
  hkArrayBase<hkaiFaceCutResults> *v71; // [rsp+D8h] [rbp+10h]
  hkPointerMap<unsigned int,hkArray<unsigned int,hkContainerHeapAllocator> *,hkContainerTempAllocator> *v72; // [rsp+E0h] [rbp+18h]
  hkArray<unsigned int,hkContainerTempAllocator> *v73; // [rsp+E8h] [rbp+20h]

  v73 = unmappedEdges;
  v72 = edgeMap;
  v71 = results;
  v70 = collection;
  v4 = -1;
  v5 = unmappedEdges;
  v6 = collection;
  v63 = -1;
  v59 = -1;
  v7 = -1;
  v64 = 0;
  if ( results->m_size > 0 )
  {
    v8 = 0i64;
    v69 = 0i64;
    while ( 1 )
    {
      v9 = v6->m_instances.m_data;
      v10 = (char *)results->m_data + v8;
      v11 = *(_DWORD *)v10;
      v57 = *(_DWORD *)v10 >> 22;
      v12 = v9[v57].m_instancePtr;
      if ( v57 != v7 )
      {
        v13 = v12->m_ownedFaces.m_size;
        v59 = 0;
        v4 = v12->m_numOriginalFaces + v13;
        v63 = v4;
      }
      v14 = v12->m_originalFaces;
      index = v11 & 0x3FFFFF;
      v16 = v12->m_numOriginalFaces;
      v66 = v57;
      v17 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__15(
              v14,
              v16,
              &v12->m_instancedFaces,
              &v12->m_ownedFaces,
              &v12->m_faceMap,
              index);
      v19 = v10[16];
      v20 = 0;
      array = 0i64;
      v62 = 2147483648;
      v61 = 0;
      v21 = v17->m_numEdges;
      v22 = v19 & 1;
      v23 = (__int64)v17;
      v65 = v17;
      if ( v21 <= 0 )
      {
        result.m_enum = 0;
      }
      else
      {
        v24 = v21;
        if ( v21 < 0 )
          v24 = 0;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v24, 1);
        v20 = v61;
        v23 = (__int64)v65;
        v18 = v57;
      }
      v25 = &array[v20];
      v26 = v21 - v20;
      v27 = v21 - v20;
      if ( v26 > 0 )
        memset(v25, 0, v27);
      v61 = v21;
      v28 = 0i64;
      if ( v22 )
        break;
      v29 = *((signed __int16 *)v10 + 2);
      v28 = (int *)*((_QWORD *)v10 + 3);
      if ( (signed int)v29 > 0 )
        goto LABEL_14;
LABEL_47:
      v48 = (__int64)v65;
      v49 = 0;
      v50 = 0i64;
      if ( v65->m_numEdges > 0 )
      {
        v51 = v57;
        do
        {
          v52 = v49 + *(_DWORD *)v48;
          if ( !array[v50]
            && hkaiNavMeshInstance_get_hkaiNavMesh::Edge__17(
                 v12->m_originalEdges,
                 v12->m_numOriginalEdges,
                 &v12->m_instancedEdges,
                 &v12->m_ownedEdges,
                 &v12->m_edgeMap,
                 v49 + *(_DWORD *)v48)->m_oppositeEdge != -1 )
          {
            if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v5, 4);
            v5->m_data[v5->m_size++] = v52 | (v51 << 22);
          }
          ++v49;
          ++v50;
        }
        while ( v49 < *(signed __int16 *)(v48 + 8) );
      }
      v61 = 0;
      if ( v62 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          v62 & 0x3FFFFFFF);
      results = v71;
      v4 = v63;
      v6 = v70;
      v8 = v69 + 32;
      v54 = __OFSUB__(v64 + 1, v71->m_size);
      v53 = v64++ + 1 - v71->m_size < 0;
      v7 = v66;
      array = 0i64;
      v62 = 2147483648;
      v69 += 32i64;
      if ( !(v53 ^ v54) )
        return;
    }
    v29 = 1;
LABEL_14:
    v30 = v29;
    v31 = v59 + v4;
    v68 = v29;
    v58 = v59 + v4;
    v59 += v29;
    do
    {
      if ( v22 )
        v32 = *(signed __int16 *)(v23 + 8);
      else
        v32 = *v28;
      v33 = 0;
      if ( v32 > 0 )
      {
        do
        {
          if ( v22 )
          {
            v34 = v33;
            v55 = 0;
            v35 = &v55;
          }
          else
          {
            v34 = v28[*v28 + v33 + 2];
            v56 = *((_BYTE *)&v28[2 * *v28 + 2] + v33) & 3;
            v35 = &v56;
          }
          if ( !*v35 )
          {
            array[v34] = 1;
            v36 = v18 << 22;
            v37 = v34 + *(_DWORD *)v23;
            v38 = v37 | (v18 << 22);
            if ( hkaiNavMeshInstance_get_hkaiNavMesh::Edge__17(
                   v12->m_originalEdges,
                   v12->m_numOriginalEdges,
                   &v12->m_instancedEdges,
                   &v12->m_ownedEdges,
                   &v12->m_edgeMap,
                   v37)->m_oppositeEdge != -1 )
            {
              v39 = v31 | v36;
              v40 = v38;
              v41 = (_DWORD *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v72->m_map.m_elem,
                                v38,
                                0i64);
              if ( !v41 )
              {
                v42 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
                v43 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v42[11] + 8i64))(v42[11], 16i64);
                v41 = (_DWORD *)v43;
                if ( v43 )
                {
                  *(_QWORD *)v43 = 0i64;
                  *(_DWORD *)(v43 + 8) = 0;
                  *(_DWORD *)(v43 + 12) = 2147483648;
                }
                else
                {
                  v41 = 0i64;
                }
                hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                  (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v72->m_map.m_elem,
                  (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
                  v40,
                  (unsigned __int64)v41);
              }
              v44 = (signed int)v41[2];
              v45 = 0;
              v46 = 0i64;
              if ( (signed int)v44 <= 0 )
                goto LABEL_36;
              v47 = *(_DWORD **)v41;
              while ( *v47 != v39 )
              {
                ++v46;
                ++v45;
                ++v47;
                if ( v46 >= v44 )
                  goto LABEL_36;
              }
              if ( v45 == -1 )
              {
LABEL_36:
                if ( (_DWORD)v44 == (v41[3] & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v41, 4);
                *(_DWORD *)(*(_QWORD *)v41 + 4i64 * (signed int)v41[2]++) = v39;
              }
              v31 = v58;
            }
          }
          v23 = (__int64)v65;
          v18 = v57;
          ++v33;
        }
        while ( v33 < v32 );
        v30 = v68;
      }
      if ( v22 )
        v28 = 0i64;
      else
        v28 = (int *)((char *)v28 + (signed int)(((*v28 + 3) & 0xFFFFFFFC) + 8 * *v28 + 8));
      v23 = (__int64)v65;
      v18 = v57;
      ++v31;
      --v30;
      v58 = v31;
      v68 = v30;
    }
    while ( v30 );
    v5 = v73;
    goto LABEL_47;
  }
}

// File Line: 216
// RVA: 0xC1A270
void __fastcall addFacesForCut(hkaiNavMeshInstance *meshInstance, hkaiFaceCutResults *res, hkArray<int,hkContainerHeapAllocator> *magic, hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > *exactEdges)
{
  unsigned int v4; // edi
  char v5; // r13
  hkaiFaceCutResults *v6; // r15
  int v7; // edx
  int v8; // eax
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v9; // r9
  int index; // edi
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rax
  hkArray<int,hkContainerHeapAllocator> *v12; // r14
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v13; // r8
  hkaiNavMesh::Face *v14; // rcx
  int v15; // er13
  hkArrayBase<hkVector4f> *v16; // r9
  hkaiNavMeshInstance *v17; // r11
  int *v18; // r12
  int v19; // edi
  signed int v20; // esi
  int v21; // er9
  __int64 v22; // rdx
  signed int i; // edi
  __int64 v24; // rcx
  char v25; // bl
  __int64 v26; // rdi
  int v27; // eax
  int v28; // eax
  int *v29; // rax
  __int64 v30; // rcx
  int *v31; // rdi
  int v32; // eax
  hkaiNavMeshInstance *v33; // r14
  int v34; // edi
  int v35; // edi
  hkLifoAllocator *v36; // rax
  hkLifoAllocator *v37; // rcx
  char *v38; // rax
  int v39; // edx
  char *v40; // r8
  hkaiNavMeshInstance *v41; // rdi
  hkVector4f *v42; // rdx
  int v43; // er8
  int v44; // er15
  int v45; // er13
  signed int v46; // esi
  int v47; // edi
  __int16 v48; // ax
  int v49; // eax
  int v50; // edx
  hkaiNavMeshInstance::AddEdgeContext *v51; // r9
  signed int v52; // edi
  __int64 v53; // rdx
  signed __int64 v54; // rcx
  int v55; // esi
  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > *v56; // rbx
  int *v57; // rax
  signed __int64 v58; // r14
  int v59; // edi
  int v60; // edx
  int v61; // er13
  int v62; // ecx
  int v63; // edx
  hkaiNavMeshInstance **v64; // rax
  char v65; // di
  int v66; // edi
  __int64 v67; // rdx
  int v68; // ecx
  int v69; // eax
  int v70; // er15
  int v71; // edx
  char v72; // cl
  __int64 v73; // rax
  int v74; // esi
  int v75; // edx
  char *v76; // rax
  int v77; // er8
  unsigned int v78; // edi
  unsigned int *v79; // r9
  int v80; // er8
  int v81; // eax
  unsigned int v82; // edx
  bool v83; // zf
  int v84; // eax
  char *v85; // rbx
  signed int v86; // edi
  hkLifoAllocator *v87; // rax
  int v88; // er8
  char v89; // [rsp+30h] [rbp-C8h]
  char v90; // [rsp+31h] [rbp-C7h]
  char v91; // [rsp+32h] [rbp-C6h]
  char v92; // [rsp+33h] [rbp-C5h]
  int fIdx; // [rsp+34h] [rbp-C4h]
  int v94; // [rsp+38h] [rbp-C0h]
  hkaiNavMeshInstance *mesh; // [rsp+40h] [rbp-B8h]
  int v96; // [rsp+48h] [rbp-B0h]
  int v97; // [rsp+4Ch] [rbp-ACh]
  int v98; // [rsp+50h] [rbp-A8h]
  hkaiNavMesh::Face face; // [rsp+58h] [rbp-A0h]
  void *p; // [rsp+68h] [rbp-90h]
  int v101; // [rsp+70h] [rbp-88h]
  hkaiNavMeshInstance::AddEdgeContext *array; // [rsp+78h] [rbp-80h]
  int v103; // [rsp+80h] [rbp-78h]
  int v104; // [rsp+84h] [rbp-74h]
  int v105; // [rsp+88h] [rbp-70h]
  int v106; // [rsp+8Ch] [rbp-6Ch]
  int v107; // [rsp+90h] [rbp-68h]
  int v108; // [rsp+94h] [rbp-64h]
  int eIdx; // [rsp+98h] [rbp-60h]
  int v110; // [rsp+9Ch] [rbp-5Ch]
  hkaiNavMeshInstance::AddFaceContext ctx; // [rsp+A0h] [rbp-58h]
  unsigned int *v112; // [rsp+C8h] [rbp-30h]
  __int64 v113; // [rsp+D0h] [rbp-28h]
  hkResult v114; // [rsp+D8h] [rbp-20h]
  hkaiNavMeshInstance *retaddr; // [rsp+128h] [rbp+30h]
  hkaiNavMeshInstance *result; // [rsp+130h] [rbp+38h]
  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > *v117; // [rsp+140h] [rbp+48h]
  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > *v118; // [rsp+148h] [rbp+50h]

  v118 = exactEdges;
  result = meshInstance;
  v4 = res->m_originalFace;
  v5 = res->m_flags.m_storage;
  v6 = res;
  v7 = meshInstance->m_numOriginalFaces;
  v8 = v4 >> 22;
  v9 = &meshInstance->m_ownedFaces;
  index = v4 & 0x3FFFFF;
  v97 = v8;
  instanceMap = &meshInstance->m_faceMap;
  v12 = magic;
  v13 = &meshInstance->m_instancedFaces;
  v14 = meshInstance->m_originalFaces;
  v15 = v5 & 1;
  fIdx = index;
  v94 = v15;
  v104 = 2147483648;
  mesh = (hkaiNavMeshInstance *)hkaiNavMeshInstance_get_hkaiNavMesh::Face__15(v14, v7, v13, v9, instanceMap, index);
  array = 0i64;
  v103 = 0;
  v18 = 0i64;
  if ( v15 )
  {
    v20 = 1;
  }
  else
  {
    v19 = v6->m_numEdges;
    v18 = (int *)v6->m_data;
    v20 = v6->m_numPolys;
    if ( v19 > 0 )
    {
      v21 = v6->m_numEdges;
      if ( v19 < 0 )
        v21 = 0;
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        &array,
        v21,
        4);
      v17 = retaddr;
    }
    v103 = v19;
    v22 = 0i64;
    for ( i = 0; i < v20; v18 = (int *)((char *)v18 + (signed int)(((*v18 + 3) & 0xFFFFFFFC) + 8 * *v18 + 8)) )
    {
      if ( *v18 > 0 )
      {
        v24 = (unsigned int)*v18;
        do
        {
          *((_DWORD *)array + ++v22 - 1) = i;
          --v24;
        }
        while ( v24 );
      }
      ++i;
    }
    index = fIdx;
  }
  if ( v17->m_faceFlags.m_size )
    LOBYTE(result) = v17->m_faceFlags.m_data[index].m_storage;
  else
    LOBYTE(result) = 0;
  v25 = (unsigned __int8)result ^ 2;
  v89 = (unsigned __int8)result ^ 2;
  v17->m_faceFlags.m_data[index].m_storage = (unsigned __int8)result ^ 1;
  v105 = v17->m_numOriginalEdges + v17->m_ownedEdges.m_size;
  v108 = v17->m_numOriginalFaces + v17->m_ownedFaces.m_size;
  if ( v20 )
  {
    v12->m_data[index] = v12->m_size;
    v26 = v12->m_size;
    v16 = (hkArrayBase<hkVector4f> *)(unsigned int)(v26 + v20);
    v27 = v12->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v27 < (signed int)v16 )
    {
      v28 = 2 * v27;
      if ( (signed int)v16 < v28 )
        LODWORD(v16) = v28;
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v12,
        (int)v16,
        4);
    }
    v29 = v12->m_data;
    v12->m_size += v20;
    v30 = v20;
    v31 = &v29[v26];
    if ( v20 > 0 )
    {
      v32 = fIdx;
      while ( v30 )
      {
        *v31 = v32;
        ++v31;
        --v30;
      }
    }
  }
  else
  {
    v12->m_data[index] = -2;
  }
  v33 = retaddr;
  v106 = retaddr->m_numOriginalVertices + retaddr->m_ownedVertices.m_size;
  v34 = (signed __int16)mesh->m_memSizeAndFlags;
  *(_QWORD *)&face.m_startEdgeIndex = 0i64;
  *(_DWORD *)&face.m_numEdges = 0;
  v35 = v34 + 1;
  *(_DWORD *)&face.m_clusterIndex = 2147483648;
  v101 = v35;
  if ( v35 )
  {
    v36 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v37 = v36;
    v38 = (char *)v36->m_cur;
    v39 = (16 * v35 + 127) & 0xFFFFFF80;
    v40 = &v38[v39];
    if ( v39 > v37->m_slabSize || v40 > v37->m_end )
      v38 = (char *)hkLifoAllocator::allocateFromNewSlab(v37, v39);
    else
      v37->m_cur = v40;
  }
  else
  {
    v38 = 0i64;
  }
  *(_QWORD *)&face.m_startEdgeIndex = v38;
  p = v38;
  *(_DWORD *)&face.m_clusterIndex = v35 | 0x80000000;
  v41 = mesh;
  if ( v15 )
  {
    *(_DWORD *)&face.m_numEdges = (signed __int16)mesh->m_memSizeAndFlags + 1;
    hkaiNavMeshUtils::getFaceLocalVertices<hkaiNavMeshInstance>((hkaiNavMeshUtils *)retaddr, mesh, &face, v16);
    v42 = *(hkVector4f **)&face.m_startEdgeIndex;
    v43 = (signed __int16)mesh->m_memSizeAndFlags;
  }
  else
  {
    v18 = (int *)v6->m_data;
    v43 = v6->m_numVertices;
    v42 = (hkVector4f *)((char *)v18 + ((9 * v6->m_numEdges + 11 * v6->m_numPolys + 15i64) & 0xFFFFFFFFFFFFFFF0ui64));
  }
  hkaiNavMeshInstance::appendVertices(retaddr, v42, v43);
  if ( v20 > 0 )
  {
    v44 = v15;
    v113 = (unsigned int)v20;
    do
    {
      if ( v44 )
      {
        v45 = (signed __int16)v41->m_memSizeAndFlags;
        v46 = -1;
      }
      else
      {
        v45 = *v18;
        v46 = v18[1];
      }
      v47 = v33->m_numOriginalEdges + v33->m_ownedEdges.m_size;
      v98 = v45;
      *(_QWORD *)ctx.m_data = 0i64;
      *(_QWORD *)&ctx.m_data[2] = 0i64;
      hkaiNavMeshInstance::getFaceDataForContext(v33, fIdx, &ctx);
      ctx.m_face.m_numUserEdges = 0;
      ctx.m_face.m_padding = -12851;
      v48 = *(&mesh->m_referenceCount + 1);
      ctx.m_face.m_startUserEdgeIndex = -1;
      ctx.m_face.m_clusterIndex = v48;
      v49 = ctx.m_data[0];
      ctx.m_flags.m_storage = v25;
      if ( v46 != -1 )
        v49 = v46;
      ctx.m_face.m_numEdges = v45;
      ctx.m_face.m_startEdgeIndex = v47;
      ctx.m_data[0] = v49;
      hkaiNavMeshInstance::appendFaces(v33, &ctx, 1);
      v50 = v45;
      if ( v45 )
      {
        v96 = 40 * v45;
        v51 = (hkaiNavMeshInstance::AddEdgeContext *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                                       (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                                       &v96);
        v50 = v96 / 40;
      }
      else
      {
        v51 = 0i64;
      }
      v52 = 2147483648;
      array = v51;
      if ( v50 )
        v52 = v50;
      v53 = v45;
      v107 = v52;
      if ( v45 > 0 )
      {
        v54 = (signed __int64)&v51->m_edge.m_oppositeEdge;
        do
        {
          if ( v54 != 8 )
          {
            *(_QWORD *)v54 = -1i64;
            *(_DWORD *)(v54 + 8) = 4;
            *(_WORD *)(v54 + 28) = -1;
            *(_QWORD *)(v54 + 12) = 0i64;
            *(_QWORD *)(v54 + 20) = 0i64;
          }
          v54 += 40i64;
          --v53;
        }
        while ( v53 );
        v44 = v94;
      }
      v55 = 0;
      if ( v45 > 0 )
      {
        v56 = v117;
        v57 = v18 + 2;
        v58 = (signed __int64)&v51->m_edge.m_oppositeFace;
        v112 = (unsigned int *)(v18 + 2);
        do
        {
          v59 = v55;
          if ( !v44 )
            v59 = *v57;
          v110 = v55 + 1;
          v60 = (v55 + 1) % v45;
          v61 = (v55 + 1) % v45;
          if ( v44 )
            v62 = v60;
          else
            v62 = v18[v60 + 2];
          v63 = v106;
          *(_QWORD *)(v58 - 4) = -1i64;
          *(_DWORD *)(v58 + 4) = 4;
          *(_DWORD *)(v58 - 12) = v59 + v63;
          *(_DWORD *)(v58 - 8) = v62 + v63;
          if ( v44 )
          {
            LOBYTE(result) = 0;
            v64 = &result;
          }
          else
          {
            v64 = (hkaiNavMeshInstance **)&v91;
            v91 = *((_BYTE *)&v18[2 * (*v18 + 1)] + v55);
          }
          v65 = *(_BYTE *)v64;
          if ( (*(_BYTE *)v64 & 3) == 2 )
          {
            v66 = v97 << 22;
            v67 = v18[v55 + *v18 + 2];
            v68 = *(&array->m_edge.m_a + v67);
            v69 = v105;
            *(_BYTE *)(v58 + 4) = 6;
            *(_DWORD *)v58 = (v108 + v68) | v66;
            *(_DWORD *)(v58 - 4) = v66 | (v67 + v69);
          }
          else if ( (v65 & 3) == 1 )
          {
            *(_QWORD *)(v58 - 4) = -1i64;
            *(_BYTE *)(v58 + 4) = 5;
          }
          else
          {
            if ( v44 )
              v70 = v55;
            else
              v70 = v18[v55 + *v18 + 2];
            v71 = retaddr->m_numOriginalEdges;
            eIdx = v70 + LODWORD(mesh->vfptr);
            v72 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__17(
                    retaddr->m_originalEdges,
                    v71,
                    &retaddr->m_instancedEdges,
                    &retaddr->m_ownedEdges,
                    &retaddr->m_edgeMap,
                    eIdx)->m_flags.m_storage;
            v73 = v55;
            v74 = eIdx;
            v75 = eIdx;
            *(_BYTE *)(v58 + 4) = v72 & 0x40 | 4;
            hkaiNavMeshInstance::getEdgeDataForContext(retaddr, v75, &array[v73]);
            *(_WORD *)(v58 + 24) = v70;
            v44 = v94;
            if ( v94 )
            {
              v90 = 0;
              v76 = &v90;
            }
            else
            {
              v76 = &v92;
              v92 = *((_BYTE *)&v18[2 * *v18 + 2] + v61);
            }
            if ( !(v65 & 4) && !(*v76 & 4) )
            {
              v77 = v56->m_elem.m_size;
              v78 = v74 | (v97 << 22);
              if ( 2 * v56->m_numElems > v77 - 1 )
                hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int>>::resizeTable(
                  v56,
                  &v114,
                  2 * v77);
              v79 = v56->m_elem.m_data;
              v80 = v56->m_elem.m_size - 1;
              v81 = v80 & -1640531535 * (v78 >> 4);
              v82 = v56->m_elem.m_data[v81];
              if ( v82 == -1 )
              {
LABEL_80:
                ++v56->m_numElems;
                v79[v81] = v78;
              }
              else
              {
                while ( v82 != v78 )
                {
                  v81 = v80 & (v81 + 1);
                  v82 = v79[v81];
                  if ( v82 == -1 )
                    goto LABEL_80;
                }
                v56->m_numElems = v56->m_numElems;
                v79[v81] = v78;
              }
            }
          }
          v55 = v110;
          v45 = v98;
          v57 = (int *)(v112 + 1);
          v58 += 40i64;
          ++v112;
        }
        while ( v110 < v98 );
        v25 = v89;
        v33 = retaddr;
        v52 = v107;
        v51 = array;
      }
      hkaiNavMeshInstance::appendEdges(v33, v51, v45);
      if ( v44 )
        v18 = 0i64;
      else
        v18 = (int *)((char *)v18 + (signed int)(((*v18 + 3) & 0xFFFFFFFC) + 8 * *v18 + 8));
      if ( v52 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          40 * (v52 & 0x3FFFFFFF));
      v83 = v113-- == 1;
      v41 = mesh;
    }
    while ( !v83 );
  }
  v84 = *(_DWORD *)&face.m_numEdges;
  v85 = (char *)p;
  if ( p == *(void **)&face.m_startEdgeIndex )
    v84 = 0;
  *(_DWORD *)&face.m_numEdges = v84;
  v86 = (16 * v101 + 127) & 0xFFFFFF80;
  v87 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v88 = (v86 + 15) & 0xFFFFFFF0;
  if ( v86 > v87->m_slabSize || &v85[v88] != v87->m_cur || v87->m_firstNonLifoEnd == v85 )
    hkLifoAllocator::slowBlockFree(v87, v85, v88);
  else
    v87->m_cur = v85;
  *(_DWORD *)&face.m_numEdges = 0;
  if ( *(_DWORD *)&face.m_clusterIndex >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)&face.m_startEdgeIndex,
      16 * *(_DWORD *)&face.m_clusterIndex);
  *(_QWORD *)&face.m_startEdgeIndex = 0i64;
  v103 = 0;
  *(_DWORD *)&face.m_clusterIndex = 2147483648;
  if ( v104 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v104);
}

// File Line: 394
// RVA: 0xC18C50
void __fastcall hkaiNavMeshCutter::removeUnusedCutEdges(hkaiNavMeshCutter *this, hkArrayBase<int> *cutSections)
{
  int v2; // ebx
  hkArrayBase<int> *v3; // rsi
  hkaiNavMeshCutter *v4; // rbp
  __int64 v5; // rdi
  hkaiNavMeshInstance *v6; // rcx

  v2 = 0;
  v3 = cutSections;
  v4 = this;
  if ( cutSections->m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v4->m_streamingCollection.m_pntr->m_instances.m_data[v3->m_data[v5]].m_instancePtr;
      if ( v6 )
        hkaiNavMeshUtils::compactInstancedEdges(v6);
      ++v2;
      ++v5;
    }
    while ( v2 < v3->m_size );
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
void __fastcall hkaiNavMeshCutter::matchStreamingFaces(hkaiNavMeshCutter *this, hkArrayBase<int> *cutSections, hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > *cutFaces)
{
  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > *v3; // rsi
  int v4; // er8
  hkArrayBase<int> *v5; // rax
  hkaiNavMeshCutter *v6; // rbx
  __int64 v7; // rcx
  int v8; // er15
  __int64 v9; // rax
  __int64 v10; // rdx
  signed __int64 v11; // r13
  __int64 v12; // rdi
  int v13; // er14
  int v14; // er12
  __int64 v15; // rdx
  int v16; // er11
  __int64 v17; // r13
  _DWORD *v18; // r10
  int v19; // er8
  unsigned int v20; // edi
  int v21; // eax
  unsigned int v22; // edx
  int v23; // ecx
  int v24; // esi
  int v25; // eax
  int v26; // er14
  int v27; // er15
  bool v28; // bl
  bool v29; // al
  __int64 v30; // rdx
  hkArray<hkaiNavMeshCutter::FaceEdgePair,hkContainerTempAllocator> v31; // [rsp+18h] [rbp-49h]
  hkArray<hkaiNavMeshCutter::FaceEdgePair,hkContainerTempAllocator> cutPairs; // [rsp+28h] [rbp-39h]
  int v33; // [rsp+38h] [rbp-29h]
  int v34; // [rsp+3Ch] [rbp-25h]
  int v35; // [rsp+40h] [rbp-21h]
  __int64 v36; // [rsp+48h] [rbp-19h]
  int v37; // [rsp+50h] [rbp-11h]
  __int64 v38; // [rsp+58h] [rbp-9h]
  __int64 v39; // [rsp+60h] [rbp-1h]
  __int64 *v40; // [rsp+68h] [rbp+7h]
  hkaiNavMeshCutter *v41; // [rsp+C8h] [rbp+67h]
  hkArrayBase<int> *vars0; // [rsp+D0h] [rbp+6Fh]
  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > *retaddr; // [rsp+D8h] [rbp+77h]
  int v44; // [rsp+E0h] [rbp+7Fh]

  v3 = cutFaces;
  v4 = 0;
  v5 = cutSections;
  v6 = this;
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
      v10 = (__int64)v6->m_streamingCollection.m_pntr->m_instances.m_data[v9].m_instancePtr;
      v36 = v10;
      v11 = *(_QWORD *)(v10 + 96) + 64i64;
      v40 = (__int64 *)v11;
      if ( *(_DWORD *)(v11 + 8) > 0 )
      {
        v12 = 0i64;
        v39 = 0i64;
        do
        {
          if ( *(_DWORD *)(v10 + 468) == *(_DWORD *)(*(_QWORD *)v11 + v12) )
          {
            v13 = hkaiStreamingCollection::findSectionIdByUid(
                    v6->m_streamingCollection.m_pntr,
                    *(_DWORD *)(*(_QWORD *)v11 + v12 + 4));
            v34 = v13;
            if ( v13 != -1 )
            {
              v14 = 0;
              v15 = v12 + *(_QWORD *)v11;
              if ( *(_DWORD *)(v15 + 16) > 0 )
              {
                v16 = v37 << 22;
                v17 = 0i64;
                v44 = v37 << 22;
                do
                {
                  v18 = (_DWORD *)(v17 + *(_QWORD *)(v15 + 8));
                  v19 = v3->m_elem.m_size - 1;
                  cutPairs.m_data = 0i64;
                  cutPairs.m_size = 0;
                  cutPairs.m_capacityAndFlags = 2147483648;
                  v31.m_data = 0i64;
                  v31.m_size = 0;
                  v31.m_capacityAndFlags = 2147483648;
                  v20 = *v18 | v16;
                  if ( v19 <= 0 || (v21 = v19 & -1640531535 * (v20 >> 4), v22 = v3->m_elem.m_data[v21], v22 == -1) )
                  {
LABEL_13:
                    v23 = v19 + 1;
                  }
                  else
                  {
                    while ( v22 != v20 )
                    {
                      v21 = v19 & (v21 + 1);
                      v22 = v3->m_elem.m_data[v21];
                      if ( v22 == -1 )
                        goto LABEL_13;
                    }
                    v23 = v21;
                  }
                  if ( v23 <= v19 )
                  {
                    v24 = v16 | v18[1];
                    v25 = v13 << 22;
                    v26 = (v13 << 22) | v18[2];
                    v27 = v25 | v18[3];
                    v28 = hkaiStreamingCollection::areKeysConsistent(
                            v6->m_streamingCollection.m_pntr,
                            v20,
                            v16 | v18[1]);
                    v29 = hkaiStreamingCollection::areKeysConsistent(v41->m_streamingCollection.m_pntr, v26, v27);
                    if ( v28 && v29 )
                    {
                      v6 = v41;
                      hkaiNavMeshCutter::mergeCutBoundaryEdges(v41, v20, v24);
                      hkaiNavMeshCutter::mergeCutBoundaryEdges(v6, v26, v27);
                      hkaiNavMeshCutter::gatherCutEdges(v6, v24, v20, &cutPairs, GATHER_BOUNDARY_EDGES);
                      hkaiNavMeshCutter::gatherCutEdges(v6, v27, v26, &v31, GATHER_BOUNDARY_EDGES);
                      hkaiNavMeshCutter::matchNewEdgesFromOriginalEdge(
                        v6,
                        v6->m_streamingCollection.m_pntr,
                        (hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *)&cutPairs.m_data,
                        (hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *)&v31.m_data);
                      v31.m_size = 0;
                      if ( v31.m_capacityAndFlags >= 0 )
                        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                          v31.m_data,
                          8 * v31.m_capacityAndFlags);
                      v31.m_data = 0i64;
                      v31.m_capacityAndFlags = 2147483648;
                      cutPairs.m_size = 0;
                      if ( cutPairs.m_capacityAndFlags >= 0 )
                        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                          cutPairs.m_data,
                          8 * cutPairs.m_capacityAndFlags);
                    }
                    else
                    {
                      v31.m_size = 0;
                      if ( v31.m_capacityAndFlags >= 0 )
                        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                          v31.m_data,
                          8 * v31.m_capacityAndFlags);
                      v31.m_data = 0i64;
                      v31.m_capacityAndFlags = 2147483648;
                      cutPairs.m_size = 0;
                      if ( cutPairs.m_capacityAndFlags >= 0 )
                        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                          cutPairs.m_data,
                          8 * cutPairs.m_capacityAndFlags);
                      v6 = v41;
                    }
                    v13 = v34;
                    v3 = retaddr;
                    v16 = v44;
                  }
                  else
                  {
                    v31.m_size = 0;
                    v31.m_data = 0i64;
                    v31.m_capacityAndFlags = 2147483648;
                    cutPairs.m_size = 0;
                  }
                  v12 = v39;
                  ++v14;
                  v30 = *v40;
                  v17 += 16i64;
                  cutPairs.m_data = 0i64;
                  v15 = v39 + v30;
                  cutPairs.m_capacityAndFlags = 2147483648;
                }
                while ( v14 < *(_DWORD *)(v15 + 16) );
                v8 = v35;
                v11 = (signed __int64)v40;
              }
            }
            v10 = v36;
          }
          ++v8;
          v12 += 56i64;
          v35 = v8;
          v39 = v12;
        }
        while ( v8 < *(_DWORD *)(v11 + 8) );
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
}+ 4;
      v33 = v4;
      v38 += 4i64;
    }
    while ( v4 < vars0->m_size );
  }
}

// File Line: 542
// RVA: 0xC18CD0
void __fastcall hkaiNavMeshCutter::applyCutResults(hkaiNavMeshCutter *this, hkArrayBase<int> *cutSections, hkArray<hkaiFaceCutResults,hkContainerTempAllocator> *results, hkArray<unsigned int,hkContainerTempAllocator> *cutFaces)
{
  hkaiNavMeshCutter *v4; // r13
  hkArray<unsigned int,hkContainerTempAllocator> *v5; // r14
  hkArray<hkaiFaceCutResults,hkContainerTempAllocator> *v6; // rsi
  hkArrayBase<int> *v7; // r12
  _QWORD *v8; // rax
  unsigned __int64 v9; // r8
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  int v12; // er8
  signed int v13; // er8
  _QWORD *v14; // r8
  _QWORD *v15; // rcx
  unsigned __int64 v16; // rax
  signed __int64 v17; // rcx
  int v18; // edi
  __int64 v19; // r14
  char *v20; // r15
  unsigned int v21; // ebx
  _QWORD **v22; // rax
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  signed __int64 v26; // rcx
  int v27; // edx
  int v28; // esi
  __int64 v29; // rdi
  int v30; // er9
  int v31; // edx
  unsigned int v32; // ebx
  int v33; // er10
  signed int v34; // er11
  int v35; // ecx
  unsigned int v36; // edx
  _QWORD *v37; // r8
  _QWORD *v38; // rcx
  unsigned __int64 v39; // rax
  signed __int64 v40; // rcx
  int v41; // er9
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v42; // r10
  int v43; // edx
  signed __int64 v44; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v45; // rax
  int v46; // ebx
  hkArrayBase<unsigned int> *v47; // r12
  unsigned int v48; // er15
  int v49; // edx
  signed __int64 v50; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v51; // rax
  hkaiNavMeshInstance *v52; // rbx
  hkaiNavMesh::Edge *v53; // rax
  unsigned int v54; // edx
  char v55; // r8
  unsigned int v56; // ecx
  unsigned int v57; // edi
  unsigned int v58; // ecx
  unsigned int v59; // eax
  unsigned int v60; // esi
  int v61; // eax
  __int64 v62; // r14
  unsigned __int64 v63; // rbx
  hkArrayBase<unsigned int> *v64; // r8
  int v65; // er8
  _QWORD **v66; // rax
  char v67; // bl
  __int64 v68; // rbx
  hkaiNavMeshInstance *v69; // rax
  char v70; // cl
  char *v71; // rax
  int v72; // er8
  int v73; // ecx
  unsigned int v74; // edx
  int v75; // eax
  int v76; // er10
  __int64 v77; // r11
  unsigned int v78; // er8
  signed __int64 v79; // rdx
  int v80; // er8
  hkaiNavMeshInstance *v81; // r9
  int v82; // eax
  signed __int64 v83; // rcx
  hkaiNavMesh::Edge *v84; // rax
  signed __int64 v85; // rdx
  int v86; // er8
  _QWORD **v87; // rax
  int v88; // edx
  signed __int64 v89; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v90; // rax
  signed __int64 v91; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v92; // rax
  int v93; // er14
  __int64 v94; // r15
  unsigned int v95; // edx
  hkaiStreamingCollection::InstanceInfo *v96; // rsi
  hkaiNavMeshInstance *v97; // rbx
  hkaiNavMesh::Edge *v98; // rax
  hkaiNavMesh::Edge *v99; // r8
  unsigned int v100; // edx
  char v101; // r9
  unsigned int v102; // ecx
  unsigned int v103; // edi
  hkaiNavMeshInstance *v104; // r10
  hkResult *v105; // rax
  char v106; // al
  hkaiNavMesh::Edge *v107; // rbx
  _QWORD *v108; // r8
  _QWORD *v109; // rcx
  unsigned __int64 v110; // rax
  signed __int64 v111; // rcx
  _QWORD *v112; // r8
  _QWORD *v113; // rcx
  unsigned __int64 v114; // rax
  signed __int64 v115; // rcx
  unsigned int v116; // ecx
  unsigned int v117; // eax
  int v118; // er8
  int v119; // er10
  __int64 v120; // r11
  signed int v121; // eax
  hkaiNavMeshInstance *v122; // r9
  int v123; // ecx
  __int64 v124; // rcx
  hkaiNavMesh::Edge *v125; // rax
  signed __int64 v126; // rcx
  char v127; // [rsp+30h] [rbp-89h]
  hkArray<hkaiNavMeshCutter::FaceEdgePair,hkContainerTempAllocator> v128; // [rsp+38h] [rbp-81h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v129; // [rsp+48h] [rbp-71h]
  hkArray<hkaiNavMeshCutter::FaceEdgePair,hkContainerTempAllocator> cutPairs; // [rsp+58h] [rbp-61h]
  hkArray<unsigned int,hkContainerTempAllocator> unmappedEdges; // [rsp+68h] [rbp-51h]
  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > cutFacesa; // [rsp+78h] [rbp-41h]
  hkArray<hkaiNavMeshCutter::FaceEdgePair,hkContainerTempAllocator> v133; // [rsp+90h] [rbp-29h]
  __int64 v134; // [rsp+A0h] [rbp-19h]
  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int> > exactEdges; // [rsp+A8h] [rbp-11h]
  hkArrayBase<unsigned int> *v136; // [rsp+C0h] [rbp+7h]
  hkResult result; // [rsp+120h] [rbp+67h]
  hkArrayBase<int> *v138; // [rsp+128h] [rbp+6Fh]
  char v139; // [rsp+130h] [rbp+77h]
  hkArray<unsigned int,hkContainerTempAllocator> *v140; // [rsp+138h] [rbp+7Fh]

  v140 = cutFaces;
  v138 = cutSections;
  v4 = this;
  v5 = cutFaces;
  v6 = results;
  v7 = cutSections;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = v8[1];
  v10 = v8;
  if ( v9 < v8[3] )
  {
    *(_QWORD *)v9 = "LtapplyCuts";
    *(_QWORD *)(v9 + 16) = "StGatherEdges";
    v11 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v11;
    v10[1] = v9 + 24;
  }
  v12 = 2 * v6->m_size;
  v129.m_elem = 0i64;
  v129.m_numElems = 0;
  v129.m_hashMod = -1;
  exactEdges.m_elem.m_data = 0i64;
  exactEdges.m_elem.m_size = 0;
  exactEdges.m_elem.m_capacityAndFlags = 2147483648;
  exactEdges.m_numElems = 0;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    &v129,
    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
    v12);
  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int>>::reserve(&exactEdges, v6->m_size);
  v13 = v6->m_size;
  unmappedEdges.m_data = 0i64;
  unmappedEdges.m_size = 0;
  unmappedEdges.m_capacityAndFlags = 2147483648;
  if ( v13 > 1 )
    hkAlgorithm::quickSortRecursive<hkaiFaceCutResults,unsigned int (*)(hkaiFaceCutResults const &,hkaiFaceCutResults const &)>(
      v6->m_data,
      0,
      v13 - 1,
      CutResultCompare);
  gatherEdgeMap(
    v4->m_streamingCollection.m_pntr,
    (hkArrayBase<hkaiFaceCutResults> *)&v6->m_data,
    (hkPointerMap<unsigned int,hkArray<unsigned int,hkContainerHeapAllocator> *,hkContainerTempAllocator> *)&v129,
    &unmappedEdges);
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)v14[1];
  if ( (unsigned __int64)v15 < v14[3] )
  {
    *v15 = "StAddFaces";
    v16 = __rdtsc();
    v17 = (signed __int64)(v15 + 2);
    *(_DWORD *)(v17 - 8) = v16;
    v14[1] = v17;
  }
  v18 = 0;
  if ( v6->m_size > 0 )
  {
    v19 = 0i64;
    do
    {
      addFacesForCut(
        v4->m_streamingCollection.m_pntr->m_instances.m_data[v6->m_data[v19].m_originalFace >> 22].m_instancePtr,
        &v6->m_data[v18],
        &v4->m_meshInfos.m_data[v6->m_data[v19].m_originalFace >> 22].m_magic,
        &exactEdges);
      v20 = v6->m_data[v19].m_data;
      if ( v20 )
      {
        v21 = v6->m_data[v19].m_allocatedSize;
        v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, char *, _QWORD))(*v22[11] + 16i64))(v22[11], v20, v21);
      }
      ++v18;
      ++v19;
    }
    while ( v18 < v6->m_size );
    v5 = v140;
  }
  v23 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v24 = (_QWORD *)v23[1];
  if ( (unsigned __int64)v24 < v23[3] )
  {
    *v24 = "StMatchStreaming";
    v25 = __rdtsc();
    v26 = (signed __int64)(v24 + 2);
    *(_DWORD *)(v26 - 8) = v25;
    v23[1] = v26;
  }
  v27 = v5->m_size;
  cutFacesa.m_elem.m_data = 0i64;
  cutFacesa.m_elem.m_size = 0;
  cutFacesa.m_elem.m_capacityAndFlags = 2147483648;
  cutFacesa.m_numElems = 0;
  hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int>>::reserve(&cutFacesa, v27);
  v28 = 0;
  if ( v5->m_size > 0 )
  {
    v29 = 0i64;
    do
    {
      v30 = cutFacesa.m_numElems;
      v31 = cutFacesa.m_elem.m_size;
      v32 = v5->m_data[v29];
      if ( 2 * cutFacesa.m_numElems > cutFacesa.m_elem.m_size - 1 )
      {
        hkSet<unsigned int,hkContainerTempAllocator,hkMapOperations<unsigned int>>::resizeTable(
          &cutFacesa,
          &result,
          2 * cutFacesa.m_elem.m_size);
        v30 = cutFacesa.m_numElems;
        v31 = cutFacesa.m_elem.m_size;
      }
      v33 = v31 - 1;
      v34 = 1;
      v35 = (v31 - 1) & -1640531535 * (v32 >> 4);
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
      cutFacesa.m_numElems = v34 + v30;
      cutFacesa.m_elem.m_data[v35] = v32;
      ++v29;
    }
    while ( v28 < v5->m_size );
  }
  hkaiNavMeshCutter::matchStreamingFaces(v4, v7, &cutFacesa);
  v37 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v38 = (_QWORD *)v37[1];
  if ( (unsigned __int64)v38 < v37[3] )
  {
    *v38 = "StFixUpEdges";
    v39 = __rdtsc();
    v40 = (signed __int64)(v38 + 2);
    *(_DWORD *)(v40 - 8) = v39;
    v37[1] = v40;
  }
  v41 = v129.m_hashMod;
  v42 = v129.m_elem;
  v43 = 0;
  v44 = 0i64;
  if ( v129.m_hashMod >= 0 )
  {
    v45 = v129.m_elem;
    do
    {
      if ( v45->key != -1i64 )
        break;
      ++v44;
      ++v43;
      ++v45;
    }
    while ( v44 <= v129.m_hashMod );
  }
  v46 = v43;
  v134 = v43;
  if ( v43 <= v129.m_hashMod )
  {
LABEL_32:
    LOBYTE(result.m_enum) = 0;
    v47 = (hkArrayBase<unsigned int> *)v42[v46].val;
    v48 = v42[v46].key;
    v136 = v47;
    if ( !v47 )
    {
      v49 = v46 + 1;
      v50 = v46 + 1;
      if ( v50 <= v41 )
      {
        v51 = &v42[v49];
        do
        {
          if ( v51->key != -1i64 )
            break;
          ++v50;
          ++v49;
          ++v51;
        }
        while ( v50 <= v41 );
      }
      v46 = v49;
      v134 = v49;
      goto LABEL_104;
    }
    v42[v46].val = 0i64;
    cutPairs.m_data = 0i64;
    cutPairs.m_size = 0;
    cutPairs.m_capacityAndFlags = 2147483648;
    hkaiNavMeshCutter::gatherCutEdgesFromCutFaces(v4, v48, v47, &cutPairs);
    v52 = v4->m_streamingCollection.m_pntr->m_instances.m_data[v48 >> 22].m_instancePtr;
    v53 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__17(
            v52->m_originalEdges,
            v52->m_numOriginalEdges,
            &v52->m_instancedEdges,
            &v52->m_ownedEdges,
            &v52->m_edgeMap,
            v48 & 0x3FFFFF);
    v54 = v53->m_oppositeEdge;
    v55 = v53->m_flags.m_storage & 0x40;
    if ( v55 )
      v56 = v54 & 0xFFC00000;
    else
      v56 = v52->m_runtimeId << 22;
    v57 = v56 | v54 & 0x3FFFFF;
    v58 = v53->m_oppositeFace;
    if ( v54 == -1 )
      v57 = -1;
    if ( v55 )
      v59 = v58 & 0xFFC00000;
    else
      v59 = v52->m_runtimeId << 22;
    v60 = v59 | v58 & 0x3FFFFF;
    if ( v58 == -1 )
      v60 = -1;
    v61 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                              &v129,
                              v57);
    if ( v61 <= v129.m_hashMod )
    {
      v62 = v61;
      v63 = v129.m_elem[v61].val;
      if ( v63 )
      {
        v64 = (hkArrayBase<unsigned int> *)v129.m_elem[v61].val;
        v133.m_capacityAndFlags = 2147483648;
        v133.m_data = 0i64;
        v133.m_size = 0;
        hkaiNavMeshCutter::gatherCutEdgesFromCutFaces(v4, v57, v64, &v133);
        hkaiNavMeshCutter::matchNewEdgesFromOriginalEdge(
          v4,
          v4->m_streamingCollection.m_pntr,
          (hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *)&cutPairs.m_data,
          (hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *)&v133.m_data);
        v65 = *(_DWORD *)(v63 + 12);
        *(_DWORD *)(v63 + 8) = 0;
        if ( v65 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)v63,
            4 * v65);
        *(_QWORD *)v63 = 0i64;
        *(_DWORD *)(v63 + 12) = 2147483648;
        v66 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, unsigned __int64, signed __int64))(*v66[11] + 16i64))(v66[11], v63, 16i64);
        v129.m_elem[v62].val = 0i64;
        v133.m_size = 0;
        if ( v133.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v133.m_data,
            8 * v133.m_capacityAndFlags);
        v133.m_data = 0i64;
        v133.m_capacityAndFlags = 2147483648;
        v67 = 0;
        goto LABEL_89;
      }
      v5 = v140;
    }
    v68 = v60 >> 22;
    v69 = v4->m_streamingCollection.m_pntr->m_instances.m_data[v68].m_instancePtr;
    if ( v69->m_faceFlags.m_size )
    {
      v70 = v69->m_faceFlags.m_data[v60 & 0x3FFFFF].m_storage;
      v71 = &v139;
      v139 = v70;
    }
    else
    {
      v127 = 0;
      v71 = &v127;
    }
    if ( *v71 & 1 )
    {
      v67 = result.m_enum;
    }
    else
    {
      if ( cutPairs.m_size == 1 )
      {
        v72 = exactEdges.m_elem.m_size - 1;
        if ( exactEdges.m_elem.m_size - 1 <= 0
          || (v73 = v72 & -1640531535 * (v48 >> 4), v74 = exactEdges.m_elem.m_data[v73], v74 == -1) )
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
        if ( v75 <= v72 || (unsigned int)hkaiNavMeshCutter::doEdgesMatch(v4, v57, cutPairs.m_data->m_edgeKey) )
        {
          hkaiNavMeshCutterHelper::connectCutFaceToUncutFace(
            v4->m_streamingCollection.m_pntr,
            &v4->m_connectivityInfo,
            v57,
            v48,
            (hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *)&cutPairs.m_data);
          v67 = result.m_enum;
          goto LABEL_89;
        }
      }
      hkaiNavMeshCutterHelper::replaceFaceWithCutFace(
        v4->m_streamingCollection.m_pntr,
        v60,
        v57,
        &v4->m_connectivityInfo,
        &v4->m_meshInfos.m_data[v68].m_magic,
        (hkPointerMap<unsigned int,hkArray<unsigned int,hkContainerHeapAllocator> *,hkContainerTempAllocator> *)&v129);
      if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v5, 4);
      v67 = 1;
      v5->m_data[v5->m_size++] = v60;
    }
    hkaiNavMeshCutter::mergeCutBoundaryEdges(v4, v60, v57);
    v128.m_data = 0i64;
    v128.m_size = 0;
    v128.m_capacityAndFlags = 2147483648;
    hkaiNavMeshCutter::gatherCutEdges(v4, v57, v60, &v128, 0);
    v76 = 0;
    if ( v128.m_size <= 0 )
      goto LABEL_86;
    v77 = 0i64;
    while ( 1 )
    {
      v78 = v128.m_data[v77].m_edgeKey;
      v79 = v78 >> 22;
      v80 = v78 & 0x3FFFFF;
      v81 = v4->m_streamingCollection.m_pntr->m_instances.m_data[v79].m_instancePtr;
      v82 = v81->m_numOriginalEdges;
      if ( v80 >= v82 )
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
      *(_DWORD *)(v85 + 12) = -1;
      *(_DWORD *)(v85 + 8) = -1;
      ++v77;
      if ( v76 >= v128.m_size )
      {
        v47 = v136;
LABEL_86:
        hkaiNavMeshCutter::matchNewEdgesFromOriginalEdge(
          v4,
          v4->m_streamingCollection.m_pntr,
          (hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *)&cutPairs.m_data,
          (hkArrayBase<hkaiNavMeshCutter::FaceEdgePair> *)&v128.m_data);
        v128.m_size = 0;
        if ( v128.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v128.m_data,
            8 * v128.m_capacityAndFlags);
        v128.m_data = 0i64;
        v128.m_capacityAndFlags = 2147483648;
LABEL_89:
        v86 = v47->m_capacityAndFlags;
        v47->m_size = 0;
        if ( v86 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v47->m_data,
            4 * v86);
        v47->m_data = 0i64;
        v47->m_capacityAndFlags = 2147483648;
        v87 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkArrayBase<unsigned int> *, signed __int64))(*v87[11] + 16i64))(
          v87[11],
          v47,
          16i64);
        v41 = v129.m_hashMod;
        v42 = v129.m_elem;
        if ( v67 )
        {
          v88 = 0;
          v89 = 0i64;
          if ( v129.m_hashMod >= 0 )
          {
            v90 = v129.m_elem;
            do
            {
              if ( v90->key != -1i64 )
                break;
              ++v89;
              ++v88;
              ++v90;
            }
            while ( v89 <= v129.m_hashMod );
          }
        }
        else
        {
          v88 = v134 + 1;
          v91 = (signed int)v134 + 1;
          if ( v91 <= v129.m_hashMod )
          {
            v92 = &v129.m_elem[v88];
            do
            {
              if ( v92->key != -1i64 )
                break;
              ++v91;
              ++v88;
              ++v92;
            }
            while ( v91 <= v129.m_hashMod );
          }
        }
        v46 = v88;
        cutPairs.m_size = 0;
        v134 = v88;
        if ( cutPairs.m_capacityAndFlags >= 0 )
        {
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            cutPairs.m_data,
            8 * cutPairs.m_capacityAndFlags);
          v41 = v129.m_hashMod;
          v42 = v129.m_elem;
        }
        v5 = v140;
        cutPairs.m_data = 0i64;
        cutPairs.m_capacityAndFlags = 2147483648;
LABEL_104:
        if ( v46 > v41 )
        {
          v7 = v138;
          goto LABEL_106;
        }
        goto LABEL_32;
      }
    }
    v83 = v80 - v82;
    v84 = v81->m_ownedEdges.m_data;
LABEL_83:
    v85 = (signed __int64)&v84[v83];
    goto LABEL_84;
  }
LABEL_106:
  v93 = 0;
  if ( unmappedEdges.m_size > 0 )
  {
    v94 = 0i64;
    while ( 1 )
    {
      v95 = unmappedEdges.m_data[v94];
      v96 = v4->m_streamingCollection.m_pntr->m_instances.m_data;
      v97 = v96[v95 >> 22].m_instancePtr;
      v98 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__17(
              v97->m_originalEdges,
              v97->m_numOriginalEdges,
              &v97->m_instancedEdges,
              &v97->m_ownedEdges,
              &v97->m_edgeMap,
              v95 & 0x3FFFFF);
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
        if ( v100 == -1 )
          v103 = -1;
        v104 = v96[v103 >> 22].m_instancePtr;
        if ( v104->m_faceFlags.m_size )
        {
          v105 = (hkResult *)&v140;
          LOBYTE(v140) = v104->m_faceFlags.m_data[v99->m_oppositeFace & 0x3FFFFF].m_storage;
        }
        else
        {
          LOBYTE(result.m_enum) = 0;
          v105 = &result;
        }
        v106 = v105->m_enum & 0xFB;
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
            v128.m_data = 0i64;
            v128.m_size = 0;
            v128.m_capacityAndFlags = 2147483648;
            hkaiNavMeshCutter::gatherCutEdges(v4, v103, v118, &v128, 0);
            v119 = 0;
            if ( v128.m_size <= 0 )
            {
LABEL_149:
              v128.m_size = 0;
              if ( v128.m_capacityAndFlags >= 0 )
                hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                  v128.m_data,
                  8 * v128.m_capacityAndFlags);
              v128.m_data = 0i64;
              v128.m_capacityAndFlags = 2147483648;
              goto LABEL_119;
            }
            v120 = 0i64;
            while ( 2 )
            {
              v121 = v128.m_data[v120].m_edgeKey & 0x3FFFFF;
              v122 = v4->m_streamingCollection.m_pntr->m_instances.m_data[v128.m_data[v120].m_edgeKey >> 22].m_instancePtr;
              v123 = v122->m_numOriginalEdges;
              if ( v121 >= v123 )
              {
                v124 = v121 - v123;
                v125 = v122->m_ownedEdges.m_data;
                goto LABEL_147;
              }
              if ( v122->m_edgeMap.m_size )
                v121 = v122->m_edgeMap.m_data[v121];
              if ( v121 == -1 )
              {
                v126 = 0i64;
              }
              else
              {
                v124 = v121;
                v125 = v122->m_instancedEdges.m_data;
LABEL_147:
                v126 = (signed __int64)&v125[v124];
              }
              ++v119;
              *(_DWORD *)(v126 + 12) = -1;
              *(_DWORD *)(v126 + 8) = -1;
              ++v120;
              if ( v119 >= v128.m_size )
                goto LABEL_149;
              continue;
            }
          }
        }
        else
        {
          v107 = hkaiNavMeshInstance::instanceEdge(v104, v100 & 0x3FFFFF);
          hkaiNavMeshCutter::SavedConnectivity::addConnectivity(&v4->m_connectivityInfo, v103);
          v107->m_oppositeFace = -1;
          v107->m_oppositeEdge = -1;
        }
      }
LABEL_119:
      ++v93;
      ++v94;
      if ( v93 >= unmappedEdges.m_size )
      {
        v7 = v138;
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
    v111 = (signed __int64)(v109 + 2);
    *(_DWORD *)(v111 - 8) = v110;
    v108[1] = v111;
  }
  hkaiNavMeshCutter::removeUnusedCutEdges(v4, v7);
  cutFacesa.m_elem.m_size = 0;
  if ( cutFacesa.m_elem.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      cutFacesa.m_elem.m_data,
      4 * cutFacesa.m_elem.m_capacityAndFlags);
  cutFacesa.m_elem.m_data = 0i64;
  cutFacesa.m_elem.m_capacityAndFlags = 2147483648;
  unmappedEdges.m_size = 0;
  if ( unmappedEdges.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      unmappedEdges.m_data,
      4 * unmappedEdges.m_capacityAndFlags);
  unmappedEdges.m_data = 0i64;
  unmappedEdges.m_capacityAndFlags = 2147483648;
  exactEdges.m_elem.m_size = 0;
  if ( exactEdges.m_elem.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      exactEdges.m_elem.m_data,
      4 * exactEdges.m_elem.m_capacityAndFlags);
  exactEdges.m_elem.m_data = 0i64;
  exactEdges.m_elem.m_capacityAndFlags = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v129,
    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v129);
  v112 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v113 = (_QWORD *)v112[1];
  if ( (unsigned __int64)v113 < v112[3] )
  {
    *v113 = "lt";
    v114 = __rdtsc();
    v115 = (signed __int64)(v113 + 2);
    *(_DWORD *)(v115 - 8) = v114;
    v112[1] = v115;
  }
}ontainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      exactEdges.m_elem.m_data,
      4 * exactEdges.m_elem.m_capacityAndFlags);
  exactEdges.m_elem.m_data = 0i64;
  exactEdges.m_elem.m_capacityAndFlags = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::


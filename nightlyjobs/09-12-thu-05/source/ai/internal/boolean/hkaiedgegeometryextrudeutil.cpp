// File Line: 61
// RVA: 0xB9EDD0
void __fastcall hkaiGeometryExtrudeUtil_copyVertices(hkArray<hkVector4f,hkContainerHeapAllocator> *vertices, hkaiGeometryExtrudeUtil::IndexMap *indexMap, int base, hkVector4f *offset, hkArray<hkVector4f,hkContainerHeapAllocator> *verticesOut)
{
  hkVector4f *v5; // rbx
  __int64 v6; // r9
  hkaiGeometryExtrudeUtil::IndexMap *v7; // r10
  hkVector4f *v8; // r11
  __int64 v9; // rax
  __int64 v10; // rdx
  __int64 v11; // r8

  v5 = offset;
  v6 = indexMap->m_map.m_size;
  v7 = indexMap;
  v8 = &verticesOut->m_data[base];
  v9 = 0i64;
  if ( v6 > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = v7->m_map.m_data[v9];
      if ( (signed int)v11 >= 0 )
        v8[v11].m_quad = _mm_add_ps(vertices->m_data[v10].m_quad, v5->m_quad);
      ++v9;
      ++v10;
    }
    while ( v9 < v6 );
  }
}

// File Line: 82
// RVA: 0xB9EE40
signed __int64 __fastcall hkaiGeometryExtrudeUtil_isSideEdge(hkArrayBase<int> *edgeFaces, hkBitField *forwardFaces)
{
  int v2; // eax
  __int64 v4; // rdi
  __int64 v5; // r10
  int *v6; // rbx
  __int64 v7; // rax
  signed int *v8; // r9

  v2 = edgeFaces->m_size;
  if ( v2 <= 1 )
    return 1i64;
  v4 = 0i64;
  v5 = edgeFaces->m_size;
  if ( v2 <= 0 )
    return 0i64;
  v6 = edgeFaces->m_data;
  while ( 1 )
  {
    v7 = ++v4;
    if ( v4 < v5 )
      break;
LABEL_9:
    ++v6;
    if ( v4 >= v5 )
      return 0i64;
  }
  v8 = v6 + 1;
  while ( ((forwardFaces->m_storage.m_words.m_data[(signed __int64)*v6 >> 5] >> (*v6 & 0x1F)) & 1) == ((forwardFaces->m_storage.m_words.m_data[(signed __int64)*v8 >> 5] >> (*v8 & 0x1F)) & 1) )
  {
    ++v7;
    ++v8;
    if ( v7 >= v5 )
      goto LABEL_9;
  }
  return 1i64;
}

// File Line: 107
// RVA: 0xB9D8E0
hkResult *__fastcall hkaiGeometryExtrudeUtil::silhouetteExtrudeDeprecated(hkResult *result, hkaiEdgeGeometry *geom, hkVector4f *extrudeDirection, hkaiEdgeGeometry *geomOut)
{
  hkResult *v4; // rbp
  hkaiEdgeGeometry *v5; // rbx
  hkVector4f *v6; // rdi
  hkaiEdgeGeometry *v7; // rsi
  hkaiGeometryExtrudeUtil v9; // [rsp+30h] [rbp-C8h]

  v4 = result;
  v5 = geomOut;
  v6 = extrudeDirection;
  v7 = geom;
  hkaiGeometryExtrudeUtil::hkaiGeometryExtrudeUtil(&v9);
  hkaiGeometryExtrudeUtil::silhouetteExtrudeImpl(&v9, v4, v7, v6, v5);
  hkaiGeometryExtrudeUtil::~hkaiGeometryExtrudeUtil(&v9);
  return v4;
}

// File Line: 113
// RVA: 0xB9D960
hkResult *__fastcall hkaiGeometryExtrudeUtil::silhouetteExtrudeImplDeprecated(hkaiGeometryExtrudeUtil *this, hkResult *result, hkaiEdgeGeometry *geom, hkVector4f *extrudeDirection, hkaiEdgeGeometry *geomOut)
{
  hkaiGeometryExtrudeUtil *v5; // rbx
  hkaiEdgeGeometry *v6; // rsi
  hkResult *v7; // r14
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // rdi
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  int v13; // eax
  int v14; // esi
  hkaiUniqueEdges *v15; // r13
  signed __int64 v16; // r12
  int v17; // er8
  hkaiGeometryExtrudeUtil::IndexMap *v18; // r15
  hkaiGeometryExtrudeUtil::IndexMap *v19; // rdi
  hkaiEdgeGeometry *v20; // r8
  int v21; // eax
  int v22; // ecx
  hkArray<int,hkContainerHeapAllocator> *v23; // rbx
  int v24; // eax
  int v25; // eax
  int v26; // er9
  _DWORD *v27; // rdi
  __int64 i; // rcx
  int v29; // er8
  hkaiGeometryExtrudeUtil::IndexMap *v30; // rsi
  __int64 v31; // r12
  signed __int64 v32; // rbx
  signed int v33; // er14
  signed int v34; // er15
  hkaiGeometryExtrudeUtil::IndexMap *v35; // r13
  hkaiEdgeGeometry::Edge *const **v36; // rax
  int **v37; // rdi
  int **v38; // rsi
  __m128 v39; // xmm2
  int *v40; // rax
  hkResultEnum v41; // edx
  hkaiGeometryExtrudeUtil::IndexMap *v42; // r12
  hkResult *v43; // rbx
  _QWORD *v44; // rsi
  unsigned __int64 v45; // rdi
  unsigned __int64 v46; // rax
  hkaiGeometryExtrudeUtil *v48; // rcx
  hkArray<int,hkContainerHeapAllocator> *v49; // r13
  int v50; // eax
  int v51; // edi
  int v52; // eax
  int v53; // eax
  int v54; // er9
  int v55; // er8
  int v56; // edx
  __int64 v57; // r15
  signed int *v58; // r14
  hkaiEdgeGeometry::Edge *const **v59; // rax
  int **v60; // rbx
  int **v61; // r12
  int v62; // eax
  signed __int64 v63; // rcx
  int v64; // eax
  int **j; // r8
  __int64 v66; // r9
  int v67; // edx
  int v68; // esi
  __int64 v69; // rcx
  signed int *v70; // rax
  signed int v71; // eax
  __int64 v72; // rbx
  __int64 v73; // r8
  signed int *v74; // r11
  __int64 v75; // rsi
  signed int *v76; // rdi
  int *v77; // rdi
  int v78; // er8
  hkaiEdgeGeometry *v79; // rbx
  int v80; // er14
  int v81; // esi
  int v82; // eax
  __int32 v83; // er12
  hkArray<hkVector4f,hkContainerHeapAllocator> *v84; // r13
  int v85; // esi
  int v86; // edi
  int v87; // eax
  int v88; // eax
  int v89; // er9
  int v90; // eax
  int v91; // eax
  int v92; // er9
  int v93; // eax
  int v94; // eax
  hkResultEnum v95; // eax
  hkaiEdgeGeometry *v96; // rdi
  hkaiEdgeGeometry *v97; // r13
  int v98; // eax
  __int64 v99; // rax
  hkaiEdgeGeometry::Face *v100; // rcx
  hkaiEdgeGeometry::Face *v101; // rdi
  __int64 v102; // rdx
  signed __int64 v103; // rdi
  unsigned int v104; // eax
  int v105; // eax
  int v106; // eax
  int v107; // eax
  int v108; // er9
  __int64 v109; // rdx
  signed __int64 v110; // rsi
  int v111; // eax
  _DWORD *v112; // rdi
  unsigned __int64 k; // rcx
  __int64 v114; // r8
  hkResultEnum v115; // er9
  __int64 v116; // rsi
  signed int *v117; // rdi
  bool v118; // zf
  __int64 v119; // rdx
  __int64 v120; // rcx
  hkaiEdgeGeometry::Edge *v121; // rdx
  __int64 v122; // rdx
  hkaiEdgeGeometry::Edge *v123; // rdx
  int v124; // eax
  __int64 v125; // r13
  __int64 v126; // r10
  int v127; // er11
  _QWORD *v128; // r12
  int v129; // er9
  unsigned int v130; // er9
  signed int *v131; // rdx
  int *v132; // rcx
  signed __int64 v133; // rdi
  int v134; // er8
  signed __int64 v135; // rdx
  int v136; // esi
  int *v137; // rcx
  __int64 v138; // rcx
  signed __int64 v139; // rax
  unsigned int v140; // ecx
  _QWORD *v141; // rsi
  unsigned __int64 v142; // rdi
  unsigned __int64 v143; // rax
  hkResult resulta; // [rsp+30h] [rbp-71h]
  hkResult v145; // [rsp+34h] [rbp-6Dh]
  hkResult v146; // [rsp+38h] [rbp-69h]
  hkResult v147; // [rsp+3Ch] [rbp-65h]
  int numBits; // [rsp+40h] [rbp-61h]
  hkArray<int,hkContainerHeapAllocator> *v149; // [rsp+48h] [rbp-59h]
  hkaiGeometryExtrudeUtil::IndexMap *v150; // [rsp+50h] [rbp-51h]
  int v151; // [rsp+58h] [rbp-49h]
  hkaiUniqueEdges *v152; // [rsp+60h] [rbp-41h]
  __int64 v153; // [rsp+68h] [rbp-39h]
  hkaiGeometryExtrudeUtil::IndexMap *indexMap; // [rsp+70h] [rbp-31h]
  int v155; // [rsp+78h] [rbp-29h]
  hkBitField *v156; // [rsp+80h] [rbp-21h]
  hkVector4f normalOut; // [rsp+90h] [rbp-11h]
  hkaiGeometryExtrudeUtil *v158; // [rsp+100h] [rbp+5Fh]
  hkResult *v159; // [rsp+108h] [rbp+67h]
  hkaiEdgeGeometry *geoma; // [rsp+110h] [rbp+6Fh]
  hkVector4f *offset; // [rsp+118h] [rbp+77h]

  offset = extrudeDirection;
  geoma = geom;
  v159 = result;
  v158 = this;
  v5 = this;
  v6 = geom;
  v7 = result;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtsilhouetteExtrudeDeprecated";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v151 = v6->m_edges.m_size;
  v13 = v6->m_faces.m_size;
  v14 = v6->m_vertices.m_size;
  numBits = v13;
  hkaiFaceEdges::clear(&v5->m_faceEdges);
  v15 = &v5->m_uniqueEdges;
  v152 = &v5->m_uniqueEdges;
  hkaiUniqueEdges::clear(&v5->m_uniqueEdges);
  v16 = (signed __int64)&v5->m_forwardFaces;
  *(_DWORD *)(v16 + 16) = 0;
  v17 = v5->m_forwardFaces.m_storage.m_words.m_capacityAndFlags;
  v156 = &v5->m_forwardFaces;
  *(_DWORD *)(v16 + 8) = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)v16,
      4 * v17);
  v18 = &v5->m_frontVertexMap;
  *(_QWORD *)v16 = 0i64;
  v5->m_forwardFaces.m_storage.m_words.m_capacityAndFlags = 2147483648;
  v5->m_backFaceMap.m_size = 0;
  indexMap = &v5->m_frontVertexMap;
  hkaiGeometryExtrudeUtil::IndexMap::clear(&v5->m_frontVertexMap);
  v19 = &v5->m_backVertexMap;
  v150 = &v5->m_backVertexMap;
  hkaiGeometryExtrudeUtil::IndexMap::clear(&v5->m_backVertexMap);
  v20 = geoma;
  v5->m_edgeToSideFaceMap.m_size = 0;
  v5->m_edgeFaces.m_size = 0;
  hkaiFaceEdges::setGeometry(&v5->m_faceEdges, &resulta, v20);
  if ( resulta.m_enum == 1 )
    goto LABEL_124;
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::trySetSize(
    (hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > *)&v5->m_forwardFaces.m_storage,
    &resulta,
    0,
    numBits,
    0);
  if ( resulta.m_enum )
    goto LABEL_124;
  v21 = v5->m_backFaceMap.m_capacityAndFlags;
  v22 = numBits;
  v23 = &v5->m_backFaceMap;
  v24 = v21 & 0x3FFFFFFF;
  v149 = v23;
  if ( v24 < numBits )
  {
    v25 = 2 * v24;
    v26 = numBits;
    if ( numBits < v25 )
      v26 = v25;
    hkArrayUtil::_reserve(&v147, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v23, v26, 4);
    v22 = numBits;
  }
  v23->m_size = v22;
  hkaiGeometryExtrudeUtil::IndexMap::init(v18, &resulta, v14);
  if ( resulta.m_enum
    || (hkaiGeometryExtrudeUtil::IndexMap::init(v19, &resulta, v14), resulta.m_enum)
    || (v27 = *(_DWORD **)v16) == 0i64
    || (v23->m_capacityAndFlags & 0x3FFFFFFF) > 0 && !v23->m_data )
  {
LABEL_124:
    v140 = hkMonitorStream__m_instance.m_slotID;
    v7->m_enum = 1;
    v141 = TlsGetValue(v140);
    v142 = v141[1];
    if ( v142 < v141[3] )
    {
      v143 = __rdtsc();
      *(_DWORD *)(v142 + 8) = v143;
      *(_QWORD *)v142 = "Et";
      v141[1] = v142 + 16;
    }
    return v7;
  }
  if ( *(_DWORD *)(v16 + 8) - 1 >= 0 )
  {
    for ( i = *(unsigned int *)(v16 + 8); i; --i )
    {
      *v27 = 0;
      ++v27;
    }
  }
  hkaiGeometryExtrudeUtil::IndexMap::init(v18, &v147, v14);
  v29 = v14;
  v30 = v150;
  hkaiGeometryExtrudeUtil::IndexMap::init(v150, &v147, v29);
  v31 = numBits;
  v32 = 1i64;
  v146.m_enum = 0;
  v145.m_enum = 0;
  v153 = numBits;
  v33 = 2;
  v34 = 1;
  if ( numBits > 1i64 )
  {
    v35 = v30;
    do
    {
      v36 = v158->m_faceEdges.m_faceStartEdges.m_data;
      v37 = (int **)v36[v32];
      v38 = (int **)v36[v32 + 1];
      hkaiEdgeGeometry::calculateFaceNormal(geoma, v36[v32], v36[v32 + 1], &normalOut);
      v39 = _mm_mul_ps(normalOut.m_quad, offset->m_quad);
      v40 = v149->m_data;
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 170))) > 0.0 )
      {
        for ( v40[v32] = -1; v37 != v38; ++v37 )
        {
          hkaiGeometryExtrudeUtil::IndexMap::add(v35, **v37);
          hkaiGeometryExtrudeUtil::IndexMap::add(v35, (*v37)[1]);
        }
      }
      else
      {
        v41 = v146.m_enum;
        v40[v32] = v146.m_enum;
        v156->m_storage.m_words.m_data[(signed __int64)v34 >> 5] |= v33;
        v146.m_enum = v41 + 1;
        v145.m_enum += (unsigned int)(v38 - v37);
        if ( v37 != v38 )
        {
          v42 = indexMap;
          do
          {
            hkaiGeometryExtrudeUtil::IndexMap::add(v42, **v37);
            hkaiGeometryExtrudeUtil::IndexMap::add(v42, (*v37)[1]);
            hkaiGeometryExtrudeUtil::IndexMap::add(v35, **v37);
            hkaiGeometryExtrudeUtil::IndexMap::add(v35, (*v37)[1]);
            ++v37;
          }
          while ( v37 != v38 );
          v31 = v153;
        }
      }
      v33 = __ROL4__(v33, 1);
      ++v32;
      ++v34;
    }
    while ( v32 < v31 );
    v15 = v152;
    v30 = v150;
  }
  hkaiUniqueEdges::setGeometry(v15, &resulta, geoma);
  if ( resulta.m_enum == 1 )
    goto LABEL_32;
  v48 = v158;
  v49 = &v158->m_edgeToSideFaceMap;
  v50 = v158->m_edgeToSideFaceMap.m_capacityAndFlags;
  v51 = v158->m_uniqueEdges.m_startUniqueEdge.m_size - 1;
  normalOut.m_quad.m128_u64[0] = (unsigned __int64)&v158->m_edgeToSideFaceMap;
  v52 = v50 & 0x3FFFFFFF;
  v147.m_enum = v51;
  if ( v52 < v51 )
  {
    v53 = 2 * v52;
    v54 = v51;
    if ( v51 < v53 )
      v54 = v53;
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v158->m_edgeToSideFaceMap,
      v54,
      4);
    v48 = v158;
  }
  v158->m_edgeToSideFaceMap.m_size = v51;
  if ( (v158->m_edgeToSideFaceMap.m_capacityAndFlags & 0x3FFFFFFF) > 0 && !v49->m_data )
  {
LABEL_32:
    v43 = v159;
    v159->m_enum = 1;
    goto LABEL_33;
  }
  v55 = 0;
  v56 = 0;
  v57 = 0i64;
  LODWORD(v152) = 0;
  LODWORD(v149) = 0;
  v153 = v51;
  if ( v51 <= 0 )
    goto LABEL_72;
  v58 = (signed int *)&v48->m_edgeFaces;
  while ( 1 )
  {
    v59 = v48->m_uniqueEdges.m_startUniqueEdge.m_data;
    v48->m_edgeFaces.m_size = 0;
    v60 = (int **)v59[v57 + 1];
    v61 = (int **)v59[v57];
    v62 = v58[3] & 0x3FFFFFFF;
    v63 = v60 - v61;
    if ( v62 >= (signed int)v63 )
    {
      resulta.m_enum = 0;
    }
    else
    {
      v64 = 2 * v62;
      if ( (signed int)v63 < v64 )
        LODWORD(v63) = v64;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v58, v63, 4);
      if ( resulta.m_enum )
        goto LABEL_32;
    }
    for ( j = v61; j != v60; ++j )
    {
      v66 = v58[2];
      v67 = 0;
      v68 = (*j)[2];
      v69 = 0i64;
      if ( (signed int)v66 > 0 )
      {
        v70 = *(signed int **)v58;
        while ( *v70 != v68 )
        {
          ++v69;
          ++v67;
          ++v70;
          if ( v69 >= v66 )
            goto LABEL_57;
        }
        if ( v67 >= 0 )
          continue;
      }
LABEL_57:
      *(_DWORD *)(*(_QWORD *)v58 + 4 * v66) = v68;
      ++v58[2];
    }
    v71 = v58[2];
    if ( v71 > 1 )
    {
      v72 = 0i64;
      v73 = v58[2];
      if ( v71 <= 0 )
      {
LABEL_67:
        v30 = v150;
        v55 = (signed int)v152;
        v56 = (_DWORD)v149 + 1;
        v49->m_data[v57] = -1;
        LODWORD(v149) = v56;
        goto LABEL_69;
      }
      v74 = *(signed int **)v58;
      while ( 1 )
      {
        v75 = ++v72;
        if ( v72 < v73 )
          break;
LABEL_66:
        ++v74;
        if ( v72 >= v73 )
          goto LABEL_67;
      }
      v76 = v74 + 1;
      while ( ((v156->m_storage.m_words.m_data[(signed __int64)*v74 >> 5] >> (*v74 & 0x1F)) & 1) == ((v156->m_storage.m_words.m_data[(signed __int64)*v76 >> 5] >> (*v76 & 0x1F)) & 1) )
      {
        ++v75;
        ++v76;
        if ( v75 >= v73 )
          goto LABEL_66;
      }
    }
    v77 = *v61;
    hkaiGeometryExtrudeUtil::IndexMap::add(indexMap, **v61);
    hkaiGeometryExtrudeUtil::IndexMap::add(indexMap, v77[1]);
    v30 = v150;
    hkaiGeometryExtrudeUtil::IndexMap::add(v150, *v77);
    hkaiGeometryExtrudeUtil::IndexMap::add(v30, v77[1]);
    v78 = (signed int)v152;
    v56 = (signed int)v149;
    v49->m_data[v57] = (signed int)v152;
    v55 = v78 + 1;
    LODWORD(v152) = v55;
LABEL_69:
    if ( ++v57 >= v153 )
      break;
    v48 = v158;
  }
  v51 = v147.m_enum;
LABEL_72:
  v79 = geomOut;
  v80 = indexMap->m_freeIndex;
  v81 = v30->m_freeIndex;
  v82 = geoma->m_faces.m_size;
  v83 = numBits + v55 + v146.m_enum;
  LODWORD(v149) = v82;
  v147.m_enum = v55 + v82;
  v84 = &geomOut->m_vertices;
  v85 = v80 + v81;
  v86 = v151 + v145.m_enum + 4 * (v51 - v56);
  v87 = geomOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v87 >= v85 )
  {
    v145.m_enum = 0;
    goto LABEL_78;
  }
  v88 = 2 * v87;
  v89 = v85;
  if ( v85 < v88 )
    v89 = v88;
  hkArrayUtil::_reserve(
    &v145,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    &geomOut->m_vertices,
    v89,
    16);
  if ( v145.m_enum == HK_SUCCESS )
LABEL_78:
    v84->m_size = v85;
  v90 = v79->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v90 >= v83 )
  {
    v146.m_enum = 0;
  }
  else
  {
    v91 = 2 * v90;
    v92 = v83;
    if ( v83 < v91 )
      v92 = v91;
    hkArrayUtil::_reserve(&v146, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v79->m_faces, v92, 12);
  }
  v93 = v79->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v93 >= v86 )
  {
    v95 = 0;
    resulta.m_enum = 0;
  }
  else
  {
    v94 = 2 * v93;
    if ( v86 < v94 )
      v86 = v94;
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v79->m_edges,
      v86,
      16);
    v95 = resulta.m_enum;
  }
  if ( v145.m_enum == 1 || v146.m_enum == 1 || v95 == 1 )
    goto LABEL_32;
  v96 = geoma;
  hkaiGeometryExtrudeUtil_copyVertices(&geoma->m_vertices, indexMap, 0, &aabbOut, v84);
  hkaiGeometryExtrudeUtil_copyVertices(&v96->m_vertices, v150, v80, offset, v84);
  v97 = v96;
  v98 = v79->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v98 < v96->m_faces.m_size )
  {
    if ( v79->m_faces.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v79->m_faces.m_data,
        12 * v98);
    LODWORD(geoma) = 12 * v96->m_faces.m_size;
    v79->m_faces.m_data = (hkaiEdgeGeometry::Face *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                      (int *)&geoma);
    v79->m_faces.m_capacityAndFlags = (signed int)geoma / 12;
  }
  v99 = v96->m_faces.m_size;
  v100 = v79->m_faces.m_data;
  v79->m_faces.m_size = v99;
  v101 = v96->m_faces.m_data;
  v102 = v99;
  if ( (signed int)v99 > 0 )
  {
    v103 = (char *)v101 - (char *)v100;
    do
    {
      v104 = *(unsigned int *)((char *)&v100->m_data + v103);
      ++v100;
      v100[-1].m_data = v104;
      v100[-1].m_faceIndex = *(_DWORD *)((char *)v100 + v103 - 8);
      *(_DWORD *)&v100[-1].m_flags.m_storage = *(_DWORD *)((char *)v100 + v103 - 4);
      --v102;
    }
    while ( v102 );
  }
  v105 = v79->m_faces.m_capacityAndFlags;
  LOBYTE(v155) = 8;
  v106 = v105 & 0x3FFFFFFF;
  if ( v106 < v83 )
  {
    v107 = 2 * v106;
    v108 = v83;
    if ( v83 < v107 )
      v108 = v107;
    hkArrayUtil::_reserve(
      (hkResult *)&geoma,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v79->m_faces,
      v108,
      12);
  }
  v109 = v79->m_faces.m_size;
  v110 = (signed __int64)&v79->m_faces.m_data[v109];
  if ( v83 - (signed int)v109 > 0 )
  {
    v111 = v155;
    *(_QWORD *)v110 = 0i64;
    v112 = (_DWORD *)(v110 + 12);
    *(_DWORD *)(v110 + 8) = v111;
    for ( k = (unsigned __int64)(12i64 * (v83 - (signed int)v109) - 12) >> 2; k; --k )
    {
      *v112 = *(_DWORD *)v110;
      v110 += 4i64;
      ++v112;
    }
  }
  v114 = v151;
  v79->m_faces.m_size = v83;
  if ( v114 > 0 )
  {
    v115 = v147.m_enum;
    v116 = 0i64;
    do
    {
      v117 = (signed int *)&v97->m_edges.m_data[v116];
      v118 = ((v156->m_storage.m_words.m_data[(signed __int64)v117[2] >> 5] >> (v117[2] & 0x1F)) & 1) == 0;
      v119 = v79->m_edges.m_size++;
      v120 = *v117;
      if ( v118 )
      {
        v123 = &v79->m_edges.m_data[v119];
        v123->m_a = v80 + v158->m_backVertexMap.m_map.m_data[v120];
        v123->m_b = v80 + v158->m_backVertexMap.m_map.m_data[v117[1]];
        v124 = v117[2];
      }
      else
      {
        v121 = &v79->m_edges.m_data[v119];
        v121->m_a = v158->m_frontVertexMap.m_map.m_data[v120];
        v121->m_b = v158->m_frontVertexMap.m_map.m_data[v117[1]];
        v121->m_face = v117[2];
        v121->m_data = v117[3];
        v122 = v79->m_edges.m_size++;
        v123 = &v79->m_edges.m_data[v122];
        v123->m_a = v80 + v158->m_backVertexMap.m_map.m_data[*v117];
        v123->m_b = v80 + v158->m_backVertexMap.m_map.m_data[v117[1]];
        v124 = v115 + v158->m_backFaceMap.m_data[v117[2]];
      }
      v123->m_face = v124;
      ++v116;
      v123->m_data = v117[3];
      --v114;
    }
    while ( v114 );
  }
  v125 = v153;
  v126 = 0i64;
  if ( v153 > 0 )
  {
    v127 = (signed int)v149;
    v128 = (_QWORD *)normalOut.m_quad.m128_u64[0];
    do
    {
      v129 = *(_DWORD *)(*v128 + 4 * v126);
      if ( v129 >= 0 )
      {
        v130 = v127 + v129;
        v131 = (signed int *)*v158->m_uniqueEdges.m_startUniqueEdge.m_data[v126];
        v132 = v158->m_frontVertexMap.m_map.m_data;
        v133 = 4i64 * *v131;
        v134 = *(int *)((char *)v132 + v133);
        v135 = 4i64 * v131[1];
        v136 = *(int *)((char *)v132 + v135);
        v137 = v158->m_backVertexMap.m_map.m_data;
        LODWORD(v133) = *(int *)((char *)v137 + v133);
        LODWORD(v135) = *(int *)((char *)v137 + v135);
        v138 = v79->m_edges.m_size;
        LODWORD(v133) = v80 + v133;
        LODWORD(v135) = v80 + v135;
        v79->m_edges.m_size = v138 + 4;
        v139 = (signed __int64)&v79->m_edges.m_data[v138];
        *(_DWORD *)v139 = v134;
        *(_DWORD *)(v139 + 4) = v136;
        *(_QWORD *)(v139 + 8) = v130;
        *(_DWORD *)(v139 + 16) = v136;
        *(_DWORD *)(v139 + 20) = v135;
        *(_QWORD *)(v139 + 24) = v130;
        *(_DWORD *)(v139 + 32) = v135;
        *(_DWORD *)(v139 + 36) = v133;
        *(_QWORD *)(v139 + 40) = v130;
        *(_DWORD *)(v139 + 48) = v133;
        *(_DWORD *)(v139 + 52) = v134;
        *(_QWORD *)(v139 + 56) = v130;
      }
      ++v126;
    }
    while ( v126 < v125 );
  }
  v43 = v159;
  v159->m_enum = 0;
LABEL_33:
  v44 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v45 = v44[1];
  if ( v45 < v44[3] )
  {
    *(_QWORD *)v45 = "Et";
    v46 = __rdtsc();
    *(_DWORD *)(v45 + 8) = v46;
    v44[1] = v45 + 16;
  }
  return v43;
}WORD *)v45 = "Et";
    v46 = __rdtsc();
    *(_DWORD *)(v45 + 8) = v46;
    v44[1] = v45 + 16;
  }
  return v43;
}

// File Line: 444
// RVA: 0xB9E430
hkResult *__fastcall hkaiGeometryExtrudeUtil::silhouetteExtrudeImpl(hkaiGeometryExtrudeUtil *this, hkResult *result, hkaiEdgeGeometry *geom, hkVector4f *extrudeDirection, hkaiEdgeGeometry *geomOut)
{
  hkaiGeometryExtrudeUtil *v5; // rbx
  hkaiEdgeGeometry *v6; // rsi
  hkResult *v7; // r12
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // rdi
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  signed __int64 v13; // r14
  int v14; // eax
  hkaiUniqueEdges *v15; // r15
  signed __int64 v16; // r13
  int v17; // er8
  unsigned int v18; // ecx
  _QWORD *v19; // rsi
  unsigned __int64 v20; // rdi
  unsigned __int64 v21; // rax
  _DWORD *v23; // rdi
  __int64 i; // rcx
  signed int v25; // ebx
  signed __int64 v26; // rsi
  signed int v27; // edi
  hkaiEdgeGeometry *v28; // r12
  __m128 v29; // xmm2
  hkaiGeometryExtrudeUtil *v30; // rcx
  int v31; // edi
  int v32; // eax
  int v33; // eax
  int v34; // er9
  int v35; // edx
  int v36; // esi
  __int64 v37; // r12
  signed int *v38; // r15
  hkaiEdgeGeometry::Edge *const **v39; // rax
  hkaiEdgeGeometry::Edge *const *v40; // r14
  hkaiEdgeGeometry::Edge *const *v41; // rbx
  int v42; // eax
  __int64 v43; // rcx
  int v44; // eax
  hkResult *v45; // rbx
  _QWORD *v46; // rsi
  unsigned __int64 v47; // rdi
  unsigned __int64 v48; // rax
  __int64 v49; // r8
  int v50; // edx
  unsigned int v51; // esi
  __int64 v52; // rcx
  signed int *v53; // rax
  signed int v54; // eax
  __int64 v55; // rbx
  __int64 v56; // r8
  signed int *v57; // r10
  __int64 v58; // rsi
  signed int *v59; // rdi
  int *v60; // rax
  hkResultEnum v61; // edx
  hkaiEdgeGeometry *v62; // r13
  hkaiEdgeGeometry *v63; // rbx
  int v64; // er9
  int v65; // er12
  int v66; // esi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v67; // rdi
  int v68; // eax
  __int32 v69; // er15
  int v70; // esi
  int v71; // eax
  signed __int64 v72; // r14
  int v73; // eax
  int v74; // eax
  int v75; // er9
  int v76; // eax
  hkArray<hkaiEdgeGeometry::Edge,hkContainerHeapAllocator> *v77; // rbx
  int v78; // eax
  int v79; // eax
  int v80; // eax
  __int64 v81; // rax
  char *v82; // rcx
  __int64 v83; // rdx
  signed __int64 v84; // rsi
  __int128 v85; // xmm0
  int v86; // er8
  hkVector4f *v87; // r12
  __int64 v88; // rsi
  __int64 v89; // rdx
  hkVector4f *v90; // rcx
  int v91; // eax
  __int64 v92; // rax
  char *v93; // rcx
  __int64 v94; // rdx
  signed __int64 v95; // rdi
  int v96; // eax
  int v97; // eax
  int v98; // eax
  int v99; // eax
  int v100; // er9
  __int64 v101; // rdx
  signed __int64 v102; // rsi
  float v103; // eax
  _DWORD *v104; // rdi
  unsigned __int64 j; // rcx
  __int64 v106; // r15
  __int64 v107; // r14
  __int64 v108; // rsi
  int v109; // er9
  int v110; // eax
  hkaiEdgeGeometry::Edge *v111; // rdi
  int v112; // eax
  hkaiEdgeGeometry::Edge *v113; // rcx
  __int64 v114; // rsi
  int v115; // er9
  int v116; // eax
  int v117; // eax
  int v118; // er8
  hkaiEdgeGeometry::Edge *v119; // rdx
  __int64 v120; // rdx
  __int64 v121; // rsi
  hkaiGeometryExtrudeUtil *v122; // rcx
  int v123; // edi
  __int32 v124; // edi
  hkaiEdgeGeometry::Edge *const *v125; // rcx
  unsigned int v126; // er14
  unsigned int v127; // er15
  int v128; // er9
  int v129; // eax
  int v130; // er12
  int v131; // er13
  int v132; // eax
  hkaiEdgeGeometry::Edge *v133; // rax
  hkResult resulta; // [rsp+30h] [rbp-41h]
  int v135; // [rsp+34h] [rbp-3Dh]
  hkResult v136; // [rsp+38h] [rbp-39h]
  hkResult v137; // [rsp+3Ch] [rbp-35h]
  hkResult v138; // [rsp+40h] [rbp-31h]
  int v139; // [rsp+44h] [rbp-2Dh]
  int v140; // [rsp+48h] [rbp-29h]
  __int64 v141; // [rsp+50h] [rbp-21h]
  hkResult v142; // [rsp+58h] [rbp-19h]
  hkVector4f normalOut; // [rsp+60h] [rbp-11h]
  hkaiGeometryExtrudeUtil *v144; // [rsp+D0h] [rbp+5Fh]
  hkResult *v145; // [rsp+D8h] [rbp+67h]
  hkaiEdgeGeometry *geoma; // [rsp+E0h] [rbp+6Fh]
  hkVector4f *v147; // [rsp+E8h] [rbp+77h]

  v147 = extrudeDirection;
  geoma = geom;
  v145 = result;
  v144 = this;
  v5 = this;
  v6 = geom;
  v7 = result;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtsilhouetteExtrude";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = v6->m_faces.m_size;
  v140 = v6->m_edges.m_size;
  v14 = v6->m_vertices.m_size;
  v138.m_enum = (signed int)v13;
  v139 = v14;
  hkaiFaceEdges::clear(&v5->m_faceEdges);
  v15 = &v5->m_uniqueEdges;
  v141 = (__int64)&v5->m_uniqueEdges;
  hkaiUniqueEdges::clear(&v5->m_uniqueEdges);
  v16 = (signed __int64)&v5->m_forwardFaces;
  *(_DWORD *)(v16 + 16) = 0;
  v17 = v5->m_forwardFaces.m_storage.m_words.m_capacityAndFlags;
  *(_DWORD *)(v16 + 8) = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)v16,
      4 * v17);
  *(_QWORD *)v16 = 0i64;
  v5->m_forwardFaces.m_storage.m_words.m_capacityAndFlags = 2147483648;
  v5->m_edgeToSideFaceMap.m_size = 0;
  v5->m_edgeFaces.m_size = 0;
  hkaiFaceEdges::setGeometry(&v5->m_faceEdges, &resulta, v6);
  if ( resulta.m_enum == 1 )
    goto LABEL_135;
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::trySetSize(
    (hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > *)&v5->m_forwardFaces.m_storage,
    &resulta,
    0,
    v13,
    0);
  if ( resulta.m_enum )
    goto LABEL_135;
  v23 = *(_DWORD **)v16;
  if ( !*(_QWORD *)v16 )
    goto LABEL_135;
  if ( v5->m_forwardFaces.m_storage.m_words.m_size - 1 >= 0 )
  {
    for ( i = (unsigned int)v5->m_forwardFaces.m_storage.m_words.m_size; i; --i )
    {
      *v23 = 0;
      ++v23;
    }
  }
  v25 = 1;
  v26 = 1i64;
  v27 = 2;
  if ( v13 > 1 )
  {
    v28 = geoma;
    do
    {
      hkaiEdgeGeometry::calculateFaceNormal(
        v28,
        v144->m_faceEdges.m_faceStartEdges.m_data[v26],
        v144->m_faceEdges.m_faceStartEdges.m_data[v26 + 1],
        &normalOut);
      v29 = _mm_mul_ps(normalOut.m_quad, v147->m_quad);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 170))) <= 0.0 )
        *(_DWORD *)(*(_QWORD *)v16 + 4 * ((signed __int64)v25 >> 5)) |= v27;
      v27 = __ROL4__(v27, 1);
      ++v26;
      ++v25;
    }
    while ( v26 < v13 );
    v15 = (hkaiUniqueEdges *)v141;
    v7 = v145;
  }
  hkaiUniqueEdges::setGeometry(v15, &resulta, geoma);
  if ( resulta.m_enum == 1 )
    goto LABEL_135;
  v30 = v144;
  v31 = v144->m_uniqueEdges.m_startUniqueEdge.m_size - 1;
  v32 = v144->m_edgeToSideFaceMap.m_capacityAndFlags & 0x3FFFFFFF;
  v136.m_enum = v31;
  if ( v32 < v31 )
  {
    v33 = 2 * v32;
    v34 = v31;
    if ( v31 < v33 )
      v34 = v33;
    hkArrayUtil::_reserve(
      &v142,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v144->m_edgeToSideFaceMap,
      v34,
      4);
    v30 = v144;
  }
  v144->m_edgeToSideFaceMap.m_size = v31;
  if ( (v144->m_edgeToSideFaceMap.m_capacityAndFlags & 0x3FFFFFFF) > 0 && !v144->m_edgeToSideFaceMap.m_data )
  {
LABEL_135:
    v18 = hkMonitorStream__m_instance.m_slotID;
    v7->m_enum = 1;
    v19 = TlsGetValue(v18);
    v20 = v19[1];
    if ( v20 < v19[3] )
    {
      *(_QWORD *)v20 = "Et";
      v21 = __rdtsc();
      *(_DWORD *)(v20 + 8) = v21;
      v19[1] = v20 + 16;
    }
    return v7;
  }
  v35 = 0;
  v36 = 0;
  v37 = 0i64;
  v137.m_enum = 0;
  v135 = 0;
  v141 = v31;
  if ( v31 <= 0 )
    goto LABEL_63;
  v38 = (signed int *)&v30->m_edgeFaces;
  do
  {
    v39 = v30->m_uniqueEdges.m_startUniqueEdge.m_data;
    v30->m_edgeFaces.m_size = 0;
    v40 = v39[v37 + 1];
    v41 = v39[v37];
    v42 = v38[3] & 0x3FFFFFFF;
    v43 = v40 - v41;
    if ( v42 >= (signed int)v43 )
    {
      resulta.m_enum = 0;
    }
    else
    {
      v44 = 2 * v42;
      if ( (signed int)v43 < v44 )
        LODWORD(v43) = v44;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v38, v43, 4);
      if ( resulta.m_enum )
        goto LABEL_34;
    }
    if ( v41 != v40 )
    {
      do
      {
        v49 = v38[2];
        v50 = 0;
        v51 = (*v41)->m_face;
        v52 = 0i64;
        if ( (signed int)v49 <= 0 )
          goto LABEL_47;
        v53 = *(signed int **)v38;
        while ( *v53 != v51 )
        {
          ++v52;
          ++v50;
          ++v53;
          if ( v52 >= v49 )
            goto LABEL_47;
        }
        if ( v50 < 0 )
        {
LABEL_47:
          *(_DWORD *)(*(_QWORD *)v38 + 4 * v49) = v51;
          ++v38[2];
        }
        ++v41;
      }
      while ( v41 != v40 );
      v36 = v135;
    }
    v54 = v38[2];
    if ( v54 > 1 )
    {
      v55 = 0i64;
      v56 = v38[2];
      if ( v54 <= 0 )
      {
LABEL_59:
        v30 = v144;
        v35 = v137.m_enum;
        ++v36;
        v60 = v144->m_edgeToSideFaceMap.m_data;
        v135 = v36;
        v60[v37] = -1;
        goto LABEL_61;
      }
      v57 = *(signed int **)v38;
      while ( 1 )
      {
        v58 = ++v55;
        if ( v55 < v56 )
          break;
LABEL_57:
        ++v57;
        if ( v55 >= v56 )
        {
          v36 = v135;
          goto LABEL_59;
        }
      }
      v59 = v57 + 1;
      while ( ((*(_DWORD *)(*(_QWORD *)v16 + 4 * ((signed __int64)*v57 >> 5)) >> (*v57 & 0x1F)) & 1) == ((*(_DWORD *)(*(_QWORD *)v16 + 4 * ((signed __int64)*v59 >> 5)) >> (*v59 & 0x1F)) & 1) )
      {
        ++v58;
        ++v59;
        if ( v58 >= v56 )
          goto LABEL_57;
      }
    }
    v61 = v137.m_enum;
    v30 = v144;
    v36 = v135;
    v144->m_edgeToSideFaceMap.m_data[v37] = v137.m_enum;
    v35 = v61 + 1;
    v137.m_enum = v35;
LABEL_61:
    ++v37;
  }
  while ( v37 < v141 );
  v31 = v136.m_enum;
LABEL_63:
  v62 = geoma;
  v63 = geomOut;
  v64 = 2 * v139;
  v65 = geoma->m_faces.m_size + v35;
  v142.m_enum = geoma->m_faces.m_size;
  v136.m_enum = v65;
  v66 = v140 + 2 * (v31 - v36);
  v67 = &geomOut->m_vertices;
  v68 = geomOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  v69 = v35 + 2 * v138.m_enum - 1;
  v70 = 2 * v66;
  if ( v68 >= 2 * v139 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v71 = 2 * v68;
    if ( v64 < v71 )
      v64 = v71;
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &geomOut->m_vertices,
      v64,
      16);
  }
  v72 = (signed __int64)&v63->m_faces;
  v73 = v63->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v73 >= v69 )
  {
    v137.m_enum = 0;
  }
  else
  {
    v74 = 2 * v73;
    v75 = v69;
    if ( v69 < v74 )
      v75 = v74;
    hkArrayUtil::_reserve(&v137, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v63->m_faces, v75, 12);
  }
  v76 = v63->m_edges.m_capacityAndFlags;
  v77 = &v63->m_edges;
  v78 = v76 & 0x3FFFFFFF;
  if ( v78 >= v70 )
  {
    v80 = 0;
    LODWORD(geoma) = 0;
  }
  else
  {
    v79 = 2 * v78;
    if ( v70 < v79 )
      v70 = v79;
    hkArrayUtil::_reserve(
      (hkResult *)&geoma,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v77,
      v70,
      16);
    v80 = (signed int)geoma;
  }
  if ( resulta.m_enum == 1 || v137.m_enum == 1 || v80 == 1 )
  {
LABEL_34:
    v45 = v145;
    v145->m_enum = 1;
  }
  else
  {
    if ( (v67->m_capacityAndFlags & 0x3FFFFFFF) < v62->m_vertices.m_size )
    {
      if ( v67->m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v67->m_data,
          16 * v67->m_capacityAndFlags);
      v135 = 16 * v62->m_vertices.m_size;
      v67->m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                    &v135);
      v67->m_capacityAndFlags = v135 / 16;
    }
    v81 = v62->m_vertices.m_size;
    v82 = (char *)v67->m_data;
    v67->m_size = v81;
    v83 = v81;
    if ( (signed int)v81 > 0 )
    {
      v84 = (char *)v62->m_vertices.m_data - v82;
      do
      {
        v85 = *(_OWORD *)&v82[v84];
        v82 += 16;
        *((_OWORD *)v82 - 1) = v85;
        --v83;
      }
      while ( v83 );
    }
    v86 = 0;
    if ( v62->m_vertices.m_size > 0 )
    {
      v87 = v147;
      v88 = 0i64;
      do
      {
        v89 = v67->m_size;
        v90 = v62->m_vertices.m_data;
        ++v86;
        ++v88;
        v67->m_size = v89 + 1;
        v67->m_data[v89].m_quad = _mm_add_ps(v87->m_quad, v90[v88 - 1].m_quad);
      }
      while ( v86 < v62->m_vertices.m_size );
      v65 = v136.m_enum;
    }
    v91 = *(_DWORD *)(v72 + 12) & 0x3FFFFFFF;
    if ( v91 < v62->m_faces.m_size )
    {
      if ( *(_DWORD *)(v72 + 12) >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)v72,
          12 * v91);
      v135 = 12 * v62->m_faces.m_size;
      *(_QWORD *)v72 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                         (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                         &v135);
      *(_DWORD *)(v72 + 12) = v135 / 12;
    }
    v92 = v62->m_faces.m_size;
    v93 = *(char **)v72;
    *(_DWORD *)(v72 + 8) = v92;
    v94 = v92;
    if ( (signed int)v92 > 0 )
    {
      v95 = (char *)v62->m_faces.m_data - v93;
      do
      {
        v96 = *(_DWORD *)&v93[v95];
        v93 += 12;
        *((_DWORD *)v93 - 3) = v96;
        *((_DWORD *)v93 - 2) = *(_DWORD *)&v93[v95 - 8];
        *((_DWORD *)v93 - 1) = *(_DWORD *)&v93[v95 - 4];
        --v94;
      }
      while ( v94 );
    }
    v97 = *(_DWORD *)(v72 + 12);
    normalOut.m_quad.m128_i8[8] = 8;
    v98 = v97 & 0x3FFFFFFF;
    if ( v98 < v69 )
    {
      v99 = 2 * v98;
      v100 = v69;
      if ( v69 < v99 )
        v100 = v99;
      hkArrayUtil::_reserve(&v138, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, (void *)v72, v100, 12);
    }
    v101 = *(signed int *)(v72 + 8);
    v102 = *(_QWORD *)v72 + 12 * v101;
    if ( v69 - (signed int)v101 > 0 )
    {
      v103 = normalOut.m_quad.m128_f32[2];
      *(_QWORD *)v102 = 0i64;
      v104 = (_DWORD *)(v102 + 12);
      *(float *)(v102 + 8) = v103;
      for ( j = (unsigned __int64)(12i64 * (v69 - (signed int)v101) - 12) >> 2; j; --j )
      {
        *v104 = *(_DWORD *)v102;
        v102 += 4i64;
        ++v104;
      }
    }
    *(_DWORD *)(v72 + 8) = v69;
    v106 = v140;
    if ( v140 <= 0i64 )
    {
      v118 = v139;
    }
    else
    {
      v107 = 0i64;
      do
      {
        v108 = v77->m_size;
        v109 = v108 + 1;
        v110 = v77->m_capacityAndFlags & 0x3FFFFFFF;
        v111 = &v62->m_edges.m_data[v107];
        if ( v110 >= (signed int)v108 + 1 )
        {
          v138.m_enum = 0;
        }
        else
        {
          v112 = 2 * v110;
          if ( v109 < v112 )
            v109 = v112;
          hkArrayUtil::_reserve(&v138, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v77, v109, 16);
        }
        ++v77->m_size;
        v113 = &v77->m_data[v108];
        v113->m_a = v111->m_a;
        v113->m_b = v111->m_b;
        v113->m_face = v111->m_face;
        v113->m_data = v111->m_data;
        v114 = v77->m_size;
        v115 = v114 + 1;
        v116 = v77->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v116 >= (signed int)v114 + 1 )
        {
          v136.m_enum = 0;
        }
        else
        {
          v117 = 2 * v116;
          if ( v115 < v117 )
            v115 = v117;
          hkArrayUtil::_reserve(&v136, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v77, v115, 16);
        }
        ++v77->m_size;
        v118 = v139;
        ++v107;
        v119 = &v77->m_data[v114];
        v119->m_a = v139 + v111->m_a;
        v119->m_b = v118 + v111->m_b;
        v119->m_face = v65 + v111->m_face - 1;
        v119->m_data = v111->m_data;
        --v106;
      }
      while ( v106 );
    }
    v120 = v141;
    v121 = 0i64;
    if ( v141 > 0 )
    {
      v122 = v144;
      do
      {
        v123 = v122->m_edgeToSideFaceMap.m_data[v121];
        if ( v123 >= 0 )
        {
          v124 = v142.m_enum + v123;
          v125 = v122->m_uniqueEdges.m_startUniqueEdge.m_data[v121];
          v126 = **(_DWORD **)v125;
          v127 = (*v125)->m_b;
          v128 = v77->m_size + 4;
          v136.m_enum = v77->m_size;
          v129 = v77->m_capacityAndFlags & 0x3FFFFFFF;
          v130 = v127 + v118;
          v131 = v126 + v118;
          if ( v129 >= v128 )
          {
            v138.m_enum = 0;
          }
          else
          {
            v132 = 2 * v129;
            if ( v128 < v132 )
              v128 = v132;
            hkArrayUtil::_reserve(&v138, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v77, v128, 16);
            v120 = v141;
            v118 = v139;
          }
          v77->m_size += 4;
          v122 = v144;
          v133 = &v77->m_data[v136.m_enum];
          v133->m_a = v126;
          v133[1].m_a = v127;
          v133->m_b = v127;
          v133->m_face = v124;
          v133->m_data = 0;
          v133[1].m_b = v130;
          v133[1].m_face = v124;
          v133[1].m_data = 0;
          v133[2].m_a = v130;
          v133[2].m_b = v131;
          v133[2].m_face = v124;
          v133[2].m_data = 0;
          v133[3].m_a = v131;
          v133[3].m_b = v126;
          v133[3].m_face = v124;
          v133[3].m_data = 0;
        }
        ++v121;
      }
      while ( v121 < v120 );
    }
    v45 = v145;
    v145->m_enum = 0;
  }
  v46 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v47 = v46[1];
  if ( v47 < v46[3] )
  {
    v48 = __rdtsc();
    *(_DWORD *)(v47 + 8) = v48;
    *(_QWORD *)v47 = "Et";
    v46[1] = v47 + 16;
  }
  return v45;
}

// File Line: 724
// RVA: 0xB9D780
void __fastcall hkaiGeometryExtrudeUtil::IndexMap::IndexMap(hkaiGeometryExtrudeUtil::IndexMap *this)
{
  this->m_map.m_capacityAndFlags = 2147483648;
  this->m_map.m_data = 0i64;
  this->m_map.m_size = 0;
  this->m_freeIndex = 0;
}

// File Line: 729
// RVA: 0xB9D8A0
void __fastcall hkaiGeometryExtrudeUtil::IndexMap::clear(hkaiGeometryExtrudeUtil::IndexMap *this)
{
  this->m_freeIndex = 0;
  this->m_map.m_size = 0;
}

// File Line: 735
// RVA: 0xB9D7A0
hkResult *__fastcall hkaiGeometryExtrudeUtil::IndexMap::init(hkaiGeometryExtrudeUtil::IndexMap *this, hkResult *result, int size)
{
  int v3; // esi
  hkResult *v4; // rbx
  int v5; // eax
  hkaiGeometryExtrudeUtil::IndexMap *v6; // r15
  int v7; // eax
  int v8; // er9
  hkResult *v9; // rax
  int v10; // eax
  int v11; // eax
  int v12; // er9
  int v13; // edx
  int *v14; // rdi
  __int64 v15; // rcx
  hkResult v16; // [rsp+50h] [rbp+8h]
  hkResult resulta; // [rsp+60h] [rbp+18h]

  v3 = size;
  v4 = result;
  v5 = this->m_map.m_capacityAndFlags & 0x3FFFFFFF;
  v6 = this;
  if ( v5 >= size )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v7 = 2 * v5;
    v8 = size;
    if ( size < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &this->m_map, v8, 4);
    if ( resulta.m_enum )
    {
      v4->m_enum = 1;
      return v4;
    }
  }
  v10 = v6->m_map.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < v3 )
  {
    v11 = 2 * v10;
    v12 = v3;
    if ( v3 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&v16, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_map, v12, 4);
  }
  v13 = v3 - v6->m_map.m_size;
  v14 = &v6->m_map.m_data[v6->m_map.m_size];
  v15 = v13;
  if ( v13 > 0 )
  {
    while ( v15 )
    {
      *v14 = -1;
      ++v14;
      --v15;
    }
  }
  v6->m_map.m_size = v3;
  v4->m_enum = 0;
  v9 = v4;
  v6->m_freeIndex = 0;
  return v9;
}

// File Line: 744
// RVA: 0xB9D8B0
__int64 __fastcall hkaiGeometryExtrudeUtil::IndexMap::add(hkaiGeometryExtrudeUtil::IndexMap *this, int index)
{
  int *v2; // rax
  unsigned int *v3; // r8
  __int64 result; // rax
  unsigned int v5; // edx

  v2 = this->m_map.m_data;
  v3 = (unsigned int *)&v2[index];
  result = (unsigned int)v2[index];
  if ( (signed int)result < 0 )
  {
    v5 = this->m_freeIndex++;
    *v3 = v5;
    result = v5;
  }
  return result;
}


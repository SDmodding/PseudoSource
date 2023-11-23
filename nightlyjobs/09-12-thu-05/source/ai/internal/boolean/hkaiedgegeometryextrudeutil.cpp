// File Line: 61
// RVA: 0xB9EDD0
void __fastcall hkaiGeometryExtrudeUtil_copyVertices(
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertices,
        hkaiGeometryExtrudeUtil::IndexMap *indexMap,
        int base,
        hkVector4f *offset,
        hkArray<hkVector4f,hkContainerHeapAllocator> *verticesOut)
{
  __int64 m_size; // r9
  hkVector4f *v8; // r11
  __int64 v9; // rax
  __int64 v10; // rdx
  __int64 v11; // r8

  m_size = indexMap->m_map.m_size;
  v8 = &verticesOut->m_data[base];
  v9 = 0i64;
  if ( m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = indexMap->m_map.m_data[v9];
      if ( (int)v11 >= 0 )
        v8[v11].m_quad = _mm_add_ps(vertices->m_data[v10].m_quad, offset->m_quad);
      ++v9;
      ++v10;
    }
    while ( v9 < m_size );
  }
}

// File Line: 82
// RVA: 0xB9EE40
__int64 __fastcall hkaiGeometryExtrudeUtil_isSideEdge(hkArrayBase<int> *edgeFaces, hkBitField *forwardFaces)
{
  __int64 v3; // rdi
  __int64 m_size; // r10
  int *i; // rbx
  __int64 v6; // rax
  int *v7; // r9

  if ( edgeFaces->m_size <= 1 )
    return 1i64;
  v3 = 0i64;
  m_size = edgeFaces->m_size;
  for ( i = edgeFaces->m_data; ; ++i )
  {
    v6 = ++v3;
    if ( v3 < m_size )
      break;
LABEL_9:
    if ( v3 >= m_size )
      return 0i64;
  }
  v7 = i + 1;
  while ( ((forwardFaces->m_storage.m_words.m_data[(__int64)*i >> 5] >> (*i & 0x1F)) & 1) == ((forwardFaces->m_storage.m_words.m_data[(__int64)*v7 >> 5] >> (*v7 & 0x1F)) & 1) )
  {
    ++v6;
    ++v7;
    if ( v6 >= m_size )
      goto LABEL_9;
  }
  return 1i64;
}

// File Line: 107
// RVA: 0xB9D8E0
hkResult *__fastcall hkaiGeometryExtrudeUtil::silhouetteExtrudeDeprecated(
        hkResult *result,
        hkaiEdgeGeometry *geom,
        hkVector4f *extrudeDirection,
        hkaiEdgeGeometry *geomOut)
{
  hkaiGeometryExtrudeUtil v9; // [rsp+30h] [rbp-C8h] BYREF

  hkaiGeometryExtrudeUtil::hkaiGeometryExtrudeUtil(&v9);
  hkaiGeometryExtrudeUtil::silhouetteExtrudeImpl(&v9, result, geom, extrudeDirection, geomOut);
  hkaiGeometryExtrudeUtil::~hkaiGeometryExtrudeUtil(&v9);
  return result;
}

// File Line: 113
// RVA: 0xB9D960
hkResult *__fastcall hkaiGeometryExtrudeUtil::silhouetteExtrudeImplDeprecated(
        hkaiGeometryExtrudeUtil *this,
        hkResult *result,
        hkaiEdgeGeometry *geom,
        hkVector4f *extrudeDirection,
        hkaiEdgeGeometry *geomOut)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // rdi
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  int v13; // eax
  int v14; // esi
  hkaiUniqueEdges *p_m_uniqueEdges; // r13
  hkBitField *p_m_forwardFaces; // r12
  int m_capacityAndFlags; // r8d
  hkaiGeometryExtrudeUtil::IndexMap *p_m_frontVertexMap; // r15
  hkaiGeometryExtrudeUtil::IndexMap *p_m_backVertexMap; // rdi
  hkaiEdgeGeometry *v20; // r8
  int v21; // eax
  int v22; // ecx
  hkArray<int,hkContainerHeapAllocator> *p_m_backFaceMap; // rbx
  int v24; // eax
  int v25; // eax
  int v26; // r9d
  unsigned int *m_data; // rdi
  __int64 i; // rcx
  int v29; // r8d
  hkaiGeometryExtrudeUtil::IndexMap *v30; // rsi
  __int64 v31; // r12
  __int64 v32; // rbx
  int v33; // r14d
  int v34; // r15d
  hkaiGeometryExtrudeUtil::IndexMap *v35; // r13
  hkaiEdgeGeometry::Edge *const **v36; // rax
  hkaiEdgeGeometry::Edge *const *v37; // rdi
  hkaiEdgeGeometry::Edge *const *v38; // rsi
  __m128 v39; // xmm2
  int *v40; // rax
  hkResultEnum m_enum; // edx
  hkaiGeometryExtrudeUtil::IndexMap *v42; // r12
  hkResult *v43; // rbx
  _QWORD *v44; // rsi
  unsigned __int64 v45; // rdi
  unsigned __int64 v46; // rax
  hkaiGeometryExtrudeUtil *v48; // rcx
  hkArray<int,hkContainerHeapAllocator> *p_m_edgeToSideFaceMap; // r13
  int v50; // eax
  hkResultEnum v51; // edi
  int v52; // eax
  int v53; // eax
  int v54; // r9d
  int v55; // r8d
  int v56; // edx
  __int64 v57; // r15
  int *p_m_edgeFaces; // r14
  hkaiEdgeGeometry::Edge *const **v59; // rax
  int **v60; // rbx
  int **v61; // r12
  int v62; // eax
  __int64 v63; // rcx
  int v64; // eax
  int **j; // r8
  __int64 v66; // r9
  int v67; // edx
  int v68; // esi
  __int64 v69; // rcx
  int *v70; // rax
  __int64 v71; // rbx
  __int64 v72; // r8
  int *v73; // r11
  __int64 v74; // rsi
  int *v75; // rdi
  int *v76; // rdi
  int v77; // r8d
  hkaiEdgeGeometry *v78; // rbx
  int m_freeIndex; // r14d
  int v80; // esi
  __int32 v81; // r12d
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_vertices; // r13
  int v83; // esi
  int v84; // edi
  int v85; // eax
  int v86; // eax
  int v87; // r9d
  int v88; // eax
  int v89; // eax
  int v90; // r9d
  int v91; // eax
  int v92; // eax
  hkResultEnum v93; // eax
  hkaiEdgeGeometry *v94; // rdi
  hkaiEdgeGeometry *v95; // r13
  int v96; // eax
  __int64 v97; // rax
  hkaiEdgeGeometry::Face *v98; // rcx
  hkaiEdgeGeometry::Face *v99; // rdi
  __int64 v100; // rdx
  signed __int64 v101; // rdi
  unsigned int v102; // eax
  int v103; // eax
  int v104; // eax
  int v105; // eax
  int v106; // r9d
  __int64 v107; // rdx
  __int64 v108; // rsi
  int v109; // eax
  _DWORD *v110; // rdi
  unsigned __int64 k; // rcx
  __int64 v112; // r8
  hkResultEnum v113; // r9d
  __int64 v114; // rsi
  int *v115; // rdi
  bool v116; // zf
  __int64 v117; // rdx
  __int64 v118; // rcx
  hkaiEdgeGeometry::Edge *v119; // rdx
  __int64 v120; // rdx
  __int32 v121; // eax
  __int64 v122; // r13
  __int64 v123; // r10
  int v124; // r11d
  _QWORD *v125; // r12
  int v126; // r9d
  unsigned int v127; // r9d
  int *v128; // rdx
  int *v129; // rcx
  __int64 v130; // rdi
  int v131; // r8d
  __int64 v132; // rdx
  int v133; // esi
  int *v134; // rcx
  __int64 v135; // rcx
  __int64 v136; // rax
  unsigned int m_slotID; // ecx
  _QWORD *v138; // rsi
  unsigned __int64 v139; // rdi
  unsigned __int64 v140; // rax
  hkResult resulta; // [rsp+30h] [rbp-71h] BYREF
  hkResult v142; // [rsp+34h] [rbp-6Dh] BYREF
  hkResult v143; // [rsp+38h] [rbp-69h] BYREF
  hkResult v144; // [rsp+3Ch] [rbp-65h] BYREF
  int numBits; // [rsp+40h] [rbp-61h]
  hkArray<int,hkContainerHeapAllocator> *v146; // [rsp+48h] [rbp-59h]
  hkaiGeometryExtrudeUtil::IndexMap *v147; // [rsp+50h] [rbp-51h]
  int m_size; // [rsp+58h] [rbp-49h]
  hkaiUniqueEdges *v149; // [rsp+60h] [rbp-41h]
  __int64 v150; // [rsp+68h] [rbp-39h]
  hkaiGeometryExtrudeUtil::IndexMap *indexMap; // [rsp+70h] [rbp-31h]
  int v152; // [rsp+78h] [rbp-29h]
  hkBitField *v153; // [rsp+80h] [rbp-21h]
  hkVector4f normalOut; // [rsp+90h] [rbp-11h] BYREF
  hkaiEdgeGeometry *geoma; // [rsp+110h] [rbp+6Fh] BYREF
  hkVector4f *offset; // [rsp+118h] [rbp+77h]

  offset = extrudeDirection;
  geoma = geom;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtsilhouetteExtrudeDeprecated";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  m_size = geom->m_edges.m_size;
  v13 = geom->m_faces.m_size;
  v14 = geom->m_vertices.m_size;
  numBits = v13;
  hkaiFaceEdges::clear(&this->m_faceEdges);
  p_m_uniqueEdges = &this->m_uniqueEdges;
  v149 = &this->m_uniqueEdges;
  hkaiUniqueEdges::clear(&this->m_uniqueEdges);
  p_m_forwardFaces = &this->m_forwardFaces;
  this->m_forwardFaces.m_storage.m_numBits = 0;
  m_capacityAndFlags = this->m_forwardFaces.m_storage.m_words.m_capacityAndFlags;
  v153 = &this->m_forwardFaces;
  this->m_forwardFaces.m_storage.m_words.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      p_m_forwardFaces->m_storage.m_words.m_data,
      4 * m_capacityAndFlags);
  p_m_frontVertexMap = &this->m_frontVertexMap;
  p_m_forwardFaces->m_storage.m_words.m_data = 0i64;
  this->m_forwardFaces.m_storage.m_words.m_capacityAndFlags = 0x80000000;
  this->m_backFaceMap.m_size = 0;
  indexMap = &this->m_frontVertexMap;
  hkaiGeometryExtrudeUtil::IndexMap::clear(&this->m_frontVertexMap);
  p_m_backVertexMap = &this->m_backVertexMap;
  v147 = &this->m_backVertexMap;
  hkaiGeometryExtrudeUtil::IndexMap::clear(&this->m_backVertexMap);
  v20 = geoma;
  this->m_edgeToSideFaceMap.m_size = 0;
  this->m_edgeFaces.m_size = 0;
  hkaiFaceEdges::setGeometry(&this->m_faceEdges, &resulta, v20);
  if ( resulta.m_enum != HK_FAILURE )
  {
    hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::trySetSize(
      &this->m_forwardFaces,
      &resulta,
      0,
      numBits,
      0);
    if ( resulta.m_enum == HK_SUCCESS )
    {
      v21 = this->m_backFaceMap.m_capacityAndFlags;
      v22 = numBits;
      p_m_backFaceMap = &this->m_backFaceMap;
      v24 = v21 & 0x3FFFFFFF;
      v146 = p_m_backFaceMap;
      if ( v24 < numBits )
      {
        v25 = 2 * v24;
        v26 = numBits;
        if ( numBits < v25 )
          v26 = v25;
        hkArrayUtil::_reserve(&v144, &hkContainerHeapAllocator::s_alloc, p_m_backFaceMap, v26, 4);
        v22 = numBits;
      }
      p_m_backFaceMap->m_size = v22;
      hkaiGeometryExtrudeUtil::IndexMap::init(p_m_frontVertexMap, &resulta, v14);
      if ( resulta.m_enum == HK_SUCCESS )
      {
        hkaiGeometryExtrudeUtil::IndexMap::init(p_m_backVertexMap, &resulta, v14);
        if ( resulta.m_enum == HK_SUCCESS )
        {
          m_data = p_m_forwardFaces->m_storage.m_words.m_data;
          if ( p_m_forwardFaces->m_storage.m_words.m_data )
          {
            if ( (p_m_backFaceMap->m_capacityAndFlags & 0x3FFFFFFF) == 0 || p_m_backFaceMap->m_data )
            {
              if ( p_m_forwardFaces->m_storage.m_words.m_size - 1 >= 0 )
              {
                for ( i = (unsigned int)p_m_forwardFaces->m_storage.m_words.m_size; i; --i )
                  *m_data++ = 0;
              }
              hkaiGeometryExtrudeUtil::IndexMap::init(p_m_frontVertexMap, &v144, v14);
              v29 = v14;
              v30 = v147;
              hkaiGeometryExtrudeUtil::IndexMap::init(v147, &v144, v29);
              v31 = numBits;
              v32 = 1i64;
              v143.m_enum = HK_SUCCESS;
              v142.m_enum = HK_SUCCESS;
              v150 = numBits;
              v33 = 2;
              v34 = 1;
              if ( numBits > 1i64 )
              {
                v35 = v30;
                do
                {
                  v36 = this->m_faceEdges.m_faceStartEdges.m_data;
                  v37 = v36[v32];
                  v38 = v36[v32 + 1];
                  hkaiEdgeGeometry::calculateFaceNormal(geoma, v37, v38, &normalOut);
                  v39 = _mm_mul_ps(normalOut.m_quad, offset->m_quad);
                  v40 = v146->m_data;
                  if ( (float)((float)(_mm_shuffle_ps(v39, v39, 85).m128_f32[0] + _mm_shuffle_ps(v39, v39, 0).m128_f32[0])
                             + _mm_shuffle_ps(v39, v39, 170).m128_f32[0]) > 0.0 )
                  {
                    for ( v40[v32] = -1; v37 != v38; ++v37 )
                    {
                      hkaiGeometryExtrudeUtil::IndexMap::add(v35, **(_DWORD **)v37);
                      hkaiGeometryExtrudeUtil::IndexMap::add(v35, (*v37)->m_b);
                    }
                  }
                  else
                  {
                    m_enum = v143.m_enum;
                    v40[v32] = v143.m_enum;
                    v153->m_storage.m_words.m_data[(__int64)v34 >> 5] |= v33;
                    v143.m_enum = m_enum + 1;
                    v142.m_enum += (unsigned int)(v38 - v37);
                    if ( v37 != v38 )
                    {
                      v42 = indexMap;
                      do
                      {
                        hkaiGeometryExtrudeUtil::IndexMap::add(v42, **(_DWORD **)v37);
                        hkaiGeometryExtrudeUtil::IndexMap::add(v42, (*v37)->m_b);
                        hkaiGeometryExtrudeUtil::IndexMap::add(v35, **(_DWORD **)v37);
                        hkaiGeometryExtrudeUtil::IndexMap::add(v35, (*v37++)->m_b);
                      }
                      while ( v37 != v38 );
                      v31 = v150;
                    }
                  }
                  v33 = __ROL4__(v33, 1);
                  ++v32;
                  ++v34;
                }
                while ( v32 < v31 );
                p_m_uniqueEdges = v149;
                v30 = v147;
              }
              hkaiUniqueEdges::setGeometry(p_m_uniqueEdges, &resulta, geoma);
              if ( resulta.m_enum == HK_FAILURE )
                goto LABEL_32;
              v48 = this;
              p_m_edgeToSideFaceMap = &this->m_edgeToSideFaceMap;
              v50 = this->m_edgeToSideFaceMap.m_capacityAndFlags;
              v51 = this->m_uniqueEdges.m_startUniqueEdge.m_size - 1;
              normalOut.m_quad.m128_u64[0] = (unsigned __int64)&this->m_edgeToSideFaceMap;
              v52 = v50 & 0x3FFFFFFF;
              v144.m_enum = v51;
              if ( v52 < v51 )
              {
                v53 = 2 * v52;
                v54 = v51;
                if ( v51 < v53 )
                  v54 = v53;
                hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &this->m_edgeToSideFaceMap, v54, 4);
                v48 = this;
              }
              this->m_edgeToSideFaceMap.m_size = v51;
              if ( (this->m_edgeToSideFaceMap.m_capacityAndFlags & 0x3FFFFFFF) != 0 && !p_m_edgeToSideFaceMap->m_data )
                goto LABEL_32;
              v55 = 0;
              v56 = 0;
              v57 = 0i64;
              LODWORD(v149) = 0;
              LODWORD(v146) = 0;
              v150 = v51;
              if ( v51 > HK_SUCCESS )
              {
                p_m_edgeFaces = (int *)&v48->m_edgeFaces;
                while ( 1 )
                {
                  v59 = v48->m_uniqueEdges.m_startUniqueEdge.m_data;
                  v48->m_edgeFaces.m_size = 0;
                  v60 = (int **)v59[v57 + 1];
                  v61 = (int **)v59[v57];
                  v62 = p_m_edgeFaces[3] & 0x3FFFFFFF;
                  v63 = v60 - v61;
                  if ( v62 >= (int)v63 )
                  {
                    resulta.m_enum = HK_SUCCESS;
                  }
                  else
                  {
                    v64 = 2 * v62;
                    if ( (int)v63 < v64 )
                      LODWORD(v63) = v64;
                    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, p_m_edgeFaces, v63, 4);
                    if ( resulta.m_enum )
                      goto LABEL_32;
                  }
                  for ( j = v61; j != v60; ++j )
                  {
                    v66 = p_m_edgeFaces[2];
                    v67 = 0;
                    v68 = (*j)[2];
                    v69 = 0i64;
                    if ( (int)v66 > 0 )
                    {
                      v70 = *(int **)p_m_edgeFaces;
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
                    *(_DWORD *)(*(_QWORD *)p_m_edgeFaces + 4 * v66) = v68;
                    ++p_m_edgeFaces[2];
                  }
                  if ( p_m_edgeFaces[2] > 1 )
                  {
                    v71 = 0i64;
                    v72 = p_m_edgeFaces[2];
                    v73 = *(int **)p_m_edgeFaces;
                    while ( 1 )
                    {
                      v74 = ++v71;
                      if ( v71 < v72 )
                        break;
LABEL_65:
                      ++v73;
                      if ( v71 >= v72 )
                      {
                        v30 = v147;
                        v55 = (int)v149;
                        v56 = (_DWORD)v146 + 1;
                        p_m_edgeToSideFaceMap->m_data[v57] = -1;
                        LODWORD(v146) = v56;
                        goto LABEL_68;
                      }
                    }
                    v75 = v73 + 1;
                    while ( ((v153->m_storage.m_words.m_data[(__int64)*v73 >> 5] >> (*v73 & 0x1F)) & 1) == ((v153->m_storage.m_words.m_data[(__int64)*v75 >> 5] >> (*v75 & 0x1F)) & 1) )
                    {
                      ++v74;
                      ++v75;
                      if ( v74 >= v72 )
                        goto LABEL_65;
                    }
                  }
                  v76 = *v61;
                  hkaiGeometryExtrudeUtil::IndexMap::add(indexMap, **v61);
                  hkaiGeometryExtrudeUtil::IndexMap::add(indexMap, v76[1]);
                  v30 = v147;
                  hkaiGeometryExtrudeUtil::IndexMap::add(v147, *v76);
                  hkaiGeometryExtrudeUtil::IndexMap::add(v30, v76[1]);
                  v77 = (int)v149;
                  v56 = (int)v146;
                  p_m_edgeToSideFaceMap->m_data[v57] = (int)v149;
                  v55 = v77 + 1;
                  LODWORD(v149) = v55;
LABEL_68:
                  if ( ++v57 >= v150 )
                    break;
                  v48 = this;
                }
                v51 = v144.m_enum;
              }
              v78 = geomOut;
              m_freeIndex = indexMap->m_freeIndex;
              v80 = v30->m_freeIndex;
              v81 = numBits + v55 + v143.m_enum;
              LODWORD(v146) = geoma->m_faces.m_size;
              v144.m_enum = v55 + (_DWORD)v146;
              p_m_vertices = &geomOut->m_vertices;
              v83 = m_freeIndex + v80;
              v84 = m_size + v142.m_enum + 4 * (v51 - v56);
              v85 = geomOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
              if ( v85 >= v83 )
              {
                v142.m_enum = HK_SUCCESS;
              }
              else
              {
                v86 = 2 * v85;
                v87 = v83;
                if ( v83 < v86 )
                  v87 = v86;
                hkArrayUtil::_reserve(&v142, &hkContainerHeapAllocator::s_alloc, &geomOut->m_vertices, v87, 16);
                if ( v142.m_enum )
                {
LABEL_78:
                  v88 = v78->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
                  if ( v88 >= v81 )
                  {
                    v143.m_enum = HK_SUCCESS;
                  }
                  else
                  {
                    v89 = 2 * v88;
                    v90 = v81;
                    if ( v81 < v89 )
                      v90 = v89;
                    hkArrayUtil::_reserve(&v143, &hkContainerHeapAllocator::s_alloc, &v78->m_faces, v90, 12);
                  }
                  v91 = v78->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
                  if ( v91 >= v84 )
                  {
                    v93 = HK_SUCCESS;
                    resulta.m_enum = HK_SUCCESS;
                  }
                  else
                  {
                    v92 = 2 * v91;
                    if ( v84 < v92 )
                      v84 = v92;
                    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &v78->m_edges, v84, 16);
                    v93 = resulta.m_enum;
                  }
                  if ( v142.m_enum != HK_FAILURE && v143.m_enum != HK_FAILURE && v93 != HK_FAILURE )
                  {
                    v94 = geoma;
                    hkaiGeometryExtrudeUtil_copyVertices(&geoma->m_vertices, indexMap, 0, &aabbOut, p_m_vertices);
                    hkaiGeometryExtrudeUtil_copyVertices(&v94->m_vertices, v147, m_freeIndex, offset, p_m_vertices);
                    v95 = v94;
                    v96 = v78->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
                    if ( v96 < v94->m_faces.m_size )
                    {
                      if ( v78->m_faces.m_capacityAndFlags >= 0 )
                        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                          &hkContainerHeapAllocator::s_alloc,
                          v78->m_faces.m_data,
                          12 * v96);
                      LODWORD(geoma) = 12 * v94->m_faces.m_size;
                      v78->m_faces.m_data = (hkaiEdgeGeometry::Face *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                                        &hkContainerHeapAllocator::s_alloc,
                                                                        &geoma);
                      v78->m_faces.m_capacityAndFlags = (int)geoma / 12;
                    }
                    v97 = v94->m_faces.m_size;
                    v98 = v78->m_faces.m_data;
                    v78->m_faces.m_size = v97;
                    v99 = v94->m_faces.m_data;
                    v100 = v97;
                    if ( (int)v97 > 0 )
                    {
                      v101 = (char *)v99 - (char *)v98;
                      do
                      {
                        v102 = *(unsigned int *)((char *)&v98->m_data + v101);
                        ++v98;
                        v98[-1].m_data = v102;
                        v98[-1].m_faceIndex = *(_DWORD *)((char *)v98 + v101 - 8);
                        *(_DWORD *)&v98[-1].m_flags.m_storage = *(_DWORD *)((char *)v98 + v101 - 4);
                        --v100;
                      }
                      while ( v100 );
                    }
                    v103 = v78->m_faces.m_capacityAndFlags;
                    LOBYTE(v152) = 8;
                    v104 = v103 & 0x3FFFFFFF;
                    if ( v104 < v81 )
                    {
                      v105 = 2 * v104;
                      v106 = v81;
                      if ( v81 < v105 )
                        v106 = v105;
                      hkArrayUtil::_reserve(
                        (hkResult *)&geoma,
                        &hkContainerHeapAllocator::s_alloc,
                        &v78->m_faces,
                        v106,
                        12);
                    }
                    v107 = v78->m_faces.m_size;
                    v108 = (__int64)&v78->m_faces.m_data[v107];
                    if ( v81 - (int)v107 > 0 )
                    {
                      v109 = v152;
                      *(_QWORD *)v108 = 0i64;
                      v110 = (_DWORD *)(v108 + 12);
                      *(_DWORD *)(v108 + 8) = v109;
                      for ( k = (unsigned __int64)(12i64 * (v81 - (int)v107) - 12) >> 2; k; --k )
                      {
                        *v110 = *(_DWORD *)v108;
                        v108 += 4i64;
                        ++v110;
                      }
                    }
                    v112 = m_size;
                    v78->m_faces.m_size = v81;
                    if ( v112 > 0 )
                    {
                      v113 = v144.m_enum;
                      v114 = 0i64;
                      do
                      {
                        v115 = (int *)&v95->m_edges.m_data[v114];
                        v116 = ((v153->m_storage.m_words.m_data[(__int64)v115[2] >> 5] >> (v115[2] & 0x1F)) & 1) == 0;
                        v117 = v78->m_edges.m_size++;
                        v118 = *v115;
                        v119 = &v78->m_edges.m_data[v117];
                        if ( v116 )
                        {
                          v119->m_a = m_freeIndex + this->m_backVertexMap.m_map.m_data[v118];
                          v119->m_b = m_freeIndex + this->m_backVertexMap.m_map.m_data[v115[1]];
                          v121 = v115[2];
                        }
                        else
                        {
                          v119->m_a = this->m_frontVertexMap.m_map.m_data[v118];
                          v119->m_b = this->m_frontVertexMap.m_map.m_data[v115[1]];
                          v119->m_face = v115[2];
                          v119->m_data = v115[3];
                          v120 = v78->m_edges.m_size++;
                          v119 = &v78->m_edges.m_data[v120];
                          v119->m_a = m_freeIndex + this->m_backVertexMap.m_map.m_data[*v115];
                          v119->m_b = m_freeIndex + this->m_backVertexMap.m_map.m_data[v115[1]];
                          v121 = v113 + this->m_backFaceMap.m_data[v115[2]];
                        }
                        v119->m_face = v121;
                        ++v114;
                        v119->m_data = v115[3];
                        --v112;
                      }
                      while ( v112 );
                    }
                    v122 = v150;
                    v123 = 0i64;
                    if ( v150 > 0 )
                    {
                      v124 = (int)v146;
                      v125 = (_QWORD *)normalOut.m_quad.m128_u64[0];
                      do
                      {
                        v126 = *(_DWORD *)(*v125 + 4 * v123);
                        if ( v126 >= 0 )
                        {
                          v127 = v124 + v126;
                          v128 = (int *)*this->m_uniqueEdges.m_startUniqueEdge.m_data[v123];
                          v129 = this->m_frontVertexMap.m_map.m_data;
                          v130 = 4i64 * *v128;
                          v131 = *(int *)((char *)v129 + v130);
                          v132 = 4i64 * v128[1];
                          v133 = *(int *)((char *)v129 + v132);
                          v134 = this->m_backVertexMap.m_map.m_data;
                          LODWORD(v130) = *(int *)((char *)v134 + v130);
                          LODWORD(v132) = *(int *)((char *)v134 + v132);
                          v135 = v78->m_edges.m_size;
                          LODWORD(v130) = m_freeIndex + v130;
                          LODWORD(v132) = m_freeIndex + v132;
                          v78->m_edges.m_size = v135 + 4;
                          v136 = (__int64)&v78->m_edges.m_data[v135];
                          *(_DWORD *)v136 = v131;
                          *(_DWORD *)(v136 + 4) = v133;
                          *(_QWORD *)(v136 + 8) = v127;
                          *(_DWORD *)(v136 + 16) = v133;
                          *(_DWORD *)(v136 + 20) = v132;
                          *(_QWORD *)(v136 + 24) = v127;
                          *(_DWORD *)(v136 + 32) = v132;
                          *(_DWORD *)(v136 + 36) = v130;
                          *(_QWORD *)(v136 + 40) = v127;
                          *(_DWORD *)(v136 + 48) = v130;
                          *(_DWORD *)(v136 + 52) = v131;
                          *(_QWORD *)(v136 + 56) = v127;
                        }
                        ++v123;
                      }
                      while ( v123 < v122 );
                    }
                    v43 = result;
                    result->m_enum = HK_SUCCESS;
                    goto LABEL_33;
                  }
LABEL_32:
                  v43 = result;
                  result->m_enum = HK_FAILURE;
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
                }
              }
              p_m_vertices->m_size = v83;
              goto LABEL_78;
            }
          }
        }
      }
    }
  }
  m_slotID = hkMonitorStream__m_instance.m_slotID;
  result->m_enum = HK_FAILURE;
  v138 = TlsGetValue(m_slotID);
  v139 = v138[1];
  if ( v139 < v138[3] )
  {
    v140 = __rdtsc();
    *(_DWORD *)(v139 + 8) = v140;
    *(_QWORD *)v139 = "Et";
    v138[1] = v139 + 16;
  }
  return result;
}

// File Line: 444
// RVA: 0xB9E430
hkResult *__fastcall hkaiGeometryExtrudeUtil::silhouetteExtrudeImpl(
        hkaiGeometryExtrudeUtil *this,
        hkResult *result,
        hkaiEdgeGeometry *geom,
        hkVector4f *extrudeDirection,
        hkaiEdgeGeometry *geomOut)
{
  hkResult *v7; // r12
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // rdi
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  __int64 m_size; // r14
  int v14; // eax
  hkaiUniqueEdges *p_m_uniqueEdges; // r15
  hkBitField *p_m_forwardFaces; // r13
  int m_capacityAndFlags; // r8d
  unsigned int m_slotID; // ecx
  _QWORD *v19; // rsi
  unsigned __int64 v20; // rdi
  unsigned __int64 v21; // rax
  unsigned int *m_data; // rdi
  __int64 i; // rcx
  int v25; // ebx
  __int64 v26; // rsi
  int v27; // edi
  hkaiEdgeGeometry *v28; // r12
  __m128 v29; // xmm2
  hkaiGeometryExtrudeUtil *v30; // rcx
  hkResultEnum v31; // edi
  int v32; // eax
  int v33; // eax
  int v34; // r9d
  hkResultEnum m_enum; // edx
  int v36; // esi
  __int64 v37; // r12
  int *p_m_edgeFaces; // r15
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
  unsigned int m_face; // esi
  __int64 v52; // rcx
  int *v53; // rax
  __int64 v54; // rbx
  __int64 v55; // r8
  int *v56; // r10
  __int64 v57; // rsi
  int *v58; // rdi
  int *v59; // rax
  hkResultEnum v60; // edx
  hkaiEdgeGeometry *v61; // r13
  hkaiEdgeGeometry *v62; // rbx
  int v63; // r9d
  hkResultEnum v64; // r12d
  int v65; // esi
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_vertices; // rdi
  int v67; // eax
  __int32 v68; // r15d
  int v69; // esi
  int v70; // eax
  hkArray<hkaiEdgeGeometry::Face,hkContainerHeapAllocator> *p_m_faces; // r14
  int v72; // eax
  int v73; // eax
  int v74; // r9d
  int v75; // eax
  hkArray<hkaiEdgeGeometry::Edge,hkContainerHeapAllocator> *p_m_edges; // rbx
  int v77; // eax
  int v78; // eax
  int v79; // eax
  __int64 v80; // rax
  hkVector4f *v81; // rcx
  __int64 v82; // rdx
  signed __int64 v83; // rsi
  hkVector4f v84; // xmm0
  int v85; // r8d
  hkVector4f *v86; // r12
  __int64 v87; // rsi
  __int64 v88; // rdx
  hkVector4f *v89; // rcx
  int v90; // eax
  __int64 v91; // rax
  char *v92; // rcx
  __int64 v93; // rdx
  signed __int64 v94; // rdi
  int v95; // eax
  int v96; // eax
  int v97; // eax
  int v98; // eax
  int v99; // r9d
  __int64 v100; // rdx
  __int64 v101; // rsi
  int v102; // eax
  _DWORD *v103; // rdi
  unsigned __int64 j; // rcx
  __int64 v105; // r15
  __int64 v106; // r14
  __int64 v107; // rsi
  int v108; // r9d
  int v109; // eax
  hkaiEdgeGeometry::Edge *v110; // rdi
  int v111; // eax
  hkaiEdgeGeometry::Edge *v112; // rcx
  __int64 v113; // rsi
  int v114; // r9d
  int v115; // eax
  int v116; // eax
  int v117; // r8d
  hkaiEdgeGeometry::Edge *v118; // rdx
  hkaiUniqueEdges *v119; // rdx
  __int64 v120; // rsi
  hkaiGeometryExtrudeUtil *v121; // rcx
  int v122; // edi
  __int32 v123; // edi
  hkaiEdgeGeometry::Edge *const *v124; // rcx
  unsigned int v125; // r14d
  unsigned int m_b; // r15d
  int v127; // r9d
  int v128; // eax
  unsigned int v129; // r12d
  unsigned int v130; // r13d
  int v131; // eax
  hkaiEdgeGeometry::Edge *v132; // rax
  hkResult resulta; // [rsp+30h] [rbp-41h] BYREF
  int v134; // [rsp+34h] [rbp-3Dh] BYREF
  hkResult v135; // [rsp+38h] [rbp-39h] BYREF
  hkResult v136; // [rsp+3Ch] [rbp-35h] BYREF
  hkResult v137; // [rsp+40h] [rbp-31h] BYREF
  int v138; // [rsp+44h] [rbp-2Dh]
  int v139; // [rsp+48h] [rbp-29h]
  hkaiUniqueEdges *v140; // [rsp+50h] [rbp-21h]
  hkResult v141; // [rsp+58h] [rbp-19h] BYREF
  hkVector4f normalOut; // [rsp+60h] [rbp-11h] BYREF
  hkaiEdgeGeometry *geoma; // [rsp+E0h] [rbp+6Fh] BYREF
  hkVector4f *v146; // [rsp+E8h] [rbp+77h]

  v146 = extrudeDirection;
  geoma = geom;
  v7 = result;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtsilhouetteExtrude";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  m_size = geom->m_faces.m_size;
  v139 = geom->m_edges.m_size;
  v14 = geom->m_vertices.m_size;
  v137.m_enum = (int)m_size;
  v138 = v14;
  hkaiFaceEdges::clear(&this->m_faceEdges);
  p_m_uniqueEdges = &this->m_uniqueEdges;
  v140 = &this->m_uniqueEdges;
  hkaiUniqueEdges::clear(&this->m_uniqueEdges);
  p_m_forwardFaces = &this->m_forwardFaces;
  this->m_forwardFaces.m_storage.m_numBits = 0;
  m_capacityAndFlags = this->m_forwardFaces.m_storage.m_words.m_capacityAndFlags;
  this->m_forwardFaces.m_storage.m_words.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      p_m_forwardFaces->m_storage.m_words.m_data,
      4 * m_capacityAndFlags);
  p_m_forwardFaces->m_storage.m_words.m_data = 0i64;
  this->m_forwardFaces.m_storage.m_words.m_capacityAndFlags = 0x80000000;
  this->m_edgeToSideFaceMap.m_size = 0;
  this->m_edgeFaces.m_size = 0;
  hkaiFaceEdges::setGeometry(&this->m_faceEdges, &resulta, geom);
  if ( resulta.m_enum == HK_FAILURE )
    goto LABEL_6;
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::trySetSize(
    &this->m_forwardFaces,
    &resulta,
    0,
    m_size,
    0);
  if ( resulta.m_enum )
    goto LABEL_6;
  m_data = p_m_forwardFaces->m_storage.m_words.m_data;
  if ( !p_m_forwardFaces->m_storage.m_words.m_data )
    goto LABEL_6;
  if ( this->m_forwardFaces.m_storage.m_words.m_size - 1 >= 0 )
  {
    for ( i = (unsigned int)this->m_forwardFaces.m_storage.m_words.m_size; i; --i )
      *m_data++ = 0;
  }
  v25 = 1;
  v26 = 1i64;
  v27 = 2;
  if ( m_size > 1 )
  {
    v28 = geoma;
    do
    {
      hkaiEdgeGeometry::calculateFaceNormal(
        v28,
        this->m_faceEdges.m_faceStartEdges.m_data[v26],
        this->m_faceEdges.m_faceStartEdges.m_data[v26 + 1],
        &normalOut);
      v29 = _mm_mul_ps(normalOut.m_quad, v146->m_quad);
      if ( (float)((float)(_mm_shuffle_ps(v29, v29, 85).m128_f32[0] + _mm_shuffle_ps(v29, v29, 0).m128_f32[0])
                 + _mm_shuffle_ps(v29, v29, 170).m128_f32[0]) <= 0.0 )
        p_m_forwardFaces->m_storage.m_words.m_data[(__int64)v25 >> 5] |= v27;
      v27 = __ROL4__(v27, 1);
      ++v26;
      ++v25;
    }
    while ( v26 < m_size );
    p_m_uniqueEdges = v140;
    v7 = result;
  }
  hkaiUniqueEdges::setGeometry(p_m_uniqueEdges, &resulta, geoma);
  if ( resulta.m_enum == HK_FAILURE )
    goto LABEL_6;
  v30 = this;
  v31 = this->m_uniqueEdges.m_startUniqueEdge.m_size - 1;
  v32 = this->m_edgeToSideFaceMap.m_capacityAndFlags & 0x3FFFFFFF;
  v135.m_enum = v31;
  if ( v32 < v31 )
  {
    v33 = 2 * v32;
    v34 = v31;
    if ( v31 < v33 )
      v34 = v33;
    hkArrayUtil::_reserve(&v141, &hkContainerHeapAllocator::s_alloc, &this->m_edgeToSideFaceMap, v34, 4);
    v30 = this;
  }
  this->m_edgeToSideFaceMap.m_size = v31;
  if ( (this->m_edgeToSideFaceMap.m_capacityAndFlags & 0x3FFFFFFF) != 0 && !this->m_edgeToSideFaceMap.m_data )
  {
LABEL_6:
    m_slotID = hkMonitorStream__m_instance.m_slotID;
    v7->m_enum = HK_FAILURE;
    v19 = TlsGetValue(m_slotID);
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
  else
  {
    m_enum = HK_SUCCESS;
    v36 = 0;
    v37 = 0i64;
    v136.m_enum = HK_SUCCESS;
    v134 = 0;
    v140 = (hkaiUniqueEdges *)(int)v31;
    if ( v31 > HK_SUCCESS )
    {
      p_m_edgeFaces = (int *)&v30->m_edgeFaces;
      do
      {
        v39 = v30->m_uniqueEdges.m_startUniqueEdge.m_data;
        v30->m_edgeFaces.m_size = 0;
        v40 = v39[v37 + 1];
        v41 = v39[v37];
        v42 = p_m_edgeFaces[3] & 0x3FFFFFFF;
        v43 = v40 - v41;
        if ( v42 >= (int)v43 )
        {
          resulta.m_enum = HK_SUCCESS;
        }
        else
        {
          v44 = 2 * v42;
          if ( (int)v43 < v44 )
            LODWORD(v43) = v44;
          hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, p_m_edgeFaces, v43, 4);
          if ( resulta.m_enum )
            goto LABEL_34;
        }
        for ( ; v41 != v40; ++v41 )
        {
          v49 = p_m_edgeFaces[2];
          v50 = 0;
          m_face = (*v41)->m_face;
          v52 = 0i64;
          if ( (int)v49 > 0 )
          {
            v53 = *(int **)p_m_edgeFaces;
            while ( *v53 != m_face )
            {
              ++v52;
              ++v50;
              ++v53;
              if ( v52 >= v49 )
                goto LABEL_46;
            }
            if ( v50 >= 0 )
              continue;
          }
LABEL_46:
          *(_DWORD *)(*(_QWORD *)p_m_edgeFaces + 4 * v49) = m_face;
          ++p_m_edgeFaces[2];
        }
        if ( p_m_edgeFaces[2] > 1 )
        {
          v54 = 0i64;
          v55 = p_m_edgeFaces[2];
          v56 = *(int **)p_m_edgeFaces;
          while ( 1 )
          {
            v57 = ++v54;
            if ( v54 < v55 )
              break;
LABEL_54:
            ++v56;
            if ( v54 >= v55 )
            {
              v30 = this;
              m_enum = v136.m_enum;
              v36 = v134 + 1;
              v59 = this->m_edgeToSideFaceMap.m_data;
              ++v134;
              v59[v37] = -1;
              goto LABEL_57;
            }
          }
          v58 = v56 + 1;
          while ( ((p_m_forwardFaces->m_storage.m_words.m_data[(__int64)*v56 >> 5] >> (*v56 & 0x1F)) & 1) == ((p_m_forwardFaces->m_storage.m_words.m_data[(__int64)*v58 >> 5] >> (*v58 & 0x1F)) & 1) )
          {
            ++v57;
            ++v58;
            if ( v57 >= v55 )
              goto LABEL_54;
          }
        }
        v60 = v136.m_enum;
        v30 = this;
        v36 = v134;
        this->m_edgeToSideFaceMap.m_data[v37] = v136.m_enum;
        m_enum = v60 + 1;
        v136.m_enum = m_enum;
LABEL_57:
        ++v37;
      }
      while ( v37 < (__int64)v140 );
      v31 = v135.m_enum;
    }
    v61 = geoma;
    v62 = geomOut;
    v63 = 2 * v138;
    v64 = geoma->m_faces.m_size + m_enum;
    v141.m_enum = geoma->m_faces.m_size;
    v135.m_enum = v64;
    v65 = v139 + 2 * (v31 - v36);
    p_m_vertices = &geomOut->m_vertices;
    v67 = geomOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
    v68 = m_enum + 2 * v137.m_enum - 1;
    v69 = 2 * v65;
    if ( v67 >= 2 * v138 )
    {
      resulta.m_enum = HK_SUCCESS;
    }
    else
    {
      v70 = 2 * v67;
      if ( v63 < v70 )
        v63 = v70;
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &geomOut->m_vertices, v63, 16);
    }
    p_m_faces = &v62->m_faces;
    v72 = v62->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v72 >= v68 )
    {
      v136.m_enum = HK_SUCCESS;
    }
    else
    {
      v73 = 2 * v72;
      v74 = v68;
      if ( v68 < v73 )
        v74 = v73;
      hkArrayUtil::_reserve(&v136, &hkContainerHeapAllocator::s_alloc, &v62->m_faces, v74, 12);
    }
    v75 = v62->m_edges.m_capacityAndFlags;
    p_m_edges = &v62->m_edges;
    v77 = v75 & 0x3FFFFFFF;
    if ( v77 >= v69 )
    {
      v79 = 0;
      LODWORD(geoma) = 0;
    }
    else
    {
      v78 = 2 * v77;
      if ( v69 < v78 )
        v69 = v78;
      hkArrayUtil::_reserve((hkResult *)&geoma, &hkContainerHeapAllocator::s_alloc, p_m_edges, v69, 16);
      v79 = (int)geoma;
    }
    if ( resulta.m_enum == HK_FAILURE || v136.m_enum == HK_FAILURE || v79 == 1 )
    {
LABEL_34:
      v45 = result;
      result->m_enum = HK_FAILURE;
    }
    else
    {
      if ( (p_m_vertices->m_capacityAndFlags & 0x3FFFFFFF) < v61->m_vertices.m_size )
      {
        if ( p_m_vertices->m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            p_m_vertices->m_data,
            16 * p_m_vertices->m_capacityAndFlags);
        v134 = 16 * v61->m_vertices.m_size;
        p_m_vertices->m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                               &hkContainerHeapAllocator::s_alloc,
                                               &v134);
        p_m_vertices->m_capacityAndFlags = v134 / 16;
      }
      v80 = v61->m_vertices.m_size;
      v81 = p_m_vertices->m_data;
      p_m_vertices->m_size = v80;
      v82 = v80;
      if ( (int)v80 > 0 )
      {
        v83 = (char *)v61->m_vertices.m_data - (char *)v81;
        do
        {
          v84.m_quad = *(__m128 *)((char *)v81++ + v83);
          v81[-1] = (hkVector4f)v84.m_quad;
          --v82;
        }
        while ( v82 );
      }
      v85 = 0;
      if ( v61->m_vertices.m_size > 0 )
      {
        v86 = v146;
        v87 = 0i64;
        do
        {
          v88 = p_m_vertices->m_size;
          v89 = v61->m_vertices.m_data;
          ++v85;
          ++v87;
          p_m_vertices->m_size = v88 + 1;
          p_m_vertices->m_data[v88].m_quad = _mm_add_ps(v86->m_quad, v89[v87 - 1].m_quad);
        }
        while ( v85 < v61->m_vertices.m_size );
        v64 = v135.m_enum;
      }
      v90 = p_m_faces->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v90 < v61->m_faces.m_size )
      {
        if ( p_m_faces->m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            p_m_faces->m_data,
            12 * v90);
        v134 = 12 * v61->m_faces.m_size;
        p_m_faces->m_data = (hkaiEdgeGeometry::Face *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                        &hkContainerHeapAllocator::s_alloc,
                                                        &v134);
        p_m_faces->m_capacityAndFlags = v134 / 12;
      }
      v91 = v61->m_faces.m_size;
      v92 = (char *)p_m_faces->m_data;
      p_m_faces->m_size = v91;
      v93 = v91;
      if ( (int)v91 > 0 )
      {
        v94 = (char *)v61->m_faces.m_data - v92;
        do
        {
          v95 = *(_DWORD *)&v92[v94];
          v92 += 12;
          *((_DWORD *)v92 - 3) = v95;
          *((_DWORD *)v92 - 2) = *(_DWORD *)&v92[v94 - 8];
          *((_DWORD *)v92 - 1) = *(_DWORD *)&v92[v94 - 4];
          --v93;
        }
        while ( v93 );
      }
      v96 = p_m_faces->m_capacityAndFlags;
      normalOut.m_quad.m128_i8[8] = 8;
      v97 = v96 & 0x3FFFFFFF;
      if ( v97 < v68 )
      {
        v98 = 2 * v97;
        v99 = v68;
        if ( v68 < v98 )
          v99 = v98;
        hkArrayUtil::_reserve(&v137, &hkContainerHeapAllocator::s_alloc, p_m_faces, v99, 12);
      }
      v100 = p_m_faces->m_size;
      v101 = (__int64)&p_m_faces->m_data[v100];
      if ( v68 - (int)v100 > 0 )
      {
        v102 = normalOut.m_quad.m128_i32[2];
        *(_QWORD *)v101 = 0i64;
        v103 = (_DWORD *)(v101 + 12);
        *(_DWORD *)(v101 + 8) = v102;
        for ( j = (unsigned __int64)(12i64 * (v68 - (int)v100) - 12) >> 2; j; --j )
        {
          *v103 = *(_DWORD *)v101;
          v101 += 4i64;
          ++v103;
        }
      }
      p_m_faces->m_size = v68;
      v105 = v139;
      if ( v139 <= 0 )
      {
        v117 = v138;
      }
      else
      {
        v106 = 0i64;
        do
        {
          v107 = p_m_edges->m_size;
          v108 = v107 + 1;
          v109 = p_m_edges->m_capacityAndFlags & 0x3FFFFFFF;
          v110 = &v61->m_edges.m_data[v106];
          if ( v109 >= (int)v107 + 1 )
          {
            v137.m_enum = HK_SUCCESS;
          }
          else
          {
            v111 = 2 * v109;
            if ( v108 < v111 )
              v108 = v111;
            hkArrayUtil::_reserve(&v137, &hkContainerHeapAllocator::s_alloc, p_m_edges, v108, 16);
          }
          ++p_m_edges->m_size;
          v112 = &p_m_edges->m_data[v107];
          v112->m_a = v110->m_a;
          v112->m_b = v110->m_b;
          v112->m_face = v110->m_face;
          v112->m_data = v110->m_data;
          v113 = p_m_edges->m_size;
          v114 = v113 + 1;
          v115 = p_m_edges->m_capacityAndFlags & 0x3FFFFFFF;
          if ( v115 >= (int)v113 + 1 )
          {
            v135.m_enum = HK_SUCCESS;
          }
          else
          {
            v116 = 2 * v115;
            if ( v114 < v116 )
              v114 = v116;
            hkArrayUtil::_reserve(&v135, &hkContainerHeapAllocator::s_alloc, p_m_edges, v114, 16);
          }
          ++p_m_edges->m_size;
          v117 = v138;
          ++v106;
          v118 = &p_m_edges->m_data[v113];
          v118->m_a = v138 + v110->m_a;
          v118->m_b = v117 + v110->m_b;
          v118->m_face = v64 + v110->m_face - 1;
          v118->m_data = v110->m_data;
          --v105;
        }
        while ( v105 );
      }
      v119 = v140;
      v120 = 0i64;
      if ( (__int64)v140 > 0 )
      {
        v121 = this;
        do
        {
          v122 = v121->m_edgeToSideFaceMap.m_data[v120];
          if ( v122 >= 0 )
          {
            v123 = v141.m_enum + v122;
            v124 = v121->m_uniqueEdges.m_startUniqueEdge.m_data[v120];
            v125 = **(_DWORD **)v124;
            m_b = (*v124)->m_b;
            v127 = p_m_edges->m_size + 4;
            v135.m_enum = p_m_edges->m_size;
            v128 = p_m_edges->m_capacityAndFlags & 0x3FFFFFFF;
            v129 = m_b + v117;
            v130 = v125 + v117;
            if ( v128 >= v127 )
            {
              v137.m_enum = HK_SUCCESS;
            }
            else
            {
              v131 = 2 * v128;
              if ( v127 < v131 )
                v127 = v131;
              hkArrayUtil::_reserve(&v137, &hkContainerHeapAllocator::s_alloc, p_m_edges, v127, 16);
              v119 = v140;
              v117 = v138;
            }
            p_m_edges->m_size += 4;
            v121 = this;
            v132 = &p_m_edges->m_data[v135.m_enum];
            v132->m_a = v125;
            v132[1].m_a = m_b;
            v132->m_b = m_b;
            v132->m_face = v123;
            v132->m_data = 0;
            v132[1].m_b = v129;
            v132[1].m_face = v123;
            v132[1].m_data = 0;
            v132[2].m_a = v129;
            v132[2].m_b = v130;
            v132[2].m_face = v123;
            v132[2].m_data = 0;
            v132[3].m_a = v130;
            v132[3].m_b = v125;
            v132[3].m_face = v123;
            v132[3].m_data = 0;
          }
          ++v120;
        }
        while ( v120 < (__int64)v119 );
      }
      v45 = result;
      result->m_enum = HK_SUCCESS;
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
}

// File Line: 724
// RVA: 0xB9D780
void __fastcall hkaiGeometryExtrudeUtil::IndexMap::IndexMap(hkaiGeometryExtrudeUtil::IndexMap *this)
{
  this->m_map.m_capacityAndFlags = 0x80000000;
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
hkResult *__fastcall hkaiGeometryExtrudeUtil::IndexMap::init(
        hkaiGeometryExtrudeUtil::IndexMap *this,
        hkResult *result,
        int size)
{
  int v5; // eax
  int v7; // eax
  int v8; // r9d
  hkResult *v9; // rax
  int v10; // eax
  int v11; // eax
  int v12; // r9d
  int v13; // edx
  int *v14; // rdi
  __int64 v15; // rcx
  hkResult v16; // [rsp+50h] [rbp+8h] BYREF
  hkResult resulta; // [rsp+60h] [rbp+18h] BYREF

  v5 = this->m_map.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 >= size )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    v7 = 2 * v5;
    v8 = size;
    if ( size < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &this->m_map, v8, 4);
    if ( resulta.m_enum )
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  v10 = this->m_map.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < size )
  {
    v11 = 2 * v10;
    v12 = size;
    if ( size < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&v16, &hkContainerHeapAllocator::s_alloc, &this->m_map, v12, 4);
  }
  v13 = size - this->m_map.m_size;
  v14 = &this->m_map.m_data[this->m_map.m_size];
  v15 = v13;
  if ( v13 > 0 )
  {
    while ( v15 )
    {
      *v14++ = -1;
      --v15;
    }
  }
  this->m_map.m_size = size;
  result->m_enum = HK_SUCCESS;
  v9 = result;
  this->m_freeIndex = 0;
  return v9;
}

// File Line: 744
// RVA: 0xB9D8B0
__int64 __fastcall hkaiGeometryExtrudeUtil::IndexMap::add(hkaiGeometryExtrudeUtil::IndexMap *this, int index)
{
  int *v2; // r8
  __int64 result; // rax
  unsigned int v4; // edx

  v2 = &this->m_map.m_data[index];
  result = (unsigned int)*v2;
  if ( (int)result < 0 )
  {
    v4 = this->m_freeIndex++;
    *v2 = v4;
    return v4;
  }
  return result;
}


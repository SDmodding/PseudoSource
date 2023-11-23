// File Line: 28
// RVA: 0x12F2F60
void __fastcall hkaiSegmentCastingUtil::fillEdgeList_extrudedEdge(
        hkVector4f *v1,
        hkVector4f *v2,
        hkVector4f *extrusion,
        hkArray<hkVector4f,hkContainerHeapAllocator> *edgeList)
{
  __int64 m_size; // rdi
  int m_capacityAndFlags; // eax
  int v8; // r9d
  int v10; // eax
  int v12; // eax
  __m128 m_quad; // xmm3
  __m128 v14; // xmm2
  hkVector4f *v15; // rax
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  m_size = edgeList->m_size;
  m_capacityAndFlags = edgeList->m_capacityAndFlags;
  v8 = m_size + 8;
  v10 = m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < (int)m_size + 8 )
  {
    v12 = 2 * v10;
    if ( v8 < v12 )
      v8 = v12;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&edgeList->m_data, v8, 16);
  }
  edgeList->m_size += 8;
  m_quad = v2->m_quad;
  v14 = v1->m_quad;
  v15 = &edgeList->m_data[m_size];
  v16 = _mm_add_ps(v1->m_quad, extrusion->m_quad);
  v17 = _mm_add_ps(extrusion->m_quad, v2->m_quad);
  *v15 = (hkVector4f)v1->m_quad;
  v15[1] = (hkVector4f)m_quad;
  v15[2] = (hkVector4f)m_quad;
  v15[5] = (hkVector4f)v16;
  v15[6] = (hkVector4f)v16;
  v15[3] = (hkVector4f)v17;
  v15[4] = (hkVector4f)v17;
  v15[7] = (hkVector4f)v14;
}

// File Line: 47
// RVA: 0x12F3020
void __fastcall hkaiSegmentCastingUtil::fillEdgeList_triangle(
        hkVector4f *v1,
        hkVector4f *v2,
        hkVector4f *v3,
        hkArray<hkVector4f,hkContainerHeapAllocator> *edgeList)
{
  __int64 m_size; // rdi
  int m_capacityAndFlags; // eax
  int v8; // r9d
  int v10; // eax
  int v12; // eax
  hkVector4f *v13; // rax
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  m_size = edgeList->m_size;
  m_capacityAndFlags = edgeList->m_capacityAndFlags;
  v8 = m_size + 6;
  v10 = m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < (int)m_size + 6 )
  {
    v12 = 2 * v10;
    if ( v8 < v12 )
      v8 = v12;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&edgeList->m_data, v8, 16);
  }
  edgeList->m_size += 6;
  v13 = &edgeList->m_data[m_size];
  *v13 = (hkVector4f)v1->m_quad;
  v13[1] = (hkVector4f)v2->m_quad;
  v13[2] = (hkVector4f)v2->m_quad;
  v13[3] = (hkVector4f)v3->m_quad;
  v13[4] = (hkVector4f)v3->m_quad;
  v13[5] = (hkVector4f)v1->m_quad;
}

// File Line: 58
// RVA: 0x12F30D0
void __fastcall hkaiSegmentCastingUtil::fillEdgeList_geometry(
        hkGeometry *geometry,
        int triangleIndex,
        hkArray<hkVector4f,hkContainerHeapAllocator> *edgeList)
{
  hkVector4f *m_data; // r9
  hkGeometry::Triangle *v4; // rdx
  __int64 m_b; // rax
  __m128 m_quad; // xmm0
  __int64 m_c; // rax
  hkVector4f v1; // [rsp+20h] [rbp-38h] BYREF
  hkVector4f v2; // [rsp+30h] [rbp-28h] BYREF
  hkVector4f v3; // [rsp+40h] [rbp-18h] BYREF

  m_data = geometry->m_vertices.m_data;
  v4 = &geometry->m_triangles.m_data[triangleIndex];
  m_b = v4->m_b;
  v1.m_quad = (__m128)m_data[v4->m_a];
  m_quad = m_data[m_b].m_quad;
  m_c = v4->m_c;
  v2.m_quad = m_quad;
  v3.m_quad = (__m128)m_data[m_c];
  hkaiSegmentCastingUtil::fillEdgeList_triangle(&v1, &v2, &v3, edgeList);
}

// File Line: 69
// RVA: 0x12F3140
void __fastcall hkaiSegmentCastingUtil::fillEdgeList_edgeGeometry(
        hkaiEdgeGeometry *edgeGeometry,
        hkaiFaceEdges *faceEdges,
        int faceIndex,
        hkArray<hkVector4f,hkContainerHeapAllocator> *edgeList)
{
  hkaiEdgeGeometry::Edge *const **m_data; // rax
  int **v6; // rsi
  int **v7; // rdi
  int v8; // eax
  int v10; // edx
  int v11; // eax
  int *v12; // rdx
  hkResult result; // [rsp+50h] [rbp+18h] BYREF

  m_data = faceEdges->m_faceStartEdges.m_data;
  v6 = (int **)m_data[faceIndex + 1];
  v7 = (int **)m_data[faceIndex];
  v8 = edgeList->m_capacityAndFlags & 0x3FFFFFFF;
  v10 = 2 * (v6 - v7);
  if ( v8 < v10 )
  {
    v11 = 2 * v8;
    if ( v10 < v11 )
      v10 = v11;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&edgeList->m_data, v10, 16);
  }
  for ( ; v7 != v6; ++edgeList->m_size )
  {
    v12 = *v7++;
    edgeList->m_data[edgeList->m_size++] = edgeGeometry->m_vertices.m_data[*v12];
    edgeList->m_data[edgeList->m_size] = edgeGeometry->m_vertices.m_data[v12[1]];
  }
}

// File Line: 88
// RVA: 0x12F3220
void __fastcall hkaiSegmentCastingUtil::fillEdgeList_navMesh(
        hkaiNavMesh *navMesh,
        int faceIndex,
        hkArray<hkVector4f,hkContainerHeapAllocator> *edgeList)
{
  hkaiNavMesh::Face *v5; // rax
  __int64 m_numEdges; // rsi
  __int64 m_startEdgeIndex; // rbp
  int v8; // r9d
  int v9; // eax
  int v10; // eax
  __int64 v11; // r9
  __int64 v12; // r8
  hkaiNavMesh::Edge *m_data; // rdx
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  v5 = &navMesh->m_faces.m_data[faceIndex];
  m_numEdges = v5->m_numEdges;
  m_startEdgeIndex = v5->m_startEdgeIndex;
  v8 = 2 * m_numEdges;
  v9 = edgeList->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < 2 * (int)m_numEdges )
  {
    v10 = 2 * v9;
    if ( v8 < v10 )
      v8 = v10;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&edgeList->m_data, v8, 16);
  }
  v11 = m_numEdges;
  if ( (int)m_numEdges > 0 )
  {
    v12 = m_startEdgeIndex;
    do
    {
      m_data = navMesh->m_edges.m_data;
      edgeList->m_data[edgeList->m_size++] = navMesh->m_vertices.m_data[m_data[v12++].m_a];
      edgeList->m_data[edgeList->m_size++] = navMesh->m_vertices.m_data[m_data[v12 - 1].m_b];
      --v11;
    }
    while ( v11 );
  }
}

// File Line: 105
// RVA: 0x12F3310
void __fastcall hkaiSegmentCastingUtil::fillEdgeList_navMeshInstance(
        hkaiNavMeshInstance *navMeshInstance,
        int faceIndex,
        hkArray<hkVector4f,hkContainerHeapAllocator> *edgeList)
{
  hkaiNavMesh::Face *v5; // rax
  int m_numEdges; // r15d
  int m_startEdgeIndex; // ecx
  int v8; // r9d
  int v9; // eax
  int v10; // eax
  int i; // esi
  hkaiNavMesh::Edge *v12; // r14
  hkVector4f *v13; // rcx
  __int64 m_a; // rax
  int m_numOriginalVertices; // edx
  hkVector4f *v16; // rax
  hkVector4f *v17; // rcx
  __int64 m_b; // rax
  int v19; // edx
  hkVector4f *v20; // rax
  int v21; // [rsp+70h] [rbp+8h]
  hkResult result; // [rsp+80h] [rbp+18h] BYREF

  v5 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__24(
         navMeshInstance->m_originalFaces,
         navMeshInstance->m_numOriginalFaces,
         &navMeshInstance->m_instancedFaces,
         &navMeshInstance->m_ownedFaces,
         &navMeshInstance->m_faceMap,
         faceIndex);
  m_numEdges = v5->m_numEdges;
  m_startEdgeIndex = v5->m_startEdgeIndex;
  v8 = 2 * m_numEdges;
  v9 = edgeList->m_capacityAndFlags & 0x3FFFFFFF;
  v21 = m_startEdgeIndex;
  if ( v9 < 2 * m_numEdges )
  {
    v10 = 2 * v9;
    if ( v8 < v10 )
      v8 = v10;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&edgeList->m_data, v8, 16);
    m_startEdgeIndex = v21;
  }
  for ( i = 0; i < m_numEdges; m_startEdgeIndex = v21 )
  {
    v12 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__25(
            navMeshInstance->m_originalEdges,
            navMeshInstance->m_numOriginalEdges,
            &navMeshInstance->m_instancedEdges,
            &navMeshInstance->m_ownedEdges,
            &navMeshInstance->m_edgeMap,
            i + m_startEdgeIndex);
    if ( edgeList->m_size == (edgeList->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&edgeList->m_data, 16);
    v13 = &edgeList->m_data[edgeList->m_size++];
    m_a = v12->m_a;
    m_numOriginalVertices = navMeshInstance->m_numOriginalVertices;
    if ( (int)m_a >= m_numOriginalVertices )
      v16 = &navMeshInstance->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices];
    else
      v16 = &navMeshInstance->m_originalVertices[m_a];
    *v13 = (hkVector4f)v16->m_quad;
    if ( edgeList->m_size == (edgeList->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&edgeList->m_data, 16);
    v17 = &edgeList->m_data[edgeList->m_size++];
    m_b = v12->m_b;
    v19 = navMeshInstance->m_numOriginalVertices;
    if ( (int)m_b >= v19 )
      v20 = &navMeshInstance->m_ownedVertices.m_data[(int)m_b - v19];
    else
      v20 = &navMeshInstance->m_originalVertices[m_b];
    ++i;
    *v17 = (hkVector4f)v20->m_quad;
  }
}

// File Line: 127
// RVA: 0x12F34E0
_BOOL8 __fastcall hkaiSegmentCastingUtil::intersectSweptSegmentFaceAux(
        hkVector4f *leftStartIn,
        hkVector4f *rightStartIn,
        hkVector4f *displacement,
        hkArray<hkVector4f,hkContainerHeapAllocator> *edgeList,
        hkVector4f *faceNormal,
        unsigned int data,
        hkaiIntervalPartition *partition)
{
  __m128 m_quad; // xmm5
  hkVector4f v11; // xmm8
  hkVector4f v12; // xmm7
  __m128 v13; // xmm4
  __m128 v14; // xmm4
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  hkVector4f v18; // xmm6
  hkVector4f v19; // xmm10
  hkVector4f v20; // xmm11
  hkVector4f v21; // xmm12
  __m128 v22; // xmm2
  __m128 v23; // xmm4
  __m128 v24; // xmm1
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  float v29; // xmm6_4
  __m128 v30; // xmm1
  __m128 v31; // xmm0
  __m128 v32; // xmm4
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  float v38; // xmm8_4
  float v39; // xmm7_4
  int m_size; // r9d
  float *v41; // r10
  int v42; // r8d
  int v43; // eax
  __int64 v44; // r11
  hkVector4f v45; // xmm9
  __int64 v46; // rdx
  __int64 v47; // r9
  __m128 v48; // xmm1
  __m128 v49; // xmm2
  __m128 v50; // xmm4
  __m128 v51; // xmm3
  __m128 v52; // xmm5
  __m128 v53; // xmm0
  __m128 v54; // xmm1
  __m128 v55; // xmm0
  BOOL v56; // ebx
  float v57; // xmm0_4
  int i; // ebx
  float v59; // xmm0_4
  int v60; // [rsp+30h] [rbp-D0h]
  float v61; // [rsp+34h] [rbp-CCh]
  float v62; // [rsp+38h] [rbp-C8h]
  float *array; // [rsp+40h] [rbp-C0h] BYREF
  int v64; // [rsp+48h] [rbp-B8h]
  int v65; // [rsp+4Ch] [rbp-B4h]
  char v66; // [rsp+50h] [rbp-B0h]
  char v67; // [rsp+51h] [rbp-AFh]
  float v68; // [rsp+58h] [rbp-A8h]
  int v69; // [rsp+60h] [rbp-A0h]
  hkResult v70; // [rsp+64h] [rbp-9Ch] BYREF
  int v71; // [rsp+68h] [rbp-98h]
  float v72; // [rsp+70h] [rbp-90h]
  float v73; // [rsp+78h] [rbp-88h]
  float v74; // [rsp+80h] [rbp-80h]
  float v75; // [rsp+88h] [rbp-78h]
  int v76; // [rsp+90h] [rbp-70h]
  int v77; // [rsp+98h] [rbp-68h]
  int v78; // [rsp+A0h] [rbp-60h]
  int v79; // [rsp+A8h] [rbp-58h]
  float v80; // [rsp+B0h] [rbp-50h]
  hkaiIntervalPartition::Interval v81; // [rsp+B8h] [rbp-48h] BYREF
  hkaiIntervalPartition::Interval interval; // [rsp+D0h] [rbp-30h] BYREF
  hkaiIntervalPartition::Interval v83; // [rsp+E8h] [rbp-18h] BYREF
  hkResult result; // [rsp+100h] [rbp+0h] BYREF
  hkMatrix4f out; // [rsp+110h] [rbp+10h] BYREF
  hkSimdFloat32 epsilon; // [rsp+150h] [rbp+50h] BYREF
  hkMatrix4f m; // [rsp+160h] [rbp+60h] BYREF
  __m128 v88; // [rsp+1A0h] [rbp+A0h]
  __m128 v89; // [rsp+1B0h] [rbp+B0h]
  __m128 v90; // [rsp+1C0h] [rbp+C0h]
  __m128 v91; // [rsp+1D0h] [rbp+D0h]
  __m128 v92; // [rsp+1E0h] [rbp+E0h]
  __m128 v93; // [rsp+1F0h] [rbp+F0h]
  __m128 v94; // [rsp+200h] [rbp+100h]

  m_quad = displacement->m_quad;
  if ( (_mm_movemask_ps(_mm_cmpeq_ps((__m128)0i64, displacement->m_quad)) & 7) == 7 )
    return 0i64;
  v11.m_quad = _mm_shuffle_ps(leftStartIn->m_quad, _mm_unpackhi_ps(leftStartIn->m_quad, query.m_quad), 196);
  v12.m_quad = _mm_sub_ps(
                 _mm_shuffle_ps(rightStartIn->m_quad, _mm_unpackhi_ps(rightStartIn->m_quad, query.m_quad), 196),
                 v11.m_quad);
  v13 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v12.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v12.m_quad, v12.m_quad, 201), m_quad));
  v14 = _mm_shuffle_ps(v13, v13, 201);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rsqrt_ps(v16);
  v88 = v16;
  v18.m_quad = (__m128)_mm_srli_si128(
                         _mm_slli_si128(
                           (__m128i)_mm_mul_ps(
                                      _mm_andnot_ps(
                                        _mm_cmple_ps(v16, (__m128)0i64),
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v17))),
                                      v14),
                           4),
                         4);
  if ( (_mm_movemask_ps(_mm_cmplt_ps((__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v18.m_quad, 1u), 1u), *(__m128 *)&::epsilon)) & 7) == 7 )
    return 0i64;
  v71 = 981668463;
  m.m_col0 = (hkVector4f)v12.m_quad;
  m.m_col1.m_quad = m_quad;
  epsilon.m_real = _mm_shuffle_ps((__m128)0x3A83126Fu, (__m128)0x3A83126Fu, 0);
  m.m_col2 = (hkVector4f)v18.m_quad;
  m.m_col3 = (hkVector4f)v11.m_quad;
  __hkMatrix4UtilAlgo::setInverse(&result, &m, &out, &epsilon);
  v19.m_quad = (__m128)out.m_col1;
  v69 = 981668463;
  v20.m_quad = (__m128)out.m_col0;
  v21.m_quad = (__m128)out.m_col2;
  v22 = _mm_mul_ps(edgeList->m_data->m_quad, faceNormal->m_quad);
  v23 = _mm_shuffle_ps(
          faceNormal->m_quad,
          _mm_unpackhi_ps(
            faceNormal->m_quad,
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                _mm_shuffle_ps(v22, v22, 170)))),
          196);
  v24 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v18.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v18.m_quad, v18.m_quad, 201), v23));
  v25 = _mm_shuffle_ps(v24, v24, 201);
  v26 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), out.m_col1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), out.m_col0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), out.m_col2.m_quad));
  v27 = _mm_shuffle_ps(v26, v26, 0);
  if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(v27.m128_f32[0] - 0.0)) >> 1) < _mm_shuffle_ps(
                                                                                    (__m128)0x3A83126Fu,
                                                                                    (__m128)0x3A83126Fu,
                                                                                    0).m128_f32[0] )
    return 0i64;
  v28 = _mm_rcp_ps(v27);
  v89 = v27;
  v29 = 0.0;
  v30 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v27, v28)), v28);
  v31 = v23;
  v32 = _mm_mul_ps(v23, displacement->m_quad);
  v33 = _mm_mul_ps(v31, v11.m_quad);
  v90 = _mm_mul_ps(v30, _mm_shuffle_ps(v26, v26, 85));
  v62 = v90.m128_f32[0];
  v34 = _mm_add_ps(_mm_shuffle_ps(v33, v33, 78), v33);
  v35 = _mm_sub_ps((__m128)0i64, _mm_add_ps(_mm_shuffle_ps(v34, v34, 177), v34));
  v36 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)), _mm_shuffle_ps(v32, v32, 170));
  v37 = _mm_rcp_ps(v36);
  v92 = v36;
  v91 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v37, v36)), v37), v35);
  v61 = v91.m128_f32[0];
  if ( v90.m128_f32[0] <= 0.0 )
  {
    if ( v90.m128_f32[0] >= 0.0 )
    {
      if ( v91.m128_f32[0] < 0.0 || v91.m128_f32[0] > 1.0 )
        return 0i64;
      v39 = 0.0;
      v38 = *(float *)&FLOAT_1_0;
      goto LABEL_16;
    }
    v76 = 0;
    v78 = 1065353216;
    v74 = (float)(1.0 - v91.m128_f32[0]) * (float)(1.0 / v90.m128_f32[0]);
    v39 = fmaxf(v74, 0.0);
    LODWORD(v75) = COERCE_UNSIGNED_INT((float)(1.0 / v90.m128_f32[0]) * v91.m128_f32[0]) ^ _xmm[0];
    v38 = fminf(v75, 1.0);
  }
  else
  {
    v77 = 0;
    v79 = 1065353216;
    v72 = (float)(1.0 - v91.m128_f32[0]) * (float)(1.0 / v90.m128_f32[0]);
    v38 = fminf(v72, 1.0);
    LODWORD(v80) = COERCE_UNSIGNED_INT((float)(1.0 / v90.m128_f32[0]) * v91.m128_f32[0]) ^ _xmm[0];
    v39 = fmaxf(v80, 0.0);
  }
  if ( v38 <= v39 )
    return 0i64;
LABEL_16:
  m_size = edgeList->m_size;
  v65 = 0x80000000;
  v41 = 0i64;
  array = 0i64;
  v42 = 0;
  v64 = 0;
  if ( m_size <= 0 )
  {
    v70.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v70, &hkContainerTempAllocator::s_alloc, (const void **)&array, m_size, 4);
    v42 = v64;
    v41 = array;
    v21.m_quad = (__m128)out.m_col2;
    v19.m_quad = (__m128)out.m_col1;
    v20.m_quad = (__m128)out.m_col0;
  }
  v43 = edgeList->m_size / 2;
  v44 = v43;
  if ( v43 > 0 )
  {
    v45.m_quad = (__m128)out.m_col3;
    v46 = 0i64;
    v47 = 1i64;
    do
    {
      v48 = edgeList->m_data[v46].m_quad;
      v49 = edgeList->m_data[v47].m_quad;
      v50 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v48, v48, 0), v20.m_quad), v45.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v48, v48, 85), v19.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v48, v48, 170), v21.m_quad));
      v51 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v49, v49, 0), v20.m_quad), v45.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v49, v49, 85), v19.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v49, v49, 170), v21.m_quad));
      v52 = _mm_shuffle_ps(v50, v50, 170);
      v53 = _mm_shuffle_ps(v51, v51, 170);
      if ( v52.m128_f32[0] >= 0.0 != v53.m128_f32[0] >= 0.0 )
      {
        v64 = v42 + 1;
        v54 = _mm_sub_ps(v52, v53);
        v67 = 0;
        v55 = _mm_rcp_ps(v54);
        v94 = v54;
        v93 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v54, v55)), v55), v52);
        v41[v42] = (float)((float)(v51.m128_f32[0] - v50.m128_f32[0]) * v93.m128_f32[0]) + v50.m128_f32[0];
        v45.m_quad = (__m128)out.m_col3;
        v21.m_quad = (__m128)out.m_col2;
        v19.m_quad = (__m128)out.m_col1;
        v42 = v64;
        v41 = array;
        v20.m_quad = (__m128)out.m_col0;
      }
      v46 += 2i64;
      v47 += 2i64;
      --v44;
    }
    while ( v44 );
  }
  if ( v42 )
  {
    v66 = 0;
    if ( v42 > 1 )
    {
      hkAlgorithm::quickSortRecursive<float,hkAlgorithm::less<float>>(v41, 0, v42 - 1, 0);
      v42 = v64;
    }
    v60 = 0;
    v57 = 0.0;
    for ( i = v42 / 2; v60 < i; ++v60 )
    {
      v57 = array[2 * v60 + 1];
      if ( v57 > v39 )
        break;
    }
    if ( v60 < i )
    {
      v29 = array[2 * v60];
      if ( v29 < v39 )
      {
        v73 = v57;
        interval.m_data = data;
        v68 = v38;
        interval.m_leftX = v39;
        interval.m_slope = v62;
        interval.m_offset = v61;
        interval.m_rightX = fminf(v38, v57);
        if ( v39 != interval.m_rightX )
        {
          hkaiIntervalPartition::appendInterval(partition, &interval);
          ++v60;
        }
      }
    }
    for ( ; v60 < i; ++v60 )
    {
      v29 = array[2 * v60];
      v59 = array[2 * v60 + 1];
      if ( v59 > v38 )
        break;
      if ( v29 != v59 )
      {
        v83.m_rightX = array[2 * v60 + 1];
        v83.m_data = data;
        v83.m_slope = v62;
        v83.m_leftX = v29;
        v83.m_offset = v61;
        hkaiIntervalPartition::appendInterval(partition, &v83);
      }
    }
    if ( v60 < i && v29 < v38 )
    {
      v81.m_data = data;
      v81.m_slope = v62;
      v81.m_offset = v61;
      v81.m_leftX = v29;
      v81.m_rightX = v38;
      hkaiIntervalPartition::appendInterval(partition, &v81);
    }
    v41 = array;
    v56 = partition->m_intervals.m_size > 0;
  }
  else
  {
    v56 = 0;
  }
  v64 = 0;
  if ( v65 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v41, 4 * v65);
  return v56;
}

// File Line: 358
// RVA: 0x12F3CC0
_BOOL8 __fastcall hkaiSegmentCastingUtil::calcHyperbolaEqIneqRegion(
        hkVector4f *ABCD1,
        hkVector4f *ABCD2,
        hkaiIntervalPartition *ip)
{
  __m128 m_quad; // xmm3
  __m128 v5; // xmm4
  __m128 v6; // xmm1
  __m128 v8; // xmm6
  __m128 v9; // xmm6
  __m128 v10; // xmm1
  __m128 v11; // xmm7
  __m128 v12; // xmm1
  __m128 v13; // xmm9
  __m128 v14; // xmm7
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  __m128 v17; // xmm4
  __m128 v18; // xmm11
  __m128i v19; // xmm12
  __m128 v20; // xmm7
  __m128 v21; // xmm5
  __m128 v22; // xmm6
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm4
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  __m128 v28; // xmm0
  __m128 v29; // xmm1
  __m128 v30; // xmm5
  __m128 v31; // xmm2
  __m128 v32; // xmm4
  __m128 v33; // xmm1
  __m128 v34; // xmm0
  __m128 v35; // xmm1
  __m128 v36; // xmm0
  __m128 v37; // xmm6
  __m128 v38; // xmm1
  __m128 v39; // xmm0
  __m128 v40; // xmm6
  __m128 v41; // xmm1
  __m128 v42; // xmm0
  __m128 v43; // xmm6
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm0_4
  float v47; // xmm6_4
  hkaiIntervalPartition::Interval interval; // [rsp+20h] [rbp-98h] BYREF

  m_quad = ABCD1->m_quad;
  v5 = _mm_shuffle_ps(m_quad, m_quad, 0);
  if ( v5.m128_f32[0] == 0.0 )
  {
    v6 = _mm_shuffle_ps(m_quad, m_quad, 170);
    if ( v6.m128_f32[0] == 0.0 )
      return 0i64;
    v8 = _mm_cmplt_ps((__m128)0i64, v6);
    v9 = _mm_or_ps(_mm_and_ps(v8, (__m128)xmmword_141A712F0), _mm_andnot_ps(v8, (__m128)xmmword_141A712A0));
  }
  else
  {
    v10 = _mm_rcp_ps(v5);
    v9 = _mm_mul_ps(
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v10, v5)), v10),
           _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(m_quad, m_quad, 170)));
  }
  v11 = ABCD2->m_quad;
  v12 = _mm_shuffle_ps(v11, v11, 27);
  v13 = _mm_cmple_ps((__m128)0i64, v5);
  v14 = _mm_mul_ps(_mm_shuffle_ps(v11, v11, 177), m_quad);
  v15 = _mm_mul_ps(_mm_mul_ps(v12, m_quad), (__m128)xmmword_141A71320);
  v16 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 78), v15);
  v17 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 177), v16);
  v18 = _mm_sub_ps(_mm_shuffle_ps(v14, v14, 0), _mm_shuffle_ps(v14, v14, 85));
  v19 = (__m128i)_mm_mul_ps(v17, (__m128)xmmword_141A711B0);
  v20 = _mm_sub_ps(_mm_shuffle_ps(v14, v14, 170), _mm_shuffle_ps(v14, v14, 255));
  if ( v18.m128_f32[0] == 0.0 )
  {
    if ( v17.m128_f32[0] == 0.0 )
    {
      v21 = _mm_cmplt_ps((__m128)0i64, v20);
      v22 = _mm_movelh_ps(
              _mm_unpacklo_ps(
                v9,
                _mm_or_ps(_mm_andnot_ps(v13, (__m128)xmmword_141A712F0), _mm_and_ps(v13, (__m128)xmmword_141A712A0))),
              _mm_unpacklo_ps(
                _mm_or_ps(_mm_andnot_ps(v21, (__m128)xmmword_141A712F0), _mm_and_ps(v21, (__m128)xmmword_141A712A0)),
                (__m128)xmmword_141A712A0));
    }
    else
    {
      v23 = _mm_rcp_ps(v17);
      v24 = _mm_xor_ps(_mm_cmplt_ps((__m128)0i64, v17), v13);
      v22 = _mm_movelh_ps(
              _mm_unpacklo_ps(
                (__m128)xmmword_141A712A0,
                _mm_or_ps(_mm_andnot_ps(v24, (__m128)xmmword_141A712F0), _mm_and_ps(v24, (__m128)xmmword_141A712A0))),
              _mm_unpacklo_ps(
                v9,
                _mm_mul_ps(
                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v17)), v23),
                  _mm_sub_ps((__m128)0i64, v20))));
    }
  }
  else
  {
    v25 = _mm_sub_ps(_mm_mul_ps((__m128)v19, (__m128)v19), _mm_mul_ps(v20, v18));
    if ( v25.m128_f32[0] <= 0.0 )
    {
      v34 = _mm_xor_ps(_mm_cmplt_ps((__m128)0i64, v20), v13);
      v22 = _mm_movelh_ps(
              _mm_unpacklo_ps(
                v9,
                _mm_or_ps(_mm_and_ps(v34, (__m128)xmmword_141A712F0), _mm_andnot_ps(v34, (__m128)xmmword_141A712A0))),
              _mm_unpacklo_ps((__m128)xmmword_141A712A0, (__m128)xmmword_141A712A0));
    }
    else
    {
      v26 = _mm_rsqrt_ps(v25);
      v27 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26));
      v28 = _mm_mul_ps(*(__m128 *)_xmm, v26);
      v29 = _mm_rcp_ps(v18);
      v30 = _mm_xor_ps(_mm_cmplt_ps((__m128)0i64, v18), v13);
      v31 = _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_xor_ps(
                  (__m128)_mm_slli_epi32(_mm_srli_epi32(v19, 0x1Fu), 0x1Fu),
                  _mm_andnot_ps(_mm_cmple_ps(v25, (__m128)0i64), _mm_mul_ps(_mm_mul_ps(v27, v28), v25))),
                (__m128)v19));
      v32 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v29, v18)), v29);
      v33 = _mm_rcp_ps(v31);
      v22 = _mm_movelh_ps(
              _mm_unpacklo_ps(
                _mm_mul_ps(v32, v31),
                _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v33, v31)), v33), v20)),
              _mm_unpacklo_ps(
                v9,
                _mm_or_ps(_mm_and_ps(v30, (__m128)xmmword_141A712F0), _mm_andnot_ps(v30, (__m128)xmmword_141A712A0))));
    }
  }
  v35 = _mm_shuffle_ps(v22, v22, 78);
  v36 = _mm_xor_ps(_mm_cmplt_ps(v22, v35), *(__m128 *)&hkVector4fComparison_maskToComparison_557[48]);
  v37 = _mm_or_ps(_mm_and_ps(v22, v36), _mm_andnot_ps(v36, v35));
  v38 = _mm_shuffle_ps(v37, v37, 177);
  v39 = _mm_xor_ps(_mm_cmplt_ps(v37, v38), *(__m128 *)&hkVector4fComparison_maskToComparison_557[40]);
  v40 = _mm_or_ps(_mm_and_ps(v37, v39), _mm_andnot_ps(v39, v38));
  v41 = _mm_shuffle_ps(v40, v40, 216);
  v42 = _mm_xor_ps(_mm_cmplt_ps(v40, v41), *(__m128 *)&hkVector4fComparison_maskToComparison_557[16]);
  v43 = _mm_or_ps(_mm_and_ps(v40, v42), _mm_andnot_ps(v42, v41));
  v44 = _mm_shuffle_ps(v43, v43, 0).m128_f32[0];
  v45 = _mm_shuffle_ps(v43, v43, 85).m128_f32[0];
  if ( v44 < v45 )
  {
    interval.m_leftX = v44;
    interval.m_rightX = v45;
    *(_QWORD *)&interval.m_slope = 0i64;
    interval.m_data = -1;
    hkaiIntervalPartition::appendInterval(ip, &interval);
  }
  v46 = _mm_shuffle_ps(v43, v43, 170).m128_f32[0];
  v47 = _mm_shuffle_ps(v43, v43, 255).m128_f32[0];
  if ( v46 < v47 )
  {
    interval.m_leftX = v46;
    interval.m_rightX = v47;
    *(_QWORD *)&interval.m_slope = 0i64;
    interval.m_data = -1;
    hkaiIntervalPartition::appendInterval(ip, &interval);
  }
  return ip->m_intervals.m_size != 0;
}

// File Line: 483
// RVA: 0x12F4050
__int64 __fastcall hkaiSegmentCastingUtil::calcHyperbolaInUnitRegion(hkVector4f *ABCD, hkaiIntervalPartition *ip)
{
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm4_4
  float v6; // xmm5_4
  int v8; // xmm5_4
  int v9; // ecx
  int v10; // edx
  float v11; // xmm6_4
  float v12; // xmm2_4
  float v13; // xmm5_4
  float v14; // xmm2_4
  float v15; // xmm4_4
  int v16; // xmm11_4
  int v17; // xmm10_4
  float v18; // xmm7_4
  float v19; // xmm8_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  hkaiIntervalPartition::Interval interval; // [rsp+20h] [rbp-29h] BYREF

  v2 = ABCD->m_quad.m128_f32[0];
  v3 = ABCD->m_quad.m128_f32[1];
  v4 = ABCD->m_quad.m128_f32[2];
  v6 = ABCD->m_quad.m128_f32[3];
  if ( ABCD->m_quad.m128_f32[0] != 0.0 )
  {
    v13 = v6 * (float)(1.0 / v2);
    v14 = v3 * (float)(1.0 / v2);
    v15 = v4 * (float)(1.0 / v2);
    v16 = LODWORD(v15) ^ _xmm[0];
    v17 = LODWORD(v14) ^ _xmm[0];
    v18 = fminf(fmaxf(COERCE_FLOAT(COERCE_UNSIGNED_INT(v13 / v14) ^ _xmm[0]), 0.0), 1.0);
    v19 = fminf(fmaxf((float)(COERCE_FLOAT(LODWORD(v15) ^ _xmm[0]) - v13) / (float)(v14 + 1.0), 0.0), 1.0);
    if ( v13 <= (float)(v15 * v14) )
    {
      if ( *(float *)&v16 > 0.0 && *(float *)&v17 > 0.0 )
      {
        v21 = *(float *)&v17 <= 1.0 ? 0.0 : v19;
        if ( v21 < v18 )
        {
          interval.m_leftX = v21;
          interval.m_rightX = v18;
          *(_QWORD *)&interval.m_slope = 0i64;
          interval.m_data = -1;
          hkaiIntervalPartition::appendInterval(ip, &interval);
        }
      }
      if ( *(float *)&v16 >= 1.0 || *(float *)&v17 >= 1.0 )
        return ip->m_intervals.m_size != 0;
      if ( *(float *)&v17 >= 0.0 )
        v18 = *(float *)&FLOAT_1_0;
      if ( v19 >= v18 )
        return ip->m_intervals.m_size != 0;
      interval.m_leftX = v19;
      interval.m_rightX = v18;
    }
    else
    {
      if ( *(float *)&v16 > 0.0 && *(float *)&v17 < 1.0 )
      {
        v20 = *(float *)&v17 >= 0.0 ? 0.0 : v18;
        if ( v20 < v19 )
        {
          interval.m_leftX = v20;
          interval.m_rightX = v19;
          *(_QWORD *)&interval.m_slope = 0i64;
          interval.m_data = -1;
          hkaiIntervalPartition::appendInterval(ip, &interval);
        }
      }
      if ( *(float *)&v16 >= 1.0 || *(float *)&v17 <= 0.0 )
        return ip->m_intervals.m_size != 0;
      if ( *(float *)&v17 <= 1.0 )
        v19 = *(float *)&FLOAT_1_0;
      if ( v18 >= v19 )
        return ip->m_intervals.m_size != 0;
      interval.m_leftX = v18;
      interval.m_rightX = v19;
    }
    *(_QWORD *)&interval.m_slope = 0i64;
    interval.m_data = -1;
    hkaiIntervalPartition::appendInterval(ip, &interval);
    return ip->m_intervals.m_size != 0;
  }
  if ( v4 == 0.0 )
    return 0i64;
  if ( v3 == 0.0 )
  {
    v8 = LODWORD(v6) ^ _xmm[0];
    v9 = 0;
    v10 = v4 > 0.0;
    if ( *(float *)&v8 > 0.0 != v10 )
      return 0i64;
    LOBYTE(v9) = v4 >= *(float *)&v8;
    if ( v9 != v10 )
      return 0i64;
    interval.m_leftX = 0.0;
    LODWORD(interval.m_rightX) = (_DWORD)FLOAT_1_0;
  }
  else
  {
    v11 = fminf(fmaxf(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(1.0 / v3) * v6) ^ _xmm[0]), 0.0), 1.0);
    v12 = fminf(fmaxf((float)(COERCE_FLOAT(LODWORD(v4) ^ _xmm[0]) - v6) * (float)(1.0 / v3), 0.0), 1.0);
    if ( v11 >= v12 )
    {
      if ( v11 <= v12 )
        return 0i64;
      interval.m_leftX = v12;
      interval.m_rightX = v11;
    }
    else
    {
      interval.m_leftX = v11;
      interval.m_rightX = v12;
    }
  }
  *(_QWORD *)&interval.m_slope = 0i64;
  interval.m_data = -1;
  hkaiIntervalPartition::appendInterval(ip, &interval);
  return 1i64;
}

// File Line: 608
// RVA: 0x12F43B0
__int64 __fastcall hkaiSegmentCastingUtil::intersectTurnedSegmentFaceAux(
        hkVector4f *leftStartIn,
        hkVector4f *rightStartIn,
        hkVector4f *leftEndIn,
        hkVector4f *rightEndIn,
        hkArray<hkVector4f,hkContainerHeapAllocator> *edgeList,
        hkVector4f *faceNormal,
        unsigned int data,
        hkaiIntervalPartition *partition)
{
  __m128 m_quad; // xmm3
  __m128 v9; // xmm7
  __int64 result; // rax
  __m128 v11; // xmm8
  __m128i v12; // xmm9
  __m128 v13; // xmm7
  __m128i v14; // xmm8
  __m128 v15; // xmm2
  __m128 v16; // xmm9
  __m128 v17; // xmm8
  __m128 v18; // xmm5
  __m128 v19; // xmm10
  __m128 v20; // xmm4
  __m128 v21; // xmm3
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm4
  __m128 v26; // xmm0
  __m128 v27; // xmm3
  __int64 v28; // rbx
  int v29; // eax
  __int64 v30; // r14
  __int64 v31; // rsi
  __int64 v32; // rbp
  __m128 v33; // xmm6
  __m128 v34; // xmm6
  __m128 v35; // xmm6
  __m128 v36; // xmm2
  __m128 v37; // xmm5
  __m128 v38; // xmm6
  __m128 v39; // xmm0
  __m128 v40; // xmm3
  __m128 v41; // xmm4
  __m128 v42; // xmm5
  __m128 v43; // xmm4
  __m128 v44; // xmm1
  __m128 v45; // xmm3
  unsigned int v46; // ebx
  hkaiIntervalPartition other; // [rsp+20h] [rbp-A8h] BYREF
  hkVector4f ABCD; // [rsp+30h] [rbp-98h] BYREF
  hkVector4f ABCD2; // [rsp+40h] [rbp-88h] BYREF

  m_quad = leftStartIn->m_quad;
  v9 = leftEndIn->m_quad;
  if ( (_mm_movemask_ps(_mm_cmpeq_ps(leftStartIn->m_quad, leftEndIn->m_quad)) & 7) == 7
    && (_mm_movemask_ps(_mm_cmpeq_ps(rightStartIn->m_quad, rightEndIn->m_quad)) & 7) == 7 )
  {
    return 0i64;
  }
  v11 = _mm_sub_ps(rightEndIn->m_quad, v9);
  v12 = (__m128i)_mm_sub_ps(rightStartIn->m_quad, m_quad);
  v13 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_sub_ps(v9, m_quad), 4), 4);
  v14 = (__m128i)_mm_sub_ps(v11, (__m128)v12);
  v15 = _mm_mul_ps(edgeList->m_data->m_quad, faceNormal->m_quad);
  v16 = (__m128)_mm_srli_si128(_mm_slli_si128(v12, 4), 4);
  v17 = (__m128)_mm_srli_si128(_mm_slli_si128(v14, 4), 4);
  v18 = _mm_shuffle_ps(
          faceNormal->m_quad,
          _mm_unpackhi_ps(
            faceNormal->m_quad,
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                _mm_shuffle_ps(v15, v15, 170)))),
          196);
  v19 = _mm_shuffle_ps(leftStartIn->m_quad, _mm_unpackhi_ps(leftStartIn->m_quad, query.m_quad), 196);
  v20 = _mm_mul_ps(v17, v18);
  v21 = _mm_mul_ps(v13, v18);
  v22 = _mm_mul_ps(v16, v18);
  v23 = _mm_mul_ps(v19, v18);
  v24 = _mm_shuffle_ps(v20, v22, 68);
  v25 = _mm_shuffle_ps(v20, v22, 238);
  v26 = _mm_shuffle_ps(v21, v23, 68);
  v27 = _mm_shuffle_ps(v21, v23, 238);
  ABCD.m_quad = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v24, v26, 221), _mm_shuffle_ps(v24, v26, 136)),
                  _mm_add_ps(_mm_shuffle_ps(v25, v27, 221), _mm_shuffle_ps(v25, v27, 136)));
  result = hkaiSegmentCastingUtil::calcHyperbolaInUnitRegion(&ABCD, partition);
  if ( (_DWORD)result )
  {
    hkaiIntervalPartition::hkaiIntervalPartition(&other);
    v28 = 0i64;
    v29 = edgeList->m_size / 2;
    v30 = v29;
    if ( v29 <= 0 )
    {
LABEL_10:
      hkaiIntervalPartition::setAllData(partition, data);
      v46 = 1;
    }
    else
    {
      v31 = 0i64;
      v32 = 1i64;
      while ( 1 )
      {
        v33 = _mm_sub_ps(edgeList->m_data[v32].m_quad, edgeList->m_data[v31].m_quad);
        v34 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v33, v33, 201), faceNormal->m_quad),
                _mm_mul_ps(_mm_shuffle_ps(faceNormal->m_quad, faceNormal->m_quad, 201), v33));
        v35 = _mm_shuffle_ps(v34, v34, 201);
        v36 = _mm_mul_ps(v35, edgeList->m_data[v31].m_quad);
        v37 = _mm_shuffle_ps(
                v35,
                _mm_unpackhi_ps(
                  v35,
                  _mm_sub_ps(
                    (__m128)0i64,
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                      _mm_shuffle_ps(v36, v36, 170)))),
                196);
        v38 = _mm_mul_ps(v37, v19);
        v39 = _mm_mul_ps(v37, v16);
        v40 = _mm_mul_ps(v37, v13);
        v41 = _mm_mul_ps(v37, v17);
        v42 = _mm_shuffle_ps(v41, v39, 238);
        v43 = _mm_shuffle_ps(v41, v39, 68);
        v44 = _mm_shuffle_ps(v40, v38, 68);
        v45 = _mm_shuffle_ps(v40, v38, 238);
        ABCD2.m_quad = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v42, v45, 221), _mm_shuffle_ps(v42, v45, 136)),
                         _mm_add_ps(_mm_shuffle_ps(v43, v44, 221), _mm_shuffle_ps(v43, v44, 136)));
        if ( !hkaiSegmentCastingUtil::calcHyperbolaEqIneqRegion(&ABCD, &ABCD2, &other) )
          break;
        hkaiIntervalPartition::clipNotDefined(partition, &other);
        if ( !partition->m_intervals.m_size )
          goto LABEL_16;
        hkaiIntervalPartition::clear(&other);
        ++v28;
        v31 += 2i64;
        v32 += 2i64;
        if ( v28 >= v30 )
          goto LABEL_10;
      }
      hkaiIntervalPartition::clear(partition);
LABEL_16:
      v46 = 0;
    }
    other.m_intervals.m_size = 0;
    if ( other.m_intervals.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        other.m_intervals.m_data,
        20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
    return v46;
  }
  return result;
}

// File Line: 689
// RVA: 0x12F1F00
unsigned int __fastcall hkaiSegmentCastingUtil::intersectSweptSegmentFace(
        hkVector4f *leftStartIn,
        hkVector4f *rightStartIn,
        hkVector4f *displacement,
        hkaiEdgeGeometry *edgeGeometry,
        hkaiFaceEdges *faceEdges,
        int faceIdx,
        unsigned int data,
        hkaiIntervalPartition *partition)
{
  unsigned int result; // eax
  unsigned int v13; // ebx
  hkVector4f normalOut; // [rsp+40h] [rbp-128h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> edgeList; // [rsp+50h] [rbp-118h] BYREF
  char v16; // [rsp+60h] [rbp-108h] BYREF

  edgeList.m_data = (hkVector4f *)&v16;
  edgeList.m_size = 0;
  edgeList.m_capacityAndFlags = -2147483632;
  hkaiSegmentCastingUtil::fillEdgeList_edgeGeometry(edgeGeometry, faceEdges, faceIdx, &edgeList);
  hkaiEdgeGeometry::calculateFaceNormal(edgeGeometry, faceEdges, faceIdx, &normalOut);
  result = hkaiSegmentCastingUtil::intersectSweptSegmentFaceAux(
             leftStartIn,
             rightStartIn,
             displacement,
             &edgeList,
             &normalOut,
             data,
             partition);
  edgeList.m_size = 0;
  v13 = result;
  if ( edgeList.m_capacityAndFlags >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      edgeList.m_data,
      16 * edgeList.m_capacityAndFlags);
    return v13;
  }
  return result;
}

// File Line: 708
// RVA: 0x12F2010
unsigned int __fastcall hkaiSegmentCastingUtil::intersectSweptSegmentFace(
        hkVector4f *leftStartIn,
        hkVector4f *rightStartIn,
        hkVector4f *displacement,
        hkaiNavMesh *navMesh,
        unsigned int faceIndex,
        unsigned int data,
        hkaiIntervalPartition *partition)
{
  unsigned int result; // eax
  unsigned int v12; // ebx
  hkVector4f faceNormal; // [rsp+40h] [rbp-138h] BYREF
  hkaiNavMeshUtils v14; // [rsp+50h] [rbp-128h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> edgeList; // [rsp+60h] [rbp-118h] BYREF
  char v16; // [rsp+70h] [rbp-108h] BYREF

  edgeList.m_size = 0;
  edgeList.m_data = (hkVector4f *)&v16;
  edgeList.m_capacityAndFlags = -2147483632;
  hkaiSegmentCastingUtil::fillEdgeList_navMesh(navMesh, faceIndex, &edgeList);
  hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(
    &v14,
    (hkSimdFloat32 *)navMesh,
    (hkaiNavMesh *)faceIndex,
    &faceNormal.m_quad);
  result = hkaiSegmentCastingUtil::intersectSweptSegmentFaceAux(
             leftStartIn,
             rightStartIn,
             displacement,
             &edgeList,
             &faceNormal,
             data,
             partition);
  edgeList.m_size = 0;
  v12 = result;
  if ( edgeList.m_capacityAndFlags >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      edgeList.m_data,
      16 * edgeList.m_capacityAndFlags);
    return v12;
  }
  return result;
}

// File Line: 727
// RVA: 0x12F2120
__int64 __fastcall hkaiSegmentCastingUtil::intersectSweptSegmentFace(
        hkVector4f *leftStartIn,
        hkVector4f *rightStartIn,
        hkVector4f *displacement,
        hkaiNavMeshInstance *navMeshInstance,
        unsigned int faceIndex,
        unsigned int data,
        hkaiIntervalPartition *partition)
{
  unsigned int v12; // eax
  unsigned int v13; // ebx
  hkVector4f faceNormal; // [rsp+40h] [rbp-138h] BYREF
  hkaiNavMeshUtils v15; // [rsp+50h] [rbp-128h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> edgeList; // [rsp+60h] [rbp-118h] BYREF
  char v17; // [rsp+70h] [rbp-108h] BYREF
  char m_storage; // [rsp+198h] [rbp+20h]

  if ( navMeshInstance->m_faceFlags.m_size )
    m_storage = navMeshInstance->m_faceFlags.m_data[faceIndex].m_storage;
  else
    m_storage = 0;
  if ( (m_storage & 1) != 0 )
    return 0i64;
  edgeList.m_data = (hkVector4f *)&v17;
  edgeList.m_size = 0;
  edgeList.m_capacityAndFlags = -2147483632;
  hkaiSegmentCastingUtil::fillEdgeList_navMeshInstance(navMeshInstance, faceIndex, &edgeList);
  hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
    &v15,
    (hkSimdFloat32 *)navMeshInstance,
    (hkaiNavMeshInstance *)faceIndex,
    &faceNormal.m_quad);
  v12 = hkaiSegmentCastingUtil::intersectSweptSegmentFaceAux(
          leftStartIn,
          rightStartIn,
          displacement,
          &edgeList,
          &faceNormal,
          data,
          partition);
  edgeList.m_size = 0;
  v13 = v12;
  if ( edgeList.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      edgeList.m_data,
      16 * edgeList.m_capacityAndFlags);
  return v13;
}

// File Line: 751
// RVA: 0x12F2260
unsigned int __fastcall hkaiSegmentCastingUtil::intersectSweptSegmentFace(
        hkVector4f *leftStartIn,
        hkVector4f *rightStartIn,
        hkVector4f *displacement,
        hkGeometry *geometry,
        int triangleIndex,
        unsigned int data,
        hkaiIntervalPartition *partition)
{
  hkGeometry::Triangle *m_data; // rdx
  hkVector4f *v12; // rcx
  __m128 m_quad; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm5
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  unsigned int result; // eax
  unsigned int v22; // ebx
  hkVector4f faceNormal; // [rsp+40h] [rbp-128h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> edgeList; // [rsp+50h] [rbp-118h] BYREF
  char v25; // [rsp+60h] [rbp-108h] BYREF

  edgeList.m_data = (hkVector4f *)&v25;
  edgeList.m_size = 0;
  edgeList.m_capacityAndFlags = -2147483632;
  hkaiSegmentCastingUtil::fillEdgeList_geometry(geometry, triangleIndex, &edgeList);
  m_data = geometry->m_triangles.m_data;
  v12 = geometry->m_vertices.m_data;
  m_quad = v12[m_data[triangleIndex].m_a].m_quad;
  v14 = _mm_sub_ps(v12[m_data[triangleIndex].m_b].m_quad, m_quad);
  v15 = _mm_sub_ps(v12[m_data[triangleIndex].m_c].m_quad, m_quad);
  v16 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v14), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v15));
  v17 = _mm_shuffle_ps(v16, v16, 201);
  v18 = _mm_mul_ps(v17, v17);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v20 = _mm_rsqrt_ps(v19);
  faceNormal.m_quad = _mm_mul_ps(
                        v17,
                        _mm_andnot_ps(
                          _mm_cmple_ps(v19, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                            _mm_mul_ps(*(__m128 *)_xmm, v20))));
  result = hkaiSegmentCastingUtil::intersectSweptSegmentFaceAux(
             leftStartIn,
             rightStartIn,
             displacement,
             &edgeList,
             &faceNormal,
             data,
             partition);
  v22 = result;
  edgeList.m_size = 0;
  if ( edgeList.m_capacityAndFlags >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      edgeList.m_data,
      16 * edgeList.m_capacityAndFlags);
    return v22;
  }
  return result;
}

// File Line: 774
// RVA: 0x12F23F0
__int64 __fastcall hkaiSegmentCastingUtil::intersectSweptSegmentExtrudedEdge(
        hkVector4f *leftStartIn,
        hkVector4f *rightStartIn,
        hkVector4f *displacement,
        hkVector4f *vertexA,
        hkVector4f *vertexB,
        hkVector4f *extrusion,
        unsigned int data,
        hkaiIntervalPartition *partition)
{
  __m128 v12; // xmm1
  __m128 v13; // xmm5
  __m128i v14; // xmm5
  unsigned int v15; // ebx
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  hkVector4f faceNormal; // [rsp+40h] [rbp-B8h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> edgeList; // [rsp+50h] [rbp-A8h] BYREF
  char v22; // [rsp+60h] [rbp-98h] BYREF

  edgeList.m_data = (hkVector4f *)&v22;
  edgeList.m_size = 0;
  edgeList.m_capacityAndFlags = -2147483640;
  hkaiSegmentCastingUtil::fillEdgeList_extrudedEdge(vertexA, vertexB, extrusion, &edgeList);
  v12 = _mm_sub_ps(vertexB->m_quad, vertexA->m_quad);
  v13 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(extrusion->m_quad, extrusion->m_quad, 201), v12),
          _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), extrusion->m_quad));
  v14 = (__m128i)_mm_shuffle_ps(v13, v13, 201);
  if ( (_mm_movemask_ps(_mm_cmplt_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v14, 1u), 1u), *(__m128 *)&epsilon)) & 7) == 7 )
  {
    v15 = 0;
  }
  else
  {
    v16 = _mm_mul_ps((__m128)v14, (__m128)v14);
    v17 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
            _mm_shuffle_ps(v16, v16, 170));
    v18 = _mm_rsqrt_ps(v17);
    faceNormal.m_quad = _mm_mul_ps(
                          (__m128)v14,
                          _mm_andnot_ps(
                            _mm_cmple_ps(v17, (__m128)0i64),
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                              _mm_mul_ps(*(__m128 *)_xmm, v18))));
    v15 = hkaiSegmentCastingUtil::intersectSweptSegmentFaceAux(
            leftStartIn,
            rightStartIn,
            displacement,
            &edgeList,
            &faceNormal,
            data,
            partition);
  }
  edgeList.m_size = 0;
  if ( edgeList.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      edgeList.m_data,
      16 * edgeList.m_capacityAndFlags);
  return v15;
}

// File Line: 799
// RVA: 0x12F2590
__int64 __fastcall hkaiSegmentCastingUtil::intersectSweptSegmentTriangle(
        hkVector4f *leftStartIn,
        hkVector4f *rightStartIn,
        hkVector4f *displacement,
        hkVector4f *vA,
        hkVector4f *vB,
        hkVector4f *vC,
        unsigned int data,
        hkaiIntervalPartition::Interval *interval)
{
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm5
  __m128 v15; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  unsigned int v19; // ebx
  hkaiIntervalPartition partition; // [rsp+40h] [rbp-A8h] BYREF
  hkVector4f faceNormal; // [rsp+50h] [rbp-98h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> edgeList; // [rsp+60h] [rbp-88h] BYREF
  char v24; // [rsp+70h] [rbp-78h] BYREF

  edgeList.m_data = (hkVector4f *)&v24;
  edgeList.m_size = 0;
  edgeList.m_capacityAndFlags = -2147483642;
  hkaiSegmentCastingUtil::fillEdgeList_triangle(vA, vB, vC, &edgeList);
  v12 = _mm_sub_ps(vC->m_quad, vA->m_quad);
  v13 = _mm_sub_ps(vB->m_quad, vA->m_quad);
  v14 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v13), _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v12));
  v15 = _mm_shuffle_ps(v14, v14, 201);
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_rsqrt_ps(v17);
  faceNormal.m_quad = _mm_mul_ps(
                        v15,
                        _mm_andnot_ps(
                          _mm_cmple_ps(v17, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                            _mm_mul_ps(*(__m128 *)_xmm, v18))));
  hkaiIntervalPartition::hkaiIntervalPartition(&partition);
  if ( hkaiSegmentCastingUtil::intersectSweptSegmentFaceAux(
         leftStartIn,
         rightStartIn,
         displacement,
         &edgeList,
         &faceNormal,
         data,
         &partition) )
  {
    v19 = 1;
    *interval = *hkaiIntervalPartition::getInterval(&partition, 0);
  }
  else
  {
    v19 = 0;
  }
  partition.m_intervals.m_size = 0;
  if ( partition.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      partition.m_intervals.m_data,
      20 * (partition.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  partition.m_intervals.m_data = 0i64;
  partition.m_intervals.m_capacityAndFlags = 0x80000000;
  edgeList.m_size = 0;
  if ( edgeList.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      edgeList.m_data,
      16 * edgeList.m_capacityAndFlags);
  return v19;
}

// File Line: 834
// RVA: 0x12F2790
unsigned int __fastcall hkaiSegmentCastingUtil::intersectTurnedSegmentFace(
        hkVector4f *leftStartIn,
        hkVector4f *rightStartIn,
        hkVector4f *leftEndIn,
        hkVector4f *rightEndIn,
        hkaiEdgeGeometry *edgeGeometry,
        hkaiFaceEdges *faceEdges,
        int faceIdx,
        unsigned int data,
        hkaiIntervalPartition *partition)
{
  unsigned int result; // eax
  unsigned int v14; // ebx
  hkVector4f normalOut; // [rsp+40h] [rbp-128h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> edgeList; // [rsp+50h] [rbp-118h] BYREF
  char v17; // [rsp+60h] [rbp-108h] BYREF

  edgeList.m_size = 0;
  edgeList.m_capacityAndFlags = -2147483632;
  edgeList.m_data = (hkVector4f *)&v17;
  hkaiSegmentCastingUtil::fillEdgeList_edgeGeometry(edgeGeometry, faceEdges, faceIdx, &edgeList);
  hkaiEdgeGeometry::calculateFaceNormal(edgeGeometry, faceEdges, faceIdx, &normalOut);
  result = hkaiSegmentCastingUtil::intersectTurnedSegmentFaceAux(
             leftStartIn,
             rightStartIn,
             leftEndIn,
             rightEndIn,
             &edgeList,
             &normalOut,
             data,
             partition);
  v14 = result;
  edgeList.m_size = 0;
  if ( edgeList.m_capacityAndFlags >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      edgeList.m_data,
      16 * edgeList.m_capacityAndFlags);
    return v14;
  }
  return result;
}

// File Line: 854
// RVA: 0x12F28B0
unsigned int __fastcall hkaiSegmentCastingUtil::intersectTurnedSegmentFace(
        hkVector4f *leftStartIn,
        hkVector4f *rightStartIn,
        hkVector4f *leftEndIn,
        hkVector4f *rightEndIn,
        hkaiNavMesh *navMesh,
        unsigned int faceIndex,
        unsigned int data,
        hkaiIntervalPartition *partition)
{
  unsigned int result; // eax
  unsigned int v13; // ebx
  hkVector4f faceNormal; // [rsp+40h] [rbp-138h] BYREF
  hkaiNavMeshUtils v15; // [rsp+50h] [rbp-128h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> edgeList; // [rsp+60h] [rbp-118h] BYREF
  char v17; // [rsp+70h] [rbp-108h] BYREF

  edgeList.m_size = 0;
  edgeList.m_data = (hkVector4f *)&v17;
  edgeList.m_capacityAndFlags = -2147483632;
  hkaiSegmentCastingUtil::fillEdgeList_navMesh(navMesh, faceIndex, &edgeList);
  hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(
    &v15,
    (hkSimdFloat32 *)navMesh,
    (hkaiNavMesh *)faceIndex,
    &faceNormal.m_quad);
  result = hkaiSegmentCastingUtil::intersectTurnedSegmentFaceAux(
             leftStartIn,
             rightStartIn,
             leftEndIn,
             rightEndIn,
             &edgeList,
             &faceNormal,
             data,
             partition);
  v13 = result;
  edgeList.m_size = 0;
  if ( edgeList.m_capacityAndFlags >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      edgeList.m_data,
      16 * edgeList.m_capacityAndFlags);
    return v13;
  }
  return result;
}

// File Line: 874
// RVA: 0x12F4760
__int64 __fastcall hkaiSegmentCastingUtil::intersectTurnedSegmentFace(
        hkVector4f *leftStartIn,
        hkVector4f *rightStartIn,
        hkVector4f *leftEndIn,
        hkVector4f *rightEndIn,
        hkaiNavMeshInstance *navMeshInstance,
        unsigned int faceIndex,
        unsigned int data,
        hkaiIntervalPartition *partition)
{
  unsigned int v14; // ebx
  hkVector4f faceNormal; // [rsp+40h] [rbp-138h] BYREF
  hkaiNavMeshUtils v16; // [rsp+50h] [rbp-128h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> edgeList; // [rsp+60h] [rbp-118h] BYREF
  char v18; // [rsp+70h] [rbp-108h] BYREF
  char navMeshInstancea; // [rsp+1A0h] [rbp+28h]

  if ( navMeshInstance->m_faceFlags.m_size )
    navMeshInstancea = navMeshInstance->m_faceFlags.m_data[faceIndex].m_storage;
  else
    navMeshInstancea = 0;
  if ( (navMeshInstancea & 1) != 0 )
    return 0i64;
  edgeList.m_data = (hkVector4f *)&v18;
  edgeList.m_size = 0;
  edgeList.m_capacityAndFlags = -2147483632;
  hkaiSegmentCastingUtil::fillEdgeList_navMeshInstance(navMeshInstance, faceIndex, &edgeList);
  hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
    &v16,
    (hkSimdFloat32 *)navMeshInstance,
    (hkaiNavMeshInstance *)faceIndex,
    &faceNormal.m_quad);
  v14 = hkaiSegmentCastingUtil::intersectTurnedSegmentFaceAux(
          leftStartIn,
          rightStartIn,
          leftEndIn,
          rightEndIn,
          &edgeList,
          &faceNormal,
          data,
          partition);
  edgeList.m_size = 0;
  if ( edgeList.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      edgeList.m_data,
      16 * edgeList.m_capacityAndFlags);
  return v14;
}

// File Line: 899
// RVA: 0x12F29D0
unsigned int __fastcall hkaiSegmentCastingUtil::intersectTurnedSegmentFace(
        hkVector4f *leftStartIn,
        hkVector4f *rightStartIn,
        hkVector4f *leftEndIn,
        hkVector4f *rightEndIn,
        hkGeometry *geometry,
        int triangleIndex,
        unsigned int data,
        hkaiIntervalPartition *partition)
{
  hkGeometry::Triangle *m_data; // rcx
  hkVector4f *v13; // rdx
  __m128 m_quad; // xmm0
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm5
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  unsigned int result; // eax
  unsigned int v23; // ebx
  hkVector4f faceNormal; // [rsp+40h] [rbp-138h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> edgeList; // [rsp+50h] [rbp-128h] BYREF
  char v26; // [rsp+60h] [rbp-118h] BYREF

  edgeList.m_data = (hkVector4f *)&v26;
  edgeList.m_size = 0;
  edgeList.m_capacityAndFlags = -2147483632;
  hkaiSegmentCastingUtil::fillEdgeList_geometry(geometry, triangleIndex, &edgeList);
  m_data = geometry->m_triangles.m_data;
  v13 = geometry->m_vertices.m_data;
  m_quad = v13[m_data[triangleIndex].m_a].m_quad;
  v15 = _mm_sub_ps(v13[m_data[triangleIndex].m_b].m_quad, m_quad);
  v16 = _mm_sub_ps(v13[m_data[triangleIndex].m_c].m_quad, m_quad);
  v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v16));
  v18 = _mm_shuffle_ps(v17, v17, 201);
  v19 = _mm_mul_ps(v18, v18);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_rsqrt_ps(v20);
  faceNormal.m_quad = _mm_mul_ps(
                        v18,
                        _mm_andnot_ps(
                          _mm_cmple_ps(v20, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                            _mm_mul_ps(*(__m128 *)_xmm, v21))));
  result = hkaiSegmentCastingUtil::intersectTurnedSegmentFaceAux(
             leftStartIn,
             rightStartIn,
             leftEndIn,
             rightEndIn,
             &edgeList,
             &faceNormal,
             data,
             partition);
  v23 = result;
  edgeList.m_size = 0;
  if ( edgeList.m_capacityAndFlags >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      edgeList.m_data,
      16 * edgeList.m_capacityAndFlags);
    return v23;
  }
  return result;
}

// File Line: 923
// RVA: 0x12F2B70
__int64 __fastcall hkaiSegmentCastingUtil::intersectTurnedSegmentExtrudedEdge(
        hkVector4f *leftStartIn,
        hkVector4f *rightStartIn,
        hkVector4f *leftEndIn,
        hkVector4f *rightEndIn,
        hkVector4f *vertexA,
        hkVector4f *vertexB,
        hkVector4f *extrusion,
        unsigned int data,
        hkaiIntervalPartition *partition)
{
  __m128 v13; // xmm1
  __m128 v14; // xmm5
  __m128i v15; // xmm5
  unsigned int v16; // ebx
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  hkVector4f faceNormal; // [rsp+40h] [rbp-B8h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> edgeList; // [rsp+50h] [rbp-A8h] BYREF
  char v23; // [rsp+60h] [rbp-98h] BYREF

  edgeList.m_data = (hkVector4f *)&v23;
  edgeList.m_size = 0;
  edgeList.m_capacityAndFlags = -2147483640;
  hkaiSegmentCastingUtil::fillEdgeList_extrudedEdge(vertexA, vertexB, extrusion, &edgeList);
  v13 = _mm_sub_ps(vertexB->m_quad, vertexA->m_quad);
  v14 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(extrusion->m_quad, extrusion->m_quad, 201), v13),
          _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), extrusion->m_quad));
  v15 = (__m128i)_mm_shuffle_ps(v14, v14, 201);
  if ( (_mm_movemask_ps(_mm_cmplt_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v15, 1u), 1u), *(__m128 *)&epsilon)) & 7) == 7 )
  {
    v16 = 0;
  }
  else
  {
    v17 = _mm_mul_ps((__m128)v15, (__m128)v15);
    v18 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
            _mm_shuffle_ps(v17, v17, 170));
    v19 = _mm_rsqrt_ps(v18);
    faceNormal.m_quad = _mm_mul_ps(
                          (__m128)v15,
                          _mm_andnot_ps(
                            _mm_cmple_ps(v18, (__m128)0i64),
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                              _mm_mul_ps(*(__m128 *)_xmm, v19))));
    v16 = hkaiSegmentCastingUtil::intersectTurnedSegmentFaceAux(
            leftStartIn,
            rightStartIn,
            leftEndIn,
            rightEndIn,
            &edgeList,
            &faceNormal,
            data,
            partition);
  }
  edgeList.m_size = 0;
  if ( edgeList.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      edgeList.m_data,
      16 * edgeList.m_capacityAndFlags);
  return v16;
}

// File Line: 949
// RVA: 0x12F2D20
unsigned int __fastcall hkaiSegmentCastingUtil::intersectTurnedSegmentTriangle(
        hkVector4f *leftStartIn,
        hkVector4f *rightStartIn,
        hkVector4f *leftEndIn,
        hkVector4f *rightEndIn,
        hkVector4f *vA,
        hkVector4f *vB,
        hkVector4f *vC,
        unsigned int data,
        hkaiIntervalPartition *partition)
{
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm5
  __m128 v16; // xmm5
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  unsigned int result; // eax
  unsigned int v21; // ebx
  hkVector4f faceNormal; // [rsp+40h] [rbp-98h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> edgeList; // [rsp+50h] [rbp-88h] BYREF
  char v24; // [rsp+60h] [rbp-78h] BYREF

  edgeList.m_data = (hkVector4f *)&v24;
  edgeList.m_size = 0;
  edgeList.m_capacityAndFlags = -2147483642;
  hkaiSegmentCastingUtil::fillEdgeList_triangle(vA, vB, vC, &edgeList);
  v13 = _mm_sub_ps(vC->m_quad, vA->m_quad);
  v14 = _mm_sub_ps(vB->m_quad, vA->m_quad);
  v15 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v14), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v13));
  v16 = _mm_shuffle_ps(v15, v15, 201);
  v17 = _mm_mul_ps(v16, v16);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  faceNormal.m_quad = _mm_mul_ps(
                        v16,
                        _mm_andnot_ps(
                          _mm_cmple_ps(v18, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                            _mm_mul_ps(*(__m128 *)_xmm, v19))));
  result = hkaiSegmentCastingUtil::intersectTurnedSegmentFaceAux(
             leftStartIn,
             rightStartIn,
             leftEndIn,
             rightEndIn,
             &edgeList,
             &faceNormal,
             data,
             partition);
  v21 = result;
  edgeList.m_size = 0;
  if ( edgeList.m_capacityAndFlags >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      edgeList.m_data,
      16 * edgeList.m_capacityAndFlags);
    return v21;
  }
  return result;
}

// File Line: 966
// RVA: 0x12F1D50
void __fastcall hkaiSegmentCastingUtil::makeEdgeToWorldMatrix(
        hkVector4f *edgeLeft,
        hkVector4f *edgeRight,
        hkVector4f *up,
        hkMatrix4f *result,
        hkSimdFloat32 *edgeLengthOut)
{
  __m128 v5; // xmm8
  __m128 v6; // xmm1
  __m128 v7; // xmm3
  __m128 v8; // xmm2
  __m128 v9; // xmm9
  hkVector4f v10; // xmm8
  hkSimdFloat32 v11; // xmm9
  __m128 m_quad; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  hkVector4f v21; // xmm3

  v5 = _mm_sub_ps(edgeRight->m_quad, edgeLeft->m_quad);
  v6 = _mm_mul_ps(v5, v5);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v8 = _mm_rsqrt_ps(v7);
  v9 = _mm_andnot_ps(
         _mm_cmple_ps(v7, (__m128)0i64),
         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)), _mm_mul_ps(*(__m128 *)_xmm, v8)));
  v10.m_quad = _mm_mul_ps(v5, v9);
  v11.m_real = _mm_mul_ps(v9, v7);
  m_quad = up->m_quad;
  v13 = up->m_quad;
  result->m_col0 = (hkVector4f)v10.m_quad;
  v14 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v10.m_quad, v10.m_quad, 201), m_quad),
          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v10.m_quad));
  v15 = _mm_shuffle_ps(v14, v14, 201);
  v16 = _mm_mul_ps(v13, v15);
  v17 = _mm_sub_ps(
          v15,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
              _mm_shuffle_ps(v16, v16, 170)),
            m_quad));
  v18 = _mm_mul_ps(v17, v17);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v20 = _mm_rsqrt_ps(v19);
  v21.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v19, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                     _mm_mul_ps(*(__m128 *)_xmm, v20))),
                 v17);
  result->m_col1 = (hkVector4f)v21.m_quad;
  result->m_col2 = (hkVector4f)up->m_quad;
  result->m_col3 = (hkVector4f)edgeLeft->m_quad;
  result->m_col0 = (hkVector4f)_mm_srli_si128(_mm_slli_si128((__m128i)v10.m_quad, 4), 4);
  result->m_col2 = (hkVector4f)_mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)&result->m_col2), 4), 4);
  result->m_col1 = (hkVector4f)_mm_srli_si128(_mm_slli_si128((__m128i)v21.m_quad, 4), 4);
  result->m_col3.m_quad = _mm_shuffle_ps(
                            result->m_col3.m_quad,
                            _mm_unpackhi_ps(result->m_col3.m_quad, query.m_quad),
                            196);
  *edgeLengthOut = (hkSimdFloat32)v11.m_real;
}


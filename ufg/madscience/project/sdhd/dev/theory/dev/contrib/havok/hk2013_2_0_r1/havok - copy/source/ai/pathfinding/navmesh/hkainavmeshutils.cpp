// File Line: 52
// RVA: 0xBC7580
hkSimdFloat32 *__fastcall inverseInt(hkSimdFloat32 *result, int i)
{
  __m128 v2; // xmm1
  hkSimdFloat32 *v3; // rax
  __m128 v4; // xmm1
  __m128 v5; // xmm2

  v2 = 0i64;
  v2.m128_f32[0] = (float)i;
  v3 = result;
  v4 = _mm_shuffle_ps(v2, v2, 0);
  v5 = _mm_rcp_ps(v4);
  result->m_real = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v5, v4)), v5);
  return v3;
}

// File Line: 64
// RVA: 0xBCAB30
void __fastcall hkaiNavMeshUtils::getFaceLocalVertices<hkaiNavMeshInstance>(
        hkaiNavMeshUtils *this,
        hkaiNavMeshInstance *mesh,
        hkaiNavMesh::Face *face,
        hkArrayBase<hkVector4f> *faceVerticesOut)
{
  int m_memSizeAndFlags; // eax
  _OWORD *v5; // r15
  int vfptr; // r13d
  signed int v7; // r14d
  signed int v8; // ebp
  char v9; // r12
  hkaiNavMesh::Face *v10; // rsi
  _OWORD *v12; // rdi
  int v13; // esi
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // r15
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v15; // r9
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v16; // r8
  hkaiNavMesh::Edge *v17; // rax
  __int64 m_a; // rcx
  _OWORD *v19; // rcx
  __int64 m_b; // rax
  __int128 *v21; // rax
  __int128 v22; // xmm0
  __int64 v23; // rcx
  int v24; // eax
  _OWORD *v25; // rax
  int v26; // [rsp+78h] [rbp+10h]
  _OWORD *v28; // [rsp+88h] [rbp+20h]

  m_memSizeAndFlags = (__int16)mesh->m_memSizeAndFlags;
  v5 = *(_OWORD **)&face->m_startEdgeIndex;
  vfptr = (int)mesh->vfptr;
  v7 = 0;
  v8 = m_memSizeAndFlags & 0xFFFFFFFE;
  v9 = mesh->m_memSizeAndFlags & 1;
  v10 = face;
  v28 = *(_OWORD **)&face->m_startEdgeIndex;
  v12 = *(_OWORD **)&face->m_startEdgeIndex;
  v26 = m_memSizeAndFlags;
  if ( m_memSizeAndFlags >= 0 && (m_memSizeAndFlags & 0xFFFFFFFE) != 0 )
  {
    v13 = *(_DWORD *)&this[56];
    instanceMap = (hkArray<int,hkContainerHeapAllocator> *)&this[208];
    v15 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[288];
    v16 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[256];
    do
    {
      v17 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
              *(hkaiNavMesh::Edge **)&this[32],
              *(_DWORD *)&this[40],
              v16,
              v15,
              instanceMap,
              v7 + vfptr);
      m_a = v17->m_a;
      if ( (int)m_a >= v13 )
        v19 = (_OWORD *)(*(_QWORD *)&this[304] + 16i64 * ((int)m_a - v13));
      else
        v19 = (_OWORD *)(*(_QWORD *)&this[48] + 16 * m_a);
      m_b = v17->m_b;
      if ( (int)m_b >= v13 )
        v21 = (__int128 *)(*(_QWORD *)&this[304] + 16i64 * ((int)m_b - v13));
      else
        v21 = (__int128 *)(*(_QWORD *)&this[48] + 16 * m_b);
      v22 = *v21;
      v7 += 2;
      *v12 = *v19;
      v12 += 2;
      *(v12 - 1) = v22;
    }
    while ( v7 < v8 );
    v5 = v28;
    m_memSizeAndFlags = v26;
    v10 = face;
  }
  if ( v9 )
  {
    v23 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
            *(hkaiNavMesh::Edge **)&this[32],
            *(_DWORD *)&this[40],
            (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[256],
            (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[288],
            (hkArray<int,hkContainerHeapAllocator> *)&this[208],
            vfptr + m_memSizeAndFlags - 1)->m_a;
    v24 = *(_DWORD *)&this[56];
    if ( (int)v23 >= v24 )
      v25 = (_OWORD *)(*(_QWORD *)&this[304] + 16i64 * ((int)v23 - v24));
    else
      v25 = (_OWORD *)(*(_QWORD *)&this[48] + 16 * v23);
    *v12 = *v25;
  }
  v5[*(int *)&v10->m_numEdges - 1] = *v5;
}

// File Line: 101
// RVA: 0xBBF990
void __fastcall hkaiNavMeshUtils::getFaceVertices(
        hkaiNavMeshUtils *meshInstance,
        hkaiNavMeshInstance *face,
        hkaiNavMesh::Face *faceVerticesOut,
        hkArrayBase<hkVector4f> *a4)
{
  hkVector4f v6; // xmm3
  hkVector4f v7; // xmm4
  hkVector4f v8; // xmm5
  __int64 v9; // rcx
  hkVector4f v10; // xmm6
  hkVector4f *v11; // rax
  __m128 m_quad; // xmm1

  hkaiNavMeshUtils::getFaceLocalVertices<hkaiNavMeshInstance>(meshInstance, face, faceVerticesOut, a4);
  v6.m_quad = *(__m128 *)&meshInstance[112];
  v7.m_quad = *(__m128 *)&meshInstance[128];
  v8.m_quad = *(__m128 *)&meshInstance[144];
  v9 = *(_DWORD *)&faceVerticesOut->m_numEdges - 1;
  v10.m_quad = *(__m128 *)&meshInstance[160];
  v11 = (hkVector4f *)(*(_QWORD *)&faceVerticesOut->m_startEdgeIndex + 16 * v9);
  do
  {
    m_quad = v11->m_quad;
    --v11;
    --v9;
    v11[1].m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v7.m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v6.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v8.m_quad)),
                      v10.m_quad);
  }
  while ( v9 >= 0 );
}

// File Line: 109
// RVA: 0xBBFB50
void __fastcall hkaiNavMeshUtils::calcFaceNormal(hkArrayBase<hkVector4f> *facePoints, hkVector4f *normalOut)
{
  hkVector4f *m_data; // r8
  int v3; // eax
  __int64 v4; // rcx
  __m128 v5; // xmm4
  __m128 m_quad; // xmm3
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm5
  __m128 v16; // xmm3
  __m128 v17; // xmm2

  m_data = facePoints->m_data;
  v3 = facePoints->m_size - 1;
  v4 = v3;
  v5 = 0i64;
  m_quad = m_data->m_quad;
  if ( v3 > 0 )
  {
    do
    {
      v7 = m_data->m_quad;
      v8 = m_data[1].m_quad;
      ++m_data;
      v9 = _mm_sub_ps(v8, m_quad);
      v10 = _mm_sub_ps(v7, m_quad);
      v11 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v10), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v9));
      v5 = _mm_add_ps(v5, _mm_shuffle_ps(v11, v11, 201));
      --v4;
    }
    while ( v4 );
  }
  v12 = _mm_mul_ps(v5, v5);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_rsqrt_ps(v13);
  v15 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v13), (__m128)0i64);
  v16 = _mm_cmple_ps(v13, (__m128)0i64);
  v17 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)), _mm_mul_ps(*(__m128 *)_xmm, v14));
  if ( _mm_movemask_ps(v15) )
    normalOut->m_quad = _mm_or_ps(_mm_and_ps(_mm_mul_ps(_mm_andnot_ps(v16, v17), v5), v15), _mm_andnot_ps(v15, v5));
  else
    *normalOut = (hkVector4f)stru_141A71280.m_quad;
}

// File Line: 139
// RVA: 0xBBFC40
void __fastcall hkaiNavMeshUtils::calcEdgePlane(
        hkArrayBase<hkVector4f> *facePoints,
        int e,
        hkVector4f *faceNormal,
        hkVector4f *edgePlaneOut)
{
  __m128 m_quad; // xmm6
  __m128 v5; // xmm1
  __m128 v6; // xmm7
  __m128 v7; // xmm7
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm7
  __m128 v12; // xmm2

  m_quad = facePoints->m_data[e].m_quad;
  v5 = _mm_sub_ps(facePoints->m_data[e + 1].m_quad, m_quad);
  v6 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(faceNormal->m_quad, faceNormal->m_quad, 201), v5),
         _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), faceNormal->m_quad));
  v7 = _mm_shuffle_ps(v6, v6, 201);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  v11 = _mm_mul_ps(
          v7,
          _mm_andnot_ps(
            _mm_cmple_ps(v9, (__m128)0i64),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)), _mm_mul_ps(*(__m128 *)_xmm, v10))));
  v12 = _mm_mul_ps(v11, m_quad);
  edgePlaneOut->m_quad = _mm_shuffle_ps(
                           v11,
                           _mm_unpackhi_ps(
                             v11,
                             _mm_sub_ps(
                               (__m128)0i64,
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                                 _mm_shuffle_ps(v12, v12, 170)))),
                           196);
}

// File Line: 152
// RVA: 0xBBFD20
void __fastcall hkaiNavMeshUtils::calcFaceAabb(
        hkArrayBase<hkVector4f> *facePoints,
        hkSimdFloat32 *extraRadius,
        hkAabb *aabbOut)
{
  __m128 v3; // xmm2
  int v5; // eax
  __int64 v6; // rcx
  __m128 v7; // xmm1
  hkVector4f *m_data; // rax
  hkVector4f v9; // xmm1

  v3 = (__m128)xmmword_141A712A0;
  v5 = facePoints->m_size - 1;
  v6 = v5;
  v7 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), (__m128)xmmword_141A712A0);
  if ( v5 > 0 )
  {
    m_data = facePoints->m_data;
    do
    {
      v3 = _mm_min_ps(v3, m_data->m_quad);
      v7 = _mm_max_ps(v7, m_data->m_quad);
      ++m_data;
      --v6;
    }
    while ( v6 );
  }
  v9.m_quad = _mm_add_ps(v7, extraRadius->m_real);
  aabbOut->m_min.m_quad = _mm_sub_ps(v3, extraRadius->m_real);
  aabbOut->m_max = (hkVector4f)v9.m_quad;
}

// File Line: 182
// RVA: 0xBC84E0
hkaiNavMeshUtils *__fastcall hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
        hkaiNavMeshUtils *this,
        hkSimdFloat32 *result,
        hkaiNavMeshInstance *mesh,
        __m128 *faceIndex)
{
  hkaiNavMeshUtils *v5; // r13
  hkaiNavMesh::Face *v6; // rax
  int v7; // r15d
  __m128 v8; // xmm11
  int m_startEdgeIndex; // ebp
  hkaiNavMesh::Edge *v10; // r12
  __int64 m_a; // rcx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v12; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v13; // r9
  int v14; // edi
  __m128 *v15; // rax
  __m128 m_real; // xmm7
  __m128 v17; // xmm8
  int v18; // esi
  __m128 v19; // xmm9
  __m128 v20; // xmm10
  __m128 v21; // xmm6
  hkaiNavMesh::Edge *v22; // rax
  __int64 v23; // rcx
  __m128 *v24; // rcx
  __int64 m_b; // rax
  __m128 v26; // xmm3
  __m128 *v27; // rax
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm5
  __m128 v33; // xmm2
  __m128 v34; // xmm3
  __m128 v35; // xmm6
  __m128 v36; // xmm1
  int m_numEdges; // [rsp+E8h] [rbp+10h]

  v5 = this;
  v6 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
         (hkaiNavMesh::Face *)result[1].m_real.m128_u64[0],
         result[1].m_real.m128_i32[2],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&result[15],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&result[17],
         (hkArray<int,hkContainerHeapAllocator> *)&result[14],
         (int)mesh);
  v7 = result[2].m_real.m128_i32[2];
  v8 = 0i64;
  m_startEdgeIndex = v6->m_startEdgeIndex;
  v10 = (hkaiNavMesh::Edge *)result[2].m_real.m128_u64[0];
  m_numEdges = v6->m_numEdges;
  m_a = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
          v10,
          v7,
          (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&result[16],
          (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&result[18],
          (hkArray<int,hkContainerHeapAllocator> *)&result[13],
          v6->m_startEdgeIndex)->m_a;
  v14 = result[3].m_real.m128_i32[2];
  if ( (int)m_a >= v14 )
    v15 = (__m128 *)(result[19].m_real.m128_u64[0] + 16i64 * ((int)m_a - v14));
  else
    v15 = (__m128 *)(result[3].m_real.m128_u64[0] + 16 * m_a);
  m_real = result[8].m_real;
  v17 = result[7].m_real;
  v18 = 0;
  v19 = result[9].m_real;
  v20 = result[10].m_real;
  v21 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 0), v17),
              _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 85), m_real)),
            _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 170), v19)),
          v20);
  if ( m_numEdges > 0 )
  {
    do
    {
      v22 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
              v10,
              v7,
              v12,
              v13,
              (hkArray<int,hkContainerHeapAllocator> *)&result[13],
              v18 + m_startEdgeIndex);
      v23 = v22->m_a;
      if ( (int)v23 >= v14 )
        v24 = (__m128 *)(result[19].m_real.m128_u64[0] + 16i64 * ((int)v23 - v14));
      else
        v24 = (__m128 *)(result[3].m_real.m128_u64[0] + 16 * v23);
      m_b = v22->m_b;
      v26 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v24, *v24, 0), v17),
                  _mm_mul_ps(_mm_shuffle_ps(*v24, *v24, 85), m_real)),
                _mm_mul_ps(_mm_shuffle_ps(*v24, *v24, 170), v19)),
              v20);
      if ( (int)m_b >= v14 )
        v27 = (__m128 *)(result[19].m_real.m128_u64[0] + 16i64 * ((int)m_b - v14));
      else
        v27 = (__m128 *)(result[3].m_real.m128_u64[0] + 16 * m_b);
      v28 = _mm_sub_ps(v26, v21);
      ++v18;
      v29 = _mm_sub_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 0), v17),
                    _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 85), m_real)),
                  _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 170), v19)),
                v20),
              v21);
      v30 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v28), _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v29));
      v8 = _mm_add_ps(v8, _mm_shuffle_ps(v30, v30, 201));
    }
    while ( v18 < m_numEdges );
    v5 = this;
  }
  v31 = _mm_mul_ps(v8, v8);
  v32 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)), _mm_shuffle_ps(v31, v31, 170));
  v33 = _mm_rsqrt_ps(v32);
  v34 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v32), (__m128)0i64);
  v35 = _mm_or_ps(
          _mm_and_ps(
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmple_ps(v32, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v33, v32), v33)),
                  _mm_mul_ps(v33, *(__m128 *)_xmm))),
              v8),
            v34),
          _mm_andnot_ps(v34, v8));
  if ( _mm_movemask_ps(v34) )
  {
    v36 = _mm_rsqrt_ps(v32);
    *faceIndex = v35;
    *(__m128 *)v5 = _mm_mul_ps(
                      _mm_andnot_ps(
                        _mm_cmple_ps(v32, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v36, v32), v36)),
                            _mm_mul_ps(v36, *(__m128 *)_xmm)),
                          v32)),
                      (__m128)xmmword_141A711B0);
  }
  else
  {
    *(hkVector4f *)faceIndex = (hkVector4f)stru_141A71280.m_quad;
    *(hkVector4f *)v5 = (hkVector4f)aabbOut.m_quad;
  }
  return v5;
}

// File Line: 225
// RVA: 0xBC8160
void __fastcall hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
        hkaiNavMeshUtils *this,
        hkaiNavMeshInstance *mesh,
        __m128 *faceIndex,
        hkVector4f *centroidOut)
{
  __m128 v4; // xmm6
  __m128 v6; // xmm7
  hkaiNavMesh::Face *v7; // rax
  int v8; // esi
  int m_numEdges; // r13d
  int v10; // edi
  int m_startEdgeIndex; // r12d
  int v12; // r14d
  hkaiNavMesh::Edge *v13; // r15
  __m128 v14; // xmm8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v15; // r9
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v16; // r8
  __m128 v17; // xmm9
  __m128 v18; // xmm10
  __m128 v19; // xmm11
  __int64 m_a; // rcx
  __m128 *v21; // rax
  __m128 v22; // xmm6
  __m128 v23; // xmm1

  v4 = 0i64;
  v6 = 0i64;
  v7 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
         *(hkaiNavMesh::Face **)&this[16],
         *(_DWORD *)&this[24],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[240],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[272],
         (hkArray<int,hkContainerHeapAllocator> *)&this[224],
         (int)mesh);
  v8 = 0;
  m_numEdges = v7->m_numEdges;
  if ( m_numEdges > 0 )
  {
    v10 = *(_DWORD *)&this[56];
    m_startEdgeIndex = v7->m_startEdgeIndex;
    v12 = *(_DWORD *)&this[40];
    v13 = *(hkaiNavMesh::Edge **)&this[32];
    v14 = *(__m128 *)&this[128];
    v15 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[288];
    v16 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[256];
    v17 = *(__m128 *)&this[112];
    v18 = *(__m128 *)&this[144];
    v19 = *(__m128 *)&this[160];
    do
    {
      m_a = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
              v13,
              v12,
              v16,
              v15,
              (hkArray<int,hkContainerHeapAllocator> *)&this[208],
              m_startEdgeIndex + v8)->m_a;
      if ( (int)m_a >= v10 )
        v21 = (__m128 *)(*(_QWORD *)&this[304] + 16i64 * ((int)m_a - v10));
      else
        v21 = (__m128 *)(*(_QWORD *)&this[48] + 16 * m_a);
      ++v8;
      v6 = _mm_add_ps(
             v6,
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(*v21, *v21, 0), v17),
                   _mm_mul_ps(_mm_shuffle_ps(*v21, *v21, 85), v14)),
                 _mm_mul_ps(_mm_shuffle_ps(*v21, *v21, 170), v18)),
               v19));
    }
    while ( v8 < m_numEdges );
  }
  v4.m128_f32[0] = (float)m_numEdges;
  v22 = _mm_shuffle_ps(v4, v4, 0);
  v23 = _mm_rcp_ps(v22);
  *faceIndex = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v22)), v23), v6);
}

// File Line: 241
// RVA: 0xBC7D40
void __fastcall hkaiNavMeshUtils::calcEdgePlane<hkaiNavMeshInstance>(
        hkaiNavMeshUtils *this,
        hkaiNavMeshInstance *mesh,
        int faceIndex,
        __m128 *edgeIndex,
        hkVector4f *faceNormal)
{
  hkaiNavMesh::Edge *v7; // rax
  int v8; // edx
  __int64 m_a; // rcx
  __m128 *v10; // rcx
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  __int64 m_b; // rax
  __m128 v14; // xmm5
  __m128 v15; // xmm6
  __m128 v16; // xmm7
  __m128 *v17; // rax
  __m128 v18; // xmm2
  __m128 v19; // xmm6
  __m128 v20; // xmm6
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm6
  __m128 v25; // xmm2

  v7 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
         *(hkaiNavMesh::Edge **)&this[32],
         *(_DWORD *)&this[40],
         (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[256],
         (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[288],
         (hkArray<int,hkContainerHeapAllocator> *)&this[208],
         faceIndex);
  v8 = *(_DWORD *)&this[56];
  m_a = v7->m_a;
  if ( (int)m_a >= v8 )
    v10 = (__m128 *)(*(_QWORD *)&this[304] + 16i64 * ((int)m_a - v8));
  else
    v10 = (__m128 *)(*(_QWORD *)&this[48] + 16 * m_a);
  v11 = *(__m128 *)&this[128];
  v12 = *(__m128 *)&this[112];
  m_b = v7->m_b;
  v14 = *(__m128 *)&this[144];
  v15 = *(__m128 *)&this[160];
  v16 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v10, *v10, 0), v12), _mm_mul_ps(_mm_shuffle_ps(*v10, *v10, 85), v11)),
            _mm_mul_ps(_mm_shuffle_ps(*v10, *v10, 170), v14)),
          v15);
  if ( (int)m_b >= v8 )
    v17 = (__m128 *)(*(_QWORD *)&this[304] + 16i64 * ((int)m_b - v8));
  else
    v17 = (__m128 *)(*(_QWORD *)&this[48] + 16 * m_b);
  v18 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 0), v12),
                _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 85), v11)),
              _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 170), v14)),
            v15),
          v16);
  v19 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(*edgeIndex, *edgeIndex, 201), v18),
          _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), *edgeIndex));
  v20 = _mm_shuffle_ps(v19, v19, 201);
  v21 = _mm_mul_ps(v20, v20);
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v23 = _mm_rsqrt_ps(v22);
  v24 = _mm_mul_ps(
          v20,
          _mm_andnot_ps(
            _mm_cmple_ps(v22, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
              _mm_mul_ps(*(__m128 *)_xmm, v23))));
  v25 = _mm_mul_ps(v24, v16);
  faceNormal->m_quad = _mm_shuffle_ps(
                         v24,
                         _mm_unpackhi_ps(
                           v24,
                           _mm_sub_ps(
                             (__m128)0i64,
                             _mm_add_ps(
                               _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                               _mm_shuffle_ps(v25, v25, 170)))),
                         196);
}

// File Line: 263
// RVA: 0xBC02A0
void __fastcall hkaiNavMeshUtils::getClosestPointOnFace(
        hkArrayBase<hkVector4f> *facePoints,
        hkVector4f *position,
        hkVector4f *closestPointOut)
{
  float v3; // xmm14_4
  int v4; // eax
  __m128 m_quad; // xmm2
  __m128 v6; // xmm15
  hkVector4f *v7; // rdx
  __int64 v8; // rcx
  __m128 v9; // xmm9
  __m128 v10; // xmm13
  __m128 v11; // xmm3
  __m128 v12; // xmm0
  __m128 v13; // xmm1
  __m128 v14; // xmm8
  __m128 v15; // xmm7
  __m128 v16; // xmm12
  __m128 v17; // xmm2
  __m128 v18; // xmm10
  __m128 v19; // xmm11
  __m128 v20; // xmm1
  __m128 v21; // xmm6
  __m128 v22; // xmm5
  __m128 v23; // xmm6
  __m128 v24; // xmm3
  __m128 v25; // xmm5
  __m128 v26; // xmm3
  __m128 v27; // xmm4
  __m128 v28; // xmm1
  __m128 v29; // xmm4
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __m128 v32; // xmm3
  __m128 v33; // xmm1
  __m128 v34; // xmm3
  __m128 v35; // xmm0
  __m128 v36; // xmm3
  __m128 v37; // xmm5
  __m128 v38; // xmm1
  __m128 v39; // xmm4
  __m128 v40; // xmm2
  __m128 v41; // xmm5
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm5
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm1
  __m128 v49; // xmm0
  __m128 v50; // xmm2
  __m128 v51; // xmm5
  __m128 v52; // xmm1
  __m128 v53; // xmm10
  __m128 v54; // xmm11
  __m128 v55; // xmm2
  __m128 v56; // xmm3
  __m128 v57; // xmm4
  __m128 v58; // xmm2
  __m128 v59; // xmm1
  __m128 v60; // xmm3
  __m128 v61; // xmm1
  __m128 v62; // xmm1
  float v63; // xmm2_4
  __m128 v64; // [rsp+0h] [rbp-E8h]
  __m128 v65; // [rsp+10h] [rbp-D8h]
  __m128 v66; // [rsp+20h] [rbp-C8h]
  __m128 v67; // [rsp+30h] [rbp-B8h]

  v3 = 3.40282e38;
  v4 = facePoints->m_size - 2;
  m_quad = facePoints->m_data->m_quad;
  v6 = position->m_quad;
  v66 = m_quad;
  if ( v4 > 1i64 )
  {
    v7 = facePoints->m_data + 1;
    v8 = v4 - 1i64;
    v64 = _mm_shuffle_ps(aabbOut.m_quad, _mm_unpackhi_ps(aabbOut.m_quad, (__m128)xmmword_141A712F0), 196);
    v9 = v6;
    v10 = _mm_sub_ps(v6, m_quad);
    v11 = _mm_shuffle_ps(v10, v10, 201);
    v65 = _mm_shuffle_ps(query.m_quad, _mm_unpackhi_ps(query.m_quad, (__m128)xmmword_141A712A0), 196);
    v67 = v11;
    do
    {
      v12 = v7->m_quad;
      v13 = v7[1].m_quad;
      ++v7;
      v14 = _mm_sub_ps(v13, v12);
      v15 = _mm_sub_ps(v12, m_quad);
      v16 = _mm_sub_ps(m_quad, v13);
      v17 = _mm_shuffle_ps(v14, v14, 201);
      v18 = _mm_sub_ps(v9, v12);
      v19 = _mm_sub_ps(v9, v13);
      v20 = _mm_shuffle_ps(v15, v15, 201);
      v21 = _mm_sub_ps(_mm_mul_ps(v17, v15), _mm_mul_ps(v14, v20));
      v22 = _mm_sub_ps(_mm_mul_ps(v11, v15), _mm_mul_ps(v10, v20));
      v23 = _mm_shuffle_ps(v21, v21, 201);
      v24 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v14), _mm_mul_ps(v18, v17));
      v25 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v23);
      v26 = _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v23);
      v27 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v16), _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v19));
      v28 = _mm_unpacklo_ps(v25, v26);
      v29 = _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v23);
      v30 = _mm_movelh_ps(v28, v29);
      if ( (_mm_movemask_ps(
              _mm_cmplt_ps(
                v64,
                _mm_add_ps(
                  _mm_shuffle_ps(_mm_unpackhi_ps(v25, v26), v29, 228),
                  _mm_add_ps(v30, _mm_shuffle_ps(_mm_movehl_ps(v30, v28), v29, 212))))) & 7) == 7 )
      {
        v31 = _mm_mul_ps(v23, v23);
        v32 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                _mm_shuffle_ps(v31, v31, 170));
        v33 = _mm_mul_ps(v23, v10);
        v34 = _mm_sub_ps(
                v9,
                _mm_mul_ps(
                  _mm_andnot_ps(
                    _mm_cmpeq_ps((__m128)0i64, v32),
                    _mm_mul_ps(
                      _mm_rcp_ps(v32),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
                        _mm_shuffle_ps(v33, v33, 170)))),
                  v23));
      }
      else
      {
        v35 = _mm_mul_ps(v14, v14);
        v36 = _mm_mul_ps(v16, v16);
        v37 = _mm_mul_ps(v15, v15);
        v38 = _mm_unpacklo_ps(v37, v35);
        v39 = _mm_mul_ps(v10, v15);
        v40 = _mm_movelh_ps(v38, v36);
        v41 = _mm_shuffle_ps(_mm_unpackhi_ps(v37, v35), v36, 228);
        v42 = _mm_add_ps(v40, _mm_shuffle_ps(_mm_movehl_ps(v40, v38), v36, 212));
        v43 = _mm_mul_ps(v19, v16);
        v44 = _mm_add_ps(v41, v42);
        v45 = _mm_mul_ps(v18, v14);
        v46 = _mm_unpacklo_ps(v39, v45);
        v47 = _mm_movelh_ps(v46, v43);
        v48 = _mm_andnot_ps(
                _mm_cmpeq_ps(v44, (__m128)0i64),
                _mm_mul_ps(
                  _mm_rcp_ps(v44),
                  _mm_add_ps(
                    _mm_shuffle_ps(_mm_unpackhi_ps(v39, v45), v43, 228),
                    _mm_add_ps(v47, _mm_shuffle_ps(_mm_movehl_ps(v47, v46), v43, 212)))));
        v49 = _mm_cmplt_ps(v48, v65);
        v50 = _mm_max_ps(v64, _mm_or_ps(_mm_and_ps(v48, v49), _mm_andnot_ps(v49, v65)));
        v51 = _mm_sub_ps(v10, _mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), v15));
        v52 = _mm_mul_ps(v51, v51);
        v53 = _mm_sub_ps(v18, _mm_mul_ps(_mm_shuffle_ps(v50, v50, 85), v14));
        v54 = _mm_sub_ps(v19, _mm_mul_ps(_mm_shuffle_ps(v50, v50, 170), v16));
        v55 = _mm_mul_ps(v53, v53);
        v56 = _mm_cmplt_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                  _mm_shuffle_ps(v52, v52, 170)),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                  _mm_shuffle_ps(v55, v55, 170)));
        v57 = _mm_or_ps(_mm_andnot_ps(v56, v53), _mm_and_ps(v51, v56));
        v58 = _mm_mul_ps(v54, v54);
        v59 = _mm_mul_ps(v57, v57);
        v60 = _mm_cmplt_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v59, v59, 85), _mm_shuffle_ps(v59, v59, 0)),
                  _mm_shuffle_ps(v59, v59, 170)),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v58, v58, 85), _mm_shuffle_ps(v58, v58, 0)),
                  _mm_shuffle_ps(v58, v58, 170)));
        v34 = _mm_sub_ps(v9, _mm_or_ps(_mm_andnot_ps(v60, v54), _mm_and_ps(v57, v60)));
      }
      v61 = _mm_sub_ps(v9, v34);
      v62 = _mm_mul_ps(v61, v61);
      v63 = (float)(_mm_shuffle_ps(v62, v62, 85).m128_f32[0] + _mm_shuffle_ps(v62, v62, 0).m128_f32[0])
          + _mm_shuffle_ps(v62, v62, 170).m128_f32[0];
      if ( v63 < v3 )
      {
        v3 = v63;
        v6 = v34;
      }
      m_quad = v66;
      v11 = v67;
      --v8;
    }
    while ( v8 );
  }
  *closestPointOut = (hkVector4f)v6;
}

// File Line: 300
// RVA: 0xBCBA70
void __fastcall hkaiNavMeshUtils_getClosestPointOnFace<hkaiNavMeshInstance,1>(
        hkaiNavMeshInstance *mesh,
        hkVector4f *position,
        int faceIndex,
        hkVector4f *closestPointOut)
{
  hkaiNavMesh::Face *v6; // rax
  int m_numOriginalEdges; // r15d
  hkaiNavMesh::Edge *m_originalEdges; // r12
  int m_startEdgeIndex; // ebp
  hkaiNavMesh::Face *v10; // r13
  hkaiNavMesh::Edge *v11; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v12; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v13; // r9
  int m_numOriginalVertices; // edi
  __int64 m_a; // rcx
  hkVector4f *v16; // rax
  __m128 m_quad; // xmm6
  __m128 v18; // xmm15
  int index; // esi
  float v20; // xmm14_4
  int v21; // ebp
  __m128 v22; // xmm9
  __m128 v23; // xmm13
  hkaiNavMesh::Edge *v24; // rax
  __int64 v25; // rcx
  hkVector4f *v26; // rcx
  __int64 m_b; // rax
  __m128 v28; // xmm1
  hkVector4f *v29; // rax
  __m128 v30; // xmm7
  __m128 v31; // xmm12
  __m128 v32; // xmm11
  __m128 v33; // xmm8
  __m128 v34; // xmm10
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm6
  __m128 v38; // xmm6
  __m128 v39; // xmm5
  __m128 v40; // xmm3
  __m128 v41; // xmm5
  __m128 v42; // xmm4
  __m128 v43; // xmm3
  __m128 v44; // xmm1
  __m128 v45; // xmm4
  __m128 v46; // xmm2
  __m128 v47; // xmm1
  __m128 v48; // xmm3
  __m128 v49; // xmm1
  __m128 v50; // xmm3
  __m128 v51; // xmm0
  __m128 v52; // xmm3
  __m128 v53; // xmm5
  __m128 v54; // xmm1
  __m128 v55; // xmm4
  __m128 v56; // xmm2
  __m128 v57; // xmm5
  __m128 v58; // xmm2
  __m128 v59; // xmm3
  __m128 v60; // xmm5
  __m128 v61; // xmm0
  __m128 v62; // xmm1
  __m128 v63; // xmm2
  __m128 v64; // xmm2
  __m128 v65; // xmm0
  __m128 v66; // xmm3
  __m128 v67; // xmm5
  __m128 v68; // xmm4
  __m128 v69; // xmm10
  __m128 v70; // xmm11
  __m128 v71; // xmm1
  __m128 v72; // xmm2
  __m128 v73; // xmm5
  __m128 v74; // xmm2
  __m128 v75; // xmm1
  __m128 v76; // xmm3
  __m128 v77; // xmm1
  __m128 v78; // xmm1
  float v79; // xmm2_4
  __m128 v80; // [rsp+30h] [rbp-118h]
  __m128 v81; // [rsp+40h] [rbp-108h]
  __m128 v82; // [rsp+50h] [rbp-F8h]
  __m128 v83; // [rsp+60h] [rbp-E8h]

  v6 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
         mesh->m_originalFaces,
         mesh->m_numOriginalFaces,
         &mesh->m_instancedFaces,
         &mesh->m_ownedFaces,
         &mesh->m_faceMap,
         faceIndex);
  m_numOriginalEdges = mesh->m_numOriginalEdges;
  m_originalEdges = mesh->m_originalEdges;
  m_startEdgeIndex = v6->m_startEdgeIndex;
  v10 = v6;
  v11 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
          m_originalEdges,
          m_numOriginalEdges,
          &mesh->m_instancedEdges,
          &mesh->m_ownedEdges,
          &mesh->m_edgeMap,
          v6->m_startEdgeIndex);
  m_numOriginalVertices = mesh->m_numOriginalVertices;
  m_a = v11->m_a;
  if ( (int)m_a >= m_numOriginalVertices )
    v16 = &mesh->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices];
  else
    v16 = &mesh->m_originalVertices[m_a];
  m_quad = v16->m_quad;
  v18 = position->m_quad;
  index = m_startEdgeIndex + 1;
  v20 = 3.40282e38;
  v83 = v16->m_quad;
  v21 = v10->m_numEdges + m_startEdgeIndex - 1;
  if ( index < v21 )
  {
    v22 = position->m_quad;
    v23 = _mm_sub_ps(position->m_quad, m_quad);
    v80 = _mm_shuffle_ps(aabbOut.m_quad, _mm_unpackhi_ps(aabbOut.m_quad, (__m128)xmmword_141A712F0), 196);
    v82 = _mm_shuffle_ps(query.m_quad, _mm_unpackhi_ps(query.m_quad, (__m128)xmmword_141A712A0), 196);
    v81 = _mm_shuffle_ps(v23, v23, 201);
    do
    {
      v24 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
              m_originalEdges,
              m_numOriginalEdges,
              v12,
              v13,
              &mesh->m_edgeMap,
              index);
      v25 = v24->m_a;
      if ( (int)v25 >= m_numOriginalVertices )
        v26 = &mesh->m_ownedVertices.m_data[(int)v25 - m_numOriginalVertices];
      else
        v26 = &mesh->m_originalVertices[v25];
      m_b = v24->m_b;
      v28 = v26->m_quad;
      if ( (int)m_b >= m_numOriginalVertices )
        v29 = &mesh->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices];
      else
        v29 = &mesh->m_originalVertices[m_b];
      v30 = _mm_sub_ps(v28, m_quad);
      v31 = _mm_sub_ps(m_quad, v29->m_quad);
      v32 = _mm_sub_ps(v22, v29->m_quad);
      v33 = _mm_sub_ps(v29->m_quad, v28);
      v34 = _mm_sub_ps(v22, v28);
      v35 = _mm_shuffle_ps(v30, v30, 201);
      v36 = _mm_shuffle_ps(v33, v33, 201);
      v37 = _mm_sub_ps(_mm_mul_ps(v30, v36), _mm_mul_ps(v33, v35));
      v38 = _mm_shuffle_ps(v37, v37, 201);
      v39 = _mm_sub_ps(_mm_mul_ps(v30, v81), _mm_mul_ps(v23, v35));
      v40 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v33), _mm_mul_ps(v34, v36));
      v41 = _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v38);
      v42 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), v31), _mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v32));
      v43 = _mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v38);
      v44 = _mm_unpacklo_ps(v41, v43);
      v45 = _mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v38);
      v46 = _mm_movelh_ps(v44, v45);
      if ( (_mm_movemask_ps(
              _mm_cmplt_ps(
                v80,
                _mm_add_ps(
                  _mm_shuffle_ps(_mm_unpackhi_ps(v41, v43), v45, 228),
                  _mm_add_ps(v46, _mm_shuffle_ps(_mm_movehl_ps(v46, v44), v45, 212))))) & 7) == 7 )
      {
        v47 = _mm_mul_ps(v38, v38);
        v48 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
                _mm_shuffle_ps(v47, v47, 170));
        v49 = _mm_mul_ps(v38, v23);
        v50 = _mm_sub_ps(
                v22,
                _mm_mul_ps(
                  _mm_andnot_ps(
                    _mm_cmpeq_ps((__m128)0i64, v48),
                    _mm_mul_ps(
                      _mm_rcp_ps(v48),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)),
                        _mm_shuffle_ps(v49, v49, 170)))),
                  v38));
      }
      else
      {
        v51 = _mm_mul_ps(v33, v33);
        v52 = _mm_mul_ps(v31, v31);
        v53 = _mm_mul_ps(v30, v30);
        v54 = _mm_unpacklo_ps(v53, v51);
        v55 = _mm_mul_ps(v23, v30);
        v56 = _mm_movelh_ps(v54, v52);
        v57 = _mm_shuffle_ps(_mm_unpackhi_ps(v53, v51), v52, 228);
        v58 = _mm_add_ps(v56, _mm_shuffle_ps(_mm_movehl_ps(v56, v54), v52, 212));
        v59 = _mm_mul_ps(v32, v31);
        v60 = _mm_add_ps(v57, v58);
        v61 = _mm_mul_ps(v34, v33);
        v62 = _mm_unpacklo_ps(v55, v61);
        v63 = _mm_movelh_ps(v62, v59);
        v64 = _mm_andnot_ps(
                _mm_cmpeq_ps(v60, (__m128)0i64),
                _mm_mul_ps(
                  _mm_rcp_ps(v60),
                  _mm_add_ps(
                    _mm_shuffle_ps(_mm_unpackhi_ps(v55, v61), v59, 228),
                    _mm_add_ps(v63, _mm_shuffle_ps(_mm_movehl_ps(v63, v62), v59, 212)))));
        v65 = _mm_cmplt_ps(v64, v82);
        v66 = _mm_max_ps(v80, _mm_or_ps(_mm_andnot_ps(v65, v82), _mm_and_ps(v64, v65)));
        v67 = _mm_sub_ps(v23, _mm_mul_ps(_mm_shuffle_ps(v66, v66, 0), v30));
        v68 = _mm_mul_ps(v67, v67);
        v69 = _mm_sub_ps(v34, _mm_mul_ps(_mm_shuffle_ps(v66, v66, 85), v33));
        v70 = _mm_sub_ps(v32, _mm_mul_ps(_mm_shuffle_ps(v66, v66, 170), v31));
        v71 = _mm_mul_ps(v69, v69);
        v72 = _mm_cmplt_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)),
                  _mm_shuffle_ps(v68, v68, 170)),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v71, v71, 85), _mm_shuffle_ps(v71, v71, 0)),
                  _mm_shuffle_ps(v71, v71, 170)));
        v73 = _mm_or_ps(_mm_and_ps(v67, v72), _mm_andnot_ps(v72, v69));
        v74 = _mm_mul_ps(v70, v70);
        v75 = _mm_mul_ps(v73, v73);
        v76 = _mm_cmplt_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v75, v75, 85), _mm_shuffle_ps(v75, v75, 0)),
                  _mm_shuffle_ps(v75, v75, 170)),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v74, v74, 85), _mm_shuffle_ps(v74, v74, 0)),
                  _mm_shuffle_ps(v74, v74, 170)));
        v50 = _mm_sub_ps(v22, _mm_or_ps(_mm_andnot_ps(v76, v70), _mm_and_ps(v73, v76)));
      }
      v77 = _mm_sub_ps(v22, v50);
      v78 = _mm_mul_ps(v77, v77);
      v79 = (float)(_mm_shuffle_ps(v78, v78, 85).m128_f32[0] + _mm_shuffle_ps(v78, v78, 0).m128_f32[0])
          + _mm_shuffle_ps(v78, v78, 170).m128_f32[0];
      if ( v79 < v20 )
      {
        v20 = v79;
        v18 = v50;
      }
      m_quad = v83;
      ++index;
    }
    while ( index < v21 );
  }
  *closestPointOut = (hkVector4f)v18;
}

// File Line: 357
// RVA: 0xBC0270
// attributes: thunk
void __fastcall hkaiNavMeshUtils::getClosestPointOnFace(
        hkaiNavMesh *mesh,
        hkVector4f *position,
        int faceIndex,
        hkVector4f *closestPointOut)
{
  hkaiNavMeshUtils_getClosestPointOnFace<hkaiNavMesh,0>(mesh, position, faceIndex, closestPointOut);
}

// File Line: 362
// RVA: 0xBC0280
// attributes: thunk
void __fastcall hkaiNavMeshUtils::getClosestPointOnFace(
        hkaiNavMeshInstance *mesh,
        hkVector4f *position,
        int faceIndex,
        hkVector4f *closestPointOut)
{
  hkaiNavMeshUtils_getClosestPointOnFace<hkaiNavMeshInstance,0>(mesh, position, faceIndex, closestPointOut);
}

// File Line: 367
// RVA: 0xBC0290
// attributes: thunk
void __fastcall hkaiNavMeshUtils::getClosestPointOnFaceLocal(
        hkaiNavMeshInstance *mesh,
        hkVector4f *position,
        int faceIndex,
        hkVector4f *closestPointOut)
{
  hkaiNavMeshUtils_getClosestPointOnFace<hkaiNavMeshInstance,1>(mesh, position, faceIndex, closestPointOut);
}

// File Line: 374
// RVA: 0xBCACC0
__int64 __fastcall hkaiNavMeshUtils_getClosestBoundaryOnFace<hkaiNavMesh,0>(
        hkaiNavMesh *mesh,
        const int faceIndex,
        hkVector4f *point,
        hkVector4f *up,
        hkVector4f *closestPointOut)
{
  unsigned int v5; // r10d
  hkaiNavMesh::Face *v7; // rax
  __m128 v8; // xmm10
  __int64 m_startEdgeIndex; // rdx
  __m128 m_quad; // xmm11
  int v11; // r9d
  __m128 v12; // xmm8
  __m128 v13; // xmm1
  __m128 v14; // xmm9
  hkaiNavMesh::Edge *v15; // r8
  hkVector4f *m_data; // rcx
  __m128 v17; // xmm7
  __m128 v18; // xmm1
  __m128 v19; // xmm6
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm7
  __m128 v23; // xmm5
  __m128 v24; // xmm6
  __m128 v25; // xmm4
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm1
  __m128 v29; // xmm0
  __m128 v30; // xmm1
  __m128 v31; // xmm0
  __m128 v32; // xmm2
  __m128 v33; // xmm5
  __m128 v34; // xmm9
  __m128 v35; // xmm1
  __m128 v36; // xmm7
  __m128 v37; // xmm7
  __m128 v38; // xmm6
  __m128 v39; // xmm6
  __m128 v40; // xmm2
  __int64 result; // rax

  v5 = -1;
  v7 = &mesh->m_faces.m_data[faceIndex];
  v8 = (__m128)xmmword_141A712A0;
  m_startEdgeIndex = v7->m_startEdgeIndex;
  m_quad = up->m_quad;
  v11 = m_startEdgeIndex + v7->m_numEdges;
  v12 = 0i64;
  v13 = _mm_mul_ps(m_quad, point->m_quad);
  v14 = _mm_sub_ps(
          point->m_quad,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
              _mm_shuffle_ps(v13, v13, 170)),
            m_quad));
  if ( (int)m_startEdgeIndex < v11 )
  {
    v15 = &mesh->m_edges.m_data[m_startEdgeIndex];
    do
    {
      if ( v15->m_oppositeEdge == -1 || (v15->m_flags.m_storage & 0x20) != 0 )
      {
        m_data = mesh->m_vertices.m_data;
        v17 = m_data[v15->m_a].m_quad;
        v18 = _mm_mul_ps(m_quad, v17);
        v19 = m_data[v15->m_b].m_quad;
        v20 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                _mm_shuffle_ps(v18, v18, 170));
        v21 = _mm_mul_ps(m_quad, v19);
        v22 = _mm_sub_ps(v17, _mm_mul_ps(v20, m_quad));
        v23 = _mm_sub_ps(v22, v14);
        v24 = _mm_sub_ps(
                v19,
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                    _mm_shuffle_ps(v21, v21, 170)),
                  m_quad));
        v25 = _mm_sub_ps(v22, v24);
        v26 = _mm_mul_ps(v25, v25);
        v27 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                _mm_shuffle_ps(v26, v26, 170));
        v28 = _mm_mul_ps(v23, v25);
        v29 = _mm_rcp_ps(v27);
        v30 = _mm_mul_ps(
                _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v27, v29)), v29),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                  _mm_shuffle_ps(v28, v28, 170)));
        v31 = _mm_cmplt_ps(v30, query.m_quad);
        v32 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v30, v31), _mm_andnot_ps(v31, query.m_quad)));
        v33 = _mm_sub_ps(v23, _mm_mul_ps(v32, v25));
        v34 = _mm_add_ps(v14, v33);
        v35 = _mm_mul_ps(v33, v33);
        v14 = _mm_shuffle_ps(v34, _mm_unpackhi_ps(v34, v32), 196);
        v36 = _mm_sub_ps(v22, v14);
        v37 = _mm_mul_ps(v36, v36);
        v38 = _mm_sub_ps(v24, v14);
        v39 = _mm_mul_ps(v38, v38);
        v40 = _mm_min_ps(
                _mm_min_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
                    _mm_shuffle_ps(v37, v37, 170)),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                    _mm_shuffle_ps(v39, v39, 170))),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
                  _mm_shuffle_ps(v35, v35, 170)));
        if ( v40.m128_f32[0] < v8.m128_f32[0] )
        {
          v8 = v40;
          v5 = m_startEdgeIndex;
          v12 = v14;
        }
      }
      LODWORD(m_startEdgeIndex) = m_startEdgeIndex + 1;
      ++v15;
    }
    while ( (int)m_startEdgeIndex < v11 );
  }
  result = v5;
  closestPointOut->m_quad = _mm_shuffle_ps(v12, _mm_unpackhi_ps(v12, v8), 196);
  return result;
}

// File Line: 426
// RVA: 0xBC06C0
int __fastcall hkaiNavMeshUtils::getClosestBoundaryOnFace(
        hkaiNavMesh *mesh,
        hkVector4f *point,
        int fIdx,
        hkVector4f *up,
        hkVector4f *closestPointOut)
{
  return hkaiNavMeshUtils_getClosestBoundaryOnFace<hkaiNavMesh,0>(mesh, fIdx, point, up, closestPointOut);
}

// File Line: 432
// RVA: 0xBC06E0
int __fastcall hkaiNavMeshUtils::getClosestBoundaryOnFace(
        hkaiNavMeshInstance *mesh,
        hkVector4f *point,
        int fIdx,
        hkVector4f *up,
        hkVector4f *closestPointOut)
{
  return hkaiNavMeshUtils_getClosestBoundaryOnFace<hkaiNavMeshInstance,0>(mesh, fIdx, point, up, closestPointOut);
}

// File Line: 438
// RVA: 0xBC0700
int __fastcall hkaiNavMeshUtils::getClosestBoundaryOnFaceLocal(
        hkaiNavMeshInstance *mesh,
        hkVector4f *point,
        int fIdx,
        hkVector4f *up,
        hkVector4f *closestPointOut)
{
  return hkaiNavMeshUtils_getClosestBoundaryOnFace<hkaiNavMeshInstance,1>(mesh, fIdx, point, up, closestPointOut);
}

// File Line: 446
// RVA: 0xBC9230
__int64 __fastcall hkaiNavMeshUtils::castRayFace<hkaiNavMeshInstance>(
        hkaiNavMeshUtils *this,
        hkaiNavMeshInstance *mesh,
        __m128 *faceIdx,
        hkcdRay *ray,
        hkSimdFloat32 *hitFractionOut)
{
  hkaiNavMesh::Face *v6; // rax
  int v7; // r12d
  int m_startEdgeIndex; // r14d
  hkaiNavMesh::Edge *v9; // r13
  hkaiNavMesh::Edge *v10; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v11; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v12; // r9
  int v13; // edi
  __int64 m_a; // rcx
  __m128 *v15; // rax
  __m128 v16; // xmm6
  __m128 v17; // xmm8
  int index; // esi
  unsigned __int8 v19; // bp
  int v20; // r14d
  __m128 v21; // xmm10
  __m128 v22; // xmm14
  __m128 m_quad; // xmm13
  __m128 v24; // xmm11
  __m128 v25; // xmm12
  hkaiNavMesh::Edge *v26; // rax
  __int64 v27; // rcx
  __m128 *v28; // rcx
  __int64 m_b; // rax
  __m128 v30; // xmm7
  __m128 *v31; // rax
  __m128 v32; // xmm7
  __m128 v33; // xmm15
  __m128 v34; // xmm9
  __m128 v35; // xmm14
  __m128 v36; // xmm10
  __m128 v37; // xmm10
  __m128 v38; // xmm1
  __m128 v39; // xmm4
  __m128 v40; // xmm1
  __m128 v41; // xmm3
  __m128 v42; // xmm1
  __m128 v43; // xmm8
  __m128 v44; // xmm6
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  __m128 v47; // xmm4
  __m128 v48; // xmm5
  __m128 v49; // xmm1
  __m128 v50; // xmm5
  __m128 v51; // xmm7
  __m128 v52; // xmm6
  __m128 v53; // xmm6
  __m128 v54; // xmm7
  __m128 v55; // xmm0
  __m128 v56; // xmm3
  __m128 v57; // xmm5
  __m128 v58; // xmm1
  __m128 v60; // [rsp+30h] [rbp-128h]
  __m128 v61; // [rsp+40h] [rbp-118h]
  __m128 v62; // [rsp+50h] [rbp-108h]
  __m128 v63; // [rsp+60h] [rbp-F8h]
  __m128 v64; // [rsp+70h] [rbp-E8h]
  hkaiNavMesh::Face *v65; // [rsp+160h] [rbp+8h]

  v6 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
         *(hkaiNavMesh::Face **)&this[16],
         *(_DWORD *)&this[24],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[240],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[272],
         (hkArray<int,hkContainerHeapAllocator> *)&this[224],
         (int)mesh);
  v7 = *(_DWORD *)&this[40];
  m_startEdgeIndex = v6->m_startEdgeIndex;
  v9 = *(hkaiNavMesh::Edge **)&this[32];
  v65 = v6;
  v10 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
          v9,
          v7,
          (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[256],
          (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[288],
          (hkArray<int,hkContainerHeapAllocator> *)&this[208],
          v6->m_startEdgeIndex);
  v13 = *(_DWORD *)&this[56];
  m_a = v10->m_a;
  if ( (int)m_a >= v13 )
    v15 = (__m128 *)(*(_QWORD *)&this[304] + 16i64 * ((int)m_a - v13));
  else
    v15 = (__m128 *)(*(_QWORD *)&this[48] + 16 * m_a);
  v16 = *(__m128 *)&this[128];
  v17 = *(__m128 *)&this[112];
  index = m_startEdgeIndex + 1;
  v19 = 0;
  v20 = v65->m_numEdges + m_startEdgeIndex - 1;
  v21 = *(__m128 *)&this[144];
  v22 = *(__m128 *)&this[160];
  m_quad = query.m_quad;
  v61 = v16;
  v60 = v17;
  v63 = v21;
  v64 = v22;
  v24 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 0), v17), _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 85), v16)),
            _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 170), v21)),
          v22);
  if ( index < v20 )
  {
    v25 = faceIdx[1];
    v62 = _mm_sub_ps(*faceIdx, v24);
    do
    {
      v26 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
              v9,
              v7,
              v11,
              v12,
              (hkArray<int,hkContainerHeapAllocator> *)&this[208],
              index);
      v27 = v26->m_a;
      if ( (int)v27 >= v13 )
        v28 = (__m128 *)(*(_QWORD *)&this[304] + 16i64 * ((int)v27 - v13));
      else
        v28 = (__m128 *)(*(_QWORD *)&this[48] + 16 * v27);
      m_b = v26->m_b;
      v30 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v28, *v28, 0), v17),
                  _mm_mul_ps(_mm_shuffle_ps(*v28, *v28, 85), v16)),
                _mm_mul_ps(_mm_shuffle_ps(*v28, *v28, 170), v21)),
              v22);
      if ( (int)m_b >= v13 )
        v31 = (__m128 *)(*(_QWORD *)&this[304] + 16i64 * ((int)m_b - v13));
      else
        v31 = (__m128 *)(*(_QWORD *)&this[48] + 16 * m_b);
      v32 = _mm_sub_ps(v30, v24);
      v33 = _mm_shuffle_ps(v32, v32, 201);
      v34 = _mm_sub_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*v31, *v31, 0), v17),
                    _mm_mul_ps(_mm_shuffle_ps(*v31, *v31, 85), v16)),
                  _mm_mul_ps(_mm_shuffle_ps(*v31, *v31, 170), v21)),
                v22),
              v24);
      v35 = _mm_shuffle_ps(v34, v34, 201);
      v36 = _mm_sub_ps(_mm_mul_ps(v32, v35), _mm_mul_ps(v34, v33));
      v37 = _mm_shuffle_ps(v36, v36, 201);
      v38 = _mm_mul_ps(v37, v25);
      v39 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
              _mm_shuffle_ps(v38, v38, 170));
      if ( (float)(v39.m128_f32[0] * v39.m128_f32[0]) >= 0.00000011920929 )
      {
        v40 = _mm_mul_ps(v37, v62);
        v41 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
                _mm_shuffle_ps(v40, v40, 170));
        v42 = _mm_rcp_ps(v39);
        v43 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v42, v39)), v42), _mm_sub_ps((__m128)0i64, v41));
        if ( _mm_movemask_ps(_mm_mul_ps(v41, v39)) )
        {
          if ( v43.m128_f32[0] < _mm_shuffle_ps(v25, v25, 255).m128_f32[0] )
          {
            v44 = _mm_add_ps(_mm_mul_ps(v43, v25), v62);
            v45 = _mm_sub_ps(v34, v44);
            v46 = _mm_sub_ps(v32, v44);
            v47 = _mm_mul_ps(v37, v37);
            v48 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v45, v45, 201), v46),
                    _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), v45));
            v49 = _mm_shuffle_ps(v44, v44, 201);
            v50 = _mm_mul_ps(_mm_shuffle_ps(v48, v48, 201), v37);
            v51 = _mm_sub_ps(_mm_mul_ps(v32, v49), _mm_mul_ps(v44, v33));
            v52 = _mm_sub_ps(_mm_mul_ps(v44, v35), _mm_mul_ps(v34, v49));
            v53 = _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v37);
            v54 = _mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v37);
            v55 = _mm_unpacklo_ps(v50, v54);
            v56 = _mm_movelh_ps(v55, v53);
            v57 = _mm_shuffle_ps(_mm_unpackhi_ps(v50, v54), v53, 228);
            v58 = _mm_shuffle_ps(_mm_movehl_ps(v56, v55), v53, 212);
            v16 = v61;
            if ( (_mm_movemask_ps(
                    _mm_cmple_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
                          _mm_shuffle_ps(v47, v47, 170)),
                        (__m128)_xmm_b951b717b951b717b951b717b951b717),
                      _mm_add_ps(v57, _mm_add_ps(v56, v58)))) & 7) == 7
              && v43.m128_f32[0] < m_quad.m128_f32[0] )
            {
              v19 = 1;
              m_quad = v43;
            }
          }
        }
        v17 = v60;
      }
      v21 = v63;
      v22 = v64;
      ++index;
    }
    while ( index < v20 );
    if ( v19 )
      ray->m_origin.m_quad = m_quad;
  }
  return v19;
}

// File Line: 486
// RVA: 0xBCC510
bool __fastcall hkaiNavMeshUtils::intersectLineFace<hkaiNavMeshInstance>(
        hkaiNavMeshUtils *this,
        hkaiNavMeshInstance *mesh,
        hkcdRay *faceIdx,
        hkcdRay *ray)
{
  hkaiNavMesh::Face *v7; // rsi
  __int64 m_a; // rcx
  int v9; // eax
  __m128 *v10; // rax
  int index; // edi
  hkaiNavMesh::Edge *v12; // rax
  int v13; // edx
  __int64 v14; // rcx
  __m128 *v15; // rcx
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __int64 m_b; // rax
  __m128 v19; // xmm5
  __m128 v20; // xmm6
  __m128 v21; // xmm2
  __m128 *v22; // rax
  __m128 v23; // xmm1
  bool result; // al
  hkSimdFloat32 tolerance; // [rsp+30h] [rbp-88h] BYREF
  hkVector4f vC; // [rsp+40h] [rbp-78h] BYREF
  hkVector4f vB; // [rsp+50h] [rbp-68h] BYREF
  hkVector4f vA; // [rsp+60h] [rbp-58h] BYREF
  hkSimdFloat32 fractionOut; // [rsp+70h] [rbp-48h] BYREF

  v7 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
         *(hkaiNavMesh::Face **)&this[16],
         *(_DWORD *)&this[24],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[240],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[272],
         (hkArray<int,hkContainerHeapAllocator> *)&this[224],
         (int)mesh);
  m_a = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
          *(hkaiNavMesh::Edge **)&this[32],
          *(_DWORD *)&this[40],
          (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[256],
          (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[288],
          (hkArray<int,hkContainerHeapAllocator> *)&this[208],
          v7->m_startEdgeIndex)->m_a;
  v9 = *(_DWORD *)&this[56];
  if ( (int)m_a >= v9 )
    v10 = (__m128 *)(*(_QWORD *)&this[304] + 16i64 * ((int)m_a - v9));
  else
    v10 = (__m128 *)(*(_QWORD *)&this[48] + 16 * m_a);
  vA.m_quad = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*v10, *v10, 85), *(__m128 *)&this[128]),
                    _mm_mul_ps(_mm_shuffle_ps(*v10, *v10, 0), *(__m128 *)&this[112])),
                  _mm_mul_ps(_mm_shuffle_ps(*v10, *v10, 170), *(__m128 *)&this[144])),
                *(__m128 *)&this[160]);
  index = v7->m_startEdgeIndex + 1;
  if ( index >= v7->m_numEdges + v7->m_startEdgeIndex - 1 )
    return 0;
  while ( 1 )
  {
    v12 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
            *(hkaiNavMesh::Edge **)&this[32],
            *(_DWORD *)&this[40],
            (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[256],
            (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[288],
            (hkArray<int,hkContainerHeapAllocator> *)&this[208],
            index);
    v13 = *(_DWORD *)&this[56];
    v14 = v12->m_a;
    v15 = (__m128 *)((int)v14 >= v13 ? *(_QWORD *)&this[304] + 16i64 * ((int)v14 - v13) : *(_QWORD *)&this[48]
                                                                                        + 16 * v14);
    v16 = *(__m128 *)&this[128];
    v17 = *(__m128 *)&this[112];
    m_b = v12->m_b;
    v19 = *(__m128 *)&this[144];
    v20 = *(__m128 *)&this[160];
    v21 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 0), v17),
                _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 85), v16)),
              _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 170), v19)),
            v20);
    v22 = (__m128 *)((int)m_b >= v13 ? *(_QWORD *)&this[304] + 16i64 * ((int)m_b - v13) : *(_QWORD *)&this[48]
                                                                                        + 16 * m_b);
    v23 = *v22;
    vB.m_quad = v21;
    tolerance.m_real = aabbOut.m_quad;
    vC.m_quad = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v17),
                      _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v16)),
                    _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v19)),
                  v20);
    if ( hkcdLineTriangleIntersect(faceIdx, &vA, &vB, &vC, &tolerance, &fractionOut) )
      break;
    if ( ++index >= v7->m_startEdgeIndex + v7->m_numEdges - 1 )
      return 0;
  }
  result = 1;
  ray->m_origin = (hkVector4f)fractionOut.m_real;
  return result;
}

// File Line: 561
// RVA: 0xBC7D00
void __fastcall hkaiNavMeshUtils::calcEdgeMidpoint<hkaiNavMeshInstance>(
        hkaiNavMeshUtils *this,
        hkaiNavMeshInstance *mesh,
        __m128 *edgeIndex,
        hkVector4f *midpointOut)
{
  hkVector4f edgeB; // [rsp+20h] [rbp-28h] BYREF
  hkVector4f edgeA; // [rsp+30h] [rbp-18h] BYREF

  hkaiNavMeshInstance::getEdgePoints((hkaiNavMeshInstance *)this, (int)mesh, &edgeA, &edgeB);
  *edgeIndex = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(edgeB.m_quad, edgeA.m_quad), (__m128)xmmword_141A711B0), edgeA.m_quad);
}

// File Line: 570
// RVA: 0xBC8B50
void __fastcall hkaiNavMeshUtils::calcVertexPlane<hkaiNavMeshInstance>(
        hkaiNavMeshUtils *this,
        hkaiNavMeshInstance *mesh,
        int faceIndex,
        __m128 *edgeIndex,
        hkVector4f *normal)
{
  hkaiNavMesh::Face *v7; // rax
  int v8; // r11d
  int v9; // r15d
  int m_startEdgeIndex; // ebx
  hkaiNavMesh::Edge *v11; // r12
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v12; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v13; // r9
  hkaiNavMesh::Edge *v14; // rax
  __int64 m_a; // rcx
  int v16; // edx
  hkaiNavMesh::Edge *v17; // r8
  __m128 *v18; // rcx
  __m128 v19; // xmm5
  __m128 v20; // xmm8
  __int64 m_b; // rax
  __m128 v22; // xmm9
  __m128 v23; // xmm10
  __m128 v24; // xmm7
  __m128 *v25; // rax
  __m128 v26; // xmm1
  __m128 v27; // xmm11
  __int64 v28; // rax
  __m128 v29; // xmm12
  __m128 v30; // xmm6
  __m128 v31; // xmm6
  __m128 v32; // xmm6
  __m128 v33; // xmm1
  __m128 v34; // xmm3
  __m128 v35; // xmm2
  __m128 v36; // xmm6
  __m128 *v37; // rax
  __m128 v38; // xmm1
  __int64 v39; // rax
  __m128 v40; // xmm2
  __m128 *v41; // rax
  __m128 v42; // xmm4
  __m128 v43; // xmm4
  __m128 v44; // xmm4
  __m128 v45; // xmm1
  __m128 v46; // xmm3
  __m128 v47; // xmm2
  __m128 v48; // xmm5
  __m128 v49; // xmm1
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  __m128 v52; // xmm5
  __m128 v53; // xmm2

  v7 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
         *(hkaiNavMesh::Face **)&this[16],
         *(_DWORD *)&this[24],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[240],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[272],
         (hkArray<int,hkContainerHeapAllocator> *)&this[224],
         (int)mesh);
  if ( v8 )
    v9 = v8 - 1;
  else
    v9 = v7->m_numEdges - 1;
  m_startEdgeIndex = v7->m_startEdgeIndex;
  v11 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
          *(hkaiNavMesh::Edge **)&this[32],
          *(_DWORD *)&this[40],
          (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[256],
          (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[288],
          (hkArray<int,hkContainerHeapAllocator> *)&this[208],
          v7->m_startEdgeIndex + v8);
  v14 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
          *(hkaiNavMesh::Edge **)&this[32],
          *(_DWORD *)&this[40],
          v12,
          v13,
          (hkArray<int,hkContainerHeapAllocator> *)&this[208],
          m_startEdgeIndex + v9);
  m_a = v11->m_a;
  v16 = *(_DWORD *)&this[56];
  v17 = v14;
  if ( (int)m_a >= v16 )
    v18 = (__m128 *)(*(_QWORD *)&this[304] + 16i64 * ((int)m_a - v16));
  else
    v18 = (__m128 *)(*(_QWORD *)&this[48] + 16 * m_a);
  v19 = *(__m128 *)&this[128];
  v20 = *(__m128 *)&this[112];
  m_b = v11->m_b;
  v22 = *(__m128 *)&this[144];
  v23 = *(__m128 *)&this[160];
  v24 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 0), v20), _mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 85), v19)),
            _mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 170), v22)),
          v23);
  if ( (int)m_b >= v16 )
    v25 = (__m128 *)(*(_QWORD *)&this[304] + 16i64 * ((int)m_b - v16));
  else
    v25 = (__m128 *)(*(_QWORD *)&this[48] + 16 * m_b);
  v26 = *v25;
  v27 = *edgeIndex;
  v28 = v17->m_a;
  v29 = _mm_shuffle_ps(v27, v27, 201);
  v30 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), v20), _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), v19)),
              _mm_mul_ps(_mm_shuffle_ps(v26, v26, 170), v22)),
            v23),
          v24);
  v31 = _mm_sub_ps(_mm_mul_ps(v30, v29), _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), *edgeIndex));
  v32 = _mm_shuffle_ps(v31, v31, 201);
  v33 = _mm_mul_ps(v32, v32);
  v34 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)), _mm_shuffle_ps(v33, v33, 170));
  v35 = _mm_rsqrt_ps(v34);
  v36 = _mm_mul_ps(
          v32,
          _mm_andnot_ps(
            _mm_cmple_ps(v34, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v35, v34), v35)),
              _mm_mul_ps(*(__m128 *)_xmm, v35))));
  if ( (int)v28 >= v16 )
    v37 = (__m128 *)(*(_QWORD *)&this[304] + 16i64 * ((int)v28 - v16));
  else
    v37 = (__m128 *)(*(_QWORD *)&this[48] + 16 * v28);
  v38 = *v37;
  v39 = v17->m_b;
  v40 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), v20), _mm_mul_ps(_mm_shuffle_ps(v38, v38, 85), v19)),
            _mm_mul_ps(_mm_shuffle_ps(v38, v38, 170), v22)),
          v23);
  if ( (int)v39 >= v16 )
    v41 = (__m128 *)(*(_QWORD *)&this[304] + 16i64 * ((int)v39 - v16));
  else
    v41 = (__m128 *)(*(_QWORD *)&this[48] + 16 * v39);
  v42 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*v41, *v41, 0), v20),
                _mm_mul_ps(_mm_shuffle_ps(*v41, *v41, 85), v19)),
              _mm_mul_ps(_mm_shuffle_ps(*v41, *v41, 170), v22)),
            v23),
          v40);
  v43 = _mm_sub_ps(_mm_mul_ps(v42, v29), _mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v27));
  v44 = _mm_shuffle_ps(v43, v43, 201);
  v45 = _mm_mul_ps(v44, v44);
  v46 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)), _mm_shuffle_ps(v45, v45, 170));
  v47 = _mm_rsqrt_ps(v46);
  v48 = _mm_add_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmple_ps(v46, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v47, v46), v47)),
                _mm_mul_ps(v47, *(__m128 *)_xmm))),
            v44),
          v36);
  v49 = _mm_mul_ps(v48, v48);
  v50 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)), _mm_shuffle_ps(v49, v49, 170));
  v51 = _mm_rsqrt_ps(v50);
  v52 = _mm_mul_ps(
          v48,
          _mm_andnot_ps(
            _mm_cmple_ps(v50, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v51, v50), v51)),
              _mm_mul_ps(v51, *(__m128 *)_xmm))));
  v53 = _mm_mul_ps(v52, v24);
  normal->m_quad = _mm_shuffle_ps(
                     v52,
                     _mm_unpackhi_ps(
                       v52,
                       _mm_sub_ps(
                         (__m128)0i64,
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v53, v53, 85), _mm_shuffle_ps(v53, v53, 0)),
                           _mm_shuffle_ps(v53, v53, 170)))),
                     196);
}

// File Line: 606
// RVA: 0xBBFD80
char __fastcall hkaiNavMeshUtils::isPointOnFace(
        hkaiNavMeshUtils *meshInstance,
        unsigned int faceIndex,
        hkVector4f *faceNormal,
        hkVector4f *point,
        hkSimdFloat32 *tolerance)
{
  int v7; // r12d
  hkaiNavMesh::Face *v9; // rdi
  int m_startEdgeIndex; // ebx
  __m128 v11; // xmm2
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  hkVector4f *index; // [rsp+28h] [rbp-30h]
  hkVector4f faceNormala; // [rsp+30h] [rbp-28h] BYREF

  v7 = (int)faceNormal;
  v9 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
         *(hkaiNavMesh::Face **)&meshInstance[16],
         *(_DWORD *)&meshInstance[24],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&meshInstance[240],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&meshInstance[272],
         (hkArray<int,hkContainerHeapAllocator> *)&meshInstance[224],
         faceIndex);
  m_startEdgeIndex = v9->m_startEdgeIndex;
  if ( v9->m_startEdgeIndex >= v9->m_startEdgeIndex + v9->m_numEdges )
    return 1;
  while ( 1 )
  {
    hkaiNavMeshUtils::calcEdgePlane<hkaiNavMeshInstance>(
      meshInstance,
      (hkaiNavMeshInstance *)faceIndex,
      m_startEdgeIndex,
      v7,
      &faceNormala,
      index);
    v11 = _mm_mul_ps(point->m_quad, faceNormala.m_quad);
    v12 = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, faceNormala.m_quad), 196);
    v13 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 78), v12);
    if ( (float)(_mm_shuffle_ps(v13, v13, 177).m128_f32[0] + v13.m128_f32[0]) > tolerance->m_real.m128_f32[0] )
      break;
    if ( ++m_startEdgeIndex >= v9->m_startEdgeIndex + v9->m_numEdges )
      return 1;
  }
  return 0;
}

// File Line: 623
// RVA: 0xBBFE70
__int64 __fastcall hkaiNavMeshUtils::isAwayFromBoundaryEdges(
        hkaiStreamingCollection *collection,
        hkaiNavMeshQueryMediator *mediator,
        hkVector4f *point,
        hkSimdFloat32 *radius)
{
  __m128 m_quad; // xmm2
  __m128 v5; // xmm0
  __m128 v6; // xmm2
  __m128 v7; // xmm0
  hkBaseObjectVtbl *vfptr; // rax
  int v11; // r12d
  float v12; // xmm8_4
  hkaiStreamingCollection::InstanceInfo *m_data; // r8
  _DWORD *v14; // r13
  hkaiNavMeshInstance *m_instancePtr; // rbx
  hkaiNavMesh::Face *v16; // rax
  int index; // edi
  int v18; // r15d
  int m_numOriginalEdges; // ebp
  hkaiNavMesh::Edge *m_originalEdges; // r14
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_ownedEdges; // r9
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_instancedEdges; // r8
  hkaiNavMesh::Edge *v23; // rax
  hkaiNavMesh::Edge *v24; // rax
  int m_numOriginalVertices; // edx
  __int64 m_a; // rcx
  __m128 *v27; // rcx
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  __int64 m_b; // rax
  __m128 v31; // xmm6
  __m128 v32; // xmm7
  __m128 v33; // xmm5
  __m128 *v34; // rax
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm4
  __m128 v38; // xmm5
  __m128 v39; // xmm4
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm1
  __m128 v43; // xmm3
  __m128 v44; // xmm1
  __m128 v45; // xmm2
  __m128 v46; // xmm0
  __m128 v47; // xmm5
  __m128 v48; // xmm5
  unsigned __int8 v49; // bl
  _DWORD *v51; // [rsp+30h] [rbp-D8h] BYREF
  int v52; // [rsp+38h] [rbp-D0h]
  int v53; // [rsp+3Ch] [rbp-CCh]
  int v54; // [rsp+40h] [rbp-C8h] BYREF
  __int64 v55; // [rsp+48h] [rbp-C0h]
  __int128 v56; // [rsp+50h] [rbp-B8h]
  __int64 v57; // [rsp+60h] [rbp-A8h]
  __m128 v58; // [rsp+70h] [rbp-98h]
  __m128 v59; // [rsp+80h] [rbp-88h]
  hkaiStreamingCollection::InstanceInfo *i; // [rsp+118h] [rbp+10h]

  m_quad = point->m_quad;
  v56 = 0i64;
  v5 = m_quad;
  v6 = _mm_add_ps(m_quad, radius->m_real);
  v7 = _mm_sub_ps(v5, radius->m_real);
  v54 = 0;
  v55 = 0i64;
  v58 = v7;
  v57 = 0i64;
  v59 = v6;
  vfptr = mediator->vfptr;
  v51 = 0i64;
  v52 = 0;
  v53 = 0x80000000;
  ((void (__fastcall *)(hkaiNavMeshQueryMediator *, int *, _DWORD **))vfptr[3].__first_virtual_table_function__)(
    mediator,
    &v54,
    &v51);
  v11 = 0;
  v12 = radius->m_real.m128_f32[0] * radius->m_real.m128_f32[0];
  if ( v52 <= 0 )
  {
LABEL_18:
    v49 = 1;
  }
  else
  {
    m_data = collection->m_instances.m_data;
    v14 = v51;
    for ( i = m_data; ; m_data = i )
    {
      m_instancePtr = m_data[*v14 >> 22].m_instancePtr;
      v16 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
              m_instancePtr->m_originalFaces,
              m_instancePtr->m_numOriginalFaces,
              &m_instancePtr->m_instancedFaces,
              &m_instancePtr->m_ownedFaces,
              &m_instancePtr->m_faceMap,
              *v14 & 0x3FFFFF);
      index = v16->m_startEdgeIndex;
      v18 = v16->m_startEdgeIndex + v16->m_numEdges;
      if ( v16->m_startEdgeIndex < v18 )
        break;
LABEL_15:
      ++v11;
      ++v14;
      if ( v11 >= v52 )
        goto LABEL_18;
    }
    m_numOriginalEdges = m_instancePtr->m_numOriginalEdges;
    m_originalEdges = m_instancePtr->m_originalEdges;
    p_m_ownedEdges = &m_instancePtr->m_ownedEdges;
    p_m_instancedEdges = &m_instancePtr->m_instancedEdges;
    while ( 1 )
    {
      v23 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
              m_originalEdges,
              m_numOriginalEdges,
              p_m_instancedEdges,
              p_m_ownedEdges,
              &m_instancePtr->m_edgeMap,
              index);
      if ( v23->m_oppositeEdge == -1 || (v23->m_flags.m_storage & 0x20) != 0 )
      {
        v24 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
                m_originalEdges,
                m_numOriginalEdges,
                p_m_instancedEdges,
                p_m_ownedEdges,
                &m_instancePtr->m_edgeMap,
                index);
        m_numOriginalVertices = m_instancePtr->m_numOriginalVertices;
        m_a = v24->m_a;
        v27 = (__m128 *)((int)m_a >= m_numOriginalVertices
                       ? &m_instancePtr->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices]
                       : &m_instancePtr->m_originalVertices[m_a]);
        v28 = m_instancePtr->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
        v29 = m_instancePtr->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
        m_b = v24->m_b;
        v31 = m_instancePtr->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
        v32 = m_instancePtr->m_referenceFrame.m_transform.m_translation.m_quad;
        v33 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 0), v29),
                    _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 85), v28)),
                  _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 170), v31)),
                v32);
        v34 = (__m128 *)((int)m_b >= m_numOriginalVertices
                       ? &m_instancePtr->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices]
                       : &m_instancePtr->m_originalVertices[m_b]);
        v35 = *v34;
        v36 = _mm_mul_ps(_mm_shuffle_ps(v35, v35, 0), v29);
        v37 = v33;
        v38 = _mm_sub_ps(v33, point->m_quad);
        v39 = _mm_sub_ps(
                v37,
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(v36, _mm_mul_ps(_mm_shuffle_ps(v35, v35, 85), v28)),
                    _mm_mul_ps(_mm_shuffle_ps(v35, v35, 170), v31)),
                  v32));
        v40 = _mm_mul_ps(v39, v39);
        v41 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
                _mm_shuffle_ps(v40, v40, 170));
        v42 = _mm_mul_ps(v38, v39);
        v43 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)),
                _mm_shuffle_ps(v42, v42, 170));
        v44 = _mm_rcp_ps(v41);
        v45 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v44, v41)), v44), v43);
        v46 = _mm_cmplt_ps(v45, query.m_quad);
        v47 = _mm_sub_ps(
                v38,
                _mm_mul_ps(
                  _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v46, query.m_quad), _mm_and_ps(v45, v46))),
                  v39));
        v48 = _mm_mul_ps(v47, v47);
        if ( (float)((float)(_mm_shuffle_ps(v48, v48, 85).m128_f32[0] + _mm_shuffle_ps(v48, v48, 0).m128_f32[0])
                   + _mm_shuffle_ps(v48, v48, 170).m128_f32[0]) < v12 )
          break;
      }
      if ( ++index >= v18 )
        goto LABEL_15;
    }
    v49 = 0;
  }
  v52 = 0;
  if ( v53 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v51, 4 * v53);
  return v49;
}

// File Line: 662
// RVA: 0xBC7F80
void __fastcall hkaiNavMeshUtils::calcFaceAabb<hkaiNavMeshInstance>(
        hkaiNavMeshUtils *this,
        hkaiNavMeshInstance *mesh,
        __m128 *faceIndex,
        hkSimdFloat32 *extraRadius,
        hkAabb *aabbOut)
{
  __m128 v5; // xmm7
  __m128 v8; // xmm6
  hkaiNavMesh::Face *v9; // rax
  int index; // esi
  int v11; // r12d
  int v12; // edi
  int v13; // r14d
  __m128 v14; // xmm8
  hkaiNavMesh::Edge *v15; // r15
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v16; // r9
  __m128 v17; // xmm9
  __m128 v18; // xmm10
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v19; // r8
  __m128 v20; // xmm11
  __int64 m_a; // rcx
  __m128 *v22; // rax
  __m128 v23; // xmm2
  __m128 v24; // xmm6

  v5 = (__m128)xmmword_141A712A0;
  v8 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), (__m128)xmmword_141A712A0);
  v9 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
         *(hkaiNavMesh::Face **)&this[16],
         *(_DWORD *)&this[24],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[240],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[272],
         (hkArray<int,hkContainerHeapAllocator> *)&this[224],
         (int)mesh);
  index = v9->m_startEdgeIndex;
  v11 = v9->m_startEdgeIndex + v9->m_numEdges;
  if ( v9->m_startEdgeIndex < v11 )
  {
    v12 = *(_DWORD *)&this[56];
    v13 = *(_DWORD *)&this[40];
    v14 = *(__m128 *)&this[128];
    v15 = *(hkaiNavMesh::Edge **)&this[32];
    v16 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[288];
    v17 = *(__m128 *)&this[112];
    v18 = *(__m128 *)&this[144];
    v19 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[256];
    v20 = *(__m128 *)&this[160];
    do
    {
      m_a = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
              v15,
              v13,
              v19,
              v16,
              (hkArray<int,hkContainerHeapAllocator> *)&this[208],
              index)->m_a;
      if ( (int)m_a >= v12 )
        v22 = (__m128 *)(*(_QWORD *)&this[304] + 16i64 * ((int)m_a - v12));
      else
        v22 = (__m128 *)(*(_QWORD *)&this[48] + 16 * m_a);
      ++index;
      v23 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v22, *v22, 0), v17),
                  _mm_mul_ps(_mm_shuffle_ps(*v22, *v22, 85), v14)),
                _mm_mul_ps(_mm_shuffle_ps(*v22, *v22, 170), v18)),
              v20);
      v5 = _mm_min_ps(v5, v23);
      v8 = _mm_max_ps(v8, v23);
    }
    while ( index < v11 );
  }
  v24 = _mm_add_ps(v8, *faceIndex);
  extraRadius->m_real = _mm_sub_ps(v5, *faceIndex);
  extraRadius[1] = (hkSimdFloat32)v24;
}

// File Line: 678
// RVA: 0xBC0220
void __fastcall hkaiNavMeshUtils::calcMeshAabb(hkaiNavMesh *mesh, hkSimdFloat32 *extraRadius, hkAabb *aabbOut)
{
  hkVector4f v5; // xmm1

  hkAabbUtil::calcAabb(mesh->m_vertices.m_data, mesh->m_vertices.m_size, aabbOut);
  v5.m_quad = (__m128)aabbOut->m_min;
  aabbOut->m_max.m_quad = _mm_add_ps(aabbOut->m_max.m_quad, extraRadius->m_real);
  aabbOut->m_min.m_quad = _mm_sub_ps(v5.m_quad, extraRadius->m_real);
}

// File Line: 684
// RVA: 0xBC07C0
void __fastcall hkaiNavMeshUtils::createFaceIndexArray(
        hkaiNavMesh *mesh,
        hkArray<int,hkContainerTempAllocator> *faceIndices)
{
  int m_capacityAndFlags; // eax
  int v3; // ebx
  int m_size; // esi
  int v6; // eax
  int v8; // eax
  int v9; // r9d
  __int64 v10; // rdx
  int *v11; // rdi
  __int64 v12; // rcx
  __int64 i; // r9
  hkaiNavMesh::Face *v14; // rdi
  int m_startEdgeIndex; // eax
  int m_startUserEdgeIndex; // r8d
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  m_capacityAndFlags = faceIndices->m_capacityAndFlags;
  v3 = 0;
  faceIndices->m_size = 0;
  m_size = mesh->m_edges.m_size;
  v6 = m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < m_size )
  {
    v8 = 2 * v6;
    v9 = mesh->m_edges.m_size;
    if ( m_size < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, faceIndices, v9, 4);
  }
  v10 = faceIndices->m_size;
  v11 = &faceIndices->m_data[v10];
  v12 = m_size - (int)v10;
  if ( m_size - (int)v10 > 0 )
  {
    while ( v12 )
    {
      *v11++ = -1;
      --v12;
    }
  }
  faceIndices->m_size = m_size;
  if ( mesh->m_faces.m_size > 0 )
  {
    for ( i = 0i64; ; ++i )
    {
      v14 = &mesh->m_faces.m_data[i];
      m_startEdgeIndex = v14->m_numUserEdges <= 0 ? v14->m_startEdgeIndex : v14->m_startUserEdgeIndex;
      if ( m_startEdgeIndex != -1 )
        break;
LABEL_22:
      if ( ++v3 >= mesh->m_faces.m_size )
        return;
    }
    while ( 1 )
    {
      faceIndices->m_data[m_startEdgeIndex] = v3;
      m_startUserEdgeIndex = v14->m_startUserEdgeIndex;
      if ( m_startEdgeIndex >= m_startUserEdgeIndex && m_startEdgeIndex < v14->m_numUserEdges + m_startUserEdgeIndex - 1 )
        goto LABEL_20;
      if ( m_startEdgeIndex != v14->m_numUserEdges + m_startUserEdgeIndex - 1 )
        break;
      m_startEdgeIndex = v14->m_startEdgeIndex;
LABEL_21:
      if ( m_startEdgeIndex == -1 )
        goto LABEL_22;
    }
    if ( m_startEdgeIndex < v14->m_startEdgeIndex || m_startEdgeIndex >= v14->m_numEdges + v14->m_startEdgeIndex - 1 )
      goto LABEL_22;
LABEL_20:
    ++m_startEdgeIndex;
    goto LABEL_21;
  }
}

// File Line: 700
// RVA: 0xBC08D0
void __fastcall hkaiNavMeshUtils::createOwnedFaceIndexArray(
        hkaiNavMeshInstance *meshInstance,
        hkArray<int,hkContainerTempAllocator> *faceIndices)
{
  int m_capacityAndFlags; // eax
  int v3; // esi
  int m_size; // ebx
  int v6; // eax
  int v8; // eax
  int v9; // r9d
  __int64 v10; // rdx
  int *v11; // rdi
  __int64 v12; // rcx
  __int64 i; // r9
  hkaiNavMesh::Face *v14; // rdi
  int m_startEdgeIndex; // eax
  int m_startUserEdgeIndex; // r8d
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  m_capacityAndFlags = faceIndices->m_capacityAndFlags;
  v3 = 0;
  faceIndices->m_size = 0;
  m_size = meshInstance->m_ownedEdges.m_size;
  v6 = m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < m_size )
  {
    v8 = 2 * v6;
    v9 = meshInstance->m_ownedEdges.m_size;
    if ( m_size < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, faceIndices, v9, 4);
  }
  v10 = faceIndices->m_size;
  v11 = &faceIndices->m_data[v10];
  v12 = m_size - (int)v10;
  if ( m_size - (int)v10 > 0 )
  {
    while ( v12 )
    {
      *v11++ = -1;
      --v12;
    }
  }
  faceIndices->m_size = m_size;
  if ( meshInstance->m_ownedFaces.m_size > 0 )
  {
    for ( i = 0i64; ; ++i )
    {
      v14 = &meshInstance->m_ownedFaces.m_data[i];
      m_startEdgeIndex = v14->m_numUserEdges <= 0 ? v14->m_startEdgeIndex : v14->m_startUserEdgeIndex;
      if ( m_startEdgeIndex != -1 )
        break;
LABEL_22:
      if ( ++v3 >= meshInstance->m_ownedFaces.m_size )
        return;
    }
    while ( 1 )
    {
      faceIndices->m_data[m_startEdgeIndex - (__int64)meshInstance->m_numOriginalEdges] = v3;
      m_startUserEdgeIndex = v14->m_startUserEdgeIndex;
      if ( m_startEdgeIndex >= m_startUserEdgeIndex && m_startEdgeIndex < v14->m_numUserEdges + m_startUserEdgeIndex - 1 )
        goto LABEL_20;
      if ( m_startEdgeIndex != v14->m_numUserEdges + m_startUserEdgeIndex - 1 )
        break;
      m_startEdgeIndex = v14->m_startEdgeIndex;
LABEL_21:
      if ( m_startEdgeIndex == -1 )
        goto LABEL_22;
    }
    if ( m_startEdgeIndex < v14->m_startEdgeIndex || m_startEdgeIndex >= v14->m_numEdges + v14->m_startEdgeIndex - 1 )
      goto LABEL_22;
LABEL_20:
    ++m_startEdgeIndex;
    goto LABEL_21;
  }
}

// File Line: 719
// RVA: 0xBC0A00
void __fastcall hkaiNavMeshUtils::createInstancedFaceIndexArray(
        hkaiNavMeshInstance *meshInstance,
        hkArray<int,hkContainerTempAllocator> *faceIndices)
{
  int m_capacityAndFlags; // eax
  int v3; // esi
  int m_size; // ebx
  int v6; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // edx
  int *v11; // rdi
  __int64 v12; // rcx
  __int64 i; // r9
  hkaiNavMesh::Face *v14; // rdi
  int m_startEdgeIndex; // eax
  __int64 m_numOriginalEdges; // rcx
  int m_startUserEdgeIndex; // r8d
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  m_capacityAndFlags = faceIndices->m_capacityAndFlags;
  v3 = 0;
  faceIndices->m_size = 0;
  m_size = meshInstance->m_ownedEdges.m_size;
  v6 = m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < m_size )
  {
    v8 = 2 * v6;
    v9 = meshInstance->m_ownedEdges.m_size;
    if ( m_size < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, faceIndices, v9, 4);
  }
  v10 = m_size - faceIndices->m_size;
  v11 = &faceIndices->m_data[faceIndices->m_size];
  v12 = v10;
  if ( v10 > 0 )
  {
    while ( v12 )
    {
      *v11++ = -1;
      --v12;
    }
  }
  faceIndices->m_size = m_size;
  if ( meshInstance->m_instancedFaces.m_size > 0 )
  {
    for ( i = 0i64; ; ++i )
    {
      v14 = &meshInstance->m_instancedFaces.m_data[i];
      m_startEdgeIndex = v14->m_numUserEdges <= 0 ? v14->m_startEdgeIndex : v14->m_startUserEdgeIndex;
      if ( m_startEdgeIndex != -1 )
        break;
LABEL_24:
      if ( ++v3 >= meshInstance->m_instancedFaces.m_size )
        return;
    }
    while ( 1 )
    {
      m_numOriginalEdges = meshInstance->m_numOriginalEdges;
      if ( m_startEdgeIndex >= (int)m_numOriginalEdges )
        faceIndices->m_data[m_startEdgeIndex - m_numOriginalEdges] = v3;
      m_startUserEdgeIndex = v14->m_startUserEdgeIndex;
      if ( m_startEdgeIndex >= m_startUserEdgeIndex && m_startEdgeIndex < v14->m_numUserEdges + m_startUserEdgeIndex - 1 )
        goto LABEL_22;
      if ( m_startEdgeIndex != v14->m_numUserEdges + m_startUserEdgeIndex - 1 )
        break;
      m_startEdgeIndex = v14->m_startEdgeIndex;
LABEL_23:
      if ( m_startEdgeIndex == -1 )
        goto LABEL_24;
    }
    if ( m_startEdgeIndex < v14->m_startEdgeIndex || m_startEdgeIndex >= v14->m_numEdges + v14->m_startEdgeIndex - 1 )
      goto LABEL_24;
LABEL_22:
    ++m_startEdgeIndex;
    goto LABEL_23;
  }
}

// File Line: 755
// RVA: 0xBC7630
void __fastcall copyStructAndData_hkaiNavMesh::Edge_int_(
        hkaiNavMesh::Edge *dstT,
        char *dstData,
        hkaiNavMesh::Edge *srcT,
        char *srcData,
        int dataStride)
{
  __int64 v5; // rcx
  signed __int64 v6; // r9
  int v7; // eax

  *dstT = *srcT;
  if ( dataStride == 1 )
  {
    *(_DWORD *)dstData = *(_DWORD *)srcData;
  }
  else
  {
    v5 = dataStride;
    if ( dataStride >= 1i64 )
    {
      v6 = srcData - dstData;
      do
      {
        v7 = *(_DWORD *)&dstData[v6];
        dstData += 4;
        *((_DWORD *)dstData - 1) = v7;
        --v5;
      }
      while ( v5 );
    }
  }
}

// File Line: 761
// RVA: 0xBC75B0
void __fastcall copyEdgeAndData(hkaiNavMesh *mesh, int dstIdx, int srcIdx)
{
  int dataStride; // r11d
  __int64 v4; // rbx
  int *v5; // rdx
  const int *v6; // r9

  dataStride = mesh->m_edgeDataStriding;
  v4 = dstIdx;
  v5 = 0i64;
  if ( dataStride )
    v6 = &mesh->m_edgeData.m_data[srcIdx * dataStride];
  else
    v6 = 0i64;
  if ( dataStride )
    v5 = &mesh->m_edgeData.m_data[(int)v4 * dataStride];
  copyStructAndData_hkaiNavMesh::Edge_int_(&mesh->m_edges.m_data[v4], v5, &mesh->m_edges.m_data[srcIdx], v6, dataStride);
}

// File Line: 766
// RVA: 0xBC76A0
void __fastcall copyFaceAndData(hkaiNavMesh *mesh, int dstIdx, int srcIdx)
{
  int dataStride; // r10d
  __int64 v4; // rbx
  int *v5; // rdx
  const int *v6; // r9

  dataStride = mesh->m_faceDataStriding;
  v4 = dstIdx;
  v5 = 0i64;
  if ( dataStride )
    v6 = &mesh->m_faceData.m_data[srcIdx * dataStride];
  else
    v6 = 0i64;
  if ( dataStride )
    v5 = &mesh->m_faceData.m_data[(int)v4 * dataStride];
  copyStructAndData_hkaiNavMesh::Face_int_(&mesh->m_faces.m_data[v4], v5, &mesh->m_faces.m_data[srcIdx], v6, dataStride);
}

// File Line: 771
// RVA: 0xBC0C00
hkResult *__fastcall hkaiNavMeshUtils::removeFaces(
        hkResult *result,
        hkaiNavMesh *mesh,
        __int64 facesToRemove,
        bool invalidateOppEdges)
{
  int v5; // r8d
  hkResult *v8; // r15
  __int64 v10; // rsi
  int v11; // r9d
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // ebx
  __int64 v16; // r15
  hkaiNavMesh::Face *v17; // rdx
  int m_startEdgeIndex; // edi
  int m_startUserEdgeIndex; // r9d
  int v20; // eax
  unsigned __int64 v21; // rdx
  __int16 v22; // r10
  __int16 v23; // r11
  hkaiNavMesh::Edge *m_data; // r8
  unsigned int m_oppositeEdge; // eax
  int m_size; // edi
  unsigned int v27; // eax
  int v28; // edi
  int v29; // eax
  int v30; // eax
  int v31; // r9d
  int v32; // r9d
  int m_capacityAndFlags; // r8d
  int v34; // ebx
  hkResultEnum v35; // r13d
  int v36; // edi
  __int32 v37; // ecx
  void *v38; // r8
  int v39; // eax
  int v40; // ecx
  int v41; // r9d
  int v42; // edi
  __int64 v43; // rcx
  _DWORD *v44; // rdi
  int *v45; // r9
  int v46; // r8d
  int *v47; // r12
  int v48; // ebx
  int v49; // r8d
  int v50; // r13d
  __int64 v51; // r15
  __int64 v52; // r10
  hkaiNavMesh::Face *v53; // rdx
  __int16 m_numUserEdges; // ax
  signed int v55; // edx
  __m128i si128; // xmm3
  __m128i v57; // xmm2
  __m128i v58; // xmm1
  int v59; // eax
  __m128i v60; // xmm0
  __int64 v61; // rsi
  hkResultEnum m_enum; // r11d
  __int64 v63; // rdi
  __int32 v64; // edx
  __int64 v65; // r8
  int v66; // edi
  int v67; // ecx
  __int64 v68; // r12
  int v69; // r15d
  _DWORD *v70; // rbx
  int v71; // edi
  int v72; // r10d
  __int64 v73; // r11
  hkaiNavMesh::Face *v74; // r8
  __int64 v75; // rax
  bool v76; // cc
  hkaiNavMesh::Edge *v77; // r9
  unsigned int v78; // edx
  unsigned int v79; // edi
  unsigned int v80; // edx
  int v81; // edi
  int v82; // r8d
  hkResult v83; // [rsp+30h] [rbp-29h] BYREF
  hkResult resulta; // [rsp+34h] [rbp-25h] BYREF
  char *v85; // [rsp+38h] [rbp-21h] BYREF
  int v86; // [rsp+40h] [rbp-19h]
  int v87; // [rsp+44h] [rbp-15h]
  hkArray<int,hkContainerTempAllocator> faceIndices; // [rsp+48h] [rbp-11h] BYREF
  char *array; // [rsp+58h] [rbp-1h] BYREF
  int v90; // [rsp+60h] [rbp+7h]
  int v91; // [rsp+64h] [rbp+Bh]
  unsigned __int64 v92; // [rsp+68h] [rbp+Fh] BYREF
  __int64 v93; // [rsp+70h] [rbp+17h]
  int v94; // [rsp+78h] [rbp+1Fh]
  _DWORD **v96; // [rsp+D0h] [rbp+77h] BYREF

  v96 = (_DWORD **)facesToRemove;
  v5 = *(_DWORD *)(facesToRemove + 8);
  v8 = result;
  if ( !v5 )
  {
    result->m_enum = HK_SUCCESS;
    return result;
  }
  if ( v5 > 1 )
    hkAlgorithm::quickSortRecursive<int,hkAlgorithm::less<int>>(*(int **)facesToRemove, 0, v5 - 1, 0);
  v10 = 0i64;
  v11 = *(_DWORD *)(facesToRemove + 8) + 1;
  v12 = *(_DWORD *)(facesToRemove + 12) & 0x3FFFFFFF;
  if ( v12 >= v11 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    v13 = 2 * v12;
    if ( v11 < v13 )
      v11 = v13;
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, (void *)facesToRemove, v11, 4);
    if ( resulta.m_enum )
    {
      v8->m_enum = HK_FAILURE;
      return v8;
    }
  }
  if ( *(_DWORD *)(facesToRemove + 8) == (*(_DWORD *)(facesToRemove + 12) & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (void *)facesToRemove, 4);
  *(_DWORD *)(*(_QWORD *)facesToRemove + 4i64 * *(int *)(facesToRemove + 8)) = -1;
  v14 = *(_DWORD *)(facesToRemove + 8);
  *(_DWORD *)(facesToRemove + 8) = v14;
  if ( invalidateOppEdges )
  {
    v15 = 0;
    if ( v14 > 0 )
    {
      v16 = 0i64;
      while ( 1 )
      {
        v17 = &mesh->m_faces.m_data[*(int *)(v16 + *(_QWORD *)facesToRemove)];
        m_startEdgeIndex = v17->m_startEdgeIndex;
        m_startUserEdgeIndex = v17->m_startUserEdgeIndex;
        LODWORD(v93) = *(_DWORD *)&v17->m_numEdges;
        v20 = *(_DWORD *)&v17->m_clusterIndex;
        v92 = __PAIR64__(m_startUserEdgeIndex, m_startEdgeIndex);
        HIDWORD(v93) = v20;
        if ( SWORD1(v93) <= 0 )
          LODWORD(v21) = m_startEdgeIndex;
        else
          v21 = HIDWORD(v92);
        if ( (_DWORD)v21 != -1 )
          break;
LABEL_31:
        ++v15;
        v16 += 4i64;
        if ( v15 >= *(_DWORD *)(facesToRemove + 8) )
        {
          v8 = result;
          goto LABEL_33;
        }
      }
      v22 = WORD1(v93);
      v23 = v93;
      while ( 1 )
      {
        m_data = mesh->m_edges.m_data;
        m_oppositeEdge = m_data[(int)v21].m_oppositeEdge;
        if ( m_oppositeEdge != -1 )
          *(_QWORD *)&m_data[m_oppositeEdge & 0x3FFFFF].m_oppositeEdge = -1i64;
        if ( (int)v21 >= m_startUserEdgeIndex && (int)v21 < v22 + m_startUserEdgeIndex - 1 )
          goto LABEL_29;
        if ( (_DWORD)v21 != v22 + m_startUserEdgeIndex - 1 )
          break;
        LODWORD(v21) = m_startEdgeIndex;
LABEL_30:
        if ( (_DWORD)v21 == -1 )
          goto LABEL_31;
      }
      if ( (int)v21 < m_startEdgeIndex || (int)v21 >= v23 + m_startEdgeIndex - 1 )
        goto LABEL_31;
LABEL_29:
      LODWORD(v21) = v21 + 1;
      goto LABEL_30;
    }
  }
LABEL_33:
  m_size = mesh->m_faces.m_size;
  v27 = 0x80000000;
  array = 0i64;
  v90 = 0;
  v91 = 0x80000000;
  v85 = 0i64;
  v86 = 0;
  v87 = 0x80000000;
  if ( m_size <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, m_size, 4);
    if ( resulta.m_enum )
    {
LABEL_41:
      v8->m_enum = HK_FAILURE;
LABEL_47:
      v86 = 0;
      if ( v87 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v85, 4 * v87);
      v85 = 0i64;
      v87 = 0x80000000;
      v90 = 0;
      if ( v91 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v91);
      return v8;
    }
    v27 = v87;
  }
  v90 = m_size;
  v28 = mesh->m_edges.m_size;
  v29 = v27 & 0x3FFFFFFF;
  if ( v29 < v28 )
  {
    v30 = 2 * v29;
    v31 = mesh->m_edges.m_size;
    if ( v28 < v30 )
      v31 = v30;
    hkArrayUtil::_reserve(&v83, &hkContainerTempAllocator::s_alloc, &v85, v31, 4);
    if ( v83.m_enum )
      goto LABEL_41;
  }
  v32 = mesh->m_edges.m_size;
  v86 = v28;
  faceIndices.m_data = 0i64;
  faceIndices.m_size = 0;
  faceIndices.m_capacityAndFlags = 0x80000000;
  if ( v32 > 0 )
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &faceIndices, v32, 4);
    if ( resulta.m_enum )
    {
      m_capacityAndFlags = faceIndices.m_capacityAndFlags;
      v8->m_enum = HK_FAILURE;
      faceIndices.m_size = 0;
      if ( m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          faceIndices.m_data,
          4 * m_capacityAndFlags);
      faceIndices.m_data = 0i64;
      faceIndices.m_capacityAndFlags = 0x80000000;
      goto LABEL_47;
    }
  }
  hkaiNavMeshUtils::createFaceIndexArray(mesh, &faceIndices);
  v34 = mesh->m_faces.m_size;
  v35 = HK_SUCCESS;
  v83.m_enum = HK_SUCCESS;
  v92 = 0i64;
  v36 = (v34 + 31) >> 5;
  v93 = 0x8000000000000000ui64;
  v37 = v36;
  if ( v36 )
  {
    resulta.m_enum = 4 * v36;
    v38 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &resulta);
    v37 = resulta.m_enum / 4;
  }
  else
  {
    v38 = 0i64;
  }
  v39 = 0x80000000;
  v92 = (unsigned __int64)v38;
  if ( v37 )
    v39 = v37;
  LODWORD(v93) = (v34 + 31) >> 5;
  v94 = v34;
  HIDWORD(v93) = v39;
  v40 = v39 & 0x3FFFFFFF;
  if ( (v39 & 0x3FFFFFFF) < v36 )
  {
    v41 = (v34 + 31) >> 5;
    if ( v36 < 2 * v40 )
      v41 = 2 * v40;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &v92, v41, 4);
    v39 = HIDWORD(v93);
  }
  LODWORD(v93) = (v34 + 31) >> 5;
  if ( !v92 )
  {
    v8->m_enum = HK_FAILURE;
    LODWORD(v93) = 0;
    if ( v39 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, 0i64, 4 * v39);
    v92 = 0i64;
    HIDWORD(v93) = 0x80000000;
    faceIndices.m_size = 0;
    if ( faceIndices.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        faceIndices.m_data,
        4 * faceIndices.m_capacityAndFlags);
    faceIndices.m_data = 0i64;
    faceIndices.m_capacityAndFlags = 0x80000000;
    v86 = 0;
    if ( v87 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v85, 4 * v87);
    v85 = 0i64;
    v87 = 0x80000000;
    v90 = 0;
    if ( v91 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v91);
    return v8;
  }
  v42 = v36 - 1;
  if ( v42 >= 0 )
  {
    v43 = (unsigned int)(v42 + 1);
    v44 = (_DWORD *)v92;
    while ( v43 )
    {
      *v44++ = 0;
      --v43;
    }
    v39 = HIDWORD(v93);
  }
  v45 = *(int **)facesToRemove;
  v46 = 0;
  if ( mesh->m_faces.m_size > 0 )
  {
    do
    {
      if ( v46 == *v45 )
      {
        *(_DWORD *)(v92 + 4 * ((__int64)v46 >> 5)) |= 1 << (v46 & 0x1F);
        ++v45;
      }
      ++v46;
    }
    while ( v46 < mesh->m_faces.m_size );
    v39 = HIDWORD(v93);
  }
  v47 = faceIndices.m_data;
  v48 = 0;
  v49 = 0;
  resulta.m_enum = HK_SUCCESS;
  if ( mesh->m_edges.m_size > 0 )
  {
    do
    {
      v50 = 1;
      v51 = v49;
      v52 = faceIndices.m_data[v51];
      if ( (int)v52 >= 0 )
      {
        v53 = &mesh->m_faces.m_data[v52];
        if ( (mesh->m_edges.m_data[v49].m_flags.m_storage & 0x10) != 0 )
          m_numUserEdges = v53->m_numUserEdges;
        else
          m_numUserEdges = v53->m_numEdges;
        v50 = m_numUserEdges;
      }
      v55 = 0;
      v45 = 0i64;
      if ( v50 >= 4 )
      {
        si128 = _mm_load_si128((const __m128i *)&_xmm);
        v57 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v83.m_enum), 0);
        v58 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v49), 0);
        do
        {
          v59 = v55 + v49;
          v60 = _mm_cvtsi32_si128(v55);
          v55 += 4;
          ++v45;
          *(__m128i *)&v85[4 * v59] = _mm_sub_epi32(
                                        _mm_add_epi32(_mm_add_epi32(_mm_shuffle_epi32(v60, 0), si128), v58),
                                        v57);
        }
        while ( v55 < (int)(v50 - (v50 & 0x80000003)) );
      }
      v61 = v50;
      if ( (__int64)v45 >= v50 )
      {
        m_enum = v83.m_enum;
      }
      else
      {
        m_enum = v83.m_enum;
        v63 = 4i64 * ((_QWORD)v45 + v49);
        v64 = v49 + v55 - v83.m_enum;
        v65 = v50 - (_QWORD)v45;
        do
        {
          v63 += 4i64;
          *(_DWORD *)&v85[v63 - 4] = v64++;
          --v65;
        }
        while ( v65 );
        v49 = resulta.m_enum;
      }
      if ( (int)v52 < 0 || ((*(_DWORD *)(v92 + 4 * (v52 >> 5)) >> (v52 & 0x1F)) & 1) != 0 )
      {
        v83.m_enum = v50 + m_enum;
      }
      else if ( v50 > 0 )
      {
        v66 = v49 - v48;
        do
        {
          copyEdgeAndData(mesh, v48, v66 + v48);
          ++v47;
          v67 = faceIndices.m_data[v51];
          ++v48;
          ++v51;
          *(v47 - 1) = v67;
          --v61;
        }
        while ( v61 );
        v49 = resulta.m_enum;
      }
      v49 += v50;
      v10 = 0i64;
      resulta.m_enum = v49;
    }
    while ( v49 < mesh->m_edges.m_size );
    v39 = HIDWORD(v93);
    v35 = v83.m_enum;
  }
  v68 = (__int64)v96;
  v69 = 0;
  v70 = *v96;
  v71 = 0;
  if ( mesh->m_faces.m_size > 0 )
  {
    do
    {
      *(_DWORD *)&array[v10] = v71 - (((__int64)v70 - *(_QWORD *)v68) >> 2);
      if ( v71 == *v70 )
        ++v70;
      else
        copyFaceAndData(mesh, v69++, v71);
      ++v71;
      v10 += 4i64;
    }
    while ( v71 < mesh->m_faces.m_size );
    v39 = HIDWORD(v93);
  }
  LODWORD(v93) = 0;
  if ( v39 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, unsigned __int64, _QWORD, int *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v92,
      (unsigned int)(4 * v39),
      v45);
  hkaiNavMesh::setFacesSize(mesh, (hkResult *)&v96, mesh->m_faces.m_size - *(_DWORD *)(v68 + 8));
  hkaiNavMesh::setEdgesSize(mesh, (hkResult *)&v96, mesh->m_edges.m_size - v35);
  v72 = 0;
  if ( mesh->m_faces.m_size > 0 )
  {
    v73 = 0i64;
    while ( 1 )
    {
      v74 = &mesh->m_faces.m_data[v73];
      v75 = v74->m_startUserEdgeIndex;
      v74->m_startEdgeIndex = *(_DWORD *)&v85[4 * v74->m_startEdgeIndex];
      if ( (int)v75 >= 0 )
        LODWORD(v75) = *(_DWORD *)&v85[4 * v75];
      v76 = v74->m_numUserEdges <= 0;
      v74->m_startUserEdgeIndex = v75;
      if ( v76 )
        LODWORD(v75) = v74->m_startEdgeIndex;
      if ( (_DWORD)v75 != -1 )
        break;
LABEL_129:
      ++v72;
      ++v73;
      if ( v72 >= mesh->m_faces.m_size )
        goto LABEL_130;
    }
    while ( 1 )
    {
      v77 = &mesh->m_edges.m_data[(int)v75];
      v78 = v77->m_oppositeEdge;
      if ( v78 != -1 )
      {
        v79 = *(_DWORD *)&v85[4 * (v78 & 0x3FFFFF)];
        v80 = *(_DWORD *)&array[4 * (v77->m_oppositeFace & 0x3FFFFF)];
        v77->m_oppositeEdge = v79;
        v77->m_oppositeFace = v80;
      }
      v81 = v74->m_startUserEdgeIndex;
      if ( (int)v75 >= v81 && (int)v75 < v74->m_numUserEdges + v81 - 1 )
        goto LABEL_127;
      if ( (_DWORD)v75 != v74->m_numUserEdges + v81 - 1 )
        break;
      LODWORD(v75) = v74->m_startEdgeIndex;
LABEL_128:
      if ( (_DWORD)v75 == -1 )
        goto LABEL_129;
    }
    if ( (int)v75 < v74->m_startEdgeIndex || (int)v75 >= v74->m_numEdges + v74->m_startEdgeIndex - 1 )
      goto LABEL_129;
LABEL_127:
    LODWORD(v75) = v75 + 1;
    goto LABEL_128;
  }
LABEL_130:
  v82 = faceIndices.m_capacityAndFlags;
  faceIndices.m_size = 0;
  result->m_enum = HK_SUCCESS;
  if ( v82 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, faceIndices.m_data, 4 * v82);
  faceIndices.m_data = 0i64;
  faceIndices.m_capacityAndFlags = 0x80000000;
  v86 = 0;
  if ( v87 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v85, 4 * v87);
  v85 = 0i64;
  v87 = 0x80000000;
  v90 = 0;
  if ( v91 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v91);
  return result;
}

// File Line: 952
// RVA: 0xBC3140
void __fastcall hkaiNavMeshUtils::compactClearanceCache(hkaiNavMeshInstance *meshInstance)
{
  _BYTE *v1; // r8
  hkArray<hkHalf,hkContainerHeapAllocator> *p_m_clearanceCache; // r14
  int m_size; // eax
  __int64 v5; // rdx
  _WORD *v6; // rcx
  signed __int64 v7; // rdi
  __int16 v8; // ax
  __int64 v9; // r12
  hkArray<int,hkContainerHeapAllocator> *p_m_faceClearanceIndices; // rbp
  int v11; // esi
  int v12; // eax
  int v13; // eax
  int v14; // r9d
  int v15; // edx
  int *v16; // rdi
  __int64 v17; // rcx
  int index; // r13d
  __int64 v19; // r15
  hkArray<int,hkContainerHeapAllocator> *p_m_faceMap; // rax
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_ownedFaces; // rcx
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_instancedFaces; // rdx
  int m_numEdges; // ecx
  __int64 v24; // r11
  int *m_data; // rax
  __int64 v26; // rbp
  int v27; // esi
  __int64 v28; // rdi
  int v29; // r9d
  int v30; // eax
  int v31; // eax
  hkHalf *v32; // rax
  __int64 v33; // rcx
  hkHalf *v34; // rdi
  signed __int64 v35; // rdx
  __int16 v36; // ax
  int v37; // esi
  hkArray<int,hkContainerHeapAllocator> *v38; // r11
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v39; // r9
  __int64 v40; // rdi
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v41; // r8
  hkaiNavMesh::Face *v42; // rax
  int v43; // ecx
  int v44; // eax
  int v45; // r9d
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // r9d
  int v50; // edx
  hkHalf *v51; // rdi
  __int64 v52; // rcx
  int v53; // eax
  _BYTE *v54; // [rsp+30h] [rbp-58h]
  int v55; // [rsp+90h] [rbp+8h] BYREF
  int v56; // [rsp+98h] [rbp+10h]
  hkResult result; // [rsp+A0h] [rbp+18h] BYREF

  v1 = 0i64;
  p_m_clearanceCache = &meshInstance->m_clearanceCache;
  m_size = meshInstance->m_clearanceCache.m_size;
  v54 = 0i64;
  v56 = 0x80000000;
  if ( m_size > 0 )
  {
    v55 = 2 * m_size;
    v1 = hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &v55);
    v54 = v1;
    v56 = v55 / 2;
  }
  v5 = p_m_clearanceCache->m_size;
  if ( v5 > 0 )
  {
    v6 = v1;
    v7 = (char *)p_m_clearanceCache->m_data - v1;
    do
    {
      v8 = *(_WORD *)((char *)v6++ + v7);
      *(v6 - 1) = v8;
      --v5;
    }
    while ( v5 );
  }
  v9 = meshInstance->m_faceClearanceIndices.m_size;
  p_m_faceClearanceIndices = &meshInstance->m_faceClearanceIndices;
  v11 = meshInstance->m_numOriginalFaces + meshInstance->m_ownedFaces.m_size;
  meshInstance->m_clearanceCache.m_size = 0;
  v12 = meshInstance->m_faceClearanceIndices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v12 < v11 )
  {
    v13 = 2 * v12;
    v14 = v11;
    if ( v11 < v13 )
      v14 = v13;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &meshInstance->m_faceClearanceIndices, v14, 4);
  }
  v15 = v11 - meshInstance->m_faceClearanceIndices.m_size;
  v16 = &meshInstance->m_faceClearanceIndices.m_data[meshInstance->m_faceClearanceIndices.m_size];
  v17 = v15;
  if ( v15 > 0 )
  {
    while ( v17 )
    {
      *v16++ = -1;
      --v17;
    }
  }
  index = 0;
  v19 = 0i64;
  meshInstance->m_faceClearanceIndices.m_size = v11;
  if ( (int)v9 > 0 )
  {
    p_m_faceMap = &meshInstance->m_faceMap;
    p_m_ownedFaces = &meshInstance->m_ownedFaces;
    p_m_instancedFaces = &meshInstance->m_instancedFaces;
    do
    {
      m_numEdges = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
                     meshInstance->m_originalFaces,
                     meshInstance->m_numOriginalFaces,
                     p_m_instancedFaces,
                     p_m_ownedFaces,
                     p_m_faceMap,
                     index)->m_numEdges;
      m_data = meshInstance->m_faceClearanceIndices.m_data;
      v26 = m_data[v19];
      v27 = 3 * (m_numEdges - 2);
      m_data[v19] = meshInstance->m_clearanceCache.m_size;
      v28 = p_m_clearanceCache->m_size;
      v29 = v27 + v28;
      v30 = p_m_clearanceCache->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v30 >= v27 + (int)v28 )
      {
        result.m_enum = HK_SUCCESS;
      }
      else
      {
        v31 = 2 * v30;
        if ( v29 < v31 )
          v29 = v31;
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_clearanceCache, v29, 2);
        v24 = v9;
      }
      v32 = p_m_clearanceCache->m_data;
      p_m_clearanceCache->m_size += v27;
      v33 = v27;
      v34 = &v32[v28];
      if ( (_DWORD)v26 == -1 )
      {
        if ( v27 > 0 )
        {
          while ( v33 )
          {
            v34->m_value = -16512;
            ++v34;
            --v33;
          }
        }
      }
      else if ( v27 > 0 )
      {
        v35 = &v54[2 * v26] - (_BYTE *)v34;
        do
        {
          v36 = *(__int16 *)((char *)&v34->m_value + v35);
          ++v34;
          v34[-1].m_value = v36;
          --v33;
        }
        while ( v33 );
      }
      ++v19;
      ++index;
      p_m_faceMap = &meshInstance->m_faceMap;
      p_m_ownedFaces = &meshInstance->m_ownedFaces;
      p_m_instancedFaces = &meshInstance->m_instancedFaces;
    }
    while ( v19 < v24 );
    p_m_faceClearanceIndices = &meshInstance->m_faceClearanceIndices;
  }
  v37 = meshInstance->m_clearanceCache.m_size;
  if ( (int)v9 < meshInstance->m_numOriginalFaces + meshInstance->m_ownedFaces.m_size )
  {
    v38 = &meshInstance->m_faceMap;
    v39 = &meshInstance->m_ownedFaces;
    v40 = (int)v9;
    v41 = &meshInstance->m_instancedFaces;
    do
    {
      v42 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
              meshInstance->m_originalFaces,
              meshInstance->m_numOriginalFaces,
              v41,
              v39,
              v38,
              v9);
      LODWORD(v9) = v9 + 1;
      v43 = v42->m_numEdges;
      p_m_faceClearanceIndices->m_data[v40++] = v37;
      v37 += 3 * (v43 - 2);
    }
    while ( (int)v9 < meshInstance->m_numOriginalFaces + meshInstance->m_ownedFaces.m_size );
  }
  v44 = p_m_clearanceCache->m_capacityAndFlags & 0x3FFFFFFF;
  v45 = (v37 + 7) & 0xFFFFFFF8;
  if ( v44 < v45 )
  {
    v46 = 2 * v44;
    if ( v45 < v46 )
      v45 = v46;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_clearanceCache, v45, 2);
  }
  v47 = p_m_clearanceCache->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v47 < v37 )
  {
    v48 = 2 * v47;
    v49 = v37;
    if ( v37 < v48 )
      v49 = v48;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_clearanceCache, v49, 2);
  }
  v50 = v37 - p_m_clearanceCache->m_size;
  v51 = &p_m_clearanceCache->m_data[p_m_clearanceCache->m_size];
  v52 = v50;
  if ( v50 > 0 )
  {
    while ( v52 )
    {
      v51->m_value = -16512;
      ++v51;
      --v52;
    }
  }
  v53 = v56;
  p_m_clearanceCache->m_size = v37;
  if ( v53 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v54, 2 * (v53 & 0x3FFFFFFF));
}

// File Line: 1010
// RVA: 0xBC30D0
void __fastcall hkaiNavMeshUtils::compactOwnedEdges(
        hkaiNavMeshInstance *meshInstance,
        hkaiStreamingCollection *collection)
{
  hkArray<int,hkContainerTempAllocator> facesToRemove; // [rsp+20h] [rbp-18h] BYREF

  facesToRemove.m_data = 0i64;
  facesToRemove.m_size = 0;
  facesToRemove.m_capacityAndFlags = 0x80000000;
  hkaiNavMeshUtils::removeOwnedFaces(meshInstance, collection, &facesToRemove, ALWAYS_COMPACT);
  facesToRemove.m_size = 0;
  if ( facesToRemove.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      facesToRemove.m_data,
      4 * facesToRemove.m_capacityAndFlags);
}

// File Line: 1017
// RVA: 0xBC1580
void __fastcall hkaiNavMeshUtils::removeOwnedFaces(
        hkaiNavMeshInstance *meshInstance,
        hkaiStreamingCollection *collection,
        hkArray<int,hkContainerTempAllocator> *facesToRemove,
        hkaiNavMeshUtils::RemoveOwnedFacesMode mode)
{
  hkArray<int,hkContainerTempAllocator> *v4; // r14
  _QWORD *Value; // rdi
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  int m_size; // r8d
  int v11; // eax
  unsigned int v12; // r12d
  __int64 v13; // rcx
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rdx
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_ownedFaces; // rdi
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *p_m_instancedFaces; // r8
  hkaiNavMesh::Face *v17; // rax
  int m_startEdgeIndex; // esi
  int m_startUserEdgeIndex; // r14d
  unsigned __int64 index; // rdi
  __int16 v21; // r15
  __int16 v22; // r12
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_ownedEdges; // r9
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_instancedEdges; // rax
  hkaiNavMesh::Edge *v25; // rax
  unsigned int m_oppositeEdge; // edx
  unsigned int m_runtimeId; // eax
  hkaiNavMeshInstance *m_instancePtr; // r8
  int m_numOriginalEdges; // eax
  int v30; // edx
  __int64 v31; // rcx
  hkaiNavMesh::Edge *m_data; // rax
  hkaiNavMesh::Edge *v33; // rdx
  bool v34; // cc
  int v35; // r13d
  int v36; // r15d
  int m_numOriginalFaces; // esi
  unsigned int *v38; // rax
  int v39; // edi
  hkLifoAllocator *v40; // rax
  unsigned int *m_cur; // rcx
  int v42; // edx
  char *v43; // r8
  int v44; // r9d
  int v45; // eax
  unsigned int *v46; // rdi
  __int64 i; // rcx
  int *v48; // r9
  int v49; // edi
  int v50; // edx
  __int64 v51; // r8
  int v52; // esi
  signed int v53; // r14d
  int v54; // r12d
  __int64 v55; // rcx
  __int64 v56; // r8
  __int64 v57; // rdx
  __int64 v58; // r10
  hkaiNavMesh::Edge *v59; // rax
  char v60; // al
  hkaiNavMesh::Face *v61; // r15
  __int16 m_numEdges; // ax
  __int16 m_numUserEdges; // ax
  signed int v64; // edx
  __int64 v65; // r9
  unsigned int v66; // r11d
  __m128i si128; // xmm3
  __m128i v68; // xmm1
  __m128i v69; // xmm2
  int v70; // eax
  __m128i v71; // xmm0
  __int64 v72; // r13
  unsigned int v73; // edx
  __int64 v74; // rcx
  __int64 v75; // rdi
  unsigned __int16 v76; // r12
  int v77; // edi
  bool v78; // zf
  int j; // edi
  int v80; // r15d
  int *v81; // r14
  int v82; // edi
  __int64 v83; // rsi
  __int64 v84; // r12
  int v85; // r8d
  __int64 v86; // rdi
  hkaiNavMesh::Face *v87; // rdx
  __int64 v88; // rax
  int v89; // edi
  __int64 v90; // rdx
  hkaiNavMesh::Face *v91; // r8
  __int64 v92; // rax
  int v93; // esi
  int v94; // eax
  _DWORD *v95; // rdi
  __int64 v96; // rcx
  __int64 v97; // r8
  int v98; // edi
  __int64 k; // rdx
  __int64 v100; // rcx
  int v101; // esi
  __int64 v102; // r13
  __int64 v103; // r11
  int v104; // r14d
  int v105; // edx
  __int64 v106; // rcx
  int v107; // r15d
  hkaiNavMesh::Edge *v108; // r8
  int v109; // edx
  char v110; // cl
  unsigned int v111; // eax
  int v112; // edi
  hkaiNavMeshInstance *v113; // rsi
  int v114; // eax
  __int64 v115; // rcx
  hkaiNavMesh::Edge *v116; // rax
  hkaiNavMesh::Edge *v117; // rdx
  _QWORD *v118; // rax
  _QWORD *v119; // rcx
  _QWORD *v120; // rdi
  unsigned __int64 v121; // rax
  _QWORD *v122; // rcx
  int v123; // edx
  int v124; // edi
  int v125; // ecx
  int v126; // r9d
  hkaiNavMesh::Edge *v127; // rdx
  int v128; // ecx
  int v129; // eax
  hkaiNavMesh::Edge *v130; // rdx
  bool v131; // [rsp+30h] [rbp-D0h]
  unsigned int v132; // [rsp+34h] [rbp-CCh]
  int v133; // [rsp+38h] [rbp-C8h]
  char v134; // [rsp+38h] [rbp-C8h]
  hkResult result[2]; // [rsp+40h] [rbp-C0h] BYREF
  int v136; // [rsp+48h] [rbp-B8h]
  _DWORD *v137; // [rsp+50h] [rbp-B0h] BYREF
  int v138; // [rsp+58h] [rbp-A8h]
  int v139; // [rsp+5Ch] [rbp-A4h]
  __int64 v140; // [rsp+60h] [rbp-A0h]
  _DWORD *v141; // [rsp+68h] [rbp-98h] BYREF
  int v142; // [rsp+70h] [rbp-90h]
  int v143; // [rsp+74h] [rbp-8Ch]
  int v144; // [rsp+78h] [rbp-88h]
  _DWORD *array; // [rsp+80h] [rbp-80h] BYREF
  int v146; // [rsp+88h] [rbp-78h]
  int v147; // [rsp+8Ch] [rbp-74h]
  hkArray<int,hkContainerTempAllocator> faceIndices; // [rsp+90h] [rbp-70h] BYREF
  hkArray<int,hkContainerTempAllocator> v149; // [rsp+A0h] [rbp-60h] BYREF
  unsigned __int64 v150; // [rsp+B0h] [rbp-50h]
  __int64 v151; // [rsp+B8h] [rbp-48h]
  __int64 v152; // [rsp+C0h] [rbp-40h]
  hkBitFieldStorage<hkLocalArray<unsigned int> > v153; // [rsp+C8h] [rbp-38h] BYREF
  int v156; // [rsp+140h] [rbp+40h]

  v4 = facesToRemove;
  if ( !facesToRemove->m_size && mode == EXIT_IF_NO_FACES_TO_REMOVE )
    return;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtremoveOwnedFaces";
    v8 = __rdtsc();
    v9 = v7 + 2;
    *((_DWORD *)v9 - 2) = v8;
    Value[1] = v9;
  }
  m_size = v4->m_size;
  v131 = m_size == 0;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<int,hkAlgorithm::less<int>>(v4->m_data, 0, m_size - 1, 0);
  if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, v4, 4);
  v4->m_data[v4->m_size] = -1;
  v11 = v4->m_size;
  v12 = 0;
  v4->m_size = v11;
  v133 = 0;
  if ( v11 > 0 )
  {
    v13 = 0i64;
    instanceMap = &meshInstance->m_faceMap;
    p_m_ownedFaces = &meshInstance->m_ownedFaces;
    *(_QWORD *)&result[0].m_enum = 0i64;
    p_m_instancedFaces = &meshInstance->m_instancedFaces;
    while ( 1 )
    {
      v17 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
              meshInstance->m_originalFaces,
              meshInstance->m_numOriginalFaces,
              p_m_instancedFaces,
              p_m_ownedFaces,
              instanceMap,
              *(int *)((char *)v4->m_data + v13));
      m_startEdgeIndex = v17->m_startEdgeIndex;
      m_startUserEdgeIndex = v17->m_startUserEdgeIndex;
      v151 = *(_QWORD *)&v17->m_numEdges;
      v150 = __PAIR64__(m_startUserEdgeIndex, m_startEdgeIndex);
      if ( SWORD1(v151) <= 0 )
        LODWORD(index) = m_startEdgeIndex;
      else
        index = HIDWORD(v150);
      if ( (_DWORD)index != -1 )
        break;
LABEL_41:
      v4 = facesToRemove;
      v13 = *(_QWORD *)&result[0].m_enum + 4i64;
      instanceMap = &meshInstance->m_faceMap;
      v34 = ++v133 < facesToRemove->m_size;
      p_m_ownedFaces = &meshInstance->m_ownedFaces;
      *(_QWORD *)&result[0].m_enum += 4i64;
      if ( !v34 )
      {
        v12 = 0;
        goto LABEL_43;
      }
    }
    v21 = WORD1(v151);
    v22 = v151;
    p_m_ownedEdges = &meshInstance->m_ownedEdges;
    p_m_instancedEdges = &meshInstance->m_instancedEdges;
    while ( 1 )
    {
      v25 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
              meshInstance->m_originalEdges,
              meshInstance->m_numOriginalEdges,
              p_m_instancedEdges,
              p_m_ownedEdges,
              &meshInstance->m_edgeMap,
              index);
      m_oppositeEdge = v25->m_oppositeEdge;
      if ( m_oppositeEdge != -1 )
        break;
LABEL_32:
      if ( (int)index >= m_startUserEdgeIndex && (int)index < v21 + m_startUserEdgeIndex - 1 )
        goto LABEL_38;
      if ( (_DWORD)index != v21 + m_startUserEdgeIndex - 1 )
      {
        if ( (int)index < m_startEdgeIndex || (int)index >= v22 + m_startEdgeIndex - 1 )
        {
LABEL_40:
          p_m_instancedFaces = &meshInstance->m_instancedFaces;
          goto LABEL_41;
        }
LABEL_38:
        LODWORD(index) = index + 1;
        goto LABEL_39;
      }
      LODWORD(index) = m_startEdgeIndex;
LABEL_39:
      p_m_instancedEdges = &meshInstance->m_instancedEdges;
      if ( (_DWORD)index == -1 )
        goto LABEL_40;
    }
    if ( (v25->m_flags.m_storage & 0x40) != 0 )
      m_runtimeId = m_oppositeEdge >> 22;
    else
      m_runtimeId = meshInstance->m_runtimeId;
    if ( collection )
      m_instancePtr = collection->m_instances.m_data[m_runtimeId].m_instancePtr;
    else
      m_instancePtr = meshInstance;
    m_numOriginalEdges = m_instancePtr->m_numOriginalEdges;
    v30 = m_oppositeEdge & 0x3FFFFF;
    if ( v30 < m_numOriginalEdges )
    {
      if ( m_instancePtr->m_edgeMap.m_size )
        v30 = m_instancePtr->m_edgeMap.m_data[v30];
      if ( v30 == -1 )
      {
        v33 = 0i64;
LABEL_31:
        v33->m_oppositeFace = -1;
        v33->m_oppositeEdge = -1;
        goto LABEL_32;
      }
      v31 = v30;
      m_data = m_instancePtr->m_instancedEdges.m_data;
    }
    else
    {
      v31 = v30 - m_numOriginalEdges;
      m_data = m_instancePtr->m_ownedEdges.m_data;
    }
    v33 = &m_data[v31];
    goto LABEL_31;
  }
LABEL_43:
  v35 = meshInstance->m_ownedFaces.m_size;
  v36 = meshInstance->m_ownedEdges.m_size;
  m_numOriginalFaces = meshInstance->m_numOriginalFaces;
  v144 = v35;
  LODWORD(v140) = v36;
  array = 0i64;
  v146 = 0;
  v147 = 0x80000000;
  if ( v35 > 0 )
    hkArrayUtil::_reserve(result, &hkContainerTempAllocator::s_alloc, &array, v35, 4);
  v146 = v35;
  v137 = 0i64;
  v138 = 0;
  v139 = 0x80000000;
  if ( v36 > 0 )
    hkArrayUtil::_reserve(result, &hkContainerTempAllocator::s_alloc, &v137, v36, 4);
  v138 = v36;
  faceIndices.m_data = 0i64;
  faceIndices.m_size = 0;
  faceIndices.m_capacityAndFlags = 0x80000000;
  hkaiNavMeshUtils::createOwnedFaceIndexArray(meshInstance, &faceIndices);
  v149.m_data = 0i64;
  v149.m_size = 0;
  v149.m_capacityAndFlags = 0x80000000;
  hkaiNavMeshUtils::createInstancedFaceIndexArray(meshInstance, &v149);
  v38 = 0i64;
  v39 = (v35 + 31) >> 5;
  v132 = 0;
  v153.m_words.m_data = 0i64;
  v153.m_words.m_size = 0;
  v153.m_words.m_capacityAndFlags = 0x80000000;
  v153.m_words.m_initialCapacity = v39;
  if ( !v39 )
    goto LABEL_52;
  v40 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (unsigned int *)v40->m_cur;
  v42 = (4 * v39 + 127) & 0xFFFFFF80;
  v43 = (char *)m_cur + v42;
  if ( v42 > v40->m_slabSize || v43 > v40->m_end )
  {
    v38 = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v40, v42);
LABEL_52:
    m_cur = v38;
    goto LABEL_53;
  }
  v40->m_cur = v43;
LABEL_53:
  v153.m_words.m_data = m_cur;
  v153.m_words.m_localMemory = m_cur;
  v153.m_numBits = v35;
  v153.m_words.m_capacityAndFlags = v39 | 0x80000000;
  if ( (v39 & 0x3FFFFFFF) < v39 )
  {
    v44 = (v35 + 31) >> 5;
    if ( v39 < 2 * (v39 & 0x3FFFFFFF) )
      v44 = 2 * (v39 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(result, &hkContainerHeapAllocator::s_alloc, &v153, v44, 4);
  }
  v45 = v39 - 1;
  v153.m_words.m_size = (v35 + 31) >> 5;
  if ( v39 - 1 >= 0 )
  {
    v46 = v153.m_words.m_data;
    for ( i = (unsigned int)(v45 + 1); i; --i )
      *v46++ = 0;
  }
  v48 = v4->m_data;
  if ( !v131 )
  {
    v49 = 0;
    v50 = 1;
    if ( v35 > 0 )
    {
      v51 = 0i64;
      do
      {
        if ( v49 + m_numOriginalFaces == *v48 )
        {
          v153.m_words.m_data[v51 >> 5] |= v50;
          ++v48;
        }
        v50 = __ROL4__(v50, 1);
        ++v49;
        ++v51;
      }
      while ( v49 < v35 );
    }
  }
  v52 = 0;
  v53 = 0;
  if ( v36 > 0 )
  {
    while ( 1 )
    {
      v54 = 1;
      v55 = faceIndices.m_data[v53];
      v56 = 4i64 * v53;
      v57 = *(int *)((char *)v149.m_data + v56);
      v152 = v56;
      v58 = 20i64 * v53;
      v59 = meshInstance->m_ownedEdges.m_data;
      v136 = 1;
      v60 = *(&v59->m_flags.m_storage + v58);
      v134 = 1;
      v61 = 0i64;
      v150 = v58;
      result[0].m_enum = v60 & 0x10;
      if ( (int)v55 >= 0 )
        break;
      if ( (int)v57 >= 0 )
      {
        v61 = &meshInstance->m_instancedFaces.m_data[v57];
        if ( (v60 & 0x10) != 0 )
          m_numUserEdges = v61->m_numUserEdges;
        else
          m_numUserEdges = v61->m_numEdges;
        v54 = m_numUserEdges;
        v134 = 0;
        goto LABEL_78;
      }
LABEL_79:
      v64 = 0;
      v65 = 0i64;
      v66 = v132;
      if ( v54 >= 4 )
      {
        si128 = _mm_load_si128((const __m128i *)&_xmm);
        v64 = 0;
        v65 = 0i64;
        v68 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v53), 0);
        v69 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v132), 0);
        do
        {
          v70 = v64 + v53;
          v71 = _mm_cvtsi32_si128(v64);
          v64 += 4;
          v65 += 4i64;
          *(__m128i *)&v137[v70] = _mm_sub_epi32(
                                     _mm_add_epi32(_mm_add_epi32(_mm_shuffle_epi32(v71, 0), si128), v68),
                                     v69);
        }
        while ( v64 < (int)(v54 - (v54 & 0x80000003)) );
      }
      v72 = v54;
      if ( v65 < v54 )
      {
        v73 = v53 + v64 - v132;
        v74 = v65 + v53;
        v75 = v54 - v65;
        do
        {
          v137[v74++] = v73++;
          --v75;
        }
        while ( v75 );
      }
      if ( v134 )
      {
        v132 += v54;
      }
      else if ( result[0].m_enum )
      {
        v76 = 0;
        v77 = 0;
        if ( v72 > 0 )
        {
          do
          {
            *(_DWORD *)((char *)v137 + v56) = v53 + v77 - v66;
            if ( *(unsigned int *)((char *)&meshInstance->m_ownedEdges.m_data->m_oppositeEdge + v58) == -1 )
            {
              ++v66;
              ++v76;
              v132 = v66;
            }
            else
            {
              hkaiNavMeshInstance::copyOwnedEdge(meshInstance, v52, v77 + v53);
              v56 = v152;
              v58 = v150;
              v66 = v132;
              ++v52;
            }
            v56 += 4i64;
            v58 += 20i64;
            ++v77;
            v152 = v56;
            v150 = v58;
            --v72;
          }
          while ( v72 );
        }
        v78 = v61->m_numUserEdges == v76;
        v61->m_numUserEdges -= v76;
        v54 = v136;
        if ( v78 )
          v61->m_startUserEdgeIndex = -1;
      }
      else
      {
        for ( j = 0; j < v54; ++v52 )
        {
          hkaiNavMeshInstance::copyOwnedEdge(meshInstance, v52, j + v53);
          ++j;
        }
      }
      v53 += v54;
      if ( v53 >= (int)v140 )
      {
        v12 = v132;
        v35 = v144;
        goto LABEL_99;
      }
    }
    v61 = &meshInstance->m_ownedFaces.m_data[v55];
    if ( (v60 & 0x10) != 0 )
      m_numEdges = v61->m_numUserEdges;
    else
      m_numEdges = v61->m_numEdges;
    v54 = m_numEdges;
    v134 = (v153.m_words.m_data[v55 >> 5] >> (v55 & 0x1F)) & 1;
LABEL_78:
    v136 = v54;
    goto LABEL_79;
  }
LABEL_99:
  v80 = 0;
  v81 = facesToRemove->m_data;
  if ( !v131 )
  {
    v82 = 0;
    v83 = 0i64;
    if ( v35 > 0 )
    {
      do
      {
        array[v83] = v82 - (v81 - facesToRemove->m_data);
        if ( v82 + meshInstance->m_numOriginalFaces == *v81 )
          ++v81;
        else
          hkaiNavMeshInstance::copyOwnedFace(meshInstance, v80++, v82);
        ++v83;
        ++v82;
      }
      while ( v83 < v35 );
      v12 = v132;
    }
  }
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>(&v153);
  hkaiNavMeshInstance::setNumOwnedFaces(meshInstance, v144 - facesToRemove->m_size);
  hkaiNavMeshInstance::setNumOwnedEdges(meshInstance, v140 - v12);
  v84 = meshInstance->m_numOriginalEdges;
  v156 = meshInstance->m_numOriginalFaces;
  v85 = 0;
  if ( meshInstance->m_ownedFaces.m_size > 0 )
  {
    v86 = 0i64;
    do
    {
      v87 = &meshInstance->m_ownedFaces.m_data[v86];
      v87->m_startEdgeIndex = v84 + v137[v87->m_startEdgeIndex - v84];
      v88 = v87->m_startUserEdgeIndex;
      if ( (int)v88 >= 0 )
        LODWORD(v88) = v84 + v137[v88 - v84];
      ++v85;
      v87->m_startUserEdgeIndex = v88;
      ++v86;
    }
    while ( v85 < meshInstance->m_ownedFaces.m_size );
  }
  v89 = 0;
  if ( meshInstance->m_instancedFaces.m_size > 0 )
  {
    v90 = 0i64;
    do
    {
      v91 = meshInstance->m_instancedFaces.m_data;
      v92 = v91[v90].m_startUserEdgeIndex;
      if ( (int)v92 >= (int)v84 )
        LODWORD(v92) = v84 + v137[v92 - v84];
      v91[v90].m_startUserEdgeIndex = v92;
      ++v89;
      ++v90;
    }
    while ( v89 < meshInstance->m_instancedFaces.m_size );
  }
  hkaiNavMeshUtils::createOwnedFaceIndexArray(meshInstance, &faceIndices);
  hkaiNavMeshUtils::createInstancedFaceIndexArray(meshInstance, &v149);
  v93 = meshInstance->m_instancedFaces.m_size;
  v94 = 0;
  v141 = 0i64;
  v142 = 0;
  v143 = 0x80000000;
  if ( v93 > 0 )
  {
    hkArrayUtil::_reserve(result, &hkContainerTempAllocator::s_alloc, &v141, v93, 4);
    v94 = v142;
  }
  v95 = &v141[v94];
  v96 = v93 - v94;
  if ( v96 > 0 )
  {
    while ( v96 )
    {
      *v95++ = -1;
      --v96;
    }
  }
  v97 = meshInstance->m_faceMap.m_size;
  v142 = v93;
  v98 = 0;
  for ( k = 0i64; k < v97; ++v98 )
  {
    v100 = meshInstance->m_faceMap.m_data[k];
    if ( (_DWORD)v100 != -1 )
      v141[v100] = v98;
    ++k;
  }
  v101 = v156;
  v102 = 0i64;
  if ( meshInstance->m_ownedEdges.m_size > 0 )
  {
    v103 = 0i64;
    v140 = 0i64;
    v104 = v84;
    result[0].m_enum = -(int)v84;
    while ( 1 )
    {
      v105 = faceIndices.m_data[v102];
      v106 = v149.m_data[v102];
      if ( v105 >= 0 )
        break;
      if ( (int)v106 >= 0 )
      {
        v107 = v141[v106];
        goto LABEL_131;
      }
LABEL_149:
      ++v104;
      v103 += 20i64;
      ++v102;
      v140 = v103;
      if ( v104 + result[0].m_enum >= meshInstance->m_ownedEdges.m_size )
        goto LABEL_150;
    }
    v107 = v105 + v101;
LABEL_131:
    if ( v107 < 0 )
      goto LABEL_149;
    v108 = meshInstance->m_ownedEdges.m_data;
    v109 = *(unsigned int *)((char *)&v108->m_oppositeEdge + v103);
    if ( v109 == -1 )
      goto LABEL_149;
    v110 = *(&v108->m_flags.m_storage + v103) & 0x40;
    if ( v110 )
      v111 = v109 & 0xFFC00000;
    else
      v111 = meshInstance->m_runtimeId << 22;
    if ( !collection || !v110 )
    {
      v123 = v109 & 0x3FFFFF;
      if ( v123 < (int)v84 )
      {
        v129 = meshInstance->m_numOriginalEdges;
        if ( v123 < v129 )
        {
          if ( meshInstance->m_edgeMap.m_size )
            v123 = meshInstance->m_edgeMap.m_data[v123];
          if ( v123 == -1 )
            v130 = 0i64;
          else
            v130 = &meshInstance->m_instancedEdges.m_data[v123];
        }
        else
        {
          v130 = &v108[v123 - v129];
        }
        v130->m_oppositeFace = v107 | (meshInstance->m_runtimeId << 22);
        v130->m_oppositeEdge = v104 | (meshInstance->m_runtimeId << 22);
      }
      else
      {
        v124 = *(unsigned int *)((_BYTE *)&v108->m_oppositeFace + v103) & 0x3FFFFF;
        if ( v124 >= v101 && !v131 )
          v124 = v101 + array[v124 - (__int64)v101];
        v125 = meshInstance->m_numOriginalEdges;
        v126 = v84 + v137[v123 - v84];
        if ( v104 < v125 )
        {
          if ( meshInstance->m_edgeMap.m_size )
            v128 = meshInstance->m_edgeMap.m_data[v84 + v102];
          else
            v128 = v104;
          if ( v128 == -1 )
            v127 = 0i64;
          else
            v127 = &meshInstance->m_instancedEdges.m_data[v128];
        }
        else
        {
          v127 = &v108[v104 - v125];
        }
        v127->m_oppositeFace = v124 | (meshInstance->m_runtimeId << 22);
        v127->m_oppositeEdge = v126 | (meshInstance->m_runtimeId << 22);
      }
      goto LABEL_149;
    }
    v112 = v111 & 0x3FFFFF | v109 & 0x3FFFFF;
    v113 = collection->m_instances.m_data[(v111 | v109 & 0x3FFFFF) >> 22].m_instancePtr;
    if ( hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
           v113->m_originalEdges,
           v113->m_numOriginalEdges,
           &v113->m_instancedEdges,
           &v113->m_ownedEdges,
           &v113->m_edgeMap,
           v112)->m_oppositeEdge == -1 )
    {
LABEL_148:
      v101 = v156;
      v103 = v140;
      goto LABEL_149;
    }
    v114 = v113->m_numOriginalEdges;
    if ( v112 < v114 )
    {
      if ( v113->m_edgeMap.m_size )
        v112 = v113->m_edgeMap.m_data[v112];
      if ( v112 == -1 )
      {
        v117 = 0i64;
LABEL_147:
        v117->m_oppositeFace = v107 | (meshInstance->m_runtimeId << 22);
        v117->m_oppositeEdge = v104 | (meshInstance->m_runtimeId << 22);
        goto LABEL_148;
      }
      v115 = v112;
      v116 = v113->m_instancedEdges.m_data;
    }
    else
    {
      v115 = v112 - v114;
      v116 = v113->m_ownedEdges.m_data;
    }
    v117 = &v116[v115];
    goto LABEL_147;
  }
LABEL_150:
  v142 = 0;
  if ( v143 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v141, 4 * v143);
  v141 = 0i64;
  v143 = 0x80000000;
  v149.m_size = 0;
  if ( v149.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v149.m_data,
      4 * v149.m_capacityAndFlags);
  v149.m_data = 0i64;
  v149.m_capacityAndFlags = 0x80000000;
  faceIndices.m_size = 0;
  if ( faceIndices.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      faceIndices.m_data,
      4 * faceIndices.m_capacityAndFlags);
  faceIndices.m_data = 0i64;
  faceIndices.m_capacityAndFlags = 0x80000000;
  v138 = 0;
  if ( v139 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v137, 4 * v139);
  v137 = 0i64;
  v139 = 0x80000000;
  v146 = 0;
  if ( v147 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v147);
  array = 0i64;
  v147 = 0x80000000;
  v118 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v119 = (_QWORD *)v118[1];
  v120 = v118;
  if ( (unsigned __int64)v119 < v118[3] )
  {
    *v119 = "Et";
    v121 = __rdtsc();
    v122 = v119 + 2;
    *((_DWORD *)v122 - 2) = v121;
    v120[1] = v122;
  }
}

// File Line: 1351
// RVA: 0xBC0B40
void __fastcall hkaiNavMeshUtils::removeFace(hkaiNavMesh *mesh, int faceToRemoveIndex, bool invalidateOppEdges)
{
  hkArray<int,hkContainerTempAllocator> array; // [rsp+20h] [rbp-18h] BYREF
  hkResult result; // [rsp+58h] [rbp+20h] BYREF

  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 4);
  array.m_data[array.m_size++] = faceToRemoveIndex;
  hkaiNavMeshUtils::removeFaces(&result, mesh, &array, invalidateOppEdges);
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      4 * array.m_capacityAndFlags);
}

// File Line: 1565
// RVA: 0xBC0720
// attributes: thunk
void __fastcall hkaiNavMeshUtils::validate(hkaiNavMesh *mesh, bool checkVerticesInsideAabb)
{
  hkaiNavMesh::checkDeterminism(mesh);
}

// File Line: 1614
// RVA: 0xBC0730
void __fastcall hkaiNavMeshUtils::validate(
        hkaiNavMeshInstance *meshInstance,
        bool checkVerticesInsideAabb,
        bool checkClearanceCache)
{
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TthkaiNavMeshUtils::validateInstance";
    v6 = __rdtsc();
    v7 = v5 + 2;
    *((_DWORD *)v7 - 2) = v6;
    Value[1] = v7;
  }
  hkaiNavMeshInstance::checkDeterminism(meshInstance);
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "Et";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    v8[1] = v11;
  }
}

// File Line: 1765
// RVA: 0xBC2340
hkResult *__fastcall hkaiNavMeshUtils::compactVertices(
        hkResult *result,
        hkaiNavMesh *mesh,
        int edgeStartIdx,
        hkResultEnum vertexStartIdx)
{
  int v5; // r15d
  int v6; // edx
  __int64 v7; // r14
  hkResult *v8; // r13
  int v9; // ebx
  int v10; // r8d
  int v11; // r9d
  char *v12; // rdi
  __int64 v13; // rcx
  _DWORD *v14; // r12
  int v15; // r9d
  __int64 v16; // r8
  hkaiNavMesh::Edge *m_data; // rdi
  __int64 v18; // rdi
  int v19; // r8d
  hkVector4f *v20; // r11
  __int64 v21; // r8
  hkVector4f *v22; // r11
  int v23; // r10d
  __int64 v24; // r9
  __int64 v25; // r13
  hkVector4f *v26; // rcx
  int v27; // edi
  int v28; // eax
  int v29; // eax
  int v30; // r9d
  __int64 v31; // r8
  hkaiNavMesh::Edge *v32; // rdi
  int v33; // r8d
  hkResult v35; // [rsp+30h] [rbp-40h] BYREF
  hkResult v36[2]; // [rsp+38h] [rbp-38h] BYREF
  __int64 m_enum; // [rsp+40h] [rbp-30h]
  char *array; // [rsp+48h] [rbp-28h] BYREF
  int v39; // [rsp+50h] [rbp-20h]
  int v40; // [rsp+54h] [rbp-1Ch]
  _DWORD *v41; // [rsp+58h] [rbp-18h] BYREF
  int v42; // [rsp+60h] [rbp-10h]
  int v43; // [rsp+64h] [rbp-Ch]
  hkResult resulta; // [rsp+B8h] [rbp+48h] BYREF
  hkResult v46; // [rsp+C8h] [rbp+58h] BYREF

  v46.m_enum = vertexStartIdx;
  v5 = mesh->m_vertices.m_size - vertexStartIdx;
  v6 = 0;
  v7 = edgeStartIdx;
  v8 = result;
  array = 0i64;
  v9 = (v5 + 31) >> 5;
  v39 = 0;
  v40 = 0x80000000;
  if ( v9 <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, (v5 + 31) >> 5, 4);
    if ( resulta.m_enum )
    {
      v10 = v40;
      v8->m_enum = HK_FAILURE;
      v39 = 0;
      if ( v10 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v10);
      return v8;
    }
    v6 = v39;
  }
  if ( (v40 & 0x3FFFFFFF) < v9 )
  {
    v11 = (v5 + 31) >> 5;
    if ( v9 < 2 * (v40 & 0x3FFFFFFF) )
      v11 = 2 * (v40 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(v36, &hkContainerTempAllocator::s_alloc, &array, v11, 4);
    v6 = v39;
  }
  v12 = &array[4 * v6];
  v13 = v9 - v6;
  if ( v9 - v6 > 0 )
  {
    while ( v13 )
    {
      *(_DWORD *)v12 = 0;
      v12 += 4;
      --v13;
    }
  }
  v14 = array;
  v39 = (v5 + 31) >> 5;
  v15 = v7;
  *(_QWORD *)&v36[0].m_enum = array;
  if ( (int)v7 < mesh->m_edges.m_size )
  {
    v16 = v7;
    do
    {
      m_data = mesh->m_edges.m_data;
      ++v15;
      ++v16;
      v14[(__int64)m_data[v16 - 1].m_a >> 5] |= 1 << (m_data[v16 - 1].m_a & 0x1F);
      v14[(__int64)m_data[v16 - 1].m_b >> 5] |= 1 << (m_data[v16 - 1].m_b & 0x1F);
    }
    while ( v15 < mesh->m_edges.m_size );
  }
  v18 = 0i64;
  v43 = 0x80000000;
  v41 = 0i64;
  v42 = 0;
  if ( v5 <= 0 )
  {
    v35.m_enum = HK_SUCCESS;
    goto LABEL_23;
  }
  hkArrayUtil::_reserve(&v35, &hkContainerTempAllocator::s_alloc, &v41, v5, 4);
  if ( v35.m_enum == HK_SUCCESS )
  {
LABEL_23:
    v20 = mesh->m_vertices.m_data;
    v42 = v5;
    m_enum = v46.m_enum;
    v21 = v46.m_enum;
    v22 = &v20[v21];
    v23 = 0;
    v24 = 0i64;
    if ( v5 > 0 )
    {
      v25 = *(_QWORD *)&v36[0].m_enum;
      do
      {
        v41[v18] = v23;
        if ( ((*(_DWORD *)(v25 + 4 * ((__int64)(int)v24 >> 5)) >> (v24 & 0x1F)) & 1) != 0 )
        {
          v26 = v22++;
          *v26 = mesh->m_vertices.m_data[v21];
        }
        else
        {
          ++v23;
        }
        ++v18;
        v24 = (unsigned int)(v24 + 1);
        ++v21;
      }
      while ( v18 < v5 );
      v8 = result;
    }
    v27 = mesh->m_vertices.m_size - v23;
    v28 = mesh->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v28 < v27 )
    {
      v29 = 2 * v28;
      v30 = mesh->m_vertices.m_size - v23;
      if ( v27 < v29 )
        v30 = v29;
      hkArrayUtil::_reserve(&v46, &hkContainerHeapAllocator::s_alloc, &mesh->m_vertices, v30, 16);
    }
    mesh->m_vertices.m_size = v27;
    if ( (int)v7 < mesh->m_edges.m_size )
    {
      v24 = m_enum;
      v31 = v7;
      do
      {
        LODWORD(v7) = v7 + 1;
        v32 = &mesh->m_edges.m_data[v31++];
        v32->m_a -= v41[v32->m_a - v24];
        v32->m_b -= v41[v32->m_b - v24];
      }
      while ( (int)v7 < mesh->m_edges.m_size );
    }
    v33 = v43;
    v8->m_enum = HK_SUCCESS;
    v42 = 0;
    if ( v33 >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, _DWORD *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        v41,
        (unsigned int)(4 * v33),
        v24);
    v41 = 0i64;
    v43 = 0x80000000;
    goto LABEL_40;
  }
  v19 = v43;
  v8->m_enum = HK_FAILURE;
  v42 = 0;
  if ( v19 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v41, 4 * v19);
  v41 = 0i64;
  v43 = 0x80000000;
LABEL_40:
  v39 = 0;
  if ( v40 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v40);
  return v8;
}

// File Line: 1829
// RVA: 0xBC2700
void __fastcall hkaiNavMeshUtils::compactOwnedVertices(hkaiNavMeshInstance *meshInstance)
{
  __int64 m_size; // r13
  hkResultEnum m_numOriginalVertices; // esi
  int v3; // r14d
  int v5; // edi
  hkLifoAllocator *Value; // rax
  unsigned int *m_cur; // rdx
  int v8; // ecx
  char *v9; // r8
  int v10; // r9d
  __int64 v11; // rcx
  unsigned int *v12; // rdi
  int v13; // r8d
  __int64 v14; // r9
  hkaiNavMesh::Edge *m_data; // rax
  int m_a; // ecx
  int m_b; // edi
  int v18; // edi
  int v19; // ecx
  int v20; // r8d
  __int64 v21; // r9
  hkaiNavMesh::Edge *v22; // rax
  int v23; // edi
  int v24; // ecx
  hkVector4f *v25; // r10
  hkHalf *v26; // rax
  int v27; // r14d
  int v28; // r8d
  __int64 v29; // rdi
  hkHalf *v30; // r11
  __int64 v31; // r9
  hkVector4f *v32; // rcx
  __int16 *p_m_value; // rcx
  int v34; // r13d
  int v35; // eax
  int v36; // eax
  int v37; // r9d
  int v38; // edi
  int v39; // eax
  int v40; // eax
  int v41; // r9d
  __int64 v42; // r9
  int v43; // r14d
  __int64 v44; // r11
  hkaiNavMesh::Edge *v45; // r8
  __int64 v46; // rdi
  __int64 v47; // rdx
  int v48; // r8d
  int *v49; // rdi
  __int64 v50; // rdx
  __int64 v51; // rdx
  __int64 v52; // [rsp+30h] [rbp-40h] BYREF
  int v53; // [rsp+38h] [rbp-38h]
  int v54; // [rsp+3Ch] [rbp-34h]
  hkBitFieldStorage<hkLocalArray<unsigned int> > array; // [rsp+40h] [rbp-30h] BYREF
  hkResult v56; // [rsp+B0h] [rbp+40h] BYREF
  int v57; // [rsp+B8h] [rbp+48h]
  hkResult result; // [rsp+C0h] [rbp+50h] BYREF

  m_size = meshInstance->m_ownedVertices.m_size;
  m_numOriginalVertices = meshInstance->m_numOriginalVertices;
  v3 = m_numOriginalVertices + m_size;
  v5 = ((int)m_size + 31) >> 5;
  v56.m_enum = m_numOriginalVertices;
  array.m_words.m_data = 0i64;
  v57 = m_numOriginalVertices + m_size;
  array.m_words.m_size = 0;
  array.m_words.m_capacityAndFlags = 0x80000000;
  array.m_words.m_initialCapacity = v5;
  if ( v5 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (unsigned int *)Value->m_cur;
    v8 = (4 * v5 + 127) & 0xFFFFFF80;
    v9 = (char *)m_cur + v8;
    if ( v8 > Value->m_slabSize || v9 > Value->m_end )
      m_cur = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(Value, v8);
    else
      Value->m_cur = v9;
  }
  else
  {
    m_cur = 0i64;
  }
  array.m_words.m_data = m_cur;
  array.m_words.m_localMemory = m_cur;
  array.m_numBits = m_size;
  array.m_words.m_capacityAndFlags = v5 | 0x80000000;
  if ( (v5 & 0x3FFFFFFF) < v5 )
  {
    v10 = ((int)m_size + 31) >> 5;
    if ( v5 < 2 * (v5 & 0x3FFFFFFF) )
      v10 = 2 * (v5 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array, v10, 4);
    m_cur = array.m_words.m_data;
  }
  array.m_words.m_size = ((int)m_size + 31) >> 5;
  if ( v5 - 1 >= 0 )
  {
    v11 = (unsigned int)v5;
    v12 = m_cur;
    while ( v11 )
    {
      *v12++ = 0;
      --v11;
    }
    m_cur = array.m_words.m_data;
  }
  v13 = 0;
  if ( meshInstance->m_ownedEdges.m_size > 0 )
  {
    v14 = 0i64;
    do
    {
      m_data = meshInstance->m_ownedEdges.m_data;
      m_a = m_data[v14].m_a;
      if ( m_a < v3 )
      {
        m_b = m_data[v14].m_b;
        if ( m_b < v3 )
        {
          v18 = m_b - m_numOriginalVertices;
          v19 = m_a - m_numOriginalVertices;
          if ( v19 >= 0 )
          {
            m_cur[(__int64)v19 >> 5] |= 1 << (v19 & 0x1F);
            m_cur = array.m_words.m_data;
          }
          if ( v18 >= 0 )
          {
            m_cur[(__int64)v18 >> 5] |= 1 << (v18 & 0x1F);
            m_cur = array.m_words.m_data;
          }
        }
      }
      ++v13;
      ++v14;
    }
    while ( v13 < meshInstance->m_ownedEdges.m_size );
  }
  v20 = 0;
  if ( meshInstance->m_instancedEdges.m_size > 0 )
  {
    v21 = 0i64;
    do
    {
      v22 = meshInstance->m_instancedEdges.m_data;
      v23 = v22[v21].m_b - m_numOriginalVertices;
      v24 = v22[v21].m_a - m_numOriginalVertices;
      if ( v24 >= 0 )
      {
        m_cur[(__int64)v24 >> 5] |= 1 << (v24 & 0x1F);
        m_cur = array.m_words.m_data;
      }
      if ( v23 >= 0 )
      {
        m_cur[(__int64)v23 >> 5] |= 1 << (v23 & 0x1F);
        m_cur = array.m_words.m_data;
      }
      ++v20;
      ++v21;
    }
    while ( v20 < meshInstance->m_instancedEdges.m_size );
  }
  v52 = 0i64;
  v53 = 0;
  v54 = 0x80000000;
  if ( (int)m_size > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &v52, m_size, 4);
  v25 = meshInstance->m_ownedVertices.m_data;
  v26 = &meshInstance->m_globalClearanceCache.m_data[meshInstance->m_numOriginalVertices];
  v53 = m_size;
  v27 = 0;
  v28 = 0;
  v29 = 0i64;
  v30 = v26;
  if ( (int)m_size > 0 )
  {
    v31 = 0i64;
    do
    {
      *(_DWORD *)(v52 + 4 * v29) = v27;
      if ( ((array.m_words.m_data[(__int64)v28 >> 5] >> (v28 & 0x1F)) & 1) != 0 )
      {
        v32 = v25++;
        *v32 = meshInstance->m_ownedVertices.m_data[v31];
        p_m_value = &v30->m_value;
        ++v30;
        *p_m_value = v26[v29].m_value;
      }
      else
      {
        ++v27;
      }
      ++v29;
      ++v28;
      ++v31;
    }
    while ( v29 < m_size );
    m_numOriginalVertices = v56.m_enum;
  }
  v34 = m_size - v27;
  v35 = meshInstance->m_ownedVertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v35 < v34 )
  {
    v36 = 2 * v35;
    v37 = v34;
    if ( v34 < v36 )
      v37 = v36;
    hkArrayUtil::_reserve(&v56, &hkContainerHeapAllocator::s_alloc, &meshInstance->m_ownedVertices, v37, 16);
  }
  meshInstance->m_ownedVertices.m_size = v34;
  v38 = meshInstance->m_globalClearanceCache.m_size - v27;
  v39 = meshInstance->m_globalClearanceCache.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v39 < v38 )
  {
    v40 = 2 * v39;
    v41 = meshInstance->m_globalClearanceCache.m_size - v27;
    if ( v38 < v40 )
      v41 = v40;
    hkArrayUtil::_reserve(&v56, &hkContainerHeapAllocator::s_alloc, &meshInstance->m_globalClearanceCache, v41, 2);
  }
  meshInstance->m_globalClearanceCache.m_size = v38;
  v42 = 0i64;
  if ( meshInstance->m_ownedEdges.m_size > 0 )
  {
    v43 = v57;
    v44 = 0i64;
    do
    {
      v45 = &meshInstance->m_ownedEdges.m_data[v44];
      v46 = v45->m_a;
      if ( (int)v46 < v43 )
      {
        v47 = v45->m_b;
        if ( (int)v47 < v43 )
        {
          if ( (int)v46 >= m_numOriginalVertices )
            v45->m_a = v46 - *(_DWORD *)(v52 + 4 * (v46 - (int)m_numOriginalVertices));
          if ( (int)v47 >= m_numOriginalVertices )
            v45->m_b = v47 - *(_DWORD *)(v52 + 4 * (v47 - (int)m_numOriginalVertices));
        }
      }
      v42 = (unsigned int)(v42 + 1);
      ++v44;
    }
    while ( (int)v42 < meshInstance->m_ownedEdges.m_size );
  }
  v48 = 0;
  if ( meshInstance->m_instancedEdges.m_size > 0 )
  {
    v42 = 0i64;
    do
    {
      v49 = (int *)((char *)&meshInstance->m_instancedEdges.m_data->m_a + v42);
      v50 = *v49;
      if ( (int)v50 >= m_numOriginalVertices )
        *v49 = v50 - *(_DWORD *)(v52 + 4 * (v50 - (int)m_numOriginalVertices));
      v51 = v49[1];
      if ( (int)v51 >= m_numOriginalVertices )
        v49[1] = v51 - *(_DWORD *)(v52 + 4 * (v51 - (int)m_numOriginalVertices));
      ++v48;
      v42 += 20i64;
    }
    while ( v48 < meshInstance->m_instancedEdges.m_size );
  }
  v53 = 0;
  if ( v54 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v52,
      (unsigned int)(4 * v54),
      v42);
  v52 = 0i64;
  v54 = 0x80000000;
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>(&array);
}

// File Line: 1912
// RVA: 0xBC2B90
hkResult *__fastcall hkaiNavMeshUtils::compactEdges(
        hkResult *result,
        hkaiNavMesh *mesh,
        unsigned int edgeStartIdx,
        bool checkUserData)
{
  int m_size; // esi
  __int64 v5; // r14
  int v8; // edi
  hkLifoAllocator *Value; // rax
  unsigned int *m_cur; // rcx
  int v11; // edx
  char *v12; // r8
  int v13; // r9d
  int v14; // eax
  unsigned int *m_data; // rdi
  __int64 i; // rcx
  int v17; // edx
  __int64 v18; // rdi
  __int64 v19; // r8
  __int64 v20; // rcx
  int v21; // r9d
  __int64 v22; // r10
  hkaiNavMesh::Face *v23; // r8
  int m_startEdgeIndex; // eax
  int m_startUserEdgeIndex; // edi
  int v26; // edi
  hkaiNavMesh::Edge *v27; // r11
  int v28; // r9d
  int v29; // edi
  __int64 v30; // r10
  __int64 v31; // r8
  hkaiNavMesh::Edge *v32; // rdx
  hkaiNavMesh::Edge *v33; // rcx
  int v34; // edi
  __int64 v35; // r8
  hkaiNavMesh::Face *v36; // rdx
  __int64 v37; // rax
  int v38; // edx
  __int64 v39; // rdi
  hkaiNavMesh::Edge *v40; // r8
  unsigned int m_oppositeEdge; // ecx
  _DWORD *v43; // [rsp+30h] [rbp-40h] BYREF
  int v44; // [rsp+38h] [rbp-38h]
  int v45; // [rsp+3Ch] [rbp-34h]
  hkBitFieldStorage<hkLocalArray<unsigned int> > array; // [rsp+40h] [rbp-30h] BYREF
  hkResult resulta; // [rsp+A8h] [rbp+38h] BYREF

  m_size = mesh->m_edges.m_size;
  v5 = edgeStartIdx;
  v8 = (m_size + 31) >> 5;
  array.m_words.m_data = 0i64;
  array.m_words.m_size = 0;
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
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &array, v13, 4);
  }
  array.m_words.m_size = (m_size + 31) >> 5;
  if ( !array.m_words.m_data )
  {
    result->m_enum = HK_FAILURE;
    goto LABEL_58;
  }
  v14 = v8 - 1;
  if ( v8 - 1 >= 0 )
  {
    m_data = array.m_words.m_data;
    for ( i = (unsigned int)(v14 + 1); i; --i )
      *m_data++ = 0;
  }
  v17 = 1;
  if ( (int)v5 > 0 )
  {
    v18 = 0i64;
    v19 = v5;
    do
    {
      v20 = v18++;
      array.m_words.m_data[v20 >> 5] |= v17;
      v17 = __ROL4__(v17, 1);
      --v19;
    }
    while ( v19 );
  }
  v21 = 0;
  if ( mesh->m_faces.m_size > 0 )
  {
    v22 = 0i64;
    while ( 1 )
    {
      v23 = &mesh->m_faces.m_data[v22];
      m_startEdgeIndex = v23->m_numUserEdges <= 0 ? v23->m_startEdgeIndex : v23->m_startUserEdgeIndex;
      if ( m_startEdgeIndex != -1 )
        break;
LABEL_34:
      ++v21;
      ++v22;
      if ( v21 >= mesh->m_faces.m_size )
        goto LABEL_35;
    }
    while ( 1 )
    {
      array.m_words.m_data[(__int64)m_startEdgeIndex >> 5] |= 1 << (m_startEdgeIndex & 0x1F);
      m_startUserEdgeIndex = v23->m_startUserEdgeIndex;
      if ( m_startEdgeIndex >= m_startUserEdgeIndex && m_startEdgeIndex < v23->m_numUserEdges + m_startUserEdgeIndex - 1 )
        goto LABEL_32;
      if ( m_startEdgeIndex != v23->m_numUserEdges + m_startUserEdgeIndex - 1 )
        break;
      m_startEdgeIndex = v23->m_startEdgeIndex;
LABEL_33:
      if ( m_startEdgeIndex == -1 )
        goto LABEL_34;
    }
    if ( m_startEdgeIndex < v23->m_startEdgeIndex || m_startEdgeIndex >= v23->m_numEdges + v23->m_startEdgeIndex - 1 )
      goto LABEL_34;
LABEL_32:
    ++m_startEdgeIndex;
    goto LABEL_33;
  }
LABEL_35:
  v26 = mesh->m_edges.m_size;
  v43 = 0i64;
  v44 = 0;
  v45 = 0x80000000;
  if ( v26 > 0 && (hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &v43, v26, 4), resulta.m_enum) )
  {
    result->m_enum = HK_FAILURE;
  }
  else
  {
    v27 = mesh->m_edges.m_data;
    v44 = v26;
    v28 = 0;
    v29 = 0;
    if ( mesh->m_edges.m_size > 0 )
    {
      v30 = 0i64;
      v31 = 0i64;
      do
      {
        v43[v31] = v29 - v28;
        if ( ((array.m_words.m_data[(__int64)v29 >> 5] >> (v29 & 0x1F)) & 1) != 0 )
        {
          v32 = v27++;
          v33 = &mesh->m_edges.m_data[v30];
          v32->m_a = v33->m_a;
          v32->m_b = v33->m_b;
          v32->m_oppositeEdge = v33->m_oppositeEdge;
          v32->m_oppositeFace = v33->m_oppositeFace;
          v32->m_flags.m_storage = v33->m_flags.m_storage;
          v32->m_paddingByte = v33->m_paddingByte;
          v32->m_userEdgeCost.m_value = v33->m_userEdgeCost.m_value;
        }
        else
        {
          ++v28;
        }
        ++v29;
        ++v31;
        ++v30;
      }
      while ( v29 < mesh->m_edges.m_size );
    }
    hkaiNavMesh::setEdgesSize(mesh, &resulta, mesh->m_edges.m_size - v28);
    v34 = 0;
    if ( mesh->m_faces.m_size > 0 )
    {
      v35 = 0i64;
      do
      {
        v36 = &mesh->m_faces.m_data[v35];
        v37 = v36->m_startUserEdgeIndex;
        v36->m_startEdgeIndex = v43[v36->m_startEdgeIndex];
        if ( (int)v37 >= 0 )
          LODWORD(v37) = v43[v37];
        ++v34;
        v36->m_startUserEdgeIndex = v37;
        ++v35;
      }
      while ( v34 < mesh->m_faces.m_size );
    }
    v38 = 0;
    if ( mesh->m_edges.m_size > 0 )
    {
      v39 = 0i64;
      do
      {
        v40 = mesh->m_edges.m_data;
        m_oppositeEdge = v40[v39].m_oppositeEdge;
        if ( m_oppositeEdge != -1 )
          v40[v39].m_oppositeEdge = v43[m_oppositeEdge & 0x3FFFFF];
        ++v38;
        ++v39;
      }
      while ( v38 < mesh->m_edges.m_size );
    }
    result->m_enum = HK_SUCCESS;
  }
  v44 = 0;
  if ( v45 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v43, 4 * v45);
  v45 = 0x80000000;
  v43 = 0i64;
LABEL_58:
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>(&array);
  return result;
}

// File Line: 2007
// RVA: 0xBC3560
hkResult *__fastcall hkaiNavMeshUtils::getPointOnMeshInsideAabb(
        hkResult *result,
        hkaiStreamingCollection *collection,
        hkaiNavMeshQueryMediator *mediator,
        hkAabb *aabb,
        hkVector4f *up,
        hkPseudoRandomGenerator *rand,
        hkSimdFloat32 *radius,
        hkVector4f *out,
        int maxSamples)
{
  int v12; // ebx
  __m128 v13; // xmm3
  __int64 v14; // r13
  __int64 v15; // r13
  unsigned int m_current; // ecx
  int v17; // eax
  float v18; // xmm0_4
  int v19; // eax
  float v20; // xmm0_4
  int v21; // eax
  float v22; // xmm0_4
  signed int v23; // eax
  __m128 v24; // xmm4
  float v25; // xmm0_4
  hkBaseObjectVtbl *vfptr; // rax
  __m128 v27; // xmm2
  __m128 v28; // xmm5
  __m128 v29; // xmm0
  __m128 v30; // xmm1
  __m128 v31; // xmm7
  __m128 v32; // xmm0
  __m128 v33; // xmm6
  __m128 v35; // [rsp+20h] [rbp-D8h]
  __m128 v36[2]; // [rsp+30h] [rbp-C8h] BYREF
  int v37; // [rsp+50h] [rbp-A8h] BYREF
  __int64 v38; // [rsp+58h] [rbp-A0h]
  __int128 v39; // [rsp+60h] [rbp-98h]
  __int64 v40; // [rsp+70h] [rbp-88h]
  __m128 v41; // [rsp+80h] [rbp-78h]
  __m128 v42; // [rsp+90h] [rbp-68h]
  hkAabb *v43; // [rsp+118h] [rbp+20h]

  v43 = aabb;
  v12 = 0;
  v13 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)up), 1u), 1u);
  v14 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                               _mm_and_ps(
                                                                 _mm_cmple_ps(
                                                                   _mm_max_ps(
                                                                     _mm_shuffle_ps(v13, v13, 170),
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v13, v13, 85),
                                                                       _mm_shuffle_ps(v13, v13, 0))),
                                                                   v13),
                                                                 (__m128)xmmword_141A5BF50))];
  if ( maxSamples <= 0 )
  {
LABEL_8:
    result->m_enum = HK_FAILURE;
  }
  else
  {
    v15 = v14;
    while ( 1 )
    {
      v37 = 0;
      m_current = rand->m_current;
      v38 = 0i64;
      v40 = 0i64;
      v17 = 1664525 * m_current + 1013904223;
      v18 = (float)v17;
      v19 = 1664525 * v17 + 1013904223;
      v35.m128_f32[0] = v18 * 2.3283064e-10;
      v20 = (float)v19;
      v21 = 1664525 * v19 + 1013904223;
      v35.m128_f32[1] = v20 * 2.3283064e-10;
      v22 = (float)v21;
      v23 = 1664525 * v21 + 1013904223;
      rand->m_current = v23;
      v24 = (__m128)`hkVector4f::getComponent::`2::indexToMask[v15];
      v35.m128_f32[2] = v22 * 2.3283064e-10;
      v25 = (float)v23;
      vfptr = mediator->vfptr;
      v35.m128_f32[3] = v25 * 2.3283064e-10;
      v27 = _mm_and_ps(v24, aabb->m_max.m_quad);
      v28 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(aabb->m_max.m_quad, aabb->m_min.m_quad), v35), aabb->m_min.m_quad);
      v29 = _mm_and_ps(v24, aabb->m_min.m_quad);
      v30 = _mm_or_ps(_mm_shuffle_ps(v29, v29, 78), v29);
      v31 = _mm_or_ps(_mm_and_ps(_mm_or_ps(_mm_shuffle_ps(v30, v30, 177), v30), v24), _mm_andnot_ps(v24, v28));
      v41 = v31;
      v32 = _mm_or_ps(_mm_shuffle_ps(v27, v27, 78), v27);
      v39 = 0i64;
      v33 = _mm_or_ps(_mm_and_ps(_mm_or_ps(_mm_shuffle_ps(v32, v32, 177), v32), v24), _mm_andnot_ps(v24, v28));
      v42 = v33;
      if ( ((unsigned __int8 (__fastcall *)(hkaiNavMeshQueryMediator *, int *, __m128 *))vfptr[2].__first_virtual_table_function__)(
             mediator,
             &v37,
             v36) )
      {
        out->m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v33, v31), v36[0]), v31);
        if ( (unsigned __int8)hkaiNavMeshUtils::isAwayFromBoundaryEdges(collection, mediator, out, radius) )
          break;
      }
      if ( ++v12 >= maxSamples )
        goto LABEL_8;
      aabb = v43;
    }
    result->m_enum = HK_SUCCESS;
  }
  return result;
}

// File Line: 2041
// RVA: 0xBC37F0
bool __fastcall hkaiNavMeshUtils::isEdgeInsideAabb(hkaiNavMeshInstance *meshInstance, hkAabb *aabb, int eIdx)
{
  hkVector4f edgeB; // [rsp+20h] [rbp-28h] BYREF
  hkVector4f edgeA; // [rsp+30h] [rbp-18h] BYREF

  hkaiNavMeshInstance::getEdgePoints(meshInstance, eIdx, &edgeA, &edgeB);
  return hkaiNavMeshUtils::_isSegmentInsideAabb(&edgeA, &edgeB, aabb);
}

// File Line: 2048
// RVA: 0xBC3830
bool __fastcall hkaiNavMeshUtils::_isSegmentInsideAabb(hkVector4f *edgeA, hkVector4f *edgeB, hkAabb *aabb)
{
  __m128i v3; // xmm6
  __m128 v4; // xmm1
  __m128 v5; // xmm3
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  __m128 v8; // xmm4
  __m128 v9; // xmm3
  __m128 v11; // [rsp+20h] [rbp-28h]

  v3 = (__m128i)_mm_sub_ps(edgeB->m_quad, edgeA->m_quad);
  v4 = _mm_rcp_ps((__m128)v3);
  v5 = _mm_cmpeq_ps((__m128)0i64, (__m128)v3);
  v11 = _mm_or_ps(
          _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v3, 0x1Fu), 0x1Fu), (__m128)_xmm), v5),
          _mm_andnot_ps(v5, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v4, (__m128)v3)), v4)));
  v11.m128_i32[3] = _mm_movemask_ps(
                      _mm_cmple_ps(
                        (__m128)0i64,
                        _mm_shuffle_ps((__m128)v3, _mm_unpackhi_ps((__m128)v3, query.m_quad), 196))) & 7 | 0x3F000000;
  v6 = _mm_mul_ps(v11, _mm_sub_ps(aabb->m_max.m_quad, edgeA->m_quad));
  v7 = _mm_mul_ps(v11, _mm_sub_ps(aabb->m_min.m_quad, edgeA->m_quad));
  v8 = _mm_max_ps(v7, v6);
  v9 = _mm_min_ps(v7, v6);
  return fmax(
           fmax(
             _mm_shuffle_ps(v9, v9, 170).m128_f32[0],
             fmax(_mm_shuffle_ps(v9, v9, 85).m128_f32[0], _mm_shuffle_ps(v9, v9, 0).m128_f32[0])),
           0.0) <= fmin(
                     fmin(
                       _mm_shuffle_ps(v8, v8, 170).m128_f32[0],
                       fmin(_mm_shuffle_ps(v8, v8, 85).m128_f32[0], _mm_shuffle_ps(v8, v8, 0).m128_f32[0])),
                     1.0);
}

// File Line: 2055
// RVA: 0xBC5920
void __fastcall hkaiNavMeshUtils::getEdgesInsideAabb(
        hkaiNavMeshInstance *meshInstance,
        hkaiNavMeshQueryMediator *mediator,
        hkAabb *aabb,
        hkArray<hkaiNavMeshUtils::FaceEdgeKeyPair,hkContainerTempAllocator> *edgeHits)
{
  hkVector4f v4; // xmm0
  hkVector4f v5; // xmm1
  int v9; // edx
  __int64 v10; // rcx
  hkaiStreamingCollection::InstanceInfo *m_data; // r9
  __int64 v12; // rdx
  hkaiDirectedGraphInstance **p_m_clusterGraphInstance; // rax
  hkArrayBase<unsigned int> faceHits; // [rsp+30h] [rbp-49h] BYREF
  hkaiStreamingCollection array; // [rsp+40h] [rbp-39h] BYREF
  int v16; // [rsp+70h] [rbp-9h] BYREF
  __int64 v17; // [rsp+78h] [rbp-1h]
  __int64 v18; // [rsp+80h] [rbp+7h]
  hkaiNavMeshInstance *v19; // [rsp+88h] [rbp+Fh]
  hkaiReferenceFrame *p_m_referenceFrame; // [rsp+90h] [rbp+17h]
  __m128 m_quad; // [rsp+A0h] [rbp+27h]
  __m128 v22; // [rsp+B0h] [rbp+37h]
  hkResult result; // [rsp+E0h] [rbp+67h] BYREF

  v4.m_quad = (__m128)aabb->m_min;
  v5.m_quad = (__m128)aabb->m_max;
  faceHits.m_data = 0i64;
  faceHits.m_size = 0;
  m_quad = v4.m_quad;
  v22 = v5.m_quad;
  faceHits.m_capacityAndFlags = 0x80000000;
  v16 = 0;
  v17 = 0i64;
  v18 = 0i64;
  v19 = meshInstance;
  if ( meshInstance )
    p_m_referenceFrame = &meshInstance->m_referenceFrame;
  else
    p_m_referenceFrame = 0i64;
  ((void (__fastcall *)(hkaiNavMeshQueryMediator *, int *, hkArrayBase<unsigned int> *))mediator->vfptr[3].__first_virtual_table_function__)(
    mediator,
    &v16,
    &faceHits);
  v9 = 0;
  if ( faceHits.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      ++v9;
      faceHits.m_data[v10++] &= 0x3FFFFFu;
    }
    while ( v9 < faceHits.m_size );
  }
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array.m_instances, 1, 48);
  m_data = array.m_instances.m_data;
  v12 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    p_m_clusterGraphInstance = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( p_m_clusterGraphInstance != (hkaiDirectedGraphInstance **)16 )
      {
        *(p_m_clusterGraphInstance - 2) = 0i64;
        *(p_m_clusterGraphInstance - 1) = 0i64;
        *p_m_clusterGraphInstance = 0i64;
        p_m_clusterGraphInstance[1] = 0i64;
        p_m_clusterGraphInstance[2] = 0i64;
        *((_DWORD *)p_m_clusterGraphInstance + 6) = -1;
      }
      p_m_clusterGraphInstance += 6;
      --v12;
    }
    while ( v12 );
    m_data = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  m_data->m_instancePtr = meshInstance;
  array.m_instances.m_data->m_clusterGraphInstance = 0i64;
  array.m_instances.m_data->m_mediator = 0i64;
  hkaiNavMeshUtils::_getEdgesInsideAabb(&array, aabb, &faceHits, edgeHits);
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
  faceHits.m_size = 0;
  if ( faceHits.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      faceHits.m_data,
      4 * faceHits.m_capacityAndFlags);
}

// File Line: 2078
// RVA: 0xBC5AF0
void __fastcall hkaiNavMeshUtils::getEdgesInsideAabb(
        hkaiStreamingCollection *collection,
        hkaiNavMeshQueryMediator *mediator,
        hkAabb *aabb,
        hkArray<hkaiNavMeshUtils::FaceEdgeKeyPair,hkContainerTempAllocator> *edgeHits)
{
  hkVector4f v4; // xmm1
  hkVector4f v5; // xmm0
  hkArrayBase<unsigned int> faceHits; // [rsp+20h] [rbp-68h] BYREF
  int v10; // [rsp+30h] [rbp-58h] BYREF
  __int64 v11; // [rsp+38h] [rbp-50h]
  __int128 v12; // [rsp+40h] [rbp-48h]
  __int64 v13; // [rsp+50h] [rbp-38h]
  __m128 v14; // [rsp+60h] [rbp-28h]
  __m128 m_quad; // [rsp+70h] [rbp-18h]

  v4.m_quad = (__m128)aabb->m_min;
  v12 = 0i64;
  v5.m_quad = (__m128)aabb->m_max;
  faceHits.m_data = 0i64;
  faceHits.m_size = 0;
  faceHits.m_capacityAndFlags = 0x80000000;
  v10 = 0;
  v11 = 0i64;
  v13 = 0i64;
  m_quad = v5.m_quad;
  v14 = v4.m_quad;
  ((void (__fastcall *)(hkaiNavMeshQueryMediator *, int *, hkArrayBase<unsigned int> *))mediator->vfptr[3].__first_virtual_table_function__)(
    mediator,
    &v10,
    &faceHits);
  hkaiNavMeshUtils::_getEdgesInsideAabb(collection, aabb, &faceHits, edgeHits);
  faceHits.m_size = 0;
  if ( faceHits.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      faceHits.m_data,
      4 * faceHits.m_capacityAndFlags);
}

// File Line: 2088
// RVA: 0xBC5BC0
void __fastcall hkaiNavMeshUtils::_getEdgesInsideAabb(
        hkaiStreamingCollection *collection,
        hkAabb *aabb,
        hkArrayBase<unsigned int> *faceHits,
        hkArray<hkaiNavMeshUtils::FaceEdgeKeyPair,hkContainerTempAllocator> *edgeHits)
{
  int v4; // r12d
  hkArrayBase<unsigned int> *v7; // rax
  hkaiStreamingCollection *v8; // rdx
  __int64 v9; // rcx
  unsigned int v10; // r15d
  __int64 v11; // r14
  hkaiNavMeshInstance *m_instancePtr; // rbp
  hkaiNavMesh::Face *v13; // rsi
  int i; // edi
  hkaiNavMeshUtils::FaceEdgeKeyPair *v15; // rdx
  hkaiNavMeshUtils::FaceEdgeKeyPair v16; // [rsp+30h] [rbp-48h]
  __int64 v17; // [rsp+38h] [rbp-40h]

  v4 = 0;
  v7 = faceHits;
  v8 = collection;
  if ( faceHits->m_size > 0 )
  {
    v9 = 0i64;
    v17 = 0i64;
    do
    {
      v10 = *(unsigned int *)((char *)v7->m_data + v9);
      v11 = v10 >> 22;
      m_instancePtr = v8->m_instances.m_data[v11].m_instancePtr;
      v13 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
              m_instancePtr->m_originalFaces,
              m_instancePtr->m_numOriginalFaces,
              &m_instancePtr->m_instancedFaces,
              &m_instancePtr->m_ownedFaces,
              &m_instancePtr->m_faceMap,
              v10 & 0x3FFFFF);
      for ( i = v13->m_startEdgeIndex; i < v13->m_startEdgeIndex + v13->m_numEdges; ++i )
      {
        if ( hkaiNavMeshUtils::isEdgeInsideAabb(m_instancePtr, aabb, i) )
        {
          v16.m_faceKey = v10;
          if ( edgeHits->m_size == (edgeHits->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, edgeHits, 8);
          v15 = &edgeHits->m_data[edgeHits->m_size];
          if ( v15 )
          {
            v16.m_edgeKey = i | ((_DWORD)v11 << 22);
            *v15 = v16;
          }
          ++edgeHits->m_size;
        }
      }
      v7 = faceHits;
      v8 = collection;
      v9 = v17 + 4;
      ++v4;
      v17 += 4i64;
    }
    while ( v4 < faceHits->m_size );
  }
}

// File Line: 2112
// RVA: 0xBC5D40
void __fastcall hkaiNavMeshUtils::resolveEdgePenetrations(
        hkaiStreamingCollection *collection,
        hkaiNavMeshQueryMediator *mediator,
        hkVector4f *point,
        hkSimdFloat32 *radius,
        hkVector4f *pointOut)
{
  __m128 m_quad; // xmm1
  __m128 m_real; // xmm2
  hkBaseObjectVtbl *vfptr; // rax
  __int64 v8; // r14
  unsigned int v12; // eax
  __m128 v13; // xmm0
  unsigned int v14; // r12d
  __m128 v15; // xmm0
  hkaiNavMeshQueryMediator *v16; // rdx
  hkaiStreamingCollection *v17; // rbx
  int m_size; // r15d
  int v19; // esi
  int v20; // ebx
  unsigned int m_edgeKey; // edi
  hkaiNavMeshInstance *m_instancePtr; // rcx
  hkaiNavMesh::Edge *v23; // rax
  __m128 v24; // xmm9
  hkaiStreamingCollection::InstanceInfo *m_data; // rax
  __int64 v26; // rdi
  hkaiNavMesh::Face *v27; // r14
  hkVector4f *v28; // r9
  hkVector4f *v29; // r9
  __int64 v30; // rcx
  __m128 *v31; // r13
  __m128 v32; // xmm15
  float v33; // xmm14_4
  hkaiStreamingCollection::InstanceInfo *v34; // r12
  _DWORD *v35; // rsi
  __int64 v36; // r15
  hkaiNavMeshInstance *v37; // rbx
  hkaiNavMesh::Edge *v38; // rax
  int m_numOriginalVertices; // edx
  __int64 m_a; // rcx
  __m128 *p_m_quad; // rcx
  __m128 v42; // xmm3
  __m128 v43; // xmm4
  __int64 m_b; // rax
  __m128 v45; // xmm6
  __m128 v46; // xmm7
  __m128 v47; // xmm5
  __m128 *v48; // rax
  __m128 v49; // xmm1
  __m128 v50; // xmm2
  __m128 v51; // xmm4
  __m128 v52; // xmm5
  __m128 v53; // xmm4
  __m128 v54; // xmm1
  __m128 v55; // xmm3
  __m128 v56; // xmm1
  __m128 v57; // xmm0
  __m128 v58; // xmm1
  __m128 v59; // xmm0
  __m128 v60; // xmm2
  __m128 v61; // xmm5
  __m128 v62; // xmm1
  __m128 v63; // xmm5
  __m128 v64; // xmm10
  __m128 v65; // xmm5
  __m128 v66; // xmm8
  __m128 v67; // xmm2
  __m128 v68; // xmm1
  __m128 v69; // xmm0
  __m128 v70; // xmm7
  __m128 v71; // xmm8
  __m128 v72; // xmm1
  __m128 v73; // xmm8
  __m128 v74; // xmm1
  __m128 v75; // xmm3
  __m128 v76; // xmm2
  __m128 v77; // xmm1
  int m_startEdgeIndex; // ebx
  hkaiNavMesh::Edge *v79; // rax
  __m128 v80; // xmm1
  __m128 v81; // xmm1
  __m128 v82; // xmm0
  __m128 v83; // xmm1
  hkVector4f *index; // [rsp+28h] [rbp-D0h]
  _DWORD *array; // [rsp+30h] [rbp-C8h] BYREF
  unsigned int v86; // [rsp+38h] [rbp-C0h]
  int v87; // [rsp+3Ch] [rbp-BCh]
  hkArray<hkaiNavMeshUtils::FaceEdgeKeyPair,hkContainerTempAllocator> edgeHits; // [rsp+40h] [rbp-B8h] BYREF
  __int64 v89; // [rsp+50h] [rbp-A8h]
  int faceIndex[4]; // [rsp+60h] [rbp-98h] BYREF
  char aabb[40]; // [rsp+70h] [rbp-88h] BYREF
  __int128 v92[2]; // [rsp+98h] [rbp-60h] BYREF
  int v93; // [rsp+B8h] [rbp-40h] BYREF
  __int64 v94; // [rsp+C0h] [rbp-38h]
  __int128 v95; // [rsp+C8h] [rbp-30h]
  __int64 v96; // [rsp+D8h] [rbp-20h]
  __m128 v97; // [rsp+E8h] [rbp-10h]
  __m128 v98; // [rsp+F8h] [rbp+0h]
  __int64 v99; // [rsp+108h] [rbp+10h]
  hkaiStreamingCollection *retaddr; // [rsp+208h] [rbp+110h]
  unsigned int mesh; // [rsp+210h] [rbp+118h]
  unsigned int mesha; // [rsp+210h] [rbp+118h]
  __int64 v103; // [rsp+218h] [rbp+120h]
  __m128 *v104; // [rsp+220h] [rbp+128h]

  m_quad = point->m_quad;
  m_real = radius->m_real;
  v95 = 0i64;
  v97 = m_quad;
  vfptr = mediator->vfptr;
  v8 = 0i64;
  v98 = _mm_mul_ps(m_real, (__m128)xmmword_141A710D0);
  edgeHits.m_data = 0i64;
  edgeHits.m_size = 0;
  edgeHits.m_capacityAndFlags = 0x80000000;
  array = 0i64;
  v86 = 0;
  v87 = 0x80000000;
  v93 = 0;
  v94 = 0i64;
  v96 = 0i64;
  v99 = 0i64;
  v12 = ((__int64 (__fastcall *)(hkaiNavMeshQueryMediator *, int *, char *))vfptr[1].__first_virtual_table_function__)(
          mediator,
          &v93,
          aabb);
  v13 = point->m_quad;
  v14 = v12;
  mesh = v12;
  if ( v12 == -1 )
  {
    *radius = (hkSimdFloat32)v13;
  }
  else
  {
    v15 = _mm_add_ps(v13, radius->m_real);
    v16 = mediator;
    v17 = retaddr;
    *(__m128 *)&aabb[8] = _mm_sub_ps(point->m_quad, radius->m_real);
    *(__m128 *)&aabb[24] = v15;
    hkaiNavMeshUtils::getEdgesInsideAabb(retaddr, v16, (hkAabb *)&aabb[8], &edgeHits);
    m_size = edgeHits.m_size;
    v19 = 0;
    if ( edgeHits.m_size > 0 )
    {
      v20 = v86;
      do
      {
        m_edgeKey = edgeHits.m_data[v8].m_edgeKey;
        m_instancePtr = retaddr->m_instances.m_data[m_edgeKey >> 22].m_instancePtr;
        v23 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
                m_instancePtr->m_originalEdges,
                m_instancePtr->m_numOriginalEdges,
                &m_instancePtr->m_instancedEdges,
                &m_instancePtr->m_ownedEdges,
                &m_instancePtr->m_edgeMap,
                m_edgeKey & 0x3FFFFF);
        if ( v23->m_oppositeEdge == -1 || (v23->m_flags.m_storage & 0x20) != 0 )
        {
          if ( v20 == (v87 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 4);
            v20 = v86;
          }
          array[v20] = m_edgeKey;
          m_size = edgeHits.m_size;
          v20 = ++v86;
        }
        ++v19;
        ++v8;
      }
      while ( v19 < m_size );
      v14 = mesh;
      v17 = retaddr;
    }
    v24 = point->m_quad;
    mesha = v14 & 0x3FFFFF;
    m_data = v17->m_instances.m_data;
    v92[0] = _xmm;
    v92[1] = *(_OWORD *)_xmm;
    v26 = (__int64)m_data[v14 >> 22].m_instancePtr;
    v89 = v26;
    v27 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
            *(hkaiNavMesh::Face **)(v26 + 16),
            *(_DWORD *)(v26 + 24),
            (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v26 + 240),
            (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v26 + 272),
            (hkArray<int,hkContainerHeapAllocator> *)(v26 + 224),
            v14 & 0x3FFFFF);
    hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)v26,
      (hkaiNavMeshInstance *)(v14 & 0x3FFFFF),
      (int)faceIndex,
      v28);
    hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)v26,
      (hkaiNavMeshInstance *)(v14 & 0x3FFFFF),
      (int)&aabb[8],
      v29);
    v30 = 2i64;
    v31 = (__m128 *)v92;
    v103 = 2i64;
    v32 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
    v33 = v104->m128_f32[0] * v104->m128_f32[0];
    do
    {
      if ( (int)v86 > 0 )
      {
        v34 = v17->m_instances.m_data;
        v35 = array;
        v36 = v86;
        do
        {
          v37 = v34[*v35 >> 22].m_instancePtr;
          v38 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
                  v37->m_originalEdges,
                  v37->m_numOriginalEdges,
                  &v37->m_instancedEdges,
                  &v37->m_ownedEdges,
                  &v37->m_edgeMap,
                  *v35 & 0x3FFFFF);
          m_numOriginalVertices = v37->m_numOriginalVertices;
          m_a = v38->m_a;
          if ( (int)m_a >= m_numOriginalVertices )
            p_m_quad = &v37->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices].m_quad;
          else
            p_m_quad = &v37->m_originalVertices[m_a].m_quad;
          v42 = v37->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
          v43 = v37->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
          m_b = v38->m_b;
          v45 = v37->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
          v46 = v37->m_referenceFrame.m_transform.m_translation.m_quad;
          v47 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(*p_m_quad, *p_m_quad, 0), v43),
                      _mm_mul_ps(_mm_shuffle_ps(*p_m_quad, *p_m_quad, 85), v42)),
                    _mm_mul_ps(_mm_shuffle_ps(*p_m_quad, *p_m_quad, 170), v45)),
                  v46);
          if ( (int)m_b >= m_numOriginalVertices )
            v48 = &v37->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices].m_quad;
          else
            v48 = &v37->m_originalVertices[m_b].m_quad;
          v49 = *v48;
          v50 = _mm_mul_ps(_mm_shuffle_ps(v49, v49, 0), v43);
          v51 = v47;
          v52 = _mm_sub_ps(v47, v24);
          v53 = _mm_sub_ps(
                  v51,
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(v50, _mm_mul_ps(_mm_shuffle_ps(*v48, *v48, 85), v42)),
                      _mm_mul_ps(_mm_shuffle_ps(v49, v49, 170), v45)),
                    v46));
          v54 = _mm_mul_ps(v53, v53);
          v55 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), _mm_shuffle_ps(v54, v54, 0)),
                  _mm_shuffle_ps(v54, v54, 170));
          v56 = _mm_mul_ps(v52, v53);
          v57 = _mm_rcp_ps(v55);
          v58 = _mm_mul_ps(
                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v55, v57)), v57),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
                    _mm_shuffle_ps(v56, v56, 170)));
          v59 = _mm_cmplt_ps(v58, query.m_quad);
          v60 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v58, v59), _mm_andnot_ps(v59, query.m_quad)));
          v61 = _mm_sub_ps(v52, _mm_mul_ps(v60, v53));
          v62 = _mm_mul_ps(v61, v61);
          v63 = _mm_add_ps(v61, v24);
          v64 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v62, v62, 85), _mm_shuffle_ps(v62, v62, 0)),
                  _mm_shuffle_ps(v62, v62, 170));
          v65 = _mm_shuffle_ps(v63, _mm_unpackhi_ps(v63, v60), 196);
          if ( v64.m128_f32[0] < v33 )
          {
            v66 = _mm_sub_ps(v24, v65);
            v67 = _mm_sub_ps(*(__m128 *)&aabb[8], v65);
            v68 = _mm_mul_ps(v66, v67);
            v69 = _mm_cmplt_ps(v32, v64);
            v70 = (__m128)_mm_slli_epi32(
                            _mm_srli_epi32(
                              _mm_srai_epi32(
                                (__m128i)_mm_add_ps(
                                           _mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)),
                                           _mm_shuffle_ps(v68, v68, 170)),
                                0x1Fu),
                              0x1Fu),
                            0x1Fu);
            v71 = _mm_or_ps(_mm_and_ps(_mm_xor_ps(v66, v70), v69), _mm_andnot_ps(v69, v67));
            v72 = _mm_mul_ps(*(__m128 *)faceIndex, v71);
            v73 = _mm_sub_ps(
                    v71,
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v72, v72, 85), _mm_shuffle_ps(v72, v72, 0)),
                        _mm_shuffle_ps(v72, v72, 170)),
                      *(__m128 *)faceIndex));
            v74 = _mm_mul_ps(v73, v73);
            v75 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v74, v74, 85), _mm_shuffle_ps(v74, v74, 0)),
                    _mm_shuffle_ps(v74, v74, 170));
            v76 = _mm_rsqrt_ps(v75);
            v77 = _mm_rsqrt_ps(v64);
            v24 = _mm_add_ps(
                    v24,
                    _mm_mul_ps(
                      _mm_sub_ps(
                        *v104,
                        _mm_xor_ps(
                          _mm_andnot_ps(
                            _mm_cmple_ps(v64, (__m128)0i64),
                            _mm_mul_ps(
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v77, v64), v77)),
                                _mm_mul_ps(*(__m128 *)_xmm, v77)),
                              v64)),
                          v70)),
                      _mm_mul_ps(
                        v73,
                        _mm_andnot_ps(
                          _mm_cmple_ps(v75, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v76, v75), v76)),
                            _mm_mul_ps(*(__m128 *)_xmm, v76))))));
          }
          ++v35;
          --v36;
        }
        while ( v36 );
        v26 = v89;
        v30 = v103;
      }
      m_startEdgeIndex = v27->m_startEdgeIndex;
      if ( v27->m_startEdgeIndex < v27->m_startEdgeIndex + v27->m_numEdges )
      {
        do
        {
          v79 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
                  *(hkaiNavMesh::Edge **)(v26 + 32),
                  *(_DWORD *)(v26 + 40),
                  (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v26 + 256),
                  (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v26 + 288),
                  (hkArray<int,hkContainerHeapAllocator> *)(v26 + 208),
                  m_startEdgeIndex);
          if ( v79->m_oppositeEdge != -1 && (v79->m_flags.m_storage & 0x20) == 0 )
          {
            hkaiNavMeshUtils::calcEdgePlane<hkaiNavMeshInstance>(
              (hkaiNavMeshUtils *)v26,
              (hkaiNavMeshInstance *)mesha,
              m_startEdgeIndex,
              (int)faceIndex,
              (hkVector4f *)aabb,
              index);
            v80 = _mm_mul_ps(*(__m128 *)aabb, v24);
            v81 = _mm_shuffle_ps(v80, _mm_unpackhi_ps(v80, *(__m128 *)aabb), 196);
            v82 = _mm_add_ps(_mm_shuffle_ps(v81, v81, 78), v81);
            v83 = _mm_add_ps(_mm_shuffle_ps(v82, v82, 177), v82);
            if ( v83.m128_f32[0] > 0.0 )
              v24 = _mm_sub_ps(v24, _mm_mul_ps(_mm_mul_ps(v83, *v31), *(__m128 *)aabb));
          }
          ++m_startEdgeIndex;
        }
        while ( m_startEdgeIndex < v27->m_startEdgeIndex + v27->m_numEdges );
        v30 = v103;
      }
      v17 = retaddr;
      ++v31;
      v103 = --v30;
    }
    while ( v30 );
    *radius = (hkSimdFloat32)v24;
  }
  v86 = 0;
  if ( v87 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v87);
  array = 0i64;
  edgeHits.m_size = 0;
  v87 = 0x80000000;
  if ( edgeHits.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      edgeHits.m_data,
      8 * edgeHits.m_capacityAndFlags);
}

// File Line: 2230
// RVA: 0xBC6550
hkaiStaticTreeNavMeshQueryMediator *__fastcall hkaiNavMeshUtils::setupQueryMediator(
        hkaiNavMesh *mesh,
        hkaiNavMeshUtils::MediatorType mediatorType)
{
  _QWORD **Value; // rax
  hkaiStaticTreeNavMeshQueryMediator *v4; // rax
  hkaiStaticTreeNavMeshQueryMediator *v5; // rax
  hkaiStaticTreeNavMeshQueryMediator *v6; // rbx

  hkaiNavMeshUtils::validate(mesh, 1);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (hkaiStaticTreeNavMeshQueryMediator *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                               Value[11],
                                               32i64);
  if ( v4 )
  {
    hkaiStaticTreeNavMeshQueryMediator::hkaiStaticTreeNavMeshQueryMediator(v4);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  hkaiStaticTreeNavMeshQueryMediator::setNavMesh(v6, mesh);
  return v6;
}

// File Line: 2246
// RVA: 0xBC3920
void __fastcall hkaiNavMeshUtils::getNearbyBoundaries(
        hkaiStreamingCollection::InstanceInfo *streamingInfo,
        unsigned int currentFaceKey,
        hkAabb *aabb,
        hkaiAgentTraversalInfo *traversalInfo,
        hkaiAstarEdgeFilter *filter,
        bool doFloodFill,
        hkVector4f *position,
        hkVector4f *up,
        hkArrayBase<hkVector4f> *boundariesOut)
{
  if ( doFloodFill )
    hkaiNavMeshUtils::_getNearbyBoundariesFlood(
      streamingInfo,
      currentFaceKey,
      aabb,
      traversalInfo,
      filter,
      position,
      up,
      boundariesOut);
  else
    hkaiNavMeshUtils::_getNearbyBoundariesNeighbors(
      streamingInfo,
      currentFaceKey,
      aabb,
      traversalInfo,
      filter,
      position,
      boundariesOut);
}

// File Line: 2259
// RVA: 0xBC4170
void __fastcall hkaiNavMeshUtils::_getNearbyBoundariesFlood(
        hkaiStreamingCollection::InstanceInfo *streamingInfo,
        unsigned int inputFaceKey,
        hkAabb *aabb,
        hkaiAgentTraversalInfo *traversalInfo,
        hkaiAstarEdgeFilter *filter,
        hkVector4f *position,
        hkVector4f *up,
        hkArrayBase<hkVector4f> *boundariesOut)
{
  _QWORD *Value; // rax
  _QWORD *v12; // rcx
  _QWORD *v13; // r10
  unsigned __int64 v14; // rax
  _QWORD *v15; // rcx
  int v16; // r12d
  __m128 v17; // xmm2
  __m128 v18; // xmm10
  __m128 v19; // xmm2
  float v20; // xmm11_4
  hkLifoAllocator *v21; // rax
  bool v22; // cc
  unsigned __int64 v23; // rcx
  int SizeInBytesFor; // ebx
  hkLifoAllocator *v25; // rax
  char *v26; // rsi
  int v27; // edx
  char *v28; // rcx
  hkaiAgentTraversalInfo *v29; // r13
  __m128 v30; // xmm6
  int v31; // r15d
  int v32; // r9d
  unsigned int v33; // edx
  unsigned int v34; // r8d
  int m_size; // eax
  int v36; // r11d
  unsigned int v37; // edx
  unsigned int v38; // r8d
  hkaiNavMesh::Face *v39; // rax
  hkaiNavMesh::Face *v40; // r13
  int v41; // ecx
  hkaiNavMeshInstance *m_accessor; // rbx
  unsigned int v43; // esi
  int index; // ecx
  int v45; // r13d
  hkaiNavMesh::Edge *v46; // rax
  int m_numOriginalVertices; // edx
  __int64 v48; // rsi
  __int64 m_a; // rax
  hkVector4f *v50; // rcx
  __int64 v51; // rax
  __m128 v52; // xmm5
  hkVector4f *v53; // rax
  __m128 m_quad; // xmm1
  __m128 v55; // xmm8
  __m128 v56; // xmm3
  __m128 v57; // xmm7
  __m128 v58; // xmm2
  __m128 v59; // xmm2
  __m128 v60; // xmm4
  __m128 v61; // xmm1
  __m128 v62; // xmm3
  __m128 v63; // xmm1
  __m128 v64; // xmm2
  __m128 v65; // xmm1
  __m128 v66; // xmm3
  __m128 v67; // xmm1
  __m128 v68; // xmm8
  __m128 v69; // xmm8
  hkaiAgentTraversalInfo v70; // rax
  int v71; // ecx
  unsigned int v72; // eax
  unsigned int v73; // r9d
  int v74; // r10d
  int v75; // edx
  unsigned int v76; // r8d
  int v77; // eax
  __int64 v78; // rax
  int v79; // eax
  int m_numEdges; // eax
  char v81; // si
  unsigned int v82; // ebx
  hkaiNavMesh::Edge *v83; // rax
  __int64 v84; // rdx
  __int64 m_b; // r8
  int m_oppositeEdge; // r11d
  int m_oppositeFace; // r10d
  char m_storage; // cl
  int v89; // r9d
  hkVector4f *v90; // rdx
  __m128 v91; // xmm2
  hkVector4f *v92; // rdx
  __m128 v93; // xmm1
  __m128 v94; // xmm0
  char v95; // cl
  unsigned int v96; // edx
  unsigned int v97; // eax
  signed int v98; // ebx
  hkLifoAllocator *v99; // rax
  void *v100; // rsi
  int v101; // r8d
  hkLifoAllocator *v102; // rax
  _QWORD *v103; // rax
  _QWORD *v104; // rcx
  _QWORD *v105; // r8
  unsigned __int64 v106; // rax
  _QWORD *v107; // rcx
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > v108; // [rsp+60h] [rbp-98h] BYREF
  void *m_cur; // [rsp+78h] [rbp-80h]
  int v110[2]; // [rsp+80h] [rbp-78h] BYREF
  int v111; // [rsp+88h] [rbp-70h]
  int v112; // [rsp+8Ch] [rbp-6Ch]
  int v113; // [rsp+90h] [rbp-68h]
  void *p; // [rsp+98h] [rbp-60h]
  hkaiGeneralAccessor v115; // [rsp+A0h] [rbp-58h] BYREF
  int v116; // [rsp+B8h] [rbp-40h]
  int v117; // [rsp+BCh] [rbp-3Ch]
  int *v118; // [rsp+C0h] [rbp-38h] BYREF
  int *v119; // [rsp+C8h] [rbp-30h]
  int *dataPtrOut; // [rsp+D0h] [rbp-28h] BYREF
  int *v121; // [rsp+D8h] [rbp-20h] BYREF
  hkaiNavMesh::Face *v122; // [rsp+E0h] [rbp-18h]
  hkVector4f startInOut; // [rsp+F8h] [rbp+0h] BYREF
  hkVector4f endInOut; // [rsp+108h] [rbp+10h] BYREF
  __int64 v125[3]; // [rsp+118h] [rbp+20h] BYREF
  char v126; // [rsp+130h] [rbp+38h]
  int v127; // [rsp+138h] [rbp+40h] BYREF
  int *v128; // [rsp+140h] [rbp+48h]
  int *v129; // [rsp+148h] [rbp+50h]
  __m128 v130; // [rsp+158h] [rbp+60h]
  int v131; // [rsp+168h] [rbp+70h]
  __int64 v132; // [rsp+170h] [rbp+78h]
  int *v133; // [rsp+178h] [rbp+80h]
  __m128 v134; // [rsp+188h] [rbp+90h]
  unsigned int v135; // [rsp+198h] [rbp+A0h]
  hkaiNavMesh::Face *v136; // [rsp+1A0h] [rbp+A8h]
  int *v137; // [rsp+1A8h] [rbp+B0h]
  hkAabb *aabba; // [rsp+268h] [rbp+170h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)Value[1];
  v13 = Value;
  if ( (unsigned __int64)v12 < Value[3] )
  {
    *v12 = "TtgetNearbyBoundariesFlood";
    v14 = __rdtsc();
    v15 = v12 + 2;
    *((_DWORD *)v15 - 2) = v14;
    v13[1] = v15;
  }
  if ( inputFaceKey != -1 )
  {
    v115.m_currentSection = -1;
    v115.m_sectionInfo = streamingInfo;
    v115.m_accessor = 0i64;
    hkaiGeneralAccessor::setSection(&v115, inputFaceKey >> 22);
    v16 = 0;
    v17 = _mm_mul_ps(_mm_sub_ps(aabb->m_max.m_quad, aabb->m_min.m_quad), (__m128)xmmword_141A711B0);
    v18 = _mm_mul_ps(_mm_add_ps(aabb->m_min.m_quad, aabb->m_max.m_quad), (__m128)xmmword_141A711B0);
    v19 = _mm_mul_ps(v17, v17);
    v20 = (float)(_mm_shuffle_ps(v19, v19, 85).m128_f32[0] + _mm_shuffle_ps(v19, v19, 0).m128_f32[0])
        + _mm_shuffle_ps(v19, v19, 170).m128_f32[0];
    v21 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v22 = v21->m_slabSize < 256;
    v23 = (unsigned __int64)v21->m_cur + 256;
    m_cur = v21->m_cur;
    if ( v22 || (void *)v23 > v21->m_end )
      m_cur = hkLifoAllocator::allocateFromNewSlab(v21, 256);
    else
      v21->m_cur = (void *)v23;
    SizeInBytesFor = hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::getSizeInBytesFor(64);
    v117 = SizeInBytesFor;
    if ( SizeInBytesFor )
    {
      v25 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v26 = (char *)v25->m_cur;
      v27 = (SizeInBytesFor + 127) & 0xFFFFFF80;
      p = v26;
      v28 = &v26[v27];
      if ( v27 > v25->m_slabSize || v28 > v25->m_end )
      {
        v26 = (char *)hkLifoAllocator::allocateFromNewSlab(v25, v27);
        p = v26;
      }
      else
      {
        v25->m_cur = v28;
      }
    }
    else
    {
      v26 = 0i64;
      p = 0i64;
    }
    v116 = SizeInBytesFor | 0x80000000;
    hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>(
      &v108,
      v26,
      SizeInBytesFor);
    v29 = traversalInfo;
    v30 = v18;
    v119 = 0i64;
    v118 = 0i64;
    v113 = 4;
    v31 = -1;
    HIDWORD(m_cur) = -1;
    v112 = -1;
    v111 = -1;
    while ( 1 )
    {
      v32 = v108.m_elem.m_size - 1;
      if ( v108.m_elem.m_size - 1 <= 0
        || (v33 = v32 & (-1640531535 * (inputFaceKey >> 4)), v34 = v108.m_elem.m_data[v33], v34 == -1) )
      {
LABEL_19:
        m_size = v108.m_elem.m_size;
      }
      else
      {
        while ( v34 != inputFaceKey )
        {
          v33 = v32 & (v33 + 1);
          v34 = v108.m_elem.m_data[v33];
          if ( v34 == -1 )
            goto LABEL_19;
        }
        m_size = v33;
      }
      if ( m_size > v32 )
      {
        if ( 2 * v108.m_numElems > v32 )
          break;
        v36 = 1;
        v37 = (v108.m_elem.m_size - 1) & (-1640531535 * (inputFaceKey >> 4));
        v38 = v108.m_elem.m_data[v37];
        if ( v38 != -1 )
        {
          while ( v38 != inputFaceKey )
          {
            v37 = (v108.m_elem.m_size - 1) & (v37 + 1);
            v38 = v108.m_elem.m_data[v37];
            if ( v38 == -1 )
              goto LABEL_28;
          }
          v36 = 0;
        }
LABEL_28:
        v108.m_numElems += v36;
        v108.m_elem.m_data[v37] = inputFaceKey;
        hkaiGeneralAccessor::setSection(&v115, inputFaceKey >> 22);
        v39 = hkaiNavMeshInstance_getWithData_hkaiNavMesh::Face_int_(
                v115.m_accessor->m_originalFaces,
                v115.m_accessor->m_numOriginalFaces,
                &v115.m_accessor->m_instancedFaces,
                &v115.m_accessor->m_ownedFaces,
                v115.m_accessor->m_originalFaceData,
                &v115.m_accessor->m_instancedFaceData,
                &v115.m_accessor->m_ownedFaceData,
                &v115.m_accessor->m_faceMap,
                inputFaceKey & 0x3FFFFF,
                v115.m_accessor->m_faceDataStriding,
                (const int **)&dataPtrOut);
        v128 = 0i64;
        v132 = 0i64;
        v40 = v39;
        v122 = v39;
        v136 = 0i64;
        v127 = -1;
        v131 = -1;
        v135 = -1;
        if ( traversalInfo )
        {
          v136 = v39;
          v130 = v30;
          v127 = HIDWORD(m_cur);
          v135 = inputFaceKey;
          v128 = v119;
          v137 = dataPtrOut;
          v129 = v118;
        }
        v41 = 0;
        LODWORD(m_cur) = 0;
        if ( v39->m_numEdges > 0 )
        {
          m_accessor = v115.m_accessor;
          v43 = inputFaceKey >> 22 << 22;
          do
          {
            index = v40->m_startEdgeIndex + v41;
            v45 = index | v43;
            if ( (index | v43) != v31 )
            {
              v46 = hkaiNavMeshInstance_getWithData_hkaiNavMesh::Edge_int_(
                      m_accessor->m_originalEdges,
                      m_accessor->m_numOriginalEdges,
                      &m_accessor->m_instancedEdges,
                      &m_accessor->m_ownedEdges,
                      m_accessor->m_originalEdgeData,
                      &m_accessor->m_instancedEdgeData,
                      &m_accessor->m_ownedEdgeData,
                      &m_accessor->m_edgeMap,
                      index,
                      m_accessor->m_edgeDataStriding,
                      (const int **)&v121);
              m_accessor = v115.m_accessor;
              m_numOriginalVertices = v115.m_accessor->m_numOriginalVertices;
              v48 = (__int64)v46;
              m_a = v46->m_a;
              if ( (int)m_a >= m_numOriginalVertices )
                v50 = &v115.m_accessor->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices];
              else
                v50 = &v115.m_accessor->m_originalVertices[m_a];
              v51 = *(int *)(v48 + 4);
              v52 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_shuffle_ps(v50->m_quad, v50->m_quad, 85),
                            v115.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                          _mm_mul_ps(
                            _mm_shuffle_ps(v50->m_quad, v50->m_quad, 0),
                            v115.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                        _mm_mul_ps(
                          _mm_shuffle_ps(v50->m_quad, v50->m_quad, 170),
                          v115.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
                      v115.m_accessor->m_referenceFrame.m_transform.m_translation.m_quad);
              if ( (int)v51 >= m_numOriginalVertices )
                v53 = &v115.m_accessor->m_ownedVertices.m_data[(int)v51 - m_numOriginalVertices];
              else
                v53 = &v115.m_accessor->m_originalVertices[v51];
              m_quad = v53->m_quad;
              v55 = _mm_sub_ps(v52, v18);
              v56 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_shuffle_ps(m_quad, m_quad, 85),
                            v115.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                          _mm_mul_ps(
                            _mm_shuffle_ps(m_quad, m_quad, 0),
                            v115.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                        _mm_mul_ps(
                          _mm_shuffle_ps(m_quad, m_quad, 170),
                          v115.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
                      v115.m_accessor->m_referenceFrame.m_transform.m_translation.m_quad);
              startInOut.m_quad = v52;
              endInOut.m_quad = v56;
              v57 = _mm_sub_ps(v56, v52);
              v58 = _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v57, v57, 201), v55),
                      _mm_mul_ps(_mm_shuffle_ps(v55, v55, 201), v57));
              v59 = _mm_mul_ps(_mm_shuffle_ps(v58, v58, 201), position->m_quad);
              if ( (float)((float)(_mm_shuffle_ps(v59, v59, 85).m128_f32[0] + _mm_shuffle_ps(v59, v59, 0).m128_f32[0])
                         + _mm_shuffle_ps(v59, v59, 170).m128_f32[0]) >= 0.0 )
              {
                v60 = _mm_sub_ps(v52, v56);
                v61 = _mm_mul_ps(v60, v60);
                v62 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v61, v61, 85), _mm_shuffle_ps(v61, v61, 0)),
                        _mm_shuffle_ps(v61, v61, 170));
                v63 = _mm_mul_ps(v55, v60);
                v64 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v63, v63, 85), _mm_shuffle_ps(v63, v63, 0)),
                        _mm_shuffle_ps(v63, v63, 170));
                v65 = _mm_rcp_ps(v62);
                v66 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v65, v62)), v65), v64);
                v67 = _mm_cmplt_ps(v66, query.m_quad);
                v68 = _mm_sub_ps(
                        v55,
                        _mm_mul_ps(
                          _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v67, query.m_quad), _mm_and_ps(v67, v66))),
                          v60));
                v69 = _mm_mul_ps(v68, v68);
                if ( (float)((float)(_mm_shuffle_ps(v69, v69, 85).m128_f32[0] + _mm_shuffle_ps(v69, v69, 0).m128_f32[0])
                           + _mm_shuffle_ps(v69, v69, 170).m128_f32[0]) < v20 )
                {
                  if ( *(_DWORD *)(v48 + 8) != -1 && (*(_BYTE *)(v48 + 16) & 0x20) == 0 )
                  {
                    if ( !traversalInfo )
                      goto LABEL_46;
                    v133 = v121;
                    v131 = v45;
                    v125[1] = (__int64)aabb;
                    v132 = v48;
                    v134 = _mm_add_ps(_mm_mul_ps(v57, (__m128)xmmword_141A711B0), v52);
                    v125[2] = (__int64)&v127;
                    v70 = *traversalInfo;
                    v125[0] = (__int64)v115.m_accessor;
                    v126 = 4;
                    if ( (*(unsigned __int8 (__fastcall **)(hkaiAgentTraversalInfo *, __int64 *))(*(_QWORD *)&v70 + 40i64))(
                           traversalInfo,
                           v125) )
                    {
                      m_accessor = v115.m_accessor;
LABEL_46:
                      if ( v16 >= 64 )
                        goto LABEL_88;
                      v71 = *(_DWORD *)(v48 + 12);
                      if ( (*(_BYTE *)(v48 + 16) & 0x40) != 0 )
                        v72 = v71 & 0xFFC00000;
                      else
                        v72 = m_accessor->m_runtimeId << 22;
                      v73 = v72 | v71 & 0x3FFFFF;
                      if ( v71 == -1 )
                        v73 = -1;
                      v74 = v108.m_elem.m_size - 1;
                      if ( v108.m_elem.m_size - 1 <= 0
                        || (v75 = v74 & (-1640531535 * (v73 >> 4)), v76 = v108.m_elem.m_data[v75], v76 == -1) )
                      {
LABEL_56:
                        v77 = v108.m_elem.m_size;
                      }
                      else
                      {
                        while ( v76 != v73 )
                        {
                          v75 = v74 & (v75 + 1);
                          v76 = v108.m_elem.m_data[v75];
                          if ( v76 == -1 )
                            goto LABEL_56;
                        }
                        v77 = v75;
                      }
                      v43 = inputFaceKey >> 22 << 22;
                      if ( v77 > v74 )
                      {
                        v78 = v16++;
                        *((_DWORD *)m_cur + v78) = v45;
                        m_accessor = v115.m_accessor;
                      }
                      goto LABEL_64;
                    }
                  }
                  if ( hkaiAvoidanceSolverUtils::clipSegmentInsideAabb(aabba, &startInOut, &endInOut) )
                  {
                    *(hkVector4f *)(up->m_quad.m128_u64[0] + 16i64 * up->m_quad.m128_i32[2]++) = (hkVector4f)startInOut.m_quad;
                    *(hkVector4f *)(up->m_quad.m128_u64[0] + 16i64 * up->m_quad.m128_i32[2]) = (hkVector4f)endInOut.m_quad;
                    v79 = up->m_quad.m128_i32[3];
                    if ( ++up->m_quad.m128_i32[2] == (v79 & 0x3FFFFFFF) )
                      goto LABEL_88;
                  }
                  m_accessor = v115.m_accessor;
                }
              }
              v43 = inputFaceKey >> 22 << 22;
            }
LABEL_64:
            v40 = v122;
            m_numEdges = v122->m_numEdges;
            v41 = (_DWORD)m_cur + 1;
            LODWORD(m_cur) = v41;
          }
          while ( v41 < m_numEdges );
        }
        v29 = traversalInfo;
      }
      v81 = 0;
      if ( !v16 )
        break;
      do
      {
        if ( v81 )
          break;
        v81 = 1;
        v82 = *((_DWORD *)m_cur + --v16);
        HIDWORD(m_cur) = v82;
        hkaiGeneralAccessor::setSection(&v115, v82 >> 22);
        v83 = hkaiNavMeshInstance_getWithData_hkaiNavMesh::Edge_int_(
                v115.m_accessor->m_originalEdges,
                v115.m_accessor->m_numOriginalEdges,
                &v115.m_accessor->m_instancedEdges,
                &v115.m_accessor->m_ownedEdges,
                v115.m_accessor->m_originalEdgeData,
                &v115.m_accessor->m_instancedEdgeData,
                &v115.m_accessor->m_ownedEdgeData,
                &v115.m_accessor->m_edgeMap,
                v82 & 0x3FFFFF,
                v115.m_accessor->m_edgeDataStriding,
                (const int **)&v118);
        v84 = v83->m_a;
        v110[0] = v83->m_a;
        m_b = v83->m_b;
        v110[1] = v83->m_b;
        m_oppositeEdge = v83->m_oppositeEdge;
        v111 = m_oppositeEdge;
        m_oppositeFace = v83->m_oppositeFace;
        v112 = m_oppositeFace;
        m_storage = v83->m_flags.m_storage;
        v113 = *(_DWORD *)&v83->m_flags.m_storage;
        if ( v29 )
        {
          v89 = v115.m_accessor->m_numOriginalVertices;
          if ( (int)v84 >= v89 )
            v90 = &v115.m_accessor->m_ownedVertices.m_data[(int)v84 - v89];
          else
            v90 = &v115.m_accessor->m_originalVertices[v84];
          v91 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(v90->m_quad, v90->m_quad, 85),
                        v115.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                      _mm_mul_ps(
                        _mm_shuffle_ps(v90->m_quad, v90->m_quad, 0),
                        v115.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                    _mm_mul_ps(
                      _mm_shuffle_ps(v90->m_quad, v90->m_quad, 170),
                      v115.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
                  v115.m_accessor->m_referenceFrame.m_transform.m_translation.m_quad);
          if ( (int)m_b >= v89 )
            v92 = &v115.m_accessor->m_ownedVertices.m_data[(int)m_b - v89];
          else
            v92 = &v115.m_accessor->m_originalVertices[m_b];
          v93 = v92->m_quad;
          v94 = v92->m_quad;
          v119 = v110;
          v30 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(v93, v93, 85),
                              v115.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                            _mm_mul_ps(
                              _mm_shuffle_ps(v94, v93, 0),
                              v115.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                          _mm_mul_ps(
                            _mm_shuffle_ps(v93, v93, 170),
                            v115.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
                        v115.m_accessor->m_referenceFrame.m_transform.m_translation.m_quad),
                      v91),
                    (__m128)xmmword_141A711B0),
                  v91);
        }
        v95 = m_storage & 0x40;
        if ( v95 )
          v96 = m_oppositeFace & 0xFFC00000;
        else
          v96 = v115.m_accessor->m_runtimeId << 22;
        inputFaceKey = v96 | m_oppositeFace & 0x3FFFFF;
        if ( m_oppositeFace == -1 )
          inputFaceKey = -1;
        v97 = v95 ? m_oppositeEdge & 0xFFC00000 : v115.m_accessor->m_runtimeId << 22;
        v31 = v97 | m_oppositeEdge & 0x3FFFFF;
        if ( m_oppositeEdge == -1 )
          v31 = -1;
      }
      while ( v16 );
    }
LABEL_88:
    v108.m_elem.m_size = 0;
    if ( v108.m_elem.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v108.m_elem.m_data,
        4 * v108.m_elem.m_capacityAndFlags);
    v108.m_elem.m_data = 0i64;
    v108.m_elem.m_capacityAndFlags = 0x80000000;
    v98 = (v117 + 127) & 0xFFFFFF80;
    v99 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v100 = p;
    v101 = (v98 + 15) & 0xFFFFFFF0;
    if ( v98 > v99->m_slabSize || (char *)p + v101 != v99->m_cur || v99->m_firstNonLifoEnd == p )
      hkLifoAllocator::slowBlockFree(v99, p, v101);
    else
      v99->m_cur = p;
    if ( v116 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v100, v116 & 0x3FFFFFFF);
    v102 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    if ( v102->m_slabSize < 256 || (char *)m_cur + 256 != v102->m_cur || v102->m_firstNonLifoEnd == m_cur )
      hkLifoAllocator::slowBlockFree(v102, m_cur, 256);
    else
      v102->m_cur = m_cur;
  }
  v103 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v104 = (_QWORD *)v103[1];
  v105 = v103;
  if ( (unsigned __int64)v104 < v103[3] )
  {
    *v104 = "Et";
    v106 = __rdtsc();
    v107 = v104 + 2;
    *((_DWORD *)v107 - 2) = v106;
    v105[1] = v107;
  }
}

// File Line: 2452
// RVA: 0xBC39A0
void __fastcall hkaiNavMeshUtils::_getNearbyBoundariesNeighbors(
        hkaiStreamingCollection::InstanceInfo *streamingInfo,
        unsigned int currentFaceKey,
        hkAabb *aabb,
        hkaiAgentTraversalInfo *traversalInfo,
        hkaiAstarEdgeFilter *modifier,
        hkVector4f *position,
        hkArrayBase<hkVector4f> *boundariesOut)
{
  hkaiStreamingCollection::InstanceInfo *v7; // r15
  unsigned int v8; // r14d
  _QWORD *Value; // r11
  unsigned __int64 v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  _QWORD *v15; // rcx
  hkaiNavMeshInstance *m_instancePtr; // rbx
  int m_numOriginalFaces; // edx
  hkaiNavMesh::Face *v18; // rsi
  int v19; // r12d
  int v20; // edi
  hkLifoAllocator *v21; // rax
  int *m_cur; // r13
  int v23; // edx
  char *v24; // rcx
  int v25; // edi
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_ownedEdges; // r9
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_instancedEdges; // r8
  hkaiNavMesh::Edge *v28; // rax
  unsigned int m_oppositeFace; // edx
  unsigned int v30; // eax
  int v31; // ecx
  __int64 v32; // rax
  __int64 v33; // rax
  int v34; // r12d
  _QWORD *v35; // r8
  _QWORD *v36; // rcx
  unsigned __int64 v37; // rax
  _QWORD *v38; // rcx
  int v39; // edi
  int *v40; // rax
  __int64 v41; // rbx
  hkaiNavMesh::Face *v42; // r15
  int index; // r14d
  hkArray<int,hkContainerHeapAllocator> *ownedData; // rdx
  hkArray<int,hkContainerHeapAllocator> *v45; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v46; // rcx
  hkaiNavMesh::Edge *v47; // rdi
  int v48; // eax
  __int64 m_a; // rax
  int v50; // ecx
  __m128 *v51; // rax
  __m128 v52; // xmm1
  __m128 v53; // xmm4
  __m128 v54; // xmm5
  __int64 m_b; // rax
  __m128 v56; // xmm6
  __m128 v57; // xmm7
  __m128 v58; // xmm3
  __m128 *v59; // rax
  __m128 v60; // xmm1
  hkaiNavMesh::Edge *v61; // rax
  int v62; // edx
  __int64 v63; // rcx
  __m128 *v64; // rcx
  __m128 v65; // xmm3
  __m128 v66; // xmm4
  __int64 v67; // rax
  __m128 v68; // xmm5
  __m128 v69; // xmm6
  __m128 v70; // xmm2
  __m128 *v71; // rax
  __m128 v72; // xmm1
  int v73; // eax
  signed int v74; // ebx
  hkLifoAllocator *v75; // rax
  int v76; // r8d
  _QWORD *v77; // rax
  _QWORD *v78; // rcx
  _QWORD *v79; // r8
  unsigned __int64 v80; // rax
  _QWORD *v81; // rcx
  int v82; // [rsp+60h] [rbp-98h]
  int v83; // [rsp+64h] [rbp-94h]
  int v84; // [rsp+68h] [rbp-90h]
  unsigned int v85; // [rsp+70h] [rbp-88h]
  int *v86; // [rsp+78h] [rbp-80h]
  int *v87; // [rsp+80h] [rbp-78h] BYREF
  int *dataPtrOut; // [rsp+88h] [rbp-70h] BYREF
  hkVector4f startInOut; // [rsp+98h] [rbp-60h] BYREF
  hkVector4f endInOut; // [rsp+A8h] [rbp-50h] BYREF
  __int64 v91[3]; // [rsp+B8h] [rbp-40h] BYREF
  char v92; // [rsp+D0h] [rbp-28h]
  int v93; // [rsp+D8h] [rbp-20h] BYREF
  __int64 v94; // [rsp+E0h] [rbp-18h]
  __int64 v95; // [rsp+E8h] [rbp-10h]
  hkReferencedObject v96; // [rsp+F8h] [rbp+0h]
  unsigned int v97; // [rsp+108h] [rbp+10h]
  hkaiNavMesh::Edge *v98; // [rsp+110h] [rbp+18h]
  int *v99; // [rsp+118h] [rbp+20h]
  __m128 v100; // [rsp+128h] [rbp+30h]
  int v101; // [rsp+138h] [rbp+40h]
  hkaiNavMesh::Face *v102; // [rsp+140h] [rbp+48h]
  int *v103; // [rsp+148h] [rbp+50h]
  hkaiStreamingCollection::InstanceInfo *retaddr; // [rsp+1C8h] [rbp+D0h]
  unsigned int v105; // [rsp+1D0h] [rbp+D8h]
  int v106; // [rsp+1D0h] [rbp+D8h]
  hkAabb *aabba; // [rsp+1D8h] [rbp+E0h]

  LODWORD(aabba) = currentFaceKey;
  v105 = (unsigned int)streamingInfo;
  v7 = streamingInfo;
  v8 = currentFaceKey;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = Value[1];
  if ( v10 < Value[3] )
  {
    *(_QWORD *)v10 = "LtgetBoundariesNeighbors";
    *(_QWORD *)(v10 + 16) = "Stinit";
    v11 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v11;
    Value[1] = v10 + 24;
  }
  if ( v8 != -1 )
  {
    v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v13 = (_QWORD *)v12[1];
    if ( (unsigned __int64)v13 < v12[3] )
    {
      *v13 = "Stneighbors";
      v14 = __rdtsc();
      v15 = v13 + 2;
      *((_DWORD *)v15 - 2) = v14;
      v12[1] = v15;
    }
    m_instancePtr = v7[v8 >> 22].m_instancePtr;
    m_numOriginalFaces = m_instancePtr->m_numOriginalFaces;
    if ( (int)(v8 & 0x3FFFFF) < m_numOriginalFaces + m_instancePtr->m_ownedFaces.m_size )
    {
      v18 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
              m_instancePtr->m_originalFaces,
              m_numOriginalFaces,
              &m_instancePtr->m_instancedFaces,
              &m_instancePtr->m_ownedFaces,
              &m_instancePtr->m_faceMap,
              v8 & 0x3FFFFF);
      v19 = 0;
      v20 = v18->m_numEdges + 1;
      v83 = v20;
      if ( v18->m_numEdges == -1 )
      {
        m_cur = 0i64;
      }
      else
      {
        v21 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        m_cur = (int *)v21->m_cur;
        v23 = (4 * v20 + 127) & 0xFFFFFF80;
        v24 = (char *)m_cur + v23;
        if ( v23 > v21->m_slabSize || v24 > v21->m_end )
          m_cur = (int *)hkLifoAllocator::allocateFromNewSlab(v21, v23);
        else
          v21->m_cur = v24;
      }
      v25 = 0;
      if ( v18->m_numEdges > 0 )
      {
        p_m_ownedEdges = &m_instancePtr->m_ownedEdges;
        p_m_instancedEdges = &m_instancePtr->m_instancedEdges;
        do
        {
          v28 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
                  m_instancePtr->m_originalEdges,
                  m_instancePtr->m_numOriginalEdges,
                  p_m_instancedEdges,
                  p_m_ownedEdges,
                  &m_instancePtr->m_edgeMap,
                  v25 + v18->m_startEdgeIndex);
          if ( v28->m_oppositeEdge != -1 )
          {
            m_oppositeFace = v28->m_oppositeFace;
            if ( (v28->m_flags.m_storage & 0x40) != 0 )
              v30 = m_oppositeFace & 0xFFC00000;
            else
              v30 = m_instancePtr->m_runtimeId << 22;
            v31 = v30 | m_oppositeFace & 0x3FFFFF;
            v32 = v19;
            if ( m_oppositeFace == -1 )
              v31 = -1;
            ++v19;
            m_cur[v32] = v31;
          }
          ++v25;
        }
        while ( v25 < v18->m_numEdges );
        v8 = v105;
        v7 = retaddr;
      }
      v33 = v19;
      v34 = v19 + 1;
      m_cur[v33] = v8;
      v82 = v34;
      v35 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v36 = (_QWORD *)v35[1];
      if ( (unsigned __int64)v36 < v35[3] )
      {
        *v36 = "StnarrowPhase";
        v37 = __rdtsc();
        v38 = v36 + 2;
        *((_DWORD *)v38 - 2) = v37;
        v35[1] = v38;
      }
      v39 = 0;
      v106 = 0;
      if ( v34 > 0 )
      {
        v40 = m_cur;
        v86 = m_cur;
        while ( 1 )
        {
          v84 = *v40;
          v85 = (unsigned int)*v40 >> 22;
          v41 = (__int64)v7[v85].m_instancePtr;
          v42 = hkaiNavMeshInstance_getWithData_hkaiNavMesh::Face_int_(
                  *(hkaiNavMesh::Face **)(v41 + 16),
                  *(_DWORD *)(v41 + 24),
                  (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v41 + 240),
                  (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v41 + 272),
                  *(const int **)(v41 + 64),
                  (hkArray<int,hkContainerHeapAllocator> *)(v41 + 352),
                  (hkArray<int,hkContainerHeapAllocator> *)(v41 + 384),
                  (hkArray<int,hkContainerHeapAllocator> *)(v41 + 224),
                  *v40 & 0x3FFFFF,
                  *(_DWORD *)(v41 + 72),
                  (const int **)&dataPtrOut);
          index = v42->m_startEdgeIndex;
          if ( index < index + v42->m_numEdges )
            break;
LABEL_53:
          v7 = retaddr;
          ++v39;
          v40 = v86 + 1;
          v106 = v39;
          ++v86;
          if ( v39 >= v34 )
            goto LABEL_54;
        }
        ownedData = (hkArray<int,hkContainerHeapAllocator> *)(v41 + 400);
        v45 = (hkArray<int,hkContainerHeapAllocator> *)(v41 + 368);
        v46 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v41 + 256);
        while ( 1 )
        {
          v47 = hkaiNavMeshInstance_getWithData_hkaiNavMesh::Edge_int_(
                  *(hkaiNavMesh::Edge **)(v41 + 32),
                  *(_DWORD *)(v41 + 40),
                  v46,
                  (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v41 + 288),
                  *(const int **)(v41 + 80),
                  v45,
                  ownedData,
                  (hkArray<int,hkContainerHeapAllocator> *)(v41 + 208),
                  index,
                  *(_DWORD *)(v41 + 88),
                  (const int **)&v87);
          v48 = 1;
          if ( v47->m_oppositeEdge == -1 )
            goto LABEL_64;
          if ( (v47->m_flags.m_storage & 0x20) == 0 && traversalInfo )
          {
            m_a = v47->m_a;
            v50 = *(_DWORD *)(v41 + 56);
            v93 = -1;
            v94 = 0i64;
            v97 = -1;
            v98 = 0i64;
            v101 = -1;
            v102 = 0i64;
            if ( (int)m_a >= v50 )
              v51 = (__m128 *)(*(_QWORD *)(v41 + 304) + 16i64 * ((int)m_a - v50));
            else
              v51 = (__m128 *)(*(_QWORD *)(v41 + 48) + 16 * m_a);
            v52 = *v51;
            v53 = *(__m128 *)(v41 + 128);
            v54 = *(__m128 *)(v41 + 112);
            m_b = v47->m_b;
            v56 = *(__m128 *)(v41 + 144);
            v57 = *(__m128 *)(v41 + 160);
            v58 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v52, v52, 0), v54),
                        _mm_mul_ps(_mm_shuffle_ps(v52, v52, 85), v53)),
                      _mm_mul_ps(_mm_shuffle_ps(v52, v52, 170), v56)),
                    v57);
            if ( (int)m_b >= v50 )
              v59 = (__m128 *)(*(_QWORD *)(v41 + 304) + 16i64 * ((int)m_b - v50));
            else
              v59 = (__m128 *)(*(_QWORD *)(v41 + 48) + 16 * m_b);
            v60 = *v59;
            v93 = -1;
            v97 = index | (v85 << 22);
            v98 = v47;
            v99 = v87;
            v94 = 0i64;
            v95 = 0i64;
            v102 = v42;
            v91[0] = v41;
            v96 = modifier->hkReferencedObject;
            v92 = 4;
            v101 = v84;
            v103 = dataPtrOut;
            v100 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(v60, v60, 0), v54),
                               _mm_mul_ps(_mm_shuffle_ps(v60, v60, 85), v53)),
                             _mm_mul_ps(_mm_shuffle_ps(v60, v60, 170), v56)),
                           v57),
                         v58),
                       (__m128)xmmword_141A711B0),
                     v58);
            v91[1] = (__int64)aabb;
            v91[2] = (__int64)&v93;
            v48 = (*(unsigned __int8 (__fastcall **)(hkaiAgentTraversalInfo *, __int64 *))(*(_QWORD *)traversalInfo
                                                                                         + 40i64))(
                    traversalInfo,
                    v91);
          }
          if ( v47->m_oppositeEdge == -1 || (v47->m_flags.m_storage & 0x20) != 0 || !v48 )
          {
LABEL_64:
            v61 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
                    *(hkaiNavMesh::Edge **)(v41 + 32),
                    *(_DWORD *)(v41 + 40),
                    (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v41 + 256),
                    (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v41 + 288),
                    (hkArray<int,hkContainerHeapAllocator> *)(v41 + 208),
                    index);
            v62 = *(_DWORD *)(v41 + 56);
            v63 = v61->m_a;
            v64 = (__m128 *)((int)v63 >= v62
                           ? *(_QWORD *)(v41 + 304) + 16i64 * ((int)v63 - v62)
                           : *(_QWORD *)(v41 + 48) + 16 * v63);
            v65 = *(__m128 *)(v41 + 128);
            v66 = *(__m128 *)(v41 + 112);
            v67 = v61->m_b;
            v68 = *(__m128 *)(v41 + 144);
            v69 = *(__m128 *)(v41 + 160);
            v70 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(*v64, *v64, 0), v66),
                        _mm_mul_ps(_mm_shuffle_ps(*v64, *v64, 85), v65)),
                      _mm_mul_ps(_mm_shuffle_ps(*v64, *v64, 170), v68)),
                    v69);
            v71 = (__m128 *)((int)v67 >= v62
                           ? *(_QWORD *)(v41 + 304) + 16i64 * ((int)v67 - v62)
                           : *(_QWORD *)(v41 + 48) + 16 * v67);
            v72 = *v71;
            startInOut.m_quad = v70;
            endInOut.m_quad = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v72, v72, 0), v66),
                                    _mm_mul_ps(_mm_shuffle_ps(v72, v72, 85), v65)),
                                  _mm_mul_ps(_mm_shuffle_ps(v72, v72, 170), v68)),
                                v69);
            if ( hkaiAvoidanceSolverUtils::clipSegmentInsideAabb(aabba, &startInOut, &endInOut) )
            {
              *(hkVector4f *)(position->m_quad.m128_u64[0] + 16i64 * position->m_quad.m128_i32[2]++) = (hkVector4f)startInOut.m_quad;
              *(hkVector4f *)(position->m_quad.m128_u64[0] + 16i64 * position->m_quad.m128_i32[2]) = (hkVector4f)endInOut.m_quad;
              v73 = position->m_quad.m128_i32[3];
              if ( ++position->m_quad.m128_i32[2] == (v73 & 0x3FFFFFFF) )
                break;
            }
          }
          ++index;
          v46 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v41 + 256);
          ownedData = (hkArray<int,hkContainerHeapAllocator> *)(v41 + 400);
          v45 = (hkArray<int,hkContainerHeapAllocator> *)(v41 + 368);
          if ( index >= v42->m_startEdgeIndex + v42->m_numEdges )
          {
            v34 = v82;
            v39 = v106;
            goto LABEL_53;
          }
        }
LABEL_54:
        m_cur = v86;
      }
      v74 = (4 * v83 + 127) & 0xFFFFFF80;
      v75 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v76 = (v74 + 15) & 0xFFFFFFF0;
      if ( v74 > v75->m_slabSize || (char *)m_cur + v76 != v75->m_cur || v75->m_firstNonLifoEnd == m_cur )
        hkLifoAllocator::slowBlockFree(v75, m_cur, v76);
      else
        v75->m_cur = m_cur;
    }
  }
  v77 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v78 = (_QWORD *)v77[1];
  v79 = v77;
  if ( (unsigned __int64)v78 < v77[3] )
  {
    *v78 = "lt";
    v80 = __rdtsc();
    v81 = v78 + 2;
    *((_DWORD *)v81 - 2) = v80;
    v79[1] = v81;
  }
}

// File Line: 2577
// RVA: 0xBC4D20
void __fastcall hkaiNavMeshUtils::ClosestBoundaryInput::ClosestBoundaryInput(
        hkaiNavMeshUtils::ClosestBoundaryInput *this)
{
  this->m_startFaceKey = -1;
  this->m_testRadius.m_real = _mm_shuffle_ps(
                                (__m128)LODWORD(FLOAT_1_8446726e19),
                                (__m128)LODWORD(FLOAT_1_8446726e19),
                                0);
  this->m_traversalInfo = 0i64;
  this->m_edgeFilter = 0i64;
}

// File Line: 2582
// RVA: 0xBC4D60
void __fastcall hkaiNavMeshUtils::getDistanceToClosestBoundary(
        hkaiStreamingCollection *collection,
        hkaiNavMeshUtils::ClosestBoundaryInput *input,
        hkaiNavMeshUtils::ClosestBoundaryOutput *closestBoundary)
{
  hkaiStreamingCollection *v3; // r13
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkaiAstarEdgeFilter *m_edgeFilter; // r15
  hkLifoAllocator *v12; // rax
  char *m_cur; // rcx
  char *v14; // rdx
  unsigned int m_startFaceKey; // r14d
  hkSimdFloat32 v16; // xmm10
  hkVector4f v17; // xmm6
  unsigned int *m_data; // rsi
  hkVector4f v19; // xmm10
  int v20; // edi
  int v21; // r12d
  int v22; // r8d
  int v23; // ecx
  unsigned int v24; // edx
  int m_size; // eax
  int v26; // r9d
  int v27; // ecx
  unsigned int v28; // edx
  __int64 m_instancePtr; // rbx
  int v30; // r13d
  hkaiNavMesh::Face *v31; // rax
  __int64 v32; // r11
  int striding; // ecx
  int *v34; // r8
  int v35; // r14d
  unsigned int v36; // ecx
  int index; // eax
  int v38; // r13d
  hkaiNavMesh::Edge *v39; // rax
  int v40; // edx
  __int64 v41; // r15
  __int64 m_a; // rax
  __m128 *v43; // rcx
  __m128 v44; // xmm2
  __m128 v45; // xmm3
  __int64 v46; // rax
  __m128 v47; // xmm4
  __m128 v48; // xmm5
  __m128 v49; // xmm7
  __m128 *v50; // rax
  __m128 v51; // xmm8
  __m128 v52; // xmm5
  __m128 v53; // xmm4
  __m128 v54; // xmm1
  __m128 v55; // xmm3
  __m128 v56; // xmm1
  __m128 v57; // xmm2
  __m128 v58; // xmm1
  __m128 v59; // xmm3
  __m128 v60; // xmm2
  __m128 v61; // xmm5
  __m128 v62; // xmm5
  __m128 v63; // xmm9
  hkaiAstarEdgeFilter *v64; // r11
  int v65; // eax
  __m128 v66; // xmm8
  int *v67; // rax
  hkBaseObjectVtbl *vfptr; // rax
  char v69; // al
  int v70; // ecx
  unsigned int v71; // eax
  unsigned int v72; // r8d
  int v73; // r9d
  int v74; // ecx
  unsigned int v75; // edx
  int v76; // eax
  unsigned __int64 *v77; // rdx
  char v78; // r13
  __m128 v79; // xmm0
  unsigned int v80; // ecx
  int v81; // r14d
  hkaiNavMeshInstance *v82; // rbx
  int m_numOriginalEdges; // r12d
  hkaiNavMesh::Edge *v84; // rax
  hkaiNavMesh::Edge *v85; // r11
  __int64 v86; // rcx
  int m_numOriginalVertices; // edx
  __m128 *p_m_quad; // rcx
  __m128 v89; // xmm3
  __m128 v90; // xmm4
  __int64 m_b; // rax
  __m128 v92; // xmm5
  __m128 v93; // xmm7
  __m128 v94; // xmm2
  __m128 *v95; // rax
  int *v96; // rax
  char m_storage; // cl
  unsigned int m_oppositeFace; // edx
  char v99; // cl
  unsigned int v100; // eax
  bool v101; // zf
  unsigned int m_oppositeEdge; // edx
  unsigned int v103; // eax
  int m_capacityAndFlags; // r8d
  char *v105; // rsi
  signed int v106; // ebx
  hkLifoAllocator *v107; // rax
  int v108; // r8d
  _QWORD *v109; // rax
  _QWORD *v110; // rcx
  _QWORD *v111; // r8
  unsigned __int64 v112; // rax
  _QWORD *v113; // rcx
  int v114; // [rsp+40h] [rbp-B8h]
  _DWORD *array; // [rsp+48h] [rbp-B0h] BYREF
  int v116; // [rsp+50h] [rbp-A8h]
  int v117; // [rsp+54h] [rbp-A4h]
  void *p; // [rsp+58h] [rbp-A0h]
  int v119; // [rsp+60h] [rbp-98h]
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > v120; // [rsp+68h] [rbp-90h] BYREF
  hkaiNavMesh::Edge *v121; // [rsp+80h] [rbp-78h]
  hkaiAstarEdgeFilter *v122; // [rsp+88h] [rbp-70h]
  hkaiNavMesh::Face *v123; // [rsp+90h] [rbp-68h]
  int *v124; // [rsp+98h] [rbp-60h]
  unsigned __int64 v125; // [rsp+A0h] [rbp-58h]
  hkResult result; // [rsp+A8h] [rbp-50h] BYREF
  __int64 v127[3]; // [rsp+B0h] [rbp-48h] BYREF
  char v128; // [rsp+C8h] [rbp-30h]
  int v129; // [rsp+D8h] [rbp-20h] BYREF
  __int64 v130; // [rsp+E0h] [rbp-18h]
  int *v131; // [rsp+E8h] [rbp-10h]
  __m128 m_quad; // [rsp+F8h] [rbp+0h]
  int v133; // [rsp+108h] [rbp+10h]
  __int64 v134; // [rsp+110h] [rbp+18h]
  int *v135; // [rsp+118h] [rbp+20h]
  __m128 v136; // [rsp+128h] [rbp+30h]
  unsigned int v137; // [rsp+138h] [rbp+40h]
  hkaiNavMesh::Face *v138; // [rsp+140h] [rbp+48h]
  int *v139; // [rsp+148h] [rbp+50h]
  hkaiStreamingCollection *retaddr; // [rsp+1F8h] [rbp+100h]
  unsigned int v143; // [rsp+210h] [rbp+118h]
  unsigned int v144; // [rsp+210h] [rbp+118h]

  v3 = collection;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtgetDistanceToNearestBoundary";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  closestBoundary->m_edgeKey = -1;
  if ( input->m_startFaceKey != -1 )
  {
    m_edgeFilter = input->m_edgeFilter;
    v117 = 0x80000000;
    v119 = 64;
    v122 = m_edgeFilter;
    array = 0i64;
    v116 = 0;
    v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)v12->m_cur;
    v14 = m_cur + 512;
    if ( v12->m_slabSize < 512 || v14 > v12->m_end )
      m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(v12, 512);
    else
      v12->m_cur = v14;
    m_startFaceKey = input->m_startFaceKey;
    v16.m_real = (__m128)input->m_testRadius;
    v17.m_quad = (__m128)input->m_startPosition;
    m_data = 0i64;
    v120.m_elem.m_data = 0i64;
    v120.m_elem.m_size = 0;
    v19.m_quad = _mm_mul_ps(v16.m_real, v16.m_real);
    v121 = 0i64;
    v124 = 0i64;
    v20 = v116;
    v120.m_numElems = m_startFaceKey;
    array = m_cur;
    v117 = -2147483584;
    p = m_cur;
    v120.m_elem.m_capacityAndFlags = 0x80000000;
    v21 = -1;
    *(&v120.m_numElems + 1) = -1;
    do
    {
LABEL_10:
      v22 = v120.m_elem.m_size - 1;
      if ( v120.m_elem.m_size - 1 <= 0
        || (v23 = v22 & (-1640531535 * (m_startFaceKey >> 4)), v24 = m_data[v23], v24 == -1) )
      {
LABEL_14:
        m_size = v120.m_elem.m_size;
      }
      else
      {
        while ( v24 != m_startFaceKey )
        {
          v23 = v22 & (v23 + 1);
          v24 = m_data[v23];
          if ( v24 == -1 )
            goto LABEL_14;
        }
        m_size = v23;
      }
      if ( m_size > v22 )
      {
        v143 = m_startFaceKey >> 22;
        if ( 2 * v120.m_numElems > v22 )
        {
          hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
            &v120,
            &result,
            2 * v22 + 2);
          m_data = v120.m_elem.m_data;
        }
        v26 = 1;
        v27 = (v120.m_elem.m_size - 1) & (-1640531535 * (m_startFaceKey >> 4));
        v28 = m_data[v27];
        if ( v28 != -1 )
        {
          while ( v28 != m_startFaceKey )
          {
            v27 = (v120.m_elem.m_size - 1) & (v27 + 1);
            v28 = m_data[v27];
            if ( v28 == -1 )
              goto LABEL_24;
          }
          v26 = 0;
        }
LABEL_24:
        v120.m_numElems += v26;
        m_data[v27] = m_startFaceKey;
        m_instancePtr = (__int64)v3->m_instances.m_data[m_startFaceKey >> 22].m_instancePtr;
        v30 = *(_DWORD *)(m_instancePtr + 24);
        v31 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
                *(hkaiNavMesh::Face **)(m_instancePtr + 16),
                v30,
                (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(m_instancePtr + 240),
                (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(m_instancePtr + 272),
                (hkArray<int,hkContainerHeapAllocator> *)(m_instancePtr + 224),
                m_startFaceKey & 0x3FFFFF);
        striding = *(_DWORD *)(m_instancePtr + 72);
        v123 = v31;
        if ( striding )
        {
          v34 = hkaiNavMeshInstance_getWithStriding_int__1(
                  *(const int **)(m_instancePtr + 64),
                  v30,
                  (hkArray<int,hkContainerHeapAllocator> *)(m_instancePtr + 352),
                  (hkArray<int,hkContainerHeapAllocator> *)(m_instancePtr + 384),
                  (hkArray<int,hkContainerHeapAllocator> *)(m_instancePtr + 224),
                  m_startFaceKey & 0x3FFFFF,
                  striding);
          v31 = v123;
        }
        else
        {
          v34 = 0i64;
        }
        v130 = 0i64;
        v134 = 0i64;
        v138 = 0i64;
        v129 = -1;
        v133 = -1;
        v137 = -1;
        if ( m_edgeFilter )
        {
          v137 = m_startFaceKey;
          v138 = v31;
          m_quad = v17.m_quad;
          v129 = *(&v120.m_numElems + 1);
          v139 = v34;
          v131 = v124;
          v130 = v32;
        }
        v20 = v116;
        m_data = v120.m_elem.m_data;
        if ( v31->m_numEdges > 0 )
        {
          v35 = 0;
          v36 = v143 << 22;
          v144 = v143 << 22;
          do
          {
            index = v35 + v31->m_startEdgeIndex;
            v38 = index | v36;
            v114 = index;
            if ( (index | v36) != v21 )
            {
              v39 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
                      *(hkaiNavMesh::Edge **)(m_instancePtr + 32),
                      *(_DWORD *)(m_instancePtr + 40),
                      (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(m_instancePtr + 256),
                      (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(m_instancePtr + 288),
                      (hkArray<int,hkContainerHeapAllocator> *)(m_instancePtr + 208),
                      index);
              v40 = *(_DWORD *)(m_instancePtr + 56);
              v41 = (__int64)v39;
              m_a = v39->m_a;
              if ( (int)m_a >= v40 )
                v43 = (__m128 *)(*(_QWORD *)(m_instancePtr + 304) + 16i64 * ((int)m_a - v40));
              else
                v43 = (__m128 *)(*(_QWORD *)(m_instancePtr + 48) + 16 * m_a);
              v44 = *(__m128 *)(m_instancePtr + 128);
              v45 = *(__m128 *)(m_instancePtr + 112);
              v46 = *(int *)(v41 + 4);
              v47 = *(__m128 *)(m_instancePtr + 144);
              v48 = *(__m128 *)(m_instancePtr + 160);
              v49 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(*v43, *v43, 0), v45),
                          _mm_mul_ps(_mm_shuffle_ps(*v43, *v43, 85), v44)),
                        _mm_mul_ps(_mm_shuffle_ps(*v43, *v43, 170), v47)),
                      v48);
              if ( (int)v46 >= v40 )
                v50 = (__m128 *)(*(_QWORD *)(m_instancePtr + 304) + 16i64 * ((int)v46 - v40));
              else
                v50 = (__m128 *)(*(_QWORD *)(m_instancePtr + 48) + 16 * v46);
              v51 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(*v50, *v50, 0), v45),
                          _mm_mul_ps(_mm_shuffle_ps(*v50, *v50, 85), v44)),
                        _mm_mul_ps(_mm_shuffle_ps(*v50, *v50, 170), v47)),
                      v48);
              v52 = _mm_sub_ps(v49, *(__m128 *)&collection->m_isTemporary.m_bool);
              v53 = _mm_sub_ps(v49, v51);
              v54 = _mm_mul_ps(v53, v53);
              v55 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), _mm_shuffle_ps(v54, v54, 0)),
                      _mm_shuffle_ps(v54, v54, 170));
              v56 = _mm_mul_ps(v52, v53);
              v57 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
                      _mm_shuffle_ps(v56, v56, 170));
              v58 = _mm_rcp_ps(v55);
              v59 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v58, v55)), v58), v57);
              v60 = _mm_cmplt_ps(v59, query.m_quad);
              v61 = _mm_sub_ps(
                      v52,
                      _mm_mul_ps(
                        _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v60, v59), _mm_andnot_ps(v60, query.m_quad))),
                        v53));
              v62 = _mm_mul_ps(v61, v61);
              v63 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v62, v62, 85), _mm_shuffle_ps(v62, v62, 0)),
                      _mm_shuffle_ps(v62, v62, 170));
              if ( v63.m128_f32[0] < v19.m_quad.m128_f32[0] )
              {
                if ( *(_DWORD *)(v41 + 8) == -1 || (*(_BYTE *)(v41 + 16) & 0x20) != 0 )
                  goto LABEL_63;
                v64 = v122;
                if ( !v122 )
                  goto LABEL_46;
                v65 = *(_DWORD *)(m_instancePtr + 88);
                v66 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v51, v49), (__m128)xmmword_141A711B0), v49);
                v67 = v65
                    ? hkaiNavMeshInstance_getWithStriding_int__1(
                        *(const int **)(m_instancePtr + 80),
                        *(_DWORD *)(m_instancePtr + 40),
                        (hkArray<int,hkContainerHeapAllocator> *)(m_instancePtr + 368),
                        (hkArray<int,hkContainerHeapAllocator> *)(m_instancePtr + 400),
                        (hkArray<int,hkContainerHeapAllocator> *)(m_instancePtr + 208),
                        v114,
                        v65)
                    : 0i64;
                v135 = v67;
                v136 = v66;
                v133 = v38;
                v127[1] = (__int64)&collection[1];
                v134 = v41;
                v127[2] = (__int64)&v129;
                vfptr = v64->vfptr;
                v127[0] = m_instancePtr;
                v128 = 4;
                v69 = ((__int64 (__fastcall *)(hkaiAstarEdgeFilter *, __int64 *))vfptr[2].__first_virtual_table_function__)(
                        v64,
                        v127);
                v20 = v116;
                m_data = v120.m_elem.m_data;
                if ( !v69 )
                {
LABEL_63:
                  v19.m_quad = v63;
                  input->m_startFaceKey = v38;
                }
                else
                {
LABEL_46:
                  v70 = *(_DWORD *)(v41 + 12);
                  if ( (*(_BYTE *)(v41 + 16) & 0x40) != 0 )
                    v71 = v70 & 0xFFC00000;
                  else
                    v71 = *(_DWORD *)(m_instancePtr + 472) << 22;
                  v72 = v71 | v70 & 0x3FFFFF;
                  if ( v70 == -1 )
                    v72 = -1;
                  v73 = v120.m_elem.m_size - 1;
                  if ( v120.m_elem.m_size - 1 <= 0
                    || (v74 = v73 & (-1640531535 * (v72 >> 4)), v75 = m_data[v74], v75 == -1) )
                  {
LABEL_55:
                    v76 = v120.m_elem.m_size;
                  }
                  else
                  {
                    while ( v75 != v72 )
                    {
                      v74 = v73 & (v74 + 1);
                      v75 = m_data[v74];
                      if ( v75 == -1 )
                        goto LABEL_55;
                    }
                    v76 = v74;
                  }
                  if ( v76 > v73 )
                  {
                    v125 = __PAIR64__(v63.m128_u32[0], v38);
                    if ( v20 == (v117 & 0x3FFFFFFF) )
                    {
                      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 8);
                      v20 = v116;
                      m_data = v120.m_elem.m_data;
                    }
                    v77 = (unsigned __int64 *)&array[2 * v20];
                    if ( v77 )
                    {
                      *v77 = v125;
                      v20 = v116;
                      m_data = v120.m_elem.m_data;
                    }
                    v116 = ++v20;
                  }
                }
              }
              v36 = v144;
            }
            ++v35;
            v31 = v123;
          }
          while ( v35 < v123->m_numEdges );
          m_startFaceKey = v120.m_numElems;
        }
      }
      v78 = 0;
      if ( !v20 )
        break;
      do
      {
        if ( v78 )
        {
          m_edgeFilter = v122;
          v3 = retaddr;
          goto LABEL_10;
        }
        v79 = (__m128)(unsigned int)array[2 * --v20 + 1];
        v80 = array[2 * v20];
        v116 = v20;
        *(&v120.m_numElems + 1) = v80;
        if ( _mm_shuffle_ps(v79, v79, 0).m128_f32[0] < v19.m_quad.m128_f32[0] )
        {
          v78 = 1;
          v81 = v80 & 0x3FFFFF;
          v82 = retaddr->m_instances.m_data[v80 >> 22].m_instancePtr;
          m_numOriginalEdges = v82->m_numOriginalEdges;
          v84 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
                  v82->m_originalEdges,
                  m_numOriginalEdges,
                  &v82->m_instancedEdges,
                  &v82->m_ownedEdges,
                  &v82->m_edgeMap,
                  v80 & 0x3FFFFF);
          v85 = v84;
          v121 = v84;
          if ( v122 )
          {
            v86 = v84->m_a;
            m_numOriginalVertices = v82->m_numOriginalVertices;
            if ( (int)v86 >= m_numOriginalVertices )
              p_m_quad = &v82->m_ownedVertices.m_data[(int)v86 - m_numOriginalVertices].m_quad;
            else
              p_m_quad = &v82->m_originalVertices[v86].m_quad;
            v89 = v82->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
            v90 = v82->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
            m_b = v84->m_b;
            v92 = v82->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
            v93 = v82->m_referenceFrame.m_transform.m_translation.m_quad;
            v94 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(*p_m_quad, *p_m_quad, 0), v90),
                        _mm_mul_ps(_mm_shuffle_ps(*p_m_quad, *p_m_quad, 85), v89)),
                      _mm_mul_ps(_mm_shuffle_ps(*p_m_quad, *p_m_quad, 170), v92)),
                    v93);
            if ( (int)m_b >= m_numOriginalVertices )
              v95 = &v82->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices].m_quad;
            else
              v95 = &v82->m_originalVertices[m_b].m_quad;
            v17.m_quad = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_sub_ps(
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(_mm_shuffle_ps(*v95, *v95, 0), v90),
                                     _mm_mul_ps(_mm_shuffle_ps(*v95, *v95, 85), v89)),
                                   _mm_mul_ps(_mm_shuffle_ps(*v95, *v95, 170), v92)),
                                 v93),
                               v94),
                             (__m128)xmmword_141A711B0),
                           v94);
          }
          if ( v82->m_edgeDataStriding )
            v96 = hkaiNavMeshInstance_getWithStriding_int__1(
                    v82->m_originalEdgeData,
                    m_numOriginalEdges,
                    &v82->m_instancedEdgeData,
                    &v82->m_ownedEdgeData,
                    &v82->m_edgeMap,
                    v81,
                    v82->m_edgeDataStriding);
          else
            v96 = 0i64;
          m_storage = v85->m_flags.m_storage;
          m_oppositeFace = v85->m_oppositeFace;
          v124 = v96;
          v99 = m_storage & 0x40;
          if ( v99 )
            v100 = m_oppositeFace & 0xFFC00000;
          else
            v100 = v82->m_runtimeId << 22;
          m_startFaceKey = v100 | m_oppositeFace & 0x3FFFFF;
          v101 = m_oppositeFace == -1;
          m_oppositeEdge = v85->m_oppositeEdge;
          if ( v101 )
            m_startFaceKey = -1;
          v120.m_numElems = m_startFaceKey;
          if ( v99 )
            v103 = m_oppositeEdge & 0xFFC00000;
          else
            v103 = v82->m_runtimeId << 22;
          v21 = v103 | m_oppositeEdge & 0x3FFFFF;
          if ( m_oppositeEdge == -1 )
            v21 = -1;
        }
      }
      while ( v20 );
      m_edgeFilter = v122;
      v101 = v78 == 0;
      v3 = retaddr;
    }
    while ( !v101 );
    m_capacityAndFlags = v120.m_elem.m_capacityAndFlags;
    v120.m_elem.m_size = 0;
    input->m_startPosition = (hkVector4f)v19.m_quad;
    if ( m_capacityAndFlags >= 0 )
    {
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        m_data,
        4 * m_capacityAndFlags);
      v20 = v116;
    }
    v105 = (char *)p;
    v120.m_elem.m_data = 0i64;
    if ( p == array )
      v20 = 0;
    v120.m_elem.m_capacityAndFlags = 0x80000000;
    v106 = (8 * v119 + 127) & 0xFFFFFF80;
    v116 = v20;
    v107 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v108 = (v106 + 15) & 0xFFFFFFF0;
    if ( v106 > v107->m_slabSize || &v105[v108] != v107->m_cur || v107->m_firstNonLifoEnd == v105 )
      hkLifoAllocator::slowBlockFree(v107, v105, v108);
    else
      v107->m_cur = v105;
    v116 = 0;
    if ( v117 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v117);
    array = 0i64;
    v117 = 0x80000000;
  }
  v109 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v110 = (_QWORD *)v109[1];
  v111 = v109;
  if ( (unsigned __int64)v110 < v109[3] )
  {
    *v110 = "Et";
    v112 = __rdtsc();
    v113 = v110 + 2;
    *((_DWORD *)v113 - 2) = v112;
    v111[1] = v113;
  }
}

// File Line: 2736
// RVA: 0xBC65C0
__int64 __fastcall hkaiNavMeshUtils::triangleAabbCheck(
        hkAabb *aabb,
        hkVector4f *triA,
        hkVector4f *triB,
        hkVector4f *triC)
{
  __m128 m_quad; // xmm3
  __m128 v5; // xmm4
  __m128 v6; // xmm5
  hkVector4f v7; // xmm6
  hkVector4f v8; // xmm9
  hkVector4f *v10; // rdx
  unsigned int v11; // r8d
  __m128 v12; // xmm14
  __m128 v13; // xmm15
  __m128 v14; // xmm1
  __m128 v15; // xmm10
  __m128 v16; // xmm9
  __m128 v17; // xmm11
  __m128 v18; // xmm12
  __m128 v19; // xmm7
  __int64 v20; // rax
  __m128 *v21; // rcx
  __m128 v22; // xmm8
  __m128 v23; // xmm6
  __m128i v24; // xmm3
  __m128 v25; // xmm6
  __m128 v26; // xmm0
  __m128 v27; // xmm5
  __m128 v28; // xmm3
  __m128 v29; // xmm1
  __m128 v30; // xmm6
  __m128 v31; // xmm2
  __m128 v32; // xmm5
  __m128 v33; // xmm5
  __m128 v34; // xmm5
  __m128 v35; // xmm1
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm5
  __m128 v39; // xmm2
  __m128 v40; // xmm2
  __m128 v41; // xmm2
  __int128 v42[3]; // [rsp+0h] [rbp-D8h] BYREF

  m_quad = triA->m_quad;
  v5 = triB->m_quad;
  v6 = triC->m_quad;
  v7.m_quad = (__m128)aabb->m_min;
  v8.m_quad = (__m128)aabb->m_max;
  if ( (_mm_movemask_ps(
          _mm_and_ps(
            _mm_cmple_ps(aabb->m_min.m_quad, _mm_max_ps(_mm_max_ps(triA->m_quad, triB->m_quad), triC->m_quad)),
            _mm_cmple_ps(_mm_min_ps(_mm_min_ps(triA->m_quad, triB->m_quad), triC->m_quad), v8.m_quad))) & 7) != 7 )
    return 0i64;
  v10 = &transform;
  v11 = 0;
  v12 = _mm_sub_ps(v5, m_quad);
  v13 = _mm_sub_ps(v6, v5);
  v42[0] = (__int128)v12;
  v14 = _mm_mul_ps(_mm_add_ps(v7.m_quad, v8.m_quad), (__m128)xmmword_141A711B0);
  v42[1] = (__int128)v13;
  v15 = _mm_sub_ps(m_quad, v14);
  v16 = _mm_mul_ps(_mm_sub_ps(v8.m_quad, v7.m_quad), (__m128)xmmword_141A711B0);
  v42[2] = (__int128)_mm_sub_ps(m_quad, v6);
  v17 = _mm_sub_ps(v5, v14);
  v18 = _mm_sub_ps(v6, v14);
  while ( 2 )
  {
    v19 = v10->m_quad;
    v20 = 0i64;
    v21 = (__m128 *)v42;
    v22 = _mm_shuffle_ps(v19, v19, 201);
    do
    {
      v23 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(*v21, *v21, 201), v19), _mm_mul_ps(v22, *v21));
      v24 = (__m128i)_mm_shuffle_ps(v23, v23, 201);
      v25 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v24, 1u), 1u);
      v26 = _mm_mul_ps((__m128)v24, v17);
      v27 = _mm_mul_ps((__m128)v24, v15);
      v28 = _mm_mul_ps((__m128)v24, v18);
      v29 = _mm_unpacklo_ps(v27, v26);
      v30 = _mm_mul_ps(v25, v16);
      v31 = _mm_movelh_ps(v29, v28);
      v32 = _mm_add_ps(
              _mm_shuffle_ps(_mm_unpackhi_ps(v27, v26), v28, 228),
              _mm_add_ps(v31, _mm_shuffle_ps(_mm_movehl_ps(v31, v29), v28, 212)));
      v28.m128_i32[0] = _mm_shuffle_ps(v32, v32, 85).m128_u32[0];
      v31.m128_i32[0] = _mm_shuffle_ps(v32, v32, 0).m128_u32[0];
      v29.m128_i32[0] = _mm_shuffle_ps(v32, v32, 170).m128_u32[0];
      if ( fmax(
             0.0 - fmax(v29.m128_f32[0], fmax(v28.m128_f32[0], v31.m128_f32[0])),
             fmin(v29.m128_f32[0], fmin(v28.m128_f32[0], v31.m128_f32[0]))) > (float)((float)(_mm_shuffle_ps(
                                                                                                v30,
                                                                                                v30,
                                                                                                85).m128_f32[0]
                                                                                            + _mm_shuffle_ps(
                                                                                                v30,
                                                                                                v30,
                                                                                                0).m128_f32[0])
                                                                                    + _mm_shuffle_ps(v30, v30, 170).m128_f32[0]) )
        return 0i64;
      ++v20;
      ++v21;
    }
    while ( v20 < 3 );
    if ( (__int64)++v10 < (__int64)&qi )
      continue;
    break;
  }
  v33 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v12), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v13));
  v34 = _mm_shuffle_ps(v33, v33, 201);
  v35 = _mm_mul_ps(v34, v34);
  v36 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)), _mm_shuffle_ps(v35, v35, 170));
  v37 = _mm_rsqrt_ps(v36);
  v38 = _mm_mul_ps(
          v34,
          _mm_andnot_ps(
            _mm_cmple_ps(v36, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v37, v36), v37)),
              _mm_mul_ps(*(__m128 *)_xmm, v37))));
  v39 = _mm_mul_ps(v38, v15);
  v40 = (__m128)_mm_srli_epi32(
                  _mm_slli_epi32(
                    (__m128i)_mm_shuffle_ps(
                               v38,
                               _mm_unpackhi_ps(
                                 v38,
                                 _mm_sub_ps(
                                   (__m128)0i64,
                                   _mm_add_ps(
                                     _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                                     _mm_shuffle_ps(v39, v39, 170)))),
                               196),
                    1u),
                  1u);
  v38.m128_f32[0] = _mm_shuffle_ps(v40, v40, 255).m128_f32[0];
  v41 = _mm_mul_ps(v40, v16);
  if ( v38.m128_f32[0] <= (float)((float)(_mm_shuffle_ps(v41, v41, 85).m128_f32[0]
                                        + _mm_shuffle_ps(v41, v41, 0).m128_f32[0])
                                + _mm_shuffle_ps(v41, v41, 170).m128_f32[0]) )
    return 1;
  return v11;
}

// File Line: 2816
// RVA: 0xBC68E0
__int64 __fastcall hkaiNavMeshUtils::faceAabbCheck(hkAabb *aabb, hkArrayBase<hkVector4f> *vertices)
{
  int m_size; // edi
  int v3; // ebx
  hkVector4f *m_data; // rsi

  m_size = vertices->m_size;
  v3 = 2;
  if ( m_size <= 2 )
    return 0i64;
  m_data = vertices->m_data;
  while ( !(unsigned int)hkaiNavMeshUtils::triangleAabbCheck(aabb, m_data, &m_data[v3 - 1], &m_data[v3]) )
  {
    if ( ++v3 >= m_size )
      return 0i64;
  }
  return 1i64;
}

// File Line: 2829
// RVA: 0xBC6960
__int64 __fastcall hkaiNavMeshUtils::faceAabbCheck(hkAabb *aabb, hkaiNavMesh *mesh, int faceIndex)
{
  hkAabb *v3; // r10
  hkaiNavMesh::Face *v4; // rdi
  __int16 m_numUserEdges; // r15
  int m_startEdgeIndex; // ebx
  hkaiNavMesh::Edge *m_data; // r13
  hkVector4f *v8; // r12
  int m_numEdges; // r14d
  int v10; // ebp
  int m_startUserEdgeIndex; // esi
  __int64 m_b; // rax
  hkVector4f triC; // [rsp+20h] [rbp-58h] BYREF
  hkVector4f triB; // [rsp+30h] [rbp-48h] BYREF
  hkVector4f triA; // [rsp+40h] [rbp-38h] BYREF

  v3 = aabb;
  v4 = &mesh->m_faces.m_data[faceIndex];
  m_numUserEdges = v4->m_numUserEdges;
  if ( m_numUserEdges <= 0 )
    m_startEdgeIndex = v4->m_startEdgeIndex;
  else
    m_startEdgeIndex = v4->m_startUserEdgeIndex;
  m_data = mesh->m_edges.m_data;
  v8 = mesh->m_vertices.m_data;
  m_numEdges = v4->m_numEdges;
  v10 = 2;
  triA.m_quad = (__m128)v8[m_data[m_startEdgeIndex].m_a];
  if ( m_numEdges <= 2 )
    return 0i64;
  m_startUserEdgeIndex = v4->m_startUserEdgeIndex;
  while ( 1 )
  {
    if ( m_startEdgeIndex < m_startUserEdgeIndex || m_startEdgeIndex >= m_numUserEdges + m_startUserEdgeIndex - 1 )
    {
      if ( m_startEdgeIndex == m_numUserEdges + m_startUserEdgeIndex - 1 )
      {
        m_startEdgeIndex = v4->m_startEdgeIndex;
      }
      else if ( m_startEdgeIndex < v4->m_startEdgeIndex || m_startEdgeIndex >= m_numEdges + v4->m_startEdgeIndex - 1 )
      {
        m_startEdgeIndex = -1;
      }
      else
      {
        ++m_startEdgeIndex;
      }
    }
    else
    {
      ++m_startEdgeIndex;
    }
    m_b = m_data[m_startEdgeIndex].m_b;
    triB.m_quad = (__m128)v8[m_data[m_startEdgeIndex].m_a];
    triC.m_quad = (__m128)v8[m_b];
    if ( (unsigned int)hkaiNavMeshUtils::triangleAabbCheck(v3, &triA, &triB, &triC) )
      break;
    v3 = aabb;
    if ( ++v10 >= m_numEdges )
      return 0i64;
  }
  return 1i64;
}

// File Line: 2854
// RVA: 0xBC5820
void __fastcall hkaiNavMeshUtils::transform(hkTransformf *t, hkaiNavMesh *mesh, hkaiNavMeshUtils::AabbMode mode)
{
  hkVector4f v3; // xmm3
  hkVector4f v4; // xmm4
  hkVector4f v6; // xmm5
  hkVector4f v7; // xmm6
  __int64 v8; // rcx
  hkVector4f *v9; // rax
  __m128 m_quad; // xmm1
  hkVector4f v11; // xmm1
  hkSimdFloat32 extraRadius; // [rsp+20h] [rbp-48h] BYREF
  hkAabb aabb; // [rsp+30h] [rbp-38h] BYREF

  v3.m_quad = (__m128)t->m_rotation.m_col0;
  v4.m_quad = (__m128)t->m_rotation.m_col1;
  v6.m_quad = (__m128)t->m_rotation.m_col2;
  v7.m_quad = (__m128)t->m_translation;
  v8 = mesh->m_vertices.m_size - 1;
  v9 = &mesh->m_vertices.m_data[v8];
  do
  {
    m_quad = v9->m_quad;
    --v9;
    --v8;
    v9[1].m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v4.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v3.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v6.m_quad)),
                     v7.m_quad);
  }
  while ( v8 >= 0 );
  if ( mode )
  {
    v11.m_quad = (__m128)mesh->m_aabb.m_max;
    aabb.m_min = mesh->m_aabb.m_min;
    aabb.m_max = (hkVector4f)v11.m_quad;
    extraRadius.m_real = aabbOut.m_quad;
    hkAabbUtil::calcAabb(t, &aabb, &extraRadius, &mesh->m_aabb);
  }
  else
  {
    extraRadius.m_real = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_050000001), (__m128)LODWORD(FLOAT_0_050000001), 0);
    hkaiNavMeshUtils::calcMeshAabb(mesh, &extraRadius, &mesh->m_aabb);
  }
}

// File Line: 2873
// RVA: 0xBC2F40
void __fastcall hkaiNavMeshUtils::compactInstancedFaces(hkaiNavMeshInstance *instance)
{
  ;
}

// File Line: 2878
// RVA: 0xBC2F50
void __fastcall hkaiNavMeshUtils::compactInstancedEdges(hkaiNavMeshInstance *instance)
{
  __int64 m_size; // r15
  int v3; // edx
  _DWORD *v4; // rdi
  __int64 v5; // rcx
  __int64 v6; // r8
  int v7; // edi
  __int64 i; // rdx
  __int64 v9; // rcx
  int v10; // r13d
  int v11; // ebp
  int v12; // esi
  __int64 v13; // rbx
  _DWORD *v14; // [rsp+30h] [rbp-38h] BYREF
  int v15; // [rsp+38h] [rbp-30h]
  int v16; // [rsp+3Ch] [rbp-2Ch]
  hkResult v17; // [rsp+70h] [rbp+8h] BYREF

  m_size = instance->m_instancedEdges.m_size;
  v3 = 0;
  v14 = 0i64;
  v16 = 0x80000000;
  v15 = 0;
  if ( (int)m_size > 0 )
  {
    hkArrayUtil::_reserve(&v17, &hkContainerTempAllocator::s_alloc, &v14, m_size, 4);
    v3 = v15;
  }
  v4 = &v14[v3];
  v5 = (int)m_size - v3;
  if ( (int)m_size - v3 > 0 )
  {
    while ( v5 )
    {
      *v4++ = -1;
      --v5;
    }
  }
  v6 = instance->m_edgeMap.m_size;
  v15 = m_size;
  v7 = 0;
  for ( i = 0i64; i < v6; ++v7 )
  {
    v9 = instance->m_edgeMap.m_data[i];
    if ( (_DWORD)v9 != -1 )
      v14[v9] = v7;
    ++i;
  }
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0i64;
  if ( (int)m_size > 0 )
  {
    do
    {
      if ( v14[v13] == -1 )
      {
        ++v11;
      }
      else
      {
        hkaiNavMeshInstance::copyInstancedEdge(instance, v10++, v12);
        instance->m_edgeMap.m_data[v14[v13]] = v12 - v11;
      }
      ++v13;
      ++v12;
    }
    while ( v13 < m_size );
  }
  hkaiNavMeshInstance::setNumInstancedEdges(instance, m_size - v11);
  v15 = 0;
  if ( v16 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v14, 4 * v16);
}

// File Line: 2977
// RVA: 0xBC34C0
__int64 __fastcall hkaiNavMeshUtils::computeRegions(
        hkaiNavMesh *mesh,
        bool sortRegionsByArea,
        hkArrayBase<int> *regions,
        hkArray<float,hkContainerHeapAllocator> *areasOut)
{
  unsigned int v4; // ebx
  int numRegionsOut; // [rsp+30h] [rbp-18h] BYREF
  hkResult result; // [rsp+34h] [rbp-14h] BYREF

  v4 = -1;
  numRegionsOut = -1;
  hkaiComputeRegionUtils::computeRegions<hkaiNavMesh,float>(
    &result,
    mesh,
    sortRegionsByArea,
    regions,
    &numRegionsOut,
    areasOut);
  if ( result.m_enum == HK_SUCCESS )
    return (unsigned int)numRegionsOut;
  return v4;
}

// File Line: 2984
// RVA: 0xBC3510
__int64 __fastcall hkaiNavMeshUtils::computeRegions(
        hkaiNavMeshInstance *meshInstance,
        bool sortRegionsByArea,
        hkArrayBase<int> *regions,
        hkArray<float,hkContainerHeapAllocator> *areasOut)
{
  unsigned int v4; // ebx
  int numRegionsOut; // [rsp+30h] [rbp-18h] BYREF
  hkResult result; // [rsp+34h] [rbp-14h] BYREF

  v4 = -1;
  numRegionsOut = -1;
  hkaiComputeRegionUtils::computeRegions<hkaiNavMeshInstance,float>(
    &result,
    meshInstance,
    sortRegionsByArea,
    regions,
    &numRegionsOut,
    areasOut);
  if ( result.m_enum == HK_SUCCESS )
    return (unsigned int)numRegionsOut;
  return v4;
}

// File Line: 2994
// RVA: 0xBBFA30
void __fastcall hkaiNavMeshUtils::calcFacePlane(hkArrayBase<hkVector4f> *facePoints, hkVector4f *planeOut)
{
  hkVector4f *m_data; // rax
  int v3; // r8d
  __int64 v4; // rcx
  __m128 m_quad; // xmm3
  __m128 v6; // xmm6
  __m128 v7; // xmm5
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm0
  __m128 v13; // xmm2
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm5
  __m128 v21; // xmm2

  m_data = facePoints->m_data;
  v3 = facePoints->m_size - 1;
  v4 = v3;
  m_quad = m_data->m_quad;
  v6 = 0i64;
  v7 = 0i64;
  if ( v3 > 0 )
  {
    do
    {
      v8 = m_data->m_quad;
      v9 = m_data[1].m_quad;
      ++m_data;
      v10 = _mm_sub_ps(v9, m_quad);
      v6 = _mm_add_ps(v6, v8);
      v11 = _mm_sub_ps(v8, m_quad);
      v12 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v11), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v10));
      v7 = _mm_add_ps(v7, _mm_shuffle_ps(v12, v12, 201));
      --v4;
    }
    while ( v4 );
  }
  v13 = 0i64;
  v13.m128_f32[0] = (float)v3;
  v14 = _mm_shuffle_ps(v13, v13, 0);
  v15 = _mm_rcp_ps(v14);
  v16 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v14, v15)), v15);
  v17 = _mm_mul_ps(v7, v7);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  v20 = _mm_mul_ps(
          v7,
          _mm_andnot_ps(
            _mm_cmple_ps(v18, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
              _mm_mul_ps(*(__m128 *)_xmm, v19))));
  v21 = _mm_mul_ps(v20, _mm_mul_ps(v6, v16));
  planeOut->m_quad = _mm_shuffle_ps(
                       v20,
                       _mm_unpackhi_ps(
                         v20,
                         _mm_sub_ps(
                           (__m128)0i64,
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                             _mm_shuffle_ps(v21, v21, 170)))),
                       196);
}

// File Line: 3025
// RVA: 0xBC8830
void __fastcall hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(
        hkaiNavMeshUtils *this,
        hkaiNavMeshInstance *mesh,
        __m128 *faceIndex,
        hkVector4f *planeOut)
{
  hkaiNavMesh::Face *v5; // rax
  int v6; // r15d
  hkaiNavMesh::Edge *v7; // r12
  __m128 v8; // xmm7
  __m128 v9; // xmm8
  int m_startEdgeIndex; // ebp
  int m_numEdges; // r13d
  hkaiNavMesh::Edge *v12; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v13; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v14; // r9
  int v15; // edi
  __int64 m_a; // rcx
  __m128 *v17; // rax
  __m128 v18; // xmm9
  __m128 v19; // xmm10
  int v20; // esi
  __m128 v21; // xmm11
  __m128 v22; // xmm12
  __m128 i; // xmm6
  hkaiNavMesh::Edge *v24; // rax
  __int64 v25; // rcx
  __m128 *v26; // rcx
  __int64 m_b; // rax
  __m128 v28; // xmm3
  __m128 *v29; // rax
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm0
  __m128 v33; // xmm2
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  __m128 v36; // xmm0
  __m128 v37; // xmm1
  __m128 v38; // xmm3
  __m128 v39; // xmm2
  __m128 v40; // xmm8
  __m128 v41; // xmm7

  v5 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
         *(hkaiNavMesh::Face **)&this[16],
         *(_DWORD *)&this[24],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[240],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[272],
         (hkArray<int,hkContainerHeapAllocator> *)&this[224],
         (int)mesh);
  v6 = *(_DWORD *)&this[40];
  v7 = *(hkaiNavMesh::Edge **)&this[32];
  v8 = 0i64;
  v9 = 0i64;
  m_startEdgeIndex = v5->m_startEdgeIndex;
  m_numEdges = v5->m_numEdges;
  v12 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
          v7,
          v6,
          (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[256],
          (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[288],
          (hkArray<int,hkContainerHeapAllocator> *)&this[208],
          v5->m_startEdgeIndex);
  v15 = *(_DWORD *)&this[56];
  m_a = v12->m_a;
  if ( (int)m_a >= v15 )
    v17 = (__m128 *)(*(_QWORD *)&this[304] + 16i64 * ((int)m_a - v15));
  else
    v17 = (__m128 *)(*(_QWORD *)&this[48] + 16 * m_a);
  v18 = *(__m128 *)&this[128];
  v19 = *(__m128 *)&this[112];
  v20 = 0;
  v21 = *(__m128 *)&this[144];
  v22 = *(__m128 *)&this[160];
  for ( i = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 0), v19),
                  _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 85), v18)),
                _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 170), v21)),
              v22); v20 < m_numEdges; v9 = _mm_add_ps(v9, _mm_shuffle_ps(v32, v32, 201)) )
  {
    v24 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
            v7,
            v6,
            v13,
            v14,
            (hkArray<int,hkContainerHeapAllocator> *)&this[208],
            v20 + m_startEdgeIndex);
    v25 = v24->m_a;
    if ( (int)v25 >= v15 )
      v26 = (__m128 *)(*(_QWORD *)&this[304] + 16i64 * ((int)v25 - v15));
    else
      v26 = (__m128 *)(*(_QWORD *)&this[48] + 16 * v25);
    m_b = v24->m_b;
    v28 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*v26, *v26, 0), v19),
                _mm_mul_ps(_mm_shuffle_ps(*v26, *v26, 85), v18)),
              _mm_mul_ps(_mm_shuffle_ps(*v26, *v26, 170), v21)),
            v22);
    if ( (int)m_b >= v15 )
      v29 = (__m128 *)(*(_QWORD *)&this[304] + 16i64 * ((int)m_b - v15));
    else
      v29 = (__m128 *)(*(_QWORD *)&this[48] + 16 * m_b);
    v8 = _mm_add_ps(v8, v28);
    v30 = _mm_sub_ps(v28, i);
    ++v20;
    v31 = _mm_sub_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v29, *v29, 0), v19),
                  _mm_mul_ps(_mm_shuffle_ps(*v29, *v29, 85), v18)),
                _mm_mul_ps(_mm_shuffle_ps(*v29, *v29, 170), v21)),
              v22),
            i);
    v32 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v30), _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v31));
  }
  v33 = 0i64;
  v33.m128_f32[0] = (float)m_numEdges;
  v34 = _mm_shuffle_ps(v33, v33, 0);
  v35 = _mm_rcp_ps(v34);
  v36 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v34, v35)), v35);
  v37 = _mm_mul_ps(v9, v9);
  v38 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)), _mm_shuffle_ps(v37, v37, 170));
  v39 = _mm_rsqrt_ps(v38);
  v40 = _mm_mul_ps(
          v9,
          _mm_andnot_ps(
            _mm_cmple_ps(v38, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
              _mm_mul_ps(*(__m128 *)_xmm, v39))));
  v41 = _mm_mul_ps(_mm_mul_ps(v8, v36), v40);
  *faceIndex = _mm_shuffle_ps(
                 v40,
                 _mm_unpackhi_ps(
                   v40,
                   _mm_sub_ps(
                     (__m128)0i64,
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
                       _mm_shuffle_ps(v41, v41, 170)))),
                 196);
}

// File Line: 3066
// RVA: 0xBCC980
void __fastcall `anonymous namespace::rotateArray<hkaiNavMesh::Edge>(hkaiNavMesh::Edge *data, int n, int offset)
{
  __int64 v4; // rbp
  __int64 v5; // rdi
  hkLifoAllocator *Value; // rax
  char *m_cur; // rbx
  int v8; // esi
  char *v9; // rcx
  char *v10; // rcx
  __int64 v11; // r8
  char *v12; // rdx
  int v13; // eax
  __int64 v14; // rcx
  char *v15; // rdx
  char *v16; // r8
  int v17; // eax
  int v18; // edi
  __int64 v19; // r8
  unsigned int *p_m_oppositeEdge; // rax
  __int64 v21; // rdx
  unsigned int v22; // ecx
  hkLifoAllocator *v23; // rax
  int v24; // r8d

  if ( offset )
  {
    v4 = offset;
    v5 = n;
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)Value->m_cur;
    v8 = (20 * v5 + 127) & 0xFFFFFF80;
    v9 = &m_cur[v8];
    if ( v8 > Value->m_slabSize || v9 > Value->m_end )
      m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v8);
    else
      Value->m_cur = v9;
    if ( (int)v5 > 0 )
    {
      v10 = m_cur + 4;
      v11 = v5;
      v12 = (char *)((char *)data - m_cur);
      do
      {
        v13 = *(_DWORD *)&v12[(_QWORD)v10 - 4];
        v10 += 20;
        *((_DWORD *)v10 - 6) = v13;
        *((_DWORD *)v10 - 5) = *(_DWORD *)&v10[(_QWORD)v12 - 20];
        *((_DWORD *)v10 - 4) = *(_DWORD *)&v10[(_QWORD)v12 - 16];
        *((_DWORD *)v10 - 3) = *(_DWORD *)&v10[(_QWORD)v12 - 12];
        *(v10 - 8) = v12[(_QWORD)v10 - 8];
        *(v10 - 7) = v12[(_QWORD)v10 - 7];
        *((_WORD *)v10 - 3) = *(_WORD *)&v12[(_QWORD)v10 - 6];
        --v11;
      }
      while ( v11 );
    }
    if ( (int)v4 > 0 )
    {
      v14 = v4;
      v15 = &m_cur[20 * (v5 - v4) + 8];
      v16 = (char *)data + 20 * (v4 - v5) - (_QWORD)m_cur;
      do
      {
        v17 = *((_DWORD *)v15 - 2);
        v15 += 20;
        *(_DWORD *)&v16[(_QWORD)v15 - 28] = v17;
        *(_DWORD *)&v15[(_QWORD)v16 - 24] = *((_DWORD *)v15 - 6);
        *(_DWORD *)&v15[(_QWORD)v16 - 20] = *((_DWORD *)v15 - 5);
        *(_DWORD *)&v15[(_QWORD)v16 - 16] = *((_DWORD *)v15 - 4);
        v15[(_QWORD)v16 - 12] = *(v15 - 12);
        v15[(_QWORD)v16 - 11] = *(v15 - 11);
        *(_WORD *)&v16[(_QWORD)v15 - 10] = *((_WORD *)v15 - 5);
        --v14;
      }
      while ( v14 );
    }
    v18 = v5 - v4;
    v19 = v18;
    if ( v18 > 0 )
    {
      p_m_oppositeEdge = &data[v4].m_oppositeEdge;
      v21 = &m_cur[-20 * v4] - (char *)data;
      do
      {
        v22 = *(unsigned int *)((char *)p_m_oppositeEdge + v21 - 8);
        p_m_oppositeEdge += 5;
        *(p_m_oppositeEdge - 7) = v22;
        *(p_m_oppositeEdge - 6) = *(unsigned int *)((char *)p_m_oppositeEdge + v21 - 24);
        *(p_m_oppositeEdge - 5) = *(unsigned int *)((char *)p_m_oppositeEdge + v21 - 20);
        *(p_m_oppositeEdge - 4) = *(unsigned int *)((char *)p_m_oppositeEdge + v21 - 16);
        *((_BYTE *)p_m_oppositeEdge - 12) = *((_BYTE *)p_m_oppositeEdge + v21 - 12);
        *((_BYTE *)p_m_oppositeEdge - 11) = *((_BYTE *)p_m_oppositeEdge + v21 - 11);
        *((_WORD *)p_m_oppositeEdge - 5) = *(_WORD *)((char *)p_m_oppositeEdge + v21 - 10);
        --v19;
      }
      while ( v19 );
    }
    v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v24 = (v8 + 15) & 0xFFFFFFF0;
    if ( v8 > v23->m_slabSize || &m_cur[v24] != v23->m_cur || v23->m_firstNonLifoEnd == m_cur )
      hkLifoAllocator::slowBlockFree(v23, m_cur, v24);
    else
      v23->m_cur = m_cur;
  }
}

// File Line: 3095
// RVA: 0xBC7770
void __fastcall `anonymous namespace::calcMinimalWidth(
        hkArrayBase<hkVector4f> *vertices,
        hkVector4f *up,
        int *baseOut,
        int *antipodeOut,
        hkSimdFloat32 *widthOut)
{
  __int64 m_size; // r10
  hkVector4f *m_data; // r11
  int v7; // ebx
  hkSimdFloat32 v8; // xmm7
  int v9; // ecx
  int v13; // edi
  int v14; // edx
  __m128 m_quad; // xmm10
  int v16; // r9d
  __m128 v17; // xmm8
  __m128 *p_m_quad; // r8
  __m128 v19; // xmm9
  __m128 v20; // xmm5
  __int64 v21; // rax
  int v22; // edx
  __m128 v23; // xmm1
  __m128 v24; // xmm6
  __m128 v25; // xmm6
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  __m128 v29; // xmm6
  __m128 v30; // xmm2
  __m128 v31; // xmm6
  __m128 v32; // xmm1
  __m128 v33; // xmm1
  __m128 v34; // xmm0
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  __m128 v38; // xmm0
  __m128 i; // xmm1
  __m128 v40; // xmm1
  __m128 v41; // xmm1
  __m128 v42; // xmm0

  m_size = vertices->m_size;
  m_data = vertices->m_data;
  v7 = -1;
  v8.m_real = (__m128)xmmword_141A712B0;
  v9 = 0;
  v13 = -1;
  v14 = 1;
  m_quad = m_data[m_size - 1].m_quad;
  v16 = m_size - 1;
  if ( (int)m_size > 0 )
  {
    v17 = up->m_quad;
    p_m_quad = &m_data->m_quad;
    v19 = _mm_shuffle_ps(v17, v17, 201);
    do
    {
      v20 = m_quad;
      m_quad = *p_m_quad;
      v21 = v14;
      v22 = v14 + 1;
      v23 = _mm_sub_ps(*p_m_quad, v20);
      v24 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v17), _mm_mul_ps(v19, v23));
      v25 = _mm_shuffle_ps(v24, v24, 201);
      v26 = _mm_mul_ps(v25, v25);
      v27 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
              _mm_shuffle_ps(v26, v26, 170));
      v28 = _mm_rsqrt_ps(v27);
      v29 = _mm_mul_ps(
              v25,
              _mm_andnot_ps(
                _mm_cmple_ps(v27, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v27), v28)),
                  _mm_mul_ps(*(__m128 *)_xmm, v28))));
      v30 = _mm_mul_ps(v29, v20);
      v31 = _mm_shuffle_ps(
              v29,
              _mm_unpackhi_ps(
                v29,
                _mm_sub_ps(
                  (__m128)0i64,
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                    _mm_shuffle_ps(v30, v30, 170)))),
              196);
      v32 = _mm_mul_ps(m_data[v21].m_quad, v31);
      v33 = _mm_shuffle_ps(v32, _mm_unpackhi_ps(v32, v31), 196);
      v34 = _mm_add_ps(_mm_shuffle_ps(v33, v33, 78), v33);
      v35 = _mm_mul_ps(m_data[v22].m_quad, v31);
      v36 = _mm_add_ps(_mm_shuffle_ps(v34, v34, 177), v34);
      v37 = _mm_shuffle_ps(v35, _mm_unpackhi_ps(v35, v31), 196);
      v38 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 78), v37);
      for ( i = _mm_add_ps(_mm_shuffle_ps(v38, v38, 177), v38);
            i.m128_f32[0] >= v36.m128_f32[0];
            i = _mm_add_ps(_mm_shuffle_ps(v42, v42, 177), v42) )
      {
        v36 = i;
        v22 = (v22 + 1) % (int)m_size;
        v40 = _mm_mul_ps(m_data[v22].m_quad, v31);
        v41 = _mm_shuffle_ps(v40, _mm_unpackhi_ps(v40, v31), 196);
        v42 = _mm_add_ps(_mm_shuffle_ps(v41, v41, 78), v41);
      }
      v14 = ((int)m_size - 1 + v22) % (int)m_size;
      if ( v36.m128_f32[0] < v8.m_real.m128_f32[0] )
      {
        v7 = v16;
        v13 = v14;
        v8.m_real = v36;
      }
      v16 = v9++;
      ++p_m_quad;
    }
    while ( v9 < (int)m_size );
  }
  *baseOut = v7;
  *antipodeOut = v13;
  *widthOut = (hkSimdFloat32)v8.m_real;
}

// File Line: 3162
// RVA: 0xBC6AB0
void __fastcall hkaiNavMeshUtils::rotateFace(hkaiNavMesh *navMesh, int faceIndex, int newFirstEdgeIndex)
{
  hkaiNavMesh::Face *v4; // rbx
  __int64 m_startEdgeIndex; // rax
  int m_numEdges; // edx
  int v7; // esi
  int m_edgeDataStriding; // ecx
  __int64 v9; // r9
  int v10; // eax
  __int64 v11; // r8
  __int64 v12; // r10
  hkaiNavMesh::Edge *m_data; // r11
  unsigned int m_oppositeEdge; // eax

  v4 = &navMesh->m_faces.m_data[faceIndex];
  m_startEdgeIndex = v4->m_startEdgeIndex;
  if ( newFirstEdgeIndex != (_DWORD)m_startEdgeIndex )
  {
    m_numEdges = v4->m_numEdges;
    v7 = m_startEdgeIndex + m_numEdges - newFirstEdgeIndex;
    `anonymous namespace::rotateArray<hkaiNavMesh::Edge>(&navMesh->m_edges.m_data[m_startEdgeIndex], m_numEdges, v7);
    m_edgeDataStriding = navMesh->m_edgeDataStriding;
    if ( m_edgeDataStriding > 0 )
      `anonymous namespace::rotateArray<int>(
        &navMesh->m_edgeData.m_data[m_edgeDataStriding * v4->m_startEdgeIndex],
        m_edgeDataStriding * v4->m_numEdges,
        v7 * m_edgeDataStriding);
    v9 = v4->m_startEdgeIndex;
    v10 = v9 + v4->m_numEdges;
    if ( v9 != v10 )
    {
      v11 = v9;
      v12 = v10 - v9;
      do
      {
        m_data = navMesh->m_edges.m_data;
        m_oppositeEdge = m_data[v11].m_oppositeEdge;
        if ( m_oppositeEdge != -1 )
          m_data[m_oppositeEdge & 0x3FFFFF].m_oppositeEdge = v9 | m_oppositeEdge & 0xFFC00000;
        LODWORD(v9) = v9 + 1;
        ++v11;
        --v12;
      }
      while ( v12 );
    }
  }
}

// File Line: 3202
// RVA: 0xBC6BA0
void __fastcall hkaiNavMeshUtils::rotateOwnedFace(
        hkaiStreamingCollection *streamingCollection,
        unsigned int faceKey,
        unsigned int newFirstEdgeKey)
{
  __int64 v3; // r12
  unsigned int v4; // r8d
  hkaiNavMeshInstance *m_instancePtr; // rdi
  hkaiNavMesh::Face *v7; // rsi
  int m_startEdgeIndex; // eax
  int m_numEdges; // edx
  int v10; // ebx
  int m_edgeDataStriding; // r9d
  __int64 v12; // rax
  int m_numOriginalEdges; // ecx
  __int64 v14; // rcx
  int *m_data; // rax
  int *v16; // rcx
  int v17; // ebx
  int v18; // esi
  hkaiNavMesh::Edge *v19; // rax
  unsigned int m_oppositeEdge; // edx
  hkaiNavMeshInstance *v21; // r9
  int v22; // eax
  int index; // edx
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // r10
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_instancedEdges; // r11
  __int64 v26; // rcx
  hkaiNavMesh::Edge *v27; // rax
  int v28; // r8d
  hkaiNavMesh::Edge *v29; // rdx

  v3 = faceKey >> 22;
  v4 = newFirstEdgeKey & 0x3FFFFF;
  m_instancePtr = streamingCollection->m_instances.m_data[v3].m_instancePtr;
  v7 = &m_instancePtr->m_ownedFaces.m_data[(faceKey & 0x3FFFFF) - m_instancePtr->m_numOriginalFaces];
  m_startEdgeIndex = v7->m_startEdgeIndex;
  if ( v4 == v7->m_startEdgeIndex )
    return;
  m_numEdges = v7->m_numEdges;
  v10 = m_startEdgeIndex + m_numEdges - v4;
  `anonymous namespace::rotateArray<hkaiNavMesh::Edge>(
    &m_instancePtr->m_ownedEdges.m_data[m_startEdgeIndex - m_instancePtr->m_numOriginalEdges],
    m_numEdges,
    v10);
  m_edgeDataStriding = m_instancePtr->m_edgeDataStriding;
  if ( m_edgeDataStriding > 0 )
  {
    v12 = v7->m_startEdgeIndex;
    m_numOriginalEdges = m_instancePtr->m_numOriginalEdges;
    if ( (int)v12 < m_numOriginalEdges )
    {
      if ( m_instancePtr->m_edgeMap.m_size )
        LODWORD(v12) = m_instancePtr->m_edgeMap.m_data[v12];
      if ( (_DWORD)v12 == -1 )
      {
        v16 = 0i64;
LABEL_11:
        `anonymous namespace::rotateArray<int>(v16, m_edgeDataStriding * v7->m_numEdges, v10 * m_edgeDataStriding);
        goto LABEL_12;
      }
      v14 = (int)v12;
      m_data = m_instancePtr->m_instancedEdgeData.m_data;
    }
    else
    {
      v14 = (int)v12 - m_numOriginalEdges;
      m_data = m_instancePtr->m_ownedEdgeData.m_data;
    }
    v16 = &m_data[v14];
    goto LABEL_11;
  }
LABEL_12:
  v17 = v7->m_startEdgeIndex;
  v18 = v7->m_startEdgeIndex + v7->m_numEdges;
  if ( v17 != v18 )
  {
    while ( 1 )
    {
      v19 = m_instancePtr->m_ownedEdges.m_data;
      m_oppositeEdge = v19[v17 - m_instancePtr->m_numOriginalEdges].m_oppositeEdge;
      if ( m_oppositeEdge != -1 )
        break;
LABEL_27:
      if ( ++v17 == v18 )
        return;
    }
    if ( (v19[v17 - m_instancePtr->m_numOriginalEdges].m_flags.m_storage & 0x40) != 0 )
      v21 = streamingCollection->m_instances.m_data[m_oppositeEdge >> 22].m_instancePtr;
    else
      v21 = m_instancePtr;
    v22 = v21->m_numOriginalEdges;
    index = m_oppositeEdge & 0x3FFFFF;
    instanceMap = &v21->m_edgeMap;
    p_m_instancedEdges = &v21->m_instancedEdges;
    if ( index < v22 )
    {
      if ( v21->m_edgeMap.m_size )
        v28 = instanceMap->m_data[index];
      else
        v28 = index;
      if ( v28 == -1 )
      {
        v29 = hkaiNavMeshInstance_instance_hkaiNavMesh::Edge_int__0(
                v21->m_originalEdges,
                p_m_instancedEdges,
                v21->m_originalEdgeData,
                &v21->m_instancedEdgeData,
                instanceMap,
                index,
                v21->m_edgeDataStriding);
LABEL_26:
        v29->m_oppositeEdge = v17 | ((_DWORD)v3 << 22);
        goto LABEL_27;
      }
      v26 = v28;
      v27 = p_m_instancedEdges->m_data;
    }
    else
    {
      v26 = index - v22;
      v27 = v21->m_ownedEdges.m_data;
    }
    v29 = &v27[v26];
    goto LABEL_26;
  }
}

// File Line: 3258
// RVA: 0xBC6DB0
__int64 __fastcall hkaiNavMeshUtils::findBestCenter(hkaiNavMesh *mesh, int faceIndex, hkVector4f *upIn)
{
  __m128 m_quad; // xmm6
  hkaiNavMesh::Face *v5; // rax
  __int64 m_numEdges; // rdi
  __int64 m_startEdgeIndex; // rax
  _DWORD *v8; // r14
  int v9; // r15d
  hkLifoAllocator *Value; // rax
  __m128 *m_cur; // rsi
  int v12; // edx
  char *v13; // rcx
  int v14; // ebx
  hkResultEnum m_enum; // r12d
  hkLifoAllocator *v16; // rax
  int v17; // edx
  char *v18; // rcx
  __int64 v19; // r9
  int v20; // r10d
  __int64 v21; // r11
  __int64 v22; // rdx
  hkaiNavMesh::Edge *m_data; // r8
  int v24; // ecx
  __int64 v25; // rax
  __int64 m_a; // rcx
  __m128 v27; // xmm3
  __int64 v28; // rax
  __m128 v29; // xmm1
  __int64 v30; // rcx
  __m128 v31; // xmm4
  __int64 v32; // rax
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  __m128 v35; // xmm2
  hkLifoAllocator *v36; // rax
  char *v37; // r9
  int v38; // edx
  char *v39; // rcx
  int v40; // r9d
  int v41; // xmm10_4
  int v42; // r11d
  int v43; // r8d
  int v44; // r10d
  __m128 *v45; // r15
  __m128 v46; // xmm11
  __m128 v47; // xmm0
  int v48; // edx
  __m128 v49; // xmm12
  __m128 v50; // xmm6
  int v51; // ecx
  __m128 v52; // xmm9
  __m128 v53; // xmm7
  int v54; // edx
  __m128 v55; // xmm2
  float v56; // xmm5_4
  __m128 v57; // xmm4
  __m128 v58; // xmm1
  __m128 v59; // xmm3
  __m128 v60; // xmm1
  __m128 v61; // xmm2
  __m128 v62; // xmm0
  __m128 v63; // xmm4
  __m128 v64; // xmm4
  float v65; // xmm1_4
  char *v66; // r15
  int v67; // eax
  unsigned int v68; // r13d
  signed int v69; // ebx
  hkLifoAllocator *v70; // rax
  int v71; // r8d
  int v72; // ebx
  hkLifoAllocator *v73; // rax
  int v74; // r8d
  int v75; // edi
  hkLifoAllocator *v76; // rax
  int v77; // r8d
  char *array; // [rsp+18h] [rbp-79h] BYREF
  int sizeElem; // [rsp+20h] [rbp-71h]
  hkResultEnum v80; // [rsp+24h] [rbp-6Dh]
  char *v81; // [rsp+28h] [rbp-69h]
  int v82; // [rsp+30h] [rbp-61h]
  hkResult result; // [rsp+F8h] [rbp+67h] BYREF
  int vars0; // [rsp+100h] [rbp+6Fh]

  m_quad = upIn->m_quad;
  v5 = &mesh->m_faces.m_data[faceIndex];
  m_numEdges = v5->m_numEdges;
  m_startEdgeIndex = (unsigned int)v5->m_startEdgeIndex;
  vars0 = m_startEdgeIndex;
  if ( (_DWORD)m_numEdges != 3 )
  {
    v8 = 0i64;
    v9 = 0;
    if ( (_DWORD)m_numEdges )
    {
      Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (__m128 *)Value->m_cur;
      v12 = (16 * m_numEdges + 127) & 0xFFFFFF80;
      v13 = (char *)m_cur + v12;
      if ( v12 > Value->m_slabSize || v13 > Value->m_end )
        m_cur = (__m128 *)hkLifoAllocator::allocateFromNewSlab(Value, v12);
      else
        Value->m_cur = v13;
    }
    else
    {
      m_cur = 0i64;
    }
    v14 = 0;
    m_enum = m_numEdges | 0x80000000;
    result.m_enum = m_numEdges | 0x80000000;
    if ( (_DWORD)m_numEdges )
    {
      v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v8 = v16->m_cur;
      v17 = (4 * m_numEdges + 127) & 0xFFFFFF80;
      v18 = (char *)v8 + v17;
      if ( v17 > v16->m_slabSize || v18 > v16->m_end )
        v8 = hkLifoAllocator::allocateFromNewSlab(v16, v17);
      else
        v16->m_cur = v18;
    }
    v19 = m_numEdges;
    v20 = 0;
    if ( (int)m_numEdges <= 0 )
      goto LABEL_57;
    v21 = m_numEdges;
    v22 = vars0;
    do
    {
      m_data = mesh->m_edges.m_data;
      if ( m_data[v22].m_oppositeEdge == -1 || (v24 = 1, (m_data[v22].m_flags.m_storage & 0x20) != 0) )
        v24 = 0;
      v25 = v14++;
      v8[v25] = v24;
      if ( v24 )
        ++v20;
      m_a = m_data[v22++].m_a;
      v27 = mesh->m_vertices.m_data[m_a].m_quad;
      v28 = v9++;
      v29 = _mm_mul_ps(m_quad, v27);
      m_cur[v28] = _mm_sub_ps(
                     v27,
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                         _mm_shuffle_ps(v29, v29, 170)),
                       m_quad));
      --v21;
    }
    while ( v21 );
    m_enum = result.m_enum;
    if ( v20 < 2 )
    {
LABEL_57:
      v68 = vars0;
    }
    else
    {
      v30 = 16i64 * ((int)m_numEdges - 1);
      v31 = m_cur[m_numEdges - 1];
      v32 = 0i64;
      do
      {
        v33 = v31;
        v31 = m_cur[v32];
        v34 = _mm_sub_ps(v33, v31);
        v35 = _mm_mul_ps(v34, v34);
        *(__m128 *)((char *)m_cur + v30) = _mm_shuffle_ps(
                                             v33,
                                             _mm_unpackhi_ps(
                                               v33,
                                               _mm_add_ps(
                                                 _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
                                                 _mm_shuffle_ps(v35, v35, 170))),
                                             196);
        v30 = v32 * 16;
        ++v32;
        --v19;
      }
      while ( v19 );
      sizeElem = 0;
      v80 = 0x80000000;
      v82 = m_numEdges;
      v36 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v37 = (char *)v36->m_cur;
      v38 = (4 * m_numEdges + 127) & 0xFFFFFF80;
      v39 = &v37[v38];
      if ( v38 > v36->m_slabSize || v39 > v36->m_end )
      {
        v37 = (char *)hkLifoAllocator::allocateFromNewSlab(v36, v38);
        array = v37;
      }
      else
      {
        v36->m_cur = v39;
        array = v37;
      }
      v80 = m_enum;
      v81 = v37;
      if ( (m_enum & 0x3FFFFFFF) < (int)m_numEdges )
      {
        v40 = m_numEdges;
        if ( (int)m_numEdges < 2 * (m_enum & 0x3FFFFFFF) )
          v40 = 2 * (m_enum & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array, v40, 4);
        v37 = array;
      }
      v41 = 1602224112;
      v42 = 0;
      v43 = 0;
      v44 = m_numEdges - 1;
      sizeElem = m_numEdges;
      v45 = m_cur;
      v46 = query.m_quad;
      do
      {
        v47 = 0i64;
        v48 = v44;
        if ( v44 != v43 )
        {
          do
          {
            if ( v8[v48] )
              v47 = _mm_max_ps(v47, _mm_shuffle_ps(m_cur[v48], m_cur[v48], 255));
            *(_DWORD *)&v37[4 * v48] = v47.m128_i32[0];
            v37 = array;
            v48 = ((int)m_numEdges - 1 + v48) % (int)m_numEdges;
          }
          while ( v48 != v43 );
          v46 = query.m_quad;
        }
        v49 = *v45;
        v50 = 0i64;
        v51 = v43;
        v52 = *v45;
        if ( v43 != v44 )
        {
          do
          {
            v53 = v52;
            v54 = (v51 + 1) % (int)m_numEdges;
            v55 = _mm_shuffle_ps(v52, v52, 255);
            v52 = m_cur[v54];
            if ( v8[v51] )
            {
              v50 = _mm_max_ps(v50, v55);
            }
            else if ( v50.m128_f32[0] > 0.0 )
            {
              v56 = _mm_shuffle_ps((__m128)*(unsigned int *)&v37[4 * v51], (__m128)*(unsigned int *)&v37[4 * v51], 0).m128_f32[0];
              if ( v56 == 0.0 )
                break;
              v57 = _mm_sub_ps(v52, v53);
              v58 = _mm_mul_ps(_mm_sub_ps(v49, v53), v57);
              v59 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v58, v58, 85), _mm_shuffle_ps(v58, v58, 0)),
                      _mm_shuffle_ps(v58, v58, 170));
              v60 = _mm_rcp_ps(v55);
              v61 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v60, v55)), v60), v59);
              v62 = _mm_cmplt_ps(v61, v46);
              v63 = _mm_sub_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          v57,
                          _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v61, v62), _mm_andnot_ps(v62, v46)))),
                        v53),
                      v49);
              v64 = _mm_mul_ps(v63, v63);
              v65 = (float)(_mm_shuffle_ps(v64, v64, 85).m128_f32[0] + _mm_shuffle_ps(v64, v64, 0).m128_f32[0])
                  + _mm_shuffle_ps(v64, v64, 170).m128_f32[0];
              if ( v65 < (float)(fmin(fmin(v56, v50.m128_f32[0]), *(float *)&v41) - 0.0039215689) )
              {
                v42 = v43;
                v41 = LODWORD(v65);
              }
            }
            v51 = (v51 + 1) % (int)m_numEdges;
          }
          while ( v54 != v44 );
        }
        v44 = v43++;
        ++v45;
      }
      while ( v43 < (int)m_numEdges );
      v66 = v81;
      v67 = sizeElem;
      v68 = v42 + vars0;
      if ( v81 == v37 )
        v67 = 0;
      sizeElem = v67;
      v69 = (4 * v82 + 127) & 0xFFFFFF80;
      v70 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v71 = (v69 + 15) & 0xFFFFFFF0;
      if ( v69 > v70->m_slabSize || &v66[v71] != v70->m_cur || v70->m_firstNonLifoEnd == v66 )
        hkLifoAllocator::slowBlockFree(v70, v66, v71);
      else
        v70->m_cur = v66;
      sizeElem = 0;
      if ( v80 >= HK_SUCCESS )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v80);
      array = 0i64;
      v80 = 0x80000000;
    }
    v72 = (4 * m_numEdges + 127) & 0xFFFFFF80;
    v73 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v74 = (v72 + 15) & 0xFFFFFFF0;
    if ( v72 > v73->m_slabSize || (char *)v8 + v74 != v73->m_cur || v73->m_firstNonLifoEnd == v8 )
      hkLifoAllocator::slowBlockFree(v73, v8, v74);
    else
      v73->m_cur = v8;
    if ( m_enum >= HK_SUCCESS )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v8, 4 * m_enum);
    v75 = (16 * m_numEdges + 127) & 0xFFFFFF80;
    v76 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v77 = (v75 + 15) & 0xFFFFFFF0;
    if ( v75 > v76->m_slabSize || (char *)m_cur + v77 != v76->m_cur || v76->m_firstNonLifoEnd == m_cur )
      hkLifoAllocator::slowBlockFree(v76, m_cur, v77);
    else
      v76->m_cur = m_cur;
    if ( m_enum >= HK_SUCCESS )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, m_cur, 16 * m_enum);
    return v68;
  }
  return m_startEdgeIndex;
}

// File Line: 3384
// RVA: 0xBC7420
void __fastcall hkaiNavMeshUtils::setBestFaceCenters(hkaiNavMesh *mesh, hkVector4f *up)
{
  int m_size; // esi
  int i; // ebx
  int BestCenter; // eax

  m_size = mesh->m_faces.m_size;
  for ( i = 0; i < m_size; ++i )
  {
    BestCenter = hkaiNavMeshUtils::findBestCenter(mesh, i, up);
    hkaiNavMeshUtils::rotateFace(mesh, i, BestCenter);
  }
}


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
void __fastcall hkaiNavMeshUtils::getFaceLocalVertices<hkaiNavMeshInstance>(hkaiNavMeshUtils *this, hkaiNavMeshInstance *mesh, hkaiNavMesh::Face *face, hkArrayBase<hkVector4f> *faceVerticesOut)
{
  int v4; // eax
  _OWORD *v5; // r15
  int v6; // er13
  signed int v7; // er14
  signed int v8; // ebp
  char v9; // r12
  hkaiNavMesh::Face *v10; // rsi
  hkaiNavMeshUtils *v11; // rbx
  __m128i *v12; // rdi
  signed int v13; // esi
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // r15
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v15; // r9
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v16; // r8
  hkaiNavMesh::Edge *v17; // rax
  __int64 v18; // rcx
  __m128i *v19; // rcx
  __int64 v20; // rax
  __m128i *v21; // rax
  __m128i v22; // xmm0
  __int64 v23; // rcx
  signed int v24; // eax
  __m128i *v25; // rax
  int v26; // [rsp+78h] [rbp+10h]
  hkaiNavMesh::Face *v27; // [rsp+80h] [rbp+18h]
  _OWORD *v28; // [rsp+88h] [rbp+20h]

  v27 = face;
  v4 = (signed __int16)mesh->m_memSizeAndFlags;
  v5 = *(_OWORD **)&face->m_startEdgeIndex;
  v6 = (int)mesh->vfptr;
  v7 = 0;
  v8 = v4 & 0xFFFFFFFE;
  v9 = mesh->m_memSizeAndFlags & 1;
  v10 = face;
  v11 = this;
  v28 = *(_OWORD **)&face->m_startEdgeIndex;
  v12 = *(__m128i **)&face->m_startEdgeIndex;
  v26 = (signed __int16)mesh->m_memSizeAndFlags;
  if ( (signed int)(v4 & 0xFFFFFFFE) > 0 )
  {
    v13 = *(_DWORD *)&this[56];
    instanceMap = (hkArray<int,hkContainerHeapAllocator> *)&this[208];
    v15 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[288];
    v16 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[256];
    do
    {
      v17 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
              *(hkaiNavMesh::Edge **)&v11[32],
              *(_DWORD *)&v11[40],
              v16,
              v15,
              instanceMap,
              v7 + v6);
      v18 = v17->m_a;
      if ( (signed int)v18 >= v13 )
        v19 = (__m128i *)(*(_QWORD *)&v11[304] + 16i64 * ((signed int)v18 - v13));
      else
        v19 = (__m128i *)(*(_QWORD *)&v11[48] + 16 * v18);
      v20 = v17->m_b;
      if ( (signed int)v20 >= v13 )
        v21 = (__m128i *)(*(_QWORD *)&v11[304] + 16i64 * ((signed int)v20 - v13));
      else
        v21 = (__m128i *)(*(_QWORD *)&v11[48] + 16 * v20);
      v22 = *v21;
      v7 += 2;
      *v12 = *v19;
      v12 += 2;
      v12[-1] = v22;
    }
    while ( v7 < v8 );
    v5 = v28;
    v4 = v26;
    v10 = v27;
  }
  if ( v9 )
  {
    v23 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
            *(hkaiNavMesh::Edge **)&v11[32],
            *(_DWORD *)&v11[40],
            (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&v11[256],
            (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&v11[288],
            (hkArray<int,hkContainerHeapAllocator> *)&v11[208],
            v6 + v4 - 1)->m_a;
    v24 = *(_DWORD *)&v11[56];
    if ( (signed int)v23 >= v24 )
      v25 = (__m128i *)(*(_QWORD *)&v11[304] + 16i64 * ((signed int)v23 - v24));
    else
      v25 = (__m128i *)(*(_QWORD *)&v11[48] + 16 * v23);
    _mm_store_si128(v12, *v25);
  }
  v5[*(signed int *)&v10->m_numEdges - 1] = *v5;
}

// File Line: 101
// RVA: 0xBBF990
void __fastcall hkaiNavMeshUtils::getFaceVertices(hkaiNavMeshInstance *meshInstance, hkaiNavMesh::Face *face, hkArrayBase<hkVector4f> *faceVerticesOut, hkArrayBase<hkVector4f> *a4)
{
  hkArrayBase<hkVector4f> *v4; // rdi
  hkaiNavMeshInstance *v5; // rbx
  __m128 v6; // xmm3
  __m128 v7; // xmm4
  __m128 v8; // xmm5
  __int64 v9; // rcx
  __m128 v10; // xmm6
  signed __int64 v11; // rax
  __m128 v12; // xmm1

  v4 = faceVerticesOut;
  v5 = meshInstance;
  hkaiNavMeshUtils::getFaceLocalVertices<hkaiNavMeshInstance>(
    (hkaiNavMeshUtils *)meshInstance,
    (hkaiNavMeshInstance *)face,
    (hkaiNavMesh::Face *)faceVerticesOut,
    a4);
  v6 = v5->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
  v7 = v5->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
  v8 = v5->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
  v9 = v4->m_size - 1;
  v10 = v5->m_referenceFrame.m_transform.m_translation.m_quad;
  v11 = (signed __int64)&v4->m_data[v9];
  do
  {
    v12 = *(__m128 *)v11;
    v11 -= 16i64;
    --v9;
    *(__m128 *)(v11 + 16) = _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), v7),
                                  _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), v6)),
                                _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), v8)),
                              v10);
  }
  while ( v9 >= 0 );
}

// File Line: 109
// RVA: 0xBBFB50
void __fastcall hkaiNavMeshUtils::calcFaceNormal(hkArrayBase<hkVector4f> *facePoints, hkVector4f *normalOut)
{
  hkVector4f *v2; // r8
  int v3; // eax
  __int64 v4; // rcx
  __m128 v5; // xmm4
  __m128 v6; // xmm3
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

  v2 = facePoints->m_data;
  v3 = facePoints->m_size - 1;
  v4 = v3;
  v5 = 0i64;
  v6 = v2->m_quad;
  if ( v3 > 0 )
  {
    do
    {
      v7 = v2->m_quad;
      v8 = v2[1].m_quad;
      ++v2;
      v9 = _mm_sub_ps(v8, v6);
      v10 = _mm_sub_ps(v7, v6);
      v11 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v10), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v9));
      v5 = _mm_add_ps(v5, _mm_shuffle_ps(v11, v11, 201));
      --v4;
    }
    while ( v4 );
  }
  v12 = _mm_mul_ps(v5, v5);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_rsqrt_ps(v13);
  v15 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v13), (__m128)0i64);
  v16 = _mm_cmpleps(v13, (__m128)0i64);
  v17 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)), _mm_mul_ps(*(__m128 *)_xmm, v14));
  if ( _mm_movemask_ps(v15) )
    normalOut->m_quad = _mm_or_ps(_mm_and_ps(_mm_mul_ps(_mm_andnot_ps(v16, v17), v5), v15), _mm_andnot_ps(v15, v5));
  else
    *normalOut = (hkVector4f)stru_141A71280.m_quad;
}

// File Line: 139
// RVA: 0xBBFC40
void __fastcall hkaiNavMeshUtils::calcEdgePlane(hkArrayBase<hkVector4f> *facePoints, int e, hkVector4f *faceNormal, hkVector4f *edgePlaneOut)
{
  __m128 v4; // xmm6
  __m128 v5; // xmm1
  __m128 v6; // xmm7
  __m128 v7; // xmm7
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm7
  __m128 v12; // xmm2

  v4 = facePoints->m_data[e].m_quad;
  v5 = _mm_sub_ps(facePoints->m_data[e + 1].m_quad, v4);
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
            _mm_cmpleps(v9, (__m128)0i64),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)), _mm_mul_ps(*(__m128 *)_xmm, v10))));
  v12 = _mm_mul_ps(v11, v4);
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
void __fastcall hkaiNavMeshUtils::calcFaceAabb(hkArrayBase<hkVector4f> *facePoints, hkSimdFloat32 *extraRadius, hkAabb *aabbOut)
{
  __m128 v3; // xmm2
  hkArrayBase<hkVector4f> *v4; // r9
  int v5; // eax
  __int64 v6; // rcx
  __m128 v7; // xmm1
  __m128 *v8; // rax
  hkVector4f v9; // xmm1

  v3 = (__m128)xmmword_141A712A0;
  v4 = facePoints;
  v5 = facePoints->m_size - 1;
  v6 = v5;
  v7 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), (__m128)xmmword_141A712A0);
  if ( v5 > 0 )
  {
    v8 = &v4->m_data->m_quad;
    do
    {
      v3 = _mm_min_ps(v3, *v8);
      v7 = _mm_max_ps(v7, *v8);
      ++v8;
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
hkaiNavMeshUtils *__fastcall hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(hkaiNavMeshUtils *this, hkSimdFloat32 *result, hkaiNavMeshInstance *mesh, __int64 faceIndex)
{
  hkSimdFloat32 *v4; // rbx
  hkaiNavMeshUtils *v5; // r13
  hkaiNavMesh::Face *v6; // rax
  int v7; // er15
  __m128 v8; // xmm11
  int v9; // ebp
  hkaiNavMesh::Edge *v10; // r12
  __int64 v11; // rcx
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v12; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v13; // r9
  signed int v14; // edi
  __m128 *v15; // rax
  __m128 v16; // xmm7
  __m128 v17; // xmm8
  int v18; // esi
  __m128 v19; // xmm9
  __m128 v20; // xmm10
  __m128 v21; // xmm6
  hkaiNavMesh::Edge *v22; // rax
  __int64 v23; // rcx
  __m128 *v24; // rcx
  __int64 v25; // rax
  __m128 v26; // xmm3
  __m128 *v27; // rax
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm5
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm3
  __m128 v36; // xmm6
  __m128 v37; // xmm1
  hkaiNavMeshUtils *v39; // [rsp+E0h] [rbp+8h]
  int v40; // [rsp+E8h] [rbp+10h]
  __m128 *v41; // [rsp+F8h] [rbp+20h]

  v41 = (__m128 *)faceIndex;
  v39 = this;
  v4 = result;
  v5 = this;
  v6 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
         (hkaiNavMesh::Face *)result[1].m_real.m128_u64[0],
         result[1].m_real.m128_i32[2],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&result[15],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&result[17],
         (hkArray<int,hkContainerHeapAllocator> *)&result[14],
         (int)mesh);
  v7 = v4[2].m_real.m128_i32[2];
  v8 = 0i64;
  v9 = v6->m_startEdgeIndex;
  v10 = (hkaiNavMesh::Edge *)v4[2].m_real.m128_u64[0];
  v40 = v6->m_numEdges;
  v11 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
          (hkaiNavMesh::Edge *)v4[2].m_real.m128_u64[0],
          v4[2].m_real.m128_i32[2],
          (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&v4[16],
          (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&v4[18],
          (hkArray<int,hkContainerHeapAllocator> *)&v4[13],
          v6->m_startEdgeIndex)->m_a;
  v14 = v4[3].m_real.m128_i32[2];
  if ( (signed int)v11 >= v14 )
    v15 = (__m128 *)(v4[19].m_real.m128_u64[0] + 16i64 * ((signed int)v11 - v14));
  else
    v15 = (__m128 *)(v4[3].m_real.m128_u64[0] + 16 * v11);
  v16 = v4[8].m_real;
  v17 = v4[7].m_real;
  v18 = 0;
  v19 = v4[9].m_real;
  v20 = v4[10].m_real;
  v21 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 0), v17), _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 85), v16)),
            _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 170), v19)),
          v20);
  if ( v40 > 0 )
  {
    do
    {
      v22 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
              v10,
              v7,
              v12,
              v13,
              (hkArray<int,hkContainerHeapAllocator> *)&v4[13],
              v18 + v9);
      v23 = v22->m_a;
      if ( (signed int)v23 >= v14 )
        v24 = (__m128 *)(v4[19].m_real.m128_u64[0] + 16i64 * ((signed int)v23 - v14));
      else
        v24 = (__m128 *)(v4[3].m_real.m128_u64[0] + 16 * v23);
      v25 = v22->m_b;
      v26 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v24, *v24, 0), v17),
                  _mm_mul_ps(_mm_shuffle_ps(*v24, *v24, 85), v16)),
                _mm_mul_ps(_mm_shuffle_ps(*v24, *v24, 170), v19)),
              v20);
      if ( (signed int)v25 >= v14 )
        v27 = (__m128 *)(v4[19].m_real.m128_u64[0] + 16i64 * ((signed int)v25 - v14));
      else
        v27 = (__m128 *)(v4[3].m_real.m128_u64[0] + 16 * v25);
      v28 = _mm_sub_ps(v26, v21);
      ++v18;
      v29 = _mm_sub_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 0), v17),
                    _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 85), v16)),
                  _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 170), v19)),
                v20),
              v21);
      v30 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v28), _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v29));
      v8 = _mm_add_ps(v8, _mm_shuffle_ps(v30, v30, 201));
    }
    while ( v18 < v40 );
    v5 = v39;
  }
  v31 = _mm_mul_ps(v8, v8);
  v32 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)), _mm_shuffle_ps(v31, v31, 170));
  v33 = v32;
  v34 = _mm_rsqrt_ps(v33);
  v35 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v33), (__m128)0i64);
  v36 = _mm_or_ps(
          _mm_and_ps(
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmpleps(v33, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
                  _mm_mul_ps(v34, *(__m128 *)_xmm))),
              v8),
            v35),
          _mm_andnot_ps(v35, v8));
  if ( _mm_movemask_ps(v35) )
  {
    v37 = _mm_rsqrt_ps(v32);
    *v41 = v36;
    *(__m128 *)v5 = _mm_mul_ps(
                      _mm_andnot_ps(
                        _mm_cmpleps(v32, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v37, v32), v37)),
                            _mm_mul_ps(v37, *(__m128 *)_xmm)),
                          v32)),
                      (__m128)xmmword_141A711B0);
  }
  else
  {
    *(hkVector4f *)v41 = (hkVector4f)stru_141A71280.m_quad;
    *(hkVector4f *)v5 = (hkVector4f)aabbOut.m_quad;
  }
  return v5;
}

// File Line: 225
// RVA: 0xBC8160
void __fastcall hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(hkaiNavMeshUtils *this, hkaiNavMeshInstance *mesh, __int64 faceIndex, hkVector4f *centroidOut)
{
  __m128 v4; // xmm6
  hkaiNavMeshUtils *v5; // rbx
  __m128 v6; // xmm7
  hkaiNavMesh::Face *v7; // rax
  signed int v8; // esi
  signed int v9; // er13
  signed int v10; // edi
  int v11; // er12
  int v12; // er14
  hkaiNavMesh::Edge *v13; // r15
  __m128 v14; // xmm8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v15; // r9
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v16; // r8
  __m128 v17; // xmm9
  __m128 v18; // xmm10
  __m128 v19; // xmm11
  __int64 v20; // rcx
  __m128 *v21; // rax
  __m128 v22; // xmm6
  __m128 v23; // xmm1
  __m128 *v24; // [rsp+D0h] [rbp+18h]

  v24 = (__m128 *)faceIndex;
  v4 = 0i64;
  v5 = this;
  v6 = 0i64;
  v7 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
         *(hkaiNavMesh::Face **)&this[16],
         *(_DWORD *)&this[24],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[240],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[272],
         (hkArray<int,hkContainerHeapAllocator> *)&this[224],
         (int)mesh);
  v8 = 0;
  v9 = v7->m_numEdges;
  if ( v9 > 0 )
  {
    v10 = *(_DWORD *)&v5[56];
    v11 = v7->m_startEdgeIndex;
    v12 = *(_DWORD *)&v5[40];
    v13 = *(hkaiNavMesh::Edge **)&v5[32];
    v14 = *(__m128 *)&v5[128];
    v15 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&v5[288];
    v16 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&v5[256];
    v17 = *(__m128 *)&v5[112];
    v18 = *(__m128 *)&v5[144];
    v19 = *(__m128 *)&v5[160];
    do
    {
      v20 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
              v13,
              v12,
              v16,
              v15,
              (hkArray<int,hkContainerHeapAllocator> *)&v5[208],
              v11 + v8)->m_a;
      if ( (signed int)v20 >= v10 )
        v21 = (__m128 *)(*(_QWORD *)&v5[304] + 16i64 * ((signed int)v20 - v10));
      else
        v21 = (__m128 *)(*(_QWORD *)&v5[48] + 16 * v20);
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
    while ( v8 < v9 );
  }
  v4.m128_f32[0] = (float)v9;
  v22 = _mm_shuffle_ps(v4, v4, 0);
  v23 = _mm_rcp_ps(v22);
  *v24 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v22)), v23), v6);
}

// File Line: 241
// RVA: 0xBC7D40
void __fastcall hkaiNavMeshUtils::calcEdgePlane<hkaiNavMeshInstance>(hkaiNavMeshUtils *this, hkaiNavMeshInstance *mesh, int faceIndex, __int64 edgeIndex, hkVector4f *faceNormal)
{
  hkaiNavMeshUtils *v5; // rbx
  __m128 *v6; // rdi
  hkaiNavMesh::Edge *v7; // rax
  signed int v8; // edx
  __int64 v9; // rcx
  __m128 *v10; // rcx
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  __int64 v13; // rax
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

  v5 = this;
  v6 = (__m128 *)edgeIndex;
  v7 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
         *(hkaiNavMesh::Edge **)&this[32],
         *(_DWORD *)&this[40],
         (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[256],
         (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&this[288],
         (hkArray<int,hkContainerHeapAllocator> *)&this[208],
         faceIndex);
  v8 = *(_DWORD *)&v5[56];
  v9 = v7->m_a;
  if ( (signed int)v9 >= v8 )
    v10 = (__m128 *)(*(_QWORD *)&v5[304] + 16i64 * ((signed int)v9 - v8));
  else
    v10 = (__m128 *)(*(_QWORD *)&v5[48] + 16 * v9);
  v11 = *(__m128 *)&v5[128];
  v12 = *(__m128 *)&v5[112];
  v13 = v7->m_b;
  v14 = *(__m128 *)&v5[144];
  v15 = *(__m128 *)&v5[160];
  v16 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v10, *v10, 0), v12), _mm_mul_ps(_mm_shuffle_ps(*v10, *v10, 85), v11)),
            _mm_mul_ps(_mm_shuffle_ps(*v10, *v10, 170), v14)),
          v15);
  if ( (signed int)v13 >= v8 )
    v17 = (__m128 *)(*(_QWORD *)&v5[304] + 16i64 * ((signed int)v13 - v8));
  else
    v17 = (__m128 *)(*(_QWORD *)&v5[48] + 16 * v13);
  v18 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 0), v12),
                _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 85), v11)),
              _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 170), v14)),
            v15),
          v16);
  v19 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(*v6, *v6, 201), v18), _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), *v6));
  v20 = _mm_shuffle_ps(v19, v19, 201);
  v21 = _mm_mul_ps(v20, v20);
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v23 = _mm_rsqrt_ps(v22);
  v24 = _mm_mul_ps(
          v20,
          _mm_andnot_ps(
            _mm_cmpleps(v22, (__m128)0i64),
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
void __fastcall hkaiNavMeshUtils::getClosestPointOnFace(hkArrayBase<hkVector4f> *facePoints, hkVector4f *position, hkVector4f *closestPointOut)
{
  float v3; // xmm14_4
  int v4; // eax
  __m128 v5; // xmm2
  __m128 v6; // xmm15
  hkVector4f *v7; // rdx
  signed __int64 v8; // rcx
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

  v3 = *(float *)&xmmword_141A712A0;
  v4 = facePoints->m_size - 2;
  v5 = facePoints->m_data->m_quad;
  v6 = position->m_quad;
  v66 = facePoints->m_data->m_quad;
  if ( v4 > 1i64 )
  {
    v7 = facePoints->m_data + 1;
    v8 = v4 - 1i64;
    v64 = _mm_shuffle_ps(aabbOut.m_quad, _mm_unpackhi_ps(aabbOut.m_quad, (__m128)xmmword_141A712F0), 196);
    v9 = v6;
    v10 = _mm_sub_ps(v6, v5);
    v11 = _mm_shuffle_ps(v10, v10, 201);
    v65 = _mm_shuffle_ps(query.m_quad, _mm_unpackhi_ps(query.m_quad, (__m128)xmmword_141A712A0), 196);
    v67 = v11;
    do
    {
      v12 = v7->m_quad;
      v13 = v7[1].m_quad;
      ++v7;
      v14 = _mm_sub_ps(v13, v12);
      v15 = _mm_sub_ps(v12, v5);
      v16 = _mm_sub_ps(v5, v13);
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
              _mm_cmpltps(
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
                    _mm_cmpeqps((__m128)0i64, v32),
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
                _mm_cmpeqps(v44, (__m128)0i64),
                _mm_mul_ps(
                  _mm_rcp_ps(v44),
                  _mm_add_ps(
                    _mm_shuffle_ps(_mm_unpackhi_ps(v39, v45), v43, 228),
                    _mm_add_ps(v47, _mm_shuffle_ps(_mm_movehl_ps(v47, v46), v43, 212)))));
        v49 = _mm_cmpltps(v48, v65);
        v50 = _mm_max_ps(v64, _mm_or_ps(_mm_and_ps(v48, v49), _mm_andnot_ps(v49, v65)));
        v51 = _mm_sub_ps(v10, _mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), v15));
        v52 = _mm_mul_ps(v51, v51);
        v53 = _mm_sub_ps(v18, _mm_mul_ps(_mm_shuffle_ps(v50, v50, 85), v14));
        v54 = _mm_sub_ps(v19, _mm_mul_ps(_mm_shuffle_ps(v50, v50, 170), v16));
        v55 = _mm_mul_ps(v53, v53);
        v56 = _mm_cmpltps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                  _mm_shuffle_ps(v52, v52, 170)),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                  _mm_shuffle_ps(v55, v55, 170)));
        v57 = _mm_or_ps(_mm_andnot_ps(v56, v53), _mm_and_ps(v51, v56));
        v58 = _mm_mul_ps(v54, v54);
        v59 = _mm_mul_ps(v57, v57);
        v60 = _mm_cmpltps(
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
      v63 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v62, v62, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v62, v62, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v62, v62, 170));
      if ( v63 < v3 )
      {
        v3 = v63;
        v6 = v34;
      }
      v5 = v66;
      v11 = v67;
      --v8;
    }
    while ( v8 );
  }
  *closestPointOut = (hkVector4f)v6;
}

// File Line: 300
// RVA: 0xBCBA70
void __fastcall hkaiNavMeshUtils_getClosestPointOnFace<hkaiNavMeshInstance,1>(hkaiNavMeshInstance *mesh, hkVector4f *position, int faceIndex, hkVector4f *closestPointOut)
{
  hkVector4f *v4; // rsi
  hkaiNavMeshInstance *v5; // rbx
  hkaiNavMesh::Face *v6; // rax
  int v7; // er15
  hkaiNavMesh::Edge *v8; // r12
  int v9; // ebp
  hkaiNavMesh::Face *v10; // r13
  hkaiNavMesh::Edge *v11; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v12; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v13; // r9
  signed int v14; // edi
  __int64 v15; // rcx
  __m128 *v16; // rax
  __m128 v17; // xmm6
  __m128 v18; // xmm15
  int index; // esi
  float v20; // xmm14_4
  int v21; // ebp
  __m128 v22; // xmm9
  __m128 v23; // xmm13
  hkaiNavMesh::Edge *v24; // rax
  __int64 v25; // rcx
  __m128 *v26; // rcx
  __int64 v27; // rax
  __m128 v28; // xmm1
  __m128 *v29; // rax
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
  hkVector4f *v84; // [rsp+158h] [rbp+10h]
  hkVector4f *v85; // [rsp+168h] [rbp+20h]

  v85 = closestPointOut;
  v84 = position;
  v4 = position;
  v5 = mesh;
  v6 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
         mesh->m_originalFaces,
         mesh->m_numOriginalFaces,
         &mesh->m_instancedFaces,
         &mesh->m_ownedFaces,
         &mesh->m_faceMap,
         faceIndex);
  v7 = v5->m_numOriginalEdges;
  v8 = v5->m_originalEdges;
  v9 = v6->m_startEdgeIndex;
  v10 = v6;
  v11 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
          v5->m_originalEdges,
          v5->m_numOriginalEdges,
          &v5->m_instancedEdges,
          &v5->m_ownedEdges,
          &v5->m_edgeMap,
          v6->m_startEdgeIndex);
  v14 = v5->m_numOriginalVertices;
  v15 = v11->m_a;
  if ( (signed int)v15 >= v14 )
    v16 = &v5->m_ownedVertices.m_data[(signed int)v15 - v14].m_quad;
  else
    v16 = &v5->m_originalVertices[v15].m_quad;
  v17 = *v16;
  v18 = v4->m_quad;
  index = v9 + 1;
  v20 = *(float *)&xmmword_141A712A0;
  v83 = *v16;
  v21 = v10->m_numEdges + v9 - 1;
  if ( index < v21 )
  {
    v22 = v84->m_quad;
    v23 = _mm_sub_ps(v84->m_quad, v17);
    v80 = _mm_shuffle_ps(aabbOut.m_quad, _mm_unpackhi_ps(aabbOut.m_quad, (__m128)xmmword_141A712F0), 196);
    v82 = _mm_shuffle_ps(query.m_quad, _mm_unpackhi_ps(query.m_quad, (__m128)xmmword_141A712A0), 196);
    v81 = _mm_shuffle_ps(v23, v23, 201);
    do
    {
      v24 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(v8, v7, v12, v13, &v5->m_edgeMap, index);
      v25 = v24->m_a;
      if ( (signed int)v25 >= v14 )
        v26 = &v5->m_ownedVertices.m_data[(signed int)v25 - v14].m_quad;
      else
        v26 = &v5->m_originalVertices[v25].m_quad;
      v27 = v24->m_b;
      v28 = *v26;
      if ( (signed int)v27 >= v14 )
        v29 = &v5->m_ownedVertices.m_data[(signed int)v27 - v14].m_quad;
      else
        v29 = &v5->m_originalVertices[v27].m_quad;
      v30 = _mm_sub_ps(v28, v17);
      v31 = _mm_sub_ps(v17, *v29);
      v32 = _mm_sub_ps(v22, *v29);
      v33 = _mm_sub_ps(*v29, v28);
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
              _mm_cmpltps(
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
                    _mm_cmpeqps((__m128)0i64, v48),
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
                _mm_cmpeqps(v60, (__m128)0i64),
                _mm_mul_ps(
                  _mm_rcp_ps(v60),
                  _mm_add_ps(
                    _mm_shuffle_ps(_mm_unpackhi_ps(v55, v61), v59, 228),
                    _mm_add_ps(v63, _mm_shuffle_ps(_mm_movehl_ps(v63, v62), v59, 212)))));
        v65 = _mm_cmpltps(v64, v82);
        v66 = _mm_max_ps(v80, _mm_or_ps(_mm_andnot_ps(v65, v82), _mm_and_ps(v64, v65)));
        v67 = _mm_sub_ps(v23, _mm_mul_ps(_mm_shuffle_ps(v66, v66, 0), v30));
        v68 = _mm_mul_ps(v67, v67);
        v69 = _mm_sub_ps(v34, _mm_mul_ps(_mm_shuffle_ps(v66, v66, 85), v33));
        v70 = _mm_sub_ps(v32, _mm_mul_ps(_mm_shuffle_ps(v66, v66, 170), v31));
        v71 = _mm_mul_ps(v69, v69);
        v72 = _mm_cmpltps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)),
                  _mm_shuffle_ps(v68, v68, 170)),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v71, v71, 85), _mm_shuffle_ps(v71, v71, 0)),
                  _mm_shuffle_ps(v71, v71, 170)));
        v73 = _mm_or_ps(_mm_and_ps(v67, v72), _mm_andnot_ps(v72, v69));
        v74 = _mm_mul_ps(v70, v70);
        v75 = _mm_mul_ps(v73, v73);
        v76 = _mm_cmpltps(
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
      v79 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v78, v78, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v78, v78, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v78, v78, 170));
      if ( v79 < v20 )
      {
        v20 = v79;
        v18 = v50;
      }
      v17 = v83;
      ++index;
    }
    while ( index < v21 );
  }
  *v85 = (hkVector4f)v18;
}

// File Line: 357
// RVA: 0xBC0270
void __fastcall hkaiNavMeshUtils::getClosestPointOnFace(hkaiNavMesh *mesh, hkVector4f *position, int faceIndex, hkVector4f *closestPointOut)
{
  hkaiNavMeshUtils_getClosestPointOnFace<hkaiNavMesh,0>(mesh, position, faceIndex, closestPointOut);
}

// File Line: 362
// RVA: 0xBC0280
void __fastcall hkaiNavMeshUtils::getClosestPointOnFace(hkaiNavMeshInstance *mesh, hkVector4f *position, int faceIndex, hkVector4f *closestPointOut)
{
  hkaiNavMeshUtils_getClosestPointOnFace<hkaiNavMeshInstance,0>(mesh, position, faceIndex, closestPointOut);
}

// File Line: 367
// RVA: 0xBC0290
void __fastcall hkaiNavMeshUtils::getClosestPointOnFaceLocal(hkaiNavMeshInstance *mesh, hkVector4f *position, int faceIndex, hkVector4f *closestPointOut)
{
  hkaiNavMeshUtils_getClosestPointOnFace<hkaiNavMeshInstance,1>(mesh, position, faceIndex, closestPointOut);
}

// File Line: 374
// RVA: 0xBCACC0
__int64 __fastcall hkaiNavMeshUtils_getClosestBoundaryOnFace<hkaiNavMesh,0>(hkaiNavMesh *mesh, const int faceIndex, hkVector4f *point, hkVector4f *up, hkVector4f *closestPointOut)
{
  unsigned int v5; // er10
  hkaiNavMesh *v6; // r11
  hkaiNavMesh::Face *v7; // rax
  __m128 v8; // xmm10
  __int64 v9; // rdx
  __m128 v10; // xmm11
  signed int v11; // er9
  __m128 v12; // xmm8
  __m128 v13; // xmm1
  __m128 v14; // xmm9
  hkaiNavMesh::Edge *v15; // r8
  hkVector4f *v16; // rcx
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
  v6 = mesh;
  v7 = &mesh->m_faces.m_data[faceIndex];
  v8 = (__m128)xmmword_141A712A0;
  v9 = v7->m_startEdgeIndex;
  v10 = up->m_quad;
  v11 = v9 + v7->m_numEdges;
  v12 = 0i64;
  v13 = _mm_mul_ps(v10, point->m_quad);
  v14 = _mm_sub_ps(
          point->m_quad,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
              _mm_shuffle_ps(v13, v13, 170)),
            v10));
  if ( (signed int)v9 < v11 )
  {
    v15 = &mesh->m_edges.m_data[v9];
    do
    {
      if ( v15->m_oppositeEdge == -1 || v15->m_flags.m_storage & 0x20 )
      {
        v16 = v6->m_vertices.m_data;
        v17 = v16[v15->m_a].m_quad;
        v18 = _mm_mul_ps(v10, v17);
        v19 = v16[v15->m_b].m_quad;
        v20 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                _mm_shuffle_ps(v18, v18, 170));
        v21 = _mm_mul_ps(v10, v19);
        v22 = _mm_sub_ps(v17, _mm_mul_ps(v20, v10));
        v23 = _mm_sub_ps(v22, v14);
        v24 = _mm_sub_ps(
                v19,
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                    _mm_shuffle_ps(v21, v21, 170)),
                  v10));
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
        v31 = _mm_cmpltps(v30, query.m_quad);
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
          v5 = v9;
          v12 = v14;
        }
      }
      LODWORD(v9) = v9 + 1;
      ++v15;
    }
    while ( (signed int)v9 < v11 );
  }
  result = v5;
  closestPointOut->m_quad = _mm_shuffle_ps(v12, _mm_unpackhi_ps(v12, v8), 196);
  return result;
}

// File Line: 426
// RVA: 0xBC06C0
int __fastcall hkaiNavMeshUtils::getClosestBoundaryOnFace(hkaiNavMesh *mesh, hkVector4f *point, const int fIdx, hkVector4f *up, hkVector4f *closestPointOut)
{
  return hkaiNavMeshUtils_getClosestBoundaryOnFace<hkaiNavMesh,0>(mesh, fIdx, point, up, closestPointOut);
}

// File Line: 432
// RVA: 0xBC06E0
int __fastcall hkaiNavMeshUtils::getClosestBoundaryOnFace(hkaiNavMeshInstance *mesh, hkVector4f *point, const int fIdx, hkVector4f *up, hkVector4f *closestPointOut)
{
  return hkaiNavMeshUtils_getClosestBoundaryOnFace<hkaiNavMeshInstance,0>(mesh, fIdx, point, up, closestPointOut);
}

// File Line: 438
// RVA: 0xBC0700
int __fastcall hkaiNavMeshUtils::getClosestBoundaryOnFaceLocal(hkaiNavMeshInstance *mesh, hkVector4f *point, const int fIdx, hkVector4f *up, hkVector4f *closestPointOut)
{
  return hkaiNavMeshUtils_getClosestBoundaryOnFace<hkaiNavMeshInstance,1>(mesh, fIdx, point, up, closestPointOut);
}

// File Line: 446
// RVA: 0xBC9230
__int64 __fastcall hkaiNavMeshUtils::castRayFace<hkaiNavMeshInstance>(hkaiNavMeshUtils *this, hkaiNavMeshInstance *mesh, __int64 faceIdx, hkcdRay *ray, hkSimdFloat32 *hitFractionOut)
{
  hkaiNavMeshUtils *v5; // rbx
  hkaiNavMesh::Face *v6; // rax
  int v7; // er12
  int v8; // er14
  hkaiNavMesh::Edge *v9; // r13
  hkaiNavMesh::Edge *v10; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v11; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v12; // r9
  signed int v13; // edi
  __int64 v14; // rcx
  __m128 *v15; // rax
  __m128 v16; // xmm6
  __m128 v17; // xmm8
  int index; // esi
  unsigned __int8 v19; // bp
  int v20; // er14
  __m128 v21; // xmm10
  __m128 v22; // xmm14
  __m128 v23; // xmm13
  __m128 v24; // xmm11
  __m128 v25; // xmm12
  hkaiNavMesh::Edge *v26; // rax
  __int64 v27; // rcx
  __m128 *v28; // rcx
  __int64 v29; // rax
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
  __m128 *v66; // [rsp+170h] [rbp+18h]
  hkcdRay *v67; // [rsp+178h] [rbp+20h]

  v67 = ray;
  v66 = (__m128 *)faceIdx;
  v5 = this;
  v6 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
         *(hkaiNavMesh::Face **)&this[16],
         *(_DWORD *)&this[24],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[240],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[272],
         (hkArray<int,hkContainerHeapAllocator> *)&this[224],
         (int)mesh);
  v7 = *(_DWORD *)&v5[40];
  v8 = v6->m_startEdgeIndex;
  v9 = *(hkaiNavMesh::Edge **)&v5[32];
  v65 = v6;
  v10 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
          *(hkaiNavMesh::Edge **)&v5[32],
          *(_DWORD *)&v5[40],
          (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&v5[256],
          (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&v5[288],
          (hkArray<int,hkContainerHeapAllocator> *)&v5[208],
          v6->m_startEdgeIndex);
  v13 = *(_DWORD *)&v5[56];
  v14 = v10->m_a;
  if ( (signed int)v14 >= v13 )
    v15 = (__m128 *)(*(_QWORD *)&v5[304] + 16i64 * ((signed int)v14 - v13));
  else
    v15 = (__m128 *)(*(_QWORD *)&v5[48] + 16 * v14);
  v16 = *(__m128 *)&v5[128];
  v17 = *(__m128 *)&v5[112];
  index = v8 + 1;
  v19 = 0;
  v20 = v65->m_numEdges + v8 - 1;
  v21 = *(__m128 *)&v5[144];
  v22 = *(__m128 *)&v5[160];
  v23 = query.m_quad;
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
    v25 = v66[1];
    v62 = _mm_sub_ps(*v66, v24);
    do
    {
      v26 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
              v9,
              v7,
              v11,
              v12,
              (hkArray<int,hkContainerHeapAllocator> *)&v5[208],
              index);
      v27 = v26->m_a;
      if ( (signed int)v27 >= v13 )
        v28 = (__m128 *)(*(_QWORD *)&v5[304] + 16i64 * ((signed int)v27 - v13));
      else
        v28 = (__m128 *)(*(_QWORD *)&v5[48] + 16 * v27);
      v29 = v26->m_b;
      v30 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v28, *v28, 0), v17),
                  _mm_mul_ps(_mm_shuffle_ps(*v28, *v28, 85), v16)),
                _mm_mul_ps(_mm_shuffle_ps(*v28, *v28, 170), v21)),
              v22);
      if ( (signed int)v29 >= v13 )
        v31 = (__m128 *)(*(_QWORD *)&v5[304] + 16i64 * ((signed int)v29 - v13));
      else
        v31 = (__m128 *)(*(_QWORD *)&v5[48] + 16 * v29);
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
          if ( v43.m128_f32[0] < COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 255)) )
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
                    _mm_cmpleps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
                          _mm_shuffle_ps(v47, v47, 170)),
                        (__m128)_xmm_b951b717b951b717b951b717b951b717),
                      _mm_add_ps(v57, _mm_add_ps(v56, v58)))) & 7) == 7
              && v43.m128_f32[0] < v23.m128_f32[0] )
            {
              v19 = 1;
              v23 = v43;
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
      v67->m_origin.m_quad = v23;
  }
  return v19;
}

// File Line: 486
// RVA: 0xBCC510
char __fastcall hkaiNavMeshUtils::intersectLineFace<hkaiNavMeshInstance>(hkaiNavMeshUtils *this, hkaiNavMeshInstance *mesh, __int64 faceIdx, hkcdRay *ray)
{
  hkcdRay *v4; // r12
  hkcdRay *v5; // r13
  hkaiNavMeshUtils *v6; // rbx
  hkaiNavMesh::Face *v7; // rsi
  __int64 v8; // rcx
  signed int v9; // eax
  __m128 *v10; // rax
  int index; // edi
  hkaiNavMesh::Edge *v12; // rax
  signed int v13; // edx
  __int64 v14; // rcx
  __m128 *v15; // rcx
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __int64 v18; // rax
  __m128 v19; // xmm5
  __m128 v20; // xmm6
  __m128 v21; // xmm2
  __m128 *v22; // rax
  __m128 v23; // xmm1
  char result; // al
  hkSimdFloat32 tolerance; // [rsp+30h] [rbp-88h]
  hkVector4f vC; // [rsp+40h] [rbp-78h]
  hkVector4f vB; // [rsp+50h] [rbp-68h]
  hkVector4f vA; // [rsp+60h] [rbp-58h]
  hkSimdFloat32 fractionOut; // [rsp+70h] [rbp-48h]

  v4 = ray;
  v5 = (hkcdRay *)faceIdx;
  v6 = this;
  v7 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
         *(hkaiNavMesh::Face **)&this[16],
         *(_DWORD *)&this[24],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[240],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[272],
         (hkArray<int,hkContainerHeapAllocator> *)&this[224],
         (int)mesh);
  v8 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
         *(hkaiNavMesh::Edge **)&v6[32],
         *(_DWORD *)&v6[40],
         (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&v6[256],
         (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&v6[288],
         (hkArray<int,hkContainerHeapAllocator> *)&v6[208],
         v7->m_startEdgeIndex)->m_a;
  v9 = *(_DWORD *)&v6[56];
  if ( (signed int)v8 >= v9 )
    v10 = (__m128 *)(*(_QWORD *)&v6[304] + 16i64 * ((signed int)v8 - v9));
  else
    v10 = (__m128 *)(*(_QWORD *)&v6[48] + 16 * v8);
  vA.m_quad = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*v10, *v10, 85), *(__m128 *)&v6[128]),
                    _mm_mul_ps(_mm_shuffle_ps(*v10, *v10, 0), *(__m128 *)&v6[112])),
                  _mm_mul_ps(_mm_shuffle_ps(*v10, *v10, 170), *(__m128 *)&v6[144])),
                *(__m128 *)&v6[160]);
  index = v7->m_startEdgeIndex + 1;
  if ( index >= v7->m_numEdges + v7->m_startEdgeIndex - 1 )
    return 0;
  while ( 1 )
  {
    v12 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
            *(hkaiNavMesh::Edge **)&v6[32],
            *(_DWORD *)&v6[40],
            (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&v6[256],
            (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&v6[288],
            (hkArray<int,hkContainerHeapAllocator> *)&v6[208],
            index);
    v13 = *(_DWORD *)&v6[56];
    v14 = v12->m_a;
    v15 = (__m128 *)((signed int)v14 >= v13 ? *(_QWORD *)&v6[304] + 16i64 * ((signed int)v14 - v13) : *(_QWORD *)&v6[48] + 16 * v14);
    v16 = *(__m128 *)&v6[128];
    v17 = *(__m128 *)&v6[112];
    v18 = v12->m_b;
    v19 = *(__m128 *)&v6[144];
    v20 = *(__m128 *)&v6[160];
    v21 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 0), v17),
                _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 85), v16)),
              _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 170), v19)),
            v20);
    v22 = (__m128 *)((signed int)v18 >= v13 ? *(_QWORD *)&v6[304] + 16i64 * ((signed int)v18 - v13) : *(_QWORD *)&v6[48] + 16 * v18);
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
    if ( hkcdLineTriangleIntersect(v5, &vA, &vB, &vC, &tolerance, &fractionOut) )
      break;
    if ( ++index >= v7->m_startEdgeIndex + v7->m_numEdges - 1 )
      return 0;
  }
  result = 1;
  v4->m_origin = (hkVector4f)fractionOut.m_real;
  return result;
}

// File Line: 561
// RVA: 0xBC7D00
void __fastcall hkaiNavMeshUtils::calcEdgeMidpoint<hkaiNavMeshInstance>(hkaiNavMeshUtils *this, hkaiNavMeshInstance *mesh, __int64 edgeIndex, hkVector4f *midpointOut)
{
  __m128 *v4; // rbx
  hkVector4f edgeB; // [rsp+20h] [rbp-28h]
  hkVector4f edgeA; // [rsp+30h] [rbp-18h]

  v4 = (__m128 *)edgeIndex;
  hkaiNavMeshInstance::getEdgePoints((hkaiNavMeshInstance *)this, (int)mesh, &edgeA, &edgeB);
  *v4 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(edgeB.m_quad, edgeA.m_quad), (__m128)xmmword_141A711B0), edgeA.m_quad);
}

// File Line: 570
// RVA: 0xBC8B50
void __fastcall hkaiNavMeshUtils::calcVertexPlane<hkaiNavMeshInstance>(hkaiNavMeshUtils *this, hkaiNavMeshInstance *mesh, int faceIndex, __int64 edgeIndex, hkVector4f *normal)
{
  __m128 *v5; // r13
  hkaiNavMeshUtils *v6; // r14
  hkaiNavMesh::Face *v7; // rax
  int v8; // er11
  int v9; // er15
  int v10; // ebx
  hkaiNavMesh::Edge *v11; // r12
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v12; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v13; // r9
  hkaiNavMesh::Edge *v14; // rax
  __int64 v15; // rcx
  signed int v16; // edx
  hkaiNavMesh::Edge *v17; // r8
  __m128 *v18; // rcx
  __m128 v19; // xmm5
  __m128 v20; // xmm8
  __int64 v21; // rax
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

  v5 = (__m128 *)edgeIndex;
  v6 = this;
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
  v10 = v7->m_startEdgeIndex;
  v11 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
          *(hkaiNavMesh::Edge **)&v6[32],
          *(_DWORD *)&v6[40],
          (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&v6[256],
          (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&v6[288],
          (hkArray<int,hkContainerHeapAllocator> *)&v6[208],
          v7->m_startEdgeIndex + v8);
  v14 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
          *(hkaiNavMesh::Edge **)&v6[32],
          *(_DWORD *)&v6[40],
          v12,
          v13,
          (hkArray<int,hkContainerHeapAllocator> *)&v6[208],
          v10 + v9);
  v15 = v11->m_a;
  v16 = *(_DWORD *)&v6[56];
  v17 = v14;
  if ( (signed int)v15 >= v16 )
    v18 = (__m128 *)(*(_QWORD *)&v6[304] + 16i64 * ((signed int)v15 - v16));
  else
    v18 = (__m128 *)(*(_QWORD *)&v6[48] + 16 * v15);
  v19 = *(__m128 *)&v6[128];
  v20 = *(__m128 *)&v6[112];
  v21 = v11->m_b;
  v22 = *(__m128 *)&v6[144];
  v23 = *(__m128 *)&v6[160];
  v24 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 0), v20), _mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 85), v19)),
            _mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 170), v22)),
          v23);
  if ( (signed int)v21 >= v16 )
    v25 = (__m128 *)(*(_QWORD *)&v6[304] + 16i64 * ((signed int)v21 - v16));
  else
    v25 = (__m128 *)(*(_QWORD *)&v6[48] + 16 * v21);
  v26 = *v25;
  v27 = *v5;
  v28 = v17->m_a;
  v29 = _mm_shuffle_ps(v27, v27, 201);
  v30 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), v20), _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), v19)),
              _mm_mul_ps(_mm_shuffle_ps(v26, v26, 170), v22)),
            v23),
          v24);
  v31 = _mm_sub_ps(_mm_mul_ps(v30, v29), _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), *v5));
  v32 = _mm_shuffle_ps(v31, v31, 201);
  v33 = _mm_mul_ps(v32, v32);
  v34 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)), _mm_shuffle_ps(v33, v33, 170));
  v35 = _mm_rsqrt_ps(v34);
  v36 = _mm_mul_ps(
          v32,
          _mm_andnot_ps(
            _mm_cmpleps(v34, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v35, v34), v35)),
              _mm_mul_ps(*(__m128 *)_xmm, v35))));
  if ( (signed int)v28 >= v16 )
    v37 = (__m128 *)(*(_QWORD *)&v6[304] + 16i64 * ((signed int)v28 - v16));
  else
    v37 = (__m128 *)(*(_QWORD *)&v6[48] + 16 * v28);
  v38 = *v37;
  v39 = v17->m_b;
  v40 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), v20), _mm_mul_ps(_mm_shuffle_ps(v38, v38, 85), v19)),
            _mm_mul_ps(_mm_shuffle_ps(v38, v38, 170), v22)),
          v23);
  if ( (signed int)v39 >= v16 )
    v41 = (__m128 *)(*(_QWORD *)&v6[304] + 16i64 * ((signed int)v39 - v16));
  else
    v41 = (__m128 *)(*(_QWORD *)&v6[48] + 16 * v39);
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
              _mm_cmpleps(v46, (__m128)0i64),
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
            _mm_cmpleps(v50, (__m128)0i64),
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
char __fastcall hkaiNavMeshUtils::isPointOnFace(hkaiNavMeshInstance *meshInstance, int faceIndex, hkVector4f *faceNormal, hkVector4f *point, hkSimdFloat32 *tolerance)
{
  unsigned int v5; // ebp
  hkVector4f *v6; // r15
  int v7; // er12
  hkaiNavMeshInstance *v8; // rsi
  hkaiNavMesh::Face *v9; // rdi
  int v10; // ebx
  __m128 v11; // xmm2
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  hkVector4f *index; // [rsp+28h] [rbp-30h]
  hkVector4f faceNormala; // [rsp+30h] [rbp-28h]

  v5 = faceIndex;
  v6 = point;
  v7 = (signed int)faceNormal;
  v8 = meshInstance;
  v9 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
         meshInstance->m_originalFaces,
         meshInstance->m_numOriginalFaces,
         &meshInstance->m_instancedFaces,
         &meshInstance->m_ownedFaces,
         &meshInstance->m_faceMap,
         faceIndex);
  v10 = v9->m_startEdgeIndex;
  if ( v9->m_startEdgeIndex >= v9->m_startEdgeIndex + v9->m_numEdges )
    return 1;
  while ( 1 )
  {
    hkaiNavMeshUtils::calcEdgePlane<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)v8,
      (hkaiNavMeshInstance *)v5,
      v10,
      v7,
      &faceNormala,
      index);
    v11 = _mm_mul_ps(v6->m_quad, faceNormala.m_quad);
    v12 = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, faceNormala.m_quad), 196);
    v13 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 78), v12);
    if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 177)) + v13.m128_f32[0]) > tolerance->m_real.m128_f32[0] )
      break;
    if ( ++v10 >= v9->m_startEdgeIndex + v9->m_numEdges )
      return 1;
  }
  return 0;
}

// File Line: 623
// RVA: 0xBBFE70
__int64 __fastcall hkaiNavMeshUtils::isAwayFromBoundaryEdges(hkaiStreamingCollection *collection, hkaiNavMeshQueryMediator *mediator, hkVector4f *point, hkSimdFloat32 *radius)
{
  __m128 v4; // xmm2
  __m128 v5; // xmm0
  __m128 v6; // xmm2
  __m128 v7; // xmm0
  hkaiStreamingCollection *v8; // rdi
  hkBaseObjectVtbl *v9; // rax
  hkSimdFloat32 *v10; // rbx
  int v11; // er12
  float v12; // xmm8_4
  hkaiStreamingCollection::InstanceInfo *v13; // r8
  _DWORD *v14; // r13
  hkaiNavMeshInstance *v15; // rbx
  hkaiNavMesh::Face *v16; // rax
  int index; // edi
  int v18; // er15
  int v19; // ebp
  hkaiNavMesh::Edge *v20; // r14
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v21; // r9
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v22; // r8
  hkaiNavMesh::Edge *v23; // rax
  hkaiNavMesh::Edge *v24; // rax
  signed int v25; // edx
  __int64 v26; // rcx
  __m128 *v27; // rcx
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  __int64 v30; // rax
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
  _DWORD *v51; // [rsp+30h] [rbp-D8h]
  int v52; // [rsp+38h] [rbp-D0h]
  int v53; // [rsp+3Ch] [rbp-CCh]
  int v54; // [rsp+40h] [rbp-C8h]
  __int64 v55; // [rsp+48h] [rbp-C0h]
  __int128 v56; // [rsp+50h] [rbp-B8h]
  __int64 v57; // [rsp+60h] [rbp-A8h]
  __m128 v58; // [rsp+70h] [rbp-98h]
  __m128 v59; // [rsp+80h] [rbp-88h]
  hkaiStreamingCollection::InstanceInfo *i; // [rsp+118h] [rbp+10h]
  hkVector4f *v61; // [rsp+120h] [rbp+18h]

  v61 = point;
  v4 = point->m_quad;
  _mm_store_si128((__m128i *)&v56, (__m128i)0i64);
  v5 = v4;
  v6 = _mm_add_ps(v4, radius->m_real);
  v7 = _mm_sub_ps(v5, radius->m_real);
  v54 = 0;
  v55 = 0i64;
  v58 = v7;
  v57 = 0i64;
  v8 = collection;
  v59 = v6;
  v9 = mediator->vfptr;
  v10 = radius;
  v51 = 0i64;
  v52 = 0;
  v53 = 2147483648;
  ((void (__fastcall *)(hkaiNavMeshQueryMediator *, int *, _DWORD **))v9[3].__first_virtual_table_function__)(
    mediator,
    &v54,
    &v51);
  v11 = 0;
  v12 = v10->m_real.m128_f32[0] * v10->m_real.m128_f32[0];
  if ( v52 <= 0 )
  {
LABEL_18:
    v49 = 1;
  }
  else
  {
    v13 = v8->m_instances.m_data;
    v14 = v51;
    for ( i = v8->m_instances.m_data; ; v13 = i )
    {
      v15 = v13[*v14 >> 22].m_instancePtr;
      v16 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
              v15->m_originalFaces,
              v15->m_numOriginalFaces,
              &v15->m_instancedFaces,
              &v15->m_ownedFaces,
              &v15->m_faceMap,
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
    v19 = v15->m_numOriginalEdges;
    v20 = v15->m_originalEdges;
    v21 = &v15->m_ownedEdges;
    v22 = &v15->m_instancedEdges;
    while ( 1 )
    {
      v23 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(v20, v19, v22, v21, &v15->m_edgeMap, index);
      if ( v23->m_oppositeEdge == -1 || v23->m_flags.m_storage & 0x20 )
      {
        v24 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(v20, v19, v22, v21, &v15->m_edgeMap, index);
        v25 = v15->m_numOriginalVertices;
        v26 = v24->m_a;
        v27 = (__m128 *)((signed int)v26 >= v25 ? &v15->m_ownedVertices.m_data[(signed int)v26 - v25] : &v15->m_originalVertices[v26]);
        v28 = v15->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
        v29 = v15->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
        v30 = v24->m_b;
        v31 = v15->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
        v32 = v15->m_referenceFrame.m_transform.m_translation.m_quad;
        v33 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 0), v29),
                    _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 85), v28)),
                  _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 170), v31)),
                v32);
        v34 = (__m128 *)((signed int)v30 >= v25 ? &v15->m_ownedVertices.m_data[(signed int)v30 - v25] : &v15->m_originalVertices[v30]);
        v35 = *v34;
        v36 = _mm_mul_ps(_mm_shuffle_ps(v35, v35, 0), v29);
        v37 = v33;
        v38 = _mm_sub_ps(v33, v61->m_quad);
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
        v46 = _mm_cmpltps(v45, query.m_quad);
        v47 = _mm_sub_ps(
                v38,
                _mm_mul_ps(
                  _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v46, query.m_quad), _mm_and_ps(v45, v46))),
                  v39));
        v48 = _mm_mul_ps(v47, v47);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v48, v48, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v48, v48, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v48, v48, 170))) < v12 )
          break;
      }
      if ( ++index >= v18 )
        goto LABEL_15;
    }
    v49 = 0;
  }
  v52 = 0;
  if ( v53 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v51,
      4 * v53);
  return v49;
}

// File Line: 662
// RVA: 0xBC7F80
void __fastcall hkaiNavMeshUtils::calcFaceAabb<hkaiNavMeshInstance>(hkaiNavMeshUtils *this, hkaiNavMeshInstance *mesh, __int64 faceIndex, hkSimdFloat32 *extraRadius, hkAabb *aabbOut)
{
  __m128 v5; // xmm7
  hkSimdFloat32 *v6; // r13
  hkaiNavMeshUtils *v7; // rbx
  __m128 v8; // xmm6
  hkaiNavMesh::Face *v9; // rax
  int index; // esi
  int v11; // er12
  signed int v12; // edi
  int v13; // er14
  __m128 v14; // xmm8
  hkaiNavMesh::Edge *v15; // r15
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v16; // r9
  __m128 v17; // xmm9
  __m128 v18; // xmm10
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v19; // r8
  __m128 v20; // xmm11
  __int64 v21; // rcx
  __m128 *v22; // rax
  __m128 v23; // xmm2
  __m128 v24; // xmm6
  __m128 *v25; // [rsp+D0h] [rbp+18h]

  v25 = (__m128 *)faceIndex;
  v5 = (__m128)xmmword_141A712A0;
  v6 = extraRadius;
  v7 = this;
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
    v12 = *(_DWORD *)&v7[56];
    v13 = *(_DWORD *)&v7[40];
    v14 = *(__m128 *)&v7[128];
    v15 = *(hkaiNavMesh::Edge **)&v7[32];
    v16 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&v7[288];
    v17 = *(__m128 *)&v7[112];
    v18 = *(__m128 *)&v7[144];
    v19 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&v7[256];
    v20 = *(__m128 *)&v7[160];
    do
    {
      v21 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
              v15,
              v13,
              v19,
              v16,
              (hkArray<int,hkContainerHeapAllocator> *)&v7[208],
              index)->m_a;
      if ( (signed int)v21 >= v12 )
        v22 = (__m128 *)(*(_QWORD *)&v7[304] + 16i64 * ((signed int)v21 - v12));
      else
        v22 = (__m128 *)(*(_QWORD *)&v7[48] + 16 * v21);
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
  v24 = _mm_add_ps(v8, *v25);
  v6->m_real = _mm_sub_ps(v5, *v25);
  v6[1] = (hkSimdFloat32)v24;
}

// File Line: 678
// RVA: 0xBC0220
void __fastcall hkaiNavMeshUtils::calcMeshAabb(hkaiNavMesh *mesh, hkSimdFloat32 *extraRadius, hkAabb *aabbOut)
{
  hkSimdFloat32 *v3; // rbx
  hkAabb *v4; // rdi
  __m128 v5; // xmm1

  v3 = extraRadius;
  v4 = aabbOut;
  hkAabbUtil::calcAabb(mesh->m_vertices.m_data, mesh->m_vertices.m_size, aabbOut);
  v5 = v4->m_min.m_quad;
  v4->m_max.m_quad = _mm_add_ps(v4->m_max.m_quad, v3->m_real);
  v4->m_min.m_quad = _mm_sub_ps(v5, v3->m_real);
}

// File Line: 684
// RVA: 0xBC07C0
void __fastcall hkaiNavMeshUtils::createFaceIndexArray(hkaiNavMesh *mesh, hkArray<int,hkContainerTempAllocator> *faceIndices)
{
  int v2; // eax
  int v3; // ebx
  hkArray<int,hkContainerTempAllocator> *v4; // r14
  int v5; // esi
  int v6; // eax
  hkaiNavMesh *v7; // rbp
  int v8; // eax
  int v9; // er9
  __int64 v10; // rdx
  int *v11; // rdi
  __int64 v12; // rcx
  __int64 v13; // r9
  hkaiNavMesh::Face *v14; // rdi
  int v15; // eax
  int v16; // er8
  hkResult result; // [rsp+50h] [rbp+8h]

  v2 = faceIndices->m_capacityAndFlags;
  v3 = 0;
  v4 = faceIndices;
  faceIndices->m_size = 0;
  v5 = mesh->m_edges.m_size;
  v6 = v2 & 0x3FFFFFFF;
  v7 = mesh;
  if ( v6 < v5 )
  {
    v8 = 2 * v6;
    v9 = mesh->m_edges.m_size;
    if ( v5 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, faceIndices, v9, 4);
  }
  v10 = v4->m_size;
  v11 = &v4->m_data[v10];
  v12 = v5 - (signed int)v10;
  if ( v5 - (signed int)v10 > 0 )
  {
    while ( v12 )
    {
      *v11 = -1;
      ++v11;
      --v12;
    }
  }
  v4->m_size = v5;
  if ( v7->m_faces.m_size > 0 )
  {
    v13 = 0i64;
    while ( 1 )
    {
      v14 = &v7->m_faces.m_data[v13];
      v15 = v14->m_numUserEdges <= 0 ? v14->m_startEdgeIndex : v14->m_startUserEdgeIndex;
      if ( v15 != -1 )
        break;
LABEL_22:
      ++v3;
      ++v13;
      if ( v3 >= v7->m_faces.m_size )
        return;
    }
    while ( 1 )
    {
      v4->m_data[v15] = v3;
      v16 = v14->m_startUserEdgeIndex;
      if ( v15 >= v16 && v15 < v14->m_numUserEdges + v16 - 1 )
        goto LABEL_20;
      if ( v15 != v14->m_numUserEdges + v16 - 1 )
        break;
      v15 = v14->m_startEdgeIndex;
LABEL_21:
      if ( v15 == -1 )
        goto LABEL_22;
    }
    if ( v15 < v14->m_startEdgeIndex || v15 >= v14->m_numEdges + v14->m_startEdgeIndex - 1 )
      goto LABEL_22;
LABEL_20:
    ++v15;
    goto LABEL_21;
  }
}

// File Line: 700
// RVA: 0xBC08D0
void __fastcall hkaiNavMeshUtils::createOwnedFaceIndexArray(hkaiNavMeshInstance *meshInstance, hkArray<int,hkContainerTempAllocator> *faceIndices)
{
  int v2; // eax
  int v3; // esi
  hkArray<int,hkContainerTempAllocator> *v4; // r14
  int v5; // ebx
  int v6; // eax
  hkaiNavMeshInstance *v7; // rbp
  int v8; // eax
  int v9; // er9
  __int64 v10; // rdx
  int *v11; // rdi
  __int64 v12; // rcx
  __int64 v13; // r9
  hkaiNavMesh::Face *v14; // rdi
  int v15; // eax
  int v16; // er8
  hkResult result; // [rsp+50h] [rbp+8h]

  v2 = faceIndices->m_capacityAndFlags;
  v3 = 0;
  v4 = faceIndices;
  faceIndices->m_size = 0;
  v5 = meshInstance->m_ownedEdges.m_size;
  v6 = v2 & 0x3FFFFFFF;
  v7 = meshInstance;
  if ( v6 < v5 )
  {
    v8 = 2 * v6;
    v9 = meshInstance->m_ownedEdges.m_size;
    if ( v5 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, faceIndices, v9, 4);
  }
  v10 = v4->m_size;
  v11 = &v4->m_data[v10];
  v12 = v5 - (signed int)v10;
  if ( v5 - (signed int)v10 > 0 )
  {
    while ( v12 )
    {
      *v11 = -1;
      ++v11;
      --v12;
    }
  }
  v4->m_size = v5;
  if ( v7->m_ownedFaces.m_size > 0 )
  {
    v13 = 0i64;
    while ( 1 )
    {
      v14 = &v7->m_ownedFaces.m_data[v13];
      v15 = v14->m_numUserEdges <= 0 ? v14->m_startEdgeIndex : v14->m_startUserEdgeIndex;
      if ( v15 != -1 )
        break;
LABEL_22:
      ++v3;
      ++v13;
      if ( v3 >= v7->m_ownedFaces.m_size )
        return;
    }
    while ( 1 )
    {
      v4->m_data[v15 - (signed __int64)v7->m_numOriginalEdges] = v3;
      v16 = v14->m_startUserEdgeIndex;
      if ( v15 >= v16 && v15 < v14->m_numUserEdges + v16 - 1 )
        goto LABEL_20;
      if ( v15 != v14->m_numUserEdges + v16 - 1 )
        break;
      v15 = v14->m_startEdgeIndex;
LABEL_21:
      if ( v15 == -1 )
        goto LABEL_22;
    }
    if ( v15 < v14->m_startEdgeIndex || v15 >= v14->m_numEdges + v14->m_startEdgeIndex - 1 )
      goto LABEL_22;
LABEL_20:
    ++v15;
    goto LABEL_21;
  }
}

// File Line: 719
// RVA: 0xBC0A00
void __fastcall hkaiNavMeshUtils::createInstancedFaceIndexArray(hkaiNavMeshInstance *meshInstance, hkArray<int,hkContainerTempAllocator> *faceIndices)
{
  int v2; // eax
  int v3; // esi
  hkArray<int,hkContainerTempAllocator> *v4; // r14
  int v5; // ebx
  int v6; // eax
  hkaiNavMeshInstance *v7; // rbp
  int v8; // eax
  int v9; // er9
  int v10; // edx
  int *v11; // rdi
  __int64 v12; // rcx
  __int64 v13; // r9
  hkaiNavMesh::Face *v14; // rdi
  int v15; // eax
  __int64 v16; // rcx
  int v17; // er8
  hkResult result; // [rsp+50h] [rbp+8h]

  v2 = faceIndices->m_capacityAndFlags;
  v3 = 0;
  v4 = faceIndices;
  faceIndices->m_size = 0;
  v5 = meshInstance->m_ownedEdges.m_size;
  v6 = v2 & 0x3FFFFFFF;
  v7 = meshInstance;
  if ( v6 < v5 )
  {
    v8 = 2 * v6;
    v9 = meshInstance->m_ownedEdges.m_size;
    if ( v5 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, faceIndices, v9, 4);
  }
  v10 = v5 - v4->m_size;
  v11 = &v4->m_data[v4->m_size];
  v12 = v10;
  if ( v10 > 0 )
  {
    while ( v12 )
    {
      *v11 = -1;
      ++v11;
      --v12;
    }
  }
  v4->m_size = v5;
  if ( v7->m_instancedFaces.m_size > 0 )
  {
    v13 = 0i64;
    while ( 1 )
    {
      v14 = &v7->m_instancedFaces.m_data[v13];
      v15 = v14->m_numUserEdges <= 0 ? v14->m_startEdgeIndex : v14->m_startUserEdgeIndex;
      if ( v15 != -1 )
        break;
LABEL_24:
      ++v3;
      ++v13;
      if ( v3 >= v7->m_instancedFaces.m_size )
        return;
    }
    while ( 1 )
    {
      v16 = v7->m_numOriginalEdges;
      if ( v15 >= (signed int)v16 )
        v4->m_data[v15 - v16] = v3;
      v17 = v14->m_startUserEdgeIndex;
      if ( v15 >= v17 && v15 < v14->m_numUserEdges + v17 - 1 )
        goto LABEL_22;
      if ( v15 != v14->m_numUserEdges + v17 - 1 )
        break;
      v15 = v14->m_startEdgeIndex;
LABEL_23:
      if ( v15 == -1 )
        goto LABEL_24;
    }
    if ( v15 < v14->m_startEdgeIndex || v15 >= v14->m_numEdges + v14->m_startEdgeIndex - 1 )
      goto LABEL_24;
LABEL_22:
    ++v15;
    goto LABEL_23;
  }
}

// File Line: 755
// RVA: 0xBC7630
void __fastcall copyStructAndData_hkaiNavMesh::Edge_int_(hkaiNavMesh::Edge *dstT, int *dstData, hkaiNavMesh::Edge *srcT, const int *srcData, int dataStride)
{
  __int64 v5; // rcx
  signed __int64 v6; // r9
  int v7; // eax

  dstT->m_a = srcT->m_a;
  dstT->m_b = srcT->m_b;
  dstT->m_oppositeEdge = srcT->m_oppositeEdge;
  dstT->m_oppositeFace = srcT->m_oppositeFace;
  dstT->m_flags.m_storage = srcT->m_flags.m_storage;
  dstT->m_paddingByte = srcT->m_paddingByte;
  dstT->m_userEdgeCost.m_value = srcT->m_userEdgeCost.m_value;
  if ( dataStride == 1 )
  {
    *dstData = *srcData;
  }
  else
  {
    v5 = dataStride;
    if ( dataStride >= 1i64 )
    {
      v6 = (char *)srcData - (char *)dstData;
      do
      {
        v7 = *(int *)((char *)dstData + v6);
        ++dstData;
        *(dstData - 1) = v7;
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
  int dataStride; // er11
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
    v5 = &mesh->m_edgeData.m_data[(signed int)v4 * dataStride];
  copyStructAndData_hkaiNavMesh::Edge_int_(&mesh->m_edges.m_data[v4], v5, &mesh->m_edges.m_data[srcIdx], v6, dataStride);
}

// File Line: 766
// RVA: 0xBC76A0
void __fastcall copyFaceAndData(hkaiNavMesh *mesh, int dstIdx, int srcIdx)
{
  int dataStride; // er10
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
    v5 = &mesh->m_faceData.m_data[(signed int)v4 * dataStride];
  copyStructAndData_hkaiNavMesh::Face_int_(&mesh->m_faces.m_data[v4], v5, &mesh->m_faces.m_data[srcIdx], v6, dataStride);
}

// File Line: 771
// RVA: 0xBC0C00
hkResult *__fastcall hkaiNavMeshUtils::removeFaces(hkResult *result, hkaiNavMesh *mesh, hkArray<int,hkContainerTempAllocator> *facesToRemove, bool invalidateOppEdges)
{
  hkArray<int,hkContainerTempAllocator> *v4; // r12
  int v5; // er8
  bool v6; // di
  hkaiNavMesh *v7; // r14
  hkResult *v8; // r15
  __int64 v10; // rsi
  int v11; // er9
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // ebx
  __int64 v16; // r15
  hkaiNavMesh::Face *v17; // rdx
  signed int v18; // edi
  signed int v19; // er9
  int v20; // eax
  unsigned __int64 v21; // rdx
  __int16 v22; // r10
  __int16 v23; // r11
  hkaiNavMesh::Edge *v24; // r8
  unsigned int v25; // eax
  int v26; // edi
  unsigned int v27; // eax
  int v28; // er9
  int v29; // edi
  int v30; // eax
  int v31; // eax
  int v32; // er9
  int v33; // er9
  int v34; // er8
  int v35; // ebx
  hkResultEnum v36; // er13
  int v37; // edi
  __int32 v38; // ecx
  void *v39; // r8
  signed int v40; // eax
  int v41; // ecx
  int v42; // er9
  int v43; // edi
  __int64 v44; // rcx
  _DWORD *v45; // rdi
  int *v46; // r9
  int v47; // er8
  int *v48; // r12
  int v49; // ebx
  hkResultEnum v50; // er8
  signed int v51; // er13
  __int64 v52; // r15
  __int64 v53; // r10
  signed __int64 v54; // rdx
  __int16 v55; // ax
  signed int v56; // edx
  __m128i v57; // xmm3
  __m128i v58; // xmm2
  __m128i v59; // xmm1
  int v60; // eax
  __m128i v61; // xmm0
  __int64 v62; // rsi
  hkResultEnum v63; // er11
  signed __int64 v64; // rdi
  __int32 v65; // edx
  __int64 v66; // r8
  int v67; // edi
  int v68; // ecx
  __int64 v69; // r12
  int v70; // er15
  int *v71; // rbx
  int v72; // edi
  int v73; // er10
  __int64 v74; // r11
  hkaiNavMesh::Face *v75; // r8
  __int64 v76; // rax
  bool v77; // zf
  bool v78; // sf
  signed __int64 v79; // r9
  int v80; // edx
  int v81; // edi
  int v82; // edx
  signed int v83; // edi
  int v84; // er8
  hkResult v85; // [rsp+30h] [rbp-29h]
  hkResult resulta; // [rsp+34h] [rbp-25h]
  char *v87; // [rsp+38h] [rbp-21h]
  int v88; // [rsp+40h] [rbp-19h]
  int v89; // [rsp+44h] [rbp-15h]
  hkArray<int,hkContainerTempAllocator> faceIndices; // [rsp+48h] [rbp-11h]
  char *array; // [rsp+58h] [rbp-1h]
  int v92; // [rsp+60h] [rbp+7h]
  int v93; // [rsp+64h] [rbp+Bh]
  unsigned __int64 v94; // [rsp+68h] [rbp+Fh]
  __int64 v95; // [rsp+70h] [rbp+17h]
  int v96; // [rsp+78h] [rbp+1Fh]
  hkResult *v97; // [rsp+C0h] [rbp+67h]
  hkArray<int,hkContainerTempAllocator> *v98; // [rsp+D0h] [rbp+77h]

  v98 = facesToRemove;
  v97 = result;
  v4 = facesToRemove;
  v5 = facesToRemove->m_size;
  v6 = invalidateOppEdges;
  v7 = mesh;
  v8 = result;
  if ( !v5 )
  {
    result->m_enum = 0;
    return result;
  }
  if ( v5 > 1 )
    hkAlgorithm::quickSortRecursive<int,hkAlgorithm::less<int>>(v4->m_data, 0, v5 - 1, 0);
  v10 = 0i64;
  v11 = v4->m_size + 1;
  v12 = v4->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v12 >= v11 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v13 = 2 * v12;
    if ( v11 < v13 )
      v11 = v13;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4, v11, 4);
    if ( resulta.m_enum )
    {
      v8->m_enum = 1;
      return v8;
    }
  }
  if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4, 4);
  v4->m_data[v4->m_size] = -1;
  v14 = v4->m_size;
  v4->m_size = v14;
  if ( v6 )
  {
    v15 = 0;
    if ( v14 > 0 )
    {
      v16 = 0i64;
      while ( 1 )
      {
        v17 = &v7->m_faces.m_data[v4->m_data[v16]];
        v18 = v17->m_startEdgeIndex;
        v19 = v17->m_startUserEdgeIndex;
        LODWORD(v95) = *(_DWORD *)&v17->m_numEdges;
        v20 = *(_DWORD *)&v17->m_clusterIndex;
        v94 = __PAIR__(v19, v18);
        HIDWORD(v95) = v20;
        if ( SWORD1(v95) <= 0 )
          LODWORD(v21) = v18;
        else
          v21 = v94 >> 32;
        if ( (_DWORD)v21 != -1 )
          break;
LABEL_31:
        ++v15;
        ++v16;
        if ( v15 >= v4->m_size )
        {
          v8 = v97;
          goto LABEL_33;
        }
      }
      v22 = WORD1(v95);
      v23 = v95;
      while ( 1 )
      {
        v24 = v7->m_edges.m_data;
        v25 = v24[(signed int)v21].m_oppositeEdge;
        if ( v25 != -1 )
          *(_QWORD *)&v24[v25 & 0x3FFFFF].m_oppositeEdge = -1i64;
        if ( (signed int)v21 >= v19 && (signed int)v21 < v22 + v19 - 1 )
          goto LABEL_29;
        if ( (_DWORD)v21 != v22 + v19 - 1 )
          break;
        LODWORD(v21) = v18;
LABEL_30:
        if ( (_DWORD)v21 == -1 )
          goto LABEL_31;
      }
      if ( (signed int)v21 < v18 || (signed int)v21 >= v23 + v18 - 1 )
        goto LABEL_31;
LABEL_29:
      LODWORD(v21) = v21 + 1;
      goto LABEL_30;
    }
  }
LABEL_33:
  v26 = v7->m_faces.m_size;
  v27 = 2147483648;
  array = 0i64;
  v92 = 0;
  v93 = 2147483648;
  v87 = 0i64;
  v88 = 0;
  v89 = 2147483648;
  if ( v26 <= 0 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v28 = v26;
    if ( v26 < 0 )
      v28 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v28, 4);
    if ( resulta.m_enum )
      goto LABEL_43;
    v27 = v89;
  }
  v92 = v26;
  v29 = v7->m_edges.m_size;
  v30 = v27 & 0x3FFFFFFF;
  if ( v30 < v29 )
  {
    v31 = 2 * v30;
    v32 = v7->m_edges.m_size;
    if ( v29 < v31 )
      v32 = v31;
    hkArrayUtil::_reserve(&v85, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v87, v32, 4);
    if ( v85.m_enum )
    {
LABEL_43:
      v8->m_enum = 1;
LABEL_51:
      v88 = 0;
      if ( v89 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v87,
          4 * v89);
      v87 = 0i64;
      v89 = 2147483648;
      v92 = 0;
      if ( v93 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          4 * v93);
      return v8;
    }
  }
  v33 = v7->m_edges.m_size;
  v88 = v29;
  faceIndices.m_data = 0i64;
  faceIndices.m_size = 0;
  faceIndices.m_capacityAndFlags = 2147483648;
  if ( v33 > 0 )
  {
    if ( v33 < 0 )
      v33 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &faceIndices, v33, 4);
    if ( resulta.m_enum )
    {
      v34 = faceIndices.m_capacityAndFlags;
      v8->m_enum = 1;
      faceIndices.m_size = 0;
      if ( v34 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          faceIndices.m_data,
          4 * v34);
      faceIndices.m_data = 0i64;
      faceIndices.m_capacityAndFlags = 2147483648;
      goto LABEL_51;
    }
  }
  hkaiNavMeshUtils::createFaceIndexArray(v7, &faceIndices);
  v35 = v7->m_faces.m_size;
  v36 = 0;
  v85.m_enum = 0;
  v94 = 0i64;
  v37 = (v35 + 31) >> 5;
  v95 = 0x8000000000000000i64;
  v38 = v37;
  if ( v37 )
  {
    resulta.m_enum = 4 * v37;
    v39 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            (int *)&resulta);
    v38 = resulta.m_enum / 4;
  }
  else
  {
    v39 = 0i64;
  }
  v40 = 2147483648;
  v94 = (unsigned __int64)v39;
  if ( v38 )
    v40 = v38;
  LODWORD(v95) = (v35 + 31) >> 5;
  v96 = v35;
  HIDWORD(v95) = v40;
  v41 = v40 & 0x3FFFFFFF;
  if ( (v40 & 0x3FFFFFFF) < v37 )
  {
    v42 = (v35 + 31) >> 5;
    if ( v37 < 2 * v41 )
      v42 = 2 * v41;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v94, v42, 4);
    v40 = HIDWORD(v95);
  }
  LODWORD(v95) = (v35 + 31) >> 5;
  if ( !v94 )
  {
    v8->m_enum = 1;
    LODWORD(v95) = 0;
    if ( v40 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        0i64,
        4 * v40);
    v94 = 0i64;
    HIDWORD(v95) = 2147483648;
    faceIndices.m_size = 0;
    if ( faceIndices.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        faceIndices.m_data,
        4 * faceIndices.m_capacityAndFlags);
    faceIndices.m_data = 0i64;
    faceIndices.m_capacityAndFlags = 2147483648;
    v88 = 0;
    if ( v89 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v87,
        4 * v89);
    v87 = 0i64;
    v89 = 2147483648;
    v92 = 0;
    if ( v93 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        4 * v93);
    return v8;
  }
  v43 = v37 - 1;
  if ( v43 >= 0 )
  {
    v44 = (unsigned int)(v43 + 1);
    v45 = (_DWORD *)v94;
    while ( v44 )
    {
      *v45 = 0;
      ++v45;
      --v44;
    }
    v40 = HIDWORD(v95);
  }
  v46 = v4->m_data;
  v47 = 0;
  if ( v7->m_faces.m_size > 0 )
  {
    do
    {
      if ( v47 == *v46 )
      {
        *(_DWORD *)(v94 + 4 * ((signed __int64)v47 >> 5)) |= 1 << (v47 & 0x1F);
        ++v46;
      }
      ++v47;
    }
    while ( v47 < v7->m_faces.m_size );
    v40 = HIDWORD(v95);
  }
  v48 = faceIndices.m_data;
  v49 = 0;
  v50 = 0;
  resulta.m_enum = 0;
  if ( v7->m_edges.m_size > 0 )
  {
    do
    {
      v51 = 1;
      v52 = v50;
      v53 = faceIndices.m_data[v52];
      if ( (signed int)v53 >= 0 )
      {
        v54 = (signed __int64)&v7->m_faces.m_data[v53];
        if ( v7->m_edges.m_data[v50].m_flags.m_storage & 0x10 )
          v55 = *(_WORD *)(v54 + 10);
        else
          v55 = *(_WORD *)(v54 + 8);
        v51 = v55;
      }
      v56 = 0;
      v46 = 0i64;
      if ( v51 > 0 && (unsigned int)v51 >= 4 )
      {
        v57 = _mm_load_si128((const __m128i *)&_xmm);
        v58 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v85.m_enum), 0);
        v59 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v50), 0);
        do
        {
          v60 = v56 + v50;
          v61 = _mm_cvtsi32_si128(v56);
          v56 += 4;
          ++v46;
          _mm_storeu_si128(
            (__m128i *)&v87[4 * v60],
            _mm_sub_epi32(_mm_add_epi32(_mm_add_epi32(_mm_shuffle_epi32(v61, 0), v57), v59), v58));
        }
        while ( v56 < v51 - v51 % 4 );
      }
      v62 = v51;
      if ( (signed __int64)v46 >= v51 )
      {
        v63 = v85.m_enum;
      }
      else
      {
        v63 = v85.m_enum;
        v64 = 4i64 * ((_QWORD)v46 + (signed int)v50);
        v65 = v50 + v56 - v85.m_enum;
        v66 = v51 - (_QWORD)v46;
        do
        {
          v64 += 4i64;
          *(_DWORD *)&v87[v64 - 4] = v65++;
          --v66;
        }
        while ( v66 );
        v50 = resulta.m_enum;
      }
      if ( (signed int)v53 < 0 || (*(_DWORD *)(v94 + 4 * (v53 >> 5)) >> (v53 & 0x1F)) & 1 )
      {
        v85.m_enum = v51 + v63;
      }
      else if ( v51 > 0 )
      {
        v67 = v50 - v49;
        do
        {
          copyEdgeAndData(v7, v49, v67 + v49);
          ++v48;
          v68 = faceIndices.m_data[v52];
          ++v49;
          ++v52;
          *(v48 - 1) = v68;
          --v62;
        }
        while ( v62 );
        v50 = resulta.m_enum;
      }
      v50 += v51;
      v10 = 0i64;
      resulta.m_enum = v50;
    }
    while ( v50 < v7->m_edges.m_size );
    v40 = HIDWORD(v95);
    v36 = v85.m_enum;
  }
  v69 = (__int64)v98;
  v70 = 0;
  v71 = v98->m_data;
  v72 = 0;
  if ( v7->m_faces.m_size > 0 )
  {
    do
    {
      *(_DWORD *)&array[v10] = v72 - (unsigned __int64)(((signed __int64)v71 - *(_QWORD *)v69) >> 2);
      if ( v72 == *v71 )
        ++v71;
      else
        copyFaceAndData(v7, v70++, v72);
      ++v72;
      v10 += 4i64;
    }
    while ( v72 < v7->m_faces.m_size );
    v40 = HIDWORD(v95);
    LODWORD(v10) = 0;
  }
  LODWORD(v95) = v10;
  if ( v40 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, unsigned __int64, _QWORD, int *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v94,
      (unsigned int)(4 * v40),
      v46);
  hkaiNavMesh::setFacesSize(v7, (hkResult *)&v98, v7->m_faces.m_size - *(_DWORD *)(v69 + 8));
  hkaiNavMesh::setEdgesSize(v7, (hkResult *)&v98, v7->m_edges.m_size - v36);
  v73 = v10;
  if ( v7->m_faces.m_size > 0 )
  {
    v74 = 0i64;
    while ( 1 )
    {
      v75 = &v7->m_faces.m_data[v74];
      v76 = v75->m_startUserEdgeIndex;
      v75->m_startEdgeIndex = *(_DWORD *)&v87[4 * v75->m_startEdgeIndex];
      if ( (signed int)v76 >= 0 )
        LODWORD(v76) = *(_DWORD *)&v87[4 * v76];
      v77 = v75->m_numUserEdges == 0;
      v78 = v75->m_numUserEdges < 0;
      v75->m_startUserEdgeIndex = v76;
      if ( v78 || v77 )
        LODWORD(v76) = v75->m_startEdgeIndex;
      if ( (_DWORD)v76 != -1 )
        break;
LABEL_134:
      ++v73;
      ++v74;
      if ( v73 >= v7->m_faces.m_size )
        goto LABEL_135;
    }
    while ( 1 )
    {
      v79 = (signed __int64)&v7->m_edges.m_data[(signed int)v76];
      v80 = *(_DWORD *)(v79 + 8);
      if ( v80 != -1 )
      {
        v81 = *(_DWORD *)&v87[4 * (v80 & 0x3FFFFF)];
        v82 = *(_DWORD *)&array[4 * (*(_DWORD *)(v79 + 12) & 0x3FFFFF)];
        *(_DWORD *)(v79 + 8) = v81;
        *(_DWORD *)(v79 + 12) = v82;
      }
      v83 = v75->m_startUserEdgeIndex;
      if ( (signed int)v76 >= v83 && (signed int)v76 < v75->m_numUserEdges + v83 - 1 )
        goto LABEL_132;
      if ( (_DWORD)v76 != v75->m_numUserEdges + v83 - 1 )
        break;
      LODWORD(v76) = v75->m_startEdgeIndex;
LABEL_133:
      if ( (_DWORD)v76 == -1 )
        goto LABEL_134;
    }
    if ( (signed int)v76 < v75->m_startEdgeIndex || (signed int)v76 >= v75->m_numEdges + v75->m_startEdgeIndex - 1 )
      goto LABEL_134;
LABEL_132:
    LODWORD(v76) = v76 + 1;
    goto LABEL_133;
  }
LABEL_135:
  v84 = faceIndices.m_capacityAndFlags;
  faceIndices.m_size = v10;
  v97->m_enum = v10;
  if ( v84 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      faceIndices.m_data,
      4 * v84);
  faceIndices.m_data = 0i64;
  faceIndices.m_capacityAndFlags = 2147483648;
  v88 = 0;
  if ( v89 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v87,
      4 * v89);
  v87 = 0i64;
  v89 = 2147483648;
  v92 = 0;
  if ( v93 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v93);
  return v97;
}

// File Line: 952
// RVA: 0xBC3140
void __fastcall hkaiNavMeshUtils::compactClearanceCache(hkaiNavMeshInstance *meshInstance)
{
  _BYTE *v1; // r8
  hkArray<hkHalf,hkContainerHeapAllocator> *v2; // r14
  hkaiNavMeshInstance *v3; // rbx
  int v4; // eax
  __int64 v5; // rdx
  _WORD *v6; // rcx
  signed __int64 v7; // rdi
  __int16 v8; // ax
  __int64 v9; // r12
  hkArray<int,hkContainerHeapAllocator> *v10; // rbp
  int v11; // esi
  int v12; // eax
  int v13; // eax
  int v14; // er9
  int v15; // edx
  int *v16; // rdi
  __int64 v17; // rcx
  int index; // er13
  __int64 v19; // r15
  hkArray<int,hkContainerHeapAllocator> *v20; // rax
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v21; // rcx
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v22; // rdx
  int v23; // ecx
  __int64 v24; // r11
  int *v25; // rax
  __int64 v26; // rbp
  int v27; // esi
  __int64 v28; // rdi
  int v29; // er9
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
  signed __int64 v40; // rdi
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v41; // r8
  hkaiNavMesh::Face *v42; // rax
  int v43; // ecx
  int v44; // eax
  int v45; // er9
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // er9
  int v50; // edx
  hkHalf *v51; // rdi
  __int64 v52; // rcx
  int v53; // eax
  _BYTE *v54; // [rsp+30h] [rbp-58h]
  int v55; // [rsp+90h] [rbp+8h]
  int v56; // [rsp+98h] [rbp+10h]
  hkResult result; // [rsp+A0h] [rbp+18h]

  v1 = 0i64;
  v2 = &meshInstance->m_clearanceCache;
  v3 = meshInstance;
  v4 = meshInstance->m_clearanceCache.m_size;
  v54 = 0i64;
  v56 = 2147483648;
  if ( v4 > 0 )
  {
    v55 = 2 * v4;
    v1 = (_BYTE *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                    &v55);
    v54 = v1;
    v56 = v55 / 2;
  }
  v5 = v2->m_size;
  if ( v5 > 0 )
  {
    v6 = v1;
    v7 = (char *)v2->m_data - v1;
    do
    {
      v8 = *(_WORD *)((char *)v6 + v7);
      ++v6;
      *(v6 - 1) = v8;
      --v5;
    }
    while ( v5 );
  }
  v9 = v3->m_faceClearanceIndices.m_size;
  v10 = &v3->m_faceClearanceIndices;
  v11 = v3->m_numOriginalFaces + v3->m_ownedFaces.m_size;
  v3->m_clearanceCache.m_size = 0;
  v12 = v3->m_faceClearanceIndices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v12 < v11 )
  {
    v13 = 2 * v12;
    v14 = v11;
    if ( v11 < v13 )
      v14 = v13;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v3->m_faceClearanceIndices,
      v14,
      4);
  }
  v15 = v11 - v3->m_faceClearanceIndices.m_size;
  v16 = &v3->m_faceClearanceIndices.m_data[v3->m_faceClearanceIndices.m_size];
  v17 = v15;
  if ( v15 > 0 )
  {
    while ( v17 )
    {
      *v16 = -1;
      ++v16;
      --v17;
    }
  }
  index = 0;
  v19 = 0i64;
  v3->m_faceClearanceIndices.m_size = v11;
  if ( (signed int)v9 > 0 )
  {
    v20 = &v3->m_faceMap;
    v21 = &v3->m_ownedFaces;
    v22 = &v3->m_instancedFaces;
    do
    {
      v23 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
              v3->m_originalFaces,
              v3->m_numOriginalFaces,
              v22,
              v21,
              v20,
              index)->m_numEdges;
      v25 = v3->m_faceClearanceIndices.m_data;
      v26 = v25[v19];
      v27 = 3 * (v23 - 2);
      v25[v19] = v3->m_clearanceCache.m_size;
      v28 = v2->m_size;
      v29 = v27 + v28;
      v30 = v2->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v30 >= v27 + (signed int)v28 )
      {
        result.m_enum = 0;
      }
      else
      {
        v31 = 2 * v30;
        if ( v29 < v31 )
          v29 = v31;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, v29, 2);
        v24 = v9;
      }
      v32 = v2->m_data;
      v2->m_size += v27;
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
      v20 = &v3->m_faceMap;
      v21 = &v3->m_ownedFaces;
      v22 = &v3->m_instancedFaces;
    }
    while ( v19 < v24 );
    v10 = &v3->m_faceClearanceIndices;
  }
  v37 = v3->m_clearanceCache.m_size;
  if ( (signed int)v9 < v3->m_numOriginalFaces + v3->m_ownedFaces.m_size )
  {
    v38 = &v3->m_faceMap;
    v39 = &v3->m_ownedFaces;
    v40 = (signed int)v9;
    v41 = &v3->m_instancedFaces;
    do
    {
      v42 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(v3->m_originalFaces, v3->m_numOriginalFaces, v41, v39, v38, v9);
      LODWORD(v9) = v9 + 1;
      v43 = v42->m_numEdges;
      ++v40;
      v10->m_data[v40 - 1] = v37;
      v37 += 3 * (v43 - 2);
    }
    while ( (signed int)v9 < v3->m_numOriginalFaces + v3->m_ownedFaces.m_size );
  }
  v44 = v2->m_capacityAndFlags & 0x3FFFFFFF;
  v45 = (v37 + 7) & 0xFFFFFFF8;
  if ( v44 < v45 )
  {
    v46 = 2 * v44;
    if ( v45 < v46 )
      v45 = v46;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, v45, 2);
  }
  v47 = v2->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v47 < v37 )
  {
    v48 = 2 * v47;
    v49 = v37;
    if ( v37 < v48 )
      v49 = v48;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, v49, 2);
  }
  v50 = v37 - v2->m_size;
  v51 = &v2->m_data[v2->m_size];
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
  v2->m_size = v37;
  if ( v53 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v54,
      2 * (v53 & 0x3FFFFFFF));
}

// File Line: 1010
// RVA: 0xBC30D0
void __fastcall hkaiNavMeshUtils::compactOwnedEdges(hkaiNavMeshInstance *meshInstance, hkaiStreamingCollection *collection)
{
  hkArray<int,hkContainerTempAllocator> facesToRemove; // [rsp+20h] [rbp-18h]

  facesToRemove.m_data = 0i64;
  facesToRemove.m_size = 0;
  facesToRemove.m_capacityAndFlags = 2147483648;
  hkaiNavMeshUtils::removeOwnedFaces(meshInstance, collection, &facesToRemove, 0);
  facesToRemove.m_size = 0;
  if ( facesToRemove.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      facesToRemove.m_data,
      4 * facesToRemove.m_capacityAndFlags);
}

// File Line: 1017
// RVA: 0xBC1580
void __fastcall hkaiNavMeshUtils::removeOwnedFaces(hkaiNavMeshInstance *meshInstance, hkaiStreamingCollection *collection, hkArray<int,hkContainerTempAllocator> *facesToRemove, hkaiNavMeshUtils::RemoveOwnedFacesMode mode)
{
  hkArray<int,hkContainerTempAllocator> *v4; // r14
  hkaiNavMeshInstance *v5; // rbx
  _QWORD *v6; // rdi
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  signed __int64 v9; // rcx
  signed int v10; // er8
  int v11; // eax
  unsigned int v12; // er12
  signed __int64 v13; // rcx
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // rdx
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v15; // rdi
  hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *v16; // r8
  hkaiNavMesh::Face *v17; // rax
  signed int v18; // esi
  signed int v19; // er14
  unsigned __int64 index; // rdi
  __int16 v21; // r15
  __int16 v22; // r12
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v23; // r9
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v24; // rax
  hkaiNavMesh::Edge *v25; // rax
  unsigned int v26; // edx
  signed int v27; // eax
  hkaiNavMeshInstance *v28; // r8
  int v29; // eax
  int v30; // edx
  signed __int64 v31; // rcx
  hkaiNavMesh::Edge *v32; // rax
  signed __int64 v33; // rdx
  bool v34; // sf
  unsigned __int8 v35; // of
  __int64 v36; // r13
  int v37; // er15
  int v38; // esi
  int v39; // er9
  int v40; // er9
  unsigned int *v41; // rax
  int v42; // edi
  hkLifoAllocator *v43; // rax
  unsigned int *v44; // rcx
  int v45; // edx
  char *v46; // r8
  signed int v47; // eax
  int v48; // eax
  int v49; // er9
  int v50; // eax
  unsigned int *v51; // rdi
  __int64 i; // rcx
  int *v53; // r9
  signed int v54; // edi
  signed int v55; // edx
  __int64 v56; // r8
  int v57; // esi
  signed int v58; // er14
  signed int v59; // er12
  __int64 v60; // rcx
  signed __int64 v61; // r8
  __int64 v62; // rdx
  signed __int64 v63; // r10
  hkaiNavMesh::Edge *v64; // rax
  char v65; // al
  signed __int64 v66; // r15
  __int16 v67; // ax
  __int16 v68; // ax
  signed int v69; // edx
  signed __int64 v70; // r9
  unsigned int v71; // er11
  __m128i v72; // xmm3
  __m128i v73; // xmm1
  __m128i v74; // xmm2
  int v75; // eax
  __m128i v76; // xmm0
  __int64 v77; // r13
  int v78; // edx
  signed __int64 v79; // rcx
  signed __int64 v80; // rdi
  __int16 v81; // r12
  int v82; // edi
  bool v83; // zf
  signed int j; // edi
  int v85; // er15
  int *v86; // r14
  int v87; // edi
  __int64 v88; // rsi
  __int64 v89; // r12
  int v90; // er8
  __int64 v91; // rdi
  hkaiNavMesh::Face *v92; // rdx
  __int64 v93; // rax
  int v94; // edi
  __int64 v95; // rdx
  hkaiNavMesh::Face *v96; // r8
  __int64 v97; // rax
  int v98; // esi
  int v99; // eax
  int v100; // er9
  _DWORD *v101; // rdi
  __int64 v102; // rcx
  __int64 v103; // r8
  int v104; // edi
  __int64 k; // rdx
  __int64 v106; // rcx
  int v107; // esi
  __int64 v108; // r13
  __int64 v109; // r11
  int v110; // er14
  int v111; // edx
  __int64 v112; // rcx
  int v113; // er15
  hkaiNavMesh::Edge *v114; // r8
  int v115; // edx
  char v116; // cl
  unsigned int v117; // eax
  int v118; // edi
  unsigned int v119; // eax
  int v120; // edi
  hkaiNavMeshInstance *v121; // rsi
  int v122; // eax
  signed __int64 v123; // rcx
  hkaiNavMesh::Edge *v124; // rax
  signed __int64 v125; // rdx
  _QWORD *v126; // rax
  _QWORD *v127; // rcx
  _QWORD *v128; // rdi
  unsigned __int64 v129; // rax
  signed __int64 v130; // rcx
  int v131; // edx
  int v132; // edi
  int v133; // ecx
  int v134; // er9
  signed __int64 v135; // rdx
  int v136; // ecx
  int v137; // eax
  signed __int64 v138; // rdx
  bool v139; // [rsp+30h] [rbp-D0h]
  unsigned int v140; // [rsp+34h] [rbp-CCh]
  int v141; // [rsp+38h] [rbp-C8h]
  char v142; // [rsp+38h] [rbp-C8h]
  hkResult result[2]; // [rsp+40h] [rbp-C0h]
  int v144; // [rsp+48h] [rbp-B8h]
  _DWORD *v145; // [rsp+50h] [rbp-B0h]
  int v146; // [rsp+58h] [rbp-A8h]
  int v147; // [rsp+5Ch] [rbp-A4h]
  __int64 v148; // [rsp+60h] [rbp-A0h]
  _DWORD *v149; // [rsp+68h] [rbp-98h]
  int v150; // [rsp+70h] [rbp-90h]
  int v151; // [rsp+74h] [rbp-8Ch]
  int v152; // [rsp+78h] [rbp-88h]
  _DWORD *array; // [rsp+80h] [rbp-80h]
  int v154; // [rsp+88h] [rbp-78h]
  int v155; // [rsp+8Ch] [rbp-74h]
  hkArray<int,hkContainerTempAllocator> faceIndices; // [rsp+90h] [rbp-70h]
  hkArray<int,hkContainerTempAllocator> v157; // [rsp+A0h] [rbp-60h]
  unsigned __int64 v158; // [rsp+B0h] [rbp-50h]
  __int64 v159; // [rsp+B8h] [rbp-48h]
  __int64 v160; // [rsp+C0h] [rbp-40h]
  hkBitFieldStorage<hkLocalArray<unsigned int> > v161; // [rsp+C8h] [rbp-38h]
  hkaiStreamingCollection *v162; // [rsp+138h] [rbp+38h]
  hkArray<int,hkContainerTempAllocator> *v163; // [rsp+140h] [rbp+40h]
  int v164; // [rsp+140h] [rbp+40h]

  v163 = facesToRemove;
  v162 = collection;
  v4 = facesToRemove;
  v5 = meshInstance;
  if ( !facesToRemove->m_size && mode == 1 )
    return;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtremoveOwnedFaces";
    v8 = __rdtsc();
    v9 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v9 - 8) = v8;
    v6[1] = v9;
  }
  v10 = v4->m_size;
  v139 = v10 == 0;
  if ( v10 > 1 )
    hkAlgorithm::quickSortRecursive<int,hkAlgorithm::less<int>>(v4->m_data, 0, v10 - 1, 0);
  if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4, 4);
  v4->m_data[v4->m_size] = -1;
  v11 = v4->m_size;
  v12 = 0;
  v4->m_size = v11;
  v141 = 0;
  if ( v11 > 0 )
  {
    v13 = 0i64;
    instanceMap = &v5->m_faceMap;
    v15 = &v5->m_ownedFaces;
    *(_QWORD *)&result[0].m_enum = 0i64;
    v16 = &v5->m_instancedFaces;
    while ( 1 )
    {
      v17 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
              v5->m_originalFaces,
              v5->m_numOriginalFaces,
              v16,
              v15,
              instanceMap,
              *(int *)((char *)v4->m_data + v13));
      v18 = v17->m_startEdgeIndex;
      v19 = v17->m_startUserEdgeIndex;
      v159 = *(_QWORD *)&v17->m_numEdges;
      v158 = __PAIR__(v19, v18);
      if ( SWORD1(v159) <= 0 )
        LODWORD(index) = v18;
      else
        index = v158 >> 32;
      if ( (_DWORD)index != -1 )
        break;
LABEL_43:
      v4 = v163;
      v13 = *(_QWORD *)&result[0].m_enum + 4i64;
      instanceMap = &v5->m_faceMap;
      v35 = __OFSUB__(v141 + 1, v163->m_size);
      v34 = v141++ + 1 - v163->m_size < 0;
      v15 = &v5->m_ownedFaces;
      *(_QWORD *)&result[0].m_enum += 4i64;
      if ( !(v34 ^ v35) )
      {
        v12 = 0;
        goto LABEL_45;
      }
    }
    v21 = WORD1(v159);
    v22 = v159;
    v23 = &v5->m_ownedEdges;
    v24 = &v5->m_instancedEdges;
    while ( 1 )
    {
      v25 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
              v5->m_originalEdges,
              v5->m_numOriginalEdges,
              v24,
              v23,
              &v5->m_edgeMap,
              index);
      v26 = v25->m_oppositeEdge;
      if ( v26 != -1 )
        break;
LABEL_34:
      if ( (signed int)index >= v19 && (signed int)index < v21 + v19 - 1 )
        goto LABEL_40;
      if ( (_DWORD)index != v21 + v19 - 1 )
      {
        if ( (signed int)index < v18 || (signed int)index >= v22 + v18 - 1 )
        {
LABEL_42:
          v16 = &v5->m_instancedFaces;
          goto LABEL_43;
        }
LABEL_40:
        LODWORD(index) = index + 1;
        goto LABEL_41;
      }
      LODWORD(index) = v18;
LABEL_41:
      v24 = &v5->m_instancedEdges;
      if ( (_DWORD)index == -1 )
        goto LABEL_42;
    }
    if ( v25->m_flags.m_storage & 0x40 )
      v27 = v26 >> 22;
    else
      v27 = v5->m_runtimeId;
    if ( v162 )
    {
      if ( v26 == -1 )
        v27 = -1;
      v28 = v162->m_instances.m_data[v27].m_instancePtr;
    }
    else
    {
      v28 = v5;
    }
    v29 = v28->m_numOriginalEdges;
    v30 = v26 & 0x3FFFFF;
    if ( v30 < v29 )
    {
      if ( v28->m_edgeMap.m_size )
        v30 = v28->m_edgeMap.m_data[v30];
      if ( v30 == -1 )
      {
        v33 = 0i64;
LABEL_33:
        *(_DWORD *)(v33 + 12) = -1;
        *(_DWORD *)(v33 + 8) = -1;
        goto LABEL_34;
      }
      v31 = v30;
      v32 = v28->m_instancedEdges.m_data;
    }
    else
    {
      v31 = v30 - v29;
      v32 = v28->m_ownedEdges.m_data;
    }
    v33 = (signed __int64)&v32[v31];
    goto LABEL_33;
  }
LABEL_45:
  LODWORD(v36) = v5->m_ownedFaces.m_size;
  v37 = v5->m_ownedEdges.m_size;
  v38 = v5->m_numOriginalFaces;
  v152 = v36;
  LODWORD(v148) = v37;
  array = 0i64;
  v154 = 0;
  v155 = 2147483648;
  if ( (signed int)v36 > 0 )
  {
    v39 = v36;
    if ( (signed int)v36 < 0 )
      v39 = 0;
    hkArrayUtil::_reserve(result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v39, 4);
  }
  v154 = v36;
  v145 = 0i64;
  v146 = 0;
  v147 = 2147483648;
  if ( v37 > 0 )
  {
    v40 = v37;
    if ( v37 < 0 )
      v40 = 0;
    hkArrayUtil::_reserve(result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v145, v40, 4);
  }
  v146 = v37;
  faceIndices.m_data = 0i64;
  faceIndices.m_size = 0;
  faceIndices.m_capacityAndFlags = 2147483648;
  hkaiNavMeshUtils::createOwnedFaceIndexArray(v5, &faceIndices);
  v157.m_data = 0i64;
  v157.m_size = 0;
  v157.m_capacityAndFlags = 2147483648;
  hkaiNavMeshUtils::createInstancedFaceIndexArray(v5, &v157);
  v41 = 0i64;
  v42 = ((signed int)v36 + 31) >> 5;
  v140 = 0;
  v161.m_words.m_data = 0i64;
  v161.m_words.m_size = 0;
  v161.m_words.m_capacityAndFlags = 2147483648;
  v161.m_words.m_initialCapacity = v42;
  if ( !v42 )
    goto LABEL_58;
  v43 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v44 = (unsigned int *)v43->m_cur;
  v45 = (4 * v42 + 127) & 0xFFFFFF80;
  v46 = (char *)v44 + v45;
  if ( v45 > v43->m_slabSize || v46 > v43->m_end )
  {
    v41 = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v43, v45);
LABEL_58:
    v44 = v41;
    goto LABEL_59;
  }
  v43->m_cur = v46;
LABEL_59:
  v161.m_words.m_data = v44;
  v161.m_words.m_localMemory = v44;
  v161.m_numBits = v36;
  v161.m_words.m_capacityAndFlags = v42 | 0x80000000;
  v47 = (v42 | 0x80000000) & 0x3FFFFFFF;
  if ( v47 < v42 )
  {
    v48 = 2 * v47;
    v49 = ((signed int)v36 + 31) >> 5;
    if ( v42 < v48 )
      v49 = v48;
    hkArrayUtil::_reserve(result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v161, v49, 4);
  }
  v50 = v42 - 1;
  v161.m_words.m_size = ((signed int)v36 + 31) >> 5;
  if ( v42 - 1 >= 0 )
  {
    v51 = v161.m_words.m_data;
    for ( i = (unsigned int)(v50 + 1); i; --i )
    {
      *v51 = 0;
      ++v51;
    }
  }
  v53 = v4->m_data;
  if ( !v139 )
  {
    v54 = 0;
    v55 = 1;
    if ( (signed int)v36 > 0 )
    {
      v56 = 0i64;
      do
      {
        if ( v54 + v38 == *v53 )
        {
          v161.m_words.m_data[v56 >> 5] |= v55;
          ++v53;
        }
        v55 = __ROL4__(v55, 1);
        ++v54;
        ++v56;
      }
      while ( v54 < (signed int)v36 );
    }
  }
  v57 = 0;
  v58 = 0;
  if ( v37 > 0 )
  {
    while ( 1 )
    {
      v59 = 1;
      v60 = faceIndices.m_data[v58];
      v61 = 4i64 * v58;
      v62 = *(int *)((char *)v157.m_data + v61);
      v160 = 4i64 * v58;
      v63 = 20i64 * v58;
      v64 = v5->m_ownedEdges.m_data;
      v144 = 1;
      v65 = *(&v64->m_flags.m_storage + v63);
      v142 = 1;
      v66 = 0i64;
      v158 = 20i64 * v58;
      result[0].m_enum = v65 & 0x10;
      if ( (signed int)v60 < 0 )
      {
        if ( (signed int)v62 < 0 )
          goto LABEL_85;
        v66 = (signed __int64)&v5->m_instancedFaces.m_data[v62];
        if ( v65 & 0x10 )
          v68 = *(_WORD *)(v66 + 10);
        else
          v68 = *(_WORD *)(v66 + 8);
        v59 = v68;
        v142 = 0;
      }
      else
      {
        v66 = (signed __int64)&v5->m_ownedFaces.m_data[v60];
        if ( v65 & 0x10 )
          v67 = *(_WORD *)(v66 + 10);
        else
          v67 = *(_WORD *)(v66 + 8);
        v59 = v67;
        v142 = (v161.m_words.m_data[v60 >> 5] >> (v60 & 0x1F)) & 1;
      }
      v144 = v59;
LABEL_85:
      v69 = 0;
      v70 = 0i64;
      v71 = v140;
      if ( v59 > 0 && (unsigned int)v59 >= 4 )
      {
        v72 = _mm_load_si128((const __m128i *)&_xmm);
        v69 = 0;
        v70 = 0i64;
        v73 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v58), 0);
        v74 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v140), 0);
        do
        {
          v75 = v69 + v58;
          v76 = _mm_cvtsi32_si128(v69);
          v69 += 4;
          v70 += 4i64;
          _mm_storeu_si128(
            (__m128i *)&v145[v75],
            _mm_sub_epi32(_mm_add_epi32(_mm_add_epi32(_mm_shuffle_epi32(v76, 0), v72), v73), v74));
        }
        while ( v69 < v59 - v59 % 4 );
      }
      v77 = v59;
      if ( v70 < v59 )
      {
        v78 = v58 + v69 - v140;
        v79 = v70 + v58;
        v80 = v59 - v70;
        do
        {
          ++v79;
          v145[v79 - 1] = v78++;
          --v80;
        }
        while ( v80 );
      }
      if ( v142 )
      {
        v140 += v59;
      }
      else if ( result[0].m_enum )
      {
        v81 = 0;
        v82 = 0;
        if ( v77 > 0 )
        {
          do
          {
            *(_DWORD *)((char *)v145 + v61) = v58 + v82 - v71;
            if ( *(unsigned int *)((char *)&v5->m_ownedEdges.m_data->m_oppositeEdge + v63) == -1 )
            {
              ++v71;
              ++v81;
              v140 = v71;
            }
            else
            {
              hkaiNavMeshInstance::copyOwnedEdge(v5, v57, v82 + v58);
              v61 = v160;
              v63 = v158;
              v71 = v140;
              ++v57;
            }
            v61 += 4i64;
            v63 += 20i64;
            ++v82;
            v160 = v61;
            v158 = v63;
            --v77;
          }
          while ( v77 );
        }
        v83 = *(_WORD *)(v66 + 10) == v81;
        *(_WORD *)(v66 + 10) -= v81;
        v59 = v144;
        if ( v83 )
          *(_DWORD *)(v66 + 4) = -1;
      }
      else
      {
        for ( j = 0; j < v59; ++v57 )
          hkaiNavMeshInstance::copyOwnedEdge(v5, v57, j++ + v58);
      }
      v58 += v59;
      if ( v58 >= (signed int)v148 )
      {
        v12 = v140;
        LODWORD(v36) = v152;
        break;
      }
    }
  }
  v85 = 0;
  v86 = v163->m_data;
  if ( !v139 )
  {
    v36 = (signed int)v36;
    v87 = 0;
    v88 = 0i64;
    if ( (signed int)v36 > 0i64 )
    {
      do
      {
        array[v88] = v87 - (unsigned __int64)(v86 - v163->m_data);
        if ( v87 + v5->m_numOriginalFaces == *v86 )
          ++v86;
        else
          hkaiNavMeshInstance::copyOwnedFace(v5, v85++, v87);
        ++v88;
        ++v87;
      }
      while ( v88 < v36 );
      v12 = v140;
    }
  }
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>(&v161);
  hkaiNavMeshInstance::setNumOwnedFaces(v5, v152 - v163->m_size);
  hkaiNavMeshInstance::setNumOwnedEdges(v5, v148 - v12);
  v89 = v5->m_numOriginalEdges;
  v164 = v5->m_numOriginalFaces;
  v90 = 0;
  if ( v5->m_ownedFaces.m_size > 0 )
  {
    v91 = 0i64;
    do
    {
      v92 = &v5->m_ownedFaces.m_data[v91];
      v92->m_startEdgeIndex = v89 + v145[v92->m_startEdgeIndex - v89];
      v93 = v92->m_startUserEdgeIndex;
      if ( (signed int)v93 >= 0 )
        LODWORD(v93) = v89 + v145[v93 - v89];
      ++v90;
      v92->m_startUserEdgeIndex = v93;
      ++v91;
    }
    while ( v90 < v5->m_ownedFaces.m_size );
  }
  v94 = 0;
  if ( v5->m_instancedFaces.m_size > 0 )
  {
    v95 = 0i64;
    do
    {
      v96 = v5->m_instancedFaces.m_data;
      v97 = v96[v95].m_startUserEdgeIndex;
      if ( (signed int)v97 >= (signed int)v89 )
        LODWORD(v97) = v89 + v145[v97 - v89];
      v96[v95].m_startUserEdgeIndex = v97;
      ++v94;
      ++v95;
    }
    while ( v94 < v5->m_instancedFaces.m_size );
  }
  hkaiNavMeshUtils::createOwnedFaceIndexArray(v5, &faceIndices);
  hkaiNavMeshUtils::createInstancedFaceIndexArray(v5, &v157);
  v98 = v5->m_instancedFaces.m_size;
  v99 = 0;
  v149 = 0i64;
  v150 = 0;
  v151 = 2147483648;
  if ( v98 > 0 )
  {
    v100 = v98;
    if ( v98 < 0 )
      v100 = 0;
    hkArrayUtil::_reserve(result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v149, v100, 4);
    v99 = v150;
  }
  v101 = &v149[v99];
  v102 = v98 - v99;
  if ( v102 > 0 )
  {
    while ( v102 )
    {
      *v101 = -1;
      ++v101;
      --v102;
    }
  }
  v103 = v5->m_faceMap.m_size;
  v150 = v98;
  v104 = 0;
  for ( k = 0i64; k < v103; ++v104 )
  {
    v106 = v5->m_faceMap.m_data[k];
    if ( (_DWORD)v106 != -1 )
      v149[v106] = v104;
    ++k;
  }
  v107 = v164;
  v108 = 0i64;
  if ( v5->m_ownedEdges.m_size > 0 )
  {
    v109 = 0i64;
    v148 = 0i64;
    v110 = v89;
    result[0].m_enum = -(signed int)v89;
    while ( 1 )
    {
      v111 = faceIndices.m_data[v108];
      v112 = v157.m_data[v108];
      if ( v111 >= 0 )
        break;
      if ( (signed int)v112 >= 0 )
      {
        v113 = v149[v112];
        goto LABEL_140;
      }
LABEL_160:
      ++v110;
      v109 += 20i64;
      ++v108;
      v148 = v109;
      if ( v110 + result[0].m_enum >= v5->m_ownedEdges.m_size )
        goto LABEL_161;
    }
    v113 = v111 + v107;
LABEL_140:
    if ( v113 < 0 )
      goto LABEL_160;
    v114 = v5->m_ownedEdges.m_data;
    v115 = *(unsigned int *)((char *)&v114->m_oppositeEdge + v109);
    if ( v115 == -1 )
      goto LABEL_160;
    v116 = *(&v114->m_flags.m_storage + v109) & 0x40;
    if ( v116 )
      v117 = v115 & 0xFFC00000;
    else
      v117 = v5->m_runtimeId << 22;
    v118 = v117 | v115 & 0x3FFFFF;
    if ( v115 == -1 )
      v118 = -1;
    if ( !v162 || !v116 )
    {
      v131 = v115 & 0x3FFFFF;
      if ( v131 < (signed int)v89 )
      {
        v137 = v5->m_numOriginalEdges;
        if ( v131 < v137 )
        {
          if ( v5->m_edgeMap.m_size )
            v131 = v5->m_edgeMap.m_data[v131];
          if ( v131 == -1 )
            v138 = 0i64;
          else
            v138 = (signed __int64)&v5->m_instancedEdges.m_data[v131];
        }
        else
        {
          v138 = (signed __int64)&v114[v131 - v137];
        }
        *(_DWORD *)(v138 + 12) = v113 | (v5->m_runtimeId << 22);
        *(_DWORD *)(v138 + 8) = v110 | (v5->m_runtimeId << 22);
      }
      else
      {
        v132 = *(unsigned int *)((_BYTE *)&v114->m_oppositeFace + v109) & 0x3FFFFF;
        if ( v132 >= v107 && !v139 )
          v132 = v107 + array[v132 - (signed __int64)v107];
        v133 = v5->m_numOriginalEdges;
        v134 = v89 + v145[v131 - v89];
        if ( v110 < v133 )
        {
          if ( v5->m_edgeMap.m_size )
            v136 = v5->m_edgeMap.m_data[v89 + v108];
          else
            v136 = v110;
          if ( v136 == -1 )
            v135 = 0i64;
          else
            v135 = (signed __int64)&v5->m_instancedEdges.m_data[v136];
        }
        else
        {
          v135 = (signed __int64)&v114[v110 - v133];
        }
        *(_DWORD *)(v135 + 12) = v132 | (v5->m_runtimeId << 22);
        *(_DWORD *)(v135 + 8) = v134 | (v5->m_runtimeId << 22);
      }
      goto LABEL_160;
    }
    v119 = v118;
    v120 = v118 & 0x3FFFFF;
    v121 = v162->m_instances.m_data[v119 >> 22].m_instancePtr;
    if ( hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
           v121->m_originalEdges,
           v121->m_numOriginalEdges,
           &v121->m_instancedEdges,
           &v121->m_ownedEdges,
           &v121->m_edgeMap,
           v120)->m_oppositeEdge == -1 )
    {
LABEL_159:
      v107 = v164;
      v109 = v148;
      goto LABEL_160;
    }
    v122 = v121->m_numOriginalEdges;
    if ( v120 < v122 )
    {
      if ( v121->m_edgeMap.m_size )
        v120 = v121->m_edgeMap.m_data[v120];
      if ( v120 == -1 )
      {
        v125 = 0i64;
LABEL_158:
        *(_DWORD *)(v125 + 12) = v113 | (v5->m_runtimeId << 22);
        *(_DWORD *)(v125 + 8) = v110 | (v5->m_runtimeId << 22);
        goto LABEL_159;
      }
      v123 = v120;
      v124 = v121->m_instancedEdges.m_data;
    }
    else
    {
      v123 = v120 - v122;
      v124 = v121->m_ownedEdges.m_data;
    }
    v125 = (signed __int64)&v124[v123];
    goto LABEL_158;
  }
LABEL_161:
  v150 = 0;
  if ( v151 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v149,
      4 * v151);
  v149 = 0i64;
  v151 = 2147483648;
  v157.m_size = 0;
  if ( v157.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v157.m_data,
      4 * v157.m_capacityAndFlags);
  v157.m_data = 0i64;
  v157.m_capacityAndFlags = 2147483648;
  faceIndices.m_size = 0;
  if ( faceIndices.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      faceIndices.m_data,
      4 * faceIndices.m_capacityAndFlags);
  faceIndices.m_data = 0i64;
  faceIndices.m_capacityAndFlags = 2147483648;
  v146 = 0;
  if ( v147 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v145,
      4 * v147);
  v145 = 0i64;
  v147 = 2147483648;
  v154 = 0;
  if ( v155 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v155);
  array = 0i64;
  v155 = 2147483648;
  v126 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v127 = (_QWORD *)v126[1];
  v128 = v126;
  if ( (unsigned __int64)v127 < v126[3] )
  {
    *v127 = "Et";
    v129 = __rdtsc();
    v130 = (signed __int64)(v127 + 2);
    *(_DWORD *)(v130 - 8) = v129;
    v128[1] = v130;
  }
}

// File Line: 1351
// RVA: 0xBC0B40
void __fastcall hkaiNavMeshUtils::removeFace(hkaiNavMesh *mesh, int faceToRemoveIndex, bool invalidateOppEdges)
{
  int v3; // ebx
  hkaiNavMesh *v4; // rsi
  bool v5; // di
  _DWORD *array; // [rsp+20h] [rbp-18h]
  int v7; // [rsp+28h] [rbp-10h]
  int v8; // [rsp+2Ch] [rbp-Ch]
  hkResult result; // [rsp+58h] [rbp+20h]

  v3 = faceToRemoveIndex;
  v4 = mesh;
  v5 = invalidateOppEdges;
  array = 0i64;
  v7 = 0;
  v8 = 2147483648;
  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 4);
  array[v7++] = v3;
  hkaiNavMeshUtils::removeFaces(&result, v4, (hkArray<int,hkContainerTempAllocator> *)&array, v5);
  v7 = 0;
  if ( v8 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v8);
}

// File Line: 1565
// RVA: 0xBC0720
void __fastcall hkaiNavMeshUtils::validate(hkaiNavMesh *mesh, bool checkVerticesInsideAabb)
{
  hkaiNavMesh::checkDeterminism(mesh);
}

// File Line: 1614
// RVA: 0xBC0730
void __fastcall hkaiNavMeshUtils::validate(hkaiNavMeshInstance *meshInstance, bool checkVerticesInsideAabb, bool checkClearanceCache)
{
  hkaiNavMeshInstance *v3; // rbx
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx

  v3 = meshInstance;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TthkaiNavMeshUtils::validateInstance";
    v6 = __rdtsc();
    v7 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v7 - 8) = v6;
    v4[1] = v7;
  }
  hkaiNavMeshInstance::checkDeterminism(v3);
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "Et";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
}

// File Line: 1765
// RVA: 0xBC2340
hkResult *__fastcall hkaiNavMeshUtils::compactVertices(hkResult *result, hkaiNavMesh *mesh, int edgeStartIdx, int vertexStartIdx)
{
  hkaiNavMesh *v4; // rsi
  __int64 v5; // r15
  int v6; // edx
  signed __int64 v7; // r14
  hkResult *v8; // r13
  int v9; // ebx
  int v10; // er9
  int v11; // er8
  int v12; // er9
  char *v13; // rdi
  __int64 v14; // rcx
  _DWORD *v15; // r12
  signed int v16; // ebx
  int v17; // er9
  signed __int64 v18; // r8
  hkaiNavMesh::Edge *v19; // rdi
  __int64 v20; // rdi
  int v21; // er9
  int v22; // er8
  void *v23; // rdx
  hkVector4f *v24; // r11
  signed __int64 v25; // r8
  _OWORD *v26; // r11
  int v27; // er10
  __int64 v28; // r9
  __int64 v29; // r13
  _OWORD *v30; // rcx
  int v31; // edi
  int v32; // eax
  int v33; // eax
  int v34; // er9
  signed __int64 v35; // r8
  hkaiNavMesh::Edge *v36; // rdi
  int v37; // er8
  hkResult v39; // [rsp+30h] [rbp-40h]
  hkResult v40[2]; // [rsp+38h] [rbp-38h]
  __int64 v41; // [rsp+40h] [rbp-30h]
  char *array; // [rsp+48h] [rbp-28h]
  int v43; // [rsp+50h] [rbp-20h]
  int v44; // [rsp+54h] [rbp-1Ch]
  _DWORD *v45; // [rsp+58h] [rbp-18h]
  int v46; // [rsp+60h] [rbp-10h]
  int v47; // [rsp+64h] [rbp-Ch]
  hkResult *v48; // [rsp+B0h] [rbp+40h]
  hkResult resulta; // [rsp+B8h] [rbp+48h]
  hkResult v50; // [rsp+C8h] [rbp+58h]

  v50.m_enum = vertexStartIdx;
  v48 = result;
  v4 = mesh;
  LODWORD(v5) = mesh->m_vertices.m_size - vertexStartIdx;
  v6 = 0;
  v7 = edgeStartIdx;
  v8 = result;
  array = 0i64;
  v9 = ((signed int)v5 + 31) >> 5;
  v43 = 0;
  v44 = 2147483648;
  if ( v9 <= 0 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v10 = ((signed int)v5 + 31) >> 5;
    if ( v9 < 0 )
      v10 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v10, 4);
    if ( resulta.m_enum )
    {
      v11 = v44;
      v8->m_enum = 1;
      v43 = 0;
      if ( v11 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          4 * v11);
      return v8;
    }
    v6 = v43;
  }
  if ( (v44 & 0x3FFFFFFF) < v9 )
  {
    v12 = ((signed int)v5 + 31) >> 5;
    if ( v9 < 2 * (v44 & 0x3FFFFFFF) )
      v12 = 2 * (v44 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(v40, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v12, 4);
    v6 = v43;
  }
  v13 = &array[4 * v6];
  v14 = v9 - v6;
  if ( v9 - v6 > 0 )
  {
    while ( v14 )
    {
      *(_DWORD *)v13 = 0;
      v13 += 4;
      --v14;
    }
  }
  v15 = array;
  v43 = ((signed int)v5 + 31) >> 5;
  v16 = v9 | 0x80000000;
  v17 = v7;
  *(_QWORD *)&v40[0].m_enum = array;
  if ( (signed int)v7 < v4->m_edges.m_size )
  {
    v18 = v7;
    do
    {
      v19 = v4->m_edges.m_data;
      ++v17;
      ++v18;
      v15[(signed __int64)v19[v18 - 1].m_a >> 5] |= 1 << (v19[v18 - 1].m_a & 0x1F);
      v15[(signed __int64)*((signed int *)&v19[v18] - 4) >> 5] |= 1 << (*((_DWORD *)&v19[v18] - 4) & 0x1F);
    }
    while ( v17 < v4->m_edges.m_size );
  }
  v20 = 0i64;
  v47 = 2147483648;
  v45 = 0i64;
  v46 = 0;
  if ( (signed int)v5 <= 0 )
  {
    v39.m_enum = 0;
LABEL_28:
    v24 = v4->m_vertices.m_data;
    v46 = v5;
    v41 = v50.m_enum;
    v25 = v50.m_enum;
    v5 = (signed int)v5;
    v26 = (_OWORD *)v24[v25].m_quad.m128_f32;
    v27 = 0;
    v28 = 0i64;
    if ( (signed int)v5 > 0i64 )
    {
      v29 = *(_QWORD *)&v40[0].m_enum;
      do
      {
        v45[v20] = v27;
        if ( (*(_DWORD *)(v29 + 4 * ((signed __int64)(signed int)v28 >> 5)) >> (v28 & 0x1F)) & 1 )
        {
          v30 = v26;
          ++v26;
          *v30 = v4->m_vertices.m_data[v25];
        }
        else
        {
          ++v27;
        }
        ++v20;
        v28 = (unsigned int)(v28 + 1);
        ++v25;
      }
      while ( v20 < v5 );
      v8 = v48;
    }
    v31 = v4->m_vertices.m_size - v27;
    v32 = v4->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v32 < v31 )
    {
      v33 = 2 * v32;
      v34 = v4->m_vertices.m_size - v27;
      if ( v31 < v33 )
        v34 = v33;
      hkArrayUtil::_reserve(
        &v50,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v4->m_vertices,
        v34,
        16);
    }
    v4->m_vertices.m_size = v31;
    if ( (signed int)v7 < v4->m_edges.m_size )
    {
      v28 = v41;
      v35 = v7;
      do
      {
        LODWORD(v7) = v7 + 1;
        v36 = &v4->m_edges.m_data[v35];
        ++v35;
        v36->m_a -= v45[v36->m_a - v28];
        v36->m_b -= v45[v36->m_b - v28];
      }
      while ( (signed int)v7 < v4->m_edges.m_size );
    }
    v37 = v47;
    LODWORD(v20) = 0;
    v8->m_enum = 0;
    v46 = 0;
    if ( v37 >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, _DWORD *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        v45,
        (unsigned int)(4 * v37),
        v28);
    v45 = 0i64;
    v47 = 2147483648;
    if ( v16 < 0 )
      goto LABEL_47;
    v23 = *(void **)&v40[0].m_enum;
    goto LABEL_46;
  }
  v21 = v5;
  if ( (signed int)v5 < 0 )
    v21 = 0;
  hkArrayUtil::_reserve(&v39, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v45, v21, 4);
  if ( v39.m_enum == HK_SUCCESS )
    goto LABEL_28;
  v22 = v47;
  v8->m_enum = 1;
  v46 = 0;
  if ( v22 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v45,
      4 * v22);
  v45 = 0i64;
  v47 = 2147483648;
  if ( v16 < 0 )
    goto LABEL_47;
  v23 = v15;
LABEL_46:
  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
    v23,
    4 * v16);
LABEL_47:
  v43 = v20;
  if ( v44 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v44);
  return v8;
}

// File Line: 1829
// RVA: 0xBC2700
void __fastcall hkaiNavMeshUtils::compactOwnedVertices(hkaiNavMeshInstance *meshInstance)
{
  __int64 v1; // r13
  signed int v2; // esi
  int v3; // er14
  hkaiNavMeshInstance *v4; // rbx
  int v5; // edi
  hkLifoAllocator *v6; // rax
  _DWORD *v7; // rdx
  int v8; // ecx
  char *v9; // r8
  signed int v10; // eax
  int v11; // eax
  int v12; // er9
  __int64 v13; // rcx
  _DWORD *v14; // rdi
  int v15; // er8
  __int64 v16; // r9
  hkaiNavMesh::Edge *v17; // rax
  int v18; // ecx
  int v19; // edi
  int v20; // edi
  int v21; // ecx
  int v22; // er8
  __int64 v23; // r9
  hkaiNavMesh::Edge *v24; // rax
  int v25; // edi
  int v26; // ecx
  int v27; // er9
  hkVector4f *v28; // r10
  signed __int64 v29; // rax
  int v30; // er14
  int v31; // er8
  __int64 v32; // rdi
  _WORD *v33; // r11
  __int64 v34; // r9
  hkVector4f *v35; // rcx
  _WORD *v36; // rcx
  int v37; // er13
  int v38; // eax
  int v39; // eax
  int v40; // er9
  int v41; // edi
  int v42; // eax
  int v43; // eax
  int v44; // er9
  __int64 v45; // r9
  signed int v46; // er14
  __int64 v47; // r11
  hkaiNavMesh::Edge *v48; // r8
  __int64 v49; // rdi
  __int64 v50; // rdx
  int v51; // er8
  signed int *v52; // rdi
  __int64 v53; // rdx
  __int64 v54; // rdx
  __int64 v55; // [rsp+30h] [rbp-40h]
  int v56; // [rsp+38h] [rbp-38h]
  int v57; // [rsp+3Ch] [rbp-34h]
  _DWORD *array; // [rsp+40h] [rbp-30h]
  int v59; // [rsp+48h] [rbp-28h]
  unsigned int v60; // [rsp+4Ch] [rbp-24h]
  _DWORD *v61; // [rsp+50h] [rbp-20h]
  int v62; // [rsp+58h] [rbp-18h]
  int v63; // [rsp+60h] [rbp-10h]
  hkResult v64; // [rsp+B0h] [rbp+40h]
  int v65; // [rsp+B8h] [rbp+48h]
  hkResult result; // [rsp+C0h] [rbp+50h]

  v1 = meshInstance->m_ownedVertices.m_size;
  v2 = meshInstance->m_numOriginalVertices;
  v3 = v2 + v1;
  v4 = meshInstance;
  v5 = ((signed int)v1 + 31) >> 5;
  v64.m_enum = meshInstance->m_numOriginalVertices;
  array = 0i64;
  v65 = v2 + v1;
  v59 = 0;
  v60 = 2147483648;
  v62 = v5;
  if ( v5 )
  {
    v6 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v7 = v6->m_cur;
    v8 = (4 * v5 + 127) & 0xFFFFFF80;
    v9 = (char *)v7 + v8;
    if ( v8 > v6->m_slabSize || v9 > v6->m_end )
      v7 = hkLifoAllocator::allocateFromNewSlab(v6, v8);
    else
      v6->m_cur = v9;
  }
  else
  {
    v7 = 0i64;
  }
  array = v7;
  v61 = v7;
  v63 = v1;
  v60 = v5 | 0x80000000;
  v10 = (v5 | 0x80000000) & 0x3FFFFFFF;
  if ( v10 < v5 )
  {
    v11 = 2 * v10;
    v12 = ((signed int)v1 + 31) >> 5;
    if ( v5 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v12, 4);
    v7 = array;
  }
  v59 = ((signed int)v1 + 31) >> 5;
  if ( v5 - 1 >= 0 )
  {
    v13 = (unsigned int)v5;
    v14 = v7;
    while ( v13 )
    {
      *v14 = 0;
      ++v14;
      --v13;
    }
    v7 = array;
  }
  v15 = 0;
  if ( v4->m_ownedEdges.m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      v17 = v4->m_ownedEdges.m_data;
      v18 = v17[v16].m_a;
      if ( v18 < v3 )
      {
        v19 = v17[v16].m_b;
        if ( v19 < v3 )
        {
          v20 = v19 - v2;
          v21 = v18 - v2;
          if ( v21 >= 0 )
          {
            v7[(signed __int64)v21 >> 5] |= 1 << (v21 & 0x1F);
            v7 = array;
          }
          if ( v20 >= 0 )
          {
            v7[(signed __int64)v20 >> 5] |= 1 << (v20 & 0x1F);
            v7 = array;
          }
        }
      }
      ++v15;
      ++v16;
    }
    while ( v15 < v4->m_ownedEdges.m_size );
  }
  v22 = 0;
  if ( v4->m_instancedEdges.m_size > 0 )
  {
    v23 = 0i64;
    do
    {
      v24 = v4->m_instancedEdges.m_data;
      v25 = v24[v23].m_b - v2;
      v26 = v24[v23].m_a - v2;
      if ( v26 >= 0 )
      {
        v7[(signed __int64)v26 >> 5] |= 1 << (v26 & 0x1F);
        v7 = array;
      }
      if ( v25 >= 0 )
      {
        v7[(signed __int64)v25 >> 5] |= 1 << (v25 & 0x1F);
        v7 = array;
      }
      ++v22;
      ++v23;
    }
    while ( v22 < v4->m_instancedEdges.m_size );
  }
  v55 = 0i64;
  v56 = 0;
  v57 = 2147483648;
  if ( (signed int)v1 > 0 )
  {
    v27 = v1;
    if ( (signed int)v1 < 0 )
      v27 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v55, v27, 4);
  }
  v28 = v4->m_ownedVertices.m_data;
  v29 = (signed __int64)&v4->m_globalClearanceCache.m_data[v4->m_numOriginalVertices];
  v56 = v1;
  v30 = 0;
  v31 = 0;
  v32 = 0i64;
  v33 = (_WORD *)v29;
  if ( (signed int)v1 > 0 )
  {
    v34 = 0i64;
    do
    {
      *(_DWORD *)(v55 + 4 * v32) = v30;
      if ( (array[(signed __int64)v31 >> 5] >> (v31 & 0x1F)) & 1 )
      {
        v35 = v28;
        ++v28;
        *v35 = v4->m_ownedVertices.m_data[v34];
        v36 = v33;
        ++v33;
        *v36 = *(_WORD *)(v29 + 2 * v32);
      }
      else
      {
        ++v30;
      }
      ++v32;
      ++v31;
      ++v34;
    }
    while ( v32 < v1 );
    v2 = v64.m_enum;
  }
  v37 = v1 - v30;
  v38 = v4->m_ownedVertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v38 < v37 )
  {
    v39 = 2 * v38;
    v40 = v37;
    if ( v37 < v39 )
      v40 = v39;
    hkArrayUtil::_reserve(
      &v64,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v4->m_ownedVertices,
      v40,
      16);
  }
  v4->m_ownedVertices.m_size = v37;
  v41 = v4->m_globalClearanceCache.m_size - v30;
  v42 = v4->m_globalClearanceCache.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v42 < v41 )
  {
    v43 = 2 * v42;
    v44 = v4->m_globalClearanceCache.m_size - v30;
    if ( v41 < v43 )
      v44 = v43;
    hkArrayUtil::_reserve(
      &v64,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v4->m_globalClearanceCache,
      v44,
      2);
  }
  v4->m_globalClearanceCache.m_size = v41;
  v45 = 0i64;
  if ( v4->m_ownedEdges.m_size > 0 )
  {
    v46 = v65;
    v47 = 0i64;
    do
    {
      v48 = &v4->m_ownedEdges.m_data[v47];
      v49 = v48->m_a;
      if ( (signed int)v49 < v46 )
      {
        v50 = v48->m_b;
        if ( (signed int)v50 < v46 )
        {
          if ( (signed int)v49 >= v2 )
            v48->m_a = v49 - *(_DWORD *)(v55 + 4 * (v49 - v2));
          if ( (signed int)v50 >= v2 )
            v48->m_b = v50 - *(_DWORD *)(v55 + 4 * (v50 - v2));
        }
      }
      v45 = (unsigned int)(v45 + 1);
      ++v47;
    }
    while ( (signed int)v45 < v4->m_ownedEdges.m_size );
  }
  v51 = 0;
  if ( v4->m_instancedEdges.m_size > 0 )
  {
    v45 = 0i64;
    do
    {
      v52 = (int *)((char *)&v4->m_instancedEdges.m_data->m_a + v45);
      v53 = *v52;
      if ( (signed int)v53 >= v2 )
        *v52 = v53 - *(_DWORD *)(v55 + 4 * (v53 - v2));
      v54 = v52[1];
      if ( (signed int)v54 >= v2 )
        v52[1] = v54 - *(_DWORD *)(v55 + 4 * (v54 - v2));
      ++v51;
      v45 += 20i64;
    }
    while ( v51 < v4->m_instancedEdges.m_size );
  }
  v56 = 0;
  if ( v57 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v55,
      (unsigned int)(4 * v57),
      v45);
  v55 = 0i64;
  v57 = 2147483648;
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>((hkBitFieldStorage<hkLocalArray<unsigned int> > *)&array);
}

// File Line: 1912
// RVA: 0xBC2B90
hkResult *__fastcall hkaiNavMeshUtils::compactEdges(hkResult *result, hkaiNavMesh *mesh, int edgeStartIdx, bool checkUserData)
{
  int v4; // esi
  __int64 v5; // r14
  hkaiNavMesh *v6; // rbx
  hkResult *v7; // r15
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
  signed int v19; // edx
  __int64 v20; // rdi
  __int64 v21; // r8
  __int64 v22; // rcx
  int v23; // er9
  __int64 v24; // r10
  hkaiNavMesh::Face *v25; // r8
  int v26; // eax
  int v27; // edi
  int v28; // edi
  int v29; // er9
  hkaiNavMesh::Edge *v30; // r11
  int v31; // er9
  int v32; // edi
  __int64 v33; // r10
  __int64 v34; // r8
  hkaiNavMesh::Edge *v35; // rdx
  hkaiNavMesh::Edge *v36; // rcx
  int v37; // edi
  __int64 v38; // r8
  hkaiNavMesh::Face *v39; // rdx
  __int64 v40; // rax
  int v41; // edx
  __int64 v42; // rdi
  hkaiNavMesh::Edge *v43; // r8
  unsigned int v44; // ecx
  _DWORD *v46; // [rsp+30h] [rbp-40h]
  int v47; // [rsp+38h] [rbp-38h]
  int v48; // [rsp+3Ch] [rbp-34h]
  _DWORD *array; // [rsp+40h] [rbp-30h]
  int v50; // [rsp+48h] [rbp-28h]
  unsigned int v51; // [rsp+4Ch] [rbp-24h]
  char *v52; // [rsp+50h] [rbp-20h]
  int v53; // [rsp+58h] [rbp-18h]
  int v54; // [rsp+60h] [rbp-10h]
  hkResult resulta; // [rsp+A8h] [rbp+38h]

  v4 = mesh->m_edges.m_size;
  v5 = (unsigned int)edgeStartIdx;
  v6 = mesh;
  v7 = result;
  v8 = (v4 + 31) >> 5;
  array = 0i64;
  v50 = 0;
  v51 = 2147483648;
  v53 = v8;
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
  v52 = v10;
  v54 = v4;
  v51 = v8 | 0x80000000;
  v13 = (v8 | 0x80000000) & 0x3FFFFFFF;
  if ( v13 < v8 )
  {
    v14 = 2 * v13;
    v15 = (v4 + 31) >> 5;
    if ( v8 < v14 )
      v15 = v14;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v15, 4);
  }
  v50 = (v4 + 31) >> 5;
  if ( !array )
  {
    v7->m_enum = 1;
    goto LABEL_60;
  }
  v16 = v8 - 1;
  if ( v8 - 1 >= 0 )
  {
    v17 = array;
    for ( i = (unsigned int)(v16 + 1); i; --i )
    {
      *v17 = 0;
      ++v17;
    }
  }
  v19 = 1;
  if ( (signed int)v5 > 0 )
  {
    v20 = 0i64;
    v21 = v5;
    do
    {
      v22 = v20++;
      array[v22 >> 5] |= v19;
      v19 = __ROL4__(v19, 1);
      --v21;
    }
    while ( v21 );
  }
  v23 = 0;
  if ( v6->m_faces.m_size > 0 )
  {
    v24 = 0i64;
    while ( 1 )
    {
      v25 = &v6->m_faces.m_data[v24];
      v26 = v25->m_numUserEdges <= 0 ? v25->m_startEdgeIndex : v25->m_startUserEdgeIndex;
      if ( v26 != -1 )
        break;
LABEL_34:
      ++v23;
      ++v24;
      if ( v23 >= v6->m_faces.m_size )
        goto LABEL_35;
    }
    while ( 1 )
    {
      array[(signed __int64)v26 >> 5] |= 1 << (v26 & 0x1F);
      v27 = v25->m_startUserEdgeIndex;
      if ( v26 >= v27 && v26 < v25->m_numUserEdges + v27 - 1 )
        goto LABEL_32;
      if ( v26 != v25->m_numUserEdges + v27 - 1 )
        break;
      v26 = v25->m_startEdgeIndex;
LABEL_33:
      if ( v26 == -1 )
        goto LABEL_34;
    }
    if ( v26 < v25->m_startEdgeIndex || v26 >= v25->m_numEdges + v25->m_startEdgeIndex - 1 )
      goto LABEL_34;
LABEL_32:
    ++v26;
    goto LABEL_33;
  }
LABEL_35:
  v28 = v6->m_edges.m_size;
  v46 = 0i64;
  v47 = 0;
  v48 = 2147483648;
  if ( v28 <= 0 )
    goto LABEL_63;
  v29 = v28;
  if ( v28 < 0 )
    v29 = 0;
  hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v46, v29, 4);
  if ( resulta.m_enum )
  {
    v7->m_enum = 1;
  }
  else
  {
LABEL_63:
    v30 = v6->m_edges.m_data;
    v47 = v28;
    v31 = 0;
    v32 = 0;
    if ( v6->m_edges.m_size > 0 )
    {
      v33 = 0i64;
      v34 = 0i64;
      do
      {
        v46[v34] = v32 - v31;
        if ( (array[(signed __int64)v32 >> 5] >> (v32 & 0x1F)) & 1 )
        {
          v35 = v30;
          ++v30;
          v36 = &v6->m_edges.m_data[v33];
          v35->m_a = v36->m_a;
          v35->m_b = v36->m_b;
          v35->m_oppositeEdge = v36->m_oppositeEdge;
          v35->m_oppositeFace = v36->m_oppositeFace;
          v35->m_flags.m_storage = v36->m_flags.m_storage;
          v35->m_paddingByte = v36->m_paddingByte;
          v35->m_userEdgeCost.m_value = v36->m_userEdgeCost.m_value;
        }
        else
        {
          ++v31;
        }
        ++v32;
        ++v34;
        ++v33;
      }
      while ( v32 < v6->m_edges.m_size );
    }
    hkaiNavMesh::setEdgesSize(v6, &resulta, v6->m_edges.m_size - v31);
    v37 = 0;
    if ( v6->m_faces.m_size > 0 )
    {
      v38 = 0i64;
      do
      {
        v39 = &v6->m_faces.m_data[v38];
        v40 = v39->m_startUserEdgeIndex;
        v39->m_startEdgeIndex = v46[v39->m_startEdgeIndex];
        if ( (signed int)v40 >= 0 )
          LODWORD(v40) = v46[v40];
        ++v37;
        v39->m_startUserEdgeIndex = v40;
        ++v38;
      }
      while ( v37 < v6->m_faces.m_size );
    }
    v41 = 0;
    if ( v6->m_edges.m_size > 0 )
    {
      v42 = 0i64;
      do
      {
        v43 = v6->m_edges.m_data;
        v44 = v43[v42].m_oppositeEdge;
        if ( v44 != -1 )
          v43[v42].m_oppositeEdge = v46[v44 & 0x3FFFFF];
        ++v41;
        ++v42;
      }
      while ( v41 < v6->m_edges.m_size );
    }
    v7->m_enum = 0;
  }
  v47 = 0;
  if ( v48 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v46,
      4 * v48);
  v48 = 2147483648;
  v46 = 0i64;
LABEL_60:
  hkBitFieldStorage<hkLocalArray<unsigned int>>::~hkBitFieldStorage<hkLocalArray<unsigned int>>((hkBitFieldStorage<hkLocalArray<unsigned int> > *)&array);
  return v7;
}

// File Line: 2007
// RVA: 0xBC3560
hkResult *__fastcall hkaiNavMeshUtils::getPointOnMeshInsideAabb(hkResult *result, hkaiStreamingCollection *collection, hkaiNavMeshQueryMediator *mediator, hkAabb *aabb, hkVector4f *up, hkPseudoRandomGenerator *rand, hkSimdFloat32 *radius, hkVector4f *out, int maxSamples)
{
  hkResult *v9; // r14
  hkaiNavMeshQueryMediator *v10; // r15
  hkaiStreamingCollection *v11; // r12
  __m128 v12; // xmm3
  int v13; // eax
  __int128 v14; // cx
  __int64 v15; // r13
  unsigned int v16; // ecx
  int v17; // ecx
  float v18; // xmm0_4
  int v19; // ecx
  signed int v20; // eax
  int v21; // ecx
  __m128 v22; // ST20_16
  signed int v23; // eax
  __m128 v24; // xmm4
  __m128 v25; // xmm2
  float v26; // xmm0_4
  hkBaseObjectVtbl *v27; // rax
  __m128 v28; // xmm0
  __m128 v29; // xmm2
  __m128 v30; // xmm5
  __m128 v31; // xmm0
  __m128 v32; // xmm1
  __m128 v33; // xmm7
  __m128 v34; // xmm0
  __m128 v35; // xmm6
  __m128 v37; // [rsp+30h] [rbp-C8h]
  int v38; // [rsp+50h] [rbp-A8h]
  __int64 v39; // [rsp+58h] [rbp-A0h]
  __int128 v40; // [rsp+60h] [rbp-98h]
  __int64 v41; // [rsp+70h] [rbp-88h]
  __m128 v42; // [rsp+80h] [rbp-78h]
  __m128 v43; // [rsp+90h] [rbp-68h]
  hkAabb *v44; // [rsp+118h] [rbp+20h]

  v44 = aabb;
  v9 = result;
  v10 = mediator;
  v11 = collection;
  v12 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)up), 1u), 1u);
  v13 = _mm_movemask_ps(
          _mm_and_ps(
            _mm_cmpleps(
              _mm_max_ps(
                _mm_shuffle_ps(v12, v12, 170),
                _mm_max_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0))),
              v12),
            (__m128)xmmword_141A5BF50));
  v14 = (unsigned __int64)v13;
  if ( maxSamples <= 0 )
  {
LABEL_8:
    v9->m_enum = 1;
  }
  else
  {
    v15 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[v13];
    while ( 1 )
    {
      v38 = 0;
      v16 = rand->m_current;
      v39 = 0i64;
      v41 = 0i64;
      v17 = 1664525 * v16 + 1013904223;
      v18 = (float)v17;
      v19 = 1664525 * v17 + 1013904223;
      v20 = v19;
      v21 = 1664525 * v19 + 1013904223;
      v22.m128_f32[0] = v18 * 2.3283064e-10;
      v22.m128_f32[1] = (float)v20 * 2.3283064e-10;
      v23 = 1664525 * v21 + 1013904223;
      rand->m_current = v23;
      v24 = (__m128)`hkVector4f::getComponent'::`2'::indexToMask[v15];
      v25 = (__m128)`hkVector4f::getComponent'::`2'::indexToMask[v15];
      v22.m128_f32[2] = (float)v21 * 2.3283064e-10;
      v26 = (float)v23;
      v27 = v10->vfptr;
      v22.m128_f32[3] = v26 * 2.3283064e-10;
      v28 = v25;
      v29 = _mm_and_ps(v25, aabb->m_max.m_quad);
      v30 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(aabb->m_max.m_quad, aabb->m_min.m_quad), v22), aabb->m_min.m_quad);
      v31 = _mm_and_ps(v28, aabb->m_min.m_quad);
      v32 = _mm_or_ps(_mm_shuffle_ps(v31, v31, 78), v31);
      v33 = _mm_or_ps(_mm_and_ps(_mm_or_ps(_mm_shuffle_ps(v32, v32, 177), v32), v24), _mm_andnot_ps(v24, v30));
      v42 = v33;
      v34 = _mm_or_ps(_mm_shuffle_ps(v29, v29, 78), v29);
      _mm_store_si128((__m128i *)&v40, (__m128i)0i64);
      v35 = _mm_or_ps(_mm_and_ps(_mm_or_ps(_mm_shuffle_ps(v34, v34, 177), v34), v24), _mm_andnot_ps(v24, v30));
      v43 = v35;
      if ( ((unsigned __int8 (__fastcall *)(hkaiNavMeshQueryMediator *, int *, __m128 *))v27[2].__first_virtual_table_function__)(
             v10,
             &v38,
             &v37) )
      {
        out->m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v35, v33), v37), v33);
        if ( (unsigned __int8)hkaiNavMeshUtils::isAwayFromBoundaryEdges(v11, v10, out, radius) )
          break;
      }
      if ( ++DWORD2(v14) >= maxSamples )
        goto LABEL_8;
      aabb = v44;
    }
    v9->m_enum = 0;
  }
  return v9;
}

// File Line: 2041
// RVA: 0xBC37F0
bool __fastcall hkaiNavMeshUtils::isEdgeInsideAabb(hkaiNavMeshInstance *meshInstance, hkAabb *aabb, int eIdx)
{
  hkAabb *v3; // rbx
  hkVector4f edgeB; // [rsp+20h] [rbp-28h]
  hkVector4f edgeA; // [rsp+30h] [rbp-18h]

  v3 = aabb;
  hkaiNavMeshInstance::getEdgePoints(meshInstance, eIdx, &edgeA, &edgeB);
  return hkaiNavMeshUtils::_isSegmentInsideAabb(&edgeA, &edgeB, v3);
}

// File Line: 2048
// RVA: 0xBC3830
bool __fastcall hkaiNavMeshUtils::_isSegmentInsideAabb(hkVector4f *edgeA, hkVector4f *edgeB, hkAabb *aabb)
{
  __m128i v3; // xmm6
  __m128 v4; // xmm1
  __m128 v5; // xmm3
  __m128 v6; // ST20_16
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  __m128 v9; // xmm3
  __m128 v10; // xmm4
  __m128 v11; // xmm3

  v3 = (__m128i)_mm_sub_ps(edgeB->m_quad, edgeA->m_quad);
  v4 = _mm_rcp_ps((__m128)v3);
  v5 = _mm_cmpeqps((__m128)0i64, (__m128)v3);
  v6 = _mm_or_ps(
         _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v3, 0x1Fu), 0x1Fu), (__m128)_xmm), v5),
         _mm_andnot_ps(v5, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v4, (__m128)v3)), v4)));
  v6.m128_i32[3] = _mm_movemask_ps(
                     _mm_cmpleps(
                       (__m128)0i64,
                       _mm_shuffle_ps((__m128)v3, _mm_unpackhi_ps((__m128)v3, query.m_quad), 196))) & 7 | 0x3F000000;
  v7 = _mm_mul_ps(v6, _mm_sub_ps(aabb->m_max.m_quad, edgeA->m_quad));
  v8 = _mm_mul_ps(v6, _mm_sub_ps(aabb->m_min.m_quad, edgeA->m_quad));
  v9 = v8;
  v10 = _mm_max_ps(v8, v7);
  v11 = _mm_min_ps(v9, v7);
  return fmax(
           fmax(
             COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170)),
             fmax(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)), COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))),
           0.0) <= fmin(
                     fmin(
                       COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 170)),
                       fmin(COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 85)), COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 0)))),
                     1.0);
}

// File Line: 2055
// RVA: 0xBC5920
void __fastcall hkaiNavMeshUtils::getEdgesInsideAabb(hkaiNavMeshInstance *meshInstance, hkaiNavMeshQueryMediator *mediator, hkAabb *aabb, hkArray<hkaiNavMeshUtils::FaceEdgeKeyPair,hkContainerTempAllocator> *edgeHits)
{
  hkVector4f v4; // xmm0
  hkVector4f v5; // xmm1
  hkArray<hkaiNavMeshUtils::FaceEdgeKeyPair,hkContainerTempAllocator> *v6; // rsi
  hkAabb *v7; // rdi
  hkaiNavMeshInstance *v8; // rbx
  int v9; // edx
  __int64 v10; // rcx
  int v11; // er9
  hkaiStreamingCollection::InstanceInfo *v12; // r9
  __int64 v13; // rdx
  hkaiDirectedGraphInstance **v14; // rax
  hkArrayBase<unsigned int> faceHits; // [rsp+30h] [rbp-49h]
  hkaiStreamingCollection array; // [rsp+40h] [rbp-39h]
  int v17; // [rsp+70h] [rbp-9h]
  __int64 v18; // [rsp+78h] [rbp-1h]
  __int64 v19; // [rsp+80h] [rbp+7h]
  hkaiNavMeshInstance *v20; // [rsp+88h] [rbp+Fh]
  hkaiReferenceFrame *v21; // [rsp+90h] [rbp+17h]
  __m128 v22; // [rsp+A0h] [rbp+27h]
  __m128 v23; // [rsp+B0h] [rbp+37h]
  hkResult result; // [rsp+E0h] [rbp+67h]

  v4.m_quad = (__m128)aabb->m_min;
  v5.m_quad = (__m128)aabb->m_max;
  v6 = edgeHits;
  v7 = aabb;
  v8 = meshInstance;
  faceHits.m_data = 0i64;
  faceHits.m_size = 0;
  v22 = v4.m_quad;
  v23 = v5.m_quad;
  faceHits.m_capacityAndFlags = 2147483648;
  v17 = 0;
  v18 = 0i64;
  v19 = 0i64;
  v20 = meshInstance;
  if ( meshInstance )
    v21 = &meshInstance->m_referenceFrame;
  else
    v21 = 0i64;
  ((void (__fastcall *)(hkaiNavMeshQueryMediator *, int *, hkArrayBase<unsigned int> *))mediator->vfptr[3].__first_virtual_table_function__)(
    mediator,
    &v17,
    &faceHits);
  v9 = 0;
  if ( faceHits.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      ++v9;
      ++v10;
      faceHits.m_data[v10 - 1] &= 0x3FFFFFu;
    }
    while ( v9 < faceHits.m_size );
  }
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) < 1 )
  {
    v11 = 1;
    if ( 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) > 1 )
      v11 = 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array.m_instances,
      v11,
      48);
  }
  v12 = array.m_instances.m_data;
  v13 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    v14 = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( v14 != (hkaiDirectedGraphInstance **)16 )
      {
        *(v14 - 2) = 0i64;
        *(v14 - 1) = 0i64;
        *v14 = 0i64;
        v14[1] = 0i64;
        v14[2] = 0i64;
        *((_DWORD *)v14 + 6) = -1;
      }
      v14 += 6;
      --v13;
    }
    while ( v13 );
    v12 = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  v12->m_instancePtr = v8;
  array.m_instances.m_data->m_clusterGraphInstance = 0i64;
  array.m_instances.m_data->m_mediator = 0i64;
  hkaiNavMeshUtils::_getEdgesInsideAabb(&array, v7, &faceHits, v6);
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
  faceHits.m_size = 0;
  if ( faceHits.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      faceHits.m_data,
      4 * faceHits.m_capacityAndFlags);
}

// File Line: 2078
// RVA: 0xBC5AF0
void __fastcall hkaiNavMeshUtils::getEdgesInsideAabb(hkaiStreamingCollection *collection, hkaiNavMeshQueryMediator *mediator, hkAabb *aabb, hkArray<hkaiNavMeshUtils::FaceEdgeKeyPair,hkContainerTempAllocator> *edgeHits)
{
  hkVector4f v4; // xmm1
  hkVector4f v5; // xmm0
  hkAabb *v6; // rsi
  hkaiStreamingCollection *v7; // rdi
  hkArray<hkaiNavMeshUtils::FaceEdgeKeyPair,hkContainerTempAllocator> *v8; // rbx
  hkArrayBase<unsigned int> faceHits; // [rsp+20h] [rbp-68h]
  int v10; // [rsp+30h] [rbp-58h]
  __int64 v11; // [rsp+38h] [rbp-50h]
  __int64 v12; // [rsp+40h] [rbp-48h]
  __int64 v13; // [rsp+50h] [rbp-38h]
  __m128 v14; // [rsp+60h] [rbp-28h]
  __m128 v15; // [rsp+70h] [rbp-18h]

  v4.m_quad = (__m128)aabb->m_min;
  _mm_store_si128((__m128i *)&v12, (__m128i)0i64);
  v5.m_quad = (__m128)aabb->m_max;
  faceHits.m_data = 0i64;
  faceHits.m_size = 0;
  faceHits.m_capacityAndFlags = 2147483648;
  v10 = 0;
  v11 = 0i64;
  v13 = 0i64;
  v15 = v5.m_quad;
  v14 = v4.m_quad;
  v6 = aabb;
  v7 = collection;
  v8 = edgeHits;
  ((void (__fastcall *)(hkaiNavMeshQueryMediator *, int *, hkArrayBase<unsigned int> *))mediator->vfptr[3].__first_virtual_table_function__)(
    mediator,
    &v10,
    &faceHits);
  hkaiNavMeshUtils::_getEdgesInsideAabb(v7, v6, &faceHits, v8);
  faceHits.m_size = 0;
  if ( faceHits.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      faceHits.m_data,
      4 * faceHits.m_capacityAndFlags);
}

// File Line: 2088
// RVA: 0xBC5BC0
void __fastcall hkaiNavMeshUtils::_getEdgesInsideAabb(hkaiStreamingCollection *collection, hkAabb *aabb, hkArrayBase<unsigned int> *faceHits, hkArray<hkaiNavMeshUtils::FaceEdgeKeyPair,hkContainerTempAllocator> *edgeHits)
{
  int v4; // er12
  hkAabb *v5; // r13
  hkArray<hkaiNavMeshUtils::FaceEdgeKeyPair,hkContainerTempAllocator> *v6; // rbx
  hkArrayBase<unsigned int> *v7; // rax
  hkaiStreamingCollection *v8; // rdx
  signed __int64 v9; // rcx
  unsigned int v10; // er15
  __int64 v11; // r14
  hkaiNavMeshInstance *v12; // rbp
  hkaiNavMesh::Face *v13; // rsi
  int i; // edi
  hkaiNavMeshUtils::FaceEdgeKeyPair *v15; // rdx
  hkaiNavMeshUtils::FaceEdgeKeyPair v16; // [rsp+30h] [rbp-48h]
  __int64 v17; // [rsp+38h] [rbp-40h]
  hkaiStreamingCollection *v18; // [rsp+80h] [rbp+8h]
  hkArrayBase<unsigned int> *v19; // [rsp+90h] [rbp+18h]

  v19 = faceHits;
  v18 = collection;
  v4 = 0;
  v5 = aabb;
  v6 = edgeHits;
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
      v12 = v8->m_instances.m_data[v11].m_instancePtr;
      v13 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
              v12->m_originalFaces,
              v12->m_numOriginalFaces,
              &v12->m_instancedFaces,
              &v12->m_ownedFaces,
              &v12->m_faceMap,
              *(unsigned int *)((_BYTE *)v7->m_data + v9) & 0x3FFFFF);
      for ( i = v13->m_startEdgeIndex; i < v13->m_startEdgeIndex + v13->m_numEdges; ++i )
      {
        if ( hkaiNavMeshUtils::isEdgeInsideAabb(v12, v5, i) )
        {
          v16.m_faceKey = v10;
          if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v6, 8);
          v15 = &v6->m_data[v6->m_size];
          if ( v15 )
          {
            v16.m_edgeKey = i | ((_DWORD)v11 << 22);
            *v15 = v16;
          }
          ++v6->m_size;
        }
      }
      v7 = v19;
      v8 = v18;
      v9 = v17 + 4;
      ++v4;
      v17 += 4i64;
    }
    while ( v4 < v19->m_size );
  }
}

// File Line: 2112
// RVA: 0xBC5D40
void __fastcall hkaiNavMeshUtils::resolveEdgePenetrations(hkaiStreamingCollection *collection, hkaiNavMeshQueryMediator *mediator, hkVector4f *point, hkSimdFloat32 *radius, hkVector4f *pointOut)
{
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  hkBaseObjectVtbl *v7; // rax
  __int64 v8; // r14
  hkaiNavMeshQueryMediator *v9; // rbx
  hkVector4f *v10; // r13
  hkSimdFloat32 *v11; // rdi
  unsigned int v12; // eax
  __m128 v13; // xmm0
  unsigned int v14; // er12
  hkVector4f v15; // xmm0
  hkaiNavMeshQueryMediator *v16; // rdx
  hkaiStreamingCollection *v17; // rbx
  int v18; // er15
  int v19; // esi
  int v20; // ebx
  unsigned int v21; // edi
  hkaiNavMeshInstance *v22; // rcx
  hkaiNavMesh::Edge *v23; // rax
  __m128 v24; // xmm9
  hkaiStreamingCollection::InstanceInfo *v25; // rax
  __int64 v26; // rdi
  hkaiNavMesh::Face *v27; // r14
  hkVector4f *v28; // r9
  hkVector4f *v29; // r9
  signed __int64 v30; // rcx
  __m128 *v31; // r13
  __m128 v32; // xmm15
  float v33; // xmm14_4
  hkaiStreamingCollection::InstanceInfo *v34; // r12
  _DWORD *v35; // rsi
  __int64 v36; // r15
  hkaiNavMeshInstance *v37; // rbx
  hkaiNavMesh::Edge *v38; // rax
  signed int v39; // edx
  __int64 v40; // rcx
  __m128 *v41; // rcx
  __m128 v42; // xmm3
  __m128 v43; // xmm4
  __int64 v44; // rax
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
  int v78; // ebx
  hkaiNavMesh::Edge *v79; // rax
  __m128 v80; // xmm1
  __m128 v81; // xmm1
  __m128 v82; // xmm0
  __m128 v83; // xmm1
  hkVector4f *index; // [rsp+28h] [rbp-D0h]
  _DWORD *array; // [rsp+30h] [rbp-C8h]
  unsigned int v86; // [rsp+38h] [rbp-C0h]
  int v87; // [rsp+3Ch] [rbp-BCh]
  hkArray<hkaiNavMeshUtils::FaceEdgeKeyPair,hkContainerTempAllocator> edgeHits; // [rsp+40h] [rbp-B8h]
  __int64 v89; // [rsp+50h] [rbp-A8h]
  int faceIndex[4]; // [rsp+60h] [rbp-98h]
  hkAabb aabb; // [rsp+70h] [rbp-88h]
  __int128 v92; // [rsp+98h] [rbp-60h]
  __int128 v93; // [rsp+A8h] [rbp-50h]
  int v94; // [rsp+B8h] [rbp-40h]
  __int64 v95; // [rsp+C0h] [rbp-38h]
  __int128 v96; // [rsp+C8h] [rbp-30h]
  __int64 v97; // [rsp+D8h] [rbp-20h]
  __int128 v98; // [rsp+E8h] [rbp-10h]
  __int128 v99; // [rsp+F8h] [rbp+0h]
  __int64 v100; // [rsp+108h] [rbp+10h]
  hkaiStreamingCollection *retaddr; // [rsp+208h] [rbp+110h]
  unsigned int mesh; // [rsp+210h] [rbp+118h]
  unsigned int mesha; // [rsp+210h] [rbp+118h]
  signed __int64 v104; // [rsp+218h] [rbp+120h]
  __m128 *v105; // [rsp+220h] [rbp+128h]
  hkSimdFloat32 *v106; // [rsp+228h] [rbp+130h]

  v106 = radius;
  v5 = point->m_quad;
  v6 = radius->m_real;
  _mm_store_si128((__m128i *)&v96, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v98, (__m128i)v5);
  v7 = mediator->vfptr;
  v8 = 0i64;
  _mm_store_si128((__m128i *)&v99, (__m128i)_mm_mul_ps(v6, (__m128)xmmword_141A710D0));
  v9 = mediator;
  v10 = point;
  v11 = radius;
  edgeHits.m_data = 0i64;
  edgeHits.m_size = 0;
  edgeHits.m_capacityAndFlags = 2147483648;
  array = 0i64;
  v86 = 0;
  v87 = 2147483648;
  v94 = 0;
  v95 = 0i64;
  v97 = 0i64;
  v100 = 0i64;
  v12 = ((__int64 (__fastcall *)(hkaiNavMeshQueryMediator *, int *, hkAabb *))v7[1].__first_virtual_table_function__)(
          mediator,
          &v94,
          &aabb);
  v13 = v10->m_quad;
  v14 = v12;
  mesh = v12;
  if ( v12 == -1 )
  {
    *v106 = (hkSimdFloat32)v13;
  }
  else
  {
    v15.m_quad = _mm_add_ps(v13, v11->m_real);
    v16 = v9;
    v17 = retaddr;
    *(__m128 *)((char *)&aabb.m_min.m_quad + 8) = _mm_sub_ps(v10->m_quad, v11->m_real);
    *(hkVector4f *)((char *)&aabb.m_max + 8) = (hkVector4f)v15.m_quad;
    hkaiNavMeshUtils::getEdgesInsideAabb(retaddr, v16, (hkAabb *)((char *)&aabb + 8), &edgeHits);
    v18 = edgeHits.m_size;
    v19 = 0;
    if ( edgeHits.m_size > 0 )
    {
      v20 = v86;
      do
      {
        v21 = *(unsigned int *)((char *)&edgeHits.m_data->m_edgeKey + v8);
        v22 = retaddr->m_instances.m_data[v21 >> 22].m_instancePtr;
        v23 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
                v22->m_originalEdges,
                v22->m_numOriginalEdges,
                &v22->m_instancedEdges,
                &v22->m_ownedEdges,
                &v22->m_edgeMap,
                *(unsigned int *)((_BYTE *)&edgeHits.m_data->m_edgeKey + v8) & 0x3FFFFF);
        if ( v23->m_oppositeEdge == -1 || v23->m_flags.m_storage & 0x20 )
        {
          if ( v20 == (v87 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 4);
            v20 = v86;
          }
          array[v20] = v21;
          v18 = edgeHits.m_size;
          v20 = v86++ + 1;
        }
        ++v19;
        v8 += 8i64;
      }
      while ( v19 < v18 );
      v14 = mesh;
      v17 = retaddr;
    }
    v24 = v10->m_quad;
    mesha = v14 & 0x3FFFFF;
    v25 = v17->m_instances.m_data;
    v92 = _xmm;
    v93 = *(_OWORD *)_xmm;
    v26 = (__int64)v25[v14 >> 22].m_instancePtr;
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
      (unsigned __int64)faceIndex,
      v28);
    hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)v26,
      (hkaiNavMeshInstance *)(v14 & 0x3FFFFF),
      (unsigned __int64)&aabb.m_min.m_quad.m128_u64[1],
      v29);
    v30 = 2i64;
    v31 = (__m128 *)&v92;
    v104 = 2i64;
    v32 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
    v33 = *(float *)v105->m128_u64 * *(float *)v105->m128_u64;
    do
    {
      if ( (signed int)v86 > 0 )
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
          v39 = v37->m_numOriginalVertices;
          v40 = v38->m_a;
          if ( (signed int)v40 >= v39 )
            v41 = &v37->m_ownedVertices.m_data[(signed int)v40 - v39].m_quad;
          else
            v41 = &v37->m_originalVertices[v40].m_quad;
          v42 = v37->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
          v43 = v37->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
          v44 = v38->m_b;
          v45 = v37->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
          v46 = v37->m_referenceFrame.m_transform.m_translation.m_quad;
          v47 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(*v41, *v41, 0), v43),
                      _mm_mul_ps(_mm_shuffle_ps(*v41, *v41, 85), v42)),
                    _mm_mul_ps(_mm_shuffle_ps(*v41, *v41, 170), v45)),
                  v46);
          if ( (signed int)v44 >= v39 )
            v48 = &v37->m_ownedVertices.m_data[(signed int)v44 - v39].m_quad;
          else
            v48 = &v37->m_originalVertices[v44].m_quad;
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
          v59 = _mm_cmpltps(v58, query.m_quad);
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
            v67 = _mm_sub_ps(*(__m128 *)((char *)&aabb.m_min.m_quad + 8), v65);
            v68 = _mm_mul_ps(v66, v67);
            v69 = _mm_cmpltps(v32, v64);
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
                        *v105,
                        _mm_xor_ps(
                          _mm_andnot_ps(
                            _mm_cmpleps(v64, (__m128)0i64),
                            _mm_mul_ps(
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v77, v64), v77)),
                                _mm_mul_ps(*(__m128 *)_xmm, v77)),
                              v64)),
                          v70)),
                      _mm_mul_ps(
                        v73,
                        _mm_andnot_ps(
                          _mm_cmpleps(v75, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v76, v75), v76)),
                            _mm_mul_ps(*(__m128 *)_xmm, v76))))));
          }
          ++v35;
          --v36;
        }
        while ( v36 );
        v26 = v89;
        v30 = v104;
      }
      v78 = v27->m_startEdgeIndex;
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
                  v78);
          if ( v79->m_oppositeEdge != -1 && !(v79->m_flags.m_storage & 0x20) )
          {
            hkaiNavMeshUtils::calcEdgePlane<hkaiNavMeshInstance>(
              (hkaiNavMeshUtils *)v26,
              (hkaiNavMeshInstance *)mesha,
              v78,
              (unsigned __int64)faceIndex,
              &aabb.m_min,
              index);
            v80 = _mm_mul_ps(aabb.m_min.m_quad, v24);
            v81 = _mm_shuffle_ps(v80, _mm_unpackhi_ps(v80, aabb.m_min.m_quad), 196);
            v82 = _mm_add_ps(_mm_shuffle_ps(v81, v81, 78), v81);
            v83 = _mm_add_ps(_mm_shuffle_ps(v82, v82, 177), v82);
            if ( v83.m128_f32[0] > 0.0 )
              v24 = _mm_sub_ps(v24, _mm_mul_ps(_mm_mul_ps(v83, *v31), aabb.m_min.m_quad));
          }
          ++v78;
        }
        while ( v78 < v27->m_startEdgeIndex + v27->m_numEdges );
        v30 = v104;
      }
      v17 = retaddr;
      ++v31;
      v104 = --v30;
    }
    while ( v30 );
    LODWORD(v8) = 0;
    *v106 = (hkSimdFloat32)v24;
  }
  v86 = v8;
  if ( v87 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v87);
  array = 0i64;
  edgeHits.m_size = 0;
  v87 = 2147483648;
  if ( edgeHits.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      edgeHits.m_data,
      8 * edgeHits.m_capacityAndFlags);
}

// File Line: 2230
// RVA: 0xBC6550
hkaiStaticTreeNavMeshQueryMediator *__fastcall hkaiNavMeshUtils::setupQueryMediator(hkaiNavMesh *mesh, hkaiNavMeshUtils::MediatorType mediatorType)
{
  hkaiNavMesh *v2; // rdi
  _QWORD **v3; // rax
  hkaiStaticTreeNavMeshQueryMediator *v4; // rax
  hkaiStaticTreeNavMeshQueryMediator *v5; // rax
  hkaiStaticTreeNavMeshQueryMediator *v6; // rbx

  v2 = mesh;
  hkaiNavMeshUtils::validate(mesh, 1);
  v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (hkaiStaticTreeNavMeshQueryMediator *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v3[11] + 8i64))(
                                               v3[11],
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
  hkaiStaticTreeNavMeshQueryMediator::setNavMesh(v6, v2);
  return v6;
}

// File Line: 2246
// RVA: 0xBC3920
void __fastcall hkaiNavMeshUtils::getNearbyBoundaries(hkaiStreamingCollection::InstanceInfo *streamingInfo, unsigned int currentFaceKey, hkAabb *aabb, hkaiAgentTraversalInfo *traversalInfo, hkaiAstarEdgeFilter *filter, bool doFloodFill, hkVector4f *position, hkVector4f *up, hkArrayBase<hkVector4f> *boundariesOut)
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
void __fastcall hkaiNavMeshUtils::_getNearbyBoundariesFlood(hkaiStreamingCollection::InstanceInfo *streamingInfo, unsigned int inputFaceKey, hkAabb *aabb, hkaiAgentTraversalInfo *traversalInfo, hkaiAstarEdgeFilter *filter, hkVector4f *position, hkVector4f *up, hkArrayBase<hkVector4f> *boundariesOut)
{
  hkaiStreamingCollection::InstanceInfo *v8; // rbx
  hkAabb *v9; // rsi
  unsigned int v10; // edi
  _QWORD *v11; // rax
  _QWORD *v12; // rcx
  _QWORD *v13; // r10
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx
  signed int v16; // er12
  __m128 v17; // xmm2
  __m128 v18; // xmm10
  __m128 v19; // xmm2
  float v20; // xmm11_4
  hkLifoAllocator *v21; // rax
  bool v22; // sf
  unsigned __int8 v23; // of
  unsigned __int64 v24; // rcx
  int v25; // ebx
  hkLifoAllocator *v26; // rax
  char *v27; // rsi
  int v28; // edx
  char *v29; // rcx
  hkaiAgentTraversalInfo *v30; // r13
  __m128 v31; // xmm6
  int v32; // er15
  int v33; // er11
  int v34; // er9
  int v35; // edx
  unsigned int v36; // er8
  int v37; // eax
  int v38; // er10
  int v39; // er9
  signed int v40; // er11
  int v41; // edx
  unsigned int v42; // er8
  hkaiNavMesh::Face *v43; // rax
  hkaiNavMesh::Face *v44; // r13
  int v45; // ecx
  hkaiNavMeshInstance *v46; // rbx
  unsigned int v47; // esi
  int index; // ecx
  int v49; // er13
  hkaiNavMesh::Edge *v50; // rax
  int v51; // edx
  __int64 v52; // rsi
  __int64 v53; // rax
  hkVector4f *v54; // rcx
  __int64 v55; // rax
  __m128 v56; // xmm5
  hkVector4f *v57; // rax
  __m128 v58; // xmm1
  __m128 v59; // xmm8
  __m128 v60; // xmm3
  __m128 v61; // xmm7
  __m128 v62; // xmm2
  __m128 v63; // xmm2
  __m128 v64; // xmm4
  __m128 v65; // xmm1
  __m128 v66; // xmm3
  __m128 v67; // xmm1
  __m128 v68; // xmm2
  __m128 v69; // xmm1
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  __m128 v72; // xmm8
  __m128 v73; // xmm8
  hkaiAgentTraversalInfo v74; // rax
  int v75; // ecx
  unsigned int v76; // eax
  unsigned int v77; // er9
  int v78; // er10
  int v79; // edx
  unsigned int v80; // er8
  int v81; // eax
  __int64 v82; // rax
  float v83; // eax
  int v84; // eax
  char v85; // si
  unsigned int v86; // ebx
  hkaiNavMesh::Edge *v87; // rax
  __int64 v88; // rdx
  __int64 v89; // r8
  unsigned int v90; // er11
  unsigned int v91; // er10
  char v92; // cl
  int v93; // er9
  hkVector4f *v94; // rdx
  __m128 v95; // xmm2
  hkVector4f *v96; // rdx
  __m128 v97; // xmm1
  __m128 v98; // xmm0
  char v99; // cl
  unsigned int v100; // edx
  unsigned int v101; // eax
  signed int v102; // ebx
  hkLifoAllocator *v103; // rax
  void *v104; // rsi
  int v105; // er8
  hkLifoAllocator *v106; // rax
  _QWORD *v107; // rax
  _QWORD *v108; // rcx
  _QWORD *v109; // r8
  unsigned __int64 v110; // rax
  signed __int64 v111; // rcx
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > v112; // [rsp+60h] [rbp-98h]
  void *v113; // [rsp+78h] [rbp-80h]
  int v114; // [rsp+80h] [rbp-78h]
  int v115; // [rsp+84h] [rbp-74h]
  unsigned int v116; // [rsp+88h] [rbp-70h]
  unsigned int v117; // [rsp+8Ch] [rbp-6Ch]
  int v118; // [rsp+90h] [rbp-68h]
  void *p; // [rsp+98h] [rbp-60h]
  hkaiGeneralAccessor v120; // [rsp+A0h] [rbp-58h]
  int v121; // [rsp+B8h] [rbp-40h]
  int v122; // [rsp+BCh] [rbp-3Ch]
  int *v123; // [rsp+C0h] [rbp-38h]
  int *v124; // [rsp+C8h] [rbp-30h]
  int *dataPtrOut; // [rsp+D0h] [rbp-28h]
  int *v126; // [rsp+D8h] [rbp-20h]
  hkaiNavMesh::Face *v127; // [rsp+E0h] [rbp-18h]
  hkResult result; // [rsp+E8h] [rbp-10h]
  hkVector4f startInOut; // [rsp+F8h] [rbp+0h]
  hkVector4f endInOut; // [rsp+108h] [rbp+10h]
  hkaiNavMeshInstance *v131; // [rsp+118h] [rbp+20h]
  hkAabb *v132; // [rsp+120h] [rbp+28h]
  int *v133; // [rsp+128h] [rbp+30h]
  char v134; // [rsp+130h] [rbp+38h]
  int v135; // [rsp+138h] [rbp+40h]
  int *v136; // [rsp+140h] [rbp+48h]
  int *v137; // [rsp+148h] [rbp+50h]
  __m128 v138; // [rsp+158h] [rbp+60h]
  int v139; // [rsp+168h] [rbp+70h]
  __int64 v140; // [rsp+170h] [rbp+78h]
  int *v141; // [rsp+178h] [rbp+80h]
  __m128 v142; // [rsp+188h] [rbp+90h]
  unsigned int v143; // [rsp+198h] [rbp+A0h]
  hkaiNavMesh::Face *v144; // [rsp+1A0h] [rbp+A8h]
  int *v145; // [rsp+1A8h] [rbp+B0h]
  hkAabb *aabba; // [rsp+268h] [rbp+170h]
  hkAabb *v147; // [rsp+270h] [rbp+178h]
  hkaiAgentTraversalInfo *v148; // [rsp+278h] [rbp+180h]

  v148 = traversalInfo;
  v147 = aabb;
  v8 = streamingInfo;
  v9 = aabb;
  v10 = inputFaceKey;
  v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)v11[1];
  v13 = v11;
  if ( (unsigned __int64)v12 < v11[3] )
  {
    *v12 = "TtgetNearbyBoundariesFlood";
    v14 = __rdtsc();
    v15 = (signed __int64)(v12 + 2);
    *(_DWORD *)(v15 - 8) = v14;
    v13[1] = v15;
  }
  if ( v10 != -1 )
  {
    v120.m_currentSection = -1;
    v120.m_sectionInfo = v8;
    v120.m_accessor = 0i64;
    hkaiGeneralAccessor::setSection(&v120, v10 >> 22);
    v16 = 0;
    v17 = _mm_mul_ps(_mm_sub_ps(v9->m_max.m_quad, v9->m_min.m_quad), (__m128)xmmword_141A711B0);
    v18 = _mm_mul_ps(_mm_add_ps(v9->m_min.m_quad, v9->m_max.m_quad), (__m128)xmmword_141A711B0);
    v19 = _mm_mul_ps(v17, v17);
    v20 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 0)))
        + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 170));
    v21 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v23 = __OFSUB__(v21->m_slabSize, 256);
    v22 = v21->m_slabSize - 256 < 0;
    v24 = (unsigned __int64)v21->m_cur + 256;
    v113 = v21->m_cur;
    if ( v22 ^ v23 || (void *)v24 > v21->m_end )
      v113 = hkLifoAllocator::allocateFromNewSlab(v21, 256);
    else
      v21->m_cur = (void *)v24;
    v25 = hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::getSizeInBytesFor(64);
    v122 = v25;
    if ( v25 )
    {
      v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v27 = (char *)v26->m_cur;
      v28 = (v25 + 127) & 0xFFFFFF80;
      p = v27;
      v29 = &v27[v28];
      if ( v28 > v26->m_slabSize || v29 > v26->m_end )
      {
        v27 = (char *)hkLifoAllocator::allocateFromNewSlab(v26, v28);
        p = v27;
      }
      else
      {
        v26->m_cur = v29;
      }
    }
    else
    {
      v27 = 0i64;
      p = 0i64;
    }
    v121 = v25 | 0x80000000;
    hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>(
      &v112,
      v27,
      v25);
    v30 = v148;
    v31 = v18;
    v124 = 0i64;
    v123 = 0i64;
    v118 = 4;
    v32 = -1;
    HIDWORD(v113) = -1;
    v117 = -1;
    v116 = -1;
    while ( 1 )
    {
      v33 = v112.m_elem.m_size;
      v34 = v112.m_elem.m_size - 1;
      if ( v112.m_elem.m_size - 1 <= 0
        || (v35 = v34 & -1640531535 * (v10 >> 4), v36 = v112.m_elem.m_data[v35], v36 == -1) )
      {
LABEL_19:
        v37 = v112.m_elem.m_size;
      }
      else
      {
        while ( v36 != v10 )
        {
          v35 = v34 & (v35 + 1);
          v36 = v112.m_elem.m_data[v35];
          if ( v36 == -1 )
            goto LABEL_19;
        }
        v37 = v35;
      }
      if ( v37 > v34 )
      {
        v38 = v112.m_numElems;
        if ( 2 * v112.m_numElems > v34 )
          break;
        if ( 2 * v112.m_numElems > v34 )
        {
          hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
            &v112,
            &result,
            2 * v34 + 2);
          v38 = v112.m_numElems;
          v33 = v112.m_elem.m_size;
        }
        v39 = v33 - 1;
        v40 = 1;
        v41 = v39 & -1640531535 * (v10 >> 4);
        v42 = v112.m_elem.m_data[v41];
        if ( v42 != -1 )
        {
          while ( v42 != v10 )
          {
            v41 = v39 & (v41 + 1);
            v42 = v112.m_elem.m_data[v41];
            if ( v42 == -1 )
              goto LABEL_30;
          }
          v40 = 0;
        }
LABEL_30:
        v112.m_numElems = v40 + v38;
        v112.m_elem.m_data[v41] = v10;
        hkaiGeneralAccessor::setSection(&v120, v10 >> 22);
        v43 = hkaiNavMeshInstance_getWithData_hkaiNavMesh::Face_int_(
                v120.m_accessor->m_originalFaces,
                v120.m_accessor->m_numOriginalFaces,
                &v120.m_accessor->m_instancedFaces,
                &v120.m_accessor->m_ownedFaces,
                v120.m_accessor->m_originalFaceData,
                &v120.m_accessor->m_instancedFaceData,
                &v120.m_accessor->m_ownedFaceData,
                &v120.m_accessor->m_faceMap,
                v10 & 0x3FFFFF,
                v120.m_accessor->m_faceDataStriding,
                (const int **)&dataPtrOut);
        v136 = 0i64;
        v140 = 0i64;
        v44 = v43;
        v127 = v43;
        v144 = 0i64;
        v135 = -1;
        v139 = -1;
        v143 = -1;
        if ( v148 )
        {
          v144 = v43;
          v138 = v31;
          v135 = HIDWORD(v113);
          v143 = v10;
          v136 = v124;
          v145 = dataPtrOut;
          v137 = v123;
        }
        v45 = 0;
        LODWORD(v113) = 0;
        if ( v43->m_numEdges > 0 )
        {
          v46 = v120.m_accessor;
          v47 = v10 >> 22 << 22;
          do
          {
            index = v44->m_startEdgeIndex + v45;
            v49 = index | v47;
            if ( (index | v47) != v32 )
            {
              v50 = hkaiNavMeshInstance_getWithData_hkaiNavMesh::Edge_int_(
                      v46->m_originalEdges,
                      v46->m_numOriginalEdges,
                      &v46->m_instancedEdges,
                      &v46->m_ownedEdges,
                      v46->m_originalEdgeData,
                      &v46->m_instancedEdgeData,
                      &v46->m_ownedEdgeData,
                      &v46->m_edgeMap,
                      index,
                      v46->m_edgeDataStriding,
                      (const int **)&v126);
              v46 = v120.m_accessor;
              v51 = v120.m_accessor->m_numOriginalVertices;
              v52 = (__int64)v50;
              v53 = v50->m_a;
              if ( (signed int)v53 >= v51 )
                v54 = &v120.m_accessor->m_ownedVertices.m_data[(signed int)v53 - v51];
              else
                v54 = &v120.m_accessor->m_originalVertices[v53];
              v55 = *(signed int *)(v52 + 4);
              v56 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_shuffle_ps(v54->m_quad, v54->m_quad, 85),
                            v120.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                          _mm_mul_ps(
                            _mm_shuffle_ps(v54->m_quad, v54->m_quad, 0),
                            v120.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                        _mm_mul_ps(
                          _mm_shuffle_ps(v54->m_quad, v54->m_quad, 170),
                          v120.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
                      v120.m_accessor->m_referenceFrame.m_transform.m_translation.m_quad);
              if ( (signed int)v55 >= v51 )
                v57 = &v120.m_accessor->m_ownedVertices.m_data[(signed int)v55 - v51];
              else
                v57 = &v120.m_accessor->m_originalVertices[v55];
              v58 = v57->m_quad;
              v59 = _mm_sub_ps(v56, v18);
              v60 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_shuffle_ps(v58, v58, 85),
                            v120.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                          _mm_mul_ps(
                            _mm_shuffle_ps(v58, v58, 0),
                            v120.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                        _mm_mul_ps(
                          _mm_shuffle_ps(v58, v58, 170),
                          v120.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
                      v120.m_accessor->m_referenceFrame.m_transform.m_translation.m_quad);
              startInOut.m_quad = v56;
              endInOut.m_quad = v60;
              v61 = _mm_sub_ps(v60, v56);
              v62 = _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v61, v61, 201), v59),
                      _mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v61));
              v63 = _mm_mul_ps(_mm_shuffle_ps(v62, v62, 201), position->m_quad);
              if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 170))) >= 0.0 )
              {
                v64 = _mm_sub_ps(v56, v60);
                v65 = _mm_mul_ps(v64, v64);
                v66 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)),
                        _mm_shuffle_ps(v65, v65, 170));
                v67 = _mm_mul_ps(v59, v64);
                v68 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v67, v67, 85), _mm_shuffle_ps(v67, v67, 0)),
                        _mm_shuffle_ps(v67, v67, 170));
                v69 = _mm_rcp_ps(v66);
                v70 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v69, v66)), v69), v68);
                v71 = _mm_cmpltps(v70, query.m_quad);
                v72 = _mm_sub_ps(
                        v59,
                        _mm_mul_ps(
                          _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v71, query.m_quad), _mm_and_ps(v71, v70))),
                          v64));
                v73 = _mm_mul_ps(v72, v72);
                if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v73, v73, 85))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v73, v73, 0)))
                           + COERCE_FLOAT(_mm_shuffle_ps(v73, v73, 170))) < v20 )
                {
                  if ( *(_DWORD *)(v52 + 8) != -1 && !(*(_BYTE *)(v52 + 16) & 0x20) )
                  {
                    if ( !v148 )
                      goto LABEL_48;
                    v141 = v126;
                    v139 = v49;
                    v132 = v147;
                    v140 = v52;
                    v142 = _mm_add_ps(_mm_mul_ps(v61, (__m128)xmmword_141A711B0), v56);
                    v133 = &v135;
                    v74 = *v148;
                    v131 = v120.m_accessor;
                    v134 = 4;
                    if ( (*(unsigned __int8 (__fastcall **)(hkaiAgentTraversalInfo *, hkaiNavMeshInstance **))(*(_QWORD *)&v74 + 40i64))(
                           v148,
                           &v131) )
                    {
                      v46 = v120.m_accessor;
LABEL_48:
                      if ( v16 >= 64 )
                        goto LABEL_90;
                      v75 = *(_DWORD *)(v52 + 12);
                      if ( *(_BYTE *)(v52 + 16) & 0x40 )
                        v76 = v75 & 0xFFC00000;
                      else
                        v76 = v46->m_runtimeId << 22;
                      v77 = v76 | v75 & 0x3FFFFF;
                      if ( v75 == -1 )
                        v77 = -1;
                      v78 = v112.m_elem.m_size - 1;
                      if ( v112.m_elem.m_size - 1 <= 0
                        || (v79 = v78 & -1640531535 * (v77 >> 4), v80 = v112.m_elem.m_data[v79], v80 == -1) )
                      {
LABEL_58:
                        v81 = v112.m_elem.m_size;
                      }
                      else
                      {
                        while ( v80 != v77 )
                        {
                          v79 = v78 & (v79 + 1);
                          v80 = v112.m_elem.m_data[v79];
                          if ( v80 == -1 )
                            goto LABEL_58;
                        }
                        v81 = v79;
                      }
                      v47 = v10 >> 22 << 22;
                      if ( v81 > v78 )
                      {
                        v82 = v16++;
                        *((_DWORD *)v113 + v82) = v49;
                        v46 = v120.m_accessor;
                      }
                      goto LABEL_66;
                    }
                  }
                  if ( hkaiAvoidanceSolverUtils::clipSegmentInsideAabb(aabba, &startInOut, &endInOut) )
                  {
                    *(hkVector4f *)(up->m_quad.m128_u64[0] + 16i64 * up->m_quad.m128_i32[2]++) = (hkVector4f)startInOut.m_quad;
                    *(hkVector4f *)(up->m_quad.m128_u64[0] + 16i64 * up->m_quad.m128_i32[2]) = (hkVector4f)endInOut.m_quad;
                    v83 = up->m_quad.m128_f32[3];
                    if ( ++up->m_quad.m128_i32[2] == (LODWORD(v83) & 0x3FFFFFFF) )
                      goto LABEL_90;
                  }
                  v46 = v120.m_accessor;
                }
              }
              v47 = v10 >> 22 << 22;
            }
LABEL_66:
            v44 = v127;
            v84 = v127->m_numEdges;
            v45 = (_DWORD)v113 + 1;
            LODWORD(v113) = v45;
          }
          while ( v45 < v84 );
        }
        v30 = v148;
      }
      v85 = 0;
      if ( !v16 )
        break;
      do
      {
        if ( v85 )
          break;
        v85 = 1;
        v86 = *((_DWORD *)v113 + v16-- - 1);
        HIDWORD(v113) = v86;
        hkaiGeneralAccessor::setSection(&v120, v86 >> 22);
        v87 = hkaiNavMeshInstance_getWithData_hkaiNavMesh::Edge_int_(
                v120.m_accessor->m_originalEdges,
                v120.m_accessor->m_numOriginalEdges,
                &v120.m_accessor->m_instancedEdges,
                &v120.m_accessor->m_ownedEdges,
                v120.m_accessor->m_originalEdgeData,
                &v120.m_accessor->m_instancedEdgeData,
                &v120.m_accessor->m_ownedEdgeData,
                &v120.m_accessor->m_edgeMap,
                v86 & 0x3FFFFF,
                v120.m_accessor->m_edgeDataStriding,
                (const int **)&v123);
        v88 = v87->m_a;
        v114 = v87->m_a;
        v89 = v87->m_b;
        v115 = v87->m_b;
        v90 = v87->m_oppositeEdge;
        v116 = v87->m_oppositeEdge;
        v91 = v87->m_oppositeFace;
        v117 = v87->m_oppositeFace;
        v92 = v87->m_flags.m_storage;
        v118 = *(_DWORD *)&v87->m_flags.m_storage;
        if ( v30 )
        {
          v93 = v120.m_accessor->m_numOriginalVertices;
          if ( (signed int)v88 >= v93 )
            v94 = &v120.m_accessor->m_ownedVertices.m_data[(signed int)v88 - v93];
          else
            v94 = &v120.m_accessor->m_originalVertices[v88];
          v95 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(v94->m_quad, v94->m_quad, 85),
                        v120.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                      _mm_mul_ps(
                        _mm_shuffle_ps(v94->m_quad, v94->m_quad, 0),
                        v120.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                    _mm_mul_ps(
                      _mm_shuffle_ps(v94->m_quad, v94->m_quad, 170),
                      v120.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
                  v120.m_accessor->m_referenceFrame.m_transform.m_translation.m_quad);
          if ( (signed int)v89 >= v93 )
            v96 = &v120.m_accessor->m_ownedVertices.m_data[(signed int)v89 - v93];
          else
            v96 = &v120.m_accessor->m_originalVertices[v89];
          v97 = v96->m_quad;
          v98 = v96->m_quad;
          v124 = &v114;
          v31 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(v97, v97, 85),
                              v120.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                            _mm_mul_ps(
                              _mm_shuffle_ps(v98, v97, 0),
                              v120.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                          _mm_mul_ps(
                            _mm_shuffle_ps(v97, v97, 170),
                            v120.m_accessor->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
                        v120.m_accessor->m_referenceFrame.m_transform.m_translation.m_quad),
                      v95),
                    (__m128)xmmword_141A711B0),
                  v95);
        }
        v99 = v92 & 0x40;
        if ( v99 )
          v100 = v91 & 0xFFC00000;
        else
          v100 = v120.m_accessor->m_runtimeId << 22;
        v10 = v100 | v91 & 0x3FFFFF;
        if ( v91 == -1 )
          v10 = -1;
        v101 = v99 ? v90 & 0xFFC00000 : v120.m_accessor->m_runtimeId << 22;
        v32 = v101 | v90 & 0x3FFFFF;
        if ( v90 == -1 )
          v32 = -1;
      }
      while ( v16 );
    }
LABEL_90:
    v112.m_elem.m_size = 0;
    if ( v112.m_elem.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v112.m_elem.m_data,
        4 * v112.m_elem.m_capacityAndFlags);
    v112.m_elem.m_data = 0i64;
    v112.m_elem.m_capacityAndFlags = 2147483648;
    v102 = (v122 + 127) & 0xFFFFFF80;
    v103 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v104 = p;
    v105 = (v102 + 15) & 0xFFFFFFF0;
    if ( v102 > v103->m_slabSize || (char *)p + v105 != v103->m_cur || v103->m_firstNonLifoEnd == p )
      hkLifoAllocator::slowBlockFree(v103, p, v105);
    else
      v103->m_cur = p;
    if ( v121 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v104,
        v121 & 0x3FFFFFFF);
    v106 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    if ( v106->m_slabSize < 256 || (char *)v113 + 256 != v106->m_cur || v106->m_firstNonLifoEnd == v113 )
      hkLifoAllocator::slowBlockFree(v106, v113, 256);
    else
      v106->m_cur = v113;
  }
  v107 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v108 = (_QWORD *)v107[1];
  v109 = v107;
  if ( (unsigned __int64)v108 < v107[3] )
  {
    *v108 = "Et";
    v110 = __rdtsc();
    v111 = (signed __int64)(v108 + 2);
    *(_DWORD *)(v111 - 8) = v110;
    v109[1] = v111;
  }
}

// File Line: 2452
// RVA: 0xBC39A0
void __fastcall hkaiNavMeshUtils::_getNearbyBoundariesNeighbors(hkaiStreamingCollection::InstanceInfo *streamingInfo, unsigned int currentFaceKey, hkAabb *aabb, hkaiAgentTraversalInfo *traversalInfo, hkaiAstarEdgeFilter *modifier, hkVector4f *position, hkArrayBase<hkVector4f> *boundariesOut)
{
  hkaiStreamingCollection::InstanceInfo *v7; // r15
  unsigned int v8; // er14
  _QWORD *v9; // r11
  unsigned __int64 v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // r8
  _QWORD *v13; // rcx
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx
  hkaiNavMeshInstance *v16; // rbx
  int v17; // edx
  hkaiNavMesh::Face *v18; // rsi
  int v19; // er12
  int v20; // edi
  hkLifoAllocator *v21; // rax
  int *v22; // r13
  int v23; // edx
  char *v24; // rcx
  int v25; // eax
  signed int v26; // edi
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v27; // r9
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v28; // r8
  hkaiNavMesh::Edge *v29; // rax
  unsigned int v30; // edx
  unsigned int v31; // eax
  int v32; // ecx
  __int64 v33; // rax
  __int64 v34; // rax
  int v35; // er12
  _QWORD *v36; // r8
  _QWORD *v37; // rcx
  unsigned __int64 v38; // rax
  signed __int64 v39; // rcx
  int v40; // edi
  int *v41; // rax
  __int64 v42; // rbx
  hkaiNavMesh::Face *v43; // r15
  int index; // er14
  hkArray<int,hkContainerHeapAllocator> *ownedData; // rdx
  hkArray<int,hkContainerHeapAllocator> *v46; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v47; // rcx
  hkaiNavMesh::Edge *v48; // rdi
  signed int v49; // eax
  __int64 v50; // rax
  signed int v51; // ecx
  __m128 *v52; // rax
  __m128 v53; // xmm1
  __m128 v54; // xmm4
  __m128 v55; // xmm5
  __int64 v56; // rax
  __m128 v57; // xmm6
  __m128 v58; // xmm7
  __m128 v59; // xmm3
  __m128 *v60; // rax
  __m128 v61; // xmm1
  hkaiNavMesh::Edge *v62; // rax
  signed int v63; // edx
  __int64 v64; // rcx
  __m128 *v65; // rcx
  __m128 v66; // xmm3
  __m128 v67; // xmm4
  __int64 v68; // rax
  __m128 v69; // xmm5
  __m128 v70; // xmm6
  __m128 v71; // xmm2
  __m128 *v72; // rax
  __m128 v73; // xmm1
  float v74; // eax
  signed int v75; // ebx
  hkLifoAllocator *v76; // rax
  int v77; // er8
  _QWORD *v78; // rax
  _QWORD *v79; // rcx
  _QWORD *v80; // r8
  unsigned __int64 v81; // rax
  signed __int64 v82; // rcx
  int v83; // [rsp+60h] [rbp-98h]
  int v84; // [rsp+64h] [rbp-94h]
  int v85; // [rsp+68h] [rbp-90h]
  signed int v86; // [rsp+6Ch] [rbp-8Ch]
  unsigned int v87; // [rsp+70h] [rbp-88h]
  int *v88; // [rsp+78h] [rbp-80h]
  int *v89; // [rsp+80h] [rbp-78h]
  int *dataPtrOut; // [rsp+88h] [rbp-70h]
  hkVector4f startInOut; // [rsp+98h] [rbp-60h]
  hkVector4f endInOut; // [rsp+A8h] [rbp-50h]
  __int64 v93; // [rsp+B8h] [rbp-40h]
  hkAabb *v94; // [rsp+C0h] [rbp-38h]
  int *v95; // [rsp+C8h] [rbp-30h]
  char v96; // [rsp+D0h] [rbp-28h]
  int v97; // [rsp+D8h] [rbp-20h]
  __int64 v98; // [rsp+E0h] [rbp-18h]
  __int64 v99; // [rsp+E8h] [rbp-10h]
  __int128 v100; // [rsp+F8h] [rbp+0h]
  unsigned int v101; // [rsp+108h] [rbp+10h]
  hkaiNavMesh::Edge *v102; // [rsp+110h] [rbp+18h]
  int *v103; // [rsp+118h] [rbp+20h]
  __m128 v104; // [rsp+128h] [rbp+30h]
  int v105; // [rsp+138h] [rbp+40h]
  hkaiNavMesh::Face *v106; // [rsp+140h] [rbp+48h]
  int *v107; // [rsp+148h] [rbp+50h]
  hkaiStreamingCollection::InstanceInfo *retaddr; // [rsp+1C8h] [rbp+D0h]
  hkaiStreamingCollection::InstanceInfo *v109; // [rsp+1D0h] [rbp+D8h]
  int v110; // [rsp+1D0h] [rbp+D8h]
  hkAabb *aabba; // [rsp+1D8h] [rbp+E0h]
  hkAabb *v112; // [rsp+1E0h] [rbp+E8h]
  hkaiAgentTraversalInfo *v113; // [rsp+1E8h] [rbp+F0h]

  v113 = traversalInfo;
  v112 = aabb;
  LODWORD(aabba) = currentFaceKey;
  v109 = streamingInfo;
  v7 = streamingInfo;
  v8 = currentFaceKey;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = v9[1];
  if ( v10 < v9[3] )
  {
    *(_QWORD *)v10 = "LtgetBoundariesNeighbors";
    *(_QWORD *)(v10 + 16) = "Stinit";
    v11 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v11;
    v9[1] = v10 + 24;
  }
  if ( v8 != -1 )
  {
    v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v13 = (_QWORD *)v12[1];
    if ( (unsigned __int64)v13 < v12[3] )
    {
      *v13 = "Stneighbors";
      v14 = __rdtsc();
      v15 = (signed __int64)(v13 + 2);
      *(_DWORD *)(v15 - 8) = v14;
      v12[1] = v15;
    }
    v16 = v7[v8 >> 22].m_instancePtr;
    v17 = v16->m_numOriginalFaces;
    if ( (signed int)(v8 & 0x3FFFFF) < v17 + v16->m_ownedFaces.m_size )
    {
      v18 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
              v16->m_originalFaces,
              v17,
              &v16->m_instancedFaces,
              &v16->m_ownedFaces,
              &v16->m_faceMap,
              v8 & 0x3FFFFF);
      v19 = 0;
      v20 = v18->m_numEdges + 1;
      v84 = v18->m_numEdges + 1;
      if ( v18->m_numEdges == -1 )
      {
        v22 = 0i64;
      }
      else
      {
        v21 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v22 = (int *)v21->m_cur;
        v23 = (4 * v20 + 127) & 0xFFFFFF80;
        v24 = (char *)v22 + v23;
        if ( v23 > v21->m_slabSize || v24 > v21->m_end )
          v22 = (int *)hkLifoAllocator::allocateFromNewSlab(v21, v23);
        else
          v21->m_cur = v24;
      }
      v25 = v20;
      v26 = 0;
      v86 = v25 | 0x80000000;
      if ( v18->m_numEdges > 0 )
      {
        v27 = &v16->m_ownedEdges;
        v28 = &v16->m_instancedEdges;
        do
        {
          v29 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
                  v16->m_originalEdges,
                  v16->m_numOriginalEdges,
                  v28,
                  v27,
                  &v16->m_edgeMap,
                  v26 + v18->m_startEdgeIndex);
          if ( v29->m_oppositeEdge != -1 )
          {
            v30 = v29->m_oppositeFace;
            if ( v29->m_flags.m_storage & 0x40 )
              v31 = v30 & 0xFFC00000;
            else
              v31 = v16->m_runtimeId << 22;
            v32 = v31 | v30 & 0x3FFFFF;
            v33 = v19;
            if ( v30 == -1 )
              v32 = -1;
            ++v19;
            v22[v33] = v32;
          }
          ++v26;
        }
        while ( v26 < v18->m_numEdges );
        v8 = (unsigned int)v109;
        v7 = retaddr;
      }
      v34 = v19;
      v35 = v19 + 1;
      v22[v34] = v8;
      v83 = v35;
      v36 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v37 = (_QWORD *)v36[1];
      if ( (unsigned __int64)v37 < v36[3] )
      {
        *v37 = "StnarrowPhase";
        v38 = __rdtsc();
        v39 = (signed __int64)(v37 + 2);
        *(_DWORD *)(v39 - 8) = v38;
        v36[1] = v39;
      }
      v40 = 0;
      v110 = 0;
      if ( v35 > 0 )
      {
        v41 = v22;
        v88 = v22;
        while ( 1 )
        {
          v85 = *v41;
          v87 = (unsigned int)*v41 >> 22;
          v42 = (__int64)v7[v87].m_instancePtr;
          v43 = hkaiNavMeshInstance_getWithData_hkaiNavMesh::Face_int_(
                  *(hkaiNavMesh::Face **)(v42 + 16),
                  *(_DWORD *)(v42 + 24),
                  (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v42 + 240),
                  (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v42 + 272),
                  *(const int **)(v42 + 64),
                  (hkArray<int,hkContainerHeapAllocator> *)(v42 + 352),
                  (hkArray<int,hkContainerHeapAllocator> *)(v42 + 384),
                  (hkArray<int,hkContainerHeapAllocator> *)(v42 + 224),
                  *v41 & 0x3FFFFF,
                  *(_DWORD *)(v42 + 72),
                  (const int **)&dataPtrOut);
          index = v43->m_startEdgeIndex;
          if ( index < index + v43->m_numEdges )
            break;
LABEL_53:
          v7 = retaddr;
          ++v40;
          v41 = v88 + 1;
          v110 = v40;
          ++v88;
          if ( v40 >= v35 )
            goto LABEL_54;
        }
        ownedData = (hkArray<int,hkContainerHeapAllocator> *)(v42 + 400);
        v46 = (hkArray<int,hkContainerHeapAllocator> *)(v42 + 368);
        v47 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v42 + 256);
        while ( 1 )
        {
          v48 = hkaiNavMeshInstance_getWithData_hkaiNavMesh::Edge_int_(
                  *(hkaiNavMesh::Edge **)(v42 + 32),
                  *(_DWORD *)(v42 + 40),
                  v47,
                  (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v42 + 288),
                  *(const int **)(v42 + 80),
                  v46,
                  ownedData,
                  (hkArray<int,hkContainerHeapAllocator> *)(v42 + 208),
                  index,
                  *(_DWORD *)(v42 + 88),
                  (const int **)&v89);
          v49 = 1;
          if ( v48->m_oppositeEdge == -1 )
            goto LABEL_66;
          if ( !(v48->m_flags.m_storage & 0x20) && v113 )
          {
            v50 = v48->m_a;
            v51 = *(_DWORD *)(v42 + 56);
            v97 = -1;
            v98 = 0i64;
            v101 = -1;
            v102 = 0i64;
            v105 = -1;
            v106 = 0i64;
            if ( (signed int)v50 >= v51 )
              v52 = (__m128 *)(*(_QWORD *)(v42 + 304) + 16i64 * ((signed int)v50 - v51));
            else
              v52 = (__m128 *)(*(_QWORD *)(v42 + 48) + 16 * v50);
            v53 = *v52;
            v54 = *(__m128 *)(v42 + 128);
            v55 = *(__m128 *)(v42 + 112);
            v56 = v48->m_b;
            v57 = *(__m128 *)(v42 + 144);
            v58 = *(__m128 *)(v42 + 160);
            v59 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v53, v53, 0), v55),
                        _mm_mul_ps(_mm_shuffle_ps(v53, v53, 85), v54)),
                      _mm_mul_ps(_mm_shuffle_ps(v53, v53, 170), v57)),
                    v58);
            if ( (signed int)v56 >= v51 )
              v60 = (__m128 *)(*(_QWORD *)(v42 + 304) + 16i64 * ((signed int)v56 - v51));
            else
              v60 = (__m128 *)(*(_QWORD *)(v42 + 48) + 16 * v56);
            v61 = *v60;
            v97 = -1;
            v101 = index | (v87 << 22);
            v102 = v48;
            v103 = v89;
            v98 = 0i64;
            v99 = 0i64;
            v106 = v43;
            v93 = v42;
            v100 = *(_OWORD *)&modifier->vfptr;
            v96 = 4;
            v105 = v85;
            v107 = dataPtrOut;
            v104 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(v61, v61, 0), v55),
                               _mm_mul_ps(_mm_shuffle_ps(v61, v61, 85), v54)),
                             _mm_mul_ps(_mm_shuffle_ps(v61, v61, 170), v57)),
                           v58),
                         v59),
                       (__m128)xmmword_141A711B0),
                     v59);
            v94 = v112;
            v95 = &v97;
            v49 = (*(unsigned __int8 (__fastcall **)(hkaiAgentTraversalInfo *, __int64 *))(*(_QWORD *)v113 + 40i64))(
                    v113,
                    &v93);
          }
          if ( v48->m_oppositeEdge == -1 || v48->m_flags.m_storage & 0x20 || !v49 )
          {
LABEL_66:
            v62 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
                    *(hkaiNavMesh::Edge **)(v42 + 32),
                    *(_DWORD *)(v42 + 40),
                    (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v42 + 256),
                    (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v42 + 288),
                    (hkArray<int,hkContainerHeapAllocator> *)(v42 + 208),
                    index);
            v63 = *(_DWORD *)(v42 + 56);
            v64 = v62->m_a;
            v65 = (__m128 *)((signed int)v64 >= v63 ? *(_QWORD *)(v42 + 304) + 16i64 * ((signed int)v64 - v63) : *(_QWORD *)(v42 + 48) + 16 * v64);
            v66 = *(__m128 *)(v42 + 128);
            v67 = *(__m128 *)(v42 + 112);
            v68 = v62->m_b;
            v69 = *(__m128 *)(v42 + 144);
            v70 = *(__m128 *)(v42 + 160);
            v71 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(*v65, *v65, 0), v67),
                        _mm_mul_ps(_mm_shuffle_ps(*v65, *v65, 85), v66)),
                      _mm_mul_ps(_mm_shuffle_ps(*v65, *v65, 170), v69)),
                    v70);
            v72 = (__m128 *)((signed int)v68 >= v63 ? *(_QWORD *)(v42 + 304) + 16i64 * ((signed int)v68 - v63) : *(_QWORD *)(v42 + 48) + 16 * v68);
            v73 = *v72;
            startInOut.m_quad = v71;
            endInOut.m_quad = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v73, v73, 0), v67),
                                    _mm_mul_ps(_mm_shuffle_ps(v73, v73, 85), v66)),
                                  _mm_mul_ps(_mm_shuffle_ps(v73, v73, 170), v69)),
                                v70);
            if ( hkaiAvoidanceSolverUtils::clipSegmentInsideAabb(aabba, &startInOut, &endInOut) )
            {
              *(hkVector4f *)(position->m_quad.m128_u64[0] + 16i64 * position->m_quad.m128_i32[2]++) = (hkVector4f)startInOut.m_quad;
              *(hkVector4f *)(position->m_quad.m128_u64[0] + 16i64 * position->m_quad.m128_i32[2]) = (hkVector4f)endInOut.m_quad;
              v74 = position->m_quad.m128_f32[3];
              if ( ++position->m_quad.m128_i32[2] == (LODWORD(v74) & 0x3FFFFFFF) )
                break;
            }
          }
          ++index;
          v47 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v42 + 256);
          ownedData = (hkArray<int,hkContainerHeapAllocator> *)(v42 + 400);
          v46 = (hkArray<int,hkContainerHeapAllocator> *)(v42 + 368);
          if ( index >= v43->m_startEdgeIndex + v43->m_numEdges )
          {
            v35 = v83;
            v40 = v110;
            goto LABEL_53;
          }
        }
LABEL_54:
        v22 = v88;
      }
      v75 = (4 * v84 + 127) & 0xFFFFFF80;
      v76 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v77 = (v75 + 15) & 0xFFFFFFF0;
      if ( v75 > v76->m_slabSize || (char *)v22 + v77 != v76->m_cur || v76->m_firstNonLifoEnd == v22 )
        hkLifoAllocator::slowBlockFree(v76, v22, v77);
      else
        v76->m_cur = v22;
      if ( v86 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v22,
          4 * v86);
    }
  }
  v78 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v79 = (_QWORD *)v78[1];
  v80 = v78;
  if ( (unsigned __int64)v79 < v78[3] )
  {
    *v79 = "lt";
    v81 = __rdtsc();
    v82 = (signed __int64)(v79 + 2);
    *(_DWORD *)(v82 - 8) = v81;
    v80[1] = v82;
  }
}

// File Line: 2577
// RVA: 0xBC4D20
void __fastcall hkaiNavMeshUtils::ClosestBoundaryInput::ClosestBoundaryInput(hkaiNavMeshUtils::ClosestBoundaryInput *this)
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
void __fastcall hkaiNavMeshUtils::getDistanceToClosestBoundary(hkaiStreamingCollection *collection, hkaiNavMeshUtils::ClosestBoundaryInput *input, hkaiNavMeshUtils::ClosestBoundaryOutput *closestBoundary)
{
  hkaiStreamingCollection *v3; // r13
  hkaiNavMeshUtils::ClosestBoundaryOutput *v4; // rdi
  hkaiNavMeshUtils::ClosestBoundaryInput *v5; // rbx
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  __int64 v11; // r15
  hkLifoAllocator *v12; // rax
  char *v13; // rcx
  unsigned __int64 v14; // rdx
  unsigned int v15; // er14
  __m128 v16; // xmm10
  __m128 v17; // xmm6
  unsigned int *v18; // rsi
  __m128 v19; // xmm10
  int v20; // edi
  int v21; // er12
  int v22; // er8
  int v23; // ecx
  unsigned int v24; // edx
  int v25; // eax
  signed int v26; // er9
  int v27; // ecx
  unsigned int v28; // edx
  __int64 v29; // rbx
  int v30; // er13
  hkaiNavMesh::Face *v31; // rax
  __int64 v32; // r11
  int striding; // ecx
  int *v34; // r8
  int v35; // er14
  unsigned int v36; // ecx
  int index; // eax
  int v38; // er13
  hkaiNavMesh::Edge *v39; // rax
  signed int v40; // edx
  __int64 v41; // r15
  __int64 v42; // rax
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
  __m128 v60; // xmm1
  __m128 v61; // xmm5
  __m128 v62; // xmm5
  __m128 v63; // xmm9
  __int64 *v64; // r11
  int v65; // eax
  __m128 v66; // xmm8
  int *v67; // rax
  __int64 v68; // rax
  char v69; // al
  int v70; // ecx
  unsigned int v71; // eax
  unsigned int v72; // er8
  int v73; // er9
  int v74; // ecx
  unsigned int v75; // edx
  int v76; // eax
  unsigned __int64 *v77; // rdx
  int v78; // eax
  bool v79; // sf
  unsigned __int8 v80; // of
  char v81; // r13
  __m128 v82; // xmm0
  unsigned int v83; // ecx
  int v84; // er14
  hkaiNavMeshInstance *v85; // rbx
  int v86; // er12
  hkaiNavMesh::Edge *v87; // rax
  hkaiNavMesh::Edge *v88; // r11
  __int64 v89; // rcx
  signed int v90; // edx
  __m128 *v91; // rcx
  __m128 v92; // xmm3
  __m128 v93; // xmm4
  __int64 v94; // rax
  __m128 v95; // xmm5
  __m128 v96; // xmm7
  __m128 v97; // xmm2
  __m128 *v98; // rax
  int *v99; // rax
  char v100; // cl
  unsigned int v101; // edx
  char v102; // cl
  unsigned int v103; // eax
  bool v104; // zf
  unsigned int v105; // edx
  unsigned int v106; // eax
  int v107; // er8
  char *v108; // rsi
  signed int v109; // ebx
  hkLifoAllocator *v110; // rax
  int v111; // er8
  _QWORD *v112; // rax
  _QWORD *v113; // rcx
  _QWORD *v114; // r8
  unsigned __int64 v115; // rax
  signed __int64 v116; // rcx
  int v117; // [rsp+40h] [rbp-B8h]
  _DWORD *array; // [rsp+48h] [rbp-B0h]
  int v119; // [rsp+50h] [rbp-A8h]
  int v120; // [rsp+54h] [rbp-A4h]
  void *p; // [rsp+58h] [rbp-A0h]
  int v122; // [rsp+60h] [rbp-98h]
  hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int> > v123; // [rsp+68h] [rbp-90h]
  hkaiNavMesh::Edge *v124; // [rsp+80h] [rbp-78h]
  __int64 *v125; // [rsp+88h] [rbp-70h]
  hkaiNavMesh::Face *v126; // [rsp+90h] [rbp-68h]
  int *v127; // [rsp+98h] [rbp-60h]
  unsigned __int64 v128; // [rsp+A0h] [rbp-58h]
  hkResult result; // [rsp+A8h] [rbp-50h]
  __int64 v130; // [rsp+B0h] [rbp-48h]
  hkaiStreamingCollection *v131; // [rsp+B8h] [rbp-40h]
  int *v132; // [rsp+C0h] [rbp-38h]
  char v133; // [rsp+C8h] [rbp-30h]
  int v134; // [rsp+D8h] [rbp-20h]
  __int64 v135; // [rsp+E0h] [rbp-18h]
  int *v136; // [rsp+E8h] [rbp-10h]
  __m128 v137; // [rsp+F8h] [rbp+0h]
  int v138; // [rsp+108h] [rbp+10h]
  __int64 v139; // [rsp+110h] [rbp+18h]
  int *v140; // [rsp+118h] [rbp+20h]
  __m128 v141; // [rsp+128h] [rbp+30h]
  unsigned int v142; // [rsp+138h] [rbp+40h]
  hkaiNavMesh::Face *v143; // [rsp+140h] [rbp+48h]
  int *v144; // [rsp+148h] [rbp+50h]
  hkaiStreamingCollection *retaddr; // [rsp+1F8h] [rbp+100h]
  hkaiStreamingCollection *v146; // [rsp+200h] [rbp+108h]
  hkaiNavMeshUtils::ClosestBoundaryInput *v147; // [rsp+208h] [rbp+110h]
  unsigned int v148; // [rsp+210h] [rbp+118h]
  unsigned int v149; // [rsp+210h] [rbp+118h]

  v147 = input;
  v146 = collection;
  v3 = collection;
  v4 = closestBoundary;
  v5 = input;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtgetDistanceToNearestBoundary";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v4->m_edgeKey = -1;
  if ( v5->m_startFaceKey != -1 )
  {
    v11 = (__int64)v5->m_edgeFilter;
    v120 = 2147483648;
    v122 = 64;
    v125 = (__int64 *)v11;
    array = 0i64;
    v119 = 0;
    v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v13 = (char *)v12->m_cur;
    v14 = (unsigned __int64)(v13 + 512);
    if ( v12->m_slabSize < 512 || (void *)v14 > v12->m_end )
      v13 = (char *)hkLifoAllocator::allocateFromNewSlab(v12, 512);
    else
      v12->m_cur = (void *)v14;
    v15 = v5->m_startFaceKey;
    v16 = v5->m_testRadius.m_real;
    v17 = v5->m_startPosition.m_quad;
    v18 = 0i64;
    v123.m_elem.m_data = 0i64;
    v123.m_elem.m_size = 0;
    v19 = _mm_mul_ps(v16, v16);
    v124 = 0i64;
    v127 = 0i64;
    v20 = v119;
    v123.m_numElems = v15;
    array = v13;
    v120 = -2147483584;
    p = v13;
    v123.m_elem.m_capacityAndFlags = 2147483648;
    v21 = -1;
    *(&v123.m_numElems + 1) = -1;
    do
    {
LABEL_10:
      v22 = v123.m_elem.m_size - 1;
      if ( v123.m_elem.m_size - 1 <= 0 || (v23 = v22 & -1640531535 * (v15 >> 4), v24 = v18[v23], v24 == -1) )
      {
LABEL_14:
        v25 = v123.m_elem.m_size;
      }
      else
      {
        while ( v24 != v15 )
        {
          v23 = v22 & (v23 + 1);
          v24 = v18[v23];
          if ( v24 == -1 )
            goto LABEL_14;
        }
        v25 = v23;
      }
      if ( v25 > v22 )
      {
        v148 = v15 >> 22;
        if ( 2 * v123.m_numElems > v22 )
        {
          hkSet<unsigned int,hkContainerHeapAllocator,hkMapOperations<unsigned int>>::resizeTable(
            &v123,
            &result,
            2 * v22 + 2);
          v18 = v123.m_elem.m_data;
        }
        v26 = 1;
        v27 = (v123.m_elem.m_size - 1) & -1640531535 * (v15 >> 4);
        v28 = v18[v27];
        if ( v28 != -1 )
        {
          while ( v28 != v15 )
          {
            v27 = (v123.m_elem.m_size - 1) & (v27 + 1);
            v28 = v18[v27];
            if ( v28 == -1 )
              goto LABEL_24;
          }
          v26 = 0;
        }
LABEL_24:
        v123.m_numElems += v26;
        v18[v27] = v15;
        v29 = (__int64)v3->m_instances.m_data[v15 >> 22].m_instancePtr;
        v30 = *(_DWORD *)(v29 + 24);
        v31 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
                *(hkaiNavMesh::Face **)(v29 + 16),
                *(_DWORD *)(v29 + 24),
                (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v29 + 240),
                (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(v29 + 272),
                (hkArray<int,hkContainerHeapAllocator> *)(v29 + 224),
                v15 & 0x3FFFFF);
        striding = *(_DWORD *)(v29 + 72);
        v126 = v31;
        if ( striding )
        {
          v34 = hkaiNavMeshInstance_getWithStriding_int__1(
                  *(const int **)(v29 + 64),
                  v30,
                  (hkArray<int,hkContainerHeapAllocator> *)(v29 + 352),
                  (hkArray<int,hkContainerHeapAllocator> *)(v29 + 384),
                  (hkArray<int,hkContainerHeapAllocator> *)(v29 + 224),
                  v15 & 0x3FFFFF,
                  striding);
          v31 = v126;
        }
        else
        {
          v34 = 0i64;
        }
        v135 = 0i64;
        v139 = 0i64;
        v143 = 0i64;
        v134 = -1;
        v138 = -1;
        v142 = -1;
        if ( v11 )
        {
          v142 = v15;
          v143 = v31;
          v137 = v17;
          v134 = *(&v123.m_numElems + 1);
          v144 = v34;
          v136 = v127;
          v135 = v32;
        }
        v20 = v119;
        v18 = v123.m_elem.m_data;
        if ( v31->m_numEdges > 0 )
        {
          v35 = 0;
          v36 = v148 << 22;
          v149 = v148 << 22;
          do
          {
            index = v35 + v31->m_startEdgeIndex;
            v38 = index | v36;
            v117 = index;
            if ( (index | v36) != v21 )
            {
              v39 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
                      *(hkaiNavMesh::Edge **)(v29 + 32),
                      *(_DWORD *)(v29 + 40),
                      (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v29 + 256),
                      (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)(v29 + 288),
                      (hkArray<int,hkContainerHeapAllocator> *)(v29 + 208),
                      index);
              v40 = *(_DWORD *)(v29 + 56);
              v41 = (__int64)v39;
              v42 = v39->m_a;
              if ( (signed int)v42 >= v40 )
                v43 = (__m128 *)(*(_QWORD *)(v29 + 304) + 16i64 * ((signed int)v42 - v40));
              else
                v43 = (__m128 *)(*(_QWORD *)(v29 + 48) + 16 * v42);
              v44 = *(__m128 *)(v29 + 128);
              v45 = *(__m128 *)(v29 + 112);
              v46 = *(signed int *)(v41 + 4);
              v47 = *(__m128 *)(v29 + 144);
              v48 = *(__m128 *)(v29 + 160);
              v49 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(*v43, *v43, 0), v45),
                          _mm_mul_ps(_mm_shuffle_ps(*v43, *v43, 85), v44)),
                        _mm_mul_ps(_mm_shuffle_ps(*v43, *v43, 170), v47)),
                      v48);
              if ( (signed int)v46 >= v40 )
                v50 = (__m128 *)(*(_QWORD *)(v29 + 304) + 16i64 * ((signed int)v46 - v40));
              else
                v50 = (__m128 *)(*(_QWORD *)(v29 + 48) + 16 * v46);
              v51 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(*v50, *v50, 0), v45),
                          _mm_mul_ps(_mm_shuffle_ps(*v50, *v50, 85), v44)),
                        _mm_mul_ps(_mm_shuffle_ps(*v50, *v50, 170), v47)),
                      v48);
              v52 = _mm_sub_ps(v49, *(__m128 *)&v146->m_isTemporary.m_bool);
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
              v60 = _mm_cmpltps(v59, query.m_quad);
              v61 = _mm_sub_ps(
                      v52,
                      _mm_mul_ps(
                        _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v60, v59), _mm_andnot_ps(v60, query.m_quad))),
                        v53));
              v62 = _mm_mul_ps(v61, v61);
              v63 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v62, v62, 85), _mm_shuffle_ps(v62, v62, 0)),
                      _mm_shuffle_ps(v62, v62, 170));
              if ( v63.m128_f32[0] < v19.m128_f32[0] )
              {
                if ( *(_DWORD *)(v41 + 8) == -1 || *(_BYTE *)(v41 + 16) & 0x20 )
                  goto LABEL_109;
                v64 = v125;
                if ( !v125 )
                  goto LABEL_110;
                v65 = *(_DWORD *)(v29 + 88);
                v66 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v51, v49), (__m128)xmmword_141A711B0), v49);
                v67 = v65 ? hkaiNavMeshInstance_getWithStriding_int__1(
                              *(const int **)(v29 + 80),
                              *(_DWORD *)(v29 + 40),
                              (hkArray<int,hkContainerHeapAllocator> *)(v29 + 368),
                              (hkArray<int,hkContainerHeapAllocator> *)(v29 + 400),
                              (hkArray<int,hkContainerHeapAllocator> *)(v29 + 208),
                              v117,
                              v65) : 0i64;
                v140 = v67;
                v141 = v66;
                v138 = v38;
                v131 = v146 + 1;
                v139 = v41;
                v132 = &v134;
                v68 = *v64;
                v130 = v29;
                v133 = 4;
                v69 = (*(__int64 (__fastcall **)(__int64 *, __int64 *))(v68 + 40))(v64, &v130);
                v20 = v119;
                v18 = v123.m_elem.m_data;
                if ( !v69 )
                {
LABEL_109:
                  v19 = v63;
                  v147->m_startFaceKey = v38;
                }
                else
                {
LABEL_110:
                  v70 = *(_DWORD *)(v41 + 12);
                  if ( *(_BYTE *)(v41 + 16) & 0x40 )
                    v71 = v70 & 0xFFC00000;
                  else
                    v71 = *(_DWORD *)(v29 + 472) << 22;
                  v72 = v71 | v70 & 0x3FFFFF;
                  if ( v70 == -1 )
                    v72 = -1;
                  v73 = v123.m_elem.m_size - 1;
                  if ( v123.m_elem.m_size - 1 <= 0 || (v74 = v73 & -1640531535 * (v72 >> 4), v75 = v18[v74], v75 == -1) )
                  {
LABEL_55:
                    v76 = v123.m_elem.m_size;
                  }
                  else
                  {
                    while ( v75 != v72 )
                    {
                      v74 = v73 & (v74 + 1);
                      v75 = v18[v74];
                      if ( v75 == -1 )
                        goto LABEL_55;
                    }
                    v76 = v74;
                  }
                  if ( v76 > v73 )
                  {
                    v128 = __PAIR__(v63.m128_u32[0], v38);
                    if ( v20 == (v120 & 0x3FFFFFFF) )
                    {
                      hkArrayUtil::_reserveMore(
                        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                        &array,
                        8);
                      v20 = v119;
                      v18 = v123.m_elem.m_data;
                    }
                    v77 = (unsigned __int64 *)&array[2 * v20];
                    if ( v77 )
                    {
                      *v77 = v128;
                      v20 = v119;
                      v18 = v123.m_elem.m_data;
                    }
                    v119 = ++v20;
                  }
                }
              }
              v36 = v149;
            }
            ++v35;
            v78 = v126->m_numEdges;
            v80 = __OFSUB__(v35, v78);
            v79 = v35 - v78 < 0;
            v31 = v126;
          }
          while ( v79 ^ v80 );
          v15 = v123.m_numElems;
        }
      }
      v81 = 0;
      if ( !v20 )
        break;
      do
      {
        if ( v81 )
        {
          v11 = (__int64)v125;
          v3 = retaddr;
          goto LABEL_10;
        }
        v82 = (__m128)(unsigned int)array[2 * --v20 + 1];
        v83 = array[2 * v20];
        v119 = v20;
        *(&v123.m_numElems + 1) = v83;
        if ( COERCE_FLOAT(_mm_shuffle_ps(v82, v82, 0)) < v19.m128_f32[0] )
        {
          v81 = 1;
          v84 = v83 & 0x3FFFFF;
          v85 = retaddr->m_instances.m_data[v83 >> 22].m_instancePtr;
          v86 = v85->m_numOriginalEdges;
          v87 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
                  v85->m_originalEdges,
                  v85->m_numOriginalEdges,
                  &v85->m_instancedEdges,
                  &v85->m_ownedEdges,
                  &v85->m_edgeMap,
                  v83 & 0x3FFFFF);
          v88 = v87;
          v124 = v87;
          if ( v125 )
          {
            v89 = v87->m_a;
            v90 = v85->m_numOriginalVertices;
            if ( (signed int)v89 >= v90 )
              v91 = &v85->m_ownedVertices.m_data[(signed int)v89 - v90].m_quad;
            else
              v91 = &v85->m_originalVertices[v89].m_quad;
            v92 = v85->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
            v93 = v85->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
            v94 = v87->m_b;
            v95 = v85->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
            v96 = v85->m_referenceFrame.m_transform.m_translation.m_quad;
            v97 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(*v91, *v91, 0), v93),
                        _mm_mul_ps(_mm_shuffle_ps(*v91, *v91, 85), v92)),
                      _mm_mul_ps(_mm_shuffle_ps(*v91, *v91, 170), v95)),
                    v96);
            if ( (signed int)v94 >= v90 )
              v98 = &v85->m_ownedVertices.m_data[(signed int)v94 - v90].m_quad;
            else
              v98 = &v85->m_originalVertices[v94].m_quad;
            v17 = _mm_add_ps(
                    _mm_mul_ps(
                      _mm_sub_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_mul_ps(_mm_shuffle_ps(*v98, *v98, 0), v93),
                              _mm_mul_ps(_mm_shuffle_ps(*v98, *v98, 85), v92)),
                            _mm_mul_ps(_mm_shuffle_ps(*v98, *v98, 170), v95)),
                          v96),
                        v97),
                      (__m128)xmmword_141A711B0),
                    v97);
          }
          if ( v85->m_edgeDataStriding )
            v99 = hkaiNavMeshInstance_getWithStriding_int__1(
                    v85->m_originalEdgeData,
                    v86,
                    &v85->m_instancedEdgeData,
                    &v85->m_ownedEdgeData,
                    &v85->m_edgeMap,
                    v84,
                    v85->m_edgeDataStriding);
          else
            v99 = 0i64;
          v100 = v88->m_flags.m_storage;
          v101 = v88->m_oppositeFace;
          v127 = v99;
          v102 = v100 & 0x40;
          if ( v102 )
            v103 = v101 & 0xFFC00000;
          else
            v103 = v85->m_runtimeId << 22;
          v15 = v103 | v101 & 0x3FFFFF;
          v104 = v101 == -1;
          v105 = v88->m_oppositeEdge;
          if ( v104 )
            v15 = -1;
          v123.m_numElems = v15;
          if ( v102 )
            v106 = v105 & 0xFFC00000;
          else
            v106 = v85->m_runtimeId << 22;
          v21 = v106 | v105 & 0x3FFFFF;
          if ( v105 == -1 )
            v21 = -1;
        }
      }
      while ( v20 );
      v11 = (__int64)v125;
      v104 = v81 == 0;
      v3 = retaddr;
    }
    while ( !v104 );
    v107 = v123.m_elem.m_capacityAndFlags;
    v123.m_elem.m_size = 0;
    v147->m_startPosition.m_quad = v19;
    if ( v107 >= 0 )
    {
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v18,
        4 * v107);
      v20 = v119;
    }
    v108 = (char *)p;
    v123.m_elem.m_data = 0i64;
    if ( p == array )
      v20 = 0;
    v123.m_elem.m_capacityAndFlags = 2147483648;
    v109 = (8 * v122 + 127) & 0xFFFFFF80;
    v119 = v20;
    v110 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v111 = (v109 + 15) & 0xFFFFFFF0;
    if ( v109 > v110->m_slabSize || &v108[v111] != v110->m_cur || v110->m_firstNonLifoEnd == v108 )
      hkLifoAllocator::slowBlockFree(v110, v108, v111);
    else
      v110->m_cur = v108;
    v119 = 0;
    if ( v120 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        8 * v120);
    array = 0i64;
    v120 = 2147483648;
  }
  v112 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v113 = (_QWORD *)v112[1];
  v114 = v112;
  if ( (unsigned __int64)v113 < v112[3] )
  {
    *v113 = "Et";
    v115 = __rdtsc();
    v116 = (signed __int64)(v113 + 2);
    *(_DWORD *)(v116 - 8) = v115;
    v114[1] = v116;
  }
}

// File Line: 2736
// RVA: 0xBC65C0
__int64 __fastcall hkaiNavMeshUtils::triangleAabbCheck(hkAabb *aabb, hkVector4f *triA, hkVector4f *triB, hkVector4f *triC)
{
  __m128 v4; // xmm3
  __m128 v5; // xmm4
  __m128 v6; // xmm5
  hkVector4f v7; // xmm6
  hkVector4f v8; // xmm9
  hkVector4f *v10; // rdx
  unsigned int v11; // er8
  __m128i v12; // xmm14
  __m128i v13; // xmm15
  __m128 v14; // xmm1
  __m128 v15; // xmm10
  __m128 v16; // xmm9
  __m128 v17; // xmm11
  __m128 v18; // xmm12
  __m128 v19; // xmm7
  signed __int64 v20; // rax
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
  __m128 v40; // xmm5
  __m128 v41; // xmm2
  __int128 v42; // [rsp+0h] [rbp-D8h]
  __int128 v43; // [rsp+10h] [rbp-C8h]
  __int128 v44; // [rsp+20h] [rbp-B8h]

  v4 = triA->m_quad;
  v5 = triB->m_quad;
  v6 = triC->m_quad;
  v7.m_quad = (__m128)aabb->m_min;
  v8.m_quad = (__m128)aabb->m_max;
  if ( (_mm_movemask_ps(
          _mm_and_ps(
            _mm_cmpleps(aabb->m_min.m_quad, _mm_max_ps(_mm_max_ps(triA->m_quad, triB->m_quad), triC->m_quad)),
            _mm_cmpleps(_mm_min_ps(_mm_min_ps(triA->m_quad, triB->m_quad), triC->m_quad), v8.m_quad))) & 7) != 7 )
    return 0i64;
  v10 = &transform;
  v11 = 0;
  v12 = (__m128i)_mm_sub_ps(v5, v4);
  v13 = (__m128i)_mm_sub_ps(v6, v5);
  _mm_store_si128((__m128i *)&v42, v12);
  v14 = _mm_mul_ps(_mm_add_ps(v7.m_quad, v8.m_quad), (__m128)xmmword_141A711B0);
  _mm_store_si128((__m128i *)&v43, v13);
  v15 = _mm_sub_ps(v4, v14);
  v16 = _mm_mul_ps(_mm_sub_ps(v8.m_quad, v7.m_quad), (__m128)xmmword_141A711B0);
  _mm_store_si128((__m128i *)&v44, (__m128i)_mm_sub_ps(v4, v6));
  v17 = _mm_sub_ps(v5, v14);
  v18 = _mm_sub_ps(v6, v14);
  while ( 2 )
  {
    v19 = v10->m_quad;
    v20 = 0i64;
    v21 = (__m128 *)&v42;
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
      v28.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v32, v32, 85);
      v31.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v32, v32, 0);
      v29.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v32, v32, 170);
      if ( fmax(
             0.0 - fmax(v29.m128_f32[0], fmax(v28.m128_f32[0], v31.m128_f32[0])),
             fmin(v29.m128_f32[0], fmin(v28.m128_f32[0], v31.m128_f32[0]))) > (float)((float)(COERCE_FLOAT(
                                                                                                _mm_shuffle_ps(
                                                                                                  v30,
                                                                                                  v30,
                                                                                                  85))
                                                                                            + COERCE_FLOAT(
                                                                                                _mm_shuffle_ps(
                                                                                                  v30,
                                                                                                  v30,
                                                                                                  0)))
                                                                                    + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 170))) )
        return 0i64;
      ++v20;
      ++v21;
    }
    while ( v20 < 3 );
    ++v10;
    if ( (signed __int64)v10 < (signed __int64)&qi )
      continue;
    break;
  }
  v33 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)v13, (__m128)v13, 201), (__m128)v12),
          _mm_mul_ps(_mm_shuffle_ps((__m128)v12, (__m128)v12, 201), (__m128)v13));
  v34 = _mm_shuffle_ps(v33, v33, 201);
  v35 = _mm_mul_ps(v34, v34);
  v36 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)), _mm_shuffle_ps(v35, v35, 170));
  v37 = _mm_rsqrt_ps(v36);
  v38 = _mm_mul_ps(
          v34,
          _mm_andnot_ps(
            _mm_cmpleps(v36, (__m128)0i64),
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
  v41 = _mm_mul_ps(v40, v16);
  if ( COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 255)) <= (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 85))
                                                                    + COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 0)))
                                                            + COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 170))) )
    v11 = 1;
  return v11;
}

// File Line: 2816
// RVA: 0xBC68E0
signed __int64 __fastcall hkaiNavMeshUtils::faceAabbCheck(hkAabb *aabb, hkArrayBase<hkVector4f> *vertices)
{
  int v2; // edi
  signed int v3; // ebx
  hkAabb *v4; // rbp
  hkVector4f *v5; // rsi

  v2 = vertices->m_size;
  v3 = 2;
  v4 = aabb;
  if ( v2 <= 2 )
    return 0i64;
  v5 = vertices->m_data;
  while ( !(unsigned int)hkaiNavMeshUtils::triangleAabbCheck(v4, v5, &v5[v3 - 1], &v5[v3]) )
  {
    if ( ++v3 >= v2 )
      return 0i64;
  }
  return 1i64;
}

// File Line: 2829
// RVA: 0xBC6960
signed __int64 __fastcall hkaiNavMeshUtils::faceAabbCheck(hkAabb *aabb, hkaiNavMesh *mesh, int faceIndex)
{
  hkAabb *v3; // r10
  hkaiNavMesh::Face *v4; // rdi
  __int16 v5; // r15
  int v6; // ebx
  hkaiNavMesh::Edge *v7; // r13
  hkVector4f *v8; // r12
  signed int v9; // er14
  signed int v10; // ebp
  int v11; // esi
  signed __int64 v12; // rax
  hkVector4f triC; // [rsp+20h] [rbp-58h]
  hkVector4f triB; // [rsp+30h] [rbp-48h]
  hkVector4f triA; // [rsp+40h] [rbp-38h]
  hkAabb *v17; // [rsp+80h] [rbp+8h]

  v17 = aabb;
  v3 = aabb;
  v4 = &mesh->m_faces.m_data[faceIndex];
  v5 = v4->m_numUserEdges;
  if ( v5 <= 0 )
    v6 = v4->m_startEdgeIndex;
  else
    v6 = v4->m_startUserEdgeIndex;
  v7 = mesh->m_edges.m_data;
  v8 = mesh->m_vertices.m_data;
  v9 = v4->m_numEdges;
  v10 = 2;
  triA.m_quad = (__m128)v8[v7[v6].m_a];
  if ( v9 <= 2 )
    return 0i64;
  v11 = v4->m_startUserEdgeIndex;
  while ( 1 )
  {
    if ( v6 < v11 || v6 >= v5 + v11 - 1 )
    {
      if ( v6 == v5 + v11 - 1 )
      {
        v6 = v4->m_startEdgeIndex;
      }
      else if ( v6 < v4->m_startEdgeIndex || v6 >= v9 + v4->m_startEdgeIndex - 1 )
      {
        v6 = -1;
      }
      else
      {
        ++v6;
      }
    }
    else
    {
      ++v6;
    }
    v12 = v7[v6].m_b;
    triB.m_quad = (__m128)v8[v7[v6].m_a];
    triC.m_quad = (__m128)v8[v12];
    if ( (unsigned int)hkaiNavMeshUtils::triangleAabbCheck(v3, &triA, &triB, &triC) )
      break;
    v3 = v17;
    if ( ++v10 >= v9 )
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
  hkTransformf *v5; // r10
  hkVector4f v6; // xmm5
  hkVector4f v7; // xmm6
  __int64 v8; // rcx
  hkVector4f *v9; // rax
  __m128 v10; // xmm1
  hkVector4f v11; // xmm1
  hkSimdFloat32 extraRadius; // [rsp+20h] [rbp-48h]
  hkAabb aabb; // [rsp+30h] [rbp-38h]

  v3.m_quad = (__m128)t->m_rotation.m_col0;
  v4.m_quad = (__m128)t->m_rotation.m_col1;
  v5 = t;
  v6.m_quad = (__m128)t->m_rotation.m_col2;
  v7.m_quad = (__m128)t->m_translation;
  v8 = mesh->m_vertices.m_size - 1;
  v9 = &mesh->m_vertices.m_data[v8];
  do
  {
    v10 = v9->m_quad;
    --v9;
    --v8;
    v9[1].m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), v4.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v3.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v10, v10, 170), v6.m_quad)),
                     v7.m_quad);
  }
  while ( v8 >= 0 );
  if ( mode )
  {
    v11.m_quad = (__m128)mesh->m_aabb.m_max;
    aabb.m_min = mesh->m_aabb.m_min;
    aabb.m_max = (hkVector4f)v11.m_quad;
    extraRadius.m_real = aabbOut.m_quad;
    hkAabbUtil::calcAabb(v5, &aabb, &extraRadius, &mesh->m_aabb);
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
  __int64 v1; // r15
  hkaiNavMeshInstance *v2; // r14
  int v3; // edx
  int v4; // er9
  _DWORD *v5; // rdi
  __int64 v6; // rcx
  __int64 v7; // r8
  int v8; // edi
  __int64 i; // rdx
  __int64 v10; // rcx
  int v11; // er13
  int v12; // ebp
  int v13; // esi
  __int64 v14; // rbx
  _DWORD *v15; // [rsp+30h] [rbp-38h]
  int v16; // [rsp+38h] [rbp-30h]
  int v17; // [rsp+3Ch] [rbp-2Ch]
  __int64 v18; // [rsp+70h] [rbp+8h]

  v1 = instance->m_instancedEdges.m_size;
  v2 = instance;
  v3 = 0;
  v15 = 0i64;
  v17 = 2147483648;
  v16 = 0;
  if ( (signed int)v1 > 0 )
  {
    v4 = v1;
    if ( (signed int)v1 < 0 )
      v4 = 0;
    hkArrayUtil::_reserve((hkResult *)&v18, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v15, v4, 4);
    v3 = v16;
  }
  v5 = &v15[v3];
  v6 = (signed int)v1 - v3;
  if ( (signed int)v1 - v3 > 0 )
  {
    while ( v6 )
    {
      *v5 = -1;
      ++v5;
      --v6;
    }
  }
  v7 = v2->m_edgeMap.m_size;
  v16 = v1;
  v8 = 0;
  for ( i = 0i64; i < v7; ++v8 )
  {
    v10 = v2->m_edgeMap.m_data[i];
    if ( (_DWORD)v10 != -1 )
      v15[v10] = v8;
    ++i;
  }
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0i64;
  if ( (signed int)v1 > 0 )
  {
    do
    {
      if ( v15[v14] == -1 )
      {
        ++v12;
      }
      else
      {
        hkaiNavMeshInstance::copyInstancedEdge(v2, v11++, v13);
        v2->m_edgeMap.m_data[v15[v14]] = v13 - v12;
      }
      ++v14;
      ++v13;
    }
    while ( v14 < v1 );
  }
  hkaiNavMeshInstance::setNumInstancedEdges(v2, v1 - v12);
  v16 = 0;
  if ( v17 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v15,
      4 * v17);
}

// File Line: 2977
// RVA: 0xBC34C0
__int64 __fastcall hkaiNavMeshUtils::computeRegions(hkaiNavMesh *mesh, bool sortRegionsByArea, hkArrayBase<int> *regions, hkArray<float,hkContainerHeapAllocator> *areasOut)
{
  unsigned int v4; // ebx
  int numRegionsOut; // [rsp+30h] [rbp-18h]
  hkResult result; // [rsp+34h] [rbp-14h]

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
    v4 = numRegionsOut;
  return v4;
}

// File Line: 2984
// RVA: 0xBC3510
__int64 __fastcall hkaiNavMeshUtils::computeRegions(hkaiNavMeshInstance *meshInstance, bool sortRegionsByArea, hkArrayBase<int> *regions, hkArray<float,hkContainerHeapAllocator> *areasOut)
{
  unsigned int v4; // ebx
  int numRegionsOut; // [rsp+30h] [rbp-18h]
  hkResult result; // [rsp+34h] [rbp-14h]

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
    v4 = numRegionsOut;
  return v4;
}

// File Line: 2994
// RVA: 0xBBFA30
void __fastcall hkaiNavMeshUtils::calcFacePlane(hkArrayBase<hkVector4f> *facePoints, hkVector4f *planeOut)
{
  hkVector4f *v2; // rax
  int v3; // er8
  __int64 v4; // rcx
  __m128 v5; // xmm3
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

  v2 = facePoints->m_data;
  v3 = facePoints->m_size - 1;
  v4 = v3;
  v5 = v2->m_quad;
  v6 = 0i64;
  v7 = 0i64;
  if ( v3 > 0 )
  {
    do
    {
      v8 = v2->m_quad;
      v9 = v2[1].m_quad;
      ++v2;
      v10 = _mm_sub_ps(v9, v5);
      v6 = _mm_add_ps(v6, v8);
      v11 = _mm_sub_ps(v8, v5);
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
            _mm_cmpleps(v18, (__m128)0i64),
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
void __fastcall hkaiNavMeshUtils::calcFacePlane<hkaiNavMeshInstance>(hkaiNavMeshUtils *this, hkaiNavMeshInstance *mesh, __int64 faceIndex, hkVector4f *planeOut)
{
  hkaiNavMeshUtils *v4; // rbx
  hkaiNavMesh::Face *v5; // rax
  int v6; // er15
  hkaiNavMesh::Edge *v7; // r12
  __m128 v8; // xmm7
  __m128 v9; // xmm8
  int v10; // ebp
  signed int v11; // er13
  hkaiNavMesh::Edge *v12; // rax
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v13; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v14; // r9
  signed int v15; // edi
  __int64 v16; // rcx
  __m128 *v17; // rax
  __m128 v18; // xmm9
  __m128 v19; // xmm10
  signed int v20; // esi
  __m128 v21; // xmm11
  __m128 v22; // xmm12
  __m128 i; // xmm6
  hkaiNavMesh::Edge *v24; // rax
  __int64 v25; // rcx
  __m128 *v26; // rcx
  __int64 v27; // rax
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
  __m128 *v42; // [rsp+F0h] [rbp+18h]

  v42 = (__m128 *)faceIndex;
  v4 = this;
  v5 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__3(
         *(hkaiNavMesh::Face **)&this[16],
         *(_DWORD *)&this[24],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[240],
         (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&this[272],
         (hkArray<int,hkContainerHeapAllocator> *)&this[224],
         (int)mesh);
  v6 = *(_DWORD *)&v4[40];
  v7 = *(hkaiNavMesh::Edge **)&v4[32];
  v8 = 0i64;
  v9 = 0i64;
  v10 = v5->m_startEdgeIndex;
  v11 = v5->m_numEdges;
  v12 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
          *(hkaiNavMesh::Edge **)&v4[32],
          *(_DWORD *)&v4[40],
          (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&v4[256],
          (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&v4[288],
          (hkArray<int,hkContainerHeapAllocator> *)&v4[208],
          v5->m_startEdgeIndex);
  v15 = *(_DWORD *)&v4[56];
  v16 = v12->m_a;
  if ( (signed int)v16 >= v15 )
    v17 = (__m128 *)(*(_QWORD *)&v4[304] + 16i64 * ((signed int)v16 - v15));
  else
    v17 = (__m128 *)(*(_QWORD *)&v4[48] + 16 * v16);
  v18 = *(__m128 *)&v4[128];
  v19 = *(__m128 *)&v4[112];
  v20 = 0;
  v21 = *(__m128 *)&v4[144];
  v22 = *(__m128 *)&v4[160];
  for ( i = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 0), v19),
                  _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 85), v18)),
                _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 170), v21)),
              v22); v20 < v11; v9 = _mm_add_ps(v9, _mm_shuffle_ps(v32, v32, 201)) )
  {
    v24 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__3(
            v7,
            v6,
            v13,
            v14,
            (hkArray<int,hkContainerHeapAllocator> *)&v4[208],
            v20 + v10);
    v25 = v24->m_a;
    if ( (signed int)v25 >= v15 )
      v26 = (__m128 *)(*(_QWORD *)&v4[304] + 16i64 * ((signed int)v25 - v15));
    else
      v26 = (__m128 *)(*(_QWORD *)&v4[48] + 16 * v25);
    v27 = v24->m_b;
    v28 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*v26, *v26, 0), v19),
                _mm_mul_ps(_mm_shuffle_ps(*v26, *v26, 85), v18)),
              _mm_mul_ps(_mm_shuffle_ps(*v26, *v26, 170), v21)),
            v22);
    if ( (signed int)v27 >= v15 )
      v29 = (__m128 *)(*(_QWORD *)&v4[304] + 16i64 * ((signed int)v27 - v15));
    else
      v29 = (__m128 *)(*(_QWORD *)&v4[48] + 16 * v27);
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
  v33.m128_f32[0] = (float)v11;
  v34 = _mm_shuffle_ps(v33, v33, 0);
  v35 = _mm_rcp_ps(v34);
  v36 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v34, v35)), v35);
  v37 = _mm_mul_ps(v9, v9);
  v38 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)), _mm_shuffle_ps(v37, v37, 170));
  v39 = _mm_rsqrt_ps(v38);
  v40 = _mm_mul_ps(
          v9,
          _mm_andnot_ps(
            _mm_cmpleps(v38, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
              _mm_mul_ps(*(__m128 *)_xmm, v39))));
  v41 = _mm_mul_ps(_mm_mul_ps(v8, v36), v40);
  *v42 = _mm_shuffle_ps(
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
void __fastcall `anonymous namespace'::rotateArray<hkaiNavMesh::Edge>(hkaiNavMesh::Edge *data, int n, int offset)
{
  hkaiNavMesh::Edge *v3; // r14
  __int64 v4; // rbp
  __int64 v5; // rdi
  hkLifoAllocator *v6; // rax
  _BYTE *v7; // rbx
  int v8; // esi
  char *v9; // rcx
  signed __int64 v10; // rcx
  __int64 v11; // r8
  signed __int64 v12; // rdx
  int v13; // eax
  __int64 v14; // rcx
  signed __int64 v15; // rdx
  signed __int64 v16; // r8
  int v17; // eax
  int v18; // edi
  __int64 v19; // r8
  signed __int64 v20; // rax
  signed __int64 v21; // rdx
  int v22; // ecx
  hkLifoAllocator *v23; // rax
  int v24; // er8

  if ( offset )
  {
    v3 = data;
    v4 = offset;
    v5 = n;
    v6 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v7 = v6->m_cur;
    v8 = (20 * v5 + 127) & 0xFFFFFF80;
    v9 = &v7[v8];
    if ( v8 > v6->m_slabSize || v9 > v6->m_end )
      v7 = hkLifoAllocator::allocateFromNewSlab(v6, v8);
    else
      v6->m_cur = v9;
    if ( (signed int)v5 > 0 )
    {
      v10 = (signed __int64)(v7 + 4);
      v11 = v5;
      v12 = (char *)v3 - v7;
      do
      {
        v13 = *(_DWORD *)(v10 + v12 - 4);
        v10 += 20i64;
        *(_DWORD *)(v10 - 24) = v13;
        *(_DWORD *)(v10 - 20) = *(_DWORD *)(v12 + v10 - 20);
        *(_DWORD *)(v10 - 16) = *(_DWORD *)(v12 + v10 - 16);
        *(_DWORD *)(v10 - 12) = *(_DWORD *)(v12 + v10 - 12);
        *(_BYTE *)(v10 - 8) = *(_BYTE *)(v10 + v12 - 8);
        *(_BYTE *)(v10 - 7) = *(_BYTE *)(v10 + v12 - 7);
        *(_WORD *)(v10 - 6) = *(_WORD *)(v10 + v12 - 6);
        --v11;
      }
      while ( v11 );
    }
    if ( (signed int)v4 > 0 )
    {
      v14 = v4;
      v15 = (signed __int64)&v7[4 * (5 * (v5 - v4) + 2)];
      v16 = (signed __int64)v3 + 20 * (v4 - v5) - (_QWORD)v7;
      do
      {
        v17 = *(_DWORD *)(v15 - 8);
        v15 += 20i64;
        *(_DWORD *)(v15 + v16 - 28) = v17;
        *(_DWORD *)(v16 + v15 - 24) = *(_DWORD *)(v15 - 24);
        *(_DWORD *)(v16 + v15 - 20) = *(_DWORD *)(v15 - 20);
        *(_DWORD *)(v16 + v15 - 16) = *(_DWORD *)(v15 - 16);
        *(_BYTE *)(v16 + v15 - 12) = *(_BYTE *)(v15 - 12);
        *(_BYTE *)(v16 + v15 - 11) = *(_BYTE *)(v15 - 11);
        *(_WORD *)(v15 + v16 - 10) = *(_WORD *)(v15 - 10);
        --v14;
      }
      while ( v14 );
    }
    v18 = v5 - v4;
    v19 = v18;
    if ( v18 > 0 )
    {
      v20 = (signed __int64)&v3[v4].m_oppositeEdge;
      v21 = &v7[-20 * v4] - (_BYTE *)v3;
      do
      {
        v22 = *(_DWORD *)(v21 + v20 - 8);
        v20 += 20i64;
        *(_DWORD *)(v20 - 28) = v22;
        *(_DWORD *)(v20 - 24) = *(_DWORD *)(v21 + v20 - 24);
        *(_DWORD *)(v20 - 20) = *(_DWORD *)(v21 + v20 - 20);
        *(_DWORD *)(v20 - 16) = *(_DWORD *)(v21 + v20 - 16);
        *(_BYTE *)(v20 - 12) = *(_BYTE *)(v21 + v20 - 12);
        *(_BYTE *)(v20 - 11) = *(_BYTE *)(v21 + v20 - 11);
        *(_WORD *)(v20 - 10) = *(_WORD *)(v21 + v20 - 10);
        --v19;
      }
      while ( v19 );
    }
    v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v24 = (v8 + 15) & 0xFFFFFFF0;
    if ( v8 > v23->m_slabSize || &v7[v24] != v23->m_cur || v23->m_firstNonLifoEnd == v7 )
      hkLifoAllocator::slowBlockFree(v23, v7, v24);
    else
      v23->m_cur = v7;
  }
}

// File Line: 3095
// RVA: 0xBC7770
void __fastcall `anonymous namespace'::calcMinimalWidth(hkArrayBase<hkVector4f> *vertices, hkVector4f *up, int *baseOut, int *antipodeOut, hkSimdFloat32 *widthOut)
{
  __int64 v5; // r10
  hkVector4f *v6; // r11
  signed int v7; // ebx
  hkSimdFloat32 v8; // xmm7
  signed int v9; // ecx
  int *v10; // r14
  hkVector4f *v11; // rbp
  int *v12; // r15
  signed int v13; // edi
  int v14; // edx
  __m128 v15; // xmm10
  signed int v16; // er9
  __m128 v17; // xmm8
  __m128 *v18; // r8
  __m128 v19; // xmm9
  __m128 v20; // xmm5
  signed __int64 v21; // rax
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

  v5 = vertices->m_size;
  v6 = vertices->m_data;
  v7 = -1;
  v8.m_real = (__m128)xmmword_141A712B0;
  v9 = 0;
  v10 = antipodeOut;
  v11 = up;
  v12 = baseOut;
  v13 = -1;
  v14 = 1;
  v15 = v6[v5 - 1].m_quad;
  v16 = v5 - 1;
  if ( (signed int)v5 > 0 )
  {
    v17 = v11->m_quad;
    v18 = &v6->m_quad;
    v19 = _mm_shuffle_ps(v17, v17, 201);
    do
    {
      v20 = v15;
      v15 = *v18;
      v21 = v14;
      v22 = v14 + 1;
      v23 = _mm_sub_ps(*v18, v20);
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
                _mm_cmpleps(v27, (__m128)0i64),
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
      v32 = _mm_mul_ps(v6[v21].m_quad, v31);
      v33 = _mm_shuffle_ps(v32, _mm_unpackhi_ps(v32, v31), 196);
      v34 = _mm_add_ps(_mm_shuffle_ps(v33, v33, 78), v33);
      v35 = _mm_mul_ps(v6[v22].m_quad, v31);
      v36 = _mm_add_ps(_mm_shuffle_ps(v34, v34, 177), v34);
      v37 = _mm_shuffle_ps(v35, _mm_unpackhi_ps(v35, v31), 196);
      v38 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 78), v37);
      for ( i = _mm_add_ps(_mm_shuffle_ps(v38, v38, 177), v38);
            i.m128_f32[0] >= v36.m128_f32[0];
            i = _mm_add_ps(_mm_shuffle_ps(v42, v42, 177), v42) )
      {
        v36 = i;
        v22 = (v22 + 1) % (signed int)v5;
        v40 = _mm_mul_ps(v6[v22].m_quad, v31);
        v41 = _mm_shuffle_ps(v40, _mm_unpackhi_ps(v40, v31), 196);
        v42 = _mm_add_ps(_mm_shuffle_ps(v41, v41, 78), v41);
      }
      v14 = ((signed int)v5 - 1 + v22) % (signed int)v5;
      if ( v36.m128_f32[0] < v8.m_real.m128_f32[0] )
      {
        v7 = v16;
        v13 = v14;
        v8.m_real = v36;
      }
      v16 = v9++;
      ++v18;
    }
    while ( v9 < (signed int)v5 );
  }
  *v12 = v7;
  *v10 = v13;
  *widthOut = (hkSimdFloat32)v8.m_real;
}

// File Line: 3162
// RVA: 0xBC6AB0
void __fastcall hkaiNavMeshUtils::rotateFace(hkaiNavMesh *navMesh, int faceIndex, int newFirstEdgeIndex)
{
  hkaiNavMesh *v3; // rdi
  hkaiNavMesh::Face *v4; // rbx
  __int64 v5; // rax
  int v6; // edx
  int v7; // esi
  int v8; // ecx
  signed __int64 v9; // r9
  int v10; // eax
  signed __int64 v11; // r8
  signed __int64 v12; // r10
  hkaiNavMesh::Edge *v13; // r11
  unsigned int v14; // eax

  v3 = navMesh;
  v4 = &navMesh->m_faces.m_data[faceIndex];
  v5 = v4->m_startEdgeIndex;
  if ( newFirstEdgeIndex != (_DWORD)v5 )
  {
    v6 = v4->m_numEdges;
    v7 = v5 + v6 - newFirstEdgeIndex;
    `anonymous namespace'::rotateArray<hkaiNavMesh::Edge>(&navMesh->m_edges.m_data[v5], v6, v5 + v6 - newFirstEdgeIndex);
    v8 = v3->m_edgeDataStriding;
    if ( v8 > 0 )
      `anonymous namespace'::rotateArray<int>(
        &v3->m_edgeData.m_data[v8 * v4->m_startEdgeIndex],
        v8 * v4->m_numEdges,
        v7 * v8);
    v9 = v4->m_startEdgeIndex;
    v10 = v9 + v4->m_numEdges;
    if ( v9 != v10 )
    {
      v11 = v9;
      v12 = v10 - v9;
      do
      {
        v13 = v3->m_edges.m_data;
        v14 = v13[v11].m_oppositeEdge;
        if ( v14 != -1 )
          v13[v14 & 0x3FFFFF].m_oppositeEdge = v9 | v14 & 0xFFC00000;
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
void __fastcall hkaiNavMeshUtils::rotateOwnedFace(hkaiStreamingCollection *streamingCollection, unsigned int faceKey, unsigned int newFirstEdgeKey)
{
  __int64 v3; // r12
  unsigned int v4; // er8
  hkaiStreamingCollection *v5; // r13
  hkaiNavMeshInstance *v6; // rdi
  hkaiNavMesh::Face *v7; // rsi
  int v8; // eax
  int v9; // edx
  int v10; // ebx
  int v11; // er9
  __int64 v12; // rax
  signed int v13; // ecx
  __int64 v14; // rcx
  int *v15; // rax
  int *v16; // rcx
  int v17; // ebx
  int v18; // esi
  hkaiNavMesh::Edge *v19; // rax
  unsigned int v20; // edx
  hkaiNavMeshInstance *v21; // r9
  int v22; // eax
  int index; // edx
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // r10
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v25; // r11
  signed __int64 v26; // rcx
  hkaiNavMesh::Edge *v27; // rax
  int v28; // er8
  hkaiNavMesh::Edge *v29; // rdx

  v3 = faceKey >> 22;
  v4 = newFirstEdgeKey & 0x3FFFFF;
  v5 = streamingCollection;
  v6 = streamingCollection->m_instances.m_data[v3].m_instancePtr;
  v7 = &v6->m_ownedFaces.m_data[(faceKey & 0x3FFFFF) - v6->m_numOriginalFaces];
  v8 = v7->m_startEdgeIndex;
  if ( v4 == v7->m_startEdgeIndex )
    return;
  v9 = v7->m_numEdges;
  v10 = v8 + v9 - v4;
  `anonymous namespace'::rotateArray<hkaiNavMesh::Edge>(&v6->m_ownedEdges.m_data[v8 - v6->m_numOriginalEdges], v9, v10);
  v11 = v6->m_edgeDataStriding;
  if ( v11 > 0 )
  {
    v12 = v7->m_startEdgeIndex;
    v13 = v6->m_numOriginalEdges;
    if ( (signed int)v12 < v13 )
    {
      if ( v6->m_edgeMap.m_size )
        LODWORD(v12) = v6->m_edgeMap.m_data[v12];
      if ( (_DWORD)v12 == -1 )
      {
        v16 = 0i64;
LABEL_11:
        `anonymous namespace'::rotateArray<int>(v16, v11 * v7->m_numEdges, v10 * v11);
        goto LABEL_12;
      }
      v14 = (signed int)v12;
      v15 = v6->m_instancedEdgeData.m_data;
    }
    else
    {
      v14 = (signed int)v12 - v13;
      v15 = v6->m_ownedEdgeData.m_data;
    }
    v16 = &v15[v14];
    goto LABEL_11;
  }
LABEL_12:
  v17 = v7->m_startEdgeIndex;
  v18 = v7->m_startEdgeIndex + v7->m_numEdges;
  if ( v17 != v18 )
  {
    while ( 1 )
    {
      v19 = v6->m_ownedEdges.m_data;
      v20 = v19[v17 - v6->m_numOriginalEdges].m_oppositeEdge;
      if ( v20 != -1 )
        break;
LABEL_27:
      if ( ++v17 == v18 )
        return;
    }
    if ( v19[v17 - v6->m_numOriginalEdges].m_flags.m_storage & 0x40 )
      v21 = v5->m_instances.m_data[v20 >> 22].m_instancePtr;
    else
      v21 = v6;
    v22 = v21->m_numOriginalEdges;
    index = v20 & 0x3FFFFF;
    instanceMap = &v21->m_edgeMap;
    v25 = &v21->m_instancedEdges;
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
                v25,
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
      v27 = v25->m_data;
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
  __m128 v3; // xmm6
  hkaiNavMesh *v4; // r13
  hkaiNavMesh::Face *v5; // rax
  __int64 v6; // rdi
  __int64 v7; // rax
  _DWORD *v8; // r14
  int v9; // er15
  hkLifoAllocator *v10; // rax
  __m128 *v11; // rsi
  int v12; // edx
  char *v13; // rcx
  int v14; // ebx
  hkResultEnum v15; // er12
  hkLifoAllocator *v16; // rax
  int v17; // edx
  char *v18; // rcx
  __int64 v19; // r9
  signed int v20; // er10
  __int64 v21; // r11
  signed __int64 v22; // rdx
  hkaiNavMesh::Edge *v23; // r8
  signed int v24; // ecx
  __int64 v25; // rax
  signed __int64 v26; // rcx
  __m128 v27; // xmm3
  __int64 v28; // rax
  __m128 v29; // xmm1
  signed __int64 v30; // rcx
  __m128 v31; // xmm4
  signed __int64 v32; // rax
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  __m128 v35; // xmm2
  hkLifoAllocator *v36; // rax
  char *v37; // r9
  int v38; // edx
  char *v39; // rcx
  char *v40; // r15
  int v41; // er9
  float v42; // xmm10_4
  int v43; // eax
  signed int v44; // er11
  signed int v45; // er8
  int v46; // er10
  __m128 *v47; // r15
  __m128 v48; // xmm11
  __m128 v49; // xmm0
  int v50; // edx
  __m128 v51; // xmm12
  __m128 v52; // xmm6
  int v53; // ecx
  __m128 v54; // xmm9
  __m128 v55; // xmm7
  int v56; // edx
  __m128 v57; // xmm2
  float v58; // xmm5_4
  __m128 v59; // xmm4
  __m128 v60; // xmm1
  __m128 v61; // xmm3
  __m128 v62; // xmm1
  __m128 v63; // xmm2
  __m128 v64; // xmm0
  __m128 v65; // xmm4
  __m128 v66; // xmm4
  float v67; // xmm1_4
  unsigned int v68; // er13
  signed int v69; // ebx
  hkLifoAllocator *v70; // rax
  int v71; // er8
  int v72; // ebx
  hkLifoAllocator *v73; // rax
  int v74; // er8
  int v75; // edi
  hkLifoAllocator *v76; // rax
  int v77; // er8
  char *array; // [rsp+18h] [rbp-79h]
  int sizeElem; // [rsp+20h] [rbp-71h]
  hkResultEnum v80; // [rsp+24h] [rbp-6Dh]
  char *v81; // [rsp+28h] [rbp-69h]
  int v82; // [rsp+30h] [rbp-61h]
  hkResult result; // [rsp+F8h] [rbp+67h]
  unsigned int vars0; // [rsp+100h] [rbp+6Fh]

  v3 = upIn->m_quad;
  v4 = mesh;
  v5 = &mesh->m_faces.m_data[faceIndex];
  v6 = v5->m_numEdges;
  v7 = (unsigned int)v5->m_startEdgeIndex;
  vars0 = v7;
  if ( (_DWORD)v6 != 3 )
  {
    v8 = 0i64;
    v9 = 0;
    if ( (_DWORD)v6 )
    {
      v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v11 = (__m128 *)v10->m_cur;
      v12 = (16 * v6 + 127) & 0xFFFFFF80;
      v13 = (char *)v11 + v12;
      if ( v12 > v10->m_slabSize || v13 > v10->m_end )
        v11 = (__m128 *)hkLifoAllocator::allocateFromNewSlab(v10, v12);
      else
        v10->m_cur = v13;
    }
    else
    {
      v11 = 0i64;
    }
    v14 = 0;
    v15 = v6 | 0x80000000;
    result.m_enum = v6 | 0x80000000;
    if ( (_DWORD)v6 )
    {
      v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v8 = v16->m_cur;
      v17 = (4 * v6 + 127) & 0xFFFFFF80;
      v18 = (char *)v8 + v17;
      if ( v17 > v16->m_slabSize || v18 > v16->m_end )
        v8 = hkLifoAllocator::allocateFromNewSlab(v16, v17);
      else
        v16->m_cur = v18;
    }
    v19 = v6;
    v20 = 0;
    if ( (signed int)v6 <= 0 )
      goto LABEL_79;
    v21 = v6;
    v22 = (signed int)vars0;
    do
    {
      v23 = v4->m_edges.m_data;
      if ( v23[v22].m_oppositeEdge == -1 || (v24 = 1, v23[v22].m_flags.m_storage & 0x20) )
        v24 = 0;
      v25 = v14++;
      v8[v25] = v24;
      if ( v24 )
        ++v20;
      v26 = v23[v22].m_a;
      ++v22;
      v27 = v4->m_vertices.m_data[v26].m_quad;
      v28 = v9++;
      v29 = _mm_mul_ps(v3, v27);
      v11[v28] = _mm_sub_ps(
                   v27,
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                       _mm_shuffle_ps(v29, v29, 170)),
                     v3));
      --v21;
    }
    while ( v21 );
    v15 = result.m_enum;
    if ( v20 < 2 )
    {
LABEL_79:
      v68 = vars0;
    }
    else
    {
      v30 = 16i64 * ((signed int)v6 - 1);
      v31 = v11[v6 - 1];
      v32 = 0i64;
      do
      {
        v33 = v31;
        v31 = v11[v32];
        v34 = _mm_sub_ps(v33, v31);
        v35 = _mm_mul_ps(v34, v34);
        *(__m128 *)((char *)v11 + v30) = _mm_shuffle_ps(
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
      array = 0i64;
      sizeElem = 0;
      v80 = 2147483648;
      v82 = v6;
      if ( (_DWORD)v6 )
      {
        v36 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v37 = (char *)v36->m_cur;
        v38 = (4 * v6 + 127) & 0xFFFFFF80;
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
      }
      else
      {
        v37 = 0i64;
        array = 0i64;
      }
      v80 = v15;
      v40 = v37;
      v81 = v37;
      if ( (v15 & 0x3FFFFFFF) < (signed int)v6 )
      {
        v41 = v6;
        if ( (signed int)v6 < 2 * (v15 & 0x3FFFFFFF) )
          v41 = 2 * (v15 & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v41, 4);
        v40 = v81;
        v37 = array;
      }
      v42 = *(float *)&xmmword_141A712B0;
      v43 = v6;
      v44 = 0;
      v45 = 0;
      v46 = v6 - 1;
      sizeElem = v6;
      if ( (signed int)v6 > 0 )
      {
        v47 = v11;
        v48 = query.m_quad;
        do
        {
          v49 = 0i64;
          v50 = v46;
          if ( v46 != v45 )
          {
            do
            {
              if ( v8[v50] )
                v49 = _mm_max_ps(v49, _mm_shuffle_ps(v11[v50], v11[v50], 255));
              *(_DWORD *)&v37[4 * v50] = v49.m128_i32[0];
              v37 = array;
              v50 = ((signed int)v6 - 1 + v50) % (signed int)v6;
            }
            while ( v50 != v45 );
            v48 = query.m_quad;
          }
          v51 = *v47;
          v52 = 0i64;
          v53 = v45;
          v54 = *v47;
          if ( v45 != v46 )
          {
            do
            {
              v55 = v54;
              v56 = (v53 + 1) % (signed int)v6;
              v57 = _mm_shuffle_ps(v54, v54, 255);
              v54 = v11[v56];
              if ( v8[v53] )
              {
                v52 = _mm_max_ps(v52, v57);
              }
              else if ( v52.m128_f32[0] > 0.0 )
              {
                LODWORD(v58) = (unsigned __int128)_mm_shuffle_ps(
                                                    (__m128)*(unsigned int *)&v37[4 * v53],
                                                    (__m128)*(unsigned int *)&v37[4 * v53],
                                                    0);
                if ( v58 == 0.0 )
                  break;
                v59 = _mm_sub_ps(v54, v55);
                v60 = _mm_mul_ps(_mm_sub_ps(v51, v55), v59);
                v61 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v60, v60, 85), _mm_shuffle_ps(v60, v60, 0)),
                        _mm_shuffle_ps(v60, v60, 170));
                v62 = _mm_rcp_ps(v57);
                v63 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v62, v57)), v62), v61);
                v64 = _mm_cmpltps(v63, v48);
                v65 = _mm_sub_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            v59,
                            _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v63, v64), _mm_andnot_ps(v64, v48)))),
                          v55),
                        v51);
                v66 = _mm_mul_ps(v65, v65);
                v67 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v66, v66, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v66, v66, 0)))
                    + COERCE_FLOAT(_mm_shuffle_ps(v66, v66, 170));
                if ( v67 < (float)(fmin(fmin(v58, v52.m128_f32[0]), v42) - 0.0039215689) )
                {
                  v44 = v45;
                  v42 = v67;
                }
              }
              v53 = (v53 + 1) % (signed int)v6;
            }
            while ( v56 != v46 );
          }
          v46 = v45++;
          ++v47;
        }
        while ( v45 < (signed int)v6 );
        v40 = v81;
        v43 = sizeElem;
      }
      v68 = v44 + vars0;
      if ( v40 == v37 )
        v43 = 0;
      sizeElem = v43;
      v69 = (4 * v82 + 127) & 0xFFFFFF80;
      v70 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v71 = (v69 + 15) & 0xFFFFFFF0;
      if ( v69 > v70->m_slabSize || &v40[v71] != v70->m_cur || v70->m_firstNonLifoEnd == v40 )
        hkLifoAllocator::slowBlockFree(v70, v40, v71);
      else
        v70->m_cur = v40;
      sizeElem = 0;
      if ( (signed int)v80 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          4 * v80);
      array = 0i64;
      v80 = 2147483648;
    }
    v72 = (4 * v6 + 127) & 0xFFFFFF80;
    v73 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v74 = (v72 + 15) & 0xFFFFFFF0;
    if ( v72 > v73->m_slabSize || (char *)v8 + v74 != v73->m_cur || v73->m_firstNonLifoEnd == v8 )
      hkLifoAllocator::slowBlockFree(v73, v8, v74);
    else
      v73->m_cur = v8;
    if ( (signed int)v15 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v8,
        4 * v15);
    v75 = (16 * v6 + 127) & 0xFFFFFF80;
    v76 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v77 = (v75 + 15) & 0xFFFFFFF0;
    if ( v75 > v76->m_slabSize || (char *)v11 + v77 != v76->m_cur || v76->m_firstNonLifoEnd == v11 )
      hkLifoAllocator::slowBlockFree(v76, v11, v77);
    else
      v76->m_cur = v11;
    if ( (signed int)v15 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v11,
        16 * v15);
    v7 = v68;
  }
  return v7;
}

// File Line: 3384
// RVA: 0xBC7420
void __fastcall hkaiNavMeshUtils::setBestFaceCenters(hkaiNavMesh *mesh, hkVector4f *up)
{
  int v2; // esi
  int v3; // ebx
  hkVector4f *v4; // rbp
  hkaiNavMesh *i; // rdi
  int v6; // eax

  v2 = mesh->m_faces.m_size;
  v3 = 0;
  v4 = up;
  for ( i = mesh; v3 < v2; ++v3 )
  {
    v6 = hkaiNavMeshUtils::findBestCenter(i, v3, v4);
    hkaiNavMeshUtils::rotateFace(i, v3, v6);
  }
}


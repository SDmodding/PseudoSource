// File Line: 19
// RVA: 0xB9CB40
void __fastcall hkaiGeometryToEdgeGeometryConverter::hkaiGeometryToEdgeGeometryConverter(hkaiGeometryToEdgeGeometryConverter *this)
{
  this->m_triangles.m_capacityAndFlags = 2147483648;
  this->m_triangles.m_data = 0i64;
  this->m_triangles.m_size = 0;
  this->m_faceTriangleIndices.m_data = 0i64;
  this->m_faceTriangleIndices.m_size = 0;
  this->m_faceTriangleIndices.m_capacityAndFlags = 2147483648;
  this->m_numTrianglesPerFace.m_data = 0i64;
  this->m_numTrianglesPerFace.m_size = 0;
  this->m_numTrianglesPerFace.m_capacityAndFlags = 2147483648;
  this->m_vertices.m_data = 0i64;
  this->m_vertices.m_size = 0;
  this->m_vertices.m_capacityAndFlags = 2147483648;
  this->m_orderedTriangles.m_data = 0i64;
  this->m_orderedTriangles.m_size = 0;
  this->m_orderedTriangles.m_capacityAndFlags = 2147483648;
  this->m_edgeAngularDistance = 0.0;
  this->m_planeEpsilon = 0.0020000001;
  this->m_allowMergingDifferentUserData.m_bool = 0;
}

// File Line: 28
// RVA: 0xB9CBA0
void __fastcall hkaiGeometryToEdgeGeometryConverter::_addEdge(hkaiGeometryToEdgeGeometryConverter *this, int a, int b, int triangle, hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *edgeToTriangleMap)
{
  __int64 v5; // r14
  __int64 v6; // rbx
  unsigned __int64 v7; // rbp
  unsigned __int64 v8; // rsi
  int v9; // eax
  unsigned __int64 v10; // r9
  unsigned __int64 v11; // r8

  v5 = a;
  v6 = b;
  v7 = triangle;
  v8 = b | (unsigned __int64)((signed __int64)a << 32);
  v9 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                           (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&edgeToTriangleMap->m_map.m_elem,
                           v8);
  if ( v9 > edgeToTriangleMap->m_map.m_hashMod )
  {
    v10 = v7;
    v11 = v8;
  }
  else
  {
    v10 = -1i64;
    edgeToTriangleMap->m_map.m_elem[v9].val = -1i64;
    v11 = v5 | (v6 << 32);
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&edgeToTriangleMap->m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v11,
    v10);
}

// File Line: 48
// RVA: 0xB9CC40
void __fastcall hkaiGeometryToEdgeGeometryConverter::_calculatePlane(hkaiGeometryToEdgeGeometryConverter *this, hkaiGeometryToEdgeGeometryConverter::Triangle *tri, hkVector4f *planeOut)
{
  hkVector4f *v3; // r9
  __m128 v4; // xmm4
  __m128 v5; // xmm1
  __m128 v6; // xmm0
  __m128 v7; // xmm5
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm4

  v3 = this->m_vertices.m_data;
  v4 = v3[tri->m_vertexIndices[0]].m_quad;
  v5 = _mm_sub_ps(v3[tri->m_vertexIndices[1]].m_quad, v4);
  v6 = _mm_sub_ps(v3[tri->m_vertexIndices[2]].m_quad, v4);
  v7 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v5), _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v6));
  v8 = _mm_shuffle_ps(v7, v7, 201);
  v9 = _mm_mul_ps(v8, v8);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 170))) >= COERCE_FLOAT(
                                                               _mm_shuffle_ps(
                                                                 (__m128)LODWORD(FLOAT_9_9999994eN11),
                                                                 (__m128)LODWORD(FLOAT_9_9999994eN11),
                                                                 0)) )
  {
    v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
    v12 = _mm_rsqrt_ps(v11);
    v10 = _mm_mul_ps(
            v8,
            _mm_andnot_ps(
              _mm_cmpleps(v11, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
                _mm_mul_ps(*(__m128 *)_xmm, v12))));
  }
  else
  {
    v10 = transform.m_quad;
  }
  v13 = _mm_mul_ps(v4, v10);
  planeOut->m_quad = _mm_shuffle_ps(
                       v10,
                       _mm_unpackhi_ps(
                         v10,
                         _mm_sub_ps(
                           (__m128)0i64,
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                             _mm_shuffle_ps(v13, v13, 170)))),
                       196);
}

// File Line: 70
// RVA: 0xB9D150
char __fastcall hkaiGeometryToEdgeGeometryConverter::_hasEdge(hkaiGeometryToEdgeGeometryConverter::Triangle *tri, int a, int b)
{
  signed int v3; // er9
  signed __int64 v4; // r10
  __int64 v5; // rax

  v3 = 0;
  v4 = 8i64;
  v5 = 0i64;
  while ( *(int *)((char *)tri->m_vertexIndices + v4) != a || tri->m_vertexIndices[v5] != b )
  {
    ++v3;
    v4 = v5 * 4;
    ++v5;
    if ( v3 >= 3 )
      return 0;
  }
  return 1;
}

// File Line: 86
// RVA: 0xB9CD60
void __fastcall hkaiGeometryToEdgeGeometryConverter::_tryAddNeighbor(hkaiGeometryToEdgeGeometryConverter *this, hkaiGeometryToEdgeGeometryConverter::Triangle *startTri, int a, int b, hkVector4f *facePlane, hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *edgeToTriangleMap)
{
  hkaiGeometryToEdgeGeometryConverter::Triangle *v6; // r12
  __int64 v7; // rsi
  int v8; // edi
  hkaiGeometryToEdgeGeometryConverter *v9; // rbx
  float v10; // xmm6_4
  __int64 v11; // r14
  int v12; // eax
  int v13; // er15
  hkaiGeometryToEdgeGeometryConverter::Triangle *v14; // r9
  int v15; // er8
  int *v16; // rax
  signed __int64 v17; // rcx
  hkVector4f *v18; // rdx
  float v19; // xmm7_4
  __m128 v20; // xmm11
  __m128 v21; // xmm8
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 v24; // xmm1
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  __m128 v27; // xmm4
  __m128 v28; // xmm1
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  __m128 v31; // xmm4
  __m128 v32; // xmm3
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm2
  __m128 v38; // xmm0
  float v39; // xmm2_4
  bool v40; // cf
  bool v41; // zf
  float v42; // xmm0_4
  float v43; // xmm1_4
  __m128 v44; // xmm2
  __m128 v45; // xmm2
  __m128 v46; // xmm0
  float v47; // xmm1_4

  v6 = startTri;
  v7 = a;
  v8 = b;
  v9 = this;
  LODWORD(v10) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(FLOAT_9_9999994eN11),
                                      (__m128)LODWORD(FLOAT_9_9999994eN11),
                                      0);
  v11 = b;
  v12 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&edgeToTriangleMap->m_map.m_elem,
          a | (unsigned __int64)((signed __int64)b << 32),
          0xFFFFFFFFFFFFFFFFui64);
  v13 = v12;
  if ( v12 >= 0 )
  {
    v14 = &v9->m_triangles.m_data[v12];
    if ( v14->m_face < 0 && (v14->m_userData == v6->m_userData || v9->m_allowMergingDifferentUserData.m_bool) )
    {
      v15 = 0;
      v16 = v14->m_vertexIndices;
      v17 = 0i64;
      while ( *v16 == (_DWORD)v7 || *v16 == v8 )
      {
        ++v17;
        ++v15;
        ++v16;
        if ( v17 >= 3 )
          return;
      }
      if ( v15 >= 0 )
      {
        v18 = v9->m_vertices.m_data;
        LODWORD(v19) = (unsigned __int128)_mm_shuffle_ps(
                                            (__m128)LODWORD(v9->m_edgeAngularDistance),
                                            (__m128)LODWORD(v9->m_edgeAngularDistance),
                                            0);
        if ( v19 <= 0.0 )
        {
          v44 = _mm_mul_ps(v18[v14->m_vertexIndices[v15]].m_quad, facePlane->m_quad);
          v45 = _mm_shuffle_ps(v44, _mm_unpackhi_ps(v44, facePlane->m_quad), 196);
          v46 = _mm_add_ps(_mm_shuffle_ps(v45, v45, 78), v45);
          LODWORD(v47) = (unsigned int)(2
                                      * COERCE_SIGNED_INT(COERCE_FLOAT(_mm_shuffle_ps(v46, v46, 177)) + v46.m128_f32[0])) >> 1;
          v40 = v47 < v9->m_planeEpsilon;
          v41 = v47 == v9->m_planeEpsilon;
        }
        else
        {
          v20 = v18[v14->m_vertexIndices[v15]].m_quad;
          v21 = _mm_sub_ps(v18[v11].m_quad, v18[v7].m_quad);
          v22 = _mm_mul_ps(v21, v21);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 170))) >= v10 )
          {
            v28 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                    _mm_shuffle_ps(v22, v22, 170));
            v29 = _mm_sub_ps(v20, v18[v7].m_quad);
            v30 = _mm_rsqrt_ps(v28);
            v31 = _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_andnot_ps(
                        _mm_cmpleps(v28, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v28), v30)),
                          _mm_mul_ps(v30, *(__m128 *)_xmm))),
                      v21),
                    v29);
            v32 = _mm_mul_ps(v29, v29);
            v33 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                    _mm_shuffle_ps(v31, v31, 170));
            v34 = _mm_sub_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                      _mm_shuffle_ps(v32, v32, 170)),
                    _mm_mul_ps(v33, v33));
            v35 = _mm_rsqrt_ps(v34);
            v27 = _mm_andnot_ps(
                    _mm_cmpleps(v34, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v35, v34), v35)),
                        _mm_mul_ps(v35, *(__m128 *)_xmm)),
                      v34));
          }
          else
          {
            v23 = _mm_sub_ps(v20, v18[v7].m_quad);
            v24 = _mm_mul_ps(v23, v23);
            v25 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                    _mm_shuffle_ps(v24, v24, 170));
            v26 = _mm_rsqrt_ps(v25);
            v27 = _mm_andnot_ps(
                    _mm_cmpleps(v25, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                        _mm_mul_ps(*(__m128 *)_xmm, v26)),
                      v25));
          }
          v36 = _mm_mul_ps(facePlane->m_quad, v20);
          v37 = _mm_shuffle_ps(v36, _mm_unpackhi_ps(v36, facePlane->m_quad), 196);
          v38 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 78), v37);
          LODWORD(v39) = (unsigned int)(2
                                      * COERCE_SIGNED_INT(COERCE_FLOAT(_mm_shuffle_ps(v38, v38, 177)) + v38.m128_f32[0])) >> 1;
          if ( v27.m128_f32[0] >= v19 )
          {
            LODWORD(v42) = (unsigned __int128)_mm_rcp_ps(v27);
            v43 = (float)((float)(2.0 - (float)(v27.m128_f32[0] * v42)) * v42) * (float)(v39 * v19);
            v40 = v43 < v9->m_planeEpsilon;
            v41 = v43 == v9->m_planeEpsilon;
          }
          else
          {
            v40 = v39 < v9->m_planeEpsilon;
            v41 = v39 == v9->m_planeEpsilon;
          }
        }
        if ( v40 || v41 )
        {
          v14->m_face = v6->m_face;
          if ( v9->m_faceTriangleIndices.m_size == (v9->m_faceTriangleIndices.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v9->m_faceTriangleIndices,
              4);
          v9->m_faceTriangleIndices.m_data[v9->m_faceTriangleIndices.m_size++] = v13;
        }
      }
    }
  }
}

// File Line: 207
// RVA: 0xB9D0D0
signed __int64 __fastcall hkaiGeometryToEdgeGeometryConverter::_findNeighboringFace(hkaiGeometryToEdgeGeometryConverter *this, int faceIndex, int a, int b, hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *edgeToTriangleMap)
{
  int v5; // ebx
  hkaiGeometryToEdgeGeometryConverter *v6; // rdi
  int v7; // eax
  signed __int64 result; // rax

  v5 = faceIndex;
  v6 = this;
  v7 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&edgeToTriangleMap->m_map.m_elem,
         a | (unsigned __int64)((signed __int64)b << 32),
         0xFFFFFFFFFFFFFFFFui64);
  if ( v7 < 0 )
    return 0i64;
  result = (unsigned int)v6->m_triangles.m_data[v7].m_face;
  if ( v5 == (_DWORD)result )
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 227
// RVA: 0xB9D190
void __fastcall hkaiGeometryToEdgeGeometryConverter::_findCoplanarTriangleFaces(hkaiGeometryToEdgeGeometryConverter *this, hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *edgeToTriangleMap)
{
  __int64 v2; // rbx
  hkArray<hkaiGeometryToEdgeGeometryConverter::TriangleArea,hkContainerHeapAllocator> *v3; // rsi
  int v4; // eax
  hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *v5; // r14
  hkaiGeometryToEdgeGeometryConverter *v6; // rdi
  int v7; // eax
  int v8; // er9
  hkaiGeometryToEdgeGeometryConverter::Triangle *v9; // rdx
  hkpTypedBroadPhaseHandlePair *v10; // r9
  signed __int64 v11; // r8
  int *v12; // rdx
  hkVector4f *v13; // rcx
  __m128 v14; // xmm0
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  signed __int64 v17; // rax
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm3
  __m128 v21; // xmm3
  __m128 v22; // xmm4
  __m128 v23; // xmm2
  __int64 v24; // rdx
  __int64 v25; // rcx
  hkaiGeometryToEdgeGeometryConverter::Triangle *v26; // rsi
  signed __int64 v27; // r12
  unsigned __int64 v28; // rdx
  unsigned __int64 v29; // rbx
  signed int v30; // eax
  signed __int64 v31; // rcx
  signed int v32; // er13
  int v33; // ebp
  signed __int64 v34; // rsi
  hkaiGeometryToEdgeGeometryConverter::Triangle *v35; // rax
  hkaiGeometryToEdgeGeometryConverter::Triangle *v36; // rbx
  int v37; // esi
  hkVector4f planeOut; // [rsp+30h] [rbp-68h]
  hkResult result; // [rsp+A0h] [rbp+8h]
  __int64 v40; // [rsp+B0h] [rbp+18h]

  v2 = this->m_triangles.m_size;
  v3 = &this->m_orderedTriangles;
  v4 = this->m_orderedTriangles.m_capacityAndFlags & 0x3FFFFFFF;
  v5 = edgeToTriangleMap;
  v6 = this;
  if ( v4 < (signed int)v2 )
  {
    v7 = 2 * v4;
    v8 = v2;
    if ( (signed int)v2 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v8, 16);
  }
  v3->m_size = v2;
  v9 = v6->m_triangles.m_data;
  v10 = (hkpTypedBroadPhaseHandlePair *)v3->m_data;
  v11 = (signed __int64)&v9[v6->m_triangles.m_size];
  if ( v9 != (hkaiGeometryToEdgeGeometryConverter::Triangle *)v11 )
  {
    v12 = v9->m_vertexIndices;
    do
    {
      v13 = v6->m_vertices.m_data;
      ++v10;
      v14 = v13[*v12].m_quad;
      v15 = _mm_sub_ps(v13[v12[1]].m_quad, v14);
      v16 = v13[v12[2]].m_quad;
      v17 = (signed __int64)(v12 - 2);
      v12 += 5;
      v18 = _mm_sub_ps(v16, v14);
      v19 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v18));
      v20 = _mm_shuffle_ps(v19, v19, 201);
      v21 = _mm_mul_ps(v20, v20);
      v22 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
              _mm_shuffle_ps(v21, v21, 170));
      v23 = _mm_rsqrt_ps(v22);
      LODWORD(v10[-1].m_b) = (unsigned __int128)_mm_andnot_ps(
                                                  _mm_cmpleps(v22, (__m128)0i64),
                                                  _mm_mul_ps(
                                                    _mm_mul_ps(
                                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                                                      _mm_mul_ps(*(__m128 *)_xmm, v23)),
                                                    v22));
      v10[-1].m_a = (hkpBroadPhaseHandle *)v17;
    }
    while ( v12 - 2 != (int *)v11 );
  }
  if ( (signed int)v2 > 1 )
    hkAlgorithm::quickSortRecursive<hkaiGeometryToEdgeGeometryConverter::TriangleArea,bool (*)(hkaiGeometryToEdgeGeometryConverter::TriangleArea const &,hkaiGeometryToEdgeGeometryConverter::TriangleArea const &)>(
      (hkpTypedBroadPhaseHandlePair *)v3->m_data,
      0,
      v2 - 1,
      (bool (__fastcall *)(hkpTypedBroadPhaseHandlePair *, hkpTypedBroadPhaseHandlePair *))hkaiGeometryToEdgeGeometryConverter::_orderTriangles);
  v24 = v2;
  v40 = v2;
  if ( (signed int)v2 > 0 )
  {
    v25 = 0i64;
    *(_QWORD *)&result.m_enum = 0i64;
    do
    {
      v26 = *(hkaiGeometryToEdgeGeometryConverter::Triangle **)((char *)&v3->m_data->m_triangle + v25);
      if ( v26->m_face < 0 )
      {
        v27 = v6->m_faceTriangleIndices.m_size;
        v28 = (unsigned __int128)(((char *)v26 - (char *)v6->m_triangles.m_data)
                                * (signed __int128)7378697629483820647i64) >> 64;
        v29 = (v28 >> 63) + ((signed __int64)v28 >> 3);
        v26->m_face = v6->m_numTrianglesPerFace.m_size;
        if ( v6->m_faceTriangleIndices.m_size == (v6->m_faceTriangleIndices.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v6->m_faceTriangleIndices,
            4);
        v6->m_faceTriangleIndices.m_data[v6->m_faceTriangleIndices.m_size++] = v29;
        hkaiGeometryToEdgeGeometryConverter::_calculatePlane(v6, v26, &planeOut);
        v30 = v6->m_faceTriangleIndices.m_size;
        v31 = v27;
        do
        {
          v32 = v30;
          v33 = v27;
          if ( (signed int)v27 < v30 )
          {
            v34 = v31;
            do
            {
              v35 = v6->m_triangles.m_data;
              v36 = &v35[v6->m_faceTriangleIndices.m_data[v34]];
              hkaiGeometryToEdgeGeometryConverter::_tryAddNeighbor(
                v6,
                &v35[v6->m_faceTriangleIndices.m_data[v34]],
                v35[v6->m_faceTriangleIndices.m_data[v34]].m_vertexIndices[0],
                v35[v6->m_faceTriangleIndices.m_data[v34]].m_vertexIndices[1],
                &planeOut,
                v5);
              hkaiGeometryToEdgeGeometryConverter::_tryAddNeighbor(
                v6,
                v36,
                v36->m_vertexIndices[1],
                v36->m_vertexIndices[2],
                &planeOut,
                v5);
              hkaiGeometryToEdgeGeometryConverter::_tryAddNeighbor(
                v6,
                v36,
                v36->m_vertexIndices[2],
                v36->m_vertexIndices[0],
                &planeOut,
                v5);
              ++v33;
              ++v34;
            }
            while ( v33 < v6->m_faceTriangleIndices.m_size );
            v31 = v27;
          }
          v30 = v6->m_faceTriangleIndices.m_size;
        }
        while ( v30 != v32 );
        v37 = v30 - v27;
        if ( v6->m_numTrianglesPerFace.m_size == (v6->m_numTrianglesPerFace.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v6->m_numTrianglesPerFace,
            4);
        v24 = v40;
        v6->m_numTrianglesPerFace.m_data[v6->m_numTrianglesPerFace.m_size++] = v37;
        v25 = *(_QWORD *)&result.m_enum;
      }
      v25 += 16i64;
      --v24;
      v3 = &v6->m_orderedTriangles;
      v40 = v24;
      *(_QWORD *)&result.m_enum = v25;
    }
    while ( v24 );
  }
}

// File Line: 316
// RVA: 0xB9C320
hkResult *__fastcall hkaiGeometryToEdgeGeometryConverter::convertGeometryToEdgeGeometry(hkaiGeometryToEdgeGeometryConverter *this, hkResult *result, hkGeometry *mesh, hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char> faceFlags, hkaiEdgeGeometry *geomOut)
{
  hkaiEdgeGeometry *v5; // r13
  hkaiGeometryToEdgeGeometryConverter *v6; // r15
  hkGeometry *v7; // rbx
  hkResult *v8; // r12
  hkArray<hkaiGeometryToEdgeGeometryConverter::Triangle,hkContainerHeapAllocator> *v9; // rsi
  __int64 v10; // rdi
  int v11; // eax
  int v12; // eax
  int v13; // er9
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r9
  hkaiGeometryToEdgeGeometryConverter::Triangle *v18; // rdx
  hkGeometry::Triangle *v19; // rcx
  int v20; // ecx
  hkVector4f *v21; // rax
  int v22; // eax
  void *v23; // rdx
  hkResultEnum v24; // ecx
  int v25; // eax
  int v26; // edi
  __int64 v27; // rsi
  int *v28; // rbx
  int v29; // er9
  int v30; // eax
  int v31; // eax
  int v32; // er9
  int v33; // eax
  int v34; // eax
  int v35; // er9
  hkArray<int,hkContainerHeapAllocator> *v36; // rdi
  int v37; // eax
  int v38; // eax
  __int64 v39; // r14
  __int64 v40; // rbx
  signed __int64 v41; // r15
  int v42; // eax
  int v43; // eax
  int v44; // er9
  int v45; // er8
  __int64 v46; // r9
  __int64 v47; // rdx
  hkaiGeometryToEdgeGeometryConverter *v48; // r10
  hkResultEnum v49; // er12
  __int32 v50; // ecx
  hkaiEdgeGeometry *v51; // rbx
  __int64 v52; // r14
  int v53; // ecx
  __int64 v54; // rdx
  __int64 v55; // r8
  __int64 v56; // rcx
  int *v57; // rax
  __int64 v58; // rdi
  __int64 v59; // rcx
  hkaiGeometryToEdgeGeometryConverter::Triangle *v60; // rax
  signed __int64 v61; // rsi
  signed __int64 v62; // r13
  signed __int64 v63; // rax
  unsigned int v64; // er14
  unsigned int v65; // er15
  hkaiEdgeGeometry::Edge *v66; // rcx
  bool v67; // zf
  __int64 v68; // r12
  int *v69; // rax
  __int64 v70; // rdi
  __int64 v71; // rcx
  hkResultEnum v72; // er12
  signed __int64 v73; // r15
  signed __int64 v74; // r13
  signed __int64 v75; // rax
  unsigned int v76; // esi
  unsigned int v77; // er14
  hkaiEdgeGeometry::Edge *v78; // rcx
  hkResult *v79; // rbx
  int v80; // er9
  hkVector4f *v81; // rax
  __int64 v82; // rax
  hkVector4f *v83; // rcx
  __int64 v84; // rdx
  char *v85; // r8
  hkVector4f v86; // xmm0
  int sizeElem; // [rsp+20h] [rbp-91h]
  hkResult v88; // [rsp+30h] [rbp-81h]
  int v89; // [rsp+34h] [rbp-7Dh]
  hkResult v90; // [rsp+38h] [rbp-79h]
  hkResult v91; // [rsp+3Ch] [rbp-75h]
  int v92; // [rsp+40h] [rbp-71h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v93; // [rsp+48h] [rbp-69h]
  void *v94; // [rsp+58h] [rbp-59h]
  int v95; // [rsp+60h] [rbp-51h]
  __int64 v96; // [rsp+68h] [rbp-49h]
  __int64 v97; // [rsp+70h] [rbp-41h]
  int v98; // [rsp+78h] [rbp-39h]
  int v99; // [rsp+7Ch] [rbp-35h]
  __int64 v100; // [rsp+80h] [rbp-31h]
  __int64 v101; // [rsp+88h] [rbp-29h]
  hkArray<int,hkContainerHeapAllocator> *v102; // [rsp+90h] [rbp-21h]
  __int64 v103; // [rsp+98h] [rbp-19h]
  hkArray<hkaiGeometryToEdgeGeometryConverter::Triangle,hkContainerHeapAllocator> *v104; // [rsp+A0h] [rbp-11h]
  hkArray<hkaiEdgeGeometry::Face,hkContainerHeapAllocator> *v105; // [rsp+A8h] [rbp-9h]
  __int64 v106; // [rsp+B0h] [rbp-1h]
  hkaiGeometryToEdgeGeometryConverter *v107; // [rsp+110h] [rbp+5Fh]
  hkResult *v108; // [rsp+118h] [rbp+67h]
  hkResult resulta; // [rsp+120h] [rbp+6Fh]
  char v110; // [rsp+128h] [rbp+77h]

  v110 = faceFlags.m_storage;
  v108 = result;
  v107 = this;
  v5 = geomOut;
  v6 = this;
  v7 = mesh;
  v8 = result;
  hkaiEdgeGeometry::clear(geomOut);
  v9 = &v6->m_triangles;
  v6->m_triangles.m_size = 0;
  v6->m_faceTriangleIndices.m_size = 0;
  v6->m_numTrianglesPerFace.m_size = 0;
  v6->m_vertices.m_size = 0;
  v6->m_orderedTriangles.m_size = 0;
  v10 = v7->m_triangles.m_size;
  v11 = v6->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  v104 = &v6->m_triangles;
  if ( v11 < (signed int)v10 )
  {
    v12 = 2 * v11;
    v13 = v10;
    if ( (signed int)v10 < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_triangles,
      v13,
      20);
  }
  v6->m_triangles.m_size = v10;
  if ( (v6->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) > 0 && !v9->m_data )
  {
    v8->m_enum = 1;
    return v8;
  }
  v15 = v10;
  if ( (signed int)v10 > 0 )
  {
    v16 = 0i64;
    v17 = 0i64;
    do
    {
      v18 = &v9->m_data[v17];
      v19 = &v7->m_triangles.m_data[v16];
      ++v17;
      v18->m_face = -1;
      ++v16;
      v18->m_userData = v19->m_material;
      v18->m_vertexIndices[0] = v19->m_a;
      v18->m_vertexIndices[1] = v19->m_b;
      v18->m_vertexIndices[2] = v19->m_c;
      --v15;
    }
    while ( v15 );
  }
  v20 = v7->m_vertices.m_size;
  v21 = v7->m_vertices.m_data;
  v6->m_vertices.m_size = v20;
  v6->m_vertices.m_data = v21;
  v6->m_vertices.m_capacityAndFlags = v20 | 0x80000000;
  v22 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getSizeInBytesFor(3 * v6->m_triangles.m_size);
  if ( v22 )
  {
    v95 = v22;
    v23 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            &v95);
    v22 = v95;
  }
  else
  {
    v23 = 0i64;
  }
  v24 = 2147483648;
  v94 = v23;
  if ( v22 )
    v24 = v22;
  resulta.m_enum = v24;
  v25 = v24 & 0x3FFFFFFF;
  v89 = v24 & 0x3FFFFFFF;
  if ( (v24 & 0x3FFFFFFF) > 0 && !v23 )
  {
    v8->m_enum = 1;
    if ( (signed int)v24 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        0i64,
        v25);
    return v8;
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>(
    &v93,
    v23,
    v25);
  v26 = 0;
  if ( v6->m_triangles.m_size > 0 )
  {
    v27 = 0i64;
    do
    {
      v28 = &v6->m_triangles.m_data[v27].m_userData;
      hkaiGeometryToEdgeGeometryConverter::_addEdge(
        v6,
        v28[2],
        v28[3],
        v26,
        (hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *)&v93);
      hkaiGeometryToEdgeGeometryConverter::_addEdge(
        v6,
        v28[3],
        v28[4],
        v26,
        (hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *)&v93);
      hkaiGeometryToEdgeGeometryConverter::_addEdge(
        v6,
        v28[4],
        v28[2],
        v26++,
        (hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *)&v93);
      ++v27;
    }
    while ( v26 < v6->m_triangles.m_size );
    v9 = &v6->m_triangles;
  }
  v29 = v6->m_triangles.m_size;
  v30 = v6->m_numTrianglesPerFace.m_capacityAndFlags & 0x3FFFFFFF;
  v101 = 4i64;
  if ( v30 < v29 )
  {
    v31 = 2 * v30;
    if ( v29 < v31 )
      v29 = v31;
    hkArrayUtil::_reserve(
      &v90,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_numTrianglesPerFace,
      v29,
      4);
  }
  v32 = v6->m_triangles.m_size;
  v33 = v6->m_orderedTriangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v33 < v32 )
  {
    v34 = 2 * v33;
    if ( v32 < v34 )
      v32 = v34;
    hkArrayUtil::_reserve(
      &v90,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_orderedTriangles,
      v32,
      16);
  }
  v35 = v6->m_triangles.m_size;
  v36 = &v6->m_faceTriangleIndices;
  v37 = v6->m_faceTriangleIndices.m_capacityAndFlags & 0x3FFFFFFF;
  v102 = &v6->m_faceTriangleIndices;
  if ( v37 < v35 )
  {
    v38 = 2 * v37;
    if ( v35 < v38 )
      v35 = v38;
    hkArrayUtil::_reserve(
      &v90,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_faceTriangleIndices,
      v35,
      4);
  }
  if ( (v6->m_numTrianglesPerFace.m_capacityAndFlags & 0x3FFFFFFF) > 0 && !v6->m_numTrianglesPerFace.m_data
    || (v6->m_orderedTriangles.m_capacityAndFlags & 0x3FFFFFFF) > 0 && !v6->m_orderedTriangles.m_data
    || (v6->m_faceTriangleIndices.m_capacityAndFlags & 0x3FFFFFFF) > 0 && !v36->m_data )
  {
    goto LABEL_50;
  }
  v39 = 4i64;
  if ( v6->m_numTrianglesPerFace.m_size == (v6->m_numTrianglesPerFace.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_numTrianglesPerFace,
      4);
  v6->m_numTrianglesPerFace.m_data[v6->m_numTrianglesPerFace.m_size++] = 0;
  hkaiGeometryToEdgeGeometryConverter::_findCoplanarTriangleFaces(
    v6,
    (hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *)&v93);
  v40 = v6->m_numTrianglesPerFace.m_size;
  v41 = (signed __int64)&v5->m_faces;
  v42 = v5->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
  v105 = &v5->m_faces;
  v100 = 12i64;
  if ( v42 >= (signed int)v40 )
    goto LABEL_102;
  v43 = 2 * v42;
  v44 = v40;
  if ( (signed int)v40 < v43 )
    v44 = v43;
  hkArrayUtil::_reserve(&v88, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v5->m_faces, v44, 12);
  if ( v88.m_enum == HK_SUCCESS )
  {
LABEL_102:
    v5->m_faces.m_size = v40;
LABEL_53:
    v45 = 0;
    v46 = v40;
    if ( (signed int)v40 > 0 )
    {
      v47 = 0i64;
      do
      {
        v47 += 12i64;
        *(_DWORD *)(v47 + *(_QWORD *)v41 - 12) = 0;
        *(_DWORD *)(v47 + *(_QWORD *)v41 - 8) = v45++;
        *(_BYTE *)(v47 + *(_QWORD *)v41 - 4) = v110;
        --v46;
      }
      while ( v46 );
    }
    v48 = v107;
    v49 = 1;
    v50 = 0;
    *(_BYTE *)(*(_QWORD *)v41 + 8i64) = 0;
    v88.m_enum = 1;
    v92 = 0;
    if ( v107->m_numTrianglesPerFace.m_size > 1 )
    {
      while ( 1 )
      {
        v51 = geomOut;
        v52 = *(int *)((char *)v48->m_numTrianglesPerFace.m_data + v39);
        v90.m_enum = (signed int)v52;
        if ( (signed int)v52 > 0 )
        {
          *(_DWORD *)(v100 + *(_QWORD *)v41) = v9->m_data[v36->m_data[v50]].m_userData;
          hkaiArrayUtil::reserveSmall<hkVector4f,hkContainerHeapAllocator>(
            (hkaiArrayUtil *)&v99,
            (hkResult *)&v51->m_edges,
            (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(unsigned int)(v51->m_edges.m_size + 3 * v52),
            -1,
            sizeElem);
          if ( v99 == 1 )
          {
            v79 = v108;
            v108->m_enum = 1;
            goto LABEL_97;
          }
          v48 = v107;
        }
        v53 = v51->m_edges.m_size;
        v54 = v92;
        v55 = v52;
        v97 = v52;
        v98 = v53;
        v106 = v92;
        if ( (signed int)v52 > 0 )
        {
          v56 = 4i64 * v92;
          v96 = v52;
          v103 = 4i64 * v92;
          do
          {
            v57 = v36->m_data;
            v58 = 0i64;
            v59 = *(int *)((char *)v57 + v56);
            v60 = v9->m_data;
            v61 = 3i64;
            v62 = (signed __int64)&v60[v59];
            v63 = 8i64;
            do
            {
              v64 = *(_DWORD *)(v63 + v62 + 8);
              v65 = *(_DWORD *)(v62 + v58 + 8);
              if ( hkaiGeometryToEdgeGeometryConverter::_findNeighboringFace(
                     v48,
                     v49,
                     *(_DWORD *)(v63 + v62 + 8),
                     *(_DWORD *)(v62 + v58 + 8),
                     (hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *)&v93) >= 0 )
              {
                if ( v51->m_edges.m_size == (v51->m_edges.m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    &v51->m_edges,
                    16);
                v66 = &v51->m_edges.m_data[v51->m_edges.m_size++];
                v51 = geomOut;
                v66->m_a = v64;
                v66->m_b = v65;
                v66->m_face = v49;
                v66->m_data = 0;
              }
              v48 = v107;
              v63 = v58;
              v58 += 4i64;
              --v61;
            }
            while ( v61 );
            v9 = &v107->m_triangles;
            v36 = &v107->m_faceTriangleIndices;
            v56 = v103 + 4;
            v67 = v96-- == 1;
            v103 += 4i64;
          }
          while ( !v67 );
          v53 = v98;
          v54 = v106;
          v55 = v97;
          v36 = v102;
        }
        if ( v51->m_edges.m_size - v53 < 3 )
        {
          v51->m_edges.m_size = v53;
          if ( v55 > 0 )
          {
            v68 = 4 * v54;
            v96 = 4 * v54;
            do
            {
              v69 = v36->m_data;
              v70 = 0i64;
              v71 = *(int *)((char *)v69 + v68);
              v72 = v88.m_enum;
              v73 = 3i64;
              v74 = (signed __int64)&v104->m_data[v71];
              v75 = 8i64;
              do
              {
                v76 = *(_DWORD *)(v75 + v74 + 8);
                v77 = *(_DWORD *)(v74 + v70 + 8);
                if ( v51->m_edges.m_size == (v51->m_edges.m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    &v51->m_edges,
                    16);
                v78 = &v51->m_edges.m_data[v51->m_edges.m_size++];
                v75 = v70;
                v70 += 4i64;
                v78->m_a = v76;
                v78->m_b = v77;
                v78->m_face = v72;
                v78->m_data = 0;
                --v73;
              }
              while ( v73 );
              v36 = v102;
              v68 = v96 + 4;
              v67 = v97-- == 1;
              v96 += 4i64;
            }
            while ( !v67 );
            v49 = v88.m_enum;
          }
        }
        v48 = v107;
        v50 = v90.m_enum + v92;
        v100 += 12i64;
        ++v49;
        v39 = v101 + 4;
        v88.m_enum = v49;
        v92 += v90.m_enum;
        v101 += 4i64;
        if ( v49 >= v107->m_numTrianglesPerFace.m_size )
          break;
        v41 = (signed __int64)v105;
        v9 = &v107->m_triangles;
        v36 = &v107->m_faceTriangleIndices;
      }
      v5 = geomOut;
    }
    v80 = v48->m_vertices.m_size;
    if ( (v5->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) >= v80 )
    {
      v91.m_enum = 0;
    }
    else
    {
      hkArrayUtil::_reserve(
        &v91,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v5->m_vertices,
        v80,
        16);
      if ( v91.m_enum )
        goto LABEL_94;
      v48 = v107;
    }
    if ( (v5->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) < v48->m_vertices.m_size )
    {
      if ( v5->m_vertices.m_capacityAndFlags >= 0 )
      {
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v5->m_vertices.m_data,
          16 * v5->m_vertices.m_capacityAndFlags);
        v48 = v107;
      }
      v88.m_enum = 16 * v48->m_vertices.m_size;
      v81 = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                            (int *)&v88);
      v48 = v107;
      v5->m_vertices.m_data = v81;
      v5->m_vertices.m_capacityAndFlags = v88.m_enum / 16;
    }
    v82 = v48->m_vertices.m_size;
    v83 = v5->m_vertices.m_data;
    v5->m_vertices.m_size = v82;
    v84 = v82;
    if ( (signed int)v82 > 0 )
    {
      v85 = (char *)((char *)v48->m_vertices.m_data - (char *)v83);
      do
      {
        v86.m_quad = *(__m128 *)((char *)v83 + (_QWORD)v85);
        ++v83;
        v83[-1] = (hkVector4f)v86.m_quad;
        --v84;
      }
      while ( v84 );
    }
LABEL_94:
    v79 = v108;
    v108->m_enum = v91.m_enum == 1;
LABEL_97:
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v93,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&v93);
    if ( (signed int)resulta.m_enum >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v94,
        v89);
    return v79;
  }
  if ( v88.m_enum != 1 )
    goto LABEL_53;
LABEL_50:
  v8->m_enum = 1;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v93,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v93);
  if ( (signed int)resulta.m_enum < 0 )
    return v8;
  hkContainerHeapAllocator::s_alloc.vfptr->bufFree((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc, v94, v89);
  return v8;
}


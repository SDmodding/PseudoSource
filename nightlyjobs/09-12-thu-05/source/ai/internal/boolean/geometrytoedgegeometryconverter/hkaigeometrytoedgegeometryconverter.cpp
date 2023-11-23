// File Line: 19
// RVA: 0xB9CB40
void __fastcall hkaiGeometryToEdgeGeometryConverter::hkaiGeometryToEdgeGeometryConverter(
        hkaiGeometryToEdgeGeometryConverter *this)
{
  this->m_triangles.m_capacityAndFlags = 0x80000000;
  this->m_triangles.m_data = 0i64;
  this->m_triangles.m_size = 0;
  this->m_faceTriangleIndices.m_data = 0i64;
  this->m_faceTriangleIndices.m_size = 0;
  this->m_faceTriangleIndices.m_capacityAndFlags = 0x80000000;
  this->m_numTrianglesPerFace.m_data = 0i64;
  this->m_numTrianglesPerFace.m_size = 0;
  this->m_numTrianglesPerFace.m_capacityAndFlags = 0x80000000;
  this->m_vertices.m_data = 0i64;
  this->m_vertices.m_size = 0;
  this->m_vertices.m_capacityAndFlags = 0x80000000;
  this->m_orderedTriangles.m_data = 0i64;
  this->m_orderedTriangles.m_size = 0;
  this->m_orderedTriangles.m_capacityAndFlags = 0x80000000;
  this->m_edgeAngularDistance = 0.0;
  this->m_planeEpsilon = 0.0020000001;
  this->m_allowMergingDifferentUserData.m_bool = 0;
}

// File Line: 28
// RVA: 0xB9CBA0
void __fastcall hkaiGeometryToEdgeGeometryConverter::_addEdge(
        hkaiGeometryToEdgeGeometryConverter *this,
        int a,
        int b,
        int triangle,
        hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *edgeToTriangleMap)
{
  __int64 v5; // r14
  __int64 v6; // rbx
  unsigned __int64 v7; // rbp
  unsigned __int64 v8; // rsi
  int Key; // eax
  unsigned __int64 v10; // r9
  unsigned __int64 v11; // r8

  v5 = a;
  v6 = b;
  v7 = triangle;
  v8 = b | (unsigned __int64)((__int64)a << 32);
  Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                        &edgeToTriangleMap->m_map,
                        v8);
  if ( Key > edgeToTriangleMap->m_map.m_hashMod )
  {
    v10 = v7;
    v11 = v8;
  }
  else
  {
    v10 = -1i64;
    edgeToTriangleMap->m_map.m_elem[Key].val = -1i64;
    v11 = v5 | (v6 << 32);
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &edgeToTriangleMap->m_map,
    &hkContainerHeapAllocator::s_alloc,
    v11,
    v10);
}

// File Line: 48
// RVA: 0xB9CC40
void __fastcall hkaiGeometryToEdgeGeometryConverter::_calculatePlane(
        hkaiGeometryToEdgeGeometryConverter *this,
        hkaiGeometryToEdgeGeometryConverter::Triangle *tri,
        hkVector4f *planeOut)
{
  hkVector4f *m_data; // r9
  __m128 m_quad; // xmm4
  __m128 v5; // xmm1
  __m128 v6; // xmm0
  __m128 v7; // xmm5
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm4

  m_data = this->m_vertices.m_data;
  m_quad = m_data[tri->m_vertexIndices[0]].m_quad;
  v5 = _mm_sub_ps(m_data[tri->m_vertexIndices[1]].m_quad, m_quad);
  v6 = _mm_sub_ps(m_data[tri->m_vertexIndices[2]].m_quad, m_quad);
  v7 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v5), _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v6));
  v8 = _mm_shuffle_ps(v7, v7, 201);
  v9 = _mm_mul_ps(v8, v8);
  if ( (float)((float)(_mm_shuffle_ps(v9, v9, 85).m128_f32[0] + _mm_shuffle_ps(v9, v9, 0).m128_f32[0])
             + _mm_shuffle_ps(v9, v9, 170).m128_f32[0]) >= _mm_shuffle_ps(
                                                             (__m128)LODWORD(FLOAT_9_9999994eN11),
                                                             (__m128)LODWORD(FLOAT_9_9999994eN11),
                                                             0).m128_f32[0] )
  {
    v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
    v12 = _mm_rsqrt_ps(v11);
    v10 = _mm_mul_ps(
            v8,
            _mm_andnot_ps(
              _mm_cmple_ps(v11, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
                _mm_mul_ps(*(__m128 *)_xmm, v12))));
  }
  else
  {
    v10 = transform.m_quad;
  }
  v13 = _mm_mul_ps(m_quad, v10);
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
char __fastcall hkaiGeometryToEdgeGeometryConverter::_hasEdge(
        hkaiGeometryToEdgeGeometryConverter::Triangle *tri,
        int a,
        int b)
{
  int v3; // r9d
  __int64 v4; // r10
  __int64 i; // rax

  v3 = 0;
  v4 = 8i64;
  for ( i = 0i64; *(int *)((char *)tri->m_vertexIndices + v4) != a || tri->m_vertexIndices[i] != b; ++i )
  {
    ++v3;
    v4 = i * 4;
    if ( v3 >= 3 )
      return 0;
  }
  return 1;
}

// File Line: 86
// RVA: 0xB9CD60
void __fastcall hkaiGeometryToEdgeGeometryConverter::_tryAddNeighbor(
        hkaiGeometryToEdgeGeometryConverter *this,
        hkaiGeometryToEdgeGeometryConverter::Triangle *startTri,
        int a,
        int b,
        hkVector4f *facePlane,
        hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *edgeToTriangleMap)
{
  __int64 v7; // rsi
  float v10; // xmm6_4
  __int64 v11; // r14
  int v12; // eax
  int v13; // r15d
  hkaiGeometryToEdgeGeometryConverter::Triangle *v14; // r9
  int v15; // r8d
  int *m_vertexIndices; // rax
  __int64 v17; // rcx
  hkVector4f *m_data; // rdx
  float v19; // xmm7_4
  __m128 m_quad; // xmm11
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
  bool v40; // cc
  float v41; // xmm0_4
  __m128 v42; // xmm2
  __m128 v43; // xmm2
  __m128 v44; // xmm0

  v7 = a;
  LODWORD(v10) = _mm_shuffle_ps((__m128)LODWORD(FLOAT_9_9999994eN11), (__m128)LODWORD(FLOAT_9_9999994eN11), 0).m128_u32[0];
  v11 = b;
  v12 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
          &edgeToTriangleMap->m_map,
          a | (unsigned __int64)((__int64)b << 32),
          0xFFFFFFFFFFFFFFFFui64);
  v13 = v12;
  if ( v12 >= 0 )
  {
    v14 = &this->m_triangles.m_data[v12];
    if ( v14->m_face < 0 && (v14->m_userData == startTri->m_userData || this->m_allowMergingDifferentUserData.m_bool) )
    {
      v15 = 0;
      m_vertexIndices = v14->m_vertexIndices;
      v17 = 0i64;
      while ( *m_vertexIndices == (_DWORD)v7 || *m_vertexIndices == b )
      {
        ++v17;
        ++v15;
        ++m_vertexIndices;
        if ( v17 >= 3 )
          return;
      }
      if ( v15 >= 0 )
      {
        m_data = this->m_vertices.m_data;
        v19 = _mm_shuffle_ps(
                (__m128)LODWORD(this->m_edgeAngularDistance),
                (__m128)LODWORD(this->m_edgeAngularDistance),
                0).m128_f32[0];
        if ( v19 <= 0.0 )
        {
          v42 = _mm_mul_ps(m_data[v14->m_vertexIndices[v15]].m_quad, facePlane->m_quad);
          v43 = _mm_shuffle_ps(v42, _mm_unpackhi_ps(v42, facePlane->m_quad), 196);
          v44 = _mm_add_ps(_mm_shuffle_ps(v43, v43, 78), v43);
          v40 = COERCE_FLOAT((unsigned int)(2 * COERCE_INT(_mm_shuffle_ps(v44, v44, 177).m128_f32[0] + v44.m128_f32[0])) >> 1) <= this->m_planeEpsilon;
        }
        else
        {
          m_quad = m_data[v14->m_vertexIndices[v15]].m_quad;
          v21 = _mm_sub_ps(m_data[v11].m_quad, m_data[v7].m_quad);
          v22 = _mm_mul_ps(v21, v21);
          if ( (float)((float)(_mm_shuffle_ps(v22, v22, 85).m128_f32[0] + _mm_shuffle_ps(v22, v22, 0).m128_f32[0])
                     + _mm_shuffle_ps(v22, v22, 170).m128_f32[0]) >= v10 )
          {
            v28 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                    _mm_shuffle_ps(v22, v22, 170));
            v29 = _mm_sub_ps(m_quad, m_data[v7].m_quad);
            v30 = _mm_rsqrt_ps(v28);
            v31 = _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_andnot_ps(
                        _mm_cmple_ps(v28, (__m128)0i64),
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
                    _mm_cmple_ps(v34, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v35, v34), v35)),
                        _mm_mul_ps(v35, *(__m128 *)_xmm)),
                      v34));
          }
          else
          {
            v23 = _mm_sub_ps(m_quad, m_data[v7].m_quad);
            v24 = _mm_mul_ps(v23, v23);
            v25 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                    _mm_shuffle_ps(v24, v24, 170));
            v26 = _mm_rsqrt_ps(v25);
            v27 = _mm_andnot_ps(
                    _mm_cmple_ps(v25, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                        _mm_mul_ps(*(__m128 *)_xmm, v26)),
                      v25));
          }
          v36 = _mm_mul_ps(facePlane->m_quad, m_quad);
          v37 = _mm_shuffle_ps(v36, _mm_unpackhi_ps(v36, facePlane->m_quad), 196);
          v38 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 78), v37);
          LODWORD(v39) = (unsigned int)(2 * COERCE_INT(_mm_shuffle_ps(v38, v38, 177).m128_f32[0] + v38.m128_f32[0])) >> 1;
          if ( v27.m128_f32[0] >= v19 )
          {
            v41 = _mm_rcp_ps(v27).m128_f32[0];
            v40 = (float)((float)((float)(2.0 - (float)(v27.m128_f32[0] * v41)) * v41) * (float)(v39 * v19)) <= this->m_planeEpsilon;
          }
          else
          {
            v40 = v39 <= this->m_planeEpsilon;
          }
        }
        if ( v40 )
        {
          v14->m_face = startTri->m_face;
          if ( this->m_faceTriangleIndices.m_size == (this->m_faceTriangleIndices.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_faceTriangleIndices, 4);
          this->m_faceTriangleIndices.m_data[this->m_faceTriangleIndices.m_size++] = v13;
        }
      }
    }
  }
}

// File Line: 207
// RVA: 0xB9D0D0
__int64 __fastcall hkaiGeometryToEdgeGeometryConverter::_findNeighboringFace(
        hkaiGeometryToEdgeGeometryConverter *this,
        int faceIndex,
        int a,
        int b,
        hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *edgeToTriangleMap)
{
  int v7; // eax
  __int64 result; // rax

  v7 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         &edgeToTriangleMap->m_map,
         a | (unsigned __int64)((__int64)b << 32),
         0xFFFFFFFFFFFFFFFFui64);
  if ( v7 < 0 )
    return 0i64;
  result = (unsigned int)this->m_triangles.m_data[v7].m_face;
  if ( faceIndex == (_DWORD)result )
    return 0xFFFFFFFFi64;
  return result;
}

// File Line: 227
// RVA: 0xB9D190
void __fastcall hkaiGeometryToEdgeGeometryConverter::_findCoplanarTriangleFaces(
        hkaiGeometryToEdgeGeometryConverter *this,
        hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *edgeToTriangleMap)
{
  __int64 m_size; // rbx
  hkArray<hkaiGeometryToEdgeGeometryConverter::TriangleArea,hkContainerHeapAllocator> *p_m_orderedTriangles; // rsi
  int v4; // eax
  int v7; // eax
  int v8; // r9d
  hkaiGeometryToEdgeGeometryConverter::Triangle *m_data; // rdx
  hkpTypedBroadPhaseHandlePair *v10; // r9
  hkaiGeometryToEdgeGeometryConverter::Triangle *v11; // r8
  int *m_vertexIndices; // rdx
  hkVector4f *v13; // rcx
  __m128 m_quad; // xmm0
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  hkpBroadPhaseHandle *v17; // rax
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm3
  __m128 v21; // xmm3
  __m128 v22; // xmm4
  __m128 v23; // xmm2
  __int64 v24; // rdx
  __int64 v25; // rcx
  hkaiGeometryToEdgeGeometryConverter::Triangle *v26; // rsi
  __int64 v27; // r12
  signed __int64 v28; // rbx
  int v29; // eax
  __int64 v30; // rcx
  int v31; // r13d
  int v32; // ebp
  __int64 v33; // rsi
  hkaiGeometryToEdgeGeometryConverter::Triangle *v34; // rbx
  int v35; // esi
  hkVector4f planeOut; // [rsp+30h] [rbp-68h] BYREF
  __int64 result; // [rsp+A0h] [rbp+8h] BYREF
  __int64 v38; // [rsp+B0h] [rbp+18h]

  m_size = this->m_triangles.m_size;
  p_m_orderedTriangles = &this->m_orderedTriangles;
  v4 = this->m_orderedTriangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < (int)m_size )
  {
    v7 = 2 * v4;
    v8 = this->m_triangles.m_size;
    if ( (int)m_size < v7 )
      v8 = v7;
    hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, p_m_orderedTriangles, v8, 16);
  }
  p_m_orderedTriangles->m_size = m_size;
  m_data = this->m_triangles.m_data;
  v10 = (hkpTypedBroadPhaseHandlePair *)p_m_orderedTriangles->m_data;
  v11 = &m_data[this->m_triangles.m_size];
  if ( m_data != v11 )
  {
    m_vertexIndices = m_data->m_vertexIndices;
    do
    {
      v13 = this->m_vertices.m_data;
      ++v10;
      m_quad = v13[*m_vertexIndices].m_quad;
      v15 = _mm_sub_ps(v13[m_vertexIndices[1]].m_quad, m_quad);
      v16 = v13[m_vertexIndices[2]].m_quad;
      v17 = (hkpBroadPhaseHandle *)(m_vertexIndices - 2);
      m_vertexIndices += 5;
      v18 = _mm_sub_ps(v16, m_quad);
      v19 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v18));
      v20 = _mm_shuffle_ps(v19, v19, 201);
      v21 = _mm_mul_ps(v20, v20);
      v22 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
              _mm_shuffle_ps(v21, v21, 170));
      v23 = _mm_rsqrt_ps(v22);
      LODWORD(v10[-1].m_b) = _mm_andnot_ps(
                               _mm_cmple_ps(v22, (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_mul_ps(
                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                                   _mm_mul_ps(*(__m128 *)_xmm, v23)),
                                 v22)).m128_u32[0];
      v10[-1].m_a = v17;
    }
    while ( m_vertexIndices - 2 != (int *)v11 );
  }
  if ( (int)m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkaiGeometryToEdgeGeometryConverter::TriangleArea,bool (*)(hkaiGeometryToEdgeGeometryConverter::TriangleArea const &,hkaiGeometryToEdgeGeometryConverter::TriangleArea const &)>(
      (hkpTypedBroadPhaseHandlePair *)p_m_orderedTriangles->m_data,
      0,
      m_size - 1,
      (bool (__fastcall *)(hkpTypedBroadPhaseHandlePair *, hkpTypedBroadPhaseHandlePair *))hkaiGeometryToEdgeGeometryConverter::_orderTriangles);
  v24 = m_size;
  v38 = m_size;
  if ( (int)m_size > 0 )
  {
    v25 = 0i64;
    result = 0i64;
    do
    {
      v26 = *(hkaiGeometryToEdgeGeometryConverter::Triangle **)((char *)&p_m_orderedTriangles->m_data->m_triangle + v25);
      if ( v26->m_face < 0 )
      {
        v27 = this->m_faceTriangleIndices.m_size;
        v28 = v26 - this->m_triangles.m_data;
        v26->m_face = this->m_numTrianglesPerFace.m_size;
        if ( this->m_faceTriangleIndices.m_size == (this->m_faceTriangleIndices.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_faceTriangleIndices, 4);
        this->m_faceTriangleIndices.m_data[this->m_faceTriangleIndices.m_size++] = v28;
        hkaiGeometryToEdgeGeometryConverter::_calculatePlane(this, v26, &planeOut);
        v29 = this->m_faceTriangleIndices.m_size;
        v30 = v27;
        do
        {
          v31 = v29;
          v32 = v27;
          if ( (int)v27 < v29 )
          {
            v33 = v30;
            do
            {
              v34 = &this->m_triangles.m_data[this->m_faceTriangleIndices.m_data[v33]];
              hkaiGeometryToEdgeGeometryConverter::_tryAddNeighbor(
                this,
                v34,
                v34->m_vertexIndices[0],
                v34->m_vertexIndices[1],
                &planeOut,
                edgeToTriangleMap);
              hkaiGeometryToEdgeGeometryConverter::_tryAddNeighbor(
                this,
                v34,
                v34->m_vertexIndices[1],
                v34->m_vertexIndices[2],
                &planeOut,
                edgeToTriangleMap);
              hkaiGeometryToEdgeGeometryConverter::_tryAddNeighbor(
                this,
                v34,
                v34->m_vertexIndices[2],
                v34->m_vertexIndices[0],
                &planeOut,
                edgeToTriangleMap);
              ++v32;
              ++v33;
            }
            while ( v32 < this->m_faceTriangleIndices.m_size );
            v30 = v27;
          }
          v29 = this->m_faceTriangleIndices.m_size;
        }
        while ( v29 != v31 );
        v35 = v29 - v27;
        if ( this->m_numTrianglesPerFace.m_size == (this->m_numTrianglesPerFace.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_numTrianglesPerFace, 4);
        v24 = v38;
        this->m_numTrianglesPerFace.m_data[this->m_numTrianglesPerFace.m_size++] = v35;
        v25 = result;
      }
      v25 += 16i64;
      --v24;
      p_m_orderedTriangles = &this->m_orderedTriangles;
      v38 = v24;
      result = v25;
    }
    while ( v24 );
  }
}

// File Line: 316
// RVA: 0xB9C320
hkResult *__fastcall hkaiGeometryToEdgeGeometryConverter::convertGeometryToEdgeGeometry(
        hkaiGeometryToEdgeGeometryConverter *this,
        hkResult *result,
        hkGeometry *mesh,
        hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char> faceFlags,
        hkaiEdgeGeometry *geomOut)
{
  hkaiEdgeGeometry *v5; // r13
  hkArray<hkaiGeometryToEdgeGeometryConverter::Triangle,hkContainerHeapAllocator> *p_m_triangles; // rsi
  __int64 m_size; // rdi
  int v11; // eax
  int v12; // eax
  int v13; // r9d
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r9
  hkaiGeometryToEdgeGeometryConverter::Triangle *v18; // rdx
  hkGeometry::Triangle *v19; // rcx
  int v20; // ecx
  hkVector4f *m_data; // rax
  int SizeInBytesFor; // eax
  IAmdDxExtQuadBufferStereo *v23; // rdx
  hkResultEnum v24; // ecx
  int v25; // eax
  int v26; // edi
  __int64 v27; // rsi
  hkaiGeometryToEdgeGeometryConverter::Triangle *v28; // rbx
  int v29; // r9d
  int v30; // eax
  int v31; // eax
  int v32; // r9d
  int v33; // eax
  int v34; // eax
  int v35; // r9d
  hkArray<int,hkContainerHeapAllocator> *p_m_faceTriangleIndices; // rdi
  int v37; // eax
  int v38; // eax
  __int64 v39; // r14
  __int64 v40; // rbx
  __int64 p_m_faces; // r15
  int v42; // eax
  int v43; // eax
  int v44; // r9d
  int v45; // r8d
  __int64 v46; // r9
  __int64 v47; // rdx
  hkaiGeometryToEdgeGeometryConverter *v48; // r10
  int v49; // r12d
  int v50; // ecx
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
  __int64 v61; // rsi
  hkaiGeometryToEdgeGeometryConverter::Triangle *v62; // r13
  __int64 v63; // rax
  int v64; // r14d
  int v65; // r15d
  hkaiEdgeGeometry::Edge *v66; // rcx
  bool v67; // zf
  __int64 v68; // r12
  int *v69; // rax
  __int64 v70; // rdi
  __int64 v71; // rcx
  hkResultEnum m_enum; // r12d
  __int64 v73; // r15
  __int64 v74; // r13
  __int64 v75; // rax
  unsigned int v76; // esi
  unsigned int v77; // r14d
  hkaiEdgeGeometry::Edge *v78; // rcx
  hkResult *v79; // rbx
  int v80; // r9d
  hkVector4f *v81; // rax
  __int64 v82; // rax
  hkVector4f *v83; // rcx
  __int64 v84; // rdx
  char *v85; // r8
  hkVector4f v86; // xmm0
  int sizeElem; // [rsp+20h] [rbp-91h]
  hkResult v88; // [rsp+30h] [rbp-81h] BYREF
  int v89; // [rsp+34h] [rbp-7Dh]
  hkResult v90; // [rsp+38h] [rbp-79h] BYREF
  hkResult v91; // [rsp+3Ch] [rbp-75h] BYREF
  int v92; // [rsp+40h] [rbp-71h]
  AMD_HD3D v93; // [rsp+48h] [rbp-69h] BYREF
  __int64 v94; // [rsp+68h] [rbp-49h]
  __int64 v95; // [rsp+70h] [rbp-41h]
  int v96; // [rsp+78h] [rbp-39h]
  int v97; // [rsp+7Ch] [rbp-35h] BYREF
  __int64 v98; // [rsp+80h] [rbp-31h]
  __int64 v99; // [rsp+88h] [rbp-29h]
  hkArray<int,hkContainerHeapAllocator> *v100; // [rsp+90h] [rbp-21h]
  __int64 v101; // [rsp+98h] [rbp-19h]
  hkArray<hkaiGeometryToEdgeGeometryConverter::Triangle,hkContainerHeapAllocator> *v102; // [rsp+A0h] [rbp-11h]
  hkArray<hkaiEdgeGeometry::Face,hkContainerHeapAllocator> *v103; // [rsp+A8h] [rbp-9h]
  __int64 v104; // [rsp+B0h] [rbp-1h]
  hkResult resulta; // [rsp+120h] [rbp+6Fh] BYREF
  char m_storage; // [rsp+128h] [rbp+77h]

  m_storage = faceFlags.m_storage;
  v5 = geomOut;
  hkaiEdgeGeometry::clear(geomOut);
  p_m_triangles = &this->m_triangles;
  this->m_triangles.m_size = 0;
  this->m_faceTriangleIndices.m_size = 0;
  this->m_numTrianglesPerFace.m_size = 0;
  this->m_vertices.m_size = 0;
  this->m_orderedTriangles.m_size = 0;
  m_size = mesh->m_triangles.m_size;
  v11 = this->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  v102 = &this->m_triangles;
  if ( v11 < (int)m_size )
  {
    v12 = 2 * v11;
    v13 = m_size;
    if ( (int)m_size < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &this->m_triangles, v13, 20);
  }
  this->m_triangles.m_size = m_size;
  if ( (this->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) != 0 && !p_m_triangles->m_data )
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  v15 = m_size;
  if ( (int)m_size > 0 )
  {
    v16 = 0i64;
    v17 = 0i64;
    do
    {
      v18 = &p_m_triangles->m_data[v17];
      v19 = &mesh->m_triangles.m_data[v16];
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
  v20 = mesh->m_vertices.m_size;
  m_data = mesh->m_vertices.m_data;
  this->m_vertices.m_size = v20;
  this->m_vertices.m_data = m_data;
  this->m_vertices.m_capacityAndFlags = v20 | 0x80000000;
  SizeInBytesFor = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getSizeInBytesFor(3 * this->m_triangles.m_size);
  if ( SizeInBytesFor )
  {
    LODWORD(v93.mExtension) = SizeInBytesFor;
    v23 = (IAmdDxExtQuadBufferStereo *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                         &hkContainerHeapAllocator::s_alloc,
                                         &v93.mExtension);
    SizeInBytesFor = (int)v93.mExtension;
  }
  else
  {
    v23 = 0i64;
  }
  v24 = 0x80000000;
  v93.mStereo = v23;
  if ( SizeInBytesFor )
    v24 = SizeInBytesFor;
  resulta.m_enum = v24;
  v25 = v24 & 0x3FFFFFFF;
  v89 = v24 & 0x3FFFFFFF;
  if ( (v24 & 0x3FFFFFFF) != 0 && !v23 )
  {
    result->m_enum = HK_FAILURE;
    if ( v24 >= HK_SUCCESS )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, 0i64, v25);
    return result;
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v93,
    v23,
    v25);
  v26 = 0;
  if ( this->m_triangles.m_size > 0 )
  {
    v27 = 0i64;
    do
    {
      v28 = &this->m_triangles.m_data[v27];
      hkaiGeometryToEdgeGeometryConverter::_addEdge(
        this,
        v28->m_vertexIndices[0],
        v28->m_vertexIndices[1],
        v26,
        (hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *)&v93);
      hkaiGeometryToEdgeGeometryConverter::_addEdge(
        this,
        v28->m_vertexIndices[1],
        v28->m_vertexIndices[2],
        v26,
        (hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *)&v93);
      hkaiGeometryToEdgeGeometryConverter::_addEdge(
        this,
        v28->m_vertexIndices[2],
        v28->m_vertexIndices[0],
        v26++,
        (hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *)&v93);
      ++v27;
    }
    while ( v26 < this->m_triangles.m_size );
    p_m_triangles = &this->m_triangles;
  }
  v29 = this->m_triangles.m_size;
  v30 = this->m_numTrianglesPerFace.m_capacityAndFlags & 0x3FFFFFFF;
  v99 = 4i64;
  if ( v30 < v29 )
  {
    v31 = 2 * v30;
    if ( v29 < v31 )
      v29 = v31;
    hkArrayUtil::_reserve(&v90, &hkContainerHeapAllocator::s_alloc, &this->m_numTrianglesPerFace, v29, 4);
  }
  v32 = this->m_triangles.m_size;
  v33 = this->m_orderedTriangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v33 < v32 )
  {
    v34 = 2 * v33;
    if ( v32 < v34 )
      v32 = v34;
    hkArrayUtil::_reserve(&v90, &hkContainerHeapAllocator::s_alloc, &this->m_orderedTriangles, v32, 16);
  }
  v35 = this->m_triangles.m_size;
  p_m_faceTriangleIndices = &this->m_faceTriangleIndices;
  v37 = this->m_faceTriangleIndices.m_capacityAndFlags & 0x3FFFFFFF;
  v100 = &this->m_faceTriangleIndices;
  if ( v37 < v35 )
  {
    v38 = 2 * v37;
    if ( v35 < v38 )
      v35 = v38;
    hkArrayUtil::_reserve(&v90, &hkContainerHeapAllocator::s_alloc, &this->m_faceTriangleIndices, v35, 4);
  }
  if ( (this->m_numTrianglesPerFace.m_capacityAndFlags & 0x3FFFFFFF) != 0 && !this->m_numTrianglesPerFace.m_data
    || (this->m_orderedTriangles.m_capacityAndFlags & 0x3FFFFFFF) != 0 && !this->m_orderedTriangles.m_data
    || (this->m_faceTriangleIndices.m_capacityAndFlags & 0x3FFFFFFF) != 0 && !p_m_faceTriangleIndices->m_data )
  {
    goto LABEL_50;
  }
  v39 = 4i64;
  if ( this->m_numTrianglesPerFace.m_size == (this->m_numTrianglesPerFace.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_numTrianglesPerFace, 4);
  this->m_numTrianglesPerFace.m_data[this->m_numTrianglesPerFace.m_size++] = 0;
  hkaiGeometryToEdgeGeometryConverter::_findCoplanarTriangleFaces(
    this,
    (hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *)&v93);
  v40 = this->m_numTrianglesPerFace.m_size;
  p_m_faces = (__int64)&v5->m_faces;
  v42 = v5->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
  v103 = &v5->m_faces;
  v98 = 12i64;
  if ( v42 >= (int)v40 )
    goto LABEL_52;
  v43 = 2 * v42;
  v44 = v40;
  if ( (int)v40 < v43 )
    v44 = v43;
  hkArrayUtil::_reserve(&v88, &hkContainerHeapAllocator::s_alloc, &v5->m_faces, v44, 12);
  if ( v88.m_enum == HK_SUCCESS )
  {
LABEL_52:
    v5->m_faces.m_size = v40;
LABEL_53:
    v45 = 0;
    v46 = v40;
    if ( (int)v40 > 0 )
    {
      v47 = 0i64;
      do
      {
        v47 += 12i64;
        *(_DWORD *)(v47 + *(_QWORD *)p_m_faces - 12) = 0;
        *(_DWORD *)(v47 + *(_QWORD *)p_m_faces - 8) = v45++;
        *(_BYTE *)(v47 + *(_QWORD *)p_m_faces - 4) = m_storage;
        --v46;
      }
      while ( v46 );
    }
    v48 = this;
    v49 = 1;
    v50 = 0;
    *(_BYTE *)(*(_QWORD *)p_m_faces + 8i64) = 0;
    v88.m_enum = HK_FAILURE;
    v92 = 0;
    if ( this->m_numTrianglesPerFace.m_size > 1 )
    {
      while ( 1 )
      {
        v51 = geomOut;
        v52 = *(int *)((char *)v48->m_numTrianglesPerFace.m_data + v39);
        v90.m_enum = (int)v52;
        if ( (int)v52 > 0 )
        {
          *(_DWORD *)(v98 + *(_QWORD *)p_m_faces) = p_m_triangles->m_data[p_m_faceTriangleIndices->m_data[v50]].m_userData;
          hkaiArrayUtil::reserveSmall<hkVector4f,hkContainerHeapAllocator>(
            (hkaiArrayUtil *)&v97,
            (hkResult *)&v51->m_edges,
            (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)(unsigned int)(v51->m_edges.m_size + 3 * v52),
            -1,
            sizeElem);
          if ( v97 == 1 )
          {
            v79 = result;
            result->m_enum = HK_FAILURE;
            goto LABEL_97;
          }
          v48 = this;
        }
        v53 = v51->m_edges.m_size;
        v54 = v92;
        v55 = v52;
        v95 = v52;
        v96 = v53;
        v104 = v92;
        if ( (int)v52 > 0 )
        {
          v56 = 4i64 * v92;
          v94 = v52;
          v101 = v56;
          do
          {
            v57 = p_m_faceTriangleIndices->m_data;
            v58 = 0i64;
            v59 = *(int *)((char *)v57 + v56);
            v60 = p_m_triangles->m_data;
            v61 = 3i64;
            v62 = &v60[v59];
            v63 = 8i64;
            do
            {
              v64 = *(int *)((char *)v62->m_vertexIndices + v63);
              v65 = v62->m_vertexIndices[v58];
              if ( hkaiGeometryToEdgeGeometryConverter::_findNeighboringFace(
                     v48,
                     v49,
                     v64,
                     v65,
                     (hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *)&v93) >= 0 )
              {
                if ( v51->m_edges.m_size == (v51->m_edges.m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v51->m_edges, 16);
                v66 = &v51->m_edges.m_data[v51->m_edges.m_size++];
                v51 = geomOut;
                v66->m_a = v64;
                v66->m_b = v65;
                v66->m_face = v49;
                v66->m_data = 0;
              }
              v48 = this;
              v63 = v58 * 4;
              ++v58;
              --v61;
            }
            while ( v61 );
            p_m_triangles = &this->m_triangles;
            p_m_faceTriangleIndices = &this->m_faceTriangleIndices;
            v56 = v101 + 4;
            v67 = v94-- == 1;
            v101 += 4i64;
          }
          while ( !v67 );
          v53 = v96;
          v54 = v104;
          v55 = v95;
          p_m_faceTriangleIndices = v100;
        }
        if ( v51->m_edges.m_size - v53 < 3 )
        {
          v51->m_edges.m_size = v53;
          if ( v55 > 0 )
          {
            v68 = 4 * v54;
            v94 = 4 * v54;
            do
            {
              v69 = p_m_faceTriangleIndices->m_data;
              v70 = 0i64;
              v71 = *(int *)((char *)v69 + v68);
              m_enum = v88.m_enum;
              v73 = 3i64;
              v74 = (__int64)&v102->m_data[v71];
              v75 = 8i64;
              do
              {
                v76 = *(_DWORD *)(v75 + v74 + 8);
                v77 = *(_DWORD *)(v74 + v70 + 8);
                if ( v51->m_edges.m_size == (v51->m_edges.m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v51->m_edges, 16);
                v78 = &v51->m_edges.m_data[v51->m_edges.m_size++];
                v75 = v70;
                v70 += 4i64;
                v78->m_a = v76;
                v78->m_b = v77;
                v78->m_face = m_enum;
                v78->m_data = 0;
                --v73;
              }
              while ( v73 );
              p_m_faceTriangleIndices = v100;
              v68 = v94 + 4;
              v67 = v95-- == 1;
              v94 += 4i64;
            }
            while ( !v67 );
            v49 = v88.m_enum;
          }
        }
        v48 = this;
        v50 = v90.m_enum + v92;
        v98 += 12i64;
        ++v49;
        v39 = v99 + 4;
        v88.m_enum = v49;
        v92 += v90.m_enum;
        v99 += 4i64;
        if ( v49 >= this->m_numTrianglesPerFace.m_size )
          break;
        p_m_faces = (__int64)v103;
        p_m_triangles = &this->m_triangles;
        p_m_faceTriangleIndices = &this->m_faceTriangleIndices;
      }
      v5 = geomOut;
    }
    v80 = v48->m_vertices.m_size;
    if ( (v5->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) >= v80 )
    {
      v91.m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(&v91, &hkContainerHeapAllocator::s_alloc, &v5->m_vertices, v80, 16);
      if ( v91.m_enum )
        goto LABEL_94;
      v48 = this;
    }
    if ( (v5->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) < v48->m_vertices.m_size )
    {
      if ( v5->m_vertices.m_capacityAndFlags >= 0 )
      {
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v5->m_vertices.m_data,
          16 * v5->m_vertices.m_capacityAndFlags);
        v48 = this;
      }
      v88.m_enum = 16 * v48->m_vertices.m_size;
      v81 = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v88);
      v48 = this;
      v5->m_vertices.m_data = v81;
      v5->m_vertices.m_capacityAndFlags = v88.m_enum / 16;
    }
    v82 = v48->m_vertices.m_size;
    v83 = v5->m_vertices.m_data;
    v5->m_vertices.m_size = v82;
    v84 = v82;
    if ( (int)v82 > 0 )
    {
      v85 = (char *)((char *)v48->m_vertices.m_data - (char *)v83);
      do
      {
        v86.m_quad = *(__m128 *)((char *)v83++ + (_QWORD)v85);
        v83[-1] = (hkVector4f)v86.m_quad;
        --v84;
      }
      while ( v84 );
    }
LABEL_94:
    v79 = result;
    result->m_enum = v91.m_enum == HK_FAILURE;
LABEL_97:
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v93,
      &hkContainerHeapAllocator::s_alloc);
    _(&v93);
    if ( resulta.m_enum >= HK_SUCCESS )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v93.mStereo, v89);
    return v79;
  }
  if ( v88.m_enum != HK_FAILURE )
    goto LABEL_53;
LABEL_50:
  result->m_enum = HK_FAILURE;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v93,
    &hkContainerHeapAllocator::s_alloc);
  _(&v93);
  if ( resulta.m_enum < HK_SUCCESS )
    return result;
  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v93.mStereo, v89);
  return result;
}


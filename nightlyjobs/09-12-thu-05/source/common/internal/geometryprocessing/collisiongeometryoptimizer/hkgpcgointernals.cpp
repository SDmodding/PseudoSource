// File Line: 27
// RVA: 0xCEA4E0
void __fastcall computeUnionOfSortedArray_int_hkgpCgoInternal::ArrayCollector_int___(
        hkArray<int,hkContainerHeapAllocator> *a,
        hkArray<int,hkContainerHeapAllocator> *b,
        hkgpCgoInternal::ArrayCollector<int> *collector)
{
  __int64 m_size; // r14
  int v4; // r12d
  __int64 v5; // r13
  hkArray<int,hkContainerHeapAllocator> *v7; // rax
  int v8; // ebp
  __int64 v9; // rdi
  __int64 v10; // rsi
  hkArray<int,hkContainerHeapAllocator> *m_items; // rbx
  int *v12; // rbp
  int v13; // ecx
  int *v14; // r14
  int m_capacityAndFlags; // eax
  int v16; // eax
  int *v17; // rdx
  int v18; // eax
  __int64 j; // rdi
  hkArray<int,hkContainerHeapAllocator> *v20; // rbx
  int *v21; // rsi
  __int64 k; // rdi
  hkArray<int,hkContainerHeapAllocator> *v23; // rbx
  int *v24; // rsi
  __int64 i; // [rsp+20h] [rbp-48h]
  hkArray<int,hkContainerHeapAllocator> *v27; // [rsp+78h] [rbp+10h]
  int v28; // [rsp+88h] [rbp+20h]

  v27 = b;
  m_size = b->m_size;
  v4 = 0;
  v5 = a->m_size;
  v7 = a;
  v8 = 0;
  v28 = 0;
  v9 = 0i64;
  v10 = 0i64;
  for ( i = m_size; v9 < v5; b = v27 )
  {
    if ( v10 >= m_size )
      break;
    m_items = collector->m_items;
    v12 = &v7->m_data[v9];
    v13 = b->m_data[v10];
    v14 = &b->m_data[v10];
    m_capacityAndFlags = collector->m_items->m_capacityAndFlags;
    if ( v13 <= *v12 )
    {
      if ( v13 >= *v12 )
      {
        if ( m_items->m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&collector->m_items->m_data, 4);
        ++v4;
        v17 = &m_items->m_data[m_items->m_size];
        v18 = *v12;
        ++v9;
      }
      else
      {
        if ( m_items->m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&collector->m_items->m_data, 4);
        v17 = &m_items->m_data[m_items->m_size];
        v18 = *v14;
      }
      *v17 = v18;
      ++m_items->m_size;
      v8 = v28 + 1;
      ++v10;
      ++v28;
    }
    else
    {
      if ( m_items->m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&collector->m_items->m_data, 4);
      ++v4;
      v16 = *v12;
      v8 = v28;
      m_items->m_data[m_items->m_size++] = v16;
      ++v9;
    }
    m_size = i;
    v7 = a;
  }
  for ( j = v4; j < v5; v7 = a )
  {
    v20 = collector->m_items;
    v21 = &v7->m_data[j];
    if ( collector->m_items->m_size == (collector->m_items->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&collector->m_items->m_data, 4);
    ++j;
    v20->m_data[v20->m_size++] = *v21;
  }
  for ( k = v8; k < m_size; v23->m_data[v23->m_size++] = *v24 )
  {
    v23 = collector->m_items;
    v24 = &v27->m_data[k];
    if ( collector->m_items->m_size == (collector->m_items->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&collector->m_items->m_data, 4);
    ++k;
  }
}

// File Line: 46
// RVA: 0xCEA160
void __fastcall computeUnionOfSortedArray_hkgpCgoInternal::HTriangle_(
        hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *a,
        hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *b,
        hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *output)
{
  int m_capacityAndFlags; // eax
  int v4; // r9d
  int v5; // eax
  int v9; // eax
  hkgpCgoInternal::ArrayCollector<hkgpCgoInternal::HTriangle> result; // [rsp+40h] [rbp+8h] BYREF

  m_capacityAndFlags = output->m_capacityAndFlags;
  output->m_size = 0;
  v4 = b->m_size + a->m_size;
  v5 = m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < v4 )
  {
    v9 = 2 * v5;
    if ( v4 < v9 )
      v4 = v9;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&output->m_data,
      v4,
      8);
  }
  result.m_items = output;
  computeUnionOfSortedArray_hkgpCgoInternal::HTriangle_hkgpCgoInternal::ArrayCollector_hkgpCgoInternal::HTriangle___(
    a,
    b,
    &result);
}

// File Line: 55
// RVA: 0xCE9DB0
void __fastcall computeNormalSafe(hkVector4f *a, hkVector4f *b, hkVector4f *c, hkVector4f *normal)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm5
  __m128 v7; // xmm5
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2

  v4 = _mm_sub_ps(c->m_quad, a->m_quad);
  v5 = _mm_sub_ps(b->m_quad, a->m_quad);
  v6 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), v5), _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v4));
  v7 = _mm_shuffle_ps(v6, v6, 201);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  normal->m_quad = _mm_mul_ps(
                     _mm_andnot_ps(
                       _mm_cmple_ps(v9, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                         _mm_mul_ps(*(__m128 *)_xmm, v10))),
                     v7);
}

// File Line: 64
// RVA: 0xCE9E40
void __fastcall computePlaneSafe(hkVector4f *a, hkVector4f *b, hkVector4f *c, bool invert, hkVector4f *plane)
{
  __m128 v5; // xmm1
  __m128 v6; // xmm7
  __m128 v7; // xmm7
  __m128 v8; // xmm7
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  __m128 v12; // xmm7
  __m128 v13; // xmm6
  __m128 v14; // xmm7

  v5 = _mm_sub_ps(b->m_quad, a->m_quad);
  v6 = _mm_sub_ps(c->m_quad, a->m_quad);
  v7 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v5), _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v6));
  v8 = _mm_shuffle_ps(v7, v7, 201);
  v9 = _mm_mul_ps(v8, v8);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_rsqrt_ps(v10);
  v12 = _mm_mul_ps(
          v8,
          _mm_andnot_ps(
            _mm_cmple_ps(v10, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)),
              _mm_mul_ps(*(__m128 *)_xmm, v11))));
  v13 = _mm_mul_ps(a->m_quad, v12);
  v14 = _mm_shuffle_ps(
          v12,
          _mm_unpackhi_ps(
            v12,
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                _mm_shuffle_ps(v13, v13, 170)))),
          196);
  *plane = (hkVector4f)v14;
  if ( invert )
    plane->m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v14);
}

// File Line: 73
// RVA: 0xCE9F30
float __fastcall computeTriangleQuality(hkVector4f *a, hkVector4f *b, hkVector4f *c)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm9
  __m128 v5; // xmm1
  __m128 v6; // xmm3
  __m128 v7; // xmm9
  __m128 v8; // xmm2
  __m128 v9; // xmm10
  __m128 v10; // xmm1
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm6
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  __m128 v20; // xmm4
  __m128 v21; // xmm5
  __m128 v22; // xmm3

  v3 = _mm_sub_ps(c->m_quad, a->m_quad);
  v4 = _mm_sub_ps(a->m_quad, b->m_quad);
  v5 = _mm_mul_ps(v3, v3);
  v6 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
  v7 = _mm_mul_ps(v4, v4);
  v8 = _mm_rsqrt_ps(v6);
  v9 = _mm_unpacklo_ps(
         _mm_andnot_ps(
           _mm_cmple_ps(v6, (__m128)0i64),
           _mm_mul_ps(
             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v6, v8), v8)), _mm_mul_ps(*(__m128 *)_xmm, v8)),
             v6)),
         aabbOut.m_quad);
  v10 = _mm_sub_ps(b->m_quad, c->m_quad);
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_rsqrt_ps(v12);
  v14 = _mm_andnot_ps(
          _mm_cmple_ps(v12, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v13), v13)),
              _mm_mul_ps(*(__m128 *)_xmm, v13)),
            v12));
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v16 = _mm_rsqrt_ps(v15);
  v17 = _mm_movelh_ps(
          _mm_unpacklo_ps(
            _mm_andnot_ps(
              _mm_cmple_ps(v15, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v16), v16)),
                  _mm_mul_ps(*(__m128 *)_xmm, v16)),
                v15)),
            v14),
          v9);
  v18 = _mm_shuffle_ps(v17, v17, 85);
  v19 = _mm_shuffle_ps(v17, v17, 0);
  v20 = _mm_shuffle_ps(v17, v17, 170);
  v21 = _mm_max_ps(v20, _mm_max_ps(v18, v19));
  v22 = _mm_rcp_ps(v21);
  return _mm_andnot_ps(_mm_cmpeq_ps((__m128)0i64, v21), _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v21)), v22)).m128_f32[0]
       * fmin(v20.m128_f32[0], fmin(v18.m128_f32[0], v19.m128_f32[0]));
}

// File Line: 84
// RVA: 0xCEA0E0
void __fastcall projectOnPlanes(hkArrayBase<hkVector4f> *planes, hkVector4f *x, hkVector4f *xOut)
{
  __int64 m_size; // rax
  __m128 m_quad; // xmm4
  hkVector4f *m_data; // rdx
  __m128 v6; // xmm3
  __m128 v7; // xmm2
  __m128 v8; // xmm2
  __m128 v9; // xmm1

  m_size = planes->m_size;
  m_quad = x->m_quad;
  if ( m_size > 0 )
  {
    m_data = planes->m_data;
    do
    {
      v6 = m_data->m_quad;
      ++m_data;
      v7 = _mm_mul_ps(v6, m_quad);
      v8 = _mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, v6), 196);
      v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 78), v8);
      m_quad = _mm_sub_ps(
                 m_quad,
                 _mm_mul_ps(_mm_min_ps(aabbOut.m_quad, _mm_add_ps(_mm_shuffle_ps(v9, v9, 177), v9)), v6));
      --m_size;
    }
    while ( m_size );
  }
  *xOut = (hkVector4f)m_quad;
}

// File Line: 100
// RVA: 0xCE50C0
char __fastcall hkgpCgoInternal::ICollapse::validTriangleSet(
        hkgpCgoInternal::ICollapse *this,
        hkArrayBase<hkgpIndexedMeshDefinitions::Triangle *> *triangles,
        hkgpIndexedMeshDefinitions::Vertex *from,
        hkgpIndexedMeshDefinitions::Vertex *to)
{
  int v6; // r14d
  __int64 v7; // rsi
  hkgpCgoInternal *m_instance; // rcx
  hkgpCgoInternal::EdgeInfo *EdgeInfo; // rax
  hkgpCgoInternal *v10; // rcx
  hkgpCgoInternal::EdgeInfo *v11; // rax
  hkgpCgoInternal *v12; // rcx
  hkgpCgoInternal::EdgeInfo *v13; // rax
  hkgpIndexedMeshDefinitions::Edge v15; // [rsp+20h] [rbp-78h]
  hkgpIndexedMeshDefinitions::Edge v16; // [rsp+30h] [rbp-68h]
  hkgpIndexedMeshDefinitions::Edge v17; // [rsp+40h] [rbp-58h]
  hkgpIndexedMeshDefinitions::Edge v18; // [rsp+50h] [rbp-48h] BYREF
  hkgpIndexedMeshDefinitions::Edge v19; // [rsp+60h] [rbp-38h] BYREF
  hkgpIndexedMeshDefinitions::Edge v20; // [rsp+70h] [rbp-28h] BYREF

  v6 = 0;
  if ( triangles->m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v15.m_index = 0;
      v15.m_triangle = triangles->m_data[v7];
      m_instance = this->m_instance;
      v18 = v15;
      EdgeInfo = hkgpCgoInternal::getEdgeInfo(m_instance, &v18);
      hkgpCgoInternal::invalidateEdgeInfo(this->m_instance, EdgeInfo);
      v16.m_index = 1;
      v16.m_triangle = triangles->m_data[v7];
      v10 = this->m_instance;
      v19 = v16;
      v11 = hkgpCgoInternal::getEdgeInfo(v10, &v19);
      hkgpCgoInternal::invalidateEdgeInfo(this->m_instance, v11);
      v17.m_index = 2;
      v17.m_triangle = triangles->m_data[v7];
      v12 = this->m_instance;
      v20 = v17;
      v13 = hkgpCgoInternal::getEdgeInfo(v12, &v20);
      hkgpCgoInternal::invalidateEdgeInfo(this->m_instance, v13);
      ++v6;
      ++v7;
    }
    while ( v6 < triangles->m_size );
  }
  return 1;
}

// File Line: 112
// RVA: 0xCE51F0
void __fastcall hkgpCgoInternal::ICollapse::removeTriangle(
        hkgpCgoInternal::ICollapse *this,
        hkgpIndexedMeshDefinitions::Triangle *triangle)
{
  hkgpCgoInternal::VertexInfo *m_vertex; // rbx
  int m_index; // edi
  hkgpIndexedMeshDefinitions::Vertex **m_vertices; // r15
  int i; // ebp
  hkgpCgoInternal *m_instance; // rcx
  hkgpCgoInternal::EdgeInfo *EdgeInfo; // rdi
  unsigned __int64 v10; // rdx
  hkgpCgoInternal *v11; // rcx
  hkgpIndexedMeshDefinitions::Triangle *v12; // rax
  int v13; // edx
  __int64 v14; // rcx
  hkgpCgoInternal::VertexInfo *v15; // r10
  __int64 m_size; // r9
  hkgpIndexedMeshDefinitions::Triangle **p_m_triangle; // rax
  int v18; // r9d
  __int64 v19; // rax
  int v20; // r9d
  __int64 v21; // rdx
  __int64 v22; // rcx
  hkgpIndexedMeshDefinitions::Edge v23; // [rsp+20h] [rbp-78h]
  hkgpIndexedMeshDefinitions::Edge v24; // [rsp+30h] [rbp-68h]
  hkgpIndexedMeshDefinitions::Edge v25; // [rsp+40h] [rbp-58h] BYREF
  hkgpIndexedMeshDefinitions::Edge v26; // [rsp+50h] [rbp-48h] BYREF
  hkgpIndexedMeshDefinitions::Edge v27; // [rsp+60h] [rbp-38h] BYREF

  m_vertex = this->m_vertex;
  if ( m_vertex )
  {
    m_index = triangle->m_index;
    if ( m_vertex->m_cluster.m_size == (m_vertex->m_cluster.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_vertex->m_cluster.m_data, 4);
    m_vertex->m_cluster.m_data[m_vertex->m_cluster.m_size++] = m_index;
  }
  m_vertices = triangle->m_vertices;
  this->m_instance->m_triangles.m_data[(__int64)SLODWORD(triangle->m_index)].m_removed = 1;
  for ( i = 0; i < 3; ++i )
  {
    m_instance = this->m_instance;
    v23.m_triangle = triangle;
    v23.m_index = i;
    v25 = v23;
    EdgeInfo = hkgpCgoInternal::getEdgeInfo(m_instance, &v25);
    hkgpCgoInternal::invalidateEdgeInfo(this->m_instance, EdgeInfo);
    if ( (char *)EdgeInfo->m_edge.m_triangle + EdgeInfo->m_edge.m_index == (char *)triangle + (unsigned int)i )
    {
      v10 = triangle->m_links[i];
      v11 = this->m_instance;
      if ( (v10 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
      {
        v24.m_triangle = (hkgpIndexedMeshDefinitions::Triangle *)(v10 & 0xFFFFFFFFFFFFFFFCui64);
        v24.m_index = v10 & 3;
        v26 = v24;
        hkgpCgoInternal::setEdgeInfo(v11, &v26, EdgeInfo);
      }
      else
      {
        v27 = v23;
        hkgpCgoInternal::setEdgeInfo(v11, &v27, 0i64);
        hkgpCgoInternal::removeEdgeInfoFromInvalidQueue(this->m_instance, EdgeInfo);
        if ( (`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::`local static guard & 1) != 0 )
        {
          v12 = (hkgpIndexedMeshDefinitions::Triangle *)`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e;
        }
        else
        {
          DWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e) = 0;
          `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::`local static guard |= 1u;
          v12 = 0i64;
          *(_QWORD *)&`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e = 0i64;
        }
        EdgeInfo->m_edge.m_triangle = v12;
        *(_QWORD *)&EdgeInfo->m_edge.m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e
                                               + 1);
      }
    }
    v13 = 0;
    v14 = 0i64;
    v15 = &this->m_instance->m_vertices.m_data[(__int64)SLODWORD((*m_vertices)->m_index)];
    m_size = v15->m_ring.m_size;
    if ( (int)m_size > 0 )
    {
      p_m_triangle = &v15->m_ring.m_data->m_triangle;
      while ( *p_m_triangle != triangle )
      {
        ++v14;
        ++v13;
        ++p_m_triangle;
        if ( v14 >= m_size )
          goto LABEL_22;
      }
      if ( v14 != -1 )
      {
        v18 = m_size - 1;
        v15->m_ring.m_size = v18;
        v19 = (__int64)&v15->m_ring.m_data[v14];
        v20 = 8 * (v18 - v13);
        if ( v20 > 0 )
        {
          v21 = ((unsigned int)(v20 - 1) >> 3) + 1;
          do
          {
            v22 = *(_QWORD *)(v19 + 8);
            v19 += 8i64;
            *(_QWORD *)(v19 - 8) = v22;
            --v21;
          }
          while ( v21 );
        }
      }
    }
LABEL_22:
    ++m_vertices;
  }
}

// File Line: 150
// RVA: 0xCE4F10
void __fastcall hkgpCgoInternal::ICollapse::bind(
        hkgpCgoInternal::ICollapse *this,
        hkgpIndexedMeshDefinitions::Edge *e0,
        hkgpIndexedMeshDefinitions::Edge *e1)
{
  hkgpCgoInternal::TriangleInfo *m_data; // r9
  __int64 v7; // rcx
  hkgpCgoInternal::TriangleInfo *v8; // rdx
  hkgpCgoInternal *m_instance; // rcx
  hkgpCgoInternal::EdgeInfo *EdgeInfo; // rax
  hkgpCgoInternal *v11; // rcx
  hkgpCgoInternal::EdgeInfo *v12; // rbp
  hkgpCgoInternal::EdgeInfo *v13; // rax
  hkgpCgoInternal::EdgeInfo *v14; // rbx
  hkgpCgoInternal *v15; // rcx
  hkgpIndexedMeshDefinitions::Edge v16[2]; // [rsp+20h] [rbp-28h] BYREF

  m_data = this->m_instance->m_triangles.m_data;
  v7 = (__int64)&m_data[(__int64)SLODWORD(e0->m_triangle->m_index)] + 4 * (int)e0->m_index;
  v8 = &m_data[(__int64)SLODWORD(e1->m_triangle->m_index)];
  if ( *(int *)(v7 + 40) >= 0 || v8->m_planes[e1->m_index] >= 0 )
  {
    *(_DWORD *)(v7 + 40) = -1;
    v8->m_planes[e1->m_index] = -1;
    this->m_instance->m_vertices.m_data[(__int64)SLODWORD(e0->m_triangle->m_vertices[e0->m_index]->m_index)].m_planes.m_size = 0;
    this->m_instance->m_vertices.m_data[(__int64)SLODWORD(e0->m_triangle->m_vertices[(9i64 >> (2
                                                                                             * (unsigned __int8)e0->m_index)) & 3]->m_index)].m_planes.m_size = 0;
  }
  m_instance = this->m_instance;
  v16[0] = *e0;
  EdgeInfo = hkgpCgoInternal::getEdgeInfo(m_instance, v16);
  v11 = this->m_instance;
  v12 = EdgeInfo;
  v16[0] = *e1;
  v13 = hkgpCgoInternal::getEdgeInfo(v11, v16);
  v14 = v13;
  if ( v12 )
  {
    if ( v13 )
    {
      hkgpCgoInternal::removeEdgeInfoFromInvalidQueue(this->m_instance, v13);
      if ( (`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::`local static guard & 1) != 0 )
      {
        v14->m_edge.m_triangle = (hkgpIndexedMeshDefinitions::Triangle *)`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e;
      }
      else
      {
        DWORD2(`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e) = 0;
        *(_QWORD *)&`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e = 0i64;
        `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::`local static guard |= 1u;
        v14->m_edge.m_triangle = 0i64;
      }
      *(_QWORD *)&v14->m_edge.m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e
                                        + 1);
    }
  }
  else if ( v13 )
  {
    v12 = v13;
    e0->m_triangle = e1->m_triangle;
    *(_QWORD *)&e0->m_index = *(_QWORD *)&e1->m_index;
  }
  v15 = this->m_instance;
  v16[0] = *e0;
  hkgpCgoInternal::setEdgeInfo(v15, v16, v12);
}

// File Line: 186
// RVA: 0xCE5430
void __fastcall hkgpCgoInternal::reset(hkgpCgoInternal *this)
{
  hkgpCgoInternal::ICustomMetric *m_cstMetric; // rcx
  hkBaseObjectVtbl *vfptr; // rax
  int v4; // ebx
  hkgpCgoInternal::VertexInfo *v5; // rdi

  m_cstMetric = this->m_cstMetric;
  if ( m_cstMetric )
    m_cstMetric->vfptr->onReset(m_cstMetric, this);
  vfptr = this->m_topology.vfptr;
  this->m_geometry = 0i64;
  vfptr[1].__first_virtual_table_function__(&this->m_topology);
  v4 = this->m_vertices.m_size - 1;
  if ( v4 >= 0 )
  {
    v5 = &this->m_vertices.m_data[(__int64)v4];
    do
    {
      hkgpCgoInternal::VertexInfo::~VertexInfo(v5--);
      --v4;
    }
    while ( v4 >= 0 );
  }
  this->m_vertices.m_size = 0;
  this->m_triangles.m_size = 0;
  this->m_invalidEdges.m_size = 0;
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::clear(&this->m_edgesTree, 0);
  this->m_edgesStorage.m_size = 0;
}

// File Line: 200
// RVA: 0xCE54E0
void __fastcall hkgpCgoInternal::bake(hkgpCgoInternal *this)
{
  hkgpCgoInternal *v1; // rdi
  hkgpCgoInternal::ICustomMetric *m_cstMetric; // rcx
  hkGeometry *m_geometry; // rax
  hkGeometry *v4; // r8
  hkGeometry *v5; // rbx
  int m_capacityAndFlags; // r8d
  hkGeometry *v7; // rbx
  int v8; // r8d
  hkGeometry *v9; // r8
  int v10; // eax
  int m_numUsed; // r9d
  const void **p_m_data; // r8
  int v13; // eax
  int v14; // eax
  hkgpIndexedMeshDefinitions::Triangle *m_used; // rbx
  hkgpCgoInternal **v16; // rax
  hkGeometry *v17; // rdi
  int m_size; // eax
  hkgpIndexedMeshDefinitions::Vertex **m_vertices; // r12
  __int64 v20; // rbx
  hkgpCgoInternal *v21; // rcx
  __int64 i; // rdi
  unsigned __int64 m_index_low; // r13
  unsigned __int64 v24; // r14
  __int64 v25; // rax
  __int64 v26; // rsi
  hkVector4f *v27; // r15
  hkgpCgoInternal *v28; // rdx
  float v29; // ecx
  int v30; // eax
  hkgpCgoInternal **v31; // rax
  int sizeElem[2]; // [rsp+20h] [rbp-9h]
  float v33; // [rsp+28h] [rbp-1h]
  hkArrayBase<hkVector4f> v34; // [rsp+30h] [rbp+7h] BYREF
  AMD_HD3D v35; // [rsp+40h] [rbp+17h] BYREF
  hkgpCgoInternal *vars0; // [rsp+90h] [rbp+67h]
  float *retaddr; // [rsp+98h] [rbp+6Fh] BYREF
  hkgpCgoInternal *v38; // [rsp+A0h] [rbp+77h] BYREF

  v38 = this;
  v1 = this;
  m_cstMetric = this->m_cstMetric;
  if ( m_cstMetric )
    m_cstMetric->vfptr->onBake(m_cstMetric);
  m_geometry = v1->m_geometry;
  v35.mHeight = -1;
  *(_QWORD *)&v35.mEnableStereo = 0i64;
  v35.mWidth = 0;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v35,
    &hkContainerHeapAllocator::s_alloc,
    m_geometry->m_vertices.m_size);
  v4 = v1->m_geometry;
  v34.m_data = 0i64;
  v34.m_size = 0;
  v34.m_capacityAndFlags = 0x80000000;
  hkArrayBase<hkVector4f>::_append(
    &v34,
    &hkContainerHeapAllocator::s_alloc,
    v4->m_vertices.m_data,
    v4->m_vertices.m_size);
  v5 = v1->m_geometry;
  m_capacityAndFlags = v5->m_vertices.m_capacityAndFlags;
  v5->m_vertices.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v5->m_vertices.m_data,
      16 * m_capacityAndFlags);
  v5->m_vertices.m_data = 0i64;
  v5->m_vertices.m_capacityAndFlags = 0x80000000;
  v7 = v1->m_geometry;
  v8 = v7->m_triangles.m_capacityAndFlags;
  v7->m_triangles.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v7->m_triangles.m_data,
      16 * v8);
  v7->m_triangles.m_data = 0i64;
  v7->m_triangles.m_capacityAndFlags = 0x80000000;
  v9 = v1->m_geometry;
  v10 = v9->m_triangles.m_capacityAndFlags;
  m_numUsed = v1->m_topology.m_triangles.m_numUsed;
  p_m_data = (const void **)&v9->m_triangles.m_data;
  v13 = v10 & 0x3FFFFFFF;
  if ( v13 < m_numUsed )
  {
    v14 = 2 * v13;
    sizeElem[0] = 16;
    if ( m_numUsed < v14 )
      m_numUsed = v14;
    hkArrayUtil::_reserve((hkResult *)&retaddr, &hkContainerHeapAllocator::s_alloc, p_m_data, m_numUsed, sizeElem[0]);
  }
  m_used = v1->m_topology.m_triangles.m_used;
  v16 = &v38;
  retaddr = (float *)m_used;
  if ( !m_used )
    v16 = 0i64;
  if ( v16 )
  {
    do
    {
      v17 = v1->m_geometry;
      if ( v17->m_triangles.m_size == (v17->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v17->m_triangles.m_data, 16);
      m_size = v17->m_triangles.m_size;
      m_vertices = m_used->m_vertices;
      v20 = (__int64)vars0;
      *(_QWORD *)sizeElem = 0i64;
      v33 = 0.0;
      v21 = (hkgpCgoInternal *)&v17->m_triangles.m_data[m_size];
      v17->m_triangles.m_size = m_size + 1;
      v38 = v21;
      for ( i = 0i64; i < 3; ++i )
      {
        m_index_low = SLODWORD((*m_vertices)->m_index);
        LODWORD(v24) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                         (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v35,
                         m_index_low,
                         0xFFFFFFFFFFFFFFFFui64);
        if ( (v24 & 0x80000000) != 0i64 )
        {
          v25 = *(_QWORD *)(v20 + 80);
          v24 = *(int *)(v25 + 24);
          v26 = v25 + 16;
          v27 = &v34.m_data[m_index_low];
          if ( *(_DWORD *)(v25 + 24) == (*(_DWORD *)(v25 + 28) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)v26, 16);
          *(hkVector4f *)(*(_QWORD *)v26 + 16i64 * (int)(*(_DWORD *)(v26 + 8))++) = (hkVector4f)v27->m_quad;
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v35,
            &hkContainerHeapAllocator::s_alloc,
            m_index_low,
            v24);
        }
        sizeElem[i] = v24;
        ++m_vertices;
      }
      v28 = v38;
      v29 = retaddr[19];
      v1 = vars0;
      v38->m_config.m_semantic = sizeElem[0];
      v30 = sizeElem[1];
      v28->m_config.m_maxShrink = v29;
      v28->m_config.m_combinator = v30;
      v28->m_config.m_maxDistance = v33;
      m_used = *(hkgpIndexedMeshDefinitions::Triangle **)retaddr;
      v31 = &v38;
      retaddr = *(float **)retaddr;
      if ( !retaddr )
        v31 = 0i64;
    }
    while ( v31 );
  }
  hkgpCgoInternal::load(v1, v1->m_geometry);
  v34.m_size = 0;
  if ( v34.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v34.m_data,
      16 * v34.m_capacityAndFlags);
  v34.m_data = 0i64;
  v34.m_capacityAndFlags = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v35,
    &hkContainerHeapAllocator::s_alloc);
  _(&v35);
}

// File Line: 232
// RVA: 0xCE5820
void __fastcall hkgpCgoInternal::load(hkgpCgoInternal *this, hkGeometry *geometry)
{
  hkgpCgoInternal::ICustomMetric *m_cstMetric; // rcx
  __m128 v5; // xmm9
  __m128i si128; // xmm6
  __m128 v7; // xmm2
  __m128i v8; // xmm8
  __m128i v9; // xmm6
  __m128 v10; // xmm4
  __m128 v11; // xmm5
  __m128 v12; // xmm4
  __m128 v13; // xmm2
  float v14; // xmm13_4
  float m_weldDistance; // xmm1_4
  hkArray<hkgpCgoInternal::VertexInfo,hkContainerHeapAllocator> *p_m_vertices; // r14
  __int64 m_size; // r15
  int v18; // eax
  int v19; // eax
  int v20; // r9d
  int v21; // ebx
  hkgpCgoInternal::VertexInfo *v22; // rdi
  __int64 v23; // r13
  int v24; // eax
  __int64 v25; // rdx
  int *p_m_capacityAndFlags; // rax
  hkArray<hkgpCgoInternal::TriangleInfo,hkContainerHeapAllocator> *p_m_triangles; // r12
  int v28; // ebx
  int v29; // eax
  int v30; // eax
  int v31; // r9d
  int v32; // r15d
  __int64 v33; // rbx
  hkgpCgoInternal::VertexInfo *m_data; // rdi
  int m_capacityAndFlags; // r8d
  hkgpCgoInternal::VertexInfo *v36; // rdi
  int v37; // r8d
  int v38; // edx
  __int64 v39; // rcx
  hkgpIndexedMeshDefinitions::Vertex *m_used; // rbx
  int *v41; // rax
  int m_numRefs; // r9d
  __int64 p_m_ring; // r8
  int v44; // eax
  int v45; // eax
  int *v46; // rax
  int v47; // r8d
  hkgpIndexedMeshDefinitions::Triangle *m_next; // rbx
  hkgpIndexedMesh::EdgeBarrier *v49; // rax
  int v50; // r15d
  hkGeometry *m_geometry; // r10
  hkVector4f *v52; // r8
  __int64 m_index_low; // rdx
  hkgpIndexedMeshDefinitions::Vertex *v54; // rax
  __int64 v55; // r9
  __int64 v56; // rdi
  __int64 v57; // rcx
  __m128 m_quad; // xmm6
  __m128 *p_m_quad; // rdi
  __m128 v60; // xmm7
  __m128 v61; // xmm8
  int m_material; // r11d
  hkgpCgo::Tracker *m_tracker; // rcx
  __m128 v64; // xmm8
  __m128 v65; // xmm7
  bool v66; // al
  __m128 v67; // xmm5
  __m128 v68; // xmm5
  __m128 v69; // xmm1
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  __m128 v72; // xmm5
  __m128 v73; // xmm6
  __m128 v74; // xmm5
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v75; // r15
  __int64 m_triangle_low; // r9
  hkgpCgoInternal::VertexInfo *v77; // r8
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *v78; // rdi
  hkgpIndexedMeshDefinitions::Triangle **p_m_triangle; // rdx
  hkgpIndexedMesh::EdgeBarrier *v80; // rax
  hkgpIndexedMeshDefinitions::Triangle *v81; // rdx
  hkgpIndexedMeshDefinitions::Triangle *m_triangle; // rbx
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v83; // rax
  signed int m_index; // r13d
  unsigned __int64 v85; // r9
  __int64 v86; // r15
  __m128 v87; // xmm1
  hkVector4f *v88; // rdx
  __m128 v89; // xmm6
  __m128 v90; // xmm0
  __m128 v91; // xmm7
  __m128 v92; // xmm7
  __m128 v93; // xmm1
  __m128 v94; // xmm3
  __m128 v95; // xmm2
  __m128 v96; // xmm7
  __m128 v97; // xmm2
  __m128 v98; // xmm7
  int vfptr; // edx
  hkgpCgoInternal::TriangleInfo *v100; // rcx
  int v101; // eax
  __int64 v102; // rdi
  __int64 v103; // rdi
  hkVector4f *v104; // r8
  __m128 v105; // xmm3
  hkgpIndexedMeshDefinitions::Vertex *v106; // rax
  __m128 v107; // xmm2
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v108; // rax
  int v109; // r9d
  int v110; // ebx
  hkgpIndexedMeshDefinitions::Triangle *v111; // rdx
  hkgpIndexedMeshDefinitions::Triangle *v112; // rdi
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v113; // rax
  hkgpIndexedMeshDefinitions::Triangle **v114; // rcx
  hkgpIndexedMeshDefinitions::Triangle *v115; // rax
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v116; // rax
  int v117; // r11d
  __int64 v118; // r10
  char *v119; // r8
  unsigned int v120; // ecx
  unsigned int v121; // edx
  bool v122; // sf
  unsigned int v123; // ecx
  unsigned int m_x; // eax
  unsigned int v125; // eax
  __int64 v126; // rcx
  __int64 v127; // rdx
  char *v128; // r9
  int v129; // edx
  int v130; // eax
  int v131; // edi
  int v132; // eax
  __int64 v133; // rcx
  __int64 v134; // r8
  hkgpCgoInternal::Action *p_m_action; // rcx
  hkArray<hkgpCgoInternal::EdgeInfo *,hkContainerHeapAllocator> *p_m_invalidEdges; // r15
  int v137; // ebx
  int v138; // eax
  int v139; // eax
  int v140; // ebx
  __int64 v141; // rdi
  __int64 v142; // r12
  hkgpCgoInternal::EdgeInfo *v143; // r8
  char *v144; // rcx
  __int64 v145; // rax
  hkArray<unsigned int,hkContainerHeapAllocator> m_edge; // xmm0
  int v147; // edi
  __int64 v148; // rbx
  int v149; // r8d
  int v150; // r8d
  int v151; // ebx
  unsigned int v152; // edx
  __m128 v153; // xmm6
  int v154; // eax
  _OWORD *v155; // rcx
  __int64 v156; // rdx
  hkgpIndexedMeshDefinitions::Triangle *v157; // rax
  hkgpIndexedMesh::EdgeBarrier *v158; // rcx
  hkVector4f *v159; // r10
  __m128 v160; // xmm0
  __m128 *v161; // rcx
  __m128 v162; // xmm1
  hkgpIndexedMesh::EdgeBarrier *v163; // rcx
  int v164; // edi
  hkArray<hkgpCgoInternal::Set,hkContainerHeapAllocator> *p_m_sets; // rbx
  int v166; // eax
  int v167; // eax
  int v168; // r9d
  bool v169; // cc
  int v170; // edx
  __int64 v171; // r9
  __int64 v172; // r8
  __m128 v173; // xmm1
  __m128 v174; // xmm1
  __m128 v175; // xmm4
  __m128 v176; // xmm2
  int v177; // r8d
  int v178; // r8d
  int v179; // r9d
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator v180; // [rsp+30h] [rbp-C8h] BYREF
  char *array; // [rsp+40h] [rbp-B8h] BYREF
  int v182; // [rsp+48h] [rbp-B0h]
  int v183; // [rsp+4Ch] [rbp-ACh]
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > v184; // [rsp+50h] [rbp-A8h] BYREF
  hkMatrix3f v185; // [rsp+70h] [rbp-88h] BYREF
  hkgpIndexedMesh::EdgeBarrier retaddr; // [rsp+158h] [rbp+60h] BYREF
  int v187; // [rsp+160h] [rbp+68h] BYREF

  hkgpCgoInternal::reset(this);
  m_cstMetric = this->m_cstMetric;
  v5 = _mm_add_ps((__m128)LODWORD(this->m_config.m_maxAngle), *(__m128 *)_xmm);
  si128 = _mm_load_si128((const __m128i *)_xmm);
  v7 = _mm_andnot_ps(*(__m128 *)_xmm, v5);
  v8 = _mm_add_epi32(si128, si128);
  v9 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v7, *(__m128 *)_xmm)), si128));
  v10 = _mm_cvtepi32_ps(v9);
  v11 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v9, v8), (__m128i)0i64);
  v12 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v10, *(__m128 *)DP1_0), v7), _mm_mul_ps(v10, *(__m128 *)DP2)),
          _mm_mul_ps(v10, *(__m128 *)DP3));
  v13 = _mm_mul_ps(v12, v12);
  LODWORD(retaddr.vfptr) = (_mm_andnot_ps(
                              v11,
                              _mm_add_ps(
                                _mm_sub_ps(
                                  _mm_mul_ps(
                                    _mm_mul_ps(
                                      _mm_add_ps(
                                        _mm_mul_ps(
                                          _mm_add_ps(_mm_mul_ps(v13, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1),
                                          v13),
                                        *(__m128 *)cosCoeff2_0),
                                      v13),
                                    v13),
                                  _mm_mul_ps(v13, *(__m128 *)_xmm)),
                                *(__m128 *)_xmm)).m128_u32[0] | COERCE_UNSIGNED_INT(
                                                                  (float)((float)((float)((float)((float)((float)(v13.m128_f32[0] * -0.00019515296) + 0.0083321612)
                                                                                                * v13.m128_f32[0])
                                                                                        + -0.16666655)
                                                                                * v13.m128_f32[0])
                                                                        * v12.m128_f32[0])
                                                                + v12.m128_f32[0]) & v11.m128_i32[0]) ^ (_mm_and_si128(_mm_add_epi32(v8, v8), v9).m128i_u32[0] << 29) ^ v5.m128_i32[0] & _xmm[0];
  LODWORD(v14) = _mm_shuffle_ps((__m128)LODWORD(retaddr.vfptr), (__m128)LODWORD(retaddr.vfptr), 0).m128_u32[0];
  if ( m_cstMetric )
    m_cstMetric->vfptr->onLoad(m_cstMetric, geometry);
  m_weldDistance = this->m_config.m_weldDistance;
  if ( m_weldDistance >= 0.0 )
    hkGeometryUtils::weldVertices(geometry, m_weldDistance);
  this->m_geometry = geometry;
  hkgpIndexedMesh::appendFromGeometry(&this->m_topology, geometry);
  p_m_vertices = &this->m_vertices;
  m_size = this->m_geometry->m_vertices.m_size;
  v18 = this->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v18 < (int)m_size )
  {
    v19 = 2 * v18;
    v20 = this->m_geometry->m_vertices.m_size;
    if ( (int)m_size < v19 )
      v20 = v19;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_vertices.m_data,
      v20,
      64);
  }
  v21 = this->m_vertices.m_size - m_size - 1;
  if ( v21 >= 0 )
  {
    v22 = &p_m_vertices->m_data[m_size + v21];
    do
    {
      hkgpCgoInternal::VertexInfo::~VertexInfo(v22--);
      --v21;
    }
    while ( v21 >= 0 );
  }
  v23 = 0i64;
  v24 = m_size - this->m_vertices.m_size;
  v25 = v24;
  if ( v24 > 0 )
  {
    p_m_capacityAndFlags = &this->m_vertices.m_data[(__int64)this->m_vertices.m_size].m_ring.m_capacityAndFlags;
    do
    {
      if ( p_m_capacityAndFlags != (int *)28 )
      {
        *(_QWORD *)(p_m_capacityAndFlags - 7) = 0i64;
        *(p_m_capacityAndFlags - 5) = 0;
        *(p_m_capacityAndFlags - 4) = 0x80000000;
        *(_QWORD *)(p_m_capacityAndFlags - 3) = 0i64;
        *(p_m_capacityAndFlags - 1) = 0;
        *p_m_capacityAndFlags = 0x80000000;
        *(_QWORD *)(p_m_capacityAndFlags + 1) = 0i64;
        p_m_capacityAndFlags[3] = 0;
        p_m_capacityAndFlags[4] = 0x80000000;
      }
      p_m_capacityAndFlags += 16;
      --v25;
    }
    while ( v25 );
  }
  this->m_vertices.m_size = m_size;
  p_m_triangles = &this->m_triangles;
  v28 = this->m_geometry->m_triangles.m_size;
  v29 = this->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v29 < v28 )
  {
    v30 = 2 * v29;
    v31 = this->m_geometry->m_triangles.m_size;
    if ( v28 < v30 )
      v31 = v30;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_triangles.m_data,
      v31,
      64);
  }
  this->m_triangles.m_size = v28;
  v32 = 0;
  if ( this->m_vertices.m_size > 0 )
  {
    v33 = 0i64;
    do
    {
      p_m_vertices->m_data[v33].m_isFixed = 0;
      p_m_vertices->m_data[v33].m_isNaked = 0;
      p_m_vertices->m_data[v33].m_material = 0;
      p_m_vertices->m_data[v33].m_error = 0.0;
      m_data = p_m_vertices->m_data;
      m_capacityAndFlags = p_m_vertices->m_data[v33].m_ring.m_capacityAndFlags;
      p_m_vertices->m_data[v33].m_ring.m_size = 0;
      if ( m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          m_data[v33].m_ring.m_data,
          8 * m_capacityAndFlags);
      m_data[v33].m_ring.m_data = 0i64;
      m_data[v33].m_ring.m_capacityAndFlags = 0x80000000;
      v36 = p_m_vertices->m_data;
      v37 = p_m_vertices->m_data[v33].m_planes.m_capacityAndFlags;
      p_m_vertices->m_data[v33].m_planes.m_size = 0;
      if ( v37 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v36[v33].m_planes.m_data,
          4 * v37);
      v36[v33].m_planes.m_data = 0i64;
      v36[v33].m_planes.m_capacityAndFlags = 0x80000000;
      ++v32;
      ++v33;
    }
    while ( v32 < this->m_vertices.m_size );
  }
  v38 = 0;
  if ( this->m_triangles.m_size > 0 )
  {
    v39 = 0i64;
    do
    {
      ++v38;
      p_m_triangles->m_data[v39++].m_plane = 0i64;
      p_m_triangles->m_data[v39 - 1].m_edges[0] = 0i64;
      p_m_triangles->m_data[v39 - 1].m_edges[1] = 0i64;
      p_m_triangles->m_data[v39 - 1].m_edges[2] = 0i64;
    }
    while ( v38 < this->m_triangles.m_size );
  }
  m_used = this->m_topology.m_vertices.m_used;
  v41 = &v187;
  if ( !m_used )
    v41 = 0i64;
  if ( v41 )
  {
    do
    {
      m_numRefs = m_used->m_numRefs;
      p_m_ring = (__int64)&p_m_vertices->m_data[(__int64)SLODWORD(m_used->m_index)].m_ring;
      v44 = *(_DWORD *)(p_m_ring + 12) & 0x3FFFFFFF;
      if ( v44 >= m_numRefs )
      {
        LODWORD(retaddr.vfptr) = 0;
      }
      else
      {
        v45 = 2 * v44;
        if ( m_numRefs < v45 )
          m_numRefs = v45;
        hkArrayUtil::_reserve(
          (hkResult *)&retaddr,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)p_m_ring,
          m_numRefs,
          8);
      }
      m_used = m_used->m_next;
      v46 = &v187;
      if ( !m_used )
        v46 = 0i64;
    }
    while ( v46 );
  }
  v47 = this->m_vertices.m_size;
  v184.m_storage.m_words.m_data = 0i64;
  v184.m_storage.m_words.m_size = 0;
  v184.m_storage.m_words.m_capacityAndFlags = 0x80000000;
  v184.m_storage.m_numBits = 0;
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::setSizeAndFill(&v184, 0, v47, 0);
  m_next = this->m_topology.m_triangles.m_used;
  v49 = &retaddr;
  v50 = 0;
  if ( !m_next )
    v49 = 0i64;
  if ( v49 )
  {
    do
    {
      m_geometry = this->m_geometry;
      v52 = m_geometry->m_vertices.m_data;
      m_index_low = SLODWORD(m_next->m_vertices[1]->m_index);
      v54 = m_next->m_vertices[2];
      LODWORD(v180.m_edge.m_triangle) = m_next->m_vertices[0]->m_index;
      v55 = SLODWORD(v54->m_index);
      v56 = SLODWORD(m_next->m_index);
      v57 = v56;
      HIDWORD(v180.m_edge.m_triangle) = m_index_low;
      v180.m_edge.m_index = v55;
      m_quad = v52[SLODWORD(v180.m_edge.m_triangle)].m_quad;
      p_m_quad = &p_m_triangles->m_data[v56].m_plane.m_quad;
      v60 = v52[m_index_low].m_quad;
      v61 = v52[v55].m_quad;
      m_material = m_geometry->m_triangles.m_data[v57].m_material;
      p_m_quad[3].m128_i32[1] = v50;
      p_m_quad[1].m128_u64[0] = 0i64;
      p_m_quad[1].m128_u64[1] = 0i64;
      p_m_quad[2].m128_u64[0] = 0i64;
      p_m_quad[2].m128_u64[1] = -1i64;
      p_m_quad[3].m128_i32[0] = -1;
      p_m_quad[3].m128_i8[8] = 0;
      m_tracker = this->m_config.m_tracker;
      LODWORD(retaddr.vfptr) = m_material;
      v187 = v50 + 1;
      if ( m_tracker && this->m_config.m_buildClusters.m_bool )
      {
        m_tracker->vfptr->setClusterId(m_tracker, &p_m_quad[3].m128_i32[1], 1, p_m_quad[3].m128_i32[1]);
        m_material = (int)retaddr.vfptr;
      }
      v64 = _mm_sub_ps(v61, m_quad);
      v65 = _mm_sub_ps(v60, m_quad);
      v66 = this->m_config.m_inverseOrientation.m_bool != 0;
      v67 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v64, v64, 201), v65), _mm_mul_ps(_mm_shuffle_ps(v65, v65, 201), v64));
      v68 = _mm_shuffle_ps(v67, v67, 201);
      v69 = _mm_mul_ps(v68, v68);
      v70 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v69, v69, 85), _mm_shuffle_ps(v69, v69, 0)),
              _mm_shuffle_ps(v69, v69, 170));
      v71 = _mm_rsqrt_ps(v70);
      v72 = _mm_mul_ps(
              v68,
              _mm_andnot_ps(
                _mm_cmple_ps(v70, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v71, v70), v71)),
                  _mm_mul_ps(*(__m128 *)_xmm, v71))));
      v73 = _mm_mul_ps(m_quad, v72);
      v74 = _mm_shuffle_ps(
              v72,
              _mm_unpackhi_ps(
                v72,
                _mm_sub_ps(
                  (__m128)0i64,
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
                    _mm_shuffle_ps(v73, v73, 170)))),
              196);
      *p_m_quad = v74;
      if ( v66 )
        *p_m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v74);
      v75 = &v180;
      v23 = 3i64;
      do
      {
        m_triangle_low = SLODWORD(v75->m_edge.m_triangle);
        v77 = &p_m_vertices->m_data[m_triangle_low];
        if ( this->m_config.m_protectMaterialBoundaries.m_bool
          && ((v184.m_storage.m_words.m_data[m_triangle_low >> 5] >> (m_triangle_low & 0x1F)) & 1) != 0
          && v77->m_material != m_material )
        {
          v77->m_isFixed = 1;
        }
        else
        {
          v184.m_storage.m_words.m_data[(__int64)SLODWORD(v75->m_edge.m_triangle) >> 5] |= 1 << (m_triangle_low & 0x1F);
          v77->m_material = m_material;
        }
        v78 = &v77->m_ring;
        if ( v77->m_ring.m_size == (v77->m_ring.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v78->m_data, 8);
          m_material = (int)retaddr.vfptr;
        }
        p_m_triangle = &v78->m_data[v78->m_size].m_triangle;
        if ( p_m_triangle )
          *p_m_triangle = m_next;
        ++v78->m_size;
        v75 = (hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *)((char *)v75 + 4);
        --v23;
      }
      while ( v23 );
      m_next = m_next->m_next;
      v50 = v187;
      v80 = &retaddr;
      if ( !m_next )
        v80 = 0i64;
    }
    while ( v80 );
  }
  v184.m_storage.m_words.m_size = 0;
  if ( v184.m_storage.m_words.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v184.m_storage.m_words.m_data,
      4 * v184.m_storage.m_words.m_capacityAndFlags);
  v81 = this->m_topology.m_triangles.m_used;
  v180.m_edge.m_index = 0;
  v180.m_edge.m_triangle = v81;
  if ( v81
    && v81->m_vertices[0]->m_index > v81->m_vertices[1]->m_index
    && (v81->m_links[0] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
  {
    hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v180);
  }
  m_triangle = v180.m_edge.m_triangle;
  v83 = &v180;
  if ( !v180.m_edge.m_triangle )
    v83 = 0i64;
  if ( v83 )
  {
    m_index = v180.m_edge.m_index;
    while ( 1 )
    {
      v85 = m_triangle->m_links[m_index];
      if ( (v85 & 0xFFFFFFFFFFFFFFFCui64) != 0 )
      {
        if ( this->m_config.m_maxAngle > 3.1415927 )
          goto LABEL_87;
        v104 = this->m_geometry->m_vertices.m_data;
        v105 = v104[m_triangle->m_vertices[m_index]->m_index].m_quad;
        v86 = (9i64 >> (2 * (unsigned __int8)m_index)) & 3;
        v106 = m_triangle->m_vertices[(18i64 >> (2 * (unsigned __int8)m_index)) & 3];
        v185.m_col0.m_quad = _mm_sub_ps(v104[m_triangle->m_vertices[v86]->m_index].m_quad, v105);
        *(__m128 *)((char *)&v185.m_col0.m_quad + 8) = _mm_sub_ps(v104[v106->m_index].m_quad, v105);
        *(__m128 *)((char *)&v185.m_col1.m_quad + 8) = _mm_sub_ps(
                                                         v104[*(_QWORD *)(*(_QWORD *)((v85 & 0xFFFFFFFFFFFFFFFCui64)
                                                                                    + 8
                                                                                    * ((18i64 >> (2
                                                                                                * ((unsigned __int8)v85 & 3u))) & 3)
                                                                                    + 16)
                                                                        + 16i64)].m_quad,
                                                         v105);
        hkMatrix3f::getDeterminant(&v185, (hkSimdFloat32 *)&v184);
        if ( *(float *)&v184.m_storage.m_words.m_data < 0.0 )
          goto LABEL_87;
        v107 = _mm_mul_ps(
                 p_m_triangles->m_data[(__int64)SLODWORD(m_triangle->m_index)].m_plane.m_quad,
                 p_m_triangles->m_data[(__int64)*(int *)((m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64) + 64)].m_plane.m_quad);
        if ( (float)((float)(_mm_shuffle_ps(v107, v107, 85).m128_f32[0] + _mm_shuffle_ps(v107, v107, 0).m128_f32[0])
                   + _mm_shuffle_ps(v107, v107, 170).m128_f32[0]) >= v14 )
          goto LABEL_87;
      }
      else
      {
        p_m_vertices->m_data[(__int64)SLODWORD(m_triangle->m_vertices[m_index]->m_index)].m_isNaked = 1;
        v86 = (9i64 >> (2 * (unsigned __int8)m_index)) & 3;
        p_m_vertices->m_data[(__int64)SLODWORD(m_triangle->m_vertices[v86]->m_index)].m_isNaked = 1;
        if ( !this->m_config.m_protectNakedBoundaries.m_bool )
        {
          v87 = p_m_triangles->m_data[(__int64)SLODWORD(m_triangle->m_index)].m_plane.m_quad;
          v88 = this->m_geometry->m_vertices.m_data;
          v89 = v88[SLODWORD(m_triangle->m_vertices[m_index]->m_index)].m_quad;
          LODWORD(retaddr.vfptr) = this->m_triangles.m_size;
          v90 = _mm_sub_ps(v88[SLODWORD(m_triangle->m_vertices[v86]->m_index)].m_quad, v89);
          v91 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v87, v87, 201), v90),
                  _mm_mul_ps(_mm_shuffle_ps(v90, v90, 201), v87));
          v92 = _mm_shuffle_ps(v91, v91, 201);
          v93 = _mm_mul_ps(v92, v92);
          v94 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v93, v93, 85), _mm_shuffle_ps(v93, v93, 0)),
                  _mm_shuffle_ps(v93, v93, 170));
          v95 = _mm_rsqrt_ps(v94);
          v96 = _mm_mul_ps(
                  v92,
                  _mm_andnot_ps(
                    _mm_cmple_ps(v94, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v95, v94), v95)),
                      _mm_mul_ps(*(__m128 *)_xmm, v95))));
          v97 = _mm_mul_ps(v96, v89);
          v98 = _mm_shuffle_ps(
                  v96,
                  _mm_unpackhi_ps(
                    v96,
                    _mm_sub_ps(
                      (__m128)0i64,
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v97, v97, 85), _mm_shuffle_ps(v97, v97, 0)),
                        _mm_shuffle_ps(v97, v97, 170)))),
                  196);
          if ( LODWORD(retaddr.vfptr) == (this->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_triangles.m_data, 64);
          vfptr = (int)retaddr.vfptr;
          v100 = &this->m_triangles.m_data[(__int64)this->m_triangles.m_size++];
          *(_QWORD *)v100->m_planes = -1i64;
          v100->m_planes[2] = -1;
          v100->m_plane.m_quad = v98;
          v100->m_edges[0] = 0i64;
          v100->m_edges[1] = 0i64;
          v100->m_edges[2] = 0i64;
          v101 = m_triangle->m_index;
          v100->m_removed = 0;
          v100->m_cid = v101;
          p_m_triangles->m_data[SLODWORD(m_triangle->m_index)].m_planes[m_index] = (int)retaddr.vfptr;
          v102 = (__int64)&p_m_vertices->m_data[(__int64)SLODWORD(m_triangle->m_vertices[m_index]->m_index)];
          if ( *(_DWORD *)(v102 + 8) == (*(_DWORD *)(v102 + 12) & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&p_m_vertices->m_data[(__int64)SLODWORD(m_triangle->m_vertices[m_index]->m_index)].m_planes.m_data,
              4);
            vfptr = (int)retaddr.vfptr;
          }
          *(_DWORD *)(*(_QWORD *)v102 + 4i64 * (int)(*(_DWORD *)(v102 + 8))++) = vfptr;
          v103 = (__int64)&p_m_vertices->m_data[(__int64)SLODWORD(m_triangle->m_vertices[v86]->m_index)];
          if ( *(_DWORD *)(v103 + 8) == (*(_DWORD *)(v103 + 12) & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&p_m_vertices->m_data[(__int64)SLODWORD(m_triangle->m_vertices[v86]->m_index)].m_planes.m_data,
              4);
            vfptr = (int)retaddr.vfptr;
          }
          *(_DWORD *)(*(_QWORD *)v103 + 4i64 * (int)(*(_DWORD *)(v103 + 8))++) = vfptr;
          goto LABEL_87;
        }
      }
      p_m_vertices->m_data[(__int64)SLODWORD(m_triangle->m_vertices[m_index]->m_index)].m_isFixed = 1;
      p_m_vertices->m_data[(__int64)SLODWORD(m_triangle->m_vertices[v86]->m_index)].m_isFixed = 1;
LABEL_87:
      if ( m_triangle )
      {
        hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v180);
        m_index = v180.m_edge.m_index;
        m_triangle = v180.m_edge.m_triangle;
      }
      v108 = &v180;
      if ( !m_triangle )
        v108 = 0i64;
      if ( !v108 )
      {
        v23 = 0i64;
        break;
      }
    }
  }
  v109 = 2 * this->m_triangles.m_size;
  v110 = 0;
  array = 0i64;
  v182 = 0;
  v183 = 0x80000000;
  if ( v109 > 0 )
  {
    hkArrayUtil::_reserve((hkResult *)&retaddr, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v109, 16);
    v110 = v182;
  }
  v111 = this->m_topology.m_triangles.m_used;
  v180.m_edge.m_index = 0;
  v180.m_edge.m_triangle = v111;
  if ( v111
    && v111->m_vertices[0]->m_index > v111->m_vertices[1]->m_index
    && (v111->m_links[0] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
  {
    hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v180);
  }
  v112 = v180.m_edge.m_triangle;
  v113 = &v180;
  if ( !v180.m_edge.m_triangle )
    v113 = 0i64;
  if ( v113 )
  {
    do
    {
      if ( v110 == (v183 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
        v110 = v182;
      }
      v114 = (hkgpIndexedMeshDefinitions::Triangle **)&array[16 * v110];
      if ( v114 )
      {
        v115 = *(hkgpIndexedMeshDefinitions::Triangle **)&v180.m_edge.m_index;
        *v114 = v112;
        v114[1] = v115;
        v110 = v182;
      }
      v182 = ++v110;
      if ( v112 )
      {
        hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v180);
        v112 = v180.m_edge.m_triangle;
      }
      v116 = &v180;
      if ( !v112 )
        v116 = 0i64;
    }
    while ( v116 );
  }
  v117 = 0;
  if ( v110 > 0 )
  {
    v118 = 0i64;
    do
    {
      v119 = array;
      v118 += 16i64;
      v120 = this->m_edgesTree.m_prng.m_w + this->m_edgesTree.m_prng.m_c;
      v121 = this->m_edgesTree.m_prng.m_y ^ (32 * this->m_edgesTree.m_prng.m_y) ^ ((this->m_edgesTree.m_prng.m_y ^ (32 * this->m_edgesTree.m_prng.m_y)) >> 7) ^ ((this->m_edgesTree.m_prng.m_y ^ (32 * this->m_edgesTree.m_prng.m_y) ^ ((this->m_edgesTree.m_prng.m_y ^ (32 * this->m_edgesTree.m_prng.m_y)) >> 7)) << 22);
      v122 = (int)(this->m_edgesTree.m_prng.m_z + v120) < 0;
      v123 = this->m_edgesTree.m_prng.m_z + v120;
      this->m_edgesTree.m_prng.m_z = this->m_edgesTree.m_prng.m_w;
      this->m_edgesTree.m_prng.m_y = v121;
      this->m_edgesTree.m_prng.m_x += 1411392427;
      v123 &= ~0x80000000;
      this->m_edgesTree.m_prng.m_c = v122;
      m_x = this->m_edgesTree.m_prng.m_x;
      this->m_edgesTree.m_prng.m_w = v123;
      ++v117;
      v125 = v123 + v121 + m_x;
      v126 = *(_QWORD *)&v119[v118 - 16];
      v127 = *(_QWORD *)&v119[v118 - 8];
      v128 = &v119[16 * ((int)(v125 >> 1) % v110)];
      *(_QWORD *)&v119[v118 - 16] = *(_QWORD *)v128;
      *(_QWORD *)&v119[v118 - 8] = *((_QWORD *)v128 + 1);
      *(_QWORD *)v128 = v126;
      *((_QWORD *)v128 + 1) = v127;
      v110 = v182;
    }
    while ( v117 < v182 );
  }
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::preAllocateNodes(&this->m_edgesTree, v110);
  v129 = v182;
  v130 = this->m_edgesStorage.m_capacityAndFlags & 0x3FFFFFFF;
  v131 = v182;
  if ( v130 < v182 )
  {
    v132 = 2 * v130;
    if ( v182 < v132 )
      v129 = v132;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_edgesStorage.m_data,
      v129,
      48);
    v129 = v182;
  }
  v133 = this->m_edgesStorage.m_size;
  v134 = v131 - (int)v133;
  if ( v131 - (int)v133 > 0 )
  {
    p_m_action = &this->m_edgesStorage.m_data[v133].m_action;
    do
    {
      if ( p_m_action != (hkgpCgoInternal::Action *)36 )
        *(_DWORD *)p_m_action &= 0xFFFFFFFC;
      p_m_action += 12;
      --v134;
    }
    while ( v134 );
    v129 = v182;
  }
  p_m_invalidEdges = &this->m_invalidEdges;
  this->m_edgesStorage.m_size = v131;
  v137 = v129;
  v138 = this->m_invalidEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v138 < v129 )
  {
    v139 = 2 * v138;
    if ( v129 < v139 )
      v129 = v139;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_invalidEdges.m_data,
      v129,
      8);
    v129 = v182;
  }
  this->m_invalidEdges.m_size = v137;
  v140 = 0;
  if ( v129 > 0 )
  {
    v141 = 0i64;
    v142 = 0i64;
    do
    {
      v143 = (hkgpCgoInternal::EdgeInfo *)((char *)this->m_edgesStorage.m_data + v23);
      p_m_invalidEdges->m_data[v142] = v143;
      v144 = array;
      v143->m_edge.m_triangle = *(hkgpIndexedMeshDefinitions::Triangle **)&array[v141];
      v145 = *(_QWORD *)&v144[v141 + 8];
      v143->m_vertex = 0i64;
      *(_QWORD *)&v143->m_edge.m_index = v145;
      v143->m_error = 3.40282e38;
      m_edge = (hkArray<unsigned int,hkContainerHeapAllocator>)v143->m_edge;
      v143->m_invalidIndex = v140;
      v143->m_nodeIndex = 0;
      v184.m_storage.m_words = m_edge;
      hkgpCgoInternal::setEdgeInfo(this, (hkgpIndexedMeshDefinitions::Edge *)&v184, v143);
      ++v140;
      v23 += 48i64;
      ++v142;
      v141 += 16i64;
    }
    while ( v140 < v182 );
    p_m_vertices = &this->m_vertices;
  }
  v147 = 0;
  if ( this->m_vertices.m_size > 0 )
  {
    v148 = 0i64;
    do
    {
      v149 = p_m_vertices->m_data[v148].m_planes.m_size;
      if ( v149 > 1 )
        hkAlgorithm::quickSortRecursive<int,hkAlgorithm::less<int>>(
          p_m_vertices->m_data[v148].m_planes.m_data,
          0,
          v149 - 1,
          0);
      v150 = p_m_vertices->m_data[v148].m_ring.m_size;
      if ( v150 > 1 )
        hkAlgorithm::quickSortRecursive<hkgpCgoInternal::HTriangle,hkAlgorithm::less<hkgpCgoInternal::HTriangle>>(
          p_m_vertices->m_data[v148].m_ring.m_data,
          0,
          v150 - 1,
          0);
      ++v147;
      ++v148;
    }
    while ( v147 < this->m_vertices.m_size );
  }
  if ( this->m_config.m_decimateComponents.m_bool )
  {
    retaddr.vfptr = (hkgpIndexedMesh::EdgeBarrierVtbl *)&hkgpIndexedMesh::EdgeBarrier::`vftable;
    hkgpIndexedMesh::computeSets(&this->m_topology, &retaddr);
    v151 = this->m_topology.m_sets.m_size;
    v152 = 0;
    v180.m_edge.m_triangle = 0i64;
    *(&v180.m_edge.m_index + 1) = 0x80000000;
    v180.m_edge.m_index = 0;
    v153 = _mm_xor_ps(
             (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
             (__m128)xmmword_141A712A0);
    if ( v151 > 0 )
    {
      hkArrayUtil::_reserve(
        (hkResult *)&retaddr,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&v180.m_edge.m_triangle,
        v151,
        32);
      v152 = v180.m_edge.m_index;
    }
    v154 = v151 - v152;
    v155 = (_OWORD *)((char *)v180.m_edge.m_triangle + 32 * (int)v152);
    v156 = (int)(v151 - v152);
    if ( v154 > 0 )
    {
      do
      {
        if ( v155 )
        {
          *v155 = xmmword_141A712A0;
          v155[1] = v153;
        }
        v155 += 2;
        --v156;
      }
      while ( v156 );
    }
    v157 = this->m_topology.m_triangles.m_used;
    v158 = &retaddr;
    v180.m_edge.m_index = v151;
    if ( !v157 )
      v158 = 0i64;
    if ( v158 )
    {
      do
      {
        v159 = this->m_geometry->m_vertices.m_data;
        v160 = v159[SLODWORD(v157->m_vertices[1]->m_index)].m_quad;
        v161 = (__m128 *)((char *)v180.m_edge.m_triangle + 32 * v157->m_set);
        v162 = _mm_max_ps(
                 v161[1],
                 _mm_max_ps(
                   _mm_max_ps(v159[SLODWORD(v157->m_vertices[0]->m_index)].m_quad, v160),
                   v159[SLODWORD(v157->m_vertices[2]->m_index)].m_quad));
        *v161 = _mm_min_ps(
                  *v161,
                  _mm_min_ps(
                    _mm_min_ps(v159[SLODWORD(v157->m_vertices[0]->m_index)].m_quad, v160),
                    v159[SLODWORD(v157->m_vertices[2]->m_index)].m_quad));
        v161[1] = v162;
        v157 = v157->m_next;
        v163 = &retaddr;
        if ( !v157 )
          v163 = 0i64;
      }
      while ( v163 );
    }
    v164 = this->m_topology.m_sets.m_size;
    p_m_sets = &this->m_sets;
    v166 = this->m_sets.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v166 < v164 )
    {
      v167 = 2 * v166;
      v168 = this->m_topology.m_sets.m_size;
      if ( v164 < v167 )
        v168 = v167;
      hkArrayUtil::_reserve(
        (hkResult *)&retaddr,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_sets.m_data,
        v168,
        8);
    }
    v169 = (signed int)v180.m_edge.m_index <= 0;
    this->m_sets.m_size = v164;
    v170 = 0;
    if ( !v169 )
    {
      v171 = 0i64;
      v172 = 0i64;
      do
      {
        v172 += 32i64;
        ++v171;
        v173 = _mm_sub_ps(
                 *(__m128 *)((char *)v180.m_edge.m_triangle + v172 - 32),
                 *(__m128 *)((char *)v180.m_edge.m_triangle + v172 - 16));
        v174 = _mm_mul_ps(v173, v173);
        v175 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v174, v174, 85), _mm_shuffle_ps(v174, v174, 0)),
                 _mm_shuffle_ps(v174, v174, 170));
        v176 = _mm_rsqrt_ps(v175);
        p_m_sets->m_data[v170].m_error = _mm_andnot_ps(
                                           _mm_cmple_ps(v175, (__m128)0i64),
                                           _mm_mul_ps(
                                             _mm_mul_ps(
                                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v176, v175), v176)),
                                               _mm_mul_ps(*(__m128 *)_xmm, v176)),
                                             v175)).m128_f32[0]
                                       * 0.5;
        p_m_sets->m_data[v171 - 1].m_index = v170++;
      }
      while ( v170 < (int)v180.m_edge.m_index );
    }
    v177 = this->m_sets.m_size;
    if ( v177 > 1 )
      hkAlgorithm::quickSortRecursive<hkgpCgoInternal::Set,hkAlgorithm::greater<hkgpCgoInternal::Set>>(
        p_m_sets->m_data,
        0,
        v177 - 1,
        0);
    v180.m_edge.m_index = 0;
    if ( *((int *)&v180.m_edge.m_index + 1) >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v180.m_edge.m_triangle,
        32 * *(&v180.m_edge.m_index + 1));
  }
  hkgpCgoInternal::update(this);
  v178 = this->m_invalidEdges.m_capacityAndFlags;
  this->m_invalidEdges.m_size = 0;
  if ( v178 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      p_m_invalidEdges->m_data,
      8 * v178);
  p_m_invalidEdges->m_data = 0i64;
  this->m_invalidEdges.m_capacityAndFlags = 0x80000000;
  v179 = 256;
  if ( (this->m_invalidEdges.m_capacityAndFlags & 0x3FFFFFFFu) < 0x100 )
  {
    if ( 2 * (this->m_invalidEdges.m_capacityAndFlags & 0x3FFFFFFF) > 256 )
      v179 = 2 * (this->m_invalidEdges.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&p_m_invalidEdges->m_data,
      v179,
      8);
  }
  v182 = 0;
  if ( v183 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v183);
}* *(&v180.m_edge.m_index + 1));
  }
  hkgpCgoInternal::update(this);
  v178 = this->m_invalidEdges.m_capacityAndFlags;
  this->m_invalidEdges.m_size = 0;
  if ( v178 >= 0 )
    hkContainerHeapAllocator::s_alloc

// File Line: 445
// RVA: 0xCE6B30
void __fastcall hkgpCgoInternal::analyze(
        hkgpCgoInternal *this,
        hkArray<hkgpCgo::ClusterData,hkContainerHeapAllocator> *clusters)
{
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16> *p_m_edgesTree; // rdi
  __int64 m_root; // rax
  int m_capacityAndFlags; // edx
  int m_size; // r9d
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::Node *m_data; // r14
  __int64 v8; // rsi
  int v9; // r8d
  hkgpCgoInternal::EdgeInfo *m_value; // r15
  int v11; // r8d
  int v12; // r8d
  int v13; // edx
  __int64 v14; // rcx
  __int64 v15; // r9
  __int64 v16; // r8
  __int64 v17; // rdx
  hkgpCgo::ClusterData *v18; // rcx
  float v19; // xmm0_4
  int v20; // r8d
  int v21; // r8d
  __int64 v22; // r10
  hkgpCgo::ClusterData *v23; // rcx
  int v24; // eax
  __int64 v25; // rdx
  int v26; // eax
  hkgpCgoInternal::ErrorCollector functor; // [rsp+30h] [rbp-40h] BYREF
  hkArray<int,hkContainerHeapAllocator> clusterIds; // [rsp+40h] [rbp-30h] BYREF
  float v29; // [rsp+88h] [rbp+18h]

  p_m_edgesTree = &this->m_edgesTree;
  m_root = this->m_edgesTree.m_root;
  m_capacityAndFlags = 0x80000000;
  functor.m_values.m_data = 0i64;
  m_size = 0;
  functor.m_values.m_size = 0;
  functor.m_values.m_capacityAndFlags = 0x80000000;
  if ( (_DWORD)m_root )
  {
    m_data = p_m_edgesTree->m_nodes.m_data;
    v8 = m_root;
    v9 = p_m_edgesTree->m_nodes.m_data[m_root].m_children[0];
    if ( v9 )
    {
      hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::traverseMinMax<hkgpCgoInternal::ErrorCollector>(
        &this->m_edgesTree,
        &functor,
        v9);
      m_capacityAndFlags = functor.m_values.m_capacityAndFlags;
      m_size = functor.m_values.m_size;
    }
    m_value = m_data[v8].m_value;
    if ( m_value->m_error < 3.40282e38 )
    {
      if ( m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&functor.m_values.m_data, 4);
        m_size = functor.m_values.m_size;
      }
      functor.m_values.m_data[m_size] = m_value->m_error;
      ++functor.m_values.m_size;
    }
    v11 = m_data[v8].m_children[1];
    if ( v11 )
      hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::traverseMinMax<hkgpCgoInternal::ErrorCollector>(
        p_m_edgesTree,
        &functor,
        v11);
  }
  v12 = clusters->m_size;
  clusterIds.m_data = 0i64;
  clusterIds.m_size = 0;
  clusterIds.m_capacityAndFlags = 0x80000000;
  hkGeometryProcessing::generateClusters(&functor.m_values, 0i64, v12, &clusterIds, 512);
  v13 = 0;
  if ( clusters->m_size > 0 )
  {
    v14 = 0i64;
    do
    {
      ++v13;
      clusters->m_data[v14++].m_errorRange[0] = 3.40282e38;
      clusters->m_data[v14 - 1].m_errorRange[1] = -3.40282e38;
      clusters->m_data[v14 - 1].m_numVertices = 0;
    }
    while ( v13 < clusters->m_size );
  }
  v15 = 0i64;
  if ( functor.m_values.m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      v15 = (unsigned int)(v15 + 1);
      v17 = clusterIds.m_data[v16++];
      v18 = clusters->m_data;
      v29 = clusters->m_data[clusterIds.m_data[v16 - 1]].m_errorRange[1];
      v18[v17].m_errorRange[0] = fminf(
                                   clusters->m_data[clusterIds.m_data[v16 - 1]].m_errorRange[0],
                                   functor.m_values.m_data[v16 - 1]);
      v19 = functor.m_values.m_data[v16 - 1];
      ++v18[v17].m_numVertices;
      v18[v17].m_errorRange[1] = fmaxf(v29, v19);
    }
    while ( (int)v15 < functor.m_values.m_size );
  }
  v20 = clusters->m_size;
  if ( v20 > 1 )
    hkAlgorithm::quickSortRecursive<hkgpCgo::ClusterData,hkAlgorithm::less<hkgpCgo::ClusterData>>(
      clusters->m_data,
      0,
      v20 - 1,
      0);
  v21 = 0;
  if ( clusters->m_size > 0 )
  {
    v22 = 0i64;
    do
    {
      v23 = &clusters->m_data[v22];
      if ( !v23->m_numVertices )
      {
        --clusters->m_size;
        v15 = (__int64)&v23[1];
        v24 = 12 * (clusters->m_size - v21);
        if ( v24 > 0 )
        {
          v15 = 12i64;
          v25 = ((unsigned int)(v24 - 1) >> 2) + 1;
          do
          {
            v26 = LODWORD(v23[1].m_errorRange[0]);
            v23 = (hkgpCgo::ClusterData *)((char *)v23 + 4);
            v23[-1].m_numVertices = v26;
            --v25;
          }
          while ( v25 );
        }
        --v21;
        --v22;
      }
      ++v21;
      ++v22;
    }
    while ( v21 < clusters->m_size );
  }
  clusterIds.m_size = 0;
  if ( clusterIds.m_capacityAndFlags >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      clusterIds.m_data,
      (unsigned int)(4 * clusterIds.m_capacityAndFlags),
      v15);
  clusterIds.m_data = 0i64;
  functor.m_values.m_size = 0;
  clusterIds.m_capacityAndFlags = 0x80000000;
  if ( functor.m_values.m_capacityAndFlags >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, float *, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      functor.m_values.m_data,
      (unsigned int)(4 * functor.m_values.m_capacityAndFlags),
      v15);
}

// File Line: 476
// RVA: 0xCE6E10
bool __fastcall hkgpCgoInternal::update(hkgpCgoInternal *this)
{
  bool v2; // r15
  int i; // r14d
  int v4; // r9d
  hkgpCgoInternal::EdgeInfo **v5; // rdi
  _QWORD **Value; // rax
  hkgpJobQueue::IJob *v7; // rax
  __int64 v8; // rcx
  int v9; // r8d
  hkVector4f *m_data; // rdx
  int m_capacityAndFlags; // ecx
  __int64 v12; // rbx
  hkgpCgoInternal::ProcessConfig pcfg; // [rsp+20h] [rbp-D8h] BYREF
  __int64 v15; // [rsp+D0h] [rbp-28h]

  v2 = this->m_config.m_multiThreaded.m_bool != 0;
  for ( i = 0; i < this->m_invalidEdges.m_size; i += 16 )
  {
    v4 = 16;
    v5 = &this->m_invalidEdges.m_data[i];
    if ( this->m_invalidEdges.m_size - i < 16 )
      v4 = this->m_invalidEdges.m_size - i;
    LODWORD(v15) = v4;
    if ( v2 )
    {
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v7 = (hkgpJobQueue::IJob *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
      if ( v7 )
      {
        v8 = v15;
        v7[1].vfptr = (hkgpJobQueue::IJobVtbl *)this;
        v7[2].vfptr = (hkgpJobQueue::IJobVtbl *)v5;
        v7[3].vfptr = (hkgpJobQueue::IJobVtbl *)v8;
        v7->vfptr = (hkgpJobQueue::IJobVtbl *)&hkgpJobQueue::Box<hkgpCgoInternal::UpdateJob>::`vftable;
        hkgpJobQueue::push(&this->m_jobQueue, v7);
      }
      else
      {
        hkgpJobQueue::push(&this->m_jobQueue, 0i64);
      }
    }
    else
    {
      *(_DWORD *)&pcfg.m_action &= 0xFFFFFFFC;
      v9 = 0x80000000;
      m_data = 0i64;
      m_capacityAndFlags = 0x80000000;
      pcfg.m_ring.m_data = 0i64;
      pcfg.m_ring.m_size = 0;
      pcfg.m_ring.m_capacityAndFlags = 0x80000000;
      pcfg.m_planes.m_data = 0i64;
      pcfg.m_planes.m_size = 0;
      pcfg.m_planes.m_capacityAndFlags = 0x80000000;
      if ( v4 > 0 )
      {
        v12 = (unsigned int)v4;
        do
        {
          hkgpCgoInternal::updateEdge(this, &pcfg, *v5++);
          --v12;
        }
        while ( v12 );
        m_capacityAndFlags = pcfg.m_planes.m_capacityAndFlags;
        m_data = pcfg.m_planes.m_data;
        v9 = pcfg.m_ring.m_capacityAndFlags;
      }
      pcfg.m_planes.m_size = 0;
      if ( m_capacityAndFlags >= 0 )
      {
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          m_data,
          16 * m_capacityAndFlags);
        v9 = pcfg.m_ring.m_capacityAndFlags;
      }
      pcfg.m_planes.m_data = 0i64;
      pcfg.m_planes.m_capacityAndFlags = 0x80000000;
      pcfg.m_ring.m_size = 0;
      if ( v9 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, pcfg.m_ring.m_data, 8 * v9);
    }
  }
  hkgpJobQueue::waitForCompletion(&this->m_jobQueue);
  this->m_invalidEdges.m_size = 0;
  return hkgpCgoInternal::getBestEdge(this) != 0i64;
}

// File Line: 504
// RVA: 0xCE7010
hkgpCgoInternal::EdgeInfo *__fastcall hkgpCgoInternal::getBestEdge(hkgpCgoInternal *this)
{
  int m_root; // edx
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::Node *m_data; // r9
  hkgpCgoInternal::EdgeInfo *result; // rax

  if ( !this->m_edgesTree.m_root )
    return 0i64;
  m_root = this->m_edgesTree.m_root;
  if ( m_root )
  {
    while ( 1 )
    {
      m_data = this->m_edgesTree.m_nodes.m_data;
      if ( !m_data[m_root].m_children[0] )
        break;
      m_root = m_data[m_root].m_children[0];
    }
  }
  result = this->m_edgesTree.m_nodes.m_data[m_root].m_value;
  if ( result->m_error >= 3.40282e38 )
    return 0i64;
  return result;
}

// File Line: 519
// RVA: 0xCE7070
void __fastcall hkgpCgoInternal::getErrors(hkgpCgoInternal *this, hkArray<float,hkContainerHeapAllocator> *errors)
{
  __int64 m_size; // rdx
  int v5; // edi
  __int64 v6; // r8
  int *m_children; // rax
  __int64 i; // rbx
  hkgpCgoInternal::EdgeInfo *m_value; // r14
  __int64 v10; // r9
  __int64 v11; // rax
  int v12; // edx
  int *v13; // r8
  int v14; // r8d

  errors->m_size = 0;
  if ( this->m_edgesTree.m_root )
  {
    m_size = this->m_edgesTree.m_nodes.m_size;
    v5 = 1;
    v6 = 1i64;
    if ( m_size <= 1 )
    {
LABEL_6:
      v5 = 0;
    }
    else
    {
      m_children = this->m_edgesTree.m_nodes.m_data[1].m_children;
      while ( *m_children == v5 )
      {
        ++v6;
        ++v5;
        m_children += 6;
        if ( v6 >= m_size )
          goto LABEL_6;
      }
    }
    for ( i = v5; i; v5 = v12 )
    {
      m_value = this->m_edgesTree.m_nodes.m_data[i].m_value;
      if ( errors->m_size == (errors->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&errors->m_data, 4);
      errors->m_data[errors->m_size++] = m_value->m_error;
      if ( !i )
        break;
      v10 = this->m_edgesTree.m_nodes.m_size;
      v11 = i + 1;
      v12 = v5 + 1;
      i = v11;
      if ( v11 >= v10 )
        break;
      v13 = this->m_edgesTree.m_nodes.m_data[v11].m_children;
      while ( *v13 == v12 )
      {
        ++i;
        ++v12;
        v13 += 6;
        if ( i >= v10 )
          goto LABEL_17;
      }
    }
LABEL_17:
    v14 = errors->m_size;
    if ( v14 > 1 )
      hkAlgorithm::quickSortRecursive<float,hkAlgorithm::less<float>>(errors->m_data, 0, v14 - 1, 0);
  }
}

// File Line: 533
// RVA: 0xCE8940
bool __fastcall hkgpCgoInternal::solveVertex(
        hkgpCgoInternal *this,
        hkgpCgoInternal::ProcessConfig *pcfg,
        bool project,
        hkVector4f *vertex)
{
  hkVector4f v6; // xmm0
  hkSimdFloat32 v7; // xmm1
  bool result; // al
  hkVector4f vertexa; // [rsp+20h] [rbp-48h] BYREF
  hkgpCgoInternal::ProcessedVertex vertexOut; // [rsp+30h] [rbp-38h] BYREF
  int v11; // [rsp+80h] [rbp+18h]

  vertexa.m_quad = vertex->m_quad;
  if ( project && !hkgpCgoInternal::projectVertex(this, &pcfg->m_planes, &vertexa)
    || !hkgpCgoInternal::processVertex(this, pcfg, &vertexa, &vertexOut) )
  {
    return 0;
  }
  v6.m_quad = (__m128)vertexOut.m_vertex;
  v7.m_real = (__m128)vertexOut.m_error;
  pcfg->m_action = (hkgpCgoInternal::Action)(v11 & 0xFFFFFFFC | 2);
  result = 1;
  pcfg->m_vertex = (hkVector4f)v6.m_quad;
  pcfg->m_maxError = (hkSimdFloat32)v7.m_real;
  return result;
}

// File Line: 554
// RVA: 0xCE71C0
void __fastcall hkgpCgoInternal::updateEdge(
        hkgpCgoInternal *this,
        hkgpCgoInternal::ProcessConfig *pcfg,
        hkgpCgoInternal::EdgeInfo *e)
{
  hkgpCgoInternal::Action v5; // eax
  __int64 v6; // r14
  __int64 m_index_low; // r8
  __int64 v9; // rdx
  hkgpCgoInternal::VertexInfo *m_data; // rax
  unsigned __int64 v11; // r15
  hkgpCgoInternal::VertexInfo *v12; // rbx
  float m_error; // xmm0_4
  hkgpCgo::Config::VertexCombinator m_combinator; // ecx
  __int32 v15; // ecx
  hkSimdFloat32 v16; // xmm1
  int v17; // r9d
  int v18; // eax
  int v19; // eax
  int v20; // r13d
  __int64 v21; // r12
  hkgpCgoInternal::TriangleInfo *v22; // r15
  int v23; // r13d
  __int64 v24; // r12
  hkgpCgoInternal::TriangleInfo *v25; // r15
  char v26; // dl
  hkgpCgoInternal::ICustomMetric *m_cstMetric; // rcx
  bool v28; // zf
  char v29; // cl
  bool v30; // al
  hkVector4f *m_edgeVertices; // r15
  hkVector4f *v32; // r12
  __m128 v33; // xmm11
  hkgpCgo::Config::SolverAccuracy v34; // r11d
  hkVector4f *v35; // r10
  __int64 m_size; // r9
  int v37; // r14d
  __m128 v38; // xmm10
  __m128 v39; // xmm5
  __m128 v40; // xmm1
  __m128 v41; // xmm3
  __m128 v42; // xmm2
  __m128 v43; // xmm9
  __m128 v44; // xmm10
  __m128 v45; // xmm9
  __m128 v46; // xmm3
  hkVector4f *v47; // rax
  __int64 v48; // rcx
  __m128 v49; // xmm2
  __m128 v50; // xmm2
  __m128 v51; // xmm2
  __m128 v52; // xmm0
  __m128 v53; // xmm2
  __m128 v54; // xmm2
  __m128 v55; // xmm0
  __m128 v56; // xmm1
  __m128 v57; // xmm2
  __m128 v58; // xmm0
  __m128 v59; // xmm1
  __m128 v60; // xmm0
  __int64 v61; // r9
  hkVector4f v62; // xmm0
  hkSimdFloat32 v63; // xmm1
  hkgpCgo::Config::SolverAccuracy m_solverAccuracy; // r15d
  __m128 m_minConvergence_low; // xmm10
  unsigned __int64 *v66; // rdx
  float v67; // xmm10_4
  int v68; // r9d
  __m128 m_quad; // xmm6
  __m128 v70; // xmm7
  int v71; // r13d
  __m128 v72; // xmm11
  __int64 v73; // rcx
  __m128 v74; // xmm11
  hkSimdFloat32 v75; // xmm9
  int v76; // ebx
  int v77; // r15d
  __m128 v78; // xmm8
  __m128 v79; // xmm6
  __int64 v80; // r12
  __m128 v81; // xmm2
  __m128 v82; // xmm2
  hkArray<int,hkContainerHeapAllocator> v83; // xmm1
  bool v84; // r8
  __m128 v85; // xmm7
  __m128 v86; // xmm6
  bool v87; // cc
  hkVector4f v88; // xmm0
  hkSimdFloat32 v89; // xmm1
  float *v90; // rdx
  hkVector4f *p_m_vertex; // r9
  hkgpCgoInternal::Action m_action; // eax
  float v93; // xmm0_4
  hkCriticalSection *p_m_lock; // rdi
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16> *p_m_edgesTree; // rsi
  __int64 m_free; // rbx
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::Node *v97; // r9
  hkVector4f *v98; // r14
  hkArray<int,hkContainerHeapAllocator> output; // [rsp+30h] [rbp-A8h] BYREF
  hkVector4f x; // [rsp+40h] [rbp-98h] BYREF
  hkgpCgoInternal::ProcessedVertex vertexOut; // [rsp+50h] [rbp-88h] BYREF
  hkResult result; // [rsp+328h] [rbp+250h] BYREF
  hkResultEnum v103; // [rsp+330h] [rbp+258h]
  hkgpCgoInternal::EdgeInfo *v104; // [rsp+338h] [rbp+260h]

  v5 = (hkgpCgoInternal::Action)((unsigned int)v104 & 0xFFFFFFFC);
  v6 = 0i64;
  pcfg->m_ring.m_size = 0;
  pcfg->m_action = v5;
  pcfg->m_planes.m_size = 0;
  pcfg->m_vertex = 0i64;
  pcfg->m_maxError = (hkSimdFloat32)xmmword_141A712A0;
  m_index_low = SLODWORD(e->m_edge.m_triangle->m_vertices[e->m_edge.m_index]->m_index);
  pcfg->m_edgeIndices[0] = m_index_low;
  v9 = SLODWORD(e->m_edge.m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)e->m_edge.m_index)) & 3]->m_index);
  pcfg->m_edgeIndices[1] = v9;
  pcfg->m_edgeVertices[0] = this->m_geometry->m_vertices.m_data[m_index_low];
  pcfg->m_edgeVertices[1] = this->m_geometry->m_vertices.m_data[v9];
  m_data = this->m_vertices.m_data;
  v11 = (unsigned __int64)&m_data[m_index_low];
  v12 = &m_data[v9];
  x.m_quad.m128_u64[0] = v11;
  m_error = v12->m_error;
  result.m_enum = *(_DWORD *)(v11 + 48);
  v103 = LODWORD(m_error);
  result.m_enum = fmaxf(*(float *)&result.m_enum, m_error);
  pcfg->m_vtxError.m_real = _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0);
  m_combinator = this->m_config.m_combinator;
  if ( m_combinator )
  {
    v15 = m_combinator - 1;
    if ( v15 )
    {
      if ( v15 != 1 )
        goto LABEL_8;
      v16.m_real = _mm_mul_ps(
                     _mm_add_ps(
                       _mm_shuffle_ps(pcfg->m_edgeVertices[1].m_quad, pcfg->m_edgeVertices[1].m_quad, 255),
                       _mm_shuffle_ps(pcfg->m_edgeVertices[0].m_quad, pcfg->m_edgeVertices[0].m_quad, 255)),
                     (__m128)xmmword_141A711B0);
    }
    else
    {
      v16.m_real = _mm_max_ps(
                     _mm_shuffle_ps(pcfg->m_edgeVertices[0].m_quad, pcfg->m_edgeVertices[0].m_quad, 255),
                     _mm_shuffle_ps(pcfg->m_edgeVertices[1].m_quad, pcfg->m_edgeVertices[1].m_quad, 255));
    }
  }
  else
  {
    v16.m_real = _mm_min_ps(
                   _mm_shuffle_ps(pcfg->m_edgeVertices[0].m_quad, pcfg->m_edgeVertices[0].m_quad, 255),
                   _mm_shuffle_ps(pcfg->m_edgeVertices[1].m_quad, pcfg->m_edgeVertices[1].m_quad, 255));
  }
  pcfg->m_vertexW = (hkSimdFloat32)v16.m_real;
LABEL_8:
  pcfg->m_ring.m_size = 0;
  computeUnionOfSortedArray_hkgpCgoInternal::HTriangle_(
    (hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *)(v11 + 16),
    &v12->m_ring,
    &pcfg->m_ring);
  pcfg->m_planes.m_size = 0;
  output.m_data = 0i64;
  output.m_size = 0;
  output.m_capacityAndFlags = 0x80000000;
  computeUnionOfSortedArray_int_((hkArray<int,hkContainerHeapAllocator> *)v11, &v12->m_planes, &output);
  v17 = pcfg->m_ring.m_size + output.m_size;
  v18 = pcfg->m_planes.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v18 < v17 )
  {
    v19 = 2 * v18;
    if ( v17 < v19 )
      v17 = v19;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&pcfg->m_planes.m_data, v17, 16);
  }
  v20 = 0;
  if ( pcfg->m_ring.m_size > 0 )
  {
    v21 = 0i64;
    do
    {
      v22 = &this->m_triangles.m_data[(__int64)SLODWORD(pcfg->m_ring.m_data[v21].m_triangle->m_index)];
      if ( pcfg->m_planes.m_size == (pcfg->m_planes.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pcfg->m_planes.m_data, 16);
      ++v20;
      ++v21;
      pcfg->m_planes.m_data[pcfg->m_planes.m_size++] = v22->m_plane;
    }
    while ( v20 < pcfg->m_ring.m_size );
  }
  v23 = 0;
  if ( output.m_size > 0 )
  {
    v24 = 0i64;
    do
    {
      v25 = &this->m_triangles.m_data[(__int64)output.m_data[v24]];
      if ( pcfg->m_planes.m_size == (pcfg->m_planes.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pcfg->m_planes.m_data, 16);
      ++v23;
      ++v24;
      pcfg->m_planes.m_data[pcfg->m_planes.m_size++] = v25->m_plane;
    }
    while ( v23 < output.m_size );
  }
  output.m_size = 0;
  if ( output.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      output.m_data,
      4 * output.m_capacityAndFlags);
  v26 = *(_BYTE *)(x.m_quad.m128_u64[0] + 52);
  if ( v26 && v12->m_isFixed )
    goto LABEL_66;
  m_cstMetric = this->m_cstMetric;
  if ( m_cstMetric )
  {
    m_cstMetric->vfptr->onUpdate(m_cstMetric, v104, pcfg);
LABEL_66:
    m_edgeVertices = pcfg->m_edgeVertices;
    goto LABEL_67;
  }
  v28 = v26 == 0;
  if ( v26 )
  {
LABEL_64:
    LOBYTE(v6) = v28;
    if ( hkgpCgoInternal::processVertex(this, pcfg, &pcfg->m_edgeVertices[v6], &vertexOut) )
    {
      v88.m_quad = (__m128)vertexOut.m_vertex;
      v89.m_real = (__m128)vertexOut.m_error;
      pcfg->m_action = (hkgpCgoInternal::Action)((unsigned int)v104 & 0xFFFFFFFC | 2);
      pcfg->m_vertex = (hkVector4f)v88.m_quad;
      pcfg->m_maxError = (hkSimdFloat32)v89.m_real;
    }
    goto LABEL_66;
  }
  if ( v12->m_isFixed )
  {
    v28 = 1;
    goto LABEL_64;
  }
  v29 = *(_BYTE *)(x.m_quad.m128_u64[0] + 53);
  if ( v29 != v12->m_isNaked )
  {
    LOBYTE(v6) = v29 == 0;
    v30 = hkgpCgoInternal::processVertex(this, pcfg, &pcfg->m_edgeVertices[v6], &vertexOut);
    m_edgeVertices = pcfg->m_edgeVertices;
    v32 = &pcfg->m_edgeVertices[1];
  }
  else
  {
    m_edgeVertices = pcfg->m_edgeVertices;
    if ( *(_DWORD *)&pcfg->m_action & 1 | ((*(_DWORD *)&pcfg->m_action & 2) != 0) )
    {
LABEL_67:
      v32 = &pcfg->m_edgeVertices[1];
      goto LABEL_68;
    }
    hkgpCgoInternal::solveVertex(this, pcfg, this->m_config.m_project.m_bool != 0, pcfg->m_edgeVertices);
    v32 = &pcfg->m_edgeVertices[1];
    hkgpCgoInternal::solveVertex(this, pcfg, this->m_config.m_project.m_bool != 0, &pcfg->m_edgeVertices[1]);
    if ( this->m_config.m_useLegacySolver.m_bool )
    {
      m_solverAccuracy = this->m_config.m_solverAccuracy;
      m_minConvergence_low = (__m128)LODWORD(this->m_config.m_minConvergence);
      v66 = &vertexOut.m_error.m_real.m128_u64[1];
      vertexOut.m_error.m_real.m128_u64[0] = 0x8000008000000000ui64;
      LODWORD(v67) = _mm_shuffle_ps(m_minConvergence_low, m_minConvergence_low, 0).m128_u32[0];
      v103 = m_solverAccuracy;
      vertexOut.m_vertex.m_quad.m128_u64[1] = (unsigned __int64)&vertexOut.m_error.m_real.m128_u64[1];
      if ( m_solverAccuracy + 2 > 128 )
      {
        v68 = m_solverAccuracy + 2;
        if ( m_solverAccuracy + 2 < 256 )
          v68 = 256;
        hkArrayUtil::_reserve(
          &result,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&vertexOut.m_vertex.m_quad.m128_u64[1],
          v68,
          4);
        v66 = (unsigned __int64 *)vertexOut.m_vertex.m_quad.m128_u64[1];
      }
      m_quad = query.m_quad;
      vertexOut.m_error.m_real.m128_i32[0] = m_solverAccuracy + 2;
      v70 = 0i64;
      result.m_enum = HK_SUCCESS;
      if ( m_solverAccuracy > 0 )
      {
        v71 = m_solverAccuracy + 1;
        v72 = 0i64;
        v73 = m_solverAccuracy + 1;
        v72.m128_f32[0] = (float)(m_solverAccuracy + 1);
        v74 = _mm_shuffle_ps(v72, v72, 0);
        while ( 1 )
        {
          v75.m_real = (__m128)pcfg->m_maxError;
          *(_DWORD *)v66 = v70.m128_i32[0];
          v76 = 0;
          v77 = 1;
          *(_DWORD *)(vertexOut.m_vertex.m_quad.m128_u64[1] + 4 * v73) = m_quad.m128_i32[0];
          v78 = _mm_div_ps(query.m_quad, v74);
          if ( v71 <= 1 )
            break;
          v79 = _mm_sub_ps(m_quad, v70);
          v80 = 4i64;
          do
          {
            v81 = 0i64;
            v81.m128_f32[0] = (float)v77;
            v82 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), v78), v79), v70);
            v83 = (hkArray<int,hkContainerHeapAllocator>)_mm_add_ps(
                                                           _mm_mul_ps(
                                                             _mm_sub_ps(
                                                               pcfg->m_edgeVertices[1].m_quad,
                                                               pcfg->m_edgeVertices[0].m_quad),
                                                             v82),
                                                           pcfg->m_edgeVertices[0].m_quad);
            *(_DWORD *)(v80 + vertexOut.m_vertex.m_quad.m128_u64[1]) = v82.m128_i32[0];
            v84 = this->m_config.m_project.m_bool != 0;
            output = v83;
            if ( hkgpCgoInternal::solveVertex(this, pcfg, v84, (hkVector4f *)&output) )
              v76 = v77;
            ++v77;
            v80 += 4i64;
          }
          while ( v77 < v71 );
          if ( !v76 || (float)(v75.m_real.m128_f32[0] - pcfg->m_maxError.m_real.m128_f32[0]) <= v67 )
            break;
          v66 = (unsigned __int64 *)vertexOut.m_vertex.m_quad.m128_u64[1];
          v85 = (__m128)*(unsigned int *)(vertexOut.m_vertex.m_quad.m128_u64[1] + 4i64 * (v76 - 1));
          v70 = _mm_shuffle_ps(v85, v85, 0);
          v86 = (__m128)*(unsigned int *)(vertexOut.m_vertex.m_quad.m128_u64[1] + 4i64 * (v76 + 1));
          v87 = ++result.m_enum < v103;
          v73 = v71;
          m_quad = _mm_shuffle_ps(v86, v86, 0);
          if ( !v87 )
            goto LABEL_61;
        }
        v66 = (unsigned __int64 *)vertexOut.m_vertex.m_quad.m128_u64[1];
      }
LABEL_61:
      vertexOut.m_error.m_real.m128_i32[0] = 0;
      if ( vertexOut.m_error.m_real.m128_i32[1] >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v66,
          4 * vertexOut.m_error.m_real.m128_i32[1]);
      goto LABEL_66;
    }
    v33 = m_edgeVertices->m_quad;
    v34 = this->m_config.m_solverAccuracy;
    v35 = pcfg->m_planes.m_data;
    m_size = pcfg->m_planes.m_size;
    v37 = 1;
    v38 = _mm_sub_ps(v32->m_quad, m_edgeVertices->m_quad);
    v39 = _mm_mul_ps(_mm_add_ps(m_edgeVertices->m_quad, v32->m_quad), (__m128)xmmword_141A711B0);
    v40 = _mm_mul_ps(v38, v38);
    output = (hkArray<int,hkContainerHeapAllocator>)v39;
    v41 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
            _mm_shuffle_ps(v40, v40, 170));
    v42 = _mm_rsqrt_ps(v41);
    v43 = _mm_andnot_ps(
            _mm_cmple_ps(v41, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v42, v41), v42)),
              _mm_mul_ps(*(__m128 *)_xmm, v42)));
    v44 = _mm_mul_ps(v38, v43);
    v45 = _mm_mul_ps(v43, v41);
    if ( v34 >= 1 )
    {
      do
      {
        v46 = g_vectorfConstants[0];
        if ( m_size > 0 )
        {
          v47 = v35;
          v48 = m_size;
          do
          {
            v49 = v47->m_quad;
            ++v47;
            v50 = _mm_mul_ps(v49, v39);
            v51 = _mm_shuffle_ps(v50, _mm_unpackhi_ps(v50, v47[-1].m_quad), 196);
            v52 = _mm_add_ps(_mm_shuffle_ps(v51, v51, 78), v51);
            v53 = _mm_add_ps(_mm_shuffle_ps(v52, v52, 177), v52);
            v54 = _mm_mul_ps(v53, v53);
            v55 = _mm_cmplt_ps(v46, v54);
            v46 = _mm_or_ps(_mm_and_ps(v55, v54), _mm_andnot_ps(v55, v46));
            --v48;
          }
          while ( v48 );
        }
        v56 = _mm_mul_ps(_mm_sub_ps(v39, v33), v44);
        v57 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
                _mm_shuffle_ps(v56, v56, 170));
        v58 = _mm_cmplt_ps(v57, v45);
        v59 = _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v58, v57), _mm_andnot_ps(v58, v45)));
        v60 = 0i64;
        v60.m128_f32[0] = (float)v37;
        x.m_quad = _mm_sub_ps(
                     v39,
                     _mm_mul_ps(
                       _mm_div_ps(query.m_quad, _mm_shuffle_ps(v60, v60, 0)),
                       _mm_sub_ps(v39, _mm_add_ps(_mm_mul_ps(v59, v44), v33))));
        projectOnPlanes(&pcfg->m_planes, &x, &x);
        v39 = x.m_quad;
        ++v37;
      }
      while ( v37 <= v34 );
      output = (hkArray<int,hkContainerHeapAllocator>)x.m_quad;
    }
    if ( v34 > 0 )
    {
      do
        projectOnPlanes(&pcfg->m_planes, (hkVector4f *)&output, (hkVector4f *)&output);
      while ( v61 != 1 );
    }
    v30 = hkgpCgoInternal::processVertex(this, pcfg, (hkVector4f *)&output, &vertexOut);
  }
  if ( v30 )
  {
    v62.m_quad = (__m128)vertexOut.m_vertex;
    v63.m_real = (__m128)vertexOut.m_error;
    pcfg->m_action = (hkgpCgoInternal::Action)((unsigned int)v104 & 0xFFFFFFFC | 2);
    pcfg->m_vertex = (hkVector4f)v62.m_quad;
    pcfg->m_maxError = (hkSimdFloat32)v63.m_real;
  }
LABEL_68:
  v90 = (float *)v104;
  p_m_vertex = &v104->m_vertex;
  v104->m_vertex = pcfg->m_vertex;
  *((_DWORD *)v90 + 8) = pcfg->m_maxError;
  m_action = pcfg->m_action;
  v90[11] = NAN;
  *((hkgpCgoInternal::Action *)v90 + 9) = m_action;
  if ( this->m_config.m_decimateComponents.m_bool )
  {
    v93 = this->m_sets.m_data[*(int *)(*(_QWORD *)v90 + 72i64)].m_error;
    if ( v93 < v90[8] )
    {
      *((_DWORD *)v90 + 9) |= 2u;
      v90[8] = v93;
      p_m_vertex->m_quad = _mm_add_ps(
                             _mm_mul_ps(_mm_sub_ps(v32->m_quad, m_edgeVertices->m_quad), (__m128)xmmword_141A711B0),
                             m_edgeVertices->m_quad);
    }
  }
  p_m_vertex->m_quad = _mm_shuffle_ps(
                         p_m_vertex->m_quad,
                         _mm_unpackhi_ps(p_m_vertex->m_quad, pcfg->m_vertexW.m_real),
                         196);
  if ( v90[8] < 3.40282e38
    && hkgpCgoInternal::checkTwist(this, pcfg->m_edgeIndices[0], pcfg->m_edgeIndices[1], p_m_vertex, &pcfg->m_ring) )
  {
    p_m_lock = &this->m_lock;
    EnterCriticalSection(&this->m_lock.m_section);
    p_m_edgesTree = &this->m_edgesTree;
    if ( !p_m_edgesTree->m_free )
      hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::preAllocateNodes(p_m_edgesTree, 16);
    m_free = p_m_edgesTree->m_free;
    v97 = p_m_edgesTree->m_nodes.m_data;
    v98 = (hkVector4f *)v104;
    p_m_edgesTree->m_free = p_m_edgesTree->m_nodes.m_data[m_free].m_parent;
    v97[m_free].m_value = (hkgpCgoInternal::EdgeInfo *)v98;
    hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::insertNode(p_m_edgesTree, m_free);
    ++p_m_edgesTree->m_size;
    v98[2].m_quad.m128_i32[2] = m_free;
    LeaveCriticalSection(&p_m_lock->m_section);
  }
}

// File Line: 820
// RVA: 0xCE7B80
void __fastcall hkgpCgoInternal::updatePlane(hkgpCgoInternal *this, hkgpIndexedMeshDefinitions::Triangle *triangle)
{
  hkVector4f *m_data; // r9
  hkgpCgoInternal::TriangleInfo *v3; // r11
  __m128 m_quad; // xmm6
  bool v5; // r10
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm7
  __m128 v9; // xmm7
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm2
  __m128 v13; // xmm7
  __m128 v14; // xmm6
  __m128 v15; // xmm7

  m_data = this->m_geometry->m_vertices.m_data;
  v3 = &this->m_triangles.m_data[(__int64)SLODWORD(triangle->m_index)];
  m_quad = m_data[SLODWORD(triangle->m_vertices[0]->m_index)].m_quad;
  v5 = this->m_config.m_inverseOrientation.m_bool != 0;
  v6 = _mm_sub_ps(m_data[SLODWORD(triangle->m_vertices[1]->m_index)].m_quad, m_quad);
  v7 = _mm_sub_ps(m_data[SLODWORD(triangle->m_vertices[2]->m_index)].m_quad, m_quad);
  v8 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v6), _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v7));
  v9 = _mm_shuffle_ps(v8, v8, 201);
  v10 = _mm_mul_ps(v9, v9);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_rsqrt_ps(v11);
  v13 = _mm_mul_ps(
          v9,
          _mm_andnot_ps(
            _mm_cmple_ps(v11, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
              _mm_mul_ps(*(__m128 *)_xmm, v12))));
  v14 = _mm_mul_ps(m_quad, v13);
  v15 = _mm_shuffle_ps(
          v13,
          _mm_unpackhi_ps(
            v13,
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                _mm_shuffle_ps(v14, v14, 170)))),
          196);
  v3->m_plane.m_quad = v15;
  if ( v5 )
    v3->m_plane.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v15);
}

// File Line: 829
// RVA: 0xCE7CB0
void __fastcall hkgpCgoInternal::computeError(
        hkgpCgoInternal *this,
        hkArray<hkVector4f,hkContainerHeapAllocator> *planes,
        hkVector4f *vertex,
        hkSimdFloat32 *value)
{
  __m128 m_quad; // xmm6
  __int64 m_size; // r8
  int v7; // edx
  __int64 v8; // rax
  __m128 v9; // xmm5
  __m128 v10; // xmm7
  hkVector4f *v11; // rcx
  unsigned __int64 v12; // rax
  __m128 v13; // xmm0
  __m128 v14; // xmm4
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm4
  __m128 v20; // xmm0
  __m128 v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm4
  hkVector4f *v25; // rax
  __int64 v26; // rcx
  __m128 v27; // xmm2
  __m128 v28; // xmm2
  __m128 v29; // xmm2
  __m128 v30; // xmm0
  __m128 v31; // xmm1
  __m128 v32; // xmm1

  m_quad = vertex->m_quad;
  m_size = planes->m_size;
  v7 = 0;
  v8 = (int)m_size - 3;
  v9 = 0i64;
  v10 = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, query.m_quad), 196);
  if ( v8 > 0 )
  {
    v11 = planes->m_data + 2;
    v12 = ((unsigned __int64)(v8 - 1) >> 2) + 1;
    v7 = 4 * v12;
    do
    {
      v13 = _mm_mul_ps(v11[-1].m_quad, v10);
      v14 = _mm_mul_ps(v11[-2].m_quad, v10);
      v15 = _mm_mul_ps(v11->m_quad, v10);
      v16 = v11[1].m_quad;
      v11 += 4;
      v17 = _mm_mul_ps(v16, v10);
      v18 = _mm_shuffle_ps(v14, v13, 68);
      v19 = _mm_shuffle_ps(v14, v13, 238);
      v20 = _mm_shuffle_ps(v15, v17, 68);
      v21 = _mm_shuffle_ps(v15, v17, 238);
      v22 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v18, v20, 221), _mm_shuffle_ps(v18, v20, 136)),
              _mm_add_ps(_mm_shuffle_ps(v19, v21, 221), _mm_shuffle_ps(v19, v21, 136)));
      v9 = _mm_max_ps(v9, _mm_mul_ps(v22, v22));
      --v12;
    }
    while ( v12 );
  }
  v23 = _mm_max_ps(_mm_shuffle_ps(v9, v9, 78), v9);
  v24 = _mm_max_ps(v23, _mm_shuffle_ps(v23, v23, 177));
  if ( v7 < m_size )
  {
    v25 = &planes->m_data[v7];
    v26 = m_size - v7;
    do
    {
      v27 = v25->m_quad;
      ++v25;
      v28 = _mm_mul_ps(v27, m_quad);
      v29 = _mm_shuffle_ps(v28, _mm_unpackhi_ps(v28, v25[-1].m_quad), 196);
      v30 = _mm_add_ps(_mm_shuffle_ps(v29, v29, 78), v29);
      v31 = _mm_add_ps(_mm_shuffle_ps(v30, v30, 177), v30);
      v24 = _mm_max_ps(v24, _mm_mul_ps(v31, v31));
      --v26;
    }
    while ( v26 );
  }
  v32 = _mm_rsqrt_ps(v24);
  value->m_real = _mm_andnot_ps(
                    _mm_cmple_ps(v24, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v24), v32)),
                        _mm_mul_ps(*(__m128 *)_xmm, v32)),
                      v24));
}

// File Line: 854
// RVA: 0xCE7E30
char __fastcall hkgpCgoInternal::projectVertex(
        hkgpCgoInternal *this,
        hkArray<hkVector4f,hkContainerHeapAllocator> *planes,
        hkVector4f *vertex)
{
  int m_size; // r11d
  float v4; // xmm5_4
  int v5; // r9d
  float v7; // xmm4_4
  __int64 v8; // rcx
  __m128 m_quad; // xmm2
  char v10; // dl
  hkVector4f *m_data; // rax
  __m128 v12; // xmm1
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  __m128 v16; // xmm1
  __m128 v17; // xmm1
  float v18; // xmm3_4

  m_size = planes->m_size;
  v4 = 3.40282e38;
  v5 = 0;
  LODWORD(v7) = _mm_shuffle_ps(
                  (__m128)LODWORD(this->m_config.m_minDistance),
                  (__m128)LODWORD(this->m_config.m_minDistance),
                  0).m128_u32[0];
  if ( m_size <= 0 )
    return 0;
  while ( 1 )
  {
    v8 = planes->m_size;
    m_quad = vertex->m_quad;
    v10 = 0;
    if ( v8 <= 0 )
      break;
    m_data = planes->m_data;
    do
    {
      v12 = _mm_mul_ps(m_data->m_quad, m_quad);
      v13 = _mm_shuffle_ps(v12, _mm_unpackhi_ps(v12, m_data->m_quad), 196);
      v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
      v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14);
      if ( v15.m128_f32[0] < v7 )
      {
        v10 = 1;
        m_quad = _mm_sub_ps(m_quad, _mm_mul_ps(m_data->m_quad, v15));
      }
      ++m_data;
      --v8;
    }
    while ( v8 );
    if ( !v10 )
      break;
    v16 = _mm_sub_ps(vertex->m_quad, m_quad);
    v17 = _mm_mul_ps(v16, v16);
    v18 = (float)(_mm_shuffle_ps(v17, v17, 85).m128_f32[0] + _mm_shuffle_ps(v17, v17, 0).m128_f32[0])
        + _mm_shuffle_ps(v17, v17, 170).m128_f32[0];
    if ( v18 <= v4 )
    {
      ++v5;
      v4 = v18;
      *vertex = (hkVector4f)m_quad;
      if ( v5 < m_size )
        continue;
    }
    return 0;
  }
  return 1;
}

// File Line: 883
// RVA: 0xCE7F00
bool __fastcall hkgpCgoInternal::processVertex(
        hkgpCgoInternal *this,
        hkgpCgoInternal::ProcessConfig *pcfg,
        hkVector4f *vertexIn,
        hkgpCgoInternal::ProcessedVertex *vertexOut)
{
  __m128 v7; // xmm7
  __m128 m_minDistance_low; // xmm8
  __m128 m_maxDistance_low; // xmm9
  __m128 m_quad; // xmm1
  __m128 v11; // xmm8
  __m128 v12; // xmm9
  bool result; // al
  __m128 v14; // xmm4
  __m128 v15; // xmm6
  __m128 v16; // xmm4
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // xmm10
  __m128 v25; // xmm6
  __m128 m_real; // xmm2
  hkSimdFloat32 v27; // xmm3
  __m128 v28; // xmm3
  __m128 v29; // xmm0
  __m128 v30; // xmm4
  __m128 v31; // xmm8
  __m128 v32; // xmm4
  __m128 v33; // xmm1
  __m128 v34; // xmm0
  __m128 v35; // xmm7
  __m128 v36; // xmm1
  __m128 v37; // xmm3
  __m128 v38; // xmm1
  __m128 v39; // xmm2
  __m128 v40; // xmm1
  __m128 v41; // xmm9
  __m128 v42; // xmm0
  __m128 v43; // xmm10
  __m128 v44; // xmm8
  hkSimdFloat32 value; // [rsp+20h] [rbp-68h] BYREF

  v7 = _mm_shuffle_ps((__m128)LODWORD(this->m_config.m_maxShrink), (__m128)LODWORD(this->m_config.m_maxShrink), 0);
  m_minDistance_low = (__m128)LODWORD(this->m_config.m_minDistance);
  m_maxDistance_low = (__m128)LODWORD(this->m_config.m_maxDistance);
  vertexOut->m_error = pcfg->m_maxError;
  m_quad = vertexIn->m_quad;
  v11 = _mm_shuffle_ps(m_minDistance_low, m_minDistance_low, 0);
  v12 = _mm_shuffle_ps(m_maxDistance_low, m_maxDistance_low, 0);
  vertexOut->m_valid = 0;
  vertexOut->m_vertex.m_quad = m_quad;
  if ( !this->m_config.m_project.m_bool || (result = hkgpCgoInternal::checkInside(this, &pcfg->m_planes, vertexIn)) )
  {
    if ( !this->m_config.m_proportionalShrinking.m_bool && v7.m128_f32[0] != 0.0 )
    {
      v14 = pcfg->m_edgeVertices[0].m_quad;
      v15 = _mm_sub_ps(v14, vertexOut->m_vertex.m_quad);
      v16 = _mm_sub_ps(v14, pcfg->m_edgeVertices[1].m_quad);
      v17 = _mm_mul_ps(v16, v16);
      v18 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170));
      v19 = _mm_mul_ps(v15, v16);
      v20 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
              _mm_shuffle_ps(v19, v19, 170));
      v21 = _mm_rcp_ps(v18);
      v22 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v21, v18)), v21), v20);
      v23 = _mm_cmplt_ps(v22, query.m_quad);
      v24 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v22, v23), _mm_andnot_ps(v23, query.m_quad)));
      v25 = _mm_add_ps(_mm_sub_ps(v15, _mm_mul_ps(v24, v16)), vertexOut->m_vertex.m_quad);
      vertexOut->m_vertex.m_quad = _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_sub_ps(
                                         _mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, v24), 196),
                                         vertexOut->m_vertex.m_quad),
                                       v7),
                                     vertexOut->m_vertex.m_quad);
    }
    hkgpCgoInternal::computeError(this, &pcfg->m_planes, &vertexOut->m_vertex, &value);
    m_real = value.m_real;
    if ( this->m_config.m_useAccumulatedError.m_bool )
      m_real = _mm_add_ps(value.m_real, pcfg->m_vtxError.m_real);
    v27.m_real = (__m128)pcfg->m_maxError;
    switch ( this->m_config.m_semantic )
    {
      case VS_WEIGHT:
        v27.m_real = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v12, v11), pcfg->m_vertexW.m_real), v11);
        break;
      case VS_DISTANCE:
        v27.m_real = (__m128)pcfg->m_vertexW;
        break;
      case VS_FACTOR:
        m_real = _mm_mul_ps(m_real, pcfg->m_vertexW.m_real);
        break;
      case VS_OFFSET:
        m_real = _mm_add_ps(m_real, pcfg->m_vertexW.m_real);
        break;
    }
    v28 = _mm_min_ps(v27.m_real, pcfg->m_maxError.m_real);
    if ( m_real.m128_f32[0] < v28.m128_f32[0] )
    {
      vertexOut->m_error.m_real = m_real;
      vertexOut->m_valid = 1;
      if ( this->m_config.m_proportionalShrinking.m_bool )
      {
        if ( v7.m128_f32[0] != 0.0 )
        {
          v29 = _mm_rcp_ps(v28);
          v30 = pcfg->m_edgeVertices[0].m_quad;
          v31 = _mm_sub_ps(v30, vertexOut->m_vertex.m_quad);
          v32 = _mm_sub_ps(v30, pcfg->m_edgeVertices[1].m_quad);
          v33 = _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v28, v29)), v29), m_real), v7);
          v34 = _mm_cmplt_ps(v33, query.m_quad);
          v35 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v33, v34), _mm_andnot_ps(v34, query.m_quad)));
          v36 = _mm_mul_ps(v32, v32);
          v37 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                  _mm_shuffle_ps(v36, v36, 170));
          v38 = _mm_mul_ps(v31, v32);
          v39 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                  _mm_shuffle_ps(v38, v38, 170));
          v40 = _mm_rcp_ps(v37);
          v41 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v40, v37)), v40), v39);
          v42 = _mm_cmplt_ps(v41, query.m_quad);
          v43 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v41, v42), _mm_andnot_ps(v42, query.m_quad)));
          v44 = _mm_add_ps(_mm_sub_ps(v31, _mm_mul_ps(v43, v32)), vertexOut->m_vertex.m_quad);
          vertexOut->m_vertex.m_quad = _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_sub_ps(
                                             _mm_shuffle_ps(v44, _mm_unpackhi_ps(v44, v43), 196),
                                             vertexOut->m_vertex.m_quad),
                                           v35),
                                         vertexOut->m_vertex.m_quad);
        }
      }
    }
    return vertexOut->m_valid;
  }
  return result;
}

// File Line: 943
// RVA: 0xCE81F0
char __fastcall hkgpCgoInternal::checkTwist(
        hkgpCgoInternal *this,
        int index0,
        int index1,
        hkVector4f *vertex,
        hkArrayBase<hkgpCgoInternal::HTriangle> *ring)
{
  __m128i si128; // xmm6
  __int64 v6; // rbp
  __int64 m_size; // r12
  __m128 v12; // xmm9
  __m128i v13; // xmm7
  __m128 v14; // xmm2
  __m128i v15; // xmm6
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm2
  float v20; // xmm15_4
  hkgpCgoInternal::HTriangle *m_data; // r14
  hkVector4f *v22; // r11
  int v23; // r9d
  __int64 m_vertices; // r8
  __int64 v25; // rcx
  __int64 v26; // r10
  int v27; // edx
  __m128 m_quad; // xmm0
  __m128 v29; // xmm1
  __m128 v30; // xmm7
  __m128 v31; // xmm9
  __m128 v32; // xmm6
  __m128 v33; // xmm6
  __m128 v34; // xmm1
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  __m128 v37; // xmm0
  __m128 v38; // xmm6
  __m128 v39; // xmm5
  __m128 v40; // xmm5
  __m128 v41; // xmm1
  __m128 v42; // xmm3
  __m128 v43; // xmm2
  __m128 v44; // xmm4
  float m_minEdgeRatio; // xmm10_4
  __m128 v46; // xmm8
  __m128 v47; // xmm7
  __m128 v48; // xmm8
  __m128 v49; // xmm3
  __m128 v50; // xmm2
  __m128 v51; // xmm6
  __m128 v52; // xmm1
  __m128 v53; // xmm1
  __m128 v54; // xmm3
  __m128 v55; // xmm2
  __m128 v56; // xmm5
  __m128 v57; // xmm1
  __m128 v58; // xmm3
  __m128 v59; // xmm2
  __m128 v60; // xmm4
  __m128 v61; // xmm2
  __m128 v62; // xmm1
  __m128 v63; // xmm3
  __m128 v64; // xmm4
  float v65; // xmm0_4
  __m128 v66; // xmm2
  __m128 v67; // xmm11
  __m128 v68; // xmm9
  __m128 v69; // xmm11
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  __m128 v72; // xmm6
  __m128 v73; // xmm1
  __m128 v74; // xmm1
  __m128 v75; // xmm3
  __m128 v76; // xmm2
  __m128 v77; // xmm1
  __m128 v78; // xmm2
  __m128 v79; // xmm5
  __m128 v80; // xmm1
  __m128 v81; // xmm4
  __m128 v82; // xmm2
  __m128 v83; // xmm1
  __m128 v84; // xmm4
  __m128 v85; // xmm4
  __m128 v86; // xmm1
  float v87; // xmm2_4
  __m128 v89; // [rsp+0h] [rbp-128h]
  __m128 v90; // [rsp+10h] [rbp-118h]
  __m128 v91; // [rsp+20h] [rbp-108h]
  __m128 v92; // [rsp+30h] [rbp-F8h]
  __m128 v93; // [rsp+40h] [rbp-E8h]
  __m128 v94; // [rsp+50h] [rbp-D8h]
  unsigned int v95; // [rsp+130h] [rbp+8h]

  si128 = _mm_load_si128((const __m128i *)_xmm);
  v6 = 0i64;
  m_size = ring->m_size;
  v12 = _mm_add_ps((__m128)LODWORD(this->m_config.m_maxAngleDrift), *(__m128 *)_xmm);
  v13 = _mm_add_epi32(si128, si128);
  v14 = _mm_andnot_ps(*(__m128 *)_xmm, v12);
  v15 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(*(__m128 *)_xmm, v14)), si128));
  v16 = _mm_cvtepi32_ps(v15);
  v17 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v15, v13), (__m128i)0i64);
  v18 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v16, *(__m128 *)DP1_0), v14), _mm_mul_ps(v16, *(__m128 *)DP2)),
          _mm_mul_ps(v16, *(__m128 *)DP3));
  v19 = _mm_mul_ps(v18, v18);
  v95 = (_mm_andnot_ps(
           v17,
           _mm_add_ps(
             _mm_sub_ps(
               _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v19, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v19),
                     *(__m128 *)cosCoeff2_0),
                   v19),
                 v19),
               _mm_mul_ps(v19, *(__m128 *)_xmm)),
             *(__m128 *)_xmm)).m128_u32[0] | COERCE_UNSIGNED_INT(
                                               (float)((float)((float)((float)((float)((float)(v19.m128_f32[0]
                                                                                             * -0.00019515296)
                                                                                     + 0.0083321612)
                                                                             * v19.m128_f32[0])
                                                                     + -0.16666655)
                                                             * v19.m128_f32[0])
                                                     * v18.m128_f32[0])
                                             + v18.m128_f32[0]) & v17.m128_i32[0]) ^ (_mm_and_si128(
                                                                                        _mm_add_epi32(v13, v13),
                                                                                        v15).m128i_u32[0] << 29) ^ _xmm[0] & v12.m128_i32[0];
  v20 = fmax(_mm_shuffle_ps((__m128)v95, (__m128)v95, 0).m128_f32[0], 0.00000011920929);
  if ( m_size <= 0 )
    return 1;
  m_data = ring->m_data;
  v22 = this->m_geometry->m_vertices.m_data;
  while ( 1 )
  {
    v23 = 0;
    m_vertices = (__int64)m_data->m_triangle->m_vertices;
    v25 = 0i64;
    v26 = 3i64;
    do
    {
      v27 = *(_DWORD *)(*(_QWORD *)m_vertices + 16i64);
      m_quad = v22[v27].m_quad;
      *(__m128 *)((char *)&v92 + v25) = m_quad;
      *(__m128 *)((char *)&v89 + v25) = m_quad;
      if ( v27 == index0 || v27 == index1 )
      {
        ++v23;
        *(__m128 *)((char *)&v89 + v25) = vertex->m_quad;
      }
      m_vertices += 8i64;
      v25 += 16i64;
      --v26;
    }
    while ( v26 );
    if ( v23 == 1 )
    {
      v29 = _mm_sub_ps(v93, v92);
      v30 = _mm_sub_ps(v94, v92);
      v31 = _mm_sub_ps(v91, v89);
      v32 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v29), _mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v30));
      v33 = _mm_shuffle_ps(v32, v32, 201);
      v34 = _mm_mul_ps(v33, v33);
      v35 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
              _mm_shuffle_ps(v34, v34, 170));
      v36 = _mm_rsqrt_ps(v35);
      v37 = _mm_sub_ps(v90, v89);
      v38 = _mm_mul_ps(
              v33,
              _mm_andnot_ps(
                _mm_cmple_ps(v35, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v36, v35), v36)),
                  _mm_mul_ps(v36, *(__m128 *)_xmm))));
      v39 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v37), _mm_mul_ps(_mm_shuffle_ps(v37, v37, 201), v31));
      v40 = _mm_shuffle_ps(v39, v39, 201);
      v41 = _mm_mul_ps(v40, v40);
      v42 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
              _mm_shuffle_ps(v41, v41, 170));
      v43 = _mm_rsqrt_ps(v42);
      v44 = _mm_mul_ps(
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v42, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v43, v42), v43)),
                    _mm_mul_ps(v43, *(__m128 *)_xmm))),
                v40),
              v38);
      if ( (float)((float)(_mm_shuffle_ps(v44, v44, 85).m128_f32[0] + _mm_shuffle_ps(v44, v44, 0).m128_f32[0])
                 + _mm_shuffle_ps(v44, v44, 170).m128_f32[0]) < v20 )
        break;
      m_minEdgeRatio = this->m_config.m_minEdgeRatio;
      if ( m_minEdgeRatio > 0.0 )
      {
        v46 = _mm_sub_ps(v92, v93);
        v47 = _mm_mul_ps(v30, v30);
        v48 = _mm_mul_ps(v46, v46);
        v49 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
                _mm_shuffle_ps(v47, v47, 170));
        v50 = _mm_rsqrt_ps(v49);
        v51 = _mm_unpacklo_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v49, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v49), v50)),
                      _mm_mul_ps(v50, *(__m128 *)_xmm)),
                    v49)),
                aabbOut.m_quad);
        v52 = _mm_sub_ps(v93, v94);
        v53 = _mm_mul_ps(v52, v52);
        v54 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v53, v53, 85), _mm_shuffle_ps(v53, v53, 0)),
                _mm_shuffle_ps(v53, v53, 170));
        v55 = _mm_rsqrt_ps(v54);
        v56 = _mm_cmple_ps(v54, (__m128)0i64);
        v57 = _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v55, v54), v55)),
                  _mm_mul_ps(v55, *(__m128 *)_xmm)),
                v54);
        v58 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v48, v48, 85), _mm_shuffle_ps(v48, v48, 0)),
                _mm_shuffle_ps(v48, v48, 170));
        v59 = _mm_rsqrt_ps(v58);
        v60 = _mm_movelh_ps(
                _mm_unpacklo_ps(
                  _mm_andnot_ps(
                    _mm_cmple_ps(v58, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v59, v58), v59)),
                        _mm_mul_ps(v59, *(__m128 *)_xmm)),
                      v58)),
                  _mm_andnot_ps(v56, v57)),
                v51);
        v61 = _mm_shuffle_ps(v60, v60, 85);
        v62 = _mm_shuffle_ps(v60, v60, 0);
        v63 = _mm_shuffle_ps(v60, v60, 170);
        v64 = _mm_max_ps(v63, _mm_max_ps(v61, v62));
        v65 = fmin(v61.m128_f32[0], v62.m128_f32[0]);
        v66 = _mm_rcp_ps(v64);
        v67 = _mm_sub_ps(v89, v90);
        v68 = _mm_mul_ps(v31, v31);
        v69 = _mm_mul_ps(v67, v67);
        v48.m128_f32[0] = _mm_andnot_ps(
                            _mm_cmpeq_ps(v64, (__m128)0i64),
                            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v66, v64)), v66)).m128_f32[0]
                        * fmin(v63.m128_f32[0], v65);
        v70 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)),
                _mm_shuffle_ps(v68, v68, 170));
        v71 = _mm_rsqrt_ps(v70);
        v72 = _mm_unpacklo_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v70, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v71, v70), v71)),
                      _mm_mul_ps(v71, *(__m128 *)_xmm)),
                    v70)),
                aabbOut.m_quad);
        v73 = _mm_sub_ps(v90, v91);
        v74 = _mm_mul_ps(v73, v73);
        v75 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v74, v74, 85), _mm_shuffle_ps(v74, v74, 0)),
                _mm_shuffle_ps(v74, v74, 170));
        v76 = _mm_rsqrt_ps(v75);
        v77 = _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v76, v75), v76)),
                  _mm_mul_ps(v76, *(__m128 *)_xmm)),
                v75);
        v78 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v69, v69, 85), _mm_shuffle_ps(v69, v69, 0)),
                _mm_shuffle_ps(v69, v69, 170));
        v79 = _mm_andnot_ps(_mm_cmple_ps(v75, (__m128)0i64), v77);
        v80 = _mm_rsqrt_ps(v78);
        v81 = _mm_movelh_ps(
                _mm_unpacklo_ps(
                  _mm_andnot_ps(
                    _mm_cmple_ps(v78, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v80, v78), v80)),
                        _mm_mul_ps(v80, *(__m128 *)_xmm)),
                      v78)),
                  v79),
                v72);
        v82 = _mm_shuffle_ps(v81, v81, 85);
        v83 = _mm_shuffle_ps(v81, v81, 0);
        v84 = _mm_shuffle_ps(v81, v81, 170);
        v75.m128_f32[0] = fmin(v84.m128_f32[0], fmin(v82.m128_f32[0], v83.m128_f32[0]));
        v85 = _mm_max_ps(v84, _mm_max_ps(v82, v83));
        v86 = _mm_rcp_ps(v85);
        v87 = _mm_andnot_ps(
                _mm_cmpeq_ps(v85, (__m128)0i64),
                _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v86, v85)), v86)).m128_f32[0]
            * v75.m128_f32[0];
        if ( v87 < v48.m128_f32[0] && v87 < m_minEdgeRatio )
          break;
      }
    }
    ++v6;
    ++m_data;
    if ( v6 >= m_size )
      return 1;
  }
  return 0;
}    }
    ++v6;
    ++m_data;
    if ( v6 >= m_size )
      return 1;
  }
  return 0;
}

// File Line: 998
// RVA: 0xCE8820
char __fastcall hkgpCgoInternal::checkInside(
        hkgpCgoInternal *this,
        hkArray<hkVector4f,hkContainerHeapAllocator> *planes,
        hkVector4f *vertex)
{
  __int64 m_size; // r11
  __m128 m_quad; // xmm6
  int v5; // r8d
  __int64 v7; // rdx
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  hkVector4f *v10; // rcx
  __m128 v11; // xmm0
  __m128 v12; // xmm4
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm4
  __m128 v17; // xmm0
  __m128 v18; // xmm3
  __int64 v19; // rcx
  hkVector4f *i; // rax
  __m128 v21; // xmm2
  __m128 v22; // xmm2
  __m128 v23; // xmm1

  m_size = planes->m_size;
  m_quad = vertex->m_quad;
  v5 = 0;
  v7 = 0i64;
  v8 = _mm_shuffle_ps((__m128)LODWORD(this->m_config.m_minDistance), (__m128)LODWORD(this->m_config.m_minDistance), 0);
  v9 = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, query.m_quad), 196);
  if ( (int)m_size - 3 <= 0 )
  {
LABEL_5:
    v19 = v5;
    if ( v5 >= m_size )
      return 1;
    for ( i = &planes->m_data[v5]; ; ++i )
    {
      v21 = _mm_mul_ps(i->m_quad, v9);
      v22 = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, i->m_quad), 196);
      v23 = _mm_add_ps(_mm_shuffle_ps(v22, v22, 78), v22);
      if ( (float)(_mm_shuffle_ps(v23, v23, 177).m128_f32[0] + v23.m128_f32[0]) < v8.m128_f32[0] )
        break;
      if ( ++v19 >= m_size )
        return 1;
    }
  }
  else
  {
    v10 = planes->m_data + 2;
    while ( 1 )
    {
      v11 = _mm_mul_ps(v10[-1].m_quad, v9);
      v12 = _mm_mul_ps(v10[-2].m_quad, v9);
      v13 = _mm_mul_ps(v10->m_quad, v9);
      v14 = _mm_mul_ps(v10[1].m_quad, v9);
      v15 = _mm_shuffle_ps(v12, v11, 68);
      v16 = _mm_shuffle_ps(v12, v11, 238);
      v17 = _mm_shuffle_ps(v13, v14, 68);
      v18 = _mm_shuffle_ps(v13, v14, 238);
      if ( _mm_movemask_ps(
             _mm_cmplt_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v15, v17, 221), _mm_shuffle_ps(v15, v17, 136)),
                 _mm_add_ps(_mm_shuffle_ps(v16, v18, 221), _mm_shuffle_ps(v16, v18, 136))),
               v8)) )
      {
        break;
      }
      v7 += 4i64;
      v5 += 4;
      v10 += 4;
      if ( v7 >= (int)m_size - 3 )
        goto LABEL_5;
    }
  }
  return 0;
}

// File Line: 1019
// RVA: 0xCE89E0
char __fastcall hkgpCgoInternal::collapseEdge(hkgpCgoInternal *this, hkgpCgoInternal::EdgeInfo *e)
{
  hkOstream *v4; // rax
  hkgpCgo::Tracker *m_tracker; // r10
  __int64 m_index; // rdx
  __int64 m_index_low; // rcx
  hkgpCgoInternal::VertexInfo *m_data; // rax
  hkgpCgoInternal::VertexInfo *v9; // r14
  __int64 v10; // r13
  hkgpCgoInternal::VertexInfo *v11; // rdi
  hkgpCgoInternal::ICustomMetric *m_cstMetric; // rcx
  int m_capacityAndFlags; // r8d
  int v15; // r8d
  int v16; // r8d
  hkVector4f *p_m_vertex; // r14
  int v18; // r15d
  __int64 v19; // r14
  hkgpIndexedMeshDefinitions::Edge m_edge; // xmm0
  hkStreamWriter *v21; // rax
  bool v22; // zf
  int *v23; // rdx
  hkgpCgoInternal::TriangleInfo *v24; // r10
  int m_size; // r11d
  __int64 m_cid; // r9
  int *v27; // rdx
  __int64 v28; // r8
  __int64 v29; // rax
  __int64 v30; // rax
  int v31; // r8d
  __int64 v32; // rdx
  hkgpCgo::Tracker *v33; // rcx
  hkgpCgo::Tracker *v34; // rcx
  hkArray<int,hkContainerHeapAllocator> v35; // [rsp+30h] [rbp-D0h] BYREF
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> output; // [rsp+40h] [rbp-C0h] BYREF
  hkErrStream v37; // [rsp+50h] [rbp-B0h] BYREF
  hkgpIndexedMeshDefinitions::Edge v38; // [rsp+70h] [rbp-90h] BYREF
  char buf[512]; // [rsp+80h] [rbp-80h] BYREF
  unsigned int index1; // [rsp+2C8h] [rbp+1C8h]
  int index0; // [rsp+2D0h] [rbp+1D0h]

  if ( (*(_BYTE *)&e->m_action & 1) != 0 )
  {
    hkErrStream::hkErrStream(&v37, buf, 512);
    v4 = hkOstream::operator<<(&v37, "Flip edge ");
    hkOstream::operator<<(v4, e->m_error);
    hkError::messageReport(0, buf, 0i64, 0);
    hkOstream::~hkOstream(&v37);
    m_tracker = this->m_config.m_tracker;
    if ( m_tracker )
      m_tracker->vfptr->edgeFlip(
        this->m_config.m_tracker,
        e->m_edge.m_triangle->m_vertices[e->m_edge.m_index]->m_index,
        e->m_edge.m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)e->m_edge.m_index)) & 3]->m_index);
    hkgpCgoInternal::flipEdge(this, e);
  }
  if ( (*(_BYTE *)&e->m_action & 2) == 0 )
    return 1;
  m_index = (int)e->m_edge.m_index;
  index0 = e->m_edge.m_triangle->m_vertices[m_index]->m_index;
  m_index_low = SLODWORD(e->m_edge.m_triangle->m_vertices[(9i64 >> (2 * (unsigned __int8)m_index)) & 3]->m_index);
  m_data = this->m_vertices.m_data;
  output.m_capacityAndFlags = 0x80000000;
  v9 = &m_data[(__int64)index0];
  index1 = m_index_low;
  v10 = m_index_low;
  v11 = &m_data[m_index_low];
  output.m_data = 0i64;
  output.m_size = 0;
  computeUnionOfSortedArray_hkgpCgoInternal::HTriangle_(&v9->m_ring, &v11->m_ring, &output);
  v35.m_data = 0i64;
  v35.m_size = 0;
  v35.m_capacityAndFlags = 0x80000000;
  computeUnionOfSortedArray_int_(&v9->m_planes, &v11->m_planes, &v35);
  m_cstMetric = this->m_cstMetric;
  if ( (!m_cstMetric || m_cstMetric->vfptr->canCollapse(m_cstMetric, e, &output))
    && (this->m_cstMetric || hkgpCgoInternal::checkTwist(this, index0, index1, &e->m_vertex, &output)) )
  {
    if ( this->m_config.m_buildClusters.m_bool )
    {
      hkArrayBase<unsigned int>::_append(
        (hkArrayBase<unsigned int> *)&v11->m_cluster,
        &hkContainerHeapAllocator::s_alloc,
        (char *)v9->m_cluster.m_data,
        v9->m_cluster.m_size);
      m_capacityAndFlags = v9->m_cluster.m_capacityAndFlags;
      v9->m_cluster.m_size = 0;
      if ( m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v9->m_cluster.m_data,
          4 * m_capacityAndFlags);
      v9->m_cluster.m_data = 0i64;
      v9->m_cluster.m_capacityAndFlags = 0x80000000;
    }
    v11->m_isFixed |= v9->m_isFixed;
    v11->m_error = e->m_error;
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v11,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v35);
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v11->m_ring,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&output);
    v15 = v9->m_ring.m_capacityAndFlags;
    v9->m_ring.m_size = 0;
    if ( v15 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v9->m_ring.m_data, 8 * v15);
    v9->m_ring.m_data = 0i64;
    v9->m_ring.m_capacityAndFlags = 0x80000000;
    v16 = v9->m_planes.m_capacityAndFlags;
    v9->m_planes.m_size = 0;
    if ( v16 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v9->m_planes.m_data, 4 * v16);
    v9->m_planes.m_data = 0i64;
    v9->m_planes.m_capacityAndFlags = 0x80000000;
    p_m_vertex = &e->m_vertex;
    this->m_geometry->m_vertices.m_data[v10] = e->m_vertex;
    v18 = 0;
    if ( v11->m_ring.m_size > 0 )
    {
      v19 = 0i64;
      do
      {
        hkgpCgoInternal::updatePlane(this, v11->m_ring.m_data[v19].m_triangle);
        ++v18;
        ++v19;
      }
      while ( v18 < v11->m_ring.m_size );
      p_m_vertex = &e->m_vertex;
    }
    m_edge = e->m_edge;
    v37.vfptr = (hkBaseObjectVtbl *)&hkgpCgoInternal::ICollapse::`vftable;
    v21 = 0i64;
    v38 = m_edge;
    v22 = this->m_config.m_buildClusters.m_bool == 0;
    *(_QWORD *)&v37.m_memSizeAndFlags = this;
    if ( !v22 )
      v21 = (hkStreamWriter *)v11;
    v37.m_writer.m_pntr = v21;
    hkgpIndexedMesh::collapseEdge(&this->m_topology, &v38, 0i64, (hkgpIndexedMesh::IEdgeCollapse *)&v37);
    if ( this->m_config.m_buildClusters.m_bool )
    {
      v23 = v11->m_cluster.m_data;
      v24 = this->m_triangles.m_data;
      m_size = v11->m_cluster.m_size;
      m_cid = (unsigned int)v24[(__int64)*v23].m_cid;
      if ( m_size > 1 )
      {
        v27 = v23 + 1;
        v28 = (unsigned int)(m_size - 1);
        do
        {
          v29 = *v27++;
          v30 = v29 << 6;
          if ( *(int *)((char *)&v24->m_planes[3] + v30) < (int)m_cid )
            m_cid = *(unsigned int *)((char *)&v24->m_planes[3] + v30);
          --v28;
        }
        while ( v28 );
      }
      v31 = 0;
      if ( m_size > 0 )
      {
        v32 = 0i64;
        do
        {
          ++v31;
          this->m_triangles.m_data[(__int64)v11->m_cluster.m_data[v32++]].m_cid = m_cid;
        }
        while ( v31 < v11->m_cluster.m_size );
      }
      v33 = this->m_config.m_tracker;
      if ( v33 )
        v33->vfptr->setClusterId(v33, v11->m_cluster.m_data, v11->m_cluster.m_size, m_cid);
    }
    v34 = this->m_config.m_tracker;
    if ( v34 )
      ((void (__fastcall *)(hkgpCgo::Tracker *, _QWORD, _QWORD, hkVector4f *, _DWORD))v34->vfptr->edgeCollapse)(
        v34,
        (unsigned int)index0,
        index1,
        p_m_vertex,
        LODWORD(e->m_error));
    v35.m_size = 0;
    v37.vfptr = (hkBaseObjectVtbl *)&hkgpIndexedMesh::IVertexRemoval::`vftable;
    if ( v35.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v35.m_data,
        4 * v35.m_capacityAndFlags);
    v35.m_data = 0i64;
    v35.m_capacityAndFlags = 0x80000000;
    output.m_size = 0;
    if ( output.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        output.m_data,
        8 * output.m_capacityAndFlags);
    return 1;
  }
  hkgpCgoInternal::invalidateEdgeInfo(this, e);
  v35.m_size = 0;
  if ( v35.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v35.m_data,
      4 * v35.m_capacityAndFlags);
  v35.m_data = 0i64;
  v35.m_capacityAndFlags = 0x80000000;
  output.m_size = 0;
  if ( output.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      output.m_data,
      8 * output.m_capacityAndFlags);
  return 0;
}    &hkContainerHeapAllocator::s_alloc,
      output.m_data,
      8 * output.m_capacityAndFlags);
  return 0;
}

// File Line: 1115
// RVA: 0xCE8F40
void __fastcall hkgpCgoInternal::flipEdge(hkgpCgoInternal *this, hkgpCgoInternal::EdgeInfo *e)
{
  __int64 v2; // rax
  char v4; // r14
  __int64 v5; // rsi
  unsigned __int64 v7; // rdi
  __int64 v8; // r15
  hkgpCgoInternal::EdgeInfo *v9; // rax
  hkgpCgoInternal::EdgeInfo *v10; // r13
  hkgpCgoInternal::EdgeInfo *v11; // rax
  hkgpCgoInternal::VertexInfo *m_data; // r9
  __int64 v13; // r8
  hkgpIndexedMeshDefinitions::Vertex *v14; // rax
  hkgpIndexedMeshDefinitions::Edge *v15; // rax
  __int64 v16; // rdi
  hkgpIndexedMeshDefinitions::Triangle *v17; // r12
  char *v18; // r15
  hkgpIndexedMeshDefinitions::Triangle *v19; // r14
  __int64 v20; // rsi
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *v21; // r15
  __int64 m_size; // r8
  int v23; // edx
  __int64 v24; // rcx
  hkgpCgoInternal::HTriangle *v25; // rax
  int v26; // r9d
  __int64 v27; // rdx
  int v28; // r9d
  __int64 v29; // rcx
  __int64 v30; // rax
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *v31; // r14
  int v32; // edx
  __int64 v33; // r8
  __int64 v34; // rcx
  hkgpCgoInternal::HTriangle *v35; // rax
  int v36; // r9d
  __int64 v37; // rdx
  int v38; // r9d
  __int64 v39; // rcx
  __int64 v40; // rax
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *v41; // r13
  hkgpCgoInternal::HTriangle *v42; // rdx
  hkgpCgoInternal::HTriangle *v43; // rdx
  int v44; // r8d
  int v45; // r8d
  int v46; // esi
  __int64 v47; // rdi
  hkgpIndexedMeshDefinitions::Edge m_edge; // [rsp+20h] [rbp-79h] BYREF
  hkgpIndexedMeshDefinitions::Edge v49; // [rsp+30h] [rbp-69h]
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> v50; // [rsp+40h] [rbp-59h] BYREF
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> b; // [rsp+50h] [rbp-49h] BYREF
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> output; // [rsp+60h] [rbp-39h] BYREF
  hkgpCgoInternal::EdgeInfo *EdgeInfo; // [rsp+70h] [rbp-29h]
  hkgpCgoInternal::EdgeInfo *v54; // [rsp+78h] [rbp-21h]
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *v55; // [rsp+80h] [rbp-19h]
  hkgpCgoInternal::EdgeInfo *v56; // [rsp+88h] [rbp-11h]
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *v57; // [rsp+90h] [rbp-9h]
  hkgpIndexedMeshDefinitions::Edge v58; // [rsp+98h] [rbp-1h] BYREF
  unsigned __int64 v59; // [rsp+100h] [rbp+67h]
  hkgpIndexedMeshDefinitions::Triangle *m_triangle; // [rsp+110h] [rbp+77h]
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *v62; // [rsp+118h] [rbp+7Fh]

  v2 = *(_QWORD *)&e->m_edge.m_index;
  v4 = 2 * v2;
  v5 = (int)v2;
  v49.m_triangle = e->m_edge.m_triangle;
  m_triangle = v49.m_triangle;
  v7 = v49.m_triangle->m_links[(int)v2] & 0xFFFFFFFFFFFFFFFCui64;
  v8 = v49.m_triangle->m_links[(int)v2] & 3;
  v59 = v7;
  v49.m_index = (9 >> (2 * v2)) & 3;
  m_edge = v49;
  EdgeInfo = hkgpCgoInternal::getEdgeInfo(this, &m_edge);
  v49.m_triangle = m_triangle;
  v49.m_index = (18 >> v4) & 3;
  m_edge = v49;
  v9 = hkgpCgoInternal::getEdgeInfo(this, &m_edge);
  v49.m_triangle = (hkgpIndexedMeshDefinitions::Triangle *)v7;
  v54 = v9;
  v49.m_index = (9 >> (2 * v8)) & 3;
  m_edge = v49;
  v10 = hkgpCgoInternal::getEdgeInfo(this, &m_edge);
  v49.m_triangle = (hkgpIndexedMeshDefinitions::Triangle *)v7;
  v49.m_index = (18 >> (2 * v8)) & 3;
  m_edge = v49;
  v11 = hkgpCgoInternal::getEdgeInfo(this, &m_edge);
  m_data = this->m_vertices.m_data;
  v56 = v11;
  v13 = *(_QWORD *)(v7 + 8i64 * (int)v8 + 16);
  v55 = (hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *)&m_data[(__int64)SLODWORD(m_triangle->m_vertices[v5]->m_index)];
  v57 = (hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *)&m_data[(__int64)*(int *)(v13 + 16)];
  v14 = m_triangle->m_vertices[(18i64 >> v4) & 3];
  m_edge = e->m_edge;
  v49.m_triangle = (hkgpIndexedMeshDefinitions::Triangle *)&m_data[(__int64)SLODWORD(v14->m_index)];
  v62 = (hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *)&m_data[(__int64)*(int *)(*(_QWORD *)(v7 + 8 * ((18i64 >> (2 * (unsigned __int8)v8)) & 3) + 16)
                                                                                                + 16i64)];
  v15 = hkgpIndexedMesh::flipEdge(&this->m_topology, &v58, &m_edge);
  v16 = *(_QWORD *)&v15->m_index;
  m_edge = *v15;
  v17 = m_edge.m_triangle;
  v18 = (char *)m_edge.m_triangle + 8 * (int)v16;
  v19 = (hkgpIndexedMeshDefinitions::Triangle *)(*((_QWORD *)v18 + 5) & 0xFFFFFFFFFFFFFFFCui64);
  v20 = *((_QWORD *)v18 + 5) & 3i64;
  hkgpCgoInternal::setEdgeInfo(this, &m_edge, e);
  m_edge.m_triangle = v17;
  LOBYTE(v16) = 2 * v16;
  m_edge.m_index = (9 >> v16) & 3;
  hkgpCgoInternal::setEdgeInfo(this, &m_edge, v54);
  m_edge.m_triangle = v17;
  m_edge.m_index = (18 >> v16) & 3;
  hkgpCgoInternal::setEdgeInfo(this, &m_edge, v10);
  m_edge.m_triangle = v19;
  m_edge.m_index = (9 >> (2 * v20)) & 3;
  hkgpCgoInternal::setEdgeInfo(this, &m_edge, v56);
  m_edge.m_triangle = v19;
  m_edge.m_index = (18 >> (2 * v20)) & 3;
  hkgpCgoInternal::setEdgeInfo(this, &m_edge, EdgeInfo);
  hkgpCgoInternal::updatePlane(this, v17);
  hkgpCgoInternal::updatePlane(
    this,
    (hkgpIndexedMeshDefinitions::Triangle *)(*((_QWORD *)v18 + 5) & 0xFFFFFFFFFFFFFFFCui64));
  v21 = v55;
  m_size = v55[1].m_size;
  v23 = 0;
  v24 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    v23 = -1;
  }
  else
  {
    v25 = v55[1].m_data;
    while ( v25->m_triangle != (hkgpIndexedMeshDefinitions::Triangle *)v59 )
    {
      ++v24;
      ++v23;
      ++v25;
      if ( v24 >= m_size )
        goto LABEL_5;
    }
  }
  --v55[1].m_size;
  v26 = v21[1].m_size - v23;
  v27 = (__int64)&v21[1].m_data[v23];
  v28 = 8 * v26;
  if ( v28 > 0 )
  {
    v29 = ((unsigned int)(v28 - 1) >> 3) + 1;
    do
    {
      v30 = *(_QWORD *)(v27 + 8);
      v27 += 8i64;
      *(_QWORD *)(v27 - 8) = v30;
      --v29;
    }
    while ( v29 );
  }
  v31 = v57;
  v32 = 0;
  v33 = v57[1].m_size;
  v34 = 0i64;
  if ( v33 <= 0 )
  {
LABEL_13:
    v32 = -1;
  }
  else
  {
    v35 = v57[1].m_data;
    while ( v35->m_triangle != m_triangle )
    {
      ++v34;
      ++v32;
      ++v35;
      if ( v34 >= v33 )
        goto LABEL_13;
    }
  }
  --v57[1].m_size;
  v36 = v31[1].m_size - v32;
  v37 = (__int64)&v31[1].m_data[v32];
  v38 = 8 * v36;
  if ( v38 > 0 )
  {
    v39 = ((unsigned int)(v38 - 1) >> 3) + 1;
    do
    {
      v40 = *(_QWORD *)(v37 + 8);
      v37 += 8i64;
      *(_QWORD *)(v37 - 8) = v40;
      --v39;
    }
    while ( v39 );
  }
  v41 = (hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *)v49.m_triangle;
  if ( LODWORD(v49.m_triangle->m_vertices[1]) == (HIDWORD(v49.m_triangle->m_vertices[1]) & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)v49.m_triangle->m_vertices, 8);
  v42 = &v41[1].m_data[v41[1].m_size];
  if ( v42 )
    v42->m_triangle = (hkgpIndexedMeshDefinitions::Triangle *)v59;
  ++v41[1].m_size;
  if ( v62[1].m_size == (v62[1].m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v62[1].m_data, 8);
  v43 = &v62[1].m_data[v62[1].m_size];
  if ( v43 )
    v43->m_triangle = m_triangle;
  ++v62[1].m_size;
  v44 = v41[1].m_size;
  if ( v44 > 1 )
    hkAlgorithm::quickSortRecursive<hkgpCgoInternal::HTriangle,hkAlgorithm::less<hkgpCgoInternal::HTriangle>>(
      v41[1].m_data,
      0,
      v44 - 1,
      0);
  v45 = v62[1].m_size;
  if ( v45 > 1 )
    hkAlgorithm::quickSortRecursive<hkgpCgoInternal::HTriangle,hkAlgorithm::less<hkgpCgoInternal::HTriangle>>(
      v62[1].m_data,
      0,
      v45 - 1,
      0);
  output.m_capacityAndFlags = 0x80000000;
  output.m_data = 0i64;
  output.m_size = 0;
  computeUnionOfSortedArray_hkgpCgoInternal::HTriangle_(v21 + 1, v31 + 1, &output);
  b.m_data = 0i64;
  b.m_size = 0;
  b.m_capacityAndFlags = 0x80000000;
  computeUnionOfSortedArray_hkgpCgoInternal::HTriangle_(v41 + 1, v62 + 1, &b);
  v50.m_data = 0i64;
  v50.m_size = 0;
  v50.m_capacityAndFlags = 0x80000000;
  computeUnionOfSortedArray_hkgpCgoInternal::HTriangle_(&output, &b, &v50);
  v46 = 0;
  if ( v50.m_size > 0 )
  {
    v47 = 0i64;
    do
    {
      hkgpCgoInternal::invalidateEdgeInfo(
        this,
        this->m_triangles.m_data[(__int64)SLODWORD(v50.m_data[v47].m_triangle->m_index)].m_edges[0]);
      hkgpCgoInternal::invalidateEdgeInfo(
        this,
        this->m_triangles.m_data[(__int64)SLODWORD(v50.m_data[v47].m_triangle->m_index)].m_edges[1]);
      hkgpCgoInternal::invalidateEdgeInfo(
        this,
        this->m_triangles.m_data[(__int64)SLODWORD(v50.m_data[v47].m_triangle->m_index)].m_edges[2]);
      ++v46;
      ++v47;
    }
    while ( v46 < v50.m_size );
  }
  v50.m_size = 0;
  if ( v50.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v50.m_data,
      8 * v50.m_capacityAndFlags);
  v50.m_data = 0i64;
  v50.m_capacityAndFlags = 0x80000000;
  b.m_size = 0;
  if ( b.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      b.m_data,
      8 * b.m_capacityAndFlags);
  b.m_data = 0i64;
  b.m_capacityAndFlags = 0x80000000;
  output.m_size = 0;
  if ( output.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      output.m_data,
      8 * output.m_capacityAndFlags);
}

// File Line: 1156
// RVA: 0xCE9540
hkgpCgoInternal::EdgeInfo *__fastcall hkgpCgoInternal::getEdgeInfo(
        hkgpCgoInternal *this,
        hkgpIndexedMeshDefinitions::Edge *edge)
{
  hkgpIndexedMeshDefinitions::Triangle *m_triangle; // r8
  __int64 m_index; // r9
  hkgpCgoInternal::TriangleInfo *m_data; // rdx
  hkgpCgoInternal::EdgeInfo *result; // rax

  m_triangle = edge->m_triangle;
  m_index = (int)edge->m_index;
  m_data = this->m_triangles.m_data;
  result = m_data[SLODWORD(m_triangle->m_index)].m_edges[m_index];
  if ( !result && (m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
    return m_data[*(int *)((m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64) + 64)].m_edges[m_triangle->m_links[m_index] & 3];
  return result;
}

// File Line: 1164
// RVA: 0xCE9590
void __fastcall hkgpCgoInternal::setEdgeInfo(
        hkgpCgoInternal *this,
        hkgpIndexedMeshDefinitions::Edge *edge,
        hkgpCgoInternal::EdgeInfo *edgeInfo)
{
  char *v3; // rdx

  if ( edgeInfo )
    edgeInfo->m_edge = *edge;
  this->m_triangles.m_data[SLODWORD(edge->m_triangle->m_index)].m_edges[edge->m_index] = edgeInfo;
  v3 = (char *)edge->m_triangle + 8 * (int)edge->m_index;
  if ( (*((_QWORD *)v3 + 5) & 0xFFFFFFFFFFFFFFFCui64) != 0 )
    this->m_triangles.m_data[*(int *)((*((_QWORD *)v3 + 5) & 0xFFFFFFFFFFFFFFFCui64) + 64)].m_edges[*((_DWORD *)v3 + 10) & 3] = 0i64;
}

// File Line: 1177
// RVA: 0xCE9600
void __fastcall hkgpCgoInternal::invalidateEdgeInfo(hkgpCgoInternal *this, hkgpCgoInternal::EdgeInfo *edgeInfo)
{
  hkArray<hkgpCgoInternal::EdgeInfo *,hkContainerHeapAllocator> *p_m_invalidEdges; // rbx
  __int64 m_nodeIndex; // rbp

  if ( edgeInfo && edgeInfo->m_invalidIndex == -1 )
  {
    p_m_invalidEdges = &this->m_invalidEdges;
    edgeInfo->m_invalidIndex = this->m_invalidEdges.m_size;
    if ( this->m_invalidEdges.m_size == (this->m_invalidEdges.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_invalidEdges->m_data, 8);
    p_m_invalidEdges->m_data[p_m_invalidEdges->m_size++] = edgeInfo;
    m_nodeIndex = edgeInfo->m_nodeIndex;
    if ( (_DWORD)m_nodeIndex )
    {
      hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::removeNode(
        &this->m_edgesTree,
        m_nodeIndex);
      this->m_edgesTree.m_nodes.m_data[m_nodeIndex].m_parent = this->m_edgesTree.m_free;
      --this->m_edgesTree.m_size;
      this->m_edgesTree.m_free = m_nodeIndex;
      edgeInfo->m_nodeIndex = 0;
    }
  }
}

// File Line: 1192
// RVA: 0xCE96D0
void __fastcall hkgpCgoInternal::removeEdgeInfoFromInvalidQueue(
        hkgpCgoInternal *this,
        hkgpCgoInternal::EdgeInfo *edgeInfo)
{
  int m_invalidIndex; // edx
  __int64 v4; // r8
  __int64 v5; // rax

  m_invalidIndex = edgeInfo->m_invalidIndex;
  if ( m_invalidIndex != -1 )
  {
    this->m_invalidEdges.m_data[this->m_invalidEdges.m_size - 1]->m_invalidIndex = m_invalidIndex;
    v4 = edgeInfo->m_invalidIndex;
    v5 = --this->m_invalidEdges.m_size;
    if ( (_DWORD)v5 != (_DWORD)v4 )
      this->m_invalidEdges.m_data[v4] = this->m_invalidEdges.m_data[v5];
    edgeInfo->m_invalidIndex = -1;
  }
}

// File Line: 1203
// RVA: 0xCE9730
void __fastcall hkgpCgoInternal::getRing(
        hkgpCgoInternal *this,
        int v0,
        int v1,
        hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *ring)
{
  computeUnionOfSortedArray_hkgpCgoInternal::HTriangle_(
    &this->m_vertices.m_data[(__int64)v0].m_ring,
    &this->m_vertices.m_data[(__int64)v1].m_ring,
    ring);
}

// File Line: 1209
// RVA: 0xCE9770
void __fastcall hkgpCgoInternal::getPlanes(
        hkgpCgoInternal *this,
        int v0,
        int v1,
        hkArray<hkVector4f,hkContainerHeapAllocator> *planes)
{
  hkgpCgoInternal::VertexInfo *m_data; // rax
  __int64 v6; // rdi
  __int64 v7; // rsi
  hkgpCgoInternal::VertexInfo *v9; // rax
  int m_size; // ecx
  int m_capacityAndFlags; // eax
  int v12; // r9d
  int v13; // eax
  int v14; // eax
  int v15; // r14d
  __int64 v16; // rsi
  hkgpCgoInternal::TriangleInfo *v17; // rdi
  int v18; // r14d
  __int64 v19; // rsi
  hkgpCgoInternal::TriangleInfo *v20; // rdi
  hkArray<int,hkContainerHeapAllocator> v21; // [rsp+30h] [rbp-20h] BYREF
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> output; // [rsp+40h] [rbp-10h] BYREF
  hkResult result; // [rsp+88h] [rbp+38h] BYREF

  m_data = this->m_vertices.m_data;
  v6 = (__int64)v0 << 6;
  v7 = (__int64)v1 << 6;
  output.m_data = 0i64;
  output.m_size = 0;
  output.m_capacityAndFlags = 0x80000000;
  computeUnionOfSortedArray_hkgpCgoInternal::HTriangle_(
    (hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *)((char *)&m_data->m_ring + v6),
    (hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *)((char *)&m_data->m_ring + v7),
    &output);
  v9 = this->m_vertices.m_data;
  v21.m_data = 0i64;
  v21.m_size = 0;
  v21.m_capacityAndFlags = 0x80000000;
  computeUnionOfSortedArray_int_(
    (hkArray<int,hkContainerHeapAllocator> *)((char *)&v9->m_planes + v6),
    (hkArray<int,hkContainerHeapAllocator> *)((char *)&v9->m_planes + v7),
    &v21);
  m_size = output.m_size;
  m_capacityAndFlags = planes->m_capacityAndFlags;
  v12 = output.m_size + v21.m_size;
  planes->m_size = 0;
  v13 = m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 < v12 )
  {
    v14 = 2 * v13;
    if ( v12 < v14 )
      v12 = v14;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&planes->m_data, v12, 16);
    m_size = output.m_size;
  }
  v15 = 0;
  if ( m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      v17 = &this->m_triangles.m_data[(__int64)SLODWORD(output.m_data[v16].m_triangle->m_index)];
      if ( planes->m_size == (planes->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&planes->m_data, 16);
      ++v15;
      ++v16;
      planes->m_data[planes->m_size++] = v17->m_plane;
    }
    while ( v15 < output.m_size );
  }
  v18 = 0;
  if ( v21.m_size > 0 )
  {
    v19 = 0i64;
    do
    {
      v20 = &this->m_triangles.m_data[(__int64)v21.m_data[v19]];
      if ( planes->m_size == (planes->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&planes->m_data, 16);
      ++v18;
      ++v19;
      planes->m_data[planes->m_size++] = v20->m_plane;
    }
    while ( v18 < v21.m_size );
  }
  v21.m_size = 0;
  if ( v21.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v21.m_data,
      4 * v21.m_capacityAndFlags);
  v21.m_data = 0i64;
  v21.m_capacityAndFlags = 0x80000000;
  output.m_size = 0;
  if ( output.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      output.m_data,
      8 * output.m_capacityAndFlags);
}

// File Line: 1220
// RVA: 0xCE9990
__int64 __fastcall hkgpCgoInternal::checkIntegrity(hkgpCgoInternal *this)
{
  hkgpIndexedMeshDefinitions::Triangle *m_used; // rbx
  hkgpCgoInternal::EdgeInfo *v2; // rdi
  __int64 *v3; // rax
  unsigned __int8 v5; // r10
  hkgpIndexedMeshDefinitions::Vertex *v6; // rdx
  hkgpIndexedMeshDefinitions::Vertex *v7; // rax
  hkgpIndexedMeshDefinitions::Vertex *v8; // rcx
  int v9; // r14d
  hkgpCgoInternal::TriangleInfo *v10; // rax
  signed __int64 v11; // r12
  hkgpCgoInternal::EdgeInfo **m_edges; // r15
  hkgpCgoInternal::EdgeInfo *v13; // r8
  int v14; // r9d
  unsigned int v15; // ecx
  int v16; // edx
  hkgpCgoInternal::VertexInfo *v17; // rax
  __int64 v18; // rcx
  __int64 m_size; // r8
  hkgpCgoInternal::HTriangle *m_data; // rax
  char *v21; // rcx
  hkErrStream v23; // [rsp+20h] [rbp-C0h] BYREF
  char buf[512]; // [rsp+40h] [rbp-A0h] BYREF
  char v25; // [rsp+250h] [rbp+170h] BYREF
  __int64 v26; // [rsp+270h] [rbp+190h] BYREF

  m_used = this->m_topology.m_triangles.m_used;
  v2 = 0i64;
  v3 = &v26;
  v5 = 1;
  if ( !m_used )
    v3 = 0i64;
  if ( v3 )
  {
    do
    {
      v6 = m_used->m_vertices[1];
      v7 = m_used->m_vertices[0];
      if ( v7 == v6 || (v8 = m_used->m_vertices[2], v7 == v8) || v6 == v8 )
      {
        hkErrStream::hkErrStream(&v23, buf, 512);
        hkOstream::operator<<(&v23, "Invalid triangle vertices");
        if ( (unsigned int)hkError::messageError(
                             0x1FD03A80u,
                             buf,
                             "GeometryProcessing\\CollisionGeometryOptimizer\\hkgpCgoInternals.cpp",
                             1229) )
          __debugbreak();
        hkOstream::~hkOstream(&v23);
        v5 = 0;
      }
      v9 = 0;
      v10 = &this->m_triangles.m_data[(__int64)SLODWORD(m_used->m_index)];
      v11 = (char *)m_used - (char *)v10;
      m_edges = v10->m_edges;
      do
      {
        v13 = *m_edges;
        if ( (m_used->m_links[v9] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          v2 = this->m_triangles.m_data[*(int *)((m_used->m_links[v9] & 0xFFFFFFFFFFFFFFFCui64) + 64)].m_edges[m_used->m_links[v9] & 3];
        if ( v13 )
        {
          if ( (char *)v13->m_edge.m_triangle + v13->m_edge.m_index != (char *)m_used + (unsigned int)v9 )
          {
            hkErrStream::hkErrStream(&v23, buf, 512);
            hkOstream::operator<<(&v23, "Invalid edge reference");
            if ( (unsigned int)hkError::messageError(
                                 0x166BBC3Cu,
                                 buf,
                                 "GeometryProcessing\\CollisionGeometryOptimizer\\hkgpCgoInternals.cpp",
                                 1244) )
              __debugbreak();
            hkOstream::~hkOstream(&v23);
            v5 = 0;
          }
          if ( (m_used->m_links[v9] & 0xFFFFFFFFFFFFFFFCui64) == 0 || !v2 )
            goto LABEL_27;
          hkErrStream::hkErrStream(&v23, buf, 512);
          hkOstream::operator<<(&v23, "Non-null edge info");
          v14 = 1249;
          v15 = 1613305869;
          goto LABEL_24;
        }
        if ( (m_used->m_links[v9] & 0xFFFFFFFFFFFFFFFCui64) != 0 && !v2 )
        {
          hkErrStream::hkErrStream(&v23, buf, 512);
          hkOstream::operator<<(&v23, "Null edge info");
          v14 = 1257;
          v15 = 1817719705;
LABEL_24:
          if ( (unsigned int)hkError::messageError(
                               v15,
                               buf,
                               "GeometryProcessing\\CollisionGeometryOptimizer\\hkgpCgoInternals.cpp",
                               v14) )
            __debugbreak();
          hkOstream::~hkOstream(&v23);
          v5 = 0;
        }
LABEL_27:
        v2 = 0i64;
        v16 = 0;
        v17 = &this->m_vertices.m_data[(__int64)(*(hkgpCgoInternal::EdgeInfo **)((char *)m_edges + v11))->m_vertex.m_quad.m128_i32[0]];
        v18 = 0i64;
        m_size = v17->m_ring.m_size;
        if ( m_size <= 0 )
          goto LABEL_33;
        m_data = v17->m_ring.m_data;
        while ( m_data->m_triangle != m_used )
        {
          ++v18;
          ++v16;
          ++m_data;
          if ( v18 >= m_size )
            goto LABEL_33;
        }
        if ( v16 == -1 )
        {
LABEL_33:
          hkErrStream::hkErrStream(&v23, buf, 512);
          hkOstream::operator<<(&v23, "Cannot find triangle reference in vertex ring");
          if ( (unsigned int)hkError::messageError(
                               0x109EE5BEu,
                               buf,
                               "GeometryProcessing\\CollisionGeometryOptimizer\\hkgpCgoInternals.cpp",
                               1264) )
            __debugbreak();
          hkOstream::~hkOstream(&v23);
          v5 = 0;
        }
        ++v9;
        ++m_edges;
      }
      while ( v9 < 3 );
      m_used = m_used->m_next;
      v21 = &v25;
      if ( !m_used )
        v21 = 0i64;
    }
    while ( v21 );
  }
  return v5;
}


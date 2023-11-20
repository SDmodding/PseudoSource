// File Line: 27
// RVA: 0xCEA4E0
void __fastcall computeUnionOfSortedArray_int_hkgpCgoInternal::ArrayCollector_int___(hkArray<int,hkContainerHeapAllocator> *a, hkArray<int,hkContainerHeapAllocator> *b, hkgpCgoInternal::ArrayCollector<int> *collector)
{
  __int64 v3; // r14
  int v4; // er12
  __int64 v5; // r13
  hkgpCgoInternal::ArrayCollector<int> *v6; // r15
  hkArray<int,hkContainerHeapAllocator> *v7; // rax
  int v8; // ebp
  __int64 v9; // rdi
  __int64 v10; // rsi
  hkArray<int,hkContainerHeapAllocator> *v11; // rbx
  int *v12; // rbp
  int v13; // ecx
  int *v14; // r14
  int v15; // eax
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
  hkArray<int,hkContainerHeapAllocator> *v26; // [rsp+70h] [rbp+8h]
  hkArray<int,hkContainerHeapAllocator> *v27; // [rsp+78h] [rbp+10h]
  int v28; // [rsp+88h] [rbp+20h]

  v27 = b;
  v26 = a;
  v3 = b->m_size;
  v4 = 0;
  v5 = a->m_size;
  v6 = collector;
  v7 = a;
  v8 = 0;
  v28 = 0;
  v9 = 0i64;
  v10 = 0i64;
  for ( i = b->m_size; v9 < v5; b = v27 )
  {
    if ( v10 >= v3 )
      break;
    v11 = v6->m_items;
    v12 = &v7->m_data[v9];
    v13 = b->m_data[v10];
    v14 = &b->m_data[v10];
    v15 = v6->m_items->m_capacityAndFlags;
    if ( v13 <= *v12 )
    {
      if ( v13 >= *v12 )
      {
        if ( v11->m_size == (v15 & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6->m_items, 4);
        ++v4;
        v17 = &v11->m_data[v11->m_size];
        v18 = *v12;
        ++v9;
      }
      else
      {
        if ( v11->m_size == (v15 & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6->m_items, 4);
        v17 = &v11->m_data[v11->m_size];
        v18 = *v14;
      }
      *v17 = v18;
      ++v11->m_size;
      v8 = v28 + 1;
      ++v10;
      ++v28;
    }
    else
    {
      if ( v11->m_size == (v15 & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6->m_items, 4);
      ++v4;
      v16 = *v12;
      v8 = v28;
      v11->m_data[v11->m_size++] = v16;
      ++v9;
    }
    v3 = i;
    v7 = v26;
  }
  for ( j = v4; j < v5; v7 = v26 )
  {
    v20 = v6->m_items;
    v21 = &v7->m_data[j];
    if ( v6->m_items->m_size == (v6->m_items->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6->m_items, 4);
    ++j;
    v20->m_data[v20->m_size++] = *v21;
  }
  for ( k = v8; k < v3; ++v23->m_size )
  {
    v23 = v6->m_items;
    v24 = &v27->m_data[k];
    if ( v6->m_items->m_size == (v6->m_items->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6->m_items, 4);
    ++k;
    v23->m_data[v23->m_size] = *v24;
  }
}

// File Line: 46
// RVA: 0xCEA160
void __fastcall computeUnionOfSortedArray_hkgpCgoInternal::HTriangle_(hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *a, hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *b, hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *output)
{
  int v3; // eax
  int v4; // er9
  int v5; // eax
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *v6; // rbx
  unsigned __int128 v7; // di
  int v8; // eax
  hkResult result; // [rsp+40h] [rbp+8h]

  v3 = output->m_capacityAndFlags;
  output->m_size = 0;
  v4 = b->m_size + a->m_size;
  v5 = v3 & 0x3FFFFFFF;
  v6 = output;
  v7 = __PAIR__((unsigned __int64)a, (unsigned __int64)b);
  if ( v5 < v4 )
  {
    v8 = 2 * v5;
    if ( v4 < v8 )
      v4 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, output, v4, 8);
  }
  *(_QWORD *)&result.m_enum = v6;
  computeUnionOfSortedArray_hkgpCgoInternal::HTriangle_hkgpCgoInternal::ArrayCollector_hkgpCgoInternal::HTriangle___(
    *((hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> **)&v7 + 1),
    (hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *)v7,
    (hkgpCgoInternal::ArrayCollector<hkgpCgoInternal::HTriangle> *)&result);
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
                       _mm_cmpleps(v9, (__m128)0i64),
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
  hkVector4f v14; // xmm7

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
            _mm_cmpleps(v10, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)),
              _mm_mul_ps(*(__m128 *)_xmm, v11))));
  v13 = _mm_mul_ps(a->m_quad, v12);
  v14.m_quad = _mm_shuffle_ps(
                 v12,
                 _mm_unpackhi_ps(
                   v12,
                   _mm_sub_ps(
                     (__m128)0i64,
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                       _mm_shuffle_ps(v13, v13, 170)))),
                 196);
  *plane = (hkVector4f)v14.m_quad;
  if ( invert )
    plane->m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v14.m_quad);
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
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm5
  float v21; // xmm4_4
  __m128 v22; // xmm5
  __m128 v23; // xmm3

  v3 = _mm_sub_ps(c->m_quad, a->m_quad);
  v4 = _mm_sub_ps(a->m_quad, b->m_quad);
  v5 = _mm_mul_ps(v3, v3);
  v6 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
  v7 = _mm_mul_ps(v4, v4);
  v8 = _mm_rsqrt_ps(v6);
  v9 = _mm_unpacklo_ps(
         _mm_andnot_ps(
           _mm_cmpleps(v6, (__m128)0i64),
           _mm_mul_ps(
             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v6, v8), v8)), _mm_mul_ps(*(__m128 *)_xmm, v8)),
             v6)),
         aabbOut.m_quad);
  v10 = _mm_sub_ps(b->m_quad, c->m_quad);
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_rsqrt_ps(v12);
  v14 = _mm_andnot_ps(
          _mm_cmpleps(v12, (__m128)0i64),
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
              _mm_cmpleps(v15, (__m128)0i64),
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
  v21 = v20.m128_f32[0];
  v22 = _mm_max_ps(v20, _mm_max_ps(v18, v19));
  v23 = _mm_rcp_ps(v22);
  return COERCE_FLOAT(
           _mm_andnot_ps(
             _mm_cmpeqps((__m128)0i64, v22),
             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v22)), v23)))
       * fmin(v21, fmin(v18.m128_f32[0], v19.m128_f32[0]));
}

// File Line: 84
// RVA: 0xCEA0E0
void __fastcall projectOnPlanes(hkArrayBase<hkVector4f> *planes, hkVector4f *x, hkVector4f *xOut)
{
  __int64 v3; // rax
  __m128 v4; // xmm4
  hkVector4f *v5; // rdx
  __m128 v6; // xmm3
  __m128 v7; // xmm2
  __m128 v8; // xmm2
  __m128 v9; // xmm1

  v3 = planes->m_size;
  v4 = x->m_quad;
  if ( v3 > 0 )
  {
    v5 = planes->m_data;
    do
    {
      v6 = v5->m_quad;
      ++v5;
      v7 = _mm_mul_ps(v6, v4);
      v8 = _mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, v6), 196);
      v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 78), v8);
      v4 = _mm_sub_ps(v4, _mm_mul_ps(_mm_min_ps(aabbOut.m_quad, _mm_add_ps(_mm_shuffle_ps(v9, v9, 177), v9)), v6));
      --v3;
    }
    while ( v3 );
  }
  *xOut = (hkVector4f)v4;
}

// File Line: 100
// RVA: 0xCE50C0
char __fastcall hkgpCgoInternal::ICollapse::validTriangleSet(hkgpCgoInternal::ICollapse *this, hkArrayBase<hkgpIndexedMeshDefinitions::Triangle *> *triangles, hkgpIndexedMeshDefinitions::Vertex *from, hkgpIndexedMeshDefinitions::Vertex *to)
{
  hkArrayBase<hkgpIndexedMeshDefinitions::Triangle *> *v4; // rdi
  hkgpCgoInternal::ICollapse *v5; // rbp
  int v6; // er14
  __int64 v7; // rsi
  hkgpCgoInternal *v8; // rcx
  hkgpCgoInternal::EdgeInfo *v9; // rax
  hkgpCgoInternal *v10; // rcx
  hkgpCgoInternal::EdgeInfo *v11; // rax
  hkgpCgoInternal *v12; // rcx
  hkgpCgoInternal::EdgeInfo *v13; // rax
  __m128i v15; // [rsp+20h] [rbp-78h]
  __m128i v16; // [rsp+30h] [rbp-68h]
  __m128i v17; // [rsp+40h] [rbp-58h]
  __int128 v18; // [rsp+50h] [rbp-48h]
  __int128 v19; // [rsp+60h] [rbp-38h]
  __int128 v20; // [rsp+70h] [rbp-28h]

  v4 = triangles;
  v5 = this;
  v6 = 0;
  if ( triangles->m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v15.m128i_i32[2] = 0;
      v15.m128i_i64[0] = (__int64)v4->m_data[v7];
      v8 = v5->m_instance;
      _mm_store_si128((__m128i *)&v18, v15);
      v9 = hkgpCgoInternal::getEdgeInfo(v8, (hkgpIndexedMeshDefinitions::Edge *)&v18);
      hkgpCgoInternal::invalidateEdgeInfo(v5->m_instance, v9);
      v16.m128i_i32[2] = 1;
      v16.m128i_i64[0] = (__int64)v4->m_data[v7];
      v10 = v5->m_instance;
      _mm_store_si128((__m128i *)&v19, v16);
      v11 = hkgpCgoInternal::getEdgeInfo(v10, (hkgpIndexedMeshDefinitions::Edge *)&v19);
      hkgpCgoInternal::invalidateEdgeInfo(v5->m_instance, v11);
      v17.m128i_i32[2] = 2;
      v17.m128i_i64[0] = (__int64)v4->m_data[v7];
      v12 = v5->m_instance;
      _mm_store_si128((__m128i *)&v20, v17);
      v13 = hkgpCgoInternal::getEdgeInfo(v12, (hkgpIndexedMeshDefinitions::Edge *)&v20);
      hkgpCgoInternal::invalidateEdgeInfo(v5->m_instance, v13);
      ++v6;
      ++v7;
    }
    while ( v6 < v4->m_size );
  }
  return 1;
}

// File Line: 112
// RVA: 0xCE51F0
void __fastcall hkgpCgoInternal::ICollapse::removeTriangle(hkgpCgoInternal::ICollapse *this, hkgpIndexedMeshDefinitions::Triangle *triangle)
{
  hkgpCgoInternal::VertexInfo *v2; // rbx
  hkgpIndexedMeshDefinitions::Triangle *v3; // rsi
  hkgpCgoInternal::ICollapse *v4; // r14
  int v5; // edi
  signed __int64 v6; // r15
  signed int v7; // ebp
  hkgpCgoInternal *v8; // rcx
  hkgpCgoInternal::EdgeInfo *v9; // rdi
  unsigned __int64 v10; // rdx
  hkgpCgoInternal *v11; // rcx
  hkgpIndexedMeshDefinitions::Triangle *v12; // rax
  int v13; // edx
  __int64 v14; // rcx
  signed __int64 v15; // r10
  __int64 v16; // r9
  hkgpIndexedMeshDefinitions::Triangle **v17; // rax
  int v18; // er9
  signed __int64 v19; // rax
  int v20; // er9
  __int64 v21; // rdx
  __int64 v22; // rcx
  __m128i v23; // [rsp+20h] [rbp-78h]
  __m128i v24; // [rsp+30h] [rbp-68h]
  __int128 v25; // [rsp+40h] [rbp-58h]
  __int128 v26; // [rsp+50h] [rbp-48h]
  __int128 v27; // [rsp+60h] [rbp-38h]

  v2 = this->m_vertex;
  v3 = triangle;
  v4 = this;
  if ( v2 )
  {
    v5 = triangle->m_index;
    if ( v2->m_cluster.m_size == (v2->m_cluster.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_cluster, 4);
    v2->m_cluster.m_data[v2->m_cluster.m_size++] = v5;
  }
  v6 = (signed __int64)v3->m_vertices;
  v4->m_instance->m_triangles.m_data[(signed __int64)SLODWORD(v3->m_index)].m_removed = 1;
  v7 = 0;
  do
  {
    v8 = v4->m_instance;
    v23.m128i_i64[0] = (__int64)v3;
    v23.m128i_i32[2] = v7;
    _mm_store_si128((__m128i *)&v25, v23);
    v9 = hkgpCgoInternal::getEdgeInfo(v8, (hkgpIndexedMeshDefinitions::Edge *)&v25);
    hkgpCgoInternal::invalidateEdgeInfo(v4->m_instance, v9);
    if ( (char *)v9->m_edge.m_triangle + v9->m_edge.m_index == (char *)v3 + (unsigned int)v7 )
    {
      v10 = v3->m_links[v7];
      v11 = v4->m_instance;
      if ( v10 & 0xFFFFFFFFFFFFFFFCui64 )
      {
        v24.m128i_i64[0] = v10 & 0xFFFFFFFFFFFFFFFCui64;
        v24.m128i_i32[2] = v10 & 3;
        _mm_store_si128((__m128i *)&v26, v24);
        hkgpCgoInternal::setEdgeInfo(v11, (hkgpIndexedMeshDefinitions::Edge *)&v26, v9);
      }
      else
      {
        _mm_store_si128((__m128i *)&v27, v23);
        hkgpCgoInternal::setEdgeInfo(v11, (hkgpIndexedMeshDefinitions::Edge *)&v27, 0i64);
        hkgpCgoInternal::removeEdgeInfoFromInvalidQueue(v4->m_instance, v9);
        if ( `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::`local static guard & 1 )
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
        v9->m_edge.m_triangle = v12;
        *(_QWORD *)&v9->m_edge.m_index = *((_QWORD *)&`hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::e
                                         + 1);
      }
    }
    v13 = 0;
    v14 = 0i64;
    v15 = (signed __int64)&v4->m_instance->m_vertices.m_data[(signed __int64)*(signed int *)(*(_QWORD *)v6 + 16i64)];
    v16 = *(signed int *)(v15 + 24);
    if ( (signed int)v16 > 0 )
    {
      v17 = *(hkgpIndexedMeshDefinitions::Triangle ***)(v15 + 16);
      while ( *v17 != v3 )
      {
        ++v14;
        ++v13;
        ++v17;
        if ( v14 >= v16 )
          goto LABEL_22;
      }
      if ( v14 != -1 )
      {
        v18 = v16 - 1;
        *(_DWORD *)(v15 + 24) = v18;
        v19 = *(_QWORD *)(v15 + 16) + 8 * v14;
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
    ++v7;
    v6 += 8i64;
  }
  while ( v7 < 3 );
}

// File Line: 150
// RVA: 0xCE4F10
void __fastcall hkgpCgoInternal::ICollapse::bind(hkgpCgoInternal::ICollapse *this, hkgpIndexedMeshDefinitions::Edge *e0, hkgpIndexedMeshDefinitions::Edge *e1)
{
  hkgpIndexedMeshDefinitions::Edge *v3; // rdi
  hkgpCgoInternal::ICollapse *v4; // r13
  hkgpCgoInternal::TriangleInfo *v5; // r9
  hkgpIndexedMeshDefinitions::Edge *v6; // r14
  signed __int64 v7; // rcx
  signed __int64 v8; // rdx
  hkgpCgoInternal *v9; // rcx
  hkgpCgoInternal::EdgeInfo *v10; // rax
  hkgpCgoInternal *v11; // rcx
  hkgpCgoInternal::EdgeInfo *v12; // rbp
  hkgpCgoInternal::EdgeInfo *v13; // rax
  hkgpCgoInternal::EdgeInfo *v14; // rbx
  hkgpCgoInternal *v15; // rcx
  hkgpIndexedMeshDefinitions::Edge v16; // [rsp+20h] [rbp-28h]

  v3 = e0;
  v4 = this;
  v5 = this->m_instance->m_triangles.m_data;
  v6 = e1;
  v7 = (signed __int64)&v5[(signed __int64)SLODWORD(e0->m_triangle->m_index)] + 4 * (signed int)e0->m_index;
  v8 = (signed __int64)&v5[(signed __int64)SLODWORD(e1->m_triangle->m_index)];
  if ( *(_DWORD *)(v7 + 40) >= 0 || *(_DWORD *)(v8 + 4i64 * (signed int)e1->m_index + 40) >= 0 )
  {
    *(_DWORD *)(v7 + 40) = -1;
    *(_DWORD *)(v8 + 4i64 * (signed int)e1->m_index + 40) = -1;
    v4->m_instance->m_vertices.m_data[(signed __int64)SLODWORD(v3->m_triangle->m_vertices[v3->m_index]->m_index)].m_planes.m_size = 0;
    v4->m_instance->m_vertices.m_data[(signed __int64)SLODWORD(v3->m_triangle->m_vertices[(9i64 >> 2
                                                                                                 * (unsigned __int8)v3->m_index) & 3]->m_index)].m_planes.m_size = 0;
  }
  v9 = v4->m_instance;
  v16 = *v3;
  v10 = hkgpCgoInternal::getEdgeInfo(v9, &v16);
  v11 = v4->m_instance;
  v12 = v10;
  v16 = *v6;
  v13 = hkgpCgoInternal::getEdgeInfo(v11, &v16);
  v14 = v13;
  if ( v12 )
  {
    if ( v13 )
    {
      hkgpCgoInternal::removeEdgeInfoFromInvalidQueue(v4->m_instance, v13);
      if ( `hkgpTopology::Edge<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkgpIndexedMeshDefinitions::Vertex *>::null::`2::`local static guard & 1 )
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
    v3->m_triangle = v6->m_triangle;
    *(_QWORD *)&v3->m_index = *(_QWORD *)&v6->m_index;
  }
  v15 = v4->m_instance;
  v16 = *v3;
  hkgpCgoInternal::setEdgeInfo(v15, &v16, v12);
}

// File Line: 186
// RVA: 0xCE5430
void __fastcall hkgpCgoInternal::reset(hkgpCgoInternal *this)
{
  hkgpCgoInternal *v1; // rsi
  hkgpCgoInternal::ICustomMetric *v2; // rcx
  hkBaseObjectVtbl *v3; // rax
  int v4; // ebx
  hkgpCgoInternal::VertexInfo *v5; // rdi

  v1 = this;
  v2 = this->m_cstMetric;
  if ( v2 )
    v2->vfptr->onReset(v2, v1);
  v3 = v1->m_topology.vfptr;
  v1->m_geometry = 0i64;
  v3[1].__first_virtual_table_function__((hkBaseObject *)&v1->m_topology.vfptr);
  v4 = v1->m_vertices.m_size - 1;
  if ( v4 >= 0 )
  {
    v5 = &v1->m_vertices.m_data[(signed __int64)v4];
    do
    {
      hkgpCgoInternal::VertexInfo::~VertexInfo(v5);
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v1->m_vertices.m_size = 0;
  v1->m_triangles.m_size = 0;
  v1->m_invalidEdges.m_size = 0;
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::clear(&v1->m_edgesTree, 0);
  v1->m_edgesStorage.m_size = 0;
}

// File Line: 200
// RVA: 0xCE54E0
void __fastcall hkgpCgoInternal::bake(hkgpCgoInternal *this)
{
  hkgpCgoInternal *v1; // rdi
  hkgpCgoInternal::ICustomMetric *v2; // rcx
  hkGeometry *v3; // rax
  hkGeometry *v4; // r8
  hkGeometry *v5; // rbx
  int v6; // er8
  hkGeometry *v7; // rbx
  int v8; // er8
  hkGeometry *v9; // r8
  int v10; // eax
  int v11; // er9
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *v12; // r8
  int v13; // eax
  int v14; // eax
  hkgpIndexedMeshDefinitions::Triangle *v15; // rbx
  hkgpCgoInternal **v16; // rax
  hkGeometry *v17; // rdi
  int v18; // eax
  signed __int64 v19; // r12
  __int64 v20; // rbx
  __int64 v21; // rcx
  hkgpCgoInternal *v22; // rcx
  signed __int64 v23; // rdi
  unsigned __int64 v24; // r13
  unsigned __int64 v25; // r14
  _DWORD *v26; // rax
  _DWORD *v27; // rsi
  hkVector4f *v28; // r15
  hkgpCgoInternal *v29; // rdx
  float v30; // ecx
  int v31; // eax
  hkgpCgoInternal **v32; // rax
  int sizeElem[2]; // [rsp+20h] [rbp-9h]
  float v34; // [rsp+28h] [rbp-1h]
  hkArrayBase<hkVector4f> v35; // [rsp+30h] [rbp+7h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v36; // [rsp+40h] [rbp+17h]
  hkgpCgoInternal *vars0; // [rsp+90h] [rbp+67h]
  hkgpIndexedMeshDefinitions::Triangle *retaddr; // [rsp+98h] [rbp+6Fh]
  hkgpCgoInternal *v39; // [rsp+A0h] [rbp+77h]

  v39 = this;
  v1 = this;
  v2 = this->m_cstMetric;
  if ( v2 )
    ((void (*)(void))v2->vfptr->onBake)();
  v3 = v1->m_geometry;
  v36.m_hashMod = -1;
  v36.m_elem = 0i64;
  v36.m_numElems = 0;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    &v36,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v3->m_vertices.m_size);
  v4 = v1->m_geometry;
  v35.m_data = 0i64;
  v35.m_size = 0;
  v35.m_capacityAndFlags = 2147483648;
  hkArrayBase<hkVector4f>::_append(
    &v35,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v4->m_vertices.m_data,
    v4->m_vertices.m_size);
  v5 = v1->m_geometry;
  v6 = v5->m_vertices.m_capacityAndFlags;
  v5->m_vertices.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v5->m_vertices.m_data,
      16 * v6);
  v5->m_vertices.m_data = 0i64;
  v5->m_vertices.m_capacityAndFlags = 2147483648;
  v7 = v1->m_geometry;
  v8 = v7->m_triangles.m_capacityAndFlags;
  v7->m_triangles.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v7->m_triangles.m_data,
      16 * v8);
  v7->m_triangles.m_data = 0i64;
  v7->m_triangles.m_capacityAndFlags = 2147483648;
  v9 = v1->m_geometry;
  v10 = v9->m_triangles.m_capacityAndFlags;
  v11 = v1->m_topology.m_triangles.m_numUsed;
  v12 = &v9->m_triangles;
  v13 = v10 & 0x3FFFFFFF;
  if ( v13 < v11 )
  {
    v14 = 2 * v13;
    sizeElem[0] = 16;
    if ( v11 < v14 )
      v11 = v14;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v12,
      v11,
      sizeElem[0]);
  }
  v15 = v1->m_topology.m_triangles.m_used;
  v16 = &v39;
  retaddr = v1->m_topology.m_triangles.m_used;
  if ( !v15 )
    v16 = 0i64;
  if ( v16 )
  {
    do
    {
      v17 = v1->m_geometry;
      if ( v17->m_triangles.m_size == (v17->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v17->m_triangles, 16);
      v18 = v17->m_triangles.m_size;
      v19 = (signed __int64)v15->m_vertices;
      v20 = (__int64)vars0;
      v21 = v17->m_triangles.m_size;
      *(_QWORD *)sizeElem = 0i64;
      v34 = 0.0;
      v22 = (hkgpCgoInternal *)&v17->m_triangles.m_data[v21];
      v17->m_triangles.m_size = v18 + 1;
      v39 = v22;
      v23 = 0i64;
      do
      {
        v24 = *(signed int *)(*(_QWORD *)v19 + 16i64);
        LODWORD(v25) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                         &v36,
                         v24,
                         0xFFFFFFFFFFFFFFFFui64);
        if ( (v25 & 0x80000000) != 0i64 )
        {
          v26 = *(_DWORD **)(v20 + 80);
          v25 = (signed int)v26[6];
          v27 = v26 + 4;
          v28 = &v35.m_data[v24];
          if ( v26[6] == (v26[7] & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v27, 16);
          *(hkVector4f *)(*(_QWORD *)v27 + 16i64 * (signed int)v27[2]++) = (hkVector4f)v28->m_quad;
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            &v36,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            v24,
            v25);
        }
        sizeElem[v23++] = v25;
        v19 += 8i64;
      }
      while ( v23 < 3 );
      v29 = v39;
      v30 = *(float *)&retaddr->m_material;
      v1 = vars0;
      v39->m_config.m_semantic = sizeElem[0];
      v31 = sizeElem[1];
      v29->m_config.m_maxShrink = v30;
      v29->m_config.m_combinator = v31;
      v29->m_config.m_maxDistance = v34;
      v15 = retaddr->m_next;
      v32 = &v39;
      retaddr = retaddr->m_next;
      if ( !retaddr )
        v32 = 0i64;
    }
    while ( v32 );
  }
  hkgpCgoInternal::load(v1, v1->m_geometry);
  v35.m_size = 0;
  if ( v35.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v35.m_data,
      16 * v35.m_capacityAndFlags);
  v35.m_data = 0i64;
  v35.m_capacityAndFlags = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v36,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v36);
}

// File Line: 232
// RVA: 0xCE5820
void __fastcall hkgpCgoInternal::load(hkgpCgoInternal *this, hkGeometry *geometry)
{
  hkGeometry *v2; // rbx
  hkgpCgoInternal *v3; // rsi
  hkgpCgoInternal::ICustomMetric *v4; // rcx
  __m128 v5; // xmm9
  __m128i v6; // xmm6
  __m128 v7; // xmm2
  __m128i v8; // xmm8
  __m128i v9; // xmm6
  __m128 v10; // xmm1
  __m128 v11; // xmm5
  __m128 v12; // xmm4
  __m128 v13; // xmm2
  float v14; // xmm13_4
  float v15; // xmm1_4
  hkArray<hkgpCgoInternal::VertexInfo,hkContainerHeapAllocator> *v16; // r14
  __int64 v17; // r15
  int v18; // eax
  int v19; // eax
  int v20; // er9
  int v21; // ebx
  hkgpCgoInternal::VertexInfo *v22; // rdi
  signed __int64 v23; // r13
  int v24; // eax
  __int64 v25; // rdx
  signed __int64 v26; // rax
  hkArray<hkgpCgoInternal::TriangleInfo,hkContainerHeapAllocator> *v27; // r12
  int v28; // ebx
  int v29; // eax
  int v30; // eax
  int v31; // er9
  int v32; // er15
  __int64 v33; // rbx
  hkgpCgoInternal::VertexInfo *v34; // rdi
  int v35; // er8
  hkgpCgoInternal::VertexInfo *v36; // rdi
  int v37; // er8
  int v38; // edx
  __int64 v39; // rcx
  hkgpIndexedMeshDefinitions::Vertex *v40; // rbx
  int *v41; // rax
  int v42; // er9
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *v43; // r8
  int v44; // eax
  int v45; // eax
  int *v46; // rax
  int v47; // er8
  hkgpIndexedMeshDefinitions::Triangle *v48; // rbx
  void ***v49; // rax
  int v50; // er15
  hkGeometry *v51; // r10
  hkVector4f *v52; // r8
  __int64 v53; // rdx
  hkgpIndexedMeshDefinitions::Vertex *v54; // rax
  __int64 v55; // r9
  __int64 v56; // rcx
  __int64 v57; // rdi
  __m128 v58; // xmm6
  __m128 *v59; // rdi
  __m128 v60; // xmm7
  __m128 v61; // xmm8
  int v62; // er11
  hkgpCgo::Tracker *v63; // rcx
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
  __int64 v76; // r9
  hkgpCgoInternal::VertexInfo *v77; // r8
  signed int *v78; // rdi
  hkgpIndexedMeshDefinitions::Triangle **v79; // rdx
  void ***v80; // rax
  hkgpIndexedMeshDefinitions::Triangle *v81; // rdx
  unsigned __int64 v82; // r8
  unsigned __int64 v83; // r9
  int v84; // eax
  hkgpIndexedMeshDefinitions::Triangle *v85; // rbx
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v86; // rax
  signed int v87; // er13
  unsigned __int64 v88; // r9
  signed __int64 v89; // r15
  __m128 v90; // xmm1
  hkVector4f *v91; // rdx
  __m128 v92; // xmm6
  __m128 v93; // xmm0
  __m128 v94; // xmm7
  __m128 v95; // xmm7
  __m128 v96; // xmm1
  __m128 v97; // xmm3
  __m128 v98; // xmm2
  __m128 v99; // xmm7
  __m128 v100; // xmm2
  __m128 v101; // xmm7
  int v102; // edx
  signed __int64 v103; // rcx
  int v104; // eax
  signed __int64 v105; // rdi
  signed __int64 v106; // rdi
  hkVector4f *v107; // r8
  __m128 v108; // xmm3
  hkgpIndexedMeshDefinitions::Vertex *v109; // rax
  __m128 v110; // xmm2
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v111; // rax
  int v112; // er9
  int v113; // ebx
  hkgpIndexedMeshDefinitions::Triangle *v114; // rdx
  unsigned __int64 v115; // r8
  unsigned __int64 v116; // r9
  int v117; // eax
  hkgpIndexedMeshDefinitions::Triangle *v118; // rdi
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v119; // rax
  hkgpIndexedMeshDefinitions::Triangle **v120; // rcx
  hkgpIndexedMeshDefinitions::Triangle *v121; // rax
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v122; // rax
  int v123; // er11
  __int64 v124; // r10
  char *v125; // r8
  int v126; // ecx
  unsigned int v127; // edx
  bool v128; // sf
  int v129; // ecx
  unsigned int v130; // eax
  unsigned int v131; // eax
  unsigned int v132; // eax
  __int64 v133; // rcx
  __int64 v134; // rdx
  char *v135; // r9
  int v136; // edx
  int v137; // eax
  int v138; // edi
  int v139; // eax
  __int64 v140; // rcx
  __int64 v141; // r8
  hkgpCgoInternal::Action *v142; // rcx
  void **v143; // r15
  int v144; // ebx
  int v145; // eax
  int v146; // eax
  int v147; // ebx
  __int64 v148; // rdi
  __int64 v149; // r12
  char *v150; // r8
  char *v151; // rcx
  __int64 v152; // rax
  hkArray<unsigned int,hkContainerHeapAllocator> v153; // xmm0
  int v154; // edi
  __int64 v155; // rbx
  signed int v156; // er8
  signed int v157; // er8
  signed int v158; // ebx
  unsigned int v159; // edx
  __m128 v160; // xmm6
  int v161; // er9
  int v162; // eax
  _OWORD *v163; // rcx
  __int64 v164; // rdx
  hkgpIndexedMeshDefinitions::Triangle *v165; // rax
  void ***v166; // rcx
  hkVector4f *v167; // r10
  __m128 v168; // xmm0
  __m128 *v169; // rcx
  __m128 v170; // xmm1
  void ***v171; // rcx
  int v172; // edi
  hkgpCgoInternal::Set **v173; // rbx
  int v174; // eax
  int v175; // eax
  int v176; // er9
  bool v177; // zf
  signed int v178; // edx
  __int64 v179; // r9
  __int64 v180; // r8
  __m128 v181; // xmm1
  __m128 v182; // xmm1
  __m128 v183; // xmm4
  __m128 v184; // xmm2
  signed int v185; // er8
  int v186; // er8
  int v187; // eax
  int v188; // er9
  int v189; // eax
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator v190; // [rsp+30h] [rbp-C8h]
  char *array; // [rsp+40h] [rbp-B8h]
  int v192; // [rsp+48h] [rbp-B0h]
  int v193; // [rsp+4Ch] [rbp-ACh]
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > v194; // [rsp+50h] [rbp-A8h]
  hkMatrix3f v195; // [rsp+70h] [rbp-88h]
  void **retaddr; // [rsp+158h] [rbp+60h]
  int v197; // [rsp+160h] [rbp+68h]

  v2 = geometry;
  v3 = this;
  hkgpCgoInternal::reset(this);
  v4 = v3->m_cstMetric;
  v5 = _mm_add_ps((__m128)LODWORD(v3->m_config.m_maxAngle), *(__m128 *)_xmm);
  v6 = _mm_load_si128((const __m128i *)_xmm);
  v7 = _mm_andnot_ps(*(__m128 *)_xmm, v5);
  v8 = _mm_add_epi32(v6, v6);
  v9 = _mm_andnot_si128(v6, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v7, *(__m128 *)_xmm)), v6));
  v10 = _mm_cvtepi32_ps(v9);
  v11 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v9, v8), (__m128i)0i64);
  v12 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v10, *(__m128 *)DP1_0), v7), _mm_mul_ps(v10, *(__m128 *)DP2)),
          _mm_mul_ps(v10, *(__m128 *)DP3));
  v13 = _mm_mul_ps(v12, v12);
  LODWORD(retaddr) = (*(unsigned __int128 *)&_mm_andnot_ps(
                                               v11,
                                               _mm_add_ps(
                                                 _mm_sub_ps(
                                                   _mm_mul_ps(
                                                     _mm_mul_ps(
                                                       _mm_add_ps(
                                                         _mm_mul_ps(
                                                           _mm_add_ps(
                                                             _mm_mul_ps(v13, *(__m128 *)cosCoeff0_0),
                                                             *(__m128 *)cosCoeff1),
                                                           v13),
                                                         *(__m128 *)cosCoeff2_0),
                                                       v13),
                                                     v13),
                                                   _mm_mul_ps(v13, *(__m128 *)_xmm)),
                                                 *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                                       (float)((float)((float)((float)((float)((float)(v13.m128_f32[0] * -0.00019515296) + 0.0083321612) * v13.m128_f32[0])
                                                                                             + -0.16666655)
                                                                                     * v13.m128_f32[0])
                                                                             * v12.m128_f32[0])
                                                                     + v12.m128_f32[0]) & v11.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v8, v8), v9) << 29) ^ v5.m128_i32[0] & _xmm[0];
  LODWORD(v14) = (unsigned __int128)_mm_shuffle_ps((__m128)(unsigned int)retaddr, (__m128)(unsigned int)retaddr, 0);
  if ( v4 )
    v4->vfptr->onLoad(v4, v2);
  v15 = v3->m_config.m_weldDistance;
  if ( v15 >= 0.0 )
    hkGeometryUtils::weldVertices(v2, v15);
  v3->m_geometry = v2;
  hkgpIndexedMesh::appendFromGeometry(&v3->m_topology, v2);
  v16 = &v3->m_vertices;
  v17 = v3->m_geometry->m_vertices.m_size;
  v18 = v3->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v18 < (signed int)v17 )
  {
    v19 = 2 * v18;
    v20 = v3->m_geometry->m_vertices.m_size;
    if ( (signed int)v17 < v19 )
      v20 = v19;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v3->m_vertices,
      v20,
      64);
  }
  v21 = v3->m_vertices.m_size - v17 - 1;
  if ( v21 >= 0 )
  {
    v22 = &v16->m_data[v17 + v21];
    do
    {
      hkgpCgoInternal::VertexInfo::~VertexInfo(v22);
      --v22;
      --v21;
    }
    while ( v21 >= 0 );
  }
  v23 = 0i64;
  v24 = v17 - v3->m_vertices.m_size;
  v25 = v24;
  if ( v24 > 0 )
  {
    v26 = (signed __int64)&v3->m_vertices.m_data[(signed __int64)v3->m_vertices.m_size].m_ring.m_capacityAndFlags;
    do
    {
      if ( v26 != 28 )
      {
        *(_QWORD *)(v26 - 28) = 0i64;
        *(_DWORD *)(v26 - 20) = 0;
        *(_DWORD *)(v26 - 16) = 2147483648;
        *(_QWORD *)(v26 - 12) = 0i64;
        *(_DWORD *)(v26 - 4) = 0;
        *(_DWORD *)v26 = 2147483648;
        *(_QWORD *)(v26 + 4) = 0i64;
        *(_DWORD *)(v26 + 12) = 0;
        *(_DWORD *)(v26 + 16) = 2147483648;
      }
      v26 += 64i64;
      --v25;
    }
    while ( v25 );
  }
  v3->m_vertices.m_size = v17;
  v27 = &v3->m_triangles;
  v28 = v3->m_geometry->m_triangles.m_size;
  v29 = v3->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v29 < v28 )
  {
    v30 = 2 * v29;
    v31 = v3->m_geometry->m_triangles.m_size;
    if ( v28 < v30 )
      v31 = v30;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v3->m_triangles,
      v31,
      64);
  }
  v3->m_triangles.m_size = v28;
  v32 = 0;
  if ( v3->m_vertices.m_size > 0 )
  {
    v33 = 0i64;
    do
    {
      v16->m_data[v33].m_isFixed = 0;
      v16->m_data[v33].m_isNaked = 0;
      v16->m_data[v33].m_material = 0;
      v16->m_data[v33].m_error = 0.0;
      v34 = v16->m_data;
      v35 = v16->m_data[v33].m_ring.m_capacityAndFlags;
      v16->m_data[v33].m_ring.m_size = 0;
      if ( v35 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v34[v33].m_ring.m_data,
          8 * v35);
      v34[v33].m_ring.m_data = 0i64;
      v34[v33].m_ring.m_capacityAndFlags = 2147483648;
      v36 = v16->m_data;
      v37 = v16->m_data[v33].m_planes.m_capacityAndFlags;
      v16->m_data[v33].m_planes.m_size = 0;
      if ( v37 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v36[v33].m_planes.m_data,
          4 * v37);
      v36[v33].m_planes.m_data = 0i64;
      v36[v33].m_planes.m_capacityAndFlags = 2147483648;
      ++v32;
      ++v33;
    }
    while ( v32 < v3->m_vertices.m_size );
  }
  v38 = 0;
  if ( v3->m_triangles.m_size > 0 )
  {
    v39 = 0i64;
    do
    {
      ++v38;
      ++v39;
      v27->m_data[v39 - 1].m_plane = 0i64;
      *((_QWORD *)&v27->m_data[v39] - 6) = 0i64;
      *((_QWORD *)&v27->m_data[v39] - 5) = 0i64;
      *((_QWORD *)&v27->m_data[v39] - 4) = 0i64;
    }
    while ( v38 < v3->m_triangles.m_size );
  }
  v40 = v3->m_topology.m_vertices.m_used;
  v41 = &v197;
  if ( !v40 )
    v41 = 0i64;
  if ( v41 )
  {
    do
    {
      v42 = v40->m_numRefs;
      v43 = &v16->m_data[(signed __int64)SLODWORD(v40->m_index)].m_ring;
      v44 = v43->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v44 >= v42 )
      {
        LODWORD(retaddr) = 0;
      }
      else
      {
        v45 = 2 * v44;
        if ( v42 < v45 )
          v42 = v45;
        hkArrayUtil::_reserve(
          (hkResult *)&retaddr,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v43,
          v42,
          8);
      }
      v40 = v40->m_next;
      v46 = &v197;
      if ( !v40 )
        v46 = 0i64;
    }
    while ( v46 );
  }
  v47 = v3->m_vertices.m_size;
  v194.m_storage.m_words.m_data = 0i64;
  v194.m_storage.m_words.m_size = 0;
  v194.m_storage.m_words.m_capacityAndFlags = 2147483648;
  v194.m_storage.m_numBits = 0;
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::setSizeAndFill(&v194, 0, v47, 0);
  v48 = v3->m_topology.m_triangles.m_used;
  v49 = &retaddr;
  v50 = 0;
  if ( !v48 )
    v49 = 0i64;
  if ( v49 )
  {
    do
    {
      v51 = v3->m_geometry;
      v52 = v51->m_vertices.m_data;
      v53 = SLODWORD(v48->m_vertices[1]->m_index);
      v54 = v48->m_vertices[2];
      LODWORD(v190.m_edge.m_triangle) = v48->m_vertices[0]->m_index;
      v55 = SLODWORD(v54->m_index);
      v56 = SLODWORD(v48->m_index);
      v57 = SLODWORD(v48->m_index);
      HIDWORD(v190.m_edge.m_triangle) = v53;
      v190.m_edge.m_index = v55;
      v58 = v52[SLODWORD(v190.m_edge.m_triangle)].m_quad;
      v59 = &v27->m_data[v57].m_plane.m_quad;
      v60 = v52[v53].m_quad;
      v61 = v52[v55].m_quad;
      v62 = v51->m_triangles.m_data[v56].m_material;
      v59[3].m128_i32[1] = v50;
      v59[1].m128_u64[0] = 0i64;
      v59[1].m128_u64[1] = 0i64;
      v59[2].m128_u64[0] = 0i64;
      v59[2].m128_u64[1] = -1i64;
      v59[3].m128_i32[0] = -1;
      v59[3].m128_i8[8] = 0;
      v63 = v3->m_config.m_tracker;
      LODWORD(retaddr) = v62;
      v197 = v50 + 1;
      if ( v63 && v3->m_config.m_buildClusters.m_bool )
      {
        v63->vfptr->setClusterId(v63, &v59[3].m128_i32[1], 1, v59[3].m128_i32[1]);
        v62 = (signed int)retaddr;
      }
      v64 = _mm_sub_ps(v61, v58);
      v65 = _mm_sub_ps(v60, v58);
      v66 = v3->m_config.m_inverseOrientation.m_bool != 0;
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
                _mm_cmpleps(v70, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v71, v70), v71)),
                  _mm_mul_ps(*(__m128 *)_xmm, v71))));
      v73 = _mm_mul_ps(v58, v72);
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
      *v59 = v74;
      if ( v66 )
        *v59 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v74);
      v75 = &v190;
      v23 = 3i64;
      do
      {
        v76 = SLODWORD(v75->m_edge.m_triangle);
        v77 = &v16->m_data[v76];
        if ( v3->m_config.m_protectMaterialBoundaries.m_bool
          && (v194.m_storage.m_words.m_data[v76 >> 5] >> (v76 & 0x1F)) & 1
          && v77->m_material != v62 )
        {
          v77->m_isFixed = 1;
        }
        else
        {
          v194.m_storage.m_words.m_data[(signed __int64)SLODWORD(v75->m_edge.m_triangle) >> 5] |= 1 << (v76 & 0x1F);
          v77->m_material = v62;
        }
        v78 = (signed int *)&v77->m_ring;
        if ( v77->m_ring.m_size == (v77->m_ring.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v78, 8);
          v62 = (signed int)retaddr;
        }
        v79 = (hkgpIndexedMeshDefinitions::Triangle **)(*(_QWORD *)v78 + 8i64 * v78[2]);
        if ( v79 )
          *v79 = v48;
        ++v78[2];
        v75 = (hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *)((char *)v75 + 4);
        --v23;
      }
      while ( v23 );
      v48 = v48->m_next;
      v50 = v197;
      v80 = &retaddr;
      if ( !v48 )
        v80 = 0i64;
    }
    while ( v80 );
  }
  v194.m_storage.m_words.m_size = v23;
  if ( v194.m_storage.m_words.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v194.m_storage.m_words.m_data,
      4 * v194.m_storage.m_words.m_capacityAndFlags);
  v81 = v3->m_topology.m_triangles.m_used;
  v190.m_edge.m_index = v23;
  v190.m_edge.m_triangle = v81;
  _mm_store_si128((__m128i *)&v190, (__m128i)v190);
  if ( v81 )
  {
    v82 = v81->m_vertices[1]->m_index;
    v83 = v81->m_vertices[0]->m_index;
    if ( v83 >= v82 )
    {
      v84 = v23;
      LOBYTE(v84) = v83 > v82;
      if ( v84 > 0 )
      {
        if ( v81->m_links[0] & 0xFFFFFFFFFFFFFFFCui64 )
          hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v190);
      }
    }
  }
  v85 = v190.m_edge.m_triangle;
  v86 = &v190;
  if ( !v190.m_edge.m_triangle )
    v86 = 0i64;
  if ( v86 )
  {
    v87 = v190.m_edge.m_index;
    while ( 1 )
    {
      v88 = v85->m_links[v87];
      if ( v88 & 0xFFFFFFFFFFFFFFFCui64 )
      {
        if ( v3->m_config.m_maxAngle > 3.1415927 )
          goto LABEL_88;
        v107 = v3->m_geometry->m_vertices.m_data;
        v108 = v107[v85->m_vertices[v87]->m_index].m_quad;
        v89 = (9i64 >> 2 * (unsigned __int8)v87) & 3;
        v109 = v85->m_vertices[(18i64 >> 2 * (unsigned __int8)v87) & 3];
        v195.m_col0.m_quad = _mm_sub_ps(v107[v85->m_vertices[v89]->m_index].m_quad, v108);
        *(__m128 *)((char *)&v195.m_col0.m_quad + 8) = _mm_sub_ps(v107[v109->m_index].m_quad, v108);
        *(__m128 *)((char *)&v195.m_col1.m_quad + 8) = _mm_sub_ps(
                                                         v107[*(_QWORD *)(*(_QWORD *)((v88 & 0xFFFFFFFFFFFFFFFCui64)
                                                                                    + 8
                                                                                    * ((18i64 >> 2
                                                                                               * ((unsigned __int8)v88 & 3u)) & 3)
                                                                                    + 16)
                                                                        + 16i64)].m_quad,
                                                         v108);
        hkMatrix3f::getDeterminant(&v195, (hkSimdFloat32 *)&v194);
        if ( *(float *)&v194.m_storage.m_words.m_data < 0.0 )
          goto LABEL_88;
        v110 = _mm_mul_ps(
                 v27->m_data[(signed __int64)SLODWORD(v85->m_index)].m_plane.m_quad,
                 v27->m_data[(signed __int64)*(signed int *)((v85->m_links[v87] & 0xFFFFFFFFFFFFFFFCui64) + 64)].m_plane.m_quad);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v110, v110, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v110, v110, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v110, v110, 170))) >= v14 )
          goto LABEL_88;
      }
      else
      {
        v16->m_data[(signed __int64)SLODWORD(v85->m_vertices[v87]->m_index)].m_isNaked = 1;
        v89 = (9i64 >> 2 * (unsigned __int8)v87) & 3;
        v16->m_data[(signed __int64)SLODWORD(v85->m_vertices[v89]->m_index)].m_isNaked = 1;
        if ( !v3->m_config.m_protectNakedBoundaries.m_bool )
        {
          v90 = v27->m_data[(signed __int64)SLODWORD(v85->m_index)].m_plane.m_quad;
          v91 = v3->m_geometry->m_vertices.m_data;
          v92 = v91[SLODWORD(v85->m_vertices[v87]->m_index)].m_quad;
          LODWORD(retaddr) = v3->m_triangles.m_size;
          v93 = _mm_sub_ps(v91[SLODWORD(v85->m_vertices[v89]->m_index)].m_quad, v92);
          v94 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v90, v90, 201), v93),
                  _mm_mul_ps(_mm_shuffle_ps(v93, v93, 201), v90));
          v95 = _mm_shuffle_ps(v94, v94, 201);
          v96 = _mm_mul_ps(v95, v95);
          v97 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v96, v96, 85), _mm_shuffle_ps(v96, v96, 0)),
                  _mm_shuffle_ps(v96, v96, 170));
          v98 = _mm_rsqrt_ps(v97);
          v99 = _mm_mul_ps(
                  v95,
                  _mm_andnot_ps(
                    _mm_cmpleps(v97, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v98, v97), v98)),
                      _mm_mul_ps(*(__m128 *)_xmm, v98))));
          v100 = _mm_mul_ps(v99, v92);
          v101 = _mm_shuffle_ps(
                   v99,
                   _mm_unpackhi_ps(
                     v99,
                     _mm_sub_ps(
                       (__m128)0i64,
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v100, v100, 85), _mm_shuffle_ps(v100, v100, 0)),
                         _mm_shuffle_ps(v100, v100, 170)))),
                   196);
          if ( v3->m_triangles.m_size == (v3->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v3->m_triangles,
              64);
          v102 = (signed int)retaddr;
          v103 = (signed __int64)&v3->m_triangles.m_data[(signed __int64)v3->m_triangles.m_size++];
          *(_QWORD *)(v103 + 40) = -1i64;
          *(_DWORD *)(v103 + 48) = -1;
          *(__m128 *)v103 = v101;
          *(_QWORD *)(v103 + 16) = 0i64;
          *(_QWORD *)(v103 + 24) = 0i64;
          *(_QWORD *)(v103 + 32) = 0i64;
          v104 = v85->m_index;
          *(_BYTE *)(v103 + 56) = 0;
          *(_DWORD *)(v103 + 52) = v104;
          v27->m_data->m_planes[v87 + 16i64 * SLODWORD(v85->m_index)] = (signed int)retaddr;
          v105 = (signed __int64)&v16->m_data[(signed __int64)SLODWORD(v85->m_vertices[v87]->m_index)];
          if ( *(_DWORD *)(v105 + 8) == (*(_DWORD *)(v105 + 12) & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v16->m_data[(signed __int64)SLODWORD(v85->m_vertices[v87]->m_index)],
              4);
            v102 = (signed int)retaddr;
          }
          *(_DWORD *)(*(_QWORD *)v105 + 4i64 * (signed int)(*(_DWORD *)(v105 + 8))++) = v102;
          v106 = (signed __int64)&v16->m_data[(signed __int64)SLODWORD(v85->m_vertices[v89]->m_index)];
          if ( *(_DWORD *)(v106 + 8) == (*(_DWORD *)(v106 + 12) & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v16->m_data[(signed __int64)SLODWORD(v85->m_vertices[v89]->m_index)],
              4);
            v102 = (signed int)retaddr;
          }
          *(_DWORD *)(*(_QWORD *)v106 + 4i64 * (signed int)(*(_DWORD *)(v106 + 8))++) = v102;
          goto LABEL_88;
        }
      }
      v16->m_data[(signed __int64)SLODWORD(v85->m_vertices[v87]->m_index)].m_isFixed = 1;
      v16->m_data[(signed __int64)SLODWORD(v85->m_vertices[v89]->m_index)].m_isFixed = 1;
LABEL_88:
      if ( v85 )
      {
        hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v190);
        v87 = v190.m_edge.m_index;
        v85 = v190.m_edge.m_triangle;
      }
      v111 = &v190;
      if ( !v85 )
        v111 = 0i64;
      if ( !v111 )
      {
        v23 = 0i64;
        break;
      }
    }
  }
  v112 = 2 * v3->m_triangles.m_size;
  v113 = 0;
  array = 0i64;
  v192 = 0;
  v193 = 2147483648;
  if ( v112 > 0 )
  {
    if ( v112 < 0 )
      v112 = v23;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      v112,
      16);
    v113 = v192;
  }
  v114 = v3->m_topology.m_triangles.m_used;
  v190.m_edge.m_index = v23;
  v190.m_edge.m_triangle = v114;
  _mm_store_si128((__m128i *)&v190, (__m128i)v190);
  if ( v114 )
  {
    v115 = v114->m_vertices[1]->m_index;
    v116 = v114->m_vertices[0]->m_index;
    if ( v116 >= v115 )
    {
      v117 = v23;
      LOBYTE(v117) = v116 > v115;
      if ( v117 > 0 )
      {
        if ( v114->m_links[0] & 0xFFFFFFFFFFFFFFFCui64 )
          hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v190);
      }
    }
  }
  v118 = v190.m_edge.m_triangle;
  v119 = &v190;
  if ( !v190.m_edge.m_triangle )
    v119 = 0i64;
  if ( v119 )
  {
    do
    {
      if ( v113 == (v193 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
        v113 = v192;
      }
      v120 = (hkgpIndexedMeshDefinitions::Triangle **)&array[16 * v113];
      if ( v120 )
      {
        v121 = *(hkgpIndexedMeshDefinitions::Triangle **)&v190.m_edge.m_index;
        *v120 = v118;
        v120[1] = v121;
        v113 = v192;
      }
      v192 = ++v113;
      if ( v118 )
      {
        hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v190);
        v118 = v190.m_edge.m_triangle;
      }
      v122 = &v190;
      if ( !v118 )
        v122 = 0i64;
    }
    while ( v122 );
  }
  v123 = v23;
  if ( v113 > 0 )
  {
    v124 = 0i64;
    do
    {
      v125 = array;
      v124 += 16i64;
      v126 = v3->m_edgesTree.m_prng.m_w + v3->m_edgesTree.m_prng.m_c;
      v127 = v3->m_edgesTree.m_prng.m_y ^ 32 * v3->m_edgesTree.m_prng.m_y ^ ((v3->m_edgesTree.m_prng.m_y ^ 32 * v3->m_edgesTree.m_prng.m_y) >> 7) ^ ((v3->m_edgesTree.m_prng.m_y ^ 32 * v3->m_edgesTree.m_prng.m_y ^ ((v3->m_edgesTree.m_prng.m_y ^ 32 * v3->m_edgesTree.m_prng.m_y) >> 7)) << 22);
      v128 = (signed int)(v3->m_edgesTree.m_prng.m_z + v126) < 0;
      v129 = v3->m_edgesTree.m_prng.m_z + v126;
      v3->m_edgesTree.m_prng.m_z = v3->m_edgesTree.m_prng.m_w;
      v3->m_edgesTree.m_prng.m_y = v127;
      v130 = v23;
      LOBYTE(v130) = v128;
      v3->m_edgesTree.m_prng.m_x += 1411392427;
      v129 &= 0x7FFFFFFFu;
      v3->m_edgesTree.m_prng.m_c = v130;
      v131 = v3->m_edgesTree.m_prng.m_x;
      v3->m_edgesTree.m_prng.m_w = v129;
      ++v123;
      v132 = v129 + v127 + v131;
      v133 = *(_QWORD *)&v125[v124 - 16];
      v134 = *(_QWORD *)&v125[v124 - 8];
      v135 = &v125[16 * ((signed int)(v132 >> 1) % v113)];
      *(_QWORD *)&v125[v124 - 16] = *(_QWORD *)v135;
      *(_QWORD *)&v125[v124 - 8] = *((_QWORD *)v135 + 1);
      *(_QWORD *)v135 = v133;
      *((_QWORD *)v135 + 1) = v134;
      v113 = v192;
    }
    while ( v123 < v192 );
  }
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::preAllocateNodes(&v3->m_edgesTree, v113);
  v136 = v192;
  v137 = v3->m_edgesStorage.m_capacityAndFlags & 0x3FFFFFFF;
  v138 = v192;
  if ( v137 < v192 )
  {
    v139 = 2 * v137;
    if ( v192 < v139 )
      v136 = v139;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v3->m_edgesStorage,
      v136,
      48);
    v136 = v192;
  }
  v140 = v3->m_edgesStorage.m_size;
  v141 = v138 - (signed int)v140;
  if ( v138 - (signed int)v140 > 0 )
  {
    v142 = &v3->m_edgesStorage.m_data[v140].m_action;
    do
    {
      if ( v142 != (hkgpCgoInternal::Action *)36 )
        *(_DWORD *)v142 &= 0xFFFFFFFC;
      v142 += 12;
      --v141;
    }
    while ( v141 );
    v136 = v192;
  }
  v143 = (void **)&v3->m_invalidEdges.m_data;
  v3->m_edgesStorage.m_size = v138;
  v144 = v136;
  v145 = v3->m_invalidEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v145 < v136 )
  {
    v146 = 2 * v145;
    if ( v136 < v146 )
      v136 = v146;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v3->m_invalidEdges,
      v136,
      8);
    v136 = v192;
  }
  v3->m_invalidEdges.m_size = v144;
  v147 = v23;
  if ( v136 > 0 )
  {
    v148 = 0i64;
    v149 = 0i64;
    do
    {
      v150 = (char *)v3->m_edgesStorage.m_data + v23;
      *(_QWORD *)((char *)*v143 + v149) = v150;
      v151 = array;
      *(_QWORD *)v150 = *(_QWORD *)&array[v148];
      v152 = *(_QWORD *)&v151[v148 + 8];
      *((_OWORD *)v150 + 1) = 0i64;
      *((_QWORD *)v150 + 1) = v152;
      *((_DWORD *)v150 + 8) = 2139095022;
      v153 = *(hkArray<unsigned int,hkContainerHeapAllocator> *)v150;
      *((_DWORD *)v150 + 11) = v147;
      *((_DWORD *)v150 + 10) = 0;
      v194.m_storage.m_words = v153;
      hkgpCgoInternal::setEdgeInfo(v3, (hkgpIndexedMeshDefinitions::Edge *)&v194, (hkgpCgoInternal::EdgeInfo *)v150);
      ++v147;
      v23 += 48i64;
      v149 += 8i64;
      v148 += 16i64;
    }
    while ( v147 < v192 );
    v16 = &v3->m_vertices;
    LODWORD(v23) = 0;
  }
  v154 = v23;
  if ( v3->m_vertices.m_size > 0 )
  {
    v155 = 0i64;
    do
    {
      v156 = v16->m_data[v155].m_planes.m_size;
      if ( v156 > 1 )
        hkAlgorithm::quickSortRecursive<int,hkAlgorithm::less<int>>(v16->m_data[v155].m_planes.m_data, 0, v156 - 1, 0);
      v157 = v16->m_data[v155].m_ring.m_size;
      if ( v157 > 1 )
        hkAlgorithm::quickSortRecursive<hkgpCgoInternal::HTriangle,hkAlgorithm::less<hkgpCgoInternal::HTriangle>>(
          v16->m_data[v155].m_ring.m_data,
          0,
          v157 - 1,
          0);
      ++v154;
      ++v155;
    }
    while ( v154 < v3->m_vertices.m_size );
  }
  if ( v3->m_config.m_decimateComponents.m_bool )
  {
    retaddr = &hkgpIndexedMesh::EdgeBarrier::`vftable;
    hkgpIndexedMesh::computeSets(&v3->m_topology, (hkgpIndexedMesh::EdgeBarrier *)&retaddr);
    v158 = v3->m_topology.m_sets.m_size;
    v159 = 0;
    v190.m_edge.m_triangle = 0i64;
    *(&v190.m_edge.m_index + 1) = 2147483648;
    v190.m_edge.m_index = 0;
    v160 = _mm_xor_ps(
             (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
             (__m128)xmmword_141A712A0);
    if ( v158 > 0 )
    {
      v161 = v158;
      if ( v158 < 0 )
        v161 = v23;
      hkArrayUtil::_reserve(
        (hkResult *)&retaddr,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v190,
        v161,
        32);
      v159 = v190.m_edge.m_index;
    }
    v162 = v158 - v159;
    v163 = (_OWORD *)((char *)v190.m_edge.m_triangle + 32 * (signed int)v159);
    v164 = (signed int)(v158 - v159);
    if ( v162 > 0 )
    {
      do
      {
        if ( v163 )
        {
          *v163 = xmmword_141A712A0;
          v163[1] = v160;
        }
        v163 += 2;
        --v164;
      }
      while ( v164 );
    }
    v165 = v3->m_topology.m_triangles.m_used;
    v166 = &retaddr;
    v190.m_edge.m_index = v158;
    if ( !v165 )
      v166 = 0i64;
    if ( v166 )
    {
      do
      {
        v167 = v3->m_geometry->m_vertices.m_data;
        v168 = v167[SLODWORD(v165->m_vertices[1]->m_index)].m_quad;
        v169 = (__m128 *)((char *)v190.m_edge.m_triangle + 32 * v165->m_set);
        v170 = _mm_max_ps(
                 v169[1],
                 _mm_max_ps(
                   _mm_max_ps(v167[SLODWORD(v165->m_vertices[0]->m_index)].m_quad, v168),
                   v167[SLODWORD(v165->m_vertices[2]->m_index)].m_quad));
        *v169 = _mm_min_ps(
                  *v169,
                  _mm_min_ps(
                    _mm_min_ps(v167[SLODWORD(v165->m_vertices[0]->m_index)].m_quad, v168),
                    v167[SLODWORD(v165->m_vertices[2]->m_index)].m_quad));
        v169[1] = v170;
        v165 = v165->m_next;
        v171 = &retaddr;
        if ( !v165 )
          v171 = 0i64;
      }
      while ( v171 );
    }
    v172 = v3->m_topology.m_sets.m_size;
    v173 = &v3->m_sets.m_data;
    v174 = v3->m_sets.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v174 < v172 )
    {
      v175 = 2 * v174;
      v176 = v3->m_topology.m_sets.m_size;
      if ( v172 < v175 )
        v176 = v175;
      hkArrayUtil::_reserve(
        (hkResult *)&retaddr,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v3->m_sets,
        v176,
        8);
    }
    v177 = v190.m_edge.m_index == 0;
    v128 = (v190.m_edge.m_index & 0x80000000) != 0;
    v3->m_sets.m_size = v172;
    v178 = v23;
    if ( !v128 && !v177 )
    {
      v179 = 0i64;
      v180 = 0i64;
      do
      {
        v180 += 32i64;
        ++v179;
        v181 = _mm_sub_ps(
                 *(__m128 *)((char *)v190.m_edge.m_triangle + v180 - 32),
                 *(__m128 *)((char *)v190.m_edge.m_triangle + v180 - 16));
        v182 = _mm_mul_ps(v181, v181);
        v183 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v182, v182, 85), _mm_shuffle_ps(v182, v182, 0)),
                 _mm_shuffle_ps(v182, v182, 170));
        v184 = _mm_rsqrt_ps(v183);
        (*v173)[v178].m_error = COERCE_FLOAT(
                                  _mm_andnot_ps(
                                    _mm_cmpleps(v183, (__m128)0i64),
                                    _mm_mul_ps(
                                      _mm_mul_ps(
                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v184, v183), v184)),
                                        _mm_mul_ps(*(__m128 *)_xmm, v184)),
                                      v183)))
                              * 0.5;
        *((_DWORD *)&(*v173)[v179] - 1) = v178++;
      }
      while ( v178 < (signed int)v190.m_edge.m_index );
    }
    v185 = v3->m_sets.m_size;
    if ( v185 > 1 )
      hkAlgorithm::quickSortRecursive<hkgpCgoInternal::Set,hkAlgorithm::greater<hkgpCgoInternal::Set>>(
        *v173,
        0,
        v185 - 1,
        0);
    v190.m_edge.m_index = v23;
    if ( (*(&v190.m_edge.m_index + 1) & 0x80000000) == 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v190.m_edge.m_triangle,
        32 * *(&v190.m_edge.m_index + 1));
  }
  hkgpCgoInternal::update(v3);
  v186 = v3->m_invalidEdges.m_capacityAndFlags;
  v3->m_invalidEdges.m_size = v23;
  if ( v186 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *v143,
      8 * v186);
  *v143 = 0i64;
  v3->m_invalidEdges.m_capacityAndFlags = 2147483648;
  v187 = v3->m_invalidEdges.m_capacityAndFlags & 0x3FFFFFFF;
  v188 = 256;
  if ( v187 < 256 )
  {
    v189 = 2 * v187;
    if ( v189 > 256 )
      v188 = v189;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v143,
      v188,
      8);
  }
  v192 = v23;
  if ( v193 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v193);
}bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v190.m_edge.m_triangle,
        32 * *(&v190.m_edge.m_index + 1));
  }
  hkgpCgoInternal::update(v3);
  v186 = v3->m_invalidEdges.m_capacityAndFlags;
  v3->m_invalidEdges.m_size = v23;
  if ( v186 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,

// File Line: 445
// RVA: 0xCE6B30
void __fastcall hkgpCgoInternal::analyze(hkgpCgoInternal *this, hkArray<hkgpCgo::ClusterData,hkContainerHeapAllocator> *clusters)
{
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16> *v2; // rdi
  signed __int64 v3; // rax
  hkArray<hkgpCgo::ClusterData,hkContainerHeapAllocator> *v4; // rbx
  int v5; // edx
  int v6; // er9
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::Node *v7; // r14
  signed __int64 v8; // rsi
  int v9; // er8
  hkgpCgoInternal::EdgeInfo *v10; // r15
  int v11; // er8
  int v12; // er8
  int v13; // edx
  __int64 v14; // rcx
  signed __int64 v15; // r9
  __int64 v16; // r8
  signed __int64 v17; // rdx
  hkgpCgo::ClusterData *v18; // rcx
  float v19; // xmm0_4
  signed int v20; // er8
  int v21; // er8
  __int64 v22; // r10
  hkgpCgo::ClusterData *v23; // rcx
  int v24; // eax
  __int64 v25; // rdx
  int v26; // eax
  hkgpCgoInternal::ErrorCollector functor; // [rsp+30h] [rbp-40h]
  hkArray<int,hkContainerHeapAllocator> clusterIds; // [rsp+40h] [rbp-30h]
  float v29; // [rsp+88h] [rbp+18h]

  v2 = &this->m_edgesTree;
  v3 = this->m_edgesTree.m_root;
  v4 = clusters;
  v5 = 2147483648;
  functor.m_values.m_data = 0i64;
  v6 = 0;
  functor.m_values.m_size = 0;
  functor.m_values.m_capacityAndFlags = 2147483648;
  if ( (_DWORD)v3 )
  {
    v7 = v2->m_nodes.m_data;
    v8 = v3;
    v9 = v2->m_nodes.m_data[v3].m_children[0];
    if ( v9 )
    {
      hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::traverseMinMax<hkgpCgoInternal::ErrorCollector>(
        &this->m_edgesTree,
        &functor,
        v9);
      v5 = functor.m_values.m_capacityAndFlags;
      v6 = functor.m_values.m_size;
    }
    v10 = v7[v8].m_value;
    if ( v10->m_error < 3.40282e38 )
    {
      if ( v6 == (v5 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &functor, 4);
        v6 = functor.m_values.m_size;
      }
      functor.m_values.m_data[v6] = v10->m_error;
      ++functor.m_values.m_size;
    }
    v11 = v7[v8].m_children[1];
    if ( v11 )
      hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::traverseMinMax<hkgpCgoInternal::ErrorCollector>(
        v2,
        &functor,
        v11);
  }
  v12 = v4->m_size;
  clusterIds.m_data = 0i64;
  clusterIds.m_size = 0;
  clusterIds.m_capacityAndFlags = 2147483648;
  hkGeometryProcessing::generateClusters(&functor.m_values, 0i64, v12, &clusterIds, 512);
  v13 = 0;
  if ( v4->m_size > 0 )
  {
    v14 = 0i64;
    do
    {
      ++v13;
      ++v14;
      v4->m_data[v14 - 1].m_errorRange[0] = 3.40282e38;
      *((_DWORD *)&v4->m_data[v14] - 2) = -8388626;
      *((_DWORD *)&v4->m_data[v14] - 1) = 0;
    }
    while ( v13 < v4->m_size );
  }
  v15 = 0i64;
  if ( functor.m_values.m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      v15 = (unsigned int)(v15 + 1);
      ++v16;
      v17 = clusterIds.m_data[v16 - 1];
      v18 = v4->m_data;
      v29 = v4->m_data[clusterIds.m_data[v16 - 1]].m_errorRange[1];
      v18[v17].m_errorRange[0] = fminf(
                                   v4->m_data[clusterIds.m_data[v16 - 1]].m_errorRange[0],
                                   functor.m_values.m_data[v16 - 1]);
      v19 = functor.m_values.m_data[v16 - 1];
      ++v18[v17].m_numVertices;
      v18[v17].m_errorRange[1] = fmaxf(v29, v19);
    }
    while ( (signed int)v15 < functor.m_values.m_size );
  }
  v20 = v4->m_size;
  if ( v20 > 1 )
    hkAlgorithm::quickSortRecursive<hkgpCgo::ClusterData,hkAlgorithm::less<hkgpCgo::ClusterData>>(
      v4->m_data,
      0,
      v20 - 1,
      0);
  v21 = 0;
  if ( v4->m_size > 0 )
  {
    v22 = 0i64;
    do
    {
      v23 = &v4->m_data[v22];
      if ( !v23->m_numVertices )
      {
        --v4->m_size;
        v15 = (signed __int64)&v23[1];
        v24 = 12 * (v4->m_size - v21);
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
    while ( v21 < v4->m_size );
  }
  clusterIds.m_size = 0;
  if ( clusterIds.m_capacityAndFlags >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, _QWORD, signed __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      clusterIds.m_data,
      (unsigned int)(4 * clusterIds.m_capacityAndFlags),
      v15);
  clusterIds.m_data = 0i64;
  functor.m_values.m_size = 0;
  clusterIds.m_capacityAndFlags = 2147483648;
  if ( functor.m_values.m_capacityAndFlags >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, float *, _QWORD, signed __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      functor.m_values.m_data,
      (unsigned int)(4 * functor.m_values.m_capacityAndFlags),
      v15);
}

// File Line: 476
// RVA: 0xCE6E10
bool __fastcall hkgpCgoInternal::update(hkgpCgoInternal *this)
{
  hkgpCgoInternal *v1; // rsi
  bool v2; // r15
  int i; // er14
  int v4; // er9
  hkgpCgoInternal::EdgeInfo **v5; // rdi
  _QWORD **v6; // rax
  hkgpJobQueue::IJob *v7; // rax
  __int64 v8; // rcx
  int v9; // er8
  hkVector4f *v10; // rdx
  int v11; // ecx
  __int64 v12; // rbx
  hkgpCgoInternal::ProcessConfig pcfg; // [rsp+20h] [rbp-D8h]
  __int64 v15; // [rsp+D0h] [rbp-28h]

  v1 = this;
  v2 = this->m_config.m_multiThreaded.m_bool != 0;
  for ( i = 0; i < v1->m_invalidEdges.m_size; i += 16 )
  {
    v4 = 16;
    v5 = &v1->m_invalidEdges.m_data[i];
    if ( v1->m_invalidEdges.m_size - i < 16 )
      v4 = v1->m_invalidEdges.m_size - i;
    LODWORD(v15) = v4;
    if ( v2 )
    {
      v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v7 = (hkgpJobQueue::IJob *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 32i64);
      if ( v7 )
      {
        v8 = v15;
        v7[1].vfptr = (hkgpJobQueue::IJobVtbl *)v1;
        v7[2].vfptr = (hkgpJobQueue::IJobVtbl *)v5;
        v7[3].vfptr = (hkgpJobQueue::IJobVtbl *)v8;
        v7->vfptr = (hkgpJobQueue::IJobVtbl *)&hkgpJobQueue::Box<hkgpCgoInternal::UpdateJob>::`vftable;
        hkgpJobQueue::push(&v1->m_jobQueue, v7);
      }
      else
      {
        hkgpJobQueue::push(&v1->m_jobQueue, 0i64);
      }
    }
    else
    {
      *(_DWORD *)&pcfg.m_action &= 0xFFFFFFFC;
      v9 = 2147483648;
      v10 = 0i64;
      v11 = 2147483648;
      pcfg.m_ring.m_data = 0i64;
      pcfg.m_ring.m_size = 0;
      pcfg.m_ring.m_capacityAndFlags = 2147483648;
      pcfg.m_planes.m_data = 0i64;
      pcfg.m_planes.m_size = 0;
      pcfg.m_planes.m_capacityAndFlags = 2147483648;
      if ( v4 > 0 )
      {
        v12 = (unsigned int)v4;
        do
        {
          hkgpCgoInternal::updateEdge(v1, &pcfg, *v5);
          ++v5;
          --v12;
        }
        while ( v12 );
        v11 = pcfg.m_planes.m_capacityAndFlags;
        v10 = pcfg.m_planes.m_data;
        v9 = pcfg.m_ring.m_capacityAndFlags;
      }
      pcfg.m_planes.m_size = 0;
      if ( v11 >= 0 )
      {
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v10,
          16 * v11);
        v9 = pcfg.m_ring.m_capacityAndFlags;
      }
      pcfg.m_planes.m_data = 0i64;
      pcfg.m_planes.m_capacityAndFlags = 2147483648;
      pcfg.m_ring.m_size = 0;
      if ( v9 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          pcfg.m_ring.m_data,
          8 * v9);
    }
  }
  hkgpJobQueue::waitForCompletion(&v1->m_jobQueue);
  v1->m_invalidEdges.m_size = 0;
  return hkgpCgoInternal::getBestEdge(v1) != 0i64;
}

// File Line: 504
// RVA: 0xCE7010
hkgpCgoInternal::EdgeInfo *__fastcall hkgpCgoInternal::getBestEdge(hkgpCgoInternal *this)
{
  int v1; // edx
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::Node *v2; // r9
  hkgpCgoInternal::EdgeInfo *result; // rax

  if ( !this->m_edgesTree.m_root )
    return 0i64;
  v1 = this->m_edgesTree.m_root;
  if ( v1 )
  {
    while ( 1 )
    {
      v2 = this->m_edgesTree.m_nodes.m_data;
      if ( !v2[v1].m_children[0] )
        break;
      v1 = v2[v1].m_children[0];
    }
  }
  result = this->m_edgesTree.m_nodes.m_data[v1].m_value;
  if ( result->m_error >= 3.40282e38 )
    return 0i64;
  return result;
}

// File Line: 519
// RVA: 0xCE7070
void __fastcall hkgpCgoInternal::getErrors(hkgpCgoInternal *this, hkArray<float,hkContainerHeapAllocator> *errors)
{
  hkArray<float,hkContainerHeapAllocator> *v2; // rsi
  hkgpCgoInternal *v3; // rbp
  signed __int64 v4; // rdx
  signed int v5; // edi
  signed __int64 v6; // r8
  int *v7; // rax
  signed __int64 i; // rbx
  hkgpCgoInternal::EdgeInfo *v9; // r14
  signed __int64 v10; // r9
  signed __int64 v11; // rax
  int v12; // edx
  hkgpCgoInternal::EdgeInfo **v13; // r8
  signed int v14; // er8

  errors->m_size = 0;
  v2 = errors;
  v3 = this;
  if ( this->m_edgesTree.m_root )
  {
    v4 = this->m_edgesTree.m_nodes.m_size;
    v5 = 1;
    v6 = 1i64;
    if ( v4 <= 1 )
    {
LABEL_6:
      v5 = 0;
    }
    else
    {
      v7 = this->m_edgesTree.m_nodes.m_data[1].m_children;
      while ( *v7 == v5 )
      {
        ++v6;
        ++v5;
        v7 += 6;
        if ( v6 >= v4 )
          goto LABEL_6;
      }
    }
    for ( i = v5; i; v5 = v12 )
    {
      v9 = v3->m_edgesTree.m_nodes.m_data[i].m_value;
      if ( v2->m_size == (v2->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 4);
      v2->m_data[v2->m_size++] = v9->m_error;
      if ( !i )
        break;
      v10 = v3->m_edgesTree.m_nodes.m_size;
      v11 = i + 1;
      v12 = v5 + 1;
      i = v11;
      if ( v11 >= v10 )
        break;
      v13 = &v3->m_edgesTree.m_nodes.m_data->m_value + 3 * v11 + 1;
      while ( *(_DWORD *)v13 == v12 )
      {
        ++i;
        ++v12;
        v13 += 3;
        if ( i >= v10 )
          goto LABEL_17;
      }
    }
LABEL_17:
    v14 = v2->m_size;
    if ( v14 > 1 )
      hkAlgorithm::quickSortRecursive<float,hkAlgorithm::less<float>>(v2->m_data, 0, v14 - 1, 0);
  }
}

// File Line: 533
// RVA: 0xCE8940
char __fastcall hkgpCgoInternal::solveVertex(hkgpCgoInternal *this, hkgpCgoInternal::ProcessConfig *pcfg, bool project, hkVector4f *vertex)
{
  hkgpCgoInternal::ProcessConfig *v4; // rbx
  hkgpCgoInternal *v5; // rdi
  hkVector4f v6; // xmm0
  hkSimdFloat32 v7; // xmm1
  char result; // al
  hkVector4f vertexa; // [rsp+20h] [rbp-48h]
  hkgpCgoInternal::ProcessedVertex vertexOut; // [rsp+30h] [rbp-38h]
  int v11; // [rsp+80h] [rbp+18h]

  v4 = pcfg;
  v5 = this;
  _mm_store_si128((__m128i *)&vertexa, (__m128i)vertex->m_quad);
  if ( project && !hkgpCgoInternal::projectVertex(this, &pcfg->m_planes, &vertexa)
    || !hkgpCgoInternal::processVertex(v5, v4, &vertexa, &vertexOut) )
  {
    return 0;
  }
  v6.m_quad = (__m128)vertexOut.m_vertex;
  v7.m_real = (__m128)vertexOut.m_error;
  v4->m_action = (hkgpCgoInternal::Action)(v11 & 0xFFFFFFFE | 2);
  result = 1;
  v4->m_vertex = (hkVector4f)v6.m_quad;
  v4->m_maxError = (hkSimdFloat32)v7.m_real;
  return result;
}

// File Line: 554
// RVA: 0xCE71C0
void __fastcall hkgpCgoInternal::updateEdge(hkgpCgoInternal *this, hkgpCgoInternal::ProcessConfig *pcfg, hkgpCgoInternal::EdgeInfo *e)
{
  hkgpCgoInternal *v3; // rsi
  hkgpCgoInternal::ProcessConfig *v4; // rdi
  hkgpCgoInternal::Action v5; // eax
  __int64 v6; // r14
  hkgpCgoInternal::EdgeInfo *v7; // r9
  __int64 v8; // r8
  __int64 v9; // rdx
  hkgpCgoInternal::VertexInfo *v10; // rax
  unsigned __int64 v11; // r15
  hkgpCgoInternal::VertexInfo *v12; // rbx
  float v13; // xmm0_4
  hkgpCgo::Config::VertexCombinator v14; // ecx
  int v15; // ecx
  __m128 v16; // xmm1
  int v17; // er9
  int v18; // eax
  int v19; // eax
  int v20; // er13
  __int64 v21; // r12
  hkVector4f *v22; // r15
  int v23; // er13
  __int64 v24; // r12
  hkVector4f *v25; // r15
  char v26; // dl
  hkgpCgoInternal::ICustomMetric *v27; // rcx
  bool v28; // zf
  unsigned __int8 v29; // cl
  bool v30; // al
  __m128 *v31; // r15
  __m128 *v32; // r12
  __m128 v33; // xmm11
  signed int v34; // er11
  hkVector4f *v35; // r10
  __int64 v36; // r9
  signed int v37; // er14
  __m128 v38; // xmm10
  __m128 v39; // xmm5
  __m128 v40; // xmm1
  __m128 v41; // xmm3
  __m128 v42; // xmm2
  __m128 v43; // xmm9
  __m128 v44; // xmm10
  __m128 v45; // xmm9
  __m128 v46; // xmm3
  __m128 *v47; // rax
  __int64 v48; // rcx
  __m128 v49; // xmm2
  __m128 v50; // xmm2
  __m128 v51; // xmm2
  __m128 v52; // xmm0
  __m128 v53; // xmm2
  __m128 v54; // xmm2
  __m128 v55; // xmm1
  __m128 v56; // xmm1
  __m128 v57; // xmm2
  __m128 v58; // xmm1
  __m128 v59; // xmm0
  __int64 v60; // r9
  hkVector4f v61; // xmm0
  hkSimdFloat32 v62; // xmm1
  int v63; // er15
  __m128 v64; // xmm10
  int *v65; // rdx
  float v66; // xmm10_4
  int v67; // er9
  __m128 v68; // xmm6
  __m128 v69; // xmm7
  int v70; // er13
  __m128 v71; // xmm11
  __int64 v72; // rcx
  __m128 v73; // xmm11
  hkSimdFloat32 v74; // xmm9
  signed int v75; // ebx
  signed int v76; // er15
  __m128 v77; // xmm8
  __m128 v78; // xmm6
  signed __int64 v79; // r12
  __m128 v80; // xmm2
  __m128 v81; // xmm2
  hkArray<int,hkContainerHeapAllocator> v82; // xmm1
  bool v83; // r8
  __m128 v84; // xmm7
  __m128 v85; // xmm6
  bool v86; // sf
  unsigned __int8 v87; // of
  hkVector4f v88; // xmm0
  hkSimdFloat32 v89; // xmm1
  float *v90; // rdx
  hkVector4f *v91; // r9
  hkgpCgoInternal::Action v92; // eax
  float v93; // xmm0_4
  _RTL_CRITICAL_SECTION *v94; // rdi
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16> *v95; // rsi
  __int64 v96; // rbx
  hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::Node *v97; // r9
  __int64 v98; // r14
  hkArray<int,hkContainerHeapAllocator> output; // [rsp+30h] [rbp-A8h]
  hkVector4f x; // [rsp+40h] [rbp-98h]
  hkgpCgoInternal::ProcessedVertex vertexOut; // [rsp+50h] [rbp-88h]
  hkResult result; // [rsp+328h] [rbp+250h]
  float v103; // [rsp+330h] [rbp+258h]
  hkgpCgoInternal::EdgeInfo *v104; // [rsp+338h] [rbp+260h]

  v3 = this;
  v4 = pcfg;
  v5 = (hkgpCgoInternal::Action)((unsigned int)v104 & 0xFFFFFFFC);
  v6 = 0i64;
  v7 = e;
  pcfg->m_ring.m_size = 0;
  pcfg->m_action = v5;
  pcfg->m_planes.m_size = 0;
  pcfg->m_vertex = 0i64;
  pcfg->m_maxError = (hkSimdFloat32)xmmword_141A712A0;
  v8 = SLODWORD(e->m_edge.m_triangle->m_vertices[e->m_edge.m_index]->m_index);
  pcfg->m_edgeIndices[0] = v8;
  v9 = SLODWORD(v7->m_edge.m_triangle->m_vertices[(9i64 >> 2 * (unsigned __int8)v7->m_edge.m_index) & 3]->m_index);
  v4->m_edgeIndices[1] = v9;
  v4->m_edgeVertices[0] = this->m_geometry->m_vertices.m_data[v8];
  v4->m_edgeVertices[1] = this->m_geometry->m_vertices.m_data[v9];
  v10 = this->m_vertices.m_data;
  v11 = (unsigned __int64)&v10[v8];
  v12 = &v10[v9];
  x.m_quad.m128_u64[0] = v11;
  v13 = v12->m_error;
  result.m_enum = *(_DWORD *)(v11 + 48);
  v103 = v13;
  result.m_enum = fmaxf(*(float *)&result.m_enum, v13);
  v4->m_vtxError.m_real = _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0);
  v14 = this->m_config.m_combinator;
  if ( v14 )
  {
    v15 = v14 - 1;
    if ( v15 )
    {
      if ( v15 != 1 )
        goto LABEL_8;
      v16 = _mm_mul_ps(
              _mm_add_ps(
                _mm_shuffle_ps(v4->m_edgeVertices[1].m_quad, v4->m_edgeVertices[1].m_quad, 255),
                _mm_shuffle_ps(v4->m_edgeVertices[0].m_quad, v4->m_edgeVertices[0].m_quad, 255)),
              (__m128)xmmword_141A711B0);
    }
    else
    {
      v16 = _mm_max_ps(
              _mm_shuffle_ps(v4->m_edgeVertices[0].m_quad, v4->m_edgeVertices[0].m_quad, 255),
              _mm_shuffle_ps(v4->m_edgeVertices[1].m_quad, v4->m_edgeVertices[1].m_quad, 255));
    }
  }
  else
  {
    v16 = _mm_min_ps(
            _mm_shuffle_ps(v4->m_edgeVertices[0].m_quad, v4->m_edgeVertices[0].m_quad, 255),
            _mm_shuffle_ps(v4->m_edgeVertices[1].m_quad, v4->m_edgeVertices[1].m_quad, 255));
  }
  v4->m_vertexW.m_real = v16;
LABEL_8:
  v4->m_ring.m_size = 0;
  computeUnionOfSortedArray_hkgpCgoInternal::HTriangle_(
    (hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *)(v11 + 16),
    &v12->m_ring,
    &v4->m_ring);
  v4->m_planes.m_size = 0;
  output.m_data = 0i64;
  output.m_size = 0;
  output.m_capacityAndFlags = 2147483648;
  computeUnionOfSortedArray_int_((hkArray<int,hkContainerHeapAllocator> *)v11, &v12->m_planes, &output);
  v17 = v4->m_ring.m_size + output.m_size;
  v18 = v4->m_planes.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v18 < v17 )
  {
    v19 = 2 * v18;
    if ( v17 < v19 )
      v17 = v19;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v4->m_planes,
      v17,
      16);
  }
  v20 = 0;
  if ( v4->m_ring.m_size > 0 )
  {
    v21 = 0i64;
    do
    {
      v22 = &v3->m_triangles.m_data[(signed __int64)SLODWORD(v4->m_ring.m_data[v21].m_triangle->m_index)].m_plane;
      if ( v4->m_planes.m_size == (v4->m_planes.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_planes, 16);
      ++v20;
      ++v21;
      v4->m_planes.m_data[v4->m_planes.m_size++] = (hkVector4f)v22->m_quad;
    }
    while ( v20 < v4->m_ring.m_size );
  }
  v23 = 0;
  if ( output.m_size > 0 )
  {
    v24 = 0i64;
    do
    {
      v25 = &v3->m_triangles.m_data[(signed __int64)output.m_data[v24]].m_plane;
      if ( v4->m_planes.m_size == (v4->m_planes.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_planes, 16);
      ++v23;
      ++v24;
      v4->m_planes.m_data[v4->m_planes.m_size++] = (hkVector4f)v25->m_quad;
    }
    while ( v23 < output.m_size );
  }
  output.m_size = 0;
  if ( output.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      output.m_data,
      4 * output.m_capacityAndFlags);
  v26 = *(_BYTE *)(x.m_quad.m128_u64[0] + 52);
  if ( v26 && v12->m_isFixed )
    goto LABEL_66;
  v27 = v3->m_cstMetric;
  if ( v27 )
  {
    v27->vfptr->onUpdate(v27, v104, v4);
LABEL_66:
    v31 = (__m128 *)v4->m_edgeVertices;
    goto LABEL_67;
  }
  v28 = v26 == 0;
  if ( v26 )
  {
LABEL_64:
    LOBYTE(v6) = v28;
    if ( hkgpCgoInternal::processVertex(v3, v4, (hkVector4f *)&(&v4->m_ring.m_data)[2 * (v6 + 5)], &vertexOut) )
    {
      v88.m_quad = (__m128)vertexOut.m_vertex;
      v89.m_real = (__m128)vertexOut.m_error;
      v4->m_action = (hkgpCgoInternal::Action)((unsigned int)v104 & 0xFFFFFFFE | 2);
      v4->m_vertex = (hkVector4f)v88.m_quad;
      v4->m_maxError = (hkSimdFloat32)v89.m_real;
    }
    goto LABEL_66;
  }
  if ( v12->m_isFixed )
  {
    v28 = 1;
    goto LABEL_64;
  }
  v29 = *(_BYTE *)(x.m_quad.m128_u64[0] + 53);
  if ( v29 ^ v12->m_isNaked )
  {
    LOBYTE(v6) = v29 == 0;
    v30 = hkgpCgoInternal::processVertex(v3, v4, (hkVector4f *)&(&v4->m_ring.m_data)[2 * (v6 + 5)], &vertexOut);
    v31 = (__m128 *)v4->m_edgeVertices;
    v32 = &v4->m_edgeVertices[1].m_quad;
  }
  else
  {
    v31 = (__m128 *)v4->m_edgeVertices;
    if ( !(~((unsigned __int8)*(_DWORD *)&v4->m_action | (unsigned __int8)(*(_DWORD *)&v4->m_action >> 1)) & 1) )
    {
LABEL_67:
      v32 = &v4->m_edgeVertices[1].m_quad;
      goto LABEL_68;
    }
    hkgpCgoInternal::solveVertex(v3, v4, v3->m_config.m_project.m_bool != 0, v4->m_edgeVertices);
    v32 = &v4->m_edgeVertices[1].m_quad;
    hkgpCgoInternal::solveVertex(v3, v4, v3->m_config.m_project.m_bool != 0, &v4->m_edgeVertices[1]);
    if ( v3->m_config.m_useLegacySolver.m_bool )
    {
      v63 = v3->m_config.m_solverAccuracy;
      v64 = (__m128)LODWORD(v3->m_config.m_minConvergence);
      v65 = &vertexOut.m_error.m_real.m128_i32[2];
      vertexOut.m_error.m_real.m128_u64[0] = -9223371487098961920i64;
      LODWORD(v66) = (unsigned __int128)_mm_shuffle_ps(v64, v64, 0);
      v103 = *(float *)&v63;
      vertexOut.m_vertex.m_quad.m128_u64[1] = (unsigned __int64)&vertexOut.m_error.m_real.m128_u64[1];
      if ( v63 + 2 > 128 )
      {
        v67 = v63 + 2;
        if ( v63 + 2 < 256 )
          v67 = 256;
        hkArrayUtil::_reserve(
          &result,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &vertexOut.m_vertex.m_quad.m128_u16[4],
          v67,
          4);
        v65 = (int *)vertexOut.m_vertex.m_quad.m128_u64[1];
      }
      v68 = query.m_quad;
      vertexOut.m_error.m_real.m128_i32[0] = v63 + 2;
      v69 = 0i64;
      result.m_enum = 0;
      if ( v63 > 0 )
      {
        v70 = v63 + 1;
        v71 = 0i64;
        v72 = v63 + 1;
        v71.m128_f32[0] = (float)(v63 + 1);
        v73 = _mm_shuffle_ps(v71, v71, 0);
        while ( 1 )
        {
          v74.m_real = (__m128)v4->m_maxError;
          *v65 = v69.m128_i32[0];
          v75 = 0;
          v76 = 1;
          *(_DWORD *)(vertexOut.m_vertex.m_quad.m128_u64[1] + 4 * v72) = v68.m128_i32[0];
          v77 = _mm_div_ps(query.m_quad, v73);
          if ( v70 <= 1 )
            break;
          v78 = _mm_sub_ps(v68, v69);
          v79 = 4i64;
          do
          {
            v80 = 0i64;
            v80.m128_f32[0] = (float)v76;
            v81 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v80, v80, 0), v77), v78), v69);
            v82 = (hkArray<int,hkContainerHeapAllocator>)_mm_add_ps(
                                                           _mm_mul_ps(
                                                             _mm_sub_ps(
                                                               v4->m_edgeVertices[1].m_quad,
                                                               v4->m_edgeVertices[0].m_quad),
                                                             v81),
                                                           v4->m_edgeVertices[0].m_quad);
            *(_DWORD *)(v79 + vertexOut.m_vertex.m_quad.m128_u64[1]) = v81.m128_i32[0];
            v83 = v3->m_config.m_project.m_bool != 0;
            output = v82;
            if ( hkgpCgoInternal::solveVertex(v3, v4, v83, (hkVector4f *)&output) )
              v75 = v76;
            ++v76;
            v79 += 4i64;
          }
          while ( v76 < v70 );
          if ( !v75 || (float)(v74.m_real.m128_f32[0] - v4->m_maxError.m_real.m128_f32[0]) <= v66 )
            break;
          v65 = (int *)vertexOut.m_vertex.m_quad.m128_u64[1];
          v84 = (__m128)*(unsigned int *)(vertexOut.m_vertex.m_quad.m128_u64[1] + 4i64 * (v75 - 1));
          v69 = _mm_shuffle_ps(v84, v84, 0);
          v85 = (__m128)*(unsigned int *)(vertexOut.m_vertex.m_quad.m128_u64[1] + 4i64 * (v75 + 1));
          v87 = __OFSUB__(result.m_enum + 1, LODWORD(v103));
          v86 = result.m_enum++ + 1 - LODWORD(v103) < 0;
          v72 = v70;
          v68 = _mm_shuffle_ps(v85, v85, 0);
          if ( !(v86 ^ v87) )
            goto LABEL_61;
        }
        v65 = (int *)vertexOut.m_vertex.m_quad.m128_u64[1];
      }
LABEL_61:
      vertexOut.m_error.m_real.m128_i32[0] = 0;
      if ( vertexOut.m_error.m_real.m128_i32[1] >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v65,
          4 * vertexOut.m_error.m_real.m128_i32[1]);
      goto LABEL_66;
    }
    v33 = *v31;
    v34 = v3->m_config.m_solverAccuracy;
    v35 = v4->m_planes.m_data;
    v36 = v4->m_planes.m_size;
    v37 = 1;
    v38 = _mm_sub_ps(*v32, *v31);
    v39 = _mm_mul_ps(_mm_add_ps(*v31, *v32), (__m128)xmmword_141A711B0);
    v40 = _mm_mul_ps(v38, v38);
    output = (hkArray<int,hkContainerHeapAllocator>)v39;
    v41 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
            _mm_shuffle_ps(v40, v40, 170));
    v42 = _mm_rsqrt_ps(v41);
    v43 = _mm_andnot_ps(
            _mm_cmpleps(v41, (__m128)0i64),
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
        if ( v36 > 0 )
        {
          v47 = &v35->m_quad;
          v48 = v36;
          do
          {
            v49 = *v47;
            ++v47;
            v50 = _mm_mul_ps(v49, v39);
            v51 = _mm_shuffle_ps(v50, _mm_unpackhi_ps(v50, v47[-1]), 196);
            v52 = _mm_add_ps(_mm_shuffle_ps(v51, v51, 78), v51);
            v53 = _mm_add_ps(_mm_shuffle_ps(v52, v52, 177), v52);
            v54 = _mm_mul_ps(v53, v53);
            v55 = _mm_cmpltps(v46, v54);
            v46 = _mm_or_ps(_mm_and_ps(v55, v54), _mm_andnot_ps(v55, v46));
            --v48;
          }
          while ( v48 );
        }
        v56 = _mm_mul_ps(_mm_sub_ps(v39, v33), v44);
        v57 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
                _mm_shuffle_ps(v56, v56, 170));
        v58 = _mm_cmpltps(v57, v45);
        v59 = 0i64;
        v59.m128_f32[0] = (float)v37;
        x.m_quad = _mm_sub_ps(
                     v39,
                     _mm_mul_ps(
                       _mm_div_ps(query.m_quad, _mm_shuffle_ps(v59, v59, 0)),
                       _mm_sub_ps(
                         v39,
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v58, v57), _mm_andnot_ps(v58, v45))),
                             v44),
                           v33))));
        projectOnPlanes((hkArrayBase<hkVector4f> *)&v4->m_planes.m_data, &x, &x);
        v39 = x.m_quad;
        ++v37;
      }
      while ( v37 <= v34 );
      output = (hkArray<int,hkContainerHeapAllocator>)x.m_quad;
    }
    if ( v34 > 0 )
    {
      do
        projectOnPlanes((hkArrayBase<hkVector4f> *)&v4->m_planes.m_data, (hkVector4f *)&output, (hkVector4f *)&output);
      while ( v60 != 1 );
    }
    v30 = hkgpCgoInternal::processVertex(v3, v4, (hkVector4f *)&output, &vertexOut);
  }
  if ( v30 )
  {
    v61.m_quad = (__m128)vertexOut.m_vertex;
    v62.m_real = (__m128)vertexOut.m_error;
    v4->m_action = (hkgpCgoInternal::Action)((unsigned int)v104 & 0xFFFFFFFE | 2);
    v4->m_vertex = (hkVector4f)v61.m_quad;
    v4->m_maxError = (hkSimdFloat32)v62.m_real;
  }
LABEL_68:
  v90 = (float *)v104;
  v91 = &v104->m_vertex;
  v104->m_vertex = v4->m_vertex;
  *((_DWORD *)v90 + 8) = v4->m_maxError;
  v92 = v4->m_action;
  v90[11] = -6.8056469e38/*NaN*/;
  *((hkgpCgoInternal::Action *)v90 + 9) = v92;
  if ( v3->m_config.m_decimateComponents.m_bool )
  {
    v93 = v3->m_sets.m_data[*(signed int *)(*(_QWORD *)v90 + 72i64)].m_error;
    if ( v93 < v90[8] )
    {
      *((_DWORD *)v90 + 9) |= 2u;
      v90[8] = v93;
      v91->m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*v32, *v31), (__m128)xmmword_141A711B0), *v31);
    }
  }
  v91->m_quad = _mm_shuffle_ps(v91->m_quad, _mm_unpackhi_ps(v91->m_quad, v4->m_vertexW.m_real), 196);
  if ( v90[8] < 3.40282e38
    && hkgpCgoInternal::checkTwist(
         v3,
         v4->m_edgeIndices[0],
         v4->m_edgeIndices[1],
         v91,
         (hkArrayBase<hkgpCgoInternal::HTriangle> *)&v4->m_ring.m_data) )
  {
    v94 = &v3->m_lock.m_section;
    EnterCriticalSection(&v3->m_lock.m_section);
    v95 = &v3->m_edgesTree;
    if ( !v95->m_free )
      hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::preAllocateNodes(v95, 16);
    v96 = v95->m_free;
    v97 = v95->m_nodes.m_data;
    v98 = (__int64)v104;
    v95->m_free = v95->m_nodes.m_data[v96].m_parent;
    v97[v96].m_value = (hkgpCgoInternal::EdgeInfo *)v98;
    hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::insertNode(v95, v96);
    ++v95->m_size;
    *(_DWORD *)(v98 + 40) = v96;
    LeaveCriticalSection(v94);
  }
}

// File Line: 820
// RVA: 0xCE7B80
void __fastcall hkgpCgoInternal::updatePlane(hkgpCgoInternal *this, hkgpIndexedMeshDefinitions::Triangle *triangle)
{
  hkVector4f *v2; // r9
  hkgpCgoInternal::TriangleInfo *v3; // r11
  bool v4; // zf
  __m128 v5; // xmm6
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

  v2 = this->m_geometry->m_vertices.m_data;
  v3 = &this->m_triangles.m_data[(signed __int64)SLODWORD(triangle->m_index)];
  v4 = this->m_config.m_inverseOrientation.m_bool == 0;
  v5 = v2[SLODWORD(triangle->m_vertices[0]->m_index)].m_quad;
  v6 = _mm_sub_ps(v2[SLODWORD(triangle->m_vertices[1]->m_index)].m_quad, v5);
  v7 = _mm_sub_ps(v2[SLODWORD(triangle->m_vertices[2]->m_index)].m_quad, v5);
  v8 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v6), _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v7));
  v9 = _mm_shuffle_ps(v8, v8, 201);
  v10 = _mm_mul_ps(v9, v9);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_rsqrt_ps(v11);
  v13 = _mm_mul_ps(
          v9,
          _mm_andnot_ps(
            _mm_cmpleps(v11, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)),
              _mm_mul_ps(*(__m128 *)_xmm, v12))));
  v14 = _mm_mul_ps(v5, v13);
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
  if ( !v4 )
    v3->m_plane.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v15);
}

// File Line: 829
// RVA: 0xCE7CB0
void __fastcall hkgpCgoInternal::computeError(hkgpCgoInternal *this, hkArray<hkVector4f,hkContainerHeapAllocator> *planes, hkVector4f *vertex, hkSimdFloat32 *value)
{
  __m128 v4; // xmm6
  signed __int64 v5; // r8
  hkArray<hkVector4f,hkContainerHeapAllocator> *v6; // r10
  __int64 v7; // rax
  __m128 v8; // xmm5
  __m128 v9; // xmm7
  signed __int64 v10; // rcx
  unsigned __int64 v11; // rax
  __m128 v12; // xmm0
  __m128 v13; // xmm4
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm4
  __m128 v19; // xmm0
  __m128 v20; // xmm3
  __m128 v21; // xmm1
  __m128 v22; // xmm4
  __m128 v23; // xmm4
  __m128 *v24; // rax
  signed __int64 v25; // rcx
  __m128 v26; // xmm2
  __m128 v27; // xmm2
  __m128 v28; // xmm2
  __m128 v29; // xmm0
  __m128 v30; // xmm1
  __m128 v31; // xmm1

  v4 = vertex->m_quad;
  v5 = planes->m_size;
  v6 = planes;
  LODWORD(planes) = 0;
  v7 = (signed int)v5 - 3;
  v8 = 0i64;
  v9 = _mm_shuffle_ps(v4, _mm_unpackhi_ps(v4, query.m_quad), 196);
  if ( v7 > 0 )
  {
    v10 = (signed __int64)&v6->m_data[2];
    v11 = ((unsigned __int64)(v7 - 1) >> 2) + 1;
    LODWORD(planes) = 4 * v11;
    do
    {
      v12 = _mm_mul_ps(*(__m128 *)(v10 - 16), v9);
      v13 = _mm_mul_ps(*(__m128 *)(v10 - 32), v9);
      v14 = _mm_mul_ps(*(__m128 *)v10, v9);
      v15 = *(__m128 *)(v10 + 16);
      v10 += 64i64;
      v16 = _mm_mul_ps(v15, v9);
      v17 = _mm_shuffle_ps(v13, v12, 68);
      v18 = _mm_shuffle_ps(v13, v12, 238);
      v19 = _mm_shuffle_ps(v14, v16, 68);
      v20 = _mm_shuffle_ps(v14, v16, 238);
      v21 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v19, 221), _mm_shuffle_ps(v17, v19, 136)),
              _mm_add_ps(_mm_shuffle_ps(v18, v20, 221), _mm_shuffle_ps(v18, v20, 136)));
      v8 = _mm_max_ps(v8, _mm_mul_ps(v21, v21));
      --v11;
    }
    while ( v11 );
  }
  planes = (hkArray<hkVector4f,hkContainerHeapAllocator> *)(signed int)planes;
  v22 = _mm_max_ps(_mm_shuffle_ps(v8, v8, 78), v8);
  v23 = _mm_max_ps(v22, _mm_shuffle_ps(v22, v22, 177));
  if ( (signed int)planes < v5 )
  {
    v24 = &v6->m_data[(_QWORD)planes].m_quad;
    v25 = v5 - (_QWORD)planes;
    do
    {
      v26 = *v24;
      ++v24;
      v27 = _mm_mul_ps(v26, v4);
      v28 = _mm_shuffle_ps(v27, _mm_unpackhi_ps(v27, v24[-1]), 196);
      v29 = _mm_add_ps(_mm_shuffle_ps(v28, v28, 78), v28);
      v30 = _mm_add_ps(_mm_shuffle_ps(v29, v29, 177), v29);
      v23 = _mm_max_ps(v23, _mm_mul_ps(v30, v30));
      --v25;
    }
    while ( v25 );
  }
  v31 = _mm_rsqrt_ps(v23);
  value->m_real = _mm_andnot_ps(
                    _mm_cmpleps(v23, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v23), v31)),
                        _mm_mul_ps(*(__m128 *)_xmm, v31)),
                      v23));
}

// File Line: 854
// RVA: 0xCE7E30
char __fastcall hkgpCgoInternal::projectVertex(hkgpCgoInternal *this, hkArray<hkVector4f,hkContainerHeapAllocator> *planes, hkVector4f *vertex)
{
  int v3; // er11
  float v4; // xmm5_4
  int v5; // er9
  hkArray<hkVector4f,hkContainerHeapAllocator> *v6; // r10
  float v7; // xmm4_4
  __int64 v8; // rcx
  __m128 v9; // xmm2
  char v10; // dl
  __m128 *v11; // rax
  __m128 v12; // xmm1
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  __m128 v16; // xmm1
  __m128 v17; // xmm1
  float v18; // xmm3_4

  v3 = planes->m_size;
  v4 = *(float *)&xmmword_141A712A0;
  v5 = 0;
  v6 = planes;
  LODWORD(v7) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(this->m_config.m_minDistance),
                                     (__m128)LODWORD(this->m_config.m_minDistance),
                                     0);
  if ( v3 <= 0 )
    return 0;
  while ( 1 )
  {
    v8 = v6->m_size;
    v9 = vertex->m_quad;
    v10 = 0;
    if ( v8 <= 0 )
      break;
    v11 = &v6->m_data->m_quad;
    do
    {
      v12 = _mm_mul_ps(*v11, v9);
      v13 = _mm_shuffle_ps(v12, _mm_unpackhi_ps(v12, *v11), 196);
      v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
      v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14);
      if ( v15.m128_f32[0] < v7 )
      {
        v10 = 1;
        v9 = _mm_sub_ps(v9, _mm_mul_ps(*v11, v15));
      }
      ++v11;
      --v8;
    }
    while ( v8 );
    if ( !v10 )
      break;
    v16 = _mm_sub_ps(vertex->m_quad, v9);
    v17 = _mm_mul_ps(v16, v16);
    v18 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 0)))
        + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 170));
    if ( v18 <= v4 )
    {
      ++v5;
      v4 = v18;
      *vertex = (hkVector4f)v9;
      if ( v5 < v3 )
        continue;
    }
    return 0;
  }
  return 1;
}

// File Line: 883
// RVA: 0xCE7F00
bool __fastcall hkgpCgoInternal::processVertex(hkgpCgoInternal *this, hkgpCgoInternal::ProcessConfig *pcfg, hkVector4f *vertexIn, hkgpCgoInternal::ProcessedVertex *vertexOut)
{
  hkgpCgoInternal::ProcessedVertex *v4; // rsi
  hkgpCgoInternal::ProcessConfig *v5; // rbx
  hkgpCgoInternal *v6; // rdi
  __m128 v7; // xmm7
  __m128 v8; // xmm8
  __m128 v9; // xmm9
  __m128 v10; // xmm1
  __m128 v11; // xmm8
  __m128 v12; // xmm9
  bool result; // al
  __m128 v14; // xmm6
  __m128 v15; // xmm4
  __m128 v16; // xmm6
  __m128 v17; // xmm4
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm10
  __m128 v26; // xmm6
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  __m128 v29; // xmm3
  __m128 v30; // xmm0
  __m128 v31; // xmm8
  __m128 v32; // xmm4
  __m128 v33; // xmm8
  __m128 v34; // xmm4
  __m128 v35; // xmm1
  __m128 v36; // xmm0
  __m128 v37; // xmm7
  __m128 v38; // xmm1
  __m128 v39; // xmm3
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm1
  __m128 v43; // xmm9
  __m128 v44; // xmm0
  __m128 v45; // xmm10
  __m128 v46; // xmm8
  hkSimdFloat32 value; // [rsp+20h] [rbp-68h]

  v4 = vertexOut;
  v5 = pcfg;
  v6 = this;
  v7 = _mm_shuffle_ps((__m128)LODWORD(this->m_config.m_maxShrink), (__m128)LODWORD(this->m_config.m_maxShrink), 0);
  v8 = (__m128)LODWORD(this->m_config.m_minDistance);
  v9 = (__m128)LODWORD(this->m_config.m_maxDistance);
  vertexOut->m_error = pcfg->m_maxError;
  v10 = vertexIn->m_quad;
  v11 = _mm_shuffle_ps(v8, v8, 0);
  v12 = _mm_shuffle_ps(v9, v9, 0);
  vertexOut->m_valid = 0;
  vertexOut->m_vertex.m_quad = v10;
  if ( !this->m_config.m_project.m_bool || (result = hkgpCgoInternal::checkInside(this, &pcfg->m_planes, vertexIn)) != 0 )
  {
    if ( !v6->m_config.m_proportionalShrinking.m_bool && v7.m128_f32[0] != 0.0 )
    {
      v14 = v5->m_edgeVertices[0].m_quad;
      v15 = v14;
      v16 = _mm_sub_ps(v14, v4->m_vertex.m_quad);
      v17 = _mm_sub_ps(v15, v5->m_edgeVertices[1].m_quad);
      v18 = _mm_mul_ps(v17, v17);
      v19 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
              _mm_shuffle_ps(v18, v18, 170));
      v20 = _mm_mul_ps(v16, v17);
      v21 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
              _mm_shuffle_ps(v20, v20, 170));
      v22 = _mm_rcp_ps(v19);
      v23 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v19)), v22), v21);
      v24 = _mm_cmpltps(v23, query.m_quad);
      v25 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v23, v24), _mm_andnot_ps(v24, query.m_quad)));
      v26 = _mm_add_ps(_mm_sub_ps(v16, _mm_mul_ps(v25, v17)), v4->m_vertex.m_quad);
      v4->m_vertex.m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_sub_ps(_mm_shuffle_ps(v26, _mm_unpackhi_ps(v26, v25), 196), v4->m_vertex.m_quad),
                                v7),
                              v4->m_vertex.m_quad);
    }
    hkgpCgoInternal::computeError(v6, &v5->m_planes, &v4->m_vertex, &value);
    v27 = value.m_real;
    if ( v6->m_config.m_useAccumulatedError.m_bool )
      v27 = _mm_add_ps(value.m_real, v5->m_vtxError.m_real);
    v28 = v5->m_maxError.m_real;
    switch ( v6->m_config.m_semantic )
    {
      case 1:
        v28 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v12, v11), v5->m_vertexW.m_real), v11);
        break;
      case 2:
        v28 = v5->m_vertexW.m_real;
        break;
      case 3:
        v27 = _mm_mul_ps(v27, v5->m_vertexW.m_real);
        break;
      case 4:
        v27 = _mm_add_ps(v27, v5->m_vertexW.m_real);
        break;
    }
    v29 = _mm_min_ps(v28, v5->m_maxError.m_real);
    if ( v27.m128_f32[0] < v29.m128_f32[0] )
    {
      v4->m_error.m_real = v27;
      v4->m_valid = 1;
      if ( v6->m_config.m_proportionalShrinking.m_bool )
      {
        if ( v7.m128_f32[0] != 0.0 )
        {
          v30 = _mm_rcp_ps(v29);
          v31 = v5->m_edgeVertices[0].m_quad;
          v32 = v31;
          v33 = _mm_sub_ps(v31, v4->m_vertex.m_quad);
          v34 = _mm_sub_ps(v32, v5->m_edgeVertices[1].m_quad);
          v35 = _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v29, v30)), v30), v27), v7);
          v36 = _mm_cmpltps(v35, query.m_quad);
          v37 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v35, v36), _mm_andnot_ps(v36, query.m_quad)));
          v38 = _mm_mul_ps(v34, v34);
          v39 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                  _mm_shuffle_ps(v38, v38, 170));
          v40 = _mm_mul_ps(v33, v34);
          v41 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
                  _mm_shuffle_ps(v40, v40, 170));
          v42 = _mm_rcp_ps(v39);
          v43 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v42, v39)), v42), v41);
          v44 = _mm_cmpltps(v43, query.m_quad);
          v45 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v43, v44), _mm_andnot_ps(v44, query.m_quad)));
          v46 = _mm_add_ps(_mm_sub_ps(v33, _mm_mul_ps(v45, v34)), v4->m_vertex.m_quad);
          v4->m_vertex.m_quad = _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_sub_ps(_mm_shuffle_ps(v46, _mm_unpackhi_ps(v46, v45), 196), v4->m_vertex.m_quad),
                                    v37),
                                  v4->m_vertex.m_quad);
        }
      }
    }
    result = v4->m_valid;
  }
  return result;
}

// File Line: 943
// RVA: 0xCE81F0
char __fastcall hkgpCgoInternal::checkTwist(hkgpCgoInternal *this, int index0, int index1, hkVector4f *vertex, hkArrayBase<hkgpCgoInternal::HTriangle> *ring)
{
  __m128i v5; // xmm6
  __int64 v6; // rbp
  hkVector4f *v7; // rbx
  int v8; // edi
  __int64 v9; // r12
  int v10; // esi
  hkgpCgoInternal *v11; // r15
  __m128 v12; // xmm9
  __m128i v13; // xmm7
  __m128 v14; // xmm2
  __m128i v15; // xmm6
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm2
  float v20; // xmm15_4
  hkgpCgoInternal::HTriangle *v21; // r14
  hkVector4f *v22; // r11
  int v23; // er9
  signed __int64 v24; // r8
  __int64 v25; // rcx
  signed __int64 v26; // r10
  int v27; // edx
  __int128 v28; // xmm0
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
  float v45; // xmm10_4
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
  __m128 v63; // xmm4
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

  v5 = _mm_load_si128((const __m128i *)_xmm);
  v6 = 0i64;
  v7 = vertex;
  v8 = index1;
  v9 = ring->m_size;
  v10 = index0;
  v11 = this;
  v12 = _mm_add_ps((__m128)LODWORD(this->m_config.m_maxAngleDrift), *(__m128 *)_xmm);
  v13 = _mm_add_epi32(v5, v5);
  v14 = _mm_andnot_ps(*(__m128 *)_xmm, v12);
  v15 = _mm_andnot_si128(v5, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(*(__m128 *)_xmm, v14)), v5));
  v16 = _mm_cvtepi32_ps(v15);
  v17 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v15, v13), (__m128i)0i64);
  v18 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v16, *(__m128 *)DP1_0), v14), _mm_mul_ps(v16, *(__m128 *)DP2)),
          _mm_mul_ps(v16, *(__m128 *)DP3));
  v19 = _mm_mul_ps(v18, v18);
  v95 = (*(unsigned __int128 *)&_mm_andnot_ps(
                                  v17,
                                  _mm_add_ps(
                                    _mm_sub_ps(
                                      _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_add_ps(
                                            _mm_mul_ps(
                                              _mm_add_ps(_mm_mul_ps(v19, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1),
                                              v19),
                                            *(__m128 *)cosCoeff2_0),
                                          v19),
                                        v19),
                                      _mm_mul_ps(v19, *(__m128 *)_xmm)),
                                    *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                          (float)((float)((float)((float)((float)((float)(v19.m128_f32[0] * -0.00019515296)
                                                                                                + 0.0083321612)
                                                                                        * v19.m128_f32[0])
                                                                                + -0.16666655)
                                                                        * v19.m128_f32[0])
                                                                * v18.m128_f32[0])
                                                        + v18.m128_f32[0]) & v17.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v13, v13), v15) << 29) ^ _xmm[0] & v12.m128_i32[0];
  v20 = fmax(COERCE_FLOAT(_mm_shuffle_ps((__m128)v95, (__m128)v95, 0)), 0.00000011920929);
  if ( v9 <= 0 )
    return 1;
  v21 = ring->m_data;
  v22 = this->m_geometry->m_vertices.m_data;
  while ( 1 )
  {
    v23 = 0;
    v24 = (signed __int64)v21->m_triangle->m_vertices;
    v25 = 0i64;
    v26 = 3i64;
    do
    {
      v27 = *(_DWORD *)(*(_QWORD *)v24 + 16i64);
      v28 = (__int128)v22[*(signed int *)(*(_QWORD *)v24 + 16i64)];
      *(__m128 *)((char *)&v92 + v25) = (__m128)v28;
      *(__m128 *)((char *)&v89 + v25) = (__m128)v28;
      if ( v27 == v10 || v27 == v8 )
      {
        ++v23;
        *(__m128 *)((char *)&v89 + v25) = v7->m_quad;
      }
      v24 += 8i64;
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
                _mm_cmpleps(v35, (__m128)0i64),
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
                  _mm_cmpleps(v42, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v43, v42), v43)),
                    _mm_mul_ps(v43, *(__m128 *)_xmm))),
                v40),
              v38);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 170))) < v20 )
        break;
      v45 = v11->m_config.m_minEdgeRatio;
      if ( v45 > 0.0 )
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
                  _mm_cmpleps(v49, (__m128)0i64),
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
        v56 = _mm_cmpleps(v54, (__m128)0i64);
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
                    _mm_cmpleps(v58, (__m128)0i64),
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
        v58.m128_i32[0] = v63.m128_i32[0];
        v64 = _mm_max_ps(v63, _mm_max_ps(v61, v62));
        v65 = fmin(v61.m128_f32[0], v62.m128_f32[0]);
        v66 = _mm_rcp_ps(v64);
        v67 = _mm_sub_ps(v89, v90);
        v68 = _mm_mul_ps(v31, v31);
        v69 = _mm_mul_ps(v67, v67);
        v48.m128_f32[0] = COERCE_FLOAT(
                            _mm_andnot_ps(
                              _mm_cmpeqps(v64, (__m128)0i64),
                              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v66, v64)), v66)))
                        * fmin(v58.m128_f32[0], v65);
        v70 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)),
                _mm_shuffle_ps(v68, v68, 170));
        v71 = _mm_rsqrt_ps(v70);
        v72 = _mm_unpacklo_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v70, (__m128)0i64),
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
        v79 = _mm_andnot_ps(_mm_cmpleps(v75, (__m128)0i64), v77);
        v80 = _mm_rsqrt_ps(v78);
        v81 = _mm_movelh_ps(
                _mm_unpacklo_ps(
                  _mm_andnot_ps(
                    _mm_cmpleps(v78, (__m128)0i64),
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
        v87 = COERCE_FLOAT(
                _mm_andnot_ps(
                  _mm_cmpeqps(v85, (__m128)0i64),
                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v86, v85)), v86)))
            * v75.m128_f32[0];
        if ( v87 < v48.m128_f32[0] && v87 < v45 )
          break;
      }
    }
    ++v6;
    ++v21;
    if ( v6 >= v9 )
      return 1;
  }
  return 0;
} 

// File Line: 998
// RVA: 0xCE8820
char __fastcall hkgpCgoInternal::checkInside(hkgpCgoInternal *this, hkArray<hkVector4f,hkContainerHeapAllocator> *planes, hkVector4f *vertex)
{
  signed __int64 v3; // r11
  __m128 v4; // xmm6
  int v5; // er8
  hkArray<hkVector4f,hkContainerHeapAllocator> *v6; // r10
  signed __int64 v7; // rdx
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  __m128 *v10; // rcx
  __m128 v11; // xmm0
  __m128 v12; // xmm4
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm4
  __m128 v17; // xmm0
  __m128 v18; // xmm3
  signed __int64 v19; // rcx
  __m128 *v20; // rax
  __m128 v21; // xmm2
  __m128 v22; // xmm2
  __m128 v23; // xmm1

  v3 = planes->m_size;
  v4 = vertex->m_quad;
  v5 = 0;
  v6 = planes;
  v7 = 0i64;
  v8 = _mm_shuffle_ps((__m128)LODWORD(this->m_config.m_minDistance), (__m128)LODWORD(this->m_config.m_minDistance), 0);
  v9 = _mm_shuffle_ps(v4, _mm_unpackhi_ps(v4, query.m_quad), 196);
  if ( (signed int)v3 - 3 <= 0 )
  {
LABEL_5:
    v19 = v5;
    if ( v5 >= v3 )
      return 1;
    v20 = &v6->m_data[v5].m_quad;
    while ( 1 )
    {
      v21 = _mm_mul_ps(*v20, v9);
      v22 = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, *v20), 196);
      v23 = _mm_add_ps(_mm_shuffle_ps(v22, v22, 78), v22);
      if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 177)) + v23.m128_f32[0]) < v8.m128_f32[0] )
        break;
      ++v19;
      ++v20;
      if ( v19 >= v3 )
        return 1;
    }
  }
  else
  {
    v10 = &v6->m_data[2].m_quad;
    while ( 1 )
    {
      v11 = _mm_mul_ps(v10[-1], v9);
      v12 = _mm_mul_ps(v10[-2], v9);
      v13 = _mm_mul_ps(*v10, v9);
      v14 = _mm_mul_ps(v10[1], v9);
      v15 = _mm_shuffle_ps(v12, v11, 68);
      v16 = _mm_shuffle_ps(v12, v11, 238);
      v17 = _mm_shuffle_ps(v13, v14, 68);
      v18 = _mm_shuffle_ps(v13, v14, 238);
      if ( _mm_movemask_ps(
             _mm_cmpltps(
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
      if ( v7 >= (signed int)v3 - 3 )
        goto LABEL_5;
    }
  }
  return 0;
}

// File Line: 1019
// RVA: 0xCE89E0
char __fastcall hkgpCgoInternal::collapseEdge(hkgpCgoInternal *this, hkgpCgoInternal::EdgeInfo *e)
{
  hkgpCgoInternal::EdgeInfo *v2; // rsi
  hkgpCgoInternal *v3; // rbx
  hkOstream *v4; // rax
  hkgpCgo::Tracker *v5; // r10
  __int64 v6; // rdx
  __int64 v7; // rcx
  hkgpCgoInternal::VertexInfo *v8; // rax
  signed __int64 v9; // r14
  __int64 v10; // r13
  hkgpCgoInternal::VertexInfo *v11; // rdi
  hkgpCgoInternal::ICustomMetric *v12; // rcx
  int v14; // er8
  int v15; // er8
  int v16; // er8
  signed __int64 v17; // r14
  int v18; // er15
  __int64 v19; // r14
  __int128 v20; // xmm0
  hkStreamWriter *v21; // rax
  bool v22; // zf
  signed int *v23; // rdx
  hkgpCgoInternal::TriangleInfo *v24; // r10
  signed int v25; // er11
  __int64 v26; // r9
  signed int *v27; // rdx
  __int64 v28; // r8
  __int64 v29; // rax
  __int64 v30; // rax
  int v31; // er8
  __int64 v32; // rdx
  hkgpCgo::Tracker *v33; // rcx
  hkgpCgo::Tracker *v34; // rcx
  hkArrayBase<hkgpCgoInternal::HTriangle> *ring; // [rsp+20h] [rbp-E0h]
  hkArray<int,hkContainerHeapAllocator> v36; // [rsp+30h] [rbp-D0h]
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> output; // [rsp+40h] [rbp-C0h]
  hkErrStream v38; // [rsp+50h] [rbp-B0h]
  __int128 v39; // [rsp+70h] [rbp-90h]
  char buf; // [rsp+80h] [rbp-80h]
  unsigned int index1; // [rsp+2C8h] [rbp+1C8h]
  int index0; // [rsp+2D0h] [rbp+1D0h]

  v2 = e;
  v3 = this;
  if ( *(_BYTE *)&e->m_action & 1 )
  {
    hkErrStream::hkErrStream(&v38, &buf, 512);
    v4 = hkOstream::operator<<((hkOstream *)&v38.vfptr, "Flip edge ");
    hkOstream::operator<<(v4, v2->m_error, (int)v4);
    hkError::messageReport(0, &buf, 0i64, 0);
    hkOstream::~hkOstream((hkOstream *)&v38.vfptr);
    v5 = v3->m_config.m_tracker;
    if ( v5 )
      v5->vfptr->edgeFlip(
        v3->m_config.m_tracker,
        v2->m_edge.m_triangle->m_vertices[v2->m_edge.m_index]->m_index,
        v2->m_edge.m_triangle->m_vertices[(9i64 >> 2 * (unsigned __int8)v2->m_edge.m_index) & 3]->m_index);
    hkgpCgoInternal::flipEdge(v3, v2);
  }
  if ( !(*(_BYTE *)&v2->m_action & 2) )
    return 1;
  v6 = (signed int)v2->m_edge.m_index;
  index0 = v2->m_edge.m_triangle->m_vertices[v6]->m_index;
  v7 = SLODWORD(v2->m_edge.m_triangle->m_vertices[(9i64 >> 2 * (unsigned __int8)v6) & 3]->m_index);
  v8 = v3->m_vertices.m_data;
  output.m_capacityAndFlags = 2147483648;
  v9 = (signed __int64)&v8[(signed __int64)index0];
  index1 = v7;
  v10 = v7;
  v11 = &v8[v7];
  output.m_data = 0i64;
  output.m_size = 0;
  computeUnionOfSortedArray_hkgpCgoInternal::HTriangle_(
    (hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *)(v9 + 16),
    &v11->m_ring,
    &output);
  v36.m_data = 0i64;
  v36.m_size = 0;
  v36.m_capacityAndFlags = 2147483648;
  computeUnionOfSortedArray_int_((hkArray<int,hkContainerHeapAllocator> *)v9, &v11->m_planes, &v36);
  v12 = v3->m_cstMetric;
  if ( (!v12 || v12->vfptr->canCollapse(v12, v2, &output))
    && (v3->m_cstMetric
     || hkgpCgoInternal::checkTwist(
          v3,
          index0,
          index1,
          &v2->m_vertex,
          (hkArrayBase<hkgpCgoInternal::HTriangle> *)&output.m_data)) )
  {
    if ( v3->m_config.m_buildClusters.m_bool )
    {
      hkArrayBase<unsigned int>::_append(
        (hkArrayBase<unsigned int> *)&v11->m_cluster,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        *(const unsigned int **)(v9 + 32),
        *(_DWORD *)(v9 + 40));
      v14 = *(_DWORD *)(v9 + 44);
      *(_DWORD *)(v9 + 40) = 0;
      if ( v14 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v9 + 32),
          4 * v14);
      *(_QWORD *)(v9 + 32) = 0i64;
      *(_DWORD *)(v9 + 44) = 2147483648;
    }
    v11->m_isFixed |= *(_BYTE *)(v9 + 52);
    v11->m_error = v2->m_error;
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v11,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v36);
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v11->m_ring,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&output);
    v15 = *(_DWORD *)(v9 + 28);
    *(_DWORD *)(v9 + 24) = 0;
    if ( v15 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)(v9 + 16),
        8 * v15);
    *(_QWORD *)(v9 + 16) = 0i64;
    *(_DWORD *)(v9 + 28) = 2147483648;
    v16 = *(_DWORD *)(v9 + 12);
    *(_DWORD *)(v9 + 8) = 0;
    if ( v16 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)v9,
        4 * v16);
    *(_QWORD *)v9 = 0i64;
    *(_DWORD *)(v9 + 12) = 2147483648;
    v17 = (signed __int64)&v2->m_vertex;
    v3->m_geometry->m_vertices.m_data[v10] = v2->m_vertex;
    v18 = 0;
    if ( v11->m_ring.m_size > 0 )
    {
      v19 = 0i64;
      do
      {
        hkgpCgoInternal::updatePlane(v3, v11->m_ring.m_data[v19].m_triangle);
        ++v18;
        ++v19;
      }
      while ( v18 < v11->m_ring.m_size );
      v17 = (signed __int64)&v2->m_vertex;
    }
    v20 = (__int128)v2->m_edge;
    v38.vfptr = (hkBaseObjectVtbl *)&hkgpCgoInternal::ICollapse::`vftable;
    v21 = 0i64;
    v39 = v20;
    v22 = v3->m_config.m_buildClusters.m_bool == 0;
    *(_QWORD *)&v38.m_memSizeAndFlags = v3;
    if ( !v22 )
      v21 = (hkStreamWriter *)v11;
    v38.m_writer.m_pntr = v21;
    hkgpIndexedMesh::collapseEdge(
      &v3->m_topology,
      (hkgpIndexedMeshDefinitions::Edge *)&v39,
      0i64,
      (hkgpIndexedMesh::IEdgeCollapse *)&v38);
    if ( v3->m_config.m_buildClusters.m_bool )
    {
      v23 = v11->m_cluster.m_data;
      v24 = v3->m_triangles.m_data;
      v25 = v11->m_cluster.m_size;
      v26 = (unsigned int)v24[(signed __int64)*v23].m_cid;
      if ( v25 > 1 )
      {
        v27 = v23 + 1;
        v28 = (unsigned int)(v25 - 1);
        do
        {
          v29 = *v27;
          ++v27;
          v30 = v29 << 6;
          if ( *(int *)((char *)&v24->m_cid + v30) < (signed int)v26 )
            v26 = *(unsigned int *)((char *)&v24->m_cid + v30);
          --v28;
        }
        while ( v28 );
      }
      v31 = 0;
      if ( v25 > 0 )
      {
        v32 = 0i64;
        do
        {
          ++v31;
          ++v32;
          v3->m_triangles.m_data[(signed __int64)v11->m_cluster.m_data[v32 - 1]].m_cid = v26;
        }
        while ( v31 < v11->m_cluster.m_size );
      }
      v33 = v3->m_config.m_tracker;
      if ( v33 )
        v33->vfptr->setClusterId(v33, v11->m_cluster.m_data, v11->m_cluster.m_size, v26);
    }
    v34 = v3->m_config.m_tracker;
    if ( v34 )
    {
      *(float *)&ring = v2->m_error;
      ((void (__fastcall *)(hkgpCgo::Tracker *, _QWORD, _QWORD, signed __int64, hkArrayBase<hkgpCgoInternal::HTriangle> *))v34->vfptr->edgeCollapse)(
        v34,
        (unsigned int)index0,
        index1,
        v17,
        ring);
    }
    v36.m_size = 0;
    v38.vfptr = (hkBaseObjectVtbl *)&hkgpIndexedMesh::IVertexRemoval::`vftable;
    if ( v36.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v36.m_data,
        4 * v36.m_capacityAndFlags);
    v36.m_data = 0i64;
    v36.m_capacityAndFlags = 2147483648;
    output.m_size = 0;
    if ( output.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        output.m_data,
        8 * output.m_capacityAndFlags);
    return 1;
  }
  hkgpCgoInternal::invalidateEdgeInfo(v3, v2);
  v36.m_size = 0;
  if ( v36.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v36.m_data,
      4 * v36.m_capacityAndFlags);
  v36.m_data = 0i64;
  v36.m_capacityAndFlags = 2147483648;
  output.m_size = 0;
  if ( output.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      output.m_data,
      8 * output.m_capacityAndFlags);
  return 0;
}

// File Line: 1115
// RVA: 0xCE8F40
void __fastcall hkgpCgoInternal::flipEdge(hkgpCgoInternal *this, hkgpCgoInternal::EdgeInfo *e)
{
  __int64 v2; // rax
  hkgpCgoInternal *v3; // rbx
  char v4; // r14
  __int64 v5; // rsi
  hkgpCgoInternal::EdgeInfo *v6; // r12
  unsigned __int64 v7; // rdi
  signed __int64 v8; // r15
  hkgpCgoInternal::EdgeInfo *v9; // rax
  hkgpCgoInternal::EdgeInfo *v10; // r13
  hkgpCgoInternal::EdgeInfo *v11; // rax
  hkgpCgoInternal::VertexInfo *v12; // r9
  __int64 v13; // r8
  __int64 v14; // rax
  hkgpIndexedMeshDefinitions::Edge *v15; // rax
  __int64 v16; // rdi
  hkgpIndexedMeshDefinitions::Triangle *v17; // r12
  __int64 v18; // r15
  unsigned __int64 v19; // r14
  signed __int64 v20; // rsi
  hkgpCgoInternal::EdgeInfo *v21; // r8
  hkgpCgoInternal::EdgeInfo *v22; // r8
  hkgpCgoInternal::EdgeInfo *v23; // r8
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *v24; // r15
  __int64 v25; // r8
  signed int v26; // edx
  __int64 v27; // rcx
  hkgpCgoInternal::HTriangle *v28; // rax
  int v29; // er9
  signed __int64 v30; // rdx
  int v31; // er9
  __int64 v32; // rcx
  __int64 v33; // rax
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *v34; // r14
  signed int v35; // edx
  __int64 v36; // r8
  __int64 v37; // rcx
  hkgpCgoInternal::HTriangle *v38; // rax
  int v39; // er9
  signed __int64 v40; // rdx
  int v41; // er9
  __int64 v42; // rcx
  __int64 v43; // rax
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *v44; // r13
  _QWORD *v45; // rdx
  hkgpCgoInternal::HTriangle *v46; // rdx
  signed int v47; // er8
  signed int v48; // er8
  int v49; // esi
  __int64 v50; // rdi
  __m128i v51; // [rsp+20h] [rbp-79h]
  __m128i v52; // [rsp+30h] [rbp-69h]
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> v53; // [rsp+40h] [rbp-59h]
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> b; // [rsp+50h] [rbp-49h]
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> output; // [rsp+60h] [rbp-39h]
  hkgpCgoInternal::EdgeInfo *v56; // [rsp+70h] [rbp-29h]
  hkgpCgoInternal::EdgeInfo *v57; // [rsp+78h] [rbp-21h]
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *v58; // [rsp+80h] [rbp-19h]
  hkgpCgoInternal::EdgeInfo *v59; // [rsp+88h] [rbp-11h]
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *v60; // [rsp+90h] [rbp-9h]
  char v61; // [rsp+98h] [rbp-1h]
  unsigned __int64 v62; // [rsp+100h] [rbp+67h]
  hkgpCgoInternal::EdgeInfo *v63; // [rsp+108h] [rbp+6Fh]
  __int64 v64; // [rsp+110h] [rbp+77h]
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *v65; // [rsp+118h] [rbp+7Fh]

  v63 = e;
  v2 = *(_QWORD *)&e->m_edge.m_index;
  v3 = this;
  v4 = 2 * v2;
  v5 = (signed int)v2;
  v52.m128i_i64[0] = (__int64)e->m_edge.m_triangle;
  v64 = v52.m128i_i64[0];
  v6 = e;
  v7 = *(_QWORD *)(v52.m128i_i64[0] + 8i64 * (signed int)v2 + 40) & 0xFFFFFFFFFFFFFFFCui64;
  v8 = *(_QWORD *)(v52.m128i_i64[0] + 8i64 * (signed int)v2 + 40) & 3i64;
  v62 = *(_QWORD *)(v52.m128i_i64[0] + 8i64 * (signed int)v2 + 40) & 0xFFFFFFFFFFFFFFFCui64;
  v52.m128i_i32[2] = (9 >> 2 * v2) & 3;
  _mm_store_si128(&v51, v52);
  v56 = hkgpCgoInternal::getEdgeInfo(this, (hkgpIndexedMeshDefinitions::Edge *)&v51);
  v52.m128i_i64[0] = v64;
  v52.m128i_i32[2] = (18 >> v4) & 3;
  _mm_store_si128(&v51, v52);
  v9 = hkgpCgoInternal::getEdgeInfo(v3, (hkgpIndexedMeshDefinitions::Edge *)&v51);
  v52.m128i_i64[0] = v7;
  v57 = v9;
  v52.m128i_i32[2] = (9 >> 2 * v8) & 3;
  _mm_store_si128(&v51, v52);
  v10 = hkgpCgoInternal::getEdgeInfo(v3, (hkgpIndexedMeshDefinitions::Edge *)&v51);
  v52.m128i_i64[0] = v62;
  v52.m128i_i32[2] = (18 >> 2 * v8) & 3;
  _mm_store_si128(&v51, v52);
  v11 = hkgpCgoInternal::getEdgeInfo(v3, (hkgpIndexedMeshDefinitions::Edge *)&v51);
  v12 = v3->m_vertices.m_data;
  v59 = v11;
  v13 = *(_QWORD *)(v62 + 8i64 * (signed int)v8 + 16);
  v58 = (hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *)&v12[(signed __int64)*(signed int *)(*(_QWORD *)(v64 + 8 * v5 + 16) + 16i64)];
  v60 = (hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *)&v12[(signed __int64)*(signed int *)(v13 + 16)];
  v14 = *(_QWORD *)(v64 + 8 * ((18i64 >> v4) & 3) + 16);
  v51 = (__m128i)v6->m_edge;
  v52.m128i_i64[0] = (__int64)&v12[(signed __int64)*(signed int *)(v14 + 16)];
  v65 = (hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *)&v12[(signed __int64)*(signed int *)(*(_QWORD *)(v62 + 8 * ((18i64 >> 2 * (unsigned __int8)v8) & 3) + 16) + 16i64)];
  v15 = hkgpIndexedMesh::flipEdge(
          &v3->m_topology,
          (hkgpIndexedMeshDefinitions::Edge *)&v61,
          (hkgpIndexedMeshDefinitions::Edge *)&v51);
  v16 = *(_QWORD *)&v15->m_index;
  v51 = *(__m128i *)v15;
  v17 = (hkgpIndexedMeshDefinitions::Triangle *)v51.m128i_i64[0];
  v18 = v51.m128i_i64[0] + 8i64 * (signed int)v16;
  v19 = *(_QWORD *)(v18 + 40) & 0xFFFFFFFFFFFFFFFCui64;
  v20 = *(_QWORD *)(v18 + 40) & 3i64;
  hkgpCgoInternal::setEdgeInfo(v3, (hkgpIndexedMeshDefinitions::Edge *)&v51, v63);
  v21 = v57;
  v51.m128i_i64[0] = (__int64)v17;
  LOBYTE(v16) = 2 * v16;
  v51.m128i_i32[2] = (9 >> v16) & 3;
  _mm_store_si128(&v51, v51);
  hkgpCgoInternal::setEdgeInfo(v3, (hkgpIndexedMeshDefinitions::Edge *)&v51, v21);
  v51.m128i_i64[0] = (__int64)v17;
  v51.m128i_i32[2] = (18 >> v16) & 3;
  _mm_store_si128(&v51, v51);
  hkgpCgoInternal::setEdgeInfo(v3, (hkgpIndexedMeshDefinitions::Edge *)&v51, v10);
  v22 = v59;
  v51.m128i_i64[0] = v19;
  v51.m128i_i32[2] = (9 >> 2 * v20) & 3;
  _mm_store_si128(&v51, v51);
  hkgpCgoInternal::setEdgeInfo(v3, (hkgpIndexedMeshDefinitions::Edge *)&v51, v22);
  v51.m128i_i64[0] = v19;
  v51.m128i_i32[2] = (18 >> 2 * v20) & 3;
  v23 = v56;
  _mm_store_si128(&v51, v51);
  hkgpCgoInternal::setEdgeInfo(v3, (hkgpIndexedMeshDefinitions::Edge *)&v51, v23);
  hkgpCgoInternal::updatePlane(v3, v17);
  hkgpCgoInternal::updatePlane(
    v3,
    (hkgpIndexedMeshDefinitions::Triangle *)(*(_QWORD *)(v18 + 40) & 0xFFFFFFFFFFFFFFFCui64));
  v24 = v58;
  v25 = v58[1].m_size;
  v26 = 0;
  v27 = 0i64;
  if ( v25 <= 0 )
  {
LABEL_5:
    v26 = -1;
  }
  else
  {
    v28 = v58[1].m_data;
    while ( v28->m_triangle != (hkgpIndexedMeshDefinitions::Triangle *)v62 )
    {
      ++v27;
      ++v26;
      ++v28;
      if ( v27 >= v25 )
        goto LABEL_5;
    }
  }
  --v58[1].m_size;
  v29 = v24[1].m_size - v26;
  v30 = (signed __int64)&v24[1].m_data[v26];
  v31 = 8 * v29;
  if ( v31 > 0 )
  {
    v32 = ((unsigned int)(v31 - 1) >> 3) + 1;
    do
    {
      v33 = *(_QWORD *)(v30 + 8);
      v30 += 8i64;
      *(_QWORD *)(v30 - 8) = v33;
      --v32;
    }
    while ( v32 );
  }
  v34 = v60;
  v35 = 0;
  v36 = v60[1].m_size;
  v37 = 0i64;
  if ( v36 <= 0 )
  {
LABEL_13:
    v35 = -1;
  }
  else
  {
    v38 = v60[1].m_data;
    while ( v38->m_triangle != (hkgpIndexedMeshDefinitions::Triangle *)v64 )
    {
      ++v37;
      ++v35;
      ++v38;
      if ( v37 >= v36 )
        goto LABEL_13;
    }
  }
  --v60[1].m_size;
  v39 = v34[1].m_size - v35;
  v40 = (signed __int64)&v34[1].m_data[v35];
  v41 = 8 * v39;
  if ( v41 > 0 )
  {
    v42 = ((unsigned int)(v41 - 1) >> 3) + 1;
    do
    {
      v43 = *(_QWORD *)(v40 + 8);
      v40 += 8i64;
      *(_QWORD *)(v40 - 8) = v43;
      --v42;
    }
    while ( v42 );
  }
  v44 = (hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *)v52.m128i_i64[0];
  if ( *(_DWORD *)(v52.m128i_i64[0] + 24) == (*(_DWORD *)(v52.m128i_i64[0] + 28) & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (void *)(v52.m128i_i64[0] + 16),
      8);
  v45 = &v44[1].m_data[v44[1].m_size].m_triangle;
  if ( v45 )
    *v45 = v62;
  ++v44[1].m_size;
  if ( v65[1].m_size == (v65[1].m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v65[1], 8);
  v46 = &v65[1].m_data[v65[1].m_size];
  if ( v46 )
    v46->m_triangle = (hkgpIndexedMeshDefinitions::Triangle *)v64;
  ++v65[1].m_size;
  v47 = v44[1].m_size;
  if ( v47 > 1 )
    hkAlgorithm::quickSortRecursive<hkgpCgoInternal::HTriangle,hkAlgorithm::less<hkgpCgoInternal::HTriangle>>(
      v44[1].m_data,
      0,
      v47 - 1,
      0);
  v48 = v65[1].m_size;
  if ( v48 > 1 )
    hkAlgorithm::quickSortRecursive<hkgpCgoInternal::HTriangle,hkAlgorithm::less<hkgpCgoInternal::HTriangle>>(
      v65[1].m_data,
      0,
      v48 - 1,
      0);
  output.m_capacityAndFlags = 2147483648;
  output.m_data = 0i64;
  output.m_size = 0;
  computeUnionOfSortedArray_hkgpCgoInternal::HTriangle_(v24 + 1, v34 + 1, &output);
  b.m_data = 0i64;
  b.m_size = 0;
  b.m_capacityAndFlags = 2147483648;
  computeUnionOfSortedArray_hkgpCgoInternal::HTriangle_(v44 + 1, v65 + 1, &b);
  v53.m_data = 0i64;
  v53.m_size = 0;
  v53.m_capacityAndFlags = 2147483648;
  computeUnionOfSortedArray_hkgpCgoInternal::HTriangle_(&output, &b, &v53);
  v49 = 0;
  if ( v53.m_size > 0 )
  {
    v50 = 0i64;
    do
    {
      hkgpCgoInternal::invalidateEdgeInfo(
        v3,
        v3->m_triangles.m_data[(signed __int64)SLODWORD(v53.m_data[v50].m_triangle->m_index)].m_edges[0]);
      hkgpCgoInternal::invalidateEdgeInfo(
        v3,
        v3->m_triangles.m_data[(signed __int64)SLODWORD(v53.m_data[v50].m_triangle->m_index)].m_edges[1]);
      hkgpCgoInternal::invalidateEdgeInfo(
        v3,
        v3->m_triangles.m_data[(signed __int64)SLODWORD(v53.m_data[v50].m_triangle->m_index)].m_edges[2]);
      ++v49;
      ++v50;
    }
    while ( v49 < v53.m_size );
  }
  v53.m_size = 0;
  if ( v53.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v53.m_data,
      8 * v53.m_capacityAndFlags);
  v53.m_data = 0i64;
  v53.m_capacityAndFlags = 2147483648;
  b.m_size = 0;
  if ( b.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      b.m_data,
      8 * b.m_capacityAndFlags);
  b.m_data = 0i64;
  b.m_capacityAndFlags = 2147483648;
  output.m_size = 0;
  if ( output.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      output.m_data,
      8 * output.m_capacityAndFlags);
}

// File Line: 1156
// RVA: 0xCE9540
hkgpCgoInternal::EdgeInfo *__fastcall hkgpCgoInternal::getEdgeInfo(hkgpCgoInternal *this, hkgpIndexedMeshDefinitions::Edge *edge)
{
  hkgpIndexedMeshDefinitions::Triangle *v2; // r8
  __int64 v3; // r9
  hkgpCgoInternal::TriangleInfo *v4; // rdx
  hkgpCgoInternal::EdgeInfo *result; // rax

  v2 = edge->m_triangle;
  v3 = (signed int)edge->m_index;
  v4 = this->m_triangles.m_data;
  result = v4->m_edges[v3 + 8i64 * SLODWORD(v2->m_index)];
  if ( !result )
  {
    if ( v2->m_links[v3] & 0xFFFFFFFFFFFFFFFCui64 )
      result = v4->m_edges[(v2->m_links[v3] & 3)
                         + 8i64 * *(signed int *)((v2->m_links[v3] & 0xFFFFFFFFFFFFFFFCui64) + 64)];
  }
  return result;
}

// File Line: 1164
// RVA: 0xCE9590
void __fastcall hkgpCgoInternal::setEdgeInfo(hkgpCgoInternal *this, hkgpIndexedMeshDefinitions::Edge *edge, hkgpCgoInternal::EdgeInfo *edgeInfo)
{
  hkgpIndexedMeshDefinitions::Edge *v3; // r9
  hkgpCgoInternal *v4; // r10
  __int64 v5; // rcx
  char *v6; // rdx

  v3 = edge;
  v4 = this;
  if ( edgeInfo )
    edgeInfo->m_edge = *edge;
  this->m_triangles.m_data->m_edges[(signed int)edge->m_index + 8i64 * SLODWORD(edge->m_triangle->m_index)] = edgeInfo;
  v5 = (signed int)edge->m_index;
  v6 = (char *)edge->m_triangle + 8 * v5;
  if ( v3->m_triangle->m_links[v5] & 0xFFFFFFFFFFFFFFFCui64 )
    v4->m_triangles.m_data->m_edges[(*((_DWORD *)v6 + 10) & 3)
                                  + 8i64 * *(signed int *)((v3->m_triangle->m_links[v5] & 0xFFFFFFFFFFFFFFFCui64) + 64)] = 0i64;
}

// File Line: 1177
// RVA: 0xCE9600
void __fastcall hkgpCgoInternal::invalidateEdgeInfo(hkgpCgoInternal *this, hkgpCgoInternal::EdgeInfo *edgeInfo)
{
  hkgpCgoInternal::EdgeInfo *v2; // rdi
  hkgpCgoInternal *v3; // rsi
  hkArray<hkgpCgoInternal::EdgeInfo *,hkContainerHeapAllocator> *v4; // rbx
  __int64 v5; // rbp

  if ( edgeInfo )
  {
    v2 = edgeInfo;
    v3 = this;
    if ( edgeInfo->m_invalidIndex == -1 )
    {
      v4 = &this->m_invalidEdges;
      edgeInfo->m_invalidIndex = this->m_invalidEdges.m_size;
      if ( this->m_invalidEdges.m_size == (this->m_invalidEdges.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
      v4->m_data[v4->m_size++] = v2;
      v5 = v2->m_nodeIndex;
      if ( (_DWORD)v5 )
      {
        hkSortedTree<hkgpCgoInternal::EdgeInfo *,hkgpCgoInternal::EdgeInfo,int,16>::removeNode(&v3->m_edgesTree, v5);
        v3->m_edgesTree.m_nodes.m_data[v5].m_parent = v3->m_edgesTree.m_free;
        --v3->m_edgesTree.m_size;
        v3->m_edgesTree.m_free = v5;
        v2->m_nodeIndex = 0;
      }
    }
  }
}

// File Line: 1192
// RVA: 0xCE96D0
void __fastcall hkgpCgoInternal::removeEdgeInfoFromInvalidQueue(hkgpCgoInternal *this, hkgpCgoInternal::EdgeInfo *edgeInfo)
{
  hkgpCgoInternal::EdgeInfo *v2; // r9
  int v3; // edx
  __int64 v4; // r8
  __int64 v5; // rax

  v2 = edgeInfo;
  v3 = edgeInfo->m_invalidIndex;
  if ( v3 != -1 )
  {
    this->m_invalidEdges.m_data[this->m_invalidEdges.m_size - 1]->m_invalidIndex = v3;
    v4 = v2->m_invalidIndex;
    v5 = --this->m_invalidEdges.m_size;
    if ( (_DWORD)v5 != (_DWORD)v4 )
      this->m_invalidEdges.m_data[v4] = this->m_invalidEdges.m_data[v5];
    v2->m_invalidIndex = -1;
  }
}

// File Line: 1203
// RVA: 0xCE9730
void __fastcall hkgpCgoInternal::getRing(hkgpCgoInternal *this, int v0, int v1, hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *ring)
{
  computeUnionOfSortedArray_hkgpCgoInternal::HTriangle_(
    &this->m_vertices.m_data[(signed __int64)v0].m_ring,
    &this->m_vertices.m_data[(signed __int64)v1].m_ring,
    ring);
}

// File Line: 1209
// RVA: 0xCE9770
void __fastcall hkgpCgoInternal::getPlanes(hkgpCgoInternal *this, int v0, int v1, hkArray<hkVector4f,hkContainerHeapAllocator> *planes)
{
  hkgpCgoInternal::VertexInfo *v4; // rax
  hkgpCgoInternal *v5; // r15
  signed __int64 v6; // rdi
  signed __int64 v7; // rsi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v8; // rbx
  hkgpCgoInternal::VertexInfo *v9; // rax
  int v10; // ecx
  int v11; // eax
  int v12; // er9
  int v13; // eax
  int v14; // eax
  int v15; // er14
  __int64 v16; // rsi
  hkVector4f *v17; // rdi
  int v18; // er14
  __int64 v19; // rsi
  hkVector4f *v20; // rdi
  hkArray<int,hkContainerHeapAllocator> v21; // [rsp+30h] [rbp-20h]
  hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> output; // [rsp+40h] [rbp-10h]
  hkResult result; // [rsp+88h] [rbp+38h]

  v4 = this->m_vertices.m_data;
  v5 = this;
  v6 = (signed __int64)v0 << 6;
  v7 = (signed __int64)v1 << 6;
  v8 = planes;
  output.m_data = 0i64;
  output.m_size = 0;
  output.m_capacityAndFlags = 2147483648;
  computeUnionOfSortedArray_hkgpCgoInternal::HTriangle_(
    (hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *)((char *)&v4->m_ring + v6),
    (hkArray<hkgpCgoInternal::HTriangle,hkContainerHeapAllocator> *)((char *)&v4->m_ring + v7),
    &output);
  v9 = v5->m_vertices.m_data;
  v21.m_data = 0i64;
  v21.m_size = 0;
  v21.m_capacityAndFlags = 2147483648;
  computeUnionOfSortedArray_int_(
    (hkArray<int,hkContainerHeapAllocator> *)((char *)&v9->m_planes + v6),
    (hkArray<int,hkContainerHeapAllocator> *)((char *)&v9->m_planes + v7),
    &v21);
  v10 = output.m_size;
  v11 = v8->m_capacityAndFlags;
  v12 = output.m_size + v21.m_size;
  v8->m_size = 0;
  v13 = v11 & 0x3FFFFFFF;
  if ( v13 < v12 )
  {
    v14 = 2 * v13;
    if ( v12 < v14 )
      v12 = v14;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, v12, 16);
    v10 = output.m_size;
  }
  v15 = 0;
  if ( v10 > 0 )
  {
    v16 = 0i64;
    do
    {
      v17 = &v5->m_triangles.m_data[(signed __int64)SLODWORD(output.m_data[v16].m_triangle->m_index)].m_plane;
      if ( v8->m_size == (v8->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, 16);
      ++v15;
      ++v16;
      v8->m_data[v8->m_size++] = (hkVector4f)v17->m_quad;
    }
    while ( v15 < output.m_size );
  }
  v18 = 0;
  if ( v21.m_size > 0 )
  {
    v19 = 0i64;
    do
    {
      v20 = &v5->m_triangles.m_data[(signed __int64)v21.m_data[v19]].m_plane;
      if ( v8->m_size == (v8->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, 16);
      ++v18;
      ++v19;
      v8->m_data[v8->m_size++] = (hkVector4f)v20->m_quad;
    }
    while ( v18 < v21.m_size );
  }
  v21.m_size = 0;
  if ( v21.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v21.m_data,
      4 * v21.m_capacityAndFlags);
  v21.m_data = 0i64;
  v21.m_capacityAndFlags = 2147483648;
  output.m_size = 0;
  if ( output.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      output.m_data,
      8 * output.m_capacityAndFlags);
}

// File Line: 1220
// RVA: 0xCE9990
__int64 __fastcall hkgpCgoInternal::checkIntegrity(hkgpCgoInternal *this)
{
  hkgpIndexedMeshDefinitions::Triangle *v1; // rbx
  hkgpCgoInternal::EdgeInfo *v2; // rdi
  __int64 *v3; // rax
  hkgpCgoInternal *v4; // r13
  unsigned __int8 v5; // r10
  hkgpIndexedMeshDefinitions::Vertex *v6; // rdx
  hkgpIndexedMeshDefinitions::Vertex *v7; // rax
  hkgpIndexedMeshDefinitions::Vertex *v8; // rcx
  signed int v9; // er14
  signed __int64 v10; // rax
  char *v11; // r12
  __int64 *v12; // r15
  __int64 v13; // r8
  signed __int64 v14; // rax
  int v15; // er9
  int v16; // ecx
  int v17; // edx
  signed __int64 v18; // rax
  __int64 v19; // rcx
  __int64 v20; // r8
  hkgpIndexedMeshDefinitions::Triangle **v21; // rax
  char *v22; // rcx
  hkErrStream v24; // [rsp+20h] [rbp-C0h]
  char buf; // [rsp+40h] [rbp-A0h]
  char v26; // [rsp+250h] [rbp+170h]
  __int64 v27; // [rsp+270h] [rbp+190h]

  v1 = this->m_topology.m_triangles.m_used;
  v2 = 0i64;
  v3 = &v27;
  v4 = this;
  v5 = 1;
  if ( !v1 )
    v3 = 0i64;
  if ( v3 )
  {
    do
    {
      v6 = v1->m_vertices[1];
      v7 = v1->m_vertices[0];
      if ( v7 == v6 || (v8 = v1->m_vertices[2], v7 == v8) || v6 == v8 )
      {
        hkErrStream::hkErrStream(&v24, &buf, 512);
        hkOstream::operator<<((hkOstream *)&v24.vfptr, "Invalid triangle vertices");
        if ( (unsigned int)hkError::messageError(
                             533740160,
                             &buf,
                             "GeometryProcessing\\CollisionGeometryOptimizer\\hkgpCgoInternals.cpp",
                             1229) )
          __debugbreak();
        hkOstream::~hkOstream((hkOstream *)&v24.vfptr);
        v5 = 0;
      }
      v9 = (signed int)v2;
      v10 = (signed __int64)&v4->m_triangles.m_data[(signed __int64)SLODWORD(v1->m_index)];
      v11 = (char *)v1 - v10;
      v12 = (__int64 *)(v10 + 16);
      do
      {
        v13 = *v12;
        v14 = v1->m_links[v9] & 3;
        if ( v1->m_links[v9] & 0xFFFFFFFFFFFFFFFCui64 )
          v2 = v4->m_triangles.m_data->m_edges[(signed int)v14
                                             + 8i64 * *(signed int *)((v1->m_links[v9] & 0xFFFFFFFFFFFFFFFCui64) + 64)];
        if ( v13 )
        {
          if ( (hkgpIndexedMeshDefinitions::Triangle *)(*(_QWORD *)v13 + *(unsigned int *)(v13 + 8)) != (hkgpIndexedMeshDefinitions::Triangle *)((char *)v1 + (unsigned int)v9) )
          {
            hkErrStream::hkErrStream(&v24, &buf, 512);
            hkOstream::operator<<((hkOstream *)&v24.vfptr, "Invalid edge reference");
            if ( (unsigned int)hkError::messageError(
                                 376159292,
                                 &buf,
                                 "GeometryProcessing\\CollisionGeometryOptimizer\\hkgpCgoInternals.cpp",
                                 1244) )
              __debugbreak();
            hkOstream::~hkOstream((hkOstream *)&v24.vfptr);
            v5 = 0;
          }
          if ( !(v1->m_links[v9] & 0xFFFFFFFFFFFFFFFCui64) || !v2 )
            goto LABEL_27;
          hkErrStream::hkErrStream(&v24, &buf, 512);
          hkOstream::operator<<((hkOstream *)&v24.vfptr, "Non-null edge info");
          v15 = 1249;
          v16 = 1613305869;
          goto LABEL_24;
        }
        if ( v1->m_links[v9] & 0xFFFFFFFFFFFFFFFCui64 && !v2 )
        {
          hkErrStream::hkErrStream(&v24, &buf, 512);
          hkOstream::operator<<((hkOstream *)&v24.vfptr, "Null edge info");
          v15 = 1257;
          v16 = 1817719705;
LABEL_24:
          if ( (unsigned int)hkError::messageError(
                               v16,
                               &buf,
                               "GeometryProcessing\\CollisionGeometryOptimizer\\hkgpCgoInternals.cpp",
                               v15) )
            __debugbreak();
          hkOstream::~hkOstream((hkOstream *)&v24.vfptr);
          v5 = 0;
        }
LABEL_27:
        v2 = 0i64;
        v17 = 0;
        v18 = (signed __int64)&v4->m_vertices.m_data[(signed __int64)*(signed int *)(*(__int64 *)((char *)v12
                                                                                                + (_QWORD)v11)
                                                                                   + 16)];
        v19 = 0i64;
        v20 = *(signed int *)(v18 + 24);
        if ( v20 <= 0 )
          goto LABEL_33;
        v21 = *(hkgpIndexedMeshDefinitions::Triangle ***)(v18 + 16);
        while ( *v21 != v1 )
        {
          ++v19;
          ++v17;
          ++v21;
          if ( v19 >= v20 )
            goto LABEL_33;
        }
        if ( v17 == -1 )
        {
LABEL_33:
          hkErrStream::hkErrStream(&v24, &buf, 512);
          hkOstream::operator<<((hkOstream *)&v24.vfptr, "Cannot find triangle reference in vertex ring");
          if ( (unsigned int)hkError::messageError(
                               278848958,
                               &buf,
                               "GeometryProcessing\\CollisionGeometryOptimizer\\hkgpCgoInternals.cpp",
                               1264) )
            __debugbreak();
          hkOstream::~hkOstream((hkOstream *)&v24.vfptr);
          v5 = 0;
        }
        ++v9;
        ++v12;
      }
      while ( v9 < 3 );
      v1 = v1->m_next;
      v22 = &v26;
      if ( !v1 )
        v22 = 0i64;
    }
    while ( v22 );
  }
  return v5;
}


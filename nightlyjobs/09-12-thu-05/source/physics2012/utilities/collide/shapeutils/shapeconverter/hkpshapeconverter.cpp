// File Line: 22
// RVA: 0xE13510
hkGeometry *__fastcall hkpShapeConverter::toSingleGeometry(hkpShape *shape)
{
  hkpShape *v1; // rbx
  _QWORD **v2; // rax
  __int64 v3; // rax
  hkGeometry *v4; // rbx
  __int64 i; // rsi
  hkDisplayGeometry *v6; // rdi
  hkGeometry *v7; // rcx
  __m128 v8; // xmm3
  hkGeometry *v9; // r8
  __m128i v10; // xmm1
  __m128i v11; // xmm2
  hkErrStream v13; // [rsp+20h] [rbp-D0h]
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> displayGeometries; // [rsp+40h] [rbp-B0h]
  char v15; // [rsp+50h] [rbp-A0h]
  hkpShapeDisplayBuilder v16; // [rsp+80h] [rbp-70h]
  hkMatrix4f transform; // [rsp+A0h] [rbp-50h]
  char buf; // [rsp+E0h] [rbp-10h]
  void *retaddr; // [rsp+318h] [rbp+228h]
  hkResult result; // [rsp+320h] [rbp+230h]
  hkpShapeDisplayBuilder::hkpShapeDisplayBuilderEnvironment env; // [rsp+328h] [rbp+238h]

  v1 = shape;
  displayGeometries.m_capacityAndFlags = -2147483640;
  displayGeometries.m_data = (hkDisplayGeometry **)&v15;
  displayGeometries.m_size = 0;
  hkpShapeDisplayBuilder::hkpShapeDisplayBuilderEnvironment::hkpShapeDisplayBuilderEnvironment(&env);
  hkpShapeDisplayBuilder::hkpShapeDisplayBuilder(&v16, &env);
  hkpShapeDisplayBuilder::buildDisplayGeometries(&v16, v1, &displayGeometries);
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 48i64);
  v4 = (hkGeometry *)v3;
  if ( v3 )
  {
    *(_DWORD *)(v3 + 8) = 0x1FFFF;
    *(_QWORD *)v3 = &hkGeometry::`vftable';
    *(_QWORD *)(v3 + 16) = 0i64;
    *(_DWORD *)(v3 + 24) = 0;
    *(_DWORD *)(v3 + 28) = 2147483648;
    *(_QWORD *)(v3 + 32) = 0i64;
    *(_DWORD *)(v3 + 40) = 0;
    *(_DWORD *)(v3 + 44) = 2147483648;
  }
  else
  {
    v4 = 0i64;
  }
  for ( i = displayGeometries.m_size - 1; i >= 0; --i )
  {
    v6 = displayGeometries.m_data[i];
    v6->vfptr[1].__first_virtual_table_function__((hkBaseObject *)&v6->vfptr);
    v7 = v6->m_geometry;
    if ( v7 )
    {
      if ( hkGeometry::isValid(v7, (hkBool *)&retaddr)->m_bool )
      {
        v8 = v6->m_transform.m_translation.m_quad;
        v9 = v6->m_geometry;
        v10 = _mm_srli_si128(_mm_slli_si128((__m128i)v6->m_transform.m_rotation.m_col1.m_quad, 4), 4);
        v11 = (__m128i)v6->m_transform.m_rotation.m_col2;
        _mm_store_si128(
          (__m128i *)&transform,
          _mm_srli_si128(_mm_slli_si128((__m128i)v6->m_transform.m_rotation.m_col0.m_quad, 4), 4));
        _mm_store_si128((__m128i *)&transform.m_col1, v10);
        _mm_store_si128((__m128i *)&transform.m_col2, _mm_srli_si128(_mm_slli_si128(v11, 4), 4));
        transform.m_col3.m_quad = _mm_shuffle_ps(v8, _mm_unpackhi_ps(v8, query.m_quad), 196);
        hkGeometry::appendGeometry(v4, &result, v9, &transform);
      }
      else
      {
        hkErrStream::hkErrStream(&v13, &buf, 512);
        hkOstream::operator<<(
          (hkOstream *)&v13.vfptr,
          "Invalid geometry from hkShape display geometry data. Skipping it.");
        hkError::messageWarning(1870306875, &buf, "Collide\\ShapeUtils\\ShapeConverter\\hkpShapeConverter.cpp", 47);
        hkOstream::~hkOstream((hkOstream *)&v13.vfptr);
      }
    }
    else
    {
      hkErrStream::hkErrStream(&v13, &buf, 512);
      hkOstream::operator<<((hkOstream *)&v13.vfptr, "Unable to build geometry from hkShape display geometry data.");
      hkError::messageWarning(1870306874, &buf, "Collide\\ShapeUtils\\ShapeConverter\\hkpShapeConverter.cpp", 41);
      hkOstream::~hkOstream((hkOstream *)&v13.vfptr);
    }
    hkReferencedObject::removeReference((hkReferencedObject *)&v6->vfptr);
  }
  if ( !hkGeometry::isValid(v4, (hkBool *)&retaddr)->m_bool || v4->m_vertices.m_size <= 0 )
  {
    hkErrStream::hkErrStream(&v13, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v13.vfptr, "Appending geometries failed.");
    hkError::messageWarning(116894179, &buf, "Collide\\ShapeUtils\\ShapeConverter\\hkpShapeConverter.cpp", 63);
    hkOstream::~hkOstream((hkOstream *)&v13.vfptr);
    if ( v4 )
      v4->vfptr->__vecDelDtor((hkBaseObject *)&v4->vfptr, 1u);
    v4 = 0i64;
  }
  displayGeometries.m_size = 0;
  v16.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  if ( displayGeometries.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      displayGeometries.m_data,
      8 * displayGeometries.m_capacityAndFlags);
  return v4;
}

// File Line: 73
// RVA: 0xE13820
hkGeometry *__fastcall hkpShapeConverter::clone(hkGeometry *geom)
{
  hkGeometry *v1; // rdi
  _QWORD **v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx
  __int64 v5; // rax
  __int64 v6; // rcx
  __int64 v7; // rdx
  char *v8; // r8
  __int128 v9; // xmm0
  __int64 v10; // rax
  __int64 v11; // rcx
  __int64 v12; // r8
  char *v13; // r9
  int v14; // edx
  int v16; // [rsp+30h] [rbp+8h]

  v1 = geom;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 48i64);
  v4 = v3;
  if ( v3 )
  {
    *(_DWORD *)(v3 + 8) = 0x1FFFF;
    *(_QWORD *)v3 = &hkGeometry::`vftable';
    *(_DWORD *)(v3 + 28) = 2147483648;
    *(_QWORD *)(v3 + 16) = 0i64;
    *(_DWORD *)(v3 + 24) = 0;
    *(_QWORD *)(v3 + 32) = 0i64;
    *(_DWORD *)(v3 + 40) = 0;
    *(_DWORD *)(v3 + 44) = 2147483648;
  }
  else
  {
    v4 = 0i64;
  }
  if ( (*(_DWORD *)(v4 + 28) & 0x3FFFFFFF) < v1->m_vertices.m_size )
  {
    if ( *(_DWORD *)(v4 + 28) >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)(v4 + 16),
        16 * *(_DWORD *)(v4 + 28));
    v16 = 16 * v1->m_vertices.m_size;
    *(_QWORD *)(v4 + 16) = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                             (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                             &v16);
    *(_DWORD *)(v4 + 28) = v16 / 16;
  }
  v5 = v1->m_vertices.m_size;
  v6 = *(_QWORD *)(v4 + 16);
  *(_DWORD *)(v4 + 24) = v5;
  v7 = v5;
  if ( (signed int)v5 > 0 )
  {
    v8 = (char *)v1->m_vertices.m_data - v6;
    do
    {
      v9 = *(_OWORD *)&v8[v6];
      v6 += 16i64;
      *(_OWORD *)(v6 - 16) = v9;
      --v7;
    }
    while ( v7 );
  }
  if ( (*(_DWORD *)(v4 + 44) & 0x3FFFFFFF) < v1->m_triangles.m_size )
  {
    if ( *(_DWORD *)(v4 + 44) >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)(v4 + 32),
        16 * *(_DWORD *)(v4 + 44));
    v16 = 16 * v1->m_triangles.m_size;
    *(_QWORD *)(v4 + 32) = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                             (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                             &v16);
    *(_DWORD *)(v4 + 44) = v16 / 16;
  }
  v10 = v1->m_triangles.m_size;
  v11 = *(_QWORD *)(v4 + 32);
  *(_DWORD *)(v4 + 40) = v10;
  v12 = v10;
  if ( (signed int)v10 > 0 )
  {
    v13 = (char *)v1->m_triangles.m_data - v11;
    do
    {
      v14 = *(_DWORD *)&v13[v11];
      v11 += 16i64;
      *(_DWORD *)(v11 - 16) = v14;
      *(_DWORD *)(v11 - 12) = *(_DWORD *)&v13[v11 - 12];
      *(_DWORD *)(v11 - 8) = *(_DWORD *)&v13[v11 - 8];
      *(_DWORD *)(v11 - 4) = *(_DWORD *)&v13[v11 - 4];
      --v12;
    }
    while ( v12 );
  }
  return (hkGeometry *)v4;
}


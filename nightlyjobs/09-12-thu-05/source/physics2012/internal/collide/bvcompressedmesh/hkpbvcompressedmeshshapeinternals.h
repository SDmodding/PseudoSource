// File Line: 80
// RVA: 0xDF1F50
void __fastcall hkpBvCompressedMeshShapeTree::hkpBvCompressedMeshShapeTree(hkpBvCompressedMeshShapeTree *this)
{
  this->m_nodes.m_capacityAndFlags = 0x80000000;
  this->m_nodes.m_data = 0i64;
  this->m_nodes.m_size = 0;
  this->m_domain.m_min = (hkVector4f)xmmword_141A712A0;
  this->m_domain.m_max.m_quad = _mm_xor_ps(
                                  (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                  this->m_domain.m_min.m_quad);
  *(_QWORD *)&this->m_numPrimitiveKeys = 0i64;
  this->m_sections.m_data = 0i64;
  this->m_sections.m_size = 0;
  this->m_sections.m_capacityAndFlags = 0x80000000;
  this->m_primitives.m_data = 0i64;
  this->m_primitives.m_size = 0;
  this->m_primitives.m_capacityAndFlags = 0x80000000;
  this->m_sharedVerticesIndex.m_data = 0i64;
  this->m_sharedVerticesIndex.m_size = 0;
  this->m_sharedVerticesIndex.m_capacityAndFlags = 0x80000000;
  this->m_packedVertices.m_data = 0i64;
  this->m_packedVertices.m_size = 0;
  this->m_packedVertices.m_capacityAndFlags = 0x80000000;
  this->m_sharedVertices.m_data = 0i64;
  this->m_sharedVertices.m_size = 0;
  this->m_sharedVertices.m_capacityAndFlags = 0x80000000;
  this->m_primitiveDataRuns.m_data = 0i64;
  this->m_primitiveDataRuns.m_size = 0;
  this->m_primitiveDataRuns.m_capacityAndFlags = 0x80000000;
}

// File Line: 172
// RVA: 0xDF20A0
void __fastcall hkpBvCompressedMeshShape_Internals::GeometryProvider::~GeometryProvider(
        hkpBvCompressedMeshShape_Internals::GeometryProvider *this)
{
  int v2; // esi
  __int64 v3; // r14
  hkpBvCompressedMeshShape_Internals::GeometryProvider::Cache *v4; // rbx
  int m_capacityAndFlags; // r8d
  _QWORD **Value; // rax
  int v7; // r8d

  v2 = 0;
  if ( this->m_caches.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = this->m_caches.m_data[v3];
      if ( v4 )
      {
        m_capacityAndFlags = v4->m_vertices.m_capacityAndFlags;
        v4->m_vertices.m_size = 0;
        if ( m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v4->m_vertices.m_data,
            16 * m_capacityAndFlags);
        v4->m_vertices.m_data = 0i64;
        v4->m_vertices.m_capacityAndFlags = 0x80000000;
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkpBvCompressedMeshShape_Internals::GeometryProvider::Cache *, __int64))(*Value[11] + 16i64))(
          Value[11],
          v4,
          48i64);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_caches.m_size );
  }
  v7 = this->m_caches.m_capacityAndFlags;
  this->m_caches.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_caches.m_data, 8 * v7);
  this->m_caches.m_data = 0i64;
  this->m_caches.m_capacityAndFlags = 0x80000000;
}

// File Line: 203
// RVA: 0xE09DF0
void __fastcall hkpBvCompressedMeshShape_Internals::expandBoxVertices(hkVector4f *vertices)
{
  __m128 m_quad; // xmm0
  __m128 v2; // xmm1
  __m128 v3; // xmm3
  __m128 v4; // xmm5
  __m128 v5; // xmm1
  __m128 v6; // xmm1

  m_quad = vertices[2].m_quad;
  v2 = vertices[1].m_quad;
  v3 = _mm_add_ps(_mm_sub_ps(m_quad, vertices->m_quad), v2);
  v4 = _mm_sub_ps(vertices[3].m_quad, vertices->m_quad);
  v5 = _mm_sub_ps(v2, vertices->m_quad);
  vertices[4] = (hkVector4f)v3;
  v6 = _mm_add_ps(v5, vertices[3].m_quad);
  vertices[5].m_quad = _mm_add_ps(m_quad, v4);
  vertices[7].m_quad = _mm_add_ps(v3, v4);
  vertices[6] = (hkVector4f)v6;
}


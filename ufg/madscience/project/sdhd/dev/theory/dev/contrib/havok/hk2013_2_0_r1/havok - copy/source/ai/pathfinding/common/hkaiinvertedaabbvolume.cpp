// File Line: 18
// RVA: 0xBE4E50
void __fastcall hkaiInvertedAabbVolume::hkaiInvertedAabbVolume(hkaiInvertedAabbVolume *this, hkAabb *aabb)
{
  hkAabb *p_m_aabb; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  p_m_aabb = &this->m_aabb;
  p_m_aabb[-1].m_max.m_quad.m128_u64[0] = (unsigned __int64)&hkaiInvertedAabbVolume::`vftable;
  *p_m_aabb = *aabb;
  this->m_geometry.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  *(_DWORD *)&this->m_geometry.m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry.m_vertices.m_data = 0i64;
  this->m_geometry.m_vertices.m_size = 0;
  this->m_geometry.m_vertices.m_capacityAndFlags = 0x80000000;
  this->m_geometry.m_triangles.m_data = 0i64;
  this->m_geometry.m_triangles.m_size = 0;
  this->m_geometry.m_triangles.m_capacityAndFlags = 0x80000000;
  hkaiPlaneVolume::createAabbGeometry(p_m_aabb, &this->m_geometry);
}

// File Line: 23
// RVA: 0xBE4ED0
void __fastcall hkaiInvertedAabbVolume::calcPointsInside(
        hkaiInvertedAabbVolume *this,
        hkVector4f *points,
        __int64 numPoints,
        hkBitField *pointsInside)
{
  int v5; // eax
  __int64 v6; // r10

  v5 = 1;
  if ( (int)numPoints > 0 )
  {
    v6 = 0i64;
    numPoints = (unsigned int)numPoints;
    do
    {
      if ( (_mm_movemask_ps(
              _mm_and_ps(
                _mm_cmple_ps(this->m_aabb.m_min.m_quad, points->m_quad),
                _mm_cmple_ps(points->m_quad, this->m_aabb.m_max.m_quad))) & 7) != 7 )
        pointsInside->m_storage.m_words.m_data[v6 >> 5] |= v5;
      v5 = __ROL4__(v5, 1);
      ++v6;
      ++points;
      --numPoints;
    }
    while ( numPoints );
  }
}

// File Line: 35
// RVA: 0xBE4F40
_BOOL8 __fastcall hkaiInvertedAabbVolume::containsTriangle(
        hkaiInvertedAabbVolume *this,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c)
{
  return (_mm_movemask_ps(
            _mm_and_ps(
              _mm_cmple_ps(_mm_min_ps(_mm_min_ps(a->m_quad, b->m_quad), c->m_quad), this->m_aabb.m_max.m_quad),
              _mm_cmple_ps(this->m_aabb.m_min.m_quad, _mm_max_ps(_mm_max_ps(a->m_quad, b->m_quad), c->m_quad)))) & 7) != 7;
}

// File Line: 42
// RVA: 0xBE4F80
_BOOL8 __fastcall hkaiInvertedAabbVolume::containsAabb(hkaiInvertedAabbVolume *this, hkAabb *aabbIn)
{
  return (_mm_movemask_ps(
            _mm_and_ps(
              _mm_cmple_ps(aabbIn->m_min.m_quad, this->m_aabb.m_max.m_quad),
              _mm_cmple_ps(this->m_aabb.m_min.m_quad, aabbIn->m_max.m_quad))) & 7) != 7;
}

// File Line: 47
// RVA: 0xBE4FB0
hkResult *__fastcall hkaiInvertedAabbVolume::calcGeometry(
        hkaiInvertedAabbVolume *this,
        hkResult *result,
        hkGeometry *geom)
{
  int m_size; // r9d
  __int64 v7; // rax
  hkVector4f *m_data; // rcx
  __int64 v9; // rdx
  char *v10; // r8
  hkVector4f v11; // xmm0
  int v13; // r9d
  __int64 v14; // rcx
  hkGeometry::Triangle *v15; // rax
  __int64 v16; // rdx
  char *v17; // r8
  int v18; // ecx
  hkResult resulta; // [rsp+50h] [rbp+8h] BYREF
  int v20; // [rsp+60h] [rbp+18h] BYREF

  m_size = this->m_geometry.m_vertices.m_size;
  if ( (geom->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) >= m_size )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &geom->m_vertices, m_size, 16);
    if ( resulta.m_enum )
    {
LABEL_13:
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  if ( (geom->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) < this->m_geometry.m_vertices.m_size )
  {
    if ( geom->m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        geom->m_vertices.m_data,
        16 * geom->m_vertices.m_capacityAndFlags);
    v20 = 16 * this->m_geometry.m_vertices.m_size;
    geom->m_vertices.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                              &hkContainerHeapAllocator::s_alloc,
                                              &v20);
    geom->m_vertices.m_capacityAndFlags = v20 / 16;
  }
  v7 = this->m_geometry.m_vertices.m_size;
  m_data = geom->m_vertices.m_data;
  geom->m_vertices.m_size = v7;
  v9 = v7;
  if ( (int)v7 > 0 )
  {
    v10 = (char *)((char *)this->m_geometry.m_vertices.m_data - (char *)m_data);
    do
    {
      v11.m_quad = *(__m128 *)((char *)m_data++ + (_QWORD)v10);
      m_data[-1] = (hkVector4f)v11.m_quad;
      --v9;
    }
    while ( v9 );
  }
  if ( resulta.m_enum )
    goto LABEL_13;
  v13 = this->m_geometry.m_triangles.m_size;
  if ( (geom->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) >= v13 )
  {
    result->m_enum = HK_SUCCESS;
LABEL_18:
    if ( (geom->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) < this->m_geometry.m_triangles.m_size )
    {
      if ( geom->m_triangles.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          geom->m_triangles.m_data,
          16 * geom->m_triangles.m_capacityAndFlags);
      v20 = 16 * this->m_geometry.m_triangles.m_size;
      geom->m_triangles.m_data = (hkGeometry::Triangle *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                           &hkContainerHeapAllocator::s_alloc,
                                                           &v20);
      geom->m_triangles.m_capacityAndFlags = v20 / 16;
    }
    v14 = this->m_geometry.m_triangles.m_size;
    v15 = geom->m_triangles.m_data;
    geom->m_triangles.m_size = v14;
    v16 = v14;
    if ( (int)v14 > 0 )
    {
      v17 = (char *)((char *)this->m_geometry.m_triangles.m_data - (char *)v15);
      do
      {
        v18 = *(int *)((char *)&v15->m_a + (_QWORD)v17);
        ++v15;
        v15[-1].m_a = v18;
        v15[-1].m_b = *(_DWORD *)((char *)v15 + (_QWORD)v17 - 12);
        v15[-1].m_c = *(_DWORD *)((char *)v15 + (_QWORD)v17 - 8);
        v15[-1].m_material = *(_DWORD *)((char *)v15 + (_QWORD)v17 - 4);
        --v16;
      }
      while ( v16 );
    }
    return result;
  }
  hkArrayUtil::_reserve(result, &hkContainerHeapAllocator::s_alloc, &geom->m_triangles, v13, 16);
  if ( result->m_enum == HK_SUCCESS )
    goto LABEL_18;
  return result;
}

// File Line: 54
// RVA: 0xBE51C0
void __fastcall hkaiInvertedAabbVolume::getAabb(hkaiInvertedAabbVolume *this, hkAabb *aabbOut)
{
  aabbOut->m_max = (hkVector4f)xmmword_141A712A0;
  aabbOut->m_min.m_quad = _mm_xor_ps(
                            (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                            aabbOut->m_max.m_quad);
}


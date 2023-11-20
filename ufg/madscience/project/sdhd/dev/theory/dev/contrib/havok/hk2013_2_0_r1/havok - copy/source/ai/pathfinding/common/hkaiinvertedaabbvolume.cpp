// File Line: 18
// RVA: 0xBE4E50
void __fastcall hkaiInvertedAabbVolume::hkaiInvertedAabbVolume(hkaiInvertedAabbVolume *this, hkAabb *aabb)
{
  hkaiInvertedAabbVolume *v2; // rbx
  hkAabb *v3; // rcx
  hkVector4f v4; // xmm1
  signed __int64 v5; // rdx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = this;
  v3 = &this->m_aabb;
  v3[-1].m_max.m_quad.m128_u64[0] = (unsigned __int64)&hkaiInvertedAabbVolume::`vftable';
  v3->m_min = aabb->m_min;
  v4.m_quad = (__m128)aabb->m_max;
  v5 = (signed __int64)&v2->m_geometry;
  v3->m_max = (hkVector4f)v4.m_quad;
  *(_QWORD *)v5 = &hkGeometry::`vftable';
  *(_DWORD *)(v5 + 8) = 0x1FFFF;
  *(_QWORD *)(v5 + 16) = 0i64;
  *(_DWORD *)(v5 + 24) = 0;
  *(_DWORD *)(v5 + 28) = 2147483648;
  *(_QWORD *)(v5 + 32) = 0i64;
  *(_DWORD *)(v5 + 40) = 0;
  *(_DWORD *)(v5 + 44) = 2147483648;
  hkaiPlaneVolume::createAabbGeometry(v3, &v2->m_geometry);
}

// File Line: 23
// RVA: 0xBE4ED0
void __fastcall hkaiInvertedAabbVolume::calcPointsInside(hkaiInvertedAabbVolume *this, hkVector4f *points, __int64 numPoints, hkBitField *pointsInside)
{
  hkVector4f *v4; // r11
  signed int v5; // eax
  __int64 v6; // r10

  v4 = points;
  v5 = 1;
  if ( (signed int)numPoints > 0 )
  {
    v6 = 0i64;
    numPoints = (unsigned int)numPoints;
    do
    {
      if ( (_mm_movemask_ps(
              _mm_and_ps(
                _mm_cmpleps(this->m_aabb.m_min.m_quad, v4->m_quad),
                _mm_cmpleps(v4->m_quad, this->m_aabb.m_max.m_quad))) & 7) != 7 )
        pointsInside->m_storage.m_words.m_data[v6 >> 5] |= v5;
      v5 = __ROL4__(v5, 1);
      ++v6;
      ++v4;
      --numPoints;
    }
    while ( numPoints );
  }
}

// File Line: 35
// RVA: 0xBE4F40
_BOOL8 __fastcall hkaiInvertedAabbVolume::containsTriangle(hkaiInvertedAabbVolume *this, hkVector4f *a, hkVector4f *b, hkVector4f *c)
{
  return (_mm_movemask_ps(
            _mm_and_ps(
              _mm_cmpleps(_mm_min_ps(_mm_min_ps(a->m_quad, b->m_quad), c->m_quad), this->m_aabb.m_max.m_quad),
              _mm_cmpleps(this->m_aabb.m_min.m_quad, _mm_max_ps(_mm_max_ps(a->m_quad, b->m_quad), c->m_quad)))) & 7) != 7;
}

// File Line: 42
// RVA: 0xBE4F80
_BOOL8 __fastcall hkaiInvertedAabbVolume::containsAabb(hkaiInvertedAabbVolume *this, hkAabb *aabbIn)
{
  return (_mm_movemask_ps(
            _mm_and_ps(
              _mm_cmpleps(aabbIn->m_min.m_quad, this->m_aabb.m_max.m_quad),
              _mm_cmpleps(this->m_aabb.m_min.m_quad, aabbIn->m_max.m_quad))) & 7) != 7;
}

// File Line: 47
// RVA: 0xBE4FB0
hkResult *__fastcall hkaiInvertedAabbVolume::calcGeometry(hkaiInvertedAabbVolume *this, hkResult *result, hkGeometry *geom)
{
  int v3; // er9
  hkGeometry *v4; // rbp
  hkResult *v5; // rsi
  hkaiInvertedAabbVolume *v6; // rdi
  __int64 v7; // rax
  hkVector4f *v8; // rcx
  __int64 v9; // rdx
  char *v10; // r8
  hkVector4f v11; // xmm0
  int v13; // er9
  __int64 v14; // rcx
  hkGeometry::Triangle *v15; // rax
  __int64 v16; // rdx
  char *v17; // r8
  int v18; // ecx
  hkResult resulta; // [rsp+50h] [rbp+8h]
  int v20; // [rsp+60h] [rbp+18h]

  v3 = this->m_geometry.m_vertices.m_size;
  v4 = geom;
  v5 = result;
  v6 = this;
  if ( (geom->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) >= v3 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &geom->m_vertices,
      v3,
      16);
    if ( resulta.m_enum )
    {
LABEL_13:
      v5->m_enum = 1;
      return v5;
    }
  }
  if ( (v4->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) < v6->m_geometry.m_vertices.m_size )
  {
    if ( v4->m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v4->m_vertices.m_data,
        16 * v4->m_vertices.m_capacityAndFlags);
    v20 = 16 * v6->m_geometry.m_vertices.m_size;
    v4->m_vertices.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                            &v20);
    v4->m_vertices.m_capacityAndFlags = v20 / 16;
  }
  v7 = v6->m_geometry.m_vertices.m_size;
  v8 = v4->m_vertices.m_data;
  v4->m_vertices.m_size = v7;
  v9 = v7;
  if ( (signed int)v7 > 0 )
  {
    v10 = (char *)((char *)v6->m_geometry.m_vertices.m_data - (char *)v8);
    do
    {
      v11.m_quad = *(__m128 *)((char *)v8 + (_QWORD)v10);
      ++v8;
      v8[-1] = (hkVector4f)v11.m_quad;
      --v9;
    }
    while ( v9 );
  }
  if ( resulta.m_enum )
    goto LABEL_13;
  v13 = v6->m_geometry.m_triangles.m_size;
  if ( (v4->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) >= v13 )
  {
    v5->m_enum = 0;
LABEL_18:
    if ( (v4->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) < v6->m_geometry.m_triangles.m_size )
    {
      if ( v4->m_triangles.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v4->m_triangles.m_data,
          16 * v4->m_triangles.m_capacityAndFlags);
      v20 = 16 * v6->m_geometry.m_triangles.m_size;
      v4->m_triangles.m_data = (hkGeometry::Triangle *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                         (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                         &v20);
      v4->m_triangles.m_capacityAndFlags = v20 / 16;
    }
    v14 = v6->m_geometry.m_triangles.m_size;
    v15 = v4->m_triangles.m_data;
    v4->m_triangles.m_size = v14;
    v16 = v14;
    if ( (signed int)v14 > 0 )
    {
      v17 = (char *)((char *)v6->m_geometry.m_triangles.m_data - (char *)v15);
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
    return v5;
  }
  hkArrayUtil::_reserve(v5, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_triangles, v13, 16);
  if ( v5->m_enum == HK_SUCCESS )
    goto LABEL_18;
  return v5;
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


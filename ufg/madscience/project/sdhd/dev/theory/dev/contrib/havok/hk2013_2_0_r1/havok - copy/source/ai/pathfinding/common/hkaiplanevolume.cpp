// File Line: 23
// RVA: 0xBE56B0
void __fastcall hkaiPlaneVolume::hkaiPlaneVolume(hkaiPlaneVolume *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPlaneVolume::`vftable;
  this->m_planes.m_data = 0i64;
  this->m_planes.m_size = 0;
  this->m_planes.m_capacityAndFlags = 0x80000000;
  *(_DWORD *)&this->m_geometry.m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  this->m_geometry.m_vertices.m_data = 0i64;
  this->m_geometry.m_vertices.m_size = 0;
  this->m_geometry.m_vertices.m_capacityAndFlags = 0x80000000;
  this->m_geometry.m_triangles.m_data = 0i64;
  this->m_geometry.m_triangles.m_size = 0;
  this->m_geometry.m_triangles.m_capacityAndFlags = 0x80000000;
  this->m_isInverted.m_bool = 0;
  this->m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
  this->m_aabb.m_max.m_quad = _mm_xor_ps(
                                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                this->m_aabb.m_min.m_quad);
}

// File Line: 31
// RVA: 0xBE5740
void __fastcall hkaiPlaneVolume::hkaiPlaneVolume(hkaiPlaneVolume *this, hkFinishLoadedObjectFlag f)
{
  hkGeometry *p_m_geometry; // rcx

  p_m_geometry = &this->m_geometry;
  p_m_geometry[-1].m_vertices.m_data = (hkVector4f *)&hkaiPlaneVolume::`vftable;
  hkGeometry::hkGeometry(p_m_geometry, f);
  if ( f.m_finishing )
  {
    if ( (_mm_movemask_ps(_mm_cmple_ps(this->m_aabb.m_max.m_quad, this->m_aabb.m_min.m_quad)) & 7) != 0 )
      hkaiPlaneVolume::updateInternalInfo(this);
  }
}

// File Line: 42
// RVA: 0xBE6150
void __fastcall hkaiPlaneVolume::createConvexVolume(hkVector4f *points, int numPoints, hkaiPlaneVolume *volumeOut)
{
  hkStridedVertices stridedVertsIn; // [rsp+20h] [rbp-18h] BYREF

  stridedVertsIn.m_vertices = (const float *)points;
  stridedVertsIn.m_numVertices = numPoints;
  stridedVertsIn.m_striding = 16;
  hkGeometryUtility::createConvexGeometry(&stridedVertsIn, &volumeOut->m_geometry, &volumeOut->m_planes);
  hkaiPlaneVolume::updateInternalInfo(volumeOut);
}

// File Line: 53
// RVA: 0xBE5D50
void __fastcall hkaiPlaneVolume::setFromAabb(hkaiPlaneVolume *this, hkAabb *aabb)
{
  int v4; // r9d
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  if ( (this->m_planes.m_capacityAndFlags & 0x3FFFFFFFu) < 6 )
  {
    v4 = 6;
    if ( 2 * (this->m_planes.m_capacityAndFlags & 0x3FFFFFFF) > 6 )
      v4 = 2 * (this->m_planes.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_planes, v4, 16);
  }
  this->m_planes.m_size = 6;
  this->m_planes.m_data->m_quad = _mm_unpacklo_ps(
                                    (__m128)_xmm,
                                    _mm_unpacklo_ps(
                                      (__m128)0i64,
                                      _mm_xor_ps((__m128)aabb->m_max.m_quad.m128_u32[0], (__m128)(unsigned int)_xmm[0])));
  this->m_planes.m_data[1].m_quad = _mm_unpacklo_ps(
                                      (__m128)_xmm,
                                      _mm_unpacklo_ps((__m128)0i64, (__m128)aabb->m_min.m_quad.m128_u32[0]));
  this->m_planes.m_data[2].m_quad = _mm_unpacklo_ps(
                                      (__m128)0i64,
                                      _mm_unpacklo_ps(
                                        (__m128)(unsigned int)FLOAT_1_0,
                                        _mm_xor_ps(
                                          (__m128)aabb->m_max.m_quad.m128_u32[1],
                                          (__m128)(unsigned int)_xmm[0])));
  this->m_planes.m_data[3].m_quad = _mm_unpacklo_ps(
                                      (__m128)0i64,
                                      _mm_unpacklo_ps(
                                        (__m128)LODWORD(FLOAT_N1_0),
                                        (__m128)aabb->m_min.m_quad.m128_u32[1]));
  this->m_planes.m_data[4].m_quad = _mm_unpacklo_ps(
                                      _xmm,
                                      _mm_unpacklo_ps(
                                        (__m128)0i64,
                                        _mm_xor_ps(
                                          (__m128)aabb->m_max.m_quad.m128_u32[2],
                                          (__m128)(unsigned int)_xmm[0])));
  this->m_planes.m_data[5].m_quad = _mm_unpacklo_ps(
                                      (__m128)_xmm,
                                      _mm_unpacklo_ps((__m128)0i64, (__m128)aabb->m_min.m_quad.m128_u32[2]));
  hkaiPlaneVolume::createAabbGeometry(aabb, &this->m_geometry);
  hkaiPlaneVolume::updateInternalInfo(this);
}

// File Line: 70
// RVA: 0xBE6190
void __fastcall hkaiPlaneVolume::createAabbGeometry(hkAabb *aabb, hkGeometry *geometryOut)
{
  int v4; // r9d
  int v5; // ecx
  __int64 v6; // rdx
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  int v10; // r9d
  hkGeometry::Triangle *m_data; // r8
  const unsigned __int16 *v12; // rdx
  int *p_m_c; // rcx
  __int64 v14; // r9
  int v15; // eax
  int v16; // eax
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  if ( (geometryOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFFu) < 8 )
  {
    v4 = 8;
    if ( 2 * (geometryOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) > 8 )
      v4 = 2 * (geometryOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &geometryOut->m_vertices, v4, 16);
  }
  geometryOut->m_vertices.m_size = 8;
  v5 = 0;
  v6 = 0i64;
  do
  {
    if ( (v5 & 4) != 0 )
      v7 = (__m128)aabb->m_max.m_quad.m128_u32[2];
    else
      v7 = (__m128)aabb->m_min.m_quad.m128_u32[2];
    if ( (v5 & 2) != 0 )
      v8 = (__m128)aabb->m_max.m_quad.m128_u32[1];
    else
      v8 = (__m128)aabb->m_min.m_quad.m128_u32[1];
    if ( (v5 & 1) != 0 )
      v9 = (__m128)aabb->m_max.m_quad.m128_u32[0];
    else
      v9 = (__m128)aabb->m_min.m_quad.m128_u32[0];
    ++v5;
    geometryOut->m_vertices.m_data[v6++].m_quad = _mm_unpacklo_ps(
                                                    _mm_unpacklo_ps(v9, v7),
                                                    _mm_unpacklo_ps(v8, (__m128)0i64));
  }
  while ( v5 < 8 );
  if ( (geometryOut->m_triangles.m_capacityAndFlags & 0x3FFFFFFFu) < 0xC )
  {
    v10 = 12;
    if ( 2 * (geometryOut->m_triangles.m_capacityAndFlags & 0x3FFFFFFF) > 12 )
      v10 = 2 * (geometryOut->m_triangles.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &geometryOut->m_triangles, v10, 16);
  }
  m_data = geometryOut->m_triangles.m_data;
  geometryOut->m_triangles.m_size = 12;
  v12 = &indices[2];
  p_m_c = &m_data[1].m_c;
  v14 = 6i64;
  do
  {
    v15 = *(v12 - 2);
    p_m_c += 8;
    v12 += 4;
    m_data->m_a = v15;
    m_data += 2;
    *(p_m_c - 13) = *(v12 - 5);
    v16 = *(v12 - 4);
    *(p_m_c - 11) = 0;
    *(p_m_c - 12) = v16;
    *(p_m_c - 10) = *(v12 - 6);
    *(p_m_c - 9) = *(v12 - 4);
    *((_QWORD *)p_m_c - 4) = *(v12 - 3);
    --v14;
  }
  while ( v14 );
}

// File Line: 123
// RVA: 0xBE5EA0
void __fastcall hkaiPlaneVolume::transform(hkaiPlaneVolume *this, hkTransformf *trans)
{
  hkVector4f *m_data; // rax
  hkVector4f v4; // xmm6
  hkVector4f v5; // xmm7
  hkVector4f *v6; // r8
  int v7; // ecx
  hkVector4f v8; // xmm8
  __m128 v9; // xmm4
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm5
  __m128 m_quad; // xmm4
  __m128 v14; // xmm1
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  hkVector4f v18; // xmm3
  hkVector4f v19; // xmm4
  hkVector4f v20; // xmm5
  hkVector4f v21; // xmm6
  __int64 v22; // rcx
  hkVector4f *v23; // rax
  __m128 v24; // xmm1

  m_data = this->m_planes.m_data;
  v4.m_quad = (__m128)trans->m_rotation.m_col2;
  v5.m_quad = (__m128)trans->m_rotation.m_col0;
  v6 = m_data;
  v7 = this->m_planes.m_size - 1;
  v8.m_quad = (__m128)trans->m_rotation.m_col1;
  v9 = _mm_xor_ps(
         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
         trans->m_translation.m_quad);
  v10 = _mm_unpacklo_ps(trans->m_rotation.m_col0.m_quad, v8.m_quad);
  v11 = _mm_movelh_ps(v10, v4.m_quad);
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(_mm_movehl_ps(v11, v10), v4.m_quad, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), v11)),
          _mm_mul_ps(
            _mm_shuffle_ps(_mm_unpackhi_ps(trans->m_rotation.m_col0.m_quad, v8.m_quad), v4.m_quad, 228),
            _mm_shuffle_ps(v9, v9, 170)));
  do
  {
    m_quad = v6->m_quad;
    ++m_data;
    ++v6;
    --v7;
    v14 = _mm_mul_ps(m_quad, v12);
    v15 = _mm_shuffle_ps(v14, _mm_unpackhi_ps(v14, m_quad), 196);
    v16 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 78), v15);
    v17 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v8.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v5.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v4.m_quad));
    m_data[-1].m_quad = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, _mm_add_ps(_mm_shuffle_ps(v16, v16, 177), v16)), 196);
  }
  while ( v7 >= 0 );
  v18.m_quad = (__m128)trans->m_rotation.m_col0;
  v19.m_quad = (__m128)trans->m_rotation.m_col1;
  v20.m_quad = (__m128)trans->m_rotation.m_col2;
  v21.m_quad = (__m128)trans->m_translation;
  v22 = this->m_geometry.m_vertices.m_size - 1;
  v23 = &this->m_geometry.m_vertices.m_data[v22];
  do
  {
    v24 = v23->m_quad;
    --v23;
    --v22;
    v23[1].m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v19.m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v18.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v20.m_quad)),
                      v21.m_quad);
  }
  while ( v22 >= 0 );
  hkaiPlaneVolume::updateInternalInfo(this);
}

// File Line: 135
// RVA: 0xBE6700
__int64 __fastcall hkaiPlaneVolume::contains(hkaiPlaneVolume *this, hkVector4f *point)
{
  __m128 m_quad; // xmm3
  __int64 m_size; // rdx
  __int64 v5; // rax
  hkVector4f *i; // rcx
  __m128 v7; // xmm2
  __m128 v8; // xmm2
  __m128 v9; // xmm1

  m_quad = point->m_quad;
  if ( (_mm_movemask_ps(
          _mm_and_ps(
            _mm_cmple_ps(point->m_quad, this->m_aabb.m_max.m_quad),
            _mm_cmple_ps(this->m_aabb.m_min.m_quad, point->m_quad))) & 7) != 7 )
    return 0i64;
  m_size = this->m_planes.m_size;
  v5 = 0i64;
  if ( m_size > 0 )
  {
    for ( i = this->m_planes.m_data; ; ++i )
    {
      v7 = _mm_mul_ps(i->m_quad, m_quad);
      v8 = _mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, i->m_quad), 196);
      v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 78), v8);
      if ( (float)(_mm_shuffle_ps(v9, v9, 177).m128_f32[0] + v9.m128_f32[0]) > 0.0 )
        break;
      if ( ++v5 >= m_size )
        return 1i64;
    }
    return 0i64;
  }
  return 1i64;
}

// File Line: 155
// RVA: 0xBE5790
void __fastcall hkaiPlaneVolume::calcPointsInside(
        hkaiPlaneVolume *this,
        hkVector4f *points,
        unsigned int numPoints,
        hkBitField *pointsInside)
{
  __int64 v5; // rdi
  int v8; // ebx
  __int64 v9; // rbp

  if ( (int)numPoints > 0 )
  {
    v5 = 0i64;
    v8 = 1;
    v9 = numPoints;
    do
    {
      if ( (this->m_isInverted.m_bool != 0) != (hkaiPlaneVolume::contains(this, points) != 0) )
        pointsInside->m_storage.m_words.m_data[v5 >> 5] |= v8;
      v8 = __ROL4__(v8, 1);
      ++v5;
      ++points;
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 169
// RVA: 0xBE5A30
_BOOL8 __fastcall hkaiPlaneVolume::containsTriangle(hkaiPlaneVolume *this, hkVector4f *a, hkVector4f *b, hkVector4f *c)
{
  __m128 m_quad; // xmm5
  __m128 v8; // xmm6
  __int64 m_size; // r8
  __int64 v11; // rax
  hkVector4f *i; // rdx
  __m128 v13; // xmm1
  __m128 v14; // xmm1
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm1
  __m128 v21; // xmm3

  if ( !this->m_isInverted.m_bool )
    return hkaiPlaneVolume::contains(this, a)
        && hkaiPlaneVolume::contains(this, b)
        && hkaiPlaneVolume::contains(this, c);
  m_quad = a->m_quad;
  v8 = b->m_quad;
  if ( (_mm_movemask_ps(
          _mm_and_ps(
            _mm_cmple_ps(_mm_min_ps(_mm_min_ps(m_quad, b->m_quad), c->m_quad), this->m_aabb.m_max.m_quad),
            _mm_cmple_ps(this->m_aabb.m_min.m_quad, _mm_max_ps(_mm_max_ps(m_quad, b->m_quad), c->m_quad)))) & 7) == 7 )
  {
    m_size = this->m_planes.m_size;
    v11 = 0i64;
    if ( m_size <= 0 )
    {
      return 0i64;
    }
    else
    {
      for ( i = this->m_planes.m_data; ; ++i )
      {
        v13 = _mm_mul_ps(i->m_quad, m_quad);
        v14 = _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, i->m_quad), 196);
        v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 78), v14);
        v16 = _mm_mul_ps(i->m_quad, v8);
        v17 = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, i->m_quad), 196);
        v18 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 78), v17);
        v19 = _mm_mul_ps(i->m_quad, c->m_quad);
        v20 = _mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, i->m_quad), 196);
        v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 78), v20);
        if ( _mm_movemask_ps(
               _mm_and_ps(
                 _mm_and_ps(
                   _mm_cmplt_ps((__m128)0i64, _mm_add_ps(_mm_shuffle_ps(v18, v18, 177), v18)),
                   _mm_cmplt_ps((__m128)0i64, _mm_add_ps(_mm_shuffle_ps(v15, v15, 177), v15))),
                 _mm_cmplt_ps((__m128)0i64, _mm_add_ps(_mm_shuffle_ps(v21, v21, 177), v21)))) )
        {
          break;
        }
        if ( ++v11 >= m_size )
          return 0i64;
      }
      return 1i64;
    }
  }
  else
  {
    return 1i64;
  }
}

// File Line: 207
// RVA: 0xBE5BF0
__int64 __fastcall hkaiPlaneVolume::containsAabb(hkaiPlaneVolume *this, hkAabb *aabbIn)
{
  hkVector4f v2; // xmm5
  hkVector4f v4; // xmm6
  unsigned int v5; // edx
  __int64 m_size; // r9
  __int64 v8; // rax
  char m_bool; // r10
  hkVector4f *m_data; // rcx
  float v11; // xmm4_4
  __m128 v12; // xmm0
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm3

  v2.m_quad = (__m128)aabbIn->m_max;
  v4.m_quad = (__m128)aabbIn->m_min;
  v5 = 0;
  if ( (_mm_movemask_ps(
          _mm_and_ps(
            _mm_cmple_ps(v4.m_quad, this->m_aabb.m_max.m_quad),
            _mm_cmple_ps(this->m_aabb.m_min.m_quad, v2.m_quad))) & 7) != 7 )
  {
    LOBYTE(v5) = this->m_isInverted.m_bool != 0;
    return v5;
  }
  m_size = this->m_planes.m_size;
  v8 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_10:
    LOBYTE(v5) = this->m_isInverted.m_bool == 0;
    return v5;
  }
  m_bool = this->m_isInverted.m_bool;
  m_data = this->m_planes.m_data;
  while ( 1 )
  {
    LODWORD(v11) = _mm_shuffle_ps(m_data->m_quad, m_data->m_quad, 255).m128_u32[0];
    v12 = _mm_mul_ps(m_data->m_quad, v2.m_quad);
    v13 = _mm_mul_ps(m_data->m_quad, v4.m_quad);
    v14 = _mm_max_ps(v13, v12);
    v15 = _mm_min_ps(v13, v12);
    if ( !m_bool )
      break;
    if ( (float)((float)((float)(_mm_shuffle_ps(v15, v15, 85).m128_f32[0] + _mm_shuffle_ps(v15, v15, 0).m128_f32[0])
                       + _mm_shuffle_ps(v15, v15, 170).m128_f32[0])
               + v11) >= 0.0 )
      return 1i64;
LABEL_9:
    ++v8;
    ++m_data;
    if ( v8 >= m_size )
      goto LABEL_10;
  }
  if ( (float)((float)((float)(_mm_shuffle_ps(v14, v14, 85).m128_f32[0] + _mm_shuffle_ps(v14, v14, 0).m128_f32[0])
                     + _mm_shuffle_ps(v14, v14, 170).m128_f32[0])
             + v11) < 0.0 )
    goto LABEL_9;
  return 0i64;
}

// File Line: 245
// RVA: 0xBE5820
hkResult *__fastcall hkaiPlaneVolume::calcGeometry(hkaiPlaneVolume *this, hkResult *result, hkGeometry *geom)
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

// File Line: 252
// RVA: 0xBE5D00
void __fastcall hkaiPlaneVolume::getAabb(hkaiPlaneVolume *this, hkAabb *aabbOut)
{
  if ( this->m_isInverted.m_bool )
  {
    aabbOut->m_max = (hkVector4f)xmmword_141A712A0;
    aabbOut->m_min.m_quad = _mm_xor_ps(
                              (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                              aabbOut->m_max.m_quad);
  }
  else
  {
    *aabbOut = this->m_aabb;
  }
}

// File Line: 266
// RVA: 0xBE6030
hkaiPlaneVolume *__fastcall hkaiPlaneVolume::clone(hkaiPlaneVolume *this, hkTransformf *t)
{
  _QWORD **Value; // rax
  hkaiPlaneVolume *v5; // rax
  hkaiPlaneVolume *v6; // rax
  hkaiPlaneVolume *v7; // rbx
  __int64 m_size; // rcx
  hkVector4f *m_data; // rax
  __int64 v10; // rdx
  char *v11; // r8
  hkVector4f v12; // xmm0
  hkResult result; // [rsp+30h] [rbp+8h] BYREF

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkaiPlaneVolume *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 128i64);
  if ( v5 )
  {
    hkaiPlaneVolume::hkaiPlaneVolume(v5);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  hkGeometry::appendGeometry(&v7->m_geometry, &result, &this->m_geometry, 0i64);
  if ( (v7->m_planes.m_capacityAndFlags & 0x3FFFFFFF) < this->m_planes.m_size )
  {
    if ( v7->m_planes.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v7->m_planes.m_data,
        16 * v7->m_planes.m_capacityAndFlags);
    result.m_enum = 16 * this->m_planes.m_size;
    v7->m_planes.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                          &hkContainerHeapAllocator::s_alloc,
                                          &result);
    v7->m_planes.m_capacityAndFlags = result.m_enum / 16;
  }
  m_size = this->m_planes.m_size;
  m_data = v7->m_planes.m_data;
  v7->m_planes.m_size = m_size;
  v10 = m_size;
  if ( (int)m_size > 0 )
  {
    v11 = (char *)((char *)this->m_planes.m_data - (char *)m_data);
    do
    {
      v12.m_quad = *(__m128 *)((char *)m_data++ + (_QWORD)v11);
      m_data[-1] = (hkVector4f)v12.m_quad;
      --v10;
    }
    while ( v10 );
  }
  v7->m_isInverted.m_bool = this->m_isInverted.m_bool;
  hkaiPlaneVolume::transform(v7, t);
  return v7;
}

// File Line: 278
// RVA: 0xBE6300
void __fastcall hkaiPlaneVolume::createExtruded2DConvexHullVolume(
        hkVector4f *inputVerts,
        int numVerts,
        hkVector4f *up,
        hkSimdFloat32 *_cutoffHeight)
{
  __int64 v6; // rsi
  __m128 m_quad; // xmm8
  __m128 v9; // xmm6
  __int64 v10; // rdi
  __m128 v11; // xmm7
  __m128 v12; // xmm9
  __m128 v13; // xmm5
  __m128 v14; // xmm9
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm2
  hkVector4f v18; // xmm9
  hkVector4f *v19; // rax
  __int64 v20; // rcx
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __int32 v23; // ecx
  hkVector4f *v24; // r8
  unsigned int v25; // eax
  __m128 m_real; // xmm8
  int v27; // ecx
  float v28; // xmm8_4
  __m128 v29; // xmm2
  __m128 v30; // xmm0
  __m128 v31; // xmm6
  __m128 v32; // xmm7
  __int64 m_size; // rdi
  int v34; // ebx
  int v35; // r9d
  __int64 v36; // r8
  __int64 v37; // rdx
  __m128 v38; // xmm4
  __m128 v39; // xmm1
  __m128 v40; // xmm0
  __m128 v41; // xmm4
  hkVector4f *v42; // [rsp+8h] [rbp-79h] BYREF
  int v43; // [rsp+10h] [rbp-71h]
  int v44; // [rsp+14h] [rbp-6Dh]
  hkArrayBase<hkVector4f> array; // [rsp+18h] [rbp-69h] BYREF
  hkaiConvex2dUtils::Convex2DHullInput input; // [rsp+28h] [rbp-59h] BYREF
  hkResult result; // [rsp+E0h] [rbp+5Fh] BYREF
  hkaiPlaneVolume *v48; // [rsp+100h] [rbp+7Fh]

  v6 = numVerts;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  if ( numVerts > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, numVerts, 16);
  m_quad = up->m_quad;
  v9 = (__m128)xmmword_141A712A0;
  array.m_size = v6;
  v10 = v6;
  v11 = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A712A0);
  v12 = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, (__m128)0i64), 196);
  v13 = _mm_shuffle_ps(v12, v12, 241);
  v14 = _mm_shuffle_ps(v12, v12, 206);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_mul_ps(v13, v13);
  v17 = _mm_cmplt_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
            _mm_shuffle_ps(v16, v16, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
            _mm_shuffle_ps(v15, v15, 170)));
  v18.m_quad = _mm_xor_ps(
                 _mm_or_ps(_mm_and_ps(v14, v17), _mm_andnot_ps(v17, v13)),
                 (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
  if ( (int)v6 > 0 )
  {
    v19 = inputVerts;
    v20 = v6;
    do
    {
      ++v19;
      v21 = _mm_mul_ps(m_quad, v19[-1].m_quad);
      v22 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
              _mm_shuffle_ps(v21, v21, 170));
      v9 = _mm_min_ps(v9, v22);
      v11 = _mm_max_ps(v11, v22);
      --v20;
    }
    while ( v20 );
  }
  v23 = v6;
  v42 = 0i64;
  v43 = 0;
  v44 = 0x80000000;
  if ( (_DWORD)v6 )
  {
    result.m_enum = 16 * v6;
    v24 = (hkVector4f *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &result);
    v23 = result.m_enum / 16;
  }
  else
  {
    v24 = 0i64;
  }
  v25 = 0x80000000;
  v42 = v24;
  if ( v23 )
    v25 = v23;
  v43 = v6;
  v44 = v25;
  m_real = _cutoffHeight->m_real;
  v27 = 0;
  v43 = 0;
  v28 = m_real.m128_f32[0] + v9.m128_f32[0];
  if ( (int)v6 > 0 )
  {
    do
    {
      v29 = _mm_mul_ps(up->m_quad, inputVerts->m_quad);
      if ( (float)((float)(_mm_shuffle_ps(v29, v29, 85).m128_f32[0] + _mm_shuffle_ps(v29, v29, 0).m128_f32[0])
                 + _mm_shuffle_ps(v29, v29, 170).m128_f32[0]) < v28 )
      {
        if ( v27 == (v25 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &v42, 16);
          v27 = v43;
        }
        v42[v27] = (hkVector4f)inputVerts->m_quad;
        v25 = v44;
        v27 = ++v43;
      }
      ++inputVerts;
      --v10;
    }
    while ( v10 );
  }
  v30 = up->m_quad;
  v31 = _mm_sub_ps(v9, query.m_quad);
  v32 = _mm_add_ps(v11, query.m_quad);
  input.m_numVerts = v27;
  input.m_referenceAxis = (hkVector4f)v18.m_quad;
  input.m_up.m_quad = v30;
  input.m_transform = &hkQTransformfIdentity_storage;
  input.m_verts = v42;
  hkaiConvex2dUtils::createConvexHullSilhouette(&input, &array);
  m_size = array.m_size;
  v34 = 2 * array.m_size;
  if ( (array.m_capacityAndFlags & 0x3FFFFFFF) < 2 * array.m_size )
  {
    v35 = 2 * array.m_size;
    if ( v34 < 2 * (array.m_capacityAndFlags & 0x3FFFFFFF) )
      v35 = 2 * (array.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, v35, 16);
  }
  array.m_size = v34;
  v36 = m_size;
  if ( (int)m_size > 0 )
  {
    v37 = 0i64;
    do
    {
      v38 = array.m_data[v37++].m_quad;
      v39 = _mm_mul_ps(up->m_quad, v38);
      v40 = _mm_mul_ps(up->m_quad, v31);
      v41 = _mm_sub_ps(
              v38,
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                  _mm_shuffle_ps(v39, v39, 170)),
                up->m_quad));
      array.m_data[v37 - 1].m_quad = _mm_add_ps(_mm_mul_ps(up->m_quad, v32), v41);
      array.m_data[m_size - 1 + v37].m_quad = _mm_add_ps(v41, v40);
      --v36;
    }
    while ( v36 );
    v34 = array.m_size;
  }
  hkaiPlaneVolume::createConvexVolume(array.m_data, v34, v48);
  v43 = 0;
  if ( v44 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v42, 16 * v44);
  v42 = 0i64;
  v44 = 0x80000000;
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      16 * array.m_capacityAndFlags);
}

// File Line: 343
// RVA: 0xBE6790
void __fastcall hkaiPlaneVolume::updateInternalInfo(hkaiPlaneVolume *this)
{
  hkAabbUtil::calcAabb(this->m_geometry.m_vertices.m_data, this->m_geometry.m_vertices.m_size, &this->m_aabb);
}


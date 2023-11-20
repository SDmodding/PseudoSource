// File Line: 23
// RVA: 0xBE56B0
void __fastcall hkaiPlaneVolume::hkaiPlaneVolume(hkaiPlaneVolume *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPlaneVolume::`vftable;
  this->m_planes.m_data = 0i64;
  this->m_planes.m_size = 0;
  this->m_planes.m_capacityAndFlags = 2147483648;
  *(_DWORD *)&this->m_geometry.m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  this->m_geometry.m_vertices.m_data = 0i64;
  this->m_geometry.m_vertices.m_size = 0;
  this->m_geometry.m_vertices.m_capacityAndFlags = 2147483648;
  this->m_geometry.m_triangles.m_data = 0i64;
  this->m_geometry.m_triangles.m_size = 0;
  this->m_geometry.m_triangles.m_capacityAndFlags = 2147483648;
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
  hkaiPlaneVolume *v2; // rbx
  hkGeometry *v3; // rcx
  int v4; // [rsp+38h] [rbp+10h]

  v4 = f.m_finishing;
  v2 = this;
  v3 = &this->m_geometry;
  v3[-1].m_vertices.m_data = (hkVector4f *)&hkaiPlaneVolume::`vftable;
  hkGeometry::hkGeometry(v3, f);
  if ( v4 )
  {
    if ( _mm_movemask_ps(_mm_cmpleps(v2->m_aabb.m_max.m_quad, v2->m_aabb.m_min.m_quad)) & 7 )
      hkaiPlaneVolume::updateInternalInfo(v2);
  }
}

// File Line: 42
// RVA: 0xBE6150
void __fastcall hkaiPlaneVolume::createConvexVolume(hkVector4f *points, int numPoints, hkaiPlaneVolume *volumeOut)
{
  hkaiPlaneVolume *v3; // rbx
  hkStridedVertices stridedVertsIn; // [rsp+20h] [rbp-18h]

  v3 = volumeOut;
  stridedVertsIn.m_vertices = (const float *)points;
  stridedVertsIn.m_numVertices = numPoints;
  stridedVertsIn.m_striding = 16;
  hkGeometryUtility::createConvexGeometry(&stridedVertsIn, &volumeOut->m_geometry, &volumeOut->m_planes);
  hkaiPlaneVolume::updateInternalInfo(v3);
}

// File Line: 53
// RVA: 0xBE5D50
void __fastcall hkaiPlaneVolume::setFromAabb(hkaiPlaneVolume *this, hkAabb *aabb)
{
  hkAabb *v2; // rsi
  hkaiPlaneVolume *v3; // rdi
  int v4; // eax
  int v5; // eax
  int v6; // er9
  hkResult result; // [rsp+40h] [rbp+8h]

  v2 = aabb;
  v3 = this;
  v4 = this->m_planes.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < 6 )
  {
    v5 = 2 * v4;
    v6 = 6;
    if ( v5 > 6 )
      v6 = v5;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_planes,
      v6,
      16);
  }
  v3->m_planes.m_size = 6;
  v3->m_planes.m_data->m_quad = _mm_unpacklo_ps(
                                  (__m128)_xmm,
                                  _mm_unpacklo_ps(
                                    (__m128)0i64,
                                    _mm_xor_ps((__m128)v2->m_max.m_quad.m128_u32[0], (__m128)(unsigned int)_xmm[0])));
  v3->m_planes.m_data[1].m_quad = _mm_unpacklo_ps(
                                    (__m128)_xmm,
                                    _mm_unpacklo_ps((__m128)0i64, (__m128)v2->m_min.m_quad.m128_u32[0]));
  v3->m_planes.m_data[2].m_quad = _mm_unpacklo_ps(
                                    (__m128)0i64,
                                    _mm_unpacklo_ps(
                                      (__m128)(unsigned int)FLOAT_1_0,
                                      _mm_xor_ps((__m128)v2->m_max.m_quad.m128_u32[1], (__m128)(unsigned int)_xmm[0])));
  v3->m_planes.m_data[3].m_quad = _mm_unpacklo_ps(
                                    (__m128)0i64,
                                    _mm_unpacklo_ps((__m128)LODWORD(FLOAT_N1_0), (__m128)v2->m_min.m_quad.m128_u32[1]));
  v3->m_planes.m_data[4].m_quad = _mm_unpacklo_ps(
                                    _xmm,
                                    _mm_unpacklo_ps(
                                      (__m128)0i64,
                                      _mm_xor_ps((__m128)v2->m_max.m_quad.m128_u32[2], (__m128)(unsigned int)_xmm[0])));
  v3->m_planes.m_data[5].m_quad = _mm_unpacklo_ps(
                                    (__m128)_xmm,
                                    _mm_unpacklo_ps((__m128)0i64, (__m128)v2->m_min.m_quad.m128_u32[2]));
  hkaiPlaneVolume::createAabbGeometry(v2, &v3->m_geometry);
  hkaiPlaneVolume::updateInternalInfo(v3);
}

// File Line: 70
// RVA: 0xBE6190
void __fastcall hkaiPlaneVolume::createAabbGeometry(hkAabb *aabb, hkGeometry *geometryOut)
{
  hkGeometry *v2; // rsi
  hkAabb *v3; // rbx
  int v4; // eax
  int v5; // eax
  int v6; // er9
  signed int v7; // ecx
  __int64 v8; // rdx
  __m128 v9; // xmm0
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  int v12; // eax
  int v13; // eax
  int v14; // er9
  hkGeometry::Triangle *v15; // r8
  const unsigned __int16 *v16; // rdx
  signed __int64 v17; // rcx
  signed __int64 v18; // r9
  int v19; // eax
  int v20; // eax
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = geometryOut;
  v3 = aabb;
  v4 = geometryOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < 8 )
  {
    v5 = 2 * v4;
    v6 = 8;
    if ( v5 > 8 )
      v6 = v5;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &geometryOut->m_vertices,
      v6,
      16);
  }
  v2->m_vertices.m_size = 8;
  v7 = 0;
  v8 = 0i64;
  do
  {
    if ( v7 & 4 )
      v9 = (__m128)v3->m_max.m_quad.m128_u32[2];
    else
      v9 = (__m128)v3->m_min.m_quad.m128_u32[2];
    if ( v7 & 2 )
      v10 = (__m128)v3->m_max.m_quad.m128_u32[1];
    else
      v10 = (__m128)v3->m_min.m_quad.m128_u32[1];
    if ( v7 & 1 )
      v11 = (__m128)v3->m_max.m_quad.m128_u32[0];
    else
      v11 = (__m128)v3->m_min.m_quad.m128_u32[0];
    ++v7;
    ++v8;
    v2->m_vertices.m_data[v8 - 1].m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v11, v9), _mm_unpacklo_ps(v10, (__m128)0i64));
  }
  while ( v7 < 8 );
  v12 = v2->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v12 < 12 )
  {
    v13 = 2 * v12;
    v14 = 12;
    if ( v13 > 12 )
      v14 = v13;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v2->m_triangles,
      v14,
      16);
  }
  v15 = v2->m_triangles.m_data;
  v2->m_triangles.m_size = 12;
  v16 = &indices[2];
  v17 = (signed __int64)&v15[1].m_c;
  v18 = 6i64;
  do
  {
    v19 = *(v16 - 2);
    v17 += 32i64;
    v16 += 4;
    v15->m_a = v19;
    v15 += 2;
    *(_DWORD *)(v17 - 52) = *(v16 - 5);
    v20 = *(v16 - 4);
    *(_DWORD *)(v17 - 44) = 0;
    *(_DWORD *)(v17 - 48) = v20;
    *(_DWORD *)(v17 - 40) = *(v16 - 6);
    *(_DWORD *)(v17 - 36) = *(v16 - 4);
    *(_QWORD *)(v17 - 32) = *(v16 - 3);
    --v18;
  }
  while ( v18 );
}

// File Line: 123
// RVA: 0xBE5EA0
void __fastcall hkaiPlaneVolume::transform(hkaiPlaneVolume *this, hkTransformf *trans)
{
  hkVector4f *v2; // rax
  hkaiPlaneVolume *v3; // r10
  hkVector4f v4; // xmm6
  hkVector4f v5; // xmm7
  hkVector4f *v6; // r8
  int v7; // ecx
  hkVector4f v8; // xmm8
  __m128 v9; // xmm4
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm5
  __m128 v13; // xmm4
  __m128 v14; // xmm1
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  hkVector4f v18; // xmm3
  hkVector4f v19; // xmm4
  hkVector4f v20; // xmm5
  hkVector4f v21; // xmm6
  __int64 v22; // rcx
  signed __int64 v23; // rax
  __m128 v24; // xmm1

  v2 = this->m_planes.m_data;
  v3 = this;
  v4.m_quad = (__m128)trans->m_rotation.m_col2;
  v5.m_quad = (__m128)trans->m_rotation.m_col0;
  v6 = this->m_planes.m_data;
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
    v13 = v6->m_quad;
    ++v2;
    ++v6;
    --v7;
    v14 = _mm_mul_ps(v13, v12);
    v15 = _mm_shuffle_ps(v14, _mm_unpackhi_ps(v14, v13), 196);
    v16 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 78), v15);
    v17 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), v8.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v5.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v4.m_quad));
    v2[-1].m_quad = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, _mm_add_ps(_mm_shuffle_ps(v16, v16, 177), v16)), 196);
  }
  while ( v7 >= 0 );
  v18.m_quad = (__m128)trans->m_rotation.m_col0;
  v19.m_quad = (__m128)trans->m_rotation.m_col1;
  v20.m_quad = (__m128)trans->m_rotation.m_col2;
  v21.m_quad = (__m128)trans->m_translation;
  v22 = v3->m_geometry.m_vertices.m_size - 1;
  v23 = (signed __int64)&v3->m_geometry.m_vertices.m_data[v22];
  do
  {
    v24 = *(__m128 *)v23;
    v23 -= 16i64;
    --v22;
    *(__m128 *)(v23 + 16) = _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v19.m_quad),
                                  _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v18.m_quad)),
                                _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v20.m_quad)),
                              v21.m_quad);
  }
  while ( v22 >= 0 );
  hkaiPlaneVolume::updateInternalInfo(v3);
}

// File Line: 135
// RVA: 0xBE6700
signed __int64 __fastcall hkaiPlaneVolume::contains(hkaiPlaneVolume *this, hkVector4f *point)
{
  __m128 v2; // xmm3
  __int64 v4; // rdx
  __int64 v5; // rax
  hkVector4f *v6; // rcx
  __m128 v7; // xmm2
  __m128 v8; // xmm2
  __m128 v9; // xmm1

  v2 = point->m_quad;
  if ( (_mm_movemask_ps(
          _mm_and_ps(
            _mm_cmpleps(point->m_quad, this->m_aabb.m_max.m_quad),
            _mm_cmpleps(this->m_aabb.m_min.m_quad, point->m_quad))) & 7) != 7 )
    return 0i64;
  v4 = this->m_planes.m_size;
  v5 = 0i64;
  if ( v4 > 0 )
  {
    v6 = this->m_planes.m_data;
    while ( 1 )
    {
      v7 = _mm_mul_ps(v6->m_quad, v2);
      v8 = _mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, v6->m_quad), 196);
      v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 78), v8);
      if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 177)) + v9.m128_f32[0]) > 0.0 )
        break;
      ++v5;
      ++v6;
      if ( v5 >= v4 )
        return 1i64;
    }
    return 0i64;
  }
  return 1i64;
}

// File Line: 155
// RVA: 0xBE5790
void __fastcall hkaiPlaneVolume::calcPointsInside(hkaiPlaneVolume *this, hkVector4f *points, int numPoints, hkBitField *pointsInside)
{
  hkBitField *v4; // r15
  __int64 v5; // rdi
  hkVector4f *v6; // rsi
  hkaiPlaneVolume *v7; // r14
  signed int v8; // ebx
  __int64 v9; // rbp

  if ( numPoints > 0 )
  {
    v4 = pointsInside;
    v5 = 0i64;
    v6 = points;
    v7 = this;
    v8 = 1;
    v9 = (unsigned int)numPoints;
    do
    {
      if ( (v7->m_isInverted.m_bool != 0) ^ (hkaiPlaneVolume::contains(v7, v6) != 0) )
        v4->m_storage.m_words.m_data[v5 >> 5] |= v8;
      v8 = __ROL4__(v8, 1);
      ++v5;
      ++v6;
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 169
// RVA: 0xBE5A30
_BOOL8 __fastcall hkaiPlaneVolume::containsTriangle(hkaiPlaneVolume *this, hkVector4f *a, hkVector4f *b, hkVector4f *c)
{
  hkVector4f *v4; // rdi
  hkVector4f *v5; // rsi
  hkaiPlaneVolume *v6; // rbx
  __m128 v7; // xmm5
  __m128 v8; // xmm6
  __int64 v10; // r8
  __int64 v11; // rax
  hkVector4f *v12; // rdx
  __m128 v13; // xmm1
  __m128 v14; // xmm1
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm1
  __m128 v21; // xmm3

  v4 = c;
  v5 = b;
  v6 = this;
  if ( !this->m_isInverted.m_bool )
    return hkaiPlaneVolume::contains(this, a) && hkaiPlaneVolume::contains(v6, v5) && hkaiPlaneVolume::contains(v6, v4);
  v7 = a->m_quad;
  v8 = b->m_quad;
  if ( (_mm_movemask_ps(
          _mm_and_ps(
            _mm_cmpleps(_mm_min_ps(_mm_min_ps(v7, b->m_quad), c->m_quad), this->m_aabb.m_max.m_quad),
            _mm_cmpleps(this->m_aabb.m_min.m_quad, _mm_max_ps(_mm_max_ps(v7, b->m_quad), c->m_quad)))) & 7) != 7 )
    return 1i64;
  v10 = this->m_planes.m_size;
  v11 = 0i64;
  if ( v10 <= 0 )
    return 0i64;
  v12 = this->m_planes.m_data;
  while ( 1 )
  {
    v13 = _mm_mul_ps(v12->m_quad, v7);
    v14 = _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, v12->m_quad), 196);
    v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 78), v14);
    v16 = _mm_mul_ps(v12->m_quad, v8);
    v17 = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, v12->m_quad), 196);
    v18 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 78), v17);
    v19 = _mm_mul_ps(v12->m_quad, c->m_quad);
    v20 = _mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, v12->m_quad), 196);
    v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 78), v20);
    if ( _mm_movemask_ps(
           _mm_and_ps(
             _mm_and_ps(
               _mm_cmpltps((__m128)0i64, _mm_add_ps(_mm_shuffle_ps(v18, v18, 177), v18)),
               _mm_cmpltps((__m128)0i64, _mm_add_ps(_mm_shuffle_ps(v15, v15, 177), v15))),
             _mm_cmpltps((__m128)0i64, _mm_add_ps(_mm_shuffle_ps(v21, v21, 177), v21)))) )
    {
      break;
    }
    ++v11;
    ++v12;
    if ( v11 >= v10 )
      return 0i64;
  }
  return 1i64;
}

// File Line: 207
// RVA: 0xBE5BF0
signed __int64 __fastcall hkaiPlaneVolume::containsAabb(hkaiPlaneVolume *this, hkAabb *aabbIn)
{
  hkVector4f v2; // xmm5
  hkaiPlaneVolume *v3; // r8
  hkVector4f v4; // xmm6
  unsigned int v5; // edx
  __int64 v7; // r9
  __int64 v8; // rax
  char v9; // r10
  hkVector4f *v10; // rcx
  float v11; // xmm4_4
  __m128 v12; // xmm0
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm3

  v2.m_quad = (__m128)aabbIn->m_max;
  v3 = this;
  v4.m_quad = (__m128)aabbIn->m_min;
  v5 = 0;
  if ( (_mm_movemask_ps(
          _mm_and_ps(
            _mm_cmpleps(v4.m_quad, this->m_aabb.m_max.m_quad),
            _mm_cmpleps(this->m_aabb.m_min.m_quad, v2.m_quad))) & 7) != 7 )
  {
    LOBYTE(v5) = this->m_isInverted.m_bool != 0;
    return v5;
  }
  v7 = this->m_planes.m_size;
  v8 = 0i64;
  if ( v7 <= 0 )
  {
LABEL_10:
    LOBYTE(v5) = v3->m_isInverted.m_bool == 0;
    return v5;
  }
  v9 = this->m_isInverted.m_bool;
  v10 = this->m_planes.m_data;
  while ( 1 )
  {
    LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(v10->m_quad, v10->m_quad, 255);
    v12 = _mm_mul_ps(v10->m_quad, v2.m_quad);
    v13 = _mm_mul_ps(v10->m_quad, v4.m_quad);
    v14 = _mm_max_ps(v13, v12);
    v15 = _mm_min_ps(v13, v12);
    if ( !v9 )
      break;
    if ( (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 0)))
                       + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 170)))
               + v11) >= 0.0 )
      return 1i64;
LABEL_9:
    ++v8;
    ++v10;
    if ( v8 >= v7 )
      goto LABEL_10;
  }
  if ( (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 170)))
             + v11) < 0.0 )
    goto LABEL_9;
  return 0i64;
}

// File Line: 245
// RVA: 0xBE5820
hkResult *__fastcall hkaiPlaneVolume::calcGeometry(hkaiPlaneVolume *this, hkResult *result, hkGeometry *geom)
{
  int v3; // er9
  hkGeometry *v4; // rbp
  hkResult *v5; // rsi
  hkaiPlaneVolume *v6; // rdi
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
    aabbOut->m_min = this->m_aabb.m_min;
    aabbOut->m_max = this->m_aabb.m_max;
  }
}

// File Line: 266
// RVA: 0xBE6030
hkaiPlaneVolume *__fastcall hkaiPlaneVolume::clone(hkaiPlaneVolume *this, hkTransformf *t)
{
  hkaiPlaneVolume *v2; // rdi
  hkTransformf *v3; // rsi
  _QWORD **v4; // rax
  hkaiPlaneVolume *v5; // rax
  hkaiPlaneVolume *v6; // rax
  hkaiPlaneVolume *v7; // rbx
  __int64 v8; // rcx
  hkVector4f *v9; // rax
  __int64 v10; // rdx
  char *v11; // r8
  hkVector4f v12; // xmm0
  hkResult result; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = t;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkaiPlaneVolume *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 128i64);
  if ( v5 )
  {
    hkaiPlaneVolume::hkaiPlaneVolume(v5);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  hkGeometry::appendGeometry(&v7->m_geometry, &result, &v2->m_geometry, 0i64);
  if ( (v7->m_planes.m_capacityAndFlags & 0x3FFFFFFF) < v2->m_planes.m_size )
  {
    if ( v7->m_planes.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v7->m_planes.m_data,
        16 * v7->m_planes.m_capacityAndFlags);
    result.m_enum = 16 * v2->m_planes.m_size;
    v7->m_planes.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                          (int *)&result);
    v7->m_planes.m_capacityAndFlags = result.m_enum / 16;
  }
  v8 = v2->m_planes.m_size;
  v9 = v7->m_planes.m_data;
  v7->m_planes.m_size = v8;
  v10 = v8;
  if ( (signed int)v8 > 0 )
  {
    v11 = (char *)((char *)v2->m_planes.m_data - (char *)v9);
    do
    {
      v12.m_quad = *(__m128 *)((char *)v9 + (_QWORD)v11);
      ++v9;
      v9[-1] = (hkVector4f)v12.m_quad;
      --v10;
    }
    while ( v10 );
  }
  v7->m_isInverted.m_bool = v2->m_isInverted.m_bool;
  hkaiPlaneVolume::transform(v7, v3);
  return v7;
}

// File Line: 278
// RVA: 0xBE6300
void __fastcall hkaiPlaneVolume::createExtruded2DConvexHullVolume(hkVector4f *inputVerts, int numVerts, hkVector4f *up, hkSimdFloat32 *_cutoffHeight)
{
  hkSimdFloat32 *v4; // r15
  hkVector4f *v5; // r14
  __int64 v6; // rsi
  hkVector4f *v7; // rbx
  int v8; // er9
  __m128 v9; // xmm8
  __m128 v10; // xmm6
  __int64 v11; // rdi
  __m128 v12; // xmm7
  __m128 v13; // xmm9
  __m128 v14; // xmm5
  __m128 v15; // xmm9
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  hkVector4f v19; // xmm9
  hkVector4f *v20; // rax
  __int64 v21; // rcx
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __int32 v24; // ecx
  hkVector4f *v25; // r8
  unsigned int v26; // eax
  int v27; // ecx
  int v28; // er9
  __m128 v29; // xmm8
  int v30; // ecx
  float v31; // xmm8_4
  __m128 v32; // xmm2
  hkVector4f v33; // xmm0
  __m128 v34; // xmm6
  __m128 v35; // xmm7
  __int64 v36; // rdi
  int v37; // ebx
  int v38; // er9
  __int64 v39; // r8
  __int64 v40; // rdx
  __m128 v41; // xmm4
  __m128 v42; // xmm1
  __m128 v43; // xmm0
  __m128 v44; // xmm4
  hkVector4f *v45; // [rsp+8h] [rbp-79h]
  int v46; // [rsp+10h] [rbp-71h]
  int v47; // [rsp+14h] [rbp-6Dh]
  hkVector4f *array; // [rsp+18h] [rbp-69h]
  int sizeElem; // [rsp+20h] [rbp-61h]
  int v50; // [rsp+24h] [rbp-5Dh]
  hkaiConvex2dUtils::Convex2DHullInput input; // [rsp+28h] [rbp-59h]
  hkResult result; // [rsp+E0h] [rbp+5Fh]
  hkaiPlaneVolume *v53; // [rsp+100h] [rbp+7Fh]

  v4 = _cutoffHeight;
  v5 = up;
  v6 = numVerts;
  array = 0i64;
  sizeElem = 0;
  v7 = inputVerts;
  v50 = 2147483648;
  if ( numVerts > 0 )
  {
    v8 = numVerts;
    if ( numVerts < 0 )
      v8 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v8, 16);
  }
  v9 = v5->m_quad;
  v10 = (__m128)xmmword_141A712A0;
  sizeElem = v6;
  v11 = v6;
  v12 = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A712A0);
  v13 = _mm_shuffle_ps(v9, _mm_unpackhi_ps(v9, (__m128)0i64), 196);
  v14 = _mm_shuffle_ps(v13, v13, 241);
  v15 = _mm_shuffle_ps(v13, v13, 206);
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_mul_ps(v14, v14);
  v18 = _mm_cmpltps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
            _mm_shuffle_ps(v17, v17, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
            _mm_shuffle_ps(v16, v16, 170)));
  v19.m_quad = _mm_xor_ps(
                 _mm_or_ps(_mm_and_ps(v15, v18), _mm_andnot_ps(v18, v14)),
                 (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
  if ( (signed int)v6 > 0 )
  {
    v20 = v7;
    v21 = v6;
    do
    {
      ++v20;
      v22 = _mm_mul_ps(v9, v20[-1].m_quad);
      v23 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
              _mm_shuffle_ps(v22, v22, 170));
      v10 = _mm_min_ps(v10, v23);
      v12 = _mm_max_ps(v12, v23);
      --v21;
    }
    while ( v21 );
  }
  v24 = v6;
  v45 = 0i64;
  v46 = 0;
  v47 = 2147483648;
  if ( (_DWORD)v6 )
  {
    result.m_enum = 16 * v6;
    v25 = (hkVector4f *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                          (int *)&result);
    v24 = result.m_enum / 16;
  }
  else
  {
    v25 = 0i64;
  }
  v26 = 2147483648;
  v45 = v25;
  if ( v24 )
    v26 = v24;
  v46 = v6;
  v47 = v26;
  v27 = v26 & 0x3FFFFFFF;
  if ( (v26 & 0x3FFFFFFF & 0x80000000) != 0 )
  {
    v28 = 0;
    if ( 2 * v27 > 0 )
      v28 = 2 * v27;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v45, v28, 16);
    v26 = v47;
  }
  v29 = v4->m_real;
  v30 = 0;
  v46 = 0;
  v31 = v29.m128_f32[0] + v10.m128_f32[0];
  if ( (signed int)v6 > 0 )
  {
    do
    {
      v32 = _mm_mul_ps(v5->m_quad, v7->m_quad);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 170))) < v31 )
      {
        if ( v30 == (v26 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v45, 16);
          v30 = v46;
        }
        v45[v30] = (hkVector4f)v7->m_quad;
        v26 = v47;
        v30 = v46++ + 1;
      }
      ++v7;
      --v11;
    }
    while ( v11 );
  }
  v33.m_quad = v5->m_quad;
  v34 = _mm_sub_ps(v10, query.m_quad);
  v35 = _mm_add_ps(v12, query.m_quad);
  input.m_numVerts = v30;
  input.m_referenceAxis = (hkVector4f)v19.m_quad;
  input.m_up = (hkVector4f)v33.m_quad;
  input.m_transform = &hkQTransformfIdentity_storage;
  input.m_verts = v45;
  hkaiConvex2dUtils::createConvexHullSilhouette(&input, (hkArrayBase<hkVector4f> *)&array);
  v36 = sizeElem;
  v37 = 2 * sizeElem;
  if ( (v50 & 0x3FFFFFFF) < 2 * sizeElem )
  {
    v38 = 2 * sizeElem;
    if ( v37 < 2 * (v50 & 0x3FFFFFFF) )
      v38 = 2 * (v50 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v38, 16);
  }
  sizeElem = v37;
  v39 = v36;
  if ( (signed int)v36 > 0 )
  {
    v40 = 0i64;
    do
    {
      ++v40;
      v41 = array[v40 - 1].m_quad;
      v42 = _mm_mul_ps(v5->m_quad, v41);
      v43 = _mm_mul_ps(v5->m_quad, v34);
      v44 = _mm_sub_ps(
              v41,
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)),
                  _mm_shuffle_ps(v42, v42, 170)),
                v5->m_quad));
      array[v40 - 1].m_quad = _mm_add_ps(_mm_mul_ps(v5->m_quad, v35), v44);
      array[v36 - 1 + v40].m_quad = _mm_add_ps(v44, v43);
      --v39;
    }
    while ( v39 );
    v37 = sizeElem;
  }
  hkaiPlaneVolume::createConvexVolume(array, v37, v53);
  v46 = 0;
  if ( v47 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v45,
      16 * v47);
  v45 = 0i64;
  v47 = 2147483648;
  sizeElem = 0;
  if ( v50 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      16 * v50);
}

// File Line: 343
// RVA: 0xBE6790
void __fastcall hkaiPlaneVolume::updateInternalInfo(hkaiPlaneVolume *this)
{
  hkAabbUtil::calcAabb(this->m_geometry.m_vertices.m_data, this->m_geometry.m_vertices.m_size, &this->m_aabb);
}


// File Line: 26
// RVA: 0xE7E030
void __fastcall hkDisplaySemiCircle::hkDisplaySemiCircle(hkDisplaySemiCircle *this, hkVector4f *center, hkVector4f *normal, hkVector4f *startPerp, const float thetaMin, const float thetaMax, const float radius, const int numSegments)
{
  __m128 v8; // xmm0

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = 5;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable';
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplaySemiCircle::`vftable';
  this->m_normal = (hkVector4f)normal->m_quad;
  this->m_perp = (hkVector4f)startPerp->m_quad;
  v8 = center->m_quad;
  this->m_thetaMin = thetaMin;
  this->m_numSegments = numSegments;
  this->m_center.m_quad = v8;
  this->m_thetaMax = thetaMax;
  this->m_radius = radius;
}

// File Line: 35
// RVA: 0xE7E0E0
void __fastcall hkDisplaySemiCircle::hkDisplaySemiCircle(hkDisplaySemiCircle *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type = 5;
  this->m_geometry = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable';
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->m_normal = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplaySemiCircle::`vftable';
  *(_QWORD *)&this->m_thetaMin = 0i64;
  *(_QWORD *)&this->m_radius = 0i64;
  this->m_center = 0i64;
  this->m_perp = 0i64;
}

// File Line: 42
// RVA: 0xE7E4A0
void __fastcall hkDisplaySemiCircle::generatePoints(hkDisplaySemiCircle *this, hkArray<hkVector4f,hkContainerHeapAllocator> *points)
{
  float v2; // xmm2_4
  hkArray<hkVector4f,hkContainerHeapAllocator> *v3; // r14
  hkVector4f *v4; // rdi
  float v5; // xmm6_4
  int v6; // ebx
  signed __int64 v7; // rsi
  int v8; // eax
  int v9; // eax
  int v10; // er9
  __m128 *v11; // rax
  __m128 v12; // xmm0
  int v13; // ebx
  __m128 v14; // xmm0
  hkVector4f *v15; // rax
  __m128 v16; // xmm0
  hkVector4f b; // [rsp+30h] [rbp-68h]
  hkVector4f v18; // [rsp+40h] [rbp-58h]
  hkMatrix3f a; // [rsp+50h] [rbp-48h]
  hkResult result; // [rsp+A0h] [rbp+8h]

  v2 = this->m_thetaMin;
  v3 = points;
  v4 = (hkVector4f *)this;
  v5 = (float)(this->m_thetaMax - v2) / (float)this->m_numSegments;
  hkRotationf::setAxisAngle((hkRotationf *)&a, &this->m_normal, v2);
  b.m_quad = _mm_mul_ps(
               _mm_shuffle_ps((__m128)v4[10].m_quad.m128_u32[2], (__m128)v4[10].m_quad.m128_u32[2], 0),
               v4[8].m_quad);
  hkVector4f::setRotatedDir(&b, &a, &b);
  b.m_quad = _mm_add_ps(b.m_quad, v4[9].m_quad);
  hkRotationf::setAxisAngle((hkRotationf *)&a, v4 + 7, v5);
  v6 = v4[10].m_quad.m128_i32[3] + 2;
  v7 = 1i64;
  v8 = v3->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v6 )
  {
    v9 = 2 * v8;
    v10 = v4[10].m_quad.m128_i32[3] + 2;
    if ( v6 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v10, 16);
  }
  v11 = &v3->m_data->m_quad;
  v12 = b.m_quad;
  v3->m_size = v6;
  v13 = 0;
  *v11 = v12;
  if ( v4[10].m_quad.m128_i32[3] >= 0 )
  {
    v14 = b.m_quad;
    do
    {
      v18.m_quad = _mm_sub_ps(v14, v4[9].m_quad);
      hkVector4f::setRotatedDir(&v18, &a, &v18);
      v15 = v3->m_data;
      ++v13;
      ++v7;
      v16 = _mm_add_ps(v18.m_quad, v4[9].m_quad);
      v18.m_quad = v16;
      v15[v7 - 1] = (hkVector4f)v16;
      v14 = v18.m_quad;
      b.m_quad = v18.m_quad;
    }
    while ( v13 <= v4[10].m_quad.m128_i32[3] );
  }
}

// File Line: 75
// RVA: 0xE7E160
void __fastcall hkDisplaySemiCircle::buildGeometry(hkDisplaySemiCircle *this)
{
  hkDisplaySemiCircle *v1; // rdi
  _QWORD **v2; // rax
  hkArray<hkVector4f,hkContainerHeapAllocator> *v3; // rax
  int v4; // ebx
  hkGeometry *v5; // rsi
  int v6; // er8
  __int64 v7; // rdx
  hkGeometry::Triangle *v8; // rcx

  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkArray<hkVector4f,hkContainerHeapAllocator> *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                                         v2[11],
                                                         48i64);
  v4 = 0;
  if ( v3 )
  {
    v3->m_size = 0x1FFFF;
    v3->m_data = (hkVector4f *)&hkGeometry::`vftable';
    v3[1].m_data = 0i64;
    v3[1].m_size = 0;
    v3[1].m_capacityAndFlags = 2147483648;
    v3[2].m_data = 0i64;
    v3[2].m_size = 0;
    v3[2].m_capacityAndFlags = 2147483648;
  }
  else
  {
    v3 = 0i64;
  }
  v1->m_geometry = (hkGeometry *)v3;
  hkDisplaySemiCircle::generatePoints(v1, v3 + 1);
  v5 = v1->m_geometry;
  if ( v5->m_vertices.m_size == (v5->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v5->m_vertices, 16);
  v5->m_vertices.m_data[v5->m_vertices.m_size++] = v1->m_center;
  v6 = v1->m_geometry->m_vertices.m_size - 1;
  if ( v1->m_numSegments > 0 )
  {
    v7 = 0i64;
    do
    {
      ++v7;
      v8 = v1->m_geometry->m_triangles.m_data;
      *((_DWORD *)&v8[v7] - 2) = v4;
      v8[v7 - 1].m_a = v6;
      *((_DWORD *)&v8[v7] - 3) = v4 + 1;
      *((_DWORD *)&v8[v7] - 1) = -1;
      ++v4;
    }
    while ( v4 < v1->m_numSegments );
  }
}

// File Line: 92
// RVA: 0xE7E280
void __fastcall hkDisplaySemiCircle::getWireframeGeometry(hkDisplaySemiCircle *this, hkArrayBase<hkVector4f> *lines, hkMemoryAllocator *a)
{
  hkArrayBase<hkVector4f> *v3; // rbx
  hkMemoryAllocator *v4; // rbp
  hkDisplaySemiCircle *v5; // rdi
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // er9
  int v10; // er9
  __int64 v11; // rdx
  __int64 v12; // r8
  char *v13; // [rsp+30h] [rbp-18h]
  int v14; // [rsp+38h] [rbp-10h]
  int v15; // [rsp+3Ch] [rbp-Ch]
  hkResult result; // [rsp+50h] [rbp+8h]

  v3 = lines;
  v4 = a;
  v5 = this;
  v13 = 0i64;
  v14 = 0;
  v15 = 2147483648;
  hkDisplaySemiCircle::generatePoints(this, (hkArray<hkVector4f,hkContainerHeapAllocator> *)&v13);
  v6 = 2 * v5->m_numSegments;
  v7 = v3->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v6 )
  {
    v8 = 2 * v7;
    v9 = 2 * v5->m_numSegments;
    if ( v6 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, v4, v3, v9, 16);
  }
  v10 = 0;
  v3->m_size = v6;
  if ( v5->m_numSegments > 0 )
  {
    v11 = 0i64;
    v12 = 0i64;
    do
    {
      ++v10;
      v11 += 2i64;
      v12 += 16i64;
      v3->m_data[v11 - 2] = *(hkVector4f *)&v13[v12 - 16];
      v3->m_data[v11 - 1] = *(hkVector4f *)&v13[v12];
    }
    while ( v10 < v5->m_numSegments );
  }
  v14 = 0;
  if ( v15 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v13,
      16 * v15);
}

// File Line: 115
// RVA: 0xE7E3A0
void __fastcall hkDisplaySemiCircle::setParameters(hkDisplaySemiCircle *this, const float radius, const float thetaMin, const float thetaMax, const int numSegments, hkVector4f *center, hkVector4f *normal, hkVector4f *startPerp)
{
  __m128 v8; // xmm0

  this->m_center = (hkVector4f)center->m_quad;
  this->m_normal = (hkVector4f)normal->m_quad;
  v8 = startPerp->m_quad;
  this->m_thetaMin = thetaMin;
  this->m_thetaMax = thetaMax;
  this->m_numSegments = numSegments;
  this->m_perp.m_quad = v8;
  this->m_radius = radius;
}

// File Line: 126
// RVA: 0xE7E400
hkVector4f *__fastcall hkDisplaySemiCircle::getNormal(hkDisplaySemiCircle *this, hkVector4f *result)
{
  hkVector4f *v2; // rax

  v2 = result;
  _mm_store_si128((__m128i *)result, (__m128i)this->m_normal.m_quad);
  return v2;
}

// File Line: 131
// RVA: 0xE7E440
hkVector4f *__fastcall hkDisplaySemiCircle::getPerp(hkDisplaySemiCircle *this, hkVector4f *result)
{
  hkVector4f *v2; // rax

  v2 = result;
  _mm_store_si128((__m128i *)result, (__m128i)this->m_perp.m_quad);
  return v2;
}

// File Line: 136
// RVA: 0xE7E460
float __fastcall hkDisplaySemiCircle::getThetaMin(hkDisplaySemiCircle *this)
{
  return this->m_thetaMin;
}

// File Line: 141
// RVA: 0xE7E470
float __fastcall hkDisplaySemiCircle::getThetaMax(hkDisplaySemiCircle *this)
{
  return this->m_thetaMax;
}

// File Line: 146
// RVA: 0xE7E480
float __fastcall hkDisplaySemiCircle::getRadius(hkDisplaySemiCircle *this)
{
  return this->m_radius;
}

// File Line: 151
// RVA: 0xE7E490
__int64 __fastcall hkDisplaySemiCircle::getNumSegments(hkDisplaySemiCircle *this)
{
  return (unsigned int)this->m_numSegments;
}

// File Line: 157
// RVA: 0xE7E420
hkVector4f *__fastcall hkDisplaySemiCircle::getCenter(hkDisplaySemiCircle *this, hkVector4f *result)
{
  hkVector4f *v2; // rax

  v2 = result;
  _mm_store_si128((__m128i *)result, (__m128i)this->m_center.m_quad);
  return v2;
}


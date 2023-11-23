// File Line: 26
// RVA: 0xE7E030
void __fastcall hkDisplaySemiCircle::hkDisplaySemiCircle(
        hkDisplaySemiCircle *this,
        hkVector4f *center,
        hkVector4f *normal,
        hkVector4f *startPerp,
        float thetaMin,
        float thetaMax,
        float radius,
        int numSegments)
{
  __m128 m_quad; // xmm0

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = HK_DISPLAY_SEMICIRCLE;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplaySemiCircle::`vftable;
  this->m_normal = (hkVector4f)normal->m_quad;
  this->m_perp = (hkVector4f)startPerp->m_quad;
  m_quad = center->m_quad;
  this->m_thetaMin = thetaMin;
  this->m_numSegments = numSegments;
  this->m_center.m_quad = m_quad;
  this->m_thetaMax = thetaMax;
  this->m_radius = radius;
}

// File Line: 35
// RVA: 0xE7E0E0
void __fastcall hkDisplaySemiCircle::hkDisplaySemiCircle(hkDisplaySemiCircle *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type = HK_DISPLAY_SEMICIRCLE;
  this->m_geometry = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->m_normal = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplaySemiCircle::`vftable;
  *(_QWORD *)&this->m_thetaMin = 0i64;
  *(_QWORD *)&this->m_radius = 0i64;
  this->m_center = 0i64;
  this->m_perp = 0i64;
}

// File Line: 42
// RVA: 0xE7E4A0
void __fastcall hkDisplaySemiCircle::generatePoints(
        hkDisplaySemiCircle *this,
        hkArray<hkVector4f,hkContainerHeapAllocator> *points)
{
  float m_thetaMin; // xmm2_4
  float v5; // xmm6_4
  int v6; // ebx
  __int64 v7; // rsi
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  hkVector4f *m_data; // rax
  __m128 m_quad; // xmm0
  int v13; // ebx
  __m128 v14; // xmm0
  hkVector4f *v15; // rax
  hkVector4f b; // [rsp+30h] [rbp-68h] BYREF
  hkVector4f v17; // [rsp+40h] [rbp-58h] BYREF
  hkMatrix3f a; // [rsp+50h] [rbp-48h] BYREF
  hkResult result; // [rsp+A0h] [rbp+8h] BYREF

  m_thetaMin = this->m_thetaMin;
  v5 = (float)(this->m_thetaMax - m_thetaMin) / (float)this->m_numSegments;
  hkRotationf::setAxisAngle((hkRotationf *)&a, &this->m_normal, m_thetaMin);
  b.m_quad = _mm_mul_ps(
               _mm_shuffle_ps((__m128)LODWORD(this->m_radius), (__m128)LODWORD(this->m_radius), 0),
               this->m_perp.m_quad);
  hkVector4f::setRotatedDir(&b, &a, &b);
  b.m_quad = _mm_add_ps(b.m_quad, this->m_center.m_quad);
  hkRotationf::setAxisAngle((hkRotationf *)&a, &this->m_normal, v5);
  v6 = this->m_numSegments + 2;
  v7 = 1i64;
  v8 = points->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v6 )
  {
    v9 = 2 * v8;
    v10 = this->m_numSegments + 2;
    if ( v6 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&points->m_data, v10, 16);
  }
  m_data = points->m_data;
  m_quad = b.m_quad;
  points->m_size = v6;
  v13 = 0;
  *m_data = (hkVector4f)m_quad;
  if ( this->m_numSegments >= 0 )
  {
    v14 = b.m_quad;
    do
    {
      v17.m_quad = _mm_sub_ps(v14, this->m_center.m_quad);
      hkVector4f::setRotatedDir(&v17, &a, &v17);
      v15 = points->m_data;
      ++v13;
      ++v7;
      v17.m_quad = _mm_add_ps(v17.m_quad, this->m_center.m_quad);
      v15[v7 - 1] = (hkVector4f)v17.m_quad;
      v14 = v17.m_quad;
      b.m_quad = v17.m_quad;
    }
    while ( v13 <= this->m_numSegments );
  }
}

// File Line: 75
// RVA: 0xE7E160
void __fastcall hkDisplaySemiCircle::buildGeometry(hkDisplaySemiCircle *this)
{
  _QWORD **Value; // rax
  __int64 v3; // rax
  int v4; // ebx
  hkGeometry *m_geometry; // rsi
  int v6; // r8d
  __int64 v7; // rdx
  hkGeometry::Triangle *m_data; // rcx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  v4 = 0;
  if ( v3 )
  {
    *(_DWORD *)(v3 + 8) = 0x1FFFF;
    *(_QWORD *)v3 = &hkGeometry::`vftable;
    *(_QWORD *)(v3 + 16) = 0i64;
    *(_DWORD *)(v3 + 24) = 0;
    *(_DWORD *)(v3 + 28) = 0x80000000;
    *(_QWORD *)(v3 + 32) = 0i64;
    *(_DWORD *)(v3 + 40) = 0;
    *(_DWORD *)(v3 + 44) = 0x80000000;
  }
  else
  {
    v3 = 0i64;
  }
  this->m_geometry = (hkGeometry *)v3;
  hkDisplaySemiCircle::generatePoints(this, (hkArray<hkVector4f,hkContainerHeapAllocator> *)(v3 + 16));
  m_geometry = this->m_geometry;
  if ( m_geometry->m_vertices.m_size == (m_geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_geometry->m_vertices.m_data, 16);
  m_geometry->m_vertices.m_data[m_geometry->m_vertices.m_size++] = this->m_center;
  v6 = this->m_geometry->m_vertices.m_size - 1;
  if ( this->m_numSegments > 0 )
  {
    v7 = 0i64;
    do
    {
      ++v7;
      m_data = this->m_geometry->m_triangles.m_data;
      m_data[v7 - 1].m_c = v4;
      m_data[v7 - 1].m_a = v6;
      m_data[v7 - 1].m_b = v4 + 1;
      m_data[v7 - 1].m_material = -1;
      ++v4;
    }
    while ( v4 < this->m_numSegments );
  }
}

// File Line: 92
// RVA: 0xE7E280
void __fastcall hkDisplaySemiCircle::getWireframeGeometry(
        hkDisplaySemiCircle *this,
        hkArrayBase<hkVector4f> *lines,
        hkMemoryAllocator *a)
{
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // r9d
  __int64 v11; // rdx
  __int64 v12; // r8
  hkArray<hkVector4f,hkContainerHeapAllocator> v13; // [rsp+30h] [rbp-18h] BYREF
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  v13.m_data = 0i64;
  v13.m_size = 0;
  v13.m_capacityAndFlags = 0x80000000;
  hkDisplaySemiCircle::generatePoints(this, &v13);
  v6 = 2 * this->m_numSegments;
  v7 = lines->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v6 )
  {
    v8 = 2 * v7;
    v9 = 2 * this->m_numSegments;
    if ( v6 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, a, (const void **)&lines->m_data, v9, 16);
  }
  v10 = 0;
  lines->m_size = v6;
  if ( this->m_numSegments > 0 )
  {
    v11 = 0i64;
    v12 = 0i64;
    do
    {
      ++v10;
      v11 += 2i64;
      lines->m_data[v11 - 2] = v13.m_data[v12++];
      lines->m_data[v11 - 1] = v13.m_data[v12];
    }
    while ( v10 < this->m_numSegments );
  }
  v13.m_size = 0;
  if ( v13.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v13.m_data,
      16 * v13.m_capacityAndFlags);
}

// File Line: 115
// RVA: 0xE7E3A0
void __fastcall hkDisplaySemiCircle::setParameters(
        hkDisplaySemiCircle *this,
        float radius,
        float thetaMin,
        float thetaMax,
        int numSegments,
        hkVector4f *center,
        hkVector4f *normal,
        hkVector4f *startPerp)
{
  __m128 m_quad; // xmm0

  this->m_center = (hkVector4f)center->m_quad;
  this->m_normal = (hkVector4f)normal->m_quad;
  m_quad = startPerp->m_quad;
  this->m_thetaMin = thetaMin;
  this->m_thetaMax = thetaMax;
  this->m_numSegments = numSegments;
  this->m_perp.m_quad = m_quad;
  this->m_radius = radius;
}

// File Line: 126
// RVA: 0xE7E400
hkVector4f *__fastcall hkDisplaySemiCircle::getNormal(hkDisplaySemiCircle *this, hkVector4f *result)
{
  hkVector4f *v2; // rax

  v2 = result;
  *result = this->m_normal;
  return v2;
}

// File Line: 131
// RVA: 0xE7E440
hkVector4f *__fastcall hkDisplaySemiCircle::getPerp(hkDisplaySemiCircle *this, hkVector4f *result)
{
  hkVector4f *v2; // rax

  v2 = result;
  *result = this->m_perp;
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
  *result = this->m_center;
  return v2;
}


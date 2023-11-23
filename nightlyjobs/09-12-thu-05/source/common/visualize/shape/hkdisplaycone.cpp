// File Line: 21
// RVA: 0xE7D960
void __fastcall hkDisplayCone::hkDisplayCone(
        hkDisplayCone *this,
        float coneAngle,
        float coneHeight,
        int numSegments,
        hkVector4f *coneAxis,
        hkVector4f *startPos)
{
  __m128 m_quad; // xmm0

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = HK_DISPLAY_CONE;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayCone::`vftable;
  this->m_startPos = (hkVector4f)startPos->m_quad;
  m_quad = coneAxis->m_quad;
  this->m_coneAngle = coneAngle;
  this->m_coneHeight = coneHeight;
  this->m_numSegments = numSegments;
  this->m_coneAxis.m_quad = m_quad;
}

// File Line: 30
// RVA: 0xE7DA00
void __fastcall hkDisplayCone::hkDisplayCone(hkDisplayCone *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type = HK_DISPLAY_CONE;
  this->m_geometry = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->m_startPos = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayCone::`vftable;
  *(_QWORD *)&this->m_numSegments = 0i64;
  this->m_coneHeight = 0.0;
  this->m_coneAxis = 0i64;
}

// File Line: 42
// RVA: 0xE7DA80
void __fastcall hkDisplayCone::setParameters(
        hkDisplayCone *this,
        float coneAngle,
        float coneHeight,
        int numSegments,
        hkVector4f *coneAxis,
        hkVector4f *startPos)
{
  __m128 m_quad; // xmm1

  this->m_coneAngle = coneAngle;
  this->m_startPos = (hkVector4f)startPos->m_quad;
  m_quad = coneAxis->m_quad;
  this->m_coneHeight = coneHeight;
  this->m_numSegments = numSegments;
  this->m_coneAxis.m_quad = m_quad;
}

// File Line: 52
// RVA: 0xE7DE30
void __fastcall hkDisplayCone::generateConeVertices(
        hkDisplayCone *this,
        hkArray<hkVector4f,hkContainerHeapAllocator> *conePoints)
{
  int m_numSegments; // ebx
  int v3; // eax
  int v6; // eax
  int v7; // r9d
  __m128 v8; // xmm7
  __m128 v9; // xmm5
  __m128 v10; // xmm7
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm2
  __m128 v14; // xmm7
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  int v20; // esi
  __int64 v21; // rbx
  hkVector4f direction; // [rsp+30h] [rbp-68h] BYREF
  hkVector4f axis; // [rsp+40h] [rbp-58h] BYREF
  hkQuaternionf quat; // [rsp+50h] [rbp-48h] BYREF
  hkQuaternionf v25; // [rsp+60h] [rbp-38h] BYREF
  hkResult v26; // [rsp+A0h] [rbp+8h] BYREF

  m_numSegments = this->m_numSegments;
  v3 = conePoints->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v3 < m_numSegments )
  {
    v6 = 2 * v3;
    v7 = this->m_numSegments;
    if ( m_numSegments < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(&v26, &hkContainerHeapAllocator::s_alloc, (const void **)&conePoints->m_data, v7, 16);
  }
  conePoints->m_size = m_numSegments;
  v8 = _mm_shuffle_ps(this->m_coneAxis.m_quad, _mm_unpackhi_ps(this->m_coneAxis.m_quad, (__m128)0i64), 196);
  v9 = _mm_shuffle_ps(v8, v8, 241);
  v10 = _mm_shuffle_ps(v8, v8, 206);
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_mul_ps(v9, v9);
  v13 = _mm_cmplt_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
            _mm_shuffle_ps(v12, v12, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170)));
  v14 = _mm_xor_ps(
          _mm_or_ps(_mm_and_ps(v10, v13), _mm_andnot_ps(v13, v9)),
          (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rsqrt_ps(v16);
  v18 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17));
  v19 = _mm_mul_ps(*(__m128 *)_xmm, v17);
  v17.m128_i32[0] = LODWORD(this->m_coneAngle);
  axis.m_quad = _mm_mul_ps(v14, _mm_andnot_ps(_mm_cmple_ps(v16, (__m128)0i64), _mm_mul_ps(v18, v19)));
  hkQuaternionf::setAxisAngle(&quat, &axis, v17.m128_f32[0]);
  hkQuaternionf::setAxisAngle(&v25, &this->m_coneAxis, 6.2831855 / (float)this->m_numSegments);
  hkVector4f::setRotatedDir(&direction, &quat, &this->m_coneAxis);
  v20 = 0;
  if ( this->m_numSegments > 0 )
  {
    v21 = 0i64;
    do
    {
      conePoints->m_data[v21] = this->m_startPos;
      conePoints->m_data[v21].m_quad = _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(
                                             (__m128)LODWORD(this->m_coneHeight),
                                             (__m128)LODWORD(this->m_coneHeight),
                                             0),
                                           direction.m_quad),
                                         conePoints->m_data[v21].m_quad);
      hkVector4f::setRotatedDir(&direction, &v25, &direction);
      ++v20;
      ++v21;
    }
    while ( v20 < this->m_numSegments );
  }
}

// File Line: 84
// RVA: 0xE7DAC0
void __fastcall hkDisplayCone::buildGeometry(hkDisplayCone *this)
{
  _QWORD **Value; // rax
  __int64 v3; // rax
  hkGeometry *m_geometry; // rsi
  hkGeometry *v5; // rsi
  int m_numSegments; // ebp
  int v7; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // edx
  __int64 v11; // r8
  hkGeometry::Triangle *m_data; // rcx
  hkGeometry::Triangle *v13; // rcx
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
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
  hkDisplayCone::generateConeVertices(this, (hkArray<hkVector4f,hkContainerHeapAllocator> *)(v3 + 16));
  m_geometry = this->m_geometry;
  if ( m_geometry->m_vertices.m_size == (m_geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_geometry->m_vertices.m_data, 16);
  m_geometry->m_vertices.m_data[m_geometry->m_vertices.m_size++] = this->m_startPos;
  v5 = this->m_geometry;
  m_numSegments = this->m_numSegments;
  v7 = v5->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < m_numSegments )
  {
    v8 = 2 * v7;
    v9 = this->m_numSegments;
    if ( m_numSegments < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v5->m_triangles.m_data, v9, 16);
  }
  v5->m_triangles.m_size = m_numSegments;
  v10 = 0;
  if ( this->m_numSegments - 1 > 0 )
  {
    v11 = 0i64;
    do
    {
      ++v11;
      m_data = this->m_geometry->m_triangles.m_data;
      m_data[v11 - 1].m_a = this->m_numSegments;
      m_data[v11 - 1].m_c = v10;
      m_data[v11 - 1].m_b = ++v10;
      m_data[v11 - 1].m_material = -1;
    }
    while ( v10 < this->m_numSegments - 1 );
  }
  v13 = &this->m_geometry->m_triangles.m_data[v10];
  *(_QWORD *)&v13->m_a = (unsigned int)this->m_numSegments;
  v13->m_c = v10;
  v13->m_material = -1;
}

// File Line: 104
// RVA: 0xE7DC50
void __fastcall hkDisplayCone::getWireframeGeometry(
        hkDisplayCone *this,
        hkArrayBase<hkVector4f> *lines,
        hkMemoryAllocator *a)
{
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // r10d
  __int64 v11; // r9
  __int64 v12; // r11
  hkArray<hkVector4f,hkContainerHeapAllocator> conePoints; // [rsp+30h] [rbp-18h] BYREF
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  conePoints.m_data = 0i64;
  conePoints.m_size = 0;
  conePoints.m_capacityAndFlags = 0x80000000;
  hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&conePoints.m_data, 256, 16);
  hkDisplayCone::generateConeVertices(this, &conePoints);
  v6 = 4 * this->m_numSegments;
  v7 = lines->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v6 )
  {
    v8 = 2 * v7;
    v9 = 4 * this->m_numSegments;
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
      ++v12;
      v11 += 4i64;
      lines->m_data[v11 - 4] = this->m_startPos;
      lines->m_data[v11 - 3] = conePoints.m_data[v12 - 1];
      lines->m_data[v11 - 2] = conePoints.m_data[v12 - 1];
      lines->m_data[v11 - 1] = conePoints.m_data[v10 % this->m_numSegments];
    }
    while ( v10 < this->m_numSegments );
  }
  conePoints.m_size = 0;
  if ( conePoints.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      conePoints.m_data,
      16 * conePoints.m_capacityAndFlags);
}

// File Line: 126
// RVA: 0xE7DDC0
hkVector4f *__fastcall hkDisplayCone::getPosition(hkDisplayCone *this, hkVector4f *result)
{
  hkVector4f *v2; // rax

  v2 = result;
  *result = this->m_startPos;
  return v2;
}

// File Line: 132
// RVA: 0xE7DDE0
hkVector4f *__fastcall hkDisplayCone::getAxis(hkDisplayCone *this, hkVector4f *result)
{
  hkVector4f *v2; // rax

  v2 = result;
  *result = this->m_coneAxis;
  return v2;
}

// File Line: 137
// RVA: 0xE7DE00
float __fastcall hkDisplayCone::getHeight(hkDisplayCone *this)
{
  return this->m_coneHeight;
}

// File Line: 142
// RVA: 0xE7DE10
float __fastcall hkDisplayCone::getAngle(hkDisplayCone *this)
{
  return this->m_coneAngle;
}

// File Line: 147
// RVA: 0xE7DE20
__int64 __fastcall hkDisplayCone::getNumSegments(hkDisplayCone *this)
{
  return (unsigned int)this->m_numSegments;
}


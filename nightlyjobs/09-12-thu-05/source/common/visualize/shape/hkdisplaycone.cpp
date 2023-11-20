// File Line: 21
// RVA: 0xE7D960
void __fastcall hkDisplayCone::hkDisplayCone(hkDisplayCone *this, const float coneAngle, const float coneHeight, const int numSegments, hkVector4f *coneAxis, hkVector4f *startPos)
{
  __m128 v6; // xmm0

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = 4;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable';
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayCone::`vftable';
  this->m_startPos = (hkVector4f)startPos->m_quad;
  v6 = coneAxis->m_quad;
  this->m_coneAngle = coneAngle;
  this->m_coneHeight = coneHeight;
  this->m_numSegments = numSegments;
  this->m_coneAxis.m_quad = v6;
}

// File Line: 30
// RVA: 0xE7DA00
void __fastcall hkDisplayCone::hkDisplayCone(hkDisplayCone *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type = 4;
  this->m_geometry = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable';
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->m_startPos = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayCone::`vftable';
  *(_QWORD *)&this->m_numSegments = 0i64;
  this->m_coneHeight = 0.0;
  this->m_coneAxis = 0i64;
}

// File Line: 42
// RVA: 0xE7DA80
void __fastcall hkDisplayCone::setParameters(hkDisplayCone *this, const float coneAngle, const float coneHeight, const int numSegments, hkVector4f *coneAxis, hkVector4f *startPos)
{
  __m128 v6; // xmm1

  this->m_coneAngle = coneAngle;
  this->m_startPos = (hkVector4f)startPos->m_quad;
  v6 = coneAxis->m_quad;
  this->m_coneHeight = coneHeight;
  this->m_numSegments = numSegments;
  this->m_coneAxis.m_quad = v6;
}

// File Line: 52
// RVA: 0xE7DE30
void __fastcall hkDisplayCone::generateConeVertices(hkDisplayCone *this, hkArray<hkVector4f,hkContainerHeapAllocator> *conePoints)
{
  int v2; // ebx
  int v3; // eax
  hkArray<hkVector4f,hkContainerHeapAllocator> *v4; // r14
  hkDisplayCone *v5; // rdi
  int v6; // eax
  int v7; // er9
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
  hkVector4f direction; // [rsp+30h] [rbp-68h]
  hkVector4f axis; // [rsp+40h] [rbp-58h]
  hkQuaternionf quat; // [rsp+50h] [rbp-48h]
  hkQuaternionf v25; // [rsp+60h] [rbp-38h]
  __int64 v26; // [rsp+A0h] [rbp+8h]

  v2 = this->m_numSegments;
  v3 = conePoints->m_capacityAndFlags & 0x3FFFFFFF;
  v4 = conePoints;
  v5 = this;
  if ( v3 < v2 )
  {
    v6 = 2 * v3;
    v7 = this->m_numSegments;
    if ( v2 < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(
      (hkResult *)&v26,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      conePoints,
      v7,
      16);
  }
  v4->m_size = v2;
  v8 = _mm_shuffle_ps(v5->m_coneAxis.m_quad, _mm_unpackhi_ps(v5->m_coneAxis.m_quad, (__m128)0i64), 196);
  v9 = _mm_shuffle_ps(v8, v8, 241);
  v10 = _mm_shuffle_ps(v8, v8, 206);
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_mul_ps(v9, v9);
  v13 = _mm_cmpltps(
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
  v17.m128_i32[0] = LODWORD(v5->m_coneAngle);
  axis.m_quad = _mm_mul_ps(v14, _mm_andnot_ps(_mm_cmpleps(v16, (__m128)0i64), _mm_mul_ps(v18, v19)));
  hkQuaternionf::setAxisAngle(&quat, &axis, v17.m128_f32[0]);
  hkQuaternionf::setAxisAngle(&v25, &v5->m_coneAxis, 6.2831855 / (float)v5->m_numSegments);
  hkVector4f::setRotatedDir(&direction, &quat, &v5->m_coneAxis);
  v20 = 0;
  if ( v5->m_numSegments > 0 )
  {
    v21 = 0i64;
    do
    {
      v4->m_data[v21] = v5->m_startPos;
      v4->m_data[v21].m_quad = _mm_add_ps(
                                 _mm_mul_ps(
                                   _mm_shuffle_ps(
                                     (__m128)LODWORD(v5->m_coneHeight),
                                     (__m128)LODWORD(v5->m_coneHeight),
                                     0),
                                   direction.m_quad),
                                 v4->m_data[v21].m_quad);
      hkVector4f::setRotatedDir(&direction, &v25, &direction);
      ++v20;
      ++v21;
    }
    while ( v20 < v5->m_numSegments );
  }
}

// File Line: 84
// RVA: 0xE7DAC0
void __fastcall hkDisplayCone::buildGeometry(hkDisplayCone *this)
{
  hkDisplayCone *v1; // rbx
  _QWORD **v2; // rax
  hkArray<hkVector4f,hkContainerHeapAllocator> *v3; // rax
  hkGeometry *v4; // rsi
  hkGeometry *v5; // rsi
  int v6; // ebp
  int v7; // eax
  int v8; // eax
  int v9; // er9
  int v10; // edx
  __int64 v11; // r8
  hkGeometry::Triangle *v12; // rcx
  signed __int64 v13; // rcx
  hkResult result; // [rsp+40h] [rbp+8h]

  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkArray<hkVector4f,hkContainerHeapAllocator> *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                                         v2[11],
                                                         48i64);
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
  hkDisplayCone::generateConeVertices(v1, v3 + 1);
  v4 = v1->m_geometry;
  if ( v4->m_vertices.m_size == (v4->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_vertices, 16);
  v4->m_vertices.m_data[v4->m_vertices.m_size++] = v1->m_startPos;
  v5 = v1->m_geometry;
  v6 = v1->m_numSegments;
  v7 = v5->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v6 )
  {
    v8 = 2 * v7;
    v9 = v1->m_numSegments;
    if ( v6 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v5->m_triangles,
      v9,
      16);
  }
  v5->m_triangles.m_size = v6;
  v10 = 0;
  if ( v1->m_numSegments - 1 > 0 )
  {
    v11 = 0i64;
    do
    {
      ++v11;
      v12 = v1->m_geometry->m_triangles.m_data;
      v12[v11 - 1].m_a = v1->m_numSegments;
      *((_DWORD *)&v12[v11] - 2) = v10;
      *((_DWORD *)&v12[v11] - 3) = v10++ + 1;
      *((_DWORD *)&v12[v11] - 1) = -1;
    }
    while ( v10 < v1->m_numSegments - 1 );
  }
  v13 = (signed __int64)&v1->m_geometry->m_triangles.m_data[v10];
  *(_QWORD *)v13 = (unsigned int)v1->m_numSegments;
  *(_DWORD *)(v13 + 8) = v10;
  *(_DWORD *)(v13 + 12) = -1;
}

// File Line: 104
// RVA: 0xE7DC50
void __fastcall hkDisplayCone::getWireframeGeometry(hkDisplayCone *this, hkArrayBase<hkVector4f> *lines, hkMemoryAllocator *a)
{
  hkMemoryAllocator *v3; // rbp
  hkArrayBase<hkVector4f> *v4; // rbx
  hkDisplayCone *v5; // rdi
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // er9
  int v10; // er10
  __int64 v11; // r9
  __int64 v12; // r11
  hkArray<hkVector4f,hkContainerHeapAllocator> conePoints; // [rsp+30h] [rbp-18h]
  hkResult result; // [rsp+50h] [rbp+8h]

  v3 = a;
  v4 = lines;
  v5 = this;
  conePoints.m_data = 0i64;
  conePoints.m_size = 0;
  conePoints.m_capacityAndFlags = 2147483648;
  hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &conePoints, 256, 16);
  hkDisplayCone::generateConeVertices(v5, &conePoints);
  v6 = 4 * v5->m_numSegments;
  v7 = v4->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v6 )
  {
    v8 = 2 * v7;
    v9 = 4 * v5->m_numSegments;
    if ( v6 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, v3, v4, v9, 16);
  }
  v10 = 0;
  v4->m_size = v6;
  if ( v5->m_numSegments > 0 )
  {
    v11 = 0i64;
    v12 = 0i64;
    do
    {
      ++v10;
      ++v12;
      v11 += 4i64;
      v4->m_data[v11 - 4] = v5->m_startPos;
      v4->m_data[v11 - 3] = conePoints.m_data[v12 - 1];
      v4->m_data[v11 - 2] = conePoints.m_data[v12 - 1];
      v4->m_data[v11 - 1] = conePoints.m_data[v10 % v5->m_numSegments];
    }
    while ( v10 < v5->m_numSegments );
  }
  conePoints.m_size = 0;
  if ( conePoints.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      conePoints.m_data,
      16 * conePoints.m_capacityAndFlags);
}

// File Line: 126
// RVA: 0xE7DDC0
hkVector4f *__fastcall hkDisplayCone::getPosition(hkDisplayCone *this, hkVector4f *result)
{
  hkVector4f *v2; // rax

  v2 = result;
  _mm_store_si128((__m128i *)result, (__m128i)this->m_startPos.m_quad);
  return v2;
}

// File Line: 132
// RVA: 0xE7DDE0
hkVector4f *__fastcall hkDisplayCone::getAxis(hkDisplayCone *this, hkVector4f *result)
{
  hkVector4f *v2; // rax

  v2 = result;
  _mm_store_si128((__m128i *)result, (__m128i)this->m_coneAxis.m_quad);
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


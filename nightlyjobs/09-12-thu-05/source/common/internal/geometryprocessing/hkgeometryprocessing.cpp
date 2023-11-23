// File Line: 135
// RVA: 0xCB99F0
__int64 __fastcall hkGeometryProcessing::IsoVertex::solveTriangle(
        float *values,
        hkGeometryProcessing::IsoVertex *verticesOut,
        float orientation)
{
  float v3; // xmm3_4
  unsigned int v5; // r8d
  float v6; // xmm8_4
  float v8; // xmm9_4
  float v9; // xmm5_4
  float v10; // xmm4_4
  float v11; // xmm2_4
  __int64 result; // rax
  hkGeometryProcessing::IsoVertex v13; // rcx
  unsigned __int64 v14; // rax
  hkGeometryProcessing::IsoVertex v15; // rcx
  float v16; // xmm6_4
  hkGeometryProcessing::IsoVertex v17; // [rsp+68h] [rbp+20h]
  hkGeometryProcessing::IsoVertex v18; // [rsp+68h] [rbp+20h]
  hkGeometryProcessing::IsoVertex v19; // [rsp+68h] [rbp+20h]
  hkGeometryProcessing::IsoVertex v20; // [rsp+68h] [rbp+20h]

  v3 = *values;
  v5 = 0;
  v6 = values[2];
  v8 = 0.0;
  v9 = 0.0;
  v10 = 0.0;
  if ( v6 != *values && (float)(v3 * v6) <= 0.0 )
  {
    v5 = 4;
    v10 = v6 / (float)(v6 - v3);
    if ( v10 >= 0.0 )
    {
      if ( v10 > 1.0 )
        v10 = *(float *)&FLOAT_1_0;
    }
    else
    {
      v10 = 0.0;
    }
  }
  v11 = values[1];
  if ( v3 != v11 && (float)(v11 * v3) <= 0.0 )
  {
    v5 |= 1u;
    v8 = v3 / (float)(v3 - v11);
    if ( v8 >= 0.0 )
    {
      if ( v8 > 1.0 )
        LODWORD(v8) = (_DWORD)FLOAT_1_0;
    }
    else
    {
      v8 = 0.0;
    }
  }
  if ( v11 != v6 && (float)(v11 * v6) <= 0.0 )
  {
    v5 |= 2u;
    v9 = v11 / (float)(v11 - v6);
    if ( v9 >= 0.0 )
    {
      if ( v9 > 1.0 )
        v9 = *(float *)&FLOAT_1_0;
    }
    else
    {
      v9 = 0.0;
    }
  }
  switch ( v5 )
  {
    case 3u:
      v14 = __PAIR64__(LODWORD(v8), 0);
      v20.m_solution = v9;
      v20.m_edge = 1;
      v15 = v20;
      verticesOut[1] = v20;
      *verticesOut = (hkGeometryProcessing::IsoVertex)__PAIR64__(LODWORD(v8), 0);
      v16 = orientation * values[1];
      break;
    case 5u:
      v19.m_solution = v10;
      v19.m_edge = 2;
      v14 = (unsigned __int64)v19;
      v15 = (hkGeometryProcessing::IsoVertex)__PAIR64__(LODWORD(v8), 0);
      verticesOut[1] = (hkGeometryProcessing::IsoVertex)__PAIR64__(LODWORD(v8), 0);
      *verticesOut = v19;
      v16 = orientation * *values;
      break;
    case 6u:
      v17.m_solution = v9;
      v17.m_edge = 1;
      v13 = v17;
      v18.m_solution = v10;
      v18.m_edge = 2;
      *verticesOut = v13;
      verticesOut[1] = v18;
      result = 6i64;
      if ( (float)(orientation * values[2]) < 0.0 )
      {
        *verticesOut = v18;
        verticesOut[1] = v13;
      }
      return result;
    default:
      return 0i64;
  }
  if ( v16 < 0.0 )
  {
    verticesOut[1] = (hkGeometryProcessing::IsoVertex)v14;
    *verticesOut = v15;
  }
  return v5;
}

// File Line: 176
// RVA: 0xCB9BE0
void __fastcall hkGeometryProcessing::SurfaceSampler::clear(hkGeometryProcessing::SurfaceSampler *this)
{
  this->m_elements.m_size = 0;
  this->m_domain = 0.0;
}

// File Line: 183
// RVA: 0xCB9BF0
void __fastcall hkGeometryProcessing::SurfaceSampler::addGeometry(
        hkGeometryProcessing::SurfaceSampler *this,
        hkGeometry *geometry,
        int baseIndex)
{
  int v4; // r9d
  int v5; // eax
  int v8; // eax
  int v9; // ebx
  __int64 v10; // rbp
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  v4 = geometry->m_triangles.m_size + this->m_elements.m_size;
  v5 = this->m_elements.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < v4 )
  {
    v8 = 2 * v5;
    if ( v4 < v8 )
      v4 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_elements.m_data, v4, 8);
  }
  v9 = 0;
  if ( geometry->m_triangles.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      hkGeometryProcessing::SurfaceSampler::addElement(
        this,
        &geometry->m_vertices.m_data[geometry->m_triangles.m_data[v10].m_a],
        &geometry->m_vertices.m_data[geometry->m_triangles.m_data[v10].m_b],
        &geometry->m_vertices.m_data[geometry->m_triangles.m_data[v10].m_c],
        v9 + baseIndex);
      ++v9;
      ++v10;
    }
    while ( v9 < geometry->m_triangles.m_size );
  }
}

// File Line: 196
// RVA: 0xCB9CB0
void __fastcall hkGeometryProcessing::SurfaceSampler::addElement(
        hkGeometryProcessing::SurfaceSampler *this,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c,
        int index)
{
  hkGeometryProcessing::SurfaceSampler::Element *m_data; // rcx
  __int64 m_size; // rdx
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm1

  if ( this->m_elements.m_size == (this->m_elements.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_elements.m_data, 8);
  m_data = this->m_elements.m_data;
  m_size = this->m_elements.m_size;
  this->m_elements.m_size = m_size + 1;
  m_data[m_size].m_index = index;
  m_data[m_size].m_value = this->m_domain;
  v11 = _mm_sub_ps(b->m_quad, a->m_quad);
  v12 = _mm_sub_ps(c->m_quad, a->m_quad);
  v13 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v11), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v12));
  v14 = _mm_shuffle_ps(v13, v13, 201);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rsqrt_ps(v16);
  this->m_domain = _mm_andnot_ps(
                     _mm_cmple_ps(v16, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                         _mm_mul_ps(*(__m128 *)_xmm, v17)),
                       v16)).m128_f32[0]
                 + this->m_domain;
}

// File Line: 205
// RVA: 0xCB9DB0
__int64 __fastcall hkGeometryProcessing::SurfaceSampler::findElement(
        hkGeometryProcessing::SurfaceSampler *this,
        int index)
{
  __int64 m_size; // r10
  unsigned int v3; // r9d
  __int64 v4; // r8
  int *i; // rax

  m_size = this->m_elements.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
    return 0xFFFFFFFFi64;
  for ( i = &this->m_elements.m_data->m_index; *i != index; i += 2 )
  {
    ++v4;
    ++v3;
    if ( v4 >= m_size )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 215
// RVA: 0xCB9DF0
__int64 __fastcall hkGeometryProcessing::SurfaceSampler::searchElement(
        hkGeometryProcessing::SurfaceSampler *this,
        float value)
{
  int v2; // r10d
  int v3; // r9d
  int v4; // r8d
  int v5; // edx
  float m_value; // xmm0_4
  __int64 v7; // rax
  hkGeometryProcessing::SurfaceSampler::Element *v8; // rcx

  v2 = 0;
  v3 = this->m_elements.m_size - 1;
  v4 = -1;
  if ( v3 < 0 )
    return (unsigned int)v4;
  do
  {
    v5 = (v3 + v2) >> 1;
    if ( v2 >= v3 )
      goto LABEL_7;
    m_value = this->m_elements.m_data[v5].m_value;
    if ( m_value > value )
    {
      v3 = (v3 + v2) >> 1;
      continue;
    }
    if ( m_value >= value )
LABEL_7:
      v4 = (v3 + v2) >> 1;
    else
      v2 = v5 + 1;
  }
  while ( v4 < 0 );
  v7 = v4;
  if ( value < this->m_elements.m_data[v4].m_value )
  {
    v8 = &this->m_elements.m_data[v4];
    do
    {
      if ( !v7 )
        break;
      --v8;
      --v4;
      --v7;
    }
    while ( value < v8->m_value );
  }
  return (unsigned int)v4;
}

// File Line: 235
// RVA: 0xCB9E70
__int64 __fastcall hkGeometryProcessing::SurfaceSampler::getSample(
        hkGeometryProcessing::SurfaceSampler *this,
        hkGeometryProcessing::Prng *prng,
        hkVector4f *baryCenter)
{
  unsigned int v3; // r15d
  unsigned int v4; // r9d
  int v7; // esi
  unsigned int m_w; // eax
  bool v9; // sf
  unsigned int v10; // r15d
  BOOL v11; // edi
  unsigned int m_x; // ebx
  int v13; // eax
  hkGeometryProcessing::SurfaceSampler::Element *m_data; // r11
  signed int v15; // r9d
  unsigned int v16; // edx
  float v17; // xmm0_4
  unsigned int v18; // r8d
  int v19; // edx
  __m128 v20; // xmm1
  BOOL v21; // ebp
  int v22; // edx
  __m128 v23; // xmm3
  __m128 v24; // xmm1

  v3 = prng->m_c + prng->m_w;
  v4 = prng->m_y ^ (32 * prng->m_y);
  v7 = v4 ^ (v4 >> 7) ^ ((v4 ^ (v4 >> 7)) << 22);
  m_w = prng->m_w;
  v9 = (int)(prng->m_z + v3) < 0;
  v10 = prng->m_z + v3;
  v11 = v9;
  prng->m_x += 1411392427;
  m_x = prng->m_x;
  prng->m_z = m_w;
  v10 &= ~0x80000000;
  prng->m_y = v7;
  prng->m_c = v9;
  prng->m_w = v10;
  v13 = hkGeometryProcessing::SurfaceSampler::searchElement(
          this,
          (float)((float)(int)(v10 + v7 + m_x) * 2.3283064e-10) * this->m_domain);
  m_data = this->m_elements.m_data;
  m_x += 1411392427;
  v15 = prng->m_z + v10 + v11;
  prng->m_z = v15 & 0x7FFFFFFF;
  v16 = v7 ^ (32 * v7) ^ ((v7 ^ (unsigned int)(32 * v7)) >> 7) ^ ((v7 ^ (32 * v7) ^ ((v7 ^ (unsigned int)(32 * v7)) >> 7)) << 22);
  v17 = (float)(int)((v15 & 0x7FFFFFFF) + m_x + v16);
  v18 = v16 ^ (32 * v16) ^ ((v16 ^ (32 * v16)) >> 7) ^ ((v16 ^ (32 * v16) ^ ((v16 ^ (32 * v16)) >> 7)) << 22);
  prng->m_y = v18;
  v19 = (v15 & 0x7FFFFFFF) + (v15 < 0);
  v20 = _mm_shuffle_ps(
          (__m128)COERCE_UNSIGNED_INT(v17 * 2.3283064e-10),
          (__m128)COERCE_UNSIGNED_INT(v17 * 2.3283064e-10),
          0);
  v21 = (int)(v10 + v19) < 0;
  v22 = (v10 + v19) & 0x7FFFFFFF;
  prng->m_c = v21;
  prng->m_w = v22;
  v23 = _mm_andnot_ps(_mm_cmple_ps(v20, (__m128)0i64), _mm_sqrt_ps(v20));
  prng->m_x = m_x + 1411392427;
  v24 = _mm_shuffle_ps(
          (__m128)COERCE_UNSIGNED_INT((float)(int)(v22 + v18 + m_x + 1411392427) * 2.3283064e-10),
          (__m128)COERCE_UNSIGNED_INT((float)(int)(v22 + v18 + m_x + 1411392427) * 2.3283064e-10),
          0);
  baryCenter->m_quad = _mm_movelh_ps(
                         _mm_unpacklo_ps(_mm_sub_ps(query.m_quad, v23), _mm_mul_ps(_mm_sub_ps(query.m_quad, v24), v23)),
                         _mm_unpacklo_ps(_mm_mul_ps(v23, v24), aabbOut.m_quad));
  return (unsigned int)m_data[v13].m_index;
}

// File Line: 247
// RVA: 0xCBA020
bool __fastcall hkGeometryProcessing::intersectPlanes(
        hkVector4f *p0,
        hkVector4f *p1,
        hkVector4f *p2,
        hkVector4f *intersection)
{
  __m128 m_quad; // xmm2
  __m128 v9; // xmm1
  bool result; // al
  __m128 v11; // xmm2
  hkMatrix3f v12; // [rsp+20h] [rbp-38h] BYREF
  hkResult v13; // [rsp+60h] [rbp+8h] BYREF

  m_quad = p2->m_quad;
  v9 = _mm_unpacklo_ps(p0->m_quad, p1->m_quad);
  v12.m_col2.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(p0->m_quad, p1->m_quad), p2->m_quad, 228);
  v12.m_col0.m_quad = _mm_movelh_ps(v9, m_quad);
  v12.m_col1.m_quad = _mm_shuffle_ps(_mm_movehl_ps(v12.m_col0.m_quad, v9), m_quad, 212);
  if ( hkMatrix3f::invert(&v12, &v13, 0.00000011920929)->m_enum )
    return 0;
  result = 1;
  v11 = _mm_xor_ps(
          _mm_movelh_ps(
            _mm_unpacklo_ps(_mm_shuffle_ps(p0->m_quad, p0->m_quad, 255), _mm_shuffle_ps(p1->m_quad, p1->m_quad, 255)),
            _mm_unpacklo_ps(_mm_shuffle_ps(p2->m_quad, p2->m_quad, 255), aabbOut.m_quad)),
          (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64));
  intersection->m_quad = _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v12.m_col1.m_quad),
                             _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v12.m_col0.m_quad)),
                           _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v12.m_col2.m_quad));
  return result;
}

// File Line: 262
// RVA: 0xCBA110
bool __fastcall hkGeometryProcessing::intersectLineWithPlane(
        hkVector4f *x0,
        hkVector4f *x1,
        hkVector4f *plane,
        hkSimdFloat32 *toi)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm4
  bool result; // al
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  __m128 v9; // xmm1

  v4 = _mm_mul_ps(_mm_sub_ps(x1->m_quad, x0->m_quad), plane->m_quad);
  v5 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)), _mm_shuffle_ps(v4, v4, 170));
  if ( (float)(v5.m128_f32[0] * v5.m128_f32[0]) <= 0.00000011920929 )
    return 0;
  result = 1;
  v7 = _mm_mul_ps(plane->m_quad, x0->m_quad);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rcp_ps(v5);
  toi->m_real = _mm_mul_ps(
                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v5)), v9),
                  _mm_sub_ps((__m128)0i64, _mm_add_ps(v8, _mm_shuffle_ps(plane->m_quad, plane->m_quad, 255))));
  return result;
}

// File Line: 320
// RVA: 0xCBA1A0
hkSimdFloat32 *__fastcall hkGeometryProcessing::squaredDistanceFromPointToLine(
        hkSimdFloat32 *result,
        hkVector4f *p,
        hkVector4f *p0,
        hkVector4f *p1,
        hkSimdFloat32 *toi)
{
  __m128 v5; // xmm4
  __m128 v6; // xmm5
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm0
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  hkSimdFloat32 *v14; // rax
  __m128 v15; // xmm3
  __m128 v16; // xmm3

  v5 = _mm_sub_ps(p1->m_quad, p0->m_quad);
  v6 = _mm_sub_ps(p0->m_quad, p->m_quad);
  v7 = _mm_mul_ps(v5, v5);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_mul_ps(v6, v5);
  v10 = _mm_rcp_ps(v8);
  v11 = _mm_sub_ps(
          (__m128)0i64,
          _mm_mul_ps(
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v8, v10)), v10),
            _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170))));
  *toi = (hkSimdFloat32)v11;
  v12 = _mm_cmplt_ps(v11, query.m_quad);
  v13 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v11, v12), _mm_andnot_ps(v12, query.m_quad)));
  *toi = (hkSimdFloat32)v13;
  v14 = result;
  v15 = _mm_add_ps(_mm_mul_ps(v13, v5), v6);
  v16 = _mm_mul_ps(v15, v15);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                     _mm_shuffle_ps(v16, v16, 170));
  return v14;
}

// File Line: 333
// RVA: 0xCBA260
hkSimdFloat32 *__fastcall hkGeometryProcessing::squaredDistanceFromPointToLine(
        hkSimdFloat32 *result,
        hkVector4f *p,
        hkVector4f *p0,
        hkVector4f *p1,
        hkVector4f *normalOut,
        float *baryOut)
{
  __m128 v6; // xmm5
  __m128 v7; // xmm1
  __m128 v8; // xmm6
  __m128 v9; // xmm4
  __m128 v10; // xmm2
  __m128 v11; // xmm0
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm7
  __m128 v15; // xmm2
  __m128 v16; // xmm2
  hkSimdFloat32 *v17; // rax

  v6 = _mm_sub_ps(p1->m_quad, p0->m_quad);
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_sub_ps(p0->m_quad, p->m_quad);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v10 = _mm_mul_ps(v8, v6);
  v11 = _mm_rcp_ps(v9);
  v12 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v11)), v11),
          _mm_sub_ps(
            (__m128)0i64,
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
              _mm_shuffle_ps(v10, v10, 170))));
  v13 = _mm_cmplt_ps(v12, query.m_quad);
  v14 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v12, v13), _mm_andnot_ps(v13, query.m_quad)));
  v15 = _mm_add_ps(_mm_mul_ps(v14, v6), v8);
  normalOut->m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v15);
  if ( baryOut )
    *baryOut = v14.m128_f32[0];
  v16 = _mm_mul_ps(v15, v15);
  v17 = result;
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                     _mm_shuffle_ps(v16, v16, 170));
  return v17;
}

// File Line: 348
// RVA: 0xCBA360
hkSimdFloat32 *__fastcall hkGeometryProcessing::squaredDistanceFromPointToTriangle(
        hkSimdFloat32 *result,
        hkVector4f *p,
        hkVector4f *p0,
        hkVector4f *p1,
        hkVector4f *p2,
        hkVector4f *normalOut,
        hkVector4f *baryOut)
{
  __m128 m_quad; // xmm11
  __m128 v8; // xmm1
  __m128 v9; // xmm13
  __m128 v10; // xmm0
  __m128 v11; // xmm4
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm5
  __m128 v17; // xmm2
  __m128 v18; // xmm5
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128i v21; // xmm4
  __m128 v22; // xmm1
  __m128 v23; // xmm14
  __m128 v24; // xmm8
  __m128 v25; // xmm6
  __m128 v26; // xmm7
  hkVector4f v27; // xmm10
  __m128 v28; // xmm1
  __m128 v29; // xmm5
  __m128 v30; // xmm3
  __m128 v31; // xmm0
  __m128 v32; // xmm2
  __m128 v33; // xmm8
  __m128 v34; // xmm1
  __m128 v35; // xmm3
  __m128 v36; // xmm1
  __m128 v37; // xmm8
  __m128 v38; // xmm2
  __m128 v39; // xmm3
  __m128 v40; // xmm2
  __m128 v41; // xmm0
  __m128 v42; // xmm6
  __m128 v43; // xmm7
  __m128 v44; // xmm8
  __m128 v45; // xmm4
  __m128 v46; // xmm10
  __m128 v47; // xmm9
  __m128 v48; // xmm13
  __m128 v49; // xmm0
  __m128 v50; // xmm3
  __m128 v51; // xmm5
  __m128 v52; // xmm1
  __m128 v53; // xmm2
  __m128 v54; // xmm5
  __m128 v55; // xmm3
  __m128 v56; // xmm0
  __m128 v57; // xmm1
  __m128 v58; // xmm2
  __m128 v59; // xmm4
  __m128 v60; // xmm0
  __m128 v61; // xmm2
  __m128 v62; // xmm0
  __m128 v63; // xmm3
  __m128 v64; // xmm9
  __m128 v65; // xmm13
  __m128 v66; // xmm1
  __m128 v67; // xmm10
  __m128 v68; // xmm1
  __m128 v69; // xmm2
  __m128 v70; // xmm10
  __m128 v71; // xmm5
  int v72; // eax
  int v73; // edx
  hkVector4f v74; // xmm4
  __m128 v75; // xmm0
  __m128 v76; // xmm11
  __m128 v77; // xmm0
  __m128 v78; // xmm11
  __m128 v79; // xmm1
  __m128 v81; // [rsp+0h] [rbp-C8h]
  __m128 v82; // [rsp+10h] [rbp-B8h]
  __m128 v83; // [rsp+20h] [rbp-A8h]

  m_quad = query.m_quad;
  v8 = _mm_sub_ps(p1->m_quad, p0->m_quad);
  v9 = _mm_shuffle_ps(p->m_quad, _mm_unpackhi_ps(p->m_quad, query.m_quad), 196);
  v10 = _mm_sub_ps(p2->m_quad, p0->m_quad);
  v11 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v10));
  v12 = _mm_shuffle_ps(v11, v11, 201);
  v13 = _mm_mul_ps(v12, v12);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_rsqrt_ps(v14);
  v16 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v14, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
              _mm_mul_ps(*(__m128 *)_xmm, v15))),
          v12);
  v17 = _mm_mul_ps(p0->m_quad, v16);
  v18 = _mm_shuffle_ps(
          v16,
          _mm_unpackhi_ps(
            v16,
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                _mm_shuffle_ps(v17, v17, 170)))),
          196);
  v19 = _mm_mul_ps(v18, v9);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 78), v19);
  v21 = (__m128i)_mm_add_ps(_mm_shuffle_ps(v20, v20, 177), v20);
  v22 = _mm_sub_ps(v9, _mm_mul_ps((__m128)v21, v18));
  v23 = *(__m128 *)&epsilon;
  v24 = _mm_sub_ps(p1->m_quad, v22);
  v25 = _mm_sub_ps(p2->m_quad, v22);
  v26 = _mm_sub_ps(p0->m_quad, v22);
  v27.m_quad = _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v21, 0x1Fu), 0x1Fu), v18);
  v28 = _mm_shuffle_ps(v18, v18, 210);
  v29 = _mm_shuffle_ps(v18, v18, 201);
  v30 = _mm_mul_ps(
          _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v28), _mm_mul_ps(_mm_shuffle_ps(v25, v25, 210), v29)),
          v24);
  v31 = _mm_shuffle_ps(v24, v24, 210);
  v32 = _mm_mul_ps(
          _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v28), _mm_mul_ps(_mm_shuffle_ps(v26, v26, 210), v29)),
          v25);
  v33 = _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v28);
  v34 = v30;
  v35 = _mm_unpackhi_ps(v30, v32);
  v36 = _mm_unpacklo_ps(v34, v32);
  v37 = _mm_mul_ps(_mm_sub_ps(v33, _mm_mul_ps(v31, v29)), v26);
  v38 = _mm_movelh_ps(v36, v37);
  v39 = _mm_add_ps(_mm_shuffle_ps(v35, v37, 228), _mm_add_ps(v38, _mm_shuffle_ps(_mm_movehl_ps(v38, v36), v37, 212)));
  if ( baryOut )
  {
    v40 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
            _mm_shuffle_ps(v39, v39, 170));
    v41 = _mm_rcp_ps(v40);
    baryOut->m_quad = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v40, v41)), v41), v39);
    v23 = *(__m128 *)&epsilon;
    m_quad = query.m_quad;
  }
  if ( (_mm_movemask_ps(_mm_cmplt_ps(*(__m128 *)&epsilon, v39)) & 7) == 7 )
  {
    *normalOut = (hkVector4f)v27.m_quad;
    result->m_real = _mm_mul_ps((__m128)v21, (__m128)v21);
  }
  else
  {
    v42 = _mm_sub_ps(p1->m_quad, p0->m_quad);
    v43 = _mm_sub_ps(p2->m_quad, p1->m_quad);
    v44 = _mm_sub_ps(p0->m_quad, p2->m_quad);
    v45 = _mm_mul_ps(v42, v42);
    v46 = _mm_sub_ps(v9, p0->m_quad);
    v47 = _mm_sub_ps(v9, p1->m_quad);
    v48 = _mm_sub_ps(v9, p2->m_quad);
    v49 = _mm_mul_ps(v47, v43);
    v50 = _mm_mul_ps(v48, v44);
    v51 = _mm_mul_ps(v46, v42);
    v52 = _mm_unpacklo_ps(v51, v49);
    v53 = _mm_movelh_ps(v52, v50);
    v54 = _mm_add_ps(
            _mm_shuffle_ps(_mm_unpackhi_ps(v51, v49), v50, 228),
            _mm_add_ps(v53, _mm_shuffle_ps(_mm_movehl_ps(v53, v52), v50, 212)));
    v55 = _mm_mul_ps(v44, v44);
    v56 = _mm_mul_ps(v43, v43);
    v57 = _mm_unpacklo_ps(v45, v56);
    v58 = _mm_movelh_ps(v57, v55);
    v59 = _mm_max_ps(
            _mm_add_ps(
              _mm_shuffle_ps(_mm_unpackhi_ps(v45, v56), v55, 228),
              _mm_add_ps(v58, _mm_shuffle_ps(_mm_movehl_ps(v58, v57), v55, 212))),
            v23);
    v60 = _mm_rcp_ps(v59);
    v61 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v59, v60)), v60), v54);
    v62 = _mm_cmplt_ps(v61, m_quad);
    v63 = _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v62, m_quad), _mm_and_ps(v61, v62)));
    v81 = _mm_sub_ps(v46, _mm_mul_ps(_mm_shuffle_ps(v63, v63, 0), v42));
    v82 = _mm_sub_ps(v47, _mm_mul_ps(_mm_shuffle_ps(v63, v63, 85), v43));
    v64 = _mm_mul_ps(v82, v82);
    v83 = _mm_sub_ps(v48, _mm_mul_ps(_mm_shuffle_ps(v63, v63, 170), v44));
    v65 = _mm_mul_ps(v83, v83);
    v66 = _mm_mul_ps(v81, v81);
    v67 = _mm_unpackhi_ps(v66, v64);
    v68 = _mm_unpacklo_ps(v66, v64);
    v69 = _mm_movelh_ps(v68, v65);
    v70 = _mm_add_ps(_mm_shuffle_ps(v67, v65, 228), _mm_add_ps(v69, _mm_shuffle_ps(_mm_movehl_ps(v69, v68), v65, 212)));
    v71 = _mm_min_ps(
            _mm_shuffle_ps(v70, v70, 170),
            _mm_min_ps(_mm_shuffle_ps(v70, v70, 85), _mm_shuffle_ps(v70, v70, 0)));
    v72 = _mm_movemask_ps(_mm_cmpeq_ps(v70, v71));
    if ( (v72 & 7) != 0 )
      v73 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[v72];
    else
      v73 = -1;
    v74.m_quad = (__m128)*((_OWORD *)&v81 + v73);
    if ( baryOut )
    {
      v75 = _mm_sub_ps(m_quad, v63);
      v76 = _mm_unpackhi_ps(v75, v63);
      v77 = _mm_unpacklo_ps(v75, v63);
      v78 = _mm_shuffle_ps(v76, (__m128)0i64, 228);
      v81 = _mm_movelh_ps(v77, (__m128)0i64);
      v79 = _mm_shuffle_ps(_mm_movehl_ps(v81, v77), (__m128)0i64, 212);
      v83 = _mm_shuffle_ps(v78, v78, 137);
      v82 = _mm_shuffle_ps(v79, v79, 146);
      *baryOut = *((hkVector4f *)&v81 + v73);
    }
    *result = (hkSimdFloat32)v71;
    *normalOut = (hkVector4f)v74.m_quad;
  }
  return result;
}

// File Line: 356
// RVA: 0xCBA800
hkSimdFloat32 *__fastcall hkGeometryProcessing::nearestDistanceBetweenLines(
        hkSimdFloat32 *result,
        hkVector4f *a0,
        hkVector4f *a1,
        hkVector4f *b0,
        hkVector4f *b1,
        hkSimdFloat32 *u,
        hkSimdFloat32 *v)
{
  __m128 v7; // xmm8
  __m128 v8; // xmm7
  __m128 v9; // xmm9
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm6
  __m128 v13; // xmm11
  __m128 v14; // xmm4
  __m128 v15; // xmm1
  __m128 v16; // xmm9
  __m128 v17; // xmm5
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm1
  __m128 v21; // xmm5
  __m128 v22; // xmm3
  __m128 v23; // xmm5
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  __m128 v26; // xmm3
  __m128 v27; // xmm1
  __m128 v28; // xmm0
  __m128 v29; // xmm7
  __m128 v30; // xmm7
  __m128 v31; // xmm4
  __m128 v32; // xmm1

  v7 = _mm_sub_ps(b1->m_quad, b0->m_quad);
  v8 = _mm_sub_ps(a1->m_quad, a0->m_quad);
  v9 = _mm_sub_ps(b0->m_quad, a0->m_quad);
  v10 = _mm_mul_ps(v7, v8);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_mul_ps(v8, v8);
  v13 = _mm_mul_ps(v9, v8);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v15 = _mm_mul_ps(v7, v7);
  v16 = _mm_mul_ps(v9, v7);
  v17 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
              _mm_shuffle_ps(v15, v15, 170)),
            v14),
          _mm_sub_ps((__m128)0i64, _mm_mul_ps(v11, v11)));
  if ( COERCE_FLOAT((unsigned int)(2 * v17.m128_i32[0]) >> 1) <= 0.00000011920929 )
  {
    *u = 0i64;
    *v = 0i64;
    *result = (hkSimdFloat32)xmmword_141A712A0;
  }
  else
  {
    v18 = _mm_rcp_ps(v17);
    v19 = _mm_mul_ps(
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, v17)), v18),
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                    _mm_shuffle_ps(v13, v13, 170)),
                  _mm_sub_ps((__m128)0i64, v11)),
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                    _mm_shuffle_ps(v16, v16, 170)),
                  v14))));
    v20 = _mm_cmplt_ps(v19, query.m_quad);
    v21 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v19, v20), _mm_andnot_ps(v20, query.m_quad)));
    *v = (hkSimdFloat32)v21;
    v22 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
            _mm_shuffle_ps(v12, v12, 170));
    v23 = _mm_add_ps(_mm_mul_ps(v21, v7), b0->m_quad);
    v24 = _mm_mul_ps(_mm_sub_ps(a0->m_quad, v23), v8);
    v25 = _mm_rcp_ps(v22);
    v26 = _mm_sub_ps(
            (__m128)0i64,
            _mm_mul_ps(
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v25)), v25),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                _mm_shuffle_ps(v24, v24, 170))));
    v27 = _mm_cmplt_ps(v26, query.m_quad);
    v28 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v27, query.m_quad), _mm_and_ps(v27, v26)));
    *u = (hkSimdFloat32)v28;
    v29 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v8, v28), a0->m_quad), v23);
    v30 = _mm_mul_ps(v29, v29);
    v31 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
            _mm_shuffle_ps(v30, v30, 170));
    v32 = _mm_rsqrt_ps(v31);
    result->m_real = _mm_andnot_ps(
                       _mm_cmple_ps(v31, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v32), v32)),
                           _mm_mul_ps(*(__m128 *)_xmm, v32)),
                         v31));
  }
  return result;
}            

// File Line: 399
// RVA: 0xCBAAB0
bool __fastcall hkGeometryProcessing::checkPointInsideTriangle(
        hkVector4f *p,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c,
        hkSimdFloat32 *epsilon)
{
  __m128 v5; // xmm4
  __m128 v6; // xmm1
  __m128 v7; // xmm6
  __m128 v8; // xmm5
  __m128 m_real; // xmm7
  __m128 v10; // xmm6
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm2
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  __m128 v19; // xmm2

  v5 = _mm_sub_ps(b->m_quad, p->m_quad);
  v6 = _mm_sub_ps(b->m_quad, a->m_quad);
  v7 = _mm_sub_ps(c->m_quad, a->m_quad);
  v8 = _mm_sub_ps(a->m_quad, p->m_quad);
  m_real = epsilon->m_real;
  v10 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v6), _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v7));
  v11 = _mm_shuffle_ps(v10, v10, 201);
  v12 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v5));
  v13 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v11);
  if ( (float)((float)(_mm_shuffle_ps(v13, v13, 85).m128_f32[0] + _mm_shuffle_ps(v13, v13, 0).m128_f32[0])
             + _mm_shuffle_ps(v13, v13, 170).m128_f32[0]) < COERCE_FLOAT(*epsilon) )
    return 0;
  v15 = _mm_sub_ps(c->m_quad, p->m_quad);
  v16 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v5), _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v15));
  v17 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v11);
  if ( (float)((float)(_mm_shuffle_ps(v17, v17, 85).m128_f32[0] + _mm_shuffle_ps(v17, v17, 0).m128_f32[0])
             + _mm_shuffle_ps(v17, v17, 170).m128_f32[0]) < m_real.m128_f32[0] )
    return 0;
  v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v8));
  v19 = _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v11);
  return (float)((float)(_mm_shuffle_ps(v19, v19, 85).m128_f32[0] + _mm_shuffle_ps(v19, v19, 0).m128_f32[0])
               + _mm_shuffle_ps(v19, v19, 170).m128_f32[0]) >= m_real.m128_f32[0];
}

// File Line: 410
// RVA: 0xCBABD0
void __fastcall hkGeometryProcessing::buildTransposedArray(
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertices,
        hkArray<hkFourTransposedPointsf,hkContainerHeapAllocator> *output)
{
  int m_size; // ebp
  __int64 v3; // r14
  int v4; // ebp
  int v5; // eax
  int v6; // ebx
  int v7; // r9d
  int v10; // eax
  __int64 v11; // r9
  __int64 v12; // rdx
  hkFourTransposedPointsf *v13; // r10
  __int64 v14; // r8
  __int64 v15; // rax
  __m128 v16; // xmm5
  __m128 v17; // xmm4
  __m128 v18; // xmm6
  __m128 v19; // xmm3
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 *v22; // rcx
  __int64 v23; // rdx
  __m128 *v24; // rax
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  __m128 m_quad; // [rsp+30h] [rbp-68h] BYREF
  __m128 v28; // [rsp+40h] [rbp-58h]
  __m128 v29; // [rsp+50h] [rbp-48h]
  __m128 v30; // [rsp+60h] [rbp-38h]
  hkResult result; // [rsp+A0h] [rbp+8h] BYREF

  m_size = vertices->m_size;
  v3 = output->m_size;
  m_quad = aabbOut.m_quad;
  v28 = aabbOut.m_quad;
  v29 = aabbOut.m_quad;
  v30 = aabbOut.m_quad;
  v4 = (m_size + 3) >> 2;
  v5 = output->m_capacityAndFlags & 0x3FFFFFFF;
  v6 = 0;
  v7 = v3 + v4;
  if ( v5 < (int)v3 + v4 )
  {
    v10 = 2 * v5;
    if ( v7 < v10 )
      v7 = v10;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&output->m_data, v7, 48);
  }
  output->m_size += v4;
  v11 = vertices->m_size;
  v12 = 0i64;
  v13 = &output->m_data[v3];
  if ( v11 > 0 )
  {
    v14 = 0i64;
    do
    {
      v15 = v12++;
      ++v6;
      *(&m_quad + v15) = vertices->m_data[v14].m_quad;
      v16 = v30;
      v17 = v29;
      v18 = v28;
      v19 = m_quad;
      if ( v12 == 4 )
      {
        v6 = 0;
        v12 = 0i64;
        ++v13;
        v20 = _mm_shuffle_ps(v29, v30, 68);
        v21 = _mm_shuffle_ps(m_quad, v28, 68);
        v13[-1].m_vertices[0].m_quad = _mm_shuffle_ps(v21, v20, 136);
        v13[-1].m_vertices[1].m_quad = _mm_shuffle_ps(v21, v20, 221);
        v13[-1].m_vertices[2].m_quad = _mm_shuffle_ps(_mm_shuffle_ps(v19, v18, 238), _mm_shuffle_ps(v17, v16, 238), 136);
      }
      ++v14;
      --v11;
    }
    while ( v11 );
    if ( v6 )
    {
      if ( v6 < 4i64 )
      {
        v22 = &m_quad + v6;
        v23 = 4i64 - v6;
        do
        {
          v24 = v22++;
          *v24 = v19;
          v19 = m_quad;
          --v23;
        }
        while ( v23 );
        v16 = v30;
        v17 = v29;
        v18 = v28;
      }
      v25 = _mm_shuffle_ps(v19, v18, 68);
      v26 = _mm_shuffle_ps(v17, v16, 68);
      v13->m_vertices[0].m_quad = _mm_shuffle_ps(v25, v26, 136);
      v13->m_vertices[1].m_quad = _mm_shuffle_ps(v25, v26, 221);
      v13->m_vertices[2].m_quad = _mm_shuffle_ps(_mm_shuffle_ps(v19, v18, 238), _mm_shuffle_ps(v17, v16, 238), 136);
    }
  }
}

// File Line: 434
// RVA: 0xCBADB0
void __fastcall hkGeometryProcessing::getSupportingVertex(
        hkArrayBase<hkFourTransposedPointsf> *transposedVertices,
        hkVector4f *direction,
        hkVector4f *vertexOut)
{
  __m128 m_quad; // xmm4
  hkFourTransposedPointsf *m_data; // r9
  __int64 m_size; // rcx
  __m128i v6; // xmm5
  __m128 v8; // xmm7
  __m128 v9; // xmm8
  __m128 v10; // xmm4
  __m128i v11; // xmm6
  __m128 v12; // xmm3
  __m128i si128; // xmm9
  __m128 *p_m_quad; // rax
  __int64 v15; // rcx
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128i v20; // xmm1
  __m128 v21; // xmm2
  __m128i v22; // xmm0
  __m128 v23; // xmm2
  __m128i v24; // xmm1
  __m128i v25; // xmm2
  unsigned int v26; // r8d
  hkFourTransposedPointsf *v27; // rdx
  __int64 v28; // rcx
  hkVector4f v29; // [rsp+0h] [rbp-58h]

  m_quad = direction->m_quad;
  m_data = transposedVertices->m_data;
  m_size = transposedVertices->m_size;
  v6 = (__m128i)xmmword_141A720C0;
  v8 = _mm_shuffle_ps(m_quad, m_quad, 0);
  v9 = _mm_shuffle_ps(direction->m_quad, direction->m_quad, 85);
  v10 = _mm_shuffle_ps(m_quad, m_quad, 170);
  v11 = (__m128i)xmmword_141A720C0;
  v12 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(m_data->m_vertices[1].m_quad, v9), _mm_mul_ps(m_data->m_vertices[0].m_quad, v8)),
          _mm_mul_ps(m_data->m_vertices[2].m_quad, v10));
  if ( m_size > 1 )
  {
    si128 = _mm_load_si128((const __m128i *)&xmmword_141A720B0);
    p_m_quad = &m_data[1].m_vertices[2].m_quad;
    v15 = m_size - 1;
    do
    {
      v16 = p_m_quad[-1];
      v17 = p_m_quad[-2];
      v18 = *p_m_quad;
      v6 = _mm_add_epi32(v6, si128);
      p_m_quad += 3;
      v19 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v16, v9), _mm_mul_ps(v17, v8)), _mm_mul_ps(v18, v10));
      v20 = (__m128i)_mm_cmplt_ps(v12, v19);
      v12 = _mm_or_ps(_mm_and_ps(v19, (__m128)v20), _mm_andnot_ps((__m128)v20, v12));
      v11 = _mm_or_si128(_mm_andnot_si128(v20, v11), _mm_and_si128(v20, v6));
      --v15;
    }
    while ( v15 );
  }
  v21 = _mm_shuffle_ps(v12, v12, 57);
  v22 = (__m128i)_mm_cmplt_ps(v12, v21);
  v23 = _mm_max_ps(v21, v12);
  v24 = _mm_or_si128(_mm_and_si128(_mm_shuffle_epi32(v11, 57), v22), _mm_andnot_si128(v22, v11));
  v25 = (__m128i)_mm_cmplt_ps(v23, _mm_shuffle_ps(v23, v23, 170));
  v26 = _mm_cvtsi128_si32(_mm_or_si128(_mm_and_si128(_mm_shuffle_epi32(v24, 170), v25), _mm_andnot_si128(v25, v24)));
  v27 = &m_data[(unsigned __int64)v26 >> 2];
  v28 = v26 & 3;
  v29.m_quad.m128_i32[3] = v26 | 0x3F000000;
  v29.m_quad.m128_i32[0] = v27->m_vertices[0].m_quad.m128_i32[v28];
  v29.m_quad.m128_i32[1] = v27->m_vertices[1].m_quad.m128_i32[v28];
  v29.m_quad.m128_i32[2] = v27->m_vertices[2].m_quad.m128_i32[v28];
  *vertexOut = (hkVector4f)v29.m_quad;
}

// File Line: 442
// RVA: 0xCBEAA0
bool __fastcall hkGeometryProcessingInternals::generateRandomDistribution(
        hkgpMesh *mesh,
        int numPoints,
        hkArray<hkVector4f,hkContainerHeapAllocator> *points,
        hkPseudoRandomGenerator *rndGenerator)
{
  hkVector4f v8; // xmm8
  int v9; // r14d
  int v10; // edi
  __m128 v11; // xmm7
  bool v12; // zf
  signed int v13; // eax
  float v14; // xmm0_4
  int v15; // eax
  float v16; // xmm0_4
  int v17; // eax
  float v18; // xmm0_4
  signed int v19; // eax
  int v20; // eax
  __m128 m_quad; // xmm1
  hkVector4f x; // [rsp+30h] [rbp-B8h] BYREF
  hkVector4fComparison inside; // [rsp+40h] [rbp-A8h] BYREF
  hkVector4f normal; // [rsp+50h] [rbp-98h] BYREF
  hkSimdFloat32 result; // [rsp+60h] [rbp-88h] BYREF
  hkAabb v27; // [rsp+70h] [rbp-78h] BYREF

  hkgpMesh::getBoundingBox(mesh, &v27);
  v8.m_quad = (__m128)v27.m_min;
  v9 = 8 * numPoints;
  v10 = 0;
  v11 = _mm_sub_ps(v27.m_max.m_quad, v27.m_min.m_quad);
  v12 = numPoints == 0;
  if ( numPoints )
  {
    do
    {
      v13 = 1664525 * rndGenerator->m_current + 1013904223;
      v14 = (float)v13;
      v15 = 1664525 * v13 + 1013904223;
      x.m_quad.m128_f32[0] = v14 * 2.3283064e-10;
      v16 = (float)v15;
      v17 = 1664525 * v15 + 1013904223;
      x.m_quad.m128_f32[1] = v16 * 2.3283064e-10;
      v18 = (float)v17;
      v19 = 1664525 * v17 + 1013904223;
      rndGenerator->m_current = v19;
      x.m_quad.m128_f32[2] = v18 * 2.3283064e-10;
      x.m_quad.m128_f32[3] = (float)v19 * 2.3283064e-10;
      x.m_quad = _mm_add_ps(_mm_mul_ps(x.m_quad, v11), v8.m_quad);
      hkgpMesh::squaredDistanceToPoint(mesh, &result, &x, &normal, &inside);
      if ( _mm_movemask_ps(inside.m_mask) )
      {
        v20 = points->m_capacityAndFlags & 0x3FFFFFFF;
        m_quad = _mm_shuffle_ps(x.m_quad, _mm_unpackhi_ps(x.m_quad, query.m_quad), 196);
        x.m_quad = m_quad;
        if ( points->m_size == v20 )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&points->m_data, 16);
          m_quad = x.m_quad;
        }
        v10 = 0;
        points->m_data[points->m_size++].m_quad = m_quad;
        --numPoints;
      }
      else if ( ++v10 > v9 )
      {
        return numPoints == 0;
      }
    }
    while ( numPoints );
    return numPoints == 0;
  }
  return v12;
}

// File Line: 467
// RVA: 0xCBAF40
bool __fastcall hkGeometryProcessing::generateRandomDistribution(
        hkGeometry *geometry,
        int numPoints,
        hkArray<hkVector4f,hkContainerHeapAllocator> *points,
        int seed)
{
  return hkGeometryProcessing::generateUniformDistribution(geometry, numPoints, points, seed, 0, 0i64);
}

// File Line: 473
// RVA: 0xCBAF60
__int64 __fastcall hkGeometryProcessing::generateUniformDistribution(
        hkGeometry *geometry,
        unsigned int numPoints,
        hkArray<hkVector4f,hkContainerHeapAllocator> *points,
        int maxIterations,
        int seed,
        hkGeometryProcessing::ConstFunction<hkGeometryProcessing::IFunction<hkVector4f,float> > *densityFunction)
{
  __m128 v6; // xmm2
  int v7; // esi
  __int64 v9; // r14
  hkGeometryProcessing::ConstFunction<hkGeometryProcessing::IFunction<hkVector4f,float> > *v11; // r15
  __m128 v12; // xmm1
  __int64 m_size; // rdi
  unsigned __int8 v14; // bl
  hkVector4f *v15; // r12
  __int64 v16; // r13
  __m128 *p_m_quad; // rsi
  __m128i v18; // xmm6
  __m128i v19; // xmm7
  unsigned __int64 m_firstFree; // r14
  hkcdDynamicTree::CodecRawUlong *m_data; // rcx
  unsigned __int64 v22; // rdi
  hkcdDynamicTree::CodecRawUlong *v23; // r8
  unsigned __int64 m_root; // rbx
  __m128 v25; // xmm7
  __m128 v26; // xmm8
  unsigned __int64 v27; // r9
  __m128 *v28; // rbx
  hkcdDynamicTree::CodecRawUlong *v29; // r9
  __m128 v30; // xmm9
  __m128 v31; // xmm10
  __m128 v32; // xmm1
  __int64 v33; // rax
  __int64 v34; // rcx
  __m128 v35; // xmm2
  __m128 v36; // xmm6
  __m128 v37; // xmm3
  __m128 v38; // xmm2
  __m128 v39; // xmm5
  __m128 v40; // xmm6
  __m128 v41; // xmm2
  __m128 v42; // xmm6
  unsigned __int64 v43; // r11
  __int64 v44; // r10
  __int64 v45; // rax
  float v46; // xmm0_4
  bool v47; // zf
  __m128 v48; // xmm2
  int v49; // ecx
  int v50; // eax
  int m_capacityAndFlags; // r8d
  int v52; // ebx
  int v53; // r14d
  __int64 v54; // rdi
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::ClosestFromPointWrapper<hkGeometryProcessingInternals::NearestFeaturePolicy> *v56; // r9
  hkcdDynamicTree::CodecRawUlong *m_cur; // rcx
  hkcdDynamicTree::CodecRawUlong *v58; // rdx
  int v59; // eax
  char *v60; // rsi
  signed int v61; // ebx
  hkLifoAllocator *v62; // rax
  int v63; // r8d
  __m128 *v64; // rbx
  __int64 v65; // r13
  __m128 *v66; // rsi
  __m128 v67; // xmm1
  __m128 v68; // xmm2
  hkcdDynamicTree::CodecRawUlong *v69; // r11
  unsigned __int64 v70; // rdx
  unsigned __int64 v71; // r14
  unsigned __int64 v72; // rdi
  hkVector4f v73; // xmm5
  hkVector4f v74; // xmm6
  __m128i v75; // xmm4
  __m128i v76; // xmm3
  hkcdDynamicTree::CodecRawUlong *v77; // r9
  unsigned __int64 m_parent; // rax
  hkcdDynamicTree::CodecRawUlong *v79; // rbx
  unsigned __int64 v80; // r8
  hkcdDynamicTree::CodecRawUlong *v81; // rcx
  unsigned __int64 v82; // rdx
  __m128 *v83; // rcx
  unsigned __int64 v84; // rax
  __m128 v85; // xmm2
  __m128 v86; // xmm1
  unsigned __int64 v87; // rax
  __m128 v88; // xmm2
  hkcdDynamicTree::CodecRawUlong *v89; // r8
  unsigned __int64 v90; // rbx
  __m128 v91; // xmm7
  __m128 v92; // xmm8
  unsigned __int64 v93; // r9
  __m128 *v94; // rbx
  hkcdDynamicTree::CodecRawUlong *v95; // r9
  __m128 v96; // xmm9
  __m128 v97; // xmm10
  __m128 v98; // xmm1
  __int64 v99; // rax
  __int64 v100; // rcx
  __m128 v101; // xmm3
  __m128 v102; // xmm6
  __m128 v103; // xmm2
  __m128 v104; // xmm5
  __m128 v105; // xmm3
  __m128 v106; // xmm3
  __m128 v107; // xmm6
  __m128 v108; // xmm6
  unsigned __int64 v109; // r11
  __int64 v110; // r10
  __int64 v111; // rax
  float v112; // xmm0_4
  __m128 v113; // xmm1
  __m128 v114; // xmm2
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> v116; // [rsp+30h] [rbp-D0h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> pointsa; // [rsp+58h] [rbp-A8h] BYREF
  char *array; // [rsp+68h] [rbp-98h] BYREF
  int v119; // [rsp+70h] [rbp-90h]
  int v120; // [rsp+74h] [rbp-8Ch]
  __int64 v121[2]; // [rsp+78h] [rbp-88h] BYREF
  hkPseudoRandomGenerator rndGenerator; // [rsp+88h] [rbp-78h] BYREF
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> tree; // [rsp+90h] [rbp-70h] BYREF
  hkGeometryProcessing::ConstFunction<hkGeometryProcessing::IFunction<hkVector4f,float> > *v124; // [rsp+B8h] [rbp-48h]
  __int64 v125[2]; // [rsp+C0h] [rbp-40h]
  hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64> stackInstance; // [rsp+D0h] [rbp-30h] BYREF
  __int128 v127; // [rsp+F0h] [rbp-10h]
  int v128; // [rsp+100h] [rbp+0h]
  hkgpMesh mesh; // [rsp+110h] [rbp+10h] BYREF
  __int64 result; // [rsp+250h] [rbp+150h] BYREF
  int v132; // [rsp+258h] [rbp+158h]

  v132 = maxIterations;
  v7 = maxIterations;
  v9 = numPoints;
  if ( (_S1_43 & 1) == 0 )
  {
    _S1_43 |= 1u;
    LODWORD(unityFunction.m_value) = (_DWORD)FLOAT_1_0;
    unityFunction.vfptr = (hkGeometryProcessing::IFunction<hkVector4f,float>Vtbl *)&hkGeometryProcessing::ConstFunction<hkGeometryProcessing::IFunction<hkVector4f,float>>::`vftable;
    atexit(hkGeometryProcessing::generateUniformDistribution_::_2_::_dynamic_atexit_destructor_for__unityFunction__);
  }
  v11 = &unityFunction;
  rndGenerator.m_seed = seed;
  rndGenerator.m_current = seed;
  if ( densityFunction )
    v11 = densityFunction;
  v124 = v11;
  hkgpMesh::hkgpMesh(&mesh);
  hkgpMesh::appendFromGeometry(&mesh, geometry, (hkTransformf *)&transform, -1, 0, 1);
  hkgpMesh::assignVertexNormals(&mesh);
  v12 = 0i64;
  hkgpMesh::rebuildTrianglesTree(&mesh, 0.0);
  m_size = points->m_size;
  if ( !hkGeometryProcessingInternals::generateRandomDistribution(&mesh, v9, points, &rndGenerator) )
  {
    v14 = 0;
    goto LABEL_86;
  }
  if ( v7 <= 0 )
  {
LABEL_85:
    v14 = 1;
    goto LABEL_86;
  }
  v120 = 0x80000000;
  array = 0i64;
  v119 = 0;
  v15 = &points->m_data[m_size];
  v116.m_nodes.m_size = 0;
  v116.m_nodes.m_data = 0i64;
  v116.m_nodes.m_capacityAndFlags = 0x80000000;
  memset(&v116.m_firstFree, 0, 24);
  tree.m_root = (unsigned __int64)v15;
  if ( (int)v9 > 0 )
    hkArrayUtil::_reserve((hkResult *)&seed, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v9, 8);
  v119 = v9;
  if ( (int)v9 > 0 )
  {
    v16 = 0i64;
    p_m_quad = &v15->m_quad;
    result = v9;
    do
    {
      v18 = _mm_srli_si128(_mm_slli_si128((__m128i)_mm_add_ps(*p_m_quad, aabbOut.m_quad), 4), 4);
      v19 = _mm_srli_si128(_mm_slli_si128((__m128i)_mm_sub_ps(*p_m_quad, aabbOut.m_quad), 4), 4);
      if ( !v116.m_firstFree )
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
          &v116,
          (hkResult *)&seed,
          1);
      m_firstFree = v116.m_firstFree;
      m_data = v116.m_nodes.m_data;
      v22 = v116.m_firstFree << 6;
      v116.m_firstFree = v116.m_nodes.m_data[(__int64)SLODWORD(v116.m_firstFree)].m_aabb.m_min.m_quad.m128_u64[0];
      *(unsigned __int64 *)((char *)v116.m_nodes.m_data->m_children + v22) = 0i64;
      *(unsigned __int64 *)((char *)&m_data->m_children[1] + v22) = (unsigned __int64)v15;
      *(__m128i *)((char *)&m_data->m_aabb.m_min + v22) = v19;
      *(__m128i *)((char *)&m_data->m_aabb.m_max + v22) = v18;
      v23 = v116.m_nodes.m_data;
      m_root = v116.m_root;
      v25 = *(__m128 *)((char *)&v116.m_nodes.m_data->m_aabb.m_min.m_quad + v22);
      v26 = *(__m128 *)((char *)&v116.m_nodes.m_data->m_aabb.m_max.m_quad + v22);
      if ( v116.m_root )
      {
        v27 = v116.m_firstFree;
        if ( !v116.m_firstFree )
        {
          hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
            &v116,
            (hkResult *)&densityFunction,
            1);
          v27 = v116.m_firstFree;
          v23 = v116.m_nodes.m_data;
        }
        v28 = &v23[m_root].m_aabb.m_min.m_quad;
        v29 = &v23[v27];
        v116.m_firstFree = v23[(__int64)SLODWORD(v116.m_firstFree)].m_aabb.m_min.m_quad.m128_u64[0];
        if ( v28[2].m128_i32[2] )
        {
          v30 = _mm_add_ps(v26, v25);
          v31 = _mm_sub_ps(v26, v25);
          do
          {
            v32 = v28[1];
            v33 = (__int64)&v23[v28[3].m128_u64[0]];
            v34 = (__int64)&v23[v28[2].m128_u64[1]];
            *v28 = _mm_min_ps(*v28, v25);
            v121[1] = v33;
            v121[0] = v34;
            v28[1] = _mm_max_ps(v32, v26);
            v23 = v116.m_nodes.m_data;
            v35 = *(__m128 *)(v34 + 16);
            v36 = *(__m128 *)(v33 + 16);
            v37 = _mm_add_ps(_mm_sub_ps(v35, *(__m128 *)v34), v31);
            v38 = _mm_sub_ps(_mm_add_ps(v35, *(__m128 *)v34), v30);
            v39 = _mm_add_ps(_mm_sub_ps(v36, *(__m128 *)v33), v31);
            v40 = _mm_sub_ps(_mm_add_ps(v36, *(__m128 *)v33), v30);
            v41 = _mm_mul_ps(v38, v38);
            v42 = _mm_mul_ps(v40, v40);
            v28 = (__m128 *)v121[(float)((float)((float)(_mm_shuffle_ps(v41, v41, 85).m128_f32[0]
                                                       + _mm_shuffle_ps(v41, v41, 0).m128_f32[0])
                                               + _mm_shuffle_ps(v41, v41, 170).m128_f32[0])
                                       * (float)((float)(_mm_shuffle_ps(v37, v37, 85).m128_f32[0]
                                                       + _mm_shuffle_ps(v37, v37, 0).m128_f32[0])
                                               + _mm_shuffle_ps(v37, v37, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v39, v39, 85).m128_f32[0] + _mm_shuffle_ps(v39, v39, 0).m128_f32[0]) + _mm_shuffle_ps(v39, v39, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v42, v42, 85).m128_f32[0] + _mm_shuffle_ps(v42, v42, 0).m128_f32[0]) + _mm_shuffle_ps(v42, v42, 170).m128_f32[0]))];
          }
          while ( v28[2].m128_i32[2] );
        }
        v43 = v28[2].m128_u64[0];
        v44 = v29 - v23;
        if ( v43 )
          v23[v43].m_children[v23[v43].m_children[1] == ((char *)v28 - (char *)v23) >> 6] = v44;
        else
          v116.m_root = v29 - v23;
        v29->m_parent = v28[2].m128_u64[0];
        v45 = (char *)v28 - (char *)v116.m_nodes.m_data;
        v29->m_children[1] = m_firstFree;
        v29->m_children[0] = v45 >> 6;
        v28[2].m128_u64[0] = v44;
        *(unsigned __int64 *)((char *)&v116.m_nodes.m_data->m_parent + v22) = v44;
        v12 = _mm_max_ps(v28[1], v26);
        v29->m_aabb.m_min.m_quad = _mm_min_ps(*v28, v25);
        v29->m_aabb.m_max.m_quad = v12;
      }
      else
      {
        v116.m_root = m_firstFree;
        *(unsigned __int64 *)((char *)&v116.m_nodes.m_data->m_parent + v22) = 0i64;
      }
      ++v116.m_numLeaves;
      *(_QWORD *)&array[v16] = m_firstFree;
      v46 = v11->vfptr->evaluate(v11, v15);
      ++p_m_quad;
      ++v15;
      v16 += 8i64;
      v47 = result-- == 1;
      v12.m128_f32[0] = v46;
      v12 = _mm_shuffle_ps(v12, v12, 0);
      v48 = _mm_mul_ps(v12, p_m_quad[-1]);
      v6 = _mm_shuffle_ps(v48, _mm_unpackhi_ps(v48, v12), 196);
      p_m_quad[-1] = v6;
    }
    while ( !v47 );
    LODWORD(v9) = numPoints;
    v15 = (hkVector4f *)tree.m_root;
    v7 = v132;
  }
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH(&v116, v116.m_root, (hkBool)1, 32, 16);
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::compactIndices(&v116);
  v49 = 256;
  v50 = 2 * v9;
  m_capacityAndFlags = 0x80000000;
  pointsa.m_data = 0i64;
  pointsa.m_size = 0;
  seed = 256;
  pointsa.m_capacityAndFlags = 0x80000000;
  if ( 2 * (int)v9 < 256 || (v49 = 0x2000, seed = 0x2000, v50 > 0x2000) || (v49 = 2 * v9, seed = 2 * v9, v50 > 0) )
  {
    hkArrayUtil::_reserve(
      (hkResult *)&densityFunction,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&pointsa.m_data,
      v49,
      16);
    m_capacityAndFlags = pointsa.m_capacityAndFlags;
    v49 = seed;
  }
  v52 = 0;
  LODWORD(densityFunction) = 0;
  if ( v7 <= 0 )
  {
LABEL_79:
    pointsa.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        pointsa.m_data,
        16 * m_capacityAndFlags);
    pointsa.m_data = 0i64;
    pointsa.m_capacityAndFlags = 0x80000000;
    v116.m_nodes.m_size = 0;
    if ( v116.m_nodes.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v116.m_nodes.m_data,
        v116.m_nodes.m_capacityAndFlags << 6);
    v116.m_nodes.m_data = 0i64;
    v116.m_nodes.m_capacityAndFlags = 0x80000000;
    v119 = 0;
    if ( v120 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v120);
    goto LABEL_85;
  }
  while ( 1 )
  {
    pointsa.m_size = 0;
    if ( !hkGeometryProcessingInternals::generateRandomDistribution(&mesh, v49, &pointsa, &rndGenerator) )
      break;
    v53 = 0;
    if ( pointsa.m_size > 0 )
    {
      v54 = 0i64;
      do
      {
        stackInstance.m_stack.m_data = (unsigned __int64 *)v121;
        v121[0] = 0i64;
        v127 = xmmword_141A712A0;
        v128 = 0;
        tree.m_nodes.m_data = 0i64;
        tree.m_nodes.m_size = 0;
        *(hkVector4f *)&stackInstance.m_stack.m_localMemory = pointsa.m_data[v54];
        tree.m_nodes.m_capacityAndFlags = 0x80000000;
        tree.m_numLeaves = 64;
        Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        m_cur = (hkcdDynamicTree::CodecRawUlong *)Value->m_cur;
        v58 = m_cur + 8;
        if ( Value->m_slabSize < 512 || v58 > Value->m_end )
          m_cur = (hkcdDynamicTree::CodecRawUlong *)hkLifoAllocator::allocateFromNewSlab(Value, 512);
        else
          Value->m_cur = v58;
        tree.m_nodes.m_data = m_cur;
        tree.m_firstFree = (unsigned __int64)m_cur;
        tree.m_nodes.m_capacityAndFlags = -2147483584;
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::ClosestFromPointWrapper<hkGeometryProcessingInternals::NearestFeaturePolicy>>(
          (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&v116,
          &tree,
          &stackInstance,
          v56);
        v59 = tree.m_nodes.m_size;
        v60 = (char *)tree.m_firstFree;
        if ( (hkcdDynamicTree::CodecRawUlong *)tree.m_firstFree == tree.m_nodes.m_data )
          v59 = 0;
        tree.m_nodes.m_size = v59;
        v61 = (8 * tree.m_numLeaves + 127) & 0xFFFFFF80;
        v62 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v63 = (v61 + 15) & 0xFFFFFFF0;
        if ( v61 > v62->m_slabSize || &v60[v63] != v62->m_cur || v62->m_firstNonLifoEnd == v60 )
          hkLifoAllocator::slowBlockFree(v62, v60, v63);
        else
          v62->m_cur = v60;
        tree.m_nodes.m_size = 0;
        if ( tree.m_nodes.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            tree.m_nodes.m_data,
            8 * tree.m_nodes.m_capacityAndFlags);
        if ( v121[0] )
        {
          v64 = *(__m128 **)(v121[0] + 48);
          v6.m128_f32[0] = v11->vfptr->evaluate(v11, &pointsa.m_data[v53]);
          v6 = _mm_shuffle_ps(v6, v6, 0);
          pointsa.m_data[v54].m_quad = _mm_mul_ps(v6, pointsa.m_data[v54].m_quad);
          pointsa.m_data[v54].m_quad = _mm_shuffle_ps(
                                         pointsa.m_data[v54].m_quad,
                                         _mm_unpackhi_ps(pointsa.m_data[v54].m_quad, v6),
                                         196);
          *v64 = _mm_add_ps(pointsa.m_data[v54].m_quad, *v64);
        }
        ++v53;
        ++v54;
      }
      while ( v53 < pointsa.m_size );
      v52 = (int)densityFunction;
      v15 = (hkVector4f *)tree.m_root;
      v7 = v132;
    }
    if ( (int)numPoints > 0 )
    {
      v65 = 0i64;
      v66 = &v15->m_quad;
      v121[0] = numPoints;
      do
      {
        v67 = *v66;
        v68 = _mm_mul_ps(_mm_div_ps(query.m_quad, _mm_shuffle_ps(v67, v67, 255)), *v66);
        *v66 = v68;
        v69 = v116.m_nodes.m_data;
        v70 = v116.m_root;
        v71 = *(_QWORD *)&array[v65];
        v72 = v71 << 6;
        v73.m_quad = (__m128)v116.m_nodes.m_data[v71].m_aabb.m_min;
        v74.m_quad = (__m128)v116.m_nodes.m_data[v71].m_aabb.m_max;
        v75 = _mm_srli_si128(_mm_slli_si128((__m128i)_mm_sub_ps(v68, aabbOut.m_quad), 4), 4);
        v76 = _mm_srli_si128(_mm_slli_si128((__m128i)_mm_add_ps(aabbOut.m_quad, v68), 4), 4);
        if ( v71 == v116.m_root )
        {
          v116.m_root = 0i64;
        }
        else
        {
          v77 = &v116.m_nodes.m_data[*(unsigned __int64 *)((char *)&v116.m_nodes.m_data->m_parent + v72)];
          m_parent = v77->m_parent;
          v79 = &v116.m_nodes.m_data[v77->m_aabb.m_min.m_quad.m128_u64[6i64
                                                                     - (v77->m_children[1] == *(_QWORD *)&array[v65])]];
          if ( m_parent )
          {
            v79->m_parent = m_parent;
            v116.m_nodes.m_data[v77->m_parent].m_children[v116.m_nodes.m_data[v77->m_parent].m_children[1] == *(unsigned __int64 *)((char *)&v69->m_parent + v72)] = v79 - v116.m_nodes.m_data;
            v80 = *(unsigned __int64 *)((char *)&v69->m_parent + v72);
            v116.m_nodes.m_data[(__int64)(int)v80].m_aabb.m_min.m_quad.m128_u64[0] = v116.m_firstFree;
            v69 = v116.m_nodes.m_data;
            v116.m_firstFree = v80;
            v81 = &v116.m_nodes.m_data[v79->m_parent];
            while ( 1 )
            {
              v82 = v81->m_parent;
              v83 = (__m128 *)((char *)&v69->m_aabb.m_min.m_quad + (((char *)v81 - (char *)v69) & 0xFFFFFFFFFFFFFFC0ui64));
              v84 = v83[2].m128_u64[1] << 6;
              v85 = *(__m128 *)((char *)&v69->m_aabb.m_min.m_quad + v84);
              v86 = *(__m128 *)((char *)&v69->m_aabb.m_max.m_quad + v84);
              v87 = v83[3].m128_u64[0] << 6;
              v88 = _mm_min_ps(v85, *(__m128 *)((char *)&v69->m_aabb.m_min.m_quad + v87));
              v67 = _mm_max_ps(v86, *(__m128 *)((char *)&v69->m_aabb.m_max.m_quad + v87));
              *v83 = v88;
              v83[1] = v67;
              if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v74.m_quad, v67), _mm_cmple_ps(v88, v73.m_quad))) & 7) == 7
                || !v82 )
              {
                break;
              }
              v69 = v116.m_nodes.m_data;
              v81 = &v116.m_nodes.m_data[v82];
              if ( !v81 )
                goto LABEL_60;
            }
            v69 = v116.m_nodes.m_data;
          }
          else
          {
            v116.m_nodes.m_data[(__int64)SLODWORD(v116.m_root)].m_aabb.m_min.m_quad.m128_u64[0] = v116.m_firstFree;
            v116.m_firstFree = v70;
            v116.m_root = v79 - v116.m_nodes.m_data;
            v79->m_parent = 0i64;
            v69 = v116.m_nodes.m_data;
          }
        }
LABEL_60:
        *(__m128i *)((char *)&v69->m_aabb.m_min + v72) = v75;
        *(__m128i *)((char *)&v69->m_aabb.m_max + v72) = v76;
        v89 = v116.m_nodes.m_data;
        v90 = v116.m_root;
        v91 = *(__m128 *)((char *)&v116.m_nodes.m_data->m_aabb.m_min.m_quad + v72);
        v92 = *(__m128 *)((char *)&v116.m_nodes.m_data->m_aabb.m_max.m_quad + v72);
        if ( v116.m_root )
        {
          v93 = v116.m_firstFree;
          if ( !v116.m_firstFree )
          {
            hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
              &v116,
              (hkResult *)&result,
              1);
            v93 = v116.m_firstFree;
            v89 = v116.m_nodes.m_data;
          }
          v94 = &v89[v90].m_aabb.m_min.m_quad;
          v95 = &v89[v93];
          v116.m_firstFree = v89[(__int64)SLODWORD(v116.m_firstFree)].m_aabb.m_min.m_quad.m128_u64[0];
          if ( v94[2].m128_i32[2] )
          {
            v96 = _mm_add_ps(v92, v91);
            v97 = _mm_sub_ps(v92, v91);
            do
            {
              v98 = v94[1];
              v99 = (__int64)&v89[v94[3].m128_u64[0]];
              v100 = (__int64)&v89[v94[2].m128_u64[1]];
              *v94 = _mm_min_ps(*v94, v91);
              v125[1] = v99;
              v125[0] = v100;
              v94[1] = _mm_max_ps(v98, v92);
              v89 = v116.m_nodes.m_data;
              v101 = *(__m128 *)(v100 + 16);
              v102 = *(__m128 *)(v99 + 16);
              v103 = _mm_add_ps(_mm_sub_ps(v101, *(__m128 *)v100), v97);
              v104 = _mm_add_ps(_mm_sub_ps(v102, *(__m128 *)v99), v97);
              v105 = _mm_sub_ps(_mm_add_ps(v101, *(__m128 *)v100), v96);
              v106 = _mm_mul_ps(v105, v105);
              v107 = _mm_sub_ps(_mm_add_ps(v102, *(__m128 *)v99), v96);
              v108 = _mm_mul_ps(v107, v107);
              v94 = (__m128 *)v125[(float)((float)((float)(_mm_shuffle_ps(v103, v103, 85).m128_f32[0]
                                                         + _mm_shuffle_ps(v103, v103, 0).m128_f32[0])
                                                 + _mm_shuffle_ps(v103, v103, 170).m128_f32[0])
                                         * (float)((float)(_mm_shuffle_ps(v106, v106, 85).m128_f32[0]
                                                         + _mm_shuffle_ps(v106, v106, 0).m128_f32[0])
                                                 + _mm_shuffle_ps(v106, v106, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v104, v104, 85).m128_f32[0] + _mm_shuffle_ps(v104, v104, 0).m128_f32[0]) + _mm_shuffle_ps(v104, v104, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v108, v108, 85).m128_f32[0] + _mm_shuffle_ps(v108, v108, 0).m128_f32[0]) + _mm_shuffle_ps(v108, v108, 170).m128_f32[0]))];
            }
            while ( v94[2].m128_i32[2] );
            v11 = v124;
          }
          v109 = v94[2].m128_u64[0];
          v110 = v95 - v89;
          if ( v109 )
            v89[v109].m_children[v89[v109].m_children[1] == ((char *)v94 - (char *)v89) >> 6] = v110;
          else
            v116.m_root = v95 - v89;
          v95->m_parent = v94[2].m128_u64[0];
          v111 = (char *)v94 - (char *)v116.m_nodes.m_data;
          v95->m_children[1] = v71;
          v95->m_children[0] = v111 >> 6;
          v94[2].m128_u64[0] = v110;
          *(unsigned __int64 *)((char *)&v116.m_nodes.m_data->m_parent + v72) = v110;
          v67 = _mm_max_ps(v94[1], v92);
          v95->m_aabb.m_min.m_quad = _mm_min_ps(*v94, v91);
          v95->m_aabb.m_max.m_quad = v67;
        }
        else
        {
          v116.m_root = v71;
          *(unsigned __int64 *)((char *)&v116.m_nodes.m_data->m_parent + v72) = 0i64;
        }
        v112 = v11->vfptr->evaluate(v11, v15);
        ++v66;
        ++v15;
        v65 += 8i64;
        v47 = v121[0]-- == 1;
        v67.m128_f32[0] = v112;
        v113 = _mm_shuffle_ps(v67, v67, 0);
        v114 = _mm_mul_ps(v113, v66[-1]);
        v6 = _mm_shuffle_ps(v114, _mm_unpackhi_ps(v114, v113), 196);
        v66[-1] = v6;
      }
      while ( !v47 );
      v52 = (int)densityFunction;
      v7 = v132;
    }
    v49 = seed;
    v15 = (hkVector4f *)tree.m_root;
    LODWORD(densityFunction) = ++v52;
    if ( v52 >= v7 )
    {
      m_capacityAndFlags = pointsa.m_capacityAndFlags;
      goto LABEL_79;
    }
  }
  pointsa.m_size = 0;
  if ( pointsa.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      pointsa.m_data,
      16 * pointsa.m_capacityAndFlags);
  pointsa.m_data = 0i64;
  pointsa.m_capacityAndFlags = 0x80000000;
  v116.m_nodes.m_size = 0;
  if ( v116.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v116.m_nodes.m_data,
      v116.m_nodes.m_capacityAndFlags << 6);
  v116.m_nodes.m_data = 0i64;
  v116.m_nodes.m_capacityAndFlags = 0x80000000;
  v119 = 0;
  if ( v120 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v120);
  v14 = 0;
LABEL_86:
  hkgpMesh::~hkgpMesh(&mesh);
  return v14;
}.m_data = 0i64;
  pointsa.m_capacityAndFlags = 0x80000000;
  v116.m_nodes.m_size = 0;
  if ( v116.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v116.m_nodes.m_data,
      v116.m_nodes.m_capacityAndFlags << 6);
  v116.m_nodes.m_data = 0i64;
  v116.m_nodes.m_capacityAndFlags = 0x80000000;
  v119 = 0;
  if ( v120 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v120);
  v14 = 0;
LABEL_86:
  hkgpMesh::~hkgpMesh(&mesh);

// File Line: 545
// RVA: 0xCBBCC0
void __fastcall hkGeometryProcessing::normalizeAspectRatio(hkAabb *box)
{
  hkVector4f v1; // xmm3
  __m128 v2; // xmm2
  __m128 v3; // xmm3
  __m128 v4; // xmm3

  v1.m_quad = (__m128)box->m_max;
  v2 = _mm_mul_ps(_mm_add_ps(box->m_min.m_quad, v1.m_quad), (__m128)xmmword_141A711B0);
  v3 = (__m128)_mm_srli_epi32(
                 _mm_slli_epi32(
                   (__m128i)_mm_mul_ps(_mm_sub_ps(v1.m_quad, box->m_min.m_quad), (__m128)xmmword_141A711B0),
                   1u),
                 1u);
  v4 = (__m128)_mm_srli_si128(
                 _mm_slli_si128(
                   (__m128i)_mm_max_ps(
                              _mm_shuffle_ps(v3, v3, 170),
                              _mm_max_ps(_mm_shuffle_ps(v3, v3, 85), _mm_shuffle_ps(v3, v3, 0))),
                   4),
                 4);
  box->m_min.m_quad = _mm_sub_ps(v2, v4);
  box->m_max.m_quad = _mm_add_ps(v2, v4);
}

// File Line: 558
// RVA: 0xCBBD20
hkVector4f *__fastcall hkGeometryProcessing::sampleAabb(hkVector4f *result, hkAabb *box, hkVector4f *unitLocation)
{
  hkVector4f *v3; // rax

  v3 = result;
  result->m_quad = _mm_add_ps(
                     _mm_mul_ps(_mm_sub_ps(box->m_max.m_quad, box->m_min.m_quad), unitLocation->m_quad),
                     box->m_min.m_quad);
  return v3;
}

// File Line: 566
// RVA: 0xCBBD40
void __fastcall hkGeometryProcessing::octahedronToNormal(hkVector4f *uv, hkVector4f *normal)
{
  __m128 m_quad; // xmm7
  __m128 v3; // xmm8
  __m128 v4; // xmm7
  __m128 v5; // xmm8
  __m128 v6; // xmm3
  __m128 v7; // xmm6
  __m128 v8; // xmm2
  __m128 v9; // xmm5
  __m128 v10; // xmm12
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm6
  __m128 v14; // xmm4
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __m128 v19; // xmm3
  __m128 v20; // xmm12
  __m128 v21; // xmm6
  __m128 v22; // xmm2
  __m128 v23; // xmm11
  __m128 v24; // xmm0
  __m128i si128; // xmm6
  __m128 v26; // xmm14
  __m128 v27; // xmm1
  __m128i v28; // xmm8
  __m128 v29; // xmm10
  __m128 v30; // xmm9
  __m128 v31; // xmm2
  __m128i v32; // xmm6
  __m128 v33; // xmm1
  __m128 v34; // xmm5
  __m128 v35; // xmm4
  __m128 v36; // xmm2
  __m128 v37; // xmm3

  m_quad = uv->m_quad;
  v3 = _mm_shuffle_ps(m_quad, m_quad, 0);
  v4 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), (__m128)xmmword_141A710D0), query.m_quad);
  v5 = _mm_sub_ps(_mm_mul_ps(v3, (__m128)xmmword_141A710D0), query.m_quad);
  v6 = _mm_add_ps(v4, v5);
  v7 = _mm_sub_ps(v4, v5);
  if ( v4.m128_f32[0] < 0.0 )
  {
    if ( v5.m128_f32[0] >= 0.0 )
    {
      v20 = _mm_cmple_ps(g_vectorfConstants[0], v7);
      v9 = _mm_or_ps(
             _mm_andnot_ps(v20, _mm_add_ps(v7, (__m128)xmmword_141A710D0)),
             _mm_and_ps(_mm_sub_ps((__m128)0i64, v7), v20));
      v21 = _mm_or_ps(_mm_andnot_ps(v20, _mm_add_ps(v4, query.m_quad)), _mm_and_ps(v20, v5));
      v22 = _mm_rcp_ps(v9);
      v10 = _mm_or_ps(_mm_andnot_ps(v20, g_vectorfConstants[0]), _mm_and_ps(v20, query.m_quad));
      v13 = _mm_add_ps(
              _mm_mul_ps(v21, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v9)), v22)),
              (__m128)xmmword_141A710E0);
    }
    else
    {
      v17 = _mm_cmple_ps(g_vectorfConstants[0], v6);
      v9 = _mm_or_ps(
             _mm_andnot_ps(v17, _mm_add_ps(v6, (__m128)xmmword_141A710D0)),
             _mm_and_ps(_mm_sub_ps((__m128)0i64, v6), v17));
      v10 = _mm_or_ps(_mm_andnot_ps(v17, g_vectorfConstants[0]), _mm_and_ps(v17, query.m_quad));
      v18 = _mm_rcp_ps(v9);
      v19 = _mm_mul_ps(
              _mm_or_ps(_mm_andnot_ps(v17, _mm_add_ps(v5, query.m_quad)), _mm_and_ps(v17, v4)),
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v18)), v18));
      v13 = _mm_or_ps(
              _mm_andnot_ps(v17, _mm_add_ps(v19, (__m128)xmmword_141A710D0)),
              _mm_and_ps(_mm_sub_ps((__m128)xmmword_141A710D0, v19), v17));
    }
  }
  else if ( v5.m128_f32[0] < 0.0 )
  {
    v14 = _mm_cmple_ps(v7, query.m_quad);
    v9 = _mm_or_ps(_mm_andnot_ps(v14, _mm_sub_ps((__m128)xmmword_141A710D0, v7)), _mm_and_ps(v14, v7));
    v10 = _mm_or_ps(_mm_andnot_ps(v14, g_vectorfConstants[0]), _mm_and_ps(v14, query.m_quad));
    v15 = _mm_rcp_ps(v9);
    v16 = _mm_mul_ps(
            _mm_or_ps(_mm_andnot_ps(v14, _mm_sub_ps(query.m_quad, v4)), _mm_and_ps(v14, v5)),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v15)), v15));
    v13 = _mm_or_ps(_mm_andnot_ps(v14, _mm_add_ps(v16, query.m_quad)), _mm_and_ps(_mm_sub_ps(query.m_quad, v16), v14));
  }
  else
  {
    v8 = _mm_cmple_ps(v6, query.m_quad);
    v9 = _mm_or_ps(_mm_andnot_ps(v8, _mm_sub_ps((__m128)xmmword_141A710D0, v6)), _mm_and_ps(v8, v6));
    v10 = _mm_or_ps(_mm_andnot_ps(v8, g_vectorfConstants[0]), _mm_and_ps(v8, query.m_quad));
    v11 = _mm_or_ps(_mm_andnot_ps(v8, _mm_sub_ps(query.m_quad, v5)), _mm_and_ps(v8, v4));
    v12 = _mm_rcp_ps(v9);
    v13 = _mm_mul_ps(v11, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v12)), v12));
  }
  v23 = _mm_mul_ps(v9, v9);
  v24 = _mm_mul_ps((__m128)xmmword_141A713C0, v13);
  si128 = _mm_load_si128((const __m128i *)_xmm);
  v26 = _mm_sub_ps((__m128)xmmword_141A710D0, v23);
  v27 = _mm_rsqrt_ps(v26);
  v28 = _mm_add_epi32(si128, si128);
  v29 = _mm_add_ps(_mm_andnot_ps(_mm_cmpeq_ps(v9, (__m128)0i64), v24), *(__m128 *)offset_1);
  v30 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v26, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                _mm_mul_ps(*(__m128 *)_xmm, v27)),
              v26)),
          v9);
  v31 = _mm_andnot_ps(*(__m128 *)_xmm, v29);
  v32 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v31, *(__m128 *)_xmm)), si128));
  v33 = _mm_cvtepi32_ps(v32);
  v34 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v32, v28), (__m128i)0i64);
  v35 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v33, *(__m128 *)DP1_0), v31), _mm_mul_ps(v33, *(__m128 *)DP2)),
          _mm_mul_ps(v33, *(__m128 *)DP3));
  v36 = _mm_mul_ps(v35, v35);
  v37 = _mm_xor_ps(
          _mm_or_ps(
            _mm_andnot_ps(
              v34,
              _mm_add_ps(
                _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v36, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v36),
                        *(__m128 *)cosCoeff2_0),
                      v36),
                    v36),
                  _mm_mul_ps(v36, *(__m128 *)_xmm)),
                *(__m128 *)_xmm)),
            _mm_and_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v36, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v36),
                      *(__m128 *)sinCoeff2_0),
                    v36),
                  v35),
                v35),
              v34)),
          _mm_xor_ps(
            (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v28, v28), v32), 0x1Du),
            _mm_and_ps(v29, *(__m128 *)_xmm)));
  normal->m_quad = _mm_movelh_ps(
                     _mm_unpacklo_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v37, v37, 85), v30),
                       _mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), v30)),
                     _mm_unpacklo_ps(_mm_mul_ps(_mm_sub_ps(query.m_quad, v23), v10), aabbOut.m_quad));
}

// File Line: 624
// RVA: 0xCBC170
void __fastcall hkGeometryProcessing::normalToOctahedron(hkVector4f *normal, hkVector4f *uv)
{
  __m128 v2; // xmm1
  __m128 v3; // xmm8
  __m128 v4; // xmm2
  __m128 v5; // xmm4
  __m128 v6; // xmm7
  __m128 v7; // xmm6
  __m128 v8; // xmm3
  __m128 v9; // xmm2
  __m128 v10; // xmm6
  __m128 v11; // xmm4
  __m128 v12; // xmm2
  __m128 v13; // xmm6
  unsigned int v14; // xmm0_4
  __m128 v15; // xmm6
  __m128 v16; // xmm4
  __m128 v17; // xmm6
  __m128 v18; // xmm1
  __m128 v19; // xmm5
  __m128 v20; // xmm9
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  __m128 v24; // xmm10
  __m128 v25; // xmm0
  __m128 v26; // xmm4
  __m128 v27; // xmm0
  __m128 v28; // xmm5
  __m128 v29; // xmm3
  __m128 v30; // xmm1
  __m128 v31; // xmm5
  __m128 v32; // xmm1
  __m128 v33; // xmm10
  __m128 v34; // xmm1
  __m128 v35; // xmm2

  v2 = _mm_rcp_ps((__m128)normal->m_quad.m128_u32[0]);
  v3 = (__m128)normal->m_quad.m128_u32[1];
  v4 = _mm_mul_ps(v2, v3);
  v5 = _mm_or_ps(_mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v4), _mm_cmplt_ps(*(__m128 *)_xmm, v4));
  v6 = _mm_cmple_ps((__m128)0i64, v2);
  v7 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v4), v5), _mm_andnot_ps(v5, v4));
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_mul_ps(
         _mm_rcp_ps(
           _mm_add_ps(
             _mm_mul_ps(
               _mm_rcp_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_rcp_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v8, *(__m128 *)s0)), *(__m128 *)t0),
                         _mm_add_ps(v8, *(__m128 *)s1))),
                     *(__m128 *)t1),
                   _mm_add_ps(v8, *(__m128 *)s2))),
               *(__m128 *)t2),
             _mm_add_ps(v8, *(__m128 *)s3))),
         _mm_mul_ps(v7, *(__m128 *)t3));
  v10 = _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v7, *(__m128 *)_xmm), *(__m128 *)_xmm), v9), v5);
  v11 = _mm_andnot_ps(v5, v9);
  v12 = _mm_rcp_ps((__m128)xmmword_141A713B0);
  v13 = _mm_or_ps(v10, v11);
  v14 = _mm_andnot_ps(v6, _mm_add_ps(_mm_or_ps(_mm_and_ps(v3, *(__m128 *)_xmm), *(__m128 *)_xmm), v13)).m128_u32[0] | v13.m128_i32[0] & v6.m128_i32[0];
  v15 = _mm_shuffle_ps(normal->m_quad, normal->m_quad, 170);
  v16 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v12, (__m128)xmmword_141A713B0)), v12),
          _mm_mul_ps(_mm_shuffle_ps((__m128)v14, (__m128)v14, 0), (__m128)xmmword_141A710D0));
  if ( v15.m128_f32[0] >= 0.0 )
  {
    v29 = _mm_sub_ps(query.m_quad, v15);
    v30 = _mm_rsqrt_ps(v29);
    v31 = _mm_andnot_ps(
            _mm_cmple_ps(v29, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                _mm_mul_ps(*(__m128 *)_xmm, v30)),
              v29));
    if ( v16.m128_f32[0] < 0.0 )
    {
      v33 = _mm_cmplt_ps(g_vectorfConstants[0], v16);
      v23 = _mm_or_ps(
              _mm_andnot_ps(v33, _mm_mul_ps(_mm_add_ps(v16, (__m128)xmmword_141A710D0), _mm_sub_ps((__m128)0i64, v31))),
              _mm_and_ps(_mm_mul_ps(v16, v31), v33));
      v34 = _mm_add_ps(v23, v31);
      v22 = _mm_or_ps(_mm_andnot_ps(v33, _mm_sub_ps((__m128)0i64, v34)), _mm_and_ps(v33, v34));
    }
    else
    {
      v32 = _mm_cmplt_ps(v16, query.m_quad);
      v23 = _mm_or_ps(
              _mm_andnot_ps(v32, _mm_mul_ps(_mm_sub_ps((__m128)xmmword_141A710D0, v16), v31)),
              _mm_and_ps(_mm_mul_ps(v16, v31), v32));
      v22 = _mm_or_ps(_mm_andnot_ps(v32, _mm_sub_ps(v23, v31)), _mm_and_ps(_mm_sub_ps(v31, v23), v32));
    }
  }
  else
  {
    v17 = _mm_add_ps(v15, query.m_quad);
    v18 = _mm_rsqrt_ps(v17);
    v19 = _mm_andnot_ps(
            _mm_cmple_ps(v17, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                _mm_mul_ps(*(__m128 *)_xmm, v18)),
              v17));
    if ( v16.m128_f32[0] < 0.0 )
    {
      v24 = _mm_cmple_ps(g_vectorfConstants[0], v16);
      v25 = v16;
      v26 = _mm_add_ps(_mm_mul_ps(v16, v19), query.m_quad);
      v27 = _mm_sub_ps(_mm_mul_ps(_mm_add_ps(v25, (__m128)xmmword_141A710D0), v19), query.m_quad);
      v28 = _mm_sub_ps(v19, (__m128)xmmword_141A710D0);
      v22 = _mm_or_ps(_mm_andnot_ps(v24, v27), _mm_and_ps(v26, v24));
      v23 = _mm_or_ps(_mm_andnot_ps(v24, _mm_sub_ps(v28, v22)), _mm_and_ps(_mm_add_ps(v22, v28), v24));
    }
    else
    {
      v20 = _mm_sub_ps((__m128)xmmword_141A710D0, v19);
      v21 = _mm_cmple_ps(v16, query.m_quad);
      v22 = _mm_or_ps(
              _mm_andnot_ps(v21, _mm_sub_ps(_mm_mul_ps(_mm_sub_ps((__m128)xmmword_141A710D0, v16), v19), query.m_quad)),
              _mm_and_ps(_mm_sub_ps(query.m_quad, _mm_mul_ps(v16, v19)), v21));
      v23 = _mm_or_ps(_mm_andnot_ps(v21, _mm_add_ps(v22, v20)), _mm_and_ps(_mm_sub_ps(v20, v22), v21));
    }
  }
  v35 = _mm_movelh_ps(
          _mm_unpacklo_ps(_mm_add_ps(v22, query.m_quad), _mm_add_ps(v23, query.m_quad)),
          _mm_unpacklo_ps((__m128)0i64, (__m128)0i64));
  *uv = (hkVector4f)v35;
  uv->m_quad = _mm_mul_ps(v35, (__m128)xmmword_141A711B0);
}

// File Line: 670
// RVA: 0xCBC4B0
void __fastcall hkGeometryProcessing::wrapOctahedronCoordinates(hkVector4f *uv)
{
  ;
}

// File Line: 676
// RVA: 0xCBC4C0
hkSimdFloat32 *__fastcall hkGeometryProcessing::computeTriangleQuality(
        hkSimdFloat32 *result,
        hkVector4f *p0,
        hkVector4f *p1,
        hkVector4f *p2)
{
  __m128 v4; // xmm9
  __m128 v5; // xmm0
  __m128 v6; // xmm8
  __m128 v7; // xmm1
  __m128 v8; // xmm8
  __m128 v9; // xmm0
  __m128 v10; // xmm9
  __m128 v11; // xmm1
  __m128 v12; // xmm1
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm7
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  __m128 v19; // xmm3
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  hkSimdFloat32 *v22; // rax

  v4 = _mm_sub_ps(p2->m_quad, p0->m_quad);
  v5 = _mm_sub_ps(p1->m_quad, p0->m_quad);
  v6 = _mm_sub_ps(p0->m_quad, p1->m_quad);
  v7 = _mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), v5);
  v8 = _mm_mul_ps(v6, v6);
  v9 = _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v4);
  v10 = _mm_mul_ps(v4, v4);
  v11 = _mm_sub_ps(v7, v9);
  v12 = _mm_shuffle_ps(v11, v11, 201);
  v13 = _mm_mul_ps(v12, v12);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_rsqrt_ps(v14);
  v16 = _mm_andnot_ps(
          _mm_cmple_ps(v14, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
              _mm_mul_ps(*(__m128 *)_xmm, v15)),
            v14));
  v17 = _mm_sub_ps(p1->m_quad, p2->m_quad);
  v18 = _mm_mul_ps(v17, v17);
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170)),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
              _mm_shuffle_ps(v18, v18, 170))),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
            _mm_shuffle_ps(v10, v10, 170)));
  v20 = _mm_rcp_ps(v19);
  v21 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v20, v19)), v20),
          _mm_mul_ps(v16, _mm_shuffle_ps((__m128)LODWORD(FLOAT_3_4641016), (__m128)LODWORD(FLOAT_3_4641016), 0)));
  *result = (hkSimdFloat32)v21;
  v22 = result;
  result->m_real = _mm_and_ps(_mm_cmplt_ps((__m128)xmmword_141A712D0, v19), v21);
  return v22;
}

// File Line: 685
// RVA: 0xCBC640
hkVector4f *__fastcall hkGeometryProcessing::computeMedian(hkVector4f *result, hkVector4f *a, hkVector4f *b)
{
  hkVector4f *v3; // rax

  v3 = result;
  result->m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(b->m_quad, a->m_quad), (__m128)xmmword_141A711B0), a->m_quad);
  return v3;
}

// File Line: 692
// RVA: 0xCBC660
hkVector4f *__fastcall hkGeometryProcessing::computeMedian(
        hkVector4f *result,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c)
{
  hkVector4f *v4; // rax

  v4 = result;
  result->m_quad = _mm_mul_ps(_mm_add_ps(_mm_add_ps(a->m_quad, b->m_quad), c->m_quad), (__m128)xmmword_141A711C0);
  return v4;
}

// File Line: 702
// RVA: 0xCBC680
hkVector4f *__fastcall hkGeometryProcessing::computeMedian(
        hkVector4f *result,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c,
        hkVector4f *d)
{
  hkVector4f *v5; // rax

  v5 = result;
  result->m_quad = _mm_mul_ps(
                     _mm_add_ps(_mm_add_ps(c->m_quad, d->m_quad), _mm_add_ps(a->m_quad, b->m_quad)),
                     (__m128)xmmword_141A711D0);
  return v5;
}

// File Line: 712
// RVA: 0xCBC6B0
void __fastcall hkGeometryProcessing::weldVertices(hkGeometry *geometry)
{
  hkgpMesh v2; // [rsp+30h] [rbp-A8h] BYREF

  hkgpMesh::hkgpMesh(&v2);
  hkgpMesh::appendFromGeometry(&v2, geometry, (hkTransformf *)&transform, -1, 0, 0);
  hkGeometry::clear(geometry);
  hkgpMesh::appendToGeometry(&v2, geometry, 0);
  hkgpMesh::~hkgpMesh(&v2);
}

// File Line: 721
// RVA: 0xCBC720
hkBool *__fastcall hkGeometryProcessing::isGeometryClosed(hkBool *result, hkGeometry *geometry)
{
  hkgpIndexedMesh v5; // [rsp+20h] [rbp-98h] BYREF

  hkgpIndexedMesh::hkgpIndexedMesh(&v5);
  hkgpIndexedMesh::appendFromGeometry(&v5, geometry);
  result->m_bool = v5.m_nakedEdges == 0;
  hkgpIndexedMesh::~hkgpIndexedMesh(&v5);
  return result;
}

// File Line: 729
// RVA: 0xCBC780
void __fastcall hkGeometryProcessing::generateClusters(
        hkArray<hkVector4f,hkContainerHeapAllocator> *data,
        hkArray<hkSimdFloat32,hkContainerHeapAllocator> *weights,
        int numClusters,
        hkArray<int,hkContainerHeapAllocator> *clusterIds,
        int maxIterations)
{
  __int64 m_size; // rbx
  __int64 v7; // rsi
  int v9; // eax
  int v11; // eax
  int v12; // r9d
  __int64 v13; // r9
  int v14; // r8d
  __int64 i; // rcx
  int v16; // eax
  __m128 *v17; // rcx
  int v18; // edx
  int j; // r8d
  __m128 *v20; // rax
  __m128 *k; // rcx
  __m128 *v22; // rax
  int v23; // r13d
  int v24; // r12d
  __int64 v25; // r8
  __int64 v26; // rdx
  __m128 m_real; // xmm1
  __int64 v28; // r8
  __int64 v29; // rdx
  __int64 v30; // rcx
  __int64 v31; // rdx
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  int v34; // r11d
  int v35; // r10d
  __int64 v36; // r8
  __m128i si128; // xmm10
  __m128 v38; // xmm5
  __m128i v39; // xmm4
  __m128i v40; // xmm6
  __int64 v41; // rcx
  __m128 *v42; // rax
  __m128 v43; // xmm1
  __m128 v44; // xmm1
  __m128 v45; // xmm0
  __m128 v46; // xmm3
  __m128i v47; // xmm2
  __m128 *v48; // [rsp+28h] [rbp-51h] BYREF
  int v49; // [rsp+30h] [rbp-49h]
  int v50; // [rsp+34h] [rbp-45h]
  __m128 *array; // [rsp+38h] [rbp-41h] BYREF
  int v52; // [rsp+40h] [rbp-39h]
  int v53; // [rsp+44h] [rbp-35h]
  hkResult result; // [rsp+E8h] [rbp+6Fh] BYREF
  __int64 v55; // [rsp+F8h] [rbp+7Fh]

  m_size = data->m_size;
  v7 = numClusters;
  v9 = clusterIds->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < (int)m_size )
  {
    v11 = 2 * v9;
    v12 = data->m_size;
    if ( (int)m_size < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&clusterIds->m_data, v12, 4);
  }
  v13 = 0i64;
  clusterIds->m_size = m_size;
  v14 = 0;
  for ( i = 0i64; i < m_size; clusterIds->m_data[i - 1] = v16 % (int)v7 )
  {
    v16 = v14;
    ++i;
    ++v14;
  }
  array = 0i64;
  v52 = 0;
  v53 = 0x80000000;
  if ( (int)v7 > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v7, 16);
    v13 = 0i64;
  }
  v52 = v7;
  v48 = 0i64;
  v49 = 0;
  v50 = 0x80000000;
  if ( (int)v7 > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v48, v7, 16);
    v13 = 0i64;
  }
  v17 = array;
  v18 = v7 - 1;
  v49 = v7;
  for ( j = v7 - 1; j >= 0; *v20 = 0i64 )
  {
    v20 = v17++;
    --j;
  }
  for ( k = array; v18 >= 0; *v22 = 0i64 )
  {
    v22 = k++;
    --v18;
  }
  v23 = v55;
  v24 = 0;
  if ( (int)v55 > 0 )
  {
    while ( !weights )
    {
      v28 = 0i64;
      if ( m_size > 0 )
      {
        do
        {
          ++v28;
          v13 += 16i64;
          v29 = clusterIds->m_data[v28 - 1];
          v48[v29] = _mm_add_ps(v48[clusterIds->m_data[v28 - 1]], query.m_quad);
          array[v29] = _mm_add_ps(*(__m128 *)((char *)&data->m_data[-1].m_quad + v13), array[v29]);
        }
        while ( v28 < m_size );
LABEL_23:
        v13 = 0i64;
      }
      if ( v7 > 0 )
      {
        v30 = 0i64;
        v31 = v7;
        do
        {
          v32 = v48[v30++];
          v33 = _mm_rcp_ps(v32);
          array[v30 - 1] = _mm_mul_ps(
                             _mm_andnot_ps(
                               _mm_cmpeq_ps(v32, (__m128)0i64),
                               _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v33, v32)), v33)),
                             array[v30 - 1]);
          v48[v30 - 1] = 0i64;
          --v31;
        }
        while ( v31 );
      }
      v34 = 0;
      v35 = 0;
      v36 = 0i64;
      if ( m_size > 0 )
      {
        si128 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
        do
        {
          v38 = (__m128)xmmword_141A712A0;
          v39 = si128;
          v40 = 0i64;
          if ( v7 > 0 )
          {
            v41 = v7;
            v42 = array;
            do
            {
              ++v42;
              v43 = _mm_sub_ps(*(__m128 *)((char *)&data->m_data->m_quad + v13), v42[-1]);
              v44 = _mm_mul_ps(v43, v43);
              v45 = _mm_add_ps(_mm_shuffle_ps(v44, v44, 78), v44);
              v46 = _mm_add_ps(_mm_shuffle_ps(v45, v45, 177), v45);
              v47 = (__m128i)_mm_cmplt_ps(v46, v38);
              v39 = _mm_or_si128(_mm_and_si128(v40, v47), _mm_andnot_si128(v47, v39));
              v38 = _mm_or_ps(_mm_andnot_ps((__m128)v47, v38), _mm_and_ps((__m128)v47, v46));
              v40 = _mm_add_epi32((__m128i)xmmword_141A72090, v40);
              --v41;
            }
            while ( v41 );
          }
          if ( _mm_movemask_ps((__m128)_mm_or_si128(
                                         _mm_cmpgt_epi32(v39, *(__m128i *)&g_intVectorConstants[0][0]),
                                         _mm_cmpeq_epi32(v39, *(__m128i *)&g_intVectorConstants[0][0]))) )
          {
            if ( (_mm_movemask_ps((__m128)_mm_cmpeq_epi32((__m128i)(unsigned int)clusterIds->m_data[v35], v39)) & 1) == 0 )
              ++v34;
            clusterIds->m_data[v35] = v39.m128i_i32[0];
          }
          ++v36;
          ++v35;
          v13 += 16i64;
        }
        while ( v36 < m_size );
        if ( v34 )
        {
          ++v24;
          v13 = 0i64;
          if ( v24 < v23 )
            continue;
        }
      }
      goto LABEL_39;
    }
    if ( m_size > 0 )
    {
      v25 = 0i64;
      do
      {
        ++v13;
        ++v25;
        v26 = clusterIds->m_data[v13 - 1];
        m_real = weights->m_data[v25 - 1].m_real;
        v48[v26] = _mm_add_ps(m_real, v48[clusterIds->m_data[v13 - 1]]);
        array[v26] = _mm_add_ps(_mm_mul_ps(data->m_data[v25 - 1].m_quad, m_real), array[v26]);
      }
      while ( v13 < m_size );
    }
    goto LABEL_23;
  }
LABEL_39:
  v49 = 0;
  if ( v50 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v48, 16 * v50);
  v48 = 0i64;
  v50 = 0x80000000;
  v52 = 0;
  if ( v53 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v53);
}

// File Line: 829
// RVA: 0xCBCC40
void __fastcall hkGeometryProcessing::generateClusters(
        hkArray<float,hkContainerHeapAllocator> *data,
        hkArray<hkSimdFloat32,hkContainerHeapAllocator> *weights,
        int numClusters,
        hkArray<int,hkContainerHeapAllocator> *clusterIds,
        int maxIterations)
{
  int m_size; // edi
  int v10; // edx
  hkVector4f *m_data; // rcx
  int i; // edx
  hkVector4f *v13; // rax
  int v14; // r8d
  __int64 v15; // r9
  __int64 v16; // rcx
  hkVector4f v17; // xmm0
  hkArray<hkVector4f,hkContainerHeapAllocator> dataa; // [rsp+30h] [rbp-28h] BYREF
  hkResult v19; // [rsp+60h] [rbp+8h] BYREF

  m_size = data->m_size;
  dataa.m_data = 0i64;
  dataa.m_size = 0;
  dataa.m_capacityAndFlags = 0x80000000;
  if ( m_size > 0 )
    hkArrayUtil::_reserve(&v19, &hkContainerHeapAllocator::s_alloc, (const void **)&dataa.m_data, m_size, 16);
  v10 = data->m_size;
  m_data = dataa.m_data;
  dataa.m_size = m_size;
  for ( i = v10 - 1; i >= 0; *v13 = 0i64 )
  {
    v13 = m_data++;
    --i;
  }
  v14 = 0;
  if ( data->m_size > 0 )
  {
    v15 = 0i64;
    do
    {
      v16 = v14++;
      v17.m_quad = (__m128)dataa.m_data[v15++];
      v17.m_quad.m128_f32[0] = data->m_data[v16];
      dataa.m_data[v15 - 1] = (hkVector4f)v17.m_quad;
    }
    while ( v14 < data->m_size );
  }
  hkGeometryProcessing::generateClusters(&dataa, weights, numClusters, clusterIds, maxIterations);
  dataa.m_size = 0;
  if ( dataa.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      dataa.m_data,
      16 * dataa.m_capacityAndFlags);
}

// File Line: 842
// RVA: 0xCBCD70
void __fastcall hkGeometryProcessing::generateClusters(
        hkAabb *aabbs,
        int numAabbs,
        int maxClusters,
        hkArray<int,hkContainerHeapAllocator> *clusterRoots,
        hkArray<int,hkContainerHeapAllocator> *clusterNexts)
{
  hkArray<int,hkContainerHeapAllocator> *v5; // r15
  int v6; // ebx
  int v9; // eax
  int v11; // eax
  int v12; // r9d
  __int64 m_size; // rdx
  int *v14; // rdi
  __int64 v15; // rcx
  int v16; // r15d
  int v17; // eax
  int v18; // eax
  int v19; // r9d
  __int64 v20; // rcx
  hkcdDynamicTree::CodecRawUint *m_data; // rdx
  int v22; // r12d
  unsigned int m_firstFree; // esi
  unsigned int v24; // eax
  __int64 v25; // r15
  hkcdDynamicTree::CodecRawUint *v26; // r8
  __int64 m_root; // rdi
  hkVector4f v28; // xmm7
  hkVector4f v29; // xmm8
  unsigned int v30; // edx
  __m128 *p_m_quad; // r9
  __int64 v32; // rax
  hkcdDynamicTree::CodecRawUint *v33; // r11
  __m128 v34; // xmm9
  __m128 v35; // xmm10
  __int64 v36; // rcx
  __m128 v37; // xmm1
  __m128 *v38; // rcx
  __m128 v39; // xmm3
  __m128 v40; // xmm2
  __m128 v41; // xmm2
  __m128 v42; // xmm5
  __m128 v43; // xmm3
  __m128 v44; // xmm3
  __m128 v45; // xmm6
  __m128 v46; // xmm6
  __int64 v47; // r10
  int v48; // eax
  signed __int64 v49; // rcx
  __m128 v50; // xmm1
  unsigned int v51; // ecx
  int v52; // r11d
  unsigned int v53; // r8d
  unsigned int v54; // ecx
  unsigned int m_parent; // edx
  unsigned int i; // edi
  int m_free; // esi
  hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::Node *v58; // rdx
  hkcdDynamicTree::CodecRawUint *v59; // r9
  hkcdDynamicTree::CodecRawUint *v60; // r14
  __int64 v61; // r9
  int v62; // r11d
  unsigned int v63; // r8d
  unsigned int v64; // ecx
  unsigned int v65; // edx
  unsigned int j; // edi
  __int64 v67; // rcx
  int v68; // edi
  hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::Node *v69; // r9
  int m_value; // r8d
  hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::Node *v71; // rdx
  int v72; // ecx
  int v73; // eax
  BOOL v74; // ecx
  int v75; // eax
  __int64 v76; // r9
  int v77; // r11d
  unsigned int v78; // r8d
  unsigned int v79; // ecx
  unsigned int v80; // edx
  unsigned int k; // edi
  __int64 v82; // rax
  int v83; // r13d
  int *m_children; // rcx
  __int64 v85; // r15
  hkArray<int,hkContainerHeapAllocator> *v86; // r12
  int v87; // r10d
  __int64 m_index; // rsi
  unsigned int v89; // edi
  unsigned int v90; // eax
  unsigned int m; // r8d
  int v92; // r8d
  __int64 v93; // rdi
  _DWORD *v94; // rsi
  int v95; // edi
  int v96; // r9d
  __int64 v97; // r8
  int v98; // ecx
  __int64 v99; // rax
  int *v100; // rcx
  int *array; // [rsp+30h] [rbp-D0h] BYREF
  int v102; // [rsp+38h] [rbp-C8h]
  int v103; // [rsp+3Ch] [rbp-C4h]
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> v104; // [rsp+40h] [rbp-C0h] BYREF
  hkGeometryProcessingInternals::ClusterQueueNode value; // [rsp+68h] [rbp-98h] BYREF
  hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16> v106; // [rsp+70h] [rbp-90h] BYREF
  hkGeometryProcessingInternals::ClusterQueueNode v107; // [rsp+A0h] [rbp-60h] BYREF
  __m128 *v108; // [rsp+A8h] [rbp-58h]
  hkcdDynamicTree::DefaultTree48Storage output; // [rsp+B0h] [rbp-50h] BYREF
  hkResult result; // [rsp+178h] [rbp+78h] BYREF
  int count; // [rsp+180h] [rbp+80h]
  void *v112; // [rsp+188h] [rbp+88h]

  v112 = clusterRoots;
  count = maxClusters;
  v5 = clusterNexts;
  v6 = 0;
  clusterRoots->m_size = 0;
  v9 = v5->m_capacityAndFlags & 0x3FFFFFFF;
  v5->m_size = 0;
  if ( v9 < numAabbs )
  {
    v11 = 2 * v9;
    v12 = numAabbs;
    if ( numAabbs < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v5->m_data, v12, 4);
  }
  m_size = v5->m_size;
  v14 = &v5->m_data[m_size];
  v15 = numAabbs - (int)m_size;
  if ( numAabbs - (int)m_size > 0 )
  {
    while ( v15 )
    {
      *v14++ = -1;
      --v15;
    }
  }
  v5->m_size = numAabbs;
  if ( numAabbs )
  {
    v16 = count;
    if ( count < numAabbs )
    {
      v104.m_nodes.m_size = 0;
      m_data = 0i64;
      v22 = 0;
      v104.m_nodes.m_data = 0i64;
      v104.m_nodes.m_capacityAndFlags = 0x80000000;
      m_firstFree = 0;
      v104.m_firstFree = 0;
      v24 = 0;
      *(_QWORD *)&v104.m_path = 0i64;
      v104.m_numLeaves = 0;
      if ( numAabbs > 0 )
      {
        while ( 1 )
        {
          if ( !m_firstFree )
          {
            hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
              &v104,
              &result,
              1);
            m_firstFree = v104.m_firstFree;
            m_data = v104.m_nodes.m_data;
          }
          v104.m_firstFree = m_data[m_firstFree].m_aabb.m_min.m_quad.m128_u32[0];
          v25 = m_firstFree;
          m_data[v25].m_children[0] = 0;
          m_data[v25].m_children[1] = v22;
          m_data[v25].m_aabb.m_min = aabbs->m_min;
          m_data[v25].m_aabb.m_max = aabbs->m_max;
          v26 = v104.m_nodes.m_data;
          m_root = v104.m_root;
          v28.m_quad = (__m128)v104.m_nodes.m_data[m_firstFree].m_aabb.m_min;
          v29.m_quad = (__m128)v104.m_nodes.m_data[m_firstFree].m_aabb.m_max;
          if ( v104.m_root )
          {
            v30 = v104.m_firstFree;
            if ( !v104.m_firstFree )
            {
              hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
                &v104,
                (hkResult *)&value,
                1);
              v30 = v104.m_firstFree;
              v26 = v104.m_nodes.m_data;
            }
            p_m_quad = &v26[m_root].m_aabb.m_min.m_quad;
            v104.m_firstFree = v26[v30].m_aabb.m_min.m_quad.m128_u32[0];
            v32 = p_m_quad[2].m128_u32[1];
            v33 = &v26[v30];
            if ( (_DWORD)v32 )
            {
              v34 = _mm_add_ps(v29.m_quad, v28.m_quad);
              v35 = _mm_sub_ps(v29.m_quad, v28.m_quad);
              do
              {
                v36 = p_m_quad[2].m128_u32[2];
                v37 = _mm_max_ps(p_m_quad[1], v29.m_quad);
                *p_m_quad = _mm_min_ps(*p_m_quad, v28.m_quad);
                p_m_quad[1] = v37;
                v107 = (hkGeometryProcessingInternals::ClusterQueueNode)&v26[v32];
                v38 = &v26[v36].m_aabb.m_min.m_quad;
                v26 = v104.m_nodes.m_data;
                v39 = *(__m128 *)(*(_QWORD *)&v107 + 16i64);
                v40 = _mm_sub_ps(v39, *(__m128 *)v107);
                v108 = v38;
                v41 = _mm_add_ps(v40, v35);
                v42 = _mm_add_ps(_mm_sub_ps(v38[1], *v38), v35);
                v43 = _mm_sub_ps(_mm_add_ps(v39, *(__m128 *)v107), v34);
                v44 = _mm_mul_ps(v43, v43);
                v45 = _mm_sub_ps(_mm_add_ps(v38[1], *v38), v34);
                v46 = _mm_mul_ps(v45, v45);
                p_m_quad = (__m128 *)*((_QWORD *)&v107
                                     + ((float)((float)((float)(_mm_shuffle_ps(v41, v41, 85).m128_f32[0]
                                                              + _mm_shuffle_ps(v41, v41, 0).m128_f32[0])
                                                      + _mm_shuffle_ps(v41, v41, 170).m128_f32[0])
                                              * (float)((float)(_mm_shuffle_ps(v44, v44, 85).m128_f32[0]
                                                              + _mm_shuffle_ps(v44, v44, 0).m128_f32[0])
                                                      + _mm_shuffle_ps(v44, v44, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v42, v42, 85).m128_f32[0] + _mm_shuffle_ps(v42, v42, 0).m128_f32[0]) + _mm_shuffle_ps(v42, v42, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v46, v46, 85).m128_f32[0] + _mm_shuffle_ps(v46, v46, 0).m128_f32[0]) + _mm_shuffle_ps(v46, v46, 170).m128_f32[0]))));
                v32 = p_m_quad[2].m128_u32[1];
              }
              while ( (_DWORD)v32 );
            }
            v47 = v33 - v26;
            v48 = p_m_quad[2].m128_i32[0];
            if ( v48 )
              v26[v48].m_children[v26[v48].m_children[1] == (unsigned int)(((char *)p_m_quad - (char *)v26) / 48)] = v47;
            else
              v104.m_root = v33 - v26;
            v33->m_parent = p_m_quad[2].m128_u32[0];
            v49 = (char *)p_m_quad - (char *)v104.m_nodes.m_data;
            v33->m_children[1] = m_firstFree;
            v33->m_children[0] = v49 / 48;
            p_m_quad[2].m128_i32[0] = v47;
            v104.m_nodes.m_data[m_firstFree].m_parent = v47;
            v50 = _mm_max_ps(p_m_quad[1], v29.m_quad);
            v33->m_aabb.m_min.m_quad = _mm_min_ps(*p_m_quad, v28.m_quad);
            v33->m_aabb.m_max.m_quad = v50;
          }
          else
          {
            v104.m_root = m_firstFree;
            v104.m_nodes.m_data[m_firstFree].m_parent = 0;
          }
          ++v104.m_numLeaves;
          ++v22;
          ++aabbs;
          if ( v22 >= numAabbs )
            break;
          m_firstFree = v104.m_firstFree;
          m_data = v104.m_nodes.m_data;
        }
        v24 = v104.m_root;
        v16 = count;
      }
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::rebuildBranchSAH(&v104, v24, (hkBool)1, 32, 16);
      if ( v104.m_root )
      {
        output.m_nodes.m_size = 0;
        output.m_nodes.m_data = 0i64;
        output.m_nodes.m_capacityAndFlags = 0x80000000;
        output.m_firstFree = 0;
        *(_QWORD *)&output.m_path = 0i64;
        output.m_numLeaves = 0;
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>>(
          &v104,
          &output);
        hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
          (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&output,
          (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v104);
        v51 = output.m_firstFree;
        output.m_firstFree = v104.m_firstFree;
        v104.m_firstFree = v51;
        v104.m_root = 1;
        output.m_nodes.m_size = 0;
        if ( output.m_nodes.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            output.m_nodes.m_data,
            48 * (output.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
      }
      v106.m_nodes.m_data = 0i64;
      v106.m_nodes.m_size = 0;
      v106.m_nodes.m_capacityAndFlags = 0x80000000;
      v106.m_prng.m_x = 123456789;
      v106.m_prng.m_y = 234567891;
      v106.m_prng.m_z = 345678912;
      *(_QWORD *)&v106.m_prng.m_w = 456789123i64;
      hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::clear(
        &v106,
        0);
      hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::preAllocateNodes(
        &v106,
        v16);
      v52 = 0;
      value.m_index = v104.m_root;
      if ( v104.m_root )
      {
        v53 = v104.m_nodes.m_data[v104.m_root].m_children[0];
        if ( v53 )
        {
          do
          {
            v54 = v104.m_nodes.m_data[v53].m_children[0];
            v52 += v54 == 0;
            if ( v54 )
            {
              v53 = v104.m_nodes.m_data[v53].m_children[0];
            }
            else
            {
              m_parent = v104.m_nodes.m_data[v53].m_parent;
              for ( i = v53; m_parent != v104.m_root; m_parent = v104.m_nodes.m_data[m_parent].m_parent )
              {
                if ( v104.m_nodes.m_data[m_parent].m_children[1] != i )
                  break;
                i = m_parent;
              }
              if ( m_parent )
                v53 = v104.m_nodes.m_data[m_parent].m_children[1];
              else
                v53 = i;
              if ( m_parent == v104.m_root && v53 == i )
                v53 = 0;
            }
          }
          while ( v53 );
        }
        else
        {
          v52 = 1;
        }
      }
      value.m_value = v52;
      hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::insert(
        &v106,
        &value);
      if ( v106.m_size >= v16 )
      {
LABEL_103:
        v59 = v104.m_nodes.m_data;
        v58 = v106.m_nodes.m_data;
      }
      else
      {
        while ( 1 )
        {
          m_free = v106.m_root;
          v58 = v106.m_nodes.m_data;
          if ( v106.m_root )
          {
            while ( v106.m_nodes.m_data[m_free].m_children[1] )
              m_free = v106.m_nodes.m_data[m_free].m_children[1];
          }
          v59 = v104.m_nodes.m_data;
          v60 = &v104.m_nodes.m_data[v106.m_nodes.m_data[m_free].m_value.m_index];
          if ( !v60->m_children[0] )
            break;
          hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::removeNode(
            &v106,
            m_free);
          v106.m_nodes.m_data[m_free].m_parent = v106.m_free;
          --v106.m_size;
          v106.m_free = m_free;
          v61 = v60->m_children[0];
          v62 = 0;
          value.m_index = v61;
          if ( (_DWORD)v61 )
          {
            v63 = v104.m_nodes.m_data[v61].m_children[0];
            if ( v63 )
            {
              do
              {
                v64 = v104.m_nodes.m_data[v63].m_children[0];
                v62 += v64 == 0;
                if ( v64 )
                {
                  v63 = v104.m_nodes.m_data[v63].m_children[0];
                }
                else
                {
                  v65 = v104.m_nodes.m_data[v63].m_parent;
                  for ( j = v63; v65 != (_DWORD)v61; v65 = v104.m_nodes.m_data[v65].m_parent )
                  {
                    if ( v104.m_nodes.m_data[v65].m_children[1] != j )
                      break;
                    j = v65;
                  }
                  if ( v65 )
                    v63 = v104.m_nodes.m_data[v65].m_children[1];
                  else
                    v63 = j;
                  if ( v65 == (_DWORD)v61 && v63 == j )
                    v63 = 0;
                }
              }
              while ( v63 );
            }
            else
            {
              v62 = 1;
            }
          }
          value.m_value = v62;
          if ( !m_free )
          {
            hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::preAllocateNodes(
              &v106,
              16);
            m_free = v106.m_free;
          }
          v106.m_free = v106.m_nodes.m_data[m_free].m_parent;
          v67 = m_free;
          v106.m_nodes.m_data[v67].m_value = value;
          v68 = v106.m_root;
          v69 = &v106.m_nodes.m_data[v67];
          if ( v106.m_root )
          {
            m_value = v69->m_value.m_value;
            while ( 1 )
            {
              v71 = &v106.m_nodes.m_data[v68];
              v72 = v71->m_value.m_value;
              v73 = m_value >= v72 ? v72 < m_value : -1;
              v74 = v73 >= 0;
              v75 = v71->m_children[v73 >= 0];
              if ( !v75 )
                break;
              v68 = v75;
            }
            v71->m_children[v74] = m_free;
            v69->m_parent = v68;
          }
          else
          {
            v106.m_root = m_free;
            v69->m_parent = 0;
          }
          *(_QWORD *)v69->m_children = 0i64;
          ++v106.m_size;
          v76 = v60->m_children[1];
          v107.m_index = v76;
          v77 = 0;
          if ( (_DWORD)v76 )
          {
            v78 = v104.m_nodes.m_data[v76].m_children[0];
            if ( v78 )
            {
              do
              {
                v79 = v104.m_nodes.m_data[v78].m_children[0];
                v77 += v79 == 0;
                if ( v79 )
                {
                  v78 = v104.m_nodes.m_data[v78].m_children[0];
                }
                else
                {
                  v80 = v104.m_nodes.m_data[v78].m_parent;
                  for ( k = v78; v80 != (_DWORD)v76; v80 = v104.m_nodes.m_data[v80].m_parent )
                  {
                    if ( v104.m_nodes.m_data[v80].m_children[1] != k )
                      break;
                    k = v80;
                  }
                  if ( v80 )
                    v78 = v104.m_nodes.m_data[v80].m_children[1];
                  else
                    v78 = k;
                  if ( v80 == (_DWORD)v76 && v78 == k )
                    v78 = 0;
                }
              }
              while ( v78 );
            }
            else
            {
              v77 = 1;
            }
          }
          v107.m_value = v77;
          hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::insert(
            &v106,
            &v107);
          if ( v106.m_size >= v16 )
            goto LABEL_103;
        }
      }
      v82 = 1i64;
      array = 0i64;
      v102 = 0;
      v103 = 0x80000000;
      v83 = 1;
      if ( v106.m_nodes.m_size <= 1i64 )
      {
LABEL_108:
        v83 = 0;
      }
      else
      {
        m_children = v58[1].m_children;
        while ( *m_children == v83 )
        {
          ++v82;
          ++v83;
          m_children += 5;
          if ( v82 >= v106.m_nodes.m_size )
            goto LABEL_108;
        }
      }
      v85 = v83;
      if ( v83 )
      {
        v86 = clusterNexts;
        while ( 1 )
        {
          v102 = 0;
          v87 = 0;
          m_index = v58[v85].m_value.m_index;
          if ( (_DWORD)m_index )
          {
            v89 = v59[m_index].m_children[0];
            if ( v89 )
            {
              do
              {
                if ( !v59[v89].m_children[0] )
                {
                  if ( v87 == (v103 & 0x3FFFFFFF) )
                  {
                    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 4);
                    v87 = v102;
                  }
                  array[v87] = v89;
                  v59 = v104.m_nodes.m_data;
                  v87 = ++v102;
                }
                if ( v59[v89].m_children[0] )
                {
                  v89 = v59[v89].m_children[0];
                }
                else
                {
                  v90 = v59[v89].m_parent;
                  for ( m = v89; v90 != (_DWORD)m_index; v90 = v59[v90].m_parent )
                  {
                    if ( v59[v90].m_children[1] != m )
                      break;
                    m = v90;
                  }
                  if ( v90 )
                    v89 = v59[v90].m_children[1];
                  else
                    v89 = m;
                  if ( v90 == (_DWORD)m_index && v89 == m )
                    v89 = 0;
                }
              }
              while ( v89 );
            }
            else
            {
              if ( (v103 & 0x3FFFFFFF) == 0 )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 4);
                v87 = v102;
              }
              array[v87] = m_index;
              v59 = v104.m_nodes.m_data;
              v87 = ++v102;
            }
          }
          v92 = 0;
          if ( v87 > 0 )
          {
            v93 = 0i64;
            while ( 1 )
            {
              ++v92;
              ++v93;
              array[v93 - 1] = v59[array[v93 - 1]].m_children[1];
              if ( v92 >= v102 )
                break;
              v59 = v104.m_nodes.m_data;
            }
          }
          v94 = v112;
          v95 = *array;
          if ( *((_DWORD *)v112 + 2) == (*((_DWORD *)v112 + 3) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)v112, 4);
          v96 = 1;
          *(_DWORD *)(*(_QWORD *)v94 + 4i64 * (int)v94[2]++) = v95;
          if ( v102 > 1 )
          {
            v97 = 1i64;
            do
            {
              v98 = array[v97];
              ++v96;
              ++v97;
              v86->m_data[v95] = v98;
              v95 = array[v97 - 1];
            }
            while ( v96 < v102 );
          }
          if ( !v85 )
            break;
          v99 = v85 + 1;
          ++v83;
          v85 = v99;
          if ( v99 >= v106.m_nodes.m_size )
            break;
          v58 = v106.m_nodes.m_data;
          v100 = &v106.m_nodes.m_data->m_children[4 * v99 + v99];
          while ( *v100 == v83 )
          {
            ++v85;
            ++v83;
            v100 += 5;
            if ( v85 >= v106.m_nodes.m_size )
              goto LABEL_151;
          }
          v59 = v104.m_nodes.m_data;
          if ( !v85 )
            goto LABEL_152;
        }
        v58 = v106.m_nodes.m_data;
LABEL_151:
        v59 = v104.m_nodes.m_data;
      }
LABEL_152:
      v102 = 0;
      if ( v103 >= 0 )
      {
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v103);
        v59 = v104.m_nodes.m_data;
        v58 = v106.m_nodes.m_data;
      }
      array = 0i64;
      v103 = 0x80000000;
      v106.m_nodes.m_size = 0;
      if ( v106.m_nodes.m_capacityAndFlags >= 0 )
      {
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v58,
          20 * (v106.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
        v59 = v104.m_nodes.m_data;
      }
      v106.m_nodes.m_data = 0i64;
      v106.m_nodes.m_capacityAndFlags = 0x80000000;
      v104.m_nodes.m_size = 0;
      if ( v104.m_nodes.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v59,
          48 * (v104.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
    }
    else
    {
      v17 = clusterRoots->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v17 < numAabbs )
      {
        v18 = 2 * v17;
        v19 = numAabbs;
        if ( numAabbs < v18 )
          v19 = v18;
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&clusterRoots->m_data, v19, 4);
      }
      clusterRoots->m_size = numAabbs;
      if ( numAabbs > 0 )
      {
        v20 = 0i64;
        do
          clusterRoots->m_data[v20++] = v6++;
        while ( v6 < numAabbs );
      }
    }
  }
}

// File Line: 909
// RVA: 0xCBD9C0
void __fastcall hkGeometryProcessing::computeCurvature(hkGeometry *geometry, hkSimdFloat32 *maxCurvature)
{
  hkVector4f *m_data; // rdi
  int v5; // ecx
  const __m128i *v6; // rax
  __m128i si128; // xmm0
  int m_size; // esi
  int v9; // r9d
  __int64 v10; // r8
  hkGeometry::Triangle *v11; // rcx
  __int64 m_a; // rax
  __m128 m_quad; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm5
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  hkgpIndexedMeshDefinitions::Triangle *m_firstPool; // rdx
  hkgpIndexedMeshDefinitions::Triangle *m_triangle; // r9
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v23; // rax
  signed int m_index; // r10d
  __int64 v25; // r8
  __m128 v26; // xmm1
  __m128 v27; // xmm9
  __m128 v28; // xmm7
  __m128 v29; // xmm2
  __m128 v30; // xmm5
  __m128 v31; // xmm4
  __m128 v32; // xmm3
  __m128 v33; // xmm2
  __m128 v34; // xmm3
  __m128 v35; // xmm2
  __m128 v36; // xmm0
  __m128 v37; // xmm1
  __m128 v38; // xmm4
  __m128 v39; // xmm0
  __m128 v40; // xmm1
  unsigned __int64 v41; // rcx
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v42; // rax
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator v43; // [rsp+30h] [rbp-C8h] BYREF
  __m128 *array; // [rsp+40h] [rbp-B8h] BYREF
  int v45; // [rsp+48h] [rbp-B0h]
  int v46; // [rsp+4Ch] [rbp-ACh]
  hkgpIndexedMesh v47; // [rsp+50h] [rbp-A8h] BYREF
  void *retaddr; // [rsp+138h] [rbp+40h] BYREF

  m_data = geometry->m_vertices.m_data;
  v5 = 0;
  if ( geometry->m_vertices.m_size > 0 )
  {
    v6 = (const __m128i *)m_data;
    do
    {
      si128 = _mm_load_si128(v6);
      ++v5;
      ++v6;
      v6[-1] = _mm_srli_si128(_mm_slli_si128(si128, 4), 4);
    }
    while ( v5 < geometry->m_vertices.m_size );
  }
  m_size = geometry->m_triangles.m_size;
  array = 0i64;
  v45 = 0;
  v46 = 0x80000000;
  if ( m_size > 0 )
    hkArrayUtil::_reserve((hkResult *)&retaddr, &hkContainerHeapAllocator::s_alloc, (const void **)&array, m_size, 16);
  v45 = m_size;
  v9 = 0;
  if ( geometry->m_triangles.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = geometry->m_triangles.m_data;
      ++v9;
      m_a = v11[v10++].m_a;
      m_quad = m_data[m_a].m_quad;
      v14 = _mm_sub_ps(m_data[v11[v10 - 1].m_b].m_quad, m_quad);
      v15 = _mm_sub_ps(m_data[v11[v10 - 1].m_c].m_quad, m_quad);
      v16 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v14), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v15));
      v17 = _mm_shuffle_ps(v16, v16, 201);
      v18 = _mm_mul_ps(v17, v17);
      v19 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
              _mm_shuffle_ps(v18, v18, 170));
      v20 = _mm_rsqrt_ps(v19);
      array[v10 - 1] = _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmple_ps(v19, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                             _mm_mul_ps(*(__m128 *)_xmm, v20))),
                         v17);
    }
    while ( v9 < geometry->m_triangles.m_size );
  }
  hkgpIndexedMesh::hkgpIndexedMesh(&v47);
  hkgpIndexedMesh::appendFromGeometry(&v47, geometry);
  m_firstPool = (hkgpIndexedMeshDefinitions::Triangle *)v47.m_triangles.m_allocator.m_firstPool;
  *maxCurvature = 0i64;
  v43.m_edge.m_triangle = m_firstPool;
  v43.m_edge.m_index = 0;
  if ( m_firstPool
    && m_firstPool->m_vertices[0]->m_index > m_firstPool->m_vertices[1]->m_index
    && (m_firstPool->m_links[0] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
  {
    hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v43);
  }
  m_triangle = v43.m_edge.m_triangle;
  v23 = &v43;
  if ( !v43.m_edge.m_triangle )
    v23 = 0i64;
  if ( v23 )
  {
    m_index = v43.m_edge.m_index;
    do
    {
      if ( (m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
      {
        v25 = (9i64 >> (2 * (unsigned __int8)m_index)) & 3;
        v26 = _mm_mul_ps(
                array[*(int *)((m_triangle->m_links[m_index] & 0xFFFFFFFFFFFFFFFCui64) + 64)],
                array[SLODWORD(m_triangle->m_index)]);
        v27 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                _mm_shuffle_ps(v26, v26, 170));
        v28 = _mm_andnot_ps(*(__m128 *)_xmm, v27);
        v29 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v28), *(__m128 *)_xmm);
        v30 = _mm_cmplt_ps(*(__m128 *)_xmm, v28);
        v31 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v29), v30), _mm_andnot_ps(v30, v28));
        v32 = _mm_or_ps(_mm_andnot_ps(v30, _mm_mul_ps(v28, v28)), _mm_and_ps(v30, v29));
        v33 = _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v32, *(__m128 *)coeff4), *(__m128 *)coeff3), v32),
                          *(__m128 *)coeff2),
                        v32),
                      *(__m128 *)coeff1),
                    v32),
                  *(__m128 *)coeff0),
                v32);
        v34 = m_data[m_triangle->m_vertices[v25]->m_index].m_quad;
        v35 = _mm_add_ps(_mm_mul_ps(v33, v31), v31);
        v36 = _mm_cmplt_ps(v28, *(__m128 *)_xmm);
        v37 = m_data[m_triangle->m_vertices[m_index]->m_index].m_quad;
        v38 = _mm_sub_ps(
                *(__m128 *)_xmm,
                _mm_xor_ps(
                  _mm_or_ps(
                    _mm_andnot_ps(
                      v36,
                      _mm_or_ps(
                        _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v35, v35)), v30),
                        _mm_andnot_ps(v30, v35))),
                    _mm_and_ps(v36, v28)),
                  _mm_and_ps(v27, *(__m128 *)_xmm)));
        m_data[m_triangle->m_vertices[m_index]->m_index].m_quad = _mm_shuffle_ps(
                                                                    v37,
                                                                    _mm_unpackhi_ps(
                                                                      v37,
                                                                      _mm_max_ps(_mm_shuffle_ps(v37, v37, 255), v38)),
                                                                    196);
        m_data[m_triangle->m_vertices[v25]->m_index].m_quad = _mm_shuffle_ps(
                                                                m_data[m_triangle->m_vertices[v25]->m_index].m_quad,
                                                                _mm_unpackhi_ps(
                                                                  m_data[m_triangle->m_vertices[v25]->m_index].m_quad,
                                                                  _mm_max_ps(_mm_shuffle_ps(v34, v34, 255), v38)),
                                                                196);
        v39 = m_data[m_triangle->m_vertices[m_index]->m_index].m_quad;
        v40 = _mm_max_ps(maxCurvature->m_real, _mm_shuffle_ps(v39, v39, 255));
        *maxCurvature = (hkSimdFloat32)v40;
        v41 = m_triangle->m_vertices[v25]->m_index;
        maxCurvature->m_real = _mm_max_ps(v40, _mm_shuffle_ps(m_data[v41].m_quad, m_data[v41].m_quad, 255));
      }
      if ( m_triangle )
      {
        hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v43);
        m_index = v43.m_edge.m_index;
        m_triangle = v43.m_edge.m_triangle;
      }
      v42 = &v43;
      if ( !m_triangle )
        v42 = 0i64;
    }
    while ( v42 );
  }
  hkgpIndexedMesh::~hkgpIndexedMesh(&v47);
  v45 = 0;
  if ( v46 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v46);
}

// File Line: 961
// RVA: 0xCBDE70
void __fastcall hkGeometryProcessing::fixTJunctions(hkGeometry *geometry, float maxDistance)
{
  int v3; // r14d
  float v4; // xmm14_4
  __m128 v5; // xmm11
  __m128 v6; // xmm12
  char v7; // bl
  int m_size; // r8d
  int v9; // r8d
  hkgpIndexedMeshDefinitions::Triangle *m_triangle; // rdx
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v11; // rax
  int *v12; // r15
  __int64 v13; // r12
  __int64 v14; // rdi
  hkVector4f *v15; // rdx
  unsigned int m_firstFree; // esi
  __m128 v17; // xmm6
  __m128 v18; // xmm7
  hkcdDynamicTree::CodecRawUint *m_data; // rdx
  __int64 v20; // rbx
  hkcdDynamicTree::CodecRawUint *v21; // r9
  __int64 m_root; // r14
  hkVector4f v23; // xmm7
  hkVector4f v24; // xmm8
  unsigned int v25; // edx
  __m128 *p_m_quad; // r10
  __int64 v27; // rax
  hkcdDynamicTree::CodecRawUint *v28; // rdi
  __m128 v29; // xmm9
  __m128 v30; // xmm10
  __int64 v31; // rcx
  __m128 v32; // xmm1
  __m128 *v33; // rcx
  __m128 v34; // xmm2
  __m128 v35; // xmm3
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm2
  __m128 v39; // xmm6
  __m128 v40; // xmm5
  __m128 v41; // xmm5
  __int64 v42; // r11
  int v43; // eax
  signed __int64 v44; // rcx
  __m128 v45; // xmm1
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v46; // rax
  unsigned int v47; // ecx
  int v48; // r8d
  hkgpIndexedMeshDefinitions::Triangle *v49; // rdi
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v50; // rax
  hkVector4f *v51; // rdx
  __int64 m_index_low; // r9
  __int64 v53; // r10
  __m128 v54; // xmm1
  __m128 v55; // xmm1
  __m128 v56; // xmm4
  __m128 v57; // xmm1
  __m128 m_quad; // xmm2
  __m128 v59; // xmm1
  __m128 v60; // xmm2
  __m128 v61; // xmm1
  hkLifoAllocator *Value; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkGeometryProcessingInternals::TJunctionsQuery> *v63; // r9
  hkcdDynamicTree::CodecRawUint *m_cur; // rcx
  hkVector4f *p_m_max; // rdx
  int v66; // eax
  char *v67; // rsi
  signed int v68; // ebx
  hkLifoAllocator *v69; // rax
  int v70; // r8d
  __int64 v71; // r8
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v72; // rax
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> v73; // [rsp+30h] [rbp-B0h] BYREF
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> v74; // [rsp+58h] [rbp-88h] BYREF
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator v75; // [rsp+80h] [rbp-60h] BYREF
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator v76; // [rsp+90h] [rbp-50h] BYREF
  int v77[2]; // [rsp+A0h] [rbp-40h] BYREF
  hkResult v78; // [rsp+A8h] [rbp-38h] BYREF
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator v79; // [rsp+B0h] [rbp-30h]
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator v80; // [rsp+C0h] [rbp-20h]
  __int64 v81[2]; // [rsp+D0h] [rbp-10h]
  hkcdTreeQueriesStacks::Dynamic<64,unsigned int> stackInstance; // [rsp+E0h] [rbp+0h] BYREF
  __m128 v83; // [rsp+100h] [rbp+20h]
  char v84; // [rsp+110h] [rbp+30h] BYREF
  __m128 v85; // [rsp+120h] [rbp+40h]
  hkGeometry *v86; // [rsp+130h] [rbp+50h]
  hkgpIndexedMeshDefinitions::Triangle *v87; // [rsp+138h] [rbp+58h]
  __int64 v88; // [rsp+140h] [rbp+60h]
  int v89; // [rsp+148h] [rbp+68h]
  int v90; // [rsp+14Ch] [rbp+6Ch]
  int m_index; // [rsp+150h] [rbp+70h]
  hkVector4f v92; // [rsp+160h] [rbp+80h]
  hkVector4f v93; // [rsp+170h] [rbp+90h]
  hkVector4f v94; // [rsp+180h] [rbp+A0h]
  hkgpIndexedMesh v95; // [rsp+190h] [rbp+B0h] BYREF
  int v96; // [rsp+300h] [rbp+220h]
  float v97; // [rsp+308h] [rbp+228h]
  hkResult result; // [rsp+310h] [rbp+230h] BYREF
  void *retaddr; // [rsp+318h] [rbp+238h] BYREF

  v3 = 0;
  v4 = fmaxf(0.00000011920929, maxDistance);
  v96 = 0;
  v97 = v4;
  v5 = _mm_shuffle_ps((__m128)LODWORD(v4), (__m128)LODWORD(v4), 0);
  v6 = _mm_mul_ps(v5, v5);
  if ( geometry->m_vertices.m_size > 0 )
  {
    while ( 1 )
    {
      v7 = 0;
      LOBYTE(v97) = 0;
      hkGeometryUtils::weldVertices(geometry, v4);
      hkgpIndexedMesh::hkgpIndexedMesh(&v95);
      hkgpIndexedMesh::appendFromGeometry(&v95, geometry);
      m_size = geometry->m_vertices.m_size;
      v73.m_nodes.m_size = 0;
      v73.m_nodes.m_data = 0i64;
      v73.m_nodes.m_capacityAndFlags = 0x80000000;
      v73.m_firstFree = 0;
      *(_QWORD *)&v73.m_path = 0i64;
      v73.m_numLeaves = 0;
      hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
        &v73,
        &result,
        m_size);
      v9 = geometry->m_vertices.m_size;
      v74.m_nodes.m_data = 0i64;
      v74.m_nodes.m_size = 0;
      v74.m_nodes.m_capacityAndFlags = 0x80000000;
      v74.m_firstFree = 0;
      hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::setSizeAndFill(
        (hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > *)&v74,
        0,
        v9,
        0);
      v80.m_edge.m_triangle = v95.m_triangles.m_used;
      v80.m_edge.m_index = 0;
      v76 = v80;
      if ( v95.m_triangles.m_used
        && v95.m_triangles.m_used->m_vertices[0]->m_index > v95.m_triangles.m_used->m_vertices[1]->m_index
        && (v95.m_triangles.m_used->m_links[0] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
      {
        hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v76);
      }
      m_triangle = v76.m_edge.m_triangle;
      v11 = &v76;
      if ( !v76.m_edge.m_triangle )
        v11 = 0i64;
      if ( v11 )
      {
        do
        {
          if ( (m_triangle->m_links[v76.m_edge.m_index] & 0xFFFFFFFFFFFFFFFCui64) == 0 )
          {
            v12 = v77;
            v13 = 2i64;
            v77[0] = m_triangle->m_vertices[v76.m_edge.m_index]->m_index;
            v77[1] = m_triangle->m_vertices[(9i64 >> (2 * LOBYTE(v76.m_edge.m_index))) & 3]->m_index;
            do
            {
              v14 = *v12;
              if ( (((unsigned int)v74.m_nodes.m_data->m_aabb.m_min.m_quad.m128_i32[v14 >> 5] >> (*(_BYTE *)v12 & 0x1F)) & 1) == 0 )
              {
                v74.m_nodes.m_data->m_aabb.m_min.m_quad.m128_i32[v14 >> 5] |= 1 << (*(_BYTE *)v12 & 0x1F);
                v15 = &geometry->m_vertices.m_data[v14];
                m_firstFree = v73.m_firstFree;
                v17 = _mm_add_ps(v15->m_quad, v5);
                v18 = _mm_sub_ps(v15->m_quad, v5);
                if ( !v73.m_firstFree )
                {
                  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
                    &v73,
                    (hkResult *)&retaddr,
                    1);
                  m_firstFree = v73.m_firstFree;
                }
                m_data = v73.m_nodes.m_data;
                v73.m_firstFree = v73.m_nodes.m_data[m_firstFree].m_aabb.m_min.m_quad.m128_u32[0];
                v20 = m_firstFree;
                v73.m_nodes.m_data[v20].m_children[0] = 0;
                m_data[v20].m_children[1] = v14;
                m_data[v20].m_aabb.m_min.m_quad = v18;
                m_data[v20].m_aabb.m_max.m_quad = v17;
                v21 = v73.m_nodes.m_data;
                m_root = v73.m_root;
                v23.m_quad = (__m128)v73.m_nodes.m_data[v20].m_aabb.m_min;
                v24.m_quad = (__m128)v73.m_nodes.m_data[v20].m_aabb.m_max;
                if ( v73.m_root )
                {
                  v25 = v73.m_firstFree;
                  if ( !v73.m_firstFree )
                  {
                    hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
                      &v73,
                      &v78,
                      1);
                    v25 = v73.m_firstFree;
                    v21 = v73.m_nodes.m_data;
                  }
                  p_m_quad = &v21[m_root].m_aabb.m_min.m_quad;
                  v73.m_firstFree = v21[v25].m_aabb.m_min.m_quad.m128_u32[0];
                  v27 = p_m_quad[2].m128_u32[1];
                  v28 = &v21[v25];
                  if ( (_DWORD)v27 )
                  {
                    v29 = _mm_add_ps(v24.m_quad, v23.m_quad);
                    v30 = _mm_sub_ps(v24.m_quad, v23.m_quad);
                    do
                    {
                      v31 = p_m_quad[2].m128_u32[2];
                      v32 = _mm_max_ps(p_m_quad[1], v24.m_quad);
                      *p_m_quad = _mm_min_ps(*p_m_quad, v23.m_quad);
                      p_m_quad[1] = v32;
                      v81[0] = (__int64)&v21[v27];
                      v33 = &v21[v31].m_aabb.m_min.m_quad;
                      v21 = v73.m_nodes.m_data;
                      v34 = *(__m128 *)(v81[0] + 16);
                      v35 = _mm_sub_ps(v34, *(__m128 *)v81[0]);
                      v81[1] = (__int64)v33;
                      v36 = _mm_add_ps(v35, v30);
                      v37 = _mm_sub_ps(_mm_add_ps(v34, *(__m128 *)v81[0]), v29);
                      v38 = _mm_mul_ps(v37, v37);
                      v39 = _mm_add_ps(_mm_sub_ps(v33[1], *v33), v30);
                      v40 = _mm_sub_ps(_mm_add_ps(v33[1], *v33), v29);
                      v41 = _mm_mul_ps(v40, v40);
                      p_m_quad = (__m128 *)v81[(float)((float)((float)(_mm_shuffle_ps(v38, v38, 85).m128_f32[0]
                                                                     + _mm_shuffle_ps(v38, v38, 0).m128_f32[0])
                                                             + _mm_shuffle_ps(v38, v38, 170).m128_f32[0])
                                                     * (float)((float)(_mm_shuffle_ps(v36, v36, 85).m128_f32[0]
                                                                     + _mm_shuffle_ps(v36, v36, 0).m128_f32[0])
                                                             + _mm_shuffle_ps(v36, v36, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v41, v41, 85).m128_f32[0] + _mm_shuffle_ps(v41, v41, 0).m128_f32[0]) + _mm_shuffle_ps(v41, v41, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v39, v39, 85).m128_f32[0] + _mm_shuffle_ps(v39, v39, 0).m128_f32[0]) + _mm_shuffle_ps(v39, v39, 170).m128_f32[0]))];
                      v27 = p_m_quad[2].m128_u32[1];
                    }
                    while ( (_DWORD)v27 );
                  }
                  v42 = v28 - v21;
                  v43 = p_m_quad[2].m128_i32[0];
                  if ( v43 )
                    v21[v43].m_children[v21[v43].m_children[1] == (unsigned int)(((char *)p_m_quad - (char *)v21) / 48)] = v42;
                  else
                    v73.m_root = v28 - v21;
                  v28->m_parent = p_m_quad[2].m128_u32[0];
                  v44 = (char *)p_m_quad - (char *)v73.m_nodes.m_data;
                  v28->m_children[1] = m_firstFree;
                  v28->m_children[0] = v44 / 48;
                  p_m_quad[2].m128_i32[0] = v42;
                  v73.m_nodes.m_data[v20].m_parent = v42;
                  v45 = _mm_max_ps(p_m_quad[1], v24.m_quad);
                  v28->m_aabb.m_min.m_quad = _mm_min_ps(*p_m_quad, v23.m_quad);
                  v28->m_aabb.m_max.m_quad = v45;
                }
                else
                {
                  v73.m_root = m_firstFree;
                  v73.m_nodes.m_data[v20].m_parent = 0;
                }
                ++v73.m_numLeaves;
              }
              ++v12;
              --v13;
            }
            while ( v13 );
          }
          hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v76);
          m_triangle = v76.m_edge.m_triangle;
          v46 = &v76;
          if ( !v76.m_edge.m_triangle )
            v46 = 0i64;
        }
        while ( v46 );
        v3 = v96;
        v7 = 0;
      }
      v74.m_nodes.m_size = 0;
      if ( v74.m_nodes.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v74.m_nodes.m_data,
          4 * v74.m_nodes.m_capacityAndFlags);
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::rebuildBranchSAH(&v73, v73.m_root, (hkBool)1, 32, 16);
      if ( v73.m_root )
      {
        v74.m_nodes.m_size = 0;
        v74.m_nodes.m_data = 0i64;
        v74.m_nodes.m_capacityAndFlags = 0x80000000;
        v74.m_firstFree = 0;
        *(_QWORD *)&v74.m_path = 0i64;
        v74.m_numLeaves = 0;
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>>(
          &v73,
          (hkcdDynamicTree::DefaultTree48Storage *)&v74);
        hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
          (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v74,
          (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v73);
        v47 = v74.m_firstFree;
        v74.m_firstFree = v73.m_firstFree;
        v73.m_firstFree = v47;
        v73.m_root = 1;
        v74.m_nodes.m_size = 0;
        if ( v74.m_nodes.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v74.m_nodes.m_data,
            48 * (v74.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
      }
      v48 = geometry->m_triangles.m_size;
      *(_QWORD *)&v74.m_nodes.m_size = 0i64;
      v74.m_firstFree = 0;
      *(&v74.m_firstFree + 1) = 0x80000000;
      v74.m_numLeaves = 0;
      hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::setSizeAndFill(
        (hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > *)&v74.m_nodes.m_size,
        0,
        v48,
        0);
      v79.m_edge.m_index = 0;
      v79.m_edge.m_triangle = v95.m_triangles.m_used;
      v75 = v79;
      if ( v95.m_triangles.m_used
        && v95.m_triangles.m_used->m_vertices[0]->m_index > v95.m_triangles.m_used->m_vertices[1]->m_index
        && (v95.m_triangles.m_used->m_links[0] & 0xFFFFFFFFFFFFFFFCui64) != 0 )
      {
        hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v75);
      }
      v49 = v75.m_edge.m_triangle;
      v50 = &v75;
      if ( !v75.m_edge.m_triangle )
        v50 = 0i64;
      if ( !v50 )
        break;
      do
      {
        if ( ((*(_DWORD *)(*(_QWORD *)&v74.m_nodes.m_size + 4 * ((__int64)SLODWORD(v49->m_index) >> 5)) >> (v49->m_index & 0x1F)) & 1) == 0
          && (v49->m_links[v75.m_edge.m_index] & 0xFFFFFFFFFFFFFFFCui64) == 0 )
        {
          v51 = geometry->m_vertices.m_data;
          m_index_low = SLODWORD(v49->m_vertices[v75.m_edge.m_index]->m_index);
          v53 = SLODWORD(v49->m_vertices[(9i64 >> (2 * LOBYTE(v75.m_edge.m_index))) & 3]->m_index);
          v54 = _mm_sub_ps(v51[m_index_low].m_quad, v51[v53].m_quad);
          v55 = _mm_mul_ps(v54, v54);
          v56 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                  _mm_shuffle_ps(v55, v55, 170));
          v57 = _mm_rsqrt_ps(v56);
          if ( _mm_andnot_ps(
                 _mm_cmple_ps(v56, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v56, v57), v57)),
                     _mm_mul_ps(*(__m128 *)_xmm, v57)),
                   v56)).m128_f32[0] > (float)(v5.m128_f32[0] + v5.m128_f32[0]) )
          {
            m_quad = v51[m_index_low].m_quad;
            stackInstance.m_stack.m_size = 1;
            v59 = m_quad;
            v74.m_nodes.m_data = 0i64;
            v74.m_nodes.m_size = 0;
            v60 = _mm_max_ps(m_quad, v51[v53].m_quad);
            v74.m_nodes.m_capacityAndFlags = 0x80000000;
            v74.m_numLeaves = 64;
            v61 = _mm_min_ps(v59, v51[v53].m_quad);
            v85 = v6;
            v83 = v60;
            v84 = 0;
            v86 = geometry;
            v87 = v49;
            *(__m128 *)&stackInstance.m_stack.m_localMemory = v61;
            v88 = *(_QWORD *)&v75.m_edge.m_index;
            v89 = m_index_low;
            v90 = v53;
            m_index = v49->m_vertices[(18i64 >> (2 * LOBYTE(v75.m_edge.m_index))) & 3]->m_index;
            v92.m_quad = (__m128)v51[m_index_low];
            v93.m_quad = (__m128)v51[v53];
            v94.m_quad = (__m128)v51[m_index];
            stackInstance.m_stack.m_data = (unsigned int *)&v84;
            Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            m_cur = (hkcdDynamicTree::CodecRawUint *)Value->m_cur;
            p_m_max = &m_cur[5].m_aabb.m_max;
            if ( Value->m_slabSize < 256 || p_m_max > Value->m_end )
              m_cur = (hkcdDynamicTree::CodecRawUint *)hkLifoAllocator::allocateFromNewSlab(Value, 256);
            else
              Value->m_cur = p_m_max;
            v74.m_nodes.m_data = m_cur;
            *(_QWORD *)&v74.m_firstFree = m_cur;
            v74.m_nodes.m_capacityAndFlags = -2147483584;
            hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>,hkcdTreeQueriesStacks::Dynamic<64,unsigned int>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkGeometryProcessingInternals::TJunctionsQuery>>(
              (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&v73,
              &v74,
              &stackInstance,
              v63);
            v66 = v74.m_nodes.m_size;
            v67 = *(char **)&v74.m_firstFree;
            if ( *(hkcdDynamicTree::CodecRawUint **)&v74.m_firstFree == v74.m_nodes.m_data )
              v66 = 0;
            v74.m_nodes.m_size = v66;
            v68 = (4 * v74.m_numLeaves + 127) & 0xFFFFFF80;
            v69 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v70 = (v68 + 15) & 0xFFFFFFF0;
            if ( v68 > v69->m_slabSize || &v67[v70] != v69->m_cur || v69->m_firstNonLifoEnd == v67 )
              hkLifoAllocator::slowBlockFree(v69, v67, v70);
            else
              v69->m_cur = v67;
            v74.m_nodes.m_size = 0;
            if ( v74.m_nodes.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                v74.m_nodes.m_data,
                4 * v74.m_nodes.m_capacityAndFlags);
            if ( v84 )
            {
              v71 = SLODWORD(v49->m_index);
              v7 = 1;
              LOBYTE(v97) = 1;
              *(_DWORD *)(*(_QWORD *)&v74.m_nodes.m_size + 4 * (v71 >> 5)) |= 1 << (v71 & 0x1F);
            }
            else
            {
              v7 = LOBYTE(v97);
            }
          }
        }
        hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v75);
        v49 = v75.m_edge.m_triangle;
        v72 = &v75;
        if ( !v75.m_edge.m_triangle )
          v72 = 0i64;
      }
      while ( v72 );
      if ( !v7 )
        break;
      hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>((hkaMatrix<float> *)&v74.m_nodes.m_size);
      v73.m_nodes.m_size = 0;
      if ( v73.m_nodes.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v73.m_nodes.m_data,
          48 * (v73.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
      v73.m_nodes.m_data = 0i64;
      v73.m_nodes.m_capacityAndFlags = 0x80000000;
      hkgpIndexedMesh::~hkgpIndexedMesh(&v95);
      v96 = ++v3;
      if ( v3 >= geometry->m_vertices.m_size )
        return;
    }
    v74.m_firstFree = 0;
    if ( *((int *)&v74.m_firstFree + 1) >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        *(void **)&v74.m_nodes.m_size,
        4 * *(&v74.m_firstFree + 1));
    *(_QWORD *)&v74.m_nodes.m_size = 0i64;
    *(&v74.m_firstFree + 1) = 0x80000000;
    v73.m_nodes.m_size = 0;
    if ( v73.m_nodes.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v73.m_nodes.m_data,
        48 * (v73.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
    v73.m_nodes.m_data = 0i64;
    v73.m_nodes.m_capacityAndFlags = 0x80000000;
    hkgpIndexedMesh::~hkgpIndexedMesh(&v95);
  }
}


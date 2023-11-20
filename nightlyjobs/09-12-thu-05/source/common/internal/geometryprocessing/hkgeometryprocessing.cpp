// File Line: 135
// RVA: 0xCB99F0
__int64 __fastcall hkGeometryProcessing::IsoVertex::solveTriangle(const float *values, hkGeometryProcessing::IsoVertex *verticesOut, float orientation)
{
  float v3; // xmm3_4
  const float *v4; // r10
  unsigned int v5; // er8
  float v6; // xmm8_4
  float v7; // xmm6_4
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
  v4 = values;
  v5 = 0;
  v6 = values[2];
  v7 = orientation;
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
      v14 = __PAIR__(LODWORD(v8), 0);
      v20.m_solution = v9;
      v20.m_edge = 1;
      v15 = v20;
      verticesOut[1] = v20;
      *verticesOut = (hkGeometryProcessing::IsoVertex)__PAIR__(LODWORD(v8), 0);
      v16 = v7 * v4[1];
      break;
    case 5u:
      v19.m_solution = v10;
      v19.m_edge = 2;
      v14 = (unsigned __int64)v19;
      v15 = (hkGeometryProcessing::IsoVertex)__PAIR__(LODWORD(v8), 0);
      verticesOut[1] = (hkGeometryProcessing::IsoVertex)__PAIR__(LODWORD(v8), 0);
      *verticesOut = v19;
      v16 = v7 * *v4;
      break;
    case 6u:
      v17.m_solution = v9;
      v17.m_edge = 1;
      v13 = v17;
      v18.m_solution = v10;
      v18.m_edge = 2;
      *verticesOut = v13;
      verticesOut[1] = v18;
      result = v5;
      if ( (float)(v7 * v4[2]) < 0.0 )
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
void __fastcall hkGeometryProcessing::SurfaceSampler::addGeometry(hkGeometryProcessing::SurfaceSampler *this, hkGeometry *geometry, int baseIndex)
{
  int v3; // er14
  int v4; // er9
  int v5; // eax
  unsigned __int128 v6; // di
  int v7; // eax
  int v8; // ebx
  __int64 v9; // rbp
  hkResult result; // [rsp+50h] [rbp+8h]

  v3 = baseIndex;
  v4 = geometry->m_triangles.m_size + this->m_elements.m_size;
  v5 = this->m_elements.m_capacityAndFlags & 0x3FFFFFFF;
  v6 = __PAIR__((unsigned __int64)this, (unsigned __int64)geometry);
  if ( v5 < v4 )
  {
    v7 = 2 * v5;
    if ( v4 < v7 )
      v4 = v7;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, v4, 8);
  }
  v8 = 0;
  if ( *(_DWORD *)(v6 + 40) > 0 )
  {
    v9 = 0i64;
    do
    {
      hkGeometryProcessing::SurfaceSampler::addElement(
        *((hkGeometryProcessing::SurfaceSampler **)&v6 + 1),
        (hkVector4f *)(*(_QWORD *)(v6 + 16) + 16i64 * *(signed int *)(*(_QWORD *)(v6 + 32) + v9)),
        (hkVector4f *)(*(_QWORD *)(v6 + 16) + 16i64 * *(signed int *)(*(_QWORD *)(v6 + 32) + v9 + 4)),
        (hkVector4f *)(*(_QWORD *)(v6 + 16) + 16i64 * *(signed int *)(*(_QWORD *)(v6 + 32) + v9 + 8)),
        v8++ + v3);
      v9 += 16i64;
    }
    while ( v8 < *(_DWORD *)(v6 + 40) );
  }
}

// File Line: 196
// RVA: 0xCB9CB0
void __fastcall hkGeometryProcessing::SurfaceSampler::addElement(hkGeometryProcessing::SurfaceSampler *this, hkVector4f *a, hkVector4f *b, hkVector4f *c, int index)
{
  hkVector4f *v5; // rdi
  hkVector4f *v6; // rsi
  hkVector4f *v7; // rbp
  hkGeometryProcessing::SurfaceSampler *v8; // rbx
  hkGeometryProcessing::SurfaceSampler::Element *v9; // rcx
  __int64 v10; // rdx
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm3
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm1

  v5 = c;
  v6 = b;
  v7 = a;
  v8 = this;
  if ( this->m_elements.m_size == (this->m_elements.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, 8);
  v9 = v8->m_elements.m_data;
  v10 = v8->m_elements.m_size;
  v8->m_elements.m_size = v10 + 1;
  v9[v10].m_index = index;
  v9[v10].m_value = v8->m_domain;
  v11 = _mm_sub_ps(v6->m_quad, v7->m_quad);
  v12 = _mm_sub_ps(v5->m_quad, v7->m_quad);
  v13 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v11), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v12));
  v14 = _mm_shuffle_ps(v13, v13, 201);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rsqrt_ps(v16);
  v8->m_domain = COERCE_FLOAT(
                   _mm_andnot_ps(
                     _mm_cmpleps(v16, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                         _mm_mul_ps(*(__m128 *)_xmm, v17)),
                       v16)))
               + v8->m_domain;
}

// File Line: 205
// RVA: 0xCB9DB0
signed __int64 __fastcall hkGeometryProcessing::SurfaceSampler::findElement(hkGeometryProcessing::SurfaceSampler *this, int index)
{
  __int64 v2; // r10
  unsigned int v3; // er9
  __int64 v4; // r8
  int *v5; // rax

  v2 = this->m_elements.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
    return 0xFFFFFFFFi64;
  v5 = &this->m_elements.m_data->m_index;
  while ( *v5 != index )
  {
    ++v4;
    ++v3;
    v5 += 2;
    if ( v4 >= v2 )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 215
// RVA: 0xCB9DF0
__int64 __fastcall hkGeometryProcessing::SurfaceSampler::searchElement(hkGeometryProcessing::SurfaceSampler *this, float value)
{
  int v2; // er10
  int v3; // er9
  int v4; // er8
  int v5; // edx
  float v6; // xmm0_4
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
      goto LABEL_16;
    v6 = this->m_elements.m_data[v5].m_value;
    if ( v6 > value )
    {
      v3 = (v3 + v2) >> 1;
      continue;
    }
    if ( v6 >= value )
LABEL_16:
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
__int64 __fastcall hkGeometryProcessing::SurfaceSampler::getSample(hkGeometryProcessing::SurfaceSampler *this, hkGeometryProcessing::Prng *prng, hkVector4f *baryCenter)
{
  unsigned int v3; // er15
  unsigned int v4; // er9
  hkGeometryProcessing::Prng *v5; // r13
  hkGeometryProcessing::SurfaceSampler *v6; // r14
  int v7; // esi
  unsigned int v8; // eax
  bool v9; // sf
  unsigned int v10; // er15
  BOOL v11; // edi
  unsigned int v12; // ebx
  int v13; // eax
  hkGeometryProcessing::SurfaceSampler::Element *v14; // r11
  __int64 v15; // r12
  int v16; // er9
  int v17; // er10
  unsigned int v18; // edx
  float v19; // xmm0_4
  unsigned int v20; // eax
  int v21; // er8
  int v22; // edx
  __m128 v23; // xmm1
  BOOL v24; // ebp
  int v25; // edx
  __m128 v26; // xmm3
  __m128 v27; // xmm1
  hkVector4f *v29; // [rsp+70h] [rbp+18h]

  v29 = baryCenter;
  v3 = prng->m_c + prng->m_w;
  v4 = prng->m_y ^ 32 * prng->m_y;
  v5 = prng;
  v6 = this;
  v7 = v4 ^ (v4 >> 7) ^ ((v4 ^ (v4 >> 7)) << 22);
  v8 = prng->m_w;
  v9 = (signed int)(prng->m_z + v3) < 0;
  v10 = prng->m_z + v3;
  v11 = v9;
  prng->m_x += 1411392427;
  v12 = prng->m_x;
  prng->m_z = v8;
  v10 &= 0x7FFFFFFFu;
  prng->m_y = v7;
  prng->m_c = v9;
  prng->m_w = v10;
  v13 = hkGeometryProcessing::SurfaceSampler::searchElement(
          this,
          (float)((float)(signed int)(v10 + v7 + v12) * 2.3283064e-10) * this->m_domain);
  v14 = v6->m_elements.m_data;
  v12 += 1411392427;
  v15 = v13;
  v16 = v5->m_z + v10 + v11;
  v17 = v16 & 0x7FFFFFFF;
  v5->m_z = v17;
  v18 = v7 ^ 32 * v7 ^ ((v7 ^ (unsigned int)(32 * v7)) >> 7) ^ ((v7 ^ 32 * v7 ^ ((v7 ^ (unsigned int)(32 * v7)) >> 7)) << 22);
  v19 = (float)(signed int)(v17 + v12 + v18);
  v20 = v18 ^ 32 * v18;
  v21 = v20 ^ (v20 >> 7) ^ ((v20 ^ (v20 >> 7)) << 22);
  v5->m_y = v21;
  v22 = v17 + (v16 < 0);
  v23 = _mm_shuffle_ps(
          (__m128)COERCE_UNSIGNED_INT(v19 * 2.3283064e-10),
          (__m128)COERCE_UNSIGNED_INT(v19 * 2.3283064e-10),
          0);
  v24 = (signed int)(v10 + v22) < 0;
  v25 = (v10 + v22) & 0x7FFFFFFF;
  v5->m_c = v24;
  v5->m_w = v25;
  v26 = _mm_andnot_ps(_mm_cmpleps(v23, (__m128)0i64), _mm_sqrt_ps(v23));
  v5->m_x = v12 + 1411392427;
  v27 = _mm_shuffle_ps(
          (__m128)COERCE_UNSIGNED_INT((float)(signed int)(v25 + v21 + v12 + 1411392427) * 2.3283064e-10),
          (__m128)COERCE_UNSIGNED_INT((float)(signed int)(v25 + v21 + v12 + 1411392427) * 2.3283064e-10),
          0);
  v29->m_quad = _mm_movelh_ps(
                  _mm_unpacklo_ps(_mm_sub_ps(query.m_quad, v26), _mm_mul_ps(_mm_sub_ps(query.m_quad, v27), v26)),
                  _mm_unpacklo_ps(_mm_mul_ps(v26, v27), aabbOut.m_quad));
  return (unsigned int)v14[v15].m_index;
}

// File Line: 247
// RVA: 0xCBA020
char __fastcall hkGeometryProcessing::intersectPlanes(hkVector4f *p0, hkVector4f *p1, hkVector4f *p2, hkVector4f *intersection)
{
  __m128 v4; // xmm2
  hkVector4f *v5; // rdi
  hkVector4f *v6; // rsi
  hkVector4f *v7; // rbp
  hkVector4f *v8; // rbx
  __m128 v9; // xmm1
  char result; // al
  __m128 v11; // xmm2
  __m128 v12; // [rsp+20h] [rbp-38h]
  __m128 v13; // [rsp+30h] [rbp-28h]
  __m128 v14; // [rsp+40h] [rbp-18h]
  __int64 v15; // [rsp+60h] [rbp+8h]

  v4 = p2->m_quad;
  v5 = p1;
  v6 = p0;
  v7 = intersection;
  v8 = p2;
  v9 = _mm_unpacklo_ps(p0->m_quad, p1->m_quad);
  v14 = _mm_shuffle_ps(_mm_unpackhi_ps(p0->m_quad, p1->m_quad), p2->m_quad, 228);
  v12 = _mm_movelh_ps(v9, v4);
  v13 = _mm_shuffle_ps(_mm_movehl_ps(v12, v9), v4, 212);
  if ( hkMatrix3f::invert((hkMatrix3f *)&v12, (hkResult *)&v15, 0.00000011920929)->m_enum )
    return 0;
  result = 1;
  v11 = _mm_xor_ps(
          _mm_movelh_ps(
            _mm_unpacklo_ps(_mm_shuffle_ps(v6->m_quad, v6->m_quad, 255), _mm_shuffle_ps(v5->m_quad, v5->m_quad, 255)),
            _mm_unpacklo_ps(_mm_shuffle_ps(v8->m_quad, v8->m_quad, 255), aabbOut.m_quad)),
          (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64));
  v7->m_quad = _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v13), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v12)),
                 _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v14));
  return result;
}

// File Line: 262
// RVA: 0xCBA110
char __fastcall hkGeometryProcessing::intersectLineWithPlane(hkVector4f *x0, hkVector4f *x1, hkVector4f *plane, hkSimdFloat32 *toi)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm4
  char result; // al
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
hkSimdFloat32 *__fastcall hkGeometryProcessing::squaredDistanceFromPointToLine(hkSimdFloat32 *result, hkVector4f *p, hkVector4f *p0, hkVector4f *p1, hkSimdFloat32 *toi)
{
  __m128 v5; // xmm4
  __m128 v6; // xmm5
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm0
  hkSimdFloat32 v11; // xmm2
  __m128 v12; // xmm1
  hkSimdFloat32 v13; // xmm3
  hkSimdFloat32 *v14; // rax
  __m128 v15; // xmm3
  __m128 v16; // xmm3

  v5 = _mm_sub_ps(p1->m_quad, p0->m_quad);
  v6 = _mm_sub_ps(p0->m_quad, p->m_quad);
  v7 = _mm_mul_ps(v5, v5);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_mul_ps(v6, v5);
  v10 = _mm_rcp_ps(v8);
  v11.m_real = _mm_sub_ps(
                 (__m128)0i64,
                 _mm_mul_ps(
                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v8, v10)), v10),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)),
                     _mm_shuffle_ps(v9, v9, 170))));
  *toi = (hkSimdFloat32)v11.m_real;
  v12 = _mm_cmpltps(v11.m_real, query.m_quad);
  v13.m_real = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v11.m_real, v12), _mm_andnot_ps(v12, query.m_quad)));
  *toi = (hkSimdFloat32)v13.m_real;
  v14 = result;
  v15 = _mm_add_ps(_mm_mul_ps(v13.m_real, v5), v6);
  v16 = _mm_mul_ps(v15, v15);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                     _mm_shuffle_ps(v16, v16, 170));
  return v14;
}

// File Line: 333
// RVA: 0xCBA260
hkSimdFloat32 *__fastcall hkGeometryProcessing::squaredDistanceFromPointToLine(hkSimdFloat32 *result, hkVector4f *p, hkVector4f *p0, hkVector4f *p1, hkVector4f *normalOut, float *baryOut)
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
  v13 = _mm_cmpltps(v12, query.m_quad);
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
hkSimdFloat32 *__fastcall hkGeometryProcessing::squaredDistanceFromPointToTriangle(hkSimdFloat32 *result, hkVector4f *p, hkVector4f *p0, hkVector4f *p1, hkVector4f *p2, hkVector4f *normalOut, hkVector4f *baryOut)
{
  __m128 v7; // xmm11
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
  __m128 v64; // xmm10
  __m128 v65; // xmm10
  __m128 v66; // xmm9
  __m128 v67; // xmm9
  __m128 v68; // xmm13
  __m128 v69; // xmm13
  __m128 v70; // xmm1
  __m128 v71; // xmm2
  __m128 v72; // xmm10
  __m128i v73; // xmm5
  int v74; // eax
  signed int v75; // edx
  hkVector4f v76; // xmm4
  __m128 v77; // xmm11
  __m128 v78; // xmm0
  __m128 v79; // xmm11
  __m128i v80; // xmm2
  __m128 v81; // xmm1
  __m128 v83; // [rsp+0h] [rbp-C8h]
  __m128 v84; // [rsp+10h] [rbp-B8h]
  __m128 v85; // [rsp+20h] [rbp-A8h]

  v7 = query.m_quad;
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
            _mm_cmpleps(v14, (__m128)0i64),
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
    v7 = query.m_quad;
  }
  if ( (_mm_movemask_ps(_mm_cmpltps(*(__m128 *)&epsilon, v39)) & 7) == 7 )
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
    v62 = _mm_cmpltps(v61, v7);
    v63 = _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v62, v7), _mm_and_ps(v61, v62)));
    v64 = _mm_sub_ps(v46, _mm_mul_ps(_mm_shuffle_ps(v63, v63, 0), v42));
    v83 = v64;
    v65 = _mm_mul_ps(v64, v64);
    v66 = _mm_sub_ps(v47, _mm_mul_ps(_mm_shuffle_ps(v63, v63, 85), v43));
    v84 = v66;
    v67 = _mm_mul_ps(v66, v66);
    v68 = _mm_sub_ps(v48, _mm_mul_ps(_mm_shuffle_ps(v63, v63, 170), v44));
    v85 = v68;
    v69 = _mm_mul_ps(v68, v68);
    v70 = _mm_unpacklo_ps(v65, v67);
    v71 = _mm_movelh_ps(v70, v69);
    v72 = _mm_add_ps(
            _mm_shuffle_ps(_mm_unpackhi_ps(v65, v67), v69, 228),
            _mm_add_ps(v71, _mm_shuffle_ps(_mm_movehl_ps(v71, v70), v69, 212)));
    v73 = (__m128i)_mm_min_ps(
                     _mm_shuffle_ps(v72, v72, 170),
                     _mm_min_ps(_mm_shuffle_ps(v72, v72, 85), _mm_shuffle_ps(v72, v72, 0)));
    v74 = _mm_movemask_ps(_mm_cmpeqps(v72, (__m128)v73));
    if ( v74 & 7 )
      v75 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[v74];
    else
      v75 = -1;
    v76.m_quad = (__m128)*((_OWORD *)&v83 + v75);
    if ( baryOut )
    {
      v77 = _mm_sub_ps(v7, v63);
      v78 = _mm_unpacklo_ps(v77, v63);
      v79 = _mm_shuffle_ps(_mm_unpackhi_ps(v77, v63), (__m128)0i64, 228);
      v80 = (__m128i)_mm_movelh_ps(v78, (__m128)0i64);
      _mm_store_si128((__m128i *)&v83, v80);
      v81 = _mm_shuffle_ps(_mm_movehl_ps((__m128)v80, v78), (__m128)0i64, 212);
      _mm_store_si128((__m128i *)&v85, (__m128i)_mm_shuffle_ps(v79, v79, 137));
      _mm_store_si128((__m128i *)&v84, (__m128i)_mm_shuffle_ps(v81, v81, 146));
      *baryOut = *((hkVector4f *)&v83 + v75);
    }
    _mm_store_si128((__m128i *)result, v73);
    *normalOut = (hkVector4f)v76.m_quad;
  }
  return result;
}

// File Line: 356
// RVA: 0xCBA800
hkSimdFloat32 *__fastcall hkGeometryProcessing::nearestDistanceBetweenLines(hkSimdFloat32 *result, hkVector4f *a0, hkVector4f *a1, hkVector4f *b0, hkVector4f *b1, hkSimdFloat32 *u, hkSimdFloat32 *v)
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
  hkSimdFloat32 v21; // xmm5
  __m128 v22; // xmm3
  __m128 v23; // xmm5
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  hkSimdFloat32 v28; // xmm0
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
    v20 = _mm_cmpltps(v19, query.m_quad);
    v21.m_real = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v19, v20), _mm_andnot_ps(v20, query.m_quad)));
    *v = (hkSimdFloat32)v21.m_real;
    v22 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
            _mm_shuffle_ps(v12, v12, 170));
    v23 = _mm_add_ps(_mm_mul_ps(v21.m_real, v7), b0->m_quad);
    v24 = _mm_mul_ps(_mm_sub_ps(a0->m_quad, v23), v8);
    v25 = _mm_rcp_ps(v22);
    v26 = _mm_sub_ps(
            (__m128)0i64,
            _mm_mul_ps(
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v25)), v25),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                _mm_shuffle_ps(v24, v24, 170))));
    v27 = _mm_cmpltps(v26, query.m_quad);
    v28.m_real = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v27, query.m_quad), _mm_and_ps(v27, v26)));
    *u = (hkSimdFloat32)v28.m_real;
    v29 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v8, v28.m_real), a0->m_quad), v23);
    v30 = _mm_mul_ps(v29, v29);
    v31 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
            _mm_shuffle_ps(v30, v30, 170));
    v32 = _mm_rsqrt_ps(v31);
    result->m_real = _mm_andnot_ps(
                       _mm_cmpleps(v31, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v32), v32)),
                           _mm_mul_ps(*(__m128 *)_xmm, v32)),
                         v31));
  }
  return result;
}           _mm_m

// File Line: 399
// RVA: 0xCBAAB0
bool __fastcall hkGeometryProcessing::checkPointInsideTriangle(hkVector4f *p, hkVector4f *a, hkVector4f *b, hkVector4f *c, hkSimdFloat32 *epsilon)
{
  __m128 v5; // xmm4
  __m128 v6; // xmm1
  __m128 v7; // xmm6
  __m128 v8; // xmm5
  __m128 v9; // xmm7
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
  v9 = epsilon->m_real;
  v10 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v6), _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v7));
  v11 = _mm_shuffle_ps(v10, v10, 201);
  v12 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v5));
  v13 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v11);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 170))) < COERCE_FLOAT(*epsilon) )
    return 0;
  v15 = _mm_sub_ps(c->m_quad, p->m_quad);
  v16 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v5), _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v15));
  v17 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v11);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 170))) < v9.m128_f32[0] )
    return 0;
  v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v8));
  v19 = _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v11);
  return (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 170))) >= v9.m128_f32[0];
}

// File Line: 410
// RVA: 0xCBABD0
void __fastcall hkGeometryProcessing::buildTransposedArray(hkArray<hkVector4f,hkContainerHeapAllocator> *vertices, hkArray<hkFourTransposedPointsf,hkContainerHeapAllocator> *output)
{
  int v2; // ebp
  __int64 v3; // r14
  int v4; // ebp
  int v5; // eax
  int v6; // ebx
  int v7; // er9
  unsigned __int128 v8; // di
  int v9; // eax
  __int64 v10; // r9
  __int64 v11; // rdx
  __m128 *v12; // r10
  __int64 v13; // r8
  __int64 v14; // rax
  __m128 v15; // xmm5
  __m128 v16; // xmm4
  __m128 v17; // xmm6
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __int128 *v21; // rcx
  signed __int64 v22; // rdx
  _OWORD *v23; // rax
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  __m128 v26; // [rsp+30h] [rbp-68h]
  __m128 v27; // [rsp+40h] [rbp-58h]
  __m128 v28; // [rsp+50h] [rbp-48h]
  __m128 v29; // [rsp+60h] [rbp-38h]
  hkResult result; // [rsp+A0h] [rbp+8h]

  v2 = vertices->m_size;
  v3 = output->m_size;
  _mm_store_si128((__m128i *)&v26, (__m128i)aabbOut.m_quad);
  _mm_store_si128((__m128i *)&v27, (__m128i)aabbOut.m_quad);
  _mm_store_si128((__m128i *)&v28, (__m128i)aabbOut.m_quad);
  _mm_store_si128((__m128i *)&v29, (__m128i)aabbOut.m_quad);
  v4 = (v2 + 3) >> 2;
  v5 = output->m_capacityAndFlags & 0x3FFFFFFF;
  v6 = 0;
  v7 = v3 + v4;
  v8 = __PAIR__((unsigned __int64)vertices, (unsigned __int64)output);
  if ( v5 < (signed int)v3 + v4 )
  {
    v9 = 2 * v5;
    if ( v7 < v9 )
      v7 = v9;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, output, v7, 48);
  }
  *(_DWORD *)(v8 + 8) += v4;
  v10 = *(signed int *)(*((_QWORD *)&v8 + 1) + 8i64);
  v11 = 0i64;
  v12 = (__m128 *)(*(_QWORD *)v8 + 48 * v3);
  if ( v10 > 0 )
  {
    v13 = 0i64;
    do
    {
      v14 = v11++;
      ++v6;
      *(&v26 + v14) = *(__m128 *)(v13 + **((_QWORD **)&v8 + 1));
      v15 = v29;
      v16 = v28;
      v17 = v27;
      v18 = v26;
      if ( v11 == 4 )
      {
        v6 = 0;
        v11 = 0i64;
        v12 += 3;
        v19 = _mm_shuffle_ps(v28, v29, 68);
        v20 = _mm_shuffle_ps(v26, v27, 68);
        v12[-3] = _mm_shuffle_ps(v20, v19, 136);
        v12[-2] = _mm_shuffle_ps(v20, v19, 221);
        v12[-1] = _mm_shuffle_ps(_mm_shuffle_ps(v18, v17, 238), _mm_shuffle_ps(v16, v15, 238), 136);
      }
      v13 += 16i64;
      --v10;
    }
    while ( v10 );
    if ( v6 )
    {
      if ( v6 < 4i64 )
      {
        v21 = (__int128 *)(&v26 + v6);
        v22 = 4i64 - v6;
        do
        {
          v23 = v21;
          ++v21;
          *v23 = v18;
          v18 = v26;
          --v22;
        }
        while ( v22 );
        v15 = v29;
        v16 = v28;
        v17 = v27;
      }
      v24 = _mm_shuffle_ps(v18, v17, 68);
      v25 = _mm_shuffle_ps(v16, v15, 68);
      *v12 = _mm_shuffle_ps(v24, v25, 136);
      v12[1] = _mm_shuffle_ps(v24, v25, 221);
      v12[2] = _mm_shuffle_ps(_mm_shuffle_ps(v18, v17, 238), _mm_shuffle_ps(v16, v15, 238), 136);
    }
  }
}

// File Line: 434
// RVA: 0xCBADB0
void __fastcall hkGeometryProcessing::getSupportingVertex(hkArrayBase<hkFourTransposedPointsf> *transposedVertices, hkVector4f *direction, hkVector4f *vertexOut)
{
  __m128 v3; // xmm4
  hkFourTransposedPointsf *v4; // r9
  signed __int64 v5; // rcx
  __m128i v6; // xmm5
  hkVector4f *v7; // r10
  __m128 v8; // xmm7
  __m128 v9; // xmm8
  __m128 v10; // xmm4
  __m128i v11; // xmm6
  __m128 v12; // xmm3
  __m128i v13; // xmm9
  __m128 *v14; // rax
  signed __int64 v15; // rcx
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
  unsigned int v26; // er8
  unsigned __int64 v27; // rdx
  __int64 v28; // rcx
  hkVector4f v29; // ST00_16

  v3 = direction->m_quad;
  v4 = transposedVertices->m_data;
  v5 = transposedVertices->m_size;
  v6 = (__m128i)xmmword_141A720C0;
  v7 = vertexOut;
  v8 = _mm_shuffle_ps(v3, v3, 0);
  v9 = _mm_shuffle_ps(direction->m_quad, direction->m_quad, 85);
  v10 = _mm_shuffle_ps(v3, v3, 170);
  v11 = (__m128i)xmmword_141A720C0;
  v12 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(v4->m_vertices[1].m_quad, v9), _mm_mul_ps(v4->m_vertices[0].m_quad, v8)),
          _mm_mul_ps(v4->m_vertices[2].m_quad, v10));
  if ( v5 > 1 )
  {
    v13 = _mm_load_si128((const __m128i *)&xmmword_141A720B0);
    v14 = &v4[1].m_vertices[2].m_quad;
    v15 = v5 - 1;
    do
    {
      v16 = v14[-1];
      v17 = v14[-2];
      v18 = *v14;
      v6 = _mm_add_epi32(v6, v13);
      v14 += 3;
      v19 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v16, v9), _mm_mul_ps(v17, v8)), _mm_mul_ps(v18, v10));
      v20 = (__m128i)_mm_cmpltps(v12, v19);
      v12 = _mm_or_ps(_mm_and_ps(v19, (__m128)v20), _mm_andnot_ps((__m128)v20, v12));
      v11 = _mm_or_si128(_mm_andnot_si128(v20, v11), _mm_and_si128(v20, v6));
      --v15;
    }
    while ( v15 );
  }
  v21 = _mm_shuffle_ps(v12, v12, 57);
  v22 = (__m128i)_mm_cmpltps(v12, v21);
  v23 = _mm_max_ps(v21, v12);
  v24 = _mm_or_si128(_mm_and_si128(_mm_shuffle_epi32(v11, 57), v22), _mm_andnot_si128(v22, v11));
  v25 = (__m128i)_mm_cmpltps(v23, _mm_shuffle_ps(v23, v23, 170));
  v26 = _mm_cvtsi128_si32(_mm_or_si128(_mm_and_si128(_mm_shuffle_epi32(v24, 170), v25), _mm_andnot_si128(v25, v24)));
  v27 = (unsigned __int64)&v4[(unsigned __int64)v26 >> 2];
  v28 = v26 & 3;
  v29.m_quad.m128_i32[3] = v26 | 0x3F000000;
  v29.m_quad.m128_i32[0] = *(_DWORD *)(v27 + 4 * v28);
  v29.m_quad.m128_i32[1] = *(_DWORD *)(v27 + 4 * v28 + 16);
  v29.m_quad.m128_i32[2] = *(_DWORD *)(v27 + 4 * v28 + 32);
  *v7 = (hkVector4f)v29.m_quad;
}

// File Line: 442
// RVA: 0xCBEAA0
bool __fastcall hkGeometryProcessingInternals::generateRandomDistribution(hkgpMesh *mesh, int numPoints, hkArray<hkVector4f,hkContainerHeapAllocator> *points, hkPseudoRandomGenerator *rndGenerator)
{
  int v4; // esi
  hkPseudoRandomGenerator *v5; // r13
  hkArray<hkVector4f,hkContainerHeapAllocator> *v6; // rbx
  hkgpMesh *v7; // r15
  __m128 v8; // xmm8
  int v9; // er14
  int v10; // edi
  __m128 v11; // xmm7
  bool v12; // zf
  int v13; // ecx
  float v14; // xmm0_4
  int v15; // ecx
  signed int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // eax
  __m128 v20; // xmm1
  hkVector4f x; // [rsp+30h] [rbp-B8h]
  hkVector4fComparison inside; // [rsp+40h] [rbp-A8h]
  hkVector4f normal; // [rsp+50h] [rbp-98h]
  hkSimdFloat32 result; // [rsp+60h] [rbp-88h]
  __m128 v26; // [rsp+70h] [rbp-78h]
  __m128 v27; // [rsp+80h] [rbp-68h]

  v4 = numPoints;
  v5 = rndGenerator;
  v6 = points;
  v7 = mesh;
  hkgpMesh::getBoundingBox(mesh, (hkAabb *)&v26);
  v8 = v26;
  v9 = 8 * v4;
  v10 = 0;
  v11 = _mm_sub_ps(v27, v26);
  v12 = v4 == 0;
  if ( v4 )
  {
    do
    {
      v13 = 1664525 * v5->m_current + 1013904223;
      v14 = (float)v13;
      v15 = 1664525 * v13 + 1013904223;
      v16 = v15;
      v17 = 1664525 * v15 + 1013904223;
      x.m_quad.m128_f32[0] = v14 * 2.3283064e-10;
      x.m_quad.m128_f32[1] = (float)v16 * 2.3283064e-10;
      v18 = 1664525 * v17 + 1013904223;
      v5->m_current = v18;
      x.m_quad.m128_f32[2] = (float)v17 * 2.3283064e-10;
      x.m_quad.m128_f32[3] = (float)v18 * 2.3283064e-10;
      x.m_quad = _mm_add_ps(_mm_mul_ps(x.m_quad, v11), v8);
      hkgpMesh::squaredDistanceToPoint(v7, &result, &x, &normal, &inside);
      if ( _mm_movemask_ps(inside.m_mask) )
      {
        v19 = v6->m_capacityAndFlags & 0x3FFFFFFF;
        v20 = _mm_shuffle_ps(x.m_quad, _mm_unpackhi_ps(x.m_quad, query.m_quad), 196);
        x.m_quad = v20;
        if ( v6->m_size == v19 )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 16);
          v20 = x.m_quad;
        }
        v10 = 0;
        v6->m_data[v6->m_size++].m_quad = v20;
        --v4;
      }
      else if ( ++v10 > v9 )
      {
        break;
      }
    }
    while ( v4 );
    v12 = v4 == 0;
  }
  return v12;
}

// File Line: 467
// RVA: 0xCBAF40
bool __fastcall hkGeometryProcessing::generateRandomDistribution(hkGeometry *geometry, int numPoints, hkArray<hkVector4f,hkContainerHeapAllocator> *points, int seed)
{
  return hkGeometryProcessing::generateUniformDistribution(geometry, numPoints, points, seed, 0, 0i64);
}

// File Line: 473
// RVA: 0xCBAF60
__int64 __usercall hkGeometryProcessing::generateUniformDistribution@<rax>(hkGeometry *geometry@<rcx>, int numPoints@<edx>, hkArray<hkVector4f,hkContainerHeapAllocator> *points@<r8>, int maxIterations@<r9d>, __m128 a5@<xmm0>, __m128 a6@<xmm2>, int seed, hkGeometryProcessing::IFunction<hkVector4f,float> *densityFunction)
{
  int v8; // esi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v9; // rbx
  __int64 v10; // r14
  hkGeometry *v11; // rdi
  hkGeometryProcessing::ConstFunction<hkGeometryProcessing::IFunction<hkVector4f,float> > *v12; // r15
  __m128 v13; // xmm1
  __int64 v14; // rdi
  unsigned __int8 v15; // bl
  signed __int64 v16; // r12
  int v17; // er9
  __int64 v18; // r13
  __m128 *v19; // rsi
  __m128i v20; // xmm6
  __m128i v21; // xmm7
  unsigned __int64 v22; // r14
  hkcdDynamicTree::CodecRawUlong *v23; // rcx
  unsigned __int64 v24; // rdi
  hkcdDynamicTree::CodecRawUlong *v25; // r8
  unsigned __int64 v26; // rbx
  __m128 v27; // xmm7
  __m128 v28; // xmm8
  unsigned __int64 v29; // r9
  __m128 *v30; // rbx
  hkcdDynamicTree::CodecRawUlong *v31; // r9
  __m128 v32; // xmm9
  __m128 v33; // xmm10
  __m128 v34; // xmm1
  __int64 v35; // rax
  __int64 v36; // rcx
  __m128 v37; // xmm5
  __m128 v38; // xmm3
  __m128 v39; // xmm2
  __m128 v40; // xmm6
  __m128 v41; // xmm3
  __m128 v42; // xmm2
  __m128 v43; // xmm5
  __m128 v44; // xmm6
  __m128 v45; // xmm2
  __m128 v46; // xmm6
  unsigned __int64 v47; // r11
  unsigned __int64 v48; // r10
  signed __int64 v49; // rax
  bool v50; // zf
  __m128 v51; // xmm2
  signed int v52; // ecx
  signed int v53; // eax
  int v54; // er8
  int v55; // ebx
  int v56; // er14
  __int64 v57; // rdi
  hkVector4f v58; // xmm0
  hkLifoAllocator *v59; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::ClosestFromPointWrapper<hkGeometryProcessingInternals::NearestFeaturePolicy> *v60; // r9
  hkcdDynamicTree::CodecRawUlong *v61; // rcx
  unsigned __int64 v62; // rdx
  int v63; // eax
  char *v64; // rsi
  signed int v65; // ebx
  hkLifoAllocator *v66; // rax
  int v67; // er8
  __m128 *v68; // rbx
  __int64 v69; // r13
  __m128 *v70; // rsi
  __m128 v71; // xmm1
  __m128 v72; // xmm0
  __m128 v73; // xmm2
  hkcdDynamicTree::CodecRawUlong *v74; // r11
  unsigned __int64 v75; // rdx
  unsigned __int64 v76; // r14
  __int64 v77; // rdi
  __m128 v78; // xmm5
  __m128 v79; // xmm6
  __m128i v80; // xmm4
  __m128i v81; // xmm3
  hkcdDynamicTree::CodecRawUlong *v82; // r9
  unsigned __int64 v83; // rax
  hkcdDynamicTree::CodecRawUlong *v84; // rbx
  unsigned __int64 v85; // r8
  hkcdDynamicTree::CodecRawUlong *v86; // rcx
  unsigned __int64 v87; // rdx
  unsigned __int64 v88; // rcx
  __int64 v89; // rax
  __m128 v90; // xmm2
  __m128 v91; // xmm1
  __int64 v92; // rax
  __m128 v93; // xmm2
  hkcdDynamicTree::CodecRawUlong *v94; // r8
  unsigned __int64 v95; // rbx
  __m128 v96; // xmm7
  __m128 v97; // xmm8
  unsigned __int64 v98; // r9
  __m128 *v99; // rbx
  hkcdDynamicTree::CodecRawUlong *v100; // r9
  __m128 v101; // xmm9
  __m128 v102; // xmm10
  __m128 v103; // xmm1
  __int64 v104; // rax
  __int64 v105; // rcx
  __m128 v106; // xmm5
  __m128 v107; // xmm2
  __m128 v108; // xmm3
  __m128 v109; // xmm6
  __m128 v110; // xmm2
  __m128 v111; // xmm5
  __m128 v112; // xmm3
  __m128 v113; // xmm3
  __m128 v114; // xmm6
  __m128 v115; // xmm6
  unsigned __int64 v116; // r11
  unsigned __int64 v117; // r10
  signed __int64 v118; // rax
  __m128 v119; // xmm1
  __m128 v120; // xmm2
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> v122; // [rsp+30h] [rbp-D0h]
  __int64 v123; // [rsp+48h] [rbp-B8h]
  unsigned __int64 branch; // [rsp+50h] [rbp-B0h]
  hkArray<hkVector4f,hkContainerHeapAllocator> pointsa; // [rsp+58h] [rbp-A8h]
  char *array; // [rsp+68h] [rbp-98h]
  int v127; // [rsp+70h] [rbp-90h]
  int v128; // [rsp+74h] [rbp-8Ch]
  __int64 v129; // [rsp+78h] [rbp-88h]
  __int64 v130; // [rsp+80h] [rbp-80h]
  hkPseudoRandomGenerator rndGenerator; // [rsp+88h] [rbp-78h]
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> tree; // [rsp+90h] [rbp-70h]
  hkGeometryProcessing::ConstFunction<hkGeometryProcessing::IFunction<hkVector4f,float> > *v133; // [rsp+B8h] [rbp-48h]
  __int64 v134; // [rsp+C0h] [rbp-40h]
  __int64 v135; // [rsp+C8h] [rbp-38h]
  hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64> stackInstance; // [rsp+D0h] [rbp-30h]
  __int128 v137; // [rsp+F0h] [rbp-10h]
  int v138; // [rsp+100h] [rbp+0h]
  hkgpMesh mesh; // [rsp+110h] [rbp+10h]
  int v140; // [rsp+248h] [rbp+148h]
  __int64 result; // [rsp+250h] [rbp+150h]
  int v142; // [rsp+258h] [rbp+158h]

  v142 = maxIterations;
  v140 = numPoints;
  v8 = maxIterations;
  v9 = points;
  v10 = (unsigned int)numPoints;
  v11 = geometry;
  if ( !(_S1_43 & 1) )
  {
    a5.m128_i32[0] = (signed int)FLOAT_1_0;
    _S1_43 |= 1u;
    LODWORD(unityFunction.m_value) = (_DWORD)FLOAT_1_0;
    unityFunction.vfptr = (hkGeometryProcessing::IFunction<hkVector4f,float>Vtbl *)&hkGeometryProcessing::ConstFunction<hkGeometryProcessing::IFunction<hkVector4f,float>>::`vftable';
    atexit(hkGeometryProcessing::generateUniformDistribution_::_2_::_dynamic_atexit_destructor_for__unityFunction__);
  }
  v12 = &unityFunction;
  rndGenerator.m_seed = seed;
  rndGenerator.m_current = seed;
  if ( densityFunction )
    v12 = (hkGeometryProcessing::ConstFunction<hkGeometryProcessing::IFunction<hkVector4f,float> > *)densityFunction;
  v133 = v12;
  hkgpMesh::hkgpMesh(&mesh);
  hkgpMesh::appendFromGeometry(&mesh, v11, (hkTransformf *)&transform, -1, 0, 1);
  hkgpMesh::assignVertexNormals(&mesh);
  v13 = 0i64;
  hkgpMesh::rebuildTrianglesTree(&mesh, 0.0);
  v14 = v9->m_size;
  if ( !hkGeometryProcessingInternals::generateRandomDistribution(&mesh, v10, v9, &rndGenerator) )
  {
    v15 = 0;
    goto LABEL_88;
  }
  if ( v8 <= 0 )
  {
LABEL_87:
    v15 = 1;
    goto LABEL_88;
  }
  v128 = 2147483648;
  array = 0i64;
  v127 = 0;
  v16 = (signed __int64)&v9->m_data[v14];
  v122.m_nodes.m_size = 0;
  v122.m_nodes.m_data = 0i64;
  v122.m_nodes.m_capacityAndFlags = 2147483648;
  v122.m_firstFree = 0i64;
  branch = 0i64;
  tree.m_root = v16;
  v123 = 0i64;
  if ( (signed int)v10 > 0 )
  {
    v17 = v10;
    if ( (signed int)v10 < 0 )
      v17 = 0;
    hkArrayUtil::_reserve(
      (hkResult *)&seed,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      v17,
      8);
  }
  v127 = v10;
  if ( (signed int)v10 > 0 )
  {
    v18 = 0i64;
    v19 = (__m128 *)v16;
    result = v10;
    do
    {
      v20 = _mm_srli_si128(_mm_slli_si128((__m128i)_mm_add_ps(*v19, aabbOut.m_quad), 4), 4);
      v21 = _mm_srli_si128(_mm_slli_si128((__m128i)_mm_sub_ps(*v19, aabbOut.m_quad), 4), 4);
      if ( !v122.m_firstFree )
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
          &v122,
          (hkResult *)&seed,
          1);
      v22 = v122.m_firstFree;
      v23 = v122.m_nodes.m_data;
      v24 = v122.m_firstFree << 6;
      v122.m_firstFree = v122.m_nodes.m_data[(signed __int64)SLODWORD(v122.m_firstFree)].m_aabb.m_min.m_quad.m128_u64[0];
      *(unsigned __int64 *)((char *)v122.m_nodes.m_data->m_children + v24) = 0i64;
      *(unsigned __int64 *)((char *)&v23->m_children[1] + v24) = v16;
      *(__m128i *)((char *)&v23->m_aabb.m_min + v24) = v21;
      *(__m128i *)((char *)&v23->m_aabb.m_max + v24) = v20;
      v25 = v122.m_nodes.m_data;
      v26 = branch;
      v27 = *(__m128 *)((char *)&v122.m_nodes.m_data->m_aabb.m_min.m_quad + v24);
      v28 = *(__m128 *)((char *)&v122.m_nodes.m_data->m_aabb.m_max.m_quad + v24);
      if ( branch )
      {
        v29 = v122.m_firstFree;
        if ( !v122.m_firstFree )
        {
          hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
            &v122,
            (hkResult *)&densityFunction,
            LODWORD(v122.m_firstFree) + 1);
          v29 = v122.m_firstFree;
          v25 = v122.m_nodes.m_data;
        }
        v30 = &v25[v26].m_aabb.m_min.m_quad;
        v31 = &v25[v29];
        v122.m_firstFree = v25[(signed __int64)SLODWORD(v122.m_firstFree)].m_aabb.m_min.m_quad.m128_u64[0];
        if ( v30[2].m128_i32[2] )
        {
          v32 = _mm_add_ps(v28, v27);
          v33 = _mm_sub_ps(v28, v27);
          do
          {
            v34 = v30[1];
            v35 = (__int64)&v25[v30[3].m128_u64[0]];
            v36 = (__int64)&v25[v30[2].m128_u64[1]];
            *v30 = _mm_min_ps(*v30, v27);
            v130 = v35;
            v129 = v36;
            v30[1] = _mm_max_ps(v34, v28);
            v37 = *(__m128 *)(v35 + 16);
            v38 = *(__m128 *)(v36 + 16);
            v25 = v122.m_nodes.m_data;
            v39 = v38;
            v40 = v37;
            v41 = _mm_add_ps(_mm_sub_ps(v38, *(__m128 *)v36), v33);
            v42 = _mm_sub_ps(_mm_add_ps(v39, *(__m128 *)v36), v32);
            v43 = _mm_add_ps(_mm_sub_ps(v37, *(__m128 *)v35), v33);
            v44 = _mm_sub_ps(_mm_add_ps(v40, *(__m128 *)v35), v32);
            v45 = _mm_mul_ps(v42, v42);
            v46 = _mm_mul_ps(v44, v44);
            v30 = (__m128 *)*(&v129
                            + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v45, v45, 85))
                                                     + COERCE_FLOAT(_mm_shuffle_ps(v45, v45, 0)))
                                             + COERCE_FLOAT(_mm_shuffle_ps(v45, v45, 170)))
                                     * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 85))
                                                     + COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 0)))
                                             + COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v43, v43, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v43, v43, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v43, v43, 170))) * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v46, v46, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v46, v46, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v46, v46, 170))))));
          }
          while ( v30[2].m128_i32[2] );
        }
        v47 = v30[2].m128_u64[0];
        v48 = v31 - v25;
        if ( v47 )
          v25->m_children[(v25[v47].m_children[1] == ((char *)v30 - (char *)v25) >> 6) + 8 * v47] = v48;
        else
          branch = v31 - v25;
        v31->m_parent = v30[2].m128_u64[0];
        v49 = (char *)v30 - (char *)v122.m_nodes.m_data;
        v31->m_children[1] = v22;
        v31->m_children[0] = v49 >> 6;
        v30[2].m128_u64[0] = v48;
        *(unsigned __int64 *)((char *)&v122.m_nodes.m_data->m_parent + v24) = v48;
        a5 = _mm_min_ps(*v30, v27);
        v13 = _mm_max_ps(v30[1], v28);
        v31->m_aabb.m_min.m_quad = a5;
        v31->m_aabb.m_max.m_quad = v13;
      }
      else
      {
        branch = v22;
        *(unsigned __int64 *)((char *)&v122.m_nodes.m_data->m_parent + v24) = 0i64;
      }
      LODWORD(v123) = v123 + 1;
      *(_QWORD *)&array[v18] = v22;
      v12->vfptr->evaluate((hkGeometryProcessing::IFunction<hkVector4f,float> *)&v12->vfptr, (hkVector4f *)v16);
      ++v19;
      v16 += 16i64;
      v18 += 8i64;
      v50 = result-- == 1;
      v13.m128_f32[0] = a5.m128_f32[0];
      v13 = _mm_shuffle_ps(v13, v13, 0);
      v51 = _mm_mul_ps(v13, v19[-1]);
      a5 = _mm_unpackhi_ps(v51, v13);
      a6 = _mm_shuffle_ps(v51, a5, 196);
      v19[-1] = a6;
    }
    while ( !v50 );
    LODWORD(v10) = v140;
    v16 = tree.m_root;
    v8 = v142;
  }
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::rebuildBranchSAH(
    (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)&v122,
    branch,
    (hkBool)1,
    32,
    16);
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>::compactIndices((hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr> *)&v122);
  v52 = 256;
  v53 = 2 * v10;
  v54 = 2147483648;
  pointsa.m_data = 0i64;
  pointsa.m_size = 0;
  seed = 256;
  pointsa.m_capacityAndFlags = 2147483648;
  if ( 2 * (signed int)v10 < 256
    || (v52 = 0x2000, seed = 0x2000, v53 > 0x2000)
    || (v52 = 2 * v10, seed = 2 * v10, v53 > 0) )
  {
    hkArrayUtil::_reserve(
      (hkResult *)&densityFunction,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &pointsa,
      v52,
      16);
    v54 = pointsa.m_capacityAndFlags;
    v52 = seed;
  }
  v55 = 0;
  LODWORD(densityFunction) = 0;
  if ( v8 <= 0 )
  {
LABEL_81:
    pointsa.m_size = 0;
    if ( v54 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        pointsa.m_data,
        16 * v54);
    pointsa.m_data = 0i64;
    pointsa.m_capacityAndFlags = 2147483648;
    v122.m_nodes.m_size = 0;
    if ( v122.m_nodes.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v122.m_nodes.m_data,
        v122.m_nodes.m_capacityAndFlags << 6);
    v122.m_nodes.m_data = 0i64;
    v122.m_nodes.m_capacityAndFlags = 2147483648;
    v127 = 0;
    if ( v128 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        8 * v128);
    goto LABEL_87;
  }
  while ( 1 )
  {
    pointsa.m_size = 0;
    if ( !hkGeometryProcessingInternals::generateRandomDistribution(&mesh, v52, &pointsa, &rndGenerator) )
      break;
    v56 = 0;
    if ( pointsa.m_size > 0 )
    {
      v57 = 0i64;
      do
      {
        stackInstance.m_stack.m_data = (unsigned __int64 *)&v129;
        v129 = 0i64;
        v137 = xmmword_141A712A0;
        v138 = 0;
        tree.m_nodes.m_data = 0i64;
        tree.m_nodes.m_size = 0;
        v58.m_quad = (__m128)pointsa.m_data[v57];
        *(hkVector4f *)&stackInstance.m_stack.m_localMemory = pointsa.m_data[v57];
        tree.m_nodes.m_capacityAndFlags = 2147483648;
        tree.m_numLeaves = 64;
        v59 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v61 = (hkcdDynamicTree::CodecRawUlong *)v59->m_cur;
        v62 = (unsigned __int64)&v61[8];
        if ( v59->m_slabSize < 512 || (void *)v62 > v59->m_end )
          v61 = (hkcdDynamicTree::CodecRawUlong *)hkLifoAllocator::allocateFromNewSlab(v59, 512);
        else
          v59->m_cur = (void *)v62;
        tree.m_nodes.m_data = v61;
        tree.m_firstFree = (unsigned __int64)v61;
        tree.m_nodes.m_capacityAndFlags = -2147483584;
        hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStoragePtr>,hkcdTreeQueriesStacks::Dynamic<64,unsigned __int64>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::ClosestFromPointWrapper<hkGeometryProcessingInternals::NearestFeaturePolicy>>(
          (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&v122,
          &tree,
          &stackInstance,
          v60);
        v63 = tree.m_nodes.m_size;
        v64 = (char *)tree.m_firstFree;
        if ( (hkcdDynamicTree::CodecRawUlong *)tree.m_firstFree == tree.m_nodes.m_data )
          v63 = 0;
        tree.m_nodes.m_size = v63;
        v65 = (8 * tree.m_numLeaves + 127) & 0xFFFFFF80;
        v66 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v67 = (v65 + 15) & 0xFFFFFFF0;
        if ( v65 > v66->m_slabSize || &v64[v67] != v66->m_cur || v66->m_firstNonLifoEnd == v64 )
          hkLifoAllocator::slowBlockFree(v66, v64, v67);
        else
          v66->m_cur = v64;
        tree.m_nodes.m_size = 0;
        if ( tree.m_nodes.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            tree.m_nodes.m_data,
            8 * tree.m_nodes.m_capacityAndFlags);
        if ( v129 )
        {
          v68 = *(__m128 **)(v129 + 48);
          v12->vfptr->evaluate((hkGeometryProcessing::IFunction<hkVector4f,float> *)&v12->vfptr, &pointsa.m_data[v56]);
          a6.m128_f32[0] = v58.m_quad.m128_f32[0];
          a6 = _mm_shuffle_ps(a6, a6, 0);
          pointsa.m_data[v57].m_quad = _mm_mul_ps(a6, pointsa.m_data[v57].m_quad);
          pointsa.m_data[v57].m_quad = _mm_shuffle_ps(
                                         pointsa.m_data[v57].m_quad,
                                         _mm_unpackhi_ps(pointsa.m_data[v57].m_quad, a6),
                                         196);
          *v68 = _mm_add_ps(pointsa.m_data[v57].m_quad, *v68);
        }
        ++v56;
        ++v57;
      }
      while ( v56 < pointsa.m_size );
      v55 = (signed int)densityFunction;
      v16 = tree.m_root;
      v8 = v142;
    }
    if ( v140 > 0 )
    {
      v69 = 0i64;
      v70 = (__m128 *)v16;
      v129 = (unsigned int)v140;
      do
      {
        v71 = *v70;
        v72 = _mm_shuffle_ps(v71, v71, 255);
        v73 = _mm_mul_ps(_mm_div_ps(query.m_quad, v72), *v70);
        *v70 = v73;
        v74 = v122.m_nodes.m_data;
        v75 = branch;
        v76 = *(_QWORD *)&array[v69];
        v77 = *(_QWORD *)&array[v69] << 6;
        v78 = *(__m128 *)((char *)&v122.m_nodes.m_data->m_aabb.m_min.m_quad + v77);
        v79 = *(__m128 *)((char *)&v122.m_nodes.m_data->m_aabb.m_max.m_quad + v77);
        v80 = _mm_srli_si128(_mm_slli_si128((__m128i)_mm_sub_ps(v73, aabbOut.m_quad), 4), 4);
        v81 = _mm_srli_si128(_mm_slli_si128((__m128i)_mm_add_ps(aabbOut.m_quad, v73), 4), 4);
        if ( v76 == branch )
        {
          branch = 0i64;
        }
        else
        {
          v82 = &v122.m_nodes.m_data[*(unsigned __int64 *)((char *)&v122.m_nodes.m_data->m_parent + v77)];
          v83 = v82->m_parent;
          v84 = &v122.m_nodes.m_data[v82->m_aabb.m_min.m_quad.m128_u64[6i64
                                                                     - (v82->m_children[1] == *(_QWORD *)&array[v69])]];
          if ( v83 )
          {
            v84->m_parent = v83;
            v122.m_nodes.m_data->m_children[(v122.m_nodes.m_data[v82->m_parent].m_children[1] == *(unsigned __int64 *)((char *)&v74->m_parent + v77))
                                          + 8 * v82->m_parent] = v84 - v122.m_nodes.m_data;
            v85 = *(unsigned __int64 *)((char *)&v74->m_parent + v77);
            v122.m_nodes.m_data[(signed __int64)(signed int)v85].m_aabb.m_min.m_quad.m128_u64[0] = v122.m_firstFree;
            v74 = v122.m_nodes.m_data;
            v122.m_firstFree = v85;
            v86 = &v122.m_nodes.m_data[v84->m_parent];
            while ( 1 )
            {
              v87 = v86->m_parent;
              v88 = (unsigned __int64)v74 + (((char *)v86 - (char *)v74) & 0xFFFFFFFFFFFFFFC0ui64);
              v89 = *(_QWORD *)(v88 + 40) << 6;
              v90 = *(__m128 *)((char *)&v74->m_aabb.m_min.m_quad + v89);
              v91 = *(__m128 *)((char *)&v74->m_aabb.m_max.m_quad + v89);
              v92 = *(_QWORD *)(v88 + 48) << 6;
              v93 = _mm_min_ps(v90, *(__m128 *)((char *)&v74->m_aabb.m_min.m_quad + v92));
              v71 = _mm_max_ps(v91, *(__m128 *)((char *)&v74->m_aabb.m_max.m_quad + v92));
              *(__m128 *)v88 = v93;
              *(__m128 *)(v88 + 16) = v71;
              v72 = _mm_and_ps(_mm_cmpleps(v79, v71), _mm_cmpleps(v93, v78));
              if ( (_mm_movemask_ps(v72) & 7) == 7 || !v87 )
                break;
              v74 = v122.m_nodes.m_data;
              v86 = &v122.m_nodes.m_data[v87];
              if ( !v86 )
                goto LABEL_62;
            }
            v74 = v122.m_nodes.m_data;
          }
          else
          {
            v122.m_nodes.m_data[(signed __int64)(signed int)branch].m_aabb.m_min.m_quad.m128_u64[0] = v122.m_firstFree;
            v122.m_firstFree = v75;
            branch = v84 - v122.m_nodes.m_data;
            v84->m_parent = 0i64;
            v74 = v122.m_nodes.m_data;
          }
        }
LABEL_62:
        *(__m128i *)((char *)&v74->m_aabb.m_min + v77) = v80;
        *(__m128i *)((char *)&v74->m_aabb.m_max + v77) = v81;
        v94 = v122.m_nodes.m_data;
        v95 = branch;
        v96 = *(__m128 *)((char *)&v122.m_nodes.m_data->m_aabb.m_min.m_quad + v77);
        v97 = *(__m128 *)((char *)&v122.m_nodes.m_data->m_aabb.m_max.m_quad + v77);
        if ( branch )
        {
          v98 = v122.m_firstFree;
          if ( !v122.m_firstFree )
          {
            hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
              &v122,
              (hkResult *)&result,
              LODWORD(v122.m_firstFree) + 1);
            v98 = v122.m_firstFree;
            v94 = v122.m_nodes.m_data;
          }
          v99 = &v94[v95].m_aabb.m_min.m_quad;
          v100 = &v94[v98];
          v122.m_firstFree = v94[(signed __int64)SLODWORD(v122.m_firstFree)].m_aabb.m_min.m_quad.m128_u64[0];
          if ( v99[2].m128_i32[2] )
          {
            v101 = _mm_add_ps(v97, v96);
            v102 = _mm_sub_ps(v97, v96);
            do
            {
              v103 = v99[1];
              v104 = (__int64)&v94[v99[3].m128_u64[0]];
              v105 = (__int64)&v94[v99[2].m128_u64[1]];
              *v99 = _mm_min_ps(*v99, v96);
              v135 = v104;
              v134 = v105;
              v99[1] = _mm_max_ps(v103, v97);
              v106 = *(__m128 *)(v104 + 16);
              v107 = *(__m128 *)(v105 + 16);
              v94 = v122.m_nodes.m_data;
              v108 = v107;
              v109 = v106;
              v110 = _mm_add_ps(_mm_sub_ps(v107, *(__m128 *)v105), v102);
              v111 = _mm_add_ps(_mm_sub_ps(v106, *(__m128 *)v104), v102);
              v112 = _mm_sub_ps(_mm_add_ps(v108, *(__m128 *)v105), v101);
              v113 = _mm_mul_ps(v112, v112);
              v114 = _mm_sub_ps(_mm_add_ps(v109, *(__m128 *)v104), v101);
              v115 = _mm_mul_ps(v114, v114);
              v99 = (__m128 *)*(&v134
                              + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v110, v110, 85))
                                                       + COERCE_FLOAT(_mm_shuffle_ps(v110, v110, 0)))
                                               + COERCE_FLOAT(_mm_shuffle_ps(v110, v110, 170)))
                                       * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v113, v113, 85))
                                                       + COERCE_FLOAT(_mm_shuffle_ps(v113, v113, 0)))
                                               + COERCE_FLOAT(_mm_shuffle_ps(v113, v113, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v111, v111, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v111, v111, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v111, v111, 170))) * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v115, v115, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v115, v115, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v115, v115, 170))))));
            }
            while ( v99[2].m128_i32[2] );
            v12 = v133;
          }
          v116 = v99[2].m128_u64[0];
          v117 = v100 - v94;
          if ( v116 )
            v94->m_children[(v94[v116].m_children[1] == ((char *)v99 - (char *)v94) >> 6) + 8 * v116] = v117;
          else
            branch = v100 - v94;
          v100->m_parent = v99[2].m128_u64[0];
          v118 = (char *)v99 - (char *)v122.m_nodes.m_data;
          v100->m_children[1] = v76;
          v100->m_children[0] = v118 >> 6;
          v99[2].m128_u64[0] = v117;
          *(unsigned __int64 *)((char *)&v122.m_nodes.m_data->m_parent + v77) = v117;
          v72 = _mm_min_ps(*v99, v96);
          v71 = _mm_max_ps(v99[1], v97);
          v100->m_aabb.m_min.m_quad = v72;
          v100->m_aabb.m_max.m_quad = v71;
        }
        else
        {
          branch = v76;
          *(unsigned __int64 *)((char *)&v122.m_nodes.m_data->m_parent + v77) = 0i64;
        }
        v12->vfptr->evaluate((hkGeometryProcessing::IFunction<hkVector4f,float> *)&v12->vfptr, (hkVector4f *)v16);
        ++v70;
        v16 += 16i64;
        v69 += 8i64;
        v50 = v129-- == 1;
        v71.m128_f32[0] = v72.m128_f32[0];
        v119 = _mm_shuffle_ps(v71, v71, 0);
        v120 = _mm_mul_ps(v119, v70[-1]);
        a6 = _mm_shuffle_ps(v120, _mm_unpackhi_ps(v120, v119), 196);
        v70[-1] = a6;
      }
      while ( !v50 );
      v55 = (signed int)densityFunction;
      v8 = v142;
    }
    v52 = seed;
    v16 = tree.m_root;
    LODWORD(densityFunction) = ++v55;
    if ( v55 >= v8 )
    {
      v54 = pointsa.m_capacityAndFlags;
      goto LABEL_81;
    }
  }
  pointsa.m_size = 0;
  if ( pointsa.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      pointsa.m_data,
      16 * pointsa.m_capacityAndFlags);
  pointsa.m_data = 0i64;
  pointsa.m_capacityAndFlags = 2147483648;
  v122.m_nodes.m_size = 0;
  if ( v122.m_nodes.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v122.m_nodes.m_data,
      v122.m_nodes.m_capacityAndFlags << 6);
  v122.m_nodes.m_data = 0i64;
  v122.m_nodes.m_capacityAndFlags = 2147483648;
  v127 = 0;
  if ( v128 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v128);
  v15 = 0;
LABEL_88:
  hkgpMesh::~hkgpMesh(&mesh);
  return v15;
}

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
  __m128 v2; // xmm7
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
  __m128i v25; // xmm6
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

  v2 = uv->m_quad;
  v3 = _mm_shuffle_ps(v2, v2, 0);
  v4 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v2, v2, 85), (__m128)xmmword_141A710D0), query.m_quad);
  v5 = _mm_sub_ps(_mm_mul_ps(v3, (__m128)xmmword_141A710D0), query.m_quad);
  v6 = _mm_add_ps(v4, v5);
  v7 = _mm_sub_ps(v4, v5);
  if ( v4.m128_f32[0] < 0.0 )
  {
    if ( v5.m128_f32[0] >= 0.0 )
    {
      v20 = _mm_cmpleps(g_vectorfConstants[0], v7);
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
      v17 = _mm_cmpleps(g_vectorfConstants[0], v6);
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
    v14 = _mm_cmpleps(v7, query.m_quad);
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
    v8 = _mm_cmpleps(v6, query.m_quad);
    v9 = _mm_or_ps(_mm_andnot_ps(v8, _mm_sub_ps((__m128)xmmword_141A710D0, v6)), _mm_and_ps(v8, v6));
    v10 = _mm_or_ps(_mm_andnot_ps(v8, g_vectorfConstants[0]), _mm_and_ps(v8, query.m_quad));
    v11 = _mm_or_ps(_mm_andnot_ps(v8, _mm_sub_ps(query.m_quad, v5)), _mm_and_ps(v8, v4));
    v12 = _mm_rcp_ps(v9);
    v13 = _mm_mul_ps(v11, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v12)), v12));
  }
  v23 = _mm_mul_ps(v9, v9);
  v24 = _mm_mul_ps((__m128)xmmword_141A713C0, v13);
  v25 = _mm_load_si128((const __m128i *)_xmm);
  v26 = _mm_sub_ps((__m128)xmmword_141A710D0, v23);
  v27 = _mm_rsqrt_ps(v26);
  v28 = _mm_add_epi32(v25, v25);
  v29 = _mm_add_ps(_mm_andnot_ps(_mm_cmpeqps(v9, (__m128)0i64), v24), *(__m128 *)offset_1);
  v30 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v26, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                _mm_mul_ps(*(__m128 *)_xmm, v27)),
              v26)),
          v9);
  v31 = _mm_andnot_ps(*(__m128 *)_xmm, v29);
  v32 = _mm_andnot_si128(v25, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v31, *(__m128 *)_xmm)), v25));
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
  hkVector4f v35; // xmm2

  v2 = _mm_rcp_ps((__m128)normal->m_quad.m128_u32[0]);
  v3 = (__m128)normal->m_quad.m128_u32[1];
  v4 = _mm_mul_ps(v2, v3);
  v5 = _mm_or_ps(_mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v4), _mm_cmpltps(*(__m128 *)_xmm, v4));
  v6 = _mm_cmpleps((__m128)0i64, v2);
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
  v14 = *(unsigned __int128 *)&_mm_andnot_ps(
                                 v6,
                                 _mm_add_ps(_mm_or_ps(_mm_and_ps(v3, *(__m128 *)_xmm), *(__m128 *)_xmm), v13)) | v13.m128_i32[0] & v6.m128_i32[0];
  v15 = _mm_shuffle_ps(normal->m_quad, normal->m_quad, 170);
  v16 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v12, (__m128)xmmword_141A713B0)), v12),
          _mm_mul_ps(_mm_shuffle_ps((__m128)v14, (__m128)v14, 0), (__m128)xmmword_141A710D0));
  if ( v15.m128_f32[0] >= 0.0 )
  {
    v29 = _mm_sub_ps(query.m_quad, v15);
    v30 = _mm_rsqrt_ps(v29);
    v31 = _mm_andnot_ps(
            _mm_cmpleps(v29, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                _mm_mul_ps(*(__m128 *)_xmm, v30)),
              v29));
    if ( v16.m128_f32[0] < 0.0 )
    {
      v33 = _mm_cmpltps(g_vectorfConstants[0], v16);
      v23 = _mm_or_ps(
              _mm_andnot_ps(v33, _mm_mul_ps(_mm_add_ps(v16, (__m128)xmmword_141A710D0), _mm_sub_ps((__m128)0i64, v31))),
              _mm_and_ps(_mm_mul_ps(v16, v31), v33));
      v34 = _mm_add_ps(v23, v31);
      v22 = _mm_or_ps(_mm_andnot_ps(v33, _mm_sub_ps((__m128)0i64, v34)), _mm_and_ps(v33, v34));
    }
    else
    {
      v32 = _mm_cmpltps(v16, query.m_quad);
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
            _mm_cmpleps(v17, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                _mm_mul_ps(*(__m128 *)_xmm, v18)),
              v17));
    if ( v16.m128_f32[0] < 0.0 )
    {
      v24 = _mm_cmpleps(g_vectorfConstants[0], v16);
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
      v21 = _mm_cmpleps(v16, query.m_quad);
      v22 = _mm_or_ps(
              _mm_andnot_ps(v21, _mm_sub_ps(_mm_mul_ps(_mm_sub_ps((__m128)xmmword_141A710D0, v16), v19), query.m_quad)),
              _mm_and_ps(_mm_sub_ps(query.m_quad, _mm_mul_ps(v16, v19)), v21));
      v23 = _mm_or_ps(_mm_andnot_ps(v21, _mm_add_ps(v22, v20)), _mm_and_ps(_mm_sub_ps(v20, v22), v21));
    }
  }
  v35.m_quad = _mm_movelh_ps(
                 _mm_unpacklo_ps(_mm_add_ps(v22, query.m_quad), _mm_add_ps(v23, query.m_quad)),
                 _mm_unpacklo_ps((__m128)0i64, (__m128)0i64));
  *uv = (hkVector4f)v35.m_quad;
  uv->m_quad = _mm_mul_ps(v35.m_quad, (__m128)xmmword_141A711B0);
}

// File Line: 670
// RVA: 0xCBC4B0
void __fastcall hkGeometryProcessing::wrapOctahedronCoordinates(hkVector4f *uv)
{
  ;
}

// File Line: 676
// RVA: 0xCBC4C0
hkSimdFloat32 *__fastcall hkGeometryProcessing::computeTriangleQuality(hkSimdFloat32 *result, hkVector4f *p0, hkVector4f *p1, hkVector4f *p2)
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
  hkSimdFloat32 v21; // xmm2
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
          _mm_cmpleps(v14, (__m128)0i64),
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
  v21.m_real = _mm_mul_ps(
                 _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v20, v19)), v20),
                 _mm_mul_ps(v16, _mm_shuffle_ps((__m128)LODWORD(FLOAT_3_4641016), (__m128)LODWORD(FLOAT_3_4641016), 0)));
  *result = (hkSimdFloat32)v21.m_real;
  v22 = result;
  result->m_real = _mm_and_ps(_mm_cmpltps((__m128)xmmword_141A712D0, v19), v21.m_real);
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
hkVector4f *__fastcall hkGeometryProcessing::computeMedian(hkVector4f *result, hkVector4f *a, hkVector4f *b, hkVector4f *c)
{
  hkVector4f *v4; // rax

  v4 = result;
  result->m_quad = _mm_mul_ps(_mm_add_ps(_mm_add_ps(a->m_quad, b->m_quad), c->m_quad), (__m128)xmmword_141A711C0);
  return v4;
}

// File Line: 702
// RVA: 0xCBC680
hkVector4f *__fastcall hkGeometryProcessing::computeMedian(hkVector4f *result, hkVector4f *a, hkVector4f *b, hkVector4f *c, hkVector4f *d)
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
  hkGeometry *v1; // rbx
  hkgpMesh v2; // [rsp+30h] [rbp-A8h]

  v1 = geometry;
  hkgpMesh::hkgpMesh(&v2);
  hkgpMesh::appendFromGeometry(&v2, v1, (hkTransformf *)&transform, -1, 0, 0);
  hkGeometry::clear(v1);
  hkgpMesh::appendToGeometry(&v2, v1, 0);
  hkgpMesh::~hkgpMesh(&v2);
}

// File Line: 721
// RVA: 0xCBC720
hkBool *__fastcall hkGeometryProcessing::isGeometryClosed(hkBool *result, hkGeometry *geometry)
{
  hkBool *v2; // rdi
  hkGeometry *v3; // rbx
  hkgpIndexedMesh v5; // [rsp+20h] [rbp-98h]

  v2 = result;
  v3 = geometry;
  hkgpIndexedMesh::hkgpIndexedMesh(&v5);
  hkgpIndexedMesh::appendFromGeometry(&v5, v3);
  v2->m_bool = v5.m_nakedEdges == 0;
  hkgpIndexedMesh::~hkgpIndexedMesh(&v5);
  return v2;
}

// File Line: 729
// RVA: 0xCBC780
void __fastcall hkGeometryProcessing::generateClusters(hkArray<hkVector4f,hkContainerHeapAllocator> *data, hkArray<hkSimdFloat32,hkContainerHeapAllocator> *weights, int numClusters, hkArray<int,hkContainerHeapAllocator> *clusterIds, int maxIterations)
{
  __int64 v5; // rbx
  hkArray<int,hkContainerHeapAllocator> *v6; // rdi
  __int64 v7; // rsi
  hkArray<hkSimdFloat32,hkContainerHeapAllocator> *v8; // r15
  int v9; // eax
  hkArray<hkVector4f,hkContainerHeapAllocator> *v10; // r14
  int v11; // eax
  int v12; // er9
  __int64 v13; // r9
  int v14; // er8
  __int64 i; // rcx
  int v16; // eax
  int v17; // er9
  int v18; // er9
  __int64 v19; // rcx
  int v20; // edx
  int j; // er8
  _OWORD *v22; // rax
  __int64 k; // rcx
  _OWORD *v24; // rax
  int v25; // er13
  int v26; // er12
  __int64 v27; // r8
  signed __int64 v28; // rdx
  __m128 v29; // xmm1
  __int64 v30; // r8
  signed __int64 v31; // rdx
  __int64 v32; // rcx
  __int64 v33; // rdx
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  int v36; // er11
  int v37; // er10
  __int64 v38; // r8
  __m128i v39; // xmm10
  __m128 v40; // xmm5
  __m128i v41; // xmm4
  __m128i v42; // xmm6
  __int64 v43; // rcx
  __int64 v44; // rax
  __m128 v45; // xmm1
  __m128 v46; // xmm1
  __m128 v47; // xmm0
  __m128 v48; // xmm3
  __m128i v49; // xmm2
  __m128 *v50; // [rsp+28h] [rbp-51h]
  int v51; // [rsp+30h] [rbp-49h]
  int v52; // [rsp+34h] [rbp-45h]
  __int64 array; // [rsp+38h] [rbp-41h]
  int v54; // [rsp+40h] [rbp-39h]
  int v55; // [rsp+44h] [rbp-35h]
  hkResult result; // [rsp+E8h] [rbp+6Fh]
  __int64 v57; // [rsp+F8h] [rbp+7Fh]

  v5 = data->m_size;
  v6 = clusterIds;
  v7 = numClusters;
  v8 = weights;
  v9 = clusterIds->m_capacityAndFlags & 0x3FFFFFFF;
  v10 = data;
  if ( v9 < (signed int)v5 )
  {
    v11 = 2 * v9;
    v12 = data->m_size;
    if ( (signed int)v5 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, v12, 4);
  }
  v13 = 0i64;
  v6->m_size = v5;
  v14 = 0;
  for ( i = 0i64; i < v5; v6->m_data[i - 1] = v16 % (signed int)v7 )
  {
    v16 = v14;
    ++i;
    ++v14;
  }
  array = 0i64;
  v54 = 0;
  v55 = 2147483648;
  if ( (signed int)v7 > 0 )
  {
    v17 = v7;
    if ( (signed int)v7 < 0 )
      v17 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v17, 16);
    v13 = 0i64;
  }
  v54 = v7;
  v50 = 0i64;
  v51 = 0;
  v52 = 2147483648;
  if ( (signed int)v7 > 0 )
  {
    v18 = v7;
    if ( (signed int)v7 < 0 )
      v18 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v50, v18, 16);
    v13 = 0i64;
  }
  v19 = array;
  v20 = v7 - 1;
  v51 = v7;
  for ( j = v7 - 1; j >= 0; *v22 = 0i64 )
  {
    v22 = (_OWORD *)v19;
    v19 += 16i64;
    --j;
  }
  for ( k = array; v20 >= 0; *v24 = 0i64 )
  {
    v24 = (_OWORD *)k;
    k += 16i64;
    --v20;
  }
  v25 = v57;
  v26 = 0;
  if ( (signed int)v57 > 0 )
  {
    do
    {
      if ( v8 )
      {
        if ( v5 > 0 )
        {
          v27 = 0i64;
          do
          {
            ++v13;
            ++v27;
            v28 = v6->m_data[v13 - 1];
            v29 = v8->m_data[v27 - 1].m_real;
            v50[v28] = _mm_add_ps(v8->m_data[v27 - 1].m_real, v50[v6->m_data[v13 - 1]]);
            *(__m128 *)(array + 4 * v28) = _mm_add_ps(
                                             _mm_mul_ps(v10->m_data[v27 - 1].m_quad, v29),
                                             *(__m128 *)(array + 4 * v28));
          }
          while ( v13 < v5 );
        }
      }
      else
      {
        v30 = 0i64;
        if ( v5 <= 0 )
          goto LABEL_28;
        do
        {
          ++v30;
          v13 += 16i64;
          v31 = v6->m_data[v30 - 1];
          v50[v31] = _mm_add_ps(v50[v6->m_data[v30 - 1]], query.m_quad);
          *(__m128 *)(array + 4 * v31) = _mm_add_ps(
                                           *(__m128 *)((char *)&v10->m_data[-1].m_quad + v13),
                                           *(__m128 *)(array + 4 * v31));
        }
        while ( v30 < v5 );
      }
      v13 = 0i64;
LABEL_28:
      if ( v7 > 0 )
      {
        v32 = 0i64;
        v33 = v7;
        do
        {
          ++v32;
          v34 = v50[v32 - 1];
          v35 = _mm_rcp_ps(v34);
          *(__m128 *)(v32 * 16 + array - 16) = _mm_mul_ps(
                                                 _mm_andnot_ps(
                                                   _mm_cmpeqps(v34, (__m128)0i64),
                                                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v35, v34)), v35)),
                                                 *(__m128 *)(v32 * 16 + array - 16));
          v50[v32 - 1] = 0i64;
          --v33;
        }
        while ( v33 );
      }
      v36 = 0;
      v37 = 0;
      v38 = 0i64;
      if ( v5 <= 0 )
        break;
      v39 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
      do
      {
        v40 = (__m128)xmmword_141A712A0;
        v41 = v39;
        v42 = 0i64;
        if ( v7 > 0 )
        {
          v43 = v7;
          v44 = array;
          do
          {
            v44 += 16i64;
            v45 = _mm_sub_ps(*(__m128 *)((char *)&v10->m_data->m_quad + v13), *(__m128 *)(v44 - 16));
            v46 = _mm_mul_ps(v45, v45);
            v47 = _mm_add_ps(_mm_shuffle_ps(v46, v46, 78), v46);
            v48 = _mm_add_ps(_mm_shuffle_ps(v47, v47, 177), v47);
            v49 = (__m128i)_mm_cmpltps(v48, v40);
            v41 = _mm_or_si128(_mm_and_si128(v42, v49), _mm_andnot_si128(v49, v41));
            v40 = _mm_or_ps(_mm_andnot_ps((__m128)v49, v40), _mm_and_ps((__m128)v49, v48));
            v42 = _mm_add_epi32((__m128i)xmmword_141A72090, v42);
            --v43;
          }
          while ( v43 );
        }
        if ( _mm_movemask_ps((__m128)_mm_or_si128(
                                       _mm_cmpgt_epi32(v41, *(__m128i *)&g_intVectorConstants[0][0]),
                                       _mm_cmpeq_epi32(v41, *(__m128i *)&g_intVectorConstants[0][0]))) )
        {
          if ( !(_mm_movemask_ps((__m128)_mm_cmpeq_epi32((__m128i)(unsigned int)v6->m_data[v37], v41)) & 1) )
            ++v36;
          v6->m_data[v37] = v41.m128i_i32[0];
        }
        ++v38;
        ++v37;
        v13 += 16i64;
      }
      while ( v38 < v5 );
      if ( !v36 )
      {
        LODWORD(v13) = 0;
        break;
      }
      ++v26;
      v13 = 0i64;
    }
    while ( v26 < v25 );
  }
  v51 = v13;
  if ( v52 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v50,
      16 * v52);
  v50 = 0i64;
  v52 = 2147483648;
  v54 = 0;
  if ( v55 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, __int64, _QWORD, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      array,
      (unsigned int)(16 * v55),
      0i64);
}

// File Line: 829
// RVA: 0xCBCC40
void __fastcall hkGeometryProcessing::generateClusters(hkArray<float,hkContainerHeapAllocator> *data, hkArray<hkSimdFloat32,hkContainerHeapAllocator> *weights, int numClusters, hkArray<int,hkContainerHeapAllocator> *clusterIds, int maxIterations)
{
  int v5; // edi
  hkArray<int,hkContainerHeapAllocator> *v6; // rsi
  int v7; // ebp
  hkArray<hkSimdFloat32,hkContainerHeapAllocator> *v8; // r14
  hkArray<float,hkContainerHeapAllocator> *v9; // rbx
  int v10; // er9
  int v11; // edx
  hkVector4f *v12; // rcx
  int i; // edx
  hkVector4f *v14; // rax
  int v15; // er8
  __int64 v16; // r9
  __int64 v17; // rcx
  hkVector4f v18; // xmm0
  hkArray<hkVector4f,hkContainerHeapAllocator> dataa; // [rsp+30h] [rbp-28h]
  __int64 v20; // [rsp+60h] [rbp+8h]

  v5 = data->m_size;
  v6 = clusterIds;
  v7 = numClusters;
  v8 = weights;
  v9 = data;
  dataa.m_data = 0i64;
  dataa.m_size = 0;
  dataa.m_capacityAndFlags = 2147483648;
  if ( v5 > 0 )
  {
    v10 = v5;
    if ( v5 < 0 )
      v10 = 0;
    hkArrayUtil::_reserve(
      (hkResult *)&v20,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &dataa,
      v10,
      16);
  }
  v11 = v9->m_size;
  v12 = dataa.m_data;
  dataa.m_size = v5;
  for ( i = v11 - 1; i >= 0; *v14 = 0i64 )
  {
    v14 = v12;
    ++v12;
    --i;
  }
  v15 = 0;
  if ( v9->m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      v17 = v15++;
      ++v16;
      v18.m_quad = (__m128)dataa.m_data[v16 - 1];
      v18.m_quad.m128_f32[0] = v9->m_data[v17];
      dataa.m_data[v16 - 1] = (hkVector4f)v18.m_quad;
    }
    while ( v15 < v9->m_size );
  }
  hkGeometryProcessing::generateClusters(&dataa, v8, v7, v6, maxIterations);
  dataa.m_size = 0;
  if ( dataa.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      dataa.m_data,
      16 * dataa.m_capacityAndFlags);
}

// File Line: 842
// RVA: 0xCBCD70
void __fastcall hkGeometryProcessing::generateClusters(hkAabb *aabbs, int numAabbs, int maxClusters, hkArray<int,hkContainerHeapAllocator> *clusterRoots, hkArray<int,hkContainerHeapAllocator> *clusterNexts)
{
  hkArray<int,hkContainerHeapAllocator> *v5; // r15
  int v6; // ebx
  hkArray<int,hkContainerHeapAllocator> *v7; // rsi
  int v8; // er14
  int v9; // eax
  hkAabb *v10; // r13
  int v11; // eax
  int v12; // er9
  __int64 v13; // rdx
  int *v14; // rdi
  __int64 v15; // rcx
  int v16; // er15
  int v17; // eax
  int v18; // eax
  int v19; // er9
  __int64 v20; // rcx
  hkcdDynamicTree::CodecRawUint *v21; // rdx
  int v22; // er12
  unsigned int v23; // esi
  unsigned int v24; // eax
  signed __int64 v25; // r15
  hkcdDynamicTree::CodecRawUint *v26; // r8
  __int64 v27; // rdi
  hkVector4f v28; // xmm7
  hkVector4f v29; // xmm8
  unsigned int v30; // edx
  __m128 *v31; // r9
  __int64 v32; // rax
  signed __int64 v33; // r11
  __m128 v34; // xmm9
  __m128 v35; // xmm10
  signed __int64 v36; // rcx
  __m128 v37; // xmm1
  __m128 v38; // xmm2
  __m128 *v39; // rcx
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm2
  __m128 v43; // xmm5
  __m128 v44; // xmm3
  __m128 v45; // xmm3
  __m128 v46; // xmm6
  __m128 v47; // xmm6
  unsigned __int64 v48; // r10
  float v49; // eax
  signed __int64 v50; // rcx
  __m128 v51; // xmm1
  unsigned int v52; // ecx
  int v53; // er11
  unsigned int v54; // er8
  unsigned int v55; // ecx
  unsigned int v56; // edx
  unsigned int i; // edi
  int v58; // esi
  hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::Node *v59; // rdx
  hkcdDynamicTree::CodecRawUint *v60; // r9
  hkcdDynamicTree::CodecRawUint *v61; // r14
  __int64 v62; // r9
  int v63; // er11
  unsigned int v64; // er8
  unsigned int v65; // ecx
  unsigned int v66; // edx
  unsigned int j; // edi
  __int64 v68; // rcx
  int v69; // edi
  hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::Node *v70; // r9
  int v71; // er8
  hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::Node *v72; // rdx
  int v73; // ecx
  int v74; // eax
  BOOL v75; // ecx
  int v76; // eax
  __int64 v77; // r9
  int v78; // er11
  unsigned int v79; // er8
  unsigned int v80; // ecx
  unsigned int v81; // edx
  unsigned int k; // edi
  signed __int64 v83; // rax
  signed int v84; // er13
  int *v85; // rcx
  signed __int64 v86; // r15
  hkArray<int,hkContainerHeapAllocator> *v87; // r12
  int v88; // er10
  __int64 v89; // rsi
  unsigned int v90; // edi
  unsigned int v91; // eax
  unsigned int l; // er8
  int v93; // er8
  __int64 v94; // rdi
  _DWORD *v95; // rsi
  int v96; // edi
  signed int v97; // er9
  signed __int64 v98; // r8
  int v99; // ecx
  signed __int64 v100; // rax
  _DWORD *v101; // rcx
  int *array; // [rsp+30h] [rbp-D0h]
  int v103; // [rsp+38h] [rbp-C8h]
  int v104; // [rsp+3Ch] [rbp-C4h]
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> v105; // [rsp+40h] [rbp-C0h]
  int v106; // [rsp+58h] [rbp-A8h]
  __int64 v107; // [rsp+5Ch] [rbp-A4h]
  hkGeometryProcessingInternals::ClusterQueueNode value; // [rsp+68h] [rbp-98h]
  hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16> v109; // [rsp+70h] [rbp-90h]
  hkGeometryProcessingInternals::ClusterQueueNode v110; // [rsp+A0h] [rbp-60h]
  __m128 *v111; // [rsp+A8h] [rbp-58h]
  hkcdDynamicTree::DefaultTree48Storage output; // [rsp+B0h] [rbp-50h]
  hkResult result; // [rsp+178h] [rbp+78h]
  int count; // [rsp+180h] [rbp+80h]
  void *v115; // [rsp+188h] [rbp+88h]

  v115 = clusterRoots;
  count = maxClusters;
  v5 = clusterNexts;
  v6 = 0;
  v7 = clusterRoots;
  clusterRoots->m_size = 0;
  v8 = numAabbs;
  v9 = v5->m_capacityAndFlags & 0x3FFFFFFF;
  v10 = aabbs;
  v5->m_size = 0;
  if ( v9 < numAabbs )
  {
    v11 = 2 * v9;
    v12 = numAabbs;
    if ( numAabbs < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, v12, 4);
  }
  v13 = v5->m_size;
  v14 = &v5->m_data[v13];
  v15 = v8 - (signed int)v13;
  if ( v8 - (signed int)v13 > 0 )
  {
    while ( v15 )
    {
      *v14 = -1;
      ++v14;
      --v15;
    }
  }
  v5->m_size = v8;
  if ( v8 )
  {
    v16 = count;
    if ( count >= v8 )
    {
      v17 = v7->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v17 < v8 )
      {
        v18 = 2 * v17;
        v19 = v8;
        if ( v8 < v18 )
          v19 = v18;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, v19, 4);
      }
      v7->m_size = v8;
      if ( v8 > 0 )
      {
        v20 = 0i64;
        do
        {
          ++v20;
          v7->m_data[v20 - 1] = v6++;
        }
        while ( v6 < v8 );
      }
      return;
    }
    v105.m_nodes.m_size = 0;
    v21 = 0i64;
    v22 = 0;
    v105.m_nodes.m_data = 0i64;
    v105.m_nodes.m_capacityAndFlags = 2147483648;
    v23 = 0;
    v105.m_firstFree = 0;
    v24 = 0;
    v107 = 0i64;
    v106 = 0;
    if ( v8 > 0 )
    {
      while ( 1 )
      {
        if ( !v23 )
        {
          hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
            &v105,
            &result,
            1);
          v23 = v105.m_firstFree;
          v21 = v105.m_nodes.m_data;
        }
        v105.m_firstFree = v21[v23].m_aabb.m_min.m_quad.m128_u32[0];
        v25 = v23;
        v21[v25].m_children[0] = 0;
        v21[v25].m_children[1] = v22;
        v21[v25].m_aabb.m_min = v10->m_min;
        v21[v25].m_aabb.m_max = v10->m_max;
        v26 = v105.m_nodes.m_data;
        v27 = HIDWORD(v107);
        v28.m_quad = (__m128)v105.m_nodes.m_data[v23].m_aabb.m_min;
        v29.m_quad = (__m128)v105.m_nodes.m_data[v23].m_aabb.m_max;
        if ( HIDWORD(v107) )
        {
          v30 = v105.m_firstFree;
          if ( !v105.m_firstFree )
          {
            hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
              &v105,
              (hkResult *)&value,
              v105.m_firstFree + 1);
            v30 = v105.m_firstFree;
            v26 = v105.m_nodes.m_data;
          }
          v31 = &v26[v27].m_aabb.m_min.m_quad;
          v105.m_firstFree = v26[v30].m_aabb.m_min.m_quad.m128_u32[0];
          v32 = v31[2].m128_u32[1];
          v33 = (signed __int64)&v26[v30];
          if ( (_DWORD)v32 )
          {
            v34 = _mm_add_ps(v29.m_quad, v28.m_quad);
            v35 = _mm_sub_ps(v29.m_quad, v28.m_quad);
            do
            {
              v36 = v31[2].m128_u32[2];
              v37 = _mm_max_ps(v31[1], v29.m_quad);
              *v31 = _mm_min_ps(*v31, v28.m_quad);
              v31[1] = v37;
              v110 = (hkGeometryProcessingInternals::ClusterQueueNode)&v26[v32];
              v38 = *(__m128 *)(*(_QWORD *)&v110 + 16i64);
              v39 = &v26[v36].m_aabb.m_min.m_quad;
              v26 = v105.m_nodes.m_data;
              v40 = v38;
              v41 = _mm_sub_ps(v38, *(__m128 *)v110);
              v111 = v39;
              v42 = _mm_add_ps(v41, v35);
              v43 = _mm_add_ps(_mm_sub_ps(v39[1], *v39), v35);
              v44 = _mm_sub_ps(_mm_add_ps(v40, *(__m128 *)v110), v34);
              v45 = _mm_mul_ps(v44, v44);
              v46 = _mm_sub_ps(_mm_add_ps(v39[1], *v39), v34);
              v47 = _mm_mul_ps(v46, v46);
              v31 = (__m128 *)*((_QWORD *)&v110
                              + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v42, v42, 85))
                                                       + COERCE_FLOAT(_mm_shuffle_ps(v42, v42, 0)))
                                               + COERCE_FLOAT(_mm_shuffle_ps(v42, v42, 170)))
                                       * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v45, v45, 85))
                                                       + COERCE_FLOAT(_mm_shuffle_ps(v45, v45, 0)))
                                               + COERCE_FLOAT(_mm_shuffle_ps(v45, v45, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v43, v43, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v43, v43, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v43, v43, 170))) * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 170))))));
              v32 = v31[2].m128_u32[1];
            }
            while ( (_DWORD)v32 );
          }
          v48 = ((unsigned __int64)((unsigned __int128)((v33 - (signed __int64)v26)
                                                      * (signed __int128)3074457345618258603i64) >> 64) >> 63)
              + ((signed __int64)((unsigned __int128)((v33 - (signed __int64)v26)
                                                    * (signed __int128)3074457345618258603i64) >> 64) >> 3);
          v49 = v31[2].m128_f32[0];
          if ( v49 == 0.0 )
            HIDWORD(v107) = ((unsigned __int64)((unsigned __int128)((v33 - (signed __int64)v26)
                                                                  * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                          + ((signed __int64)((unsigned __int128)((v33 - (signed __int64)v26)
                                                                * (signed __int128)3074457345618258603i64) >> 64) >> 3);
          else
            v26->m_children[(v26[LODWORD(v49)].m_children[1] == ((unsigned __int64)((unsigned __int128)(((char *)v31 - (char *)v26) * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                                              + (unsigned int)((signed __int64)((unsigned __int128)(((char *)v31 - (char *)v26) * (signed __int128)3074457345618258603i64) >> 64) >> 3))
                          + 12i64 * LODWORD(v49)] = v48;
          *(float *)(v33 + 32) = v31[2].m128_f32[0];
          v50 = (char *)v31 - (char *)v105.m_nodes.m_data;
          *(_DWORD *)(v33 + 40) = v23;
          *(_DWORD *)(v33 + 36) = ((unsigned __int64)((unsigned __int128)(v50 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                + ((signed __int64)((unsigned __int128)(v50 * (signed __int128)3074457345618258603i64) >> 64) >> 3);
          v31[2].m128_i32[0] = v48;
          v105.m_nodes.m_data[v23].m_parent = v48;
          v51 = _mm_max_ps(v31[1], v29.m_quad);
          *(__m128 *)v33 = _mm_min_ps(*v31, v28.m_quad);
          *(__m128 *)(v33 + 16) = v51;
        }
        else
        {
          HIDWORD(v107) = v23;
          v105.m_nodes.m_data[v23].m_parent = 0;
        }
        ++v106;
        ++v22;
        ++v10;
        if ( v22 >= v8 )
          break;
        v23 = v105.m_firstFree;
        v21 = v105.m_nodes.m_data;
      }
      v24 = HIDWORD(v107);
      v16 = count;
    }
    hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::rebuildBranchSAH(
      (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)&v105,
      v24,
      (hkBool)1,
      32,
      16);
    if ( HIDWORD(v107) )
    {
      output.m_nodes.m_size = 0;
      output.m_nodes.m_data = 0i64;
      output.m_nodes.m_capacityAndFlags = 2147483648;
      output.m_firstFree = 0;
      *(_QWORD *)&output.m_path = 0i64;
      output.m_numLeaves = 0;
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>>(
        (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)&v105,
        &output);
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&output,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v105);
      v52 = output.m_firstFree;
      output.m_firstFree = v105.m_firstFree;
      v105.m_firstFree = v52;
      HIDWORD(v107) = 1;
      output.m_nodes.m_size = 0;
      if ( output.m_nodes.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          output.m_nodes.m_data,
          48 * (output.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
    }
    v109.m_nodes.m_data = 0i64;
    v109.m_nodes.m_size = 0;
    v109.m_nodes.m_capacityAndFlags = 2147483648;
    v109.m_prng.m_x = 123456789;
    v109.m_prng.m_y = 234567891;
    v109.m_prng.m_z = 345678912;
    *(_QWORD *)&v109.m_prng.m_w = 456789123i64;
    hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::clear(
      &v109,
      0);
    hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::preAllocateNodes(
      &v109,
      v16);
    v53 = 0;
    value.m_index = HIDWORD(v107);
    if ( HIDWORD(v107) )
    {
      v54 = v105.m_nodes.m_data[HIDWORD(v107)].m_children[0];
      if ( v54 )
      {
        do
        {
          v55 = v105.m_nodes.m_data[v54].m_children[0];
          v53 += v55 == 0;
          if ( v55 )
          {
            v54 = v105.m_nodes.m_data[v54].m_children[0];
          }
          else
          {
            v56 = v105.m_nodes.m_data[v54].m_parent;
            for ( i = v54; v56 != HIDWORD(v107); v56 = v105.m_nodes.m_data[v56].m_parent )
            {
              if ( v105.m_nodes.m_data[v56].m_children[1] != i )
                break;
              i = v56;
            }
            if ( v56 )
              v54 = v105.m_nodes.m_data[v56].m_children[1];
            else
              v54 = i;
            if ( v56 == HIDWORD(v107) && v54 == i )
              v54 = 0;
          }
        }
        while ( v54 );
      }
      else
      {
        v53 = 1;
      }
    }
    value.m_value = v53;
    hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::insert(
      &v109,
      &value);
    if ( v109.m_size >= v16 )
    {
LABEL_103:
      v60 = v105.m_nodes.m_data;
      v59 = v109.m_nodes.m_data;
    }
    else
    {
      while ( 1 )
      {
        v58 = v109.m_root;
        v59 = v109.m_nodes.m_data;
        if ( v109.m_root )
        {
          while ( v109.m_nodes.m_data[v58].m_children[1] )
            v58 = v109.m_nodes.m_data[v58].m_children[1];
        }
        v60 = v105.m_nodes.m_data;
        v61 = &v105.m_nodes.m_data[v109.m_nodes.m_data[v58].m_value.m_index];
        if ( !v61->m_children[0] )
          break;
        hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::removeNode(
          &v109,
          v58);
        v109.m_nodes.m_data[v58].m_parent = v109.m_free;
        --v109.m_size;
        v109.m_free = v58;
        v62 = v61->m_children[0];
        v63 = 0;
        value.m_index = v62;
        if ( (_DWORD)v62 )
        {
          v64 = v105.m_nodes.m_data[v62].m_children[0];
          if ( v64 )
          {
            do
            {
              v65 = v105.m_nodes.m_data[v64].m_children[0];
              v63 += v65 == 0;
              if ( v65 )
              {
                v64 = v105.m_nodes.m_data[v64].m_children[0];
              }
              else
              {
                v66 = v105.m_nodes.m_data[v64].m_parent;
                for ( j = v64; v66 != (_DWORD)v62; v66 = v105.m_nodes.m_data[v66].m_parent )
                {
                  if ( v105.m_nodes.m_data[v66].m_children[1] != j )
                    break;
                  j = v66;
                }
                if ( v66 )
                  v64 = v105.m_nodes.m_data[v66].m_children[1];
                else
                  v64 = j;
                if ( v66 == (_DWORD)v62 && v64 == j )
                  v64 = 0;
              }
            }
            while ( v64 );
          }
          else
          {
            v63 = 1;
          }
        }
        value.m_value = v63;
        if ( !v58 )
        {
          hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::preAllocateNodes(
            &v109,
            16);
          v58 = v109.m_free;
        }
        v109.m_free = v109.m_nodes.m_data[v58].m_parent;
        v68 = v58;
        v109.m_nodes.m_data[v68].m_value = value;
        v69 = v109.m_root;
        v70 = &v109.m_nodes.m_data[v68];
        if ( v109.m_root )
        {
          v71 = v70->m_value.m_value;
          while ( 1 )
          {
            v72 = &v109.m_nodes.m_data[v69];
            v73 = v109.m_nodes.m_data[v69].m_value.m_value;
            v74 = v71 >= v73 ? (unsigned __int8)(v73 < v71) : -1;
            v75 = v74 >= 0;
            v76 = v72->m_children[v74 >= 0];
            if ( !v76 )
              break;
            v69 = v76;
          }
          v72->m_children[v75] = v58;
          v70->m_parent = v69;
        }
        else
        {
          v109.m_root = v58;
          v70->m_parent = 0;
        }
        *(_QWORD *)v70->m_children = 0i64;
        ++v109.m_size;
        v77 = v61->m_children[1];
        v110.m_index = v77;
        v78 = 0;
        if ( (_DWORD)v77 )
        {
          v79 = v105.m_nodes.m_data[v77].m_children[0];
          if ( v79 )
          {
            do
            {
              v80 = v105.m_nodes.m_data[v79].m_children[0];
              v78 += v80 == 0;
              if ( v80 )
              {
                v79 = v105.m_nodes.m_data[v79].m_children[0];
              }
              else
              {
                v81 = v105.m_nodes.m_data[v79].m_parent;
                for ( k = v79; v81 != (_DWORD)v77; v81 = v105.m_nodes.m_data[v81].m_parent )
                {
                  if ( v105.m_nodes.m_data[v81].m_children[1] != k )
                    break;
                  k = v81;
                }
                if ( v81 )
                  v79 = v105.m_nodes.m_data[v81].m_children[1];
                else
                  v79 = k;
                if ( v81 == (_DWORD)v77 && v79 == k )
                  v79 = 0;
              }
            }
            while ( v79 );
          }
          else
          {
            v78 = 1;
          }
        }
        v110.m_value = v78;
        hkSortedTree<hkGeometryProcessingInternals::ClusterQueueNode,hkSortedTreeBase::CompareValues,int,16>::insert(
          &v109,
          &v110);
        if ( v109.m_size >= v16 )
          goto LABEL_103;
      }
    }
    v83 = 1i64;
    array = 0i64;
    v103 = 0;
    v104 = 2147483648;
    v84 = 1;
    if ( v109.m_nodes.m_size <= 1i64 )
    {
LABEL_108:
      v84 = 0;
    }
    else
    {
      v85 = v59[1].m_children;
      while ( *v85 == v84 )
      {
        ++v83;
        ++v84;
        v85 += 5;
        if ( v83 >= v109.m_nodes.m_size )
          goto LABEL_108;
      }
    }
    v86 = v84;
    if ( v84 )
    {
      v87 = clusterNexts;
      while ( 1 )
      {
        v103 = 0;
        v88 = 0;
        v89 = v59[v86].m_value.m_index;
        if ( (_DWORD)v89 )
        {
          v90 = v60[v89].m_children[0];
          if ( v90 )
          {
            while ( 1 )
            {
              if ( !v60[v90].m_children[0] )
              {
                if ( v88 == (v104 & 0x3FFFFFFF) )
                {
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 4);
                  v88 = v103;
                }
                array[v88] = v90;
                v60 = v105.m_nodes.m_data;
                v88 = v103++ + 1;
              }
              if ( !v90 )
                goto LABEL_128;
              if ( !v60[v90].m_children[0] )
                break;
              v90 = v60[v90].m_children[0];
LABEL_129:
              if ( !v90 )
                goto LABEL_134;
            }
            v91 = v60[v90].m_parent;
            for ( l = v90; v91 != (_DWORD)v89; v91 = v60[v91].m_parent )
            {
              if ( v60[v91].m_children[1] != l )
                break;
              l = v91;
            }
            if ( v91 )
              v90 = v60[v91].m_children[1];
            else
              v90 = l;
            if ( v91 != (_DWORD)v89 || v90 != l )
              goto LABEL_129;
LABEL_128:
            v90 = 0;
            goto LABEL_129;
          }
          if ( !(v104 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 4);
            v88 = v103;
          }
          array[v88] = v89;
          v60 = v105.m_nodes.m_data;
          v88 = v103++ + 1;
        }
LABEL_134:
        v93 = 0;
        if ( v88 > 0 )
        {
          v94 = 0i64;
          while ( 1 )
          {
            ++v93;
            ++v94;
            array[v94 - 1] = v60[array[v94 - 1]].m_children[1];
            if ( v93 >= v103 )
              break;
            v60 = v105.m_nodes.m_data;
          }
        }
        v95 = v115;
        v96 = *array;
        if ( *((_DWORD *)v115 + 2) == (*((_DWORD *)v115 + 3) & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v115, 4);
        v97 = 1;
        *(_DWORD *)(*(_QWORD *)v95 + 4i64 * (signed int)v95[2]++) = v96;
        if ( v103 > 1 )
        {
          v98 = 1i64;
          do
          {
            v99 = array[v98];
            ++v97;
            ++v98;
            v87->m_data[v96] = v99;
            v96 = array[v98 - 1];
          }
          while ( v97 < v103 );
        }
        if ( !v86 )
          break;
        v100 = v86 + 1;
        ++v84;
        v86 = v100;
        if ( v100 >= v109.m_nodes.m_size )
          break;
        v59 = v109.m_nodes.m_data;
        v101 = (_DWORD *)((char *)&v109.m_nodes.m_data->m_value + 4 * (v100 + 4 * v100 + 2));
        while ( *v101 == v84 )
        {
          ++v86;
          ++v84;
          v101 += 5;
          if ( v86 >= v109.m_nodes.m_size )
            goto LABEL_152;
        }
        v60 = v105.m_nodes.m_data;
        if ( !v86 )
          goto LABEL_153;
      }
      v59 = v109.m_nodes.m_data;
LABEL_152:
      v60 = v105.m_nodes.m_data;
    }
LABEL_153:
    v103 = 0;
    if ( v104 >= 0 )
    {
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        4 * v104);
      v60 = v105.m_nodes.m_data;
      v59 = v109.m_nodes.m_data;
    }
    array = 0i64;
    v104 = 2147483648;
    v109.m_nodes.m_size = 0;
    if ( v109.m_nodes.m_capacityAndFlags >= 0 )
    {
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v59,
        20 * (v109.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
      v60 = v105.m_nodes.m_data;
    }
    v109.m_nodes.m_data = 0i64;
    v109.m_nodes.m_capacityAndFlags = 2147483648;
    v105.m_nodes.m_size = 0;
    if ( v105.m_nodes.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v60,
        48 * (v105.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
  }
}

// File Line: 909
// RVA: 0xCBD9C0
void __fastcall hkGeometryProcessing::computeCurvature(hkGeometry *geometry, hkSimdFloat32 *maxCurvature)
{
  hkVector4f *v2; // rdi
  hkGeometry *v3; // rbx
  hkSimdFloat32 *v4; // r14
  int v5; // ecx
  const __m128i *v6; // rax
  __m128i v7; // xmm0
  int v8; // esi
  int v9; // er9
  int v10; // er9
  __int64 v11; // r8
  hkGeometry::Triangle *v12; // rcx
  __int64 v13; // rax
  __m128 v14; // xmm0
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm5
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  hkgpIndexedMeshDefinitions::Triangle *v22; // rdx
  unsigned __int64 v23; // r8
  unsigned __int64 v24; // r9
  hkgpIndexedMeshDefinitions::Triangle *v25; // r9
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v26; // rax
  signed int v27; // er10
  signed __int64 v28; // r8
  __m128 v29; // xmm1
  __m128 v30; // xmm9
  __m128 v31; // xmm7
  __m128 v32; // xmm6
  __m128 v33; // xmm2
  __m128 v34; // xmm5
  __m128 v35; // xmm4
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm3
  __m128 v39; // xmm2
  __m128 v40; // xmm1
  __m128 v41; // xmm4
  __m128 v42; // xmm0
  __m128 v43; // xmm1
  unsigned __int64 v44; // rcx
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v45; // rax
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator v46; // [rsp+30h] [rbp-C8h]
  __m128 *array; // [rsp+40h] [rbp-B8h]
  int v48; // [rsp+48h] [rbp-B0h]
  int v49; // [rsp+4Ch] [rbp-ACh]
  hkgpIndexedMesh v50; // [rsp+50h] [rbp-A8h]
  void *retaddr; // [rsp+138h] [rbp+40h]

  v2 = geometry->m_vertices.m_data;
  v3 = geometry;
  v4 = maxCurvature;
  v5 = 0;
  if ( v3->m_vertices.m_size > 0 )
  {
    v6 = (const __m128i *)v2;
    do
    {
      v7 = _mm_load_si128(v6);
      ++v5;
      ++v6;
      _mm_store_si128((__m128i *)&v6[-1], _mm_srli_si128(_mm_slli_si128(v7, 4), 4));
    }
    while ( v5 < v3->m_vertices.m_size );
  }
  v8 = v3->m_triangles.m_size;
  array = 0i64;
  v48 = 0;
  v49 = 2147483648;
  if ( v8 > 0 )
  {
    v9 = v8;
    if ( v8 < 0 )
      v9 = 0;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      v9,
      16);
  }
  v48 = v8;
  v10 = 0;
  if ( v3->m_triangles.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      v12 = v3->m_triangles.m_data;
      ++v10;
      v13 = v12[v11].m_a;
      ++v11;
      v14 = v2[v13].m_quad;
      v15 = _mm_sub_ps(v2[*((signed int *)&v12[v11] - 3)].m_quad, v14);
      v16 = _mm_sub_ps(v2[*((signed int *)&v12[v11] - 2)].m_quad, v14);
      v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v16));
      v18 = _mm_shuffle_ps(v17, v17, 201);
      v19 = _mm_mul_ps(v18, v18);
      v20 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
              _mm_shuffle_ps(v19, v19, 170));
      v21 = _mm_rsqrt_ps(v20);
      array[v11 - 1] = _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmpleps(v20, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                             _mm_mul_ps(*(__m128 *)_xmm, v21))),
                         v18);
    }
    while ( v10 < v3->m_triangles.m_size );
  }
  hkgpIndexedMesh::hkgpIndexedMesh(&v50);
  hkgpIndexedMesh::appendFromGeometry(&v50, v3);
  v22 = (hkgpIndexedMeshDefinitions::Triangle *)v50.m_triangles.m_allocator.m_firstPool;
  *v4 = 0i64;
  v46.m_edge.m_triangle = v22;
  v46.m_edge.m_index = 0;
  _mm_store_si128((__m128i *)&v46, (__m128i)v46);
  if ( v22 )
  {
    v23 = v22->m_vertices[0]->m_index;
    v24 = v22->m_vertices[1]->m_index;
    if ( v23 >= v24 && (v23 > v24) > 0 && v22->m_links[0] & 0xFFFFFFFFFFFFFFFCui64 )
      hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v46);
  }
  v25 = v46.m_edge.m_triangle;
  v26 = &v46;
  if ( !v46.m_edge.m_triangle )
    v26 = 0i64;
  if ( v26 )
  {
    v27 = v46.m_edge.m_index;
    do
    {
      if ( v25->m_links[v27] & 0xFFFFFFFFFFFFFFFCui64 )
      {
        v28 = (9i64 >> 2 * (unsigned __int8)v27) & 3;
        v29 = _mm_mul_ps(
                array[*(signed int *)((v25->m_links[v27] & 0xFFFFFFFFFFFFFFFCui64) + 64)],
                array[SLODWORD(v25->m_index)]);
        v30 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                _mm_shuffle_ps(v29, v29, 170));
        v31 = _mm_andnot_ps(*(__m128 *)_xmm, v30);
        v32 = _mm_cmpltps(v31, *(__m128 *)_xmm);
        v33 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v31), *(__m128 *)_xmm);
        v34 = _mm_cmpltps(*(__m128 *)_xmm, v31);
        v35 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v33), v34), _mm_andnot_ps(v34, v31));
        v36 = _mm_or_ps(_mm_andnot_ps(v34, _mm_mul_ps(v31, v31)), _mm_and_ps(v34, v33));
        v37 = _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v36, *(__m128 *)coeff4), *(__m128 *)coeff3), v36),
                          *(__m128 *)coeff2),
                        v36),
                      *(__m128 *)coeff1),
                    v36),
                  *(__m128 *)coeff0),
                v36);
        v38 = v2[v25->m_vertices[v28]->m_index].m_quad;
        v39 = _mm_add_ps(_mm_mul_ps(v37, v35), v35);
        v40 = v2[v25->m_vertices[v27]->m_index].m_quad;
        v41 = _mm_sub_ps(
                *(__m128 *)_xmm,
                _mm_xor_ps(
                  _mm_or_ps(
                    _mm_andnot_ps(
                      v32,
                      _mm_or_ps(
                        _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v39, v39)), v34),
                        _mm_andnot_ps(v34, v39))),
                    _mm_and_ps(v32, v31)),
                  _mm_and_ps(v30, *(__m128 *)_xmm)));
        v2[v25->m_vertices[v27]->m_index].m_quad = _mm_shuffle_ps(
                                                     v2[v25->m_vertices[v27]->m_index].m_quad,
                                                     _mm_unpackhi_ps(
                                                       v2[v25->m_vertices[v27]->m_index].m_quad,
                                                       _mm_max_ps(_mm_shuffle_ps(v40, v40, 255), v41)),
                                                     196);
        v2[v25->m_vertices[v28]->m_index].m_quad = _mm_shuffle_ps(
                                                     v2[v25->m_vertices[v28]->m_index].m_quad,
                                                     _mm_unpackhi_ps(
                                                       v2[v25->m_vertices[v28]->m_index].m_quad,
                                                       _mm_max_ps(_mm_shuffle_ps(v38, v38, 255), v41)),
                                                     196);
        v42 = v2[v25->m_vertices[v27]->m_index].m_quad;
        v43 = _mm_max_ps(v4->m_real, _mm_shuffle_ps(v42, v42, 255));
        *v4 = (hkSimdFloat32)v43;
        v44 = v25->m_vertices[v28]->m_index;
        v4->m_real = _mm_max_ps(v43, _mm_shuffle_ps(v2[v44].m_quad, v2[v44].m_quad, 255));
      }
      if ( v25 )
      {
        hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v46);
        v27 = v46.m_edge.m_index;
        v25 = v46.m_edge.m_triangle;
      }
      v45 = &v46;
      if ( !v25 )
        v45 = 0i64;
    }
    while ( v45 );
  }
  hkgpIndexedMesh::~hkgpIndexedMesh(&v50);
  v48 = 0;
  if ( v49 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v49);
}

// File Line: 961
// RVA: 0xCBDE70
void __fastcall hkGeometryProcessing::fixTJunctions(hkGeometry *geometry, float maxDistance)
{
  hkGeometry *v2; // r13
  int v3; // er14
  float v4; // xmm14_4
  __m128 v5; // xmm11
  __m128i v6; // xmm12
  char v7; // bl
  int v8; // er8
  int v9; // er8
  hkgpIndexedMeshDefinitions::Triangle *v10; // rdx
  unsigned __int64 v11; // r8
  unsigned __int64 v12; // r9
  hkgpIndexedMeshDefinitions::Triangle *v13; // rdx
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v14; // rax
  int *v15; // r15
  signed __int64 v16; // r12
  __int64 v17; // rdi
  __int64 v18; // rdx
  int v19; // ecx
  __m128 *v20; // rdx
  unsigned int v21; // esi
  __m128 v22; // xmm6
  __m128 v23; // xmm7
  hkcdDynamicTree::CodecRawUint *v24; // rdx
  __int64 v25; // rbx
  hkcdDynamicTree::CodecRawUint *v26; // r9
  __int64 v27; // r14
  hkVector4f v28; // xmm7
  hkVector4f v29; // xmm8
  unsigned int v30; // edx
  __m128 *v31; // r10
  __int64 v32; // rax
  signed __int64 v33; // rdi
  __m128 v34; // xmm9
  __m128 v35; // xmm10
  signed __int64 v36; // rcx
  __m128 v37; // xmm1
  __m128 v38; // xmm3
  __m128 *v39; // rcx
  __m128 v40; // xmm2
  __m128 v41; // xmm3
  __m128 v42; // xmm3
  __m128 v43; // xmm2
  __m128 v44; // xmm2
  __m128 v45; // xmm6
  __m128 v46; // xmm5
  __m128 v47; // xmm5
  unsigned __int64 v48; // r11
  float v49; // eax
  signed __int64 v50; // rcx
  __m128 v51; // xmm1
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v52; // rax
  int v53; // ecx
  int v54; // er8
  hkgpIndexedMeshDefinitions::Triangle *v55; // rdx
  unsigned __int64 v56; // r8
  unsigned __int64 v57; // r9
  hkgpIndexedMeshDefinitions::Triangle *v58; // rdi
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v59; // rax
  __int64 v60; // r8
  hkVector4f *v61; // rdx
  __int64 v62; // r9
  __int64 v63; // r10
  __m128 v64; // xmm1
  __m128 v65; // xmm1
  __m128 v66; // xmm4
  __m128 v67; // xmm1
  __m128 v68; // xmm2
  __m128 v69; // xmm1
  __m128 v70; // xmm2
  __m128 v71; // xmm1
  hkLifoAllocator *v72; // rax
  hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkGeometryProcessingInternals::TJunctionsQuery> *v73; // r9
  unsigned int *v74; // rcx
  unsigned __int64 v75; // rdx
  int v76; // eax
  char *v77; // rsi
  signed int v78; // ebx
  hkLifoAllocator *v79; // rax
  int v80; // er8
  signed __int64 v81; // r8
  signed int v82; // eax
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator *v83; // rax
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> v84; // [rsp+30h] [rbp-B0h]
  int v85; // [rsp+48h] [rbp-98h]
  unsigned int branch[2]; // [rsp+4Ch] [rbp-94h]
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > v87; // [rsp+58h] [rbp-88h]
  int v88; // [rsp+70h] [rbp-70h]
  __int64 v89; // [rsp+74h] [rbp-6Ch]
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator v90; // [rsp+80h] [rbp-60h]
  hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator v91; // [rsp+90h] [rbp-50h]
  int v92; // [rsp+A0h] [rbp-40h]
  int v93; // [rsp+A4h] [rbp-3Ch]
  hkResult v94; // [rsp+A8h] [rbp-38h]
  __m128i v95; // [rsp+B0h] [rbp-30h]
  __m128i v96; // [rsp+C0h] [rbp-20h]
  hkcdDynamicTree::CodecRawUint *v97; // [rsp+D0h] [rbp-10h]
  __m128 *v98; // [rsp+D8h] [rbp-8h]
  hkcdTreeQueriesStacks::Dynamic<64,unsigned int> stackInstance; // [rsp+E0h] [rbp+0h]
  __m128 v100; // [rsp+100h] [rbp+20h]
  char v101; // [rsp+110h] [rbp+30h]
  __int128 v102; // [rsp+120h] [rbp+40h]
  hkGeometry *v103; // [rsp+130h] [rbp+50h]
  hkgpIndexedMeshDefinitions::Triangle *v104; // [rsp+138h] [rbp+58h]
  __int64 v105; // [rsp+140h] [rbp+60h]
  int v106; // [rsp+148h] [rbp+68h]
  int v107; // [rsp+14Ch] [rbp+6Ch]
  int v108; // [rsp+150h] [rbp+70h]
  hkVector4f v109; // [rsp+160h] [rbp+80h]
  hkVector4f v110; // [rsp+170h] [rbp+90h]
  hkVector4f v111; // [rsp+180h] [rbp+A0h]
  hkgpIndexedMesh v112; // [rsp+190h] [rbp+B0h]
  int v113; // [rsp+300h] [rbp+220h]
  float v114; // [rsp+308h] [rbp+228h]
  hkResult result; // [rsp+310h] [rbp+230h]
  void *retaddr; // [rsp+318h] [rbp+238h]

  v2 = geometry;
  v3 = 0;
  v4 = fmaxf(0.00000011920929, maxDistance);
  v113 = 0;
  v114 = v4;
  v5 = _mm_shuffle_ps((__m128)LODWORD(v4), (__m128)LODWORD(v4), 0);
  v6 = (__m128i)_mm_mul_ps(v5, v5);
  if ( geometry->m_vertices.m_size > 0 )
  {
    while ( 1 )
    {
      v7 = 0;
      LOBYTE(v114) = 0;
      hkGeometryUtils::weldVertices(v2, v4);
      hkgpIndexedMesh::hkgpIndexedMesh(&v112);
      hkgpIndexedMesh::appendFromGeometry(&v112, v2);
      v8 = v2->m_vertices.m_size;
      v84.m_nodes.m_size = 0;
      v84.m_nodes.m_data = 0i64;
      v84.m_nodes.m_capacityAndFlags = 2147483648;
      v84.m_firstFree = 0;
      *(_QWORD *)branch = 0i64;
      v85 = 0;
      hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
        &v84,
        &result,
        v8);
      v9 = v2->m_vertices.m_size;
      v87.m_storage.m_words.m_data = 0i64;
      v87.m_storage.m_words.m_size = 0;
      v87.m_storage.m_words.m_capacityAndFlags = 2147483648;
      v87.m_storage.m_numBits = 0;
      hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::setSizeAndFill(&v87, 0, v9, 0);
      v10 = v112.m_triangles.m_used;
      v96.m128i_i64[0] = (__int64)v112.m_triangles.m_used;
      v96.m128i_i32[2] = 0;
      _mm_store_si128((__m128i *)&v91, v96);
      if ( v10 )
      {
        v11 = v10->m_vertices[0]->m_index;
        v12 = v10->m_vertices[1]->m_index;
        if ( v11 >= v12 && (v11 > v12) > 0 && v10->m_links[0] & 0xFFFFFFFFFFFFFFFCui64 )
          hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v91);
      }
      v13 = v91.m_edge.m_triangle;
      v14 = &v91;
      if ( !v91.m_edge.m_triangle )
        v14 = 0i64;
      if ( v14 )
      {
        do
        {
          if ( !(v13->m_links[v91.m_edge.m_index] & 0xFFFFFFFFFFFFFFFCui64) )
          {
            v15 = &v92;
            v16 = 2i64;
            v92 = v13->m_vertices[v91.m_edge.m_index]->m_index;
            v93 = v13->m_vertices[(9i64 >> 2 * LOBYTE(v91.m_edge.m_index)) & 3]->m_index;
            do
            {
              v17 = *v15;
              v18 = *v15;
              v19 = *v15 & 0x1F;
              if ( !((v87.m_storage.m_words.m_data[v17 >> 5] >> (*(_BYTE *)v15 & 0x1F)) & 1) )
              {
                v87.m_storage.m_words.m_data[v17 >> 5] |= 1 << v19;
                v20 = &v2->m_vertices.m_data[v18].m_quad;
                v21 = v84.m_firstFree;
                v22 = _mm_add_ps(*v20, v5);
                v23 = _mm_sub_ps(*v20, v5);
                if ( !v84.m_firstFree )
                {
                  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
                    &v84,
                    (hkResult *)&retaddr,
                    v84.m_firstFree + 1);
                  v21 = v84.m_firstFree;
                }
                v24 = v84.m_nodes.m_data;
                v84.m_firstFree = v84.m_nodes.m_data[v21].m_aabb.m_min.m_quad.m128_u32[0];
                v25 = v21;
                v84.m_nodes.m_data[v25].m_children[0] = 0;
                v24[v25].m_children[1] = v17;
                v24[v25].m_aabb.m_min.m_quad = v23;
                v24[v25].m_aabb.m_max.m_quad = v22;
                v26 = v84.m_nodes.m_data;
                v27 = branch[1];
                v28.m_quad = (__m128)v84.m_nodes.m_data[v25].m_aabb.m_min;
                v29.m_quad = (__m128)v84.m_nodes.m_data[v25].m_aabb.m_max;
                if ( branch[1] )
                {
                  v30 = v84.m_firstFree;
                  if ( !v84.m_firstFree )
                  {
                    hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
                      &v84,
                      &v94,
                      v84.m_firstFree + 1);
                    v30 = v84.m_firstFree;
                    v26 = v84.m_nodes.m_data;
                  }
                  v31 = &v26[v27].m_aabb.m_min.m_quad;
                  v84.m_firstFree = v26[v30].m_aabb.m_min.m_quad.m128_u32[0];
                  v32 = v31[2].m128_u32[1];
                  v33 = (signed __int64)&v26[v30];
                  if ( (_DWORD)v32 )
                  {
                    v34 = _mm_add_ps(v29.m_quad, v28.m_quad);
                    v35 = _mm_sub_ps(v29.m_quad, v28.m_quad);
                    do
                    {
                      v36 = v31[2].m128_u32[2];
                      v37 = _mm_max_ps(v31[1], v29.m_quad);
                      *v31 = _mm_min_ps(*v31, v28.m_quad);
                      v31[1] = v37;
                      v97 = &v26[v32];
                      v38 = v97->m_aabb.m_max.m_quad;
                      v39 = &v26[v36].m_aabb.m_min.m_quad;
                      v26 = v84.m_nodes.m_data;
                      v40 = v38;
                      v41 = _mm_sub_ps(v38, v97->m_aabb.m_min.m_quad);
                      v98 = v39;
                      v42 = _mm_add_ps(v41, v35);
                      v43 = _mm_sub_ps(_mm_add_ps(v40, v97->m_aabb.m_min.m_quad), v34);
                      v44 = _mm_mul_ps(v43, v43);
                      v45 = _mm_add_ps(_mm_sub_ps(v39[1], *v39), v35);
                      v46 = _mm_sub_ps(_mm_add_ps(v39[1], *v39), v34);
                      v47 = _mm_mul_ps(v46, v46);
                      v31 = (__m128 *)*(&v97
                                      + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 85))
                                                               + COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 0)))
                                                       + COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 170)))
                                               * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v42, v42, 85))
                                                               + COERCE_FLOAT(_mm_shuffle_ps(v42, v42, 0)))
                                                       + COERCE_FLOAT(_mm_shuffle_ps(v42, v42, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 170))) * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v45, v45, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v45, v45, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v45, v45, 170))))));
                      v32 = v31[2].m128_u32[1];
                    }
                    while ( (_DWORD)v32 );
                  }
                  v48 = ((unsigned __int64)((unsigned __int128)((v33 - (signed __int64)v26)
                                                              * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                      + ((signed __int64)((unsigned __int128)((v33 - (signed __int64)v26)
                                                            * (signed __int128)3074457345618258603i64) >> 64) >> 3);
                  v49 = v31[2].m128_f32[0];
                  if ( v49 == 0.0 )
                    branch[1] = v48;
                  else
                    v26->m_children[(v26[LODWORD(v49)].m_children[1] == ((unsigned __int64)((unsigned __int128)(((char *)v31 - (char *)v26) * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                                                      + (unsigned int)((signed __int64)((unsigned __int128)(((char *)v31 - (char *)v26) * (signed __int128)3074457345618258603i64) >> 64) >> 3))
                                  + 12i64 * LODWORD(v49)] = v48;
                  *(float *)(v33 + 32) = v31[2].m128_f32[0];
                  v50 = (char *)v31 - (char *)v84.m_nodes.m_data;
                  *(_DWORD *)(v33 + 40) = v21;
                  *(_DWORD *)(v33 + 36) = ((unsigned __int64)((unsigned __int128)(v50
                                                                                * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                        + ((signed __int64)((unsigned __int128)(v50
                                                                              * (signed __int128)3074457345618258603i64) >> 64) >> 3);
                  v31[2].m128_i32[0] = v48;
                  v84.m_nodes.m_data[v25].m_parent = v48;
                  v51 = _mm_max_ps(v31[1], v29.m_quad);
                  *(__m128 *)v33 = _mm_min_ps(*v31, v28.m_quad);
                  *(__m128 *)(v33 + 16) = v51;
                }
                else
                {
                  branch[1] = v21;
                  v84.m_nodes.m_data[v25].m_parent = 0;
                }
                ++v85;
              }
              ++v15;
              --v16;
            }
            while ( v16 );
          }
          hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v91);
          v13 = v91.m_edge.m_triangle;
          v52 = &v91;
          if ( !v91.m_edge.m_triangle )
            v52 = 0i64;
        }
        while ( v52 );
        v3 = v113;
        v7 = 0;
      }
      v87.m_storage.m_words.m_size = 0;
      if ( v87.m_storage.m_words.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v87.m_storage.m_words.m_data,
          4 * v87.m_storage.m_words.m_capacityAndFlags);
      hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::rebuildBranchSAH(
        (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)&v84,
        branch[1],
        (hkBool)1,
        32,
        16);
      if ( branch[1] )
      {
        v87.m_storage.m_words.m_size = 0;
        v87.m_storage.m_words.m_data = 0i64;
        v87.m_storage.m_words.m_capacityAndFlags = 2147483648;
        v87.m_storage.m_numBits = 0;
        v89 = 0i64;
        v88 = 0;
        hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::copyTo<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>>(
          (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)&v84,
          (hkcdDynamicTree::DefaultTree48Storage *)&v87);
        hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
          (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v87,
          (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v84);
        v53 = v87.m_storage.m_numBits;
        v87.m_storage.m_numBits = v84.m_firstFree;
        v84.m_firstFree = v53;
        branch[1] = 1;
        v87.m_storage.m_words.m_size = 0;
        if ( v87.m_storage.m_words.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v87.m_storage.m_words.m_data,
            48 * (v87.m_storage.m_words.m_capacityAndFlags & 0x3FFFFFFF));
      }
      v54 = v2->m_triangles.m_size;
      *(_QWORD *)&v87.m_storage.m_words.m_size = 0i64;
      v87.m_storage.m_numBits = 0;
      *(&v87.m_storage.m_numBits + 1) = 2147483648;
      v88 = 0;
      hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::setSizeAndFill(
        (hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > *)((char *)&v87 + 8),
        0,
        v54,
        0);
      v55 = v112.m_triangles.m_used;
      v95.m128i_i32[2] = 0;
      v95.m128i_i64[0] = (__int64)v112.m_triangles.m_used;
      _mm_store_si128((__m128i *)&v90, v95);
      if ( v55 )
      {
        v56 = v55->m_vertices[0]->m_index;
        v57 = v55->m_vertices[1]->m_index;
        if ( v56 >= v57 && (v56 > v57) > 0 && v55->m_links[0] & 0xFFFFFFFFFFFFFFFCui64 )
          hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v90);
      }
      v58 = v90.m_edge.m_triangle;
      v59 = &v90;
      if ( !v90.m_edge.m_triangle )
        v59 = 0i64;
      if ( !v59 )
        break;
      do
      {
        if ( !((*(_DWORD *)(*(_QWORD *)&v87.m_storage.m_words.m_size + 4 * ((signed __int64)SLODWORD(v58->m_index) >> 5)) >> (v58->m_index & 0x1F)) & 1) )
        {
          v60 = *(_QWORD *)&v90.m_edge.m_index;
          if ( !(v58->m_links[v90.m_edge.m_index] & 0xFFFFFFFFFFFFFFFCui64) )
          {
            v61 = v2->m_vertices.m_data;
            v62 = SLODWORD(v58->m_vertices[v90.m_edge.m_index]->m_index);
            v63 = SLODWORD(v58->m_vertices[(9i64 >> 2 * LOBYTE(v90.m_edge.m_index)) & 3]->m_index);
            v64 = _mm_sub_ps(v61[v62].m_quad, v61[v63].m_quad);
            v65 = _mm_mul_ps(v64, v64);
            v66 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)),
                    _mm_shuffle_ps(v65, v65, 170));
            v67 = _mm_rsqrt_ps(v66);
            if ( COERCE_FLOAT(
                   _mm_andnot_ps(
                     _mm_cmpleps(v66, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v66, v67), v67)),
                         _mm_mul_ps(*(__m128 *)_xmm, v67)),
                       v66))) > (float)(v5.m128_f32[0] + v5.m128_f32[0]) )
            {
              v68 = v61[v62].m_quad;
              stackInstance.m_stack.m_size = 1;
              v69 = v68;
              v87.m_storage.m_words.m_data = 0i64;
              v87.m_storage.m_words.m_size = 0;
              v70 = _mm_max_ps(v68, v61[v63].m_quad);
              v87.m_storage.m_words.m_capacityAndFlags = 2147483648;
              v88 = 64;
              v71 = _mm_min_ps(v69, v61[v63].m_quad);
              _mm_store_si128((__m128i *)&v102, v6);
              v100 = v70;
              v101 = 0;
              v103 = v2;
              v104 = v58;
              *(__m128 *)&stackInstance.m_stack.m_localMemory = v71;
              v105 = v60;
              v106 = v62;
              v107 = v63;
              v108 = v58->m_vertices[(18i64 >> 2 * (unsigned __int8)v60) & 3]->m_index;
              v109.m_quad = (__m128)v61[v62];
              v110.m_quad = (__m128)v61[v63];
              v111.m_quad = (__m128)v61[v108];
              stackInstance.m_stack.m_data = (unsigned int *)&v101;
              v72 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              v74 = (unsigned int *)v72->m_cur;
              v75 = (unsigned __int64)(v74 + 64);
              if ( v72->m_slabSize < 256 || (void *)v75 > v72->m_end )
                v74 = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v72, 256);
              else
                v72->m_cur = (void *)v75;
              v87.m_storage.m_words.m_data = v74;
              *(_QWORD *)&v87.m_storage.m_numBits = v74;
              v87.m_storage.m_words.m_capacityAndFlags = -2147483584;
              hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::unary<hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>,hkcdTreeQueriesStacks::Dynamic<64,unsigned int>,hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0>::AabbOverlapsWithEarlyExitWrapper<hkGeometryProcessingInternals::TJunctionsQuery>>(
                (hkcdTreeQueries<hkcdTreeQueriesStacks::Dynamic,64,0> *)&v84,
                (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)&v87,
                &stackInstance,
                v73);
              v76 = v87.m_storage.m_words.m_size;
              v77 = *(char **)&v87.m_storage.m_numBits;
              if ( *(unsigned int **)&v87.m_storage.m_numBits == v87.m_storage.m_words.m_data )
                v76 = 0;
              v87.m_storage.m_words.m_size = v76;
              v78 = (4 * v88 + 127) & 0xFFFFFF80;
              v79 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              v80 = (v78 + 15) & 0xFFFFFFF0;
              if ( v78 > v79->m_slabSize || &v77[v80] != v79->m_cur || v79->m_firstNonLifoEnd == v77 )
                hkLifoAllocator::slowBlockFree(v79, v77, v80);
              else
                v79->m_cur = v77;
              v87.m_storage.m_words.m_size = 0;
              if ( v87.m_storage.m_words.m_capacityAndFlags >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  v87.m_storage.m_words.m_data,
                  4 * v87.m_storage.m_words.m_capacityAndFlags);
              if ( v101 )
              {
                v7 = 1;
                v81 = (signed __int64)SLODWORD(v58->m_index) >> 5;
                v82 = 1 << (v58->m_index & 0x1F);
                LOBYTE(v114) = 1;
                *(_DWORD *)(*(_QWORD *)&v87.m_storage.m_words.m_size + 4 * v81) |= v82;
              }
              else
              {
                v7 = LOBYTE(v114);
              }
            }
          }
        }
        hkgpAbstractMesh<hkgpIndexedMeshDefinitions::Edge,hkgpIndexedMeshDefinitions::Vertex,hkgpIndexedMeshDefinitions::Triangle,hkContainerHeapAllocator>::EdgeIterator::next(&v90);
        v58 = v90.m_edge.m_triangle;
        v83 = &v90;
        if ( !v90.m_edge.m_triangle )
          v83 = 0i64;
      }
      while ( v83 );
      if ( !v7 )
        break;
      hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>((hkaMatrix<float> *)&v87.m_storage.m_words.m_size);
      v84.m_nodes.m_size = 0;
      if ( v84.m_nodes.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v84.m_nodes.m_data,
          48 * (v84.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
      v84.m_nodes.m_data = 0i64;
      v84.m_nodes.m_capacityAndFlags = 2147483648;
      hkgpIndexedMesh::~hkgpIndexedMesh(&v112);
      v113 = ++v3;
      if ( v3 >= v2->m_vertices.m_size )
        return;
    }
    v87.m_storage.m_numBits = 0;
    if ( *(&v87.m_storage.m_numBits + 1) >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)&v87.m_storage.m_words.m_size,
        4 * *(&v87.m_storage.m_numBits + 1));
    *(_QWORD *)&v87.m_storage.m_words.m_size = 0i64;
    *(&v87.m_storage.m_numBits + 1) = 2147483648;
    v84.m_nodes.m_size = 0;
    if ( v84.m_nodes.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v84.m_nodes.m_data,
        48 * (v84.m_nodes.m_capacityAndFlags & 0x3FFFFFFF));
    v84.m_nodes.m_data = 0i64;
    v84.m_nodes.m_capacityAndFlags = 2147483648;
    hkgpIndexedMesh::~hkgpIndexedMesh(&v112);
  }
}tyAndFlags = 2147483648;
    hkgpIndexedMesh::~hkgpIndexedMesh(&v112);
  }
}


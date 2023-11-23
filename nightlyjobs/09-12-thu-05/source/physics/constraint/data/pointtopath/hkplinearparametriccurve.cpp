// File Line: 15
// RVA: 0xD4C570
void __fastcall hkpLinearParametricCurve::hkpLinearParametricCurve(hkpLinearParametricCurve *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_smoothingFactor = 0.0099999998;
  this->vfptr = (hkBaseObjectVtbl *)&hkpLinearParametricCurve::`vftable;
  this->m_closedLoop.m_bool = 0;
  this->m_points.m_data = 0i64;
  this->m_points.m_size = 0;
  this->m_points.m_capacityAndFlags = 0x80000000;
  this->m_distance.m_data = 0i64;
  this->m_distance.m_size = 0;
  this->m_distance.m_capacityAndFlags = 0x80000000;
  this->m_dirNotParallelToTangentAlongWholePath = (hkVector4f)direction.m_quad;
}

// File Line: 22
// RVA: 0xD4C5C0
void __fastcall hkpLinearParametricCurve::getPoint(hkpLinearParametricCurve *this, float t, hkVector4f *pointOnCurve)
{
  int v3; // eax
  __m128 v4; // xmm0

  v3 = (int)t;
  v4 = 0i64;
  if ( (int)t < 0 )
    v3 = 0;
  if ( v3 + 1 >= this->m_points.m_size )
  {
    *pointOnCurve = this->m_points.m_data[v3];
  }
  else
  {
    v4.m128_f32[0] = (float)v3;
    pointOnCurve->m_quad = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_sub_ps(
                                 _mm_shuffle_ps((__m128)LODWORD(t), (__m128)LODWORD(t), 0),
                                 _mm_shuffle_ps(v4, v4, 0)),
                               _mm_sub_ps(this->m_points.m_data[v3 + 1].m_quad, this->m_points.m_data[v3].m_quad)),
                             this->m_points.m_data[v3].m_quad);
  }
}

// File Line: 41
// RVA: 0xD4D170
void __fastcall hkpLinearParametricCurve::setClosedLoop(hkpLinearParametricCurve *this, hkBool closeLoop)
{
  this->m_closedLoop = closeLoop;
}

// File Line: 48
// RVA: 0xD4CF20
hkBool *__fastcall hkpLinearParametricCurve::isClosedLoop(hkpLinearParametricCurve *this, hkBool *result)
{
  result->m_bool = (char)this->m_closedLoop;
  return result;
}

// File Line: 56
// RVA: 0xD4C640
float __fastcall hkpLinearParametricCurve::getNearestPoint(
        hkpLinearParametricCurve *this,
        float t,
        hkVector4f *nearPoint,
        hkVector4f *pointOnCurve)
{
  int m_size; // edi
  __int64 v5; // rdx
  int v9; // r10d
  hkVector4f *m_data; // rsi
  __m128 m_quad; // xmm6
  __int64 v12; // rcx
  int v13; // r8d
  __m128 *p_m_quad; // r9
  __m128 *v15; // r11
  __m128 *v16; // rax
  __m128 v17; // xmm5
  __m128 v18; // xmm8
  __m128 v19; // xmm1
  __m128 v20; // xmm4
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm7
  __m128 v26; // xmm2
  __m128 v27; // xmm9
  __m128 v28; // xmm2
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  __m128 v33; // xmm8
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  __m128 v36; // xmm3
  __m128 v37; // xmm0
  __m128 v38; // xmm2
  __m128 v39; // xmm3
  float v40; // xmm0_4
  float v41; // xmm4_4
  float v42; // xmm2_4
  float result; // xmm0_4

  m_size = this->m_points.m_size;
  v5 = (unsigned int)(int)t;
  if ( (int)v5 < 0 )
    v5 = 0i64;
  v9 = v5 + 1;
  if ( (int)v5 + 1 >= m_size )
  {
    v9 = m_size - 1;
    v5 = (unsigned int)(m_size - 2);
  }
  m_data = this->m_points.m_data;
  m_quad = nearPoint->m_quad;
  v12 = (int)v5;
  v13 = v9 + 1;
  p_m_quad = &m_data[v9].m_quad;
  v15 = p_m_quad + 1;
  v16 = &m_data[(int)v5].m_quad;
  while ( 1 )
  {
    while ( 1 )
    {
      v17 = *p_m_quad;
      v18 = _mm_sub_ps(*p_m_quad, *v16);
      v19 = _mm_mul_ps(_mm_sub_ps(m_quad, *v16), v18);
      v20 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
              _mm_shuffle_ps(v19, v19, 170));
      v21 = _mm_mul_ps(v18, v18);
      v22 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
              _mm_shuffle_ps(v21, v21, 170));
      v23 = _mm_rcp_ps(v22);
      v24 = _mm_mul_ps(v20, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v22)), v23));
      if ( v24.m128_f32[0] >= 0.0 )
        break;
      if ( !v12 )
        goto LABEL_17;
      v5 = (unsigned int)(v5 - 1);
      --v12;
      --v16;
      --v9;
      --v13;
      --v15;
      --p_m_quad;
    }
    v25 = _mm_sub_ps(m_quad, v17);
    v26 = _mm_mul_ps(v25, v18);
    if ( (float)((float)(_mm_shuffle_ps(v26, v26, 85).m128_f32[0] + _mm_shuffle_ps(v26, v26, 0).m128_f32[0])
               + _mm_shuffle_ps(v26, v26, 170).m128_f32[0]) <= 0.0
      || v13 >= m_size )
    {
      break;
    }
    v27 = _mm_sub_ps(*v15, v17);
    v28 = _mm_mul_ps(v25, v27);
    if ( (float)((float)(_mm_shuffle_ps(v28, v28, 85).m128_f32[0] + _mm_shuffle_ps(v28, v28, 0).m128_f32[0])
               + _mm_shuffle_ps(v28, v28, 170).m128_f32[0]) <= 0.0 )
    {
      v29 = _mm_mul_ps(v18, v18);
      v30 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
              _mm_shuffle_ps(v29, v29, 170));
      v31 = _mm_rsqrt_ps(v30);
      v32 = _mm_mul_ps(v27, v27);
      v33 = _mm_mul_ps(
              v18,
              _mm_andnot_ps(
                _mm_cmple_ps(v30, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                  _mm_mul_ps(v31, *(__m128 *)_xmm))));
      v34 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
              _mm_shuffle_ps(v32, v32, 170));
      v35 = _mm_rsqrt_ps(v34);
      v36 = _mm_cmple_ps(v34, (__m128)0i64);
      v37 = _mm_mul_ps(_mm_mul_ps(v35, v34), v35);
      v38 = _mm_mul_ps(v25, v33);
      v39 = _mm_mul_ps(
              _mm_mul_ps(
                _mm_andnot_ps(v36, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v37), _mm_mul_ps(v35, *(__m128 *)_xmm))),
                v27),
              v25);
      if ( (float)(0.0
                 - (float)((float)(_mm_shuffle_ps(v39, v39, 85).m128_f32[0] + _mm_shuffle_ps(v39, v39, 0).m128_f32[0])
                         + _mm_shuffle_ps(v39, v39, 170).m128_f32[0])) <= (float)((float)(_mm_shuffle_ps(v38, v38, 85).m128_f32[0]
                                                                                        + _mm_shuffle_ps(v38, v38, 0).m128_f32[0])
                                                                                + _mm_shuffle_ps(v38, v38, 170).m128_f32[0]) )
      {
        v40 = FLOAT_0_0099999998;
        v5 = (unsigned int)(v5 + 1);
        ++v9;
      }
      else
      {
        v40 = FLOAT_0_99000001;
      }
      v24 = _mm_shuffle_ps((__m128)LODWORD(v40), (__m128)LODWORD(v40), 0);
      break;
    }
    v5 = (unsigned int)(v5 + 1);
    ++v12;
    ++v16;
    ++v9;
    ++v13;
    ++v15;
    ++p_m_quad;
  }
LABEL_17:
  pointOnCurve->m_quad = _mm_add_ps(
                           _mm_mul_ps(_mm_sub_ps(m_data[v9].m_quad, m_data[(int)v5].m_quad), v24),
                           m_data[(int)v5].m_quad);
  v41 = v24.m128_f32[0] + (float)(int)v5;
  if ( !this->m_closedLoop.m_bool )
    return v41;
  v42 = (float)(this->m_points.m_size - 1);
  if ( v41 < 0.25 )
  {
    result = 1.0 - v41;
    ((void (__fastcall *)(hkpLinearParametricCurve *, __int64, hkVector4f *, hkVector4f *))this->vfptr[2].__vecDelDtor)(
      this,
      v5,
      nearPoint,
      pointOnCurve);
    return result;
  }
  result = v42 - 0.25;
  if ( v41 <= (float)(v42 - 0.25) )
    return v41;
  ((void (__fastcall *)(hkpLinearParametricCurve *, __int64, hkVector4f *, hkVector4f *))this->vfptr[2].__vecDelDtor)(
    this,
    v5,
    nearPoint,
    pointOnCurve);
  return result;
}

// File Line: 181
// RVA: 0xD4C9F0
void __fastcall hkpLinearParametricCurve::getTangent(hkpLinearParametricCurve *this, float t, hkVector4f *tangent)
{
  __m128 v4; // xmm6
  __m128 v5; // xmm1
  __m128 v6; // xmm7
  int v7; // r8d
  __m128 v8; // xmm8
  int m_size; // eax
  int v10; // r9d
  __int64 v11; // rbx
  __int64 v12; // rdi
  __m128 v13; // xmm5
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm10
  __m128 v19; // xmm4
  __m128 v20; // xmm1
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  __m128 v23; // xmm5
  __m128 v24; // xmm1
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  __m128 v27; // xmm5
  __m128 v28; // xmm5
  __m128 v29; // xmm4
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  __m128 v33; // xmm6
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  __m128 v36; // xmm1

  v4 = _mm_shuffle_ps((__m128)LODWORD(this->m_smoothingFactor), (__m128)LODWORD(this->m_smoothingFactor), 0);
  v5 = _mm_rcp_ps(v4);
  v6 = _mm_shuffle_ps((__m128)LODWORD(t), (__m128)LODWORD(t), 0);
  v7 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v6));
  v8 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v4, v5)), v5);
  if ( v7 < 0 )
    v7 = 0;
  m_size = this->m_points.m_size;
  v10 = v7 + 1;
  if ( v7 + 1 >= m_size )
  {
    v10 = m_size - 1;
    v7 = m_size - 2;
  }
  v11 = v10;
  v12 = v7;
  v13 = _mm_sub_ps(this->m_points.m_data[v10].m_quad, this->m_points.m_data[v7].m_quad);
  v14 = _mm_mul_ps(v13, v13);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_rsqrt_ps(v15);
  v17 = 0i64;
  v17.m128_f32[0] = (float)v7;
  v18 = _mm_sub_ps(v6, _mm_shuffle_ps(v17, v17, 0));
  tangent->m_quad = _mm_mul_ps(
                      _mm_andnot_ps(
                        _mm_cmple_ps(v15, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
                          _mm_mul_ps(v16, *(__m128 *)_xmm))),
                      v13);
  if ( v18.m128_f32[0] < v4.m128_f32[0] && v7 > 0 )
  {
    --v10;
    v12 = v7 - 1;
    v11 = v10;
    v19 = _mm_sub_ps(this->m_points.m_data[v10].m_quad, this->m_points.m_data[v12].m_quad);
    v20 = _mm_mul_ps(v19, v19);
    v21 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
            _mm_shuffle_ps(v20, v20, 170));
    v22 = _mm_rsqrt_ps(v21);
    v23 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(
                _mm_mul_ps(
                  _mm_andnot_ps(
                    _mm_cmple_ps(v21, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                      _mm_mul_ps(v22, *(__m128 *)_xmm))),
                  v19),
                tangent->m_quad),
              _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v4, v18), (__m128)xmmword_141A711B0), v8)),
            tangent->m_quad);
    v24 = _mm_mul_ps(v23, v23);
    v25 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
            _mm_shuffle_ps(v24, v24, 170));
    v26 = _mm_rsqrt_ps(v25);
    tangent->m_quad = _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmple_ps(v25, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                            _mm_mul_ps(v26, *(__m128 *)_xmm))),
                        v23);
  }
  v27 = 0i64;
  v27.m128_f32[0] = (float)v10;
  v28 = _mm_sub_ps(_mm_shuffle_ps(v27, v27, 0), v6);
  if ( v28.m128_f32[0] < v4.m128_f32[0] && v10 < this->m_points.m_size - 1 )
  {
    v29 = _mm_sub_ps(this->m_points.m_data[v11 + 1].m_quad, this->m_points.m_data[v12 + 1].m_quad);
    v30 = _mm_mul_ps(v29, v29);
    v31 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
            _mm_shuffle_ps(v30, v30, 170));
    v32 = _mm_rsqrt_ps(v31);
    v33 = _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v4, v28), (__m128)xmmword_141A711B0), v8),
              _mm_sub_ps(
                _mm_mul_ps(
                  _mm_andnot_ps(
                    _mm_cmple_ps(v31, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)),
                      _mm_mul_ps(v32, *(__m128 *)_xmm))),
                  v29),
                tangent->m_quad)),
            tangent->m_quad);
    v34 = _mm_mul_ps(v33, v33);
    v35 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
            _mm_shuffle_ps(v34, v34, 170));
    v36 = _mm_rsqrt_ps(v35);
    tangent->m_quad = _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmple_ps(v35, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v36, v35), v36)),
                            _mm_mul_ps(v36, *(__m128 *)_xmm))),
                        v33);
  }
}

// File Line: 241
// RVA: 0xD4CD10
float __fastcall hkpLinearParametricCurve::getStart(hkpLinearParametricCurve *this)
{
  return 0.0;
}

// File Line: 248
// RVA: 0xD4CD20
float __fastcall hkpLinearParametricCurve::getEnd(hkpLinearParametricCurve *this)
{
  return (float)(this->m_points.m_size - 1);
}

// File Line: 255
// RVA: 0xD4CD40
float __fastcall hkpLinearParametricCurve::getLengthFromStart(hkpLinearParametricCurve *this, float t)
{
  __int64 v2; // rdx
  int v3; // eax
  __int64 v4; // r8
  float v5; // xmm2_4

  LODWORD(v2) = (int)t;
  if ( (int)t < 0 )
    LODWORD(v2) = 0;
  v3 = this->m_points.m_size - 1;
  if ( (int)v2 < v3 )
  {
    v4 = (int)v2;
    v5 = this->m_distance.m_data[v4 + 1] - this->m_distance.m_data[v4];
  }
  else
  {
    v2 = v3;
    v4 = v2;
    v5 = this->m_distance.m_data[v2] - this->m_distance.m_data[v2 - 1];
  }
  return (float)((float)(t - (float)(int)v2) * v5) + this->m_distance.m_data[v4];
}

// File Line: 279
// RVA: 0xD4CDC0
void __fastcall hkpLinearParametricCurve::getBinormal(hkpLinearParametricCurve *this, float t, hkVector4f *up)
{
  __int64 v3; // rdx
  __m128 v6; // xmm2
  __m128 v7; // xmm1
  __m128 v8; // xmm6
  __m128 v9; // xmm5
  __m128 v10; // xmm6
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // [rsp+20h] [rbp-28h] BYREF

  ((void (__fastcall *)(hkpLinearParametricCurve *, __int64, __m128 *))this->vfptr[2].__first_virtual_table_function__)(
    this,
    v3,
    &v17);
  v6 = _mm_mul_ps(direction.m_quad, v17);
  if ( (float)((float)(_mm_shuffle_ps(v6, v6, 85).m128_f32[0] + _mm_shuffle_ps(v6, v6, 0).m128_f32[0])
             + _mm_shuffle_ps(v6, v6, 170).m128_f32[0]) >= 0.98000002 )
  {
    v8 = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, (__m128)0i64), 196);
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
    up->m_quad = _mm_xor_ps(
                   _mm_or_ps(_mm_and_ps(v10, v13), _mm_andnot_ps(v13, v9)),
                   (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
  }
  else
  {
    v7 = _mm_sub_ps(
           _mm_mul_ps(
             _mm_shuffle_ps(
               this->m_dirNotParallelToTangentAlongWholePath.m_quad,
               this->m_dirNotParallelToTangentAlongWholePath.m_quad,
               201),
             v17),
           _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), this->m_dirNotParallelToTangentAlongWholePath.m_quad));
    up->m_quad = _mm_shuffle_ps(v7, v7, 201);
  }
  v14 = _mm_mul_ps(up->m_quad, up->m_quad);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_rsqrt_ps(v15);
  up->m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v15, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
                     _mm_mul_ps(*(__m128 *)_xmm, v16))),
                 up->m_quad);
}

// File Line: 298
// RVA: 0xD4CF30
void __fastcall hkpLinearParametricCurve::addPoint(hkpLinearParametricCurve *this, hkVector4f *p)
{
  __int64 m_size; // rax
  __m128 v5; // xmm1
  __m128 v6; // xmm1
  __m128 v7; // xmm3
  __m128 v8; // xmm1
  float v9; // xmm6_4

  if ( this->m_points.m_size == (this->m_points.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_points.m_data, 16);
  this->m_points.m_data[this->m_points.m_size++] = (hkVector4f)p->m_quad;
  m_size = this->m_points.m_size;
  if ( (_DWORD)m_size == 1 )
  {
    if ( this->m_distance.m_size == (this->m_distance.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_distance.m_data, 4);
    this->m_distance.m_data[this->m_distance.m_size++] = 0.0;
  }
  else
  {
    v5 = _mm_sub_ps(p->m_quad, this->m_points.m_data[m_size - 2].m_quad);
    v6 = _mm_mul_ps(v5, v5);
    v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
    v8 = _mm_rsqrt_ps(v7);
    v9 = _mm_andnot_ps(
           _mm_cmple_ps(v7, (__m128)0i64),
           _mm_mul_ps(
             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)), _mm_mul_ps(*(__m128 *)_xmm, v8)),
             v7)).m128_f32[0]
       + this->m_distance.m_data[this->m_distance.m_size - 1];
    if ( this->m_distance.m_size == (this->m_distance.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_distance.m_data, 4);
    this->m_distance.m_data[this->m_distance.m_size++] = v9;
  }
}

// File Line: 321
// RVA: 0xD4D090
float __fastcall hkpLinearParametricCurve::getSmoothingFactor(hkpLinearParametricCurve *this)
{
  return this->m_smoothingFactor;
}

// File Line: 329
// RVA: 0xD4D0A0
void __fastcall hkpLinearParametricCurve::setSmoothingFactor(hkpLinearParametricCurve *this, float smooth)
{
  this->m_smoothingFactor = smooth;
}

// File Line: 336
// RVA: 0xD4D0B0
void __fastcall hkpLinearParametricCurve::getPointsToDraw(
        hkpLinearParametricCurve *this,
        hkArray<hkVector4f,hkContainerHeapAllocator> *pathPoints)
{
  __int64 m_size; // rcx
  hkVector4f *m_data; // rax
  __int64 v6; // rdx
  char *v7; // r8
  hkVector4f v8; // xmm0
  int v9; // [rsp+30h] [rbp+8h] BYREF

  if ( (pathPoints->m_capacityAndFlags & 0x3FFFFFFF) < this->m_points.m_size )
  {
    if ( pathPoints->m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        pathPoints->m_data,
        16 * pathPoints->m_capacityAndFlags);
    v9 = 16 * this->m_points.m_size;
    pathPoints->m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                         &hkContainerHeapAllocator::s_alloc,
                                         &v9);
    pathPoints->m_capacityAndFlags = v9 / 16;
  }
  m_size = this->m_points.m_size;
  m_data = pathPoints->m_data;
  pathPoints->m_size = m_size;
  v6 = m_size;
  if ( (int)m_size > 0 )
  {
    v7 = (char *)((char *)this->m_points.m_data - (char *)m_data);
    do
    {
      v8.m_quad = *(__m128 *)((char *)m_data++ + (_QWORD)v7);
      m_data[-1] = (hkVector4f)v8.m_quad;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 348
// RVA: 0xD4D180
void __fastcall hkpLinearParametricCurve::transformPoints(hkpLinearParametricCurve *this, hkTransformf *transformation)
{
  __int64 m_size; // r8
  __int64 v3; // r9
  hkVector4f *m_data; // rax
  __m128 m_quad; // xmm1

  m_size = this->m_points.m_size;
  if ( m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      m_data = this->m_points.m_data;
      m_quad = m_data[v3++].m_quad;
      m_data[v3 - 1].m_quad = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(m_quad, m_quad, 85),
                                      transformation->m_rotation.m_col1.m_quad),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(m_quad, m_quad, 0),
                                      transformation->m_rotation.m_col0.m_quad)),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(m_quad, m_quad, 170),
                                    transformation->m_rotation.m_col2.m_quad)),
                                transformation->m_translation.m_quad);
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 361
// RVA: 0xD4D1E0
hkpLinearParametricCurve *__fastcall hkpLinearParametricCurve::clone(hkpLinearParametricCurve *this)
{
  _QWORD **Value; // rax
  hkpLinearParametricCurve *v3; // rax
  __int64 v4; // r14
  hkpLinearParametricCurve *v5; // rax
  hkpLinearParametricCurve *v6; // rdi
  int m_size; // eax
  __int64 v8; // rsi
  __int64 v9; // rbx
  __int64 v10; // rax
  float *m_data; // r11
  float *v12; // r9
  __int64 v13; // rdx
  float *v14; // rcx
  char *v15; // r8
  unsigned __int64 v16; // r10
  int v17; // eax
  char *v18; // r9
  float *v19; // rcx
  __int64 v20; // rdx
  int v21; // eax
  int v23; // [rsp+40h] [rbp+8h] BYREF

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpLinearParametricCurve *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
  v4 = 0i64;
  if ( v3 )
  {
    hkpLinearParametricCurve::hkpLinearParametricCurve(v3);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  m_size = this->m_points.m_size;
  if ( m_size > 0 )
  {
    v8 = (unsigned int)m_size;
    v9 = 0i64;
    do
    {
      hkpLinearParametricCurve::addPoint(v6, &this->m_points.m_data[v9++]);
      --v8;
    }
    while ( v8 );
  }
  v6->m_closedLoop.m_bool = this->m_closedLoop.m_bool;
  v6->m_dirNotParallelToTangentAlongWholePath.m_quad = _mm_shuffle_ps(
                                                         this->m_dirNotParallelToTangentAlongWholePath.m_quad,
                                                         _mm_unpackhi_ps(
                                                           this->m_dirNotParallelToTangentAlongWholePath.m_quad,
                                                           (__m128)0i64),
                                                         196);
  if ( (v6->m_distance.m_capacityAndFlags & 0x3FFFFFFF) < this->m_distance.m_size )
  {
    if ( v6->m_distance.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v6->m_distance.m_data,
        4 * v6->m_distance.m_capacityAndFlags);
    v23 = 4 * this->m_distance.m_size;
    v6->m_distance.m_data = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                       &hkContainerHeapAllocator::s_alloc,
                                       &v23);
    v6->m_distance.m_capacityAndFlags = v23 / 4;
  }
  v10 = this->m_distance.m_size;
  m_data = v6->m_distance.m_data;
  v6->m_distance.m_size = v10;
  v12 = this->m_distance.m_data;
  v13 = v10;
  if ( v10 >= 4 )
  {
    v14 = m_data + 1;
    v15 = (char *)((char *)v12 - (char *)m_data);
    v16 = ((unsigned __int64)(v10 - 4) >> 2) + 1;
    v4 = 4 * v16;
    do
    {
      v17 = *(_DWORD *)((char *)v14 + (_QWORD)v15 - 4);
      v14 += 4;
      *((_DWORD *)v14 - 5) = v17;
      *(v14 - 4) = *(float *)((char *)v14 + (_QWORD)v15 - 16);
      *(v14 - 3) = *(float *)((char *)v14 + (_QWORD)v15 - 12);
      *(v14 - 2) = *(float *)((char *)v14 + (_QWORD)v15 - 8);
      --v16;
    }
    while ( v16 );
  }
  if ( v4 < v13 )
  {
    v18 = (char *)((char *)v12 - (char *)m_data);
    v19 = &m_data[v4];
    v20 = v13 - v4;
    do
    {
      v21 = *(_DWORD *)&v18[(_QWORD)v19++];
      *((_DWORD *)v19 - 1) = v21;
      --v20;
    }
    while ( v20 );
  }
  v6->m_smoothingFactor = this->m_smoothingFactor;
  return v6;
}


// File Line: 15
// RVA: 0xD4C570
void __fastcall hkpLinearParametricCurve::hkpLinearParametricCurve(hkpLinearParametricCurve *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_smoothingFactor = 0.0099999998;
  this->vfptr = (hkBaseObjectVtbl *)&hkpLinearParametricCurve::`vftable';
  this->m_closedLoop.m_bool = 0;
  this->m_points.m_data = 0i64;
  this->m_points.m_size = 0;
  this->m_points.m_capacityAndFlags = 2147483648;
  this->m_distance.m_data = 0i64;
  this->m_distance.m_size = 0;
  this->m_distance.m_capacityAndFlags = 2147483648;
  this->m_dirNotParallelToTangentAlongWholePath = (hkVector4f)direction.m_quad;
}

// File Line: 22
// RVA: 0xD4C5C0
void __fastcall hkpLinearParametricCurve::getPoint(hkpLinearParametricCurve *this, float t, hkVector4f *pointOnCurve)
{
  signed int v3; // eax
  __m128 v4; // xmm0

  v3 = (signed int)t;
  v4 = 0i64;
  if ( (signed int)t < 0 )
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
float __fastcall hkpLinearParametricCurve::getNearestPoint(hkpLinearParametricCurve *this, float t, hkVector4f *nearPoint, hkVector4f *pointOnCurve)
{
  int v4; // edi
  __int64 v5; // rdx
  hkVector4f *v6; // r14
  hkVector4f *v7; // rbp
  hkpLinearParametricCurve *v8; // rbx
  int v9; // er10
  hkVector4f *v10; // rsi
  __m128 v11; // xmm6
  __int64 v12; // rcx
  int v13; // er8
  __m128 *v14; // r9
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

  v4 = this->m_points.m_size;
  v5 = (unsigned int)(signed int)t;
  v6 = pointOnCurve;
  v7 = nearPoint;
  v8 = this;
  if ( (signed int)v5 < 0 )
    v5 = 0i64;
  v9 = v5 + 1;
  if ( (signed int)v5 + 1 >= v4 )
  {
    v9 = v4 - 1;
    v5 = (unsigned int)(v4 - 2);
  }
  v10 = this->m_points.m_data;
  v11 = nearPoint->m_quad;
  v12 = (signed int)v5;
  v13 = v9 + 1;
  v14 = &v10[v9].m_quad;
  v15 = v14 + 1;
  v16 = &v10[(signed int)v5].m_quad;
  while ( 1 )
  {
    while ( 1 )
    {
      v17 = *v14;
      v18 = _mm_sub_ps(*v14, *v16);
      v19 = _mm_mul_ps(_mm_sub_ps(v11, *v16), v18);
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
      --v14;
    }
    v25 = _mm_sub_ps(v11, v17);
    v26 = _mm_mul_ps(v25, v18);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 170))) <= 0.0
      || v13 >= v4 )
    {
      break;
    }
    v27 = _mm_sub_ps(*v15, v17);
    v28 = _mm_mul_ps(v25, v27);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v28, v28, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v28, v28, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v28, v28, 170))) <= 0.0 )
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
                _mm_cmpleps(v30, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                  _mm_mul_ps(v31, *(__m128 *)_xmm))));
      v34 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
              _mm_shuffle_ps(v32, v32, 170));
      v35 = _mm_rsqrt_ps(v34);
      v36 = _mm_cmpleps(v34, (__m128)0i64);
      v37 = _mm_mul_ps(_mm_mul_ps(v35, v34), v35);
      v38 = _mm_mul_ps(v25, v33);
      v39 = _mm_mul_ps(
              _mm_mul_ps(
                _mm_andnot_ps(v36, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v37), _mm_mul_ps(v35, *(__m128 *)_xmm))),
                v27),
              v25);
      if ( (float)(0.0
                 - (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 170)))) <= (float)((float)(COERCE_FLOAT(
                                                                                              _mm_shuffle_ps(
                                                                                                v38,
                                                                                                v38,
                                                                                                85))
                                                                                          + COERCE_FLOAT(
                                                                                              _mm_shuffle_ps(
                                                                                                v38,
                                                                                                v38,
                                                                                                0)))
                                                                                  + COERCE_FLOAT(_mm_shuffle_ps(v38, v38, 170))) )
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
    ++v14;
  }
LABEL_17:
  v6->m_quad = _mm_add_ps(
                 _mm_mul_ps(_mm_sub_ps(v10[v9].m_quad, v10[(signed int)v5].m_quad), v24),
                 v10[(signed int)v5].m_quad);
  v41 = v24.m128_f32[0] + (float)(signed int)v5;
  if ( !v8->m_closedLoop.m_bool )
    return v41;
  v42 = (float)(v8->m_points.m_size - 1);
  if ( v41 < 0.25 )
  {
    result = 1.0 - v41;
    ((void (__fastcall *)(hkpLinearParametricCurve *, __int64, hkVector4f *, hkVector4f *))v8->vfptr[2].__vecDelDtor)(
      v8,
      v5,
      v7,
      v6);
    return result;
  }
  result = v42 - 0.25;
  if ( v41 <= (float)(v42 - 0.25) )
    return v41;
  ((void (__fastcall *)(hkpLinearParametricCurve *, __int64, hkVector4f *, hkVector4f *))v8->vfptr[2].__vecDelDtor)(
    v8,
    v5,
    v7,
    v6);
  return result;
}

// File Line: 181
// RVA: 0xD4C9F0
void __fastcall hkpLinearParametricCurve::getTangent(hkpLinearParametricCurve *this, float t, hkVector4f *tangent)
{
  hkVector4f *v3; // r11
  __m128 v4; // xmm6
  __m128 v5; // xmm1
  __m128 v6; // xmm7
  int v7; // er8
  __m128 v8; // xmm8
  int v9; // eax
  int v10; // er9
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
  float v37; // [rsp+88h] [rbp+10h]

  v37 = t;
  v3 = tangent;
  v4 = _mm_shuffle_ps((__m128)LODWORD(this->m_smoothingFactor), (__m128)LODWORD(this->m_smoothingFactor), 0);
  v5 = _mm_rcp_ps(v4);
  v6 = _mm_shuffle_ps((__m128)LODWORD(v37), (__m128)LODWORD(v37), 0);
  v7 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v6));
  v8 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v4, v5)), v5);
  if ( v7 < 0 )
    v7 = 0;
  v9 = this->m_points.m_size;
  v10 = v7 + 1;
  if ( v7 + 1 >= v9 )
  {
    v10 = v9 - 1;
    v7 = v9 - 2;
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
  v3->m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v15, (__m128)0i64),
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
                    _mm_cmpleps(v21, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                      _mm_mul_ps(v22, *(__m128 *)_xmm))),
                  v19),
                v3->m_quad),
              _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v4, v18), (__m128)xmmword_141A711B0), v8)),
            v3->m_quad);
    v24 = _mm_mul_ps(v23, v23);
    v25 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
            _mm_shuffle_ps(v24, v24, 170));
    v26 = _mm_rsqrt_ps(v25);
    v3->m_quad = _mm_mul_ps(
                   _mm_andnot_ps(
                     _mm_cmpleps(v25, (__m128)0i64),
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
                    _mm_cmpleps(v31, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)),
                      _mm_mul_ps(v32, *(__m128 *)_xmm))),
                  v29),
                v3->m_quad)),
            v3->m_quad);
    v34 = _mm_mul_ps(v33, v33);
    v35 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
            _mm_shuffle_ps(v34, v34, 170));
    v36 = _mm_rsqrt_ps(v35);
    v3->m_quad = _mm_mul_ps(
                   _mm_andnot_ps(
                     _mm_cmpleps(v35, (__m128)0i64),
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

  LODWORD(v2) = (signed int)t;
  if ( (signed int)t < 0 )
    LODWORD(v2) = 0;
  v3 = this->m_points.m_size - 1;
  if ( (signed int)v2 < v3 )
  {
    v4 = (signed int)v2;
    v5 = this->m_distance.m_data[(signed int)v2 + 1] - this->m_distance.m_data[(signed int)v2];
  }
  else
  {
    v2 = v3;
    v4 = v2;
    v5 = this->m_distance.m_data[v2] - this->m_distance.m_data[v2 - 1];
  }
  return (float)((float)(t - (float)(signed int)v2) * v5) + this->m_distance.m_data[v4];
}

// File Line: 279
// RVA: 0xD4CDC0
void __usercall hkpLinearParametricCurve::getBinormal(hkpLinearParametricCurve *this@<rcx>, float t@<xmm1>, hkVector4f *up@<r8>, __int64 a4@<rdx>)
{
  hkVector4f *v4; // rdi
  hkpLinearParametricCurve *v5; // rbx
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
  __m128 v17; // [rsp+20h] [rbp-28h]

  v4 = up;
  v5 = this;
  ((void (__fastcall *)(hkpLinearParametricCurve *, __int64, __m128 *))this->vfptr[2].__first_virtual_table_function__)(
    this,
    a4,
    &v17);
  v6 = _mm_mul_ps(direction.m_quad, v17);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 170))) >= 0.98000002 )
  {
    v8 = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, (__m128)0i64), 196);
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
    v4->m_quad = _mm_xor_ps(
                   _mm_or_ps(_mm_and_ps(v10, v13), _mm_andnot_ps(v13, v9)),
                   (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
  }
  else
  {
    v7 = _mm_sub_ps(
           _mm_mul_ps(
             _mm_shuffle_ps(
               v5->m_dirNotParallelToTangentAlongWholePath.m_quad,
               v5->m_dirNotParallelToTangentAlongWholePath.m_quad,
               201),
             v17),
           _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v5->m_dirNotParallelToTangentAlongWholePath.m_quad));
    v4->m_quad = _mm_shuffle_ps(v7, v7, 201);
  }
  v14 = _mm_mul_ps(v4->m_quad, v4->m_quad);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_rsqrt_ps(v15);
  v4->m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v15, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
                     _mm_mul_ps(*(__m128 *)_xmm, v16))),
                 v4->m_quad);
}

// File Line: 298
// RVA: 0xD4CF30
void __fastcall hkpLinearParametricCurve::addPoint(hkpLinearParametricCurve *this, hkVector4f *p)
{
  hkVector4f *v2; // rsi
  hkpLinearParametricCurve *v3; // rdi
  __int64 v4; // rax
  __m128 v5; // xmm1
  __m128 v6; // xmm1
  __m128 v7; // xmm3
  __m128 v8; // xmm1
  float v9; // xmm6_4

  v2 = p;
  v3 = this;
  if ( this->m_points.m_size == (this->m_points.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &this->m_points, 16);
  v3->m_points.m_data[v3->m_points.m_size++] = (hkVector4f)v2->m_quad;
  v4 = v3->m_points.m_size;
  if ( (_DWORD)v4 == 1 )
  {
    if ( v3->m_distance.m_size == (v3->m_distance.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_distance, 4);
    v3->m_distance.m_data[v3->m_distance.m_size++] = 0.0;
  }
  else
  {
    v5 = _mm_sub_ps(v2->m_quad, v3->m_points.m_data[v4 - 2].m_quad);
    v6 = _mm_mul_ps(v5, v5);
    v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
    v8 = _mm_rsqrt_ps(v7);
    v9 = COERCE_FLOAT(
           _mm_andnot_ps(
             _mm_cmpleps(v7, (__m128)0i64),
             _mm_mul_ps(
               _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8)), _mm_mul_ps(*(__m128 *)_xmm, v8)),
               v7)))
       + v3->m_distance.m_data[v3->m_distance.m_size - 1];
    if ( v3->m_distance.m_size == (v3->m_distance.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_distance, 4);
    v3->m_distance.m_data[v3->m_distance.m_size++] = v9;
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
void __fastcall hkpLinearParametricCurve::getPointsToDraw(hkpLinearParametricCurve *this, hkArray<hkVector4f,hkContainerHeapAllocator> *pathPoints)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v2; // rbx
  hkpLinearParametricCurve *v3; // rdi
  __int64 v4; // rcx
  hkVector4f *v5; // rax
  __int64 v6; // rdx
  char *v7; // r8
  hkVector4f v8; // xmm0
  int v9; // [rsp+30h] [rbp+8h]

  v2 = pathPoints;
  v3 = this;
  if ( (pathPoints->m_capacityAndFlags & 0x3FFFFFFF) < this->m_points.m_size )
  {
    if ( pathPoints->m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        pathPoints->m_data,
        16 * pathPoints->m_capacityAndFlags);
    v9 = 16 * v3->m_points.m_size;
    v2->m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                 (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                 &v9);
    v2->m_capacityAndFlags = v9 / 16;
  }
  v4 = v3->m_points.m_size;
  v5 = v2->m_data;
  v2->m_size = v4;
  v6 = v4;
  if ( (signed int)v4 > 0 )
  {
    v7 = (char *)((char *)v3->m_points.m_data - (char *)v5);
    do
    {
      v8.m_quad = *(__m128 *)((char *)v5 + (_QWORD)v7);
      ++v5;
      v5[-1] = (hkVector4f)v8.m_quad;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 348
// RVA: 0xD4D180
void __fastcall hkpLinearParametricCurve::transformPoints(hkpLinearParametricCurve *this, hkTransformf *transformation)
{
  __int64 v2; // r8
  __int64 v3; // r9
  hkVector4f *v4; // rax
  __m128 v5; // xmm1

  v2 = this->m_points.m_size;
  if ( v2 > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = this->m_points.m_data;
      ++v3;
      v5 = v4[v3 - 1].m_quad;
      v4[v3 - 1].m_quad = _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v5, v5, 85), transformation->m_rotation.m_col1.m_quad),
                                _mm_mul_ps(
                                  _mm_shuffle_ps(v4[v3 - 1].m_quad, v5, 0),
                                  transformation->m_rotation.m_col0.m_quad)),
                              _mm_mul_ps(_mm_shuffle_ps(v5, v5, 170), transformation->m_rotation.m_col2.m_quad)),
                            transformation->m_translation.m_quad);
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 361
// RVA: 0xD4D1E0
hkpLinearParametricCurve *__fastcall hkpLinearParametricCurve::clone(hkpLinearParametricCurve *this)
{
  __m128 *v1; // rbp
  _QWORD **v2; // rax
  hkpLinearParametricCurve *v3; // rax
  signed __int64 v4; // r14
  hkpLinearParametricCurve *v5; // rax
  hkpLinearParametricCurve *v6; // rdi
  float v7; // eax
  __int64 v8; // rsi
  __int64 v9; // rbx
  signed __int64 v10; // rax
  float *v11; // r11
  unsigned __int64 v12; // r9
  signed __int64 v13; // rdx
  signed __int64 v14; // rcx
  unsigned __int64 v15; // r8
  unsigned __int64 v16; // r10
  int v17; // eax
  unsigned __int64 v18; // r9
  signed __int64 v19; // rcx
  signed __int64 v20; // rdx
  int v21; // eax
  int v23; // [rsp+40h] [rbp+8h]

  v1 = (__m128 *)this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpLinearParametricCurve *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 80i64);
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
  v7 = v1[3].m128_f32[2];
  if ( SLODWORD(v7) > 0 )
  {
    v8 = LODWORD(v7);
    v9 = 0i64;
    do
    {
      hkpLinearParametricCurve::addPoint(v6, (hkVector4f *)(v9 + v1[3].m128_u64[0]));
      v9 += 16i64;
      --v8;
    }
    while ( v8 );
  }
  v6->m_closedLoop.m_bool = v1[1].m128_i8[4];
  v6->m_dirNotParallelToTangentAlongWholePath.m_quad = _mm_shuffle_ps(v1[2], _mm_unpackhi_ps(v1[2], (__m128)0i64), 196);
  if ( (v6->m_distance.m_capacityAndFlags & 0x3FFFFFFF) < v1[4].m128_i32[2] )
  {
    if ( v6->m_distance.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v6->m_distance.m_data,
        4 * v6->m_distance.m_capacityAndFlags);
    v23 = 4 * v1[4].m128_i32[2];
    v6->m_distance.m_data = (float *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                       (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                       &v23);
    v6->m_distance.m_capacityAndFlags = v23 / 4;
  }
  v10 = v1[4].m128_i32[2];
  v11 = v6->m_distance.m_data;
  v6->m_distance.m_size = v10;
  v12 = v1[4].m128_u64[0];
  v13 = v10;
  if ( v10 >= 4 )
  {
    v14 = (signed __int64)(v11 + 1);
    v15 = v12 - (_QWORD)v11;
    v16 = ((unsigned __int64)(v10 - 4) >> 2) + 1;
    v4 = 4 * v16;
    do
    {
      v17 = *(_DWORD *)(v15 + v14 - 4);
      v14 += 16i64;
      *(_DWORD *)(v14 - 20) = v17;
      *(_DWORD *)(v14 - 16) = *(_DWORD *)(v15 + v14 - 16);
      *(_DWORD *)(v14 - 12) = *(_DWORD *)(v15 + v14 - 12);
      *(_DWORD *)(v14 - 8) = *(_DWORD *)(v15 + v14 - 8);
      --v16;
    }
    while ( v16 );
  }
  if ( v4 < v13 )
  {
    v18 = v12 - (_QWORD)v11;
    v19 = (signed __int64)&v11[v4];
    v20 = v13 - v4;
    do
    {
      v21 = *(_DWORD *)(v19 + v18);
      v19 += 4i64;
      *(_DWORD *)(v19 - 4) = v21;
      --v20;
    }
    while ( v20 );
  }
  v6->m_smoothingFactor = v1[1].m128_f32[0];
  return v6;
}


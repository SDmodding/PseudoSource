// File Line: 87
// RVA: 0xDB9C60
void __fastcall hkpGsk::print(hkpGsk *this)
{
  ;
}

// File Line: 96
// RVA: 0xDBB000
__int64 __fastcall findClosestTriangleBackup(hkVector4f *a0, hkVector4f *tetra, hkVector4f *oldDots, float sign)
{
  char *v4; // r9
  hkVector4f *v5; // r10
  __int64 v6; // r11
  __m128 m_quad; // xmm7
  __int64 v8; // rbx
  __m128 v9; // xmm0
  __m128 v10; // xmm1
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm6
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm5
  __m128 v18; // xmm6
  __m128 v19; // xmm4
  __m128 v20; // xmm5
  __m128 v21; // xmm0
  int v22; // eax

  v4 = hkpCollideTriangleUtil::vertexToEdgeLut;
  v5 = tetra;
  v6 = 3i64;
  do
  {
    m_quad = oldDots->m_quad;
    v8 = *v4;
    v9 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v4[2]], oldDots->m_quad);
    v10 = _mm_or_ps(_mm_shuffle_ps(v9, v9, 78), v9);
    if ( COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 177).m128_u32[0] | v10.m128_i32[0]) >= 0.0 )
    {
      v11 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v8], m_quad);
      v12 = _mm_or_ps(_mm_shuffle_ps(v11, v11, 78), v11);
      if ( COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 177).m128_u32[0] | v12.m128_i32[0]) >= 0.0 )
      {
        v13 = _mm_sub_ps(tetra[v4[2]].m_quad, v5->m_quad);
        v14 = _mm_sub_ps(tetra[3].m_quad, v5->m_quad);
        v15 = _mm_mul_ps(v14, v13);
        v16 = _mm_sub_ps(tetra[v8].m_quad, v5->m_quad);
        v17 = _mm_sub_ps(a0->m_quad, v5->m_quad);
        v18 = _mm_mul_ps(v14, v16);
        v19 = _mm_mul_ps(v17, v16);
        v20 = _mm_mul_ps(v17, v13);
        if ( (float)((float)((float)((float)(_mm_shuffle_ps(v20, v20, 85).m128_f32[0]
                                           + _mm_shuffle_ps(v20, v20, 0).m128_f32[0])
                                   + _mm_shuffle_ps(v20, v20, 170).m128_f32[0])
                           * (float)((float)(_mm_shuffle_ps(v18, v18, 85).m128_f32[0]
                                           + _mm_shuffle_ps(v18, v18, 0).m128_f32[0])
                                   + _mm_shuffle_ps(v18, v18, 170).m128_f32[0]))
                   - (float)((float)((float)(_mm_shuffle_ps(v15, v15, 85).m128_f32[0]
                                           + _mm_shuffle_ps(v15, v15, 0).m128_f32[0])
                                   + _mm_shuffle_ps(v15, v15, 170).m128_f32[0])
                           * (float)((float)(_mm_shuffle_ps(v19, v19, 85).m128_f32[0]
                                           + _mm_shuffle_ps(v19, v19, 0).m128_f32[0])
                                   + _mm_shuffle_ps(v19, v19, 170).m128_f32[0]))) >= 0.0 )
          v21 = (__m128)`hkVector4f::getComponent::`2::indexToMask[v4[2]];
        else
          v21 = (__m128)`hkVector4f::getComponent::`2::indexToMask[v8];
        oldDots->m_quad = _mm_or_ps(_mm_andnot_ps(v21, m_quad), _mm_and_ps(v21, g_vectorfConstants[0]));
      }
    }
    ++v4;
    ++v5;
    --v6;
  }
  while ( v6 );
  v22 = _mm_movemask_ps(_mm_cmplt_ps((__m128)0i64, oldDots->m_quad));
  if ( (v22 & 7) != 0 )
    return (unsigned __int8)hkVector4Comparison_maskToFirstIndex[v22];
  else
    return 0xFFFFFFFFi64;
}

// File Line: 143
// RVA: 0xDB9C40
void hkpGsk::codeBegin(void)
{
  ;
}

// File Line: 147
// RVA: 0xDBA470
__int64 __fastcall hkpGsk::checkTriangleBoundaries(
        hkpGsk *this,
        hkVector4f *a,
        hkVector4f *b,
        hkpGsk::SupportTypes checkSupport)
{
  __m128 m_quad; // xmm2
  __m128 v5; // xmm4
  __m128 v6; // xmm9
  __m128 v7; // xmm7
  __m128 v8; // xmm1
  __m128 v9; // xmm6
  __m128 v10; // xmm8
  __m128 v11; // xmm2
  __m128 v12; // xmm5
  __m128 v13; // xmm10
  __m128 v14; // xmm11
  hkVector4f v15; // xmm11
  __m128 v16; // xmm10
  __m128 v17; // xmm8
  __m128 v18; // xmm1
  __m128 v19; // xmm8
  __m128 v20; // xmm9
  __m128 v21; // xmm10
  __m128 v22; // xmm1
  __m128 v23; // xmm9
  __m128 v24; // xmm2
  hkVector4f v25; // xmm10
  __int64 result; // rax
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  hkVector4f v29; // xmm1
  int v30; // xmm0_4

  m_quad = b[1].m_quad;
  v5 = b[2].m_quad;
  v6 = _mm_sub_ps(m_quad, b->m_quad);
  v7 = _mm_sub_ps(b->m_quad, v5);
  v8 = _mm_sub_ps(a->m_quad, m_quad);
  v9 = _mm_sub_ps(v5, m_quad);
  v10 = _mm_shuffle_ps(v7, v7, 201);
  v11 = _mm_sub_ps(a->m_quad, v5);
  v12 = _mm_sub_ps(a->m_quad, b->m_quad);
  v13 = _mm_shuffle_ps(v9, v9, 201);
  v14 = _mm_sub_ps(_mm_mul_ps(v10, v9), _mm_mul_ps(v13, v7));
  v15.m_quad = _mm_shuffle_ps(v14, v14, 201);
  v16 = _mm_sub_ps(_mm_mul_ps(v13, v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v9));
  v17 = _mm_sub_ps(_mm_mul_ps(v10, v11), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v7));
  v18 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v15.m_quad);
  v19 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v15.m_quad);
  v20 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v12), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v6));
  v21 = _mm_unpackhi_ps(v18, v19);
  v22 = _mm_unpacklo_ps(v18, v19);
  v23 = _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v15.m_quad);
  v24 = _mm_movelh_ps(v22, v23);
  v25.m_quad = _mm_add_ps(
                 _mm_shuffle_ps(v21, v23, 228),
                 _mm_add_ps(v24, _mm_shuffle_ps(_mm_movehl_ps(v24, v22), v23, 212)));
  this->m_checkTriangleDots = (hkVector4f)v25.m_quad;
  result = _mm_movemask_ps(_mm_cmplt_ps(v25.m_quad, (__m128)0i64)) & 7;
  if ( checkSupport )
  {
    this->m_support = (hkVector4f)v15.m_quad;
    if ( (_DWORD)result == 7 )
    {
      v27 = _mm_mul_ps(_mm_sub_ps(this->m_verticesA[0].m_quad, this->m_verticesBinA[0].m_quad), v15.m_quad);
      if ( (float)((float)(_mm_shuffle_ps(v27, v27, 85).m128_f32[0] + _mm_shuffle_ps(v27, v27, 0).m128_f32[0])
                 + _mm_shuffle_ps(v27, v27, 170).m128_f32[0]) < 0.0 )
      {
        this->m_support.m_quad = _mm_xor_ps(
                                   (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                   v15.m_quad);
        v28 = b->m_quad;
        *b = (hkVector4f)b[1].m_quad;
        b[1] = (hkVector4f)v28;
        v29.m_quad = (__m128)b[4];
        b[4] = (hkVector4f)b[5].m_quad;
        b[5] = (hkVector4f)v29.m_quad;
        v30 = this->m_checkTriangleDots.m_quad.m128_i32[0];
        this->m_checkTriangleDots.m_quad.m128_i32[0] = this->m_checkTriangleDots.m_quad.m128_i32[1];
        this->m_checkTriangleDots.m_quad.m128_i32[1] = v30;
        this->m_featureChange.m_storage = 1;
      }
    }
  }
  return result;
}

// File Line: 207
// RVA: 0xDBB1E0
__int64 __fastcall findClosestTriangle(hkVector4f *a0, hkVector4f *tetra, float sign)
{
  __m128 m_quad; // xmm1
  __m128 v4; // xmm3
  __m128 v5; // xmm5
  __m128 v6; // xmm6
  __m128 v7; // xmm4
  __m128 v9; // xmm2
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  __m128 v12; // xmm9
  __m128 v13; // xmm9
  __m128 v14; // xmm4
  __m128 v15; // xmm8
  __m128 v16; // xmm8
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm8
  __m128 v20; // xmm5
  __m128 v21; // xmm5
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  __m128 v26; // xmm9
  __m128 v27; // xmm0
  __m128 v28; // xmm5
  __m128 v29; // xmm1
  __m128 v30; // xmm7
  __m128 v31; // xmm0
  __m128 v32; // xmm2
  __m128 v33; // xmm7
  __m128 v34; // xmm2
  __m128 v35; // xmm9
  __m128 v36; // xmm2
  __m128 v37; // xmm0
  __m128 v38; // xmm3
  __m128 v39; // xmm1
  __m128 v40; // xmm0
  __m128 v41; // xmm4
  __m128 v42; // xmm6
  __m128 v43; // xmm8
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm8
  __m128 v47; // xmm2
  __m128 v48; // xmm6
  float v49; // xmm2_4
  hkVector4f oldDots; // [rsp+20h] [rbp-68h] BYREF

  m_quad = tetra[1].m_quad;
  v4 = tetra[2].m_quad;
  v5 = _mm_sub_ps(tetra->m_quad, v4);
  v6 = _mm_sub_ps(m_quad, tetra->m_quad);
  v7 = _mm_sub_ps(v4, m_quad);
  v9 = _mm_sub_ps(tetra[3].m_quad, tetra->m_quad);
  v10 = _mm_sub_ps(tetra[3].m_quad, m_quad);
  v11 = _mm_sub_ps(tetra[3].m_quad, v4);
  v12 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v7), _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v10));
  v13 = _mm_shuffle_ps(v12, v12, 201);
  v14 = _mm_mul_ps(
          _mm_shuffle_ps((__m128)LODWORD(sign), (__m128)LODWORD(sign), 0),
          _mm_sub_ps(a0->m_quad, tetra[3].m_quad));
  v15 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v5), _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v11));
  v16 = _mm_shuffle_ps(v15, v15, 201);
  v17 = _mm_unpackhi_ps(v13, v16);
  v18 = _mm_unpacklo_ps(v13, v16);
  v19 = _mm_mul_ps(v16, v16);
  v20 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v6), _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v9));
  v21 = _mm_shuffle_ps(v20, v20, 201);
  v22 = _mm_shuffle_ps(v17, v21, 228);
  v23 = _mm_movelh_ps(v18, v21);
  v24 = _mm_movehl_ps(v23, v18);
  v25 = _mm_mul_ps(v13, v13);
  v26 = _mm_unpackhi_ps(v25, v19);
  v27 = _mm_shuffle_ps(v24, v21, 212);
  v28 = _mm_mul_ps(v21, v21);
  v29 = _mm_unpacklo_ps(v25, v19);
  v30 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v27);
  v31 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v23);
  v32 = _mm_movelh_ps(v29, v28);
  v33 = _mm_add_ps(_mm_add_ps(v30, v31), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v22));
  v34 = _mm_add_ps(_mm_shuffle_ps(v26, v28, 228), _mm_add_ps(v32, _mm_shuffle_ps(_mm_movehl_ps(v32, v29), v28, 212)));
  v35 = _mm_max_ps(v34, *(__m128 *)&epsilon);
  v36 = _mm_cmpeq_ps(v34, (__m128)0i64);
  v37 = _mm_rcp_ps(v35);
  v38 = _mm_or_ps(
          _mm_and_ps(v36, (__m128)xmmword_141A712A0),
          _mm_andnot_ps(
            v36,
            _mm_mul_ps(
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v35, v37)), v37),
              _mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v33, 1u), 1u), v33))));
  v39 = _mm_shuffle_ps(v38, v38, 0);
  v40 = _mm_shuffle_ps(v38, v38, 85);
  v41 = _mm_shuffle_ps(v38, v38, 170);
  v42 = _mm_min_ps(v41, _mm_min_ps(v40, v39));
  v43 = _mm_max_ps(v41, _mm_max_ps(v40, v39));
  v44 = _mm_unpacklo_ps(v43, v43);
  v45 = _mm_cmple_ps(v43, v38);
  v46 = _mm_and_ps(v45, (__m128)xmmword_141A9E180);
  v47 = _mm_or_ps(_mm_andnot_ps(v45, v38), _mm_and_ps(v45, v42));
  v48 = _mm_movelh_ps(
          _mm_unpacklo_ps(
            v42,
            _mm_max_ps(
              _mm_shuffle_ps(v47, v47, 170),
              _mm_max_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)))),
          v44);
  v49 = _mm_shuffle_ps(v48, v48, 170).m128_f32[0];
  if ( v49 < 0.00000011920929 )
    return 0xFFFFFFFFi64;
  if ( v49 > (float)(_mm_shuffle_ps(v48, v48, 85).m128_f32[0]
                   * _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_1), (__m128)LODWORD(FLOAT_1_1), 0).m128_f32[0]) )
    return (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(v46)];
  oldDots.m_quad = v33;
  return findClosestTriangleBackup(a0, tetra, &oldDots, sign);
}

// File Line: 319
// RVA: 0xDBB470
void __fastcall process_point_edge(
        hkVector4f *vertexA,
        hkVector4f *vertexB,
        hkPadSpu<int> *dimB,
        hkVector4f *support,
        hkpGsk::SupportTypes stype)
{
  __m128 m_quad; // xmm7
  __m128 v6; // xmm9
  __m128 v7; // xmm5
  __m128 v8; // xmm8
  __m128 v9; // xmm6
  __m128 v10; // xmm2
  __m128 v11; // xmm4
  float v12; // xmm1_4
  __m128 v13; // xmm2
  __m128 v14; // xmm5
  __m128 v15; // xmm6
  __m128 v16; // xmm6
  __m128 v17; // xmm0
  __m128 v18; // xmm5
  __m128 v19; // xmm0
  hkVector4f v20; // xmm0
  __m128 v21; // xmm5
  hkVector4f v22; // xmm0

  m_quad = vertexA->m_quad;
  v6 = vertexB[1].m_quad;
  v7 = _mm_sub_ps(v6, vertexB->m_quad);
  v8 = _mm_sub_ps(v6, vertexA->m_quad);
  v9 = _mm_sub_ps(vertexB->m_quad, vertexA->m_quad);
  v10 = _mm_mul_ps(v7, v8);
  v11 = _mm_mul_ps(v7, v9);
  v12 = (float)(_mm_shuffle_ps(v10, v10, 85).m128_f32[0] + _mm_shuffle_ps(v10, v10, 0).m128_f32[0])
      + _mm_shuffle_ps(v10, v10, 170).m128_f32[0];
  if ( v12 < 0.0 == (float)((float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0] + _mm_shuffle_ps(v11, v11, 0).m128_f32[0])
                          + _mm_shuffle_ps(v11, v11, 170).m128_f32[0]) < 0.0 )
  {
    if ( v12 < 0.0 )
    {
      v22.m_quad = (__m128)vertexB[5];
      *vertexB = (hkVector4f)v6;
      vertexB[4] = (hkVector4f)v22.m_quad;
    }
    --dimB->m_storage;
    if ( stype == BUILD_POS_SUPPORT )
    {
      support->m_quad = _mm_sub_ps(m_quad, vertexB->m_quad);
      return;
    }
    v20.m_quad = _mm_sub_ps(vertexB->m_quad, m_quad);
  }
  else
  {
    v13 = _mm_mul_ps(v7, v7);
    v14 = _mm_mul_ps(
            v7,
            _mm_rsqrt_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                _mm_shuffle_ps(v13, v13, 170))));
    v15 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v9));
    v16 = _mm_shuffle_ps(v15, v15, 201);
    v17 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v14);
    v18 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v16);
    if ( stype != BUILD_POS_SUPPORT )
    {
      v21 = _mm_sub_ps(v18, v17);
      support->m_quad = _mm_shuffle_ps(v21, v21, 201);
      return;
    }
    v19 = _mm_sub_ps(v17, v18);
    v20.m_quad = _mm_shuffle_ps(v19, v19, 201);
  }
  *support = (hkVector4f)v20.m_quad;
}

// File Line: 362
// RVA: 0xDBA670
__int64 __fastcall hkpGsk::processEdgeTriangle(
        hkpGsk *this,
        hkVector4f *vertexA,
        hkVector4f *vertexB,
        hkPadSpu<int> *dimA,
        hkPadSpu<int> *dimB,
        hkBool comingFromEdgeEdge,
        hkpGsk::SupportTypes supportType)
{
  __m128 v11; // xmm2
  __m128 v12; // xmm6
  __m128 v13; // xmm5
  __m128 v14; // xmm3
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __int64 result; // rax
  __m128 v23; // xmm0
  hkVector4f v24; // xmm1
  _BOOL8 v25; // rcx
  hkVector4f v26; // xmm3
  __m128 m_quad; // xmm4
  hkVector4f v28; // xmm6
  __m128 v29; // xmm1
  __m128 v30; // xmm7
  __m128 v31; // xmm1
  __m128 v32; // xmm5
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  int v35; // eax
  hkVector4f v36; // xmm0
  hkVector4f v37; // xmm0
  float v38; // xmm2_4
  float v39; // xmm6_4
  float v40; // xmm2_4
  float v41; // xmm6_4
  hkVector4f v42; // xmm1
  float v43; // xmm2_4
  float v44; // xmm6_4
  hkVector4f v45; // xmm1
  hkVector4f a; // [rsp+30h] [rbp-108h] BYREF
  hkVector4f v47; // [rsp+40h] [rbp-F8h] BYREF
  hkVector4f dB; // [rsp+50h] [rbp-E8h] BYREF
  hkLineSegmentUtil::ClosestLineSegLineSegResult v49; // [rsp+60h] [rbp-D8h] BYREF
  hkLineSegmentUtil::ClosestLineSegLineSegResult v50; // [rsp+B0h] [rbp-88h] BYREF

  if ( !comingFromEdgeEdge.m_bool )
  {
    v26.m_quad = (__m128)this->m_support;
    m_quad = vertexA[1].m_quad;
    v28.m_quad = (__m128)this->m_checkTriangleDots;
    v29 = _mm_mul_ps(_mm_sub_ps(m_quad, vertexB->m_quad), v26.m_quad);
    v30 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
            _mm_shuffle_ps(v29, v29, 170));
    v31 = _mm_mul_ps(_mm_sub_ps(vertexA->m_quad, vertexB->m_quad), v26.m_quad);
    v32 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
            _mm_shuffle_ps(v31, v31, 170));
    if ( (float)(v32.m128_f32[0] * v30.m128_f32[0]) < 0.0 )
    {
      v33 = _mm_sub_ps(v32, v30);
      v34 = _mm_rcp_ps(v33);
      v47.m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(m_quad, vertexA->m_quad),
                       _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v34, v33)), v34), v32)),
                     vertexA->m_quad);
      if ( (unsigned int)hkpGsk::checkTriangleBoundaries(this, &v47, vertexB, BUILD_NO_SUPPORT) == 7 )
        return 1i64;
    }
    v35 = hkpGsk::checkTriangleBoundaries(this, vertexA + 1, vertexB, BUILD_NO_SUPPORT);
    if ( v35 == 7 )
    {
      v36.m_quad = (__m128)vertexA[1];
      --dimA->m_storage;
      *vertexA = (hkVector4f)v36.m_quad;
      v37.m_quad = (__m128)vertexA[5];
      this->m_supportState = supportType;
      result = 0i64;
      vertexA[4] = (hkVector4f)v37.m_quad;
      return result;
    }
    if ( v35 != 6 )
    {
      switch ( v35 )
      {
        case 5:
$remove_b1:
          v45.m_quad = (__m128)vertexB[6];
          vertexB[1] = (hkVector4f)vertexB[2].m_quad;
          vertexB[5] = (hkVector4f)v45.m_quad;
          goto $remove_b2;
        case 3:
$remove_b2:
          --dimB->m_storage;
          return 2i64;
        case 1:
          v38 = _mm_shuffle_ps(v28.m_quad, v28.m_quad, 85).m128_f32[0];
          v39 = _mm_shuffle_ps(v28.m_quad, v28.m_quad, 170).m128_f32[0];
          if ( (float)((float)(_mm_shuffle_ps(this->m_checkTriangleDots.m_quad, this->m_checkTriangleDots.m_quad, 85).m128_f32[0]
                             - v38)
                     * v39) <= (float)((float)(_mm_shuffle_ps(
                                                 this->m_checkTriangleDots.m_quad,
                                                 this->m_checkTriangleDots.m_quad,
                                                 170).m128_f32[0]
                                             - v39)
                                     * v38) )
            goto $remove_b1;
          goto $remove_b2;
        case 2:
          v40 = _mm_shuffle_ps(v28.m_quad, v28.m_quad, 170).m128_f32[0];
          v41 = _mm_shuffle_ps(v28.m_quad, v28.m_quad, 0).m128_f32[0];
          if ( (float)((float)(_mm_shuffle_ps(this->m_checkTriangleDots.m_quad, this->m_checkTriangleDots.m_quad, 170).m128_f32[0]
                             - v40)
                     * v41) <= (float)((float)(_mm_shuffle_ps(
                                                 this->m_checkTriangleDots.m_quad,
                                                 this->m_checkTriangleDots.m_quad,
                                                 0).m128_f32[0]
                                             - v41)
                                     * v40) )
            goto $remove_b2;
          break;
        case 4:
          v43 = _mm_shuffle_ps(v28.m_quad, v28.m_quad, 0).m128_f32[0];
          v44 = _mm_shuffle_ps(v28.m_quad, v28.m_quad, 85).m128_f32[0];
          if ( (float)((float)(_mm_shuffle_ps(this->m_checkTriangleDots.m_quad, this->m_checkTriangleDots.m_quad, 0).m128_f32[0]
                             - v43)
                     * v44) > (float)((float)(_mm_shuffle_ps(
                                                this->m_checkTriangleDots.m_quad,
                                                this->m_checkTriangleDots.m_quad,
                                                85).m128_f32[0]
                                            - v44)
                                    * v43) )
            goto $remove_b1;
          break;
      }
    }
    v42.m_quad = (__m128)vertexB[6];
    *vertexB = (hkVector4f)vertexB[2].m_quad;
    vertexB[4] = (hkVector4f)v42.m_quad;
    goto $remove_b2;
  }
  v11 = vertexB->m_quad;
  v12 = vertexA->m_quad;
  v13 = vertexA[1].m_quad;
  dB.m_quad = _mm_sub_ps(vertexB[1].m_quad, vertexB[2].m_quad);
  v47.m_quad = _mm_sub_ps(v11, vertexB[2].m_quad);
  v14 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v47.m_quad, v47.m_quad, 201), dB.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(dB.m_quad, dB.m_quad, 201), v47.m_quad));
  v15 = _mm_shuffle_ps(v14, v14, 201);
  v16 = _mm_mul_ps(_mm_sub_ps(v12, v11), v15);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_mul_ps(_mm_sub_ps(v13, v11), v15);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  if ( v17.m128_f32[0] < 0.0 == v19.m128_f32[0] < 0.0 )
  {
    if ( COERCE_FLOAT((unsigned int)(2 * v17.m128_i32[0]) >> 1) > COERCE_FLOAT((unsigned int)(2 * v19.m128_i32[0]) >> 1) )
    {
      v23 = vertexA->m_quad;
      *vertexA = (hkVector4f)v13;
      vertexA[1] = (hkVector4f)v23;
      v24.m_quad = (__m128)vertexA[4];
      vertexA[4] = (hkVector4f)vertexA[5].m_quad;
      vertexA[5] = (hkVector4f)v24.m_quad;
    }
    if ( (unsigned int)hkpGsk::checkTriangleBoundaries(this, vertexA, vertexB, BUILD_POS_SUPPORT) == 7 )
    {
      --dimA->m_storage;
      return 0i64;
    }
  }
  else
  {
    v20 = _mm_sub_ps(v17, v19);
    v21 = _mm_rcp_ps(v20);
    a.m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(v13, v12),
                   _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v21, v20)), v21), v17)),
                 v12);
    if ( (unsigned int)hkpGsk::checkTriangleBoundaries(this, &a, vertexB, BUILD_NO_SUPPORT) == 7 )
      return 1i64;
  }
  a.m_quad = _mm_sub_ps(vertexA[1].m_quad, vertexA->m_quad);
  hkLineSegmentUtil::closestLineSegLineSeg(vertexA, &a, vertexB + 2, &dB, &v49);
  hkLineSegmentUtil::closestLineSegLineSeg(vertexA, &a, vertexB + 2, &v47, &v50);
  v25 = v49.m_distanceSquared.m_storage > v50.m_distanceSquared.m_storage;
  vertexB[v25] = (hkVector4f)vertexB[2].m_quad;
  vertexB[v25 + 4] = (hkVector4f)vertexB[6].m_quad;
  --dimB->m_storage;
  return 2i64;
}xB[v25 + 4] = (hkVector4f)vertexB[6].m_quad;
  --dimB->m_storage;
  return 2i64;
}

// File Line: 797
// RVA: 0xDBB5B0
hkSimdFloat32 *__fastcall hkGskCalcSupportDistSquared(
        hkSimdFloat32 *result,
        hkVector4f *support,
        hkVector4f *newPoint,
        hkVector4f *oldPoint)
{
  hkSimdFloat32 *v4; // rax
  __m128 v5; // xmm1
  __m128i v6; // xmm2

  v4 = result;
  v5 = _mm_mul_ps(_mm_sub_ps(newPoint->m_quad, oldPoint->m_quad), support->m_quad);
  v6 = (__m128i)_mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)),
                  _mm_shuffle_ps(v5, v5, 170));
  result->m_real = _mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v6, 1u), 1u), (__m128)v6);
  return v4;
}

// File Line: 808
// RVA: 0xDB8BF0
__int64 __fastcall hkpGsk::getClosestFeature(
        hkpGsk *this,
        hkpConvexShape *shapeA,
        hkpConvexShape *shapeB,
        hkTransformf *aTb,
        hkVector4f *separatingNormalOut)
{
  hkVector4f v5; // xmm3
  hkVector4f v6; // xmm4
  hkVector4f v7; // xmm5
  hkPadSpu<int> *dimB; // rdi
  hkVector4f v12; // xmm6
  __int64 v13; // rcx
  hkcdVertex *v14; // rax
  __m128 m_quad; // xmm1
  char v16; // r12
  hkVector4f *m_verticesBinA; // rbp
  __m128 v18; // xmm7
  int v19; // r14d
  int v20; // eax
  unsigned int v21; // eax
  hkpGsk::NextCase v22; // eax
  __int32 v23; // eax
  __m128 v24; // xmm1
  int v25; // eax
  hkcdVertex v26; // xmm1
  int ClosestTriangle; // eax
  int v28; // eax
  __int64 v29; // rcx
  __int64 v30; // r9
  __int64 v31; // rcx
  __m128 v32; // xmm0
  __m128 v33; // xmm2
  __m128 v34; // xmm4
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  __m128 v37; // xmm3
  hkVector4f v38; // xmm0
  __m128 v39; // xmm3
  int v40; // eax
  __int64 v41; // rax
  __int64 v42; // rcx
  hkcdVertex v43; // xmm0
  int v44; // eax
  int v45; // eax
  __int64 v46; // rcx
  __int64 v47; // r8
  __int64 v48; // rdx
  __m128 v49; // xmm0
  __int64 v50; // rax
  __m128 v51; // xmm2
  __m128 v52; // xmm4
  __m128 v53; // xmm3
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm3
  int v57; // eax
  int v58; // eax
  int v59; // edx
  __m128 v60; // xmm3
  hkVector4f v61; // xmm3
  __m128 v62; // xmm1
  __m128 v63; // xmm1
  int v64; // ecx
  __m128 v65; // xmm9
  __m128 v66; // xmm6
  __m128 v67; // xmm5
  __m128 v68; // xmm8
  __m128 v69; // xmm2
  __m128 v70; // xmm4
  float v71; // xmm1_4
  __m128 v72; // xmm2
  __m128 v73; // xmm5
  __m128 v74; // xmm1
  __m128 v75; // xmm1
  __m128 v76; // xmm0
  hkVector4f v77; // xmm0
  int v78; // ecx
  __m128 v79; // xmm9
  __m128 v80; // xmm8
  __m128 v81; // xmm6
  __m128 v82; // xmm5
  __m128 v83; // xmm8
  __m128 v84; // xmm2
  __m128 v85; // xmm4
  float v86; // xmm1_4
  __m128 v87; // xmm2
  __m128 v88; // xmm5
  __m128 v89; // xmm1
  __m128 v90; // xmm1
  __m128 v91; // xmm5
  hkcdVertex v92; // xmm0
  hkVector4f v93; // xmm0
  hkVector4f v94; // xmm1
  __int64 m_storage; // rcx
  __m128 v96; // xmm4
  __m128 v97; // xmm1
  float v98; // xmm2_4
  __m128 v99; // xmm1
  float v100; // xmm3_4
  float v101; // xmm6_4
  hkBaseObjectVtbl *vfptr; // rax
  __int64 v103; // rdx
  __m128 v104; // xmm3
  __m128 v105; // xmm1
  float v106; // xmm2_4
  __m128 v107; // xmm1
  float v108; // xmm2_4
  __m128 v109; // xmm3
  float v110; // xmm1_4
  __int64 v111; // rcx
  hkVector4f v112; // xmm4
  hkBaseObjectVtbl *v113; // rax
  __m128 v114; // xmm1
  __m128 v115; // xmm2
  __m128 v116; // xmm0
  hkVector4f v117; // xmm1
  __int64 v118; // rcx
  __int64 v119; // rdx
  __m128 v120; // xmm3
  __m128 v121; // xmm1
  int v122; // ecx
  __m128 v123; // xmm1
  float v124; // xmm2_4
  __m128 v125; // xmm3
  float v126; // xmm1_4
  __m128 v127; // xmm1
  __int64 v128; // rcx
  hkBaseObjectVtbl *v129; // rax
  __m128 v130; // xmm3
  __m128 v131; // xmm1
  float v132; // xmm2_4
  __m128 v133; // xmm1
  float v134; // xmm2_4
  __m128 v135; // xmm3
  float v136; // xmm1_4
  hkVector4f v137; // xmm5
  __m128 v138; // xmm1
  __m128 v139; // xmm3
  __m128 v140; // xmm2
  hkVector4f v141; // xmm4
  __m128 v142; // xmm6
  hkVector4f v143; // xmm2
  hkVector4f dB; // [rsp+40h] [rbp-E8h] BYREF
  hkVector4f dA; // [rsp+50h] [rbp-D8h] BYREF
  __m128 v147; // [rsp+60h] [rbp-C8h] BYREF
  __m128 v148; // [rsp+70h] [rbp-B8h] BYREF
  __m128 v149[3]; // [rsp+80h] [rbp-A8h] BYREF

  v5.m_quad = (__m128)aTb->m_rotation.m_col0;
  v6.m_quad = (__m128)aTb->m_rotation.m_col1;
  v7.m_quad = (__m128)aTb->m_rotation.m_col2;
  dimB = &this->m_dimB;
  v12.m_quad = (__m128)aTb->m_translation;
  v13 = this->m_dimB.m_storage - 1;
  v14 = &this->m_verticesBinB[v13];
  do
  {
    m_quad = v14->m_quad;
    --v14;
    --v13;
    v14[-3].m_quad = _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v6.m_quad),
                           _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v5.m_quad)),
                         _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v7.m_quad)),
                       v12.m_quad);
  }
  while ( v13 >= 0 );
  v16 = 0;
  m_verticesBinA = this->m_verticesBinA;
  v18 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_192093eN10), (__m128)LODWORD(FLOAT_1_192093eN10), 0);
LABEL_4:
  ++v16;
  v18 = _mm_add_ps(v18, v18);
  v19 = this->m_dimA.m_storage + dimB->m_storage;
  v20 = dimB->m_storage | (8 * this->m_dimA.m_storage);
  this->m_supportState = SUPPORT_CHANGED;
  v21 = v20 - 9;
  while ( 2 )
  {
    switch ( v21 )
    {
      case 0u:
        goto $LN860_0;
      case 1u:
        goto LABEL_46;
      case 2u:
        goto LABEL_21;
      case 3u:
        ClosestTriangle = findClosestTriangle(&this->m_verticesA[0], this->m_verticesBinA, 1.0);
        if ( ClosestTriangle < 0 )
          goto LABEL_62;
        --dimB->m_storage;
        this->m_verticesBinA[ClosestTriangle] = this->m_verticesBinA[3];
        this->m_verticesBinB[ClosestTriangle] = this->m_verticesBinB[3];
LABEL_21:
        v28 = hkpGsk::checkTriangleBoundaries(this, &this->m_verticesA[0], this->m_verticesBinA, BUILD_POS_SUPPORT);
        if ( v28 == 7 )
          goto LABEL_61;
        v29 = hkpCollideTriangleUtil::maskToIndex[v28];
        if ( (int)v29 >= 0 )
        {
          v30 = hkpCollideTriangleUtil::vertexToEdgeLut[v29];
          v31 = hkpCollideTriangleUtil::vertexToEdgeLut[v29 + 2];
          v32 = this->m_verticesBinA[hkpCollideTriangleUtil::maskToIndex[v28]].m_quad;
          v33 = _mm_sub_ps(this->m_verticesBinA[v30].m_quad, v32);
          v34 = _mm_sub_ps(this->m_verticesA[0].m_quad, v32);
          v35 = this->m_verticesBinA[v31].m_quad;
          dimB->m_storage = 2;
          v36 = _mm_mul_ps(v33, v34);
          v37 = _mm_sub_ps(v35, v32);
          v38.m_quad = (__m128)this->m_verticesBinA[2];
          if ( (float)((float)(_mm_shuffle_ps(v36, v36, 85).m128_f32[0] + _mm_shuffle_ps(v36, v36, 0).m128_f32[0])
                     + _mm_shuffle_ps(v36, v36, 170).m128_f32[0]) >= 0.0 )
          {
            this->m_verticesBinA[v31] = (hkVector4f)v38.m_quad;
            v43.m_quad = (__m128)this->m_verticesBinB[2];
            v41 = v31 + 14;
          }
          else
          {
            v39 = _mm_mul_ps(v37, v34);
            this->m_verticesBinA[v30] = (hkVector4f)v38.m_quad;
            this->m_verticesBinB[v30] = this->m_verticesBinB[2];
            if ( (float)((float)(_mm_shuffle_ps(v39, v39, 85).m128_f32[0] + _mm_shuffle_ps(v39, v39, 0).m128_f32[0])
                       + _mm_shuffle_ps(v39, v39, 170).m128_f32[0]) >= 0.0 )
              goto LABEL_41;
            if ( (_DWORD)v31 == dimB->m_storage )
              LODWORD(v31) = v30;
            v40 = dimB->m_storage - 1;
            dimB->m_storage = v40;
            this->m_verticesBinA[(int)v31] = this->m_verticesBinA[v40];
            v41 = (int)v31 + 14i64;
            v42 = dimB->m_storage + 14i64;
LABEL_38:
            v43.m_quad = (__m128)*((_OWORD *)&this->m_dimA.m_storage + v42);
          }
          v50 = 2 * v41;
LABEL_40:
          *(hkcdVertex *)(&this->m_dimA.m_storage + 2 * v50) = (hkcdVertex)v43.m_quad;
LABEL_41:
          v21 = (dimB->m_storage | (8 * this->m_dimA.m_storage)) - 9;
          if ( v21 > 0x18 )
          {
LABEL_62:
            v59 = 1;
            goto LABEL_63;
          }
          continue;
        }
        v64 = v29 + 8;
        if ( v64 == 7 )
          goto LABEL_55;
        --dimB->m_storage;
        this->m_verticesBinA[v64] = this->m_verticesBinA[2];
        this->m_verticesBinB[v64] = this->m_verticesBinB[2];
LABEL_46:
        v65 = this->m_verticesBinA[1].m_quad;
        v66 = _mm_sub_ps(v65, this->m_verticesA[0].m_quad);
        v67 = _mm_sub_ps(v65, this->m_verticesBinA[0].m_quad);
        v68 = _mm_sub_ps(m_verticesBinA->m_quad, this->m_verticesA[0].m_quad);
        v69 = _mm_mul_ps(v66, v67);
        v70 = _mm_mul_ps(v68, v67);
        v71 = (float)(_mm_shuffle_ps(v69, v69, 85).m128_f32[0] + _mm_shuffle_ps(v69, v69, 0).m128_f32[0])
            + _mm_shuffle_ps(v69, v69, 170).m128_f32[0];
        if ( v71 < 0.0 == (float)((float)(_mm_shuffle_ps(v70, v70, 85).m128_f32[0]
                                        + _mm_shuffle_ps(v70, v70, 0).m128_f32[0])
                                + _mm_shuffle_ps(v70, v70, 170).m128_f32[0]) < 0.0 )
        {
          if ( v71 < 0.0 )
          {
            v92.m_quad = (__m128)this->m_verticesBinB[1];
            *m_verticesBinA = (hkVector4f)v65;
            this->m_verticesBinB[0] = (hkcdVertex)v92.m_quad;
          }
          --dimB->m_storage;
          goto $LN860_0;
        }
        v72 = _mm_mul_ps(v67, v67);
        v73 = _mm_mul_ps(
                v67,
                _mm_rsqrt_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v72, v72, 85), _mm_shuffle_ps(v72, v72, 0)),
                    _mm_shuffle_ps(v72, v72, 170))));
        v74 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v68, v68, 201), v66), _mm_mul_ps(_mm_shuffle_ps(v66, v66, 201), v68));
        v75 = _mm_shuffle_ps(v74, v74, 201);
        v76 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v75, v75, 201), v73), _mm_mul_ps(_mm_shuffle_ps(v73, v73, 201), v75));
        v77.m_quad = _mm_shuffle_ps(v76, v76, 201);
LABEL_60:
        this->m_support = (hkVector4f)v77.m_quad;
LABEL_61:
        v59 = 0;
        this->m_lastDimB = (hkPadSpu<int>)dimB->m_storage;
LABEL_63:
        v94.m_quad = (__m128)this->m_support;
        m_storage = this->m_dimA.m_storage;
        v96 = v94.m_quad;
        this->m_featureChange.m_storage |= dimB->m_storage + this->m_dimA.m_storage - v19;
        v97 = _mm_mul_ps(v94.m_quad, v94.m_quad);
        v98 = (float)(_mm_shuffle_ps(v97, v97, 85).m128_f32[0] + _mm_shuffle_ps(v97, v97, 0).m128_f32[0])
            + _mm_shuffle_ps(v97, v97, 170).m128_f32[0];
        v99 = _mm_mul_ps(_mm_sub_ps(this->m_verticesA[0].m_quad, m_verticesBinA->m_quad), v96);
        v100 = (float)(_mm_shuffle_ps(v99, v99, 85).m128_f32[0] + _mm_shuffle_ps(v99, v99, 0).m128_f32[0])
             + _mm_shuffle_ps(v99, v99, 170).m128_f32[0];
        if ( v59
          || (v101 = v18.m128_f32[0] * v98,
              (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v100)) >> 1) * v100) <= (float)(v18.m128_f32[0] * v98))
          || v98 < v18.m128_f32[0] )
        {
          if ( !this->m_doNotHandlePenetration.m_storage )
          {
            hkpGsk::handlePenetration(this, shapeA, shapeB, aTb);
            goto LABEL_94;
          }
          if ( this->m_dimA.m_storage + dimB->m_storage > 4 )
          {
            if ( this->m_dimA.m_storage <= dimB->m_storage )
            {
              this->m_dimA.m_storage = 1;
              dimB->m_storage = 3;
            }
            else
            {
              this->m_dimA.m_storage = 3;
              dimB->m_storage = 1;
            }
          }
          return 4i64;
        }
        else
        {
          if ( (v16 & 1) == 0 )
            goto LABEL_75;
          if ( (_DWORD)m_storage == this->m_maxDimA.m_storage )
            goto LABEL_75;
          if ( this->m_supportState == DONT_CALL_GET_SUPPORTING_VERTEX_A )
            goto LABEL_75;
          vfptr = shapeA->vfptr;
          v147 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v96);
          ((void (__fastcall *)(hkpConvexShape *, __m128 *, hkcdVertex *))vfptr[4].__vecDelDtor)(
            shapeA,
            &v147,
            &this->m_verticesA[m_storage]);
          v103 = this->m_dimA.m_storage;
          v104 = this->m_verticesA[v103].m_quad;
          v105 = _mm_mul_ps(_mm_sub_ps(v104, this->m_verticesA[0].m_quad), v147);
          v106 = (float)(_mm_shuffle_ps(v105, v105, 85).m128_f32[0] + _mm_shuffle_ps(v105, v105, 0).m128_f32[0])
               + _mm_shuffle_ps(v105, v105, 170).m128_f32[0];
          if ( (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v106)) >> 1) * v106) <= v101 )
            goto LABEL_75;
          if ( (_DWORD)v103 == 2 )
            goto LABEL_73;
          if ( (_DWORD)v103 != 3 )
            goto LABEL_74;
          v107 = _mm_mul_ps(_mm_sub_ps(v104, this->m_verticesA[2].m_quad), v147);
          v108 = (float)(_mm_shuffle_ps(v107, v107, 85).m128_f32[0] + _mm_shuffle_ps(v107, v107, 0).m128_f32[0])
               + _mm_shuffle_ps(v107, v107, 170).m128_f32[0];
          if ( (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v108)) >> 1) * v108) >= v101 )
          {
LABEL_73:
            v109 = _mm_mul_ps(_mm_sub_ps(v104, this->m_verticesA[1].m_quad), v147);
            v110 = (float)(_mm_shuffle_ps(v109, v109, 85).m128_f32[0] + _mm_shuffle_ps(v109, v109, 0).m128_f32[0])
                 + _mm_shuffle_ps(v109, v109, 170).m128_f32[0];
            if ( (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v110)) >> 1) * v110) >= v101 )
              goto LABEL_74;
          }
LABEL_75:
          v111 = dimB->m_storage;
          if ( (_DWORD)v111 == this->m_maxDimB.m_storage )
            goto LABEL_83;
          if ( this->m_supportState == DONT_CALL_GET_SUPPORTING_VERTEX_B )
            goto LABEL_83;
          v112.m_quad = (__m128)aTb->m_rotation.m_col2;
          v113 = shapeB->vfptr;
          v114 = _mm_unpacklo_ps(aTb->m_rotation.m_col0.m_quad, aTb->m_rotation.m_col1.m_quad);
          v115 = _mm_movelh_ps(v114, v112.m_quad);
          v116 = _mm_movehl_ps(v115, v114);
          v117.m_quad = (__m128)this->m_support;
          v148 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v117.m_quad, v117.m_quad, 85), _mm_shuffle_ps(v116, v112.m_quad, 212)),
                     _mm_mul_ps(_mm_shuffle_ps(v117.m_quad, v117.m_quad, 0), v115)),
                   _mm_mul_ps(
                     _mm_shuffle_ps(
                       _mm_unpackhi_ps(aTb->m_rotation.m_col0.m_quad, aTb->m_rotation.m_col1.m_quad),
                       v112.m_quad,
                       228),
                     _mm_shuffle_ps(v117.m_quad, v117.m_quad, 170)));
          ((void (__fastcall *)(hkpConvexShape *, __m128 *, hkcdVertex *))v113[4].__vecDelDtor)(
            shapeB,
            &v148,
            &this->m_verticesBinB[v111]);
          v118 = dimB->m_storage;
          v119 = 2 * (v118 + 14);
          v120 = this->m_verticesBinB[v118].m_quad;
          v121 = _mm_mul_ps(_mm_sub_ps(v120, this->m_verticesBinB[0].m_quad), v148);
          v115.m128_f32[0] = (float)(_mm_shuffle_ps(v121, v121, 85).m128_f32[0]
                                   + _mm_shuffle_ps(v121, v121, 0).m128_f32[0])
                           + _mm_shuffle_ps(v121, v121, 170).m128_f32[0];
          if ( (float)(COERCE_FLOAT((unsigned int)(2 * v115.m128_i32[0]) >> 1) * v115.m128_f32[0]) <= v101 )
            goto LABEL_83;
          v122 = v118 - 2;
          if ( !v122 )
            goto LABEL_81;
          if ( v122 != 1 )
          {
LABEL_82:
            v127 = *(__m128 *)(&this->m_dimA.m_storage + 2 * v119);
            this->m_verticesBinA[dimB->m_storage++].m_quad = _mm_add_ps(
                                                               _mm_add_ps(
                                                                 _mm_add_ps(
                                                                   _mm_mul_ps(
                                                                     _mm_shuffle_ps(v127, v127, 0),
                                                                     aTb->m_rotation.m_col0.m_quad),
                                                                   _mm_mul_ps(
                                                                     _mm_shuffle_ps(v127, v127, 85),
                                                                     aTb->m_rotation.m_col1.m_quad)),
                                                                 _mm_mul_ps(
                                                                   _mm_shuffle_ps(v127, v127, 170),
                                                                   aTb->m_rotation.m_col2.m_quad)),
                                                               aTb->m_translation.m_quad);
            this->m_featureChange.m_storage = 1;
            goto LABEL_4;
          }
          v123 = _mm_mul_ps(_mm_sub_ps(v120, this->m_verticesBinB[2].m_quad), v148);
          v124 = (float)(_mm_shuffle_ps(v123, v123, 85).m128_f32[0] + _mm_shuffle_ps(v123, v123, 0).m128_f32[0])
               + _mm_shuffle_ps(v123, v123, 170).m128_f32[0];
          if ( (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v124)) >> 1) * v124) >= v101 )
          {
LABEL_81:
            v125 = _mm_mul_ps(_mm_sub_ps(v120, this->m_verticesBinB[1].m_quad), v148);
            v126 = (float)(_mm_shuffle_ps(v125, v125, 85).m128_f32[0] + _mm_shuffle_ps(v125, v125, 0).m128_f32[0])
                 + _mm_shuffle_ps(v125, v125, 170).m128_f32[0];
            if ( (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v126)) >> 1) * v126) >= v101 )
              goto LABEL_82;
          }
LABEL_83:
          if ( (v16 & 1) != 0 )
            goto LABEL_94;
          v128 = this->m_dimA.m_storage;
          if ( (_DWORD)v128 == this->m_maxDimA.m_storage )
            goto LABEL_94;
          if ( this->m_supportState == DONT_CALL_GET_SUPPORTING_VERTEX_A )
            goto LABEL_94;
          v129 = shapeA->vfptr;
          v149[0] = _mm_xor_ps(
                      (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                      this->m_support.m_quad);
          ((void (__fastcall *)(hkpConvexShape *, __m128 *, hkcdVertex *))v129[4].__vecDelDtor)(
            shapeA,
            v149,
            &this->m_verticesA[v128]);
          v103 = this->m_dimA.m_storage;
          v130 = this->m_verticesA[v103].m_quad;
          v131 = _mm_mul_ps(_mm_sub_ps(v130, this->m_verticesA[0].m_quad), v149[0]);
          v132 = (float)(_mm_shuffle_ps(v131, v131, 85).m128_f32[0] + _mm_shuffle_ps(v131, v131, 0).m128_f32[0])
               + _mm_shuffle_ps(v131, v131, 170).m128_f32[0];
          if ( (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v132)) >> 1) * v132) <= v101 )
            goto LABEL_94;
          if ( (_DWORD)v103 == 2 )
            goto LABEL_90;
          if ( (_DWORD)v103 != 3 )
          {
LABEL_74:
            this->m_featureChange.m_storage = 1;
            this->m_dimA.m_storage = v103 + 1;
            goto LABEL_4;
          }
          v133 = _mm_mul_ps(_mm_sub_ps(v130, this->m_verticesA[2].m_quad), v149[0]);
          v134 = (float)(_mm_shuffle_ps(v133, v133, 85).m128_f32[0] + _mm_shuffle_ps(v133, v133, 0).m128_f32[0])
               + _mm_shuffle_ps(v133, v133, 170).m128_f32[0];
          if ( (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v134)) >> 1) * v134) >= v101 )
          {
LABEL_90:
            v135 = _mm_mul_ps(_mm_sub_ps(v130, this->m_verticesA[1].m_quad), v149[0]);
            v136 = (float)(_mm_shuffle_ps(v135, v135, 85).m128_f32[0] + _mm_shuffle_ps(v135, v135, 0).m128_f32[0])
                 + _mm_shuffle_ps(v135, v135, 170).m128_f32[0];
            if ( (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v136)) >> 1) * v136) >= v101 )
            {
              this->m_featureChange.m_storage = 1;
              this->m_dimA.m_storage = v103 + 1;
              goto LABEL_4;
            }
          }
LABEL_94:
          v137.m_quad = (__m128)this->m_support;
          v138 = _mm_mul_ps(v137.m_quad, v137.m_quad);
          v139 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v138, v138, 85), _mm_shuffle_ps(v138, v138, 0)),
                   _mm_shuffle_ps(v138, v138, 170));
          v140 = _mm_rsqrt_ps(v139);
          v141.m_quad = _mm_mul_ps(
                          _mm_andnot_ps(
                            _mm_cmple_ps(v139, (__m128)0i64),
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v140, v139), v140)),
                              _mm_mul_ps(*(__m128 *)_xmm, v140))),
                          v137.m_quad);
          v142 = _mm_mul_ps(_mm_sub_ps(this->m_verticesA[0].m_quad, m_verticesBinA->m_quad), v141.m_quad);
          this->m_support = (hkVector4f)v141.m_quad;
          v143.m_quad = _mm_shuffle_ps(
                          v141.m_quad,
                          _mm_unpackhi_ps(
                            v141.m_quad,
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v142, v142, 85), _mm_shuffle_ps(v142, v142, 0)),
                              _mm_shuffle_ps(v142, v142, 170))),
                          196);
          *separatingNormalOut = (hkVector4f)v143.m_quad;
          this->m_support = (hkVector4f)v143.m_quad;
          return 0i64;
        }
      case 8u:
        goto LABEL_50;
      case 9u:
        goto LABEL_10;
      case 0xAu:
        v22 = hkpGsk::processEdgeTriangle(
                this,
                &this->m_verticesA[0],
                this->m_verticesBinA,
                &this->m_dimA,
                dimB,
                (hkBool)(this->m_lastDimB.m_storage == 2),
                BUILD_POS_SUPPORT);
        goto LABEL_8;
      case 0x10u:
        goto LABEL_31;
      case 0x11u:
        v22 = hkpGsk::processEdgeTriangle(
                this,
                this->m_verticesBinA,
                &this->m_verticesA[0],
                dimB,
                &this->m_dimA,
                (hkBool)(this->m_lastDimB.m_storage == 2),
                BUILD_NEG_SUPPORT);
LABEL_8:
        v23 = v22 - 1;
        if ( !v23 )
          goto LABEL_62;
        if ( v23 != 1 )
          goto LABEL_61;
LABEL_10:
        v24 = _mm_sub_ps(this->m_verticesBinA[1].m_quad, m_verticesBinA->m_quad);
        dA.m_quad = _mm_sub_ps(this->m_verticesA[1].m_quad, this->m_verticesA[0].m_quad);
        dB.m_quad = v24;
        v25 = hkLineSegmentUtil::closestLineSegLineSeg(
                &this->m_verticesA[0],
                &dA,
                this->m_verticesBinA,
                &dB,
                &this->m_closestLineLineResult);
        if ( !v25 )
        {
          v58 = dimB->m_storage;
          v59 = 0;
          v60 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(dB.m_quad, dB.m_quad, 201), dA.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(dA.m_quad, dA.m_quad, 201), dB.m_quad));
          v61.m_quad = _mm_shuffle_ps(v60, v60, 201);
          this->m_support = (hkVector4f)v61.m_quad;
          v62 = _mm_sub_ps(this->m_verticesA[0].m_quad, m_verticesBinA->m_quad);
          this->m_lastDimB.m_storage = v58;
          v63 = _mm_mul_ps(v62, v61.m_quad);
          this->m_support.m_quad = _mm_xor_ps(
                                     (__m128)_mm_slli_epi32(
                                               _mm_srli_epi32(
                                                 (__m128i)_mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_shuffle_ps(v63, v63, 85),
                                                              _mm_shuffle_ps(v63, v63, 0)),
                                                            _mm_shuffle_ps(v63, v63, 170)),
                                                 0x1Fu),
                                               0x1Fu),
                                     v61.m_quad);
          goto LABEL_63;
        }
        if ( (v25 & 1) != 0 )
        {
          this->m_verticesA[0] = this->m_verticesA[1];
        }
        else if ( (v25 & 2) == 0 )
        {
          goto LABEL_15;
        }
        this->m_dimA.m_storage = 1;
LABEL_15:
        if ( (v25 & 4) != 0 )
        {
          v26.m_quad = (__m128)this->m_verticesBinB[1];
          *m_verticesBinA = this->m_verticesBinA[1];
          this->m_verticesBinB[0] = (hkcdVertex)v26.m_quad;
          dimB->m_storage = 1;
        }
        else if ( (v25 & 8) != 0 )
        {
          dimB->m_storage = 1;
        }
        goto LABEL_41;
      case 0x18u:
        v44 = findClosestTriangle(this->m_verticesBinA, &this->m_verticesA[0], -1.0);
        if ( v44 < 0 )
          goto LABEL_62;
        --this->m_dimA.m_storage;
        this->m_verticesA[v44] = this->m_verticesA[3];
LABEL_31:
        v45 = hkpGsk::checkTriangleBoundaries(this, this->m_verticesBinA, &this->m_verticesA[0], BUILD_NEG_SUPPORT);
        if ( v45 == 7 )
          goto LABEL_61;
        v46 = hkpCollideTriangleUtil::maskToIndex[v45];
        if ( (int)v46 < 0 )
        {
          v78 = v46 + 8;
          if ( v78 != 7 )
          {
            --this->m_dimA.m_storage;
            this->m_verticesA[v78] = this->m_verticesA[2];
LABEL_50:
            v79 = this->m_verticesA[1].m_quad;
            v80 = this->m_verticesA[0].m_quad;
            v81 = _mm_sub_ps(v79, m_verticesBinA->m_quad);
            v82 = _mm_sub_ps(v79, v80);
            v83 = _mm_sub_ps(v80, m_verticesBinA->m_quad);
            v84 = _mm_mul_ps(v81, v82);
            v85 = _mm_mul_ps(v83, v82);
            v86 = (float)(_mm_shuffle_ps(v84, v84, 85).m128_f32[0] + _mm_shuffle_ps(v84, v84, 0).m128_f32[0])
                + _mm_shuffle_ps(v84, v84, 170).m128_f32[0];
            if ( v86 < 0.0 != (float)((float)(_mm_shuffle_ps(v85, v85, 85).m128_f32[0]
                                            + _mm_shuffle_ps(v85, v85, 0).m128_f32[0])
                                    + _mm_shuffle_ps(v85, v85, 170).m128_f32[0]) < 0.0 )
            {
              v59 = 0;
              v87 = _mm_mul_ps(v82, v82);
              v88 = _mm_mul_ps(
                      v82,
                      _mm_rsqrt_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v87, v87, 85), _mm_shuffle_ps(v87, v87, 0)),
                          _mm_shuffle_ps(v87, v87, 170))));
              v89 = _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v83, v83, 201), v81),
                      _mm_mul_ps(_mm_shuffle_ps(v81, v81, 201), v83));
              v90 = _mm_shuffle_ps(v89, v89, 201);
              v91 = _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v88, v88, 201), v90),
                      _mm_mul_ps(_mm_shuffle_ps(v90, v90, 201), v88));
              this->m_support.m_quad = _mm_shuffle_ps(v91, v91, 201);
              this->m_lastDimB = (hkPadSpu<int>)dimB->m_storage;
              goto LABEL_63;
            }
            if ( v86 < 0.0 )
            {
              v93.m_quad = (__m128)this->m_dummy[1];
              this->m_verticesA[0].m_quad = v79;
              this->m_dummy[0] = (hkVector4f)v93.m_quad;
            }
            --this->m_dimA.m_storage;
$LN860_0:
            v77.m_quad = _mm_sub_ps(this->m_verticesA[0].m_quad, m_verticesBinA->m_quad);
            goto LABEL_60;
          }
LABEL_55:
          this->m_dimA.m_storage = 1;
          dimB->m_storage = 1;
          goto $LN860_0;
        }
        v47 = hkpCollideTriangleUtil::vertexToEdgeLut[v46];
        v48 = hkpCollideTriangleUtil::vertexToEdgeLut[v46 + 2];
        v49 = this->m_verticesA[v46].m_quad;
        v50 = 2 * (v48 + 2);
        v51 = _mm_sub_ps(this->m_verticesA[v47].m_quad, v49);
        v52 = _mm_sub_ps(m_verticesBinA->m_quad, v49);
        v53 = this->m_verticesA[v48].m_quad;
        this->m_dimA.m_storage = 2;
        v54 = _mm_mul_ps(v51, v52);
        v55 = _mm_sub_ps(v53, v49);
        v43.m_quad = (__m128)this->m_verticesA[2];
        if ( (float)((float)(_mm_shuffle_ps(v54, v54, 85).m128_f32[0] + _mm_shuffle_ps(v54, v54, 0).m128_f32[0])
                   + _mm_shuffle_ps(v54, v54, 170).m128_f32[0]) >= 0.0 )
          goto LABEL_40;
        v56 = _mm_mul_ps(v55, v52);
        this->m_verticesA[v47] = (hkcdVertex)v43.m_quad;
        if ( (float)((float)(_mm_shuffle_ps(v56, v56, 85).m128_f32[0] + _mm_shuffle_ps(v56, v56, 0).m128_f32[0])
                   + _mm_shuffle_ps(v56, v56, 170).m128_f32[0]) >= 0.0 )
          goto LABEL_41;
        if ( (_DWORD)v48 == this->m_dimA.m_storage )
          LODWORD(v48) = v47;
        v57 = this->m_dimA.m_storage - 1;
        this->m_dimA.m_storage = v57;
        v42 = v57 + 2i64;
        v41 = (int)v48 + 2i64;
        goto LABEL_38;
      default:
        goto LABEL_62;
    }
  }
}       + _mm_shuffle_ps(v54, v54, 170).m128_f32[0]) >= 0.0 )
          goto LABEL_40;
        v56 = _mm_mul_ps(v55, v52);
        this->m_verticesA[v47] = (hkcdVertex)v43.m_quad;
        if ( (float)((float)(_mm_shuffle_ps(v56, v56, 85).m128_f32[0] + _mm_shuffle_ps(v56, v56, 0).m128_f32[0])
                   + _mm

// File Line: 1101
// RVA: 0xDBA360
void __fastcall hkpGsk::exitAndExportCacheImpl(hkpGsk *this, hkpGskCache *cache)
{
  int v3; // r11d
  unsigned __int16 v4; // r9
  unsigned __int16 v5; // r10
  int v6; // ebx
  unsigned __int16 v7; // dx
  unsigned __int16 v8; // ax
  int m_storage; // r9d
  unsigned __int16 v10; // dx
  unsigned __int16 v11; // r10
  unsigned __int16 v12; // r9
  unsigned __int16 v13; // ax

  v3 = 0;
  cache->m_dimA = this->m_dimA.m_storage;
  cache->m_dimB = this->m_dimB.m_storage;
  v4 = this->m_verticesA[0].m_quad.m128_u16[6];
  if ( this->m_dimA.m_storage >= 2 )
  {
    v5 = this->m_verticesA[1].m_quad.m128_u16[6];
    v6 = 0;
    if ( v5 > v4 )
    {
      v5 = this->m_verticesA[0].m_quad.m128_u16[6];
      v6 = 1;
      v4 = this->m_verticesA[1].m_quad.m128_u16[6];
    }
    if ( this->m_dimA.m_storage > 2 )
    {
      v7 = this->m_verticesA[2].m_quad.m128_u16[6];
      if ( v7 > v4 )
      {
        v7 = v4;
        ++v6;
        v4 = this->m_verticesA[2].m_quad.m128_u16[6];
      }
      if ( v6 == 1 )
      {
        v8 = v7;
        v7 = v5;
        v5 = v8;
      }
      cache->m_vertices[2] = v7;
    }
    cache->m_vertices[1] = v5;
  }
  cache->m_vertices[0] = v4;
  m_storage = this->m_dimB.m_storage;
  v10 = this->m_verticesBinB[0].m_quad.m128_u16[6];
  if ( m_storage >= 2 )
  {
    v11 = this->m_verticesBinB[1].m_quad.m128_u16[6];
    if ( v11 > v10 )
    {
      v11 = this->m_verticesBinB[0].m_quad.m128_u16[6];
      v3 = 1;
      v10 = this->m_verticesBinB[1].m_quad.m128_u16[6];
    }
    if ( m_storage > 2 )
    {
      v12 = this->m_verticesBinB[2].m_quad.m128_u16[6];
      if ( v12 > v10 )
      {
        v12 = v10;
        ++v3;
        v10 = this->m_verticesBinB[2].m_quad.m128_u16[6];
      }
      if ( v3 == 1 )
      {
        v13 = v12;
        v12 = v11;
        v11 = v13;
      }
      cache->m_vertices[this->m_dimA.m_storage + 2] = v12;
    }
    cache->m_vertices[this->m_dimA.m_storage + 1] = v11;
  }
  cache->m_vertices[this->m_dimA.m_storage] = v10;
}

// File Line: 1147
// RVA: 0xDB99F0
void __fastcall hkpGsk::convertFeatureToClosestDistance(hkpGsk *this, hkVector4f *separatingNormal, hkpGskOut *out)
{
  __m128 m_quad; // xmm1
  __m128 v4; // xmm0

  LODWORD(out->m_distance.m_storage) = separatingNormal->m_quad.m128_i32[3];
  m_quad = separatingNormal->m_quad;
  out->m_normalInA = (hkVector4f)separatingNormal->m_quad;
  if ( this->m_dimA.m_storage == 1 )
  {
    out->m_pointAinA = (hkVector4f)this->m_verticesA[0];
  }
  else
  {
    if ( this->m_dimB.m_storage == 1 )
      v4 = _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(separatingNormal->m_quad, separatingNormal->m_quad, 255), m_quad),
             this->m_verticesBinA[0].m_quad);
    else
      v4 = this->m_closestLineLineResult.m_closestPointA.m_quad;
    out->m_pointAinA.m_quad = v4;
  }
}

// File Line: 1171
// RVA: 0xDB9A40
hkResult *__fastcall hkpGsk::getClosestPoint(
        hkResult *result,
        hkpGsk::GetClosesetPointInput *input,
        hkpGskCache *gskCache,
        hkVector4f *separatingNormalOut,
        hkVector4f *pointOnBOut)
{
  hkpConvexShape *m_storage; // rbx
  __int64 m_dimA; // r8
  hkpConvexShape *v10; // rcx
  unsigned int v11; // edx
  __m128 m_quad; // xmm5
  __m128 m_radius_low; // xmm4
  __m128 v15; // xmm6
  __m128 v16; // xmm0
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm4
  hkTransformf *v21; // rax
  hkVector4f v23; // [rsp+30h] [rbp-1D8h] BYREF
  hkpGsk v24; // [rsp+40h] [rbp-1C8h] BYREF

  m_storage = input->m_shapeB.m_storage;
  m_dimA = (unsigned __int8)gskCache->m_dimA;
  v23.m_quad = 0i64;
  v10 = input->m_shapeA.m_storage;
  v11 = *((unsigned __int8 *)gskCache + 10);
  v24.m_dimB.m_storage = (unsigned __int8)gskCache->m_dimB;
  v24.m_featureChange.m_storage = 0;
  *(_QWORD *)&v24.m_maxDimB.m_storage = v11 >> 4;
  v24.m_dimA.m_storage = m_dimA;
  v24.m_maxDimA.m_storage = v11 & 0xF;
  ((void (__fastcall *)(hkpConvexShape *, hkpGskCache *, __int64, hkcdVertex *))v10->vfptr[4].__first_virtual_table_function__)(
    v10,
    gskCache,
    m_dimA,
    v24.m_verticesA);
  ((void (__fastcall *)(hkpConvexShape *, unsigned __int16 *, _QWORD, hkcdVertex *))m_storage->vfptr[4].__first_virtual_table_function__)(
    m_storage,
    &gskCache->m_vertices[v24.m_dimA.m_storage],
    (unsigned int)v24.m_dimB.m_storage,
    v24.m_verticesBinB);
  hkpGsk::getClosestFeature(&v24, input->m_shapeA.m_storage, input->m_shapeB.m_storage, input->m_aTb.m_storage, &v23);
  if ( v24.m_featureChange.m_storage )
    hkpGsk::exitAndExportCacheImpl(&v24, gskCache);
  m_quad = v23.m_quad;
  m_radius_low = (__m128)LODWORD(input->m_shapeB.m_storage->m_radius);
  v15 = _mm_shuffle_ps(v23.m_quad, v23.m_quad, 255);
  v16 = (__m128)LODWORD(input->m_shapeA.m_storage->m_radius);
  v17 = _mm_shuffle_ps(m_radius_low, m_radius_low, 0);
  v18 = _mm_sub_ps(_mm_sub_ps(v15, _mm_shuffle_ps(v16, v16, 0)), v17);
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(v23.m_quad, v23.m_quad, 85),
              input->m_transformA.m_storage->m_rotation.m_col1.m_quad),
            _mm_mul_ps(
              _mm_shuffle_ps(v23.m_quad, v23.m_quad, 0),
              input->m_transformA.m_storage->m_rotation.m_col0.m_quad)),
          _mm_mul_ps(
            _mm_shuffle_ps(v23.m_quad, v23.m_quad, 170),
            input->m_transformA.m_storage->m_rotation.m_col2.m_quad));
  separatingNormalOut->m_quad = _mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, v18), 196);
  if ( v18.m128_f32[0] >= _mm_shuffle_ps(
                            (__m128)LODWORD(input->m_collisionTolerance.m_storage),
                            (__m128)LODWORD(input->m_collisionTolerance.m_storage),
                            0).m128_f32[0] )
  {
    result->m_enum = HK_FAILURE;
  }
  else
  {
    if ( v24.m_dimA.m_storage == 1 )
    {
      v20 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v17, v15), m_quad), v24.m_verticesA[0].m_quad);
    }
    else if ( v24.m_dimB.m_storage == 1 )
    {
      v20 = _mm_add_ps(_mm_mul_ps(v17, m_quad), v24.m_verticesBinA[0].m_quad);
    }
    else
    {
      v20 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v17, v15), m_quad), v24.m_closestLineLineResult.m_closestPointA.m_quad);
    }
    v21 = input->m_transformA.m_storage;
    result->m_enum = HK_SUCCESS;
    pointOnBOut->m_quad = _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v21->m_rotation.m_col1.m_quad),
                                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v21->m_rotation.m_col0.m_quad)),
                              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v21->m_rotation.m_col2.m_quad)),
                            v21->m_translation.m_quad);
  }
  return result;
}

// File Line: 1249
// RVA: 0xDB9C50
void hkpGsk::codeEnd(void)
{
  ;
}

// File Line: 1253
// RVA: 0xDB9FC0
void __fastcall hkpGsk::handlePenetration(
        hkpGsk *this,
        hkpConvexShape *shapeA,
        hkpConvexShape *shapeB,
        hkTransformf *aTb)
{
  int m_storage; // eax
  int simplexSize; // r10d
  __int64 v8; // rcx
  hkcdVertex v9; // xmm0
  hkcdVertex v10; // xmm0
  hkcdVertex v11; // xmm1
  hkVector4f v12; // xmm0
  __int64 v13; // rcx
  hkcdVertex *m_verticesA; // rax
  __m128 m_quad; // xmm0
  hkcdVertex *v16; // rdi
  __int16 v17; // ax
  __int16 v18; // ax
  int v19; // ecx
  hkVector4f v20; // xmm3
  hkVector4f v21; // xmm4
  __int64 v22; // rcx
  hkVector4f v23; // xmm5
  hkVector4f v24; // xmm6
  hkcdVertex *v25; // rax
  __m128 v26; // xmm1
  __m128 v27; // xmm1
  hkVector4f v28; // xmm0
  hkVector4f dA; // [rsp+50h] [rbp-A8h] BYREF
  hkVector4f dB; // [rsp+60h] [rbp-98h] BYREF
  hkpGskOut output; // [rsp+70h] [rbp-88h] BYREF
  hkVector4f simplex; // [rsp+A0h] [rbp-58h] BYREF

  m_storage = this->m_dimB.m_storage;
  simplexSize = 4;
  if ( m_storage < 3 )
  {
    v8 = this->m_dimA.m_storage;
    if ( (int)v8 < 3 )
    {
      v10.m_quad = (__m128)this->m_verticesA[0];
      simplexSize = 1;
      this->m_verticesA[v8] = (hkcdVertex)v10.m_quad;
      this->m_verticesA[this->m_dimA.m_storage + 1] = (hkcdVertex)v10.m_quad;
      v11.m_quad = (__m128)this->m_verticesBinB[0];
      this->m_verticesBinB[this->m_dimB.m_storage] = (hkcdVertex)v11.m_quad;
      this->m_verticesBinB[this->m_dimB.m_storage + 1] = (hkcdVertex)v11.m_quad;
      v12.m_quad = (__m128)this->m_verticesBinA[0];
      this->m_verticesBinA[this->m_dimB.m_storage] = (hkVector4f)v12.m_quad;
      this->m_verticesBinA[this->m_dimB.m_storage + 1] = (hkVector4f)v12.m_quad;
    }
    else
    {
      if ( (int)v8 <= 3 )
      {
        if ( m_storage <= 1 )
        {
          simplexSize = 3;
        }
        else
        {
          this->m_verticesA[3] = this->m_verticesA[0];
          this->m_verticesBinB[3] = this->m_verticesBinB[1];
          this->m_verticesBinA[3] = this->m_verticesBinA[1];
        }
      }
      else
      {
        this->m_verticesBinB[3] = this->m_verticesBinB[0];
        this->m_verticesBinA[3] = this->m_verticesBinA[0];
      }
      this->m_verticesBinB[1] = this->m_verticesBinB[0];
      v9.m_quad = (__m128)this->m_verticesBinB[0];
      this->m_verticesBinA[1] = this->m_verticesBinA[0];
      this->m_verticesBinB[2] = (hkcdVertex)v9.m_quad;
      this->m_verticesBinA[2] = this->m_verticesBinA[0];
    }
  }
  else
  {
    if ( m_storage <= 3 )
    {
      if ( this->m_dimA.m_storage <= 1 )
      {
        simplexSize = 3;
      }
      else
      {
        this->m_verticesA[3] = this->m_verticesA[1];
        this->m_verticesBinB[3] = this->m_verticesBinB[0];
        this->m_verticesBinA[3] = this->m_verticesBinA[0];
      }
    }
    else
    {
      this->m_verticesA[3] = this->m_verticesA[0];
    }
    this->m_verticesA[1] = this->m_verticesA[0];
    this->m_verticesA[2] = this->m_verticesA[0];
  }
  v13 = simplexSize;
  m_verticesA = this->m_verticesA;
  do
  {
    m_quad = m_verticesA->m_quad;
    ++m_verticesA;
    *(__m128 *)((char *)&m_verticesA[-3].m_quad + (char *)&simplex - (char *)this) = _mm_sub_ps(
                                                                                       m_quad,
                                                                                       m_verticesA[7].m_quad);
    --v13;
  }
  while ( v13 );
  v16 = this->m_verticesA;
  if ( hkCalculatePenetrationDepth(
         shapeA,
         shapeB,
         aTb,
         0.000099999997,
         this->m_verticesA,
         this->m_verticesBinB,
         &simplex,
         simplexSize,
         &output) == HK_GSK_PD_HEURISTIC_SAMPLING )
  {
    this->m_dimA.m_storage = 1;
    this->m_dimB.m_storage = 1;
  }
  else
  {
    this->m_dimA.m_storage = 3;
    this->m_dimB.m_storage = 3;
    v17 = this->m_verticesA[2].m_quad.m128_i16[6];
    if ( this->m_verticesA[1].m_quad.m128_i16[6] == v17 || this->m_verticesA[0].m_quad.m128_i16[6] == v17 )
      this->m_dimA.m_storage = 2;
    if ( this->m_verticesA[0].m_quad.m128_i16[6] == this->m_verticesA[1].m_quad.m128_i16[6] )
      *v16 = this->m_verticesA[--this->m_dimA.m_storage];
    v18 = this->m_verticesBinB[2].m_quad.m128_i16[6];
    if ( this->m_verticesBinB[1].m_quad.m128_i16[6] == v18 || this->m_verticesBinB[0].m_quad.m128_i16[6] == v18 )
      --this->m_dimB.m_storage;
    v19 = this->m_dimB.m_storage;
    if ( v19 >= 2 && this->m_verticesBinB[0].m_quad.m128_i16[6] == this->m_verticesBinB[1].m_quad.m128_i16[6] )
    {
      this->m_dimB.m_storage = v19 - 1;
      this->m_verticesBinB[0] = (hkcdVertex)this->m_verticesBinA[v19 + 3];
    }
    v20.m_quad = (__m128)aTb->m_rotation.m_col0;
    v21.m_quad = (__m128)aTb->m_rotation.m_col1;
    v22 = this->m_dimB.m_storage - 1;
    v23.m_quad = (__m128)aTb->m_rotation.m_col2;
    v24.m_quad = (__m128)aTb->m_translation;
    v25 = &this->m_verticesBinB[v22];
    do
    {
      v26 = v25->m_quad;
      --v25;
      --v22;
      v25[-3].m_quad = _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), v21.m_quad),
                             _mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), v20.m_quad)),
                           _mm_mul_ps(_mm_shuffle_ps(v26, v26, 170), v23.m_quad)),
                         v24.m_quad);
    }
    while ( v22 >= 0 );
    if ( this->m_dimB.m_storage + this->m_dimA.m_storage > 4 )
      hkpGsk::reduceDimensionExtended(this);
    if ( this->m_dimA.m_storage == 2 && this->m_dimB.m_storage == 2 )
    {
      v27 = _mm_sub_ps(this->m_verticesBinA[1].m_quad, this->m_verticesBinA[0].m_quad);
      dA.m_quad = _mm_sub_ps(this->m_verticesA[1].m_quad, v16->m_quad);
      dB.m_quad = v27;
      hkLineSegmentUtil::closestLineSegLineSeg(
        &this->m_verticesA[0],
        &dA,
        this->m_verticesBinA,
        &dB,
        &this->m_closestLineLineResult);
    }
  }
  v28.m_quad = (__m128)output.m_normalInA;
  this->m_featureChange.m_storage = 1;
  this->m_support = (hkVector4f)v28.m_quad;
}

// File Line: 1403
// RVA: 0xDB9C70
void __fastcall hkpGsk::reduceDimensionExtended(hkpGsk *this)
{
  int v2; // edi
  int v3; // edi
  int v4; // r9d
  int v5; // eax
  float m_storage; // xmm6_4
  int v7; // r13d
  int v8; // r14d
  __int64 v9; // r12
  __int64 v10; // r15
  hkcdVertex *m_verticesA; // rcx
  int v12; // edi
  __int64 v13; // rsi
  hkVector4f *m_verticesBinA; // rbp
  hkcdVertex *v15; // r10
  __int64 v16; // rax
  int v17; // r8d
  __int64 v18; // rdx
  __int64 v19; // [rsp+38h] [rbp-D0h]
  hkVector4f dB; // [rsp+40h] [rbp-C8h] BYREF
  hkVector4f dA; // [rsp+50h] [rbp-B8h] BYREF
  hkLineSegmentUtil::ClosestLineSegLineSegResult result; // [rsp+60h] [rbp-A8h] BYREF
  int v23; // [rsp+110h] [rbp+8h]
  int v24; // [rsp+118h] [rbp+10h]
  int v25; // [rsp+120h] [rbp+18h]
  hkcdVertex *v26; // [rsp+128h] [rbp+20h]

  if ( this->m_dimB.m_storage == 3 && (v2 = 0, this->m_dimA.m_storage > 0) )
  {
    while ( hkpGsk::checkTriangleBoundaries(this, &this->m_verticesA[v2], this->m_verticesBinA, BUILD_NO_SUPPORT) != 7 )
    {
      if ( ++v2 >= this->m_dimA.m_storage )
        goto LABEL_5;
    }
    this->m_verticesA[0] = this->m_verticesA[v2];
    this->m_dimA.m_storage = 1;
  }
  else
  {
LABEL_5:
    if ( this->m_dimA.m_storage == 3 && (v3 = 0, this->m_dimB.m_storage > 0) )
    {
      while ( hkpGsk::checkTriangleBoundaries(this, &this->m_verticesBinA[v3], &this->m_verticesA[0], BUILD_NO_SUPPORT) != 7 )
      {
        if ( ++v3 >= this->m_dimB.m_storage )
          goto LABEL_9;
      }
      this->m_verticesBinB[0] = this->m_verticesBinB[v3];
      this->m_verticesBinA[0] = this->m_verticesBinA[v3];
      this->m_dimB.m_storage = 1;
    }
    else
    {
LABEL_9:
      v4 = 1;
      v5 = 1;
      m_storage = FLOAT_3_40282e38;
      if ( this->m_dimA.m_storage == 3 )
        v5 = 3;
      if ( this->m_dimB.m_storage == 3 )
        v4 = 3;
      v25 = v5;
      v7 = 0;
      v8 = 0;
      v9 = 0i64;
      v23 = 0;
      v24 = v4;
      v10 = v4;
      v19 = v5;
      m_verticesA = this->m_verticesA;
      v26 = this->m_verticesA;
      do
      {
        v12 = 0;
        v13 = 0i64;
        m_verticesBinA = this->m_verticesBinA;
        v15 = &this->m_verticesA[v8];
        do
        {
          v16 = hkpCollideTriangleUtil::vertexToEdgeLut[v13 + 2] + 10i64;
          dA.m_quad = _mm_sub_ps(
                        this->m_verticesA[hkpCollideTriangleUtil::vertexToEdgeLut[v9 + 2]].m_quad,
                        m_verticesA->m_quad);
          dB.m_quad = _mm_sub_ps(*((__m128 *)&this->m_dimA.m_storage + v16), m_verticesBinA->m_quad);
          hkLineSegmentUtil::closestLineSegLineSeg(v15, &dA, &this->m_verticesBinA[v12], &dB, &result);
          if ( result.m_distanceSquared.m_storage >= m_storage )
          {
            v17 = v23;
          }
          else
          {
            m_storage = result.m_distanceSquared.m_storage;
            v7 = v8;
            v17 = v12;
            v23 = v12;
          }
          m_verticesA = v26;
          v15 = &this->m_verticesA[v8];
          ++v13;
          ++v12;
          ++m_verticesBinA;
        }
        while ( v13 < v10 );
        m_verticesA = v26 + 1;
        ++v9;
        ++v8;
        ++v26;
      }
      while ( v9 < v19 );
      if ( v25 == 3 )
        this->m_verticesA[hkpCollideTriangleUtil::vertexToEdgeLut[v7]] = this->m_verticesA[--this->m_dimA.m_storage];
      if ( v24 == 3 )
      {
        --this->m_dimB.m_storage;
        v18 = hkpCollideTriangleUtil::vertexToEdgeLut[v17];
        this->m_verticesBinB[v18] = this->m_verticesBinB[this->m_dimB.m_storage];
        this->m_verticesBinA[v18] = this->m_verticesBinA[this->m_dimB.m_storage];
      }
    }
  }
}

// File Line: 1580
// RVA: 0xDBB600
hkSimdFloat32 *__fastcall hkGskRecalcContact_pointTriangle(
        hkSimdFloat32 *result,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *masterNormal,
        hkVector4f *support)
{
  __m128 v5; // xmm1
  __m128 v6; // xmm5
  __m128 v7; // xmm5
  __m128 v8; // xmm5
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm2
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  hkSimdFloat32 *v17; // rax
  __m128 v18; // xmm2

  v5 = _mm_sub_ps(b[2].m_quad, b[1].m_quad);
  v6 = _mm_sub_ps(b->m_quad, b[2].m_quad);
  v7 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v5), _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v6));
  v8 = _mm_shuffle_ps(v7, v7, 201);
  *support = (hkVector4f)v8;
  v9 = _mm_mul_ps(v8, v8);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_rsqrt_ps(v10);
  v12 = _mm_cmple_ps(v10, (__m128)0i64);
  v13 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11));
  v14 = _mm_mul_ps(*(__m128 *)_xmm, v11);
  v15 = _mm_mul_ps(v8, masterNormal->m_quad);
  v16 = _mm_mul_ps(
          _mm_xor_ps(
            (__m128)_mm_slli_epi32(
                      _mm_srli_epi32(
                        (__m128i)_mm_add_ps(
                                   _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                                   _mm_shuffle_ps(v15, v15, 170)),
                        0x1Fu),
                      0x1Fu),
            v8),
          _mm_andnot_ps(v12, _mm_mul_ps(v13, v14)));
  *support = (hkVector4f)v16;
  v17 = result;
  v18 = _mm_mul_ps(_mm_sub_ps(a->m_quad, b->m_quad), v16);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                     _mm_shuffle_ps(v18, v18, 170));
  return v17;
}

// File Line: 1599
// RVA: 0xDBB6F0
hkSimdFloat32 *__fastcall hkGskRecalcContact_pointEdge(
        hkSimdFloat32 *result,
        hkVector4f *vertexA,
        hkVector4f *vertexB,
        hkVector4f *masterNormal,
        hkVector4f *support)
{
  __m128 m_quad; // xmm2
  __m128 v6; // xmm0
  hkSimdFloat32 *v7; // rax
  __m128 v8; // xmm2

  m_quad = masterNormal->m_quad;
  v6 = _mm_sub_ps(vertexA->m_quad, vertexB->m_quad);
  *support = (hkVector4f)masterNormal->m_quad;
  v7 = result;
  v8 = _mm_mul_ps(m_quad, v6);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)),
                     _mm_shuffle_ps(v8, v8, 170));
  return v7;
}

// File Line: 1609
// RVA: 0xDBB730
void __fastcall hkGskRecalcContact_edgeEdge(
        hkVector4f *vertexA,
        hkVector4f *vertexB,
        hkVector4f *masterNormal,
        hkVector4f *pointAOut,
        hkVector4f *support)
{
  __m128 v8; // xmm0
  __m128 v10; // xmm2
  __m128 v11; // xmm6
  __m128 v12; // xmm1
  __m128 v13; // xmm6
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  float v16; // xmm4_4
  __m128 v17; // xmm1
  __m128 v18; // xmm5
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  hkVector4f dA; // [rsp+30h] [rbp-88h] BYREF
  hkVector4f dB; // [rsp+40h] [rbp-78h] BYREF
  hkLineSegmentUtil::ClosestLineSegLineSegResult result; // [rsp+50h] [rbp-68h] BYREF

  v8 = _mm_sub_ps(vertexA[1].m_quad, vertexA->m_quad);
  dB.m_quad = _mm_sub_ps(vertexB[1].m_quad, vertexB->m_quad);
  dA.m_quad = v8;
  hkLineSegmentUtil::closestLineSegLineSeg(vertexA, &dA, vertexB, &dB, &result);
  v10 = _mm_mul_ps(dA.m_quad, dA.m_quad);
  v11 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(dB.m_quad, dB.m_quad, 201), dA.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(dA.m_quad, dA.m_quad, 201), dB.m_quad));
  v12 = _mm_mul_ps(dB.m_quad, dB.m_quad);
  v13 = _mm_shuffle_ps(v11, v11, 201);
  *support = (hkVector4f)v13;
  v14 = _mm_add_ps(v10, v12);
  v15 = _mm_mul_ps(v13, v13);
  v16 = (float)(_mm_shuffle_ps(v14, v14, 85).m128_f32[0] + _mm_shuffle_ps(v14, v14, 0).m128_f32[0])
      + _mm_shuffle_ps(v14, v14, 170).m128_f32[0];
  if ( (float)((float)((float)(_mm_shuffle_ps(v15, v15, 85).m128_f32[0] + _mm_shuffle_ps(v15, v15, 0).m128_f32[0])
                     + _mm_shuffle_ps(v15, v15, 170).m128_f32[0])
             * _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0).m128_f32[0]) <= (float)(v16 * v16) )
  {
    *support = (hkVector4f)masterNormal->m_quad;
  }
  else
  {
    v17 = _mm_mul_ps(v13, masterNormal->m_quad);
    v18 = _mm_xor_ps(
            (__m128)_mm_slli_epi32(
                      _mm_srli_epi32(
                        (__m128i)_mm_add_ps(
                                   _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                                   _mm_shuffle_ps(v17, v17, 170)),
                        0x1Fu),
                      0x1Fu),
            v13);
    v19 = _mm_mul_ps(v18, v18);
    v20 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
            _mm_shuffle_ps(v19, v19, 170));
    v21 = _mm_rsqrt_ps(v20);
    support->m_quad = _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmple_ps(v20, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                            _mm_mul_ps(*(__m128 *)_xmm, v21))),
                        v18);
  }
  v22 = _mm_mul_ps(_mm_sub_ps(vertexA->m_quad, vertexB->m_quad), support->m_quad);
  *pointAOut = result.m_closestPointA;
  support->m_quad = _mm_shuffle_ps(
                      support->m_quad,
                      _mm_unpackhi_ps(
                        support->m_quad,
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                          _mm_shuffle_ps(v22, v22, 170))),
                      196);
}

// File Line: 1644
// RVA: 0xDBAAA0
void __fastcall hkGskRecalcContactInternal(
        hkVector4f *verticesA,
        hkVector4f *verticesB,
        int dimA,
        int dimB,
        hkVector4f *masterNormal,
        hkVector4f *pointA,
        hkVector4f *support)
{
  hkVector4f *v8; // rbx
  int v9; // edx
  __m128 v10; // xmm6
  __m128 v11; // xmm5
  __m128 v12; // xmm4
  __m128 v13; // xmm5
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm5
  hkVector4f v17; // xmm6
  __m128 v18; // xmm2
  hkVector4f *v19; // rcx
  __m128 v20; // xmm1
  __m128 m_quad; // xmm0
  __m128 v22; // xmm1
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm5
  __m128 v29; // xmm5
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm0
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm3
  __m128 v38; // xmm1
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm6
  __m128 v45; // xmm1
  __m128 v46; // xmm6
  __m128 v47; // xmm2
  __m128 v48; // xmm1
  float v49; // xmm4_4
  __m128 v50; // xmm1
  __m128 v51; // xmm5
  __m128 v52; // xmm1
  __m128 v53; // xmm3
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  hkVector4f dB; // [rsp+30h] [rbp-98h] BYREF
  hkVector4f dA; // [rsp+40h] [rbp-88h] BYREF
  hkLineSegmentUtil::ClosestLineSegLineSegResult result; // [rsp+50h] [rbp-78h] BYREF

  v8 = verticesA;
  v9 = dimB | (8 * dimA);
  switch ( v9 )
  {
    case 9:
      v10 = _mm_sub_ps(verticesA->m_quad, verticesB->m_quad);
      *support = (hkVector4f)v10;
      v11 = _mm_mul_ps(v10, v10);
      v12 = _mm_mul_ps(masterNormal->m_quad, v10);
      if ( (float)((float)((float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0] + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])
                         + _mm_shuffle_ps(v12, v12, 170).m128_f32[0])
                 * _mm_shuffle_ps((__m128)LODWORD(FLOAT_1000_0), (__m128)LODWORD(FLOAT_1000_0), 0).m128_f32[0]) >= (float)((float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0] + _mm_shuffle_ps(v11, v11, 0).m128_f32[0]) + _mm_shuffle_ps(v11, v11, 170).m128_f32[0]) )
      {
        v14 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                _mm_shuffle_ps(v11, v11, 170));
        v15 = _mm_rsqrt_ps(v14);
        v16 = _mm_andnot_ps(
                _mm_cmple_ps(v14, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
                  _mm_mul_ps(*(__m128 *)_xmm, v15)));
        v17.m_quad = _mm_mul_ps(v10, v16);
        v13 = _mm_mul_ps(v16, v14);
        *support = (hkVector4f)v17.m_quad;
      }
      else
      {
        *support = (hkVector4f)masterNormal->m_quad;
        v13 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                _mm_shuffle_ps(v12, v12, 170));
      }
      support->m_quad = _mm_shuffle_ps(support->m_quad, _mm_unpackhi_ps(support->m_quad, v13), 196);
      *pointA = (hkVector4f)verticesA->m_quad;
      return;
    case 10:
      v18 = _mm_mul_ps(masterNormal->m_quad, _mm_sub_ps(verticesA->m_quad, verticesB->m_quad));
      support->m_quad = _mm_shuffle_ps(
                          masterNormal->m_quad,
                          _mm_unpackhi_ps(
                            masterNormal->m_quad,
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                              _mm_shuffle_ps(v18, v18, 170))),
                          196);
      *pointA = (hkVector4f)verticesA->m_quad;
      return;
    case 11:
      goto $LN5_200;
    case 17:
      v19 = support;
      v20 = _mm_sub_ps(verticesB->m_quad, v8->m_quad);
      m_quad = masterNormal->m_quad;
      *support = (hkVector4f)masterNormal->m_quad;
      v22 = _mm_mul_ps(v20, m_quad);
      v23 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
              _mm_shuffle_ps(v22, v22, 170));
      v24 = verticesB->m_quad;
      *pointA = (hkVector4f)verticesB->m_quad;
      pointA->m_quad = _mm_sub_ps(v24, _mm_mul_ps(v23, support->m_quad));
      v25 = _mm_sub_ps((__m128)0i64, v23);
      goto LABEL_17;
    case 18:
      v42 = _mm_sub_ps(verticesB[1].m_quad, verticesB->m_quad);
      dA.m_quad = _mm_sub_ps(verticesA[1].m_quad, verticesA->m_quad);
      dB.m_quad = v42;
      hkLineSegmentUtil::closestLineSegLineSeg(verticesA, &dA, verticesB, &dB, &result);
      v19 = support;
      v43 = _mm_mul_ps(dB.m_quad, dB.m_quad);
      v44 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(dB.m_quad, dB.m_quad, 201), dA.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(dA.m_quad, dA.m_quad, 201), dB.m_quad));
      v45 = _mm_mul_ps(dA.m_quad, dA.m_quad);
      v46 = _mm_shuffle_ps(v44, v44, 201);
      *support = (hkVector4f)v46;
      v47 = _mm_add_ps(v43, v45);
      v48 = _mm_mul_ps(v46, v46);
      v49 = (float)(_mm_shuffle_ps(v47, v47, 85).m128_f32[0] + _mm_shuffle_ps(v47, v47, 0).m128_f32[0])
          + _mm_shuffle_ps(v47, v47, 170).m128_f32[0];
      if ( (float)((float)((float)(_mm_shuffle_ps(v48, v48, 85).m128_f32[0] + _mm_shuffle_ps(v48, v48, 0).m128_f32[0])
                         + _mm_shuffle_ps(v48, v48, 170).m128_f32[0])
                 * _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0).m128_f32[0]) <= (float)(v49 * v49) )
      {
        *support = (hkVector4f)masterNormal->m_quad;
      }
      else
      {
        v50 = _mm_mul_ps(v46, masterNormal->m_quad);
        v51 = _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32(
                            (__m128i)_mm_add_ps(
                                       _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
                                       _mm_shuffle_ps(v50, v50, 170)),
                            0x1Fu),
                          0x1Fu),
                v46);
        v52 = _mm_mul_ps(v51, v51);
        v53 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                _mm_shuffle_ps(v52, v52, 170));
        v54 = _mm_rsqrt_ps(v53);
        support->m_quad = _mm_mul_ps(
                            _mm_andnot_ps(
                              _mm_cmple_ps(v53, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v54, v53), v54)),
                                _mm_mul_ps(*(__m128 *)_xmm, v54))),
                            v51);
      }
      v55 = _mm_mul_ps(_mm_sub_ps(v8->m_quad, verticesB->m_quad), support->m_quad);
      *pointA = result.m_closestPointA;
      v25 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
              _mm_shuffle_ps(v55, v55, 170));
LABEL_17:
      v19->m_quad = _mm_shuffle_ps(v19->m_quad, _mm_unpackhi_ps(v19->m_quad, v25), 196);
      break;
    case 25:
      v8 = verticesB;
      verticesB = verticesA;
$LN5_200:
      v26 = _mm_sub_ps(verticesB[2].m_quad, verticesB[1].m_quad);
      v27 = _mm_sub_ps(verticesB->m_quad, verticesB[2].m_quad);
      v28 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v26), _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v27));
      v29 = _mm_shuffle_ps(v28, v28, 201);
      *support = (hkVector4f)v29;
      v30 = _mm_mul_ps(v29, v29);
      v31 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
              _mm_shuffle_ps(v30, v30, 170));
      v32 = _mm_rsqrt_ps(v31);
      v33 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32));
      v34 = _mm_mul_ps(*(__m128 *)_xmm, v32);
      v35 = _mm_mul_ps(v29, masterNormal->m_quad);
      v36 = _mm_mul_ps(
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32(
                            (__m128i)_mm_add_ps(
                                       _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
                                       _mm_shuffle_ps(v35, v35, 170)),
                            0x1Fu),
                          0x1Fu),
                v29),
              _mm_andnot_ps(_mm_cmple_ps(v31, (__m128)0i64), _mm_mul_ps(v33, v34)));
      *support = (hkVector4f)v36;
      v37 = v8->m_quad;
      v38 = _mm_sub_ps(v8->m_quad, verticesB->m_quad);
      *pointA = (hkVector4f)v8->m_quad;
      v39 = _mm_mul_ps(v38, v36);
      v40 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
              _mm_shuffle_ps(v39, v39, 170));
      if ( v9 == 11 )
      {
        v41 = _mm_unpackhi_ps(support->m_quad, v40);
      }
      else
      {
        pointA->m_quad = _mm_sub_ps(v37, _mm_mul_ps(v40, support->m_quad));
        v41 = _mm_unpackhi_ps(support->m_quad, _mm_sub_ps((__m128)0i64, v40));
      }
      support->m_quad = _mm_shuffle_ps(support->m_quad, v41, 196);
      break;
    default:
      return;
  }
}


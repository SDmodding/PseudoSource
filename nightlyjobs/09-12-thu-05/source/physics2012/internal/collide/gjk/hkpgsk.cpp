// File Line: 87
// RVA: 0xDB9C60
void __fastcall hkpGsk::print(hkpGsk *this)
{
  ;
}

// File Line: 96
// RVA: 0xDBB000
signed __int64 __fastcall findClosestTriangleBackup(hkVector4f *a0, hkVector4f *tetra, hkVector4f *oldDots, float sign)
{
  char *v4; // r9
  hkVector4f *v5; // r10
  signed __int64 v6; // r11
  __m128 v7; // xmm7
  __int64 v8; // rbx
  __m128 v9; // xmm0
  __m128 v10; // xmm1
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm6
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm4
  __m128 v18; // xmm5
  __m128 v19; // xmm6
  __m128 v20; // xmm4
  __m128 v21; // xmm5
  __m128 v22; // xmm0
  int v23; // eax
  signed __int64 result; // rax

  v4 = hkpCollideTriangleUtil::vertexToEdgeLut;
  v5 = tetra;
  v6 = 3i64;
  do
  {
    v7 = oldDots->m_quad;
    v8 = *v4;
    v9 = _mm_and_ps((__m128)`hkVector4f::getComponent'::`2'::indexToMask[v4[2]], oldDots->m_quad);
    v10 = _mm_or_ps(_mm_shuffle_ps(v9, v9, 78), v9);
    if ( COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v10, v10, 177) | v10.m128_i32[0]) >= 0.0 )
    {
      v11 = _mm_and_ps((__m128)`hkVector4f::getComponent'::`2'::indexToMask[v8], v7);
      v12 = _mm_or_ps(_mm_shuffle_ps(v11, v11, 78), v11);
      if ( COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v12, v12, 177) | v12.m128_i32[0]) >= 0.0 )
      {
        v13 = _mm_sub_ps(tetra[v4[2]].m_quad, v5->m_quad);
        v14 = _mm_sub_ps(tetra[3].m_quad, v5->m_quad);
        v15 = _mm_mul_ps(v14, v13);
        v16 = _mm_sub_ps(tetra[v8].m_quad, v5->m_quad);
        v17 = _mm_sub_ps(a0->m_quad, v5->m_quad);
        v18 = v17;
        v19 = _mm_mul_ps(v14, v16);
        v20 = _mm_mul_ps(v17, v16);
        v21 = _mm_mul_ps(v18, v13);
        if ( (float)((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 170)))
                           * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 170))))
                   - (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 170)))
                           * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 170))))) >= 0.0 )
          v22 = (__m128)`hkVector4f::getComponent'::`2'::indexToMask[v4[2]];
        else
          v22 = (__m128)`hkVector4f::getComponent'::`2'::indexToMask[v8];
        oldDots->m_quad = _mm_or_ps(_mm_andnot_ps(v22, v7), _mm_and_ps(v22, g_vectorfConstants[0]));
      }
    }
    ++v4;
    ++v5;
    --v6;
  }
  while ( v6 );
  v23 = _mm_movemask_ps(_mm_cmpltps((__m128)0i64, oldDots->m_quad));
  if ( v23 & 7 )
    result = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[v23];
  else
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 143
// RVA: 0xDB9C40
void hkpGsk::codeBegin(void)
{
  ;
}

// File Line: 147
// RVA: 0xDBA470
__int64 __fastcall hkpGsk::checkTriangleBoundaries(hkpGsk *this, hkVector4f *a, hkVector4f *b, hkpGsk::SupportTypes checkSupport)
{
  __m128 v4; // xmm2
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
  __m128 v18; // xmm10
  __m128 v19; // xmm8
  __m128 v20; // xmm9
  __m128 v21; // xmm1
  __m128 v22; // xmm9
  __m128 v23; // xmm2
  hkVector4f v24; // xmm10
  __int64 result; // rax
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  hkVector4f v28; // xmm1
  int v29; // xmm0_4

  v4 = b[1].m_quad;
  v5 = b[2].m_quad;
  v6 = _mm_sub_ps(b[1].m_quad, b->m_quad);
  v7 = _mm_sub_ps(b->m_quad, v5);
  v8 = _mm_sub_ps(a->m_quad, v4);
  v9 = _mm_sub_ps(b[2].m_quad, v4);
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
  v21 = _mm_unpacklo_ps(v18, v19);
  v22 = _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v15.m_quad);
  v23 = _mm_movelh_ps(v21, v22);
  v24.m_quad = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v18, v19), v22, 228),
                 _mm_add_ps(v23, _mm_shuffle_ps(_mm_movehl_ps(v23, v21), v22, 212)));
  this->m_checkTriangleDots = (hkVector4f)v24.m_quad;
  result = _mm_movemask_ps(_mm_cmpltps(v24.m_quad, (__m128)0i64)) & 7;
  if ( checkSupport )
  {
    this->m_support = (hkVector4f)v15.m_quad;
    if ( (_DWORD)result == 7 )
    {
      v26 = _mm_mul_ps(_mm_sub_ps(this->m_verticesA[0].m_quad, this->m_verticesBinA[0].m_quad), v15.m_quad);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 170))) < 0.0 )
      {
        this->m_support.m_quad = _mm_xor_ps(
                                   (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                   v15.m_quad);
        v27 = b->m_quad;
        *b = (hkVector4f)b[1].m_quad;
        b[1] = (hkVector4f)v27;
        v28.m_quad = (__m128)b[4];
        b[4] = (hkVector4f)b[5].m_quad;
        b[5] = (hkVector4f)v28.m_quad;
        v29 = this->m_checkTriangleDots.m_quad.m128_i32[0];
        this->m_checkTriangleDots.m_quad.m128_i32[0] = this->m_checkTriangleDots.m_quad.m128_i32[1];
        this->m_checkTriangleDots.m_quad.m128_i32[1] = v29;
        this->m_featureChange.m_storage = 1;
      }
    }
  }
  return result;
}

// File Line: 207
// RVA: 0xDBB1E0
signed __int64 __fastcall findClosestTriangle(hkVector4f *a0, hkVector4f *tetra, float sign)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm3
  __m128 v5; // xmm5
  __m128 v6; // xmm6
  __m128 v7; // xmm4
  float v8; // xmm10_4
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
  __m128 v19; // xmm9
  __m128 v20; // xmm8
  __m128 v21; // xmm5
  __m128 v22; // xmm5
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  __m128 v25; // xmm0
  __m128 v26; // xmm5
  __m128 v27; // xmm1
  __m128 v28; // xmm7
  __m128 v29; // xmm0
  __m128 v30; // xmm2
  __m128i v31; // xmm7
  __m128 v32; // xmm9
  __m128 v33; // xmm2
  __m128 v34; // xmm9
  __m128 v35; // xmm2
  __m128 v36; // xmm0
  __m128 v37; // xmm3
  __m128 v38; // xmm2
  __m128 v39; // xmm1
  __m128 v40; // xmm6
  __m128 v41; // xmm4
  __m128 v42; // xmm6
  __m128 v43; // xmm8
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm8
  __m128 v47; // xmm2
  __m128 v48; // xmm6
  float v49; // xmm2_4
  hkVector4f oldDots; // [rsp+20h] [rbp-68h]
  float v52; // [rsp+A0h] [rbp+18h]

  v52 = sign;
  v3 = tetra[1].m_quad;
  v4 = tetra[2].m_quad;
  v5 = _mm_sub_ps(tetra->m_quad, v4);
  v6 = _mm_sub_ps(tetra[1].m_quad, tetra->m_quad);
  v7 = _mm_sub_ps(tetra[2].m_quad, v3);
  v8 = sign;
  v9 = _mm_sub_ps(tetra[3].m_quad, tetra->m_quad);
  v10 = _mm_sub_ps(tetra[3].m_quad, v3);
  v11 = _mm_sub_ps(tetra[3].m_quad, v4);
  v12 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v7), _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v10));
  v13 = _mm_shuffle_ps(v12, v12, 201);
  v14 = _mm_mul_ps(
          _mm_shuffle_ps((__m128)LODWORD(v52), (__m128)LODWORD(v52), 0),
          _mm_sub_ps(a0->m_quad, tetra[3].m_quad));
  v15 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v5), _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v11));
  v16 = _mm_shuffle_ps(v15, v15, 201);
  v17 = _mm_unpackhi_ps(v13, v16);
  v18 = _mm_unpacklo_ps(v13, v16);
  v19 = _mm_mul_ps(v13, v13);
  v20 = _mm_mul_ps(v16, v16);
  v21 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v6), _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v9));
  v22 = _mm_shuffle_ps(v21, v21, 201);
  v23 = _mm_shuffle_ps(v17, v22, 228);
  v24 = _mm_movelh_ps(v18, v22);
  v25 = _mm_shuffle_ps(_mm_movehl_ps(v24, v18), v22, 212);
  v26 = _mm_mul_ps(v22, v22);
  v27 = _mm_unpacklo_ps(v19, v20);
  v28 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v25);
  v29 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v24);
  v30 = _mm_movelh_ps(v27, v26);
  v31 = (__m128i)_mm_add_ps(_mm_add_ps(v28, v29), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v23));
  v32 = _mm_add_ps(
          _mm_shuffle_ps(_mm_unpackhi_ps(v19, v20), v26, 228),
          _mm_add_ps(v30, _mm_shuffle_ps(_mm_movehl_ps(v30, v27), v26, 212)));
  v33 = v32;
  v34 = _mm_max_ps(v32, *(__m128 *)&epsilon);
  v35 = _mm_cmpeqps(v33, (__m128)0i64);
  v36 = _mm_rcp_ps(v34);
  v37 = _mm_or_ps(
          _mm_and_ps(v35, (__m128)xmmword_141A712A0),
          _mm_andnot_ps(
            v35,
            _mm_mul_ps(
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v34, v36)), v36),
              _mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v31, 1u), 1u), (__m128)v31))));
  v38 = _mm_shuffle_ps(v37, v37, 85);
  v39 = _mm_shuffle_ps(v37, v37, 0);
  v40 = _mm_shuffle_ps(v37, v37, 170);
  v41 = v40;
  v42 = _mm_min_ps(v40, _mm_min_ps(v38, v39));
  v43 = _mm_max_ps(v41, _mm_max_ps(v38, v39));
  v44 = _mm_unpacklo_ps(v43, v43);
  v45 = _mm_cmpleps(v43, v37);
  v46 = _mm_and_ps(v45, (__m128)xmmword_141A9E180);
  v47 = _mm_or_ps(_mm_andnot_ps(v45, v37), _mm_and_ps(v45, v42));
  v48 = _mm_movelh_ps(
          _mm_unpacklo_ps(
            v42,
            _mm_max_ps(
              _mm_shuffle_ps(v47, v47, 170),
              _mm_max_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)))),
          v44);
  LODWORD(v49) = (unsigned __int128)_mm_shuffle_ps(v48, v48, 170);
  if ( v49 < 0.00000011920929 )
    return 0xFFFFFFFFi64;
  if ( v49 > (float)(COERCE_FLOAT(_mm_shuffle_ps(v48, v48, 85))
                   * COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_1_1), (__m128)LODWORD(FLOAT_1_1), 0))) )
    return (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(v46)];
  _mm_store_si128((__m128i *)&oldDots, v31);
  return findClosestTriangleBackup(a0, tetra, &oldDots, v8);
}

// File Line: 319
// RVA: 0xDBB470
void __fastcall process_point_edge(hkVector4f *vertexA, hkVector4f *vertexB, hkPadSpu<int> *dimB, hkVector4f *support, hkpGsk::SupportTypes stype)
{
  __m128 v5; // xmm7
  hkVector4f v6; // xmm9
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

  v5 = vertexA->m_quad;
  v6.m_quad = (__m128)vertexB[1];
  v7 = _mm_sub_ps(v6.m_quad, vertexB->m_quad);
  v8 = _mm_sub_ps(vertexB[1].m_quad, vertexA->m_quad);
  v9 = _mm_sub_ps(vertexB->m_quad, vertexA->m_quad);
  v10 = _mm_mul_ps(v7, v8);
  v11 = _mm_mul_ps(v7, v9);
  v12 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 170));
  if ( v12 < 0.0 == (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85))
                                  + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))
                          + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170))) < 0.0 )
  {
    if ( v12 < 0.0 )
    {
      v22.m_quad = (__m128)vertexB[5];
      *vertexB = (hkVector4f)v6.m_quad;
      vertexB[4] = (hkVector4f)v22.m_quad;
    }
    --dimB->m_storage;
    if ( stype == 1 )
    {
      support->m_quad = _mm_sub_ps(v5, vertexB->m_quad);
      return;
    }
    v20.m_quad = _mm_sub_ps(vertexB->m_quad, v5);
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
    v17 = _mm_mul_ps(v16, v14);
    v18 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v16);
    if ( stype != 1 )
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
signed __int64 __fastcall hkpGsk::processEdgeTriangle(hkpGsk *this, hkVector4f *vertexA, hkVector4f *vertexB, hkPadSpu<int> *dimA, hkPadSpu<int> *dimB, hkBool comingFromEdgeEdge, hkpGsk::SupportTypes supportType)
{
  hkPadSpu<int> *v7; // rbp
  hkVector4f *v8; // rbx
  hkVector4f *v9; // rdi
  hkpGsk *v10; // rsi
  __m128 v11; // xmm2
  __m128 v12; // xmm6
  hkVector4f v13; // xmm5
  __m128 v14; // xmm3
  __m128 v15; // xmm3
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  signed __int64 result; // rax
  __m128 v24; // xmm0
  hkVector4f v25; // xmm1
  _BOOL8 v26; // rcx
  hkVector4f v27; // xmm3
  __m128 v28; // xmm4
  hkVector4f v29; // xmm6
  __m128 v30; // xmm1
  __m128 v31; // xmm7
  __m128 v32; // xmm1
  __m128 v33; // xmm5
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  int v36; // eax
  hkVector4f v37; // xmm0
  hkVector4f v38; // xmm0
  float v39; // xmm2_4
  float v40; // xmm6_4
  float v41; // xmm2_4
  float v42; // xmm6_4
  hkVector4f v43; // xmm1
  float v44; // xmm2_4
  float v45; // xmm6_4
  hkVector4f v46; // xmm1
  hkVector4f a; // [rsp+30h] [rbp-108h]
  hkVector4f v48; // [rsp+40h] [rbp-F8h]
  hkVector4f dB; // [rsp+50h] [rbp-E8h]
  hkLineSegmentUtil::ClosestLineSegLineSegResult v50; // [rsp+60h] [rbp-D8h]
  hkLineSegmentUtil::ClosestLineSegLineSegResult v51; // [rsp+B0h] [rbp-88h]

  v7 = dimA;
  v8 = vertexB;
  v9 = vertexA;
  v10 = this;
  if ( !comingFromEdgeEdge.m_bool )
  {
    v27.m_quad = (__m128)this->m_support;
    v28 = vertexA[1].m_quad;
    v29.m_quad = (__m128)this->m_checkTriangleDots;
    v30 = _mm_mul_ps(_mm_sub_ps(v28, vertexB->m_quad), v27.m_quad);
    v31 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
            _mm_shuffle_ps(v30, v30, 170));
    v32 = _mm_mul_ps(_mm_sub_ps(vertexA->m_quad, vertexB->m_quad), v27.m_quad);
    v33 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
            _mm_shuffle_ps(v32, v32, 170));
    if ( (float)(v33.m128_f32[0] * v31.m128_f32[0]) < 0.0 )
    {
      v34 = _mm_sub_ps(v33, v31);
      v35 = _mm_rcp_ps(v34);
      v48.m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(v28, vertexA->m_quad),
                       _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v35, v34)), v35), v33)),
                     vertexA->m_quad);
      if ( (unsigned int)hkpGsk::checkTriangleBoundaries(this, &v48, vertexB, 0) == 7 )
        return 1i64;
    }
    v36 = hkpGsk::checkTriangleBoundaries(v10, v9 + 1, v8, 0);
    if ( v36 == 7 )
    {
      v37.m_quad = (__m128)v9[1];
      --v7->m_storage;
      *v9 = (hkVector4f)v37.m_quad;
      v38.m_quad = (__m128)v9[5];
      v10->m_supportState = supportType;
      result = 0i64;
      v9[4] = (hkVector4f)v38.m_quad;
      return result;
    }
    if ( v36 != 6 )
    {
      switch ( v36 )
      {
        case 5:
$remove_b1:
          v46.m_quad = (__m128)v8[6];
          v8[1] = (hkVector4f)v8[2].m_quad;
          v8[5] = (hkVector4f)v46.m_quad;
          goto $remove_b2;
        case 3:
$remove_b2:
          --dimB->m_storage;
          return 2i64;
        case 1:
          LODWORD(v39) = (unsigned __int128)_mm_shuffle_ps(v29.m_quad, v29.m_quad, 85);
          LODWORD(v40) = (unsigned __int128)_mm_shuffle_ps(v29.m_quad, v29.m_quad, 170);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v10->m_checkTriangleDots.m_quad, v10->m_checkTriangleDots.m_quad, 85))
                             - v39)
                     * v40) <= (float)((float)(COERCE_FLOAT(
                                                 _mm_shuffle_ps(
                                                   v10->m_checkTriangleDots.m_quad,
                                                   v10->m_checkTriangleDots.m_quad,
                                                   170))
                                             - v40)
                                     * v39) )
            goto $remove_b1;
          goto $remove_b2;
        case 2:
          LODWORD(v41) = (unsigned __int128)_mm_shuffle_ps(v29.m_quad, v29.m_quad, 170);
          LODWORD(v42) = (unsigned __int128)_mm_shuffle_ps(v29.m_quad, v29.m_quad, 0);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v10->m_checkTriangleDots.m_quad, v10->m_checkTriangleDots.m_quad, 170))
                             - v41)
                     * v42) <= (float)((float)(COERCE_FLOAT(
                                                 _mm_shuffle_ps(
                                                   v10->m_checkTriangleDots.m_quad,
                                                   v10->m_checkTriangleDots.m_quad,
                                                   0))
                                             - v42)
                                     * v41) )
            goto $remove_b2;
          break;
        case 4:
          LODWORD(v44) = (unsigned __int128)_mm_shuffle_ps(v29.m_quad, v29.m_quad, 0);
          LODWORD(v45) = (unsigned __int128)_mm_shuffle_ps(v29.m_quad, v29.m_quad, 85);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v10->m_checkTriangleDots.m_quad, v10->m_checkTriangleDots.m_quad, 0))
                             - v44)
                     * v45) > (float)((float)(COERCE_FLOAT(
                                                _mm_shuffle_ps(
                                                  v10->m_checkTriangleDots.m_quad,
                                                  v10->m_checkTriangleDots.m_quad,
                                                  85))
                                            - v45)
                                    * v44) )
            goto $remove_b1;
          break;
      }
    }
    v43.m_quad = (__m128)v8[6];
    *v8 = (hkVector4f)v8[2].m_quad;
    v8[4] = (hkVector4f)v43.m_quad;
    goto $remove_b2;
  }
  v11 = vertexB->m_quad;
  v12 = vertexA->m_quad;
  v13.m_quad = (__m128)vertexA[1];
  dB.m_quad = _mm_sub_ps(vertexB[1].m_quad, vertexB[2].m_quad);
  v14 = _mm_sub_ps(v11, vertexB[2].m_quad);
  v48.m_quad = v14;
  v15 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), dB.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(dB.m_quad, dB.m_quad, 201), v14));
  v16 = _mm_shuffle_ps(v15, v15, 201);
  v17 = _mm_mul_ps(_mm_sub_ps(v12, v11), v16);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_mul_ps(_mm_sub_ps(v13.m_quad, v11), v16);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  if ( v18.m128_f32[0] < 0.0 == v20.m128_f32[0] < 0.0 )
  {
    if ( COERCE_FLOAT((unsigned int)(2 * v18.m128_i32[0]) >> 1) > COERCE_FLOAT((unsigned int)(2 * v20.m128_i32[0]) >> 1) )
    {
      v24 = vertexA->m_quad;
      *vertexA = (hkVector4f)v13.m_quad;
      vertexA[1] = (hkVector4f)v24;
      v25.m_quad = (__m128)vertexA[4];
      vertexA[4] = (hkVector4f)vertexA[5].m_quad;
      vertexA[5] = (hkVector4f)v25.m_quad;
    }
    if ( (unsigned int)hkpGsk::checkTriangleBoundaries(this, vertexA, vertexB, BUILD_POS_SUPPORT) == 7 )
    {
      --v7->m_storage;
      return 0i64;
    }
  }
  else
  {
    v21 = _mm_sub_ps(v18, v20);
    v22 = _mm_rcp_ps(v21);
    a.m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(v13.m_quad, v12),
                   _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v21)), v22), v18)),
                 v12);
    if ( (unsigned int)hkpGsk::checkTriangleBoundaries(this, &a, vertexB, 0) == 7 )
      return 1i64;
  }
  a.m_quad = _mm_sub_ps(v9[1].m_quad, v9->m_quad);
  hkLineSegmentUtil::closestLineSegLineSeg(v9, &a, v8 + 2, &dB, &v50);
  hkLineSegmentUtil::closestLineSegLineSeg(v9, &a, v8 + 2, &v48, &v51);
  v26 = v50.m_distanceSquared.m_storage > v51.m_distanceSquared.m_storage;
  v8[v26] = (hkVector4f)v8[2].m_quad;
  v8[v26 + 4] = (hkVector4f)v8[6].m_quad;
  --dimB->m_storage;
  return 2i64;
}51);
  v26 = v50.m_distanceSquared.m_storage > v51.m_distanceSquared.m_storage;
  v8[v2

// File Line: 797
// RVA: 0xDBB5B0
hkSimdFloat32 *__fastcall hkGskCalcSupportDistSquared(hkSimdFloat32 *result, hkVector4f *support, hkVector4f *newPoint, hkVector4f *oldPoint)
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
signed __int64 __fastcall hkpGsk::getClosestFeature(hkpGsk *this, hkpConvexShape *shapeA, hkpConvexShape *shapeB, hkTransformf *aTb, hkVector4f *separatingNormalOut)
{
  hkVector4f v5; // xmm3
  hkVector4f v6; // xmm4
  hkVector4f v7; // xmm5
  hkPadSpu<int> *dimB; // rdi
  hkpGsk *v9; // rbx
  hkTransformf *v10; // r15
  hkpConvexShape *v11; // r13
  hkVector4f v12; // xmm6
  __int64 v13; // rcx
  __m128 *v14; // rax
  __m128 v15; // xmm1
  char v16; // r12
  __m128 *v17; // rbp
  __m128 v18; // xmm7
  int v19; // er14
  int v20; // eax
  unsigned int v21; // eax
  hkpGsk::NextCase v22; // eax
  int v23; // eax
  __m128 v24; // xmm1
  int v25; // eax
  hkcdVertex v26; // xmm1
  int v27; // eax
  int v28; // eax
  int v29; // ecx
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
  signed __int64 v41; // rax
  signed __int64 v42; // rcx
  hkcdVertex v43; // xmm0
  int v44; // eax
  int v45; // eax
  __int64 v46; // rcx
  __int64 v47; // r8
  __int64 v48; // rdx
  __m128 v49; // xmm0
  signed __int64 v50; // rax
  __m128 v51; // xmm2
  __m128 v52; // xmm4
  __m128 v53; // xmm3
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm3
  int v57; // eax
  hkPadSpu<int> v58; // eax
  signed int v59; // edx
  __m128 v60; // xmm3
  __m128 v61; // xmm3
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
  __m128 v77; // xmm0
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
  __m128 v94; // xmm1
  __int64 v95; // rcx
  __m128 v96; // xmm4
  __m128 v97; // xmm1
  float v98; // xmm2_4
  __m128 v99; // xmm1
  float v100; // xmm3_4
  float v101; // xmm6_4
  hkBaseObjectVtbl *v102; // rax
  __int64 v103; // rdx
  __m128 v104; // xmm3
  __m128 v105; // xmm1
  float v106; // xmm2_4
  __m128 v107; // xmm1
  float v108; // xmm2_4
  __m128 v109; // xmm3
  float v110; // xmm1_4
  __int64 v111; // rcx
  __m128 v112; // xmm4
  hkBaseObjectVtbl *v113; // rax
  __m128 v114; // xmm1
  __m128 v115; // xmm2
  __m128 v116; // xmm0
  __m128 v117; // xmm1
  __int64 v118; // rcx
  signed __int64 v119; // rdx
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
  __m128 v137; // xmm5
  __m128 v138; // xmm1
  __m128 v139; // xmm3
  __m128 v140; // xmm2
  __m128 v141; // xmm4
  __m128 v142; // xmm6
  hkVector4f v143; // xmm2
  signed __int64 result; // rax
  hkVector4f dB; // [rsp+40h] [rbp-E8h]
  hkVector4f dA; // [rsp+50h] [rbp-D8h]
  __m128 v147; // [rsp+60h] [rbp-C8h]
  __m128 v148; // [rsp+70h] [rbp-B8h]
  __m128 v149; // [rsp+80h] [rbp-A8h]
  hkpConvexShape *shapeBa; // [rsp+140h] [rbp+18h]

  shapeBa = shapeB;
  v5.m_quad = (__m128)aTb->m_rotation.m_col0;
  v6.m_quad = (__m128)aTb->m_rotation.m_col1;
  v7.m_quad = (__m128)aTb->m_rotation.m_col2;
  dimB = &this->m_dimB;
  v9 = this;
  v10 = aTb;
  v11 = shapeA;
  v12.m_quad = (__m128)aTb->m_translation;
  v13 = this->m_dimB.m_storage - 1;
  v14 = (__m128 *)((char *)v9 + 16 * (v13 + 14));
  do
  {
    v15 = *v14;
    --v14;
    --v13;
    v14[-3] = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), v6.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v5.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), v7.m_quad)),
                v12.m_quad);
  }
  while ( v13 >= 0 );
  v16 = 0;
  v17 = (__m128 *)v9->m_verticesBinA;
  v18 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_192093eN10), (__m128)LODWORD(FLOAT_1_192093eN10), 0);
LABEL_4:
  ++v16;
  v18 = _mm_add_ps(v18, v18);
  v19 = v9->m_dimA.m_storage + dimB->m_storage;
  v20 = dimB->m_storage | 8 * v9->m_dimA.m_storage;
  v9->m_supportState = 0;
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
        v27 = findClosestTriangle((hkVector4f *)v9->m_verticesA, v9->m_verticesBinA, 1.0);
        if ( v27 < 0 )
          goto LABEL_62;
        --dimB->m_storage;
        *((_OWORD *)&v9->m_dimA.m_storage + v27 + 10i64) = v9->m_verticesBinA[3];
        *((_OWORD *)&v9->m_dimA.m_storage + v27 + 14i64) = v9->m_verticesBinB[3];
LABEL_21:
        v28 = hkpGsk::checkTriangleBoundaries(v9, (hkVector4f *)v9->m_verticesA, v9->m_verticesBinA, BUILD_POS_SUPPORT);
        if ( v28 == 7 )
          goto LABEL_61;
        v29 = hkpCollideTriangleUtil::maskToIndex[v28];
        if ( v29 >= 0 )
        {
          v30 = hkpCollideTriangleUtil::vertexToEdgeLut[hkpCollideTriangleUtil::maskToIndex[v28]];
          v31 = hkpCollideTriangleUtil::vertexToEdgeLut[hkpCollideTriangleUtil::maskToIndex[v28] + 2];
          v32 = v9->m_verticesBinA[hkpCollideTriangleUtil::maskToIndex[v28]].m_quad;
          v33 = _mm_sub_ps(v9->m_verticesBinA[v30].m_quad, v32);
          v34 = _mm_sub_ps(v9->m_verticesA[0].m_quad, v32);
          v35 = v9->m_verticesBinA[v31].m_quad;
          dimB->m_storage = 2;
          v36 = _mm_mul_ps(v33, v34);
          v37 = _mm_sub_ps(v35, v32);
          v38.m_quad = (__m128)v9->m_verticesBinA[2];
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 170))) >= 0.0 )
          {
            v9->m_verticesBinA[v31] = (hkVector4f)v38.m_quad;
            v43.m_quad = (__m128)v9->m_verticesBinB[2];
            v41 = v31 + 14;
          }
          else
          {
            v39 = _mm_mul_ps(v37, v34);
            v9->m_verticesBinA[v30] = (hkVector4f)v38.m_quad;
            *((_OWORD *)&v9->m_dimA.m_storage + v30 + 14) = v9->m_verticesBinB[2];
            if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 0)))
                       + COERCE_FLOAT(_mm_shuffle_ps(v39, v39, 170))) >= 0.0 )
              goto LABEL_41;
            if ( (_DWORD)v31 == dimB->m_storage )
              LODWORD(v31) = v30;
            v40 = dimB->m_storage - 1;
            dimB->m_storage = v40;
            *((_OWORD *)&v9->m_dimA.m_storage + (signed int)v31 + 10i64) = *((_OWORD *)&v9->m_dimA.m_storage
                                                                           + v40
                                                                           + 10i64);
            v41 = (signed int)v31 + 14i64;
            v42 = dimB->m_storage + 14i64;
LABEL_38:
            v43.m_quad = (__m128)*((_OWORD *)&v9->m_dimA.m_storage + v42);
          }
          v50 = 2 * v41;
LABEL_40:
          *(hkcdVertex *)(&v9->m_dimA.m_storage + 2 * v50) = (hkcdVertex)v43.m_quad;
LABEL_41:
          v21 = (dimB->m_storage | 8 * v9->m_dimA.m_storage) - 9;
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
        *((_OWORD *)&v9->m_dimA.m_storage + v64 + 10i64) = v9->m_verticesBinA[2];
        *((_OWORD *)&v9->m_dimA.m_storage + v64 + 14i64) = v9->m_verticesBinB[2];
LABEL_46:
        v65 = v9->m_verticesBinA[1].m_quad;
        v66 = _mm_sub_ps(v65, v9->m_verticesA[0].m_quad);
        v67 = _mm_sub_ps(v9->m_verticesBinA[1].m_quad, v9->m_verticesBinA[0].m_quad);
        v68 = _mm_sub_ps(*v17, v9->m_verticesA[0].m_quad);
        v69 = _mm_mul_ps(v66, v67);
        v70 = _mm_mul_ps(v68, v67);
        v71 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 0)))
            + COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 170));
        if ( v71 < 0.0 == (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v70, v70, 85))
                                        + COERCE_FLOAT(_mm_shuffle_ps(v70, v70, 0)))
                                + COERCE_FLOAT(_mm_shuffle_ps(v70, v70, 170))) < 0.0 )
        {
          if ( v71 < 0.0 )
          {
            v92.m_quad = (__m128)v9->m_verticesBinB[1];
            *v17 = v65;
            v9->m_verticesBinB[0] = (hkcdVertex)v92.m_quad;
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
        v76 = _mm_sub_ps(_mm_mul_ps(v75, v73), _mm_mul_ps(_mm_shuffle_ps(v73, v73, 201), v75));
        v77 = _mm_shuffle_ps(v76, v76, 201);
LABEL_60:
        v9->m_support.m_quad = v77;
LABEL_61:
        v59 = 0;
        v9->m_lastDimB = (hkPadSpu<int>)dimB->m_storage;
LABEL_63:
        v94 = v9->m_support.m_quad;
        v95 = v9->m_dimA.m_storage;
        v96 = v9->m_support.m_quad;
        v9->m_featureChange.m_storage |= dimB->m_storage + v9->m_dimA.m_storage - v19;
        v97 = _mm_mul_ps(v94, v94);
        v98 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v97, v97, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v97, v97, 0)))
            + COERCE_FLOAT(_mm_shuffle_ps(v97, v97, 170));
        v99 = _mm_mul_ps(_mm_sub_ps(v9->m_verticesA[0].m_quad, *v17), v96);
        v100 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v99, v99, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v99, v99, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v99, v99, 170));
        if ( v59
          || (v101 = v18.m128_f32[0] * v98,
              (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v100)) >> 1) * v100) <= (float)(v18.m128_f32[0] * v98))
          || v98 < v18.m128_f32[0] )
        {
          if ( !v9->m_doNotHandlePenetration.m_storage )
          {
            hkpGsk::handlePenetration(v9, v11, shapeBa, v10);
            goto LABEL_94;
          }
          if ( v9->m_dimA.m_storage + dimB->m_storage > 4 )
          {
            if ( v9->m_dimA.m_storage <= dimB->m_storage )
            {
              v9->m_dimA.m_storage = 1;
              dimB->m_storage = 3;
            }
            else
            {
              v9->m_dimA.m_storage = 3;
              dimB->m_storage = 1;
            }
          }
          result = 4i64;
        }
        else
        {
          if ( !(v16 & 1) )
            goto LABEL_75;
          if ( (_DWORD)v95 == v9->m_maxDimA.m_storage )
            goto LABEL_75;
          if ( v9->m_supportState == 1 )
            goto LABEL_75;
          v102 = v11->vfptr;
          v147 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v96);
          ((void (__fastcall *)(hkpConvexShape *, __m128 *, signed __int64))v102[4].__vecDelDtor)(
            v11,
            &v147,
            (signed __int64)v9 + 16 * (v95 + 2));
          v103 = v9->m_dimA.m_storage;
          v104 = v9->m_verticesA[v103].m_quad;
          v105 = _mm_mul_ps(_mm_sub_ps(v9->m_verticesA[v103].m_quad, v9->m_verticesA[0].m_quad), v147);
          v106 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v105, v105, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v105, v105, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v105, v105, 170));
          if ( (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v106)) >> 1) * v106) <= v101 )
            goto LABEL_75;
          if ( (_DWORD)v103 == 2 )
            goto LABEL_73;
          if ( (_DWORD)v103 != 3 )
            goto LABEL_74;
          v107 = _mm_mul_ps(_mm_sub_ps(v104, v9->m_verticesA[2].m_quad), v147);
          v108 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v107, v107, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v107, v107, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v107, v107, 170));
          if ( (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v108)) >> 1) * v108) >= v101 )
          {
LABEL_73:
            v109 = _mm_mul_ps(_mm_sub_ps(v104, v9->m_verticesA[1].m_quad), v147);
            v110 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v109, v109, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v109, v109, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v109, v109, 170));
            if ( (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v110)) >> 1) * v110) >= v101 )
              goto LABEL_74;
          }
LABEL_75:
          v111 = dimB->m_storage;
          if ( (_DWORD)v111 == v9->m_maxDimB.m_storage )
            goto LABEL_83;
          if ( v9->m_supportState == -1 )
            goto LABEL_83;
          v112 = v10->m_rotation.m_col2.m_quad;
          v113 = shapeBa->vfptr;
          v114 = _mm_unpacklo_ps(v10->m_rotation.m_col0.m_quad, v10->m_rotation.m_col1.m_quad);
          v115 = _mm_movelh_ps(v114, v112);
          v116 = _mm_movehl_ps(v115, v114);
          v117 = v9->m_support.m_quad;
          v148 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v117, v117, 85), _mm_shuffle_ps(v116, v112, 212)),
                     _mm_mul_ps(_mm_shuffle_ps(v9->m_support.m_quad, v117, 0), v115)),
                   _mm_mul_ps(
                     _mm_shuffle_ps(
                       _mm_unpackhi_ps(v10->m_rotation.m_col0.m_quad, v10->m_rotation.m_col1.m_quad),
                       v112,
                       228),
                     _mm_shuffle_ps(v117, v117, 170)));
          ((void (__fastcall *)(hkpConvexShape *, __m128 *, signed __int64))v113[4].__vecDelDtor)(
            shapeBa,
            &v148,
            (signed __int64)v9 + 16 * (v111 + 14));
          v118 = dimB->m_storage;
          v119 = 2 * (v118 + 14);
          v120 = v9->m_verticesBinB[v118].m_quad;
          v121 = _mm_mul_ps(_mm_sub_ps(v9->m_verticesBinB[v118].m_quad, v9->m_verticesBinB[0].m_quad), v148);
          v115.m128_f32[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v121, v121, 85))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v121, v121, 0)))
                           + COERCE_FLOAT(_mm_shuffle_ps(v121, v121, 170));
          if ( (float)(COERCE_FLOAT((unsigned int)(2 * v115.m128_i32[0]) >> 1) * v115.m128_f32[0]) <= v101 )
            goto LABEL_83;
          v122 = v118 - 2;
          if ( !v122 )
            goto LABEL_81;
          if ( v122 != 1 )
          {
LABEL_82:
            v127 = *(__m128 *)(&v9->m_dimA.m_storage + 2 * v119);
            v9->m_verticesBinA[dimB->m_storage++] = (hkVector4f)_mm_add_ps(
                                                                  _mm_add_ps(
                                                                    _mm_add_ps(
                                                                      _mm_mul_ps(
                                                                        _mm_shuffle_ps(v127, v127, 0),
                                                                        v10->m_rotation.m_col0.m_quad),
                                                                      _mm_mul_ps(
                                                                        _mm_shuffle_ps(
                                                                          *(__m128 *)(&v9->m_dimA.m_storage + 2 * v119),
                                                                          v127,
                                                                          85),
                                                                        v10->m_rotation.m_col1.m_quad)),
                                                                    _mm_mul_ps(
                                                                      _mm_shuffle_ps(v127, v127, 170),
                                                                      v10->m_rotation.m_col2.m_quad)),
                                                                  v10->m_translation.m_quad);
            v9->m_featureChange.m_storage = 1;
            goto LABEL_4;
          }
          v123 = _mm_mul_ps(_mm_sub_ps(v120, v9->m_verticesBinB[2].m_quad), v148);
          v124 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v123, v123, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v123, v123, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v123, v123, 170));
          if ( (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v124)) >> 1) * v124) >= v101 )
          {
LABEL_81:
            v125 = _mm_mul_ps(_mm_sub_ps(v120, v9->m_verticesBinB[1].m_quad), v148);
            v126 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v125, v125, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v125, v125, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v125, v125, 170));
            if ( (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v126)) >> 1) * v126) >= v101 )
              goto LABEL_82;
          }
LABEL_83:
          if ( v16 & 1 )
            goto LABEL_94;
          v128 = v9->m_dimA.m_storage;
          if ( (_DWORD)v128 == v9->m_maxDimA.m_storage )
            goto LABEL_94;
          if ( v9->m_supportState == 1 )
            goto LABEL_94;
          v129 = v11->vfptr;
          v149 = _mm_xor_ps(
                   (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                   v9->m_support.m_quad);
          ((void (__fastcall *)(hkpConvexShape *, __m128 *, signed __int64))v129[4].__vecDelDtor)(
            v11,
            &v149,
            (signed __int64)v9 + 16 * (v128 + 2));
          v103 = v9->m_dimA.m_storage;
          v130 = v9->m_verticesA[v103].m_quad;
          v131 = _mm_mul_ps(_mm_sub_ps(v9->m_verticesA[v103].m_quad, v9->m_verticesA[0].m_quad), v149);
          v132 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v131, v131, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v131, v131, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v131, v131, 170));
          if ( (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v132)) >> 1) * v132) <= v101 )
            goto LABEL_94;
          if ( (_DWORD)v103 == 2 )
            goto LABEL_90;
          if ( (_DWORD)v103 != 3 )
          {
LABEL_74:
            v9->m_featureChange.m_storage = 1;
            v9->m_dimA.m_storage = v103 + 1;
            goto LABEL_4;
          }
          v133 = _mm_mul_ps(_mm_sub_ps(v130, v9->m_verticesA[2].m_quad), v149);
          v134 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v133, v133, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v133, v133, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v133, v133, 170));
          if ( (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v134)) >> 1) * v134) >= v101 )
          {
LABEL_90:
            v135 = _mm_mul_ps(_mm_sub_ps(v130, v9->m_verticesA[1].m_quad), v149);
            v136 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v135, v135, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v135, v135, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v135, v135, 170));
            if ( (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v136)) >> 1) * v136) >= v101 )
            {
              v9->m_featureChange.m_storage = 1;
              v9->m_dimA.m_storage = v103 + 1;
              goto LABEL_4;
            }
          }
LABEL_94:
          v137 = v9->m_support.m_quad;
          v138 = _mm_mul_ps(v137, v137);
          v139 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v138, v138, 85), _mm_shuffle_ps(v138, v138, 0)),
                   _mm_shuffle_ps(v138, v138, 170));
          v140 = _mm_rsqrt_ps(v139);
          v141 = _mm_mul_ps(
                   _mm_andnot_ps(
                     _mm_cmpleps(v139, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v140, v139), v140)),
                       _mm_mul_ps(*(__m128 *)_xmm, v140))),
                   v137);
          v142 = _mm_mul_ps(_mm_sub_ps(v9->m_verticesA[0].m_quad, *v17), v141);
          v9->m_support.m_quad = v141;
          v143.m_quad = _mm_shuffle_ps(
                          v141,
                          _mm_unpackhi_ps(
                            v141,
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v142, v142, 85), _mm_shuffle_ps(v142, v142, 0)),
                              _mm_shuffle_ps(v142, v142, 170))),
                          196);
          *separatingNormalOut = (hkVector4f)v143.m_quad;
          v9->m_support = (hkVector4f)v143.m_quad;
          result = 0i64;
        }
        return result;
      case 8u:
        goto LABEL_50;
      case 9u:
        goto LABEL_10;
      case 0xAu:
        v22 = hkpGsk::processEdgeTriangle(
                v9,
                (hkVector4f *)v9->m_verticesA,
                v9->m_verticesBinA,
                &v9->m_dimA,
                dimB,
                (hkBool)(v9->m_lastDimB.m_storage == 2),
                BUILD_POS_SUPPORT);
        goto LABEL_8;
      case 0x10u:
        goto LABEL_31;
      case 0x11u:
        v22 = hkpGsk::processEdgeTriangle(
                v9,
                v9->m_verticesBinA,
                (hkVector4f *)v9->m_verticesA,
                dimB,
                &v9->m_dimA,
                (hkBool)(v9->m_lastDimB.m_storage == 2),
                BUILD_NEG_SUPPORT);
LABEL_8:
        v23 = v22 - 1;
        if ( !v23 )
          goto LABEL_62;
        if ( v23 != 1 )
          goto LABEL_61;
LABEL_10:
        v24 = _mm_sub_ps(v9->m_verticesBinA[1].m_quad, *v17);
        dA.m_quad = _mm_sub_ps(v9->m_verticesA[1].m_quad, v9->m_verticesA[0].m_quad);
        dB.m_quad = v24;
        v25 = hkLineSegmentUtil::closestLineSegLineSeg(
                (hkVector4f *)v9->m_verticesA,
                &dA,
                v9->m_verticesBinA,
                &dB,
                &v9->m_closestLineLineResult);
        if ( !v25 )
        {
          v58.m_storage = dimB->m_storage;
          v59 = 0;
          v60 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(dB.m_quad, dB.m_quad, 201), dA.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(dA.m_quad, dA.m_quad, 201), dB.m_quad));
          v61 = _mm_shuffle_ps(v60, v60, 201);
          v9->m_support.m_quad = v61;
          v62 = _mm_sub_ps(v9->m_verticesA[0].m_quad, *v17);
          v9->m_lastDimB = v58;
          v63 = _mm_mul_ps(v62, v61);
          v9->m_support.m_quad = _mm_xor_ps(
                                   (__m128)_mm_slli_epi32(
                                             _mm_srli_epi32(
                                               (__m128i)_mm_add_ps(
                                                          _mm_add_ps(
                                                            _mm_shuffle_ps(v63, v63, 85),
                                                            _mm_shuffle_ps(v63, v63, 0)),
                                                          _mm_shuffle_ps(v63, v63, 170)),
                                               0x1Fu),
                                             0x1Fu),
                                   v61);
          goto LABEL_63;
        }
        if ( v25 & 1 )
        {
          v9->m_verticesA[0] = v9->m_verticesA[1];
        }
        else if ( !(v25 & 2) )
        {
          goto LABEL_15;
        }
        v9->m_dimA.m_storage = 1;
LABEL_15:
        if ( v25 & 4 )
        {
          v26.m_quad = (__m128)v9->m_verticesBinB[1];
          *v17 = v9->m_verticesBinA[1].m_quad;
          v9->m_verticesBinB[0] = (hkcdVertex)v26.m_quad;
          dimB->m_storage = 1;
        }
        else if ( v25 & 8 )
        {
          dimB->m_storage = 1;
        }
        goto LABEL_41;
      case 0x18u:
        v44 = findClosestTriangle(v9->m_verticesBinA, (hkVector4f *)v9->m_verticesA, -1.0);
        if ( v44 < 0 )
          goto LABEL_62;
        --v9->m_dimA.m_storage;
        *((_OWORD *)&v9->m_dimA.m_storage + v44 + 2i64) = v9->m_verticesA[3];
LABEL_31:
        v45 = hkpGsk::checkTriangleBoundaries(v9, v9->m_verticesBinA, (hkVector4f *)v9->m_verticesA, BUILD_NEG_SUPPORT);
        if ( v45 == 7 )
          goto LABEL_61;
        v46 = hkpCollideTriangleUtil::maskToIndex[v45];
        if ( (signed int)v46 < 0 )
        {
          v78 = v46 + 8;
          if ( v78 != 7 )
          {
            --v9->m_dimA.m_storage;
            *((_OWORD *)&v9->m_dimA.m_storage + v78 + 2i64) = v9->m_verticesA[2];
LABEL_50:
            v79 = v9->m_verticesA[1].m_quad;
            v80 = v9->m_verticesA[0].m_quad;
            v81 = _mm_sub_ps(v79, *v17);
            v82 = _mm_sub_ps(v9->m_verticesA[1].m_quad, v80);
            v83 = _mm_sub_ps(v80, *v17);
            v84 = _mm_mul_ps(v81, v82);
            v85 = _mm_mul_ps(v83, v82);
            v86 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v84, v84, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v84, v84, 0)))
                + COERCE_FLOAT(_mm_shuffle_ps(v84, v84, 170));
            if ( v86 < 0.0 != (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v85, v85, 85))
                                            + COERCE_FLOAT(_mm_shuffle_ps(v85, v85, 0)))
                                    + COERCE_FLOAT(_mm_shuffle_ps(v85, v85, 170))) < 0.0 )
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
              v91 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v88, v88, 201), v90), _mm_mul_ps(v90, v88));
              v9->m_support.m_quad = _mm_shuffle_ps(v91, v91, 201);
              v9->m_lastDimB = (hkPadSpu<int>)dimB->m_storage;
              goto LABEL_63;
            }
            if ( v86 < 0.0 )
            {
              v93.m_quad = (__m128)v9->m_dummy[1];
              v9->m_verticesA[0].m_quad = v79;
              v9->m_dummy[0] = (hkVector4f)v93.m_quad;
            }
            --v9->m_dimA.m_storage;
$LN860_0:
            v77 = _mm_sub_ps(v9->m_verticesA[0].m_quad, *v17);
            goto LABEL_60;
          }
LABEL_55:
          v9->m_dimA.m_storage = 1;
          dimB->m_storage = 1;
          goto $LN860_0;
        }
        v47 = hkpCollideTriangleUtil::vertexToEdgeLut[hkpCollideTriangleUtil::maskToIndex[v45]];
        v48 = hkpCollideTriangleUtil::vertexToEdgeLut[hkpCollideTriangleUtil::maskToIndex[v45] + 2];
        v49 = v9->m_verticesA[v46].m_quad;
        v50 = 2 * (v48 + 2);
        v51 = _mm_sub_ps(v9->m_verticesA[v47].m_quad, v49);
        v52 = _mm_sub_ps(*v17, v49);
        v53 = v9->m_verticesA[v48].m_quad;
        v9->m_dimA.m_storage = 2;
        v54 = _mm_mul_ps(v51, v52);
        v55 = _mm_sub_ps(v53, v49);
        v43.m_quad = (__m128)v9->m_verticesA[2];
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v54, v54, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v54, v54, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v54, v54, 170))) >= 0.0 )
          goto LABEL_40;
        v56 = _mm_mul_ps(v55, v52);
        v9->m_verticesA[v47] = (hkcdVertex)v43.m_quad;
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v56, v56, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v56, v56, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v56, v56, 170))) >= 0.0 )
          goto LABEL_41;
        if ( (_DWORD)v48 == v9->m_dimA.m_storage )
          LODWORD(v48) = v47;
        v57 = v9->m_dimA.m_storage - 1;
        v9->m_dimA.m_storage = v57;
        v42 = v57 + 2i64;
        v41 = (signed int)v48 + 2i64;
        goto LABEL_38;
      default:
        goto LABEL_62;
    }
  }
}        + COERCE_FLOAT(_mm_shuffle_ps(v54, v54, 170))) >= 0.0 )
          goto LABEL_40;
        v56 = _mm_mul_ps

// File Line: 1101
// RVA: 0xDBA360
void __fastcall hkpGsk::exitAndExportCacheImpl(hkpGsk *this, hkpGskCache *cache)
{
  hkpGskCache *v2; // r8
  signed int v3; // er11
  unsigned __int16 v4; // r9
  unsigned __int16 v5; // r10
  signed int v6; // ebx
  unsigned __int16 v7; // dx
  unsigned __int16 v8; // ax
  int v9; // er9
  unsigned __int16 v10; // dx
  unsigned __int16 v11; // r10
  unsigned __int16 v12; // r9
  unsigned __int16 v13; // ax

  v2 = cache;
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
      v2->m_vertices[2] = v7;
    }
    v2->m_vertices[1] = v5;
  }
  v2->m_vertices[0] = v4;
  v9 = this->m_dimB.m_storage;
  v10 = this->m_verticesBinB[0].m_quad.m128_u16[6];
  if ( v9 >= 2 )
  {
    v11 = this->m_verticesBinB[1].m_quad.m128_u16[6];
    if ( v11 > v10 )
    {
      v11 = this->m_verticesBinB[0].m_quad.m128_u16[6];
      v3 = 1;
      v10 = this->m_verticesBinB[1].m_quad.m128_u16[6];
    }
    if ( v9 > 2 )
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
      v2->m_vertices[this->m_dimA.m_storage + 2] = v12;
    }
    v2->m_vertices[this->m_dimA.m_storage + 1] = v11;
  }
  v2->m_vertices[this->m_dimA.m_storage] = v10;
}

// File Line: 1147
// RVA: 0xDB99F0
void __fastcall hkpGsk::convertFeatureToClosestDistance(hkpGsk *this, hkVector4f *separatingNormal, hkpGskOut *out)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm0

  out->m_distance.m_storage = separatingNormal->m_quad.m128_f32[3];
  v3 = separatingNormal->m_quad;
  out->m_normalInA = (hkVector4f)separatingNormal->m_quad;
  if ( this->m_dimA.m_storage == 1 )
  {
    out->m_pointAinA = (hkVector4f)this->m_verticesA[0];
  }
  else
  {
    if ( this->m_dimB.m_storage == 1 )
      v4 = _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(separatingNormal->m_quad, separatingNormal->m_quad, 255), v3),
             this->m_verticesBinA[0].m_quad);
    else
      v4 = this->m_closestLineLineResult.m_closestPointA.m_quad;
    out->m_pointAinA.m_quad = v4;
  }
}

// File Line: 1171
// RVA: 0xDB9A40
hkResult *__fastcall hkpGsk::getClosestPoint(hkResult *result, hkpGsk::GetClosesetPointInput *input, hkpGskCache *gskCache, hkVector4f *separatingNormalOut, hkVector4f *pointOnBOut)
{
  hkpConvexShape *v5; // rbx
  hkpGskCache *v6; // rsi
  __int64 v7; // r8
  hkpGsk::GetClosesetPointInput *v8; // r14
  hkResult *v9; // rdi
  hkpConvexShape *v10; // rcx
  unsigned int v11; // edx
  hkVector4f *v12; // rbp
  __m128 v13; // xmm5
  __m128 v14; // xmm4
  __m128 v15; // xmm6
  __m128 v16; // xmm0
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm4
  __m128 *v21; // rax
  hkVector4f v23; // [rsp+30h] [rbp-1D8h]
  hkpGsk v24; // [rsp+40h] [rbp-1C8h]

  v5 = input->m_shapeB.m_storage;
  v6 = gskCache;
  v7 = (unsigned __int8)gskCache->m_dimA;
  v23.m_quad = 0i64;
  v8 = input;
  v9 = result;
  v10 = input->m_shapeA.m_storage;
  v11 = *((unsigned __int8 *)v6 + 10);
  v24.m_dimB.m_storage = (unsigned __int8)v6->m_dimB;
  *(_QWORD *)&v24.m_doNotHandlePenetration.m_storage = 0i64;
  *(_QWORD *)&v24.m_maxDimB.m_storage = v11 >> 4;
  v24.m_dimA.m_storage = v7;
  v24.m_maxDimA.m_storage = v11 & 0xF;
  v12 = separatingNormalOut;
  ((void (__fastcall *)(hkpConvexShape *, hkpGskCache *, __int64, hkcdVertex *))v10->vfptr[4].__first_virtual_table_function__)(
    v10,
    v6,
    v7,
    v24.m_verticesA);
  ((void (__fastcall *)(hkpConvexShape *, unsigned __int16 *, _QWORD, hkcdVertex *))v5->vfptr[4].__first_virtual_table_function__)(
    v5,
    &v6->m_vertices[v24.m_dimA.m_storage],
    (unsigned int)v24.m_dimB.m_storage,
    v24.m_verticesBinB);
  hkpGsk::getClosestFeature(&v24, v8->m_shapeA.m_storage, v8->m_shapeB.m_storage, v8->m_aTb.m_storage, &v23);
  if ( v24.m_featureChange.m_storage )
    hkpGsk::exitAndExportCacheImpl(&v24, v6);
  v13 = v23.m_quad;
  v14 = (__m128)LODWORD(v8->m_shapeB.m_storage->m_radius);
  v15 = _mm_shuffle_ps(v23.m_quad, v23.m_quad, 255);
  v16 = (__m128)LODWORD(v8->m_shapeA.m_storage->m_radius);
  v17 = _mm_shuffle_ps(v14, v14, 0);
  v18 = _mm_sub_ps(_mm_sub_ps(v15, _mm_shuffle_ps(v16, v16, 0)), v17);
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v23.m_quad, v23.m_quad, 85), v8->m_transformA.m_storage->m_rotation.m_col1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v23.m_quad, v23.m_quad, 0), v8->m_transformA.m_storage->m_rotation.m_col0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v23.m_quad, v23.m_quad, 170), v8->m_transformA.m_storage->m_rotation.m_col2.m_quad));
  v12->m_quad = _mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, v18), 196);
  if ( v18.m128_f32[0] >= COERCE_FLOAT(
                            _mm_shuffle_ps(
                              (__m128)LODWORD(v8->m_collisionTolerance.m_storage),
                              (__m128)LODWORD(v8->m_collisionTolerance.m_storage),
                              0)) )
  {
    v9->m_enum = 1;
  }
  else
  {
    if ( v24.m_dimA.m_storage == 1 )
    {
      v20 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v17, v15), v13), v24.m_verticesA[0].m_quad);
    }
    else if ( v24.m_dimB.m_storage == 1 )
    {
      v20 = _mm_add_ps(_mm_mul_ps(v17, v13), v24.m_verticesBinA[0].m_quad);
    }
    else
    {
      v20 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v17, v15), v13), v24.m_closestLineLineResult.m_closestPointA.m_quad);
    }
    v21 = &v8->m_transformA.m_storage->m_rotation.m_col0.m_quad;
    v9->m_enum = 0;
    pointOnBOut->m_quad = _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v21[1]),
                                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), *v21)),
                              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v21[2])),
                            v21[3]);
  }
  return v9;
}

// File Line: 1249
// RVA: 0xDB9C50
void hkpGsk::codeEnd(void)
{
  ;
}

// File Line: 1253
// RVA: 0xDB9FC0
void __fastcall hkpGsk::handlePenetration(hkpGsk *this, hkpConvexShape *shapeA, hkpConvexShape *shapeB, hkTransformf *aTb)
{
  int v4; // eax
  hkTransformf *v5; // rbp
  hkpGsk *v6; // rbx
  int simplexSize; // er10
  __int64 v8; // rcx
  hkcdVertex v9; // xmm0
  hkcdVertex v10; // xmm0
  hkcdVertex v11; // xmm1
  hkVector4f v12; // xmm0
  __int64 v13; // rcx
  signed __int64 v14; // rax
  __m128 v15; // xmm0
  __m128 *v16; // rdi
  __int16 v17; // ax
  __int16 v18; // ax
  signed int v19; // ecx
  __m128 v20; // xmm3
  __m128 v21; // xmm4
  __int64 v22; // rcx
  __m128 v23; // xmm5
  __m128 v24; // xmm6
  __m128 *v25; // rax
  __m128 v26; // xmm1
  __m128 v27; // xmm1
  hkVector4f v28; // xmm0
  hkVector4f dA; // [rsp+50h] [rbp-A8h]
  hkVector4f dB; // [rsp+60h] [rbp-98h]
  hkpGskOut output; // [rsp+70h] [rbp-88h]
  hkVector4f simplex; // [rsp+A0h] [rbp-58h]

  v4 = this->m_dimB.m_storage;
  v5 = aTb;
  v6 = this;
  simplexSize = 4;
  if ( v4 < 3 )
  {
    v8 = this->m_dimA.m_storage;
    if ( (signed int)v8 < 3 )
    {
      v10.m_quad = (__m128)v6->m_verticesA[0];
      simplexSize = 1;
      v6->m_verticesA[v8] = (hkcdVertex)v10.m_quad;
      v6->m_verticesA[v6->m_dimA.m_storage + 1] = (hkcdVertex)v10.m_quad;
      v11.m_quad = (__m128)v6->m_verticesBinB[0];
      v6->m_verticesBinB[v6->m_dimB.m_storage] = (hkcdVertex)v11.m_quad;
      v6->m_verticesBinB[v6->m_dimB.m_storage + 1] = (hkcdVertex)v11.m_quad;
      v12.m_quad = (__m128)v6->m_verticesBinA[0];
      v6->m_verticesBinA[v6->m_dimB.m_storage] = (hkVector4f)v12.m_quad;
      v6->m_verticesBinA[v6->m_dimB.m_storage + 1] = (hkVector4f)v12.m_quad;
    }
    else
    {
      if ( (signed int)v8 <= 3 )
      {
        if ( v4 <= 1 )
        {
          simplexSize = 3;
        }
        else
        {
          v6->m_verticesA[3] = v6->m_verticesA[0];
          v6->m_verticesBinB[3] = v6->m_verticesBinB[1];
          v6->m_verticesBinA[3] = v6->m_verticesBinA[1];
        }
      }
      else
      {
        v6->m_verticesBinB[3] = v6->m_verticesBinB[0];
        v6->m_verticesBinA[3] = v6->m_verticesBinA[0];
      }
      v6->m_verticesBinB[1] = v6->m_verticesBinB[0];
      v9.m_quad = (__m128)v6->m_verticesBinB[0];
      v6->m_verticesBinA[1] = v6->m_verticesBinA[0];
      v6->m_verticesBinB[2] = (hkcdVertex)v9.m_quad;
      v6->m_verticesBinA[2] = v6->m_verticesBinA[0];
    }
  }
  else
  {
    if ( v4 <= 3 )
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
  if ( simplexSize > 0 )
  {
    v14 = (signed __int64)v6->m_verticesA;
    do
    {
      v15 = *(__m128 *)v14;
      v14 += 16i64;
      *(__m128 *)((char *)&simplex - (char *)v6 + v14 - 48) = _mm_sub_ps(v15, *(__m128 *)(v14 + 112));
      --v13;
    }
    while ( v13 );
  }
  v16 = (__m128 *)v6->m_verticesA;
  if ( hkCalculatePenetrationDepth(
         shapeA,
         shapeB,
         aTb,
         0.000099999997,
         v6->m_verticesA,
         v6->m_verticesBinB,
         &simplex,
         simplexSize,
         &output) == 1 )
  {
    v6->m_dimA.m_storage = 1;
    v6->m_dimB.m_storage = 1;
  }
  else
  {
    v6->m_dimA.m_storage = 3;
    v6->m_dimB.m_storage = 3;
    v17 = v6->m_verticesA[2].m_quad.m128_i16[6];
    if ( v6->m_verticesA[1].m_quad.m128_i16[6] == v17 || v6->m_verticesA[0].m_quad.m128_i16[6] == v17 )
      v6->m_dimA.m_storage = 2;
    if ( v6->m_verticesA[0].m_quad.m128_i16[6] == v6->m_verticesA[1].m_quad.m128_i16[6] )
      *v16 = v6->m_verticesA[--v6->m_dimA.m_storage].m_quad;
    v18 = v6->m_verticesBinB[2].m_quad.m128_i16[6];
    if ( v6->m_verticesBinB[1].m_quad.m128_i16[6] == v18 || v6->m_verticesBinB[0].m_quad.m128_i16[6] == v18 )
      --v6->m_dimB.m_storage;
    v19 = v6->m_dimB.m_storage;
    if ( v19 >= 2 && v6->m_verticesBinB[0].m_quad.m128_i16[6] == v6->m_verticesBinB[1].m_quad.m128_i16[6] )
    {
      v6->m_dimB.m_storage = v19 - 1;
      v6->m_verticesBinB[0] = (hkcdVertex)*((_OWORD *)&v6->m_dimA.m_storage + v19 - 1 + 14i64);
    }
    v20 = v5->m_rotation.m_col0.m_quad;
    v21 = v5->m_rotation.m_col1.m_quad;
    v22 = v6->m_dimB.m_storage - 1;
    v23 = v5->m_rotation.m_col2.m_quad;
    v24 = v5->m_translation.m_quad;
    v25 = (__m128 *)((char *)v6 + 16 * (v22 + 14));
    do
    {
      v26 = *v25;
      --v25;
      --v22;
      v25[-3] = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), v21),
                      _mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), v20)),
                    _mm_mul_ps(_mm_shuffle_ps(v26, v26, 170), v23)),
                  v24);
    }
    while ( v22 >= 0 );
    if ( v6->m_dimB.m_storage + v6->m_dimA.m_storage > 4 )
      hkpGsk::reduceDimensionExtended(v6);
    if ( v6->m_dimA.m_storage == 2 && v6->m_dimB.m_storage == 2 )
    {
      v27 = _mm_sub_ps(v6->m_verticesBinA[1].m_quad, v6->m_verticesBinA[0].m_quad);
      dA.m_quad = _mm_sub_ps(v6->m_verticesA[1].m_quad, *v16);
      dB.m_quad = v27;
      hkLineSegmentUtil::closestLineSegLineSeg(
        (hkVector4f *)v6->m_verticesA,
        &dA,
        v6->m_verticesBinA,
        &dB,
        &v6->m_closestLineLineResult);
    }
  }
  v28.m_quad = (__m128)output.m_normalInA;
  v6->m_featureChange.m_storage = 1;
  v6->m_support = (hkVector4f)v28.m_quad;
}

// File Line: 1403
// RVA: 0xDB9C70
void __fastcall hkpGsk::reduceDimensionExtended(hkpGsk *this)
{
  hkpGsk *v1; // rbx
  int v2; // edi
  int v3; // edi
  signed int v4; // er9
  __int64 v5; // rax
  float v6; // xmm6_4
  int v7; // er8
  int v8; // er13
  int v9; // er14
  __int64 v10; // r12
  __int64 v11; // r15
  __m128 *v12; // rcx
  int v13; // edi
  __int64 v14; // rsi
  __m128 *v15; // rbp
  hkVector4f *v16; // r10
  signed __int64 v17; // rax
  __int64 v18; // rax
  __int64 v19; // [rsp+38h] [rbp-D0h]
  hkVector4f dB; // [rsp+40h] [rbp-C8h]
  hkVector4f dA; // [rsp+50h] [rbp-B8h]
  hkLineSegmentUtil::ClosestLineSegLineSegResult result; // [rsp+60h] [rbp-A8h]
  int v23; // [rsp+110h] [rbp+8h]
  signed int v24; // [rsp+118h] [rbp+10h]
  int v25; // [rsp+120h] [rbp+18h]
  signed __int64 v26; // [rsp+128h] [rbp+20h]

  v1 = this;
  if ( this->m_dimB.m_storage != 3 || (v2 = 0, this->m_dimA.m_storage <= 0) )
  {
LABEL_5:
    if ( v1->m_dimA.m_storage != 3 || (v3 = 0, v1->m_dimB.m_storage <= 0) )
    {
LABEL_9:
      v4 = 1;
      LODWORD(v5) = 1;
      v6 = FLOAT_3_40282e38;
      if ( v1->m_dimA.m_storage == 3 )
        LODWORD(v5) = 3;
      if ( v1->m_dimB.m_storage == 3 )
        v4 = 3;
      v7 = 0;
      v25 = v5;
      v5 = (signed int)v5;
      v8 = 0;
      v9 = 0;
      v10 = 0i64;
      v23 = 0;
      v24 = v4;
      v11 = v4;
      v19 = v5;
      if ( (signed int)v5 > 0i64 )
      {
        v12 = (__m128 *)v1->m_verticesA;
        v26 = (signed __int64)v1->m_verticesA;
        do
        {
          v13 = 0;
          v14 = 0i64;
          if ( v11 > 0 )
          {
            v15 = (__m128 *)v1->m_verticesBinA;
            v16 = (hkVector4f *)((char *)v1 + 16 * (v9 + 2i64));
            do
            {
              v17 = hkpCollideTriangleUtil::vertexToEdgeLut[v14 + 2] + 10i64;
              dA.m_quad = _mm_sub_ps(v1->m_verticesA[hkpCollideTriangleUtil::vertexToEdgeLut[v10 + 2]].m_quad, *v12);
              dB.m_quad = _mm_sub_ps(*((__m128 *)&v1->m_dimA.m_storage + v17), *v15);
              hkLineSegmentUtil::closestLineSegLineSeg(v16, &dA, (hkVector4f *)v1 + v13 + 10i64, &dB, &result);
              if ( result.m_distanceSquared.m_storage >= v6 )
              {
                v7 = v23;
              }
              else
              {
                v6 = result.m_distanceSquared.m_storage;
                v8 = v9;
                v7 = v13;
                v23 = v13;
              }
              v12 = (__m128 *)v26;
              v16 = (hkVector4f *)((char *)v1 + 16 * (v9 + 2i64));
              ++v14;
              ++v13;
              ++v15;
            }
            while ( v14 < v11 );
            v5 = v19;
          }
          ++v12;
          ++v10;
          ++v9;
          v26 = (signed __int64)v12;
        }
        while ( v10 < v5 );
        v4 = v24;
      }
      if ( v25 == 3 )
        *((_OWORD *)&v1->m_dimA.m_storage + hkpCollideTriangleUtil::vertexToEdgeLut[v8] + 2i64) = *((_OWORD *)&v1->m_dimA.m_storage
                                                                                                  + --v1->m_dimA.m_storage
                                                                                                  + 2i64);
      if ( v4 == 3 )
      {
        --v1->m_dimB.m_storage;
        v18 = hkpCollideTriangleUtil::vertexToEdgeLut[v7];
        *((_OWORD *)&v1->m_dimA.m_storage + v18 + 14) = *((_OWORD *)&v1->m_dimA.m_storage + v1->m_dimB.m_storage + 14i64);
        *((_OWORD *)&v1->m_dimA.m_storage + v18 + 10) = *((_OWORD *)&v1->m_dimA.m_storage + v1->m_dimB.m_storage + 10i64);
      }
    }
    else
    {
      while ( hkpGsk::checkTriangleBoundaries(v1, (hkVector4f *)v1 + v3 + 10i64, (hkVector4f *)v1->m_verticesA, 0) != 7 )
      {
        if ( ++v3 >= v1->m_dimB.m_storage )
          goto LABEL_9;
      }
      v1->m_verticesBinB[0] = (hkcdVertex)*((_OWORD *)&v1->m_dimA.m_storage + v3 + 14i64);
      v1->m_verticesBinA[0] = (hkVector4f)*((_OWORD *)&v1->m_dimA.m_storage + v3 + 10i64);
      v1->m_dimB.m_storage = 1;
    }
  }
  else
  {
    while ( hkpGsk::checkTriangleBoundaries(v1, (hkVector4f *)v1 + v2 + 2i64, v1->m_verticesBinA, 0) != 7 )
    {
      if ( ++v2 >= v1->m_dimA.m_storage )
        goto LABEL_5;
    }
    v1->m_verticesA[0] = (hkcdVertex)*((_OWORD *)&v1->m_dimA.m_storage + v2 + 2i64);
    v1->m_dimA.m_storage = 1;
  }
}

// File Line: 1580
// RVA: 0xDBB600
hkSimdFloat32 *__fastcall hkGskRecalcContact_pointTriangle(hkSimdFloat32 *result, hkVector4f *a, hkVector4f *b, hkVector4f *masterNormal, hkVector4f *support)
{
  __m128 v5; // xmm1
  __m128 v6; // xmm5
  __m128 v7; // xmm5
  hkVector4f v8; // xmm5
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm2
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  hkVector4f v16; // xmm3
  hkSimdFloat32 *v17; // rax
  __m128 v18; // xmm2

  v5 = _mm_sub_ps(b[2].m_quad, b[1].m_quad);
  v6 = _mm_sub_ps(b->m_quad, b[2].m_quad);
  v7 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v5), _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v6));
  v8.m_quad = _mm_shuffle_ps(v7, v7, 201);
  *support = (hkVector4f)v8.m_quad;
  v9 = _mm_mul_ps(v8.m_quad, v8.m_quad);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_rsqrt_ps(v10);
  v12 = _mm_cmpleps(v10, (__m128)0i64);
  v13 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11));
  v14 = _mm_mul_ps(*(__m128 *)_xmm, v11);
  v15 = _mm_mul_ps(v8.m_quad, masterNormal->m_quad);
  v16.m_quad = _mm_mul_ps(
                 _mm_xor_ps(
                   (__m128)_mm_slli_epi32(
                             _mm_srli_epi32(
                               (__m128i)_mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                                          _mm_shuffle_ps(v15, v15, 170)),
                               0x1Fu),
                             0x1Fu),
                   v8.m_quad),
                 _mm_andnot_ps(v12, _mm_mul_ps(v13, v14)));
  *support = (hkVector4f)v16.m_quad;
  v17 = result;
  v18 = _mm_mul_ps(_mm_sub_ps(a->m_quad, b->m_quad), v16.m_quad);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                     _mm_shuffle_ps(v18, v18, 170));
  return v17;
}

// File Line: 1599
// RVA: 0xDBB6F0
hkSimdFloat32 *__fastcall hkGskRecalcContact_pointEdge(hkSimdFloat32 *result, hkVector4f *vertexA, hkVector4f *vertexB, hkVector4f *masterNormal, hkVector4f *support)
{
  __m128 v5; // xmm2
  __m128 v6; // xmm0
  hkSimdFloat32 *v7; // rax
  __m128 v8; // xmm2

  v5 = masterNormal->m_quad;
  v6 = _mm_sub_ps(vertexA->m_quad, vertexB->m_quad);
  *support = (hkVector4f)masterNormal->m_quad;
  v7 = result;
  v8 = _mm_mul_ps(v5, v6);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)),
                     _mm_shuffle_ps(v8, v8, 170));
  return v7;
}

// File Line: 1609
// RVA: 0xDBB730
void __fastcall hkGskRecalcContact_edgeEdge(hkVector4f *vertexA, hkVector4f *vertexB, hkVector4f *masterNormal, hkVector4f *pointAOut, hkVector4f *support)
{
  hkVector4f *v5; // rbx
  hkVector4f *v6; // rbp
  hkVector4f *v7; // rdi
  __m128 v8; // xmm0
  hkVector4f *v9; // rsi
  __m128 v10; // xmm2
  __m128 v11; // xmm6
  __m128 v12; // xmm1
  hkVector4f v13; // xmm6
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  float v16; // xmm4_4
  __m128 v17; // xmm1
  __m128 v18; // xmm5
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  hkVector4f dA; // [rsp+30h] [rbp-88h]
  hkVector4f dB; // [rsp+40h] [rbp-78h]
  hkLineSegmentUtil::ClosestLineSegLineSegResult result; // [rsp+50h] [rbp-68h]

  v5 = masterNormal;
  v6 = pointAOut;
  v7 = vertexB;
  v8 = _mm_sub_ps(vertexA[1].m_quad, vertexA->m_quad);
  v9 = vertexA;
  dB.m_quad = _mm_sub_ps(vertexB[1].m_quad, vertexB->m_quad);
  dA.m_quad = v8;
  hkLineSegmentUtil::closestLineSegLineSeg(vertexA, &dA, vertexB, &dB, &result);
  v10 = _mm_mul_ps(dA.m_quad, dA.m_quad);
  v11 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(dB.m_quad, dB.m_quad, 201), dA.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(dA.m_quad, dA.m_quad, 201), dB.m_quad));
  v12 = _mm_mul_ps(dB.m_quad, dB.m_quad);
  v13.m_quad = _mm_shuffle_ps(v11, v11, 201);
  *support = (hkVector4f)v13.m_quad;
  v14 = _mm_add_ps(v10, v12);
  v15 = _mm_mul_ps(v13.m_quad, v13.m_quad);
  v16 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 170));
  if ( (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 170)))
             * COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0))) <= (float)(v16 * v16) )
  {
    *support = (hkVector4f)v5->m_quad;
  }
  else
  {
    v17 = _mm_mul_ps(v13.m_quad, v5->m_quad);
    v18 = _mm_xor_ps(
            (__m128)_mm_slli_epi32(
                      _mm_srli_epi32(
                        (__m128i)_mm_add_ps(
                                   _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                                   _mm_shuffle_ps(v17, v17, 170)),
                        0x1Fu),
                      0x1Fu),
            v13.m_quad);
    v19 = _mm_mul_ps(v18, v18);
    v20 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
            _mm_shuffle_ps(v19, v19, 170));
    v21 = _mm_rsqrt_ps(v20);
    support->m_quad = _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmpleps(v20, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                            _mm_mul_ps(*(__m128 *)_xmm, v21))),
                        v18);
  }
  v22 = _mm_mul_ps(_mm_sub_ps(v9->m_quad, v7->m_quad), support->m_quad);
  *v6 = result.m_closestPointA;
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
void __fastcall hkGskRecalcContactInternal(hkVector4f *verticesA, hkVector4f *verticesB, int dimA, int dimB, hkVector4f *masterNormal, hkVector4f *pointA, hkVector4f *support)
{
  hkVector4f *v7; // rdi
  hkVector4f *v8; // rbx
  int v9; // edx
  hkVector4f v10; // xmm6
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
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm5
  hkVector4f v29; // xmm5
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm0
  __m128 v35; // xmm1
  hkVector4f v36; // xmm2
  __m128 v37; // xmm3
  __m128 v38; // xmm1
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm6
  __m128 v45; // xmm1
  hkVector4f v46; // xmm6
  __m128 v47; // xmm2
  __m128 v48; // xmm1
  float v49; // xmm4_4
  __m128 v50; // xmm1
  __m128 v51; // xmm5
  __m128 v52; // xmm1
  __m128 v53; // xmm3
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  hkVector4f dB; // [rsp+30h] [rbp-98h]
  hkVector4f dA; // [rsp+40h] [rbp-88h]
  hkLineSegmentUtil::ClosestLineSegLineSegResult result; // [rsp+50h] [rbp-78h]

  v7 = verticesB;
  v8 = verticesA;
  v9 = dimB | 8 * dimA;
  switch ( v9 )
  {
    case 9:
      v10.m_quad = _mm_sub_ps(verticesA->m_quad, v7->m_quad);
      *support = (hkVector4f)v10.m_quad;
      v11 = _mm_mul_ps(v10.m_quad, v10.m_quad);
      v12 = _mm_mul_ps(masterNormal->m_quad, v10.m_quad);
      if ( (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170)))
                 * COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_1000_0), (__m128)LODWORD(FLOAT_1000_0), 0))) >= (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170))) )
      {
        v14 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                _mm_shuffle_ps(v11, v11, 170));
        v15 = _mm_rsqrt_ps(v14);
        v16 = _mm_andnot_ps(
                _mm_cmpleps(v14, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
                  _mm_mul_ps(*(__m128 *)_xmm, v15)));
        v17.m_quad = _mm_mul_ps(v10.m_quad, v16);
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
      v18 = _mm_mul_ps(masterNormal->m_quad, _mm_sub_ps(verticesA->m_quad, v7->m_quad));
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
      v20 = _mm_sub_ps(v7->m_quad, v8->m_quad);
      v21 = masterNormal->m_quad;
      *support = (hkVector4f)masterNormal->m_quad;
      v22 = _mm_mul_ps(v20, v21);
      v23 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
              _mm_shuffle_ps(v22, v22, 170));
      v24 = v7->m_quad;
      *pointA = (hkVector4f)v7->m_quad;
      pointA->m_quad = _mm_sub_ps(v24, _mm_mul_ps(v23, support->m_quad));
      v25 = _mm_sub_ps((__m128)0i64, v23);
      goto LABEL_17;
    case 18:
      v42 = _mm_sub_ps(v7[1].m_quad, v7->m_quad);
      dA.m_quad = _mm_sub_ps(verticesA[1].m_quad, verticesA->m_quad);
      dB.m_quad = v42;
      hkLineSegmentUtil::closestLineSegLineSeg(verticesA, &dA, v7, &dB, &result);
      v19 = support;
      v43 = _mm_mul_ps(dB.m_quad, dB.m_quad);
      v44 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(dB.m_quad, dB.m_quad, 201), dA.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(dA.m_quad, dA.m_quad, 201), dB.m_quad));
      v45 = _mm_mul_ps(dA.m_quad, dA.m_quad);
      v46.m_quad = _mm_shuffle_ps(v44, v44, 201);
      *support = (hkVector4f)v46.m_quad;
      v47 = _mm_add_ps(v43, v45);
      v48 = _mm_mul_ps(v46.m_quad, v46.m_quad);
      v49 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 170));
      if ( (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v48, v48, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v48, v48, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v48, v48, 170)))
                 * COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0))) <= (float)(v49 * v49) )
      {
        *support = (hkVector4f)masterNormal->m_quad;
      }
      else
      {
        v50 = _mm_mul_ps(v46.m_quad, masterNormal->m_quad);
        v51 = _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32(
                            (__m128i)_mm_add_ps(
                                       _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
                                       _mm_shuffle_ps(v50, v50, 170)),
                            0x1Fu),
                          0x1Fu),
                v46.m_quad);
        v52 = _mm_mul_ps(v51, v51);
        v53 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                _mm_shuffle_ps(v52, v52, 170));
        v54 = _mm_rsqrt_ps(v53);
        support->m_quad = _mm_mul_ps(
                            _mm_andnot_ps(
                              _mm_cmpleps(v53, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v54, v53), v54)),
                                _mm_mul_ps(*(__m128 *)_xmm, v54))),
                            v51);
      }
      v55 = _mm_mul_ps(_mm_sub_ps(v8->m_quad, v7->m_quad), support->m_quad);
      *pointA = result.m_closestPointA;
      v25 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
              _mm_shuffle_ps(v55, v55, 170));
LABEL_17:
      v19->m_quad = _mm_shuffle_ps(v19->m_quad, _mm_unpackhi_ps(v19->m_quad, v25), 196);
      break;
    case 25:
      v8 = v7;
      v7 = verticesA;
$LN5_200:
      v26 = _mm_sub_ps(v7[2].m_quad, v7[1].m_quad);
      v27 = _mm_sub_ps(v7->m_quad, v7[2].m_quad);
      v28 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v26), _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v27));
      v29.m_quad = _mm_shuffle_ps(v28, v28, 201);
      *support = (hkVector4f)v29.m_quad;
      v30 = _mm_mul_ps(v29.m_quad, v29.m_quad);
      v31 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
              _mm_shuffle_ps(v30, v30, 170));
      v32 = _mm_rsqrt_ps(v31);
      v33 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32));
      v34 = _mm_mul_ps(*(__m128 *)_xmm, v32);
      v35 = _mm_mul_ps(v29.m_quad, masterNormal->m_quad);
      v36.m_quad = _mm_mul_ps(
                     _mm_xor_ps(
                       (__m128)_mm_slli_epi32(
                                 _mm_srli_epi32(
                                   (__m128i)_mm_add_ps(
                                              _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
                                              _mm_shuffle_ps(v35, v35, 170)),
                                   0x1Fu),
                                 0x1Fu),
                       v29.m_quad),
                     _mm_andnot_ps(_mm_cmpleps(v31, (__m128)0i64), _mm_mul_ps(v33, v34)));
      *support = (hkVector4f)v36.m_quad;
      v37 = v8->m_quad;
      v38 = _mm_sub_ps(v8->m_quad, v7->m_quad);
      *pointA = (hkVector4f)v8->m_quad;
      v39 = _mm_mul_ps(v38, v36.m_quad);
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

